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
static void F_6 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_3 V_18 ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_19 = true ;
return;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
if ( V_4 -> V_21 [ V_18 ] != V_22 )
F_7 ( V_4 -> V_21 [ V_18 ] , V_6 -> V_23 ) ;
if ( V_4 -> V_24 != V_22 )
F_7 ( V_4 -> V_24 , V_6 -> V_23 ) ;
F_5 ( V_8 -> V_25 , V_6 -> V_26 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
T_3 F_8 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
T_3 V_29 = 0 , V_18 ;
if ( V_4 -> type == V_30 )
return F_9 ( V_31 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
if ( V_4 -> V_21 [ V_18 ] != V_22 )
V_29 |= F_9 ( V_4 -> V_21 [ V_18 ] ) ;
return V_29 ;
}
void F_10 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_28 = V_28 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_11 (
V_28 -> V_32 , V_33 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_12 ( V_6 . V_15 ,
V_13 ) ;
}
static int F_13 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_28 = V_28 ,
. V_4 = V_4 ,
. V_26 = { ( 1 << V_34 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_23 = {
F_9 ( V_31 ) |
F_9 ( V_28 -> V_35 ) |
F_9 (IWL_MVM_CMD_QUEUE)
} ,
. V_19 = false ,
} ;
T_3 V_18 ;
int V_36 , V_37 ;
switch ( V_4 -> type ) {
case V_38 :
break;
case V_10 :
if ( ! V_4 -> V_39 )
break;
default:
F_5 ( 0 , V_6 . V_26 ) ;
}
F_11 (
V_28 -> V_32 , V_33 ,
F_6 , & V_6 ) ;
if ( V_6 . V_19 )
return 0 ;
if ( F_14 ( F_3 ( V_40 , & V_28 -> V_41 ) ) )
return - V_42 ;
V_8 -> V_25 = F_12 ( V_6 . V_26 ,
V_34 ) ;
if ( V_8 -> V_25 == V_34 ) {
F_15 ( V_28 , L_1 ) ;
V_36 = - V_43 ;
goto V_44;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_12 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_15 ( V_28 , L_2 ) ;
V_36 = - V_43 ;
goto V_44;
}
V_8 -> V_45 = 0 ;
F_16 ( & V_8 -> V_46 . V_47 ) ;
V_8 -> V_46 . V_25 = V_48 ;
if ( V_4 -> type == V_30 ) {
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
V_4 -> V_21 [ V_18 ] = V_22 ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
T_1 V_49 = F_17 ( V_6 . V_23 ,
V_28 -> V_50 ) ;
if ( V_49 >= V_28 -> V_50 ) {
F_15 ( V_28 , L_3 ) ;
V_36 = - V_43 ;
goto V_44;
}
F_7 ( V_49 , V_6 . V_23 ) ;
V_4 -> V_21 [ V_18 ] = V_49 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_49 = F_17 ( V_6 . V_23 ,
V_28 -> V_50 ) ;
if ( V_49 >= V_28 -> V_50 ) {
F_15 ( V_28 , L_4 ) ;
V_36 = - V_43 ;
goto V_44;
}
V_4 -> V_24 = V_49 ;
} else {
V_4 -> V_24 = V_22 ;
}
V_8 -> V_51 . V_52 = V_53 ;
V_8 -> V_54 = V_53 ;
for ( V_37 = 0 ; V_37 < V_55 ; V_37 ++ )
V_8 -> V_56 [ V_37 ] = V_57 ;
return 0 ;
V_44:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_21 , V_22 , sizeof( V_4 -> V_21 ) ) ;
V_4 -> V_24 = V_22 ;
return V_36 ;
}
int F_18 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
T_3 V_18 ;
int V_36 ;
F_19 ( & V_28 -> V_58 ) ;
V_36 = F_13 ( V_28 , V_4 ) ;
if ( V_36 )
return V_36 ;
switch ( V_4 -> type ) {
case V_30 :
F_20 ( V_28 -> V_59 , V_31 ,
V_60 ) ;
break;
case V_11 :
F_20 ( V_28 -> V_59 , V_4 -> V_24 ,
V_61 ) ;
default:
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
F_20 ( V_28 -> V_59 , V_4 -> V_21 [ V_18 ] ,
V_62 [ V_18 ] ) ;
break;
}
return 0 ;
}
void F_21 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
int V_18 ;
F_19 ( & V_28 -> V_58 ) ;
switch ( V_4 -> type ) {
case V_30 :
F_22 ( V_28 -> V_59 , V_31 ) ;
break;
case V_11 :
F_22 ( V_28 -> V_59 , V_4 -> V_24 ) ;
default:
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
F_22 ( V_28 -> V_59 , V_4 -> V_21 [ V_18 ] ) ;
}
}
static void F_23 ( struct V_27 * V_28 ,
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
V_68 = V_28 -> V_32 -> V_75 -> V_76 [ V_64 ] ;
F_24 (i, &basic, BITS_PER_LONG) {
int V_32 = V_68 -> V_77 [ V_37 ] . V_78 ;
if ( V_32 >= V_79 ) {
V_74 |= F_9 ( V_32 - V_79 ) ;
if ( V_71 > V_32 )
V_71 = V_32 ;
} else {
F_25 ( V_80 != 0 ) ;
V_73 |= F_9 ( V_32 ) ;
if ( V_72 > V_32 )
V_72 = V_32 ;
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
static void F_27 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_86 * V_87 )
{
T_1 V_88 = V_4 -> V_16 . V_89 &
V_90 ;
T_3 V_91 = V_92 | V_93 ;
F_28 ( V_28 , L_5 , V_88 ) ;
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
F_15 ( V_28 , L_6 ,
V_88 ) ;
break;
}
}
static void F_30 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_86 * V_87 ,
T_3 V_102 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_103 * V_104 ;
bool V_105 = ! ! ( V_4 -> V_16 . V_89 &
V_90 ) ;
T_1 V_106 , V_107 ;
int V_37 ;
V_87 -> V_108 = F_29 ( F_31 ( V_8 -> V_25 ,
V_8 -> V_45 ) ) ;
V_87 -> V_102 = F_29 ( V_102 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_39 )
V_87 -> V_109 = F_29 ( V_110 ) ;
else
V_87 -> V_109 = F_29 ( V_111 ) ;
break;
case V_11 :
V_87 -> V_109 = F_29 ( V_112 ) ;
break;
case V_113 :
V_87 -> V_109 = F_29 ( V_114 ) ;
break;
case V_30 :
V_87 -> V_109 = F_29 ( V_115 ) ;
break;
case V_38 :
V_87 -> V_109 = F_29 ( V_116 ) ;
break;
default:
F_14 ( 1 ) ;
}
V_87 -> V_14 = F_29 ( V_8 -> V_14 ) ;
memcpy ( V_87 -> V_117 , V_4 -> V_118 , V_119 ) ;
if ( V_4 -> V_16 . V_120 )
memcpy ( V_87 -> V_121 , V_4 -> V_16 . V_120 , V_119 ) ;
else
F_32 ( V_87 -> V_121 ) ;
F_33 () ;
V_104 = F_34 ( V_4 -> V_122 ) ;
F_23 ( V_28 , V_4 , V_104 ? V_104 -> V_123 . V_124 -> V_64
: V_125 ,
& V_106 , & V_107 ) ;
F_35 () ;
V_87 -> V_65 = F_29 ( ( T_3 ) V_106 ) ;
V_87 -> V_66 = F_29 ( ( T_3 ) V_107 ) ;
V_87 -> V_126 =
F_29 ( V_4 -> V_16 . V_127 ?
V_128 : 0 ) ;
V_87 -> V_129 =
F_29 ( V_4 -> V_16 . V_130 ?
V_131 : 0 ) ;
for ( V_37 = 0 ; V_37 < V_20 ; V_37 ++ ) {
T_1 V_132 = V_62 [ V_37 ] ;
V_87 -> V_18 [ V_132 ] . V_133 =
F_36 ( V_8 -> V_134 [ V_37 ] . V_133 ) ;
V_87 -> V_18 [ V_132 ] . V_135 =
F_36 ( V_8 -> V_134 [ V_37 ] . V_135 ) ;
V_87 -> V_18 [ V_132 ] . V_136 =
F_36 ( V_8 -> V_134 [ V_37 ] . V_137 * 32 ) ;
V_87 -> V_18 [ V_132 ] . V_138 = V_8 -> V_134 [ V_37 ] . V_139 ;
V_87 -> V_18 [ V_132 ] . V_140 = F_9 ( V_132 ) ;
}
if ( V_4 -> type == V_11 )
V_87 -> V_18 [ V_60 ] . V_140 |=
F_9 ( V_61 ) ;
if ( V_4 -> V_16 . V_141 )
V_87 -> V_142 |= F_29 ( V_143 ) ;
if ( V_4 -> V_16 . V_144 )
V_87 -> V_97 |= F_29 ( V_145 ) ;
F_28 ( V_28 , L_7 ,
V_4 -> V_16 . V_144 ,
V_4 -> V_16 . V_89 ) ;
if ( V_4 -> V_16 . V_99 . V_100 != V_146 )
V_87 -> V_142 |= F_29 ( V_147 ) ;
if ( V_105 )
F_27 ( V_28 , V_4 , V_87 ) ;
V_87 -> V_148 = F_29 ( V_149 ) ;
}
static int F_37 ( struct V_27 * V_28 ,
struct V_86 * V_87 )
{
int V_36 = F_38 ( V_28 , V_150 , 0 ,
sizeof( * V_87 ) , V_87 ) ;
if ( V_36 )
F_15 ( V_28 , L_8 ,
F_39 ( V_87 -> V_102 ) , V_36 ) ;
return V_36 ;
}
static int F_40 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 , bool V_151 )
{
struct V_86 V_87 = {} ;
struct V_152 * V_153 ;
F_41 ( V_4 -> type != V_10 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
if ( V_4 -> V_39 ) {
struct V_154 * V_155 =
& V_4 -> V_16 . V_156 ;
V_87 . V_157 . V_158 = F_29 ( V_155 -> V_159 &
V_160 ) ;
V_153 = & V_87 . V_157 . V_161 ;
} else {
V_153 = & V_87 . V_161 ;
}
if ( V_4 -> V_16 . V_162 && V_4 -> V_16 . V_163 &&
! V_151 ) {
T_3 V_164 ;
V_87 . V_148 |= F_29 ( V_165 ) ;
V_164 = V_4 -> V_16 . V_166 *
V_4 -> V_16 . V_17 ;
V_164 *= 1024 ;
V_153 -> V_167 =
F_42 ( V_4 -> V_16 . V_168 + V_164 ) ;
V_153 -> V_169 =
F_29 ( V_4 -> V_16 . V_170 + V_164 ) ;
F_43 ( V_28 , L_9 ,
F_44 ( V_153 -> V_167 ) ,
F_39 ( V_153 -> V_169 ) ,
V_164 ) ;
V_153 -> V_171 = F_29 ( 1 ) ;
} else {
V_153 -> V_171 = F_29 ( 0 ) ;
}
V_153 -> V_172 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_153 -> V_173 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_153 -> V_174 = F_29 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_163 ) ;
V_153 -> V_175 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_163 ) ) ;
V_153 -> V_176 = F_29 ( V_28 -> V_32 -> V_177 . V_176 ) ;
V_153 -> V_178 = F_29 ( V_4 -> V_16 . V_179 ) ;
return F_37 ( V_28 , & V_87 ) ;
}
static int F_46 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
F_41 ( V_4 -> type != V_113 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_148 = F_29 ( V_180 |
V_181 |
V_165 |
V_182 |
V_183 ) ;
V_28 -> V_32 -> V_184 |= V_185 ;
return F_37 ( V_28 , & V_87 ) ;
}
static int F_47 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_86 V_87 = {} ;
F_41 ( V_4 -> type != V_38 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_148 = F_29 ( V_165 |
V_182 ) ;
V_87 . V_186 . V_172 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_87 . V_186 . V_173 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_87 . V_186 . V_187 = F_29 ( V_8 -> V_25 ) ;
return F_37 ( V_28 , & V_87 ) ;
}
static void F_48 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_188 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_39 &&
V_8 -> V_189 )
V_6 -> V_190 = true ;
}
static int F_49 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
struct V_188 V_6 = {} ;
F_41 ( V_4 -> type != V_30 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_97 |= F_29 ( V_145 ) ;
V_87 . V_148 = F_29 ( V_182 ) ;
F_11 (
V_28 -> V_32 , V_33 ,
F_48 , & V_6 ) ;
V_87 . V_191 . V_192 = F_29 ( V_6 . V_190 ? 1 : 0 ) ;
return F_37 ( V_28 , & V_87 ) ;
}
static void F_50 ( struct V_27 * V_28 ,
struct V_193 * V_194 ,
T_1 * V_195 , T_3 V_196 )
{
T_3 V_197 ;
struct V_198 * V_199 = (struct V_198 * ) V_195 ;
V_197 = V_199 -> V_200 . V_195 . V_201 - V_195 ;
while ( ( V_197 < ( V_196 - 2 ) ) &&
( V_195 [ V_197 ] != V_202 ) )
V_197 += V_195 [ V_197 + 1 ] + 2 ;
if ( ( V_197 < ( V_196 - 1 ) ) && ( V_195 [ V_197 ] == V_202 ) ) {
V_194 -> V_197 = F_29 ( V_197 ) ;
V_194 -> V_203 = F_29 ( ( T_3 ) V_195 [ V_197 + 1 ] ) ;
} else {
F_51 ( V_28 , L_10 ) ;
}
}
static int F_52 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_204 * V_195 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_205 V_87 = {
. V_25 = V_206 ,
. V_184 = V_207 ,
} ;
struct V_193 V_194 = {} ;
struct V_208 * V_209 ;
T_3 V_210 ;
T_3 V_211 ;
if ( F_41 ( ! V_195 ) )
return - V_212 ;
V_210 = V_195 -> V_213 ;
V_194 . V_214 = F_29 ( ( T_3 ) V_8 -> V_25 ) ;
V_194 . V_215 . V_213 = F_36 ( ( T_2 ) V_210 ) ;
V_194 . V_215 . V_52 = V_8 -> V_51 . V_52 ;
V_194 . V_215 . V_216 = F_29 ( V_217 ) ;
V_194 . V_215 . V_218 = F_29 ( V_219 |
V_220 |
V_221 ) ;
V_28 -> V_222 =
F_53 ( V_28 , V_28 -> V_223 -> V_224 ,
V_28 -> V_222 ) ;
V_194 . V_215 . V_225 =
F_29 ( F_9 ( V_28 -> V_222 ) <<
V_226 ) ;
V_209 = F_54 ( V_195 ) ;
if ( V_209 -> V_64 == V_227 || V_4 -> V_39 ) {
V_211 = V_79 ;
} else {
V_211 = V_80 ;
V_194 . V_215 . V_225 |= F_29 ( V_228 ) ;
}
V_194 . V_215 . V_225 |=
F_29 ( F_55 ( V_211 ) ) ;
if ( V_4 -> type == V_11 )
F_50 ( V_28 , & V_194 ,
V_195 -> V_6 ,
V_210 ) ;
V_87 . V_213 [ 0 ] = sizeof( V_194 ) ;
V_87 . V_6 [ 0 ] = & V_194 ;
V_87 . V_229 [ 0 ] = 0 ;
V_87 . V_213 [ 1 ] = V_210 ;
V_87 . V_6 [ 1 ] = V_195 -> V_6 ;
V_87 . V_229 [ 1 ] = V_230 ;
return F_56 ( V_28 , & V_87 ) ;
}
int F_57 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
struct V_204 * V_195 ;
int V_36 ;
F_41 ( V_4 -> type != V_11 &&
V_4 -> type != V_38 ) ;
V_195 = F_58 ( V_28 -> V_32 , V_4 ) ;
if ( ! V_195 )
return - V_231 ;
V_36 = F_52 ( V_28 , V_4 , V_195 ) ;
F_59 ( V_195 ) ;
return V_36 ;
}
static void F_60 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_232 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_162 )
return;
if ( V_4 -> V_39 && V_6 -> V_233 )
return;
V_6 -> V_233 = V_4 -> V_16 . V_170 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_61 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_234 * V_235 ,
bool V_236 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_232 V_6 = {
. V_28 = V_28 ,
. V_4 = V_4 ,
. V_233 = 0
} ;
V_235 -> V_172 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_235 -> V_173 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_235 -> V_174 = F_29 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_163 ) ;
V_235 -> V_175 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_163 ) ) ;
V_235 -> V_237 = F_29 ( V_4 -> V_24 ) ;
if ( V_236 ) {
F_11 (
V_28 -> V_32 , V_33 ,
F_60 , & V_6 ) ;
if ( V_6 . V_233 ) {
T_3 rand = ( F_62 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_238 = V_6 . V_233 +
F_63 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_238 =
F_64 ( V_28 -> V_59 ,
V_239 ) ;
}
}
V_235 -> V_240 = F_29 ( V_8 -> V_238 ) ;
V_235 -> V_241 = 0 ;
V_235 -> V_187 = F_29 ( V_8 -> V_25 ) ;
}
static int F_65 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
F_41 ( V_4 -> type != V_11 || V_4 -> V_39 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_148 |= F_29 ( V_182 |
V_165 ) ;
F_61 ( V_28 , V_4 , & V_87 . V_242 ,
V_102 == V_243 ) ;
return F_37 ( V_28 , & V_87 ) ;
}
static int F_66 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
struct V_154 * V_155 = & V_4 -> V_16 . V_156 ;
F_41 ( V_4 -> type != V_11 || ! V_4 -> V_39 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_148 |= F_29 ( V_182 |
V_165 ) ;
F_61 ( V_28 , V_4 , & V_87 . V_244 . V_242 ,
V_102 == V_243 ) ;
V_87 . V_244 . V_158 = F_29 ( V_155 -> V_159 &
V_160 ) ;
V_87 . V_244 . V_245 =
F_29 ( ! ! ( V_155 -> V_159 &
V_246 ) ) ;
return F_37 ( V_28 , & V_87 ) ;
}
static int F_67 ( struct V_27 * V_28 , struct V_3 * V_4 ,
T_3 V_102 , bool V_151 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_40 ( V_28 , V_4 , V_102 ,
V_151 ) ;
break;
case V_11 :
if ( ! V_4 -> V_39 )
return F_65 ( V_28 , V_4 , V_102 ) ;
else
return F_66 ( V_28 , V_4 , V_102 ) ;
break;
case V_113 :
return F_46 ( V_28 , V_4 , V_102 ) ;
case V_30 :
return F_49 ( V_28 , V_4 , V_102 ) ;
case V_38 :
return F_47 ( V_28 , V_4 , V_102 ) ;
default:
break;
}
return - V_247 ;
}
int F_68 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_36 ;
if ( F_69 ( V_8 -> V_248 , L_11 ,
V_4 -> V_118 , F_70 ( V_4 ) ) )
return - V_43 ;
V_36 = F_67 ( V_28 , V_4 , V_243 ,
true ) ;
if ( V_36 )
return V_36 ;
F_71 ( V_28 , V_4 ) ;
V_8 -> V_248 = true ;
return 0 ;
}
int F_72 ( struct V_27 * V_28 , struct V_3 * V_4 ,
bool V_151 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_69 ( ! V_8 -> V_248 , L_12 ,
V_4 -> V_118 , F_70 ( V_4 ) ) )
return - V_43 ;
return F_67 ( V_28 , V_4 , V_249 ,
V_151 ) ;
}
int F_73 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_86 V_87 ;
int V_36 ;
if ( F_69 ( ! V_8 -> V_248 , L_13 ,
V_4 -> V_118 , F_70 ( V_4 ) ) )
return - V_43 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_108 = F_29 ( F_31 ( V_8 -> V_25 ,
V_8 -> V_45 ) ) ;
V_87 . V_102 = F_29 ( V_250 ) ;
V_36 = F_38 ( V_28 , V_150 , 0 ,
sizeof( V_87 ) , & V_87 ) ;
if ( V_36 ) {
F_15 ( V_28 , L_14 , V_36 ) ;
return V_36 ;
}
V_8 -> V_248 = false ;
if ( V_4 -> type == V_113 )
V_28 -> V_32 -> V_184 &= ~ V_185 ;
return 0 ;
}
int F_74 ( struct V_27 * V_28 ,
struct V_251 * V_252 ,
struct V_253 * V_87 )
{
struct V_254 * V_255 = F_75 ( V_252 ) ;
struct V_256 * V_195 = ( void * ) V_255 -> V_6 ;
T_2 V_41 V_257 =
F_76 ( V_195 -> V_258 . V_41 . V_41 ) ;
T_3 V_211 V_257 =
F_39 ( V_195 -> V_258 . V_259 ) ;
F_19 ( & V_28 -> V_58 ) ;
F_77 ( V_28 , L_15 ,
V_41 & V_260 ,
V_195 -> V_258 . V_261 ,
F_44 ( V_195 -> V_262 ) ,
V_211 ) ;
if ( F_78 ( V_28 -> V_263 && V_28 -> V_263 -> V_264 ) ) {
if ( ! F_79 ( V_28 -> V_263 ) ) {
F_57 ( V_28 , V_28 -> V_263 ) ;
} else {
F_80 ( V_28 -> V_263 ) ;
V_28 -> V_263 = NULL ;
}
}
return 0 ;
}
static void F_81 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_265 * V_266 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_25 != ( T_2 ) F_39 ( V_266 -> V_267 ) )
return;
if ( F_39 ( V_266 -> V_268 ) >
V_269 )
F_82 ( V_4 ) ;
}
int F_83 ( struct V_27 * V_28 ,
struct V_251 * V_252 ,
struct V_253 * V_87 )
{
struct V_254 * V_255 = F_75 ( V_252 ) ;
struct V_265 * V_270 = ( void * ) V_255 -> V_6 ;
F_43 ( V_28 ,
L_16 ,
F_39 ( V_270 -> V_267 ) ,
F_39 ( V_270 -> V_271 ) ,
F_39 ( V_270 -> V_268 ) ,
F_39 ( V_270 -> V_272 ) ,
F_39 ( V_270 -> V_273 ) ) ;
F_11 ( V_28 -> V_32 ,
V_274 ,
F_81 ,
V_270 ) ;
return 0 ;
}
