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
V_32 . V_34 = 0 ;
for (; V_37 -> type != V_41 ; V_37 ++ ) {
switch ( V_37 -> type & V_42 ) {
case V_43 :
V_6 = F_9 ( V_2 , & V_32 ) ;
if ( V_6 )
return V_6 ;
F_13 ( V_37 -> V_5 ) ;
break;
default:
if ( ! F_11 ( V_2 , & V_32 ,
V_37 ) ) {
V_6 = F_9 ( V_2 , & V_32 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_10 ( V_2 , & V_32 , V_37 ) ;
if ( V_6 ) {
F_2 ( & V_2 -> V_11 , L_6 ,
V_12 ) ;
return V_6 ;
}
break;
}
}
return F_9 ( V_2 , & V_32 ) ;
}
static int F_14 ( struct V_44 * V_45 , T_2 * V_5 )
{
* V_5 = ( V_46 << 16 ) | V_47 ;
return 0 ;
}
static int F_15 ( struct V_44 * V_45 , T_2 * V_5 )
{
* V_5 = ( V_48 << 16 ) | V_49 ;
return 0 ;
}
static int F_16 ( struct V_44 * V_45 , T_2 * V_5 )
{
* V_5 = ( V_48 << 24 ) |
( V_49 << 16 ) |
( V_48 << 8 ) | V_49 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_44 * V_45 = F_18 ( V_2 ) ;
struct V_54 * V_11 = NULL ;
struct V_55 * V_22 = & V_51 -> V_9 ;
const unsigned int V_56 = 19200000 ;
const unsigned int V_57 = 10 ;
unsigned int V_58 ;
T_1 V_59 ;
T_1 V_60 ;
T_1 V_61 ;
T_1 V_62 ;
int V_28 ;
if ( ! V_51 )
return - V_17 ;
V_11 = F_19 ( V_45 ) ;
V_28 = F_1 ( V_2 , V_14 ,
V_63 , & V_59 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_1 ( V_2 , V_14 ,
V_64 , & V_60 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_1 ( V_2 , V_14 ,
V_65 , & V_61 ) ;
if ( V_28 )
return V_28 ;
V_59 = ( V_59 & 0x70 ) >> 4 ;
if ( 0 == V_59 )
return - V_17 ;
V_60 = V_60 & 0x7f ;
V_61 = V_61 & 0x03 ;
V_58 = V_56 / V_59 * V_60
* V_61 / V_57 ;
V_11 -> V_66 = V_58 ;
V_22 -> V_66 = V_58 ;
V_22 -> V_67 = V_68 ;
V_22 -> V_69 =
V_70 ;
V_22 -> V_71 = V_72 ;
V_22 -> V_73 =
V_74 ;
V_22 -> V_75 = V_72 ;
V_22 -> V_76 = V_53 -> V_77 ;
V_22 -> V_78 = V_53 -> V_79 ;
V_22 -> V_80 = V_53 -> V_81 ;
V_28 = F_1 ( V_2 , V_15 ,
V_82 , & V_62 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_83 = V_62 ;
V_28 = F_1 ( V_2 , V_15 ,
V_84 , & V_62 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_85 = V_62 ;
V_28 = F_1 ( V_2 , V_15 ,
V_86 , & V_62 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_87 = V_62 ;
V_28 = F_1 ( V_2 , V_15 ,
V_88 , & V_62 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_89 = V_62 ;
V_28 = F_1 ( V_2 , V_15 ,
V_90 , & V_62 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_91 = V_62 ;
V_28 = F_1 ( V_2 , V_15 ,
V_92 , & V_62 ) ;
if ( V_28 )
return V_28 ;
V_22 -> V_93 = V_62 ;
V_22 -> V_94 = V_53 -> V_95 ?
V_53 -> V_95 : 1 ;
V_22 -> V_96 = V_53 -> V_97 ?
V_53 -> V_97 : 1 ;
return 0 ;
}
static long F_20 ( struct V_44 * V_45 , int V_98 ,
int V_99 , int V_100 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
struct V_54 * V_11 = F_19 ( V_45 ) ;
T_1 V_101 , V_102 ;
int V_28 ;
F_22 ( & V_2 -> V_11 , L_7 ) ;
V_28 = F_7 ( V_2 , V_15 , V_103 , 0 ) ;
if ( V_28 )
return V_28 ;
V_101 = V_11 -> V_79 ;
V_102 = V_11 -> V_77 ;
if ( ( V_98 + V_70 ) > V_102 )
V_102 = V_98 + V_70 ;
V_98 <<= 4 ;
V_100 <<= 2 ;
V_28 = F_7 ( V_2 , V_15 ,
V_104 , V_102 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_15 ,
V_105 , V_101 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_14 ,
V_106 ,
V_98 & 0xff ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_15 ,
V_107 ,
( V_98 >> 8 ) & 0xfff ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_15 ,
V_108 , V_99 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_15 ,
V_109 , V_100 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_15 ,
V_110 , V_100 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_15 ,
V_111 , V_100 ) ;
return V_28 ;
}
static int F_23 ( struct V_44 * V_45 , int V_112 ,
int V_99 , int V_100 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
int V_28 ;
F_24 ( & V_11 -> V_113 ) ;
V_28 = F_20 ( V_45 , V_112 , V_99 , V_100 ) ;
F_25 ( & V_11 -> V_113 ) ;
return V_28 ;
}
static long F_26 ( struct V_44 * V_45 ,
struct V_114 * V_112 )
{
int exp = V_112 -> V_115 [ 0 ] ;
int V_99 = V_112 -> V_99 [ 0 ] ;
int V_100 = V_112 -> V_99 [ 1 ] ;
if ( V_99 == 0 ) {
struct V_1 * V_2 = F_21 ( V_45 ) ;
F_27 ( V_2 , L_8 , V_12 ) ;
return - V_17 ;
}
return F_23 ( V_45 , exp , V_99 , V_100 ) ;
}
static long F_28 ( struct V_44 * V_45 , unsigned int V_116 , void * V_117 )
{
switch ( V_116 ) {
case V_118 :
return F_26 ( V_45 , V_117 ) ;
default:
return - V_17 ;
}
return 0 ;
}
static int F_29 ( struct V_44 * V_45 , T_2 * V_119 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
T_1 V_120 , V_121 ;
int V_28 ;
V_28 = F_1 ( V_2 , V_14 ,
V_106 ,
& V_120 ) ;
if ( V_28 )
goto V_6;
V_28 = F_1 ( V_2 , V_14 ,
V_122 ,
& V_121 ) ;
if ( V_28 )
goto V_6;
V_120 += V_121 << 8 ;
V_28 = F_1 ( V_2 , V_14 ,
V_107 ,
& V_121 ) ;
if ( V_28 )
goto V_6;
* V_119 = V_120 + ( ( ( V_26 ) V_121 << 16 ) ) ;
V_6:
return V_28 ;
}
static int F_30 ( struct V_123 * V_32 )
{
struct V_54 * V_11 =
F_31 ( V_32 -> V_124 , struct V_54 , V_125 ) ;
int V_28 = 0 ;
unsigned int V_5 ;
switch ( V_32 -> V_126 ) {
case V_127 :
V_28 = F_29 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_128 :
V_28 = F_14 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_129 :
V_28 = F_15 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_130 :
V_28 = F_16 ( & V_11 -> V_45 , & V_32 -> V_5 ) ;
break;
case V_131 :
V_5 = V_132 [ V_11 -> V_133 ] . V_134 ;
if ( V_5 == 0 )
return - V_17 ;
V_32 -> V_5 = V_5 * 1000 ;
break;
default:
V_28 = - V_17 ;
}
return V_28 ;
}
static int F_32 ( struct V_44 * V_45 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
F_24 ( & V_11 -> V_113 ) ;
V_132 = V_135 ;
V_136 = V_137 ;
F_25 ( & V_11 -> V_113 ) ;
return 0 ;
}
static int F_33 ( struct V_44 * V_45 , bool V_138 )
{
int V_28 = - 1 ;
struct V_54 * V_11 = F_19 ( V_45 ) ;
if ( ! V_11 || ! V_11 -> V_139 )
return - V_13 ;
if ( V_11 -> V_139 -> F_33 )
return V_11 -> V_139 -> F_33 ( V_45 , V_138 ) ;
if ( V_138 ) {
V_28 = V_11 -> V_139 -> V_140 ( V_45 , 1 ) ;
if ( V_28 == 0 ) {
V_28 = V_11 -> V_139 -> V_141 ( V_45 , 1 ) ;
if ( V_28 )
V_11 -> V_139 -> V_140 ( V_45 , 0 ) ;
}
} else {
V_28 = V_11 -> V_139 -> V_140 ( V_45 , 0 ) ;
V_28 |= V_11 -> V_139 -> V_141 ( V_45 , 0 ) ;
}
return V_28 ;
}
static int F_34 ( struct V_44 * V_45 , bool V_138 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
int V_28 = - 1 ;
if ( ! V_11 || ! V_11 -> V_139 )
return - V_13 ;
if ( V_11 -> V_139 -> F_34 )
return V_11 -> V_139 -> F_34 ( V_45 , V_138 ) ;
V_28 = V_11 -> V_139 -> V_142 ( V_45 , V_138 ) ;
V_28 |= V_11 -> V_139 -> V_143 ( V_45 , ! V_138 ) ;
return V_28 ;
}
static int F_35 ( struct V_44 * V_45 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
int V_28 ;
if ( ! V_11 -> V_139 ) {
F_2 ( & V_2 -> V_11 ,
L_9 ) ;
return - V_13 ;
}
V_28 = F_33 ( V_45 , 1 ) ;
if ( V_28 )
goto V_144;
F_36 ( 5000 , 6000 ) ;
V_28 = F_34 ( V_45 , 1 ) ;
if ( V_28 ) {
V_28 = F_34 ( V_45 , 0 ) ;
if ( V_28 )
goto V_144;
}
V_28 = V_11 -> V_139 -> V_145 ( V_45 , 1 ) ;
if ( V_28 )
goto V_146;
F_13 ( 20 ) ;
return 0 ;
V_146:
F_34 ( V_45 , 0 ) ;
V_144:
F_33 ( V_45 , 0 ) ;
F_2 ( & V_2 -> V_11 , L_10 ) ;
return V_28 ;
}
static int F_37 ( struct V_44 * V_45 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
int V_28 = 0 ;
if ( ! V_11 -> V_139 ) {
F_2 ( & V_2 -> V_11 ,
L_9 ) ;
return - V_13 ;
}
V_28 = V_11 -> V_139 -> V_145 ( V_45 , 0 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_11 ) ;
V_28 = F_34 ( V_45 , 0 ) ;
if ( V_28 ) {
V_28 = F_34 ( V_45 , 0 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_12 ) ;
}
V_28 = F_33 ( V_45 , 0 ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_13 ) ;
return V_28 ;
}
static int F_38 ( struct V_44 * V_45 , int V_147 )
{
int V_28 ;
if ( V_147 == 0 )
return F_37 ( V_45 ) ;
else {
V_28 = F_35 ( V_45 ) ;
if ( ! V_28 )
return F_32 ( V_45 ) ;
}
return V_28 ;
}
static int F_39 ( struct V_52 * V_53 , V_26 V_148 , V_26 V_149 )
{
unsigned int V_150 = ( V_53 -> V_151 << 13 ) / V_148 ;
unsigned int V_152 ;
int V_153 ;
if ( V_149 == 0 )
return - 1 ;
V_152 = ( V_53 -> V_154 << 13 ) / V_149 ;
if ( V_152 == 0 )
return - 1 ;
V_153 = abs ( ( ( V_150 << 13 ) / V_152 ) - 8192 ) ;
if ( ( V_150 < 8192 ) || ( V_152 < 8192 ) ||
( V_153 > V_155 ) )
return - 1 ;
return V_150 + V_152 ;
}
static int F_40 ( int V_148 , int V_149 )
{
int V_156 ;
int V_157 = - 1 ;
int V_158 ;
int V_159 = V_160 ;
struct V_52 * V_161 = NULL ;
for ( V_156 = 0 ; V_156 < V_136 ; V_156 ++ ) {
V_161 = & V_132 [ V_156 ] ;
V_158 = F_39 ( V_161 , V_148 , V_149 ) ;
if ( V_158 == - 1 )
continue;
if ( V_158 < V_159 ) {
V_159 = V_158 ;
V_157 = V_156 ;
}
}
return V_157 ;
}
static int F_41 ( int V_148 , int V_149 )
{
int V_156 ;
for ( V_156 = 0 ; V_156 < V_136 ; V_156 ++ ) {
if ( V_148 != V_132 [ V_156 ] . V_151 )
continue;
if ( V_149 != V_132 [ V_156 ] . V_154 )
continue;
return V_156 ;
}
return - 1 ;
}
static int F_42 ( struct V_44 * V_45 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
int V_28 = 0 ;
V_28 = F_7 ( V_2 , V_14 ,
V_162 , 0x01 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_14 ) ;
return V_28 ;
}
V_28 = F_12 ( V_2 , V_132 [ V_11 -> V_133 ] . V_163 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_15 ) ;
return V_28 ;
}
return V_28 ;
}
static int F_43 ( struct V_44 * V_45 ,
struct V_164 * V_165 ,
struct V_166 * V_167 )
{
struct V_168 * V_169 = & V_167 -> V_167 ;
struct V_54 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
struct V_50 * V_170 = NULL ;
int V_28 = 0 ;
int V_157 ;
if ( V_167 -> V_171 )
return - V_17 ;
if ( ! V_169 )
return - V_17 ;
V_170 = F_44 ( V_45 ) ;
if ( ! V_170 )
return - V_17 ;
F_24 ( & V_11 -> V_113 ) ;
V_157 = F_40 ( V_169 -> V_151 , V_169 -> V_154 ) ;
if ( V_157 == - 1 ) {
V_169 -> V_151 = V_132 [ V_136 - 1 ] . V_151 ;
V_169 -> V_154 = V_132 [ V_136 - 1 ] . V_154 ;
} else {
V_169 -> V_151 = V_132 [ V_157 ] . V_151 ;
V_169 -> V_154 = V_132 [ V_157 ] . V_154 ;
}
V_169 -> V_172 = V_173 ;
if ( V_167 -> V_174 == V_175 ) {
V_165 -> V_176 = * V_169 ;
F_25 ( & V_11 -> V_113 ) ;
return 0 ;
}
V_11 -> V_133 = F_41 ( V_169 -> V_151 , V_169 -> V_154 ) ;
if ( V_11 -> V_133 == - 1 ) {
F_2 ( & V_2 -> V_11 , L_16 ) ;
F_25 ( & V_11 -> V_113 ) ;
return - V_17 ;
}
V_11 -> V_79 = V_132 [ V_11 -> V_133 ] . V_79 ;
V_11 -> V_77 = V_132 [ V_11 -> V_133 ] . V_77 ;
V_28 = F_42 ( V_45 ) ;
if ( V_28 ) {
int V_156 = 0 ;
F_2 ( & V_2 -> V_11 , L_17 ) ;
for ( V_156 = 0 ; V_156 < V_177 ; V_156 ++ ) {
F_2 ( & V_2 -> V_11 ,
L_18 ,
V_156 + 1 , V_177 ) ;
F_37 ( V_45 ) ;
V_28 = F_35 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_19 ) ;
continue;
}
V_28 = F_42 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_20 ) ;
} else {
F_2 ( & V_2 -> V_11 , L_21 ) ;
break;
}
}
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_22 ) ;
goto V_6;
}
}
V_28 = F_17 ( V_2 , V_170 ,
& V_132 [ V_11 -> V_133 ] ) ;
if ( V_28 )
F_2 ( & V_2 -> V_11 , L_23 ) ;
V_6:
F_25 ( & V_11 -> V_113 ) ;
return V_28 ;
}
static int F_45 ( struct V_44 * V_45 ,
struct V_164 * V_165 ,
struct V_166 * V_167 )
{
struct V_168 * V_169 = & V_167 -> V_167 ;
struct V_54 * V_11 = F_19 ( V_45 ) ;
if ( V_167 -> V_171 )
return - V_17 ;
if ( ! V_169 )
return - V_17 ;
V_169 -> V_151 = V_132 [ V_11 -> V_133 ] . V_151 ;
V_169 -> V_154 = V_132 [ V_11 -> V_133 ] . V_154 ;
V_169 -> V_172 = V_178 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_179 * V_10 = V_2 -> V_10 ;
T_1 V_180 , V_181 ;
int V_28 ;
T_1 V_126 ;
V_23 V_182 ;
if ( ! F_47 ( V_10 , V_183 ) )
return - V_13 ;
V_28 = F_1 ( V_2 , V_14 ,
V_184 , & V_180 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_24 , V_180 ) ;
return - V_13 ;
}
V_28 = F_1 ( V_2 , V_14 ,
V_185 , & V_181 ) ;
V_126 = ( V_180 << 8 ) | V_181 ;
if ( ( V_126 != V_186 ) && ( V_126 != V_187 ) ) {
F_2 ( & V_2 -> V_11 , L_25 ) ;
return - V_13 ;
}
V_28 = F_1 ( V_2 , V_14 ,
V_188 , & V_180 ) ;
V_182 = ( V_23 ) V_180 & 0x0f ;
F_22 ( & V_2 -> V_11 , L_26 , V_182 ) ;
F_22 ( & V_2 -> V_11 , L_27 ) ;
return 0 ;
}
static int F_48 ( struct V_44 * V_45 , int V_189 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
int V_28 ;
F_24 ( & V_11 -> V_113 ) ;
V_28 = F_7 ( V_2 , V_14 , V_190 ,
V_189 ? V_191 :
V_192 ) ;
F_25 ( & V_11 -> V_113 ) ;
return V_28 ;
}
static int F_49 ( struct V_44 * V_45 ,
int V_193 , void * V_139 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
int V_28 = 0 ;
if ( ! V_139 )
return - V_13 ;
V_11 -> V_139 =
(struct V_194 * ) V_139 ;
F_24 ( & V_11 -> V_113 ) ;
if ( V_11 -> V_139 -> V_195 ) {
V_28 = V_11 -> V_139 -> V_195 ( V_2 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_28 ) ;
goto V_196;
}
}
V_28 = F_37 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_29 ) ;
goto V_197;
}
V_28 = F_35 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_30 ) ;
goto V_198;
}
V_28 = V_11 -> V_139 -> V_199 ( V_45 , 1 ) ;
if ( V_28 )
goto V_200;
V_28 = F_46 ( V_2 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_31 ) ;
goto V_200;
}
V_28 = F_37 ( V_45 ) ;
if ( V_28 ) {
F_2 ( & V_2 -> V_11 , L_29 ) ;
goto V_200;
}
F_25 ( & V_11 -> V_113 ) ;
return 0 ;
V_200:
V_11 -> V_139 -> V_199 ( V_45 , 0 ) ;
V_198:
F_37 ( V_45 ) ;
F_2 ( & V_2 -> V_11 , L_32 ) ;
V_197:
if ( V_11 -> V_139 -> V_201 )
V_11 -> V_139 -> V_201 () ;
V_196:
F_25 ( & V_11 -> V_113 ) ;
return V_28 ;
}
static int F_50 ( struct V_44 * V_45 ,
struct V_202 * V_203 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
if ( ! V_203 )
return - V_17 ;
if ( V_203 -> type != V_204 ) {
F_2 ( & V_2 -> V_11 , L_33 ) ;
return - V_17 ;
}
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_203 -> type = V_204 ;
if ( V_11 -> V_133 >= 0 && V_11 -> V_133 < V_136 ) {
V_203 -> V_205 . V_206 . V_207 = V_208 ;
V_203 -> V_205 . V_206 . V_209 . V_210 = 1 ;
V_203 -> V_205 . V_206 . V_211 = V_11 -> V_212 ;
V_203 -> V_205 . V_206 . V_209 . V_213 =
V_132 [ V_11 -> V_133 ] . V_214 ;
}
return 0 ;
}
static int F_51 ( struct V_44 * V_45 ,
struct V_202 * V_203 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
V_11 -> V_212 = V_203 -> V_205 . V_206 . V_211 ;
F_24 ( & V_11 -> V_113 ) ;
switch ( V_11 -> V_212 ) {
case V_215 :
V_132 = V_216 ;
V_136 = V_217 ;
break;
case V_218 :
V_132 = V_219 ;
V_136 = V_220 ;
break;
default:
V_132 = V_135 ;
V_136 = V_137 ;
}
F_25 ( & V_11 -> V_113 ) ;
return 0 ;
}
static int F_52 ( struct V_44 * V_45 ,
struct V_221 * V_222 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
V_222 -> V_222 . V_210 = 1 ;
V_222 -> V_222 . V_213 = V_132 [ V_11 -> V_133 ] . V_214 ;
return 0 ;
}
static int F_53 ( struct V_44 * V_45 ,
struct V_164 * V_165 ,
struct V_223 * V_172 )
{
if ( V_172 -> V_34 >= V_224 )
return - V_17 ;
V_172 -> V_172 = V_178 ;
return 0 ;
}
static int F_54 ( struct V_44 * V_45 ,
struct V_164 * V_165 ,
struct V_225 * V_226 )
{
int V_34 = V_226 -> V_34 ;
if ( V_34 >= V_136 )
return - V_17 ;
V_226 -> V_227 = V_132 [ V_34 ] . V_151 ;
V_226 -> V_228 = V_132 [ V_34 ] . V_154 ;
V_226 -> V_229 = V_132 [ V_34 ] . V_151 ;
V_226 -> V_230 = V_132 [ V_34 ] . V_154 ;
return 0 ;
}
static int F_55 ( struct V_44 * V_45 , V_26 * V_231 )
{
struct V_54 * V_11 = F_19 ( V_45 ) ;
F_24 ( & V_11 -> V_113 ) ;
* V_231 = V_132 [ V_11 -> V_133 ] . V_232 ;
F_25 ( & V_11 -> V_113 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_18 ( V_2 ) ;
struct V_54 * V_11 = F_19 ( V_45 ) ;
F_22 ( & V_2 -> V_11 , L_34 ) ;
if ( V_11 -> V_139 -> V_201 )
V_11 -> V_139 -> V_201 () ;
V_11 -> V_139 -> V_199 ( V_45 , 0 ) ;
F_57 ( & V_11 -> V_125 ) ;
F_58 ( V_45 ) ;
F_59 ( V_45 ) ;
F_60 ( & V_11 -> V_45 . V_233 ) ;
F_61 ( V_11 ) ;
return 0 ;
}
static int F_62 ( struct V_54 * V_11 )
{
struct V_234 * V_235 ;
unsigned int V_156 ;
V_235 = & V_11 -> V_125 ;
F_63 ( & V_11 -> V_125 , F_64 ( V_236 ) ) ;
for ( V_156 = 0 ; V_156 < F_64 ( V_236 ) ; V_156 ++ )
F_65 ( & V_11 -> V_125 , & V_236 [ V_156 ] ,
NULL ) ;
V_11 -> V_237 = F_66 ( & V_11 -> V_125 , V_131 ) ;
if ( V_11 -> V_125 . error || ! V_11 -> V_237 )
return V_11 -> V_125 . error ;
V_11 -> V_45 . V_125 = V_235 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
const struct V_238 * V_126 )
{
struct V_54 * V_11 ;
void * V_239 ;
int V_28 ;
struct V_240 * V_241 ;
V_11 = F_68 ( sizeof( * V_11 ) , V_242 ) ;
if ( ! V_11 ) {
F_2 ( & V_2 -> V_11 , L_35 ) ;
return - V_243 ;
}
F_69 ( & V_11 -> V_113 ) ;
V_11 -> V_133 = 0 ;
F_70 ( & ( V_11 -> V_45 ) , V_2 , & V_244 ) ;
V_239 = V_2 -> V_11 . V_139 ;
V_241 = F_71 ( & V_2 -> V_11 ) ;
if ( V_241 ) {
V_241 -> V_245 . V_19 . V_246 = 0 ;
V_239 = F_72 ( & V_11 -> V_45 ,
V_247 ,
V_248 ) ;
}
V_28 = F_49 ( & V_11 -> V_45 , V_2 -> V_193 , V_239 ) ;
if ( V_28 )
goto V_249;
V_28 = F_62 ( V_11 ) ;
if ( V_28 )
goto V_250;
V_11 -> V_45 . V_19 |= V_251 ;
V_11 -> V_171 . V_19 = V_252 ;
V_11 -> V_167 . V_172 = V_178 ;
V_11 -> V_45 . V_233 . V_253 = V_254 ;
V_28 = F_73 ( & V_11 -> V_45 . V_233 , 1 , & V_11 -> V_171 ) ;
if ( V_28 )
F_56 ( V_2 ) ;
if ( F_74 ( & V_2 -> V_11 ) )
V_28 = F_75 ( & V_11 -> V_45 , V_239 , V_255 ) ;
return V_28 ;
V_250:
F_57 ( & V_11 -> V_125 ) ;
V_249:
F_58 ( & V_11 -> V_45 ) ;
F_61 ( V_11 ) ;
return V_28 ;
}
static int F_76 ( void )
{
return F_77 ( & V_256 ) ;
}
static void F_78 ( void )
{
F_79 ( & V_256 ) ;
}
