static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 == V_4 )
return true ;
else
return false ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_4 :
return false ;
default:
return true ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
return true ;
default:
return false ;
}
}
static int F_4 ( int V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < F_5 ( V_54 ) ; V_53 ++ ) {
if ( V_54 [ V_53 ] . V_52 == V_52 )
return V_53 ;
}
return - V_55 ;
}
static int F_6 ( int V_56 , int V_57 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < F_5 ( V_58 ) ; V_53 ++ ) {
if ( V_58 [ V_53 ] . V_56 == V_56 &&
V_58 [ V_53 ] . V_57 == V_57 )
return V_53 ;
}
return - V_55 ;
}
static int F_7 ( struct V_59 * V_60 ,
int V_61 , unsigned int V_62 , int V_63 )
{
struct V_64 * V_65 = F_8 ( V_60 -> V_66 ) ;
int V_67 ;
T_1 V_56 ;
V_67 = F_4 ( V_62 ) ;
if ( V_67 < 0 )
return V_67 ;
V_56 = V_54 [ V_67 ] . V_52 /
V_54 [ V_67 ] . V_68 ;
F_9 ( V_65 -> V_69 , V_10 ,
V_70 ,
V_54 [ V_67 ] . V_71 ) ;
V_65 -> V_56 = V_56 ;
return 0 ;
}
static int F_10 ( struct V_59 * V_60 , unsigned int V_72 )
{
struct V_64 * V_65 = F_8 ( V_60 -> V_66 ) ;
T_2 V_73 = 0 , V_74 = 0 ;
switch ( V_72 & V_75 ) {
case V_76 :
V_73 |= V_77 ;
break;
case V_78 :
break;
default:
return - V_55 ;
}
switch ( V_72 & V_79 ) {
case V_80 :
V_74 |= V_81 ;
break;
case V_82 :
V_74 |= V_83 ;
break;
default:
return - V_55 ;
}
switch ( V_72 & V_84 ) {
case V_85 :
case V_86 :
V_73 ^= V_87 ;
break;
default:
break;
}
F_9 ( V_65 -> V_69 , V_13 ,
V_77 | V_87 , V_73 ) ;
F_9 ( V_65 -> V_69 , V_14 ,
V_81 | V_83 , V_74 ) ;
return 0 ;
}
static int F_11 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
struct V_59 * V_60 )
{
struct V_64 * V_65 = F_8 ( V_60 -> V_66 ) ;
int V_57 = F_12 ( V_91 ) ;
int V_92 ;
V_92 = F_6 ( V_65 -> V_56 , V_57 ) ;
if ( V_92 < 0 )
return - V_55 ;
F_9 ( V_65 -> V_69 , V_11 ,
V_93 ,
V_58 [ V_92 ] . V_94 ) ;
F_9 ( V_65 -> V_69 , V_10 ,
V_95 ,
V_58 [ V_92 ] . V_96 ) ;
F_9 ( V_65 -> V_69 , V_13 ,
V_97 ,
V_58 [ V_92 ] . V_98 ) ;
return 0 ;
}
static int F_13 ( struct V_99 * V_66 ,
enum V_100 V_101 )
{
struct V_102 * V_103 = F_14 ( V_66 ) ;
struct V_64 * V_65 = F_8 ( V_66 ) ;
unsigned int V_3 ;
int V_53 , V_104 , V_105 ;
switch ( V_101 ) {
case V_106 :
break;
case V_107 :
if ( V_103 -> V_108 == V_109 )
F_9 ( V_65 -> V_69 , V_9 ,
V_110 , 0 ) ;
break;
case V_109 :
if ( V_103 -> V_108 == V_111 ) {
V_105 = F_15 ( V_65 -> V_112 ) ;
if ( V_105 ) {
F_16 ( V_66 -> V_2 ,
L_1 , V_105 ) ;
return V_105 ;
}
F_9 ( V_65 -> V_69 , V_10 ,
V_113 , 0 ) ;
F_9 ( V_65 -> V_69 , V_9 ,
V_114 , 0 ) ;
F_17 ( 50 ) ;
} else {
F_9 ( V_65 -> V_69 , V_9 ,
V_114 ,
V_115 ) ;
}
break;
case V_111 :
F_9 ( V_65 -> V_69 , V_51 ,
V_116 , 0 ) ;
F_18 ( V_65 -> V_69 , V_26 , & V_3 ) ;
if ( V_3 & V_117 )
V_104 = V_118 ;
else
V_104 = 10 ;
F_9 ( V_65 -> V_69 , V_9 ,
V_114 ,
V_115 ) ;
F_17 ( 20 ) ;
F_18 ( V_65 -> V_69 , V_4 , & V_3 ) ;
for ( V_53 = 0 ; V_53 < V_104 ; V_53 ++ ) {
if ( V_104 < 10 ) {
F_19 ( 1000 , 1100 ) ;
F_18 ( V_65 -> V_69 , V_4 , & V_3 ) ;
if ( V_3 & V_116 )
break;
} else {
F_19 ( 10000 , 10100 ) ;
F_18 ( V_65 -> V_69 , V_4 , & V_3 ) ;
if ( V_3 & V_116 )
break;
}
}
F_9 ( V_65 -> V_69 , V_51 ,
V_116 , V_116 ) ;
F_9 ( V_65 -> V_69 , V_10 ,
V_113 ,
V_119 ) ;
F_20 ( V_65 -> V_112 ) ;
break;
}
return 0 ;
}
static int F_21 ( struct V_59 * V_60 , int V_120 )
{
struct V_64 * V_65 = F_8 ( V_60 -> V_66 ) ;
T_2 V_121 = V_120 ? V_122 : 0 ;
return F_9 ( V_65 -> V_69 , V_14 ,
V_123 , V_121 ) ;
}
static int F_22 ( struct V_88 * V_89 ,
struct V_59 * V_60 )
{
F_23 ( V_89 -> V_124 , 0 ,
V_125 , & V_126 ) ;
return 0 ;
}
static int F_24 ( struct V_59 * V_60 ,
unsigned int V_127 , unsigned int V_128 ,
int V_129 , int V_130 )
{
struct V_64 * V_65 = F_8 ( V_60 -> V_66 ) ;
unsigned int V_131 [ V_132 ] = { 48 , 48 , 48 , 48 } ;
unsigned int V_133 , V_134 ;
T_3 V_135 = 0 ;
int V_53 ;
if ( ! V_128 ) {
F_16 ( V_60 -> V_2 , L_2 ) ;
return - V_55 ;
}
if ( V_129 <= 0 || V_130 <= 0 || V_130 > 64 ) {
F_16 ( V_60 -> V_2 , L_3 ) ;
return - V_55 ;
}
if ( V_130 & 0x7 ) {
F_16 ( V_60 -> V_2 , L_4 ) ;
return - V_55 ;
}
V_134 = V_130 >> 3 ;
for ( V_53 = 0 ; V_128 && V_53 < V_132 ; V_53 ++ ) {
V_133 = F_25 ( V_128 ) ;
V_131 [ V_53 ] = V_133 * V_134 ;
V_135 |= ( T_3 ) ( ( T_3 ) ( 1 << V_134 ) - 1 ) << ( T_3 ) V_131 [ V_53 ] ;
V_128 &= ~ ( 1 << V_133 ) ;
}
if ( V_128 && V_53 == V_132 ) {
F_16 ( V_60 -> V_2 , L_5 ,
V_132 ) ;
return - V_55 ;
}
V_133 = V_131 [ V_53 - 1 ] + V_134 - 1 ;
if ( V_133 > 47 ) {
F_16 ( V_60 -> V_2 , L_6 ,
V_133 ) ;
return - V_55 ;
}
for ( V_53 = 0 ; V_53 < V_132 && V_131 [ V_53 ] != 48 ; V_53 ++ ) {
F_9 ( V_65 -> V_69 , F_26 ( V_53 ) ,
V_136 , V_131 [ V_53 ] ) ;
F_27 ( V_60 -> V_2 , L_7 , V_53 , V_131 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < V_137 && V_135 ; V_53 ++ ) {
F_28 ( V_65 -> V_69 , F_29 ( V_53 ) ,
V_135 & 0xff ) ;
V_135 >>= 8 ;
F_27 ( V_60 -> V_2 , L_8 ,
F_29 ( V_53 ) , V_135 & 0xff ) ;
}
return 0 ;
}
static int F_30 ( struct V_59 * V_60 , int V_138 , int V_139 )
{
struct V_64 * V_65 = F_8 ( V_60 -> V_66 ) ;
if ( V_65 -> V_140 )
F_31 ( V_65 -> V_140 , V_138 ) ;
return 0 ;
}
static int F_32 ( struct V_99 * V_66 )
{
struct V_64 * V_65 = F_8 ( V_66 ) ;
struct V_102 * V_103 = F_14 ( V_66 ) ;
if ( V_65 -> V_141 )
F_33 ( V_103 , V_142 ,
F_5 ( V_142 ) ) ;
else
F_33 ( V_103 , V_143 ,
F_5 ( V_143 ) ) ;
return 0 ;
}
static int F_34 ( struct V_144 * V_145 ,
const struct V_146 * V_147 )
{
const struct V_148 * V_149 = V_145 -> V_2 . V_150 ;
struct V_1 * V_2 = & V_145 -> V_2 ;
struct V_64 * V_151 ;
unsigned int V_152 = 0 ;
unsigned int V_3 ;
int V_105 = 0 , V_53 ;
T_2 V_121 ;
V_151 = F_35 ( V_2 , sizeof( * V_151 ) , V_153 ) ;
if ( ! V_151 )
return - V_154 ;
for ( V_53 = 0 ; V_53 < F_5 ( V_151 -> V_155 ) ; V_53 ++ )
V_151 -> V_155 [ V_53 ] . V_156 = V_157 [ V_53 ] ;
V_105 = F_36 ( V_2 , F_5 ( V_151 -> V_155 ) ,
V_151 -> V_155 ) ;
if ( V_105 ) {
F_16 ( V_2 , L_9 , V_105 ) ;
return V_105 ;
}
V_105 = F_37 ( F_5 ( V_151 -> V_155 ) ,
V_151 -> V_155 ) ;
if ( V_105 ) {
F_16 ( V_2 , L_10 , V_105 ) ;
return V_105 ;
}
V_151 -> V_158 = F_38 ( V_2 , L_11 ,
V_159 ) ;
if ( F_39 ( V_151 -> V_158 ) ) {
V_105 = F_40 ( V_151 -> V_158 ) ;
goto error;
}
if ( V_151 -> V_158 )
F_31 ( V_151 -> V_158 , 1 ) ;
F_41 ( V_145 , V_151 ) ;
V_151 -> V_56 = 0 ;
V_151 -> V_69 = F_42 ( V_145 , & V_160 ) ;
if ( F_39 ( V_151 -> V_69 ) ) {
V_105 = F_40 ( V_151 -> V_69 ) ;
F_16 ( V_2 , L_12 , V_105 ) ;
goto error;
}
V_105 = F_18 ( V_151 -> V_69 , V_5 , & V_3 ) ;
V_152 = V_3 << 12 ;
V_105 = F_18 ( V_151 -> V_69 , V_6 , & V_3 ) ;
V_152 |= V_3 << 4 ;
V_105 = F_18 ( V_151 -> V_69 , V_7 , & V_3 ) ;
V_152 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_152 != V_161 ) {
V_105 = - V_162 ;
F_16 ( V_2 , L_13 ,
V_152 , V_161 ) ;
goto error;
}
V_105 = F_18 ( V_151 -> V_69 , V_8 , & V_3 ) ;
if ( V_105 < 0 ) {
F_16 ( V_2 , L_14 , V_105 ) ;
goto error;
}
V_151 -> V_112 = F_43 ( V_2 , L_15 ) ;
if ( F_39 ( V_151 -> V_112 ) ) {
if ( F_40 ( V_151 -> V_112 ) != - V_163 ) {
V_105 = F_40 ( V_151 -> V_112 ) ;
goto error;
}
V_151 -> V_112 = NULL ;
}
V_151 -> V_140 = F_38 ( V_2 , L_16 ,
V_164 ) ;
if ( F_39 ( V_151 -> V_140 ) ) {
V_105 = F_40 ( V_151 -> V_140 ) ;
goto error;
}
if ( V_151 -> V_140 ) {
F_28 ( V_151 -> V_69 , V_29 ,
V_165 ) ;
if ( F_44 ( V_151 -> V_140 ) )
F_9 ( V_151 -> V_69 , V_30 ,
V_166 , 0 ) ;
}
if ( ! F_45 ( V_149 , L_17 , & V_121 ) )
F_9 ( V_151 -> V_69 , V_12 ,
V_167 , V_121 ) ;
if ( F_46 ( V_149 , L_18 ) )
V_151 -> V_141 = true ;
F_47 ( V_2 , L_19 , V_3 & 0xFF ) ;
V_105 = F_48 ( V_2 , & V_168 , & V_169 , 1 ) ;
if ( V_105 ) {
F_16 ( V_2 , L_20 , V_105 ) ;
goto error;
}
return 0 ;
error:
F_49 ( F_5 ( V_151 -> V_155 ) ,
V_151 -> V_155 ) ;
return V_105 ;
}
static int F_50 ( struct V_144 * V_145 )
{
struct V_64 * V_151 = F_51 ( V_145 ) ;
F_52 ( & V_145 -> V_2 ) ;
if ( V_151 -> V_158 )
F_31 ( V_151 -> V_158 , 0 ) ;
F_49 ( F_5 ( V_151 -> V_155 ) ,
V_151 -> V_155 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_64 * V_151 = F_54 ( V_2 ) ;
F_55 ( V_151 -> V_69 , true ) ;
if ( V_151 -> V_158 )
F_31 ( V_151 -> V_158 , 0 ) ;
F_49 ( F_5 ( V_151 -> V_155 ) ,
V_151 -> V_155 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_64 * V_151 = F_54 ( V_2 ) ;
int V_105 ;
V_105 = F_37 ( F_5 ( V_151 -> V_155 ) ,
V_151 -> V_155 ) ;
if ( V_105 ) {
F_16 ( V_2 , L_10 , V_105 ) ;
return V_105 ;
}
if ( V_151 -> V_158 )
F_31 ( V_151 -> V_158 , 1 ) ;
F_55 ( V_151 -> V_69 , false ) ;
V_105 = F_57 ( V_151 -> V_69 ) ;
if ( V_105 ) {
F_16 ( V_2 , L_21 , V_105 ) ;
return V_105 ;
}
return 0 ;
}
