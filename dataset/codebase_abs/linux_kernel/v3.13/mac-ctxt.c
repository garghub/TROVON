static void F_1 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_9 ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_10 = true ;
return;
}
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
if ( V_4 -> V_12 [ V_9 ] != V_13 )
F_3 ( V_4 -> V_12 [ V_9 ] , V_6 -> V_14 ) ;
if ( V_4 -> V_15 != V_13 )
F_3 ( V_4 -> V_15 , V_6 -> V_14 ) ;
F_4 ( V_8 -> V_16 , V_6 -> V_17 ) ;
switch ( V_6 -> V_4 -> type ) {
case V_18 :
if ( V_4 -> type == V_19 ) {
if ( V_6 -> V_20 == V_21 &&
F_5 ( V_8 -> V_22 , V_6 -> V_23 ) )
V_6 -> V_20 = V_8 -> V_22 ;
return;
}
break;
case V_19 :
if ( V_4 -> type == V_18 ||
V_4 -> type == V_19 ) {
if ( V_6 -> V_20 == V_21 &&
F_5 ( V_8 -> V_22 , V_6 -> V_23 ) )
V_6 -> V_20 = V_8 -> V_22 ;
return;
}
break;
default:
break;
}
F_4 ( V_8 -> V_22 , V_6 -> V_23 ) ;
if ( V_6 -> V_20 == V_8 -> V_22 )
V_6 -> V_20 = V_21 ;
}
T_2 F_6 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
T_2 V_26 = 0 , V_9 ;
if ( V_4 -> type == V_27 )
return F_7 ( V_28 ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
if ( V_4 -> V_12 [ V_9 ] != V_13 )
V_26 |= F_7 ( V_4 -> V_12 [ V_9 ] ) ;
return V_26 ;
}
static int F_8 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_25 = V_25 ,
. V_4 = V_4 ,
. V_17 = { ( 1 << V_29 ) - 1 } ,
. V_23 = { ( 1 << V_21 ) - 1 } ,
. V_20 = V_21 ,
. V_14 = {
F_7 ( V_28 ) |
F_7 ( V_25 -> V_30 ) |
F_7 (IWL_MVM_CMD_QUEUE)
} ,
. V_10 = false ,
} ;
T_2 V_9 ;
int V_31 , V_32 ;
switch ( V_4 -> type ) {
case V_33 :
break;
case V_18 :
if ( ! V_4 -> V_34 )
break;
default:
F_4 ( 0 , V_6 . V_17 ) ;
}
F_9 (
V_25 -> V_35 , V_36 ,
F_1 , & V_6 ) ;
if ( V_6 . V_10 )
return 0 ;
if ( F_10 ( F_5 ( V_37 , & V_25 -> V_38 ) ) )
return - V_39 ;
V_8 -> V_16 = F_11 ( V_6 . V_17 ,
V_29 ) ;
if ( V_8 -> V_16 == V_29 ) {
F_12 ( V_25 , L_1 ) ;
V_31 = - V_40 ;
goto V_41;
}
if ( V_6 . V_20 != V_21 )
V_8 -> V_22 = V_6 . V_20 ;
else
V_8 -> V_22 = F_11 ( V_6 . V_23 ,
V_21 ) ;
if ( V_8 -> V_22 == V_21 ) {
F_12 ( V_25 , L_2 ) ;
V_31 = - V_40 ;
goto V_41;
}
V_8 -> V_42 = 0 ;
F_13 ( & V_8 -> V_43 . V_44 ) ;
V_8 -> V_43 . V_16 = V_45 ;
if ( V_4 -> type == V_27 ) {
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
V_4 -> V_12 [ V_9 ] = V_13 ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
T_1 V_46 = F_14 ( V_6 . V_14 ,
V_25 -> V_47 ) ;
if ( V_46 >= V_25 -> V_47 ) {
F_12 ( V_25 , L_3 ) ;
V_31 = - V_40 ;
goto V_41;
}
F_3 ( V_46 , V_6 . V_14 ) ;
V_4 -> V_12 [ V_9 ] = V_46 ;
}
if ( V_4 -> type == V_19 ) {
T_1 V_46 = F_14 ( V_6 . V_14 ,
V_25 -> V_47 ) ;
if ( V_46 >= V_25 -> V_47 ) {
F_12 ( V_25 , L_4 ) ;
V_31 = - V_40 ;
goto V_41;
}
V_4 -> V_15 = V_46 ;
} else {
V_4 -> V_15 = V_13 ;
}
V_8 -> V_48 . V_49 = V_50 ;
V_8 -> V_51 = V_50 ;
for ( V_32 = 0 ; V_32 < V_52 ; V_32 ++ )
V_8 -> V_53 [ V_32 ] = V_54 ;
return 0 ;
V_41:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_12 , V_13 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_15 = V_13 ;
return V_31 ;
}
int F_15 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
T_2 V_9 ;
int V_31 ;
F_16 ( & V_25 -> V_55 ) ;
V_31 = F_8 ( V_25 , V_4 ) ;
if ( V_31 )
return V_31 ;
switch ( V_4 -> type ) {
case V_27 :
F_17 ( V_25 -> V_56 , V_28 ,
V_57 ) ;
break;
case V_19 :
F_17 ( V_25 -> V_56 , V_4 -> V_15 ,
V_58 ) ;
default:
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_17 ( V_25 -> V_56 , V_4 -> V_12 [ V_9 ] ,
V_59 [ V_9 ] ) ;
break;
}
return 0 ;
}
void F_18 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
int V_9 ;
F_16 ( & V_25 -> V_55 ) ;
switch ( V_4 -> type ) {
case V_27 :
F_19 ( V_25 -> V_56 , V_28 ) ;
break;
case V_19 :
F_19 ( V_25 -> V_56 , V_4 -> V_15 ) ;
default:
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_19 ( V_25 -> V_56 , V_4 -> V_12 [ V_9 ] ) ;
}
}
static void F_20 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
enum V_60 V_61 ,
T_1 * V_62 , T_1 * V_63 )
{
struct V_64 * V_65 ;
unsigned long V_66 = V_4 -> V_67 . V_68 ;
int V_69 = 100 ;
int V_70 = 100 ;
T_1 V_71 = 0 ;
T_1 V_72 = 0 ;
int V_32 ;
V_65 = V_25 -> V_35 -> V_73 -> V_74 [ V_61 ] ;
F_21 (i, &basic, BITS_PER_LONG) {
int V_35 = V_65 -> V_75 [ V_32 ] . V_76 ;
if ( V_35 >= V_77 ) {
V_72 |= F_7 ( V_35 - V_77 ) ;
if ( V_69 > V_35 )
V_69 = V_35 ;
} else {
F_22 ( V_78 != 0 ) ;
V_71 |= F_7 ( V_35 ) ;
if ( V_70 > V_35 )
V_70 = V_35 ;
}
}
if ( V_79 < V_69 )
V_72 |= F_23 ( 24 ) >> V_77 ;
if ( V_80 < V_69 )
V_72 |= F_23 ( 12 ) >> V_77 ;
V_72 |= F_23 ( 6 ) >> V_77 ;
if ( V_81 < V_70 )
V_71 |= F_23 ( 11 ) >> V_78 ;
if ( V_82 < V_70 )
V_71 |= F_23 ( 5 ) >> V_78 ;
if ( V_83 < V_70 )
V_71 |= F_23 ( 2 ) >> V_78 ;
V_71 |= F_23 ( 1 ) >> V_78 ;
* V_62 = V_71 ;
* V_63 = V_72 ;
}
static void F_24 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_84 * V_85 ,
T_2 V_86 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_87 * V_88 ;
T_1 V_89 , V_90 ;
int V_32 ;
V_85 -> V_91 = F_25 ( F_26 ( V_8 -> V_16 ,
V_8 -> V_42 ) ) ;
V_85 -> V_86 = F_25 ( V_86 ) ;
switch ( V_4 -> type ) {
case V_18 :
if ( V_4 -> V_34 )
V_85 -> V_92 = F_25 ( V_93 ) ;
else
V_85 -> V_92 = F_25 ( V_94 ) ;
break;
case V_19 :
V_85 -> V_92 = F_25 ( V_95 ) ;
break;
case V_96 :
V_85 -> V_92 = F_25 ( V_97 ) ;
break;
case V_27 :
V_85 -> V_92 = F_25 ( V_98 ) ;
break;
case V_33 :
V_85 -> V_92 = F_25 ( V_99 ) ;
break;
default:
F_10 ( 1 ) ;
}
V_85 -> V_22 = F_25 ( V_8 -> V_22 ) ;
memcpy ( V_85 -> V_100 , V_4 -> V_101 , V_102 ) ;
if ( V_4 -> V_67 . V_103 )
memcpy ( V_85 -> V_104 , V_4 -> V_67 . V_103 , V_102 ) ;
else
F_27 ( V_85 -> V_104 ) ;
F_28 () ;
V_88 = F_29 ( V_4 -> V_105 ) ;
F_20 ( V_25 , V_4 , V_88 ? V_88 -> V_106 . V_107 -> V_61
: V_108 ,
& V_89 , & V_90 ) ;
F_30 () ;
V_85 -> V_62 = F_25 ( ( T_2 ) V_89 ) ;
V_85 -> V_63 = F_25 ( ( T_2 ) V_90 ) ;
V_85 -> V_109 =
F_25 ( V_4 -> V_67 . V_110 ?
V_111 : 0 ) ;
V_85 -> V_112 =
F_25 ( V_4 -> V_67 . V_113 ?
V_114 : 0 ) ;
for ( V_32 = 0 ; V_32 < V_115 ; V_32 ++ ) {
V_85 -> V_9 [ V_32 ] . V_116 = F_31 ( V_8 -> V_117 [ V_32 ] . V_116 ) ;
V_85 -> V_9 [ V_32 ] . V_118 = F_31 ( V_8 -> V_117 [ V_32 ] . V_118 ) ;
V_85 -> V_9 [ V_32 ] . V_119 = V_8 -> V_117 [ V_32 ] . V_120 ;
V_85 -> V_9 [ V_32 ] . V_121 =
F_31 ( V_8 -> V_117 [ V_32 ] . V_122 * 32 ) ;
V_85 -> V_9 [ V_32 ] . V_123 = F_7 ( V_59 [ V_32 ] ) ;
}
if ( V_4 -> type == V_19 )
V_85 -> V_9 [ V_124 ] . V_123 |= F_7 ( V_58 ) ;
if ( V_4 -> V_67 . V_125 )
V_85 -> V_126 |= F_25 ( V_127 ) ;
if ( V_4 -> V_67 . V_128 ) {
V_85 -> V_129 |= F_25 ( V_130 ) ;
if ( F_32 ( V_25 -> V_131 -> V_132 ) >= 8 )
V_85 -> V_129 |=
F_25 ( V_133 ) ;
}
if ( V_4 -> V_67 . V_134 . V_135 != V_136 ) {
V_85 -> V_126 |= F_25 ( V_137 ) ;
V_85 -> V_129 |= F_25 ( V_138 |
V_139 ) ;
}
V_85 -> V_140 = F_25 ( V_141 ) ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_84 * V_85 )
{
int V_31 = F_34 ( V_25 , V_142 , V_143 ,
sizeof( * V_85 ) , V_85 ) ;
if ( V_31 )
F_12 ( V_25 , L_5 ,
F_35 ( V_85 -> V_86 ) , V_31 ) ;
return V_31 ;
}
static void F_36 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_144 * V_145 ,
bool V_146 )
{
if ( V_4 -> V_67 . V_147 && V_4 -> V_67 . V_148 &&
! V_146 ) {
T_2 V_149 ;
V_149 = V_4 -> V_67 . V_150 *
V_4 -> V_67 . V_151 ;
V_149 *= 1024 ;
V_145 -> V_152 =
F_37 ( V_4 -> V_67 . V_153 + V_149 ) ;
V_145 -> V_154 =
F_25 ( V_4 -> V_67 . V_155 + V_149 ) ;
F_38 ( V_25 , L_6 ,
F_39 ( V_145 -> V_152 ) ,
F_35 ( V_145 -> V_154 ) ,
V_149 ) ;
V_145 -> V_156 = F_25 ( 1 ) ;
} else {
V_145 -> V_156 = F_25 ( 0 ) ;
}
V_145 -> V_157 = F_25 ( V_4 -> V_67 . V_151 ) ;
V_145 -> V_158 =
F_25 ( F_40 ( V_4 -> V_67 . V_151 ) ) ;
V_145 -> V_159 = F_25 ( V_4 -> V_67 . V_151 *
V_4 -> V_67 . V_148 ) ;
V_145 -> V_160 =
F_25 ( F_40 ( V_4 -> V_67 . V_151 *
V_4 -> V_67 . V_148 ) ) ;
V_145 -> V_161 = F_25 ( V_25 -> V_35 -> V_162 . V_161 ) ;
V_145 -> V_163 = F_25 ( V_4 -> V_67 . V_164 ) ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_86 )
{
struct V_84 V_85 = {} ;
F_42 ( V_4 -> type != V_18 || V_4 -> V_34 ) ;
F_24 ( V_25 , V_4 , & V_85 , V_86 ) ;
if ( ! V_4 -> V_67 . V_147 || ! V_4 -> V_67 . V_148 )
V_85 . V_140 |= F_25 ( V_165 ) ;
else
V_85 . V_140 &= ~ F_25 ( V_165 ) ;
F_36 ( V_25 , V_4 , & V_85 . V_166 ,
V_86 == V_167 ) ;
return F_33 ( V_25 , & V_85 ) ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_86 )
{
struct V_84 V_85 = {} ;
struct V_168 * V_169 = & V_4 -> V_67 . V_170 ;
F_42 ( V_4 -> type != V_18 || ! V_4 -> V_34 ) ;
F_24 ( V_25 , V_4 , & V_85 , V_86 ) ;
F_36 ( V_25 , V_4 , & V_85 . V_171 . V_166 ,
V_86 == V_167 ) ;
V_85 . V_171 . V_172 = F_25 ( V_169 -> V_173 &
V_174 ) ;
return F_33 ( V_25 , & V_85 ) ;
}
static int F_44 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_86 )
{
struct V_84 V_85 = {} ;
F_42 ( V_4 -> type != V_96 ) ;
F_24 ( V_25 , V_4 , & V_85 , V_86 ) ;
V_85 . V_140 = F_25 ( V_175 |
V_176 |
V_165 |
V_177 |
V_178 ) ;
V_25 -> V_35 -> V_179 |= V_180 ;
return F_33 ( V_25 , & V_85 ) ;
}
static int F_45 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_86 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_84 V_85 = {} ;
F_42 ( V_4 -> type != V_33 ) ;
F_24 ( V_25 , V_4 , & V_85 , V_86 ) ;
V_85 . V_140 = F_25 ( V_165 |
V_177 ) ;
V_85 . V_181 . V_157 = F_25 ( V_4 -> V_67 . V_151 ) ;
V_85 . V_181 . V_158 =
F_25 ( F_40 ( V_4 -> V_67 . V_151 ) ) ;
V_85 . V_181 . V_182 = F_25 ( V_8 -> V_16 ) ;
return F_33 ( V_25 , & V_85 ) ;
}
static void F_46 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_183 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_19 && V_4 -> V_34 &&
V_8 -> V_184 )
V_6 -> V_185 = true ;
}
static int F_47 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_86 )
{
struct V_84 V_85 = {} ;
struct V_183 V_6 = {} ;
F_42 ( V_4 -> type != V_27 ) ;
F_24 ( V_25 , V_4 , & V_85 , V_86 ) ;
V_85 . V_129 |= F_25 ( V_130 ) ;
V_85 . V_140 = F_25 ( V_177 ) ;
F_9 (
V_25 -> V_35 , V_36 ,
F_46 , & V_6 ) ;
V_85 . V_186 . V_187 = F_25 ( V_6 . V_185 ? 1 : 0 ) ;
return F_33 ( V_25 , & V_85 ) ;
}
static void F_48 ( struct V_24 * V_25 ,
struct V_188 * V_189 ,
T_1 * V_190 , T_2 V_191 )
{
T_2 V_192 ;
struct V_193 * V_194 = (struct V_193 * ) V_190 ;
V_192 = V_194 -> V_195 . V_190 . V_196 - V_190 ;
while ( ( V_192 < ( V_191 - 2 ) ) &&
( V_190 [ V_192 ] != V_197 ) )
V_192 += V_190 [ V_192 + 1 ] + 2 ;
if ( ( V_192 < ( V_191 - 1 ) ) && ( V_190 [ V_192 ] == V_197 ) ) {
V_189 -> V_192 = F_25 ( V_192 ) ;
V_189 -> V_198 = F_25 ( ( T_2 ) V_190 [ V_192 + 1 ] ) ;
} else {
F_49 ( V_25 , L_7 ) ;
}
}
static int F_50 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_199 * V_190 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_200 V_85 = {
. V_16 = V_201 ,
. V_179 = V_202 ,
} ;
struct V_188 V_189 = {} ;
struct V_203 * V_204 ;
T_2 V_205 ;
T_2 V_206 ;
if ( F_42 ( ! V_190 ) )
return - V_207 ;
V_205 = V_190 -> V_208 ;
V_189 . V_209 = F_25 ( ( T_2 ) V_8 -> V_16 ) ;
V_189 . V_210 . V_208 = F_31 ( ( V_211 ) V_205 ) ;
V_189 . V_210 . V_49 = V_8 -> V_48 . V_49 ;
V_189 . V_210 . V_212 = F_25 ( V_213 ) ;
V_189 . V_210 . V_214 = F_25 ( V_215 |
V_216 |
V_217 ) ;
V_25 -> V_218 =
F_51 ( V_25 , F_52 ( V_25 -> V_131 ) ,
V_25 -> V_218 ) ;
V_189 . V_210 . V_219 =
F_25 ( F_7 ( V_25 -> V_218 ) <<
V_220 ) ;
V_204 = F_53 ( V_190 ) ;
if ( V_204 -> V_61 == V_221 || V_4 -> V_34 ) {
V_206 = V_77 ;
} else {
V_206 = V_78 ;
V_189 . V_210 . V_219 |= F_25 ( V_222 ) ;
}
V_189 . V_210 . V_219 |=
F_25 ( F_54 ( V_206 ) ) ;
if ( V_4 -> type == V_19 )
F_48 ( V_25 , & V_189 ,
V_190 -> V_6 ,
V_205 ) ;
V_85 . V_208 [ 0 ] = sizeof( V_189 ) ;
V_85 . V_6 [ 0 ] = & V_189 ;
V_85 . V_223 [ 0 ] = 0 ;
V_85 . V_208 [ 1 ] = V_205 ;
V_85 . V_6 [ 1 ] = V_190 -> V_6 ;
V_85 . V_223 [ 1 ] = V_224 ;
return F_55 ( V_25 , & V_85 ) ;
}
int F_56 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
struct V_199 * V_190 ;
int V_31 ;
F_42 ( V_4 -> type != V_19 &&
V_4 -> type != V_33 ) ;
V_190 = F_57 ( V_25 -> V_35 , V_4 ) ;
if ( ! V_190 )
return - V_225 ;
V_31 = F_50 ( V_25 , V_4 , V_190 ) ;
F_58 ( V_190 ) ;
return V_31 ;
}
static void F_59 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_226 * V_6 = V_1 ;
if ( V_4 -> type != V_18 || ! V_4 -> V_67 . V_147 )
return;
if ( V_4 -> V_34 && V_6 -> V_227 )
return;
V_6 -> V_227 = V_4 -> V_67 . V_155 ;
V_6 -> V_151 = V_4 -> V_67 . V_151 ;
}
static void F_60 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_228 * V_229 ,
bool V_230 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_226 V_6 = {
. V_25 = V_25 ,
. V_4 = V_4 ,
. V_227 = 0
} ;
V_229 -> V_157 = F_25 ( V_4 -> V_67 . V_151 ) ;
V_229 -> V_158 =
F_25 ( F_40 ( V_4 -> V_67 . V_151 ) ) ;
V_229 -> V_159 = F_25 ( V_4 -> V_67 . V_151 *
V_4 -> V_67 . V_148 ) ;
V_229 -> V_160 =
F_25 ( F_40 ( V_4 -> V_67 . V_151 *
V_4 -> V_67 . V_148 ) ) ;
V_229 -> V_231 = F_25 ( V_4 -> V_15 ) ;
if ( V_230 ) {
F_9 (
V_25 -> V_35 , V_36 ,
F_59 , & V_6 ) ;
if ( V_6 . V_227 ) {
T_2 rand = ( F_61 () % ( 80 - 20 ) ) + 20 ;
V_8 -> V_232 = V_6 . V_227 +
F_62 ( V_6 . V_151 * rand /
100 ) ;
} else {
V_8 -> V_232 =
F_63 ( V_25 -> V_56 ,
V_233 ) ;
}
}
V_229 -> V_234 = F_25 ( V_8 -> V_232 ) ;
V_229 -> V_235 = 0 ;
V_229 -> V_182 = F_25 ( V_8 -> V_16 ) ;
}
static int F_64 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_86 )
{
struct V_84 V_85 = {} ;
F_42 ( V_4 -> type != V_19 || V_4 -> V_34 ) ;
F_24 ( V_25 , V_4 , & V_85 , V_86 ) ;
V_85 . V_140 |= F_25 ( V_177 ) ;
F_60 ( V_25 , V_4 , & V_85 . V_236 ,
V_86 == V_167 ) ;
return F_33 ( V_25 , & V_85 ) ;
}
static int F_65 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_86 )
{
struct V_84 V_85 = {} ;
struct V_168 * V_169 = & V_4 -> V_67 . V_170 ;
F_42 ( V_4 -> type != V_19 || ! V_4 -> V_34 ) ;
F_24 ( V_25 , V_4 , & V_85 , V_86 ) ;
F_60 ( V_25 , V_4 , & V_85 . V_237 . V_236 ,
V_86 == V_167 ) ;
V_85 . V_237 . V_172 = F_25 ( V_169 -> V_173 &
V_174 ) ;
V_85 . V_237 . V_238 =
F_25 ( ! ! ( V_169 -> V_173 &
V_239 ) ) ;
return F_33 ( V_25 , & V_85 ) ;
}
static int F_66 ( struct V_24 * V_25 , struct V_3 * V_4 ,
T_2 V_86 )
{
switch ( V_4 -> type ) {
case V_18 :
if ( ! V_4 -> V_34 )
return F_41 ( V_25 , V_4 ,
V_86 ) ;
else
return F_43 ( V_25 , V_4 ,
V_86 ) ;
break;
case V_19 :
if ( ! V_4 -> V_34 )
return F_64 ( V_25 , V_4 , V_86 ) ;
else
return F_65 ( V_25 , V_4 , V_86 ) ;
break;
case V_96 :
return F_44 ( V_25 , V_4 , V_86 ) ;
case V_27 :
return F_47 ( V_25 , V_4 , V_86 ) ;
case V_33 :
return F_45 ( V_25 , V_4 , V_86 ) ;
default:
break;
}
return - V_240 ;
}
int F_67 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_31 ;
if ( F_68 ( V_8 -> V_241 , L_8 ,
V_4 -> V_101 , F_69 ( V_4 ) ) )
return - V_40 ;
V_31 = F_66 ( V_25 , V_4 , V_167 ) ;
if ( V_31 )
return V_31 ;
F_70 ( V_25 , V_4 ) ;
V_8 -> V_241 = true ;
return 0 ;
}
int F_71 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_68 ( ! V_8 -> V_241 , L_9 ,
V_4 -> V_101 , F_69 ( V_4 ) ) )
return - V_40 ;
return F_66 ( V_25 , V_4 , V_242 ) ;
}
int F_72 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_84 V_85 ;
int V_31 ;
if ( F_68 ( ! V_8 -> V_241 , L_10 ,
V_4 -> V_101 , F_69 ( V_4 ) ) )
return - V_40 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_91 = F_25 ( F_26 ( V_8 -> V_16 ,
V_8 -> V_42 ) ) ;
V_85 . V_86 = F_25 ( V_243 ) ;
V_31 = F_34 ( V_25 , V_142 , V_143 ,
sizeof( V_85 ) , & V_85 ) ;
if ( V_31 ) {
F_12 ( V_25 , L_11 , V_31 ) ;
return V_31 ;
}
V_8 -> V_241 = false ;
if ( V_4 -> type == V_96 )
V_25 -> V_35 -> V_179 &= ~ V_180 ;
return 0 ;
}
int F_73 ( struct V_24 * V_25 ,
struct V_244 * V_245 ,
struct V_246 * V_85 )
{
struct V_247 * V_248 = F_74 ( V_245 ) ;
struct V_249 * V_190 = ( void * ) V_248 -> V_6 ;
V_211 V_38 V_250 =
F_75 ( V_190 -> V_251 . V_38 . V_38 ) ;
T_2 V_206 V_250 =
F_35 ( V_190 -> V_251 . V_252 ) ;
F_76 ( V_25 , L_12 ,
V_38 & V_253 ,
V_190 -> V_251 . V_254 ,
F_39 ( V_190 -> V_255 ) ,
V_206 ) ;
return 0 ;
}
static void F_77 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
V_211 * V_16 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_16 == * V_16 )
F_78 ( V_4 ) ;
}
int F_79 ( struct V_24 * V_25 ,
struct V_244 * V_245 ,
struct V_246 * V_85 )
{
struct V_247 * V_248 = F_74 ( V_245 ) ;
struct V_256 * V_257 = ( void * ) V_248 -> V_6 ;
V_211 V_16 = ( V_211 ) F_35 ( V_257 -> V_258 ) ;
F_9 ( V_25 -> V_35 ,
V_259 ,
F_77 ,
& V_16 ) ;
return 0 ;
}
