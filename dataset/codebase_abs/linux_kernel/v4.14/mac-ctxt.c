static void F_1 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_9 ;
if ( V_4 == V_6 -> V_4 )
return;
switch ( V_6 -> V_4 -> type ) {
case V_10 :
if ( V_4 -> type != V_11 ||
V_6 -> V_12 != V_13 ||
! F_3 ( V_8 -> V_14 , V_6 -> V_15 ) )
break;
V_9 = F_4 ( V_6 -> V_4 -> V_16 . V_17 ,
V_4 -> V_16 . V_17 ) ;
if ( ! V_9 )
break;
if ( ( V_6 -> V_4 -> V_16 . V_17 -
V_4 -> V_16 . V_17 ) % V_9 == 0 ) {
V_6 -> V_12 = V_8 -> V_14 ;
return;
}
break;
case V_11 :
if ( ( V_4 -> type != V_11 &&
V_4 -> type != V_10 ) ||
V_6 -> V_12 != V_13 ||
! F_3 ( V_8 -> V_14 , V_6 -> V_15 ) )
break;
V_9 = F_4 ( V_6 -> V_4 -> V_16 . V_17 ,
V_4 -> V_16 . V_17 ) ;
if ( ! V_9 )
break;
if ( ( V_6 -> V_4 -> V_16 . V_17 -
V_4 -> V_16 . V_17 ) % V_9 == 0 ) {
V_6 -> V_12 = V_8 -> V_14 ;
return;
}
break;
default:
break;
}
F_5 ( V_8 -> V_14 , V_6 -> V_15 ) ;
if ( V_6 -> V_12 == V_8 -> V_14 )
V_6 -> V_12 = V_13 ;
}
T_3 F_6 ( struct V_3 * V_4 )
{
T_3 V_18 = 0 , V_19 ;
if ( V_4 -> type == V_20 )
return F_7 ( V_21 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
if ( V_4 -> V_23 [ V_19 ] != V_24 )
V_18 |= F_7 ( V_4 -> V_23 [ V_19 ] ) ;
}
if ( V_4 -> type == V_11 ||
V_4 -> type == V_25 )
V_18 |= F_7 ( V_4 -> V_26 ) ;
return V_18 ;
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_27 * V_6 = V_1 ;
if ( V_4 == V_6 -> V_28 )
return;
V_6 -> V_29 |= F_6 ( V_4 ) ;
}
unsigned long F_9 ( struct V_30 * V_31 ,
struct V_3 * V_28 )
{
struct V_27 V_6 = {
. V_28 = V_28 ,
. V_29 =
F_7 ( V_21 ) |
F_7 ( V_31 -> V_32 ) |
F_7 ( V_33 ) ,
} ;
F_10 ( & V_31 -> V_34 ) ;
F_11 (
V_31 -> V_35 , V_36 ,
F_8 , & V_6 ) ;
return V_6 . V_29 ;
}
static void F_12 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_37 = true ;
return;
}
F_5 ( V_8 -> V_38 , V_6 -> V_39 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
void F_13 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_31 = V_31 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_11 (
V_31 -> V_35 , V_36 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_14 ( V_6 . V_15 ,
V_13 ) ;
}
int F_15 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_31 = V_31 ,
. V_4 = V_4 ,
. V_39 = { ( 1 << V_40 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_37 = false ,
} ;
T_3 V_19 ;
int V_41 , V_42 , V_43 ;
unsigned long V_29 ;
F_10 ( & V_31 -> V_34 ) ;
switch ( V_4 -> type ) {
case V_25 :
break;
case V_10 :
if ( ! V_4 -> V_44 )
break;
default:
F_5 ( 0 , V_6 . V_39 ) ;
}
F_11 (
V_31 -> V_35 , V_36 ,
F_12 , & V_6 ) ;
V_29 = F_9 ( V_31 , V_4 ) ;
if ( V_6 . V_37 )
return 0 ;
if ( F_16 ( F_3 ( V_45 , & V_31 -> V_46 ) ) )
return - V_47 ;
V_8 -> V_38 = F_14 ( V_6 . V_39 ,
V_40 ) ;
if ( V_8 -> V_38 == V_40 ) {
F_17 ( V_31 , L_1 ) ;
V_41 = - V_48 ;
goto V_49;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_14 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_17 ( V_31 , L_2 ) ;
V_41 = - V_48 ;
goto V_49;
}
V_8 -> V_50 = 0 ;
F_18 ( & V_8 -> V_51 . V_52 ) ;
V_8 -> V_51 . V_38 = V_53 ;
if ( V_4 -> type == V_20 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_4 -> V_23 [ V_19 ] = V_24 ;
return 0 ;
}
V_43 = V_54 ;
F_19 ( V_54 >
V_55 *
sizeof( V_31 -> V_56 [ 0 ] ) ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
T_1 V_57 = F_20 ( & V_29 , V_43 ) ;
if ( V_57 >= V_43 ) {
F_17 ( V_31 , L_3 ) ;
V_41 = - V_48 ;
goto V_49;
}
F_21 ( V_57 , & V_29 ) ;
V_4 -> V_23 [ V_19 ] = V_57 ;
}
if ( V_4 -> type == V_11 ) {
V_8 -> V_26 = V_33 ;
V_4 -> V_26 = V_33 ;
} else {
V_4 -> V_26 = V_24 ;
}
V_8 -> V_58 . V_59 = V_60 ;
V_8 -> V_61 . V_59 = V_60 ;
V_8 -> V_62 = V_60 ;
for ( V_42 = 0 ; V_42 < V_63 ; V_42 ++ )
V_8 -> V_64 [ V_42 ] = V_65 ;
return 0 ;
V_49:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_24 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_26 = V_24 ;
return V_41 ;
}
static void F_22 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
enum V_66 V_67 ,
T_1 * V_68 , T_1 * V_69 )
{
struct V_70 * V_71 ;
unsigned long V_72 = V_4 -> V_16 . V_73 ;
int V_74 = 100 ;
int V_75 = 100 ;
T_1 V_76 = 0 ;
T_1 V_77 = 0 ;
int V_42 ;
V_71 = V_31 -> V_35 -> V_78 -> V_79 [ V_67 ] ;
F_23 (i, &basic, BITS_PER_LONG) {
int V_35 = V_71 -> V_80 [ V_42 ] . V_81 ;
if ( V_35 >= V_82 ) {
V_77 |= F_7 ( V_35 - V_82 ) ;
if ( V_74 > V_35 )
V_74 = V_35 ;
} else {
F_19 ( V_83 != 0 ) ;
V_76 |= F_7 ( V_35 ) ;
if ( V_75 > V_35 )
V_75 = V_35 ;
}
}
if ( V_84 < V_74 )
V_77 |= F_24 ( 24 ) >> V_82 ;
if ( V_85 < V_74 )
V_77 |= F_24 ( 12 ) >> V_82 ;
V_77 |= F_24 ( 6 ) >> V_82 ;
if ( V_86 < V_75 )
V_76 |= F_24 ( 11 ) >> V_83 ;
if ( V_87 < V_75 )
V_76 |= F_24 ( 5 ) >> V_83 ;
if ( V_88 < V_75 )
V_76 |= F_24 ( 2 ) >> V_83 ;
V_76 |= F_24 ( 1 ) >> V_83 ;
* V_68 = V_76 ;
* V_69 = V_77 ;
}
static void F_25 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_89 * V_90 )
{
T_1 V_91 = V_4 -> V_16 . V_92 &
V_93 ;
T_3 V_94 = V_95 | V_96 ;
F_26 ( V_31 , L_4 , V_91 ) ;
switch ( V_91 ) {
case V_97 :
break;
case V_98 :
case V_99 :
V_90 -> V_100 |= F_27 ( V_94 ) ;
break;
case V_101 :
if ( V_4 -> V_16 . V_102 . V_103 > V_104 )
V_90 -> V_100 |= F_27 ( V_94 ) ;
break;
default:
F_17 ( V_31 , L_5 ,
V_91 ) ;
break;
}
}
static void F_28 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_89 * V_90 ,
const T_1 * V_105 ,
T_3 V_106 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_107 * V_108 ;
bool V_109 = ! ! ( V_4 -> V_16 . V_92 &
V_93 ) ;
T_1 V_110 , V_111 ;
const T_1 * V_112 = V_105 ? : V_4 -> V_16 . V_112 ;
int V_42 ;
V_90 -> V_113 = F_27 ( F_29 ( V_8 -> V_38 ,
V_8 -> V_50 ) ) ;
V_90 -> V_106 = F_27 ( V_106 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_44 )
V_90 -> V_114 = F_27 ( V_115 ) ;
else
V_90 -> V_114 = F_27 ( V_116 ) ;
break;
case V_11 :
V_90 -> V_114 = F_27 ( V_117 ) ;
break;
case V_118 :
V_90 -> V_114 = F_27 ( V_119 ) ;
break;
case V_20 :
V_90 -> V_114 = F_27 ( V_120 ) ;
break;
case V_25 :
V_90 -> V_114 = F_27 ( V_121 ) ;
break;
default:
F_16 ( 1 ) ;
}
V_90 -> V_14 = F_27 ( V_8 -> V_14 ) ;
memcpy ( V_90 -> V_122 , V_4 -> V_123 , V_124 ) ;
if ( V_112 )
memcpy ( V_90 -> V_125 , V_112 , V_124 ) ;
else
F_30 ( V_90 -> V_125 ) ;
F_31 () ;
V_108 = F_32 ( V_4 -> V_126 ) ;
F_22 ( V_31 , V_4 , V_108 ? V_108 -> V_127 . V_128 -> V_67
: V_129 ,
& V_110 , & V_111 ) ;
F_33 () ;
V_90 -> V_68 = F_27 ( ( T_3 ) V_110 ) ;
V_90 -> V_69 = F_27 ( ( T_3 ) V_111 ) ;
V_90 -> V_130 =
F_27 ( V_4 -> V_16 . V_131 ?
V_132 : 0 ) ;
V_90 -> V_133 =
F_27 ( V_4 -> V_16 . V_134 ?
V_135 : 0 ) ;
V_90 -> V_136 = F_27 ( V_137 ) ;
for ( V_42 = 0 ; V_42 < V_22 ; V_42 ++ ) {
T_1 V_138 = F_34 ( V_31 , V_42 ) ;
V_90 -> V_19 [ V_138 ] . V_139 =
F_35 ( V_8 -> V_140 [ V_42 ] . V_139 ) ;
V_90 -> V_19 [ V_138 ] . V_141 =
F_35 ( V_8 -> V_140 [ V_42 ] . V_141 ) ;
V_90 -> V_19 [ V_138 ] . V_142 =
F_35 ( V_8 -> V_140 [ V_42 ] . V_143 * 32 ) ;
V_90 -> V_19 [ V_138 ] . V_144 = V_8 -> V_140 [ V_42 ] . V_145 ;
V_90 -> V_19 [ V_138 ] . V_146 = F_7 ( V_138 ) ;
}
if ( V_4 -> V_16 . V_147 )
V_90 -> V_148 |= F_27 ( V_149 ) ;
if ( V_4 -> V_16 . V_150 )
V_90 -> V_100 |= F_27 ( V_151 ) ;
F_26 ( V_31 , L_6 ,
V_4 -> V_16 . V_150 ,
V_4 -> V_16 . V_92 ) ;
if ( V_4 -> V_16 . V_102 . V_103 != V_152 )
V_90 -> V_148 |= F_27 ( V_153 ) ;
if ( V_109 )
F_25 ( V_31 , V_4 , V_90 ) ;
}
static int F_36 ( struct V_30 * V_31 ,
struct V_89 * V_90 )
{
int V_41 = F_37 ( V_31 , V_154 , 0 ,
sizeof( * V_90 ) , V_90 ) ;
if ( V_41 )
F_17 ( V_31 , L_7 ,
F_38 ( V_90 -> V_106 ) , V_41 ) ;
return V_41 ;
}
static int F_39 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_3 V_106 , bool V_155 ,
const T_1 * V_105 )
{
struct V_89 V_90 = {} ;
struct V_156 * V_157 ;
F_40 ( V_4 -> type != V_10 ) ;
F_28 ( V_31 , V_4 , & V_90 , V_105 , V_106 ) ;
if ( V_4 -> V_44 ) {
struct V_158 * V_159 =
& V_4 -> V_16 . V_160 ;
V_90 . V_161 . V_162 = F_27 ( V_159 -> V_163 &
V_164 ) ;
V_157 = & V_90 . V_161 . V_165 ;
} else {
V_157 = & V_90 . V_165 ;
}
if ( V_4 -> V_16 . V_166 && V_4 -> V_16 . V_167 &&
! V_155 ) {
T_3 V_168 ;
V_168 = V_4 -> V_16 . V_169 *
V_4 -> V_16 . V_17 ;
V_168 *= 1024 ;
V_157 -> V_170 =
F_41 ( V_4 -> V_16 . V_171 + V_168 ) ;
V_157 -> V_172 =
F_27 ( V_4 -> V_16 . V_173 + V_168 ) ;
V_157 -> V_174 =
F_27 ( V_4 -> V_16 . V_173 ) ;
F_42 ( V_31 , L_8 ,
F_43 ( V_157 -> V_170 ) ,
F_38 ( V_157 -> V_172 ) ,
V_168 ) ;
V_157 -> V_175 = F_27 ( 1 ) ;
} else {
V_157 -> V_175 = F_27 ( 0 ) ;
V_90 . V_136 |= F_27 ( V_176 ) ;
}
V_157 -> V_177 = F_27 ( V_4 -> V_16 . V_17 ) ;
V_157 -> V_178 =
F_27 ( F_44 ( V_4 -> V_16 . V_17 ) ) ;
V_157 -> V_179 = F_27 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_167 ) ;
V_157 -> V_180 =
F_27 ( F_44 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_167 ) ) ;
V_157 -> V_181 = F_27 ( V_31 -> V_35 -> V_182 . V_181 ) ;
V_157 -> V_183 = F_27 ( V_4 -> V_16 . V_184 ) ;
if ( V_4 -> V_185 && V_4 -> V_16 . V_166 && V_4 -> V_44 )
V_90 . V_136 |= F_27 ( V_186 ) ;
return F_36 ( V_31 , & V_90 ) ;
}
static int F_45 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_3 V_106 )
{
struct V_89 V_90 = {} ;
T_3 V_187 = 0 ;
int V_41 ;
F_40 ( V_4 -> type != V_118 ) ;
F_28 ( V_31 , V_4 , & V_90 , NULL , V_106 ) ;
V_90 . V_136 = F_27 ( V_188 |
V_189 |
V_176 |
V_186 |
V_190 ) ;
F_46 ( V_31 -> V_35 , V_191 ) ;
V_41 = F_47 ( V_31 , & V_31 -> V_192 , V_187 ,
V_4 -> type , V_193 ) ;
if ( V_41 )
return V_41 ;
return F_36 ( V_31 , & V_90 ) ;
}
static int F_48 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_3 V_106 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_89 V_90 = {} ;
F_40 ( V_4 -> type != V_25 ) ;
F_28 ( V_31 , V_4 , & V_90 , NULL , V_106 ) ;
V_90 . V_136 = F_27 ( V_176 |
V_186 ) ;
V_90 . V_194 . V_177 = F_27 ( V_4 -> V_16 . V_17 ) ;
V_90 . V_194 . V_178 =
F_27 ( F_44 ( V_4 -> V_16 . V_17 ) ) ;
V_90 . V_194 . V_195 = F_27 ( V_8 -> V_38 ) ;
return F_36 ( V_31 , & V_90 ) ;
}
static void F_49 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_196 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_44 &&
V_8 -> V_197 )
V_6 -> V_198 = true ;
}
static int F_50 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_3 V_106 )
{
struct V_89 V_90 = {} ;
struct V_196 V_6 = {} ;
F_40 ( V_4 -> type != V_20 ) ;
F_28 ( V_31 , V_4 , & V_90 , NULL , V_106 ) ;
V_90 . V_100 |= F_27 ( V_151 ) ;
V_90 . V_136 = F_27 ( V_186 ) ;
F_11 (
V_31 -> V_35 , V_36 ,
F_49 , & V_6 ) ;
V_90 . V_199 . V_200 = F_27 ( V_6 . V_198 ? 1 : 0 ) ;
return F_36 ( V_31 , & V_90 ) ;
}
static void F_51 ( struct V_30 * V_31 ,
T_4 * V_201 , T_4 * V_202 ,
T_1 * V_203 , T_3 V_204 )
{
T_3 V_205 ;
struct V_206 * V_207 = (struct V_206 * ) V_203 ;
V_205 = V_207 -> V_208 . V_203 . V_209 - V_203 ;
while ( ( V_205 < ( V_204 - 2 ) ) &&
( V_203 [ V_205 ] != V_210 ) )
V_205 += V_203 [ V_205 + 1 ] + 2 ;
if ( ( V_205 < ( V_204 - 1 ) ) && ( V_203 [ V_205 ] == V_210 ) ) {
* V_201 = F_27 ( V_205 ) ;
* V_202 = F_27 ( ( T_3 ) V_203 [ V_205 + 1 ] ) ;
} else {
F_52 ( V_31 , L_9 ) ;
}
}
static T_3 F_53 ( T_1 * V_203 , T_1 V_211 , T_3 V_204 )
{
struct V_206 * V_207 = ( void * ) V_203 ;
const T_1 * V_212 ;
if ( F_16 ( V_204 <= ( V_207 -> V_208 . V_203 . V_209 - V_203 ) ) )
return 0 ;
V_204 -= V_207 -> V_208 . V_203 . V_209 - V_203 ;
V_212 = F_54 ( V_211 , V_207 -> V_208 . V_203 . V_209 , V_204 ) ;
if ( ! V_212 )
return 0 ;
return V_212 - V_203 ;
}
static T_1 F_55 ( struct V_213 * V_214 ,
struct V_3 * V_4 )
{
T_1 V_215 ;
if ( V_214 -> V_67 == V_216 || V_4 -> V_44 )
V_215 = V_82 ;
else
V_215 = V_83 ;
return V_215 ;
}
static void F_56 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_217 * V_203 ,
struct V_218 * V_219 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_213 * V_214 ;
T_1 V_215 ;
T_3 V_220 ;
V_214 = F_57 ( V_203 ) ;
V_219 -> V_221 = F_35 ( ( T_2 ) V_203 -> V_221 ) ;
V_219 -> V_59 = V_8 -> V_58 . V_59 ;
V_219 -> V_222 = F_27 ( V_223 ) ;
V_220 = V_224 | V_225 ;
V_220 |=
F_58 ( V_31 , ( void * ) V_203 -> V_6 , V_214 , 0 ) <<
V_226 ;
V_219 -> V_220 = F_27 ( V_220 ) ;
if ( ! F_59 ( & V_31 -> V_227 -> V_228 ,
V_229 ) ) {
V_31 -> V_230 =
F_60 ( V_31 , F_61 ( V_31 ) ,
V_31 -> V_230 ) ;
}
V_219 -> V_231 =
F_27 ( F_7 ( V_31 -> V_230 ) <<
V_232 ) ;
V_215 = F_55 ( V_214 , V_4 ) ;
V_219 -> V_231 |= F_27 ( F_62 ( V_215 ) ) ;
if ( V_215 == V_83 )
V_219 -> V_231 |= F_27 ( V_233 ) ;
}
static int F_63 ( struct V_30 * V_31 ,
struct V_217 * V_203 ,
void * V_6 , int V_221 )
{
struct V_234 V_90 = {
. V_38 = V_235 ,
. V_236 = V_237 ,
} ;
V_90 . V_221 [ 0 ] = V_221 ;
V_90 . V_6 [ 0 ] = V_6 ;
V_90 . V_238 [ 0 ] = 0 ;
V_90 . V_221 [ 1 ] = V_203 -> V_221 ;
V_90 . V_6 [ 1 ] = V_203 -> V_6 ;
V_90 . V_238 [ 1 ] = V_239 ;
return F_64 ( V_31 , & V_90 ) ;
}
static int F_65 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_217 * V_203 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_240 V_241 = {} ;
F_56 ( V_31 , V_4 , V_203 , & V_241 . V_219 ) ;
V_241 . V_242 = F_27 ( ( T_3 ) V_8 -> V_38 ) ;
if ( V_4 -> type == V_11 )
F_51 ( V_31 , & V_241 . V_205 ,
& V_241 . V_202 ,
V_203 -> V_6 , V_203 -> V_221 ) ;
return F_63 ( V_31 , V_203 , & V_241 ,
sizeof( V_241 ) ) ;
}
static int F_66 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_217 * V_203 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_243 V_241 = {} ;
F_56 ( V_31 , V_4 , V_203 , & V_241 . V_219 ) ;
V_241 . V_242 = F_27 ( ( T_3 ) V_8 -> V_38 ) ;
if ( V_4 -> type == V_11 )
F_51 ( V_31 , & V_241 . V_205 ,
& V_241 . V_202 ,
V_203 -> V_6 , V_203 -> V_221 ) ;
V_241 . V_244 =
F_27 ( F_53 ( V_203 -> V_6 ,
V_245 ,
V_203 -> V_221 ) ) ;
V_241 . V_246 =
F_27 ( F_53 ( V_203 -> V_6 ,
V_247 ,
V_203 -> V_221 ) ) ;
return F_63 ( V_31 , V_203 , & V_241 ,
sizeof( V_241 ) ) ;
}
static int F_67 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_217 * V_203 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_213 * V_214 = F_57 ( V_203 ) ;
struct V_248 V_241 = {} ;
T_1 V_215 = F_55 ( V_214 , V_4 ) ;
T_2 V_236 ;
V_236 = F_62 ( V_215 ) ;
if ( V_215 == V_83 )
V_236 |= V_249 ;
V_241 . V_236 = F_35 ( V_236 ) ;
V_241 . V_250 = F_35 ( ( T_2 ) V_203 -> V_221 ) ;
V_241 . V_242 = F_27 ( ( T_3 ) V_8 -> V_38 ) ;
if ( V_4 -> type == V_11 )
F_51 ( V_31 , & V_241 . V_205 ,
& V_241 . V_202 ,
V_203 -> V_6 , V_203 -> V_221 ) ;
V_241 . V_244 =
F_27 ( F_53 ( V_203 -> V_6 ,
V_245 ,
V_203 -> V_221 ) ) ;
V_241 . V_246 =
F_27 ( F_53 ( V_203 -> V_6 ,
V_247 ,
V_203 -> V_221 ) ) ;
return F_63 ( V_31 , V_203 , & V_241 ,
sizeof( V_241 ) ) ;
}
static int F_68 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_217 * V_203 )
{
if ( F_40 ( ! V_203 ) )
return - V_251 ;
if ( ! F_59 ( & V_31 -> V_227 -> V_228 ,
V_252 ) )
return F_65 ( V_31 , V_4 , V_203 ) ;
if ( F_69 ( & V_31 -> V_227 -> V_228 ,
V_253 ) )
return F_67 ( V_31 , V_4 , V_203 ) ;
return F_66 ( V_31 , V_4 , V_203 ) ;
}
int F_70 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
struct V_217 * V_203 ;
int V_41 ;
F_40 ( V_4 -> type != V_11 &&
V_4 -> type != V_25 ) ;
V_203 = F_71 ( V_31 -> V_35 , V_4 , NULL ) ;
if ( ! V_203 )
return - V_254 ;
V_41 = F_68 ( V_31 , V_4 , V_203 ) ;
F_72 ( V_203 ) ;
return V_41 ;
}
static void F_73 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_255 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_166 )
return;
if ( V_4 -> V_44 && V_6 -> V_256 )
return;
V_6 -> V_256 = V_4 -> V_16 . V_173 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_74 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_89 * V_90 ,
struct V_257 * V_258 ,
bool V_259 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_255 V_6 = {
. V_31 = V_31 ,
. V_4 = V_4 ,
. V_256 = 0
} ;
V_90 -> V_19 [ V_260 ] . V_146 |= F_7 ( V_261 ) ;
V_90 -> V_136 |= F_27 ( V_186 ) ;
if ( V_8 -> V_262 || ! V_31 -> V_263 ) {
V_90 -> V_136 |= F_27 ( V_176 ) ;
F_75 ( V_31 , L_10 ) ;
} else {
F_75 ( V_31 , L_11 ) ;
}
V_258 -> V_177 = F_27 ( V_4 -> V_16 . V_17 ) ;
V_258 -> V_178 =
F_27 ( F_44 ( V_4 -> V_16 . V_17 ) ) ;
V_258 -> V_179 = F_27 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_167 ) ;
V_258 -> V_180 =
F_27 ( F_44 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_167 ) ) ;
if ( ! F_69 ( & V_31 -> V_227 -> V_228 ,
V_264 ) )
V_258 -> V_265 = F_27 ( V_4 -> V_26 ) ;
if ( V_259 ) {
F_11 (
V_31 -> V_35 , V_36 ,
F_73 , & V_6 ) ;
if ( V_6 . V_256 ) {
T_3 rand = ( F_76 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_266 = V_6 . V_256 +
F_77 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_266 =
F_78 ( V_31 -> V_267 ,
V_268 ) ;
}
}
V_258 -> V_269 = F_27 ( V_8 -> V_266 ) ;
V_258 -> V_270 = 0 ;
V_258 -> V_195 = F_27 ( V_8 -> V_38 ) ;
}
static int F_79 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_3 V_106 )
{
struct V_89 V_90 = {} ;
F_40 ( V_4 -> type != V_11 || V_4 -> V_44 ) ;
F_28 ( V_31 , V_4 , & V_90 , NULL , V_106 ) ;
F_74 ( V_31 , V_4 , & V_90 , & V_90 . V_271 ,
V_106 == V_272 ) ;
return F_36 ( V_31 , & V_90 ) ;
}
static int F_80 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
T_3 V_106 )
{
struct V_89 V_90 = {} ;
struct V_158 * V_159 = & V_4 -> V_16 . V_160 ;
F_40 ( V_4 -> type != V_11 || ! V_4 -> V_44 ) ;
F_28 ( V_31 , V_4 , & V_90 , NULL , V_106 ) ;
F_74 ( V_31 , V_4 , & V_90 , & V_90 . V_273 . V_271 ,
V_106 == V_272 ) ;
V_90 . V_273 . V_162 = F_27 ( V_159 -> V_163 &
V_164 ) ;
V_90 . V_273 . V_274 =
F_27 ( ! ! ( V_159 -> V_163 &
V_275 ) ) ;
return F_36 ( V_31 , & V_90 ) ;
}
static int F_81 ( struct V_30 * V_31 , struct V_3 * V_4 ,
T_3 V_106 , bool V_155 ,
const T_1 * V_105 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_39 ( V_31 , V_4 , V_106 ,
V_155 ,
V_105 ) ;
break;
case V_11 :
if ( ! V_4 -> V_44 )
return F_79 ( V_31 , V_4 , V_106 ) ;
else
return F_80 ( V_31 , V_4 , V_106 ) ;
break;
case V_118 :
return F_45 ( V_31 , V_4 , V_106 ) ;
case V_20 :
return F_50 ( V_31 , V_4 , V_106 ) ;
case V_25 :
return F_48 ( V_31 , V_4 , V_106 ) ;
default:
break;
}
return - V_276 ;
}
int F_82 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_41 ;
if ( F_83 ( V_8 -> V_277 , L_12 ,
V_4 -> V_123 , F_84 ( V_4 ) ) )
return - V_48 ;
V_41 = F_81 ( V_31 , V_4 , V_272 ,
true , NULL ) ;
if ( V_41 )
return V_41 ;
F_85 ( V_31 , V_4 ) ;
V_8 -> V_277 = true ;
return 0 ;
}
int F_86 ( struct V_30 * V_31 , struct V_3 * V_4 ,
bool V_155 , const T_1 * V_105 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_83 ( ! V_8 -> V_277 , L_13 ,
V_4 -> V_123 , F_84 ( V_4 ) ) )
return - V_48 ;
return F_81 ( V_31 , V_4 , V_278 ,
V_155 , V_105 ) ;
}
int F_87 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_89 V_90 ;
int V_41 ;
if ( F_83 ( ! V_8 -> V_277 , L_14 ,
V_4 -> V_123 , F_84 ( V_4 ) ) )
return - V_48 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_113 = F_27 ( F_29 ( V_8 -> V_38 ,
V_8 -> V_50 ) ) ;
V_90 . V_106 = F_27 ( V_279 ) ;
V_41 = F_37 ( V_31 , V_154 , 0 ,
sizeof( V_90 ) , & V_90 ) ;
if ( V_41 ) {
F_17 ( V_31 , L_15 , V_41 ) ;
return V_41 ;
}
V_8 -> V_277 = false ;
if ( V_4 -> type == V_118 ) {
F_5 ( V_280 , V_31 -> V_35 -> V_236 ) ;
F_88 ( V_31 ) ;
}
return 0 ;
}
static void F_89 ( struct V_30 * V_31 ,
struct V_3 * V_281 , T_3 V_282 ,
bool V_283 )
{
struct V_7 * V_8 =
F_2 ( V_281 ) ;
if ( ! V_283 && ! V_8 -> V_284 )
return;
V_8 -> V_284 = true ;
if ( ! F_90 ( V_281 ) ) {
int V_285 = F_91 ( V_281 ) ;
F_70 ( V_31 , V_281 ) ;
if ( V_281 -> V_44 &&
! F_92 ( & V_8 -> V_51 ) && V_282 &&
V_283 ) {
T_3 V_286 = ( V_285 + 1 ) *
V_281 -> V_16 . V_17 -
V_287 ;
T_3 V_288 = V_282 + V_286 * 1024 ;
F_93 ( V_31 , V_281 ,
V_287 -
V_289 ,
V_288 ) ;
}
} else if ( ! F_92 ( & V_8 -> V_51 ) ) {
F_94 ( V_281 ) ;
F_95 ( V_31 -> V_281 , NULL ) ;
}
}
void F_96 ( struct V_30 * V_31 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_97 ( V_291 ) ;
struct V_294 * V_203 = ( void * ) V_293 -> V_6 ;
struct V_295 * V_296 ;
struct V_3 * V_281 ;
struct V_3 * V_297 ;
struct V_298 * V_299 ;
T_2 V_46 ;
F_10 ( & V_31 -> V_34 ) ;
V_296 = & V_203 -> V_296 ;
V_31 -> V_300 = F_38 ( V_203 -> V_282 ) ;
V_31 -> V_301 = V_203 -> V_302 != 0 ;
V_299 = F_98 ( V_31 , V_296 ) ;
V_46 = F_99 ( V_299 -> V_46 ) & V_303 ;
F_100 ( V_31 ,
L_16 ,
V_46 , V_296 -> V_304 ,
F_43 ( V_203 -> V_305 ) ,
V_31 -> V_300 ,
F_38 ( V_296 -> V_306 ) ) ;
V_281 = F_101 ( V_31 -> V_281 ,
F_102 ( & V_31 -> V_34 ) ) ;
if ( F_103 ( V_281 && V_281 -> V_307 ) )
F_89 ( V_31 , V_281 , V_31 -> V_300 ,
( V_46 == V_308 ) ) ;
V_297 = F_101 ( V_31 -> V_309 ,
F_102 ( & V_31 -> V_34 ) ) ;
if ( F_103 ( V_297 ) ) {
struct V_7 * V_8 =
F_2 ( V_297 ) ;
if ( ! V_31 -> V_310 )
V_31 -> V_310 =
V_311 ;
else
V_31 -> V_310 -- ;
if ( V_31 -> V_310 == 0 ) {
F_104 ( V_31 , V_8 , false ) ;
F_95 ( V_31 -> V_309 , NULL ) ;
}
}
}
static void F_105 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_312 * V_313 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_30 * V_31 = V_8 -> V_31 ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
T_3 V_318 , V_319 ;
T_3 V_320 , V_321 ;
if ( V_8 -> V_38 != ( T_2 ) F_38 ( V_313 -> V_322 ) )
return;
V_320 = F_38 ( V_313 -> V_323 ) ;
V_321 =
F_38 ( V_313 -> V_324 ) ;
if ( F_38 ( V_313 -> V_324 ) >
V_325 )
F_106 ( V_4 ) ;
if ( ! F_107 ( V_31 -> V_227 ,
V_326 ) )
return;
V_317 = F_108 ( V_31 -> V_227 ,
V_326 ) ;
V_315 = ( void * ) V_317 -> V_6 ;
V_318 = F_38 ( V_315 -> V_327 ) ;
V_319 =
F_38 ( V_315 -> V_328 ) ;
if ( ! F_109 ( & V_31 -> V_329 ,
F_110 ( V_4 ) ,
V_317 ) )
return;
if ( V_321 >= V_319 ||
V_320 >= V_318 )
F_111 ( & V_31 -> V_329 , V_317 , NULL ) ;
}
void F_112 ( struct V_30 * V_31 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_97 ( V_291 ) ;
struct V_312 * V_330 = ( void * ) V_293 -> V_6 ;
F_42 ( V_31 ,
L_17 ,
F_38 ( V_330 -> V_322 ) ,
F_38 ( V_330 -> V_323 ) ,
F_38 ( V_330 -> V_324 ) ,
F_38 ( V_330 -> V_331 ) ,
F_38 ( V_330 -> V_332 ) ) ;
F_11 ( V_31 -> V_35 ,
V_333 ,
F_105 ,
V_330 ) ;
}
void F_113 ( struct V_30 * V_31 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_97 ( V_291 ) ;
struct V_334 * V_335 = ( void * ) V_293 -> V_6 ;
struct V_336 V_337 ;
struct V_217 * V_338 ;
T_3 V_339 = F_38 ( V_335 -> V_340 ) ;
if ( V_339 == 0 )
return;
V_338 = F_114 ( V_339 , V_341 ) ;
if ( ! V_338 ) {
F_17 ( V_31 , L_18 ) ;
return;
}
memset ( & V_337 , 0 , sizeof( V_337 ) ) ;
V_337 . V_342 = F_43 ( V_335 -> V_305 ) ;
V_337 . V_343 |= V_344 ;
V_337 . V_345 = F_38 ( V_335 -> V_346 ) ;
V_337 . V_67 =
( V_335 -> V_67 & F_35 ( V_347 ) ) ?
V_129 : V_216 ;
V_337 . V_348 =
F_115 ( F_99 ( V_335 -> V_349 ) ,
V_337 . V_67 ) ;
F_116 ( V_338 , V_335 -> V_6 , V_339 ) ;
memcpy ( F_117 ( V_338 ) , & V_337 , sizeof( V_337 ) ) ;
F_118 ( V_31 -> V_35 , NULL , V_338 , NULL ) ;
}
void F_119 ( struct V_30 * V_31 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 = F_97 ( V_291 ) ;
struct V_350 * V_351 = ( void * ) V_293 -> V_6 ;
struct V_3 * V_281 ;
struct V_7 * V_8 ;
int V_221 = F_120 ( V_293 ) ;
T_3 V_352 ;
if ( F_16 ( V_221 < sizeof( * V_351 ) ) )
return;
F_31 () ;
V_281 = F_32 ( V_31 -> V_281 ) ;
if ( F_40 ( ! V_281 || ! V_281 -> V_307 ) )
goto V_353;
V_352 = F_38 ( V_351 -> V_113 ) ;
V_8 = F_2 ( V_281 ) ;
if ( F_121 ( F_29 ( V_8 -> V_38 , V_8 -> V_50 ) != V_352 ,
L_19 ,
F_29 ( V_8 -> V_38 , V_8 -> V_50 ) , V_352 ) )
goto V_353;
F_42 ( V_31 , L_20 ) ;
F_122 ( & V_31 -> V_354 ,
F_123 ( V_311 *
V_281 -> V_16 . V_17 ) ) ;
F_94 ( V_281 ) ;
F_33 () ;
F_95 ( V_31 -> V_281 , NULL ) ;
return;
V_353:
F_33 () ;
}
