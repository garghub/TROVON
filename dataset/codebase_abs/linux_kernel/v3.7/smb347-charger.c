static int F_1 ( const unsigned int * V_1 , T_1 V_2 , unsigned int V_3 )
{
if ( V_3 >= V_2 )
return - V_4 ;
return V_1 [ V_3 ] ;
}
static int F_2 ( const unsigned int * V_1 , T_1 V_2 , unsigned int V_3 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
if ( V_3 < V_1 [ V_5 ] )
break;
return V_5 > 0 ? V_5 - 1 : - V_4 ;
}
static int F_3 ( struct V_6 * V_7 )
{
bool V_8 = false ;
bool V_9 = false ;
unsigned int V_3 ;
int V_10 ;
V_10 = F_4 ( V_7 -> V_11 , V_12 , & V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_7 -> V_13 -> V_14 )
V_9 = ! ( V_3 & V_15 ) ;
if ( V_7 -> V_13 -> V_16 )
V_8 = ! ( V_3 & V_17 ) ;
F_5 ( & V_7 -> V_18 ) ;
V_10 = V_7 -> V_19 != V_9 || V_7 -> V_20 != V_8 ;
V_7 -> V_19 = V_9 ;
V_7 -> V_20 = V_8 ;
F_6 ( & V_7 -> V_18 ) ;
return V_10 ;
}
static bool F_7 ( struct V_6 * V_7 )
{
bool V_10 ;
F_5 ( & V_7 -> V_18 ) ;
V_10 = V_7 -> V_20 || V_7 -> V_19 ;
F_6 ( & V_7 -> V_18 ) ;
return V_10 ;
}
static int F_8 ( struct V_6 * V_7 )
{
unsigned int V_3 ;
int V_10 ;
if ( ! F_7 ( V_7 ) )
return 0 ;
V_10 = F_4 ( V_7 -> V_11 , V_21 , & V_3 ) ;
if ( V_10 < 0 )
return 0 ;
return ( V_3 & V_22 ) >> V_23 ;
}
static int F_9 ( struct V_6 * V_7 , bool V_24 )
{
int V_10 = 0 ;
if ( V_7 -> V_13 -> V_25 != V_26 ) {
F_10 ( V_7 -> V_27 , L_1 ) ;
return 0 ;
}
F_5 ( & V_7 -> V_18 ) ;
if ( V_7 -> V_28 != V_24 ) {
V_10 = F_11 ( V_7 -> V_11 , V_29 , V_30 ,
V_24 ? V_30 : 0 ) ;
if ( ! V_10 )
V_7 -> V_28 = V_24 ;
}
F_6 ( & V_7 -> V_18 ) ;
return V_10 ;
}
static inline int F_12 ( struct V_6 * V_7 )
{
return F_9 ( V_7 , true ) ;
}
static inline int F_13 ( struct V_6 * V_7 )
{
return F_9 ( V_7 , false ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
int V_10 ;
if ( F_7 ( V_7 ) ) {
V_10 = F_12 ( V_7 ) ;
if ( V_10 < 0 )
F_15 ( V_7 -> V_27 , L_2 ) ;
} else {
V_10 = F_13 ( V_7 ) ;
if ( V_10 < 0 )
F_15 ( V_7 -> V_27 , L_3 ) ;
}
return V_10 ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_10 ;
if ( V_7 -> V_13 -> V_31 ) {
V_10 = F_2 ( V_32 , F_17 ( V_32 ) ,
V_7 -> V_13 -> V_31 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_7 -> V_11 , V_33 ,
V_34 ,
V_10 << V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_36 ) {
V_10 = F_2 ( V_37 , F_17 ( V_37 ) ,
V_7 -> V_13 -> V_36 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_7 -> V_11 , V_33 ,
V_38 ,
V_10 << V_39 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_40 ) {
V_10 = F_2 ( V_41 , F_17 ( V_41 ) ,
V_7 -> V_13 -> V_40 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_7 -> V_11 , V_33 ,
V_42 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_10 ;
if ( V_7 -> V_13 -> V_43 ) {
V_10 = F_2 ( V_44 , F_17 ( V_44 ) ,
V_7 -> V_13 -> V_43 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_7 -> V_11 , V_45 ,
V_46 ,
V_10 << V_47 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_48 ) {
V_10 = F_2 ( V_44 , F_17 ( V_44 ) ,
V_7 -> V_13 -> V_48 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_7 -> V_11 , V_45 ,
V_49 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
int V_10 ;
if ( V_7 -> V_13 -> V_50 ) {
V_10 = V_7 -> V_13 -> V_50 ;
V_10 = F_20 ( V_10 , 2400000 , 3000000 ) - 2400000 ;
V_10 /= 200000 ;
V_10 = F_11 ( V_7 -> V_11 , V_51 ,
V_52 ,
V_10 << V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_54 ) {
V_10 = V_7 -> V_13 -> V_54 ;
V_10 = F_20 ( V_10 , 3500000 , 4500000 ) - 3500000 ;
V_10 /= 20000 ;
V_10 = F_11 ( V_7 -> V_11 , V_51 ,
V_55 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
bool V_56 = false ;
int V_10 = 0 ;
int V_3 ;
if ( V_7 -> V_13 -> V_57 ) {
V_3 = V_7 -> V_13 -> V_57 ;
V_3 = F_20 ( V_3 , 100 , 130 ) - 100 ;
V_3 /= 10 ;
V_10 = F_11 ( V_7 -> V_11 , V_58 ,
V_59 ,
V_3 << V_60 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_61 != V_62 ) {
V_3 = V_7 -> V_13 -> V_61 ;
V_3 = F_20 ( V_3 , 0 , 15 ) ;
V_3 /= 5 ;
V_3 = ~ V_3 & 0x3 ;
V_10 = F_11 ( V_7 -> V_11 , V_63 ,
V_64 ,
V_3 << V_65 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_7 -> V_13 -> V_66 != V_62 ) {
V_3 = V_7 -> V_13 -> V_66 ;
V_3 = F_20 ( V_3 , 40 , 55 ) - 40 ;
V_3 /= 5 ;
V_10 = F_11 ( V_7 -> V_11 , V_63 ,
V_67 ,
V_3 << V_68 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_7 -> V_13 -> V_69 != V_62 ) {
V_3 = V_7 -> V_13 -> V_69 ;
V_3 = F_20 ( V_3 , - 5 , 10 ) + 5 ;
V_3 /= 5 ;
V_3 = ~ V_3 & 0x3 ;
V_10 = F_11 ( V_7 -> V_11 , V_63 ,
V_70 ,
V_3 << V_71 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_7 -> V_13 -> V_72 != V_62 ) {
V_3 = V_7 -> V_13 -> V_72 ;
V_3 = F_20 ( V_3 , 50 , 65 ) - 50 ;
V_3 /= 5 ;
V_10 = F_11 ( V_7 -> V_11 , V_63 ,
V_73 ,
V_3 << V_74 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_56 ) {
V_10 = F_11 ( V_7 -> V_11 , V_75 ,
V_76 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_77 ) {
V_10 = F_11 ( V_7 -> V_11 , V_78 ,
V_79 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_80 !=
V_81 ) {
V_3 = V_7 -> V_13 -> V_80 & 0x3 ;
V_10 = F_11 ( V_7 -> V_11 , V_75 ,
V_82 ,
V_3 << V_83 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_7 -> V_11 , V_75 ,
V_84 ,
V_3 << V_85 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_86 ) {
V_3 = F_2 ( V_87 , F_17 ( V_87 ) ,
V_7 -> V_13 -> V_86 ) ;
if ( V_3 < 0 )
return V_3 ;
V_10 = F_11 ( V_7 -> V_11 , V_58 ,
V_88 ,
( V_3 & 0x3 ) << V_89 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return V_10 ;
}
static int F_22 ( struct V_6 * V_7 , bool V_90 )
{
return F_11 ( V_7 -> V_11 , V_29 , V_91 ,
V_90 ? V_91 : 0 ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
unsigned int V_3 ;
int V_10 ;
V_10 = F_22 ( V_7 , true ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_16 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_18 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_19 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_21 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
if ( ! V_7 -> V_13 -> V_16 ) {
V_10 = F_11 ( V_7 -> V_11 , V_29 ,
V_93 ,
V_93 ) ;
if ( V_10 < 0 )
goto V_92;
}
V_10 = F_11 ( V_7 -> V_11 , V_94 , V_95 ,
V_7 -> V_13 -> V_96 ? V_97 : 0 ) ;
if ( V_10 < 0 )
goto V_92;
switch ( V_7 -> V_13 -> V_25 ) {
case V_98 :
V_3 = V_99 ;
break;
case V_100 :
V_3 = V_101 ;
break;
default:
V_3 = 0 ;
break;
}
V_10 = F_11 ( V_7 -> V_11 , V_102 , V_103 ,
V_3 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_11 ( V_7 -> V_11 , V_102 , V_104 , 0 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_14 ( V_7 ) ;
V_92:
F_22 ( V_7 , false ) ;
return V_10 ;
}
static T_2 F_24 ( int V_105 , void * V_106 )
{
struct V_6 * V_7 = V_106 ;
unsigned int V_107 , V_108 , V_109 , V_110 ;
bool V_111 = false ;
int V_10 ;
V_10 = F_4 ( V_7 -> V_11 , V_21 , & V_107 ) ;
if ( V_10 < 0 ) {
F_25 ( V_7 -> V_27 , L_4 ) ;
return V_112 ;
}
V_10 = F_4 ( V_7 -> V_11 , V_113 , & V_108 ) ;
if ( V_10 < 0 ) {
F_25 ( V_7 -> V_27 , L_5 ) ;
return V_112 ;
}
V_10 = F_4 ( V_7 -> V_11 , V_114 , & V_109 ) ;
if ( V_10 < 0 ) {
F_25 ( V_7 -> V_27 , L_6 ) ;
return V_112 ;
}
V_10 = F_4 ( V_7 -> V_11 , V_12 , & V_110 ) ;
if ( V_10 < 0 ) {
F_25 ( V_7 -> V_27 , L_7 ) ;
return V_112 ;
}
if ( V_107 & V_115 ) {
F_15 ( V_7 -> V_27 , L_8 ) ;
F_26 ( & V_7 -> V_116 ) ;
V_111 = true ;
}
if ( V_108 & ( V_117 | V_118 ) ) {
if ( V_108 & V_119 )
F_26 ( & V_7 -> V_116 ) ;
F_10 ( V_7 -> V_27 , L_9 ) ;
V_111 = true ;
}
if ( V_109 & V_120 ) {
F_10 ( V_7 -> V_27 , L_10 ) ;
if ( V_109 & V_121 )
F_25 ( V_7 -> V_27 , L_11 ) ;
F_26 ( & V_7 -> V_116 ) ;
V_111 = true ;
}
if ( V_110 & ( V_122 | V_123 ) ) {
if ( F_3 ( V_7 ) > 0 ) {
F_14 ( V_7 ) ;
if ( V_7 -> V_13 -> V_14 )
F_26 ( & V_7 -> V_124 ) ;
if ( V_7 -> V_13 -> V_16 )
F_26 ( & V_7 -> V_8 ) ;
}
V_111 = true ;
}
return V_111 ? V_125 : V_112 ;
}
static int F_27 ( struct V_6 * V_7 , bool V_24 )
{
int V_10 ;
V_10 = F_22 ( V_7 , true ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_11 ( V_7 -> V_11 , V_126 , 0xff ,
V_24 ? V_127 : 0 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_11 ( V_7 -> V_11 , V_128 , 0xff ,
V_24 ? ( V_129 |
V_130 ) : 0 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_11 ( V_7 -> V_11 , V_102 , V_131 ,
V_24 ? V_131 : 0 ) ;
V_92:
F_22 ( V_7 , false ) ;
return V_10 ;
}
static inline int F_28 ( struct V_6 * V_7 )
{
return F_27 ( V_7 , true ) ;
}
static inline int F_29 ( struct V_6 * V_7 )
{
return F_27 ( V_7 , false ) ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_132 * V_133 )
{
const struct V_134 * V_13 = V_7 -> V_13 ;
int V_10 , V_105 = F_31 ( V_13 -> V_135 ) ;
V_10 = F_32 ( V_13 -> V_135 , V_136 , V_133 -> V_137 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_33 ( V_105 , NULL , F_24 ,
V_138 , V_133 -> V_137 , V_7 ) ;
if ( V_10 < 0 )
goto V_139;
V_10 = F_22 ( V_7 , true ) ;
if ( V_10 < 0 )
goto V_140;
V_10 = F_11 ( V_7 -> V_11 , V_141 ,
V_142 | V_143 ,
V_143 ) ;
if ( V_10 < 0 )
goto V_144;
F_22 ( V_7 , false ) ;
V_133 -> V_105 = V_105 ;
return 0 ;
V_144:
F_22 ( V_7 , false ) ;
V_140:
F_34 ( V_105 , V_7 ) ;
V_139:
F_35 ( V_13 -> V_135 ) ;
V_92:
V_133 -> V_105 = 0 ;
return V_10 ;
}
static int F_36 ( struct V_6 * V_7 )
{
int V_10 , V_145 ;
unsigned int V_146 ;
if ( ! F_7 ( V_7 ) )
return - V_147 ;
V_10 = F_4 ( V_7 -> V_11 , V_148 , & V_146 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_146 & 0x20 ) {
V_145 = F_1 ( V_32 , F_17 ( V_32 ) , V_146 & 7 ) ;
} else {
V_146 >>= 3 ;
V_145 = F_1 ( V_37 , F_17 ( V_37 ) , V_146 & 7 ) ;
}
return V_145 ;
}
static int F_37 ( struct V_6 * V_7 )
{
int V_10 , V_145 ;
unsigned int V_146 ;
if ( ! F_7 ( V_7 ) )
return - V_147 ;
V_10 = F_4 ( V_7 -> V_11 , V_149 , & V_146 ) ;
if ( V_10 < 0 )
return V_10 ;
V_146 &= V_150 ;
if ( V_146 > 0x3d )
V_146 = 0x3d ;
V_145 = 3500000 + V_146 * 20000 ;
return V_145 ;
}
static int F_38 ( struct V_151 * V_152 ,
enum V_153 V_154 ,
union V_155 * V_3 )
{
struct V_6 * V_7 =
F_39 ( V_152 , struct V_6 , V_124 ) ;
int V_10 ;
switch ( V_154 ) {
case V_156 :
V_3 -> V_145 = V_7 -> V_19 ;
break;
case V_157 :
V_10 = F_37 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
else
V_3 -> V_145 = V_10 ;
break;
case V_158 :
V_10 = F_36 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
else
V_3 -> V_145 = V_10 ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static int F_40 ( struct V_151 * V_152 ,
enum V_153 V_154 ,
union V_155 * V_3 )
{
struct V_6 * V_7 =
F_39 ( V_152 , struct V_6 , V_8 ) ;
int V_10 ;
switch ( V_154 ) {
case V_156 :
V_3 -> V_145 = V_7 -> V_20 ;
break;
case V_157 :
V_10 = F_37 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
else
V_3 -> V_145 = V_10 ;
break;
case V_158 :
V_10 = F_36 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
else
V_3 -> V_145 = V_10 ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
int V_10 , V_159 ;
unsigned int V_3 ;
if ( ! F_7 ( V_7 ) )
return V_160 ;
V_10 = F_4 ( V_7 -> V_11 , V_21 , & V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ( V_3 & V_115 ) ||
( V_3 & V_161 ) ) {
V_159 = V_162 ;
} else {
if ( ( V_3 & V_22 ) >> V_23 ) {
V_159 = V_163 ;
} else if ( V_3 & V_164 ) {
V_159 = V_165 ;
} else {
V_159 = V_162 ;
}
}
return V_159 ;
}
static int F_42 ( struct V_151 * V_152 ,
enum V_153 V_154 ,
union V_155 * V_3 )
{
struct V_6 * V_7 =
F_39 ( V_152 , struct V_6 , V_116 ) ;
const struct V_134 * V_13 = V_7 -> V_13 ;
int V_10 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_154 ) {
case V_166 :
V_10 = F_41 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
V_3 -> V_145 = V_10 ;
break;
case V_167 :
if ( ! F_7 ( V_7 ) )
return - V_147 ;
switch ( F_8 ( V_7 ) ) {
case 1 :
V_3 -> V_145 = V_168 ;
break;
case 2 :
V_3 -> V_145 = V_169 ;
break;
default:
V_3 -> V_145 = V_170 ;
break;
}
break;
case V_171 :
V_3 -> V_145 = V_13 -> V_172 . V_173 ;
break;
case V_174 :
V_3 -> V_145 = V_13 -> V_172 . V_175 ;
break;
case V_176 :
V_3 -> V_145 = V_13 -> V_172 . V_177 ;
break;
case V_178 :
V_3 -> V_145 = V_13 -> V_172 . V_179 ;
break;
case V_180 :
V_3 -> V_181 = V_13 -> V_172 . V_137 ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static bool F_43 ( struct V_182 * V_27 , unsigned int V_183 )
{
switch ( V_183 ) {
case V_184 :
case V_113 :
case V_12 :
case V_185 :
case V_149 :
case V_148 :
case V_21 :
case V_186 :
return true ;
}
return false ;
}
static bool F_44 ( struct V_182 * V_27 , unsigned int V_183 )
{
switch ( V_183 ) {
case V_33 :
case V_45 :
case V_51 :
case V_141 :
case V_102 :
case V_75 :
case V_78 :
case V_94 :
case V_58 :
case V_63 :
case V_126 :
case V_128 :
case V_187 :
case V_29 :
case V_188 :
case V_189 :
return true ;
}
return F_43 ( V_27 , V_183 ) ;
}
static int F_45 ( struct V_132 * V_133 ,
const struct V_190 * V_191 )
{
static char * V_116 [] = { L_12 } ;
const struct V_134 * V_13 ;
struct V_182 * V_27 = & V_133 -> V_27 ;
struct V_6 * V_7 ;
int V_10 ;
V_13 = V_27 -> V_192 ;
if ( ! V_13 )
return - V_4 ;
if ( ! V_13 -> V_14 && ! V_13 -> V_16 )
return - V_4 ;
V_7 = F_46 ( V_27 , sizeof( * V_7 ) , V_193 ) ;
if ( ! V_7 )
return - V_194 ;
F_47 ( V_133 , V_7 ) ;
F_48 ( & V_7 -> V_18 ) ;
V_7 -> V_27 = & V_133 -> V_27 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = F_49 ( V_133 , & V_195 ) ;
if ( F_50 ( V_7 -> V_11 ) )
return F_51 ( V_7 -> V_11 ) ;
V_10 = F_23 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_7 -> V_13 -> V_14 ) {
V_7 -> V_124 . V_137 = L_13 ;
V_7 -> V_124 . type = V_196 ;
V_7 -> V_124 . V_197 = F_38 ;
V_7 -> V_124 . V_198 = V_199 ;
V_7 -> V_124 . V_200 = F_17 ( V_199 ) ;
V_7 -> V_124 . V_201 = V_116 ;
V_7 -> V_124 . V_202 = F_17 ( V_116 ) ;
V_10 = F_52 ( V_27 , & V_7 -> V_124 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_16 ) {
V_7 -> V_8 . V_137 = L_14 ;
V_7 -> V_8 . type = V_203 ;
V_7 -> V_8 . V_197 = F_40 ;
V_7 -> V_8 . V_198 = V_204 ;
V_7 -> V_8 . V_200 = F_17 ( V_204 ) ;
V_7 -> V_8 . V_201 = V_116 ;
V_7 -> V_8 . V_202 = F_17 ( V_116 ) ;
V_10 = F_52 ( V_27 , & V_7 -> V_8 ) ;
if ( V_10 < 0 ) {
if ( V_7 -> V_13 -> V_14 )
F_53 ( & V_7 -> V_124 ) ;
return V_10 ;
}
}
V_7 -> V_116 . V_137 = L_12 ;
V_7 -> V_116 . type = V_205 ;
V_7 -> V_116 . V_197 = F_42 ;
V_7 -> V_116 . V_198 = V_206 ;
V_7 -> V_116 . V_200 = F_17 ( V_206 ) ;
V_10 = F_52 ( V_27 , & V_7 -> V_116 ) ;
if ( V_10 < 0 ) {
if ( V_7 -> V_13 -> V_16 )
F_53 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_13 -> V_14 )
F_53 ( & V_7 -> V_124 ) ;
return V_10 ;
}
if ( V_13 -> V_135 >= 0 ) {
V_10 = F_30 ( V_7 , V_133 ) ;
if ( V_10 < 0 ) {
F_25 ( V_27 , L_15 , V_10 ) ;
F_25 ( V_27 , L_16 ) ;
} else {
F_28 ( V_7 ) ;
}
}
return 0 ;
}
static int F_54 ( struct V_132 * V_133 )
{
struct V_6 * V_7 = F_55 ( V_133 ) ;
if ( V_133 -> V_105 ) {
F_29 ( V_7 ) ;
F_34 ( V_133 -> V_105 , V_7 ) ;
F_35 ( V_7 -> V_13 -> V_135 ) ;
}
F_53 ( & V_7 -> V_116 ) ;
if ( V_7 -> V_13 -> V_16 )
F_53 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_13 -> V_14 )
F_53 ( & V_7 -> V_124 ) ;
return 0 ;
}
