static struct V_1 * F_1 ( struct V_2 * V_2 ,
const char * V_3 ,
enum V_4 type ,
T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_3 ( V_9 , V_3 , & V_10 , type , V_7 ) ;
if ( V_13 )
return F_4 ( V_13 ) ;
if ( type == V_14 && V_5 ) {
V_12 = F_5 ( V_10 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
}
return V_10 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
F_7 ( F_5 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
enum V_4 type , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
V_19 = F_10 ( V_12 , type ) ;
if ( V_19 )
return V_19 ;
if ( type == V_20 &&
V_7 && V_7 -> V_21 == 0 )
F_11 ( V_12 -> V_15 . V_22 . V_23 , NULL ) ;
else if ( type == V_24 &&
V_7 && V_7 -> V_21 >= 0 )
V_12 -> V_15 . V_25 . V_21 = V_7 -> V_21 ;
if ( V_12 -> V_26 . type == V_14 && V_5 ) {
struct V_8 * V_9 = V_12 -> V_9 ;
if ( F_12 ( V_12 ) ) {
T_1 V_27 = V_28 |
V_29 ;
if ( ( * V_5 & V_27 ) != ( V_12 -> V_15 . V_16 & V_27 ) )
return - V_30 ;
F_13 ( V_12 , - 1 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
F_13 ( V_12 , 1 ) ;
F_14 ( V_9 ) ;
} else {
V_12 -> V_15 . V_16 = * V_5 ;
}
}
return 0 ;
}
static int F_15 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_19 ;
F_16 ( & V_12 -> V_9 -> V_31 ) ;
V_19 = F_17 ( V_12 , NULL , 0 , 0 ) ;
F_18 ( & V_12 -> V_9 -> V_31 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_19 ( V_10 , true ) ;
}
static void F_20 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
F_21 ( F_5 ( V_10 ) ) ;
}
static int F_22 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_2 V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_32 = V_32 ;
return 0 ;
}
static int F_23 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 ,
struct V_36 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 = NULL ;
const struct V_38 * V_39 = NULL ;
struct V_40 * V_41 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
switch ( V_7 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
if ( F_24 ( V_9 -> V_47 ) )
return - V_48 ;
break;
case V_49 :
case V_50 :
case V_51 :
break;
default:
V_39 = F_25 ( V_9 , V_7 -> V_43 , V_12 -> V_26 . type ) ;
break;
}
V_41 = F_26 ( V_7 -> V_43 , V_33 , V_7 -> V_52 ,
V_7 -> V_41 , V_7 -> V_53 , V_7 -> V_54 ,
V_39 ) ;
if ( F_24 ( V_41 ) )
return F_27 ( V_41 ) ;
if ( V_34 )
V_41 -> V_55 . V_5 |= V_56 ;
F_16 ( & V_9 -> V_57 ) ;
if ( V_35 ) {
if ( F_28 ( & V_12 -> V_26 ) )
V_23 = F_29 ( V_12 , V_35 ) ;
else
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 || ! F_31 ( V_23 , V_58 ) ) {
F_32 ( V_41 ) ;
V_13 = - V_59 ;
goto V_60;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_61 != V_62 )
V_41 -> V_55 . V_5 |= V_63 ;
break;
case V_64 :
case V_20 :
if ( V_41 -> V_23 && F_31 ( V_41 -> V_23 , V_65 ) )
V_41 -> V_55 . V_5 |= V_63 ;
break;
case V_66 :
break;
case V_67 :
#ifdef F_33
if ( V_12 -> V_15 . V_68 . V_69 != V_70 )
V_41 -> V_55 . V_5 |= V_63 ;
break;
#endif
case V_71 :
case V_14 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
F_34 ( 1 ) ;
break;
}
if ( V_23 )
V_23 -> V_77 = V_39 ;
V_13 = F_35 ( V_41 , V_12 , V_23 ) ;
V_60:
F_18 ( & V_9 -> V_57 ) ;
return V_13 ;
}
static int F_36 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
struct V_40 * V_41 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_57 ) ;
F_16 ( & V_9 -> V_78 ) ;
if ( V_35 ) {
V_19 = - V_59 ;
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_60;
if ( V_34 )
V_41 = F_37 ( V_9 , V_23 -> V_79 [ V_33 ] ) ;
else
V_41 = F_37 ( V_9 , V_23 -> V_80 [ V_33 ] ) ;
} else
V_41 = F_37 ( V_9 , V_12 -> V_81 [ V_33 ] ) ;
if ( ! V_41 ) {
V_19 = - V_59 ;
goto V_60;
}
F_38 ( V_41 , true ) ;
V_19 = 0 ;
V_60:
F_18 ( & V_9 -> V_78 ) ;
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_39 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 ,
void * V_82 ,
void (* F_40)( void * V_82 ,
struct V_36 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_37 * V_23 = NULL ;
T_3 V_54 [ 6 ] = { 0 } ;
struct V_36 V_7 ;
struct V_40 * V_41 = NULL ;
T_4 V_83 ;
T_1 V_84 ;
T_2 V_85 ;
int V_13 = - V_59 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
if ( V_35 ) {
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_86;
if ( V_34 && V_33 < V_87 )
V_41 = F_42 ( V_23 -> V_79 [ V_33 ] ) ;
else if ( ! V_34 &&
V_33 < V_87 + V_88 )
V_41 = F_42 ( V_23 -> V_80 [ V_33 ] ) ;
} else
V_41 = F_42 ( V_12 -> V_81 [ V_33 ] ) ;
if ( ! V_41 )
goto V_86;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_43 = V_41 -> V_55 . V_43 ;
switch ( V_41 -> V_55 . V_43 ) {
case V_45 :
V_84 = V_41 -> V_15 . V_89 . V_90 . V_84 ;
V_85 = V_41 -> V_15 . V_89 . V_90 . V_85 ;
if ( V_41 -> V_5 & V_91 )
F_43 ( V_12 -> V_9 ,
V_41 -> V_55 . V_92 ,
& V_84 , & V_85 ) ;
V_54 [ 0 ] = V_85 & 0xff ;
V_54 [ 1 ] = ( V_85 >> 8 ) & 0xff ;
V_54 [ 2 ] = V_84 & 0xff ;
V_54 [ 3 ] = ( V_84 >> 8 ) & 0xff ;
V_54 [ 4 ] = ( V_84 >> 16 ) & 0xff ;
V_54 [ 5 ] = ( V_84 >> 24 ) & 0xff ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
case V_49 :
V_83 = F_44 ( & V_41 -> V_15 . V_93 . V_94 ) ;
V_54 [ 0 ] = V_83 ;
V_54 [ 1 ] = V_83 >> 8 ;
V_54 [ 2 ] = V_83 >> 16 ;
V_54 [ 3 ] = V_83 >> 24 ;
V_54 [ 4 ] = V_83 >> 32 ;
V_54 [ 5 ] = V_83 >> 40 ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
case V_50 :
V_83 = F_44 ( & V_41 -> V_15 . V_95 . V_94 ) ;
V_54 [ 0 ] = V_83 ;
V_54 [ 1 ] = V_83 >> 8 ;
V_54 [ 2 ] = V_83 >> 16 ;
V_54 [ 3 ] = V_83 >> 24 ;
V_54 [ 4 ] = V_83 >> 32 ;
V_54 [ 5 ] = V_83 >> 40 ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
}
V_7 . V_41 = V_41 -> V_55 . V_41 ;
V_7 . V_52 = V_41 -> V_55 . V_96 ;
F_40 ( V_82 , & V_7 ) ;
V_13 = 0 ;
V_86:
F_45 () ;
return V_13 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_33 , bool V_97 ,
bool V_98 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_33 , V_97 , V_98 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_33 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_49 ( V_12 , V_33 ) ;
return 0 ;
}
void F_50 ( struct V_37 * V_23 ,
const struct V_99 * V_100 ,
struct V_101 * V_102 )
{
V_102 -> V_5 = 0 ;
if ( V_100 -> V_5 & V_103 ) {
V_102 -> V_5 |= V_104 ;
V_102 -> V_105 = V_100 -> V_106 ;
} else if ( V_100 -> V_5 & V_107 ) {
V_102 -> V_5 |= V_108 ;
V_102 -> V_105 = F_51 ( V_100 ) ;
V_102 -> V_109 = F_52 ( V_100 ) ;
} else {
struct V_110 * V_111 ;
int V_112 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_113 ;
V_111 = V_23 -> V_9 -> V_114 . V_2 -> V_115 [
F_54 ( V_23 -> V_12 ) ] ;
V_113 = V_111 -> V_116 [ V_100 -> V_106 ] . V_117 ;
V_102 -> V_118 = F_55 ( V_113 , 1 << V_112 ) ;
}
if ( V_100 -> V_5 & V_119 )
V_102 -> V_5 |= V_120 ;
if ( V_100 -> V_5 & V_121 )
V_102 -> V_5 |= V_122 ;
if ( V_100 -> V_5 & V_123 )
V_102 -> V_5 |= V_124 ;
if ( V_100 -> V_5 & V_125 )
V_102 -> V_5 |= V_126 ;
}
void F_56 ( struct V_37 * V_23 , struct V_101 * V_102 )
{
V_102 -> V_5 = 0 ;
if ( V_23 -> V_127 & V_128 ) {
V_102 -> V_5 |= V_104 ;
V_102 -> V_105 = V_23 -> V_129 ;
} else if ( V_23 -> V_127 & V_130 ) {
V_102 -> V_5 |= V_108 ;
V_102 -> V_109 = V_23 -> V_131 ;
V_102 -> V_105 = V_23 -> V_129 ;
} else {
struct V_110 * V_111 ;
int V_112 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_113 ;
V_111 = V_23 -> V_9 -> V_114 . V_2 -> V_115 [
F_54 ( V_23 -> V_12 ) ] ;
V_113 = V_111 -> V_116 [ V_23 -> V_129 ] . V_117 ;
V_102 -> V_118 = F_55 ( V_113 , 1 << V_112 ) ;
}
if ( V_23 -> V_127 & V_132 )
V_102 -> V_5 |= V_120 ;
if ( V_23 -> V_127 & V_133 )
V_102 -> V_5 |= V_126 ;
if ( V_23 -> V_134 & V_135 )
V_102 -> V_5 |= V_122 ;
if ( V_23 -> V_134 & V_136 )
V_102 -> V_5 |= V_137 ;
if ( V_23 -> V_134 & V_138 )
V_102 -> V_5 |= V_124 ;
}
static int F_57 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_106 , T_3 * V_139 , struct V_140 * V_141 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_59 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_58 ( V_12 , V_106 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_139 , V_23 -> V_23 . V_142 , V_143 ) ;
F_59 ( V_23 , V_141 ) ;
}
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_60 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_106 , struct V_144 * V_145 )
{
struct V_8 * V_9 = F_61 ( V_18 -> V_146 ) ;
return F_62 ( V_9 , V_106 , V_145 ) ;
}
static int F_63 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_139 , struct V_140 * V_141 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_59 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_30 ( V_12 , V_139 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_59 ( V_23 , V_141 ) ;
}
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_64 ( struct V_2 * V_2 ,
struct V_147 * V_148 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_65 ( & V_9 -> V_149 , V_148 ) )
return 0 ;
F_16 ( & V_9 -> V_150 ) ;
F_16 ( & V_9 -> V_151 ) ;
if ( V_9 -> V_152 ) {
V_12 = F_66 (
V_9 -> V_153 ,
F_67 ( & V_9 -> V_151 ) ) ;
if ( V_12 ) {
F_68 ( V_12 ) ;
V_19 = F_69 ( V_12 , V_148 ,
V_154 ) ;
}
} else if ( V_9 -> V_155 == V_9 -> V_156 ) {
V_9 -> V_157 = * V_148 ;
F_70 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_149 = * V_148 ;
F_18 ( & V_9 -> V_151 ) ;
F_18 ( & V_9 -> V_150 ) ;
return V_19 ;
}
static int F_71 ( struct V_11 * V_12 ,
const T_3 * V_158 , T_5 V_159 ,
const struct V_160 * V_161 )
{
struct V_162 * V_163 , * V_164 ;
if ( ! V_158 || ! V_159 )
return 1 ;
V_164 = F_72 ( V_12 -> V_15 . V_165 . V_162 , V_12 ) ;
V_163 = F_73 ( sizeof( struct V_162 ) + V_159 , V_166 ) ;
if ( ! V_163 )
return - V_167 ;
V_163 -> V_168 = V_159 ;
memcpy ( V_163 -> V_169 , V_158 , V_159 ) ;
if ( V_161 )
memcpy ( V_163 -> V_170 , V_161 -> V_171 ,
V_161 -> V_172 *
sizeof( V_163 -> V_170 [ 0 ] ) ) ;
F_74 ( V_12 -> V_15 . V_165 . V_162 , V_163 ) ;
if ( V_164 )
F_75 ( V_164 , V_173 ) ;
return 0 ;
}
static int F_76 ( struct V_11 * V_12 ,
struct V_174 * V_7 ,
const struct V_160 * V_161 )
{
struct V_175 * V_163 , * V_164 ;
int V_176 , V_177 ;
int V_178 , V_13 ;
T_1 V_179 = V_180 ;
V_164 = F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) ;
if ( ! V_7 -> V_182 && ! V_164 )
return - V_48 ;
if ( V_7 -> V_182 )
V_176 = V_7 -> V_183 ;
else
V_176 = V_164 -> V_183 ;
if ( V_7 -> V_184 || ! V_164 )
V_177 = V_7 -> V_185 ;
else
V_177 = V_164 -> V_185 ;
V_178 = sizeof( * V_163 ) + V_176 + V_177 ;
V_163 = F_73 ( V_178 , V_166 ) ;
if ( ! V_163 )
return - V_167 ;
V_163 -> V_182 = ( ( T_3 * ) V_163 ) + sizeof( * V_163 ) ;
V_163 -> V_184 = V_163 -> V_182 + V_176 ;
V_163 -> V_183 = V_176 ;
V_163 -> V_185 = V_177 ;
if ( V_161 ) {
V_163 -> V_186 = V_161 -> V_187 ;
memcpy ( V_163 -> V_170 , V_161 -> V_188 ,
V_161 -> V_189 *
sizeof( V_163 -> V_170 [ 0 ] ) ) ;
}
if ( V_7 -> V_182 )
memcpy ( V_163 -> V_182 , V_7 -> V_182 , V_176 ) ;
else
memcpy ( V_163 -> V_182 , V_164 -> V_182 , V_176 ) ;
if ( V_7 -> V_184 )
memcpy ( V_163 -> V_184 , V_7 -> V_184 , V_177 ) ;
else
if ( V_164 )
memcpy ( V_163 -> V_184 , V_164 -> V_184 , V_177 ) ;
V_13 = F_71 ( V_12 , V_7 -> V_162 ,
V_7 -> V_190 , V_161 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_179 |= V_191 ;
F_74 ( V_12 -> V_15 . V_165 . V_181 , V_163 ) ;
if ( V_164 )
F_75 ( V_164 , V_173 ) ;
return V_179 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_192 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_175 * V_164 ;
struct V_11 * V_22 ;
T_1 V_179 = V_193 |
V_194 |
V_180 |
V_195 |
V_196 ;
int V_13 ;
V_164 = F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) ;
if ( V_164 )
return - V_197 ;
V_12 -> V_198 = V_199 ;
V_12 -> V_200 = V_12 -> V_9 -> V_201 ;
F_16 ( & V_9 -> V_150 ) ;
V_13 = F_69 ( V_12 , & V_7 -> V_148 ,
V_202 ) ;
if ( ! V_13 )
F_78 ( V_12 , false ) ;
F_18 ( & V_9 -> V_150 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_203 = V_7 -> V_204 . V_205 ;
V_12 -> V_206 = V_7 -> V_204 . V_206 ;
V_12 -> V_207 = F_79 ( V_12 -> V_9 ,
& V_7 -> V_204 ,
V_12 -> V_26 . type ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_203 =
V_7 -> V_204 . V_205 ;
V_22 -> V_206 =
V_7 -> V_204 . V_206 ;
V_22 -> V_207 =
F_79 ( V_12 -> V_9 ,
& V_7 -> V_204 ,
V_22 -> V_26 . type ) ;
}
V_12 -> V_26 . V_208 . V_209 = V_7 -> V_210 ;
V_12 -> V_26 . V_208 . V_211 = V_7 -> V_211 ;
V_12 -> V_26 . V_208 . V_212 = true ;
V_12 -> V_26 . V_208 . V_213 = V_7 -> V_213 ;
if ( V_7 -> V_213 )
memcpy ( V_12 -> V_26 . V_208 . V_214 , V_7 -> V_214 ,
V_7 -> V_213 ) ;
V_12 -> V_26 . V_208 . V_215 =
( V_7 -> V_215 != V_216 ) ;
memset ( & V_12 -> V_26 . V_208 . V_217 , 0 ,
sizeof( V_12 -> V_26 . V_208 . V_217 ) ) ;
V_12 -> V_26 . V_208 . V_217 . V_218 =
V_7 -> V_219 & V_220 ;
if ( V_7 -> V_221 )
V_12 -> V_26 . V_208 . V_217 . V_218 |=
V_222 ;
V_13 = F_76 ( V_12 , & V_7 -> V_181 , NULL ) ;
if ( V_13 < 0 ) {
F_68 ( V_12 ) ;
return V_13 ;
}
V_179 |= V_13 ;
V_13 = F_81 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_164 = F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) ;
if ( V_164 )
F_75 ( V_164 , V_173 ) ;
F_11 ( V_12 -> V_15 . V_165 . V_181 , NULL ) ;
F_68 ( V_12 ) ;
return V_13 ;
}
F_82 ( V_9 , V_12 ) ;
F_83 ( V_12 , V_179 ) ;
F_84 ( V_18 ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_84 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_174 * V_7 )
{
struct V_11 * V_12 ;
struct V_175 * V_164 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_86 ( V_12 ) ;
if ( V_12 -> V_26 . V_223 )
return - V_30 ;
V_164 = F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) ;
if ( ! V_164 )
return - V_59 ;
V_13 = F_76 ( V_12 , V_7 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
F_83 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_175 * V_224 ;
struct V_162 * V_225 ;
struct V_147 V_148 ;
F_86 ( V_12 ) ;
V_224 = F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) ;
if ( ! V_224 )
return - V_59 ;
V_225 = F_72 ( V_12 -> V_15 . V_165 . V_162 , V_12 ) ;
F_16 ( & V_9 -> V_150 ) ;
V_12 -> V_26 . V_223 = false ;
if ( V_12 -> V_226 ) {
F_88 ( V_9 , V_12 ,
V_227 ) ;
V_12 -> V_226 = false ;
}
F_18 ( & V_9 -> V_150 ) ;
F_89 ( V_12 -> V_15 . V_165 . V_228 ) ;
V_12 -> V_15 . V_165 . V_228 = NULL ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_90 ( V_22 -> V_18 ) ;
F_90 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_165 . V_181 , NULL ) ;
F_11 ( V_12 -> V_15 . V_165 . V_162 , NULL ) ;
F_75 ( V_224 , V_173 ) ;
if ( V_225 )
F_75 ( V_225 , V_173 ) ;
V_12 -> V_15 . V_165 . V_229 = V_199 ;
F_91 ( V_12 , true ) ;
F_92 ( V_12 , true ) ;
V_12 -> V_26 . V_208 . V_212 = false ;
V_12 -> V_26 . V_208 . V_213 = 0 ;
F_93 ( V_230 , & V_12 -> V_231 ) ;
F_83 ( V_12 , V_194 ) ;
if ( V_12 -> V_10 . V_232 ) {
V_148 = V_12 -> V_26 . V_208 . V_148 ;
F_94 ( & V_12 -> V_233 ) ;
F_95 ( V_12 -> V_18 , & V_148 ,
V_234 ,
V_166 ) ;
}
F_96 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_235 -= F_97 ( & V_12 -> V_15 . V_165 . V_236 . V_237 ) ;
F_98 ( & V_12 -> V_15 . V_165 . V_236 . V_237 ) ;
F_16 ( & V_9 -> V_150 ) ;
F_78 ( V_12 , true ) ;
F_68 ( V_12 ) ;
F_18 ( & V_9 -> V_150 ) ;
return 0 ;
}
static void F_99 ( struct V_37 * V_23 )
{
struct V_238 * V_239 ;
struct V_240 * V_241 ;
V_241 = F_100 ( sizeof( * V_239 ) ) ;
if ( ! V_241 )
return;
V_239 = (struct V_238 * ) F_101 ( V_241 , sizeof( * V_239 ) ) ;
F_102 ( V_239 -> V_242 ) ;
memcpy ( V_239 -> V_243 , V_23 -> V_23 . V_142 , V_143 ) ;
V_239 -> V_168 = F_103 ( 6 ) ;
V_239 -> V_244 = 0 ;
V_239 -> V_245 = 0x01 ;
V_239 -> V_246 = 0xaf ;
V_239 -> V_247 [ 0 ] = 0x81 ;
V_239 -> V_247 [ 1 ] = 1 ;
V_239 -> V_247 [ 2 ] = 0 ;
V_241 -> V_18 = V_23 -> V_12 -> V_18 ;
V_241 -> V_248 = F_104 ( V_241 , V_23 -> V_12 -> V_18 ) ;
memset ( V_241 -> V_249 , 0 , sizeof( V_241 -> V_249 ) ) ;
F_105 ( V_241 ) ;
}
static int F_106 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
T_1 V_27 , T_1 V_250 )
{
int V_19 ;
if ( V_27 & F_107 ( V_251 ) &&
V_250 & F_107 ( V_251 ) &&
! F_31 ( V_23 , V_252 ) ) {
V_19 = F_108 ( V_23 , V_253 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_254 ) &&
V_250 & F_107 ( V_254 ) &&
! F_31 ( V_23 , V_58 ) ) {
V_19 = F_108 ( V_23 , V_255 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_256 ) ) {
if ( V_250 & F_107 ( V_256 ) )
V_19 = F_108 ( V_23 , V_257 ) ;
else if ( F_31 ( V_23 , V_258 ) )
V_19 = F_108 ( V_23 , V_255 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_254 ) &&
! ( V_250 & F_107 ( V_254 ) ) &&
F_31 ( V_23 , V_58 ) ) {
V_19 = F_108 ( V_23 , V_253 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_251 ) &&
! ( V_250 & F_107 ( V_251 ) ) &&
F_31 ( V_23 , V_252 ) ) {
V_19 = F_108 ( V_23 , V_259 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_109 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
struct V_260 * V_7 )
{
int V_19 = 0 ;
struct V_110 * V_111 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_261 V_262 = F_54 ( V_12 ) ;
T_1 V_27 , V_250 ;
V_111 = V_9 -> V_114 . V_2 -> V_115 [ V_262 ] ;
V_27 = V_7 -> V_263 ;
V_250 = V_7 -> V_264 ;
if ( F_28 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_107 ( V_251 ) )
V_27 |= F_107 ( V_254 ) ;
if ( V_250 & F_107 ( V_251 ) )
V_250 |= F_107 ( V_254 ) ;
} else if ( F_31 ( V_23 , V_265 ) ) {
if ( V_250 & F_107 ( V_256 ) ) {
V_250 |= F_107 ( V_251 ) |
F_107 ( V_254 ) ;
V_27 |= F_107 ( V_251 ) |
F_107 ( V_254 ) ;
}
}
if ( ! F_31 ( V_23 , V_265 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_250 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_266 ) ) {
if ( V_250 & F_107 ( V_266 ) )
F_110 ( V_23 , V_267 ) ;
else
F_111 ( V_23 , V_267 ) ;
}
if ( V_27 & F_107 ( V_268 ) ) {
if ( V_250 & F_107 ( V_268 ) ) {
F_110 ( V_23 , V_269 ) ;
V_23 -> V_23 . V_270 = true ;
} else {
F_111 ( V_23 , V_269 ) ;
V_23 -> V_23 . V_270 = false ;
}
}
if ( V_27 & F_107 ( V_271 ) ) {
if ( V_250 & F_107 ( V_271 ) )
F_110 ( V_23 , V_65 ) ;
else
F_111 ( V_23 , V_65 ) ;
}
if ( V_27 & F_107 ( V_272 ) ) {
if ( V_250 & F_107 ( V_272 ) )
F_110 ( V_23 , V_265 ) ;
else
F_111 ( V_23 , V_265 ) ;
}
if ( V_7 -> V_273 & V_274 ) {
V_23 -> V_23 . V_275 = V_7 -> V_275 ;
V_23 -> V_23 . V_276 = V_7 -> V_276 ;
}
if ( V_7 -> V_277 )
V_23 -> V_23 . V_277 = V_7 -> V_277 ;
if ( V_7 -> V_278 >= 0 )
V_23 -> V_278 = V_7 -> V_278 ;
if ( V_7 -> V_279 ) {
F_112 ( & V_12 -> V_26 . V_208 . V_148 ,
V_111 , V_7 -> V_279 ,
V_7 -> V_280 ,
& V_23 -> V_23 . V_281 [ V_262 ] ) ;
}
if ( V_7 -> V_282 )
F_113 ( V_12 , V_111 ,
V_7 -> V_282 , V_23 ) ;
if ( V_7 -> V_283 )
F_114 ( V_12 , V_111 ,
V_7 -> V_283 , V_23 ) ;
if ( V_7 -> V_284 ) {
F_115 ( V_12 , V_23 ,
V_7 -> V_285 ,
V_262 , false ) ;
}
if ( F_28 ( & V_12 -> V_26 ) ) {
#ifdef F_33
T_1 V_179 = 0 ;
if ( V_7 -> V_273 & V_286 ) {
switch ( V_7 -> V_287 ) {
case V_288 :
if ( V_23 -> V_287 != V_288 )
V_179 = F_116 (
V_12 ) ;
V_23 -> V_287 = V_7 -> V_287 ;
F_117 ( V_23 ) ;
V_179 |= F_118 ( V_23 ,
V_12 -> V_15 . V_68 . V_289 . V_290 ) ;
break;
case V_291 :
case V_292 :
case V_293 :
case V_294 :
case V_295 :
case V_296 :
if ( V_23 -> V_287 == V_288 )
V_179 = F_119 (
V_12 ) ;
V_23 -> V_287 = V_7 -> V_287 ;
F_117 ( V_23 ) ;
V_179 |= F_118 ( V_23 ,
V_297 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_298 ) {
case V_299 :
break;
case V_300 :
V_179 |= F_120 ( V_23 ) ;
break;
case V_301 :
V_179 |= F_121 ( V_23 ) ;
break;
}
if ( V_7 -> V_302 )
V_179 |=
F_118 ( V_23 ,
V_7 -> V_302 ) ;
F_122 ( V_12 , V_179 ) ;
#endif
}
if ( F_31 ( V_23 , V_265 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_250 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_123 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_139 ,
struct V_260 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_303 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_64 )
return - V_48 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_124 ( V_139 , V_12 -> V_26 . V_142 ) )
return - V_48 ;
if ( F_125 ( V_139 ) )
return - V_48 ;
V_23 = F_126 ( V_12 , V_139 , V_166 ) ;
if ( ! V_23 )
return - V_167 ;
if ( ! ( V_7 -> V_264 & F_107 ( V_272 ) ) ) {
F_127 ( V_23 , V_253 ) ;
F_127 ( V_23 , V_255 ) ;
} else {
V_23 -> V_23 . V_304 = true ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_128 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_31 ( V_23 , V_265 ) )
F_129 ( V_23 ) ;
V_303 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_64 ;
V_13 = F_130 ( V_23 ) ;
if ( V_13 ) {
F_45 () ;
return V_13 ;
}
if ( V_303 )
F_99 ( V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_139 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_139 )
return F_132 ( V_12 , V_139 ) ;
F_133 ( V_12 ) ;
return 0 ;
}
static int F_134 ( struct V_2 * V_2 ,
struct V_17 * V_18 , const T_3 * V_139 ,
struct V_260 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_305 ;
enum V_306 V_307 ;
int V_13 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_30 ( V_12 , V_139 ) ;
if ( ! V_23 ) {
V_13 = - V_59 ;
goto V_308;
}
switch ( V_12 -> V_26 . type ) {
case V_67 :
if ( V_12 -> V_15 . V_68 . V_309 )
V_307 = V_310 ;
else
V_307 = V_311 ;
break;
case V_66 :
V_307 = V_312 ;
break;
case V_24 :
if ( ! F_31 ( V_23 , V_265 ) ) {
V_307 = V_313 ;
break;
}
if ( F_31 ( V_23 , V_258 ) )
V_307 = V_314 ;
else
V_307 = V_315 ;
break;
case V_64 :
case V_20 :
V_307 = V_316 ;
break;
default:
V_13 = - V_317 ;
goto V_308;
}
V_13 = F_135 ( V_2 , V_7 , V_307 ) ;
if ( V_13 )
goto V_308;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_318 = false ;
bool V_319 = false ;
V_305 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_146 -> V_21 ) {
if ( V_305 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_308;
}
F_74 ( V_305 -> V_15 . V_22 . V_23 , V_23 ) ;
V_319 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_11 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_318 = true ;
}
V_23 -> V_12 = V_305 ;
if ( V_23 -> V_320 == V_257 &&
V_318 != V_319 ) {
if ( V_319 )
F_136 ( & V_23 -> V_12 -> V_321 -> V_322 ) ;
else
F_137 ( & V_23 -> V_12 -> V_321 -> V_322 ) ;
}
F_99 ( V_23 ) ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_308;
if ( F_31 ( V_23 , V_265 ) &&
F_31 ( V_23 , V_258 ) )
F_129 ( V_23 ) ;
F_18 ( & V_9 -> V_57 ) ;
if ( ( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_323 != V_23 -> V_12 -> V_321 -> V_324 &&
F_31 ( V_23 , V_258 ) &&
F_138 ( V_23 ) != 1 ) {
F_139 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_142 ) ;
F_140 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_321 -> V_324 ,
V_23 -> V_23 . V_142 ,
V_23 -> V_12 -> V_26 . V_208 . V_325 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_263 & F_107 ( V_256 ) ) {
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
}
return 0 ;
V_308:
F_18 ( & V_9 -> V_57 ) ;
return V_13 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_326 , const T_3 * V_327 )
{
struct V_11 * V_12 ;
struct V_328 * V_329 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_327 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_329 = F_144 ( V_12 , V_326 ) ;
if ( F_24 ( V_329 ) ) {
F_45 () ;
return F_27 ( V_329 ) ;
}
F_145 ( V_329 , V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_326 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_326 )
return F_147 ( V_12 , V_326 ) ;
F_148 ( V_12 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_326 , const T_3 * V_327 )
{
struct V_11 * V_12 ;
struct V_328 * V_329 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_327 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_329 = F_150 ( V_12 , V_326 ) ;
if ( ! V_329 ) {
F_45 () ;
return - V_59 ;
}
F_145 ( V_329 , V_23 ) ;
F_45 () ;
return 0 ;
}
static void F_151 ( struct V_328 * V_329 , T_3 * V_327 ,
struct V_330 * V_331 )
{
struct V_37 * V_332 = F_42 ( V_329 -> V_327 ) ;
if ( V_332 )
memcpy ( V_327 , V_332 -> V_23 . V_142 , V_143 ) ;
else
memset ( V_327 , 0 , V_143 ) ;
memset ( V_331 , 0 , sizeof( * V_331 ) ) ;
V_331 -> V_333 = V_334 ;
V_331 -> V_335 = V_336 |
V_337 |
V_338 |
V_339 |
V_340 |
V_341 |
V_342 ;
V_331 -> V_343 = V_329 -> V_344 . V_345 ;
V_331 -> V_346 = V_329 -> V_346 ;
V_331 -> V_347 = V_329 -> V_347 ;
if ( F_152 ( V_348 , V_329 -> V_349 ) )
V_331 -> V_350 = F_153 ( V_329 -> V_349 - V_348 ) ;
V_331 -> V_351 =
F_153 ( V_329 -> V_351 ) ;
V_331 -> V_352 = V_329 -> V_352 ;
if ( V_329 -> V_5 & V_353 )
V_331 -> V_5 |= V_354 ;
if ( V_329 -> V_5 & V_355 )
V_331 -> V_5 |= V_356 ;
if ( V_329 -> V_5 & V_357 )
V_331 -> V_5 |= V_358 ;
if ( V_329 -> V_5 & V_359 )
V_331 -> V_5 |= V_360 ;
if ( V_329 -> V_5 & V_361 )
V_331 -> V_5 |= V_362 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_326 , T_3 * V_327 , struct V_330 * V_331 )
{
struct V_11 * V_12 ;
struct V_328 * V_329 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_329 = F_150 ( V_12 , V_326 ) ;
if ( ! V_329 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_326 , V_329 -> V_326 , V_143 ) ;
F_151 ( V_329 , V_327 , V_331 ) ;
F_45 () ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_106 , T_3 * V_326 , T_3 * V_327 ,
struct V_330 * V_331 )
{
struct V_11 * V_12 ;
struct V_328 * V_329 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_329 = F_156 ( V_12 , V_106 ) ;
if ( ! V_329 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_326 , V_329 -> V_326 , V_143 ) ;
F_151 ( V_329 , V_327 , V_331 ) ;
F_45 () ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_363 * V_55 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_55 , & ( V_12 -> V_15 . V_68 . V_289 ) , sizeof( struct V_363 ) ) ;
return 0 ;
}
static inline bool F_158 ( enum V_364 V_365 , T_1 V_27 )
{
return ( V_27 >> ( V_365 - 1 ) ) & 0x1 ;
}
static int F_159 ( struct V_366 * V_367 ,
const struct V_368 * V_369 )
{
T_3 * V_370 ;
const T_3 * V_371 ;
struct V_11 * V_12 = F_160 ( V_367 ,
struct V_11 , V_15 . V_68 ) ;
V_370 = NULL ;
V_371 = V_367 -> V_372 ;
if ( V_369 -> V_373 ) {
V_370 = F_161 ( V_369 -> V_372 , V_369 -> V_373 ,
V_166 ) ;
if ( ! V_370 )
return - V_167 ;
}
V_367 -> V_373 = V_369 -> V_373 ;
V_367 -> V_372 = V_370 ;
F_89 ( V_371 ) ;
V_367 -> V_374 = V_369 -> V_374 ;
memcpy ( V_367 -> V_375 , V_369 -> V_375 , V_367 -> V_374 ) ;
V_367 -> V_376 = V_369 -> V_377 ;
V_367 -> V_378 = V_369 -> V_379 ;
V_367 -> V_380 = V_369 -> V_381 ;
V_367 -> V_309 = V_369 -> V_309 ;
V_367 -> V_382 = V_369 -> V_383 ;
V_367 -> V_69 = V_70 ;
if ( V_369 -> V_384 )
V_367 -> V_69 |= V_385 ;
if ( V_369 -> V_386 )
V_367 -> V_69 |= V_387 ;
memcpy ( V_12 -> V_26 . V_208 . V_388 , V_369 -> V_388 ,
sizeof( V_369 -> V_388 ) ) ;
V_12 -> V_26 . V_208 . V_389 = V_369 -> V_389 ;
V_12 -> V_26 . V_208 . V_209 = V_369 -> V_210 ;
V_12 -> V_26 . V_208 . V_211 = V_369 -> V_211 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_363 * V_390 )
{
struct V_363 * V_55 ;
struct V_11 * V_12 ;
struct V_366 * V_367 ;
V_12 = F_9 ( V_18 ) ;
V_367 = & V_12 -> V_15 . V_68 ;
V_55 = & ( V_12 -> V_15 . V_68 . V_289 ) ;
if ( F_158 ( V_391 , V_27 ) )
V_55 -> V_392 = V_390 -> V_392 ;
if ( F_158 ( V_393 , V_27 ) )
V_55 -> V_394 = V_390 -> V_394 ;
if ( F_158 ( V_395 , V_27 ) )
V_55 -> V_396 = V_390 -> V_396 ;
if ( F_158 ( V_397 , V_27 ) )
V_55 -> V_398 = V_390 -> V_398 ;
if ( F_158 ( V_399 , V_27 ) )
V_55 -> V_400 = V_390 -> V_400 ;
if ( F_158 ( V_401 , V_27 ) )
V_55 -> V_402 = V_390 -> V_402 ;
if ( F_158 ( V_403 , V_27 ) )
V_55 -> V_404 = V_390 -> V_404 ;
if ( F_158 ( V_405 , V_27 ) ) {
if ( V_367 -> V_309 )
return - V_30 ;
V_55 -> V_406 = V_390 -> V_406 ;
}
if ( F_158 ( V_407 , V_27 ) )
V_55 -> V_408 =
V_390 -> V_408 ;
if ( F_158 ( V_409 , V_27 ) )
V_55 -> V_410 =
V_390 -> V_410 ;
if ( F_158 ( V_411 , V_27 ) )
V_55 -> V_412 = V_390 -> V_412 ;
if ( F_158 ( V_413 , V_27 ) )
V_55 -> V_414 = V_390 -> V_414 ;
if ( F_158 ( V_415 , V_27 ) )
V_55 -> V_416 =
V_390 -> V_416 ;
if ( F_158 ( V_417 , V_27 ) )
V_55 -> V_418 =
V_390 -> V_418 ;
if ( F_158 ( V_419 , V_27 ) )
V_55 -> V_420 =
V_390 -> V_420 ;
if ( F_158 ( V_421 ,
V_27 ) )
V_55 -> V_422 =
V_390 -> V_422 ;
if ( F_158 ( V_423 , V_27 ) ) {
V_55 -> V_424 = V_390 -> V_424 ;
F_163 ( V_367 ) ;
}
if ( F_158 ( V_425 , V_27 ) ) {
if ( V_390 -> V_426 &&
! ( V_55 -> V_424 > V_427 ) ) {
V_55 -> V_424 = V_428 ;
F_163 ( V_367 ) ;
}
V_55 -> V_426 =
V_390 -> V_426 ;
}
if ( F_158 ( V_429 , V_27 ) )
V_55 -> V_430 =
V_390 -> V_430 ;
if ( F_158 ( V_431 , V_27 ) )
V_55 -> V_432 = V_390 -> V_432 ;
if ( F_158 ( V_433 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_114 . V_5 & V_434 ) )
return - V_435 ;
V_55 -> V_436 = V_390 -> V_436 ;
}
if ( F_158 ( V_437 , V_27 ) ) {
V_55 -> V_438 = V_390 -> V_438 ;
V_12 -> V_26 . V_208 . V_439 = V_390 -> V_438 ;
F_83 ( V_12 , V_440 ) ;
}
if ( F_158 ( V_441 , V_27 ) )
V_55 -> V_442 =
V_390 -> V_442 ;
if ( F_158 ( V_443 , V_27 ) )
V_55 -> V_444 =
V_390 -> V_444 ;
if ( F_158 ( V_445 , V_27 ) )
V_55 -> V_446 =
V_390 -> V_446 ;
if ( F_158 ( V_447 , V_27 ) ) {
V_55 -> V_290 = V_390 -> V_290 ;
F_164 ( V_12 ) ;
}
if ( F_158 ( V_448 , V_27 ) )
V_55 -> V_449 =
V_390 -> V_449 ;
if ( F_158 ( V_450 , V_27 ) )
V_55 -> V_451 = V_390 -> V_451 ;
F_122 ( V_12 , V_180 ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_363 * V_55 ,
const struct V_368 * V_369 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_366 * V_367 = & V_12 -> V_15 . V_68 ;
int V_13 ;
memcpy ( & V_367 -> V_289 , V_55 , sizeof( struct V_363 ) ) ;
V_13 = F_159 ( V_367 , V_369 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_198 = V_199 ;
V_12 -> V_200 = V_12 -> V_9 -> V_201 ;
F_16 ( & V_12 -> V_9 -> V_150 ) ;
V_13 = F_69 ( V_12 , & V_369 -> V_148 ,
V_202 ) ;
F_18 ( & V_12 -> V_9 -> V_150 ) ;
if ( V_13 )
return V_13 ;
return F_166 ( V_12 ) ;
}
static int F_167 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_168 ( V_12 ) ;
F_16 ( & V_12 -> V_9 -> V_150 ) ;
F_68 ( V_12 ) ;
F_18 ( & V_12 -> V_9 -> V_150 ) ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_452 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_261 V_262 ;
T_1 V_179 = 0 ;
if ( ! F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) )
return - V_59 ;
V_262 = F_54 ( V_12 ) ;
if ( V_7 -> V_453 >= 0 ) {
V_12 -> V_26 . V_208 . V_453 = V_7 -> V_453 ;
V_179 |= V_454 ;
}
if ( V_7 -> V_455 >= 0 ) {
V_12 -> V_26 . V_208 . V_455 =
V_7 -> V_455 ;
V_179 |= V_456 ;
}
if ( ! V_12 -> V_26 . V_208 . V_457 &&
V_262 == V_458 ) {
V_12 -> V_26 . V_208 . V_457 = true ;
V_179 |= V_459 ;
}
if ( V_7 -> V_460 >= 0 ) {
V_12 -> V_26 . V_208 . V_457 =
V_7 -> V_460 ;
V_179 |= V_459 ;
}
if ( V_7 -> V_389 ) {
F_112 ( & V_12 -> V_26 . V_208 . V_148 ,
V_2 -> V_115 [ V_262 ] ,
V_7 -> V_389 ,
V_7 -> V_461 ,
& V_12 -> V_26 . V_208 . V_389 ) ;
V_179 |= V_462 ;
}
if ( V_7 -> V_463 >= 0 ) {
if ( V_7 -> V_463 )
V_12 -> V_5 |= V_464 ;
else
V_12 -> V_5 &= ~ V_464 ;
}
if ( V_7 -> V_438 >= 0 ) {
V_12 -> V_26 . V_208 . V_439 =
( T_2 ) V_7 -> V_438 ;
V_179 |= V_440 ;
}
if ( V_7 -> V_219 >= 0 ) {
V_12 -> V_26 . V_208 . V_217 . V_218 &=
~ V_220 ;
V_12 -> V_26 . V_208 . V_217 . V_218 |=
V_7 -> V_219 & V_220 ;
V_179 |= V_196 ;
}
if ( V_7 -> V_221 > 0 ) {
V_12 -> V_26 . V_208 . V_217 . V_218 |=
V_222 ;
V_179 |= V_196 ;
} else if ( V_7 -> V_221 == 0 ) {
V_12 -> V_26 . V_208 . V_217 . V_218 &=
~ V_222 ;
V_179 |= V_196 ;
}
F_83 ( V_12 , V_179 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_465 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_466 V_467 ;
if ( ! V_9 -> V_468 -> V_469 )
return - V_317 ;
if ( V_9 -> V_114 . V_470 < V_471 )
return - V_317 ;
memset ( & V_467 , 0 , sizeof( V_467 ) ) ;
V_467 . V_472 = V_7 -> V_472 ;
V_467 . V_473 = V_7 -> V_474 ;
V_467 . V_475 = V_7 -> V_476 ;
V_467 . V_477 = V_7 -> V_477 ;
V_467 . V_478 = false ;
V_12 -> V_479 [ V_7 -> V_480 ] = V_467 ;
if ( F_171 ( V_9 , V_12 , V_7 -> V_480 , & V_467 ) ) {
F_172 ( V_9 -> V_114 . V_2 ,
L_2 ,
V_7 -> V_480 ) ;
return - V_48 ;
}
F_83 ( V_12 , V_481 ) ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 ,
struct V_482 * V_483 )
{
return F_174 ( F_2 ( V_2 ) , V_483 ) ;
}
static int F_175 ( struct V_2 * V_2 )
{
return F_176 ( F_2 ( V_2 ) ) ;
}
static int F_177 ( struct V_2 * V_2 ,
struct V_484 * V_485 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_485 -> V_10 ) ;
switch ( F_178 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_66 :
case V_67 :
case V_75 :
case V_72 :
break;
case V_76 :
if ( V_12 -> V_9 -> V_468 -> V_486 )
break;
case V_64 :
if ( V_12 -> V_15 . V_165 . V_181 &&
( ! ( V_2 -> V_487 & V_488 ) ||
! ( V_485 -> V_5 & V_489 ) ) )
return - V_317 ;
break;
default:
return - V_317 ;
}
return F_179 ( V_12 , V_485 ) ;
}
static int
F_180 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_490 * V_485 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_468 -> V_491 )
return - V_317 ;
return F_181 ( V_12 , V_485 ) ;
}
static int
F_182 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_468 -> V_492 )
return - V_317 ;
return F_183 ( V_12 ) ;
}
static int F_184 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_493 * V_485 )
{
return F_185 ( F_9 ( V_18 ) , V_485 ) ;
}
static int F_186 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_494 * V_485 )
{
return F_187 ( F_9 ( V_18 ) , V_485 ) ;
}
static int F_188 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_495 * V_485 )
{
return F_189 ( F_9 ( V_18 ) , V_485 ) ;
}
static int F_190 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_496 * V_485 )
{
return F_191 ( F_9 ( V_18 ) , V_485 ) ;
}
static int F_192 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_497 * V_7 )
{
return F_193 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_195 ( F_9 ( V_18 ) ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 [ V_498 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_208 . V_388 , V_100 ,
sizeof( int ) * V_498 ) ;
return 0 ;
}
static int F_197 ( struct V_2 * V_2 , T_1 V_179 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_179 & V_499 ) {
V_13 = F_198 ( V_9 , V_2 -> V_500 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_179 & V_501 ) {
V_13 = F_199 ( V_9 , V_2 -> V_502 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_179 & V_503 ) {
V_13 = F_200 ( V_9 , V_2 -> V_504 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_179 & V_505 ) {
if ( V_2 -> V_506 > V_507 )
return - V_48 ;
V_9 -> V_114 . V_55 . V_508 = V_2 -> V_506 ;
}
if ( V_179 & V_509 ) {
if ( V_2 -> V_510 > V_507 )
return - V_48 ;
V_9 -> V_114 . V_55 . V_511 = V_2 -> V_510 ;
}
if ( V_179 &
( V_505 | V_509 ) )
F_70 ( V_9 , V_512 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_513 type , int V_514 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_515 :
V_12 -> V_516 = V_517 ;
break;
case V_518 :
case V_519 :
if ( V_514 < 0 || ( V_514 % 100 ) )
return - V_317 ;
V_12 -> V_516 = F_202 ( V_514 ) ;
break;
}
F_203 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_515 :
V_9 -> V_516 = V_517 ;
break;
case V_518 :
case V_519 :
if ( V_514 < 0 || ( V_514 % 100 ) )
return - V_317 ;
V_9 -> V_516 = F_202 ( V_514 ) ;
break;
}
F_16 ( & V_9 -> V_151 ) ;
F_80 (sdata, &local->interfaces, list)
V_12 -> V_516 = V_9 -> V_516 ;
F_80 (sdata, &local->interfaces, list)
F_203 ( V_12 ) ;
F_18 ( & V_9 -> V_151 ) ;
return 0 ;
}
static int F_204 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_520 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_152 )
* V_520 = V_9 -> V_114 . V_55 . V_521 ;
else
* V_520 = V_12 -> V_26 . V_208 . V_522 ;
return 0 ;
}
static int F_205 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_142 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_523 . V_524 , V_142 , V_143 ) ;
return 0 ;
}
static void F_206 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_207 ( V_9 ) ;
}
static int F_208 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_169 , int V_168 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_525 * V_26 = NULL ;
if ( ! V_9 -> V_468 -> V_526 )
return - V_317 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_527 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_468 -> V_526 ( & V_9 -> V_114 , V_26 , V_169 , V_168 ) ;
}
static int F_209 ( struct V_2 * V_2 ,
struct V_240 * V_241 ,
struct V_528 * V_249 ,
void * V_169 , int V_168 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_468 -> V_529 )
return - V_317 ;
return V_9 -> V_468 -> V_529 ( & V_9 -> V_114 , V_241 , V_249 , V_169 , V_168 ) ;
}
int F_210 ( struct V_11 * V_12 ,
enum V_530 V_198 )
{
struct V_37 * V_23 ;
enum V_530 V_531 ;
int V_532 ;
if ( F_34 ( V_12 -> V_26 . type != V_64 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_208 . V_148 . V_533 == V_534 )
return 0 ;
V_531 = V_12 -> V_15 . V_165 . V_324 ;
V_12 -> V_15 . V_165 . V_324 = V_198 ;
if ( V_531 == V_198 ||
V_198 == V_535 )
return 0 ;
if ( ! F_211 ( & V_12 -> V_15 . V_165 . V_322 ) ) {
V_12 -> V_198 = V_198 ;
F_212 ( & V_12 -> V_9 -> V_114 , & V_12 -> V_536 ) ;
return 0 ;
}
F_139 ( V_12 ,
L_3 ,
V_198 , F_211 ( & V_12 -> V_15 . V_165 . V_322 ) ) ;
F_16 ( & V_12 -> V_9 -> V_57 ) ;
for ( V_532 = 0 ; V_532 < V_537 ; V_532 ++ ) {
for ( V_23 = F_66 ( V_12 -> V_9 -> V_538 [ V_532 ] ,
F_67 ( & V_12 -> V_9 -> V_57 ) ) ;
V_23 ;
V_23 = F_66 ( V_23 -> V_539 ,
F_67 ( & V_12 -> V_9 -> V_57 ) ) ) {
if ( V_23 -> V_12 -> V_321 != & V_12 -> V_15 . V_165 )
continue;
if ( F_138 ( V_23 ) == 1 )
continue;
if ( F_31 ( V_23 , V_540 ) &&
! F_213 ( V_23 -> V_323 ,
V_198 ) ) {
F_139 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_142 ) ;
continue;
}
if ( ! F_31 ( V_23 , V_258 ) )
continue;
F_139 ( V_12 , L_5 , V_23 -> V_23 . V_142 ) ;
F_140 ( V_12 , V_198 ,
V_23 -> V_23 . V_142 ,
V_12 -> V_26 . V_208 . V_325 ) ;
}
}
F_18 ( & V_12 -> V_9 -> V_57 ) ;
V_12 -> V_198 = V_198 ;
F_212 ( & V_12 -> V_9 -> V_114 , & V_12 -> V_536 ) ;
return 0 ;
}
int F_214 ( struct V_11 * V_12 ,
enum V_530 V_198 )
{
const T_3 * V_165 ;
enum V_530 V_531 ;
int V_13 ;
F_215 ( & V_12 -> V_10 . V_150 ) ;
if ( F_34 ( V_12 -> V_26 . type != V_24 ) )
return - V_48 ;
V_531 = V_12 -> V_15 . V_25 . V_324 ;
V_12 -> V_15 . V_25 . V_324 = V_198 ;
if ( V_531 == V_198 &&
V_198 != V_535 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_541 ||
V_12 -> V_26 . V_208 . V_148 . V_533 == V_534 )
return 0 ;
V_165 = V_12 -> V_15 . V_25 . V_541 -> V_325 ;
if ( V_198 == V_535 ) {
if ( V_12 -> V_15 . V_25 . V_542 )
V_198 = V_543 ;
else
V_198 = V_199 ;
}
V_13 = F_140 ( V_12 , V_198 ,
V_165 , V_165 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_324 = V_531 ;
return V_13 ;
}
static int F_216 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_544 , int V_545 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_146 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_317 ;
if ( ! ( V_9 -> V_114 . V_5 & V_546 ) )
return - V_317 ;
if ( V_544 == V_12 -> V_15 . V_25 . V_542 &&
V_545 == V_9 -> V_547 )
return 0 ;
V_12 -> V_15 . V_25 . V_542 = V_544 ;
V_9 -> V_547 = V_545 ;
F_217 ( V_12 ) ;
F_214 ( V_12 , V_12 -> V_15 . V_25 . V_324 ) ;
F_218 ( V_12 ) ;
if ( V_9 -> V_114 . V_5 & V_548 )
F_70 ( V_9 , V_549 ) ;
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_550 , T_1 V_551 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_525 * V_26 = & V_12 -> V_26 ;
struct V_552 * V_208 = & V_26 -> V_208 ;
if ( V_550 == V_208 -> V_553 &&
V_551 == V_208 -> V_554 )
return 0 ;
V_208 -> V_553 = V_550 ;
V_208 -> V_554 = V_551 ;
if ( V_12 -> V_15 . V_25 . V_541 &&
V_12 -> V_26 . V_555 & V_556 )
F_83 ( V_12 , V_557 ) ;
return 0 ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_142 ,
const struct V_558 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_146 ) ;
int V_532 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
if ( V_9 -> V_114 . V_5 & V_559 ) {
V_19 = F_221 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_532 = 0 ; V_532 < V_498 ; V_532 ++ ) {
struct V_110 * V_111 = V_2 -> V_115 [ V_532 ] ;
int V_560 ;
V_12 -> V_561 [ V_532 ] = V_27 -> V_246 [ V_532 ] . V_118 ;
memcpy ( V_12 -> V_562 [ V_532 ] , V_27 -> V_246 [ V_532 ] . V_563 ,
sizeof( V_27 -> V_246 [ V_532 ] . V_563 ) ) ;
V_12 -> V_564 [ V_532 ] = false ;
if ( ! V_111 )
continue;
for ( V_560 = 0 ; V_560 < V_565 ; V_560 ++ )
if ( ~ V_12 -> V_562 [ V_532 ] [ V_560 ] ) {
V_12 -> V_564 [ V_532 ] = true ;
break;
}
}
return 0 ;
}
static int F_222 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_566 * V_567 ,
unsigned int V_568 , T_4 * V_82 ,
struct V_240 * V_569 ,
enum V_570 type )
{
struct V_571 * V_572 , * V_573 ;
bool V_574 = false ;
int V_19 ;
F_215 ( & V_9 -> V_150 ) ;
if ( V_9 -> V_152 && ! V_9 -> V_468 -> V_575 )
return - V_317 ;
V_572 = F_73 ( sizeof( * V_572 ) , V_166 ) ;
if ( ! V_572 )
return - V_167 ;
if ( ! V_568 )
V_568 = 10 ;
V_572 -> V_576 = V_567 ;
V_572 -> V_568 = V_568 ;
V_572 -> V_577 = V_568 ;
V_572 -> V_578 = V_569 ;
V_572 -> type = type ;
V_572 -> V_579 = ( unsigned long ) V_569 ;
V_572 -> V_12 = V_12 ;
F_223 ( & V_572 -> V_580 , V_581 ) ;
F_224 ( & V_572 -> V_582 ) ;
if ( ! V_569 ) {
V_9 -> V_583 ++ ;
V_572 -> V_82 = V_9 -> V_583 ;
if ( F_225 ( V_572 -> V_82 == 0 ) ) {
V_572 -> V_82 = 1 ;
V_9 -> V_583 ++ ;
}
* V_82 = V_572 -> V_82 ;
} else {
* V_82 = ( unsigned long ) V_569 ;
}
if ( ! F_226 ( & V_9 -> V_584 ) ||
V_9 -> V_585 || V_9 -> V_586 )
goto V_587;
if ( ! V_9 -> V_468 -> V_575 ) {
F_227 ( & V_9 -> V_114 , & V_572 -> V_580 , 0 ) ;
goto V_588;
}
V_19 = F_228 ( V_9 , V_12 , V_567 , V_568 , type ) ;
if ( V_19 ) {
F_89 ( V_572 ) ;
return V_19 ;
}
V_572 -> V_589 = true ;
goto V_588;
V_587:
F_80 (tmp, &local->roc_list, list) {
if ( V_573 -> V_576 != V_567 || V_573 -> V_12 != V_12 )
continue;
if ( ! V_573 -> V_589 ) {
F_229 ( & V_572 -> V_590 , & V_573 -> V_582 ) ;
V_573 -> V_568 = F_230 ( V_573 -> V_568 , V_572 -> V_568 ) ;
V_573 -> type = F_230 ( V_573 -> type , V_572 -> type ) ;
V_574 = true ;
break;
}
if ( V_9 -> V_468 -> V_575 ) {
unsigned long V_560 = V_348 ;
if ( ! V_573 -> V_591 ) {
F_229 ( & V_572 -> V_590 , & V_573 -> V_582 ) ;
V_574 = true ;
break;
}
if ( F_152 ( V_560 + V_592 ,
V_573 -> V_593 +
F_231 ( V_573 -> V_568 ) ) ) {
int V_594 ;
F_232 ( V_572 ) ;
V_594 = V_572 -> V_568 -
F_153 ( V_573 -> V_593 +
F_231 (
V_573 -> V_568 ) -
V_560 ) ;
if ( V_594 > 0 ) {
F_233 ( & V_572 -> V_590 , & V_573 -> V_590 ) ;
} else {
F_229 ( & V_572 -> V_590 ,
& V_573 -> V_582 ) ;
}
V_574 = true ;
}
} else if ( F_234 ( & V_573 -> V_580 . V_595 ) ) {
unsigned long V_596 ;
F_229 ( & V_572 -> V_590 , & V_573 -> V_582 ) ;
V_574 = true ;
V_596 = V_348 + F_231 ( V_572 -> V_568 ) ;
if ( F_235 ( V_596 , V_573 -> V_580 . V_595 . V_597 ) )
F_236 ( & V_573 -> V_580 . V_595 , V_596 ) ;
else
F_237 ( & V_573 -> V_580 . V_595 ) ;
F_232 ( V_572 ) ;
}
break;
}
V_588:
if ( ! V_574 )
F_229 ( & V_572 -> V_590 , & V_9 -> V_584 ) ;
return 0 ;
}
static int F_238 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_566 * V_576 ,
unsigned int V_568 ,
T_4 * V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_150 ) ;
V_19 = F_222 ( V_9 , V_12 , V_576 ,
V_568 , V_82 , NULL ,
V_598 ) ;
F_18 ( & V_9 -> V_150 ) ;
return V_19 ;
}
static int F_239 ( struct V_8 * V_9 ,
T_4 V_82 , bool V_599 )
{
struct V_571 * V_572 , * V_573 , * V_600 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_150 ) ;
F_240 (roc, tmp, &local->roc_list, list) {
struct V_571 * V_601 , * V_602 ;
F_240 (dep, tmp2, &roc->dependents, list) {
if ( ! V_599 && V_601 -> V_82 != V_82 )
continue;
else if ( V_599 && V_601 -> V_579 != V_82 )
continue;
F_241 ( & V_601 -> V_590 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_242 ( V_601 , true ) ;
return 0 ;
}
if ( ! V_599 && V_572 -> V_82 != V_82 )
continue;
else if ( V_599 && V_572 -> V_579 != V_82 )
continue;
V_600 = V_572 ;
break;
}
if ( ! V_600 ) {
F_18 ( & V_9 -> V_150 ) ;
return - V_59 ;
}
if ( V_9 -> V_468 -> V_575 ) {
if ( V_600 -> V_589 ) {
V_19 = F_243 ( V_9 ) ;
if ( F_34 ( V_19 ) ) {
F_18 ( & V_9 -> V_150 ) ;
return V_19 ;
}
}
F_241 ( & V_600 -> V_590 ) ;
if ( V_600 -> V_589 )
F_244 ( V_9 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_242 ( V_600 , true ) ;
} else {
V_600 -> abort = true ;
F_227 ( & V_9 -> V_114 , & V_600 -> V_580 , 0 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_245 ( & V_600 -> V_580 ) ;
F_225 ( ! V_600 -> V_603 ) ;
F_89 ( V_600 ) ;
}
return 0 ;
}
static int F_246 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_239 ( V_9 , V_82 , false ) ;
}
static int F_247 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_147 * V_148 ,
T_1 V_604 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_150 ) ;
if ( ! F_226 ( & V_9 -> V_584 ) || V_9 -> V_585 ) {
V_13 = - V_30 ;
goto V_60;
}
V_12 -> V_198 = V_199 ;
V_12 -> V_200 = V_9 -> V_201 ;
V_13 = F_69 ( V_12 , V_148 ,
V_202 ) ;
if ( V_13 )
goto V_60;
F_227 ( & V_12 -> V_9 -> V_114 ,
& V_12 -> V_233 ,
F_231 ( V_604 ) ) ;
V_60:
F_18 ( & V_9 -> V_150 ) ;
return V_13 ;
}
static struct V_174 *
F_248 ( struct V_174 * V_181 )
{
struct V_174 * V_605 ;
T_3 * V_606 ;
int V_168 ;
V_168 = V_181 -> V_183 + V_181 -> V_185 + V_181 -> V_607 +
V_181 -> V_608 + V_181 -> V_609 +
V_181 -> V_190 ;
V_605 = F_73 ( sizeof( * V_605 ) + V_168 , V_166 ) ;
if ( ! V_605 )
return NULL ;
V_606 = ( T_3 * ) ( V_605 + 1 ) ;
if ( V_181 -> V_183 ) {
V_605 -> V_183 = V_181 -> V_183 ;
V_605 -> V_182 = V_606 ;
memcpy ( V_606 , V_181 -> V_182 , V_181 -> V_183 ) ;
V_606 += V_181 -> V_183 ;
}
if ( V_181 -> V_185 ) {
V_605 -> V_185 = V_181 -> V_185 ;
V_605 -> V_184 = V_606 ;
memcpy ( V_606 , V_181 -> V_184 , V_181 -> V_185 ) ;
V_606 += V_181 -> V_185 ;
}
if ( V_181 -> V_607 ) {
V_605 -> V_607 = V_181 -> V_607 ;
V_605 -> V_610 = V_606 ;
memcpy ( V_606 , V_181 -> V_610 , V_181 -> V_607 ) ;
V_606 += V_181 -> V_607 ;
}
if ( V_181 -> V_608 ) {
V_605 -> V_608 = V_181 -> V_608 ;
V_605 -> V_611 = V_606 ;
memcpy ( V_606 , V_181 -> V_611 , V_181 -> V_608 ) ;
V_606 += V_181 -> V_608 ;
}
if ( V_181 -> V_609 ) {
V_605 -> V_609 = V_181 -> V_609 ;
V_605 -> V_612 = V_606 ;
memcpy ( V_606 , V_181 -> V_612 , V_181 -> V_609 ) ;
V_606 += V_181 -> V_609 ;
}
if ( V_181 -> V_190 ) {
V_605 -> V_190 = V_181 -> V_190 ;
V_181 -> V_162 = V_606 ;
memcpy ( V_606 , V_181 -> V_162 , V_181 -> V_190 ) ;
V_606 += V_181 -> V_190 ;
}
return V_605 ;
}
void F_249 ( struct V_525 * V_26 )
{
struct V_11 * V_12 = F_250 ( V_26 ) ;
F_212 ( & V_12 -> V_9 -> V_114 ,
& V_12 -> V_613 ) ;
}
static int F_251 ( struct V_11 * V_12 ,
T_1 * V_179 )
{
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_13 = F_76 ( V_12 , V_12 -> V_15 . V_165 . V_228 ,
NULL ) ;
F_89 ( V_12 -> V_15 . V_165 . V_228 ) ;
V_12 -> V_15 . V_165 . V_228 = NULL ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
break;
case V_66 :
V_13 = F_252 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
break;
#ifdef F_33
case V_67 :
V_13 = F_253 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
break;
#endif
default:
F_225 ( 1 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_254 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_1 V_179 = 0 ;
int V_13 ;
F_86 ( V_12 ) ;
F_215 ( & V_9 -> V_150 ) ;
F_215 ( & V_9 -> V_31 ) ;
if ( V_12 -> V_614 ) {
if ( V_12 -> V_615 )
return 0 ;
V_13 = F_255 ( V_12 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
if ( ! F_65 ( & V_12 -> V_26 . V_208 . V_148 ,
& V_12 -> V_616 ) )
return - V_48 ;
V_12 -> V_26 . V_223 = false ;
V_13 = F_251 ( V_12 , & V_179 ) ;
if ( V_13 )
return V_13 ;
F_83 ( V_12 , V_179 ) ;
F_256 ( V_12 -> V_18 , & V_12 -> V_616 ) ;
if ( V_12 -> V_226 ) {
F_88 ( V_9 , V_12 ,
V_227 ) ;
V_12 -> V_226 = false ;
}
return 0 ;
}
static void F_257 ( struct V_11 * V_12 )
{
if ( F_254 ( V_12 ) ) {
F_258 ( V_12 , L_6 ) ;
F_259 ( V_12 -> V_9 -> V_114 . V_2 , & V_12 -> V_10 ,
V_166 ) ;
}
}
void F_260 ( struct V_617 * V_580 )
{
struct V_11 * V_12 =
F_160 ( V_580 , struct V_11 ,
V_613 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
F_217 ( V_12 ) ;
F_16 ( & V_9 -> V_150 ) ;
F_16 ( & V_9 -> V_31 ) ;
if ( ! V_12 -> V_26 . V_223 )
goto V_618;
if ( ! F_12 ( V_12 ) )
goto V_618;
F_257 ( V_12 ) ;
V_618:
F_18 ( & V_9 -> V_31 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_218 ( V_12 ) ;
}
static int F_261 ( struct V_11 * V_12 ,
struct V_619 * V_7 ,
T_1 * V_179 )
{
struct V_160 V_161 = {} ;
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_12 -> V_15 . V_165 . V_228 =
F_248 ( & V_7 -> V_620 ) ;
if ( ! V_12 -> V_15 . V_165 . V_228 )
return - V_167 ;
if ( V_7 -> V_187 <= 1 )
break;
if ( ( V_7 -> V_189 >
V_621 ) ||
( V_7 -> V_172 >
V_621 ) )
return - V_48 ;
V_161 . V_188 = V_7 -> V_188 ;
V_161 . V_171 = V_7 -> V_171 ;
V_161 . V_189 = V_7 -> V_189 ;
V_161 . V_172 = V_7 -> V_172 ;
V_161 . V_187 = V_7 -> V_187 ;
V_13 = F_76 ( V_12 , & V_7 -> V_622 , & V_161 ) ;
if ( V_13 < 0 ) {
F_89 ( V_12 -> V_15 . V_165 . V_228 ) ;
return V_13 ;
}
* V_179 |= V_13 ;
break;
case V_66 :
if ( ! V_12 -> V_26 . V_208 . V_623 )
return - V_48 ;
if ( V_7 -> V_148 . V_533 != V_12 -> V_15 . V_624 . V_148 . V_533 )
return - V_48 ;
switch ( V_7 -> V_148 . V_533 ) {
case V_625 :
if ( F_262 ( & V_7 -> V_148 ) !=
F_262 ( & V_12 -> V_15 . V_624 . V_148 ) )
return - V_48 ;
case V_626 :
case V_627 :
case V_534 :
case V_628 :
break;
default:
return - V_48 ;
}
if ( V_12 -> V_15 . V_624 . V_148 . V_576 -> V_262 !=
V_7 -> V_148 . V_576 -> V_262 )
return - V_48 ;
if ( V_7 -> V_187 > 1 ) {
V_13 = F_263 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
}
F_264 ( V_12 , V_7 ) ;
break;
#ifdef F_33
case V_67 : {
struct V_366 * V_367 = & V_12 -> V_15 . V_68 ;
if ( V_7 -> V_148 . V_533 != V_12 -> V_26 . V_208 . V_148 . V_533 )
return - V_48 ;
if ( V_12 -> V_26 . V_208 . V_148 . V_576 -> V_262 !=
V_7 -> V_148 . V_576 -> V_262 )
return - V_48 ;
if ( V_367 -> V_629 == V_630 ) {
V_367 -> V_629 = V_631 ;
if ( ! V_367 -> V_632 )
V_367 -> V_632 = 1 ;
else
V_367 -> V_632 ++ ;
}
if ( V_7 -> V_187 > 1 ) {
V_13 = F_265 ( V_12 , V_7 ) ;
if ( V_13 < 0 ) {
V_367 -> V_629 = V_630 ;
return V_13 ;
}
* V_179 |= V_13 ;
}
if ( V_367 -> V_629 == V_631 )
F_264 ( V_12 , V_7 ) ;
break;
}
#endif
default:
return - V_317 ;
}
return 0 ;
}
static int
F_266 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_619 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_633 * V_55 ;
struct V_634 * V_635 ;
int V_13 , V_179 = 0 ;
F_86 ( V_12 ) ;
F_215 ( & V_9 -> V_150 ) ;
if ( ! F_226 ( & V_9 -> V_584 ) || V_9 -> V_585 )
return - V_30 ;
if ( V_12 -> V_10 . V_232 )
return - V_30 ;
if ( F_65 ( & V_7 -> V_148 ,
& V_12 -> V_26 . V_208 . V_148 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_223 )
return - V_30 ;
F_16 ( & V_9 -> V_31 ) ;
V_55 = F_66 ( V_12 -> V_26 . V_636 ,
F_67 ( & V_9 -> V_31 ) ) ;
if ( ! V_55 ) {
V_13 = - V_30 ;
goto V_86;
}
V_635 = F_160 ( V_55 , struct V_634 , V_55 ) ;
if ( ! V_635 ) {
V_13 = - V_30 ;
goto V_86;
}
V_13 = F_267 ( V_12 , & V_7 -> V_148 ,
V_635 -> V_637 ,
V_7 -> V_638 ) ;
if ( V_13 )
goto V_86;
V_13 = F_17 ( V_12 , NULL , V_635 -> V_637 , 0 ) ;
if ( V_13 ) {
F_268 ( V_12 ) ;
goto V_86;
}
V_13 = F_261 ( V_12 , V_7 , & V_179 ) ;
if ( V_13 ) {
F_268 ( V_12 ) ;
goto V_86;
}
V_12 -> V_616 = V_7 -> V_148 ;
V_12 -> V_226 = V_7 -> V_639 ;
V_12 -> V_26 . V_223 = true ;
if ( V_12 -> V_226 )
F_269 ( V_9 , V_12 ,
V_227 ) ;
if ( V_179 ) {
F_83 ( V_12 , V_179 ) ;
F_270 ( V_12 , & V_7 -> V_148 ) ;
} else {
F_257 ( V_12 ) ;
}
V_86:
F_18 ( & V_9 -> V_31 ) ;
return V_13 ;
}
int F_271 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_619 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_150 ) ;
V_13 = F_266 ( V_2 , V_18 , V_7 ) ;
F_18 ( & V_9 -> V_150 ) ;
return V_13 ;
}
static int F_272 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_640 * V_7 ,
T_4 * V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_240 * V_241 ;
struct V_37 * V_23 ;
const struct V_641 * V_642 = ( void * ) V_7 -> V_643 ;
bool V_644 = false ;
T_1 V_5 ;
int V_19 ;
T_3 * V_169 ;
if ( V_7 -> V_645 )
V_5 = V_646 ;
else
V_5 = V_647 |
V_648 ;
if ( V_7 -> V_649 )
V_5 |= V_650 ;
switch ( V_12 -> V_26 . type ) {
case V_66 :
if ( ! V_12 -> V_26 . V_208 . V_623 )
V_644 = true ;
#ifdef F_33
case V_67 :
if ( F_28 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_68 . V_374 )
V_644 = true ;
#endif
case V_64 :
case V_20 :
case V_76 :
if ( V_12 -> V_26 . type != V_66 &&
! F_28 ( & V_12 -> V_26 ) &&
! F_273 ( V_12 -> V_321 -> V_181 ) )
V_644 = true ;
if ( ! F_274 ( V_642 -> V_651 ) ||
V_642 -> V_15 . V_652 . V_653 == V_654 ||
V_642 -> V_15 . V_652 . V_653 == V_655 ||
V_642 -> V_15 . V_652 . V_653 == V_656 )
break;
F_41 () ;
V_23 = F_29 ( V_12 , V_642 -> V_242 ) ;
F_45 () ;
if ( ! V_23 )
return - V_657 ;
break;
case V_24 :
case V_75 :
if ( ! V_12 -> V_15 . V_25 . V_541 )
V_644 = true ;
break;
case V_72 :
V_644 = true ;
break;
default:
return - V_317 ;
}
if ( V_644 && ! V_7 -> V_576 )
return - V_48 ;
F_16 ( & V_9 -> V_150 ) ;
if ( ! V_644 ) {
struct V_633 * V_636 ;
F_41 () ;
V_636 = F_42 ( V_12 -> V_26 . V_636 ) ;
if ( V_636 ) {
V_644 = V_7 -> V_576 &&
( V_7 -> V_576 !=
V_636 -> V_658 . V_576 ) ;
} else if ( ! V_7 -> V_576 ) {
V_19 = - V_48 ;
F_45 () ;
goto V_60;
} else {
V_644 = true ;
}
F_45 () ;
}
if ( V_644 && ! V_7 -> V_659 ) {
V_19 = - V_30 ;
goto V_60;
}
V_241 = F_100 ( V_9 -> V_114 . V_660 + V_7 -> V_168 ) ;
if ( ! V_241 ) {
V_19 = - V_167 ;
goto V_60;
}
F_275 ( V_241 , V_9 -> V_114 . V_660 ) ;
V_169 = F_101 ( V_241 , V_7 -> V_168 ) ;
memcpy ( V_169 , V_7 -> V_643 , V_7 -> V_168 ) ;
if ( V_12 -> V_26 . V_223 &&
( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_66 ) &&
V_7 -> V_661 ) {
int V_532 ;
struct V_175 * V_181 = NULL ;
F_41 () ;
if ( V_12 -> V_26 . type == V_64 )
V_181 = F_42 ( V_12 -> V_15 . V_165 . V_181 ) ;
else if ( V_12 -> V_26 . type == V_66 )
V_181 = F_42 ( V_12 -> V_15 . V_624 . V_662 ) ;
else if ( F_28 ( & V_12 -> V_26 ) )
V_181 = F_42 ( V_12 -> V_15 . V_68 . V_181 ) ;
if ( V_181 )
for ( V_532 = 0 ; V_532 < V_7 -> V_661 ; V_532 ++ )
V_169 [ V_7 -> V_663 [ V_532 ] ] =
V_181 -> V_186 ;
F_45 () ;
}
F_276 ( V_241 ) -> V_5 = V_5 ;
V_241 -> V_18 = V_12 -> V_18 ;
if ( ! V_644 ) {
* V_82 = ( unsigned long ) V_241 ;
F_277 ( V_12 , V_241 ) ;
V_19 = 0 ;
goto V_60;
}
F_276 ( V_241 ) -> V_5 |= V_664 |
V_665 ;
if ( V_9 -> V_114 . V_5 & V_666 )
F_276 ( V_241 ) -> V_667 =
V_9 -> V_114 . V_668 ;
V_19 = F_222 ( V_9 , V_12 , V_7 -> V_576 ,
V_7 -> V_669 , V_82 , V_241 ,
V_670 ) ;
if ( V_19 )
F_278 ( V_241 ) ;
V_60:
F_18 ( & V_9 -> V_150 ) ;
return V_19 ;
}
static int F_279 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_82 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_239 ( V_9 , V_82 , true ) ;
}
static void F_280 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_671 , bool V_672 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_671 ) {
case V_673 | V_674 :
if ( V_672 )
V_9 -> V_675 ++ ;
else
V_9 -> V_675 -- ;
if ( ! V_9 -> V_155 )
break;
F_212 ( & V_9 -> V_114 , & V_9 -> V_676 ) ;
break;
default:
break;
}
}
static int F_281 ( struct V_2 * V_2 , T_1 V_677 , T_1 V_678 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_589 )
return - V_317 ;
return F_282 ( V_9 , V_677 , V_678 ) ;
}
static int F_283 ( struct V_2 * V_2 , T_1 * V_677 , T_1 * V_678 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_284 ( V_9 , V_677 , V_678 ) ;
}
static int F_285 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_679 * V_169 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_468 -> V_680 )
return - V_317 ;
F_286 ( V_9 , V_12 , V_169 ) ;
return 0 ;
}
static int F_287 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_681 , T_4 * V_82 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_682 * V_683 ;
struct V_240 * V_241 ;
int V_178 = sizeof( * V_683 ) ;
T_7 V_684 ;
bool V_685 ;
struct V_686 * V_687 ;
struct V_37 * V_23 ;
struct V_633 * V_636 ;
enum V_261 V_262 ;
F_41 () ;
V_636 = F_42 ( V_12 -> V_26 . V_636 ) ;
if ( F_225 ( ! V_636 ) ) {
F_45 () ;
return - V_48 ;
}
V_262 = V_636 -> V_658 . V_576 -> V_262 ;
V_23 = F_30 ( V_12 , V_681 ) ;
if ( V_23 ) {
V_685 = F_31 ( V_23 , V_269 ) ;
} else {
F_45 () ;
return - V_657 ;
}
if ( V_685 ) {
V_684 = F_288 ( V_688 |
V_689 |
V_690 ) ;
} else {
V_178 -= 2 ;
V_684 = F_288 ( V_688 |
V_691 |
V_690 ) ;
}
V_241 = F_100 ( V_9 -> V_114 . V_660 + V_178 ) ;
if ( ! V_241 ) {
F_45 () ;
return - V_167 ;
}
V_241 -> V_18 = V_18 ;
F_275 ( V_241 , V_9 -> V_114 . V_660 ) ;
V_683 = ( void * ) F_101 ( V_241 , V_178 ) ;
V_683 -> V_651 = V_684 ;
V_683 -> V_692 = 0 ;
memcpy ( V_683 -> V_693 , V_23 -> V_23 . V_142 , V_143 ) ;
memcpy ( V_683 -> V_694 , V_12 -> V_26 . V_142 , V_143 ) ;
memcpy ( V_683 -> V_695 , V_12 -> V_26 . V_142 , V_143 ) ;
V_683 -> V_696 = 0 ;
V_687 = F_276 ( V_241 ) ;
V_687 -> V_5 |= V_648 |
V_647 ;
F_289 ( V_241 , V_697 ) ;
V_241 -> V_698 = 7 ;
if ( V_685 )
V_683 -> V_699 = F_288 ( 7 ) ;
F_290 () ;
F_291 ( V_12 , V_241 , V_262 ) ;
F_292 () ;
F_45 () ;
* V_82 = ( unsigned long ) V_241 ;
return 0 ;
}
static int F_293 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_147 * V_148 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_633 * V_636 ;
int V_19 = - V_700 ;
F_41 () ;
V_636 = F_42 ( V_12 -> V_26 . V_636 ) ;
if ( V_636 ) {
* V_148 = V_636 -> V_658 ;
V_19 = 0 ;
} else if ( V_9 -> V_155 > 0 &&
V_9 -> V_155 == V_9 -> V_156 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_152 )
* V_148 = V_9 -> V_149 ;
else
* V_148 = V_9 -> V_157 ;
V_19 = 0 ;
}
F_45 () ;
return V_19 ;
}
static void F_294 ( struct V_2 * V_2 , bool V_544 )
{
F_295 ( F_2 ( V_2 ) , V_544 ) ;
}
static int F_296 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_701 * V_702 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_703 * V_704 , * V_705 ;
if ( V_702 ) {
V_704 = F_73 ( sizeof( * V_704 ) , V_166 ) ;
if ( ! V_704 )
return - V_167 ;
memcpy ( & V_704 -> V_702 , V_702 , sizeof( * V_702 ) ) ;
} else {
V_704 = NULL ;
}
V_705 = F_72 ( V_12 -> V_702 , V_12 ) ;
F_74 ( V_12 -> V_702 , V_704 ) ;
if ( V_705 )
F_75 ( V_705 , V_173 ) ;
return 0 ;
}
static int F_297 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_147 * V_148 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
T_1 V_179 = 0 ;
V_19 = F_298 ( V_12 , V_148 , & V_179 ) ;
if ( V_19 == 0 )
F_83 ( V_12 , V_179 ) ;
return V_19 ;
}
