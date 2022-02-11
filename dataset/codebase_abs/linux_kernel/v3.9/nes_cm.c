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
V_86 = F_80 ( V_279 -> V_86 ) ;
else
V_86 = V_279 -> V_86 ;
V_294 = F_81 ( & V_302 , & V_292 -> V_303 , V_86 ) ;
F_82 () ;
if ( V_294 ) {
if ( V_294 -> V_304 & V_305 ) {
F_7 ( V_14 , L_51
L_52 , V_289 ,
V_294 -> V_306 , F_36 ( V_292 -> V_303 ) ) ;
if ( V_290 >= 0 ) {
if ( ! memcmp ( V_298 -> V_307 [ V_290 ] . V_308 ,
V_294 -> V_306 , V_95 ) ) {
goto V_309;
}
F_83 ( V_279 -> V_86 ,
V_298 -> V_307 [ V_290 ] . V_308 ,
V_289 , V_310 ) ;
}
F_83 ( V_279 -> V_86 , V_294 -> V_306 ,
V_289 , V_311 ) ;
V_295 = F_84 ( V_279 -> V_280 , V_289 , NULL ,
V_312 ) ;
} else {
F_85 ( V_294 , NULL ) ;
}
}
V_309:
F_86 () ;
if ( V_294 )
F_87 ( V_294 ) ;
F_88 ( V_292 ) ;
return V_295 ;
}
static struct V_1 * F_89 ( struct V_130 * V_3 ,
struct V_288 * V_279 , struct V_313 * V_9 ,
struct V_257 * V_266 )
{
struct V_1 * V_2 ;
struct V_314 V_315 ;
int V_316 = 0 ;
int V_290 = 0 ;
struct V_317 * V_280 ;
struct V_297 * V_298 ;
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
V_2 -> V_266 = V_266 ;
V_2 -> V_86 = V_279 -> V_86 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_97 , V_279 -> V_86 -> V_319 , V_95 ) ;
F_7 ( V_14 , L_54 , V_2 -> V_266 ,
V_2 -> V_7 ) ;
F_90 ( & V_2 -> V_188 ) ;
V_2 -> V_275 = NULL ;
F_91 ( & V_2 -> V_264 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_105 . V_106 = V_320 ;
V_2 -> V_105 . V_248 = V_321 ;
V_2 -> V_105 . V_126 = V_322 >>
V_321 ;
V_315 = F_92 () ;
V_2 -> V_105 . V_114 = F_23 ( V_315 . V_323 ) ;
V_2 -> V_105 . V_244 = V_279 -> V_324 - sizeof( struct V_77 ) -
sizeof( struct V_75 ) - V_83 - V_325 ;
V_2 -> V_105 . V_116 = 0 ;
F_38 ( & V_3 -> V_133 ) ;
V_2 -> V_326 = V_9 -> V_326 ;
V_2 -> V_327 = 0 ;
V_2 -> V_287 = 0 ;
V_2 -> V_279 = V_279 ;
V_280 = V_279 -> V_280 ;
V_298 = V_280 -> V_298 ;
V_2 -> V_275 = NULL ;
V_316 = F_84 ( V_280 , V_2 -> V_10 , NULL , V_312 ) ;
V_290 = F_75 ( V_279 , V_9 -> V_10 , V_316 ) ;
if ( V_290 < 0 ) {
F_34 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_94 , V_298 -> V_307 [ V_290 ] . V_308 , V_95 ) ;
F_7 ( V_14 , L_55 ,
V_2 -> V_94 ) ;
F_63 ( V_3 , V_2 ) ;
F_38 ( & V_328 ) ;
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
if ( V_2 -> V_327 && V_2 -> V_279 ) {
F_70 ( V_2 -> V_279 , V_2 -> V_13 ,
F_71 (
V_2 -> V_279 -> V_280 -> V_281 -> V_282 ) ,
V_283 ) ;
}
}
F_69 ( & V_3 -> V_133 ) ;
F_38 ( & V_329 ) ;
V_143 = V_2 -> V_143 ;
if ( V_143 ) {
V_143 -> V_2 = NULL ;
F_93 ( & V_143 -> V_330 ) ;
V_2 -> V_143 = NULL ;
}
F_34 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , T_1 * V_331 ,
T_3 V_72 , T_3 V_332 )
{
T_3 V_333 ;
T_3 V_334 = 0 ;
union V_239 * V_335 ;
char V_336 = 0 ;
while ( V_334 < V_72 ) {
V_335 = (union V_239 * ) ( V_331 + V_334 ) ;
switch ( V_335 -> V_251 . V_241 ) {
case V_254 :
V_334 = V_72 ;
break;
case V_337 :
V_334 += 1 ;
continue;
case V_242 :
F_7 ( V_14 , L_56
L_57 , V_301 ,
V_335 -> V_240 . V_243 , V_334 , V_72 ) ;
V_336 = 1 ;
if ( V_335 -> V_240 . V_243 != 4 ) {
return 1 ;
} else {
V_333 = F_16 ( V_335 -> V_240 . V_244 ) ;
if ( V_333 > 0 && V_333 <
V_2 -> V_105 . V_244 )
V_2 -> V_105 . V_244 = V_333 ;
}
break;
case V_246 :
V_2 -> V_105 . V_338 =
V_335 -> V_245 . V_247 ;
break;
default:
F_7 ( V_14 , L_58 ,
V_335 -> V_251 . V_241 ) ;
break;
}
V_334 += V_335 -> V_251 . V_243 ;
}
if ( ( ! V_336 ) && ( V_332 ) )
V_2 -> V_105 . V_244 = V_339 ;
return 0 ;
}
static void F_95 ( struct V_15 * V_16 )
{
F_38 ( & V_340 ) ;
F_96 ( V_16 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_59
L_46 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_264 ) ) ;
switch ( V_2 -> V_32 ) {
case V_197 :
case V_341 :
case V_342 :
case V_343 :
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
case V_344 :
V_2 -> V_105 . V_116 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_345 ;
F_58 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_183 , 1 , 0 ) ;
break;
case V_345 :
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
static void F_98 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_346 = 0 ;
F_38 ( & V_347 ) ;
F_7 ( V_14 , L_61
L_62 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_264 ) ) ;
F_42 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_341 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_301 , __LINE__ , V_2 ,
V_2 -> V_266 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_341 ;
if ( F_57 ( V_2 , 0 , NULL ) ) {
F_99 ( V_2 , V_16 , V_346 ) ;
}
break;
case V_46 :
default:
F_99 ( V_2 , V_16 , V_346 ) ;
break;
}
break;
case V_278 :
F_38 ( & V_2 -> V_348 ) ;
F_96 ( V_16 ) ;
break;
case V_342 :
case V_197 :
case V_349 :
F_7 ( V_14 , L_65 , V_301 , __LINE__ ) ;
F_100 ( V_2 , V_16 , V_346 ) ;
break;
case V_225 :
F_99 ( V_2 , V_16 , V_346 ) ;
break;
case V_196 :
F_95 ( V_16 ) ;
break;
case V_344 :
case V_33 :
case V_199 :
V_2 -> V_7 -> V_200 ( V_2 -> V_7 ) ;
case V_345 :
V_2 -> V_32 = V_196 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_95 ( V_16 ) ;
break;
default:
F_95 ( V_16 ) ;
break;
}
}
static void F_101 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_136 = 0 ;
int V_74 = V_16 -> V_35 ;
T_1 * V_350 = V_16 -> V_73 ;
enum V_5 type = V_351 ;
T_3 V_352 ;
V_136 = F_15 ( V_2 , V_350 , & V_352 , V_74 ) ;
if ( V_136 ) {
F_7 ( V_14 , L_66 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_67
L_68 , V_301 ,
__LINE__ , V_2 , V_2 -> V_266 ,
V_2 -> V_32 ) ;
F_99 ( V_2 , V_16 , 1 ) ;
} else {
F_100 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_342 :
if ( V_352 == V_70 )
F_35 ( 1 ) ;
V_2 -> V_32 = V_278 ;
type = V_353 ;
F_91 ( & V_2 -> V_348 ,
V_354 ) ;
break;
case V_49 :
F_42 ( V_2 ) ;
if ( V_352 == V_70 ) {
type = V_355 ;
V_2 -> V_32 = V_343 ;
} else {
type = V_356 ;
V_2 -> V_32 = V_225 ;
}
break;
default:
F_35 ( 1 ) ;
break;
}
F_96 ( V_16 ) ;
F_5 ( V_2 , type ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_2 -> V_32 ) {
case V_341 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_301 , __LINE__ , V_2 ,
V_2 -> V_266 , V_2 -> V_32 ) ;
F_99 ( V_2 , V_16 , 1 ) ;
break;
case V_342 :
case V_197 :
F_100 ( V_2 , V_16 , 1 ) ;
break;
case V_225 :
default:
F_95 ( V_16 ) ;
}
}
static int F_103 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 )
{
int V_268 ;
V_268 = ( ( F_36 ( V_76 -> V_117 ) == V_2 -> V_105 . V_114 ) ) ? 0 : 1 ;
if ( V_268 )
F_99 ( V_2 , V_16 , 1 ) ;
return V_268 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_75 * V_76 ,
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
else if ( ! F_105 ( V_113 , V_116 , ( V_116 + V_126 ) ) )
V_268 = 1 ;
if ( V_268 ) {
F_7 ( V_14 , L_63
L_64 , V_301 , __LINE__ , V_2 ,
V_2 -> V_266 , V_2 -> V_32 ) ;
F_102 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_69
L_70 , V_2 , V_113 , V_116 ,
V_126 ) ;
}
return V_268 ;
}
static void F_106 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_136 ;
T_3 V_357 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_357 = F_36 ( V_76 -> V_113 ) ;
switch ( V_2 -> V_32 ) {
case V_341 :
case V_49 :
F_99 ( V_2 , V_16 , 1 ) ;
break;
case V_349 :
if ( F_26 ( & V_2 -> V_266 -> V_285 ) >
V_2 -> V_266 -> V_358 ) {
F_7 ( V_14 , L_71
L_72 ) ;
V_359 ++ ;
F_100 ( V_2 , V_16 , 0 ) ;
break;
}
V_136 = F_107 ( V_2 , V_76 , V_16 , V_72 ,
1 ) ;
if ( V_136 ) {
F_100 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_105 . V_116 = V_357 + 1 ;
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
case V_342 :
case V_33 :
case V_344 :
case V_278 :
case V_199 :
case V_198 :
case V_360 :
default:
F_95 ( V_16 ) ;
break;
}
}
static void F_108 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_136 ;
T_3 V_357 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
F_17 ( V_16 , 0 ) ;
V_357 = F_36 ( V_76 -> V_113 ) ;
switch ( V_2 -> V_32 ) {
case V_341 :
F_42 ( V_2 ) ;
if ( F_103 ( V_2 , V_76 , V_16 ) )
return;
V_2 -> V_105 . V_228 = F_36 ( V_76 -> V_117 ) ;
V_136 = F_107 ( V_2 , V_76 , V_16 , V_72 , 0 ) ;
if ( V_136 ) {
F_7 ( V_14 , L_73 ,
V_2 ) ;
break;
}
F_42 ( V_2 ) ;
V_2 -> V_105 . V_116 = V_357 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_278 :
F_100 ( V_2 , V_16 , 1 ) ;
break;
case V_349 :
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
case V_342 :
case V_33 :
case V_344 :
case V_199 :
case V_225 :
case V_198 :
case V_360 :
case V_49 :
default:
F_95 ( V_16 ) ;
break;
}
}
static int F_109 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_75 * V_76 )
{
int V_74 = 0 ;
T_3 V_357 ;
int V_136 = 0 ;
int V_72 ;
V_72 = ( V_76 -> V_124 << 2 ) - sizeof( struct V_75 ) ;
if ( F_104 ( V_2 , V_76 , V_16 ) )
return - V_43 ;
F_110 ( V_16 , V_76 -> V_124 << 2 ) ;
V_357 = F_36 ( V_76 -> V_113 ) ;
V_74 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_197 :
F_42 ( V_2 ) ;
V_136 = F_107 ( V_2 , V_76 , V_16 , V_72 , 1 ) ;
if ( V_136 )
break;
V_2 -> V_105 . V_228 = F_36 ( V_76 -> V_117 ) ;
V_2 -> V_32 = V_342 ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_357 + V_74 ;
F_101 ( V_2 , V_16 ) ;
} else {
F_96 ( V_16 ) ;
}
break;
case V_342 :
F_42 ( V_2 ) ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_357 + V_74 ;
F_101 ( V_2 , V_16 ) ;
} else {
F_95 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_105 . V_228 = F_36 ( V_76 -> V_117 ) ;
if ( V_74 ) {
V_2 -> V_105 . V_116 = V_357 + V_74 ;
F_101 ( V_2 , V_16 ) ;
} else {
F_96 ( V_16 ) ;
}
break;
case V_349 :
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
F_95 ( V_16 ) ;
break;
case V_33 :
F_42 ( V_2 ) ;
F_95 ( V_16 ) ;
V_2 -> V_32 = V_344 ;
break;
case V_341 :
case V_344 :
case V_225 :
case V_278 :
case V_360 :
default:
F_42 ( V_2 ) ;
F_95 ( V_16 ) ;
break;
}
return V_136 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_15 * V_16 , int V_72 , int V_361 )
{
T_1 * V_331 = ( T_1 * ) & V_76 [ 1 ] ;
if ( V_72 ) {
if ( F_94 ( V_2 , V_331 , V_72 ,
( T_3 ) V_76 -> V_120 ) ) {
F_7 ( V_14 , L_74 ,
V_301 , V_2 ) ;
if ( V_361 )
F_100 ( V_2 , V_16 , 1 ) ;
else
F_99 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_105 . V_362 = F_16 ( V_76 -> V_125 ) <<
V_2 -> V_105 . V_338 ;
if ( V_2 -> V_105 . V_362 > V_2 -> V_105 . V_363 )
V_2 -> V_105 . V_363 = V_2 -> V_105 . V_362 ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_346 )
{
F_42 ( V_2 ) ;
if ( V_346 ) {
F_7 ( V_14 , L_75
L_76 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
} else {
F_96 ( V_16 ) ;
}
V_2 -> V_32 = V_196 ;
F_5 ( V_2 , V_201 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_346 )
{
F_42 ( V_2 ) ;
V_2 -> V_32 = V_196 ;
if ( V_346 ) {
F_7 ( V_14 , L_77
L_78 , V_2 , V_2 -> V_32 ) ;
F_46 ( V_2 , V_16 ) ;
} else {
F_96 ( V_16 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_175 * V_189 ;
V_189 = V_2 -> V_189 ;
if ( V_189 ) {
V_2 -> V_189 = NULL ;
F_96 ( V_189 -> V_16 ) ;
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
static void F_111 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_130 * V_3 )
{
enum V_364 V_365 = V_366 ;
struct V_75 * V_76 = F_37 ( V_16 ) ;
T_3 V_367 = 0 ;
int V_136 = 0 ;
F_110 ( V_16 , F_112 ( V_16 ) -> V_101 << 2 ) ;
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 , V_76 -> V_120 ,
V_76 -> V_118 , V_76 -> V_123 , V_76 -> V_121 ) ;
if ( V_76 -> V_123 ) {
V_365 = V_368 ;
} else if ( V_76 -> V_120 ) {
V_365 = V_369 ;
if ( V_76 -> V_118 )
V_365 = V_370 ;
} else if ( V_76 -> V_118 ) {
V_365 = V_371 ;
}
if ( V_76 -> V_121 )
V_367 = 1 ;
switch ( V_365 ) {
case V_369 :
F_106 ( V_2 , V_16 , V_76 ) ;
break;
case V_370 :
F_108 ( V_2 , V_16 , V_76 ) ;
break;
case V_371 :
V_136 = F_109 ( V_2 , V_16 , V_76 ) ;
if ( V_367 && ! V_136 )
F_97 ( V_2 ) ;
break;
case V_368 :
F_98 ( V_2 , V_16 , V_76 ) ;
break;
default:
if ( ( V_367 ) && ( ! F_104 ( V_2 , V_76 , V_16 ) ) )
F_97 ( V_2 ) ;
F_95 ( V_16 ) ;
break;
}
}
static struct V_257 * F_113 ( struct V_130 * V_3 ,
struct V_288 * V_279 , struct V_313 * V_9 )
{
struct V_257 * V_266 ;
unsigned long V_29 ;
F_7 ( V_14 , L_81 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_266 = F_62 ( V_3 , F_23 ( V_9 -> V_11 ) ,
F_22 ( V_9 -> V_13 ) , V_372 ) ;
if ( V_266 && V_266 -> V_261 == V_373 ) {
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
V_266 -> V_374 = 0 ;
F_91 ( & V_266 -> V_264 , 1 ) ;
}
else {
V_266 -> V_374 = 1 ;
}
V_266 -> V_7 = V_9 -> V_7 ;
F_91 ( & V_266 -> V_285 , 0 ) ;
V_266 -> V_3 = V_3 ;
V_266 -> V_279 = V_279 ;
F_38 ( & V_3 -> V_133 ) ;
V_266 -> V_326 = V_9 -> V_326 ;
V_266 -> V_358 = V_9 -> V_358 ;
V_266 -> V_261 = V_373 ;
if ( ! V_266 -> V_374 ) {
F_39 ( & V_3 -> V_263 , V_29 ) ;
F_53 ( & V_266 -> V_223 , & V_3 -> V_375 . V_223 ) ;
F_40 ( & V_3 -> V_263 , V_29 ) ;
F_38 ( & V_3 -> V_132 ) ;
}
F_7 ( V_14 , L_84
L_85 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_266 , V_266 -> V_358 , V_266 -> V_7 ) ;
return V_266 ;
}
static struct V_1 * F_114 ( struct V_130 * V_3 ,
struct V_288 * V_279 , T_2 V_376 ,
void * V_377 , struct V_313 * V_9 )
{
int V_136 = 0 ;
struct V_1 * V_2 ;
struct V_257 * V_378 ;
struct V_1 * V_379 ;
struct V_313 V_380 ;
T_1 * V_19 ;
V_2 = F_89 ( V_3 , V_279 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_105 . V_381 = 1 ;
V_2 -> V_105 . V_248 = V_321 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_378 = F_62 ( V_3 ,
F_36 ( V_279 -> V_382 ) , V_2 -> V_12 ,
V_373 ) ;
if ( V_378 == NULL ) {
F_5 ( V_2 , V_201 ) ;
} else {
V_380 = * V_9 ;
V_380 . V_13 = V_9 -> V_12 ;
V_380 . V_12 = V_9 -> V_13 ;
V_380 . V_7 = V_378 -> V_7 ;
V_379 = F_89 ( V_3 , V_279 ,
& V_380 , V_378 ) ;
if ( ! V_379 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_38 ( & V_383 ) ;
V_379 -> V_275 = V_2 ;
V_379 -> V_105 . V_248 =
V_321 ;
V_2 -> V_275 = V_379 ;
memcpy ( V_379 -> V_69 , V_377 ,
V_376 ) ;
V_379 -> V_54 = V_376 ;
V_2 -> V_32 = V_225 ;
V_2 -> V_105 . V_116 =
V_379 -> V_105 . V_114 ;
V_379 -> V_105 . V_116 =
V_2 -> V_105 . V_114 ;
V_2 -> V_105 . V_363 =
V_379 -> V_105 . V_126 ;
V_379 -> V_105 . V_363 =
V_2 -> V_105 . V_126 ;
V_2 -> V_105 . V_362 =
V_379 -> V_105 . V_126 ;
V_379 -> V_105 . V_362 =
V_2 -> V_105 . V_126 ;
V_2 -> V_105 . V_338 =
V_379 -> V_105 . V_248 ;
V_379 -> V_105 . V_338 =
V_2 -> V_105 . V_248 ;
V_379 -> V_32 = V_278 ;
F_5 ( V_379 , V_353 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_376 ;
memcpy ( V_19 , V_377 , V_376 ) ;
V_2 -> V_32 = V_341 ;
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
static int F_115 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_116 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
int V_136 = 0 ;
int V_268 = 0 ;
int V_348 ;
struct V_4 V_6 ;
struct V_194 * V_7 = V_2 -> V_7 ;
struct V_1 * V_274 = V_2 -> V_275 ;
F_7 ( V_14 , L_90 ,
V_301 , V_2 , V_2 -> V_105 . V_381 , V_2 -> V_32 ) ;
if ( V_2 -> V_105 . V_381 )
return V_136 ;
F_42 ( V_2 ) ;
if ( ! V_274 ) {
V_348 = F_117 ( 1 , & V_2 -> V_348 ) ;
if ( V_348 == V_384 ) {
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
V_7 -> V_385 ( V_7 ) ;
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
F_118 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_274 -> V_32 = V_198 ;
V_7 = V_274 -> V_7 ;
F_4 ( V_3 , V_274 ) ;
V_7 -> V_200 ( V_7 ) ;
}
}
return V_136 ;
}
static int F_119 ( struct V_130 * V_3 , struct V_1 * V_2 )
{
int V_136 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_197 :
case V_341 :
case V_386 :
case V_342 :
case V_387 :
case V_49 :
case V_278 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_388 :
V_2 -> V_32 = V_199 ;
F_59 ( V_2 , NULL ) ;
break;
case V_33 :
case V_344 :
case V_199 :
case V_345 :
case V_198 :
V_136 = - 1 ;
break;
case V_349 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_343 :
case V_360 :
case V_389 :
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
static int F_120 ( struct V_130 * V_3 ,
struct V_288 * V_279 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_257 * V_266 = NULL ;
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
V_390 . V_11 = F_36 ( V_78 -> V_110 ) ;
V_390 . V_13 = F_16 ( V_76 -> V_112 ) ;
V_390 . V_10 = F_36 ( V_78 -> V_109 ) ;
V_390 . V_12 = F_16 ( V_76 -> V_111 ) ;
V_392 = F_121 ( V_78 -> V_110 ) ;
V_393 = F_121 ( V_78 -> V_109 ) ;
F_7 ( V_14 , L_93 ,
& V_392 , V_76 -> V_112 , & V_393 , V_76 -> V_111 ) ;
do {
V_2 = F_60 ( V_3 ,
V_390 . V_12 , V_390 . V_10 ,
V_390 . V_13 , V_390 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_76 -> V_120 ) || ( V_76 -> V_118 ) ) {
V_391 = 0 ;
break;
}
V_266 = F_62 ( V_3 , V_390 . V_11 ,
V_390 . V_13 ,
V_373 ) ;
if ( ! V_266 ) {
V_390 . V_7 = NULL ;
V_390 . V_326 = 0 ;
F_7 ( V_14 , L_94 ) ;
V_391 = 0 ;
break;
}
V_390 . V_7 = V_266 -> V_7 ;
V_390 . V_326 = V_266 -> V_326 ;
V_2 = F_89 ( V_3 , V_279 , & V_390 ,
V_266 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_95
L_96 ) ;
V_226 ++ ;
F_69 ( & V_266 -> V_264 ) ;
F_96 ( V_16 ) ;
break;
}
if ( ! V_76 -> V_123 && ! V_76 -> V_121 ) {
V_2 -> V_32 = V_349 ;
} else {
V_226 ++ ;
F_4 ( V_3 , V_2 ) ;
F_96 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_225 ) {
if ( V_2 -> V_143 -> V_394 )
F_122 ( V_16 , V_279 , V_2 -> V_143 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_38 ( & V_340 ) ;
F_96 ( V_16 ) ;
}
break;
}
F_123 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_76 ) ) ;
V_16 -> V_35 = F_16 ( V_78 -> V_103 ) ;
F_111 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_391 ;
}
static struct V_130 * F_124 ( void )
{
struct V_130 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_395 ) ;
if ( ! V_3 )
return NULL ;
F_50 ( & V_3 -> V_256 ) ;
F_125 ( & V_3 -> V_193 ) ;
V_3 -> V_193 . V_396 = F_49 ;
V_3 -> V_397 = V_398 ;
V_3 -> V_32 = V_389 ;
V_3 -> V_399 = V_400 ;
F_91 ( & V_3 -> V_401 , 0 ) ;
V_3 -> V_402 = & V_403 ;
F_90 ( & V_3 -> V_222 ) ;
F_90 ( & V_3 -> V_263 ) ;
F_50 ( & V_3 -> V_375 . V_223 ) ;
F_7 ( V_14 , L_97 , V_3 ) ;
F_7 ( V_14 , L_98 ) ;
V_3 -> V_404 = F_126 ( L_99 ) ;
V_3 -> V_405 = F_8 ;
F_7 ( V_14 , L_100 ) ;
V_3 -> V_406 = F_126 ( L_101 ) ;
F_25 ( V_3 ) ;
return V_3 ;
}
static int F_127 ( struct V_130 * V_3 )
{
F_7 ( V_14 , L_102 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_128 () ;
if ( F_43 ( & V_3 -> V_193 ) )
F_129 ( & V_3 -> V_193 ) ;
F_130 ( V_3 -> V_404 ) ;
F_130 ( V_3 -> V_406 ) ;
F_7 ( V_14 , L_103 ) ;
F_34 ( V_3 ) ;
return 0 ;
}
static int F_131 ( struct V_130 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_132 ( struct V_130 * V_3 , T_3 type , T_3 V_407 )
{
int V_136 = 0 ;
switch ( type ) {
case V_408 :
V_3 -> V_397 = V_407 ;
break;
case V_409 :
V_3 -> V_399 = V_407 ;
break;
default:
V_136 = - V_43 ;
}
return V_136 ;
}
static int F_133 ( struct V_140 * V_143 , struct V_1 * V_2 )
{
int V_136 = 0 ;
if ( ! V_143 )
return - V_43 ;
V_143 -> V_165 -> V_410 |= F_31 ( V_411 |
V_412 | V_413 |
V_414 ) ;
if ( V_2 -> V_105 . V_338 || V_2 -> V_105 . V_248 )
V_143 -> V_165 -> V_410 |= F_31 ( V_415 ) ;
V_143 -> V_165 -> V_416 |= F_31 ( 64 << V_417 ) ;
V_143 -> V_165 -> V_244 |= F_31 ( ( ( T_3 ) V_2 -> V_105 . V_244 ) << 16 ) ;
V_143 -> V_165 -> V_418 |= F_31 (
( T_3 ) V_419 << V_420 ) ;
V_143 -> V_165 -> V_421 |= F_31 (
( V_2 -> V_105 . V_338 << V_422 ) &
V_423 ) ;
V_143 -> V_165 -> V_421 |= F_31 (
( V_2 -> V_105 . V_248 << V_424 ) &
V_425 ) ;
V_143 -> V_165 -> V_426 = F_31 ( 0x80 ) ;
V_143 -> V_165 -> V_427 = 0 ;
V_143 -> V_165 -> V_428 = 0 ;
V_143 -> V_165 -> V_429 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_362 = F_31 ( V_2 -> V_105 . V_362 ) ;
V_143 -> V_165 -> V_116 = F_31 ( V_2 -> V_105 . V_116 ) ;
V_143 -> V_165 -> V_126 = F_31 ( V_2 -> V_105 . V_126 <<
V_2 -> V_105 . V_248 ) ;
V_143 -> V_165 -> V_430 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_431 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_432 = 0 ;
V_143 -> V_165 -> V_433 = F_31 ( 0x6 ) ;
V_143 -> V_165 -> V_434 = F_31 ( 0x3FFFC000 ) ;
V_143 -> V_165 -> V_435 = F_31 ( 2 * V_2 -> V_105 . V_244 ) ;
V_143 -> V_165 -> V_436 = F_31 ( V_2 -> V_105 . V_116 ) ;
V_143 -> V_165 -> V_437 = F_31 ( V_2 -> V_105 . V_114 ) ;
V_143 -> V_165 -> V_363 = F_31 ( V_2 -> V_105 . V_363 ) ;
F_7 ( V_14 , L_104
L_105 ,
V_143 -> V_146 . V_205 , F_134 ( V_143 -> V_165 -> V_116 ) ,
F_134 ( V_143 -> V_165 -> V_429 ) ,
V_2 -> V_105 . V_244 , F_134 ( V_143 -> V_165 -> V_421 ) ,
F_134 ( V_143 -> V_165 -> V_126 ) ,
F_134 ( V_143 -> V_165 -> V_410 ) ) ;
F_7 ( V_14 , L_106 , F_134 ( V_143 -> V_165 -> V_362 ) ) ;
F_7 ( V_14 , L_107 , F_134 ( V_143 -> V_165 -> V_435 ) ) ;
F_7 ( V_14 , L_108 , F_134 ( V_143 -> V_165 -> V_363 ) ) ;
F_7 ( V_14 , L_109 ) ;
V_2 -> V_32 = V_225 ;
return V_136 ;
}
int F_48 ( struct V_140 * V_143 )
{
struct V_438 * V_439 ;
V_439 = F_6 ( sizeof *V_439 , V_8 ) ;
if ( ! V_439 )
return - V_27 ;
F_135 ( & V_143 -> V_330 ) ;
V_439 -> V_143 = V_143 ;
F_136 ( & V_439 -> V_439 , V_440 ) ;
F_137 ( V_219 -> V_406 , & V_439 -> V_439 ) ;
return 0 ;
}
static void V_440 ( struct V_441 * V_439 )
{
struct V_438 * V_442 = F_52 ( V_439 , struct V_438 , V_439 ) ;
struct V_140 * V_143 = V_442 -> V_143 ;
F_34 ( V_442 ) ;
F_7 ( V_14 , L_110 ,
V_143 -> V_209 , V_143 -> V_146 . V_205 ) ;
F_138 ( V_143 ) ;
F_93 ( & V_143 -> V_330 ) ;
}
static int F_138 ( struct V_140 * V_143 )
{
unsigned long V_29 ;
int V_136 = 0 ;
struct V_194 * V_7 ;
struct V_443 V_444 ;
struct V_288 * V_279 ;
T_2 V_445 ;
T_1 V_446 ;
T_1 V_447 ;
int V_448 = 0 ;
int V_449 = 0 ;
int V_450 = 0 ;
int V_451 = 0 ;
T_3 V_452 = V_453 ;
struct V_454 V_455 ;
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
V_279 = F_139 ( V_143 -> V_330 . V_456 ) ;
F_7 ( V_14 , L_113 , V_143 -> V_146 . V_205 ) ;
V_446 = V_143 -> V_207 ;
V_447 = V_143 -> V_211 ;
V_445 = V_143 -> V_209 ;
if ( V_143 -> V_457 ) {
V_449 = 1 ;
V_450 = 1 ;
V_143 -> V_7 = NULL ;
F_129 ( & V_143 -> V_458 ) ;
if ( V_143 -> V_459 == 0 ) {
V_143 -> V_459 = 1 ;
V_451 = 1 ;
}
} else if ( ( V_446 == V_460 ) ||
( ( V_447 == V_461 ) &&
( V_445 == V_462 ) ) ) {
V_449 = 1 ;
if ( V_445 == V_462 )
V_448 = - V_463 ;
}
if ( ( ( V_446 == V_208 ) ||
( V_446 == V_464 ) ||
( V_445 == V_465 ) ||
( V_445 == V_462 ) ) ) {
V_450 = 1 ;
V_143 -> V_7 = NULL ;
if ( V_143 -> V_459 == 0 ) {
V_143 -> V_459 = 1 ;
V_451 = 1 ;
}
}
F_40 ( & V_143 -> V_204 , V_29 ) ;
if ( ( V_451 ) && ( V_143 -> V_466 == 0 ) ) {
if ( V_143 -> V_467 >= V_468 )
V_452 |= V_469 ;
F_140 ( V_279 -> V_280 , V_143 , V_452 , 1 ) ;
if ( V_143 -> V_457 ) {
V_455 . V_456 = V_143 -> V_330 . V_456 ;
V_455 . V_6 = V_143 -> V_470 ;
V_455 . V_471 . V_472 = & V_143 -> V_330 ;
if ( V_143 -> V_330 . V_473 )
V_143 -> V_330 . V_473 ( & V_455 , V_143 -> V_330 . V_474 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_473 ) ) {
if ( V_449 ) {
F_38 ( & V_475 ) ;
V_444 . V_6 = V_476 ;
V_444 . V_477 = V_448 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_377 = NULL ;
V_444 . V_376 = 0 ;
F_7 ( V_14 , L_114
L_115
L_116 ,
V_143 -> V_146 . V_205 , V_143 -> V_146 . V_480 ,
V_143 -> V_146 . V_171 , V_7 ,
F_26 ( & V_143 -> V_206 ) ) ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_136 )
F_7 ( V_14 , L_117
L_118 , V_136 ) ;
}
if ( V_450 ) {
F_38 ( & V_481 ) ;
F_141 ( V_143 , 1 ) ;
V_7 -> V_482 = V_143 ;
V_444 . V_6 = V_483 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_377 = NULL ;
V_444 . V_376 = 0 ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_136 )
F_7 ( V_14 , L_119 , V_136 ) ;
V_7 -> V_200 ( V_7 ) ;
}
}
return 0 ;
}
static int F_141 ( struct V_140 * V_143 , int V_484 )
{
int V_136 = 0 ;
struct V_288 * V_279 ;
struct V_317 * V_280 ;
struct V_485 * V_486 ;
V_279 = F_139 ( V_143 -> V_330 . V_456 ) ;
if ( ! V_279 )
return - V_43 ;
V_280 = V_279 -> V_280 ;
V_486 = V_279 -> V_486 ;
F_7 ( V_14 , L_120 ,
F_142 ( V_279 -> V_86 ) ) ;
if ( V_143 -> V_487 ) {
V_143 -> V_487 = 0 ;
} else {
if ( V_143 -> V_488 ) {
if ( V_143 -> V_489 )
V_486 -> V_490 . V_491 ( V_143 -> V_489 ) ;
F_143 ( V_280 -> V_281 ,
V_143 -> V_376 + V_143 -> V_492 ,
V_143 -> V_488 , V_143 -> V_493 ) ;
}
}
if ( V_143 -> V_2 ) {
F_7 ( V_14 , L_121 ) ;
V_219 -> V_402 -> V_494 ( V_219 , V_143 -> V_2 ) ;
}
return V_136 ;
}
int F_144 ( struct V_194 * V_7 , struct V_495 * V_496 )
{
T_4 V_142 ;
struct V_497 * V_330 ;
struct V_140 * V_143 ;
struct V_288 * V_279 ;
struct V_317 * V_280 ;
struct V_1 * V_2 ;
struct V_297 * V_498 ;
struct V_499 V_500 ;
struct V_443 V_444 ;
struct V_144 * V_145 ;
struct V_501 V_502 ;
T_3 V_503 ;
int V_136 ;
int V_348 ;
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
V_330 = F_145 ( V_7 -> V_456 , V_496 -> V_512 ) ;
if ( ! V_330 )
return - V_43 ;
V_143 = F_146 ( V_330 ) ;
V_279 = F_139 ( V_143 -> V_330 . V_456 ) ;
V_280 = V_279 -> V_280 ;
V_498 = V_280 -> V_298 ;
V_2 = (struct V_1 * ) V_7 -> V_482 ;
F_7 ( V_14 , L_122
L_123 , V_2 , V_279 , V_279 -> V_86 ,
V_279 -> V_86 -> V_513 ) ;
if ( V_277 == V_2 -> V_32 ) {
if ( V_2 -> V_275 )
F_4 ( V_2 -> V_3 , V_2 -> V_275 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_348 = F_117 ( 1 , & V_2 -> V_348 ) ;
if ( V_348 == V_384 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_463 ;
}
V_143 -> V_2 = ( void * ) V_2 ;
V_2 -> V_143 = V_143 ;
F_7 ( V_14 , L_124 ,
V_143 -> V_146 . V_205 , V_2 , V_182 , V_2 -> V_266 ) ;
F_38 ( & V_514 ) ;
F_7 ( V_14 , L_120 ,
F_142 ( V_279 -> V_86 ) ) ;
V_143 -> V_492 = sizeof( struct V_36 ) ;
V_143 -> V_488 = F_147 ( V_280 -> V_281 ,
V_143 -> V_492 + V_496 -> V_376 ,
& V_143 -> V_493 ) ;
if ( ! V_143 -> V_488 ) {
F_7 ( V_14 , L_125 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_143 -> V_488 ;
if ( V_2 -> V_48 == V_46 )
V_511 = 4 ;
memcpy ( V_37 -> V_515 , V_496 -> V_377 ,
V_496 -> V_376 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_143 -> V_488 , V_28 ) ;
V_143 -> V_376 = V_496 -> V_376 ;
V_145 = & V_143 -> V_146 . V_147 [ 0 ] ;
if ( V_7 -> V_479 . V_516 . V_517 !=
V_7 -> V_478 . V_516 . V_517 ) {
V_142 = ( unsigned long ) V_143 ;
V_486 = V_279 -> V_486 ;
V_509 = V_143 -> V_509 ;
V_507 . V_518 = V_143 -> V_493 + V_511 ;
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
F_143 ( V_280 -> V_281 ,
V_143 -> V_376 + V_143 -> V_492 ,
V_143 -> V_488 , V_143 -> V_493 ) ;
return - V_27 ;
}
V_505 -> V_523 = & V_509 -> V_524 ;
V_505 -> V_456 = V_509 -> V_524 . V_456 ;
V_143 -> V_489 = V_505 ;
V_142 |= V_148 >> 1 ;
F_30 ( V_145 -> V_149 ,
V_150 ,
V_142 ) ;
V_145 -> V_149 [ V_153 ] =
F_31 ( V_525 |
V_526 ) ;
V_145 -> V_149 [ V_155 ] =
F_31 ( V_20 ) ;
F_30 ( V_145 -> V_149 ,
V_151 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_145 -> V_149 [ V_156 ] =
F_31 ( V_20 ) ;
V_145 -> V_149 [ V_157 ] = V_505 -> V_527 ;
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
V_7 -> V_482 = V_143 ;
V_143 -> V_487 = 0 ;
if ( V_2 -> V_32 == V_225 )
F_7 ( V_14 , L_128 ,
V_2 ) ;
F_133 ( V_143 , V_2 ) ;
V_143 -> V_165 -> V_528 [ 0 ] =
F_148 ( F_16 ( V_7 -> V_478 . V_529 ) ) ;
V_143 -> V_165 -> V_528 [ 1 ] =
F_148 ( F_16 ( V_7 -> V_479 . V_529 ) ) ;
V_143 -> V_165 -> V_530 =
F_31 ( F_36 ( V_7 -> V_479 . V_516 . V_517 ) ) ;
V_143 -> V_165 -> V_416 |= F_31 (
( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) <<
V_531 ) ;
V_143 -> V_165 -> V_532 |=
F_31 ( F_84 ( V_280 ,
F_134 ( V_143 -> V_165 -> V_530 ) , NULL ,
V_312 ) << 16 ) ;
V_143 -> V_165 -> V_533 = F_31 (
V_182 - F_149 ( V_280 , V_534 ) ) ;
V_143 -> V_165 -> V_535 = F_31 ( V_143 -> V_146 . V_205 ) ;
V_143 -> V_165 -> V_166 |= F_31 (
( ( T_3 ) 1 << V_536 ) ) ;
V_143 -> V_165 -> V_166 |=
F_31 ( ( T_3 ) V_496 -> V_537 ) ;
memset ( & V_502 , 0 , sizeof( V_502 ) ) ;
V_502 . V_538 =
F_31 ( ( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) << 24 ) ;
V_502 . V_539 = V_7 -> V_479 . V_516 . V_517 ;
V_502 . V_540 [ 0 ] = V_7 -> V_479 . V_529 ;
V_502 . V_540 [ 1 ] = V_7 -> V_478 . V_529 ;
V_503 = F_150 ( & V_502 ) ;
V_143 -> V_541 = F_121 ( V_503 ^ 0xffffffff ) ;
F_7 ( V_14 , L_129 ,
V_143 -> V_541 , V_143 -> V_541 & V_498 -> V_542 ) ;
V_143 -> V_541 &= V_498 -> V_542 ;
V_143 -> V_165 -> V_541 = F_31 ( V_143 -> V_541 ) ;
V_2 -> V_3 -> V_402 -> V_272 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_130
L_131
L_132 , V_143 -> V_146 . V_205 ,
F_36 ( V_7 -> V_479 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_479 . V_529 ) ,
F_36 ( V_7 -> V_478 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_478 . V_529 ) ,
F_134 ( V_143 -> V_165 -> V_116 ) ,
F_134 ( V_143 -> V_165 -> V_429 ) ,
V_20 ) ;
V_7 -> V_385 ( V_7 ) ;
F_135 ( & V_143 -> V_330 ) ;
V_444 . V_6 = V_543 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = ( void * ) V_143 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_377 = NULL ;
V_444 . V_376 = 0 ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
V_500 . V_544 = V_461 ;
F_151 ( & V_143 -> V_330 , & V_500 , V_545 , NULL ) ;
if ( V_2 -> V_275 ) {
V_2 -> V_275 -> V_54 =
V_143 -> V_376 ;
memcpy ( V_2 -> V_275 -> V_69 ,
V_496 -> V_377 , V_496 -> V_376 ) ;
F_5 ( V_2 -> V_275 , V_356 ) ;
}
if ( V_136 )
F_78 ( V_300 L_133
L_134 , V_301 , __LINE__ , V_136 ) ;
return 0 ;
}
int F_152 ( struct V_194 * V_7 , const void * V_546 , T_1 V_547 )
{
struct V_1 * V_2 ;
struct V_1 * V_274 ;
struct V_130 * V_3 ;
T_1 * V_19 ;
F_38 ( & V_548 ) ;
V_2 = (struct V_1 * ) V_7 -> V_482 ;
V_274 = V_2 -> V_275 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_547 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_274 ) {
memcpy ( & V_274 -> V_25 . V_515 , V_546 , V_547 ) ;
V_274 -> V_25 . V_41 = V_547 ;
V_274 -> V_54 = V_547 ;
} else {
V_19 = & V_2 -> V_69 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_547 ;
memcpy ( V_19 , V_546 , V_547 ) ;
}
return V_3 -> V_402 -> V_549 ( V_3 , V_2 ) ;
}
int F_153 ( struct V_194 * V_7 , struct V_495 * V_496 )
{
struct V_497 * V_330 ;
struct V_140 * V_143 ;
struct V_288 * V_279 ;
struct V_317 * V_280 ;
struct V_1 * V_2 ;
struct V_313 V_9 ;
int V_327 = 0 ;
V_330 = F_145 ( V_7 -> V_456 , V_496 -> V_512 ) ;
if ( ! V_330 )
return - V_43 ;
V_143 = F_146 ( V_330 ) ;
if ( ! V_143 )
return - V_43 ;
V_279 = F_139 ( V_143 -> V_330 . V_456 ) ;
if ( ! V_279 )
return - V_43 ;
V_280 = V_279 -> V_280 ;
if ( ! V_280 )
return - V_43 ;
if ( ! ( V_7 -> V_478 . V_529 ) || ! ( V_7 -> V_479 . V_529 ) )
return - V_43 ;
F_7 ( V_14 , L_135
L_136 , V_143 -> V_146 . V_205 ,
F_36 ( V_279 -> V_382 ) ,
F_36 ( V_7 -> V_479 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_479 . V_529 ) ,
F_36 ( V_7 -> V_478 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_478 . V_529 ) ) ;
F_38 ( & V_550 ) ;
V_143 -> V_487 = 1 ;
V_143 -> V_7 = V_7 ;
V_7 -> V_482 = V_143 ;
V_143 -> V_376 = V_496 -> V_376 ;
V_143 -> V_165 -> V_166 |= F_31 ( ( T_3 ) V_496 -> V_537 ) ;
if ( V_496 -> V_537 == 0 )
V_143 -> V_165 -> V_166 |= F_31 ( 1 ) ;
F_7 ( V_14 , L_137 , ( T_3 ) V_496 -> V_537 ) ;
F_7 ( V_14 , L_138 ,
V_496 -> V_376 ) ;
if ( V_7 -> V_478 . V_516 . V_517 !=
V_7 -> V_479 . V_516 . V_517 ) {
F_70 ( V_279 , F_16 ( V_7 -> V_478 . V_529 ) ,
F_71 ( V_280 -> V_281 -> V_282 ) , V_551 ) ;
V_327 = 1 ;
}
V_9 . V_11 = F_23 ( V_7 -> V_478 . V_516 . V_517 ) ;
V_9 . V_13 = F_22 ( V_7 -> V_478 . V_529 ) ;
V_9 . V_10 = F_23 ( V_7 -> V_479 . V_516 . V_517 ) ;
V_9 . V_12 = F_22 ( V_7 -> V_479 . V_529 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_326 = V_552 ;
V_7 -> V_385 ( V_7 ) ;
V_2 = V_219 -> V_402 -> V_553 ( V_219 , V_279 ,
V_496 -> V_376 , ( void * ) V_496 -> V_377 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_327 )
F_70 ( V_279 , F_16 ( V_7 -> V_478 . V_529 ) ,
F_71 ( V_280 -> V_281 -> V_282 ) ,
V_283 ) ;
V_7 -> V_200 ( V_7 ) ;
return - V_27 ;
}
V_2 -> V_327 = V_327 ;
V_143 -> V_2 = V_2 ;
V_2 -> V_143 = V_143 ;
F_135 ( & V_143 -> V_330 ) ;
return 0 ;
}
int F_154 ( struct V_194 * V_7 , int V_358 )
{
struct V_288 * V_279 ;
struct V_257 * V_2 ;
struct V_313 V_9 ;
int V_268 ;
F_7 ( V_14 , L_139 ,
V_7 , F_16 ( V_7 -> V_478 . V_529 ) ) ;
V_279 = F_139 ( V_7 -> V_456 ) ;
if ( ! V_279 )
return - V_43 ;
F_7 ( V_14 , L_140 ,
V_279 , V_279 -> V_86 , V_279 -> V_86 -> V_513 ) ;
F_7 ( V_14 , L_141 ,
V_279 -> V_382 , V_7 -> V_478 . V_516 . V_517 ) ;
V_9 . V_11 = V_279 -> V_382 ;
V_9 . V_13 = V_7 -> V_478 . V_529 ;
V_9 . V_358 = V_358 ;
V_9 . V_7 = V_7 ;
V_9 . V_326 = V_552 ;
V_2 = V_219 -> V_402 -> V_554 ( V_219 , V_279 , & V_9 ) ;
if ( ! V_2 ) {
F_78 ( V_300 L_142 ,
V_301 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_482 = V_2 ;
if ( ! V_2 -> V_374 ) {
V_268 = F_70 ( V_279 ,
F_16 ( V_7 -> V_478 . V_529 ) ,
F_71 ( V_279 -> V_280 -> V_281 -> V_282 ) ,
V_551 ) ;
if ( V_268 ) {
F_78 ( V_300 L_143 ,
V_268 ) ;
V_219 -> V_402 -> V_555 ( V_219 , ( void * ) V_2 ) ;
return V_268 ;
}
F_38 ( & V_556 ) ;
}
V_7 -> V_385 ( V_7 ) ;
V_7 -> V_482 = ( void * ) V_2 ;
return 0 ;
}
int F_155 ( struct V_194 * V_7 )
{
if ( V_7 -> V_482 )
V_219 -> V_402 -> V_555 ( V_219 , V_7 -> V_482 ) ;
else
F_7 ( V_14 , L_144 ) ;
V_7 -> V_200 ( V_7 ) ;
return 0 ;
}
int F_156 ( struct V_15 * V_16 , struct V_296 * V_557 )
{
int V_295 = 0 ;
V_558 ++ ;
if ( ( V_219 ) && ( V_219 -> V_402 ) )
V_295 = V_219 -> V_402 -> V_559 ( V_219 , F_157 ( V_557 ) , V_16 ) ;
else
F_7 ( V_14 , L_145
L_146 ) ;
return V_295 ;
}
int F_158 ( void )
{
F_7 ( V_14 , L_103 ) ;
V_219 = F_124 () ;
if ( V_219 )
return 0 ;
else
return - V_27 ;
}
int F_159 ( void )
{
V_219 -> V_402 -> V_560 ( V_219 ) ;
return 0 ;
}
static void F_160 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_288 * V_279 ;
struct V_317 * V_280 ;
struct V_1 * V_2 ;
struct V_297 * V_298 ;
struct V_499 V_500 ;
struct V_194 * V_7 ;
struct V_443 V_444 ;
struct V_501 V_502 ;
T_3 V_503 ;
int V_136 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_147 , V_2 , V_7 ) ;
V_143 = (struct V_140 * ) V_7 -> V_482 ;
V_279 = F_139 ( V_143 -> V_330 . V_456 ) ;
V_280 = V_279 -> V_280 ;
V_298 = V_280 -> V_298 ;
if ( V_143 -> V_466 )
return;
F_38 ( & V_561 ) ;
F_7 ( V_14 , L_148
L_149 ,
V_143 -> V_146 . V_205 ,
F_36 ( V_7 -> V_479 . V_516 . V_517 ) ,
F_16 ( V_7 -> V_479 . V_529 ) ,
F_16 ( V_7 -> V_478 . V_529 ) ,
V_182 ) ;
F_133 ( V_143 , V_2 ) ;
V_143 -> V_165 -> V_528 [ 0 ] =
F_148 ( F_16 ( V_7 -> V_478 . V_529 ) ) ;
V_143 -> V_165 -> V_528 [ 1 ] =
F_148 ( F_16 ( V_7 -> V_479 . V_529 ) ) ;
V_143 -> V_165 -> V_530 =
F_31 ( F_36 ( V_7 -> V_479 . V_516 . V_517 ) ) ;
V_143 -> V_165 -> V_416 |= F_31 (
( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) <<
V_531 ) ;
V_143 -> V_165 -> V_532 |= F_31 (
F_84 ( V_280 ,
F_134 ( V_143 -> V_165 -> V_530 ) ,
NULL , V_312 ) << 16 ) ;
V_143 -> V_165 -> V_533 = F_31 (
V_182 - F_149 ( V_280 , V_534 ) ) ;
V_143 -> V_165 -> V_535 = F_31 ( V_143 -> V_146 . V_205 ) ;
V_143 -> V_165 -> V_166 |=
F_31 ( ( T_3 ) 1 <<
V_536 ) ;
F_29 ( V_2 , & V_143 ) ;
F_161 ( V_280 -> V_562 + V_563 ,
( 1 << 24 ) | 0x00800000 | V_143 -> V_146 . V_205 ) ;
memset ( & V_502 , 0 , sizeof( V_502 ) ) ;
V_502 . V_538 =
F_31 ( ( T_3 ) F_71 ( V_280 -> V_281 -> V_282 ) << 24 ) ;
V_502 . V_539 = V_7 -> V_479 . V_516 . V_517 ;
V_502 . V_540 [ 0 ] = V_7 -> V_479 . V_529 ;
V_502 . V_540 [ 1 ] = V_7 -> V_478 . V_529 ;
V_503 = F_150 ( & V_502 ) ;
V_143 -> V_541 = F_121 ( V_503 ^ 0xffffffff ) ;
F_7 ( V_14 , L_150 ,
V_143 -> V_541 , V_143 -> V_541 & V_298 -> V_542 ) ;
V_143 -> V_541 &= V_298 -> V_542 ;
V_143 -> V_165 -> V_541 = F_31 ( V_143 -> V_541 ) ;
V_143 -> V_488 = & V_2 -> V_25 ;
V_143 -> V_376 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_402 -> V_272 ( V_2 -> V_3 , V_2 ) ;
V_444 . V_6 = V_564 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 . V_565 = V_566 ;
V_444 . V_478 . V_529 = V_7 -> V_478 . V_529 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_377 = ( void * ) V_6 -> V_2 -> V_69 ;
V_444 . V_376 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_444 . V_567 = V_2 -> V_55 ;
V_444 . V_537 = V_2 -> V_56 ;
V_444 . V_478 . V_516 . V_517 = V_6 -> V_9 . V_10 ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
if ( V_136 )
F_78 ( V_300 L_133
L_134 , V_301 , __LINE__ , V_136 ) ;
V_500 . V_544 = V_461 ;
F_151 ( & V_143 -> V_330 , & V_500 , V_545 , NULL ) ;
F_7 ( V_14 , L_151
L_152 , V_143 -> V_146 . V_205 , V_182 ) ;
return;
}
static void F_66 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_194 * V_7 ;
struct V_443 V_444 ;
int V_136 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_153 , V_6 -> V_2 , V_7 ) ;
V_143 = V_7 -> V_482 ;
if ( ! V_143 )
return;
V_143 -> V_7 = NULL ;
V_7 -> V_482 = NULL ;
V_444 . V_6 = V_564 ;
V_444 . V_477 = - V_463 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_377 = NULL ;
V_444 . V_376 = 0 ;
F_7 ( V_14 , L_154
L_155 , V_444 . V_478 . V_516 . V_517 ,
V_444 . V_479 . V_516 . V_517 ) ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
if ( V_136 )
F_78 ( V_300 L_133
L_134 , V_301 , __LINE__ , V_136 ) ;
V_7 -> V_200 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_162 ( struct V_4 * V_6 )
{
struct V_140 * V_143 ;
struct V_194 * V_7 ;
struct V_443 V_444 ;
int V_136 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_156 , V_6 -> V_2 , V_7 ) ;
V_143 = V_7 -> V_482 ;
if ( ! V_143 )
return;
V_143 -> V_7 = NULL ;
V_444 . V_6 = V_476 ;
V_444 . V_477 = - V_463 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_377 = NULL ;
V_444 . V_376 = 0 ;
V_7 -> V_385 ( V_7 ) ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_38 ( & V_481 ) ;
V_444 . V_6 = V_483 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 = V_7 -> V_478 ;
V_444 . V_479 = V_7 -> V_479 ;
V_444 . V_377 = NULL ;
V_444 . V_376 = 0 ;
F_7 ( V_14 , L_157 , V_6 -> V_2 ) ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
F_7 ( V_14 , L_119 , V_136 ) ;
V_7 -> V_200 ( V_7 ) ;
return;
}
static void F_163 ( struct V_4 * V_6 )
{
struct V_194 * V_7 ;
struct V_443 V_444 ;
int V_136 ;
struct V_1 * V_2 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_568 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_182 ) ;
V_444 . V_6 = V_569 ;
V_444 . V_477 = 0 ;
V_444 . V_482 = ( void * ) V_2 ;
V_444 . V_478 . V_565 = V_566 ;
V_444 . V_478 . V_529 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_444 . V_478 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_444 . V_479 . V_565 = V_566 ;
V_444 . V_479 . V_529 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_444 . V_479 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_444 . V_377 = V_2 -> V_69 ;
V_444 . V_376 = ( T_1 ) V_2 -> V_54 ;
V_444 . V_567 = V_2 -> V_55 ;
V_444 . V_537 = V_2 -> V_56 ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_136 )
F_78 ( V_300 L_159 ,
V_301 , __LINE__ , V_136 ) ;
return;
}
static void F_118 ( struct V_4 * V_6 )
{
struct V_194 * V_7 ;
struct V_443 V_444 ;
struct V_1 * V_2 ;
int V_136 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_568 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_182 ) ;
V_444 . V_6 = V_564 ;
V_444 . V_477 = - V_570 ;
V_444 . V_482 = V_7 -> V_482 ;
V_444 . V_478 . V_565 = V_566 ;
V_444 . V_478 . V_529 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_444 . V_478 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_444 . V_479 . V_565 = V_566 ;
V_444 . V_479 . V_529 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_444 . V_479 . V_516 . V_517 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_444 . V_377 = V_2 -> V_69 ;
V_444 . V_376 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_160
L_155 ,
V_444 . V_478 . V_516 . V_517 ,
V_444 . V_479 . V_516 . V_517 ) ;
V_136 = V_7 -> V_473 ( V_7 , & V_444 ) ;
if ( V_136 )
F_78 ( V_300 L_159 ,
V_301 , __LINE__ , V_136 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_38 ( & V_6 -> V_2 -> V_3 -> V_401 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_385 ( V_6 -> V_9 . V_7 ) ;
F_136 ( & V_6 -> V_571 , V_572 ) ;
F_7 ( V_14 , L_161 ,
V_6 -> V_2 , V_6 ) ;
F_137 ( V_6 -> V_2 -> V_3 -> V_404 , & V_6 -> V_571 ) ;
F_7 ( V_14 , L_162 ) ;
return 0 ;
}
static void V_572 ( struct V_441 * V_439 )
{
struct V_4 * V_6 = F_52 ( V_439 , struct V_4 ,
V_571 ) ;
struct V_130 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_163 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_401 ) ) ;
switch ( V_6 -> type ) {
case V_353 :
F_163 ( V_6 ) ;
F_7 ( V_14 , L_164 ,
V_6 -> V_2 ) ;
break;
case V_573 :
F_7 ( V_14 , L_165 ,
V_6 -> V_2 ) ;
F_162 ( V_6 ) ;
break;
case V_356 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_225 ) )
break;
F_160 ( V_6 ) ;
F_7 ( V_14 , L_166 ) ;
break;
case V_355 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_225 ) )
break;
F_118 ( V_6 ) ;
F_7 ( V_14 , L_167 ) ;
break;
case V_201 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_225 ) )
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
V_6 -> V_9 . V_7 -> V_200 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_34 ( V_6 ) ;
return;
}
