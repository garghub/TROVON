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
struct V_47 * V_29 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
V_29 -> V_48 = V_19 -> V_49 ;
V_29 -> V_50 = 0 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
int V_13 ;
V_52 -> V_53 = 1 ;
if ( V_52 -> V_52 > 0xff )
return - V_46 ;
V_13 = F_3 ( V_6 , V_52 -> V_52 ) ;
if ( V_13 < 0 )
return V_13 ;
V_52 -> V_12 = ( V_54 ) V_13 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
const struct V_51 * V_52 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
if ( V_52 -> V_52 > 0xff ||
V_52 -> V_12 > 0xff )
return - V_46 ;
return F_5 ( V_6 , V_52 -> V_52 , V_52 -> V_12 ) ;
}
static int F_17 ( struct V_2 * V_3 , int V_55 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
struct V_56 * V_57 = F_18 ( V_6 ) ;
return F_19 ( & V_6 -> V_20 , V_57 , V_55 ) ;
}
static const struct V_58 * F_20 ( T_3 V_59 , T_3 V_60 )
{
const struct V_58 * V_23 = & V_61 [ 0 ] ;
T_3 V_62 = V_63 ;
unsigned int V_64 ;
for ( V_64 = 0 ; V_64 < F_21 ( V_61 ) ; ++ V_64 ) {
T_3 V_65 = abs ( V_59 - V_61 [ V_64 ] . V_66 . V_59 )
+ abs ( V_60 - V_61 [ V_64 ] . V_66 . V_60 ) ;
if ( V_65 < V_62 ) {
V_62 = V_65 ;
V_23 = & V_61 [ V_64 ] ;
}
}
return V_23 ;
}
static void F_22 ( const struct V_67 * V_68 ,
const struct V_69 * * V_21 ,
const struct V_58 * * V_23 )
{
unsigned int V_64 ;
* V_21 = & V_70 [ 0 ] ;
for ( V_64 = 0 ; V_64 < F_21 ( V_70 ) ; V_64 ++ ) {
if ( V_68 -> V_22 == V_70 [ V_64 ] . V_22 ) {
* V_21 = & V_70 [ V_64 ] ;
break;
}
}
* V_23 = F_20 ( V_68 -> V_59 , V_68 -> V_60 ) ;
}
static int F_23 ( struct V_1 * V_19 ,
const struct V_69 * V_21 ,
const struct V_58 * V_23 )
{
struct V_5 * V_6 = F_11 ( & V_19 -> V_4 ) ;
int V_13 ;
T_1 V_12 ;
F_8 ( V_6 ) ;
if ( V_19 -> V_33 -> V_71 . V_72 & V_73 ) {
V_13 = F_7 ( V_6 , V_74 , V_75 , 0x00 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_7 ( V_6 ,
V_77 , V_78 ,
V_19 -> V_33 -> V_71 . V_79 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_7 ( V_6 ,
V_80 , V_81 ,
V_19 -> V_33 -> V_71 . V_72 ) ;
if ( V_13 < 0 )
goto V_76;
} else if ( V_19 -> V_33 -> V_71 . V_82 > V_19 -> V_33 -> V_71 . V_83 ) {
V_13 = F_7 ( V_6 ,
V_84 , V_85 ,
V_19 -> V_33 -> V_71 . V_82 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_7 ( V_6 ,
V_86 , V_87 ,
V_19 -> V_33 -> V_71 . V_83 ) ;
if ( V_13 < 0 )
goto V_76;
}
V_13 = F_5 ( V_6 , V_88 , V_23 -> V_66 . V_89 >> 2 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_90 , V_23 -> V_66 . V_59 >> 2 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_91 , V_23 -> V_66 . V_92 >> 1 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_93 , V_23 -> V_66 . V_60 >> 1 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_94 , V_23 -> V_66 . V_59 >> 2 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_95 , V_23 -> V_66 . V_60 >> 1 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_96 ,
( ( V_23 -> V_66 . V_92 & 1 ) << V_97 ) |
( ( V_23 -> V_66 . V_89 & 3 ) << V_98 ) |
( ( V_23 -> V_66 . V_60 & 1 ) << V_99 ) |
( ( V_23 -> V_66 . V_59 & 3 ) << V_100 ) ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_101 ,
( ( V_23 -> V_66 . V_60 & 1 ) << V_102 ) |
( ( V_23 -> V_66 . V_59 & 3 ) << V_103 ) ) ;
if ( V_13 < 0 )
goto V_76;
V_12 = V_21 -> V_104 ;
if ( V_12 ) {
V_13 = F_7 ( V_6 ,
V_105 , V_106 , V_12 ) ;
if ( V_13 < 0 )
goto V_76;
}
if ( V_21 -> V_107 ) {
V_13 = F_5 ( V_6 , V_108 , V_21 -> V_107 ) ;
if ( V_13 < 0 )
goto V_76;
}
V_12 = V_21 -> V_109 ;
if ( V_19 -> V_33 -> V_34 & V_35 )
V_12 |= V_31 ;
if ( V_19 -> V_33 -> V_34 & V_40 )
V_12 |= V_38 ;
if ( V_19 -> V_32 )
V_12 ^= V_31 ;
if ( V_19 -> V_39 )
V_12 ^= V_38 ;
V_13 = F_7 ( V_6 ,
V_36 , V_110 | V_111 , V_12 ) ;
if ( V_13 < 0 )
goto V_76;
V_13 = F_5 ( V_6 , V_14 , V_23 -> V_112 | V_21 -> V_113 ) ;
if ( V_13 < 0 )
goto V_76;
if ( V_19 -> V_45 ) {
V_13 = F_7 ( V_6 , V_43 , V_44 , 1 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_6 , V_42 ,
0xff , 256 - V_19 -> V_45 ) ;
if ( V_13 < 0 )
goto V_76;
}
return V_13 ;
V_76:
F_8 ( V_6 ) ;
return V_13 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_114 * V_115 )
{
V_115 -> V_116 . V_89 = 0 ;
V_115 -> V_116 . V_92 = 0 ;
V_115 -> V_116 . V_59 = V_117 ;
V_115 -> V_116 . V_60 = V_118 ;
V_115 -> type = V_119 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_120 * V_115 )
{
V_115 -> V_121 . V_89 = 0 ;
V_115 -> V_121 . V_92 = 0 ;
V_115 -> V_121 . V_59 = V_122 ;
V_115 -> V_121 . V_60 = V_123 ;
V_115 -> V_124 = V_115 -> V_121 ;
V_115 -> type = V_119 ;
V_115 -> V_125 . V_126 = 1 ;
V_115 -> V_125 . V_127 = 1 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
V_68 -> V_59 = V_19 -> V_23 -> V_66 . V_59 ;
V_68 -> V_60 = V_19 -> V_23 -> V_66 . V_60 ;
V_68 -> V_22 = V_19 -> V_21 -> V_22 ;
V_68 -> V_128 = V_19 -> V_21 -> V_128 ;
V_68 -> V_129 = V_130 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
const struct V_69 * V_21 ;
const struct V_58 * V_23 ;
int V_13 ;
F_22 ( V_68 , & V_21 , & V_23 ) ;
V_13 = F_23 ( V_19 , V_21 , V_23 ) ;
if ( V_13 < 0 )
return V_13 ;
V_19 -> V_23 = V_23 ;
V_19 -> V_21 = V_21 ;
V_68 -> V_22 = V_21 -> V_22 ;
V_68 -> V_59 = V_23 -> V_66 . V_59 ;
V_68 -> V_60 = V_23 -> V_66 . V_60 ;
V_68 -> V_129 = V_130 ;
V_68 -> V_128 = V_21 -> V_128 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
const struct V_69 * V_21 ;
const struct V_58 * V_23 ;
F_22 ( V_68 , & V_21 , & V_23 ) ;
V_68 -> V_22 = V_21 -> V_22 ;
V_68 -> V_59 = V_23 -> V_66 . V_59 ;
V_68 -> V_60 = V_23 -> V_66 . V_60 ;
V_68 -> V_129 = V_130 ;
V_68 -> V_128 = V_21 -> V_128 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_19 )
{
struct V_5 * V_6 = F_11 ( & V_19 -> V_4 ) ;
T_1 V_131 , V_132 ;
const char * V_133 ;
int V_13 ;
V_13 = F_17 ( & V_19 -> V_4 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_131 = F_3 ( V_6 , V_134 ) ;
V_132 = F_3 ( V_6 , V_135 ) ;
switch ( F_30 ( V_131 , V_132 ) ) {
case V_136 :
V_133 = L_2 ;
V_19 -> V_49 = V_137 ;
break;
case V_138 :
V_133 = L_3 ;
V_19 -> V_49 = V_139 ;
break;
default:
F_31 ( & V_6 -> V_20 ,
L_4 , V_131 , V_132 ) ;
V_13 = - V_140 ;
goto V_141;
}
F_32 ( & V_6 -> V_20 ,
L_5 ,
V_133 ,
V_131 ,
V_132 ,
F_3 ( V_6 , V_142 ) ,
F_3 ( V_6 , V_143 ) ) ;
V_13 = F_33 ( & V_19 -> V_28 ) ;
V_141:
F_17 ( & V_19 -> V_4 , 0 ) ;
return V_13 ;
}
static int F_34 ( struct V_2 * V_3 , unsigned int V_144 ,
enum V_145 * V_22 )
{
if ( V_144 >= F_21 ( V_70 ) )
return - V_46 ;
* V_22 = V_70 [ V_144 ] . V_22 ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 = F_11 ( V_3 ) ;
struct V_56 * V_57 = F_18 ( V_6 ) ;
V_147 -> V_34 = V_148 | V_149 |
V_150 | V_151 |
V_152 ;
V_147 -> type = V_153 ;
V_147 -> V_34 = F_36 ( V_57 , V_147 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
const struct V_154 * V_155 )
{
struct V_1 * V_19 ;
struct V_56 * V_57 = F_18 ( V_6 ) ;
struct V_156 * V_157 = F_38 ( V_6 -> V_20 . V_158 ) ;
int V_13 ;
if ( ! V_57 || ! V_57 -> V_159 ) {
F_31 ( & V_6 -> V_20 , L_6 ) ;
return - V_46 ;
}
if ( ! F_39 ( V_157 , V_160 ) ) {
F_31 ( & V_157 -> V_20 ,
L_7
L_8 ) ;
return - V_161 ;
}
V_19 = F_40 ( & V_6 -> V_20 , sizeof( * V_19 ) , V_162 ) ;
if ( ! V_19 )
return - V_163 ;
V_19 -> V_33 = V_57 -> V_159 ;
F_41 ( & V_19 -> V_4 , V_6 , & V_164 ) ;
F_42 ( & V_19 -> V_28 , 3 ) ;
F_43 ( & V_19 -> V_28 , & V_165 ,
V_30 , 0 , 1 , 1 , 0 ) ;
F_43 ( & V_19 -> V_28 , & V_165 ,
V_37 , 0 , 1 , 1 , 0 ) ;
F_43 ( & V_19 -> V_28 , & V_165 ,
V_41 , 0 , 256 , 1 , 0 ) ;
V_19 -> V_4 . V_166 = & V_19 -> V_28 ;
if ( V_19 -> V_28 . error )
return V_19 -> V_28 . error ;
V_13 = F_29 ( V_19 ) ;
if ( V_13 < 0 ) {
F_44 ( & V_19 -> V_28 ) ;
} else {
V_19 -> V_21 = & V_70 [ 0 ] ;
V_19 -> V_23 = & V_61 [ 0 ] ;
}
return V_13 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_19 = F_1 ( F_46 ( V_6 ) ) ;
F_47 ( & V_19 -> V_4 ) ;
F_44 ( & V_19 -> V_28 ) ;
return 0 ;
}
