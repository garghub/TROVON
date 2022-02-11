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
V_16 -> V_86 = F_22 ( 0x800 ) ;
V_16 -> V_87 = 0 ;
V_16 -> V_88 = V_83 ;
memcpy ( V_80 -> V_89 , V_2 -> V_90 , V_91 ) ;
memcpy ( V_80 -> V_92 , V_2 -> V_93 , V_91 ) ;
V_80 -> V_94 = F_22 ( 0x0800 ) ;
V_78 -> V_95 = V_96 ;
V_78 -> V_97 = 5 ;
V_78 -> V_98 = 0 ;
V_78 -> V_99 = F_22 ( V_82 ) ;
V_78 -> V_100 = F_22 ( ++ V_2 -> V_101 . V_102 ) ;
V_78 -> V_103 = F_22 ( 0x4000 ) ;
V_78 -> V_104 = 0x40 ;
V_78 -> V_86 = 0x06 ;
V_78 -> V_105 = F_23 ( V_2 -> V_11 ) ;
V_78 -> V_106 = F_23 ( V_2 -> V_10 ) ;
V_76 -> V_107 = F_22 ( V_2 -> V_13 ) ;
V_76 -> V_108 = F_22 ( V_2 -> V_12 ) ;
V_76 -> V_109 = F_23 ( V_2 -> V_101 . V_110 ) ;
if ( V_29 & V_22 ) {
V_2 -> V_101 . V_111 = V_2 -> V_101 . V_112 ;
V_76 -> V_113 = F_23 ( V_2 -> V_101 . V_111 ) ;
V_76 -> V_114 = 1 ;
} else {
V_76 -> V_113 = 0 ;
}
if ( V_29 & V_115 ) {
V_2 -> V_101 . V_110 ++ ;
V_76 -> V_116 = 1 ;
} else {
V_2 -> V_101 . V_110 += V_74 ;
}
if ( V_29 & V_31 ) {
V_2 -> V_101 . V_110 ++ ;
V_76 -> V_117 = 1 ;
}
if ( V_29 & V_118 )
V_76 -> V_119 = 1 ;
V_76 -> V_120 = ( T_2 ) ( ( sizeof( * V_76 ) + V_72 + 3 ) >> 2 ) ;
V_76 -> V_121 = F_22 ( V_2 -> V_101 . V_122 ) ;
V_76 -> V_123 = 0 ;
if ( V_72 )
memcpy ( V_81 , V_71 , V_72 ) ;
V_81 += V_72 ;
if ( V_74 )
memcpy ( V_81 , V_73 , V_74 ) ;
F_24 ( V_16 ) -> V_124 = 0 ;
V_125 ++ ;
}
static void F_25 ( struct V_126 * V_127 )
{
F_7 ( V_14 , L_16 ) ;
F_7 ( V_14 , L_17 , V_127 ) ;
if ( ! V_127 )
return;
F_7 ( V_14 , L_16 ) ;
F_7 ( V_14 , L_18 , V_127 -> V_32 ) ;
F_7 ( V_14 , L_19 , F_26 ( & V_127 -> V_128 ) ) ;
F_7 ( V_14 , L_20 , F_26 ( & V_127 -> V_129 ) ) ;
F_7 ( V_14 , L_21 , V_127 ) ;
F_7 ( V_14 , L_22 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * * V_19 ,
T_2 * V_20 , T_1 * V_130 , T_1 V_131 )
{
int V_132 = 0 ;
* V_19 = ( V_130 ) ? V_130 : & V_2 -> V_69 [ 0 ] ;
switch ( V_2 -> V_48 ) {
case V_46 :
* V_19 = ( T_1 * ) * V_19 + sizeof( struct V_38 ) ;
* V_20 = sizeof( struct V_24 ) + V_2 -> V_54 ;
F_27 ( V_2 , * V_19 , V_131 ) ;
break;
case V_47 :
* V_20 = sizeof( struct V_36 ) + V_2 -> V_54 ;
F_28 ( V_2 , * V_19 , V_131 ) ;
break;
default:
V_132 = - V_43 ;
}
return V_132 ;
}
static void F_28 ( struct V_1 * V_2 ,
void * V_17 , T_1 V_131 )
{
struct V_36 * V_25 = (struct V_36 * ) V_17 ;
struct V_38 * V_39 = & V_25 -> V_39 ;
T_2 V_60 ;
T_2 V_61 ;
F_27 ( V_2 , V_17 , V_131 ) ;
V_25 -> V_29 |= V_133 ;
V_25 -> V_41 += F_22 ( V_59 ) ;
V_60 = ( V_2 -> V_55 > V_62 ) ?
V_62 : V_2 -> V_55 ;
V_61 = ( V_2 -> V_56 > V_62 ) ?
V_62 : V_2 -> V_56 ;
V_60 |= V_63 ;
V_60 |= V_134 ;
switch ( V_131 ) {
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
static void F_27 ( struct V_1 * V_2 , void * V_17 , T_1 V_131 )
{
struct V_24 * V_25 = (struct V_24 * ) V_17 ;
switch ( V_131 ) {
case V_21 :
memcpy ( V_25 -> V_50 , V_51 , V_52 ) ;
break;
case V_28 :
memcpy ( V_25 -> V_50 , V_53 , V_52 ) ;
break;
}
V_25 -> V_29 = V_135 ;
V_25 -> V_45 = V_2 -> V_48 ;
V_25 -> V_41 = F_22 ( V_2 -> V_54 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_136 * * V_137 )
{
T_4 V_138 ;
struct V_136 * V_139 = * V_137 ;
struct V_140 * V_141 = & V_139 -> V_142 . V_143 [ 0 ] ;
V_138 = ( unsigned long ) V_139 ;
V_138 |= V_144 >> 1 ;
F_30 ( V_141 -> V_145 , V_146 , V_138 ) ;
V_141 -> V_145 [ V_147 ] = 0 ;
V_141 -> V_145 [ V_148 ] = 0 ;
switch ( V_2 -> V_65 ) {
case V_68 :
F_7 ( V_14 , L_23 ) ;
V_141 -> V_145 [ V_149 ] =
F_31 ( V_150 ) ;
V_141 -> V_145 [ V_151 ] = 0 ;
V_141 -> V_145 [ V_152 ] = 0 ;
V_141 -> V_145 [ V_153 ] = 0 ;
break;
case V_66 :
default:
if ( V_2 -> V_65 != V_66 ) {
F_32 ( V_154 L_24 ,
V_155 , __LINE__ , V_2 -> V_65 ) ;
F_33 ( 1 ) ;
}
F_7 ( V_14 , L_25 ) ;
V_141 -> V_145 [ V_149 ] =
F_31 ( V_156 ) ;
V_141 -> V_145 [ V_157 ] = 1 ;
V_141 -> V_145 [ V_158 ] = 0 ;
V_141 -> V_145 [ V_159 ] = 0 ;
V_141 -> V_145 [ V_160 ] = 1 ;
V_141 -> V_145 [ V_153 ] = 1 ;
break;
}
if ( V_139 -> V_161 ) {
V_139 -> V_161 = 0 ;
F_34 ( V_139 -> V_162 ) ;
}
V_139 -> V_163 -> V_164 &= F_31 ( ~ ( V_165 |
V_166 |
V_167 ) ) ;
V_139 -> V_168 = 1 ;
V_139 -> V_142 . V_169 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_170 type , int V_171 ,
int V_172 )
{
unsigned long V_29 ;
struct V_126 * V_3 = V_2 -> V_3 ;
struct V_173 * V_174 ;
int V_132 = 0 ;
T_3 V_175 ;
V_174 = F_6 ( sizeof( * V_174 ) , V_8 ) ;
if ( ! V_174 )
return - V_27 ;
V_174 -> V_176 = V_177 ;
V_174 -> V_178 = V_179 ;
V_174 -> V_16 = V_16 ;
V_174 -> V_180 = V_181 ;
V_174 -> type = type ;
V_174 -> V_182 = V_2 -> V_182 ;
V_174 -> V_171 = V_171 ;
V_174 -> V_172 = V_172 ;
if ( type == V_183 ) {
V_174 -> V_180 += ( V_184 / 10 ) ;
if ( V_2 -> V_185 ) {
F_35 ( V_174 ) ;
F_33 ( 1 ) ;
return - V_43 ;
}
V_2 -> V_185 = V_174 ;
}
if ( type == V_23 ) {
V_174 -> V_186 = F_36 ( F_37 ( V_16 ) -> V_109 ) ;
F_38 ( & V_174 -> V_16 -> V_187 ) ;
F_39 ( & V_2 -> V_188 , V_29 ) ;
V_2 -> V_189 = V_174 ;
F_2 ( V_2 ) ;
F_40 ( & V_2 -> V_188 , V_29 ) ;
V_174 -> V_180 = V_181 + V_190 ;
V_132 = F_41 ( V_174 -> V_16 , V_2 -> V_182 ) ;
if ( V_132 != V_191 ) {
F_7 ( V_14 , L_26
L_27 , V_174 , V_181 ) ;
V_174 -> V_180 = V_181 ;
V_132 = V_191 ;
} else {
V_192 ++ ;
if ( ! V_171 ) {
F_42 ( V_2 ) ;
if ( V_172 )
F_4 ( V_3 , V_2 ) ;
return V_132 ;
}
}
}
V_175 = F_43 ( & V_3 -> V_193 ) ;
if ( ! V_175 ) {
V_3 -> V_193 . V_194 = V_174 -> V_180 ;
F_44 ( & V_3 -> V_193 ) ;
}
return V_132 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_195 * V_7 = V_2 -> V_7 ;
enum V_196 V_32 = V_2 -> V_32 ;
V_2 -> V_32 = V_197 ;
switch ( V_32 ) {
case V_198 :
case V_199 :
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_200 :
case V_33 :
if ( V_2 -> V_7 )
V_7 -> V_201 ( V_7 ) ;
F_46 ( V_2 , NULL ) ;
break;
default:
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
F_5 ( V_2 , V_202 ) ;
}
}
static void F_47 ( struct V_1 * V_2 , T_3 V_203 )
{
struct V_173 * V_185 = V_2 -> V_185 ;
struct V_195 * V_7 = V_2 -> V_7 ;
struct V_136 * V_139 ;
unsigned long V_204 ;
if ( ! V_185 )
return;
V_139 = (struct V_136 * ) V_185 -> V_16 ;
if ( V_139 ) {
F_39 ( & V_139 -> V_205 , V_204 ) ;
if ( V_139 -> V_7 ) {
F_7 ( V_14 , L_28
L_29
L_30
L_31 , V_139 -> V_142 . V_206 , V_7 ,
F_26 ( & V_139 -> V_207 ) ) ;
V_139 -> V_208 = V_209 ;
V_139 -> V_210 = V_211 ;
V_139 -> V_212 = V_213 ;
F_40 ( & V_139 -> V_205 , V_204 ) ;
F_48 ( V_139 ) ;
} else {
F_40 ( & V_139 -> V_205 , V_204 ) ;
F_7 ( V_14 , L_28
L_29
L_32
L_31 , V_139 -> V_142 . V_206 , V_7 ,
F_26 ( & V_139 -> V_207 ) ) ;
}
} else if ( V_203 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_2 -> V_7 )
V_7 -> V_201 ( V_7 ) ;
F_35 ( V_185 ) ;
V_2 -> V_185 = NULL ;
}
static void F_49 ( unsigned long V_214 )
{
unsigned long V_29 ;
unsigned long V_215 = V_181 + V_216 ;
struct V_1 * V_2 ;
struct V_173 * V_189 , * V_185 ;
struct V_217 * V_218 ;
struct V_217 * V_219 ;
struct V_126 * V_3 = V_220 ;
T_3 V_221 = 0 ;
unsigned long V_180 ;
int V_132 = V_191 ;
struct V_217 V_222 ;
F_50 ( & V_222 ) ;
F_39 ( & V_3 -> V_223 , V_29 ) ;
F_51 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_2 = F_52 ( V_219 , struct V_1 , V_224 ) ;
if ( ( V_2 -> V_185 ) || ( V_2 -> V_189 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_225 , & V_222 ) ;
}
}
F_40 ( & V_3 -> V_223 , V_29 ) ;
F_51 (list_node, list_core_temp, &timer_list) {
V_2 = F_52 ( V_219 , struct V_1 ,
V_225 ) ;
V_185 = V_2 -> V_185 ;
if ( V_185 ) {
if ( F_54 ( V_185 -> V_180 , V_181 ) ) {
if ( V_215 > V_185 -> V_180 ||
! V_221 ) {
V_215 = V_185 -> V_180 ;
V_221 = 1 ;
}
} else {
F_47 ( V_2 , 1 ) ;
}
}
F_39 ( & V_2 -> V_188 , V_29 ) ;
do {
V_189 = V_2 -> V_189 ;
if ( ! V_189 )
break;
if ( F_54 ( V_189 -> V_180 , V_181 ) ) {
if ( V_2 -> V_32 != V_226 ) {
if ( ( V_215 >
V_189 -> V_180 ) ||
! V_221 ) {
V_215 =
V_189 -> V_180 ;
V_221 = 1 ;
}
} else {
F_55 ( V_2 ) ;
}
break;
}
if ( ( V_2 -> V_32 == V_226 ) ||
( V_2 -> V_32 == V_197 ) ) {
F_55 ( V_2 ) ;
break;
}
if ( ! V_189 -> V_178 ||
! V_189 -> V_176 ) {
V_227 ++ ;
F_55 ( V_2 ) ;
F_40 (
& V_2 -> V_188 , V_29 ) ;
F_45 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
F_39 ( & V_2 -> V_188 ,
V_29 ) ;
break;
}
F_38 ( & V_189 -> V_16 -> V_187 ) ;
V_228 ++ ;
F_7 ( V_14 , L_33
L_34
L_35
L_36
L_37 , V_189 , V_2 , V_181 ,
V_189 -> V_180 ,
V_189 -> V_178 ,
V_189 -> V_186 ,
V_2 -> V_101 . V_229 ) ;
F_40 ( & V_2 -> V_188 ,
V_29 ) ;
V_132 = F_41 ( V_189 -> V_16 , V_2 -> V_182 ) ;
F_39 ( & V_2 -> V_188 , V_29 ) ;
if ( V_132 != V_191 ) {
F_7 ( V_14 , L_38
L_39 , V_2 ) ;
V_230 ++ ;
V_189 -> V_176 -- ;
V_215 = V_181 + V_231 ;
V_221 = 1 ;
break;
} else {
V_192 ++ ;
}
F_7 ( V_14 , L_40
L_41 ,
V_189 -> V_178 ,
V_189 -> V_176 ) ;
if ( V_189 -> V_171 ) {
V_189 -> V_178 -- ;
V_180 = ( V_190 <<
( V_179 - V_189 -> V_178 ) ) ;
V_189 -> V_180 = V_181 +
F_56 ( V_180 , V_232 ) ;
if ( V_215 > V_189 -> V_180 ||
! V_221 ) {
V_215 = V_189 -> V_180 ;
V_221 = 1 ;
}
} else {
int V_172 ;
V_172 =
V_189 -> V_172 ;
F_7 ( V_14 , L_42 ,
V_2 , V_2 -> V_32 ) ;
F_55 ( V_2 ) ;
if ( V_172 )
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
} while ( 0 );
F_40 ( & V_2 -> V_188 , V_29 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_221 ) {
if ( ! F_43 ( & V_3 -> V_193 ) ) {
V_3 -> V_193 . V_194 = V_215 ;
F_44 ( & V_3 -> V_193 ) ;
}
}
}
static int F_57 ( struct V_1 * V_2 , T_3 V_233 ,
struct V_15 * V_16 )
{
int V_132 ;
int V_29 = V_115 ;
char V_234 [ sizeof( struct V_235 ) +
sizeof( struct V_236 ) + sizeof( struct V_237 ) +
V_238 ] ;
int V_239 = 0 ;
union V_240 * V_71 ;
if ( ! V_2 )
return - V_43 ;
V_71 = (union V_240 * ) & V_234 [ V_239 ] ;
V_71 -> V_241 . V_242 = V_243 ;
V_71 -> V_241 . V_244 = sizeof( struct V_235 ) ;
V_71 -> V_241 . V_245 = F_22 ( V_2 -> V_101 . V_245 ) ;
V_239 += sizeof( struct V_235 ) ;
V_71 = (union V_240 * ) & V_234 [ V_239 ] ;
V_71 -> V_246 . V_242 = V_247 ;
V_71 -> V_246 . V_244 = sizeof( struct V_236 ) ;
V_71 -> V_246 . V_248 = V_2 -> V_101 . V_249 ;
V_239 += sizeof( struct V_236 ) ;
if ( V_233 && ! ( V_250 & V_251 ) ) {
V_71 = (union V_240 * ) & V_234 [ V_239 ] ;
V_71 -> V_252 . V_242 = V_253 ;
V_71 -> V_252 . V_244 = sizeof( struct V_237 ) ;
V_239 += sizeof( struct V_237 ) ;
V_71 = (union V_240 * ) & V_234 [ V_239 ] ;
V_71 -> V_254 = 1 ;
V_239 += 1 ;
V_71 = (union V_240 * ) & V_234 [ V_239 ] ;
V_71 -> V_254 = 1 ;
V_239 += 1 ;
}
V_71 = (union V_240 * ) & V_234 [ V_239 ] ;
V_71 -> V_254 = V_255 ;
V_239 += 1 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
if ( V_233 )
V_29 |= V_22 ;
F_11 ( V_16 , V_2 , V_234 , V_239 , NULL , 0 , V_29 ) ;
V_132 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_132 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_132 ;
int V_29 = V_118 | V_22 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - V_27 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_29 ) ;
V_132 = F_12 ( V_2 , V_16 , V_23 , 0 , 1 ) ;
return V_132 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_132 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 ) ;
V_132 = F_12 ( V_2 , V_16 , V_23 , 0 , 0 ) ;
return V_132 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_132 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 | V_31 ) ;
V_132 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_132 ;
}
static struct V_1 * F_60 ( struct V_126 * V_3 ,
T_2 V_12 , T_5 V_10 , T_2 V_13 , T_5 V_11 )
{
unsigned long V_29 ;
struct V_217 * V_256 ;
struct V_1 * V_2 ;
V_256 = & V_3 -> V_257 ;
F_39 ( & V_3 -> V_223 , V_29 ) ;
F_61 (cm_node, hte, list) {
F_7 ( V_14 , L_43 ,
V_2 -> V_11 , V_2 -> V_13 ,
V_11 , V_13 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_10 , V_12 ) ;
if ( ( V_2 -> V_11 == V_11 ) && ( V_2 -> V_13 == V_13 ) &&
( V_2 -> V_10 == V_10 ) && ( V_2 -> V_12 == V_12 ) ) {
F_2 ( V_2 ) ;
F_40 ( & V_3 -> V_223 , V_29 ) ;
return V_2 ;
}
}
F_40 ( & V_3 -> V_223 , V_29 ) ;
return NULL ;
}
static struct V_258 * F_62 ( struct V_126 * V_3 ,
T_5 V_259 , T_2 V_260 , enum V_261 V_262 )
{
unsigned long V_29 ;
struct V_258 * V_263 ;
F_39 ( & V_3 -> V_264 , V_29 ) ;
F_61 (listen_node, &cm_core->listen_list.list, list) {
if ( ( ( V_263 -> V_11 == V_259 ) ||
V_263 -> V_11 == 0x00000000 ) &&
( V_263 -> V_13 == V_260 ) &&
( V_262 & V_263 -> V_262 ) ) {
F_38 ( & V_263 -> V_265 ) ;
F_40 ( & V_3 -> V_264 , V_29 ) ;
return V_263 ;
}
}
F_40 ( & V_3 -> V_264 , V_29 ) ;
return NULL ;
}
static int F_63 ( struct V_126 * V_3 , struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_217 * V_256 ;
if ( ! V_2 || ! V_3 )
return - V_43 ;
F_7 ( V_14 , L_44 ,
V_2 ) ;
F_39 ( & V_3 -> V_223 , V_29 ) ;
V_256 = & V_3 -> V_257 ;
F_64 ( & V_2 -> V_224 , V_256 ) ;
F_38 ( & V_3 -> V_266 ) ;
F_40 ( & V_3 -> V_223 , V_29 ) ;
return 0 ;
}
static int F_65 ( struct V_126 * V_3 ,
struct V_258 * V_267 , int V_268 )
{
int V_132 = - V_43 ;
int V_269 = 0 ;
unsigned long V_29 ;
struct V_217 * V_270 = NULL ;
struct V_217 * V_271 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_217 V_272 ;
F_7 ( V_14 , L_45
L_46 , V_267 , V_268 ,
F_26 ( & V_267 -> V_265 ) ) ;
F_50 ( & V_272 ) ;
if ( V_268 ) {
F_39 ( & V_3 -> V_223 , V_29 ) ;
F_51 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_52 ( V_270 , struct V_1 ,
V_224 ) ;
if ( ( V_2 -> V_267 == V_267 ) &&
( ! V_2 -> V_273 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_274 , & V_272 ) ;
}
}
F_40 ( & V_3 -> V_223 , V_29 ) ;
}
F_51 (list_pos, list_temp, &reset_list) {
V_2 = F_52 ( V_270 , struct V_1 ,
V_274 ) ;
{
struct V_1 * V_275 = V_2 -> V_276 ;
enum V_196 V_277 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_275 ) {
F_42 ( V_2 ) ;
V_269 = F_46 ( V_2 , NULL ) ;
if ( V_269 ) {
V_2 -> V_32 =
V_197 ;
F_33 ( 1 ) ;
} else {
V_277 = V_2 -> V_32 ;
V_2 -> V_32 = V_278 ;
if ( V_277 != V_279 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_275 ;
V_6 . V_9 . V_10 =
V_275 -> V_10 ;
V_6 . V_9 . V_11 =
V_275 -> V_11 ;
V_6 . V_9 . V_12 =
V_275 -> V_12 ;
V_6 . V_9 . V_13 =
V_275 -> V_13 ;
V_6 . V_9 . V_7 = V_275 -> V_7 ;
F_2 ( V_275 ) ;
V_275 -> V_32 = V_197 ;
F_66 ( & V_6 ) ;
V_2 -> V_32 = V_278 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_39 ( & V_3 -> V_264 , V_29 ) ;
if ( ! F_67 ( & V_267 -> V_265 ) ) {
F_68 ( & V_267 -> V_224 ) ;
F_69 ( & V_3 -> V_128 ) ;
F_40 ( & V_3 -> V_264 , V_29 ) ;
if ( V_267 -> V_280 )
F_70 ( V_267 -> V_280 , V_267 -> V_13 ,
F_71 ( V_267 -> V_280 -> V_281 -> V_282 -> V_283 ) , V_284 ) ;
F_7 ( V_14 , L_47 , V_267 ) ;
F_35 ( V_267 ) ;
V_267 = NULL ;
V_132 = 0 ;
F_38 ( & V_285 ) ;
} else {
F_40 ( & V_3 -> V_264 , V_29 ) ;
}
if ( V_267 ) {
if ( F_26 ( & V_267 -> V_286 ) > 0 )
F_7 ( V_14 , L_48
L_49 ,
V_267 , F_26 ( & V_267 -> V_286 ) ) ;
}
return V_132 ;
}
static int F_72 ( struct V_126 * V_3 ,
struct V_258 * V_267 )
{
V_267 -> V_262 = V_287 ;
V_267 -> V_7 = NULL ;
return F_65 ( V_3 , V_267 , 1 ) ;
}
static inline int F_73 ( struct V_126 * V_3 ,
struct V_1 * V_2 )
{
T_3 V_175 ;
V_2 -> V_273 = 1 ;
if ( V_2 -> V_288 ) {
F_74 ( ! V_2 -> V_267 ) ;
F_69 ( & V_2 -> V_267 -> V_286 ) ;
V_2 -> V_288 = 0 ;
F_74 ( F_26 ( & V_2 -> V_267 -> V_286 ) < 0 ) ;
}
V_175 = F_43 ( & V_3 -> V_193 ) ;
if ( ! V_175 ) {
V_3 -> V_193 . V_194 = V_181 + V_231 ;
F_44 ( & V_3 -> V_193 ) ;
}
return 0 ;
}
static int F_75 ( struct V_289 * V_280 , T_3 V_290 , int V_291 )
{
struct V_292 * V_293 ;
struct V_294 * V_295 ;
int V_296 = V_291 ;
struct V_297 * V_182 ;
struct V_298 * V_299 = V_280 -> V_281 -> V_299 ;
V_293 = F_76 ( & V_300 , F_23 ( V_290 ) , 0 , 0 , 0 ) ;
if ( F_77 ( V_293 ) ) {
F_32 ( V_154 L_50 ,
V_155 , V_290 ) ;
return V_296 ;
}
if ( F_78 ( V_280 -> V_182 ) )
V_182 = V_280 -> V_182 -> V_301 ;
else
V_182 = V_280 -> V_182 ;
V_295 = F_79 ( & V_293 -> V_302 , & V_290 ) ;
F_80 () ;
if ( V_295 ) {
if ( V_295 -> V_303 & V_304 ) {
F_7 ( V_14 , L_51
L_52 , V_290 ,
V_295 -> V_305 , F_36 ( V_293 -> V_306 ) ) ;
if ( V_291 >= 0 ) {
if ( ! memcmp ( V_299 -> V_307 [ V_291 ] . V_308 ,
V_295 -> V_305 , V_91 ) ) {
goto V_309;
}
F_81 ( V_280 -> V_182 ,
V_299 -> V_307 [ V_291 ] . V_308 ,
V_290 , V_310 ) ;
}
F_81 ( V_280 -> V_182 , V_295 -> V_305 ,
V_290 , V_311 ) ;
V_296 = F_82 ( V_280 -> V_281 , V_290 , NULL ,
V_312 ) ;
} else {
F_83 ( V_295 , NULL ) ;
}
}
V_309:
F_84 () ;
if ( V_295 )
F_85 ( V_295 ) ;
F_86 ( V_293 ) ;
return V_296 ;
}
static struct V_1 * F_87 ( struct V_126 * V_3 ,
struct V_289 * V_280 , struct V_313 * V_9 ,
struct V_258 * V_267 )
{
struct V_1 * V_2 ;
struct V_314 V_315 ;
int V_316 = 0 ;
int V_291 = 0 ;
struct V_317 * V_281 ;
struct V_298 * V_299 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_48 = V_318 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_55 = V_62 ;
V_2 -> V_56 = V_62 ;
F_7 ( V_14 , L_53 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_267 = V_267 ;
V_2 -> V_182 = V_280 -> V_182 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_93 , V_280 -> V_182 -> V_319 , V_91 ) ;
F_7 ( V_14 , L_54 , V_2 -> V_267 ,
V_2 -> V_7 ) ;
F_88 ( & V_2 -> V_188 ) ;
V_2 -> V_276 = NULL ;
F_89 ( & V_2 -> V_265 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_101 . V_102 = V_320 ;
V_2 -> V_101 . V_249 = V_321 ;
V_2 -> V_101 . V_122 = V_322 >>
V_321 ;
V_315 = F_90 () ;
V_2 -> V_101 . V_110 = F_23 ( V_315 . V_323 ) ;
V_2 -> V_101 . V_245 = V_280 -> V_324 - sizeof( struct V_77 ) -
sizeof( struct V_75 ) - V_83 - V_325 ;
V_2 -> V_101 . V_112 = 0 ;
F_38 ( & V_3 -> V_129 ) ;
V_2 -> V_326 = V_9 -> V_326 ;
V_2 -> V_327 = 0 ;
V_2 -> V_288 = 0 ;
V_2 -> V_280 = V_280 ;
V_281 = V_280 -> V_281 ;
V_299 = V_281 -> V_299 ;
V_2 -> V_276 = NULL ;
if ( F_91 ( F_23 ( V_2 -> V_10 ) ) ) {
V_291 = F_82 ( V_281 , F_36 ( V_280 -> V_328 ) , NULL , V_312 ) ;
} else {
V_316 = F_82 ( V_281 , V_2 -> V_10 , NULL , V_312 ) ;
V_291 = F_75 ( V_280 , V_9 -> V_10 , V_316 ) ;
}
if ( V_291 < 0 ) {
F_35 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_90 , V_299 -> V_307 [ V_291 ] . V_308 , V_91 ) ;
F_7 ( V_14 , L_55 ,
V_2 -> V_90 ) ;
F_63 ( V_3 , V_2 ) ;
F_38 ( & V_329 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_265 ) ;
return 0 ;
}
static int F_4 ( struct V_126 * V_3 ,
struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_136 * V_139 ;
if ( ! V_2 )
return - V_43 ;
F_39 ( & V_2 -> V_3 -> V_223 , V_29 ) ;
if ( F_67 ( & V_2 -> V_265 ) ) {
F_40 ( & V_2 -> V_3 -> V_223 , V_29 ) ;
return 0 ;
}
F_68 ( & V_2 -> V_224 ) ;
F_69 ( & V_3 -> V_266 ) ;
F_40 ( & V_2 -> V_3 -> V_223 , V_29 ) ;
if ( ! V_2 -> V_273 && V_2 -> V_288 ) {
F_74 ( ! V_2 -> V_267 ) ;
F_69 ( & V_2 -> V_267 -> V_286 ) ;
F_74 ( F_26 ( & V_2 -> V_267 -> V_286 ) < 0 ) ;
}
F_33 ( V_2 -> V_189 ) ;
if ( V_2 -> V_185 )
F_47 ( V_2 , 0 ) ;
if ( V_2 -> V_267 ) {
F_65 ( V_3 , V_2 -> V_267 , 0 ) ;
} else {
if ( V_2 -> V_327 && V_2 -> V_280 ) {
F_70 ( V_2 -> V_280 , V_2 -> V_13 ,
F_71 (
V_2 -> V_280 -> V_281 -> V_282 -> V_283 ) ,
V_284 ) ;
}
}
F_69 ( & V_3 -> V_129 ) ;
F_38 ( & V_330 ) ;
V_139 = V_2 -> V_139 ;
if ( V_139 ) {
V_139 -> V_2 = NULL ;
F_92 ( & V_139 -> V_331 ) ;
V_2 -> V_139 = NULL ;
}
F_35 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , T_1 * V_332 ,
T_3 V_72 , T_3 V_333 )
{
T_3 V_334 ;
T_3 V_335 = 0 ;
union V_240 * V_336 ;
char V_337 = 0 ;
while ( V_335 < V_72 ) {
V_336 = (union V_240 * ) ( V_332 + V_335 ) ;
switch ( V_336 -> V_252 . V_242 ) {
case V_255 :
V_335 = V_72 ;
break;
case V_338 :
V_335 += 1 ;
continue;
case V_243 :
F_7 ( V_14 , L_56
L_57 , V_155 ,
V_336 -> V_241 . V_244 , V_335 , V_72 ) ;
V_337 = 1 ;
if ( V_336 -> V_241 . V_244 != 4 ) {
return 1 ;
} else {
V_334 = F_16 ( V_336 -> V_241 . V_245 ) ;
if ( V_334 > 0 && V_334 <
V_2 -> V_101 . V_245 )
V_2 -> V_101 . V_245 = V_334 ;
}
break;
case V_247 :
V_2 -> V_101 . V_339 =
V_336 -> V_246 . V_248 ;
break;
default:
F_7 ( V_14 , L_58 ,
V_336 -> V_252 . V_242 ) ;
break;
}
V_335 += V_336 -> V_252 . V_244 ;
}
if ( ( ! V_337 ) && ( V_333 ) )
V_2 -> V_101 . V_245 = V_340 ;
return 0 ;
}
static void F_94 ( struct V_15 * V_16 )
{
F_38 ( & V_341 ) ;
F_95 ( V_16 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_59
L_46 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_265 ) ) ;
switch ( V_2 -> V_32 ) {
case V_198 :
case V_342 :
case V_343 :
case V_344 :
V_2 -> V_101 . V_112 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_200 ;
F_59 ( V_2 , NULL ) ;
break;
case V_49 :
F_5 ( V_2 , V_202 ) ;
V_2 -> V_101 . V_112 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_33 :
V_2 -> V_101 . V_112 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_199 ;
F_58 ( V_2 , NULL ) ;
break;
case V_345 :
V_2 -> V_101 . V_112 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_346 ;
F_58 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_183 , 1 , 0 ) ;
break;
case V_346 :
V_2 -> V_101 . V_112 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_226 :
default:
F_7 ( V_14 , L_60 ,
V_2 , V_2 -> V_32 ) ;
break;
}
}
static void F_97 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_347 = 0 ;
F_38 ( & V_348 ) ;
F_7 ( V_14 , L_61
L_62 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_265 ) ) ;
F_42 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_342 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_155 , __LINE__ , V_2 ,
V_2 -> V_267 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_342 ;
if ( F_57 ( V_2 , 0 , NULL ) ) {
F_98 ( V_2 , V_16 , V_347 ) ;
}
break;
case V_46 :
default:
F_98 ( V_2 , V_16 , V_347 ) ;
break;
}
break;
case V_279 :
F_38 ( & V_2 -> V_349 ) ;
F_95 ( V_16 ) ;
break;
case V_343 :
case V_198 :
case V_350 :
F_7 ( V_14 , L_65 , V_155 , __LINE__ ) ;
F_99 ( V_2 , V_16 , V_347 ) ;
break;
case V_226 :
F_98 ( V_2 , V_16 , V_347 ) ;
break;
case V_197 :
F_94 ( V_16 ) ;
break;
case V_345 :
case V_33 :
case V_200 :
V_2 -> V_7 -> V_201 ( V_2 -> V_7 ) ;
case V_346 :
V_2 -> V_32 = V_197 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_94 ( V_16 ) ;
break;
default:
F_94 ( V_16 ) ;
break;
}
}
static void F_100 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_132 = 0 ;
int V_74 = V_16 -> V_35 ;
T_1 * V_351 = V_16 -> V_73 ;
enum V_5 type = V_352 ;
T_3 V_353 ;
V_132 = F_15 ( V_2 , V_351 , & V_353 , V_74 ) ;
if ( V_132 ) {
F_7 ( V_14 , L_66 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_67
L_68 , V_155 ,
__LINE__ , V_2 , V_2 -> V_267 ,
V_2 -> V_32 ) ;
F_98 ( V_2 , V_16 , 1 ) ;
} else {
F_99 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_343 :
if ( V_353 == V_70 )
F_33 ( 1 ) ;
V_2 -> V_32 = V_279 ;
type = V_354 ;
F_89 ( & V_2 -> V_349 ,
V_355 ) ;
break;
case V_49 :
F_42 ( V_2 ) ;
if ( V_353 == V_70 ) {
type = V_356 ;
V_2 -> V_32 = V_344 ;
} else {
type = V_357 ;
V_2 -> V_32 = V_226 ;
}
break;
default:
F_33 ( 1 ) ;
break;
}
F_95 ( V_16 ) ;
F_5 ( V_2 , type ) ;
}
static void F_101 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_2 -> V_32 ) {
case V_342 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_155 , __LINE__ , V_2 ,
V_2 -> V_267 , V_2 -> V_32 ) ;
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_343 :
case V_198 :
F_99 ( V_2 , V_16 , 1 ) ;
break;
case V_226 :
default:
F_94 ( V_16 ) ;
}
}
static int F_102 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 )
{
int V_269 ;
V_269 = ( ( F_36 ( V_76 -> V_113 ) == V_2 -> V_101 . V_110 ) ) ? 0 : 1 ;
if ( V_269 )
F_98 ( V_2 , V_16 , 1 ) ;
return V_269 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 )
{
int V_269 = 0 ;
T_3 V_109 ;
T_3 V_113 ;
T_3 V_110 = V_2 -> V_101 . V_110 ;
T_3 V_112 = V_2 -> V_101 . V_112 ;
T_3 V_122 ;
V_109 = F_36 ( V_76 -> V_109 ) ;
V_113 = F_36 ( V_76 -> V_113 ) ;
V_122 = V_2 -> V_101 . V_122 ;
if ( V_113 != V_110 )
V_269 = 1 ;
else if ( ! F_104 ( V_109 , V_112 , ( V_112 + V_122 ) ) )
V_269 = 1 ;
if ( V_269 ) {
F_7 ( V_14 , L_63
L_64 , V_155 , __LINE__ , V_2 ,
V_2 -> V_267 , V_2 -> V_32 ) ;
F_101 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_69
L_70 , V_2 , V_109 , V_112 ,
V_122 ) ;
}
return V_269 ;
}
static void F_105 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_132 ;
T_3 V_358 ;
int V_72 ;
V_72 = ( V_76 -> V_120 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_358 = F_36 ( V_76 -> V_109 ) ;
switch ( V_2 -> V_32 ) {
case V_342 :
case V_49 :
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_350 :
if ( F_26 ( & V_2 -> V_267 -> V_286 ) >
V_2 -> V_267 -> V_359 ) {
F_7 ( V_14 , L_71
L_72 ) ;
V_360 ++ ;
F_99 ( V_2 , V_16 , 0 ) ;
break;
}
V_132 = F_106 ( V_2 , V_76 , V_16 , V_72 ,
1 ) ;
if ( V_132 ) {
F_99 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_101 . V_112 = V_358 + 1 ;
F_74 ( V_2 -> V_189 ) ;
V_2 -> V_288 = 1 ;
F_38 ( & V_2 -> V_267 -> V_286 ) ;
V_2 -> V_32 = V_198 ;
F_57 ( V_2 , 1 , V_16 ) ;
break;
case V_197 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_226 :
case V_343 :
case V_33 :
case V_345 :
case V_279 :
case V_200 :
case V_199 :
case V_361 :
default:
F_94 ( V_16 ) ;
break;
}
}
static void F_107 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_132 ;
T_3 V_358 ;
int V_72 ;
V_72 = ( V_76 -> V_120 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_358 = F_36 ( V_76 -> V_109 ) ;
switch ( V_2 -> V_32 ) {
case V_342 :
F_42 ( V_2 ) ;
if ( F_102 ( V_2 , V_76 , V_16 ) )
return;
V_2 -> V_101 . V_229 = F_36 ( V_76 -> V_113 ) ;
V_132 = F_106 ( V_2 , V_76 , V_16 , V_72 , 0 ) ;
if ( V_132 ) {
F_7 ( V_14 , L_73 ,
V_2 ) ;
break;
}
F_42 ( V_2 ) ;
V_2 -> V_101 . V_112 = V_358 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_279 :
F_99 ( V_2 , V_16 , 1 ) ;
break;
case V_350 :
V_2 -> V_101 . V_110 = F_36 ( V_76 -> V_113 ) ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_197 :
V_2 -> V_101 . V_110 = F_36 ( V_76 -> V_113 ) ;
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_343 :
case V_33 :
case V_345 :
case V_200 :
case V_226 :
case V_199 :
case V_361 :
case V_49 :
default:
F_94 ( V_16 ) ;
break;
}
}
static int F_108 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_74 = 0 ;
T_3 V_358 ;
int V_132 = 0 ;
int V_72 ;
V_72 = ( V_76 -> V_120 << 2 ) - sizeof( struct V_75 ) ;
if ( F_103 ( V_2 , V_76 , V_16 ) )
return - V_43 ;
F_109 ( V_16 , V_76 -> V_120 << 2 ) ;
V_358 = F_36 ( V_76 -> V_109 ) ;
V_74 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_198 :
F_42 ( V_2 ) ;
V_132 = F_106 ( V_2 , V_76 , V_16 , V_72 , 1 ) ;
if ( V_132 )
break;
V_2 -> V_101 . V_229 = F_36 ( V_76 -> V_113 ) ;
V_2 -> V_32 = V_343 ;
if ( V_74 ) {
V_2 -> V_101 . V_112 = V_358 + V_74 ;
F_100 ( V_2 , V_16 ) ;
} else {
F_95 ( V_16 ) ;
}
break;
case V_343 :
F_42 ( V_2 ) ;
if ( V_74 ) {
V_2 -> V_101 . V_112 = V_358 + V_74 ;
F_100 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_101 . V_229 = F_36 ( V_76 -> V_113 ) ;
if ( V_74 ) {
V_2 -> V_101 . V_112 = V_358 + V_74 ;
F_100 ( V_2 , V_16 ) ;
} else {
F_95 ( V_16 ) ;
}
break;
case V_350 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_197 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_200 :
case V_199 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
V_2 -> V_7 -> V_201 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_94 ( V_16 ) ;
break;
case V_33 :
F_42 ( V_2 ) ;
F_94 ( V_16 ) ;
V_2 -> V_32 = V_345 ;
break;
case V_342 :
case V_345 :
case V_226 :
case V_279 :
case V_361 :
default:
F_42 ( V_2 ) ;
F_94 ( V_16 ) ;
break;
}
return V_132 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 , int V_72 , int V_362 )
{
T_1 * V_332 = ( T_1 * ) & V_76 [ 1 ] ;
if ( V_72 ) {
if ( F_93 ( V_2 , V_332 , V_72 ,
( T_3 ) V_76 -> V_116 ) ) {
F_7 ( V_14 , L_74 ,
V_155 , V_2 ) ;
if ( V_362 )
F_99 ( V_2 , V_16 , 1 ) ;
else
F_98 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_101 . V_363 = F_16 ( V_76 -> V_121 ) <<
V_2 -> V_101 . V_339 ;
if ( V_2 -> V_101 . V_363 > V_2 -> V_101 . V_364 )
V_2 -> V_101 . V_364 = V_2 -> V_101 . V_363 ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_347 )
{
F_42 ( V_2 ) ;
if ( V_347 ) {
F_7 ( V_14 , L_75
L_76 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
} else {
F_95 ( V_16 ) ;
}
V_2 -> V_32 = V_197 ;
F_5 ( V_2 , V_202 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_347 )
{
F_42 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
if ( V_347 ) {
F_7 ( V_14 , L_77
L_78 , V_2 , V_2 -> V_32 ) ;
F_46 ( V_2 , V_16 ) ;
} else {
F_95 ( V_16 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_173 * V_189 ;
V_189 = V_2 -> V_189 ;
if ( V_189 ) {
V_2 -> V_189 = NULL ;
F_95 ( V_189 -> V_16 ) ;
F_35 ( V_189 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_39 ( & V_2 -> V_188 , V_29 ) ;
F_55 ( V_2 ) ;
F_40 ( & V_2 -> V_188 , V_29 ) ;
}
static void F_110 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_126 * V_3 )
{
enum V_365 V_366 = V_367 ;
struct V_75 * V_76 = F_37 ( V_16 ) ;
T_3 V_368 = 0 ;
int V_132 = 0 ;
F_109 ( V_16 , F_111 ( V_16 ) -> V_97 << 2 ) ;
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 , V_76 -> V_116 ,
V_76 -> V_114 , V_76 -> V_119 , V_76 -> V_117 ) ;
if ( V_76 -> V_119 ) {
V_366 = V_369 ;
} else if ( V_76 -> V_116 ) {
V_366 = V_370 ;
if ( V_76 -> V_114 )
V_366 = V_371 ;
} else if ( V_76 -> V_114 ) {
V_366 = V_372 ;
}
if ( V_76 -> V_117 )
V_368 = 1 ;
switch ( V_366 ) {
case V_370 :
F_105 ( V_2 , V_16 , V_76 ) ;
break;
case V_371 :
F_107 ( V_2 , V_16 , V_76 ) ;
break;
case V_372 :
V_132 = F_108 ( V_2 , V_16 , V_76 ) ;
if ( V_368 && ! V_132 )
F_96 ( V_2 ) ;
break;
case V_369 :
F_97 ( V_2 , V_16 , V_76 ) ;
break;
default:
if ( ( V_368 ) && ( ! F_103 ( V_2 , V_76 , V_16 ) ) )
F_96 ( V_2 ) ;
F_94 ( V_16 ) ;
break;
}
}
static struct V_258 * F_112 ( struct V_126 * V_3 ,
struct V_289 * V_280 , struct V_313 * V_9 )
{
struct V_258 * V_267 ;
unsigned long V_29 ;
F_7 ( V_14 , L_81 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_267 = F_62 ( V_3 , F_23 ( V_9 -> V_11 ) ,
F_22 ( V_9 -> V_13 ) , V_373 ) ;
if ( V_267 && V_267 -> V_262 == V_374 ) {
F_69 ( & V_267 -> V_265 ) ;
F_7 ( V_14 , L_82 ) ;
return NULL ;
}
if ( ! V_267 ) {
V_267 = F_6 ( sizeof( * V_267 ) , V_8 ) ;
if ( ! V_267 ) {
F_7 ( V_14 , L_83 ) ;
return NULL ;
}
V_267 -> V_11 = F_23 ( V_9 -> V_11 ) ;
V_267 -> V_13 = F_22 ( V_9 -> V_13 ) ;
V_267 -> V_375 = 0 ;
F_89 ( & V_267 -> V_265 , 1 ) ;
}
else {
V_267 -> V_375 = 1 ;
}
V_267 -> V_7 = V_9 -> V_7 ;
F_89 ( & V_267 -> V_286 , 0 ) ;
V_267 -> V_3 = V_3 ;
V_267 -> V_280 = V_280 ;
F_38 ( & V_3 -> V_129 ) ;
V_267 -> V_326 = V_9 -> V_326 ;
V_267 -> V_359 = V_9 -> V_359 ;
V_267 -> V_262 = V_374 ;
if ( ! V_267 -> V_375 ) {
F_39 ( & V_3 -> V_264 , V_29 ) ;
F_53 ( & V_267 -> V_224 , & V_3 -> V_376 . V_224 ) ;
F_40 ( & V_3 -> V_264 , V_29 ) ;
F_38 ( & V_3 -> V_128 ) ;
}
F_7 ( V_14 , L_84
L_85 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_267 , V_267 -> V_359 , V_267 -> V_7 ) ;
return V_267 ;
}
static struct V_1 * F_113 ( struct V_126 * V_3 ,
struct V_289 * V_280 , T_2 V_377 ,
void * V_378 , struct V_313 * V_9 )
{
int V_132 = 0 ;
struct V_1 * V_2 ;
struct V_258 * V_379 ;
struct V_1 * V_380 ;
struct V_313 V_381 ;
T_1 * V_19 ;
V_2 = F_87 ( V_3 , V_280 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_101 . V_382 = 1 ;
V_2 -> V_101 . V_249 = V_321 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_379 = F_62 ( V_3 ,
F_36 ( V_280 -> V_328 ) , V_2 -> V_12 ,
V_374 ) ;
if ( V_379 == NULL ) {
F_5 ( V_2 , V_202 ) ;
} else {
V_381 = * V_9 ;
V_381 . V_13 = V_9 -> V_12 ;
V_381 . V_12 = V_9 -> V_13 ;
V_381 . V_7 = V_379 -> V_7 ;
V_380 = F_87 ( V_3 , V_280 ,
& V_381 , V_379 ) ;
if ( ! V_380 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_38 ( & V_383 ) ;
V_380 -> V_276 = V_2 ;
V_380 -> V_101 . V_249 =
V_321 ;
V_2 -> V_276 = V_380 ;
memcpy ( V_380 -> V_69 , V_378 ,
V_377 ) ;
V_380 -> V_54 = V_377 ;
V_2 -> V_32 = V_226 ;
V_2 -> V_101 . V_112 =
V_380 -> V_101 . V_110 ;
V_380 -> V_101 . V_112 =
V_2 -> V_101 . V_110 ;
V_2 -> V_101 . V_364 =
V_380 -> V_101 . V_122 ;
V_380 -> V_101 . V_364 =
V_2 -> V_101 . V_122 ;
V_2 -> V_101 . V_363 =
V_380 -> V_101 . V_122 ;
V_380 -> V_101 . V_363 =
V_2 -> V_101 . V_122 ;
V_2 -> V_101 . V_339 =
V_380 -> V_101 . V_249 ;
V_380 -> V_101 . V_339 =
V_2 -> V_101 . V_249 ;
V_380 -> V_32 = V_279 ;
F_5 ( V_380 , V_354 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_377 ;
memcpy ( V_19 , V_378 , V_377 ) ;
V_2 -> V_32 = V_342 ;
V_132 = F_57 ( V_2 , 0 , NULL ) ;
if ( V_132 ) {
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
static int F_114 ( struct V_126 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_115 ( struct V_126 * V_3 , struct V_1 * V_2 )
{
int V_132 = 0 ;
int V_269 = 0 ;
int V_349 ;
struct V_4 V_6 ;
struct V_195 * V_7 = V_2 -> V_7 ;
struct V_1 * V_275 = V_2 -> V_276 ;
F_7 ( V_14 , L_90 ,
V_155 , V_2 , V_2 -> V_101 . V_382 , V_2 -> V_32 ) ;
if ( V_2 -> V_101 . V_382 )
return V_132 ;
F_42 ( V_2 ) ;
if ( ! V_275 ) {
V_349 = F_116 ( 1 , & V_2 -> V_349 ) ;
if ( V_349 == V_384 ) {
V_2 -> V_32 = V_197 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_278 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_132 = F_13 ( V_2 ) ;
if ( V_132 ) {
V_2 -> V_32 = V_197 ;
V_269 = F_46 ( V_2 , NULL ) ;
if ( V_269 )
F_33 ( 1 ) ;
} else {
V_7 -> V_385 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_278 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_275 ) ;
} else {
V_6 . V_2 = V_275 ;
V_6 . V_9 . V_10 = V_275 -> V_10 ;
V_6 . V_9 . V_11 = V_275 -> V_11 ;
V_6 . V_9 . V_12 = V_275 -> V_12 ;
V_6 . V_9 . V_13 = V_275 -> V_13 ;
V_6 . V_9 . V_7 = V_275 -> V_7 ;
F_117 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_275 -> V_32 = V_199 ;
V_7 = V_275 -> V_7 ;
F_4 ( V_3 , V_275 ) ;
V_7 -> V_201 ( V_7 ) ;
}
}
return V_132 ;
}
static int F_118 ( struct V_126 * V_3 , struct V_1 * V_2 )
{
int V_132 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_198 :
case V_342 :
case V_386 :
case V_343 :
case V_387 :
case V_49 :
case V_279 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_388 :
V_2 -> V_32 = V_200 ;
F_59 ( V_2 , NULL ) ;
break;
case V_33 :
case V_345 :
case V_200 :
case V_346 :
case V_199 :
V_132 = - 1 ;
break;
case V_350 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_344 :
case V_361 :
case V_389 :
case V_197 :
case V_278 :
V_132 = F_4 ( V_3 , V_2 ) ;
break;
case V_226 :
if ( V_2 -> V_189 )
F_32 ( V_154 L_91
L_92 , V_2 -> V_189 ) ;
V_132 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_132 ;
}
static int F_119 ( struct V_126 * V_3 ,
struct V_289 * V_280 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_258 * V_267 = NULL ;
struct V_77 * V_78 ;
struct V_75 * V_76 ;
struct V_313 V_390 ;
int V_391 = 1 ;
T_6 V_392 , V_393 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_77 ) + sizeof( struct V_75 ) )
return 0 ;
V_78 = (struct V_77 * ) V_16 -> V_73 ;
V_76 = (struct V_75 * ) ( V_16 -> V_73 + sizeof( struct V_77 ) ) ;
V_390 . V_11 = F_36 ( V_78 -> V_106 ) ;
V_390 . V_13 = F_16 ( V_76 -> V_108 ) ;
V_390 . V_10 = F_36 ( V_78 -> V_105 ) ;
V_390 . V_12 = F_16 ( V_76 -> V_107 ) ;
V_392 = F_120 ( V_78 -> V_106 ) ;
V_393 = F_120 ( V_78 -> V_105 ) ;
F_7 ( V_14 , L_93 ,
& V_392 , V_76 -> V_108 , & V_393 , V_76 -> V_107 ) ;
do {
V_2 = F_60 ( V_3 ,
V_390 . V_12 , V_390 . V_10 ,
V_390 . V_13 , V_390 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_76 -> V_116 ) || ( V_76 -> V_114 ) ) {
V_391 = 0 ;
break;
}
V_267 = F_62 ( V_3 , V_390 . V_11 ,
V_390 . V_13 ,
V_374 ) ;
if ( ! V_267 ) {
V_390 . V_7 = NULL ;
V_390 . V_326 = 0 ;
F_7 ( V_14 , L_94 ) ;
V_391 = 0 ;
break;
}
V_390 . V_7 = V_267 -> V_7 ;
V_390 . V_326 = V_267 -> V_326 ;
V_2 = F_87 ( V_3 , V_280 , & V_390 ,
V_267 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_95
L_96 ) ;
V_227 ++ ;
F_69 ( & V_267 -> V_265 ) ;
F_95 ( V_16 ) ;
break;
}
if ( ! V_76 -> V_119 && ! V_76 -> V_117 ) {
V_2 -> V_32 = V_350 ;
} else {
V_227 ++ ;
F_4 ( V_3 , V_2 ) ;
F_95 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_226 ) {
if ( V_2 -> V_139 -> V_394 )
F_121 ( V_16 , V_280 , V_2 -> V_139 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_38 ( & V_341 ) ;
F_95 ( V_16 ) ;
}
break;
}
F_122 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_76 ) ) ;
V_16 -> V_35 = F_16 ( V_78 -> V_99 ) ;
F_110 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_391 ;
}
static struct V_126 * F_123 ( void )
{
struct V_126 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_395 ) ;
if ( ! V_3 )
return NULL ;
F_50 ( & V_3 -> V_257 ) ;
F_124 ( & V_3 -> V_193 ) ;
V_3 -> V_193 . V_396 = F_49 ;
V_3 -> V_397 = V_398 ;
V_3 -> V_32 = V_389 ;
V_3 -> V_399 = V_400 ;
F_89 ( & V_3 -> V_401 , 0 ) ;
V_3 -> V_402 = & V_403 ;
F_88 ( & V_3 -> V_223 ) ;
F_88 ( & V_3 -> V_264 ) ;
F_50 ( & V_3 -> V_376 . V_224 ) ;
F_7 ( V_14 , L_97 , V_3 ) ;
F_7 ( V_14 , L_98 ) ;
V_3 -> V_404 = F_125 ( L_99 ) ;
V_3 -> V_405 = F_8 ;
F_7 ( V_14 , L_100 ) ;
V_3 -> V_406 = F_125 ( L_101 ) ;
F_25 ( V_3 ) ;
return V_3 ;
}
static int F_126 ( struct V_126 * V_3 )
{
F_7 ( V_14 , L_102 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_127 () ;
if ( F_43 ( & V_3 -> V_193 ) )
F_128 ( & V_3 -> V_193 ) ;
F_129 ( V_3 -> V_404 ) ;
F_129 ( V_3 -> V_406 ) ;
F_7 ( V_14 , L_103 ) ;
F_35 ( V_3 ) ;
return 0 ;
}
static int F_130 ( struct V_126 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_131 ( struct V_126 * V_3 , T_3 type , T_3 V_407 )
{
int V_132 = 0 ;
switch ( type ) {
case V_408 :
V_3 -> V_397 = V_407 ;
break;
case V_409 :
V_3 -> V_399 = V_407 ;
break;
default:
V_132 = - V_43 ;
}
return V_132 ;
}
static int F_132 ( struct V_136 * V_139 , struct V_1 * V_2 )
{
int V_132 = 0 ;
if ( ! V_139 )
return - V_43 ;
V_139 -> V_163 -> V_410 |= F_31 ( V_411 |
V_412 | V_413 |
V_414 ) ;
if ( V_2 -> V_101 . V_339 || V_2 -> V_101 . V_249 )
V_139 -> V_163 -> V_410 |= F_31 ( V_415 ) ;
V_139 -> V_163 -> V_416 |= F_31 ( 64 << V_417 ) ;
V_139 -> V_163 -> V_245 |= F_31 ( ( ( T_3 ) V_2 -> V_101 . V_245 ) << 16 ) ;
V_139 -> V_163 -> V_418 |= F_31 (
( T_3 ) V_419 << V_420 ) ;
V_139 -> V_163 -> V_421 |= F_31 (
( V_2 -> V_101 . V_339 << V_422 ) &
V_423 ) ;
V_139 -> V_163 -> V_421 |= F_31 (
( V_2 -> V_101 . V_249 << V_424 ) &
V_425 ) ;
V_139 -> V_163 -> V_426 = F_31 ( 0x80 ) ;
V_139 -> V_163 -> V_427 = 0 ;
V_139 -> V_163 -> V_428 = 0 ;
V_139 -> V_163 -> V_429 = F_31 ( V_2 -> V_101 . V_110 ) ;
V_139 -> V_163 -> V_363 = F_31 ( V_2 -> V_101 . V_363 ) ;
V_139 -> V_163 -> V_112 = F_31 ( V_2 -> V_101 . V_112 ) ;
V_139 -> V_163 -> V_122 = F_31 ( V_2 -> V_101 . V_122 <<
V_2 -> V_101 . V_249 ) ;
V_139 -> V_163 -> V_430 = F_31 ( V_2 -> V_101 . V_110 ) ;
V_139 -> V_163 -> V_431 = F_31 ( V_2 -> V_101 . V_110 ) ;
V_139 -> V_163 -> V_432 = 0 ;
V_139 -> V_163 -> V_433 = F_31 ( 0x6 ) ;
V_139 -> V_163 -> V_434 = F_31 ( 0x3FFFC000 ) ;
V_139 -> V_163 -> V_435 = F_31 ( 2 * V_2 -> V_101 . V_245 ) ;
V_139 -> V_163 -> V_436 = F_31 ( V_2 -> V_101 . V_112 ) ;
V_139 -> V_163 -> V_437 = F_31 ( V_2 -> V_101 . V_110 ) ;
V_139 -> V_163 -> V_364 = F_31 ( V_2 -> V_101 . V_364 ) ;
F_7 ( V_14 , L_104
L_105 ,
V_139 -> V_142 . V_206 , F_133 ( V_139 -> V_163 -> V_112 ) ,
F_133 ( V_139 -> V_163 -> V_429 ) ,
V_2 -> V_101 . V_245 , F_133 ( V_139 -> V_163 -> V_421 ) ,
F_133 ( V_139 -> V_163 -> V_122 ) ,
F_133 ( V_139 -> V_163 -> V_410 ) ) ;
F_7 ( V_14 , L_106 , F_133 ( V_139 -> V_163 -> V_363 ) ) ;
F_7 ( V_14 , L_107 , F_133 ( V_139 -> V_163 -> V_435 ) ) ;
F_7 ( V_14 , L_108 , F_133 ( V_139 -> V_163 -> V_364 ) ) ;
F_7 ( V_14 , L_109 ) ;
V_2 -> V_32 = V_226 ;
return V_132 ;
}
int F_48 ( struct V_136 * V_139 )
{
struct V_438 * V_439 ;
V_439 = F_6 ( sizeof *V_439 , V_8 ) ;
if ( ! V_439 )
return - V_27 ;
F_134 ( & V_139 -> V_331 ) ;
V_439 -> V_139 = V_139 ;
F_135 ( & V_439 -> V_439 , V_440 ) ;
F_136 ( V_220 -> V_406 , & V_439 -> V_439 ) ;
return 0 ;
}
static void V_440 ( struct V_441 * V_439 )
{
struct V_438 * V_442 = F_52 ( V_439 , struct V_438 , V_439 ) ;
struct V_136 * V_139 = V_442 -> V_139 ;
F_35 ( V_442 ) ;
F_7 ( V_14 , L_110 ,
V_139 -> V_210 , V_139 -> V_142 . V_206 ) ;
F_137 ( V_139 ) ;
F_92 ( & V_139 -> V_331 ) ;
}
static int F_137 ( struct V_136 * V_139 )
{
unsigned long V_29 ;
int V_132 = 0 ;
struct V_195 * V_7 ;
struct V_443 V_444 ;
struct V_289 * V_280 ;
T_2 V_445 ;
T_1 V_446 ;
T_1 V_447 ;
int V_448 = 0 ;
int V_449 = 0 ;
int V_450 = 0 ;
int V_451 = 0 ;
T_3 V_452 = V_453 ;
struct V_454 V_455 ;
if ( ! V_139 ) {
F_7 ( V_14 , L_111 ) ;
return - 1 ;
}
F_39 ( & V_139 -> V_205 , V_29 ) ;
V_7 = V_139 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_112 ,
V_139 -> V_142 . V_206 ) ;
F_40 ( & V_139 -> V_205 , V_29 ) ;
return - 1 ;
}
V_280 = F_138 ( V_139 -> V_331 . V_456 ) ;
F_7 ( V_14 , L_113 , V_139 -> V_142 . V_206 ) ;
V_446 = V_139 -> V_208 ;
V_447 = V_139 -> V_212 ;
V_445 = V_139 -> V_210 ;
if ( V_139 -> V_457 ) {
V_449 = 1 ;
V_450 = 1 ;
V_139 -> V_7 = NULL ;
F_128 ( & V_139 -> V_458 ) ;
if ( V_139 -> V_459 == 0 ) {
V_139 -> V_459 = 1 ;
V_451 = 1 ;
}
} else if ( ( V_446 == V_460 ) ||
( ( V_447 == V_461 ) &&
( V_445 == V_462 ) ) ) {
V_449 = 1 ;
if ( V_445 == V_462 )
V_448 = - V_463 ;
}
if ( ( ( V_446 == V_209 ) ||
( V_446 == V_464 ) ||
( V_445 == V_465 ) ||
( V_445 == V_462 ) ) ) {
V_450 = 1 ;
V_139 -> V_7 = NULL ;
if ( V_139 -> V_459 == 0 ) {
V_139 -> V_459 = 1 ;
V_451 = 1 ;
}
}
F_40 ( & V_139 -> V_205 , V_29 ) ;
if ( ( V_451 ) && ( V_139 -> V_466 == 0 ) ) {
if ( V_139 -> V_467 >= V_468 )
V_452 |= V_469 ;
F_139 ( V_280 -> V_281 , V_139 , V_452 , 1 ) ;
if ( V_139 -> V_457 ) {
V_455 . V_456 = V_139 -> V_331 . V_456 ;
V_455 . V_6 = V_139 -> V_470 ;
V_455 . V_471 . V_472 = & V_139 -> V_331 ;
V_139 -> V_331 . V_473 ( & V_455 , V_139 -> V_331 . V_474 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_473 ) ) {
if ( V_449 ) {
F_38 ( & V_475 ) ;
V_444 . V_6 = V_476 ;
V_444 . V_477 = V_448 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_378 = NULL ;
V_444 . V_377 = 0 ;
F_7 ( V_14 , L_114
L_115
L_116 ,
V_139 -> V_142 . V_206 , V_139 -> V_142 . V_480 ,
V_139 -> V_142 . V_169 , V_7 ,
F_26 ( & V_139 -> V_207 ) ) ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_132 )
F_7 ( V_14 , L_117
L_118 , V_132 ) ;
}
if ( V_450 ) {
F_38 ( & V_481 ) ;
F_140 ( V_139 , 1 ) ;
V_7 -> V_482 = V_139 ;
V_444 . V_6 = V_483 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_378 = NULL ;
V_444 . V_377 = 0 ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_132 )
F_7 ( V_14 , L_119 , V_132 ) ;
V_7 -> V_201 ( V_7 ) ;
}
}
return 0 ;
}
static int F_140 ( struct V_136 * V_139 , int V_484 )
{
int V_132 = 0 ;
struct V_289 * V_280 ;
struct V_317 * V_281 ;
struct V_485 * V_486 ;
V_280 = F_138 ( V_139 -> V_331 . V_456 ) ;
if ( ! V_280 )
return - V_43 ;
V_281 = V_280 -> V_281 ;
V_486 = V_280 -> V_486 ;
F_7 ( V_14 , L_120 ,
F_141 ( V_280 -> V_182 ) ) ;
if ( V_139 -> V_487 ) {
V_139 -> V_487 = 0 ;
} else {
if ( V_139 -> V_488 ) {
if ( V_139 -> V_489 )
V_486 -> V_490 . V_491 ( V_139 -> V_489 ) ;
F_142 ( V_281 -> V_282 ,
V_139 -> V_377 + V_139 -> V_492 ,
V_139 -> V_488 , V_139 -> V_493 ) ;
}
}
if ( V_139 -> V_2 ) {
F_7 ( V_14 , L_121 ) ;
V_220 -> V_402 -> V_494 ( V_220 , V_139 -> V_2 ) ;
}
return V_132 ;
}
int F_143 ( struct V_195 * V_7 , struct V_495 * V_496 )
{
T_4 V_138 ;
struct V_497 * V_331 ;
struct V_136 * V_139 ;
struct V_289 * V_280 ;
struct V_317 * V_281 ;
struct V_1 * V_2 ;
struct V_298 * V_498 ;
struct V_499 V_500 ;
struct V_443 V_444 ;
struct V_140 * V_141 ;
struct V_501 V_502 ;
T_3 V_503 ;
int V_132 ;
int V_349 ;
struct V_485 * V_486 ;
struct V_504 * V_505 = NULL ;
struct V_506 V_507 ;
struct V_508 * V_509 ;
T_4 V_510 ;
T_1 V_511 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
V_331 = F_144 ( V_7 -> V_456 , V_496 -> V_512 ) ;
if ( ! V_331 )
return - V_43 ;
V_139 = F_145 ( V_331 ) ;
V_280 = F_138 ( V_139 -> V_331 . V_456 ) ;
V_281 = V_280 -> V_281 ;
V_498 = V_281 -> V_299 ;
V_2 = (struct V_1 * ) V_7 -> V_482 ;
F_7 ( V_14 , L_122
L_123 , V_2 , V_280 , V_280 -> V_182 ,
V_280 -> V_182 -> V_513 ) ;
if ( V_278 == V_2 -> V_32 ) {
if ( V_2 -> V_276 )
F_4 ( V_2 -> V_3 , V_2 -> V_276 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_349 = F_116 ( 1 , & V_2 -> V_349 ) ;
if ( V_349 == V_384 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_463 ;
}
V_139 -> V_2 = ( void * ) V_2 ;
V_2 -> V_139 = V_139 ;
F_7 ( V_14 , L_124 ,
V_139 -> V_142 . V_206 , V_2 , V_181 , V_2 -> V_267 ) ;
F_38 ( & V_514 ) ;
F_7 ( V_14 , L_120 ,
F_141 ( V_280 -> V_182 ) ) ;
V_139 -> V_492 = sizeof( struct V_36 ) ;
V_139 -> V_488 = F_146 ( V_281 -> V_282 ,
V_139 -> V_492 + V_496 -> V_377 ,
& V_139 -> V_493 ) ;
if ( ! V_139 -> V_488 ) {
F_7 ( V_14 , L_125 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_139 -> V_488 ;
if ( V_2 -> V_48 == V_46 )
V_511 = 4 ;
memcpy ( V_37 -> V_515 , V_496 -> V_378 ,
V_496 -> V_377 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_139 -> V_488 , V_28 ) ;
V_139 -> V_377 = V_496 -> V_377 ;
V_141 = & V_139 -> V_142 . V_143 [ 0 ] ;
if ( V_7 -> V_479 . V_516 . V_517 !=
V_7 -> V_478 . V_516 . V_517 ) {
V_138 = ( unsigned long ) V_139 ;
V_486 = V_280 -> V_486 ;
V_509 = V_139 -> V_509 ;
V_507 . V_518 = V_139 -> V_493 + V_511 ;
V_507 . V_519 = V_20 ;
V_510 = ( T_4 ) ( unsigned long ) * V_19 ;
V_505 = V_486 -> V_490 . V_520 ( (struct V_521 * ) V_509 ,
& V_507 , 1 ,
V_522 ,
& V_510 ) ;
if ( ! V_505 ) {
F_7 ( V_14 , L_126
L_127 ,
V_2 ) ;
F_142 ( V_281 -> V_282 ,
V_139 -> V_377 + V_139 -> V_492 ,
V_139 -> V_488 , V_139 -> V_493 ) ;
return - V_27 ;
}
V_505 -> V_523 = & V_509 -> V_524 ;
V_505 -> V_456 = V_509 -> V_524 . V_456 ;
V_139 -> V_489 = V_505 ;
V_138 |= V_144 >> 1 ;
F_30 ( V_141 -> V_145 ,
V_146 ,
V_138 ) ;
V_141 -> V_145 [ V_149 ] =
F_31 ( V_525 |
V_526 ) ;
V_141 -> V_145 [ V_151 ] =
F_31 ( V_20 ) ;
F_30 ( V_141 -> V_145 ,
V_147 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_141 -> V_145 [ V_152 ] =
F_31 ( V_20 ) ;
V_141 -> V_145 [ V_153 ] = V_505 -> V_527 ;
if ( V_139 -> V_161 ) {
V_139 -> V_161 = 0 ;
F_34 ( V_139 -> V_162 ) ;
}
V_139 -> V_163 -> V_164 |=
F_31 ( V_165 |
V_166 ) ;
} else {
V_139 -> V_163 -> V_164 |=
F_31 ( V_166 ) ;
}
V_139 -> V_168 = 1 ;
V_139 -> V_7 = V_7 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_482 = V_139 ;
V_139 -> V_487 = 0 ;
if ( V_2 -> V_32 == V_226 )
F_7 ( V_14 , L_128 ,
V_2 ) ;
F_132 ( V_139 , V_2 ) ;
V_139 -> V_163 -> V_528 [ 0 ] =
F_147 ( F_16 ( V_7 -> V_478 . V_529 ) ) ;
V_139 -> V_163 -> V_528 [ 1 ] =
F_147 ( F_16 ( V_7 -> V_479 . V_529 ) ) ;
if ( F_91 ( V_7 -> V_479 . V_516 . V_517 ) )
V_139 -> V_163 -> V_530 =
F_31 ( F_36 ( V_280 -> V_328 ) ) ;
else
V_139 -> V_163 -> V_530 =
F_31 ( F_36 ( V_7 -> V_479 . V_516 . V_517 ) ) ;
V_139 -> V_163 -> V_416 |= F_31 (
( T_3 ) F_71 ( V_281 -> V_282 -> V_283 ) <<
V_531 ) ;
V_139 -> V_163 -> V_532 |=
F_31 ( F_82 ( V_281 ,
F_133 ( V_139 -> V_163 -> V_530 ) , NULL ,
V_312 ) << 16 ) ;
V_139 -> V_163 -> V_533 = F_31 (
V_181 - F_148 ( V_281 , V_534 ) ) ;
V_139 -> V_163 -> V_535 = F_31 ( V_139 -> V_142 . V_206 ) ;
V_139 -> V_163 -> V_164 |= F_31 (
( ( T_3 ) 1 << V_536 ) ) ;
V_139 -> V_163 -> V_164 |=
F_31 ( ( T_3 ) V_496 -> V_537 ) ;
memset ( & V_502 , 0 , sizeof( V_502 ) ) ;
V_502 . V_538 =
F_31 ( ( T_3 ) F_71 ( V_281 -> V_282 -> V_283 ) << 24 ) ;
if ( F_91 ( V_7 -> V_479 . V_516 . V_517 ) )
V_502 . V_539 = V_280 -> V_328 ;
else
V_502 . V_539 = V_7 -> V_479 . V_516 . V_517 ;
V_502 . V_540 [ 0 ] = V_7 -> V_479 . V_529 ;
V_502 . V_540 [ 1 ] = V_7 -> V_478 . V_529 ;
V_503 = F_149 ( & V_502 ) ;
V_139 -> V_541 = F_120 ( V_503 ^ 0xffffffff ) ;
F_7 ( V_14 , L_129 ,
V_139 -> V_541 , V_139 -> V_541 & V_498 -> V_542 ) ;
V_139 -> V_541 &= V_498 -> V_542 ;
V_139 -> V_163 -> V_541 = F_31 ( V_139 -> V_541 ) ;
V_2 -> V_3 -> V_402 -> V_273 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_130
L_131
L_132 , V_139 -> V_142 . V_206 ,
F_36 ( V_7 -> V_479 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_479 . V_529 ) ,
F_36 ( V_7 -> V_478 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_478 . V_529 ) ,
F_133 ( V_139 -> V_163 -> V_112 ) ,
F_133 ( V_139 -> V_163 -> V_429 ) ,
V_20 ) ;
V_7 -> V_385 ( V_7 ) ;
F_134 ( & V_139 -> V_331 ) ;
V_444 . V_6 = V_543 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = ( void * ) V_139 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_378 = NULL ;
V_444 . V_377 = 0 ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
V_500 . V_544 = V_461 ;
F_150 ( & V_139 -> V_331 , & V_500 , V_545 , NULL ) ;
if ( V_2 -> V_276 ) {
V_2 -> V_276 -> V_54 =
V_139 -> V_377 ;
memcpy ( V_2 -> V_276 -> V_69 ,
V_496 -> V_378 , V_496 -> V_377 ) ;
F_5 ( V_2 -> V_276 , V_357 ) ;
}
if ( V_132 )
F_32 ( V_154 L_133
L_134 , V_155 , __LINE__ , V_132 ) ;
return 0 ;
}
int F_151 ( struct V_195 * V_7 , const void * V_546 , T_1 V_547 )
{
struct V_1 * V_2 ;
struct V_1 * V_275 ;
struct V_126 * V_3 ;
T_1 * V_19 ;
F_38 ( & V_548 ) ;
V_2 = (struct V_1 * ) V_7 -> V_482 ;
V_275 = V_2 -> V_276 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_547 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_275 ) {
memcpy ( & V_275 -> V_25 . V_515 , V_546 , V_547 ) ;
V_275 -> V_25 . V_41 = V_547 ;
V_275 -> V_54 = V_547 ;
} else {
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_547 ;
memcpy ( V_19 , V_546 , V_547 ) ;
}
return V_3 -> V_402 -> V_549 ( V_3 , V_2 ) ;
}
int F_152 ( struct V_195 * V_7 , struct V_495 * V_496 )
{
struct V_497 * V_331 ;
struct V_136 * V_139 ;
struct V_289 * V_280 ;
struct V_317 * V_281 ;
struct V_1 * V_2 ;
struct V_313 V_9 ;
int V_327 = 0 ;
V_331 = F_144 ( V_7 -> V_456 , V_496 -> V_512 ) ;
if ( ! V_331 )
return - V_43 ;
V_139 = F_145 ( V_331 ) ;
if ( ! V_139 )
return - V_43 ;
V_280 = F_138 ( V_139 -> V_331 . V_456 ) ;
if ( ! V_280 )
return - V_43 ;
V_281 = V_280 -> V_281 ;
if ( ! V_281 )
return - V_43 ;
if ( ! ( V_7 -> V_478 . V_529 ) || ! ( V_7 -> V_479 . V_529 ) )
return - V_43 ;
F_7 ( V_14 , L_135
L_136 , V_139 -> V_142 . V_206 ,
F_36 ( V_280 -> V_328 ) ,
F_36 ( V_7 -> V_479 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_479 . V_529 ) ,
F_36 ( V_7 -> V_478 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_478 . V_529 ) ) ;
F_38 ( & V_550 ) ;
V_139 -> V_487 = 1 ;
V_139 -> V_7 = V_7 ;
V_7 -> V_482 = V_139 ;
V_139 -> V_377 = V_496 -> V_377 ;
V_139 -> V_163 -> V_164 |= F_31 ( ( T_3 ) V_496 -> V_537 ) ;
F_7 ( V_14 , L_137 , ( T_3 ) V_496 -> V_537 ) ;
F_7 ( V_14 , L_138 ,
V_496 -> V_377 ) ;
if ( V_7 -> V_478 . V_516 . V_517 !=
V_7 -> V_479 . V_516 . V_517 ) {
F_70 ( V_280 , F_16 ( V_7 -> V_478 . V_529 ) ,
F_71 ( V_281 -> V_282 -> V_283 ) , V_551 ) ;
V_327 = 1 ;
}
V_9 . V_11 = F_23 ( V_7 -> V_478 . V_516 . V_517 ) ;
V_9 . V_13 = F_22 ( V_7 -> V_478 . V_529 ) ;
V_9 . V_10 = F_23 ( V_7 -> V_479 . V_516 . V_517 ) ;
V_9 . V_12 = F_22 ( V_7 -> V_479 . V_529 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_326 = V_552 ;
V_7 -> V_385 ( V_7 ) ;
V_2 = V_220 -> V_402 -> V_553 ( V_220 , V_280 ,
V_496 -> V_377 , ( void * ) V_496 -> V_378 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_327 )
F_70 ( V_280 , F_16 ( V_7 -> V_478 . V_529 ) ,
F_71 ( V_281 -> V_282 -> V_283 ) ,
V_284 ) ;
V_7 -> V_201 ( V_7 ) ;
return - V_27 ;
}
V_2 -> V_327 = V_327 ;
V_139 -> V_2 = V_2 ;
V_2 -> V_139 = V_139 ;
F_134 ( & V_139 -> V_331 ) ;
return 0 ;
}
int F_153 ( struct V_195 * V_7 , int V_359 )
{
struct V_289 * V_280 ;
struct V_258 * V_2 ;
struct V_313 V_9 ;
int V_269 ;
F_7 ( V_14 , L_139 ,
V_7 , F_16 ( V_7 -> V_478 . V_529 ) ) ;
V_280 = F_138 ( V_7 -> V_456 ) ;
if ( ! V_280 )
return - V_43 ;
F_7 ( V_14 , L_140 ,
V_280 , V_280 -> V_182 , V_280 -> V_182 -> V_513 ) ;
F_7 ( V_14 , L_141 ,
V_280 -> V_328 , V_7 -> V_478 . V_516 . V_517 ) ;
V_9 . V_11 = V_280 -> V_328 ;
V_9 . V_13 = V_7 -> V_478 . V_529 ;
V_9 . V_359 = V_359 ;
V_9 . V_7 = V_7 ;
V_9 . V_326 = V_552 ;
V_2 = V_220 -> V_402 -> V_554 ( V_220 , V_280 , & V_9 ) ;
if ( ! V_2 ) {
F_32 ( V_154 L_142 ,
V_155 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_482 = V_2 ;
if ( ! V_2 -> V_375 ) {
V_269 = F_70 ( V_280 ,
F_16 ( V_7 -> V_478 . V_529 ) ,
F_71 ( V_280 -> V_281 -> V_282 -> V_283 ) ,
V_551 ) ;
if ( V_269 ) {
F_32 ( V_154 L_143 ,
V_269 ) ;
V_220 -> V_402 -> V_555 ( V_220 , ( void * ) V_2 ) ;
return V_269 ;
}
F_38 ( & V_556 ) ;
}
V_7 -> V_385 ( V_7 ) ;
V_7 -> V_482 = ( void * ) V_2 ;
return 0 ;
}
int F_154 ( struct V_195 * V_7 )
{
if ( V_7 -> V_482 )
V_220 -> V_402 -> V_555 ( V_220 , V_7 -> V_482 ) ;
else
F_7 ( V_14 , L_144 ) ;
V_7 -> V_201 ( V_7 ) ;
return 0 ;
}
int F_155 ( struct V_15 * V_16 , struct V_297 * V_557 )
{
int V_296 = 0 ;
V_558 ++ ;
if ( ( V_220 ) && ( V_220 -> V_402 ) )
V_296 = V_220 -> V_402 -> V_559 ( V_220 , F_156 ( V_557 ) , V_16 ) ;
else
F_7 ( V_14 , L_145
L_146 ) ;
return V_296 ;
}
int F_157 ( void )
{
F_7 ( V_14 , L_103 ) ;
V_220 = F_123 () ;
if ( V_220 )
return 0 ;
else
return - V_27 ;
}
int F_158 ( void )
{
V_220 -> V_402 -> V_560 ( V_220 ) ;
return 0 ;
}
static void F_159 ( struct V_4 * V_6 )
{
struct V_136 * V_139 ;
struct V_289 * V_280 ;
struct V_317 * V_281 ;
struct V_1 * V_2 ;
struct V_298 * V_299 ;
struct V_499 V_500 ;
struct V_195 * V_7 ;
struct V_443 V_444 ;
struct V_501 V_502 ;
T_3 V_503 ;
int V_132 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_147 , V_2 , V_7 ) ;
V_139 = (struct V_136 * ) V_7 -> V_482 ;
V_280 = F_138 ( V_139 -> V_331 . V_456 ) ;
V_281 = V_280 -> V_281 ;
V_299 = V_281 -> V_299 ;
if ( V_139 -> V_466 )
return;
F_38 ( & V_561 ) ;
F_7 ( V_14 , L_148
L_149 ,
V_139 -> V_142 . V_206 ,
F_36 ( V_7 -> V_479 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_479 . V_529 ) ,
F_16 ( V_7 -> V_478 . V_529 ) ,
V_181 ) ;
F_132 ( V_139 , V_2 ) ;
V_139 -> V_163 -> V_528 [ 0 ] =
F_147 ( F_16 ( V_7 -> V_478 . V_529 ) ) ;
V_139 -> V_163 -> V_528 [ 1 ] =
F_147 ( F_16 ( V_7 -> V_479 . V_529 ) ) ;
if ( F_91 ( V_7 -> V_479 . V_516 . V_517 ) )
V_139 -> V_163 -> V_530 =
F_31 ( F_36 ( V_280 -> V_328 ) ) ;
else
V_139 -> V_163 -> V_530 =
F_31 ( F_36 ( V_7 -> V_479 . V_516 . V_517 ) ) ;
V_139 -> V_163 -> V_416 |= F_31 (
( T_3 ) F_71 ( V_281 -> V_282 -> V_283 ) <<
V_531 ) ;
V_139 -> V_163 -> V_532 |= F_31 (
F_82 ( V_281 ,
F_133 ( V_139 -> V_163 -> V_530 ) ,
NULL , V_312 ) << 16 ) ;
V_139 -> V_163 -> V_533 = F_31 (
V_181 - F_148 ( V_281 , V_534 ) ) ;
V_139 -> V_163 -> V_535 = F_31 ( V_139 -> V_142 . V_206 ) ;
V_139 -> V_163 -> V_164 |=
F_31 ( ( T_3 ) 1 <<
V_536 ) ;
F_29 ( V_2 , & V_139 ) ;
F_160 ( V_281 -> V_562 + V_563 ,
( 1 << 24 ) | 0x00800000 | V_139 -> V_142 . V_206 ) ;
memset ( & V_502 , 0 , sizeof( V_502 ) ) ;
V_502 . V_538 =
F_31 ( ( T_3 ) F_71 ( V_281 -> V_282 -> V_283 ) << 24 ) ;
if ( F_91 ( V_7 -> V_479 . V_516 . V_517 ) )
V_502 . V_539 = V_280 -> V_328 ;
else
V_502 . V_539 = V_7 -> V_479 . V_516 . V_517 ;
V_502 . V_540 [ 0 ] = V_7 -> V_479 . V_529 ;
V_502 . V_540 [ 1 ] = V_7 -> V_478 . V_529 ;
V_503 = F_149 ( & V_502 ) ;
V_139 -> V_541 = F_120 ( V_503 ^ 0xffffffff ) ;
F_7 ( V_14 , L_150 ,
V_139 -> V_541 , V_139 -> V_541 & V_299 -> V_542 ) ;
V_139 -> V_541 &= V_299 -> V_542 ;
V_139 -> V_163 -> V_541 = F_31 ( V_139 -> V_541 ) ;
V_139 -> V_488 = & V_2 -> V_25 ;
V_139 -> V_377 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_402 -> V_273 ( V_2 -> V_3 , V_2 ) ;
V_444 . V_6 = V_564 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 . V_565 = V_566 ;
V_444 . V_478 . V_529 = V_7 -> V_478 . V_529 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_378 = ( void * ) V_6 -> V_2 -> V_69 ;
V_444 . V_377 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_444 . V_567 = V_2 -> V_55 ;
V_444 . V_537 = V_2 -> V_56 ;
V_444 . V_478 . V_516 . V_517 = V_6 -> V_9 . V_10 ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_7 ( V_14 , L_119 , V_132 ) ;
if ( V_132 )
F_32 ( V_154 L_133
L_134 , V_155 , __LINE__ , V_132 ) ;
V_500 . V_544 = V_461 ;
F_150 ( & V_139 -> V_331 , & V_500 , V_545 , NULL ) ;
F_7 ( V_14 , L_151
L_152 , V_139 -> V_142 . V_206 , V_181 ) ;
return;
}
static void F_66 ( struct V_4 * V_6 )
{
struct V_136 * V_139 ;
struct V_195 * V_7 ;
struct V_443 V_444 ;
int V_132 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_153 , V_6 -> V_2 , V_7 ) ;
V_139 = V_7 -> V_482 ;
if ( ! V_139 )
return;
V_139 -> V_7 = NULL ;
V_7 -> V_482 = NULL ;
V_444 . V_6 = V_564 ;
V_444 . V_477 = - V_463 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_378 = NULL ;
V_444 . V_377 = 0 ;
F_7 ( V_14 , L_154
L_155 , V_444 . V_478 . V_516 . V_517 ,
V_444 . V_479 . V_516 . V_517 ) ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_7 ( V_14 , L_119 , V_132 ) ;
if ( V_132 )
F_32 ( V_154 L_133
L_134 , V_155 , __LINE__ , V_132 ) ;
V_7 -> V_201 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_161 ( struct V_4 * V_6 )
{
struct V_136 * V_139 ;
struct V_195 * V_7 ;
struct V_443 V_444 ;
int V_132 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_156 , V_6 -> V_2 , V_7 ) ;
V_139 = V_7 -> V_482 ;
if ( ! V_139 )
return;
V_139 -> V_7 = NULL ;
V_444 . V_6 = V_476 ;
V_444 . V_477 = - V_463 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_378 = NULL ;
V_444 . V_377 = 0 ;
V_7 -> V_385 ( V_7 ) ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_38 ( & V_481 ) ;
V_444 . V_6 = V_483 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_378 = NULL ;
V_444 . V_377 = 0 ;
F_7 ( V_14 , L_157 , V_6 -> V_2 ) ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_7 ( V_14 , L_119 , V_132 ) ;
V_7 -> V_201 ( V_7 ) ;
return;
}
static void F_162 ( struct V_4 * V_6 )
{
struct V_195 * V_7 ;
struct V_443 V_444 ;
int V_132 ;
struct V_1 * V_2 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_568 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_181 ) ;
V_444 . V_6 = V_569 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = ( void * ) V_2 ;
V_444 . V_478 . V_565 = V_566 ;
V_444 . V_478 . V_529 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_444 . V_478 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_444 . V_479 . V_565 = V_566 ;
V_444 . V_479 . V_529 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_444 . V_479 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_444 . V_378 = V_2 -> V_69 ;
V_444 . V_377 = ( T_1 ) V_2 -> V_54 ;
V_444 . V_567 = V_2 -> V_55 ;
V_444 . V_537 = V_2 -> V_56 ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_132 )
F_32 ( V_154 L_159 ,
V_155 , __LINE__ , V_132 ) ;
return;
}
static void F_117 ( struct V_4 * V_6 )
{
struct V_195 * V_7 ;
struct V_443 V_444 ;
struct V_1 * V_2 ;
int V_132 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_568 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_181 ) ;
V_444 . V_6 = V_564 ;
V_444 . V_477 = - V_570 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 . V_565 = V_566 ;
V_444 . V_478 . V_529 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_444 . V_478 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_444 . V_479 . V_565 = V_566 ;
V_444 . V_479 . V_529 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_444 . V_479 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_444 . V_378 = V_2 -> V_69 ;
V_444 . V_377 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_160
L_155 ,
V_444 . V_478 . V_516 . V_517 ,
V_444 . V_479 . V_516 . V_517 ) ;
V_132 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_132 )
F_32 ( V_154 L_159 ,
V_155 , __LINE__ , V_132 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_38 ( & V_6 -> V_2 -> V_3 -> V_401 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_385 ( V_6 -> V_9 . V_7 ) ;
F_135 ( & V_6 -> V_571 , V_572 ) ;
F_7 ( V_14 , L_161 ,
V_6 -> V_2 , V_6 ) ;
F_136 ( V_6 -> V_2 -> V_3 -> V_404 , & V_6 -> V_571 ) ;
F_7 ( V_14 , L_162 ) ;
return 0 ;
}
static void V_572 ( struct V_441 * V_439 )
{
struct V_4 * V_6 = F_52 ( V_439 , struct V_4 ,
V_571 ) ;
struct V_126 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_163 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_401 ) ) ;
switch ( V_6 -> type ) {
case V_354 :
F_162 ( V_6 ) ;
F_7 ( V_14 , L_164 ,
V_6 -> V_2 ) ;
break;
case V_573 :
F_7 ( V_14 , L_165 ,
V_6 -> V_2 ) ;
F_161 ( V_6 ) ;
break;
case V_357 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_226 ) )
break;
F_159 ( V_6 ) ;
F_7 ( V_14 , L_166 ) ;
break;
case V_356 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_226 ) )
break;
F_117 ( V_6 ) ;
F_7 ( V_14 , L_167 ) ;
break;
case V_202 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_226 ) )
break;
F_66 ( V_6 ) ;
F_7 ( V_14 , L_168 ) ;
break;
case V_574 :
F_7 ( V_14 , L_169 ) ;
break;
default:
F_7 ( V_14 , L_170 ) ;
break;
}
F_69 ( & V_3 -> V_401 ) ;
V_6 -> V_9 . V_7 -> V_201 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_35 ( V_6 ) ;
return;
}
