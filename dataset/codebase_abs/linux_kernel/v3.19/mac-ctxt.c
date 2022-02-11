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
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_18 |= F_7 ( V_4 -> V_23 [ V_19 ] ) ;
if ( V_4 -> type == V_11 )
V_18 |= F_7 ( V_4 -> V_24 ) ;
return V_18 ;
}
static void F_8 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_25 * V_6 = V_1 ;
if ( V_4 == V_6 -> V_26 )
return;
V_6 -> V_27 |= F_6 ( V_4 ) ;
}
static void F_9 ( void * V_1 ,
struct V_28 * V_29 )
{
struct V_25 * V_6 = V_1 ;
struct V_30 * V_31 = F_10 ( V_29 ) ;
V_6 -> V_27 |= V_31 -> V_32 ;
}
unsigned long F_11 ( struct V_33 * V_34 ,
struct V_3 * V_26 )
{
struct V_25 V_6 = {
. V_26 = V_26 ,
. V_27 =
F_7 ( V_21 ) |
F_7 ( V_34 -> V_35 ) |
F_7 ( V_36 ) ,
} ;
F_12 ( & V_34 -> V_37 ) ;
F_13 (
V_34 -> V_38 , V_39 ,
F_8 , & V_6 ) ;
F_14 ( V_34 -> V_38 ,
F_9 ,
& V_6 ) ;
return V_6 . V_27 ;
}
static void F_15 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_4 ) {
V_6 -> V_40 = true ;
return;
}
F_5 ( V_8 -> V_41 , V_6 -> V_42 ) ;
F_1 ( V_1 , V_2 , V_4 ) ;
}
void F_16 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_34 = V_34 ,
. V_4 = V_4 ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
} ;
F_13 (
V_34 -> V_38 , V_39 ,
F_1 , & V_6 ) ;
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else if ( ! F_3 ( V_8 -> V_14 , V_6 . V_15 ) )
V_8 -> V_14 = F_17 ( V_6 . V_15 ,
V_13 ) ;
}
static int F_18 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_5 V_6 = {
. V_34 = V_34 ,
. V_4 = V_4 ,
. V_42 = { ( 1 << V_43 ) - 1 } ,
. V_15 = { ( 1 << V_13 ) - 1 } ,
. V_12 = V_13 ,
. V_40 = false ,
} ;
T_3 V_19 ;
int V_44 , V_45 ;
unsigned long V_27 ;
switch ( V_4 -> type ) {
case V_46 :
break;
case V_10 :
if ( ! V_4 -> V_47 )
break;
default:
F_5 ( 0 , V_6 . V_42 ) ;
}
F_13 (
V_34 -> V_38 , V_39 ,
F_15 , & V_6 ) ;
V_27 = F_11 ( V_34 , V_4 ) ;
if ( V_6 . V_40 )
return 0 ;
if ( F_19 ( F_3 ( V_48 , & V_34 -> V_49 ) ) )
return - V_50 ;
V_8 -> V_41 = F_17 ( V_6 . V_42 ,
V_43 ) ;
if ( V_8 -> V_41 == V_43 ) {
F_20 ( V_34 , L_1 ) ;
V_44 = - V_51 ;
goto V_52;
}
if ( V_6 . V_12 != V_13 )
V_8 -> V_14 = V_6 . V_12 ;
else
V_8 -> V_14 = F_17 ( V_6 . V_15 ,
V_13 ) ;
if ( V_8 -> V_14 == V_13 ) {
F_20 ( V_34 , L_2 ) ;
V_44 = - V_51 ;
goto V_52;
}
V_8 -> V_53 = 0 ;
F_21 ( & V_8 -> V_54 . V_55 ) ;
V_8 -> V_54 . V_41 = V_56 ;
if ( V_4 -> type == V_20 ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
V_4 -> V_23 [ V_19 ] = V_57 ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
T_1 V_58 = F_22 ( & V_27 ,
V_34 -> V_59 ) ;
if ( V_58 >= V_34 -> V_59 ) {
F_20 ( V_34 , L_3 ) ;
V_44 = - V_51 ;
goto V_52;
}
F_23 ( V_58 , & V_27 ) ;
V_4 -> V_23 [ V_19 ] = V_58 ;
}
if ( V_4 -> type == V_11 ) {
T_1 V_58 = F_22 ( & V_27 ,
V_34 -> V_59 ) ;
if ( V_58 >= V_34 -> V_59 ) {
F_20 ( V_34 , L_4 ) ;
V_44 = - V_51 ;
goto V_52;
}
V_4 -> V_24 = V_58 ;
} else {
V_4 -> V_24 = V_57 ;
}
V_8 -> V_60 . V_61 = V_62 ;
V_8 -> V_63 = V_62 ;
for ( V_45 = 0 ; V_45 < V_64 ; V_45 ++ )
V_8 -> V_65 [ V_45 ] = V_66 ;
return 0 ;
V_52:
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
memset ( V_4 -> V_23 , V_57 , sizeof( V_4 -> V_23 ) ) ;
V_4 -> V_24 = V_57 ;
return V_44 ;
}
int F_24 ( struct V_33 * V_34 , struct V_3 * V_4 )
{
T_3 V_19 ;
int V_44 ;
F_12 ( & V_34 -> V_37 ) ;
V_44 = F_18 ( V_34 , V_4 ) ;
if ( V_44 )
return V_44 ;
switch ( V_4 -> type ) {
case V_20 :
F_25 ( V_34 , V_21 ,
V_67 ) ;
break;
case V_11 :
F_25 ( V_34 , V_4 -> V_24 ,
V_68 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_25 ( V_34 , V_4 -> V_23 [ V_19 ] ,
V_69 [ V_19 ] ) ;
break;
}
return 0 ;
}
void F_26 ( struct V_33 * V_34 , struct V_3 * V_4 )
{
int V_19 ;
F_12 ( & V_34 -> V_37 ) ;
switch ( V_4 -> type ) {
case V_20 :
F_27 ( V_34 , V_21 ) ;
break;
case V_11 :
F_27 ( V_34 , V_4 -> V_24 ) ;
default:
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
F_27 ( V_34 , V_4 -> V_23 [ V_19 ] ) ;
}
}
static void F_28 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
enum V_70 V_71 ,
T_1 * V_72 , T_1 * V_73 )
{
struct V_74 * V_75 ;
unsigned long V_76 = V_4 -> V_16 . V_77 ;
int V_78 = 100 ;
int V_79 = 100 ;
T_1 V_80 = 0 ;
T_1 V_81 = 0 ;
int V_45 ;
V_75 = V_34 -> V_38 -> V_82 -> V_83 [ V_71 ] ;
F_29 (i, &basic, BITS_PER_LONG) {
int V_38 = V_75 -> V_84 [ V_45 ] . V_85 ;
if ( V_38 >= V_86 ) {
V_81 |= F_7 ( V_38 - V_86 ) ;
if ( V_78 > V_38 )
V_78 = V_38 ;
} else {
F_30 ( V_87 != 0 ) ;
V_80 |= F_7 ( V_38 ) ;
if ( V_79 > V_38 )
V_79 = V_38 ;
}
}
if ( V_88 < V_78 )
V_81 |= F_31 ( 24 ) >> V_86 ;
if ( V_89 < V_78 )
V_81 |= F_31 ( 12 ) >> V_86 ;
V_81 |= F_31 ( 6 ) >> V_86 ;
if ( V_90 < V_79 )
V_80 |= F_31 ( 11 ) >> V_87 ;
if ( V_91 < V_79 )
V_80 |= F_31 ( 5 ) >> V_87 ;
if ( V_92 < V_79 )
V_80 |= F_31 ( 2 ) >> V_87 ;
V_80 |= F_31 ( 1 ) >> V_87 ;
* V_72 = V_80 ;
* V_73 = V_81 ;
}
static void F_32 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
struct V_93 * V_94 )
{
T_1 V_95 = V_4 -> V_16 . V_96 &
V_97 ;
T_3 V_98 = V_99 | V_100 ;
F_33 ( V_34 , L_5 , V_95 ) ;
switch ( V_95 ) {
case V_101 :
break;
case V_102 :
case V_103 :
V_94 -> V_104 |= F_34 ( V_98 ) ;
break;
case V_105 :
if ( V_4 -> V_16 . V_106 . V_107 > V_108 )
V_94 -> V_104 |= F_34 ( V_98 ) ;
break;
default:
F_20 ( V_34 , L_6 ,
V_95 ) ;
break;
}
}
static void F_35 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
struct V_93 * V_94 ,
const T_1 * V_109 ,
T_3 V_110 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_111 * V_112 ;
bool V_113 = ! ! ( V_4 -> V_16 . V_96 &
V_97 ) ;
T_1 V_114 , V_115 ;
const T_1 * V_116 = V_109 ? : V_4 -> V_16 . V_116 ;
int V_45 ;
V_94 -> V_117 = F_34 ( F_36 ( V_8 -> V_41 ,
V_8 -> V_53 ) ) ;
V_94 -> V_110 = F_34 ( V_110 ) ;
switch ( V_4 -> type ) {
case V_10 :
if ( V_4 -> V_47 )
V_94 -> V_118 = F_34 ( V_119 ) ;
else
V_94 -> V_118 = F_34 ( V_120 ) ;
break;
case V_11 :
V_94 -> V_118 = F_34 ( V_121 ) ;
break;
case V_122 :
V_94 -> V_118 = F_34 ( V_123 ) ;
break;
case V_20 :
V_94 -> V_118 = F_34 ( V_124 ) ;
break;
case V_46 :
V_94 -> V_118 = F_34 ( V_125 ) ;
break;
default:
F_19 ( 1 ) ;
}
V_94 -> V_14 = F_34 ( V_8 -> V_14 ) ;
memcpy ( V_94 -> V_126 , V_4 -> V_127 , V_128 ) ;
if ( V_116 )
memcpy ( V_94 -> V_129 , V_116 , V_128 ) ;
else
F_37 ( V_94 -> V_129 ) ;
F_38 () ;
V_112 = F_39 ( V_4 -> V_130 ) ;
F_28 ( V_34 , V_4 , V_112 ? V_112 -> V_131 . V_132 -> V_71
: V_133 ,
& V_114 , & V_115 ) ;
F_40 () ;
V_94 -> V_72 = F_34 ( ( T_3 ) V_114 ) ;
V_94 -> V_73 = F_34 ( ( T_3 ) V_115 ) ;
V_94 -> V_134 =
F_34 ( V_4 -> V_16 . V_135 ?
V_136 : 0 ) ;
V_94 -> V_137 =
F_34 ( V_4 -> V_16 . V_138 ?
V_139 : 0 ) ;
for ( V_45 = 0 ; V_45 < V_22 ; V_45 ++ ) {
T_1 V_140 = V_69 [ V_45 ] ;
V_94 -> V_19 [ V_140 ] . V_141 =
F_41 ( V_8 -> V_142 [ V_45 ] . V_141 ) ;
V_94 -> V_19 [ V_140 ] . V_143 =
F_41 ( V_8 -> V_142 [ V_45 ] . V_143 ) ;
V_94 -> V_19 [ V_140 ] . V_144 =
F_41 ( V_8 -> V_142 [ V_45 ] . V_145 * 32 ) ;
V_94 -> V_19 [ V_140 ] . V_146 = V_8 -> V_142 [ V_45 ] . V_147 ;
V_94 -> V_19 [ V_140 ] . V_148 = F_7 ( V_140 ) ;
}
if ( V_4 -> type == V_11 )
V_94 -> V_19 [ V_67 ] . V_148 |=
F_7 ( V_68 ) ;
if ( V_4 -> V_16 . V_149 )
V_94 -> V_150 |= F_34 ( V_151 ) ;
if ( V_4 -> V_16 . V_152 )
V_94 -> V_104 |= F_34 ( V_153 ) ;
F_33 ( V_34 , L_7 ,
V_4 -> V_16 . V_152 ,
V_4 -> V_16 . V_96 ) ;
if ( V_4 -> V_16 . V_106 . V_107 != V_154 )
V_94 -> V_150 |= F_34 ( V_155 ) ;
if ( V_113 )
F_32 ( V_34 , V_4 , V_94 ) ;
V_94 -> V_156 = F_34 ( V_157 ) ;
}
static int F_42 ( struct V_33 * V_34 ,
struct V_93 * V_94 )
{
int V_44 = F_43 ( V_34 , V_158 , 0 ,
sizeof( * V_94 ) , V_94 ) ;
if ( V_44 )
F_20 ( V_34 , L_8 ,
F_44 ( V_94 -> V_110 ) , V_44 ) ;
return V_44 ;
}
static int F_45 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
T_3 V_110 , bool V_159 ,
const T_1 * V_109 )
{
struct V_93 V_94 = {} ;
struct V_160 * V_161 ;
F_46 ( V_4 -> type != V_10 ) ;
F_35 ( V_34 , V_4 , & V_94 , V_109 , V_110 ) ;
if ( V_4 -> V_47 ) {
struct V_162 * V_163 =
& V_4 -> V_16 . V_164 ;
V_94 . V_165 . V_166 = F_34 ( V_163 -> V_167 &
V_168 ) ;
V_161 = & V_94 . V_165 . V_29 ;
} else {
V_161 = & V_94 . V_29 ;
}
if ( V_4 -> V_16 . V_169 && V_4 -> V_16 . V_170 &&
! V_159 ) {
T_3 V_171 ;
V_171 = V_4 -> V_16 . V_172 *
V_4 -> V_16 . V_17 ;
V_171 *= 1024 ;
V_161 -> V_173 =
F_47 ( V_4 -> V_16 . V_174 + V_171 ) ;
V_161 -> V_175 =
F_34 ( V_4 -> V_16 . V_176 + V_171 ) ;
F_48 ( V_34 , L_9 ,
F_49 ( V_161 -> V_173 ) ,
F_44 ( V_161 -> V_175 ) ,
V_171 ) ;
V_161 -> V_177 = F_34 ( 1 ) ;
} else {
V_161 -> V_177 = F_34 ( 0 ) ;
V_94 . V_156 |= F_34 ( V_178 ) ;
}
V_161 -> V_179 = F_34 ( V_4 -> V_16 . V_17 ) ;
V_161 -> V_180 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 ) ) ;
V_161 -> V_181 = F_34 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_170 ) ;
V_161 -> V_182 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_170 ) ) ;
V_161 -> V_183 = F_34 ( V_34 -> V_38 -> V_184 . V_183 ) ;
V_161 -> V_185 = F_34 ( V_4 -> V_16 . V_186 ) ;
return F_42 ( V_34 , & V_94 ) ;
}
static int F_51 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
T_3 V_110 )
{
struct V_93 V_94 = {} ;
F_46 ( V_4 -> type != V_122 ) ;
F_35 ( V_34 , V_4 , & V_94 , NULL , V_110 ) ;
V_94 . V_156 = F_34 ( V_187 |
V_188 |
V_178 |
V_189 |
V_190 ) ;
V_34 -> V_38 -> V_191 |= V_192 ;
return F_42 ( V_34 , & V_94 ) ;
}
static int F_52 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
T_3 V_110 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_93 V_94 = {} ;
F_46 ( V_4 -> type != V_46 ) ;
F_35 ( V_34 , V_4 , & V_94 , NULL , V_110 ) ;
V_94 . V_156 = F_34 ( V_178 |
V_189 ) ;
V_94 . V_193 . V_179 = F_34 ( V_4 -> V_16 . V_17 ) ;
V_94 . V_193 . V_180 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 ) ) ;
V_94 . V_193 . V_194 = F_34 ( V_8 -> V_41 ) ;
return F_42 ( V_34 , & V_94 ) ;
}
static void F_53 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_195 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_47 &&
V_8 -> V_196 )
V_6 -> V_197 = true ;
}
static int F_54 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
T_3 V_110 )
{
struct V_93 V_94 = {} ;
struct V_195 V_6 = {} ;
F_46 ( V_4 -> type != V_20 ) ;
F_35 ( V_34 , V_4 , & V_94 , NULL , V_110 ) ;
V_94 . V_104 |= F_34 ( V_153 ) ;
V_94 . V_156 = F_34 ( V_189 ) ;
F_13 (
V_34 -> V_38 , V_39 ,
F_53 , & V_6 ) ;
V_94 . V_198 . V_199 = F_34 ( V_6 . V_197 ? 1 : 0 ) ;
return F_42 ( V_34 , & V_94 ) ;
}
static void F_55 ( struct V_33 * V_34 ,
struct V_200 * V_201 ,
T_1 * V_202 , T_3 V_203 )
{
T_3 V_204 ;
struct V_205 * V_206 = (struct V_205 * ) V_202 ;
V_204 = V_206 -> V_207 . V_202 . V_208 - V_202 ;
while ( ( V_204 < ( V_203 - 2 ) ) &&
( V_202 [ V_204 ] != V_209 ) )
V_204 += V_202 [ V_204 + 1 ] + 2 ;
if ( ( V_204 < ( V_203 - 1 ) ) && ( V_202 [ V_204 ] == V_209 ) ) {
V_201 -> V_204 = F_34 ( V_204 ) ;
V_201 -> V_210 = F_34 ( ( T_3 ) V_202 [ V_204 + 1 ] ) ;
} else {
F_56 ( V_34 , L_10 ) ;
}
}
static int F_57 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
struct V_211 * V_202 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_212 V_94 = {
. V_41 = V_213 ,
. V_191 = V_214 ,
} ;
struct V_200 V_201 = {} ;
struct V_215 * V_216 ;
T_3 V_217 ;
T_3 V_218 , V_219 ;
if ( F_46 ( ! V_202 ) )
return - V_220 ;
V_217 = V_202 -> V_221 ;
V_201 . V_222 = F_34 ( ( T_3 ) V_8 -> V_41 ) ;
V_216 = F_58 ( V_202 ) ;
V_201 . V_223 . V_221 = F_41 ( ( T_2 ) V_217 ) ;
V_201 . V_223 . V_61 = V_8 -> V_60 . V_61 ;
V_201 . V_223 . V_224 = F_34 ( V_225 ) ;
V_219 = V_226 | V_227 ;
V_219 |=
F_59 ( V_34 , ( void * ) V_202 -> V_6 , V_216 , 0 ) <<
V_228 ;
V_201 . V_223 . V_219 = F_34 ( V_219 ) ;
V_34 -> V_229 =
F_60 ( V_34 , V_34 -> V_230 -> V_231 ,
V_34 -> V_229 ) ;
V_201 . V_223 . V_232 =
F_34 ( F_7 ( V_34 -> V_229 ) <<
V_233 ) ;
if ( V_216 -> V_71 == V_234 || V_4 -> V_47 ) {
V_218 = V_86 ;
} else {
V_218 = V_87 ;
V_201 . V_223 . V_232 |= F_34 ( V_235 ) ;
}
V_201 . V_223 . V_232 |=
F_34 ( F_61 ( V_218 ) ) ;
if ( V_4 -> type == V_11 )
F_55 ( V_34 , & V_201 ,
V_202 -> V_6 ,
V_217 ) ;
V_94 . V_221 [ 0 ] = sizeof( V_201 ) ;
V_94 . V_6 [ 0 ] = & V_201 ;
V_94 . V_236 [ 0 ] = 0 ;
V_94 . V_221 [ 1 ] = V_217 ;
V_94 . V_6 [ 1 ] = V_202 -> V_6 ;
V_94 . V_236 [ 1 ] = V_237 ;
return F_62 ( V_34 , & V_94 ) ;
}
int F_63 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_211 * V_202 ;
int V_44 ;
F_46 ( V_4 -> type != V_11 &&
V_4 -> type != V_46 ) ;
V_202 = F_64 ( V_34 -> V_38 , V_4 , NULL ) ;
if ( ! V_202 )
return - V_238 ;
V_44 = F_57 ( V_34 , V_4 , V_202 ) ;
F_65 ( V_202 ) ;
return V_44 ;
}
static void F_66 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_239 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_169 )
return;
if ( V_4 -> V_47 && V_6 -> V_240 )
return;
V_6 -> V_240 = V_4 -> V_16 . V_176 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_67 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
struct V_241 * V_242 ,
bool V_243 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_239 V_6 = {
. V_34 = V_34 ,
. V_4 = V_4 ,
. V_240 = 0
} ;
V_242 -> V_179 = F_34 ( V_4 -> V_16 . V_17 ) ;
V_242 -> V_180 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 ) ) ;
V_242 -> V_181 = F_34 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_170 ) ;
V_242 -> V_182 =
F_34 ( F_50 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_170 ) ) ;
V_242 -> V_244 = F_34 ( V_4 -> V_24 ) ;
if ( V_243 ) {
F_13 (
V_34 -> V_38 , V_39 ,
F_66 , & V_6 ) ;
if ( V_6 . V_240 ) {
T_3 rand = ( F_68 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_245 = V_6 . V_240 +
F_69 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_245 =
F_70 ( V_34 -> V_246 ,
V_247 ) ;
}
}
V_242 -> V_248 = F_34 ( V_8 -> V_245 ) ;
V_242 -> V_249 = 0 ;
V_242 -> V_194 = F_34 ( V_8 -> V_41 ) ;
}
static int F_71 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
T_3 V_110 )
{
struct V_93 V_94 = {} ;
F_46 ( V_4 -> type != V_11 || V_4 -> V_47 ) ;
F_35 ( V_34 , V_4 , & V_94 , NULL , V_110 ) ;
V_94 . V_156 |= F_34 ( V_189 |
V_178 ) ;
F_67 ( V_34 , V_4 , & V_94 . V_250 ,
V_110 == V_251 ) ;
return F_42 ( V_34 , & V_94 ) ;
}
static int F_72 ( struct V_33 * V_34 ,
struct V_3 * V_4 ,
T_3 V_110 )
{
struct V_93 V_94 = {} ;
struct V_162 * V_163 = & V_4 -> V_16 . V_164 ;
F_46 ( V_4 -> type != V_11 || ! V_4 -> V_47 ) ;
F_35 ( V_34 , V_4 , & V_94 , NULL , V_110 ) ;
V_94 . V_156 |= F_34 ( V_189 |
V_178 ) ;
F_67 ( V_34 , V_4 , & V_94 . V_252 . V_250 ,
V_110 == V_251 ) ;
V_94 . V_252 . V_166 = F_34 ( V_163 -> V_167 &
V_168 ) ;
V_94 . V_252 . V_253 =
F_34 ( ! ! ( V_163 -> V_167 &
V_254 ) ) ;
return F_42 ( V_34 , & V_94 ) ;
}
static int F_73 ( struct V_33 * V_34 , struct V_3 * V_4 ,
T_3 V_110 , bool V_159 ,
const T_1 * V_109 )
{
switch ( V_4 -> type ) {
case V_10 :
return F_45 ( V_34 , V_4 , V_110 ,
V_159 ,
V_109 ) ;
break;
case V_11 :
if ( ! V_4 -> V_47 )
return F_71 ( V_34 , V_4 , V_110 ) ;
else
return F_72 ( V_34 , V_4 , V_110 ) ;
break;
case V_122 :
return F_51 ( V_34 , V_4 , V_110 ) ;
case V_20 :
return F_54 ( V_34 , V_4 , V_110 ) ;
case V_46 :
return F_52 ( V_34 , V_4 , V_110 ) ;
default:
break;
}
return - V_255 ;
}
int F_74 ( struct V_33 * V_34 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_44 ;
if ( F_75 ( V_8 -> V_256 , L_11 ,
V_4 -> V_127 , F_76 ( V_4 ) ) )
return - V_51 ;
V_44 = F_73 ( V_34 , V_4 , V_251 ,
true , NULL ) ;
if ( V_44 )
return V_44 ;
F_77 ( V_34 , V_4 ) ;
V_8 -> V_256 = true ;
return 0 ;
}
int F_78 ( struct V_33 * V_34 , struct V_3 * V_4 ,
bool V_159 , const T_1 * V_109 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_75 ( ! V_8 -> V_256 , L_12 ,
V_4 -> V_127 , F_76 ( V_4 ) ) )
return - V_51 ;
return F_73 ( V_34 , V_4 , V_257 ,
V_159 , V_109 ) ;
}
int F_79 ( struct V_33 * V_34 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_93 V_94 ;
int V_44 ;
if ( F_75 ( ! V_8 -> V_256 , L_13 ,
V_4 -> V_127 , F_76 ( V_4 ) ) )
return - V_51 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_117 = F_34 ( F_36 ( V_8 -> V_41 ,
V_8 -> V_53 ) ) ;
V_94 . V_110 = F_34 ( V_258 ) ;
V_44 = F_43 ( V_34 , V_158 , 0 ,
sizeof( V_94 ) , & V_94 ) ;
if ( V_44 ) {
F_20 ( V_34 , L_14 , V_44 ) ;
return V_44 ;
}
V_8 -> V_256 = false ;
if ( V_4 -> type == V_122 )
V_34 -> V_38 -> V_191 &= ~ V_192 ;
return 0 ;
}
static void F_80 ( struct V_33 * V_34 ,
struct V_3 * V_259 , T_3 V_260 ,
bool V_261 )
{
struct V_7 * V_8 =
F_2 ( V_259 ) ;
if ( ! V_261 && ! V_8 -> V_262 )
return;
V_8 -> V_262 = true ;
if ( ! F_81 ( V_259 ) ) {
int V_263 = F_82 ( V_259 ) ;
F_63 ( V_34 , V_259 ) ;
if ( V_259 -> V_47 &&
! F_83 ( & V_8 -> V_54 ) && V_260 &&
V_261 ) {
T_3 V_264 = ( V_263 + 1 ) *
V_259 -> V_16 . V_17 -
V_265 ;
T_3 V_266 = V_260 + V_264 * 1024 ;
F_84 ( V_34 , V_259 ,
V_265 -
V_267 ,
V_266 ) ;
}
} else if ( ! F_83 ( & V_8 -> V_54 ) ) {
F_85 ( V_259 ) ;
F_86 ( V_34 -> V_259 , NULL ) ;
}
}
int F_87 ( struct V_33 * V_34 ,
struct V_268 * V_269 ,
struct V_270 * V_94 )
{
struct V_271 * V_272 = F_88 ( V_269 ) ;
struct V_273 * V_202 = ( void * ) V_272 -> V_6 ;
struct V_274 * V_275 ;
struct V_3 * V_259 ;
struct V_3 * V_276 ;
T_2 V_49 ;
F_12 ( & V_34 -> V_37 ) ;
V_275 = & V_202 -> V_275 ;
V_34 -> V_277 = F_44 ( V_202 -> V_260 ) ;
V_49 = F_89 ( V_275 -> V_49 . V_49 ) & V_278 ;
F_90 ( V_34 ,
L_15 ,
V_49 , V_275 -> V_279 ,
F_49 ( V_202 -> V_280 ) ,
V_34 -> V_277 ,
F_44 ( V_275 -> V_281 ) ) ;
V_259 = F_91 ( V_34 -> V_259 ,
F_92 ( & V_34 -> V_37 ) ) ;
if ( F_93 ( V_259 && V_259 -> V_282 ) )
F_80 ( V_34 , V_259 , V_34 -> V_277 ,
( V_49 == V_283 ) ) ;
V_276 = F_91 ( V_34 -> V_284 ,
F_92 ( & V_34 -> V_37 ) ) ;
if ( F_93 ( V_276 ) ) {
struct V_7 * V_8 =
F_2 ( V_276 ) ;
if ( ! V_34 -> V_285 )
V_34 -> V_285 =
V_286 ;
else
V_34 -> V_285 -- ;
if ( V_34 -> V_285 == 0 ) {
F_94 ( V_34 , V_8 , false ) ;
F_86 ( V_34 -> V_284 , NULL ) ;
}
}
return 0 ;
}
static void F_95 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_287 * V_288 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_41 != ( T_2 ) F_44 ( V_288 -> V_289 ) )
return;
if ( F_44 ( V_288 -> V_290 ) >
V_291 )
F_96 ( V_4 ) ;
}
int F_97 ( struct V_33 * V_34 ,
struct V_268 * V_269 ,
struct V_270 * V_94 )
{
struct V_271 * V_272 = F_88 ( V_269 ) ;
struct V_287 * V_292 = ( void * ) V_272 -> V_6 ;
F_48 ( V_34 ,
L_16 ,
F_44 ( V_292 -> V_289 ) ,
F_44 ( V_292 -> V_293 ) ,
F_44 ( V_292 -> V_290 ) ,
F_44 ( V_292 -> V_294 ) ,
F_44 ( V_292 -> V_295 ) ) ;
F_13 ( V_34 -> V_38 ,
V_296 ,
F_95 ,
V_292 ) ;
return 0 ;
}
