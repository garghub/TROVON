static struct V_1 * F_1 ( struct V_2 * V_2 ,
const char * V_3 ,
unsigned char V_4 ,
enum V_5 type ,
T_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_1 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
V_14 = F_3 ( V_10 , V_3 , V_4 , & V_11 , type , V_8 ) ;
if ( V_14 )
return F_4 ( V_14 ) ;
if ( type == V_15 && V_6 ) {
V_13 = F_5 ( V_11 ) ;
V_13 -> V_16 . V_17 = * V_6 ;
}
return V_11 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_7 ( F_5 ( V_11 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
enum V_5 type , T_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
V_20 = F_10 ( V_13 , type ) ;
if ( V_20 )
return V_20 ;
if ( type == V_21 &&
V_8 && V_8 -> V_22 == 0 )
F_11 ( V_13 -> V_16 . V_23 . V_24 , NULL ) ;
else if ( type == V_25 &&
V_8 && V_8 -> V_22 >= 0 )
V_13 -> V_16 . V_26 . V_22 = V_8 -> V_22 ;
if ( V_13 -> V_27 . type == V_15 && V_6 ) {
struct V_9 * V_10 = V_13 -> V_10 ;
if ( F_12 ( V_13 ) ) {
T_1 V_28 = V_29 |
V_30 ;
if ( ( * V_6 & V_28 ) != ( V_13 -> V_16 . V_17 & V_28 ) )
return - V_31 ;
F_13 ( V_13 , - 1 ) ;
V_13 -> V_16 . V_17 = * V_6 ;
F_13 ( V_13 , 1 ) ;
F_14 ( V_10 ) ;
} else {
V_13 -> V_16 . V_17 = * V_6 ;
}
}
return 0 ;
}
static int F_15 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_20 ;
F_16 ( & V_13 -> V_10 -> V_32 ) ;
V_20 = F_17 ( V_13 , NULL , 0 , 0 ) ;
F_18 ( & V_13 -> V_10 -> V_32 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_19 ( V_11 , true ) ;
}
static void F_20 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
F_21 ( F_5 ( V_11 ) ) ;
}
static int F_22 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_2 V_33 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
V_13 -> V_33 = V_33 ;
F_23 ( V_13 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 ,
struct V_37 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 = NULL ;
const struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
int V_14 ;
if ( ! F_12 ( V_13 ) )
return - V_43 ;
switch ( V_8 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
if ( F_25 ( V_10 -> V_48 ) )
return - V_49 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
break;
default:
V_40 = F_26 ( V_10 , V_8 -> V_44 , V_13 -> V_27 . type ) ;
break;
}
V_42 = F_27 ( V_8 -> V_44 , V_34 , V_8 -> V_58 ,
V_8 -> V_42 , V_8 -> V_59 , V_8 -> V_60 ,
V_40 ) ;
if ( F_25 ( V_42 ) )
return F_28 ( V_42 ) ;
if ( V_35 )
V_42 -> V_61 . V_6 |= V_62 ;
F_16 ( & V_10 -> V_63 ) ;
if ( V_36 ) {
if ( F_29 ( & V_13 -> V_27 ) )
V_24 = F_30 ( V_13 , V_36 ) ;
else
V_24 = F_31 ( V_13 , V_36 ) ;
if ( ! V_24 || ! F_32 ( V_24 , V_64 ) ) {
F_33 ( V_42 ) ;
V_14 = - V_65 ;
goto V_66;
}
}
switch ( V_13 -> V_27 . type ) {
case V_25 :
if ( V_13 -> V_16 . V_26 . V_67 != V_68 )
V_42 -> V_61 . V_6 |= V_69 ;
break;
case V_70 :
case V_21 :
if ( V_42 -> V_24 && F_32 ( V_42 -> V_24 , V_71 ) )
V_42 -> V_61 . V_6 |= V_69 ;
break;
case V_72 :
break;
case V_73 :
#ifdef F_34
if ( V_13 -> V_16 . V_74 . V_75 != V_76 )
V_42 -> V_61 . V_6 |= V_69 ;
break;
#endif
case V_77 :
case V_15 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
F_35 ( 1 ) ;
break;
}
if ( V_24 )
V_24 -> V_84 = V_40 ;
V_14 = F_36 ( V_42 , V_13 , V_24 ) ;
V_66:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
struct V_41 * V_42 = NULL ;
int V_20 ;
F_16 ( & V_10 -> V_63 ) ;
F_16 ( & V_10 -> V_85 ) ;
if ( V_36 ) {
V_20 = - V_65 ;
V_24 = F_31 ( V_13 , V_36 ) ;
if ( ! V_24 )
goto V_66;
if ( V_35 )
V_42 = F_38 ( V_10 , V_24 -> V_86 [ V_34 ] ) ;
else
V_42 = F_38 ( V_10 , V_24 -> V_87 [ V_34 ] ) ;
} else
V_42 = F_38 ( V_10 , V_13 -> V_88 [ V_34 ] ) ;
if ( ! V_42 ) {
V_20 = - V_65 ;
goto V_66;
}
F_39 ( V_42 , true ) ;
V_20 = 0 ;
V_66:
F_18 ( & V_10 -> V_85 ) ;
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_40 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 ,
void * V_89 ,
void (* F_41)( void * V_89 ,
struct V_37 * V_8 ) )
{
struct V_12 * V_13 ;
struct V_38 * V_24 = NULL ;
T_3 V_60 [ 6 ] = { 0 } ;
struct V_37 V_8 ;
struct V_41 * V_42 = NULL ;
T_4 V_90 ;
T_1 V_91 ;
T_2 V_92 ;
int V_14 = - V_65 ;
struct V_93 V_94 = {} ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
if ( V_36 ) {
V_24 = F_31 ( V_13 , V_36 ) ;
if ( ! V_24 )
goto V_95;
if ( V_35 && V_34 < V_96 )
V_42 = F_43 ( V_24 -> V_86 [ V_34 ] ) ;
else if ( ! V_35 &&
V_34 < V_96 + V_97 )
V_42 = F_43 ( V_24 -> V_87 [ V_34 ] ) ;
} else
V_42 = F_43 ( V_13 -> V_88 [ V_34 ] ) ;
if ( ! V_42 )
goto V_95;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_44 = V_42 -> V_61 . V_44 ;
switch ( V_42 -> V_61 . V_44 ) {
case V_46 :
V_91 = V_42 -> V_16 . V_98 . V_99 . V_91 ;
V_92 = V_42 -> V_16 . V_98 . V_99 . V_92 ;
if ( V_42 -> V_6 & V_100 &&
! ( V_42 -> V_61 . V_6 & V_101 ) ) {
F_44 ( V_13 -> V_10 , V_42 , & V_94 ) ;
V_91 = V_94 . V_98 . V_91 ;
V_92 = V_94 . V_98 . V_92 ;
}
V_60 [ 0 ] = V_92 & 0xff ;
V_60 [ 1 ] = ( V_92 >> 8 ) & 0xff ;
V_60 [ 2 ] = V_91 & 0xff ;
V_60 [ 3 ] = ( V_91 >> 8 ) & 0xff ;
V_60 [ 4 ] = ( V_91 >> 16 ) & 0xff ;
V_60 [ 5 ] = ( V_91 >> 24 ) & 0xff ;
V_8 . V_60 = V_60 ;
V_8 . V_59 = 6 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
F_45 ( F_46 ( F_47 ( V_94 ) , V_102 ) !=
F_46 ( F_47 ( V_94 ) , V_103 ) ) ;
case V_54 :
case V_55 :
F_45 ( F_46 ( F_47 ( V_94 ) , V_102 ) !=
F_46 ( F_47 ( V_94 ) , V_104 ) ) ;
case V_56 :
case V_57 :
F_45 ( F_46 ( F_47 ( V_94 ) , V_102 ) !=
F_46 ( F_47 ( V_94 ) , V_105 ) ) ;
if ( V_42 -> V_6 & V_100 &&
! ( V_42 -> V_61 . V_6 & V_101 ) ) {
F_44 ( V_13 -> V_10 , V_42 , & V_94 ) ;
memcpy ( V_60 , V_94 . V_102 . V_106 , 6 ) ;
} else {
V_90 = F_48 ( & V_42 -> V_61 . V_107 ) ;
V_60 [ 0 ] = V_90 ;
V_60 [ 1 ] = V_90 >> 8 ;
V_60 [ 2 ] = V_90 >> 16 ;
V_60 [ 3 ] = V_90 >> 24 ;
V_60 [ 4 ] = V_90 >> 32 ;
V_60 [ 5 ] = V_90 >> 40 ;
}
V_8 . V_60 = V_60 ;
V_8 . V_59 = 6 ;
break;
default:
if ( ! ( V_42 -> V_6 & V_100 ) )
break;
if ( F_49 ( V_42 -> V_61 . V_6 & V_101 ) )
break;
F_44 ( V_13 -> V_10 , V_42 , & V_94 ) ;
V_8 . V_60 = V_94 . V_108 . V_60 ;
V_8 . V_59 = V_94 . V_108 . V_59 ;
break;
}
V_8 . V_42 = V_42 -> V_61 . V_42 ;
V_8 . V_58 = V_42 -> V_61 . V_109 ;
F_41 ( V_89 , & V_8 ) ;
V_14 = 0 ;
V_95:
F_50 () ;
return V_14 ;
}
static int F_51 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 , bool V_110 ,
bool V_111 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_52 ( V_13 , V_34 , V_110 , V_111 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_54 ( V_13 , V_34 ) ;
return 0 ;
}
void F_55 ( struct V_38 * V_24 ,
const struct V_112 * V_113 ,
struct V_114 * V_115 )
{
V_115 -> V_6 = 0 ;
if ( V_113 -> V_6 & V_116 ) {
V_115 -> V_6 |= V_117 ;
V_115 -> V_118 = V_113 -> V_119 ;
} else if ( V_113 -> V_6 & V_120 ) {
V_115 -> V_6 |= V_121 ;
V_115 -> V_118 = F_56 ( V_113 ) ;
V_115 -> V_122 = F_57 ( V_113 ) ;
} else {
struct V_123 * V_124 ;
int V_125 = F_58 ( & V_24 -> V_13 -> V_27 ) ;
T_2 V_126 ;
V_124 = V_24 -> V_10 -> V_108 . V_2 -> V_127 [
F_59 ( V_24 -> V_13 ) ] ;
V_126 = V_124 -> V_128 [ V_113 -> V_119 ] . V_129 ;
V_115 -> V_130 = F_60 ( V_126 , 1 << V_125 ) ;
}
if ( V_113 -> V_6 & V_131 )
V_115 -> V_132 = V_133 ;
else if ( V_113 -> V_6 & V_134 )
V_115 -> V_132 = V_135 ;
else if ( V_113 -> V_6 & V_136 )
V_115 -> V_132 = V_137 ;
else
V_115 -> V_132 = V_138 ;
if ( V_113 -> V_6 & V_139 )
V_115 -> V_6 |= V_140 ;
}
void F_61 ( struct V_38 * V_24 , struct V_114 * V_115 )
{
V_115 -> V_6 = 0 ;
if ( V_24 -> V_141 & V_142 ) {
V_115 -> V_6 |= V_117 ;
V_115 -> V_118 = V_24 -> V_143 ;
} else if ( V_24 -> V_141 & V_144 ) {
V_115 -> V_6 |= V_121 ;
V_115 -> V_122 = V_24 -> V_145 ;
V_115 -> V_118 = V_24 -> V_143 ;
} else {
struct V_123 * V_124 ;
int V_125 = F_58 ( & V_24 -> V_13 -> V_27 ) ;
T_2 V_126 ;
V_124 = V_24 -> V_10 -> V_108 . V_2 -> V_127 [
F_59 ( V_24 -> V_13 ) ] ;
V_126 = V_124 -> V_128 [ V_24 -> V_143 ] . V_129 ;
V_115 -> V_130 = F_60 ( V_126 , 1 << V_125 ) ;
}
if ( V_24 -> V_141 & V_146 )
V_115 -> V_6 |= V_140 ;
if ( V_24 -> V_141 & V_147 )
V_115 -> V_132 = V_148 ;
else if ( V_24 -> V_141 & V_149 )
V_115 -> V_132 = V_150 ;
else if ( V_24 -> V_141 & V_151 )
V_115 -> V_132 = V_133 ;
else if ( V_24 -> V_152 & V_153 )
V_115 -> V_132 = V_135 ;
else if ( V_24 -> V_152 & V_154 )
V_115 -> V_132 = V_137 ;
else
V_115 -> V_132 = V_138 ;
}
static int F_62 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_155 , struct V_156 * V_157 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_63 ( V_13 , V_119 ) ;
if ( V_24 ) {
V_20 = 0 ;
memcpy ( V_155 , V_24 -> V_24 . V_158 , V_159 ) ;
F_64 ( V_24 , V_157 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_65 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , struct V_160 * V_161 )
{
struct V_9 * V_10 = F_66 ( V_19 -> V_162 ) ;
return F_67 ( V_10 , V_119 , V_161 ) ;
}
static int F_68 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_155 , struct V_156 * V_157 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_31 ( V_13 , V_155 ) ;
if ( V_24 ) {
V_20 = 0 ;
F_64 ( V_24 , V_157 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_69 ( struct V_2 * V_2 ,
struct V_163 * V_164 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
int V_20 = 0 ;
if ( F_70 ( & V_10 -> V_165 , V_164 ) )
return 0 ;
F_16 ( & V_10 -> V_166 ) ;
F_16 ( & V_10 -> V_167 ) ;
if ( V_10 -> V_168 ) {
V_13 = F_71 (
V_10 -> V_169 ,
F_72 ( & V_10 -> V_167 ) ) ;
if ( V_13 ) {
F_73 ( V_13 ) ;
V_20 = F_74 ( V_13 , V_164 ,
V_170 ) ;
}
} else if ( V_10 -> V_171 == V_10 -> V_172 ) {
V_10 -> V_173 = * V_164 ;
F_75 ( V_10 , 0 ) ;
}
if ( V_20 == 0 )
V_10 -> V_165 = * V_164 ;
F_18 ( & V_10 -> V_167 ) ;
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
static int F_76 ( struct V_12 * V_13 ,
const T_3 * V_174 , T_5 V_175 ,
const struct V_176 * V_177 )
{
struct V_178 * V_179 , * V_180 ;
if ( ! V_174 || ! V_175 )
return 1 ;
V_180 = F_77 ( V_13 -> V_16 . V_181 . V_178 , V_13 ) ;
V_179 = F_78 ( sizeof( struct V_178 ) + V_175 , V_182 ) ;
if ( ! V_179 )
return - V_183 ;
V_179 -> V_184 = V_175 ;
memcpy ( V_179 -> V_185 , V_174 , V_175 ) ;
if ( V_177 )
memcpy ( V_179 -> V_186 , V_177 -> V_187 ,
V_177 -> V_188 *
sizeof( V_179 -> V_186 [ 0 ] ) ) ;
F_79 ( V_13 -> V_16 . V_181 . V_178 , V_179 ) ;
if ( V_180 )
F_80 ( V_180 , V_189 ) ;
return 0 ;
}
static int F_81 ( struct V_12 * V_13 ,
struct V_190 * V_8 ,
const struct V_176 * V_177 )
{
struct V_191 * V_179 , * V_180 ;
int V_192 , V_193 ;
int V_194 , V_14 ;
T_1 V_195 = V_196 ;
V_180 = F_77 ( V_13 -> V_16 . V_181 . V_197 , V_13 ) ;
if ( ! V_8 -> V_198 && ! V_180 )
return - V_49 ;
if ( V_8 -> V_198 )
V_192 = V_8 -> V_199 ;
else
V_192 = V_180 -> V_199 ;
if ( V_8 -> V_200 || ! V_180 )
V_193 = V_8 -> V_201 ;
else
V_193 = V_180 -> V_201 ;
V_194 = sizeof( * V_179 ) + V_192 + V_193 ;
V_179 = F_78 ( V_194 , V_182 ) ;
if ( ! V_179 )
return - V_183 ;
V_179 -> V_198 = ( ( T_3 * ) V_179 ) + sizeof( * V_179 ) ;
V_179 -> V_200 = V_179 -> V_198 + V_192 ;
V_179 -> V_199 = V_192 ;
V_179 -> V_201 = V_193 ;
if ( V_177 ) {
V_179 -> V_202 = V_177 -> V_203 ;
memcpy ( V_179 -> V_186 , V_177 -> V_204 ,
V_177 -> V_205 *
sizeof( V_179 -> V_186 [ 0 ] ) ) ;
}
if ( V_8 -> V_198 )
memcpy ( V_179 -> V_198 , V_8 -> V_198 , V_192 ) ;
else
memcpy ( V_179 -> V_198 , V_180 -> V_198 , V_192 ) ;
if ( V_8 -> V_200 )
memcpy ( V_179 -> V_200 , V_8 -> V_200 , V_193 ) ;
else
if ( V_180 )
memcpy ( V_179 -> V_200 , V_180 -> V_200 , V_193 ) ;
V_14 = F_76 ( V_13 , V_8 -> V_178 ,
V_8 -> V_206 , V_177 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
V_195 |= V_207 ;
F_79 ( V_13 -> V_16 . V_181 . V_197 , V_179 ) ;
if ( V_180 )
F_80 ( V_180 , V_189 ) ;
return V_195 ;
}
static int F_82 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_208 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_191 * V_180 ;
struct V_12 * V_23 ;
T_1 V_195 = V_209 |
V_210 |
V_196 |
V_211 |
V_212 |
V_213 ;
int V_14 ;
V_180 = F_77 ( V_13 -> V_16 . V_181 . V_197 , V_13 ) ;
if ( V_180 )
return - V_214 ;
switch ( V_8 -> V_215 ) {
case V_216 :
V_13 -> V_215 = V_217 ;
break;
case V_218 :
V_13 -> V_215 = V_219 ;
break;
case V_220 :
V_13 -> V_215 = V_221 ;
break;
default:
return - V_49 ;
}
V_13 -> V_222 = V_13 -> V_10 -> V_223 ;
F_16 ( & V_10 -> V_166 ) ;
V_14 = F_74 ( V_13 , & V_8 -> V_164 ,
V_224 ) ;
if ( ! V_14 )
F_83 ( V_13 , false ) ;
F_18 ( & V_10 -> V_166 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_225 = V_8 -> V_226 . V_227 ;
V_13 -> V_228 = V_8 -> V_226 . V_228 ;
V_13 -> V_229 = F_84 ( V_13 -> V_10 ,
& V_8 -> V_226 ,
V_13 -> V_27 . type ) ;
F_85 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_23 -> V_225 =
V_8 -> V_226 . V_227 ;
V_23 -> V_228 =
V_8 -> V_226 . V_228 ;
V_23 -> V_229 =
F_84 ( V_13 -> V_10 ,
& V_8 -> V_226 ,
V_23 -> V_27 . type ) ;
}
V_13 -> V_27 . V_230 . V_231 = V_8 -> V_232 ;
V_13 -> V_27 . V_230 . V_233 = V_8 -> V_233 ;
V_13 -> V_27 . V_230 . V_234 = true ;
V_13 -> V_27 . V_230 . V_235 = V_8 -> V_235 ;
if ( V_8 -> V_235 )
memcpy ( V_13 -> V_27 . V_230 . V_236 , V_8 -> V_236 ,
V_8 -> V_235 ) ;
V_13 -> V_27 . V_230 . V_237 =
( V_8 -> V_237 != V_238 ) ;
memset ( & V_13 -> V_27 . V_230 . V_239 , 0 ,
sizeof( V_13 -> V_27 . V_230 . V_239 ) ) ;
V_13 -> V_27 . V_230 . V_239 . V_240 =
V_8 -> V_241 & V_242 ;
if ( V_8 -> V_243 )
V_13 -> V_27 . V_230 . V_239 . V_240 |=
V_244 ;
V_14 = F_81 ( V_13 , & V_8 -> V_197 , NULL ) ;
if ( V_14 < 0 ) {
F_73 ( V_13 ) ;
return V_14 ;
}
V_195 |= V_14 ;
V_14 = F_86 ( V_13 -> V_10 , V_13 ) ;
if ( V_14 ) {
V_180 = F_77 ( V_13 -> V_16 . V_181 . V_197 , V_13 ) ;
if ( V_180 )
F_80 ( V_180 , V_189 ) ;
F_11 ( V_13 -> V_16 . V_181 . V_197 , NULL ) ;
F_73 ( V_13 ) ;
return V_14 ;
}
F_87 ( V_10 , V_13 ) ;
F_88 ( V_13 , V_195 ) ;
F_89 ( V_19 ) ;
F_85 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_89 ( V_23 -> V_19 ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_190 * V_8 )
{
struct V_12 * V_13 ;
struct V_191 * V_180 ;
int V_14 ;
V_13 = F_9 ( V_19 ) ;
F_91 ( V_13 ) ;
if ( V_13 -> V_27 . V_245 )
return - V_31 ;
V_180 = F_77 ( V_13 -> V_16 . V_181 . V_197 , V_13 ) ;
if ( ! V_180 )
return - V_65 ;
V_14 = F_81 ( V_13 , V_8 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
F_88 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_92 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_12 * V_23 ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_191 * V_246 ;
struct V_178 * V_247 ;
struct V_163 V_164 ;
F_91 ( V_13 ) ;
V_246 = F_77 ( V_13 -> V_16 . V_181 . V_197 , V_13 ) ;
if ( ! V_246 )
return - V_65 ;
V_247 = F_77 ( V_13 -> V_16 . V_181 . V_178 , V_13 ) ;
F_16 ( & V_10 -> V_166 ) ;
V_13 -> V_27 . V_245 = false ;
if ( V_13 -> V_248 ) {
F_93 ( V_10 , V_13 ,
V_249 ) ;
V_13 -> V_248 = false ;
}
F_18 ( & V_10 -> V_166 ) ;
F_94 ( V_13 -> V_16 . V_181 . V_250 ) ;
V_13 -> V_16 . V_181 . V_250 = NULL ;
F_85 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_95 ( V_23 -> V_19 ) ;
F_95 ( V_19 ) ;
F_11 ( V_13 -> V_16 . V_181 . V_197 , NULL ) ;
F_11 ( V_13 -> V_16 . V_181 . V_178 , NULL ) ;
F_80 ( V_246 , V_189 ) ;
if ( V_247 )
F_80 ( V_247 , V_189 ) ;
V_13 -> V_16 . V_181 . V_251 = V_217 ;
F_96 ( V_13 , true ) ;
F_97 ( V_13 , true ) ;
V_13 -> V_27 . V_230 . V_234 = false ;
V_13 -> V_27 . V_230 . V_235 = 0 ;
F_98 ( V_252 , & V_13 -> V_253 ) ;
F_88 ( V_13 , V_210 ) ;
if ( V_13 -> V_11 . V_254 ) {
V_164 = V_13 -> V_27 . V_230 . V_164 ;
F_99 ( & V_13 -> V_255 ) ;
F_100 ( V_13 -> V_19 , & V_164 ,
V_256 ,
V_182 ) ;
}
F_101 ( V_13 -> V_10 , V_13 ) ;
V_10 -> V_257 -= F_102 ( & V_13 -> V_16 . V_181 . V_258 . V_259 ) ;
F_103 ( & V_13 -> V_16 . V_181 . V_258 . V_259 ) ;
F_16 ( & V_10 -> V_166 ) ;
F_83 ( V_13 , true ) ;
F_73 ( V_13 ) ;
F_18 ( & V_10 -> V_166 ) ;
return 0 ;
}
static void F_104 ( struct V_38 * V_24 )
{
struct V_260 * V_261 ;
struct V_262 * V_263 ;
V_263 = F_105 ( sizeof( * V_261 ) ) ;
if ( ! V_263 )
return;
V_261 = (struct V_260 * ) F_106 ( V_263 , sizeof( * V_261 ) ) ;
F_107 ( V_261 -> V_264 ) ;
memcpy ( V_261 -> V_265 , V_24 -> V_24 . V_158 , V_159 ) ;
V_261 -> V_184 = F_108 ( 6 ) ;
V_261 -> V_266 = 0 ;
V_261 -> V_267 = 0x01 ;
V_261 -> V_268 = 0xaf ;
V_261 -> V_269 [ 0 ] = 0x81 ;
V_261 -> V_269 [ 1 ] = 1 ;
V_261 -> V_269 [ 2 ] = 0 ;
V_263 -> V_19 = V_24 -> V_13 -> V_19 ;
V_263 -> V_270 = F_109 ( V_263 , V_24 -> V_13 -> V_19 ) ;
memset ( V_263 -> V_271 , 0 , sizeof( V_263 -> V_271 ) ) ;
F_110 ( V_263 ) ;
}
static int F_111 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
T_1 V_28 , T_1 V_272 )
{
int V_20 ;
if ( V_28 & F_112 ( V_273 ) &&
V_272 & F_112 ( V_273 ) &&
! F_32 ( V_24 , V_274 ) ) {
V_20 = F_113 ( V_24 , V_275 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_112 ( V_276 ) &&
V_272 & F_112 ( V_276 ) &&
! F_32 ( V_24 , V_64 ) ) {
if ( F_32 ( V_24 , V_277 ) )
F_114 ( V_24 ) ;
V_20 = F_113 ( V_24 , V_278 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_112 ( V_279 ) ) {
if ( V_272 & F_112 ( V_279 ) )
V_20 = F_113 ( V_24 , V_280 ) ;
else if ( F_32 ( V_24 , V_281 ) )
V_20 = F_113 ( V_24 , V_278 ) ;
else
V_20 = 0 ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_112 ( V_276 ) &&
! ( V_272 & F_112 ( V_276 ) ) &&
F_32 ( V_24 , V_64 ) ) {
V_20 = F_113 ( V_24 , V_275 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_112 ( V_273 ) &&
! ( V_272 & F_112 ( V_273 ) ) &&
F_32 ( V_24 , V_274 ) ) {
V_20 = F_113 ( V_24 , V_282 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_115 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_283 * V_8 )
{
int V_20 = 0 ;
struct V_123 * V_124 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_284 V_285 = F_59 ( V_13 ) ;
T_1 V_28 , V_272 ;
V_124 = V_10 -> V_108 . V_2 -> V_127 [ V_285 ] ;
V_28 = V_8 -> V_286 ;
V_272 = V_8 -> V_287 ;
if ( F_29 ( & V_13 -> V_27 ) ) {
if ( V_28 & F_112 ( V_273 ) )
V_28 |= F_112 ( V_276 ) ;
if ( V_272 & F_112 ( V_273 ) )
V_272 |= F_112 ( V_276 ) ;
} else if ( F_32 ( V_24 , V_277 ) ) {
if ( V_272 & F_112 ( V_279 ) ) {
V_272 |= F_112 ( V_273 ) |
F_112 ( V_276 ) ;
V_28 |= F_112 ( V_273 ) |
F_112 ( V_276 ) ;
}
}
if ( V_28 & F_112 ( V_288 ) &&
V_10 -> V_108 . V_289 >= V_290 )
V_24 -> V_24 . V_291 = V_272 & F_112 ( V_288 ) ;
if ( ! F_32 ( V_24 , V_277 ) ) {
V_20 = F_111 ( V_10 , V_24 , V_28 , V_272 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_112 ( V_292 ) ) {
if ( V_272 & F_112 ( V_292 ) )
F_116 ( V_24 , V_293 ) ;
else
F_117 ( V_24 , V_293 ) ;
}
if ( V_28 & F_112 ( V_294 ) ) {
V_24 -> V_24 . V_67 = ! ! ( V_272 & F_112 ( V_294 ) ) ;
if ( V_272 & F_112 ( V_294 ) )
F_116 ( V_24 , V_71 ) ;
else
F_117 ( V_24 , V_71 ) ;
}
if ( V_28 & F_112 ( V_295 ) ) {
if ( V_272 & F_112 ( V_295 ) )
F_116 ( V_24 , V_277 ) ;
else
F_117 ( V_24 , V_277 ) ;
}
if ( F_32 ( V_24 , V_277 ) &&
! V_13 -> V_16 . V_26 . V_296 &&
V_8 -> V_297 >= 4 &&
V_8 -> V_298 [ 3 ] & V_299 )
F_116 ( V_24 , V_300 ) ;
if ( V_8 -> V_301 & V_302 ) {
V_24 -> V_24 . V_303 = V_8 -> V_303 ;
V_24 -> V_24 . V_304 = V_8 -> V_304 ;
}
if ( V_8 -> V_305 )
V_24 -> V_24 . V_305 = V_8 -> V_305 ;
if ( V_8 -> V_306 >= 0 )
V_24 -> V_306 = V_8 -> V_306 ;
if ( V_8 -> V_307 ) {
F_118 ( & V_13 -> V_27 . V_230 . V_164 ,
V_124 , V_8 -> V_307 ,
V_8 -> V_308 ,
& V_24 -> V_24 . V_309 [ V_285 ] ) ;
}
if ( V_8 -> V_310 )
F_119 ( V_13 , V_124 ,
V_8 -> V_310 , V_24 ) ;
if ( V_8 -> V_311 )
F_120 ( V_13 , V_124 ,
V_8 -> V_311 , V_24 ) ;
if ( V_8 -> V_312 ) {
F_121 ( V_13 , V_24 ,
V_8 -> V_313 ,
V_285 , false ) ;
}
if ( F_29 ( & V_13 -> V_27 ) ) {
#ifdef F_34
T_1 V_195 = 0 ;
if ( V_8 -> V_301 & V_314 ) {
switch ( V_8 -> V_315 ) {
case V_316 :
if ( V_24 -> V_315 != V_316 )
V_195 = F_122 (
V_13 ) ;
V_24 -> V_315 = V_8 -> V_315 ;
F_123 ( V_24 ) ;
V_195 |= F_124 ( V_24 ,
V_13 -> V_16 . V_74 . V_317 . V_318 ) ;
break;
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_324 :
if ( V_24 -> V_315 == V_316 )
V_195 = F_125 (
V_13 ) ;
V_24 -> V_315 = V_8 -> V_315 ;
F_123 ( V_24 ) ;
V_195 |= F_124 ( V_24 ,
V_325 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_326 ) {
case V_327 :
break;
case V_328 :
V_195 |= F_126 ( V_24 ) ;
break;
case V_329 :
V_195 |= F_127 ( V_24 ) ;
break;
}
if ( V_8 -> V_330 )
V_195 |=
F_124 ( V_24 ,
V_8 -> V_330 ) ;
F_128 ( V_13 , V_195 ) ;
#endif
}
if ( F_32 ( V_24 , V_277 ) ) {
V_20 = F_111 ( V_10 , V_24 , V_28 , V_272 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_129 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_155 ,
struct V_283 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_13 ;
int V_14 ;
int V_331 ;
if ( V_8 -> V_23 ) {
V_13 = F_9 ( V_8 -> V_23 ) ;
if ( V_13 -> V_27 . type != V_21 &&
V_13 -> V_27 . type != V_70 )
return - V_49 ;
} else
V_13 = F_9 ( V_19 ) ;
if ( F_130 ( V_155 , V_13 -> V_27 . V_158 ) )
return - V_49 ;
if ( F_131 ( V_155 ) )
return - V_49 ;
V_24 = F_132 ( V_13 , V_155 , V_182 ) ;
if ( ! V_24 )
return - V_183 ;
if ( ! ( V_8 -> V_287 & F_112 ( V_295 ) ) ) {
F_133 ( V_24 , V_275 ) ;
F_133 ( V_24 , V_278 ) ;
} else {
V_24 -> V_24 . V_332 = true ;
}
V_14 = F_115 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_134 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_32 ( V_24 , V_277 ) )
F_114 ( V_24 ) ;
V_331 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_135 ( V_24 ) ;
if ( V_14 ) {
F_50 () ;
return V_14 ;
}
if ( V_331 )
F_104 ( V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_136 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_333 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_155 )
return F_137 ( V_13 , V_8 -> V_155 ) ;
F_138 ( V_13 ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 ,
struct V_18 * V_19 , const T_3 * V_155 ,
struct V_283 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_334 ;
enum V_335 V_336 ;
int V_14 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_31 ( V_13 , V_155 ) ;
if ( ! V_24 ) {
V_14 = - V_65 ;
goto V_337;
}
switch ( V_13 -> V_27 . type ) {
case V_73 :
if ( V_13 -> V_16 . V_74 . V_338 )
V_336 = V_339 ;
else
V_336 = V_340 ;
break;
case V_72 :
V_336 = V_341 ;
break;
case V_25 :
if ( ! F_32 ( V_24 , V_277 ) ) {
V_336 = V_342 ;
break;
}
if ( F_32 ( V_24 , V_281 ) )
V_336 = V_343 ;
else
V_336 = V_344 ;
break;
case V_70 :
case V_21 :
V_336 = V_345 ;
break;
default:
V_14 = - V_346 ;
goto V_337;
}
V_14 = F_140 ( V_2 , V_8 , V_336 ) ;
if ( V_14 )
goto V_337;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_347 = false ;
bool V_348 = false ;
V_334 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_162 -> V_22 ) {
if ( V_334 -> V_16 . V_23 . V_24 ) {
V_14 = - V_31 ;
goto V_337;
}
F_79 ( V_334 -> V_16 . V_23 . V_24 , V_24 ) ;
V_348 = true ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_347 = true ;
}
V_24 -> V_13 = V_334 ;
F_141 ( V_24 ) ;
if ( V_24 -> V_349 == V_280 &&
V_347 != V_348 ) {
if ( V_348 )
F_142 ( & V_24 -> V_13 -> V_350 -> V_351 ) ;
else
F_143 ( & V_24 -> V_13 -> V_350 -> V_351 ) ;
}
F_104 ( V_24 ) ;
}
V_14 = F_115 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_337;
F_18 ( & V_10 -> V_63 ) ;
if ( ( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_352 != V_24 -> V_13 -> V_350 -> V_353 &&
F_32 ( V_24 , V_281 ) &&
F_144 ( V_24 ) != 1 ) {
F_145 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_158 ) ;
F_146 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_350 -> V_353 ,
V_24 -> V_24 . V_158 ,
V_24 -> V_13 -> V_27 . V_230 . V_354 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_286 & F_112 ( V_279 ) ) {
F_147 ( V_10 , - 1 ) ;
F_148 ( V_13 ) ;
}
return 0 ;
V_337:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_149 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_355 , const T_3 * V_356 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_356 ) ;
if ( ! V_24 ) {
F_50 () ;
return - V_65 ;
}
V_358 = F_150 ( V_13 , V_355 ) ;
if ( F_25 ( V_358 ) ) {
F_50 () ;
return F_28 ( V_358 ) ;
}
F_151 ( V_358 , V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_152 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_355 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_355 )
return F_153 ( V_13 , V_355 ) ;
F_154 ( V_13 ) ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_355 , const T_3 * V_356 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_356 ) ;
if ( ! V_24 ) {
F_50 () ;
return - V_65 ;
}
V_358 = F_156 ( V_13 , V_355 ) ;
if ( ! V_358 ) {
F_50 () ;
return - V_65 ;
}
F_151 ( V_358 , V_24 ) ;
F_50 () ;
return 0 ;
}
static void F_157 ( struct V_357 * V_358 , T_3 * V_356 ,
struct V_359 * V_360 )
{
struct V_38 * V_361 = F_43 ( V_358 -> V_356 ) ;
if ( V_361 )
memcpy ( V_356 , V_361 -> V_24 . V_158 , V_159 ) ;
else
F_158 ( V_356 ) ;
memset ( V_360 , 0 , sizeof( * V_360 ) ) ;
V_360 -> V_362 = V_363 ;
V_360 -> V_364 = V_365 |
V_366 |
V_367 |
V_368 |
V_369 |
V_370 |
V_371 ;
V_360 -> V_372 = V_358 -> V_373 . V_374 ;
V_360 -> V_375 = V_358 -> V_375 ;
V_360 -> V_376 = V_358 -> V_376 ;
if ( F_159 ( V_377 , V_358 -> V_378 ) )
V_360 -> V_379 = F_160 ( V_358 -> V_378 - V_377 ) ;
V_360 -> V_380 =
F_160 ( V_358 -> V_380 ) ;
V_360 -> V_381 = V_358 -> V_381 ;
if ( V_358 -> V_6 & V_382 )
V_360 -> V_6 |= V_383 ;
if ( V_358 -> V_6 & V_384 )
V_360 -> V_6 |= V_385 ;
if ( V_358 -> V_6 & V_386 )
V_360 -> V_6 |= V_387 ;
if ( V_358 -> V_6 & V_388 )
V_360 -> V_6 |= V_389 ;
if ( V_358 -> V_6 & V_390 )
V_360 -> V_6 |= V_391 ;
}
static int F_161 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_355 , T_3 * V_356 , struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_358 = F_156 ( V_13 , V_355 ) ;
if ( ! V_358 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_159 ) ;
F_157 ( V_358 , V_356 , V_360 ) ;
F_50 () ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_355 , T_3 * V_356 ,
struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_358 = F_163 ( V_13 , V_119 ) ;
if ( ! V_358 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_159 ) ;
F_157 ( V_358 , V_356 , V_360 ) ;
F_50 () ;
return 0 ;
}
static void F_164 ( struct V_357 * V_358 , T_3 * V_392 ,
struct V_359 * V_360 )
{
memset ( V_360 , 0 , sizeof( * V_360 ) ) ;
memcpy ( V_392 , V_358 -> V_392 , V_159 ) ;
V_360 -> V_362 = V_393 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_355 , T_3 * V_392 , struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_358 = F_166 ( V_13 , V_355 ) ;
if ( ! V_358 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_159 ) ;
F_164 ( V_358 , V_392 , V_360 ) ;
F_50 () ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_355 , T_3 * V_392 ,
struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_358 = F_168 ( V_13 , V_119 ) ;
if ( ! V_358 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_159 ) ;
F_164 ( V_358 , V_392 , V_360 ) ;
F_50 () ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_394 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_317 ) , sizeof( struct V_394 ) ) ;
return 0 ;
}
static inline bool F_170 ( enum V_395 V_396 , T_1 V_28 )
{
return ( V_28 >> ( V_396 - 1 ) ) & 0x1 ;
}
static int F_171 ( struct V_397 * V_398 ,
const struct V_399 * V_400 )
{
T_3 * V_401 ;
const T_3 * V_402 ;
struct V_12 * V_13 = F_172 ( V_398 ,
struct V_12 , V_16 . V_74 ) ;
V_401 = NULL ;
V_402 = V_398 -> V_403 ;
if ( V_400 -> V_404 ) {
V_401 = F_173 ( V_400 -> V_403 , V_400 -> V_404 ,
V_182 ) ;
if ( ! V_401 )
return - V_183 ;
}
V_398 -> V_404 = V_400 -> V_404 ;
V_398 -> V_403 = V_401 ;
F_94 ( V_402 ) ;
V_398 -> V_405 = V_400 -> V_405 ;
memcpy ( V_398 -> V_406 , V_400 -> V_406 , V_398 -> V_405 ) ;
V_398 -> V_407 = V_400 -> V_408 ;
V_398 -> V_409 = V_400 -> V_410 ;
V_398 -> V_411 = V_400 -> V_412 ;
V_398 -> V_338 = V_400 -> V_338 ;
V_398 -> V_413 = V_400 -> V_414 ;
V_398 -> V_75 = V_76 ;
if ( V_400 -> V_415 )
V_398 -> V_75 |= V_416 ;
if ( V_400 -> V_417 )
V_398 -> V_75 |= V_418 ;
memcpy ( V_13 -> V_27 . V_230 . V_419 , V_400 -> V_419 ,
sizeof( V_400 -> V_419 ) ) ;
V_13 -> V_27 . V_230 . V_420 = V_400 -> V_420 ;
V_13 -> V_27 . V_230 . V_231 = V_400 -> V_232 ;
V_13 -> V_27 . V_230 . V_233 = V_400 -> V_233 ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_394 * V_421 )
{
struct V_394 * V_61 ;
struct V_12 * V_13 ;
struct V_397 * V_398 ;
V_13 = F_9 ( V_19 ) ;
V_398 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_317 ) ;
if ( F_170 ( V_422 , V_28 ) )
V_61 -> V_423 = V_421 -> V_423 ;
if ( F_170 ( V_424 , V_28 ) )
V_61 -> V_425 = V_421 -> V_425 ;
if ( F_170 ( V_426 , V_28 ) )
V_61 -> V_427 = V_421 -> V_427 ;
if ( F_170 ( V_428 , V_28 ) )
V_61 -> V_429 = V_421 -> V_429 ;
if ( F_170 ( V_430 , V_28 ) )
V_61 -> V_431 = V_421 -> V_431 ;
if ( F_170 ( V_432 , V_28 ) )
V_61 -> V_433 = V_421 -> V_433 ;
if ( F_170 ( V_434 , V_28 ) )
V_61 -> V_435 = V_421 -> V_435 ;
if ( F_170 ( V_436 , V_28 ) ) {
if ( V_398 -> V_338 )
return - V_31 ;
V_61 -> V_437 = V_421 -> V_437 ;
}
if ( F_170 ( V_438 , V_28 ) )
V_61 -> V_439 =
V_421 -> V_439 ;
if ( F_170 ( V_440 , V_28 ) )
V_61 -> V_441 =
V_421 -> V_441 ;
if ( F_170 ( V_442 , V_28 ) )
V_61 -> V_443 = V_421 -> V_443 ;
if ( F_170 ( V_444 , V_28 ) )
V_61 -> V_445 = V_421 -> V_445 ;
if ( F_170 ( V_446 , V_28 ) )
V_61 -> V_447 =
V_421 -> V_447 ;
if ( F_170 ( V_448 , V_28 ) )
V_61 -> V_449 =
V_421 -> V_449 ;
if ( F_170 ( V_450 , V_28 ) )
V_61 -> V_451 =
V_421 -> V_451 ;
if ( F_170 ( V_452 ,
V_28 ) )
V_61 -> V_453 =
V_421 -> V_453 ;
if ( F_170 ( V_454 , V_28 ) ) {
V_61 -> V_455 = V_421 -> V_455 ;
F_175 ( V_398 ) ;
}
if ( F_170 ( V_456 , V_28 ) ) {
if ( V_421 -> V_457 &&
! ( V_61 -> V_455 > V_458 ) ) {
V_61 -> V_455 = V_459 ;
F_175 ( V_398 ) ;
}
V_61 -> V_457 =
V_421 -> V_457 ;
}
if ( F_170 ( V_460 , V_28 ) )
V_61 -> V_461 =
V_421 -> V_461 ;
if ( F_170 ( V_462 , V_28 ) )
V_61 -> V_463 = V_421 -> V_463 ;
if ( F_170 ( V_464 , V_28 ) ) {
if ( ! F_176 ( & V_13 -> V_10 -> V_108 , V_465 ) )
return - V_466 ;
V_61 -> V_467 = V_421 -> V_467 ;
}
if ( F_170 ( V_468 , V_28 ) ) {
V_61 -> V_469 = V_421 -> V_469 ;
V_13 -> V_27 . V_230 . V_470 = V_421 -> V_469 ;
F_88 ( V_13 , V_471 ) ;
}
if ( F_170 ( V_472 , V_28 ) )
V_61 -> V_473 =
V_421 -> V_473 ;
if ( F_170 ( V_474 , V_28 ) )
V_61 -> V_475 =
V_421 -> V_475 ;
if ( F_170 ( V_476 , V_28 ) )
V_61 -> V_477 =
V_421 -> V_477 ;
if ( F_170 ( V_478 , V_28 ) ) {
V_61 -> V_318 = V_421 -> V_318 ;
F_177 ( V_13 ) ;
}
if ( F_170 ( V_479 , V_28 ) )
V_61 -> V_480 =
V_421 -> V_480 ;
if ( F_170 ( V_481 , V_28 ) )
V_61 -> V_482 = V_421 -> V_482 ;
F_128 ( V_13 , V_196 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_394 * V_61 ,
const struct V_399 * V_400 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_397 * V_398 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_398 -> V_317 , V_61 , sizeof( struct V_394 ) ) ;
V_14 = F_171 ( V_398 , V_400 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_215 = V_217 ;
V_13 -> V_222 = V_13 -> V_10 -> V_223 ;
F_16 ( & V_13 -> V_10 -> V_166 ) ;
V_14 = F_74 ( V_13 , & V_400 -> V_164 ,
V_224 ) ;
F_18 ( & V_13 -> V_10 -> V_166 ) ;
if ( V_14 )
return V_14 ;
return F_179 ( V_13 ) ;
}
static int F_180 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_181 ( V_13 ) ;
F_16 ( & V_13 -> V_10 -> V_166 ) ;
F_73 ( V_13 ) ;
F_18 ( & V_13 -> V_10 -> V_166 ) ;
return 0 ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_483 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_284 V_285 ;
T_1 V_195 = 0 ;
if ( ! F_77 ( V_13 -> V_16 . V_181 . V_197 , V_13 ) )
return - V_65 ;
V_285 = F_59 ( V_13 ) ;
if ( V_8 -> V_484 >= 0 ) {
V_13 -> V_27 . V_230 . V_484 = V_8 -> V_484 ;
V_195 |= V_485 ;
}
if ( V_8 -> V_486 >= 0 ) {
V_13 -> V_27 . V_230 . V_486 =
V_8 -> V_486 ;
V_195 |= V_487 ;
}
if ( ! V_13 -> V_27 . V_230 . V_488 &&
V_285 == V_489 ) {
V_13 -> V_27 . V_230 . V_488 = true ;
V_195 |= V_490 ;
}
if ( V_8 -> V_491 >= 0 ) {
V_13 -> V_27 . V_230 . V_488 =
V_8 -> V_491 ;
V_195 |= V_490 ;
}
if ( V_8 -> V_420 ) {
F_118 ( & V_13 -> V_27 . V_230 . V_164 ,
V_2 -> V_127 [ V_285 ] ,
V_8 -> V_420 ,
V_8 -> V_492 ,
& V_13 -> V_27 . V_230 . V_420 ) ;
V_195 |= V_493 ;
}
if ( V_8 -> V_494 >= 0 ) {
if ( V_8 -> V_494 )
V_13 -> V_6 |= V_495 ;
else
V_13 -> V_6 &= ~ V_495 ;
}
if ( V_8 -> V_469 >= 0 ) {
V_13 -> V_27 . V_230 . V_470 =
( T_2 ) V_8 -> V_469 ;
V_195 |= V_471 ;
}
if ( V_8 -> V_241 >= 0 ) {
V_13 -> V_27 . V_230 . V_239 . V_240 &=
~ V_242 ;
V_13 -> V_27 . V_230 . V_239 . V_240 |=
V_8 -> V_241 & V_242 ;
V_195 |= V_212 ;
}
if ( V_8 -> V_243 > 0 ) {
V_13 -> V_27 . V_230 . V_239 . V_240 |=
V_244 ;
V_195 |= V_212 ;
} else if ( V_8 -> V_243 == 0 ) {
V_13 -> V_27 . V_230 . V_239 . V_240 &=
~ V_244 ;
V_195 |= V_212 ;
}
F_88 ( V_13 , V_195 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_496 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_497 V_498 ;
if ( ! V_10 -> V_499 -> V_500 )
return - V_346 ;
if ( V_10 -> V_108 . V_289 < V_290 )
return - V_346 ;
memset ( & V_498 , 0 , sizeof( V_498 ) ) ;
V_498 . V_501 = V_8 -> V_501 ;
V_498 . V_502 = V_8 -> V_503 ;
V_498 . V_504 = V_8 -> V_505 ;
V_498 . V_506 = V_8 -> V_506 ;
V_498 . V_507 = false ;
V_13 -> V_508 [ V_8 -> V_509 ] = V_498 ;
if ( F_184 ( V_10 , V_13 , V_8 -> V_509 , & V_498 ) ) {
F_185 ( V_10 -> V_108 . V_2 ,
L_2 ,
V_8 -> V_509 ) ;
return - V_49 ;
}
F_88 ( V_13 , V_510 ) ;
return 0 ;
}
static int F_186 ( struct V_2 * V_2 ,
struct V_511 * V_512 )
{
return F_187 ( F_2 ( V_2 ) , V_512 ) ;
}
static int F_188 ( struct V_2 * V_2 )
{
return F_189 ( F_2 ( V_2 ) ) ;
}
static int F_190 ( struct V_2 * V_2 ,
struct V_513 * V_514 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_514 -> V_11 ) ;
switch ( F_191 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_72 :
case V_73 :
case V_81 :
case V_78 :
break;
case V_82 :
if ( V_13 -> V_10 -> V_499 -> V_515 )
break;
case V_70 :
if ( V_13 -> V_16 . V_181 . V_197 &&
( ! ( V_2 -> V_516 & V_517 ) ||
! ( V_514 -> V_6 & V_518 ) ) )
return - V_346 ;
break;
default:
return - V_346 ;
}
return F_192 ( V_13 , V_514 ) ;
}
static int
F_193 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_519 * V_514 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_499 -> V_520 )
return - V_346 ;
return F_194 ( V_13 , V_514 ) ;
}
static int
F_195 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_499 -> V_521 )
return - V_346 ;
return F_196 ( V_13 ) ;
}
static int F_197 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_522 * V_514 )
{
return F_198 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_523 * V_514 )
{
return F_200 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_201 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_524 * V_514 )
{
return F_202 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_203 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_525 * V_514 )
{
return F_204 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_205 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_526 * V_8 )
{
return F_206 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_207 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_208 ( F_9 ( V_19 ) ) ;
}
static int F_209 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_527 * V_400 )
{
return F_210 ( F_9 ( V_19 ) , V_400 ) ;
}
static int F_211 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_212 ( F_9 ( V_19 ) ) ;
}
static int F_213 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_113 [ V_528 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_230 . V_419 , V_113 ,
sizeof( int ) * V_528 ) ;
return 0 ;
}
static int F_214 ( struct V_2 * V_2 , T_1 V_195 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_195 & V_529 ) {
F_215 ( V_10 ) ;
V_14 = F_216 ( V_10 , V_2 -> V_530 ) ;
if ( V_14 ) {
F_215 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_195 & V_531 ) ||
( V_195 & V_532 ) ) {
T_6 V_533 ;
V_533 = V_195 & V_531 ?
V_2 -> V_533 : - 1 ;
V_14 = F_217 ( V_10 , V_533 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_195 & V_534 ) {
V_14 = F_218 ( V_10 , V_2 -> V_535 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_195 & V_536 ) {
if ( V_2 -> V_537 > V_538 )
return - V_49 ;
V_10 -> V_108 . V_61 . V_539 = V_2 -> V_537 ;
}
if ( V_195 & V_540 ) {
if ( V_2 -> V_541 > V_538 )
return - V_49 ;
V_10 -> V_108 . V_61 . V_542 = V_2 -> V_541 ;
}
if ( V_195 &
( V_536 | V_540 ) )
F_75 ( V_10 , V_543 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_544 type , int V_545 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_544 V_546 = type ;
bool V_547 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_548 :
V_13 -> V_549 = V_550 ;
V_546 = V_551 ;
break;
case V_551 :
case V_552 :
if ( V_545 < 0 || ( V_545 % 100 ) )
return - V_346 ;
V_13 -> V_549 = F_220 ( V_545 ) ;
break;
}
if ( V_546 != V_13 -> V_27 . V_230 . V_553 ) {
V_547 = true ;
V_13 -> V_27 . V_230 . V_553 = V_546 ;
}
F_221 ( V_13 , V_547 ) ;
return 0 ;
}
switch ( type ) {
case V_548 :
V_10 -> V_549 = V_550 ;
V_546 = V_551 ;
break;
case V_551 :
case V_552 :
if ( V_545 < 0 || ( V_545 % 100 ) )
return - V_346 ;
V_10 -> V_549 = F_220 ( V_545 ) ;
break;
}
F_16 ( & V_10 -> V_167 ) ;
F_85 (sdata, &local->interfaces, list) {
V_13 -> V_549 = V_10 -> V_549 ;
if ( V_546 != V_13 -> V_27 . V_230 . V_553 )
V_547 = true ;
V_13 -> V_27 . V_230 . V_553 = V_546 ;
}
F_85 (sdata, &local->interfaces, list)
F_221 ( V_13 , V_547 ) ;
F_18 ( & V_10 -> V_167 ) ;
return 0 ;
}
static int F_222 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_554 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_499 -> V_555 )
return F_223 ( V_10 , V_13 , V_554 ) ;
if ( ! V_10 -> V_168 )
* V_554 = V_10 -> V_108 . V_61 . V_556 ;
else
* V_554 = V_13 -> V_27 . V_230 . V_557 ;
return 0 ;
}
static int F_224 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_158 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_558 . V_559 , V_158 , V_159 ) ;
return 0 ;
}
static void F_225 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_226 ( V_10 ) ;
}
static int F_227 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
void * V_185 , int V_184 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_560 * V_27 = NULL ;
if ( ! V_10 -> V_499 -> V_561 )
return - V_346 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_562 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_499 -> V_561 ( & V_10 -> V_108 , V_27 , V_185 , V_184 ) ;
}
static int F_228 ( struct V_2 * V_2 ,
struct V_262 * V_263 ,
struct V_563 * V_271 ,
void * V_185 , int V_184 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_499 -> V_564 )
return - V_346 ;
return V_10 -> V_499 -> V_564 ( & V_10 -> V_108 , V_263 , V_271 , V_185 , V_184 ) ;
}
int F_229 ( struct V_12 * V_13 ,
enum V_565 V_215 )
{
struct V_38 * V_24 ;
enum V_565 V_566 ;
if ( F_35 ( V_13 -> V_27 . type != V_70 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_230 . V_164 . V_567 == V_568 )
return 0 ;
V_566 = V_13 -> V_16 . V_181 . V_353 ;
V_13 -> V_16 . V_181 . V_353 = V_215 ;
if ( V_566 == V_215 ||
V_215 == V_569 )
return 0 ;
if ( ! F_230 ( & V_13 -> V_16 . V_181 . V_351 ) ) {
V_13 -> V_215 = V_215 ;
F_231 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_570 ) ;
return 0 ;
}
F_145 ( V_13 ,
L_3 ,
V_215 , F_230 ( & V_13 -> V_16 . V_181 . V_351 ) ) ;
F_16 ( & V_13 -> V_10 -> V_63 ) ;
F_85 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_350 != & V_13 -> V_16 . V_181 )
continue;
if ( F_144 ( V_24 ) == 1 )
continue;
if ( F_32 ( V_24 , V_571 ) &&
! F_232 ( V_24 -> V_352 ,
V_215 ) ) {
F_145 ( V_13 , L_4 ,
V_24 -> V_24 . V_158 ) ;
continue;
}
if ( ! F_32 ( V_24 , V_281 ) )
continue;
F_145 ( V_13 , L_5 , V_24 -> V_24 . V_158 ) ;
F_146 ( V_13 , V_215 , V_24 -> V_24 . V_158 ,
V_13 -> V_27 . V_230 . V_354 ) ;
}
F_18 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_215 = V_215 ;
F_231 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_570 ) ;
return 0 ;
}
int F_233 ( struct V_12 * V_13 ,
enum V_565 V_215 )
{
const T_3 * V_181 ;
enum V_565 V_566 ;
int V_14 ;
F_234 ( & V_13 -> V_11 . V_166 ) ;
if ( F_35 ( V_13 -> V_27 . type != V_25 ) )
return - V_49 ;
V_566 = V_13 -> V_16 . V_26 . V_353 ;
V_13 -> V_16 . V_26 . V_353 = V_215 ;
if ( V_566 == V_215 &&
V_215 != V_569 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_572 ||
V_13 -> V_27 . V_230 . V_164 . V_567 == V_568 )
return 0 ;
V_181 = V_13 -> V_16 . V_26 . V_572 -> V_354 ;
if ( V_215 == V_569 ) {
if ( V_13 -> V_16 . V_26 . V_573 )
V_215 = V_221 ;
else
V_215 = V_217 ;
}
V_14 = F_146 ( V_13 , V_215 ,
V_181 , V_181 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_353 = V_566 ;
return V_14 ;
}
static int F_235 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_574 , int V_575 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_66 ( V_19 -> V_162 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_346 ;
if ( ! F_176 ( & V_10 -> V_108 , V_576 ) )
return - V_346 ;
if ( V_574 == V_13 -> V_16 . V_26 . V_573 &&
V_575 == V_10 -> V_577 )
return 0 ;
V_13 -> V_16 . V_26 . V_573 = V_574 ;
V_10 -> V_577 = V_575 ;
F_236 ( V_13 ) ;
F_233 ( V_13 , V_13 -> V_16 . V_26 . V_353 ) ;
F_237 ( V_13 ) ;
if ( F_176 ( & V_10 -> V_108 , V_578 ) )
F_75 ( V_10 , V_579 ) ;
F_147 ( V_10 , - 1 ) ;
F_148 ( V_13 ) ;
return 0 ;
}
static int F_238 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_580 , T_1 V_581 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_560 * V_27 = & V_13 -> V_27 ;
struct V_582 * V_230 = & V_27 -> V_230 ;
if ( V_580 == V_230 -> V_583 &&
V_581 == V_230 -> V_584 )
return 0 ;
V_230 -> V_583 = V_580 ;
V_230 -> V_584 = V_581 ;
if ( V_13 -> V_16 . V_26 . V_572 &&
V_13 -> V_27 . V_585 & V_586 )
F_88 ( V_13 , V_587 ) ;
return 0 ;
}
static int F_239 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_158 ,
const struct V_588 * V_28 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_66 ( V_19 -> V_162 ) ;
int V_589 , V_20 ;
if ( ! F_12 ( V_13 ) )
return - V_43 ;
if ( F_176 ( & V_10 -> V_108 , V_590 ) ) {
V_20 = F_240 ( V_10 , V_13 , V_28 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_589 = 0 ; V_589 < V_528 ; V_589 ++ ) {
struct V_123 * V_124 = V_2 -> V_127 [ V_589 ] ;
int V_591 ;
V_13 -> V_592 [ V_589 ] = V_28 -> V_268 [ V_589 ] . V_130 ;
memcpy ( V_13 -> V_593 [ V_589 ] , V_28 -> V_268 [ V_589 ] . V_594 ,
sizeof( V_28 -> V_268 [ V_589 ] . V_594 ) ) ;
V_13 -> V_595 [ V_589 ] = false ;
if ( ! V_124 )
continue;
for ( V_591 = 0 ; V_591 < V_596 ; V_591 ++ )
if ( ~ V_13 -> V_593 [ V_589 ] [ V_591 ] ) {
V_13 -> V_595 [ V_589 ] = true ;
break;
}
}
return 0 ;
}
static bool F_241 ( struct V_9 * V_10 ,
struct V_597 * V_598 ,
struct V_597 * V_599 )
{
unsigned long V_600 = V_377 ;
unsigned long V_601 = V_599 -> V_602 +
F_242 ( V_599 -> V_603 ) -
V_600 ;
if ( F_49 ( ! V_599 -> V_604 || ! V_599 -> V_605 ) )
return false ;
if ( V_598 -> V_603 > F_160 ( V_601 ) )
return false ;
F_243 ( V_598 ) ;
F_244 ( & V_598 -> V_606 , & V_599 -> V_607 ) ;
return true ;
}
static T_4 F_245 ( struct V_9 * V_10 )
{
F_234 ( & V_10 -> V_166 ) ;
V_10 -> V_608 ++ ;
if ( F_49 ( V_10 -> V_608 == 0 ) )
V_10 -> V_608 ++ ;
return V_10 -> V_608 ;
}
static int F_246 ( struct V_9 * V_10 ,
struct V_12 * V_13 ,
struct V_609 * V_610 ,
unsigned int V_603 , T_4 * V_89 ,
struct V_262 * V_611 ,
enum V_612 type )
{
struct V_597 * V_613 , * V_614 ;
bool V_615 = false ;
int V_20 ;
F_234 ( & V_10 -> V_166 ) ;
if ( V_10 -> V_168 && ! V_10 -> V_499 -> V_616 )
return - V_346 ;
V_613 = F_78 ( sizeof( * V_613 ) , V_182 ) ;
if ( ! V_613 )
return - V_183 ;
if ( ! V_603 )
V_603 = 10 ;
V_613 -> V_617 = V_610 ;
V_613 -> V_603 = V_603 ;
V_613 -> V_618 = V_603 ;
V_613 -> V_619 = V_611 ;
V_613 -> type = type ;
V_613 -> V_13 = V_13 ;
F_247 ( & V_613 -> V_620 , V_621 ) ;
F_248 ( & V_613 -> V_607 ) ;
if ( ! V_611 ) {
V_613 -> V_89 = F_245 ( V_10 ) ;
* V_89 = V_613 -> V_89 ;
} else {
V_613 -> V_622 = * V_89 ;
}
if ( ! F_249 ( & V_10 -> V_623 ) ||
V_10 -> V_624 || F_250 ( V_10 ) )
goto V_625;
if ( ! V_10 -> V_499 -> V_616 ) {
F_251 ( & V_10 -> V_108 , & V_613 -> V_620 , 0 ) ;
goto V_626;
}
V_20 = F_252 ( V_10 , V_13 , V_610 , V_603 , type ) ;
if ( V_20 ) {
F_94 ( V_613 ) ;
return V_20 ;
}
V_613 -> V_604 = true ;
goto V_626;
V_625:
F_85 (tmp, &local->roc_list, list) {
if ( V_614 -> V_617 != V_610 || V_614 -> V_13 != V_13 )
continue;
if ( ! V_614 -> V_604 ) {
F_244 ( & V_613 -> V_606 , & V_614 -> V_607 ) ;
V_614 -> V_603 = F_253 ( V_614 -> V_603 , V_613 -> V_603 ) ;
V_614 -> type = F_253 ( V_614 -> type , V_613 -> type ) ;
V_615 = true ;
break;
}
if ( V_10 -> V_499 -> V_616 ) {
if ( ! V_614 -> V_605 ) {
F_244 ( & V_613 -> V_606 , & V_614 -> V_607 ) ;
V_615 = true ;
break;
}
if ( F_241 ( V_10 , V_613 , V_614 ) )
V_615 = true ;
} else if ( F_254 ( & V_614 -> V_620 . V_627 ) ) {
unsigned long V_628 ;
F_244 ( & V_613 -> V_606 , & V_614 -> V_607 ) ;
V_615 = true ;
V_628 = V_377 + F_242 ( V_613 -> V_603 ) ;
if ( F_255 ( V_628 , V_614 -> V_620 . V_627 . V_629 ) )
F_256 ( & V_614 -> V_620 . V_627 , V_628 ) ;
else
F_257 ( & V_614 -> V_620 . V_627 ) ;
F_243 ( V_613 ) ;
}
break;
}
V_626:
if ( ! V_615 )
F_244 ( & V_613 -> V_606 , & V_10 -> V_623 ) ;
return 0 ;
}
static int F_258 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_609 * V_617 ,
unsigned int V_603 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_20 ;
F_16 ( & V_10 -> V_166 ) ;
V_20 = F_246 ( V_10 , V_13 , V_617 ,
V_603 , V_89 , NULL ,
V_630 ) ;
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
static int F_259 ( struct V_9 * V_10 ,
T_4 V_89 , bool V_631 )
{
struct V_597 * V_613 , * V_614 , * V_632 = NULL ;
int V_20 ;
F_16 ( & V_10 -> V_166 ) ;
F_260 (roc, tmp, &local->roc_list, list) {
struct V_597 * V_633 , * V_634 ;
F_260 (dep, tmp2, &roc->dependents, list) {
if ( ! V_631 && V_633 -> V_89 != V_89 )
continue;
else if ( V_631 && V_633 -> V_622 != V_89 )
continue;
F_261 ( & V_633 -> V_606 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_262 ( V_633 , true ) ;
return 0 ;
}
if ( ! V_631 && V_613 -> V_89 != V_89 )
continue;
else if ( V_631 && V_613 -> V_622 != V_89 )
continue;
V_632 = V_613 ;
break;
}
if ( ! V_632 ) {
F_18 ( & V_10 -> V_166 ) ;
return - V_65 ;
}
if ( V_10 -> V_499 -> V_616 ) {
if ( V_632 -> V_604 ) {
V_20 = F_263 ( V_10 ) ;
if ( F_35 ( V_20 ) ) {
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
}
F_261 ( & V_632 -> V_606 ) ;
if ( V_632 -> V_604 )
F_264 ( V_10 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_262 ( V_632 , true ) ;
} else {
V_632 -> abort = true ;
F_251 ( & V_10 -> V_108 , & V_632 -> V_620 , 0 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_265 ( & V_632 -> V_620 ) ;
F_49 ( ! V_632 -> V_635 ) ;
F_94 ( V_632 ) ;
}
return 0 ;
}
static int F_266 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
return F_259 ( V_10 , V_89 , false ) ;
}
static int F_267 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_163 * V_164 ,
T_1 V_636 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_166 ) ;
if ( ! F_249 ( & V_10 -> V_623 ) || V_10 -> V_624 ) {
V_14 = - V_31 ;
goto V_66;
}
V_13 -> V_215 = V_217 ;
V_13 -> V_222 = V_10 -> V_223 ;
V_14 = F_74 ( V_13 , V_164 ,
V_224 ) ;
if ( V_14 )
goto V_66;
F_251 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_255 ,
F_242 ( V_636 ) ) ;
V_66:
F_18 ( & V_10 -> V_166 ) ;
return V_14 ;
}
static struct V_190 *
F_268 ( struct V_190 * V_197 )
{
struct V_190 * V_637 ;
T_3 * V_638 ;
int V_184 ;
V_184 = V_197 -> V_199 + V_197 -> V_201 + V_197 -> V_639 +
V_197 -> V_640 + V_197 -> V_641 +
V_197 -> V_206 ;
V_637 = F_78 ( sizeof( * V_637 ) + V_184 , V_182 ) ;
if ( ! V_637 )
return NULL ;
V_638 = ( T_3 * ) ( V_637 + 1 ) ;
if ( V_197 -> V_199 ) {
V_637 -> V_199 = V_197 -> V_199 ;
V_637 -> V_198 = V_638 ;
memcpy ( V_638 , V_197 -> V_198 , V_197 -> V_199 ) ;
V_638 += V_197 -> V_199 ;
}
if ( V_197 -> V_201 ) {
V_637 -> V_201 = V_197 -> V_201 ;
V_637 -> V_200 = V_638 ;
memcpy ( V_638 , V_197 -> V_200 , V_197 -> V_201 ) ;
V_638 += V_197 -> V_201 ;
}
if ( V_197 -> V_639 ) {
V_637 -> V_639 = V_197 -> V_639 ;
V_637 -> V_642 = V_638 ;
memcpy ( V_638 , V_197 -> V_642 , V_197 -> V_639 ) ;
V_638 += V_197 -> V_639 ;
}
if ( V_197 -> V_640 ) {
V_637 -> V_640 = V_197 -> V_640 ;
V_637 -> V_643 = V_638 ;
memcpy ( V_638 , V_197 -> V_643 , V_197 -> V_640 ) ;
V_638 += V_197 -> V_640 ;
}
if ( V_197 -> V_641 ) {
V_637 -> V_641 = V_197 -> V_641 ;
V_637 -> V_644 = V_638 ;
memcpy ( V_638 , V_197 -> V_644 , V_197 -> V_641 ) ;
V_638 += V_197 -> V_641 ;
}
if ( V_197 -> V_206 ) {
V_637 -> V_206 = V_197 -> V_206 ;
V_197 -> V_178 = V_638 ;
memcpy ( V_638 , V_197 -> V_178 , V_197 -> V_206 ) ;
V_638 += V_197 -> V_206 ;
}
return V_637 ;
}
void F_269 ( struct V_560 * V_27 )
{
struct V_12 * V_13 = F_270 ( V_27 ) ;
F_231 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_645 ) ;
}
static int F_271 ( struct V_12 * V_13 ,
T_1 * V_195 )
{
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_14 = F_81 ( V_13 , V_13 -> V_16 . V_181 . V_250 ,
NULL ) ;
F_94 ( V_13 -> V_16 . V_181 . V_250 ) ;
V_13 -> V_16 . V_181 . V_250 = NULL ;
if ( V_14 < 0 )
return V_14 ;
* V_195 |= V_14 ;
break;
case V_72 :
V_14 = F_272 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_195 |= V_14 ;
break;
#ifdef F_34
case V_73 :
V_14 = F_273 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_195 |= V_14 ;
break;
#endif
default:
F_49 ( 1 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_274 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_195 = 0 ;
int V_14 ;
F_91 ( V_13 ) ;
F_234 ( & V_10 -> V_166 ) ;
F_234 ( & V_10 -> V_32 ) ;
if ( V_13 -> V_646 ) {
if ( V_13 -> V_647 )
return 0 ;
return F_275 ( V_13 ) ;
}
if ( ! F_70 ( & V_13 -> V_27 . V_230 . V_164 ,
& V_13 -> V_648 ) )
return - V_49 ;
V_13 -> V_27 . V_245 = false ;
V_14 = F_271 ( V_13 , & V_195 ) ;
if ( V_14 )
return V_14 ;
F_88 ( V_13 , V_195 ) ;
if ( V_13 -> V_248 ) {
F_93 ( V_10 , V_13 ,
V_249 ) ;
V_13 -> V_248 = false ;
}
V_14 = F_276 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_277 ( V_13 -> V_19 , & V_13 -> V_648 ) ;
return 0 ;
}
static void F_278 ( struct V_12 * V_13 )
{
if ( F_274 ( V_13 ) ) {
F_279 ( V_13 , L_6 ) ;
F_280 ( V_13 -> V_10 -> V_108 . V_2 , & V_13 -> V_11 ,
V_182 ) ;
}
}
void F_281 ( struct V_649 * V_620 )
{
struct V_12 * V_13 =
F_172 ( V_620 , struct V_12 ,
V_645 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_236 ( V_13 ) ;
F_16 ( & V_10 -> V_166 ) ;
F_16 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_245 )
goto V_650;
if ( ! F_12 ( V_13 ) )
goto V_650;
F_278 ( V_13 ) ;
V_650:
F_18 ( & V_10 -> V_32 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_237 ( V_13 ) ;
}
static int F_282 ( struct V_12 * V_13 ,
struct V_651 * V_8 ,
T_1 * V_195 )
{
struct V_176 V_177 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_181 . V_250 =
F_268 ( & V_8 -> V_652 ) ;
if ( ! V_13 -> V_16 . V_181 . V_250 )
return - V_183 ;
if ( V_8 -> V_203 <= 1 )
break;
if ( ( V_8 -> V_205 >
V_653 ) ||
( V_8 -> V_188 >
V_653 ) )
return - V_49 ;
V_177 . V_204 = V_8 -> V_204 ;
V_177 . V_187 = V_8 -> V_187 ;
V_177 . V_205 = V_8 -> V_205 ;
V_177 . V_188 = V_8 -> V_188 ;
V_177 . V_203 = V_8 -> V_203 ;
V_14 = F_81 ( V_13 , & V_8 -> V_654 , & V_177 ) ;
if ( V_14 < 0 ) {
F_94 ( V_13 -> V_16 . V_181 . V_250 ) ;
return V_14 ;
}
* V_195 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_230 . V_655 )
return - V_49 ;
if ( V_8 -> V_164 . V_567 != V_13 -> V_16 . V_656 . V_164 . V_567 )
return - V_49 ;
switch ( V_8 -> V_164 . V_567 ) {
case V_657 :
if ( F_283 ( & V_8 -> V_164 ) !=
F_283 ( & V_13 -> V_16 . V_656 . V_164 ) )
return - V_49 ;
case V_658 :
case V_659 :
case V_568 :
case V_660 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_656 . V_164 . V_617 -> V_285 !=
V_8 -> V_164 . V_617 -> V_285 )
return - V_49 ;
if ( V_8 -> V_203 > 1 ) {
V_14 = F_284 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_195 |= V_14 ;
}
F_285 ( V_13 , V_8 ) ;
break;
#ifdef F_34
case V_73 : {
struct V_397 * V_398 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_164 . V_567 != V_13 -> V_27 . V_230 . V_164 . V_567 )
return - V_49 ;
if ( V_13 -> V_27 . V_230 . V_164 . V_617 -> V_285 !=
V_8 -> V_164 . V_617 -> V_285 )
return - V_49 ;
if ( V_398 -> V_661 == V_662 ) {
V_398 -> V_661 = V_663 ;
if ( ! V_398 -> V_664 )
V_398 -> V_664 = 1 ;
else
V_398 -> V_664 ++ ;
}
if ( V_8 -> V_203 > 1 ) {
V_14 = F_286 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_398 -> V_661 = V_662 ;
return V_14 ;
}
* V_195 |= V_14 ;
}
if ( V_398 -> V_661 == V_663 )
F_285 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_346 ;
}
return 0 ;
}
static int
F_287 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_651 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_665 V_666 ;
struct V_667 * V_61 ;
struct V_668 * V_669 ;
T_1 V_195 = 0 ;
int V_14 ;
F_91 ( V_13 ) ;
F_234 ( & V_10 -> V_166 ) ;
if ( ! F_249 ( & V_10 -> V_623 ) || V_10 -> V_624 )
return - V_31 ;
if ( V_13 -> V_11 . V_254 )
return - V_31 ;
if ( F_70 ( & V_8 -> V_164 ,
& V_13 -> V_27 . V_230 . V_164 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_245 )
return - V_31 ;
F_16 ( & V_10 -> V_32 ) ;
V_61 = F_71 ( V_13 -> V_27 . V_670 ,
F_72 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_95;
}
V_669 = F_172 ( V_61 , struct V_668 , V_61 ) ;
if ( ! V_669 ) {
V_14 = - V_31 ;
goto V_95;
}
V_666 . V_671 = 0 ;
V_666 . V_672 = 0 ;
V_666 . V_673 = V_8 -> V_673 ;
V_666 . V_164 = V_8 -> V_164 ;
V_666 . V_203 = V_8 -> V_203 ;
V_14 = F_288 ( V_13 , & V_666 ) ;
if ( V_14 )
goto V_95;
V_14 = F_289 ( V_13 , & V_8 -> V_164 ,
V_669 -> V_674 ,
V_8 -> V_675 ) ;
if ( V_14 )
goto V_95;
V_14 = F_17 ( V_13 , NULL , V_669 -> V_674 , 0 ) ;
if ( V_14 ) {
F_290 ( V_13 ) ;
goto V_95;
}
V_14 = F_282 ( V_13 , V_8 , & V_195 ) ;
if ( V_14 ) {
F_290 ( V_13 ) ;
goto V_95;
}
V_13 -> V_648 = V_8 -> V_164 ;
V_13 -> V_248 = V_8 -> V_673 ;
V_13 -> V_27 . V_245 = true ;
if ( V_13 -> V_248 )
F_291 ( V_10 , V_13 ,
V_249 ) ;
F_292 ( V_13 -> V_19 , & V_13 -> V_648 ,
V_8 -> V_203 ) ;
if ( V_195 ) {
F_88 ( V_13 , V_195 ) ;
F_293 ( V_13 , & V_8 -> V_164 ) ;
} else {
F_278 ( V_13 ) ;
}
V_95:
F_18 ( & V_10 -> V_32 ) ;
return V_14 ;
}
int V_665 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_651 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_166 ) ;
V_14 = F_287 ( V_2 , V_19 , V_8 ) ;
F_18 ( & V_10 -> V_166 ) ;
return V_14 ;
}
static struct V_262 * F_294 ( struct V_9 * V_10 ,
struct V_262 * V_263 , T_4 * V_89 ,
T_8 V_676 )
{
unsigned long V_677 ;
struct V_262 * V_678 ;
int V_679 ;
V_678 = F_295 ( V_263 , V_676 ) ;
if ( ! V_678 )
return F_4 ( - V_183 ) ;
F_296 ( & V_10 -> V_680 , V_677 ) ;
V_679 = F_297 ( & V_10 -> V_681 , V_678 ,
1 , 0x10000 , V_682 ) ;
F_298 ( & V_10 -> V_680 , V_677 ) ;
if ( V_679 < 0 ) {
F_299 ( V_678 ) ;
return F_4 ( - V_183 ) ;
}
F_300 ( V_263 ) -> V_683 = V_679 ;
* V_89 = F_245 ( V_10 ) ;
F_300 ( V_678 ) -> V_684 . V_89 = * V_89 ;
return V_678 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_1 * V_11 ,
struct V_685 * V_8 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_262 * V_263 , * V_678 ;
struct V_38 * V_24 ;
const struct V_686 * V_687 = ( void * ) V_8 -> V_688 ;
bool V_689 = false ;
T_1 V_6 ;
int V_20 ;
T_3 * V_185 ;
if ( V_8 -> V_690 )
V_6 = V_691 ;
else
V_6 = V_692 |
V_693 ;
if ( V_8 -> V_694 )
V_6 |= V_695 ;
switch ( V_13 -> V_27 . type ) {
case V_72 :
if ( ! V_13 -> V_27 . V_230 . V_655 )
V_689 = true ;
#ifdef F_34
case V_73 :
if ( F_29 ( & V_13 -> V_27 ) &&
! V_13 -> V_16 . V_74 . V_405 )
V_689 = true ;
#endif
case V_70 :
case V_21 :
case V_82 :
if ( V_13 -> V_27 . type != V_72 &&
! F_29 ( & V_13 -> V_27 ) &&
! F_302 ( V_13 -> V_350 -> V_197 ) )
V_689 = true ;
if ( ! F_303 ( V_687 -> V_696 ) ||
V_687 -> V_16 . V_697 . V_698 == V_699 ||
V_687 -> V_16 . V_697 . V_698 == V_700 ||
V_687 -> V_16 . V_697 . V_698 == V_701 )
break;
F_42 () ;
V_24 = F_30 ( V_13 , V_687 -> V_264 ) ;
F_50 () ;
if ( ! V_24 )
return - V_702 ;
break;
case V_25 :
case V_81 :
F_236 ( V_13 ) ;
if ( ! V_13 -> V_16 . V_26 . V_572 ||
( V_8 -> V_703 && V_8 -> V_704 &&
V_10 -> V_499 -> V_616 &&
memcmp ( V_13 -> V_16 . V_26 . V_572 -> V_354 ,
V_687 -> V_354 , V_159 ) ) )
V_689 = true ;
F_237 ( V_13 ) ;
break;
case V_78 :
V_689 = true ;
break;
default:
return - V_346 ;
}
if ( V_689 && ! V_8 -> V_617 )
return - V_49 ;
F_16 ( & V_10 -> V_166 ) ;
if ( ! V_689 ) {
struct V_667 * V_670 ;
F_42 () ;
V_670 = F_43 ( V_13 -> V_27 . V_670 ) ;
if ( V_670 ) {
V_689 = V_8 -> V_617 &&
( V_8 -> V_617 !=
V_670 -> V_705 . V_617 ) ;
} else if ( ! V_8 -> V_617 ) {
V_20 = - V_49 ;
F_50 () ;
goto V_66;
} else {
V_689 = true ;
}
F_50 () ;
}
if ( V_689 && ! V_8 -> V_703 ) {
V_20 = - V_31 ;
goto V_66;
}
V_263 = F_105 ( V_10 -> V_108 . V_706 + V_8 -> V_184 ) ;
if ( ! V_263 ) {
V_20 = - V_183 ;
goto V_66;
}
F_304 ( V_263 , V_10 -> V_108 . V_706 ) ;
V_185 = F_106 ( V_263 , V_8 -> V_184 ) ;
memcpy ( V_185 , V_8 -> V_688 , V_8 -> V_184 ) ;
if ( V_13 -> V_27 . V_245 &&
( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_73 ||
V_13 -> V_27 . type == V_72 ) &&
V_8 -> V_707 ) {
int V_589 ;
struct V_191 * V_197 = NULL ;
F_42 () ;
if ( V_13 -> V_27 . type == V_70 )
V_197 = F_43 ( V_13 -> V_16 . V_181 . V_197 ) ;
else if ( V_13 -> V_27 . type == V_72 )
V_197 = F_43 ( V_13 -> V_16 . V_656 . V_708 ) ;
else if ( F_29 ( & V_13 -> V_27 ) )
V_197 = F_43 ( V_13 -> V_16 . V_74 . V_197 ) ;
if ( V_197 )
for ( V_589 = 0 ; V_589 < V_8 -> V_707 ; V_589 ++ )
V_185 [ V_8 -> V_709 [ V_589 ] ] =
V_197 -> V_202 ;
F_50 () ;
}
F_300 ( V_263 ) -> V_6 = V_6 ;
V_263 -> V_19 = V_13 -> V_19 ;
if ( ! V_8 -> V_690 ) {
V_678 = F_294 ( V_10 , V_263 , V_89 ,
V_182 ) ;
if ( F_25 ( V_678 ) ) {
V_20 = F_28 ( V_678 ) ;
F_299 ( V_263 ) ;
goto V_66;
}
} else {
V_678 = V_263 ;
}
if ( ! V_689 ) {
F_305 ( V_13 , V_263 ) ;
V_20 = 0 ;
goto V_66;
}
F_300 ( V_263 ) -> V_6 |= V_710 |
V_711 ;
if ( F_176 ( & V_10 -> V_108 , V_712 ) )
F_300 ( V_263 ) -> V_713 =
V_10 -> V_108 . V_714 ;
V_20 = F_246 ( V_10 , V_13 , V_8 -> V_617 ,
V_8 -> V_704 , V_89 , V_263 ,
V_715 ) ;
if ( V_20 )
F_299 ( V_263 ) ;
V_66:
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
static int F_306 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_259 ( V_10 , V_89 , true ) ;
}
static void F_307 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_716 , bool V_717 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
switch ( V_716 ) {
case V_718 | V_719 :
if ( V_717 )
V_10 -> V_720 ++ ;
else
V_10 -> V_720 -- ;
if ( ! V_10 -> V_171 )
break;
F_231 ( & V_10 -> V_108 , & V_10 -> V_721 ) ;
break;
default:
break;
}
}
static int F_308 ( struct V_2 * V_2 , T_1 V_722 , T_1 V_723 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_604 )
return - V_346 ;
return F_309 ( V_10 , V_722 , V_723 ) ;
}
static int F_310 ( struct V_2 * V_2 , T_1 * V_722 , T_1 * V_723 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_311 ( V_10 , V_722 , V_723 ) ;
}
static int F_312 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_724 * V_185 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_499 -> V_725 )
return - V_346 ;
F_313 ( V_10 , V_13 , V_185 ) ;
return 0 ;
}
static int F_314 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_726 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_727 * V_728 ;
struct V_262 * V_263 , * V_678 ;
int V_194 = sizeof( * V_728 ) ;
T_9 V_729 ;
bool V_730 ;
struct V_731 * V_732 ;
struct V_38 * V_24 ;
struct V_667 * V_670 ;
enum V_284 V_285 ;
int V_20 ;
F_16 ( & V_10 -> V_166 ) ;
F_42 () ;
V_670 = F_43 ( V_13 -> V_27 . V_670 ) ;
if ( F_49 ( ! V_670 ) ) {
V_20 = - V_49 ;
goto V_650;
}
V_285 = V_670 -> V_705 . V_617 -> V_285 ;
V_24 = F_31 ( V_13 , V_726 ) ;
if ( V_24 ) {
V_730 = V_24 -> V_24 . V_291 ;
} else {
V_20 = - V_702 ;
goto V_650;
}
if ( V_730 ) {
V_729 = F_315 ( V_733 |
V_734 |
V_735 ) ;
} else {
V_194 -= 2 ;
V_729 = F_315 ( V_733 |
V_736 |
V_735 ) ;
}
V_263 = F_105 ( V_10 -> V_108 . V_706 + V_194 ) ;
if ( ! V_263 ) {
V_20 = - V_183 ;
goto V_650;
}
V_263 -> V_19 = V_19 ;
F_304 ( V_263 , V_10 -> V_108 . V_706 ) ;
V_728 = ( void * ) F_106 ( V_263 , V_194 ) ;
V_728 -> V_696 = V_729 ;
V_728 -> V_737 = 0 ;
memcpy ( V_728 -> V_738 , V_24 -> V_24 . V_158 , V_159 ) ;
memcpy ( V_728 -> V_739 , V_13 -> V_27 . V_158 , V_159 ) ;
memcpy ( V_728 -> V_740 , V_13 -> V_27 . V_158 , V_159 ) ;
V_728 -> V_741 = 0 ;
V_732 = F_300 ( V_263 ) ;
V_732 -> V_6 |= V_693 |
V_692 ;
V_732 -> V_285 = V_285 ;
F_316 ( V_263 , V_742 ) ;
V_263 -> V_743 = 7 ;
if ( V_730 )
V_728 -> V_744 = F_315 ( 7 ) ;
V_678 = F_294 ( V_10 , V_263 , V_89 , V_682 ) ;
if ( F_25 ( V_678 ) ) {
F_299 ( V_263 ) ;
V_20 = F_28 ( V_678 ) ;
goto V_650;
}
F_317 () ;
F_318 ( V_13 , V_24 , V_263 ) ;
F_319 () ;
V_20 = 0 ;
V_650:
F_50 () ;
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
static int F_320 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_163 * V_164 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_667 * V_670 ;
int V_20 = - V_745 ;
F_42 () ;
V_670 = F_43 ( V_13 -> V_27 . V_670 ) ;
if ( V_670 ) {
* V_164 = V_13 -> V_27 . V_230 . V_164 ;
V_20 = 0 ;
} else if ( V_10 -> V_171 > 0 &&
V_10 -> V_171 == V_10 -> V_172 &&
V_13 -> V_27 . type == V_15 ) {
if ( V_10 -> V_168 )
* V_164 = V_10 -> V_165 ;
else
* V_164 = V_10 -> V_173 ;
V_20 = 0 ;
}
F_50 () ;
return V_20 ;
}
static void F_321 ( struct V_2 * V_2 , bool V_574 )
{
F_322 ( F_2 ( V_2 ) , V_574 ) ;
}
static int F_323 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_746 * V_747 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_748 * V_749 , * V_750 ;
if ( V_747 ) {
V_749 = F_78 ( sizeof( * V_749 ) , V_182 ) ;
if ( ! V_749 )
return - V_183 ;
memcpy ( & V_749 -> V_747 , V_747 , sizeof( * V_747 ) ) ;
} else {
V_749 = NULL ;
}
V_750 = F_77 ( V_13 -> V_747 , V_13 ) ;
F_79 ( V_13 -> V_747 , V_749 ) ;
if ( V_750 )
F_80 ( V_750 , V_189 ) ;
return 0 ;
}
static int F_324 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_163 * V_164 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_195 = 0 ;
V_20 = F_325 ( V_13 , V_164 , & V_195 ) ;
if ( V_20 == 0 )
F_88 ( V_13 , V_195 ) ;
return V_20 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_751 , const T_3 * V_726 , T_3 V_752 ,
T_2 V_753 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_754 * V_755 = & V_13 -> V_16 . V_26 ;
int V_509 = V_756 [ V_752 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_346 ;
if ( ! ( V_13 -> V_757 & F_112 ( V_752 ) ) )
return - V_49 ;
if ( V_755 -> V_758 [ V_509 ] . V_753 )
return - V_31 ;
if ( V_753 ) {
V_755 -> V_758 [ V_509 ] . V_753 = 32 * V_753 ;
V_755 -> V_758 [ V_509 ] . V_751 = V_751 ;
V_755 -> V_758 [ V_509 ] . V_752 = V_752 ;
}
return 0 ;
}
static int F_327 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_751 , const T_3 * V_726 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_754 * V_755 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_509 ;
for ( V_509 = 0 ; V_509 < V_290 ; V_509 ++ ) {
struct V_759 * V_758 = & V_755 -> V_758 [ V_509 ] ;
if ( ! V_758 -> V_753 )
continue;
if ( V_758 -> V_751 != V_751 )
continue;
V_758 -> V_752 = - 1 ;
F_328 () ;
F_329 ( V_10 , V_13 , false ) ;
V_758 -> V_697 = V_760 ;
V_758 -> V_761 = false ;
F_330 ( V_13 ) ;
memset ( V_758 , 0 , sizeof( * V_758 ) ) ;
return 0 ;
}
return - V_65 ;
}
