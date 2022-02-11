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
static int F_61 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_141 , struct V_142 * V_143 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_62 ( V_13 , V_119 ) ;
if ( V_24 ) {
V_20 = 0 ;
memcpy ( V_141 , V_24 -> V_24 . V_144 , V_145 ) ;
F_63 ( V_24 , V_143 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_64 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , struct V_146 * V_147 )
{
struct V_9 * V_10 = F_65 ( V_19 -> V_148 ) ;
return F_66 ( V_10 , V_119 , V_147 ) ;
}
static int F_67 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_141 , struct V_142 * V_143 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_38 * V_24 ;
int V_20 = - V_65 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_31 ( V_13 , V_141 ) ;
if ( V_24 ) {
V_20 = 0 ;
F_63 ( V_24 , V_143 ) ;
}
F_18 ( & V_10 -> V_63 ) ;
return V_20 ;
}
static int F_68 ( struct V_2 * V_2 ,
struct V_149 * V_150 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
int V_20 = 0 ;
if ( F_69 ( & V_10 -> V_151 , V_150 ) )
return 0 ;
F_16 ( & V_10 -> V_152 ) ;
F_16 ( & V_10 -> V_153 ) ;
if ( V_10 -> V_154 ) {
V_13 = F_70 (
V_10 -> V_155 ,
F_71 ( & V_10 -> V_153 ) ) ;
if ( V_13 ) {
F_72 ( V_13 ) ;
V_20 = F_73 ( V_13 , V_150 ,
V_156 ) ;
}
} else if ( V_10 -> V_157 == V_10 -> V_158 ) {
V_10 -> V_159 = * V_150 ;
F_74 ( V_10 , 0 ) ;
}
if ( V_20 == 0 )
V_10 -> V_151 = * V_150 ;
F_18 ( & V_10 -> V_153 ) ;
F_18 ( & V_10 -> V_152 ) ;
return V_20 ;
}
static int F_75 ( struct V_12 * V_13 ,
const T_3 * V_160 , T_5 V_161 ,
const struct V_162 * V_163 )
{
struct V_164 * V_165 , * V_166 ;
if ( ! V_160 || ! V_161 )
return 1 ;
V_166 = F_76 ( V_13 -> V_16 . V_167 . V_164 , V_13 ) ;
V_165 = F_77 ( sizeof( struct V_164 ) + V_161 , V_168 ) ;
if ( ! V_165 )
return - V_169 ;
V_165 -> V_170 = V_161 ;
memcpy ( V_165 -> V_171 , V_160 , V_161 ) ;
if ( V_163 )
memcpy ( V_165 -> V_172 , V_163 -> V_173 ,
V_163 -> V_174 *
sizeof( V_165 -> V_172 [ 0 ] ) ) ;
F_78 ( V_13 -> V_16 . V_167 . V_164 , V_165 ) ;
if ( V_166 )
F_79 ( V_166 , V_175 ) ;
return 0 ;
}
static int F_80 ( struct V_12 * V_13 ,
struct V_176 * V_8 ,
const struct V_162 * V_163 )
{
struct V_177 * V_165 , * V_166 ;
int V_178 , V_179 ;
int V_180 , V_14 ;
T_1 V_181 = V_182 ;
V_166 = F_76 ( V_13 -> V_16 . V_167 . V_183 , V_13 ) ;
if ( ! V_8 -> V_184 && ! V_166 )
return - V_49 ;
if ( V_8 -> V_184 )
V_178 = V_8 -> V_185 ;
else
V_178 = V_166 -> V_185 ;
if ( V_8 -> V_186 || ! V_166 )
V_179 = V_8 -> V_187 ;
else
V_179 = V_166 -> V_187 ;
V_180 = sizeof( * V_165 ) + V_178 + V_179 ;
V_165 = F_77 ( V_180 , V_168 ) ;
if ( ! V_165 )
return - V_169 ;
V_165 -> V_184 = ( ( T_3 * ) V_165 ) + sizeof( * V_165 ) ;
V_165 -> V_186 = V_165 -> V_184 + V_178 ;
V_165 -> V_185 = V_178 ;
V_165 -> V_187 = V_179 ;
if ( V_163 ) {
V_165 -> V_188 = V_163 -> V_189 ;
memcpy ( V_165 -> V_172 , V_163 -> V_190 ,
V_163 -> V_191 *
sizeof( V_165 -> V_172 [ 0 ] ) ) ;
}
if ( V_8 -> V_184 )
memcpy ( V_165 -> V_184 , V_8 -> V_184 , V_178 ) ;
else
memcpy ( V_165 -> V_184 , V_166 -> V_184 , V_178 ) ;
if ( V_8 -> V_186 )
memcpy ( V_165 -> V_186 , V_8 -> V_186 , V_179 ) ;
else
if ( V_166 )
memcpy ( V_165 -> V_186 , V_166 -> V_186 , V_179 ) ;
V_14 = F_75 ( V_13 , V_8 -> V_164 ,
V_8 -> V_192 , V_163 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 == 0 )
V_181 |= V_193 ;
F_78 ( V_13 -> V_16 . V_167 . V_183 , V_165 ) ;
if ( V_166 )
F_79 ( V_166 , V_175 ) ;
return V_181 ;
}
static int F_81 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_194 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_177 * V_166 ;
struct V_12 * V_23 ;
T_1 V_181 = V_195 |
V_196 |
V_182 |
V_197 |
V_198 |
V_199 ;
int V_14 ;
V_166 = F_76 ( V_13 -> V_16 . V_167 . V_183 , V_13 ) ;
if ( V_166 )
return - V_200 ;
switch ( V_8 -> V_201 ) {
case V_202 :
V_13 -> V_201 = V_203 ;
break;
case V_204 :
V_13 -> V_201 = V_205 ;
break;
case V_206 :
V_13 -> V_201 = V_207 ;
break;
default:
return - V_49 ;
}
V_13 -> V_208 = V_13 -> V_10 -> V_209 ;
F_16 ( & V_10 -> V_152 ) ;
V_14 = F_73 ( V_13 , & V_8 -> V_150 ,
V_210 ) ;
if ( ! V_14 )
F_82 ( V_13 , false ) ;
F_18 ( & V_10 -> V_152 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_211 = V_8 -> V_212 . V_213 ;
V_13 -> V_214 = V_8 -> V_212 . V_214 ;
V_13 -> V_215 = F_83 ( V_13 -> V_10 ,
& V_8 -> V_212 ,
V_13 -> V_27 . type ) ;
F_84 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_23 -> V_211 =
V_8 -> V_212 . V_213 ;
V_23 -> V_214 =
V_8 -> V_212 . V_214 ;
V_23 -> V_215 =
F_83 ( V_13 -> V_10 ,
& V_8 -> V_212 ,
V_23 -> V_27 . type ) ;
}
V_13 -> V_27 . V_216 . V_217 = V_8 -> V_218 ;
V_13 -> V_27 . V_216 . V_219 = V_8 -> V_219 ;
V_13 -> V_27 . V_216 . V_220 = true ;
V_13 -> V_27 . V_216 . V_221 = V_8 -> V_221 ;
if ( V_8 -> V_221 )
memcpy ( V_13 -> V_27 . V_216 . V_222 , V_8 -> V_222 ,
V_8 -> V_221 ) ;
V_13 -> V_27 . V_216 . V_223 =
( V_8 -> V_223 != V_224 ) ;
memset ( & V_13 -> V_27 . V_216 . V_225 , 0 ,
sizeof( V_13 -> V_27 . V_216 . V_225 ) ) ;
V_13 -> V_27 . V_216 . V_225 . V_226 =
V_8 -> V_227 & V_228 ;
if ( V_8 -> V_229 )
V_13 -> V_27 . V_216 . V_225 . V_226 |=
V_230 ;
V_14 = F_80 ( V_13 , & V_8 -> V_183 , NULL ) ;
if ( V_14 < 0 ) {
F_72 ( V_13 ) ;
return V_14 ;
}
V_181 |= V_14 ;
V_14 = F_85 ( V_13 -> V_10 , V_13 ) ;
if ( V_14 ) {
V_166 = F_76 ( V_13 -> V_16 . V_167 . V_183 , V_13 ) ;
if ( V_166 )
F_79 ( V_166 , V_175 ) ;
F_11 ( V_13 -> V_16 . V_167 . V_183 , NULL ) ;
F_72 ( V_13 ) ;
return V_14 ;
}
F_86 ( V_10 , V_13 ) ;
F_87 ( V_13 , V_181 ) ;
F_88 ( V_19 ) ;
F_84 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_88 ( V_23 -> V_19 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_176 * V_8 )
{
struct V_12 * V_13 ;
struct V_177 * V_166 ;
int V_14 ;
V_13 = F_9 ( V_19 ) ;
F_90 ( V_13 ) ;
if ( V_13 -> V_27 . V_231 )
return - V_31 ;
V_166 = F_76 ( V_13 -> V_16 . V_167 . V_183 , V_13 ) ;
if ( ! V_166 )
return - V_65 ;
V_14 = F_80 ( V_13 , V_8 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
F_87 ( V_13 , V_14 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_12 * V_23 ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_177 * V_232 ;
struct V_164 * V_233 ;
struct V_149 V_150 ;
F_90 ( V_13 ) ;
V_232 = F_76 ( V_13 -> V_16 . V_167 . V_183 , V_13 ) ;
if ( ! V_232 )
return - V_65 ;
V_233 = F_76 ( V_13 -> V_16 . V_167 . V_164 , V_13 ) ;
F_16 ( & V_10 -> V_152 ) ;
V_13 -> V_27 . V_231 = false ;
if ( V_13 -> V_234 ) {
F_92 ( V_10 , V_13 ,
V_235 ) ;
V_13 -> V_234 = false ;
}
F_18 ( & V_10 -> V_152 ) ;
F_93 ( V_13 -> V_16 . V_167 . V_236 ) ;
V_13 -> V_16 . V_167 . V_236 = NULL ;
F_84 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_94 ( V_23 -> V_19 ) ;
F_94 ( V_19 ) ;
F_11 ( V_13 -> V_16 . V_167 . V_183 , NULL ) ;
F_11 ( V_13 -> V_16 . V_167 . V_164 , NULL ) ;
F_79 ( V_232 , V_175 ) ;
if ( V_233 )
F_79 ( V_233 , V_175 ) ;
V_13 -> V_16 . V_167 . V_237 = V_203 ;
F_95 ( V_13 , true ) ;
F_96 ( V_13 , true ) ;
V_13 -> V_27 . V_216 . V_220 = false ;
V_13 -> V_27 . V_216 . V_221 = 0 ;
F_97 ( V_238 , & V_13 -> V_239 ) ;
F_87 ( V_13 , V_196 ) ;
if ( V_13 -> V_11 . V_240 ) {
V_150 = V_13 -> V_27 . V_216 . V_150 ;
F_98 ( & V_13 -> V_241 ) ;
F_99 ( V_13 -> V_19 , & V_150 ,
V_242 ,
V_168 ) ;
}
F_100 ( V_13 -> V_10 , V_13 ) ;
V_10 -> V_243 -= F_101 ( & V_13 -> V_16 . V_167 . V_244 . V_245 ) ;
F_102 ( & V_13 -> V_16 . V_167 . V_244 . V_245 ) ;
F_16 ( & V_10 -> V_152 ) ;
F_82 ( V_13 , true ) ;
F_72 ( V_13 ) ;
F_18 ( & V_10 -> V_152 ) ;
return 0 ;
}
static void F_103 ( struct V_38 * V_24 )
{
struct V_246 * V_247 ;
struct V_248 * V_249 ;
V_249 = F_104 ( sizeof( * V_247 ) ) ;
if ( ! V_249 )
return;
V_247 = (struct V_246 * ) F_105 ( V_249 , sizeof( * V_247 ) ) ;
F_106 ( V_247 -> V_250 ) ;
memcpy ( V_247 -> V_251 , V_24 -> V_24 . V_144 , V_145 ) ;
V_247 -> V_170 = F_107 ( 6 ) ;
V_247 -> V_252 = 0 ;
V_247 -> V_253 = 0x01 ;
V_247 -> V_254 = 0xaf ;
V_247 -> V_255 [ 0 ] = 0x81 ;
V_247 -> V_255 [ 1 ] = 1 ;
V_247 -> V_255 [ 2 ] = 0 ;
V_249 -> V_19 = V_24 -> V_13 -> V_19 ;
V_249 -> V_256 = F_108 ( V_249 , V_24 -> V_13 -> V_19 ) ;
memset ( V_249 -> V_257 , 0 , sizeof( V_249 -> V_257 ) ) ;
F_109 ( V_249 ) ;
}
static int F_110 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
T_1 V_28 , T_1 V_258 )
{
int V_20 ;
if ( V_28 & F_111 ( V_259 ) &&
V_258 & F_111 ( V_259 ) &&
! F_32 ( V_24 , V_260 ) ) {
V_20 = F_112 ( V_24 , V_261 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_111 ( V_262 ) &&
V_258 & F_111 ( V_262 ) &&
! F_32 ( V_24 , V_64 ) ) {
if ( ! F_32 ( V_24 , V_263 ) )
F_113 ( V_24 ) ;
V_20 = F_112 ( V_24 , V_264 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_111 ( V_265 ) ) {
if ( V_258 & F_111 ( V_265 ) )
V_20 = F_112 ( V_24 , V_266 ) ;
else if ( F_32 ( V_24 , V_267 ) )
V_20 = F_112 ( V_24 , V_264 ) ;
else
V_20 = 0 ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_111 ( V_262 ) &&
! ( V_258 & F_111 ( V_262 ) ) &&
F_32 ( V_24 , V_64 ) ) {
V_20 = F_112 ( V_24 , V_261 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_111 ( V_259 ) &&
! ( V_258 & F_111 ( V_259 ) ) &&
F_32 ( V_24 , V_260 ) ) {
V_20 = F_112 ( V_24 , V_268 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static void F_114 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_269 * V_8 )
{
#ifdef F_34
struct V_12 * V_13 = V_24 -> V_13 ;
T_1 V_181 = 0 ;
if ( V_8 -> V_270 & V_271 ) {
switch ( V_8 -> V_272 ) {
case V_273 :
if ( V_24 -> V_74 -> V_272 != V_273 )
V_181 = F_115 ( V_13 ) ;
V_24 -> V_74 -> V_272 = V_8 -> V_272 ;
F_116 ( V_24 ) ;
V_181 |= F_117 ( V_24 ,
V_13 -> V_16 . V_74 . V_274 . V_275 ) ;
break;
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
if ( V_24 -> V_74 -> V_272 == V_273 )
V_181 = F_118 ( V_13 ) ;
V_24 -> V_74 -> V_272 = V_8 -> V_272 ;
F_116 ( V_24 ) ;
V_181 |= F_117 ( V_24 ,
V_282 ) ;
break;
default:
break;
}
}
switch ( V_8 -> V_283 ) {
case V_284 :
break;
case V_285 :
V_181 |= F_119 ( V_24 ) ;
break;
case V_286 :
V_181 |= F_120 ( V_24 ) ;
break;
}
if ( V_8 -> V_287 )
V_181 |= F_117 ( V_24 ,
V_8 -> V_287 ) ;
F_121 ( V_13 , V_181 ) ;
#endif
}
static int F_122 ( struct V_9 * V_10 ,
struct V_38 * V_24 ,
struct V_269 * V_8 )
{
int V_20 = 0 ;
struct V_123 * V_124 ;
struct V_12 * V_13 = V_24 -> V_13 ;
enum V_288 V_289 = F_59 ( V_13 ) ;
T_1 V_28 , V_258 ;
V_124 = V_10 -> V_108 . V_2 -> V_127 [ V_289 ] ;
V_28 = V_8 -> V_290 ;
V_258 = V_8 -> V_291 ;
if ( F_29 ( & V_13 -> V_27 ) ) {
if ( V_28 & F_111 ( V_259 ) )
V_28 |= F_111 ( V_262 ) ;
if ( V_258 & F_111 ( V_259 ) )
V_258 |= F_111 ( V_262 ) ;
} else if ( F_32 ( V_24 , V_292 ) ) {
if ( V_258 & F_111 ( V_265 ) ) {
V_258 |= F_111 ( V_259 ) |
F_111 ( V_262 ) ;
V_28 |= F_111 ( V_259 ) |
F_111 ( V_262 ) ;
}
}
if ( V_28 & F_111 ( V_293 ) &&
V_10 -> V_108 . V_294 >= V_295 )
V_24 -> V_24 . V_296 = V_258 & F_111 ( V_293 ) ;
if ( ! F_32 ( V_24 , V_292 ) &&
! ( ( V_28 & F_111 ( V_262 ) ) &&
( V_258 & F_111 ( V_262 ) ) ) ) {
V_20 = F_110 ( V_10 , V_24 , V_28 , V_258 ) ;
if ( V_20 )
return V_20 ;
}
if ( V_28 & F_111 ( V_297 ) ) {
if ( V_258 & F_111 ( V_297 ) )
F_123 ( V_24 , V_298 ) ;
else
F_124 ( V_24 , V_298 ) ;
}
if ( V_28 & F_111 ( V_299 ) ) {
V_24 -> V_24 . V_67 = ! ! ( V_258 & F_111 ( V_299 ) ) ;
if ( V_258 & F_111 ( V_299 ) )
F_123 ( V_24 , V_71 ) ;
else
F_124 ( V_24 , V_71 ) ;
}
if ( V_28 & F_111 ( V_300 ) ) {
if ( V_258 & F_111 ( V_300 ) )
F_123 ( V_24 , V_292 ) ;
else
F_124 ( V_24 , V_292 ) ;
}
if ( F_32 ( V_24 , V_292 ) &&
! V_13 -> V_16 . V_26 . V_301 &&
V_8 -> V_302 >= 4 &&
V_8 -> V_303 [ 3 ] & V_304 )
F_123 ( V_24 , V_305 ) ;
if ( F_32 ( V_24 , V_292 ) &&
! V_13 -> V_16 . V_26 . V_306 &&
F_125 ( & V_10 -> V_108 , V_307 ) &&
V_8 -> V_302 >= 8 &&
V_8 -> V_303 [ 7 ] & V_308 )
F_123 ( V_24 , V_309 ) ;
if ( V_8 -> V_270 & V_310 ) {
V_24 -> V_24 . V_311 = V_8 -> V_311 ;
V_24 -> V_24 . V_312 = V_8 -> V_312 ;
}
if ( V_8 -> V_313 )
V_24 -> V_24 . V_313 = V_8 -> V_313 ;
if ( V_8 -> V_314 >= 0 )
V_24 -> V_314 = V_8 -> V_314 ;
if ( V_8 -> V_315 ) {
F_126 ( & V_13 -> V_27 . V_216 . V_150 ,
V_124 , V_8 -> V_315 ,
V_8 -> V_316 ,
& V_24 -> V_24 . V_317 [ V_289 ] ) ;
}
if ( V_8 -> V_318 )
F_127 ( V_13 , V_124 ,
V_8 -> V_318 , V_24 ) ;
if ( V_8 -> V_319 )
F_128 ( V_13 , V_124 ,
V_8 -> V_319 , V_24 ) ;
if ( V_8 -> V_320 ) {
F_129 ( V_13 , V_24 ,
V_8 -> V_321 , V_289 ) ;
}
if ( F_29 ( & V_13 -> V_27 ) )
F_114 ( V_10 , V_24 , V_8 ) ;
if ( F_32 ( V_24 , V_292 ) ||
V_258 & F_111 ( V_262 ) ) {
V_20 = F_110 ( V_10 , V_24 , V_28 , V_258 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_130 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_141 ,
struct V_269 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_13 ;
int V_14 ;
int V_322 ;
if ( V_8 -> V_23 ) {
V_13 = F_9 ( V_8 -> V_23 ) ;
if ( V_13 -> V_27 . type != V_21 &&
V_13 -> V_27 . type != V_70 )
return - V_49 ;
} else
V_13 = F_9 ( V_19 ) ;
if ( F_131 ( V_141 , V_13 -> V_27 . V_144 ) )
return - V_49 ;
if ( F_132 ( V_141 ) )
return - V_49 ;
V_24 = F_133 ( V_13 , V_141 , V_168 ) ;
if ( ! V_24 )
return - V_169 ;
if ( ! ( V_8 -> V_291 & F_111 ( V_300 ) ) &&
! ( V_8 -> V_291 & ( F_111 ( V_259 ) |
F_111 ( V_262 ) ) ) ) {
F_134 ( V_24 , V_261 ) ;
F_134 ( V_24 , V_264 ) ;
}
if ( V_8 -> V_291 & F_111 ( V_300 ) )
V_24 -> V_24 . V_323 = true ;
V_14 = F_122 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_135 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_32 ( V_24 , V_292 ) &&
F_32 ( V_24 , V_64 ) )
F_113 ( V_24 ) ;
V_322 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_136 ( V_24 ) ;
if ( V_14 ) {
F_50 () ;
return V_14 ;
}
if ( V_322 )
F_103 ( V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_137 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_324 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_141 )
return F_138 ( V_13 , V_8 -> V_141 ) ;
F_139 ( V_13 ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_2 ,
struct V_18 * V_19 , const T_3 * V_141 ,
struct V_269 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_38 * V_24 ;
struct V_12 * V_325 ;
enum V_326 V_327 ;
int V_14 ;
F_16 ( & V_10 -> V_63 ) ;
V_24 = F_31 ( V_13 , V_141 ) ;
if ( ! V_24 ) {
V_14 = - V_65 ;
goto V_328;
}
switch ( V_13 -> V_27 . type ) {
case V_73 :
if ( V_13 -> V_16 . V_74 . V_329 )
V_327 = V_330 ;
else
V_327 = V_331 ;
break;
case V_72 :
V_327 = V_332 ;
break;
case V_25 :
if ( ! F_32 ( V_24 , V_292 ) ) {
V_327 = V_333 ;
break;
}
if ( F_32 ( V_24 , V_267 ) )
V_327 = V_334 ;
else
V_327 = V_335 ;
break;
case V_70 :
case V_21 :
if ( F_32 ( V_24 , V_64 ) )
V_327 = V_336 ;
else
V_327 = V_337 ;
break;
default:
V_14 = - V_338 ;
goto V_328;
}
V_14 = F_141 ( V_2 , V_8 , V_327 ) ;
if ( V_14 )
goto V_328;
if ( V_8 -> V_23 && V_8 -> V_23 != V_24 -> V_13 -> V_19 ) {
bool V_339 = false ;
bool V_340 = false ;
V_325 = F_9 ( V_8 -> V_23 ) ;
if ( V_8 -> V_23 -> V_148 -> V_22 ) {
if ( V_325 -> V_16 . V_23 . V_24 ) {
V_14 = - V_31 ;
goto V_328;
}
F_78 ( V_325 -> V_16 . V_23 . V_24 , V_24 ) ;
V_340 = true ;
}
if ( V_24 -> V_13 -> V_27 . type == V_21 &&
V_24 -> V_13 -> V_16 . V_23 . V_24 ) {
F_11 ( V_24 -> V_13 -> V_16 . V_23 . V_24 , NULL ) ;
V_339 = true ;
}
V_24 -> V_13 = V_325 ;
F_142 ( V_24 ) ;
if ( V_24 -> V_341 == V_266 &&
V_339 != V_340 ) {
if ( V_340 )
F_143 ( & V_24 -> V_13 -> V_342 -> V_343 ) ;
else
F_144 ( & V_24 -> V_13 -> V_342 -> V_343 ) ;
}
F_103 ( V_24 ) ;
}
V_14 = F_122 ( V_10 , V_24 , V_8 ) ;
if ( V_14 )
goto V_328;
F_18 ( & V_10 -> V_63 ) ;
if ( ( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_21 ) &&
V_24 -> V_344 != V_24 -> V_13 -> V_342 -> V_345 &&
F_32 ( V_24 , V_267 ) &&
F_145 ( V_24 ) != 1 ) {
F_146 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_144 ) ;
F_147 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_342 -> V_345 ,
V_24 -> V_24 . V_144 ,
V_24 -> V_13 -> V_27 . V_216 . V_346 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_290 & F_111 ( V_265 ) ) {
F_148 ( V_10 ) ;
F_149 ( V_13 ) ;
}
return 0 ;
V_328:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_150 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_347 , const T_3 * V_348 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_348 ) ;
if ( ! V_24 ) {
F_50 () ;
return - V_65 ;
}
V_350 = F_151 ( V_13 , V_347 ) ;
if ( F_25 ( V_350 ) ) {
F_50 () ;
return F_28 ( V_350 ) ;
}
F_152 ( V_350 , V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_153 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_347 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_347 )
return F_154 ( V_13 , V_347 ) ;
F_155 ( V_13 ) ;
return 0 ;
}
static int F_156 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_347 , const T_3 * V_348 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
struct V_38 * V_24 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_24 = F_30 ( V_13 , V_348 ) ;
if ( ! V_24 ) {
F_50 () ;
return - V_65 ;
}
V_350 = F_157 ( V_13 , V_347 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
F_152 ( V_350 , V_24 ) ;
F_50 () ;
return 0 ;
}
static void F_158 ( struct V_349 * V_350 , T_3 * V_348 ,
struct V_351 * V_352 )
{
struct V_38 * V_353 = F_43 ( V_350 -> V_348 ) ;
if ( V_353 )
memcpy ( V_348 , V_353 -> V_24 . V_144 , V_145 ) ;
else
F_159 ( V_348 ) ;
memset ( V_352 , 0 , sizeof( * V_352 ) ) ;
V_352 -> V_354 = V_355 ;
V_352 -> V_356 = V_357 |
V_358 |
V_359 |
V_360 |
V_361 |
V_362 |
V_363 ;
V_352 -> V_364 = V_350 -> V_365 . V_366 ;
V_352 -> V_367 = V_350 -> V_367 ;
V_352 -> V_368 = V_350 -> V_368 ;
if ( F_160 ( V_369 , V_350 -> V_370 ) )
V_352 -> V_371 = F_161 ( V_350 -> V_370 - V_369 ) ;
V_352 -> V_372 =
F_161 ( V_350 -> V_372 ) ;
V_352 -> V_373 = V_350 -> V_373 ;
if ( V_350 -> V_6 & V_374 )
V_352 -> V_6 |= V_375 ;
if ( V_350 -> V_6 & V_376 )
V_352 -> V_6 |= V_377 ;
if ( V_350 -> V_6 & V_378 )
V_352 -> V_6 |= V_379 ;
if ( V_350 -> V_6 & V_380 )
V_352 -> V_6 |= V_381 ;
if ( V_350 -> V_6 & V_382 )
V_352 -> V_6 |= V_383 ;
}
static int F_162 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_347 , T_3 * V_348 , struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_157 ( V_13 , V_347 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_158 ( V_350 , V_348 , V_352 ) ;
F_50 () ;
return 0 ;
}
static int F_163 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_347 , T_3 * V_348 ,
struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_164 ( V_13 , V_119 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_158 ( V_350 , V_348 , V_352 ) ;
F_50 () ;
return 0 ;
}
static void F_165 ( struct V_349 * V_350 , T_3 * V_384 ,
struct V_351 * V_352 )
{
memset ( V_352 , 0 , sizeof( * V_352 ) ) ;
memcpy ( V_384 , V_350 -> V_384 , V_145 ) ;
V_352 -> V_354 = V_385 ;
}
static int F_166 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_347 , T_3 * V_384 , struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_167 ( V_13 , V_347 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_165 ( V_350 , V_384 , V_352 ) ;
F_50 () ;
return 0 ;
}
static int F_168 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_347 , T_3 * V_384 ,
struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_169 ( V_13 , V_119 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_165 ( V_350 , V_384 , V_352 ) ;
F_50 () ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_386 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_274 ) , sizeof( struct V_386 ) ) ;
return 0 ;
}
static inline bool F_171 ( enum V_387 V_388 , T_1 V_28 )
{
return ( V_28 >> ( V_388 - 1 ) ) & 0x1 ;
}
static int F_172 ( struct V_389 * V_390 ,
const struct V_391 * V_392 )
{
T_3 * V_393 ;
const T_3 * V_394 ;
struct V_12 * V_13 = F_173 ( V_390 ,
struct V_12 , V_16 . V_74 ) ;
V_393 = NULL ;
V_394 = V_390 -> V_395 ;
if ( V_392 -> V_396 ) {
V_393 = F_174 ( V_392 -> V_395 , V_392 -> V_396 ,
V_168 ) ;
if ( ! V_393 )
return - V_169 ;
}
V_390 -> V_396 = V_392 -> V_396 ;
V_390 -> V_395 = V_393 ;
F_93 ( V_394 ) ;
V_390 -> V_397 = V_392 -> V_397 ;
memcpy ( V_390 -> V_398 , V_392 -> V_398 , V_390 -> V_397 ) ;
V_390 -> V_399 = V_392 -> V_400 ;
V_390 -> V_401 = V_392 -> V_402 ;
V_390 -> V_403 = V_392 -> V_404 ;
V_390 -> V_329 = V_392 -> V_329 ;
V_390 -> V_405 = V_392 -> V_406 ;
V_390 -> V_75 = V_76 ;
if ( V_392 -> V_407 )
V_390 -> V_75 |= V_408 ;
if ( V_392 -> V_409 )
V_390 -> V_75 |= V_410 ;
memcpy ( V_13 -> V_27 . V_216 . V_411 , V_392 -> V_411 ,
sizeof( V_392 -> V_411 ) ) ;
V_13 -> V_27 . V_216 . V_412 = V_392 -> V_412 ;
V_13 -> V_27 . V_216 . V_217 = V_392 -> V_218 ;
V_13 -> V_27 . V_216 . V_219 = V_392 -> V_219 ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_386 * V_413 )
{
struct V_386 * V_61 ;
struct V_12 * V_13 ;
struct V_389 * V_390 ;
V_13 = F_9 ( V_19 ) ;
V_390 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_274 ) ;
if ( F_171 ( V_414 , V_28 ) )
V_61 -> V_415 = V_413 -> V_415 ;
if ( F_171 ( V_416 , V_28 ) )
V_61 -> V_417 = V_413 -> V_417 ;
if ( F_171 ( V_418 , V_28 ) )
V_61 -> V_419 = V_413 -> V_419 ;
if ( F_171 ( V_420 , V_28 ) )
V_61 -> V_421 = V_413 -> V_421 ;
if ( F_171 ( V_422 , V_28 ) )
V_61 -> V_423 = V_413 -> V_423 ;
if ( F_171 ( V_424 , V_28 ) )
V_61 -> V_425 = V_413 -> V_425 ;
if ( F_171 ( V_426 , V_28 ) )
V_61 -> V_427 = V_413 -> V_427 ;
if ( F_171 ( V_428 , V_28 ) ) {
if ( V_390 -> V_329 )
return - V_31 ;
V_61 -> V_429 = V_413 -> V_429 ;
}
if ( F_171 ( V_430 , V_28 ) )
V_61 -> V_431 =
V_413 -> V_431 ;
if ( F_171 ( V_432 , V_28 ) )
V_61 -> V_433 =
V_413 -> V_433 ;
if ( F_171 ( V_434 , V_28 ) )
V_61 -> V_435 = V_413 -> V_435 ;
if ( F_171 ( V_436 , V_28 ) )
V_61 -> V_437 = V_413 -> V_437 ;
if ( F_171 ( V_438 , V_28 ) )
V_61 -> V_439 =
V_413 -> V_439 ;
if ( F_171 ( V_440 , V_28 ) )
V_61 -> V_441 =
V_413 -> V_441 ;
if ( F_171 ( V_442 , V_28 ) )
V_61 -> V_443 =
V_413 -> V_443 ;
if ( F_171 ( V_444 ,
V_28 ) )
V_61 -> V_445 =
V_413 -> V_445 ;
if ( F_171 ( V_446 , V_28 ) ) {
V_61 -> V_447 = V_413 -> V_447 ;
F_176 ( V_390 ) ;
}
if ( F_171 ( V_448 , V_28 ) ) {
if ( V_413 -> V_449 &&
! ( V_61 -> V_447 > V_450 ) ) {
V_61 -> V_447 = V_451 ;
F_176 ( V_390 ) ;
}
V_61 -> V_449 =
V_413 -> V_449 ;
}
if ( F_171 ( V_452 , V_28 ) )
V_61 -> V_453 =
V_413 -> V_453 ;
if ( F_171 ( V_454 , V_28 ) )
V_61 -> V_455 = V_413 -> V_455 ;
if ( F_171 ( V_456 , V_28 ) ) {
if ( ! F_125 ( & V_13 -> V_10 -> V_108 , V_457 ) )
return - V_458 ;
V_61 -> V_459 = V_413 -> V_459 ;
}
if ( F_171 ( V_460 , V_28 ) ) {
V_61 -> V_461 = V_413 -> V_461 ;
V_13 -> V_27 . V_216 . V_462 = V_413 -> V_461 ;
F_87 ( V_13 , V_463 ) ;
}
if ( F_171 ( V_464 , V_28 ) )
V_61 -> V_465 =
V_413 -> V_465 ;
if ( F_171 ( V_466 , V_28 ) )
V_61 -> V_467 =
V_413 -> V_467 ;
if ( F_171 ( V_468 , V_28 ) )
V_61 -> V_469 =
V_413 -> V_469 ;
if ( F_171 ( V_470 , V_28 ) ) {
V_61 -> V_275 = V_413 -> V_275 ;
F_177 ( V_13 ) ;
}
if ( F_171 ( V_471 , V_28 ) )
V_61 -> V_472 =
V_413 -> V_472 ;
if ( F_171 ( V_473 , V_28 ) )
V_61 -> V_474 = V_413 -> V_474 ;
F_121 ( V_13 , V_182 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_386 * V_61 ,
const struct V_391 * V_392 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_389 * V_390 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_390 -> V_274 , V_61 , sizeof( struct V_386 ) ) ;
V_14 = F_172 ( V_390 , V_392 ) ;
if ( V_14 )
return V_14 ;
V_13 -> V_201 = V_203 ;
V_13 -> V_208 = V_13 -> V_10 -> V_209 ;
F_16 ( & V_13 -> V_10 -> V_152 ) ;
V_14 = F_73 ( V_13 , & V_392 -> V_150 ,
V_210 ) ;
F_18 ( & V_13 -> V_10 -> V_152 ) ;
if ( V_14 )
return V_14 ;
return F_179 ( V_13 ) ;
}
static int F_180 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_181 ( V_13 ) ;
F_16 ( & V_13 -> V_10 -> V_152 ) ;
F_72 ( V_13 ) ;
F_18 ( & V_13 -> V_10 -> V_152 ) ;
return 0 ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_475 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
enum V_288 V_289 ;
T_1 V_181 = 0 ;
if ( ! F_76 ( V_13 -> V_16 . V_167 . V_183 , V_13 ) )
return - V_65 ;
V_289 = F_59 ( V_13 ) ;
if ( V_8 -> V_476 >= 0 ) {
V_13 -> V_27 . V_216 . V_476 = V_8 -> V_476 ;
V_181 |= V_477 ;
}
if ( V_8 -> V_478 >= 0 ) {
V_13 -> V_27 . V_216 . V_478 =
V_8 -> V_478 ;
V_181 |= V_479 ;
}
if ( ! V_13 -> V_27 . V_216 . V_480 &&
V_289 == V_481 ) {
V_13 -> V_27 . V_216 . V_480 = true ;
V_181 |= V_482 ;
}
if ( V_8 -> V_483 >= 0 ) {
V_13 -> V_27 . V_216 . V_480 =
V_8 -> V_483 ;
V_181 |= V_482 ;
}
if ( V_8 -> V_412 ) {
F_126 ( & V_13 -> V_27 . V_216 . V_150 ,
V_2 -> V_127 [ V_289 ] ,
V_8 -> V_412 ,
V_8 -> V_484 ,
& V_13 -> V_27 . V_216 . V_412 ) ;
V_181 |= V_485 ;
}
if ( V_8 -> V_486 >= 0 ) {
if ( V_8 -> V_486 )
V_13 -> V_6 |= V_487 ;
else
V_13 -> V_6 &= ~ V_487 ;
}
if ( V_8 -> V_461 >= 0 ) {
V_13 -> V_27 . V_216 . V_462 =
( T_2 ) V_8 -> V_461 ;
V_181 |= V_463 ;
}
if ( V_8 -> V_227 >= 0 ) {
V_13 -> V_27 . V_216 . V_225 . V_226 &=
~ V_228 ;
V_13 -> V_27 . V_216 . V_225 . V_226 |=
V_8 -> V_227 & V_228 ;
V_181 |= V_198 ;
}
if ( V_8 -> V_229 > 0 ) {
V_13 -> V_27 . V_216 . V_225 . V_226 |=
V_230 ;
V_181 |= V_198 ;
} else if ( V_8 -> V_229 == 0 ) {
V_13 -> V_27 . V_216 . V_225 . V_226 &=
~ V_230 ;
V_181 |= V_198 ;
}
F_87 ( V_13 , V_181 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_488 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_489 V_490 ;
if ( ! V_10 -> V_491 -> V_492 )
return - V_338 ;
if ( V_10 -> V_108 . V_294 < V_295 )
return - V_338 ;
memset ( & V_490 , 0 , sizeof( V_490 ) ) ;
V_490 . V_493 = V_8 -> V_493 ;
V_490 . V_494 = V_8 -> V_495 ;
V_490 . V_496 = V_8 -> V_497 ;
V_490 . V_498 = V_8 -> V_498 ;
V_490 . V_499 = false ;
V_13 -> V_500 [ V_8 -> V_501 ] = V_490 ;
if ( F_184 ( V_10 , V_13 , V_8 -> V_501 , & V_490 ) ) {
F_185 ( V_10 -> V_108 . V_2 ,
L_2 ,
V_8 -> V_501 ) ;
return - V_49 ;
}
F_87 ( V_13 , V_502 ) ;
return 0 ;
}
static int F_186 ( struct V_2 * V_2 ,
struct V_503 * V_504 )
{
return F_187 ( F_2 ( V_2 ) , V_504 ) ;
}
static int F_188 ( struct V_2 * V_2 )
{
return F_189 ( F_2 ( V_2 ) ) ;
}
static int F_190 ( struct V_2 * V_2 ,
struct V_505 * V_506 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_506 -> V_11 ) ;
switch ( F_191 ( & V_13 -> V_27 ) ) {
case V_25 :
case V_72 :
case V_73 :
case V_81 :
case V_78 :
break;
case V_82 :
if ( V_13 -> V_10 -> V_491 -> V_507 )
break;
case V_70 :
if ( V_13 -> V_16 . V_167 . V_183 &&
( ! ( V_2 -> V_508 & V_509 ) ||
! ( V_506 -> V_6 & V_510 ) ) )
return - V_338 ;
break;
default:
return - V_338 ;
}
return F_192 ( V_13 , V_506 ) ;
}
static int
F_193 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_511 * V_506 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_491 -> V_512 )
return - V_338 ;
return F_194 ( V_13 , V_506 ) ;
}
static int
F_195 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_491 -> V_513 )
return - V_338 ;
return F_196 ( V_10 ) ;
}
static int F_197 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_514 * V_506 )
{
return F_198 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_515 * V_506 )
{
return F_200 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_201 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_516 * V_506 )
{
return F_202 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_203 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_517 * V_506 )
{
return F_204 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_205 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_518 * V_8 )
{
return F_206 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_207 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_208 ( F_9 ( V_19 ) ) ;
}
static int F_209 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_519 * V_392 )
{
return F_210 ( F_9 ( V_19 ) , V_392 ) ;
}
static int F_211 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_212 ( F_9 ( V_19 ) ) ;
}
static int F_213 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_113 [ V_520 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_216 . V_411 , V_113 ,
sizeof( int ) * V_520 ) ;
return 0 ;
}
static int F_214 ( struct V_2 * V_2 , T_1 V_181 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_181 & V_521 ) {
F_215 ( V_10 ) ;
V_14 = F_216 ( V_10 , V_2 -> V_522 ) ;
if ( V_14 ) {
F_215 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_181 & V_523 ) ||
( V_181 & V_524 ) ) {
T_6 V_525 ;
V_525 = V_181 & V_523 ?
V_2 -> V_525 : - 1 ;
V_14 = F_217 ( V_10 , V_525 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_181 & V_526 ) {
V_14 = F_218 ( V_10 , V_2 -> V_527 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_181 & V_528 ) {
if ( V_2 -> V_529 > V_530 )
return - V_49 ;
V_10 -> V_108 . V_61 . V_531 = V_2 -> V_529 ;
}
if ( V_181 & V_532 ) {
if ( V_2 -> V_533 > V_530 )
return - V_49 ;
V_10 -> V_108 . V_61 . V_534 = V_2 -> V_533 ;
}
if ( V_181 &
( V_528 | V_532 ) )
F_74 ( V_10 , V_535 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
enum V_536 type , int V_537 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
enum V_536 V_538 = type ;
bool V_539 = false ;
if ( V_11 ) {
V_13 = F_5 ( V_11 ) ;
switch ( type ) {
case V_540 :
V_13 -> V_541 = V_542 ;
V_538 = V_543 ;
break;
case V_543 :
case V_544 :
if ( V_537 < 0 || ( V_537 % 100 ) )
return - V_338 ;
V_13 -> V_541 = F_220 ( V_537 ) ;
break;
}
if ( V_538 != V_13 -> V_27 . V_216 . V_545 ) {
V_539 = true ;
V_13 -> V_27 . V_216 . V_545 = V_538 ;
}
F_221 ( V_13 , V_539 ) ;
return 0 ;
}
switch ( type ) {
case V_540 :
V_10 -> V_541 = V_542 ;
V_538 = V_543 ;
break;
case V_543 :
case V_544 :
if ( V_537 < 0 || ( V_537 % 100 ) )
return - V_338 ;
V_10 -> V_541 = F_220 ( V_537 ) ;
break;
}
F_16 ( & V_10 -> V_153 ) ;
F_84 (sdata, &local->interfaces, list) {
V_13 -> V_541 = V_10 -> V_541 ;
if ( V_538 != V_13 -> V_27 . V_216 . V_545 )
V_539 = true ;
V_13 -> V_27 . V_216 . V_545 = V_538 ;
}
F_84 (sdata, &local->interfaces, list)
F_221 ( V_13 , V_539 ) ;
F_18 ( & V_10 -> V_153 ) ;
return 0 ;
}
static int F_222 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_546 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_491 -> V_547 )
return F_223 ( V_10 , V_13 , V_546 ) ;
if ( ! V_10 -> V_154 )
* V_546 = V_10 -> V_108 . V_61 . V_548 ;
else
* V_546 = V_13 -> V_27 . V_216 . V_549 ;
return 0 ;
}
static int F_224 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_144 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_550 . V_551 , V_144 , V_145 ) ;
return 0 ;
}
static void F_225 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_226 ( V_10 ) ;
}
static int F_227 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
void * V_171 , int V_170 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_552 * V_27 = NULL ;
if ( ! V_10 -> V_491 -> V_553 )
return - V_338 ;
if ( V_11 ) {
struct V_12 * V_13 ;
V_13 = F_5 ( V_11 ) ;
if ( V_13 -> V_6 & V_554 )
V_27 = & V_13 -> V_27 ;
}
return V_10 -> V_491 -> V_553 ( & V_10 -> V_108 , V_27 , V_171 , V_170 ) ;
}
static int F_228 ( struct V_2 * V_2 ,
struct V_248 * V_249 ,
struct V_555 * V_257 ,
void * V_171 , int V_170 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_491 -> V_556 )
return - V_338 ;
return V_10 -> V_491 -> V_556 ( & V_10 -> V_108 , V_249 , V_257 , V_171 , V_170 ) ;
}
int F_229 ( struct V_12 * V_13 ,
enum V_557 V_201 )
{
struct V_38 * V_24 ;
enum V_557 V_558 ;
if ( F_35 ( V_13 -> V_27 . type != V_70 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_216 . V_150 . V_559 == V_560 )
return 0 ;
V_558 = V_13 -> V_16 . V_167 . V_345 ;
V_13 -> V_16 . V_167 . V_345 = V_201 ;
if ( V_558 == V_201 ||
V_201 == V_561 )
return 0 ;
if ( ! F_230 ( & V_13 -> V_16 . V_167 . V_343 ) ) {
V_13 -> V_201 = V_201 ;
F_231 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_562 ) ;
return 0 ;
}
F_146 ( V_13 ,
L_3 ,
V_201 , F_230 ( & V_13 -> V_16 . V_167 . V_343 ) ) ;
F_16 ( & V_13 -> V_10 -> V_63 ) ;
F_84 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_342 != & V_13 -> V_16 . V_167 )
continue;
if ( F_145 ( V_24 ) == 1 )
continue;
if ( F_32 ( V_24 , V_563 ) &&
! F_232 ( V_24 -> V_344 ,
V_201 ) ) {
F_146 ( V_13 , L_4 ,
V_24 -> V_24 . V_144 ) ;
continue;
}
if ( ! F_32 ( V_24 , V_267 ) )
continue;
F_146 ( V_13 , L_5 , V_24 -> V_24 . V_144 ) ;
F_147 ( V_13 , V_201 , V_24 -> V_24 . V_144 ,
V_13 -> V_27 . V_216 . V_346 ) ;
}
F_18 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_201 = V_201 ;
F_231 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_562 ) ;
return 0 ;
}
int F_233 ( struct V_12 * V_13 ,
enum V_557 V_201 )
{
const T_3 * V_167 ;
enum V_557 V_558 ;
int V_14 ;
struct V_38 * V_24 ;
bool V_564 = false ;
F_234 ( & V_13 -> V_11 . V_152 ) ;
if ( F_35 ( V_13 -> V_27 . type != V_25 ) )
return - V_49 ;
V_558 = V_13 -> V_16 . V_26 . V_345 ;
V_13 -> V_16 . V_26 . V_345 = V_201 ;
if ( V_558 == V_201 &&
V_201 != V_561 )
return 0 ;
if ( ! V_13 -> V_16 . V_26 . V_565 ||
V_13 -> V_27 . V_216 . V_150 . V_559 == V_560 )
return 0 ;
V_167 = V_13 -> V_16 . V_26 . V_565 -> V_346 ;
F_42 () ;
F_235 (sta, &sdata->local->sta_list, list) {
if ( ! V_24 -> V_24 . V_323 || V_24 -> V_13 != V_13 || ! V_24 -> V_566 ||
! F_32 ( V_24 , V_267 ) )
continue;
V_564 = true ;
break;
}
F_50 () ;
if ( V_201 == V_561 ) {
if ( V_564 || ! V_13 -> V_16 . V_26 . V_567 )
V_201 = V_203 ;
else
V_201 = V_207 ;
}
V_14 = F_147 ( V_13 , V_201 ,
V_167 , V_167 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_345 = V_558 ;
else if ( V_201 != V_203 && V_564 )
F_236 ( V_13 ) ;
return V_14 ;
}
static int F_237 ( struct V_2 * V_2 , struct V_18 * V_19 ,
bool V_568 , int V_569 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_65 ( V_19 -> V_148 ) ;
if ( V_13 -> V_27 . type != V_25 )
return - V_338 ;
if ( ! F_125 ( & V_10 -> V_108 , V_570 ) )
return - V_338 ;
if ( V_568 == V_13 -> V_16 . V_26 . V_567 &&
V_569 == V_10 -> V_571 )
return 0 ;
V_13 -> V_16 . V_26 . V_567 = V_568 ;
V_10 -> V_571 = V_569 ;
F_238 ( V_13 ) ;
F_233 ( V_13 , V_13 -> V_16 . V_26 . V_345 ) ;
F_239 ( V_13 ) ;
if ( F_125 ( & V_10 -> V_108 , V_572 ) )
F_74 ( V_10 , V_573 ) ;
F_148 ( V_10 ) ;
F_149 ( V_13 ) ;
return 0 ;
}
static int F_240 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
T_7 V_574 , T_1 V_575 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_552 * V_27 = & V_13 -> V_27 ;
struct V_576 * V_216 = & V_27 -> V_216 ;
if ( V_574 == V_216 -> V_577 &&
V_575 == V_216 -> V_578 )
return 0 ;
if ( V_13 -> V_27 . V_579 & V_580 &&
! ( V_13 -> V_27 . V_579 & V_581 ) )
return - V_338 ;
V_216 -> V_577 = V_574 ;
V_216 -> V_578 = V_575 ;
V_13 -> V_16 . V_26 . V_582 = 0 ;
if ( V_13 -> V_16 . V_26 . V_565 &&
V_13 -> V_27 . V_579 & V_581 )
F_87 ( V_13 , V_583 ) ;
return 0 ;
}
static int F_241 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
const T_3 * V_144 ,
const struct V_584 * V_28 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = F_65 ( V_19 -> V_148 ) ;
int V_585 , V_20 ;
if ( ! F_12 ( V_13 ) )
return - V_43 ;
if ( F_125 ( & V_10 -> V_108 , V_586 ) ) {
V_20 = F_242 ( V_10 , V_13 , V_28 ) ;
if ( V_20 )
return V_20 ;
}
for ( V_585 = 0 ; V_585 < V_520 ; V_585 ++ ) {
struct V_123 * V_124 = V_2 -> V_127 [ V_585 ] ;
int V_587 ;
V_13 -> V_588 [ V_585 ] = V_28 -> V_254 [ V_585 ] . V_130 ;
memcpy ( V_13 -> V_589 [ V_585 ] , V_28 -> V_254 [ V_585 ] . V_590 ,
sizeof( V_28 -> V_254 [ V_585 ] . V_590 ) ) ;
memcpy ( V_13 -> V_591 [ V_585 ] ,
V_28 -> V_254 [ V_585 ] . V_592 ,
sizeof( V_28 -> V_254 [ V_585 ] . V_592 ) ) ;
V_13 -> V_593 [ V_585 ] = false ;
V_13 -> V_594 [ V_585 ] = false ;
if ( ! V_124 )
continue;
for ( V_587 = 0 ; V_587 < V_595 ; V_587 ++ ) {
if ( ~ V_13 -> V_589 [ V_585 ] [ V_587 ] ) {
V_13 -> V_593 [ V_585 ] = true ;
break;
}
}
for ( V_587 = 0 ; V_587 < V_596 ; V_587 ++ ) {
if ( ~ V_13 -> V_591 [ V_585 ] [ V_587 ] ) {
V_13 -> V_594 [ V_585 ] = true ;
break;
}
}
}
return 0 ;
}
static bool F_243 ( struct V_9 * V_10 ,
struct V_597 * V_598 ,
struct V_597 * V_599 )
{
unsigned long V_600 = V_369 ;
unsigned long V_601 = V_599 -> V_602 +
F_244 ( V_599 -> V_603 ) -
V_600 ;
if ( F_49 ( ! V_599 -> V_604 || ! V_599 -> V_605 ) )
return false ;
if ( V_598 -> V_603 > F_161 ( V_601 ) )
return false ;
F_245 ( V_598 ) ;
F_246 ( & V_598 -> V_606 , & V_599 -> V_607 ) ;
return true ;
}
static T_4 F_247 ( struct V_9 * V_10 )
{
F_234 ( & V_10 -> V_152 ) ;
V_10 -> V_608 ++ ;
if ( F_49 ( V_10 -> V_608 == 0 ) )
V_10 -> V_608 ++ ;
return V_10 -> V_608 ;
}
static int F_248 ( struct V_9 * V_10 ,
struct V_12 * V_13 ,
struct V_609 * V_610 ,
unsigned int V_603 , T_4 * V_89 ,
struct V_248 * V_611 ,
enum V_612 type )
{
struct V_597 * V_613 , * V_614 ;
bool V_615 = false ;
int V_20 ;
F_234 ( & V_10 -> V_152 ) ;
if ( V_10 -> V_154 && ! V_10 -> V_491 -> V_616 )
return - V_338 ;
V_613 = F_77 ( sizeof( * V_613 ) , V_168 ) ;
if ( ! V_613 )
return - V_169 ;
if ( ! V_603 )
V_603 = 10 ;
V_613 -> V_617 = V_610 ;
V_613 -> V_603 = V_603 ;
V_613 -> V_618 = V_603 ;
V_613 -> V_619 = V_611 ;
V_613 -> type = type ;
V_613 -> V_13 = V_13 ;
F_249 ( & V_613 -> V_620 , V_621 ) ;
F_250 ( & V_613 -> V_607 ) ;
if ( ! V_611 ) {
V_613 -> V_89 = F_247 ( V_10 ) ;
* V_89 = V_613 -> V_89 ;
} else {
V_613 -> V_622 = * V_89 ;
}
if ( ! F_251 ( & V_10 -> V_623 ) ||
V_10 -> V_624 || F_252 ( V_10 ) )
goto V_625;
if ( ! V_10 -> V_491 -> V_616 ) {
F_253 ( & V_10 -> V_108 , & V_613 -> V_620 , 0 ) ;
goto V_626;
}
V_20 = F_254 ( V_10 , V_13 , V_610 , V_603 , type ) ;
if ( V_20 ) {
F_93 ( V_613 ) ;
return V_20 ;
}
V_613 -> V_604 = true ;
goto V_626;
V_625:
F_84 (tmp, &local->roc_list, list) {
if ( V_614 -> V_617 != V_610 || V_614 -> V_13 != V_13 )
continue;
if ( ! V_614 -> V_604 ) {
F_246 ( & V_613 -> V_606 , & V_614 -> V_607 ) ;
V_614 -> V_603 = F_255 ( V_614 -> V_603 , V_613 -> V_603 ) ;
V_614 -> type = F_255 ( V_614 -> type , V_613 -> type ) ;
V_615 = true ;
break;
}
if ( V_10 -> V_491 -> V_616 ) {
if ( ! V_614 -> V_605 ) {
F_246 ( & V_613 -> V_606 , & V_614 -> V_607 ) ;
V_615 = true ;
break;
}
if ( F_243 ( V_10 , V_613 , V_614 ) )
V_615 = true ;
} else if ( F_256 ( & V_614 -> V_620 . V_627 ) ) {
unsigned long V_628 ;
F_246 ( & V_613 -> V_606 , & V_614 -> V_607 ) ;
V_615 = true ;
V_628 = V_369 + F_244 ( V_613 -> V_603 ) ;
if ( F_257 ( V_628 , V_614 -> V_620 . V_627 . V_629 ) )
F_258 ( & V_614 -> V_620 . V_627 , V_628 ) ;
else
F_259 ( & V_614 -> V_620 . V_627 ) ;
F_245 ( V_613 ) ;
}
break;
}
V_626:
if ( ! V_615 )
F_246 ( & V_613 -> V_606 , & V_10 -> V_623 ) ;
return 0 ;
}
static int F_260 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_609 * V_617 ,
unsigned int V_603 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_20 ;
F_16 ( & V_10 -> V_152 ) ;
V_20 = F_248 ( V_10 , V_13 , V_617 ,
V_603 , V_89 , NULL ,
V_630 ) ;
F_18 ( & V_10 -> V_152 ) ;
return V_20 ;
}
static int F_261 ( struct V_9 * V_10 ,
T_4 V_89 , bool V_631 )
{
struct V_597 * V_613 , * V_614 , * V_632 = NULL ;
int V_20 ;
F_16 ( & V_10 -> V_152 ) ;
F_262 (roc, tmp, &local->roc_list, list) {
struct V_597 * V_633 , * V_634 ;
F_262 (dep, tmp2, &roc->dependents, list) {
if ( ! V_631 && V_633 -> V_89 != V_89 )
continue;
else if ( V_631 && V_633 -> V_622 != V_89 )
continue;
F_263 ( & V_633 -> V_606 ) ;
F_18 ( & V_10 -> V_152 ) ;
F_264 ( V_633 , true ) ;
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
F_18 ( & V_10 -> V_152 ) ;
return - V_65 ;
}
if ( V_10 -> V_491 -> V_616 ) {
if ( V_632 -> V_604 ) {
V_20 = F_265 ( V_10 ) ;
if ( F_35 ( V_20 ) ) {
F_18 ( & V_10 -> V_152 ) ;
return V_20 ;
}
}
F_263 ( & V_632 -> V_606 ) ;
if ( V_632 -> V_604 )
F_266 ( V_10 ) ;
F_18 ( & V_10 -> V_152 ) ;
F_264 ( V_632 , true ) ;
} else {
V_632 -> abort = true ;
F_253 ( & V_10 -> V_108 , & V_632 -> V_620 , 0 ) ;
F_18 ( & V_10 -> V_152 ) ;
F_267 ( & V_632 -> V_620 ) ;
F_49 ( ! V_632 -> V_635 ) ;
F_93 ( V_632 ) ;
}
return 0 ;
}
static int F_268 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
return F_261 ( V_10 , V_89 , false ) ;
}
static int F_269 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_149 * V_150 ,
T_1 V_636 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_152 ) ;
if ( ! F_251 ( & V_10 -> V_623 ) || V_10 -> V_624 ) {
V_14 = - V_31 ;
goto V_66;
}
V_13 -> V_201 = V_203 ;
V_13 -> V_208 = V_10 -> V_209 ;
V_14 = F_73 ( V_13 , V_150 ,
V_210 ) ;
if ( V_14 )
goto V_66;
F_253 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_241 ,
F_244 ( V_636 ) ) ;
V_66:
F_18 ( & V_10 -> V_152 ) ;
return V_14 ;
}
static struct V_176 *
F_270 ( struct V_176 * V_183 )
{
struct V_176 * V_637 ;
T_3 * V_638 ;
int V_170 ;
V_170 = V_183 -> V_185 + V_183 -> V_187 + V_183 -> V_639 +
V_183 -> V_640 + V_183 -> V_641 +
V_183 -> V_192 ;
V_637 = F_77 ( sizeof( * V_637 ) + V_170 , V_168 ) ;
if ( ! V_637 )
return NULL ;
V_638 = ( T_3 * ) ( V_637 + 1 ) ;
if ( V_183 -> V_185 ) {
V_637 -> V_185 = V_183 -> V_185 ;
V_637 -> V_184 = V_638 ;
memcpy ( V_638 , V_183 -> V_184 , V_183 -> V_185 ) ;
V_638 += V_183 -> V_185 ;
}
if ( V_183 -> V_187 ) {
V_637 -> V_187 = V_183 -> V_187 ;
V_637 -> V_186 = V_638 ;
memcpy ( V_638 , V_183 -> V_186 , V_183 -> V_187 ) ;
V_638 += V_183 -> V_187 ;
}
if ( V_183 -> V_639 ) {
V_637 -> V_639 = V_183 -> V_639 ;
V_637 -> V_642 = V_638 ;
memcpy ( V_638 , V_183 -> V_642 , V_183 -> V_639 ) ;
V_638 += V_183 -> V_639 ;
}
if ( V_183 -> V_640 ) {
V_637 -> V_640 = V_183 -> V_640 ;
V_637 -> V_643 = V_638 ;
memcpy ( V_638 , V_183 -> V_643 , V_183 -> V_640 ) ;
V_638 += V_183 -> V_640 ;
}
if ( V_183 -> V_641 ) {
V_637 -> V_641 = V_183 -> V_641 ;
V_637 -> V_644 = V_638 ;
memcpy ( V_638 , V_183 -> V_644 , V_183 -> V_641 ) ;
V_638 += V_183 -> V_641 ;
}
if ( V_183 -> V_192 ) {
V_637 -> V_192 = V_183 -> V_192 ;
V_183 -> V_164 = V_638 ;
memcpy ( V_638 , V_183 -> V_164 , V_183 -> V_192 ) ;
V_638 += V_183 -> V_192 ;
}
return V_637 ;
}
void F_271 ( struct V_552 * V_27 )
{
struct V_12 * V_13 = F_272 ( V_27 ) ;
F_231 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_645 ) ;
}
static int F_273 ( struct V_12 * V_13 ,
T_1 * V_181 )
{
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_14 = F_80 ( V_13 , V_13 -> V_16 . V_167 . V_236 ,
NULL ) ;
F_93 ( V_13 -> V_16 . V_167 . V_236 ) ;
V_13 -> V_16 . V_167 . V_236 = NULL ;
if ( V_14 < 0 )
return V_14 ;
* V_181 |= V_14 ;
break;
case V_72 :
V_14 = F_274 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_181 |= V_14 ;
break;
#ifdef F_34
case V_73 :
V_14 = F_275 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_181 |= V_14 ;
break;
#endif
default:
F_49 ( 1 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_276 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_181 = 0 ;
int V_14 ;
F_90 ( V_13 ) ;
F_234 ( & V_10 -> V_152 ) ;
F_234 ( & V_10 -> V_32 ) ;
if ( V_13 -> V_646 ) {
if ( V_13 -> V_647 )
return 0 ;
return F_277 ( V_13 ) ;
}
if ( ! F_69 ( & V_13 -> V_27 . V_216 . V_150 ,
& V_13 -> V_648 ) )
return - V_49 ;
V_13 -> V_27 . V_231 = false ;
V_14 = F_273 ( V_13 , & V_181 ) ;
if ( V_14 )
return V_14 ;
F_87 ( V_13 , V_181 ) ;
if ( V_13 -> V_234 ) {
F_92 ( V_10 , V_13 ,
V_235 ) ;
V_13 -> V_234 = false ;
}
V_14 = F_278 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_279 ( V_13 -> V_19 , & V_13 -> V_648 ) ;
return 0 ;
}
static void F_280 ( struct V_12 * V_13 )
{
if ( F_276 ( V_13 ) ) {
F_281 ( V_13 , L_6 ) ;
F_282 ( V_13 -> V_10 -> V_108 . V_2 , & V_13 -> V_11 ,
V_168 ) ;
}
}
void F_283 ( struct V_649 * V_620 )
{
struct V_12 * V_13 =
F_173 ( V_620 , struct V_12 ,
V_645 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_238 ( V_13 ) ;
F_16 ( & V_10 -> V_152 ) ;
F_16 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_231 )
goto V_650;
if ( ! F_12 ( V_13 ) )
goto V_650;
F_280 ( V_13 ) ;
V_650:
F_18 ( & V_10 -> V_32 ) ;
F_18 ( & V_10 -> V_152 ) ;
F_239 ( V_13 ) ;
}
static int F_284 ( struct V_12 * V_13 ,
struct V_651 * V_8 ,
T_1 * V_181 )
{
struct V_162 V_163 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_167 . V_236 =
F_270 ( & V_8 -> V_652 ) ;
if ( ! V_13 -> V_16 . V_167 . V_236 )
return - V_169 ;
if ( V_8 -> V_189 <= 1 )
break;
if ( ( V_8 -> V_191 >
V_653 ) ||
( V_8 -> V_174 >
V_653 ) )
return - V_49 ;
V_163 . V_190 = V_8 -> V_190 ;
V_163 . V_173 = V_8 -> V_173 ;
V_163 . V_191 = V_8 -> V_191 ;
V_163 . V_174 = V_8 -> V_174 ;
V_163 . V_189 = V_8 -> V_189 ;
V_14 = F_80 ( V_13 , & V_8 -> V_654 , & V_163 ) ;
if ( V_14 < 0 ) {
F_93 ( V_13 -> V_16 . V_167 . V_236 ) ;
return V_14 ;
}
* V_181 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_216 . V_655 )
return - V_49 ;
if ( V_8 -> V_150 . V_559 != V_13 -> V_16 . V_656 . V_150 . V_559 )
return - V_49 ;
switch ( V_8 -> V_150 . V_559 ) {
case V_657 :
if ( F_285 ( & V_8 -> V_150 ) !=
F_285 ( & V_13 -> V_16 . V_656 . V_150 ) )
return - V_49 ;
case V_658 :
case V_659 :
case V_560 :
case V_660 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_656 . V_150 . V_617 -> V_289 !=
V_8 -> V_150 . V_617 -> V_289 )
return - V_49 ;
if ( V_8 -> V_189 > 1 ) {
V_14 = F_286 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_181 |= V_14 ;
}
F_287 ( V_13 , V_8 ) ;
break;
#ifdef F_34
case V_73 : {
struct V_389 * V_390 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_150 . V_559 != V_13 -> V_27 . V_216 . V_150 . V_559 )
return - V_49 ;
if ( V_13 -> V_27 . V_216 . V_150 . V_617 -> V_289 !=
V_8 -> V_150 . V_617 -> V_289 )
return - V_49 ;
if ( V_390 -> V_661 == V_662 ) {
V_390 -> V_661 = V_663 ;
if ( ! V_390 -> V_664 )
V_390 -> V_664 = 1 ;
else
V_390 -> V_664 ++ ;
}
if ( V_8 -> V_189 > 1 ) {
V_14 = F_288 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_390 -> V_661 = V_662 ;
return V_14 ;
}
* V_181 |= V_14 ;
}
if ( V_390 -> V_661 == V_663 )
F_287 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_338 ;
}
return 0 ;
}
static int
F_289 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_651 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_665 V_666 ;
struct V_667 * V_61 ;
struct V_668 * V_669 ;
T_1 V_181 = 0 ;
int V_14 ;
F_90 ( V_13 ) ;
F_234 ( & V_10 -> V_152 ) ;
if ( ! F_251 ( & V_10 -> V_623 ) || V_10 -> V_624 )
return - V_31 ;
if ( V_13 -> V_11 . V_240 )
return - V_31 ;
if ( F_69 ( & V_8 -> V_150 ,
& V_13 -> V_27 . V_216 . V_150 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_231 )
return - V_31 ;
F_16 ( & V_10 -> V_32 ) ;
V_61 = F_70 ( V_13 -> V_27 . V_670 ,
F_71 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_95;
}
V_669 = F_173 ( V_61 , struct V_668 , V_61 ) ;
if ( ! V_669 ) {
V_14 = - V_31 ;
goto V_95;
}
V_666 . V_671 = 0 ;
V_666 . V_672 = 0 ;
V_666 . V_673 = V_8 -> V_673 ;
V_666 . V_150 = V_8 -> V_150 ;
V_666 . V_189 = V_8 -> V_189 ;
V_14 = F_290 ( V_13 , & V_666 ) ;
if ( V_14 )
goto V_95;
V_14 = F_291 ( V_13 , & V_8 -> V_150 ,
V_669 -> V_674 ,
V_8 -> V_675 ) ;
if ( V_14 )
goto V_95;
V_14 = F_17 ( V_13 , NULL , V_669 -> V_674 , 0 ) ;
if ( V_14 ) {
F_292 ( V_13 ) ;
goto V_95;
}
V_14 = F_284 ( V_13 , V_8 , & V_181 ) ;
if ( V_14 ) {
F_292 ( V_13 ) ;
goto V_95;
}
V_13 -> V_648 = V_8 -> V_150 ;
V_13 -> V_234 = V_8 -> V_673 ;
V_13 -> V_27 . V_231 = true ;
if ( V_13 -> V_234 )
F_293 ( V_10 , V_13 ,
V_235 ) ;
F_294 ( V_13 -> V_19 , & V_13 -> V_648 ,
V_8 -> V_189 ) ;
if ( V_181 ) {
F_87 ( V_13 , V_181 ) ;
F_295 ( V_13 , & V_8 -> V_150 ) ;
} else {
F_280 ( V_13 ) ;
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
F_16 ( & V_10 -> V_152 ) ;
V_14 = F_289 ( V_2 , V_19 , V_8 ) ;
F_18 ( & V_10 -> V_152 ) ;
return V_14 ;
}
static struct V_248 * F_296 ( struct V_9 * V_10 ,
struct V_248 * V_249 , T_4 * V_89 ,
T_8 V_676 )
{
unsigned long V_677 ;
struct V_248 * V_678 ;
int V_679 ;
V_678 = F_297 ( V_249 , V_676 ) ;
if ( ! V_678 )
return F_4 ( - V_169 ) ;
F_298 ( & V_10 -> V_680 , V_677 ) ;
V_679 = F_299 ( & V_10 -> V_681 , V_678 ,
1 , 0x10000 , V_682 ) ;
F_300 ( & V_10 -> V_680 , V_677 ) ;
if ( V_679 < 0 ) {
F_301 ( V_678 ) ;
return F_4 ( - V_169 ) ;
}
F_302 ( V_249 ) -> V_683 = V_679 ;
* V_89 = F_247 ( V_10 ) ;
F_302 ( V_678 ) -> V_684 . V_89 = * V_89 ;
return V_678 ;
}
static int F_303 ( struct V_2 * V_2 , struct V_1 * V_11 ,
struct V_685 * V_8 ,
T_4 * V_89 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_248 * V_249 , * V_678 ;
struct V_38 * V_24 ;
const struct V_686 * V_687 = ( void * ) V_8 -> V_688 ;
bool V_689 = false ;
T_1 V_6 ;
int V_20 ;
T_3 * V_171 ;
if ( V_8 -> V_690 )
V_6 = V_691 ;
else
V_6 = V_692 |
V_693 ;
if ( V_8 -> V_694 )
V_6 |= V_695 ;
switch ( V_13 -> V_27 . type ) {
case V_72 :
if ( ! V_13 -> V_27 . V_216 . V_655 )
V_689 = true ;
#ifdef F_34
case V_73 :
if ( F_29 ( & V_13 -> V_27 ) &&
! V_13 -> V_16 . V_74 . V_397 )
V_689 = true ;
#endif
case V_70 :
case V_21 :
case V_82 :
if ( V_13 -> V_27 . type != V_72 &&
! F_29 ( & V_13 -> V_27 ) &&
! F_304 ( V_13 -> V_342 -> V_183 ) )
V_689 = true ;
if ( ! F_305 ( V_687 -> V_696 ) ||
V_687 -> V_16 . V_697 . V_698 == V_699 ||
V_687 -> V_16 . V_697 . V_698 == V_700 ||
V_687 -> V_16 . V_697 . V_698 == V_701 )
break;
F_42 () ;
V_24 = F_30 ( V_13 , V_687 -> V_250 ) ;
F_50 () ;
if ( ! V_24 )
return - V_702 ;
break;
case V_25 :
case V_81 :
F_238 ( V_13 ) ;
if ( ! V_13 -> V_16 . V_26 . V_565 ||
( V_8 -> V_703 && V_8 -> V_704 &&
V_10 -> V_491 -> V_616 &&
memcmp ( V_13 -> V_16 . V_26 . V_565 -> V_346 ,
V_687 -> V_346 , V_145 ) ) )
V_689 = true ;
F_239 ( V_13 ) ;
break;
case V_78 :
V_689 = true ;
break;
default:
return - V_338 ;
}
if ( V_689 && ! V_8 -> V_617 )
return - V_49 ;
F_16 ( & V_10 -> V_152 ) ;
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
V_249 = F_104 ( V_10 -> V_108 . V_706 + V_8 -> V_170 ) ;
if ( ! V_249 ) {
V_20 = - V_169 ;
goto V_66;
}
F_306 ( V_249 , V_10 -> V_108 . V_706 ) ;
V_171 = F_105 ( V_249 , V_8 -> V_170 ) ;
memcpy ( V_171 , V_8 -> V_688 , V_8 -> V_170 ) ;
if ( V_13 -> V_27 . V_231 &&
( V_13 -> V_27 . type == V_70 ||
V_13 -> V_27 . type == V_73 ||
V_13 -> V_27 . type == V_72 ) &&
V_8 -> V_707 ) {
int V_585 ;
struct V_177 * V_183 = NULL ;
F_42 () ;
if ( V_13 -> V_27 . type == V_70 )
V_183 = F_43 ( V_13 -> V_16 . V_167 . V_183 ) ;
else if ( V_13 -> V_27 . type == V_72 )
V_183 = F_43 ( V_13 -> V_16 . V_656 . V_708 ) ;
else if ( F_29 ( & V_13 -> V_27 ) )
V_183 = F_43 ( V_13 -> V_16 . V_74 . V_183 ) ;
if ( V_183 )
for ( V_585 = 0 ; V_585 < V_8 -> V_707 ; V_585 ++ )
V_171 [ V_8 -> V_709 [ V_585 ] ] =
V_183 -> V_188 ;
F_50 () ;
}
F_302 ( V_249 ) -> V_6 = V_6 ;
V_249 -> V_19 = V_13 -> V_19 ;
if ( ! V_8 -> V_690 ) {
V_678 = F_296 ( V_10 , V_249 , V_89 ,
V_168 ) ;
if ( F_25 ( V_678 ) ) {
V_20 = F_28 ( V_678 ) ;
F_301 ( V_249 ) ;
goto V_66;
}
} else {
* V_89 = 0xffffffff ;
}
if ( ! V_689 ) {
F_307 ( V_13 , V_249 ) ;
V_20 = 0 ;
goto V_66;
}
F_302 ( V_249 ) -> V_6 |= V_710 |
V_711 ;
if ( F_125 ( & V_10 -> V_108 , V_712 ) )
F_302 ( V_249 ) -> V_713 =
V_10 -> V_108 . V_714 ;
V_20 = F_248 ( V_10 , V_13 , V_8 -> V_617 ,
V_8 -> V_704 , V_89 , V_249 ,
V_715 ) ;
if ( V_20 )
F_301 ( V_249 ) ;
V_66:
F_18 ( & V_10 -> V_152 ) ;
return V_20 ;
}
static int F_308 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_4 V_89 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_261 ( V_10 , V_89 , true ) ;
}
static void F_309 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_716 , bool V_717 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_716 ) {
case V_718 | V_719 :
if ( V_717 ) {
V_10 -> V_720 ++ ;
V_13 -> V_27 . V_720 ++ ;
} else {
if ( V_10 -> V_720 )
V_10 -> V_720 -- ;
if ( V_13 -> V_27 . V_720 )
V_13 -> V_27 . V_720 -- ;
}
if ( ! V_10 -> V_157 )
break;
if ( V_13 -> V_27 . V_720 == 1 )
F_310 ( V_10 , V_13 , V_721 ,
V_721 ) ;
else if ( V_13 -> V_27 . V_720 == 0 )
F_310 ( V_10 , V_13 , 0 ,
V_721 ) ;
F_14 ( V_10 ) ;
break;
default:
break;
}
}
static int F_311 ( struct V_2 * V_2 , T_1 V_722 , T_1 V_723 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_604 )
return - V_338 ;
return F_312 ( V_10 , V_722 , V_723 ) ;
}
static int F_313 ( struct V_2 * V_2 , T_1 * V_722 , T_1 * V_723 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_314 ( V_10 , V_722 , V_723 ) ;
}
static int F_315 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_724 * V_171 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_491 -> V_725 )
return - V_338 ;
F_316 ( V_10 , V_13 , V_171 ) ;
return 0 ;
}
static int F_317 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_726 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_727 * V_728 ;
struct V_248 * V_249 , * V_678 ;
int V_180 = sizeof( * V_728 ) ;
T_9 V_729 ;
bool V_730 ;
struct V_731 * V_732 ;
struct V_38 * V_24 ;
struct V_667 * V_670 ;
enum V_288 V_289 ;
int V_20 ;
F_16 ( & V_10 -> V_152 ) ;
F_42 () ;
V_670 = F_43 ( V_13 -> V_27 . V_670 ) ;
if ( F_49 ( ! V_670 ) ) {
V_20 = - V_49 ;
goto V_650;
}
V_289 = V_670 -> V_705 . V_617 -> V_289 ;
V_24 = F_31 ( V_13 , V_726 ) ;
if ( V_24 ) {
V_730 = V_24 -> V_24 . V_296 ;
} else {
V_20 = - V_702 ;
goto V_650;
}
if ( V_730 ) {
V_729 = F_318 ( V_733 |
V_734 |
V_735 ) ;
} else {
V_180 -= 2 ;
V_729 = F_318 ( V_733 |
V_736 |
V_735 ) ;
}
V_249 = F_104 ( V_10 -> V_108 . V_706 + V_180 ) ;
if ( ! V_249 ) {
V_20 = - V_169 ;
goto V_650;
}
V_249 -> V_19 = V_19 ;
F_306 ( V_249 , V_10 -> V_108 . V_706 ) ;
V_728 = ( void * ) F_105 ( V_249 , V_180 ) ;
V_728 -> V_696 = V_729 ;
V_728 -> V_737 = 0 ;
memcpy ( V_728 -> V_738 , V_24 -> V_24 . V_144 , V_145 ) ;
memcpy ( V_728 -> V_739 , V_13 -> V_27 . V_144 , V_145 ) ;
memcpy ( V_728 -> V_740 , V_13 -> V_27 . V_144 , V_145 ) ;
V_728 -> V_741 = 0 ;
V_732 = F_302 ( V_249 ) ;
V_732 -> V_6 |= V_693 |
V_692 ;
V_732 -> V_289 = V_289 ;
F_319 ( V_249 , V_742 ) ;
V_249 -> V_743 = 7 ;
if ( V_730 )
V_728 -> V_744 = F_318 ( 7 ) ;
V_678 = F_296 ( V_10 , V_249 , V_89 , V_682 ) ;
if ( F_25 ( V_678 ) ) {
F_301 ( V_249 ) ;
V_20 = F_28 ( V_678 ) ;
goto V_650;
}
F_320 () ;
F_321 ( V_13 , V_24 , V_249 ) ;
F_322 () ;
V_20 = 0 ;
V_650:
F_50 () ;
F_18 ( & V_10 -> V_152 ) ;
return V_20 ;
}
static int F_323 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_149 * V_150 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_667 * V_670 ;
int V_20 = - V_745 ;
F_42 () ;
V_670 = F_43 ( V_13 -> V_27 . V_670 ) ;
if ( V_670 ) {
* V_150 = V_13 -> V_27 . V_216 . V_150 ;
V_20 = 0 ;
} else if ( V_10 -> V_157 > 0 &&
V_10 -> V_157 == V_10 -> V_158 &&
V_13 -> V_27 . type == V_15 ) {
if ( V_10 -> V_154 )
* V_150 = V_10 -> V_151 ;
else
* V_150 = V_10 -> V_159 ;
V_20 = 0 ;
}
F_50 () ;
return V_20 ;
}
static void F_324 ( struct V_2 * V_2 , bool V_568 )
{
F_325 ( F_2 ( V_2 ) , V_568 ) ;
}
static int F_326 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_746 * V_747 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_748 * V_749 , * V_750 ;
if ( V_747 ) {
V_749 = F_77 ( sizeof( * V_749 ) , V_168 ) ;
if ( ! V_749 )
return - V_169 ;
memcpy ( & V_749 -> V_747 , V_747 , sizeof( * V_747 ) ) ;
} else {
V_749 = NULL ;
}
V_750 = F_76 ( V_13 -> V_747 , V_13 ) ;
F_78 ( V_13 -> V_747 , V_749 ) ;
if ( V_750 )
F_79 ( V_750 , V_175 ) ;
return 0 ;
}
static int F_327 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_149 * V_150 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_181 = 0 ;
V_20 = F_328 ( V_13 , V_150 , & V_181 ) ;
if ( V_20 == 0 )
F_87 ( V_13 , V_181 ) ;
return V_20 ;
}
static int F_329 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_751 , const T_3 * V_726 , T_3 V_752 ,
T_2 V_753 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_754 * V_755 = & V_13 -> V_16 . V_26 ;
int V_501 = V_756 [ V_752 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_338 ;
if ( ! ( V_13 -> V_757 & F_111 ( V_752 ) ) )
return - V_49 ;
if ( V_755 -> V_758 [ V_501 ] . V_753 )
return - V_31 ;
if ( V_753 ) {
V_755 -> V_758 [ V_501 ] . V_753 = 32 * V_753 ;
V_755 -> V_758 [ V_501 ] . V_751 = V_751 ;
V_755 -> V_758 [ V_501 ] . V_752 = V_752 ;
}
return 0 ;
}
static int F_330 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_751 , const T_3 * V_726 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_754 * V_755 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_501 ;
for ( V_501 = 0 ; V_501 < V_295 ; V_501 ++ ) {
struct V_759 * V_758 = & V_755 -> V_758 [ V_501 ] ;
if ( ! V_758 -> V_753 )
continue;
if ( V_758 -> V_751 != V_751 )
continue;
V_758 -> V_752 = - 1 ;
F_331 () ;
F_332 ( V_10 , V_13 , false ) ;
V_758 -> V_697 = V_760 ;
V_758 -> V_761 = false ;
F_333 ( V_13 ) ;
memset ( V_758 , 0 , sizeof( * V_758 ) ) ;
return 0 ;
}
return - V_65 ;
}
