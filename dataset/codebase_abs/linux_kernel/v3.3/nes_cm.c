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
V_37 = (struct V_36 * ) V_34 ;
V_40 += V_57 ;
V_2 -> V_54 -= V_57 ;
V_39 = & V_37 -> V_39 ;
V_39 -> V_58 = F_16 ( V_39 -> V_58 ) ;
V_39 -> V_59 = F_16 ( V_39 -> V_59 ) ;
V_55 = V_39 -> V_58 & V_60 ;
V_56 = V_39 -> V_59 & V_60 ;
if ( ! ( V_39 -> V_58 & V_61 ) ) {
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
if ( V_39 -> V_59 & V_62 ) {
V_2 -> V_63 = V_64 ;
} else if ( V_39 -> V_59 & V_65 ) {
V_2 -> V_63 = V_66 ;
} else {
return - V_43 ;
}
break;
}
case V_46 :
default:
break;
}
memcpy ( V_2 -> V_67 , V_34 + V_40 , V_2 -> V_54 ) ;
if ( V_25 -> V_29 & V_30 )
* type = V_68 ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_1 * V_2 , void * V_69 , T_3 V_70 ,
void * V_71 , T_3 V_72 , T_1 V_29 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
T_1 * V_79 ;
T_2 V_80 = sizeof( * V_76 ) ;
V_80 += sizeof( * V_74 ) ;
V_80 += V_70 + V_72 ;
F_17 ( V_16 , 0 ) ;
memset ( V_16 -> V_71 , 0x00 , V_81 + sizeof( * V_76 ) + sizeof( * V_74 ) ) ;
V_79 = F_18 ( V_16 , V_80 + V_81 ) ;
V_78 = (struct V_77 * ) V_79 ;
V_79 += V_81 ;
V_76 = (struct V_75 * ) V_79 ;
V_79 += sizeof( * V_76 ) ;
V_74 = (struct V_73 * ) V_79 ;
F_19 ( V_16 ) ;
F_20 ( V_16 , V_81 ) ;
F_21 ( V_16 , V_81 + sizeof( * V_76 ) ) ;
V_79 += sizeof( * V_74 ) ;
V_16 -> V_82 = V_83 ;
V_16 -> V_84 = F_22 ( 0x800 ) ;
V_16 -> V_85 = 0 ;
V_16 -> V_86 = V_81 ;
memcpy ( V_78 -> V_87 , V_2 -> V_88 , V_89 ) ;
memcpy ( V_78 -> V_90 , V_2 -> V_91 , V_89 ) ;
V_78 -> V_92 = F_22 ( 0x0800 ) ;
V_76 -> V_93 = V_94 ;
V_76 -> V_95 = 5 ;
V_76 -> V_96 = 0 ;
V_76 -> V_97 = F_22 ( V_80 ) ;
V_76 -> V_98 = F_22 ( ++ V_2 -> V_99 . V_100 ) ;
V_76 -> V_101 = F_22 ( 0x4000 ) ;
V_76 -> V_102 = 0x40 ;
V_76 -> V_84 = 0x06 ;
V_76 -> V_103 = F_23 ( V_2 -> V_11 ) ;
V_76 -> V_104 = F_23 ( V_2 -> V_10 ) ;
V_74 -> V_105 = F_22 ( V_2 -> V_13 ) ;
V_74 -> V_106 = F_22 ( V_2 -> V_12 ) ;
V_74 -> V_107 = F_23 ( V_2 -> V_99 . V_108 ) ;
if ( V_29 & V_22 ) {
V_2 -> V_99 . V_109 = V_2 -> V_99 . V_110 ;
V_74 -> V_111 = F_23 ( V_2 -> V_99 . V_109 ) ;
V_74 -> V_112 = 1 ;
} else {
V_74 -> V_111 = 0 ;
}
if ( V_29 & V_113 ) {
V_2 -> V_99 . V_108 ++ ;
V_74 -> V_114 = 1 ;
} else {
V_2 -> V_99 . V_108 += V_72 ;
}
if ( V_29 & V_31 ) {
V_2 -> V_99 . V_108 ++ ;
V_74 -> V_115 = 1 ;
}
if ( V_29 & V_116 )
V_74 -> V_117 = 1 ;
V_74 -> V_118 = ( T_2 ) ( ( sizeof( * V_74 ) + V_70 + 3 ) >> 2 ) ;
V_74 -> V_119 = F_22 ( V_2 -> V_99 . V_120 ) ;
V_74 -> V_121 = 0 ;
if ( V_70 )
memcpy ( V_79 , V_69 , V_70 ) ;
V_79 += V_70 ;
if ( V_72 )
memcpy ( V_79 , V_71 , V_72 ) ;
F_24 ( V_16 ) -> V_122 = 0 ;
V_123 ++ ;
}
static void F_25 ( struct V_124 * V_125 )
{
F_7 ( V_14 , L_16 ) ;
F_7 ( V_14 , L_17 , V_125 ) ;
if ( ! V_125 )
return;
F_7 ( V_14 , L_16 ) ;
F_7 ( V_14 , L_18 , V_125 -> V_32 ) ;
F_7 ( V_14 , L_19 , F_26 ( & V_125 -> V_126 ) ) ;
F_7 ( V_14 , L_20 , F_26 ( & V_125 -> V_127 ) ) ;
F_7 ( V_14 , L_21 , V_125 ) ;
F_7 ( V_14 , L_22 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * * V_19 ,
T_2 * V_20 , T_1 * V_128 , T_1 V_129 )
{
int V_130 = 0 ;
* V_19 = ( V_128 ) ? V_128 : & V_2 -> V_67 [ 0 ] ;
switch ( V_2 -> V_48 ) {
case V_46 :
* V_19 = ( T_1 * ) * V_19 + sizeof( struct V_38 ) ;
* V_20 = sizeof( struct V_24 ) + V_2 -> V_54 ;
F_27 ( V_2 , * V_19 , V_129 ) ;
break;
case V_47 :
* V_20 = sizeof( struct V_36 ) + V_2 -> V_54 ;
F_28 ( V_2 , * V_19 , V_129 ) ;
break;
default:
V_130 = - V_43 ;
}
return V_130 ;
}
static void F_28 ( struct V_1 * V_2 ,
void * V_17 , T_1 V_129 )
{
struct V_36 * V_25 = (struct V_36 * ) V_17 ;
struct V_38 * V_39 = & V_25 -> V_39 ;
F_27 ( V_2 , V_17 , V_129 ) ;
V_25 -> V_29 |= V_131 ;
V_25 -> V_41 += F_22 ( V_57 ) ;
V_39 -> V_58 = ( V_2 -> V_55 > V_60 ) ?
V_60 : V_2 -> V_55 ;
V_39 -> V_59 = ( V_2 -> V_56 > V_60 ) ?
V_60 : V_2 -> V_56 ;
V_39 -> V_58 |= V_61 ;
V_39 -> V_58 |= V_132 ;
switch ( V_129 ) {
case V_21 :
V_39 -> V_59 |= V_65 ;
V_39 -> V_59 |= V_62 ;
break;
case V_28 :
switch ( V_2 -> V_63 ) {
case V_66 :
V_39 -> V_59 |= V_65 ;
break;
case V_64 :
V_39 -> V_59 |= V_62 ;
break;
}
}
V_39 -> V_58 = F_22 ( V_39 -> V_58 ) ;
V_39 -> V_59 = F_22 ( V_39 -> V_59 ) ;
}
static void F_27 ( struct V_1 * V_2 , void * V_17 , T_1 V_129 )
{
struct V_24 * V_25 = (struct V_24 * ) V_17 ;
switch ( V_129 ) {
case V_21 :
memcpy ( V_25 -> V_50 , V_51 , V_52 ) ;
break;
case V_28 :
memcpy ( V_25 -> V_50 , V_53 , V_52 ) ;
break;
}
V_25 -> V_29 = V_133 ;
V_25 -> V_45 = V_2 -> V_48 ;
V_25 -> V_41 = F_22 ( V_2 -> V_54 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_134 * * V_135 )
{
T_4 V_136 ;
struct V_134 * V_137 = * V_135 ;
struct V_138 * V_139 = & V_137 -> V_140 . V_141 [ 0 ] ;
V_136 = ( unsigned long ) V_137 ;
V_136 |= V_142 >> 1 ;
F_30 ( V_139 -> V_143 , V_144 , V_136 ) ;
V_139 -> V_143 [ V_145 ] = 0 ;
V_139 -> V_143 [ V_146 ] = 0 ;
switch ( V_2 -> V_63 ) {
case V_66 :
F_7 ( V_14 , L_23 ) ;
V_139 -> V_143 [ V_147 ] =
F_31 ( V_148 ) ;
V_139 -> V_143 [ V_149 ] = 0 ;
V_139 -> V_143 [ V_150 ] = 0 ;
V_139 -> V_143 [ V_151 ] = 0 ;
break;
case V_64 :
default:
if ( V_2 -> V_63 != V_64 ) {
F_32 ( V_152 L_24 ,
V_153 , __LINE__ , V_2 -> V_63 ) ;
F_33 ( 1 ) ;
}
F_7 ( V_14 , L_25 ) ;
V_139 -> V_143 [ V_147 ] =
F_31 ( V_154 ) ;
V_139 -> V_143 [ V_155 ] = 1 ;
V_139 -> V_143 [ V_156 ] = 0 ;
V_139 -> V_143 [ V_157 ] = 0 ;
V_139 -> V_143 [ V_158 ] = 1 ;
V_139 -> V_143 [ V_151 ] = 1 ;
break;
}
if ( V_137 -> V_159 ) {
V_137 -> V_159 = 0 ;
F_34 ( V_137 -> V_160 ) ;
}
V_137 -> V_161 -> V_162 &= F_31 ( ~ ( V_163 |
V_164 |
V_165 ) ) ;
V_137 -> V_166 = 1 ;
V_137 -> V_140 . V_167 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_168 type , int V_169 ,
int V_170 )
{
unsigned long V_29 ;
struct V_124 * V_3 = V_2 -> V_3 ;
struct V_171 * V_172 ;
int V_130 = 0 ;
T_3 V_173 ;
V_172 = F_6 ( sizeof( * V_172 ) , V_8 ) ;
if ( ! V_172 )
return - V_27 ;
V_172 -> V_174 = V_175 ;
V_172 -> V_176 = V_177 ;
V_172 -> V_16 = V_16 ;
V_172 -> V_178 = V_179 ;
V_172 -> type = type ;
V_172 -> V_180 = V_2 -> V_180 ;
V_172 -> V_169 = V_169 ;
V_172 -> V_170 = V_170 ;
if ( type == V_181 ) {
V_172 -> V_178 += ( V_182 / 10 ) ;
if ( V_2 -> V_183 ) {
F_35 ( V_172 ) ;
F_33 ( 1 ) ;
return - V_43 ;
}
V_2 -> V_183 = V_172 ;
}
if ( type == V_23 ) {
V_172 -> V_184 = F_36 ( F_37 ( V_16 ) -> V_107 ) ;
F_38 ( & V_172 -> V_16 -> V_185 ) ;
F_39 ( & V_2 -> V_186 , V_29 ) ;
V_2 -> V_187 = V_172 ;
F_2 ( V_2 ) ;
F_40 ( & V_2 -> V_186 , V_29 ) ;
V_172 -> V_178 = V_179 + V_188 ;
V_130 = F_41 ( V_172 -> V_16 , V_2 -> V_180 ) ;
if ( V_130 != V_189 ) {
F_7 ( V_14 , L_26
L_27 , V_172 , V_179 ) ;
V_172 -> V_178 = V_179 ;
V_130 = V_189 ;
} else {
V_190 ++ ;
if ( ! V_169 ) {
F_42 ( V_2 ) ;
if ( V_170 )
F_4 ( V_3 , V_2 ) ;
return V_130 ;
}
}
}
V_173 = F_43 ( & V_3 -> V_191 ) ;
if ( ! V_173 ) {
V_3 -> V_191 . V_192 = V_172 -> V_178 ;
F_44 ( & V_3 -> V_191 ) ;
}
return V_130 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_193 * V_7 = V_2 -> V_7 ;
enum V_194 V_32 = V_2 -> V_32 ;
V_2 -> V_32 = V_195 ;
switch ( V_32 ) {
case V_196 :
case V_197 :
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_198 :
case V_33 :
if ( V_2 -> V_7 )
V_7 -> V_199 ( V_7 ) ;
F_46 ( V_2 , NULL ) ;
break;
default:
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
F_5 ( V_2 , V_200 ) ;
}
}
static void F_47 ( struct V_1 * V_2 , T_3 V_201 )
{
struct V_171 * V_183 = V_2 -> V_183 ;
struct V_193 * V_7 = V_2 -> V_7 ;
struct V_134 * V_137 ;
unsigned long V_202 ;
if ( ! V_183 )
return;
V_137 = (struct V_134 * ) V_183 -> V_16 ;
if ( V_137 ) {
F_39 ( & V_137 -> V_203 , V_202 ) ;
if ( V_137 -> V_7 ) {
F_7 ( V_14 , L_28
L_29
L_30
L_31 , V_137 -> V_140 . V_204 , V_7 ,
F_26 ( & V_137 -> V_205 ) ) ;
V_137 -> V_206 = V_207 ;
V_137 -> V_208 = V_209 ;
V_137 -> V_210 = V_211 ;
F_40 ( & V_137 -> V_203 , V_202 ) ;
F_48 ( V_137 ) ;
} else {
F_40 ( & V_137 -> V_203 , V_202 ) ;
F_7 ( V_14 , L_28
L_29
L_32
L_31 , V_137 -> V_140 . V_204 , V_7 ,
F_26 ( & V_137 -> V_205 ) ) ;
}
} else if ( V_201 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_2 -> V_7 )
V_7 -> V_199 ( V_7 ) ;
F_35 ( V_183 ) ;
V_2 -> V_183 = NULL ;
}
static void F_49 ( unsigned long V_212 )
{
unsigned long V_29 ;
unsigned long V_213 = V_179 + V_214 ;
struct V_1 * V_2 ;
struct V_171 * V_187 , * V_183 ;
struct V_215 * V_216 ;
struct V_215 * V_217 ;
struct V_124 * V_3 = V_218 ;
T_3 V_219 = 0 ;
unsigned long V_178 ;
int V_130 = V_189 ;
struct V_215 V_220 ;
F_50 ( & V_220 ) ;
F_39 ( & V_3 -> V_221 , V_29 ) ;
F_51 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_2 = F_52 ( V_217 , struct V_1 , V_222 ) ;
if ( ( V_2 -> V_183 ) || ( V_2 -> V_187 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_223 , & V_220 ) ;
}
}
F_40 ( & V_3 -> V_221 , V_29 ) ;
F_51 (list_node, list_core_temp, &timer_list) {
V_2 = F_52 ( V_217 , struct V_1 ,
V_223 ) ;
V_183 = V_2 -> V_183 ;
if ( V_183 ) {
if ( F_54 ( V_183 -> V_178 , V_179 ) ) {
if ( V_213 > V_183 -> V_178 ||
! V_219 ) {
V_213 = V_183 -> V_178 ;
V_219 = 1 ;
}
} else {
F_47 ( V_2 , 1 ) ;
}
}
F_39 ( & V_2 -> V_186 , V_29 ) ;
do {
V_187 = V_2 -> V_187 ;
if ( ! V_187 )
break;
if ( F_54 ( V_187 -> V_178 , V_179 ) ) {
if ( V_2 -> V_32 != V_224 ) {
if ( ( V_213 >
V_187 -> V_178 ) ||
! V_219 ) {
V_213 =
V_187 -> V_178 ;
V_219 = 1 ;
}
} else {
F_55 ( V_2 ) ;
}
break;
}
if ( ( V_2 -> V_32 == V_224 ) ||
( V_2 -> V_32 == V_195 ) ) {
F_55 ( V_2 ) ;
break;
}
if ( ! V_187 -> V_176 ||
! V_187 -> V_174 ) {
V_225 ++ ;
F_55 ( V_2 ) ;
F_40 (
& V_2 -> V_186 , V_29 ) ;
F_45 ( V_2 ) ;
V_2 -> V_32 = V_195 ;
F_39 ( & V_2 -> V_186 ,
V_29 ) ;
break;
}
F_38 ( & V_187 -> V_16 -> V_185 ) ;
V_226 ++ ;
F_7 ( V_14 , L_33
L_34
L_35
L_36
L_37 , V_187 , V_2 , V_179 ,
V_187 -> V_178 ,
V_187 -> V_176 ,
V_187 -> V_184 ,
V_2 -> V_99 . V_227 ) ;
F_40 ( & V_2 -> V_186 ,
V_29 ) ;
V_130 = F_41 ( V_187 -> V_16 , V_2 -> V_180 ) ;
F_39 ( & V_2 -> V_186 , V_29 ) ;
if ( V_130 != V_189 ) {
F_7 ( V_14 , L_38
L_39 , V_2 ) ;
V_228 ++ ;
V_187 -> V_174 -- ;
V_213 = V_179 + V_229 ;
V_219 = 1 ;
break;
} else {
V_190 ++ ;
}
F_7 ( V_14 , L_40
L_41 ,
V_187 -> V_176 ,
V_187 -> V_174 ) ;
if ( V_187 -> V_169 ) {
V_187 -> V_176 -- ;
V_178 = ( V_188 <<
( V_177 - V_187 -> V_176 ) ) ;
V_187 -> V_178 = V_179 +
F_56 ( V_178 , V_230 ) ;
if ( V_213 > V_187 -> V_178 ||
! V_219 ) {
V_213 = V_187 -> V_178 ;
V_219 = 1 ;
}
} else {
int V_170 ;
V_170 =
V_187 -> V_170 ;
F_7 ( V_14 , L_42 ,
V_2 , V_2 -> V_32 ) ;
F_55 ( V_2 ) ;
if ( V_170 )
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
} while ( 0 );
F_40 ( & V_2 -> V_186 , V_29 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_219 ) {
if ( ! F_43 ( & V_3 -> V_191 ) ) {
V_3 -> V_191 . V_192 = V_213 ;
F_44 ( & V_3 -> V_191 ) ;
}
}
}
static int F_57 ( struct V_1 * V_2 , T_3 V_231 ,
struct V_15 * V_16 )
{
int V_130 ;
int V_29 = V_113 ;
char V_232 [ sizeof( struct V_233 ) +
sizeof( struct V_234 ) + sizeof( struct V_235 ) +
V_236 ] ;
int V_237 = 0 ;
union V_238 * V_69 ;
if ( ! V_2 )
return - V_43 ;
V_69 = (union V_238 * ) & V_232 [ V_237 ] ;
V_69 -> V_239 . V_240 = V_241 ;
V_69 -> V_239 . V_242 = sizeof( struct V_233 ) ;
V_69 -> V_239 . V_243 = F_22 ( V_2 -> V_99 . V_243 ) ;
V_237 += sizeof( struct V_233 ) ;
V_69 = (union V_238 * ) & V_232 [ V_237 ] ;
V_69 -> V_244 . V_240 = V_245 ;
V_69 -> V_244 . V_242 = sizeof( struct V_234 ) ;
V_69 -> V_244 . V_246 = V_2 -> V_99 . V_247 ;
V_237 += sizeof( struct V_234 ) ;
if ( V_231 && ! ( V_248 & V_249 ) ) {
V_69 = (union V_238 * ) & V_232 [ V_237 ] ;
V_69 -> V_250 . V_240 = V_251 ;
V_69 -> V_250 . V_242 = sizeof( struct V_235 ) ;
V_237 += sizeof( struct V_235 ) ;
V_69 = (union V_238 * ) & V_232 [ V_237 ] ;
V_69 -> V_252 = 1 ;
V_237 += 1 ;
V_69 = (union V_238 * ) & V_232 [ V_237 ] ;
V_69 -> V_252 = 1 ;
V_237 += 1 ;
}
V_69 = (union V_238 * ) & V_232 [ V_237 ] ;
V_69 -> V_252 = V_253 ;
V_237 += 1 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
if ( V_231 )
V_29 |= V_22 ;
F_11 ( V_16 , V_2 , V_232 , V_237 , NULL , 0 , V_29 ) ;
V_130 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_130 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_130 ;
int V_29 = V_116 | V_22 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - V_27 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_29 ) ;
V_130 = F_12 ( V_2 , V_16 , V_23 , 0 , 1 ) ;
return V_130 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_130 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 ) ;
V_130 = F_12 ( V_2 , V_16 , V_23 , 0 , 0 ) ;
return V_130 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_130 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 | V_31 ) ;
V_130 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_130 ;
}
static struct V_1 * F_60 ( struct V_124 * V_3 ,
T_2 V_12 , T_5 V_10 , T_2 V_13 , T_5 V_11 )
{
unsigned long V_29 ;
struct V_215 * V_254 ;
struct V_1 * V_2 ;
V_254 = & V_3 -> V_255 ;
F_39 ( & V_3 -> V_221 , V_29 ) ;
F_61 (cm_node, hte, list) {
F_7 ( V_14 , L_43 ,
V_2 -> V_11 , V_2 -> V_13 ,
V_11 , V_13 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_10 , V_12 ) ;
if ( ( V_2 -> V_11 == V_11 ) && ( V_2 -> V_13 == V_13 ) &&
( V_2 -> V_10 == V_10 ) && ( V_2 -> V_12 == V_12 ) ) {
F_2 ( V_2 ) ;
F_40 ( & V_3 -> V_221 , V_29 ) ;
return V_2 ;
}
}
F_40 ( & V_3 -> V_221 , V_29 ) ;
return NULL ;
}
static struct V_256 * F_62 ( struct V_124 * V_3 ,
T_5 V_257 , T_2 V_258 , enum V_259 V_260 )
{
unsigned long V_29 ;
struct V_256 * V_261 ;
F_39 ( & V_3 -> V_262 , V_29 ) ;
F_61 (listen_node, &cm_core->listen_list.list, list) {
if ( ( ( V_261 -> V_11 == V_257 ) ||
V_261 -> V_11 == 0x00000000 ) &&
( V_261 -> V_13 == V_258 ) &&
( V_260 & V_261 -> V_260 ) ) {
F_38 ( & V_261 -> V_263 ) ;
F_40 ( & V_3 -> V_262 , V_29 ) ;
return V_261 ;
}
}
F_40 ( & V_3 -> V_262 , V_29 ) ;
return NULL ;
}
static int F_63 ( struct V_124 * V_3 , struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_215 * V_254 ;
if ( ! V_2 || ! V_3 )
return - V_43 ;
F_7 ( V_14 , L_44 ,
V_2 ) ;
F_39 ( & V_3 -> V_221 , V_29 ) ;
V_254 = & V_3 -> V_255 ;
F_64 ( & V_2 -> V_222 , V_254 ) ;
F_38 ( & V_3 -> V_264 ) ;
F_40 ( & V_3 -> V_221 , V_29 ) ;
return 0 ;
}
static int F_65 ( struct V_124 * V_3 ,
struct V_256 * V_265 , int V_266 )
{
int V_130 = - V_43 ;
int V_267 = 0 ;
unsigned long V_29 ;
struct V_215 * V_268 = NULL ;
struct V_215 * V_269 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_215 V_270 ;
F_7 ( V_14 , L_45
L_46 , V_265 , V_266 ,
F_26 ( & V_265 -> V_263 ) ) ;
F_50 ( & V_270 ) ;
if ( V_266 ) {
F_39 ( & V_3 -> V_221 , V_29 ) ;
F_51 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_52 ( V_268 , struct V_1 ,
V_222 ) ;
if ( ( V_2 -> V_265 == V_265 ) &&
( ! V_2 -> V_271 ) ) {
F_2 ( V_2 ) ;
F_53 ( & V_2 -> V_272 , & V_270 ) ;
}
}
F_40 ( & V_3 -> V_221 , V_29 ) ;
}
F_51 (list_pos, list_temp, &reset_list) {
V_2 = F_52 ( V_268 , struct V_1 ,
V_272 ) ;
{
struct V_1 * V_273 = V_2 -> V_274 ;
enum V_194 V_275 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_273 ) {
F_42 ( V_2 ) ;
V_267 = F_46 ( V_2 , NULL ) ;
if ( V_267 ) {
V_2 -> V_32 =
V_195 ;
F_33 ( 1 ) ;
} else {
V_275 = V_2 -> V_32 ;
V_2 -> V_32 = V_276 ;
if ( V_275 != V_277 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_273 ;
V_6 . V_9 . V_10 =
V_273 -> V_10 ;
V_6 . V_9 . V_11 =
V_273 -> V_11 ;
V_6 . V_9 . V_12 =
V_273 -> V_12 ;
V_6 . V_9 . V_13 =
V_273 -> V_13 ;
V_6 . V_9 . V_7 = V_273 -> V_7 ;
F_2 ( V_273 ) ;
V_273 -> V_32 = V_195 ;
F_66 ( & V_6 ) ;
V_2 -> V_32 = V_276 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_39 ( & V_3 -> V_262 , V_29 ) ;
if ( ! F_67 ( & V_265 -> V_263 ) ) {
F_68 ( & V_265 -> V_222 ) ;
F_69 ( & V_3 -> V_126 ) ;
F_40 ( & V_3 -> V_262 , V_29 ) ;
if ( V_265 -> V_278 )
F_70 ( V_265 -> V_278 , V_265 -> V_13 ,
F_71 ( V_265 -> V_278 -> V_279 -> V_280 -> V_281 ) , V_282 ) ;
F_7 ( V_14 , L_47 , V_265 ) ;
F_35 ( V_265 ) ;
V_265 = NULL ;
V_130 = 0 ;
F_38 ( & V_283 ) ;
} else {
F_40 ( & V_3 -> V_262 , V_29 ) ;
}
if ( V_265 ) {
if ( F_26 ( & V_265 -> V_284 ) > 0 )
F_7 ( V_14 , L_48
L_49 ,
V_265 , F_26 ( & V_265 -> V_284 ) ) ;
}
return V_130 ;
}
static int F_72 ( struct V_124 * V_3 ,
struct V_256 * V_265 )
{
V_265 -> V_260 = V_285 ;
V_265 -> V_7 = NULL ;
return F_65 ( V_3 , V_265 , 1 ) ;
}
static inline int F_73 ( struct V_124 * V_3 ,
struct V_1 * V_2 )
{
T_3 V_173 ;
V_2 -> V_271 = 1 ;
if ( V_2 -> V_286 ) {
F_74 ( ! V_2 -> V_265 ) ;
F_69 ( & V_2 -> V_265 -> V_284 ) ;
V_2 -> V_286 = 0 ;
F_74 ( F_26 ( & V_2 -> V_265 -> V_284 ) < 0 ) ;
}
V_173 = F_43 ( & V_3 -> V_191 ) ;
if ( ! V_173 ) {
V_3 -> V_191 . V_192 = V_179 + V_229 ;
F_44 ( & V_3 -> V_191 ) ;
}
return 0 ;
}
static int F_75 ( struct V_287 * V_278 , T_3 V_288 , int V_289 )
{
struct V_290 * V_291 ;
struct V_292 * V_293 ;
int V_294 = V_289 ;
struct V_295 * V_180 ;
struct V_296 * V_297 = V_278 -> V_279 -> V_297 ;
V_291 = F_76 ( & V_298 , F_23 ( V_288 ) , 0 , 0 , 0 ) ;
if ( F_77 ( V_291 ) ) {
F_32 ( V_152 L_50 ,
V_153 , V_288 ) ;
return V_294 ;
}
if ( F_78 ( V_278 -> V_180 ) )
V_180 = V_278 -> V_180 -> V_299 ;
else
V_180 = V_278 -> V_180 ;
F_79 () ;
V_293 = F_80 ( & V_291 -> V_300 ) ;
if ( V_293 ) {
if ( V_293 -> V_301 & V_302 ) {
F_7 ( V_14 , L_51
L_52 , V_288 ,
V_293 -> V_303 , F_36 ( V_291 -> V_304 ) ) ;
if ( V_289 >= 0 ) {
if ( ! memcmp ( V_297 -> V_305 [ V_289 ] . V_306 ,
V_293 -> V_303 , V_89 ) ) {
goto V_307;
}
F_81 ( V_278 -> V_180 ,
V_297 -> V_305 [ V_289 ] . V_306 ,
V_288 , V_308 ) ;
}
F_81 ( V_278 -> V_180 , V_293 -> V_303 ,
V_288 , V_309 ) ;
V_294 = F_82 ( V_278 -> V_279 , V_288 , NULL ,
V_310 ) ;
} else {
F_83 ( V_293 , NULL ) ;
}
}
V_307:
F_84 () ;
F_85 ( V_291 ) ;
return V_294 ;
}
static struct V_1 * F_86 ( struct V_124 * V_3 ,
struct V_287 * V_278 , struct V_311 * V_9 ,
struct V_256 * V_265 )
{
struct V_1 * V_2 ;
struct V_312 V_313 ;
int V_314 = 0 ;
int V_289 = 0 ;
struct V_315 * V_279 ;
struct V_296 * V_297 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_48 = V_316 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_55 = V_60 ;
V_2 -> V_56 = V_60 ;
F_7 ( V_14 , L_53 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_265 = V_265 ;
V_2 -> V_180 = V_278 -> V_180 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_91 , V_278 -> V_180 -> V_317 , V_89 ) ;
F_7 ( V_14 , L_54 , V_2 -> V_265 ,
V_2 -> V_7 ) ;
F_87 ( & V_2 -> V_186 ) ;
V_2 -> V_274 = NULL ;
F_88 ( & V_2 -> V_263 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_99 . V_100 = V_318 ;
V_2 -> V_99 . V_247 = V_319 ;
V_2 -> V_99 . V_120 = V_320 >>
V_319 ;
V_313 = F_89 () ;
V_2 -> V_99 . V_108 = F_23 ( V_313 . V_321 ) ;
V_2 -> V_99 . V_243 = V_278 -> V_322 - sizeof( struct V_75 ) -
sizeof( struct V_73 ) - V_81 - V_323 ;
V_2 -> V_99 . V_110 = 0 ;
F_38 ( & V_3 -> V_127 ) ;
V_2 -> V_324 = V_9 -> V_324 ;
V_2 -> V_325 = 0 ;
V_2 -> V_286 = 0 ;
V_2 -> V_278 = V_278 ;
V_279 = V_278 -> V_279 ;
V_297 = V_279 -> V_297 ;
V_2 -> V_274 = NULL ;
if ( F_90 ( F_23 ( V_2 -> V_10 ) ) ) {
V_289 = F_82 ( V_279 , F_36 ( V_278 -> V_326 ) , NULL , V_310 ) ;
} else {
V_314 = F_82 ( V_279 , V_2 -> V_10 , NULL , V_310 ) ;
V_289 = F_75 ( V_278 , V_9 -> V_10 , V_314 ) ;
}
if ( V_289 < 0 ) {
F_35 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_88 , V_297 -> V_305 [ V_289 ] . V_306 , V_89 ) ;
F_7 ( V_14 , L_55 ,
V_2 -> V_88 ) ;
F_63 ( V_3 , V_2 ) ;
F_38 ( & V_327 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_263 ) ;
return 0 ;
}
static int F_4 ( struct V_124 * V_3 ,
struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_134 * V_137 ;
if ( ! V_2 )
return - V_43 ;
F_39 ( & V_2 -> V_3 -> V_221 , V_29 ) ;
if ( F_67 ( & V_2 -> V_263 ) ) {
F_40 ( & V_2 -> V_3 -> V_221 , V_29 ) ;
return 0 ;
}
F_68 ( & V_2 -> V_222 ) ;
F_69 ( & V_3 -> V_264 ) ;
F_40 ( & V_2 -> V_3 -> V_221 , V_29 ) ;
if ( ! V_2 -> V_271 && V_2 -> V_286 ) {
F_74 ( ! V_2 -> V_265 ) ;
F_69 ( & V_2 -> V_265 -> V_284 ) ;
F_74 ( F_26 ( & V_2 -> V_265 -> V_284 ) < 0 ) ;
}
F_33 ( V_2 -> V_187 ) ;
if ( V_2 -> V_183 )
F_47 ( V_2 , 0 ) ;
if ( V_2 -> V_265 ) {
F_65 ( V_3 , V_2 -> V_265 , 0 ) ;
} else {
if ( V_2 -> V_325 && V_2 -> V_278 ) {
F_70 ( V_2 -> V_278 , V_2 -> V_13 ,
F_71 (
V_2 -> V_278 -> V_279 -> V_280 -> V_281 ) ,
V_282 ) ;
}
}
F_69 ( & V_3 -> V_127 ) ;
F_38 ( & V_328 ) ;
V_137 = V_2 -> V_137 ;
if ( V_137 ) {
V_137 -> V_2 = NULL ;
F_91 ( & V_137 -> V_329 ) ;
V_2 -> V_137 = NULL ;
}
F_35 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , T_1 * V_330 ,
T_3 V_70 , T_3 V_331 )
{
T_3 V_332 ;
T_3 V_333 = 0 ;
union V_238 * V_334 ;
char V_335 = 0 ;
while ( V_333 < V_70 ) {
V_334 = (union V_238 * ) ( V_330 + V_333 ) ;
switch ( V_334 -> V_250 . V_240 ) {
case V_253 :
V_333 = V_70 ;
break;
case V_336 :
V_333 += 1 ;
continue;
case V_241 :
F_7 ( V_14 , L_56
L_57 , V_153 ,
V_334 -> V_239 . V_242 , V_333 , V_70 ) ;
V_335 = 1 ;
if ( V_334 -> V_239 . V_242 != 4 ) {
return 1 ;
} else {
V_332 = F_16 ( V_334 -> V_239 . V_243 ) ;
if ( V_332 > 0 && V_332 <
V_2 -> V_99 . V_243 )
V_2 -> V_99 . V_243 = V_332 ;
}
break;
case V_245 :
V_2 -> V_99 . V_337 =
V_334 -> V_244 . V_246 ;
break;
default:
F_7 ( V_14 , L_58 ,
V_334 -> V_250 . V_240 ) ;
break;
}
V_333 += V_334 -> V_250 . V_242 ;
}
if ( ( ! V_335 ) && ( V_331 ) )
V_2 -> V_99 . V_243 = V_338 ;
return 0 ;
}
static void F_93 ( struct V_15 * V_16 )
{
F_38 ( & V_339 ) ;
F_94 ( V_16 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_59
L_46 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_263 ) ) ;
switch ( V_2 -> V_32 ) {
case V_196 :
case V_340 :
case V_341 :
case V_342 :
V_2 -> V_99 . V_110 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_198 ;
F_59 ( V_2 , NULL ) ;
break;
case V_49 :
F_5 ( V_2 , V_200 ) ;
V_2 -> V_99 . V_110 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_195 ;
F_2 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_33 :
V_2 -> V_99 . V_110 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_197 ;
F_58 ( V_2 , NULL ) ;
break;
case V_343 :
V_2 -> V_99 . V_110 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_344 ;
F_58 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_181 , 1 , 0 ) ;
break;
case V_344 :
V_2 -> V_99 . V_110 ++ ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_195 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_224 :
default:
F_7 ( V_14 , L_60 ,
V_2 , V_2 -> V_32 ) ;
break;
}
}
static void F_96 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_73 * V_74 )
{
int V_345 = 0 ;
F_38 ( & V_346 ) ;
F_7 ( V_14 , L_61
L_62 , V_2 , V_2 -> V_32 ,
F_26 ( & V_2 -> V_263 ) ) ;
F_42 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_340 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_153 , __LINE__ , V_2 ,
V_2 -> V_265 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_340 ;
if ( F_57 ( V_2 , 0 , NULL ) ) {
F_97 ( V_2 , V_16 , V_345 ) ;
}
break;
case V_46 :
default:
F_97 ( V_2 , V_16 , V_345 ) ;
break;
}
break;
case V_277 :
F_38 ( & V_2 -> V_347 ) ;
F_94 ( V_16 ) ;
break;
case V_341 :
case V_196 :
case V_348 :
F_7 ( V_14 , L_65 , V_153 , __LINE__ ) ;
F_98 ( V_2 , V_16 , V_345 ) ;
break;
case V_224 :
F_97 ( V_2 , V_16 , V_345 ) ;
break;
case V_195 :
F_93 ( V_16 ) ;
break;
case V_343 :
case V_33 :
case V_198 :
V_2 -> V_7 -> V_199 ( V_2 -> V_7 ) ;
case V_344 :
V_2 -> V_32 = V_195 ;
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
int V_130 = 0 ;
int V_72 = V_16 -> V_35 ;
T_1 * V_349 = V_16 -> V_71 ;
enum V_5 type = V_350 ;
T_3 V_351 ;
V_130 = F_15 ( V_2 , V_349 , & V_351 , V_72 ) ;
if ( V_130 ) {
F_7 ( V_14 , L_66 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_67
L_68 , V_153 ,
__LINE__ , V_2 , V_2 -> V_265 ,
V_2 -> V_32 ) ;
F_97 ( V_2 , V_16 , 1 ) ;
} else {
F_98 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_341 :
if ( V_351 == V_68 )
F_33 ( 1 ) ;
V_2 -> V_32 = V_277 ;
type = V_352 ;
F_88 ( & V_2 -> V_347 ,
V_353 ) ;
break;
case V_49 :
F_42 ( V_2 ) ;
if ( V_351 == V_68 ) {
type = V_354 ;
V_2 -> V_32 = V_342 ;
} else {
type = V_355 ;
V_2 -> V_32 = V_224 ;
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
case V_340 :
case V_49 :
F_7 ( V_14 , L_63
L_64 , V_153 , __LINE__ , V_2 ,
V_2 -> V_265 , V_2 -> V_32 ) ;
F_97 ( V_2 , V_16 , 1 ) ;
break;
case V_341 :
case V_196 :
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_224 :
default:
F_93 ( V_16 ) ;
}
}
static int F_101 ( struct V_1 * V_2 , struct V_73 * V_74 ,
struct V_15 * V_16 )
{
int V_267 ;
V_267 = ( ( F_36 ( V_74 -> V_111 ) == V_2 -> V_99 . V_108 ) ) ? 0 : 1 ;
if ( V_267 )
F_97 ( V_2 , V_16 , 1 ) ;
return V_267 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_73 * V_74 ,
struct V_15 * V_16 )
{
int V_267 = 0 ;
T_3 V_107 ;
T_3 V_111 ;
T_3 V_108 = V_2 -> V_99 . V_108 ;
T_3 V_110 = V_2 -> V_99 . V_110 ;
T_3 V_120 ;
V_107 = F_36 ( V_74 -> V_107 ) ;
V_111 = F_36 ( V_74 -> V_111 ) ;
V_120 = V_2 -> V_99 . V_120 ;
if ( V_111 != V_108 )
V_267 = 1 ;
else if ( ! F_103 ( V_107 , V_110 , ( V_110 + V_120 ) ) )
V_267 = 1 ;
if ( V_267 ) {
F_7 ( V_14 , L_63
L_64 , V_153 , __LINE__ , V_2 ,
V_2 -> V_265 , V_2 -> V_32 ) ;
F_100 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_69
L_70 , V_2 , V_107 , V_110 ,
V_120 ) ;
}
return V_267 ;
}
static void F_104 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_73 * V_74 )
{
int V_130 ;
T_3 V_356 ;
int V_70 ;
V_70 = ( V_74 -> V_118 << 2 ) - sizeof( struct V_73 ) ;
F_17 ( V_16 , 0 ) ;
V_356 = F_36 ( V_74 -> V_107 ) ;
switch ( V_2 -> V_32 ) {
case V_340 :
case V_49 :
F_97 ( V_2 , V_16 , 1 ) ;
break;
case V_348 :
if ( F_26 ( & V_2 -> V_265 -> V_284 ) >
V_2 -> V_265 -> V_357 ) {
F_7 ( V_14 , L_71
L_72 ) ;
V_358 ++ ;
F_98 ( V_2 , V_16 , 0 ) ;
break;
}
V_130 = F_105 ( V_2 , V_74 , V_16 , V_70 ,
1 ) ;
if ( V_130 ) {
F_98 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_99 . V_110 = V_356 + 1 ;
F_74 ( V_2 -> V_187 ) ;
V_2 -> V_286 = 1 ;
F_38 ( & V_2 -> V_265 -> V_284 ) ;
V_2 -> V_32 = V_196 ;
F_57 ( V_2 , 1 , V_16 ) ;
break;
case V_195 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_224 :
case V_341 :
case V_33 :
case V_343 :
case V_277 :
case V_198 :
case V_197 :
case V_359 :
default:
F_93 ( V_16 ) ;
break;
}
}
static void F_106 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_73 * V_74 )
{
int V_130 ;
T_3 V_356 ;
int V_70 ;
V_70 = ( V_74 -> V_118 << 2 ) - sizeof( struct V_73 ) ;
F_17 ( V_16 , 0 ) ;
V_356 = F_36 ( V_74 -> V_107 ) ;
switch ( V_2 -> V_32 ) {
case V_340 :
F_42 ( V_2 ) ;
if ( F_101 ( V_2 , V_74 , V_16 ) )
return;
V_2 -> V_99 . V_227 = F_36 ( V_74 -> V_111 ) ;
V_130 = F_105 ( V_2 , V_74 , V_16 , V_70 , 0 ) ;
if ( V_130 ) {
F_7 ( V_14 , L_73 ,
V_2 ) ;
break;
}
F_42 ( V_2 ) ;
V_2 -> V_99 . V_110 = V_356 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_277 :
F_98 ( V_2 , V_16 , 1 ) ;
break;
case V_348 :
V_2 -> V_99 . V_108 = F_36 ( V_74 -> V_111 ) ;
F_42 ( V_2 ) ;
V_2 -> V_32 = V_195 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_195 :
V_2 -> V_99 . V_108 = F_36 ( V_74 -> V_111 ) ;
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_341 :
case V_33 :
case V_343 :
case V_198 :
case V_224 :
case V_197 :
case V_359 :
case V_49 :
default:
F_93 ( V_16 ) ;
break;
}
}
static int F_107 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_73 * V_74 )
{
int V_72 = 0 ;
T_3 V_356 ;
int V_130 = 0 ;
int V_70 ;
V_70 = ( V_74 -> V_118 << 2 ) - sizeof( struct V_73 ) ;
if ( F_102 ( V_2 , V_74 , V_16 ) )
return - V_43 ;
F_108 ( V_16 , V_74 -> V_118 << 2 ) ;
V_356 = F_36 ( V_74 -> V_107 ) ;
V_72 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_196 :
F_42 ( V_2 ) ;
V_130 = F_105 ( V_2 , V_74 , V_16 , V_70 , 1 ) ;
if ( V_130 )
break;
V_2 -> V_99 . V_227 = F_36 ( V_74 -> V_111 ) ;
V_2 -> V_32 = V_341 ;
if ( V_72 ) {
V_2 -> V_99 . V_110 = V_356 + V_72 ;
F_99 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
break;
case V_341 :
F_42 ( V_2 ) ;
if ( V_72 ) {
V_2 -> V_99 . V_110 = V_356 + V_72 ;
F_99 ( V_2 , V_16 ) ;
} else {
F_93 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_99 . V_227 = F_36 ( V_74 -> V_111 ) ;
if ( V_72 ) {
V_2 -> V_99 . V_110 = V_356 + V_72 ;
F_99 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
break;
case V_348 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_195 ;
F_46 ( V_2 , V_16 ) ;
break;
case V_195 :
F_42 ( V_2 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
break;
case V_198 :
case V_197 :
F_42 ( V_2 ) ;
V_2 -> V_32 = V_195 ;
V_2 -> V_7 -> V_199 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_93 ( V_16 ) ;
break;
case V_33 :
F_42 ( V_2 ) ;
F_93 ( V_16 ) ;
V_2 -> V_32 = V_343 ;
break;
case V_340 :
case V_343 :
case V_224 :
case V_277 :
case V_359 :
default:
F_42 ( V_2 ) ;
F_93 ( V_16 ) ;
break;
}
return V_130 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_73 * V_74 ,
struct V_15 * V_16 , int V_70 , int V_360 )
{
T_1 * V_330 = ( T_1 * ) & V_74 [ 1 ] ;
if ( V_70 ) {
if ( F_92 ( V_2 , V_330 , V_70 ,
( T_3 ) V_74 -> V_114 ) ) {
F_7 ( V_14 , L_74 ,
V_153 , V_2 ) ;
if ( V_360 )
F_98 ( V_2 , V_16 , 1 ) ;
else
F_97 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_99 . V_361 = F_16 ( V_74 -> V_119 ) <<
V_2 -> V_99 . V_337 ;
if ( V_2 -> V_99 . V_361 > V_2 -> V_99 . V_362 )
V_2 -> V_99 . V_362 = V_2 -> V_99 . V_361 ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_345 )
{
F_42 ( V_2 ) ;
if ( V_345 ) {
F_7 ( V_14 , L_75
L_76 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_46 ( V_2 , V_16 ) ;
} else {
F_94 ( V_16 ) ;
}
V_2 -> V_32 = V_195 ;
F_5 ( V_2 , V_200 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_345 )
{
F_42 ( V_2 ) ;
V_2 -> V_32 = V_195 ;
if ( V_345 ) {
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
struct V_171 * V_187 ;
V_187 = V_2 -> V_187 ;
if ( V_187 ) {
V_2 -> V_187 = NULL ;
F_94 ( V_187 -> V_16 ) ;
F_35 ( V_187 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_39 ( & V_2 -> V_186 , V_29 ) ;
F_55 ( V_2 ) ;
F_40 ( & V_2 -> V_186 , V_29 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_124 * V_3 )
{
enum V_363 V_364 = V_365 ;
struct V_73 * V_74 = F_37 ( V_16 ) ;
T_3 V_366 = 0 ;
int V_130 = 0 ;
F_108 ( V_16 , F_110 ( V_16 ) -> V_95 << 2 ) ;
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 , V_74 -> V_114 ,
V_74 -> V_112 , V_74 -> V_117 , V_74 -> V_115 ) ;
if ( V_74 -> V_117 ) {
V_364 = V_367 ;
} else if ( V_74 -> V_114 ) {
V_364 = V_368 ;
if ( V_74 -> V_112 )
V_364 = V_369 ;
} else if ( V_74 -> V_112 ) {
V_364 = V_370 ;
}
if ( V_74 -> V_115 )
V_366 = 1 ;
switch ( V_364 ) {
case V_368 :
F_104 ( V_2 , V_16 , V_74 ) ;
break;
case V_369 :
F_106 ( V_2 , V_16 , V_74 ) ;
break;
case V_370 :
V_130 = F_107 ( V_2 , V_16 , V_74 ) ;
if ( V_366 && ! V_130 )
F_95 ( V_2 ) ;
break;
case V_367 :
F_96 ( V_2 , V_16 , V_74 ) ;
break;
default:
if ( ( V_366 ) && ( ! F_102 ( V_2 , V_74 , V_16 ) ) )
F_95 ( V_2 ) ;
F_93 ( V_16 ) ;
break;
}
}
static struct V_256 * F_111 ( struct V_124 * V_3 ,
struct V_287 * V_278 , struct V_311 * V_9 )
{
struct V_256 * V_265 ;
unsigned long V_29 ;
F_7 ( V_14 , L_81 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_265 = F_62 ( V_3 , F_23 ( V_9 -> V_11 ) ,
F_22 ( V_9 -> V_13 ) , V_371 ) ;
if ( V_265 && V_265 -> V_260 == V_372 ) {
F_69 ( & V_265 -> V_263 ) ;
F_7 ( V_14 , L_82 ) ;
return NULL ;
}
if ( ! V_265 ) {
V_265 = F_6 ( sizeof( * V_265 ) , V_8 ) ;
if ( ! V_265 ) {
F_7 ( V_14 , L_83 ) ;
return NULL ;
}
V_265 -> V_11 = F_23 ( V_9 -> V_11 ) ;
V_265 -> V_13 = F_22 ( V_9 -> V_13 ) ;
V_265 -> V_373 = 0 ;
F_88 ( & V_265 -> V_263 , 1 ) ;
}
else {
V_265 -> V_373 = 1 ;
}
V_265 -> V_7 = V_9 -> V_7 ;
F_88 ( & V_265 -> V_284 , 0 ) ;
V_265 -> V_3 = V_3 ;
V_265 -> V_278 = V_278 ;
F_38 ( & V_3 -> V_127 ) ;
V_265 -> V_324 = V_9 -> V_324 ;
V_265 -> V_357 = V_9 -> V_357 ;
V_265 -> V_260 = V_372 ;
if ( ! V_265 -> V_373 ) {
F_39 ( & V_3 -> V_262 , V_29 ) ;
F_53 ( & V_265 -> V_222 , & V_3 -> V_374 . V_222 ) ;
F_40 ( & V_3 -> V_262 , V_29 ) ;
F_38 ( & V_3 -> V_126 ) ;
}
F_7 ( V_14 , L_84
L_85 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_265 , V_265 -> V_357 , V_265 -> V_7 ) ;
return V_265 ;
}
static struct V_1 * F_112 ( struct V_124 * V_3 ,
struct V_287 * V_278 , T_2 V_375 ,
void * V_376 , struct V_311 * V_9 )
{
int V_130 = 0 ;
struct V_1 * V_2 ;
struct V_256 * V_377 ;
struct V_1 * V_378 ;
struct V_311 V_379 ;
T_1 * V_19 ;
V_2 = F_86 ( V_3 , V_278 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_99 . V_380 = 1 ;
V_2 -> V_99 . V_247 = V_319 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_377 = F_62 ( V_3 ,
F_36 ( V_278 -> V_326 ) , V_2 -> V_12 ,
V_372 ) ;
if ( V_377 == NULL ) {
F_5 ( V_2 , V_200 ) ;
} else {
V_379 = * V_9 ;
V_379 . V_13 = V_9 -> V_12 ;
V_379 . V_12 = V_9 -> V_13 ;
V_379 . V_7 = V_377 -> V_7 ;
V_378 = F_86 ( V_3 , V_278 ,
& V_379 , V_377 ) ;
if ( ! V_378 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_38 ( & V_381 ) ;
V_378 -> V_274 = V_2 ;
V_378 -> V_99 . V_247 =
V_319 ;
V_2 -> V_274 = V_378 ;
memcpy ( V_378 -> V_67 , V_376 ,
V_375 ) ;
V_378 -> V_54 = V_375 ;
V_2 -> V_32 = V_224 ;
V_2 -> V_99 . V_110 =
V_378 -> V_99 . V_108 ;
V_378 -> V_99 . V_110 =
V_2 -> V_99 . V_108 ;
V_2 -> V_99 . V_362 =
V_378 -> V_99 . V_120 ;
V_378 -> V_99 . V_362 =
V_2 -> V_99 . V_120 ;
V_2 -> V_99 . V_361 =
V_378 -> V_99 . V_120 ;
V_378 -> V_99 . V_361 =
V_2 -> V_99 . V_120 ;
V_2 -> V_99 . V_337 =
V_378 -> V_99 . V_247 ;
V_378 -> V_99 . V_337 =
V_2 -> V_99 . V_247 ;
V_378 -> V_32 = V_277 ;
F_5 ( V_378 , V_352 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_67 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_375 ;
memcpy ( V_19 , V_376 , V_375 ) ;
V_2 -> V_32 = V_340 ;
V_130 = F_57 ( V_2 , 0 , NULL ) ;
if ( V_130 ) {
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
static int F_113 ( struct V_124 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_114 ( struct V_124 * V_3 , struct V_1 * V_2 )
{
int V_130 = 0 ;
int V_267 = 0 ;
int V_347 ;
struct V_4 V_6 ;
struct V_193 * V_7 = V_2 -> V_7 ;
struct V_1 * V_273 = V_2 -> V_274 ;
F_7 ( V_14 , L_90 ,
V_153 , V_2 , V_2 -> V_99 . V_380 , V_2 -> V_32 ) ;
if ( V_2 -> V_99 . V_380 )
return V_130 ;
F_42 ( V_2 ) ;
if ( ! V_273 ) {
V_347 = F_115 ( 1 , & V_2 -> V_347 ) ;
if ( V_347 == V_382 ) {
V_2 -> V_32 = V_195 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_276 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_130 = F_13 ( V_2 ) ;
if ( V_130 ) {
V_2 -> V_32 = V_195 ;
V_267 = F_46 ( V_2 , NULL ) ;
if ( V_267 )
F_33 ( 1 ) ;
} else {
V_7 -> V_383 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_276 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_273 ) ;
} else {
V_6 . V_2 = V_273 ;
V_6 . V_9 . V_10 = V_273 -> V_10 ;
V_6 . V_9 . V_11 = V_273 -> V_11 ;
V_6 . V_9 . V_12 = V_273 -> V_12 ;
V_6 . V_9 . V_13 = V_273 -> V_13 ;
V_6 . V_9 . V_7 = V_273 -> V_7 ;
F_116 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_273 -> V_32 = V_197 ;
V_7 = V_273 -> V_7 ;
F_4 ( V_3 , V_273 ) ;
V_7 -> V_199 ( V_7 ) ;
}
}
return V_130 ;
}
static int F_117 ( struct V_124 * V_3 , struct V_1 * V_2 )
{
int V_130 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_196 :
case V_340 :
case V_384 :
case V_341 :
case V_385 :
case V_49 :
case V_277 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_386 :
V_2 -> V_32 = V_198 ;
F_59 ( V_2 , NULL ) ;
break;
case V_33 :
case V_343 :
case V_198 :
case V_344 :
case V_197 :
V_130 = - 1 ;
break;
case V_348 :
F_42 ( V_2 ) ;
F_46 ( V_2 , NULL ) ;
break;
case V_342 :
case V_359 :
case V_387 :
case V_195 :
case V_276 :
V_130 = F_4 ( V_3 , V_2 ) ;
break;
case V_224 :
if ( V_2 -> V_187 )
F_32 ( V_152 L_91
L_92 , V_2 -> V_187 ) ;
V_130 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_130 ;
}
static int F_118 ( struct V_124 * V_3 ,
struct V_287 * V_278 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_256 * V_265 = NULL ;
struct V_75 * V_76 ;
struct V_73 * V_74 ;
struct V_311 V_388 ;
int V_389 = 1 ;
T_6 V_390 , V_391 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_75 ) + sizeof( struct V_73 ) )
return 0 ;
V_76 = (struct V_75 * ) V_16 -> V_71 ;
V_74 = (struct V_73 * ) ( V_16 -> V_71 + sizeof( struct V_75 ) ) ;
V_388 . V_11 = F_36 ( V_76 -> V_104 ) ;
V_388 . V_13 = F_16 ( V_74 -> V_106 ) ;
V_388 . V_10 = F_36 ( V_76 -> V_103 ) ;
V_388 . V_12 = F_16 ( V_74 -> V_105 ) ;
V_390 = F_119 ( V_76 -> V_104 ) ;
V_391 = F_119 ( V_76 -> V_103 ) ;
F_7 ( V_14 , L_93 ,
& V_390 , V_74 -> V_106 , & V_391 , V_74 -> V_105 ) ;
do {
V_2 = F_60 ( V_3 ,
V_388 . V_12 , V_388 . V_10 ,
V_388 . V_13 , V_388 . V_11 ) ;
if ( ! V_2 ) {
if ( ( ! V_74 -> V_114 ) || ( V_74 -> V_112 ) ) {
V_389 = 0 ;
break;
}
V_265 = F_62 ( V_3 , V_388 . V_11 ,
V_388 . V_13 ,
V_372 ) ;
if ( ! V_265 ) {
V_388 . V_7 = NULL ;
V_388 . V_324 = 0 ;
F_7 ( V_14 , L_94 ) ;
V_389 = 0 ;
break;
}
V_388 . V_7 = V_265 -> V_7 ;
V_388 . V_324 = V_265 -> V_324 ;
V_2 = F_86 ( V_3 , V_278 , & V_388 ,
V_265 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_95
L_96 ) ;
V_225 ++ ;
F_69 ( & V_265 -> V_263 ) ;
F_94 ( V_16 ) ;
break;
}
if ( ! V_74 -> V_117 && ! V_74 -> V_115 ) {
V_2 -> V_32 = V_348 ;
} else {
V_225 ++ ;
F_4 ( V_3 , V_2 ) ;
F_94 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_224 ) {
if ( V_2 -> V_137 -> V_392 )
F_120 ( V_16 , V_278 , V_2 -> V_137 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_38 ( & V_339 ) ;
F_94 ( V_16 ) ;
}
break;
}
F_121 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_74 ) ) ;
V_16 -> V_35 = F_16 ( V_76 -> V_97 ) ;
F_109 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_389 ;
}
static struct V_124 * F_122 ( void )
{
struct V_124 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_393 ) ;
if ( ! V_3 )
return NULL ;
F_50 ( & V_3 -> V_255 ) ;
F_123 ( & V_3 -> V_191 ) ;
V_3 -> V_191 . V_394 = F_49 ;
V_3 -> V_395 = V_396 ;
V_3 -> V_32 = V_387 ;
V_3 -> V_397 = V_398 ;
F_88 ( & V_3 -> V_399 , 0 ) ;
V_3 -> V_400 = & V_401 ;
F_87 ( & V_3 -> V_221 ) ;
F_87 ( & V_3 -> V_262 ) ;
F_50 ( & V_3 -> V_374 . V_222 ) ;
F_7 ( V_14 , L_97 , V_3 ) ;
F_7 ( V_14 , L_98 ) ;
V_3 -> V_402 = F_124 ( L_99 ) ;
V_3 -> V_403 = F_8 ;
F_7 ( V_14 , L_100 ) ;
V_3 -> V_404 = F_124 ( L_101 ) ;
F_25 ( V_3 ) ;
return V_3 ;
}
static int F_125 ( struct V_124 * V_3 )
{
F_7 ( V_14 , L_102 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_126 () ;
if ( F_43 ( & V_3 -> V_191 ) )
F_127 ( & V_3 -> V_191 ) ;
F_128 ( V_3 -> V_402 ) ;
F_128 ( V_3 -> V_404 ) ;
F_7 ( V_14 , L_103 ) ;
F_35 ( V_3 ) ;
return 0 ;
}
static int F_129 ( struct V_124 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_130 ( struct V_124 * V_3 , T_3 type , T_3 V_405 )
{
int V_130 = 0 ;
switch ( type ) {
case V_406 :
V_3 -> V_395 = V_405 ;
break;
case V_407 :
V_3 -> V_397 = V_405 ;
break;
default:
V_130 = - V_43 ;
}
return V_130 ;
}
static int F_131 ( struct V_134 * V_137 , struct V_1 * V_2 )
{
int V_130 = 0 ;
if ( ! V_137 )
return - V_43 ;
V_137 -> V_161 -> V_408 |= F_31 ( V_409 |
V_410 | V_411 |
V_412 ) ;
if ( V_2 -> V_99 . V_337 || V_2 -> V_99 . V_247 )
V_137 -> V_161 -> V_408 |= F_31 ( V_413 ) ;
V_137 -> V_161 -> V_414 |= F_31 ( 64 << V_415 ) ;
V_137 -> V_161 -> V_243 |= F_31 ( ( ( T_3 ) V_2 -> V_99 . V_243 ) << 16 ) ;
V_137 -> V_161 -> V_416 |= F_31 (
( T_3 ) V_417 << V_418 ) ;
V_137 -> V_161 -> V_419 |= F_31 (
( V_2 -> V_99 . V_337 << V_420 ) &
V_421 ) ;
V_137 -> V_161 -> V_419 |= F_31 (
( V_2 -> V_99 . V_247 << V_422 ) &
V_423 ) ;
V_137 -> V_161 -> V_424 = F_31 ( 0x80 ) ;
V_137 -> V_161 -> V_425 = 0 ;
V_137 -> V_161 -> V_426 = 0 ;
V_137 -> V_161 -> V_427 = F_31 ( V_2 -> V_99 . V_108 ) ;
V_137 -> V_161 -> V_361 = F_31 ( V_2 -> V_99 . V_361 ) ;
V_137 -> V_161 -> V_110 = F_31 ( V_2 -> V_99 . V_110 ) ;
V_137 -> V_161 -> V_120 = F_31 ( V_2 -> V_99 . V_120 <<
V_2 -> V_99 . V_247 ) ;
V_137 -> V_161 -> V_428 = F_31 ( V_2 -> V_99 . V_108 ) ;
V_137 -> V_161 -> V_429 = F_31 ( V_2 -> V_99 . V_108 ) ;
V_137 -> V_161 -> V_430 = 0 ;
V_137 -> V_161 -> V_431 = F_31 ( 0x6 ) ;
V_137 -> V_161 -> V_432 = F_31 ( 0x3FFFC000 ) ;
V_137 -> V_161 -> V_433 = F_31 ( 2 * V_2 -> V_99 . V_243 ) ;
V_137 -> V_161 -> V_434 = F_31 ( V_2 -> V_99 . V_110 ) ;
V_137 -> V_161 -> V_435 = F_31 ( V_2 -> V_99 . V_108 ) ;
V_137 -> V_161 -> V_362 = F_31 ( V_2 -> V_99 . V_362 ) ;
F_7 ( V_14 , L_104
L_105 ,
V_137 -> V_140 . V_204 , F_132 ( V_137 -> V_161 -> V_110 ) ,
F_132 ( V_137 -> V_161 -> V_427 ) ,
V_2 -> V_99 . V_243 , F_132 ( V_137 -> V_161 -> V_419 ) ,
F_132 ( V_137 -> V_161 -> V_120 ) ,
F_132 ( V_137 -> V_161 -> V_408 ) ) ;
F_7 ( V_14 , L_106 , F_132 ( V_137 -> V_161 -> V_361 ) ) ;
F_7 ( V_14 , L_107 , F_132 ( V_137 -> V_161 -> V_433 ) ) ;
F_7 ( V_14 , L_108 , F_132 ( V_137 -> V_161 -> V_362 ) ) ;
F_7 ( V_14 , L_109 ) ;
V_2 -> V_32 = V_224 ;
return V_130 ;
}
int F_48 ( struct V_134 * V_137 )
{
struct V_436 * V_437 ;
V_437 = F_6 ( sizeof *V_437 , V_8 ) ;
if ( ! V_437 )
return - V_27 ;
F_133 ( & V_137 -> V_329 ) ;
V_437 -> V_137 = V_137 ;
F_134 ( & V_437 -> V_437 , V_438 ) ;
F_135 ( V_218 -> V_404 , & V_437 -> V_437 ) ;
return 0 ;
}
static void V_438 ( struct V_439 * V_437 )
{
struct V_436 * V_440 = F_52 ( V_437 , struct V_436 , V_437 ) ;
struct V_134 * V_137 = V_440 -> V_137 ;
F_35 ( V_440 ) ;
F_7 ( V_14 , L_110 ,
V_137 -> V_208 , V_137 -> V_140 . V_204 ) ;
F_136 ( V_137 ) ;
F_91 ( & V_137 -> V_329 ) ;
}
static int F_136 ( struct V_134 * V_137 )
{
unsigned long V_29 ;
int V_130 = 0 ;
struct V_193 * V_7 ;
struct V_441 V_442 ;
struct V_287 * V_278 ;
T_2 V_443 ;
T_1 V_444 ;
T_1 V_445 ;
int V_446 = 0 ;
int V_447 = 0 ;
int V_448 = 0 ;
int V_449 = 0 ;
T_3 V_450 = V_451 ;
struct V_452 V_453 ;
if ( ! V_137 ) {
F_7 ( V_14 , L_111 ) ;
return - 1 ;
}
F_39 ( & V_137 -> V_203 , V_29 ) ;
V_7 = V_137 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_112 ,
V_137 -> V_140 . V_204 ) ;
F_40 ( & V_137 -> V_203 , V_29 ) ;
return - 1 ;
}
V_278 = F_137 ( V_137 -> V_329 . V_454 ) ;
F_7 ( V_14 , L_113 , V_137 -> V_140 . V_204 ) ;
V_444 = V_137 -> V_206 ;
V_445 = V_137 -> V_210 ;
V_443 = V_137 -> V_208 ;
if ( V_137 -> V_455 ) {
V_447 = 1 ;
V_448 = 1 ;
V_137 -> V_7 = NULL ;
F_127 ( & V_137 -> V_456 ) ;
if ( V_137 -> V_457 == 0 ) {
V_137 -> V_457 = 1 ;
V_449 = 1 ;
}
} else if ( ( V_444 == V_458 ) ||
( ( V_445 == V_459 ) &&
( V_443 == V_460 ) ) ) {
V_447 = 1 ;
if ( V_443 == V_460 )
V_446 = - V_461 ;
}
if ( ( ( V_444 == V_207 ) ||
( V_444 == V_462 ) ||
( V_443 == V_463 ) ||
( V_443 == V_460 ) ) ) {
V_448 = 1 ;
V_137 -> V_7 = NULL ;
if ( V_137 -> V_457 == 0 ) {
V_137 -> V_457 = 1 ;
V_449 = 1 ;
}
}
F_40 ( & V_137 -> V_203 , V_29 ) ;
if ( ( V_449 ) && ( V_137 -> V_464 == 0 ) ) {
if ( V_137 -> V_465 >= V_466 )
V_450 |= V_467 ;
F_138 ( V_278 -> V_279 , V_137 , V_450 , 1 ) ;
if ( V_137 -> V_455 ) {
V_453 . V_454 = V_137 -> V_329 . V_454 ;
V_453 . V_6 = V_137 -> V_468 ;
V_453 . V_469 . V_470 = & V_137 -> V_329 ;
V_137 -> V_329 . V_471 ( & V_453 , V_137 -> V_329 . V_472 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_471 ) ) {
if ( V_447 ) {
F_38 ( & V_473 ) ;
V_442 . V_6 = V_474 ;
V_442 . V_475 = V_446 ;
V_442 . V_476 = V_7 -> V_476 ;
V_442 . V_477 = V_7 -> V_477 ;
V_442 . V_376 = NULL ;
V_442 . V_375 = 0 ;
F_7 ( V_14 , L_114
L_115
L_116 ,
V_137 -> V_140 . V_204 , V_137 -> V_140 . V_478 ,
V_137 -> V_140 . V_167 , V_7 ,
F_26 ( & V_137 -> V_205 ) ) ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
if ( V_130 )
F_7 ( V_14 , L_117
L_118 , V_130 ) ;
}
if ( V_448 ) {
F_38 ( & V_479 ) ;
F_139 ( V_137 , 1 ) ;
V_7 -> V_480 = V_137 ;
V_442 . V_6 = V_481 ;
V_442 . V_475 = 0 ;
V_442 . V_480 = V_7 -> V_480 ;
V_442 . V_476 = V_7 -> V_476 ;
V_442 . V_477 = V_7 -> V_477 ;
V_442 . V_376 = NULL ;
V_442 . V_375 = 0 ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
if ( V_130 )
F_7 ( V_14 , L_119 , V_130 ) ;
V_7 -> V_199 ( V_7 ) ;
}
}
return 0 ;
}
static int F_139 ( struct V_134 * V_137 , int V_482 )
{
int V_130 = 0 ;
struct V_287 * V_278 ;
struct V_315 * V_279 ;
struct V_483 * V_484 ;
V_278 = F_137 ( V_137 -> V_329 . V_454 ) ;
if ( ! V_278 )
return - V_43 ;
V_279 = V_278 -> V_279 ;
V_484 = V_278 -> V_484 ;
F_7 ( V_14 , L_120 ,
F_140 ( V_278 -> V_180 ) ) ;
if ( V_137 -> V_485 ) {
V_137 -> V_485 = 0 ;
} else {
if ( V_137 -> V_486 ) {
if ( V_137 -> V_487 )
V_484 -> V_488 . V_489 ( V_137 -> V_487 ) ;
F_141 ( V_279 -> V_280 ,
V_137 -> V_375 + V_137 -> V_490 ,
V_137 -> V_486 , V_137 -> V_491 ) ;
}
}
if ( V_137 -> V_2 ) {
F_7 ( V_14 , L_121 ) ;
V_218 -> V_400 -> V_492 ( V_218 , V_137 -> V_2 ) ;
}
return V_130 ;
}
int F_142 ( struct V_193 * V_7 , struct V_493 * V_494 )
{
T_4 V_136 ;
struct V_495 * V_329 ;
struct V_134 * V_137 ;
struct V_287 * V_278 ;
struct V_315 * V_279 ;
struct V_1 * V_2 ;
struct V_296 * V_496 ;
struct V_497 V_498 ;
struct V_441 V_442 ;
struct V_138 * V_139 ;
struct V_499 V_500 ;
T_3 V_501 ;
int V_130 ;
int V_347 ;
struct V_483 * V_484 ;
struct V_502 * V_503 = NULL ;
struct V_504 V_505 ;
struct V_506 * V_507 ;
T_4 V_508 ;
T_1 V_509 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
V_329 = F_143 ( V_7 -> V_454 , V_494 -> V_510 ) ;
if ( ! V_329 )
return - V_43 ;
V_137 = F_144 ( V_329 ) ;
V_278 = F_137 ( V_137 -> V_329 . V_454 ) ;
V_279 = V_278 -> V_279 ;
V_496 = V_279 -> V_297 ;
V_2 = (struct V_1 * ) V_7 -> V_480 ;
F_7 ( V_14 , L_122
L_123 , V_2 , V_278 , V_278 -> V_180 ,
V_278 -> V_180 -> V_511 ) ;
if ( V_276 == V_2 -> V_32 ) {
if ( V_2 -> V_274 )
F_4 ( V_2 -> V_3 , V_2 -> V_274 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_347 = F_115 ( 1 , & V_2 -> V_347 ) ;
if ( V_347 == V_382 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_461 ;
}
V_137 -> V_2 = ( void * ) V_2 ;
V_2 -> V_137 = V_137 ;
F_7 ( V_14 , L_124 ,
V_137 -> V_140 . V_204 , V_2 , V_179 , V_2 -> V_265 ) ;
F_38 ( & V_512 ) ;
F_7 ( V_14 , L_120 ,
F_140 ( V_278 -> V_180 ) ) ;
V_137 -> V_490 = sizeof( struct V_36 ) ;
V_137 -> V_486 = F_145 ( V_279 -> V_280 ,
V_137 -> V_490 + V_494 -> V_375 ,
& V_137 -> V_491 ) ;
if ( ! V_137 -> V_486 ) {
F_7 ( V_14 , L_125 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_137 -> V_486 ;
if ( V_2 -> V_48 == V_46 )
V_509 = 4 ;
memcpy ( V_37 -> V_513 , V_494 -> V_376 ,
V_494 -> V_375 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_137 -> V_486 , V_28 ) ;
V_137 -> V_375 = V_494 -> V_375 ;
V_139 = & V_137 -> V_140 . V_141 [ 0 ] ;
if ( V_7 -> V_477 . V_514 . V_515 !=
V_7 -> V_476 . V_514 . V_515 ) {
V_136 = ( unsigned long ) V_137 ;
V_484 = V_278 -> V_484 ;
V_507 = V_137 -> V_507 ;
V_505 . V_516 = V_137 -> V_491 + V_509 ;
V_505 . V_517 = V_20 ;
V_508 = ( T_4 ) ( unsigned long ) * V_19 ;
V_503 = V_484 -> V_488 . V_518 ( (struct V_519 * ) V_507 ,
& V_505 , 1 ,
V_520 ,
& V_508 ) ;
if ( ! V_503 ) {
F_7 ( V_14 , L_126
L_127 ,
V_2 ) ;
F_141 ( V_279 -> V_280 ,
V_137 -> V_375 + V_137 -> V_490 ,
V_137 -> V_486 , V_137 -> V_491 ) ;
return - V_27 ;
}
V_503 -> V_521 = & V_507 -> V_522 ;
V_503 -> V_454 = V_507 -> V_522 . V_454 ;
V_137 -> V_487 = V_503 ;
V_136 |= V_142 >> 1 ;
F_30 ( V_139 -> V_143 ,
V_144 ,
V_136 ) ;
V_139 -> V_143 [ V_147 ] =
F_31 ( V_523 |
V_524 ) ;
V_139 -> V_143 [ V_149 ] =
F_31 ( V_20 ) ;
F_30 ( V_139 -> V_143 ,
V_145 ,
( T_4 ) ( unsigned long ) ( * V_19 ) ) ;
V_139 -> V_143 [ V_150 ] =
F_31 ( V_20 ) ;
V_139 -> V_143 [ V_151 ] = V_503 -> V_525 ;
if ( V_137 -> V_159 ) {
V_137 -> V_159 = 0 ;
F_34 ( V_137 -> V_160 ) ;
}
V_137 -> V_161 -> V_162 |=
F_31 ( V_163 |
V_164 ) ;
} else {
V_137 -> V_161 -> V_162 |=
F_31 ( V_164 ) ;
}
V_137 -> V_166 = 1 ;
V_137 -> V_7 = V_7 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_480 = V_137 ;
V_137 -> V_485 = 0 ;
if ( V_2 -> V_32 == V_224 )
F_7 ( V_14 , L_128 ,
V_2 ) ;
F_131 ( V_137 , V_2 ) ;
V_137 -> V_161 -> V_526 [ 0 ] =
F_146 ( F_16 ( V_7 -> V_476 . V_527 ) ) ;
V_137 -> V_161 -> V_526 [ 1 ] =
F_146 ( F_16 ( V_7 -> V_477 . V_527 ) ) ;
if ( F_90 ( V_7 -> V_477 . V_514 . V_515 ) )
V_137 -> V_161 -> V_528 =
F_31 ( F_36 ( V_278 -> V_326 ) ) ;
else
V_137 -> V_161 -> V_528 =
F_31 ( F_36 ( V_7 -> V_477 . V_514 . V_515 ) ) ;
V_137 -> V_161 -> V_414 |= F_31 (
( T_3 ) F_71 ( V_279 -> V_280 -> V_281 ) <<
V_529 ) ;
V_137 -> V_161 -> V_530 |=
F_31 ( F_82 ( V_279 ,
F_132 ( V_137 -> V_161 -> V_528 ) , NULL ,
V_310 ) << 16 ) ;
V_137 -> V_161 -> V_531 = F_31 (
V_179 - F_147 ( V_279 , V_532 ) ) ;
V_137 -> V_161 -> V_533 = F_31 ( V_137 -> V_140 . V_204 ) ;
V_137 -> V_161 -> V_162 |= F_31 (
( ( T_3 ) 1 << V_534 ) ) ;
V_137 -> V_161 -> V_162 |=
F_31 ( ( T_3 ) V_494 -> V_535 ) ;
memset ( & V_500 , 0 , sizeof( V_500 ) ) ;
V_500 . V_536 =
F_31 ( ( T_3 ) F_71 ( V_279 -> V_280 -> V_281 ) << 24 ) ;
if ( F_90 ( V_7 -> V_477 . V_514 . V_515 ) )
V_500 . V_537 = V_278 -> V_326 ;
else
V_500 . V_537 = V_7 -> V_477 . V_514 . V_515 ;
V_500 . V_538 [ 0 ] = V_7 -> V_477 . V_527 ;
V_500 . V_538 [ 1 ] = V_7 -> V_476 . V_527 ;
V_501 = F_148 ( & V_500 ) ;
V_137 -> V_539 = F_119 ( V_501 ^ 0xffffffff ) ;
F_7 ( V_14 , L_129 ,
V_137 -> V_539 , V_137 -> V_539 & V_496 -> V_540 ) ;
V_137 -> V_539 &= V_496 -> V_540 ;
V_137 -> V_161 -> V_539 = F_31 ( V_137 -> V_539 ) ;
V_2 -> V_3 -> V_400 -> V_271 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_130
L_131
L_132 , V_137 -> V_140 . V_204 ,
F_36 ( V_7 -> V_477 . V_514 . V_515 ) ,
F_16 ( V_7 -> V_477 . V_527 ) ,
F_36 ( V_7 -> V_476 . V_514 . V_515 ) ,
F_16 ( V_7 -> V_476 . V_527 ) ,
F_132 ( V_137 -> V_161 -> V_110 ) ,
F_132 ( V_137 -> V_161 -> V_427 ) ,
V_20 ) ;
V_7 -> V_383 ( V_7 ) ;
F_133 ( & V_137 -> V_329 ) ;
V_442 . V_6 = V_541 ;
V_442 . V_475 = 0 ;
V_442 . V_480 = ( void * ) V_137 ;
V_442 . V_476 = V_7 -> V_476 ;
V_442 . V_477 = V_7 -> V_477 ;
V_442 . V_376 = NULL ;
V_442 . V_375 = 0 ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
V_498 . V_542 = V_459 ;
F_149 ( & V_137 -> V_329 , & V_498 , V_543 , NULL ) ;
if ( V_2 -> V_274 ) {
V_2 -> V_274 -> V_54 =
V_137 -> V_375 ;
memcpy ( V_2 -> V_274 -> V_67 ,
V_494 -> V_376 , V_494 -> V_375 ) ;
F_5 ( V_2 -> V_274 , V_355 ) ;
}
if ( V_130 )
F_32 ( V_152 L_133
L_134 , V_153 , __LINE__ , V_130 ) ;
return 0 ;
}
int F_150 ( struct V_193 * V_7 , const void * V_544 , T_1 V_545 )
{
struct V_1 * V_2 ;
struct V_1 * V_273 ;
struct V_124 * V_3 ;
T_1 * V_19 ;
F_38 ( & V_546 ) ;
V_2 = (struct V_1 * ) V_7 -> V_480 ;
V_273 = V_2 -> V_274 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_545 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_273 ) {
memcpy ( & V_273 -> V_25 . V_513 , V_544 , V_545 ) ;
V_273 -> V_25 . V_41 = V_545 ;
V_273 -> V_54 = V_545 ;
} else {
V_19 = & V_2 -> V_67 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_545 ;
memcpy ( V_19 , V_544 , V_545 ) ;
}
return V_3 -> V_400 -> V_547 ( V_3 , V_2 ) ;
}
int F_151 ( struct V_193 * V_7 , struct V_493 * V_494 )
{
struct V_495 * V_329 ;
struct V_134 * V_137 ;
struct V_287 * V_278 ;
struct V_315 * V_279 ;
struct V_1 * V_2 ;
struct V_311 V_9 ;
int V_325 = 0 ;
V_329 = F_143 ( V_7 -> V_454 , V_494 -> V_510 ) ;
if ( ! V_329 )
return - V_43 ;
V_137 = F_144 ( V_329 ) ;
if ( ! V_137 )
return - V_43 ;
V_278 = F_137 ( V_137 -> V_329 . V_454 ) ;
if ( ! V_278 )
return - V_43 ;
V_279 = V_278 -> V_279 ;
if ( ! V_279 )
return - V_43 ;
if ( ! ( V_7 -> V_476 . V_527 ) || ! ( V_7 -> V_477 . V_527 ) )
return - V_43 ;
F_7 ( V_14 , L_135
L_136 , V_137 -> V_140 . V_204 ,
F_36 ( V_278 -> V_326 ) ,
F_36 ( V_7 -> V_477 . V_514 . V_515 ) ,
F_16 ( V_7 -> V_477 . V_527 ) ,
F_36 ( V_7 -> V_476 . V_514 . V_515 ) ,
F_16 ( V_7 -> V_476 . V_527 ) ) ;
F_38 ( & V_548 ) ;
V_137 -> V_485 = 1 ;
V_137 -> V_7 = V_7 ;
V_7 -> V_480 = V_137 ;
V_137 -> V_375 = V_494 -> V_375 ;
V_137 -> V_161 -> V_162 |= F_31 ( ( T_3 ) V_494 -> V_535 ) ;
F_7 ( V_14 , L_137 , ( T_3 ) V_494 -> V_535 ) ;
F_7 ( V_14 , L_138 ,
V_494 -> V_375 ) ;
if ( V_7 -> V_476 . V_514 . V_515 !=
V_7 -> V_477 . V_514 . V_515 ) {
F_70 ( V_278 , F_16 ( V_7 -> V_476 . V_527 ) ,
F_71 ( V_279 -> V_280 -> V_281 ) , V_549 ) ;
V_325 = 1 ;
}
V_9 . V_11 = F_23 ( V_7 -> V_476 . V_514 . V_515 ) ;
V_9 . V_13 = F_22 ( V_7 -> V_476 . V_527 ) ;
V_9 . V_10 = F_23 ( V_7 -> V_477 . V_514 . V_515 ) ;
V_9 . V_12 = F_22 ( V_7 -> V_477 . V_527 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_324 = V_550 ;
V_7 -> V_383 ( V_7 ) ;
V_2 = V_218 -> V_400 -> V_551 ( V_218 , V_278 ,
V_494 -> V_375 , ( void * ) V_494 -> V_376 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_325 )
F_70 ( V_278 , F_16 ( V_7 -> V_476 . V_527 ) ,
F_71 ( V_279 -> V_280 -> V_281 ) ,
V_282 ) ;
V_7 -> V_199 ( V_7 ) ;
return - V_27 ;
}
V_2 -> V_325 = V_325 ;
V_137 -> V_2 = V_2 ;
V_2 -> V_137 = V_137 ;
F_133 ( & V_137 -> V_329 ) ;
return 0 ;
}
int F_152 ( struct V_193 * V_7 , int V_357 )
{
struct V_287 * V_278 ;
struct V_256 * V_2 ;
struct V_311 V_9 ;
int V_267 ;
F_7 ( V_14 , L_139 ,
V_7 , F_16 ( V_7 -> V_476 . V_527 ) ) ;
V_278 = F_137 ( V_7 -> V_454 ) ;
if ( ! V_278 )
return - V_43 ;
F_7 ( V_14 , L_140 ,
V_278 , V_278 -> V_180 , V_278 -> V_180 -> V_511 ) ;
F_7 ( V_14 , L_141 ,
V_278 -> V_326 , V_7 -> V_476 . V_514 . V_515 ) ;
V_9 . V_11 = V_278 -> V_326 ;
V_9 . V_13 = V_7 -> V_476 . V_527 ;
V_9 . V_357 = V_357 ;
V_9 . V_7 = V_7 ;
V_9 . V_324 = V_550 ;
V_2 = V_218 -> V_400 -> V_552 ( V_218 , V_278 , & V_9 ) ;
if ( ! V_2 ) {
F_32 ( V_152 L_142 ,
V_153 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_480 = V_2 ;
if ( ! V_2 -> V_373 ) {
V_267 = F_70 ( V_278 ,
F_16 ( V_7 -> V_476 . V_527 ) ,
F_71 ( V_278 -> V_279 -> V_280 -> V_281 ) ,
V_549 ) ;
if ( V_267 ) {
F_32 ( V_152 L_143 ,
V_267 ) ;
V_218 -> V_400 -> V_553 ( V_218 , ( void * ) V_2 ) ;
return V_267 ;
}
F_38 ( & V_554 ) ;
}
V_7 -> V_383 ( V_7 ) ;
V_7 -> V_480 = ( void * ) V_2 ;
return 0 ;
}
int F_153 ( struct V_193 * V_7 )
{
if ( V_7 -> V_480 )
V_218 -> V_400 -> V_553 ( V_218 , V_7 -> V_480 ) ;
else
F_7 ( V_14 , L_144 ) ;
V_7 -> V_199 ( V_7 ) ;
return 0 ;
}
int F_154 ( struct V_15 * V_16 , struct V_295 * V_555 )
{
int V_294 = 0 ;
V_556 ++ ;
if ( ( V_218 ) && ( V_218 -> V_400 ) )
V_294 = V_218 -> V_400 -> V_557 ( V_218 , F_155 ( V_555 ) , V_16 ) ;
else
F_7 ( V_14 , L_145
L_146 ) ;
return V_294 ;
}
int F_156 ( void )
{
F_7 ( V_14 , L_103 ) ;
V_218 = F_122 () ;
if ( V_218 )
return 0 ;
else
return - V_27 ;
}
int F_157 ( void )
{
V_218 -> V_400 -> V_558 ( V_218 ) ;
return 0 ;
}
static void F_158 ( struct V_4 * V_6 )
{
struct V_134 * V_137 ;
struct V_287 * V_278 ;
struct V_315 * V_279 ;
struct V_1 * V_2 ;
struct V_296 * V_297 ;
struct V_497 V_498 ;
struct V_193 * V_7 ;
struct V_441 V_442 ;
struct V_499 V_500 ;
T_3 V_501 ;
int V_130 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_147 , V_2 , V_7 ) ;
V_137 = (struct V_134 * ) V_7 -> V_480 ;
V_278 = F_137 ( V_137 -> V_329 . V_454 ) ;
V_279 = V_278 -> V_279 ;
V_297 = V_279 -> V_297 ;
if ( V_137 -> V_464 )
return;
F_38 ( & V_559 ) ;
F_7 ( V_14 , L_148
L_149 ,
V_137 -> V_140 . V_204 ,
F_36 ( V_7 -> V_477 . V_514 . V_515 ) ,
F_16 ( V_7 -> V_477 . V_527 ) ,
F_16 ( V_7 -> V_476 . V_527 ) ,
V_179 ) ;
F_131 ( V_137 , V_2 ) ;
V_137 -> V_161 -> V_526 [ 0 ] =
F_146 ( F_16 ( V_7 -> V_476 . V_527 ) ) ;
V_137 -> V_161 -> V_526 [ 1 ] =
F_146 ( F_16 ( V_7 -> V_477 . V_527 ) ) ;
if ( F_90 ( V_7 -> V_477 . V_514 . V_515 ) )
V_137 -> V_161 -> V_528 =
F_31 ( F_36 ( V_278 -> V_326 ) ) ;
else
V_137 -> V_161 -> V_528 =
F_31 ( F_36 ( V_7 -> V_477 . V_514 . V_515 ) ) ;
V_137 -> V_161 -> V_414 |= F_31 (
( T_3 ) F_71 ( V_279 -> V_280 -> V_281 ) <<
V_529 ) ;
V_137 -> V_161 -> V_530 |= F_31 (
F_82 ( V_279 ,
F_132 ( V_137 -> V_161 -> V_528 ) ,
NULL , V_310 ) << 16 ) ;
V_137 -> V_161 -> V_531 = F_31 (
V_179 - F_147 ( V_279 , V_532 ) ) ;
V_137 -> V_161 -> V_533 = F_31 ( V_137 -> V_140 . V_204 ) ;
V_137 -> V_161 -> V_162 |=
F_31 ( ( T_3 ) 1 <<
V_534 ) ;
F_29 ( V_2 , & V_137 ) ;
F_159 ( V_279 -> V_560 + V_561 ,
( 1 << 24 ) | 0x00800000 | V_137 -> V_140 . V_204 ) ;
memset ( & V_500 , 0 , sizeof( V_500 ) ) ;
V_500 . V_536 =
F_31 ( ( T_3 ) F_71 ( V_279 -> V_280 -> V_281 ) << 24 ) ;
if ( F_90 ( V_7 -> V_477 . V_514 . V_515 ) )
V_500 . V_537 = V_278 -> V_326 ;
else
V_500 . V_537 = V_7 -> V_477 . V_514 . V_515 ;
V_500 . V_538 [ 0 ] = V_7 -> V_477 . V_527 ;
V_500 . V_538 [ 1 ] = V_7 -> V_476 . V_527 ;
V_501 = F_148 ( & V_500 ) ;
V_137 -> V_539 = F_119 ( V_501 ^ 0xffffffff ) ;
F_7 ( V_14 , L_150 ,
V_137 -> V_539 , V_137 -> V_539 & V_297 -> V_540 ) ;
V_137 -> V_539 &= V_297 -> V_540 ;
V_137 -> V_161 -> V_539 = F_31 ( V_137 -> V_539 ) ;
V_137 -> V_486 = & V_2 -> V_25 ;
V_137 -> V_375 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_400 -> V_271 ( V_2 -> V_3 , V_2 ) ;
V_442 . V_6 = V_562 ;
V_442 . V_475 = 0 ;
V_442 . V_480 = V_7 -> V_480 ;
V_442 . V_476 . V_563 = V_564 ;
V_442 . V_476 . V_527 = V_7 -> V_476 . V_527 ;
V_442 . V_477 = V_7 -> V_477 ;
V_442 . V_376 = ( void * ) V_6 -> V_2 -> V_67 ;
V_442 . V_375 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_442 . V_565 = V_2 -> V_55 ;
V_442 . V_535 = V_2 -> V_56 ;
V_442 . V_476 . V_514 . V_515 = V_6 -> V_9 . V_10 ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
F_7 ( V_14 , L_119 , V_130 ) ;
if ( V_130 )
F_32 ( V_152 L_133
L_134 , V_153 , __LINE__ , V_130 ) ;
V_498 . V_542 = V_459 ;
F_149 ( & V_137 -> V_329 , & V_498 , V_543 , NULL ) ;
F_7 ( V_14 , L_151
L_152 , V_137 -> V_140 . V_204 , V_179 ) ;
return;
}
static void F_66 ( struct V_4 * V_6 )
{
struct V_134 * V_137 ;
struct V_193 * V_7 ;
struct V_441 V_442 ;
int V_130 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_153 , V_6 -> V_2 , V_7 ) ;
V_137 = V_7 -> V_480 ;
if ( ! V_137 )
return;
V_137 -> V_7 = NULL ;
V_7 -> V_480 = NULL ;
V_442 . V_6 = V_562 ;
V_442 . V_475 = - V_461 ;
V_442 . V_480 = V_7 -> V_480 ;
V_442 . V_476 = V_7 -> V_476 ;
V_442 . V_477 = V_7 -> V_477 ;
V_442 . V_376 = NULL ;
V_442 . V_375 = 0 ;
F_7 ( V_14 , L_154
L_155 , V_442 . V_476 . V_514 . V_515 ,
V_442 . V_477 . V_514 . V_515 ) ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
F_7 ( V_14 , L_119 , V_130 ) ;
if ( V_130 )
F_32 ( V_152 L_133
L_134 , V_153 , __LINE__ , V_130 ) ;
V_7 -> V_199 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_160 ( struct V_4 * V_6 )
{
struct V_134 * V_137 ;
struct V_193 * V_7 ;
struct V_441 V_442 ;
int V_130 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_156 , V_6 -> V_2 , V_7 ) ;
V_137 = V_7 -> V_480 ;
if ( ! V_137 )
return;
V_137 -> V_7 = NULL ;
V_442 . V_6 = V_474 ;
V_442 . V_475 = - V_461 ;
V_442 . V_480 = V_7 -> V_480 ;
V_442 . V_476 = V_7 -> V_476 ;
V_442 . V_477 = V_7 -> V_477 ;
V_442 . V_376 = NULL ;
V_442 . V_375 = 0 ;
V_7 -> V_383 ( V_7 ) ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
F_38 ( & V_479 ) ;
V_442 . V_6 = V_481 ;
V_442 . V_475 = 0 ;
V_442 . V_480 = V_7 -> V_480 ;
V_442 . V_476 = V_7 -> V_476 ;
V_442 . V_477 = V_7 -> V_477 ;
V_442 . V_376 = NULL ;
V_442 . V_375 = 0 ;
F_7 ( V_14 , L_157 , V_6 -> V_2 ) ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
F_7 ( V_14 , L_119 , V_130 ) ;
V_7 -> V_199 ( V_7 ) ;
return;
}
static void F_161 ( struct V_4 * V_6 )
{
struct V_193 * V_7 ;
struct V_441 V_442 ;
int V_130 ;
struct V_1 * V_2 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_566 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_179 ) ;
V_442 . V_6 = V_567 ;
V_442 . V_475 = 0 ;
V_442 . V_480 = ( void * ) V_2 ;
V_442 . V_476 . V_563 = V_564 ;
V_442 . V_476 . V_527 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_442 . V_476 . V_514 . V_515 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_442 . V_477 . V_563 = V_564 ;
V_442 . V_477 . V_527 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_442 . V_477 . V_514 . V_515 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_442 . V_376 = V_2 -> V_67 ;
V_442 . V_375 = ( T_1 ) V_2 -> V_54 ;
V_442 . V_565 = V_2 -> V_55 ;
V_442 . V_535 = V_2 -> V_56 ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
if ( V_130 )
F_32 ( V_152 L_159 ,
V_153 , __LINE__ , V_130 ) ;
return;
}
static void F_116 ( struct V_4 * V_6 )
{
struct V_193 * V_7 ;
struct V_441 V_442 ;
struct V_1 * V_2 ;
int V_130 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_38 ( & V_566 ) ;
F_7 ( V_14 , L_158 ,
V_2 , V_7 , V_179 ) ;
V_442 . V_6 = V_562 ;
V_442 . V_475 = - V_568 ;
V_442 . V_480 = V_7 -> V_480 ;
V_442 . V_476 . V_563 = V_564 ;
V_442 . V_476 . V_527 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_442 . V_476 . V_514 . V_515 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_442 . V_477 . V_563 = V_564 ;
V_442 . V_477 . V_527 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_442 . V_477 . V_514 . V_515 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_442 . V_376 = V_2 -> V_67 ;
V_442 . V_375 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_160
L_155 ,
V_442 . V_476 . V_514 . V_515 ,
V_442 . V_477 . V_514 . V_515 ) ;
V_130 = V_7 -> V_471 ( V_7 , & V_442 ) ;
if ( V_130 )
F_32 ( V_152 L_159 ,
V_153 , __LINE__ , V_130 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_38 ( & V_6 -> V_2 -> V_3 -> V_399 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_383 ( V_6 -> V_9 . V_7 ) ;
F_134 ( & V_6 -> V_569 , V_570 ) ;
F_7 ( V_14 , L_161 ,
V_6 -> V_2 , V_6 ) ;
F_135 ( V_6 -> V_2 -> V_3 -> V_402 , & V_6 -> V_569 ) ;
F_7 ( V_14 , L_162 ) ;
return 0 ;
}
static void V_570 ( struct V_439 * V_437 )
{
struct V_4 * V_6 = F_52 ( V_437 , struct V_4 ,
V_569 ) ;
struct V_124 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_163 ,
V_6 , V_6 -> type , F_26 ( & V_3 -> V_399 ) ) ;
switch ( V_6 -> type ) {
case V_352 :
F_161 ( V_6 ) ;
F_7 ( V_14 , L_164 ,
V_6 -> V_2 ) ;
break;
case V_571 :
F_7 ( V_14 , L_165 ,
V_6 -> V_2 ) ;
F_160 ( V_6 ) ;
break;
case V_355 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_224 ) )
break;
F_158 ( V_6 ) ;
F_7 ( V_14 , L_166 ) ;
break;
case V_354 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_224 ) )
break;
F_116 ( V_6 ) ;
F_7 ( V_14 , L_167 ) ;
break;
case V_200 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_224 ) )
break;
F_66 ( V_6 ) ;
F_7 ( V_14 , L_168 ) ;
break;
case V_572 :
F_7 ( V_14 , L_169 ) ;
break;
default:
F_7 ( V_14 , L_170 ) ;
break;
}
F_69 ( & V_3 -> V_399 ) ;
V_6 -> V_9 . V_7 -> V_199 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_35 ( V_6 ) ;
return;
}
