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
if ( ! V_9 -> F_11 )
return - V_108 ;
if ( V_9 -> V_10 -> V_109 . V_110 == true )
return - V_111 ;
if ( V_6 -> V_51 . V_112 & V_113 ) {
struct V_114 * V_115 = (struct V_114 * ) V_7 ;
if ( V_115 -> V_116 ) {
V_23 -> V_117 . V_118 = V_115 -> V_116 ;
memcpy ( V_23 -> V_117 . V_119 , V_115 -> V_120 ,
V_115 -> V_116 ) ;
}
}
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_121 = true ;
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
F_24 ( V_122 ,
L_10 ,
V_16 ) ;
F_9 ( & V_9 -> V_10 -> V_46 ) ;
F_33 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_46 ) ;
}
}
F_38 ( V_9 -> V_10 ) ;
if ( V_9 -> V_10 -> V_123 )
V_9 -> V_10 -> V_123 ( V_2 ,
V_124 ) ;
if ( V_9 -> V_10 -> V_37 != V_43 ) {
V_9 -> V_10 -> V_125 = true ;
if ( V_23 -> V_126 )
V_23 -> V_126 ( V_23 -> V_2 ,
V_127 ) ;
F_39 ( V_9 -> V_10 , 0 ) ;
if ( V_23 -> V_126 )
V_23 -> V_126 ( V_23 -> V_2 ,
V_128 ) ;
}
V_13 = 0 ;
} else {
V_9 -> V_10 -> V_125 = true ;
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
if ( ! V_9 -> F_11 )
return - V_108 ;
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
if ( V_6 -> V_51 . V_52 > V_129 )
return - V_130 ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_51 . V_52 = F_48 ( V_131 , V_6 -> V_51 . V_52 ,
sizeof( V_9 -> V_132 ) ) ;
memset ( V_9 -> V_132 , 0 , sizeof( V_9 -> V_132 ) ) ;
memcpy ( V_9 -> V_132 , V_12 , V_6 -> V_51 . V_52 ) ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_51 . V_52 = strlen ( V_9 -> V_132 ) ;
memcpy ( V_12 , V_9 -> V_132 , V_6 -> V_51 . V_52 ) ;
V_6 -> V_51 . V_112 = 1 ;
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
if ( V_6 -> V_133 . V_134 )
V_9 -> V_10 -> V_135 = V_136 ;
else {
if ( V_6 -> V_133 . V_137 < V_71 ||
V_6 -> V_133 . V_137 > V_73 )
return - V_138 ;
V_9 -> V_10 -> V_135 = V_6 -> V_133 . V_137 & ~ 0x1 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_133 . V_137 = V_9 -> V_10 -> V_135 ;
V_6 -> V_133 . V_139 = 0 ;
V_6 -> V_133 . V_134 = ( V_6 -> V_133 . V_137 == V_136 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_140 , char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_57 ( V_9 -> V_10 , V_11 , V_140 , V_12 ) ;
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
union V_5 * V_6 , char * V_141 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_61 ( V_9 -> V_10 , V_11 , V_6 , V_141 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_141 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
struct V_22 * V_23 = V_9 -> V_10 ;
T_3 V_142 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_143 = 0xff ;
T_3 V_144 = 0 ;
T_1 V_145 [ 4 ] [ 6 ] = { { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
int V_50 ;
if ( V_9 -> V_14 )
return 0 ;
if ( ! V_9 -> F_11 )
return - V_108 ;
V_9 -> V_10 -> V_146 = 1 ;
F_9 ( & V_9 -> V_10 -> V_46 ) ;
F_33 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_46 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_24 ( V_147 , L_13 ) ;
V_13 = F_63 ( V_9 -> V_10 , V_11 , V_6 , V_141 ) ;
F_11 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_148 . V_112 & V_149 ) {
V_23 -> V_150 = V_23 -> V_151 = V_152 ;
F_64 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_153 , 0 ,
sizeof( struct V_154 ) * 32 ) ;
goto V_155;
}
if ( V_6 -> V_148 . V_52 != 0 ) {
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
V_142 [ V_50 ] |= V_141 [ 4 * V_50 + 0 ] & V_143 ;
if ( V_50 == 1 && ( 4 * V_50 + 1 ) == V_6 -> V_148 . V_52 )
V_143 = 0x00 ;
if ( V_50 == 3 && ( 4 * V_50 + 1 ) == V_6 -> V_148 . V_52 )
V_143 = 0x00 ;
V_142 [ V_50 ] |= ( V_141 [ 4 * V_50 + 1 ] & V_143 ) << 8 ;
V_142 [ V_50 ] |= ( V_141 [ 4 * V_50 + 2 ] & V_143 ) << 16 ;
V_142 [ V_50 ] |= ( V_141 [ 4 * V_50 + 3 ] & V_143 ) << 24 ;
}
switch ( V_6 -> V_148 . V_112 & V_156 ) {
case 0 :
V_144 = V_23 -> V_157 . V_158 ;
break;
case 1 :
V_144 = 0 ;
break;
case 2 :
V_144 = 1 ;
break;
case 3 :
V_144 = 2 ;
break;
case 4 :
V_144 = 3 ;
break;
default:
break;
}
if ( V_6 -> V_148 . V_52 == 0x5 ) {
V_23 -> V_150 = V_159 ;
F_65 ( V_2 ) ;
}
else if ( V_6 -> V_148 . V_52 == 0xd ) {
V_23 -> V_150 = V_160 ;
F_65 ( V_2 ) ;
F_66 ( V_2 , V_144 , V_144 , V_160 ,
V_145 [ V_144 ] , 0 , V_142 ) ;
F_67 ( V_2 , V_144 , V_144 , V_160 ,
V_145 [ V_144 ] , 0 , V_142 , 0 ) ;
} else {
F_28 ( V_2 ,
L_14 ) ;
}
}
V_155:
V_9 -> V_10 -> V_146 = 0 ;
return V_13 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_161 ,
union V_5 * V_6 , char * V_162 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_163 = ( int * ) V_162 ;
int V_38 = V_163 [ 0 ] ;
if ( V_9 -> V_14 )
return 0 ;
V_9 -> V_10 -> V_164 = V_38 ;
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_165 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_166 . V_112 & V_167 ||
V_6 -> V_166 . V_134 ) {
V_165 = - V_138 ;
goto exit;
}
if ( ! ( V_6 -> V_166 . V_112 & V_168 ) ) {
V_165 = - V_138 ;
goto exit;
}
if ( V_6 -> V_166 . V_137 > V_169 ) {
V_165 = - V_138 ;
goto exit;
}
if ( V_6 -> V_166 . V_112 & V_170 )
V_9 -> V_171 = V_6 -> V_166 . V_137 ;
else
V_9 -> V_172 = V_6 -> V_166 . V_137 ;
F_70 ( V_2 ) ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_165 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_166 . V_134 = 0 ;
if ( ( V_6 -> V_166 . V_112 & V_173 ) ==
V_167 )
return - V_138 ;
if ( V_6 -> V_166 . V_112 & V_170 ) {
V_6 -> V_166 . V_112 = V_168 | V_170 ;
V_6 -> V_166 . V_137 = V_9 -> V_171 ;
} else {
V_6 -> V_166 . V_112 = V_168 | V_174 ;
V_6 -> V_166 . V_137 = V_9 -> V_172 ;
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
V_6 -> V_175 . V_137 = V_9 -> V_175 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
short V_165 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_9 -> V_54 == NULL ) {
V_165 = - 1 ;
goto exit;
}
if ( V_9 -> V_54 ( V_2 , V_6 -> V_175 . V_137 ) == 0 )
V_9 -> V_175 = V_6 -> V_175 . V_137 ;
else
V_165 = - V_138 ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_165 ;
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
V_9 -> V_10 -> V_146 = 1 ;
F_9 ( & V_9 -> V_10 -> V_46 ) ;
F_33 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_46 ) ;
V_13 = F_75 ( V_23 , V_11 , V_6 , V_12 ) ;
{
const T_1 V_176 [ V_177 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
const T_1 V_178 [ V_177 ] = { 0 } ;
T_3 V_141 [ 4 ] = { 0 } ;
struct V_179 * V_180 = (struct V_179 * ) V_12 ;
struct V_181 * V_148 = & V_6 -> V_148 ;
T_1 V_182 = 0 , V_183 = 0 , V_184 = 0 ;
if ( ( V_148 -> V_112 & V_149 ) ||
V_180 -> V_183 == V_185 ) {
V_23 -> V_150 = V_23 -> V_151
= V_152 ;
F_64 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_153 , 0 ,
sizeof( struct V_154 ) * 32 ) ;
goto V_155;
}
V_183 = ( V_180 -> V_183 == V_186 ) ? V_187 :
V_180 -> V_183 ;
V_182 = V_148 -> V_112 & V_156 ;
if ( V_182 )
V_182 -- ;
V_184 = V_180 -> V_188 & V_189 ;
if ( ( ! V_184 ) || ( V_23 -> V_190 == V_39 ) ||
( V_183 == V_159 ) ) {
if ( ( V_180 -> V_191 == 13 ) && ( V_183 == V_159 ) )
V_183 = V_160 ;
V_23 -> V_150 = V_183 ;
F_65 ( V_2 ) ;
}
memcpy ( ( T_1 * ) V_141 , V_180 -> V_141 , 16 ) ;
if ( ( V_183 & V_159 ) && ( V_23 -> V_192 != 2 ) ) {
if ( V_180 -> V_191 == 13 )
V_23 -> V_150 = V_183 = V_160 ;
F_66 ( V_2 , V_182 , V_182 , V_183 , V_178 , 0 , V_141 ) ;
F_67 ( V_2 , V_182 , V_182 , V_183 , V_178 , 0 , V_141 , 0 ) ;
} else if ( V_184 ) {
V_23 -> V_151 = V_183 ;
F_66 ( V_2 , V_182 , V_182 , V_183 , V_176 , 0 ,
V_141 ) ;
F_67 ( V_2 , V_182 , V_182 , V_183 , V_176 , 0 ,
V_141 , 0 ) ;
} else {
if ( ( V_23 -> V_150 == V_187 ) &&
V_23 -> V_193 -> V_194 )
F_76 ( V_2 , 0x173 , 1 ) ;
F_66 ( V_2 , 4 , V_182 , V_183 ,
( T_1 * ) V_23 -> V_195 , 0 , V_141 ) ;
F_67 ( V_2 , 4 , V_182 , V_183 ,
( T_1 * ) V_23 -> V_195 , 0 , V_141 , 0 ) ;
}
}
V_155:
V_9 -> V_10 -> V_146 = 0 ;
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
V_13 = F_78 ( V_9 -> V_10 , V_11 , & ( V_51 -> V_196 ) , V_12 ) ;
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
if ( V_23 -> V_197 == 0 || V_23 -> V_198 == NULL ) {
V_51 -> V_51 . V_52 = 0 ;
return 0 ;
}
if ( V_51 -> V_51 . V_52 < V_23 -> V_197 )
return - V_130 ;
V_51 -> V_51 . V_52 = V_23 -> V_197 ;
memcpy ( V_12 , V_23 -> V_198 , V_23 -> V_197 ) ;
return V_13 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
T_3 V_199 [ 3 ] ;
T_3 V_200 ;
T_3 V_201 ;
T_3 V_202 ;
if ( F_85 ( V_199 , V_6 -> V_51 . V_203 , sizeof( V_199 ) ) )
return - V_204 ;
V_200 = V_199 [ 0 ] ;
V_201 = V_199 [ 1 ] ;
V_202 = V_199 [ 2 ] ;
if ( V_200 == V_205 ) {
V_23 -> V_206 . V_201 =
( V_201 ) ? ( true ) : ( false ) ;
V_23 -> V_206 . V_202 =
( V_202 ) ? ( true ) : ( false ) ;
( V_201 ) ?
( F_86 ( V_2 , false ) ) :
( F_87 ( V_2 , false ) ) ;
F_28 ( V_2 ,
L_15 ,
V_16 , V_201 ,
V_202 ) ;
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
V_23 -> V_206 . V_201 ,
V_23 -> V_206 . V_202 ) ;
V_6 -> V_51 . V_52 = strlen ( V_12 ) + 1 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static struct V_207 * F_89 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_9 -> V_10 ;
struct V_207 * V_208 = & V_9 -> V_208 ;
int V_209 = 0 ;
int V_210 = 0 ;
int V_211 = 0 ;
if ( V_23 -> V_28 < V_29 ) {
V_208 -> V_58 . V_58 = 10 ;
V_208 -> V_58 . V_59 = 0 ;
V_208 -> V_58 . V_60 = 0x100 - 100 ;
V_208 -> V_58 . V_61 = V_212 | V_213 ;
return V_208 ;
}
V_209 = ( & V_23 -> V_117 ) -> V_214 . V_215 ;
V_210 = ( & V_23 -> V_117 ) -> V_214 . signal ;
V_211 = ( & V_23 -> V_117 ) -> V_214 . V_60 ;
V_208 -> V_58 . V_59 = V_209 ;
V_208 -> V_58 . V_58 = V_210 ;
V_208 -> V_58 . V_60 = V_211 ;
V_208 -> V_58 . V_61 = V_212 | V_213 ;
return V_208 ;
}
