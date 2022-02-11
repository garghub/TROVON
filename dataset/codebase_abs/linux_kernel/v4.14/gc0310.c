static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 * V_5 )
{
int V_6 ;
struct V_7 V_8 [ 2 ] ;
unsigned char V_9 [ 1 ] ;
if ( ! V_2 -> V_10 ) {
F_2 ( & V_2 -> V_11 , L_1 ,
V_12 ) ;
return - V_13 ;
}
if ( V_3 != V_14 ) {
F_2 ( & V_2 -> V_11 , L_2 ,
V_12 ) ;
return - V_15 ;
}
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ 0 ] . V_16 = V_2 -> V_16 ;
V_8 [ 0 ] . V_17 = 0 ;
V_8 [ 0 ] . V_18 = V_19 ;
V_8 [ 0 ] . V_20 = V_9 ;
V_9 [ 0 ] = ( T_2 ) ( V_4 & 0xff ) ;
V_8 [ 1 ] . V_16 = V_2 -> V_16 ;
V_8 [ 1 ] . V_18 = V_3 ;
V_8 [ 1 ] . V_17 = V_21 ;
V_8 [ 1 ] . V_20 = V_9 ;
V_6 = F_3 ( V_2 -> V_10 , V_8 , 2 ) ;
if ( V_6 != 2 ) {
if ( V_6 >= 0 )
V_6 = - V_22 ;
F_2 ( & V_2 -> V_11 ,
L_3 , V_4 , V_6 ) ;
return V_6 ;
}
* V_5 = 0 ;
if ( V_3 == V_14 )
* V_5 = ( T_2 ) V_9 [ 0 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_18 , T_2 * V_9 )
{
struct V_7 V_8 ;
const int V_23 = 1 ;
int V_24 ;
V_8 . V_16 = V_2 -> V_16 ;
V_8 . V_17 = 0 ;
V_8 . V_18 = V_18 ;
V_8 . V_20 = V_9 ;
V_24 = F_3 ( V_2 -> V_10 , & V_8 , 1 ) ;
return V_24 == V_23 ? 0 : - V_22 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_24 ;
unsigned char V_9 [ 2 ] = { 0 } ;
T_2 * V_25 = ( T_2 * ) V_9 ;
const T_1 V_18 = V_3 + sizeof( T_2 ) ;
if ( V_3 != V_14 ) {
F_2 ( & V_2 -> V_11 ,
L_4 , V_12 ) ;
return - V_15 ;
}
* V_25 = ( T_2 ) ( V_4 & 0xff ) ;
if ( V_3 == V_14 )
V_9 [ 1 ] = ( T_2 ) ( V_5 ) ;
V_24 = F_4 ( V_2 , V_18 , V_9 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 ,
L_5 ,
V_5 , V_4 , V_24 ) ;
return V_24 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
T_1 V_28 ;
if ( V_27 -> V_29 == 0 )
return 0 ;
V_28 = sizeof( T_2 ) + V_27 -> V_29 ;
V_27 -> V_30 . V_16 = ( T_2 ) ( V_27 -> V_30 . V_16 ) ;
V_27 -> V_29 = 0 ;
return F_4 ( V_2 , V_28 , ( T_2 * ) & V_27 -> V_30 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
const struct V_31 * V_32 )
{
int V_28 ;
switch ( V_32 -> type ) {
case V_14 :
V_28 = 1 ;
V_27 -> V_30 . V_9 [ V_27 -> V_29 ] = ( T_2 ) V_32 -> V_5 ;
break;
default:
return - V_15 ;
}
if ( V_27 -> V_29 == 0 )
V_27 -> V_30 . V_16 = V_32 -> V_4 ;
V_27 -> V_29 += V_28 ;
if ( V_27 -> V_29 + sizeof( T_2 ) >= V_33 )
return F_6 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
const struct V_31 * V_32 )
{
if ( V_27 -> V_29 == 0 )
return 1 ;
return V_27 -> V_30 . V_16 + V_27 -> V_29 == V_32 -> V_4 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_31 * V_34 )
{
const struct V_31 * V_32 = V_34 ;
struct V_26 V_27 ;
int V_6 ;
V_27 . V_29 = 0 ;
for (; V_32 -> type != V_35 ; V_32 ++ ) {
switch ( V_32 -> type & V_36 ) {
case V_37 :
V_6 = F_6 ( V_2 , & V_27 ) ;
if ( V_6 )
return V_6 ;
F_10 ( V_32 -> V_5 ) ;
break;
default:
if ( ! F_8 ( V_2 , & V_27 ,
V_32 ) ) {
V_6 = F_6 ( V_2 , & V_27 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_7 ( V_2 , & V_27 , V_32 ) ;
if ( V_6 ) {
F_2 ( & V_2 -> V_11 , L_6 ,
V_12 ) ;
return V_6 ;
}
break;
}
}
return F_6 ( V_2 , & V_27 ) ;
}
static int F_11 ( struct V_38 * V_39 , T_3 * V_5 )
{
* V_5 = ( V_40 << 16 ) | V_41 ;
return 0 ;
}
static int F_12 ( struct V_38 * V_39 , T_3 * V_5 )
{
* V_5 = ( V_42 << 16 ) | V_43 ;
return 0 ;
}
static int F_13 ( struct V_38 * V_39 , T_3 * V_5 )
{
* V_5 = ( V_42 << 24 ) |
( V_43 << 16 ) |
( V_42 << 8 ) | V_43 ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 , T_3 * V_5 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
* V_5 = V_45 [ V_11 -> V_46 ] . V_47 ;
return 0 ;
}
static int F_16 ( struct V_38 * V_39 , T_3 * V_5 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
* V_5 = V_45 [ V_11 -> V_46 ] . V_48 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
const struct V_51 * V_52 )
{
struct V_38 * V_39 = F_18 ( V_2 ) ;
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_53 * V_20 = & V_50 -> V_9 ;
T_1 V_5 ;
T_2 V_54 ;
int V_24 ;
unsigned int V_55 ;
unsigned int V_56 ;
unsigned int V_57 ;
if ( ! V_50 )
return - V_15 ;
V_11 -> V_58 = 14400000 ;
V_20 -> V_58 = V_11 -> V_58 ;
F_19 ( L_7 , V_20 -> V_58 ) ;
V_20 -> V_59 = V_60 ;
V_20 -> V_61 =
V_62 ;
V_20 -> V_63 = V_64 ;
V_20 -> V_65 =
V_66 ;
V_20 -> V_67 = V_64 ;
V_20 -> V_68 = V_52 -> V_69 ;
V_24 = F_1 ( V_2 , V_14 ,
V_70 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_5 = ( V_54 & 0xFF ) << 8 ;
V_24 = F_1 ( V_2 , V_14 ,
V_71 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_20 -> V_72 = V_5 | ( V_54 & 0xFF ) ;
F_19 ( L_8 , V_20 -> V_72 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_73 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_5 = ( V_54 & 0xFF ) << 8 ;
V_24 = F_1 ( V_2 , V_14 ,
V_74 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_20 -> V_75 = V_5 | ( V_54 & 0xFF ) ;
F_19 ( L_9 , V_20 -> V_75 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_76 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_5 = ( V_54 & 0xFF ) << 8 ;
V_24 = F_1 ( V_2 , V_14 ,
V_77 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_20 -> V_78 = V_5 | ( V_54 & 0xFF ) ;
F_19 ( L_10 , V_20 -> V_78 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_79 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_5 = ( V_54 & 0xFF ) << 8 ;
V_24 = F_1 ( V_2 , V_14 ,
V_80 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_20 -> V_81 = V_5 | ( V_54 & 0xFF ) ;
F_19 ( L_11 , V_20 -> V_81 ) ;
V_20 -> V_82 = V_20 -> V_72 + V_20 -> V_78 - 1 ;
V_20 -> V_83 = V_20 -> V_75 + V_20 -> V_81 - 1 ;
F_19 ( L_12 , V_20 -> V_82 ) ;
F_19 ( L_13 , V_20 -> V_83 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_84 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_5 = ( V_54 & 0xFF ) << 8 ;
V_24 = F_1 ( V_2 , V_14 ,
V_85 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_55 = V_5 | ( V_54 & 0xFF ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_86 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_57 = V_54 ;
V_20 -> V_87 = V_20 -> V_78 + V_55 + V_57 + 4 ;
F_19 ( L_14 , V_55 , V_57 , V_20 -> V_87 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_88 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_5 = ( V_54 & 0xFF ) << 8 ;
V_24 = F_1 ( V_2 , V_14 ,
V_89 , & V_54 ) ;
if ( V_24 )
return V_24 ;
V_56 = V_5 | ( V_54 & 0xFF ) ;
V_20 -> V_90 = V_20 -> V_81 + V_56 ;
F_19 ( L_15 , V_56 , V_20 -> V_90 ) ;
V_20 -> V_91 = V_52 -> V_47 ?
V_52 -> V_47 : 1 ;
V_20 -> V_92 = V_52 -> V_48 ?
V_52 -> V_48 : 1 ;
return 0 ;
}
static int F_20 ( struct V_38 * V_39 , int V_93 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_24 ;
T_2 V_94 , V_95 ;
if ( V_93 < 0x20 )
V_93 = 0x20 ;
if ( V_93 > 0x80 )
V_93 = 0x80 ;
if ( V_93 >= 0x20 && V_93 < 0x40 ) {
V_94 = 0x0 ;
V_95 = V_93 ;
} else {
V_94 = 0x2 ;
V_95 = V_93 / 2 ;
}
F_19 ( L_16 , V_93 , V_94 , V_95 ) ;
V_24 = F_5 ( V_2 , V_14 ,
V_96 , V_94 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_5 ( V_2 , V_14 ,
V_97 , V_95 ) ;
if ( V_24 )
return V_24 ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 , int V_98 ,
int V_93 , int V_99 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_24 ;
F_19 ( L_17 , V_98 , V_93 , V_99 ) ;
V_24 = F_5 ( V_2 , V_14 ,
V_100 ,
V_98 & 0xff ) ;
if ( V_24 )
return V_24 ;
V_24 = F_5 ( V_2 , V_14 ,
V_101 ,
( V_98 >> 8 ) & 0x0f ) ;
if ( V_24 )
return V_24 ;
V_24 = F_20 ( V_39 , V_93 ) ;
if ( V_24 )
return V_24 ;
return V_24 ;
}
static int F_23 ( struct V_38 * V_39 , int V_102 ,
int V_93 , int V_99 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
int V_24 ;
F_24 ( & V_11 -> V_103 ) ;
V_24 = F_22 ( V_39 , V_102 , V_93 , V_99 ) ;
F_25 ( & V_11 -> V_103 ) ;
return V_24 ;
}
static long F_26 ( struct V_38 * V_39 ,
struct V_104 * V_102 )
{
int exp = V_102 -> V_105 [ 0 ] ;
int V_93 = V_102 -> V_93 [ 0 ] ;
int V_99 = V_102 -> V_93 [ 1 ] ;
if ( V_93 == 0 ) {
struct V_1 * V_2 = F_21 ( V_39 ) ;
F_27 ( V_2 , L_18 , V_12 ) ;
return - V_15 ;
}
return F_23 ( V_39 , exp , V_93 , V_99 ) ;
}
static int F_28 ( struct V_38 * V_39 , T_3 V_106 )
{
return 0 ;
}
static int F_29 ( struct V_38 * V_39 , T_3 V_106 )
{
return 0 ;
}
static long F_30 ( struct V_38 * V_39 , unsigned int V_107 , void * V_108 )
{
switch ( V_107 ) {
case V_109 :
return F_26 ( V_39 , V_108 ) ;
default:
return - V_15 ;
}
return 0 ;
}
static int F_31 ( struct V_38 * V_39 , T_3 * V_106 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
T_2 V_110 ;
int V_24 ;
V_24 = F_1 ( V_2 , V_14 ,
V_100 ,
& V_110 ) ;
if ( V_24 )
goto V_6;
* V_106 = V_110 ;
V_24 = F_1 ( V_2 , V_14 ,
V_101 ,
& V_110 ) ;
if ( V_24 )
goto V_6;
* V_106 = * V_106 + ( V_110 << 8 ) ;
V_6:
return V_24 ;
}
static int F_32 ( struct V_111 * V_27 )
{
struct V_44 * V_11 =
F_33 ( V_27 -> V_112 , struct V_44 , V_113 ) ;
struct V_1 * V_2 = F_21 ( & V_11 -> V_39 ) ;
int V_24 = 0 ;
switch ( V_27 -> V_114 ) {
case V_115 :
F_34 ( & V_2 -> V_11 , L_19 ,
V_12 , V_27 -> V_5 ) ;
V_24 = F_28 ( & V_11 -> V_39 , V_27 -> V_5 ) ;
break;
case V_116 :
F_34 ( & V_2 -> V_11 , L_20 ,
V_12 , V_27 -> V_5 ) ;
V_24 = F_29 ( & V_11 -> V_39 , V_27 -> V_5 ) ;
break;
default:
V_24 = - V_15 ;
}
return V_24 ;
}
static int F_35 ( struct V_111 * V_27 )
{
struct V_44 * V_11 =
F_33 ( V_27 -> V_112 , struct V_44 , V_113 ) ;
int V_24 = 0 ;
switch ( V_27 -> V_114 ) {
case V_117 :
V_24 = F_31 ( & V_11 -> V_39 , & V_27 -> V_5 ) ;
break;
case V_118 :
V_24 = F_11 ( & V_11 -> V_39 , & V_27 -> V_5 ) ;
break;
case V_119 :
V_24 = F_12 ( & V_11 -> V_39 , & V_27 -> V_5 ) ;
break;
case V_120 :
V_24 = F_13 ( & V_11 -> V_39 , & V_27 -> V_5 ) ;
break;
case V_121 :
V_24 = F_14 ( & V_11 -> V_39 , & V_27 -> V_5 ) ;
break;
case V_122 :
V_24 = F_16 ( & V_11 -> V_39 , & V_27 -> V_5 ) ;
break;
default:
V_24 = - V_15 ;
}
return V_24 ;
}
static int F_36 ( struct V_38 * V_39 )
{
int V_24 ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
struct V_44 * V_11 = F_15 ( V_39 ) ;
F_19 ( L_21 , V_12 ) ;
F_24 ( & V_11 -> V_103 ) ;
V_24 = F_9 ( V_2 , V_123 ) ;
V_45 = V_124 ;
V_125 = V_126 ;
F_25 ( & V_11 -> V_103 ) ;
F_19 ( L_22 , V_12 ) ;
return 0 ;
}
static int F_37 ( struct V_38 * V_39 , bool V_127 )
{
int V_24 = 0 ;
struct V_44 * V_11 = F_15 ( V_39 ) ;
if ( ! V_11 || ! V_11 -> V_128 )
return - V_13 ;
if ( V_11 -> V_128 -> F_37 )
return V_11 -> V_128 -> F_37 ( V_39 , V_127 ) ;
if ( V_127 ) {
V_24 |= V_11 -> V_128 -> V_129 ( V_39 , 1 ) ;
V_24 |= V_11 -> V_128 -> V_130 ( V_39 , 1 ) ;
F_38 ( 10000 , 15000 ) ;
}
if ( ! V_127 || V_24 ) {
V_24 |= V_11 -> V_128 -> V_129 ( V_39 , 0 ) ;
V_24 |= V_11 -> V_128 -> V_130 ( V_39 , 0 ) ;
}
return V_24 ;
}
static int F_39 ( struct V_38 * V_39 , bool V_127 )
{
int V_24 ;
struct V_44 * V_11 = F_15 ( V_39 ) ;
if ( ! V_11 || ! V_11 -> V_128 )
return - V_13 ;
if ( V_11 -> V_128 -> F_39 )
return V_11 -> V_128 -> F_39 ( V_39 , V_127 ) ;
if ( V_127 ) {
V_24 = V_11 -> V_128 -> V_131 ( V_39 , 0 ) ;
F_38 ( 5000 , 10000 ) ;
V_24 |= V_11 -> V_128 -> V_131 ( V_39 , 1 ) ;
F_38 ( 10000 , 15000 ) ;
V_24 |= V_11 -> V_128 -> V_132 ( V_39 , 0 ) ;
F_38 ( 10000 , 15000 ) ;
} else {
V_24 = V_11 -> V_128 -> V_132 ( V_39 , 1 ) ;
V_24 |= V_11 -> V_128 -> V_131 ( V_39 , 0 ) ;
}
return V_24 ;
}
static int F_40 ( struct V_38 * V_39 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_24 ;
F_19 ( L_21 , V_12 ) ;
if ( ! V_11 -> V_128 ) {
F_2 ( & V_2 -> V_11 ,
L_23 ) ;
return - V_13 ;
}
V_24 = F_37 ( V_39 , 1 ) ;
if ( V_24 )
goto V_133;
V_24 = V_11 -> V_128 -> V_134 ( V_39 , 1 ) ;
if ( V_24 )
goto V_135;
V_24 = F_39 ( V_39 , 1 ) ;
if ( V_24 ) {
V_24 = F_39 ( V_39 , 1 ) ;
if ( V_24 )
goto V_136;
}
F_10 ( 100 ) ;
F_19 ( L_22 , V_12 ) ;
return 0 ;
V_136:
V_11 -> V_128 -> V_134 ( V_39 , 0 ) ;
V_135:
F_37 ( V_39 , 0 ) ;
V_133:
F_2 ( & V_2 -> V_11 , L_24 ) ;
return V_24 ;
}
static int F_41 ( struct V_38 * V_39 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_24 = 0 ;
if ( ! V_11 -> V_128 ) {
F_2 ( & V_2 -> V_11 ,
L_23 ) ;
return - V_13 ;
}
V_24 = F_39 ( V_39 , 0 ) ;
if ( V_24 ) {
V_24 = F_39 ( V_39 , 0 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 , L_25 ) ;
}
V_24 = V_11 -> V_128 -> V_134 ( V_39 , 0 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 , L_26 ) ;
V_24 = F_37 ( V_39 , 0 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 , L_27 ) ;
return V_24 ;
}
static int F_42 ( struct V_38 * V_39 , int V_137 )
{
int V_24 ;
if ( V_137 == 0 )
return F_41 ( V_39 ) ;
else {
V_24 = F_40 ( V_39 ) ;
if ( ! V_24 )
return F_36 ( V_39 ) ;
}
return V_24 ;
}
static int F_43 ( struct V_51 * V_52 , T_4 V_138 , T_4 V_139 )
{
unsigned int V_140 = ( V_52 -> V_141 << 13 ) / V_138 ;
unsigned int V_142 ;
int V_143 ;
if ( V_139 == 0 )
return - 1 ;
V_142 = ( V_52 -> V_144 << 13 ) / V_139 ;
if ( V_142 == 0 )
return - 1 ;
V_143 = abs ( ( ( V_140 << 13 ) / V_142 ) - ( ( int ) 8192 ) ) ;
if ( ( V_140 < ( int ) 8192 ) || ( V_142 < ( int ) 8192 ) ||
( V_143 > V_145 ) )
return - 1 ;
return V_140 + V_142 ;
}
static int F_44 ( int V_138 , int V_139 )
{
int V_146 ;
int V_147 = - 1 ;
int V_148 ;
int V_149 = V_150 ;
struct V_51 * V_151 = NULL ;
for ( V_146 = 0 ; V_146 < V_125 ; V_146 ++ ) {
V_151 = & V_45 [ V_146 ] ;
V_148 = F_43 ( V_151 , V_138 , V_139 ) ;
if ( V_148 == - 1 )
continue;
if ( V_148 < V_149 ) {
V_149 = V_148 ;
V_147 = V_146 ;
}
}
return V_147 ;
}
static int F_45 ( int V_138 , int V_139 )
{
int V_146 ;
for ( V_146 = 0 ; V_146 < V_125 ; V_146 ++ ) {
if ( V_138 != V_45 [ V_146 ] . V_141 )
continue;
if ( V_139 != V_45 [ V_146 ] . V_144 )
continue;
return V_146 ;
}
return - 1 ;
}
static int F_46 ( struct V_38 * V_39 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_24 = 0 ;
F_19 ( L_21 , V_12 ) ;
V_24 = F_9 ( V_2 , V_45 [ V_11 -> V_46 ] . V_152 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_28 ) ;
return V_24 ;
}
F_19 ( L_22 , V_12 ) ;
return V_24 ;
}
static int F_47 ( struct V_38 * V_39 ,
struct V_153 * V_154 ,
struct V_155 * V_156 )
{
struct V_157 * V_158 = & V_156 -> V_156 ;
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
struct V_49 * V_159 = NULL ;
int V_24 = 0 ;
int V_147 = 0 ;
F_19 ( L_21 , V_12 ) ;
if ( V_156 -> V_160 )
return - V_15 ;
if ( ! V_158 )
return - V_15 ;
V_159 = F_48 ( V_39 ) ;
if ( ! V_159 )
return - V_15 ;
F_24 ( & V_11 -> V_103 ) ;
V_147 = F_44 ( V_158 -> V_141 , V_158 -> V_144 ) ;
if ( V_147 == - 1 ) {
V_158 -> V_141 = V_45 [ V_125 - 1 ] . V_141 ;
V_158 -> V_144 = V_45 [ V_125 - 1 ] . V_144 ;
} else {
V_158 -> V_141 = V_45 [ V_147 ] . V_141 ;
V_158 -> V_144 = V_45 [ V_147 ] . V_144 ;
}
V_158 -> V_161 = V_162 ;
if ( V_156 -> V_163 == V_164 ) {
V_154 -> V_165 = * V_158 ;
F_25 ( & V_11 -> V_103 ) ;
return 0 ;
}
V_11 -> V_46 = F_45 ( V_158 -> V_141 , V_158 -> V_144 ) ;
if ( V_11 -> V_46 == - 1 ) {
F_2 ( & V_2 -> V_11 , L_29 ) ;
F_25 ( & V_11 -> V_103 ) ;
return - V_15 ;
}
F_49 ( L_30 , V_166 ,
V_45 [ V_11 -> V_46 ] . V_167 ) ;
V_24 = F_46 ( V_39 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_31 ) ;
goto V_6;
}
V_24 = F_17 ( V_2 , V_159 ,
& V_45 [ V_11 -> V_46 ] ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_32 ) ;
goto V_6;
}
F_19 ( L_22 , V_12 ) ;
V_6:
F_25 ( & V_11 -> V_103 ) ;
return V_24 ;
}
static int F_50 ( struct V_38 * V_39 ,
struct V_153 * V_154 ,
struct V_155 * V_156 )
{
struct V_157 * V_158 = & V_156 -> V_156 ;
struct V_44 * V_11 = F_15 ( V_39 ) ;
if ( V_156 -> V_160 )
return - V_15 ;
if ( ! V_158 )
return - V_15 ;
V_158 -> V_141 = V_45 [ V_11 -> V_46 ] . V_141 ;
V_158 -> V_144 = V_45 [ V_11 -> V_46 ] . V_144 ;
V_158 -> V_161 = V_162 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_168 * V_10 = V_2 -> V_10 ;
T_2 V_169 , V_170 ;
int V_24 ;
T_1 V_114 ;
F_19 ( L_21 , V_12 ) ;
if ( ! F_52 ( V_10 , V_171 ) )
return - V_13 ;
V_24 = F_1 ( V_2 , V_14 ,
V_172 , & V_169 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_33 ) ;
return - V_13 ;
}
V_24 = F_1 ( V_2 , V_14 ,
V_173 , & V_170 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_34 ) ;
return - V_13 ;
}
V_114 = ( ( ( ( T_1 ) V_169 ) << 8 ) | ( T_1 ) V_170 ) ;
F_19 ( L_35 , V_114 ) ;
if ( V_114 != V_174 ) {
F_2 ( & V_2 -> V_11 , L_36 , V_114 , V_174 ) ;
return - V_13 ;
}
F_34 ( & V_2 -> V_11 , L_37 ) ;
F_19 ( L_22 , V_12 ) ;
return 0 ;
}
static int F_53 ( struct V_38 * V_39 , int V_175 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_24 ;
F_19 ( L_38 , V_12 , V_175 ) ;
F_24 ( & V_11 -> V_103 ) ;
if ( V_175 ) {
V_24 = F_5 ( V_2 , V_14 ,
0xFE , 0x30 ) ;
if ( V_24 ) {
F_25 ( & V_11 -> V_103 ) ;
return V_24 ;
}
}
V_24 = F_5 ( V_2 , V_14 ,
V_176 , V_177 ) ;
if ( V_24 ) {
F_25 ( & V_11 -> V_103 ) ;
return V_24 ;
}
V_24 = F_5 ( V_2 , V_14 , V_178 ,
V_175 ? V_179 :
V_180 ) ;
if ( V_24 ) {
F_25 ( & V_11 -> V_103 ) ;
return V_24 ;
}
V_24 = F_5 ( V_2 , V_14 ,
V_176 , V_181 ) ;
if ( V_24 ) {
F_25 ( & V_11 -> V_103 ) ;
return V_24 ;
}
F_25 ( & V_11 -> V_103 ) ;
F_19 ( L_22 , V_12 ) ;
return V_24 ;
}
static int F_54 ( struct V_38 * V_39 ,
int V_182 , void * V_128 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_24 = 0 ;
F_19 ( L_21 , V_12 ) ;
if ( ! V_128 )
return - V_13 ;
V_11 -> V_128 =
(struct V_183 * ) V_128 ;
F_24 ( & V_11 -> V_103 ) ;
if ( V_11 -> V_128 -> V_184 ) {
V_24 = V_11 -> V_128 -> V_184 ( V_2 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_39 ) ;
goto V_185;
}
}
V_24 = F_41 ( V_39 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_40 ) ;
goto V_186;
}
V_24 = F_40 ( V_39 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_41 ) ;
goto V_187;
}
V_24 = V_11 -> V_128 -> V_188 ( V_39 , 1 ) ;
if ( V_24 )
goto V_189;
V_24 = F_51 ( V_2 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_42 ) ;
goto V_189;
}
V_24 = F_41 ( V_39 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_40 ) ;
goto V_189;
}
F_25 ( & V_11 -> V_103 ) ;
F_19 ( L_22 , V_12 ) ;
return 0 ;
V_189:
V_11 -> V_128 -> V_188 ( V_39 , 0 ) ;
V_187:
F_41 ( V_39 ) ;
F_2 ( & V_2 -> V_11 , L_43 ) ;
V_186:
if ( V_11 -> V_128 -> V_190 )
V_11 -> V_128 -> V_190 () ;
V_185:
F_25 ( & V_11 -> V_103 ) ;
return V_24 ;
}
static int F_55 ( struct V_38 * V_39 ,
struct V_191 * V_192 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
struct V_1 * V_2 = F_21 ( V_39 ) ;
if ( ! V_192 )
return - V_15 ;
if ( V_192 -> type != V_193 ) {
F_2 ( & V_2 -> V_11 , L_44 ) ;
return - V_15 ;
}
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> type = V_193 ;
if ( V_11 -> V_46 >= 0 && V_11 -> V_46 < V_125 ) {
V_192 -> V_194 . V_195 . V_196 = V_197 ;
V_192 -> V_194 . V_195 . V_198 . V_199 = 1 ;
V_192 -> V_194 . V_195 . V_200 = V_11 -> V_201 ;
V_192 -> V_194 . V_195 . V_198 . V_202 =
V_45 [ V_11 -> V_46 ] . V_203 ;
}
return 0 ;
}
static int F_56 ( struct V_38 * V_39 ,
struct V_191 * V_192 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
V_11 -> V_201 = V_192 -> V_194 . V_195 . V_200 ;
F_24 ( & V_11 -> V_103 ) ;
switch ( V_11 -> V_201 ) {
case V_204 :
V_45 = V_205 ;
V_125 = V_206 ;
break;
case V_207 :
V_45 = V_208 ;
V_125 = V_209 ;
break;
default:
V_45 = V_124 ;
V_125 = V_126 ;
}
F_25 ( & V_11 -> V_103 ) ;
return 0 ;
}
static int F_57 ( struct V_38 * V_39 ,
struct V_210 * V_211 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
V_211 -> V_211 . V_199 = 1 ;
V_211 -> V_211 . V_202 = V_45 [ V_11 -> V_46 ] . V_203 ;
return 0 ;
}
static int F_58 ( struct V_38 * V_39 ,
struct V_153 * V_154 ,
struct V_212 * V_161 )
{
if ( V_161 -> V_29 >= V_213 )
return - V_15 ;
V_161 -> V_161 = V_162 ;
return 0 ;
}
static int F_59 ( struct V_38 * V_39 ,
struct V_153 * V_154 ,
struct V_214 * V_215 )
{
int V_29 = V_215 -> V_29 ;
if ( V_29 >= V_125 )
return - V_15 ;
V_215 -> V_216 = V_45 [ V_29 ] . V_141 ;
V_215 -> V_217 = V_45 [ V_29 ] . V_144 ;
V_215 -> V_218 = V_45 [ V_29 ] . V_141 ;
V_215 -> V_219 = V_45 [ V_29 ] . V_144 ;
return 0 ;
}
static int F_60 ( struct V_38 * V_39 , T_4 * V_220 )
{
struct V_44 * V_11 = F_15 ( V_39 ) ;
F_24 ( & V_11 -> V_103 ) ;
* V_220 = V_45 [ V_11 -> V_46 ] . V_221 ;
F_25 ( & V_11 -> V_103 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_18 ( V_2 ) ;
struct V_44 * V_11 = F_15 ( V_39 ) ;
F_34 ( & V_2 -> V_11 , L_45 ) ;
if ( V_11 -> V_128 -> V_190 )
V_11 -> V_128 -> V_190 () ;
V_11 -> V_128 -> V_188 ( V_39 , 0 ) ;
F_62 ( V_39 ) ;
F_63 ( & V_11 -> V_39 . V_222 ) ;
F_64 ( & V_11 -> V_113 ) ;
F_65 ( V_11 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_223 * V_114 )
{
struct V_44 * V_11 ;
int V_24 ;
void * V_224 ;
unsigned int V_146 ;
F_19 ( L_21 , V_12 ) ;
V_11 = F_67 ( sizeof( * V_11 ) , V_225 ) ;
if ( ! V_11 ) {
F_2 ( & V_2 -> V_11 , L_46 ) ;
return - V_226 ;
}
F_68 ( & V_11 -> V_103 ) ;
V_11 -> V_46 = 0 ;
F_69 ( & ( V_11 -> V_39 ) , V_2 , & V_227 ) ;
if ( F_70 ( & V_2 -> V_11 ) )
V_224 = F_71 ( & V_11 -> V_39 ,
V_228 ,
V_229 ) ;
else
V_224 = V_2 -> V_11 . V_128 ;
if ( ! V_224 ) {
V_24 = - V_15 ;
goto V_230;
}
V_24 = F_54 ( & V_11 -> V_39 , V_2 -> V_182 , V_224 ) ;
if ( V_24 )
goto V_230;
V_24 = F_72 ( & V_11 -> V_39 , V_224 , V_231 ) ;
if ( V_24 )
goto V_230;
V_11 -> V_39 . V_17 |= V_232 ;
V_11 -> V_160 . V_17 = V_233 ;
V_11 -> V_156 . V_161 = V_162 ;
V_11 -> V_39 . V_222 . V_234 = V_235 ;
V_24 =
F_73 ( & V_11 -> V_113 ,
F_74 ( V_236 ) ) ;
if ( V_24 ) {
F_61 ( V_2 ) ;
return V_24 ;
}
for ( V_146 = 0 ; V_146 < F_74 ( V_236 ) ; V_146 ++ )
F_75 ( & V_11 -> V_113 , & V_236 [ V_146 ] ,
NULL ) ;
if ( V_11 -> V_113 . error ) {
F_61 ( V_2 ) ;
return V_11 -> V_113 . error ;
}
V_11 -> V_113 . V_237 = & V_11 -> V_103 ;
V_11 -> V_39 . V_113 = & V_11 -> V_113 ;
V_24 = F_76 ( & V_11 -> V_39 . V_222 , 1 , & V_11 -> V_160 ) ;
if ( V_24 )
F_61 ( V_2 ) ;
F_19 ( L_22 , V_12 ) ;
return V_24 ;
V_230:
F_62 ( & V_11 -> V_39 ) ;
F_65 ( V_11 ) ;
return V_24 ;
}
static int F_77 ( void )
{
return F_78 ( & V_238 ) ;
}
static void F_79 ( void )
{
F_80 ( & V_238 ) ;
}
