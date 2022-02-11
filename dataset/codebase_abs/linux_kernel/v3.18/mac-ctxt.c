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
T_3 F_6 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
T_3 V_20 = 0 , V_21 ;
if ( V_4 -> type == V_22 )
return F_7 ( V_23 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
V_20 |= F_7 ( V_4 -> V_25 [ V_21 ] ) ;
if ( V_4 -> type == V_11 )
V_20 |= F_7 ( V_4 -> V_26 ) ;
return V_20 ;
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_27 = true ;
return;
}
V_6 -> V_28 |= F_6 ( V_6 -> V_19 , V_4 ) ;
F_5 ( V_8 -> V_29 , V_6 -> V_30 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
void F_9 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_19 = V_19 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_10 (
V_19 -> V_31 , V_32 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_11 ( V_6 . V_15 ,
V_13 ) ;
}
static int F_12 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_19 = V_19 ,
. V_4 = V_4 ,
. V_30 = { ( 1 << V_33 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_28 =
F_7 ( V_23 ) |
F_7 ( V_19 -> V_34 ) |
F_7 ( V_35 ) ,
. V_27 = false ,
} ;
T_3 V_21 ;
int V_36 , V_37 ;
unsigned long V_28 ;
switch ( V_4 -> type ) {
case V_38 :
break;
case V_10 :
if ( ! V_4 -> V_39 )
break;
default:
F_5 ( 0 , V_6 . V_30 ) ;
}
F_10 (
V_19 -> V_31 , V_32 ,
F_8 , & V_6 ) ;
if ( V_6 . V_27 )
return 0 ;
if ( F_13 ( F_3 ( V_40 , & V_19 -> V_41 ) ) )
return - V_42 ;
V_8 -> V_29 = F_11 ( V_6 . V_30 ,
V_33 ) ;
if ( V_8 -> V_29 == V_33 ) {
F_14 ( V_19 , L_1 ) ;
V_36 = - V_43 ;
goto V_44;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_11 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_14 ( V_19 , L_2 ) ;
V_36 = - V_43 ;
goto V_44;
}
V_8 -> V_45 = 0 ;
F_15 ( & V_8 -> V_46 . V_47 ) ;
V_8 -> V_46 . V_29 = V_48 ;
if ( V_4 -> type == V_22 ) {
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
V_4 -> V_25 [ V_21 ] = V_49 ;
return 0 ;
}
V_28 = V_6 . V_28 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
T_1 V_50 = F_16 ( & V_28 ,
V_19 -> V_51 ) ;
if ( V_50 >= V_19 -> V_51 ) {
F_14 ( V_19 , L_3 ) ;
V_36 = - V_43 ;
goto V_44;
}
F_17 ( V_50 , & V_28 ) ;
V_4 -> V_25 [ V_21 ] = V_50 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_50 = F_16 ( & V_28 ,
V_19 -> V_51 ) ;
if ( V_50 >= V_19 -> V_51 ) {
F_14 ( V_19 , L_4 ) ;
V_36 = - V_43 ;
goto V_44;
}
V_4 -> V_26 = V_50 ;
} else {
V_4 -> V_26 = V_49 ;
}
V_8 -> V_52 . V_53 = V_54 ;
V_8 -> V_55 = V_54 ;
for ( V_37 = 0 ; V_37 < V_56 ; V_37 ++ )
V_8 -> V_57 [ V_37 ] = V_58 ;
return 0 ;
V_44:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_25 , V_49 , sizeof( V_4 -> V_25 ) ) ;
V_4 -> V_26 = V_49 ;
return V_36 ;
}
int F_18 ( struct V_18 * V_19 , struct V_3 * V_4 )
{
T_3 V_21 ;
int V_36 ;
F_19 ( & V_19 -> V_59 ) ;
V_36 = F_12 ( V_19 , V_4 ) ;
if ( V_36 )
return V_36 ;
switch ( V_4 -> type ) {
case V_22 :
F_20 ( V_19 , V_23 ,
V_60 ) ;
break;
case V_11 :
F_20 ( V_19 , V_4 -> V_26 ,
V_61 ) ;
default:
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
F_20 ( V_19 , V_4 -> V_25 [ V_21 ] ,
V_62 [ V_21 ] ) ;
break;
}
return 0 ;
}
void F_21 ( struct V_18 * V_19 , struct V_3 * V_4 )
{
int V_21 ;
F_19 ( & V_19 -> V_59 ) ;
switch ( V_4 -> type ) {
case V_22 :
F_22 ( V_19 , V_23 ) ;
break;
case V_11 :
F_22 ( V_19 , V_4 -> V_26 ) ;
default:
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
F_22 ( V_19 , V_4 -> V_25 [ V_21 ] ) ;
}
}
static void F_23 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_63 V_64 ,
T_1 * V_65 , T_1 * V_66 )
{
struct V_67 * V_68 ;
unsigned long V_69 = V_4 -> V_16 . V_70 ;
int V_71 = 100 ;
int V_72 = 100 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
int V_37 ;
V_68 = V_19 -> V_31 -> V_75 -> V_76 [ V_64 ] ;
F_24 (i, &basic, BITS_PER_LONG) {
int V_31 = V_68 -> V_77 [ V_37 ] . V_78 ;
if ( V_31 >= V_79 ) {
V_74 |= F_7 ( V_31 - V_79 ) ;
if ( V_71 > V_31 )
V_71 = V_31 ;
} else {
F_25 ( V_80 != 0 ) ;
V_73 |= F_7 ( V_31 ) ;
if ( V_72 > V_31 )
V_72 = V_31 ;
}
}
if ( V_81 < V_71 )
V_74 |= F_26 ( 24 ) >> V_79 ;
if ( V_82 < V_71 )
V_74 |= F_26 ( 12 ) >> V_79 ;
V_74 |= F_26 ( 6 ) >> V_79 ;
if ( V_83 < V_72 )
V_73 |= F_26 ( 11 ) >> V_80 ;
if ( V_84 < V_72 )
V_73 |= F_26 ( 5 ) >> V_80 ;
if ( V_85 < V_72 )
V_73 |= F_26 ( 2 ) >> V_80 ;
V_73 |= F_26 ( 1 ) >> V_80 ;
* V_65 = V_73 ;
* V_66 = V_74 ;
}
static void F_27 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
struct V_86 * V_87 )
{
T_1 V_88 = V_4 -> V_16 . V_89 &
V_90 ;
T_3 V_91 = V_92 | V_93 ;
F_28 ( V_19 , L_5 , V_88 ) ;
switch ( V_88 ) {
case V_94 :
break;
case V_95 :
case V_96 :
V_87 -> V_97 |= F_29 ( V_91 ) ;
break;
case V_98 :
if ( V_4 -> V_16 . V_99 . V_100 > V_101 )
V_87 -> V_97 |= F_29 ( V_91 ) ;
break;
default:
F_14 ( V_19 , L_6 ,
V_88 ) ;
break;
}
}
static void F_30 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
struct V_86 * V_87 ,
const T_1 * V_102 ,
T_3 V_103 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_104 * V_105 ;
bool V_106 = ! ! ( V_4 -> V_16 . V_89 &
V_90 ) ;
T_1 V_107 , V_108 ;
const T_1 * V_109 = V_102 ? : V_4 -> V_16 . V_109 ;
int V_37 ;
V_87 -> V_110 = F_29 ( F_31 ( V_8 -> V_29 ,
V_8 -> V_45 ) ) ;
V_87 -> V_103 = F_29 ( V_103 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_39 )
V_87 -> V_111 = F_29 ( V_112 ) ;
else
V_87 -> V_111 = F_29 ( V_113 ) ;
break;
case V_11 :
V_87 -> V_111 = F_29 ( V_114 ) ;
break;
case V_115 :
V_87 -> V_111 = F_29 ( V_116 ) ;
break;
case V_22 :
V_87 -> V_111 = F_29 ( V_117 ) ;
break;
case V_38 :
V_87 -> V_111 = F_29 ( V_118 ) ;
break;
default:
F_13 ( 1 ) ;
}
V_87 -> V_14 = F_29 ( V_8 -> V_14 ) ;
memcpy ( V_87 -> V_119 , V_4 -> V_120 , V_121 ) ;
if ( V_109 )
memcpy ( V_87 -> V_122 , V_109 , V_121 ) ;
else
F_32 ( V_87 -> V_122 ) ;
F_33 () ;
V_105 = F_34 ( V_4 -> V_123 ) ;
F_23 ( V_19 , V_4 , V_105 ? V_105 -> V_124 . V_125 -> V_64
: V_126 ,
& V_107 , & V_108 ) ;
F_35 () ;
V_87 -> V_65 = F_29 ( ( T_3 ) V_107 ) ;
V_87 -> V_66 = F_29 ( ( T_3 ) V_108 ) ;
V_87 -> V_127 =
F_29 ( V_4 -> V_16 . V_128 ?
V_129 : 0 ) ;
V_87 -> V_130 =
F_29 ( V_4 -> V_16 . V_131 ?
V_132 : 0 ) ;
for ( V_37 = 0 ; V_37 < V_24 ; V_37 ++ ) {
T_1 V_133 = V_62 [ V_37 ] ;
V_87 -> V_21 [ V_133 ] . V_134 =
F_36 ( V_8 -> V_135 [ V_37 ] . V_134 ) ;
V_87 -> V_21 [ V_133 ] . V_136 =
F_36 ( V_8 -> V_135 [ V_37 ] . V_136 ) ;
V_87 -> V_21 [ V_133 ] . V_137 =
F_36 ( V_8 -> V_135 [ V_37 ] . V_138 * 32 ) ;
V_87 -> V_21 [ V_133 ] . V_139 = V_8 -> V_135 [ V_37 ] . V_140 ;
V_87 -> V_21 [ V_133 ] . V_141 = F_7 ( V_133 ) ;
}
if ( V_4 -> type == V_11 )
V_87 -> V_21 [ V_60 ] . V_141 |=
F_7 ( V_61 ) ;
if ( V_4 -> V_16 . V_142 )
V_87 -> V_143 |= F_29 ( V_144 ) ;
if ( V_4 -> V_16 . V_145 )
V_87 -> V_97 |= F_29 ( V_146 ) ;
F_28 ( V_19 , L_7 ,
V_4 -> V_16 . V_145 ,
V_4 -> V_16 . V_89 ) ;
if ( V_4 -> V_16 . V_99 . V_100 != V_147 )
V_87 -> V_143 |= F_29 ( V_148 ) ;
if ( V_106 )
F_27 ( V_19 , V_4 , V_87 ) ;
V_87 -> V_149 = F_29 ( V_150 ) ;
}
static int F_37 ( struct V_18 * V_19 ,
struct V_86 * V_87 )
{
int V_36 = F_38 ( V_19 , V_151 , 0 ,
sizeof( * V_87 ) , V_87 ) ;
if ( V_36 )
F_14 ( V_19 , L_8 ,
F_39 ( V_87 -> V_103 ) , V_36 ) ;
return V_36 ;
}
static int F_40 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_3 V_103 , bool V_152 ,
const T_1 * V_102 )
{
struct V_86 V_87 = {} ;
struct V_153 * V_154 ;
F_41 ( V_4 -> type != V_10 ) ;
F_30 ( V_19 , V_4 , & V_87 , V_102 , V_103 ) ;
if ( V_4 -> V_39 ) {
struct V_155 * V_156 =
& V_4 -> V_16 . V_157 ;
V_87 . V_158 . V_159 = F_29 ( V_156 -> V_160 &
V_161 ) ;
V_154 = & V_87 . V_158 . V_162 ;
} else {
V_154 = & V_87 . V_162 ;
}
if ( V_4 -> V_16 . V_163 && V_4 -> V_16 . V_164 &&
! V_152 ) {
T_3 V_165 ;
V_165 = V_4 -> V_16 . V_166 *
V_4 -> V_16 . V_17 ;
V_165 *= 1024 ;
V_154 -> V_167 =
F_42 ( V_4 -> V_16 . V_168 + V_165 ) ;
V_154 -> V_169 =
F_29 ( V_4 -> V_16 . V_170 + V_165 ) ;
F_43 ( V_19 , L_9 ,
F_44 ( V_154 -> V_167 ) ,
F_39 ( V_154 -> V_169 ) ,
V_165 ) ;
V_154 -> V_171 = F_29 ( 1 ) ;
} else {
V_154 -> V_171 = F_29 ( 0 ) ;
V_87 . V_149 |= F_29 ( V_172 ) ;
}
V_154 -> V_173 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_154 -> V_174 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_154 -> V_175 = F_29 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_164 ) ;
V_154 -> V_176 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_164 ) ) ;
V_154 -> V_177 = F_29 ( V_19 -> V_31 -> V_178 . V_177 ) ;
V_154 -> V_179 = F_29 ( V_4 -> V_16 . V_180 ) ;
return F_37 ( V_19 , & V_87 ) ;
}
static int F_46 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_3 V_103 )
{
struct V_86 V_87 = {} ;
F_41 ( V_4 -> type != V_115 ) ;
F_30 ( V_19 , V_4 , & V_87 , NULL , V_103 ) ;
V_87 . V_149 = F_29 ( V_181 |
V_182 |
V_172 |
V_183 |
V_184 ) ;
V_19 -> V_31 -> V_185 |= V_186 ;
return F_37 ( V_19 , & V_87 ) ;
}
static int F_47 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_3 V_103 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_86 V_87 = {} ;
F_41 ( V_4 -> type != V_38 ) ;
F_30 ( V_19 , V_4 , & V_87 , NULL , V_103 ) ;
V_87 . V_149 = F_29 ( V_172 |
V_183 ) ;
V_87 . V_187 . V_173 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_87 . V_187 . V_174 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_87 . V_187 . V_188 = F_29 ( V_8 -> V_29 ) ;
return F_37 ( V_19 , & V_87 ) ;
}
static void F_48 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_189 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_39 &&
V_8 -> V_190 )
V_6 -> V_191 = true ;
}
static int F_49 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_3 V_103 )
{
struct V_86 V_87 = {} ;
struct V_189 V_6 = {} ;
F_41 ( V_4 -> type != V_22 ) ;
F_30 ( V_19 , V_4 , & V_87 , NULL , V_103 ) ;
V_87 . V_97 |= F_29 ( V_146 ) ;
V_87 . V_149 = F_29 ( V_183 ) ;
F_10 (
V_19 -> V_31 , V_32 ,
F_48 , & V_6 ) ;
V_87 . V_192 . V_193 = F_29 ( V_6 . V_191 ? 1 : 0 ) ;
return F_37 ( V_19 , & V_87 ) ;
}
static void F_50 ( struct V_18 * V_19 ,
struct V_194 * V_195 ,
T_1 * V_196 , T_3 V_197 )
{
T_3 V_198 ;
struct V_199 * V_200 = (struct V_199 * ) V_196 ;
V_198 = V_200 -> V_201 . V_196 . V_202 - V_196 ;
while ( ( V_198 < ( V_197 - 2 ) ) &&
( V_196 [ V_198 ] != V_203 ) )
V_198 += V_196 [ V_198 + 1 ] + 2 ;
if ( ( V_198 < ( V_197 - 1 ) ) && ( V_196 [ V_198 ] == V_203 ) ) {
V_195 -> V_198 = F_29 ( V_198 ) ;
V_195 -> V_204 = F_29 ( ( T_3 ) V_196 [ V_198 + 1 ] ) ;
} else {
F_51 ( V_19 , L_10 ) ;
}
}
static int F_52 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
struct V_205 * V_196 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_206 V_87 = {
. V_29 = V_207 ,
. V_185 = V_208 ,
} ;
struct V_194 V_195 = {} ;
struct V_209 * V_210 ;
T_3 V_211 ;
T_3 V_212 , V_213 ;
if ( F_41 ( ! V_196 ) )
return - V_214 ;
V_211 = V_196 -> V_215 ;
V_195 . V_216 = F_29 ( ( T_3 ) V_8 -> V_29 ) ;
V_210 = F_53 ( V_196 ) ;
V_195 . V_217 . V_215 = F_36 ( ( T_2 ) V_211 ) ;
V_195 . V_217 . V_53 = V_8 -> V_52 . V_53 ;
V_195 . V_217 . V_218 = F_29 ( V_219 ) ;
V_213 = V_220 | V_221 ;
V_213 |=
F_54 ( V_19 , ( void * ) V_196 -> V_6 , V_210 , 0 ) <<
V_222 ;
V_195 . V_217 . V_213 = F_29 ( V_213 ) ;
V_19 -> V_223 =
F_55 ( V_19 , V_19 -> V_224 -> V_225 ,
V_19 -> V_223 ) ;
V_195 . V_217 . V_226 =
F_29 ( F_7 ( V_19 -> V_223 ) <<
V_227 ) ;
if ( V_210 -> V_64 == V_228 || V_4 -> V_39 ) {
V_212 = V_79 ;
} else {
V_212 = V_80 ;
V_195 . V_217 . V_226 |= F_29 ( V_229 ) ;
}
V_195 . V_217 . V_226 |=
F_29 ( F_56 ( V_212 ) ) ;
if ( V_4 -> type == V_11 )
F_50 ( V_19 , & V_195 ,
V_196 -> V_6 ,
V_211 ) ;
V_87 . V_215 [ 0 ] = sizeof( V_195 ) ;
V_87 . V_6 [ 0 ] = & V_195 ;
V_87 . V_230 [ 0 ] = 0 ;
V_87 . V_215 [ 1 ] = V_211 ;
V_87 . V_6 [ 1 ] = V_196 -> V_6 ;
V_87 . V_230 [ 1 ] = V_231 ;
return F_57 ( V_19 , & V_87 ) ;
}
int F_58 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_205 * V_196 ;
int V_36 ;
F_41 ( V_4 -> type != V_11 &&
V_4 -> type != V_38 ) ;
V_196 = F_59 ( V_19 -> V_31 , V_4 , NULL ) ;
if ( ! V_196 )
return - V_232 ;
V_36 = F_52 ( V_19 , V_4 , V_196 ) ;
F_60 ( V_196 ) ;
return V_36 ;
}
static void F_61 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_233 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_163 )
return;
if ( V_4 -> V_39 && V_6 -> V_234 )
return;
V_6 -> V_234 = V_4 -> V_16 . V_170 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_62 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
struct V_235 * V_236 ,
bool V_237 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_233 V_6 = {
. V_19 = V_19 ,
. V_4 = V_4 ,
. V_234 = 0
} ;
V_236 -> V_173 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_236 -> V_174 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_236 -> V_175 = F_29 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_164 ) ;
V_236 -> V_176 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_164 ) ) ;
V_236 -> V_238 = F_29 ( V_4 -> V_26 ) ;
if ( V_237 ) {
F_10 (
V_19 -> V_31 , V_32 ,
F_61 , & V_6 ) ;
if ( V_6 . V_234 ) {
T_3 rand = ( F_63 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_239 = V_6 . V_234 +
F_64 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_239 =
F_65 ( V_19 -> V_240 ,
V_241 ) ;
}
}
V_236 -> V_242 = F_29 ( V_8 -> V_239 ) ;
V_236 -> V_243 = 0 ;
V_236 -> V_188 = F_29 ( V_8 -> V_29 ) ;
}
static int F_66 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_3 V_103 )
{
struct V_86 V_87 = {} ;
F_41 ( V_4 -> type != V_11 || V_4 -> V_39 ) ;
F_30 ( V_19 , V_4 , & V_87 , NULL , V_103 ) ;
V_87 . V_149 |= F_29 ( V_183 |
V_172 ) ;
F_62 ( V_19 , V_4 , & V_87 . V_244 ,
V_103 == V_245 ) ;
return F_37 ( V_19 , & V_87 ) ;
}
static int F_67 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_3 V_103 )
{
struct V_86 V_87 = {} ;
struct V_155 * V_156 = & V_4 -> V_16 . V_157 ;
F_41 ( V_4 -> type != V_11 || ! V_4 -> V_39 ) ;
F_30 ( V_19 , V_4 , & V_87 , NULL , V_103 ) ;
V_87 . V_149 |= F_29 ( V_183 |
V_172 ) ;
F_62 ( V_19 , V_4 , & V_87 . V_246 . V_244 ,
V_103 == V_245 ) ;
V_87 . V_246 . V_159 = F_29 ( V_156 -> V_160 &
V_161 ) ;
V_87 . V_246 . V_247 =
F_29 ( ! ! ( V_156 -> V_160 &
V_248 ) ) ;
return F_37 ( V_19 , & V_87 ) ;
}
static int F_68 ( struct V_18 * V_19 , struct V_3 * V_4 ,
T_3 V_103 , bool V_152 ,
const T_1 * V_102 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_40 ( V_19 , V_4 , V_103 ,
V_152 ,
V_102 ) ;
break;
case V_11 :
if ( ! V_4 -> V_39 )
return F_66 ( V_19 , V_4 , V_103 ) ;
else
return F_67 ( V_19 , V_4 , V_103 ) ;
break;
case V_115 :
return F_46 ( V_19 , V_4 , V_103 ) ;
case V_22 :
return F_49 ( V_19 , V_4 , V_103 ) ;
case V_38 :
return F_47 ( V_19 , V_4 , V_103 ) ;
default:
break;
}
return - V_249 ;
}
int F_69 ( struct V_18 * V_19 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_36 ;
if ( F_70 ( V_8 -> V_250 , L_11 ,
V_4 -> V_120 , F_71 ( V_4 ) ) )
return - V_43 ;
V_36 = F_68 ( V_19 , V_4 , V_245 ,
true , NULL ) ;
if ( V_36 )
return V_36 ;
F_72 ( V_19 , V_4 ) ;
V_8 -> V_250 = true ;
return 0 ;
}
int F_73 ( struct V_18 * V_19 , struct V_3 * V_4 ,
bool V_152 , const T_1 * V_102 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_70 ( ! V_8 -> V_250 , L_12 ,
V_4 -> V_120 , F_71 ( V_4 ) ) )
return - V_43 ;
return F_68 ( V_19 , V_4 , V_251 ,
V_152 , V_102 ) ;
}
int F_74 ( struct V_18 * V_19 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_86 V_87 ;
int V_36 ;
if ( F_70 ( ! V_8 -> V_250 , L_13 ,
V_4 -> V_120 , F_71 ( V_4 ) ) )
return - V_43 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_110 = F_29 ( F_31 ( V_8 -> V_29 ,
V_8 -> V_45 ) ) ;
V_87 . V_103 = F_29 ( V_252 ) ;
V_36 = F_38 ( V_19 , V_151 , 0 ,
sizeof( V_87 ) , & V_87 ) ;
if ( V_36 ) {
F_14 ( V_19 , L_14 , V_36 ) ;
return V_36 ;
}
V_8 -> V_250 = false ;
if ( V_4 -> type == V_115 )
V_19 -> V_31 -> V_185 &= ~ V_186 ;
return 0 ;
}
static void F_75 ( struct V_18 * V_19 ,
struct V_3 * V_253 , T_3 V_254 )
{
struct V_7 * V_8 =
F_2 ( V_253 ) ;
if ( ! F_76 ( V_253 ) ) {
int V_255 = F_77 ( V_253 ) ;
F_58 ( V_19 , V_253 ) ;
if ( V_253 -> V_39 &&
! F_78 ( & V_8 -> V_46 ) && V_254 ) {
T_3 V_256 = ( V_255 + 1 ) *
V_253 -> V_16 . V_17 -
V_257 ;
T_3 V_258 = V_254 + V_256 * 1024 ;
F_79 ( V_19 , V_253 ,
V_257 -
V_259 ,
V_258 ) ;
}
} else if ( ! F_78 ( & V_8 -> V_46 ) ) {
F_80 ( V_253 ) ;
F_81 ( V_19 -> V_253 , NULL ) ;
}
}
int F_82 ( struct V_18 * V_19 ,
struct V_260 * V_261 ,
struct V_262 * V_87 )
{
struct V_263 * V_264 = F_83 ( V_261 ) ;
struct V_265 * V_266 ;
struct V_3 * V_253 ;
struct V_3 * V_267 ;
T_4 V_268 ;
F_19 ( & V_19 -> V_59 ) ;
if ( V_19 -> V_224 -> V_269 . V_270 [ 0 ] & V_271 ) {
struct V_272 * V_196 = ( void * ) V_264 -> V_6 ;
V_266 = & V_196 -> V_266 ;
V_268 = F_44 ( V_196 -> V_268 ) ;
V_19 -> V_273 = F_39 ( V_196 -> V_254 ) ;
} else {
struct V_274 * V_196 = ( void * ) V_264 -> V_6 ;
V_266 = & V_196 -> V_266 ;
V_268 = F_44 ( V_196 -> V_268 ) ;
}
F_84 ( V_19 ,
L_15 ,
F_85 ( V_266 -> V_41 . V_41 ) &
V_275 ,
V_266 -> V_276 , V_268 ,
V_19 -> V_273 ,
F_39 ( V_266 -> V_277 ) ) ;
V_253 = F_86 ( V_19 -> V_253 ,
F_87 ( & V_19 -> V_59 ) ) ;
if ( F_88 ( V_253 && V_253 -> V_278 ) )
F_75 ( V_19 , V_253 , V_19 -> V_273 ) ;
V_267 = F_86 ( V_19 -> V_279 ,
F_87 ( & V_19 -> V_59 ) ) ;
if ( F_88 ( V_267 ) ) {
struct V_7 * V_8 =
F_2 ( V_267 ) ;
if ( ! V_19 -> V_280 )
V_19 -> V_280 =
V_281 ;
else
V_19 -> V_280 -- ;
if ( V_19 -> V_280 == 0 ) {
F_89 ( V_19 , V_8 , false ) ;
F_81 ( V_19 -> V_279 , NULL ) ;
}
}
return 0 ;
}
static void F_90 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_282 * V_283 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_29 != ( T_2 ) F_39 ( V_283 -> V_284 ) )
return;
if ( F_39 ( V_283 -> V_285 ) >
V_286 )
F_91 ( V_4 ) ;
}
int F_92 ( struct V_18 * V_19 ,
struct V_260 * V_261 ,
struct V_262 * V_87 )
{
struct V_263 * V_264 = F_83 ( V_261 ) ;
struct V_282 * V_287 = ( void * ) V_264 -> V_6 ;
F_43 ( V_19 ,
L_16 ,
F_39 ( V_287 -> V_284 ) ,
F_39 ( V_287 -> V_288 ) ,
F_39 ( V_287 -> V_285 ) ,
F_39 ( V_287 -> V_289 ) ,
F_39 ( V_287 -> V_290 ) ) ;
F_10 ( V_19 -> V_31 ,
V_291 ,
F_90 ,
V_287 ) ;
return 0 ;
}
