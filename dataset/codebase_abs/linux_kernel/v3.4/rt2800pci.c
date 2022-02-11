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
return V_60 ;
}
static int F_27 ( struct V_1 * V_2 ,
const T_1 * V_17 , const T_4 V_61 )
{
T_2 V_5 ;
V_5 = 0 ;
F_13 ( & V_5 , V_62 , 1 ) ;
F_6 ( V_2 , V_63 , V_5 ) ;
F_28 ( V_2 , V_64 ,
V_17 , V_61 ) ;
F_6 ( V_2 , V_63 , 0x00000 ) ;
F_6 ( V_2 , V_63 , 0x00001 ) ;
F_6 ( V_2 , V_65 , 0 ) ;
F_6 ( V_2 , V_66 , 0 ) ;
return 0 ;
}
static bool F_29 ( struct V_49 * V_50 )
{
struct V_67 * V_68 = V_50 -> V_69 ;
T_2 V_70 ;
if ( V_50 -> V_37 -> V_38 == V_39 ) {
F_30 ( V_68 -> V_71 , 1 , & V_70 ) ;
return ( ! F_4 ( V_70 , V_72 ) ) ;
} else {
F_30 ( V_68 -> V_71 , 1 , & V_70 ) ;
return ( ! F_4 ( V_70 , V_73 ) ) ;
}
}
static void F_31 ( struct V_49 * V_50 )
{
struct V_67 * V_68 = V_50 -> V_69 ;
struct V_74 * V_75 = F_32 ( V_50 -> V_76 ) ;
struct V_1 * V_2 = V_50 -> V_37 -> V_2 ;
T_2 V_70 ;
if ( V_50 -> V_37 -> V_38 == V_39 ) {
F_30 ( V_68 -> V_71 , 0 , & V_70 ) ;
F_13 ( & V_70 , V_77 , V_75 -> V_78 ) ;
F_33 ( V_68 -> V_71 , 0 , V_70 ) ;
F_30 ( V_68 -> V_71 , 1 , & V_70 ) ;
F_13 ( & V_70 , V_72 , 0 ) ;
F_33 ( V_68 -> V_71 , 1 , V_70 ) ;
F_6 ( V_2 , V_79 ,
V_50 -> V_56 ) ;
} else {
F_30 ( V_68 -> V_71 , 1 , & V_70 ) ;
F_13 ( & V_70 , V_73 , 1 ) ;
F_33 ( V_68 -> V_71 , 1 , V_70 ) ;
}
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_67 * V_68 ;
T_2 V_5 ;
V_68 = V_2 -> V_80 [ 0 ] . V_81 [ 0 ] . V_69 ;
F_6 ( V_2 , V_82 , V_68 -> V_83 ) ;
F_6 ( V_2 , V_84 ,
V_2 -> V_80 [ 0 ] . V_85 ) ;
F_6 ( V_2 , V_86 , 0 ) ;
F_6 ( V_2 , V_87 , 0 ) ;
V_68 = V_2 -> V_80 [ 1 ] . V_81 [ 0 ] . V_69 ;
F_6 ( V_2 , V_88 , V_68 -> V_83 ) ;
F_6 ( V_2 , V_89 ,
V_2 -> V_80 [ 1 ] . V_85 ) ;
F_6 ( V_2 , V_90 , 0 ) ;
F_6 ( V_2 , V_91 , 0 ) ;
V_68 = V_2 -> V_80 [ 2 ] . V_81 [ 0 ] . V_69 ;
F_6 ( V_2 , V_92 , V_68 -> V_83 ) ;
F_6 ( V_2 , V_93 ,
V_2 -> V_80 [ 2 ] . V_85 ) ;
F_6 ( V_2 , V_94 , 0 ) ;
F_6 ( V_2 , V_95 , 0 ) ;
V_68 = V_2 -> V_80 [ 3 ] . V_81 [ 0 ] . V_69 ;
F_6 ( V_2 , V_96 , V_68 -> V_83 ) ;
F_6 ( V_2 , V_97 ,
V_2 -> V_80 [ 3 ] . V_85 ) ;
F_6 ( V_2 , V_98 , 0 ) ;
F_6 ( V_2 , V_99 , 0 ) ;
V_68 = V_2 -> V_100 -> V_81 [ 0 ] . V_69 ;
F_6 ( V_2 , V_101 , V_68 -> V_83 ) ;
F_6 ( V_2 , V_102 ,
V_2 -> V_100 [ 0 ] . V_85 ) ;
F_6 ( V_2 , V_79 ,
V_2 -> V_100 [ 0 ] . V_85 - 1 ) ;
F_6 ( V_2 , V_103 , 0 ) ;
F_3 ( V_2 , V_104 , & V_5 ) ;
F_13 ( & V_5 , V_105 , 0 ) ;
F_13 ( & V_5 , V_106 , 0 ) ;
F_13 ( & V_5 , V_107 , 1 ) ;
F_6 ( V_2 , V_104 , V_5 ) ;
F_6 ( V_2 , V_108 , 0 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 ,
enum V_109 V_110 )
{
T_2 V_5 ;
unsigned long V_111 ;
if ( V_110 == V_112 ) {
F_3 ( V_2 , V_113 , & V_5 ) ;
F_6 ( V_2 , V_113 , V_5 ) ;
}
F_36 ( & V_2 -> V_114 , V_111 ) ;
V_5 = 0 ;
if ( V_110 == V_112 ) {
F_13 ( & V_5 , V_115 , 1 ) ;
F_13 ( & V_5 , V_116 , 1 ) ;
F_13 ( & V_5 , V_117 , 1 ) ;
F_13 ( & V_5 , V_118 , 1 ) ;
F_13 ( & V_5 , V_119 , 1 ) ;
}
F_6 ( V_2 , V_120 , V_5 ) ;
F_37 ( & V_2 -> V_114 , V_111 ) ;
if ( V_110 == V_121 ) {
F_25 ( & V_2 -> V_122 ) ;
F_25 ( & V_2 -> V_123 ) ;
F_25 ( & V_2 -> V_124 ) ;
F_25 ( & V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_59 ) ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
T_2 V_5 ;
F_3 ( V_2 , V_125 , & V_5 ) ;
F_13 ( & V_5 , V_126 , 1 ) ;
F_13 ( & V_5 , V_127 , 1 ) ;
F_13 ( & V_5 , V_128 , 1 ) ;
F_13 ( & V_5 , V_129 , 1 ) ;
F_13 ( & V_5 , V_130 , 1 ) ;
F_13 ( & V_5 , V_131 , 1 ) ;
F_13 ( & V_5 , V_132 , 1 ) ;
F_6 ( V_2 , V_125 , V_5 ) ;
F_6 ( V_2 , V_63 , 0x00000e1f ) ;
F_6 ( V_2 , V_63 , 0x00000e00 ) ;
if ( F_39 ( V_2 ) &&
( F_40 ( V_2 , V_133 ) ||
F_40 ( V_2 , V_134 ) ||
F_40 ( V_2 , V_135 ) ) ) {
F_3 ( V_2 , V_136 , & V_5 ) ;
F_13 ( & V_5 , V_137 , 1 ) ;
F_13 ( & V_5 , V_138 , 1 ) ;
F_6 ( V_2 , V_136 , V_5 ) ;
}
F_6 ( V_2 , V_139 , 0x00000003 ) ;
V_5 = 0 ;
F_13 ( & V_5 , V_140 , 1 ) ;
F_13 ( & V_5 , V_141 , 1 ) ;
F_6 ( V_2 , V_40 , V_5 ) ;
F_6 ( V_2 , V_40 , 0x00000000 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_142 ;
if ( F_42 ( F_43 ( V_2 ) ||
F_34 ( V_2 ) ) )
return - V_143 ;
V_142 = F_44 ( V_2 ) ;
if ( V_142 )
return V_142 ;
F_6 ( V_2 , V_12 , ~ 0 ) ;
F_6 ( V_2 , V_6 , ~ 0 ) ;
F_45 ( V_2 , V_144 , V_145 , 0xff , 0x02 ) ;
F_1 ( V_2 , V_145 ) ;
F_45 ( V_2 , V_146 , V_147 , 0 , 0 ) ;
F_1 ( V_2 , V_147 ) ;
return V_142 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_47 ( V_2 ) ;
F_6 ( V_2 , V_139 , 0 ) ;
F_6 ( V_2 , V_148 , 0 ) ;
}
}
static int F_48 ( struct V_1 * V_2 ,
enum V_109 V_110 )
{
if ( V_110 == V_149 ) {
F_45 ( V_2 , V_146 , V_147 ,
0 , 0x02 ) ;
F_1 ( V_2 , V_147 ) ;
} else if ( V_110 == V_150 ) {
F_6 ( V_2 , V_12 ,
0xffffffff ) ;
F_6 ( V_2 , V_6 ,
0xffffffff ) ;
F_45 ( V_2 , V_144 , V_151 ,
0xff , 0x01 ) ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
enum V_109 V_110 )
{
int V_142 = 0 ;
switch ( V_110 ) {
case V_152 :
V_142 = F_41 ( V_2 ) ;
break;
case V_153 :
F_46 ( V_2 ) ;
F_48 ( V_2 , V_150 ) ;
break;
case V_112 :
case V_121 :
F_35 ( V_2 , V_110 ) ;
break;
case V_154 :
case V_150 :
case V_155 :
case V_149 :
V_142 = F_48 ( V_2 , V_110 ) ;
break;
default:
V_142 = - V_156 ;
break;
}
if ( F_42 ( V_142 ) )
ERROR ( V_2 , L_2 ,
V_110 , V_142 ) ;
return V_142 ;
}
static T_5 * F_50 ( struct V_49 * V_50 )
{
return ( T_5 * ) V_50 -> V_76 -> V_17 ;
}
static void F_51 ( struct V_49 * V_50 ,
struct V_157 * V_158 )
{
struct V_74 * V_75 = F_32 ( V_50 -> V_76 ) ;
struct V_67 * V_68 = V_50 -> V_69 ;
T_5 * V_159 = V_68 -> V_71 ;
T_2 V_70 ;
V_70 = 0 ;
F_13 ( & V_70 , V_160 , V_75 -> V_78 ) ;
F_33 ( V_159 , 0 , V_70 ) ;
V_70 = 0 ;
F_13 ( & V_70 , V_161 , V_50 -> V_76 -> V_61 ) ;
F_13 ( & V_70 , V_162 ,
! F_52 ( V_163 , & V_158 -> V_111 ) ) ;
F_13 ( & V_70 , V_164 ,
F_52 ( V_165 , & V_158 -> V_111 ) ) ;
F_13 ( & V_70 , V_166 , V_167 ) ;
F_13 ( & V_70 , V_168 , 0 ) ;
F_13 ( & V_70 , V_73 , 0 ) ;
F_33 ( V_159 , 1 , V_70 ) ;
V_70 = 0 ;
F_13 ( & V_70 , V_169 ,
V_75 -> V_78 + V_167 ) ;
F_33 ( V_159 , 2 , V_70 ) ;
V_70 = 0 ;
F_13 ( & V_70 , V_170 ,
! F_52 ( V_171 , & V_158 -> V_111 ) ) ;
F_13 ( & V_70 , V_172 , 2 ) ;
F_33 ( V_159 , 3 , V_70 ) ;
V_75 -> V_71 = V_159 ;
V_75 -> V_173 = V_174 ;
}
static void F_53 ( struct V_49 * V_50 ,
struct V_175 * V_176 )
{
struct V_67 * V_68 = V_50 -> V_69 ;
T_5 * V_177 = V_68 -> V_71 ;
T_2 V_70 ;
F_30 ( V_177 , 3 , & V_70 ) ;
if ( F_4 ( V_70 , V_178 ) )
V_176 -> V_111 |= V_179 ;
V_176 -> V_180 = F_4 ( V_70 , V_181 ) ;
if ( F_4 ( V_70 , V_182 ) ) {
V_176 -> V_111 |= V_183 ;
V_176 -> V_111 |= V_184 ;
if ( V_176 -> V_180 == V_185 )
V_176 -> V_111 |= V_186 ;
else if ( V_176 -> V_180 == V_187 )
V_176 -> V_111 |= V_188 ;
}
if ( F_4 ( V_70 , V_189 ) )
V_176 -> V_190 |= V_191 ;
if ( F_4 ( V_70 , V_192 ) )
V_176 -> V_190 |= V_193 ;
F_54 ( V_50 , V_176 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_194 V_195 = { . V_111 = 0 } ;
struct V_196 V_197 = { . V_195 = & V_195 } ;
F_56 ( V_2 , & V_197 , V_198 ) ;
}
static bool F_57 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_49 * V_50 ;
T_2 V_199 ;
T_1 V_38 ;
int V_200 = 16 ;
while ( F_58 ( & V_2 -> V_201 , & V_199 ) ) {
V_38 = F_4 ( V_199 , V_202 ) ;
if ( F_42 ( V_38 >= V_39 ) ) {
F_59 ( V_2 , L_3
L_4 , V_38 ) ;
break;
}
V_37 = F_60 ( V_2 , V_38 ) ;
if ( F_42 ( V_37 == NULL ) ) {
F_59 ( V_2 , L_5
L_6 , V_38 ) ;
break;
}
if ( F_42 ( F_61 ( V_37 ) ) ) {
F_59 ( V_2 , L_7
L_6 , V_38 ) ;
break;
}
V_50 = F_22 ( V_37 , V_203 ) ;
F_62 ( V_50 , V_199 , F_50 ( V_50 ) ) ;
if ( -- V_200 == 0 )
break;
}
return ! V_200 ;
}
static inline void F_63 ( struct V_1 * V_2 ,
struct V_204 V_205 )
{
T_2 V_5 ;
F_64 ( & V_2 -> V_114 ) ;
F_3 ( V_2 , V_120 , & V_5 ) ;
F_13 ( & V_5 , V_205 , 1 ) ;
F_6 ( V_2 , V_120 , V_5 ) ;
F_65 ( & V_2 -> V_114 ) ;
}
static void F_66 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
if ( F_57 ( V_2 ) )
F_67 ( & V_2 -> V_122 ) ;
}
static void F_68 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
F_69 ( V_2 ) ;
if ( F_52 ( V_206 , & V_2 -> V_111 ) )
F_63 ( V_2 , V_117 ) ;
}
static void F_70 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
struct V_207 * V_208 = V_2 -> V_208 ;
T_2 V_5 ;
F_71 ( V_2 ) ;
if ( V_2 -> V_209 ) {
if ( V_208 -> V_210 == ( V_211 - 2 ) ) {
F_3 ( V_2 , V_43 , & V_5 ) ;
F_13 ( & V_5 , V_212 ,
( V_2 -> V_213 * 16 ) - 1 ) ;
F_6 ( V_2 , V_43 , V_5 ) ;
} else if ( V_208 -> V_210 == ( V_211 - 1 ) ) {
F_3 ( V_2 , V_43 , & V_5 ) ;
F_13 ( & V_5 , V_212 ,
( V_2 -> V_213 * 16 ) ) ;
F_6 ( V_2 , V_43 , V_5 ) ;
}
V_208 -> V_210 ++ ;
V_208 -> V_210 %= V_211 ;
}
if ( F_52 ( V_206 , & V_2 -> V_111 ) )
F_63 ( V_2 , V_116 ) ;
}
static void F_72 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
if ( F_73 ( V_2 ) )
F_67 ( & V_2 -> V_123 ) ;
else if ( F_52 ( V_206 , & V_2 -> V_111 ) )
F_63 ( V_2 , V_115 ) ;
}
static void F_74 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
F_55 ( V_2 ) ;
if ( F_52 ( V_206 , & V_2 -> V_111 ) )
F_63 ( V_2 , V_119 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
T_2 V_199 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_214 -> V_80 -> V_215 ; V_4 ++ ) {
F_3 ( V_2 , V_216 , & V_199 ) ;
if ( ! F_4 ( V_199 , V_217 ) )
break;
if ( ! F_76 ( & V_2 -> V_201 , & V_199 ) ) {
F_59 ( V_2 , L_8
L_9 ) ;
break;
}
}
F_67 ( & V_2 -> V_122 ) ;
}
static T_6 F_77 ( int V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
T_2 V_5 , V_220 ;
F_3 ( V_2 , V_113 , & V_5 ) ;
F_6 ( V_2 , V_113 , V_5 ) ;
if ( ! V_5 )
return V_221 ;
if ( ! F_52 ( V_206 , & V_2 -> V_111 ) )
return V_222 ;
V_220 = ~ V_5 ;
if ( F_4 ( V_5 , V_223 ) ) {
F_75 ( V_2 ) ;
F_13 ( & V_220 , V_118 , 1 ) ;
}
if ( F_4 ( V_5 , V_224 ) )
F_78 ( & V_2 -> V_59 ) ;
if ( F_4 ( V_5 , V_225 ) )
F_78 ( & V_2 -> V_58 ) ;
if ( F_4 ( V_5 , V_226 ) )
F_67 ( & V_2 -> V_123 ) ;
if ( F_4 ( V_5 , V_227 ) )
F_67 ( & V_2 -> V_124 ) ;
F_79 ( & V_2 -> V_114 ) ;
F_3 ( V_2 , V_120 , & V_5 ) ;
V_5 &= V_220 ;
F_6 ( V_2 , V_120 , V_5 ) ;
F_80 ( & V_2 -> V_114 ) ;
return V_222 ;
}
static int F_81 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
F_7 ( V_2 ) ;
else if ( F_16 ( V_2 ) )
F_18 ( V_2 ) ;
else
F_14 ( V_2 ) ;
return F_82 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_142 ;
V_142 = F_81 ( V_2 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_84 ( V_2 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_85 ( V_2 ) ;
if ( V_142 )
return V_142 ;
F_86 ( V_228 , & V_2 -> V_229 ) ;
F_86 ( V_230 , & V_2 -> V_229 ) ;
F_86 ( V_231 , & V_2 -> V_229 ) ;
if ( ! F_2 ( V_2 ) )
F_86 ( V_232 , & V_2 -> V_229 ) ;
F_86 ( V_233 , & V_2 -> V_229 ) ;
F_86 ( V_234 , & V_2 -> V_229 ) ;
F_86 ( V_235 , & V_2 -> V_229 ) ;
F_86 ( V_236 , & V_2 -> V_229 ) ;
if ( ! V_237 )
F_86 ( V_238 , & V_2 -> V_229 ) ;
F_86 ( V_239 , & V_2 -> V_229 ) ;
F_86 ( V_240 , & V_2 -> V_229 ) ;
V_2 -> V_241 = V_242 ;
return 0 ;
}
static int F_87 ( struct V_243 * V_244 )
{
return F_88 ( V_244 , & V_245 ) ;
}
static int F_89 ( struct V_246 * V_246 ,
const struct V_247 * V_248 )
{
return F_90 ( V_246 , & V_245 ) ;
}
static int T_7 F_91 ( void )
{
int V_249 = 0 ;
#if F_92 ( V_250 ) || F_92 ( V_251 )
V_249 = F_93 ( & V_252 ) ;
if ( V_249 )
return V_249 ;
#endif
#ifdef F_94
V_249 = F_95 ( & V_253 ) ;
if ( V_249 ) {
#if F_92 ( V_250 ) || F_92 ( V_251 )
F_96 ( & V_252 ) ;
#endif
return V_249 ;
}
#endif
return V_249 ;
}
static void T_8 F_97 ( void )
{
#ifdef F_94
F_98 ( & V_253 ) ;
#endif
#if F_92 ( V_250 ) || F_92 ( V_251 )
F_96 ( & V_252 ) ;
#endif
}
