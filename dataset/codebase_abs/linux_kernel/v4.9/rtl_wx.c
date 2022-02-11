static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_3 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_5 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_7 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_10 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_13 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_15 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 ) {
F_17 ( V_2 , L_1 ,
V_16 ) ;
return 0 ;
}
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_18 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_20 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_22 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_24 ( V_17 , L_2 ,
V_16 , * V_12 ) ;
V_9 -> V_18 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_19 * V_20 = (struct V_19 * )
( & ( V_9 -> V_10 -> V_21 ) ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
F_24 ( V_24 , L_3 , V_16 , ( * V_12 == 6 ) ?
L_4 : L_5 ) ;
if ( * V_12 || V_9 -> V_25 ) {
V_9 -> V_26 = false ;
V_20 -> V_27 = true ;
} else {
if ( V_9 -> V_10 -> V_28 == V_29 )
F_26 ( V_2 ) ;
V_9 -> V_26 = true ;
V_20 -> V_27 = false ;
V_23 -> V_30 = * V_12 ;
}
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 ,
char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_19 * V_20 = (struct V_19 * )
( & ( V_9 -> V_10 -> V_21 ) ) ;
F_9 ( & V_9 -> V_15 ) ;
F_28 ( V_2 , L_6 ,
V_16 , * V_12 ) ;
V_20 -> V_31 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_28 ( V_2 ,
L_7 ,
V_16 , * V_12 ) ;
V_9 -> V_25 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_32 = * V_12 ;
if ( V_9 -> V_14 )
return 0 ;
F_28 ( V_2 , L_8 , V_16 ,
* V_12 , V_33 ) ;
if ( V_32 > 0 )
V_33 |= ( 1 << V_32 ) ;
else
V_33 &= V_34 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = F_32 ( V_2 ) ;
enum V_35 V_36 ;
int V_13 ;
if ( V_9 -> V_14 )
return 0 ;
V_36 = V_9 -> V_10 -> V_37 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_38 == V_39 || V_6 -> V_38 == V_40 ||
V_23 -> V_41 ) {
if ( V_9 -> V_10 -> V_21 . V_42 ) {
if ( V_36 == V_43 ) {
if ( V_9 -> V_10 -> V_44 >
V_45 ) {
F_17 ( V_2 , L_9 ,
V_16 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
F_28 ( V_2 ,
L_10 ,
V_16 ) ;
F_9 ( & V_9 -> V_10 -> V_46 ) ;
F_33 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_46 ) ;
}
}
}
V_13 = F_34 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_47 * V_48 = (struct V_47 * ) V_12 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_2 V_49 ;
int V_50 ;
V_6 -> V_51 . V_52 = sizeof( * V_48 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_53 = 130 * 1000 * 1000 ;
if ( V_9 -> V_54 != NULL )
V_48 -> V_55 = V_9 -> V_56 ;
V_48 -> V_57 . V_58 = 100 ;
V_48 -> V_57 . V_59 = 0 ;
V_48 -> V_57 . V_60 = 0 ;
V_48 -> V_57 . V_61 = 7 ;
V_48 -> V_62 . V_58 = 70 ;
V_48 -> V_62 . V_59 = 0 ;
V_48 -> V_62 . V_60 = 0 ;
V_48 -> V_62 . V_61 = 7 ;
V_48 -> V_63 = F_36 ( V_64 , V_65 ) ;
for ( V_50 = 0 ; V_50 < V_48 -> V_63 ; V_50 ++ )
V_48 -> V_66 [ V_50 ] = V_67 [ V_50 ] ;
V_48 -> V_68 = V_69 ;
V_48 -> V_70 = V_71 ;
V_48 -> V_72 = V_73 ;
V_48 -> V_74 = 0 ;
V_48 -> V_75 = 5000000 ;
V_48 -> V_76 = 0 ;
V_48 -> V_77 = 65535 * 1000 ;
V_48 -> V_78 = V_79 ;
V_48 -> V_80 = V_81 ;
V_48 -> V_82 = V_79 | V_81 | V_83 ;
V_48 -> V_84 = V_85 ;
V_48 -> V_86 = 18 ;
for ( V_50 = 0 , V_49 = 0 ; V_50 < 14 ; V_50 ++ ) {
if ( ( V_9 -> V_10 -> V_87 ) [ V_50 + 1 ] ) {
V_48 -> V_88 [ V_49 ] . V_50 = V_50 + 1 ;
V_48 -> V_88 [ V_49 ] . V_89 = V_90 [ V_50 ] *
100000 ;
V_48 -> V_88 [ V_49 ] . V_91 = 1 ;
V_49 ++ ;
}
if ( V_49 == V_92 )
break;
}
V_48 -> V_93 = V_49 ;
V_48 -> V_94 = V_49 ;
V_48 -> V_95 = V_96 | V_97 |
V_98 | V_99 ;
V_48 -> V_100 = V_101 | V_102 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
enum V_35 V_36 ;
int V_13 ;
if ( ! ( V_23 -> V_103 & V_104 ) ) {
if ( ( V_23 -> V_28 >= V_105 ) &&
( V_23 -> V_28 <= V_106 ) )
return 0 ;
if ( ( V_9 -> V_10 -> V_28 == V_29 ) &&
( V_9 -> V_10 -> V_107 < 2 ) )
return 0 ;
}
if ( V_9 -> V_14 ) {
F_28 ( V_2 , L_11 ,
V_16 ) ;
return 0 ;
}
V_36 = V_9 -> V_10 -> V_37 ;
if ( ! V_9 -> V_108 )
return - V_109 ;
if ( V_9 -> V_10 -> V_110 . V_111 == true )
return - V_112 ;
if ( V_6 -> V_51 . V_113 & V_114 ) {
struct V_115 * V_116 = (struct V_115 * ) V_7 ;
if ( V_116 -> V_117 ) {
V_23 -> V_118 . V_119 = V_116 -> V_117 ;
memcpy ( V_23 -> V_118 . V_120 , V_116 -> V_121 ,
V_116 -> V_117 ) ;
}
}
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_122 = true ;
if ( V_9 -> V_10 -> V_28 != V_29 ) {
if ( V_9 -> V_10 -> V_21 . V_42 ) {
if ( V_36 == V_43 ) {
if ( V_9 -> V_10 -> V_44 >
V_45 ) {
F_17 ( V_2 , L_9 ,
V_16 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
F_24 ( V_123 ,
L_10 ,
V_16 ) ;
F_9 ( & V_9 -> V_10 -> V_46 ) ;
F_33 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_46 ) ;
}
}
F_38 ( V_9 -> V_10 ) ;
if ( V_9 -> V_10 -> V_124 )
V_9 -> V_10 -> V_124 ( V_2 ,
V_125 ) ;
if ( V_9 -> V_10 -> V_37 != V_43 ) {
V_9 -> V_10 -> V_126 = true ;
if ( V_23 -> V_127 )
V_23 -> V_127 ( V_23 -> V_2 ,
V_128 ) ;
F_39 ( V_9 -> V_10 , 0 ) ;
if ( V_23 -> V_127 )
V_23 -> V_127 ( V_23 -> V_2 ,
V_129 ) ;
}
V_13 = 0 ;
} else {
V_9 -> V_10 -> V_126 = true ;
V_13 = F_40 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_108 )
return - V_109 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_42 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_9 -> V_14 ) {
F_28 ( V_2 ,
L_12 ,
V_16 ) ;
return 0 ;
}
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_44 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_46 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_6 -> V_51 . V_52 > V_130 )
return - V_131 ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_51 . V_52 = F_48 ( V_132 , V_6 -> V_51 . V_52 ,
sizeof( V_9 -> V_133 ) ) ;
memset ( V_9 -> V_133 , 0 , sizeof( V_9 -> V_133 ) ) ;
memcpy ( V_9 -> V_133 , V_12 , V_6 -> V_51 . V_52 ) ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_51 . V_52 = strlen ( V_9 -> V_133 ) ;
memcpy ( V_12 , V_9 -> V_133 , V_6 -> V_51 . V_52 ) ;
V_6 -> V_51 . V_113 = 1 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_51 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_53 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
if ( V_6 -> V_134 . V_135 )
V_9 -> V_10 -> V_136 = V_137 ;
else {
if ( V_6 -> V_134 . V_138 < V_71 ||
V_6 -> V_134 . V_138 > V_73 )
return - V_139 ;
V_9 -> V_10 -> V_136 = V_6 -> V_134 . V_138 & ~ 0x1 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_134 . V_138 = V_9 -> V_10 -> V_136 ;
V_6 -> V_134 . V_140 = 0 ;
V_6 -> V_134 . V_135 = ( V_6 -> V_134 . V_138 == V_137 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_141 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_57 ( V_9 -> V_10 , V_11 , V_141 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_59 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_142 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_61 ( V_9 -> V_10 , V_11 , V_6 , V_142 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_142 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
struct V_22 * V_23 = V_9 -> V_10 ;
T_3 V_143 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_144 = 0xff ;
T_3 V_145 = 0 ;
T_1 V_146 [ 4 ] [ 6 ] = { { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
int V_50 ;
if ( V_9 -> V_14 )
return 0 ;
if ( ! V_9 -> V_108 )
return - V_109 ;
V_9 -> V_10 -> V_147 = 1 ;
F_9 ( & V_9 -> V_10 -> V_46 ) ;
F_33 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_46 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_24 ( V_148 , L_13 ) ;
V_13 = F_63 ( V_9 -> V_10 , V_11 , V_6 , V_142 ) ;
F_11 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_149 . V_113 & V_150 ) {
V_23 -> V_151 = V_23 -> V_152 = V_153 ;
F_64 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_154 , 0 ,
sizeof( struct V_155 ) * 32 ) ;
goto V_156;
}
if ( V_6 -> V_149 . V_52 != 0 ) {
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_143 [ V_50 ] |= V_142 [ 4 * V_50 + 0 ] & V_144 ;
if ( V_50 == 1 && ( 4 * V_50 + 1 ) == V_6 -> V_149 . V_52 )
V_144 = 0x00 ;
if ( V_50 == 3 && ( 4 * V_50 + 1 ) == V_6 -> V_149 . V_52 )
V_144 = 0x00 ;
V_143 [ V_50 ] |= ( V_142 [ 4 * V_50 + 1 ] & V_144 ) << 8 ;
V_143 [ V_50 ] |= ( V_142 [ 4 * V_50 + 2 ] & V_144 ) << 16 ;
V_143 [ V_50 ] |= ( V_142 [ 4 * V_50 + 3 ] & V_144 ) << 24 ;
}
switch ( V_6 -> V_149 . V_113 & V_157 ) {
case 0 :
V_145 = V_23 -> V_158 . V_159 ;
break;
case 1 :
V_145 = 0 ;
break;
case 2 :
V_145 = 1 ;
break;
case 3 :
V_145 = 2 ;
break;
case 4 :
V_145 = 3 ;
break;
default:
break;
}
if ( V_6 -> V_149 . V_52 == 0x5 ) {
V_23 -> V_151 = V_160 ;
F_65 ( V_2 ) ;
}
else if ( V_6 -> V_149 . V_52 == 0xd ) {
V_23 -> V_151 = V_161 ;
F_65 ( V_2 ) ;
F_66 ( V_2 , V_145 , V_145 , V_161 ,
V_146 [ V_145 ] , 0 , V_143 ) ;
F_67 ( V_2 , V_145 , V_145 , V_161 ,
V_146 [ V_145 ] , 0 , V_143 , 0 ) ;
} else {
F_28 ( V_2 ,
L_14 ) ;
}
}
V_156:
V_9 -> V_10 -> V_147 = 0 ;
return V_13 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_162 ,
union V_5 * V_6 , char * V_163 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_164 = ( int * ) V_163 ;
int V_38 = V_164 [ 0 ] ;
if ( V_9 -> V_14 )
return 0 ;
V_9 -> V_10 -> V_165 = V_38 ;
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_166 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_167 . V_113 & V_168 ||
V_6 -> V_167 . V_135 ) {
V_166 = - V_139 ;
goto exit;
}
if ( ! ( V_6 -> V_167 . V_113 & V_169 ) ) {
V_166 = - V_139 ;
goto exit;
}
if ( V_6 -> V_167 . V_138 > V_170 ) {
V_166 = - V_139 ;
goto exit;
}
if ( V_6 -> V_167 . V_113 & V_171 )
V_9 -> V_172 = V_6 -> V_167 . V_138 ;
else
V_9 -> V_173 = V_6 -> V_167 . V_138 ;
F_70 ( V_2 ) ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_166 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_167 . V_135 = 0 ;
if ( ( V_6 -> V_167 . V_113 & V_174 ) ==
V_168 )
return - V_139 ;
if ( V_6 -> V_167 . V_113 & V_171 ) {
V_6 -> V_167 . V_113 = V_169 | V_171 ;
V_6 -> V_167 . V_138 = V_9 -> V_172 ;
} else {
V_6 -> V_167 . V_113 = V_169 | V_175 ;
V_6 -> V_167 . V_138 = V_9 -> V_173 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_54 == NULL )
return - 1 ;
V_6 -> V_176 . V_138 = V_9 -> V_176 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
short V_166 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_9 -> V_54 == NULL ) {
V_166 = - 1 ;
goto exit;
}
if ( V_9 -> V_54 ( V_2 , V_6 -> V_176 . V_138 ) == 0 )
V_9 -> V_176 = V_6 -> V_176 . V_138 ;
else
V_166 = - V_139 ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_166 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_147 = 1 ;
F_9 ( & V_9 -> V_10 -> V_46 ) ;
F_33 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_46 ) ;
V_13 = F_75 ( V_23 , V_11 , V_6 , V_12 ) ;
{
const T_1 V_177 [ V_178 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
const T_1 V_179 [ V_178 ] = { 0 } ;
T_3 V_142 [ 4 ] = { 0 } ;
struct V_180 * V_181 = (struct V_180 * ) V_12 ;
struct V_182 * V_149 = & V_6 -> V_149 ;
T_1 V_183 = 0 , V_184 = 0 , V_185 = 0 ;
if ( ( V_149 -> V_113 & V_150 ) ||
V_181 -> V_184 == V_186 ) {
V_23 -> V_151 = V_23 -> V_152
= V_153 ;
F_64 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_154 , 0 ,
sizeof( struct V_155 ) * 32 ) ;
goto V_156;
}
V_184 = ( V_181 -> V_184 == V_187 ) ? V_188 :
V_181 -> V_184 ;
V_183 = V_149 -> V_113 & V_157 ;
if ( V_183 )
V_183 -- ;
V_185 = V_181 -> V_189 & V_190 ;
if ( ( ! V_185 ) || ( V_23 -> V_191 == V_39 ) ||
( V_184 == V_160 ) ) {
if ( ( V_181 -> V_192 == 13 ) && ( V_184 == V_160 ) )
V_184 = V_161 ;
V_23 -> V_151 = V_184 ;
F_65 ( V_2 ) ;
}
memcpy ( ( T_1 * ) V_142 , V_181 -> V_142 , 16 ) ;
if ( ( V_184 & V_160 ) && ( V_23 -> V_193 != 2 ) ) {
if ( V_181 -> V_192 == 13 )
V_23 -> V_151 = V_184 = V_161 ;
F_66 ( V_2 , V_183 , V_183 , V_184 , V_179 , 0 , V_142 ) ;
F_67 ( V_2 , V_183 , V_183 , V_184 , V_179 , 0 , V_142 , 0 ) ;
} else if ( V_185 ) {
V_23 -> V_152 = V_184 ;
F_66 ( V_2 , V_183 , V_183 , V_184 , V_177 , 0 ,
V_142 ) ;
F_67 ( V_2 , V_183 , V_183 , V_184 , V_177 , 0 ,
V_142 , 0 ) ;
} else {
if ( ( V_23 -> V_151 == V_188 ) &&
V_23 -> V_194 -> V_195 )
F_76 ( V_2 , 0x173 , 1 ) ;
F_66 ( V_2 , 4 , V_183 , V_184 ,
( T_1 * ) V_23 -> V_196 , 0 , V_142 ) ;
F_67 ( V_2 , 4 , V_183 , V_184 ,
( T_1 * ) V_23 -> V_196 , 0 , V_142 , 0 ) ;
}
}
V_156:
V_9 -> V_10 -> V_147 = 0 ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_51 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_78 ( V_9 -> V_10 , V_11 , & ( V_51 -> V_197 ) , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_80 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_51 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_82 ( V_9 -> V_10 , V_12 , V_51 -> V_51 . V_52 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_51 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
if ( V_23 -> V_198 == 0 || V_23 -> V_199 == NULL ) {
V_51 -> V_51 . V_52 = 0 ;
return 0 ;
}
if ( V_51 -> V_51 . V_52 < V_23 -> V_198 )
return - V_131 ;
V_51 -> V_51 . V_52 = V_23 -> V_198 ;
memcpy ( V_12 , V_23 -> V_199 , V_23 -> V_198 ) ;
return V_13 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
T_3 V_200 [ 3 ] ;
T_3 V_201 ;
T_3 V_202 ;
T_3 V_203 ;
if ( F_85 ( V_200 , V_6 -> V_51 . V_204 , sizeof( V_200 ) ) )
return - V_205 ;
V_201 = V_200 [ 0 ] ;
V_202 = V_200 [ 1 ] ;
V_203 = V_200 [ 2 ] ;
if ( V_201 == V_206 ) {
V_23 -> V_207 . V_202 =
( V_202 ) ? ( true ) : ( false ) ;
V_23 -> V_207 . V_203 =
( V_203 ) ? ( true ) : ( false ) ;
( V_202 ) ?
( F_86 ( V_2 , false ) ) :
( F_87 ( V_2 , false ) ) ;
F_28 ( V_2 ,
L_15 ,
V_16 , V_202 ,
V_203 ) ;
} else {
return - 1 ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
snprintf ( V_12 , 45 , L_16 ,
V_23 -> V_207 . V_202 ,
V_23 -> V_207 . V_203 ) ;
V_6 -> V_51 . V_52 = strlen ( V_12 ) + 1 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static struct V_208 * F_89 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
struct V_208 * V_209 = & V_9 -> V_209 ;
int V_210 = 0 ;
int V_211 = 0 ;
int V_212 = 0 ;
if ( V_23 -> V_28 < V_29 ) {
V_209 -> V_58 . V_58 = 10 ;
V_209 -> V_58 . V_59 = 0 ;
V_209 -> V_58 . V_60 = 0x100 - 100 ;
V_209 -> V_58 . V_61 = V_213 | V_214 ;
return V_209 ;
}
V_210 = ( & V_23 -> V_118 ) -> V_215 . V_216 ;
V_211 = ( & V_23 -> V_118 ) -> V_215 . signal ;
V_212 = ( & V_23 -> V_118 ) -> V_215 . V_60 ;
V_209 -> V_58 . V_59 = V_210 ;
V_209 -> V_58 . V_58 = V_211 ;
V_209 -> V_58 . V_60 = V_212 ;
V_209 -> V_58 . V_61 = V_213 | V_214 ;
return V_209 ;
}
