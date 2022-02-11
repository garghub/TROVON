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
static void F_115 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_283 * V_8 )
{
#ifdef F_34
struct V_12 * V_13 = V_24 -> V_13 ;
T_1 V_195 = 0 ;
if ( V_8 -> V_284 & V_285 ) {
switch ( V_8 -> V_286 ) {
case V_287 :
if ( V_24 -> V_74 -> V_286 != V_287 )
V_195 = F_116 ( V_13 ) ;
V_24 -> V_74 -> V_286 = V_8 -> V_286 ;
F_117 ( V_24 ) ;
V_195 |= F_118 ( V_24 ,
V_13 -> V_16 . V_74 . V_288 . V_289 ) ;
break;
case V_290 :
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
if ( V_24 -> V_74 -> V_286 == V_287 )
V_195 = F_119 ( V_13 ) ;
V_24 -> V_74 -> V_286 = V_8 -> V_286 ;
F_117 ( V_24 ) ;
V_195 |= F_118 ( V_24 ,
V_296 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_297 ) {
case V_298 :
break;
case V_299 :
V_195 |= F_120 ( V_24 ) ;
break;
case V_300 :
V_195 |= F_121 ( V_24 ) ;
break;
}
if ( V_8 -> V_301 )
V_195 |= F_118 ( V_24 ,
V_8 -> V_301 ) ;
F_122 ( V_13 , V_195 ) ;
#endif
}
static int F_123 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_283 * V_8 )
{
int V_20 = 0 ;
struct V_123 * V_124 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_302 V_303 = F_59 ( V_13 ) ;
T_1 V_28 , V_272 ;
V_124 = V_10 -> V_108 . V_2 -> V_127 [ V_303 ] ;
V_28 = V_8 -> V_304 ;
V_272 = V_8 -> V_305 ;
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
if ( V_28 & F_112 ( V_306 ) &&
V_10 -> V_108 . V_307 >= V_308 )
V_24 -> V_24 . V_309 = V_272 & F_112 ( V_306 ) ;
if ( ! F_32 ( V_24 , V_277 ) ) {
V_20 = F_111 ( V_10 , V_24 , V_28 , V_272 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_112 ( V_310 ) ) {
if ( V_272 & F_112 ( V_310 ) )
F_124 ( V_24 , V_311 ) ;
else
F_125 ( V_24 , V_311 ) ;
}
if ( V_28 & F_112 ( V_312 ) ) {
if ( V_272 & F_112 ( V_312 ) )
F_124 ( V_24 , V_71 ) ;
else
F_125 ( V_24 , V_71 ) ;
}
if ( V_28 & F_112 ( V_313 ) ) {
if ( V_272 & F_112 ( V_313 ) )
F_124 ( V_24 , V_277 ) ;
else
F_125 ( V_24 , V_277 ) ;
}
if ( F_32 ( V_24 , V_277 ) &&
! V_13 -> V_16 . V_26 . V_314 &&
V_8 -> V_315 >= 4 &&
V_8 -> V_316 [ 3 ] & V_317 )
F_124 ( V_24 , V_318 ) ;
if ( F_32 ( V_24 , V_277 ) &&
F_126 ( & V_10 -> V_108 , V_319 ) &&
V_8 -> V_315 >= 8 &&
V_8 -> V_316 [ 7 ] & V_320 )
F_124 ( V_24 , V_321 ) ;
if ( V_8 -> V_284 & V_322 ) {
V_24 -> V_24 . V_323 = V_8 -> V_323 ;
V_24 -> V_24 . V_324 = V_8 -> V_324 ;
}
if ( V_8 -> V_325 )
V_24 -> V_24 . V_325 = V_8 -> V_325 ;
if ( V_8 -> V_326 >= 0 )
V_24 -> V_326 = V_8 -> V_326 ;
if ( V_8 -> V_327 ) {
F_127 ( & V_13 -> V_27 . V_230 . V_164 ,
V_124 , V_8 -> V_327 ,
V_8 -> V_328 ,
& V_24 -> V_24 . V_329 [ V_303 ] ) ;
}
if ( V_8 -> V_330 )
F_128 ( V_13 , V_124 ,
V_8 -> V_330 , V_24 ) ;
if ( V_8 -> V_331 )
F_129 ( V_13 , V_124 ,
V_8 -> V_331 , V_24 ) ;
if ( V_8 -> V_332 ) {
F_130 ( V_13 , V_24 ,
V_8 -> V_333 ,
V_303 , false ) ;
}
if ( F_29 ( & V_13 -> V_27 ) )
F_115 ( V_10 , V_24 , V_8 ) ;
if ( F_32 ( V_24 , V_277 ) ) {
V_20 = F_111 ( V_10 , V_24 , V_28 , V_272 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_155 ,
struct V_283 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_13 ;
int V_14 ;
int V_334 ;
if ( V_8 -> V_23 ) {
V_13 = F_9 ( V_8 -> V_23 ) ;
if ( V_13 -> V_27 . type != V_21 &&
V_13 -> V_27 . type != V_70 )
return - V_49 ;
} else
V_13 = F_9 ( V_19 ) ;
if ( F_132 ( V_155 , V_13 -> V_27 . V_158 ) )
return - V_49 ;
if ( F_133 ( V_155 ) )
return - V_49 ;
V_24 = F_134 ( V_13 , V_155 , V_182 ) ;
if ( ! V_24 )
return - V_183 ;
if ( ! ( V_8 -> V_305 & F_112 ( V_313 ) ) ) {
F_135 ( V_24 , V_275 ) ;
F_135 ( V_24 , V_278 ) ;
} else {
V_24 -> V_24 . V_335 = true ;
}
V_14 = F_123 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_136 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_32 ( V_24 , V_277 ) )
F_114 ( V_24 ) ;
V_334 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_137 ( V_24 ) ;
if ( V_14 ) {
F_50 () ;
return V_14 ;
}
if ( V_334 )
F_104 ( V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_138 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_336 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_155 )
return F_139 ( V_13 , V_8 -> V_155 ) ;
F_140 ( V_13 ) ;
return 0 ;
}
static int F_141 ( struct V_2 * V_2 ,
struct V_18 * V_19 , const T_3 * V_155 ,
struct V_283 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_337 ;
enum V_338 V_339 ;
int V_14 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_31 ( V_13 , V_155 ) ;
if ( ! V_24 ) {
V_14 = - V_65 ;
goto V_340;
}
switch ( V_13 -> V_27 . type ) {
case V_73 :
if ( V_13 -> V_16 . V_74 . V_341 )
V_339 = V_342 ;
else
V_339 = V_343 ;
break;
case V_72 :
V_339 = V_344 ;
break;
case V_25 :
if ( ! F_32 ( V_24 , V_277 ) ) {
V_339 = V_345 ;
break;
}
if ( F_32 ( V_24 , V_281 ) )
V_339 = V_346 ;
else
V_339 = V_347 ;
break;
case V_70 :
case V_21 :
V_339 = V_348 ;
break;
default:
V_14 = - V_349 ;
goto V_340;
}
V_14 = F_142 ( V_2 , V_8 , V_339 ) ;
if ( V_14 )
goto V_340;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_350 = false ;
bool V_351 = false ;
V_337 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_162 -> V_22 ) {
if ( V_337 -> V_16 . V_23 . V_24 ) {
V_14 = - V_31 ;
goto V_340;
}
F_79 ( V_337 -> V_16 . V_23 . V_24 , V_24 ) ;
V_351 = true ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_350 = true ;
}
V_24 -> V_13 = V_337 ;
F_143 ( V_24 ) ;
if ( V_24 -> V_352 == V_280 &&
V_350 != V_351 ) {
if ( V_351 )
F_144 ( & V_24 -> V_13 -> V_353 -> V_354 ) ;
else
F_145 ( & V_24 -> V_13 -> V_353 -> V_354 ) ;
}
F_104 ( V_24 ) ;
}
V_14 = F_123 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_340;
F_18 ( & V_10 -> V_63 ) ;
if ( ( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_355 != V_24 -> V_13 -> V_353 -> V_356 &&
F_32 ( V_24 , V_281 ) &&
F_146 ( V_24 ) != 1 ) {
F_147 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_158 ) ;
F_148 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_353 -> V_356 ,
V_24 -> V_24 . V_158 ,
V_24 -> V_13 -> V_27 . V_230 . V_357 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_304 & F_112 ( V_279 ) ) {
F_149 ( V_10 , - 1 ) ;
F_150 ( V_13 ) ;
}
return 0 ;
V_340:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_151 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_358 , const T_3 * V_359 )
{
struct V_12 * V_13 ;
struct V_360 * V_361 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_359 ) ;
if ( ! V_24 ) {
F_50 () ;
return - V_65 ;
}
V_361 = F_152 ( V_13 , V_358 ) ;
if ( F_25 ( V_361 ) ) {
F_50 () ;
return F_28 ( V_361 ) ;
}
F_153 ( V_361 , V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_358 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_358 )
return F_155 ( V_13 , V_358 ) ;
F_156 ( V_13 ) ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_358 , const T_3 * V_359 )
{
struct V_12 * V_13 ;
struct V_360 * V_361 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_359 ) ;
if ( ! V_24 ) {
F_50 () ;
return - V_65 ;
}
V_361 = F_158 ( V_13 , V_358 ) ;
if ( ! V_361 ) {
F_50 () ;
return - V_65 ;
}
F_153 ( V_361 , V_24 ) ;
F_50 () ;
return 0 ;
}
static void F_159 ( struct V_360 * V_361 , T_3 * V_359 ,
struct V_362 * V_363 )
{
struct V_38 * V_364 = F_43 ( V_361 -> V_359 ) ;
if ( V_364 )
memcpy ( V_359 , V_364 -> V_24 . V_158 , V_159 ) ;
else
F_160 ( V_359 ) ;
memset ( V_363 , 0 , sizeof( * V_363 ) ) ;
V_363 -> V_365 = V_366 ;
V_363 -> V_367 = V_368 |
V_369 |
V_370 |
V_371 |
V_372 |
V_373 |
V_374 ;
V_363 -> V_375 = V_361 -> V_376 . V_377 ;
V_363 -> V_378 = V_361 -> V_378 ;
V_363 -> V_379 = V_361 -> V_379 ;
if ( F_161 ( V_380 , V_361 -> V_381 ) )
V_363 -> V_382 = F_162 ( V_361 -> V_381 - V_380 ) ;
V_363 -> V_383 =
F_162 ( V_361 -> V_383 ) ;
V_363 -> V_384 = V_361 -> V_384 ;
if ( V_361 -> V_6 & V_385 )
V_363 -> V_6 |= V_386 ;
if ( V_361 -> V_6 & V_387 )
V_363 -> V_6 |= V_388 ;
if ( V_361 -> V_6 & V_389 )
V_363 -> V_6 |= V_390 ;
if ( V_361 -> V_6 & V_391 )
V_363 -> V_6 |= V_392 ;
if ( V_361 -> V_6 & V_393 )
V_363 -> V_6 |= V_394 ;
}
static int F_163 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_358 , T_3 * V_359 , struct V_362 * V_363 )
{
struct V_12 * V_13 ;
struct V_360 * V_361 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_361 = F_158 ( V_13 , V_358 ) ;
if ( ! V_361 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_358 , V_361 -> V_358 , V_159 ) ;
F_159 ( V_361 , V_359 , V_363 ) ;
F_50 () ;
return 0 ;
}
static int F_164 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_358 , T_3 * V_359 ,
struct V_362 * V_363 )
{
struct V_12 * V_13 ;
struct V_360 * V_361 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_361 = F_165 ( V_13 , V_119 ) ;
if ( ! V_361 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_358 , V_361 -> V_358 , V_159 ) ;
F_159 ( V_361 , V_359 , V_363 ) ;
F_50 () ;
return 0 ;
}
static void F_166 ( struct V_360 * V_361 , T_3 * V_395 ,
struct V_362 * V_363 )
{
memset ( V_363 , 0 , sizeof( * V_363 ) ) ;
memcpy ( V_395 , V_361 -> V_395 , V_159 ) ;
V_363 -> V_365 = V_396 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_358 , T_3 * V_395 , struct V_362 * V_363 )
{
struct V_12 * V_13 ;
struct V_360 * V_361 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_361 = F_168 ( V_13 , V_358 ) ;
if ( ! V_361 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_358 , V_361 -> V_358 , V_159 ) ;
F_166 ( V_361 , V_395 , V_363 ) ;
F_50 () ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_358 , T_3 * V_395 ,
struct V_362 * V_363 )
{
struct V_12 * V_13 ;
struct V_360 * V_361 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_361 = F_170 ( V_13 , V_119 ) ;
if ( ! V_361 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_358 , V_361 -> V_358 , V_159 ) ;
F_166 ( V_361 , V_395 , V_363 ) ;
F_50 () ;
return 0 ;
}
static int F_171 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_397 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_288 ) , sizeof( struct V_397 ) ) ;
return 0 ;
}
static inline bool F_172 ( enum V_398 V_399 , T_1 V_28 )
{
return ( V_28 >> ( V_399 - 1 ) ) & 0x1 ;
}
static int F_173 ( struct V_400 * V_401 ,
const struct V_402 * V_403 )
{
T_3 * V_404 ;
const T_3 * V_405 ;
struct V_12 * V_13 = F_174 ( V_401 ,
struct V_12 , V_16 . V_74 ) ;
V_404 = NULL ;
V_405 = V_401 -> V_406 ;
if ( V_403 -> V_407 ) {
V_404 = F_175 ( V_403 -> V_406 , V_403 -> V_407 ,
V_182 ) ;
if ( ! V_404 )
return - V_183 ;
}
V_401 -> V_407 = V_403 -> V_407 ;
V_401 -> V_406 = V_404 ;
F_94 ( V_405 ) ;
V_401 -> V_408 = V_403 -> V_408 ;
memcpy ( V_401 -> V_409 , V_403 -> V_409 , V_401 -> V_408 ) ;
V_401 -> V_410 = V_403 -> V_411 ;
V_401 -> V_412 = V_403 -> V_413 ;
V_401 -> V_414 = V_403 -> V_415 ;
V_401 -> V_341 = V_403 -> V_341 ;
V_401 -> V_416 = V_403 -> V_417 ;
V_401 -> V_75 = V_76 ;
if ( V_403 -> V_418 )
V_401 -> V_75 |= V_419 ;
if ( V_403 -> V_420 )
V_401 -> V_75 |= V_421 ;
memcpy ( V_13 -> V_27 . V_230 . V_422 , V_403 -> V_422 ,
sizeof( V_403 -> V_422 ) ) ;
V_13 -> V_27 . V_230 . V_423 = V_403 -> V_423 ;
V_13 -> V_27 . V_230 . V_231 = V_403 -> V_232 ;
V_13 -> V_27 . V_230 . V_233 = V_403 -> V_233 ;
return 0 ;
}
static int F_176 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_397 * V_424 )
{
struct V_397 * V_61 ;
struct V_12 * V_13 ;
struct V_400 * V_401 ;
V_13 = F_9 ( V_19 ) ;
V_401 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_288 ) ;
if ( F_172 ( V_425 , V_28 ) )
V_61 -> V_426 = V_424 -> V_426 ;
if ( F_172 ( V_427 , V_28 ) )
V_61 -> V_428 = V_424 -> V_428 ;
if ( F_172 ( V_429 , V_28 ) )
V_61 -> V_430 = V_424 -> V_430 ;
if ( F_172 ( V_431 , V_28 ) )
V_61 -> V_432 = V_424 -> V_432 ;
if ( F_172 ( V_433 , V_28 ) )
V_61 -> V_434 = V_424 -> V_434 ;
if ( F_172 ( V_435 , V_28 ) )
V_61 -> V_436 = V_424 -> V_436 ;
if ( F_172 ( V_437 , V_28 ) )
V_61 -> V_438 = V_424 -> V_438 ;
if ( F_172 ( V_439 , V_28 ) ) {
if ( V_401 -> V_341 )
return - V_31 ;
V_61 -> V_440 = V_424 -> V_440 ;
}
if ( F_172 ( V_441 , V_28 ) )
V_61 -> V_442 =
V_424 -> V_442 ;
if ( F_172 ( V_443 , V_28 ) )
V_61 -> V_444 =
V_424 -> V_444 ;
if ( F_172 ( V_445 , V_28 ) )
V_61 -> V_446 = V_424 -> V_446 ;
if ( F_172 ( V_447 , V_28 ) )
V_61 -> V_448 = V_424 -> V_448 ;
if ( F_172 ( V_449 , V_28 ) )
V_61 -> V_450 =
V_424 -> V_450 ;
if ( F_172 ( V_451 , V_28 ) )
V_61 -> V_452 =
V_424 -> V_452 ;
if ( F_172 ( V_453 , V_28 ) )
V_61 -> V_454 =
V_424 -> V_454 ;
if ( F_172 ( V_455 ,
V_28 ) )
V_61 -> V_456 =
V_424 -> V_456 ;
if ( F_172 ( V_457 , V_28 ) ) {
V_61 -> V_458 = V_424 -> V_458 ;
F_177 ( V_401 ) ;
}
if ( F_172 ( V_459 , V_28 ) ) {
if ( V_424 -> V_460 &&
! ( V_61 -> V_458 > V_461 ) ) {
V_61 -> V_458 = V_462 ;
F_177 ( V_401 ) ;
}
V_61 -> V_460 =
V_424 -> V_460 ;
}
if ( F_172 ( V_463 , V_28 ) )
V_61 -> V_464 =
V_424 -> V_464 ;
if ( F_172 ( V_465 , V_28 ) )
V_61 -> V_466 = V_424 -> V_466 ;
if ( F_172 ( V_467 , V_28 ) ) {
if ( ! F_126 ( & V_13 -> V_10 -> V_108 , V_468 ) )
return - V_469 ;
V_61 -> V_470 = V_424 -> V_470 ;
}
if ( F_172 ( V_471 , V_28 ) ) {
V_61 -> V_472 = V_424 -> V_472 ;
V_13 -> V_27 . V_230 . V_473 = V_424 -> V_472 ;
F_88 ( V_13 , V_474 ) ;
}
if ( F_172 ( V_475 , V_28 ) )
V_61 -> V_476 =
V_424 -> V_476 ;
if ( F_172 ( V_477 , V_28 ) )
V_61 -> V_478 =
V_424 -> V_478 ;
if ( F_172 ( V_479 , V_28 ) )
V_61 -> V_480 =
V_424 -> V_480 ;
if ( F_172 ( V_481 , V_28 ) ) {
V_61 -> V_289 = V_424 -> V_289 ;
F_178 ( V_13 ) ;
}
if ( F_172 ( V_482 , V_28 ) )
V_61 -> V_483 =
V_424 -> V_483 ;
if ( F_172 ( V_484 , V_28 ) )
V_61 -> V_485 = V_424 -> V_485 ;
F_122 ( V_13 , V_196 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_397 * V_61 ,
const struct V_402 * V_403 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_400 * V_401 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_401 -> V_288 , V_61 , sizeof( struct V_397 ) ) ;
V_14 = F_173 ( V_401 , V_403 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_215 = V_217 ;
V_13 -> V_222 = V_13 -> V_10 -> V_223 ;
F_16 ( & V_13 -> V_10 -> V_166 ) ;
V_14 = F_74 ( V_13 , & V_403 -> V_164 ,
V_224 ) ;
F_18 ( & V_13 -> V_10 -> V_166 ) ;
if ( V_14 )
return V_14 ;
return F_180 ( V_13 ) ;
}
static int F_181 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_182 ( V_13 ) ;
F_16 ( & V_13 -> V_10 -> V_166 ) ;
F_73 ( V_13 ) ;
F_18 ( & V_13 -> V_10 -> V_166 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_486 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_302 V_303 ;
T_1 V_195 = 0 ;
if ( ! F_77 ( V_13 -> V_16 . V_181 . V_197 , V_13 ) )
return - V_65 ;
V_303 = F_59 ( V_13 ) ;
if ( V_8 -> V_487 >= 0 ) {
V_13 -> V_27 . V_230 . V_487 = V_8 -> V_487 ;
V_195 |= V_488 ;
}
if ( V_8 -> V_489 >= 0 ) {
V_13 -> V_27 . V_230 . V_489 =
V_8 -> V_489 ;
V_195 |= V_490 ;
}
if ( ! V_13 -> V_27 . V_230 . V_491 &&
V_303 == V_492 ) {
V_13 -> V_27 . V_230 . V_491 = true ;
V_195 |= V_493 ;
}
if ( V_8 -> V_494 >= 0 ) {
V_13 -> V_27 . V_230 . V_491 =
V_8 -> V_494 ;
V_195 |= V_493 ;
}
if ( V_8 -> V_423 ) {
F_127 ( & V_13 -> V_27 . V_230 . V_164 ,
V_2 -> V_127 [ V_303 ] ,
V_8 -> V_423 ,
V_8 -> V_495 ,
& V_13 -> V_27 . V_230 . V_423 ) ;
V_195 |= V_496 ;
}
if ( V_8 -> V_497 >= 0 ) {
if ( V_8 -> V_497 )
V_13 -> V_6 |= V_498 ;
else
V_13 -> V_6 &= ~ V_498 ;
}
if ( V_8 -> V_472 >= 0 ) {
V_13 -> V_27 . V_230 . V_473 =
( T_2 ) V_8 -> V_472 ;
V_195 |= V_474 ;
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
static int F_184 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_499 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_500 V_501 ;
if ( ! V_10 -> V_502 -> V_503 )
return - V_349 ;
if ( V_10 -> V_108 . V_307 < V_308 )
return - V_349 ;
memset ( & V_501 , 0 , sizeof( V_501 ) ) ;
V_501 . V_504 = V_8 -> V_504 ;
V_501 . V_505 = V_8 -> V_506 ;
V_501 . V_507 = V_8 -> V_508 ;
V_501 . V_509 = V_8 -> V_509 ;
V_501 . V_510 = false ;
V_13 -> V_511 [ V_8 -> V_512 ] = V_501 ;
if ( F_185 ( V_10 , V_13 , V_8 -> V_512 , & V_501 ) ) {
F_186 ( V_10 -> V_108 . V_2 ,
L_2 ,
V_8 -> V_512 ) ;
return - V_49 ;
}
F_88 ( V_13 , V_513 ) ;
return 0 ;
}
static int F_187 ( struct V_2 * V_2 ,
struct V_514 * V_515 )
{
return F_188 ( F_2 ( V_2 ) , V_515 ) ;
}
static int F_189 ( struct V_2 * V_2 )
{
return F_190 ( F_2 ( V_2 ) ) ;
}
static int F_191 ( struct V_2 * V_2 ,
struct V_516 * V_517 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_517 -> V_11 ) ;
switch ( F_192 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_72 :
case V_73 :
case V_81 :
case V_78 :
break;
case V_82 :
if ( V_13 -> V_10 -> V_502 -> V_518 )
break;
case V_70 :
if ( V_13 -> V_16 . V_181 . V_197 &&
( ! ( V_2 -> V_519 & V_520 ) ||
! ( V_517 -> V_6 & V_521 ) ) )
return - V_349 ;
break;
default:
return - V_349 ;
}
return F_193 ( V_13 , V_517 ) ;
}
static int
F_194 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_522 * V_517 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_502 -> V_523 )
return - V_349 ;
return F_195 ( V_13 , V_517 ) ;
}
static int
F_196 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_502 -> V_524 )
return - V_349 ;
return F_197 ( V_13 ) ;
}
static int F_198 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_525 * V_517 )
{
return F_199 ( F_9 ( V_19 ) , V_517 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_526 * V_517 )
{
return F_201 ( F_9 ( V_19 ) , V_517 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_527 * V_517 )
{
return F_203 ( F_9 ( V_19 ) , V_517 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_528 * V_517 )
{
return F_205 ( F_9 ( V_19 ) , V_517 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_529 * V_8 )
{
return F_207 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_209 ( F_9 ( V_19 ) ) ;
}
static int F_210 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_530 * V_403 )
{
return F_211 ( F_9 ( V_19 ) , V_403 ) ;
}
static int F_212 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_213 ( F_9 ( V_19 ) ) ;
}
static int F_214 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_113 [ V_531 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_230 . V_422 , V_113 ,
sizeof( int ) * V_531 ) ;
return 0 ;
}
static int F_215 ( struct V_2 * V_2 , T_1 V_195 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_195 & V_532 ) {
F_216 ( V_10 ) ;
V_14 = F_217 ( V_10 , V_2 -> V_533 ) ;
if ( V_14 ) {
F_216 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_195 & V_534 ) ||
( V_195 & V_535 ) ) {
T_6 V_536 ;
V_536 = V_195 & V_534 ?
V_2 -> V_536 : - 1 ;
V_14 = F_218 ( V_10 , V_536 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_195 & V_537 ) {
V_14 = F_219 ( V_10 , V_2 -> V_538 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_195 & V_539 ) {
if ( V_2 -> V_540 > V_541 )
return - V_49 ;
V_10 -> V_108 . V_61 . V_542 = V_2 -> V_540 ;
}
if ( V_195 & V_543 ) {
if ( V_2 -> V_544 > V_541 )
return - V_49 ;
V_10 -> V_108 . V_61 . V_545 = V_2 -> V_544 ;
}
if ( V_195 &
( V_539 | V_543 ) )
F_75 ( V_10 , V_546 ) ;
return 0 ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_547 type , int V_548 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_547 V_549 = type ;
bool V_550 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_551 :
V_13 -> V_552 = V_553 ;
V_549 = V_554 ;
break;
case V_554 :
case V_555 :
if ( V_548 < 0 || ( V_548 % 100 ) )
return - V_349 ;
V_13 -> V_552 = F_221 ( V_548 ) ;
break;
}
if ( V_549 != V_13 -> V_27 . V_230 . V_556 ) {
V_550 = true ;
V_13 -> V_27 . V_230 . V_556 = V_549 ;
}
F_222 ( V_13 , V_550 ) ;
return 0 ;
}
switch ( type ) {
case V_551 :
V_10 -> V_552 = V_553 ;
V_549 = V_554 ;
break;
case V_554 :
case V_555 :
if ( V_548 < 0 || ( V_548 % 100 ) )
return - V_349 ;
V_10 -> V_552 = F_221 ( V_548 ) ;
break;
}
F_16 ( & V_10 -> V_167 ) ;
F_85 (sdata, &local->interfaces, list) {
V_13 -> V_552 = V_10 -> V_552 ;
if ( V_549 != V_13 -> V_27 . V_230 . V_556 )
V_550 = true ;
V_13 -> V_27 . V_230 . V_556 = V_549 ;
}
F_85 (sdata, &local->interfaces, list)
F_222 ( V_13 , V_550 ) ;
F_18 ( & V_10 -> V_167 ) ;
return 0 ;
}
static int F_223 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_557 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_502 -> V_558 )
return F_224 ( V_10 , V_13 , V_557 ) ;
if ( ! V_10 -> V_168 )
* V_557 = V_10 -> V_108 . V_61 . V_559 ;
else
* V_557 = V_13 -> V_27 . V_230 . V_560 ;
return 0 ;
}
static int F_225 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_158 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_561 . V_562 , V_158 , V_159 ) ;
return 0 ;
}
static void F_226 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_227 ( V_10 ) ;
}
static int F_228 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
void * V_185 , int V_184 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_563 * V_27 = NULL ;
if ( ! V_10 -> V_502 -> V_564 )
return - V_349 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_565 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_502 -> V_564 ( & V_10 -> V_108 , V_27 , V_185 , V_184 ) ;
}
static int F_229 ( struct V_2 * V_2 ,
struct V_262 * V_263 ,
struct V_566 * V_271 ,
void * V_185 , int V_184 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_502 -> V_567 )
return - V_349 ;
return V_10 -> V_502 -> V_567 ( & V_10 -> V_108 , V_263 , V_271 , V_185 , V_184 ) ;
}
int F_230 ( struct V_12 * V_13 ,
enum V_568 V_215 )
{
struct V_38 * V_24 ;
enum V_568 V_569 ;
if ( F_35 ( V_13 -> V_27 . type != V_70 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_230 . V_164 . V_570 == V_571 )
return 0 ;
V_569 = V_13 -> V_16 . V_181 . V_356 ;
V_13 -> V_16 . V_181 . V_356 = V_215 ;
if ( V_569 == V_215 ||
V_215 == V_572 )
return 0 ;
if ( ! F_231 ( & V_13 -> V_16 . V_181 . V_354 ) ) {
V_13 -> V_215 = V_215 ;
F_232 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_573 ) ;
return 0 ;
}
F_147 ( V_13 ,
L_3 ,
V_215 , F_231 ( & V_13 -> V_16 . V_181 . V_354 ) ) ;
F_16 ( & V_13 -> V_10 -> V_63 ) ;
F_85 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_353 != & V_13 -> V_16 . V_181 )
continue;
if ( F_146 ( V_24 ) == 1 )
continue;
if ( F_32 ( V_24 , V_574 ) &&
! F_233 ( V_24 -> V_355 ,
V_215 ) ) {
F_147 ( V_13 , L_4 ,
V_24 -> V_24 . V_158 ) ;
continue;
}
if ( ! F_32 ( V_24 , V_281 ) )
continue;
F_147 ( V_13 , L_5 , V_24 -> V_24 . V_158 ) ;
F_148 ( V_13 , V_215 , V_24 -> V_24 . V_158 ,
V_13 -> V_27 . V_230 . V_357 ) ;
}
F_18 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_215 = V_215 ;
F_232 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_573 ) ;
return 0 ;
}
int F_234 ( struct V_12 * V_13 ,
enum V_568 V_215 )
{
const T_3 * V_181 ;
enum V_568 V_569 ;
int V_14 ;
struct V_38 * V_24 ;
bool V_575 = false ;
F_235 ( & V_13 -> V_11 . V_166 ) ;
if ( F_35 ( V_13 -> V_27 . type != V_25 ) )
return - V_49 ;
V_569 = V_13 -> V_16 . V_26 . V_356 ;
V_13 -> V_16 . V_26 . V_356 = V_215 ;
if ( V_569 == V_215 &&
V_215 != V_572 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_576 ||
V_13 -> V_27 . V_230 . V_164 . V_570 == V_571 )
return 0 ;
V_181 = V_13 -> V_16 . V_26 . V_576 -> V_357 ;
F_42 () ;
F_236 (sta, &sdata->local->sta_list, list) {
if ( ! V_24 -> V_24 . V_335 || V_24 -> V_13 != V_13 || ! V_24 -> V_577 ||
! F_32 ( V_24 , V_281 ) )
continue;
V_575 = true ;
break;
}
F_50 () ;
if ( V_215 == V_572 ) {
if ( V_575 || ! V_13 -> V_16 . V_26 . V_578 )
V_215 = V_217 ;
else
V_215 = V_221 ;
}
V_14 = F_148 ( V_13 , V_215 ,
V_181 , V_181 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_356 = V_569 ;
else if ( V_215 != V_217 && V_575 )
F_237 ( V_13 ) ;
return V_14 ;
}
static int F_238 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_579 , int V_580 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_66 ( V_19 -> V_162 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_349 ;
if ( ! F_126 ( & V_10 -> V_108 , V_581 ) )
return - V_349 ;
if ( V_579 == V_13 -> V_16 . V_26 . V_578 &&
V_580 == V_10 -> V_582 )
return 0 ;
V_13 -> V_16 . V_26 . V_578 = V_579 ;
V_10 -> V_582 = V_580 ;
F_239 ( V_13 ) ;
F_234 ( V_13 , V_13 -> V_16 . V_26 . V_356 ) ;
F_240 ( V_13 ) ;
if ( F_126 ( & V_10 -> V_108 , V_583 ) )
F_75 ( V_10 , V_584 ) ;
F_149 ( V_10 , - 1 ) ;
F_150 ( V_13 ) ;
return 0 ;
}
static int F_241 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_585 , T_1 V_586 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_563 * V_27 = & V_13 -> V_27 ;
struct V_587 * V_230 = & V_27 -> V_230 ;
if ( V_585 == V_230 -> V_588 &&
V_586 == V_230 -> V_589 )
return 0 ;
if ( V_13 -> V_27 . V_590 & V_591 &&
! ( V_13 -> V_27 . V_590 & V_592 ) )
return - V_349 ;
V_230 -> V_588 = V_585 ;
V_230 -> V_589 = V_586 ;
V_13 -> V_16 . V_26 . V_593 = 0 ;
if ( V_13 -> V_16 . V_26 . V_576 &&
V_13 -> V_27 . V_590 & V_592 )
F_88 ( V_13 , V_594 ) ;
return 0 ;
}
static int F_242 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_158 ,
const struct V_595 * V_28 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_66 ( V_19 -> V_162 ) ;
int V_596 , V_20 ;
if ( ! F_12 ( V_13 ) )
return - V_43 ;
if ( F_126 ( & V_10 -> V_108 , V_597 ) ) {
V_20 = F_243 ( V_10 , V_13 , V_28 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_596 = 0 ; V_596 < V_531 ; V_596 ++ ) {
struct V_123 * V_124 = V_2 -> V_127 [ V_596 ] ;
int V_598 ;
V_13 -> V_599 [ V_596 ] = V_28 -> V_268 [ V_596 ] . V_130 ;
memcpy ( V_13 -> V_600 [ V_596 ] , V_28 -> V_268 [ V_596 ] . V_601 ,
sizeof( V_28 -> V_268 [ V_596 ] . V_601 ) ) ;
memcpy ( V_13 -> V_602 [ V_596 ] ,
V_28 -> V_268 [ V_596 ] . V_603 ,
sizeof( V_28 -> V_268 [ V_596 ] . V_603 ) ) ;
V_13 -> V_604 [ V_596 ] = false ;
V_13 -> V_605 [ V_596 ] = false ;
if ( ! V_124 )
continue;
for ( V_598 = 0 ; V_598 < V_606 ; V_598 ++ ) {
if ( ~ V_13 -> V_600 [ V_596 ] [ V_598 ] ) {
V_13 -> V_604 [ V_596 ] = true ;
break;
}
}
for ( V_598 = 0 ; V_598 < V_607 ; V_598 ++ ) {
if ( ~ V_13 -> V_602 [ V_596 ] [ V_598 ] ) {
V_13 -> V_605 [ V_596 ] = true ;
break;
}
}
}
return 0 ;
}
static bool F_244 ( struct V_9 * V_10 ,
struct V_608 * V_609 ,
struct V_608 * V_610 )
{
unsigned long V_611 = V_380 ;
unsigned long V_612 = V_610 -> V_613 +
F_245 ( V_610 -> V_614 ) -
V_611 ;
if ( F_49 ( ! V_610 -> V_615 || ! V_610 -> V_616 ) )
return false ;
if ( V_609 -> V_614 > F_162 ( V_612 ) )
return false ;
F_246 ( V_609 ) ;
F_247 ( & V_609 -> V_617 , & V_610 -> V_618 ) ;
return true ;
}
static T_4 F_248 ( struct V_9 * V_10 )
{
F_235 ( & V_10 -> V_166 ) ;
V_10 -> V_619 ++ ;
if ( F_49 ( V_10 -> V_619 == 0 ) )
V_10 -> V_619 ++ ;
return V_10 -> V_619 ;
}
static int F_249 ( struct V_9 * V_10 ,
struct V_12 * V_13 ,
struct V_620 * V_621 ,
unsigned int V_614 , T_4 * V_89 ,
struct V_262 * V_622 ,
enum V_623 type )
{
struct V_608 * V_624 , * V_625 ;
bool V_626 = false ;
int V_20 ;
F_235 ( & V_10 -> V_166 ) ;
if ( V_10 -> V_168 && ! V_10 -> V_502 -> V_627 )
return - V_349 ;
V_624 = F_78 ( sizeof( * V_624 ) , V_182 ) ;
if ( ! V_624 )
return - V_183 ;
if ( ! V_614 )
V_614 = 10 ;
V_624 -> V_628 = V_621 ;
V_624 -> V_614 = V_614 ;
V_624 -> V_629 = V_614 ;
V_624 -> V_630 = V_622 ;
V_624 -> type = type ;
V_624 -> V_13 = V_13 ;
F_250 ( & V_624 -> V_631 , V_632 ) ;
F_251 ( & V_624 -> V_618 ) ;
if ( ! V_622 ) {
V_624 -> V_89 = F_248 ( V_10 ) ;
* V_89 = V_624 -> V_89 ;
} else {
V_624 -> V_633 = * V_89 ;
}
if ( ! F_252 ( & V_10 -> V_634 ) ||
V_10 -> V_635 || F_253 ( V_10 ) )
goto V_636;
if ( ! V_10 -> V_502 -> V_627 ) {
F_254 ( & V_10 -> V_108 , & V_624 -> V_631 , 0 ) ;
goto V_637;
}
V_20 = F_255 ( V_10 , V_13 , V_621 , V_614 , type ) ;
if ( V_20 ) {
F_94 ( V_624 ) ;
return V_20 ;
}
V_624 -> V_615 = true ;
goto V_637;
V_636:
F_85 (tmp, &local->roc_list, list) {
if ( V_625 -> V_628 != V_621 || V_625 -> V_13 != V_13 )
continue;
if ( ! V_625 -> V_615 ) {
F_247 ( & V_624 -> V_617 , & V_625 -> V_618 ) ;
V_625 -> V_614 = F_256 ( V_625 -> V_614 , V_624 -> V_614 ) ;
V_625 -> type = F_256 ( V_625 -> type , V_624 -> type ) ;
V_626 = true ;
break;
}
if ( V_10 -> V_502 -> V_627 ) {
if ( ! V_625 -> V_616 ) {
F_247 ( & V_624 -> V_617 , & V_625 -> V_618 ) ;
V_626 = true ;
break;
}
if ( F_244 ( V_10 , V_624 , V_625 ) )
V_626 = true ;
} else if ( F_257 ( & V_625 -> V_631 . V_638 ) ) {
unsigned long V_639 ;
F_247 ( & V_624 -> V_617 , & V_625 -> V_618 ) ;
V_626 = true ;
V_639 = V_380 + F_245 ( V_624 -> V_614 ) ;
if ( F_258 ( V_639 , V_625 -> V_631 . V_638 . V_640 ) )
F_259 ( & V_625 -> V_631 . V_638 , V_639 ) ;
else
F_260 ( & V_625 -> V_631 . V_638 ) ;
F_246 ( V_624 ) ;
}
break;
}
V_637:
if ( ! V_626 )
F_247 ( & V_624 -> V_617 , & V_10 -> V_634 ) ;
return 0 ;
}
static int F_261 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_620 * V_628 ,
unsigned int V_614 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_20 ;
F_16 ( & V_10 -> V_166 ) ;
V_20 = F_249 ( V_10 , V_13 , V_628 ,
V_614 , V_89 , NULL ,
V_641 ) ;
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
static int F_262 ( struct V_9 * V_10 ,
T_4 V_89 , bool V_642 )
{
struct V_608 * V_624 , * V_625 , * V_643 = NULL ;
int V_20 ;
F_16 ( & V_10 -> V_166 ) ;
F_263 (roc, tmp, &local->roc_list, list) {
struct V_608 * V_644 , * V_645 ;
F_263 (dep, tmp2, &roc->dependents, list) {
if ( ! V_642 && V_644 -> V_89 != V_89 )
continue;
else if ( V_642 && V_644 -> V_633 != V_89 )
continue;
F_264 ( & V_644 -> V_617 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_265 ( V_644 , true ) ;
return 0 ;
}
if ( ! V_642 && V_624 -> V_89 != V_89 )
continue;
else if ( V_642 && V_624 -> V_633 != V_89 )
continue;
V_643 = V_624 ;
break;
}
if ( ! V_643 ) {
F_18 ( & V_10 -> V_166 ) ;
return - V_65 ;
}
if ( V_10 -> V_502 -> V_627 ) {
if ( V_643 -> V_615 ) {
V_20 = F_266 ( V_10 ) ;
if ( F_35 ( V_20 ) ) {
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
}
F_264 ( & V_643 -> V_617 ) ;
if ( V_643 -> V_615 )
F_267 ( V_10 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_265 ( V_643 , true ) ;
} else {
V_643 -> abort = true ;
F_254 ( & V_10 -> V_108 , & V_643 -> V_631 , 0 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_268 ( & V_643 -> V_631 ) ;
F_49 ( ! V_643 -> V_646 ) ;
F_94 ( V_643 ) ;
}
return 0 ;
}
static int F_269 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
return F_262 ( V_10 , V_89 , false ) ;
}
static int F_270 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_163 * V_164 ,
T_1 V_647 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_166 ) ;
if ( ! F_252 ( & V_10 -> V_634 ) || V_10 -> V_635 ) {
V_14 = - V_31 ;
goto V_66;
}
V_13 -> V_215 = V_217 ;
V_13 -> V_222 = V_10 -> V_223 ;
V_14 = F_74 ( V_13 , V_164 ,
V_224 ) ;
if ( V_14 )
goto V_66;
F_254 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_255 ,
F_245 ( V_647 ) ) ;
V_66:
F_18 ( & V_10 -> V_166 ) ;
return V_14 ;
}
static struct V_190 *
F_271 ( struct V_190 * V_197 )
{
struct V_190 * V_648 ;
T_3 * V_649 ;
int V_184 ;
V_184 = V_197 -> V_199 + V_197 -> V_201 + V_197 -> V_650 +
V_197 -> V_651 + V_197 -> V_652 +
V_197 -> V_206 ;
V_648 = F_78 ( sizeof( * V_648 ) + V_184 , V_182 ) ;
if ( ! V_648 )
return NULL ;
V_649 = ( T_3 * ) ( V_648 + 1 ) ;
if ( V_197 -> V_199 ) {
V_648 -> V_199 = V_197 -> V_199 ;
V_648 -> V_198 = V_649 ;
memcpy ( V_649 , V_197 -> V_198 , V_197 -> V_199 ) ;
V_649 += V_197 -> V_199 ;
}
if ( V_197 -> V_201 ) {
V_648 -> V_201 = V_197 -> V_201 ;
V_648 -> V_200 = V_649 ;
memcpy ( V_649 , V_197 -> V_200 , V_197 -> V_201 ) ;
V_649 += V_197 -> V_201 ;
}
if ( V_197 -> V_650 ) {
V_648 -> V_650 = V_197 -> V_650 ;
V_648 -> V_653 = V_649 ;
memcpy ( V_649 , V_197 -> V_653 , V_197 -> V_650 ) ;
V_649 += V_197 -> V_650 ;
}
if ( V_197 -> V_651 ) {
V_648 -> V_651 = V_197 -> V_651 ;
V_648 -> V_654 = V_649 ;
memcpy ( V_649 , V_197 -> V_654 , V_197 -> V_651 ) ;
V_649 += V_197 -> V_651 ;
}
if ( V_197 -> V_652 ) {
V_648 -> V_652 = V_197 -> V_652 ;
V_648 -> V_655 = V_649 ;
memcpy ( V_649 , V_197 -> V_655 , V_197 -> V_652 ) ;
V_649 += V_197 -> V_652 ;
}
if ( V_197 -> V_206 ) {
V_648 -> V_206 = V_197 -> V_206 ;
V_197 -> V_178 = V_649 ;
memcpy ( V_649 , V_197 -> V_178 , V_197 -> V_206 ) ;
V_649 += V_197 -> V_206 ;
}
return V_648 ;
}
void F_272 ( struct V_563 * V_27 )
{
struct V_12 * V_13 = F_273 ( V_27 ) ;
F_232 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_656 ) ;
}
static int F_274 ( struct V_12 * V_13 ,
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
V_14 = F_275 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_195 |= V_14 ;
break;
#ifdef F_34
case V_73 :
V_14 = F_276 ( V_13 ) ;
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
static int F_277 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_195 = 0 ;
int V_14 ;
F_91 ( V_13 ) ;
F_235 ( & V_10 -> V_166 ) ;
F_235 ( & V_10 -> V_32 ) ;
if ( V_13 -> V_657 ) {
if ( V_13 -> V_658 )
return 0 ;
return F_278 ( V_13 ) ;
}
if ( ! F_70 ( & V_13 -> V_27 . V_230 . V_164 ,
& V_13 -> V_659 ) )
return - V_49 ;
V_13 -> V_27 . V_245 = false ;
V_14 = F_274 ( V_13 , & V_195 ) ;
if ( V_14 )
return V_14 ;
F_88 ( V_13 , V_195 ) ;
if ( V_13 -> V_248 ) {
F_93 ( V_10 , V_13 ,
V_249 ) ;
V_13 -> V_248 = false ;
}
V_14 = F_279 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_280 ( V_13 -> V_19 , & V_13 -> V_659 ) ;
return 0 ;
}
static void F_281 ( struct V_12 * V_13 )
{
if ( F_277 ( V_13 ) ) {
F_282 ( V_13 , L_6 ) ;
F_283 ( V_13 -> V_10 -> V_108 . V_2 , & V_13 -> V_11 ,
V_182 ) ;
}
}
void F_284 ( struct V_660 * V_631 )
{
struct V_12 * V_13 =
F_174 ( V_631 , struct V_12 ,
V_656 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_239 ( V_13 ) ;
F_16 ( & V_10 -> V_166 ) ;
F_16 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_245 )
goto V_661;
if ( ! F_12 ( V_13 ) )
goto V_661;
F_281 ( V_13 ) ;
V_661:
F_18 ( & V_10 -> V_32 ) ;
F_18 ( & V_10 -> V_166 ) ;
F_240 ( V_13 ) ;
}
static int F_285 ( struct V_12 * V_13 ,
struct V_662 * V_8 ,
T_1 * V_195 )
{
struct V_176 V_177 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_181 . V_250 =
F_271 ( & V_8 -> V_663 ) ;
if ( ! V_13 -> V_16 . V_181 . V_250 )
return - V_183 ;
if ( V_8 -> V_203 <= 1 )
break;
if ( ( V_8 -> V_205 >
V_664 ) ||
( V_8 -> V_188 >
V_664 ) )
return - V_49 ;
V_177 . V_204 = V_8 -> V_204 ;
V_177 . V_187 = V_8 -> V_187 ;
V_177 . V_205 = V_8 -> V_205 ;
V_177 . V_188 = V_8 -> V_188 ;
V_177 . V_203 = V_8 -> V_203 ;
V_14 = F_81 ( V_13 , & V_8 -> V_665 , & V_177 ) ;
if ( V_14 < 0 ) {
F_94 ( V_13 -> V_16 . V_181 . V_250 ) ;
return V_14 ;
}
* V_195 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_230 . V_666 )
return - V_49 ;
if ( V_8 -> V_164 . V_570 != V_13 -> V_16 . V_667 . V_164 . V_570 )
return - V_49 ;
switch ( V_8 -> V_164 . V_570 ) {
case V_668 :
if ( F_286 ( & V_8 -> V_164 ) !=
F_286 ( & V_13 -> V_16 . V_667 . V_164 ) )
return - V_49 ;
case V_669 :
case V_670 :
case V_571 :
case V_671 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_667 . V_164 . V_628 -> V_303 !=
V_8 -> V_164 . V_628 -> V_303 )
return - V_49 ;
if ( V_8 -> V_203 > 1 ) {
V_14 = F_287 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_195 |= V_14 ;
}
F_288 ( V_13 , V_8 ) ;
break;
#ifdef F_34
case V_73 : {
struct V_400 * V_401 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_164 . V_570 != V_13 -> V_27 . V_230 . V_164 . V_570 )
return - V_49 ;
if ( V_13 -> V_27 . V_230 . V_164 . V_628 -> V_303 !=
V_8 -> V_164 . V_628 -> V_303 )
return - V_49 ;
if ( V_401 -> V_672 == V_673 ) {
V_401 -> V_672 = V_674 ;
if ( ! V_401 -> V_675 )
V_401 -> V_675 = 1 ;
else
V_401 -> V_675 ++ ;
}
if ( V_8 -> V_203 > 1 ) {
V_14 = F_289 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_401 -> V_672 = V_673 ;
return V_14 ;
}
* V_195 |= V_14 ;
}
if ( V_401 -> V_672 == V_674 )
F_288 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_349 ;
}
return 0 ;
}
static int
F_290 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_662 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_676 V_677 ;
struct V_678 * V_61 ;
struct V_679 * V_680 ;
T_1 V_195 = 0 ;
int V_14 ;
F_91 ( V_13 ) ;
F_235 ( & V_10 -> V_166 ) ;
if ( ! F_252 ( & V_10 -> V_634 ) || V_10 -> V_635 )
return - V_31 ;
if ( V_13 -> V_11 . V_254 )
return - V_31 ;
if ( F_70 ( & V_8 -> V_164 ,
& V_13 -> V_27 . V_230 . V_164 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_245 )
return - V_31 ;
F_16 ( & V_10 -> V_32 ) ;
V_61 = F_71 ( V_13 -> V_27 . V_681 ,
F_72 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_95;
}
V_680 = F_174 ( V_61 , struct V_679 , V_61 ) ;
if ( ! V_680 ) {
V_14 = - V_31 ;
goto V_95;
}
V_677 . V_682 = 0 ;
V_677 . V_683 = 0 ;
V_677 . V_684 = V_8 -> V_684 ;
V_677 . V_164 = V_8 -> V_164 ;
V_677 . V_203 = V_8 -> V_203 ;
V_14 = F_291 ( V_13 , & V_677 ) ;
if ( V_14 )
goto V_95;
V_14 = F_292 ( V_13 , & V_8 -> V_164 ,
V_680 -> V_685 ,
V_8 -> V_686 ) ;
if ( V_14 )
goto V_95;
V_14 = F_17 ( V_13 , NULL , V_680 -> V_685 , 0 ) ;
if ( V_14 ) {
F_293 ( V_13 ) ;
goto V_95;
}
V_14 = F_285 ( V_13 , V_8 , & V_195 ) ;
if ( V_14 ) {
F_293 ( V_13 ) ;
goto V_95;
}
V_13 -> V_659 = V_8 -> V_164 ;
V_13 -> V_248 = V_8 -> V_684 ;
V_13 -> V_27 . V_245 = true ;
if ( V_13 -> V_248 )
F_294 ( V_10 , V_13 ,
V_249 ) ;
F_295 ( V_13 -> V_19 , & V_13 -> V_659 ,
V_8 -> V_203 ) ;
if ( V_195 ) {
F_88 ( V_13 , V_195 ) ;
F_296 ( V_13 , & V_8 -> V_164 ) ;
} else {
F_281 ( V_13 ) ;
}
V_95:
F_18 ( & V_10 -> V_32 ) ;
return V_14 ;
}
int V_676 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_662 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_166 ) ;
V_14 = F_290 ( V_2 , V_19 , V_8 ) ;
F_18 ( & V_10 -> V_166 ) ;
return V_14 ;
}
static struct V_262 * F_297 ( struct V_9 * V_10 ,
struct V_262 * V_263 , T_4 * V_89 ,
T_8 V_687 )
{
unsigned long V_688 ;
struct V_262 * V_689 ;
int V_690 ;
V_689 = F_298 ( V_263 , V_687 ) ;
if ( ! V_689 )
return F_4 ( - V_183 ) ;
F_299 ( & V_10 -> V_691 , V_688 ) ;
V_690 = F_300 ( & V_10 -> V_692 , V_689 ,
1 , 0x10000 , V_693 ) ;
F_301 ( & V_10 -> V_691 , V_688 ) ;
if ( V_690 < 0 ) {
F_302 ( V_689 ) ;
return F_4 ( - V_183 ) ;
}
F_303 ( V_263 ) -> V_694 = V_690 ;
* V_89 = F_248 ( V_10 ) ;
F_303 ( V_689 ) -> V_695 . V_89 = * V_89 ;
return V_689 ;
}
static int F_304 ( struct V_2 * V_2 , struct V_1 * V_11 ,
struct V_696 * V_8 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_262 * V_263 , * V_689 ;
struct V_38 * V_24 ;
const struct V_697 * V_698 = ( void * ) V_8 -> V_699 ;
bool V_700 = false ;
T_1 V_6 ;
int V_20 ;
T_3 * V_185 ;
if ( V_8 -> V_701 )
V_6 = V_702 ;
else
V_6 = V_703 |
V_704 ;
if ( V_8 -> V_705 )
V_6 |= V_706 ;
switch ( V_13 -> V_27 . type ) {
case V_72 :
if ( ! V_13 -> V_27 . V_230 . V_666 )
V_700 = true ;
#ifdef F_34
case V_73 :
if ( F_29 ( & V_13 -> V_27 ) &&
! V_13 -> V_16 . V_74 . V_408 )
V_700 = true ;
#endif
case V_70 :
case V_21 :
case V_82 :
if ( V_13 -> V_27 . type != V_72 &&
! F_29 ( & V_13 -> V_27 ) &&
! F_305 ( V_13 -> V_353 -> V_197 ) )
V_700 = true ;
if ( ! F_306 ( V_698 -> V_707 ) ||
V_698 -> V_16 . V_708 . V_709 == V_710 ||
V_698 -> V_16 . V_708 . V_709 == V_711 ||
V_698 -> V_16 . V_708 . V_709 == V_712 )
break;
F_42 () ;
V_24 = F_30 ( V_13 , V_698 -> V_264 ) ;
F_50 () ;
if ( ! V_24 )
return - V_713 ;
break;
case V_25 :
case V_81 :
F_239 ( V_13 ) ;
if ( ! V_13 -> V_16 . V_26 . V_576 ||
( V_8 -> V_714 && V_8 -> V_715 &&
V_10 -> V_502 -> V_627 &&
memcmp ( V_13 -> V_16 . V_26 . V_576 -> V_357 ,
V_698 -> V_357 , V_159 ) ) )
V_700 = true ;
F_240 ( V_13 ) ;
break;
case V_78 :
V_700 = true ;
break;
default:
return - V_349 ;
}
if ( V_700 && ! V_8 -> V_628 )
return - V_49 ;
F_16 ( & V_10 -> V_166 ) ;
if ( ! V_700 ) {
struct V_678 * V_681 ;
F_42 () ;
V_681 = F_43 ( V_13 -> V_27 . V_681 ) ;
if ( V_681 ) {
V_700 = V_8 -> V_628 &&
( V_8 -> V_628 !=
V_681 -> V_716 . V_628 ) ;
} else if ( ! V_8 -> V_628 ) {
V_20 = - V_49 ;
F_50 () ;
goto V_66;
} else {
V_700 = true ;
}
F_50 () ;
}
if ( V_700 && ! V_8 -> V_714 ) {
V_20 = - V_31 ;
goto V_66;
}
V_263 = F_105 ( V_10 -> V_108 . V_717 + V_8 -> V_184 ) ;
if ( ! V_263 ) {
V_20 = - V_183 ;
goto V_66;
}
F_307 ( V_263 , V_10 -> V_108 . V_717 ) ;
V_185 = F_106 ( V_263 , V_8 -> V_184 ) ;
memcpy ( V_185 , V_8 -> V_699 , V_8 -> V_184 ) ;
if ( V_13 -> V_27 . V_245 &&
( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_73 ||
V_13 -> V_27 . type == V_72 ) &&
V_8 -> V_718 ) {
int V_596 ;
struct V_191 * V_197 = NULL ;
F_42 () ;
if ( V_13 -> V_27 . type == V_70 )
V_197 = F_43 ( V_13 -> V_16 . V_181 . V_197 ) ;
else if ( V_13 -> V_27 . type == V_72 )
V_197 = F_43 ( V_13 -> V_16 . V_667 . V_719 ) ;
else if ( F_29 ( & V_13 -> V_27 ) )
V_197 = F_43 ( V_13 -> V_16 . V_74 . V_197 ) ;
if ( V_197 )
for ( V_596 = 0 ; V_596 < V_8 -> V_718 ; V_596 ++ )
V_185 [ V_8 -> V_720 [ V_596 ] ] =
V_197 -> V_202 ;
F_50 () ;
}
F_303 ( V_263 ) -> V_6 = V_6 ;
V_263 -> V_19 = V_13 -> V_19 ;
if ( ! V_8 -> V_701 ) {
V_689 = F_297 ( V_10 , V_263 , V_89 ,
V_182 ) ;
if ( F_25 ( V_689 ) ) {
V_20 = F_28 ( V_689 ) ;
F_302 ( V_263 ) ;
goto V_66;
}
} else {
V_689 = V_263 ;
}
if ( ! V_700 ) {
F_308 ( V_13 , V_263 ) ;
V_20 = 0 ;
goto V_66;
}
F_303 ( V_263 ) -> V_6 |= V_721 |
V_722 ;
if ( F_126 ( & V_10 -> V_108 , V_723 ) )
F_303 ( V_263 ) -> V_724 =
V_10 -> V_108 . V_725 ;
V_20 = F_249 ( V_10 , V_13 , V_8 -> V_628 ,
V_8 -> V_715 , V_89 , V_263 ,
V_726 ) ;
if ( V_20 )
F_302 ( V_263 ) ;
V_66:
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
static int F_309 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_262 ( V_10 , V_89 , true ) ;
}
static void F_310 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_727 , bool V_728 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
switch ( V_727 ) {
case V_729 | V_730 :
if ( V_728 )
V_10 -> V_731 ++ ;
else
V_10 -> V_731 -- ;
if ( ! V_10 -> V_171 )
break;
F_232 ( & V_10 -> V_108 , & V_10 -> V_732 ) ;
break;
default:
break;
}
}
static int F_311 ( struct V_2 * V_2 , T_1 V_733 , T_1 V_734 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_615 )
return - V_349 ;
return F_312 ( V_10 , V_733 , V_734 ) ;
}
static int F_313 ( struct V_2 * V_2 , T_1 * V_733 , T_1 * V_734 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_314 ( V_10 , V_733 , V_734 ) ;
}
static int F_315 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_735 * V_185 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_502 -> V_736 )
return - V_349 ;
F_316 ( V_10 , V_13 , V_185 ) ;
return 0 ;
}
static int F_317 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_737 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_738 * V_739 ;
struct V_262 * V_263 , * V_689 ;
int V_194 = sizeof( * V_739 ) ;
T_9 V_740 ;
bool V_741 ;
struct V_742 * V_743 ;
struct V_38 * V_24 ;
struct V_678 * V_681 ;
enum V_302 V_303 ;
int V_20 ;
F_16 ( & V_10 -> V_166 ) ;
F_42 () ;
V_681 = F_43 ( V_13 -> V_27 . V_681 ) ;
if ( F_49 ( ! V_681 ) ) {
V_20 = - V_49 ;
goto V_661;
}
V_303 = V_681 -> V_716 . V_628 -> V_303 ;
V_24 = F_31 ( V_13 , V_737 ) ;
if ( V_24 ) {
V_741 = V_24 -> V_24 . V_309 ;
} else {
V_20 = - V_713 ;
goto V_661;
}
if ( V_741 ) {
V_740 = F_318 ( V_744 |
V_745 |
V_746 ) ;
} else {
V_194 -= 2 ;
V_740 = F_318 ( V_744 |
V_747 |
V_746 ) ;
}
V_263 = F_105 ( V_10 -> V_108 . V_717 + V_194 ) ;
if ( ! V_263 ) {
V_20 = - V_183 ;
goto V_661;
}
V_263 -> V_19 = V_19 ;
F_307 ( V_263 , V_10 -> V_108 . V_717 ) ;
V_739 = ( void * ) F_106 ( V_263 , V_194 ) ;
V_739 -> V_707 = V_740 ;
V_739 -> V_748 = 0 ;
memcpy ( V_739 -> V_749 , V_24 -> V_24 . V_158 , V_159 ) ;
memcpy ( V_739 -> V_750 , V_13 -> V_27 . V_158 , V_159 ) ;
memcpy ( V_739 -> V_751 , V_13 -> V_27 . V_158 , V_159 ) ;
V_739 -> V_752 = 0 ;
V_743 = F_303 ( V_263 ) ;
V_743 -> V_6 |= V_704 |
V_703 ;
V_743 -> V_303 = V_303 ;
F_319 ( V_263 , V_753 ) ;
V_263 -> V_754 = 7 ;
if ( V_741 )
V_739 -> V_755 = F_318 ( 7 ) ;
V_689 = F_297 ( V_10 , V_263 , V_89 , V_693 ) ;
if ( F_25 ( V_689 ) ) {
F_302 ( V_263 ) ;
V_20 = F_28 ( V_689 ) ;
goto V_661;
}
F_320 () ;
F_321 ( V_13 , V_24 , V_263 ) ;
F_322 () ;
V_20 = 0 ;
V_661:
F_50 () ;
F_18 ( & V_10 -> V_166 ) ;
return V_20 ;
}
static int F_323 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_163 * V_164 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_678 * V_681 ;
int V_20 = - V_756 ;
F_42 () ;
V_681 = F_43 ( V_13 -> V_27 . V_681 ) ;
if ( V_681 ) {
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
static void F_324 ( struct V_2 * V_2 , bool V_579 )
{
F_325 ( F_2 ( V_2 ) , V_579 ) ;
}
static int F_326 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_757 * V_758 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_759 * V_760 , * V_761 ;
if ( V_758 ) {
V_760 = F_78 ( sizeof( * V_760 ) , V_182 ) ;
if ( ! V_760 )
return - V_183 ;
memcpy ( & V_760 -> V_758 , V_758 , sizeof( * V_758 ) ) ;
} else {
V_760 = NULL ;
}
V_761 = F_77 ( V_13 -> V_758 , V_13 ) ;
F_79 ( V_13 -> V_758 , V_760 ) ;
if ( V_761 )
F_80 ( V_761 , V_189 ) ;
return 0 ;
}
static int F_327 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_163 * V_164 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_195 = 0 ;
V_20 = F_328 ( V_13 , V_164 , & V_195 ) ;
if ( V_20 == 0 )
F_88 ( V_13 , V_195 ) ;
return V_20 ;
}
static int F_329 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_762 , const T_3 * V_737 , T_3 V_763 ,
T_2 V_764 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_765 * V_766 = & V_13 -> V_16 . V_26 ;
int V_512 = V_767 [ V_763 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_349 ;
if ( ! ( V_13 -> V_768 & F_112 ( V_763 ) ) )
return - V_49 ;
if ( V_766 -> V_769 [ V_512 ] . V_764 )
return - V_31 ;
if ( V_764 ) {
V_766 -> V_769 [ V_512 ] . V_764 = 32 * V_764 ;
V_766 -> V_769 [ V_512 ] . V_762 = V_762 ;
V_766 -> V_769 [ V_512 ] . V_763 = V_763 ;
}
return 0 ;
}
static int F_330 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_762 , const T_3 * V_737 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_765 * V_766 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_512 ;
for ( V_512 = 0 ; V_512 < V_308 ; V_512 ++ ) {
struct V_770 * V_769 = & V_766 -> V_769 [ V_512 ] ;
if ( ! V_769 -> V_764 )
continue;
if ( V_769 -> V_762 != V_762 )
continue;
V_769 -> V_763 = - 1 ;
F_331 () ;
F_332 ( V_10 , V_13 , false ) ;
V_769 -> V_708 = V_771 ;
V_769 -> V_772 = false ;
F_333 ( V_13 ) ;
memset ( V_769 , 0 , sizeof( * V_769 ) ) ;
return 0 ;
}
return - V_65 ;
}
