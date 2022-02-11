static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_3 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_17 ( V_16 ,
L_1 ,
V_17 ) ;
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
F_17 ( V_18 , L_2 ,
V_17 , * V_12 ) ;
V_9 -> V_19 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
F_17 ( V_18 , L_3 , V_17 ) ;
V_21 -> V_22 = true ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
struct V_23 * V_6 , char * V_12 )
{
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_24 * V_25 = (struct V_24 * )
( & ( V_9 -> V_10 -> V_26 ) ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
F_17 ( V_27 , L_4 , V_17 , ( * V_12 == 6 ) ?
L_5 : L_6 ) ;
if ( * V_12 || V_9 -> V_28 ) {
V_9 -> V_29 = false ;
V_25 -> V_30 = true ;
} else {
if ( V_9 -> V_10 -> V_31 == V_32 )
F_28 ( V_2 ) ;
V_9 -> V_29 = true ;
V_25 -> V_30 = false ;
V_21 -> V_33 = * V_12 ;
}
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_30 ( V_2 , L_7 , V_17 , * V_12 ) ;
if ( ( * V_12 != 0 ) && ( * V_12 != 1 ) ) {
F_17 ( V_16 ,
L_8 ,
V_17 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
V_9 -> V_34 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_24 * V_25 = (struct V_24 * )
( & ( V_9 -> V_10 -> V_26 ) ) ;
F_9 ( & V_9 -> V_15 ) ;
F_30 ( V_2 , L_9 ,
V_17 , * V_12 ) ;
V_25 -> V_35 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_30 ( V_2 ,
L_10 ,
V_17 , * V_12 ) ;
V_9 -> V_28 = * V_12 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_36 = * V_12 ;
if ( V_9 -> V_14 )
return 0 ;
F_30 ( V_2 , L_11 , V_17 ,
* V_12 , V_37 ) ;
if ( V_36 > 0 )
V_37 |= ( 1 << V_36 ) ;
else
V_37 &= V_38 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = F_35 ( V_2 ) ;
enum V_39 V_40 ;
int V_13 ;
if ( V_9 -> V_14 )
return 0 ;
V_40 = V_9 -> V_10 -> V_41 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_42 == V_43 || V_6 -> V_42 == V_44 ||
V_21 -> V_45 ) {
if ( V_9 -> V_10 -> V_26 . V_46 ) {
if ( V_40 == V_47 ) {
if ( V_9 -> V_10 -> V_48 >
V_49 ) {
F_17 ( V_16 , L_12 ,
V_17 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
F_30 ( V_2 , L_13 ,
V_17 ) ;
F_9 ( & V_9 -> V_10 -> V_50 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_50 ) ;
}
}
}
V_13 = F_37 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_51 * V_52 = (struct V_51 * ) V_12 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_2 V_53 ;
int V_54 ;
V_6 -> V_55 . V_56 = sizeof( * V_52 ) ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> V_57 = 130 * 1000 * 1000 ;
if ( V_9 -> V_58 != NULL ) {
V_52 -> V_59 = V_9 -> V_60 ;
}
V_52 -> V_61 . V_62 = 100 ;
V_52 -> V_61 . V_63 = 0 ;
V_52 -> V_61 . V_64 = 0 ;
V_52 -> V_61 . V_65 = 7 ;
V_52 -> V_66 . V_62 = 70 ;
V_52 -> V_66 . V_63 = 0 ;
V_52 -> V_66 . V_64 = 0 ;
V_52 -> V_66 . V_65 = 7 ;
V_52 -> V_67 = F_39 ( V_68 , V_69 ) ;
for ( V_54 = 0 ; V_54 < V_52 -> V_67 ; V_54 ++ )
V_52 -> V_70 [ V_54 ] = V_71 [ V_54 ] ;
V_52 -> V_72 = V_73 ;
V_52 -> V_74 = V_75 ;
V_52 -> V_76 = V_77 ;
V_52 -> V_78 = 0 ;
V_52 -> V_79 = 5000000 ;
V_52 -> V_80 = 0 ;
V_52 -> V_81 = 65535 * 1000 ;
V_52 -> V_82 = V_83 ;
V_52 -> V_84 = V_85 ;
V_52 -> V_86 = V_83 | V_85 | V_87 ;
V_52 -> V_88 = V_89 ;
V_52 -> V_90 = 18 ;
for ( V_54 = 0 , V_53 = 0 ; V_54 < 14 ; V_54 ++ ) {
if ( ( V_9 -> V_10 -> V_91 ) [ V_54 + 1 ] ) {
V_52 -> V_92 [ V_53 ] . V_54 = V_54 + 1 ;
V_52 -> V_92 [ V_53 ] . V_93 = V_94 [ V_54 ] *
100000 ;
V_52 -> V_92 [ V_53 ] . V_95 = 1 ;
V_53 ++ ;
}
if ( V_53 == V_96 )
break;
}
V_52 -> V_97 = V_53 ;
V_52 -> V_98 = V_53 ;
V_52 -> V_99 = V_100 | V_101 |
V_102 | V_103 ;
V_52 -> V_104 = V_105 | V_106 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
enum V_39 V_40 ;
int V_13 ;
if ( ! ( V_21 -> V_107 & V_108 ) ) {
if ( ( V_21 -> V_31 >= V_109 ) &&
( V_21 -> V_31 <= V_110 ) )
return 0 ;
if ( ( V_9 -> V_10 -> V_31 == V_32 ) &&
( V_9 -> V_10 -> V_111 < 2 ) )
return 0 ;
}
if ( V_9 -> V_14 ) {
F_30 ( V_2 , L_14 ,
V_17 ) ;
return 0 ;
}
V_40 = V_9 -> V_10 -> V_41 ;
if ( ! V_9 -> F_11 )
return - V_112 ;
if ( V_9 -> V_10 -> V_113 . V_114 == true )
return - V_115 ;
if ( V_6 -> V_55 . V_116 & V_117 ) {
struct V_118 * V_119 = (struct V_118 * ) V_7 ;
if ( V_119 -> V_120 ) {
V_21 -> V_121 . V_122 = V_119 -> V_120 ;
memcpy ( V_21 -> V_121 . V_123 , V_119 -> V_124 ,
V_119 -> V_120 ) ;
}
}
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_125 = true ;
if ( V_9 -> V_10 -> V_31 != V_32 ) {
if ( V_9 -> V_10 -> V_26 . V_46 ) {
if ( V_40 == V_47 ) {
if ( V_9 -> V_10 -> V_48 >
V_49 ) {
F_17 ( V_16 ,
L_12 ,
V_17 ) ;
F_11 ( & V_9 -> V_15 ) ;
return - 1 ;
}
F_17 ( V_126 , L_13 ,
V_17 ) ;
F_9 ( & V_9 -> V_10 -> V_50 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_50 ) ;
}
}
F_41 ( V_9 -> V_10 ) ;
if ( V_9 -> V_10 -> V_127 )
V_9 -> V_10 -> V_127 ( V_2 ,
V_128 ) ;
if ( V_9 -> V_10 -> V_41 != V_47 ) {
V_9 -> V_10 -> V_129 = true ;
if ( V_21 -> V_130 )
V_21 -> V_130 ( V_21 -> V_2 ,
V_131 ) ;
F_42 ( V_9 -> V_10 , 0 ) ;
if ( V_21 -> V_130 )
V_21 -> V_130 ( V_21 -> V_2 ,
V_132 ) ;
}
V_13 = 0 ;
} else {
V_9 -> V_10 -> V_129 = true ;
V_13 = F_43 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
}
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> F_11 )
return - V_112 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_45 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_9 -> V_14 ) {
F_30 ( V_2 ,
L_15 ,
V_17 ) ;
return 0 ;
}
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_47 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_49 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_6 -> V_55 . V_56 > V_133 )
return - V_134 ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_55 . V_56 = F_51 ( V_135 , V_6 -> V_55 . V_56 , sizeof( V_9 -> V_136 ) ) ;
memset ( V_9 -> V_136 , 0 , sizeof( V_9 -> V_136 ) ) ;
memcpy ( V_9 -> V_136 , V_12 , V_6 -> V_55 . V_56 ) ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( & V_9 -> V_15 ) ;
V_6 -> V_55 . V_56 = strlen ( V_9 -> V_136 ) ;
memcpy ( V_12 , V_9 -> V_136 , V_6 -> V_55 . V_56 ) ;
V_6 -> V_55 . V_116 = 1 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_54 ( V_9 -> V_10 , V_4 , V_6 , V_7 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_56 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
if ( V_6 -> V_137 . V_138 )
V_9 -> V_10 -> V_139 = V_140 ;
else {
if ( V_6 -> V_137 . V_141 < V_75 ||
V_6 -> V_137 . V_141 > V_77 )
return - V_142 ;
V_9 -> V_10 -> V_139 = V_6 -> V_137 . V_141 & ~ 0x1 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_137 . V_141 = V_9 -> V_10 -> V_139 ;
V_6 -> V_137 . V_143 = 0 ;
V_6 -> V_137 . V_138 = ( V_6 -> V_137 . V_141 == V_140 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_144 ,
char * V_12 )
{
int V_13 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_60 ( V_9 -> V_10 , V_11 , V_144 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_62 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_145 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_64 ( V_9 -> V_10 , V_11 , V_6 , V_145 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_145 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
struct V_20 * V_21 = V_9 -> V_10 ;
T_3 V_146 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_147 = 0xff ;
T_3 V_148 = 0 ;
T_1 V_149 [ 4 ] [ 6 ] = { { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 } ,
{ 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 } } ;
int V_54 ;
if ( V_9 -> V_14 )
return 0 ;
if ( ! V_9 -> F_11 )
return - V_112 ;
V_9 -> V_10 -> V_150 = 1 ;
F_9 ( & V_9 -> V_10 -> V_50 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_50 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_17 ( V_151 , L_16 ) ;
V_13 = F_66 ( V_9 -> V_10 , V_11 , V_6 , V_145 ) ;
F_11 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_152 . V_116 & V_153 ) {
V_21 -> V_154 = V_21 -> V_155 = V_156 ;
F_67 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_157 , 0 ,
sizeof( struct V_158 ) * 32 ) ;
goto V_159;
}
if ( V_6 -> V_152 . V_56 != 0 ) {
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_146 [ V_54 ] |= V_145 [ 4 * V_54 + 0 ] & V_147 ;
if ( V_54 == 1 && ( 4 * V_54 + 1 ) == V_6 -> V_152 . V_56 )
V_147 = 0x00 ;
if ( V_54 == 3 && ( 4 * V_54 + 1 ) == V_6 -> V_152 . V_56 )
V_147 = 0x00 ;
V_146 [ V_54 ] |= ( V_145 [ 4 * V_54 + 1 ] & V_147 ) << 8 ;
V_146 [ V_54 ] |= ( V_145 [ 4 * V_54 + 2 ] & V_147 ) << 16 ;
V_146 [ V_54 ] |= ( V_145 [ 4 * V_54 + 3 ] & V_147 ) << 24 ;
}
#define F_68 0x4
#define F_69 0x14
switch ( V_6 -> V_152 . V_116 & V_160 ) {
case 0 :
V_148 = V_21 -> V_161 . V_162 ;
break;
case 1 :
V_148 = 0 ;
break;
case 2 :
V_148 = 1 ;
break;
case 3 :
V_148 = 2 ;
break;
case 4 :
V_148 = 3 ;
break;
default:
break;
}
if ( V_6 -> V_152 . V_56 == 0x5 ) {
V_21 -> V_154 = V_163 ;
F_70 ( V_2 ) ;
}
else if ( V_6 -> V_152 . V_56 == 0xd ) {
V_21 -> V_154 = V_164 ;
F_70 ( V_2 ) ;
F_71 ( V_2 , V_148 , V_148 , V_164 ,
V_149 [ V_148 ] , 0 , V_146 ) ;
F_72 ( V_2 , V_148 , V_148 , V_164 ,
V_149 [ V_148 ] , 0 , V_146 , 0 ) ;
} else {
F_30 ( V_2 ,
L_17 ) ;
}
}
V_159:
V_9 -> V_10 -> V_150 = 0 ;
return V_13 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_165 ,
union V_5 * V_6 , char * V_166 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int * V_167 = ( int * ) V_166 ;
int V_42 = V_167 [ 0 ] ;
if ( V_9 -> V_14 )
return 0 ;
V_9 -> V_10 -> V_168 = V_42 ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_169 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_6 -> V_170 . V_116 & V_171 ||
V_6 -> V_170 . V_138 ) {
V_169 = - V_142 ;
goto exit;
}
if ( ! ( V_6 -> V_170 . V_116 & V_172 ) ) {
V_169 = - V_142 ;
goto exit;
}
if ( V_6 -> V_170 . V_141 > V_173 ) {
V_169 = - V_142 ;
goto exit;
}
if ( V_6 -> V_170 . V_116 & V_174 ) {
V_9 -> V_175 = V_6 -> V_170 . V_141 ;
F_75 ( L_18 ,
V_6 -> V_170 . V_141 ) ;
} else {
V_9 -> V_176 = V_6 -> V_170 . V_141 ;
F_75 ( L_19 ,
V_6 -> V_170 . V_141 ) ;
}
F_76 ( V_2 ) ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_169 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_6 -> V_170 . V_138 = 0 ;
if ( ( V_6 -> V_170 . V_116 & V_177 ) ==
V_171 )
return - V_142 ;
if ( V_6 -> V_170 . V_116 & V_174 ) {
V_6 -> V_170 . V_116 = V_172 | V_174 ;
V_6 -> V_170 . V_141 = V_9 -> V_175 ;
} else {
V_6 -> V_170 . V_116 = V_172 | V_178 ;
V_6 -> V_170 . V_141 = V_9 -> V_176 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_58 == NULL )
return - 1 ;
V_6 -> V_179 . V_141 = V_9 -> V_179 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
short V_169 = 0 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
if ( V_9 -> V_58 == NULL ) {
V_169 = - 1 ;
goto exit;
}
if ( V_9 -> V_58 ( V_2 , V_6 -> V_179 . V_141 ) == 0 )
V_9 -> V_179 = V_6 -> V_179 . V_141 ;
else
V_169 = - V_142 ;
exit:
F_11 ( & V_9 -> V_15 ) ;
return V_169 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_9 -> V_10 -> V_150 = 1 ;
F_9 ( & V_9 -> V_10 -> V_50 ) ;
F_36 ( V_2 ) ;
F_11 ( & V_9 -> V_10 -> V_50 ) ;
V_13 = F_81 ( V_21 , V_11 , V_6 , V_12 ) ;
{
T_1 V_180 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
T_1 V_181 [ 6 ] = { 0 } ;
T_3 V_145 [ 4 ] = { 0 } ;
struct V_182 * V_183 = (struct V_182 * ) V_12 ;
struct V_184 * V_152 = & V_6 -> V_152 ;
T_1 V_185 = 0 , V_186 = 0 , V_187 = 0 ;
if ( ( V_152 -> V_116 & V_153 ) ||
V_183 -> V_186 == V_188 ) {
V_21 -> V_154 = V_21 -> V_155
= V_156 ;
F_67 ( V_2 ) ;
memset ( V_9 -> V_10 -> V_157 , 0 ,
sizeof( struct V_158 ) * 32 ) ;
goto V_159;
}
V_186 = ( V_183 -> V_186 == V_189 ) ? V_190 :
V_183 -> V_186 ;
V_185 = V_152 -> V_116 & V_160 ;
if ( V_185 )
V_185 -- ;
V_187 = V_183 -> V_191 & V_192 ;
if ( ( ! V_187 ) || ( V_43 == V_21 -> V_193 ) ||
( V_186 == V_163 ) ) {
if ( ( V_183 -> V_194 == 13 ) && ( V_186 == V_163 ) )
V_186 = V_164 ;
V_21 -> V_154 = V_186 ;
F_70 ( V_2 ) ;
}
memcpy ( ( T_1 * ) V_145 , V_183 -> V_145 , 16 ) ;
if ( ( V_186 & V_163 ) && ( V_21 -> V_195 != 2 ) ) {
if ( V_183 -> V_194 == 13 )
V_21 -> V_154 = V_186 = V_164 ;
F_71 ( V_2 , V_185 , V_185 , V_186 , V_181 , 0 , V_145 ) ;
F_72 ( V_2 , V_185 , V_185 , V_186 , V_181 , 0 , V_145 , 0 ) ;
} else if ( V_187 ) {
V_21 -> V_155 = V_186 ;
F_71 ( V_2 , V_185 , V_185 , V_186 , V_180 , 0 , V_145 ) ;
F_72 ( V_2 , V_185 , V_185 , V_186 , V_180 , 0 ,
V_145 , 0 ) ;
} else {
if ( ( V_21 -> V_154 == V_190 ) &&
V_21 -> V_196 -> V_197 )
F_82 ( V_2 , 0x173 , 1 ) ;
F_71 ( V_2 , 4 , V_185 , V_186 , ( T_1 * ) V_21 -> V_198 ,
0 , V_145 ) ;
F_72 ( V_2 , 4 , V_185 , V_186 , ( T_1 * ) V_21 -> V_198 ,
0 , V_145 , 0 ) ;
}
}
V_159:
V_9 -> V_10 -> V_150 = 0 ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_55 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_84 ( V_9 -> V_10 , V_11 , & ( V_55 -> V_199 ) , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_86 ( V_9 -> V_10 , V_11 , V_6 , V_12 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_55 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_14 )
return 0 ;
F_9 ( & V_9 -> V_15 ) ;
V_13 = F_88 ( V_9 -> V_10 , V_12 , V_55 -> V_55 . V_56 ) ;
F_11 ( & V_9 -> V_15 ) ;
return V_13 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_55 , char * V_12 )
{
int V_13 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
if ( V_21 -> V_200 == 0 || V_21 -> V_201 == NULL ) {
V_55 -> V_55 . V_56 = 0 ;
return 0 ;
}
if ( V_55 -> V_55 . V_56 < V_21 -> V_200 )
return - V_134 ;
V_55 -> V_55 . V_56 = V_21 -> V_200 ;
memcpy ( V_12 , V_21 -> V_201 , V_21 -> V_200 ) ;
return V_13 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
T_3 V_202 [ 3 ] ;
T_3 V_203 ;
T_3 V_204 ;
T_3 V_205 ;
if ( F_91 ( V_202 , V_6 -> V_55 . V_206 , sizeof( V_202 ) ) )
return - V_207 ;
V_203 = V_202 [ 0 ] ;
V_204 = V_202 [ 1 ] ;
V_205 = V_202 [ 2 ] ;
if ( V_208 == V_203 ) {
V_21 -> V_209 . V_204 =
( V_204 ) ? ( true ) : ( false ) ;
V_21 -> V_209 . V_205 =
( V_205 ) ? ( true ) : ( false ) ;
( V_204 ) ?
( F_92 ( V_2 , false ) ) :
( F_93 ( V_2 , false ) ) ;
F_30 ( V_2 ,
L_20 ,
V_17 , V_204 ,
V_205 ) ;
} else {
return - 1 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_3 * V_11 ,
union V_5 * V_6 , char * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
F_9 ( & V_9 -> V_15 ) ;
snprintf ( V_12 , 45 , L_21 ,
V_21 -> V_209 . V_204 ,
V_21 -> V_209 . V_205 ) ;
V_6 -> V_55 . V_56 = strlen ( V_12 ) + 1 ;
F_11 ( & V_9 -> V_15 ) ;
return 0 ;
}
static struct V_210 * F_95 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_9 -> V_10 ;
struct V_210 * V_211 = & V_9 -> V_211 ;
int V_212 = 0 ;
int V_213 = 0 ;
int V_214 = 0 ;
if ( V_21 -> V_31 < V_32 ) {
V_211 -> V_62 . V_62 = 10 ;
V_211 -> V_62 . V_63 = 0 ;
V_211 -> V_62 . V_64 = - 100 ;
V_211 -> V_62 . V_65 = V_215 | V_216 ;
return V_211 ;
}
V_212 = ( & V_21 -> V_121 ) -> V_217 . V_218 ;
V_213 = ( & V_21 -> V_121 ) -> V_217 . signal ;
V_214 = ( & V_21 -> V_121 ) -> V_217 . V_64 ;
V_211 -> V_62 . V_63 = V_212 ;
V_211 -> V_62 . V_62 = V_213 ;
V_211 -> V_62 . V_64 = V_214 ;
V_211 -> V_62 . V_65 = V_215 | V_216 ;
return V_211 ;
}
