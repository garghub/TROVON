static void F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
V_4 -> V_6 = V_2 ;
}
static int F_2 ( struct V_1 * V_1 , int V_7 )
{
struct V_8 * V_8 = & V_1 -> V_8 ;
if ( F_3 ( V_8 , V_7 & 0xff , V_9 ) < 0 ) {
F_4 ( V_1 ,
L_1 ,
V_7 & 0xff , V_8 -> V_10 ) ;
if ( V_8 -> V_10 == V_11 )
return V_11 ;
else
return V_12 ;
}
#ifdef F_5
F_4 ( V_1 , L_2 ,
V_7 & 0xff ) ;
#endif
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , unsigned short V_13 ,
unsigned char V_14 )
{
struct V_8 * V_8 = & V_1 -> V_8 ;
int V_15 = V_16 ;
int V_17 ;
F_7 ( V_8 ) ;
do {
V_17 = F_2 ( V_1 , V_13 & 0xff ) ;
if ( V_17 == V_11 ) {
V_17 = F_2 ( V_1 , 0x00 ) ;
if ( V_17 == V_11 )
V_17 = F_2 ( V_1 , 0x0a ) ;
}
if ( V_17 == V_12 )
continue;
V_17 = F_2 ( V_1 , V_14 ) ;
if ( V_17 == V_11 )
V_17 = F_2 ( V_1 , V_14 ) ;
if ( V_17 == V_12 )
continue;
else
break;
} while ( -- V_15 > 0 );
F_8 ( V_8 ) ;
return V_17 ;
}
static int F_9 ( struct V_1 * V_1 ,
unsigned char V_13 ,
unsigned char * V_18 )
{
int V_17 ;
struct V_8 * V_8 = & V_1 -> V_8 ;
enum V_19 V_20 ;
int V_21 ;
F_7 ( V_8 ) ;
V_20 = V_1 -> V_22 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = 0 ;
V_21 = ( V_13 == V_25 ) ? 8 : 3 ;
memset ( V_18 , 0 , V_21 ) ;
V_17 = F_2 ( V_1 , 0xe9 ) ;
if ( V_17 < 0 )
goto V_26;
F_10 ( V_8 -> V_27 ,
( V_1 -> V_24 >= V_21 ) ,
F_11 ( V_9 ) ) ;
memcpy ( V_18 , V_1 -> V_28 , V_21 ) ;
F_4 ( V_1 , L_3 ,
V_13 , V_21 , V_18 ) ;
V_26:
V_1 -> V_22 = V_20 ;
V_1 -> V_24 = 0 ;
F_8 ( V_8 ) ;
return V_17 ;
}
static bool F_12 ( struct V_1 * V_1 ,
unsigned char V_13 , unsigned char * V_18 )
{
bool V_29 = false ;
bool V_30 = false ;
int V_31 ;
if ( V_13 == V_32 ||
V_13 == V_33 ||
V_13 == V_25 )
return true ;
if ( ( ~ V_18 [ 0 ] & V_34 ) == V_34 &&
( V_18 [ 0 ] & V_35 ) == V_36 ) {
for ( V_31 = 0 ; V_31 < sizeof( V_37 ) ; V_31 ++ )
if ( V_37 [ V_31 ] == V_18 [ 1 ] )
V_30 = true ;
for ( V_31 = 0 ; V_31 < sizeof( V_38 ) ; V_31 ++ )
if ( V_38 [ V_31 ] == V_18 [ 2 ] )
V_29 = true ;
if ( V_30 && V_29 )
return true ;
}
F_4 ( V_1 , L_4 ) ;
return false ;
}
static int F_13 ( struct V_1 * V_1 , unsigned char V_13 ,
unsigned char * V_18 )
{
int V_15 = V_16 ;
int V_17 ;
F_4 ( V_1 , L_5 ,
V_13 , F_14 ( V_13 ) , F_15 ( V_13 ) ,
F_16 ( V_13 ) , F_17 ( V_13 ) ) ;
do {
F_6 ( V_1 ,
V_39 , F_17 ( V_13 ) ) ;
F_6 ( V_1 ,
V_39 , F_16 ( V_13 ) ) ;
F_6 ( V_1 ,
V_39 , F_15 ( V_13 ) ) ;
F_6 ( V_1 ,
V_39 , F_14 ( V_13 ) ) ;
V_17 = F_9 ( V_1 , V_13 , V_18 ) ;
if ( V_17 )
continue;
if ( F_12 ( V_1 , V_13 , V_18 ) )
return 0 ;
} while ( -- V_15 > 0 );
return - V_40 ;
}
int F_18 ( struct V_1 * V_1 , bool V_41 )
{
unsigned char V_18 [ 3 ] ;
if ( F_13 ( V_1 , V_32 , V_18 ) )
return - V_42 ;
if ( V_18 [ 0 ] != 0x33 || V_18 [ 1 ] != 0xCC )
return - V_42 ;
if ( V_41 ) {
V_1 -> V_43 = L_6 ;
V_1 -> V_44 = L_7 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned char V_18 [ 3 ] ;
if ( F_13 ( V_1 , V_32 , V_18 ) )
return - V_42 ;
if ( V_18 [ 0 ] != 0x33 || V_18 [ 1 ] != 0xCC )
return - V_42 ;
V_4 -> V_45 = V_18 [ 2 ] & V_46 ;
V_4 -> V_47 = ( V_18 [ 2 ] & V_48 ) ? 1 : 0 ;
if ( V_4 -> V_45 >= 11 )
V_4 -> V_47 = 0 ;
F_4 ( V_1 , L_8 , V_4 -> V_45 ) ;
F_4 ( V_1 , L_9 ,
V_4 -> V_47 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned char V_18 [ 8 ] ;
V_4 -> V_49 = V_50 ;
V_4 -> V_51 = V_52 ;
V_4 -> V_53 = V_54 ;
V_4 -> V_55 = V_56 ;
V_4 -> V_57 = V_58 ;
V_4 -> V_59 = V_60 ;
V_4 -> V_61 = V_4 -> V_53 / V_4 -> V_49 ;
V_4 -> V_62 = V_4 -> V_55 / V_4 -> V_51 ;
if ( ! V_4 -> V_47 )
return 0 ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
if ( F_13 ( V_1 , V_25 , V_18 ) == 0 ) {
V_4 -> V_53 = ( V_18 [ 1 ] << 8 ) | V_18 [ 0 ] ;
V_4 -> V_55 = ( V_18 [ 3 ] << 8 ) | V_18 [ 2 ] ;
V_4 -> V_57 = V_18 [ 4 ] ;
V_4 -> V_59 = V_18 [ 5 ] ;
}
if ( ! V_4 -> V_59 ||
V_4 -> V_59 < V_4 -> V_57 ||
! V_4 -> V_49 || ! V_4 -> V_51 ||
! V_4 -> V_53 ||
V_4 -> V_53 < V_4 -> V_49 ||
! V_4 -> V_55 ||
V_4 -> V_55 < V_4 -> V_51 )
return - V_63 ;
V_4 -> V_61 = V_4 -> V_53 / V_4 -> V_49 ;
V_4 -> V_62 = V_4 -> V_55 / V_4 -> V_51 ;
#ifdef F_5
F_4 ( V_1 , L_10 ) ;
F_4 ( V_1 , L_11 , V_4 -> V_49 ) ;
F_4 ( V_1 , L_12 , V_4 -> V_51 ) ;
F_4 ( V_1 , L_13 , V_4 -> V_53 ) ;
F_4 ( V_1 , L_14 , V_4 -> V_55 ) ;
F_4 ( V_1 , L_15 , V_4 -> V_57 ) ;
F_4 ( V_1 , L_16 , V_4 -> V_59 ) ;
F_4 ( V_1 , L_17 , V_4 -> V_61 ) ;
F_4 ( V_1 , L_18 , V_4 -> V_62 ) ;
F_4 ( V_1 , L_19 ,
( V_18 [ 6 ] & V_64 ) ? 1 : 0 ) ;
F_4 ( V_1 , L_20 ,
( V_18 [ 6 ] & V_65 ) ? 1 : 0 ) ;
F_4 ( V_1 , L_21 ,
( V_18 [ 6 ] & V_66 ) ? 1 : 0 ) ;
F_4 ( V_1 , L_22 ,
( V_18 [ 6 ] & V_67 ) ? 1 : 0 ) ;
F_4 ( V_1 , L_23 ,
( V_18 [ 6 ] & V_68 ) >> 2 ) ;
F_4 ( V_1 , L_24 ,
( V_18 [ 6 ] & V_69 ) >> 4 ) ;
F_4 ( V_1 , L_25 ,
V_18 [ 7 ] & V_70 ) ;
F_4 ( V_1 , L_26 ,
( V_18 [ 7 ] & V_71 ) >> 2 ) ;
F_4 ( V_1 , L_27 ,
( V_18 [ 7 ] & V_72 ) >> 4 ) ;
#endif
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_73 ;
V_73 = F_19 ( V_1 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_20 ( V_1 ) ;
if ( V_73 )
return V_73 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
unsigned char V_18 [ 3 ] ;
if ( F_13 ( V_1 , V_74 , V_18 ) < 0 )
return - 1 ;
V_4 -> V_75 = ( V_4 -> V_75 & ~ V_76 )
| V_77 ;
F_1 ( V_1 , 5 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
V_4 -> V_75 = 0 ;
F_24 ( V_1 ) ;
}
static int F_25 ( struct V_78 * V_79 ,
struct V_3 * V_4 )
{
int V_73 ;
if ( ! V_4 -> V_61 || ! V_4 -> V_62 )
return - V_63 ;
F_26 ( V_80 , V_79 -> V_81 ) ;
F_27 ( V_79 , V_82 , 0 , V_4 -> V_53 , 0 , 0 ) ;
F_27 ( V_79 , V_83 , 0 , V_4 -> V_55 , 0 , 0 ) ;
F_27 ( V_79 , V_84 ,
V_4 -> V_57 , V_4 -> V_59 , 0 , 0 ) ;
F_27 ( V_79 , V_85 , 0 , 255 , 0 , 0 ) ;
F_27 ( V_79 , V_86 , 0 , V_4 -> V_53 , 0 , 0 ) ;
F_27 ( V_79 , V_87 , 0 , V_4 -> V_55 , 0 , 0 ) ;
F_27 ( V_79 , V_88 , 0 , 255 , 0 , 0 ) ;
V_73 = F_28 ( V_79 , V_89 ,
V_90 | V_91 ) ;
if ( V_73 < 0 )
return V_73 ;
F_26 ( V_92 , V_79 -> V_93 ) ;
F_29 ( V_79 , V_82 , V_4 -> V_61 ) ;
F_29 ( V_79 , V_83 , V_4 -> V_62 ) ;
F_29 ( V_79 , V_86 , V_4 -> V_61 ) ;
F_29 ( V_79 , V_87 , V_4 -> V_62 ) ;
F_26 ( V_94 , V_79 -> V_95 ) ;
F_26 ( V_96 , V_79 -> V_95 ) ;
F_26 ( V_97 , V_79 -> V_95 ) ;
F_26 ( V_98 , V_79 -> V_95 ) ;
F_26 ( V_99 , V_79 -> V_95 ) ;
F_26 ( V_100 , V_79 -> V_95 ) ;
F_30 ( V_101 , V_79 -> V_81 ) ;
F_30 ( V_102 , V_79 -> V_103 ) ;
F_30 ( V_104 , V_79 -> V_103 ) ;
F_26 ( V_105 , V_79 -> V_81 ) ;
F_26 ( V_106 , V_79 -> V_95 ) ;
F_26 ( V_107 , V_79 -> V_95 ) ;
F_26 ( V_108 , V_79 -> V_95 ) ;
return 0 ;
}
static int F_31 ( unsigned char V_109 )
{
unsigned char V_110 ;
int V_111 ;
V_110 = V_109 >> 6 ;
V_111 = V_110 & 0x03 ;
if ( V_111 == 1 )
return 1 ;
if ( V_109 & V_112 ) {
switch ( V_111 ) {
case 0 : return 4 ;
case 2 : return 5 ;
default:
return 0 ;
}
}
return V_111 ;
}
static int F_32 ( struct V_1 * V_1 ,
struct V_3 * V_4 , struct V_113 * V_114 )
{
unsigned char * V_28 = V_1 -> V_28 ;
unsigned char V_109 = V_28 [ 0 ] ;
memset ( V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 -> V_115 = F_31 ( V_109 ) ;
V_114 -> V_116 = ( V_109 & V_117 ) ? 1 : 0 ;
if ( V_114 -> V_115 == 1 ) {
V_114 -> V_118 [ 0 ] . V_119 =
( ( V_28 [ 1 ] & 0x70 ) << 4 ) | V_28 [ 2 ] ;
V_114 -> V_118 [ 0 ] . V_120 =
( ( V_28 [ 1 ] & 0x07 ) << 8 ) | V_28 [ 3 ] ;
if ( V_4 -> V_75 & V_77 )
V_114 -> V_118 [ 0 ] . V_121 = V_28 [ 4 ] ;
} else if ( V_114 -> V_115 >= 2 ) {
V_114 -> V_118 [ 0 ] . V_119 =
( ( V_28 [ 1 ] & 0x70 ) << 4 ) | V_28 [ 2 ] ;
V_114 -> V_118 [ 0 ] . V_120 =
( ( V_28 [ 1 ] & 0x07 ) << 8 ) | V_28 [ 3 ] ;
if ( V_4 -> V_75 & V_77 )
V_114 -> V_118 [ 0 ] . V_121 = V_28 [ 4 ] ;
V_114 -> V_118 [ 1 ] . V_119 =
( ( V_28 [ 5 ] & 0xf0 ) << 4 ) | V_28 [ 6 ] ;
V_114 -> V_118 [ 1 ] . V_120 =
( ( V_28 [ 5 ] & 0x0f ) << 8 ) | V_28 [ 7 ] ;
if ( V_4 -> V_75 & V_77 )
V_114 -> V_118 [ 1 ] . V_121 = V_114 -> V_118 [ 0 ] . V_121 ;
}
V_114 -> V_122 = ( V_109 & V_123 ) ? 1 : 0 ;
V_114 -> V_124 = ( V_109 & V_125 ) ? 1 : 0 ;
if ( V_114 -> V_116 )
V_114 -> V_122 = 0 ;
#ifdef F_5
{
int V_31 ;
int V_2 = V_114 -> V_115 ;
F_4 ( V_1 , L_28 ) ;
F_4 ( V_1 , L_29 ,
V_114 -> V_115 ) ;
if ( V_2 > V_89 )
V_2 = V_89 ;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ )
F_4 ( V_1 , L_30 , V_31 ,
V_114 -> V_118 [ V_31 ] . V_119 ,
V_114 -> V_118 [ V_31 ] . V_120 ,
V_114 -> V_118 [ V_31 ] . V_121 ) ;
F_4 ( V_1 , L_31 , V_114 -> V_122 ) ;
F_4 ( V_1 , L_32 , V_114 -> V_124 ) ;
F_4 ( V_1 , L_33 , V_114 -> V_126 ) ;
}
#endif
return 0 ;
}
static void F_33 ( struct V_1 * V_1 , bool V_127 )
{
int V_31 ;
struct V_78 * V_79 = V_1 -> V_128 ;
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_113 V_114 ;
struct V_129 * V_130 ;
struct V_131 V_132 [ V_89 ] ;
int V_133 [ V_89 ] ;
int V_2 ;
F_32 ( V_1 , V_4 , & V_114 ) ;
V_2 = V_114 . V_115 ;
if ( V_2 > V_89 )
V_2 = V_89 ;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ ) {
V_130 = & V_114 . V_118 [ V_31 ] ;
V_132 [ V_31 ] . V_119 = V_130 -> V_119 ;
V_132 [ V_31 ] . V_120 = V_130 -> V_120 ;
}
F_34 ( V_79 , V_133 , V_132 , V_2 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_2 ; V_31 ++ ) {
V_130 = & V_114 . V_118 [ V_31 ] ;
F_35 ( V_79 , V_133 [ V_31 ] ) ;
F_36 ( V_79 , V_134 , true ) ;
F_37 ( V_79 , V_86 , V_130 -> V_119 ) ;
F_37 ( V_79 , V_87 , V_130 -> V_120 ) ;
F_37 ( V_79 , V_88 , V_130 -> V_121 ) ;
}
F_38 ( V_79 ) ;
F_39 ( V_79 , V_114 . V_115 ) ;
F_40 ( V_79 , V_106 , V_114 . V_122 ) ;
F_40 ( V_79 , V_107 , V_114 . V_124 ) ;
F_40 ( V_79 , V_108 , V_114 . V_126 ) ;
F_41 ( V_79 ) ;
}
static T_1 F_42 ( struct V_1 * V_1 )
{
int V_115 ;
int V_135 = V_1 -> V_24 - 1 ;
unsigned char * V_28 = V_1 -> V_28 ;
struct V_3 * V_4 = V_1 -> V_5 ;
if ( V_135 < 0 || V_135 > V_4 -> V_6 )
return V_136 ;
if ( V_135 == 0 && ( V_28 [ 0 ] & 0xfc ) == 0 ) {
F_33 ( V_1 , 1 ) ;
return V_137 ;
}
if ( V_135 != 0 )
return V_138 ;
if ( ( V_4 -> V_75 & V_76 ) == 0 )
return V_138 ;
if ( ( V_28 [ 0 ] & 0x08 ) == 0x08 )
return V_136 ;
V_115 = F_31 ( V_28 [ 0 ] ) ;
if ( V_4 -> V_75 & V_139 )
F_1 ( V_1 , V_115 == 2 ? 7 : 4 ) ;
else
F_1 ( V_1 , V_115 == 2 ? 8 : 5 ) ;
return V_138 ;
}
static T_1 F_43 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
if ( V_1 -> V_24 >= V_4 -> V_6 ) {
F_33 ( V_1 , 0 ) ;
return V_137 ;
}
return F_42 ( V_1 ) ;
}
static void F_44 ( struct V_1 * V_1 , unsigned int V_140 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
if ( V_140 >= 80 ) {
V_1 -> V_140 = 80 ;
V_4 -> V_75 |= V_141 ;
} else {
V_1 -> V_140 = 40 ;
V_4 -> V_75 &= ~ V_141 ;
}
F_45 ( & V_1 -> V_8 , ( unsigned char * ) & V_1 -> V_140 ,
V_142 ) ;
}
static void F_46 ( struct V_1 * V_1 )
{
F_23 ( V_1 ) ;
F_47 ( V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
}
static int F_48 ( struct V_1 * V_1 )
{
int V_15 = V_16 ;
int V_17 ;
do {
F_23 ( V_1 ) ;
V_17 = F_18 ( V_1 , false ) ;
} while ( V_17 && ( -- V_15 > 0 ) );
if ( V_17 ) {
F_49 ( V_1 , L_34 ) ;
return - 1 ;
}
if ( F_22 ( V_1 ) ) {
F_49 ( V_1 , L_35 ) ;
return - 1 ;
}
return 0 ;
}
int F_50 ( struct V_1 * V_1 )
{
struct V_3 * V_4 ;
V_4 = F_51 ( sizeof( struct V_3 ) , V_143 ) ;
if ( ! V_4 )
return - V_144 ;
V_1 -> V_5 = V_4 ;
V_1 -> V_21 = 8 ;
F_23 ( V_1 ) ;
if ( F_21 ( V_1 ) ) {
F_49 ( V_1 , L_36 ) ;
goto V_145;
}
if ( F_22 ( V_1 ) ) {
F_49 ( V_1 , L_37 ) ;
goto V_145;
}
if ( F_25 ( V_1 -> V_128 , V_4 ) < 0 ) {
F_49 ( V_1 , L_38 ) ;
goto V_145;
}
V_1 -> V_146 = 1 ;
V_1 -> V_147 = F_43 ;
V_1 -> V_148 = F_44 ;
V_1 -> V_149 = F_46 ;
V_1 -> V_150 = F_48 ;
V_1 -> V_151 = F_23 ;
V_1 -> V_152 = 0 ;
return 0 ;
V_145:
F_23 ( V_1 ) ;
V_1 -> V_5 = NULL ;
F_47 ( V_4 ) ;
return - 1 ;
}
