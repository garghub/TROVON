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
if ( V_2 -> V_32 != V_49 ) {
if ( V_2 -> V_56 > V_55 )
V_2 -> V_56 = V_55 ;
} else {
if ( V_2 -> V_56 > V_55 )
V_2 -> V_56 = V_55 ;
if ( V_2 -> V_55 < V_56 ) {
return - V_43 ;
}
}
if ( V_58 & V_64 ) {
V_2 -> V_65 = V_66 ;
} else if ( V_58 & V_67 ) {
V_2 -> V_65 = V_68 ;
} else {
return - V_43 ;
}
break;
}
case V_46 :
default:
break;
}
memcpy ( V_2 -> V_69 , V_34 + V_40 , V_2 -> V_54 ) ;
if ( V_25 -> V_29 & V_30 )
* type = V_70 ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_1 * V_2 , void * V_71 , T_3 V_72 ,
void * V_73 , T_3 V_74 , T_1 V_29 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
T_1 * V_81 ;
T_2 V_82 = sizeof( * V_78 ) ;
V_82 += sizeof( * V_76 ) ;
V_82 += V_72 + V_74 ;
F_17 ( V_16 , 0 ) ;
memset ( V_16 -> V_73 , 0x00 , V_83 + sizeof( * V_78 ) + sizeof( * V_76 ) ) ;
V_81 = F_18 ( V_16 , V_82 + V_83 ) ;
V_80 = (struct V_79 * ) V_81 ;
V_81 += V_83 ;
V_78 = (struct V_77 * ) V_81 ;
V_81 += sizeof( * V_78 ) ;
V_76 = (struct V_75 * ) V_81 ;
F_19 ( V_16 ) ;
F_20 ( V_16 , V_83 ) ;
F_21 ( V_16 , V_83 + sizeof( * V_78 ) ) ;
V_81 += sizeof( * V_76 ) ;
V_16 -> V_84 = V_85 ;
if ( ! ( V_2 -> V_86 -> V_87 & V_88 ) )
V_16 -> V_84 = V_89 ;
V_16 -> V_90 = F_22 ( 0x800 ) ;
V_16 -> V_91 = 0 ;
V_16 -> V_92 = V_83 ;
memcpy ( V_80 -> V_93 , V_2 -> V_94 , V_95 ) ;
memcpy ( V_80 -> V_96 , V_2 -> V_97 , V_95 ) ;
V_80 -> V_98 = F_22 ( 0x0800 ) ;
V_78 -> V_99 = V_100 ;
V_78 -> V_101 = 5 ;
V_78 -> V_102 = 0 ;
V_78 -> V_103 = F_22 ( V_82 ) ;
V_78 -> V_104 = F_22 ( ++ V_2 -> V_105 . V_106 ) ;
V_78 -> V_107 = F_22 ( 0x4000 ) ;
V_78 -> V_108 = 0x40 ;
V_78 -> V_90 = 0x06 ;
V_78 -> V_109 = F_23 ( V_2 -> V_11 ) ;
V_78 -> V_110 = F_23 ( V_2 -> V_10 ) ;
V_76 -> V_111 = F_22 ( V_2 -> V_13 ) ;
V_76 -> V_112 = F_22 ( V_2 -> V_12 ) ;
V_76 -> V_113 = F_23 ( V_2 -> V_105 . V_114 ) ;
if ( V_29 & V_22 ) {
V_2 -> V_105 . V_115 = V_2 -> V_105 . V_116 ;
V_76 -> V_117 = F_23 ( V_2 -> V_105 . V_115 ) ;
V_76 -> V_118 = 1 ;
} else {
V_76 -> V_117 = 0 ;
}
if ( V_29 & V_119 ) {
V_2 -> V_105 . V_114 ++ ;
V_76 -> V_120 = 1 ;
} else {
V_2 -> V_105 . V_114 += V_74 ;
}
if ( V_29 & V_31 ) {
V_2 -> V_105 . V_114 ++ ;
V_76 -> V_121 = 1 ;
}
if ( V_29 & V_122 )
V_76 -> V_123 = 1 ;
V_76 -> V_124 = ( T_2 ) ( ( sizeof( * V_76 ) + V_72 + 3 ) >> 2 ) ;
V_76 -> V_125 = F_22 ( V_2 -> V_105 . V_126 ) ;
V_76 -> V_127 = 0 ;
if ( V_72 )
memcpy ( V_81 , V_71 , V_72 ) ;
V_81 += V_72 ;
if ( V_74 )
memcpy ( V_81 , V_73 , V_74 ) ;
F_24 ( V_16 ) -> V_128 = 0 ;
V_129 ++ ;
}
static void F_25 ( struct V_130 * V_131 )
{
F_7 ( V_14 , L_16 ) ;
F_7 ( V_14 , L_17 , V_131 ) ;
if ( ! V_131 )
return;
F_7 ( V_14 , L_16 ) ;
F_7 ( V_14 , L_18 , V_131 -> V_32 ) ;
F_7 ( V_14 , L_19 , F_26 ( & V_131 -> V_132 ) ) ;
F_7 ( V_14 , L_20 , F_26 ( & V_131 -> V_133 ) ) ;
F_7 ( V_14 , L_21 , V_131 ) ;
F_7 ( V_14 , L_22 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * * V_19 ,
T_2 * V_20 , T_1 * V_134 , T_1 V_135 )
{
int V_136 = 0 ;
* V_19 = ( V_134 ) ? V_134 : & V_2 -> V_69 [ 0 ] ;
switch ( V_2 -> V_48 ) {
case V_46 :
* V_19 = ( T_1 * ) * V_19 + sizeof( struct V_38 ) ;
* V_20 = sizeof( struct V_24 ) + V_2 -> V_54 ;
F_27 ( V_2 , * V_19 , V_135 ) ;
break;
case V_47 :
* V_20 = sizeof( struct V_36 ) + V_2 -> V_54 ;
F_28 ( V_2 , * V_19 , V_135 ) ;
break;
default:
V_136 = - V_43 ;
}
return V_136 ;
}
static void F_28 ( struct V_1 * V_2 ,
void * V_17 , T_1 V_135 )
{
struct V_36 * V_25 = (struct V_36 * ) V_17 ;
struct V_38 * V_39 = & V_25 -> V_39 ;
T_2 V_60 ;
T_2 V_61 ;
F_27 ( V_2 , V_17 , V_135 ) ;
V_25 -> V_29 |= V_137 ;
V_25 -> V_41 += F_22 ( V_59 ) ;
V_60 = ( V_2 -> V_55 > V_62 ) ?
V_62 : V_2 -> V_55 ;
V_61 = ( V_2 -> V_56 > V_62 ) ?
V_62 : V_2 -> V_56 ;
V_60 |= V_63 ;
V_60 |= V_138 ;
switch ( V_135 ) {
case V_21 :
V_61 |= V_67 ;
V_61 |= V_64 ;
break;
case V_28 :
switch ( V_2 -> V_65 ) {
case V_68 :
V_61 |= V_67 ;
break;
case V_66 :
V_61 |= V_64 ;
break;
}
}
V_39 -> V_60 = F_22 ( V_60 ) ;
V_39 -> V_61 = F_22 ( V_61 ) ;
}
static void F_27 ( struct V_1 * V_2 , void * V_17 , T_1 V_135 )
{
struct V_24 * V_25 = (struct V_24 * ) V_17 ;
switch ( V_135 ) {
case V_21 :
memcpy ( V_25 -> V_50 , V_51 , V_52 ) ;
break;
case V_28 :
memcpy ( V_25 -> V_50 , V_53 , V_52 ) ;
break;
}
V_25 -> V_29 = V_139 ;
V_25 -> V_45 = V_2 -> V_48 ;
V_25 -> V_41 = F_22 ( V_2 -> V_54 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_140 * * V_141 )
{
T_4 V_142 ;
struct V_140 * V_143 = * V_141 ;
struct V_144 * V_145 = & V_143 -> V_146 . V_147 [ 0 ] ;
V_142 = ( unsigned long ) V_143 ;
V_142 |= V_148 >> 1 ;
F_30 ( V_145 -> V_149 , V_150 , V_142 ) ;
V_145 -> V_149 [ V_151 ] = 0 ;
V_145 -> V_149 [ V_152 ] = 0 ;
switch ( V_2 -> V_65 ) {
case V_68 :
F_7 ( V_14 , L_23 ) ;
V_145 -> V_149 [ V_153 ] =
F_31 ( V_154 ) ;
V_145 -> V_149 [ V_155 ] = 0 ;
V_145 -> V_149 [ V_156 ] = 0 ;
V_145 -> V_149 [ V_157 ] = 0 ;
break;
case V_66 :
default:
if ( V_2 -> V_65 != V_66 ) {
F_32 ( V_158 L_24 ,
V_159 , __LINE__ , V_2 -> V_65 ) ;
F_33 ( 1 ) ;
}
F_7 ( V_14 , L_25 ) ;
V_145 -> V_149 [ V_153 ] =
F_31 ( V_160 ) ;
V_145 -> V_149 [ V_161 ] = 1 ;
V_145 -> V_149 [ V_162 ] = 0 ;
V_145 -> V_149 [ V_163 ] = 0 ;
V_145 -> V_149 [ V_164 ] = 1 ;
V_145 -> V_149 [ V_157 ] = 1 ;
break;
}
if ( V_143 -> V_165 ) {
V_143 -> V_165 = 0 ;
F_34 ( V_143 -> V_166 ) ;
}
V_143 -> V_167 -> V_168 &= F_31 ( ~ ( V_169 |
V_170 |
V_171 ) ) ;
V_143 -> V_172 = 1 ;
V_143 -> V_146 . V_173 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_174 type , int V_175 ,
int V_176 )
{
unsigned long V_29 ;
struct V_130 * V_3 = V_2 -> V_3 ;
struct V_177 * V_178 ;
int V_136 = 0 ;
T_3 V_179 ;
V_178 = F_6 ( sizeof( * V_178 ) , V_8 ) ;
if ( ! V_178 )
return - V_27 ;
V_178 -> V_180 = V_181 ;
V_178 -> V_182 = V_183 ;
V_178 -> V_16 = V_16 ;
V_178 -> V_184 = V_185 ;
V_178 -> type = type ;
V_178 -> V_86 = V_2 -> V_86 ;
V_178 -> V_175 = V_175 ;
V_178 -> V_176 = V_176 ;
if ( type == V_186 ) {
V_178 -> V_184 += ( V_187 / 10 ) ;
if ( V_2 -> V_188 ) {
F_35 ( V_178 ) ;
F_33 ( 1 ) ;
return - V_43 ;
}
V_2 -> V_188 = V_178 ;
}
if ( type == V_23 ) {
V_178 -> V_189 = F_36 ( F_37 ( V_16 ) -> V_113 ) ;
F_38 ( & V_178 -> V_16 -> V_190 ) ;
F_39 ( & V_2 -> V_191 , V_29 ) ;
V_2 -> V_192 = V_178 ;
F_2 ( V_2 ) ;
F_40 ( & V_2 -> V_191 , V_29 ) ;
V_178 -> V_184 = V_185 + V_193 ;
V_136 = F_41 ( V_178 -> V_16 , V_2 -> V_86 ) ;
if ( V_136 != V_194 ) {
F_7 ( V_14 , L_26
L_27 , V_178 , V_185 ) ;
V_178 -> V_184 = V_185 ;
V_136 = V_194 ;
} else {
V_195 ++ ;
if ( ! V_175 ) {
F_42 ( V_2 ) ;
if ( V_176 )
F_4 ( V_3 , V_2 ) ;
return V_136 ;
}
}
}
V_179 = F_43 ( & V_3 -> V_196 ) ;
if ( ! V_179 ) {
V_3 -> V_196 . V_197 = V_178 -> V_184 ;
F_44 ( & V_3 -> V_196 ) ;
}
return V_136 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_198 * V_7 = V_2 -> V_7 ;
enum V_199 V_32 = V_2 -> V_32 ;
V_2 -> V_32 = V_200 ;
switch ( V_32 ) {
case V_201 :
case V_202 :
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_203 :
case V_33 :
if ( V_2 -> V_7 )
V_7 -> V_204 ( V_7 ) ;
F_46 ( V_2 , NULL ) ;
break;
default:
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
F_5 ( V_2 , V_205 ) ;
}
}
static void F_47 ( struct V_1 * V_2 , T_3 V_206 )
{
struct V_177 * V_188 = V_2 -> V_188 ;
struct V_198 * V_7 = V_2 -> V_7 ;
struct V_140 * V_143 ;
unsigned long V_207 ;
if ( ! V_188 )
return;
V_143 = (struct V_140 * ) V_188 -> V_16 ;
if ( V_143 ) {
F_39 ( & V_143 -> V_208 , V_207 ) ;
if ( V_143 -> V_7 ) {
F_7 ( V_14 , L_28
L_29
L_30
L_31 , V_143 -> V_146 . V_209 , V_7 ,
F_26 ( & V_143 -> V_210 ) ) ;
V_143 -> V_211 = V_212 ;
V_143 -> V_213 = V_214 ;
V_143 -> V_215 = V_216 ;
F_40 ( & V_143 -> V_208 , V_207 ) ;
F_48 ( V_143 ) ;
} else {
F_40 ( & V_143 -> V_208 , V_207 ) ;
F_7 ( V_14 , L_28
L_29
L_32
L_31 , V_143 -> V_146 . V_209 , V_7 ,
F_26 ( & V_143 -> V_210 ) ) ;
}
} else if ( V_206 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_2 -> V_7 )
V_7 -> V_204 ( V_7 ) ;
F_35 ( V_188 ) ;
V_2 -> V_188 = NULL ;
}
static void F_49 ( unsigned long V_217 )
{
unsigned long V_29 ;
unsigned long V_218 = V_185 + V_219 ;
struct V_1 * V_2 ;
struct V_177 * V_192 , * V_188 ;
struct V_220 * V_221 ;
struct V_220 * V_222 ;
struct V_130 * V_3 = V_223 ;
T_3 V_224 = 0 ;
unsigned long V_184 ;
int V_136 = V_194 ;
struct V_220 V_225 ;
F_50 ( & V_225 ) ;
F_39 ( & V_3 -> V_226 , V_29 ) ;
F_51 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_2 = F_52 ( V_222 , struct V_1 , V_227 ) ;
if ( ( V_2 -> V_188 ) || ( V_2 -> V_192 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_228 , & V_225 ) ;
}
}
F_40 ( & V_3 -> V_226 , V_29 ) ;
F_51 (list_node, list_core_temp, &timer_list) {
V_2 = F_52 ( V_222 , struct V_1 ,
V_228 ) ;
V_188 = V_2 -> V_188 ;
if ( V_188 ) {
if ( F_54 ( V_188 -> V_184 , V_185 ) ) {
if ( V_218 > V_188 -> V_184 ||
! V_224 ) {
V_218 = V_188 -> V_184 ;
V_224 = 1 ;
}
} else {
F_47 ( V_2 , 1 ) ;
}
}
F_39 ( & V_2 -> V_191 , V_29 ) ;
do {
V_192 = V_2 -> V_192 ;
if ( ! V_192 )
break;
if ( F_54 ( V_192 -> V_184 , V_185 ) ) {
if ( V_2 -> V_32 != V_229 ) {
if ( ( V_218 >
V_192 -> V_184 ) ||
! V_224 ) {
V_218 =
V_192 -> V_184 ;
V_224 = 1 ;
}
} else {
F_55 ( V_2 ) ;
}
break;
}
if ( ( V_2 -> V_32 == V_229 ) ||
( V_2 -> V_32 == V_200 ) ) {
F_55 ( V_2 ) ;
break;
}
if ( ! V_192 -> V_182 ||
! V_192 -> V_180 ) {
V_230 ++ ;
F_55 ( V_2 ) ;
F_40 (
& V_2 -> V_191 , V_29 ) ;
F_45 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
F_39 ( & V_2 -> V_191 ,
V_29 ) ;
break;
}
F_38 ( & V_192 -> V_16 -> V_190 ) ;
V_231 ++ ;
F_7 ( V_14 , L_33
L_34
L_35
L_36
L_37 , V_192 , V_2 , V_185 ,
V_192 -> V_184 ,
V_192 -> V_182 ,
V_192 -> V_189 ,
V_2 -> V_105 . V_232 ) ;
F_40 ( & V_2 -> V_191 ,
V_29 ) ;
V_136 = F_41 ( V_192 -> V_16 , V_2 -> V_86 ) ;
F_39 ( & V_2 -> V_191 , V_29 ) ;
if ( V_136 != V_194 ) {
F_7 ( V_14 , L_38
L_39 , V_2 ) ;
V_233 ++ ;
V_192 -> V_180 -- ;
V_218 = V_185 + V_234 ;
V_224 = 1 ;
break;
} else {
V_195 ++ ;
}
F_7 ( V_14 , L_40
L_41 ,
V_192 -> V_182 ,
V_192 -> V_180 ) ;
if ( V_192 -> V_175 ) {
V_192 -> V_182 -- ;
V_184 = ( V_193 <<
( V_183 - V_192 -> V_182 ) ) ;
V_192 -> V_184 = V_185 +
F_56 ( V_184 , V_235 ) ;
if ( V_218 > V_192 -> V_184 ||
! V_224 ) {
V_218 = V_192 -> V_184 ;
V_224 = 1 ;
}
} else {
int V_176 ;
V_176 =
V_192 -> V_176 ;
F_7 ( V_14 , L_42 ,
V_2 , V_2 -> V_32 ) ;
F_55 ( V_2 ) ;
if ( V_176 )
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
} while ( 0 );
F_40 ( & V_2 -> V_191 , V_29 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_224 ) {
if ( ! F_43 ( & V_3 -> V_196 ) ) {
V_3 -> V_196 . V_197 = V_218 ;
F_44 ( & V_3 -> V_196 ) ;
}
}
}
static int F_57 ( struct V_1 * V_2 , T_3 V_236 ,
struct V_15 * V_16 )
{
int V_136 ;
int V_29 = V_119 ;
char V_237 [ sizeof( struct V_238 ) +
sizeof( struct V_239 ) + sizeof( struct V_240 ) +
V_241 ] ;
int V_242 = 0 ;
union V_243 * V_71 ;
if ( ! V_2 )
return - V_43 ;
V_71 = (union V_243 * ) & V_237 [ V_242 ] ;
V_71 -> V_244 . V_245 = V_246 ;
V_71 -> V_244 . V_247 = sizeof( struct V_238 ) ;
V_71 -> V_244 . V_248 = F_22 ( V_2 -> V_105 . V_248 ) ;
V_242 += sizeof( struct V_238 ) ;
V_71 = (union V_243 * ) & V_237 [ V_242 ] ;
V_71 -> V_249 . V_245 = V_250 ;
V_71 -> V_249 . V_247 = sizeof( struct V_239 ) ;
V_71 -> V_249 . V_251 = V_2 -> V_105 . V_252 ;
V_242 += sizeof( struct V_239 ) ;
if ( V_236 && ! ( V_253 & V_254 ) ) {
V_71 = (union V_243 * ) & V_237 [ V_242 ] ;
V_71 -> V_255 . V_245 = V_256 ;
V_71 -> V_255 . V_247 = sizeof( struct V_240 ) ;
V_242 += sizeof( struct V_240 ) ;
V_71 = (union V_243 * ) & V_237 [ V_242 ] ;
V_71 -> V_257 = 1 ;
V_242 += 1 ;
V_71 = (union V_243 * ) & V_237 [ V_242 ] ;
V_71 -> V_257 = 1 ;
V_242 += 1 ;
}
V_71 = (union V_243 * ) & V_237 [ V_242 ] ;
V_71 -> V_257 = V_258 ;
V_242 += 1 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
if ( V_236 )
V_29 |= V_22 ;
F_11 ( V_16 , V_2 , V_237 , V_242 , NULL , 0 , V_29 ) ;
V_136 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_136 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_136 ;
int V_29 = V_122 | V_22 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - V_27 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_29 ) ;
V_136 = F_12 ( V_2 , V_16 , V_23 , 0 , 1 ) ;
return V_136 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_136 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 ) ;
V_136 = F_12 ( V_2 , V_16 , V_23 , 0 , 0 ) ;
return V_136 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_136 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 | V_31 ) ;
V_136 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_136 ;
}
static struct V_1 * F_60 ( struct V_130 * V_3 ,
T_2 V_12 , T_5 V_10 , T_2 V_13 , T_5 V_11 )
{
unsigned long V_29 ;
struct V_220 * V_259 ;
struct V_1 * V_2 ;
V_259 = & V_3 -> V_260 ;
F_39 ( & V_3 -> V_226 , V_29 ) ;
F_61 (cm_node, hte, list) {
F_7 ( V_14 , L_43 ,
V_2 -> V_11 , V_2 -> V_13 ,
V_11 , V_13 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_10 , V_12 ) ;
if ( ( V_2 -> V_11 == V_11 ) && ( V_2 -> V_13 == V_13 ) &&
( V_2 -> V_10 == V_10 ) && ( V_2 -> V_12 == V_12 ) ) {
F_2 ( V_2 ) ;
F_40 ( & V_3 -> V_226 , V_29 ) ;
return V_2 ;
}
}
F_40 ( & V_3 -> V_226 , V_29 ) ;
return NULL ;
}
static struct V_261 * F_62 ( struct V_130 * V_3 ,
T_5 V_262 , T_2 V_263 , enum V_264 V_265 )
{
unsigned long V_29 ;
struct V_261 * V_266 ;
F_39 ( & V_3 -> V_267 , V_29 ) ;
F_61 (listen_node, &cm_core->listen_list.list, list) {
if ( ( ( V_266 -> V_11 == V_262 ) ||
V_266 -> V_11 == 0x00000000 ) &&
( V_266 -> V_13 == V_263 ) &&
( V_265 & V_266 -> V_265 ) ) {
F_38 ( & V_266 -> V_268 ) ;
F_40 ( & V_3 -> V_267 , V_29 ) ;
return V_266 ;
}
}
F_40 ( & V_3 -> V_267 , V_29 ) ;
return NULL ;
}
static int F_63 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_220 * V_259 ;
if ( ! V_2 || ! V_3 )
return - V_43 ;
F_7 ( V_14 , L_44 ,
V_2 ) ;
F_39 ( & V_3 -> V_226 , V_29 ) ;
V_259 = & V_3 -> V_260 ;
F_64 ( & V_2 -> V_227 , V_259 ) ;
F_38 ( & V_3 -> V_269 ) ;
F_40 ( & V_3 -> V_226 , V_29 ) ;
return 0 ;
}
static int F_65 ( struct V_130 * V_3 ,
struct V_261 * V_270 , int V_271 )
{
int V_136 = - V_43 ;
int V_272 = 0 ;
unsigned long V_29 ;
struct V_220 * V_273 = NULL ;
struct V_220 * V_274 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_220 V_275 ;
F_7 ( V_14 , L_45
L_46 , V_270 , V_271 ,
F_26 ( & V_270 -> V_268 ) ) ;
F_50 ( & V_275 ) ;
if ( V_271 ) {
F_39 ( & V_3 -> V_226 , V_29 ) ;
F_51 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_52 ( V_273 , struct V_1 ,
V_227 ) ;
if ( ( V_2 -> V_270 == V_270 ) &&
( ! V_2 -> V_276 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_277 , & V_275 ) ;
}
}
F_40 ( & V_3 -> V_226 , V_29 ) ;
}
F_51 (list_pos, list_temp, &reset_list) {
V_2 = F_52 ( V_273 , struct V_1 ,
V_277 ) ;
{
struct V_1 * V_278 = V_2 -> V_279 ;
enum V_199 V_280 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_278 ) {
F_42 ( V_2 ) ;
V_272 = F_46 ( V_2 , NULL ) ;
if ( V_272 ) {
V_2 -> V_32 =
V_200 ;
F_33 ( 1 ) ;
} else {
V_280 = V_2 -> V_32 ;
V_2 -> V_32 = V_281 ;
if ( V_280 != V_282 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_278 ;
V_6 . V_9 . V_10 =
V_278 -> V_10 ;
V_6 . V_9 . V_11 =
V_278 -> V_11 ;
V_6 . V_9 . V_12 =
V_278 -> V_12 ;
V_6 . V_9 . V_13 =
V_278 -> V_13 ;
V_6 . V_9 . V_7 = V_278 -> V_7 ;
F_2 ( V_278 ) ;
V_278 -> V_32 = V_200 ;
F_66 ( & V_6 ) ;
V_2 -> V_32 = V_281 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_39 ( & V_3 -> V_267 , V_29 ) ;
if ( ! F_67 ( & V_270 -> V_268 ) ) {
F_68 ( & V_270 -> V_227 ) ;
F_69 ( & V_3 -> V_132 ) ;
F_40 ( & V_3 -> V_267 , V_29 ) ;
if ( V_270 -> V_283 )
F_70 ( V_270 -> V_283 , V_270 -> V_13 ,
F_71 ( V_270 -> V_283 -> V_284 -> V_285 -> V_286 ) , V_287 ) ;
F_7 ( V_14 , L_47 , V_270 ) ;
F_35 ( V_270 ) ;
V_270 = NULL ;
V_136 = 0 ;
F_38 ( & V_288 ) ;
} else {
F_40 ( & V_3 -> V_267 , V_29 ) ;
}
if ( V_270 ) {
if ( F_26 ( & V_270 -> V_289 ) > 0 )
F_7 ( V_14 , L_48
L_49 ,
V_270 , F_26 ( & V_270 -> V_289 ) ) ;
}
return V_136 ;
}
static int F_72 ( struct V_130 * V_3 ,
struct V_261 * V_270 )
{
V_270 -> V_265 = V_290 ;
V_270 -> V_7 = NULL ;
return F_65 ( V_3 , V_270 , 1 ) ;
}
static inline int F_73 ( struct V_130 * V_3 ,
struct V_1 * V_2 )
{
T_3 V_179 ;
V_2 -> V_276 = 1 ;
if ( V_2 -> V_291 ) {
F_74 ( ! V_2 -> V_270 ) ;
F_69 ( & V_2 -> V_270 -> V_289 ) ;
V_2 -> V_291 = 0 ;
F_74 ( F_26 ( & V_2 -> V_270 -> V_289 ) < 0 ) ;
}
V_179 = F_43 ( & V_3 -> V_196 ) ;
if ( ! V_179 ) {
V_3 -> V_196 . V_197 = V_185 + V_234 ;
F_44 ( & V_3 -> V_196 ) ;
}
return 0 ;
}
static int F_75 ( struct V_292 * V_283 , T_3 V_293 , int V_294 )
{
struct V_295 * V_296 ;
struct V_297 * V_298 ;
int V_299 = V_294 ;
struct V_300 * V_86 ;
struct V_301 * V_302 = V_283 -> V_284 -> V_302 ;
V_296 = F_76 ( & V_303 , F_23 ( V_293 ) , 0 , 0 , 0 ) ;
if ( F_77 ( V_296 ) ) {
F_32 ( V_158 L_50 ,
V_159 , V_293 ) ;
return V_299 ;
}
if ( F_78 ( V_283 -> V_86 ) )
V_86 = V_283 -> V_86 -> V_304 ;
else
V_86 = V_283 -> V_86 ;
V_298 = F_79 ( & V_305 , & V_296 -> V_306 , V_86 ) ;
F_80 () ;
if ( V_298 ) {
if ( V_298 -> V_307 & V_308 ) {
F_7 ( V_14 , L_51
L_52 , V_293 ,
V_298 -> V_309 , F_36 ( V_296 -> V_306 ) ) ;
if ( V_294 >= 0 ) {
if ( ! memcmp ( V_302 -> V_310 [ V_294 ] . V_311 ,
V_298 -> V_309 , V_95 ) ) {
goto V_312;
}
F_81 ( V_283 -> V_86 ,
V_302 -> V_310 [ V_294 ] . V_311 ,
V_293 , V_313 ) ;
}
F_81 ( V_283 -> V_86 , V_298 -> V_309 ,
V_293 , V_314 ) ;
V_299 = F_82 ( V_283 -> V_284 , V_293 , NULL ,
V_315 ) ;
} else {
F_83 ( V_298 , NULL ) ;
}
}
V_312:
F_84 () ;
if ( V_298 )
F_85 ( V_298 ) ;
F_86 ( V_296 ) ;
return V_299 ;
}
static struct V_1 * F_87 ( struct V_130 * V_3 ,
struct V_292 * V_283 , struct V_316 * V_9 ,
struct V_261 * V_270 )
{
struct V_1 * V_2 ;
struct V_317 V_318 ;
int V_319 = 0 ;
int V_294 = 0 ;
struct V_320 * V_284 ;
struct V_301 * V_302 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_48 = V_321 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_55 = V_62 ;
V_2 -> V_56 = V_62 ;
F_7 ( V_14 , L_53 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_270 = V_270 ;
V_2 -> V_86 = V_283 -> V_86 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_97 , V_283 -> V_86 -> V_322 , V_95 ) ;
F_7 ( V_14 , L_54 , V_2 -> V_270 ,
V_2 -> V_7 ) ;
F_88 ( & V_2 -> V_191 ) ;
V_2 -> V_279 = NULL ;
F_89 ( & V_2 -> V_268 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_105 . V_106 = V_323 ;
V_2 -> V_105 . V_252 = V_324 ;
V_2 -> V_105 . V_126 = V_325 >>
V_324 ;
V_318 = F_90 () ;
V_2 -> V_105 . V_114 = F_23 ( V_318 . V_326 ) ;
V_2 -> V_105 . V_248 = V_283 -> V_327 - sizeof( struct V_77 ) -
sizeof( struct V_75 ) - V_83 - V_328 ;
V_2 -> V_105 . V_116 = 0 ;
F_38 ( & V_3 -> V_133 ) ;
V_2 -> V_329 = V_9 -> V_329 ;
V_2 -> V_330 = 0 ;
V_2 -> V_291 = 0 ;
V_2 -> V_283 = V_283 ;
V_284 = V_283 -> V_284 ;
V_302 = V_284 -> V_302 ;
V_2 -> V_279 = NULL ;
V_319 = F_82 ( V_284 , V_2 -> V_10 , NULL , V_315 ) ;
V_294 = F_75 ( V_283 , V_9 -> V_10 , V_319 ) ;
if ( V_294 < 0 ) {
F_35 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_94 , V_302 -> V_310 [ V_294 ] . V_311 , V_95 ) ;
F_7 ( V_14 , L_55 ,
V_2 -> V_94 ) ;
F_63 ( V_3 , V_2 ) ;
F_38 ( & V_331 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_268 ) ;
return 0 ;
}
static int F_4 ( struct V_130 * V_3 ,
struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_140 * V_143 ;
if ( ! V_2 )
return - V_43 ;
F_39 ( & V_2 -> V_3 -> V_226 , V_29 ) ;
if ( F_67 ( & V_2 -> V_268 ) ) {
F_40 ( & V_2 -> V_3 -> V_226 , V_29 ) ;
return 0 ;
}
F_68 ( & V_2 -> V_227 ) ;
F_69 ( & V_3 -> V_269 ) ;
F_40 ( & V_2 -> V_3 -> V_226 , V_29 ) ;
if ( ! V_2 -> V_276 && V_2 -> V_291 ) {
F_74 ( ! V_2 -> V_270 ) ;
F_69 ( & V_2 -> V_270 -> V_289 ) ;
F_74 ( F_26 ( & V_2 -> V_270 -> V_289 ) < 0 ) ;
}
F_33 ( V_2 -> V_192 ) ;
if ( V_2 -> V_188 )
F_47 ( V_2 , 0 ) ;
if ( V_2 -> V_270 ) {
F_65 ( V_3 , V_2 -> V_270 , 0 ) ;
} else {
if ( V_2 -> V_330 && V_2 -> V_283 ) {
F_70 ( V_2 -> V_283 , V_2 -> V_13 ,
F_71 (
V_2 -> V_283 -> V_284 -> V_285 -> V_286 ) ,
V_287 ) ;
}
}
F_69 ( & V_3 -> V_133 ) ;
F_38 ( & V_332 ) ;
V_143 = V_2 -> V_143 ;
if ( V_143 ) {
V_143 -> V_2 = NULL ;
F_91 ( & V_143 -> V_333 ) ;
V_2 -> V_143 = NULL ;
}
F_35 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , T_1 * V_334 ,
T_3 V_72 , T_3 V_335 )
{
T_3 V_336 ;
T_3 V_337 = 0 ;
union V_243 * V_338 ;
char V_339 = 0 ;
while ( V_337 < V_72 ) {
V_338 = (union V_243 * ) ( V_334 + V_337 ) ;
switch ( V_338 -> V_255 . V_245 ) {
case V_258 :
V_337 = V_72 ;
break;
case V_340 :
V_337 += 1 ;
continue;
case V_246 :
F_7 ( V_14 , L_56
L_57 , V_159 ,
V_338 -> V_244 . V_247 , V_337 , V_72 ) ;
V_339 = 1 ;
if ( V_338 -> V_244 . V_247 != 4 ) {
return 1 ;
} else {
V_336 = F_16 ( V_338 -> V_244 . V_248 ) ;
if ( V_336 > 0 && V_336 <
V_2 -> V_105 . V_248 )
V_2 -> V_105 . V_248 = V_336 ;
}
break;
case V_250 :
V_2 -> V_105 . V_341 =
V_338 -> V_249 . V_251 ;
break;
default:
F_7 ( V_14 , L_58 ,
V_338 -> V_255 . V_245 ) ;
break;
}
V_337 += V_338 -> V_255 . V_247 ;
}
if ( ( ! V_339 ) && ( V_335 ) )
V_2 -> V_105 . V_248 = V_342 ;
return 0 ;
}
static void F_93 ( struct V_15 * V_16 )
{
F_38 ( & V_343 ) ;
F_94 ( V_16 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_59
L_46 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_268 ) ) ;
switch ( V_2 -> V_32 ) {
case V_201 :
case V_344 :
case V_345 :
case V_346 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_203 ;
F_59 ( V_2 , NULL ) ;
break;
case V_49 :
F_5 ( V_2 , V_205 ) ;
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_33 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_202 ;
F_58 ( V_2 , NULL ) ;
break;
case V_347 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_348 ;
F_58 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_186 , 1 , 0 ) ;
break;
case V_348 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_229 :
default:
F_7 ( V_14 , L_60 ,
V_2 , V_2 -> V_32 ) ;
break;
}
}
static void F_96 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_349 = 0 ;
F_38 ( & V_350 ) ;
F_7 ( V_14 , L_61
L_62 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_268 ) ) ;
F_42 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_344 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_159 , __LINE__ , V_2 ,
V_2 -> V_270 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_344 ;
if ( F_57 ( V_2 , 0 , NULL ) ) {
F_97 ( V_2 , V_16 , V_349 ) ;
}
break;
case V_46 :
default:
F_97 ( V_2 , V_16 , V_349 ) ;
break;
}
break;
case V_282 :
F_38 ( & V_2 -> V_351 ) ;
F_94 ( V_16 ) ;
break;
case V_345 :
case V_201 :
case V_352 :
F_7 ( V_14 , L_65 , V_159 , __LINE__ ) ;
F_98 ( V_2 , V_16 , V_349 ) ;
break;
case V_229 :
F_97 ( V_2 , V_16 , V_349 ) ;
break;
case V_200 :
F_93 ( V_16 ) ;
break;
case V_347 :
case V_33 :
case V_203 :
V_2 -> V_7 -> V_204 ( V_2 -> V_7 ) ;
case V_348 :
V_2 -> V_32 = V_200 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_93 ( V_16 ) ;
break;
default:
F_93 ( V_16 ) ;
break;
}
}
static void F_99 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_136 = 0 ;
int V_74 = V_16 -> V_35 ;
T_1 * V_353 = V_16 -> V_73 ;
enum V_5 type = V_354 ;
T_3 V_355 ;
V_136 = F_15 ( V_2 , V_353 , & V_355 , V_74 ) ;
if ( V_136 ) {
F_7 ( V_14 , L_66 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_67
L_68 , V_159 ,
__LINE__ , V_2 , V_2 -> V_270 ,
V_2 -> V_32 ) ;
F_97 ( V_2 , V_16 , 1 ) ;
} else {
F_98 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_345 :
if ( V_355 == V_70 )
F_33 ( 1 ) ;
V_2 -> V_32 = V_282 ;
type = V_356 ;
F_89 ( & V_2 -> V_351 ,
V_357 ) ;
break;
case V_49 :
F_42 ( V_2 ) ;
if ( V_355 == V_70 ) {
type = V_358 ;
V_2 -> V_32 = V_346 ;
} else {
type = V_359 ;
V_2 -> V_32 = V_229 ;
}
break;
default:
F_33 ( 1 ) ;
break;
}
F_94 ( V_16 ) ;
F_5 ( V_2 , type ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_2 -> V_32 ) {
case V_344 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_159 , __LINE__ , V_2 ,
V_2 -> V_270 , V_2 -> V_32 ) ;
F_97 ( V_2 , V_16 , 1 ) ;
break;
case V_345 :
case V_201 :
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_229 :
default:
F_93 ( V_16 ) ;
}
}
static int F_101 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 )
{
int V_272 ;
V_272 = ( ( F_36 ( V_76 -> V_117 ) == V_2 -> V_105 . V_114 ) ) ? 0 : 1 ;
if ( V_272 )
F_97 ( V_2 , V_16 , 1 ) ;
return V_272 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 )
{
int V_272 = 0 ;
T_3 V_113 ;
T_3 V_117 ;
T_3 V_114 = V_2 -> V_105 . V_114 ;
T_3 V_116 = V_2 -> V_105 . V_116 ;
T_3 V_126 ;
V_113 = F_36 ( V_76 -> V_113 ) ;
V_117 = F_36 ( V_76 -> V_117 ) ;
V_126 = V_2 -> V_105 . V_126 ;
if ( V_117 != V_114 )
V_272 = 1 ;
else if ( ! F_103 ( V_113 , V_116 , ( V_116 + V_126 ) ) )
V_272 = 1 ;
if ( V_272 ) {
F_7 ( V_14 , L_63
L_64 , V_159 , __LINE__ , V_2 ,
V_2 -> V_270 , V_2 -> V_32 ) ;
F_100 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_69
L_70 , V_2 , V_113 , V_116 ,
V_126 ) ;
}
return V_272 ;
}
static void F_104 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_136 ;
T_3 V_360 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_360 = F_36 ( V_76 -> V_113 ) ;
switch ( V_2 -> V_32 ) {
case V_344 :
case V_49 :
F_97 ( V_2 , V_16 , 1 ) ;
break;
case V_352 :
if ( F_26 ( & V_2 -> V_270 -> V_289 ) >
V_2 -> V_270 -> V_361 ) {
F_7 ( V_14 , L_71
L_72 ) ;
V_362 ++ ;
F_98 ( V_2 , V_16 , 0 ) ;
break;
}
V_136 = F_105 ( V_2 , V_76 , V_16 , V_72 ,
1 ) ;
if ( V_136 ) {
F_98 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_105 . V_116 = V_360 + 1 ;
F_74 ( V_2 -> V_192 ) ;
V_2 -> V_291 = 1 ;
F_38 ( & V_2 -> V_270 -> V_289 ) ;
V_2 -> V_32 = V_201 ;
F_57 ( V_2 , 1 , V_16 ) ;
break;
case V_200 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_229 :
case V_345 :
case V_33 :
case V_347 :
case V_282 :
case V_203 :
case V_202 :
case V_363 :
default:
F_93 ( V_16 ) ;
break;
}
}
static void F_106 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_136 ;
T_3 V_360 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_360 = F_36 ( V_76 -> V_113 ) ;
switch ( V_2 -> V_32 ) {
case V_344 :
F_42 ( V_2 ) ;
if ( F_101 ( V_2 , V_76 , V_16 ) )
return;
V_2 -> V_105 . V_232 = F_36 ( V_76 -> V_117 ) ;
V_136 = F_105 ( V_2 , V_76 , V_16 , V_72 , 0 ) ;
if ( V_136 ) {
F_7 ( V_14 , L_73 ,
V_2 ) ;
break;
}
F_42 ( V_2 ) ;
V_2 -> V_105 . V_116 = V_360 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_282 :
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_352 :
V_2 -> V_105 . V_114 = F_36 ( V_76 -> V_117 ) ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_200 :
V_2 -> V_105 . V_114 = F_36 ( V_76 -> V_117 ) ;
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_345 :
case V_33 :
case V_347 :
case V_203 :
case V_229 :
case V_202 :
case V_363 :
case V_49 :
default:
F_93 ( V_16 ) ;
break;
}
}
static int F_107 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_74 = 0 ;
T_3 V_360 ;
int V_136 = 0 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
if ( F_102 ( V_2 , V_76 , V_16 ) )
return - V_43 ;
F_108 ( V_16 , V_76 -> V_124 << 2 ) ;
V_360 = F_36 ( V_76 -> V_113 ) ;
V_74 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_201 :
F_42 ( V_2 ) ;
V_136 = F_105 ( V_2 , V_76 , V_16 , V_72 , 1 ) ;
if ( V_136 )
break;
V_2 -> V_105 . V_232 = F_36 ( V_76 -> V_117 ) ;
V_2 -> V_32 = V_345 ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_360 + V_74 ;
F_99 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
break;
case V_345 :
F_42 ( V_2 ) ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_360 + V_74 ;
F_99 ( V_2 , V_16 ) ;
} else {
F_93 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_105 . V_232 = F_36 ( V_76 -> V_117 ) ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_360 + V_74 ;
F_99 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
break;
case V_352 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_200 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_203 :
case V_202 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
V_2 -> V_7 -> V_204 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_93 ( V_16 ) ;
break;
case V_33 :
F_42 ( V_2 ) ;
F_93 ( V_16 ) ;
V_2 -> V_32 = V_347 ;
break;
case V_344 :
case V_347 :
case V_229 :
case V_282 :
case V_363 :
default:
F_42 ( V_2 ) ;
F_93 ( V_16 ) ;
break;
}
return V_136 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 , int V_72 , int V_364 )
{
T_1 * V_334 = ( T_1 * ) & V_76 [ 1 ] ;
if ( V_72 ) {
if ( F_92 ( V_2 , V_334 , V_72 ,
( T_3 ) V_76 -> V_120 ) ) {
F_7 ( V_14 , L_74 ,
V_159 , V_2 ) ;
if ( V_364 )
F_98 ( V_2 , V_16 , 1 ) ;
else
F_97 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_105 . V_365 = F_16 ( V_76 -> V_125 ) <<
V_2 -> V_105 . V_341 ;
if ( V_2 -> V_105 . V_365 > V_2 -> V_105 . V_366 )
V_2 -> V_105 . V_366 = V_2 -> V_105 . V_365 ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_349 )
{
F_42 ( V_2 ) ;
if ( V_349 ) {
F_7 ( V_14 , L_75
L_76 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
V_2 -> V_32 = V_200 ;
F_5 ( V_2 , V_205 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_349 )
{
F_42 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
if ( V_349 ) {
F_7 ( V_14 , L_77
L_78 , V_2 , V_2 -> V_32 ) ;
F_46 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_177 * V_192 ;
V_192 = V_2 -> V_192 ;
if ( V_192 ) {
V_2 -> V_192 = NULL ;
F_94 ( V_192 -> V_16 ) ;
F_35 ( V_192 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_39 ( & V_2 -> V_191 , V_29 ) ;
F_55 ( V_2 ) ;
F_40 ( & V_2 -> V_191 , V_29 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_130 * V_3 )
{
enum V_367 V_368 = V_369 ;
struct V_75 * V_76 = F_37 ( V_16 ) ;
T_3 V_370 = 0 ;
int V_136 = 0 ;
F_108 ( V_16 , F_110 ( V_16 ) -> V_101 << 2 ) ;
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 , V_76 -> V_120 ,
V_76 -> V_118 , V_76 -> V_123 , V_76 -> V_121 ) ;
if ( V_76 -> V_123 ) {
V_368 = V_371 ;
} else if ( V_76 -> V_120 ) {
V_368 = V_372 ;
if ( V_76 -> V_118 )
V_368 = V_373 ;
} else if ( V_76 -> V_118 ) {
V_368 = V_374 ;
}
if ( V_76 -> V_121 )
V_370 = 1 ;
switch ( V_368 ) {
case V_372 :
F_104 ( V_2 , V_16 , V_76 ) ;
break;
case V_373 :
F_106 ( V_2 , V_16 , V_76 ) ;
break;
case V_374 :
V_136 = F_107 ( V_2 , V_16 , V_76 ) ;
if ( V_370 && ! V_136 )
F_95 ( V_2 ) ;
break;
case V_371 :
F_96 ( V_2 , V_16 , V_76 ) ;
break;
default:
if ( ( V_370 ) && ( ! F_102 ( V_2 , V_76 , V_16 ) ) )
F_95 ( V_2 ) ;
F_93 ( V_16 ) ;
break;
}
}
static struct V_261 * F_111 ( struct V_130 * V_3 ,
struct V_292 * V_283 , struct V_316 * V_9 )
{
struct V_261 * V_270 ;
unsigned long V_29 ;
F_7 ( V_14 , L_81 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_270 = F_62 ( V_3 , F_23 ( V_9 -> V_11 ) ,
F_22 ( V_9 -> V_13 ) , V_375 ) ;
if ( V_270 && V_270 -> V_265 == V_376 ) {
F_69 ( & V_270 -> V_268 ) ;
F_7 ( V_14 , L_82 ) ;
return NULL ;
}
if ( ! V_270 ) {
V_270 = F_6 ( sizeof( * V_270 ) , V_8 ) ;
if ( ! V_270 ) {
F_7 ( V_14 , L_83 ) ;
return NULL ;
}
V_270 -> V_11 = F_23 ( V_9 -> V_11 ) ;
V_270 -> V_13 = F_22 ( V_9 -> V_13 ) ;
V_270 -> V_377 = 0 ;
F_89 ( & V_270 -> V_268 , 1 ) ;
}
else {
V_270 -> V_377 = 1 ;
}
V_270 -> V_7 = V_9 -> V_7 ;
F_89 ( & V_270 -> V_289 , 0 ) ;
V_270 -> V_3 = V_3 ;
V_270 -> V_283 = V_283 ;
F_38 ( & V_3 -> V_133 ) ;
V_270 -> V_329 = V_9 -> V_329 ;
V_270 -> V_361 = V_9 -> V_361 ;
V_270 -> V_265 = V_376 ;
if ( ! V_270 -> V_377 ) {
F_39 ( & V_3 -> V_267 , V_29 ) ;
F_53 ( & V_270 -> V_227 , & V_3 -> V_378 . V_227 ) ;
F_40 ( & V_3 -> V_267 , V_29 ) ;
F_38 ( & V_3 -> V_132 ) ;
}
F_7 ( V_14 , L_84
L_85 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_270 , V_270 -> V_361 , V_270 -> V_7 ) ;
return V_270 ;
}
static struct V_1 * F_112 ( struct V_130 * V_3 ,
struct V_292 * V_283 , T_2 V_379 ,
void * V_380 , struct V_316 * V_9 )
{
int V_136 = 0 ;
struct V_1 * V_2 ;
struct V_261 * V_381 ;
struct V_1 * V_382 ;
struct V_316 V_383 ;
T_1 * V_19 ;
V_2 = F_87 ( V_3 , V_283 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_105 . V_384 = 1 ;
V_2 -> V_105 . V_252 = V_324 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_381 = F_62 ( V_3 ,
F_36 ( V_283 -> V_385 ) , V_2 -> V_12 ,
V_376 ) ;
if ( V_381 == NULL ) {
F_5 ( V_2 , V_205 ) ;
} else {
V_383 = * V_9 ;
V_383 . V_13 = V_9 -> V_12 ;
V_383 . V_12 = V_9 -> V_13 ;
V_383 . V_7 = V_381 -> V_7 ;
V_382 = F_87 ( V_3 , V_283 ,
& V_383 , V_381 ) ;
if ( ! V_382 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_38 ( & V_386 ) ;
V_382 -> V_279 = V_2 ;
V_382 -> V_105 . V_252 =
V_324 ;
V_2 -> V_279 = V_382 ;
memcpy ( V_382 -> V_69 , V_380 ,
V_379 ) ;
V_382 -> V_54 = V_379 ;
V_2 -> V_32 = V_229 ;
V_2 -> V_105 . V_116 =
V_382 -> V_105 . V_114 ;
V_382 -> V_105 . V_116 =
V_2 -> V_105 . V_114 ;
V_2 -> V_105 . V_366 =
V_382 -> V_105 . V_126 ;
V_382 -> V_105 . V_366 =
V_2 -> V_105 . V_126 ;
V_2 -> V_105 . V_365 =
V_382 -> V_105 . V_126 ;
V_382 -> V_105 . V_365 =
V_2 -> V_105 . V_126 ;
V_2 -> V_105 . V_341 =
V_382 -> V_105 . V_252 ;
V_382 -> V_105 . V_341 =
V_2 -> V_105 . V_252 ;
V_382 -> V_32 = V_282 ;
F_5 ( V_382 , V_356 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_379 ;
memcpy ( V_19 , V_380 , V_379 ) ;
V_2 -> V_32 = V_344 ;
V_136 = F_57 ( V_2 , 0 , NULL ) ;
if ( V_136 ) {
F_7 ( V_14 , L_86
L_87 ,
V_2 -> V_10 , V_2 -> V_12 , V_2 ,
V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
V_2 = NULL ;
}
if ( V_2 ) {
F_7 ( V_14 , L_88
L_89 ,
V_2 -> V_10 , V_2 -> V_12 , V_2 ,
V_2 -> V_7 ) ;
}
return V_2 ;
}
static int F_113 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_114 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
int V_136 = 0 ;
int V_272 = 0 ;
int V_351 ;
struct V_4 V_6 ;
struct V_198 * V_7 = V_2 -> V_7 ;
struct V_1 * V_278 = V_2 -> V_279 ;
F_7 ( V_14 , L_90 ,
V_159 , V_2 , V_2 -> V_105 . V_384 , V_2 -> V_32 ) ;
if ( V_2 -> V_105 . V_384 )
return V_136 ;
F_42 ( V_2 ) ;
if ( ! V_278 ) {
V_351 = F_115 ( 1 , & V_2 -> V_351 ) ;
if ( V_351 == V_387 ) {
V_2 -> V_32 = V_200 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_281 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_136 = F_13 ( V_2 ) ;
if ( V_136 ) {
V_2 -> V_32 = V_200 ;
V_272 = F_46 ( V_2 , NULL ) ;
if ( V_272 )
F_33 ( 1 ) ;
} else {
V_7 -> V_388 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_281 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_278 ) ;
} else {
V_6 . V_2 = V_278 ;
V_6 . V_9 . V_10 = V_278 -> V_10 ;
V_6 . V_9 . V_11 = V_278 -> V_11 ;
V_6 . V_9 . V_12 = V_278 -> V_12 ;
V_6 . V_9 . V_13 = V_278 -> V_13 ;
V_6 . V_9 . V_7 = V_278 -> V_7 ;
F_116 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_278 -> V_32 = V_202 ;
V_7 = V_278 -> V_7 ;
F_4 ( V_3 , V_278 ) ;
V_7 -> V_204 ( V_7 ) ;
}
}
return V_136 ;
}
static int F_117 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
int V_136 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_201 :
case V_344 :
case V_389 :
case V_345 :
case V_390 :
case V_49 :
case V_282 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_391 :
V_2 -> V_32 = V_203 ;
F_59 ( V_2 , NULL ) ;
break;
case V_33 :
case V_347 :
case V_203 :
case V_348 :
case V_202 :
V_136 = - 1 ;
break;
case V_352 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_346 :
case V_363 :
case V_392 :
case V_200 :
case V_281 :
V_136 = F_4 ( V_3 , V_2 ) ;
break;
case V_229 :
if ( V_2 -> V_192 )
F_32 ( V_158 L_91
L_92 , V_2 -> V_192 ) ;
V_136 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_136 ;
}
static int F_118 ( struct V_130 * V_3 ,
struct V_292 * V_283 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_261 * V_270 = NULL ;
struct V_77 * V_78 ;
struct V_75 * V_76 ;
struct V_316 V_393 ;
int V_394 = 1 ;
T_6 V_395 , V_396 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_77 ) + sizeof( struct V_75 ) )
return 0 ;
V_78 = (struct V_77 * ) V_16 -> V_73 ;
V_76 = (struct V_75 * ) ( V_16 -> V_73 + sizeof( struct V_77 ) ) ;
V_393 . V_11 = F_36 ( V_78 -> V_110 ) ;
V_393 . V_13 = F_16 ( V_76 -> V_112 ) ;
V_393 . V_10 = F_36 ( V_78 -> V_109 ) ;
V_393 . V_12 = F_16 ( V_76 -> V_111 ) ;
V_395 = F_119 ( V_78 -> V_110 ) ;
V_396 = F_119 ( V_78 -> V_109 ) ;
F_7 ( V_14 , L_93 ,
& V_395 , V_76 -> V_112 , & V_396 , V_76 -> V_111 ) ;
do {
V_2 = F_60 ( V_3 ,
V_393 . V_12 , V_393 . V_10 ,
V_393 . V_13 , V_393 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_76 -> V_120 ) || ( V_76 -> V_118 ) ) {
V_394 = 0 ;
break;
}
V_270 = F_62 ( V_3 , V_393 . V_11 ,
V_393 . V_13 ,
V_376 ) ;
if ( ! V_270 ) {
V_393 . V_7 = NULL ;
V_393 . V_329 = 0 ;
F_7 ( V_14 , L_94 ) ;
V_394 = 0 ;
break;
}
V_393 . V_7 = V_270 -> V_7 ;
V_393 . V_329 = V_270 -> V_329 ;
V_2 = F_87 ( V_3 , V_283 , & V_393 ,
V_270 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_95
L_96 ) ;
V_230 ++ ;
F_69 ( & V_270 -> V_268 ) ;
F_94 ( V_16 ) ;
break;
}
if ( ! V_76 -> V_123 && ! V_76 -> V_121 ) {
V_2 -> V_32 = V_352 ;
} else {
V_230 ++ ;
F_4 ( V_3 , V_2 ) ;
F_94 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_229 ) {
if ( V_2 -> V_143 -> V_397 )
F_120 ( V_16 , V_283 , V_2 -> V_143 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_38 ( & V_343 ) ;
F_94 ( V_16 ) ;
}
break;
}
F_121 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_76 ) ) ;
V_16 -> V_35 = F_16 ( V_78 -> V_103 ) ;
F_109 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_394 ;
}
static struct V_130 * F_122 ( void )
{
struct V_130 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_398 ) ;
if ( ! V_3 )
return NULL ;
F_50 ( & V_3 -> V_260 ) ;
F_123 ( & V_3 -> V_196 ) ;
V_3 -> V_196 . V_399 = F_49 ;
V_3 -> V_400 = V_401 ;
V_3 -> V_32 = V_392 ;
V_3 -> V_402 = V_403 ;
F_89 ( & V_3 -> V_404 , 0 ) ;
V_3 -> V_405 = & V_406 ;
F_88 ( & V_3 -> V_226 ) ;
F_88 ( & V_3 -> V_267 ) ;
F_50 ( & V_3 -> V_378 . V_227 ) ;
F_7 ( V_14 , L_97 , V_3 ) ;
F_7 ( V_14 , L_98 ) ;
V_3 -> V_407 = F_124 ( L_99 ) ;
V_3 -> V_408 = F_8 ;
F_7 ( V_14 , L_100 ) ;
V_3 -> V_409 = F_124 ( L_101 ) ;
F_25 ( V_3 ) ;
return V_3 ;
}
static int F_125 ( struct V_130 * V_3 )
{
F_7 ( V_14 , L_102 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_126 () ;
if ( F_43 ( & V_3 -> V_196 ) )
F_127 ( & V_3 -> V_196 ) ;
F_128 ( V_3 -> V_407 ) ;
F_128 ( V_3 -> V_409 ) ;
F_7 ( V_14 , L_103 ) ;
F_35 ( V_3 ) ;
return 0 ;
}
static int F_129 ( struct V_130 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_130 ( struct V_130 * V_3 , T_3 type , T_3 V_410 )
{
int V_136 = 0 ;
switch ( type ) {
case V_411 :
V_3 -> V_400 = V_410 ;
break;
case V_412 :
V_3 -> V_402 = V_410 ;
break;
default:
V_136 = - V_43 ;
}
return V_136 ;
}
static int F_131 ( struct V_140 * V_143 , struct V_1 * V_2 )
{
int V_136 = 0 ;
if ( ! V_143 )
return - V_43 ;
V_143 -> V_167 -> V_413 |= F_31 ( V_414 |
V_415 | V_416 |
V_417 ) ;
if ( V_2 -> V_105 . V_341 || V_2 -> V_105 . V_252 )
V_143 -> V_167 -> V_413 |= F_31 ( V_418 ) ;
V_143 -> V_167 -> V_419 |= F_31 ( 64 << V_420 ) ;
V_143 -> V_167 -> V_248 |= F_31 ( ( ( T_3 ) V_2 -> V_105 . V_248 ) << 16 ) ;
V_143 -> V_167 -> V_421 |= F_31 (
( T_3 ) V_422 << V_423 ) ;
V_143 -> V_167 -> V_424 |= F_31 (
( V_2 -> V_105 . V_341 << V_425 ) &
V_426 ) ;
V_143 -> V_167 -> V_424 |= F_31 (
( V_2 -> V_105 . V_252 << V_427 ) &
V_428 ) ;
V_143 -> V_167 -> V_429 = F_31 ( 0x80 ) ;
V_143 -> V_167 -> V_430 = 0 ;
V_143 -> V_167 -> V_431 = 0 ;
V_143 -> V_167 -> V_432 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_167 -> V_365 = F_31 ( V_2 -> V_105 . V_365 ) ;
V_143 -> V_167 -> V_116 = F_31 ( V_2 -> V_105 . V_116 ) ;
V_143 -> V_167 -> V_126 = F_31 ( V_2 -> V_105 . V_126 <<
V_2 -> V_105 . V_252 ) ;
V_143 -> V_167 -> V_433 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_167 -> V_434 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_167 -> V_435 = 0 ;
V_143 -> V_167 -> V_436 = F_31 ( 0x6 ) ;
V_143 -> V_167 -> V_437 = F_31 ( 0x3FFFC000 ) ;
V_143 -> V_167 -> V_438 = F_31 ( 2 * V_2 -> V_105 . V_248 ) ;
V_143 -> V_167 -> V_439 = F_31 ( V_2 -> V_105 . V_116 ) ;
V_143 -> V_167 -> V_440 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_167 -> V_366 = F_31 ( V_2 -> V_105 . V_366 ) ;
F_7 ( V_14 , L_104
L_105 ,
V_143 -> V_146 . V_209 , F_132 ( V_143 -> V_167 -> V_116 ) ,
F_132 ( V_143 -> V_167 -> V_432 ) ,
V_2 -> V_105 . V_248 , F_132 ( V_143 -> V_167 -> V_424 ) ,
F_132 ( V_143 -> V_167 -> V_126 ) ,
F_132 ( V_143 -> V_167 -> V_413 ) ) ;
F_7 ( V_14 , L_106 , F_132 ( V_143 -> V_167 -> V_365 ) ) ;
F_7 ( V_14 , L_107 , F_132 ( V_143 -> V_167 -> V_438 ) ) ;
F_7 ( V_14 , L_108 , F_132 ( V_143 -> V_167 -> V_366 ) ) ;
F_7 ( V_14 , L_109 ) ;
V_2 -> V_32 = V_229 ;
return V_136 ;
}
int F_48 ( struct V_140 * V_143 )
{
struct V_441 * V_442 ;
V_442 = F_6 ( sizeof *V_442 , V_8 ) ;
if ( ! V_442 )
return - V_27 ;
F_133 ( & V_143 -> V_333 ) ;
V_442 -> V_143 = V_143 ;
F_134 ( & V_442 -> V_442 , V_443 ) ;
F_135 ( V_223 -> V_409 , & V_442 -> V_442 ) ;
return 0 ;
}
static void V_443 ( struct V_444 * V_442 )
{
struct V_441 * V_445 = F_52 ( V_442 , struct V_441 , V_442 ) ;
struct V_140 * V_143 = V_445 -> V_143 ;
F_35 ( V_445 ) ;
F_7 ( V_14 , L_110 ,
V_143 -> V_213 , V_143 -> V_146 . V_209 ) ;
F_136 ( V_143 ) ;
F_91 ( & V_143 -> V_333 ) ;
}
static int F_136 ( struct V_140 * V_143 )
{
unsigned long V_29 ;
int V_136 = 0 ;
struct V_198 * V_7 ;
struct V_446 V_447 ;
struct V_292 * V_283 ;
T_2 V_448 ;
T_1 V_449 ;
T_1 V_450 ;
int V_451 = 0 ;
int V_452 = 0 ;
int V_453 = 0 ;
int V_454 = 0 ;
T_3 V_455 = V_456 ;
struct V_457 V_458 ;
if ( ! V_143 ) {
F_7 ( V_14 , L_111 ) ;
return - 1 ;
}
F_39 ( & V_143 -> V_208 , V_29 ) ;
V_7 = V_143 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_112 ,
V_143 -> V_146 . V_209 ) ;
F_40 ( & V_143 -> V_208 , V_29 ) ;
return - 1 ;
}
V_283 = F_137 ( V_143 -> V_333 . V_459 ) ;
F_7 ( V_14 , L_113 , V_143 -> V_146 . V_209 ) ;
V_449 = V_143 -> V_211 ;
V_450 = V_143 -> V_215 ;
V_448 = V_143 -> V_213 ;
if ( V_143 -> V_460 ) {
V_452 = 1 ;
V_453 = 1 ;
V_143 -> V_7 = NULL ;
F_127 ( & V_143 -> V_461 ) ;
if ( V_143 -> V_462 == 0 ) {
V_143 -> V_462 = 1 ;
V_454 = 1 ;
}
} else if ( ( V_449 == V_463 ) ||
( ( V_450 == V_464 ) &&
( V_448 == V_465 ) ) ) {
V_452 = 1 ;
if ( V_448 == V_465 )
V_451 = - V_466 ;
}
if ( ( ( V_449 == V_212 ) ||
( V_449 == V_467 ) ||
( V_448 == V_468 ) ||
( V_448 == V_465 ) ) ) {
V_453 = 1 ;
V_143 -> V_7 = NULL ;
if ( V_143 -> V_462 == 0 ) {
V_143 -> V_462 = 1 ;
V_454 = 1 ;
}
}
F_40 ( & V_143 -> V_208 , V_29 ) ;
if ( ( V_454 ) && ( V_143 -> V_469 == 0 ) ) {
if ( V_143 -> V_470 >= V_471 )
V_455 |= V_472 ;
F_138 ( V_283 -> V_284 , V_143 , V_455 , 1 ) ;
if ( V_143 -> V_460 ) {
V_458 . V_459 = V_143 -> V_333 . V_459 ;
V_458 . V_6 = V_143 -> V_473 ;
V_458 . V_474 . V_475 = & V_143 -> V_333 ;
if ( V_143 -> V_333 . V_476 )
V_143 -> V_333 . V_476 ( & V_458 , V_143 -> V_333 . V_477 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_476 ) ) {
if ( V_452 ) {
F_38 ( & V_478 ) ;
V_447 . V_6 = V_479 ;
V_447 . V_480 = V_451 ;
V_447 . V_481 = V_7 -> V_481 ;
V_447 . V_482 = V_7 -> V_482 ;
V_447 . V_380 = NULL ;
V_447 . V_379 = 0 ;
F_7 ( V_14 , L_114
L_115
L_116 ,
V_143 -> V_146 . V_209 , V_143 -> V_146 . V_483 ,
V_143 -> V_146 . V_173 , V_7 ,
F_26 ( & V_143 -> V_210 ) ) ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
if ( V_136 )
F_7 ( V_14 , L_117
L_118 , V_136 ) ;
}
if ( V_453 ) {
F_38 ( & V_484 ) ;
F_139 ( V_143 , 1 ) ;
V_7 -> V_485 = V_143 ;
V_447 . V_6 = V_486 ;
V_447 . V_480 = 0 ;
V_447 . V_485 = V_7 -> V_485 ;
V_447 . V_481 = V_7 -> V_481 ;
V_447 . V_482 = V_7 -> V_482 ;
V_447 . V_380 = NULL ;
V_447 . V_379 = 0 ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
if ( V_136 )
F_7 ( V_14 , L_119 , V_136 ) ;
V_7 -> V_204 ( V_7 ) ;
}
}
return 0 ;
}
static int F_139 ( struct V_140 * V_143 , int V_487 )
{
int V_136 = 0 ;
struct V_292 * V_283 ;
struct V_320 * V_284 ;
struct V_488 * V_489 ;
V_283 = F_137 ( V_143 -> V_333 . V_459 ) ;
if ( ! V_283 )
return - V_43 ;
V_284 = V_283 -> V_284 ;
V_489 = V_283 -> V_489 ;
F_7 ( V_14 , L_120 ,
F_140 ( V_283 -> V_86 ) ) ;
if ( V_143 -> V_490 ) {
V_143 -> V_490 = 0 ;
} else {
if ( V_143 -> V_491 ) {
if ( V_143 -> V_492 )
V_489 -> V_493 . V_494 ( V_143 -> V_492 ) ;
F_141 ( V_284 -> V_285 ,
V_143 -> V_379 + V_143 -> V_495 ,
V_143 -> V_491 , V_143 -> V_496 ) ;
}
}
if ( V_143 -> V_2 ) {
F_7 ( V_14 , L_121 ) ;
V_223 -> V_405 -> V_497 ( V_223 , V_143 -> V_2 ) ;
}
return V_136 ;
}
int F_142 ( struct V_198 * V_7 , struct V_498 * V_499 )
{
T_4 V_142 ;
struct V_500 * V_333 ;
struct V_140 * V_143 ;
struct V_292 * V_283 ;
struct V_320 * V_284 ;
struct V_1 * V_2 ;
struct V_301 * V_501 ;
struct V_502 V_503 ;
struct V_446 V_447 ;
struct V_144 * V_145 ;
struct V_504 V_505 ;
T_3 V_506 ;
int V_136 ;
int V_351 ;
struct V_488 * V_489 ;
struct V_507 * V_508 = NULL ;
struct V_509 V_510 ;
struct V_511 * V_512 ;
T_4 V_513 ;
T_1 V_514 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
V_333 = F_143 ( V_7 -> V_459 , V_499 -> V_515 ) ;
if ( ! V_333 )
return - V_43 ;
V_143 = F_144 ( V_333 ) ;
V_283 = F_137 ( V_143 -> V_333 . V_459 ) ;
V_284 = V_283 -> V_284 ;
V_501 = V_284 -> V_302 ;
V_2 = (struct V_1 * ) V_7 -> V_485 ;
F_7 ( V_14 , L_122
L_123 , V_2 , V_283 , V_283 -> V_86 ,
V_283 -> V_86 -> V_516 ) ;
if ( V_281 == V_2 -> V_32 ) {
if ( V_2 -> V_279 )
F_4 ( V_2 -> V_3 , V_2 -> V_279 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_351 = F_115 ( 1 , & V_2 -> V_351 ) ;
if ( V_351 == V_387 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_466 ;
}
V_143 -> V_2 = ( void * ) V_2 ;
V_2 -> V_143 = V_143 ;
F_7 ( V_14 , L_124 ,
V_143 -> V_146 . V_209 , V_2 , V_185 , V_2 -> V_270 ) ;
F_38 ( & V_517 ) ;
F_7 ( V_14 , L_120 ,
F_140 ( V_283 -> V_86 ) ) ;
V_143 -> V_495 = sizeof( struct V_36 ) ;
V_143 -> V_491 = F_145 ( V_284 -> V_285 ,
V_143 -> V_495 + V_499 -> V_379 ,
& V_143 -> V_496 ) ;
if ( ! V_143 -> V_491 ) {
F_7 ( V_14 , L_125 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_143 -> V_491 ;
if ( V_2 -> V_48 == V_46 )
V_514 = 4 ;
memcpy ( V_37 -> V_518 , V_499 -> V_380 ,
V_499 -> V_379 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_143 -> V_491 , V_28 ) ;
V_143 -> V_379 = V_499 -> V_379 ;
V_145 = & V_143 -> V_146 . V_147 [ 0 ] ;
if ( V_7 -> V_482 . V_519 . V_520 !=
V_7 -> V_481 . V_519 . V_520 ) {
V_142 = ( unsigned long ) V_143 ;
V_489 = V_283 -> V_489 ;
V_512 = V_143 -> V_512 ;
V_510 . V_521 = V_143 -> V_496 + V_514 ;
V_510 . V_522 = V_20 ;
V_513 = ( T_4 ) ( unsigned long ) * V_19 ;
V_508 = V_489 -> V_493 . V_523 ( (struct V_524 * ) V_512 ,
& V_510 , 1 ,
V_525 ,
& V_513 ) ;
if ( ! V_508 ) {
F_7 ( V_14 , L_126
L_127 ,
V_2 ) ;
F_141 ( V_284 -> V_285 ,
V_143 -> V_379 + V_143 -> V_495 ,
V_143 -> V_491 , V_143 -> V_496 ) ;
return - V_27 ;
}
V_508 -> V_526 = & V_512 -> V_527 ;
V_508 -> V_459 = V_512 -> V_527 . V_459 ;
V_143 -> V_492 = V_508 ;
V_142 |= V_148 >> 1 ;
F_30 ( V_145 -> V_149 ,
V_150 ,
V_142 ) ;
V_145 -> V_149 [ V_153 ] =
F_31 ( V_528 |
V_529 ) ;
V_145 -> V_149 [ V_155 ] =
F_31 ( V_20 ) ;
F_30 ( V_145 -> V_149 ,
V_151 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_145 -> V_149 [ V_156 ] =
F_31 ( V_20 ) ;
V_145 -> V_149 [ V_157 ] = V_508 -> V_530 ;
if ( V_143 -> V_165 ) {
V_143 -> V_165 = 0 ;
F_34 ( V_143 -> V_166 ) ;
}
V_143 -> V_167 -> V_168 |=
F_31 ( V_169 |
V_170 ) ;
} else {
V_143 -> V_167 -> V_168 |=
F_31 ( V_170 ) ;
}
V_143 -> V_172 = 1 ;
V_143 -> V_7 = V_7 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_485 = V_143 ;
V_143 -> V_490 = 0 ;
if ( V_2 -> V_32 == V_229 )
F_7 ( V_14 , L_128 ,
V_2 ) ;
F_131 ( V_143 , V_2 ) ;
V_143 -> V_167 -> V_531 [ 0 ] =
F_146 ( F_16 ( V_7 -> V_481 . V_532 ) ) ;
V_143 -> V_167 -> V_531 [ 1 ] =
F_146 ( F_16 ( V_7 -> V_482 . V_532 ) ) ;
V_143 -> V_167 -> V_533 =
F_31 ( F_36 ( V_7 -> V_482 . V_519 . V_520 ) ) ;
V_143 -> V_167 -> V_419 |= F_31 (
( T_3 ) F_71 ( V_284 -> V_285 -> V_286 ) <<
V_534 ) ;
V_143 -> V_167 -> V_535 |=
F_31 ( F_82 ( V_284 ,
F_132 ( V_143 -> V_167 -> V_533 ) , NULL ,
V_315 ) << 16 ) ;
V_143 -> V_167 -> V_536 = F_31 (
V_185 - F_147 ( V_284 , V_537 ) ) ;
V_143 -> V_167 -> V_538 = F_31 ( V_143 -> V_146 . V_209 ) ;
V_143 -> V_167 -> V_168 |= F_31 (
( ( T_3 ) 1 << V_539 ) ) ;
V_143 -> V_167 -> V_168 |=
F_31 ( ( T_3 ) V_499 -> V_540 ) ;
memset ( & V_505 , 0 , sizeof( V_505 ) ) ;
V_505 . V_541 =
F_31 ( ( T_3 ) F_71 ( V_284 -> V_285 -> V_286 ) << 24 ) ;
V_505 . V_542 = V_7 -> V_482 . V_519 . V_520 ;
V_505 . V_543 [ 0 ] = V_7 -> V_482 . V_532 ;
V_505 . V_543 [ 1 ] = V_7 -> V_481 . V_532 ;
V_506 = F_148 ( & V_505 ) ;
V_143 -> V_544 = F_119 ( V_506 ^ 0xffffffff ) ;
F_7 ( V_14 , L_129 ,
V_143 -> V_544 , V_143 -> V_544 & V_501 -> V_545 ) ;
V_143 -> V_544 &= V_501 -> V_545 ;
V_143 -> V_167 -> V_544 = F_31 ( V_143 -> V_544 ) ;
V_2 -> V_3 -> V_405 -> V_276 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_130
L_131
L_132 , V_143 -> V_146 . V_209 ,
F_36 ( V_7 -> V_482 . V_519 . V_520 ) ,
F_16 ( V_7 -> V_482 . V_532 ) ,
F_36 ( V_7 -> V_481 . V_519 . V_520 ) ,
F_16 ( V_7 -> V_481 . V_532 ) ,
F_132 ( V_143 -> V_167 -> V_116 ) ,
F_132 ( V_143 -> V_167 -> V_432 ) ,
V_20 ) ;
V_7 -> V_388 ( V_7 ) ;
F_133 ( & V_143 -> V_333 ) ;
V_447 . V_6 = V_546 ;
V_447 . V_480 = 0 ;
V_447 . V_485 = ( void * ) V_143 ;
V_447 . V_481 = V_7 -> V_481 ;
V_447 . V_482 = V_7 -> V_482 ;
V_447 . V_380 = NULL ;
V_447 . V_379 = 0 ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
V_503 . V_547 = V_464 ;
F_149 ( & V_143 -> V_333 , & V_503 , V_548 , NULL ) ;
if ( V_2 -> V_279 ) {
V_2 -> V_279 -> V_54 =
V_143 -> V_379 ;
memcpy ( V_2 -> V_279 -> V_69 ,
V_499 -> V_380 , V_499 -> V_379 ) ;
F_5 ( V_2 -> V_279 , V_359 ) ;
}
if ( V_136 )
F_32 ( V_158 L_133
L_134 , V_159 , __LINE__ , V_136 ) ;
return 0 ;
}
int F_150 ( struct V_198 * V_7 , const void * V_549 , T_1 V_550 )
{
struct V_1 * V_2 ;
struct V_1 * V_278 ;
struct V_130 * V_3 ;
T_1 * V_19 ;
F_38 ( & V_551 ) ;
V_2 = (struct V_1 * ) V_7 -> V_485 ;
V_278 = V_2 -> V_279 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_550 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_278 ) {
memcpy ( & V_278 -> V_25 . V_518 , V_549 , V_550 ) ;
V_278 -> V_25 . V_41 = V_550 ;
V_278 -> V_54 = V_550 ;
} else {
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_550 ;
memcpy ( V_19 , V_549 , V_550 ) ;
}
return V_3 -> V_405 -> V_552 ( V_3 , V_2 ) ;
}
int F_151 ( struct V_198 * V_7 , struct V_498 * V_499 )
{
struct V_500 * V_333 ;
struct V_140 * V_143 ;
struct V_292 * V_283 ;
struct V_320 * V_284 ;
struct V_1 * V_2 ;
struct V_316 V_9 ;
int V_330 = 0 ;
V_333 = F_143 ( V_7 -> V_459 , V_499 -> V_515 ) ;
if ( ! V_333 )
return - V_43 ;
V_143 = F_144 ( V_333 ) ;
if ( ! V_143 )
return - V_43 ;
V_283 = F_137 ( V_143 -> V_333 . V_459 ) ;
if ( ! V_283 )
return - V_43 ;
V_284 = V_283 -> V_284 ;
if ( ! V_284 )
return - V_43 ;
if ( ! ( V_7 -> V_481 . V_532 ) || ! ( V_7 -> V_482 . V_532 ) )
return - V_43 ;
F_7 ( V_14 , L_135
L_136 , V_143 -> V_146 . V_209 ,
F_36 ( V_283 -> V_385 ) ,
F_36 ( V_7 -> V_482 . V_519 . V_520 ) ,
F_16 ( V_7 -> V_482 . V_532 ) ,
F_36 ( V_7 -> V_481 . V_519 . V_520 ) ,
F_16 ( V_7 -> V_481 . V_532 ) ) ;
F_38 ( & V_553 ) ;
V_143 -> V_490 = 1 ;
V_143 -> V_7 = V_7 ;
V_7 -> V_485 = V_143 ;
V_143 -> V_379 = V_499 -> V_379 ;
V_143 -> V_167 -> V_168 |= F_31 ( ( T_3 ) V_499 -> V_540 ) ;
if ( V_499 -> V_540 == 0 )
V_143 -> V_167 -> V_168 |= F_31 ( 1 ) ;
F_7 ( V_14 , L_137 , ( T_3 ) V_499 -> V_540 ) ;
F_7 ( V_14 , L_138 ,
V_499 -> V_379 ) ;
if ( V_7 -> V_481 . V_519 . V_520 !=
V_7 -> V_482 . V_519 . V_520 ) {
F_70 ( V_283 , F_16 ( V_7 -> V_481 . V_532 ) ,
F_71 ( V_284 -> V_285 -> V_286 ) , V_554 ) ;
V_330 = 1 ;
}
V_9 . V_11 = F_23 ( V_7 -> V_481 . V_519 . V_520 ) ;
V_9 . V_13 = F_22 ( V_7 -> V_481 . V_532 ) ;
V_9 . V_10 = F_23 ( V_7 -> V_482 . V_519 . V_520 ) ;
V_9 . V_12 = F_22 ( V_7 -> V_482 . V_532 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_329 = V_555 ;
V_7 -> V_388 ( V_7 ) ;
V_2 = V_223 -> V_405 -> V_556 ( V_223 , V_283 ,
V_499 -> V_379 , ( void * ) V_499 -> V_380 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_330 )
F_70 ( V_283 , F_16 ( V_7 -> V_481 . V_532 ) ,
F_71 ( V_284 -> V_285 -> V_286 ) ,
V_287 ) ;
V_7 -> V_204 ( V_7 ) ;
return - V_27 ;
}
V_2 -> V_330 = V_330 ;
V_143 -> V_2 = V_2 ;
V_2 -> V_143 = V_143 ;
F_133 ( & V_143 -> V_333 ) ;
return 0 ;
}
int F_152 ( struct V_198 * V_7 , int V_361 )
{
struct V_292 * V_283 ;
struct V_261 * V_2 ;
struct V_316 V_9 ;
int V_272 ;
F_7 ( V_14 , L_139 ,
V_7 , F_16 ( V_7 -> V_481 . V_532 ) ) ;
V_283 = F_137 ( V_7 -> V_459 ) ;
if ( ! V_283 )
return - V_43 ;
F_7 ( V_14 , L_140 ,
V_283 , V_283 -> V_86 , V_283 -> V_86 -> V_516 ) ;
F_7 ( V_14 , L_141 ,
V_283 -> V_385 , V_7 -> V_481 . V_519 . V_520 ) ;
V_9 . V_11 = V_283 -> V_385 ;
V_9 . V_13 = V_7 -> V_481 . V_532 ;
V_9 . V_361 = V_361 ;
V_9 . V_7 = V_7 ;
V_9 . V_329 = V_555 ;
V_2 = V_223 -> V_405 -> V_557 ( V_223 , V_283 , & V_9 ) ;
if ( ! V_2 ) {
F_32 ( V_158 L_142 ,
V_159 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_485 = V_2 ;
if ( ! V_2 -> V_377 ) {
V_272 = F_70 ( V_283 ,
F_16 ( V_7 -> V_481 . V_532 ) ,
F_71 ( V_283 -> V_284 -> V_285 -> V_286 ) ,
V_554 ) ;
if ( V_272 ) {
F_32 ( V_158 L_143 ,
V_272 ) ;
V_223 -> V_405 -> V_558 ( V_223 , ( void * ) V_2 ) ;
return V_272 ;
}
F_38 ( & V_559 ) ;
}
V_7 -> V_388 ( V_7 ) ;
V_7 -> V_485 = ( void * ) V_2 ;
return 0 ;
}
int F_153 ( struct V_198 * V_7 )
{
if ( V_7 -> V_485 )
V_223 -> V_405 -> V_558 ( V_223 , V_7 -> V_485 ) ;
else
F_7 ( V_14 , L_144 ) ;
V_7 -> V_204 ( V_7 ) ;
return 0 ;
}
int F_154 ( struct V_15 * V_16 , struct V_300 * V_560 )
{
int V_299 = 0 ;
V_561 ++ ;
if ( ( V_223 ) && ( V_223 -> V_405 ) )
V_299 = V_223 -> V_405 -> V_562 ( V_223 , F_155 ( V_560 ) , V_16 ) ;
else
F_7 ( V_14 , L_145
L_146 ) ;
return V_299 ;
}
int F_156 ( void )
{
F_7 ( V_14 , L_103 ) ;
V_223 = F_122 () ;
if ( V_223 )
return 0 ;
else
return - V_27 ;
}
int F_157 ( void )
{
V_223 -> V_405 -> V_563 ( V_223 ) ;
return 0 ;
}
static void F_158 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_292 * V_283 ;
struct V_320 * V_284 ;
struct V_1 * V_2 ;
struct V_301 * V_302 ;
struct V_502 V_503 ;
struct V_198 * V_7 ;
struct V_446 V_447 ;
struct V_504 V_505 ;
T_3 V_506 ;
int V_136 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_147 , V_2 , V_7 ) ;
V_143 = (struct V_140 * ) V_7 -> V_485 ;
V_283 = F_137 ( V_143 -> V_333 . V_459 ) ;
V_284 = V_283 -> V_284 ;
V_302 = V_284 -> V_302 ;
if ( V_143 -> V_469 )
return;
F_38 ( & V_564 ) ;
F_7 ( V_14 , L_148
L_149 ,
V_143 -> V_146 . V_209 ,
F_36 ( V_7 -> V_482 . V_519 . V_520 ) ,
F_16 ( V_7 -> V_482 . V_532 ) ,
F_16 ( V_7 -> V_481 . V_532 ) ,
V_185 ) ;
F_131 ( V_143 , V_2 ) ;
V_143 -> V_167 -> V_531 [ 0 ] =
F_146 ( F_16 ( V_7 -> V_481 . V_532 ) ) ;
V_143 -> V_167 -> V_531 [ 1 ] =
F_146 ( F_16 ( V_7 -> V_482 . V_532 ) ) ;
V_143 -> V_167 -> V_533 =
F_31 ( F_36 ( V_7 -> V_482 . V_519 . V_520 ) ) ;
V_143 -> V_167 -> V_419 |= F_31 (
( T_3 ) F_71 ( V_284 -> V_285 -> V_286 ) <<
V_534 ) ;
V_143 -> V_167 -> V_535 |= F_31 (
F_82 ( V_284 ,
F_132 ( V_143 -> V_167 -> V_533 ) ,
NULL , V_315 ) << 16 ) ;
V_143 -> V_167 -> V_536 = F_31 (
V_185 - F_147 ( V_284 , V_537 ) ) ;
V_143 -> V_167 -> V_538 = F_31 ( V_143 -> V_146 . V_209 ) ;
V_143 -> V_167 -> V_168 |=
F_31 ( ( T_3 ) 1 <<
V_539 ) ;
F_29 ( V_2 , & V_143 ) ;
F_159 ( V_284 -> V_565 + V_566 ,
( 1 << 24 ) | 0x00800000 | V_143 -> V_146 . V_209 ) ;
memset ( & V_505 , 0 , sizeof( V_505 ) ) ;
V_505 . V_541 =
F_31 ( ( T_3 ) F_71 ( V_284 -> V_285 -> V_286 ) << 24 ) ;
V_505 . V_542 = V_7 -> V_482 . V_519 . V_520 ;
V_505 . V_543 [ 0 ] = V_7 -> V_482 . V_532 ;
V_505 . V_543 [ 1 ] = V_7 -> V_481 . V_532 ;
V_506 = F_148 ( & V_505 ) ;
V_143 -> V_544 = F_119 ( V_506 ^ 0xffffffff ) ;
F_7 ( V_14 , L_150 ,
V_143 -> V_544 , V_143 -> V_544 & V_302 -> V_545 ) ;
V_143 -> V_544 &= V_302 -> V_545 ;
V_143 -> V_167 -> V_544 = F_31 ( V_143 -> V_544 ) ;
V_143 -> V_491 = & V_2 -> V_25 ;
V_143 -> V_379 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_405 -> V_276 ( V_2 -> V_3 , V_2 ) ;
V_447 . V_6 = V_567 ;
V_447 . V_480 = 0 ;
V_447 . V_485 = V_7 -> V_485 ;
V_447 . V_481 . V_568 = V_569 ;
V_447 . V_481 . V_532 = V_7 -> V_481 . V_532 ;
V_447 . V_482 = V_7 -> V_482 ;
V_447 . V_380 = ( void * ) V_6 -> V_2 -> V_69 ;
V_447 . V_379 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_447 . V_570 = V_2 -> V_55 ;
V_447 . V_540 = V_2 -> V_56 ;
V_447 . V_481 . V_519 . V_520 = V_6 -> V_9 . V_10 ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
if ( V_136 )
F_32 ( V_158 L_133
L_134 , V_159 , __LINE__ , V_136 ) ;
V_503 . V_547 = V_464 ;
F_149 ( & V_143 -> V_333 , & V_503 , V_548 , NULL ) ;
F_7 ( V_14 , L_151
L_152 , V_143 -> V_146 . V_209 , V_185 ) ;
return;
}
static void F_66 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_198 * V_7 ;
struct V_446 V_447 ;
int V_136 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_153 , V_6 -> V_2 , V_7 ) ;
V_143 = V_7 -> V_485 ;
if ( ! V_143 )
return;
V_143 -> V_7 = NULL ;
V_7 -> V_485 = NULL ;
V_447 . V_6 = V_567 ;
V_447 . V_480 = - V_466 ;
V_447 . V_485 = V_7 -> V_485 ;
V_447 . V_481 = V_7 -> V_481 ;
V_447 . V_482 = V_7 -> V_482 ;
V_447 . V_380 = NULL ;
V_447 . V_379 = 0 ;
F_7 ( V_14 , L_154
L_155 , V_447 . V_481 . V_519 . V_520 ,
V_447 . V_482 . V_519 . V_520 ) ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
if ( V_136 )
F_32 ( V_158 L_133
L_134 , V_159 , __LINE__ , V_136 ) ;
V_7 -> V_204 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_160 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_198 * V_7 ;
struct V_446 V_447 ;
int V_136 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_156 , V_6 -> V_2 , V_7 ) ;
V_143 = V_7 -> V_485 ;
if ( ! V_143 )
return;
V_143 -> V_7 = NULL ;
V_447 . V_6 = V_479 ;
V_447 . V_480 = - V_466 ;
V_447 . V_485 = V_7 -> V_485 ;
V_447 . V_481 = V_7 -> V_481 ;
V_447 . V_482 = V_7 -> V_482 ;
V_447 . V_380 = NULL ;
V_447 . V_379 = 0 ;
V_7 -> V_388 ( V_7 ) ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
F_38 ( & V_484 ) ;
V_447 . V_6 = V_486 ;
V_447 . V_480 = 0 ;
V_447 . V_485 = V_7 -> V_485 ;
V_447 . V_481 = V_7 -> V_481 ;
V_447 . V_482 = V_7 -> V_482 ;
V_447 . V_380 = NULL ;
V_447 . V_379 = 0 ;
F_7 ( V_14 , L_157 , V_6 -> V_2 ) ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
V_7 -> V_204 ( V_7 ) ;
return;
}
static void F_161 ( struct V_4 * V_6 )
{
struct V_198 * V_7 ;
struct V_446 V_447 ;
int V_136 ;
struct V_1 * V_2 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_571 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_185 ) ;
V_447 . V_6 = V_572 ;
V_447 . V_480 = 0 ;
V_447 . V_485 = ( void * ) V_2 ;
V_447 . V_481 . V_568 = V_569 ;
V_447 . V_481 . V_532 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_447 . V_481 . V_519 . V_520 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_447 . V_482 . V_568 = V_569 ;
V_447 . V_482 . V_532 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_447 . V_482 . V_519 . V_520 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_447 . V_380 = V_2 -> V_69 ;
V_447 . V_379 = ( T_1 ) V_2 -> V_54 ;
V_447 . V_570 = V_2 -> V_55 ;
V_447 . V_540 = V_2 -> V_56 ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
if ( V_136 )
F_32 ( V_158 L_159 ,
V_159 , __LINE__ , V_136 ) ;
return;
}
static void F_116 ( struct V_4 * V_6 )
{
struct V_198 * V_7 ;
struct V_446 V_447 ;
struct V_1 * V_2 ;
int V_136 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_571 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_185 ) ;
V_447 . V_6 = V_567 ;
V_447 . V_480 = - V_573 ;
V_447 . V_485 = V_7 -> V_485 ;
V_447 . V_481 . V_568 = V_569 ;
V_447 . V_481 . V_532 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_447 . V_481 . V_519 . V_520 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_447 . V_482 . V_568 = V_569 ;
V_447 . V_482 . V_532 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_447 . V_482 . V_519 . V_520 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_447 . V_380 = V_2 -> V_69 ;
V_447 . V_379 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_160
L_155 ,
V_447 . V_481 . V_519 . V_520 ,
V_447 . V_482 . V_519 . V_520 ) ;
V_136 = V_7 -> V_476 ( V_7 , & V_447 ) ;
if ( V_136 )
F_32 ( V_158 L_159 ,
V_159 , __LINE__ , V_136 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_38 ( & V_6 -> V_2 -> V_3 -> V_404 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_388 ( V_6 -> V_9 . V_7 ) ;
F_134 ( & V_6 -> V_574 , V_575 ) ;
F_7 ( V_14 , L_161 ,
V_6 -> V_2 , V_6 ) ;
F_135 ( V_6 -> V_2 -> V_3 -> V_407 , & V_6 -> V_574 ) ;
F_7 ( V_14 , L_162 ) ;
return 0 ;
}
static void V_575 ( struct V_444 * V_442 )
{
struct V_4 * V_6 = F_52 ( V_442 , struct V_4 ,
V_574 ) ;
struct V_130 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_163 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_404 ) ) ;
switch ( V_6 -> type ) {
case V_356 :
F_161 ( V_6 ) ;
F_7 ( V_14 , L_164 ,
V_6 -> V_2 ) ;
break;
case V_576 :
F_7 ( V_14 , L_165 ,
V_6 -> V_2 ) ;
F_160 ( V_6 ) ;
break;
case V_359 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_229 ) )
break;
F_158 ( V_6 ) ;
F_7 ( V_14 , L_166 ) ;
break;
case V_358 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_229 ) )
break;
F_116 ( V_6 ) ;
F_7 ( V_14 , L_167 ) ;
break;
case V_205 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_229 ) )
break;
F_66 ( V_6 ) ;
F_7 ( V_14 , L_168 ) ;
break;
case V_577 :
F_7 ( V_14 , L_169 ) ;
break;
default:
F_7 ( V_14 , L_170 ) ;
break;
}
F_69 ( & V_3 -> V_404 ) ;
V_6 -> V_9 . V_7 -> V_204 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_35 ( V_6 ) ;
return;
}
