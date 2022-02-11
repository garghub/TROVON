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
V_25 -> V_29 = V_144 ;
V_25 -> V_45 = V_2 -> V_48 ;
V_25 -> V_41 = F_22 ( V_2 -> V_54 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_145 * * V_146 )
{
T_4 V_147 ;
struct V_145 * V_148 = * V_146 ;
struct V_149 * V_150 = & V_148 -> V_151 . V_152 [ 0 ] ;
V_147 = ( unsigned long ) V_148 -> V_153 ;
V_147 |= V_154 >> 1 ;
F_31 ( V_150 -> V_155 , V_156 , V_147 ) ;
V_150 -> V_155 [ V_157 ] = 0 ;
V_150 -> V_155 [ V_158 ] = 0 ;
switch ( V_2 -> V_69 ) {
case V_72 :
F_7 ( V_14 , L_26 ) ;
V_150 -> V_155 [ V_159 ] =
F_32 ( V_160 ) ;
V_150 -> V_155 [ V_161 ] = 0 ;
V_150 -> V_155 [ V_162 ] = 0 ;
V_150 -> V_155 [ V_163 ] = 0 ;
break;
case V_70 :
default:
if ( V_2 -> V_69 != V_70 )
F_33 ( 1 , L_27 ,
V_2 -> V_69 ) ;
F_7 ( V_14 , L_28 ) ;
V_150 -> V_155 [ V_159 ] =
F_32 ( V_164 ) ;
V_150 -> V_155 [ V_165 ] = 1 ;
V_150 -> V_155 [ V_166 ] = 0 ;
V_150 -> V_155 [ V_167 ] = 0 ;
V_150 -> V_155 [ V_168 ] = 1 ;
V_150 -> V_155 [ V_163 ] = 1 ;
break;
}
if ( V_148 -> V_169 ) {
V_148 -> V_169 = 0 ;
F_34 ( V_148 -> V_170 ) ;
}
V_148 -> V_171 -> V_172 &= F_32 ( ~ ( V_173 |
V_174 |
V_175 ) ) ;
V_148 -> V_176 = 1 ;
V_148 -> V_151 . V_177 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_178 type , int V_179 ,
int V_180 )
{
unsigned long V_29 ;
struct V_134 * V_3 = V_2 -> V_3 ;
struct V_181 * V_182 ;
int V_142 = 0 ;
V_182 = F_6 ( sizeof( * V_182 ) , V_8 ) ;
if ( ! V_182 )
return - V_27 ;
V_182 -> V_183 = V_184 ;
V_182 -> V_185 = V_186 ;
V_182 -> V_16 = V_16 ;
V_182 -> V_187 = V_188 ;
V_182 -> type = type ;
V_182 -> V_90 = V_2 -> V_90 ;
V_182 -> V_179 = V_179 ;
V_182 -> V_180 = V_180 ;
if ( type == V_189 ) {
V_182 -> V_187 += ( V_190 / 10 ) ;
if ( V_2 -> V_191 ) {
F_35 ( V_182 ) ;
F_36 ( 1 ) ;
return - V_43 ;
}
V_2 -> V_191 = V_182 ;
}
if ( type == V_23 ) {
V_182 -> V_192 = F_37 ( F_38 ( V_16 ) -> V_117 ) ;
F_39 ( & V_182 -> V_16 -> V_193 ) ;
F_40 ( & V_2 -> V_194 , V_29 ) ;
V_2 -> V_195 = V_182 ;
F_2 ( V_2 ) ;
F_41 ( & V_2 -> V_194 , V_29 ) ;
V_182 -> V_187 = V_188 + V_196 ;
V_142 = F_42 ( V_182 -> V_16 , V_2 -> V_90 ) ;
if ( V_142 != V_197 ) {
F_7 ( V_14 , L_29
L_30 , V_182 , V_188 ) ;
V_182 -> V_187 = V_188 ;
V_142 = V_197 ;
} else {
V_198 ++ ;
if ( ! V_179 ) {
F_43 ( V_2 ) ;
if ( V_180 )
F_4 ( V_3 , V_2 ) ;
return V_142 ;
}
}
}
if ( ! F_44 ( & V_3 -> V_199 ) )
F_45 ( & V_3 -> V_199 , V_182 -> V_187 ) ;
return V_142 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_200 * V_7 = V_2 -> V_7 ;
enum V_201 V_32 = V_2 -> V_32 ;
V_2 -> V_32 = V_202 ;
switch ( V_32 ) {
case V_203 :
case V_204 :
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_205 :
case V_33 :
if ( V_2 -> V_7 )
V_7 -> V_206 ( V_7 ) ;
F_47 ( V_2 , NULL ) ;
break;
default:
F_2 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
F_5 ( V_2 , V_207 ) ;
}
}
static void F_48 ( struct V_1 * V_2 , T_3 V_208 )
{
struct V_181 * V_191 = V_2 -> V_191 ;
struct V_200 * V_7 = V_2 -> V_7 ;
struct V_145 * V_148 ;
unsigned long V_209 ;
if ( ! V_191 )
return;
V_148 = (struct V_145 * ) V_191 -> V_16 ;
if ( V_148 ) {
F_40 ( & V_148 -> V_210 , V_209 ) ;
if ( V_148 -> V_7 ) {
F_7 ( V_14 , L_31
L_32
L_33
L_34 , V_148 -> V_151 . V_211 , V_7 ,
F_26 ( & V_148 -> V_212 ) ) ;
V_148 -> V_213 = V_214 ;
V_148 -> V_215 = V_216 ;
V_148 -> V_217 = V_218 ;
F_41 ( & V_148 -> V_210 , V_209 ) ;
F_49 ( V_148 ) ;
} else {
F_41 ( & V_148 -> V_210 , V_209 ) ;
F_7 ( V_14 , L_31
L_32
L_35
L_34 , V_148 -> V_151 . V_211 , V_7 ,
F_26 ( & V_148 -> V_212 ) ) ;
}
} else if ( V_208 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_2 -> V_7 )
V_7 -> V_206 ( V_7 ) ;
F_35 ( V_191 ) ;
V_2 -> V_191 = NULL ;
}
static void F_50 ( unsigned long V_219 )
{
unsigned long V_29 ;
unsigned long V_220 = V_188 + V_221 ;
struct V_1 * V_2 ;
struct V_181 * V_195 , * V_191 ;
struct V_222 * V_223 ;
struct V_222 * V_224 ;
struct V_134 * V_3 = V_225 ;
T_3 V_226 = 0 ;
unsigned long V_187 ;
int V_142 = V_197 ;
struct V_222 V_227 ;
F_51 ( & V_227 ) ;
F_40 ( & V_3 -> V_228 , V_29 ) ;
F_52 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_2 = F_53 ( V_224 , struct V_1 , V_229 ) ;
if ( ( V_2 -> V_191 ) || ( V_2 -> V_195 ) ) {
F_2 ( V_2 ) ;
F_54 ( & V_2 -> V_230 , & V_227 ) ;
}
}
F_41 ( & V_3 -> V_228 , V_29 ) ;
F_52 (list_node, list_core_temp, &timer_list) {
V_2 = F_53 ( V_224 , struct V_1 ,
V_230 ) ;
V_191 = V_2 -> V_191 ;
if ( V_191 ) {
if ( F_55 ( V_191 -> V_187 , V_188 ) ) {
if ( V_220 > V_191 -> V_187 ||
! V_226 ) {
V_220 = V_191 -> V_187 ;
V_226 = 1 ;
}
} else {
F_48 ( V_2 , 1 ) ;
}
}
F_40 ( & V_2 -> V_194 , V_29 ) ;
do {
V_195 = V_2 -> V_195 ;
if ( ! V_195 )
break;
if ( F_55 ( V_195 -> V_187 , V_188 ) ) {
if ( V_2 -> V_32 != V_231 ) {
if ( ( V_220 >
V_195 -> V_187 ) ||
! V_226 ) {
V_220 =
V_195 -> V_187 ;
V_226 = 1 ;
}
} else {
F_56 ( V_2 ) ;
}
break;
}
if ( ( V_2 -> V_32 == V_231 ) ||
( V_2 -> V_32 == V_202 ) ) {
F_56 ( V_2 ) ;
break;
}
if ( ! V_195 -> V_185 ||
! V_195 -> V_183 ) {
V_232 ++ ;
F_56 ( V_2 ) ;
F_41 (
& V_2 -> V_194 , V_29 ) ;
F_46 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
F_40 ( & V_2 -> V_194 ,
V_29 ) ;
break;
}
F_39 ( & V_195 -> V_16 -> V_193 ) ;
V_233 ++ ;
F_7 ( V_14 , L_36
L_37
L_38
L_39
L_40 , V_195 , V_2 , V_188 ,
V_195 -> V_187 ,
V_195 -> V_185 ,
V_195 -> V_192 ,
V_2 -> V_109 . V_234 ) ;
F_41 ( & V_2 -> V_194 ,
V_29 ) ;
V_142 = F_42 ( V_195 -> V_16 , V_2 -> V_90 ) ;
F_40 ( & V_2 -> V_194 , V_29 ) ;
if ( V_142 != V_197 ) {
F_7 ( V_14 , L_41
L_42 , V_2 ) ;
V_235 ++ ;
V_195 -> V_183 -- ;
V_220 = V_188 + V_236 ;
V_226 = 1 ;
break;
} else {
V_198 ++ ;
}
F_7 ( V_14 , L_43
L_44 ,
V_195 -> V_185 ,
V_195 -> V_183 ) ;
if ( V_195 -> V_179 ) {
V_195 -> V_185 -- ;
V_187 = ( V_196 <<
( V_186 - V_195 -> V_185 ) ) ;
V_195 -> V_187 = V_188 +
F_57 ( V_187 , V_237 ) ;
if ( V_220 > V_195 -> V_187 ||
! V_226 ) {
V_220 = V_195 -> V_187 ;
V_226 = 1 ;
}
} else {
int V_180 ;
V_180 =
V_195 -> V_180 ;
F_7 ( V_14 , L_45 ,
V_2 , V_2 -> V_32 ) ;
F_56 ( V_2 ) ;
if ( V_180 )
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
} while ( 0 );
F_41 ( & V_2 -> V_194 , V_29 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_226 ) {
if ( ! F_44 ( & V_3 -> V_199 ) )
F_45 ( & V_3 -> V_199 , V_220 ) ;
}
}
static int F_58 ( struct V_1 * V_2 , T_3 V_238 ,
struct V_15 * V_16 )
{
int V_142 ;
int V_29 = V_123 ;
char V_239 [ sizeof( struct V_240 ) +
sizeof( struct V_241 ) + sizeof( struct V_242 ) +
V_243 ] ;
int V_244 = 0 ;
union V_245 * V_75 ;
if ( ! V_2 )
return - V_43 ;
V_75 = (union V_245 * ) & V_239 [ V_244 ] ;
V_75 -> V_246 . V_247 = V_248 ;
V_75 -> V_246 . V_249 = sizeof( struct V_240 ) ;
V_75 -> V_246 . V_250 = F_22 ( V_2 -> V_109 . V_250 ) ;
V_244 += sizeof( struct V_240 ) ;
V_75 = (union V_245 * ) & V_239 [ V_244 ] ;
V_75 -> V_251 . V_247 = V_252 ;
V_75 -> V_251 . V_249 = sizeof( struct V_241 ) ;
V_75 -> V_251 . V_253 = V_2 -> V_109 . V_254 ;
V_244 += sizeof( struct V_241 ) ;
if ( V_238 && ! ( V_255 & V_256 ) ) {
V_75 = (union V_245 * ) & V_239 [ V_244 ] ;
V_75 -> V_257 . V_247 = V_258 ;
V_75 -> V_257 . V_249 = sizeof( struct V_242 ) ;
V_244 += sizeof( struct V_242 ) ;
V_75 = (union V_245 * ) & V_239 [ V_244 ] ;
V_75 -> V_259 = 1 ;
V_244 += 1 ;
V_75 = (union V_245 * ) & V_239 [ V_244 ] ;
V_75 -> V_259 = 1 ;
V_244 += 1 ;
}
V_75 = (union V_245 * ) & V_239 [ V_244 ] ;
V_75 -> V_259 = V_260 ;
V_244 += 1 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
if ( V_238 )
V_29 |= V_22 ;
F_11 ( V_16 , V_2 , V_239 , V_244 , NULL , 0 , V_29 ) ;
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
struct V_222 * V_261 ;
struct V_1 * V_2 ;
V_261 = & V_3 -> V_262 ;
F_40 ( & V_3 -> V_228 , V_29 ) ;
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
F_41 ( & V_3 -> V_228 , V_29 ) ;
return V_2 ;
}
}
F_41 ( & V_3 -> V_228 , V_29 ) ;
return NULL ;
}
static struct V_263 * F_63 ( struct V_134 * V_3 ,
T_5 V_264 , T_2 V_265 ,
enum V_266 V_267 )
{
unsigned long V_29 ;
struct V_263 * V_268 ;
T_5 V_269 ;
T_2 V_270 ;
F_40 ( & V_3 -> V_271 , V_29 ) ;
F_62 (listen_node, &cm_core->listen_list.list, list) {
V_269 = V_268 -> V_11 ;
V_270 = V_268 -> V_13 ;
if ( ( ( V_269 == V_264 ) ||
V_269 == 0x00000000 ) &&
( V_270 == V_265 ) &&
( V_267 & V_268 -> V_267 ) ) {
F_64 ( & V_268 -> V_272 ) ;
F_41 ( & V_3 -> V_271 , V_29 ) ;
return V_268 ;
}
}
F_41 ( & V_3 -> V_271 , V_29 ) ;
return NULL ;
}
static int F_65 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_222 * V_261 ;
if ( ! V_2 || ! V_3 )
return - V_43 ;
F_7 ( V_14 , L_47 ,
V_2 ) ;
F_40 ( & V_3 -> V_228 , V_29 ) ;
V_261 = & V_3 -> V_262 ;
F_66 ( & V_2 -> V_229 , V_261 ) ;
F_64 ( & V_3 -> V_273 ) ;
F_41 ( & V_3 -> V_228 , V_29 ) ;
return 0 ;
}
static int F_67 ( struct V_134 * V_3 ,
struct V_263 * V_274 , int V_275 )
{
int V_142 = - V_43 ;
int V_276 = 0 ;
unsigned long V_29 ;
struct V_222 * V_277 = NULL ;
struct V_222 * V_278 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_222 V_279 ;
F_7 ( V_14 , L_48
L_49 , V_274 , V_275 ,
F_26 ( & V_274 -> V_272 ) ) ;
F_51 ( & V_279 ) ;
if ( V_275 ) {
F_40 ( & V_3 -> V_228 , V_29 ) ;
F_52 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_53 ( V_277 , struct V_1 ,
V_229 ) ;
if ( ( V_2 -> V_274 == V_274 ) &&
( ! V_2 -> V_280 ) ) {
F_2 ( V_2 ) ;
F_54 ( & V_2 -> V_281 , & V_279 ) ;
}
}
F_41 ( & V_3 -> V_228 , V_29 ) ;
}
F_52 (list_pos, list_temp, &reset_list) {
V_2 = F_53 ( V_277 , struct V_1 ,
V_281 ) ;
{
struct V_1 * V_282 = V_2 -> V_283 ;
enum V_201 V_284 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_282 ) {
F_43 ( V_2 ) ;
V_276 = F_47 ( V_2 , NULL ) ;
if ( V_276 ) {
V_2 -> V_32 =
V_202 ;
F_36 ( 1 ) ;
} else {
V_284 = V_2 -> V_32 ;
V_2 -> V_32 = V_285 ;
if ( V_284 != V_286 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_282 ;
V_6 . V_9 . V_10 =
V_282 -> V_10 ;
V_6 . V_9 . V_11 =
V_282 -> V_11 ;
V_6 . V_9 . V_12 =
V_282 -> V_12 ;
V_6 . V_9 . V_13 =
V_282 -> V_13 ;
V_6 . V_9 . V_7 = V_282 -> V_7 ;
F_2 ( V_282 ) ;
V_282 -> V_32 = V_202 ;
F_68 ( & V_6 ) ;
V_2 -> V_32 = V_285 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_40 ( & V_3 -> V_271 , V_29 ) ;
if ( ! F_69 ( & V_274 -> V_272 ) ) {
F_70 ( & V_274 -> V_229 ) ;
F_71 ( & V_3 -> V_136 ) ;
F_41 ( & V_3 -> V_271 , V_29 ) ;
if ( V_274 -> V_287 ) {
F_72 ( V_274 -> V_287 ,
V_274 -> V_13 ,
F_73 ( V_274 -> V_287 -> V_288 -> V_289 -> V_290 ) ,
V_291 ) ;
F_7 ( V_292 ,
L_50 ,
V_274 -> V_13 ) ;
}
F_7 ( V_14 , L_51 , V_274 ) ;
F_35 ( V_274 ) ;
V_274 = NULL ;
V_142 = 0 ;
F_64 ( & V_293 ) ;
} else {
F_41 ( & V_3 -> V_271 , V_29 ) ;
}
if ( V_274 ) {
if ( F_26 ( & V_274 -> V_294 ) > 0 )
F_7 ( V_14 , L_52
L_53 ,
V_274 , F_26 ( & V_274 -> V_294 ) ) ;
}
return V_142 ;
}
static int F_74 ( struct V_134 * V_3 ,
struct V_263 * V_274 )
{
V_274 -> V_267 = V_295 ;
V_274 -> V_7 = NULL ;
return F_67 ( V_3 , V_274 , 1 ) ;
}
static inline int F_75 ( struct V_134 * V_3 ,
struct V_1 * V_2 )
{
V_2 -> V_280 = 1 ;
if ( V_2 -> V_296 ) {
F_76 ( ! V_2 -> V_274 ) ;
F_71 ( & V_2 -> V_274 -> V_294 ) ;
V_2 -> V_296 = 0 ;
F_76 ( F_26 ( & V_2 -> V_274 -> V_294 ) < 0 ) ;
}
if ( ! F_44 ( & V_3 -> V_199 ) )
F_45 ( & V_3 -> V_199 , ( V_188 + V_236 ) ) ;
return 0 ;
}
static int F_77 ( struct V_297 * V_287 , T_3 V_298 , int V_299 )
{
struct V_300 * V_301 ;
struct V_302 * V_303 ;
int V_304 = V_299 ;
struct V_305 * V_90 ;
struct V_306 * V_307 = V_287 -> V_288 -> V_307 ;
T_6 V_308 = F_23 ( V_298 ) ;
V_301 = F_78 ( & V_309 , V_308 , V_287 -> V_310 , 0 , 0 ) ;
if ( F_79 ( V_301 ) ) {
F_80 ( V_311 L_54 ,
V_67 , V_298 ) ;
return V_304 ;
}
if ( F_81 ( V_287 -> V_90 ) )
V_90 = F_82 ( V_287 -> V_90 ) ;
else
V_90 = V_287 -> V_90 ;
V_303 = F_83 ( & V_301 -> V_312 , & V_308 ) ;
F_84 () ;
if ( V_303 ) {
if ( V_303 -> V_313 & V_314 ) {
F_7 ( V_14 , L_55
L_56 , V_298 ,
V_303 -> V_315 , F_37 ( V_301 -> V_316 ) ) ;
if ( V_299 >= 0 ) {
if ( F_85 ( V_307 -> V_317 [ V_299 ] . V_318 , V_303 -> V_315 ) ) {
goto V_319;
}
F_86 ( V_287 -> V_90 ,
V_307 -> V_317 [ V_299 ] . V_318 ,
V_298 , V_320 ) ;
}
F_86 ( V_287 -> V_90 , V_303 -> V_315 ,
V_298 , V_321 ) ;
V_304 = F_87 ( V_287 -> V_288 , V_298 , NULL ,
V_322 ) ;
} else {
F_88 ( V_303 , NULL ) ;
}
}
V_319:
F_89 () ;
if ( V_303 )
F_90 ( V_303 ) ;
F_91 ( V_301 ) ;
return V_304 ;
}
static struct V_1 * F_92 ( struct V_134 * V_3 ,
struct V_297 * V_287 , struct V_323 * V_9 ,
struct V_263 * V_274 )
{
struct V_1 * V_2 ;
struct V_324 V_325 ;
int V_326 = 0 ;
int V_299 = 0 ;
struct V_327 * V_288 ;
struct V_306 * V_307 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
if ( V_274 ) {
V_2 -> V_11 = V_274 -> V_11 ;
V_2 -> V_13 = V_274 -> V_13 ;
} else {
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_13 = V_9 -> V_13 ;
}
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_48 = V_328 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_64 = 0 ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
F_7 ( V_14 , L_57 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_274 = V_274 ;
if ( V_274 )
V_2 -> V_106 = V_274 -> V_106 ;
V_2 -> V_90 = V_287 -> V_90 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_101 , V_287 -> V_90 -> V_329 , V_99 ) ;
F_7 ( V_14 , L_58 , V_2 -> V_274 ,
V_2 -> V_7 ) ;
F_93 ( & V_2 -> V_194 ) ;
V_2 -> V_283 = NULL ;
F_94 ( & V_2 -> V_272 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_109 . V_110 = V_330 ;
V_2 -> V_109 . V_254 = V_331 ;
V_2 -> V_109 . V_130 = V_332 >>
V_331 ;
V_325 = F_95 () ;
V_2 -> V_109 . V_118 = F_23 ( V_325 . V_333 ) ;
V_2 -> V_109 . V_250 = V_287 -> V_334 - sizeof( struct V_81 ) -
sizeof( struct V_79 ) - V_87 - V_335 ;
V_2 -> V_109 . V_120 = 0 ;
F_64 ( & V_3 -> V_137 ) ;
V_2 -> V_336 = V_9 -> V_336 ;
V_2 -> V_337 = 0 ;
V_2 -> V_296 = 0 ;
V_2 -> V_287 = V_287 ;
V_288 = V_287 -> V_288 ;
V_307 = V_288 -> V_307 ;
V_2 -> V_283 = NULL ;
V_326 = F_87 ( V_288 , V_2 -> V_10 ,
NULL , V_322 ) ;
V_299 = F_77 ( V_287 , V_2 -> V_10 ,
V_326 ) ;
if ( V_299 < 0 ) {
F_35 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_98 , V_307 -> V_317 [ V_299 ] . V_318 , V_99 ) ;
F_7 ( V_14 , L_59 ,
V_2 -> V_98 ) ;
F_65 ( V_3 , V_2 ) ;
F_64 ( & V_338 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_64 ( & V_2 -> V_272 ) ;
return 0 ;
}
static int F_4 ( struct V_134 * V_3 ,
struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_145 * V_148 ;
if ( ! V_2 )
return - V_43 ;
F_40 ( & V_2 -> V_3 -> V_228 , V_29 ) ;
if ( F_69 ( & V_2 -> V_272 ) ) {
F_41 ( & V_2 -> V_3 -> V_228 , V_29 ) ;
return 0 ;
}
F_70 ( & V_2 -> V_229 ) ;
F_71 ( & V_3 -> V_273 ) ;
F_41 ( & V_2 -> V_3 -> V_228 , V_29 ) ;
if ( ! V_2 -> V_280 && V_2 -> V_296 ) {
F_76 ( ! V_2 -> V_274 ) ;
F_71 ( & V_2 -> V_274 -> V_294 ) ;
F_76 ( F_26 ( & V_2 -> V_274 -> V_294 ) < 0 ) ;
}
F_36 ( V_2 -> V_195 ) ;
if ( V_2 -> V_191 )
F_48 ( V_2 , 0 ) ;
if ( V_2 -> V_274 ) {
F_67 ( V_3 , V_2 -> V_274 , 0 ) ;
} else {
if ( V_2 -> V_337 && V_2 -> V_287 ) {
F_72 ( V_2 -> V_287 , V_2 -> V_13 ,
F_73 ( V_2 -> V_287 -> V_288 -> V_289 -> V_290 ) ,
V_291 ) ;
}
F_7 ( V_292 , L_50 ,
V_2 -> V_13 ) ;
}
F_71 ( & V_3 -> V_137 ) ;
F_64 ( & V_339 ) ;
V_148 = V_2 -> V_148 ;
if ( V_148 ) {
V_148 -> V_2 = NULL ;
F_96 ( & V_148 -> V_340 ) ;
V_2 -> V_148 = NULL ;
}
F_35 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , T_1 * V_341 ,
T_3 V_76 , T_3 V_342 )
{
T_3 V_343 ;
T_3 V_344 = 0 ;
union V_245 * V_345 ;
char V_346 = 0 ;
while ( V_344 < V_76 ) {
V_345 = (union V_245 * ) ( V_341 + V_344 ) ;
switch ( V_345 -> V_257 . V_247 ) {
case V_260 :
V_344 = V_76 ;
break;
case V_347 :
V_344 += 1 ;
continue;
case V_248 :
F_7 ( V_14 , L_60
L_61 , V_67 ,
V_345 -> V_246 . V_249 , V_344 , V_76 ) ;
V_346 = 1 ;
if ( V_345 -> V_246 . V_249 != 4 ) {
return 1 ;
} else {
V_343 = F_16 ( V_345 -> V_246 . V_250 ) ;
if ( V_343 > 0 && V_343 <
V_2 -> V_109 . V_250 )
V_2 -> V_109 . V_250 = V_343 ;
}
break;
case V_252 :
V_2 -> V_109 . V_348 =
V_345 -> V_251 . V_253 ;
break;
default:
F_7 ( V_14 , L_62 ,
V_345 -> V_257 . V_247 ) ;
break;
}
V_344 += V_345 -> V_257 . V_249 ;
}
if ( ( ! V_346 ) && ( V_342 ) )
V_2 -> V_109 . V_250 = V_349 ;
return 0 ;
}
static void F_98 ( struct V_15 * V_16 )
{
F_64 ( & V_350 ) ;
F_99 ( V_16 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_63
L_49 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_272 ) ) ;
switch ( V_2 -> V_32 ) {
case V_203 :
case V_351 :
case V_352 :
case V_353 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_205 ;
F_60 ( V_2 , NULL ) ;
break;
case V_49 :
F_5 ( V_2 , V_207 ) ;
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
F_2 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_33 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_204 ;
F_59 ( V_2 , NULL ) ;
break;
case V_354 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_355 ;
F_59 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_189 , 1 , 0 ) ;
break;
case V_355 :
V_2 -> V_109 . V_120 ++ ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_231 :
default:
F_7 ( V_14 , L_64 ,
V_2 , V_2 -> V_32 ) ;
break;
}
}
static void F_101 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_356 = 0 ;
F_64 ( & V_357 ) ;
F_7 ( V_14 , L_65
L_66 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_272 ) ) ;
F_43 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_351 :
case V_49 :
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_274 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_351 ;
if ( F_58 ( V_2 , 0 , NULL ) ) {
F_102 ( V_2 , V_16 , V_356 ) ;
}
break;
case V_46 :
default:
F_102 ( V_2 , V_16 , V_356 ) ;
break;
}
break;
case V_286 :
F_64 ( & V_2 -> V_358 ) ;
F_99 ( V_16 ) ;
break;
case V_352 :
case V_203 :
case V_359 :
F_7 ( V_14 , L_69 , V_67 , __LINE__ ) ;
F_103 ( V_2 , V_16 , V_356 ) ;
break;
case V_231 :
F_102 ( V_2 , V_16 , V_356 ) ;
break;
case V_202 :
F_98 ( V_16 ) ;
break;
case V_354 :
case V_33 :
case V_205 :
V_2 -> V_7 -> V_206 ( V_2 -> V_7 ) ;
case V_355 :
V_2 -> V_32 = V_202 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_98 ( V_16 ) ;
break;
default:
F_98 ( V_16 ) ;
break;
}
}
static void F_104 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_142 = 0 ;
int V_78 = V_16 -> V_35 ;
T_1 * V_360 = V_16 -> V_77 ;
enum V_5 type = V_361 ;
T_3 V_362 ;
V_142 = F_15 ( V_2 , V_360 , & V_362 , V_78 ) ;
if ( V_142 ) {
F_7 ( V_14 , L_70 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_71
L_72 , V_67 ,
__LINE__ , V_2 , V_2 -> V_274 ,
V_2 -> V_32 ) ;
F_102 ( V_2 , V_16 , 1 ) ;
} else {
F_103 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_352 :
if ( V_362 == V_74 )
F_36 ( 1 ) ;
V_2 -> V_32 = V_286 ;
type = V_363 ;
F_94 ( & V_2 -> V_358 ,
V_364 ) ;
break;
case V_49 :
F_43 ( V_2 ) ;
if ( V_362 == V_74 ) {
type = V_365 ;
V_2 -> V_32 = V_353 ;
} else {
type = V_366 ;
V_2 -> V_32 = V_231 ;
}
F_59 ( V_2 , NULL ) ;
break;
default:
F_36 ( 1 ) ;
break;
}
F_99 ( V_16 ) ;
F_5 ( V_2 , type ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_2 -> V_32 ) {
case V_351 :
case V_49 :
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_274 , V_2 -> V_32 ) ;
F_102 ( V_2 , V_16 , 1 ) ;
break;
case V_352 :
case V_203 :
F_103 ( V_2 , V_16 , 1 ) ;
break;
case V_231 :
default:
F_98 ( V_16 ) ;
}
}
static int F_106 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 )
{
int V_276 ;
V_276 = ( ( F_37 ( V_80 -> V_121 ) == V_2 -> V_109 . V_118 ) ) ? 0 : 1 ;
if ( V_276 )
F_102 ( V_2 , V_16 , 1 ) ;
return V_276 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 )
{
int V_276 = 0 ;
T_3 V_117 ;
T_3 V_121 ;
T_3 V_118 = V_2 -> V_109 . V_118 ;
T_3 V_120 = V_2 -> V_109 . V_120 ;
T_3 V_130 ;
V_117 = F_37 ( V_80 -> V_117 ) ;
V_121 = F_37 ( V_80 -> V_121 ) ;
V_130 = V_2 -> V_109 . V_130 ;
if ( V_121 != V_118 )
V_276 = 1 ;
else if ( ! F_108 ( V_117 , V_120 , ( V_120 + V_130 ) ) )
V_276 = 1 ;
if ( V_276 ) {
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_274 , V_2 -> V_32 ) ;
F_105 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_73
L_74 , V_2 , V_117 , V_120 ,
V_130 ) ;
}
return V_276 ;
}
static void F_109 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_142 ;
T_3 V_367 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_367 = F_37 ( V_80 -> V_117 ) ;
switch ( V_2 -> V_32 ) {
case V_351 :
case V_49 :
F_102 ( V_2 , V_16 , 1 ) ;
break;
case V_359 :
if ( F_26 ( & V_2 -> V_274 -> V_294 ) >
V_2 -> V_274 -> V_368 ) {
F_7 ( V_14 , L_75
L_76 ) ;
V_369 ++ ;
F_103 ( V_2 , V_16 , 0 ) ;
break;
}
V_142 = F_110 ( V_2 , V_80 , V_16 , V_76 ,
1 ) ;
if ( V_142 ) {
F_103 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_109 . V_120 = V_367 + 1 ;
F_76 ( V_2 -> V_195 ) ;
V_2 -> V_296 = 1 ;
F_64 ( & V_2 -> V_274 -> V_294 ) ;
V_2 -> V_32 = V_203 ;
F_58 ( V_2 , 1 , V_16 ) ;
break;
case V_202 :
F_43 ( V_2 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
break;
case V_231 :
case V_352 :
case V_33 :
case V_354 :
case V_286 :
case V_205 :
case V_204 :
case V_370 :
default:
F_98 ( V_16 ) ;
break;
}
}
static void F_111 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_142 ;
T_3 V_367 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_367 = F_37 ( V_80 -> V_117 ) ;
switch ( V_2 -> V_32 ) {
case V_351 :
F_43 ( V_2 ) ;
if ( F_106 ( V_2 , V_80 , V_16 ) )
return;
V_2 -> V_109 . V_234 = F_37 ( V_80 -> V_121 ) ;
V_142 = F_110 ( V_2 , V_80 , V_16 , V_76 , 0 ) ;
if ( V_142 ) {
F_7 ( V_14 , L_77 ,
V_2 ) ;
break;
}
F_43 ( V_2 ) ;
V_2 -> V_109 . V_120 = V_367 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_286 :
F_103 ( V_2 , V_16 , 1 ) ;
break;
case V_359 :
V_2 -> V_109 . V_118 = F_37 ( V_80 -> V_121 ) ;
F_43 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
F_47 ( V_2 , V_16 ) ;
break;
case V_202 :
V_2 -> V_109 . V_118 = F_37 ( V_80 -> V_121 ) ;
F_43 ( V_2 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
break;
case V_352 :
case V_33 :
case V_354 :
case V_205 :
case V_231 :
case V_204 :
case V_370 :
case V_49 :
default:
F_98 ( V_16 ) ;
break;
}
}
static int F_112 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_78 = 0 ;
T_3 V_367 ;
int V_142 = 0 ;
int V_76 ;
V_76 = ( V_80 -> V_128 << 2 ) - sizeof( struct V_79 ) ;
if ( F_107 ( V_2 , V_80 , V_16 ) )
return - V_43 ;
F_113 ( V_16 , V_80 -> V_128 << 2 ) ;
V_367 = F_37 ( V_80 -> V_117 ) ;
V_78 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_203 :
F_43 ( V_2 ) ;
V_142 = F_110 ( V_2 , V_80 , V_16 , V_76 , 1 ) ;
if ( V_142 )
break;
V_2 -> V_109 . V_234 = F_37 ( V_80 -> V_121 ) ;
V_2 -> V_32 = V_352 ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_367 + V_78 ;
F_104 ( V_2 , V_16 ) ;
} else {
F_99 ( V_16 ) ;
}
break;
case V_352 :
F_43 ( V_2 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_367 + V_78 ;
F_104 ( V_2 , V_16 ) ;
} else {
F_98 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_109 . V_234 = F_37 ( V_80 -> V_121 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_120 = V_367 + V_78 ;
F_104 ( V_2 , V_16 ) ;
} else {
F_99 ( V_16 ) ;
}
break;
case V_359 :
F_43 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
F_47 ( V_2 , V_16 ) ;
break;
case V_202 :
F_43 ( V_2 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
break;
case V_205 :
case V_204 :
F_43 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
V_2 -> V_7 -> V_206 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_98 ( V_16 ) ;
break;
case V_33 :
F_43 ( V_2 ) ;
F_98 ( V_16 ) ;
V_2 -> V_32 = V_354 ;
break;
case V_351 :
case V_354 :
case V_231 :
case V_286 :
case V_370 :
default:
F_43 ( V_2 ) ;
F_98 ( V_16 ) ;
break;
}
return V_142 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 , int V_76 , int V_371 )
{
T_1 * V_341 = ( T_1 * ) & V_80 [ 1 ] ;
if ( V_76 ) {
if ( F_97 ( V_2 , V_341 , V_76 ,
( T_3 ) V_80 -> V_124 ) ) {
F_7 ( V_14 , L_78 ,
V_67 , V_2 ) ;
if ( V_371 )
F_103 ( V_2 , V_16 , 1 ) ;
else
F_102 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_109 . V_372 = F_16 ( V_80 -> V_129 ) <<
V_2 -> V_109 . V_348 ;
if ( V_2 -> V_109 . V_372 > V_2 -> V_109 . V_373 )
V_2 -> V_109 . V_373 = V_2 -> V_109 . V_372 ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_356 )
{
F_43 ( V_2 ) ;
if ( V_356 ) {
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_47 ( V_2 , V_16 ) ;
} else {
F_99 ( V_16 ) ;
}
V_2 -> V_32 = V_202 ;
F_5 ( V_2 , V_207 ) ;
}
static void F_103 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_356 )
{
F_43 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
if ( V_356 ) {
F_7 ( V_14 , L_81
L_82 , V_2 , V_2 -> V_32 ) ;
F_47 ( V_2 , V_16 ) ;
} else {
F_99 ( V_16 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_181 * V_195 ;
V_195 = V_2 -> V_195 ;
if ( V_195 ) {
V_2 -> V_195 = NULL ;
F_99 ( V_195 -> V_16 ) ;
F_35 ( V_195 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_40 ( & V_2 -> V_194 , V_29 ) ;
F_56 ( V_2 ) ;
F_41 ( & V_2 -> V_194 , V_29 ) ;
}
static void F_114 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_134 * V_3 )
{
enum V_374 V_375 = V_376 ;
struct V_79 * V_80 = F_38 ( V_16 ) ;
T_3 V_377 = 0 ;
int V_142 = 0 ;
F_113 ( V_16 , F_115 ( V_16 ) -> V_105 << 2 ) ;
F_7 ( V_14 , L_83
L_84 , V_2 , V_2 -> V_32 , V_80 -> V_124 ,
V_80 -> V_122 , V_80 -> V_127 , V_80 -> V_125 ) ;
if ( V_80 -> V_127 ) {
V_375 = V_378 ;
} else if ( V_80 -> V_124 ) {
V_375 = V_379 ;
if ( V_80 -> V_122 )
V_375 = V_380 ;
} else if ( V_80 -> V_122 ) {
V_375 = V_381 ;
}
if ( V_80 -> V_125 )
V_377 = 1 ;
switch ( V_375 ) {
case V_379 :
F_109 ( V_2 , V_16 , V_80 ) ;
break;
case V_380 :
F_111 ( V_2 , V_16 , V_80 ) ;
break;
case V_381 :
V_142 = F_112 ( V_2 , V_16 , V_80 ) ;
if ( V_377 && ! V_142 )
F_100 ( V_2 ) ;
break;
case V_378 :
F_101 ( V_2 , V_16 , V_80 ) ;
break;
default:
if ( ( V_377 ) && ( ! F_107 ( V_2 , V_80 , V_16 ) ) )
F_100 ( V_2 ) ;
F_98 ( V_16 ) ;
break;
}
}
static struct V_263 * F_116 ( struct V_134 * V_3 ,
struct V_297 * V_287 , struct V_323 * V_9 )
{
struct V_263 * V_274 ;
unsigned long V_29 ;
F_7 ( V_14 , L_85 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_274 = F_63 ( V_3 , V_9 -> V_11 , V_9 -> V_13 ,
V_382 ) ;
if ( V_274 && V_274 -> V_267 == V_383 ) {
F_71 ( & V_274 -> V_272 ) ;
F_7 ( V_14 , L_86 ) ;
return NULL ;
}
if ( ! V_274 ) {
V_274 = F_6 ( sizeof( * V_274 ) , V_8 ) ;
if ( ! V_274 )
return NULL ;
V_274 -> V_11 = V_9 -> V_11 ;
V_274 -> V_13 = V_9 -> V_13 ;
V_274 -> V_384 = 0 ;
F_94 ( & V_274 -> V_272 , 1 ) ;
}
else {
V_274 -> V_384 = 1 ;
}
V_274 -> V_7 = V_9 -> V_7 ;
F_94 ( & V_274 -> V_294 , 0 ) ;
V_274 -> V_3 = V_3 ;
V_274 -> V_287 = V_287 ;
F_64 ( & V_3 -> V_137 ) ;
V_274 -> V_336 = V_9 -> V_336 ;
V_274 -> V_368 = V_9 -> V_368 ;
V_274 -> V_267 = V_383 ;
if ( ! V_274 -> V_384 ) {
F_40 ( & V_3 -> V_271 , V_29 ) ;
F_54 ( & V_274 -> V_229 , & V_3 -> V_385 . V_229 ) ;
F_41 ( & V_3 -> V_271 , V_29 ) ;
F_64 ( & V_3 -> V_136 ) ;
}
F_7 ( V_14 , L_87
L_88 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_274 , V_274 -> V_368 , V_274 -> V_7 ) ;
return V_274 ;
}
static struct V_1 * F_117 ( struct V_134 * V_3 ,
struct V_297 * V_287 , T_2 V_386 ,
void * V_387 , struct V_323 * V_9 )
{
int V_142 = 0 ;
struct V_1 * V_2 ;
struct V_263 * V_388 ;
struct V_1 * V_389 ;
struct V_323 V_390 ;
T_1 * V_19 ;
V_2 = F_92 ( V_3 , V_287 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_109 . V_391 = 1 ;
V_2 -> V_109 . V_254 = V_331 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_388 = F_63 ( V_3 ,
V_2 -> V_11 , V_2 -> V_12 ,
V_383 ) ;
if ( V_388 == NULL ) {
F_5 ( V_2 , V_207 ) ;
} else {
V_390 = * V_9 ;
V_390 . V_13 = V_9 -> V_12 ;
V_390 . V_12 = V_9 -> V_13 ;
V_390 . V_13 =
V_9 -> V_12 ;
V_390 . V_12 =
V_9 -> V_13 ;
V_390 . V_7 = V_388 -> V_7 ;
V_389 = F_92 ( V_3 , V_287 ,
& V_390 , V_388 ) ;
if ( ! V_389 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_64 ( & V_392 ) ;
V_389 -> V_283 = V_2 ;
V_389 -> V_109 . V_254 =
V_331 ;
V_2 -> V_283 = V_389 ;
memcpy ( V_389 -> V_73 , V_387 ,
V_386 ) ;
V_389 -> V_54 = V_386 ;
V_2 -> V_32 = V_231 ;
V_2 -> V_109 . V_120 =
V_389 -> V_109 . V_118 ;
V_389 -> V_109 . V_120 =
V_2 -> V_109 . V_118 ;
V_2 -> V_109 . V_373 =
V_389 -> V_109 . V_130 ;
V_389 -> V_109 . V_373 =
V_2 -> V_109 . V_130 ;
V_2 -> V_109 . V_372 =
V_389 -> V_109 . V_130 ;
V_389 -> V_109 . V_372 =
V_2 -> V_109 . V_130 ;
V_2 -> V_109 . V_348 =
V_389 -> V_109 . V_254 ;
V_389 -> V_109 . V_348 =
V_2 -> V_109 . V_254 ;
V_389 -> V_32 = V_286 ;
F_5 ( V_389 , V_363 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_386 ;
memcpy ( V_19 , V_387 , V_386 ) ;
V_2 -> V_32 = V_351 ;
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
static int F_118 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_119 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
int V_142 = 0 ;
int V_276 = 0 ;
int V_358 ;
struct V_4 V_6 ;
struct V_200 * V_7 = V_2 -> V_7 ;
struct V_1 * V_282 = V_2 -> V_283 ;
F_7 ( V_14 , L_93 ,
V_67 , V_2 , V_2 -> V_109 . V_391 , V_2 -> V_32 ) ;
if ( V_2 -> V_109 . V_391 )
return V_142 ;
F_43 ( V_2 ) ;
if ( ! V_282 ) {
V_358 = F_120 ( 1 , & V_2 -> V_358 ) ;
if ( V_358 == V_393 ) {
V_2 -> V_32 = V_202 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_285 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_142 = F_13 ( V_2 ) ;
if ( V_142 ) {
V_2 -> V_32 = V_202 ;
V_276 = F_47 ( V_2 , NULL ) ;
if ( V_276 )
F_36 ( 1 ) ;
} else {
V_7 -> V_394 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_285 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_282 ) ;
} else {
V_6 . V_2 = V_282 ;
V_6 . V_9 . V_10 = V_282 -> V_10 ;
V_6 . V_9 . V_11 = V_282 -> V_11 ;
V_6 . V_9 . V_12 = V_282 -> V_12 ;
V_6 . V_9 . V_13 = V_282 -> V_13 ;
V_6 . V_9 . V_7 = V_282 -> V_7 ;
F_121 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_282 -> V_32 = V_204 ;
V_7 = V_282 -> V_7 ;
F_4 ( V_3 , V_282 ) ;
V_7 -> V_206 ( V_7 ) ;
}
}
return V_142 ;
}
static int F_122 ( struct V_134 * V_3 , struct V_1 * V_2 )
{
int V_142 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_203 :
case V_351 :
case V_395 :
case V_352 :
case V_396 :
case V_49 :
case V_286 :
F_43 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_397 :
V_2 -> V_32 = V_205 ;
F_60 ( V_2 , NULL ) ;
break;
case V_33 :
case V_354 :
case V_205 :
case V_355 :
case V_204 :
V_142 = - 1 ;
break;
case V_359 :
F_43 ( V_2 ) ;
F_47 ( V_2 , NULL ) ;
break;
case V_353 :
case V_370 :
case V_398 :
case V_202 :
case V_285 :
V_142 = F_4 ( V_3 , V_2 ) ;
break;
case V_231 :
if ( V_2 -> V_195 )
F_80 ( V_311 L_94
L_95 , V_2 -> V_195 ) ;
V_142 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_142 ;
}
static int F_123 ( struct V_134 * V_3 ,
struct V_297 * V_287 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_263 * V_274 = NULL ;
struct V_81 * V_82 ;
struct V_79 * V_80 ;
struct V_323 V_399 ;
int V_400 = 1 ;
T_6 V_401 , V_402 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_81 ) + sizeof( struct V_79 ) )
return 0 ;
V_82 = (struct V_81 * ) V_16 -> V_77 ;
V_80 = (struct V_79 * ) ( V_16 -> V_77 + sizeof( struct V_81 ) ) ;
V_399 . V_11 = F_37 ( V_82 -> V_114 ) ;
V_399 . V_13 = F_16 ( V_80 -> V_116 ) ;
V_399 . V_10 = F_37 ( V_82 -> V_113 ) ;
V_399 . V_12 = F_16 ( V_80 -> V_115 ) ;
V_401 = F_124 ( V_82 -> V_114 ) ;
V_402 = F_124 ( V_82 -> V_113 ) ;
F_7 ( V_14 , L_96 ,
& V_401 , V_80 -> V_116 , & V_402 , V_80 -> V_115 ) ;
do {
V_2 = F_61 ( V_3 ,
V_399 . V_12 , V_399 . V_10 ,
V_399 . V_13 , V_399 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_80 -> V_124 ) || ( V_80 -> V_122 ) ) {
V_400 = 0 ;
break;
}
V_274 = F_63 ( V_3 , V_399 . V_11 ,
V_399 . V_13 ,
V_383 ) ;
if ( ! V_274 ) {
V_399 . V_7 = NULL ;
V_399 . V_336 = 0 ;
F_7 ( V_14 , L_97 ) ;
V_400 = 0 ;
break;
}
V_399 . V_7 = V_274 -> V_7 ;
V_399 . V_336 = V_274 -> V_336 ;
V_2 = F_92 ( V_3 , V_287 , & V_399 ,
V_274 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_98
L_99 ) ;
V_232 ++ ;
F_71 ( & V_274 -> V_272 ) ;
F_99 ( V_16 ) ;
break;
}
if ( ! V_80 -> V_127 && ! V_80 -> V_125 ) {
V_2 -> V_32 = V_359 ;
} else {
V_232 ++ ;
F_4 ( V_3 , V_2 ) ;
F_99 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_231 ) {
if ( V_2 -> V_148 -> V_403 )
F_125 ( V_16 , V_287 , V_2 -> V_148 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_64 ( & V_350 ) ;
F_99 ( V_16 ) ;
}
break;
}
F_126 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_80 ) ) ;
V_16 -> V_35 = F_16 ( V_82 -> V_107 ) ;
F_114 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_400 ;
}
static struct V_134 * F_127 ( void )
{
struct V_134 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_404 ) ;
if ( ! V_3 )
return NULL ;
F_51 ( & V_3 -> V_262 ) ;
F_128 ( & V_3 -> V_199 ) ;
V_3 -> V_199 . V_405 = F_50 ;
V_3 -> V_406 = V_407 ;
V_3 -> V_32 = V_398 ;
V_3 -> V_408 = V_409 ;
F_94 ( & V_3 -> V_410 , 0 ) ;
V_3 -> V_411 = & V_412 ;
F_93 ( & V_3 -> V_228 ) ;
F_93 ( & V_3 -> V_271 ) ;
F_51 ( & V_3 -> V_385 . V_229 ) ;
F_7 ( V_14 , L_100 , V_3 ) ;
F_7 ( V_14 , L_101 ) ;
V_3 -> V_413 = F_129 ( L_102 , 0 ) ;
if ( ! V_3 -> V_413 )
goto V_414;
V_3 -> V_415 = F_8 ;
F_7 ( V_14 , L_103 ) ;
V_3 -> V_416 = F_129 ( L_104 , 0 ) ;
if ( ! V_3 -> V_416 )
goto V_417;
F_25 ( V_3 ) ;
return V_3 ;
V_417:
F_130 ( V_3 -> V_413 ) ;
V_414:
F_35 ( V_3 ) ;
return NULL ;
}
static int F_131 ( struct V_134 * V_3 )
{
F_7 ( V_14 , L_105 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_132 () ;
if ( F_44 ( & V_3 -> V_199 ) )
F_133 ( & V_3 -> V_199 ) ;
F_130 ( V_3 -> V_413 ) ;
F_130 ( V_3 -> V_416 ) ;
F_7 ( V_14 , L_106 ) ;
F_35 ( V_3 ) ;
return 0 ;
}
static int F_134 ( struct V_134 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_135 ( struct V_134 * V_3 , T_3 type , T_3 V_418 )
{
int V_142 = 0 ;
switch ( type ) {
case V_419 :
V_3 -> V_406 = V_418 ;
break;
case V_420 :
V_3 -> V_408 = V_418 ;
break;
default:
V_142 = - V_43 ;
}
return V_142 ;
}
static int F_136 ( struct V_145 * V_148 , struct V_1 * V_2 )
{
int V_142 = 0 ;
if ( ! V_148 )
return - V_43 ;
V_148 -> V_171 -> V_421 |= F_32 ( V_422 |
V_423 | V_424 |
V_425 ) ;
if ( V_2 -> V_109 . V_348 || V_2 -> V_109 . V_254 )
V_148 -> V_171 -> V_421 |= F_32 ( V_426 ) ;
V_148 -> V_171 -> V_427 |= F_32 ( 64 << V_428 ) ;
V_148 -> V_171 -> V_427 |= F_32 (
V_2 -> V_106 << V_429 ) ;
V_148 -> V_171 -> V_250 |= F_32 ( ( ( T_3 ) V_2 -> V_109 . V_250 ) << 16 ) ;
V_148 -> V_171 -> V_430 |= F_32 (
( T_3 ) V_431 << V_432 ) ;
V_148 -> V_171 -> V_433 |= F_32 (
( V_2 -> V_109 . V_348 << V_434 ) &
V_435 ) ;
V_148 -> V_171 -> V_433 |= F_32 (
( V_2 -> V_109 . V_254 << V_436 ) &
V_437 ) ;
V_148 -> V_171 -> V_438 = F_32 ( 0x80 ) ;
V_148 -> V_171 -> V_439 = 0 ;
V_148 -> V_171 -> V_440 = 0 ;
V_148 -> V_171 -> V_441 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_148 -> V_171 -> V_372 = F_32 ( V_2 -> V_109 . V_372 ) ;
V_148 -> V_171 -> V_120 = F_32 ( V_2 -> V_109 . V_120 ) ;
V_148 -> V_171 -> V_130 = F_32 ( V_2 -> V_109 . V_130 <<
V_2 -> V_109 . V_254 ) ;
V_148 -> V_171 -> V_442 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_148 -> V_171 -> V_443 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_148 -> V_171 -> V_444 = 0 ;
V_148 -> V_171 -> V_445 = F_32 ( 0x6 ) ;
V_148 -> V_171 -> V_446 = F_32 ( 0x3FFFC000 ) ;
V_148 -> V_171 -> V_447 = F_32 ( 2 * V_2 -> V_109 . V_250 ) ;
V_148 -> V_171 -> V_448 = F_32 ( V_2 -> V_109 . V_120 ) ;
V_148 -> V_171 -> V_449 = F_32 ( V_2 -> V_109 . V_118 ) ;
V_148 -> V_171 -> V_373 = F_32 ( V_2 -> V_109 . V_373 ) ;
F_7 ( V_14 , L_107
L_108 ,
V_148 -> V_151 . V_211 , F_137 ( V_148 -> V_171 -> V_120 ) ,
F_137 ( V_148 -> V_171 -> V_441 ) ,
V_2 -> V_109 . V_250 , F_137 ( V_148 -> V_171 -> V_433 ) ,
F_137 ( V_148 -> V_171 -> V_130 ) ,
F_137 ( V_148 -> V_171 -> V_421 ) ) ;
F_7 ( V_14 , L_109 , F_137 ( V_148 -> V_171 -> V_372 ) ) ;
F_7 ( V_14 , L_110 , F_137 ( V_148 -> V_171 -> V_447 ) ) ;
F_7 ( V_14 , L_111 , F_137 ( V_148 -> V_171 -> V_373 ) ) ;
F_7 ( V_14 , L_112 ) ;
V_2 -> V_32 = V_231 ;
return V_142 ;
}
int F_49 ( struct V_145 * V_148 )
{
struct V_450 * V_451 ;
V_451 = F_6 ( sizeof *V_451 , V_8 ) ;
if ( ! V_451 )
return - V_27 ;
F_138 ( & V_148 -> V_340 ) ;
V_451 -> V_148 = V_148 ;
F_139 ( & V_451 -> V_451 , V_452 ) ;
F_140 ( V_225 -> V_416 , & V_451 -> V_451 ) ;
return 0 ;
}
static void V_452 ( struct V_453 * V_451 )
{
struct V_450 * V_454 = F_53 ( V_451 , struct V_450 , V_451 ) ;
struct V_145 * V_148 = V_454 -> V_148 ;
F_35 ( V_454 ) ;
F_7 ( V_14 , L_113 ,
V_148 -> V_215 , V_148 -> V_151 . V_211 ) ;
F_141 ( V_148 ) ;
F_96 ( & V_148 -> V_340 ) ;
}
static int F_141 ( struct V_145 * V_148 )
{
unsigned long V_29 ;
int V_142 = 0 ;
struct V_200 * V_7 ;
struct V_455 V_456 ;
struct V_297 * V_287 ;
T_2 V_457 ;
T_1 V_458 ;
T_1 V_459 ;
int V_460 = 0 ;
int V_461 = 0 ;
int V_462 = 0 ;
int V_463 = 0 ;
T_3 V_464 = V_465 ;
struct V_466 V_467 ;
if ( ! V_148 ) {
F_7 ( V_14 , L_114 ) ;
return - 1 ;
}
F_40 ( & V_148 -> V_210 , V_29 ) ;
V_7 = V_148 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_115 ,
V_148 -> V_151 . V_211 ) ;
F_41 ( & V_148 -> V_210 , V_29 ) ;
return - 1 ;
}
V_287 = F_142 ( V_148 -> V_340 . V_468 ) ;
F_7 ( V_14 , L_116 , V_148 -> V_151 . V_211 ) ;
V_458 = V_148 -> V_213 ;
V_459 = V_148 -> V_217 ;
V_457 = V_148 -> V_215 ;
if ( V_148 -> V_469 ) {
V_461 = 1 ;
V_462 = 1 ;
V_148 -> V_7 = NULL ;
F_133 ( & V_148 -> V_470 ) ;
if ( V_148 -> V_471 == 0 ) {
V_148 -> V_471 = 1 ;
V_463 = 1 ;
}
} else if ( ( V_458 == V_472 ) ||
( ( V_459 == V_473 ) &&
( V_457 == V_474 ) ) ) {
V_461 = 1 ;
if ( V_457 == V_474 )
V_460 = - V_475 ;
}
if ( ( ( V_458 == V_214 ) ||
( V_458 == V_476 ) ||
( V_457 == V_477 ) ||
( V_457 == V_474 ) ) ) {
V_462 = 1 ;
V_148 -> V_7 = NULL ;
if ( V_148 -> V_471 == 0 ) {
V_148 -> V_471 = 1 ;
V_463 = 1 ;
}
}
F_41 ( & V_148 -> V_210 , V_29 ) ;
if ( ( V_463 ) && ( V_148 -> V_478 == 0 ) ) {
if ( V_148 -> V_479 >= V_480 )
V_464 |= V_481 ;
F_143 ( V_287 -> V_288 , V_148 , V_464 , 1 ) ;
if ( V_148 -> V_469 ) {
V_467 . V_468 = V_148 -> V_340 . V_468 ;
V_467 . V_6 = V_148 -> V_482 ;
V_467 . V_483 . V_484 = & V_148 -> V_340 ;
if ( V_148 -> V_340 . V_485 )
V_148 -> V_340 . V_485 ( & V_467 , V_148 -> V_340 . V_486 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_485 ) ) {
if ( V_461 ) {
F_64 ( & V_487 ) ;
V_456 . V_6 = V_488 ;
V_456 . V_489 = V_460 ;
V_456 . V_490 = V_7 -> V_491 ;
V_456 . V_492 = V_7 -> V_493 ;
V_456 . V_387 = NULL ;
V_456 . V_386 = 0 ;
F_7 ( V_14 , L_117
L_118
L_119 ,
V_148 -> V_151 . V_211 , V_148 -> V_151 . V_494 ,
V_148 -> V_151 . V_177 , V_7 ,
F_26 ( & V_148 -> V_212 ) ) ;
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
if ( V_142 )
F_7 ( V_14 , L_120
L_121 , V_142 ) ;
}
if ( V_462 ) {
F_64 ( & V_495 ) ;
F_144 ( V_148 , 1 ) ;
V_7 -> V_496 = V_148 ;
V_456 . V_6 = V_497 ;
V_456 . V_489 = 0 ;
V_456 . V_496 = V_7 -> V_496 ;
V_456 . V_490 = V_7 -> V_491 ;
V_456 . V_492 = V_7 -> V_493 ;
V_456 . V_387 = NULL ;
V_456 . V_386 = 0 ;
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
if ( V_142 )
F_7 ( V_14 , L_122 , V_142 ) ;
V_7 -> V_206 ( V_7 ) ;
}
}
return 0 ;
}
static int F_144 ( struct V_145 * V_148 , int V_498 )
{
int V_142 = 0 ;
struct V_297 * V_287 ;
struct V_327 * V_288 ;
struct V_499 * V_500 ;
V_287 = F_142 ( V_148 -> V_340 . V_468 ) ;
if ( ! V_287 )
return - V_43 ;
V_288 = V_287 -> V_288 ;
V_500 = V_287 -> V_500 ;
F_7 ( V_14 , L_123 ,
F_145 ( V_287 -> V_90 ) ) ;
if ( V_148 -> V_501 ) {
V_148 -> V_501 = 0 ;
} else {
if ( V_148 -> V_502 ) {
if ( V_148 -> V_503 )
V_500 -> V_504 . V_505 ( V_148 -> V_503 ) ;
F_146 ( V_288 -> V_289 ,
V_148 -> V_386 + V_148 -> V_506 ,
V_148 -> V_502 , V_148 -> V_507 ) ;
}
}
if ( V_148 -> V_2 ) {
F_7 ( V_14 , L_124 ) ;
V_225 -> V_411 -> V_508 ( V_225 , V_148 -> V_2 ) ;
}
return V_142 ;
}
int F_147 ( struct V_200 * V_7 , struct V_509 * V_510 )
{
T_4 V_147 ;
struct V_511 * V_340 ;
struct V_145 * V_148 ;
struct V_297 * V_287 ;
struct V_327 * V_288 ;
struct V_1 * V_2 ;
struct V_306 * V_512 ;
struct V_513 V_514 ;
struct V_455 V_456 ;
struct V_149 * V_150 ;
struct V_515 V_516 ;
T_3 V_517 ;
int V_142 ;
int V_358 ;
struct V_499 * V_500 ;
struct V_518 * V_519 = NULL ;
struct V_520 * V_521 ;
T_4 V_522 ;
T_1 V_523 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
struct V_524 * V_525 = (struct V_524 * ) & V_7 -> V_491 ;
struct V_524 * V_526 = (struct V_524 * ) & V_7 -> V_493 ;
V_340 = F_148 ( V_7 -> V_468 , V_510 -> V_527 ) ;
if ( ! V_340 )
return - V_43 ;
V_148 = F_149 ( V_340 ) ;
V_287 = F_142 ( V_148 -> V_340 . V_468 ) ;
V_288 = V_287 -> V_288 ;
V_512 = V_288 -> V_307 ;
V_2 = (struct V_1 * ) V_7 -> V_496 ;
F_7 ( V_14 , L_125
L_126 , V_2 , V_287 , V_287 -> V_90 ,
V_287 -> V_90 -> V_528 ) ;
if ( V_285 == V_2 -> V_32 ) {
if ( V_2 -> V_283 )
F_4 ( V_2 -> V_3 , V_2 -> V_283 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_358 = F_120 ( 1 , & V_2 -> V_358 ) ;
if ( V_358 == V_393 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_475 ;
}
V_148 -> V_2 = ( void * ) V_2 ;
V_2 -> V_148 = V_148 ;
F_7 ( V_14 , L_127 ,
V_148 -> V_151 . V_211 , V_2 , V_188 , V_2 -> V_274 ) ;
F_64 ( & V_529 ) ;
F_7 ( V_14 , L_123 ,
F_145 ( V_287 -> V_90 ) ) ;
V_148 -> V_506 = sizeof( struct V_36 ) ;
V_148 -> V_502 = F_150 ( V_288 -> V_289 ,
V_148 -> V_506 + V_510 -> V_386 ,
& V_148 -> V_507 ) ;
if ( ! V_148 -> V_502 ) {
F_7 ( V_14 , L_128 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_148 -> V_502 ;
if ( V_2 -> V_48 == V_46 )
V_523 = 4 ;
if ( V_2 -> V_48 == V_46 ||
V_2 -> V_64 == V_62 ) {
F_27 ( V_2 , ( T_2 ) V_510 -> V_530 , ( T_2 ) V_510 -> V_531 ) ;
}
memcpy ( V_37 -> V_532 , V_510 -> V_387 ,
V_510 -> V_386 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_148 -> V_502 , V_28 ) ;
V_148 -> V_386 = V_510 -> V_386 ;
V_150 = & V_148 -> V_151 . V_152 [ 0 ] ;
if ( V_526 -> V_533 . V_534 != V_525 -> V_533 . V_534 ) {
V_147 = ( unsigned long ) V_148 ;
V_500 = V_287 -> V_500 ;
V_521 = V_148 -> V_521 ;
V_522 = ( T_4 ) ( unsigned long ) * V_19 ;
V_519 = F_151 ( & V_521 -> V_535 ,
V_148 -> V_507 + V_523 ,
V_20 , V_536 ,
& V_522 ) ;
if ( F_79 ( V_519 ) ) {
F_7 ( V_14 , L_129
L_130 ,
V_2 ) ;
F_146 ( V_288 -> V_289 ,
V_148 -> V_386 + V_148 -> V_506 ,
V_148 -> V_502 , V_148 -> V_507 ) ;
return F_152 ( V_519 ) ;
}
V_519 -> V_537 = & V_521 -> V_535 ;
V_519 -> V_468 = V_521 -> V_535 . V_468 ;
V_148 -> V_503 = V_519 ;
V_147 |= V_154 >> 1 ;
F_31 ( V_150 -> V_155 ,
V_156 ,
V_147 ) ;
V_150 -> V_155 [ V_159 ] =
F_32 ( V_538 |
V_539 ) ;
V_150 -> V_155 [ V_161 ] =
F_32 ( V_20 ) ;
F_31 ( V_150 -> V_155 ,
V_157 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_150 -> V_155 [ V_162 ] =
F_32 ( V_20 ) ;
V_150 -> V_155 [ V_163 ] = V_519 -> V_540 ;
if ( V_148 -> V_169 ) {
V_148 -> V_169 = 0 ;
F_34 ( V_148 -> V_170 ) ;
}
V_148 -> V_171 -> V_172 |=
F_32 ( V_173 |
V_174 ) ;
} else {
V_148 -> V_171 -> V_172 |=
F_32 ( V_174 ) ;
}
V_148 -> V_176 = 1 ;
V_148 -> V_7 = V_7 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_496 = V_148 ;
V_148 -> V_501 = 0 ;
if ( V_2 -> V_32 == V_231 )
F_7 ( V_14 , L_131 ,
V_2 ) ;
F_136 ( V_148 , V_2 ) ;
V_148 -> V_171 -> V_541 [ 0 ] =
F_153 ( V_2 -> V_13 ) ;
V_148 -> V_171 -> V_541 [ 1 ] =
F_153 ( V_2 -> V_12 ) ;
V_148 -> V_171 -> V_542 = F_32 ( V_2 -> V_10 ) ;
V_148 -> V_171 -> V_427 |= F_32 (
( T_3 ) F_73 ( V_288 -> V_289 -> V_290 ) <<
V_543 ) ;
V_148 -> V_171 -> V_544 |=
F_32 ( F_87 ( V_288 ,
F_137 ( V_148 -> V_171 -> V_542 ) , NULL ,
V_322 ) << 16 ) ;
V_148 -> V_171 -> V_545 = F_32 (
V_188 - F_154 ( V_288 , V_546 ) ) ;
V_148 -> V_171 -> V_547 = F_32 ( V_148 -> V_151 . V_211 ) ;
V_148 -> V_171 -> V_172 |= F_32 (
( ( T_3 ) 1 << V_548 ) ) ;
V_148 -> V_171 -> V_172 |=
F_32 ( ( T_3 ) V_2 -> V_56 ) ;
memset ( & V_516 , 0 , sizeof( V_516 ) ) ;
V_516 . V_549 =
F_32 ( ( T_3 ) F_73 ( V_288 -> V_289 -> V_290 ) << 24 ) ;
V_516 . V_550 = F_23 ( V_2 -> V_10 ) ;
V_516 . V_551 [ 0 ] = F_22 ( V_2 -> V_12 ) ;
V_516 . V_551 [ 1 ] = F_22 ( V_2 -> V_13 ) ;
V_517 = F_155 ( & V_516 ) ;
V_148 -> V_552 = F_124 ( V_517 ^ 0xffffffff ) ;
F_7 ( V_14 , L_132 ,
V_148 -> V_552 , V_148 -> V_552 & V_512 -> V_553 ) ;
V_148 -> V_552 &= V_512 -> V_553 ;
V_148 -> V_171 -> V_552 = F_32 ( V_148 -> V_552 ) ;
V_2 -> V_3 -> V_411 -> V_280 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_133
L_134
L_135 , V_148 -> V_151 . V_211 ,
F_37 ( V_526 -> V_533 . V_534 ) , F_16 ( V_526 -> V_554 ) ,
F_37 ( V_525 -> V_533 . V_534 ) , F_16 ( V_525 -> V_554 ) ,
F_137 ( V_148 -> V_171 -> V_120 ) ,
F_137 ( V_148 -> V_171 -> V_441 ) ,
V_20 ) ;
V_7 -> V_394 ( V_7 ) ;
F_138 ( & V_148 -> V_340 ) ;
V_456 . V_6 = V_555 ;
V_456 . V_489 = 0 ;
V_456 . V_496 = ( void * ) V_148 ;
V_456 . V_490 = V_7 -> V_491 ;
V_456 . V_492 = V_7 -> V_493 ;
V_456 . V_387 = NULL ;
V_456 . V_386 = 0 ;
V_456 . V_530 = V_2 -> V_55 ;
V_456 . V_531 = V_2 -> V_56 ;
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
V_514 . V_556 = V_473 ;
F_156 ( & V_148 -> V_340 , & V_514 , V_557 , NULL ) ;
if ( V_2 -> V_283 ) {
V_2 -> V_283 -> V_54 =
V_148 -> V_386 ;
memcpy ( V_2 -> V_283 -> V_73 ,
V_510 -> V_387 , V_510 -> V_386 ) ;
F_5 ( V_2 -> V_283 , V_366 ) ;
}
if ( V_142 )
F_80 ( V_311 L_136
L_137 , V_67 , __LINE__ , V_142 ) ;
return 0 ;
}
int F_157 ( struct V_200 * V_7 , const void * V_558 , T_1 V_559 )
{
struct V_1 * V_2 ;
struct V_1 * V_282 ;
struct V_134 * V_3 ;
T_1 * V_19 ;
F_64 ( & V_560 ) ;
V_2 = (struct V_1 * ) V_7 -> V_496 ;
V_282 = V_2 -> V_283 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_559 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_282 ) {
memcpy ( & V_282 -> V_25 . V_532 , V_558 , V_559 ) ;
V_282 -> V_25 . V_41 = V_559 ;
V_282 -> V_54 = V_559 ;
} else {
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_559 ;
memcpy ( V_19 , V_558 , V_559 ) ;
}
return V_3 -> V_411 -> V_561 ( V_3 , V_2 ) ;
}
int F_158 ( struct V_200 * V_7 , struct V_509 * V_510 )
{
struct V_511 * V_340 ;
struct V_145 * V_148 ;
struct V_297 * V_287 ;
struct V_327 * V_288 ;
struct V_1 * V_2 ;
struct V_323 V_9 ;
int V_337 = 0 ;
struct V_524 * V_525 = (struct V_524 * ) & V_7 -> V_491 ;
struct V_524 * V_526 = (struct V_524 * ) & V_7 -> V_493 ;
if ( V_7 -> V_492 . V_562 != V_563 )
return - V_564 ;
V_340 = F_148 ( V_7 -> V_468 , V_510 -> V_527 ) ;
if ( ! V_340 )
return - V_43 ;
V_148 = F_149 ( V_340 ) ;
if ( ! V_148 )
return - V_43 ;
V_287 = F_142 ( V_148 -> V_340 . V_468 ) ;
if ( ! V_287 )
return - V_43 ;
V_288 = V_287 -> V_288 ;
if ( ! V_288 )
return - V_43 ;
if ( ! V_525 -> V_554 || ! V_526 -> V_554 )
return - V_43 ;
F_7 ( V_14 , L_138
L_139 , V_148 -> V_151 . V_211 ,
F_37 ( V_287 -> V_310 ) , F_37 ( V_526 -> V_533 . V_534 ) ,
F_16 ( V_526 -> V_554 ) , F_37 ( V_525 -> V_533 . V_534 ) ,
F_16 ( V_525 -> V_554 ) ) ;
F_64 ( & V_565 ) ;
V_148 -> V_501 = 1 ;
V_148 -> V_7 = V_7 ;
V_7 -> V_496 = V_148 ;
V_148 -> V_386 = V_510 -> V_386 ;
F_7 ( V_14 , L_140 , ( T_3 ) V_510 -> V_531 ) ;
F_7 ( V_14 , L_141 ,
V_510 -> V_386 ) ;
V_9 . V_11 = F_37 ( V_525 -> V_533 . V_534 ) ;
V_9 . V_13 = F_16 ( V_525 -> V_554 ) ;
V_9 . V_10 = F_37 ( V_526 -> V_533 . V_534 ) ;
V_9 . V_12 = F_16 ( V_526 -> V_554 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_336 = V_566 ;
if ( V_525 -> V_533 . V_534 != V_526 -> V_533 . V_534 ) {
F_72 ( V_287 , V_9 . V_13 ,
F_73 ( V_288 -> V_289 -> V_290 ) ,
V_567 ) ;
V_337 = 1 ;
}
V_7 -> V_394 ( V_7 ) ;
V_2 = V_225 -> V_411 -> V_568 ( V_225 , V_287 ,
V_510 -> V_386 , ( void * ) V_510 -> V_387 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_337 )
F_72 ( V_287 , V_9 . V_13 ,
F_73 ( V_288 -> V_289 -> V_290 ) ,
V_291 ) ;
F_7 ( V_292 , L_142 ,
V_9 . V_13 ) ;
V_7 -> V_206 ( V_7 ) ;
return - V_27 ;
}
F_27 ( V_2 , ( T_2 ) V_510 -> V_530 , ( T_2 ) V_510 -> V_531 ) ;
if ( V_2 -> V_69 == V_70 &&
V_2 -> V_56 == 0 )
V_2 -> V_56 = 1 ;
V_2 -> V_337 = V_337 ;
V_2 -> V_106 = V_7 -> V_106 ;
V_148 -> V_2 = V_2 ;
V_2 -> V_148 = V_148 ;
F_138 ( & V_148 -> V_340 ) ;
return 0 ;
}
int F_159 ( struct V_200 * V_7 , int V_368 )
{
struct V_297 * V_287 ;
struct V_263 * V_2 ;
struct V_323 V_9 ;
int V_276 ;
struct V_524 * V_525 = (struct V_524 * ) & V_7 -> V_491 ;
F_7 ( V_14 , L_143 ,
V_7 , F_16 ( V_525 -> V_554 ) ) ;
if ( V_7 -> V_491 . V_562 != V_563 )
return - V_564 ;
V_287 = F_142 ( V_7 -> V_468 ) ;
if ( ! V_287 )
return - V_43 ;
F_7 ( V_14 , L_144 ,
V_287 , V_287 -> V_90 , V_287 -> V_90 -> V_528 ) ;
F_7 ( V_14 , L_145 ,
V_287 -> V_310 , V_525 -> V_533 . V_534 ) ;
V_9 . V_11 = F_37 ( V_287 -> V_310 ) ;
V_9 . V_13 = F_16 ( V_525 -> V_554 ) ;
V_9 . V_368 = V_368 ;
V_9 . V_7 = V_7 ;
V_9 . V_336 = V_566 ;
V_2 = V_225 -> V_411 -> V_569 ( V_225 , V_287 , & V_9 ) ;
if ( ! V_2 ) {
F_80 ( V_311 L_146 ,
V_67 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_496 = V_2 ;
V_2 -> V_106 = V_7 -> V_106 ;
if ( ! V_2 -> V_384 ) {
V_276 = F_72 ( V_287 , V_2 -> V_13 ,
F_73 ( V_287 -> V_288 -> V_289 -> V_290 ) ,
V_567 ) ;
if ( V_276 ) {
F_80 ( V_311 L_147 ,
V_276 ) ;
V_225 -> V_411 -> V_570 ( V_225 , ( void * ) V_2 ) ;
return V_276 ;
}
F_64 ( & V_571 ) ;
}
V_7 -> V_394 ( V_7 ) ;
V_7 -> V_496 = ( void * ) V_2 ;
return 0 ;
}
int F_160 ( struct V_200 * V_7 )
{
if ( V_7 -> V_496 )
V_225 -> V_411 -> V_570 ( V_225 , V_7 -> V_496 ) ;
else
F_7 ( V_14 , L_148 ) ;
V_7 -> V_206 ( V_7 ) ;
return 0 ;
}
int F_161 ( struct V_15 * V_16 , struct V_305 * V_572 )
{
int V_304 = 0 ;
V_573 ++ ;
if ( ( V_225 ) && ( V_225 -> V_411 ) )
V_304 = V_225 -> V_411 -> V_574 ( V_225 , F_162 ( V_572 ) , V_16 ) ;
else
F_7 ( V_14 , L_149
L_150 ) ;
return V_304 ;
}
int F_163 ( void )
{
F_7 ( V_14 , L_106 ) ;
V_225 = F_127 () ;
if ( V_225 )
return 0 ;
else
return - V_27 ;
}
int F_164 ( void )
{
V_225 -> V_411 -> V_575 ( V_225 ) ;
return 0 ;
}
static void F_165 ( struct V_4 * V_6 )
{
struct V_145 * V_148 ;
struct V_297 * V_287 ;
struct V_327 * V_288 ;
struct V_1 * V_2 ;
struct V_306 * V_307 ;
struct V_513 V_514 ;
struct V_200 * V_7 ;
struct V_455 V_456 ;
struct V_515 V_516 ;
T_3 V_517 ;
int V_142 ;
struct V_524 * V_525 ;
struct V_524 * V_526 ;
struct V_524 * V_576 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_151 , V_2 , V_7 ) ;
V_148 = (struct V_145 * ) V_7 -> V_496 ;
V_287 = F_142 ( V_148 -> V_340 . V_468 ) ;
V_288 = V_287 -> V_288 ;
V_307 = V_288 -> V_307 ;
V_525 = (struct V_524 * ) & V_7 -> V_491 ;
V_526 = (struct V_524 * ) & V_7 -> V_493 ;
V_576 = (struct V_524 * ) & V_456 . V_490 ;
if ( V_148 -> V_478 )
return;
F_64 ( & V_577 ) ;
F_7 ( V_14 , L_152
L_153 ,
V_148 -> V_151 . V_211 , F_37 ( V_526 -> V_533 . V_534 ) ,
F_16 ( V_526 -> V_554 ) , F_16 ( V_525 -> V_554 ) , V_188 ) ;
F_136 ( V_148 , V_2 ) ;
V_148 -> V_171 -> V_541 [ 0 ] =
F_153 ( V_2 -> V_13 ) ;
V_148 -> V_171 -> V_541 [ 1 ] =
F_153 ( V_2 -> V_12 ) ;
V_148 -> V_171 -> V_542 = F_32 ( V_2 -> V_10 ) ;
V_148 -> V_171 -> V_427 |= F_32 (
( T_3 ) F_73 ( V_288 -> V_289 -> V_290 ) <<
V_543 ) ;
V_148 -> V_171 -> V_544 |= F_32 (
F_87 ( V_288 ,
F_137 ( V_148 -> V_171 -> V_542 ) ,
NULL , V_322 ) << 16 ) ;
V_148 -> V_171 -> V_545 = F_32 (
V_188 - F_154 ( V_288 , V_546 ) ) ;
V_148 -> V_171 -> V_547 = F_32 ( V_148 -> V_151 . V_211 ) ;
V_148 -> V_171 -> V_172 |=
F_32 ( ( T_3 ) 1 <<
V_548 ) ;
V_148 -> V_171 -> V_172 |=
F_32 ( ( T_3 ) V_2 -> V_56 ) ;
F_30 ( V_2 , & V_148 ) ;
F_166 ( V_288 -> V_578 + V_579 ,
( 1 << 24 ) | 0x00800000 | V_148 -> V_151 . V_211 ) ;
memset ( & V_516 , 0 , sizeof( V_516 ) ) ;
V_516 . V_549 =
F_32 ( ( T_3 ) F_73 ( V_288 -> V_289 -> V_290 ) << 24 ) ;
V_516 . V_550 = F_23 ( V_2 -> V_10 ) ;
V_516 . V_551 [ 0 ] = F_22 ( V_2 -> V_12 ) ;
V_516 . V_551 [ 1 ] = F_22 ( V_2 -> V_13 ) ;
V_517 = F_155 ( & V_516 ) ;
V_148 -> V_552 = F_124 ( V_517 ^ 0xffffffff ) ;
F_7 ( V_14 , L_154 ,
V_148 -> V_552 , V_148 -> V_552 & V_307 -> V_553 ) ;
V_148 -> V_552 &= V_307 -> V_553 ;
V_148 -> V_171 -> V_552 = F_32 ( V_148 -> V_552 ) ;
V_148 -> V_502 = & V_2 -> V_25 ;
V_148 -> V_386 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_411 -> V_280 ( V_2 -> V_3 , V_2 ) ;
V_456 . V_6 = V_580 ;
V_456 . V_489 = 0 ;
V_456 . V_496 = V_7 -> V_496 ;
V_576 -> V_581 = V_563 ;
V_576 -> V_554 = V_525 -> V_554 ;
V_456 . V_492 = V_7 -> V_493 ;
V_456 . V_387 = ( void * ) V_6 -> V_2 -> V_73 ;
V_456 . V_386 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_456 . V_530 = V_2 -> V_55 ;
V_456 . V_531 = V_2 -> V_56 ;
V_576 -> V_533 . V_534 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
F_7 ( V_14 , L_122 , V_142 ) ;
if ( V_142 )
F_80 ( V_311 L_136
L_137 , V_67 , __LINE__ , V_142 ) ;
V_514 . V_556 = V_473 ;
F_156 ( & V_148 -> V_340 , & V_514 , V_557 , NULL ) ;
F_7 ( V_14 , L_155
L_156 , V_148 -> V_151 . V_211 , V_188 ) ;
return;
}
static void F_68 ( struct V_4 * V_6 )
{
struct V_145 * V_148 ;
struct V_200 * V_7 ;
struct V_455 V_456 ;
int V_142 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_157 , V_6 -> V_2 , V_7 ) ;
V_148 = V_7 -> V_496 ;
if ( ! V_148 )
return;
V_148 -> V_7 = NULL ;
V_7 -> V_496 = NULL ;
V_456 . V_6 = V_580 ;
V_456 . V_489 = - V_475 ;
V_456 . V_496 = V_7 -> V_496 ;
V_456 . V_490 = V_7 -> V_491 ;
V_456 . V_492 = V_7 -> V_493 ;
V_456 . V_387 = NULL ;
V_456 . V_386 = 0 ;
#ifdef F_167
{
struct V_524 * V_576 = (struct V_524 * )
& V_456 . V_490 ;
struct V_524 * V_582 = (struct V_524 * )
& V_456 . V_492 ;
F_7 ( V_14 , L_158 ,
V_576 -> V_533 . V_534 , V_582 -> V_533 . V_534 ) ;
}
#endif
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
F_7 ( V_14 , L_122 , V_142 ) ;
if ( V_142 )
F_80 ( V_311 L_136
L_137 , V_67 , __LINE__ , V_142 ) ;
V_7 -> V_206 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_168 ( struct V_4 * V_6 )
{
struct V_145 * V_148 ;
struct V_200 * V_7 ;
struct V_455 V_456 ;
int V_142 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_159 , V_6 -> V_2 , V_7 ) ;
V_148 = V_7 -> V_496 ;
if ( ! V_148 )
return;
V_148 -> V_7 = NULL ;
V_456 . V_6 = V_488 ;
V_456 . V_489 = - V_475 ;
V_456 . V_496 = V_7 -> V_496 ;
V_456 . V_490 = V_7 -> V_491 ;
V_456 . V_492 = V_7 -> V_493 ;
V_456 . V_387 = NULL ;
V_456 . V_386 = 0 ;
V_7 -> V_394 ( V_7 ) ;
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
F_64 ( & V_495 ) ;
V_456 . V_6 = V_497 ;
V_456 . V_489 = 0 ;
V_456 . V_496 = V_7 -> V_496 ;
V_456 . V_490 = V_7 -> V_491 ;
V_456 . V_492 = V_7 -> V_493 ;
V_456 . V_387 = NULL ;
V_456 . V_386 = 0 ;
F_7 ( V_14 , L_160 , V_6 -> V_2 ) ;
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
F_7 ( V_14 , L_122 , V_142 ) ;
V_7 -> V_206 ( V_7 ) ;
return;
}
static void F_169 ( struct V_4 * V_6 )
{
struct V_200 * V_7 ;
struct V_455 V_456 ;
int V_142 ;
struct V_1 * V_2 ;
struct V_524 * V_576 = (struct V_524 * )
& V_456 . V_490 ;
struct V_524 * V_582 = (struct V_524 * )
& V_456 . V_492 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_64 ( & V_583 ) ;
F_7 ( V_14 , L_161 ,
V_2 , V_7 , V_188 ) ;
V_456 . V_6 = V_584 ;
V_456 . V_489 = 0 ;
V_456 . V_496 = ( void * ) V_2 ;
V_576 -> V_581 = V_563 ;
V_576 -> V_554 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_576 -> V_533 . V_534 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_582 -> V_581 = V_563 ;
V_582 -> V_554 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_582 -> V_533 . V_534 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_456 . V_387 = V_2 -> V_73 ;
V_456 . V_386 = ( T_1 ) V_2 -> V_54 ;
if ( V_2 -> V_48 == V_46 ) {
V_456 . V_530 = V_65 ;
V_456 . V_531 = V_68 ;
} else {
V_456 . V_530 = V_2 -> V_55 ;
V_456 . V_531 = V_2 -> V_56 ;
}
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
if ( V_142 )
F_80 ( V_311 L_162 ,
V_67 , __LINE__ , V_142 ) ;
return;
}
static void F_121 ( struct V_4 * V_6 )
{
struct V_200 * V_7 ;
struct V_455 V_456 ;
struct V_1 * V_2 ;
int V_142 ;
struct V_524 * V_576 = (struct V_524 * )
& V_456 . V_490 ;
struct V_524 * V_582 = (struct V_524 * )
& V_456 . V_492 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_64 ( & V_583 ) ;
F_7 ( V_14 , L_161 ,
V_2 , V_7 , V_188 ) ;
V_456 . V_6 = V_580 ;
V_456 . V_489 = - V_585 ;
V_456 . V_496 = V_7 -> V_496 ;
V_576 -> V_581 = V_563 ;
V_576 -> V_554 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_576 -> V_533 . V_534 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_582 -> V_581 = V_563 ;
V_582 -> V_554 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_582 -> V_533 . V_534 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_456 . V_387 = V_2 -> V_73 ;
V_456 . V_386 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_163
L_164 ,
V_576 -> V_533 . V_534 ,
V_582 -> V_533 . V_534 ) ;
V_142 = V_7 -> V_485 ( V_7 , & V_456 ) ;
if ( V_142 )
F_80 ( V_311 L_162 ,
V_67 , __LINE__ , V_142 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_64 ( & V_6 -> V_2 -> V_3 -> V_410 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_394 ( V_6 -> V_9 . V_7 ) ;
F_139 ( & V_6 -> V_586 , V_587 ) ;
F_7 ( V_14 , L_165 ,
V_6 -> V_2 , V_6 ) ;
F_140 ( V_6 -> V_2 -> V_3 -> V_413 , & V_6 -> V_586 ) ;
F_7 ( V_14 , L_166 ) ;
return 0 ;
}
static void V_587 ( struct V_453 * V_451 )
{
struct V_4 * V_6 = F_53 ( V_451 , struct V_4 ,
V_586 ) ;
struct V_134 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_167 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_410 ) ) ;
switch ( V_6 -> type ) {
case V_363 :
F_169 ( V_6 ) ;
F_7 ( V_14 , L_168 ,
V_6 -> V_2 ) ;
break;
case V_588 :
F_7 ( V_14 , L_169 ,
V_6 -> V_2 ) ;
F_168 ( V_6 ) ;
break;
case V_366 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_231 ) )
break;
F_165 ( V_6 ) ;
F_7 ( V_14 , L_170 ) ;
break;
case V_365 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_231 ) )
break;
F_121 ( V_6 ) ;
F_7 ( V_14 , L_171 ) ;
break;
case V_207 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_231 ) )
break;
F_68 ( V_6 ) ;
F_7 ( V_14 , L_172 ) ;
break;
case V_589 :
F_7 ( V_14 , L_173 ) ;
break;
default:
F_7 ( V_14 , L_174 ) ;
break;
}
F_71 ( & V_3 -> V_410 ) ;
V_6 -> V_9 . V_7 -> V_206 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_35 ( V_6 ) ;
return;
}
