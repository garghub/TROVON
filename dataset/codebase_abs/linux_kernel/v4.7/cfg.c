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
V_8 && V_8 -> V_22 == 0 ) {
F_11 ( V_13 -> V_16 . V_23 . V_24 , NULL ) ;
F_12 ( V_13 ) ;
} else if ( type == V_25 &&
V_8 && V_8 -> V_22 >= 0 ) {
V_13 -> V_16 . V_26 . V_22 = V_8 -> V_22 ;
}
if ( V_13 -> V_27 . type == V_15 && V_6 ) {
struct V_9 * V_10 = V_13 -> V_10 ;
if ( F_13 ( V_13 ) ) {
T_1 V_28 = V_29 |
V_30 ;
if ( ( * V_6 & V_28 ) != ( V_13 -> V_16 . V_17 & V_28 ) )
return - V_31 ;
F_14 ( V_13 , - 1 ) ;
V_13 -> V_16 . V_17 = * V_6 ;
F_14 ( V_13 , 1 ) ;
F_15 ( V_10 ) ;
} else {
V_13 -> V_16 . V_17 = * V_6 ;
}
}
return 0 ;
}
static int F_16 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_20 ;
F_17 ( & V_13 -> V_10 -> V_32 ) ;
V_20 = F_18 ( V_13 , NULL , 0 , 0 ) ;
F_19 ( & V_13 -> V_10 -> V_32 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_20 ( V_11 , true ) ;
}
static void F_21 ( struct V_2 * V_2 ,
struct V_1 * V_11 )
{
F_22 ( F_5 ( V_11 ) ) ;
}
static int F_23 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_2 V_33 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
V_13 -> V_33 = V_33 ;
F_24 ( V_13 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 ,
struct V_37 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 = NULL ;
const struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
int V_14 ;
if ( ! F_13 ( V_13 ) )
return - V_43 ;
switch ( V_8 -> V_44 ) {
case V_45 :
case V_46 :
case V_47 :
if ( F_26 ( V_10 -> V_48 ) )
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
V_40 = F_27 ( V_10 , V_8 -> V_44 , V_13 -> V_27 . type ) ;
break;
}
V_42 = F_28 ( V_8 -> V_44 , V_34 , V_8 -> V_58 ,
V_8 -> V_42 , V_8 -> V_59 , V_8 -> V_60 ,
V_40 ) ;
if ( F_26 ( V_42 ) )
return F_29 ( V_42 ) ;
if ( V_35 )
V_42 -> V_61 . V_6 |= V_62 ;
F_17 ( & V_10 -> V_63 ) ;
if ( V_36 ) {
if ( F_30 ( & V_13 -> V_27 ) )
V_24 = F_31 ( V_13 , V_36 ) ;
else
V_24 = F_32 ( V_13 , V_36 ) ;
if ( ! V_24 || ! F_33 ( V_24 , V_64 ) ) {
F_34 ( V_42 ) ;
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
if ( V_42 -> V_24 && F_33 ( V_42 -> V_24 , V_71 ) )
V_42 -> V_61 . V_6 |= V_69 ;
break;
case V_72 :
break;
case V_73 :
#ifdef F_35
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
F_36 ( 1 ) ;
break;
}
if ( V_24 )
V_24 -> V_84 = V_40 ;
V_14 = F_37 ( V_42 , V_13 , V_24 ) ;
V_66:
F_19 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_38 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
struct V_41 * V_42 = NULL ;
int V_20 ;
F_17 ( & V_10 -> V_63 ) ;
F_17 ( & V_10 -> V_85 ) ;
if ( V_36 ) {
V_20 = - V_65 ;
V_24 = F_32 ( V_13 , V_36 ) ;
if ( ! V_24 )
goto V_66;
if ( V_35 )
V_42 = F_39 ( V_10 , V_24 -> V_86 [ V_34 ] ) ;
else
V_42 = F_39 ( V_10 , V_24 -> V_87 [ V_34 ] ) ;
} else
V_42 = F_39 ( V_10 , V_13 -> V_88 [ V_34 ] ) ;
if ( ! V_42 ) {
V_20 = - V_65 ;
goto V_66;
}
F_40 ( V_42 , true ) ;
V_20 = 0 ;
V_66:
F_19 ( & V_10 -> V_85 ) ;
F_19 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_41 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_34 , bool V_35 , const T_3 * V_36 ,
void * V_89 ,
void (* F_42)( void * V_89 ,
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
F_43 () ;
if ( V_36 ) {
V_24 = F_32 ( V_13 , V_36 ) ;
if ( ! V_24 )
goto V_95;
if ( V_35 && V_34 < V_96 )
V_42 = F_44 ( V_24 -> V_86 [ V_34 ] ) ;
else if ( ! V_35 &&
V_34 < V_96 + V_97 )
V_42 = F_44 ( V_24 -> V_87 [ V_34 ] ) ;
} else
V_42 = F_44 ( V_13 -> V_88 [ V_34 ] ) ;
if ( ! V_42 )
goto V_95;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_44 = V_42 -> V_61 . V_44 ;
switch ( V_42 -> V_61 . V_44 ) {
case V_46 :
V_90 = F_45 ( & V_42 -> V_61 . V_98 ) ;
V_91 = F_46 ( V_90 ) ;
V_92 = F_47 ( V_90 ) ;
if ( V_42 -> V_6 & V_99 &&
! ( V_42 -> V_61 . V_6 & V_100 ) ) {
F_48 ( V_13 -> V_10 , V_42 , & V_94 ) ;
V_91 = V_94 . V_101 . V_91 ;
V_92 = V_94 . V_101 . V_92 ;
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
F_49 ( F_50 ( F_51 ( V_94 ) , V_102 ) !=
F_50 ( F_51 ( V_94 ) , V_103 ) ) ;
case V_54 :
case V_55 :
F_49 ( F_50 ( F_51 ( V_94 ) , V_102 ) !=
F_50 ( F_51 ( V_94 ) , V_104 ) ) ;
case V_56 :
case V_57 :
F_49 ( F_50 ( F_51 ( V_94 ) , V_102 ) !=
F_50 ( F_51 ( V_94 ) , V_105 ) ) ;
if ( V_42 -> V_6 & V_99 &&
! ( V_42 -> V_61 . V_6 & V_100 ) ) {
F_48 ( V_13 -> V_10 , V_42 , & V_94 ) ;
memcpy ( V_60 , V_94 . V_102 . V_106 , 6 ) ;
} else {
V_90 = F_45 ( & V_42 -> V_61 . V_98 ) ;
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
if ( ! ( V_42 -> V_6 & V_99 ) )
break;
if ( F_52 ( V_42 -> V_61 . V_6 & V_100 ) )
break;
F_48 ( V_13 -> V_10 , V_42 , & V_94 ) ;
V_8 . V_60 = V_94 . V_107 . V_60 ;
V_8 . V_59 = V_94 . V_107 . V_59 ;
break;
}
V_8 . V_42 = V_42 -> V_61 . V_42 ;
V_8 . V_58 = V_42 -> V_61 . V_108 ;
F_42 ( V_89 , & V_8 ) ;
V_14 = 0 ;
V_95:
F_53 () ;
return V_14 ;
}
static int F_54 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 , bool V_109 ,
bool V_110 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_55 ( V_13 , V_34 , V_109 , V_110 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_57 ( V_13 , V_34 ) ;
return 0 ;
}
void F_58 ( struct V_38 * V_24 ,
const struct V_111 * V_112 ,
struct V_113 * V_114 )
{
V_114 -> V_6 = 0 ;
if ( V_112 -> V_6 & V_115 ) {
V_114 -> V_6 |= V_116 ;
V_114 -> V_117 = V_112 -> V_118 ;
} else if ( V_112 -> V_6 & V_119 ) {
V_114 -> V_6 |= V_120 ;
V_114 -> V_117 = F_59 ( V_112 ) ;
V_114 -> V_121 = F_60 ( V_112 ) ;
} else {
struct V_122 * V_123 ;
int V_124 = F_61 ( & V_24 -> V_13 -> V_27 ) ;
T_2 V_125 ;
V_123 = V_24 -> V_10 -> V_107 . V_2 -> V_126 [
F_62 ( V_24 -> V_13 ) ] ;
V_125 = V_123 -> V_127 [ V_112 -> V_118 ] . V_128 ;
V_114 -> V_129 = F_63 ( V_125 , 1 << V_124 ) ;
}
if ( V_112 -> V_6 & V_130 )
V_114 -> V_131 = V_132 ;
else if ( V_112 -> V_6 & V_133 )
V_114 -> V_131 = V_134 ;
else if ( V_112 -> V_6 & V_135 )
V_114 -> V_131 = V_136 ;
else
V_114 -> V_131 = V_137 ;
if ( V_112 -> V_6 & V_138 )
V_114 -> V_6 |= V_139 ;
}
static int F_64 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_140 , struct V_141 * V_142 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_17 ( & V_10 -> V_63 ) ;
V_24 = F_65 ( V_13 , V_118 ) ;
if ( V_24 ) {
V_20 = 0 ;
memcpy ( V_140 , V_24 -> V_24 . V_143 , V_144 ) ;
F_66 ( V_24 , V_142 ) ;
}
F_19 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_67 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , struct V_145 * V_146 )
{
struct V_9 * V_10 = F_68 ( V_19 -> V_147 ) ;
return F_69 ( V_10 , V_118 , V_146 ) ;
}
static int F_70 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_140 , struct V_141 * V_142 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_17 ( & V_10 -> V_63 ) ;
V_24 = F_32 ( V_13 , V_140 ) ;
if ( V_24 ) {
V_20 = 0 ;
F_66 ( V_24 , V_142 ) ;
}
F_19 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_71 ( struct V_2 * V_2 ,
struct V_148 * V_149 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
int V_20 = 0 ;
if ( F_72 ( & V_10 -> V_150 , V_149 ) )
return 0 ;
F_17 ( & V_10 -> V_151 ) ;
F_17 ( & V_10 -> V_152 ) ;
if ( V_10 -> V_153 ) {
V_13 = F_73 (
V_10 -> V_154 ,
F_74 ( & V_10 -> V_152 ) ) ;
if ( V_13 ) {
F_75 ( V_13 ) ;
V_20 = F_76 ( V_13 , V_149 ,
V_155 ) ;
}
} else if ( V_10 -> V_156 == V_10 -> V_157 ) {
V_10 -> V_158 = * V_149 ;
F_77 ( V_10 , 0 ) ;
}
if ( V_20 == 0 )
V_10 -> V_150 = * V_149 ;
F_19 ( & V_10 -> V_152 ) ;
F_19 ( & V_10 -> V_151 ) ;
return V_20 ;
}
static int F_78 ( struct V_12 * V_13 ,
const T_3 * V_159 , T_5 V_160 ,
const struct V_161 * V_162 )
{
struct V_163 * V_164 , * V_165 ;
if ( ! V_159 || ! V_160 )
return 1 ;
V_165 = F_79 ( V_13 -> V_16 . V_166 . V_163 , V_13 ) ;
V_164 = F_80 ( sizeof( struct V_163 ) + V_160 , V_167 ) ;
if ( ! V_164 )
return - V_168 ;
V_164 -> V_169 = V_160 ;
memcpy ( V_164 -> V_170 , V_159 , V_160 ) ;
if ( V_162 )
memcpy ( V_164 -> V_171 , V_162 -> V_172 ,
V_162 -> V_173 *
sizeof( V_164 -> V_171 [ 0 ] ) ) ;
F_81 ( V_13 -> V_16 . V_166 . V_163 , V_164 ) ;
if ( V_165 )
F_82 ( V_165 , V_174 ) ;
return 0 ;
}
static int F_83 ( struct V_12 * V_13 ,
struct V_175 * V_8 ,
const struct V_161 * V_162 )
{
struct V_176 * V_164 , * V_165 ;
int V_177 , V_178 ;
int V_179 , V_14 ;
T_1 V_180 = V_181 ;
V_165 = F_79 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( ! V_8 -> V_183 && ! V_165 )
return - V_49 ;
if ( V_8 -> V_183 )
V_177 = V_8 -> V_184 ;
else
V_177 = V_165 -> V_184 ;
if ( V_8 -> V_185 || ! V_165 )
V_178 = V_8 -> V_186 ;
else
V_178 = V_165 -> V_186 ;
V_179 = sizeof( * V_164 ) + V_177 + V_178 ;
V_164 = F_80 ( V_179 , V_167 ) ;
if ( ! V_164 )
return - V_168 ;
V_164 -> V_183 = ( ( T_3 * ) V_164 ) + sizeof( * V_164 ) ;
V_164 -> V_185 = V_164 -> V_183 + V_177 ;
V_164 -> V_184 = V_177 ;
V_164 -> V_186 = V_178 ;
if ( V_162 ) {
V_164 -> V_187 = V_162 -> V_188 ;
memcpy ( V_164 -> V_171 , V_162 -> V_189 ,
V_162 -> V_190 *
sizeof( V_164 -> V_171 [ 0 ] ) ) ;
}
if ( V_8 -> V_183 )
memcpy ( V_164 -> V_183 , V_8 -> V_183 , V_177 ) ;
else
memcpy ( V_164 -> V_183 , V_165 -> V_183 , V_177 ) ;
if ( V_8 -> V_185 )
memcpy ( V_164 -> V_185 , V_8 -> V_185 , V_178 ) ;
else
if ( V_165 )
memcpy ( V_164 -> V_185 , V_165 -> V_185 , V_178 ) ;
V_14 = F_78 ( V_13 , V_8 -> V_163 ,
V_8 -> V_191 , V_162 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
V_180 |= V_192 ;
F_81 ( V_13 -> V_16 . V_166 . V_182 , V_164 ) ;
if ( V_165 )
F_82 ( V_165 , V_174 ) ;
return V_180 ;
}
static int F_84 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_193 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_176 * V_165 ;
struct V_12 * V_23 ;
T_1 V_180 = V_194 |
V_195 |
V_181 |
V_196 |
V_197 |
V_198 ;
int V_14 ;
V_165 = F_79 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( V_165 )
return - V_199 ;
switch ( V_8 -> V_200 ) {
case V_201 :
V_13 -> V_200 = V_202 ;
break;
case V_203 :
V_13 -> V_200 = V_204 ;
break;
case V_205 :
V_13 -> V_200 = V_206 ;
break;
default:
return - V_49 ;
}
V_13 -> V_207 = V_13 -> V_10 -> V_208 ;
F_17 ( & V_10 -> V_151 ) ;
V_14 = F_76 ( V_13 , & V_8 -> V_149 ,
V_209 ) ;
if ( ! V_14 )
F_85 ( V_13 , false ) ;
F_19 ( & V_10 -> V_151 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_210 = V_8 -> V_211 . V_212 ;
V_13 -> V_213 = V_8 -> V_211 . V_213 ;
V_13 -> V_214 = F_86 ( V_13 -> V_10 ,
& V_8 -> V_211 ,
V_13 -> V_27 . type ) ;
F_87 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_23 -> V_210 =
V_8 -> V_211 . V_212 ;
V_23 -> V_213 =
V_8 -> V_211 . V_213 ;
V_23 -> V_214 =
F_86 ( V_13 -> V_10 ,
& V_8 -> V_211 ,
V_23 -> V_27 . type ) ;
}
V_13 -> V_27 . V_215 . V_216 = V_8 -> V_217 ;
V_13 -> V_27 . V_215 . V_218 = V_8 -> V_218 ;
V_13 -> V_27 . V_215 . V_219 = true ;
V_13 -> V_27 . V_215 . V_220 = V_13 -> V_27 . V_221 ;
V_13 -> V_27 . V_215 . V_222 = V_8 -> V_222 ;
if ( V_8 -> V_222 )
memcpy ( V_13 -> V_27 . V_215 . V_223 , V_8 -> V_223 ,
V_8 -> V_222 ) ;
V_13 -> V_27 . V_215 . V_224 =
( V_8 -> V_224 != V_225 ) ;
memset ( & V_13 -> V_27 . V_215 . V_226 , 0 ,
sizeof( V_13 -> V_27 . V_215 . V_226 ) ) ;
V_13 -> V_27 . V_215 . V_226 . V_227 =
V_8 -> V_228 & V_229 ;
if ( V_8 -> V_230 )
V_13 -> V_27 . V_215 . V_226 . V_227 |=
V_231 ;
V_14 = F_83 ( V_13 , & V_8 -> V_182 , NULL ) ;
if ( V_14 < 0 ) {
F_75 ( V_13 ) ;
return V_14 ;
}
V_180 |= V_14 ;
V_14 = F_88 ( V_13 -> V_10 , V_13 ) ;
if ( V_14 ) {
V_165 = F_79 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( V_165 )
F_82 ( V_165 , V_174 ) ;
F_11 ( V_13 -> V_16 . V_166 . V_182 , NULL ) ;
F_75 ( V_13 ) ;
return V_14 ;
}
F_89 ( V_10 , V_13 ) ;
F_90 ( V_13 , V_180 ) ;
F_91 ( V_19 ) ;
F_87 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_91 ( V_23 -> V_19 ) ;
return 0 ;
}
static int F_92 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_175 * V_8 )
{
struct V_12 * V_13 ;
struct V_176 * V_165 ;
int V_14 ;
V_13 = F_9 ( V_19 ) ;
F_93 ( V_13 ) ;
if ( V_13 -> V_27 . V_232 )
return - V_31 ;
V_165 = F_79 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( ! V_165 )
return - V_65 ;
V_14 = F_83 ( V_13 , V_8 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
F_90 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_12 * V_23 ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_176 * V_233 ;
struct V_163 * V_234 ;
struct V_148 V_149 ;
F_93 ( V_13 ) ;
V_233 = F_79 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( ! V_233 )
return - V_65 ;
V_234 = F_79 ( V_13 -> V_16 . V_166 . V_163 , V_13 ) ;
F_17 ( & V_10 -> V_151 ) ;
V_13 -> V_27 . V_232 = false ;
if ( V_13 -> V_235 ) {
F_95 ( V_10 , V_13 ,
V_236 ) ;
V_13 -> V_235 = false ;
}
F_19 ( & V_10 -> V_151 ) ;
F_96 ( V_13 -> V_16 . V_166 . V_237 ) ;
V_13 -> V_16 . V_166 . V_237 = NULL ;
F_87 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_97 ( V_23 -> V_19 ) ;
F_97 ( V_19 ) ;
F_11 ( V_13 -> V_16 . V_166 . V_182 , NULL ) ;
F_11 ( V_13 -> V_16 . V_166 . V_163 , NULL ) ;
F_82 ( V_233 , V_174 ) ;
if ( V_234 )
F_82 ( V_234 , V_174 ) ;
V_13 -> V_16 . V_166 . V_238 = V_202 ;
F_98 ( V_13 , true ) ;
F_99 ( V_13 , true ) ;
V_13 -> V_27 . V_215 . V_219 = false ;
V_13 -> V_27 . V_215 . V_222 = 0 ;
F_100 ( V_239 , & V_13 -> V_240 ) ;
F_90 ( V_13 , V_195 ) ;
if ( V_13 -> V_11 . V_241 ) {
V_149 = V_13 -> V_27 . V_215 . V_149 ;
F_101 ( & V_13 -> V_242 ) ;
F_102 ( V_13 -> V_19 , & V_149 ,
V_243 ,
V_167 ) ;
}
F_103 ( V_13 -> V_10 , V_13 ) ;
V_10 -> V_244 -= F_104 ( & V_13 -> V_16 . V_166 . V_245 . V_246 ) ;
F_105 ( & V_13 -> V_16 . V_166 . V_245 . V_246 ) ;
F_17 ( & V_10 -> V_151 ) ;
F_85 ( V_13 , true ) ;
F_75 ( V_13 ) ;
F_19 ( & V_10 -> V_151 ) ;
return 0 ;
}
static void F_106 ( struct V_38 * V_24 )
{
struct V_247 * V_248 ;
struct V_249 * V_250 ;
V_250 = F_107 ( sizeof( * V_248 ) ) ;
if ( ! V_250 )
return;
V_248 = (struct V_247 * ) F_108 ( V_250 , sizeof( * V_248 ) ) ;
F_109 ( V_248 -> V_251 ) ;
memcpy ( V_248 -> V_252 , V_24 -> V_24 . V_143 , V_144 ) ;
V_248 -> V_169 = F_110 ( 6 ) ;
V_248 -> V_253 = 0 ;
V_248 -> V_254 = 0x01 ;
V_248 -> V_255 = 0xaf ;
V_248 -> V_256 [ 0 ] = 0x81 ;
V_248 -> V_256 [ 1 ] = 1 ;
V_248 -> V_256 [ 2 ] = 0 ;
V_250 -> V_19 = V_24 -> V_13 -> V_19 ;
V_250 -> V_257 = F_111 ( V_250 , V_24 -> V_13 -> V_19 ) ;
memset ( V_250 -> V_258 , 0 , sizeof( V_250 -> V_258 ) ) ;
F_112 ( V_250 ) ;
}
static int F_113 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
T_1 V_28 , T_1 V_259 )
{
int V_20 ;
if ( V_28 & F_114 ( V_260 ) &&
V_259 & F_114 ( V_260 ) &&
! F_33 ( V_24 , V_261 ) ) {
V_20 = F_115 ( V_24 , V_262 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_114 ( V_263 ) &&
V_259 & F_114 ( V_263 ) &&
! F_33 ( V_24 , V_64 ) ) {
if ( ! F_33 ( V_24 , V_264 ) )
F_116 ( V_24 ) ;
V_20 = F_115 ( V_24 , V_265 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_114 ( V_266 ) ) {
if ( V_259 & F_114 ( V_266 ) )
V_20 = F_115 ( V_24 , V_267 ) ;
else if ( F_33 ( V_24 , V_268 ) )
V_20 = F_115 ( V_24 , V_265 ) ;
else
V_20 = 0 ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_114 ( V_263 ) &&
! ( V_259 & F_114 ( V_263 ) ) &&
F_33 ( V_24 , V_64 ) ) {
V_20 = F_115 ( V_24 , V_262 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_114 ( V_260 ) &&
! ( V_259 & F_114 ( V_260 ) ) &&
F_33 ( V_24 , V_261 ) ) {
V_20 = F_115 ( V_24 , V_269 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static void F_117 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_270 * V_8 )
{
#ifdef F_35
struct V_12 * V_13 = V_24 -> V_13 ;
T_1 V_180 = 0 ;
if ( V_8 -> V_271 & V_272 ) {
switch ( V_8 -> V_273 ) {
case V_274 :
if ( V_24 -> V_74 -> V_273 != V_274 )
V_180 = F_118 ( V_13 ) ;
V_24 -> V_74 -> V_273 = V_8 -> V_273 ;
F_119 ( V_24 ) ;
V_180 |= F_120 ( V_24 ,
V_13 -> V_16 . V_74 . V_275 . V_276 ) ;
break;
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
if ( V_24 -> V_74 -> V_273 == V_274 )
V_180 = F_121 ( V_13 ) ;
V_24 -> V_74 -> V_273 = V_8 -> V_273 ;
F_119 ( V_24 ) ;
V_180 |= F_120 ( V_24 ,
V_283 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_284 ) {
case V_285 :
break;
case V_286 :
V_180 |= F_122 ( V_24 ) ;
break;
case V_287 :
V_180 |= F_123 ( V_24 ) ;
break;
}
if ( V_8 -> V_288 )
V_180 |= F_120 ( V_24 ,
V_8 -> V_288 ) ;
F_124 ( V_13 , V_180 ) ;
#endif
}
static int F_125 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_270 * V_8 )
{
int V_20 = 0 ;
struct V_122 * V_123 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_289 V_290 = F_62 ( V_13 ) ;
T_1 V_28 , V_259 ;
V_123 = V_10 -> V_107 . V_2 -> V_126 [ V_290 ] ;
V_28 = V_8 -> V_291 ;
V_259 = V_8 -> V_292 ;
if ( F_30 ( & V_13 -> V_27 ) ) {
if ( V_28 & F_114 ( V_260 ) )
V_28 |= F_114 ( V_263 ) ;
if ( V_259 & F_114 ( V_260 ) )
V_259 |= F_114 ( V_263 ) ;
} else if ( F_33 ( V_24 , V_293 ) ) {
if ( V_259 & F_114 ( V_266 ) ) {
V_259 |= F_114 ( V_260 ) |
F_114 ( V_263 ) ;
V_28 |= F_114 ( V_260 ) |
F_114 ( V_263 ) ;
}
}
if ( V_28 & F_114 ( V_294 ) &&
V_10 -> V_107 . V_295 >= V_296 )
V_24 -> V_24 . V_297 = V_259 & F_114 ( V_294 ) ;
if ( ! F_33 ( V_24 , V_293 ) &&
! ( ( V_28 & F_114 ( V_263 ) ) &&
( V_259 & F_114 ( V_263 ) ) ) ) {
V_20 = F_113 ( V_10 , V_24 , V_28 , V_259 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_114 ( V_298 ) ) {
if ( V_259 & F_114 ( V_298 ) )
F_126 ( V_24 , V_299 ) ;
else
F_127 ( V_24 , V_299 ) ;
}
if ( V_28 & F_114 ( V_300 ) ) {
V_24 -> V_24 . V_67 = ! ! ( V_259 & F_114 ( V_300 ) ) ;
if ( V_259 & F_114 ( V_300 ) )
F_126 ( V_24 , V_71 ) ;
else
F_127 ( V_24 , V_71 ) ;
}
if ( V_28 & F_114 ( V_301 ) ) {
if ( V_259 & F_114 ( V_301 ) )
F_126 ( V_24 , V_293 ) ;
else
F_127 ( V_24 , V_293 ) ;
}
if ( F_33 ( V_24 , V_293 ) &&
! V_13 -> V_16 . V_26 . V_302 &&
V_8 -> V_303 >= 4 &&
V_8 -> V_304 [ 3 ] & V_305 )
F_126 ( V_24 , V_306 ) ;
if ( F_33 ( V_24 , V_293 ) &&
! V_13 -> V_16 . V_26 . V_307 &&
F_128 ( & V_10 -> V_107 , V_308 ) &&
V_8 -> V_303 >= 8 &&
V_8 -> V_304 [ 7 ] & V_309 )
F_126 ( V_24 , V_310 ) ;
if ( V_8 -> V_271 & V_311 ) {
V_24 -> V_24 . V_312 = V_8 -> V_312 ;
V_24 -> V_24 . V_313 = V_8 -> V_313 ;
}
if ( V_8 -> V_303 >= 8 ) {
T_3 V_314 = ( V_8 -> V_304 [ 7 ] &
V_315 ) >> 7 ;
if ( V_8 -> V_303 >= 9 ) {
T_3 V_316 = V_8 -> V_304 [ 8 ] &
V_317 ;
V_316 <<= 1 ;
V_314 |= V_316 ;
}
switch ( V_314 ) {
case 1 :
V_24 -> V_24 . V_318 = 32 ;
break;
case 2 :
V_24 -> V_24 . V_318 = 16 ;
break;
case 3 :
V_24 -> V_24 . V_318 = 8 ;
break;
default:
V_24 -> V_24 . V_318 = 0 ;
}
}
if ( V_8 -> V_319 )
V_24 -> V_24 . V_319 = V_8 -> V_319 ;
if ( V_8 -> V_320 >= 0 )
V_24 -> V_320 = V_8 -> V_320 ;
if ( V_8 -> V_321 ) {
F_129 ( & V_13 -> V_27 . V_215 . V_149 ,
V_123 , V_8 -> V_321 ,
V_8 -> V_322 ,
& V_24 -> V_24 . V_323 [ V_290 ] ) ;
}
if ( V_8 -> V_324 )
F_130 ( V_13 , V_123 ,
V_8 -> V_324 , V_24 ) ;
if ( V_8 -> V_325 )
F_131 ( V_13 , V_123 ,
V_8 -> V_325 , V_24 ) ;
if ( V_8 -> V_326 ) {
F_132 ( V_13 , V_24 ,
V_8 -> V_327 , V_290 ) ;
}
if ( V_8 -> V_328 >= 0 )
V_24 -> V_24 . V_328 = V_8 -> V_328 ;
if ( F_30 ( & V_13 -> V_27 ) )
F_117 ( V_10 , V_24 , V_8 ) ;
if ( F_33 ( V_24 , V_293 ) ||
V_259 & F_114 ( V_263 ) ) {
V_20 = F_113 ( V_10 , V_24 , V_28 , V_259 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_133 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_140 ,
struct V_270 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_13 ;
int V_14 ;
int V_329 ;
if ( V_8 -> V_23 ) {
V_13 = F_9 ( V_8 -> V_23 ) ;
if ( V_13 -> V_27 . type != V_21 &&
V_13 -> V_27 . type != V_70 )
return - V_49 ;
} else
V_13 = F_9 ( V_19 ) ;
if ( F_134 ( V_140 , V_13 -> V_27 . V_143 ) )
return - V_49 ;
if ( F_135 ( V_140 ) )
return - V_49 ;
V_24 = F_136 ( V_13 , V_140 , V_167 ) ;
if ( ! V_24 )
return - V_168 ;
if ( V_8 -> V_292 & F_114 ( V_301 ) )
V_24 -> V_24 . V_330 = true ;
V_14 = F_125 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_137 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_33 ( V_24 , V_293 ) &&
F_33 ( V_24 , V_64 ) )
F_116 ( V_24 ) ;
V_329 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_138 ( V_24 ) ;
if ( V_14 ) {
F_53 () ;
return V_14 ;
}
if ( V_329 )
F_106 ( V_24 ) ;
F_53 () ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_331 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_140 )
return F_140 ( V_13 , V_8 -> V_140 ) ;
F_141 ( V_13 ) ;
return 0 ;
}
static int F_142 ( struct V_2 * V_2 ,
struct V_18 * V_19 , const T_3 * V_140 ,
struct V_270 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_332 ;
enum V_333 V_334 ;
int V_14 ;
F_17 ( & V_10 -> V_63 ) ;
V_24 = F_32 ( V_13 , V_140 ) ;
if ( ! V_24 ) {
V_14 = - V_65 ;
goto V_335;
}
switch ( V_13 -> V_27 . type ) {
case V_73 :
if ( V_13 -> V_16 . V_74 . V_336 )
V_334 = V_337 ;
else
V_334 = V_338 ;
break;
case V_72 :
V_334 = V_339 ;
break;
case V_25 :
if ( ! F_33 ( V_24 , V_293 ) ) {
V_334 = V_340 ;
break;
}
if ( F_33 ( V_24 , V_268 ) )
V_334 = V_341 ;
else
V_334 = V_342 ;
break;
case V_70 :
case V_21 :
if ( F_33 ( V_24 , V_64 ) )
V_334 = V_343 ;
else
V_334 = V_344 ;
break;
default:
V_14 = - V_345 ;
goto V_335;
}
V_14 = F_143 ( V_2 , V_8 , V_334 ) ;
if ( V_14 )
goto V_335;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_346 = false ;
bool V_347 = false ;
V_332 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_147 -> V_22 ) {
if ( V_332 -> V_16 . V_23 . V_24 ) {
V_14 = - V_31 ;
goto V_335;
}
F_81 ( V_332 -> V_16 . V_23 . V_24 , V_24 ) ;
V_347 = true ;
F_144 ( V_332 ) ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_346 = true ;
}
V_24 -> V_13 = V_332 ;
F_145 ( V_24 ) ;
if ( V_24 -> V_348 == V_267 &&
V_346 != V_347 ) {
if ( V_347 )
F_146 ( & V_24 -> V_13 -> V_349 -> V_350 ) ;
else
F_147 ( & V_24 -> V_13 -> V_349 -> V_350 ) ;
}
F_106 ( V_24 ) ;
}
V_14 = F_125 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_335;
F_19 ( & V_10 -> V_63 ) ;
if ( ( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_351 != V_24 -> V_13 -> V_349 -> V_352 &&
F_33 ( V_24 , V_268 ) &&
F_148 ( V_24 ) != 1 ) {
F_149 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_143 ) ;
F_150 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_349 -> V_352 ,
V_24 -> V_24 . V_143 ,
V_24 -> V_13 -> V_27 . V_215 . V_353 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_291 & F_114 ( V_266 ) ) {
F_151 ( V_10 ) ;
F_152 ( V_13 ) ;
}
return 0 ;
V_335:
F_19 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_153 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_354 , const T_3 * V_355 )
{
struct V_12 * V_13 ;
struct V_356 * V_357 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_24 = F_31 ( V_13 , V_355 ) ;
if ( ! V_24 ) {
F_53 () ;
return - V_65 ;
}
V_357 = F_154 ( V_13 , V_354 ) ;
if ( F_26 ( V_357 ) ) {
F_53 () ;
return F_29 ( V_357 ) ;
}
F_155 ( V_357 , V_24 ) ;
F_53 () ;
return 0 ;
}
static int F_156 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_354 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_354 )
return F_157 ( V_13 , V_354 ) ;
F_158 ( V_13 ) ;
return 0 ;
}
static int F_159 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_354 , const T_3 * V_355 )
{
struct V_12 * V_13 ;
struct V_356 * V_357 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_24 = F_31 ( V_13 , V_355 ) ;
if ( ! V_24 ) {
F_53 () ;
return - V_65 ;
}
V_357 = F_160 ( V_13 , V_354 ) ;
if ( ! V_357 ) {
F_53 () ;
return - V_65 ;
}
F_155 ( V_357 , V_24 ) ;
F_53 () ;
return 0 ;
}
static void F_161 ( struct V_356 * V_357 , T_3 * V_355 ,
struct V_358 * V_359 )
{
struct V_38 * V_360 = F_44 ( V_357 -> V_355 ) ;
if ( V_360 )
memcpy ( V_355 , V_360 -> V_24 . V_143 , V_144 ) ;
else
F_162 ( V_355 ) ;
memset ( V_359 , 0 , sizeof( * V_359 ) ) ;
V_359 -> V_361 = V_357 -> V_13 -> V_16 . V_74 . V_362 ;
V_359 -> V_363 = V_364 |
V_365 |
V_366 |
V_367 |
V_368 |
V_369 |
V_370 ;
V_359 -> V_371 = V_357 -> V_372 . V_373 ;
V_359 -> V_374 = V_357 -> V_374 ;
V_359 -> V_375 = V_357 -> V_375 ;
if ( F_163 ( V_376 , V_357 -> V_377 ) )
V_359 -> V_378 = F_164 ( V_357 -> V_377 - V_376 ) ;
V_359 -> V_379 =
F_164 ( V_357 -> V_379 ) ;
V_359 -> V_380 = V_357 -> V_380 ;
if ( V_357 -> V_6 & V_381 )
V_359 -> V_6 |= V_382 ;
if ( V_357 -> V_6 & V_383 )
V_359 -> V_6 |= V_384 ;
if ( V_357 -> V_6 & V_385 )
V_359 -> V_6 |= V_386 ;
if ( V_357 -> V_6 & V_387 )
V_359 -> V_6 |= V_388 ;
if ( V_357 -> V_6 & V_389 )
V_359 -> V_6 |= V_390 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_354 , T_3 * V_355 , struct V_358 * V_359 )
{
struct V_12 * V_13 ;
struct V_356 * V_357 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_357 = F_160 ( V_13 , V_354 ) ;
if ( ! V_357 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_354 , V_357 -> V_354 , V_144 ) ;
F_161 ( V_357 , V_355 , V_359 ) ;
F_53 () ;
return 0 ;
}
static int F_166 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_354 , T_3 * V_355 ,
struct V_358 * V_359 )
{
struct V_12 * V_13 ;
struct V_356 * V_357 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_357 = F_167 ( V_13 , V_118 ) ;
if ( ! V_357 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_354 , V_357 -> V_354 , V_144 ) ;
F_161 ( V_357 , V_355 , V_359 ) ;
F_53 () ;
return 0 ;
}
static void F_168 ( struct V_356 * V_357 , T_3 * V_391 ,
struct V_358 * V_359 )
{
memset ( V_359 , 0 , sizeof( * V_359 ) ) ;
memcpy ( V_391 , V_357 -> V_391 , V_144 ) ;
V_359 -> V_361 = V_357 -> V_13 -> V_16 . V_74 . V_392 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_354 , T_3 * V_391 , struct V_358 * V_359 )
{
struct V_12 * V_13 ;
struct V_356 * V_357 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_357 = F_170 ( V_13 , V_354 ) ;
if ( ! V_357 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_354 , V_357 -> V_354 , V_144 ) ;
F_168 ( V_357 , V_391 , V_359 ) ;
F_53 () ;
return 0 ;
}
static int F_171 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_354 , T_3 * V_391 ,
struct V_358 * V_359 )
{
struct V_12 * V_13 ;
struct V_356 * V_357 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_357 = F_172 ( V_13 , V_118 ) ;
if ( ! V_357 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_354 , V_357 -> V_354 , V_144 ) ;
F_168 ( V_357 , V_391 , V_359 ) ;
F_53 () ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_393 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_275 ) , sizeof( struct V_393 ) ) ;
return 0 ;
}
static inline bool F_174 ( enum V_394 V_395 , T_1 V_28 )
{
return ( V_28 >> ( V_395 - 1 ) ) & 0x1 ;
}
static int F_175 ( struct V_396 * V_397 ,
const struct V_398 * V_399 )
{
T_3 * V_400 ;
const T_3 * V_401 ;
struct V_12 * V_13 = F_176 ( V_397 ,
struct V_12 , V_16 . V_74 ) ;
V_400 = NULL ;
V_401 = V_397 -> V_402 ;
if ( V_399 -> V_403 ) {
V_400 = F_177 ( V_399 -> V_402 , V_399 -> V_403 ,
V_167 ) ;
if ( ! V_400 )
return - V_168 ;
}
V_397 -> V_403 = V_399 -> V_403 ;
V_397 -> V_402 = V_400 ;
F_96 ( V_401 ) ;
V_397 -> V_404 = V_399 -> V_404 ;
memcpy ( V_397 -> V_405 , V_399 -> V_405 , V_397 -> V_404 ) ;
V_397 -> V_406 = V_399 -> V_407 ;
V_397 -> V_408 = V_399 -> V_409 ;
V_397 -> V_410 = V_399 -> V_411 ;
V_397 -> V_336 = V_399 -> V_336 ;
V_397 -> V_412 = V_399 -> V_413 ;
V_397 -> V_75 = V_76 ;
if ( V_399 -> V_414 )
V_397 -> V_75 |= V_415 ;
if ( V_399 -> V_416 )
V_397 -> V_75 |= V_417 ;
memcpy ( V_13 -> V_27 . V_215 . V_418 , V_399 -> V_418 ,
sizeof( V_399 -> V_418 ) ) ;
V_13 -> V_27 . V_215 . V_419 = V_399 -> V_419 ;
V_13 -> V_27 . V_215 . V_216 = V_399 -> V_217 ;
V_13 -> V_27 . V_215 . V_218 = V_399 -> V_218 ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_393 * V_420 )
{
struct V_393 * V_61 ;
struct V_12 * V_13 ;
struct V_396 * V_397 ;
V_13 = F_9 ( V_19 ) ;
V_397 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_275 ) ;
if ( F_174 ( V_421 , V_28 ) )
V_61 -> V_422 = V_420 -> V_422 ;
if ( F_174 ( V_423 , V_28 ) )
V_61 -> V_424 = V_420 -> V_424 ;
if ( F_174 ( V_425 , V_28 ) )
V_61 -> V_426 = V_420 -> V_426 ;
if ( F_174 ( V_427 , V_28 ) )
V_61 -> V_428 = V_420 -> V_428 ;
if ( F_174 ( V_429 , V_28 ) )
V_61 -> V_430 = V_420 -> V_430 ;
if ( F_174 ( V_431 , V_28 ) )
V_61 -> V_432 = V_420 -> V_432 ;
if ( F_174 ( V_433 , V_28 ) )
V_61 -> V_434 = V_420 -> V_434 ;
if ( F_174 ( V_435 , V_28 ) ) {
if ( V_397 -> V_336 )
return - V_31 ;
V_61 -> V_436 = V_420 -> V_436 ;
}
if ( F_174 ( V_437 , V_28 ) )
V_61 -> V_438 =
V_420 -> V_438 ;
if ( F_174 ( V_439 , V_28 ) )
V_61 -> V_440 =
V_420 -> V_440 ;
if ( F_174 ( V_441 , V_28 ) )
V_61 -> V_442 = V_420 -> V_442 ;
if ( F_174 ( V_443 , V_28 ) )
V_61 -> V_444 = V_420 -> V_444 ;
if ( F_174 ( V_445 , V_28 ) )
V_61 -> V_446 =
V_420 -> V_446 ;
if ( F_174 ( V_447 , V_28 ) )
V_61 -> V_448 =
V_420 -> V_448 ;
if ( F_174 ( V_449 , V_28 ) )
V_61 -> V_450 =
V_420 -> V_450 ;
if ( F_174 ( V_451 ,
V_28 ) )
V_61 -> V_452 =
V_420 -> V_452 ;
if ( F_174 ( V_453 , V_28 ) ) {
V_61 -> V_454 = V_420 -> V_454 ;
F_179 ( V_397 ) ;
}
if ( F_174 ( V_455 , V_28 ) ) {
if ( V_420 -> V_456 &&
! ( V_61 -> V_454 > V_457 ) ) {
V_61 -> V_454 = V_458 ;
F_179 ( V_397 ) ;
}
V_61 -> V_456 =
V_420 -> V_456 ;
}
if ( F_174 ( V_459 , V_28 ) )
V_61 -> V_460 =
V_420 -> V_460 ;
if ( F_174 ( V_461 , V_28 ) )
V_61 -> V_462 = V_420 -> V_462 ;
if ( F_174 ( V_463 , V_28 ) ) {
if ( ! F_128 ( & V_13 -> V_10 -> V_107 , V_464 ) )
return - V_465 ;
V_61 -> V_466 = V_420 -> V_466 ;
}
if ( F_174 ( V_467 , V_28 ) ) {
V_61 -> V_468 = V_420 -> V_468 ;
V_13 -> V_27 . V_215 . V_469 = V_420 -> V_468 ;
F_90 ( V_13 , V_470 ) ;
}
if ( F_174 ( V_471 , V_28 ) )
V_61 -> V_472 =
V_420 -> V_472 ;
if ( F_174 ( V_473 , V_28 ) )
V_61 -> V_474 =
V_420 -> V_474 ;
if ( F_174 ( V_475 , V_28 ) )
V_61 -> V_476 =
V_420 -> V_476 ;
if ( F_174 ( V_477 , V_28 ) ) {
V_61 -> V_276 = V_420 -> V_276 ;
F_180 ( V_13 ) ;
}
if ( F_174 ( V_478 , V_28 ) )
V_61 -> V_479 =
V_420 -> V_479 ;
if ( F_174 ( V_480 , V_28 ) )
V_61 -> V_481 = V_420 -> V_481 ;
F_124 ( V_13 , V_181 ) ;
return 0 ;
}
static int F_181 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_393 * V_61 ,
const struct V_398 * V_399 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_396 * V_397 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_397 -> V_275 , V_61 , sizeof( struct V_393 ) ) ;
V_14 = F_175 ( V_397 , V_399 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_200 = V_202 ;
V_13 -> V_207 = V_13 -> V_10 -> V_208 ;
F_17 ( & V_13 -> V_10 -> V_151 ) ;
V_14 = F_76 ( V_13 , & V_399 -> V_149 ,
V_209 ) ;
F_19 ( & V_13 -> V_10 -> V_151 ) ;
if ( V_14 )
return V_14 ;
return F_182 ( V_13 ) ;
}
static int F_183 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_184 ( V_13 ) ;
F_17 ( & V_13 -> V_10 -> V_151 ) ;
F_75 ( V_13 ) ;
F_19 ( & V_13 -> V_10 -> V_151 ) ;
return 0 ;
}
static int F_185 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_482 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_289 V_290 ;
T_1 V_180 = 0 ;
if ( ! F_79 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) )
return - V_65 ;
V_290 = F_62 ( V_13 ) ;
if ( V_8 -> V_483 >= 0 ) {
V_13 -> V_27 . V_215 . V_483 = V_8 -> V_483 ;
V_180 |= V_484 ;
}
if ( V_8 -> V_485 >= 0 ) {
V_13 -> V_27 . V_215 . V_485 =
V_8 -> V_485 ;
V_180 |= V_486 ;
}
if ( ! V_13 -> V_27 . V_215 . V_487 &&
V_290 == V_488 ) {
V_13 -> V_27 . V_215 . V_487 = true ;
V_180 |= V_489 ;
}
if ( V_8 -> V_490 >= 0 ) {
V_13 -> V_27 . V_215 . V_487 =
V_8 -> V_490 ;
V_180 |= V_489 ;
}
if ( V_8 -> V_419 ) {
F_129 ( & V_13 -> V_27 . V_215 . V_149 ,
V_2 -> V_126 [ V_290 ] ,
V_8 -> V_419 ,
V_8 -> V_491 ,
& V_13 -> V_27 . V_215 . V_419 ) ;
V_180 |= V_492 ;
}
if ( V_8 -> V_493 >= 0 ) {
if ( V_8 -> V_493 )
V_13 -> V_6 |= V_494 ;
else
V_13 -> V_6 &= ~ V_494 ;
F_12 ( V_13 ) ;
}
if ( V_8 -> V_468 >= 0 ) {
V_13 -> V_27 . V_215 . V_469 =
( T_2 ) V_8 -> V_468 ;
V_180 |= V_470 ;
}
if ( V_8 -> V_228 >= 0 ) {
V_13 -> V_27 . V_215 . V_226 . V_227 &=
~ V_229 ;
V_13 -> V_27 . V_215 . V_226 . V_227 |=
V_8 -> V_228 & V_229 ;
V_180 |= V_197 ;
}
if ( V_8 -> V_230 > 0 ) {
V_13 -> V_27 . V_215 . V_226 . V_227 |=
V_231 ;
V_180 |= V_197 ;
} else if ( V_8 -> V_230 == 0 ) {
V_13 -> V_27 . V_215 . V_226 . V_227 &=
~ V_231 ;
V_180 |= V_197 ;
}
F_90 ( V_13 , V_180 ) ;
return 0 ;
}
static int F_186 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_495 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_496 V_497 ;
if ( ! V_10 -> V_498 -> V_499 )
return - V_345 ;
if ( V_10 -> V_107 . V_295 < V_296 )
return - V_345 ;
memset ( & V_497 , 0 , sizeof( V_497 ) ) ;
V_497 . V_500 = V_8 -> V_500 ;
V_497 . V_501 = V_8 -> V_502 ;
V_497 . V_503 = V_8 -> V_504 ;
V_497 . V_505 = V_8 -> V_505 ;
V_497 . V_506 = false ;
V_13 -> V_507 [ V_8 -> V_508 ] = V_497 ;
if ( F_187 ( V_10 , V_13 , V_8 -> V_508 , & V_497 ) ) {
F_188 ( V_10 -> V_107 . V_2 ,
L_2 ,
V_8 -> V_508 ) ;
return - V_49 ;
}
F_90 ( V_13 , V_509 ) ;
return 0 ;
}
static int F_189 ( struct V_2 * V_2 ,
struct V_510 * V_511 )
{
return F_190 ( F_2 ( V_2 ) , V_511 ) ;
}
static int F_191 ( struct V_2 * V_2 )
{
return F_192 ( F_2 ( V_2 ) ) ;
}
static int F_193 ( struct V_2 * V_2 ,
struct V_512 * V_513 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_513 -> V_11 ) ;
switch ( F_194 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_72 :
case V_73 :
case V_81 :
case V_78 :
break;
case V_82 :
if ( V_13 -> V_10 -> V_498 -> V_514 )
break;
case V_70 :
if ( V_13 -> V_16 . V_166 . V_182 &&
( ! ( V_2 -> V_515 & V_516 ) ||
! ( V_513 -> V_6 & V_517 ) ) )
return - V_345 ;
break;
default:
return - V_345 ;
}
return F_195 ( V_13 , V_513 ) ;
}
static void F_196 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_197 ( F_2 ( V_2 ) ) ;
}
static int
F_198 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_518 * V_513 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_498 -> V_519 )
return - V_345 ;
return F_199 ( V_13 , V_513 ) ;
}
static int
F_200 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_498 -> V_520 )
return - V_345 ;
return F_201 ( V_10 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_521 * V_513 )
{
return F_203 ( F_9 ( V_19 ) , V_513 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_522 * V_513 )
{
return F_205 ( F_9 ( V_19 ) , V_513 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_523 * V_513 )
{
return F_207 ( F_9 ( V_19 ) , V_513 ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_524 * V_513 )
{
return F_209 ( F_9 ( V_19 ) , V_513 ) ;
}
static int F_210 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_525 * V_8 )
{
return F_211 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_212 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_213 ( F_9 ( V_19 ) ) ;
}
static int F_214 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_526 * V_399 )
{
return F_215 ( F_9 ( V_19 ) , V_399 ) ;
}
static int F_216 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_217 ( F_9 ( V_19 ) ) ;
}
static int F_218 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_112 [ V_527 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_215 . V_418 , V_112 ,
sizeof( int ) * V_527 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 , T_1 V_180 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_180 & V_528 ) {
F_220 ( V_10 ) ;
V_14 = F_221 ( V_10 , V_2 -> V_529 ) ;
if ( V_14 ) {
F_220 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_180 & V_530 ) ||
( V_180 & V_531 ) ) {
T_6 V_532 ;
V_532 = V_180 & V_530 ?
V_2 -> V_532 : - 1 ;
V_14 = F_222 ( V_10 , V_532 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_180 & V_533 ) {
V_14 = F_223 ( V_10 , V_2 -> V_534 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_180 & V_535 ) {
if ( V_2 -> V_536 > V_537 )
return - V_49 ;
V_10 -> V_107 . V_61 . V_538 = V_2 -> V_536 ;
}
if ( V_180 & V_539 ) {
if ( V_2 -> V_540 > V_537 )
return - V_49 ;
V_10 -> V_107 . V_61 . V_541 = V_2 -> V_540 ;
}
if ( V_180 &
( V_535 | V_539 ) )
F_77 ( V_10 , V_542 ) ;
return 0 ;
}
static int F_224 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_543 type , int V_544 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_543 V_545 = type ;
bool V_546 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_547 :
V_13 -> V_548 = V_549 ;
V_545 = V_550 ;
break;
case V_550 :
case V_551 :
if ( V_544 < 0 || ( V_544 % 100 ) )
return - V_345 ;
V_13 -> V_548 = F_225 ( V_544 ) ;
break;
}
if ( V_545 != V_13 -> V_27 . V_215 . V_552 ) {
V_546 = true ;
V_13 -> V_27 . V_215 . V_552 = V_545 ;
}
F_226 ( V_13 , V_546 ) ;
return 0 ;
}
switch ( type ) {
case V_547 :
V_10 -> V_548 = V_549 ;
V_545 = V_550 ;
break;
case V_550 :
case V_551 :
if ( V_544 < 0 || ( V_544 % 100 ) )
return - V_345 ;
V_10 -> V_548 = F_225 ( V_544 ) ;
break;
}
F_17 ( & V_10 -> V_152 ) ;
F_87 (sdata, &local->interfaces, list) {
V_13 -> V_548 = V_10 -> V_548 ;
if ( V_545 != V_13 -> V_27 . V_215 . V_552 )
V_546 = true ;
V_13 -> V_27 . V_215 . V_552 = V_545 ;
}
F_87 (sdata, &local->interfaces, list)
F_226 ( V_13 , V_546 ) ;
F_19 ( & V_10 -> V_152 ) ;
return 0 ;
}
static int F_227 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_553 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_498 -> V_554 )
return F_228 ( V_10 , V_13 , V_553 ) ;
if ( ! V_10 -> V_153 )
* V_553 = V_10 -> V_107 . V_61 . V_555 ;
else
* V_553 = V_13 -> V_27 . V_215 . V_556 ;
return 0 ;
}
static int F_229 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_143 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_557 . V_558 , V_143 , V_144 ) ;
return 0 ;
}
static void F_230 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_231 ( V_10 ) ;
}
static int F_232 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
void * V_170 , int V_169 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_559 * V_27 = NULL ;
if ( ! V_10 -> V_498 -> V_560 )
return - V_345 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_561 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_498 -> V_560 ( & V_10 -> V_107 , V_27 , V_170 , V_169 ) ;
}
static int F_233 ( struct V_2 * V_2 ,
struct V_249 * V_250 ,
struct V_562 * V_258 ,
void * V_170 , int V_169 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_498 -> V_563 )
return - V_345 ;
return V_10 -> V_498 -> V_563 ( & V_10 -> V_107 , V_250 , V_258 , V_170 , V_169 ) ;
}
int F_234 ( struct V_12 * V_13 ,
enum V_564 V_200 )
{
struct V_38 * V_24 ;
enum V_564 V_565 ;
if ( F_36 ( V_13 -> V_27 . type != V_70 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_215 . V_149 . V_566 == V_567 )
return 0 ;
V_565 = V_13 -> V_16 . V_166 . V_352 ;
V_13 -> V_16 . V_166 . V_352 = V_200 ;
if ( V_565 == V_200 ||
V_200 == V_568 )
return 0 ;
if ( ! F_235 ( & V_13 -> V_16 . V_166 . V_350 ) ) {
V_13 -> V_200 = V_200 ;
F_236 ( & V_13 -> V_10 -> V_107 , & V_13 -> V_569 ) ;
return 0 ;
}
F_149 ( V_13 ,
L_3 ,
V_200 , F_235 ( & V_13 -> V_16 . V_166 . V_350 ) ) ;
F_17 ( & V_13 -> V_10 -> V_63 ) ;
F_87 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_349 != & V_13 -> V_16 . V_166 )
continue;
if ( F_148 ( V_24 ) == 1 )
continue;
if ( F_33 ( V_24 , V_570 ) &&
! F_237 ( V_24 -> V_351 ,
V_200 ) ) {
F_149 ( V_13 , L_4 ,
V_24 -> V_24 . V_143 ) ;
continue;
}
if ( ! F_33 ( V_24 , V_268 ) )
continue;
F_149 ( V_13 , L_5 , V_24 -> V_24 . V_143 ) ;
F_150 ( V_13 , V_200 , V_24 -> V_24 . V_143 ,
V_13 -> V_27 . V_215 . V_353 ) ;
}
F_19 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_200 = V_200 ;
F_236 ( & V_13 -> V_10 -> V_107 , & V_13 -> V_569 ) ;
return 0 ;
}
int F_238 ( struct V_12 * V_13 ,
enum V_564 V_200 )
{
const T_3 * V_166 ;
enum V_564 V_565 ;
int V_14 ;
struct V_38 * V_24 ;
bool V_571 = false ;
F_239 ( & V_13 -> V_11 . V_151 ) ;
if ( F_36 ( V_13 -> V_27 . type != V_25 ) )
return - V_49 ;
V_565 = V_13 -> V_16 . V_26 . V_352 ;
V_13 -> V_16 . V_26 . V_352 = V_200 ;
if ( V_565 == V_200 &&
V_200 != V_568 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_572 ||
V_13 -> V_27 . V_215 . V_149 . V_566 == V_567 )
return 0 ;
V_166 = V_13 -> V_16 . V_26 . V_572 -> V_353 ;
F_43 () ;
F_240 (sta, &sdata->local->sta_list, list) {
if ( ! V_24 -> V_24 . V_330 || V_24 -> V_13 != V_13 || ! V_24 -> V_573 ||
! F_33 ( V_24 , V_268 ) )
continue;
V_571 = true ;
break;
}
F_53 () ;
if ( V_200 == V_568 ) {
if ( V_571 || ! V_13 -> V_16 . V_26 . V_574 )
V_200 = V_202 ;
else
V_200 = V_206 ;
}
V_14 = F_150 ( V_13 , V_200 ,
V_166 , V_166 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_352 = V_565 ;
else if ( V_200 != V_202 && V_571 )
F_241 ( V_13 ) ;
return V_14 ;
}
static int F_242 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_575 , int V_576 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_68 ( V_19 -> V_147 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_345 ;
if ( ! F_128 ( & V_10 -> V_107 , V_577 ) )
return - V_345 ;
if ( V_575 == V_13 -> V_16 . V_26 . V_574 &&
V_576 == V_10 -> V_578 )
return 0 ;
V_13 -> V_16 . V_26 . V_574 = V_575 ;
V_10 -> V_578 = V_576 ;
F_243 ( V_13 ) ;
F_238 ( V_13 , V_13 -> V_16 . V_26 . V_352 ) ;
F_244 ( V_13 ) ;
if ( F_128 ( & V_10 -> V_107 , V_579 ) )
F_77 ( V_10 , V_580 ) ;
F_151 ( V_10 ) ;
F_152 ( V_13 ) ;
return 0 ;
}
static int F_245 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_581 , T_1 V_582 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_559 * V_27 = & V_13 -> V_27 ;
struct V_583 * V_215 = & V_27 -> V_215 ;
if ( V_581 == V_215 -> V_584 &&
V_582 == V_215 -> V_585 )
return 0 ;
if ( V_13 -> V_27 . V_586 & V_587 &&
! ( V_13 -> V_27 . V_586 & V_588 ) )
return - V_345 ;
V_215 -> V_584 = V_581 ;
V_215 -> V_585 = V_582 ;
V_13 -> V_16 . V_26 . V_589 = 0 ;
if ( V_13 -> V_16 . V_26 . V_572 &&
V_13 -> V_27 . V_586 & V_588 )
F_90 ( V_13 , V_590 ) ;
return 0 ;
}
static int F_246 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_143 ,
const struct V_591 * V_28 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_68 ( V_19 -> V_147 ) ;
int V_592 , V_20 ;
if ( ! F_13 ( V_13 ) )
return - V_43 ;
if ( F_128 ( & V_10 -> V_107 , V_593 ) ) {
V_20 = F_247 ( V_10 , V_13 , V_28 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_592 = 0 ; V_592 < V_527 ; V_592 ++ ) {
struct V_122 * V_123 = V_2 -> V_126 [ V_592 ] ;
int V_594 ;
V_13 -> V_595 [ V_592 ] = V_28 -> V_255 [ V_592 ] . V_129 ;
memcpy ( V_13 -> V_596 [ V_592 ] , V_28 -> V_255 [ V_592 ] . V_597 ,
sizeof( V_28 -> V_255 [ V_592 ] . V_597 ) ) ;
memcpy ( V_13 -> V_598 [ V_592 ] ,
V_28 -> V_255 [ V_592 ] . V_599 ,
sizeof( V_28 -> V_255 [ V_592 ] . V_599 ) ) ;
V_13 -> V_600 [ V_592 ] = false ;
V_13 -> V_601 [ V_592 ] = false ;
if ( ! V_123 )
continue;
for ( V_594 = 0 ; V_594 < V_602 ; V_594 ++ ) {
if ( ~ V_13 -> V_596 [ V_592 ] [ V_594 ] ) {
V_13 -> V_600 [ V_592 ] = true ;
break;
}
}
for ( V_594 = 0 ; V_594 < V_603 ; V_594 ++ ) {
if ( ~ V_13 -> V_598 [ V_592 ] [ V_594 ] ) {
V_13 -> V_601 [ V_592 ] = true ;
break;
}
}
}
return 0 ;
}
static int F_248 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_148 * V_149 ,
T_1 V_604 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_17 ( & V_10 -> V_151 ) ;
if ( ! F_249 ( & V_10 -> V_605 ) || V_10 -> V_606 ) {
V_14 = - V_31 ;
goto V_66;
}
V_13 -> V_200 = V_202 ;
V_13 -> V_207 = V_10 -> V_208 ;
V_14 = F_76 ( V_13 , V_149 ,
V_209 ) ;
if ( V_14 )
goto V_66;
F_250 ( & V_13 -> V_10 -> V_107 ,
& V_13 -> V_242 ,
F_251 ( V_604 ) ) ;
V_66:
F_19 ( & V_10 -> V_151 ) ;
return V_14 ;
}
static struct V_175 *
F_252 ( struct V_175 * V_182 )
{
struct V_175 * V_607 ;
T_3 * V_608 ;
int V_169 ;
V_169 = V_182 -> V_184 + V_182 -> V_186 + V_182 -> V_609 +
V_182 -> V_610 + V_182 -> V_611 +
V_182 -> V_191 ;
V_607 = F_80 ( sizeof( * V_607 ) + V_169 , V_167 ) ;
if ( ! V_607 )
return NULL ;
V_608 = ( T_3 * ) ( V_607 + 1 ) ;
if ( V_182 -> V_184 ) {
V_607 -> V_184 = V_182 -> V_184 ;
V_607 -> V_183 = V_608 ;
memcpy ( V_608 , V_182 -> V_183 , V_182 -> V_184 ) ;
V_608 += V_182 -> V_184 ;
}
if ( V_182 -> V_186 ) {
V_607 -> V_186 = V_182 -> V_186 ;
V_607 -> V_185 = V_608 ;
memcpy ( V_608 , V_182 -> V_185 , V_182 -> V_186 ) ;
V_608 += V_182 -> V_186 ;
}
if ( V_182 -> V_609 ) {
V_607 -> V_609 = V_182 -> V_609 ;
V_607 -> V_612 = V_608 ;
memcpy ( V_608 , V_182 -> V_612 , V_182 -> V_609 ) ;
V_608 += V_182 -> V_609 ;
}
if ( V_182 -> V_610 ) {
V_607 -> V_610 = V_182 -> V_610 ;
V_607 -> V_613 = V_608 ;
memcpy ( V_608 , V_182 -> V_613 , V_182 -> V_610 ) ;
V_608 += V_182 -> V_610 ;
}
if ( V_182 -> V_611 ) {
V_607 -> V_611 = V_182 -> V_611 ;
V_607 -> V_614 = V_608 ;
memcpy ( V_608 , V_182 -> V_614 , V_182 -> V_611 ) ;
V_608 += V_182 -> V_611 ;
}
if ( V_182 -> V_191 ) {
V_607 -> V_191 = V_182 -> V_191 ;
V_182 -> V_163 = V_608 ;
memcpy ( V_608 , V_182 -> V_163 , V_182 -> V_191 ) ;
V_608 += V_182 -> V_191 ;
}
return V_607 ;
}
void F_253 ( struct V_559 * V_27 )
{
struct V_12 * V_13 = F_254 ( V_27 ) ;
F_236 ( & V_13 -> V_10 -> V_107 ,
& V_13 -> V_615 ) ;
}
static int F_255 ( struct V_12 * V_13 ,
T_1 * V_180 )
{
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_14 = F_83 ( V_13 , V_13 -> V_16 . V_166 . V_237 ,
NULL ) ;
F_96 ( V_13 -> V_16 . V_166 . V_237 ) ;
V_13 -> V_16 . V_166 . V_237 = NULL ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
break;
case V_72 :
V_14 = F_256 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
break;
#ifdef F_35
case V_73 :
V_14 = F_257 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
break;
#endif
default:
F_52 ( 1 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_258 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_180 = 0 ;
int V_14 ;
F_93 ( V_13 ) ;
F_239 ( & V_10 -> V_151 ) ;
F_239 ( & V_10 -> V_32 ) ;
if ( V_13 -> V_616 ) {
if ( V_13 -> V_617 )
return 0 ;
return F_259 ( V_13 ) ;
}
if ( ! F_72 ( & V_13 -> V_27 . V_215 . V_149 ,
& V_13 -> V_618 ) )
return - V_49 ;
V_13 -> V_27 . V_232 = false ;
V_14 = F_255 ( V_13 , & V_180 ) ;
if ( V_14 )
return V_14 ;
F_90 ( V_13 , V_180 ) ;
if ( V_13 -> V_235 ) {
F_95 ( V_10 , V_13 ,
V_236 ) ;
V_13 -> V_235 = false ;
}
V_14 = F_260 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_261 ( V_13 -> V_19 , & V_13 -> V_618 ) ;
return 0 ;
}
static void F_262 ( struct V_12 * V_13 )
{
if ( F_258 ( V_13 ) ) {
F_263 ( V_13 , L_6 ) ;
F_264 ( V_13 -> V_10 -> V_107 . V_2 , & V_13 -> V_11 ,
V_167 ) ;
}
}
void F_265 ( struct V_619 * V_620 )
{
struct V_12 * V_13 =
F_176 ( V_620 , struct V_12 ,
V_615 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_243 ( V_13 ) ;
F_17 ( & V_10 -> V_151 ) ;
F_17 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_232 )
goto V_621;
if ( ! F_13 ( V_13 ) )
goto V_621;
F_262 ( V_13 ) ;
V_621:
F_19 ( & V_10 -> V_32 ) ;
F_19 ( & V_10 -> V_151 ) ;
F_244 ( V_13 ) ;
}
static int F_266 ( struct V_12 * V_13 ,
struct V_622 * V_8 ,
T_1 * V_180 )
{
struct V_161 V_162 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_166 . V_237 =
F_252 ( & V_8 -> V_623 ) ;
if ( ! V_13 -> V_16 . V_166 . V_237 )
return - V_168 ;
if ( V_8 -> V_188 <= 1 )
break;
if ( ( V_8 -> V_190 >
V_624 ) ||
( V_8 -> V_173 >
V_624 ) )
return - V_49 ;
V_162 . V_189 = V_8 -> V_189 ;
V_162 . V_172 = V_8 -> V_172 ;
V_162 . V_190 = V_8 -> V_190 ;
V_162 . V_173 = V_8 -> V_173 ;
V_162 . V_188 = V_8 -> V_188 ;
V_14 = F_83 ( V_13 , & V_8 -> V_625 , & V_162 ) ;
if ( V_14 < 0 ) {
F_96 ( V_13 -> V_16 . V_166 . V_237 ) ;
return V_14 ;
}
* V_180 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_215 . V_626 )
return - V_49 ;
if ( V_8 -> V_149 . V_566 != V_13 -> V_16 . V_627 . V_149 . V_566 )
return - V_49 ;
switch ( V_8 -> V_149 . V_566 ) {
case V_628 :
if ( F_267 ( & V_8 -> V_149 ) !=
F_267 ( & V_13 -> V_16 . V_627 . V_149 ) )
return - V_49 ;
case V_629 :
case V_630 :
case V_567 :
case V_631 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_627 . V_149 . V_632 -> V_290 !=
V_8 -> V_149 . V_632 -> V_290 )
return - V_49 ;
if ( V_8 -> V_188 > 1 ) {
V_14 = F_268 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
}
F_269 ( V_13 , V_8 ) ;
break;
#ifdef F_35
case V_73 : {
struct V_396 * V_397 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_149 . V_566 != V_13 -> V_27 . V_215 . V_149 . V_566 )
return - V_49 ;
if ( V_13 -> V_27 . V_215 . V_149 . V_632 -> V_290 !=
V_8 -> V_149 . V_632 -> V_290 )
return - V_49 ;
if ( V_397 -> V_633 == V_634 ) {
V_397 -> V_633 = V_635 ;
if ( ! V_397 -> V_636 )
V_397 -> V_636 = 1 ;
else
V_397 -> V_636 ++ ;
}
if ( V_8 -> V_188 > 1 ) {
V_14 = F_270 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_397 -> V_633 = V_634 ;
return V_14 ;
}
* V_180 |= V_14 ;
}
if ( V_397 -> V_633 == V_635 )
F_269 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_345 ;
}
return 0 ;
}
static int
F_271 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_622 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_637 V_638 ;
struct V_639 * V_61 ;
struct V_640 * V_641 ;
T_1 V_180 = 0 ;
int V_14 ;
F_93 ( V_13 ) ;
F_239 ( & V_10 -> V_151 ) ;
if ( ! F_249 ( & V_10 -> V_605 ) || V_10 -> V_606 )
return - V_31 ;
if ( V_13 -> V_11 . V_241 )
return - V_31 ;
if ( F_72 ( & V_8 -> V_149 ,
& V_13 -> V_27 . V_215 . V_149 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_232 )
return - V_31 ;
F_17 ( & V_10 -> V_32 ) ;
V_61 = F_73 ( V_13 -> V_27 . V_642 ,
F_74 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_95;
}
V_641 = F_176 ( V_61 , struct V_640 , V_61 ) ;
if ( ! V_641 ) {
V_14 = - V_31 ;
goto V_95;
}
V_638 . V_643 = 0 ;
V_638 . V_644 = 0 ;
V_638 . V_645 = V_8 -> V_645 ;
V_638 . V_149 = V_8 -> V_149 ;
V_638 . V_188 = V_8 -> V_188 ;
V_14 = F_272 ( V_13 , & V_638 ) ;
if ( V_14 )
goto V_95;
V_14 = F_273 ( V_13 , & V_8 -> V_149 ,
V_641 -> V_646 ,
V_8 -> V_647 ) ;
if ( V_14 )
goto V_95;
V_14 = F_18 ( V_13 , NULL , V_641 -> V_646 , 0 ) ;
if ( V_14 ) {
F_274 ( V_13 ) ;
goto V_95;
}
V_14 = F_266 ( V_13 , V_8 , & V_180 ) ;
if ( V_14 ) {
F_274 ( V_13 ) ;
goto V_95;
}
V_13 -> V_618 = V_8 -> V_149 ;
V_13 -> V_235 = V_8 -> V_645 ;
V_13 -> V_27 . V_232 = true ;
if ( V_13 -> V_235 )
F_275 ( V_10 , V_13 ,
V_236 ) ;
F_276 ( V_13 -> V_19 , & V_13 -> V_618 ,
V_8 -> V_188 ) ;
if ( V_180 ) {
F_90 ( V_13 , V_180 ) ;
F_277 ( V_13 , & V_8 -> V_149 ) ;
} else {
F_262 ( V_13 ) ;
}
V_95:
F_19 ( & V_10 -> V_32 ) ;
return V_14 ;
}
int V_637 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_622 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_17 ( & V_10 -> V_151 ) ;
V_14 = F_271 ( V_2 , V_19 , V_8 ) ;
F_19 ( & V_10 -> V_151 ) ;
return V_14 ;
}
T_4 F_278 ( struct V_9 * V_10 )
{
F_239 ( & V_10 -> V_151 ) ;
V_10 -> V_648 ++ ;
if ( F_52 ( V_10 -> V_648 == 0 ) )
V_10 -> V_648 ++ ;
return V_10 -> V_648 ;
}
int F_279 ( struct V_9 * V_10 , struct V_249 * V_250 ,
T_4 * V_89 , T_8 V_649 )
{
unsigned long V_650 ;
struct V_249 * V_651 ;
int V_652 ;
V_651 = F_280 ( V_250 , V_649 ) ;
if ( ! V_651 )
return - V_168 ;
F_281 ( & V_10 -> V_653 , V_650 ) ;
V_652 = F_282 ( & V_10 -> V_654 , V_651 ,
1 , 0x10000 , V_655 ) ;
F_283 ( & V_10 -> V_653 , V_650 ) ;
if ( V_652 < 0 ) {
F_284 ( V_651 ) ;
return - V_168 ;
}
F_285 ( V_250 ) -> V_656 = V_652 ;
* V_89 = F_278 ( V_10 ) ;
F_285 ( V_651 ) -> V_657 . V_89 = * V_89 ;
return 0 ;
}
static void F_286 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_658 , bool V_659 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_658 ) {
case V_660 | V_661 :
if ( V_659 ) {
V_10 -> V_662 ++ ;
V_13 -> V_27 . V_662 ++ ;
} else {
if ( V_10 -> V_662 )
V_10 -> V_662 -- ;
if ( V_13 -> V_27 . V_662 )
V_13 -> V_27 . V_662 -- ;
}
if ( ! V_10 -> V_156 )
break;
if ( V_13 -> V_27 . V_662 == 1 )
F_287 ( V_10 , V_13 , V_663 ,
V_663 ) ;
else if ( V_13 -> V_27 . V_662 == 0 )
F_287 ( V_10 , V_13 , 0 ,
V_663 ) ;
F_15 ( V_10 ) ;
break;
default:
break;
}
}
static int F_288 ( struct V_2 * V_2 , T_1 V_664 , T_1 V_665 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_666 )
return - V_345 ;
return F_289 ( V_10 , V_664 , V_665 ) ;
}
static int F_290 ( struct V_2 * V_2 , T_1 * V_664 , T_1 * V_665 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_291 ( V_10 , V_664 , V_665 ) ;
}
static int F_292 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_667 * V_170 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_498 -> V_668 )
return - V_345 ;
F_293 ( V_10 , V_13 , V_170 ) ;
return 0 ;
}
static int F_294 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_669 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_670 * V_671 ;
struct V_249 * V_250 ;
int V_179 = sizeof( * V_671 ) ;
T_9 V_672 ;
bool V_673 ;
struct V_674 * V_675 ;
struct V_38 * V_24 ;
struct V_639 * V_642 ;
enum V_289 V_290 ;
int V_20 ;
F_17 ( & V_10 -> V_151 ) ;
F_43 () ;
V_642 = F_44 ( V_13 -> V_27 . V_642 ) ;
if ( F_52 ( ! V_642 ) ) {
V_20 = - V_49 ;
goto V_621;
}
V_290 = V_642 -> V_676 . V_632 -> V_290 ;
V_24 = F_32 ( V_13 , V_669 ) ;
if ( V_24 ) {
V_673 = V_24 -> V_24 . V_297 ;
} else {
V_20 = - V_677 ;
goto V_621;
}
if ( V_673 ) {
V_672 = F_295 ( V_678 |
V_679 |
V_680 ) ;
} else {
V_179 -= 2 ;
V_672 = F_295 ( V_678 |
V_681 |
V_680 ) ;
}
V_250 = F_107 ( V_10 -> V_107 . V_682 + V_179 ) ;
if ( ! V_250 ) {
V_20 = - V_168 ;
goto V_621;
}
V_250 -> V_19 = V_19 ;
F_296 ( V_250 , V_10 -> V_107 . V_682 ) ;
V_671 = ( void * ) F_108 ( V_250 , V_179 ) ;
V_671 -> V_683 = V_672 ;
V_671 -> V_684 = 0 ;
memcpy ( V_671 -> V_685 , V_24 -> V_24 . V_143 , V_144 ) ;
memcpy ( V_671 -> V_686 , V_13 -> V_27 . V_143 , V_144 ) ;
memcpy ( V_671 -> V_687 , V_13 -> V_27 . V_143 , V_144 ) ;
V_671 -> V_688 = 0 ;
V_675 = F_285 ( V_250 ) ;
V_675 -> V_6 |= V_689 |
V_690 ;
V_675 -> V_290 = V_290 ;
F_297 ( V_250 , V_691 ) ;
V_250 -> V_692 = 7 ;
if ( V_673 )
V_671 -> V_693 = F_295 ( 7 ) ;
V_20 = F_279 ( V_10 , V_250 , V_89 , V_655 ) ;
if ( V_20 ) {
F_284 ( V_250 ) ;
goto V_621;
}
F_298 () ;
F_299 ( V_13 , V_24 , V_250 ) ;
F_300 () ;
V_20 = 0 ;
V_621:
F_53 () ;
F_19 ( & V_10 -> V_151 ) ;
return V_20 ;
}
static int F_301 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_148 * V_149 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_639 * V_642 ;
int V_20 = - V_694 ;
F_43 () ;
V_642 = F_44 ( V_13 -> V_27 . V_642 ) ;
if ( V_642 ) {
* V_149 = V_13 -> V_27 . V_215 . V_149 ;
V_20 = 0 ;
} else if ( V_10 -> V_156 > 0 &&
V_10 -> V_156 == V_10 -> V_157 &&
V_13 -> V_27 . type == V_15 ) {
if ( V_10 -> V_153 )
* V_149 = V_10 -> V_150 ;
else
* V_149 = V_10 -> V_158 ;
V_20 = 0 ;
}
F_53 () ;
return V_20 ;
}
static void F_302 ( struct V_2 * V_2 , bool V_575 )
{
F_303 ( F_2 ( V_2 ) , V_575 ) ;
}
static int F_304 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_695 * V_696 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_697 * V_698 , * V_699 ;
if ( V_696 ) {
V_698 = F_80 ( sizeof( * V_698 ) , V_167 ) ;
if ( ! V_698 )
return - V_168 ;
memcpy ( & V_698 -> V_696 , V_696 , sizeof( * V_696 ) ) ;
} else {
V_698 = NULL ;
}
V_699 = F_79 ( V_13 -> V_696 , V_13 ) ;
F_81 ( V_13 -> V_696 , V_698 ) ;
if ( V_699 )
F_82 ( V_699 , V_174 ) ;
return 0 ;
}
static int F_305 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_148 * V_149 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_180 = 0 ;
V_20 = F_306 ( V_13 , V_149 , & V_180 ) ;
if ( V_20 == 0 )
F_90 ( V_13 , V_180 ) ;
return V_20 ;
}
static int F_307 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_700 , const T_3 * V_669 , T_3 V_701 ,
T_2 V_702 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_703 * V_704 = & V_13 -> V_16 . V_26 ;
int V_508 = V_705 [ V_701 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_345 ;
if ( ! ( V_13 -> V_706 & F_114 ( V_701 ) ) )
return - V_49 ;
if ( V_704 -> V_707 [ V_508 ] . V_702 )
return - V_31 ;
if ( V_702 ) {
V_704 -> V_707 [ V_508 ] . V_702 = 32 * V_702 ;
V_704 -> V_707 [ V_508 ] . V_700 = V_700 ;
V_704 -> V_707 [ V_508 ] . V_701 = V_701 ;
}
return 0 ;
}
static int F_308 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_700 , const T_3 * V_669 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_703 * V_704 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_508 ;
for ( V_508 = 0 ; V_508 < V_296 ; V_508 ++ ) {
struct V_708 * V_707 = & V_704 -> V_707 [ V_508 ] ;
if ( ! V_707 -> V_702 )
continue;
if ( V_707 -> V_700 != V_700 )
continue;
V_707 -> V_701 = - 1 ;
F_309 () ;
F_310 ( V_10 , V_13 , false ) ;
V_707 -> V_709 = V_710 ;
V_707 -> V_711 = false ;
F_311 ( V_13 ) ;
memset ( V_707 , 0 , sizeof( * V_707 ) ) ;
return 0 ;
}
return - V_65 ;
}
