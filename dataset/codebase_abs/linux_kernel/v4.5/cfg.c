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
if ( V_8 -> V_291 & F_111 ( V_300 ) )
V_24 -> V_24 . V_323 = true ;
V_14 = F_122 ( V_10 , V_24 , V_8 ) ;
if ( V_14 ) {
F_134 ( V_10 , V_24 ) ;
return V_14 ;
}
if ( ! F_32 ( V_24 , V_292 ) &&
F_32 ( V_24 , V_64 ) )
F_113 ( V_24 ) ;
V_322 = V_13 -> V_27 . type == V_21 ||
V_13 -> V_27 . type == V_70 ;
V_14 = F_135 ( V_24 ) ;
if ( V_14 ) {
F_50 () ;
return V_14 ;
}
if ( V_322 )
F_103 ( V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_136 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_324 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
if ( V_8 -> V_141 )
return F_137 ( V_13 , V_8 -> V_141 ) ;
F_138 ( V_13 ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 ,
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
V_14 = F_140 ( V_2 , V_8 , V_327 ) ;
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
F_141 ( V_24 ) ;
if ( V_24 -> V_341 == V_266 &&
V_339 != V_340 ) {
if ( V_340 )
F_142 ( & V_24 -> V_13 -> V_342 -> V_343 ) ;
else
F_143 ( & V_24 -> V_13 -> V_342 -> V_343 ) ;
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
F_144 ( V_24 ) != 1 ) {
F_145 ( V_24 -> V_13 ,
L_1 ,
V_24 -> V_24 . V_144 ) ;
F_146 ( V_24 -> V_13 ,
V_24 -> V_13 -> V_342 -> V_345 ,
V_24 -> V_24 . V_144 ,
V_24 -> V_13 -> V_27 . V_216 . V_346 ) ;
}
if ( V_13 -> V_27 . type == V_25 &&
V_8 -> V_290 & F_111 ( V_265 ) ) {
F_147 ( V_10 ) ;
F_148 ( V_13 ) ;
}
return 0 ;
V_328:
F_18 ( & V_10 -> V_63 ) ;
return V_14 ;
}
static int F_149 ( struct V_2 * V_2 , struct V_18 * V_19 ,
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
V_350 = F_150 ( V_13 , V_347 ) ;
if ( F_25 ( V_350 ) ) {
F_50 () ;
return F_28 ( V_350 ) ;
}
F_151 ( V_350 , V_24 ) ;
F_50 () ;
return 0 ;
}
static int F_152 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_347 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( V_347 )
return F_153 ( V_13 , V_347 ) ;
F_154 ( V_13 ) ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_18 * V_19 ,
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
V_350 = F_156 ( V_13 , V_347 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
F_151 ( V_350 , V_24 ) ;
F_50 () ;
return 0 ;
}
static void F_157 ( struct V_349 * V_350 , T_3 * V_348 ,
struct V_351 * V_352 )
{
struct V_38 * V_353 = F_43 ( V_350 -> V_348 ) ;
if ( V_353 )
memcpy ( V_348 , V_353 -> V_24 . V_144 , V_145 ) ;
else
F_158 ( V_348 ) ;
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
if ( F_159 ( V_369 , V_350 -> V_370 ) )
V_352 -> V_371 = F_160 ( V_350 -> V_370 - V_369 ) ;
V_352 -> V_372 =
F_160 ( V_350 -> V_372 ) ;
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
static int F_161 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_347 , T_3 * V_348 , struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_156 ( V_13 , V_347 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_157 ( V_350 , V_348 , V_352 ) ;
F_50 () ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_347 , T_3 * V_348 ,
struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_163 ( V_13 , V_119 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_157 ( V_350 , V_348 , V_352 ) ;
F_50 () ;
return 0 ;
}
static void F_164 ( struct V_349 * V_350 , T_3 * V_384 ,
struct V_351 * V_352 )
{
memset ( V_352 , 0 , sizeof( * V_352 ) ) ;
memcpy ( V_384 , V_350 -> V_384 , V_145 ) ;
V_352 -> V_354 = V_385 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 * V_347 , T_3 * V_384 , struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_166 ( V_13 , V_347 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_164 ( V_350 , V_384 , V_352 ) ;
F_50 () ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_119 , T_3 * V_347 , T_3 * V_384 ,
struct V_351 * V_352 )
{
struct V_12 * V_13 ;
struct V_349 * V_350 ;
V_13 = F_9 ( V_19 ) ;
F_42 () ;
V_350 = F_168 ( V_13 , V_119 ) ;
if ( ! V_350 ) {
F_50 () ;
return - V_65 ;
}
memcpy ( V_347 , V_350 -> V_347 , V_145 ) ;
F_164 ( V_350 , V_384 , V_352 ) ;
F_50 () ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_386 * V_61 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_19 ) ;
memcpy ( V_61 , & ( V_13 -> V_16 . V_74 . V_274 ) , sizeof( struct V_386 ) ) ;
return 0 ;
}
static inline bool F_170 ( enum V_387 V_388 , T_1 V_28 )
{
return ( V_28 >> ( V_388 - 1 ) ) & 0x1 ;
}
static int F_171 ( struct V_389 * V_390 ,
const struct V_391 * V_392 )
{
T_3 * V_393 ;
const T_3 * V_394 ;
struct V_12 * V_13 = F_172 ( V_390 ,
struct V_12 , V_16 . V_74 ) ;
V_393 = NULL ;
V_394 = V_390 -> V_395 ;
if ( V_392 -> V_396 ) {
V_393 = F_173 ( V_392 -> V_395 , V_392 -> V_396 ,
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
static int F_174 ( struct V_2 * V_2 ,
struct V_18 * V_19 , T_1 V_28 ,
const struct V_386 * V_413 )
{
struct V_386 * V_61 ;
struct V_12 * V_13 ;
struct V_389 * V_390 ;
V_13 = F_9 ( V_19 ) ;
V_390 = & V_13 -> V_16 . V_74 ;
V_61 = & ( V_13 -> V_16 . V_74 . V_274 ) ;
if ( F_170 ( V_414 , V_28 ) )
V_61 -> V_415 = V_413 -> V_415 ;
if ( F_170 ( V_416 , V_28 ) )
V_61 -> V_417 = V_413 -> V_417 ;
if ( F_170 ( V_418 , V_28 ) )
V_61 -> V_419 = V_413 -> V_419 ;
if ( F_170 ( V_420 , V_28 ) )
V_61 -> V_421 = V_413 -> V_421 ;
if ( F_170 ( V_422 , V_28 ) )
V_61 -> V_423 = V_413 -> V_423 ;
if ( F_170 ( V_424 , V_28 ) )
V_61 -> V_425 = V_413 -> V_425 ;
if ( F_170 ( V_426 , V_28 ) )
V_61 -> V_427 = V_413 -> V_427 ;
if ( F_170 ( V_428 , V_28 ) ) {
if ( V_390 -> V_329 )
return - V_31 ;
V_61 -> V_429 = V_413 -> V_429 ;
}
if ( F_170 ( V_430 , V_28 ) )
V_61 -> V_431 =
V_413 -> V_431 ;
if ( F_170 ( V_432 , V_28 ) )
V_61 -> V_433 =
V_413 -> V_433 ;
if ( F_170 ( V_434 , V_28 ) )
V_61 -> V_435 = V_413 -> V_435 ;
if ( F_170 ( V_436 , V_28 ) )
V_61 -> V_437 = V_413 -> V_437 ;
if ( F_170 ( V_438 , V_28 ) )
V_61 -> V_439 =
V_413 -> V_439 ;
if ( F_170 ( V_440 , V_28 ) )
V_61 -> V_441 =
V_413 -> V_441 ;
if ( F_170 ( V_442 , V_28 ) )
V_61 -> V_443 =
V_413 -> V_443 ;
if ( F_170 ( V_444 ,
V_28 ) )
V_61 -> V_445 =
V_413 -> V_445 ;
if ( F_170 ( V_446 , V_28 ) ) {
V_61 -> V_447 = V_413 -> V_447 ;
F_175 ( V_390 ) ;
}
if ( F_170 ( V_448 , V_28 ) ) {
if ( V_413 -> V_449 &&
! ( V_61 -> V_447 > V_450 ) ) {
V_61 -> V_447 = V_451 ;
F_175 ( V_390 ) ;
}
V_61 -> V_449 =
V_413 -> V_449 ;
}
if ( F_170 ( V_452 , V_28 ) )
V_61 -> V_453 =
V_413 -> V_453 ;
if ( F_170 ( V_454 , V_28 ) )
V_61 -> V_455 = V_413 -> V_455 ;
if ( F_170 ( V_456 , V_28 ) ) {
if ( ! F_125 ( & V_13 -> V_10 -> V_108 , V_457 ) )
return - V_458 ;
V_61 -> V_459 = V_413 -> V_459 ;
}
if ( F_170 ( V_460 , V_28 ) ) {
V_61 -> V_461 = V_413 -> V_461 ;
V_13 -> V_27 . V_216 . V_462 = V_413 -> V_461 ;
F_87 ( V_13 , V_463 ) ;
}
if ( F_170 ( V_464 , V_28 ) )
V_61 -> V_465 =
V_413 -> V_465 ;
if ( F_170 ( V_466 , V_28 ) )
V_61 -> V_467 =
V_413 -> V_467 ;
if ( F_170 ( V_468 , V_28 ) )
V_61 -> V_469 =
V_413 -> V_469 ;
if ( F_170 ( V_470 , V_28 ) ) {
V_61 -> V_275 = V_413 -> V_275 ;
F_176 ( V_13 ) ;
}
if ( F_170 ( V_471 , V_28 ) )
V_61 -> V_472 =
V_413 -> V_472 ;
if ( F_170 ( V_473 , V_28 ) )
V_61 -> V_474 = V_413 -> V_474 ;
F_121 ( V_13 , V_182 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const struct V_386 * V_61 ,
const struct V_391 * V_392 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_389 * V_390 = & V_13 -> V_16 . V_74 ;
int V_14 ;
memcpy ( & V_390 -> V_274 , V_61 , sizeof( struct V_386 ) ) ;
V_14 = F_171 ( V_390 , V_392 ) ;
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
return F_178 ( V_13 ) ;
}
static int F_179 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
F_180 ( V_13 ) ;
F_16 ( & V_13 -> V_10 -> V_152 ) ;
F_72 ( V_13 ) ;
F_18 ( & V_13 -> V_10 -> V_152 ) ;
return 0 ;
}
static int F_181 ( struct V_2 * V_2 ,
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
static int F_182 ( struct V_2 * V_2 ,
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
if ( F_183 ( V_10 , V_13 , V_8 -> V_501 , & V_490 ) ) {
F_184 ( V_10 -> V_108 . V_2 ,
L_2 ,
V_8 -> V_501 ) ;
return - V_49 ;
}
F_87 ( V_13 , V_502 ) ;
return 0 ;
}
static int F_185 ( struct V_2 * V_2 ,
struct V_503 * V_504 )
{
return F_186 ( F_2 ( V_2 ) , V_504 ) ;
}
static int F_187 ( struct V_2 * V_2 )
{
return F_188 ( F_2 ( V_2 ) ) ;
}
static int F_189 ( struct V_2 * V_2 ,
struct V_505 * V_506 )
{
struct V_12 * V_13 ;
V_13 = F_5 ( V_506 -> V_11 ) ;
switch ( F_190 ( & V_13 -> V_27 ) ) {
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
return F_191 ( V_13 , V_506 ) ;
}
static void F_192 ( struct V_2 * V_2 , struct V_1 * V_11 )
{
F_193 ( F_2 ( V_2 ) ) ;
}
static int
F_194 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_511 * V_506 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_13 -> V_10 -> V_491 -> V_512 )
return - V_338 ;
return F_195 ( V_13 , V_506 ) ;
}
static int
F_196 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_491 -> V_513 )
return - V_338 ;
return F_197 ( V_10 ) ;
}
static int F_198 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_514 * V_506 )
{
return F_199 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_515 * V_506 )
{
return F_201 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_516 * V_506 )
{
return F_203 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_517 * V_506 )
{
return F_205 ( F_9 ( V_19 ) , V_506 ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_518 * V_8 )
{
return F_207 ( F_9 ( V_19 ) , V_8 ) ;
}
static int F_208 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_209 ( F_9 ( V_19 ) ) ;
}
static int F_210 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_519 * V_392 )
{
return F_211 ( F_9 ( V_19 ) , V_392 ) ;
}
static int F_212 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
return F_213 ( F_9 ( V_19 ) ) ;
}
static int F_214 ( struct V_2 * V_2 , struct V_18 * V_19 ,
int V_113 [ V_520 ] )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( V_13 -> V_27 . V_216 . V_411 , V_113 ,
sizeof( int ) * V_520 ) ;
return 0 ;
}
static int F_215 ( struct V_2 * V_2 , T_1 V_181 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_181 & V_521 ) {
F_216 ( V_10 ) ;
V_14 = F_217 ( V_10 , V_2 -> V_522 ) ;
if ( V_14 ) {
F_216 ( V_10 ) ;
return V_14 ;
}
}
if ( ( V_181 & V_523 ) ||
( V_181 & V_524 ) ) {
T_6 V_525 ;
V_525 = V_181 & V_523 ?
V_2 -> V_525 : - 1 ;
V_14 = F_218 ( V_10 , V_525 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_181 & V_526 ) {
V_14 = F_219 ( V_10 , V_2 -> V_527 ) ;
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
static int F_220 ( struct V_2 * V_2 ,
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
V_13 -> V_541 = F_221 ( V_537 ) ;
break;
}
if ( V_538 != V_13 -> V_27 . V_216 . V_545 ) {
V_539 = true ;
V_13 -> V_27 . V_216 . V_545 = V_538 ;
}
F_222 ( V_13 , V_539 ) ;
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
V_10 -> V_541 = F_221 ( V_537 ) ;
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
F_222 ( V_13 , V_539 ) ;
F_18 ( & V_10 -> V_153 ) ;
return 0 ;
}
static int F_223 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
int * V_546 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_10 -> V_491 -> V_547 )
return F_224 ( V_10 , V_13 , V_546 ) ;
if ( ! V_10 -> V_154 )
* V_546 = V_10 -> V_108 . V_61 . V_548 ;
else
* V_546 = V_13 -> V_27 . V_216 . V_549 ;
return 0 ;
}
static int F_225 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_144 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
memcpy ( & V_13 -> V_16 . V_550 . V_551 , V_144 , V_145 ) ;
return 0 ;
}
static void F_226 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_227 ( V_10 ) ;
}
static int F_228 ( struct V_2 * V_2 ,
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
static int F_229 ( struct V_2 * V_2 ,
struct V_248 * V_249 ,
struct V_555 * V_257 ,
void * V_171 , int V_170 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_491 -> V_556 )
return - V_338 ;
return V_10 -> V_491 -> V_556 ( & V_10 -> V_108 , V_249 , V_257 , V_171 , V_170 ) ;
}
int F_230 ( struct V_12 * V_13 ,
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
if ( ! F_231 ( & V_13 -> V_16 . V_167 . V_343 ) ) {
V_13 -> V_201 = V_201 ;
F_232 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_562 ) ;
return 0 ;
}
F_145 ( V_13 ,
L_3 ,
V_201 , F_231 ( & V_13 -> V_16 . V_167 . V_343 ) ) ;
F_16 ( & V_13 -> V_10 -> V_63 ) ;
F_84 (sta, &sdata->local->sta_list, list) {
if ( V_24 -> V_13 -> V_342 != & V_13 -> V_16 . V_167 )
continue;
if ( F_144 ( V_24 ) == 1 )
continue;
if ( F_32 ( V_24 , V_563 ) &&
! F_233 ( V_24 -> V_344 ,
V_201 ) ) {
F_145 ( V_13 , L_4 ,
V_24 -> V_24 . V_144 ) ;
continue;
}
if ( ! F_32 ( V_24 , V_267 ) )
continue;
F_145 ( V_13 , L_5 , V_24 -> V_24 . V_144 ) ;
F_146 ( V_13 , V_201 , V_24 -> V_24 . V_144 ,
V_13 -> V_27 . V_216 . V_346 ) ;
}
F_18 ( & V_13 -> V_10 -> V_63 ) ;
V_13 -> V_201 = V_201 ;
F_232 ( & V_13 -> V_10 -> V_108 , & V_13 -> V_562 ) ;
return 0 ;
}
int F_234 ( struct V_12 * V_13 ,
enum V_557 V_201 )
{
const T_3 * V_167 ;
enum V_557 V_558 ;
int V_14 ;
struct V_38 * V_24 ;
bool V_564 = false ;
F_235 ( & V_13 -> V_11 . V_152 ) ;
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
F_236 (sta, &sdata->local->sta_list, list) {
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
V_14 = F_146 ( V_13 , V_201 ,
V_167 , V_167 ) ;
if ( V_14 )
V_13 -> V_16 . V_26 . V_345 = V_558 ;
else if ( V_201 != V_203 && V_564 )
F_237 ( V_13 ) ;
return V_14 ;
}
static int F_238 ( struct V_2 * V_2 , struct V_18 * V_19 ,
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
F_239 ( V_13 ) ;
F_234 ( V_13 , V_13 -> V_16 . V_26 . V_345 ) ;
F_240 ( V_13 ) ;
if ( F_125 ( & V_10 -> V_108 , V_572 ) )
F_74 ( V_10 , V_573 ) ;
F_147 ( V_10 ) ;
F_148 ( V_13 ) ;
return 0 ;
}
static int F_241 ( struct V_2 * V_2 ,
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
static int F_242 ( struct V_2 * V_2 ,
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
V_20 = F_243 ( V_10 , V_13 , V_28 ) ;
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
static int F_244 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_149 * V_150 ,
T_1 V_597 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_152 ) ;
if ( ! F_245 ( & V_10 -> V_598 ) || V_10 -> V_599 ) {
V_14 = - V_31 ;
goto V_66;
}
V_13 -> V_201 = V_203 ;
V_13 -> V_208 = V_10 -> V_209 ;
V_14 = F_73 ( V_13 , V_150 ,
V_210 ) ;
if ( V_14 )
goto V_66;
F_246 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_241 ,
F_247 ( V_597 ) ) ;
V_66:
F_18 ( & V_10 -> V_152 ) ;
return V_14 ;
}
static struct V_176 *
F_248 ( struct V_176 * V_183 )
{
struct V_176 * V_600 ;
T_3 * V_601 ;
int V_170 ;
V_170 = V_183 -> V_185 + V_183 -> V_187 + V_183 -> V_602 +
V_183 -> V_603 + V_183 -> V_604 +
V_183 -> V_192 ;
V_600 = F_77 ( sizeof( * V_600 ) + V_170 , V_168 ) ;
if ( ! V_600 )
return NULL ;
V_601 = ( T_3 * ) ( V_600 + 1 ) ;
if ( V_183 -> V_185 ) {
V_600 -> V_185 = V_183 -> V_185 ;
V_600 -> V_184 = V_601 ;
memcpy ( V_601 , V_183 -> V_184 , V_183 -> V_185 ) ;
V_601 += V_183 -> V_185 ;
}
if ( V_183 -> V_187 ) {
V_600 -> V_187 = V_183 -> V_187 ;
V_600 -> V_186 = V_601 ;
memcpy ( V_601 , V_183 -> V_186 , V_183 -> V_187 ) ;
V_601 += V_183 -> V_187 ;
}
if ( V_183 -> V_602 ) {
V_600 -> V_602 = V_183 -> V_602 ;
V_600 -> V_605 = V_601 ;
memcpy ( V_601 , V_183 -> V_605 , V_183 -> V_602 ) ;
V_601 += V_183 -> V_602 ;
}
if ( V_183 -> V_603 ) {
V_600 -> V_603 = V_183 -> V_603 ;
V_600 -> V_606 = V_601 ;
memcpy ( V_601 , V_183 -> V_606 , V_183 -> V_603 ) ;
V_601 += V_183 -> V_603 ;
}
if ( V_183 -> V_604 ) {
V_600 -> V_604 = V_183 -> V_604 ;
V_600 -> V_607 = V_601 ;
memcpy ( V_601 , V_183 -> V_607 , V_183 -> V_604 ) ;
V_601 += V_183 -> V_604 ;
}
if ( V_183 -> V_192 ) {
V_600 -> V_192 = V_183 -> V_192 ;
V_183 -> V_164 = V_601 ;
memcpy ( V_601 , V_183 -> V_164 , V_183 -> V_192 ) ;
V_601 += V_183 -> V_192 ;
}
return V_600 ;
}
void F_249 ( struct V_552 * V_27 )
{
struct V_12 * V_13 = F_250 ( V_27 ) ;
F_232 ( & V_13 -> V_10 -> V_108 ,
& V_13 -> V_608 ) ;
}
static int F_251 ( struct V_12 * V_13 ,
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
V_14 = F_252 ( V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_181 |= V_14 ;
break;
#ifdef F_34
case V_73 :
V_14 = F_253 ( V_13 ) ;
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
static int F_254 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
T_1 V_181 = 0 ;
int V_14 ;
F_90 ( V_13 ) ;
F_235 ( & V_10 -> V_152 ) ;
F_235 ( & V_10 -> V_32 ) ;
if ( V_13 -> V_609 ) {
if ( V_13 -> V_610 )
return 0 ;
return F_255 ( V_13 ) ;
}
if ( ! F_69 ( & V_13 -> V_27 . V_216 . V_150 ,
& V_13 -> V_611 ) )
return - V_49 ;
V_13 -> V_27 . V_231 = false ;
V_14 = F_251 ( V_13 , & V_181 ) ;
if ( V_14 )
return V_14 ;
F_87 ( V_13 , V_181 ) ;
if ( V_13 -> V_234 ) {
F_92 ( V_10 , V_13 ,
V_235 ) ;
V_13 -> V_234 = false ;
}
V_14 = F_256 ( V_13 ) ;
if ( V_14 )
return V_14 ;
F_257 ( V_13 -> V_19 , & V_13 -> V_611 ) ;
return 0 ;
}
static void F_258 ( struct V_12 * V_13 )
{
if ( F_254 ( V_13 ) ) {
F_259 ( V_13 , L_6 ) ;
F_260 ( V_13 -> V_10 -> V_108 . V_2 , & V_13 -> V_11 ,
V_168 ) ;
}
}
void F_261 ( struct V_612 * V_613 )
{
struct V_12 * V_13 =
F_172 ( V_613 , struct V_12 ,
V_608 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
F_239 ( V_13 ) ;
F_16 ( & V_10 -> V_152 ) ;
F_16 ( & V_10 -> V_32 ) ;
if ( ! V_13 -> V_27 . V_231 )
goto V_614;
if ( ! F_12 ( V_13 ) )
goto V_614;
F_258 ( V_13 ) ;
V_614:
F_18 ( & V_10 -> V_32 ) ;
F_18 ( & V_10 -> V_152 ) ;
F_240 ( V_13 ) ;
}
static int F_262 ( struct V_12 * V_13 ,
struct V_615 * V_8 ,
T_1 * V_181 )
{
struct V_162 V_163 = {} ;
int V_14 ;
switch ( V_13 -> V_27 . type ) {
case V_70 :
V_13 -> V_16 . V_167 . V_236 =
F_248 ( & V_8 -> V_616 ) ;
if ( ! V_13 -> V_16 . V_167 . V_236 )
return - V_169 ;
if ( V_8 -> V_189 <= 1 )
break;
if ( ( V_8 -> V_191 >
V_617 ) ||
( V_8 -> V_174 >
V_617 ) )
return - V_49 ;
V_163 . V_190 = V_8 -> V_190 ;
V_163 . V_173 = V_8 -> V_173 ;
V_163 . V_191 = V_8 -> V_191 ;
V_163 . V_174 = V_8 -> V_174 ;
V_163 . V_189 = V_8 -> V_189 ;
V_14 = F_80 ( V_13 , & V_8 -> V_618 , & V_163 ) ;
if ( V_14 < 0 ) {
F_93 ( V_13 -> V_16 . V_167 . V_236 ) ;
return V_14 ;
}
* V_181 |= V_14 ;
break;
case V_72 :
if ( ! V_13 -> V_27 . V_216 . V_619 )
return - V_49 ;
if ( V_8 -> V_150 . V_559 != V_13 -> V_16 . V_620 . V_150 . V_559 )
return - V_49 ;
switch ( V_8 -> V_150 . V_559 ) {
case V_621 :
if ( F_263 ( & V_8 -> V_150 ) !=
F_263 ( & V_13 -> V_16 . V_620 . V_150 ) )
return - V_49 ;
case V_622 :
case V_623 :
case V_560 :
case V_624 :
break;
default:
return - V_49 ;
}
if ( V_13 -> V_16 . V_620 . V_150 . V_625 -> V_289 !=
V_8 -> V_150 . V_625 -> V_289 )
return - V_49 ;
if ( V_8 -> V_189 > 1 ) {
V_14 = F_264 ( V_13 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_181 |= V_14 ;
}
F_265 ( V_13 , V_8 ) ;
break;
#ifdef F_34
case V_73 : {
struct V_389 * V_390 = & V_13 -> V_16 . V_74 ;
if ( V_8 -> V_150 . V_559 != V_13 -> V_27 . V_216 . V_150 . V_559 )
return - V_49 ;
if ( V_13 -> V_27 . V_216 . V_150 . V_625 -> V_289 !=
V_8 -> V_150 . V_625 -> V_289 )
return - V_49 ;
if ( V_390 -> V_626 == V_627 ) {
V_390 -> V_626 = V_628 ;
if ( ! V_390 -> V_629 )
V_390 -> V_629 = 1 ;
else
V_390 -> V_629 ++ ;
}
if ( V_8 -> V_189 > 1 ) {
V_14 = F_266 ( V_13 , V_8 ) ;
if ( V_14 < 0 ) {
V_390 -> V_626 = V_627 ;
return V_14 ;
}
* V_181 |= V_14 ;
}
if ( V_390 -> V_626 == V_628 )
F_265 ( V_13 , V_8 ) ;
break;
}
#endif
default:
return - V_338 ;
}
return 0 ;
}
static int
F_267 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_615 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_630 V_631 ;
struct V_632 * V_61 ;
struct V_633 * V_634 ;
T_1 V_181 = 0 ;
int V_14 ;
F_90 ( V_13 ) ;
F_235 ( & V_10 -> V_152 ) ;
if ( ! F_245 ( & V_10 -> V_598 ) || V_10 -> V_599 )
return - V_31 ;
if ( V_13 -> V_11 . V_240 )
return - V_31 ;
if ( F_69 ( & V_8 -> V_150 ,
& V_13 -> V_27 . V_216 . V_150 ) )
return - V_49 ;
if ( V_13 -> V_27 . V_231 )
return - V_31 ;
F_16 ( & V_10 -> V_32 ) ;
V_61 = F_70 ( V_13 -> V_27 . V_635 ,
F_71 ( & V_10 -> V_32 ) ) ;
if ( ! V_61 ) {
V_14 = - V_31 ;
goto V_95;
}
V_634 = F_172 ( V_61 , struct V_633 , V_61 ) ;
if ( ! V_634 ) {
V_14 = - V_31 ;
goto V_95;
}
V_631 . V_636 = 0 ;
V_631 . V_637 = 0 ;
V_631 . V_638 = V_8 -> V_638 ;
V_631 . V_150 = V_8 -> V_150 ;
V_631 . V_189 = V_8 -> V_189 ;
V_14 = F_268 ( V_13 , & V_631 ) ;
if ( V_14 )
goto V_95;
V_14 = F_269 ( V_13 , & V_8 -> V_150 ,
V_634 -> V_639 ,
V_8 -> V_640 ) ;
if ( V_14 )
goto V_95;
V_14 = F_17 ( V_13 , NULL , V_634 -> V_639 , 0 ) ;
if ( V_14 ) {
F_270 ( V_13 ) ;
goto V_95;
}
V_14 = F_262 ( V_13 , V_8 , & V_181 ) ;
if ( V_14 ) {
F_270 ( V_13 ) ;
goto V_95;
}
V_13 -> V_611 = V_8 -> V_150 ;
V_13 -> V_234 = V_8 -> V_638 ;
V_13 -> V_27 . V_231 = true ;
if ( V_13 -> V_234 )
F_271 ( V_10 , V_13 ,
V_235 ) ;
F_272 ( V_13 -> V_19 , & V_13 -> V_611 ,
V_8 -> V_189 ) ;
if ( V_181 ) {
F_87 ( V_13 , V_181 ) ;
F_273 ( V_13 , & V_8 -> V_150 ) ;
} else {
F_258 ( V_13 ) ;
}
V_95:
F_18 ( & V_10 -> V_32 ) ;
return V_14 ;
}
int V_630 ( struct V_2 * V_2 , struct V_18 * V_19 ,
struct V_615 * V_8 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
int V_14 ;
F_16 ( & V_10 -> V_152 ) ;
V_14 = F_267 ( V_2 , V_19 , V_8 ) ;
F_18 ( & V_10 -> V_152 ) ;
return V_14 ;
}
T_4 F_274 ( struct V_9 * V_10 )
{
F_235 ( & V_10 -> V_152 ) ;
V_10 -> V_641 ++ ;
if ( F_49 ( V_10 -> V_641 == 0 ) )
V_10 -> V_641 ++ ;
return V_10 -> V_641 ;
}
int F_275 ( struct V_9 * V_10 , struct V_248 * V_249 ,
T_4 * V_89 , T_8 V_642 )
{
unsigned long V_643 ;
struct V_248 * V_644 ;
int V_645 ;
V_644 = F_276 ( V_249 , V_642 ) ;
if ( ! V_644 )
return - V_169 ;
F_277 ( & V_10 -> V_646 , V_643 ) ;
V_645 = F_278 ( & V_10 -> V_647 , V_644 ,
1 , 0x10000 , V_648 ) ;
F_279 ( & V_10 -> V_646 , V_643 ) ;
if ( V_645 < 0 ) {
F_280 ( V_644 ) ;
return - V_169 ;
}
F_281 ( V_249 ) -> V_649 = V_645 ;
* V_89 = F_274 ( V_10 ) ;
F_281 ( V_644 ) -> V_650 . V_89 = * V_89 ;
return 0 ;
}
static void F_282 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
T_2 V_651 , bool V_652 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_651 ) {
case V_653 | V_654 :
if ( V_652 ) {
V_10 -> V_655 ++ ;
V_13 -> V_27 . V_655 ++ ;
} else {
if ( V_10 -> V_655 )
V_10 -> V_655 -- ;
if ( V_13 -> V_27 . V_655 )
V_13 -> V_27 . V_655 -- ;
}
if ( ! V_10 -> V_157 )
break;
if ( V_13 -> V_27 . V_655 == 1 )
F_283 ( V_10 , V_13 , V_656 ,
V_656 ) ;
else if ( V_13 -> V_27 . V_655 == 0 )
F_283 ( V_10 , V_13 , 0 ,
V_656 ) ;
F_14 ( V_10 ) ;
break;
default:
break;
}
}
static int F_284 ( struct V_2 * V_2 , T_1 V_657 , T_1 V_658 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_10 -> V_659 )
return - V_338 ;
return F_285 ( V_10 , V_657 , V_658 ) ;
}
static int F_286 ( struct V_2 * V_2 , T_1 * V_657 , T_1 * V_658 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
return F_287 ( V_10 , V_657 , V_658 ) ;
}
static int F_288 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_660 * V_171 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_19 ) ;
if ( ! V_10 -> V_491 -> V_661 )
return - V_338 ;
F_289 ( V_10 , V_13 , V_171 ) ;
return 0 ;
}
static int F_290 ( struct V_2 * V_2 , struct V_18 * V_19 ,
const T_3 * V_662 , T_4 * V_89 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_9 * V_10 = V_13 -> V_10 ;
struct V_663 * V_664 ;
struct V_248 * V_249 ;
int V_180 = sizeof( * V_664 ) ;
T_9 V_665 ;
bool V_666 ;
struct V_667 * V_668 ;
struct V_38 * V_24 ;
struct V_632 * V_635 ;
enum V_288 V_289 ;
int V_20 ;
F_16 ( & V_10 -> V_152 ) ;
F_42 () ;
V_635 = F_43 ( V_13 -> V_27 . V_635 ) ;
if ( F_49 ( ! V_635 ) ) {
V_20 = - V_49 ;
goto V_614;
}
V_289 = V_635 -> V_669 . V_625 -> V_289 ;
V_24 = F_31 ( V_13 , V_662 ) ;
if ( V_24 ) {
V_666 = V_24 -> V_24 . V_296 ;
} else {
V_20 = - V_670 ;
goto V_614;
}
if ( V_666 ) {
V_665 = F_291 ( V_671 |
V_672 |
V_673 ) ;
} else {
V_180 -= 2 ;
V_665 = F_291 ( V_671 |
V_674 |
V_673 ) ;
}
V_249 = F_104 ( V_10 -> V_108 . V_675 + V_180 ) ;
if ( ! V_249 ) {
V_20 = - V_169 ;
goto V_614;
}
V_249 -> V_19 = V_19 ;
F_292 ( V_249 , V_10 -> V_108 . V_675 ) ;
V_664 = ( void * ) F_105 ( V_249 , V_180 ) ;
V_664 -> V_676 = V_665 ;
V_664 -> V_677 = 0 ;
memcpy ( V_664 -> V_678 , V_24 -> V_24 . V_144 , V_145 ) ;
memcpy ( V_664 -> V_679 , V_13 -> V_27 . V_144 , V_145 ) ;
memcpy ( V_664 -> V_680 , V_13 -> V_27 . V_144 , V_145 ) ;
V_664 -> V_681 = 0 ;
V_668 = F_281 ( V_249 ) ;
V_668 -> V_6 |= V_682 |
V_683 ;
V_668 -> V_289 = V_289 ;
F_293 ( V_249 , V_684 ) ;
V_249 -> V_685 = 7 ;
if ( V_666 )
V_664 -> V_686 = F_291 ( 7 ) ;
V_20 = F_275 ( V_10 , V_249 , V_89 , V_648 ) ;
if ( V_20 ) {
F_280 ( V_249 ) ;
goto V_614;
}
F_294 () ;
F_295 ( V_13 , V_24 , V_249 ) ;
F_296 () ;
V_20 = 0 ;
V_614:
F_50 () ;
F_18 ( & V_10 -> V_152 ) ;
return V_20 ;
}
static int F_297 ( struct V_2 * V_2 ,
struct V_1 * V_11 ,
struct V_149 * V_150 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_632 * V_635 ;
int V_20 = - V_687 ;
F_42 () ;
V_635 = F_43 ( V_13 -> V_27 . V_635 ) ;
if ( V_635 ) {
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
static void F_298 ( struct V_2 * V_2 , bool V_568 )
{
F_299 ( F_2 ( V_2 ) , V_568 ) ;
}
static int F_300 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_688 * V_689 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_690 * V_691 , * V_692 ;
if ( V_689 ) {
V_691 = F_77 ( sizeof( * V_691 ) , V_168 ) ;
if ( ! V_691 )
return - V_169 ;
memcpy ( & V_691 -> V_689 , V_689 , sizeof( * V_689 ) ) ;
} else {
V_691 = NULL ;
}
V_692 = F_76 ( V_13 -> V_689 , V_13 ) ;
F_78 ( V_13 -> V_689 , V_691 ) ;
if ( V_692 )
F_79 ( V_692 , V_175 ) ;
return 0 ;
}
static int F_301 ( struct V_2 * V_2 ,
struct V_18 * V_19 ,
struct V_149 * V_150 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
int V_20 ;
T_1 V_181 = 0 ;
V_20 = F_302 ( V_13 , V_150 , & V_181 ) ;
if ( V_20 == 0 )
F_87 ( V_13 , V_181 ) ;
return V_20 ;
}
static int F_303 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_693 , const T_3 * V_662 , T_3 V_694 ,
T_2 V_695 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_696 * V_697 = & V_13 -> V_16 . V_26 ;
int V_501 = V_698 [ V_694 ] ;
if ( V_13 -> V_27 . type != V_25 )
return - V_338 ;
if ( ! ( V_13 -> V_699 & F_111 ( V_694 ) ) )
return - V_49 ;
if ( V_697 -> V_700 [ V_501 ] . V_695 )
return - V_31 ;
if ( V_695 ) {
V_697 -> V_700 [ V_501 ] . V_695 = 32 * V_695 ;
V_697 -> V_700 [ V_501 ] . V_693 = V_693 ;
V_697 -> V_700 [ V_501 ] . V_694 = V_694 ;
}
return 0 ;
}
static int F_304 ( struct V_2 * V_2 , struct V_18 * V_19 ,
T_3 V_693 , const T_3 * V_662 )
{
struct V_12 * V_13 = F_9 ( V_19 ) ;
struct V_696 * V_697 = & V_13 -> V_16 . V_26 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_501 ;
for ( V_501 = 0 ; V_501 < V_295 ; V_501 ++ ) {
struct V_701 * V_700 = & V_697 -> V_700 [ V_501 ] ;
if ( ! V_700 -> V_695 )
continue;
if ( V_700 -> V_693 != V_693 )
continue;
V_700 -> V_694 = - 1 ;
F_305 () ;
F_306 ( V_10 , V_13 , false ) ;
V_700 -> V_702 = V_703 ;
V_700 -> V_704 = false ;
F_307 ( V_13 ) ;
memset ( V_700 , 0 , sizeof( * V_700 ) ) ;
return 0 ;
}
return - V_65 ;
}
