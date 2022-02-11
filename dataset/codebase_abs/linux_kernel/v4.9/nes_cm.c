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
if ( ( V_2 -> V_11 == V_11 ) &&
( V_2 -> V_13 == V_13 ) &&
( V_2 -> V_10 == V_10 ) &&
( V_2 -> V_12 == V_12 ) ) {
F_2 ( V_2 ) ;
F_41 ( & V_3 -> V_229 , V_29 ) ;
return V_2 ;
}
}
F_41 ( & V_3 -> V_229 , V_29 ) ;
return NULL ;
}
static struct V_264 * F_63 ( struct V_134 * V_3 ,
T_5 V_265 , T_2 V_266 ,
enum V_267 V_268 )
{
unsigned long V_29 ;
struct V_264 * V_269 ;
T_5 V_270 ;
T_2 V_271 ;
F_40 ( & V_3 -> V_272 , V_29 ) ;
F_62 (listen_node, &cm_core->listen_list.list, list) {
V_270 = V_269 -> V_11 ;
V_271 = V_269 -> V_13 ;
if ( ( ( V_270 == V_265 ) ||
V_270 == 0x00000000 ) &&
( V_271 == V_266 ) &&
( V_268 & V_269 -> V_268 ) ) {
F_39 ( & V_269 -> V_273 ) ;
F_41 ( & V_3 -> V_272 , V_29 ) ;
return V_269 ;
}
}
F_41 ( & V_3 -> V_272 , V_29 ) ;
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
F_39 ( & V_3 -> V_274 ) ;
F_41 ( & V_3 -> V_229 , V_29 ) ;
return 0 ;
}
static int F_66 ( struct V_134 * V_3 ,
struct V_264 * V_275 , int V_276 )
{
int V_142 = - V_43 ;
int V_277 = 0 ;
unsigned long V_29 ;
struct V_223 * V_278 = NULL ;
struct V_223 * V_279 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_223 V_280 ;
F_7 ( V_14 , L_48
L_49 , V_275 , V_276 ,
F_26 ( & V_275 -> V_273 ) ) ;
F_51 ( & V_280 ) ;
if ( V_276 ) {
F_40 ( & V_3 -> V_229 , V_29 ) ;
F_52 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_53 ( V_278 , struct V_1 ,
V_230 ) ;
if ( ( V_2 -> V_275 == V_275 ) &&
( ! V_2 -> V_281 ) ) {
F_2 ( V_2 ) ;
F_54 ( & V_2 -> V_282 , & V_280 ) ;
}
}
F_41 ( & V_3 -> V_229 , V_29 ) ;
}
F_52 (list_pos, list_temp, &reset_list) {
V_2 = F_53 ( V_278 , struct V_1 ,
V_282 ) ;
{
struct V_1 * V_283 = V_2 -> V_284 ;
enum V_202 V_285 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_283 ) {
F_43 ( V_2 ) ;
V_277 = F_47 ( V_2 , NULL ) ;
if ( V_277 ) {
V_2 -> V_32 =
V_203 ;
F_36 ( 1 ) ;
} else {
V_285 = V_2 -> V_32 ;
V_2 -> V_32 = V_286 ;
if ( V_285 != V_287 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_283 ;
V_6 . V_9 . V_10 =
V_283 -> V_10 ;
V_6 . V_9 . V_11 =
V_283 -> V_11 ;
V_6 . V_9 . V_12 =
V_283 -> V_12 ;
V_6 . V_9 . V_13 =
V_283 -> V_13 ;
V_6 . V_9 . V_7 = V_283 -> V_7 ;
F_2 ( V_283 ) ;
V_283 -> V_32 = V_203 ;
F_67 ( & V_6 ) ;
V_2 -> V_32 = V_286 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_40 ( & V_3 -> V_272 , V_29 ) ;
if ( ! F_68 ( & V_275 -> V_273 ) ) {
F_69 ( & V_275 -> V_230 ) ;
F_70 ( & V_3 -> V_136 ) ;
F_41 ( & V_3 -> V_272 , V_29 ) ;
if ( V_275 -> V_288 ) {
F_71 ( V_275 -> V_288 ,
V_275 -> V_13 ,
F_72 ( V_275 -> V_288 -> V_289 -> V_290 -> V_291 ) ,
V_292 ) ;
F_7 ( V_293 ,
L_50 ,
V_275 -> V_13 ) ;
}
F_7 ( V_14 , L_51 , V_275 ) ;
F_35 ( V_275 ) ;
V_275 = NULL ;
V_142 = 0 ;
F_39 ( & V_294 ) ;
} else {
F_41 ( & V_3 -> V_272 , V_29 ) ;
}
if ( V_275 ) {
if ( F_26 ( & V_275 -> V_295 ) > 0 )
F_7 ( V_14 , L_52
L_53 ,
V_275 , F_26 ( & V_275 -> V_295 ) ) ;
}
return V_142 ;
}
static int F_73 ( struct V_134 * V_3 ,
struct V_264 * V_275 )
{
V_275 -> V_268 = V_296 ;
V_275 -> V_7 = NULL ;
return F_66 ( V_3 , V_275 , 1 ) ;
}
static inline int F_74 ( struct V_134 * V_3 ,
struct V_1 * V_2 )
{
V_2 -> V_281 = 1 ;
if ( V_2 -> V_297 ) {
F_75 ( ! V_2 -> V_275 ) ;
F_70 ( & V_2 -> V_275 -> V_295 ) ;
V_2 -> V_297 = 0 ;
F_75 ( F_26 ( & V_2 -> V_275 -> V_295 ) < 0 ) ;
}
if ( ! F_44 ( & V_3 -> V_200 ) )
F_45 ( & V_3 -> V_200 , ( V_189 + V_237 ) ) ;
return 0 ;
}
static int F_76 ( struct V_298 * V_288 , T_3 V_299 , int V_300 )
{
struct V_301 * V_302 ;
struct V_303 * V_304 ;
int V_305 = V_300 ;
struct V_306 * V_90 ;
struct V_307 * V_308 = V_288 -> V_289 -> V_308 ;
T_6 V_309 = F_23 ( V_299 ) ;
V_302 = F_77 ( & V_310 , V_309 , V_288 -> V_311 , 0 , 0 ) ;
if ( F_78 ( V_302 ) ) {
F_79 ( V_312 L_54 ,
V_67 , V_299 ) ;
return V_305 ;
}
if ( F_80 ( V_288 -> V_90 ) )
V_90 = F_81 ( V_288 -> V_90 ) ;
else
V_90 = V_288 -> V_90 ;
V_304 = F_82 ( & V_302 -> V_313 , & V_309 ) ;
F_83 () ;
if ( V_304 ) {
if ( V_304 -> V_314 & V_315 ) {
F_7 ( V_14 , L_55
L_56 , V_299 ,
V_304 -> V_316 , F_37 ( V_302 -> V_317 ) ) ;
if ( V_300 >= 0 ) {
if ( F_84 ( V_308 -> V_318 [ V_300 ] . V_319 , V_304 -> V_316 ) ) {
goto V_320;
}
F_85 ( V_288 -> V_90 ,
V_308 -> V_318 [ V_300 ] . V_319 ,
V_299 , V_321 ) ;
}
F_85 ( V_288 -> V_90 , V_304 -> V_316 ,
V_299 , V_322 ) ;
V_305 = F_86 ( V_288 -> V_289 , V_299 , NULL ,
V_323 ) ;
} else {
F_87 ( V_304 , NULL ) ;
}
}
V_320:
F_88 () ;
if ( V_304 )
F_89 ( V_304 ) ;
F_90 ( V_302 ) ;
return V_305 ;
}
static struct V_1 * F_91 ( struct V_134 * V_3 ,
struct V_298 * V_288 , struct V_324 * V_9 ,
struct V_264 * V_275 )
{
struct V_1 * V_2 ;
struct V_325 V_326 ;
int V_327 = 0 ;
int V_300 = 0 ;
struct V_328 * V_289 ;
struct V_307 * V_308 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
if ( V_275 ) {
V_2 -> V_11 = V_275 -> V_11 ;
V_2 -> V_13 = V_275 -> V_13 ;
} else {
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_13 = V_9 -> V_13 ;
}
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_48 = V_329 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_64 = 0 ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
F_7 ( V_14 , L_57 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_275 = V_275 ;
if ( V_275 )
V_2 -> V_106 = V_275 -> V_106 ;
V_2 -> V_90 = V_288 -> V_90 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_101 , V_288 -> V_90 -> V_330 , V_99 ) ;
F_7 ( V_14 , L_58 , V_2 -> V_275 ,
V_2 -> V_7 ) ;
F_92 ( & V_2 -> V_195 ) ;
V_2 -> V_284 = NULL ;
F_93 ( & V_2 -> V_273 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_109 . V_110 = V_331 ;
V_2 -> V_109 . V_255 = V_332 ;
V_2 -> V_109 . V_130 = V_333 >>
V_332 ;
V_326 = F_94 () ;
V_2 -> V_109 . V_118 = F_23 ( V_326 . V_334 ) ;
V_2 -> V_109 . V_251 = V_288 -> V_335 - sizeof( struct V_81 ) -
sizeof( struct V_79 ) - V_87 - V_336 ;
V_2 -> V_109 . V_120 = 0 ;
F_39 ( & V_3 -> V_137 ) ;
V_2 -> V_337 = V_9 -> V_337 ;
V_2 -> V_338 = 0 ;
V_2 -> V_297 = 0 ;
V_2 -> V_288 = V_288 ;
V_289 = V_288 -> V_289 ;
V_308 = V_289 -> V_308 ;
V_2 -> V_284 = NULL ;
V_327 = F_86 ( V_289 , V_2 -> V_10 ,
NULL , V_323 ) ;
V_300 = F_76 ( V_288 , V_2 -> V_10 ,
V_327 ) ;
if ( V_300 < 0 ) {
F_35 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_98 , V_308 -> V_318 [ V_300 ] . V_319 , V_99 ) ;
F_7 ( V_14 , L_59 ,
V_2 -> V_98 ) ;
F_64 ( V_3 , V_2 ) ;
F_39 ( & V_339 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_273 ) ;
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
if ( F_68 ( & V_2 -> V_273 ) ) {
F_41 ( & V_2 -> V_3 -> V_229 , V_29 ) ;
return 0 ;
}
F_69 ( & V_2 -> V_230 ) ;
F_70 ( & V_3 -> V_274 ) ;
F_41 ( & V_2 -> V_3 -> V_229 , V_29 ) ;
if ( ! V_2 -> V_281 && V_2 -> V_297 ) {
F_75 ( ! V_2 -> V_275 ) ;
F_70 ( & V_2 -> V_275 -> V_295 ) ;
F_75 ( F_26 ( & V_2 -> V_275 -> V_295 ) < 0 ) ;
}
F_36 ( V_2 -> V_196 ) ;
if ( V_2 -> V_192 )
F_48 ( V_2 , 0 ) ;
if ( V_2 -> V_275 ) {
F_66 ( V_3 , V_2 -> V_275 , 0 ) ;
} else {
if ( V_2 -> V_338 && V_2 -> V_288 ) {
F_71 ( V_2 -> V_288 , V_2 -> V_13 ,
F_72 ( V_2 -> V_288 -> V_289 -> V_290 -> V_291 ) ,
V_292 ) ;
}
F_7 ( V_293 , L_50 ,
V_2 -> V_13 ) ;
}
F_70 ( & V_3 -> V_137 ) ;
F_39 ( & V_340 ) ;
V_149 = V_2 -> V_149 ;
if ( V_149 ) {
V_149 -> V_2 = NULL ;
F_95 ( & V_149 -> V_341 ) ;
V_2 -> V_149 = NULL ;
}
F_35 ( V_2 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , T_1 * V_342 ,
T_3 V_76 , T_3 V_343 )
{
T_3 V_344 ;
T_3 V_345 = 0 ;
union V_246 * V_346 ;
char V_347 = 0 ;
while ( V_345 < V_76 ) {
V_346 = (union V_246 * ) ( V_342 + V_345 ) ;
switch ( V_346 -> V_258 . V_248 ) {
case V_261 :
V_345 = V_76 ;
break;
case V_348 :
V_345 += 1 ;
continue;
case V_249 :
F_7 ( V_14 , L_60
L_61 , V_67 ,
V_346 -> V_247 . V_250 , V_345 , V_76 ) ;
V_347 = 1 ;
if ( V_346 -> V_247 . V_250 != 4 ) {
return 1 ;
} else {
V_344 = F_16 ( V_346 -> V_247 . V_251 ) ;
if ( V_344 > 0 && V_344 <
V_2 -> V_109 . V_251 )
V_2 -> V_109 . V_251 = V_344 ;
}
break;
case V_253 :
V_2 -> V_109 . V_349 =
V_346 -> V_252 . V_254 ;
break;
default:
F_7 ( V_14 , L_62 ,
V_346 -> V_258 . V_248 ) ;
break;
}
V_345 += V_346 -> V_258 . V_250 ;
}
if ( ( ! V_347 ) && ( V_343 ) )
V_2 -> V_109 . V_251 = V_350 ;
return 0 ;
}
static void F_97 ( struct V_15 * V_16 )
{
F_39 ( & V_351 ) ;
F_98 ( V_16 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_63
L_49 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_273 ) ) ;
switch ( V_2 -> V_32 ) {
case V_204 :
case V_352 :
case V_353 :
case V_354 :
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
case V_355 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_356 ;
F_59 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_190 , 1 , 0 ) ;
break;
case V_356 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_232 :
default:
F_7 ( V_14 , L_64 ,
V_2 , V_2 -> V_32 ) ;
break;
}
}
static void F_100 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_357 = 0 ;
F_39 ( & V_358 ) ;
F_7 ( V_14 , L_65
L_66 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_273 ) ) ;
F_43 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_352 :
case V_49 :
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_275 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_352 ;
if ( F_58 ( V_2 , 0 , NULL ) ) {
F_101 ( V_2 , V_16 , V_357 ) ;
}
break;
case V_46 :
default:
F_101 ( V_2 , V_16 , V_357 ) ;
break;
}
break;
case V_287 :
F_39 ( & V_2 -> V_359 ) ;
F_98 ( V_16 ) ;
break;
case V_353 :
case V_204 :
case V_360 :
F_7 ( V_14 , L_69 , V_67 , __LINE__ ) ;
F_102 ( V_2 , V_16 , V_357 ) ;
break;
case V_232 :
F_101 ( V_2 , V_16 , V_357 ) ;
break;
case V_203 :
F_97 ( V_16 ) ;
break;
case V_355 :
case V_33 :
case V_206 :
V_2 -> V_7 -> V_207 ( V_2 -> V_7 ) ;
case V_356 :
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
T_1 * V_361 = V_16 -> V_77 ;
enum V_5 type = V_362 ;
T_3 V_363 ;
V_142 = F_15 ( V_2 , V_361 , & V_363 , V_78 ) ;
if ( V_142 ) {
F_7 ( V_14 , L_70 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_71
L_72 , V_67 ,
__LINE__ , V_2 , V_2 -> V_275 ,
V_2 -> V_32 ) ;
F_101 ( V_2 , V_16 , 1 ) ;
} else {
F_102 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_353 :
if ( V_363 == V_74 )
F_36 ( 1 ) ;
V_2 -> V_32 = V_287 ;
type = V_364 ;
F_93 ( & V_2 -> V_359 ,
V_365 ) ;
break;
case V_49 :
F_43 ( V_2 ) ;
if ( V_363 == V_74 ) {
type = V_366 ;
V_2 -> V_32 = V_354 ;
} else {
type = V_367 ;
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
case V_352 :
case V_49 :
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_275 , V_2 -> V_32 ) ;
F_101 ( V_2 , V_16 , 1 ) ;
break;
case V_353 :
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
int V_277 ;
V_277 = ( ( F_37 ( V_80 -> V_121 ) == V_2 -> V_109 . V_118 ) ) ? 0 : 1 ;
if ( V_277 )
F_101 ( V_2 , V_16 , 1 ) ;
return V_277 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 )
{
int V_277 = 0 ;
T_3 V_117 ;
T_3 V_121 ;
T_3 V_118 = V_2 -> V_109 . V_118 ;
T_3 V_120 = V_2 -> V_109 . V_120 ;
T_3 V_130 ;
V_117 = F_37 ( V_80 -> V_117 ) ;
V_121 = F_37 ( V_80 -> V_121 ) ;
V_130 = V_2 -> V_109 . V_130 ;
if ( V_121 != V_118 )
V_277 = 1 ;
else if ( ! F_107 ( V_117 , V_120 , ( V_120 + V_130 ) ) )
V_277 = 1 ;
if ( V_277 ) {
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_275 , V_2 -> V_32 ) ;
F_104 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_73
L_74 , V_2 , V_117 , V_120 ,
V_130 ) ;
}
return V_277 ;
}
static void F_108 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_142 ;
T_3 V_368 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_368 = F_37 ( V_80 -> V_117 ) ;
switch ( V_2 -> V_32 ) {
case V_352 :
case V_49 :
F_101 ( V_2 , V_16 , 1 ) ;
break;
case V_360 :
if ( F_26 ( & V_2 -> V_275 -> V_295 ) >
V_2 -> V_275 -> V_369 ) {
F_7 ( V_14 , L_75
L_76 ) ;
V_370 ++ ;
F_102 ( V_2 , V_16 , 0 ) ;
break;
}
V_142 = F_109 ( V_2 , V_80 , V_16 , V_76 ,
1 ) ;
if ( V_142 ) {
F_102 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_109 . V_120 = V_368 + 1 ;
F_75 ( V_2 -> V_196 ) ;
V_2 -> V_297 = 1 ;
F_39 ( & V_2 -> V_275 -> V_295 ) ;
V_2 -> V_32 = V_204 ;
F_58 ( V_2 , 1 , V_16 ) ;
break;
case V_203 :
F_43 ( V_2 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
break;
case V_232 :
case V_353 :
case V_33 :
case V_355 :
case V_287 :
case V_206 :
case V_205 :
case V_371 :
default:
F_97 ( V_16 ) ;
break;
}
}
static void F_110 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_142 ;
T_3 V_368 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_368 = F_37 ( V_80 -> V_117 ) ;
switch ( V_2 -> V_32 ) {
case V_352 :
F_43 ( V_2 ) ;
if ( F_105 ( V_2 , V_80 , V_16 ) )
return;
V_2 -> V_109 . V_235 = F_37 ( V_80 -> V_121 ) ;
V_142 = F_109 ( V_2 , V_80 , V_16 , V_76 , 0 ) ;
if ( V_142 ) {
F_7 ( V_14 , L_77 ,
V_2 ) ;
break;
}
F_43 ( V_2 ) ;
V_2 -> V_109 . V_120 = V_368 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_287 :
F_102 ( V_2 , V_16 , 1 ) ;
break;
case V_360 :
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
case V_353 :
case V_33 :
case V_355 :
case V_206 :
case V_232 :
case V_205 :
case V_371 :
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
T_3 V_368 ;
int V_142 = 0 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
if ( F_106 ( V_2 , V_80 , V_16 ) )
return - V_43 ;
F_112 ( V_16 , V_80 -> V_128 << 2 ) ;
V_368 = F_37 ( V_80 -> V_117 ) ;
V_78 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_204 :
F_43 ( V_2 ) ;
V_142 = F_109 ( V_2 , V_80 , V_16 , V_76 , 1 ) ;
if ( V_142 )
break;
V_2 -> V_109 . V_235 = F_37 ( V_80 -> V_121 ) ;
V_2 -> V_32 = V_353 ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_368 + V_78 ;
F_103 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
}
break;
case V_353 :
F_43 ( V_2 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_368 + V_78 ;
F_103 ( V_2 , V_16 ) ;
} else {
F_97 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_109 . V_235 = F_37 ( V_80 -> V_121 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_368 + V_78 ;
F_103 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
}
break;
case V_360 :
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
V_2 -> V_32 = V_355 ;
break;
case V_352 :
case V_355 :
case V_232 :
case V_287 :
case V_371 :
default:
F_43 ( V_2 ) ;
F_97 ( V_16 ) ;
break;
}
return V_142 ;
}
static int F_109 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 , int V_76 , int V_372 )
{
T_1 * V_342 = ( T_1 * ) & V_80 [ 1 ] ;
if ( V_76 ) {
if ( F_96 ( V_2 , V_342 , V_76 ,
( T_3 ) V_80 -> V_124 ) ) {
F_7 ( V_14 , L_78 ,
V_67 , V_2 ) ;
if ( V_372 )
F_102 ( V_2 , V_16 , 1 ) ;
else
F_101 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_109 . V_373 = F_16 ( V_80 -> V_129 ) <<
V_2 -> V_109 . V_349 ;
if ( V_2 -> V_109 . V_373 > V_2 -> V_109 . V_374 )
V_2 -> V_109 . V_374 = V_2 -> V_109 . V_373 ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_357 )
{
F_43 ( V_2 ) ;
if ( V_357 ) {
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
}
V_2 -> V_32 = V_203 ;
F_5 ( V_2 , V_208 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_357 )
{
F_43 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
if ( V_357 ) {
F_7 ( V_14 , L_81
L_82 , V_2 , V_2 -> V_32 ) ;
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
enum V_375 V_376 = V_377 ;
struct V_79 * V_80 = F_38 ( V_16 ) ;
T_3 V_378 = 0 ;
int V_142 = 0 ;
F_112 ( V_16 , F_114 ( V_16 ) -> V_105 << 2 ) ;
F_7 ( V_14 , L_83
L_84 , V_2 , V_2 -> V_32 , V_80 -> V_124 ,
V_80 -> V_122 , V_80 -> V_127 , V_80 -> V_125 ) ;
if ( V_80 -> V_127 ) {
V_376 = V_379 ;
} else if ( V_80 -> V_124 ) {
V_376 = V_380 ;
if ( V_80 -> V_122 )
V_376 = V_381 ;
} else if ( V_80 -> V_122 ) {
V_376 = V_382 ;
}
if ( V_80 -> V_125 )
V_378 = 1 ;
switch ( V_376 ) {
case V_380 :
F_108 ( V_2 , V_16 , V_80 ) ;
break;
case V_381 :
F_110 ( V_2 , V_16 , V_80 ) ;
break;
case V_382 :
V_142 = F_111 ( V_2 , V_16 , V_80 ) ;
if ( V_378 && ! V_142 )
F_99 ( V_2 ) ;
break;
case V_379 :
F_100 ( V_2 , V_16 , V_80 ) ;
break;
default:
if ( ( V_378 ) && ( ! F_106 ( V_2 , V_80 , V_16 ) ) )
F_99 ( V_2 ) ;
F_97 ( V_16 ) ;
break;
}
}
static struct V_264 * F_115 ( struct V_134 * V_3 ,
struct V_298 * V_288 , struct V_324 * V_9 )
{
struct V_264 * V_275 ;
unsigned long V_29 ;
F_7 ( V_14 , L_85 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_275 = F_63 ( V_3 , V_9 -> V_11 , V_9 -> V_13 ,
V_383 ) ;
if ( V_275 && V_275 -> V_268 == V_384 ) {
F_70 ( & V_275 -> V_273 ) ;
F_7 ( V_14 , L_86 ) ;
return NULL ;
}
if ( ! V_275 ) {
V_275 = F_6 ( sizeof( * V_275 ) , V_8 ) ;
if ( ! V_275 ) {
F_7 ( V_14 , L_87 ) ;
return NULL ;
}
V_275 -> V_11 = V_9 -> V_11 ;
V_275 -> V_13 = V_9 -> V_13 ;
V_275 -> V_385 = 0 ;
F_93 ( & V_275 -> V_273 , 1 ) ;
}
else {
V_275 -> V_385 = 1 ;
}
V_275 -> V_7 = V_9 -> V_7 ;
F_93 ( & V_275 -> V_295 , 0 ) ;
V_275 -> V_3 = V_3 ;
V_275 -> V_288 = V_288 ;
F_39 ( & V_3 -> V_137 ) ;
V_275 -> V_337 = V_9 -> V_337 ;
V_275 -> V_369 = V_9 -> V_369 ;
V_275 -> V_268 = V_384 ;
if ( ! V_275 -> V_385 ) {
F_40 ( & V_3 -> V_272 , V_29 ) ;
F_54 ( & V_275 -> V_230 , & V_3 -> V_386 . V_230 ) ;
F_41 ( & V_3 -> V_272 , V_29 ) ;
F_39 ( & V_3 -> V_136 ) ;
}
F_7 ( V_14 , L_88
L_89 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_275 , V_275 -> V_369 , V_275 -> V_7 ) ;
return V_275 ;
}
static struct V_1 * F_116 ( struct V_134 * V_3 ,
struct V_298 * V_288 , T_2 V_387 ,
void * V_388 , struct V_324 * V_9 )
{
int V_142 = 0 ;
struct V_1 * V_2 ;
struct V_264 * V_389 ;
struct V_1 * V_390 ;
struct V_324 V_391 ;
T_1 * V_19 ;
V_2 = F_91 ( V_3 , V_288 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_109 . V_392 = 1 ;
V_2 -> V_109 . V_255 = V_332 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_389 = F_63 ( V_3 ,
V_2 -> V_11 , V_2 -> V_12 ,
V_384 ) ;
if ( V_389 == NULL ) {
F_5 ( V_2 , V_208 ) ;
} else {
V_391 = * V_9 ;
V_391 . V_13 = V_9 -> V_12 ;
V_391 . V_12 = V_9 -> V_13 ;
V_391 . V_13 =
V_9 -> V_12 ;
V_391 . V_12 =
V_9 -> V_13 ;
V_391 . V_7 = V_389 -> V_7 ;
V_390 = F_91 ( V_3 , V_288 ,
& V_391 , V_389 ) ;
if ( ! V_390 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_39 ( & V_393 ) ;
V_390 -> V_284 = V_2 ;
V_390 -> V_109 . V_255 =
V_332 ;
V_2 -> V_284 = V_390 ;
memcpy ( V_390 -> V_73 , V_388 ,
V_387 ) ;
V_390 -> V_54 = V_387 ;
V_2 -> V_32 = V_232 ;
V_2 -> V_109 . V_120 =
V_390 -> V_109 . V_118 ;
V_390 -> V_109 . V_120 =
V_2 -> V_109 . V_118 ;
V_2 -> V_109 . V_374 =
V_390 -> V_109 . V_130 ;
V_390 -> V_109 . V_374 =
V_2 -> V_109 . V_130 ;
V_2 -> V_109 . V_373 =
V_390 -> V_109 . V_130 ;
V_390 -> V_109 . V_373 =
V_2 -> V_109 . V_130 ;
V_2 -> V_109 . V_349 =
V_390 -> V_109 . V_255 ;
V_390 -> V_109 . V_349 =
V_2 -> V_109 . V_255 ;
V_390 -> V_32 = V_287 ;
F_5 ( V_390 , V_364 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_387 ;
memcpy ( V_19 , V_388 , V_387 ) ;
V_2 -> V_32 = V_352 ;
V_142 = F_58 ( V_2 , 0 , NULL ) ;
if ( V_142 ) {
F_7 ( V_14 , L_90
L_91 ,
V_2 -> V_10 , V_2 -> V_12 , V_2 ,
V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
V_2 = NULL ;
}
if ( V_2 ) {
F_7 ( V_14 , L_92
L_93 ,
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
int V_277 = 0 ;
int V_359 ;
struct V_4 V_6 ;
struct V_201 * V_7 = V_2 -> V_7 ;
struct V_1 * V_283 = V_2 -> V_284 ;
F_7 ( V_14 , L_94 ,
V_67 , V_2 , V_2 -> V_109 . V_392 , V_2 -> V_32 ) ;
if ( V_2 -> V_109 . V_392 )
return V_142 ;
F_43 ( V_2 ) ;
if ( ! V_283 ) {
V_359 = F_119 ( 1 , & V_2 -> V_359 ) ;
if ( V_359 == V_394 ) {
V_2 -> V_32 = V_203 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_286 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_142 = F_13 ( V_2 ) ;
if ( V_142 ) {
V_2 -> V_32 = V_203 ;
V_277 = F_47 ( V_2 , NULL ) ;
if ( V_277 )
F_36 ( 1 ) ;
} else {
V_7 -> V_395 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_286 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_283 ) ;
} else {
V_6 . V_2 = V_283 ;
V_6 . V_9 . V_10 = V_283 -> V_10 ;
V_6 . V_9 . V_11 = V_283 -> V_11 ;
V_6 . V_9 . V_12 = V_283 -> V_12 ;
V_6 . V_9 . V_13 = V_283 -> V_13 ;
V_6 . V_9 . V_7 = V_283 -> V_7 ;
F_120 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_283 -> V_32 = V_205 ;
V_7 = V_283 -> V_7 ;
F_4 ( V_3 , V_283 ) ;
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
case V_352 :
case V_396 :
case V_353 :
case V_397 :
case V_49 :
case V_287 :
F_43 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_398 :
V_2 -> V_32 = V_206 ;
F_60 ( V_2 , NULL ) ;
break;
case V_33 :
case V_355 :
case V_206 :
case V_356 :
case V_205 :
V_142 = - 1 ;
break;
case V_360 :
F_43 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_354 :
case V_371 :
case V_399 :
case V_203 :
case V_286 :
V_142 = F_4 ( V_3 , V_2 ) ;
break;
case V_232 :
if ( V_2 -> V_196 )
F_79 ( V_312 L_95
L_96 , V_2 -> V_196 ) ;
V_142 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_142 ;
}
static int F_122 ( struct V_134 * V_3 ,
struct V_298 * V_288 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_264 * V_275 = NULL ;
struct V_81 * V_82 ;
struct V_79 * V_80 ;
struct V_324 V_400 ;
int V_401 = 1 ;
T_6 V_402 , V_403 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_81 ) + sizeof( struct V_79 ) )
return 0 ;
V_82 = (struct V_81 * ) V_16 -> V_77 ;
V_80 = (struct V_79 * ) ( V_16 -> V_77 + sizeof( struct V_81 ) ) ;
V_400 . V_11 = F_37 ( V_82 -> V_114 ) ;
V_400 . V_13 = F_16 ( V_80 -> V_116 ) ;
V_400 . V_10 = F_37 ( V_82 -> V_113 ) ;
V_400 . V_12 = F_16 ( V_80 -> V_115 ) ;
V_402 = F_123 ( V_82 -> V_114 ) ;
V_403 = F_123 ( V_82 -> V_113 ) ;
F_7 ( V_14 , L_97 ,
& V_402 , V_80 -> V_116 , & V_403 , V_80 -> V_115 ) ;
do {
V_2 = F_61 ( V_3 ,
V_400 . V_12 , V_400 . V_10 ,
V_400 . V_13 , V_400 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_80 -> V_124 ) || ( V_80 -> V_122 ) ) {
V_401 = 0 ;
break;
}
V_275 = F_63 ( V_3 , V_400 . V_11 ,
V_400 . V_13 ,
V_384 ) ;
if ( ! V_275 ) {
V_400 . V_7 = NULL ;
V_400 . V_337 = 0 ;
F_7 ( V_14 , L_98 ) ;
V_401 = 0 ;
break;
}
V_400 . V_7 = V_275 -> V_7 ;
V_400 . V_337 = V_275 -> V_337 ;
V_2 = F_91 ( V_3 , V_288 , & V_400 ,
V_275 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_99
L_100 ) ;
V_233 ++ ;
F_70 ( & V_275 -> V_273 ) ;
F_98 ( V_16 ) ;
break;
}
if ( ! V_80 -> V_127 && ! V_80 -> V_125 ) {
V_2 -> V_32 = V_360 ;
} else {
V_233 ++ ;
F_4 ( V_3 , V_2 ) ;
F_98 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_232 ) {
if ( V_2 -> V_149 -> V_404 )
F_124 ( V_16 , V_288 , V_2 -> V_149 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_39 ( & V_351 ) ;
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
return V_401 ;
}
static struct V_134 * F_126 ( void )
{
struct V_134 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_405 ) ;
if ( ! V_3 )
return NULL ;
F_51 ( & V_3 -> V_263 ) ;
F_127 ( & V_3 -> V_200 ) ;
V_3 -> V_200 . V_406 = F_50 ;
V_3 -> V_407 = V_408 ;
V_3 -> V_32 = V_399 ;
V_3 -> V_409 = V_410 ;
F_93 ( & V_3 -> V_411 , 0 ) ;
V_3 -> V_412 = & V_413 ;
F_92 ( & V_3 -> V_229 ) ;
F_92 ( & V_3 -> V_272 ) ;
F_51 ( & V_3 -> V_386 . V_230 ) ;
F_7 ( V_14 , L_101 , V_3 ) ;
F_7 ( V_14 , L_102 ) ;
V_3 -> V_414 = F_128 ( L_103 , 0 ) ;
if ( ! V_3 -> V_414 )
goto V_415;
V_3 -> V_416 = F_8 ;
F_7 ( V_14 , L_104 ) ;
V_3 -> V_417 = F_128 ( L_105 , 0 ) ;
if ( ! V_3 -> V_417 )
goto V_418;
F_25 ( V_3 ) ;
return V_3 ;
V_418:
F_129 ( V_3 -> V_414 ) ;
V_415:
F_35 ( V_3 ) ;
return NULL ;
}
static int F_130 ( struct V_134 * V_3 )
{
F_7 ( V_14 , L_106 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_131 () ;
if ( F_44 ( & V_3 -> V_200 ) )
F_132 ( & V_3 -> V_200 ) ;
F_129 ( V_3 -> V_414 ) ;
F_129 ( V_3 -> V_417 ) ;
F_7 ( V_14 , L_107 ) ;
F_35 ( V_3 ) ;
return 0 ;
}
static int F_133 ( struct V_134 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_134 ( struct V_134 * V_3 , T_3 type , T_3 V_419 )
{
int V_142 = 0 ;
switch ( type ) {
case V_420 :
V_3 -> V_407 = V_419 ;
break;
case V_421 :
V_3 -> V_409 = V_419 ;
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
V_149 -> V_172 -> V_422 |= F_32 ( V_423 |
V_424 | V_425 |
V_426 ) ;
if ( V_2 -> V_109 . V_349 || V_2 -> V_109 . V_255 )
V_149 -> V_172 -> V_422 |= F_32 ( V_427 ) ;
V_149 -> V_172 -> V_428 |= F_32 ( 64 << V_429 ) ;
V_149 -> V_172 -> V_428 |= F_32 (
V_2 -> V_106 << V_430 ) ;
V_149 -> V_172 -> V_251 |= F_32 ( ( ( T_3 ) V_2 -> V_109 . V_251 ) << 16 ) ;
V_149 -> V_172 -> V_431 |= F_32 (
( T_3 ) V_432 << V_433 ) ;
V_149 -> V_172 -> V_434 |= F_32 (
( V_2 -> V_109 . V_349 << V_435 ) &
V_436 ) ;
V_149 -> V_172 -> V_434 |= F_32 (
( V_2 -> V_109 . V_255 << V_437 ) &
V_438 ) ;
V_149 -> V_172 -> V_439 = F_32 ( 0x80 ) ;
V_149 -> V_172 -> V_440 = 0 ;
V_149 -> V_172 -> V_441 = 0 ;
V_149 -> V_172 -> V_442 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_373 = F_32 ( V_2 -> V_109 . V_373 ) ;
V_149 -> V_172 -> V_120 = F_32 ( V_2 -> V_109 . V_120 ) ;
V_149 -> V_172 -> V_130 = F_32 ( V_2 -> V_109 . V_130 <<
V_2 -> V_109 . V_255 ) ;
V_149 -> V_172 -> V_443 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_444 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_445 = 0 ;
V_149 -> V_172 -> V_446 = F_32 ( 0x6 ) ;
V_149 -> V_172 -> V_447 = F_32 ( 0x3FFFC000 ) ;
V_149 -> V_172 -> V_448 = F_32 ( 2 * V_2 -> V_109 . V_251 ) ;
V_149 -> V_172 -> V_449 = F_32 ( V_2 -> V_109 . V_120 ) ;
V_149 -> V_172 -> V_450 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_149 -> V_172 -> V_374 = F_32 ( V_2 -> V_109 . V_374 ) ;
F_7 ( V_14 , L_108
L_109 ,
V_149 -> V_152 . V_212 , F_136 ( V_149 -> V_172 -> V_120 ) ,
F_136 ( V_149 -> V_172 -> V_442 ) ,
V_2 -> V_109 . V_251 , F_136 ( V_149 -> V_172 -> V_434 ) ,
F_136 ( V_149 -> V_172 -> V_130 ) ,
F_136 ( V_149 -> V_172 -> V_422 ) ) ;
F_7 ( V_14 , L_110 , F_136 ( V_149 -> V_172 -> V_373 ) ) ;
F_7 ( V_14 , L_111 , F_136 ( V_149 -> V_172 -> V_448 ) ) ;
F_7 ( V_14 , L_112 , F_136 ( V_149 -> V_172 -> V_374 ) ) ;
F_7 ( V_14 , L_113 ) ;
V_2 -> V_32 = V_232 ;
return V_142 ;
}
int F_49 ( struct V_146 * V_149 )
{
struct V_451 * V_452 ;
V_452 = F_6 ( sizeof *V_452 , V_8 ) ;
if ( ! V_452 )
return - V_27 ;
F_137 ( & V_149 -> V_341 ) ;
V_452 -> V_149 = V_149 ;
F_138 ( & V_452 -> V_452 , V_453 ) ;
F_139 ( V_226 -> V_417 , & V_452 -> V_452 ) ;
return 0 ;
}
static void V_453 ( struct V_454 * V_452 )
{
struct V_451 * V_455 = F_53 ( V_452 , struct V_451 , V_452 ) ;
struct V_146 * V_149 = V_455 -> V_149 ;
F_35 ( V_455 ) ;
F_7 ( V_14 , L_114 ,
V_149 -> V_216 , V_149 -> V_152 . V_212 ) ;
F_140 ( V_149 ) ;
F_95 ( & V_149 -> V_341 ) ;
}
static int F_140 ( struct V_146 * V_149 )
{
unsigned long V_29 ;
int V_142 = 0 ;
struct V_201 * V_7 ;
struct V_456 V_457 ;
struct V_298 * V_288 ;
T_2 V_458 ;
T_1 V_459 ;
T_1 V_460 ;
int V_461 = 0 ;
int V_462 = 0 ;
int V_463 = 0 ;
int V_464 = 0 ;
T_3 V_465 = V_466 ;
struct V_467 V_468 ;
if ( ! V_149 ) {
F_7 ( V_14 , L_115 ) ;
return - 1 ;
}
F_40 ( & V_149 -> V_211 , V_29 ) ;
V_7 = V_149 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_116 ,
V_149 -> V_152 . V_212 ) ;
F_41 ( & V_149 -> V_211 , V_29 ) ;
return - 1 ;
}
V_288 = F_141 ( V_149 -> V_341 . V_469 ) ;
F_7 ( V_14 , L_117 , V_149 -> V_152 . V_212 ) ;
V_459 = V_149 -> V_214 ;
V_460 = V_149 -> V_218 ;
V_458 = V_149 -> V_216 ;
if ( V_149 -> V_470 ) {
V_462 = 1 ;
V_463 = 1 ;
V_149 -> V_7 = NULL ;
F_132 ( & V_149 -> V_471 ) ;
if ( V_149 -> V_472 == 0 ) {
V_149 -> V_472 = 1 ;
V_464 = 1 ;
}
} else if ( ( V_459 == V_473 ) ||
( ( V_460 == V_474 ) &&
( V_458 == V_475 ) ) ) {
V_462 = 1 ;
if ( V_458 == V_475 )
V_461 = - V_476 ;
}
if ( ( ( V_459 == V_215 ) ||
( V_459 == V_477 ) ||
( V_458 == V_478 ) ||
( V_458 == V_475 ) ) ) {
V_463 = 1 ;
V_149 -> V_7 = NULL ;
if ( V_149 -> V_472 == 0 ) {
V_149 -> V_472 = 1 ;
V_464 = 1 ;
}
}
F_41 ( & V_149 -> V_211 , V_29 ) ;
if ( ( V_464 ) && ( V_149 -> V_479 == 0 ) ) {
if ( V_149 -> V_480 >= V_481 )
V_465 |= V_482 ;
F_142 ( V_288 -> V_289 , V_149 , V_465 , 1 ) ;
if ( V_149 -> V_470 ) {
V_468 . V_469 = V_149 -> V_341 . V_469 ;
V_468 . V_6 = V_149 -> V_483 ;
V_468 . V_484 . V_485 = & V_149 -> V_341 ;
if ( V_149 -> V_341 . V_486 )
V_149 -> V_341 . V_486 ( & V_468 , V_149 -> V_341 . V_487 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_486 ) ) {
if ( V_462 ) {
F_39 ( & V_488 ) ;
V_457 . V_6 = V_489 ;
V_457 . V_490 = V_461 ;
V_457 . V_491 = V_7 -> V_492 ;
V_457 . V_493 = V_7 -> V_494 ;
V_457 . V_388 = NULL ;
V_457 . V_387 = 0 ;
F_7 ( V_14 , L_118
L_119
L_120 ,
V_149 -> V_152 . V_212 , V_149 -> V_152 . V_495 ,
V_149 -> V_152 . V_178 , V_7 ,
F_26 ( & V_149 -> V_213 ) ) ;
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
if ( V_142 )
F_7 ( V_14 , L_121
L_122 , V_142 ) ;
}
if ( V_463 ) {
F_39 ( & V_496 ) ;
F_143 ( V_149 , 1 ) ;
V_7 -> V_497 = V_149 ;
V_457 . V_6 = V_498 ;
V_457 . V_490 = 0 ;
V_457 . V_497 = V_7 -> V_497 ;
V_457 . V_491 = V_7 -> V_492 ;
V_457 . V_493 = V_7 -> V_494 ;
V_457 . V_388 = NULL ;
V_457 . V_387 = 0 ;
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
if ( V_142 )
F_7 ( V_14 , L_123 , V_142 ) ;
V_7 -> V_207 ( V_7 ) ;
}
}
return 0 ;
}
static int F_143 ( struct V_146 * V_149 , int V_499 )
{
int V_142 = 0 ;
struct V_298 * V_288 ;
struct V_328 * V_289 ;
struct V_500 * V_501 ;
V_288 = F_141 ( V_149 -> V_341 . V_469 ) ;
if ( ! V_288 )
return - V_43 ;
V_289 = V_288 -> V_289 ;
V_501 = V_288 -> V_501 ;
F_7 ( V_14 , L_124 ,
F_144 ( V_288 -> V_90 ) ) ;
if ( V_149 -> V_502 ) {
V_149 -> V_502 = 0 ;
} else {
if ( V_149 -> V_503 ) {
if ( V_149 -> V_504 )
V_501 -> V_505 . V_506 ( V_149 -> V_504 ) ;
F_145 ( V_289 -> V_290 ,
V_149 -> V_387 + V_149 -> V_507 ,
V_149 -> V_503 , V_149 -> V_508 ) ;
}
}
if ( V_149 -> V_2 ) {
F_7 ( V_14 , L_125 ) ;
V_226 -> V_412 -> V_509 ( V_226 , V_149 -> V_2 ) ;
}
return V_142 ;
}
int F_146 ( struct V_201 * V_7 , struct V_510 * V_511 )
{
T_4 V_148 ;
struct V_512 * V_341 ;
struct V_146 * V_149 ;
struct V_298 * V_288 ;
struct V_328 * V_289 ;
struct V_1 * V_2 ;
struct V_307 * V_513 ;
struct V_514 V_515 ;
struct V_456 V_457 ;
struct V_150 * V_151 ;
struct V_516 V_517 ;
T_3 V_518 ;
int V_142 ;
int V_359 ;
struct V_500 * V_501 ;
struct V_519 * V_520 = NULL ;
struct V_521 * V_522 ;
T_4 V_523 ;
T_1 V_524 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
struct V_525 * V_526 = (struct V_525 * ) & V_7 -> V_492 ;
struct V_525 * V_527 = (struct V_525 * ) & V_7 -> V_494 ;
V_341 = F_147 ( V_7 -> V_469 , V_511 -> V_528 ) ;
if ( ! V_341 )
return - V_43 ;
V_149 = F_148 ( V_341 ) ;
V_288 = F_141 ( V_149 -> V_341 . V_469 ) ;
V_289 = V_288 -> V_289 ;
V_513 = V_289 -> V_308 ;
V_2 = (struct V_1 * ) V_7 -> V_497 ;
F_7 ( V_14 , L_126
L_127 , V_2 , V_288 , V_288 -> V_90 ,
V_288 -> V_90 -> V_529 ) ;
if ( V_286 == V_2 -> V_32 ) {
if ( V_2 -> V_284 )
F_4 ( V_2 -> V_3 , V_2 -> V_284 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_359 = F_119 ( 1 , & V_2 -> V_359 ) ;
if ( V_359 == V_394 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_476 ;
}
V_149 -> V_2 = ( void * ) V_2 ;
V_2 -> V_149 = V_149 ;
F_7 ( V_14 , L_128 ,
V_149 -> V_152 . V_212 , V_2 , V_189 , V_2 -> V_275 ) ;
F_39 ( & V_530 ) ;
F_7 ( V_14 , L_124 ,
F_144 ( V_288 -> V_90 ) ) ;
V_149 -> V_507 = sizeof( struct V_36 ) ;
V_149 -> V_503 = F_149 ( V_289 -> V_290 ,
V_149 -> V_507 + V_511 -> V_387 ,
& V_149 -> V_508 ) ;
if ( ! V_149 -> V_503 ) {
F_7 ( V_14 , L_129 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_149 -> V_503 ;
if ( V_2 -> V_48 == V_46 )
V_524 = 4 ;
if ( V_2 -> V_48 == V_46 ||
V_2 -> V_64 == V_62 ) {
F_27 ( V_2 , ( T_2 ) V_511 -> V_531 , ( T_2 ) V_511 -> V_532 ) ;
}
memcpy ( V_37 -> V_533 , V_511 -> V_388 ,
V_511 -> V_387 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_149 -> V_503 , V_28 ) ;
V_149 -> V_387 = V_511 -> V_387 ;
V_151 = & V_149 -> V_152 . V_153 [ 0 ] ;
if ( V_527 -> V_534 . V_535 != V_526 -> V_534 . V_535 ) {
V_148 = ( unsigned long ) V_149 ;
V_501 = V_288 -> V_501 ;
V_522 = V_149 -> V_522 ;
V_523 = ( T_4 ) ( unsigned long ) * V_19 ;
V_520 = F_150 ( & V_522 -> V_536 ,
V_149 -> V_508 + V_524 ,
V_20 , V_537 ,
& V_523 ) ;
if ( F_78 ( V_520 ) ) {
F_7 ( V_14 , L_130
L_131 ,
V_2 ) ;
F_145 ( V_289 -> V_290 ,
V_149 -> V_387 + V_149 -> V_507 ,
V_149 -> V_503 , V_149 -> V_508 ) ;
return F_151 ( V_520 ) ;
}
V_520 -> V_538 = & V_522 -> V_536 ;
V_520 -> V_469 = V_522 -> V_536 . V_469 ;
V_149 -> V_504 = V_520 ;
V_148 |= V_155 >> 1 ;
F_31 ( V_151 -> V_156 ,
V_157 ,
V_148 ) ;
V_151 -> V_156 [ V_160 ] =
F_32 ( V_539 |
V_540 ) ;
V_151 -> V_156 [ V_162 ] =
F_32 ( V_20 ) ;
F_31 ( V_151 -> V_156 ,
V_158 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_151 -> V_156 [ V_163 ] =
F_32 ( V_20 ) ;
V_151 -> V_156 [ V_164 ] = V_520 -> V_541 ;
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
V_7 -> V_497 = V_149 ;
V_149 -> V_502 = 0 ;
if ( V_2 -> V_32 == V_232 )
F_7 ( V_14 , L_132 ,
V_2 ) ;
F_135 ( V_149 , V_2 ) ;
V_149 -> V_172 -> V_542 [ 0 ] =
F_152 ( V_2 -> V_13 ) ;
V_149 -> V_172 -> V_542 [ 1 ] =
F_152 ( V_2 -> V_12 ) ;
V_149 -> V_172 -> V_543 = F_32 ( V_2 -> V_10 ) ;
V_149 -> V_172 -> V_428 |= F_32 (
( T_3 ) F_72 ( V_289 -> V_290 -> V_291 ) <<
V_544 ) ;
V_149 -> V_172 -> V_545 |=
F_32 ( F_86 ( V_289 ,
F_136 ( V_149 -> V_172 -> V_543 ) , NULL ,
V_323 ) << 16 ) ;
V_149 -> V_172 -> V_546 = F_32 (
V_189 - F_153 ( V_289 , V_547 ) ) ;
V_149 -> V_172 -> V_548 = F_32 ( V_149 -> V_152 . V_212 ) ;
V_149 -> V_172 -> V_173 |= F_32 (
( ( T_3 ) 1 << V_549 ) ) ;
V_149 -> V_172 -> V_173 |=
F_32 ( ( T_3 ) V_2 -> V_56 ) ;
memset ( & V_517 , 0 , sizeof( V_517 ) ) ;
V_517 . V_550 =
F_32 ( ( T_3 ) F_72 ( V_289 -> V_290 -> V_291 ) << 24 ) ;
V_517 . V_551 = F_23 ( V_2 -> V_10 ) ;
V_517 . V_552 [ 0 ] = F_22 ( V_2 -> V_12 ) ;
V_517 . V_552 [ 1 ] = F_22 ( V_2 -> V_13 ) ;
V_518 = F_154 ( & V_517 ) ;
V_149 -> V_553 = F_123 ( V_518 ^ 0xffffffff ) ;
F_7 ( V_14 , L_133 ,
V_149 -> V_553 , V_149 -> V_553 & V_513 -> V_554 ) ;
V_149 -> V_553 &= V_513 -> V_554 ;
V_149 -> V_172 -> V_553 = F_32 ( V_149 -> V_553 ) ;
V_2 -> V_3 -> V_412 -> V_281 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_134
L_135
L_136 , V_149 -> V_152 . V_212 ,
F_37 ( V_527 -> V_534 . V_535 ) , F_16 ( V_527 -> V_555 ) ,
F_37 ( V_526 -> V_534 . V_535 ) , F_16 ( V_526 -> V_555 ) ,
F_136 ( V_149 -> V_172 -> V_120 ) ,
F_136 ( V_149 -> V_172 -> V_442 ) ,
V_20 ) ;
V_7 -> V_395 ( V_7 ) ;
F_137 ( & V_149 -> V_341 ) ;
V_457 . V_6 = V_556 ;
V_457 . V_490 = 0 ;
V_457 . V_497 = ( void * ) V_149 ;
V_457 . V_491 = V_7 -> V_492 ;
V_457 . V_493 = V_7 -> V_494 ;
V_457 . V_388 = NULL ;
V_457 . V_387 = 0 ;
V_457 . V_531 = V_2 -> V_55 ;
V_457 . V_532 = V_2 -> V_56 ;
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
V_515 . V_557 = V_474 ;
F_155 ( & V_149 -> V_341 , & V_515 , V_558 , NULL ) ;
if ( V_2 -> V_284 ) {
V_2 -> V_284 -> V_54 =
V_149 -> V_387 ;
memcpy ( V_2 -> V_284 -> V_73 ,
V_511 -> V_388 , V_511 -> V_387 ) ;
F_5 ( V_2 -> V_284 , V_367 ) ;
}
if ( V_142 )
F_79 ( V_312 L_137
L_138 , V_67 , __LINE__ , V_142 ) ;
return 0 ;
}
int F_156 ( struct V_201 * V_7 , const void * V_559 , T_1 V_560 )
{
struct V_1 * V_2 ;
struct V_1 * V_283 ;
struct V_134 * V_3 ;
T_1 * V_19 ;
F_39 ( & V_561 ) ;
V_2 = (struct V_1 * ) V_7 -> V_497 ;
V_283 = V_2 -> V_284 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_560 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_283 ) {
memcpy ( & V_283 -> V_25 . V_533 , V_559 , V_560 ) ;
V_283 -> V_25 . V_41 = V_560 ;
V_283 -> V_54 = V_560 ;
} else {
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_560 ;
memcpy ( V_19 , V_559 , V_560 ) ;
}
return V_3 -> V_412 -> V_562 ( V_3 , V_2 ) ;
}
int F_157 ( struct V_201 * V_7 , struct V_510 * V_511 )
{
struct V_512 * V_341 ;
struct V_146 * V_149 ;
struct V_298 * V_288 ;
struct V_328 * V_289 ;
struct V_1 * V_2 ;
struct V_324 V_9 ;
int V_338 = 0 ;
struct V_525 * V_526 = (struct V_525 * ) & V_7 -> V_492 ;
struct V_525 * V_527 = (struct V_525 * ) & V_7 -> V_494 ;
if ( V_7 -> V_493 . V_563 != V_564 )
return - V_565 ;
V_341 = F_147 ( V_7 -> V_469 , V_511 -> V_528 ) ;
if ( ! V_341 )
return - V_43 ;
V_149 = F_148 ( V_341 ) ;
if ( ! V_149 )
return - V_43 ;
V_288 = F_141 ( V_149 -> V_341 . V_469 ) ;
if ( ! V_288 )
return - V_43 ;
V_289 = V_288 -> V_289 ;
if ( ! V_289 )
return - V_43 ;
if ( ! V_526 -> V_555 || ! V_527 -> V_555 )
return - V_43 ;
F_7 ( V_14 , L_139
L_140 , V_149 -> V_152 . V_212 ,
F_37 ( V_288 -> V_311 ) , F_37 ( V_527 -> V_534 . V_535 ) ,
F_16 ( V_527 -> V_555 ) , F_37 ( V_526 -> V_534 . V_535 ) ,
F_16 ( V_526 -> V_555 ) ) ;
F_39 ( & V_566 ) ;
V_149 -> V_502 = 1 ;
V_149 -> V_7 = V_7 ;
V_7 -> V_497 = V_149 ;
V_149 -> V_387 = V_511 -> V_387 ;
F_7 ( V_14 , L_141 , ( T_3 ) V_511 -> V_532 ) ;
F_7 ( V_14 , L_142 ,
V_511 -> V_387 ) ;
V_9 . V_11 = F_37 ( V_526 -> V_534 . V_535 ) ;
V_9 . V_13 = F_16 ( V_526 -> V_555 ) ;
V_9 . V_10 = F_37 ( V_527 -> V_534 . V_535 ) ;
V_9 . V_12 = F_16 ( V_527 -> V_555 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_337 = V_567 ;
if ( V_526 -> V_534 . V_535 != V_527 -> V_534 . V_535 ) {
F_71 ( V_288 , V_9 . V_13 ,
F_72 ( V_289 -> V_290 -> V_291 ) ,
V_568 ) ;
V_338 = 1 ;
}
V_7 -> V_395 ( V_7 ) ;
V_2 = V_226 -> V_412 -> V_569 ( V_226 , V_288 ,
V_511 -> V_387 , ( void * ) V_511 -> V_388 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_338 )
F_71 ( V_288 , V_9 . V_13 ,
F_72 ( V_289 -> V_290 -> V_291 ) ,
V_292 ) ;
F_7 ( V_293 , L_143 ,
V_9 . V_13 ) ;
V_7 -> V_207 ( V_7 ) ;
return - V_27 ;
}
F_27 ( V_2 , ( T_2 ) V_511 -> V_531 , ( T_2 ) V_511 -> V_532 ) ;
if ( V_2 -> V_69 == V_70 &&
V_2 -> V_56 == 0 )
V_2 -> V_56 = 1 ;
V_2 -> V_338 = V_338 ;
V_2 -> V_106 = V_7 -> V_106 ;
V_149 -> V_2 = V_2 ;
V_2 -> V_149 = V_149 ;
F_137 ( & V_149 -> V_341 ) ;
return 0 ;
}
int F_158 ( struct V_201 * V_7 , int V_369 )
{
struct V_298 * V_288 ;
struct V_264 * V_2 ;
struct V_324 V_9 ;
int V_277 ;
struct V_525 * V_526 = (struct V_525 * ) & V_7 -> V_492 ;
F_7 ( V_14 , L_144 ,
V_7 , F_16 ( V_526 -> V_555 ) ) ;
if ( V_7 -> V_492 . V_563 != V_564 )
return - V_565 ;
V_288 = F_141 ( V_7 -> V_469 ) ;
if ( ! V_288 )
return - V_43 ;
F_7 ( V_14 , L_145 ,
V_288 , V_288 -> V_90 , V_288 -> V_90 -> V_529 ) ;
F_7 ( V_14 , L_146 ,
V_288 -> V_311 , V_526 -> V_534 . V_535 ) ;
V_9 . V_11 = F_37 ( V_288 -> V_311 ) ;
V_9 . V_13 = F_16 ( V_526 -> V_555 ) ;
V_9 . V_369 = V_369 ;
V_9 . V_7 = V_7 ;
V_9 . V_337 = V_567 ;
V_2 = V_226 -> V_412 -> V_570 ( V_226 , V_288 , & V_9 ) ;
if ( ! V_2 ) {
F_79 ( V_312 L_147 ,
V_67 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_497 = V_2 ;
V_2 -> V_106 = V_7 -> V_106 ;
if ( ! V_2 -> V_385 ) {
V_277 = F_71 ( V_288 , V_2 -> V_13 ,
F_72 ( V_288 -> V_289 -> V_290 -> V_291 ) ,
V_568 ) ;
if ( V_277 ) {
F_79 ( V_312 L_148 ,
V_277 ) ;
V_226 -> V_412 -> V_571 ( V_226 , ( void * ) V_2 ) ;
return V_277 ;
}
F_39 ( & V_572 ) ;
}
V_7 -> V_395 ( V_7 ) ;
V_7 -> V_497 = ( void * ) V_2 ;
return 0 ;
}
int F_159 ( struct V_201 * V_7 )
{
if ( V_7 -> V_497 )
V_226 -> V_412 -> V_571 ( V_226 , V_7 -> V_497 ) ;
else
F_7 ( V_14 , L_149 ) ;
V_7 -> V_207 ( V_7 ) ;
return 0 ;
}
int F_160 ( struct V_15 * V_16 , struct V_306 * V_573 )
{
int V_305 = 0 ;
V_574 ++ ;
if ( ( V_226 ) && ( V_226 -> V_412 ) )
V_305 = V_226 -> V_412 -> V_575 ( V_226 , F_161 ( V_573 ) , V_16 ) ;
else
F_7 ( V_14 , L_150
L_151 ) ;
return V_305 ;
}
int F_162 ( void )
{
F_7 ( V_14 , L_107 ) ;
V_226 = F_126 () ;
if ( V_226 )
return 0 ;
else
return - V_27 ;
}
int F_163 ( void )
{
V_226 -> V_412 -> V_576 ( V_226 ) ;
return 0 ;
}
static void F_164 ( struct V_4 * V_6 )
{
struct V_146 * V_149 ;
struct V_298 * V_288 ;
struct V_328 * V_289 ;
struct V_1 * V_2 ;
struct V_307 * V_308 ;
struct V_514 V_515 ;
struct V_201 * V_7 ;
struct V_456 V_457 ;
struct V_516 V_517 ;
T_3 V_518 ;
int V_142 ;
struct V_525 * V_526 ;
struct V_525 * V_527 ;
struct V_525 * V_577 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_152 , V_2 , V_7 ) ;
V_149 = (struct V_146 * ) V_7 -> V_497 ;
V_288 = F_141 ( V_149 -> V_341 . V_469 ) ;
V_289 = V_288 -> V_289 ;
V_308 = V_289 -> V_308 ;
V_526 = (struct V_525 * ) & V_7 -> V_492 ;
V_527 = (struct V_525 * ) & V_7 -> V_494 ;
V_577 = (struct V_525 * ) & V_457 . V_491 ;
if ( V_149 -> V_479 )
return;
F_39 ( & V_578 ) ;
F_7 ( V_14 , L_153
L_154 ,
V_149 -> V_152 . V_212 , F_37 ( V_527 -> V_534 . V_535 ) ,
F_16 ( V_527 -> V_555 ) , F_16 ( V_526 -> V_555 ) , V_189 ) ;
F_135 ( V_149 , V_2 ) ;
V_149 -> V_172 -> V_542 [ 0 ] =
F_152 ( V_2 -> V_13 ) ;
V_149 -> V_172 -> V_542 [ 1 ] =
F_152 ( V_2 -> V_12 ) ;
V_149 -> V_172 -> V_543 = F_32 ( V_2 -> V_10 ) ;
V_149 -> V_172 -> V_428 |= F_32 (
( T_3 ) F_72 ( V_289 -> V_290 -> V_291 ) <<
V_544 ) ;
V_149 -> V_172 -> V_545 |= F_32 (
F_86 ( V_289 ,
F_136 ( V_149 -> V_172 -> V_543 ) ,
NULL , V_323 ) << 16 ) ;
V_149 -> V_172 -> V_546 = F_32 (
V_189 - F_153 ( V_289 , V_547 ) ) ;
V_149 -> V_172 -> V_548 = F_32 ( V_149 -> V_152 . V_212 ) ;
V_149 -> V_172 -> V_173 |=
F_32 ( ( T_3 ) 1 <<
V_549 ) ;
V_149 -> V_172 -> V_173 |=
F_32 ( ( T_3 ) V_2 -> V_56 ) ;
F_30 ( V_2 , & V_149 ) ;
F_165 ( V_289 -> V_579 + V_580 ,
( 1 << 24 ) | 0x00800000 | V_149 -> V_152 . V_212 ) ;
memset ( & V_517 , 0 , sizeof( V_517 ) ) ;
V_517 . V_550 =
F_32 ( ( T_3 ) F_72 ( V_289 -> V_290 -> V_291 ) << 24 ) ;
V_517 . V_551 = F_23 ( V_2 -> V_10 ) ;
V_517 . V_552 [ 0 ] = F_22 ( V_2 -> V_12 ) ;
V_517 . V_552 [ 1 ] = F_22 ( V_2 -> V_13 ) ;
V_518 = F_154 ( & V_517 ) ;
V_149 -> V_553 = F_123 ( V_518 ^ 0xffffffff ) ;
F_7 ( V_14 , L_155 ,
V_149 -> V_553 , V_149 -> V_553 & V_308 -> V_554 ) ;
V_149 -> V_553 &= V_308 -> V_554 ;
V_149 -> V_172 -> V_553 = F_32 ( V_149 -> V_553 ) ;
V_149 -> V_503 = & V_2 -> V_25 ;
V_149 -> V_387 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_412 -> V_281 ( V_2 -> V_3 , V_2 ) ;
V_457 . V_6 = V_581 ;
V_457 . V_490 = 0 ;
V_457 . V_497 = V_7 -> V_497 ;
V_577 -> V_582 = V_564 ;
V_577 -> V_555 = V_526 -> V_555 ;
V_457 . V_493 = V_7 -> V_494 ;
V_457 . V_388 = ( void * ) V_6 -> V_2 -> V_73 ;
V_457 . V_387 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_457 . V_531 = V_2 -> V_55 ;
V_457 . V_532 = V_2 -> V_56 ;
V_577 -> V_534 . V_535 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
F_7 ( V_14 , L_123 , V_142 ) ;
if ( V_142 )
F_79 ( V_312 L_137
L_138 , V_67 , __LINE__ , V_142 ) ;
V_515 . V_557 = V_474 ;
F_155 ( & V_149 -> V_341 , & V_515 , V_558 , NULL ) ;
F_7 ( V_14 , L_156
L_157 , V_149 -> V_152 . V_212 , V_189 ) ;
return;
}
static void F_67 ( struct V_4 * V_6 )
{
struct V_146 * V_149 ;
struct V_201 * V_7 ;
struct V_456 V_457 ;
int V_142 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_158 , V_6 -> V_2 , V_7 ) ;
V_149 = V_7 -> V_497 ;
if ( ! V_149 )
return;
V_149 -> V_7 = NULL ;
V_7 -> V_497 = NULL ;
V_457 . V_6 = V_581 ;
V_457 . V_490 = - V_476 ;
V_457 . V_497 = V_7 -> V_497 ;
V_457 . V_491 = V_7 -> V_492 ;
V_457 . V_493 = V_7 -> V_494 ;
V_457 . V_388 = NULL ;
V_457 . V_387 = 0 ;
#ifdef F_166
{
struct V_525 * V_577 = (struct V_525 * )
& V_457 . V_491 ;
struct V_525 * V_583 = (struct V_525 * )
& V_457 . V_493 ;
F_7 ( V_14 , L_159 ,
V_577 -> V_534 . V_535 , V_583 -> V_534 . V_535 ) ;
}
#endif
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
F_7 ( V_14 , L_123 , V_142 ) ;
if ( V_142 )
F_79 ( V_312 L_137
L_138 , V_67 , __LINE__ , V_142 ) ;
V_7 -> V_207 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_167 ( struct V_4 * V_6 )
{
struct V_146 * V_149 ;
struct V_201 * V_7 ;
struct V_456 V_457 ;
int V_142 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_160 , V_6 -> V_2 , V_7 ) ;
V_149 = V_7 -> V_497 ;
if ( ! V_149 )
return;
V_149 -> V_7 = NULL ;
V_457 . V_6 = V_489 ;
V_457 . V_490 = - V_476 ;
V_457 . V_497 = V_7 -> V_497 ;
V_457 . V_491 = V_7 -> V_492 ;
V_457 . V_493 = V_7 -> V_494 ;
V_457 . V_388 = NULL ;
V_457 . V_387 = 0 ;
V_7 -> V_395 ( V_7 ) ;
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
F_39 ( & V_496 ) ;
V_457 . V_6 = V_498 ;
V_457 . V_490 = 0 ;
V_457 . V_497 = V_7 -> V_497 ;
V_457 . V_491 = V_7 -> V_492 ;
V_457 . V_493 = V_7 -> V_494 ;
V_457 . V_388 = NULL ;
V_457 . V_387 = 0 ;
F_7 ( V_14 , L_161 , V_6 -> V_2 ) ;
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
F_7 ( V_14 , L_123 , V_142 ) ;
V_7 -> V_207 ( V_7 ) ;
return;
}
static void F_168 ( struct V_4 * V_6 )
{
struct V_201 * V_7 ;
struct V_456 V_457 ;
int V_142 ;
struct V_1 * V_2 ;
struct V_525 * V_577 = (struct V_525 * )
& V_457 . V_491 ;
struct V_525 * V_583 = (struct V_525 * )
& V_457 . V_493 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_39 ( & V_584 ) ;
F_7 ( V_14 , L_162 ,
V_2 , V_7 , V_189 ) ;
V_457 . V_6 = V_585 ;
V_457 . V_490 = 0 ;
V_457 . V_497 = ( void * ) V_2 ;
V_577 -> V_582 = V_564 ;
V_577 -> V_555 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_577 -> V_534 . V_535 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_583 -> V_582 = V_564 ;
V_583 -> V_555 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_583 -> V_534 . V_535 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_457 . V_388 = V_2 -> V_73 ;
V_457 . V_387 = ( T_1 ) V_2 -> V_54 ;
if ( V_2 -> V_48 == V_46 ) {
V_457 . V_531 = V_65 ;
V_457 . V_532 = V_68 ;
} else {
V_457 . V_531 = V_2 -> V_55 ;
V_457 . V_532 = V_2 -> V_56 ;
}
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
if ( V_142 )
F_79 ( V_312 L_163 ,
V_67 , __LINE__ , V_142 ) ;
return;
}
static void F_120 ( struct V_4 * V_6 )
{
struct V_201 * V_7 ;
struct V_456 V_457 ;
struct V_1 * V_2 ;
int V_142 ;
struct V_525 * V_577 = (struct V_525 * )
& V_457 . V_491 ;
struct V_525 * V_583 = (struct V_525 * )
& V_457 . V_493 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_39 ( & V_584 ) ;
F_7 ( V_14 , L_162 ,
V_2 , V_7 , V_189 ) ;
V_457 . V_6 = V_581 ;
V_457 . V_490 = - V_586 ;
V_457 . V_497 = V_7 -> V_497 ;
V_577 -> V_582 = V_564 ;
V_577 -> V_555 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_577 -> V_534 . V_535 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_583 -> V_582 = V_564 ;
V_583 -> V_555 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_583 -> V_534 . V_535 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_457 . V_388 = V_2 -> V_73 ;
V_457 . V_387 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_164
L_165 ,
V_577 -> V_534 . V_535 ,
V_583 -> V_534 . V_535 ) ;
V_142 = V_7 -> V_486 ( V_7 , & V_457 ) ;
if ( V_142 )
F_79 ( V_312 L_163 ,
V_67 , __LINE__ , V_142 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_39 ( & V_6 -> V_2 -> V_3 -> V_411 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_395 ( V_6 -> V_9 . V_7 ) ;
F_138 ( & V_6 -> V_587 , V_588 ) ;
F_7 ( V_14 , L_166 ,
V_6 -> V_2 , V_6 ) ;
F_139 ( V_6 -> V_2 -> V_3 -> V_414 , & V_6 -> V_587 ) ;
F_7 ( V_14 , L_167 ) ;
return 0 ;
}
static void V_588 ( struct V_454 * V_452 )
{
struct V_4 * V_6 = F_53 ( V_452 , struct V_4 ,
V_587 ) ;
struct V_134 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_168 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_411 ) ) ;
switch ( V_6 -> type ) {
case V_364 :
F_168 ( V_6 ) ;
F_7 ( V_14 , L_169 ,
V_6 -> V_2 ) ;
break;
case V_589 :
F_7 ( V_14 , L_170 ,
V_6 -> V_2 ) ;
F_167 ( V_6 ) ;
break;
case V_367 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_232 ) )
break;
F_164 ( V_6 ) ;
F_7 ( V_14 , L_171 ) ;
break;
case V_366 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_232 ) )
break;
F_120 ( V_6 ) ;
F_7 ( V_14 , L_172 ) ;
break;
case V_208 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_232 ) )
break;
F_67 ( V_6 ) ;
F_7 ( V_14 , L_173 ) ;
break;
case V_590 :
F_7 ( V_14 , L_174 ) ;
break;
default:
F_7 ( V_14 , L_175 ) ;
break;
}
F_70 ( & V_3 -> V_411 ) ;
V_6 -> V_9 . V_7 -> V_207 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_35 ( V_6 ) ;
return;
}
