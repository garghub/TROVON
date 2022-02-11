static void F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
unsigned int V_4 ;
T_2 V_5 ;
if ( F_2 ( V_2 ) )
return;
for ( V_4 = 0 ; V_4 < 200 ; V_4 ++ ) {
F_3 ( V_2 , V_6 , & V_5 ) ;
if ( ( F_4 ( V_5 , V_7 ) == V_3 ) ||
( F_4 ( V_5 , V_8 ) == V_3 ) ||
( F_4 ( V_5 , V_9 ) == V_3 ) ||
( F_4 ( V_5 , V_10 ) == V_3 ) )
break;
F_5 ( V_11 ) ;
}
if ( V_4 == 200 )
ERROR ( V_2 , L_1 ) ;
F_6 ( V_2 , V_12 , ~ 0 ) ;
F_6 ( V_2 , V_6 , ~ 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
void T_3 * V_13 = F_8 ( 0x1F040000 , V_14 ) ;
F_9 ( V_2 -> V_15 , V_13 , V_14 ) ;
F_10 ( V_13 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
}
static void F_11 ( struct V_16 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
T_2 V_5 ;
F_3 ( V_2 , V_18 , & V_5 ) ;
V_15 -> V_19 = ! ! F_4 ( V_5 , V_20 ) ;
V_15 -> V_21 = ! ! F_4 ( V_5 , V_22 ) ;
V_15 -> V_23 =
! ! F_4 ( V_5 , V_24 ) ;
V_15 -> V_25 =
! ! F_4 ( V_5 , V_26 ) ;
}
static void F_12 ( struct V_16 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
T_2 V_5 = 0 ;
F_13 ( & V_5 , V_20 , ! ! V_15 -> V_19 ) ;
F_13 ( & V_5 , V_22 , ! ! V_15 -> V_21 ) ;
F_13 ( & V_5 , V_24 ,
! ! V_15 -> V_23 ) ;
F_13 ( & V_5 , V_26 ,
! ! V_15 -> V_25 ) ;
F_6 ( V_2 , V_18 , V_5 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_16 V_15 ;
T_2 V_5 ;
F_3 ( V_2 , V_18 , & V_5 ) ;
V_15 . V_17 = V_2 ;
V_15 . V_27 = F_11 ;
V_15 . V_28 = F_12 ;
switch ( F_4 ( V_5 , V_29 ) )
{
case 0 :
V_15 . V_30 = V_31 ;
break;
case 1 :
V_15 . V_30 = V_32 ;
break;
default:
V_15 . V_30 = V_33 ;
break;
}
V_15 . V_19 = 0 ;
V_15 . V_21 = 0 ;
V_15 . V_23 = 0 ;
V_15 . V_25 = 0 ;
F_15 ( & V_15 , V_34 , V_2 -> V_15 ,
V_14 / sizeof( V_35 ) ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_17 ( V_2 ) ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
}
static inline int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
}
static void F_20 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_2 V_5 ;
switch ( V_37 -> V_38 ) {
case V_39 :
F_3 ( V_2 , V_40 , & V_5 ) ;
F_13 ( & V_5 , V_41 , 1 ) ;
F_6 ( V_2 , V_40 , V_5 ) ;
break;
case V_42 :
F_3 ( V_2 , V_43 , & V_5 ) ;
F_13 ( & V_5 , V_44 , 1 ) ;
F_13 ( & V_5 , V_45 , 1 ) ;
F_13 ( & V_5 , V_46 , 1 ) ;
F_6 ( V_2 , V_43 , V_5 ) ;
F_3 ( V_2 , V_47 , & V_5 ) ;
F_13 ( & V_5 , V_48 , 1 ) ;
F_6 ( V_2 , V_47 , V_5 ) ;
break;
default:
break;
}
}
static void F_21 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_49 * V_50 ;
switch ( V_37 -> V_38 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_50 = F_22 ( V_37 , V_55 ) ;
F_6 ( V_2 , F_23 ( V_37 -> V_38 ) ,
V_50 -> V_56 ) ;
break;
case V_57 :
V_50 = F_22 ( V_37 , V_55 ) ;
F_6 ( V_2 , F_23 ( 5 ) ,
V_50 -> V_56 ) ;
break;
default:
break;
}
}
static void F_24 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_2 V_5 ;
switch ( V_37 -> V_38 ) {
case V_39 :
F_3 ( V_2 , V_40 , & V_5 ) ;
F_13 ( & V_5 , V_41 , 0 ) ;
F_6 ( V_2 , V_40 , V_5 ) ;
break;
case V_42 :
F_3 ( V_2 , V_43 , & V_5 ) ;
F_13 ( & V_5 , V_44 , 0 ) ;
F_13 ( & V_5 , V_45 , 0 ) ;
F_13 ( & V_5 , V_46 , 0 ) ;
F_6 ( V_2 , V_43 , V_5 ) ;
F_3 ( V_2 , V_47 , & V_5 ) ;
F_13 ( & V_5 , V_48 , 0 ) ;
F_6 ( V_2 , V_47 , V_5 ) ;
F_25 ( & V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_59 ) ;
break;
default:
break;
}
}
static char * F_26 ( struct V_1 * V_2 )
{
if ( F_27 ( V_2 , V_60 ) )
return V_61 ;
else
return V_62 ;
}
static int F_28 ( struct V_1 * V_2 ,
const T_1 * V_17 , const T_4 V_63 )
{
T_2 V_5 ;
V_5 = 0 ;
F_13 ( & V_5 , V_64 , 1 ) ;
F_6 ( V_2 , V_65 , V_5 ) ;
F_29 ( V_2 , V_66 ,
V_17 , V_63 ) ;
F_6 ( V_2 , V_65 , 0x00000 ) ;
F_6 ( V_2 , V_65 , 0x00001 ) ;
F_6 ( V_2 , V_67 , 0 ) ;
F_6 ( V_2 , V_68 , 0 ) ;
return 0 ;
}
static bool F_30 ( struct V_49 * V_50 )
{
struct V_69 * V_70 = V_50 -> V_71 ;
T_2 V_72 ;
if ( V_50 -> V_37 -> V_38 == V_39 ) {
F_31 ( V_70 -> V_73 , 1 , & V_72 ) ;
return ( ! F_4 ( V_72 , V_74 ) ) ;
} else {
F_31 ( V_70 -> V_73 , 1 , & V_72 ) ;
return ( ! F_4 ( V_72 , V_75 ) ) ;
}
}
static void F_32 ( struct V_49 * V_50 )
{
struct V_69 * V_70 = V_50 -> V_71 ;
struct V_76 * V_77 = F_33 ( V_50 -> V_78 ) ;
struct V_1 * V_2 = V_50 -> V_37 -> V_2 ;
T_2 V_72 ;
if ( V_50 -> V_37 -> V_38 == V_39 ) {
F_31 ( V_70 -> V_73 , 0 , & V_72 ) ;
F_13 ( & V_72 , V_79 , V_77 -> V_80 ) ;
F_34 ( V_70 -> V_73 , 0 , V_72 ) ;
F_31 ( V_70 -> V_73 , 1 , & V_72 ) ;
F_13 ( & V_72 , V_74 , 0 ) ;
F_34 ( V_70 -> V_73 , 1 , V_72 ) ;
F_6 ( V_2 , V_81 ,
V_50 -> V_56 ) ;
} else {
F_31 ( V_70 -> V_73 , 1 , & V_72 ) ;
F_13 ( & V_72 , V_75 , 1 ) ;
F_34 ( V_70 -> V_73 , 1 , V_72 ) ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
V_70 = V_2 -> V_82 [ 0 ] . V_83 [ 0 ] . V_71 ;
F_6 ( V_2 , V_84 , V_70 -> V_85 ) ;
F_6 ( V_2 , V_86 ,
V_2 -> V_82 [ 0 ] . V_87 ) ;
F_6 ( V_2 , V_88 , 0 ) ;
F_6 ( V_2 , V_89 , 0 ) ;
V_70 = V_2 -> V_82 [ 1 ] . V_83 [ 0 ] . V_71 ;
F_6 ( V_2 , V_90 , V_70 -> V_85 ) ;
F_6 ( V_2 , V_91 ,
V_2 -> V_82 [ 1 ] . V_87 ) ;
F_6 ( V_2 , V_92 , 0 ) ;
F_6 ( V_2 , V_93 , 0 ) ;
V_70 = V_2 -> V_82 [ 2 ] . V_83 [ 0 ] . V_71 ;
F_6 ( V_2 , V_94 , V_70 -> V_85 ) ;
F_6 ( V_2 , V_95 ,
V_2 -> V_82 [ 2 ] . V_87 ) ;
F_6 ( V_2 , V_96 , 0 ) ;
F_6 ( V_2 , V_97 , 0 ) ;
V_70 = V_2 -> V_82 [ 3 ] . V_83 [ 0 ] . V_71 ;
F_6 ( V_2 , V_98 , V_70 -> V_85 ) ;
F_6 ( V_2 , V_99 ,
V_2 -> V_82 [ 3 ] . V_87 ) ;
F_6 ( V_2 , V_100 , 0 ) ;
F_6 ( V_2 , V_101 , 0 ) ;
F_6 ( V_2 , V_102 , 0 ) ;
F_6 ( V_2 , V_103 , 0 ) ;
F_6 ( V_2 , V_104 , 0 ) ;
F_6 ( V_2 , V_105 , 0 ) ;
F_6 ( V_2 , V_106 , 0 ) ;
F_6 ( V_2 , V_107 , 0 ) ;
F_6 ( V_2 , V_108 , 0 ) ;
F_6 ( V_2 , V_109 , 0 ) ;
V_70 = V_2 -> V_110 -> V_83 [ 0 ] . V_71 ;
F_6 ( V_2 , V_111 , V_70 -> V_85 ) ;
F_6 ( V_2 , V_112 ,
V_2 -> V_110 [ 0 ] . V_87 ) ;
F_6 ( V_2 , V_81 ,
V_2 -> V_110 [ 0 ] . V_87 - 1 ) ;
F_6 ( V_2 , V_113 , 0 ) ;
F_36 ( V_2 ) ;
F_6 ( V_2 , V_114 , 0 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 ,
enum V_115 V_116 )
{
T_2 V_5 ;
unsigned long V_117 ;
if ( V_116 == V_118 ) {
F_3 ( V_2 , V_119 , & V_5 ) ;
F_6 ( V_2 , V_119 , V_5 ) ;
}
F_38 ( & V_2 -> V_120 , V_117 ) ;
V_5 = 0 ;
if ( V_116 == V_118 ) {
F_13 ( & V_5 , V_121 , 1 ) ;
F_13 ( & V_5 , V_122 , 1 ) ;
F_13 ( & V_5 , V_123 , 1 ) ;
F_13 ( & V_5 , V_124 , 1 ) ;
F_13 ( & V_5 , V_125 , 1 ) ;
}
F_6 ( V_2 , V_126 , V_5 ) ;
F_39 ( & V_2 -> V_120 , V_117 ) ;
if ( V_116 == V_127 ) {
F_25 ( & V_2 -> V_128 ) ;
F_25 ( & V_2 -> V_129 ) ;
F_25 ( & V_2 -> V_130 ) ;
F_25 ( & V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_59 ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
T_2 V_5 ;
F_3 ( V_2 , V_131 , & V_5 ) ;
F_13 ( & V_5 , V_132 , 1 ) ;
F_13 ( & V_5 , V_133 , 1 ) ;
F_13 ( & V_5 , V_134 , 1 ) ;
F_13 ( & V_5 , V_135 , 1 ) ;
F_13 ( & V_5 , V_136 , 1 ) ;
F_13 ( & V_5 , V_137 , 1 ) ;
F_13 ( & V_5 , V_138 , 1 ) ;
F_6 ( V_2 , V_131 , V_5 ) ;
F_6 ( V_2 , V_65 , 0x00000e1f ) ;
F_6 ( V_2 , V_65 , 0x00000e00 ) ;
if ( F_41 ( V_2 ) &&
( F_27 ( V_2 , V_139 ) ||
F_27 ( V_2 , V_140 ) ||
F_27 ( V_2 , V_141 ) ) ) {
F_3 ( V_2 , V_142 , & V_5 ) ;
F_13 ( & V_5 , V_143 , 1 ) ;
F_13 ( & V_5 , V_144 , 1 ) ;
F_6 ( V_2 , V_142 , V_5 ) ;
}
F_6 ( V_2 , V_145 , 0x00000003 ) ;
V_5 = 0 ;
F_13 ( & V_5 , V_146 , 1 ) ;
F_13 ( & V_5 , V_147 , 1 ) ;
F_6 ( V_2 , V_40 , V_5 ) ;
F_6 ( V_2 , V_40 , 0x00000000 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_148 ;
F_43 ( V_2 ) ;
if ( F_44 ( F_35 ( V_2 ) ) )
return - V_149 ;
V_148 = F_45 ( V_2 ) ;
if ( V_148 )
return V_148 ;
F_6 ( V_2 , V_12 , ~ 0 ) ;
F_6 ( V_2 , V_6 , ~ 0 ) ;
F_46 ( V_2 , V_150 , V_151 , 0xff , 0x02 ) ;
F_1 ( V_2 , V_151 ) ;
F_46 ( V_2 , V_152 , V_153 , 0 , 0 ) ;
F_1 ( V_2 , V_153 ) ;
return V_148 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_48 ( V_2 ) ;
F_6 ( V_2 , V_145 , 0 ) ;
F_6 ( V_2 , V_154 , 0 ) ;
}
}
static int F_49 ( struct V_1 * V_2 ,
enum V_115 V_116 )
{
if ( V_116 == V_155 ) {
F_46 ( V_2 , V_152 , V_153 ,
0 , 0x02 ) ;
F_1 ( V_2 , V_153 ) ;
} else if ( V_116 == V_156 ) {
F_6 ( V_2 , V_12 ,
0xffffffff ) ;
F_6 ( V_2 , V_6 ,
0xffffffff ) ;
F_46 ( V_2 , V_150 , V_157 ,
0xff , 0x01 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
enum V_115 V_116 )
{
int V_148 = 0 ;
switch ( V_116 ) {
case V_158 :
V_148 = F_42 ( V_2 ) ;
break;
case V_159 :
F_47 ( V_2 ) ;
F_49 ( V_2 , V_156 ) ;
break;
case V_118 :
case V_127 :
F_37 ( V_2 , V_116 ) ;
break;
case V_160 :
case V_156 :
case V_161 :
case V_155 :
V_148 = F_49 ( V_2 , V_116 ) ;
break;
default:
V_148 = - V_162 ;
break;
}
if ( F_44 ( V_148 ) )
ERROR ( V_2 , L_2 ,
V_116 , V_148 ) ;
return V_148 ;
}
static T_5 * F_51 ( struct V_49 * V_50 )
{
return ( T_5 * ) V_50 -> V_78 -> V_17 ;
}
static void F_52 ( struct V_49 * V_50 ,
struct V_163 * V_164 )
{
struct V_76 * V_77 = F_33 ( V_50 -> V_78 ) ;
struct V_69 * V_70 = V_50 -> V_71 ;
T_5 * V_165 = V_70 -> V_73 ;
T_2 V_72 ;
V_72 = 0 ;
F_13 ( & V_72 , V_166 , V_77 -> V_80 ) ;
F_34 ( V_165 , 0 , V_72 ) ;
V_72 = 0 ;
F_13 ( & V_72 , V_167 , V_50 -> V_78 -> V_63 ) ;
F_13 ( & V_72 , V_168 ,
! F_53 ( V_169 , & V_164 -> V_117 ) ) ;
F_13 ( & V_72 , V_170 ,
F_53 ( V_171 , & V_164 -> V_117 ) ) ;
F_13 ( & V_72 , V_172 , V_173 ) ;
F_13 ( & V_72 , V_174 , 0 ) ;
F_13 ( & V_72 , V_75 , 0 ) ;
F_34 ( V_165 , 1 , V_72 ) ;
V_72 = 0 ;
F_13 ( & V_72 , V_175 ,
V_77 -> V_80 + V_173 ) ;
F_34 ( V_165 , 2 , V_72 ) ;
V_72 = 0 ;
F_13 ( & V_72 , V_176 ,
! F_53 ( V_177 , & V_164 -> V_117 ) ) ;
F_13 ( & V_72 , V_178 , 2 ) ;
F_34 ( V_165 , 3 , V_72 ) ;
V_77 -> V_73 = V_165 ;
V_77 -> V_179 = V_180 ;
}
static void F_54 ( struct V_49 * V_50 ,
struct V_181 * V_182 )
{
struct V_69 * V_70 = V_50 -> V_71 ;
T_5 * V_183 = V_70 -> V_73 ;
T_2 V_72 ;
F_31 ( V_183 , 3 , & V_72 ) ;
if ( F_4 ( V_72 , V_184 ) )
V_182 -> V_117 |= V_185 ;
V_182 -> V_186 = F_4 ( V_72 , V_187 ) ;
if ( F_4 ( V_72 , V_188 ) ) {
V_182 -> V_117 |= V_189 ;
V_182 -> V_117 |= V_190 ;
if ( V_182 -> V_186 == V_191 )
V_182 -> V_117 |= V_192 ;
else if ( V_182 -> V_186 == V_193 )
V_182 -> V_117 |= V_194 ;
}
if ( F_4 ( V_72 , V_195 ) )
V_182 -> V_196 |= V_197 ;
if ( F_4 ( V_72 , V_198 ) )
V_182 -> V_196 |= V_199 ;
F_55 ( V_50 , V_182 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_200 V_201 = { . V_117 = 0 } ;
struct V_202 V_203 = { . V_201 = & V_201 } ;
F_57 ( V_2 , & V_203 , V_204 ) ;
}
static bool F_58 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_49 * V_50 ;
T_2 V_205 ;
T_1 V_38 ;
int V_206 = 16 ;
while ( F_59 ( & V_2 -> V_207 , & V_205 ) ) {
V_38 = F_4 ( V_205 , V_208 ) ;
if ( F_44 ( V_38 >= V_39 ) ) {
F_60 ( V_2 , L_3
L_4 , V_38 ) ;
break;
}
V_37 = F_61 ( V_2 , V_38 ) ;
if ( F_44 ( V_37 == NULL ) ) {
F_60 ( V_2 , L_5
L_6 , V_38 ) ;
break;
}
if ( F_44 ( F_62 ( V_37 ) ) ) {
F_60 ( V_2 , L_7
L_6 , V_38 ) ;
break;
}
V_50 = F_22 ( V_37 , V_209 ) ;
F_63 ( V_50 , V_205 , F_51 ( V_50 ) ) ;
if ( -- V_206 == 0 )
break;
}
return ! V_206 ;
}
static inline void F_64 ( struct V_1 * V_2 ,
struct V_210 V_211 )
{
T_2 V_5 ;
F_65 ( & V_2 -> V_120 ) ;
F_3 ( V_2 , V_126 , & V_5 ) ;
F_13 ( & V_5 , V_211 , 1 ) ;
F_6 ( V_2 , V_126 , V_5 ) ;
F_66 ( & V_2 -> V_120 ) ;
}
static void F_67 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
if ( F_58 ( V_2 ) )
F_68 ( & V_2 -> V_128 ) ;
}
static void F_69 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
F_70 ( V_2 ) ;
if ( F_53 ( V_212 , & V_2 -> V_117 ) )
F_64 ( V_2 , V_123 ) ;
}
static void F_71 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
struct V_213 * V_214 = V_2 -> V_214 ;
T_2 V_5 ;
F_72 ( V_2 ) ;
if ( V_2 -> V_215 ) {
if ( V_214 -> V_216 == ( V_217 - 2 ) ) {
F_3 ( V_2 , V_43 , & V_5 ) ;
F_13 ( & V_5 , V_218 ,
( V_2 -> V_219 * 16 ) - 1 ) ;
F_6 ( V_2 , V_43 , V_5 ) ;
} else if ( V_214 -> V_216 == ( V_217 - 1 ) ) {
F_3 ( V_2 , V_43 , & V_5 ) ;
F_13 ( & V_5 , V_218 ,
( V_2 -> V_219 * 16 ) ) ;
F_6 ( V_2 , V_43 , V_5 ) ;
}
V_214 -> V_216 ++ ;
V_214 -> V_216 %= V_217 ;
}
if ( F_53 ( V_212 , & V_2 -> V_117 ) )
F_64 ( V_2 , V_122 ) ;
}
static void F_73 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
if ( F_74 ( V_2 ) )
F_68 ( & V_2 -> V_129 ) ;
else if ( F_53 ( V_212 , & V_2 -> V_117 ) )
F_64 ( V_2 , V_121 ) ;
}
static void F_75 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
F_56 ( V_2 ) ;
if ( F_53 ( V_212 , & V_2 -> V_117 ) )
F_64 ( V_2 , V_125 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
T_2 V_205 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_220 -> V_82 -> V_221 ; V_4 ++ ) {
F_3 ( V_2 , V_222 , & V_205 ) ;
if ( ! F_4 ( V_205 , V_223 ) )
break;
if ( ! F_77 ( & V_2 -> V_207 , & V_205 ) ) {
F_60 ( V_2 , L_8
L_9 ) ;
break;
}
}
F_68 ( & V_2 -> V_128 ) ;
}
static T_6 F_78 ( int V_224 , void * V_225 )
{
struct V_1 * V_2 = V_225 ;
T_2 V_5 , V_226 ;
F_3 ( V_2 , V_119 , & V_5 ) ;
F_6 ( V_2 , V_119 , V_5 ) ;
if ( ! V_5 )
return V_227 ;
if ( ! F_53 ( V_212 , & V_2 -> V_117 ) )
return V_228 ;
V_226 = ~ V_5 ;
if ( F_4 ( V_5 , V_229 ) ) {
F_76 ( V_2 ) ;
F_13 ( & V_226 , V_124 , 1 ) ;
}
if ( F_4 ( V_5 , V_230 ) )
F_79 ( & V_2 -> V_59 ) ;
if ( F_4 ( V_5 , V_231 ) )
F_79 ( & V_2 -> V_58 ) ;
if ( F_4 ( V_5 , V_232 ) )
F_68 ( & V_2 -> V_129 ) ;
if ( F_4 ( V_5 , V_233 ) )
F_68 ( & V_2 -> V_130 ) ;
F_80 ( & V_2 -> V_120 ) ;
F_3 ( V_2 , V_126 , & V_5 ) ;
V_5 &= V_226 ;
F_6 ( V_2 , V_126 , V_5 ) ;
F_81 ( & V_2 -> V_120 ) ;
return V_228 ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
F_7 ( V_2 ) ;
else if ( F_16 ( V_2 ) )
F_18 ( V_2 ) ;
else
F_14 ( V_2 ) ;
return F_83 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_148 ;
T_2 V_5 ;
V_148 = F_82 ( V_2 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_85 ( V_2 ) ;
if ( V_148 )
return V_148 ;
F_3 ( V_2 , V_234 , & V_5 ) ;
F_13 ( & V_5 , V_235 , 1 ) ;
F_6 ( V_2 , V_234 , V_5 ) ;
V_148 = F_86 ( V_2 ) ;
if ( V_148 )
return V_148 ;
F_87 ( V_236 , & V_2 -> V_237 ) ;
F_87 ( V_238 , & V_2 -> V_237 ) ;
F_87 ( V_239 , & V_2 -> V_237 ) ;
if ( ! F_2 ( V_2 ) )
F_87 ( V_240 , & V_2 -> V_237 ) ;
F_87 ( V_241 , & V_2 -> V_237 ) ;
F_87 ( V_242 , & V_2 -> V_237 ) ;
F_87 ( V_243 , & V_2 -> V_237 ) ;
F_87 ( V_244 , & V_2 -> V_237 ) ;
if ( ! V_245 )
F_87 ( V_246 , & V_2 -> V_237 ) ;
F_87 ( V_247 , & V_2 -> V_237 ) ;
F_87 ( V_248 , & V_2 -> V_237 ) ;
V_2 -> V_249 = V_250 ;
return 0 ;
}
static int F_88 ( struct V_251 * V_252 )
{
return F_89 ( V_252 , & V_253 ) ;
}
static int F_90 ( struct V_254 * V_254 ,
const struct V_255 * V_256 )
{
return F_91 ( V_254 , & V_253 ) ;
}
static int T_7 F_92 ( void )
{
int V_257 = 0 ;
#if F_93 ( V_258 ) || F_93 ( V_259 )
V_257 = F_94 ( & V_260 ) ;
if ( V_257 )
return V_257 ;
#endif
#ifdef F_95
V_257 = F_96 ( & V_261 ) ;
if ( V_257 ) {
#if F_93 ( V_258 ) || F_93 ( V_259 )
F_97 ( & V_260 ) ;
#endif
return V_257 ;
}
#endif
return V_257 ;
}
static void T_8 F_98 ( void )
{
#ifdef F_95
F_99 ( & V_261 ) ;
#endif
#if F_93 ( V_258 ) || F_93 ( V_259 )
F_97 ( & V_260 ) ;
#endif
}
