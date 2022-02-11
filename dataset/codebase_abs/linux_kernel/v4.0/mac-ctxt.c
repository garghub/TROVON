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
if ( V_4 -> type == V_11 )
V_18 |= F_7 ( V_4 -> V_25 ) ;
return V_18 ;
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_6 = V_1 ;
if ( V_4 == V_6 -> V_27 )
return;
V_6 -> V_28 |= F_6 ( V_4 ) ;
}
static void F_9 ( void * V_1 ,
struct V_29 * V_30 )
{
struct V_26 * V_6 = V_1 ;
struct V_31 * V_32 = F_10 ( V_30 ) ;
V_6 -> V_28 |= V_32 -> V_33 ;
}
unsigned long F_11 ( struct V_34 * V_35 ,
struct V_3 * V_27 )
{
struct V_26 V_6 = {
. V_27 = V_27 ,
. V_28 =
F_7 ( V_21 ) |
F_7 ( V_35 -> V_36 ) |
F_7 ( V_37 ) ,
} ;
F_12 ( & V_35 -> V_38 ) ;
F_13 (
V_35 -> V_39 , V_40 ,
F_8 , & V_6 ) ;
F_14 ( V_35 -> V_39 ,
F_9 ,
& V_6 ) ;
return V_6 . V_28 ;
}
static void F_15 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_41 = true ;
return;
}
F_5 ( V_8 -> V_42 , V_6 -> V_43 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
void F_16 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_13 (
V_35 -> V_39 , V_40 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_17 ( V_6 . V_15 ,
V_13 ) ;
}
static int F_18 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_43 = { ( 1 << V_44 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_41 = false ,
} ;
T_3 V_19 ;
int V_45 , V_46 ;
unsigned long V_28 ;
switch ( V_4 -> type ) {
case V_47 :
break;
case V_10 :
if ( ! V_4 -> V_48 )
break;
default:
F_5 ( 0 , V_6 . V_43 ) ;
}
F_13 (
V_35 -> V_39 , V_40 ,
F_15 , & V_6 ) ;
V_28 = F_11 ( V_35 , V_4 ) ;
if ( V_6 . V_41 )
return 0 ;
if ( F_19 ( F_3 ( V_49 , & V_35 -> V_50 ) ) )
return - V_51 ;
V_8 -> V_42 = F_17 ( V_6 . V_43 ,
V_44 ) ;
if ( V_8 -> V_42 == V_44 ) {
F_20 ( V_35 , L_1 ) ;
V_45 = - V_52 ;
goto V_53;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_17 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_20 ( V_35 , L_2 ) ;
V_45 = - V_52 ;
goto V_53;
}
V_8 -> V_54 = 0 ;
F_21 ( & V_8 -> V_55 . V_56 ) ;
V_8 -> V_55 . V_42 = V_57 ;
if ( V_4 -> type == V_20 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_4 -> V_23 [ V_19 ] = V_24 ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
T_1 V_58 = F_22 ( & V_28 ,
V_35 -> V_59 ) ;
if ( V_58 >= V_35 -> V_59 ) {
F_20 ( V_35 , L_3 ) ;
V_45 = - V_52 ;
goto V_53;
}
F_23 ( V_58 , & V_28 ) ;
V_4 -> V_23 [ V_19 ] = V_58 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_58 = F_22 ( & V_28 ,
V_35 -> V_59 ) ;
if ( V_58 >= V_35 -> V_59 ) {
F_20 ( V_35 , L_4 ) ;
V_45 = - V_52 ;
goto V_53;
}
V_4 -> V_25 = V_58 ;
} else {
V_4 -> V_25 = V_24 ;
}
V_8 -> V_60 . V_61 = V_62 ;
V_8 -> V_63 = V_62 ;
for ( V_46 = 0 ; V_46 < V_64 ; V_46 ++ )
V_8 -> V_65 [ V_46 ] = V_66 ;
return 0 ;
V_53:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_24 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_25 = V_24 ;
return V_45 ;
}
int F_24 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
unsigned int V_67 = V_68 . V_69 ?
V_35 -> V_70 -> V_71 -> V_72 :
V_73 ;
T_3 V_19 ;
int V_45 ;
F_12 ( & V_35 -> V_38 ) ;
V_45 = F_18 ( V_35 , V_4 ) ;
if ( V_45 )
return V_45 ;
switch ( V_4 -> type ) {
case V_20 :
F_25 ( V_35 , V_21 ,
V_74 , V_67 ) ;
break;
case V_11 :
F_25 ( V_35 , V_4 -> V_25 ,
V_75 , V_67 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_25 ( V_35 , V_4 -> V_23 [ V_19 ] ,
V_76 [ V_19 ] ,
V_67 ) ;
break;
}
return 0 ;
}
void F_26 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
int V_19 ;
F_12 ( & V_35 -> V_38 ) ;
switch ( V_4 -> type ) {
case V_20 :
F_27 ( V_35 , V_21 , 0 ) ;
break;
case V_11 :
F_27 ( V_35 , V_4 -> V_25 , 0 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_27 ( V_35 , V_4 -> V_23 [ V_19 ] , 0 ) ;
}
}
static void F_28 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
enum V_77 V_78 ,
T_1 * V_79 , T_1 * V_80 )
{
struct V_81 * V_82 ;
unsigned long V_83 = V_4 -> V_16 . V_84 ;
int V_85 = 100 ;
int V_86 = 100 ;
T_1 V_87 = 0 ;
T_1 V_88 = 0 ;
int V_46 ;
V_82 = V_35 -> V_39 -> V_89 -> V_90 [ V_78 ] ;
F_29 (i, &basic, BITS_PER_LONG) {
int V_39 = V_82 -> V_91 [ V_46 ] . V_92 ;
if ( V_39 >= V_93 ) {
V_88 |= F_7 ( V_39 - V_93 ) ;
if ( V_85 > V_39 )
V_85 = V_39 ;
} else {
F_30 ( V_94 != 0 ) ;
V_87 |= F_7 ( V_39 ) ;
if ( V_86 > V_39 )
V_86 = V_39 ;
}
}
if ( V_95 < V_85 )
V_88 |= F_31 ( 24 ) >> V_93 ;
if ( V_96 < V_85 )
V_88 |= F_31 ( 12 ) >> V_93 ;
V_88 |= F_31 ( 6 ) >> V_93 ;
if ( V_97 < V_86 )
V_87 |= F_31 ( 11 ) >> V_94 ;
if ( V_98 < V_86 )
V_87 |= F_31 ( 5 ) >> V_94 ;
if ( V_99 < V_86 )
V_87 |= F_31 ( 2 ) >> V_94 ;
V_87 |= F_31 ( 1 ) >> V_94 ;
* V_79 = V_87 ;
* V_80 = V_88 ;
}
static void F_32 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_100 * V_101 )
{
T_1 V_102 = V_4 -> V_16 . V_103 &
V_104 ;
T_3 V_105 = V_106 | V_107 ;
F_33 ( V_35 , L_5 , V_102 ) ;
switch ( V_102 ) {
case V_108 :
break;
case V_109 :
case V_110 :
V_101 -> V_111 |= F_34 ( V_105 ) ;
break;
case V_112 :
if ( V_4 -> V_16 . V_113 . V_114 > V_115 )
V_101 -> V_111 |= F_34 ( V_105 ) ;
break;
default:
F_20 ( V_35 , L_6 ,
V_102 ) ;
break;
}
}
static void F_35 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_100 * V_101 ,
const T_1 * V_116 ,
T_3 V_117 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_118 * V_119 ;
bool V_120 = ! ! ( V_4 -> V_16 . V_103 &
V_104 ) ;
T_1 V_121 , V_122 ;
const T_1 * V_123 = V_116 ? : V_4 -> V_16 . V_123 ;
int V_46 ;
V_101 -> V_124 = F_34 ( F_36 ( V_8 -> V_42 ,
V_8 -> V_54 ) ) ;
V_101 -> V_117 = F_34 ( V_117 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_48 )
V_101 -> V_125 = F_34 ( V_126 ) ;
else
V_101 -> V_125 = F_34 ( V_127 ) ;
break;
case V_11 :
V_101 -> V_125 = F_34 ( V_128 ) ;
break;
case V_129 :
V_101 -> V_125 = F_34 ( V_130 ) ;
break;
case V_20 :
V_101 -> V_125 = F_34 ( V_131 ) ;
break;
case V_47 :
V_101 -> V_125 = F_34 ( V_132 ) ;
break;
default:
F_19 ( 1 ) ;
}
V_101 -> V_14 = F_34 ( V_8 -> V_14 ) ;
memcpy ( V_101 -> V_133 , V_4 -> V_134 , V_135 ) ;
if ( V_123 )
memcpy ( V_101 -> V_136 , V_123 , V_135 ) ;
else
F_37 ( V_101 -> V_136 ) ;
F_38 () ;
V_119 = F_39 ( V_4 -> V_137 ) ;
F_28 ( V_35 , V_4 , V_119 ? V_119 -> V_138 . V_139 -> V_78
: V_140 ,
& V_121 , & V_122 ) ;
F_40 () ;
V_101 -> V_79 = F_34 ( ( T_3 ) V_121 ) ;
V_101 -> V_80 = F_34 ( ( T_3 ) V_122 ) ;
V_101 -> V_141 =
F_34 ( V_4 -> V_16 . V_142 ?
V_143 : 0 ) ;
V_101 -> V_144 =
F_34 ( V_4 -> V_16 . V_145 ?
V_146 : 0 ) ;
for ( V_46 = 0 ; V_46 < V_22 ; V_46 ++ ) {
T_1 V_147 = V_76 [ V_46 ] ;
V_101 -> V_19 [ V_147 ] . V_148 =
F_41 ( V_8 -> V_149 [ V_46 ] . V_148 ) ;
V_101 -> V_19 [ V_147 ] . V_150 =
F_41 ( V_8 -> V_149 [ V_46 ] . V_150 ) ;
V_101 -> V_19 [ V_147 ] . V_151 =
F_41 ( V_8 -> V_149 [ V_46 ] . V_152 * 32 ) ;
V_101 -> V_19 [ V_147 ] . V_153 = V_8 -> V_149 [ V_46 ] . V_154 ;
V_101 -> V_19 [ V_147 ] . V_155 = F_7 ( V_147 ) ;
}
if ( V_4 -> type == V_11 )
V_101 -> V_19 [ V_74 ] . V_155 |=
F_7 ( V_75 ) ;
if ( V_4 -> V_16 . V_156 )
V_101 -> V_157 |= F_34 ( V_158 ) ;
if ( V_4 -> V_16 . V_159 )
V_101 -> V_111 |= F_34 ( V_160 ) ;
F_33 ( V_35 , L_7 ,
V_4 -> V_16 . V_159 ,
V_4 -> V_16 . V_103 ) ;
if ( V_4 -> V_16 . V_113 . V_114 != V_161 )
V_101 -> V_157 |= F_34 ( V_162 ) ;
if ( V_120 )
F_32 ( V_35 , V_4 , V_101 ) ;
V_101 -> V_163 = F_34 ( V_164 ) ;
}
static int F_42 ( struct V_34 * V_35 ,
struct V_100 * V_101 )
{
int V_45 = F_43 ( V_35 , V_165 , 0 ,
sizeof( * V_101 ) , V_101 ) ;
if ( V_45 )
F_20 ( V_35 , L_8 ,
F_44 ( V_101 -> V_117 ) , V_45 ) ;
return V_45 ;
}
static int F_45 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 , bool V_166 ,
const T_1 * V_116 )
{
struct V_100 V_101 = {} ;
struct V_167 * V_168 ;
F_46 ( V_4 -> type != V_10 ) ;
F_35 ( V_35 , V_4 , & V_101 , V_116 , V_117 ) ;
if ( V_4 -> V_48 ) {
struct V_169 * V_170 =
& V_4 -> V_16 . V_171 ;
V_101 . V_172 . V_173 = F_34 ( V_170 -> V_174 &
V_175 ) ;
V_168 = & V_101 . V_172 . V_30 ;
} else {
V_168 = & V_101 . V_30 ;
}
if ( V_4 -> V_16 . V_176 && V_4 -> V_16 . V_177 &&
! V_166 ) {
T_3 V_178 ;
V_178 = V_4 -> V_16 . V_179 *
V_4 -> V_16 . V_17 ;
V_178 *= 1024 ;
V_168 -> V_180 =
F_47 ( V_4 -> V_16 . V_181 + V_178 ) ;
V_168 -> V_182 =
F_34 ( V_4 -> V_16 . V_183 + V_178 ) ;
F_48 ( V_35 , L_9 ,
F_49 ( V_168 -> V_180 ) ,
F_44 ( V_168 -> V_182 ) ,
V_178 ) ;
V_168 -> V_184 = F_34 ( 1 ) ;
} else {
V_168 -> V_184 = F_34 ( 0 ) ;
V_101 . V_163 |= F_34 ( V_185 ) ;
}
V_168 -> V_186 = F_34 ( V_4 -> V_16 . V_17 ) ;
V_168 -> V_187 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 ) ) ;
V_168 -> V_188 = F_34 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ;
V_168 -> V_189 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ) ;
V_168 -> V_190 = F_34 ( V_35 -> V_39 -> V_191 . V_190 ) ;
V_168 -> V_192 = F_34 ( V_4 -> V_16 . V_193 ) ;
return F_42 ( V_35 , & V_101 ) ;
}
static int F_51 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
F_46 ( V_4 -> type != V_129 ) ;
F_35 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
V_101 . V_163 = F_34 ( V_194 |
V_195 |
V_185 |
V_196 |
V_197 ) ;
V_35 -> V_39 -> V_198 |= V_199 ;
return F_42 ( V_35 , & V_101 ) ;
}
static int F_52 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_100 V_101 = {} ;
F_46 ( V_4 -> type != V_47 ) ;
F_35 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
V_101 . V_163 = F_34 ( V_185 |
V_196 ) ;
V_101 . V_200 . V_186 = F_34 ( V_4 -> V_16 . V_17 ) ;
V_101 . V_200 . V_187 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 ) ) ;
V_101 . V_200 . V_201 = F_34 ( V_8 -> V_42 ) ;
return F_42 ( V_35 , & V_101 ) ;
}
static void F_53 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_202 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_48 &&
V_8 -> V_203 )
V_6 -> V_204 = true ;
}
static int F_54 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
struct V_202 V_6 = {} ;
F_46 ( V_4 -> type != V_20 ) ;
F_35 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
V_101 . V_111 |= F_34 ( V_160 ) ;
V_101 . V_163 = F_34 ( V_196 ) ;
F_13 (
V_35 -> V_39 , V_40 ,
F_53 , & V_6 ) ;
V_101 . V_205 . V_206 = F_34 ( V_6 . V_204 ? 1 : 0 ) ;
return F_42 ( V_35 , & V_101 ) ;
}
static void F_55 ( struct V_34 * V_35 ,
struct V_207 * V_208 ,
T_1 * V_209 , T_3 V_210 )
{
T_3 V_211 ;
struct V_212 * V_213 = (struct V_212 * ) V_209 ;
V_211 = V_213 -> V_214 . V_209 . V_215 - V_209 ;
while ( ( V_211 < ( V_210 - 2 ) ) &&
( V_209 [ V_211 ] != V_216 ) )
V_211 += V_209 [ V_211 + 1 ] + 2 ;
if ( ( V_211 < ( V_210 - 1 ) ) && ( V_209 [ V_211 ] == V_216 ) ) {
V_208 -> V_211 = F_34 ( V_211 ) ;
V_208 -> V_217 = F_34 ( ( T_3 ) V_209 [ V_211 + 1 ] ) ;
} else {
F_56 ( V_35 , L_10 ) ;
}
}
static int F_57 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_218 * V_209 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_219 V_101 = {
. V_42 = V_220 ,
. V_198 = V_221 ,
} ;
struct V_207 V_208 = {} ;
struct V_222 * V_223 ;
T_3 V_224 ;
T_3 V_225 , V_226 ;
if ( F_46 ( ! V_209 ) )
return - V_227 ;
V_224 = V_209 -> V_228 ;
V_208 . V_229 = F_34 ( ( T_3 ) V_8 -> V_42 ) ;
V_223 = F_58 ( V_209 ) ;
V_208 . V_230 . V_228 = F_41 ( ( T_2 ) V_224 ) ;
V_208 . V_230 . V_61 = V_8 -> V_60 . V_61 ;
V_208 . V_230 . V_231 = F_34 ( V_232 ) ;
V_226 = V_233 | V_234 ;
V_226 |=
F_59 ( V_35 , ( void * ) V_209 -> V_6 , V_223 , 0 ) <<
V_235 ;
V_208 . V_230 . V_226 = F_34 ( V_226 ) ;
V_35 -> V_236 =
F_60 ( V_35 , F_61 ( V_35 ) ,
V_35 -> V_236 ) ;
V_208 . V_230 . V_237 =
F_34 ( F_7 ( V_35 -> V_236 ) <<
V_238 ) ;
if ( V_223 -> V_78 == V_239 || V_4 -> V_48 ) {
V_225 = V_93 ;
} else {
V_225 = V_94 ;
V_208 . V_230 . V_237 |= F_34 ( V_240 ) ;
}
V_208 . V_230 . V_237 |=
F_34 ( F_62 ( V_225 ) ) ;
if ( V_4 -> type == V_11 )
F_55 ( V_35 , & V_208 ,
V_209 -> V_6 ,
V_224 ) ;
V_101 . V_228 [ 0 ] = sizeof( V_208 ) ;
V_101 . V_6 [ 0 ] = & V_208 ;
V_101 . V_241 [ 0 ] = 0 ;
V_101 . V_228 [ 1 ] = V_224 ;
V_101 . V_6 [ 1 ] = V_209 -> V_6 ;
V_101 . V_241 [ 1 ] = V_242 ;
return F_63 ( V_35 , & V_101 ) ;
}
int F_64 ( struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_218 * V_209 ;
int V_45 ;
F_46 ( V_4 -> type != V_11 &&
V_4 -> type != V_47 ) ;
V_209 = F_65 ( V_35 -> V_39 , V_4 , NULL ) ;
if ( ! V_209 )
return - V_243 ;
V_45 = F_57 ( V_35 , V_4 , V_209 ) ;
F_66 ( V_209 ) ;
return V_45 ;
}
static void F_67 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_244 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_176 )
return;
if ( V_4 -> V_48 && V_6 -> V_245 )
return;
V_6 -> V_245 = V_4 -> V_16 . V_183 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_68 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
struct V_246 * V_247 ,
bool V_248 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_244 V_6 = {
. V_35 = V_35 ,
. V_4 = V_4 ,
. V_245 = 0
} ;
V_247 -> V_186 = F_34 ( V_4 -> V_16 . V_17 ) ;
V_247 -> V_187 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 ) ) ;
V_247 -> V_188 = F_34 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ;
V_247 -> V_189 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_177 ) ) ;
V_247 -> V_249 = F_34 ( V_4 -> V_25 ) ;
if ( V_248 ) {
F_13 (
V_35 -> V_39 , V_40 ,
F_67 , & V_6 ) ;
if ( V_6 . V_245 ) {
T_3 rand = ( F_69 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_250 = V_6 . V_245 +
F_70 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_250 =
F_71 ( V_35 -> V_251 ,
V_252 ) ;
}
}
V_247 -> V_253 = F_34 ( V_8 -> V_250 ) ;
V_247 -> V_254 = 0 ;
V_247 -> V_201 = F_34 ( V_8 -> V_42 ) ;
}
static int F_72 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
F_46 ( V_4 -> type != V_11 || V_4 -> V_48 ) ;
F_35 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
V_101 . V_163 |= F_34 ( V_196 |
V_185 ) ;
F_68 ( V_35 , V_4 , & V_101 . V_255 ,
V_117 == V_256 ) ;
return F_42 ( V_35 , & V_101 ) ;
}
static int F_73 ( struct V_34 * V_35 ,
struct V_3 * V_4 ,
T_3 V_117 )
{
struct V_100 V_101 = {} ;
struct V_169 * V_170 = & V_4 -> V_16 . V_171 ;
F_46 ( V_4 -> type != V_11 || ! V_4 -> V_48 ) ;
F_35 ( V_35 , V_4 , & V_101 , NULL , V_117 ) ;
V_101 . V_163 |= F_34 ( V_196 |
V_185 ) ;
F_68 ( V_35 , V_4 , & V_101 . V_257 . V_255 ,
V_117 == V_256 ) ;
V_101 . V_257 . V_173 = F_34 ( V_170 -> V_174 &
V_175 ) ;
V_101 . V_257 . V_258 =
F_34 ( ! ! ( V_170 -> V_174 &
V_259 ) ) ;
return F_42 ( V_35 , & V_101 ) ;
}
static int F_74 ( struct V_34 * V_35 , struct V_3 * V_4 ,
T_3 V_117 , bool V_166 ,
const T_1 * V_116 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_45 ( V_35 , V_4 , V_117 ,
V_166 ,
V_116 ) ;
break;
case V_11 :
if ( ! V_4 -> V_48 )
return F_72 ( V_35 , V_4 , V_117 ) ;
else
return F_73 ( V_35 , V_4 , V_117 ) ;
break;
case V_129 :
return F_51 ( V_35 , V_4 , V_117 ) ;
case V_20 :
return F_54 ( V_35 , V_4 , V_117 ) ;
case V_47 :
return F_52 ( V_35 , V_4 , V_117 ) ;
default:
break;
}
return - V_260 ;
}
int F_75 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_45 ;
if ( F_76 ( V_8 -> V_261 , L_11 ,
V_4 -> V_134 , F_77 ( V_4 ) ) )
return - V_52 ;
V_45 = F_74 ( V_35 , V_4 , V_256 ,
true , NULL ) ;
if ( V_45 )
return V_45 ;
F_78 ( V_35 , V_4 ) ;
V_8 -> V_261 = true ;
return 0 ;
}
int F_79 ( struct V_34 * V_35 , struct V_3 * V_4 ,
bool V_166 , const T_1 * V_116 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_76 ( ! V_8 -> V_261 , L_12 ,
V_4 -> V_134 , F_77 ( V_4 ) ) )
return - V_52 ;
return F_74 ( V_35 , V_4 , V_262 ,
V_166 , V_116 ) ;
}
int F_80 ( struct V_34 * V_35 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_100 V_101 ;
int V_45 ;
if ( F_76 ( ! V_8 -> V_261 , L_13 ,
V_4 -> V_134 , F_77 ( V_4 ) ) )
return - V_52 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_124 = F_34 ( F_36 ( V_8 -> V_42 ,
V_8 -> V_54 ) ) ;
V_101 . V_117 = F_34 ( V_263 ) ;
V_45 = F_43 ( V_35 , V_165 , 0 ,
sizeof( V_101 ) , & V_101 ) ;
if ( V_45 ) {
F_20 ( V_35 , L_14 , V_45 ) ;
return V_45 ;
}
V_8 -> V_261 = false ;
if ( V_4 -> type == V_129 )
V_35 -> V_39 -> V_198 &= ~ V_199 ;
return 0 ;
}
static void F_81 ( struct V_34 * V_35 ,
struct V_3 * V_264 , T_3 V_265 ,
bool V_266 )
{
struct V_7 * V_8 =
F_2 ( V_264 ) ;
if ( ! V_266 && ! V_8 -> V_267 )
return;
V_8 -> V_267 = true ;
if ( ! F_82 ( V_264 ) ) {
int V_268 = F_83 ( V_264 ) ;
F_64 ( V_35 , V_264 ) ;
if ( V_264 -> V_48 &&
! F_84 ( & V_8 -> V_55 ) && V_265 &&
V_266 ) {
T_3 V_269 = ( V_268 + 1 ) *
V_264 -> V_16 . V_17 -
V_270 ;
T_3 V_271 = V_265 + V_269 * 1024 ;
F_85 ( V_35 , V_264 ,
V_270 -
V_272 ,
V_271 ) ;
}
} else if ( ! F_84 ( & V_8 -> V_55 ) ) {
F_86 ( V_264 ) ;
F_87 ( V_35 -> V_264 , NULL ) ;
}
}
int F_88 ( struct V_34 * V_35 ,
struct V_273 * V_274 ,
struct V_275 * V_101 )
{
struct V_276 * V_277 = F_89 ( V_274 ) ;
struct V_278 * V_209 = ( void * ) V_277 -> V_6 ;
struct V_279 * V_280 ;
struct V_3 * V_264 ;
struct V_3 * V_281 ;
T_2 V_50 ;
F_12 ( & V_35 -> V_38 ) ;
V_280 = & V_209 -> V_280 ;
V_35 -> V_282 = F_44 ( V_209 -> V_265 ) ;
V_50 = F_90 ( V_280 -> V_50 . V_50 ) & V_283 ;
F_91 ( V_35 ,
L_15 ,
V_50 , V_280 -> V_284 ,
F_49 ( V_209 -> V_285 ) ,
V_35 -> V_282 ,
F_44 ( V_280 -> V_286 ) ) ;
V_264 = F_92 ( V_35 -> V_264 ,
F_93 ( & V_35 -> V_38 ) ) ;
if ( F_94 ( V_264 && V_264 -> V_287 ) )
F_81 ( V_35 , V_264 , V_35 -> V_282 ,
( V_50 == V_288 ) ) ;
V_281 = F_92 ( V_35 -> V_289 ,
F_93 ( & V_35 -> V_38 ) ) ;
if ( F_94 ( V_281 ) ) {
struct V_7 * V_8 =
F_2 ( V_281 ) ;
if ( ! V_35 -> V_290 )
V_35 -> V_290 =
V_291 ;
else
V_35 -> V_290 -- ;
if ( V_35 -> V_290 == 0 ) {
F_95 ( V_35 , V_8 , false ) ;
F_87 ( V_35 -> V_289 , NULL ) ;
}
}
return 0 ;
}
static void F_96 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_292 * V_293 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_42 != ( T_2 ) F_44 ( V_293 -> V_294 ) )
return;
if ( F_44 ( V_293 -> V_295 ) >
V_296 )
F_97 ( V_4 ) ;
}
int F_98 ( struct V_34 * V_35 ,
struct V_273 * V_274 ,
struct V_275 * V_101 )
{
struct V_276 * V_277 = F_89 ( V_274 ) ;
struct V_292 * V_297 = ( void * ) V_277 -> V_6 ;
F_48 ( V_35 ,
L_16 ,
F_44 ( V_297 -> V_294 ) ,
F_44 ( V_297 -> V_298 ) ,
F_44 ( V_297 -> V_295 ) ,
F_44 ( V_297 -> V_299 ) ,
F_44 ( V_297 -> V_300 ) ) ;
F_13 ( V_35 -> V_39 ,
V_301 ,
F_96 ,
V_297 ) ;
return 0 ;
}
