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
if ( V_2 -> V_65 != V_66 )
F_32 ( 1 , L_24 ,
V_2 -> V_65 ) ;
F_7 ( V_14 , L_25 ) ;
V_145 -> V_149 [ V_153 ] =
F_31 ( V_158 ) ;
V_145 -> V_149 [ V_159 ] = 1 ;
V_145 -> V_149 [ V_160 ] = 0 ;
V_145 -> V_149 [ V_161 ] = 0 ;
V_145 -> V_149 [ V_162 ] = 1 ;
V_145 -> V_149 [ V_157 ] = 1 ;
break;
}
if ( V_143 -> V_163 ) {
V_143 -> V_163 = 0 ;
F_33 ( V_143 -> V_164 ) ;
}
V_143 -> V_165 -> V_166 &= F_31 ( ~ ( V_167 |
V_168 |
V_169 ) ) ;
V_143 -> V_170 = 1 ;
V_143 -> V_146 . V_171 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_172 type , int V_173 ,
int V_174 )
{
unsigned long V_29 ;
struct V_130 * V_3 = V_2 -> V_3 ;
struct V_175 * V_176 ;
int V_136 = 0 ;
V_176 = F_6 ( sizeof( * V_176 ) , V_8 ) ;
if ( ! V_176 )
return - V_27 ;
V_176 -> V_177 = V_178 ;
V_176 -> V_179 = V_180 ;
V_176 -> V_16 = V_16 ;
V_176 -> V_181 = V_182 ;
V_176 -> type = type ;
V_176 -> V_86 = V_2 -> V_86 ;
V_176 -> V_173 = V_173 ;
V_176 -> V_174 = V_174 ;
if ( type == V_183 ) {
V_176 -> V_181 += ( V_184 / 10 ) ;
if ( V_2 -> V_185 ) {
F_34 ( V_176 ) ;
F_35 ( 1 ) ;
return - V_43 ;
}
V_2 -> V_185 = V_176 ;
}
if ( type == V_23 ) {
V_176 -> V_186 = F_36 ( F_37 ( V_16 ) -> V_113 ) ;
F_38 ( & V_176 -> V_16 -> V_187 ) ;
F_39 ( & V_2 -> V_188 , V_29 ) ;
V_2 -> V_189 = V_176 ;
F_2 ( V_2 ) ;
F_40 ( & V_2 -> V_188 , V_29 ) ;
V_176 -> V_181 = V_182 + V_190 ;
V_136 = F_41 ( V_176 -> V_16 , V_2 -> V_86 ) ;
if ( V_136 != V_191 ) {
F_7 ( V_14 , L_26
L_27 , V_176 , V_182 ) ;
V_176 -> V_181 = V_182 ;
V_136 = V_191 ;
} else {
V_192 ++ ;
if ( ! V_173 ) {
F_42 ( V_2 ) ;
if ( V_174 )
F_4 ( V_3 , V_2 ) ;
return V_136 ;
}
}
}
if ( ! F_43 ( & V_3 -> V_193 ) )
F_44 ( & V_3 -> V_193 , V_176 -> V_181 ) ;
return V_136 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_194 * V_7 = V_2 -> V_7 ;
enum V_195 V_32 = V_2 -> V_32 ;
V_2 -> V_32 = V_196 ;
switch ( V_32 ) {
case V_197 :
case V_198 :
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_199 :
case V_33 :
if ( V_2 -> V_7 )
V_7 -> V_200 ( V_7 ) ;
F_46 ( V_2 , NULL ) ;
break;
default:
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
F_5 ( V_2 , V_201 ) ;
}
}
static void F_47 ( struct V_1 * V_2 , T_3 V_202 )
{
struct V_175 * V_185 = V_2 -> V_185 ;
struct V_194 * V_7 = V_2 -> V_7 ;
struct V_140 * V_143 ;
unsigned long V_203 ;
if ( ! V_185 )
return;
V_143 = (struct V_140 * ) V_185 -> V_16 ;
if ( V_143 ) {
F_39 ( & V_143 -> V_204 , V_203 ) ;
if ( V_143 -> V_7 ) {
F_7 ( V_14 , L_28
L_29
L_30
L_31 , V_143 -> V_146 . V_205 , V_7 ,
F_26 ( & V_143 -> V_206 ) ) ;
V_143 -> V_207 = V_208 ;
V_143 -> V_209 = V_210 ;
V_143 -> V_211 = V_212 ;
F_40 ( & V_143 -> V_204 , V_203 ) ;
F_48 ( V_143 ) ;
} else {
F_40 ( & V_143 -> V_204 , V_203 ) ;
F_7 ( V_14 , L_28
L_29
L_32
L_31 , V_143 -> V_146 . V_205 , V_7 ,
F_26 ( & V_143 -> V_206 ) ) ;
}
} else if ( V_202 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_2 -> V_7 )
V_7 -> V_200 ( V_7 ) ;
F_34 ( V_185 ) ;
V_2 -> V_185 = NULL ;
}
static void F_49 ( unsigned long V_213 )
{
unsigned long V_29 ;
unsigned long V_214 = V_182 + V_215 ;
struct V_1 * V_2 ;
struct V_175 * V_189 , * V_185 ;
struct V_216 * V_217 ;
struct V_216 * V_218 ;
struct V_130 * V_3 = V_219 ;
T_3 V_220 = 0 ;
unsigned long V_181 ;
int V_136 = V_191 ;
struct V_216 V_221 ;
F_50 ( & V_221 ) ;
F_39 ( & V_3 -> V_222 , V_29 ) ;
F_51 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_2 = F_52 ( V_218 , struct V_1 , V_223 ) ;
if ( ( V_2 -> V_185 ) || ( V_2 -> V_189 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_224 , & V_221 ) ;
}
}
F_40 ( & V_3 -> V_222 , V_29 ) ;
F_51 (list_node, list_core_temp, &timer_list) {
V_2 = F_52 ( V_218 , struct V_1 ,
V_224 ) ;
V_185 = V_2 -> V_185 ;
if ( V_185 ) {
if ( F_54 ( V_185 -> V_181 , V_182 ) ) {
if ( V_214 > V_185 -> V_181 ||
! V_220 ) {
V_214 = V_185 -> V_181 ;
V_220 = 1 ;
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
if ( F_54 ( V_189 -> V_181 , V_182 ) ) {
if ( V_2 -> V_32 != V_225 ) {
if ( ( V_214 >
V_189 -> V_181 ) ||
! V_220 ) {
V_214 =
V_189 -> V_181 ;
V_220 = 1 ;
}
} else {
F_55 ( V_2 ) ;
}
break;
}
if ( ( V_2 -> V_32 == V_225 ) ||
( V_2 -> V_32 == V_196 ) ) {
F_55 ( V_2 ) ;
break;
}
if ( ! V_189 -> V_179 ||
! V_189 -> V_177 ) {
V_226 ++ ;
F_55 ( V_2 ) ;
F_40 (
& V_2 -> V_188 , V_29 ) ;
F_45 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
F_39 ( & V_2 -> V_188 ,
V_29 ) ;
break;
}
F_38 ( & V_189 -> V_16 -> V_187 ) ;
V_227 ++ ;
F_7 ( V_14 , L_33
L_34
L_35
L_36
L_37 , V_189 , V_2 , V_182 ,
V_189 -> V_181 ,
V_189 -> V_179 ,
V_189 -> V_186 ,
V_2 -> V_105 . V_228 ) ;
F_40 ( & V_2 -> V_188 ,
V_29 ) ;
V_136 = F_41 ( V_189 -> V_16 , V_2 -> V_86 ) ;
F_39 ( & V_2 -> V_188 , V_29 ) ;
if ( V_136 != V_191 ) {
F_7 ( V_14 , L_38
L_39 , V_2 ) ;
V_229 ++ ;
V_189 -> V_177 -- ;
V_214 = V_182 + V_230 ;
V_220 = 1 ;
break;
} else {
V_192 ++ ;
}
F_7 ( V_14 , L_40
L_41 ,
V_189 -> V_179 ,
V_189 -> V_177 ) ;
if ( V_189 -> V_173 ) {
V_189 -> V_179 -- ;
V_181 = ( V_190 <<
( V_180 - V_189 -> V_179 ) ) ;
V_189 -> V_181 = V_182 +
F_56 ( V_181 , V_231 ) ;
if ( V_214 > V_189 -> V_181 ||
! V_220 ) {
V_214 = V_189 -> V_181 ;
V_220 = 1 ;
}
} else {
int V_174 ;
V_174 =
V_189 -> V_174 ;
F_7 ( V_14 , L_42 ,
V_2 , V_2 -> V_32 ) ;
F_55 ( V_2 ) ;
if ( V_174 )
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
} while ( 0 );
F_40 ( & V_2 -> V_188 , V_29 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_220 ) {
if ( ! F_43 ( & V_3 -> V_193 ) )
F_44 ( & V_3 -> V_193 , V_214 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , T_3 V_232 ,
struct V_15 * V_16 )
{
int V_136 ;
int V_29 = V_119 ;
char V_233 [ sizeof( struct V_234 ) +
sizeof( struct V_235 ) + sizeof( struct V_236 ) +
V_237 ] ;
int V_238 = 0 ;
union V_239 * V_71 ;
if ( ! V_2 )
return - V_43 ;
V_71 = (union V_239 * ) & V_233 [ V_238 ] ;
V_71 -> V_240 . V_241 = V_242 ;
V_71 -> V_240 . V_243 = sizeof( struct V_234 ) ;
V_71 -> V_240 . V_244 = F_22 ( V_2 -> V_105 . V_244 ) ;
V_238 += sizeof( struct V_234 ) ;
V_71 = (union V_239 * ) & V_233 [ V_238 ] ;
V_71 -> V_245 . V_241 = V_246 ;
V_71 -> V_245 . V_243 = sizeof( struct V_235 ) ;
V_71 -> V_245 . V_247 = V_2 -> V_105 . V_248 ;
V_238 += sizeof( struct V_235 ) ;
if ( V_232 && ! ( V_249 & V_250 ) ) {
V_71 = (union V_239 * ) & V_233 [ V_238 ] ;
V_71 -> V_251 . V_241 = V_252 ;
V_71 -> V_251 . V_243 = sizeof( struct V_236 ) ;
V_238 += sizeof( struct V_236 ) ;
V_71 = (union V_239 * ) & V_233 [ V_238 ] ;
V_71 -> V_253 = 1 ;
V_238 += 1 ;
V_71 = (union V_239 * ) & V_233 [ V_238 ] ;
V_71 -> V_253 = 1 ;
V_238 += 1 ;
}
V_71 = (union V_239 * ) & V_233 [ V_238 ] ;
V_71 -> V_253 = V_254 ;
V_238 += 1 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
if ( V_232 )
V_29 |= V_22 ;
F_11 ( V_16 , V_2 , V_233 , V_238 , NULL , 0 , V_29 ) ;
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
struct V_216 * V_255 ;
struct V_1 * V_2 ;
V_255 = & V_3 -> V_256 ;
F_39 ( & V_3 -> V_222 , V_29 ) ;
F_61 (cm_node, hte, list) {
F_7 ( V_14 , L_43 ,
V_2 -> V_11 , V_2 -> V_13 ,
V_11 , V_13 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_10 , V_12 ) ;
if ( ( V_2 -> V_11 == V_11 ) && ( V_2 -> V_13 == V_13 ) &&
( V_2 -> V_10 == V_10 ) && ( V_2 -> V_12 == V_12 ) ) {
F_2 ( V_2 ) ;
F_40 ( & V_3 -> V_222 , V_29 ) ;
return V_2 ;
}
}
F_40 ( & V_3 -> V_222 , V_29 ) ;
return NULL ;
}
static struct V_257 * F_62 ( struct V_130 * V_3 ,
T_5 V_258 , T_2 V_259 , enum V_260 V_261 )
{
unsigned long V_29 ;
struct V_257 * V_262 ;
F_39 ( & V_3 -> V_263 , V_29 ) ;
F_61 (listen_node, &cm_core->listen_list.list, list) {
if ( ( ( V_262 -> V_11 == V_258 ) ||
V_262 -> V_11 == 0x00000000 ) &&
( V_262 -> V_13 == V_259 ) &&
( V_261 & V_262 -> V_261 ) ) {
F_38 ( & V_262 -> V_264 ) ;
F_40 ( & V_3 -> V_263 , V_29 ) ;
return V_262 ;
}
}
F_40 ( & V_3 -> V_263 , V_29 ) ;
return NULL ;
}
static int F_63 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_216 * V_255 ;
if ( ! V_2 || ! V_3 )
return - V_43 ;
F_7 ( V_14 , L_44 ,
V_2 ) ;
F_39 ( & V_3 -> V_222 , V_29 ) ;
V_255 = & V_3 -> V_256 ;
F_64 ( & V_2 -> V_223 , V_255 ) ;
F_38 ( & V_3 -> V_265 ) ;
F_40 ( & V_3 -> V_222 , V_29 ) ;
return 0 ;
}
static int F_65 ( struct V_130 * V_3 ,
struct V_257 * V_266 , int V_267 )
{
int V_136 = - V_43 ;
int V_268 = 0 ;
unsigned long V_29 ;
struct V_216 * V_269 = NULL ;
struct V_216 * V_270 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_216 V_271 ;
F_7 ( V_14 , L_45
L_46 , V_266 , V_267 ,
F_26 ( & V_266 -> V_264 ) ) ;
F_50 ( & V_271 ) ;
if ( V_267 ) {
F_39 ( & V_3 -> V_222 , V_29 ) ;
F_51 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_52 ( V_269 , struct V_1 ,
V_223 ) ;
if ( ( V_2 -> V_266 == V_266 ) &&
( ! V_2 -> V_272 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_273 , & V_271 ) ;
}
}
F_40 ( & V_3 -> V_222 , V_29 ) ;
}
F_51 (list_pos, list_temp, &reset_list) {
V_2 = F_52 ( V_269 , struct V_1 ,
V_273 ) ;
{
struct V_1 * V_274 = V_2 -> V_275 ;
enum V_195 V_276 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_274 ) {
F_42 ( V_2 ) ;
V_268 = F_46 ( V_2 , NULL ) ;
if ( V_268 ) {
V_2 -> V_32 =
V_196 ;
F_35 ( 1 ) ;
} else {
V_276 = V_2 -> V_32 ;
V_2 -> V_32 = V_277 ;
if ( V_276 != V_278 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_274 ;
V_6 . V_9 . V_10 =
V_274 -> V_10 ;
V_6 . V_9 . V_11 =
V_274 -> V_11 ;
V_6 . V_9 . V_12 =
V_274 -> V_12 ;
V_6 . V_9 . V_13 =
V_274 -> V_13 ;
V_6 . V_9 . V_7 = V_274 -> V_7 ;
F_2 ( V_274 ) ;
V_274 -> V_32 = V_196 ;
F_66 ( & V_6 ) ;
V_2 -> V_32 = V_277 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_39 ( & V_3 -> V_263 , V_29 ) ;
if ( ! F_67 ( & V_266 -> V_264 ) ) {
F_68 ( & V_266 -> V_223 ) ;
F_69 ( & V_3 -> V_132 ) ;
F_40 ( & V_3 -> V_263 , V_29 ) ;
if ( V_266 -> V_279 )
F_70 ( V_266 -> V_279 , V_266 -> V_13 ,
F_71 ( V_266 -> V_279 -> V_280 -> V_281 -> V_282 ) , V_283 ) ;
F_7 ( V_14 , L_47 , V_266 ) ;
F_34 ( V_266 ) ;
V_266 = NULL ;
V_136 = 0 ;
F_38 ( & V_284 ) ;
} else {
F_40 ( & V_3 -> V_263 , V_29 ) ;
}
if ( V_266 ) {
if ( F_26 ( & V_266 -> V_285 ) > 0 )
F_7 ( V_14 , L_48
L_49 ,
V_266 , F_26 ( & V_266 -> V_285 ) ) ;
}
return V_136 ;
}
static int F_72 ( struct V_130 * V_3 ,
struct V_257 * V_266 )
{
V_266 -> V_261 = V_286 ;
V_266 -> V_7 = NULL ;
return F_65 ( V_3 , V_266 , 1 ) ;
}
static inline int F_73 ( struct V_130 * V_3 ,
struct V_1 * V_2 )
{
V_2 -> V_272 = 1 ;
if ( V_2 -> V_287 ) {
F_74 ( ! V_2 -> V_266 ) ;
F_69 ( & V_2 -> V_266 -> V_285 ) ;
V_2 -> V_287 = 0 ;
F_74 ( F_26 ( & V_2 -> V_266 -> V_285 ) < 0 ) ;
}
if ( ! F_43 ( & V_3 -> V_193 ) )
F_44 ( & V_3 -> V_193 , ( V_182 + V_230 ) ) ;
return 0 ;
}
static int F_75 ( struct V_288 * V_279 , T_3 V_289 , int V_290 )
{
struct V_291 * V_292 ;
struct V_293 * V_294 ;
int V_295 = V_290 ;
struct V_296 * V_86 ;
struct V_297 * V_298 = V_279 -> V_280 -> V_298 ;
V_292 = F_76 ( & V_299 , F_23 ( V_289 ) , 0 , 0 , 0 ) ;
if ( F_77 ( V_292 ) ) {
F_78 ( V_300 L_50 ,
V_301 , V_289 ) ;
return V_295 ;
}
if ( F_79 ( V_279 -> V_86 ) )
V_86 = V_279 -> V_86 -> V_302 ;
else
V_86 = V_279 -> V_86 ;
V_294 = F_80 ( & V_303 , & V_292 -> V_304 , V_86 ) ;
F_81 () ;
if ( V_294 ) {
if ( V_294 -> V_305 & V_306 ) {
F_7 ( V_14 , L_51
L_52 , V_289 ,
V_294 -> V_307 , F_36 ( V_292 -> V_304 ) ) ;
if ( V_290 >= 0 ) {
if ( ! memcmp ( V_298 -> V_308 [ V_290 ] . V_309 ,
V_294 -> V_307 , V_95 ) ) {
goto V_310;
}
F_82 ( V_279 -> V_86 ,
V_298 -> V_308 [ V_290 ] . V_309 ,
V_289 , V_311 ) ;
}
F_82 ( V_279 -> V_86 , V_294 -> V_307 ,
V_289 , V_312 ) ;
V_295 = F_83 ( V_279 -> V_280 , V_289 , NULL ,
V_313 ) ;
} else {
F_84 ( V_294 , NULL ) ;
}
}
V_310:
F_85 () ;
if ( V_294 )
F_86 ( V_294 ) ;
F_87 ( V_292 ) ;
return V_295 ;
}
static struct V_1 * F_88 ( struct V_130 * V_3 ,
struct V_288 * V_279 , struct V_314 * V_9 ,
struct V_257 * V_266 )
{
struct V_1 * V_2 ;
struct V_315 V_316 ;
int V_317 = 0 ;
int V_290 = 0 ;
struct V_318 * V_280 ;
struct V_297 * V_298 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_48 = V_319 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_55 = V_62 ;
V_2 -> V_56 = V_62 ;
F_7 ( V_14 , L_53 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_266 = V_266 ;
V_2 -> V_86 = V_279 -> V_86 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_97 , V_279 -> V_86 -> V_320 , V_95 ) ;
F_7 ( V_14 , L_54 , V_2 -> V_266 ,
V_2 -> V_7 ) ;
F_89 ( & V_2 -> V_188 ) ;
V_2 -> V_275 = NULL ;
F_90 ( & V_2 -> V_264 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_105 . V_106 = V_321 ;
V_2 -> V_105 . V_248 = V_322 ;
V_2 -> V_105 . V_126 = V_323 >>
V_322 ;
V_316 = F_91 () ;
V_2 -> V_105 . V_114 = F_23 ( V_316 . V_324 ) ;
V_2 -> V_105 . V_244 = V_279 -> V_325 - sizeof( struct V_77 ) -
sizeof( struct V_75 ) - V_83 - V_326 ;
V_2 -> V_105 . V_116 = 0 ;
F_38 ( & V_3 -> V_133 ) ;
V_2 -> V_327 = V_9 -> V_327 ;
V_2 -> V_328 = 0 ;
V_2 -> V_287 = 0 ;
V_2 -> V_279 = V_279 ;
V_280 = V_279 -> V_280 ;
V_298 = V_280 -> V_298 ;
V_2 -> V_275 = NULL ;
V_317 = F_83 ( V_280 , V_2 -> V_10 , NULL , V_313 ) ;
V_290 = F_75 ( V_279 , V_9 -> V_10 , V_317 ) ;
if ( V_290 < 0 ) {
F_34 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_94 , V_298 -> V_308 [ V_290 ] . V_309 , V_95 ) ;
F_7 ( V_14 , L_55 ,
V_2 -> V_94 ) ;
F_63 ( V_3 , V_2 ) ;
F_38 ( & V_329 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_264 ) ;
return 0 ;
}
static int F_4 ( struct V_130 * V_3 ,
struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_140 * V_143 ;
if ( ! V_2 )
return - V_43 ;
F_39 ( & V_2 -> V_3 -> V_222 , V_29 ) ;
if ( F_67 ( & V_2 -> V_264 ) ) {
F_40 ( & V_2 -> V_3 -> V_222 , V_29 ) ;
return 0 ;
}
F_68 ( & V_2 -> V_223 ) ;
F_69 ( & V_3 -> V_265 ) ;
F_40 ( & V_2 -> V_3 -> V_222 , V_29 ) ;
if ( ! V_2 -> V_272 && V_2 -> V_287 ) {
F_74 ( ! V_2 -> V_266 ) ;
F_69 ( & V_2 -> V_266 -> V_285 ) ;
F_74 ( F_26 ( & V_2 -> V_266 -> V_285 ) < 0 ) ;
}
F_35 ( V_2 -> V_189 ) ;
if ( V_2 -> V_185 )
F_47 ( V_2 , 0 ) ;
if ( V_2 -> V_266 ) {
F_65 ( V_3 , V_2 -> V_266 , 0 ) ;
} else {
if ( V_2 -> V_328 && V_2 -> V_279 ) {
F_70 ( V_2 -> V_279 , V_2 -> V_13 ,
F_71 (
V_2 -> V_279 -> V_280 -> V_281 -> V_282 ) ,
V_283 ) ;
}
}
F_69 ( & V_3 -> V_133 ) ;
F_38 ( & V_330 ) ;
V_143 = V_2 -> V_143 ;
if ( V_143 ) {
V_143 -> V_2 = NULL ;
F_92 ( & V_143 -> V_331 ) ;
V_2 -> V_143 = NULL ;
}
F_34 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , T_1 * V_332 ,
T_3 V_72 , T_3 V_333 )
{
T_3 V_334 ;
T_3 V_335 = 0 ;
union V_239 * V_336 ;
char V_337 = 0 ;
while ( V_335 < V_72 ) {
V_336 = (union V_239 * ) ( V_332 + V_335 ) ;
switch ( V_336 -> V_251 . V_241 ) {
case V_254 :
V_335 = V_72 ;
break;
case V_338 :
V_335 += 1 ;
continue;
case V_242 :
F_7 ( V_14 , L_56
L_57 , V_301 ,
V_336 -> V_240 . V_243 , V_335 , V_72 ) ;
V_337 = 1 ;
if ( V_336 -> V_240 . V_243 != 4 ) {
return 1 ;
} else {
V_334 = F_16 ( V_336 -> V_240 . V_244 ) ;
if ( V_334 > 0 && V_334 <
V_2 -> V_105 . V_244 )
V_2 -> V_105 . V_244 = V_334 ;
}
break;
case V_246 :
V_2 -> V_105 . V_339 =
V_336 -> V_245 . V_247 ;
break;
default:
F_7 ( V_14 , L_58 ,
V_336 -> V_251 . V_241 ) ;
break;
}
V_335 += V_336 -> V_251 . V_243 ;
}
if ( ( ! V_337 ) && ( V_333 ) )
V_2 -> V_105 . V_244 = V_340 ;
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
F_26 ( & V_2 -> V_264 ) ) ;
switch ( V_2 -> V_32 ) {
case V_197 :
case V_342 :
case V_343 :
case V_344 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_199 ;
F_59 ( V_2 , NULL ) ;
break;
case V_49 :
F_5 ( V_2 , V_201 ) ;
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_33 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_198 ;
F_58 ( V_2 , NULL ) ;
break;
case V_345 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_346 ;
F_58 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_183 , 1 , 0 ) ;
break;
case V_346 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_225 :
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
F_26 ( & V_2 -> V_264 ) ) ;
F_42 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_342 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_301 , __LINE__ , V_2 ,
V_2 -> V_266 , V_2 -> V_32 ) ;
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
case V_278 :
F_38 ( & V_2 -> V_349 ) ;
F_95 ( V_16 ) ;
break;
case V_343 :
case V_197 :
case V_350 :
F_7 ( V_14 , L_65 , V_301 , __LINE__ ) ;
F_99 ( V_2 , V_16 , V_347 ) ;
break;
case V_225 :
F_98 ( V_2 , V_16 , V_347 ) ;
break;
case V_196 :
F_94 ( V_16 ) ;
break;
case V_345 :
case V_33 :
case V_199 :
V_2 -> V_7 -> V_200 ( V_2 -> V_7 ) ;
case V_346 :
V_2 -> V_32 = V_196 ;
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
int V_136 = 0 ;
int V_74 = V_16 -> V_35 ;
T_1 * V_351 = V_16 -> V_73 ;
enum V_5 type = V_352 ;
T_3 V_353 ;
V_136 = F_15 ( V_2 , V_351 , & V_353 , V_74 ) ;
if ( V_136 ) {
F_7 ( V_14 , L_66 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_67
L_68 , V_301 ,
__LINE__ , V_2 , V_2 -> V_266 ,
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
F_35 ( 1 ) ;
V_2 -> V_32 = V_278 ;
type = V_354 ;
F_90 ( & V_2 -> V_349 ,
V_355 ) ;
break;
case V_49 :
F_42 ( V_2 ) ;
if ( V_353 == V_70 ) {
type = V_356 ;
V_2 -> V_32 = V_344 ;
} else {
type = V_357 ;
V_2 -> V_32 = V_225 ;
}
break;
default:
F_35 ( 1 ) ;
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
L_64 , V_301 , __LINE__ , V_2 ,
V_2 -> V_266 , V_2 -> V_32 ) ;
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_343 :
case V_197 :
F_99 ( V_2 , V_16 , 1 ) ;
break;
case V_225 :
default:
F_94 ( V_16 ) ;
}
}
static int F_102 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 )
{
int V_268 ;
V_268 = ( ( F_36 ( V_76 -> V_117 ) == V_2 -> V_105 . V_114 ) ) ? 0 : 1 ;
if ( V_268 )
F_98 ( V_2 , V_16 , 1 ) ;
return V_268 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 )
{
int V_268 = 0 ;
T_3 V_113 ;
T_3 V_117 ;
T_3 V_114 = V_2 -> V_105 . V_114 ;
T_3 V_116 = V_2 -> V_105 . V_116 ;
T_3 V_126 ;
V_113 = F_36 ( V_76 -> V_113 ) ;
V_117 = F_36 ( V_76 -> V_117 ) ;
V_126 = V_2 -> V_105 . V_126 ;
if ( V_117 != V_114 )
V_268 = 1 ;
else if ( ! F_104 ( V_113 , V_116 , ( V_116 + V_126 ) ) )
V_268 = 1 ;
if ( V_268 ) {
F_7 ( V_14 , L_63
L_64 , V_301 , __LINE__ , V_2 ,
V_2 -> V_266 , V_2 -> V_32 ) ;
F_101 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_69
L_70 , V_2 , V_113 , V_116 ,
V_126 ) ;
}
return V_268 ;
}
static void F_105 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_136 ;
T_3 V_358 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_358 = F_36 ( V_76 -> V_113 ) ;
switch ( V_2 -> V_32 ) {
case V_342 :
case V_49 :
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_350 :
if ( F_26 ( & V_2 -> V_266 -> V_285 ) >
V_2 -> V_266 -> V_359 ) {
F_7 ( V_14 , L_71
L_72 ) ;
V_360 ++ ;
F_99 ( V_2 , V_16 , 0 ) ;
break;
}
V_136 = F_106 ( V_2 , V_76 , V_16 , V_72 ,
1 ) ;
if ( V_136 ) {
F_99 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_105 . V_116 = V_358 + 1 ;
F_74 ( V_2 -> V_189 ) ;
V_2 -> V_287 = 1 ;
F_38 ( & V_2 -> V_266 -> V_285 ) ;
V_2 -> V_32 = V_197 ;
F_57 ( V_2 , 1 , V_16 ) ;
break;
case V_196 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_225 :
case V_343 :
case V_33 :
case V_345 :
case V_278 :
case V_199 :
case V_198 :
case V_361 :
default:
F_94 ( V_16 ) ;
break;
}
}
static void F_107 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_136 ;
T_3 V_358 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_358 = F_36 ( V_76 -> V_113 ) ;
switch ( V_2 -> V_32 ) {
case V_342 :
F_42 ( V_2 ) ;
if ( F_102 ( V_2 , V_76 , V_16 ) )
return;
V_2 -> V_105 . V_228 = F_36 ( V_76 -> V_117 ) ;
V_136 = F_106 ( V_2 , V_76 , V_16 , V_72 , 0 ) ;
if ( V_136 ) {
F_7 ( V_14 , L_73 ,
V_2 ) ;
break;
}
F_42 ( V_2 ) ;
V_2 -> V_105 . V_116 = V_358 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_278 :
F_99 ( V_2 , V_16 , 1 ) ;
break;
case V_350 :
V_2 -> V_105 . V_114 = F_36 ( V_76 -> V_117 ) ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_196 :
V_2 -> V_105 . V_114 = F_36 ( V_76 -> V_117 ) ;
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_343 :
case V_33 :
case V_345 :
case V_199 :
case V_225 :
case V_198 :
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
int V_136 = 0 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
if ( F_103 ( V_2 , V_76 , V_16 ) )
return - V_43 ;
F_109 ( V_16 , V_76 -> V_124 << 2 ) ;
V_358 = F_36 ( V_76 -> V_113 ) ;
V_74 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_197 :
F_42 ( V_2 ) ;
V_136 = F_106 ( V_2 , V_76 , V_16 , V_72 , 1 ) ;
if ( V_136 )
break;
V_2 -> V_105 . V_228 = F_36 ( V_76 -> V_117 ) ;
V_2 -> V_32 = V_343 ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_358 + V_74 ;
F_100 ( V_2 , V_16 ) ;
} else {
F_95 ( V_16 ) ;
}
break;
case V_343 :
F_42 ( V_2 ) ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_358 + V_74 ;
F_100 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_105 . V_228 = F_36 ( V_76 -> V_117 ) ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_358 + V_74 ;
F_100 ( V_2 , V_16 ) ;
} else {
F_95 ( V_16 ) ;
}
break;
case V_350 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_196 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_199 :
case V_198 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
V_2 -> V_7 -> V_200 ( V_2 -> V_7 ) ;
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
case V_225 :
case V_278 :
case V_361 :
default:
F_42 ( V_2 ) ;
F_94 ( V_16 ) ;
break;
}
return V_136 ;
}
static int F_106 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 , int V_72 , int V_362 )
{
T_1 * V_332 = ( T_1 * ) & V_76 [ 1 ] ;
if ( V_72 ) {
if ( F_93 ( V_2 , V_332 , V_72 ,
( T_3 ) V_76 -> V_120 ) ) {
F_7 ( V_14 , L_74 ,
V_301 , V_2 ) ;
if ( V_362 )
F_99 ( V_2 , V_16 , 1 ) ;
else
F_98 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_105 . V_363 = F_16 ( V_76 -> V_125 ) <<
V_2 -> V_105 . V_339 ;
if ( V_2 -> V_105 . V_363 > V_2 -> V_105 . V_364 )
V_2 -> V_105 . V_364 = V_2 -> V_105 . V_363 ;
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
V_2 -> V_32 = V_196 ;
F_5 ( V_2 , V_201 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_347 )
{
F_42 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
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
struct V_175 * V_189 ;
V_189 = V_2 -> V_189 ;
if ( V_189 ) {
V_2 -> V_189 = NULL ;
F_95 ( V_189 -> V_16 ) ;
F_34 ( V_189 ) ;
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
struct V_130 * V_3 )
{
enum V_365 V_366 = V_367 ;
struct V_75 * V_76 = F_37 ( V_16 ) ;
T_3 V_368 = 0 ;
int V_136 = 0 ;
F_109 ( V_16 , F_111 ( V_16 ) -> V_101 << 2 ) ;
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 , V_76 -> V_120 ,
V_76 -> V_118 , V_76 -> V_123 , V_76 -> V_121 ) ;
if ( V_76 -> V_123 ) {
V_366 = V_369 ;
} else if ( V_76 -> V_120 ) {
V_366 = V_370 ;
if ( V_76 -> V_118 )
V_366 = V_371 ;
} else if ( V_76 -> V_118 ) {
V_366 = V_372 ;
}
if ( V_76 -> V_121 )
V_368 = 1 ;
switch ( V_366 ) {
case V_370 :
F_105 ( V_2 , V_16 , V_76 ) ;
break;
case V_371 :
F_107 ( V_2 , V_16 , V_76 ) ;
break;
case V_372 :
V_136 = F_108 ( V_2 , V_16 , V_76 ) ;
if ( V_368 && ! V_136 )
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
static struct V_257 * F_112 ( struct V_130 * V_3 ,
struct V_288 * V_279 , struct V_314 * V_9 )
{
struct V_257 * V_266 ;
unsigned long V_29 ;
F_7 ( V_14 , L_81 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_266 = F_62 ( V_3 , F_23 ( V_9 -> V_11 ) ,
F_22 ( V_9 -> V_13 ) , V_373 ) ;
if ( V_266 && V_266 -> V_261 == V_374 ) {
F_69 ( & V_266 -> V_264 ) ;
F_7 ( V_14 , L_82 ) ;
return NULL ;
}
if ( ! V_266 ) {
V_266 = F_6 ( sizeof( * V_266 ) , V_8 ) ;
if ( ! V_266 ) {
F_7 ( V_14 , L_83 ) ;
return NULL ;
}
V_266 -> V_11 = F_23 ( V_9 -> V_11 ) ;
V_266 -> V_13 = F_22 ( V_9 -> V_13 ) ;
V_266 -> V_375 = 0 ;
F_90 ( & V_266 -> V_264 , 1 ) ;
}
else {
V_266 -> V_375 = 1 ;
}
V_266 -> V_7 = V_9 -> V_7 ;
F_90 ( & V_266 -> V_285 , 0 ) ;
V_266 -> V_3 = V_3 ;
V_266 -> V_279 = V_279 ;
F_38 ( & V_3 -> V_133 ) ;
V_266 -> V_327 = V_9 -> V_327 ;
V_266 -> V_359 = V_9 -> V_359 ;
V_266 -> V_261 = V_374 ;
if ( ! V_266 -> V_375 ) {
F_39 ( & V_3 -> V_263 , V_29 ) ;
F_53 ( & V_266 -> V_223 , & V_3 -> V_376 . V_223 ) ;
F_40 ( & V_3 -> V_263 , V_29 ) ;
F_38 ( & V_3 -> V_132 ) ;
}
F_7 ( V_14 , L_84
L_85 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_266 , V_266 -> V_359 , V_266 -> V_7 ) ;
return V_266 ;
}
static struct V_1 * F_113 ( struct V_130 * V_3 ,
struct V_288 * V_279 , T_2 V_377 ,
void * V_378 , struct V_314 * V_9 )
{
int V_136 = 0 ;
struct V_1 * V_2 ;
struct V_257 * V_379 ;
struct V_1 * V_380 ;
struct V_314 V_381 ;
T_1 * V_19 ;
V_2 = F_88 ( V_3 , V_279 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_105 . V_382 = 1 ;
V_2 -> V_105 . V_248 = V_322 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_379 = F_62 ( V_3 ,
F_36 ( V_279 -> V_383 ) , V_2 -> V_12 ,
V_374 ) ;
if ( V_379 == NULL ) {
F_5 ( V_2 , V_201 ) ;
} else {
V_381 = * V_9 ;
V_381 . V_13 = V_9 -> V_12 ;
V_381 . V_12 = V_9 -> V_13 ;
V_381 . V_7 = V_379 -> V_7 ;
V_380 = F_88 ( V_3 , V_279 ,
& V_381 , V_379 ) ;
if ( ! V_380 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_38 ( & V_384 ) ;
V_380 -> V_275 = V_2 ;
V_380 -> V_105 . V_248 =
V_322 ;
V_2 -> V_275 = V_380 ;
memcpy ( V_380 -> V_69 , V_378 ,
V_377 ) ;
V_380 -> V_54 = V_377 ;
V_2 -> V_32 = V_225 ;
V_2 -> V_105 . V_116 =
V_380 -> V_105 . V_114 ;
V_380 -> V_105 . V_116 =
V_2 -> V_105 . V_114 ;
V_2 -> V_105 . V_364 =
V_380 -> V_105 . V_126 ;
V_380 -> V_105 . V_364 =
V_2 -> V_105 . V_126 ;
V_2 -> V_105 . V_363 =
V_380 -> V_105 . V_126 ;
V_380 -> V_105 . V_363 =
V_2 -> V_105 . V_126 ;
V_2 -> V_105 . V_339 =
V_380 -> V_105 . V_248 ;
V_380 -> V_105 . V_339 =
V_2 -> V_105 . V_248 ;
V_380 -> V_32 = V_278 ;
F_5 ( V_380 , V_354 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_377 ;
memcpy ( V_19 , V_378 , V_377 ) ;
V_2 -> V_32 = V_342 ;
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
static int F_114 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_115 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
int V_136 = 0 ;
int V_268 = 0 ;
int V_349 ;
struct V_4 V_6 ;
struct V_194 * V_7 = V_2 -> V_7 ;
struct V_1 * V_274 = V_2 -> V_275 ;
F_7 ( V_14 , L_90 ,
V_301 , V_2 , V_2 -> V_105 . V_382 , V_2 -> V_32 ) ;
if ( V_2 -> V_105 . V_382 )
return V_136 ;
F_42 ( V_2 ) ;
if ( ! V_274 ) {
V_349 = F_116 ( 1 , & V_2 -> V_349 ) ;
if ( V_349 == V_385 ) {
V_2 -> V_32 = V_196 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_277 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_136 = F_13 ( V_2 ) ;
if ( V_136 ) {
V_2 -> V_32 = V_196 ;
V_268 = F_46 ( V_2 , NULL ) ;
if ( V_268 )
F_35 ( 1 ) ;
} else {
V_7 -> V_386 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_277 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_274 ) ;
} else {
V_6 . V_2 = V_274 ;
V_6 . V_9 . V_10 = V_274 -> V_10 ;
V_6 . V_9 . V_11 = V_274 -> V_11 ;
V_6 . V_9 . V_12 = V_274 -> V_12 ;
V_6 . V_9 . V_13 = V_274 -> V_13 ;
V_6 . V_9 . V_7 = V_274 -> V_7 ;
F_117 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_274 -> V_32 = V_198 ;
V_7 = V_274 -> V_7 ;
F_4 ( V_3 , V_274 ) ;
V_7 -> V_200 ( V_7 ) ;
}
}
return V_136 ;
}
static int F_118 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
int V_136 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_197 :
case V_342 :
case V_387 :
case V_343 :
case V_388 :
case V_49 :
case V_278 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_389 :
V_2 -> V_32 = V_199 ;
F_59 ( V_2 , NULL ) ;
break;
case V_33 :
case V_345 :
case V_199 :
case V_346 :
case V_198 :
V_136 = - 1 ;
break;
case V_350 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_344 :
case V_361 :
case V_390 :
case V_196 :
case V_277 :
V_136 = F_4 ( V_3 , V_2 ) ;
break;
case V_225 :
if ( V_2 -> V_189 )
F_78 ( V_300 L_91
L_92 , V_2 -> V_189 ) ;
V_136 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_136 ;
}
static int F_119 ( struct V_130 * V_3 ,
struct V_288 * V_279 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_257 * V_266 = NULL ;
struct V_77 * V_78 ;
struct V_75 * V_76 ;
struct V_314 V_391 ;
int V_392 = 1 ;
T_6 V_393 , V_394 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_77 ) + sizeof( struct V_75 ) )
return 0 ;
V_78 = (struct V_77 * ) V_16 -> V_73 ;
V_76 = (struct V_75 * ) ( V_16 -> V_73 + sizeof( struct V_77 ) ) ;
V_391 . V_11 = F_36 ( V_78 -> V_110 ) ;
V_391 . V_13 = F_16 ( V_76 -> V_112 ) ;
V_391 . V_10 = F_36 ( V_78 -> V_109 ) ;
V_391 . V_12 = F_16 ( V_76 -> V_111 ) ;
V_393 = F_120 ( V_78 -> V_110 ) ;
V_394 = F_120 ( V_78 -> V_109 ) ;
F_7 ( V_14 , L_93 ,
& V_393 , V_76 -> V_112 , & V_394 , V_76 -> V_111 ) ;
do {
V_2 = F_60 ( V_3 ,
V_391 . V_12 , V_391 . V_10 ,
V_391 . V_13 , V_391 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_76 -> V_120 ) || ( V_76 -> V_118 ) ) {
V_392 = 0 ;
break;
}
V_266 = F_62 ( V_3 , V_391 . V_11 ,
V_391 . V_13 ,
V_374 ) ;
if ( ! V_266 ) {
V_391 . V_7 = NULL ;
V_391 . V_327 = 0 ;
F_7 ( V_14 , L_94 ) ;
V_392 = 0 ;
break;
}
V_391 . V_7 = V_266 -> V_7 ;
V_391 . V_327 = V_266 -> V_327 ;
V_2 = F_88 ( V_3 , V_279 , & V_391 ,
V_266 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_95
L_96 ) ;
V_226 ++ ;
F_69 ( & V_266 -> V_264 ) ;
F_95 ( V_16 ) ;
break;
}
if ( ! V_76 -> V_123 && ! V_76 -> V_121 ) {
V_2 -> V_32 = V_350 ;
} else {
V_226 ++ ;
F_4 ( V_3 , V_2 ) ;
F_95 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_225 ) {
if ( V_2 -> V_143 -> V_395 )
F_121 ( V_16 , V_279 , V_2 -> V_143 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_38 ( & V_341 ) ;
F_95 ( V_16 ) ;
}
break;
}
F_122 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_76 ) ) ;
V_16 -> V_35 = F_16 ( V_78 -> V_103 ) ;
F_110 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_392 ;
}
static struct V_130 * F_123 ( void )
{
struct V_130 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_396 ) ;
if ( ! V_3 )
return NULL ;
F_50 ( & V_3 -> V_256 ) ;
F_124 ( & V_3 -> V_193 ) ;
V_3 -> V_193 . V_397 = F_49 ;
V_3 -> V_398 = V_399 ;
V_3 -> V_32 = V_390 ;
V_3 -> V_400 = V_401 ;
F_90 ( & V_3 -> V_402 , 0 ) ;
V_3 -> V_403 = & V_404 ;
F_89 ( & V_3 -> V_222 ) ;
F_89 ( & V_3 -> V_263 ) ;
F_50 ( & V_3 -> V_376 . V_223 ) ;
F_7 ( V_14 , L_97 , V_3 ) ;
F_7 ( V_14 , L_98 ) ;
V_3 -> V_405 = F_125 ( L_99 ) ;
V_3 -> V_406 = F_8 ;
F_7 ( V_14 , L_100 ) ;
V_3 -> V_407 = F_125 ( L_101 ) ;
F_25 ( V_3 ) ;
return V_3 ;
}
static int F_126 ( struct V_130 * V_3 )
{
F_7 ( V_14 , L_102 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_127 () ;
if ( F_43 ( & V_3 -> V_193 ) )
F_128 ( & V_3 -> V_193 ) ;
F_129 ( V_3 -> V_405 ) ;
F_129 ( V_3 -> V_407 ) ;
F_7 ( V_14 , L_103 ) ;
F_34 ( V_3 ) ;
return 0 ;
}
static int F_130 ( struct V_130 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_131 ( struct V_130 * V_3 , T_3 type , T_3 V_408 )
{
int V_136 = 0 ;
switch ( type ) {
case V_409 :
V_3 -> V_398 = V_408 ;
break;
case V_410 :
V_3 -> V_400 = V_408 ;
break;
default:
V_136 = - V_43 ;
}
return V_136 ;
}
static int F_132 ( struct V_140 * V_143 , struct V_1 * V_2 )
{
int V_136 = 0 ;
if ( ! V_143 )
return - V_43 ;
V_143 -> V_165 -> V_411 |= F_31 ( V_412 |
V_413 | V_414 |
V_415 ) ;
if ( V_2 -> V_105 . V_339 || V_2 -> V_105 . V_248 )
V_143 -> V_165 -> V_411 |= F_31 ( V_416 ) ;
V_143 -> V_165 -> V_417 |= F_31 ( 64 << V_418 ) ;
V_143 -> V_165 -> V_244 |= F_31 ( ( ( T_3 ) V_2 -> V_105 . V_244 ) << 16 ) ;
V_143 -> V_165 -> V_419 |= F_31 (
( T_3 ) V_420 << V_421 ) ;
V_143 -> V_165 -> V_422 |= F_31 (
( V_2 -> V_105 . V_339 << V_423 ) &
V_424 ) ;
V_143 -> V_165 -> V_422 |= F_31 (
( V_2 -> V_105 . V_248 << V_425 ) &
V_426 ) ;
V_143 -> V_165 -> V_427 = F_31 ( 0x80 ) ;
V_143 -> V_165 -> V_428 = 0 ;
V_143 -> V_165 -> V_429 = 0 ;
V_143 -> V_165 -> V_430 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_363 = F_31 ( V_2 -> V_105 . V_363 ) ;
V_143 -> V_165 -> V_116 = F_31 ( V_2 -> V_105 . V_116 ) ;
V_143 -> V_165 -> V_126 = F_31 ( V_2 -> V_105 . V_126 <<
V_2 -> V_105 . V_248 ) ;
V_143 -> V_165 -> V_431 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_432 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_433 = 0 ;
V_143 -> V_165 -> V_434 = F_31 ( 0x6 ) ;
V_143 -> V_165 -> V_435 = F_31 ( 0x3FFFC000 ) ;
V_143 -> V_165 -> V_436 = F_31 ( 2 * V_2 -> V_105 . V_244 ) ;
V_143 -> V_165 -> V_437 = F_31 ( V_2 -> V_105 . V_116 ) ;
V_143 -> V_165 -> V_438 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_364 = F_31 ( V_2 -> V_105 . V_364 ) ;
F_7 ( V_14 , L_104
L_105 ,
V_143 -> V_146 . V_205 , F_133 ( V_143 -> V_165 -> V_116 ) ,
F_133 ( V_143 -> V_165 -> V_430 ) ,
V_2 -> V_105 . V_244 , F_133 ( V_143 -> V_165 -> V_422 ) ,
F_133 ( V_143 -> V_165 -> V_126 ) ,
F_133 ( V_143 -> V_165 -> V_411 ) ) ;
F_7 ( V_14 , L_106 , F_133 ( V_143 -> V_165 -> V_363 ) ) ;
F_7 ( V_14 , L_107 , F_133 ( V_143 -> V_165 -> V_436 ) ) ;
F_7 ( V_14 , L_108 , F_133 ( V_143 -> V_165 -> V_364 ) ) ;
F_7 ( V_14 , L_109 ) ;
V_2 -> V_32 = V_225 ;
return V_136 ;
}
int F_48 ( struct V_140 * V_143 )
{
struct V_439 * V_440 ;
V_440 = F_6 ( sizeof *V_440 , V_8 ) ;
if ( ! V_440 )
return - V_27 ;
F_134 ( & V_143 -> V_331 ) ;
V_440 -> V_143 = V_143 ;
F_135 ( & V_440 -> V_440 , V_441 ) ;
F_136 ( V_219 -> V_407 , & V_440 -> V_440 ) ;
return 0 ;
}
static void V_441 ( struct V_442 * V_440 )
{
struct V_439 * V_443 = F_52 ( V_440 , struct V_439 , V_440 ) ;
struct V_140 * V_143 = V_443 -> V_143 ;
F_34 ( V_443 ) ;
F_7 ( V_14 , L_110 ,
V_143 -> V_209 , V_143 -> V_146 . V_205 ) ;
F_137 ( V_143 ) ;
F_92 ( & V_143 -> V_331 ) ;
}
static int F_137 ( struct V_140 * V_143 )
{
unsigned long V_29 ;
int V_136 = 0 ;
struct V_194 * V_7 ;
struct V_444 V_445 ;
struct V_288 * V_279 ;
T_2 V_446 ;
T_1 V_447 ;
T_1 V_448 ;
int V_449 = 0 ;
int V_450 = 0 ;
int V_451 = 0 ;
int V_452 = 0 ;
T_3 V_453 = V_454 ;
struct V_455 V_456 ;
if ( ! V_143 ) {
F_7 ( V_14 , L_111 ) ;
return - 1 ;
}
F_39 ( & V_143 -> V_204 , V_29 ) ;
V_7 = V_143 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_112 ,
V_143 -> V_146 . V_205 ) ;
F_40 ( & V_143 -> V_204 , V_29 ) ;
return - 1 ;
}
V_279 = F_138 ( V_143 -> V_331 . V_457 ) ;
F_7 ( V_14 , L_113 , V_143 -> V_146 . V_205 ) ;
V_447 = V_143 -> V_207 ;
V_448 = V_143 -> V_211 ;
V_446 = V_143 -> V_209 ;
if ( V_143 -> V_458 ) {
V_450 = 1 ;
V_451 = 1 ;
V_143 -> V_7 = NULL ;
F_128 ( & V_143 -> V_459 ) ;
if ( V_143 -> V_460 == 0 ) {
V_143 -> V_460 = 1 ;
V_452 = 1 ;
}
} else if ( ( V_447 == V_461 ) ||
( ( V_448 == V_462 ) &&
( V_446 == V_463 ) ) ) {
V_450 = 1 ;
if ( V_446 == V_463 )
V_449 = - V_464 ;
}
if ( ( ( V_447 == V_208 ) ||
( V_447 == V_465 ) ||
( V_446 == V_466 ) ||
( V_446 == V_463 ) ) ) {
V_451 = 1 ;
V_143 -> V_7 = NULL ;
if ( V_143 -> V_460 == 0 ) {
V_143 -> V_460 = 1 ;
V_452 = 1 ;
}
}
F_40 ( & V_143 -> V_204 , V_29 ) ;
if ( ( V_452 ) && ( V_143 -> V_467 == 0 ) ) {
if ( V_143 -> V_468 >= V_469 )
V_453 |= V_470 ;
F_139 ( V_279 -> V_280 , V_143 , V_453 , 1 ) ;
if ( V_143 -> V_458 ) {
V_456 . V_457 = V_143 -> V_331 . V_457 ;
V_456 . V_6 = V_143 -> V_471 ;
V_456 . V_472 . V_473 = & V_143 -> V_331 ;
if ( V_143 -> V_331 . V_474 )
V_143 -> V_331 . V_474 ( & V_456 , V_143 -> V_331 . V_475 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_474 ) ) {
if ( V_450 ) {
F_38 ( & V_476 ) ;
V_445 . V_6 = V_477 ;
V_445 . V_478 = V_449 ;
V_445 . V_479 = V_7 -> V_479 ;
V_445 . V_480 = V_7 -> V_480 ;
V_445 . V_378 = NULL ;
V_445 . V_377 = 0 ;
F_7 ( V_14 , L_114
L_115
L_116 ,
V_143 -> V_146 . V_205 , V_143 -> V_146 . V_481 ,
V_143 -> V_146 . V_171 , V_7 ,
F_26 ( & V_143 -> V_206 ) ) ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
if ( V_136 )
F_7 ( V_14 , L_117
L_118 , V_136 ) ;
}
if ( V_451 ) {
F_38 ( & V_482 ) ;
F_140 ( V_143 , 1 ) ;
V_7 -> V_483 = V_143 ;
V_445 . V_6 = V_484 ;
V_445 . V_478 = 0 ;
V_445 . V_483 = V_7 -> V_483 ;
V_445 . V_479 = V_7 -> V_479 ;
V_445 . V_480 = V_7 -> V_480 ;
V_445 . V_378 = NULL ;
V_445 . V_377 = 0 ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
if ( V_136 )
F_7 ( V_14 , L_119 , V_136 ) ;
V_7 -> V_200 ( V_7 ) ;
}
}
return 0 ;
}
static int F_140 ( struct V_140 * V_143 , int V_485 )
{
int V_136 = 0 ;
struct V_288 * V_279 ;
struct V_318 * V_280 ;
struct V_486 * V_487 ;
V_279 = F_138 ( V_143 -> V_331 . V_457 ) ;
if ( ! V_279 )
return - V_43 ;
V_280 = V_279 -> V_280 ;
V_487 = V_279 -> V_487 ;
F_7 ( V_14 , L_120 ,
F_141 ( V_279 -> V_86 ) ) ;
if ( V_143 -> V_488 ) {
V_143 -> V_488 = 0 ;
} else {
if ( V_143 -> V_489 ) {
if ( V_143 -> V_490 )
V_487 -> V_491 . V_492 ( V_143 -> V_490 ) ;
F_142 ( V_280 -> V_281 ,
V_143 -> V_377 + V_143 -> V_493 ,
V_143 -> V_489 , V_143 -> V_494 ) ;
}
}
if ( V_143 -> V_2 ) {
F_7 ( V_14 , L_121 ) ;
V_219 -> V_403 -> V_495 ( V_219 , V_143 -> V_2 ) ;
}
return V_136 ;
}
int F_143 ( struct V_194 * V_7 , struct V_496 * V_497 )
{
T_4 V_142 ;
struct V_498 * V_331 ;
struct V_140 * V_143 ;
struct V_288 * V_279 ;
struct V_318 * V_280 ;
struct V_1 * V_2 ;
struct V_297 * V_499 ;
struct V_500 V_501 ;
struct V_444 V_445 ;
struct V_144 * V_145 ;
struct V_502 V_503 ;
T_3 V_504 ;
int V_136 ;
int V_349 ;
struct V_486 * V_487 ;
struct V_505 * V_506 = NULL ;
struct V_507 V_508 ;
struct V_509 * V_510 ;
T_4 V_511 ;
T_1 V_512 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
V_331 = F_144 ( V_7 -> V_457 , V_497 -> V_513 ) ;
if ( ! V_331 )
return - V_43 ;
V_143 = F_145 ( V_331 ) ;
V_279 = F_138 ( V_143 -> V_331 . V_457 ) ;
V_280 = V_279 -> V_280 ;
V_499 = V_280 -> V_298 ;
V_2 = (struct V_1 * ) V_7 -> V_483 ;
F_7 ( V_14 , L_122
L_123 , V_2 , V_279 , V_279 -> V_86 ,
V_279 -> V_86 -> V_514 ) ;
if ( V_277 == V_2 -> V_32 ) {
if ( V_2 -> V_275 )
F_4 ( V_2 -> V_3 , V_2 -> V_275 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_349 = F_116 ( 1 , & V_2 -> V_349 ) ;
if ( V_349 == V_385 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_464 ;
}
V_143 -> V_2 = ( void * ) V_2 ;
V_2 -> V_143 = V_143 ;
F_7 ( V_14 , L_124 ,
V_143 -> V_146 . V_205 , V_2 , V_182 , V_2 -> V_266 ) ;
F_38 ( & V_515 ) ;
F_7 ( V_14 , L_120 ,
F_141 ( V_279 -> V_86 ) ) ;
V_143 -> V_493 = sizeof( struct V_36 ) ;
V_143 -> V_489 = F_146 ( V_280 -> V_281 ,
V_143 -> V_493 + V_497 -> V_377 ,
& V_143 -> V_494 ) ;
if ( ! V_143 -> V_489 ) {
F_7 ( V_14 , L_125 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_143 -> V_489 ;
if ( V_2 -> V_48 == V_46 )
V_512 = 4 ;
memcpy ( V_37 -> V_516 , V_497 -> V_378 ,
V_497 -> V_377 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_143 -> V_489 , V_28 ) ;
V_143 -> V_377 = V_497 -> V_377 ;
V_145 = & V_143 -> V_146 . V_147 [ 0 ] ;
if ( V_7 -> V_480 . V_517 . V_518 !=
V_7 -> V_479 . V_517 . V_518 ) {
V_142 = ( unsigned long ) V_143 ;
V_487 = V_279 -> V_487 ;
V_510 = V_143 -> V_510 ;
V_508 . V_519 = V_143 -> V_494 + V_512 ;
V_508 . V_520 = V_20 ;
V_511 = ( T_4 ) ( unsigned long ) * V_19 ;
V_506 = V_487 -> V_491 . V_521 ( (struct V_522 * ) V_510 ,
& V_508 , 1 ,
V_523 ,
& V_511 ) ;
if ( ! V_506 ) {
F_7 ( V_14 , L_126
L_127 ,
V_2 ) ;
F_142 ( V_280 -> V_281 ,
V_143 -> V_377 + V_143 -> V_493 ,
V_143 -> V_489 , V_143 -> V_494 ) ;
return - V_27 ;
}
V_506 -> V_524 = & V_510 -> V_525 ;
V_506 -> V_457 = V_510 -> V_525 . V_457 ;
V_143 -> V_490 = V_506 ;
V_142 |= V_148 >> 1 ;
F_30 ( V_145 -> V_149 ,
V_150 ,
V_142 ) ;
V_145 -> V_149 [ V_153 ] =
F_31 ( V_526 |
V_527 ) ;
V_145 -> V_149 [ V_155 ] =
F_31 ( V_20 ) ;
F_30 ( V_145 -> V_149 ,
V_151 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_145 -> V_149 [ V_156 ] =
F_31 ( V_20 ) ;
V_145 -> V_149 [ V_157 ] = V_506 -> V_528 ;
if ( V_143 -> V_163 ) {
V_143 -> V_163 = 0 ;
F_33 ( V_143 -> V_164 ) ;
}
V_143 -> V_165 -> V_166 |=
F_31 ( V_167 |
V_168 ) ;
} else {
V_143 -> V_165 -> V_166 |=
F_31 ( V_168 ) ;
}
V_143 -> V_170 = 1 ;
V_143 -> V_7 = V_7 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_483 = V_143 ;
V_143 -> V_488 = 0 ;
if ( V_2 -> V_32 == V_225 )
F_7 ( V_14 , L_128 ,
V_2 ) ;
F_132 ( V_143 , V_2 ) ;
V_143 -> V_165 -> V_529 [ 0 ] =
F_147 ( F_16 ( V_7 -> V_479 . V_530 ) ) ;
V_143 -> V_165 -> V_529 [ 1 ] =
F_147 ( F_16 ( V_7 -> V_480 . V_530 ) ) ;
V_143 -> V_165 -> V_531 =
F_31 ( F_36 ( V_7 -> V_480 . V_517 . V_518 ) ) ;
V_143 -> V_165 -> V_417 |= F_31 (
( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) <<
V_532 ) ;
V_143 -> V_165 -> V_533 |=
F_31 ( F_83 ( V_280 ,
F_133 ( V_143 -> V_165 -> V_531 ) , NULL ,
V_313 ) << 16 ) ;
V_143 -> V_165 -> V_534 = F_31 (
V_182 - F_148 ( V_280 , V_535 ) ) ;
V_143 -> V_165 -> V_536 = F_31 ( V_143 -> V_146 . V_205 ) ;
V_143 -> V_165 -> V_166 |= F_31 (
( ( T_3 ) 1 << V_537 ) ) ;
V_143 -> V_165 -> V_166 |=
F_31 ( ( T_3 ) V_497 -> V_538 ) ;
memset ( & V_503 , 0 , sizeof( V_503 ) ) ;
V_503 . V_539 =
F_31 ( ( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) << 24 ) ;
V_503 . V_540 = V_7 -> V_480 . V_517 . V_518 ;
V_503 . V_541 [ 0 ] = V_7 -> V_480 . V_530 ;
V_503 . V_541 [ 1 ] = V_7 -> V_479 . V_530 ;
V_504 = F_149 ( & V_503 ) ;
V_143 -> V_542 = F_120 ( V_504 ^ 0xffffffff ) ;
F_7 ( V_14 , L_129 ,
V_143 -> V_542 , V_143 -> V_542 & V_499 -> V_543 ) ;
V_143 -> V_542 &= V_499 -> V_543 ;
V_143 -> V_165 -> V_542 = F_31 ( V_143 -> V_542 ) ;
V_2 -> V_3 -> V_403 -> V_272 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_130
L_131
L_132 , V_143 -> V_146 . V_205 ,
F_36 ( V_7 -> V_480 . V_517 . V_518 ) ,
F_16 ( V_7 -> V_480 . V_530 ) ,
F_36 ( V_7 -> V_479 . V_517 . V_518 ) ,
F_16 ( V_7 -> V_479 . V_530 ) ,
F_133 ( V_143 -> V_165 -> V_116 ) ,
F_133 ( V_143 -> V_165 -> V_430 ) ,
V_20 ) ;
V_7 -> V_386 ( V_7 ) ;
F_134 ( & V_143 -> V_331 ) ;
V_445 . V_6 = V_544 ;
V_445 . V_478 = 0 ;
V_445 . V_483 = ( void * ) V_143 ;
V_445 . V_479 = V_7 -> V_479 ;
V_445 . V_480 = V_7 -> V_480 ;
V_445 . V_378 = NULL ;
V_445 . V_377 = 0 ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
V_501 . V_545 = V_462 ;
F_150 ( & V_143 -> V_331 , & V_501 , V_546 , NULL ) ;
if ( V_2 -> V_275 ) {
V_2 -> V_275 -> V_54 =
V_143 -> V_377 ;
memcpy ( V_2 -> V_275 -> V_69 ,
V_497 -> V_378 , V_497 -> V_377 ) ;
F_5 ( V_2 -> V_275 , V_357 ) ;
}
if ( V_136 )
F_78 ( V_300 L_133
L_134 , V_301 , __LINE__ , V_136 ) ;
return 0 ;
}
int F_151 ( struct V_194 * V_7 , const void * V_547 , T_1 V_548 )
{
struct V_1 * V_2 ;
struct V_1 * V_274 ;
struct V_130 * V_3 ;
T_1 * V_19 ;
F_38 ( & V_549 ) ;
V_2 = (struct V_1 * ) V_7 -> V_483 ;
V_274 = V_2 -> V_275 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_548 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_274 ) {
memcpy ( & V_274 -> V_25 . V_516 , V_547 , V_548 ) ;
V_274 -> V_25 . V_41 = V_548 ;
V_274 -> V_54 = V_548 ;
} else {
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_548 ;
memcpy ( V_19 , V_547 , V_548 ) ;
}
return V_3 -> V_403 -> V_550 ( V_3 , V_2 ) ;
}
int F_152 ( struct V_194 * V_7 , struct V_496 * V_497 )
{
struct V_498 * V_331 ;
struct V_140 * V_143 ;
struct V_288 * V_279 ;
struct V_318 * V_280 ;
struct V_1 * V_2 ;
struct V_314 V_9 ;
int V_328 = 0 ;
V_331 = F_144 ( V_7 -> V_457 , V_497 -> V_513 ) ;
if ( ! V_331 )
return - V_43 ;
V_143 = F_145 ( V_331 ) ;
if ( ! V_143 )
return - V_43 ;
V_279 = F_138 ( V_143 -> V_331 . V_457 ) ;
if ( ! V_279 )
return - V_43 ;
V_280 = V_279 -> V_280 ;
if ( ! V_280 )
return - V_43 ;
if ( ! ( V_7 -> V_479 . V_530 ) || ! ( V_7 -> V_480 . V_530 ) )
return - V_43 ;
F_7 ( V_14 , L_135
L_136 , V_143 -> V_146 . V_205 ,
F_36 ( V_279 -> V_383 ) ,
F_36 ( V_7 -> V_480 . V_517 . V_518 ) ,
F_16 ( V_7 -> V_480 . V_530 ) ,
F_36 ( V_7 -> V_479 . V_517 . V_518 ) ,
F_16 ( V_7 -> V_479 . V_530 ) ) ;
F_38 ( & V_551 ) ;
V_143 -> V_488 = 1 ;
V_143 -> V_7 = V_7 ;
V_7 -> V_483 = V_143 ;
V_143 -> V_377 = V_497 -> V_377 ;
V_143 -> V_165 -> V_166 |= F_31 ( ( T_3 ) V_497 -> V_538 ) ;
if ( V_497 -> V_538 == 0 )
V_143 -> V_165 -> V_166 |= F_31 ( 1 ) ;
F_7 ( V_14 , L_137 , ( T_3 ) V_497 -> V_538 ) ;
F_7 ( V_14 , L_138 ,
V_497 -> V_377 ) ;
if ( V_7 -> V_479 . V_517 . V_518 !=
V_7 -> V_480 . V_517 . V_518 ) {
F_70 ( V_279 , F_16 ( V_7 -> V_479 . V_530 ) ,
F_71 ( V_280 -> V_281 -> V_282 ) , V_552 ) ;
V_328 = 1 ;
}
V_9 . V_11 = F_23 ( V_7 -> V_479 . V_517 . V_518 ) ;
V_9 . V_13 = F_22 ( V_7 -> V_479 . V_530 ) ;
V_9 . V_10 = F_23 ( V_7 -> V_480 . V_517 . V_518 ) ;
V_9 . V_12 = F_22 ( V_7 -> V_480 . V_530 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_327 = V_553 ;
V_7 -> V_386 ( V_7 ) ;
V_2 = V_219 -> V_403 -> V_554 ( V_219 , V_279 ,
V_497 -> V_377 , ( void * ) V_497 -> V_378 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_328 )
F_70 ( V_279 , F_16 ( V_7 -> V_479 . V_530 ) ,
F_71 ( V_280 -> V_281 -> V_282 ) ,
V_283 ) ;
V_7 -> V_200 ( V_7 ) ;
return - V_27 ;
}
V_2 -> V_328 = V_328 ;
V_143 -> V_2 = V_2 ;
V_2 -> V_143 = V_143 ;
F_134 ( & V_143 -> V_331 ) ;
return 0 ;
}
int F_153 ( struct V_194 * V_7 , int V_359 )
{
struct V_288 * V_279 ;
struct V_257 * V_2 ;
struct V_314 V_9 ;
int V_268 ;
F_7 ( V_14 , L_139 ,
V_7 , F_16 ( V_7 -> V_479 . V_530 ) ) ;
V_279 = F_138 ( V_7 -> V_457 ) ;
if ( ! V_279 )
return - V_43 ;
F_7 ( V_14 , L_140 ,
V_279 , V_279 -> V_86 , V_279 -> V_86 -> V_514 ) ;
F_7 ( V_14 , L_141 ,
V_279 -> V_383 , V_7 -> V_479 . V_517 . V_518 ) ;
V_9 . V_11 = V_279 -> V_383 ;
V_9 . V_13 = V_7 -> V_479 . V_530 ;
V_9 . V_359 = V_359 ;
V_9 . V_7 = V_7 ;
V_9 . V_327 = V_553 ;
V_2 = V_219 -> V_403 -> V_555 ( V_219 , V_279 , & V_9 ) ;
if ( ! V_2 ) {
F_78 ( V_300 L_142 ,
V_301 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_483 = V_2 ;
if ( ! V_2 -> V_375 ) {
V_268 = F_70 ( V_279 ,
F_16 ( V_7 -> V_479 . V_530 ) ,
F_71 ( V_279 -> V_280 -> V_281 -> V_282 ) ,
V_552 ) ;
if ( V_268 ) {
F_78 ( V_300 L_143 ,
V_268 ) ;
V_219 -> V_403 -> V_556 ( V_219 , ( void * ) V_2 ) ;
return V_268 ;
}
F_38 ( & V_557 ) ;
}
V_7 -> V_386 ( V_7 ) ;
V_7 -> V_483 = ( void * ) V_2 ;
return 0 ;
}
int F_154 ( struct V_194 * V_7 )
{
if ( V_7 -> V_483 )
V_219 -> V_403 -> V_556 ( V_219 , V_7 -> V_483 ) ;
else
F_7 ( V_14 , L_144 ) ;
V_7 -> V_200 ( V_7 ) ;
return 0 ;
}
int F_155 ( struct V_15 * V_16 , struct V_296 * V_558 )
{
int V_295 = 0 ;
V_559 ++ ;
if ( ( V_219 ) && ( V_219 -> V_403 ) )
V_295 = V_219 -> V_403 -> V_560 ( V_219 , F_156 ( V_558 ) , V_16 ) ;
else
F_7 ( V_14 , L_145
L_146 ) ;
return V_295 ;
}
int F_157 ( void )
{
F_7 ( V_14 , L_103 ) ;
V_219 = F_123 () ;
if ( V_219 )
return 0 ;
else
return - V_27 ;
}
int F_158 ( void )
{
V_219 -> V_403 -> V_561 ( V_219 ) ;
return 0 ;
}
static void F_159 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_288 * V_279 ;
struct V_318 * V_280 ;
struct V_1 * V_2 ;
struct V_297 * V_298 ;
struct V_500 V_501 ;
struct V_194 * V_7 ;
struct V_444 V_445 ;
struct V_502 V_503 ;
T_3 V_504 ;
int V_136 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_147 , V_2 , V_7 ) ;
V_143 = (struct V_140 * ) V_7 -> V_483 ;
V_279 = F_138 ( V_143 -> V_331 . V_457 ) ;
V_280 = V_279 -> V_280 ;
V_298 = V_280 -> V_298 ;
if ( V_143 -> V_467 )
return;
F_38 ( & V_562 ) ;
F_7 ( V_14 , L_148
L_149 ,
V_143 -> V_146 . V_205 ,
F_36 ( V_7 -> V_480 . V_517 . V_518 ) ,
F_16 ( V_7 -> V_480 . V_530 ) ,
F_16 ( V_7 -> V_479 . V_530 ) ,
V_182 ) ;
F_132 ( V_143 , V_2 ) ;
V_143 -> V_165 -> V_529 [ 0 ] =
F_147 ( F_16 ( V_7 -> V_479 . V_530 ) ) ;
V_143 -> V_165 -> V_529 [ 1 ] =
F_147 ( F_16 ( V_7 -> V_480 . V_530 ) ) ;
V_143 -> V_165 -> V_531 =
F_31 ( F_36 ( V_7 -> V_480 . V_517 . V_518 ) ) ;
V_143 -> V_165 -> V_417 |= F_31 (
( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) <<
V_532 ) ;
V_143 -> V_165 -> V_533 |= F_31 (
F_83 ( V_280 ,
F_133 ( V_143 -> V_165 -> V_531 ) ,
NULL , V_313 ) << 16 ) ;
V_143 -> V_165 -> V_534 = F_31 (
V_182 - F_148 ( V_280 , V_535 ) ) ;
V_143 -> V_165 -> V_536 = F_31 ( V_143 -> V_146 . V_205 ) ;
V_143 -> V_165 -> V_166 |=
F_31 ( ( T_3 ) 1 <<
V_537 ) ;
F_29 ( V_2 , & V_143 ) ;
F_160 ( V_280 -> V_563 + V_564 ,
( 1 << 24 ) | 0x00800000 | V_143 -> V_146 . V_205 ) ;
memset ( & V_503 , 0 , sizeof( V_503 ) ) ;
V_503 . V_539 =
F_31 ( ( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) << 24 ) ;
V_503 . V_540 = V_7 -> V_480 . V_517 . V_518 ;
V_503 . V_541 [ 0 ] = V_7 -> V_480 . V_530 ;
V_503 . V_541 [ 1 ] = V_7 -> V_479 . V_530 ;
V_504 = F_149 ( & V_503 ) ;
V_143 -> V_542 = F_120 ( V_504 ^ 0xffffffff ) ;
F_7 ( V_14 , L_150 ,
V_143 -> V_542 , V_143 -> V_542 & V_298 -> V_543 ) ;
V_143 -> V_542 &= V_298 -> V_543 ;
V_143 -> V_165 -> V_542 = F_31 ( V_143 -> V_542 ) ;
V_143 -> V_489 = & V_2 -> V_25 ;
V_143 -> V_377 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_403 -> V_272 ( V_2 -> V_3 , V_2 ) ;
V_445 . V_6 = V_565 ;
V_445 . V_478 = 0 ;
V_445 . V_483 = V_7 -> V_483 ;
V_445 . V_479 . V_566 = V_567 ;
V_445 . V_479 . V_530 = V_7 -> V_479 . V_530 ;
V_445 . V_480 = V_7 -> V_480 ;
V_445 . V_378 = ( void * ) V_6 -> V_2 -> V_69 ;
V_445 . V_377 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_445 . V_568 = V_2 -> V_55 ;
V_445 . V_538 = V_2 -> V_56 ;
V_445 . V_479 . V_517 . V_518 = V_6 -> V_9 . V_10 ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
if ( V_136 )
F_78 ( V_300 L_133
L_134 , V_301 , __LINE__ , V_136 ) ;
V_501 . V_545 = V_462 ;
F_150 ( & V_143 -> V_331 , & V_501 , V_546 , NULL ) ;
F_7 ( V_14 , L_151
L_152 , V_143 -> V_146 . V_205 , V_182 ) ;
return;
}
static void F_66 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_194 * V_7 ;
struct V_444 V_445 ;
int V_136 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_153 , V_6 -> V_2 , V_7 ) ;
V_143 = V_7 -> V_483 ;
if ( ! V_143 )
return;
V_143 -> V_7 = NULL ;
V_7 -> V_483 = NULL ;
V_445 . V_6 = V_565 ;
V_445 . V_478 = - V_464 ;
V_445 . V_483 = V_7 -> V_483 ;
V_445 . V_479 = V_7 -> V_479 ;
V_445 . V_480 = V_7 -> V_480 ;
V_445 . V_378 = NULL ;
V_445 . V_377 = 0 ;
F_7 ( V_14 , L_154
L_155 , V_445 . V_479 . V_517 . V_518 ,
V_445 . V_480 . V_517 . V_518 ) ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
if ( V_136 )
F_78 ( V_300 L_133
L_134 , V_301 , __LINE__ , V_136 ) ;
V_7 -> V_200 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_161 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_194 * V_7 ;
struct V_444 V_445 ;
int V_136 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_156 , V_6 -> V_2 , V_7 ) ;
V_143 = V_7 -> V_483 ;
if ( ! V_143 )
return;
V_143 -> V_7 = NULL ;
V_445 . V_6 = V_477 ;
V_445 . V_478 = - V_464 ;
V_445 . V_483 = V_7 -> V_483 ;
V_445 . V_479 = V_7 -> V_479 ;
V_445 . V_480 = V_7 -> V_480 ;
V_445 . V_378 = NULL ;
V_445 . V_377 = 0 ;
V_7 -> V_386 ( V_7 ) ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
F_38 ( & V_482 ) ;
V_445 . V_6 = V_484 ;
V_445 . V_478 = 0 ;
V_445 . V_483 = V_7 -> V_483 ;
V_445 . V_479 = V_7 -> V_479 ;
V_445 . V_480 = V_7 -> V_480 ;
V_445 . V_378 = NULL ;
V_445 . V_377 = 0 ;
F_7 ( V_14 , L_157 , V_6 -> V_2 ) ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
V_7 -> V_200 ( V_7 ) ;
return;
}
static void F_162 ( struct V_4 * V_6 )
{
struct V_194 * V_7 ;
struct V_444 V_445 ;
int V_136 ;
struct V_1 * V_2 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_569 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_182 ) ;
V_445 . V_6 = V_570 ;
V_445 . V_478 = 0 ;
V_445 . V_483 = ( void * ) V_2 ;
V_445 . V_479 . V_566 = V_567 ;
V_445 . V_479 . V_530 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_445 . V_479 . V_517 . V_518 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_445 . V_480 . V_566 = V_567 ;
V_445 . V_480 . V_530 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_445 . V_480 . V_517 . V_518 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_445 . V_378 = V_2 -> V_69 ;
V_445 . V_377 = ( T_1 ) V_2 -> V_54 ;
V_445 . V_568 = V_2 -> V_55 ;
V_445 . V_538 = V_2 -> V_56 ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
if ( V_136 )
F_78 ( V_300 L_159 ,
V_301 , __LINE__ , V_136 ) ;
return;
}
static void F_117 ( struct V_4 * V_6 )
{
struct V_194 * V_7 ;
struct V_444 V_445 ;
struct V_1 * V_2 ;
int V_136 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_569 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_182 ) ;
V_445 . V_6 = V_565 ;
V_445 . V_478 = - V_571 ;
V_445 . V_483 = V_7 -> V_483 ;
V_445 . V_479 . V_566 = V_567 ;
V_445 . V_479 . V_530 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_445 . V_479 . V_517 . V_518 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_445 . V_480 . V_566 = V_567 ;
V_445 . V_480 . V_530 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_445 . V_480 . V_517 . V_518 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_445 . V_378 = V_2 -> V_69 ;
V_445 . V_377 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_160
L_155 ,
V_445 . V_479 . V_517 . V_518 ,
V_445 . V_480 . V_517 . V_518 ) ;
V_136 = V_7 -> V_474 ( V_7 , & V_445 ) ;
if ( V_136 )
F_78 ( V_300 L_159 ,
V_301 , __LINE__ , V_136 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_38 ( & V_6 -> V_2 -> V_3 -> V_402 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_386 ( V_6 -> V_9 . V_7 ) ;
F_135 ( & V_6 -> V_572 , V_573 ) ;
F_7 ( V_14 , L_161 ,
V_6 -> V_2 , V_6 ) ;
F_136 ( V_6 -> V_2 -> V_3 -> V_405 , & V_6 -> V_572 ) ;
F_7 ( V_14 , L_162 ) ;
return 0 ;
}
static void V_573 ( struct V_442 * V_440 )
{
struct V_4 * V_6 = F_52 ( V_440 , struct V_4 ,
V_572 ) ;
struct V_130 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_163 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_402 ) ) ;
switch ( V_6 -> type ) {
case V_354 :
F_162 ( V_6 ) ;
F_7 ( V_14 , L_164 ,
V_6 -> V_2 ) ;
break;
case V_574 :
F_7 ( V_14 , L_165 ,
V_6 -> V_2 ) ;
F_161 ( V_6 ) ;
break;
case V_357 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_225 ) )
break;
F_159 ( V_6 ) ;
F_7 ( V_14 , L_166 ) ;
break;
case V_356 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_225 ) )
break;
F_117 ( V_6 ) ;
F_7 ( V_14 , L_167 ) ;
break;
case V_201 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_225 ) )
break;
F_66 ( V_6 ) ;
F_7 ( V_14 , L_168 ) ;
break;
case V_575 :
F_7 ( V_14 , L_169 ) ;
break;
default:
F_7 ( V_14 , L_170 ) ;
break;
}
F_69 ( & V_3 -> V_402 ) ;
V_6 -> V_9 . V_7 -> V_200 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_34 ( V_6 ) ;
return;
}
