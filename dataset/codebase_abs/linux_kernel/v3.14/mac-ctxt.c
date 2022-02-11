static void F_1 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 )
return;
switch ( V_6 -> V_4 -> type ) {
case V_9 :
if ( V_4 -> type == V_10 ) {
if ( V_6 -> V_11 == V_12 &&
F_3 ( V_8 -> V_13 , V_6 -> V_14 ) &&
( V_4 -> V_15 . V_16 ==
V_6 -> V_4 -> V_15 . V_16 ) ) {
V_6 -> V_11 = V_8 -> V_13 ;
return;
}
}
break;
case V_10 :
if ( V_4 -> type == V_9 ||
V_4 -> type == V_10 ) {
if ( V_6 -> V_11 == V_12 &&
F_3 ( V_8 -> V_13 , V_6 -> V_14 ) &&
( V_4 -> V_15 . V_16 ==
V_6 -> V_4 -> V_15 . V_16 ) ) {
V_6 -> V_11 = V_8 -> V_13 ;
return;
}
}
break;
default:
break;
}
F_4 ( V_8 -> V_13 , V_6 -> V_14 ) ;
if ( V_6 -> V_11 == V_8 -> V_13 )
V_6 -> V_11 = V_12 ;
}
static void F_5 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_17 ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_18 = true ;
return;
}
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
if ( V_4 -> V_20 [ V_17 ] != V_21 )
F_6 ( V_4 -> V_20 [ V_17 ] , V_6 -> V_22 ) ;
if ( V_4 -> V_23 != V_21 )
F_6 ( V_4 -> V_23 , V_6 -> V_22 ) ;
F_4 ( V_8 -> V_24 , V_6 -> V_25 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
T_2 F_7 ( struct V_26 * V_27 ,
struct V_3 * V_4 )
{
T_2 V_28 = 0 , V_17 ;
if ( V_4 -> type == V_29 )
return F_8 ( V_30 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
if ( V_4 -> V_20 [ V_17 ] != V_21 )
V_28 |= F_8 ( V_4 -> V_20 [ V_17 ] ) ;
return V_28 ;
}
void F_9 ( struct V_26 * V_27 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_27 = V_27 ,
. V_4 = V_4 ,
. V_14 = { ( 1 << V_12 ) - 1 } ,
. V_11 = V_12 ,
} ;
F_10 (
V_27 -> V_31 , V_32 ,
F_1 , & V_6 ) ;
if ( V_6 . V_11 != V_12 )
V_8 -> V_13 = V_6 . V_11 ;
else if ( ! F_3 ( V_8 -> V_13 , V_6 . V_14 ) )
V_8 -> V_13 = F_11 ( V_6 . V_14 ,
V_12 ) ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_27 = V_27 ,
. V_4 = V_4 ,
. V_25 = { ( 1 << V_33 ) - 1 } ,
. V_14 = { ( 1 << V_12 ) - 1 } ,
. V_11 = V_12 ,
. V_22 = {
F_8 ( V_30 ) |
F_8 ( V_27 -> V_34 ) |
F_8 (IWL_MVM_CMD_QUEUE)
} ,
. V_18 = false ,
} ;
T_2 V_17 ;
int V_35 , V_36 ;
switch ( V_4 -> type ) {
case V_37 :
break;
case V_9 :
if ( ! V_4 -> V_38 )
break;
default:
F_4 ( 0 , V_6 . V_25 ) ;
}
F_10 (
V_27 -> V_31 , V_32 ,
F_5 , & V_6 ) ;
if ( V_6 . V_18 )
return 0 ;
if ( F_13 ( F_3 ( V_39 , & V_27 -> V_40 ) ) )
return - V_41 ;
V_8 -> V_24 = F_11 ( V_6 . V_25 ,
V_33 ) ;
if ( V_8 -> V_24 == V_33 ) {
F_14 ( V_27 , L_1 ) ;
V_35 = - V_42 ;
goto V_43;
}
if ( V_6 . V_11 != V_12 )
V_8 -> V_13 = V_6 . V_11 ;
else
V_8 -> V_13 = F_11 ( V_6 . V_14 ,
V_12 ) ;
if ( V_8 -> V_13 == V_12 ) {
F_14 ( V_27 , L_2 ) ;
V_35 = - V_42 ;
goto V_43;
}
V_8 -> V_44 = 0 ;
F_15 ( & V_8 -> V_45 . V_46 ) ;
V_8 -> V_45 . V_24 = V_47 ;
if ( V_4 -> type == V_29 ) {
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
V_4 -> V_20 [ V_17 ] = V_21 ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
T_1 V_48 = F_16 ( V_6 . V_22 ,
V_27 -> V_49 ) ;
if ( V_48 >= V_27 -> V_49 ) {
F_14 ( V_27 , L_3 ) ;
V_35 = - V_42 ;
goto V_43;
}
F_6 ( V_48 , V_6 . V_22 ) ;
V_4 -> V_20 [ V_17 ] = V_48 ;
}
if ( V_4 -> type == V_10 ) {
T_1 V_48 = F_16 ( V_6 . V_22 ,
V_27 -> V_49 ) ;
if ( V_48 >= V_27 -> V_49 ) {
F_14 ( V_27 , L_4 ) ;
V_35 = - V_42 ;
goto V_43;
}
V_4 -> V_23 = V_48 ;
} else {
V_4 -> V_23 = V_21 ;
}
V_8 -> V_50 . V_51 = V_52 ;
V_8 -> V_53 = V_52 ;
for ( V_36 = 0 ; V_36 < V_54 ; V_36 ++ )
V_8 -> V_55 [ V_36 ] = V_56 ;
return 0 ;
V_43:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_20 , V_21 , sizeof( V_4 -> V_20 ) ) ;
V_4 -> V_23 = V_21 ;
return V_35 ;
}
int F_17 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
T_2 V_17 ;
int V_35 ;
F_18 ( & V_27 -> V_57 ) ;
V_35 = F_12 ( V_27 , V_4 ) ;
if ( V_35 )
return V_35 ;
switch ( V_4 -> type ) {
case V_29 :
F_19 ( V_27 -> V_58 , V_30 ,
V_59 ) ;
break;
case V_10 :
F_19 ( V_27 -> V_58 , V_4 -> V_23 ,
V_60 ) ;
default:
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
F_19 ( V_27 -> V_58 , V_4 -> V_20 [ V_17 ] ,
V_61 [ V_17 ] ) ;
break;
}
return 0 ;
}
void F_20 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
int V_17 ;
F_18 ( & V_27 -> V_57 ) ;
switch ( V_4 -> type ) {
case V_29 :
F_21 ( V_27 -> V_58 , V_30 ) ;
break;
case V_10 :
F_21 ( V_27 -> V_58 , V_4 -> V_23 ) ;
default:
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
F_21 ( V_27 -> V_58 , V_4 -> V_20 [ V_17 ] ) ;
}
}
static void F_22 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
enum V_62 V_63 ,
T_1 * V_64 , T_1 * V_65 )
{
struct V_66 * V_67 ;
unsigned long V_68 = V_4 -> V_15 . V_69 ;
int V_70 = 100 ;
int V_71 = 100 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
int V_36 ;
V_67 = V_27 -> V_31 -> V_74 -> V_75 [ V_63 ] ;
F_23 (i, &basic, BITS_PER_LONG) {
int V_31 = V_67 -> V_76 [ V_36 ] . V_77 ;
if ( V_31 >= V_78 ) {
V_73 |= F_8 ( V_31 - V_78 ) ;
if ( V_70 > V_31 )
V_70 = V_31 ;
} else {
F_24 ( V_79 != 0 ) ;
V_72 |= F_8 ( V_31 ) ;
if ( V_71 > V_31 )
V_71 = V_31 ;
}
}
if ( V_80 < V_70 )
V_73 |= F_25 ( 24 ) >> V_78 ;
if ( V_81 < V_70 )
V_73 |= F_25 ( 12 ) >> V_78 ;
V_73 |= F_25 ( 6 ) >> V_78 ;
if ( V_82 < V_71 )
V_72 |= F_25 ( 11 ) >> V_79 ;
if ( V_83 < V_71 )
V_72 |= F_25 ( 5 ) >> V_79 ;
if ( V_84 < V_71 )
V_72 |= F_25 ( 2 ) >> V_79 ;
V_72 |= F_25 ( 1 ) >> V_79 ;
* V_64 = V_72 ;
* V_65 = V_73 ;
}
static void F_26 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
struct V_85 * V_86 )
{
T_1 V_87 = V_4 -> V_15 . V_88 &
V_89 ;
T_2 V_90 = V_91 | V_92 ;
F_27 ( V_27 , L_5 , V_87 ) ;
switch ( V_87 ) {
case V_93 :
break;
case V_94 :
case V_95 :
V_86 -> V_96 |= F_28 ( V_90 ) ;
break;
case V_97 :
if ( V_4 -> V_15 . V_98 . V_99 > V_100 )
V_86 -> V_96 |= F_28 ( V_90 ) ;
break;
default:
F_14 ( V_27 , L_6 ,
V_87 ) ;
break;
}
}
static void F_29 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
struct V_85 * V_86 ,
T_2 V_101 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_102 * V_103 ;
bool V_104 = ! ! ( V_4 -> V_15 . V_88 &
V_89 ) ;
T_1 V_105 , V_106 ;
int V_36 ;
V_86 -> V_107 = F_28 ( F_30 ( V_8 -> V_24 ,
V_8 -> V_44 ) ) ;
V_86 -> V_101 = F_28 ( V_101 ) ;
switch ( V_4 -> type ) {
case V_9 :
if ( V_4 -> V_38 )
V_86 -> V_108 = F_28 ( V_109 ) ;
else
V_86 -> V_108 = F_28 ( V_110 ) ;
break;
case V_10 :
V_86 -> V_108 = F_28 ( V_111 ) ;
break;
case V_112 :
V_86 -> V_108 = F_28 ( V_113 ) ;
break;
case V_29 :
V_86 -> V_108 = F_28 ( V_114 ) ;
break;
case V_37 :
V_86 -> V_108 = F_28 ( V_115 ) ;
break;
default:
F_13 ( 1 ) ;
}
V_86 -> V_13 = F_28 ( V_8 -> V_13 ) ;
memcpy ( V_86 -> V_116 , V_4 -> V_117 , V_118 ) ;
if ( V_4 -> V_15 . V_119 )
memcpy ( V_86 -> V_120 , V_4 -> V_15 . V_119 , V_118 ) ;
else
F_31 ( V_86 -> V_120 ) ;
F_32 () ;
V_103 = F_33 ( V_4 -> V_121 ) ;
F_22 ( V_27 , V_4 , V_103 ? V_103 -> V_122 . V_123 -> V_63
: V_124 ,
& V_105 , & V_106 ) ;
F_34 () ;
V_86 -> V_64 = F_28 ( ( T_2 ) V_105 ) ;
V_86 -> V_65 = F_28 ( ( T_2 ) V_106 ) ;
V_86 -> V_125 =
F_28 ( V_4 -> V_15 . V_126 ?
V_127 : 0 ) ;
V_86 -> V_128 =
F_28 ( V_4 -> V_15 . V_129 ?
V_130 : 0 ) ;
for ( V_36 = 0 ; V_36 < V_19 ; V_36 ++ ) {
T_1 V_131 = V_61 [ V_36 ] ;
V_86 -> V_17 [ V_131 ] . V_132 =
F_35 ( V_8 -> V_133 [ V_36 ] . V_132 ) ;
V_86 -> V_17 [ V_131 ] . V_134 =
F_35 ( V_8 -> V_133 [ V_36 ] . V_134 ) ;
V_86 -> V_17 [ V_131 ] . V_135 =
F_35 ( V_8 -> V_133 [ V_36 ] . V_136 * 32 ) ;
V_86 -> V_17 [ V_131 ] . V_137 = V_8 -> V_133 [ V_36 ] . V_138 ;
V_86 -> V_17 [ V_131 ] . V_139 = F_8 ( V_131 ) ;
}
if ( V_4 -> type == V_10 )
V_86 -> V_17 [ V_59 ] . V_139 |=
F_8 ( V_60 ) ;
if ( V_4 -> V_15 . V_140 )
V_86 -> V_141 |= F_28 ( V_142 ) ;
if ( V_4 -> V_15 . V_143 ) {
V_86 -> V_96 |= F_28 ( V_144 ) ;
if ( F_36 ( V_27 -> V_145 -> V_146 ) >= 8 )
V_86 -> V_96 |=
F_28 ( V_147 ) ;
}
F_27 ( V_27 , L_7 ,
V_4 -> V_15 . V_143 ,
V_4 -> V_15 . V_88 ) ;
if ( V_4 -> V_15 . V_98 . V_99 != V_148 )
V_86 -> V_141 |= F_28 ( V_149 ) ;
if ( V_104 )
F_26 ( V_27 , V_4 , V_86 ) ;
V_86 -> V_150 = F_28 ( V_151 ) ;
}
static int F_37 ( struct V_26 * V_27 ,
struct V_85 * V_86 )
{
int V_35 = F_38 ( V_27 , V_152 , V_153 ,
sizeof( * V_86 ) , V_86 ) ;
if ( V_35 )
F_14 ( V_27 , L_8 ,
F_39 ( V_86 -> V_101 ) , V_35 ) ;
return V_35 ;
}
static void F_40 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
struct V_154 * V_155 ,
bool V_156 )
{
if ( V_4 -> V_15 . V_157 && V_4 -> V_15 . V_158 &&
! V_156 ) {
T_2 V_159 ;
V_159 = V_4 -> V_15 . V_160 *
V_4 -> V_15 . V_16 ;
V_159 *= 1024 ;
V_155 -> V_161 =
F_41 ( V_4 -> V_15 . V_162 + V_159 ) ;
V_155 -> V_163 =
F_28 ( V_4 -> V_15 . V_164 + V_159 ) ;
F_42 ( V_27 , L_9 ,
F_43 ( V_155 -> V_161 ) ,
F_39 ( V_155 -> V_163 ) ,
V_159 ) ;
V_155 -> V_165 = F_28 ( 1 ) ;
} else {
V_155 -> V_165 = F_28 ( 0 ) ;
}
V_155 -> V_166 = F_28 ( V_4 -> V_15 . V_16 ) ;
V_155 -> V_167 =
F_28 ( F_44 ( V_4 -> V_15 . V_16 ) ) ;
V_155 -> V_168 = F_28 ( V_4 -> V_15 . V_16 *
V_4 -> V_15 . V_158 ) ;
V_155 -> V_169 =
F_28 ( F_44 ( V_4 -> V_15 . V_16 *
V_4 -> V_15 . V_158 ) ) ;
V_155 -> V_170 = F_28 ( V_27 -> V_31 -> V_171 . V_170 ) ;
V_155 -> V_172 = F_28 ( V_4 -> V_15 . V_173 ) ;
}
static int F_45 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_2 V_101 )
{
struct V_85 V_86 = {} ;
F_46 ( V_4 -> type != V_9 || V_4 -> V_38 ) ;
F_29 ( V_27 , V_4 , & V_86 , V_101 ) ;
if ( ! V_4 -> V_15 . V_157 || ! V_4 -> V_15 . V_158 )
V_86 . V_150 |= F_28 ( V_174 ) ;
else
V_86 . V_150 &= ~ F_28 ( V_174 ) ;
F_40 ( V_27 , V_4 , & V_86 . V_175 ,
V_101 == V_176 ) ;
return F_37 ( V_27 , & V_86 ) ;
}
static int F_47 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_2 V_101 )
{
struct V_85 V_86 = {} ;
struct V_177 * V_178 = & V_4 -> V_15 . V_179 ;
F_46 ( V_4 -> type != V_9 || ! V_4 -> V_38 ) ;
F_29 ( V_27 , V_4 , & V_86 , V_101 ) ;
F_40 ( V_27 , V_4 , & V_86 . V_180 . V_175 ,
V_101 == V_176 ) ;
V_86 . V_180 . V_181 = F_28 ( V_178 -> V_182 &
V_183 ) ;
return F_37 ( V_27 , & V_86 ) ;
}
static int F_48 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_2 V_101 )
{
struct V_85 V_86 = {} ;
F_46 ( V_4 -> type != V_112 ) ;
F_29 ( V_27 , V_4 , & V_86 , V_101 ) ;
V_86 . V_150 = F_28 ( V_184 |
V_185 |
V_174 |
V_186 |
V_187 ) ;
V_27 -> V_31 -> V_188 |= V_189 ;
return F_37 ( V_27 , & V_86 ) ;
}
static int F_49 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_2 V_101 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_85 V_86 = {} ;
F_46 ( V_4 -> type != V_37 ) ;
F_29 ( V_27 , V_4 , & V_86 , V_101 ) ;
V_86 . V_150 = F_28 ( V_174 |
V_186 ) ;
V_86 . V_190 . V_166 = F_28 ( V_4 -> V_15 . V_16 ) ;
V_86 . V_190 . V_167 =
F_28 ( F_44 ( V_4 -> V_15 . V_16 ) ) ;
V_86 . V_190 . V_191 = F_28 ( V_8 -> V_24 ) ;
return F_37 ( V_27 , & V_86 ) ;
}
static void F_50 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_192 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_10 && V_4 -> V_38 &&
V_8 -> V_193 )
V_6 -> V_194 = true ;
}
static int F_51 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_2 V_101 )
{
struct V_85 V_86 = {} ;
struct V_192 V_6 = {} ;
F_46 ( V_4 -> type != V_29 ) ;
F_29 ( V_27 , V_4 , & V_86 , V_101 ) ;
V_86 . V_96 |= F_28 ( V_144 ) ;
V_86 . V_150 = F_28 ( V_186 ) ;
F_10 (
V_27 -> V_31 , V_32 ,
F_50 , & V_6 ) ;
V_86 . V_195 . V_196 = F_28 ( V_6 . V_194 ? 1 : 0 ) ;
return F_37 ( V_27 , & V_86 ) ;
}
static void F_52 ( struct V_26 * V_27 ,
struct V_197 * V_198 ,
T_1 * V_199 , T_2 V_200 )
{
T_2 V_201 ;
struct V_202 * V_203 = (struct V_202 * ) V_199 ;
V_201 = V_203 -> V_204 . V_199 . V_205 - V_199 ;
while ( ( V_201 < ( V_200 - 2 ) ) &&
( V_199 [ V_201 ] != V_206 ) )
V_201 += V_199 [ V_201 + 1 ] + 2 ;
if ( ( V_201 < ( V_200 - 1 ) ) && ( V_199 [ V_201 ] == V_206 ) ) {
V_198 -> V_201 = F_28 ( V_201 ) ;
V_198 -> V_207 = F_28 ( ( T_2 ) V_199 [ V_201 + 1 ] ) ;
} else {
F_53 ( V_27 , L_10 ) ;
}
}
static int F_54 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
struct V_208 * V_199 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_209 V_86 = {
. V_24 = V_210 ,
. V_188 = V_211 ,
} ;
struct V_197 V_198 = {} ;
struct V_212 * V_213 ;
T_2 V_214 ;
T_2 V_215 ;
if ( F_46 ( ! V_199 ) )
return - V_216 ;
V_214 = V_199 -> V_217 ;
V_198 . V_218 = F_28 ( ( T_2 ) V_8 -> V_24 ) ;
V_198 . V_219 . V_217 = F_35 ( ( V_220 ) V_214 ) ;
V_198 . V_219 . V_51 = V_8 -> V_50 . V_51 ;
V_198 . V_219 . V_221 = F_28 ( V_222 ) ;
V_198 . V_219 . V_223 = F_28 ( V_224 |
V_225 |
V_226 ) ;
V_27 -> V_227 =
F_55 ( V_27 , F_56 ( V_27 -> V_145 ) ,
V_27 -> V_227 ) ;
V_198 . V_219 . V_228 =
F_28 ( F_8 ( V_27 -> V_227 ) <<
V_229 ) ;
V_213 = F_57 ( V_199 ) ;
if ( V_213 -> V_63 == V_230 || V_4 -> V_38 ) {
V_215 = V_78 ;
} else {
V_215 = V_79 ;
V_198 . V_219 . V_228 |= F_28 ( V_231 ) ;
}
V_198 . V_219 . V_228 |=
F_28 ( F_58 ( V_215 ) ) ;
if ( V_4 -> type == V_10 )
F_52 ( V_27 , & V_198 ,
V_199 -> V_6 ,
V_214 ) ;
V_86 . V_217 [ 0 ] = sizeof( V_198 ) ;
V_86 . V_6 [ 0 ] = & V_198 ;
V_86 . V_232 [ 0 ] = 0 ;
V_86 . V_217 [ 1 ] = V_214 ;
V_86 . V_6 [ 1 ] = V_199 -> V_6 ;
V_86 . V_232 [ 1 ] = V_233 ;
return F_59 ( V_27 , & V_86 ) ;
}
int F_60 ( struct V_26 * V_27 ,
struct V_3 * V_4 )
{
struct V_208 * V_199 ;
int V_35 ;
F_46 ( V_4 -> type != V_10 &&
V_4 -> type != V_37 ) ;
V_199 = F_61 ( V_27 -> V_31 , V_4 ) ;
if ( ! V_199 )
return - V_234 ;
V_35 = F_54 ( V_27 , V_4 , V_199 ) ;
F_62 ( V_199 ) ;
return V_35 ;
}
static void F_63 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_235 * V_6 = V_1 ;
if ( V_4 -> type != V_9 || ! V_4 -> V_15 . V_157 )
return;
if ( V_4 -> V_38 && V_6 -> V_236 )
return;
V_6 -> V_236 = V_4 -> V_15 . V_164 ;
V_6 -> V_16 = V_4 -> V_15 . V_16 ;
}
static void F_64 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
struct V_237 * V_238 ,
bool V_239 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_235 V_6 = {
. V_27 = V_27 ,
. V_4 = V_4 ,
. V_236 = 0
} ;
V_238 -> V_166 = F_28 ( V_4 -> V_15 . V_16 ) ;
V_238 -> V_167 =
F_28 ( F_44 ( V_4 -> V_15 . V_16 ) ) ;
V_238 -> V_168 = F_28 ( V_4 -> V_15 . V_16 *
V_4 -> V_15 . V_158 ) ;
V_238 -> V_169 =
F_28 ( F_44 ( V_4 -> V_15 . V_16 *
V_4 -> V_15 . V_158 ) ) ;
V_238 -> V_240 = F_28 ( V_4 -> V_23 ) ;
if ( V_239 ) {
F_10 (
V_27 -> V_31 , V_32 ,
F_63 , & V_6 ) ;
if ( V_6 . V_236 ) {
T_2 rand = ( F_65 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_241 = V_6 . V_236 +
F_66 ( V_6 . V_16 * rand /
100 ) ;
} else {
V_8 -> V_241 =
F_67 ( V_27 -> V_58 ,
V_242 ) ;
}
}
V_238 -> V_243 = F_28 ( V_8 -> V_241 ) ;
V_238 -> V_244 = 0 ;
V_238 -> V_191 = F_28 ( V_8 -> V_24 ) ;
}
static int F_68 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_2 V_101 )
{
struct V_85 V_86 = {} ;
F_46 ( V_4 -> type != V_10 || V_4 -> V_38 ) ;
F_29 ( V_27 , V_4 , & V_86 , V_101 ) ;
V_86 . V_150 |= F_28 ( V_186 ) ;
F_64 ( V_27 , V_4 , & V_86 . V_245 ,
V_101 == V_176 ) ;
return F_37 ( V_27 , & V_86 ) ;
}
static int F_69 ( struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_2 V_101 )
{
struct V_85 V_86 = {} ;
struct V_177 * V_178 = & V_4 -> V_15 . V_179 ;
F_46 ( V_4 -> type != V_10 || ! V_4 -> V_38 ) ;
F_29 ( V_27 , V_4 , & V_86 , V_101 ) ;
F_64 ( V_27 , V_4 , & V_86 . V_246 . V_245 ,
V_101 == V_176 ) ;
V_86 . V_246 . V_181 = F_28 ( V_178 -> V_182 &
V_183 ) ;
V_86 . V_246 . V_247 =
F_28 ( ! ! ( V_178 -> V_182 &
V_248 ) ) ;
return F_37 ( V_27 , & V_86 ) ;
}
static int F_70 ( struct V_26 * V_27 , struct V_3 * V_4 ,
T_2 V_101 )
{
switch ( V_4 -> type ) {
case V_9 :
if ( ! V_4 -> V_38 )
return F_45 ( V_27 , V_4 ,
V_101 ) ;
else
return F_47 ( V_27 , V_4 ,
V_101 ) ;
break;
case V_10 :
if ( ! V_4 -> V_38 )
return F_68 ( V_27 , V_4 , V_101 ) ;
else
return F_69 ( V_27 , V_4 , V_101 ) ;
break;
case V_112 :
return F_48 ( V_27 , V_4 , V_101 ) ;
case V_29 :
return F_51 ( V_27 , V_4 , V_101 ) ;
case V_37 :
return F_49 ( V_27 , V_4 , V_101 ) ;
default:
break;
}
return - V_249 ;
}
int F_71 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_35 ;
if ( F_72 ( V_8 -> V_250 , L_11 ,
V_4 -> V_117 , F_73 ( V_4 ) ) )
return - V_42 ;
V_35 = F_70 ( V_27 , V_4 , V_176 ) ;
if ( V_35 )
return V_35 ;
F_74 ( V_27 , V_4 ) ;
V_8 -> V_250 = true ;
return 0 ;
}
int F_75 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_72 ( ! V_8 -> V_250 , L_12 ,
V_4 -> V_117 , F_73 ( V_4 ) ) )
return - V_42 ;
return F_70 ( V_27 , V_4 , V_251 ) ;
}
int F_76 ( struct V_26 * V_27 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_85 V_86 ;
int V_35 ;
if ( F_72 ( ! V_8 -> V_250 , L_13 ,
V_4 -> V_117 , F_73 ( V_4 ) ) )
return - V_42 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_107 = F_28 ( F_30 ( V_8 -> V_24 ,
V_8 -> V_44 ) ) ;
V_86 . V_101 = F_28 ( V_252 ) ;
V_35 = F_38 ( V_27 , V_152 , V_153 ,
sizeof( V_86 ) , & V_86 ) ;
if ( V_35 ) {
F_14 ( V_27 , L_14 , V_35 ) ;
return V_35 ;
}
V_8 -> V_250 = false ;
if ( V_4 -> type == V_112 )
V_27 -> V_31 -> V_188 &= ~ V_189 ;
return 0 ;
}
int F_77 ( struct V_26 * V_27 ,
struct V_253 * V_254 ,
struct V_255 * V_86 )
{
struct V_256 * V_257 = F_78 ( V_254 ) ;
struct V_258 * V_199 = ( void * ) V_257 -> V_6 ;
V_220 V_40 V_259 =
F_79 ( V_199 -> V_260 . V_40 . V_40 ) ;
T_2 V_215 V_259 =
F_39 ( V_199 -> V_260 . V_261 ) ;
F_80 ( V_27 , L_15 ,
V_40 & V_262 ,
V_199 -> V_260 . V_263 ,
F_43 ( V_199 -> V_264 ) ,
V_215 ) ;
return 0 ;
}
static void F_81 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_265 * V_266 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_24 != ( V_220 ) F_39 ( V_266 -> V_267 ) )
return;
if ( F_39 ( V_266 -> V_268 ) >
V_269 )
F_82 ( V_4 ) ;
}
int F_83 ( struct V_26 * V_27 ,
struct V_253 * V_254 ,
struct V_255 * V_86 )
{
struct V_256 * V_257 = F_78 ( V_254 ) ;
struct V_265 * V_270 = ( void * ) V_257 -> V_6 ;
F_42 ( V_27 ,
L_16 ,
F_39 ( V_270 -> V_267 ) ,
F_39 ( V_270 -> V_271 ) ,
F_39 ( V_270 -> V_268 ) ,
F_39 ( V_270 -> V_272 ) ,
F_39 ( V_270 -> V_273 ) ) ;
F_10 ( V_27 -> V_31 ,
V_274 ,
F_81 ,
V_270 ) ;
return 0 ;
}
