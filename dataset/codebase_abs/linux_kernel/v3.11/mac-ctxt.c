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
F_7 ( V_30 ) |
F_7 (IWL_MVM_CMD_QUEUE)
} ,
. V_10 = false ,
} ;
T_2 V_9 ;
int V_31 , V_32 ;
if ( V_4 -> type != V_18 || V_4 -> V_33 )
F_4 ( 0 , V_6 . V_17 ) ;
F_9 (
V_25 -> V_34 , V_35 ,
F_1 , & V_6 ) ;
if ( V_6 . V_10 )
return 0 ;
F_10 ( F_5 ( V_36 , & V_25 -> V_37 ) ) ;
V_8 -> V_16 = F_11 ( V_6 . V_17 ,
V_29 ) ;
if ( V_8 -> V_16 == V_29 ) {
F_12 ( V_25 , L_1 ) ;
V_31 = - V_38 ;
goto V_39;
}
if ( V_6 . V_20 != V_21 )
V_8 -> V_22 = V_6 . V_20 ;
else
V_8 -> V_22 = F_11 ( V_6 . V_23 ,
V_21 ) ;
if ( V_8 -> V_22 == V_21 ) {
F_12 ( V_25 , L_2 ) ;
V_31 = - V_38 ;
goto V_39;
}
V_8 -> V_40 = 0 ;
F_13 ( & V_8 -> V_41 . V_42 ) ;
V_8 -> V_41 . V_16 = V_43 ;
if ( V_4 -> type == V_27 ) {
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
V_4 -> V_12 [ V_9 ] = V_13 ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
T_1 V_44 = F_14 ( V_6 . V_14 ,
V_45 ) ;
if ( V_44 >= V_45 ) {
F_12 ( V_25 , L_3 ) ;
V_31 = - V_38 ;
goto V_39;
}
F_3 ( V_44 , V_6 . V_14 ) ;
V_4 -> V_12 [ V_9 ] = V_44 ;
}
if ( V_4 -> type == V_19 ) {
T_1 V_44 = F_14 ( V_6 . V_14 ,
V_45 ) ;
if ( V_44 >= V_45 ) {
F_12 ( V_25 , L_4 ) ;
V_31 = - V_38 ;
goto V_39;
}
V_4 -> V_15 = V_44 ;
} else {
V_4 -> V_15 = V_13 ;
}
V_8 -> V_46 . V_47 = V_48 ;
V_8 -> V_49 = V_48 ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ )
V_8 -> V_51 [ V_32 ] = V_52 ;
return 0 ;
V_39:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_12 , V_13 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_15 = V_13 ;
return V_31 ;
}
int F_15 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
T_2 V_9 ;
int V_31 ;
F_16 ( & V_25 -> V_53 ) ;
V_31 = F_8 ( V_25 , V_4 ) ;
if ( V_31 )
return V_31 ;
switch ( V_4 -> type ) {
case V_27 :
F_17 ( V_25 -> V_54 , V_28 ,
V_55 ) ;
break;
case V_19 :
F_17 ( V_25 -> V_54 , V_4 -> V_15 ,
V_56 ) ;
default:
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_17 ( V_25 -> V_54 , V_4 -> V_12 [ V_9 ] ,
V_57 [ V_9 ] ) ;
break;
}
return 0 ;
}
void F_18 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
int V_9 ;
F_16 ( & V_25 -> V_53 ) ;
switch ( V_4 -> type ) {
case V_27 :
F_19 ( V_25 -> V_54 , V_28 ) ;
break;
case V_19 :
F_19 ( V_25 -> V_54 , V_4 -> V_15 ) ;
default:
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ )
F_19 ( V_25 -> V_54 , V_4 -> V_12 [ V_9 ] ) ;
}
}
static void F_20 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
enum V_58 V_59 ,
T_1 * V_60 , T_1 * V_61 )
{
struct V_62 * V_63 ;
unsigned long V_64 = V_4 -> V_65 . V_66 ;
int V_67 = 100 ;
int V_68 = 100 ;
T_1 V_69 = 0 ;
T_1 V_70 = 0 ;
int V_32 ;
V_63 = V_25 -> V_34 -> V_71 -> V_72 [ V_59 ] ;
F_21 (i, &basic, BITS_PER_LONG) {
int V_34 = V_63 -> V_73 [ V_32 ] . V_74 ;
if ( V_34 >= V_75 ) {
V_70 |= F_7 ( V_34 - V_75 ) ;
if ( V_67 > V_34 )
V_67 = V_34 ;
} else {
F_22 ( V_76 != 0 ) ;
V_69 |= F_7 ( V_34 ) ;
if ( V_68 > V_34 )
V_68 = V_34 ;
}
}
if ( V_77 < V_67 )
V_70 |= F_23 ( 24 ) >> V_75 ;
if ( V_78 < V_67 )
V_70 |= F_23 ( 12 ) >> V_75 ;
V_70 |= F_23 ( 6 ) >> V_75 ;
if ( V_79 < V_68 )
V_69 |= F_23 ( 11 ) >> V_76 ;
if ( V_80 < V_68 )
V_69 |= F_23 ( 5 ) >> V_76 ;
if ( V_81 < V_68 )
V_69 |= F_23 ( 2 ) >> V_76 ;
V_69 |= F_23 ( 1 ) >> V_76 ;
* V_60 = V_69 ;
* V_61 = V_70 ;
}
static void F_24 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_82 * V_83 ,
T_2 V_84 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_85 * V_86 ;
T_1 V_87 , V_88 ;
int V_32 ;
V_83 -> V_89 = F_25 ( F_26 ( V_8 -> V_16 ,
V_8 -> V_40 ) ) ;
V_83 -> V_84 = F_25 ( V_84 ) ;
switch ( V_4 -> type ) {
case V_18 :
if ( V_4 -> V_33 )
V_83 -> V_90 = F_25 ( V_91 ) ;
else
V_83 -> V_90 = F_25 ( V_92 ) ;
break;
case V_19 :
V_83 -> V_90 = F_25 ( V_93 ) ;
break;
case V_94 :
V_83 -> V_90 = F_25 ( V_95 ) ;
break;
case V_27 :
V_83 -> V_90 = F_25 ( V_96 ) ;
break;
case V_97 :
V_83 -> V_90 = F_25 ( V_98 ) ;
break;
default:
F_10 ( 1 ) ;
}
V_83 -> V_22 = F_25 ( V_8 -> V_22 ) ;
memcpy ( V_83 -> V_99 , V_4 -> V_100 , V_101 ) ;
if ( V_4 -> V_65 . V_102 )
memcpy ( V_83 -> V_103 , V_4 -> V_65 . V_102 , V_101 ) ;
else
F_27 ( V_83 -> V_103 ) ;
F_28 () ;
V_86 = F_29 ( V_4 -> V_104 ) ;
F_20 ( V_25 , V_4 , V_86 ? V_86 -> V_105 . V_106 -> V_59
: V_107 ,
& V_87 , & V_88 ) ;
F_30 () ;
V_83 -> V_60 = F_25 ( ( T_2 ) V_87 ) ;
V_83 -> V_61 = F_25 ( ( T_2 ) V_88 ) ;
V_83 -> V_108 =
F_25 ( V_4 -> V_65 . V_109 ?
V_110 : 0 ) ;
V_83 -> V_111 =
F_25 ( V_4 -> V_65 . V_112 ?
V_113 : 0 ) ;
for ( V_32 = 0 ; V_32 < V_114 ; V_32 ++ ) {
V_83 -> V_9 [ V_32 ] . V_115 = F_31 ( V_8 -> V_116 [ V_32 ] . V_115 ) ;
V_83 -> V_9 [ V_32 ] . V_117 = F_31 ( V_8 -> V_116 [ V_32 ] . V_117 ) ;
V_83 -> V_9 [ V_32 ] . V_118 = V_8 -> V_116 [ V_32 ] . V_119 ;
V_83 -> V_9 [ V_32 ] . V_120 =
F_31 ( V_8 -> V_116 [ V_32 ] . V_121 * 32 ) ;
V_83 -> V_9 [ V_32 ] . V_122 = F_7 ( V_57 [ V_32 ] ) ;
}
if ( V_4 -> type == V_19 )
V_83 -> V_9 [ V_123 ] . V_122 |= F_7 ( V_56 ) ;
if ( V_4 -> V_65 . V_124 )
V_83 -> V_125 |= F_25 ( V_126 ) ;
if ( V_4 -> V_65 . V_127 )
V_83 -> V_128 |= F_25 ( V_129 ) ;
if ( V_4 -> V_65 . V_130 . V_131 != V_132 ) {
V_83 -> V_125 |= F_25 ( V_133 ) ;
V_83 -> V_128 |= F_25 ( V_134 |
V_135 ) ;
}
V_83 -> V_136 = F_25 ( V_137 ) ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_82 * V_83 )
{
int V_31 = F_33 ( V_25 , V_138 , V_139 ,
sizeof( * V_83 ) , V_83 ) ;
if ( V_31 )
F_12 ( V_25 , L_5 ,
F_34 ( V_83 -> V_84 ) , V_31 ) ;
return V_31 ;
}
static void F_35 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_140 * V_141 ,
bool V_142 )
{
if ( V_4 -> V_65 . V_143 && V_4 -> V_65 . V_144 &&
! V_142 ) {
T_2 V_145 ;
V_145 = V_4 -> V_65 . V_146 *
V_4 -> V_65 . V_147 ;
V_145 *= 1024 ;
V_141 -> V_148 =
F_36 ( V_4 -> V_65 . V_149 + V_145 ) ;
V_141 -> V_150 =
F_25 ( V_4 -> V_65 . V_151 + V_145 ) ;
F_37 ( V_25 , L_6 ,
F_38 ( V_141 -> V_148 ) ,
F_34 ( V_141 -> V_150 ) ,
V_145 ) ;
V_141 -> V_152 = F_25 ( 1 ) ;
} else {
V_141 -> V_152 = F_25 ( 0 ) ;
}
V_141 -> V_153 = F_25 ( V_4 -> V_65 . V_147 ) ;
V_141 -> V_154 =
F_25 ( F_39 ( V_4 -> V_65 . V_147 ) ) ;
V_141 -> V_155 = F_25 ( V_4 -> V_65 . V_147 *
V_4 -> V_65 . V_144 ) ;
V_141 -> V_156 =
F_25 ( F_39 ( V_4 -> V_65 . V_147 *
V_4 -> V_65 . V_144 ) ) ;
V_141 -> V_157 = F_25 ( V_25 -> V_34 -> V_158 . V_157 ) ;
V_141 -> V_159 = F_25 ( V_4 -> V_65 . V_160 ) ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_84 )
{
struct V_82 V_83 = {} ;
F_41 ( V_4 -> type != V_18 || V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_83 , V_84 ) ;
if ( ! V_4 -> V_65 . V_143 || ! V_4 -> V_65 . V_144 )
V_83 . V_136 |= F_25 ( V_161 ) ;
else
V_83 . V_136 &= ~ F_25 ( V_161 ) ;
F_35 ( V_25 , V_4 , & V_83 . V_162 ,
V_84 == V_163 ) ;
return F_32 ( V_25 , & V_83 ) ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_84 )
{
struct V_82 V_83 = {} ;
struct V_164 * V_165 = & V_4 -> V_65 . V_166 ;
F_41 ( V_4 -> type != V_18 || ! V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_83 , V_84 ) ;
F_35 ( V_25 , V_4 , & V_83 . V_167 . V_162 ,
V_84 == V_163 ) ;
V_83 . V_167 . V_168 = F_25 ( V_165 -> V_169 &
V_170 ) ;
return F_32 ( V_25 , & V_83 ) ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_84 )
{
struct V_82 V_83 = {} ;
F_41 ( V_4 -> type != V_94 ) ;
F_24 ( V_25 , V_4 , & V_83 , V_84 ) ;
V_83 . V_136 = F_25 ( V_171 |
V_172 |
V_161 |
V_173 ) ;
return F_32 ( V_25 , & V_83 ) ;
}
static void F_44 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_174 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_19 && V_4 -> V_33 && V_8 -> V_175 )
V_6 -> V_176 = true ;
}
static int F_45 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_84 )
{
struct V_82 V_83 = {} ;
struct V_174 V_6 = {} ;
F_41 ( V_4 -> type != V_27 ) ;
F_24 ( V_25 , V_4 , & V_83 , V_84 ) ;
V_83 . V_128 |= F_25 ( V_129 ) ;
V_83 . V_136 = F_25 ( V_173 ) ;
F_9 (
V_25 -> V_34 , V_35 ,
F_44 , & V_6 ) ;
V_83 . V_177 . V_178 = F_25 ( V_6 . V_176 ? 1 : 0 ) ;
return F_32 ( V_25 , & V_83 ) ;
}
static void F_46 ( struct V_24 * V_25 ,
struct V_179 * V_180 ,
T_1 * V_181 , T_2 V_182 )
{
T_2 V_183 ;
struct V_184 * V_185 = (struct V_184 * ) V_181 ;
V_183 = V_185 -> V_186 . V_181 . V_187 - V_181 ;
while ( ( V_183 < ( V_182 - 2 ) ) &&
( V_181 [ V_183 ] != V_188 ) )
V_183 += V_181 [ V_183 + 1 ] + 2 ;
if ( ( V_183 < ( V_182 - 1 ) ) && ( V_181 [ V_183 ] == V_188 ) ) {
V_180 -> V_183 = F_25 ( V_183 ) ;
V_180 -> V_189 = F_25 ( ( T_2 ) V_181 [ V_183 + 1 ] ) ;
} else {
F_47 ( V_25 , L_7 ) ;
}
}
static int F_48 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_190 * V_181 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_191 V_83 = {
. V_16 = V_192 ,
. V_193 = V_194 ,
} ;
struct V_179 V_180 = {} ;
struct V_195 * V_196 ;
T_2 V_197 ;
T_2 V_198 ;
if ( F_41 ( ! V_181 ) )
return - V_199 ;
V_197 = V_181 -> V_200 ;
V_180 . V_201 = F_25 ( ( T_2 ) V_8 -> V_16 ) ;
V_180 . V_202 . V_200 = F_31 ( ( V_203 ) V_197 ) ;
V_180 . V_202 . V_47 = V_8 -> V_46 . V_47 ;
V_180 . V_202 . V_204 = F_25 ( V_205 ) ;
V_180 . V_202 . V_206 = F_25 ( V_207 |
V_208 |
V_209 ) ;
V_25 -> V_210 =
F_49 ( V_25 , F_50 ( V_25 -> V_211 ) ,
V_25 -> V_210 ) ;
V_180 . V_202 . V_212 =
F_25 ( F_7 ( V_25 -> V_210 ) <<
V_213 ) ;
V_196 = F_51 ( V_181 ) ;
if ( V_196 -> V_59 == V_214 || V_4 -> V_33 ) {
V_198 = V_75 ;
} else {
V_198 = V_76 ;
V_180 . V_202 . V_212 |= F_25 ( V_215 ) ;
}
V_180 . V_202 . V_212 |=
F_25 ( F_52 ( V_198 ) ) ;
F_46 ( V_25 , & V_180 ,
V_181 -> V_6 ,
V_197 ) ;
V_83 . V_200 [ 0 ] = sizeof( V_180 ) ;
V_83 . V_6 [ 0 ] = & V_180 ;
V_83 . V_216 [ 0 ] = 0 ;
V_83 . V_200 [ 1 ] = V_197 ;
V_83 . V_6 [ 1 ] = V_181 -> V_6 ;
V_83 . V_216 [ 1 ] = V_217 ;
return F_53 ( V_25 , & V_83 ) ;
}
int F_54 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
struct V_190 * V_181 ;
int V_31 ;
F_41 ( V_4 -> type != V_19 ) ;
V_181 = F_55 ( V_25 -> V_34 , V_4 ) ;
if ( ! V_181 )
return - V_218 ;
V_31 = F_48 ( V_25 , V_4 , V_181 ) ;
F_56 ( V_181 ) ;
return V_31 ;
}
static void F_57 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_219 * V_6 = V_1 ;
if ( V_4 -> type != V_18 || ! V_4 -> V_65 . V_143 )
return;
if ( V_4 -> V_33 && V_6 -> V_220 )
return;
V_6 -> V_220 = V_4 -> V_65 . V_151 ;
V_6 -> V_147 = V_4 -> V_65 . V_147 ;
}
static void F_58 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_221 * V_222 ,
bool V_223 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_219 V_6 = {
. V_25 = V_25 ,
. V_4 = V_4 ,
. V_220 = 0
} ;
V_222 -> V_153 = F_25 ( V_4 -> V_65 . V_147 ) ;
V_222 -> V_154 =
F_25 ( F_39 ( V_4 -> V_65 . V_147 ) ) ;
V_222 -> V_155 = F_25 ( V_4 -> V_65 . V_147 *
V_4 -> V_65 . V_144 ) ;
V_222 -> V_156 =
F_25 ( F_39 ( V_4 -> V_65 . V_147 *
V_4 -> V_65 . V_144 ) ) ;
V_222 -> V_224 = F_25 ( V_4 -> V_15 ) ;
if ( V_223 ) {
F_9 (
V_25 -> V_34 , V_35 ,
F_57 , & V_6 ) ;
if ( V_6 . V_220 ) {
T_2 rand = ( F_59 () % ( 80 - 20 ) ) + 20 ;
V_8 -> V_225 = V_6 . V_220 +
F_60 ( V_6 . V_147 * rand /
100 ) ;
} else {
V_8 -> V_225 =
F_61 ( V_25 -> V_54 ,
V_226 ) ;
}
}
V_222 -> V_227 = F_25 ( V_8 -> V_225 ) ;
V_222 -> V_228 = 0 ;
V_222 -> V_229 = F_25 ( V_8 -> V_16 ) ;
}
static int F_62 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_84 )
{
struct V_82 V_83 = {} ;
F_41 ( V_4 -> type != V_19 || V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_83 , V_84 ) ;
V_83 . V_136 |= F_25 ( V_173 ) ;
F_58 ( V_25 , V_4 , & V_83 . V_230 ,
V_84 == V_163 ) ;
return F_32 ( V_25 , & V_83 ) ;
}
static int F_63 ( struct V_24 * V_25 ,
struct V_3 * V_4 ,
T_2 V_84 )
{
struct V_82 V_83 = {} ;
struct V_164 * V_165 = & V_4 -> V_65 . V_166 ;
F_41 ( V_4 -> type != V_19 || ! V_4 -> V_33 ) ;
F_24 ( V_25 , V_4 , & V_83 , V_84 ) ;
F_58 ( V_25 , V_4 , & V_83 . V_231 . V_230 ,
V_84 == V_163 ) ;
V_83 . V_231 . V_168 = F_25 ( V_165 -> V_169 &
V_170 ) ;
V_83 . V_231 . V_232 =
F_25 ( ! ! ( V_165 -> V_169 &
V_233 ) ) ;
return F_32 ( V_25 , & V_83 ) ;
}
static int F_64 ( struct V_24 * V_25 , struct V_3 * V_4 ,
T_2 V_84 )
{
switch ( V_4 -> type ) {
case V_18 :
if ( ! V_4 -> V_33 )
return F_40 ( V_25 , V_4 ,
V_84 ) ;
else
return F_42 ( V_25 , V_4 ,
V_84 ) ;
break;
case V_19 :
if ( ! V_4 -> V_33 )
return F_62 ( V_25 , V_4 , V_84 ) ;
else
return F_63 ( V_25 , V_4 , V_84 ) ;
break;
case V_94 :
return F_43 ( V_25 , V_4 , V_84 ) ;
case V_27 :
return F_45 ( V_25 , V_4 , V_84 ) ;
default:
break;
}
return - V_234 ;
}
int F_65 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_31 ;
if ( F_66 ( V_8 -> V_235 , L_8 ,
V_4 -> V_100 , F_67 ( V_4 ) ) )
return - V_38 ;
V_31 = F_64 ( V_25 , V_4 , V_163 ) ;
if ( V_31 )
return V_31 ;
V_8 -> V_235 = true ;
return 0 ;
}
int F_68 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_66 ( ! V_8 -> V_235 , L_9 ,
V_4 -> V_100 , F_67 ( V_4 ) ) )
return - V_38 ;
return F_64 ( V_25 , V_4 , V_236 ) ;
}
int F_69 ( struct V_24 * V_25 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_82 V_83 ;
int V_31 ;
if ( F_66 ( ! V_8 -> V_235 , L_10 ,
V_4 -> V_100 , F_67 ( V_4 ) ) )
return - V_38 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_89 = F_25 ( F_26 ( V_8 -> V_16 ,
V_8 -> V_40 ) ) ;
V_83 . V_84 = F_25 ( V_237 ) ;
V_31 = F_33 ( V_25 , V_138 , V_139 ,
sizeof( V_83 ) , & V_83 ) ;
if ( V_31 ) {
F_12 ( V_25 , L_11 , V_31 ) ;
return V_31 ;
}
V_8 -> V_235 = false ;
return 0 ;
}
int F_70 ( struct V_24 * V_25 ,
struct V_238 * V_239 ,
struct V_240 * V_83 )
{
struct V_241 * V_242 = F_71 ( V_239 ) ;
struct V_243 * V_181 = ( void * ) V_242 -> V_6 ;
V_203 V_37 V_244 =
F_72 ( V_181 -> V_245 . V_37 . V_37 ) ;
T_2 V_198 V_244 =
F_34 ( V_181 -> V_245 . V_246 ) ;
F_73 ( V_25 , L_12 ,
V_37 & V_247 ,
V_181 -> V_245 . V_248 ,
F_38 ( V_181 -> V_249 ) ,
V_198 ) ;
return 0 ;
}
static void F_74 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
V_203 * V_16 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_16 == * V_16 )
F_75 ( V_4 ) ;
}
int F_76 ( struct V_24 * V_25 ,
struct V_238 * V_239 ,
struct V_240 * V_83 )
{
struct V_241 * V_242 = F_71 ( V_239 ) ;
struct V_250 * V_251 = ( void * ) V_242 -> V_6 ;
V_203 V_16 = ( V_203 ) F_34 ( V_251 -> V_252 ) ;
F_9 ( V_25 -> V_34 ,
V_253 ,
F_74 ,
& V_16 ) ;
return 0 ;
}
