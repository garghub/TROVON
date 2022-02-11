int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_3 , V_2 ) ;
}
static struct V_4 * F_5 ( struct V_1 * V_2 ,
enum V_5 type )
{
struct V_4 * V_6 ;
if ( ! V_2 -> V_7 )
return NULL ;
V_6 = F_6 ( sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> type = type ;
V_6 -> V_2 = V_2 ;
V_6 -> V_9 . V_10 = V_2 -> V_10 ;
V_6 -> V_9 . V_11 = V_2 -> V_11 ;
V_6 -> V_9 . V_12 = V_2 -> V_12 ;
V_6 -> V_9 . V_13 = V_2 -> V_13 ;
V_6 -> V_9 . V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_1
L_2 ,
V_2 , V_6 , type , V_6 -> V_9 . V_11 ,
V_6 -> V_9 . V_13 , V_6 -> V_9 . V_10 ,
V_6 -> V_9 . V_12 ) ;
F_8 ( V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
if ( ! V_16 ) {
F_7 ( V_14 , L_3 ) ;
return - 1 ;
}
F_10 ( V_2 , V_19 , & V_20 , NULL , V_21 ) ;
F_11 ( V_16 , V_2 , NULL , 0 , * V_19 , V_20 , V_22 ) ;
return F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = NULL ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
struct V_24 * V_25 ;
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - V_27 ;
}
F_10 ( V_2 , V_19 , & V_20 , NULL , V_28 ) ;
V_25 = (struct V_24 * ) * V_19 ;
V_25 -> V_29 |= V_30 ;
F_11 ( V_16 , V_2 , NULL , 0 , * V_19 , V_20 , V_22 | V_31 ) ;
V_2 -> V_32 = V_33 ;
return F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_34 , T_3 * type ,
T_3 V_35 )
{
struct V_24 * V_25 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_40 ;
int V_41 ;
* type = V_42 ;
if ( V_35 < sizeof( struct V_24 ) ) {
F_7 ( V_14 , L_5 , V_35 ) ;
return - V_43 ;
}
V_25 = (struct V_24 * ) V_34 ;
V_40 = sizeof( struct V_24 ) ;
V_41 = F_16 ( V_25 -> V_41 ) ;
if ( V_41 > V_44 ) {
F_7 ( V_14 , L_6
L_7 ) ;
return - V_43 ;
}
if ( V_25 -> V_45 != V_46 && V_25 -> V_45 != V_47 ) {
F_7 ( V_14 , L_8
L_9 ) ;
return - V_43 ;
}
if ( V_25 -> V_45 > V_2 -> V_48 ) {
F_7 ( V_14 , L_8
L_10 ) ;
return - V_43 ;
} else {
V_2 -> V_48 = V_25 -> V_45 ;
}
if ( V_2 -> V_32 != V_49 ) {
if ( memcmp ( V_25 -> V_50 , V_51 , V_52 ) ) {
F_7 ( V_14 , L_11 ) ;
return - V_43 ;
}
} else {
if ( memcmp ( V_25 -> V_50 , V_53 , V_52 ) ) {
F_7 ( V_14 , L_11 ) ;
return - V_43 ;
}
}
if ( V_41 + V_40 != V_35 ) {
F_7 ( V_14 , L_12
L_13 ,
V_41 , V_40 , V_35 ) ;
return - V_43 ;
}
if ( V_35 > V_26 ) {
F_7 ( V_14 , L_14
L_15 ,
V_41 , V_40 , V_35 ) ;
return - V_43 ;
}
V_2 -> V_54 = V_41 ;
switch ( V_25 -> V_45 ) {
case V_47 : {
T_2 V_55 ;
T_2 V_56 ;
T_2 V_57 ;
T_2 V_58 ;
V_37 = (struct V_36 * ) V_34 ;
V_40 += V_59 ;
V_2 -> V_54 -= V_59 ;
V_39 = & V_37 -> V_39 ;
V_57 = F_16 ( V_39 -> V_60 ) ;
V_58 = F_16 ( V_39 -> V_61 ) ;
V_55 = V_57 & V_62 ;
V_56 = V_58 & V_62 ;
if ( ! ( V_57 & V_63 ) ) {
return - V_43 ;
}
if ( V_55 == V_62 || V_56 == V_62 )
V_2 -> V_64 = V_62 ;
if ( V_2 -> V_64 != V_62 ) {
if ( V_2 -> V_32 != V_49 ) {
if ( V_56 > V_65 ) {
V_2 -> V_55 = V_65 ;
} else {
V_2 -> V_55 = V_56 ;
if ( V_56 == 0 &&
( V_58 & V_66 ) ) {
V_2 -> V_55 = 1 ;
F_7 ( V_14 ,
L_16 ,
V_67 , V_56 ) ;
}
}
if ( V_55 > V_68 )
V_2 -> V_56 = V_68 ;
else
V_2 -> V_56 = V_55 ;
} else {
if ( V_56 > V_65 ) {
F_7 ( V_14 ,
L_17 ,
V_67 , V_56 ) ;
return - V_43 ;
}
V_2 -> V_55 = V_56 ;
if ( V_55 > V_68 ) {
V_2 -> V_56 = V_68 ;
} else {
if ( V_55 == 0 &&
( V_58 & V_66 ) ) {
F_7 ( V_14 ,
L_18 ,
V_67 , V_55 ) ;
return - V_43 ;
} else {
V_2 -> V_56 = V_55 ;
}
}
}
}
if ( V_58 & V_66 ) {
V_2 -> V_69 = V_70 ;
} else if ( V_58 & V_71 ) {
V_2 -> V_69 = V_72 ;
} else {
return - V_43 ;
}
break;
}
case V_46 :
default:
break;
}
memcpy ( V_2 -> V_73 , V_34 + V_40 , V_2 -> V_54 ) ;
if ( V_25 -> V_29 & V_30 )
* type = V_74 ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_1 * V_2 , void * V_75 , T_3 V_76 ,
void * V_77 , T_3 V_78 , T_1 V_29 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
T_1 * V_85 ;
T_2 V_86 = sizeof( * V_82 ) ;
V_86 += sizeof( * V_80 ) ;
V_86 += V_76 + V_78 ;
F_17 ( V_16 , 0 ) ;
memset ( V_16 -> V_77 , 0x00 , V_87 + sizeof( * V_82 ) + sizeof( * V_80 ) ) ;
V_85 = F_18 ( V_16 , V_86 + V_87 ) ;
V_84 = (struct V_83 * ) V_85 ;
V_85 += V_87 ;
V_82 = (struct V_81 * ) V_85 ;
V_85 += sizeof( * V_82 ) ;
V_80 = (struct V_79 * ) V_85 ;
F_19 ( V_16 ) ;
F_20 ( V_16 , V_87 ) ;
F_21 ( V_16 , V_87 + sizeof( * V_82 ) ) ;
V_85 += sizeof( * V_80 ) ;
V_16 -> V_88 = V_89 ;
if ( ! ( V_2 -> V_90 -> V_91 & V_92 ) )
V_16 -> V_88 = V_93 ;
V_16 -> V_94 = F_22 ( 0x800 ) ;
V_16 -> V_95 = 0 ;
V_16 -> V_96 = V_87 ;
memcpy ( V_84 -> V_97 , V_2 -> V_98 , V_99 ) ;
memcpy ( V_84 -> V_100 , V_2 -> V_101 , V_99 ) ;
V_84 -> V_102 = F_22 ( 0x0800 ) ;
V_82 -> V_103 = V_104 ;
V_82 -> V_105 = 5 ;
V_82 -> V_106 = 0 ;
V_82 -> V_107 = F_22 ( V_86 ) ;
V_82 -> V_108 = F_22 ( ++ V_2 -> V_109 . V_110 ) ;
V_82 -> V_111 = F_22 ( 0x4000 ) ;
V_82 -> V_112 = 0x40 ;
V_82 -> V_94 = 0x06 ;
V_82 -> V_113 = F_23 ( V_2 -> V_11 ) ;
V_82 -> V_114 = F_23 ( V_2 -> V_10 ) ;
V_80 -> V_115 = F_22 ( V_2 -> V_13 ) ;
V_80 -> V_116 = F_22 ( V_2 -> V_12 ) ;
V_80 -> V_117 = F_23 ( V_2 -> V_109 . V_118 ) ;
if ( V_29 & V_22 ) {
V_2 -> V_109 . V_119 = V_2 -> V_109 . V_120 ;
V_80 -> V_121 = F_23 ( V_2 -> V_109 . V_119 ) ;
V_80 -> V_122 = 1 ;
} else {
V_80 -> V_121 = 0 ;
}
if ( V_29 & V_123 ) {
V_2 -> V_109 . V_118 ++ ;
V_80 -> V_124 = 1 ;
} else {
V_2 -> V_109 . V_118 += V_78 ;
}
if ( V_29 & V_31 ) {
V_2 -> V_109 . V_118 ++ ;
V_80 -> V_125 = 1 ;
}
if ( V_29 & V_126 )
V_80 -> V_127 = 1 ;
V_80 -> V_128 = ( T_2 ) ( ( sizeof( * V_80 ) + V_76 + 3 ) >> 2 ) ;
V_80 -> V_129 = F_22 ( V_2 -> V_109 . V_130 ) ;
V_80 -> V_131 = 0 ;
if ( V_76 )
memcpy ( V_85 , V_75 , V_76 ) ;
V_85 += V_76 ;
if ( V_78 )
memcpy ( V_85 , V_77 , V_78 ) ;
F_24 ( V_16 ) -> V_132 = 0 ;
V_133 ++ ;
}
static void F_25 ( struct V_134 * V_135 )
{
F_7 ( V_14 , L_19 ) ;
F_7 ( V_14 , L_20 , V_135 ) ;
if ( ! V_135 )
return;
F_7 ( V_14 , L_19 ) ;
F_7 ( V_14 , L_21 , V_135 -> V_32 ) ;
F_7 ( V_14 , L_22 , F_26 ( & V_135 -> V_136 ) ) ;
F_7 ( V_14 , L_23 , F_26 ( & V_135 -> V_137 ) ) ;
F_7 ( V_14 , L_24 , V_135 ) ;
F_7 ( V_14 , L_25 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
T_2 V_138 , T_2 V_139 )
{
if ( V_138 > V_65 )
V_138 = V_65 ;
if ( V_139 > V_68 )
V_139 = V_68 ;
V_2 -> V_55 = V_138 ;
V_2 -> V_56 = V_139 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * * V_19 ,
T_2 * V_20 , T_1 * V_140 , T_1 V_141 )
{
int V_142 = 0 ;
* V_19 = ( V_140 ) ? V_140 : & V_2 -> V_73 [ 0 ] ;
switch ( V_2 -> V_48 ) {
case V_46 :
* V_19 = ( T_1 * ) * V_19 + sizeof( struct V_38 ) ;
* V_20 = sizeof( struct V_24 ) + V_2 -> V_54 ;
F_28 ( V_2 , * V_19 , V_141 ) ;
break;
case V_47 :
* V_20 = sizeof( struct V_36 ) + V_2 -> V_54 ;
F_29 ( V_2 , * V_19 , V_141 ) ;
break;
default:
V_142 = - V_43 ;
}
return V_142 ;
}
static void F_29 ( struct V_1 * V_2 ,
void * V_17 , T_1 V_141 )
{
struct V_36 * V_25 = (struct V_36 * ) V_17 ;
struct V_38 * V_39 = & V_25 -> V_39 ;
T_2 V_60 ;
T_2 V_61 ;
F_28 ( V_2 , V_17 , V_141 ) ;
V_25 -> V_29 |= V_143 ;
V_25 -> V_41 += F_22 ( V_59 ) ;
if ( V_2 -> V_64 == V_62 ) {
V_60 = V_62 ;
V_61 = V_62 ;
} else {
V_60 = V_2 -> V_55 & V_62 ;
V_61 = V_2 -> V_56 & V_62 ;
}
V_60 |= V_63 ;
V_60 |= V_144 ;
switch ( V_141 ) {
case V_21 :
V_61 |= V_71 ;
V_61 |= V_66 ;
break;
case V_28 :
switch ( V_2 -> V_69 ) {
case V_72 :
V_61 |= V_71 ;
break;
case V_70 :
V_61 |= V_66 ;
break;
}
}
V_39 -> V_60 = F_22 ( V_60 ) ;
V_39 -> V_61 = F_22 ( V_61 ) ;
}
static void F_28 ( struct V_1 * V_2 , void * V_17 , T_1 V_141 )
{
struct V_24 * V_25 = (struct V_24 * ) V_17 ;
switch ( V_141 ) {
case V_21 :
memcpy ( V_25 -> V_50 , V_51 , V_52 ) ;
break;
case V_28 :
memcpy ( V_25 -> V_50 , V_53 , V_52 ) ;
break;
}
V_25 -> V_29 = V_145 ;
V_25 -> V_45 = V_2 -> V_48 ;
V_25 -> V_41 = F_22 ( V_2 -> V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_146 * * V_147 )
{
T_4 V_148 ;
struct V_146 * V_149 = * V_147 ;
struct V_150 * V_151 = & V_149 -> V_152 . V_153 [ 0 ] ;
V_148 = ( unsigned long ) V_149 -> V_154 ;
V_148 |= V_155 >> 1 ;
F_31 ( V_151 -> V_156 , V_157 , V_148 ) ;
V_151 -> V_156 [ V_158 ] = 0 ;
V_151 -> V_156 [ V_159 ] = 0 ;
switch ( V_2 -> V_69 ) {
case V_72 :
F_7 ( V_14 , L_26 ) ;
V_151 -> V_156 [ V_160 ] =
F_32 ( V_161 ) ;
V_151 -> V_156 [ V_162 ] = 0 ;
V_151 -> V_156 [ V_163 ] = 0 ;
V_151 -> V_156 [ V_164 ] = 0 ;
break;
case V_70 :
default:
if ( V_2 -> V_69 != V_70 )
F_33 ( 1 , L_27 ,
V_2 -> V_69 ) ;
F_7 ( V_14 , L_28 ) ;
V_151 -> V_156 [ V_160 ] =
F_32 ( V_165 ) ;
V_151 -> V_156 [ V_166 ] = 1 ;
V_151 -> V_156 [ V_167 ] = 0 ;
V_151 -> V_156 [ V_168 ] = 0 ;
V_151 -> V_156 [ V_169 ] = 1 ;
V_151 -> V_156 [ V_164 ] = 1 ;
break;
}
if ( V_149 -> V_170 ) {
V_149 -> V_170 = 0 ;
F_34 ( V_149 -> V_171 ) ;
}
V_149 -> V_172 -> V_173 &= F_32 ( ~ ( V_174 |
V_175 |
V_176 ) ) ;
V_149 -> V_177 = 1 ;
V_149 -> V_152 . V_178 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_179 type , int V_180 ,
int V_181 )
{
unsigned long V_29 ;
struct V_134 * V_3 = V_2 -> V_3 ;
struct V_182 * V_183 ;
int V_142 = 0 ;
V_183 = F_6 ( sizeof( * V_183 ) , V_8 ) ;
if ( ! V_183 )
return - V_27 ;
V_183 -> V_184 = V_185 ;
V_183 -> V_186 = V_187 ;
V_183 -> V_16 = V_16 ;
V_183 -> V_188 = V_189 ;
V_183 -> type = type ;
V_183 -> V_90 = V_2 -> V_90 ;
V_183 -> V_180 = V_180 ;
V_183 -> V_181 = V_181 ;
if ( type == V_190 ) {
V_183 -> V_188 += ( V_191 / 10 ) ;
if ( V_2 -> V_192 ) {
F_35 ( V_183 ) ;
F_36 ( 1 ) ;
return - V_43 ;
}
V_2 -> V_192 = V_183 ;
}
if ( type == V_23 ) {
V_183 -> V_193 = F_37 ( F_38 ( V_16 ) -> V_117 ) ;
F_39 ( & V_183 -> V_16 -> V_194 ) ;
F_40 ( & V_2 -> V_195 , V_29 ) ;
V_2 -> V_196 = V_183 ;
F_2 ( V_2 ) ;
F_41 ( & V_2 -> V_195 , V_29 ) ;
V_183 -> V_188 = V_189 + V_197 ;
V_142 = F_42 ( V_183 -> V_16 , V_2 -> V_90 ) ;
if ( V_142 != V_198 ) {
F_7 ( V_14 , L_29
L_30 , V_183 , V_189 ) ;
V_183 -> V_188 = V_189 ;
V_142 = V_198 ;
} else {
V_199 ++ ;
if ( ! V_180 ) {
F_43 ( V_2 ) ;
if ( V_181 )
F_4 ( V_3 , V_2 ) ;
return V_142 ;
}
}
}
if ( ! F_44 ( & V_3 -> V_200 ) )
F_45 ( & V_3 -> V_200 , V_183 -> V_188 ) ;
return V_142 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_201 * V_7 = V_2 -> V_7 ;
enum V_202 V_32 = V_2 -> V_32 ;
V_2 -> V_32 = V_203 ;
switch ( V_32 ) {
case V_204 :
case V_205 :
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_206 :
case V_33 :
if ( V_2 -> V_7 )
V_7 -> V_207 ( V_7 ) ;
F_47 ( V_2 , NULL ) ;
break;
default:
F_2 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
F_5 ( V_2 , V_208 ) ;
}
}
static void F_48 ( struct V_1 * V_2 , T_3 V_209 )
{
struct V_182 * V_192 = V_2 -> V_192 ;
struct V_201 * V_7 = V_2 -> V_7 ;
struct V_146 * V_149 ;
unsigned long V_210 ;
if ( ! V_192 )
return;
V_149 = (struct V_146 * ) V_192 -> V_16 ;
if ( V_149 ) {
F_40 ( & V_149 -> V_211 , V_210 ) ;
if ( V_149 -> V_7 ) {
F_7 ( V_14 , L_31
L_32
L_33
L_34 , V_149 -> V_152 . V_212 , V_7 ,
F_26 ( & V_149 -> V_213 ) ) ;
V_149 -> V_214 = V_215 ;
V_149 -> V_216 = V_217 ;
V_149 -> V_218 = V_219 ;
F_41 ( & V_149 -> V_211 , V_210 ) ;
F_49 ( V_149 ) ;
} else {
F_41 ( & V_149 -> V_211 , V_210 ) ;
F_7 ( V_14 , L_31
L_32
L_35
L_34 , V_149 -> V_152 . V_212 , V_7 ,
F_26 ( & V_149 -> V_213 ) ) ;
}
} else if ( V_209 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_2 -> V_7 )
V_7 -> V_207 ( V_7 ) ;
F_35 ( V_192 ) ;
V_2 -> V_192 = NULL ;
}
static void F_50 ( unsigned long V_220 )
{
unsigned long V_29 ;
unsigned long V_221 = V_189 + V_222 ;
struct V_1 * V_2 ;
struct V_182 * V_196 , * V_192 ;
struct V_223 * V_224 ;
struct V_223 * V_225 ;
struct V_134 * V_3 = V_226 ;
T_3 V_227 = 0 ;
unsigned long V_188 ;
int V_142 = V_198 ;
struct V_223 V_228 ;
F_51 ( & V_228 ) ;
F_40 ( & V_3 -> V_229 , V_29 ) ;
F_52 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_2 = F_53 ( V_225 , struct V_1 , V_230 ) ;
if ( ( V_2 -> V_192 ) || ( V_2 -> V_196 ) ) {
F_2 ( V_2 ) ;
F_54 ( & V_2 -> V_231 , & V_228 ) ;
}
}
F_41 ( & V_3 -> V_229 , V_29 ) ;
F_52 (list_node, list_core_temp, &timer_list) {
V_2 = F_53 ( V_225 , struct V_1 ,
V_231 ) ;
V_192 = V_2 -> V_192 ;
if ( V_192 ) {
if ( F_55 ( V_192 -> V_188 , V_189 ) ) {
if ( V_221 > V_192 -> V_188 ||
! V_227 ) {
V_221 = V_192 -> V_188 ;
V_227 = 1 ;
}
} else {
F_48 ( V_2 , 1 ) ;
}
}
F_40 ( & V_2 -> V_195 , V_29 ) ;
do {
V_196 = V_2 -> V_196 ;
if ( ! V_196 )
break;
if ( F_55 ( V_196 -> V_188 , V_189 ) ) {
if ( V_2 -> V_32 != V_232 ) {
if ( ( V_221 >
V_196 -> V_188 ) ||
! V_227 ) {
V_221 =
V_196 -> V_188 ;
V_227 = 1 ;
}
} else {
F_56 ( V_2 ) ;
}
break;
}
if ( ( V_2 -> V_32 == V_232 ) ||
( V_2 -> V_32 == V_203 ) ) {
F_56 ( V_2 ) ;
break;
}
if ( ! V_196 -> V_186 ||
! V_196 -> V_184 ) {
V_233 ++ ;
F_56 ( V_2 ) ;
F_41 (
& V_2 -> V_195 , V_29 ) ;
F_46 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
F_40 ( & V_2 -> V_195 ,
V_29 ) ;
break;
}
F_39 ( & V_196 -> V_16 -> V_194 ) ;
V_234 ++ ;
F_7 ( V_14 , L_36
L_37
L_38
L_39
L_40 , V_196 , V_2 , V_189 ,
V_196 -> V_188 ,
V_196 -> V_186 ,
V_196 -> V_193 ,
V_2 -> V_109 . V_235 ) ;
F_41 ( & V_2 -> V_195 ,
V_29 ) ;
V_142 = F_42 ( V_196 -> V_16 , V_2 -> V_90 ) ;
F_40 ( & V_2 -> V_195 , V_29 ) ;
if ( V_142 != V_198 ) {
F_7 ( V_14 , L_41
L_42 , V_2 ) ;
V_236 ++ ;
V_196 -> V_184 -- ;
V_221 = V_189 + V_237 ;
V_227 = 1 ;
break;
} else {
V_199 ++ ;
}
F_7 ( V_14 , L_43
L_44 ,
V_196 -> V_186 ,
V_196 -> V_184 ) ;
if ( V_196 -> V_180 ) {
V_196 -> V_186 -- ;
V_188 = ( V_197 <<
( V_187 - V_196 -> V_186 ) ) ;
V_196 -> V_188 = V_189 +
F_57 ( V_188 , V_238 ) ;
if ( V_221 > V_196 -> V_188 ||
! V_227 ) {
V_221 = V_196 -> V_188 ;
V_227 = 1 ;
}
} else {
int V_181 ;
V_181 =
V_196 -> V_181 ;
F_7 ( V_14 , L_45 ,
V_2 , V_2 -> V_32 ) ;
F_56 ( V_2 ) ;
if ( V_181 )
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
} while ( 0 );
F_41 ( & V_2 -> V_195 , V_29 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_227 ) {
if ( ! F_44 ( & V_3 -> V_200 ) )
F_45 ( & V_3 -> V_200 , V_221 ) ;
}
}
static int F_58 ( struct V_1 * V_2 , T_3 V_239 ,
struct V_15 * V_16 )
{
int V_142 ;
int V_29 = V_123 ;
char V_240 [ sizeof( struct V_241 ) +
sizeof( struct V_242 ) + sizeof( struct V_243 ) +
V_244 ] ;
int V_245 = 0 ;
union V_246 * V_75 ;
if ( ! V_2 )
return - V_43 ;
V_75 = (union V_246 * ) & V_240 [ V_245 ] ;
V_75 -> V_247 . V_248 = V_249 ;
V_75 -> V_247 . V_250 = sizeof( struct V_241 ) ;
V_75 -> V_247 . V_251 = F_22 ( V_2 -> V_109 . V_251 ) ;
V_245 += sizeof( struct V_241 ) ;
V_75 = (union V_246 * ) & V_240 [ V_245 ] ;
V_75 -> V_252 . V_248 = V_253 ;
V_75 -> V_252 . V_250 = sizeof( struct V_242 ) ;
V_75 -> V_252 . V_254 = V_2 -> V_109 . V_255 ;
V_245 += sizeof( struct V_242 ) ;
if ( V_239 && ! ( V_256 & V_257 ) ) {
V_75 = (union V_246 * ) & V_240 [ V_245 ] ;
V_75 -> V_258 . V_248 = V_259 ;
V_75 -> V_258 . V_250 = sizeof( struct V_243 ) ;
V_245 += sizeof( struct V_243 ) ;
V_75 = (union V_246 * ) & V_240 [ V_245 ] ;
V_75 -> V_260 = 1 ;
V_245 += 1 ;
V_75 = (union V_246 * ) & V_240 [ V_245 ] ;
V_75 -> V_260 = 1 ;
V_245 += 1 ;
}
V_75 = (union V_246 * ) & V_240 [ V_245 ] ;
V_75 -> V_260 = V_261 ;
V_245 += 1 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
if ( V_239 )
V_29 |= V_22 ;
F_11 ( V_16 , V_2 , V_240 , V_245 , NULL , 0 , V_29 ) ;
V_142 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_142 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_142 ;
int V_29 = V_126 | V_22 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - V_27 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_29 ) ;
V_142 = F_12 ( V_2 , V_16 , V_23 , 0 , 1 ) ;
return V_142 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_142 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 ) ;
V_142 = F_12 ( V_2 , V_16 , V_23 , 0 , 0 ) ;
return V_142 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_142 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 | V_31 ) ;
V_142 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_142 ;
}
static struct V_1 * F_61 ( struct V_134 * V_3 ,
T_2 V_12 , T_5 V_10 , T_2 V_13 , T_5 V_11 )
{
unsigned long V_29 ;
struct V_223 * V_262 ;
struct V_1 * V_2 ;
V_262 = & V_3 -> V_263 ;
F_40 ( & V_3 -> V_229 , V_29 ) ;
F_62 (cm_node, hte, list) {
F_7 ( V_14 , L_46 ,
V_2 -> V_11 , V_2 -> V_13 ,
V_11 , V_13 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_10 , V_12 ) ;
if ( ( V_2 -> V_11 == V_11 ) && ( V_2 -> V_13 == V_13 ) &&
( V_2 -> V_10 == V_10 ) && ( V_2 -> V_12 == V_12 ) ) {
F_2 ( V_2 ) ;
F_41 ( & V_3 -> V_229 , V_29 ) ;
return V_2 ;
}
}
F_41 ( & V_3 -> V_229 , V_29 ) ;
return NULL ;
}
static struct V_264 * F_63 ( struct V_134 * V_3 ,
T_5 V_265 , T_2 V_266 , enum V_267 V_268 )
{
unsigned long V_29 ;
struct V_264 * V_269 ;
F_40 ( & V_3 -> V_270 , V_29 ) ;
F_62 (listen_node, &cm_core->listen_list.list, list) {
if ( ( ( V_269 -> V_11 == V_265 ) ||
V_269 -> V_11 == 0x00000000 ) &&
( V_269 -> V_13 == V_266 ) &&
( V_268 & V_269 -> V_268 ) ) {
F_39 ( & V_269 -> V_271 ) ;
F_41 ( & V_3 -> V_270 , V_29 ) ;
return V_269 ;
}
}
F_41 ( & V_3 -> V_270 , V_29 ) ;
return NULL ;
}
static int F_64 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_223 * V_262 ;
if ( ! V_2 || ! V_3 )
return - V_43 ;
F_7 ( V_14 , L_47 ,
V_2 ) ;
F_40 ( & V_3 -> V_229 , V_29 ) ;
V_262 = & V_3 -> V_263 ;
F_65 ( & V_2 -> V_230 , V_262 ) ;
F_39 ( & V_3 -> V_272 ) ;
F_41 ( & V_3 -> V_229 , V_29 ) ;
return 0 ;
}
static int F_66 ( struct V_134 * V_3 ,
struct V_264 * V_273 , int V_274 )
{
int V_142 = - V_43 ;
int V_275 = 0 ;
unsigned long V_29 ;
struct V_223 * V_276 = NULL ;
struct V_223 * V_277 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_223 V_278 ;
F_7 ( V_14 , L_48
L_49 , V_273 , V_274 ,
F_26 ( & V_273 -> V_271 ) ) ;
F_51 ( & V_278 ) ;
if ( V_274 ) {
F_40 ( & V_3 -> V_229 , V_29 ) ;
F_52 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_53 ( V_276 , struct V_1 ,
V_230 ) ;
if ( ( V_2 -> V_273 == V_273 ) &&
( ! V_2 -> V_279 ) ) {
F_2 ( V_2 ) ;
F_54 ( & V_2 -> V_280 , & V_278 ) ;
}
}
F_41 ( & V_3 -> V_229 , V_29 ) ;
}
F_52 (list_pos, list_temp, &reset_list) {
V_2 = F_53 ( V_276 , struct V_1 ,
V_280 ) ;
{
struct V_1 * V_281 = V_2 -> V_282 ;
enum V_202 V_283 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_281 ) {
F_43 ( V_2 ) ;
V_275 = F_47 ( V_2 , NULL ) ;
if ( V_275 ) {
V_2 -> V_32 =
V_203 ;
F_36 ( 1 ) ;
} else {
V_283 = V_2 -> V_32 ;
V_2 -> V_32 = V_284 ;
if ( V_283 != V_285 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_281 ;
V_6 . V_9 . V_10 =
V_281 -> V_10 ;
V_6 . V_9 . V_11 =
V_281 -> V_11 ;
V_6 . V_9 . V_12 =
V_281 -> V_12 ;
V_6 . V_9 . V_13 =
V_281 -> V_13 ;
V_6 . V_9 . V_7 = V_281 -> V_7 ;
F_2 ( V_281 ) ;
V_281 -> V_32 = V_203 ;
F_67 ( & V_6 ) ;
V_2 -> V_32 = V_284 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_40 ( & V_3 -> V_270 , V_29 ) ;
if ( ! F_68 ( & V_273 -> V_271 ) ) {
F_69 ( & V_273 -> V_230 ) ;
F_70 ( & V_3 -> V_136 ) ;
F_41 ( & V_3 -> V_270 , V_29 ) ;
if ( V_273 -> V_286 )
F_71 ( V_273 -> V_286 , V_273 -> V_13 ,
F_72 ( V_273 -> V_286 -> V_287 -> V_288 -> V_289 ) , V_290 ) ;
F_7 ( V_14 , L_50 , V_273 ) ;
F_35 ( V_273 ) ;
V_273 = NULL ;
V_142 = 0 ;
F_39 ( & V_291 ) ;
} else {
F_41 ( & V_3 -> V_270 , V_29 ) ;
}
if ( V_273 ) {
if ( F_26 ( & V_273 -> V_292 ) > 0 )
F_7 ( V_14 , L_51
L_52 ,
V_273 , F_26 ( & V_273 -> V_292 ) ) ;
}
return V_142 ;
}
static int F_73 ( struct V_134 * V_3 ,
struct V_264 * V_273 )
{
V_273 -> V_268 = V_293 ;
V_273 -> V_7 = NULL ;
return F_66 ( V_3 , V_273 , 1 ) ;
}
static inline int F_74 ( struct V_134 * V_3 ,
struct V_1 * V_2 )
{
V_2 -> V_279 = 1 ;
if ( V_2 -> V_294 ) {
F_75 ( ! V_2 -> V_273 ) ;
F_70 ( & V_2 -> V_273 -> V_292 ) ;
V_2 -> V_294 = 0 ;
F_75 ( F_26 ( & V_2 -> V_273 -> V_292 ) < 0 ) ;
}
if ( ! F_44 ( & V_3 -> V_200 ) )
F_45 ( & V_3 -> V_200 , ( V_189 + V_237 ) ) ;
return 0 ;
}
static int F_76 ( struct V_295 * V_286 , T_3 V_296 , int V_297 )
{
struct V_298 * V_299 ;
struct V_300 * V_301 ;
int V_302 = V_297 ;
struct V_303 * V_90 ;
struct V_304 * V_305 = V_286 -> V_287 -> V_305 ;
V_299 = F_77 ( & V_306 , F_23 ( V_296 ) , 0 , 0 , 0 ) ;
if ( F_78 ( V_299 ) ) {
F_79 ( V_307 L_53 ,
V_67 , V_296 ) ;
return V_302 ;
}
if ( F_80 ( V_286 -> V_90 ) )
V_90 = F_81 ( V_286 -> V_90 ) ;
else
V_90 = V_286 -> V_90 ;
V_301 = F_82 ( & V_308 , & V_299 -> V_309 , V_90 ) ;
F_83 () ;
if ( V_301 ) {
if ( V_301 -> V_310 & V_311 ) {
F_7 ( V_14 , L_54
L_55 , V_296 ,
V_301 -> V_312 , F_37 ( V_299 -> V_309 ) ) ;
if ( V_297 >= 0 ) {
if ( F_84 ( V_305 -> V_313 [ V_297 ] . V_314 , V_301 -> V_312 ) ) {
goto V_315;
}
F_85 ( V_286 -> V_90 ,
V_305 -> V_313 [ V_297 ] . V_314 ,
V_296 , V_316 ) ;
}
F_85 ( V_286 -> V_90 , V_301 -> V_312 ,
V_296 , V_317 ) ;
V_302 = F_86 ( V_286 -> V_287 , V_296 , NULL ,
V_318 ) ;
} else {
F_87 ( V_301 , NULL ) ;
}
}
V_315:
F_88 () ;
if ( V_301 )
F_89 ( V_301 ) ;
F_90 ( V_299 ) ;
return V_302 ;
}
static struct V_1 * F_91 ( struct V_134 * V_3 ,
struct V_295 * V_286 , struct V_319 * V_9 ,
struct V_264 * V_273 )
{
struct V_1 * V_2 ;
struct V_320 V_321 ;
int V_322 = 0 ;
int V_297 = 0 ;
struct V_323 * V_287 ;
struct V_304 * V_305 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_48 = V_324 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_64 = 0 ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
F_7 ( V_14 , L_56 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_273 = V_273 ;
V_2 -> V_90 = V_286 -> V_90 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_101 , V_286 -> V_90 -> V_325 , V_99 ) ;
F_7 ( V_14 , L_57 , V_2 -> V_273 ,
V_2 -> V_7 ) ;
F_92 ( & V_2 -> V_195 ) ;
V_2 -> V_282 = NULL ;
F_93 ( & V_2 -> V_271 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_109 . V_110 = V_326 ;
V_2 -> V_109 . V_255 = V_327 ;
V_2 -> V_109 . V_130 = V_328 >>
V_327 ;
V_321 = F_94 () ;
V_2 -> V_109 . V_118 = F_23 ( V_321 . V_329 ) ;
V_2 -> V_109 . V_251 = V_286 -> V_330 - sizeof( struct V_81 ) -
sizeof( struct V_79 ) - V_87 - V_331 ;
V_2 -> V_109 . V_120 = 0 ;
F_39 ( & V_3 -> V_137 ) ;
V_2 -> V_332 = V_9 -> V_332 ;
V_2 -> V_333 = 0 ;
V_2 -> V_294 = 0 ;
V_2 -> V_286 = V_286 ;
V_287 = V_286 -> V_287 ;
V_305 = V_287 -> V_305 ;
V_2 -> V_282 = NULL ;
V_322 = F_86 ( V_287 , V_2 -> V_10 , NULL , V_318 ) ;
V_297 = F_76 ( V_286 , V_9 -> V_10 , V_322 ) ;
if ( V_297 < 0 ) {
F_35 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_98 , V_305 -> V_313 [ V_297 ] . V_314 , V_99 ) ;
F_7 ( V_14 , L_58 ,
V_2 -> V_98 ) ;
F_64 ( V_3 , V_2 ) ;
F_39 ( & V_334 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_271 ) ;
return 0 ;
}
static int F_4 ( struct V_134 * V_3 ,
struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_146 * V_149 ;
if ( ! V_2 )
return - V_43 ;
F_40 ( & V_2 -> V_3 -> V_229 , V_29 ) ;
if ( F_68 ( & V_2 -> V_271 ) ) {
F_41 ( & V_2 -> V_3 -> V_229 , V_29 ) ;
return 0 ;
}
F_69 ( & V_2 -> V_230 ) ;
F_70 ( & V_3 -> V_272 ) ;
F_41 ( & V_2 -> V_3 -> V_229 , V_29 ) ;
if ( ! V_2 -> V_279 && V_2 -> V_294 ) {
F_75 ( ! V_2 -> V_273 ) ;
F_70 ( & V_2 -> V_273 -> V_292 ) ;
F_75 ( F_26 ( & V_2 -> V_273 -> V_292 ) < 0 ) ;
}
F_36 ( V_2 -> V_196 ) ;
if ( V_2 -> V_192 )
F_48 ( V_2 , 0 ) ;
if ( V_2 -> V_273 ) {
F_66 ( V_3 , V_2 -> V_273 , 0 ) ;
} else {
if ( V_2 -> V_333 && V_2 -> V_286 ) {
F_71 ( V_2 -> V_286 , V_2 -> V_13 ,
F_72 (
V_2 -> V_286 -> V_287 -> V_288 -> V_289 ) ,
V_290 ) ;
}
}
F_70 ( & V_3 -> V_137 ) ;
F_39 ( & V_335 ) ;
V_149 = V_2 -> V_149 ;
if ( V_149 ) {
V_149 -> V_2 = NULL ;
F_95 ( & V_149 -> V_336 ) ;
V_2 -> V_149 = NULL ;
}
F_35 ( V_2 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , T_1 * V_337 ,
T_3 V_76 , T_3 V_338 )
{
T_3 V_339 ;
T_3 V_340 = 0 ;
union V_246 * V_341 ;
char V_342 = 0 ;
while ( V_340 < V_76 ) {
V_341 = (union V_246 * ) ( V_337 + V_340 ) ;
switch ( V_341 -> V_258 . V_248 ) {
case V_261 :
V_340 = V_76 ;
break;
case V_343 :
V_340 += 1 ;
continue;
case V_249 :
F_7 ( V_14 , L_59
L_60 , V_67 ,
V_341 -> V_247 . V_250 , V_340 , V_76 ) ;
V_342 = 1 ;
if ( V_341 -> V_247 . V_250 != 4 ) {
return 1 ;
} else {
V_339 = F_16 ( V_341 -> V_247 . V_251 ) ;
if ( V_339 > 0 && V_339 <
V_2 -> V_109 . V_251 )
V_2 -> V_109 . V_251 = V_339 ;
}
break;
case V_253 :
V_2 -> V_109 . V_344 =
V_341 -> V_252 . V_254 ;
break;
default:
F_7 ( V_14 , L_61 ,
V_341 -> V_258 . V_248 ) ;
break;
}
V_340 += V_341 -> V_258 . V_250 ;
}
if ( ( ! V_342 ) && ( V_338 ) )
V_2 -> V_109 . V_251 = V_345 ;
return 0 ;
}
static void F_97 ( struct V_15 * V_16 )
{
F_39 ( & V_346 ) ;
F_98 ( V_16 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_62
L_49 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_271 ) ) ;
switch ( V_2 -> V_32 ) {
case V_204 :
case V_347 :
case V_348 :
case V_349 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_206 ;
F_60 ( V_2 , NULL ) ;
break;
case V_49 :
F_5 ( V_2 , V_208 ) ;
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
F_2 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_33 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_205 ;
F_59 ( V_2 , NULL ) ;
break;
case V_350 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_351 ;
F_59 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_190 , 1 , 0 ) ;
break;
case V_351 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_232 :
default:
F_7 ( V_14 , L_63 ,
V_2 , V_2 -> V_32 ) ;
break;
}
}
static void F_100 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_352 = 0 ;
F_39 ( & V_353 ) ;
F_7 ( V_14 , L_64
L_65 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_271 ) ) ;
F_43 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_347 :
case V_49 :
F_7 ( V_14 , L_66
L_67 , V_67 , __LINE__ , V_2 ,
V_2 -> V_273 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_347 ;
if ( F_58 ( V_2 , 0 , NULL ) ) {
F_101 ( V_2 , V_16 , V_352 ) ;
}
break;
case V_46 :
default:
F_101 ( V_2 , V_16 , V_352 ) ;
break;
}
break;
case V_285 :
F_39 ( & V_2 -> V_354 ) ;
F_98 ( V_16 ) ;
break;
case V_348 :
case V_204 :
case V_355 :
F_7 ( V_14 , L_68 , V_67 , __LINE__ ) ;
F_102 ( V_2 , V_16 , V_352 ) ;
break;
case V_232 :
F_101 ( V_2 , V_16 , V_352 ) ;
break;
case V_203 :
F_97 ( V_16 ) ;
break;
case V_350 :
case V_33 :
case V_206 :
V_2 -> V_7 -> V_207 ( V_2 -> V_7 ) ;
case V_351 :
V_2 -> V_32 = V_203 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_97 ( V_16 ) ;
break;
default:
F_97 ( V_16 ) ;
break;
}
}
static void F_103 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_142 = 0 ;
int V_78 = V_16 -> V_35 ;
T_1 * V_356 = V_16 -> V_77 ;
enum V_5 type = V_357 ;
T_3 V_358 ;
V_142 = F_15 ( V_2 , V_356 , & V_358 , V_78 ) ;
if ( V_142 ) {
F_7 ( V_14 , L_69 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_70
L_71 , V_67 ,
__LINE__ , V_2 , V_2 -> V_273 ,
V_2 -> V_32 ) ;
F_101 ( V_2 , V_16 , 1 ) ;
} else {
F_102 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_348 :
if ( V_358 == V_74 )
F_36 ( 1 ) ;
V_2 -> V_32 = V_285 ;
type = V_359 ;
F_93 ( & V_2 -> V_354 ,
V_360 ) ;
break;
case V_49 :
F_43 ( V_2 ) ;
if ( V_358 == V_74 ) {
type = V_361 ;
V_2 -> V_32 = V_349 ;
} else {
type = V_362 ;
V_2 -> V_32 = V_232 ;
}
break;
default:
F_36 ( 1 ) ;
break;
}
F_98 ( V_16 ) ;
F_5 ( V_2 , type ) ;
}
static void F_104 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_2 -> V_32 ) {
case V_347 :
case V_49 :
F_7 ( V_14 , L_66
L_67 , V_67 , __LINE__ , V_2 ,
V_2 -> V_273 , V_2 -> V_32 ) ;
F_101 ( V_2 , V_16 , 1 ) ;
break;
case V_348 :
case V_204 :
F_102 ( V_2 , V_16 , 1 ) ;
break;
case V_232 :
default:
F_97 ( V_16 ) ;
}
}
static int F_105 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 )
{
int V_275 ;
V_275 = ( ( F_37 ( V_80 -> V_121 ) == V_2 -> V_109 . V_118 ) ) ? 0 : 1 ;
if ( V_275 )
F_101 ( V_2 , V_16 , 1 ) ;
return V_275 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 )
{
int V_275 = 0 ;
T_3 V_117 ;
T_3 V_121 ;
T_3 V_118 = V_2 -> V_109 . V_118 ;
T_3 V_120 = V_2 -> V_109 . V_120 ;
T_3 V_130 ;
V_117 = F_37 ( V_80 -> V_117 ) ;
V_121 = F_37 ( V_80 -> V_121 ) ;
V_130 = V_2 -> V_109 . V_130 ;
if ( V_121 != V_118 )
V_275 = 1 ;
else if ( ! F_107 ( V_117 , V_120 , ( V_120 + V_130 ) ) )
V_275 = 1 ;
if ( V_275 ) {
F_7 ( V_14 , L_66
L_67 , V_67 , __LINE__ , V_2 ,
V_2 -> V_273 , V_2 -> V_32 ) ;
F_104 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_72
L_73 , V_2 , V_117 , V_120 ,
V_130 ) ;
}
return V_275 ;
}
static void F_108 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_142 ;
T_3 V_363 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_363 = F_37 ( V_80 -> V_117 ) ;
switch ( V_2 -> V_32 ) {
case V_347 :
case V_49 :
F_101 ( V_2 , V_16 , 1 ) ;
break;
case V_355 :
if ( F_26 ( & V_2 -> V_273 -> V_292 ) >
V_2 -> V_273 -> V_364 ) {
F_7 ( V_14 , L_74
L_75 ) ;
V_365 ++ ;
F_102 ( V_2 , V_16 , 0 ) ;
break;
}
V_142 = F_109 ( V_2 , V_80 , V_16 , V_76 ,
1 ) ;
if ( V_142 ) {
F_102 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_109 . V_120 = V_363 + 1 ;
F_75 ( V_2 -> V_196 ) ;
V_2 -> V_294 = 1 ;
F_39 ( & V_2 -> V_273 -> V_292 ) ;
V_2 -> V_32 = V_204 ;
F_58 ( V_2 , 1 , V_16 ) ;
break;
case V_203 :
F_43 ( V_2 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
break;
case V_232 :
case V_348 :
case V_33 :
case V_350 :
case V_285 :
case V_206 :
case V_205 :
case V_366 :
default:
F_97 ( V_16 ) ;
break;
}
}
static void F_110 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_142 ;
T_3 V_363 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_363 = F_37 ( V_80 -> V_117 ) ;
switch ( V_2 -> V_32 ) {
case V_347 :
F_43 ( V_2 ) ;
if ( F_105 ( V_2 , V_80 , V_16 ) )
return;
V_2 -> V_109 . V_235 = F_37 ( V_80 -> V_121 ) ;
V_142 = F_109 ( V_2 , V_80 , V_16 , V_76 , 0 ) ;
if ( V_142 ) {
F_7 ( V_14 , L_76 ,
V_2 ) ;
break;
}
F_43 ( V_2 ) ;
V_2 -> V_109 . V_120 = V_363 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_285 :
F_102 ( V_2 , V_16 , 1 ) ;
break;
case V_355 :
V_2 -> V_109 . V_118 = F_37 ( V_80 -> V_121 ) ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
F_47 ( V_2 , V_16 ) ;
break;
case V_203 :
V_2 -> V_109 . V_118 = F_37 ( V_80 -> V_121 ) ;
F_43 ( V_2 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
break;
case V_348 :
case V_33 :
case V_350 :
case V_206 :
case V_232 :
case V_205 :
case V_366 :
case V_49 :
default:
F_97 ( V_16 ) ;
break;
}
}
static int F_111 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_78 = 0 ;
T_3 V_363 ;
int V_142 = 0 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
if ( F_106 ( V_2 , V_80 , V_16 ) )
return - V_43 ;
F_112 ( V_16 , V_80 -> V_128 << 2 ) ;
V_363 = F_37 ( V_80 -> V_117 ) ;
V_78 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_204 :
F_43 ( V_2 ) ;
V_142 = F_109 ( V_2 , V_80 , V_16 , V_76 , 1 ) ;
if ( V_142 )
break;
V_2 -> V_109 . V_235 = F_37 ( V_80 -> V_121 ) ;
V_2 -> V_32 = V_348 ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_363 + V_78 ;
F_103 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
}
break;
case V_348 :
F_43 ( V_2 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_363 + V_78 ;
F_103 ( V_2 , V_16 ) ;
} else {
F_97 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_109 . V_235 = F_37 ( V_80 -> V_121 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_363 + V_78 ;
F_103 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
}
break;
case V_355 :
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
F_47 ( V_2 , V_16 ) ;
break;
case V_203 :
F_43 ( V_2 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
break;
case V_206 :
case V_205 :
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
V_2 -> V_7 -> V_207 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_97 ( V_16 ) ;
break;
case V_33 :
F_43 ( V_2 ) ;
F_97 ( V_16 ) ;
V_2 -> V_32 = V_350 ;
break;
case V_347 :
case V_350 :
case V_232 :
case V_285 :
case V_366 :
default:
F_43 ( V_2 ) ;
F_97 ( V_16 ) ;
break;
}
return V_142 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 , int V_76 , int V_367 )
{
T_1 * V_337 = ( T_1 * ) & V_80 [ 1 ] ;
if ( V_76 ) {
if ( F_96 ( V_2 , V_337 , V_76 ,
( T_3 ) V_80 -> V_124 ) ) {
F_7 ( V_14 , L_77 ,
V_67 , V_2 ) ;
if ( V_367 )
F_102 ( V_2 , V_16 , 1 ) ;
else
F_101 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_109 . V_368 = F_16 ( V_80 -> V_129 ) <<
V_2 -> V_109 . V_344 ;
if ( V_2 -> V_109 . V_368 > V_2 -> V_109 . V_369 )
V_2 -> V_109 . V_369 = V_2 -> V_109 . V_368 ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_352 )
{
F_43 ( V_2 ) ;
if ( V_352 ) {
F_7 ( V_14 , L_78
L_79 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
}
V_2 -> V_32 = V_203 ;
F_5 ( V_2 , V_208 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_352 )
{
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
if ( V_352 ) {
F_7 ( V_14 , L_80
L_81 , V_2 , V_2 -> V_32 ) ;
F_47 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_182 * V_196 ;
V_196 = V_2 -> V_196 ;
if ( V_196 ) {
V_2 -> V_196 = NULL ;
F_98 ( V_196 -> V_16 ) ;
F_35 ( V_196 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_40 ( & V_2 -> V_195 , V_29 ) ;
F_56 ( V_2 ) ;
F_41 ( & V_2 -> V_195 , V_29 ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_134 * V_3 )
{
enum V_370 V_371 = V_372 ;
struct V_79 * V_80 = F_38 ( V_16 ) ;
T_3 V_373 = 0 ;
int V_142 = 0 ;
F_112 ( V_16 , F_114 ( V_16 ) -> V_105 << 2 ) ;
F_7 ( V_14 , L_82
L_83 , V_2 , V_2 -> V_32 , V_80 -> V_124 ,
V_80 -> V_122 , V_80 -> V_127 , V_80 -> V_125 ) ;
if ( V_80 -> V_127 ) {
V_371 = V_374 ;
} else if ( V_80 -> V_124 ) {
V_371 = V_375 ;
if ( V_80 -> V_122 )
V_371 = V_376 ;
} else if ( V_80 -> V_122 ) {
V_371 = V_377 ;
}
if ( V_80 -> V_125 )
V_373 = 1 ;
switch ( V_371 ) {
case V_375 :
F_108 ( V_2 , V_16 , V_80 ) ;
break;
case V_376 :
F_110 ( V_2 , V_16 , V_80 ) ;
break;
case V_377 :
V_142 = F_111 ( V_2 , V_16 , V_80 ) ;
if ( V_373 && ! V_142 )
F_99 ( V_2 ) ;
break;
case V_374 :
F_100 ( V_2 , V_16 , V_80 ) ;
break;
default:
if ( ( V_373 ) && ( ! F_106 ( V_2 , V_80 , V_16 ) ) )
F_99 ( V_2 ) ;
F_97 ( V_16 ) ;
break;
}
}
static struct V_264 * F_115 ( struct V_134 * V_3 ,
struct V_295 * V_286 , struct V_319 * V_9 )
{
struct V_264 * V_273 ;
unsigned long V_29 ;
F_7 ( V_14 , L_84 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_273 = F_63 ( V_3 , F_23 ( V_9 -> V_11 ) ,
F_22 ( V_9 -> V_13 ) , V_378 ) ;
if ( V_273 && V_273 -> V_268 == V_379 ) {
F_70 ( & V_273 -> V_271 ) ;
F_7 ( V_14 , L_85 ) ;
return NULL ;
}
if ( ! V_273 ) {
V_273 = F_6 ( sizeof( * V_273 ) , V_8 ) ;
if ( ! V_273 ) {
F_7 ( V_14 , L_86 ) ;
return NULL ;
}
V_273 -> V_11 = F_23 ( V_9 -> V_11 ) ;
V_273 -> V_13 = F_22 ( V_9 -> V_13 ) ;
V_273 -> V_380 = 0 ;
F_93 ( & V_273 -> V_271 , 1 ) ;
}
else {
V_273 -> V_380 = 1 ;
}
V_273 -> V_7 = V_9 -> V_7 ;
F_93 ( & V_273 -> V_292 , 0 ) ;
V_273 -> V_3 = V_3 ;
V_273 -> V_286 = V_286 ;
F_39 ( & V_3 -> V_137 ) ;
V_273 -> V_332 = V_9 -> V_332 ;
V_273 -> V_364 = V_9 -> V_364 ;
V_273 -> V_268 = V_379 ;
if ( ! V_273 -> V_380 ) {
F_40 ( & V_3 -> V_270 , V_29 ) ;
F_54 ( & V_273 -> V_230 , & V_3 -> V_381 . V_230 ) ;
F_41 ( & V_3 -> V_270 , V_29 ) ;
F_39 ( & V_3 -> V_136 ) ;
}
F_7 ( V_14 , L_87
L_88 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_273 , V_273 -> V_364 , V_273 -> V_7 ) ;
return V_273 ;
}
static struct V_1 * F_116 ( struct V_134 * V_3 ,
struct V_295 * V_286 , T_2 V_382 ,
void * V_383 , struct V_319 * V_9 )
{
int V_142 = 0 ;
struct V_1 * V_2 ;
struct V_264 * V_384 ;
struct V_1 * V_385 ;
struct V_319 V_386 ;
T_1 * V_19 ;
V_2 = F_91 ( V_3 , V_286 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_109 . V_387 = 1 ;
V_2 -> V_109 . V_255 = V_327 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_384 = F_63 ( V_3 ,
F_37 ( V_286 -> V_388 ) , V_2 -> V_12 ,
V_379 ) ;
if ( V_384 == NULL ) {
F_5 ( V_2 , V_208 ) ;
} else {
V_386 = * V_9 ;
V_386 . V_13 = V_9 -> V_12 ;
V_386 . V_12 = V_9 -> V_13 ;
V_386 . V_7 = V_384 -> V_7 ;
V_385 = F_91 ( V_3 , V_286 ,
& V_386 , V_384 ) ;
if ( ! V_385 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_39 ( & V_389 ) ;
V_385 -> V_282 = V_2 ;
V_385 -> V_109 . V_255 =
V_327 ;
V_2 -> V_282 = V_385 ;
memcpy ( V_385 -> V_73 , V_383 ,
V_382 ) ;
V_385 -> V_54 = V_382 ;
V_2 -> V_32 = V_232 ;
V_2 -> V_109 . V_120 =
V_385 -> V_109 . V_118 ;
V_385 -> V_109 . V_120 =
V_2 -> V_109 . V_118 ;
V_2 -> V_109 . V_369 =
V_385 -> V_109 . V_130 ;
V_385 -> V_109 . V_369 =
V_2 -> V_109 . V_130 ;
V_2 -> V_109 . V_368 =
V_385 -> V_109 . V_130 ;
V_385 -> V_109 . V_368 =
V_2 -> V_109 . V_130 ;
V_2 -> V_109 . V_344 =
V_385 -> V_109 . V_255 ;
V_385 -> V_109 . V_344 =
V_2 -> V_109 . V_255 ;
V_385 -> V_32 = V_285 ;
F_5 ( V_385 , V_359 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_382 ;
memcpy ( V_19 , V_383 , V_382 ) ;
V_2 -> V_32 = V_347 ;
V_142 = F_58 ( V_2 , 0 , NULL ) ;
if ( V_142 ) {
F_7 ( V_14 , L_89
L_90 ,
V_2 -> V_10 , V_2 -> V_12 , V_2 ,
V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
V_2 = NULL ;
}
if ( V_2 ) {
F_7 ( V_14 , L_91
L_92 ,
V_2 -> V_10 , V_2 -> V_12 , V_2 ,
V_2 -> V_7 ) ;
}
return V_2 ;
}
static int F_117 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_118 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
int V_142 = 0 ;
int V_275 = 0 ;
int V_354 ;
struct V_4 V_6 ;
struct V_201 * V_7 = V_2 -> V_7 ;
struct V_1 * V_281 = V_2 -> V_282 ;
F_7 ( V_14 , L_93 ,
V_67 , V_2 , V_2 -> V_109 . V_387 , V_2 -> V_32 ) ;
if ( V_2 -> V_109 . V_387 )
return V_142 ;
F_43 ( V_2 ) ;
if ( ! V_281 ) {
V_354 = F_119 ( 1 , & V_2 -> V_354 ) ;
if ( V_354 == V_390 ) {
V_2 -> V_32 = V_203 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_284 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_142 = F_13 ( V_2 ) ;
if ( V_142 ) {
V_2 -> V_32 = V_203 ;
V_275 = F_47 ( V_2 , NULL ) ;
if ( V_275 )
F_36 ( 1 ) ;
} else {
V_7 -> V_391 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_284 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_281 ) ;
} else {
V_6 . V_2 = V_281 ;
V_6 . V_9 . V_10 = V_281 -> V_10 ;
V_6 . V_9 . V_11 = V_281 -> V_11 ;
V_6 . V_9 . V_12 = V_281 -> V_12 ;
V_6 . V_9 . V_13 = V_281 -> V_13 ;
V_6 . V_9 . V_7 = V_281 -> V_7 ;
F_120 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_281 -> V_32 = V_205 ;
V_7 = V_281 -> V_7 ;
F_4 ( V_3 , V_281 ) ;
V_7 -> V_207 ( V_7 ) ;
}
}
return V_142 ;
}
static int F_121 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
int V_142 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_204 :
case V_347 :
case V_392 :
case V_348 :
case V_393 :
case V_49 :
case V_285 :
F_43 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_394 :
V_2 -> V_32 = V_206 ;
F_60 ( V_2 , NULL ) ;
break;
case V_33 :
case V_350 :
case V_206 :
case V_351 :
case V_205 :
V_142 = - 1 ;
break;
case V_355 :
F_43 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_349 :
case V_366 :
case V_395 :
case V_203 :
case V_284 :
V_142 = F_4 ( V_3 , V_2 ) ;
break;
case V_232 :
if ( V_2 -> V_196 )
F_79 ( V_307 L_94
L_95 , V_2 -> V_196 ) ;
V_142 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_142 ;
}
static int F_122 ( struct V_134 * V_3 ,
struct V_295 * V_286 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_264 * V_273 = NULL ;
struct V_81 * V_82 ;
struct V_79 * V_80 ;
struct V_319 V_396 ;
int V_397 = 1 ;
T_6 V_398 , V_399 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_81 ) + sizeof( struct V_79 ) )
return 0 ;
V_82 = (struct V_81 * ) V_16 -> V_77 ;
V_80 = (struct V_79 * ) ( V_16 -> V_77 + sizeof( struct V_81 ) ) ;
V_396 . V_11 = F_37 ( V_82 -> V_114 ) ;
V_396 . V_13 = F_16 ( V_80 -> V_116 ) ;
V_396 . V_10 = F_37 ( V_82 -> V_113 ) ;
V_396 . V_12 = F_16 ( V_80 -> V_115 ) ;
V_398 = F_123 ( V_82 -> V_114 ) ;
V_399 = F_123 ( V_82 -> V_113 ) ;
F_7 ( V_14 , L_96 ,
& V_398 , V_80 -> V_116 , & V_399 , V_80 -> V_115 ) ;
do {
V_2 = F_61 ( V_3 ,
V_396 . V_12 , V_396 . V_10 ,
V_396 . V_13 , V_396 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_80 -> V_124 ) || ( V_80 -> V_122 ) ) {
V_397 = 0 ;
break;
}
V_273 = F_63 ( V_3 , V_396 . V_11 ,
V_396 . V_13 ,
V_379 ) ;
if ( ! V_273 ) {
V_396 . V_7 = NULL ;
V_396 . V_332 = 0 ;
F_7 ( V_14 , L_97 ) ;
V_397 = 0 ;
break;
}
V_396 . V_7 = V_273 -> V_7 ;
V_396 . V_332 = V_273 -> V_332 ;
V_2 = F_91 ( V_3 , V_286 , & V_396 ,
V_273 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_98
L_99 ) ;
V_233 ++ ;
F_70 ( & V_273 -> V_271 ) ;
F_98 ( V_16 ) ;
break;
}
if ( ! V_80 -> V_127 && ! V_80 -> V_125 ) {
V_2 -> V_32 = V_355 ;
} else {
V_233 ++ ;
F_4 ( V_3 , V_2 ) ;
F_98 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_232 ) {
if ( V_2 -> V_149 -> V_400 )
F_124 ( V_16 , V_286 , V_2 -> V_149 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_39 ( & V_346 ) ;
F_98 ( V_16 ) ;
}
break;
}
F_125 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_80 ) ) ;
V_16 -> V_35 = F_16 ( V_82 -> V_107 ) ;
F_113 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_397 ;
}
static struct V_134 * F_126 ( void )
{
struct V_134 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_401 ) ;
if ( ! V_3 )
return NULL ;
F_51 ( & V_3 -> V_263 ) ;
F_127 ( & V_3 -> V_200 ) ;
V_3 -> V_200 . V_402 = F_50 ;
V_3 -> V_403 = V_404 ;
V_3 -> V_32 = V_395 ;
V_3 -> V_405 = V_406 ;
F_93 ( & V_3 -> V_407 , 0 ) ;
V_3 -> V_408 = & V_409 ;
F_92 ( & V_3 -> V_229 ) ;
F_92 ( & V_3 -> V_270 ) ;
F_51 ( & V_3 -> V_381 . V_230 ) ;
F_7 ( V_14 , L_100 , V_3 ) ;
F_7 ( V_14 , L_101 ) ;
V_3 -> V_410 = F_128 ( L_102 ) ;
V_3 -> V_411 = F_8 ;
F_7 ( V_14 , L_103 ) ;
V_3 -> V_412 = F_128 ( L_104 ) ;
F_25 ( V_3 ) ;
return V_3 ;
}
static int F_129 ( struct V_134 * V_3 )
{
F_7 ( V_14 , L_105 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_130 () ;
if ( F_44 ( & V_3 -> V_200 ) )
F_131 ( & V_3 -> V_200 ) ;
F_132 ( V_3 -> V_410 ) ;
F_132 ( V_3 -> V_412 ) ;
F_7 ( V_14 , L_106 ) ;
F_35 ( V_3 ) ;
return 0 ;
}
static int F_133 ( struct V_134 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_134 ( struct V_134 * V_3 , T_3 type , T_3 V_413 )
{
int V_142 = 0 ;
switch ( type ) {
case V_414 :
V_3 -> V_403 = V_413 ;
break;
case V_415 :
V_3 -> V_405 = V_413 ;
break;
default:
V_142 = - V_43 ;
}
return V_142 ;
}
static int F_135 ( struct V_146 * V_149 , struct V_1 * V_2 )
{
int V_142 = 0 ;
if ( ! V_149 )
return - V_43 ;
V_149 -> V_172 -> V_416 |= F_32 ( V_417 |
V_418 | V_419 |
V_420 ) ;
if ( V_2 -> V_109 . V_344 || V_2 -> V_109 . V_255 )
V_149 -> V_172 -> V_416 |= F_32 ( V_421 ) ;
V_149 -> V_172 -> V_422 |= F_32 ( 64 << V_423 ) ;
V_149 -> V_172 -> V_251 |= F_32 ( ( ( T_3 ) V_2 -> V_109 . V_251 ) << 16 ) ;
V_149 -> V_172 -> V_424 |= F_32 (
( T_3 ) V_425 << V_426 ) ;
V_149 -> V_172 -> V_427 |= F_32 (
( V_2 -> V_109 . V_344 << V_428 ) &
V_429 ) ;
V_149 -> V_172 -> V_427 |= F_32 (
( V_2 -> V_109 . V_255 << V_430 ) &
V_431 ) ;
V_149 -> V_172 -> V_432 = F_32 ( 0x80 ) ;
V_149 -> V_172 -> V_433 = 0 ;
V_149 -> V_172 -> V_434 = 0 ;
V_149 -> V_172 -> V_435 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_368 = F_32 ( V_2 -> V_109 . V_368 ) ;
V_149 -> V_172 -> V_120 = F_32 ( V_2 -> V_109 . V_120 ) ;
V_149 -> V_172 -> V_130 = F_32 ( V_2 -> V_109 . V_130 <<
V_2 -> V_109 . V_255 ) ;
V_149 -> V_172 -> V_436 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_437 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_438 = 0 ;
V_149 -> V_172 -> V_439 = F_32 ( 0x6 ) ;
V_149 -> V_172 -> V_440 = F_32 ( 0x3FFFC000 ) ;
V_149 -> V_172 -> V_441 = F_32 ( 2 * V_2 -> V_109 . V_251 ) ;
V_149 -> V_172 -> V_442 = F_32 ( V_2 -> V_109 . V_120 ) ;
V_149 -> V_172 -> V_443 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_369 = F_32 ( V_2 -> V_109 . V_369 ) ;
F_7 ( V_14 , L_107
L_108 ,
V_149 -> V_152 . V_212 , F_136 ( V_149 -> V_172 -> V_120 ) ,
F_136 ( V_149 -> V_172 -> V_435 ) ,
V_2 -> V_109 . V_251 , F_136 ( V_149 -> V_172 -> V_427 ) ,
F_136 ( V_149 -> V_172 -> V_130 ) ,
F_136 ( V_149 -> V_172 -> V_416 ) ) ;
F_7 ( V_14 , L_109 , F_136 ( V_149 -> V_172 -> V_368 ) ) ;
F_7 ( V_14 , L_110 , F_136 ( V_149 -> V_172 -> V_441 ) ) ;
F_7 ( V_14 , L_111 , F_136 ( V_149 -> V_172 -> V_369 ) ) ;
F_7 ( V_14 , L_112 ) ;
V_2 -> V_32 = V_232 ;
return V_142 ;
}
int F_49 ( struct V_146 * V_149 )
{
struct V_444 * V_445 ;
V_445 = F_6 ( sizeof *V_445 , V_8 ) ;
if ( ! V_445 )
return - V_27 ;
F_137 ( & V_149 -> V_336 ) ;
V_445 -> V_149 = V_149 ;
F_138 ( & V_445 -> V_445 , V_446 ) ;
F_139 ( V_226 -> V_412 , & V_445 -> V_445 ) ;
return 0 ;
}
static void V_446 ( struct V_447 * V_445 )
{
struct V_444 * V_448 = F_53 ( V_445 , struct V_444 , V_445 ) ;
struct V_146 * V_149 = V_448 -> V_149 ;
F_35 ( V_448 ) ;
F_7 ( V_14 , L_113 ,
V_149 -> V_216 , V_149 -> V_152 . V_212 ) ;
F_140 ( V_149 ) ;
F_95 ( & V_149 -> V_336 ) ;
}
static int F_140 ( struct V_146 * V_149 )
{
unsigned long V_29 ;
int V_142 = 0 ;
struct V_201 * V_7 ;
struct V_449 V_450 ;
struct V_295 * V_286 ;
T_2 V_451 ;
T_1 V_452 ;
T_1 V_453 ;
int V_454 = 0 ;
int V_455 = 0 ;
int V_456 = 0 ;
int V_457 = 0 ;
T_3 V_458 = V_459 ;
struct V_460 V_461 ;
if ( ! V_149 ) {
F_7 ( V_14 , L_114 ) ;
return - 1 ;
}
F_40 ( & V_149 -> V_211 , V_29 ) ;
V_7 = V_149 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_115 ,
V_149 -> V_152 . V_212 ) ;
F_41 ( & V_149 -> V_211 , V_29 ) ;
return - 1 ;
}
V_286 = F_141 ( V_149 -> V_336 . V_462 ) ;
F_7 ( V_14 , L_116 , V_149 -> V_152 . V_212 ) ;
V_452 = V_149 -> V_214 ;
V_453 = V_149 -> V_218 ;
V_451 = V_149 -> V_216 ;
if ( V_149 -> V_463 ) {
V_455 = 1 ;
V_456 = 1 ;
V_149 -> V_7 = NULL ;
F_131 ( & V_149 -> V_464 ) ;
if ( V_149 -> V_465 == 0 ) {
V_149 -> V_465 = 1 ;
V_457 = 1 ;
}
} else if ( ( V_452 == V_466 ) ||
( ( V_453 == V_467 ) &&
( V_451 == V_468 ) ) ) {
V_455 = 1 ;
if ( V_451 == V_468 )
V_454 = - V_469 ;
}
if ( ( ( V_452 == V_215 ) ||
( V_452 == V_470 ) ||
( V_451 == V_471 ) ||
( V_451 == V_468 ) ) ) {
V_456 = 1 ;
V_149 -> V_7 = NULL ;
if ( V_149 -> V_465 == 0 ) {
V_149 -> V_465 = 1 ;
V_457 = 1 ;
}
}
F_41 ( & V_149 -> V_211 , V_29 ) ;
if ( ( V_457 ) && ( V_149 -> V_472 == 0 ) ) {
if ( V_149 -> V_473 >= V_474 )
V_458 |= V_475 ;
F_142 ( V_286 -> V_287 , V_149 , V_458 , 1 ) ;
if ( V_149 -> V_463 ) {
V_461 . V_462 = V_149 -> V_336 . V_462 ;
V_461 . V_6 = V_149 -> V_476 ;
V_461 . V_477 . V_478 = & V_149 -> V_336 ;
if ( V_149 -> V_336 . V_479 )
V_149 -> V_336 . V_479 ( & V_461 , V_149 -> V_336 . V_480 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_479 ) ) {
if ( V_455 ) {
F_39 ( & V_481 ) ;
V_450 . V_6 = V_482 ;
V_450 . V_483 = V_454 ;
V_450 . V_484 = V_7 -> V_484 ;
V_450 . V_485 = V_7 -> V_485 ;
V_450 . V_383 = NULL ;
V_450 . V_382 = 0 ;
F_7 ( V_14 , L_117
L_118
L_119 ,
V_149 -> V_152 . V_212 , V_149 -> V_152 . V_486 ,
V_149 -> V_152 . V_178 , V_7 ,
F_26 ( & V_149 -> V_213 ) ) ;
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
if ( V_142 )
F_7 ( V_14 , L_120
L_121 , V_142 ) ;
}
if ( V_456 ) {
F_39 ( & V_487 ) ;
F_143 ( V_149 , 1 ) ;
V_7 -> V_488 = V_149 ;
V_450 . V_6 = V_489 ;
V_450 . V_483 = 0 ;
V_450 . V_488 = V_7 -> V_488 ;
V_450 . V_484 = V_7 -> V_484 ;
V_450 . V_485 = V_7 -> V_485 ;
V_450 . V_383 = NULL ;
V_450 . V_382 = 0 ;
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
if ( V_142 )
F_7 ( V_14 , L_122 , V_142 ) ;
V_7 -> V_207 ( V_7 ) ;
}
}
return 0 ;
}
static int F_143 ( struct V_146 * V_149 , int V_490 )
{
int V_142 = 0 ;
struct V_295 * V_286 ;
struct V_323 * V_287 ;
struct V_491 * V_492 ;
V_286 = F_141 ( V_149 -> V_336 . V_462 ) ;
if ( ! V_286 )
return - V_43 ;
V_287 = V_286 -> V_287 ;
V_492 = V_286 -> V_492 ;
F_7 ( V_14 , L_123 ,
F_144 ( V_286 -> V_90 ) ) ;
if ( V_149 -> V_493 ) {
V_149 -> V_493 = 0 ;
} else {
if ( V_149 -> V_494 ) {
if ( V_149 -> V_495 )
V_492 -> V_496 . V_497 ( V_149 -> V_495 ) ;
F_145 ( V_287 -> V_288 ,
V_149 -> V_382 + V_149 -> V_498 ,
V_149 -> V_494 , V_149 -> V_499 ) ;
}
}
if ( V_149 -> V_2 ) {
F_7 ( V_14 , L_124 ) ;
V_226 -> V_408 -> V_500 ( V_226 , V_149 -> V_2 ) ;
}
return V_142 ;
}
int F_146 ( struct V_201 * V_7 , struct V_501 * V_502 )
{
T_4 V_148 ;
struct V_503 * V_336 ;
struct V_146 * V_149 ;
struct V_295 * V_286 ;
struct V_323 * V_287 ;
struct V_1 * V_2 ;
struct V_304 * V_504 ;
struct V_505 V_506 ;
struct V_449 V_450 ;
struct V_150 * V_151 ;
struct V_507 V_508 ;
T_3 V_509 ;
int V_142 ;
int V_354 ;
struct V_491 * V_492 ;
struct V_510 * V_511 = NULL ;
struct V_512 V_513 ;
struct V_514 * V_515 ;
T_4 V_516 ;
T_1 V_517 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
struct V_518 * V_519 = (struct V_518 * ) & V_7 -> V_484 ;
struct V_518 * V_520 = (struct V_518 * ) & V_7 -> V_485 ;
V_336 = F_147 ( V_7 -> V_462 , V_502 -> V_521 ) ;
if ( ! V_336 )
return - V_43 ;
V_149 = F_148 ( V_336 ) ;
V_286 = F_141 ( V_149 -> V_336 . V_462 ) ;
V_287 = V_286 -> V_287 ;
V_504 = V_287 -> V_305 ;
V_2 = (struct V_1 * ) V_7 -> V_488 ;
F_7 ( V_14 , L_125
L_126 , V_2 , V_286 , V_286 -> V_90 ,
V_286 -> V_90 -> V_522 ) ;
if ( V_284 == V_2 -> V_32 ) {
if ( V_2 -> V_282 )
F_4 ( V_2 -> V_3 , V_2 -> V_282 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_354 = F_119 ( 1 , & V_2 -> V_354 ) ;
if ( V_354 == V_390 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_469 ;
}
V_149 -> V_2 = ( void * ) V_2 ;
V_2 -> V_149 = V_149 ;
F_7 ( V_14 , L_127 ,
V_149 -> V_152 . V_212 , V_2 , V_189 , V_2 -> V_273 ) ;
F_39 ( & V_523 ) ;
F_7 ( V_14 , L_123 ,
F_144 ( V_286 -> V_90 ) ) ;
V_149 -> V_498 = sizeof( struct V_36 ) ;
V_149 -> V_494 = F_149 ( V_287 -> V_288 ,
V_149 -> V_498 + V_502 -> V_382 ,
& V_149 -> V_499 ) ;
if ( ! V_149 -> V_494 ) {
F_7 ( V_14 , L_128 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_149 -> V_494 ;
if ( V_2 -> V_48 == V_46 )
V_517 = 4 ;
if ( V_2 -> V_48 == V_46 ||
V_2 -> V_64 == V_62 ) {
F_27 ( V_2 , ( T_2 ) V_502 -> V_524 , ( T_2 ) V_502 -> V_525 ) ;
}
memcpy ( V_37 -> V_526 , V_502 -> V_383 ,
V_502 -> V_382 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_149 -> V_494 , V_28 ) ;
V_149 -> V_382 = V_502 -> V_382 ;
V_151 = & V_149 -> V_152 . V_153 [ 0 ] ;
if ( V_520 -> V_527 . V_528 != V_519 -> V_527 . V_528 ) {
V_148 = ( unsigned long ) V_149 ;
V_492 = V_286 -> V_492 ;
V_515 = V_149 -> V_515 ;
V_513 . V_529 = V_149 -> V_499 + V_517 ;
V_513 . V_530 = V_20 ;
V_516 = ( T_4 ) ( unsigned long ) * V_19 ;
V_511 = V_492 -> V_496 . V_531 ( (struct V_532 * ) V_515 ,
& V_513 , 1 ,
V_533 ,
& V_516 ) ;
if ( ! V_511 ) {
F_7 ( V_14 , L_129
L_130 ,
V_2 ) ;
F_145 ( V_287 -> V_288 ,
V_149 -> V_382 + V_149 -> V_498 ,
V_149 -> V_494 , V_149 -> V_499 ) ;
return - V_27 ;
}
V_511 -> V_534 = & V_515 -> V_535 ;
V_511 -> V_462 = V_515 -> V_535 . V_462 ;
V_149 -> V_495 = V_511 ;
V_148 |= V_155 >> 1 ;
F_31 ( V_151 -> V_156 ,
V_157 ,
V_148 ) ;
V_151 -> V_156 [ V_160 ] =
F_32 ( V_536 |
V_537 ) ;
V_151 -> V_156 [ V_162 ] =
F_32 ( V_20 ) ;
F_31 ( V_151 -> V_156 ,
V_158 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_151 -> V_156 [ V_163 ] =
F_32 ( V_20 ) ;
V_151 -> V_156 [ V_164 ] = V_511 -> V_538 ;
if ( V_149 -> V_170 ) {
V_149 -> V_170 = 0 ;
F_34 ( V_149 -> V_171 ) ;
}
V_149 -> V_172 -> V_173 |=
F_32 ( V_174 |
V_175 ) ;
} else {
V_149 -> V_172 -> V_173 |=
F_32 ( V_175 ) ;
}
V_149 -> V_177 = 1 ;
V_149 -> V_7 = V_7 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_488 = V_149 ;
V_149 -> V_493 = 0 ;
if ( V_2 -> V_32 == V_232 )
F_7 ( V_14 , L_131 ,
V_2 ) ;
F_135 ( V_149 , V_2 ) ;
V_149 -> V_172 -> V_539 [ 0 ] = F_150 ( F_16 ( V_519 -> V_540 ) ) ;
V_149 -> V_172 -> V_539 [ 1 ] = F_150 ( F_16 ( V_520 -> V_540 ) ) ;
V_149 -> V_172 -> V_541 = F_32 ( F_37 ( V_520 -> V_527 . V_528 ) ) ;
V_149 -> V_172 -> V_422 |= F_32 (
( T_3 ) F_72 ( V_287 -> V_288 -> V_289 ) <<
V_542 ) ;
V_149 -> V_172 -> V_543 |=
F_32 ( F_86 ( V_287 ,
F_136 ( V_149 -> V_172 -> V_541 ) , NULL ,
V_318 ) << 16 ) ;
V_149 -> V_172 -> V_544 = F_32 (
V_189 - F_151 ( V_287 , V_545 ) ) ;
V_149 -> V_172 -> V_546 = F_32 ( V_149 -> V_152 . V_212 ) ;
V_149 -> V_172 -> V_173 |= F_32 (
( ( T_3 ) 1 << V_547 ) ) ;
V_149 -> V_172 -> V_173 |=
F_32 ( ( T_3 ) V_2 -> V_56 ) ;
memset ( & V_508 , 0 , sizeof( V_508 ) ) ;
V_508 . V_548 =
F_32 ( ( T_3 ) F_72 ( V_287 -> V_288 -> V_289 ) << 24 ) ;
V_508 . V_549 = V_520 -> V_527 . V_528 ;
V_508 . V_550 [ 0 ] = V_520 -> V_540 ;
V_508 . V_550 [ 1 ] = V_519 -> V_540 ;
V_509 = F_152 ( & V_508 ) ;
V_149 -> V_551 = F_123 ( V_509 ^ 0xffffffff ) ;
F_7 ( V_14 , L_132 ,
V_149 -> V_551 , V_149 -> V_551 & V_504 -> V_552 ) ;
V_149 -> V_551 &= V_504 -> V_552 ;
V_149 -> V_172 -> V_551 = F_32 ( V_149 -> V_551 ) ;
V_2 -> V_3 -> V_408 -> V_279 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_133
L_134
L_135 , V_149 -> V_152 . V_212 ,
F_37 ( V_520 -> V_527 . V_528 ) , F_16 ( V_520 -> V_540 ) ,
F_37 ( V_519 -> V_527 . V_528 ) , F_16 ( V_519 -> V_540 ) ,
F_136 ( V_149 -> V_172 -> V_120 ) ,
F_136 ( V_149 -> V_172 -> V_435 ) ,
V_20 ) ;
V_7 -> V_391 ( V_7 ) ;
F_137 ( & V_149 -> V_336 ) ;
V_450 . V_6 = V_553 ;
V_450 . V_483 = 0 ;
V_450 . V_488 = ( void * ) V_149 ;
V_450 . V_484 = V_7 -> V_484 ;
V_450 . V_485 = V_7 -> V_485 ;
V_450 . V_383 = NULL ;
V_450 . V_382 = 0 ;
V_450 . V_524 = V_2 -> V_55 ;
V_450 . V_525 = V_2 -> V_56 ;
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
V_506 . V_554 = V_467 ;
F_153 ( & V_149 -> V_336 , & V_506 , V_555 , NULL ) ;
if ( V_2 -> V_282 ) {
V_2 -> V_282 -> V_54 =
V_149 -> V_382 ;
memcpy ( V_2 -> V_282 -> V_73 ,
V_502 -> V_383 , V_502 -> V_382 ) ;
F_5 ( V_2 -> V_282 , V_362 ) ;
}
if ( V_142 )
F_79 ( V_307 L_136
L_137 , V_67 , __LINE__ , V_142 ) ;
return 0 ;
}
int F_154 ( struct V_201 * V_7 , const void * V_556 , T_1 V_557 )
{
struct V_1 * V_2 ;
struct V_1 * V_281 ;
struct V_134 * V_3 ;
T_1 * V_19 ;
F_39 ( & V_558 ) ;
V_2 = (struct V_1 * ) V_7 -> V_488 ;
V_281 = V_2 -> V_282 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_557 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_281 ) {
memcpy ( & V_281 -> V_25 . V_526 , V_556 , V_557 ) ;
V_281 -> V_25 . V_41 = V_557 ;
V_281 -> V_54 = V_557 ;
} else {
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_557 ;
memcpy ( V_19 , V_556 , V_557 ) ;
}
return V_3 -> V_408 -> V_559 ( V_3 , V_2 ) ;
}
int F_155 ( struct V_201 * V_7 , struct V_501 * V_502 )
{
struct V_503 * V_336 ;
struct V_146 * V_149 ;
struct V_295 * V_286 ;
struct V_323 * V_287 ;
struct V_1 * V_2 ;
struct V_319 V_9 ;
int V_333 = 0 ;
struct V_518 * V_519 = (struct V_518 * ) & V_7 -> V_484 ;
struct V_518 * V_520 = (struct V_518 * ) & V_7 -> V_485 ;
if ( V_7 -> V_485 . V_560 != V_561 )
return - V_562 ;
V_336 = F_147 ( V_7 -> V_462 , V_502 -> V_521 ) ;
if ( ! V_336 )
return - V_43 ;
V_149 = F_148 ( V_336 ) ;
if ( ! V_149 )
return - V_43 ;
V_286 = F_141 ( V_149 -> V_336 . V_462 ) ;
if ( ! V_286 )
return - V_43 ;
V_287 = V_286 -> V_287 ;
if ( ! V_287 )
return - V_43 ;
if ( ! V_519 -> V_540 || ! V_520 -> V_540 )
return - V_43 ;
F_7 ( V_14 , L_138
L_139 , V_149 -> V_152 . V_212 ,
F_37 ( V_286 -> V_388 ) , F_37 ( V_520 -> V_527 . V_528 ) ,
F_16 ( V_520 -> V_540 ) , F_37 ( V_519 -> V_527 . V_528 ) ,
F_16 ( V_519 -> V_540 ) ) ;
F_39 ( & V_563 ) ;
V_149 -> V_493 = 1 ;
V_149 -> V_7 = V_7 ;
V_7 -> V_488 = V_149 ;
V_149 -> V_382 = V_502 -> V_382 ;
F_7 ( V_14 , L_140 , ( T_3 ) V_502 -> V_525 ) ;
F_7 ( V_14 , L_141 ,
V_502 -> V_382 ) ;
if ( V_519 -> V_527 . V_528 != V_520 -> V_527 . V_528 ) {
F_71 ( V_286 , F_16 ( V_519 -> V_540 ) ,
F_72 ( V_287 -> V_288 -> V_289 ) ,
V_564 ) ;
V_333 = 1 ;
}
V_9 . V_11 = F_23 ( V_519 -> V_527 . V_528 ) ;
V_9 . V_13 = F_22 ( V_519 -> V_540 ) ;
V_9 . V_10 = F_23 ( V_520 -> V_527 . V_528 ) ;
V_9 . V_12 = F_22 ( V_520 -> V_540 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_332 = V_565 ;
V_7 -> V_391 ( V_7 ) ;
V_2 = V_226 -> V_408 -> V_566 ( V_226 , V_286 ,
V_502 -> V_382 , ( void * ) V_502 -> V_383 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_333 )
F_71 ( V_286 , F_16 ( V_519 -> V_540 ) ,
F_72 ( V_287 -> V_288 -> V_289 ) ,
V_290 ) ;
V_7 -> V_207 ( V_7 ) ;
return - V_27 ;
}
F_27 ( V_2 , ( T_2 ) V_502 -> V_524 , ( T_2 ) V_502 -> V_525 ) ;
if ( V_2 -> V_69 == V_70 &&
V_2 -> V_56 == 0 )
V_2 -> V_56 = 1 ;
V_2 -> V_333 = V_333 ;
V_149 -> V_2 = V_2 ;
V_2 -> V_149 = V_149 ;
F_137 ( & V_149 -> V_336 ) ;
return 0 ;
}
int F_156 ( struct V_201 * V_7 , int V_364 )
{
struct V_295 * V_286 ;
struct V_264 * V_2 ;
struct V_319 V_9 ;
int V_275 ;
struct V_518 * V_519 = (struct V_518 * ) & V_7 -> V_484 ;
F_7 ( V_14 , L_142 ,
V_7 , F_16 ( V_519 -> V_540 ) ) ;
if ( V_7 -> V_484 . V_560 != V_561 )
return - V_562 ;
V_286 = F_141 ( V_7 -> V_462 ) ;
if ( ! V_286 )
return - V_43 ;
F_7 ( V_14 , L_143 ,
V_286 , V_286 -> V_90 , V_286 -> V_90 -> V_522 ) ;
F_7 ( V_14 , L_144 ,
V_286 -> V_388 , V_519 -> V_527 . V_528 ) ;
V_9 . V_11 = V_286 -> V_388 ;
V_9 . V_13 = V_519 -> V_540 ;
V_9 . V_364 = V_364 ;
V_9 . V_7 = V_7 ;
V_9 . V_332 = V_565 ;
V_2 = V_226 -> V_408 -> V_567 ( V_226 , V_286 , & V_9 ) ;
if ( ! V_2 ) {
F_79 ( V_307 L_145 ,
V_67 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_488 = V_2 ;
if ( ! V_2 -> V_380 ) {
V_275 = F_71 ( V_286 , F_16 ( V_519 -> V_540 ) ,
F_72 ( V_286 -> V_287 -> V_288 -> V_289 ) ,
V_564 ) ;
if ( V_275 ) {
F_79 ( V_307 L_146 ,
V_275 ) ;
V_226 -> V_408 -> V_568 ( V_226 , ( void * ) V_2 ) ;
return V_275 ;
}
F_39 ( & V_569 ) ;
}
V_7 -> V_391 ( V_7 ) ;
V_7 -> V_488 = ( void * ) V_2 ;
return 0 ;
}
int F_157 ( struct V_201 * V_7 )
{
if ( V_7 -> V_488 )
V_226 -> V_408 -> V_568 ( V_226 , V_7 -> V_488 ) ;
else
F_7 ( V_14 , L_147 ) ;
V_7 -> V_207 ( V_7 ) ;
return 0 ;
}
int F_158 ( struct V_15 * V_16 , struct V_303 * V_570 )
{
int V_302 = 0 ;
V_571 ++ ;
if ( ( V_226 ) && ( V_226 -> V_408 ) )
V_302 = V_226 -> V_408 -> V_572 ( V_226 , F_159 ( V_570 ) , V_16 ) ;
else
F_7 ( V_14 , L_148
L_149 ) ;
return V_302 ;
}
int F_160 ( void )
{
F_7 ( V_14 , L_106 ) ;
V_226 = F_126 () ;
if ( V_226 )
return 0 ;
else
return - V_27 ;
}
int F_161 ( void )
{
V_226 -> V_408 -> V_573 ( V_226 ) ;
return 0 ;
}
static void F_162 ( struct V_4 * V_6 )
{
struct V_146 * V_149 ;
struct V_295 * V_286 ;
struct V_323 * V_287 ;
struct V_1 * V_2 ;
struct V_304 * V_305 ;
struct V_505 V_506 ;
struct V_201 * V_7 ;
struct V_449 V_450 ;
struct V_507 V_508 ;
T_3 V_509 ;
int V_142 ;
struct V_518 * V_519 ;
struct V_518 * V_520 ;
struct V_518 * V_574 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_150 , V_2 , V_7 ) ;
V_149 = (struct V_146 * ) V_7 -> V_488 ;
V_286 = F_141 ( V_149 -> V_336 . V_462 ) ;
V_287 = V_286 -> V_287 ;
V_305 = V_287 -> V_305 ;
V_519 = (struct V_518 * ) & V_7 -> V_484 ;
V_520 = (struct V_518 * ) & V_7 -> V_485 ;
V_574 = (struct V_518 * ) & V_450 . V_484 ;
if ( V_149 -> V_472 )
return;
F_39 ( & V_575 ) ;
F_7 ( V_14 , L_151
L_152 ,
V_149 -> V_152 . V_212 , F_37 ( V_520 -> V_527 . V_528 ) ,
F_16 ( V_520 -> V_540 ) , F_16 ( V_519 -> V_540 ) , V_189 ) ;
F_135 ( V_149 , V_2 ) ;
V_149 -> V_172 -> V_539 [ 0 ] = F_150 ( F_16 ( V_519 -> V_540 ) ) ;
V_149 -> V_172 -> V_539 [ 1 ] = F_150 ( F_16 ( V_520 -> V_540 ) ) ;
V_149 -> V_172 -> V_541 = F_32 ( F_37 ( V_520 -> V_527 . V_528 ) ) ;
V_149 -> V_172 -> V_422 |= F_32 (
( T_3 ) F_72 ( V_287 -> V_288 -> V_289 ) <<
V_542 ) ;
V_149 -> V_172 -> V_543 |= F_32 (
F_86 ( V_287 ,
F_136 ( V_149 -> V_172 -> V_541 ) ,
NULL , V_318 ) << 16 ) ;
V_149 -> V_172 -> V_544 = F_32 (
V_189 - F_151 ( V_287 , V_545 ) ) ;
V_149 -> V_172 -> V_546 = F_32 ( V_149 -> V_152 . V_212 ) ;
V_149 -> V_172 -> V_173 |=
F_32 ( ( T_3 ) 1 <<
V_547 ) ;
V_149 -> V_172 -> V_173 |=
F_32 ( ( T_3 ) V_2 -> V_56 ) ;
F_30 ( V_2 , & V_149 ) ;
F_163 ( V_287 -> V_576 + V_577 ,
( 1 << 24 ) | 0x00800000 | V_149 -> V_152 . V_212 ) ;
memset ( & V_508 , 0 , sizeof( V_508 ) ) ;
V_508 . V_548 =
F_32 ( ( T_3 ) F_72 ( V_287 -> V_288 -> V_289 ) << 24 ) ;
V_508 . V_549 = V_520 -> V_527 . V_528 ;
V_508 . V_550 [ 0 ] = V_520 -> V_540 ;
V_508 . V_550 [ 1 ] = V_519 -> V_540 ;
V_509 = F_152 ( & V_508 ) ;
V_149 -> V_551 = F_123 ( V_509 ^ 0xffffffff ) ;
F_7 ( V_14 , L_153 ,
V_149 -> V_551 , V_149 -> V_551 & V_305 -> V_552 ) ;
V_149 -> V_551 &= V_305 -> V_552 ;
V_149 -> V_172 -> V_551 = F_32 ( V_149 -> V_551 ) ;
V_149 -> V_494 = & V_2 -> V_25 ;
V_149 -> V_382 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_408 -> V_279 ( V_2 -> V_3 , V_2 ) ;
V_450 . V_6 = V_578 ;
V_450 . V_483 = 0 ;
V_450 . V_488 = V_7 -> V_488 ;
V_574 -> V_579 = V_561 ;
V_574 -> V_540 = V_519 -> V_540 ;
V_450 . V_485 = V_7 -> V_485 ;
V_450 . V_383 = ( void * ) V_6 -> V_2 -> V_73 ;
V_450 . V_382 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_450 . V_524 = V_2 -> V_55 ;
V_450 . V_525 = V_2 -> V_56 ;
V_574 -> V_527 . V_528 = V_6 -> V_9 . V_10 ;
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
F_7 ( V_14 , L_122 , V_142 ) ;
if ( V_142 )
F_79 ( V_307 L_136
L_137 , V_67 , __LINE__ , V_142 ) ;
V_506 . V_554 = V_467 ;
F_153 ( & V_149 -> V_336 , & V_506 , V_555 , NULL ) ;
F_7 ( V_14 , L_154
L_155 , V_149 -> V_152 . V_212 , V_189 ) ;
return;
}
static void F_67 ( struct V_4 * V_6 )
{
struct V_146 * V_149 ;
struct V_201 * V_7 ;
struct V_449 V_450 ;
int V_142 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_156 , V_6 -> V_2 , V_7 ) ;
V_149 = V_7 -> V_488 ;
if ( ! V_149 )
return;
V_149 -> V_7 = NULL ;
V_7 -> V_488 = NULL ;
V_450 . V_6 = V_578 ;
V_450 . V_483 = - V_469 ;
V_450 . V_488 = V_7 -> V_488 ;
V_450 . V_484 = V_7 -> V_484 ;
V_450 . V_485 = V_7 -> V_485 ;
V_450 . V_383 = NULL ;
V_450 . V_382 = 0 ;
#ifdef F_164
{
struct V_518 * V_574 = (struct V_518 * )
& V_450 . V_484 ;
struct V_518 * V_580 = (struct V_518 * )
& V_450 . V_485 ;
F_7 ( V_14 , L_157 ,
V_574 -> V_527 . V_528 , V_580 -> V_527 . V_528 ) ;
}
#endif
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
F_7 ( V_14 , L_122 , V_142 ) ;
if ( V_142 )
F_79 ( V_307 L_136
L_137 , V_67 , __LINE__ , V_142 ) ;
V_7 -> V_207 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_165 ( struct V_4 * V_6 )
{
struct V_146 * V_149 ;
struct V_201 * V_7 ;
struct V_449 V_450 ;
int V_142 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_158 , V_6 -> V_2 , V_7 ) ;
V_149 = V_7 -> V_488 ;
if ( ! V_149 )
return;
V_149 -> V_7 = NULL ;
V_450 . V_6 = V_482 ;
V_450 . V_483 = - V_469 ;
V_450 . V_488 = V_7 -> V_488 ;
V_450 . V_484 = V_7 -> V_484 ;
V_450 . V_485 = V_7 -> V_485 ;
V_450 . V_383 = NULL ;
V_450 . V_382 = 0 ;
V_7 -> V_391 ( V_7 ) ;
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
F_39 ( & V_487 ) ;
V_450 . V_6 = V_489 ;
V_450 . V_483 = 0 ;
V_450 . V_488 = V_7 -> V_488 ;
V_450 . V_484 = V_7 -> V_484 ;
V_450 . V_485 = V_7 -> V_485 ;
V_450 . V_383 = NULL ;
V_450 . V_382 = 0 ;
F_7 ( V_14 , L_159 , V_6 -> V_2 ) ;
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
F_7 ( V_14 , L_122 , V_142 ) ;
V_7 -> V_207 ( V_7 ) ;
return;
}
static void F_166 ( struct V_4 * V_6 )
{
struct V_201 * V_7 ;
struct V_449 V_450 ;
int V_142 ;
struct V_1 * V_2 ;
struct V_518 * V_574 = (struct V_518 * )
& V_450 . V_484 ;
struct V_518 * V_580 = (struct V_518 * )
& V_450 . V_485 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_39 ( & V_581 ) ;
F_7 ( V_14 , L_160 ,
V_2 , V_7 , V_189 ) ;
V_450 . V_6 = V_582 ;
V_450 . V_483 = 0 ;
V_450 . V_488 = ( void * ) V_2 ;
V_574 -> V_579 = V_561 ;
V_574 -> V_540 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_574 -> V_527 . V_528 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_580 -> V_579 = V_561 ;
V_580 -> V_540 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_580 -> V_527 . V_528 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_450 . V_383 = V_2 -> V_73 ;
V_450 . V_382 = ( T_1 ) V_2 -> V_54 ;
if ( V_2 -> V_48 == V_46 ) {
V_450 . V_524 = V_65 ;
V_450 . V_525 = V_68 ;
} else {
V_450 . V_524 = V_2 -> V_55 ;
V_450 . V_525 = V_2 -> V_56 ;
}
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
if ( V_142 )
F_79 ( V_307 L_161 ,
V_67 , __LINE__ , V_142 ) ;
return;
}
static void F_120 ( struct V_4 * V_6 )
{
struct V_201 * V_7 ;
struct V_449 V_450 ;
struct V_1 * V_2 ;
int V_142 ;
struct V_518 * V_574 = (struct V_518 * )
& V_450 . V_484 ;
struct V_518 * V_580 = (struct V_518 * )
& V_450 . V_485 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_39 ( & V_581 ) ;
F_7 ( V_14 , L_160 ,
V_2 , V_7 , V_189 ) ;
V_450 . V_6 = V_578 ;
V_450 . V_483 = - V_583 ;
V_450 . V_488 = V_7 -> V_488 ;
V_574 -> V_579 = V_561 ;
V_574 -> V_540 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_574 -> V_527 . V_528 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_580 -> V_579 = V_561 ;
V_580 -> V_540 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_580 -> V_527 . V_528 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_450 . V_383 = V_2 -> V_73 ;
V_450 . V_382 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_162
L_163 ,
V_574 -> V_527 . V_528 ,
V_580 -> V_527 . V_528 ) ;
V_142 = V_7 -> V_479 ( V_7 , & V_450 ) ;
if ( V_142 )
F_79 ( V_307 L_161 ,
V_67 , __LINE__ , V_142 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_39 ( & V_6 -> V_2 -> V_3 -> V_407 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_391 ( V_6 -> V_9 . V_7 ) ;
F_138 ( & V_6 -> V_584 , V_585 ) ;
F_7 ( V_14 , L_164 ,
V_6 -> V_2 , V_6 ) ;
F_139 ( V_6 -> V_2 -> V_3 -> V_410 , & V_6 -> V_584 ) ;
F_7 ( V_14 , L_165 ) ;
return 0 ;
}
static void V_585 ( struct V_447 * V_445 )
{
struct V_4 * V_6 = F_53 ( V_445 , struct V_4 ,
V_584 ) ;
struct V_134 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_166 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_407 ) ) ;
switch ( V_6 -> type ) {
case V_359 :
F_166 ( V_6 ) ;
F_7 ( V_14 , L_167 ,
V_6 -> V_2 ) ;
break;
case V_586 :
F_7 ( V_14 , L_168 ,
V_6 -> V_2 ) ;
F_165 ( V_6 ) ;
break;
case V_362 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_232 ) )
break;
F_162 ( V_6 ) ;
F_7 ( V_14 , L_169 ) ;
break;
case V_361 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_232 ) )
break;
F_120 ( V_6 ) ;
F_7 ( V_14 , L_170 ) ;
break;
case V_208 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_232 ) )
break;
F_67 ( V_6 ) ;
F_7 ( V_14 , L_171 ) ;
break;
case V_587 :
F_7 ( V_14 , L_172 ) ;
break;
default:
F_7 ( V_14 , L_173 ) ;
break;
}
F_70 ( & V_3 -> V_407 ) ;
V_6 -> V_9 . V_7 -> V_207 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_35 ( V_6 ) ;
return;
}
