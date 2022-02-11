static bool F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , const T_1 V_4 )
{
unsigned int V_5 ;
T_2 V_6 ;
if ( F_3 ( V_2 ) )
return;
for ( V_5 = 0 ; V_5 < 200 ; V_5 ++ ) {
F_4 ( V_2 , V_7 , & V_6 ) ;
if ( ( F_5 ( V_6 , V_8 ) == V_4 ) ||
( F_5 ( V_6 , V_9 ) == V_4 ) ||
( F_5 ( V_6 , V_10 ) == V_4 ) ||
( F_5 ( V_6 , V_11 ) == V_4 ) )
break;
F_6 ( V_12 ) ;
}
if ( V_5 == 200 )
F_7 ( V_2 , L_1 ) ;
F_8 ( V_2 , V_13 , ~ 0 ) ;
F_8 ( V_2 , V_7 , ~ 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
void T_3 * V_14 = F_10 ( 0x1F040000 , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
F_11 ( V_2 -> V_17 , V_14 , V_15 ) ;
F_12 ( V_14 ) ;
return 0 ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return - V_16 ;
}
static void F_13 ( struct V_18 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
T_2 V_6 ;
F_4 ( V_2 , V_20 , & V_6 ) ;
V_17 -> V_21 = ! ! F_5 ( V_6 , V_22 ) ;
V_17 -> V_23 = ! ! F_5 ( V_6 , V_24 ) ;
V_17 -> V_25 =
! ! F_5 ( V_6 , V_26 ) ;
V_17 -> V_27 =
! ! F_5 ( V_6 , V_28 ) ;
}
static void F_14 ( struct V_18 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
T_2 V_6 = 0 ;
F_15 ( & V_6 , V_22 , ! ! V_17 -> V_21 ) ;
F_15 ( & V_6 , V_24 , ! ! V_17 -> V_23 ) ;
F_15 ( & V_6 , V_26 ,
! ! V_17 -> V_25 ) ;
F_15 ( & V_6 , V_28 ,
! ! V_17 -> V_27 ) ;
F_8 ( V_2 , V_20 , V_6 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_18 V_17 ;
T_2 V_6 ;
F_4 ( V_2 , V_20 , & V_6 ) ;
V_17 . V_19 = V_2 ;
V_17 . V_29 = F_13 ;
V_17 . V_30 = F_14 ;
switch ( F_5 ( V_6 , V_31 ) )
{
case 0 :
V_17 . V_32 = V_33 ;
break;
case 1 :
V_17 . V_32 = V_34 ;
break;
default:
V_17 . V_32 = V_35 ;
break;
}
V_17 . V_21 = 0 ;
V_17 . V_23 = 0 ;
V_17 . V_25 = 0 ;
V_17 . V_27 = 0 ;
F_17 ( & V_17 , V_36 , V_2 -> V_17 ,
V_15 / sizeof( V_37 ) ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_19 ( V_2 ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return F_21 ( V_2 ) ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
return - V_38 ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return - V_38 ;
}
static void F_22 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_2 V_6 ;
switch ( V_40 -> V_41 ) {
case V_42 :
F_4 ( V_2 , V_43 , & V_6 ) ;
F_15 ( & V_6 , V_44 , 1 ) ;
F_8 ( V_2 , V_43 , V_6 ) ;
break;
case V_45 :
F_4 ( V_2 , V_46 , & V_6 ) ;
F_15 ( & V_6 , V_47 , 1 ) ;
F_15 ( & V_6 , V_48 , 1 ) ;
F_15 ( & V_6 , V_49 , 1 ) ;
F_8 ( V_2 , V_46 , V_6 ) ;
F_4 ( V_2 , V_50 , & V_6 ) ;
F_15 ( & V_6 , V_51 , 1 ) ;
F_8 ( V_2 , V_50 , V_6 ) ;
break;
default:
break;
}
}
static void F_23 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_52 * V_53 ;
switch ( V_40 -> V_41 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_53 = F_24 ( V_40 , V_58 ) ;
F_8 ( V_2 , F_25 ( V_40 -> V_41 ) ,
V_53 -> V_59 ) ;
break;
case V_60 :
V_53 = F_24 ( V_40 , V_58 ) ;
F_8 ( V_2 , F_25 ( 5 ) ,
V_53 -> V_59 ) ;
break;
default:
break;
}
}
static void F_26 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_2 V_6 ;
switch ( V_40 -> V_41 ) {
case V_42 :
F_4 ( V_2 , V_43 , & V_6 ) ;
F_15 ( & V_6 , V_44 , 0 ) ;
F_8 ( V_2 , V_43 , V_6 ) ;
break;
case V_45 :
F_4 ( V_2 , V_46 , & V_6 ) ;
F_15 ( & V_6 , V_47 , 0 ) ;
F_15 ( & V_6 , V_48 , 0 ) ;
F_15 ( & V_6 , V_49 , 0 ) ;
F_8 ( V_2 , V_46 , V_6 ) ;
F_4 ( V_2 , V_50 , & V_6 ) ;
F_15 ( & V_6 , V_51 , 0 ) ;
F_8 ( V_2 , V_50 , V_6 ) ;
F_27 ( & V_2 -> V_61 ) ;
F_27 ( & V_2 -> V_62 ) ;
break;
default:
break;
}
}
static char * F_28 ( struct V_1 * V_2 )
{
if ( F_29 ( V_2 , V_63 ) )
return V_64 ;
else
return V_65 ;
}
static int F_30 ( struct V_1 * V_2 ,
const T_1 * V_19 , const T_4 V_66 )
{
T_2 V_6 ;
V_6 = 0 ;
F_15 ( & V_6 , V_67 , 1 ) ;
F_8 ( V_2 , V_68 , V_6 ) ;
F_31 ( V_2 , V_69 ,
V_19 , V_66 ) ;
F_8 ( V_2 , V_68 , 0x00000 ) ;
F_8 ( V_2 , V_68 , 0x00001 ) ;
F_8 ( V_2 , V_70 , 0 ) ;
F_8 ( V_2 , V_71 , 0 ) ;
return 0 ;
}
static bool F_32 ( struct V_52 * V_53 )
{
struct V_72 * V_73 = V_53 -> V_74 ;
T_2 V_75 ;
if ( V_53 -> V_40 -> V_41 == V_42 ) {
F_33 ( V_73 -> V_76 , 1 , & V_75 ) ;
return ( ! F_5 ( V_75 , V_77 ) ) ;
} else {
F_33 ( V_73 -> V_76 , 1 , & V_75 ) ;
return ( ! F_5 ( V_75 , V_78 ) ) ;
}
}
static void F_34 ( struct V_52 * V_53 )
{
struct V_72 * V_73 = V_53 -> V_74 ;
struct V_79 * V_80 = F_35 ( V_53 -> V_81 ) ;
struct V_1 * V_2 = V_53 -> V_40 -> V_2 ;
T_2 V_75 ;
if ( V_53 -> V_40 -> V_41 == V_42 ) {
F_33 ( V_73 -> V_76 , 0 , & V_75 ) ;
F_15 ( & V_75 , V_82 , V_80 -> V_83 ) ;
F_36 ( V_73 -> V_76 , 0 , V_75 ) ;
F_33 ( V_73 -> V_76 , 1 , & V_75 ) ;
F_15 ( & V_75 , V_77 , 0 ) ;
F_36 ( V_73 -> V_76 , 1 , V_75 ) ;
F_8 ( V_2 , V_84 ,
V_53 -> V_59 ) ;
} else {
F_33 ( V_73 -> V_76 , 1 , & V_75 ) ;
F_15 ( & V_75 , V_78 , 1 ) ;
F_36 ( V_73 -> V_76 , 1 , V_75 ) ;
}
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
V_73 = V_2 -> V_85 [ 0 ] . V_86 [ 0 ] . V_74 ;
F_8 ( V_2 , V_87 ,
V_73 -> V_88 ) ;
F_8 ( V_2 , V_89 ,
V_2 -> V_85 [ 0 ] . V_90 ) ;
F_8 ( V_2 , V_91 , 0 ) ;
F_8 ( V_2 , V_92 , 0 ) ;
V_73 = V_2 -> V_85 [ 1 ] . V_86 [ 0 ] . V_74 ;
F_8 ( V_2 , V_93 ,
V_73 -> V_88 ) ;
F_8 ( V_2 , V_94 ,
V_2 -> V_85 [ 1 ] . V_90 ) ;
F_8 ( V_2 , V_95 , 0 ) ;
F_8 ( V_2 , V_96 , 0 ) ;
V_73 = V_2 -> V_85 [ 2 ] . V_86 [ 0 ] . V_74 ;
F_8 ( V_2 , V_97 ,
V_73 -> V_88 ) ;
F_8 ( V_2 , V_98 ,
V_2 -> V_85 [ 2 ] . V_90 ) ;
F_8 ( V_2 , V_99 , 0 ) ;
F_8 ( V_2 , V_100 , 0 ) ;
V_73 = V_2 -> V_85 [ 3 ] . V_86 [ 0 ] . V_74 ;
F_8 ( V_2 , V_101 ,
V_73 -> V_88 ) ;
F_8 ( V_2 , V_102 ,
V_2 -> V_85 [ 3 ] . V_90 ) ;
F_8 ( V_2 , V_103 , 0 ) ;
F_8 ( V_2 , V_104 , 0 ) ;
F_8 ( V_2 , V_105 , 0 ) ;
F_8 ( V_2 , V_106 , 0 ) ;
F_8 ( V_2 , V_107 , 0 ) ;
F_8 ( V_2 , V_108 , 0 ) ;
F_8 ( V_2 , V_109 , 0 ) ;
F_8 ( V_2 , V_110 , 0 ) ;
F_8 ( V_2 , V_111 , 0 ) ;
F_8 ( V_2 , V_112 , 0 ) ;
V_73 = V_2 -> V_113 -> V_86 [ 0 ] . V_74 ;
F_8 ( V_2 , V_114 ,
V_73 -> V_88 ) ;
F_8 ( V_2 , V_115 ,
V_2 -> V_113 [ 0 ] . V_90 ) ;
F_8 ( V_2 , V_84 ,
V_2 -> V_113 [ 0 ] . V_90 - 1 ) ;
F_8 ( V_2 , V_116 , 0 ) ;
F_38 ( V_2 ) ;
F_8 ( V_2 , V_117 , 0 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
enum V_118 V_119 )
{
T_2 V_6 ;
unsigned long V_120 ;
if ( V_119 == V_121 ) {
F_4 ( V_2 , V_122 , & V_6 ) ;
F_8 ( V_2 , V_122 , V_6 ) ;
}
F_40 ( & V_2 -> V_123 , V_120 ) ;
V_6 = 0 ;
if ( V_119 == V_121 ) {
F_15 ( & V_6 , V_124 , 1 ) ;
F_15 ( & V_6 , V_125 , 1 ) ;
F_15 ( & V_6 , V_126 , 1 ) ;
F_15 ( & V_6 , V_127 , 1 ) ;
F_15 ( & V_6 , V_128 , 1 ) ;
}
F_8 ( V_2 , V_129 , V_6 ) ;
F_41 ( & V_2 -> V_123 , V_120 ) ;
if ( V_119 == V_130 ) {
F_27 ( & V_2 -> V_131 ) ;
F_27 ( & V_2 -> V_132 ) ;
F_27 ( & V_2 -> V_133 ) ;
F_27 ( & V_2 -> V_61 ) ;
F_27 ( & V_2 -> V_62 ) ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
T_2 V_6 ;
F_4 ( V_2 , V_134 , & V_6 ) ;
F_15 ( & V_6 , V_135 , 1 ) ;
F_15 ( & V_6 , V_136 , 1 ) ;
F_15 ( & V_6 , V_137 , 1 ) ;
F_15 ( & V_6 , V_138 , 1 ) ;
F_15 ( & V_6 , V_139 , 1 ) ;
F_15 ( & V_6 , V_140 , 1 ) ;
F_15 ( & V_6 , V_141 , 1 ) ;
F_8 ( V_2 , V_134 , V_6 ) ;
F_8 ( V_2 , V_68 , 0x00000e1f ) ;
F_8 ( V_2 , V_68 , 0x00000e00 ) ;
if ( F_43 ( V_2 ) &&
( F_29 ( V_2 , V_142 ) ||
F_29 ( V_2 , V_143 ) ||
F_29 ( V_2 , V_144 ) ||
F_29 ( V_2 , V_145 ) ||
F_29 ( V_2 , V_146 ) ||
F_29 ( V_2 , V_147 ) ||
F_29 ( V_2 , V_148 ) ) ) {
F_4 ( V_2 , V_149 , & V_6 ) ;
F_15 ( & V_6 , V_150 , 1 ) ;
F_15 ( & V_6 , V_151 , 1 ) ;
F_8 ( V_2 , V_149 , V_6 ) ;
}
F_8 ( V_2 , V_152 , 0x00000003 ) ;
V_6 = 0 ;
F_15 ( & V_6 , V_153 , 1 ) ;
F_15 ( & V_6 , V_154 , 1 ) ;
F_8 ( V_2 , V_43 , V_6 ) ;
F_8 ( V_2 , V_43 , 0x00000000 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_155 ;
F_45 ( V_2 ) ;
if ( F_46 ( F_37 ( V_2 ) ) )
return - V_156 ;
V_155 = F_47 ( V_2 ) ;
if ( V_155 )
return V_155 ;
F_8 ( V_2 , V_13 , ~ 0 ) ;
F_8 ( V_2 , V_7 , ~ 0 ) ;
F_48 ( V_2 , V_157 , V_158 , 0xff , 0x02 ) ;
F_2 ( V_2 , V_158 ) ;
F_48 ( V_2 , V_159 , V_160 , 0 , 0 ) ;
F_2 ( V_2 , V_160 ) ;
return V_155 ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) ) {
F_50 ( V_2 ) ;
F_8 ( V_2 , V_152 , 0 ) ;
F_8 ( V_2 , V_161 , 0 ) ;
}
}
static int F_51 ( struct V_1 * V_2 ,
enum V_118 V_119 )
{
if ( V_119 == V_162 ) {
F_48 ( V_2 , V_159 , V_160 ,
0 , 0x02 ) ;
F_2 ( V_2 , V_160 ) ;
} else if ( V_119 == V_163 ) {
F_8 ( V_2 , V_13 ,
0xffffffff ) ;
F_8 ( V_2 , V_7 ,
0xffffffff ) ;
F_48 ( V_2 , V_157 , V_164 ,
0xff , 0x01 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
enum V_118 V_119 )
{
int V_155 = 0 ;
switch ( V_119 ) {
case V_165 :
V_155 = F_44 ( V_2 ) ;
break;
case V_166 :
F_49 ( V_2 ) ;
F_51 ( V_2 , V_163 ) ;
break;
case V_121 :
case V_130 :
F_39 ( V_2 , V_119 ) ;
break;
case V_167 :
case V_163 :
case V_168 :
case V_162 :
V_155 = F_51 ( V_2 , V_119 ) ;
break;
default:
V_155 = - V_169 ;
break;
}
if ( F_46 ( V_155 ) )
F_7 ( V_2 , L_2 ,
V_119 , V_155 ) ;
return V_155 ;
}
static T_5 * F_53 ( struct V_52 * V_53 )
{
return ( T_5 * ) V_53 -> V_81 -> V_19 ;
}
static void F_54 ( struct V_52 * V_53 ,
struct V_170 * V_171 )
{
struct V_79 * V_80 = F_35 ( V_53 -> V_81 ) ;
struct V_72 * V_73 = V_53 -> V_74 ;
T_5 * V_172 = V_73 -> V_76 ;
T_2 V_75 ;
const unsigned int V_173 = V_53 -> V_40 -> V_174 ;
V_75 = 0 ;
F_15 ( & V_75 , V_175 , V_80 -> V_83 ) ;
F_36 ( V_172 , 0 , V_75 ) ;
V_75 = 0 ;
F_15 ( & V_75 , V_176 , V_53 -> V_81 -> V_66 ) ;
F_15 ( & V_75 , V_177 ,
! F_55 ( V_178 , & V_171 -> V_120 ) ) ;
F_15 ( & V_75 , V_179 ,
F_55 ( V_180 , & V_171 -> V_120 ) ) ;
F_15 ( & V_75 , V_181 , V_173 ) ;
F_15 ( & V_75 , V_182 , 0 ) ;
F_15 ( & V_75 , V_78 , 0 ) ;
F_36 ( V_172 , 1 , V_75 ) ;
V_75 = 0 ;
F_15 ( & V_75 , V_183 ,
V_80 -> V_83 + V_173 ) ;
F_36 ( V_172 , 2 , V_75 ) ;
V_75 = 0 ;
F_15 ( & V_75 , V_184 ,
! F_55 ( V_185 , & V_171 -> V_120 ) ) ;
F_15 ( & V_75 , V_186 , 2 ) ;
F_36 ( V_172 , 3 , V_75 ) ;
V_80 -> V_76 = V_172 ;
V_80 -> V_187 = V_188 ;
}
static void F_56 ( struct V_52 * V_53 ,
struct V_189 * V_190 )
{
struct V_72 * V_73 = V_53 -> V_74 ;
T_5 * V_191 = V_73 -> V_76 ;
T_2 V_75 ;
F_33 ( V_191 , 3 , & V_75 ) ;
if ( F_5 ( V_75 , V_192 ) )
V_190 -> V_120 |= V_193 ;
V_190 -> V_194 = F_5 ( V_75 , V_195 ) ;
if ( F_5 ( V_75 , V_196 ) ) {
V_190 -> V_120 |= V_197 ;
V_190 -> V_120 |= V_198 ;
if ( V_190 -> V_194 == V_199 )
V_190 -> V_120 |= V_200 ;
else if ( V_190 -> V_194 == V_201 )
V_190 -> V_120 |= V_202 ;
}
if ( F_5 ( V_75 , V_203 ) )
V_190 -> V_204 |= V_205 ;
if ( F_5 ( V_75 , V_206 ) )
V_190 -> V_204 |= V_207 ;
F_57 ( V_53 , V_190 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_208 V_209 = { . V_120 = 0 } ;
struct V_210 V_211 = { . V_209 = & V_209 } ;
F_59 ( V_2 , & V_211 , V_212 ) ;
}
static bool F_60 ( struct V_52 * V_53 , T_2 V_213 )
{
T_5 * V_214 ;
T_2 V_75 ;
int V_215 , V_216 ;
V_215 = F_5 ( V_213 , V_217 ) ;
V_214 = F_61 ( V_53 ) ;
F_33 ( V_214 , 1 , & V_75 ) ;
V_216 = F_5 ( V_75 , V_218 ) ;
return ( V_216 == V_215 ) ;
}
static bool F_62 ( struct V_52 * V_53 , void * V_19 )
{
T_2 V_213 = * ( T_2 * ) V_19 ;
if ( F_60 ( V_53 , V_213 ) &&
! F_55 ( V_219 , & V_53 -> V_120 ) ) {
V_53 -> V_213 = V_213 ;
F_63 ( V_219 , & V_53 -> V_120 ) ;
return true ;
}
return false ;
}
static bool F_64 ( struct V_52 * V_53 , void * V_19 )
{
T_2 V_213 = * ( T_2 * ) V_19 ;
if ( ! F_55 ( V_219 , & V_53 -> V_120 ) ) {
V_53 -> V_213 = V_213 ;
F_63 ( V_219 , & V_53 -> V_120 ) ;
return true ;
}
return false ;
}
static bool F_65 ( struct V_52 * V_53 ,
void * V_19 )
{
if ( F_55 ( V_219 , & V_53 -> V_120 ) ) {
F_66 ( V_53 , V_53 -> V_213 ,
F_53 ( V_53 ) ) ;
return false ;
}
return true ;
}
static bool F_67 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
T_2 V_213 ;
T_1 V_41 ;
int V_220 = 16 ;
while ( F_68 ( & V_2 -> V_221 , & V_213 ) ) {
V_41 = F_5 ( V_213 , V_222 ) ;
if ( F_46 ( V_41 >= V_42 ) ) {
F_69 ( V_2 , L_3 ,
V_41 ) ;
break;
}
V_40 = F_70 ( V_2 , V_41 ) ;
if ( F_46 ( V_40 == NULL ) ) {
F_69 ( V_2 , L_4 ,
V_41 ) ;
break;
}
if ( F_46 ( F_71 ( V_40 ) ) ) {
F_69 ( V_2 , L_5 ,
V_41 ) ;
break;
}
if ( ! F_72 ( V_40 , V_223 ,
V_58 , & V_213 ,
F_62 ) ) {
if ( ! F_72 ( V_40 , V_223 ,
V_58 , & V_213 ,
F_64 ) ) {
F_69 ( V_2 , L_6 ,
V_41 ) ;
break;
}
}
F_72 ( V_40 , V_223 ,
V_58 , NULL ,
F_65 ) ;
if ( -- V_220 == 0 )
break;
}
return ! V_220 ;
}
static inline void F_73 ( struct V_1 * V_2 ,
struct V_224 V_225 )
{
T_2 V_6 ;
F_74 ( & V_2 -> V_123 ) ;
F_4 ( V_2 , V_129 , & V_6 ) ;
F_15 ( & V_6 , V_225 , 1 ) ;
F_8 ( V_2 , V_129 , V_6 ) ;
F_75 ( & V_2 -> V_123 ) ;
}
static void F_76 ( unsigned long V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
if ( F_67 ( V_2 ) )
F_77 ( & V_2 -> V_131 ) ;
}
static void F_78 ( unsigned long V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
F_79 ( V_2 ) ;
if ( F_55 ( V_226 , & V_2 -> V_120 ) )
F_73 ( V_2 , V_126 ) ;
}
static void F_80 ( unsigned long V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
struct V_227 * V_228 = V_2 -> V_228 ;
T_2 V_6 ;
F_81 ( V_2 ) ;
if ( V_2 -> V_229 ) {
if ( V_228 -> V_230 == ( V_231 - 2 ) ) {
F_4 ( V_2 , V_46 , & V_6 ) ;
F_15 ( & V_6 , V_232 ,
( V_2 -> V_233 * 16 ) - 1 ) ;
F_8 ( V_2 , V_46 , V_6 ) ;
} else if ( V_228 -> V_230 == ( V_231 - 1 ) ) {
F_4 ( V_2 , V_46 , & V_6 ) ;
F_15 ( & V_6 , V_232 ,
( V_2 -> V_233 * 16 ) ) ;
F_8 ( V_2 , V_46 , V_6 ) ;
}
V_228 -> V_230 ++ ;
V_228 -> V_230 %= V_231 ;
}
if ( F_55 ( V_226 , & V_2 -> V_120 ) )
F_73 ( V_2 , V_125 ) ;
}
static void F_82 ( unsigned long V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
if ( F_83 ( V_2 ) )
F_77 ( & V_2 -> V_132 ) ;
else if ( F_55 ( V_226 , & V_2 -> V_120 ) )
F_73 ( V_2 , V_124 ) ;
}
static void F_84 ( unsigned long V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
F_58 ( V_2 ) ;
if ( F_55 ( V_226 , & V_2 -> V_120 ) )
F_73 ( V_2 , V_128 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
T_2 V_213 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_85 -> V_90 ; V_5 ++ ) {
F_4 ( V_2 , V_234 , & V_213 ) ;
if ( ! F_5 ( V_213 , V_235 ) )
break;
if ( ! F_86 ( & V_2 -> V_221 , & V_213 ) ) {
F_69 ( V_2 , L_7 ) ;
break;
}
}
F_77 ( & V_2 -> V_131 ) ;
}
static T_6 F_87 ( int V_236 , void * V_237 )
{
struct V_1 * V_2 = V_237 ;
T_2 V_6 , V_238 ;
F_4 ( V_2 , V_122 , & V_6 ) ;
F_8 ( V_2 , V_122 , V_6 ) ;
if ( ! V_6 )
return V_239 ;
if ( ! F_55 ( V_226 , & V_2 -> V_120 ) )
return V_240 ;
V_238 = ~ V_6 ;
if ( F_5 ( V_6 , V_241 ) ) {
F_85 ( V_2 ) ;
F_15 ( & V_238 , V_127 , 1 ) ;
}
if ( F_5 ( V_6 , V_242 ) )
F_88 ( & V_2 -> V_62 ) ;
if ( F_5 ( V_6 , V_243 ) )
F_88 ( & V_2 -> V_61 ) ;
if ( F_5 ( V_6 , V_244 ) )
F_77 ( & V_2 -> V_132 ) ;
if ( F_5 ( V_6 , V_245 ) )
F_77 ( & V_2 -> V_133 ) ;
F_89 ( & V_2 -> V_123 ) ;
F_4 ( V_2 , V_129 , & V_6 ) ;
V_6 &= V_238 ;
F_8 ( V_2 , V_129 , V_6 ) ;
F_90 ( & V_2 -> V_123 ) ;
return V_240 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_155 ;
if ( F_3 ( V_2 ) )
V_155 = F_9 ( V_2 ) ;
else if ( F_18 ( V_2 ) )
V_155 = F_20 ( V_2 ) ;
else
V_155 = F_16 ( V_2 ) ;
return V_155 ;
}
static void F_92 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
unsigned short V_173 , V_246 ;
F_93 ( V_2 , & V_173 , & V_246 ) ;
switch ( V_40 -> V_41 ) {
case V_42 :
V_40 -> V_90 = 128 ;
V_40 -> V_247 = V_248 ;
V_40 -> V_249 = V_250 ;
V_40 -> V_174 = V_246 ;
V_40 -> V_251 = sizeof( struct V_72 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_40 -> V_90 = 64 ;
V_40 -> V_247 = V_248 ;
V_40 -> V_249 = V_188 ;
V_40 -> V_174 = V_173 ;
V_40 -> V_251 = sizeof( struct V_72 ) ;
break;
case V_45 :
V_40 -> V_90 = 8 ;
V_40 -> V_247 = 0 ;
V_40 -> V_249 = V_188 ;
V_40 -> V_174 = V_173 ;
V_40 -> V_251 = sizeof( struct V_72 ) ;
break;
case V_252 :
default:
F_94 () ;
break;
}
}
static int F_95 ( struct V_253 * V_254 )
{
return F_96 ( V_254 , & V_255 ) ;
}
static int F_97 ( struct V_256 * V_256 ,
const struct V_257 * V_258 )
{
return F_98 ( V_256 , & V_255 ) ;
}
static int T_7 F_99 ( void )
{
int V_259 = 0 ;
#if F_100 ( V_260 ) || F_100 ( V_261 )
V_259 = F_101 ( & V_262 ) ;
if ( V_259 )
return V_259 ;
#endif
#ifdef F_102
V_259 = F_103 ( & V_263 ) ;
if ( V_259 ) {
#if F_100 ( V_260 ) || F_100 ( V_261 )
F_104 ( & V_262 ) ;
#endif
return V_259 ;
}
#endif
return V_259 ;
}
static void T_8 F_105 ( void )
{
#ifdef F_102
F_106 ( & V_263 ) ;
#endif
#if F_100 ( V_260 ) || F_100 ( V_261 )
F_104 ( & V_262 ) ;
#endif
}
