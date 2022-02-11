static int F_1 ( const unsigned int * V_1 , T_1 V_2 , unsigned int V_3 )
{
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
if ( V_3 < V_1 [ V_4 ] )
break;
return V_4 > 0 ? V_4 - 1 : - V_5 ;
}
static int F_2 ( struct V_6 * V_7 )
{
bool V_8 = false ;
bool V_9 = false ;
unsigned int V_3 ;
int V_10 ;
V_10 = F_3 ( V_7 -> V_11 , V_12 , & V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_7 -> V_13 -> V_14 )
V_9 = ! ( V_3 & V_15 ) ;
if ( V_7 -> V_13 -> V_16 )
V_8 = ! ( V_3 & V_17 ) ;
F_4 ( & V_7 -> V_18 ) ;
V_10 = V_7 -> V_19 != V_9 || V_7 -> V_20 != V_8 ;
V_7 -> V_19 = V_9 ;
V_7 -> V_20 = V_8 ;
F_5 ( & V_7 -> V_18 ) ;
return V_10 ;
}
static bool F_6 ( struct V_6 * V_7 )
{
bool V_10 ;
F_4 ( & V_7 -> V_18 ) ;
V_10 = V_7 -> V_20 || V_7 -> V_19 ;
F_5 ( & V_7 -> V_18 ) ;
return V_10 ;
}
static int F_7 ( struct V_6 * V_7 )
{
unsigned int V_3 ;
int V_10 ;
if ( ! F_6 ( V_7 ) )
return 0 ;
V_10 = F_3 ( V_7 -> V_11 , V_21 , & V_3 ) ;
if ( V_10 < 0 )
return 0 ;
return ( V_3 & V_22 ) >> V_23 ;
}
static int F_8 ( struct V_6 * V_7 , bool V_24 )
{
int V_10 = 0 ;
if ( V_7 -> V_13 -> V_25 != V_26 ) {
F_9 ( V_7 -> V_27 , L_1 ) ;
return 0 ;
}
F_4 ( & V_7 -> V_18 ) ;
if ( V_7 -> V_28 != V_24 ) {
V_10 = F_10 ( V_7 -> V_11 , V_29 , V_30 ,
V_24 ? V_30 : 0 ) ;
if ( ! V_10 )
V_7 -> V_28 = V_24 ;
}
F_5 ( & V_7 -> V_18 ) ;
return V_10 ;
}
static inline int F_11 ( struct V_6 * V_7 )
{
return F_8 ( V_7 , true ) ;
}
static inline int F_12 ( struct V_6 * V_7 )
{
return F_8 ( V_7 , false ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
int V_10 ;
if ( F_6 ( V_7 ) ) {
V_10 = F_11 ( V_7 ) ;
if ( V_10 < 0 )
F_14 ( V_7 -> V_27 , L_2 ) ;
} else {
V_10 = F_12 ( V_7 ) ;
if ( V_10 < 0 )
F_14 ( V_7 -> V_27 , L_3 ) ;
}
return V_10 ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_10 ;
if ( V_7 -> V_13 -> V_31 ) {
V_10 = F_1 ( V_32 , F_16 ( V_32 ) ,
V_7 -> V_13 -> V_31 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_7 -> V_11 , V_33 ,
V_34 ,
V_10 << V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_36 ) {
V_10 = F_1 ( V_37 , F_16 ( V_37 ) ,
V_7 -> V_13 -> V_36 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_7 -> V_11 , V_33 ,
V_38 ,
V_10 << V_39 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_40 ) {
V_10 = F_1 ( V_41 , F_16 ( V_41 ) ,
V_7 -> V_13 -> V_40 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_7 -> V_11 , V_33 ,
V_42 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_17 ( struct V_6 * V_7 )
{
int V_10 ;
if ( V_7 -> V_13 -> V_43 ) {
V_10 = F_1 ( V_44 , F_16 ( V_44 ) ,
V_7 -> V_13 -> V_43 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_7 -> V_11 , V_45 ,
V_46 ,
V_10 << V_47 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_48 ) {
V_10 = F_1 ( V_44 , F_16 ( V_44 ) ,
V_7 -> V_13 -> V_48 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_7 -> V_11 , V_45 ,
V_49 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_10 ;
if ( V_7 -> V_13 -> V_50 ) {
V_10 = V_7 -> V_13 -> V_50 ;
V_10 = F_19 ( V_10 , 2400000 , 3000000 ) - 2400000 ;
V_10 /= 200000 ;
V_10 = F_10 ( V_7 -> V_11 , V_51 ,
V_52 ,
V_10 << V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_54 ) {
V_10 = V_7 -> V_13 -> V_54 ;
V_10 = F_19 ( V_10 , 3500000 , 4500000 ) - 3500000 ;
V_10 /= 20000 ;
V_10 = F_10 ( V_7 -> V_11 , V_51 ,
V_55 , V_10 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
bool V_56 = false ;
int V_10 = 0 ;
int V_3 ;
if ( V_7 -> V_13 -> V_57 ) {
V_3 = V_7 -> V_13 -> V_57 ;
V_3 = F_19 ( V_3 , 100 , 130 ) - 100 ;
V_3 /= 10 ;
V_10 = F_10 ( V_7 -> V_11 , V_58 ,
V_59 ,
V_3 << V_60 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_61 != V_62 ) {
V_3 = V_7 -> V_13 -> V_61 ;
V_3 = F_19 ( V_3 , 0 , 15 ) ;
V_3 /= 5 ;
V_3 = ~ V_3 & 0x3 ;
V_10 = F_10 ( V_7 -> V_11 , V_63 ,
V_64 ,
V_3 << V_65 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_7 -> V_13 -> V_66 != V_62 ) {
V_3 = V_7 -> V_13 -> V_66 ;
V_3 = F_19 ( V_3 , 40 , 55 ) - 40 ;
V_3 /= 5 ;
V_10 = F_10 ( V_7 -> V_11 , V_63 ,
V_67 ,
V_3 << V_68 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_7 -> V_13 -> V_69 != V_62 ) {
V_3 = V_7 -> V_13 -> V_69 ;
V_3 = F_19 ( V_3 , - 5 , 10 ) + 5 ;
V_3 /= 5 ;
V_3 = ~ V_3 & 0x3 ;
V_10 = F_10 ( V_7 -> V_11 , V_63 ,
V_70 ,
V_3 << V_71 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_7 -> V_13 -> V_72 != V_62 ) {
V_3 = V_7 -> V_13 -> V_72 ;
V_3 = F_19 ( V_3 , 50 , 65 ) - 50 ;
V_3 /= 5 ;
V_10 = F_10 ( V_7 -> V_11 , V_63 ,
V_73 ,
V_3 << V_74 ) ;
if ( V_10 < 0 )
return V_10 ;
V_56 = true ;
}
if ( V_56 ) {
V_10 = F_10 ( V_7 -> V_11 , V_75 ,
V_76 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_77 ) {
V_10 = F_10 ( V_7 -> V_11 , V_78 ,
V_79 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_80 !=
V_81 ) {
V_3 = V_7 -> V_13 -> V_80 & 0x3 ;
V_10 = F_10 ( V_7 -> V_11 , V_75 ,
V_82 ,
V_3 << V_83 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_7 -> V_11 , V_75 ,
V_84 ,
V_3 << V_85 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_86 ) {
V_3 = F_1 ( V_87 , F_16 ( V_87 ) ,
V_7 -> V_13 -> V_86 ) ;
if ( V_3 < 0 )
return V_3 ;
V_10 = F_10 ( V_7 -> V_11 , V_58 ,
V_88 ,
( V_3 & 0x3 ) << V_89 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return V_10 ;
}
static int F_21 ( struct V_6 * V_7 , bool V_90 )
{
return F_10 ( V_7 -> V_11 , V_29 , V_91 ,
V_90 ? V_91 : 0 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
unsigned int V_3 ;
int V_10 ;
V_10 = F_21 ( V_7 , true ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_15 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_17 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_18 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_20 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
if ( ! V_7 -> V_13 -> V_16 ) {
V_10 = F_10 ( V_7 -> V_11 , V_29 ,
V_93 ,
V_93 ) ;
if ( V_10 < 0 )
goto V_92;
}
V_10 = F_10 ( V_7 -> V_11 , V_94 , V_95 ,
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
V_10 = F_10 ( V_7 -> V_11 , V_102 , V_103 ,
V_3 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_10 ( V_7 -> V_11 , V_102 , V_104 , 0 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_2 ( V_7 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_13 ( V_7 ) ;
V_92:
F_21 ( V_7 , false ) ;
return V_10 ;
}
static T_2 F_23 ( int V_105 , void * V_106 )
{
struct V_6 * V_7 = V_106 ;
unsigned int V_107 , V_108 , V_109 ;
bool V_110 = false ;
int V_10 ;
V_10 = F_3 ( V_7 -> V_11 , V_21 , & V_107 ) ;
if ( V_10 < 0 ) {
F_24 ( V_7 -> V_27 , L_4 ) ;
return V_111 ;
}
V_10 = F_3 ( V_7 -> V_11 , V_112 , & V_109 ) ;
if ( V_10 < 0 ) {
F_24 ( V_7 -> V_27 , L_5 ) ;
return V_111 ;
}
V_10 = F_3 ( V_7 -> V_11 , V_12 , & V_108 ) ;
if ( V_10 < 0 ) {
F_24 ( V_7 -> V_27 , L_6 ) ;
return V_111 ;
}
if ( V_107 & V_113 ) {
F_14 ( V_7 -> V_27 , L_7 ) ;
F_12 ( V_7 ) ;
F_25 ( & V_7 -> V_114 ) ;
V_110 = true ;
}
if ( V_109 & ( V_115 | V_116 ) ) {
if ( V_109 & V_117 )
F_25 ( & V_7 -> V_114 ) ;
V_110 = true ;
}
if ( V_108 & ( V_118 | V_119 ) ) {
if ( F_2 ( V_7 ) > 0 ) {
F_13 ( V_7 ) ;
if ( V_7 -> V_13 -> V_14 )
F_25 ( & V_7 -> V_120 ) ;
if ( V_7 -> V_13 -> V_16 )
F_25 ( & V_7 -> V_8 ) ;
}
V_110 = true ;
}
return V_110 ? V_121 : V_111 ;
}
static int F_26 ( struct V_6 * V_7 , bool V_24 )
{
int V_10 ;
V_10 = F_21 ( V_7 , true ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_10 ( V_7 -> V_11 , V_122 , 0xff ,
V_24 ? V_123 : 0 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_10 ( V_7 -> V_11 , V_124 , 0xff ,
V_24 ? V_125 : 0 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_10 ( V_7 -> V_11 , V_102 , V_126 ,
V_24 ? V_126 : 0 ) ;
V_92:
F_21 ( V_7 , false ) ;
return V_10 ;
}
static inline int F_27 ( struct V_6 * V_7 )
{
return F_26 ( V_7 , true ) ;
}
static inline int F_28 ( struct V_6 * V_7 )
{
return F_26 ( V_7 , false ) ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_127 * V_128 )
{
const struct V_129 * V_13 = V_7 -> V_13 ;
int V_10 , V_105 = F_30 ( V_13 -> V_130 ) ;
V_10 = F_31 ( V_13 -> V_130 , V_131 , V_128 -> V_132 ) ;
if ( V_10 < 0 )
goto V_92;
V_10 = F_32 ( V_105 , NULL , F_23 ,
V_133 , V_128 -> V_132 , V_7 ) ;
if ( V_10 < 0 )
goto V_134;
V_10 = F_21 ( V_7 , true ) ;
if ( V_10 < 0 )
goto V_135;
V_10 = F_10 ( V_7 -> V_11 , V_136 ,
V_137 | V_138 ,
V_138 ) ;
if ( V_10 < 0 )
goto V_139;
F_21 ( V_7 , false ) ;
V_128 -> V_105 = V_105 ;
return 0 ;
V_139:
F_21 ( V_7 , false ) ;
V_135:
F_33 ( V_105 , V_7 ) ;
V_134:
F_34 ( V_13 -> V_130 ) ;
V_92:
V_128 -> V_105 = 0 ;
return V_10 ;
}
static int F_35 ( struct V_140 * V_141 ,
enum V_142 V_143 ,
union V_144 * V_3 )
{
struct V_6 * V_7 =
F_36 ( V_141 , struct V_6 , V_120 ) ;
if ( V_143 == V_145 ) {
V_3 -> V_146 = V_7 -> V_19 ;
return 0 ;
}
return - V_5 ;
}
static int F_37 ( struct V_140 * V_141 ,
enum V_142 V_143 ,
union V_144 * V_3 )
{
struct V_6 * V_7 =
F_36 ( V_141 , struct V_6 , V_8 ) ;
if ( V_143 == V_145 ) {
V_3 -> V_146 = V_7 -> V_20 ;
return 0 ;
}
return - V_5 ;
}
static int F_38 ( struct V_140 * V_141 ,
enum V_142 V_143 ,
union V_144 * V_3 )
{
struct V_6 * V_7 =
F_36 ( V_141 , struct V_6 , V_114 ) ;
const struct V_129 * V_13 = V_7 -> V_13 ;
int V_10 ;
V_10 = F_2 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_143 ) {
case V_147 :
if ( ! F_6 ( V_7 ) ) {
V_3 -> V_146 = V_148 ;
break;
}
if ( F_7 ( V_7 ) )
V_3 -> V_146 = V_149 ;
else
V_3 -> V_146 = V_150 ;
break;
case V_151 :
if ( ! F_6 ( V_7 ) )
return - V_152 ;
switch ( F_7 ( V_7 ) ) {
case 1 :
V_3 -> V_146 = V_153 ;
break;
case 2 :
V_3 -> V_146 = V_154 ;
break;
default:
V_3 -> V_146 = V_155 ;
break;
}
break;
case V_156 :
V_3 -> V_146 = V_13 -> V_157 . V_158 ;
break;
case V_159 :
V_3 -> V_146 = V_13 -> V_157 . V_160 ;
break;
case V_161 :
V_3 -> V_146 = V_13 -> V_157 . V_162 ;
break;
case V_163 :
V_3 -> V_146 = V_13 -> V_157 . V_164 ;
break;
case V_165 :
V_3 -> V_166 = V_13 -> V_157 . V_132 ;
break;
default:
return - V_5 ;
}
return 0 ;
}
static bool F_39 ( struct V_167 * V_27 , unsigned int V_168 )
{
switch ( V_168 ) {
case V_169 :
case V_112 :
case V_12 :
case V_170 :
case V_171 :
case V_172 :
case V_21 :
case V_173 :
return true ;
}
return false ;
}
static bool F_40 ( struct V_167 * V_27 , unsigned int V_168 )
{
switch ( V_168 ) {
case V_33 :
case V_45 :
case V_51 :
case V_136 :
case V_102 :
case V_75 :
case V_78 :
case V_94 :
case V_58 :
case V_63 :
case V_122 :
case V_124 :
case V_174 :
case V_29 :
case V_175 :
case V_176 :
return true ;
}
return F_39 ( V_27 , V_168 ) ;
}
static int F_41 ( struct V_127 * V_128 ,
const struct V_177 * V_178 )
{
static char * V_114 [] = { L_8 } ;
const struct V_129 * V_13 ;
struct V_167 * V_27 = & V_128 -> V_27 ;
struct V_6 * V_7 ;
int V_10 ;
V_13 = V_27 -> V_179 ;
if ( ! V_13 )
return - V_5 ;
if ( ! V_13 -> V_14 && ! V_13 -> V_16 )
return - V_5 ;
V_7 = F_42 ( V_27 , sizeof( * V_7 ) , V_180 ) ;
if ( ! V_7 )
return - V_181 ;
F_43 ( V_128 , V_7 ) ;
F_44 ( & V_7 -> V_18 ) ;
V_7 -> V_27 = & V_128 -> V_27 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = F_45 ( V_128 , & V_182 ) ;
if ( F_46 ( V_7 -> V_11 ) )
return F_47 ( V_7 -> V_11 ) ;
V_10 = F_22 ( V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_7 -> V_13 -> V_14 ) {
V_7 -> V_120 . V_132 = L_9 ;
V_7 -> V_120 . type = V_183 ;
V_7 -> V_120 . V_184 = F_35 ;
V_7 -> V_120 . V_185 = V_186 ;
V_7 -> V_120 . V_187 = F_16 ( V_186 ) ;
V_7 -> V_120 . V_188 = V_114 ;
V_7 -> V_120 . V_189 = F_16 ( V_114 ) ;
V_10 = F_48 ( V_27 , & V_7 -> V_120 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_7 -> V_13 -> V_16 ) {
V_7 -> V_8 . V_132 = L_10 ;
V_7 -> V_8 . type = V_190 ;
V_7 -> V_8 . V_184 = F_37 ;
V_7 -> V_8 . V_185 = V_191 ;
V_7 -> V_8 . V_187 = F_16 ( V_191 ) ;
V_7 -> V_8 . V_188 = V_114 ;
V_7 -> V_8 . V_189 = F_16 ( V_114 ) ;
V_10 = F_48 ( V_27 , & V_7 -> V_8 ) ;
if ( V_10 < 0 ) {
if ( V_7 -> V_13 -> V_14 )
F_49 ( & V_7 -> V_120 ) ;
return V_10 ;
}
}
V_7 -> V_114 . V_132 = L_8 ;
V_7 -> V_114 . type = V_192 ;
V_7 -> V_114 . V_184 = F_38 ;
V_7 -> V_114 . V_185 = V_193 ;
V_7 -> V_114 . V_187 = F_16 ( V_193 ) ;
V_10 = F_48 ( V_27 , & V_7 -> V_114 ) ;
if ( V_10 < 0 ) {
if ( V_7 -> V_13 -> V_16 )
F_49 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_13 -> V_14 )
F_49 ( & V_7 -> V_120 ) ;
return V_10 ;
}
if ( V_13 -> V_130 >= 0 ) {
V_10 = F_29 ( V_7 , V_128 ) ;
if ( V_10 < 0 ) {
F_24 ( V_27 , L_11 , V_10 ) ;
F_24 ( V_27 , L_12 ) ;
} else {
F_27 ( V_7 ) ;
}
}
return 0 ;
}
static int F_50 ( struct V_127 * V_128 )
{
struct V_6 * V_7 = F_51 ( V_128 ) ;
if ( V_128 -> V_105 ) {
F_28 ( V_7 ) ;
F_33 ( V_128 -> V_105 , V_7 ) ;
F_34 ( V_7 -> V_13 -> V_130 ) ;
}
F_49 ( & V_7 -> V_114 ) ;
if ( V_7 -> V_13 -> V_16 )
F_49 ( & V_7 -> V_8 ) ;
if ( V_7 -> V_13 -> V_14 )
F_49 ( & V_7 -> V_120 ) ;
return 0 ;
}
