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
V_90 = F_44 ( & V_42 -> V_61 . V_98 ) ;
V_91 = F_45 ( V_90 ) ;
V_92 = F_46 ( V_90 ) ;
if ( V_42 -> V_6 & V_99 &&
! ( V_42 -> V_61 . V_6 & V_100 ) ) {
F_47 ( V_13 -> V_10 , V_42 , & V_94 ) ;
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
F_48 ( F_49 ( F_50 ( V_94 ) , V_102 ) !=
F_49 ( F_50 ( V_94 ) , V_103 ) ) ;
case V_54 :
case V_55 :
F_48 ( F_49 ( F_50 ( V_94 ) , V_102 ) !=
F_49 ( F_50 ( V_94 ) , V_104 ) ) ;
case V_56 :
case V_57 :
F_48 ( F_49 ( F_50 ( V_94 ) , V_102 ) !=
F_49 ( F_50 ( V_94 ) , V_105 ) ) ;
if ( V_42 -> V_6 & V_99 &&
! ( V_42 -> V_61 . V_6 & V_100 ) ) {
F_47 ( V_13 -> V_10 , V_42 , & V_94 ) ;
memcpy ( V_60 , V_94 . V_102 . V_106 , 6 ) ;
} else {
V_90 = F_44 ( & V_42 -> V_61 . V_98 ) ;
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
if ( F_51 ( V_42 -> V_61 . V_6 & V_100 ) )
break;
F_47 ( V_13 -> V_10 , V_42 , & V_94 ) ;
V_8 . V_60 = V_94 . V_107 . V_60 ;
V_8 . V_59 = V_94 . V_107 . V_59 ;
break;
}
V_8 . V_42 = V_42 -> V_61 . V_42 ;
V_8 . V_58 = V_42 -> V_61 . V_108 ;
F_41 ( V_89 , & V_8 ) ;
V_14 = 0 ;
V_95:
F_52 () ;
return V_14 ;
}
static int F_53 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 , bool V_109 ,
bool V_110 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_54 ( V_13 , V_34 , V_109 , V_110 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_3 V_34 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_56 ( V_13 , V_34 ) ;
return 0 ;
}
void F_57 ( struct V_38 * V_24 ,
const struct V_111 * V_112 ,
struct V_113 * V_114 )
{
V_114 -> V_6 = 0 ;
if ( V_112 -> V_6 & V_115 ) {
V_114 -> V_6 |= V_116 ;
V_114 -> V_117 = V_112 -> V_118 ;
} else if ( V_112 -> V_6 & V_119 ) {
V_114 -> V_6 |= V_120 ;
V_114 -> V_117 = F_58 ( V_112 ) ;
V_114 -> V_121 = F_59 ( V_112 ) ;
} else {
struct V_122 * V_123 ;
int V_124 = F_60 ( & V_24 -> V_13 -> V_27 ) ;
T_2 V_125 ;
V_123 = V_24 -> V_10 -> V_107 . V_2 -> V_126 [
F_61 ( V_24 -> V_13 ) ] ;
V_125 = V_123 -> V_127 [ V_112 -> V_118 ] . V_128 ;
V_114 -> V_129 = F_62 ( V_125 , 1 << V_124 ) ;
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
static int F_63 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_140 , struct V_141 * V_142 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_64 ( V_13 , V_118 ) ;
if ( V_24 ) {
V_20 = 0 ;
memcpy ( V_140 , V_24 -> V_24 . V_143 , V_144 ) ;
F_65 ( V_24 , V_142 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_66 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , struct V_145 * V_146 )
{
struct V_9 * V_10 = F_67 ( V_19 -> V_147 ) ;
return F_68 ( V_10 , V_118 , V_146 ) ;
}
static int F_69 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_140 , struct V_141 * V_142 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_31 ( V_13 , V_140 ) ;
if ( V_24 ) {
V_20 = 0 ;
F_65 ( V_24 , V_142 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_70 ( struct V_2 * V_2 ,
struct V_148 * V_149 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
int V_20 = 0 ;
if ( F_71 ( & V_10 -> V_150 , V_149 ) )
return 0 ;
F_16 ( & V_10 -> V_151 ) ;
F_16 ( & V_10 -> V_152 ) ;
if ( V_10 -> V_153 ) {
V_13 = F_72 (
V_10 -> V_154 ,
F_73 ( & V_10 -> V_152 ) ) ;
if ( V_13 ) {
F_74 ( V_13 ) ;
V_20 = F_75 ( V_13 , V_149 ,
V_155 ) ;
}
} else if ( V_10 -> V_156 == V_10 -> V_157 ) {
V_10 -> V_158 = * V_149 ;
F_76 ( V_10 , 0 ) ;
}
if ( V_20 == 0 )
V_10 -> V_150 = * V_149 ;
F_18 ( & V_10 -> V_152 ) ;
F_18 ( & V_10 -> V_151 ) ;
return V_20 ;
}
static int F_77 ( struct V_12 * V_13 ,
const T_3 * V_159 , T_5 V_160 ,
const struct V_161 * V_162 )
{
struct V_163 * V_164 , * V_165 ;
if ( ! V_159 || ! V_160 )
return 1 ;
V_165 = F_78 ( V_13 -> V_16 . V_166 . V_163 , V_13 ) ;
V_164 = F_79 ( sizeof( struct V_163 ) + V_160 , V_167 ) ;
if ( ! V_164 )
return - V_168 ;
V_164 -> V_169 = V_160 ;
memcpy ( V_164 -> V_170 , V_159 , V_160 ) ;
if ( V_162 )
memcpy ( V_164 -> V_171 , V_162 -> V_172 ,
V_162 -> V_173 *
sizeof( V_164 -> V_171 [ 0 ] ) ) ;
F_80 ( V_13 -> V_16 . V_166 . V_163 , V_164 ) ;
if ( V_165 )
F_81 ( V_165 , V_174 ) ;
return 0 ;
}
static int F_82 ( struct V_12 * V_13 ,
struct V_175 * V_8 ,
const struct V_161 * V_162 )
{
struct V_176 * V_164 , * V_165 ;
int V_177 , V_178 ;
int V_179 , V_14 ;
T_1 V_180 = V_181 ;
V_165 = F_78 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
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
V_164 = F_79 ( V_179 , V_167 ) ;
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
V_14 = F_77 ( V_13 , V_8 -> V_163 ,
V_8 -> V_191 , V_162 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
V_180 |= V_192 ;
F_80 ( V_13 -> V_16 . V_166 . V_182 , V_164 ) ;
if ( V_165 )
F_81 ( V_165 , V_174 ) ;
return V_180 ;
}
static int F_83 ( struct V_2 * V_2 , struct V_18 * V_19 ,
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
V_165 = F_78 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
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
F_16 ( & V_10 -> V_151 ) ;
V_14 = F_75 ( V_13 , & V_8 -> V_149 ,
V_209 ) ;
if ( ! V_14 )
F_84 ( V_13 , false ) ;
F_18 ( & V_10 -> V_151 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_210 = V_8 -> V_211 . V_212 ;
V_13 -> V_213 = V_8 -> V_211 . V_213 ;
V_13 -> V_214 = F_85 ( V_13 -> V_10 ,
& V_8 -> V_211 ,
V_13 -> V_27 . type ) ;
F_86 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_23 -> V_210 =
V_8 -> V_211 . V_212 ;
V_23 -> V_213 =
V_8 -> V_211 . V_213 ;
V_23 -> V_214 =
F_85 ( V_13 -> V_10 ,
& V_8 -> V_211 ,
V_23 -> V_27 . type ) ;
}
V_13 -> V_27 . V_215 . V_216 = V_8 -> V_217 ;
V_13 -> V_27 . V_215 . V_218 = V_8 -> V_218 ;
V_13 -> V_27 . V_215 . V_219 = true ;
V_13 -> V_27 . V_215 . V_220 = V_8 -> V_220 ;
if ( V_8 -> V_220 )
memcpy ( V_13 -> V_27 . V_215 . V_221 , V_8 -> V_221 ,
V_8 -> V_220 ) ;
V_13 -> V_27 . V_215 . V_222 =
( V_8 -> V_222 != V_223 ) ;
memset ( & V_13 -> V_27 . V_215 . V_224 , 0 ,
sizeof( V_13 -> V_27 . V_215 . V_224 ) ) ;
V_13 -> V_27 . V_215 . V_224 . V_225 =
V_8 -> V_226 & V_227 ;
if ( V_8 -> V_228 )
V_13 -> V_27 . V_215 . V_224 . V_225 |=
V_229 ;
V_14 = F_82 ( V_13 , & V_8 -> V_182 , NULL ) ;
if ( V_14 < 0 ) {
F_74 ( V_13 ) ;
return V_14 ;
}
V_180 |= V_14 ;
V_14 = F_87 ( V_13 -> V_10 , V_13 ) ;
if ( V_14 ) {
V_165 = F_78 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( V_165 )
F_81 ( V_165 , V_174 ) ;
F_11 ( V_13 -> V_16 . V_166 . V_182 , NULL ) ;
F_74 ( V_13 ) ;
return V_14 ;
}
F_88 ( V_10 , V_13 ) ;
F_89 ( V_13 , V_180 ) ;
F_90 ( V_19 ) ;
F_86 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_90 ( V_23 -> V_19 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_175 * V_8 )
{
struct V_12 * V_13 ;
struct V_176 * V_165 ;
int V_14 ;
V_13 = F_9 ( V_19 ) ;
F_92 ( V_13 ) ;
if ( V_13 -> V_27 . V_230 )
return - V_31 ;
V_165 = F_78 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( ! V_165 )
return - V_65 ;
V_14 = F_82 ( V_13 , V_8 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
F_89 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_93 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_12 * V_23 ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_176 * V_231 ;
struct V_163 * V_232 ;
struct V_148 V_149 ;
F_92 ( V_13 ) ;
V_231 = F_78 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) ;
if ( ! V_231 )
return - V_65 ;
V_232 = F_78 ( V_13 -> V_16 . V_166 . V_163 , V_13 ) ;
F_16 ( & V_10 -> V_151 ) ;
V_13 -> V_27 . V_230 = false ;
if ( V_13 -> V_233 ) {
F_94 ( V_10 , V_13 ,
V_234 ) ;
V_13 -> V_233 = false ;
}
F_18 ( & V_10 -> V_151 ) ;
F_95 ( V_13 -> V_16 . V_166 . V_235 ) ;
V_13 -> V_16 . V_166 . V_235 = NULL ;
F_86 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_96 ( V_23 -> V_19 ) ;
F_96 ( V_19 ) ;
F_11 ( V_13 -> V_16 . V_166 . V_182 , NULL ) ;
F_11 ( V_13 -> V_16 . V_166 . V_163 , NULL ) ;
F_81 ( V_231 , V_174 ) ;
if ( V_232 )
F_81 ( V_232 , V_174 ) ;
V_13 -> V_16 . V_166 . V_236 = V_202 ;
F_97 ( V_13 , true ) ;
F_98 ( V_13 , true ) ;
V_13 -> V_27 . V_215 . V_219 = false ;
V_13 -> V_27 . V_215 . V_220 = 0 ;
F_99 ( V_237 , & V_13 -> V_238 ) ;
F_89 ( V_13 , V_195 ) ;
if ( V_13 -> V_11 . V_239 ) {
V_149 = V_13 -> V_27 . V_215 . V_149 ;
F_100 ( & V_13 -> V_240 ) ;
F_101 ( V_13 -> V_19 , & V_149 ,
V_241 ,
V_167 ) ;
}
F_102 ( V_13 -> V_10 , V_13 ) ;
V_10 -> V_242 -= F_103 ( & V_13 -> V_16 . V_166 . V_243 . V_244 ) ;
F_104 ( & V_13 -> V_16 . V_166 . V_243 . V_244 ) ;
F_16 ( & V_10 -> V_151 ) ;
F_84 ( V_13 , true ) ;
F_74 ( V_13 ) ;
F_18 ( & V_10 -> V_151 ) ;
return 0 ;
}
static void F_105 ( struct V_38 * V_24 )
{
struct V_245 * V_246 ;
struct V_247 * V_248 ;
V_248 = F_106 ( sizeof( * V_246 ) ) ;
if ( ! V_248 )
return;
V_246 = (struct V_245 * ) F_107 ( V_248 , sizeof( * V_246 ) ) ;
F_108 ( V_246 -> V_249 ) ;
memcpy ( V_246 -> V_250 , V_24 -> V_24 . V_143 , V_144 ) ;
V_246 -> V_169 = F_109 ( 6 ) ;
V_246 -> V_251 = 0 ;
V_246 -> V_252 = 0x01 ;
V_246 -> V_253 = 0xaf ;
V_246 -> V_254 [ 0 ] = 0x81 ;
V_246 -> V_254 [ 1 ] = 1 ;
V_246 -> V_254 [ 2 ] = 0 ;
V_248 -> V_19 = V_24 -> V_13 -> V_19 ;
V_248 -> V_255 = F_110 ( V_248 , V_24 -> V_13 -> V_19 ) ;
memset ( V_248 -> V_256 , 0 , sizeof( V_248 -> V_256 ) ) ;
F_111 ( V_248 ) ;
}
static int F_112 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
T_1 V_28 , T_1 V_257 )
{
int V_20 ;
if ( V_28 & F_113 ( V_258 ) &&
V_257 & F_113 ( V_258 ) &&
! F_32 ( V_24 , V_259 ) ) {
V_20 = F_114 ( V_24 , V_260 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_113 ( V_261 ) &&
V_257 & F_113 ( V_261 ) &&
! F_32 ( V_24 , V_64 ) ) {
if ( ! F_32 ( V_24 , V_262 ) )
F_115 ( V_24 ) ;
V_20 = F_114 ( V_24 , V_263 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_113 ( V_264 ) ) {
if ( V_257 & F_113 ( V_264 ) )
V_20 = F_114 ( V_24 , V_265 ) ;
else if ( F_32 ( V_24 , V_266 ) )
V_20 = F_114 ( V_24 , V_263 ) ;
else
V_20 = 0 ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_113 ( V_261 ) &&
! ( V_257 & F_113 ( V_261 ) ) &&
F_32 ( V_24 , V_64 ) ) {
V_20 = F_114 ( V_24 , V_260 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_113 ( V_258 ) &&
! ( V_257 & F_113 ( V_258 ) ) &&
F_32 ( V_24 , V_259 ) ) {
V_20 = F_114 ( V_24 , V_267 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static void F_116 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_268 * V_8 )
{
#ifdef F_34
struct V_12 * V_13 = V_24 -> V_13 ;
T_1 V_180 = 0 ;
if ( V_8 -> V_269 & V_270 ) {
switch ( V_8 -> V_271 ) {
case V_272 :
if ( V_24 -> V_74 -> V_271 != V_272 )
V_180 = F_117 ( V_13 ) ;
V_24 -> V_74 -> V_271 = V_8 -> V_271 ;
F_118 ( V_24 ) ;
V_180 |= F_119 ( V_24 ,
V_13 -> V_16 . V_74 . V_273 . V_274 ) ;
break;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
if ( V_24 -> V_74 -> V_271 == V_272 )
V_180 = F_120 ( V_13 ) ;
V_24 -> V_74 -> V_271 = V_8 -> V_271 ;
F_118 ( V_24 ) ;
V_180 |= F_119 ( V_24 ,
V_281 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_282 ) {
case V_283 :
break;
case V_284 :
V_180 |= F_121 ( V_24 ) ;
break;
case V_285 :
V_180 |= F_122 ( V_24 ) ;
break;
}
if ( V_8 -> V_286 )
V_180 |= F_119 ( V_24 ,
V_8 -> V_286 ) ;
F_123 ( V_13 , V_180 ) ;
#endif
}
static int F_124 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_268 * V_8 )
{
int V_20 = 0 ;
struct V_122 * V_123 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_287 V_288 = F_61 ( V_13 ) ;
T_1 V_28 , V_257 ;
V_123 = V_10 -> V_107 . V_2 -> V_126 [ V_288 ] ;
V_28 = V_8 -> V_289 ;
V_257 = V_8 -> V_290 ;
if ( F_29 ( & V_13 -> V_27 ) ) {
if ( V_28 & F_113 ( V_258 ) )
V_28 |= F_113 ( V_261 ) ;
if ( V_257 & F_113 ( V_258 ) )
V_257 |= F_113 ( V_261 ) ;
} else if ( F_32 ( V_24 , V_291 ) ) {
if ( V_257 & F_113 ( V_264 ) ) {
V_257 |= F_113 ( V_258 ) |
F_113 ( V_261 ) ;
V_28 |= F_113 ( V_258 ) |
F_113 ( V_261 ) ;
}
}
if ( V_28 & F_113 ( V_292 ) &&
V_10 -> V_107 . V_293 >= V_294 )
V_24 -> V_24 . V_295 = V_257 & F_113 ( V_292 ) ;
if ( ! F_32 ( V_24 , V_291 ) &&
! ( ( V_28 & F_113 ( V_261 ) ) &&
( V_257 & F_113 ( V_261 ) ) ) ) {
V_20 = F_112 ( V_10 , V_24 , V_28 , V_257 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_113 ( V_296 ) ) {
if ( V_257 & F_113 ( V_296 ) )
F_125 ( V_24 , V_297 ) ;
else
F_126 ( V_24 , V_297 ) ;
}
if ( V_28 & F_113 ( V_298 ) ) {
V_24 -> V_24 . V_67 = ! ! ( V_257 & F_113 ( V_298 ) ) ;
if ( V_257 & F_113 ( V_298 ) )
F_125 ( V_24 , V_71 ) ;
else
F_126 ( V_24 , V_71 ) ;
}
if ( V_28 & F_113 ( V_299 ) ) {
if ( V_257 & F_113 ( V_299 ) )
F_125 ( V_24 , V_291 ) ;
else
F_126 ( V_24 , V_291 ) ;
}
if ( F_32 ( V_24 , V_291 ) &&
! V_13 -> V_16 . V_26 . V_300 &&
V_8 -> V_301 >= 4 &&
V_8 -> V_302 [ 3 ] & V_303 )
F_125 ( V_24 , V_304 ) ;
if ( F_32 ( V_24 , V_291 ) &&
! V_13 -> V_16 . V_26 . V_305 &&
F_127 ( & V_10 -> V_107 , V_306 ) &&
V_8 -> V_301 >= 8 &&
V_8 -> V_302 [ 7 ] & V_307 )
F_125 ( V_24 , V_308 ) ;
if ( V_8 -> V_269 & V_309 ) {
V_24 -> V_24 . V_310 = V_8 -> V_310 ;
V_24 -> V_24 . V_311 = V_8 -> V_311 ;
}
if ( V_8 -> V_301 >= 8 ) {
T_3 V_312 = ( V_8 -> V_302 [ 7 ] &
V_313 ) >> 7 ;
if ( V_8 -> V_301 >= 9 ) {
T_3 V_314 = V_8 -> V_302 [ 8 ] &
V_315 ;
V_314 <<= 1 ;
V_312 |= V_314 ;
}
switch ( V_312 ) {
case 1 :
V_24 -> V_24 . V_316 = 32 ;
break;
case 2 :
V_24 -> V_24 . V_316 = 16 ;
break;
case 3 :
V_24 -> V_24 . V_316 = 8 ;
break;
default:
V_24 -> V_24 . V_316 = 0 ;
}
}
if ( V_8 -> V_317 )
V_24 -> V_24 . V_317 = V_8 -> V_317 ;
if ( V_8 -> V_318 >= 0 )
V_24 -> V_318 = V_8 -> V_318 ;
if ( V_8 -> V_319 ) {
F_128 ( & V_13 -> V_27 . V_215 . V_149 ,
V_123 , V_8 -> V_319 ,
V_8 -> V_320 ,
& V_24 -> V_24 . V_321 [ V_288 ] ) ;
}
if ( V_8 -> V_322 )
F_129 ( V_13 , V_123 ,
V_8 -> V_322 , V_24 ) ;
if ( V_8 -> V_323 )
F_130 ( V_13 , V_123 ,
V_8 -> V_323 , V_24 ) ;
if ( V_8 -> V_324 ) {
F_131 ( V_13 , V_24 ,
V_8 -> V_325 , V_288 ) ;
}
if ( F_29 ( & V_13 -> V_27 ) )
F_116 ( V_10 , V_24 , V_8 ) ;
if ( F_32 ( V_24 , V_291 ) ||
V_257 & F_113 ( V_261 ) ) {
V_20 = F_112 ( V_10 , V_24 , V_28 , V_257 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_132 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_140 ,
struct V_268 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_13 ;
int V_14 ;
int V_326 ;
if ( V_8 -> V_23 ) {
V_13 = F_9 ( V_8 -> V_23 ) ;
if ( V_13 -> V_27 . type != V_21 &&
V_13 -> V_27 . type != V_70 )
return - V_49 ;
} else
V_13 = F_9 ( V_19 ) ;
if ( F_133 ( V_140 , V_13 -> V_27 . V_143 ) )
return - V_49 ;
if ( F_134 ( V_140 ) )
return - V_49 ;
V_24 = F_135 ( V_13 , V_140 , V_167 ) ;
if ( ! V_24 )
return - V_168 ;
if ( V_8 -> V_290 & F_113 ( V_299 ) )
V_24 -> V_24 . V_327 = true ;
V_14 = F_124 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_136 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_32 ( V_24 , V_291 ) &&
F_32 ( V_24 , V_64 ) )
F_115 ( V_24 ) ;
V_326 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_137 ( V_24 ) ;
if ( V_14 ) {
F_52 () ;
return V_14 ;
}
if ( V_326 )
F_105 ( V_24 ) ;
F_52 () ;
return 0 ;
}
static int F_138 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_328 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_140 )
return F_139 ( V_13 , V_8 -> V_140 ) ;
F_140 ( V_13 ) ;
return 0 ;
}
static int F_141 ( struct V_2 * V_2 ,
struct V_18 * V_19 , const T_3 * V_140 ,
struct V_268 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_329 ;
enum V_330 V_331 ;
int V_14 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_31 ( V_13 , V_140 ) ;
if ( ! V_24 ) {
V_14 = - V_65 ;
goto V_332;
}
switch ( V_13 -> V_27 . type ) {
case V_73 :
if ( V_13 -> V_16 . V_74 . V_333 )
V_331 = V_334 ;
else
V_331 = V_335 ;
break;
case V_72 :
V_331 = V_336 ;
break;
case V_25 :
if ( ! F_32 ( V_24 , V_291 ) ) {
V_331 = V_337 ;
break;
}
if ( F_32 ( V_24 , V_266 ) )
V_331 = V_338 ;
else
V_331 = V_339 ;
break;
case V_70 :
case V_21 :
if ( F_32 ( V_24 , V_64 ) )
V_331 = V_340 ;
else
V_331 = V_341 ;
break;
default:
V_14 = - V_342 ;
goto V_332;
}
V_14 = F_142 ( V_2 , V_8 , V_331 ) ;
if ( V_14 )
goto V_332;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_343 = false ;
bool V_344 = false ;
V_329 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_147 -> V_22 ) {
if ( V_329 -> V_16 . V_23 . V_24 ) {
V_14 = - V_31 ;
goto V_332;
}
F_80 ( V_329 -> V_16 . V_23 . V_24 , V_24 ) ;
V_344 = true ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_343 = true ;
}
V_24 -> V_13 = V_329 ;
F_143 ( V_24 ) ;
if ( V_24 -> V_345 == V_265 &&
V_343 != V_344 ) {
if ( V_344 )
F_144 ( & V_24 -> V_13 -> V_346 -> V_347 ) ;
else
F_145 ( & V_24 -> V_13 -> V_346 -> V_347 ) ;
}
F_105 ( V_24 ) ;
}
V_14 = F_124 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_332;
F_18 ( & V_10 -> V_63 ) ;
if ( ( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_348 != V_24 -> V_13 -> V_346 -> V_349 &&
F_32 ( V_24 , V_266 ) &&
F_146 ( V_24 ) != 1 ) {
F_147 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_143 ) ;
F_148 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_346 -> V_349 ,
V_24 -> V_24 . V_143 ,
V_24 -> V_13 -> V_27 . V_215 . V_350 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_289 & F_113 ( V_264 ) ) {
F_149 ( V_10 ) ;
F_150 ( V_13 ) ;
}
return 0 ;
V_332:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_151 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_351 , const T_3 * V_352 )
{
struct V_12 * V_13 ;
struct V_353 * V_354 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_352 ) ;
if ( ! V_24 ) {
F_52 () ;
return - V_65 ;
}
V_354 = F_152 ( V_13 , V_351 ) ;
if ( F_25 ( V_354 ) ) {
F_52 () ;
return F_28 ( V_354 ) ;
}
F_153 ( V_354 , V_24 ) ;
F_52 () ;
return 0 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_351 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_351 )
return F_155 ( V_13 , V_351 ) ;
F_156 ( V_13 ) ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_351 , const T_3 * V_352 )
{
struct V_12 * V_13 ;
struct V_353 * V_354 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_352 ) ;
if ( ! V_24 ) {
F_52 () ;
return - V_65 ;
}
V_354 = F_158 ( V_13 , V_351 ) ;
if ( ! V_354 ) {
F_52 () ;
return - V_65 ;
}
F_153 ( V_354 , V_24 ) ;
F_52 () ;
return 0 ;
}
static void F_159 ( struct V_353 * V_354 , T_3 * V_352 ,
struct V_355 * V_356 )
{
struct V_38 * V_357 = F_43 ( V_354 -> V_352 ) ;
if ( V_357 )
memcpy ( V_352 , V_357 -> V_24 . V_143 , V_144 ) ;
else
F_160 ( V_352 ) ;
memset ( V_356 , 0 , sizeof( * V_356 ) ) ;
V_356 -> V_358 = V_359 ;
V_356 -> V_360 = V_361 |
V_362 |
V_363 |
V_364 |
V_365 |
V_366 |
V_367 ;
V_356 -> V_368 = V_354 -> V_369 . V_370 ;
V_356 -> V_371 = V_354 -> V_371 ;
V_356 -> V_372 = V_354 -> V_372 ;
if ( F_161 ( V_373 , V_354 -> V_374 ) )
V_356 -> V_375 = F_162 ( V_354 -> V_374 - V_373 ) ;
V_356 -> V_376 =
F_162 ( V_354 -> V_376 ) ;
V_356 -> V_377 = V_354 -> V_377 ;
if ( V_354 -> V_6 & V_378 )
V_356 -> V_6 |= V_379 ;
if ( V_354 -> V_6 & V_380 )
V_356 -> V_6 |= V_381 ;
if ( V_354 -> V_6 & V_382 )
V_356 -> V_6 |= V_383 ;
if ( V_354 -> V_6 & V_384 )
V_356 -> V_6 |= V_385 ;
if ( V_354 -> V_6 & V_386 )
V_356 -> V_6 |= V_387 ;
}
static int F_163 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_351 , T_3 * V_352 , struct V_355 * V_356 )
{
struct V_12 * V_13 ;
struct V_353 * V_354 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_354 = F_158 ( V_13 , V_351 ) ;
if ( ! V_354 ) {
F_52 () ;
return - V_65 ;
}
memcpy ( V_351 , V_354 -> V_351 , V_144 ) ;
F_159 ( V_354 , V_352 , V_356 ) ;
F_52 () ;
return 0 ;
}
static int F_164 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_351 , T_3 * V_352 ,
struct V_355 * V_356 )
{
struct V_12 * V_13 ;
struct V_353 * V_354 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_354 = F_165 ( V_13 , V_118 ) ;
if ( ! V_354 ) {
F_52 () ;
return - V_65 ;
}
memcpy ( V_351 , V_354 -> V_351 , V_144 ) ;
F_159 ( V_354 , V_352 , V_356 ) ;
F_52 () ;
return 0 ;
}
static void F_166 ( struct V_353 * V_354 , T_3 * V_388 ,
struct V_355 * V_356 )
{
memset ( V_356 , 0 , sizeof( * V_356 ) ) ;
memcpy ( V_388 , V_354 -> V_388 , V_144 ) ;
V_356 -> V_358 = V_389 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_351 , T_3 * V_388 , struct V_355 * V_356 )
{
struct V_12 * V_13 ;
struct V_353 * V_354 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_354 = F_168 ( V_13 , V_351 ) ;
if ( ! V_354 ) {
F_52 () ;
return - V_65 ;
}
memcpy ( V_351 , V_354 -> V_351 , V_144 ) ;
F_166 ( V_354 , V_388 , V_356 ) ;
F_52 () ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_118 , T_3 * V_351 , T_3 * V_388 ,
struct V_355 * V_356 )
{
struct V_12 * V_13 ;
struct V_353 * V_354 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_354 = F_170 ( V_13 , V_118 ) ;
if ( ! V_354 ) {
F_52 () ;
return - V_65 ;
}
memcpy ( V_351 , V_354 -> V_351 , V_144 ) ;
F_166 ( V_354 , V_388 , V_356 ) ;
F_52 () ;
return 0 ;
}
static int F_171 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_390 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_273 ) , sizeof( struct V_390 ) ) ;
return 0 ;
}
static inline bool F_172 ( enum V_391 V_392 , T_1 V_28 )
{
return ( V_28 >> ( V_392 - 1 ) ) & 0x1 ;
}
static int F_173 ( struct V_393 * V_394 ,
const struct V_395 * V_396 )
{
T_3 * V_397 ;
const T_3 * V_398 ;
struct V_12 * V_13 = F_174 ( V_394 ,
struct V_12 , V_16 . V_74 ) ;
V_397 = NULL ;
V_398 = V_394 -> V_399 ;
if ( V_396 -> V_400 ) {
V_397 = F_175 ( V_396 -> V_399 , V_396 -> V_400 ,
V_167 ) ;
if ( ! V_397 )
return - V_168 ;
}
V_394 -> V_400 = V_396 -> V_400 ;
V_394 -> V_399 = V_397 ;
F_95 ( V_398 ) ;
V_394 -> V_401 = V_396 -> V_401 ;
memcpy ( V_394 -> V_402 , V_396 -> V_402 , V_394 -> V_401 ) ;
V_394 -> V_403 = V_396 -> V_404 ;
V_394 -> V_405 = V_396 -> V_406 ;
V_394 -> V_407 = V_396 -> V_408 ;
V_394 -> V_333 = V_396 -> V_333 ;
V_394 -> V_409 = V_396 -> V_410 ;
V_394 -> V_75 = V_76 ;
if ( V_396 -> V_411 )
V_394 -> V_75 |= V_412 ;
if ( V_396 -> V_413 )
V_394 -> V_75 |= V_414 ;
memcpy ( V_13 -> V_27 . V_215 . V_415 , V_396 -> V_415 ,
sizeof( V_396 -> V_415 ) ) ;
V_13 -> V_27 . V_215 . V_416 = V_396 -> V_416 ;
V_13 -> V_27 . V_215 . V_216 = V_396 -> V_217 ;
V_13 -> V_27 . V_215 . V_218 = V_396 -> V_218 ;
return 0 ;
}
static int F_176 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_390 * V_417 )
{
struct V_390 * V_61 ;
struct V_12 * V_13 ;
struct V_393 * V_394 ;
V_13 = F_9 ( V_19 ) ;
V_394 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_273 ) ;
if ( F_172 ( V_418 , V_28 ) )
V_61 -> V_419 = V_417 -> V_419 ;
if ( F_172 ( V_420 , V_28 ) )
V_61 -> V_421 = V_417 -> V_421 ;
if ( F_172 ( V_422 , V_28 ) )
V_61 -> V_423 = V_417 -> V_423 ;
if ( F_172 ( V_424 , V_28 ) )
V_61 -> V_425 = V_417 -> V_425 ;
if ( F_172 ( V_426 , V_28 ) )
V_61 -> V_427 = V_417 -> V_427 ;
if ( F_172 ( V_428 , V_28 ) )
V_61 -> V_429 = V_417 -> V_429 ;
if ( F_172 ( V_430 , V_28 ) )
V_61 -> V_431 = V_417 -> V_431 ;
if ( F_172 ( V_432 , V_28 ) ) {
if ( V_394 -> V_333 )
return - V_31 ;
V_61 -> V_433 = V_417 -> V_433 ;
}
if ( F_172 ( V_434 , V_28 ) )
V_61 -> V_435 =
V_417 -> V_435 ;
if ( F_172 ( V_436 , V_28 ) )
V_61 -> V_437 =
V_417 -> V_437 ;
if ( F_172 ( V_438 , V_28 ) )
V_61 -> V_439 = V_417 -> V_439 ;
if ( F_172 ( V_440 , V_28 ) )
V_61 -> V_441 = V_417 -> V_441 ;
if ( F_172 ( V_442 , V_28 ) )
V_61 -> V_443 =
V_417 -> V_443 ;
if ( F_172 ( V_444 , V_28 ) )
V_61 -> V_445 =
V_417 -> V_445 ;
if ( F_172 ( V_446 , V_28 ) )
V_61 -> V_447 =
V_417 -> V_447 ;
if ( F_172 ( V_448 ,
V_28 ) )
V_61 -> V_449 =
V_417 -> V_449 ;
if ( F_172 ( V_450 , V_28 ) ) {
V_61 -> V_451 = V_417 -> V_451 ;
F_177 ( V_394 ) ;
}
if ( F_172 ( V_452 , V_28 ) ) {
if ( V_417 -> V_453 &&
! ( V_61 -> V_451 > V_454 ) ) {
V_61 -> V_451 = V_455 ;
F_177 ( V_394 ) ;
}
V_61 -> V_453 =
V_417 -> V_453 ;
}
if ( F_172 ( V_456 , V_28 ) )
V_61 -> V_457 =
V_417 -> V_457 ;
if ( F_172 ( V_458 , V_28 ) )
V_61 -> V_459 = V_417 -> V_459 ;
if ( F_172 ( V_460 , V_28 ) ) {
if ( ! F_127 ( & V_13 -> V_10 -> V_107 , V_461 ) )
return - V_462 ;
V_61 -> V_463 = V_417 -> V_463 ;
}
if ( F_172 ( V_464 , V_28 ) ) {
V_61 -> V_465 = V_417 -> V_465 ;
V_13 -> V_27 . V_215 . V_466 = V_417 -> V_465 ;
F_89 ( V_13 , V_467 ) ;
}
if ( F_172 ( V_468 , V_28 ) )
V_61 -> V_469 =
V_417 -> V_469 ;
if ( F_172 ( V_470 , V_28 ) )
V_61 -> V_471 =
V_417 -> V_471 ;
if ( F_172 ( V_472 , V_28 ) )
V_61 -> V_473 =
V_417 -> V_473 ;
if ( F_172 ( V_474 , V_28 ) ) {
V_61 -> V_274 = V_417 -> V_274 ;
F_178 ( V_13 ) ;
}
if ( F_172 ( V_475 , V_28 ) )
V_61 -> V_476 =
V_417 -> V_476 ;
if ( F_172 ( V_477 , V_28 ) )
V_61 -> V_478 = V_417 -> V_478 ;
F_123 ( V_13 , V_181 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_390 * V_61 ,
const struct V_395 * V_396 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_393 * V_394 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_394 -> V_273 , V_61 , sizeof( struct V_390 ) ) ;
V_14 = F_173 ( V_394 , V_396 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_200 = V_202 ;
V_13 -> V_207 = V_13 -> V_10 -> V_208 ;
F_16 ( & V_13 -> V_10 -> V_151 ) ;
V_14 = F_75 ( V_13 , & V_396 -> V_149 ,
V_209 ) ;
F_18 ( & V_13 -> V_10 -> V_151 ) ;
if ( V_14 )
return V_14 ;
return F_180 ( V_13 ) ;
}
static int F_181 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_182 ( V_13 ) ;
F_16 ( & V_13 -> V_10 -> V_151 ) ;
F_74 ( V_13 ) ;
F_18 ( & V_13 -> V_10 -> V_151 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_479 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_287 V_288 ;
T_1 V_180 = 0 ;
if ( ! F_78 ( V_13 -> V_16 . V_166 . V_182 , V_13 ) )
return - V_65 ;
V_288 = F_61 ( V_13 ) ;
if ( V_8 -> V_480 >= 0 ) {
V_13 -> V_27 . V_215 . V_480 = V_8 -> V_480 ;
V_180 |= V_481 ;
}
if ( V_8 -> V_482 >= 0 ) {
V_13 -> V_27 . V_215 . V_482 =
V_8 -> V_482 ;
V_180 |= V_483 ;
}
if ( ! V_13 -> V_27 . V_215 . V_484 &&
V_288 == V_485 ) {
V_13 -> V_27 . V_215 . V_484 = true ;
V_180 |= V_486 ;
}
if ( V_8 -> V_487 >= 0 ) {
V_13 -> V_27 . V_215 . V_484 =
V_8 -> V_487 ;
V_180 |= V_486 ;
}
if ( V_8 -> V_416 ) {
F_128 ( & V_13 -> V_27 . V_215 . V_149 ,
V_2 -> V_126 [ V_288 ] ,
V_8 -> V_416 ,
V_8 -> V_488 ,
& V_13 -> V_27 . V_215 . V_416 ) ;
V_180 |= V_489 ;
}
if ( V_8 -> V_490 >= 0 ) {
if ( V_8 -> V_490 )
V_13 -> V_6 |= V_491 ;
else
V_13 -> V_6 &= ~ V_491 ;
}
if ( V_8 -> V_465 >= 0 ) {
V_13 -> V_27 . V_215 . V_466 =
( T_2 ) V_8 -> V_465 ;
V_180 |= V_467 ;
}
if ( V_8 -> V_226 >= 0 ) {
V_13 -> V_27 . V_215 . V_224 . V_225 &=
~ V_227 ;
V_13 -> V_27 . V_215 . V_224 . V_225 |=
V_8 -> V_226 & V_227 ;
V_180 |= V_197 ;
}
if ( V_8 -> V_228 > 0 ) {
V_13 -> V_27 . V_215 . V_224 . V_225 |=
V_229 ;
V_180 |= V_197 ;
} else if ( V_8 -> V_228 == 0 ) {
V_13 -> V_27 . V_215 . V_224 . V_225 &=
~ V_229 ;
V_180 |= V_197 ;
}
F_89 ( V_13 , V_180 ) ;
return 0 ;
}
static int F_184 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_492 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_493 V_494 ;
if ( ! V_10 -> V_495 -> V_496 )
return - V_342 ;
if ( V_10 -> V_107 . V_293 < V_294 )
return - V_342 ;
memset ( & V_494 , 0 , sizeof( V_494 ) ) ;
V_494 . V_497 = V_8 -> V_497 ;
V_494 . V_498 = V_8 -> V_499 ;
V_494 . V_500 = V_8 -> V_501 ;
V_494 . V_502 = V_8 -> V_502 ;
V_494 . V_503 = false ;
V_13 -> V_504 [ V_8 -> V_505 ] = V_494 ;
if ( F_185 ( V_10 , V_13 , V_8 -> V_505 , & V_494 ) ) {
F_186 ( V_10 -> V_107 . V_2 ,
L_2 ,
V_8 -> V_505 ) ;
return - V_49 ;
}
F_89 ( V_13 , V_506 ) ;
return 0 ;
}
static int F_187 ( struct V_2 * V_2 ,
struct V_507 * V_508 )
{
return F_188 ( F_2 ( V_2 ) , V_508 ) ;
}
static int F_189 ( struct V_2 * V_2 )
{
return F_190 ( F_2 ( V_2 ) ) ;
}
static int F_191 ( struct V_2 * V_2 ,
struct V_509 * V_510 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_510 -> V_11 ) ;
switch ( F_192 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_72 :
case V_73 :
case V_81 :
case V_78 :
break;
case V_82 :
if ( V_13 -> V_10 -> V_495 -> V_511 )
break;
case V_70 :
if ( V_13 -> V_16 . V_166 . V_182 &&
( ! ( V_2 -> V_512 & V_513 ) ||
! ( V_510 -> V_6 & V_514 ) ) )
return - V_342 ;
break;
default:
return - V_342 ;
}
return F_193 ( V_13 , V_510 ) ;
}
static void F_194 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_195 ( F_2 ( V_2 ) ) ;
}
static int
F_196 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_515 * V_510 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_495 -> V_516 )
return - V_342 ;
return F_197 ( V_13 , V_510 ) ;
}
static int
F_198 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_495 -> V_517 )
return - V_342 ;
return F_199 ( V_10 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_518 * V_510 )
{
return F_201 ( F_9 ( V_19 ) , V_510 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_519 * V_510 )
{
return F_203 ( F_9 ( V_19 ) , V_510 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_520 * V_510 )
{
return F_205 ( F_9 ( V_19 ) , V_510 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_521 * V_510 )
{
return F_207 ( F_9 ( V_19 ) , V_510 ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_522 * V_8 )
{
return F_209 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_210 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_211 ( F_9 ( V_19 ) ) ;
}
static int F_212 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_523 * V_396 )
{
return F_213 ( F_9 ( V_19 ) , V_396 ) ;
}
static int F_214 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_215 ( F_9 ( V_19 ) ) ;
}
static int F_216 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_112 [ V_524 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_215 . V_415 , V_112 ,
sizeof( int ) * V_524 ) ;
return 0 ;
}
static int F_217 ( struct V_2 * V_2 , T_1 V_180 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_180 & V_525 ) {
F_218 ( V_10 ) ;
V_14 = F_219 ( V_10 , V_2 -> V_526 ) ;
if ( V_14 ) {
F_218 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_180 & V_527 ) ||
( V_180 & V_528 ) ) {
T_6 V_529 ;
V_529 = V_180 & V_527 ?
V_2 -> V_529 : - 1 ;
V_14 = F_220 ( V_10 , V_529 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_180 & V_530 ) {
V_14 = F_221 ( V_10 , V_2 -> V_531 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_180 & V_532 ) {
if ( V_2 -> V_533 > V_534 )
return - V_49 ;
V_10 -> V_107 . V_61 . V_535 = V_2 -> V_533 ;
}
if ( V_180 & V_536 ) {
if ( V_2 -> V_537 > V_534 )
return - V_49 ;
V_10 -> V_107 . V_61 . V_538 = V_2 -> V_537 ;
}
if ( V_180 &
( V_532 | V_536 ) )
F_76 ( V_10 , V_539 ) ;
return 0 ;
}
static int F_222 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_540 type , int V_541 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_540 V_542 = type ;
bool V_543 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_544 :
V_13 -> V_545 = V_546 ;
V_542 = V_547 ;
break;
case V_547 :
case V_548 :
if ( V_541 < 0 || ( V_541 % 100 ) )
return - V_342 ;
V_13 -> V_545 = F_223 ( V_541 ) ;
break;
}
if ( V_542 != V_13 -> V_27 . V_215 . V_549 ) {
V_543 = true ;
V_13 -> V_27 . V_215 . V_549 = V_542 ;
}
F_224 ( V_13 , V_543 ) ;
return 0 ;
}
switch ( type ) {
case V_544 :
V_10 -> V_545 = V_546 ;
V_542 = V_547 ;
break;
case V_547 :
case V_548 :
if ( V_541 < 0 || ( V_541 % 100 ) )
return - V_342 ;
V_10 -> V_545 = F_223 ( V_541 ) ;
break;
}
F_16 ( & V_10 -> V_152 ) ;
F_86 (sdata, &local->interfaces, list) {
V_13 -> V_545 = V_10 -> V_545 ;
if ( V_542 != V_13 -> V_27 . V_215 . V_549 )
V_543 = true ;
V_13 -> V_27 . V_215 . V_549 = V_542 ;
}
F_86 (sdata, &local->interfaces, list)
F_224 ( V_13 , V_543 ) ;
F_18 ( & V_10 -> V_152 ) ;
return 0 ;
}
static int F_225 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_550 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_495 -> V_551 )
return F_226 ( V_10 , V_13 , V_550 ) ;
if ( ! V_10 -> V_153 )
* V_550 = V_10 -> V_107 . V_61 . V_552 ;
else
* V_550 = V_13 -> V_27 . V_215 . V_553 ;
return 0 ;
}
static int F_227 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_143 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_554 . V_555 , V_143 , V_144 ) ;
return 0 ;
}
static void F_228 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_229 ( V_10 ) ;
}
static int F_230 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
void * V_170 , int V_169 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_556 * V_27 = NULL ;
if ( ! V_10 -> V_495 -> V_557 )
return - V_342 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_558 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_495 -> V_557 ( & V_10 -> V_107 , V_27 , V_170 , V_169 ) ;
}
static int F_231 ( struct V_2 * V_2 ,
struct V_247 * V_248 ,
struct V_559 * V_256 ,
void * V_170 , int V_169 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_495 -> V_560 )
return - V_342 ;
return V_10 -> V_495 -> V_560 ( & V_10 -> V_107 , V_248 , V_256 , V_170 , V_169 ) ;
}
int F_232 ( struct V_12 * V_13 ,
enum V_561 V_200 )
{
struct V_38 * V_24 ;
enum V_561 V_562 ;
if ( F_35 ( V_13 -> V_27 . type != V_70 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_215 . V_149 . V_563 == V_564 )
return 0 ;
V_562 = V_13 -> V_16 . V_166 . V_349 ;
V_13 -> V_16 . V_166 . V_349 = V_200 ;
if ( V_562 == V_200 ||
V_200 == V_565 )
return 0 ;
if ( ! F_233 ( & V_13 -> V_16 . V_166 . V_347 ) ) {
V_13 -> V_200 = V_200 ;
F_234 ( & V_13 -> V_10 -> V_107 , & V_13 -> V_566 ) ;
return 0 ;
}
F_147 ( V_13 ,
L_3 ,
V_200 , F_233 ( & V_13 -> V_16 . V_166 . V_347 ) ) ;
F_16 ( & V_13 -> V_10 -> V_63 ) ;
F_86 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_346 != & V_13 -> V_16 . V_166 )
continue;
if ( F_146 ( V_24 ) == 1 )
continue;
if ( F_32 ( V_24 , V_567 ) &&
! F_235 ( V_24 -> V_348 ,
V_200 ) ) {
F_147 ( V_13 , L_4 ,
V_24 -> V_24 . V_143 ) ;
continue;
}
if ( ! F_32 ( V_24 , V_266 ) )
continue;
F_147 ( V_13 , L_5 , V_24 -> V_24 . V_143 ) ;
F_148 ( V_13 , V_200 , V_24 -> V_24 . V_143 ,
V_13 -> V_27 . V_215 . V_350 ) ;
}
F_18 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_200 = V_200 ;
F_234 ( & V_13 -> V_10 -> V_107 , & V_13 -> V_566 ) ;
return 0 ;
}
int F_236 ( struct V_12 * V_13 ,
enum V_561 V_200 )
{
const T_3 * V_166 ;
enum V_561 V_562 ;
int V_14 ;
struct V_38 * V_24 ;
bool V_568 = false ;
F_237 ( & V_13 -> V_11 . V_151 ) ;
if ( F_35 ( V_13 -> V_27 . type != V_25 ) )
return - V_49 ;
V_562 = V_13 -> V_16 . V_26 . V_349 ;
V_13 -> V_16 . V_26 . V_349 = V_200 ;
if ( V_562 == V_200 &&
V_200 != V_565 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_569 ||
V_13 -> V_27 . V_215 . V_149 . V_563 == V_564 )
return 0 ;
V_166 = V_13 -> V_16 . V_26 . V_569 -> V_350 ;
F_42 () ;
F_238 (sta, &sdata->local->sta_list, list) {
if ( ! V_24 -> V_24 . V_327 || V_24 -> V_13 != V_13 || ! V_24 -> V_570 ||
! F_32 ( V_24 , V_266 ) )
continue;
V_568 = true ;
break;
}
F_52 () ;
if ( V_200 == V_565 ) {
if ( V_568 || ! V_13 -> V_16 . V_26 . V_571 )
V_200 = V_202 ;
else
V_200 = V_206 ;
}
V_14 = F_148 ( V_13 , V_200 ,
V_166 , V_166 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_349 = V_562 ;
else if ( V_200 != V_202 && V_568 )
F_239 ( V_13 ) ;
return V_14 ;
}
static int F_240 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_572 , int V_573 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_67 ( V_19 -> V_147 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_342 ;
if ( ! F_127 ( & V_10 -> V_107 , V_574 ) )
return - V_342 ;
if ( V_572 == V_13 -> V_16 . V_26 . V_571 &&
V_573 == V_10 -> V_575 )
return 0 ;
V_13 -> V_16 . V_26 . V_571 = V_572 ;
V_10 -> V_575 = V_573 ;
F_241 ( V_13 ) ;
F_236 ( V_13 , V_13 -> V_16 . V_26 . V_349 ) ;
F_242 ( V_13 ) ;
if ( F_127 ( & V_10 -> V_107 , V_576 ) )
F_76 ( V_10 , V_577 ) ;
F_149 ( V_10 ) ;
F_150 ( V_13 ) ;
return 0 ;
}
static int F_243 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_578 , T_1 V_579 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_556 * V_27 = & V_13 -> V_27 ;
struct V_580 * V_215 = & V_27 -> V_215 ;
if ( V_578 == V_215 -> V_581 &&
V_579 == V_215 -> V_582 )
return 0 ;
if ( V_13 -> V_27 . V_583 & V_584 &&
! ( V_13 -> V_27 . V_583 & V_585 ) )
return - V_342 ;
V_215 -> V_581 = V_578 ;
V_215 -> V_582 = V_579 ;
V_13 -> V_16 . V_26 . V_586 = 0 ;
if ( V_13 -> V_16 . V_26 . V_569 &&
V_13 -> V_27 . V_583 & V_585 )
F_89 ( V_13 , V_587 ) ;
return 0 ;
}
static int F_244 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_143 ,
const struct V_588 * V_28 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_67 ( V_19 -> V_147 ) ;
int V_589 , V_20 ;
if ( ! F_12 ( V_13 ) )
return - V_43 ;
if ( F_127 ( & V_10 -> V_107 , V_590 ) ) {
V_20 = F_245 ( V_10 , V_13 , V_28 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_589 = 0 ; V_589 < V_524 ; V_589 ++ ) {
struct V_122 * V_123 = V_2 -> V_126 [ V_589 ] ;
int V_591 ;
V_13 -> V_592 [ V_589 ] = V_28 -> V_253 [ V_589 ] . V_129 ;
memcpy ( V_13 -> V_593 [ V_589 ] , V_28 -> V_253 [ V_589 ] . V_594 ,
sizeof( V_28 -> V_253 [ V_589 ] . V_594 ) ) ;
memcpy ( V_13 -> V_595 [ V_589 ] ,
V_28 -> V_253 [ V_589 ] . V_596 ,
sizeof( V_28 -> V_253 [ V_589 ] . V_596 ) ) ;
V_13 -> V_597 [ V_589 ] = false ;
V_13 -> V_598 [ V_589 ] = false ;
if ( ! V_123 )
continue;
for ( V_591 = 0 ; V_591 < V_599 ; V_591 ++ ) {
if ( ~ V_13 -> V_593 [ V_589 ] [ V_591 ] ) {
V_13 -> V_597 [ V_589 ] = true ;
break;
}
}
for ( V_591 = 0 ; V_591 < V_600 ; V_591 ++ ) {
if ( ~ V_13 -> V_595 [ V_589 ] [ V_591 ] ) {
V_13 -> V_598 [ V_589 ] = true ;
break;
}
}
}
return 0 ;
}
static int F_246 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_148 * V_149 ,
T_1 V_601 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_151 ) ;
if ( ! F_247 ( & V_10 -> V_602 ) || V_10 -> V_603 ) {
V_14 = - V_31 ;
goto V_66;
}
V_13 -> V_200 = V_202 ;
V_13 -> V_207 = V_10 -> V_208 ;
V_14 = F_75 ( V_13 , V_149 ,
V_209 ) ;
if ( V_14 )
goto V_66;
F_248 ( & V_13 -> V_10 -> V_107 ,
& V_13 -> V_240 ,
F_249 ( V_601 ) ) ;
V_66:
F_18 ( & V_10 -> V_151 ) ;
return V_14 ;
}
static struct V_175 *
F_250 ( struct V_175 * V_182 )
{
struct V_175 * V_604 ;
T_3 * V_605 ;
int V_169 ;
V_169 = V_182 -> V_184 + V_182 -> V_186 + V_182 -> V_606 +
V_182 -> V_607 + V_182 -> V_608 +
V_182 -> V_191 ;
V_604 = F_79 ( sizeof( * V_604 ) + V_169 , V_167 ) ;
if ( ! V_604 )
return NULL ;
V_605 = ( T_3 * ) ( V_604 + 1 ) ;
if ( V_182 -> V_184 ) {
V_604 -> V_184 = V_182 -> V_184 ;
V_604 -> V_183 = V_605 ;
memcpy ( V_605 , V_182 -> V_183 , V_182 -> V_184 ) ;
V_605 += V_182 -> V_184 ;
}
if ( V_182 -> V_186 ) {
V_604 -> V_186 = V_182 -> V_186 ;
V_604 -> V_185 = V_605 ;
memcpy ( V_605 , V_182 -> V_185 , V_182 -> V_186 ) ;
V_605 += V_182 -> V_186 ;
}
if ( V_182 -> V_606 ) {
V_604 -> V_606 = V_182 -> V_606 ;
V_604 -> V_609 = V_605 ;
memcpy ( V_605 , V_182 -> V_609 , V_182 -> V_606 ) ;
V_605 += V_182 -> V_606 ;
}
if ( V_182 -> V_607 ) {
V_604 -> V_607 = V_182 -> V_607 ;
V_604 -> V_610 = V_605 ;
memcpy ( V_605 , V_182 -> V_610 , V_182 -> V_607 ) ;
V_605 += V_182 -> V_607 ;
}
if ( V_182 -> V_608 ) {
V_604 -> V_608 = V_182 -> V_608 ;
V_604 -> V_611 = V_605 ;
memcpy ( V_605 , V_182 -> V_611 , V_182 -> V_608 ) ;
V_605 += V_182 -> V_608 ;
}
if ( V_182 -> V_191 ) {
V_604 -> V_191 = V_182 -> V_191 ;
V_182 -> V_163 = V_605 ;
memcpy ( V_605 , V_182 -> V_163 , V_182 -> V_191 ) ;
V_605 += V_182 -> V_191 ;
}
return V_604 ;
}
void F_251 ( struct V_556 * V_27 )
{
struct V_12 * V_13 = F_252 ( V_27 ) ;
F_234 ( & V_13 -> V_10 -> V_107 ,
& V_13 -> V_612 ) ;
}
static int F_253 ( struct V_12 * V_13 ,
T_1 * V_180 )
{
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_14 = F_82 ( V_13 , V_13 -> V_16 . V_166 . V_235 ,
NULL ) ;
F_95 ( V_13 -> V_16 . V_166 . V_235 ) ;
V_13 -> V_16 . V_166 . V_235 = NULL ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
break;
case V_72 :
V_14 = F_254 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
break;
#ifdef F_34
case V_73 :
V_14 = F_255 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
break;
#endif
default:
F_51 ( 1 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_256 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_180 = 0 ;
int V_14 ;
F_92 ( V_13 ) ;
F_237 ( & V_10 -> V_151 ) ;
F_237 ( & V_10 -> V_32 ) ;
if ( V_13 -> V_613 ) {
if ( V_13 -> V_614 )
return 0 ;
return F_257 ( V_13 ) ;
}
if ( ! F_71 ( & V_13 -> V_27 . V_215 . V_149 ,
& V_13 -> V_615 ) )
return - V_49 ;
V_13 -> V_27 . V_230 = false ;
V_14 = F_253 ( V_13 , & V_180 ) ;
if ( V_14 )
return V_14 ;
F_89 ( V_13 , V_180 ) ;
if ( V_13 -> V_233 ) {
F_94 ( V_10 , V_13 ,
V_234 ) ;
V_13 -> V_233 = false ;
}
V_14 = F_258 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_259 ( V_13 -> V_19 , & V_13 -> V_615 ) ;
return 0 ;
}
static void F_260 ( struct V_12 * V_13 )
{
if ( F_256 ( V_13 ) ) {
F_261 ( V_13 , L_6 ) ;
F_262 ( V_13 -> V_10 -> V_107 . V_2 , & V_13 -> V_11 ,
V_167 ) ;
}
}
void F_263 ( struct V_616 * V_617 )
{
struct V_12 * V_13 =
F_174 ( V_617 , struct V_12 ,
V_612 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_241 ( V_13 ) ;
F_16 ( & V_10 -> V_151 ) ;
F_16 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_230 )
goto V_618;
if ( ! F_12 ( V_13 ) )
goto V_618;
F_260 ( V_13 ) ;
V_618:
F_18 ( & V_10 -> V_32 ) ;
F_18 ( & V_10 -> V_151 ) ;
F_242 ( V_13 ) ;
}
static int F_264 ( struct V_12 * V_13 ,
struct V_619 * V_8 ,
T_1 * V_180 )
{
struct V_161 V_162 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_166 . V_235 =
F_250 ( & V_8 -> V_620 ) ;
if ( ! V_13 -> V_16 . V_166 . V_235 )
return - V_168 ;
if ( V_8 -> V_188 <= 1 )
break;
if ( ( V_8 -> V_190 >
V_621 ) ||
( V_8 -> V_173 >
V_621 ) )
return - V_49 ;
V_162 . V_189 = V_8 -> V_189 ;
V_162 . V_172 = V_8 -> V_172 ;
V_162 . V_190 = V_8 -> V_190 ;
V_162 . V_173 = V_8 -> V_173 ;
V_162 . V_188 = V_8 -> V_188 ;
V_14 = F_82 ( V_13 , & V_8 -> V_622 , & V_162 ) ;
if ( V_14 < 0 ) {
F_95 ( V_13 -> V_16 . V_166 . V_235 ) ;
return V_14 ;
}
* V_180 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_215 . V_623 )
return - V_49 ;
if ( V_8 -> V_149 . V_563 != V_13 -> V_16 . V_624 . V_149 . V_563 )
return - V_49 ;
switch ( V_8 -> V_149 . V_563 ) {
case V_625 :
if ( F_265 ( & V_8 -> V_149 ) !=
F_265 ( & V_13 -> V_16 . V_624 . V_149 ) )
return - V_49 ;
case V_626 :
case V_627 :
case V_564 :
case V_628 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_624 . V_149 . V_629 -> V_288 !=
V_8 -> V_149 . V_629 -> V_288 )
return - V_49 ;
if ( V_8 -> V_188 > 1 ) {
V_14 = F_266 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_180 |= V_14 ;
}
F_267 ( V_13 , V_8 ) ;
break;
#ifdef F_34
case V_73 : {
struct V_393 * V_394 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_149 . V_563 != V_13 -> V_27 . V_215 . V_149 . V_563 )
return - V_49 ;
if ( V_13 -> V_27 . V_215 . V_149 . V_629 -> V_288 !=
V_8 -> V_149 . V_629 -> V_288 )
return - V_49 ;
if ( V_394 -> V_630 == V_631 ) {
V_394 -> V_630 = V_632 ;
if ( ! V_394 -> V_633 )
V_394 -> V_633 = 1 ;
else
V_394 -> V_633 ++ ;
}
if ( V_8 -> V_188 > 1 ) {
V_14 = F_268 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_394 -> V_630 = V_631 ;
return V_14 ;
}
* V_180 |= V_14 ;
}
if ( V_394 -> V_630 == V_632 )
F_267 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_342 ;
}
return 0 ;
}
static int
F_269 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_619 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_634 V_635 ;
struct V_636 * V_61 ;
struct V_637 * V_638 ;
T_1 V_180 = 0 ;
int V_14 ;
F_92 ( V_13 ) ;
F_237 ( & V_10 -> V_151 ) ;
if ( ! F_247 ( & V_10 -> V_602 ) || V_10 -> V_603 )
return - V_31 ;
if ( V_13 -> V_11 . V_239 )
return - V_31 ;
if ( F_71 ( & V_8 -> V_149 ,
& V_13 -> V_27 . V_215 . V_149 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_230 )
return - V_31 ;
F_16 ( & V_10 -> V_32 ) ;
V_61 = F_72 ( V_13 -> V_27 . V_639 ,
F_73 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_95;
}
V_638 = F_174 ( V_61 , struct V_637 , V_61 ) ;
if ( ! V_638 ) {
V_14 = - V_31 ;
goto V_95;
}
V_635 . V_640 = 0 ;
V_635 . V_641 = 0 ;
V_635 . V_642 = V_8 -> V_642 ;
V_635 . V_149 = V_8 -> V_149 ;
V_635 . V_188 = V_8 -> V_188 ;
V_14 = F_270 ( V_13 , & V_635 ) ;
if ( V_14 )
goto V_95;
V_14 = F_271 ( V_13 , & V_8 -> V_149 ,
V_638 -> V_643 ,
V_8 -> V_644 ) ;
if ( V_14 )
goto V_95;
V_14 = F_17 ( V_13 , NULL , V_638 -> V_643 , 0 ) ;
if ( V_14 ) {
F_272 ( V_13 ) ;
goto V_95;
}
V_14 = F_264 ( V_13 , V_8 , & V_180 ) ;
if ( V_14 ) {
F_272 ( V_13 ) ;
goto V_95;
}
V_13 -> V_615 = V_8 -> V_149 ;
V_13 -> V_233 = V_8 -> V_642 ;
V_13 -> V_27 . V_230 = true ;
if ( V_13 -> V_233 )
F_273 ( V_10 , V_13 ,
V_234 ) ;
F_274 ( V_13 -> V_19 , & V_13 -> V_615 ,
V_8 -> V_188 ) ;
if ( V_180 ) {
F_89 ( V_13 , V_180 ) ;
F_275 ( V_13 , & V_8 -> V_149 ) ;
} else {
F_260 ( V_13 ) ;
}
V_95:
F_18 ( & V_10 -> V_32 ) ;
return V_14 ;
}
int V_634 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_619 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_151 ) ;
V_14 = F_269 ( V_2 , V_19 , V_8 ) ;
F_18 ( & V_10 -> V_151 ) ;
return V_14 ;
}
T_4 F_276 ( struct V_9 * V_10 )
{
F_237 ( & V_10 -> V_151 ) ;
V_10 -> V_645 ++ ;
if ( F_51 ( V_10 -> V_645 == 0 ) )
V_10 -> V_645 ++ ;
return V_10 -> V_645 ;
}
int F_277 ( struct V_9 * V_10 , struct V_247 * V_248 ,
T_4 * V_89 , T_8 V_646 )
{
unsigned long V_647 ;
struct V_247 * V_648 ;
int V_649 ;
V_648 = F_278 ( V_248 , V_646 ) ;
if ( ! V_648 )
return - V_168 ;
F_279 ( & V_10 -> V_650 , V_647 ) ;
V_649 = F_280 ( & V_10 -> V_651 , V_648 ,
1 , 0x10000 , V_652 ) ;
F_281 ( & V_10 -> V_650 , V_647 ) ;
if ( V_649 < 0 ) {
F_282 ( V_648 ) ;
return - V_168 ;
}
F_283 ( V_248 ) -> V_653 = V_649 ;
* V_89 = F_276 ( V_10 ) ;
F_283 ( V_648 ) -> V_654 . V_89 = * V_89 ;
return 0 ;
}
static void F_284 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_655 , bool V_656 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_655 ) {
case V_657 | V_658 :
if ( V_656 ) {
V_10 -> V_659 ++ ;
V_13 -> V_27 . V_659 ++ ;
} else {
if ( V_10 -> V_659 )
V_10 -> V_659 -- ;
if ( V_13 -> V_27 . V_659 )
V_13 -> V_27 . V_659 -- ;
}
if ( ! V_10 -> V_156 )
break;
if ( V_13 -> V_27 . V_659 == 1 )
F_285 ( V_10 , V_13 , V_660 ,
V_660 ) ;
else if ( V_13 -> V_27 . V_659 == 0 )
F_285 ( V_10 , V_13 , 0 ,
V_660 ) ;
F_14 ( V_10 ) ;
break;
default:
break;
}
}
static int F_286 ( struct V_2 * V_2 , T_1 V_661 , T_1 V_662 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_663 )
return - V_342 ;
return F_287 ( V_10 , V_661 , V_662 ) ;
}
static int F_288 ( struct V_2 * V_2 , T_1 * V_661 , T_1 * V_662 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_289 ( V_10 , V_661 , V_662 ) ;
}
static int F_290 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_664 * V_170 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_495 -> V_665 )
return - V_342 ;
F_291 ( V_10 , V_13 , V_170 ) ;
return 0 ;
}
static int F_292 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_666 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_667 * V_668 ;
struct V_247 * V_248 ;
int V_179 = sizeof( * V_668 ) ;
T_9 V_669 ;
bool V_670 ;
struct V_671 * V_672 ;
struct V_38 * V_24 ;
struct V_636 * V_639 ;
enum V_287 V_288 ;
int V_20 ;
F_16 ( & V_10 -> V_151 ) ;
F_42 () ;
V_639 = F_43 ( V_13 -> V_27 . V_639 ) ;
if ( F_51 ( ! V_639 ) ) {
V_20 = - V_49 ;
goto V_618;
}
V_288 = V_639 -> V_673 . V_629 -> V_288 ;
V_24 = F_31 ( V_13 , V_666 ) ;
if ( V_24 ) {
V_670 = V_24 -> V_24 . V_295 ;
} else {
V_20 = - V_674 ;
goto V_618;
}
if ( V_670 ) {
V_669 = F_293 ( V_675 |
V_676 |
V_677 ) ;
} else {
V_179 -= 2 ;
V_669 = F_293 ( V_675 |
V_678 |
V_677 ) ;
}
V_248 = F_106 ( V_10 -> V_107 . V_679 + V_179 ) ;
if ( ! V_248 ) {
V_20 = - V_168 ;
goto V_618;
}
V_248 -> V_19 = V_19 ;
F_294 ( V_248 , V_10 -> V_107 . V_679 ) ;
V_668 = ( void * ) F_107 ( V_248 , V_179 ) ;
V_668 -> V_680 = V_669 ;
V_668 -> V_681 = 0 ;
memcpy ( V_668 -> V_682 , V_24 -> V_24 . V_143 , V_144 ) ;
memcpy ( V_668 -> V_683 , V_13 -> V_27 . V_143 , V_144 ) ;
memcpy ( V_668 -> V_684 , V_13 -> V_27 . V_143 , V_144 ) ;
V_668 -> V_685 = 0 ;
V_672 = F_283 ( V_248 ) ;
V_672 -> V_6 |= V_686 |
V_687 ;
V_672 -> V_288 = V_288 ;
F_295 ( V_248 , V_688 ) ;
V_248 -> V_689 = 7 ;
if ( V_670 )
V_668 -> V_690 = F_293 ( 7 ) ;
V_20 = F_277 ( V_10 , V_248 , V_89 , V_652 ) ;
if ( V_20 ) {
F_282 ( V_248 ) ;
goto V_618;
}
F_296 () ;
F_297 ( V_13 , V_24 , V_248 ) ;
F_298 () ;
V_20 = 0 ;
V_618:
F_52 () ;
F_18 ( & V_10 -> V_151 ) ;
return V_20 ;
}
static int F_299 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_148 * V_149 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_636 * V_639 ;
int V_20 = - V_691 ;
F_42 () ;
V_639 = F_43 ( V_13 -> V_27 . V_639 ) ;
if ( V_639 ) {
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
F_52 () ;
return V_20 ;
}
static void F_300 ( struct V_2 * V_2 , bool V_572 )
{
F_301 ( F_2 ( V_2 ) , V_572 ) ;
}
static int F_302 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_692 * V_693 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_694 * V_695 , * V_696 ;
if ( V_693 ) {
V_695 = F_79 ( sizeof( * V_695 ) , V_167 ) ;
if ( ! V_695 )
return - V_168 ;
memcpy ( & V_695 -> V_693 , V_693 , sizeof( * V_693 ) ) ;
} else {
V_695 = NULL ;
}
V_696 = F_78 ( V_13 -> V_693 , V_13 ) ;
F_80 ( V_13 -> V_693 , V_695 ) ;
if ( V_696 )
F_81 ( V_696 , V_174 ) ;
return 0 ;
}
static int F_303 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_148 * V_149 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_180 = 0 ;
V_20 = F_304 ( V_13 , V_149 , & V_180 ) ;
if ( V_20 == 0 )
F_89 ( V_13 , V_180 ) ;
return V_20 ;
}
static int F_305 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_697 , const T_3 * V_666 , T_3 V_698 ,
T_2 V_699 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_700 * V_701 = & V_13 -> V_16 . V_26 ;
int V_505 = V_702 [ V_698 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_342 ;
if ( ! ( V_13 -> V_703 & F_113 ( V_698 ) ) )
return - V_49 ;
if ( V_701 -> V_704 [ V_505 ] . V_699 )
return - V_31 ;
if ( V_699 ) {
V_701 -> V_704 [ V_505 ] . V_699 = 32 * V_699 ;
V_701 -> V_704 [ V_505 ] . V_697 = V_697 ;
V_701 -> V_704 [ V_505 ] . V_698 = V_698 ;
}
return 0 ;
}
static int F_306 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_697 , const T_3 * V_666 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_700 * V_701 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_505 ;
for ( V_505 = 0 ; V_505 < V_294 ; V_505 ++ ) {
struct V_705 * V_704 = & V_701 -> V_704 [ V_505 ] ;
if ( ! V_704 -> V_699 )
continue;
if ( V_704 -> V_697 != V_697 )
continue;
V_704 -> V_698 = - 1 ;
F_307 () ;
F_308 ( V_10 , V_13 , false ) ;
V_704 -> V_706 = V_707 ;
V_704 -> V_708 = false ;
F_309 ( V_13 ) ;
memset ( V_704 , 0 , sizeof( * V_704 ) ) ;
return 0 ;
}
return - V_65 ;
}
