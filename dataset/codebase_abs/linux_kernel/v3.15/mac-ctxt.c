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
if ( V_4 -> V_16 . V_144 ) {
V_87 -> V_97 |= F_29 ( V_145 ) ;
if ( F_37 ( V_28 -> V_146 -> V_147 ) >= 8 )
V_87 -> V_97 |=
F_29 ( V_148 ) ;
}
F_28 ( V_28 , L_7 ,
V_4 -> V_16 . V_144 ,
V_4 -> V_16 . V_89 ) ;
if ( V_4 -> V_16 . V_99 . V_100 != V_149 )
V_87 -> V_142 |= F_29 ( V_150 ) ;
if ( V_105 )
F_27 ( V_28 , V_4 , V_87 ) ;
V_87 -> V_151 = F_29 ( V_152 ) ;
}
static int F_38 ( struct V_27 * V_28 ,
struct V_86 * V_87 )
{
int V_36 = F_39 ( V_28 , V_153 , V_154 ,
sizeof( * V_87 ) , V_87 ) ;
if ( V_36 )
F_15 ( V_28 , L_8 ,
F_40 ( V_87 -> V_102 ) , V_36 ) ;
return V_36 ;
}
static void F_41 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_155 * V_156 ,
bool V_157 )
{
if ( V_4 -> V_16 . V_158 && V_4 -> V_16 . V_159 &&
! V_157 ) {
T_3 V_160 ;
V_160 = V_4 -> V_16 . V_161 *
V_4 -> V_16 . V_17 ;
V_160 *= 1024 ;
V_156 -> V_162 =
F_42 ( V_4 -> V_16 . V_163 + V_160 ) ;
V_156 -> V_164 =
F_29 ( V_4 -> V_16 . V_165 + V_160 ) ;
F_43 ( V_28 , L_9 ,
F_44 ( V_156 -> V_162 ) ,
F_40 ( V_156 -> V_164 ) ,
V_160 ) ;
V_156 -> V_166 = F_29 ( 1 ) ;
} else {
V_156 -> V_166 = F_29 ( 0 ) ;
}
V_156 -> V_167 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_156 -> V_168 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_156 -> V_169 = F_29 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_159 ) ;
V_156 -> V_170 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_159 ) ) ;
V_156 -> V_171 = F_29 ( V_28 -> V_32 -> V_172 . V_171 ) ;
V_156 -> V_173 = F_29 ( V_4 -> V_16 . V_174 ) ;
}
static int F_46 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
F_47 ( V_4 -> type != V_10 || V_4 -> V_39 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
if ( ! V_4 -> V_16 . V_158 || ! V_4 -> V_16 . V_159 )
V_87 . V_151 |= F_29 ( V_175 ) ;
else
V_87 . V_151 &= ~ F_29 ( V_175 ) ;
F_41 ( V_28 , V_4 , & V_87 . V_176 ,
V_102 == V_177 ) ;
return F_38 ( V_28 , & V_87 ) ;
}
static int F_48 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
struct V_178 * V_179 = & V_4 -> V_16 . V_180 ;
F_47 ( V_4 -> type != V_10 || ! V_4 -> V_39 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
F_41 ( V_28 , V_4 , & V_87 . V_181 . V_176 ,
V_102 == V_177 ) ;
V_87 . V_181 . V_182 = F_29 ( V_179 -> V_183 &
V_184 ) ;
return F_38 ( V_28 , & V_87 ) ;
}
static int F_49 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
F_47 ( V_4 -> type != V_113 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_151 = F_29 ( V_185 |
V_186 |
V_175 |
V_187 |
V_188 ) ;
V_28 -> V_32 -> V_189 |= V_190 ;
return F_38 ( V_28 , & V_87 ) ;
}
static int F_50 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_86 V_87 = {} ;
F_47 ( V_4 -> type != V_38 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_151 = F_29 ( V_175 |
V_187 ) ;
V_87 . V_191 . V_167 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_87 . V_191 . V_168 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_87 . V_191 . V_192 = F_29 ( V_8 -> V_25 ) ;
return F_38 ( V_28 , & V_87 ) ;
}
static void F_51 ( void * V_1 , T_1 * V_2 , struct V_3 * V_4 )
{
struct V_193 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 -> type == V_11 && V_4 -> V_39 &&
V_8 -> V_194 )
V_6 -> V_195 = true ;
}
static int F_52 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
struct V_193 V_6 = {} ;
F_47 ( V_4 -> type != V_30 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_97 |= F_29 ( V_145 ) ;
V_87 . V_151 = F_29 ( V_187 ) ;
F_11 (
V_28 -> V_32 , V_33 ,
F_51 , & V_6 ) ;
V_87 . V_196 . V_197 = F_29 ( V_6 . V_195 ? 1 : 0 ) ;
return F_38 ( V_28 , & V_87 ) ;
}
static void F_53 ( struct V_27 * V_28 ,
struct V_198 * V_199 ,
T_1 * V_200 , T_3 V_201 )
{
T_3 V_202 ;
struct V_203 * V_204 = (struct V_203 * ) V_200 ;
V_202 = V_204 -> V_205 . V_200 . V_206 - V_200 ;
while ( ( V_202 < ( V_201 - 2 ) ) &&
( V_200 [ V_202 ] != V_207 ) )
V_202 += V_200 [ V_202 + 1 ] + 2 ;
if ( ( V_202 < ( V_201 - 1 ) ) && ( V_200 [ V_202 ] == V_207 ) ) {
V_199 -> V_202 = F_29 ( V_202 ) ;
V_199 -> V_208 = F_29 ( ( T_3 ) V_200 [ V_202 + 1 ] ) ;
} else {
F_54 ( V_28 , L_10 ) ;
}
}
static int F_55 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_209 * V_200 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_210 V_87 = {
. V_25 = V_211 ,
. V_189 = V_212 ,
} ;
struct V_198 V_199 = {} ;
struct V_213 * V_214 ;
T_3 V_215 ;
T_3 V_216 ;
if ( F_47 ( ! V_200 ) )
return - V_217 ;
V_215 = V_200 -> V_218 ;
V_199 . V_219 = F_29 ( ( T_3 ) V_8 -> V_25 ) ;
V_199 . V_220 . V_218 = F_36 ( ( T_2 ) V_215 ) ;
V_199 . V_220 . V_52 = V_8 -> V_51 . V_52 ;
V_199 . V_220 . V_221 = F_29 ( V_222 ) ;
V_199 . V_220 . V_223 = F_29 ( V_224 |
V_225 |
V_226 ) ;
V_28 -> V_227 =
F_56 ( V_28 , V_28 -> V_146 -> V_228 ,
V_28 -> V_227 ) ;
V_199 . V_220 . V_229 =
F_29 ( F_9 ( V_28 -> V_227 ) <<
V_230 ) ;
V_214 = F_57 ( V_200 ) ;
if ( V_214 -> V_64 == V_231 || V_4 -> V_39 ) {
V_216 = V_79 ;
} else {
V_216 = V_80 ;
V_199 . V_220 . V_229 |= F_29 ( V_232 ) ;
}
V_199 . V_220 . V_229 |=
F_29 ( F_58 ( V_216 ) ) ;
if ( V_4 -> type == V_11 )
F_53 ( V_28 , & V_199 ,
V_200 -> V_6 ,
V_215 ) ;
V_87 . V_218 [ 0 ] = sizeof( V_199 ) ;
V_87 . V_6 [ 0 ] = & V_199 ;
V_87 . V_233 [ 0 ] = 0 ;
V_87 . V_218 [ 1 ] = V_215 ;
V_87 . V_6 [ 1 ] = V_200 -> V_6 ;
V_87 . V_233 [ 1 ] = V_234 ;
return F_59 ( V_28 , & V_87 ) ;
}
int F_60 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
struct V_209 * V_200 ;
int V_36 ;
F_47 ( V_4 -> type != V_11 &&
V_4 -> type != V_38 ) ;
V_200 = F_61 ( V_28 -> V_32 , V_4 ) ;
if ( ! V_200 )
return - V_235 ;
V_36 = F_55 ( V_28 , V_4 , V_200 ) ;
F_62 ( V_200 ) ;
return V_36 ;
}
static void F_63 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_236 * V_6 = V_1 ;
if ( V_4 -> type != V_10 || ! V_4 -> V_16 . V_158 )
return;
if ( V_4 -> V_39 && V_6 -> V_237 )
return;
V_6 -> V_237 = V_4 -> V_16 . V_165 ;
V_6 -> V_17 = V_4 -> V_16 . V_17 ;
}
static void F_64 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
struct V_238 * V_239 ,
bool V_240 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_236 V_6 = {
. V_28 = V_28 ,
. V_4 = V_4 ,
. V_237 = 0
} ;
V_239 -> V_167 = F_29 ( V_4 -> V_16 . V_17 ) ;
V_239 -> V_168 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 ) ) ;
V_239 -> V_169 = F_29 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_159 ) ;
V_239 -> V_170 =
F_29 ( F_45 ( V_4 -> V_16 . V_17 *
V_4 -> V_16 . V_159 ) ) ;
V_239 -> V_241 = F_29 ( V_4 -> V_24 ) ;
if ( V_240 ) {
F_11 (
V_28 -> V_32 , V_33 ,
F_63 , & V_6 ) ;
if ( V_6 . V_237 ) {
T_3 rand = ( F_65 () % ( 64 - 36 ) ) + 36 ;
V_8 -> V_242 = V_6 . V_237 +
F_66 ( V_6 . V_17 * rand /
100 ) ;
} else {
V_8 -> V_242 =
F_67 ( V_28 -> V_59 ,
V_243 ) ;
}
}
V_239 -> V_244 = F_29 ( V_8 -> V_242 ) ;
V_239 -> V_245 = 0 ;
V_239 -> V_192 = F_29 ( V_8 -> V_25 ) ;
}
static int F_68 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
F_47 ( V_4 -> type != V_11 || V_4 -> V_39 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
V_87 . V_151 |= F_29 ( V_187 ) ;
F_64 ( V_28 , V_4 , & V_87 . V_246 ,
V_102 == V_177 ) ;
return F_38 ( V_28 , & V_87 ) ;
}
static int F_69 ( struct V_27 * V_28 ,
struct V_3 * V_4 ,
T_3 V_102 )
{
struct V_86 V_87 = {} ;
struct V_178 * V_179 = & V_4 -> V_16 . V_180 ;
F_47 ( V_4 -> type != V_11 || ! V_4 -> V_39 ) ;
F_30 ( V_28 , V_4 , & V_87 , V_102 ) ;
F_64 ( V_28 , V_4 , & V_87 . V_247 . V_246 ,
V_102 == V_177 ) ;
V_87 . V_247 . V_182 = F_29 ( V_179 -> V_183 &
V_184 ) ;
V_87 . V_247 . V_248 =
F_29 ( ! ! ( V_179 -> V_183 &
V_249 ) ) ;
return F_38 ( V_28 , & V_87 ) ;
}
static int F_70 ( struct V_27 * V_28 , struct V_3 * V_4 ,
T_3 V_102 )
{
switch ( V_4 -> type ) {
case V_10 :
if ( ! V_4 -> V_39 )
return F_46 ( V_28 , V_4 ,
V_102 ) ;
else
return F_48 ( V_28 , V_4 ,
V_102 ) ;
break;
case V_11 :
if ( ! V_4 -> V_39 )
return F_68 ( V_28 , V_4 , V_102 ) ;
else
return F_69 ( V_28 , V_4 , V_102 ) ;
break;
case V_113 :
return F_49 ( V_28 , V_4 , V_102 ) ;
case V_30 :
return F_52 ( V_28 , V_4 , V_102 ) ;
case V_38 :
return F_50 ( V_28 , V_4 , V_102 ) ;
default:
break;
}
return - V_250 ;
}
int F_71 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
int V_36 ;
if ( F_72 ( V_8 -> V_251 , L_11 ,
V_4 -> V_118 , F_73 ( V_4 ) ) )
return - V_43 ;
V_36 = F_70 ( V_28 , V_4 , V_177 ) ;
if ( V_36 )
return V_36 ;
F_74 ( V_28 , V_4 ) ;
V_8 -> V_251 = true ;
return 0 ;
}
int F_75 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_72 ( ! V_8 -> V_251 , L_12 ,
V_4 -> V_118 , F_73 ( V_4 ) ) )
return - V_43 ;
return F_70 ( V_28 , V_4 , V_252 ) ;
}
int F_76 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_86 V_87 ;
int V_36 ;
if ( F_72 ( ! V_8 -> V_251 , L_13 ,
V_4 -> V_118 , F_73 ( V_4 ) ) )
return - V_43 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_108 = F_29 ( F_31 ( V_8 -> V_25 ,
V_8 -> V_45 ) ) ;
V_87 . V_102 = F_29 ( V_253 ) ;
V_36 = F_39 ( V_28 , V_153 , V_154 ,
sizeof( V_87 ) , & V_87 ) ;
if ( V_36 ) {
F_15 ( V_28 , L_14 , V_36 ) ;
return V_36 ;
}
V_8 -> V_251 = false ;
if ( V_4 -> type == V_113 )
V_28 -> V_32 -> V_189 &= ~ V_190 ;
return 0 ;
}
int F_77 ( struct V_27 * V_28 ,
struct V_254 * V_255 ,
struct V_256 * V_87 )
{
struct V_257 * V_258 = F_78 ( V_255 ) ;
struct V_259 * V_200 = ( void * ) V_258 -> V_6 ;
T_2 V_41 V_260 =
F_79 ( V_200 -> V_261 . V_41 . V_41 ) ;
T_3 V_216 V_260 =
F_40 ( V_200 -> V_261 . V_262 ) ;
F_80 ( V_28 , L_15 ,
V_41 & V_263 ,
V_200 -> V_261 . V_264 ,
F_44 ( V_200 -> V_265 ) ,
V_216 ) ;
return 0 ;
}
static void F_81 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_266 * V_267 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_8 -> V_25 != ( T_2 ) F_40 ( V_267 -> V_268 ) )
return;
if ( F_40 ( V_267 -> V_269 ) >
V_270 )
F_82 ( V_4 ) ;
}
int F_83 ( struct V_27 * V_28 ,
struct V_254 * V_255 ,
struct V_256 * V_87 )
{
struct V_257 * V_258 = F_78 ( V_255 ) ;
struct V_266 * V_271 = ( void * ) V_258 -> V_6 ;
F_43 ( V_28 ,
L_16 ,
F_40 ( V_271 -> V_268 ) ,
F_40 ( V_271 -> V_272 ) ,
F_40 ( V_271 -> V_269 ) ,
F_40 ( V_271 -> V_273 ) ,
F_40 ( V_271 -> V_274 ) ) ;
F_11 ( V_28 -> V_32 ,
V_275 ,
F_81 ,
V_271 ) ;
return 0 ;
}
