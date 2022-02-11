static const struct V_1 * F_1 (
enum V_2 V_3 , const struct V_1 * V_4 ,
int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( V_4 [ V_6 ] . V_3 == V_3 )
return V_4 + V_6 ;
return NULL ;
}
static struct V_7 * F_2 ( const struct V_8 * V_9 )
{
return F_3 ( F_4 ( V_9 ) , struct V_7 , V_10 ) ;
}
static int F_5 ( struct V_8 * V_9 , const T_1 V_11 )
{
int V_12 ;
T_1 V_13 ;
static int V_14 = - 1 ;
V_13 = ( V_11 >> 8 ) ;
if ( V_13 == V_14 )
return 0 ;
if ( V_13 > 2 )
return - V_15 ;
V_12 = F_6 ( V_9 , V_16 , F_7 ( V_13 ) ) ;
if ( ! V_12 )
V_14 = V_13 ;
return V_12 ;
}
static int F_8 ( struct V_8 * V_9 , const T_1 V_11 )
{
int V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( ! V_12 )
V_12 = F_7 ( F_9 ( V_9 , V_11 & 0xff ) ) ;
F_10 ( & V_9 -> V_17 , L_1 , V_11 , V_12 ) ;
return V_12 ;
}
static int F_11 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( ! V_12 )
V_12 = F_6 ( V_9 , V_11 & 0xff ,
F_7 ( V_18 ) ) ;
F_10 ( & V_9 -> V_17 , L_2 , V_11 , V_18 , V_12 ) ;
return V_12 ;
}
static int F_12 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_9 , V_11 , V_12 | V_18 ) ;
return V_12 ;
}
static int F_13 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_9 , V_11 , V_12 & ~ V_18 ) ;
return V_12 ;
}
static int F_14 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 , const T_1 V_19 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_9 , V_11 , ( V_12 & ~ V_19 ) | V_18 ) ;
return V_12 ;
}
static int F_15 ( struct V_7 * V_7 ,
enum V_20 V_21 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_22 = V_23 | V_24
| V_25 | V_26
| V_27 | V_28
| V_29
| V_30 ;
int V_31 = V_23 ;
if ( V_21 == V_32 )
return F_17 ( V_33 , V_22 ) ;
else
return F_17 ( V_33 , V_31 ) ;
}
static int F_18 ( struct V_7 * V_7 ,
struct V_34 * V_35 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 , V_36 ;
int V_37 = V_35 -> V_37 ;
int V_38 = V_35 -> V_38 ;
if ( V_7 -> V_4 -> V_3 == V_39 ||
V_7 -> V_4 -> V_3 == V_40 )
V_36 = 1 ;
else
V_36 = 0 ;
V_12 = F_17 ( V_41 , V_35 -> V_42 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_43 , V_35 -> V_44 ) ;
if ( V_36 ) {
if ( ! V_12 )
V_12 = F_17 ( V_45 , V_37 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_46 , V_38 ) ;
} else {
if ( ! V_12 )
V_12 = F_17 ( V_47 , V_48 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_49 , V_50 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_51 , V_37 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_52 , V_38 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_53 , V_48 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_54 , V_50 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_55 , V_37 ) ;
if ( ! V_12 )
V_12 = F_17 ( V_56 , V_38 ) ;
}
return V_12 ;
}
static int F_19 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
V_12 = F_20 ( V_57 , V_58 ) ;
if ( ! V_12 )
V_7 -> V_59 = 1 ;
return V_12 ;
}
static int F_21 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
V_12 = F_20 ( V_57 , V_60 ) ;
if ( ! V_12 )
V_12 = F_20 ( V_57 , V_61 ) ;
if ( ! V_12 )
V_12 = F_22 ( V_57 , V_60
| V_61 ) ;
return V_12 ;
}
static unsigned long F_23 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_24 ( V_63 ) ;
unsigned long V_66 = V_67 | V_68 |
V_69 | V_70 |
V_71 | V_72 ;
return F_25 ( V_65 , V_66 ) ;
}
static int F_26 ( struct V_62 * V_63 , unsigned long V_73 )
{
return 0 ;
}
static int F_27 ( struct V_7 * V_7 ,
struct V_34 * V_35 )
{
if ( V_7 -> V_4 -> V_3 == V_39 ||
V_7 -> V_4 -> V_3 == V_40 ) {
V_35 -> V_37 = F_28 ( V_35 -> V_37 , 2 ) ;
V_35 -> V_38 = F_28 ( V_35 -> V_38 , 2 ) ;
}
F_29 ( & V_35 -> V_42 , & V_35 -> V_37 ,
V_74 , 2 , V_48 ) ;
F_29 ( & V_35 -> V_44 , & V_35 -> V_38 ,
V_75 , 2 , V_50 ) ;
return F_18 ( V_7 , V_35 ) ;
}
static int F_30 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
struct V_34 V_35 = V_79 -> V_80 ;
struct V_8 * V_9 = F_16 ( V_77 ) ;
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
int V_12 ;
F_10 ( & V_9 -> V_17 , L_3 ,
V_81 , V_35 . V_42 , V_35 . V_44 , V_35 . V_37 , V_35 . V_38 ) ;
if ( V_79 -> type != V_82 )
return - V_15 ;
V_12 = F_27 ( V_7 , & V_35 ) ;
if ( ! V_12 )
V_7 -> V_35 = V_35 ;
return V_12 ;
}
static int F_31 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
V_79 -> V_80 = V_7 -> V_35 ;
V_79 -> type = V_82 ;
return 0 ;
}
static int F_32 ( struct V_76 * V_77 , struct V_83 * V_79 )
{
if ( V_79 -> type != V_82 )
return - V_15 ;
V_79 -> V_84 . V_42 = V_74 ;
V_79 -> V_84 . V_44 = V_75 ;
V_79 -> V_84 . V_37 = V_48 ;
V_79 -> V_84 . V_38 = V_50 ;
V_79 -> V_85 = V_79 -> V_84 ;
V_79 -> V_86 . V_87 = 1 ;
V_79 -> V_86 . V_88 = 1 ;
return 0 ;
}
static int F_33 ( struct V_76 * V_77 ,
struct V_89 * V_90 )
{
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
V_90 -> V_37 = V_7 -> V_35 . V_37 ;
V_90 -> V_38 = V_7 -> V_35 . V_38 ;
V_90 -> V_3 = V_7 -> V_4 -> V_3 ;
V_90 -> V_91 = V_7 -> V_4 -> V_91 ;
V_90 -> V_92 = V_93 ;
return 0 ;
}
static int F_34 ( struct V_7 * V_7 ,
enum V_2 V_3 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
T_1 V_94 , V_95 = V_96 |
V_97 | V_98 |
V_99 | V_100 |
V_101 | V_102 |
V_103 |
V_104 ;
int V_12 ;
switch ( V_3 ) {
case V_39 :
V_94 = V_96 |
V_98 ;
break;
case V_40 :
V_94 = V_97 | V_98 ;
break;
case V_105 :
V_94 = V_98 | V_100 |
V_103 ;
break;
case V_106 :
V_94 = V_98 | V_100 ;
break;
case V_107 :
V_94 = V_98 | V_99 |
V_103 ;
break;
case V_108 :
V_94 = V_98 | V_99 ;
break;
case V_109 :
V_94 = V_98 | V_99 |
V_104 ;
break;
case V_110 :
V_94 = V_98 | V_99 |
V_103 |
V_104 ;
break;
case V_111 :
V_94 = 0 ;
break;
case V_112 :
V_94 = V_104 ;
break;
case V_113 :
V_94 = V_103 ;
break;
case V_114 :
V_94 = V_103 |
V_104 ;
break;
default:
F_35 ( & V_9 -> V_17 , L_4 , V_3 ) ;
return - V_15 ;
}
V_12 = F_36 ( V_115 , V_94 ,
V_95 ) ;
if ( ! V_12 )
V_12 = F_36 ( V_116 , V_94 ,
V_95 ) ;
return V_12 ;
}
static int F_37 ( struct V_76 * V_77 ,
struct V_89 * V_90 )
{
struct V_8 * V_9 = F_16 ( V_77 ) ;
const struct V_1 * V_4 ;
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
struct V_34 V_35 = {
. V_42 = V_7 -> V_35 . V_42 ,
. V_44 = V_7 -> V_35 . V_44 ,
. V_37 = V_90 -> V_37 ,
. V_38 = V_90 -> V_38 ,
} ;
int V_12 ;
V_4 = F_1 ( V_90 -> V_3 , V_117 ,
F_38 ( V_117 ) ) ;
if ( ! V_4 )
return - V_15 ;
F_10 ( & V_9 -> V_17 ,
L_5 , V_81 ,
V_90 -> V_3 , V_35 . V_42 , V_35 . V_44 , V_35 . V_37 , V_35 . V_38 ) ;
V_12 = F_27 ( V_7 , & V_35 ) ;
if ( ! V_12 )
V_12 = F_34 ( V_7 , V_90 -> V_3 ) ;
if ( ! V_12 ) {
V_7 -> V_35 = V_35 ;
V_7 -> V_4 = V_4 ;
V_90 -> V_91 = V_4 -> V_91 ;
}
return V_12 ;
}
static int F_39 ( struct V_76 * V_77 ,
struct V_89 * V_90 )
{
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
const struct V_1 * V_4 ;
bool V_118 = V_90 -> V_3 == V_39 ||
V_90 -> V_3 == V_40 ;
V_4 = F_1 ( V_90 -> V_3 , V_117 ,
F_38 ( V_117 ) ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_90 -> V_3 = V_4 -> V_3 ;
}
if ( V_90 -> V_38 > V_50 )
V_90 -> V_38 = V_50 ;
else if ( V_90 -> V_38 < 2 )
V_90 -> V_38 = 2 ;
else if ( V_118 )
V_90 -> V_38 = F_28 ( V_90 -> V_38 , 2 ) ;
if ( V_90 -> V_37 > V_48 )
V_90 -> V_37 = V_48 ;
else if ( V_90 -> V_37 < 2 )
V_90 -> V_37 = 2 ;
else if ( V_118 )
V_90 -> V_37 = F_28 ( V_90 -> V_37 , 2 ) ;
V_90 -> V_91 = V_4 -> V_91 ;
return 0 ;
}
static int F_40 ( struct V_76 * V_77 ,
struct V_119 * V_120 )
{
struct V_8 * V_9 = F_16 ( V_77 ) ;
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
if ( V_120 -> V_121 . type != V_122 )
return - V_15 ;
if ( V_120 -> V_121 . V_123 != V_9 -> V_123 )
return - V_124 ;
V_120 -> V_125 = V_7 -> V_126 ;
V_120 -> V_127 = 0 ;
return 0 ;
}
static int F_41 ( struct V_76 * V_77 ,
struct V_128 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_77 ) ;
int V_129 ;
if ( V_11 -> V_121 . type != V_122 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_121 . V_123 != V_9 -> V_123 )
return - V_124 ;
V_129 = F_8 ( V_9 , V_11 -> V_11 ) ;
V_11 -> V_130 = 2 ;
V_11 -> V_129 = ( V_131 ) V_129 ;
if ( V_11 -> V_129 > 0xffff )
return - V_132 ;
return 0 ;
}
static int F_42 ( struct V_76 * V_77 ,
struct V_128 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_77 ) ;
if ( V_11 -> V_121 . type != V_122 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_121 . V_123 != V_9 -> V_123 )
return - V_124 ;
if ( F_11 ( V_9 , V_11 -> V_11 , V_11 -> V_129 ) < 0 )
return - V_132 ;
return 0 ;
}
static int F_43 ( struct V_7 * V_7 , int V_133 , int V_19 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
if ( V_7 -> V_134 == V_32 ) {
if ( V_133 )
V_12 = F_20 ( V_135 , V_19 ) ;
else
V_12 = F_22 ( V_135 , V_19 ) ;
} else {
if ( V_133 )
V_12 = F_20 ( V_136 , V_19 ) ;
else
V_12 = F_22 ( V_136 , V_19 ) ;
}
return V_12 ;
}
static int F_44 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_18 ;
V_18 = F_45 ( V_137 ) ;
if ( V_18 >= 0 )
return ( V_18 & 0x2f ) * ( 1 << ( ( V_18 >> 10 ) & 1 ) ) *
( 1 << ( ( V_18 >> 9 ) & 1 ) ) ;
return V_18 ;
}
static int F_46 ( struct V_7 * V_7 , int V_138 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
T_1 V_129 ;
if ( V_138 > 63 * 2 * 2 )
return - V_15 ;
V_7 -> V_138 = V_138 ;
if ( ( V_138 >= 64 * 2 ) && ( V_138 < 63 * 2 * 2 ) )
V_129 = ( 1 << 10 ) | ( 1 << 9 ) | ( V_138 / 4 ) ;
else if ( ( V_138 >= 64 ) && ( V_138 < 64 * 2 ) )
V_129 = ( 1 << 9 ) | ( V_138 / 2 ) ;
else
V_129 = V_138 ;
return F_17 ( V_137 , V_129 ) ;
}
static int F_47 ( struct V_7 * V_7 , int V_139 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
if ( V_139 )
V_12 = F_20 ( V_140 , V_141 ) ;
else
V_12 = F_22 ( V_140 , V_141 ) ;
if ( ! V_12 )
V_7 -> V_142 = V_139 ;
return V_12 ;
}
static int F_48 ( struct V_7 * V_7 , int V_139 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
if ( V_139 )
V_12 = F_20 ( V_140 , V_143 ) ;
else
V_12 = F_22 ( V_140 , V_143 ) ;
if ( ! V_12 )
V_7 -> V_144 = V_139 ;
return V_12 ;
}
static int F_49 ( struct V_76 * V_77 , struct V_145 * V_146 )
{
struct V_8 * V_9 = F_16 ( V_77 ) ;
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
int V_18 ;
switch ( V_146 -> V_120 ) {
case V_147 :
if ( V_7 -> V_134 == V_32 )
V_18 = F_45 ( V_135 ) ;
else
V_18 = F_45 ( V_136 ) ;
if ( V_18 < 0 )
return - V_132 ;
V_146 -> V_148 = ! ! ( V_18 & V_149 ) ;
break;
case V_150 :
if ( V_7 -> V_134 == V_32 )
V_18 = F_45 ( V_135 ) ;
else
V_18 = F_45 ( V_136 ) ;
if ( V_18 < 0 )
return - V_132 ;
V_146 -> V_148 = ! ! ( V_18 & V_151 ) ;
break;
case V_152 :
V_18 = F_44 ( V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
V_146 -> V_148 = V_18 ;
break;
case V_153 :
V_146 -> V_148 = V_7 -> V_142 ;
break;
case V_154 :
V_146 -> V_148 = V_7 -> V_144 ;
break;
}
return 0 ;
}
static int F_50 ( struct V_76 * V_77 , struct V_145 * V_146 )
{
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
const struct V_155 * V_156 ;
int V_12 ;
V_156 = F_51 ( & V_157 , V_146 -> V_120 ) ;
if ( ! V_156 )
return - V_15 ;
switch ( V_146 -> V_120 ) {
case V_147 :
V_7 -> V_158 = V_146 -> V_148 ;
V_12 = F_43 ( V_7 , V_146 -> V_148 ,
V_149 ) ;
break;
case V_150 :
V_7 -> V_159 = V_146 -> V_148 ;
V_12 = F_43 ( V_7 , V_146 -> V_148 ,
V_151 ) ;
break;
case V_152 :
V_12 = F_46 ( V_7 , V_146 -> V_148 ) ;
break;
case V_153 :
V_12 = F_47 ( V_7 , V_146 -> V_148 ) ;
break;
case V_154 :
V_12 = F_48 ( V_7 , V_146 -> V_148 ) ;
break;
default:
V_12 = - V_15 ;
}
return V_12 ;
}
static int F_52 ( struct V_7 * V_7 )
{
V_7 -> V_138 = F_44 ( V_7 ) ;
return 0 ;
}
static void F_53 ( struct V_7 * V_7 )
{
F_15 ( V_7 , V_7 -> V_134 ) ;
F_34 ( V_7 , V_7 -> V_4 -> V_3 ) ;
F_18 ( V_7 , & V_7 -> V_35 ) ;
F_43 ( V_7 , V_7 -> V_159 , V_151 ) ;
F_43 ( V_7 , V_7 -> V_158 , V_149 ) ;
F_46 ( V_7 , V_7 -> V_138 ) ;
F_47 ( V_7 , V_7 -> V_142 ) ;
F_48 ( V_7 , V_7 -> V_144 ) ;
}
static int F_54 ( struct V_7 * V_7 )
{
int V_12 = 0 ;
if ( V_7 -> V_59 ) {
V_12 = F_19 ( V_7 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_7 ) ;
if ( ! V_12 )
F_53 ( V_7 ) ;
}
return V_12 ;
}
static int F_55 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
V_7 -> V_134 = V_32 ;
V_12 = F_19 ( V_7 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_7 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_7 , V_7 -> V_134 ) ;
if ( ! V_12 )
V_12 = F_47 ( V_7 , V_7 -> V_142 ) ;
if ( V_12 )
F_35 ( & V_9 -> V_17 , L_6 , V_12 ) ;
return V_12 ;
}
static int F_56 ( struct V_62 * V_63 ,
struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
T_2 V_18 ;
int V_12 ;
F_57 ( ! V_63 -> V_160 ||
F_58 ( V_63 -> V_160 ) -> V_161 != V_63 -> V_162 ) ;
V_7 -> V_142 = 1 ;
V_7 -> V_144 = 1 ;
V_18 = F_45 ( V_163 ) ;
switch ( V_18 ) {
case 0x143a :
V_7 -> V_126 = V_164 ;
F_59 ( & V_9 -> V_17 ,
L_7 , V_18 ) ;
break;
case 0x148c :
V_7 -> V_126 = V_165 ;
F_59 ( & V_9 -> V_17 , L_8 , V_18 ) ;
break;
default:
V_12 = - V_124 ;
F_35 ( & V_9 -> V_17 ,
L_9 ,
V_18 ) ;
goto V_166;
}
V_12 = F_55 ( V_7 ) ;
V_166:
return V_12 ;
}
static int F_60 ( struct V_76 * V_77 , int V_139 )
{
struct V_7 * V_7 = F_3 ( V_77 , struct V_7 , V_10 ) ;
struct V_8 * V_9 = F_16 ( V_77 ) ;
int V_12 = 0 ;
F_61 ( & V_7 -> V_167 ) ;
if ( V_7 -> V_168 == ! V_139 ) {
if ( V_139 ) {
V_12 = F_54 ( V_7 ) ;
if ( V_12 ) {
F_35 ( & V_9 -> V_17 ,
L_10 , V_12 ) ;
goto V_169;
}
} else {
F_52 ( V_7 ) ;
}
}
V_7 -> V_168 += V_139 ? 1 : - 1 ;
F_62 ( V_7 -> V_168 < 0 ) ;
V_169:
F_63 ( & V_7 -> V_167 ) ;
return V_12 ;
}
static int F_64 ( struct V_76 * V_77 , unsigned int V_170 ,
enum V_2 * V_3 )
{
if ( V_170 >= F_38 ( V_117 ) )
return - V_15 ;
* V_3 = V_117 [ V_170 ] . V_3 ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 ,
const struct V_171 * V_172 )
{
struct V_7 * V_7 ;
struct V_62 * V_63 = V_9 -> V_17 . V_173 ;
struct V_174 * V_175 = F_66 ( V_9 -> V_17 . V_160 ) ;
struct V_64 * V_65 ;
int V_12 ;
if ( ! V_63 ) {
F_35 ( & V_9 -> V_17 , L_11 ) ;
return - V_15 ;
}
V_65 = F_24 ( V_63 ) ;
if ( ! V_65 ) {
F_35 ( & V_9 -> V_17 , L_12 ) ;
return - V_15 ;
}
if ( ! F_67 ( V_175 , V_176 ) ) {
F_68 ( & V_175 -> V_17 ,
L_13 ) ;
return - V_132 ;
}
V_7 = F_69 ( sizeof( struct V_7 ) , V_177 ) ;
if ( ! V_7 )
return - V_178 ;
F_70 ( & V_7 -> V_10 , V_9 , & V_179 ) ;
V_63 -> V_180 = & V_157 ;
V_7 -> V_35 . V_42 = V_74 ;
V_7 -> V_35 . V_44 = V_75 ;
V_7 -> V_35 . V_37 = V_48 ;
V_7 -> V_35 . V_38 = V_50 ;
V_7 -> V_4 = & V_117 [ 0 ] ;
V_12 = F_56 ( V_63 , V_9 ) ;
if ( V_12 ) {
V_63 -> V_180 = NULL ;
F_71 ( V_7 ) ;
}
return V_12 ;
}
static int F_72 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_62 * V_63 = V_9 -> V_17 . V_173 ;
V_63 -> V_180 = NULL ;
F_71 ( V_7 ) ;
return 0 ;
}
static int T_3 F_73 ( void )
{
return F_74 ( & V_181 ) ;
}
static void T_4 F_75 ( void )
{
F_76 ( & V_181 ) ;
}
