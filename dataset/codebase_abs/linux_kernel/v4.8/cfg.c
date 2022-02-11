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
F_105 ( & V_10 -> V_107 , & V_13 -> V_16 . V_166 . V_245 . V_246 ) ;
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
V_24 -> V_74 -> V_275 = V_8 -> V_276 ;
F_119 ( V_24 ) ;
V_180 |= F_120 ( V_24 ,
V_13 -> V_16 . V_74 . V_277 . V_278 ) ;
break;
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
if ( V_24 -> V_74 -> V_273 == V_274 )
V_180 = F_121 ( V_13 ) ;
V_24 -> V_74 -> V_273 = V_8 -> V_273 ;
F_119 ( V_24 ) ;
V_180 |= F_120 ( V_24 ,
V_285 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_286 ) {
case V_287 :
break;
case V_288 :
V_180 |= F_122 ( V_24 ) ;
break;
case V_289 :
V_180 |= F_123 ( V_24 ) ;
break;
}
if ( V_8 -> V_290 )
V_180 |= F_120 ( V_24 ,
V_8 -> V_290 ) ;
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
enum V_291 V_292 = F_62 ( V_13 ) ;
T_1 V_28 , V_259 ;
V_123 = V_10 -> V_107 . V_2 -> V_126 [ V_292 ] ;
V_28 = V_8 -> V_293 ;
V_259 = V_8 -> V_294 ;
if ( F_30 ( & V_13 -> V_27 ) ) {
if ( V_28 & F_114 ( V_260 ) )
V_28 |= F_114 ( V_263 ) ;
if ( V_259 & F_114 ( V_260 ) )
V_259 |= F_114 ( V_263 ) ;
} else if ( F_33 ( V_24 , V_295 ) ) {
if ( V_259 & F_114 ( V_266 ) ) {
V_259 |= F_114 ( V_260 ) |
F_114 ( V_263 ) ;
V_28 |= F_114 ( V_260 ) |
F_114 ( V_263 ) ;
}
}
if ( V_28 & F_114 ( V_296 ) &&
V_10 -> V_107 . V_297 >= V_298 )
V_24 -> V_24 . V_299 = V_259 & F_114 ( V_296 ) ;
if ( ! F_33 ( V_24 , V_295 ) &&
! ( ( V_28 & F_114 ( V_263 ) ) &&
( V_259 & F_114 ( V_263 ) ) ) ) {
V_20 = F_113 ( V_10 , V_24 , V_28 , V_259 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_114 ( V_300 ) ) {
if ( V_259 & F_114 ( V_300 ) )
F_126 ( V_24 , V_301 ) ;
else
F_127 ( V_24 , V_301 ) ;
}
if ( V_28 & F_114 ( V_302 ) ) {
V_24 -> V_24 . V_67 = ! ! ( V_259 & F_114 ( V_302 ) ) ;
if ( V_259 & F_114 ( V_302 ) )
F_126 ( V_24 , V_71 ) ;
else
F_127 ( V_24 , V_71 ) ;
}
if ( V_28 & F_114 ( V_303 ) ) {
if ( V_259 & F_114 ( V_303 ) )
F_126 ( V_24 , V_295 ) ;
else
F_127 ( V_24 , V_295 ) ;
}
if ( F_33 ( V_24 , V_295 ) &&
! V_13 -> V_16 . V_26 . V_304 &&
V_8 -> V_305 >= 4 &&
V_8 -> V_306 [ 3 ] & V_307 )
F_126 ( V_24 , V_308 ) ;
if ( F_33 ( V_24 , V_295 ) &&
! V_13 -> V_16 . V_26 . V_309 &&
F_128 ( & V_10 -> V_107 , V_310 ) &&
V_8 -> V_305 >= 8 &&
V_8 -> V_306 [ 7 ] & V_311 )
F_126 ( V_24 , V_312 ) ;
if ( V_8 -> V_271 & V_313 ) {
V_24 -> V_24 . V_314 = V_8 -> V_314 ;
V_24 -> V_24 . V_315 = V_8 -> V_315 ;
}
if ( V_8 -> V_305 >= 8 ) {
T_3 V_316 = ( V_8 -> V_306 [ 7 ] &
V_317 ) >> 7 ;
if ( V_8 -> V_305 >= 9 ) {
T_3 V_318 = V_8 -> V_306 [ 8 ] &
V_319 ;
V_318 <<= 1 ;
V_316 |= V_318 ;
}
switch ( V_316 ) {
case 1 :
V_24 -> V_24 . V_320 = 32 ;
break;
case 2 :
V_24 -> V_24 . V_320 = 16 ;
break;
case 3 :
V_24 -> V_24 . V_320 = 8 ;
break;
default:
V_24 -> V_24 . V_320 = 0 ;
}
}
if ( V_8 -> V_275 )
V_24 -> V_24 . V_275 = V_8 -> V_275 ;
if ( V_8 -> V_321 >= 0 )
V_24 -> V_321 = V_8 -> V_321 ;
if ( V_8 -> V_322 ) {
F_129 ( & V_13 -> V_27 . V_215 . V_149 ,
V_123 , V_8 -> V_322 ,
V_8 -> V_323 ,
& V_24 -> V_24 . V_324 [ V_292 ] ) ;
}
if ( V_8 -> V_325 )
F_130 ( V_13 , V_123 ,
V_8 -> V_325 , V_24 ) ;
if ( V_8 -> V_326 )
F_131 ( V_13 , V_123 ,
V_8 -> V_326 , V_24 ) ;
if ( V_8 -> V_327 ) {
F_132 ( V_13 , V_24 ,
V_8 -> V_328 , V_292 ) ;
}
if ( V_8 -> V_329 >= 0 )
V_24 -> V_24 . V_329 = V_8 -> V_329 ;
if ( F_30 ( & V_13 -> V_27 ) )
F_117 ( V_10 , V_24 , V_8 ) ;
if ( F_33 ( V_24 , V_295 ) ||
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
int V_330 ;
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
if ( V_8 -> V_294 & F_114 ( V_303 ) )
V_24 -> V_24 . V_331 = true ;
V_14 = F_125 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_137 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_33 ( V_24 , V_295 ) &&
F_33 ( V_24 , V_64 ) )
F_116 ( V_24 ) ;
V_330 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_138 ( V_24 ) ;
if ( V_14 ) {
F_53 () ;
return V_14 ;
}
if ( V_330 )
F_106 ( V_24 ) ;
F_53 () ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_332 * V_8 )
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
struct V_12 * V_333 ;
enum V_334 V_335 ;
int V_14 ;
F_17 ( & V_10 -> V_63 ) ;
V_24 = F_32 ( V_13 , V_140 ) ;
if ( ! V_24 ) {
V_14 = - V_65 ;
goto V_336;
}
switch ( V_13 -> V_27 . type ) {
case V_73 :
if ( V_13 -> V_16 . V_74 . V_337 )
V_335 = V_338 ;
else
V_335 = V_339 ;
break;
case V_72 :
V_335 = V_340 ;
break;
case V_25 :
if ( ! F_33 ( V_24 , V_295 ) ) {
V_335 = V_341 ;
break;
}
if ( F_33 ( V_24 , V_268 ) )
V_335 = V_342 ;
else
V_335 = V_343 ;
break;
case V_70 :
case V_21 :
if ( F_33 ( V_24 , V_64 ) )
V_335 = V_344 ;
else
V_335 = V_345 ;
break;
default:
V_14 = - V_346 ;
goto V_336;
}
V_14 = F_143 ( V_2 , V_8 , V_335 ) ;
if ( V_14 )
goto V_336;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_347 = false ;
bool V_348 = false ;
V_333 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_147 -> V_22 ) {
if ( V_333 -> V_16 . V_23 . V_24 ) {
V_14 = - V_31 ;
goto V_336;
}
F_81 ( V_333 -> V_16 . V_23 . V_24 , V_24 ) ;
V_348 = true ;
F_144 ( V_333 ) ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_347 = true ;
}
V_24 -> V_13 = V_333 ;
F_145 ( V_24 ) ;
if ( V_24 -> V_349 == V_267 &&
V_347 != V_348 ) {
if ( V_348 )
F_146 ( & V_24 -> V_13 -> V_350 -> V_351 ) ;
else
F_147 ( & V_24 -> V_13 -> V_350 -> V_351 ) ;
}
F_106 ( V_24 ) ;
}
V_14 = F_125 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_336;
F_19 ( & V_10 -> V_63 ) ;
if ( ( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_352 != V_24 -> V_13 -> V_350 -> V_353 &&
F_33 ( V_24 , V_268 ) &&
F_148 ( V_24 ) != 1 ) {
F_149 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_143 ) ;
F_150 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_350 -> V_353 ,
V_24 -> V_24 . V_143 ,
V_24 -> V_13 -> V_27 . V_215 . V_354 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_293 & F_114 ( V_266 ) ) {
F_151 ( V_10 ) ;
F_152 ( V_13 ) ;
}
return 0 ;
V_336:
F_19 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_153 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_355 , const T_3 * V_356 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_24 = F_31 ( V_13 , V_356 ) ;
if ( ! V_24 ) {
F_53 () ;
return - V_65 ;
}
V_358 = F_154 ( V_13 , V_355 ) ;
if ( F_26 ( V_358 ) ) {
F_53 () ;
return F_29 ( V_358 ) ;
}
F_155 ( V_358 , V_24 ) ;
F_53 () ;
return 0 ;
}
static int F_156 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_355 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_355 )
return F_157 ( V_13 , V_355 ) ;
F_158 ( V_13 ) ;
return 0 ;
}
static int F_159 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_355 , const T_3 * V_356 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_24 = F_31 ( V_13 , V_356 ) ;
if ( ! V_24 ) {
F_53 () ;
return - V_65 ;
}
V_358 = F_160 ( V_13 , V_355 ) ;
if ( ! V_358 ) {
F_53 () ;
return - V_65 ;
}
F_155 ( V_358 , V_24 ) ;
F_53 () ;
return 0 ;
}
static void F_161 ( struct V_357 * V_358 , T_3 * V_356 ,
struct V_359 * V_360 )
{
struct V_38 * V_361 = F_44 ( V_358 -> V_356 ) ;
if ( V_361 )
memcpy ( V_356 , V_361 -> V_24 . V_143 , V_144 ) ;
else
F_162 ( V_356 ) ;
memset ( V_360 , 0 , sizeof( * V_360 ) ) ;
V_360 -> V_362 = V_358 -> V_13 -> V_16 . V_74 . V_363 ;
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
if ( F_163 ( V_377 , V_358 -> V_378 ) )
V_360 -> V_379 = F_164 ( V_358 -> V_378 - V_377 ) ;
V_360 -> V_380 =
F_164 ( V_358 -> V_380 ) ;
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
static int F_165 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_355 , T_3 * V_356 , struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_358 = F_160 ( V_13 , V_355 ) ;
if ( ! V_358 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_144 ) ;
F_161 ( V_358 , V_356 , V_360 ) ;
F_53 () ;
return 0 ;
}
static int F_166 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_355 , T_3 * V_356 ,
struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_358 = F_167 ( V_13 , V_118 ) ;
if ( ! V_358 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_144 ) ;
F_161 ( V_358 , V_356 , V_360 ) ;
F_53 () ;
return 0 ;
}
static void F_168 ( struct V_357 * V_358 , T_3 * V_392 ,
struct V_359 * V_360 )
{
memset ( V_360 , 0 , sizeof( * V_360 ) ) ;
memcpy ( V_392 , V_358 -> V_392 , V_144 ) ;
V_360 -> V_362 = V_358 -> V_13 -> V_16 . V_74 . V_393 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_355 , T_3 * V_392 , struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_358 = F_170 ( V_13 , V_355 ) ;
if ( ! V_358 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_144 ) ;
F_168 ( V_358 , V_392 , V_360 ) ;
F_53 () ;
return 0 ;
}
static int F_171 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_355 , T_3 * V_392 ,
struct V_359 * V_360 )
{
struct V_12 * V_13 ;
struct V_357 * V_358 ;
V_13 = F_9 ( V_19 ) ;
F_43 () ;
V_358 = F_172 ( V_13 , V_118 ) ;
if ( ! V_358 ) {
F_53 () ;
return - V_65 ;
}
memcpy ( V_355 , V_358 -> V_355 , V_144 ) ;
F_168 ( V_358 , V_392 , V_360 ) ;
F_53 () ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_394 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_277 ) , sizeof( struct V_394 ) ) ;
return 0 ;
}
static inline bool F_174 ( enum V_395 V_396 , T_1 V_28 )
{
return ( V_28 >> ( V_396 - 1 ) ) & 0x1 ;
}
static int F_175 ( struct V_397 * V_398 ,
const struct V_399 * V_400 )
{
T_3 * V_401 ;
const T_3 * V_402 ;
struct V_12 * V_13 = F_176 ( V_398 ,
struct V_12 , V_16 . V_74 ) ;
V_401 = NULL ;
V_402 = V_398 -> V_403 ;
if ( V_400 -> V_404 ) {
V_401 = F_177 ( V_400 -> V_403 , V_400 -> V_404 ,
V_167 ) ;
if ( ! V_401 )
return - V_168 ;
}
V_398 -> V_404 = V_400 -> V_404 ;
V_398 -> V_403 = V_401 ;
F_96 ( V_402 ) ;
V_398 -> V_405 = V_400 -> V_405 ;
memcpy ( V_398 -> V_406 , V_400 -> V_406 , V_398 -> V_405 ) ;
V_398 -> V_407 = V_400 -> V_408 ;
V_398 -> V_409 = V_400 -> V_410 ;
V_398 -> V_411 = V_400 -> V_412 ;
V_398 -> V_337 = V_400 -> V_337 ;
V_398 -> V_413 = V_400 -> V_414 ;
V_398 -> V_75 = V_76 ;
if ( V_400 -> V_415 )
V_398 -> V_75 |= V_416 ;
if ( V_400 -> V_417 )
V_398 -> V_75 |= V_418 ;
memcpy ( V_13 -> V_27 . V_215 . V_419 , V_400 -> V_419 ,
sizeof( V_400 -> V_419 ) ) ;
V_13 -> V_27 . V_215 . V_420 = V_400 -> V_420 ;
V_13 -> V_27 . V_215 . V_216 = V_400 -> V_217 ;
V_13 -> V_27 . V_215 . V_218 = V_400 -> V_218 ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_394 * V_421 )
{
struct V_394 * V_61 ;
struct V_12 * V_13 ;
struct V_397 * V_398 ;
V_13 = F_9 ( V_19 ) ;
V_398 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_277 ) ;
if ( F_174 ( V_422 , V_28 ) )
V_61 -> V_423 = V_421 -> V_423 ;
if ( F_174 ( V_424 , V_28 ) )
V_61 -> V_425 = V_421 -> V_425 ;
if ( F_174 ( V_426 , V_28 ) )
V_61 -> V_427 = V_421 -> V_427 ;
if ( F_174 ( V_428 , V_28 ) )
V_61 -> V_429 = V_421 -> V_429 ;
if ( F_174 ( V_430 , V_28 ) )
V_61 -> V_431 = V_421 -> V_431 ;
if ( F_174 ( V_432 , V_28 ) )
V_61 -> V_433 = V_421 -> V_433 ;
if ( F_174 ( V_434 , V_28 ) )
V_61 -> V_435 = V_421 -> V_435 ;
if ( F_174 ( V_436 , V_28 ) ) {
if ( V_398 -> V_337 )
return - V_31 ;
V_61 -> V_437 = V_421 -> V_437 ;
}
if ( F_174 ( V_438 , V_28 ) )
V_61 -> V_439 =
V_421 -> V_439 ;
if ( F_174 ( V_440 , V_28 ) )
V_61 -> V_441 =
V_421 -> V_441 ;
if ( F_174 ( V_442 , V_28 ) )
V_61 -> V_443 = V_421 -> V_443 ;
if ( F_174 ( V_444 , V_28 ) )
V_61 -> V_445 = V_421 -> V_445 ;
if ( F_174 ( V_446 , V_28 ) )
V_61 -> V_447 =
V_421 -> V_447 ;
if ( F_174 ( V_448 , V_28 ) )
V_61 -> V_449 =
V_421 -> V_449 ;
if ( F_174 ( V_450 , V_28 ) )
V_61 -> V_451 =
V_421 -> V_451 ;
if ( F_174 ( V_452 ,
V_28 ) )
V_61 -> V_453 =
V_421 -> V_453 ;
if ( F_174 ( V_454 , V_28 ) ) {
V_61 -> V_455 = V_421 -> V_455 ;
F_179 ( V_398 ) ;
}
if ( F_174 ( V_456 , V_28 ) ) {
if ( V_421 -> V_457 &&
! ( V_61 -> V_455 > V_458 ) ) {
V_61 -> V_455 = V_459 ;
F_179 ( V_398 ) ;
}
V_61 -> V_457 =
V_421 -> V_457 ;
}
if ( F_174 ( V_460 , V_28 ) )
V_61 -> V_461 =
V_421 -> V_461 ;
if ( F_174 ( V_462 , V_28 ) )
V_61 -> V_463 = V_421 -> V_463 ;
if ( F_174 ( V_464 , V_28 ) ) {
if ( ! F_128 ( & V_13 -> V_10 -> V_107 , V_465 ) )
return - V_466 ;
V_61 -> V_467 = V_421 -> V_467 ;
}
if ( F_174 ( V_468 , V_28 ) ) {
V_61 -> V_469 = V_421 -> V_469 ;
V_13 -> V_27 . V_215 . V_470 = V_421 -> V_469 ;
F_90 ( V_13 , V_471 ) ;
}
if ( F_174 ( V_472 , V_28 ) )
V_61 -> V_473 =
V_421 -> V_473 ;
if ( F_174 ( V_474 , V_28 ) )
V_61 -> V_475 =
V_421 -> V_475 ;
if ( F_174 ( V_476 , V_28 ) )
V_61 -> V_477 =
V_421 -> V_477 ;
if ( F_174 ( V_478 , V_28 ) ) {
V_61 -> V_278 = V_421 -> V_278 ;
F_180 ( V_13 ) ;
}
if ( F_174 ( V_479 , V_28 ) )
V_61 -> V_480 =
V_421 -> V_480 ;
if ( F_174 ( V_481 , V_28 ) )
V_61 -> V_482 = V_421 -> V_482 ;
F_124 ( V_13 , V_181 ) ;
return 0 ;
}
static int F_181 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_394 * V_61 ,
const struct V_399 * V_400 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_397 * V_398 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_398 -> V_277 , V_61 , sizeof( struct V_394 ) ) ;
V_14 = F_175 ( V_398 , V_400 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_200 = V_202 ;
V_13 -> V_207 = V_13 -> V_10 -> V_208 ;
F_17 ( & V_13 -> V_10 -> V_151 ) ;
V_14 = F_76 ( V_13 , & V_400 -> V_149 ,
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
struct V_483 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_291 V_292 ;
T_1 V_180 = 0 ;
if ( ! F_79 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) )
return - V_65 ;
V_292 = F_62 ( V_13 ) ;
if ( V_8 -> V_484 >= 0 ) {
V_13 -> V_27 . V_215 . V_484 = V_8 -> V_484 ;
V_180 |= V_485 ;
}
if ( V_8 -> V_486 >= 0 ) {
V_13 -> V_27 . V_215 . V_486 =
V_8 -> V_486 ;
V_180 |= V_487 ;
}
if ( ! V_13 -> V_27 . V_215 . V_488 &&
V_292 == V_489 ) {
V_13 -> V_27 . V_215 . V_488 = true ;
V_180 |= V_490 ;
}
if ( V_8 -> V_491 >= 0 ) {
V_13 -> V_27 . V_215 . V_488 =
V_8 -> V_491 ;
V_180 |= V_490 ;
}
if ( V_8 -> V_420 ) {
F_129 ( & V_13 -> V_27 . V_215 . V_149 ,
V_2 -> V_126 [ V_292 ] ,
V_8 -> V_420 ,
V_8 -> V_492 ,
& V_13 -> V_27 . V_215 . V_420 ) ;
V_180 |= V_493 ;
}
if ( V_8 -> V_494 >= 0 ) {
if ( V_8 -> V_494 )
V_13 -> V_6 |= V_495 ;
else
V_13 -> V_6 &= ~ V_495 ;
F_12 ( V_13 ) ;
}
if ( V_8 -> V_469 >= 0 ) {
V_13 -> V_27 . V_215 . V_470 =
( T_2 ) V_8 -> V_469 ;
V_180 |= V_471 ;
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
struct V_496 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_497 V_498 ;
if ( ! V_10 -> V_499 -> V_500 )
return - V_346 ;
if ( V_10 -> V_107 . V_297 < V_298 )
return - V_346 ;
memset ( & V_498 , 0 , sizeof( V_498 ) ) ;
V_498 . V_501 = V_8 -> V_501 ;
V_498 . V_502 = V_8 -> V_503 ;
V_498 . V_504 = V_8 -> V_505 ;
V_498 . V_506 = V_8 -> V_506 ;
V_498 . V_507 = false ;
V_13 -> V_508 [ V_8 -> V_509 ] = V_498 ;
if ( F_187 ( V_10 , V_13 , V_8 -> V_509 , & V_498 ) ) {
F_188 ( V_10 -> V_107 . V_2 ,
L_2 ,
V_8 -> V_509 ) ;
return - V_49 ;
}
F_90 ( V_13 , V_510 ) ;
return 0 ;
}
static int F_189 ( struct V_2 * V_2 ,
struct V_511 * V_512 )
{
return F_190 ( F_2 ( V_2 ) , V_512 ) ;
}
static int F_191 ( struct V_2 * V_2 )
{
return F_192 ( F_2 ( V_2 ) ) ;
}
static int F_193 ( struct V_2 * V_2 ,
struct V_513 * V_514 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_514 -> V_11 ) ;
switch ( F_194 ( & V_13 -> V_27 ) ) {
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
if ( V_13 -> V_16 . V_166 . V_182 &&
( ! ( V_2 -> V_516 & V_517 ) ||
! ( V_514 -> V_6 & V_518 ) ) )
return - V_346 ;
break;
default:
return - V_346 ;
}
return F_195 ( V_13 , V_514 ) ;
}
static void F_196 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_197 ( F_2 ( V_2 ) ) ;
}
static int
F_198 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_519 * V_514 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_499 -> V_520 )
return - V_346 ;
return F_199 ( V_13 , V_514 ) ;
}
static int
F_200 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_499 -> V_521 )
return - V_346 ;
return F_201 ( V_10 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_522 * V_514 )
{
return F_203 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_523 * V_514 )
{
return F_205 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_524 * V_514 )
{
return F_207 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_525 * V_514 )
{
return F_209 ( F_9 ( V_19 ) , V_514 ) ;
}
static int F_210 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_526 * V_8 )
{
return F_211 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_212 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_213 ( F_9 ( V_19 ) ) ;
}
static int F_214 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_527 * V_400 )
{
return F_215 ( F_9 ( V_19 ) , V_400 ) ;
}
static int F_216 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_217 ( F_9 ( V_19 ) ) ;
}
static int F_218 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_112 [ V_528 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_215 . V_419 , V_112 ,
sizeof( int ) * V_528 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 , T_1 V_180 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_180 & V_529 ) {
F_220 ( V_10 ) ;
V_14 = F_221 ( V_10 , V_2 -> V_530 ) ;
if ( V_14 ) {
F_220 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_180 & V_531 ) ||
( V_180 & V_532 ) ) {
T_6 V_533 ;
V_533 = V_180 & V_531 ?
V_2 -> V_533 : - 1 ;
V_14 = F_222 ( V_10 , V_533 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_180 & V_534 ) {
V_14 = F_223 ( V_10 , V_2 -> V_535 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_180 & V_536 ) {
if ( V_2 -> V_537 > V_538 )
return - V_49 ;
V_10 -> V_107 . V_61 . V_539 = V_2 -> V_537 ;
}
if ( V_180 & V_540 ) {
if ( V_2 -> V_541 > V_538 )
return - V_49 ;
V_10 -> V_107 . V_61 . V_542 = V_2 -> V_541 ;
}
if ( V_180 &
( V_536 | V_540 ) )
F_77 ( V_10 , V_543 ) ;
return 0 ;
}
static int F_224 ( struct V_2 * V_2 ,
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
V_13 -> V_549 = F_225 ( V_545 ) ;
break;
}
if ( V_546 != V_13 -> V_27 . V_215 . V_553 ) {
V_547 = true ;
V_13 -> V_27 . V_215 . V_553 = V_546 ;
}
F_226 ( V_13 , V_547 ) ;
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
V_10 -> V_549 = F_225 ( V_545 ) ;
break;
}
F_17 ( & V_10 -> V_152 ) ;
F_87 (sdata, &local->interfaces, list) {
V_13 -> V_549 = V_10 -> V_549 ;
if ( V_546 != V_13 -> V_27 . V_215 . V_553 )
V_547 = true ;
V_13 -> V_27 . V_215 . V_553 = V_546 ;
}
F_87 (sdata, &local->interfaces, list)
F_226 ( V_13 , V_547 ) ;
F_19 ( & V_10 -> V_152 ) ;
return 0 ;
}
static int F_227 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_554 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_499 -> V_555 )
return F_228 ( V_10 , V_13 , V_554 ) ;
if ( ! V_10 -> V_153 )
* V_554 = V_10 -> V_107 . V_61 . V_556 ;
else
* V_554 = V_13 -> V_27 . V_215 . V_557 ;
return 0 ;
}
static int F_229 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_143 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_558 . V_559 , V_143 , V_144 ) ;
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
struct V_560 * V_27 = NULL ;
if ( ! V_10 -> V_499 -> V_561 )
return - V_346 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_562 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_499 -> V_561 ( & V_10 -> V_107 , V_27 , V_170 , V_169 ) ;
}
static int F_233 ( struct V_2 * V_2 ,
struct V_249 * V_250 ,
struct V_563 * V_258 ,
void * V_170 , int V_169 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_499 -> V_564 )
return - V_346 ;
return V_10 -> V_499 -> V_564 ( & V_10 -> V_107 , V_250 , V_258 , V_170 , V_169 ) ;
}
int F_234 ( struct V_12 * V_13 ,
enum V_565 V_200 )
{
struct V_38 * V_24 ;
enum V_565 V_566 ;
if ( F_36 ( V_13 -> V_27 . type != V_70 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_215 . V_149 . V_567 == V_568 )
return 0 ;
V_566 = V_13 -> V_16 . V_166 . V_353 ;
V_13 -> V_16 . V_166 . V_353 = V_200 ;
if ( V_566 == V_200 ||
V_200 == V_569 )
return 0 ;
if ( ! F_235 ( & V_13 -> V_16 . V_166 . V_351 ) ) {
V_13 -> V_200 = V_200 ;
F_236 ( & V_13 -> V_10 -> V_107 , & V_13 -> V_570 ) ;
return 0 ;
}
F_149 ( V_13 ,
L_3 ,
V_200 , F_235 ( & V_13 -> V_16 . V_166 . V_351 ) ) ;
F_17 ( & V_13 -> V_10 -> V_63 ) ;
F_87 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_350 != & V_13 -> V_16 . V_166 )
continue;
if ( F_148 ( V_24 ) == 1 )
continue;
if ( F_33 ( V_24 , V_571 ) &&
! F_237 ( V_24 -> V_352 ,
V_200 ) ) {
F_149 ( V_13 , L_4 ,
V_24 -> V_24 . V_143 ) ;
continue;
}
if ( ! F_33 ( V_24 , V_268 ) )
continue;
F_149 ( V_13 , L_5 , V_24 -> V_24 . V_143 ) ;
F_150 ( V_13 , V_200 , V_24 -> V_24 . V_143 ,
V_13 -> V_27 . V_215 . V_354 ) ;
}
F_19 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_200 = V_200 ;
F_236 ( & V_13 -> V_10 -> V_107 , & V_13 -> V_570 ) ;
return 0 ;
}
int F_238 ( struct V_12 * V_13 ,
enum V_565 V_200 )
{
const T_3 * V_166 ;
enum V_565 V_566 ;
int V_14 ;
struct V_38 * V_24 ;
bool V_572 = false ;
F_239 ( & V_13 -> V_11 . V_151 ) ;
if ( F_36 ( V_13 -> V_27 . type != V_25 ) )
return - V_49 ;
V_566 = V_13 -> V_16 . V_26 . V_353 ;
V_13 -> V_16 . V_26 . V_353 = V_200 ;
if ( V_566 == V_200 &&
V_200 != V_569 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_573 ||
V_13 -> V_27 . V_215 . V_149 . V_567 == V_568 )
return 0 ;
V_166 = V_13 -> V_16 . V_26 . V_573 -> V_354 ;
F_43 () ;
F_240 (sta, &sdata->local->sta_list, list) {
if ( ! V_24 -> V_24 . V_331 || V_24 -> V_13 != V_13 || ! V_24 -> V_574 ||
! F_33 ( V_24 , V_268 ) )
continue;
V_572 = true ;
break;
}
F_53 () ;
if ( V_200 == V_569 ) {
if ( V_572 || ! V_13 -> V_16 . V_26 . V_575 )
V_200 = V_202 ;
else
V_200 = V_206 ;
}
V_14 = F_150 ( V_13 , V_200 ,
V_166 , V_166 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_353 = V_566 ;
else if ( V_200 != V_202 && V_572 )
F_241 ( V_13 ) ;
return V_14 ;
}
static int F_242 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_576 , int V_577 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_68 ( V_19 -> V_147 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_346 ;
if ( ! F_128 ( & V_10 -> V_107 , V_578 ) )
return - V_346 ;
if ( V_576 == V_13 -> V_16 . V_26 . V_575 &&
V_577 == V_10 -> V_579 )
return 0 ;
V_13 -> V_16 . V_26 . V_575 = V_576 ;
V_10 -> V_579 = V_577 ;
F_243 ( V_13 ) ;
F_238 ( V_13 , V_13 -> V_16 . V_26 . V_353 ) ;
F_244 ( V_13 ) ;
if ( F_128 ( & V_10 -> V_107 , V_580 ) )
F_77 ( V_10 , V_581 ) ;
F_151 ( V_10 ) ;
F_152 ( V_13 ) ;
return 0 ;
}
static int F_245 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_582 , T_1 V_583 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_560 * V_27 = & V_13 -> V_27 ;
struct V_584 * V_215 = & V_27 -> V_215 ;
if ( V_582 == V_215 -> V_585 &&
V_583 == V_215 -> V_586 )
return 0 ;
if ( V_13 -> V_27 . V_587 & V_588 &&
! ( V_13 -> V_27 . V_587 & V_589 ) )
return - V_346 ;
V_215 -> V_585 = V_582 ;
V_215 -> V_586 = V_583 ;
V_13 -> V_16 . V_26 . V_590 = 0 ;
if ( V_13 -> V_16 . V_26 . V_573 &&
V_13 -> V_27 . V_587 & V_589 )
F_90 ( V_13 , V_591 ) ;
return 0 ;
}
static int F_246 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_143 ,
const struct V_592 * V_28 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_68 ( V_19 -> V_147 ) ;
int V_593 , V_20 ;
if ( ! F_13 ( V_13 ) )
return - V_43 ;
if ( F_128 ( & V_10 -> V_107 , V_594 ) ) {
V_20 = F_247 ( V_10 , V_13 , V_28 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_593 = 0 ; V_593 < V_528 ; V_593 ++ ) {
struct V_122 * V_123 = V_2 -> V_126 [ V_593 ] ;
int V_595 ;
V_13 -> V_596 [ V_593 ] = V_28 -> V_255 [ V_593 ] . V_129 ;
memcpy ( V_13 -> V_597 [ V_593 ] , V_28 -> V_255 [ V_593 ] . V_598 ,
sizeof( V_28 -> V_255 [ V_593 ] . V_598 ) ) ;
memcpy ( V_13 -> V_599 [ V_593 ] ,
V_28 -> V_255 [ V_593 ] . V_600 ,
sizeof( V_28 -> V_255 [ V_593 ] . V_600 ) ) ;
V_13 -> V_601 [ V_593 ] = false ;
V_13 -> V_602 [ V_593 ] = false ;
if ( ! V_123 )
continue;
for ( V_595 = 0 ; V_595 < V_603 ; V_595 ++ ) {
if ( ~ V_13 -> V_597 [ V_593 ] [ V_595 ] ) {
V_13 -> V_601 [ V_593 ] = true ;
break;
}
}
for ( V_595 = 0 ; V_595 < V_604 ; V_595 ++ ) {
if ( ~ V_13 -> V_599 [ V_593 ] [ V_595 ] ) {
V_13 -> V_602 [ V_593 ] = true ;
break;
}
}
}
return 0 ;
}
static int F_248 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_148 * V_149 ,
T_1 V_605 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_17 ( & V_10 -> V_151 ) ;
if ( ! F_249 ( & V_10 -> V_606 ) || V_10 -> V_607 ) {
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
F_251 ( V_605 ) ) ;
V_66:
F_19 ( & V_10 -> V_151 ) ;
return V_14 ;
}
static struct V_175 *
F_252 ( struct V_175 * V_182 )
{
struct V_175 * V_608 ;
T_3 * V_609 ;
int V_169 ;
V_169 = V_182 -> V_184 + V_182 -> V_186 + V_182 -> V_610 +
V_182 -> V_611 + V_182 -> V_612 +
V_182 -> V_191 ;
V_608 = F_80 ( sizeof( * V_608 ) + V_169 , V_167 ) ;
if ( ! V_608 )
return NULL ;
V_609 = ( T_3 * ) ( V_608 + 1 ) ;
if ( V_182 -> V_184 ) {
V_608 -> V_184 = V_182 -> V_184 ;
V_608 -> V_183 = V_609 ;
memcpy ( V_609 , V_182 -> V_183 , V_182 -> V_184 ) ;
V_609 += V_182 -> V_184 ;
}
if ( V_182 -> V_186 ) {
V_608 -> V_186 = V_182 -> V_186 ;
V_608 -> V_185 = V_609 ;
memcpy ( V_609 , V_182 -> V_185 , V_182 -> V_186 ) ;
V_609 += V_182 -> V_186 ;
}
if ( V_182 -> V_610 ) {
V_608 -> V_610 = V_182 -> V_610 ;
V_608 -> V_613 = V_609 ;
memcpy ( V_609 , V_182 -> V_613 , V_182 -> V_610 ) ;
V_609 += V_182 -> V_610 ;
}
if ( V_182 -> V_611 ) {
V_608 -> V_611 = V_182 -> V_611 ;
V_608 -> V_614 = V_609 ;
memcpy ( V_609 , V_182 -> V_614 , V_182 -> V_611 ) ;
V_609 += V_182 -> V_611 ;
}
if ( V_182 -> V_612 ) {
V_608 -> V_612 = V_182 -> V_612 ;
V_608 -> V_615 = V_609 ;
memcpy ( V_609 , V_182 -> V_615 , V_182 -> V_612 ) ;
V_609 += V_182 -> V_612 ;
}
if ( V_182 -> V_191 ) {
V_608 -> V_191 = V_182 -> V_191 ;
V_182 -> V_163 = V_609 ;
memcpy ( V_609 , V_182 -> V_163 , V_182 -> V_191 ) ;
V_609 += V_182 -> V_191 ;
}
return V_608 ;
}
void F_253 ( struct V_560 * V_27 )
{
struct V_12 * V_13 = F_254 ( V_27 ) ;
F_236 ( & V_13 -> V_10 -> V_107 ,
& V_13 -> V_616 ) ;
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
if ( V_13 -> V_617 ) {
if ( V_13 -> V_618 )
return 0 ;
return F_259 ( V_13 ) ;
}
if ( ! F_72 ( & V_13 -> V_27 . V_215 . V_149 ,
& V_13 -> V_619 ) )
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
F_261 ( V_13 -> V_19 , & V_13 -> V_619 ) ;
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
void F_265 ( struct V_620 * V_621 )
{
struct V_12 * V_13 =
F_176 ( V_621 , struct V_12 ,
V_616 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_243 ( V_13 ) ;
F_17 ( & V_10 -> V_151 ) ;
F_17 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_232 )
goto V_622;
if ( ! F_13 ( V_13 ) )
goto V_622;
F_262 ( V_13 ) ;
V_622:
F_19 ( & V_10 -> V_32 ) ;
F_19 ( & V_10 -> V_151 ) ;
F_244 ( V_13 ) ;
}
static int F_266 ( struct V_12 * V_13 ,
struct V_623 * V_8 ,
T_1 * V_180 )
{
struct V_161 V_162 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_166 . V_237 =
F_252 ( & V_8 -> V_624 ) ;
if ( ! V_13 -> V_16 . V_166 . V_237 )
return - V_168 ;
if ( V_8 -> V_188 <= 1 )
break;
if ( ( V_8 -> V_190 >
V_625 ) ||
( V_8 -> V_173 >
V_625 ) )
return - V_49 ;
V_162 . V_189 = V_8 -> V_189 ;
V_162 . V_172 = V_8 -> V_172 ;
V_162 . V_190 = V_8 -> V_190 ;
V_162 . V_173 = V_8 -> V_173 ;
V_162 . V_188 = V_8 -> V_188 ;
V_14 = F_83 ( V_13 , & V_8 -> V_626 , & V_162 ) ;
if ( V_14 < 0 ) {
F_96 ( V_13 -> V_16 . V_166 . V_237 ) ;
return V_14 ;
}
* V_180 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_215 . V_627 )
return - V_49 ;
if ( V_8 -> V_149 . V_567 != V_13 -> V_16 . V_628 . V_149 . V_567 )
return - V_49 ;
switch ( V_8 -> V_149 . V_567 ) {
case V_629 :
if ( F_267 ( & V_8 -> V_149 ) !=
F_267 ( & V_13 -> V_16 . V_628 . V_149 ) )
return - V_49 ;
case V_630 :
case V_631 :
case V_568 :
case V_632 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_628 . V_149 . V_633 -> V_292 !=
V_8 -> V_149 . V_633 -> V_292 )
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
struct V_397 * V_398 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_149 . V_567 != V_13 -> V_27 . V_215 . V_149 . V_567 )
return - V_49 ;
if ( V_13 -> V_27 . V_215 . V_149 . V_633 -> V_292 !=
V_8 -> V_149 . V_633 -> V_292 )
return - V_49 ;
if ( V_398 -> V_634 == V_635 ) {
V_398 -> V_634 = V_636 ;
if ( ! V_398 -> V_637 )
V_398 -> V_637 = 1 ;
else
V_398 -> V_637 ++ ;
}
if ( V_8 -> V_188 > 1 ) {
V_14 = F_270 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_398 -> V_634 = V_635 ;
return V_14 ;
}
* V_180 |= V_14 ;
}
if ( V_398 -> V_634 == V_636 )
F_269 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_346 ;
}
return 0 ;
}
static int
F_271 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_623 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_638 V_639 ;
struct V_640 * V_61 ;
struct V_641 * V_642 ;
T_1 V_180 = 0 ;
int V_14 ;
F_93 ( V_13 ) ;
F_239 ( & V_10 -> V_151 ) ;
if ( ! F_249 ( & V_10 -> V_606 ) || V_10 -> V_607 )
return - V_31 ;
if ( V_13 -> V_11 . V_241 )
return - V_31 ;
if ( F_72 ( & V_8 -> V_149 ,
& V_13 -> V_27 . V_215 . V_149 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_232 )
return - V_31 ;
F_17 ( & V_10 -> V_32 ) ;
V_61 = F_73 ( V_13 -> V_27 . V_643 ,
F_74 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_95;
}
V_642 = F_176 ( V_61 , struct V_641 , V_61 ) ;
if ( ! V_642 ) {
V_14 = - V_31 ;
goto V_95;
}
V_639 . V_644 = 0 ;
V_639 . V_645 = 0 ;
V_639 . V_646 = V_8 -> V_646 ;
V_639 . V_149 = V_8 -> V_149 ;
V_639 . V_188 = V_8 -> V_188 ;
V_14 = F_272 ( V_13 , & V_639 ) ;
if ( V_14 )
goto V_95;
V_14 = F_273 ( V_13 , & V_8 -> V_149 ,
V_642 -> V_647 ,
V_8 -> V_648 ) ;
if ( V_14 )
goto V_95;
V_14 = F_18 ( V_13 , NULL , V_642 -> V_647 , 0 ) ;
if ( V_14 ) {
F_274 ( V_13 ) ;
goto V_95;
}
V_14 = F_266 ( V_13 , V_8 , & V_180 ) ;
if ( V_14 ) {
F_274 ( V_13 ) ;
goto V_95;
}
V_13 -> V_619 = V_8 -> V_149 ;
V_13 -> V_235 = V_8 -> V_646 ;
V_13 -> V_27 . V_232 = true ;
if ( V_13 -> V_235 )
F_275 ( V_10 , V_13 ,
V_236 ) ;
F_276 ( V_13 -> V_19 , & V_13 -> V_619 ,
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
int V_638 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_623 * V_8 )
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
V_10 -> V_649 ++ ;
if ( F_52 ( V_10 -> V_649 == 0 ) )
V_10 -> V_649 ++ ;
return V_10 -> V_649 ;
}
int F_279 ( struct V_9 * V_10 , struct V_249 * V_250 ,
T_4 * V_89 , T_8 V_650 )
{
unsigned long V_651 ;
struct V_249 * V_652 ;
int V_653 ;
V_652 = F_280 ( V_250 , V_650 ) ;
if ( ! V_652 )
return - V_168 ;
F_281 ( & V_10 -> V_654 , V_651 ) ;
V_653 = F_282 ( & V_10 -> V_655 , V_652 ,
1 , 0x10000 , V_656 ) ;
F_283 ( & V_10 -> V_654 , V_651 ) ;
if ( V_653 < 0 ) {
F_284 ( V_652 ) ;
return - V_168 ;
}
F_285 ( V_250 ) -> V_657 = V_653 ;
* V_89 = F_278 ( V_10 ) ;
F_285 ( V_652 ) -> V_658 . V_89 = * V_89 ;
return 0 ;
}
static void F_286 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_659 , bool V_660 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_659 ) {
case V_661 | V_662 :
if ( V_660 ) {
V_10 -> V_663 ++ ;
V_13 -> V_27 . V_663 ++ ;
} else {
if ( V_10 -> V_663 )
V_10 -> V_663 -- ;
if ( V_13 -> V_27 . V_663 )
V_13 -> V_27 . V_663 -- ;
}
if ( ! V_10 -> V_156 )
break;
if ( V_13 -> V_27 . V_663 == 1 )
F_287 ( V_10 , V_13 , V_664 ,
V_664 ) ;
else if ( V_13 -> V_27 . V_663 == 0 )
F_287 ( V_10 , V_13 , 0 ,
V_664 ) ;
F_15 ( V_10 ) ;
break;
default:
break;
}
}
static int F_288 ( struct V_2 * V_2 , T_1 V_665 , T_1 V_666 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_667 )
return - V_346 ;
return F_289 ( V_10 , V_665 , V_666 ) ;
}
static int F_290 ( struct V_2 * V_2 , T_1 * V_665 , T_1 * V_666 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_291 ( V_10 , V_665 , V_666 ) ;
}
static int F_292 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_668 * V_170 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_499 -> V_669 )
return - V_346 ;
F_293 ( V_10 , V_13 , V_170 ) ;
return 0 ;
}
static int F_294 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_670 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_671 * V_672 ;
struct V_249 * V_250 ;
int V_179 = sizeof( * V_672 ) ;
T_9 V_673 ;
bool V_674 ;
struct V_675 * V_676 ;
struct V_38 * V_24 ;
struct V_640 * V_643 ;
enum V_291 V_292 ;
int V_20 ;
F_17 ( & V_10 -> V_151 ) ;
F_43 () ;
V_643 = F_44 ( V_13 -> V_27 . V_643 ) ;
if ( F_52 ( ! V_643 ) ) {
V_20 = - V_49 ;
goto V_622;
}
V_292 = V_643 -> V_677 . V_633 -> V_292 ;
V_24 = F_32 ( V_13 , V_670 ) ;
if ( V_24 ) {
V_674 = V_24 -> V_24 . V_299 ;
} else {
V_20 = - V_678 ;
goto V_622;
}
if ( V_674 ) {
V_673 = F_295 ( V_679 |
V_680 |
V_681 ) ;
} else {
V_179 -= 2 ;
V_673 = F_295 ( V_679 |
V_682 |
V_681 ) ;
}
V_250 = F_107 ( V_10 -> V_107 . V_683 + V_179 ) ;
if ( ! V_250 ) {
V_20 = - V_168 ;
goto V_622;
}
V_250 -> V_19 = V_19 ;
F_296 ( V_250 , V_10 -> V_107 . V_683 ) ;
V_672 = ( void * ) F_108 ( V_250 , V_179 ) ;
V_672 -> V_684 = V_673 ;
V_672 -> V_685 = 0 ;
memcpy ( V_672 -> V_686 , V_24 -> V_24 . V_143 , V_144 ) ;
memcpy ( V_672 -> V_687 , V_13 -> V_27 . V_143 , V_144 ) ;
memcpy ( V_672 -> V_688 , V_13 -> V_27 . V_143 , V_144 ) ;
V_672 -> V_689 = 0 ;
V_676 = F_285 ( V_250 ) ;
V_676 -> V_6 |= V_690 |
V_691 ;
V_676 -> V_292 = V_292 ;
F_297 ( V_250 , V_692 ) ;
V_250 -> V_693 = 7 ;
if ( V_674 )
V_672 -> V_694 = F_295 ( 7 ) ;
V_20 = F_279 ( V_10 , V_250 , V_89 , V_656 ) ;
if ( V_20 ) {
F_284 ( V_250 ) ;
goto V_622;
}
F_298 () ;
F_299 ( V_13 , V_24 , V_250 ) ;
F_300 () ;
V_20 = 0 ;
V_622:
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
struct V_640 * V_643 ;
int V_20 = - V_695 ;
F_43 () ;
V_643 = F_44 ( V_13 -> V_27 . V_643 ) ;
if ( V_643 ) {
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
static void F_302 ( struct V_2 * V_2 , bool V_576 )
{
F_303 ( F_2 ( V_2 ) , V_576 ) ;
}
static int F_304 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_696 * V_697 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_698 * V_699 , * V_700 ;
if ( V_697 ) {
V_699 = F_80 ( sizeof( * V_699 ) , V_167 ) ;
if ( ! V_699 )
return - V_168 ;
memcpy ( & V_699 -> V_697 , V_697 , sizeof( * V_697 ) ) ;
} else {
V_699 = NULL ;
}
V_700 = F_79 ( V_13 -> V_697 , V_13 ) ;
F_81 ( V_13 -> V_697 , V_699 ) ;
if ( V_700 )
F_82 ( V_700 , V_174 ) ;
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
T_3 V_701 , const T_3 * V_670 , T_3 V_702 ,
T_2 V_703 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_704 * V_705 = & V_13 -> V_16 . V_26 ;
int V_509 = V_706 [ V_702 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_346 ;
if ( ! ( V_13 -> V_707 & F_114 ( V_702 ) ) )
return - V_49 ;
if ( V_705 -> V_708 [ V_509 ] . V_703 )
return - V_31 ;
if ( V_703 ) {
V_705 -> V_708 [ V_509 ] . V_703 = 32 * V_703 ;
V_705 -> V_708 [ V_509 ] . V_701 = V_701 ;
V_705 -> V_708 [ V_509 ] . V_702 = V_702 ;
}
return 0 ;
}
static int F_308 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_701 , const T_3 * V_670 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_704 * V_705 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_509 ;
for ( V_509 = 0 ; V_509 < V_298 ; V_509 ++ ) {
struct V_709 * V_708 = & V_705 -> V_708 [ V_509 ] ;
if ( ! V_708 -> V_703 )
continue;
if ( V_708 -> V_701 != V_701 )
continue;
V_708 -> V_702 = - 1 ;
F_309 () ;
F_310 ( V_10 , V_13 , false ) ;
V_708 -> V_710 = V_711 ;
V_708 -> V_712 = false ;
F_311 ( V_13 ) ;
memset ( V_708 , 0 , sizeof( * V_708 ) ) ;
return 0 ;
}
return - V_65 ;
}
