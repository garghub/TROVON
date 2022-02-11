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
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_13 = ( V_11 >> 8 ) ;
if ( V_13 == V_7 -> V_14 )
return 0 ;
if ( V_13 > 2 )
return - V_15 ;
V_12 = F_6 ( V_9 , V_16 , F_7 ( V_13 ) ) ;
if ( ! V_12 )
V_7 -> V_14 = V_13 ;
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
static int F_23 ( struct V_7 * V_7 ,
struct V_34 * V_35 )
{
if ( V_7 -> V_4 -> V_3 == V_39 ||
V_7 -> V_4 -> V_3 == V_40 ) {
V_35 -> V_37 = F_24 ( V_35 -> V_37 , 2 ) ;
V_35 -> V_38 = F_24 ( V_35 -> V_38 , 2 ) ;
}
F_25 ( & V_35 -> V_42 , & V_35 -> V_37 ,
V_62 , 2 , V_48 ) ;
F_25 ( & V_35 -> V_44 , & V_35 -> V_38 ,
V_63 , 2 , V_50 ) ;
return F_18 ( V_7 , V_35 ) ;
}
static int F_26 ( struct V_64 * V_65 , struct V_66 * V_67 )
{
struct V_34 V_35 = V_67 -> V_68 ;
struct V_8 * V_9 = F_16 ( V_65 ) ;
struct V_7 * V_7 = F_3 ( V_65 , struct V_7 , V_10 ) ;
int V_12 ;
F_10 ( & V_9 -> V_17 , L_3 ,
V_69 , V_35 . V_42 , V_35 . V_44 , V_35 . V_37 , V_35 . V_38 ) ;
if ( V_67 -> type != V_70 )
return - V_15 ;
V_12 = F_23 ( V_7 , & V_35 ) ;
if ( ! V_12 )
V_7 -> V_35 = V_35 ;
return V_12 ;
}
static int F_27 ( struct V_64 * V_65 , struct V_66 * V_67 )
{
struct V_7 * V_7 = F_3 ( V_65 , struct V_7 , V_10 ) ;
V_67 -> V_68 = V_7 -> V_35 ;
V_67 -> type = V_70 ;
return 0 ;
}
static int F_28 ( struct V_64 * V_65 , struct V_71 * V_67 )
{
if ( V_67 -> type != V_70 )
return - V_15 ;
V_67 -> V_72 . V_42 = V_62 ;
V_67 -> V_72 . V_44 = V_63 ;
V_67 -> V_72 . V_37 = V_48 ;
V_67 -> V_72 . V_38 = V_50 ;
V_67 -> V_73 = V_67 -> V_72 ;
V_67 -> V_74 . V_75 = 1 ;
V_67 -> V_74 . V_76 = 1 ;
return 0 ;
}
static int F_29 ( struct V_64 * V_65 ,
struct V_77 * V_78 )
{
struct V_7 * V_7 = F_3 ( V_65 , struct V_7 , V_10 ) ;
V_78 -> V_37 = V_7 -> V_35 . V_37 ;
V_78 -> V_38 = V_7 -> V_35 . V_38 ;
V_78 -> V_3 = V_7 -> V_4 -> V_3 ;
V_78 -> V_79 = V_7 -> V_4 -> V_79 ;
V_78 -> V_80 = V_81 ;
return 0 ;
}
static int F_30 ( struct V_7 * V_7 ,
enum V_2 V_3 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
T_1 V_82 , V_83 = V_84 |
V_85 | V_86 |
V_87 | V_88 |
V_89 | V_90 |
V_91 |
V_92 ;
int V_12 ;
switch ( V_3 ) {
case V_39 :
V_82 = V_84 |
V_86 ;
break;
case V_40 :
V_82 = V_85 | V_86 ;
break;
case V_93 :
V_82 = V_86 | V_88 |
V_91 ;
break;
case V_94 :
V_82 = V_86 | V_88 ;
break;
case V_95 :
V_82 = V_86 | V_87 |
V_91 ;
break;
case V_96 :
V_82 = V_86 | V_87 ;
break;
case V_97 :
V_82 = V_86 | V_87 |
V_92 ;
break;
case V_98 :
V_82 = V_86 | V_87 |
V_91 |
V_92 ;
break;
case V_99 :
V_82 = 0 ;
break;
case V_100 :
V_82 = V_92 ;
break;
case V_101 :
V_82 = V_91 ;
break;
case V_102 :
V_82 = V_91 |
V_92 ;
break;
default:
F_31 ( & V_9 -> V_17 , L_4 , V_3 ) ;
return - V_15 ;
}
V_12 = F_32 ( V_103 , V_82 ,
V_83 ) ;
if ( ! V_12 )
V_12 = F_32 ( V_104 , V_82 ,
V_83 ) ;
return V_12 ;
}
static int F_33 ( struct V_64 * V_65 ,
struct V_77 * V_78 )
{
struct V_8 * V_9 = F_16 ( V_65 ) ;
const struct V_1 * V_4 ;
struct V_7 * V_7 = F_3 ( V_65 , struct V_7 , V_10 ) ;
struct V_34 V_35 = {
. V_42 = V_7 -> V_35 . V_42 ,
. V_44 = V_7 -> V_35 . V_44 ,
. V_37 = V_78 -> V_37 ,
. V_38 = V_78 -> V_38 ,
} ;
int V_12 ;
V_4 = F_1 ( V_78 -> V_3 , V_105 ,
F_34 ( V_105 ) ) ;
if ( ! V_4 )
return - V_15 ;
F_10 ( & V_9 -> V_17 ,
L_5 , V_69 ,
V_78 -> V_3 , V_35 . V_42 , V_35 . V_44 , V_35 . V_37 , V_35 . V_38 ) ;
V_12 = F_23 ( V_7 , & V_35 ) ;
if ( ! V_12 )
V_12 = F_30 ( V_7 , V_78 -> V_3 ) ;
if ( ! V_12 ) {
V_7 -> V_35 = V_35 ;
V_7 -> V_4 = V_4 ;
V_78 -> V_79 = V_4 -> V_79 ;
}
return V_12 ;
}
static int F_35 ( struct V_64 * V_65 ,
struct V_77 * V_78 )
{
struct V_7 * V_7 = F_3 ( V_65 , struct V_7 , V_10 ) ;
const struct V_1 * V_4 ;
bool V_106 = V_78 -> V_3 == V_39 ||
V_78 -> V_3 == V_40 ;
V_4 = F_1 ( V_78 -> V_3 , V_105 ,
F_34 ( V_105 ) ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_78 -> V_3 = V_4 -> V_3 ;
}
if ( V_78 -> V_38 > V_50 )
V_78 -> V_38 = V_50 ;
else if ( V_78 -> V_38 < 2 )
V_78 -> V_38 = 2 ;
else if ( V_106 )
V_78 -> V_38 = F_24 ( V_78 -> V_38 , 2 ) ;
if ( V_78 -> V_37 > V_48 )
V_78 -> V_37 = V_48 ;
else if ( V_78 -> V_37 < 2 )
V_78 -> V_37 = 2 ;
else if ( V_106 )
V_78 -> V_37 = F_24 ( V_78 -> V_37 , 2 ) ;
V_78 -> V_79 = V_4 -> V_79 ;
return 0 ;
}
static int F_36 ( struct V_64 * V_65 ,
struct V_107 * V_108 )
{
struct V_8 * V_9 = F_16 ( V_65 ) ;
struct V_7 * V_7 = F_3 ( V_65 , struct V_7 , V_10 ) ;
if ( V_108 -> V_109 . type != V_110 )
return - V_15 ;
if ( V_108 -> V_109 . V_111 != V_9 -> V_111 )
return - V_112 ;
V_108 -> V_113 = V_7 -> V_114 ;
V_108 -> V_115 = 0 ;
return 0 ;
}
static int F_37 ( struct V_64 * V_65 ,
struct V_116 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_65 ) ;
int V_117 ;
if ( V_11 -> V_109 . type != V_110 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_109 . V_111 != V_9 -> V_111 )
return - V_112 ;
V_117 = F_8 ( V_9 , V_11 -> V_11 ) ;
V_11 -> V_118 = 2 ;
V_11 -> V_117 = ( V_119 ) V_117 ;
if ( V_11 -> V_117 > 0xffff )
return - V_120 ;
return 0 ;
}
static int F_38 ( struct V_64 * V_65 ,
struct V_116 * V_11 )
{
struct V_8 * V_9 = F_16 ( V_65 ) ;
if ( V_11 -> V_109 . type != V_110 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_109 . V_111 != V_9 -> V_111 )
return - V_112 ;
if ( F_11 ( V_9 , V_11 -> V_11 , V_11 -> V_117 ) < 0 )
return - V_120 ;
return 0 ;
}
static int F_39 ( struct V_7 * V_7 , int V_121 , int V_19 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
if ( V_7 -> V_122 == V_32 ) {
if ( V_121 )
V_12 = F_20 ( V_123 , V_19 ) ;
else
V_12 = F_22 ( V_123 , V_19 ) ;
} else {
if ( V_121 )
V_12 = F_20 ( V_124 , V_19 ) ;
else
V_12 = F_22 ( V_124 , V_19 ) ;
}
return V_12 ;
}
static int F_40 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_18 ;
V_18 = F_41 ( V_125 ) ;
if ( V_18 >= 0 )
return ( V_18 & 0x2f ) * ( 1 << ( ( V_18 >> 10 ) & 1 ) ) *
( 1 << ( ( V_18 >> 9 ) & 1 ) ) ;
return V_18 ;
}
static int F_42 ( struct V_7 * V_7 , int V_126 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
T_1 V_117 ;
if ( V_126 > 63 * 2 * 2 )
return - V_15 ;
if ( ( V_126 >= 64 * 2 ) && ( V_126 < 63 * 2 * 2 ) )
V_117 = ( 1 << 10 ) | ( 1 << 9 ) | ( V_126 / 4 ) ;
else if ( ( V_126 >= 64 ) && ( V_126 < 64 * 2 ) )
V_117 = ( 1 << 9 ) | ( V_126 / 2 ) ;
else
V_117 = V_126 ;
return F_17 ( V_125 , V_117 ) ;
}
static int F_43 ( struct V_7 * V_7 , int V_127 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
if ( V_127 )
return F_20 ( V_128 , V_129 ) ;
return F_22 ( V_128 , V_129 ) ;
}
static int F_44 ( struct V_7 * V_7 , int V_127 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
if ( V_127 )
return F_20 ( V_128 , V_130 ) ;
return F_22 ( V_128 , V_130 ) ;
}
static int F_45 ( struct V_131 * V_132 )
{
struct V_7 * V_7 = F_3 ( V_132 -> V_133 ,
struct V_7 , V_134 ) ;
switch ( V_132 -> V_108 ) {
case V_135 :
return F_39 ( V_7 , V_132 -> V_117 ,
V_136 ) ;
case V_137 :
return F_39 ( V_7 , V_132 -> V_117 ,
V_138 ) ;
case V_139 :
return F_42 ( V_7 , V_132 -> V_117 ) ;
case V_140 :
return F_43 ( V_7 , V_132 -> V_117 ) ;
case V_141 :
return F_44 ( V_7 , V_132 -> V_117 ) ;
}
return - V_15 ;
}
static int F_46 ( struct V_7 * V_7 )
{
F_47 ( V_7 -> V_126 , F_40 ( V_7 ) ) ;
return 0 ;
}
static void F_48 ( struct V_7 * V_7 )
{
F_15 ( V_7 , V_7 -> V_122 ) ;
F_30 ( V_7 , V_7 -> V_4 -> V_3 ) ;
F_18 ( V_7 , & V_7 -> V_35 ) ;
F_49 ( & V_7 -> V_134 ) ;
}
static int F_50 ( struct V_7 * V_7 )
{
int V_12 = 0 ;
if ( V_7 -> V_59 ) {
V_12 = F_19 ( V_7 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_7 ) ;
if ( ! V_12 )
F_48 ( V_7 ) ;
}
return V_12 ;
}
static int F_51 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_16 ( & V_7 -> V_10 ) ;
int V_12 ;
V_7 -> V_122 = V_32 ;
V_12 = F_19 ( V_7 ) ;
if ( ! V_12 )
V_12 = F_21 ( V_7 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_7 , V_7 -> V_122 ) ;
if ( V_12 )
F_31 ( & V_9 -> V_17 , L_6 , V_12 ) ;
return V_12 ;
}
static int F_52 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
T_2 V_18 ;
int V_12 ;
V_18 = F_41 ( V_142 ) ;
switch ( V_18 ) {
case 0x143a :
V_7 -> V_114 = V_143 ;
F_53 ( & V_9 -> V_17 ,
L_7 , V_18 ) ;
break;
case 0x148c :
V_7 -> V_114 = V_144 ;
F_53 ( & V_9 -> V_17 , L_8 , V_18 ) ;
break;
default:
F_31 ( & V_9 -> V_17 ,
L_9 ,
V_18 ) ;
return - V_112 ;
}
V_12 = F_51 ( V_7 ) ;
if ( V_12 )
return V_12 ;
return F_49 ( & V_7 -> V_134 ) ;
}
static int F_54 ( struct V_64 * V_65 , int V_127 )
{
struct V_7 * V_7 = F_3 ( V_65 , struct V_7 , V_10 ) ;
struct V_8 * V_9 = F_16 ( V_65 ) ;
int V_12 = 0 ;
F_55 ( & V_7 -> V_145 ) ;
if ( V_7 -> V_146 == ! V_127 ) {
if ( V_127 ) {
V_12 = F_50 ( V_7 ) ;
if ( V_12 ) {
F_31 ( & V_9 -> V_17 ,
L_10 , V_12 ) ;
goto V_147;
}
} else {
F_46 ( V_7 ) ;
}
}
V_7 -> V_146 += V_127 ? 1 : - 1 ;
F_56 ( V_7 -> V_146 < 0 ) ;
V_147:
F_57 ( & V_7 -> V_145 ) ;
return V_12 ;
}
static int F_58 ( struct V_64 * V_65 , unsigned int V_148 ,
enum V_2 * V_3 )
{
if ( V_148 >= F_34 ( V_105 ) )
return - V_15 ;
* V_3 = V_105 [ V_148 ] . V_3 ;
return 0 ;
}
static int F_59 ( struct V_64 * V_65 ,
struct V_149 * V_150 )
{
struct V_8 * V_9 = F_16 ( V_65 ) ;
struct V_151 * V_152 = F_60 ( V_9 ) ;
V_150 -> V_153 = V_154 | V_155 |
V_156 | V_157 |
V_158 ;
V_150 -> type = V_159 ;
V_150 -> V_153 = F_61 ( V_152 , V_150 ) ;
return 0 ;
}
static int F_62 ( struct V_8 * V_9 ,
const struct V_160 * V_161 )
{
struct V_7 * V_7 ;
struct V_162 * V_163 = F_63 ( V_9 -> V_17 . V_164 ) ;
struct V_151 * V_152 = F_60 ( V_9 ) ;
int V_12 ;
if ( ! V_152 ) {
F_31 ( & V_9 -> V_17 , L_11 ) ;
return - V_15 ;
}
if ( ! F_64 ( V_163 , V_165 ) ) {
F_65 ( & V_163 -> V_17 ,
L_12 ) ;
return - V_120 ;
}
V_7 = F_66 ( sizeof( struct V_7 ) , V_166 ) ;
if ( ! V_7 )
return - V_167 ;
F_67 ( & V_7 -> V_10 , V_9 , & V_168 ) ;
F_68 ( & V_7 -> V_134 , 5 ) ;
F_69 ( & V_7 -> V_134 , & V_169 ,
V_135 , 0 , 1 , 1 , 0 ) ;
F_69 ( & V_7 -> V_134 , & V_169 ,
V_137 , 0 , 1 , 1 , 0 ) ;
F_69 ( & V_7 -> V_134 , & V_169 ,
V_141 , 0 , 1 , 1 , 1 ) ;
V_7 -> V_126 = F_69 ( & V_7 -> V_134 , & V_169 ,
V_139 , 0 , 63 * 2 * 2 , 1 , 32 ) ;
F_70 ( & V_7 -> V_134 ,
& V_169 , V_140 , 1 , 0 ,
V_170 ) ;
V_7 -> V_10 . V_171 = & V_7 -> V_134 ;
if ( V_7 -> V_134 . error ) {
int V_172 = V_7 -> V_134 . error ;
F_71 ( V_7 ) ;
return V_172 ;
}
V_7 -> V_35 . V_42 = V_62 ;
V_7 -> V_35 . V_44 = V_63 ;
V_7 -> V_35 . V_37 = V_48 ;
V_7 -> V_35 . V_38 = V_50 ;
V_7 -> V_4 = & V_105 [ 0 ] ;
V_7 -> V_14 = - 1 ;
F_72 ( & V_7 -> V_145 ) ;
V_12 = F_52 ( V_9 ) ;
if ( V_12 ) {
F_73 ( & V_7 -> V_134 ) ;
F_71 ( V_7 ) ;
}
return V_12 ;
}
static int F_74 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
F_75 ( & V_7 -> V_10 ) ;
F_73 ( & V_7 -> V_134 ) ;
F_71 ( V_7 ) ;
return 0 ;
}
static int T_3 F_76 ( void )
{
return F_77 ( & V_173 ) ;
}
static void T_4 F_78 ( void )
{
F_79 ( & V_173 ) ;
}
