static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , const T_2 V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static T_3 F_5 ( struct V_5 * V_6 , unsigned int V_7 )
{
unsigned int V_8 ;
T_3 V_9 ;
V_8 = V_7 + 716 ;
V_9 = F_6 ( 1000000000ULL * V_8 , V_6 -> V_10 ) ;
F_7 ( F_8 ( V_6 ) , L_1 , V_9 ) ;
return V_9 ;
}
static int F_9 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
struct V_14 * V_15 = & V_6 -> V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
T_3 V_18 ;
if ( ! V_12 )
V_12 = & V_6 -> V_19 ;
V_18 = F_5 ( V_6 , V_15 -> V_7 ) ;
V_17 = F_6 ( 1000000000ULL * V_12 -> V_20 ,
( V_21 ) V_18 * V_12 -> V_22 )
- V_15 -> V_23 ;
if ( V_17 > V_24 ) {
V_12 -> V_22 = 1000 ;
V_12 -> V_20 =
F_6 ( ( V_15 -> V_23 + V_24 ) *
( V_21 ) V_18 * V_12 -> V_22 ,
1000000000ULL ) ;
V_17 = F_6 ( 1000000000ULL * V_12 -> V_20 ,
( V_21 ) V_18 * V_12 -> V_22 )
- V_15 -> V_23 ;
}
V_16 = 1600000 / V_18 ;
V_17 = F_11 (unsigned int, vblank, min_vblank, MT9M032_VBLANK_MAX) ;
return F_3 ( V_2 , V_25 , V_17 ) ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_26 ;
V_26 = F_3 ( V_2 , V_27 ,
V_6 -> V_15 . V_7 - 1 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_28 ,
V_6 -> V_15 . V_23 - 1 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_29 ,
V_6 -> V_15 . V_30 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_31 ,
V_6 -> V_15 . V_32 ) ;
if ( ! V_26 )
V_26 = F_9 ( V_6 , NULL ) ;
return V_26 ;
}
static int F_13 ( struct V_5 * V_6 , bool V_33 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
T_2 V_34 = V_35
| 0x0070 ;
if ( V_33 )
V_34 |= V_36 ;
return F_3 ( V_2 , V_37 , V_34 ) ;
}
static int F_14 ( struct V_5 * V_6 )
{
static const struct V_38 V_39 = {
. V_40 = 8000000 ,
. V_41 = 16500000 ,
. V_42 = 2000000 ,
. V_43 = 24000000 ,
. V_44 = 322000000 ,
. V_45 = 693000000 ,
. V_46 = 99000000 ,
. V_47 = 1 ,
. V_48 = 64 ,
. V_49 = 16 ,
. V_50 = 255 ,
. V_51 = 1 ,
. V_52 = 128 ,
} ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
struct V_53 * V_54 = V_6 -> V_54 ;
struct V_55 V_56 ;
int V_26 ;
V_56 . V_57 = V_54 -> V_57 ;
V_56 . V_10 = V_54 -> V_10 ;
V_26 = F_15 ( & V_2 -> V_58 , & V_39 , & V_56 ) ;
if ( V_26 < 0 )
return V_26 ;
V_6 -> V_10 = V_54 -> V_10 ;
V_26 = F_3 ( V_2 , V_59 ,
( V_56 . V_60 << V_61 )
| ( V_56 . V_62 - 1 ) ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_63 , V_56 . V_64 - 1 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_65 ,
V_66 |
V_67 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_68 , 0x8006 ) ;
if ( ! V_26 )
V_26 = F_3 ( V_2 , V_69 , 0x111e ) ;
return V_26 ;
}
static int F_16 ( struct V_70 * V_13 ,
struct V_71 * V_72 ,
struct V_73 * V_74 )
{
if ( V_74 -> V_75 != 0 )
return - V_76 ;
V_74 -> V_74 = V_77 ;
return 0 ;
}
static int F_17 ( struct V_70 * V_13 ,
struct V_71 * V_72 ,
struct V_78 * V_79 )
{
if ( V_79 -> V_75 != 0 || V_79 -> V_74 != V_77 )
return - V_76 ;
V_79 -> V_80 = V_81 ;
V_79 -> V_82 = V_81 ;
V_79 -> V_83 = V_84 ;
V_79 -> V_85 = V_84 ;
return 0 ;
}
static struct V_14 *
F_18 ( struct V_5 * V_6 , struct V_71 * V_72 ,
enum V_86 V_87 )
{
switch ( V_87 ) {
case V_88 :
return F_19 ( V_72 , 0 ) ;
case V_89 :
return & V_6 -> V_15 ;
default:
return NULL ;
}
}
static struct V_90 *
F_20 ( struct V_5 * V_6 , struct V_71 * V_72 ,
enum V_86 V_87 )
{
switch ( V_87 ) {
case V_88 :
return F_21 ( V_72 , 0 ) ;
case V_89 :
return & V_6 -> V_91 ;
default:
return NULL ;
}
}
static int F_22 ( struct V_70 * V_13 ,
struct V_71 * V_72 ,
struct V_92 * V_93 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_24 ( & V_6 -> V_94 ) ;
V_93 -> V_91 = * F_20 ( V_6 , V_72 , V_93 -> V_87 ) ;
F_25 ( & V_6 -> V_94 ) ;
return 0 ;
}
static int F_26 ( struct V_70 * V_13 ,
struct V_71 * V_72 ,
struct V_92 * V_93 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
int V_26 ;
F_24 ( & V_6 -> V_94 ) ;
if ( V_6 -> V_33 && V_93 -> V_87 == V_89 ) {
V_26 = - V_95 ;
goto V_96;
}
V_93 -> V_91 = * F_20 ( V_6 , V_72 , V_93 -> V_87 ) ;
V_26 = 0 ;
V_96:
F_25 ( & V_6 -> V_94 ) ;
return V_26 ;
}
static int F_27 ( struct V_70 * V_13 ,
struct V_71 * V_72 ,
struct V_97 * V_15 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_24 ( & V_6 -> V_94 ) ;
V_15 -> V_98 = * F_18 ( V_6 , V_72 , V_15 -> V_87 ) ;
F_25 ( & V_6 -> V_94 ) ;
return 0 ;
}
static int F_28 ( struct V_70 * V_13 ,
struct V_71 * V_72 ,
struct V_97 * V_15 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
struct V_90 * V_91 ;
struct V_14 * V_99 ;
struct V_14 V_98 ;
int V_26 = 0 ;
F_24 ( & V_6 -> V_94 ) ;
if ( V_6 -> V_33 && V_15 -> V_87 == V_89 ) {
V_26 = - V_95 ;
goto V_96;
}
V_98 . V_30 = F_29 ( F_30 ( V_15 -> V_98 . V_30 , 2 ) , V_100 ,
V_101 ) ;
V_98 . V_32 = F_29 ( F_30 ( V_15 -> V_98 . V_32 , 2 ) , V_102 ,
V_103 ) ;
V_98 . V_7 = F_29 ( F_30 ( V_15 -> V_98 . V_7 , 2 ) , V_104 ,
V_105 ) ;
V_98 . V_23 = F_29 ( F_30 ( V_15 -> V_98 . V_23 , 2 ) , V_106 ,
V_107 ) ;
V_98 . V_7 = F_31 ( V_98 . V_7 , V_108 - V_98 . V_30 ) ;
V_98 . V_23 = F_31 ( V_98 . V_23 , V_109 - V_98 . V_32 ) ;
V_99 = F_18 ( V_6 , V_72 , V_15 -> V_87 ) ;
if ( V_98 . V_7 != V_99 -> V_7 || V_98 . V_23 != V_99 -> V_23 ) {
V_91 = F_20 ( V_6 , V_72 , V_15 -> V_87 ) ;
V_91 -> V_7 = V_98 . V_7 ;
V_91 -> V_23 = V_98 . V_23 ;
}
* V_99 = V_98 ;
V_15 -> V_98 = V_98 ;
if ( V_15 -> V_87 == V_89 )
V_26 = F_12 ( V_6 ) ;
V_96:
F_25 ( & V_6 -> V_94 ) ;
return V_26 ;
}
static int F_32 ( struct V_70 * V_13 ,
struct V_110 * V_111 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_24 ( & V_6 -> V_94 ) ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_12 = V_6 -> V_19 ;
F_25 ( & V_6 -> V_94 ) ;
return 0 ;
}
static int F_33 ( struct V_70 * V_13 ,
struct V_110 * V_111 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
int V_26 ;
F_24 ( & V_6 -> V_94 ) ;
if ( V_6 -> V_33 ) {
V_26 = - V_95 ;
goto V_96;
}
if ( V_111 -> V_12 . V_22 == 0 )
V_111 -> V_12 . V_22 = 1 ;
V_26 = F_9 ( V_6 , & V_111 -> V_12 ) ;
if ( ! V_26 )
V_6 -> V_19 = V_111 -> V_12 ;
V_96:
F_25 ( & V_6 -> V_94 ) ;
return V_26 ;
}
static int F_34 ( struct V_70 * V_13 , int V_33 )
{
struct V_5 * V_6 = F_23 ( V_13 ) ;
int V_26 ;
F_24 ( & V_6 -> V_94 ) ;
V_26 = F_13 ( V_6 , V_33 ) ;
if ( ! V_26 )
V_6 -> V_33 = V_33 ;
F_25 ( & V_6 -> V_94 ) ;
return V_26 ;
}
static int F_35 ( struct V_70 * V_112 ,
struct V_113 * V_3 )
{
struct V_5 * V_6 = F_23 ( V_112 ) ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_114 ;
if ( V_3 -> V_115 . type != V_116 || V_3 -> V_3 > 0xff )
return - V_76 ;
if ( V_3 -> V_115 . V_117 != V_2 -> V_117 )
return - V_118 ;
V_114 = F_1 ( V_2 , V_3 -> V_3 ) ;
if ( V_114 < 0 )
return - V_119 ;
V_3 -> V_120 = 2 ;
V_3 -> V_114 = V_114 ;
return 0 ;
}
static int F_36 ( struct V_70 * V_112 ,
struct V_113 * V_3 )
{
struct V_5 * V_6 = F_23 ( V_112 ) ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
if ( V_3 -> V_115 . type != V_116 || V_3 -> V_3 > 0xff )
return - V_76 ;
if ( V_3 -> V_115 . V_117 != V_2 -> V_117 )
return - V_118 ;
return F_3 ( V_2 , V_3 -> V_3 , V_3 -> V_114 ) ;
}
static int F_37 ( struct V_5 * V_6 , bool V_121 , bool V_122 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_34 = ( V_121 << V_123 )
| ( V_122 << V_124 )
| V_125
| 0x0007 ;
return F_3 ( V_2 , V_126 , V_34 ) ;
}
static int F_38 ( struct V_5 * V_6 , T_4 V_114 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_127 ;
int V_128 ;
int V_129 ;
T_2 V_34 ;
V_127 = 51 ;
if ( V_114 < 63 ) {
V_128 = 0 ;
V_129 = V_114 ;
} else {
V_128 = 1 ;
V_129 = V_114 / 2 ;
}
V_34 = ( ( V_127 & V_130 )
<< V_131 )
| ( ( V_128 & 1 ) << V_132 )
| ( V_129 & V_133 ) ;
return F_3 ( V_2 , V_134 , V_34 ) ;
}
static int F_39 ( struct V_135 * V_136 )
{
if ( V_136 -> V_137 == V_138 && V_136 -> V_114 >= 63 ) {
V_136 -> V_114 &= ~ 1 ;
}
return 0 ;
}
static int F_40 ( struct V_135 * V_136 )
{
struct V_5 * V_6 =
F_41 ( V_136 -> V_139 , struct V_5 , V_140 ) ;
struct V_1 * V_2 = F_10 ( & V_6 -> V_13 ) ;
int V_26 ;
switch ( V_136 -> V_137 ) {
case V_138 :
return F_38 ( V_6 , V_136 -> V_114 ) ;
case V_141 :
return F_37 ( V_6 , V_6 -> V_121 -> V_114 ,
V_6 -> V_122 -> V_114 ) ;
case V_142 :
V_26 = F_3 ( V_2 , V_143 ,
( V_136 -> V_114 >> 16 ) & 0xffff ) ;
if ( V_26 < 0 )
return V_26 ;
return F_3 ( V_2 , V_144 ,
V_136 -> V_114 & 0xffff ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_145 * V_146 )
{
struct V_147 * V_148 = V_2 -> V_148 ;
struct V_5 * V_6 ;
int V_149 ;
int V_26 ;
if ( ! F_43 ( V_148 , V_150 ) ) {
F_44 ( & V_2 -> V_58 ,
L_2 ) ;
return - V_119 ;
}
if ( ! V_2 -> V_58 . V_151 )
return - V_118 ;
V_6 = F_45 ( sizeof( * V_6 ) , V_152 ) ;
if ( V_6 == NULL )
return - V_153 ;
F_46 ( & V_6 -> V_94 ) ;
V_6 -> V_54 = V_2 -> V_58 . V_151 ;
F_47 ( & V_6 -> V_13 , V_2 , & V_154 ) ;
V_6 -> V_13 . V_155 |= V_156 ;
V_149 = F_1 ( V_2 , V_157 ) ;
if ( V_149 != V_158 ) {
F_48 ( & V_2 -> V_58 , L_3
L_4 , V_149 ) ;
V_26 = - V_118 ;
goto V_159;
}
F_49 ( & V_2 -> V_58 , L_5 ,
V_2 -> V_117 ) ;
V_6 -> V_19 . V_20 = 1 ;
V_6 -> V_19 . V_22 = 30 ;
V_6 -> V_15 . V_30 = V_160 ;
V_6 -> V_15 . V_32 = V_161 ;
V_6 -> V_15 . V_7 = V_81 ;
V_6 -> V_15 . V_23 = V_84 ;
V_6 -> V_91 . V_7 = V_6 -> V_15 . V_7 ;
V_6 -> V_91 . V_23 = V_6 -> V_15 . V_23 ;
V_6 -> V_91 . V_74 = V_77 ;
V_6 -> V_91 . V_162 = V_163 ;
V_6 -> V_91 . V_164 = V_165 ;
F_50 ( & V_6 -> V_140 , 4 ) ;
F_51 ( & V_6 -> V_140 , & V_166 ,
V_138 , 0 , 127 , 1 , 64 ) ;
V_6 -> V_122 = F_51 ( & V_6 -> V_140 ,
& V_166 ,
V_141 , 0 , 1 , 1 , 0 ) ;
V_6 -> V_121 = F_51 ( & V_6 -> V_140 ,
& V_166 ,
V_167 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_6 -> V_140 , & V_166 ,
V_142 , V_168 ,
V_169 , 1 ,
V_170 ) ;
if ( V_6 -> V_140 . error ) {
V_26 = V_6 -> V_140 . error ;
F_48 ( & V_2 -> V_58 , L_6 , V_26 ) ;
goto V_171;
}
F_52 ( 2 , & V_6 -> V_122 ) ;
V_6 -> V_13 . V_172 = & V_6 -> V_140 ;
V_6 -> V_173 . V_155 = V_174 ;
V_26 = F_53 ( & V_6 -> V_13 . V_175 , 1 , & V_6 -> V_173 , 0 ) ;
if ( V_26 < 0 )
goto V_171;
V_26 = F_3 ( V_2 , V_176 , 1 ) ;
if ( V_26 < 0 )
goto V_177;
F_3 ( V_2 , V_176 , 0 ) ;
if ( V_26 < 0 )
goto V_177;
V_26 = F_14 ( V_6 ) ;
if ( V_26 < 0 )
goto V_177;
F_54 ( 10000 , 11000 ) ;
V_26 = F_55 ( & V_6 -> V_140 ) ;
if ( V_26 < 0 )
goto V_177;
V_26 = F_12 ( V_6 ) ;
if ( V_26 < 0 )
goto V_177;
V_26 = F_3 ( V_2 , 0x41 , 0x0000 ) ;
if ( V_26 < 0 )
goto V_177;
V_26 = F_3 ( V_2 , 0x42 , 0x0003 ) ;
if ( V_26 < 0 )
goto V_177;
V_26 = F_3 ( V_2 , 0x43 , 0x0003 ) ;
if ( V_26 < 0 )
goto V_177;
V_26 = F_3 ( V_2 , 0x7f , 0x0000 ) ;
if ( V_26 < 0 )
goto V_177;
if ( V_6 -> V_54 -> V_178 ) {
V_26 = F_3 ( V_2 , V_179 ,
V_180 ) ;
if ( V_26 < 0 )
goto V_177;
}
V_26 = F_3 ( V_2 , V_181 , 1 ) ;
if ( V_26 < 0 )
goto V_177;
F_56 ( 100 ) ;
V_26 = F_3 ( V_2 , V_181 , 0 ) ;
if ( V_26 < 0 )
goto V_177;
F_56 ( 100 ) ;
V_26 = F_13 ( V_6 , false ) ;
if ( V_26 < 0 )
goto V_177;
return V_26 ;
V_177:
F_57 ( & V_6 -> V_13 . V_175 ) ;
V_171:
F_58 ( & V_6 -> V_140 ) ;
V_159:
F_59 ( & V_6 -> V_94 ) ;
F_60 ( V_6 ) ;
return V_26 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_70 * V_13 = F_62 ( V_2 ) ;
struct V_5 * V_6 = F_23 ( V_13 ) ;
F_63 ( & V_6 -> V_13 ) ;
F_58 ( & V_6 -> V_140 ) ;
F_57 ( & V_6 -> V_13 . V_175 ) ;
F_59 ( & V_6 -> V_94 ) ;
F_60 ( V_6 ) ;
return 0 ;
}
