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
ERROR ( V_2 , L_1 ) ;
F_7 ( V_2 , V_13 , ~ 0 ) ;
F_7 ( V_2 , V_7 , ~ 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
void T_3 * V_14 = F_9 ( 0x1F040000 , V_15 ) ;
F_10 ( V_2 -> V_16 , V_14 , V_15 ) ;
F_11 ( V_14 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
}
static void F_12 ( struct V_17 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_2 V_6 ;
F_4 ( V_2 , V_19 , & V_6 ) ;
V_16 -> V_20 = ! ! F_5 ( V_6 , V_21 ) ;
V_16 -> V_22 = ! ! F_5 ( V_6 , V_23 ) ;
V_16 -> V_24 =
! ! F_5 ( V_6 , V_25 ) ;
V_16 -> V_26 =
! ! F_5 ( V_6 , V_27 ) ;
}
static void F_13 ( struct V_17 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_2 V_6 = 0 ;
F_14 ( & V_6 , V_21 , ! ! V_16 -> V_20 ) ;
F_14 ( & V_6 , V_23 , ! ! V_16 -> V_22 ) ;
F_14 ( & V_6 , V_25 ,
! ! V_16 -> V_24 ) ;
F_14 ( & V_6 , V_27 ,
! ! V_16 -> V_26 ) ;
F_7 ( V_2 , V_19 , V_6 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_17 V_16 ;
T_2 V_6 ;
F_4 ( V_2 , V_19 , & V_6 ) ;
V_16 . V_18 = V_2 ;
V_16 . V_28 = F_12 ;
V_16 . V_29 = F_13 ;
switch ( F_5 ( V_6 , V_30 ) )
{
case 0 :
V_16 . V_31 = V_32 ;
break;
case 1 :
V_16 . V_31 = V_33 ;
break;
default:
V_16 . V_31 = V_34 ;
break;
}
V_16 . V_20 = 0 ;
V_16 . V_22 = 0 ;
V_16 . V_24 = 0 ;
V_16 . V_26 = 0 ;
F_16 ( & V_16 , V_35 , V_2 -> V_16 ,
V_15 / sizeof( V_36 ) ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_18 ( V_2 ) ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
}
static inline int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_19 ( struct V_1 * V_2 )
{
}
static void F_21 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
T_2 V_6 ;
switch ( V_38 -> V_39 ) {
case V_40 :
F_4 ( V_2 , V_41 , & V_6 ) ;
F_14 ( & V_6 , V_42 , 1 ) ;
F_7 ( V_2 , V_41 , V_6 ) ;
break;
case V_43 :
F_4 ( V_2 , V_44 , & V_6 ) ;
F_14 ( & V_6 , V_45 , 1 ) ;
F_14 ( & V_6 , V_46 , 1 ) ;
F_14 ( & V_6 , V_47 , 1 ) ;
F_7 ( V_2 , V_44 , V_6 ) ;
F_4 ( V_2 , V_48 , & V_6 ) ;
F_14 ( & V_6 , V_49 , 1 ) ;
F_7 ( V_2 , V_48 , V_6 ) ;
break;
default:
break;
}
}
static void F_22 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_50 * V_51 ;
switch ( V_38 -> V_39 ) {
case V_52 :
case V_53 :
case V_54 :
case V_55 :
V_51 = F_23 ( V_38 , V_56 ) ;
F_7 ( V_2 , F_24 ( V_38 -> V_39 ) ,
V_51 -> V_57 ) ;
break;
case V_58 :
V_51 = F_23 ( V_38 , V_56 ) ;
F_7 ( V_2 , F_24 ( 5 ) ,
V_51 -> V_57 ) ;
break;
default:
break;
}
}
static void F_25 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
T_2 V_6 ;
switch ( V_38 -> V_39 ) {
case V_40 :
F_4 ( V_2 , V_41 , & V_6 ) ;
F_14 ( & V_6 , V_42 , 0 ) ;
F_7 ( V_2 , V_41 , V_6 ) ;
break;
case V_43 :
F_4 ( V_2 , V_44 , & V_6 ) ;
F_14 ( & V_6 , V_45 , 0 ) ;
F_14 ( & V_6 , V_46 , 0 ) ;
F_14 ( & V_6 , V_47 , 0 ) ;
F_7 ( V_2 , V_44 , V_6 ) ;
F_4 ( V_2 , V_48 , & V_6 ) ;
F_14 ( & V_6 , V_49 , 0 ) ;
F_7 ( V_2 , V_48 , V_6 ) ;
F_26 ( & V_2 -> V_59 ) ;
F_26 ( & V_2 -> V_60 ) ;
break;
default:
break;
}
}
static char * F_27 ( struct V_1 * V_2 )
{
if ( F_28 ( V_2 , V_61 ) )
return V_62 ;
else
return V_63 ;
}
static int F_29 ( struct V_1 * V_2 ,
const T_1 * V_18 , const T_4 V_64 )
{
T_2 V_6 ;
V_6 = 0 ;
F_14 ( & V_6 , V_65 , 1 ) ;
F_7 ( V_2 , V_66 , V_6 ) ;
F_30 ( V_2 , V_67 ,
V_18 , V_64 ) ;
F_7 ( V_2 , V_66 , 0x00000 ) ;
F_7 ( V_2 , V_66 , 0x00001 ) ;
F_7 ( V_2 , V_68 , 0 ) ;
F_7 ( V_2 , V_69 , 0 ) ;
return 0 ;
}
static bool F_31 ( struct V_50 * V_51 )
{
struct V_70 * V_71 = V_51 -> V_72 ;
T_2 V_73 ;
if ( V_51 -> V_38 -> V_39 == V_40 ) {
F_32 ( V_71 -> V_74 , 1 , & V_73 ) ;
return ( ! F_5 ( V_73 , V_75 ) ) ;
} else {
F_32 ( V_71 -> V_74 , 1 , & V_73 ) ;
return ( ! F_5 ( V_73 , V_76 ) ) ;
}
}
static void F_33 ( struct V_50 * V_51 )
{
struct V_70 * V_71 = V_51 -> V_72 ;
struct V_77 * V_78 = F_34 ( V_51 -> V_79 ) ;
struct V_1 * V_2 = V_51 -> V_38 -> V_2 ;
T_2 V_73 ;
if ( V_51 -> V_38 -> V_39 == V_40 ) {
F_32 ( V_71 -> V_74 , 0 , & V_73 ) ;
F_14 ( & V_73 , V_80 , V_78 -> V_81 ) ;
F_35 ( V_71 -> V_74 , 0 , V_73 ) ;
F_32 ( V_71 -> V_74 , 1 , & V_73 ) ;
F_14 ( & V_73 , V_75 , 0 ) ;
F_35 ( V_71 -> V_74 , 1 , V_73 ) ;
F_7 ( V_2 , V_82 ,
V_51 -> V_57 ) ;
} else {
F_32 ( V_71 -> V_74 , 1 , & V_73 ) ;
F_14 ( & V_73 , V_76 , 1 ) ;
F_35 ( V_71 -> V_74 , 1 , V_73 ) ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
V_71 = V_2 -> V_83 [ 0 ] . V_84 [ 0 ] . V_72 ;
F_7 ( V_2 , V_85 , V_71 -> V_86 ) ;
F_7 ( V_2 , V_87 ,
V_2 -> V_83 [ 0 ] . V_88 ) ;
F_7 ( V_2 , V_89 , 0 ) ;
F_7 ( V_2 , V_90 , 0 ) ;
V_71 = V_2 -> V_83 [ 1 ] . V_84 [ 0 ] . V_72 ;
F_7 ( V_2 , V_91 , V_71 -> V_86 ) ;
F_7 ( V_2 , V_92 ,
V_2 -> V_83 [ 1 ] . V_88 ) ;
F_7 ( V_2 , V_93 , 0 ) ;
F_7 ( V_2 , V_94 , 0 ) ;
V_71 = V_2 -> V_83 [ 2 ] . V_84 [ 0 ] . V_72 ;
F_7 ( V_2 , V_95 , V_71 -> V_86 ) ;
F_7 ( V_2 , V_96 ,
V_2 -> V_83 [ 2 ] . V_88 ) ;
F_7 ( V_2 , V_97 , 0 ) ;
F_7 ( V_2 , V_98 , 0 ) ;
V_71 = V_2 -> V_83 [ 3 ] . V_84 [ 0 ] . V_72 ;
F_7 ( V_2 , V_99 , V_71 -> V_86 ) ;
F_7 ( V_2 , V_100 ,
V_2 -> V_83 [ 3 ] . V_88 ) ;
F_7 ( V_2 , V_101 , 0 ) ;
F_7 ( V_2 , V_102 , 0 ) ;
F_7 ( V_2 , V_103 , 0 ) ;
F_7 ( V_2 , V_104 , 0 ) ;
F_7 ( V_2 , V_105 , 0 ) ;
F_7 ( V_2 , V_106 , 0 ) ;
F_7 ( V_2 , V_107 , 0 ) ;
F_7 ( V_2 , V_108 , 0 ) ;
F_7 ( V_2 , V_109 , 0 ) ;
F_7 ( V_2 , V_110 , 0 ) ;
V_71 = V_2 -> V_111 -> V_84 [ 0 ] . V_72 ;
F_7 ( V_2 , V_112 , V_71 -> V_86 ) ;
F_7 ( V_2 , V_113 ,
V_2 -> V_111 [ 0 ] . V_88 ) ;
F_7 ( V_2 , V_82 ,
V_2 -> V_111 [ 0 ] . V_88 - 1 ) ;
F_7 ( V_2 , V_114 , 0 ) ;
F_37 ( V_2 ) ;
F_7 ( V_2 , V_115 , 0 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
T_2 V_6 ;
unsigned long V_118 ;
if ( V_117 == V_119 ) {
F_4 ( V_2 , V_120 , & V_6 ) ;
F_7 ( V_2 , V_120 , V_6 ) ;
}
F_39 ( & V_2 -> V_121 , V_118 ) ;
V_6 = 0 ;
if ( V_117 == V_119 ) {
F_14 ( & V_6 , V_122 , 1 ) ;
F_14 ( & V_6 , V_123 , 1 ) ;
F_14 ( & V_6 , V_124 , 1 ) ;
F_14 ( & V_6 , V_125 , 1 ) ;
F_14 ( & V_6 , V_126 , 1 ) ;
}
F_7 ( V_2 , V_127 , V_6 ) ;
F_40 ( & V_2 -> V_121 , V_118 ) ;
if ( V_117 == V_128 ) {
F_26 ( & V_2 -> V_129 ) ;
F_26 ( & V_2 -> V_130 ) ;
F_26 ( & V_2 -> V_131 ) ;
F_26 ( & V_2 -> V_59 ) ;
F_26 ( & V_2 -> V_60 ) ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
T_2 V_6 ;
F_4 ( V_2 , V_132 , & V_6 ) ;
F_14 ( & V_6 , V_133 , 1 ) ;
F_14 ( & V_6 , V_134 , 1 ) ;
F_14 ( & V_6 , V_135 , 1 ) ;
F_14 ( & V_6 , V_136 , 1 ) ;
F_14 ( & V_6 , V_137 , 1 ) ;
F_14 ( & V_6 , V_138 , 1 ) ;
F_14 ( & V_6 , V_139 , 1 ) ;
F_7 ( V_2 , V_132 , V_6 ) ;
F_7 ( V_2 , V_66 , 0x00000e1f ) ;
F_7 ( V_2 , V_66 , 0x00000e00 ) ;
if ( F_42 ( V_2 ) &&
( F_28 ( V_2 , V_140 ) ||
F_28 ( V_2 , V_141 ) ||
F_28 ( V_2 , V_142 ) ) ) {
F_4 ( V_2 , V_143 , & V_6 ) ;
F_14 ( & V_6 , V_144 , 1 ) ;
F_14 ( & V_6 , V_145 , 1 ) ;
F_7 ( V_2 , V_143 , V_6 ) ;
}
F_7 ( V_2 , V_146 , 0x00000003 ) ;
V_6 = 0 ;
F_14 ( & V_6 , V_147 , 1 ) ;
F_14 ( & V_6 , V_148 , 1 ) ;
F_7 ( V_2 , V_41 , V_6 ) ;
F_7 ( V_2 , V_41 , 0x00000000 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_149 ;
F_44 ( V_2 ) ;
if ( F_45 ( F_36 ( V_2 ) ) )
return - V_150 ;
V_149 = F_46 ( V_2 ) ;
if ( V_149 )
return V_149 ;
F_7 ( V_2 , V_13 , ~ 0 ) ;
F_7 ( V_2 , V_7 , ~ 0 ) ;
F_47 ( V_2 , V_151 , V_152 , 0xff , 0x02 ) ;
F_2 ( V_2 , V_152 ) ;
F_47 ( V_2 , V_153 , V_154 , 0 , 0 ) ;
F_2 ( V_2 , V_154 ) ;
return V_149 ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) ) {
F_49 ( V_2 ) ;
F_7 ( V_2 , V_146 , 0 ) ;
F_7 ( V_2 , V_155 , 0 ) ;
}
}
static int F_50 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
if ( V_117 == V_156 ) {
F_47 ( V_2 , V_153 , V_154 ,
0 , 0x02 ) ;
F_2 ( V_2 , V_154 ) ;
} else if ( V_117 == V_157 ) {
F_7 ( V_2 , V_13 ,
0xffffffff ) ;
F_7 ( V_2 , V_7 ,
0xffffffff ) ;
F_47 ( V_2 , V_151 , V_158 ,
0xff , 0x01 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
int V_149 = 0 ;
switch ( V_117 ) {
case V_159 :
V_149 = F_43 ( V_2 ) ;
break;
case V_160 :
F_48 ( V_2 ) ;
F_50 ( V_2 , V_157 ) ;
break;
case V_119 :
case V_128 :
F_38 ( V_2 , V_117 ) ;
break;
case V_161 :
case V_157 :
case V_162 :
case V_156 :
V_149 = F_50 ( V_2 , V_117 ) ;
break;
default:
V_149 = - V_163 ;
break;
}
if ( F_45 ( V_149 ) )
ERROR ( V_2 , L_2 ,
V_117 , V_149 ) ;
return V_149 ;
}
static T_5 * F_52 ( struct V_50 * V_51 )
{
return ( T_5 * ) V_51 -> V_79 -> V_18 ;
}
static void F_53 ( struct V_50 * V_51 ,
struct V_164 * V_165 )
{
struct V_77 * V_78 = F_34 ( V_51 -> V_79 ) ;
struct V_70 * V_71 = V_51 -> V_72 ;
T_5 * V_166 = V_71 -> V_74 ;
T_2 V_73 ;
V_73 = 0 ;
F_14 ( & V_73 , V_167 , V_78 -> V_81 ) ;
F_35 ( V_166 , 0 , V_73 ) ;
V_73 = 0 ;
F_14 ( & V_73 , V_168 , V_51 -> V_79 -> V_64 ) ;
F_14 ( & V_73 , V_169 ,
! F_54 ( V_170 , & V_165 -> V_118 ) ) ;
F_14 ( & V_73 , V_171 ,
F_54 ( V_172 , & V_165 -> V_118 ) ) ;
F_14 ( & V_73 , V_173 , V_174 ) ;
F_14 ( & V_73 , V_175 , 0 ) ;
F_14 ( & V_73 , V_76 , 0 ) ;
F_35 ( V_166 , 1 , V_73 ) ;
V_73 = 0 ;
F_14 ( & V_73 , V_176 ,
V_78 -> V_81 + V_174 ) ;
F_35 ( V_166 , 2 , V_73 ) ;
V_73 = 0 ;
F_14 ( & V_73 , V_177 ,
! F_54 ( V_178 , & V_165 -> V_118 ) ) ;
F_14 ( & V_73 , V_179 , 2 ) ;
F_35 ( V_166 , 3 , V_73 ) ;
V_78 -> V_74 = V_166 ;
V_78 -> V_180 = V_181 ;
}
static void F_55 ( struct V_50 * V_51 ,
struct V_182 * V_183 )
{
struct V_70 * V_71 = V_51 -> V_72 ;
T_5 * V_184 = V_71 -> V_74 ;
T_2 V_73 ;
F_32 ( V_184 , 3 , & V_73 ) ;
if ( F_5 ( V_73 , V_185 ) )
V_183 -> V_118 |= V_186 ;
V_183 -> V_187 = F_5 ( V_73 , V_188 ) ;
if ( F_5 ( V_73 , V_189 ) ) {
V_183 -> V_118 |= V_190 ;
V_183 -> V_118 |= V_191 ;
if ( V_183 -> V_187 == V_192 )
V_183 -> V_118 |= V_193 ;
else if ( V_183 -> V_187 == V_194 )
V_183 -> V_118 |= V_195 ;
}
if ( F_5 ( V_73 , V_196 ) )
V_183 -> V_197 |= V_198 ;
if ( F_5 ( V_73 , V_199 ) )
V_183 -> V_197 |= V_200 ;
F_56 ( V_51 , V_183 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_201 V_202 = { . V_118 = 0 } ;
struct V_203 V_204 = { . V_202 = & V_202 } ;
F_58 ( V_2 , & V_204 , V_205 ) ;
}
static bool F_59 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
struct V_50 * V_51 ;
T_2 V_206 ;
T_1 V_39 ;
int V_207 = 16 ;
while ( F_60 ( & V_2 -> V_208 , & V_206 ) ) {
V_39 = F_5 ( V_206 , V_209 ) ;
if ( F_45 ( V_39 >= V_40 ) ) {
F_61 ( V_2 , L_3
L_4 , V_39 ) ;
break;
}
V_38 = F_62 ( V_2 , V_39 ) ;
if ( F_45 ( V_38 == NULL ) ) {
F_61 ( V_2 , L_5
L_6 , V_39 ) ;
break;
}
if ( F_45 ( F_63 ( V_38 ) ) ) {
F_61 ( V_2 , L_7
L_6 , V_39 ) ;
break;
}
V_51 = F_23 ( V_38 , V_210 ) ;
F_64 ( V_51 , V_206 , F_52 ( V_51 ) ) ;
if ( -- V_207 == 0 )
break;
}
return ! V_207 ;
}
static inline void F_65 ( struct V_1 * V_2 ,
struct V_211 V_212 )
{
T_2 V_6 ;
F_66 ( & V_2 -> V_121 ) ;
F_4 ( V_2 , V_127 , & V_6 ) ;
F_14 ( & V_6 , V_212 , 1 ) ;
F_7 ( V_2 , V_127 , V_6 ) ;
F_67 ( & V_2 -> V_121 ) ;
}
static void F_68 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
if ( F_59 ( V_2 ) )
F_69 ( & V_2 -> V_129 ) ;
}
static void F_70 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
F_71 ( V_2 ) ;
if ( F_54 ( V_213 , & V_2 -> V_118 ) )
F_65 ( V_2 , V_124 ) ;
}
static void F_72 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
struct V_214 * V_215 = V_2 -> V_215 ;
T_2 V_6 ;
F_73 ( V_2 ) ;
if ( V_2 -> V_216 ) {
if ( V_215 -> V_217 == ( V_218 - 2 ) ) {
F_4 ( V_2 , V_44 , & V_6 ) ;
F_14 ( & V_6 , V_219 ,
( V_2 -> V_220 * 16 ) - 1 ) ;
F_7 ( V_2 , V_44 , V_6 ) ;
} else if ( V_215 -> V_217 == ( V_218 - 1 ) ) {
F_4 ( V_2 , V_44 , & V_6 ) ;
F_14 ( & V_6 , V_219 ,
( V_2 -> V_220 * 16 ) ) ;
F_7 ( V_2 , V_44 , V_6 ) ;
}
V_215 -> V_217 ++ ;
V_215 -> V_217 %= V_218 ;
}
if ( F_54 ( V_213 , & V_2 -> V_118 ) )
F_65 ( V_2 , V_123 ) ;
}
static void F_74 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
if ( F_75 ( V_2 ) )
F_69 ( & V_2 -> V_130 ) ;
else if ( F_54 ( V_213 , & V_2 -> V_118 ) )
F_65 ( V_2 , V_122 ) ;
}
static void F_76 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
F_57 ( V_2 ) ;
if ( F_54 ( V_213 , & V_2 -> V_118 ) )
F_65 ( V_2 , V_126 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
T_2 V_206 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_221 -> V_83 -> V_222 ; V_5 ++ ) {
F_4 ( V_2 , V_223 , & V_206 ) ;
if ( ! F_5 ( V_206 , V_224 ) )
break;
if ( ! F_78 ( & V_2 -> V_208 , & V_206 ) ) {
F_61 ( V_2 , L_8
L_9 ) ;
break;
}
}
F_69 ( & V_2 -> V_129 ) ;
}
static T_6 F_79 ( int V_225 , void * V_226 )
{
struct V_1 * V_2 = V_226 ;
T_2 V_6 , V_227 ;
F_4 ( V_2 , V_120 , & V_6 ) ;
F_7 ( V_2 , V_120 , V_6 ) ;
if ( ! V_6 )
return V_228 ;
if ( ! F_54 ( V_213 , & V_2 -> V_118 ) )
return V_229 ;
V_227 = ~ V_6 ;
if ( F_5 ( V_6 , V_230 ) ) {
F_77 ( V_2 ) ;
F_14 ( & V_227 , V_125 , 1 ) ;
}
if ( F_5 ( V_6 , V_231 ) )
F_80 ( & V_2 -> V_60 ) ;
if ( F_5 ( V_6 , V_232 ) )
F_80 ( & V_2 -> V_59 ) ;
if ( F_5 ( V_6 , V_233 ) )
F_69 ( & V_2 -> V_130 ) ;
if ( F_5 ( V_6 , V_234 ) )
F_69 ( & V_2 -> V_131 ) ;
F_81 ( & V_2 -> V_121 ) ;
F_4 ( V_2 , V_127 , & V_6 ) ;
V_6 &= V_227 ;
F_7 ( V_2 , V_127 , V_6 ) ;
F_82 ( & V_2 -> V_121 ) ;
return V_229 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) )
F_8 ( V_2 ) ;
else if ( F_17 ( V_2 ) )
F_19 ( V_2 ) ;
else
F_15 ( V_2 ) ;
}
static int F_84 ( struct V_235 * V_236 )
{
return F_85 ( V_236 , & V_237 ) ;
}
static int F_86 ( struct V_238 * V_238 ,
const struct V_239 * V_240 )
{
return F_87 ( V_238 , & V_237 ) ;
}
static int T_7 F_88 ( void )
{
int V_241 = 0 ;
#if F_89 ( V_242 ) || F_89 ( V_243 )
V_241 = F_90 ( & V_244 ) ;
if ( V_241 )
return V_241 ;
#endif
#ifdef F_91
V_241 = F_92 ( & V_245 ) ;
if ( V_241 ) {
#if F_89 ( V_242 ) || F_89 ( V_243 )
F_93 ( & V_244 ) ;
#endif
return V_241 ;
}
#endif
return V_241 ;
}
static void T_8 F_94 ( void )
{
#ifdef F_91
F_95 ( & V_245 ) ;
#endif
#if F_89 ( V_242 ) || F_89 ( V_243 )
F_93 ( & V_244 ) ;
#endif
}
