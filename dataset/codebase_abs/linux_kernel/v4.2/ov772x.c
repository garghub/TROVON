static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_4 ( V_6 , V_7 ) ;
}
static inline int F_5 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_8 )
{
return F_6 ( V_6 , V_7 , V_8 ) ;
}
static int F_7 ( struct V_5 * V_6 , T_1 V_9 , T_1 V_10 ,
T_1 V_11 )
{
T_2 V_12 = F_3 ( V_6 , V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 &= ~ V_10 ;
V_12 |= V_11 & V_10 ;
return F_5 ( V_6 , V_9 , V_12 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_5 ( V_6 , V_14 , V_15 ) ;
if ( V_13 < 0 )
return V_13 ;
F_9 ( 1 ) ;
return F_7 ( V_6 , V_16 , V_17 , V_17 ) ;
}
static int F_10 ( struct V_2 * V_3 , int V_18 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( ! V_18 ) {
F_7 ( V_6 , V_16 , V_17 , V_17 ) ;
return 0 ;
}
F_7 ( V_6 , V_16 , V_17 , 0 ) ;
F_12 ( & V_6 -> V_20 , L_1 ,
V_19 -> V_21 -> V_22 , V_19 -> V_23 -> V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_25 * V_26 )
{
struct V_1 * V_19 = F_2 ( V_26 -> V_27 ,
struct V_1 , V_28 ) ;
struct V_2 * V_3 = & V_19 -> V_4 ;
struct V_5 * V_6 = F_11 ( V_3 ) ;
int V_13 = 0 ;
T_1 V_12 ;
switch ( V_26 -> V_29 ) {
case V_30 :
V_12 = V_26 -> V_12 ? V_31 : 0x00 ;
V_19 -> V_32 = V_26 -> V_12 ;
if ( V_19 -> V_33 -> V_34 & V_35 )
V_12 ^= V_31 ;
return F_7 ( V_6 , V_36 , V_31 , V_12 ) ;
case V_37 :
V_12 = V_26 -> V_12 ? V_38 : 0x00 ;
V_19 -> V_39 = V_26 -> V_12 ;
if ( V_19 -> V_33 -> V_34 & V_40 )
V_12 ^= V_38 ;
return F_7 ( V_6 , V_36 , V_38 , V_12 ) ;
case V_41 :
if ( ! V_26 -> V_12 ) {
V_13 = F_7 ( V_6 , V_42 , 0xff , 0xff ) ;
if ( ! V_13 )
V_13 = F_7 ( V_6 , V_43 ,
V_44 , 0 ) ;
} else {
V_12 = 256 - V_26 -> V_12 ;
V_13 = F_7 ( V_6 , V_43 ,
V_44 , V_44 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_6 , V_42 ,
0xff , V_12 ) ;
}
if ( ! V_13 )
V_19 -> V_45 = V_26 -> V_12 ;
return V_13 ;
}
return - V_46 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_47 * V_48 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
int V_13 ;
V_48 -> V_49 = 1 ;
if ( V_48 -> V_48 > 0xff )
return - V_46 ;
V_13 = F_3 ( V_6 , V_48 -> V_48 ) ;
if ( V_13 < 0 )
return V_13 ;
V_48 -> V_12 = ( V_50 ) V_13 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
if ( V_48 -> V_48 > 0xff ||
V_48 -> V_12 > 0xff )
return - V_46 ;
return F_5 ( V_6 , V_48 -> V_48 , V_48 -> V_12 ) ;
}
static int F_16 ( struct V_2 * V_3 , int V_51 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
struct V_52 * V_53 = F_17 ( V_6 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
return F_18 ( & V_6 -> V_20 , V_53 , V_19 -> V_54 , V_51 ) ;
}
static const struct V_55 * F_19 ( T_3 V_56 , T_3 V_57 )
{
const struct V_55 * V_23 = & V_58 [ 0 ] ;
T_3 V_59 = V_60 ;
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < F_20 ( V_58 ) ; ++ V_61 ) {
T_3 V_62 = abs ( V_56 - V_58 [ V_61 ] . V_63 . V_56 )
+ abs ( V_57 - V_58 [ V_61 ] . V_63 . V_57 ) ;
if ( V_62 < V_59 ) {
V_59 = V_62 ;
V_23 = & V_58 [ V_61 ] ;
}
}
return V_23 ;
}
static void F_21 ( const struct V_64 * V_65 ,
const struct V_66 * * V_21 ,
const struct V_55 * * V_23 )
{
unsigned int V_61 ;
* V_21 = & V_67 [ 0 ] ;
for ( V_61 = 0 ; V_61 < F_20 ( V_67 ) ; V_61 ++ ) {
if ( V_65 -> V_22 == V_67 [ V_61 ] . V_22 ) {
* V_21 = & V_67 [ V_61 ] ;
break;
}
}
* V_23 = F_19 ( V_65 -> V_56 , V_65 -> V_57 ) ;
}
static int F_22 ( struct V_1 * V_19 ,
const struct V_66 * V_21 ,
const struct V_55 * V_23 )
{
struct V_5 * V_6 = F_11 ( & V_19 -> V_4 ) ;
int V_13 ;
T_1 V_12 ;
F_8 ( V_6 ) ;
if ( V_19 -> V_33 -> V_68 . V_69 & V_70 ) {
V_13 = F_7 ( V_6 , V_71 , V_72 , 0x00 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_7 ( V_6 ,
V_74 , V_75 ,
V_19 -> V_33 -> V_68 . V_76 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_7 ( V_6 ,
V_77 , V_78 ,
V_19 -> V_33 -> V_68 . V_69 ) ;
if ( V_13 < 0 )
goto V_73;
} else if ( V_19 -> V_33 -> V_68 . V_79 > V_19 -> V_33 -> V_68 . V_80 ) {
V_13 = F_7 ( V_6 ,
V_81 , V_82 ,
V_19 -> V_33 -> V_68 . V_79 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_7 ( V_6 ,
V_83 , V_84 ,
V_19 -> V_33 -> V_68 . V_80 ) ;
if ( V_13 < 0 )
goto V_73;
}
V_13 = F_5 ( V_6 , V_85 , V_23 -> V_63 . V_86 >> 2 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_87 , V_23 -> V_63 . V_56 >> 2 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_88 , V_23 -> V_63 . V_89 >> 1 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_90 , V_23 -> V_63 . V_57 >> 1 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_91 , V_23 -> V_63 . V_56 >> 2 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_92 , V_23 -> V_63 . V_57 >> 1 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_93 ,
( ( V_23 -> V_63 . V_89 & 1 ) << V_94 ) |
( ( V_23 -> V_63 . V_86 & 3 ) << V_95 ) |
( ( V_23 -> V_63 . V_57 & 1 ) << V_96 ) |
( ( V_23 -> V_63 . V_56 & 3 ) << V_97 ) ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_98 ,
( ( V_23 -> V_63 . V_57 & 1 ) << V_99 ) |
( ( V_23 -> V_63 . V_56 & 3 ) << V_100 ) ) ;
if ( V_13 < 0 )
goto V_73;
V_12 = V_21 -> V_101 ;
if ( V_12 ) {
V_13 = F_7 ( V_6 ,
V_102 , V_103 , V_12 ) ;
if ( V_13 < 0 )
goto V_73;
}
if ( V_21 -> V_104 ) {
V_13 = F_5 ( V_6 , V_105 , V_21 -> V_104 ) ;
if ( V_13 < 0 )
goto V_73;
}
V_12 = V_21 -> V_106 ;
if ( V_19 -> V_33 -> V_34 & V_35 )
V_12 |= V_31 ;
if ( V_19 -> V_33 -> V_34 & V_40 )
V_12 |= V_38 ;
if ( V_19 -> V_32 )
V_12 ^= V_31 ;
if ( V_19 -> V_39 )
V_12 ^= V_38 ;
V_13 = F_7 ( V_6 ,
V_36 , V_107 | V_108 , V_12 ) ;
if ( V_13 < 0 )
goto V_73;
V_13 = F_5 ( V_6 , V_14 , V_23 -> V_109 | V_21 -> V_110 ) ;
if ( V_13 < 0 )
goto V_73;
if ( V_19 -> V_45 ) {
V_13 = F_7 ( V_6 , V_43 , V_44 , 1 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_6 , V_42 ,
0xff , 256 - V_19 -> V_45 ) ;
if ( V_13 < 0 )
goto V_73;
}
return V_13 ;
V_73:
F_8 ( V_6 ) ;
return V_13 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_111 * V_112 )
{
V_112 -> V_113 . V_86 = 0 ;
V_112 -> V_113 . V_89 = 0 ;
V_112 -> V_113 . V_56 = V_114 ;
V_112 -> V_113 . V_57 = V_115 ;
V_112 -> type = V_116 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_117 * V_112 )
{
V_112 -> V_118 . V_86 = 0 ;
V_112 -> V_118 . V_89 = 0 ;
V_112 -> V_118 . V_56 = V_119 ;
V_112 -> V_118 . V_57 = V_120 ;
V_112 -> V_121 = V_112 -> V_118 ;
V_112 -> type = V_116 ;
V_112 -> V_122 . V_123 = 1 ;
V_112 -> V_122 . V_124 = 1 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
struct V_127 * V_128 )
{
struct V_64 * V_65 = & V_128 -> V_128 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( V_128 -> V_129 )
return - V_46 ;
V_65 -> V_56 = V_19 -> V_23 -> V_63 . V_56 ;
V_65 -> V_57 = V_19 -> V_23 -> V_63 . V_57 ;
V_65 -> V_22 = V_19 -> V_21 -> V_22 ;
V_65 -> V_130 = V_19 -> V_21 -> V_130 ;
V_65 -> V_131 = V_132 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_64 * V_65 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
const struct V_66 * V_21 ;
const struct V_55 * V_23 ;
int V_13 ;
F_21 ( V_65 , & V_21 , & V_23 ) ;
V_13 = F_22 ( V_19 , V_21 , V_23 ) ;
if ( V_13 < 0 )
return V_13 ;
V_19 -> V_23 = V_23 ;
V_19 -> V_21 = V_21 ;
V_65 -> V_22 = V_21 -> V_22 ;
V_65 -> V_56 = V_23 -> V_63 . V_56 ;
V_65 -> V_57 = V_23 -> V_63 . V_57 ;
V_65 -> V_131 = V_132 ;
V_65 -> V_130 = V_21 -> V_130 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
struct V_127 * V_128 )
{
struct V_64 * V_65 = & V_128 -> V_128 ;
const struct V_66 * V_21 ;
const struct V_55 * V_23 ;
if ( V_128 -> V_129 )
return - V_46 ;
F_21 ( V_65 , & V_21 , & V_23 ) ;
V_65 -> V_22 = V_21 -> V_22 ;
V_65 -> V_56 = V_23 -> V_63 . V_56 ;
V_65 -> V_57 = V_23 -> V_63 . V_57 ;
V_65 -> V_131 = V_132 ;
V_65 -> V_130 = V_21 -> V_130 ;
if ( V_128 -> V_133 == V_134 )
return F_26 ( V_3 , V_65 ) ;
V_126 -> V_135 = * V_65 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_19 )
{
struct V_5 * V_6 = F_11 ( & V_19 -> V_4 ) ;
T_1 V_136 , V_137 ;
const char * V_138 ;
int V_13 ;
V_13 = F_16 ( & V_19 -> V_4 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_136 = F_3 ( V_6 , V_139 ) ;
V_137 = F_3 ( V_6 , V_140 ) ;
switch ( F_29 ( V_136 , V_137 ) ) {
case V_141 :
V_138 = L_2 ;
break;
case V_142 :
V_138 = L_3 ;
break;
default:
F_30 ( & V_6 -> V_20 ,
L_4 , V_136 , V_137 ) ;
V_13 = - V_143 ;
goto V_144;
}
F_31 ( & V_6 -> V_20 ,
L_5 ,
V_138 ,
V_136 ,
V_137 ,
F_3 ( V_6 , V_145 ) ,
F_3 ( V_6 , V_146 ) ) ;
V_13 = F_32 ( & V_19 -> V_28 ) ;
V_144:
F_16 ( & V_19 -> V_4 , 0 ) ;
return V_13 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
struct V_147 * V_22 )
{
if ( V_22 -> V_129 || V_22 -> V_148 >= F_20 ( V_67 ) )
return - V_46 ;
V_22 -> V_22 = V_67 [ V_22 -> V_148 ] . V_22 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_149 * V_126 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
struct V_52 * V_53 = F_17 ( V_6 ) ;
V_126 -> V_34 = V_150 | V_151 |
V_152 | V_153 |
V_154 ;
V_126 -> type = V_155 ;
V_126 -> V_34 = F_35 ( V_53 , V_126 ) ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
const struct V_156 * V_157 )
{
struct V_1 * V_19 ;
struct V_52 * V_53 = F_17 ( V_6 ) ;
struct V_158 * V_159 = F_37 ( V_6 -> V_20 . V_160 ) ;
int V_13 ;
if ( ! V_53 || ! V_53 -> V_161 ) {
F_30 ( & V_6 -> V_20 , L_6 ) ;
return - V_46 ;
}
if ( ! F_38 ( V_159 , V_162 ) ) {
F_30 ( & V_159 -> V_20 ,
L_7
L_8 ) ;
return - V_163 ;
}
V_19 = F_39 ( & V_6 -> V_20 , sizeof( * V_19 ) , V_164 ) ;
if ( ! V_19 )
return - V_165 ;
V_19 -> V_33 = V_53 -> V_161 ;
F_40 ( & V_19 -> V_4 , V_6 , & V_166 ) ;
F_41 ( & V_19 -> V_28 , 3 ) ;
F_42 ( & V_19 -> V_28 , & V_167 ,
V_30 , 0 , 1 , 1 , 0 ) ;
F_42 ( & V_19 -> V_28 , & V_167 ,
V_37 , 0 , 1 , 1 , 0 ) ;
F_42 ( & V_19 -> V_28 , & V_167 ,
V_41 , 0 , 256 , 1 , 0 ) ;
V_19 -> V_4 . V_168 = & V_19 -> V_28 ;
if ( V_19 -> V_28 . error )
return V_19 -> V_28 . error ;
V_19 -> V_54 = F_43 ( & V_6 -> V_20 , L_9 ) ;
if ( F_44 ( V_19 -> V_54 ) ) {
V_13 = F_45 ( V_19 -> V_54 ) ;
goto V_169;
}
V_13 = F_28 ( V_19 ) ;
if ( V_13 < 0 ) {
F_46 ( V_19 -> V_54 ) ;
V_169:
F_47 ( & V_19 -> V_28 ) ;
} else {
V_19 -> V_21 = & V_67 [ 0 ] ;
V_19 -> V_23 = & V_58 [ 0 ] ;
}
return V_13 ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_19 = F_1 ( F_49 ( V_6 ) ) ;
F_46 ( V_19 -> V_54 ) ;
F_50 ( & V_19 -> V_4 ) ;
F_47 ( & V_19 -> V_28 ) ;
return 0 ;
}
