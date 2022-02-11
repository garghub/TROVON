static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
int V_6 ;
struct V_7 V_8 [ 2 ] ;
unsigned char V_9 [ 6 ] ;
if ( ! V_2 -> V_10 ) {
F_2 ( & V_2 -> V_11 , L_1 ,
V_12 ) ;
return - V_13 ;
}
if ( V_3 != V_14 && V_3 != V_15
&& V_3 != V_16 ) {
F_2 ( & V_2 -> V_11 , L_2 ,
V_12 ) ;
return - V_17 ;
}
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ 0 ] . V_18 = V_2 -> V_18 ;
V_8 [ 0 ] . V_19 = 0 ;
V_8 [ 0 ] . V_20 = V_21 ;
V_8 [ 0 ] . V_22 = V_9 ;
V_9 [ 0 ] = ( V_23 ) ( V_4 >> 8 ) ;
V_9 [ 1 ] = ( V_23 ) ( V_4 & 0xff ) ;
V_8 [ 1 ] . V_18 = V_2 -> V_18 ;
V_8 [ 1 ] . V_20 = V_3 ;
V_8 [ 1 ] . V_19 = V_24 ;
V_8 [ 1 ] . V_22 = V_9 ;
V_6 = F_3 ( V_2 -> V_10 , V_8 , 2 ) ;
if ( V_6 != 2 ) {
if ( V_6 >= 0 )
V_6 = - V_25 ;
F_2 ( & V_2 -> V_11 ,
L_3 , V_4 , V_6 ) ;
return V_6 ;
}
* V_5 = 0 ;
if ( V_3 == V_14 )
* V_5 = ( V_23 ) V_9 [ 0 ] ;
else if ( V_3 == V_15 )
* V_5 = F_4 ( * ( T_1 * ) & V_9 [ 0 ] ) ;
else
* V_5 = F_5 ( * ( V_26 * ) & V_9 [ 0 ] ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_20 , V_23 * V_9 )
{
struct V_7 V_8 ;
const int V_27 = 1 ;
int V_28 ;
V_8 . V_18 = V_2 -> V_18 ;
V_8 . V_19 = 0 ;
V_8 . V_20 = V_20 ;
V_8 . V_22 = V_9 ;
V_28 = F_3 ( V_2 -> V_10 , & V_8 , 1 ) ;
return V_28 == V_27 ? 0 : - V_25 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
int V_28 ;
unsigned char V_9 [ 4 ] = { 0 } ;
T_1 * V_29 = ( T_1 * ) V_9 ;
const T_1 V_20 = V_3 + sizeof( T_1 ) ;
if ( V_3 != V_14 && V_3 != V_15 ) {
F_2 ( & V_2 -> V_11 ,
L_4 , V_12 ) ;
return - V_17 ;
}
* V_29 = F_8 ( V_4 ) ;
if ( V_3 == V_14 ) {
V_9 [ 2 ] = ( V_23 ) ( V_5 ) ;
} else {
T_1 * V_30 = ( T_1 * ) & V_9 [ 2 ] ;
* V_30 = F_8 ( V_5 ) ;
}
V_28 = F_6 ( V_2 , V_20 , V_9 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 ,
L_5 ,
V_5 , V_4 , V_28 ) ;
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
T_1 V_33 ;
if ( V_32 -> V_34 == 0 )
return 0 ;
V_33 = sizeof( T_1 ) + V_32 -> V_34 ;
V_32 -> V_35 . V_18 = F_8 ( V_32 -> V_35 . V_18 ) ;
V_32 -> V_34 = 0 ;
return F_6 ( V_2 , V_33 , ( V_23 * ) & V_32 -> V_35 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
const struct V_36 * V_37 )
{
int V_33 ;
T_1 * V_38 ;
switch ( V_37 -> type ) {
case V_14 :
V_33 = 1 ;
V_32 -> V_35 . V_9 [ V_32 -> V_34 ] = ( V_23 ) V_37 -> V_5 ;
break;
case V_15 :
V_33 = 2 ;
V_38 = ( T_1 * ) & V_32 -> V_35 . V_9 [ V_32 -> V_34 ] ;
* V_38 = F_8 ( ( T_1 ) V_37 -> V_5 ) ;
break;
default:
return - V_17 ;
}
if ( V_32 -> V_34 == 0 )
V_32 -> V_35 . V_18 = V_37 -> V_4 ;
V_32 -> V_34 += V_33 ;
if ( V_32 -> V_34 + sizeof( T_1 ) >= V_39 )
return F_9 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
const struct V_36 * V_37 )
{
if ( V_32 -> V_34 == 0 )
return 1 ;
return V_32 -> V_35 . V_18 + V_32 -> V_34 == V_37 -> V_4 ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_36 * V_40 )
{
const struct V_36 * V_37 = V_40 ;
struct V_31 V_32 ;
int V_6 ;
F_13 ( & V_2 -> V_11 , L_6 ) ;
V_32 . V_34 = 0 ;
for (; V_37 -> type != V_41 ; V_37 ++ ) {
switch ( V_37 -> type & V_42 ) {
case V_43 :
V_6 = F_9 ( V_2 , & V_32 ) ;
if ( V_6 )
return V_6 ;
F_14 ( V_37 -> V_5 ) ;
break;
default:
F_13 ( & V_2 -> V_11 , L_7 , V_37 -> V_4 , V_37 -> V_5 ) ;
if ( ! F_11 ( V_2 , & V_32 ,
V_37 ) ) {
V_6 = F_9 ( V_2 , & V_32 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_10 ( V_2 , & V_32 , V_37 ) ;
if ( V_6 ) {
F_2 ( & V_2 -> V_11 , L_8 ,
V_12 ) ;
return V_6 ;
}
break;
}
}
return F_9 ( V_2 , & V_32 ) ;
}
static int F_15 ( struct V_44 * V_45 , T_2 * V_5 )
{
* V_5 = ( V_46 << 16 ) | V_47 ;
return 0 ;
}
static int F_16 ( struct V_44 * V_45 , T_2 * V_5 )
{
* V_5 = ( V_48 << 16 ) | V_49 ;
return 0 ;
}
static int F_17 ( struct V_44 * V_45 , T_2 * V_5 )
{
* V_5 = ( V_48 << 24 ) |
( V_49 << 16 ) |
( V_48 << 8 ) | V_49 ;
return 0 ;
}
static int F_18 ( struct V_44 * V_45 , T_2 * V_5 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
F_13 ( & V_2 -> V_11 , L_9 ) ;
* V_5 = V_51 [ V_11 -> V_52 ] . V_53 ;
return 0 ;
}
static int F_21 ( struct V_44 * V_45 , T_2 * V_5 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
* V_5 = V_51 [ V_11 -> V_52 ] . V_54 ;
F_13 ( & V_2 -> V_11 , L_10 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_44 * V_45 = F_23 ( V_2 ) ;
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_59 * V_22 = & V_56 -> V_9 ;
unsigned int V_60 ;
T_1 V_61 ;
int V_28 ;
F_13 ( & V_2 -> V_11 , L_11 ) ;
if ( ! V_56 )
return - V_17 ;
V_60 = V_58 -> V_62 * 1000000 ;
V_11 -> V_63 = V_60 ;
V_22 -> V_63 = V_60 ;
V_22 -> V_64 = V_65 ;
V_22 -> V_66 =
V_67 ;
V_22 -> V_68 = V_69 ;
V_22 -> V_70 =
V_71 ;
V_22 -> V_72 = V_69 ;
V_22 -> V_73 = V_58 -> V_74 ;
V_22 -> V_75 = V_58 -> V_76 ;
V_22 -> V_77 = V_58 -> V_78 ;
V_28 = F_1 ( V_2 , V_15 ,
V_79 , & V_61 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_80 = V_61 ;
V_28 = F_1 ( V_2 , V_15 ,
V_81 , & V_61 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_82 = V_61 ;
V_28 = F_1 ( V_2 , V_15 ,
V_83 , & V_61 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_84 = V_61 ;
V_28 = F_1 ( V_2 , V_15 ,
V_85 , & V_61 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_86 = V_61 ;
V_28 = F_1 ( V_2 , V_15 ,
V_87 , & V_61 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_88 = V_61 ;
V_28 = F_1 ( V_2 , V_15 ,
V_89 , & V_61 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_90 = V_61 ;
V_22 -> V_91 = V_58 -> V_53 ?
( V_58 -> V_53 * 2 ) : 1 ;
V_22 -> V_92 = V_58 -> V_54 ?
( V_58 -> V_54 * 2 ) : 1 ;
return 0 ;
}
static long F_24 ( struct V_44 * V_45 , int V_93 ,
int V_94 , int V_95 )
{
struct V_1 * V_2 = F_20 ( V_45 ) ;
struct V_50 * V_11 = F_19 ( V_45 ) ;
T_1 V_96 , V_97 ;
int V_28 , V_98 ;
F_13 ( & V_2 -> V_11 , L_12 , V_93 , V_94 , V_95 ) ;
V_97 = V_51 [ V_11 -> V_52 ] . V_76 ;
V_96 = V_51 [ V_11 -> V_52 ] . V_74 ;
V_28 = F_7 ( V_2 , V_14 ,
V_99 , 0x00 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_99 ) ;
return V_28 ;
}
if ( V_93 > V_96 - V_100 )
V_96 = ( T_1 ) V_93 + V_100 ;
V_28 = F_7 ( V_2 , V_15 , V_101 , V_96 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_101 ) ;
return V_28 ;
}
V_98 = V_93 << 4 ;
V_28 = F_7 ( V_2 , V_14 ,
V_102 , V_98 & 0xFF ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_102 ) ;
return V_28 ;
}
V_28 = F_7 ( V_2 , V_14 ,
V_103 , ( V_98 >> 8 ) & 0xFF ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_103 ) ;
return V_28 ;
}
V_28 = F_7 ( V_2 , V_14 ,
V_104 , ( V_98 >> 16 ) & 0x0F ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_104 ) ;
return V_28 ;
}
V_28 = F_7 ( V_2 , V_15 , V_105 , V_94 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_105 ) ;
return V_28 ;
}
if ( V_95 ) {
V_28 = F_7 ( V_2 , V_15 ,
V_106 , V_95 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_106 ) ;
return V_28 ;
}
V_28 = F_7 ( V_2 , V_15 ,
V_107 , V_95 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_106 ) ;
return V_28 ;
}
V_28 = F_7 ( V_2 , V_15 ,
V_108 , V_95 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_13 ,
V_12 , V_106 ) ;
return V_28 ;
}
}
V_28 = F_7 ( V_2 , V_14 ,
V_99 , 0x10 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_14 ,
V_99 , 0xa0 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static int F_25 ( struct V_44 * V_45 , int V_109 ,
int V_94 , int V_95 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
int V_28 ;
F_26 ( & V_11 -> V_110 ) ;
V_28 = F_24 ( V_45 , V_109 , V_94 , V_95 ) ;
F_27 ( & V_11 -> V_110 ) ;
return V_28 ;
}
static long F_28 ( struct V_44 * V_45 ,
struct V_111 * V_109 )
{
T_1 V_93 = V_109 -> V_112 [ 0 ] ;
T_1 V_113 = V_109 -> V_94 [ 0 ] ;
T_1 V_114 = V_109 -> V_94 [ 1 ] ;
if ( V_113 == 0 ) {
struct V_1 * V_2 = F_20 ( V_45 ) ;
F_29 ( V_2 , L_14 , V_12 ) ;
return - V_17 ;
}
return F_25 ( V_45 , V_93 , V_113 , V_114 ) ;
}
static long F_30 ( struct V_44 * V_45 , unsigned int V_115 , void * V_116 )
{
switch ( V_115 ) {
case V_117 :
return F_28 ( V_45 , V_116 ) ;
default:
return - V_17 ;
}
return 0 ;
}
static int F_31 ( struct V_44 * V_45 , T_2 * V_118 )
{
struct V_1 * V_2 = F_20 ( V_45 ) ;
T_1 V_119 , V_120 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_14 ,
V_102 ,
& V_119 ) ;
if ( V_28 )
goto V_6;
V_28 = F_1 ( V_2 , V_14 ,
V_103 ,
& V_120 ) ;
if ( V_28 )
goto V_6;
V_119 += V_120 << 8 ;
V_28 = F_1 ( V_2 , V_14 ,
V_104 ,
& V_120 ) ;
if ( V_28 )
goto V_6;
* V_118 = V_119 + ( ( ( V_26 ) V_120 << 16 ) ) ;
V_6:
return V_28 ;
}
static V_26 F_32 ( enum V_121 V_122 )
{
switch ( V_122 ) {
case V_123 :
return V_124 ;
case V_125 :
return V_126 ;
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
}
return 0 ;
}
static int F_33 ( struct V_44 * V_45 , T_2 V_118 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_55 * V_131 = NULL ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
int V_28 ;
T_1 V_5 ;
V_23 V_34 ;
F_13 ( & V_2 -> V_11 , L_15 , V_12 , V_118 ) ;
V_28 = F_1 ( V_2 , V_14 , V_132 , & V_5 ) ;
if ( V_28 )
return V_28 ;
if ( V_118 ) {
V_5 |= V_133 ;
} else {
V_5 &= ~ V_133 ;
}
V_28 = F_7 ( V_2 , V_14 ,
V_132 , V_5 ) ;
if ( V_28 )
return V_28 ;
V_34 = ( V_134 > 0 ? V_135 : 0 ) | ( V_136 > 0 ? V_137 : 0 ) ;
V_131 = F_34 ( V_45 ) ;
if ( V_131 ) {
V_131 -> V_138 = V_139 [ V_34 ] ;
V_11 -> V_140 . V_122 = F_32 (
V_131 -> V_138 ) ;
}
return V_28 ;
}
static int F_35 ( struct V_44 * V_45 , T_2 V_118 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_55 * V_131 = NULL ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
int V_28 ;
T_1 V_5 ;
V_23 V_34 ;
F_13 ( & V_2 -> V_11 , L_15 , V_12 , V_118 ) ;
V_28 = F_1 ( V_2 , V_14 , V_141 , & V_5 ) ;
if ( V_28 )
return V_28 ;
if ( V_118 ) {
V_5 |= V_133 ;
} else {
V_5 &= ~ V_133 ;
}
V_28 = F_7 ( V_2 , V_14 ,
V_141 , V_5 ) ;
if ( V_28 )
return V_28 ;
V_34 = ( V_134 > 0 ? V_135 : 0 ) | ( V_136 > 0 ? V_137 : 0 ) ;
V_131 = F_34 ( V_45 ) ;
if ( V_131 ) {
V_131 -> V_138 = V_139 [ V_34 ] ;
V_11 -> V_140 . V_122 = F_32 (
V_131 -> V_138 ) ;
}
return V_28 ;
}
static int F_36 ( struct V_142 * V_32 )
{
struct V_50 * V_11 =
F_37 ( V_32 -> V_143 , struct V_50 , V_144 ) ;
struct V_1 * V_2 = F_20 ( & V_11 -> V_45 ) ;
int V_28 = 0 ;
switch ( V_32 -> V_145 ) {
case V_146 :
F_13 ( & V_2 -> V_11 , L_16 ,
V_12 , V_32 -> V_5 ) ;
V_28 = F_33 ( & V_11 -> V_45 , V_32 -> V_5 ) ;
break;
case V_147 :
F_13 ( & V_2 -> V_11 , L_17 ,
V_12 , V_32 -> V_5 ) ;
V_28 = F_35 ( & V_11 -> V_45 , V_32 -> V_5 ) ;
break;
default:
V_28 = - V_17 ;
}
return V_28 ;
}
static int F_38 ( struct V_142 * V_32 )
{
struct V_50 * V_11 =
F_37 ( V_32 -> V_143 , struct V_50 , V_144 ) ;
int V_28 = 0 ;
switch ( V_32 -> V_145 ) {
case V_148 :
V_28 = F_31 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_149 :
V_28 = F_15 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_150 :
V_28 = F_16 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_151 :
V_28 = F_17 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_152 :
V_28 = F_18 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_153 :
V_28 = F_21 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
default:
V_28 = - V_17 ;
}
return V_28 ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_20 ( V_45 ) ;
int V_28 ;
V_28 = F_7 ( V_2 , V_14 , V_154 , 0x01 ) ;
V_28 |= F_12 ( V_2 , V_155 ) ;
return V_28 ;
}
static int F_40 ( struct V_44 * V_45 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
int V_28 ;
F_26 ( & V_11 -> V_110 ) ;
V_51 = V_156 ;
V_157 = V_158 ;
V_28 = F_39 ( V_45 ) ;
F_27 ( & V_11 -> V_110 ) ;
return V_28 ;
}
static int F_41 ( struct V_44 * V_45 , bool V_159 )
{
int V_28 = 0 ;
struct V_50 * V_11 = F_19 ( V_45 ) ;
if ( ! V_11 || ! V_11 -> V_160 )
return - V_13 ;
if ( V_11 -> V_160 -> F_41 )
return V_11 -> V_160 -> F_41 ( V_45 , V_159 ) ;
if ( V_159 ) {
V_28 |= V_11 -> V_160 -> V_161 ( V_45 , 1 ) ;
V_28 |= V_11 -> V_160 -> V_162 ( V_45 , 1 ) ;
F_42 ( 10000 , 15000 ) ;
}
if ( ! V_159 || V_28 ) {
V_28 |= V_11 -> V_160 -> V_161 ( V_45 , 0 ) ;
V_28 |= V_11 -> V_160 -> V_162 ( V_45 , 0 ) ;
}
return V_28 ;
}
static int F_43 ( struct V_44 * V_45 , bool V_159 )
{
int V_28 ;
struct V_50 * V_11 = F_19 ( V_45 ) ;
if ( ! V_11 || ! V_11 -> V_160 )
return - V_13 ;
if ( V_11 -> V_160 -> F_43 )
return V_11 -> V_160 -> F_43 ( V_45 , V_159 ) ;
if ( V_159 ) {
V_28 = V_11 -> V_160 -> V_163 ( V_45 , 1 ) ;
F_42 ( 10000 , 15000 ) ;
V_11 -> V_160 -> V_164 ( V_45 , 1 ) ;
F_42 ( 10000 , 15000 ) ;
} else {
V_11 -> V_160 -> V_164 ( V_45 , 0 ) ;
V_28 = V_11 -> V_160 -> V_163 ( V_45 , 0 ) ;
}
return V_28 ;
}
static int F_44 ( struct V_44 * V_45 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
int V_28 ;
if ( ! V_11 -> V_160 ) {
F_2 ( & V_2 -> V_11 ,
L_18 ) ;
return - V_13 ;
}
V_28 = F_41 ( V_45 , 1 ) ;
if ( V_28 )
goto V_165;
F_42 ( 5000 , 6000 ) ;
V_28 = F_43 ( V_45 , 1 ) ;
if ( V_28 ) {
V_28 = F_43 ( V_45 , 1 ) ;
if ( V_28 )
goto V_165;
}
V_28 = V_11 -> V_160 -> V_166 ( V_45 , 1 ) ;
if ( V_28 )
goto V_167;
F_14 ( 20 ) ;
return 0 ;
V_167:
F_43 ( V_45 , 0 ) ;
V_165:
F_41 ( V_45 , 0 ) ;
F_2 ( & V_2 -> V_11 , L_19 ) ;
return V_28 ;
}
static int F_45 ( struct V_44 * V_45 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
int V_28 = 0 ;
V_136 = 0 ;
V_134 = 0 ;
if ( ! V_11 -> V_160 ) {
F_2 ( & V_2 -> V_11 ,
L_18 ) ;
return - V_13 ;
}
V_28 = V_11 -> V_160 -> V_166 ( V_45 , 0 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_20 ) ;
V_28 = F_43 ( V_45 , 0 ) ;
if ( V_28 ) {
V_28 = F_43 ( V_45 , 0 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_21 ) ;
}
V_28 = F_41 ( V_45 , 0 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_22 ) ;
return V_28 ;
}
static int F_46 ( struct V_44 * V_45 , int V_168 )
{
int V_28 ;
if ( V_168 == 0 ) {
V_28 = F_45 ( V_45 ) ;
} else {
V_28 = F_44 ( V_45 ) ;
if ( ! V_28 )
return F_40 ( V_45 ) ;
}
return V_28 ;
}
static int F_47 ( struct V_57 * V_58 , V_26 V_169 , V_26 V_170 )
{
unsigned int V_171 = ( V_58 -> V_172 << 13 ) / V_169 ;
unsigned int V_173 ;
int V_174 ;
if ( V_170 == 0 )
return - 1 ;
V_173 = ( V_58 -> V_175 << 13 ) / V_170 ;
if ( V_173 == 0 )
return - 1 ;
V_174 = abs ( ( ( V_171 << 13 ) / V_173 ) - ( ( int ) 8192 ) ) ;
if ( ( V_171 < ( int ) 8192 ) || ( V_173 < ( int ) 8192 ) ||
( V_174 > V_176 ) )
return - 1 ;
return V_171 + V_173 ;
}
static int F_48 ( int V_169 , int V_170 )
{
int V_177 ;
int V_178 = - 1 ;
int V_179 ;
int V_180 = V_181 ;
struct V_57 * V_182 = NULL ;
for ( V_177 = 0 ; V_177 < V_157 ; V_177 ++ ) {
V_182 = & V_51 [ V_177 ] ;
V_179 = F_47 ( V_182 , V_169 , V_170 ) ;
if ( V_179 == - 1 )
continue;
if ( V_179 < V_180 ) {
V_180 = V_179 ;
V_178 = V_177 ;
}
}
return V_178 ;
}
static int F_49 ( int V_169 , int V_170 )
{
int V_177 ;
for ( V_177 = 0 ; V_177 < V_157 ; V_177 ++ ) {
if ( V_169 != V_51 [ V_177 ] . V_172 )
continue;
if ( V_170 != V_51 [ V_177 ] . V_175 )
continue;
return V_177 ;
}
return - 1 ;
}
static int F_50 ( struct V_44 * V_45 ,
struct V_183 * V_184 ,
struct V_185 * V_140 )
{
struct V_186 * V_187 = & V_140 -> V_140 ;
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
struct V_55 * V_131 = NULL ;
int V_28 = 0 ;
int V_178 = 0 ;
F_13 ( & V_2 -> V_11 , L_23 ) ;
if ( V_140 -> V_188 )
return - V_17 ;
if ( ! V_187 )
return - V_17 ;
V_131 = F_34 ( V_45 ) ;
if ( ! V_131 )
return - V_17 ;
F_26 ( & V_11 -> V_110 ) ;
V_178 = F_48 ( V_187 -> V_172 , V_187 -> V_175 ) ;
if ( V_178 == - 1 ) {
V_187 -> V_172 = V_51 [ V_157 - 1 ] . V_172 ;
V_187 -> V_175 = V_51 [ V_157 - 1 ] . V_175 ;
} else {
V_187 -> V_172 = V_51 [ V_178 ] . V_172 ;
V_187 -> V_175 = V_51 [ V_178 ] . V_175 ;
}
V_187 -> V_122 = V_128 ;
if ( V_140 -> V_189 == V_190 ) {
V_184 -> V_191 = * V_187 ;
F_27 ( & V_11 -> V_110 ) ;
return 0 ;
}
V_11 -> V_52 = F_49 ( V_187 -> V_172 , V_187 -> V_175 ) ;
F_13 ( & V_2 -> V_11 , L_24 ,
V_11 -> V_52 ) ;
if ( V_11 -> V_52 == - 1 ) {
F_2 ( & V_2 -> V_11 , L_25 ) ;
F_27 ( & V_11 -> V_110 ) ;
return - V_17 ;
}
F_51 ( V_2 , L_26 , V_11 -> V_52 ,
V_187 -> V_172 , V_187 -> V_175 ) ;
F_13 ( & V_2 -> V_11 , L_26 ,
V_11 -> V_52 , V_187 -> V_172 , V_187 -> V_175 ) ;
V_28 = F_12 ( V_2 , V_51 [ V_11 -> V_52 ] . V_192 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_27 ) ;
V_28 = F_22 ( V_2 , V_131 ,
& V_51 [ V_11 -> V_52 ] ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_28 ) ;
goto V_6;
}
if ( V_136 )
F_35 ( V_45 , V_136 ) ;
if ( V_134 )
F_33 ( V_45 , V_134 ) ;
F_51 ( V_2 , L_29 , V_12 , V_11 -> V_52 ) ;
V_6:
F_27 ( & V_11 -> V_110 ) ;
return V_28 ;
}
static int F_52 ( struct V_44 * V_45 ,
struct V_183 * V_184 ,
struct V_185 * V_140 )
{
struct V_186 * V_187 = & V_140 -> V_140 ;
struct V_50 * V_11 = F_19 ( V_45 ) ;
if ( V_140 -> V_188 )
return - V_17 ;
if ( ! V_187 )
return - V_17 ;
V_187 -> V_172 = V_51 [ V_11 -> V_52 ] . V_172 ;
V_187 -> V_175 = V_51 [ V_11 -> V_52 ] . V_175 ;
V_187 -> V_122 = V_128 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_193 * V_10 = V_2 -> V_10 ;
T_1 V_194 , V_195 ;
int V_28 ;
T_1 V_145 ;
V_23 V_196 ;
if ( ! F_54 ( V_10 , V_197 ) )
return - V_13 ;
V_28 = F_1 ( V_2 , V_14 ,
V_198 , & V_194 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_30 , V_194 ) ;
return - V_13 ;
}
V_28 = F_1 ( V_2 , V_14 ,
V_199 , & V_195 ) ;
V_145 = ( ( ( ( T_1 ) V_194 ) << 8 ) | ( T_1 ) V_195 ) ;
if ( V_145 != V_200 ) {
F_2 ( & V_2 -> V_11 , L_31 , V_145 ) ;
return - V_13 ;
}
V_28 = F_1 ( V_2 , V_14 ,
V_201 , & V_194 ) ;
V_196 = ( V_23 ) V_194 & 0x0f ;
F_55 ( & V_2 -> V_11 , L_32 , V_145 ) ;
return 0 ;
}
static int F_56 ( struct V_44 * V_45 , int V_202 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
int V_28 ;
F_26 ( & V_11 -> V_110 ) ;
if( V_202 )
F_13 ( & V_2 -> V_11 , L_33 ) ;
else
F_13 ( & V_2 -> V_11 , L_34 ) ;
V_28 = F_7 ( V_2 , V_14 , V_203 ,
V_202 ? V_204 :
V_205 ) ;
#if 0
ov2680_res = ov2680_res_preview;
N_RES = N_RES_PREVIEW;
#endif
F_27 ( & V_11 -> V_110 ) ;
return V_28 ;
}
static int F_57 ( struct V_44 * V_45 ,
int V_206 , void * V_160 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
int V_28 = 0 ;
if ( ! V_160 )
return - V_13 ;
V_11 -> V_160 =
(struct V_207 * ) V_160 ;
F_26 ( & V_11 -> V_110 ) ;
V_28 = F_45 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_35 ) ;
goto V_208;
}
V_28 = F_44 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_36 ) ;
goto V_209;
}
V_28 = V_11 -> V_160 -> V_210 ( V_45 , 1 ) ;
if ( V_28 )
goto V_211;
V_28 = F_53 ( V_2 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_37 ) ;
goto V_211;
}
V_28 = F_45 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_35 ) ;
goto V_211;
}
F_27 ( & V_11 -> V_110 ) ;
return 0 ;
V_211:
V_11 -> V_160 -> V_210 ( V_45 , 0 ) ;
V_209:
F_45 ( V_45 ) ;
F_2 ( & V_2 -> V_11 , L_38 ) ;
V_208:
F_27 ( & V_11 -> V_110 ) ;
return V_28 ;
}
static int F_58 ( struct V_44 * V_45 ,
struct V_212 * V_213 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
if ( ! V_213 )
return - V_17 ;
if ( V_213 -> type != V_214 ) {
F_2 ( & V_2 -> V_11 , L_39 ) ;
return - V_17 ;
}
memset ( V_213 , 0 , sizeof( * V_213 ) ) ;
V_213 -> type = V_214 ;
if ( V_11 -> V_52 >= 0 && V_11 -> V_52 < V_157 ) {
V_213 -> V_215 . V_216 . V_217 = V_218 ;
V_213 -> V_215 . V_216 . V_219 . V_220 = 1 ;
V_213 -> V_215 . V_216 . V_221 = V_11 -> V_222 ;
V_213 -> V_215 . V_216 . V_219 . V_223 =
V_51 [ V_11 -> V_52 ] . V_224 ;
}
return 0 ;
}
static int F_59 ( struct V_44 * V_45 ,
struct V_212 * V_213 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_20 ( V_45 ) ;
V_11 -> V_222 = V_213 -> V_215 . V_216 . V_221 ;
F_51 ( V_2 , L_40 , V_12 , V_11 -> V_222 ) ;
F_26 ( & V_11 -> V_110 ) ;
switch ( V_11 -> V_222 ) {
case V_225 :
V_51 = V_226 ;
V_157 = V_227 ;
break;
case V_228 :
V_51 = V_229 ;
V_157 = V_230 ;
break;
default:
V_51 = V_156 ;
V_157 = V_158 ;
}
F_27 ( & V_11 -> V_110 ) ;
return 0 ;
}
static int F_60 ( struct V_44 * V_45 ,
struct V_231 * V_232 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
V_232 -> V_232 . V_220 = 1 ;
V_232 -> V_232 . V_223 = V_51 [ V_11 -> V_52 ] . V_224 ;
return 0 ;
}
static int F_61 ( struct V_44 * V_45 ,
struct V_183 * V_184 ,
struct V_233 * V_122 )
{
if ( V_122 -> V_34 >= V_234 )
return - V_17 ;
V_122 -> V_122 = V_128 ;
return 0 ;
}
static int F_62 ( struct V_44 * V_45 ,
struct V_183 * V_184 ,
struct V_235 * V_236 )
{
int V_34 = V_236 -> V_34 ;
if ( V_34 >= V_157 )
return - V_17 ;
V_236 -> V_237 = V_51 [ V_34 ] . V_172 ;
V_236 -> V_238 = V_51 [ V_34 ] . V_175 ;
V_236 -> V_239 = V_51 [ V_34 ] . V_172 ;
V_236 -> V_240 = V_51 [ V_34 ] . V_175 ;
return 0 ;
}
static int F_63 ( struct V_44 * V_45 , V_26 * V_241 )
{
struct V_50 * V_11 = F_19 ( V_45 ) ;
F_26 ( & V_11 -> V_110 ) ;
* V_241 = V_51 [ V_11 -> V_52 ] . V_242 ;
F_27 ( & V_11 -> V_110 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_23 ( V_2 ) ;
struct V_50 * V_11 = F_19 ( V_45 ) ;
F_13 ( & V_2 -> V_11 , L_41 ) ;
V_11 -> V_160 -> V_210 ( V_45 , 0 ) ;
F_65 ( V_45 ) ;
F_66 ( & V_11 -> V_45 . V_243 ) ;
F_67 ( & V_11 -> V_144 ) ;
F_68 ( V_11 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
const struct V_244 * V_145 )
{
struct V_50 * V_11 ;
int V_28 ;
void * V_245 ;
unsigned int V_177 ;
V_11 = F_70 ( sizeof( * V_11 ) , V_246 ) ;
if ( ! V_11 ) {
F_2 ( & V_2 -> V_11 , L_42 ) ;
return - V_247 ;
}
F_71 ( & V_11 -> V_110 ) ;
V_11 -> V_52 = 0 ;
F_72 ( & ( V_11 -> V_45 ) , V_2 , & V_248 ) ;
if ( F_73 ( & V_2 -> V_11 ) )
V_245 = F_74 ( & V_11 -> V_45 ,
V_249 ,
V_127 ) ;
else
V_245 = V_2 -> V_11 . V_160 ;
if ( ! V_245 ) {
V_28 = - V_17 ;
goto V_250;
}
V_28 = F_57 ( & V_11 -> V_45 , V_2 -> V_206 , V_245 ) ;
if ( V_28 )
goto V_250;
V_28 = F_75 ( & V_11 -> V_45 , V_245 , V_251 ) ;
if ( V_28 )
goto V_250;
V_11 -> V_45 . V_19 |= V_252 ;
V_11 -> V_188 . V_19 = V_253 ;
V_11 -> V_140 . V_122 = V_128 ;
V_11 -> V_45 . V_243 . V_254 = V_255 ;
V_28 =
F_76 ( & V_11 -> V_144 ,
F_77 ( V_256 ) ) ;
if ( V_28 ) {
F_64 ( V_2 ) ;
return V_28 ;
}
for ( V_177 = 0 ; V_177 < F_77 ( V_256 ) ; V_177 ++ )
F_78 ( & V_11 -> V_144 , & V_256 [ V_177 ] ,
NULL ) ;
if ( V_11 -> V_144 . error ) {
F_64 ( V_2 ) ;
return V_11 -> V_144 . error ;
}
V_11 -> V_144 . V_257 = & V_11 -> V_110 ;
V_11 -> V_45 . V_144 = & V_11 -> V_144 ;
V_28 = F_79 ( & V_11 -> V_45 . V_243 , 1 , & V_11 -> V_188 ) ;
if ( V_28 )
{
F_64 ( V_2 ) ;
F_13 ( & V_2 -> V_11 , L_43 ) ;
}
return V_28 ;
V_250:
F_13 ( & V_2 -> V_11 , L_44 ) ;
F_65 ( & V_11 -> V_45 ) ;
F_68 ( V_11 ) ;
return V_28 ;
}
static int F_80 ( void )
{
return F_81 ( & V_258 ) ;
}
static void F_82 ( void )
{
F_83 ( & V_258 ) ;
}
