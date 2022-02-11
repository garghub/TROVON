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
if ( V_3 != V_14 ) {
F_2 ( & V_2 -> V_11 , L_2 ,
V_12 ) ;
return - V_15 ;
}
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ 0 ] . V_16 = V_2 -> V_16 ;
V_8 [ 0 ] . V_17 = 0 ;
V_8 [ 0 ] . V_18 = 1 ;
V_8 [ 0 ] . V_19 = V_9 ;
V_9 [ 0 ] = ( V_20 ) ( V_4 & 0xff ) ;
V_8 [ 1 ] . V_16 = V_2 -> V_16 ;
V_8 [ 1 ] . V_18 = V_3 ;
V_8 [ 1 ] . V_17 = V_21 ;
V_8 [ 1 ] . V_19 = V_9 ;
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
* V_5 = ( V_20 ) V_9 [ 0 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_18 , V_20 * V_9 )
{
struct V_7 V_8 ;
const int V_23 = 1 ;
int V_24 ;
V_8 . V_16 = V_2 -> V_16 ;
V_8 . V_17 = 0 ;
V_8 . V_18 = V_18 ;
V_8 . V_19 = V_9 ;
V_24 = F_3 ( V_2 -> V_10 , & V_8 , 1 ) ;
return V_24 == V_23 ? 0 : - V_22 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
V_20 V_4 , V_20 V_5 )
{
int V_24 ;
unsigned char V_9 [ 4 ] = { 0 } ;
const T_1 V_18 = V_3 + sizeof( V_20 ) ;
if ( V_3 != V_14 ) {
F_2 ( & V_2 -> V_11 ,
L_4 , V_12 ) ;
return - V_15 ;
}
V_9 [ 0 ] = V_4 ;
V_9 [ 1 ] = V_5 ;
V_24 = F_4 ( V_2 , V_18 , V_9 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 ,
L_5 ,
V_5 , V_4 , V_24 ) ;
return V_24 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
T_1 V_27 ;
if ( V_26 -> V_28 == 0 )
return 0 ;
V_27 = sizeof( V_20 ) + V_26 -> V_28 ;
V_26 -> V_28 = 0 ;
return F_4 ( V_2 , V_27 , ( V_20 * ) & V_26 -> V_29 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
const struct V_30 * V_31 )
{
int V_27 ;
if ( V_31 -> type != V_14 )
return - V_15 ;
V_27 = 1 ;
V_26 -> V_29 . V_9 [ V_26 -> V_28 ] = ( V_20 ) V_31 -> V_5 ;
if ( V_26 -> V_28 == 0 )
V_26 -> V_29 . V_16 = V_31 -> V_4 ;
V_26 -> V_28 += V_27 ;
if ( V_26 -> V_28 + sizeof( V_20 ) >= V_32 )
return F_6 ( V_2 , V_26 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
const struct V_30 * V_31 )
{
if ( V_26 -> V_28 == 0 )
return 1 ;
return V_26 -> V_29 . V_16 + V_26 -> V_28 == V_31 -> V_4 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_30 * V_33 )
{
const struct V_30 * V_31 = V_33 ;
struct V_25 V_26 ;
int V_6 ;
V_26 . V_28 = 0 ;
for (; V_31 -> type != V_34 ; V_31 ++ ) {
switch ( V_31 -> type & V_35 ) {
case V_36 :
V_6 = F_6 ( V_2 , & V_26 ) ;
if ( V_6 )
return V_6 ;
F_10 ( V_31 -> V_5 ) ;
break;
default:
if ( ! F_8 ( V_2 , & V_26 ,
V_31 ) ) {
V_6 = F_6 ( V_2 , & V_26 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_7 ( V_2 , & V_26 , V_31 ) ;
if ( V_6 ) {
F_2 ( & V_2 -> V_11 , L_6 ,
V_12 ) ;
return V_6 ;
}
break;
}
}
return F_6 ( V_2 , & V_26 ) ;
}
static int F_11 ( struct V_37 * V_38 , T_2 * V_5 )
{
* V_5 = ( V_39 << 16 ) | V_40 ;
return 0 ;
}
static int F_12 ( struct V_37 * V_38 , T_2 * V_5 )
{
* V_5 = ( V_41 << 16 ) | V_42 ;
return 0 ;
}
static int F_13 ( struct V_37 * V_38 , T_2 * V_5 )
{
* V_5 = ( V_41 << 24 ) |
( V_42 << 16 ) |
( V_41 << 8 ) | V_42 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
const struct V_45 * V_46 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_48 * V_19 = & V_44 -> V_9 ;
T_1 V_49 , V_50 , V_51 ;
int V_24 ;
if ( ! V_44 )
return - V_15 ;
V_19 -> V_52 = V_11 -> V_52 = 30000000 ;
V_19 -> V_53 = V_54 ;
V_19 -> V_55 =
V_56 ;
V_19 -> V_57 = V_58 ;
V_19 -> V_59 =
V_60 ;
V_19 -> V_61 = V_58 ;
V_19 -> V_62 = V_46 -> V_63 ;
V_19 -> V_64 = V_46 -> V_65 ;
V_19 -> V_66 = V_46 -> V_67 ;
V_24 = F_1 ( V_2 , V_14 ,
V_68 , & V_50 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_69 , & V_49 ) ;
if ( V_24 )
return V_24 ;
V_19 -> V_70 = ( V_50 << 8 ) | V_49 ;
V_24 = F_1 ( V_2 , V_14 ,
V_71 , & V_50 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_72 , & V_49 ) ;
if ( V_24 )
return V_24 ;
V_19 -> V_73 = ( V_50 << 8 ) | V_49 ;
V_24 = F_1 ( V_2 , V_14 ,
V_74 , & V_50 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_75 , & V_49 ) ;
if ( V_24 )
return V_24 ;
V_19 -> V_76 = ( V_50 << 8 ) | V_49 ;
V_24 = F_1 ( V_2 , V_14 ,
V_77 , & V_50 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_78 , & V_49 ) ;
if ( V_24 )
return V_24 ;
V_19 -> V_79 = ( V_50 << 8 ) | V_49 ;
V_19 -> V_80 = V_19 -> V_70 +
V_19 -> V_76 - 1 ;
V_19 -> V_81 = V_19 -> V_73 +
V_19 -> V_79 - 1 ;
V_24 = F_1 ( V_2 , V_14 ,
V_82 , & V_50 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_83 , & V_49 ) ;
if ( V_24 )
return V_24 ;
V_51 = ( V_50 << 8 ) | V_49 ;
V_24 = F_1 ( V_2 , V_14 ,
V_84 , & V_50 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_85 , & V_49 ) ;
#if 0
buf->line_length_pck = buf->output_width + 16 + dummy +
(((u16)reg_val_h << 8) | (u16)reg_val) + 4;
#endif
V_24 = F_1 ( V_2 , V_14 ,
V_86 , & V_50 ) ;
V_24 = F_1 ( V_2 , V_14 ,
V_87 , & V_49 ) ;
if ( V_24 )
return V_24 ;
#if 0
buf->frame_length_lines = buf->output_height + 32 +
(((u16)reg_val_h << 8) | (u16)reg_val);
#endif
V_19 -> V_88 = V_46 -> V_89 ?
V_46 -> V_89 : 1 ;
V_19 -> V_90 = V_46 -> V_91 ?
V_46 -> V_91 : 1 ;
return 0 ;
}
static long F_17 ( struct V_37 * V_38 , int V_92 ,
int V_93 , int V_94 )
{
struct V_1 * V_2 = F_18 ( V_38 ) ;
T_1 V_95 = ( T_1 ) V_92 ;
int V_24 = 0 ;
T_1 V_96 , V_97 , V_98 = 0xF0 , V_99 = 0xF0 ;
V_96 = V_95 >> 8 ;
V_97 = V_95 & 0xff ;
V_24 = F_5 ( V_2 , V_14 ,
V_100 , V_96 ) ;
V_24 = F_5 ( V_2 , V_14 ,
V_101 , V_97 ) ;
if ( V_93 <= 0x58 ) {
V_98 = 0x40 ;
V_99 = 0x58 ;
} else if ( V_93 < 256 ) {
V_98 = 0x40 ;
V_99 = V_93 ;
} else {
V_99 = 64 * V_93 / 256 ;
V_98 = 0xff ;
}
V_24 = F_5 ( V_2 , V_14 ,
V_102 , ( V_20 ) V_98 ) ;
V_24 = F_5 ( V_2 , V_14 ,
V_103 , ( V_20 ) V_99 ) ;
return V_24 ;
}
static int F_19 ( struct V_37 * V_38 , int V_104 ,
int V_93 , int V_94 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
int V_24 ;
F_20 ( & V_11 -> V_105 ) ;
V_24 = F_17 ( V_38 , V_104 , V_93 , V_94 ) ;
F_21 ( & V_11 -> V_105 ) ;
return V_24 ;
}
static long F_22 ( struct V_37 * V_38 ,
struct V_106 * V_104 )
{
int exp = V_104 -> V_107 [ 0 ] ;
int V_93 = V_104 -> V_93 [ 0 ] ;
int V_94 = V_104 -> V_93 [ 1 ] ;
if ( V_93 == 0 ) {
struct V_1 * V_2 = F_18 ( V_38 ) ;
F_23 ( V_2 , L_7 , V_12 ) ;
return - V_15 ;
}
return F_19 ( V_38 , exp , V_93 , V_94 ) ;
}
static long F_24 ( struct V_37 * V_38 , unsigned int V_108 , void * V_109 )
{
switch ( V_108 ) {
case V_110 :
return F_22 ( V_38 , V_109 ) ;
default:
return - V_15 ;
}
return 0 ;
}
static int F_25 ( struct V_37 * V_38 , T_2 * V_111 )
{
struct V_1 * V_2 = F_18 ( V_38 ) ;
T_1 V_112 , V_113 ;
int V_24 ;
V_24 = F_1 ( V_2 , V_14 ,
V_101 ,
& V_112 ) ;
if ( V_24 )
goto V_6;
V_24 = F_1 ( V_2 , V_14 ,
V_100 ,
& V_113 ) ;
if ( V_24 )
goto V_6;
V_112 += V_113 << 8 ;
* V_111 = V_112 ;
V_6:
return V_24 ;
}
static int F_26 ( struct V_114 * V_26 )
{
struct V_47 * V_11 =
F_27 ( V_26 -> V_115 , struct V_47 , V_116 ) ;
int V_24 = 0 ;
switch ( V_26 -> V_117 ) {
case V_118 :
V_24 = F_25 ( & V_11 -> V_38 , & V_26 -> V_5 ) ;
break;
case V_119 :
V_24 = F_11 ( & V_11 -> V_38 , & V_26 -> V_5 ) ;
break;
case V_120 :
V_24 = F_12 ( & V_11 -> V_38 , & V_26 -> V_5 ) ;
break;
case V_121 :
V_24 = F_13 ( & V_11 -> V_38 , & V_26 -> V_5 ) ;
break;
default:
V_24 = - V_15 ;
}
return V_24 ;
}
static int F_28 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_18 ( V_38 ) ;
V_122 = V_123 ;
V_124 = V_125 ;
return F_9 ( V_2 , V_126 ) ;
}
static int F_29 ( struct V_37 * V_38 , bool V_127 )
{
int V_24 = - 1 ;
struct V_47 * V_11 = F_16 ( V_38 ) ;
if ( ! V_11 || ! V_11 -> V_128 )
return - V_13 ;
if ( V_11 -> V_128 -> F_29 )
return V_11 -> V_128 -> F_29 ( V_38 , V_127 ) ;
if ( V_127 ) {
V_24 = V_11 -> V_128 -> V_129 ( V_38 , 1 ) ;
F_30 ( 60 , 90 ) ;
if ( V_24 == 0 )
V_24 |= V_11 -> V_128 -> V_130 ( V_38 , 1 ) ;
} else {
V_24 = V_11 -> V_128 -> V_129 ( V_38 , 0 ) ;
V_24 |= V_11 -> V_128 -> V_130 ( V_38 , 0 ) ;
}
return V_24 ;
}
static int F_31 ( struct V_37 * V_38 , bool V_127 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
int V_24 = - 1 ;
if ( ! V_11 || ! V_11 -> V_128 )
return - V_13 ;
if ( V_11 -> V_128 -> F_31 )
return V_11 -> V_128 -> F_31 ( V_38 , V_127 ) ;
V_24 |= V_11 -> V_128 -> V_131 ( V_38 , ! V_127 ) ;
F_30 ( 60 , 90 ) ;
return V_11 -> V_128 -> V_132 ( V_38 , V_127 ) ;
}
static int F_32 ( struct V_37 * V_38 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
int V_24 ;
if ( ! V_11 -> V_128 ) {
F_2 ( & V_2 -> V_11 ,
L_8 ) ;
return - V_13 ;
}
V_24 = F_29 ( V_38 , 1 ) ;
if ( V_24 )
goto V_133;
F_30 ( 5000 , 6000 ) ;
V_24 = V_11 -> V_128 -> V_134 ( V_38 , 1 ) ;
if ( V_24 )
goto V_135;
F_30 ( 5000 , 6000 ) ;
V_24 = F_31 ( V_38 , 1 ) ;
if ( V_24 ) {
V_24 = F_31 ( V_38 , 1 ) ;
if ( V_24 )
goto V_133;
}
F_10 ( 5 ) ;
return 0 ;
V_135:
F_31 ( V_38 , 0 ) ;
V_133:
F_29 ( V_38 , 0 ) ;
F_2 ( & V_2 -> V_11 , L_9 ) ;
return V_24 ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
int V_24 = 0 ;
if ( ! V_11 -> V_128 ) {
F_2 ( & V_2 -> V_11 ,
L_8 ) ;
return - V_13 ;
}
V_24 = F_31 ( V_38 , 0 ) ;
if ( V_24 ) {
V_24 = F_31 ( V_38 , 0 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 , L_10 ) ;
}
V_24 = V_11 -> V_128 -> V_134 ( V_38 , 0 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 , L_11 ) ;
V_24 = F_29 ( V_38 , 0 ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 , L_12 ) ;
return V_24 ;
}
static int F_34 ( struct V_37 * V_38 , int V_136 )
{
int V_24 ;
if ( V_136 == 0 )
V_24 = F_33 ( V_38 ) ;
else {
V_24 = F_32 ( V_38 ) ;
if ( ! V_24 )
V_24 = F_28 ( V_38 ) ;
V_137 = 1 ;
}
return V_24 ;
}
static int F_35 ( struct V_45 * V_46 , T_3 V_138 , T_3 V_139 )
{
unsigned int V_140 = ( V_46 -> V_141 << 13 ) / V_138 ;
unsigned int V_142 ;
int V_143 ;
if ( V_139 == 0 )
return - 1 ;
V_142 = ( V_46 -> V_144 << 13 ) / V_139 ;
if ( V_142 == 0 )
return - 1 ;
V_143 = abs ( ( ( V_140 << 13 ) / V_142 ) - 8192 ) ;
if ( ( V_140 < 8192 ) || ( V_142 < 8192 ) ||
( V_143 > V_145 ) )
return - 1 ;
return V_140 + V_142 ;
}
static int F_36 ( int V_138 , int V_139 )
{
int V_146 ;
int V_147 = - 1 ;
int V_148 ;
int V_149 = V_150 ;
struct V_45 * V_151 = NULL ;
for ( V_146 = 0 ; V_146 < V_124 ; V_146 ++ ) {
V_151 = & V_122 [ V_146 ] ;
V_148 = F_35 ( V_151 , V_138 , V_139 ) ;
if ( V_148 == - 1 )
continue;
if ( V_148 < V_149 ) {
V_149 = V_148 ;
V_147 = V_146 ;
}
}
return V_147 ;
}
static int F_37 ( int V_138 , int V_139 )
{
int V_146 ;
for ( V_146 = 0 ; V_146 < V_124 ; V_146 ++ ) {
if ( V_138 != V_122 [ V_146 ] . V_141 )
continue;
if ( V_139 != V_122 [ V_146 ] . V_144 )
continue;
return V_146 ;
}
return - 1 ;
}
static int F_38 ( struct V_37 * V_38 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
int V_24 = 0 ;
if ( V_137 == 0 ) {
F_33 ( V_38 ) ;
F_32 ( V_38 ) ;
F_9 ( V_2 , V_126 ) ;
}
V_24 = F_9 ( V_2 , V_122 [ V_11 -> V_152 ] . V_153 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_13 ) ;
return V_24 ;
}
V_137 = 0 ;
return V_24 ;
}
static int F_39 ( struct V_37 * V_38 ,
struct V_154 * V_155 ,
struct V_156 * V_157 )
{
struct V_158 * V_159 = & V_157 -> V_157 ;
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
struct V_43 * V_160 = NULL ;
int V_24 = 0 ;
int V_147 ;
V_160 = F_40 ( V_38 ) ;
if ( ! V_160 )
return - V_15 ;
if ( V_157 -> V_161 )
return - V_15 ;
if ( ! V_159 )
return - V_15 ;
F_20 ( & V_11 -> V_105 ) ;
V_147 = F_36 ( V_159 -> V_141 , V_159 -> V_144 ) ;
if ( V_147 == - 1 ) {
V_159 -> V_141 = V_122 [ V_124 - 1 ] . V_141 ;
V_159 -> V_144 = V_122 [ V_124 - 1 ] . V_144 ;
} else {
V_159 -> V_141 = V_122 [ V_147 ] . V_141 ;
V_159 -> V_144 = V_122 [ V_147 ] . V_144 ;
}
V_159 -> V_162 = V_163 ;
if ( V_157 -> V_164 == V_165 ) {
V_155 -> V_166 = * V_159 ;
F_21 ( & V_11 -> V_105 ) ;
return 0 ;
}
V_11 -> V_152 = F_37 ( V_159 -> V_141 , V_159 -> V_144 ) ;
if ( V_11 -> V_152 == - 1 ) {
F_2 ( & V_2 -> V_11 , L_14 ) ;
F_21 ( & V_11 -> V_105 ) ;
return - V_15 ;
}
V_24 = F_38 ( V_38 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_15 ) ;
goto V_6;
}
V_24 = F_14 ( V_2 , V_160 ,
& V_122 [ V_11 -> V_152 ] ) ;
if ( V_24 )
F_2 ( & V_2 -> V_11 , L_16 ) ;
V_6:
F_21 ( & V_11 -> V_105 ) ;
return V_24 ;
}
static int F_41 ( struct V_37 * V_38 ,
struct V_154 * V_155 ,
struct V_156 * V_157 )
{
struct V_158 * V_159 = & V_157 -> V_157 ;
struct V_47 * V_11 = F_16 ( V_38 ) ;
if ( V_157 -> V_161 )
return - V_15 ;
if ( ! V_159 )
return - V_15 ;
V_159 -> V_141 = V_122 [ V_11 -> V_152 ] . V_141 ;
V_159 -> V_144 = V_122 [ V_11 -> V_152 ] . V_144 ;
V_159 -> V_162 = V_163 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_167 * V_10 = V_2 -> V_10 ;
T_1 V_168 , V_169 ;
int V_24 ;
T_1 V_117 ;
if ( ! F_43 ( V_10 , V_170 ) )
return - V_13 ;
V_24 = F_1 ( V_2 , V_14 ,
V_171 , & V_168 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_17 , V_168 ) ;
return - V_13 ;
}
V_24 = F_1 ( V_2 , V_14 ,
V_172 , & V_169 ) ;
V_117 = ( ( V_168 << 8 ) | V_169 ) ;
if ( V_117 != V_173 ) {
F_2 ( & V_2 -> V_11 , L_18 , V_117 ) ;
return - V_13 ;
}
F_44 ( & V_2 -> V_11 , L_19 ) ;
return 0 ;
}
static int F_45 ( struct V_37 * V_38 , int V_174 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
int V_24 ;
F_20 ( & V_11 -> V_105 ) ;
if ( V_174 )
V_24 = F_9 ( V_2 , V_175 ) ;
else
V_24 = F_9 ( V_2 , V_176 ) ;
F_21 ( & V_11 -> V_105 ) ;
return V_24 ;
}
static int F_46 ( struct V_37 * V_38 ,
int V_177 , void * V_128 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
int V_24 = 0 ;
if ( ! V_128 )
return - V_13 ;
V_11 -> V_128 =
(struct V_178 * ) V_128 ;
F_20 ( & V_11 -> V_105 ) ;
if ( V_11 -> V_128 -> V_179 ) {
V_24 = V_11 -> V_128 -> V_179 ( V_2 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_20 ) ;
goto V_180;
}
}
V_24 = F_33 ( V_38 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_21 ) ;
goto V_181;
}
V_24 = F_32 ( V_38 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_22 ) ;
goto V_182;
}
V_24 = V_11 -> V_128 -> V_183 ( V_38 , 1 ) ;
if ( V_24 )
goto V_184;
V_24 = F_42 ( V_2 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_23 ) ;
goto V_184;
}
V_24 = F_33 ( V_38 ) ;
if ( V_24 ) {
F_2 ( & V_2 -> V_11 , L_21 ) ;
goto V_184;
}
F_21 ( & V_11 -> V_105 ) ;
return 0 ;
V_184:
V_11 -> V_128 -> V_183 ( V_38 , 0 ) ;
V_182:
F_33 ( V_38 ) ;
F_2 ( & V_2 -> V_11 , L_24 ) ;
V_181:
if ( V_11 -> V_128 -> V_185 )
V_11 -> V_128 -> V_185 () ;
V_180:
F_21 ( & V_11 -> V_105 ) ;
return V_24 ;
}
static int F_47 ( struct V_37 * V_38 ,
struct V_186 * V_187 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
if ( ! V_187 )
return - V_15 ;
if ( V_187 -> type != V_188 ) {
F_2 ( & V_2 -> V_11 , L_25 ) ;
return - V_15 ;
}
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
V_187 -> type = V_188 ;
if ( V_11 -> V_152 >= 0 && V_11 -> V_152 < V_124 ) {
V_187 -> V_189 . V_190 . V_191 = V_192 ;
V_187 -> V_189 . V_190 . V_193 . V_194 = 1 ;
V_187 -> V_189 . V_190 . V_195 = V_11 -> V_196 ;
V_187 -> V_189 . V_190 . V_193 . V_197 =
V_122 [ V_11 -> V_152 ] . V_198 ;
}
return 0 ;
}
static int F_48 ( struct V_37 * V_38 ,
struct V_186 * V_187 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
V_11 -> V_196 = V_187 -> V_189 . V_190 . V_195 ;
F_20 ( & V_11 -> V_105 ) ;
switch ( V_11 -> V_196 ) {
case V_199 :
V_122 = V_200 ;
V_124 = V_201 ;
break;
case V_202 :
V_122 = V_203 ;
V_124 = V_204 ;
break;
default:
V_122 = V_123 ;
V_124 = V_125 ;
}
F_21 ( & V_11 -> V_105 ) ;
return 0 ;
}
static int F_49 ( struct V_37 * V_38 ,
struct V_205 * V_206 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
V_206 -> V_206 . V_194 = 1 ;
V_206 -> V_206 . V_197 = V_122 [ V_11 -> V_152 ] . V_198 ;
return 0 ;
}
static int F_50 ( struct V_37 * V_38 ,
struct V_154 * V_155 ,
struct V_207 * V_162 )
{
if ( V_162 -> V_28 >= V_208 )
return - V_15 ;
V_162 -> V_162 = V_209 ;
return 0 ;
}
static int F_51 ( struct V_37 * V_38 ,
struct V_154 * V_155 ,
struct V_210 * V_211 )
{
int V_28 = V_211 -> V_28 ;
if ( V_28 >= V_124 )
return - V_15 ;
V_211 -> V_212 = V_122 [ V_28 ] . V_141 ;
V_211 -> V_213 = V_122 [ V_28 ] . V_144 ;
V_211 -> V_214 = V_122 [ V_28 ] . V_141 ;
V_211 -> V_215 = V_122 [ V_28 ] . V_144 ;
return 0 ;
}
static int F_52 ( struct V_37 * V_38 , T_3 * V_216 )
{
struct V_47 * V_11 = F_16 ( V_38 ) ;
F_20 ( & V_11 -> V_105 ) ;
* V_216 = V_122 [ V_11 -> V_152 ] . V_217 ;
F_21 ( & V_11 -> V_105 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_47 * V_11 = F_16 ( V_38 ) ;
F_54 ( & V_2 -> V_11 , L_26 ) ;
if ( V_11 -> V_128 -> V_185 )
V_11 -> V_128 -> V_185 () ;
V_11 -> V_128 -> V_183 ( V_38 , 0 ) ;
F_55 ( V_38 ) ;
F_56 ( & V_11 -> V_38 . V_218 ) ;
F_57 ( & V_11 -> V_116 ) ;
F_58 ( V_11 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_219 * V_117 )
{
struct V_47 * V_11 ;
void * V_220 ;
int V_24 ;
unsigned int V_146 ;
V_11 = F_60 ( sizeof( * V_11 ) , V_221 ) ;
if ( ! V_11 ) {
F_2 ( & V_2 -> V_11 , L_27 ) ;
return - V_222 ;
}
F_61 ( & V_11 -> V_105 ) ;
V_11 -> V_152 = 0 ;
F_62 ( & ( V_11 -> V_38 ) , V_2 , & V_223 ) ;
V_220 = V_2 -> V_11 . V_128 ;
if ( F_63 ( & V_2 -> V_11 ) )
V_220 = F_64 ( & V_11 -> V_38 ,
V_224 ,
V_225 ) ;
V_24 = F_46 ( & V_11 -> V_38 , V_2 -> V_177 , V_220 ) ;
if ( V_24 )
goto V_226;
V_11 -> V_38 . V_17 |= V_227 ;
V_11 -> V_161 . V_17 = V_228 ;
V_11 -> V_157 . V_162 = V_209 ;
V_11 -> V_38 . V_218 . V_229 = V_230 ;
V_24 =
F_65 ( & V_11 -> V_116 ,
F_66 ( V_231 ) ) ;
if ( V_24 ) {
F_53 ( V_2 ) ;
return V_24 ;
}
for ( V_146 = 0 ; V_146 < F_66 ( V_231 ) ; V_146 ++ )
F_67 ( & V_11 -> V_116 , & V_231 [ V_146 ] ,
NULL ) ;
if ( V_11 -> V_116 . error ) {
F_53 ( V_2 ) ;
return V_11 -> V_116 . error ;
}
V_11 -> V_116 . V_232 = & V_11 -> V_105 ;
V_11 -> V_38 . V_116 = & V_11 -> V_116 ;
V_24 = F_68 ( & V_11 -> V_38 . V_218 , 1 , & V_11 -> V_161 ) ;
if ( V_24 )
F_53 ( V_2 ) ;
if ( F_69 ( & V_2 -> V_11 ) )
V_24 = F_70 ( & V_11 -> V_38 , V_220 , V_233 ) ;
return V_24 ;
V_226:
F_55 ( & V_11 -> V_38 ) ;
F_58 ( V_11 ) ;
return V_24 ;
}
static int F_71 ( void )
{
return F_72 ( & V_234 ) ;
}
static void F_73 ( void )
{
F_74 ( & V_234 ) ;
}
