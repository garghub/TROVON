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
switch ( V_7 -> V_198 ) {
case V_199 :
V_12 -> V_198 = V_200 ;
break;
case V_201 :
V_12 -> V_198 = V_202 ;
break;
case V_203 :
V_12 -> V_198 = V_204 ;
break;
default:
return - V_48 ;
}
V_12 -> V_205 = V_12 -> V_9 -> V_206 ;
F_16 ( & V_9 -> V_150 ) ;
V_13 = F_69 ( V_12 , & V_7 -> V_148 ,
V_207 ) ;
if ( ! V_13 )
F_78 ( V_12 , false ) ;
F_18 ( & V_9 -> V_150 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_208 = V_7 -> V_209 . V_210 ;
V_12 -> V_211 = V_7 -> V_209 . V_211 ;
V_12 -> V_212 = F_79 ( V_12 -> V_9 ,
& V_7 -> V_209 ,
V_12 -> V_26 . type ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_208 =
V_7 -> V_209 . V_210 ;
V_22 -> V_211 =
V_7 -> V_209 . V_211 ;
V_22 -> V_212 =
F_79 ( V_12 -> V_9 ,
& V_7 -> V_209 ,
V_22 -> V_26 . type ) ;
}
V_12 -> V_26 . V_213 . V_214 = V_7 -> V_215 ;
V_12 -> V_26 . V_213 . V_216 = V_7 -> V_216 ;
V_12 -> V_26 . V_213 . V_217 = true ;
V_12 -> V_26 . V_213 . V_218 = V_7 -> V_218 ;
if ( V_7 -> V_218 )
memcpy ( V_12 -> V_26 . V_213 . V_219 , V_7 -> V_219 ,
V_7 -> V_218 ) ;
V_12 -> V_26 . V_213 . V_220 =
( V_7 -> V_220 != V_221 ) ;
memset ( & V_12 -> V_26 . V_213 . V_222 , 0 ,
sizeof( V_12 -> V_26 . V_213 . V_222 ) ) ;
V_12 -> V_26 . V_213 . V_222 . V_223 =
V_7 -> V_224 & V_225 ;
if ( V_7 -> V_226 )
V_12 -> V_26 . V_213 . V_222 . V_223 |=
V_227 ;
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
if ( V_12 -> V_26 . V_228 )
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
struct V_175 * V_229 ;
struct V_162 * V_230 ;
struct V_147 V_148 ;
F_86 ( V_12 ) ;
V_229 = F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) ;
if ( ! V_229 )
return - V_59 ;
V_230 = F_72 ( V_12 -> V_15 . V_165 . V_162 , V_12 ) ;
F_16 ( & V_9 -> V_150 ) ;
V_12 -> V_26 . V_228 = false ;
if ( V_12 -> V_231 ) {
F_88 ( V_9 , V_12 ,
V_232 ) ;
V_12 -> V_231 = false ;
}
F_18 ( & V_9 -> V_150 ) ;
F_89 ( V_12 -> V_15 . V_165 . V_233 ) ;
V_12 -> V_15 . V_165 . V_233 = NULL ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_90 ( V_22 -> V_18 ) ;
F_90 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_165 . V_181 , NULL ) ;
F_11 ( V_12 -> V_15 . V_165 . V_162 , NULL ) ;
F_75 ( V_229 , V_173 ) ;
if ( V_230 )
F_75 ( V_230 , V_173 ) ;
V_12 -> V_15 . V_165 . V_234 = V_200 ;
F_91 ( V_12 , true ) ;
F_92 ( V_12 , true ) ;
V_12 -> V_26 . V_213 . V_217 = false ;
V_12 -> V_26 . V_213 . V_218 = 0 ;
F_93 ( V_235 , & V_12 -> V_236 ) ;
F_83 ( V_12 , V_194 ) ;
if ( V_12 -> V_10 . V_237 ) {
V_148 = V_12 -> V_26 . V_213 . V_148 ;
F_94 ( & V_12 -> V_238 ) ;
F_95 ( V_12 -> V_18 , & V_148 ,
V_239 ,
V_166 ) ;
}
F_96 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_240 -= F_97 ( & V_12 -> V_15 . V_165 . V_241 . V_242 ) ;
F_98 ( & V_12 -> V_15 . V_165 . V_241 . V_242 ) ;
F_16 ( & V_9 -> V_150 ) ;
F_78 ( V_12 , true ) ;
F_68 ( V_12 ) ;
F_18 ( & V_9 -> V_150 ) ;
return 0 ;
}
static void F_99 ( struct V_37 * V_23 )
{
struct V_243 * V_244 ;
struct V_245 * V_246 ;
V_246 = F_100 ( sizeof( * V_244 ) ) ;
if ( ! V_246 )
return;
V_244 = (struct V_243 * ) F_101 ( V_246 , sizeof( * V_244 ) ) ;
F_102 ( V_244 -> V_247 ) ;
memcpy ( V_244 -> V_248 , V_23 -> V_23 . V_142 , V_143 ) ;
V_244 -> V_168 = F_103 ( 6 ) ;
V_244 -> V_249 = 0 ;
V_244 -> V_250 = 0x01 ;
V_244 -> V_251 = 0xaf ;
V_244 -> V_252 [ 0 ] = 0x81 ;
V_244 -> V_252 [ 1 ] = 1 ;
V_244 -> V_252 [ 2 ] = 0 ;
V_246 -> V_18 = V_23 -> V_12 -> V_18 ;
V_246 -> V_253 = F_104 ( V_246 , V_23 -> V_12 -> V_18 ) ;
memset ( V_246 -> V_254 , 0 , sizeof( V_246 -> V_254 ) ) ;
F_105 ( V_246 ) ;
}
static int F_106 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
T_1 V_27 , T_1 V_255 )
{
int V_19 ;
if ( V_27 & F_107 ( V_256 ) &&
V_255 & F_107 ( V_256 ) &&
! F_31 ( V_23 , V_257 ) ) {
V_19 = F_108 ( V_23 , V_258 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_259 ) &&
V_255 & F_107 ( V_259 ) &&
! F_31 ( V_23 , V_58 ) ) {
V_19 = F_108 ( V_23 , V_260 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_261 ) ) {
if ( V_255 & F_107 ( V_261 ) )
V_19 = F_108 ( V_23 , V_262 ) ;
else if ( F_31 ( V_23 , V_263 ) )
V_19 = F_108 ( V_23 , V_260 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_259 ) &&
! ( V_255 & F_107 ( V_259 ) ) &&
F_31 ( V_23 , V_58 ) ) {
V_19 = F_108 ( V_23 , V_258 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_256 ) &&
! ( V_255 & F_107 ( V_256 ) ) &&
F_31 ( V_23 , V_257 ) ) {
V_19 = F_108 ( V_23 , V_264 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_109 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
struct V_265 * V_7 )
{
int V_19 = 0 ;
struct V_110 * V_111 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_266 V_267 = F_54 ( V_12 ) ;
T_1 V_27 , V_255 ;
V_111 = V_9 -> V_114 . V_2 -> V_115 [ V_267 ] ;
V_27 = V_7 -> V_268 ;
V_255 = V_7 -> V_269 ;
if ( F_28 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_107 ( V_256 ) )
V_27 |= F_107 ( V_259 ) ;
if ( V_255 & F_107 ( V_256 ) )
V_255 |= F_107 ( V_259 ) ;
} else if ( F_31 ( V_23 , V_270 ) ) {
if ( V_255 & F_107 ( V_261 ) ) {
V_255 |= F_107 ( V_256 ) |
F_107 ( V_259 ) ;
V_27 |= F_107 ( V_256 ) |
F_107 ( V_259 ) ;
}
}
if ( ! F_31 ( V_23 , V_270 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_255 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_271 ) ) {
if ( V_255 & F_107 ( V_271 ) )
F_110 ( V_23 , V_272 ) ;
else
F_111 ( V_23 , V_272 ) ;
}
if ( V_27 & F_107 ( V_273 ) )
V_23 -> V_23 . V_274 = V_255 & F_107 ( V_273 ) ;
if ( V_27 & F_107 ( V_275 ) ) {
if ( V_255 & F_107 ( V_275 ) )
F_110 ( V_23 , V_65 ) ;
else
F_111 ( V_23 , V_65 ) ;
}
if ( V_27 & F_107 ( V_276 ) ) {
if ( V_255 & F_107 ( V_276 ) )
F_110 ( V_23 , V_270 ) ;
else
F_111 ( V_23 , V_270 ) ;
}
if ( V_7 -> V_277 & V_278 ) {
V_23 -> V_23 . V_279 = V_7 -> V_279 ;
V_23 -> V_23 . V_280 = V_7 -> V_280 ;
}
if ( V_7 -> V_281 )
V_23 -> V_23 . V_281 = V_7 -> V_281 ;
if ( V_7 -> V_282 >= 0 )
V_23 -> V_282 = V_7 -> V_282 ;
if ( V_7 -> V_283 ) {
F_112 ( & V_12 -> V_26 . V_213 . V_148 ,
V_111 , V_7 -> V_283 ,
V_7 -> V_284 ,
& V_23 -> V_23 . V_285 [ V_267 ] ) ;
}
if ( V_7 -> V_286 )
F_113 ( V_12 , V_111 ,
V_7 -> V_286 , V_23 ) ;
if ( V_7 -> V_287 )
F_114 ( V_12 , V_111 ,
V_7 -> V_287 , V_23 ) ;
if ( V_7 -> V_288 ) {
F_115 ( V_12 , V_23 ,
V_7 -> V_289 ,
V_267 , false ) ;
}
if ( F_28 ( & V_12 -> V_26 ) ) {
#ifdef F_33
T_1 V_179 = 0 ;
if ( V_7 -> V_277 & V_290 ) {
switch ( V_7 -> V_291 ) {
case V_292 :
if ( V_23 -> V_291 != V_292 )
V_179 = F_116 (
V_12 ) ;
V_23 -> V_291 = V_7 -> V_291 ;
F_117 ( V_23 ) ;
V_179 |= F_118 ( V_23 ,
V_12 -> V_15 . V_68 . V_293 . V_294 ) ;
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
if ( V_23 -> V_291 == V_292 )
V_179 = F_119 (
V_12 ) ;
V_23 -> V_291 = V_7 -> V_291 ;
F_117 ( V_23 ) ;
V_179 |= F_118 ( V_23 ,
V_301 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_302 ) {
case V_303 :
break;
case V_304 :
V_179 |= F_120 ( V_23 ) ;
break;
case V_305 :
V_179 |= F_121 ( V_23 ) ;
break;
}
if ( V_7 -> V_306 )
V_179 |=
F_118 ( V_23 ,
V_7 -> V_306 ) ;
F_122 ( V_12 , V_179 ) ;
#endif
}
if ( F_31 ( V_23 , V_270 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_255 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_123 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_139 ,
struct V_265 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_307 ;
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
if ( ! ( V_7 -> V_269 & F_107 ( V_276 ) ) ) {
F_127 ( V_23 , V_258 ) ;
F_127 ( V_23 , V_260 ) ;
} else {
V_23 -> V_23 . V_308 = true ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_128 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_31 ( V_23 , V_270 ) )
F_129 ( V_23 ) ;
V_307 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_64 ;
V_13 = F_130 ( V_23 ) ;
if ( V_13 ) {
F_45 () ;
return V_13 ;
}
if ( V_307 )
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
struct V_265 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_309 ;
enum V_310 V_311 ;
int V_13 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_30 ( V_12 , V_139 ) ;
if ( ! V_23 ) {
V_13 = - V_59 ;
goto V_312;
}
switch ( V_12 -> V_26 . type ) {
case V_67 :
if ( V_12 -> V_15 . V_68 . V_313 )
V_311 = V_314 ;
else
V_311 = V_315 ;
break;
case V_66 :
V_311 = V_316 ;
break;
case V_24 :
if ( ! F_31 ( V_23 , V_270 ) ) {
V_311 = V_317 ;
break;
}
if ( F_31 ( V_23 , V_263 ) )
V_311 = V_318 ;
else
V_311 = V_319 ;
break;
case V_64 :
case V_20 :
V_311 = V_320 ;
break;
default:
V_13 = - V_321 ;
goto V_312;
}
V_13 = F_135 ( V_2 , V_7 , V_311 ) ;
if ( V_13 )
goto V_312;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_322 = false ;
bool V_323 = false ;
V_309 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_146 -> V_21 ) {
if ( V_309 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_312;
}
F_74 ( V_309 -> V_15 . V_22 . V_23 , V_23 ) ;
V_323 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_11 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_322 = true ;
}
V_23 -> V_12 = V_309 ;
if ( V_23 -> V_324 == V_262 &&
V_322 != V_323 ) {
if ( V_323 )
F_136 ( & V_23 -> V_12 -> V_325 -> V_326 ) ;
else
F_137 ( & V_23 -> V_12 -> V_325 -> V_326 ) ;
}
F_99 ( V_23 ) ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_312;
if ( F_31 ( V_23 , V_270 ) &&
F_31 ( V_23 , V_263 ) )
F_129 ( V_23 ) ;
F_18 ( & V_9 -> V_57 ) ;
if ( ( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_327 != V_23 -> V_12 -> V_325 -> V_328 &&
F_31 ( V_23 , V_263 ) &&
F_138 ( V_23 ) != 1 ) {
F_139 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_142 ) ;
F_140 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_325 -> V_328 ,
V_23 -> V_23 . V_142 ,
V_23 -> V_12 -> V_26 . V_213 . V_329 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_268 & F_107 ( V_261 ) ) {
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
}
return 0 ;
V_312:
F_18 ( & V_9 -> V_57 ) ;
return V_13 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_330 , const T_3 * V_331 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_331 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_333 = F_144 ( V_12 , V_330 ) ;
if ( F_24 ( V_333 ) ) {
F_45 () ;
return F_27 ( V_333 ) ;
}
F_145 ( V_333 , V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_330 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_330 )
return F_147 ( V_12 , V_330 ) ;
F_148 ( V_12 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_330 , const T_3 * V_331 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_331 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_333 = F_150 ( V_12 , V_330 ) ;
if ( ! V_333 ) {
F_45 () ;
return - V_59 ;
}
F_145 ( V_333 , V_23 ) ;
F_45 () ;
return 0 ;
}
static void F_151 ( struct V_332 * V_333 , T_3 * V_331 ,
struct V_334 * V_335 )
{
struct V_37 * V_336 = F_42 ( V_333 -> V_331 ) ;
if ( V_336 )
memcpy ( V_331 , V_336 -> V_23 . V_142 , V_143 ) ;
else
memset ( V_331 , 0 , V_143 ) ;
memset ( V_335 , 0 , sizeof( * V_335 ) ) ;
V_335 -> V_337 = V_338 ;
V_335 -> V_339 = V_340 |
V_341 |
V_342 |
V_343 |
V_344 |
V_345 |
V_346 ;
V_335 -> V_347 = V_333 -> V_348 . V_349 ;
V_335 -> V_350 = V_333 -> V_350 ;
V_335 -> V_351 = V_333 -> V_351 ;
if ( F_152 ( V_352 , V_333 -> V_353 ) )
V_335 -> V_354 = F_153 ( V_333 -> V_353 - V_352 ) ;
V_335 -> V_355 =
F_153 ( V_333 -> V_355 ) ;
V_335 -> V_356 = V_333 -> V_356 ;
if ( V_333 -> V_5 & V_357 )
V_335 -> V_5 |= V_358 ;
if ( V_333 -> V_5 & V_359 )
V_335 -> V_5 |= V_360 ;
if ( V_333 -> V_5 & V_361 )
V_335 -> V_5 |= V_362 ;
if ( V_333 -> V_5 & V_363 )
V_335 -> V_5 |= V_364 ;
if ( V_333 -> V_5 & V_365 )
V_335 -> V_5 |= V_366 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_330 , T_3 * V_331 , struct V_334 * V_335 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_333 = F_150 ( V_12 , V_330 ) ;
if ( ! V_333 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_330 , V_333 -> V_330 , V_143 ) ;
F_151 ( V_333 , V_331 , V_335 ) ;
F_45 () ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_106 , T_3 * V_330 , T_3 * V_331 ,
struct V_334 * V_335 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_333 = F_156 ( V_12 , V_106 ) ;
if ( ! V_333 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_330 , V_333 -> V_330 , V_143 ) ;
F_151 ( V_333 , V_331 , V_335 ) ;
F_45 () ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_367 * V_55 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_55 , & ( V_12 -> V_15 . V_68 . V_293 ) , sizeof( struct V_367 ) ) ;
return 0 ;
}
static inline bool F_158 ( enum V_368 V_369 , T_1 V_27 )
{
return ( V_27 >> ( V_369 - 1 ) ) & 0x1 ;
}
static int F_159 ( struct V_370 * V_371 ,
const struct V_372 * V_373 )
{
T_3 * V_374 ;
const T_3 * V_375 ;
struct V_11 * V_12 = F_160 ( V_371 ,
struct V_11 , V_15 . V_68 ) ;
V_374 = NULL ;
V_375 = V_371 -> V_376 ;
if ( V_373 -> V_377 ) {
V_374 = F_161 ( V_373 -> V_376 , V_373 -> V_377 ,
V_166 ) ;
if ( ! V_374 )
return - V_167 ;
}
V_371 -> V_377 = V_373 -> V_377 ;
V_371 -> V_376 = V_374 ;
F_89 ( V_375 ) ;
V_371 -> V_378 = V_373 -> V_378 ;
memcpy ( V_371 -> V_379 , V_373 -> V_379 , V_371 -> V_378 ) ;
V_371 -> V_380 = V_373 -> V_381 ;
V_371 -> V_382 = V_373 -> V_383 ;
V_371 -> V_384 = V_373 -> V_385 ;
V_371 -> V_313 = V_373 -> V_313 ;
V_371 -> V_386 = V_373 -> V_387 ;
V_371 -> V_69 = V_70 ;
if ( V_373 -> V_388 )
V_371 -> V_69 |= V_389 ;
if ( V_373 -> V_390 )
V_371 -> V_69 |= V_391 ;
memcpy ( V_12 -> V_26 . V_213 . V_392 , V_373 -> V_392 ,
sizeof( V_373 -> V_392 ) ) ;
V_12 -> V_26 . V_213 . V_393 = V_373 -> V_393 ;
V_12 -> V_26 . V_213 . V_214 = V_373 -> V_215 ;
V_12 -> V_26 . V_213 . V_216 = V_373 -> V_216 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_367 * V_394 )
{
struct V_367 * V_55 ;
struct V_11 * V_12 ;
struct V_370 * V_371 ;
V_12 = F_9 ( V_18 ) ;
V_371 = & V_12 -> V_15 . V_68 ;
V_55 = & ( V_12 -> V_15 . V_68 . V_293 ) ;
if ( F_158 ( V_395 , V_27 ) )
V_55 -> V_396 = V_394 -> V_396 ;
if ( F_158 ( V_397 , V_27 ) )
V_55 -> V_398 = V_394 -> V_398 ;
if ( F_158 ( V_399 , V_27 ) )
V_55 -> V_400 = V_394 -> V_400 ;
if ( F_158 ( V_401 , V_27 ) )
V_55 -> V_402 = V_394 -> V_402 ;
if ( F_158 ( V_403 , V_27 ) )
V_55 -> V_404 = V_394 -> V_404 ;
if ( F_158 ( V_405 , V_27 ) )
V_55 -> V_406 = V_394 -> V_406 ;
if ( F_158 ( V_407 , V_27 ) )
V_55 -> V_408 = V_394 -> V_408 ;
if ( F_158 ( V_409 , V_27 ) ) {
if ( V_371 -> V_313 )
return - V_30 ;
V_55 -> V_410 = V_394 -> V_410 ;
}
if ( F_158 ( V_411 , V_27 ) )
V_55 -> V_412 =
V_394 -> V_412 ;
if ( F_158 ( V_413 , V_27 ) )
V_55 -> V_414 =
V_394 -> V_414 ;
if ( F_158 ( V_415 , V_27 ) )
V_55 -> V_416 = V_394 -> V_416 ;
if ( F_158 ( V_417 , V_27 ) )
V_55 -> V_418 = V_394 -> V_418 ;
if ( F_158 ( V_419 , V_27 ) )
V_55 -> V_420 =
V_394 -> V_420 ;
if ( F_158 ( V_421 , V_27 ) )
V_55 -> V_422 =
V_394 -> V_422 ;
if ( F_158 ( V_423 , V_27 ) )
V_55 -> V_424 =
V_394 -> V_424 ;
if ( F_158 ( V_425 ,
V_27 ) )
V_55 -> V_426 =
V_394 -> V_426 ;
if ( F_158 ( V_427 , V_27 ) ) {
V_55 -> V_428 = V_394 -> V_428 ;
F_163 ( V_371 ) ;
}
if ( F_158 ( V_429 , V_27 ) ) {
if ( V_394 -> V_430 &&
! ( V_55 -> V_428 > V_431 ) ) {
V_55 -> V_428 = V_432 ;
F_163 ( V_371 ) ;
}
V_55 -> V_430 =
V_394 -> V_430 ;
}
if ( F_158 ( V_433 , V_27 ) )
V_55 -> V_434 =
V_394 -> V_434 ;
if ( F_158 ( V_435 , V_27 ) )
V_55 -> V_436 = V_394 -> V_436 ;
if ( F_158 ( V_437 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_114 . V_5 & V_438 ) )
return - V_439 ;
V_55 -> V_440 = V_394 -> V_440 ;
}
if ( F_158 ( V_441 , V_27 ) ) {
V_55 -> V_442 = V_394 -> V_442 ;
V_12 -> V_26 . V_213 . V_443 = V_394 -> V_442 ;
F_83 ( V_12 , V_444 ) ;
}
if ( F_158 ( V_445 , V_27 ) )
V_55 -> V_446 =
V_394 -> V_446 ;
if ( F_158 ( V_447 , V_27 ) )
V_55 -> V_448 =
V_394 -> V_448 ;
if ( F_158 ( V_449 , V_27 ) )
V_55 -> V_450 =
V_394 -> V_450 ;
if ( F_158 ( V_451 , V_27 ) ) {
V_55 -> V_294 = V_394 -> V_294 ;
F_164 ( V_12 ) ;
}
if ( F_158 ( V_452 , V_27 ) )
V_55 -> V_453 =
V_394 -> V_453 ;
if ( F_158 ( V_454 , V_27 ) )
V_55 -> V_455 = V_394 -> V_455 ;
F_122 ( V_12 , V_180 ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_367 * V_55 ,
const struct V_372 * V_373 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_370 * V_371 = & V_12 -> V_15 . V_68 ;
int V_13 ;
memcpy ( & V_371 -> V_293 , V_55 , sizeof( struct V_367 ) ) ;
V_13 = F_159 ( V_371 , V_373 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_198 = V_200 ;
V_12 -> V_205 = V_12 -> V_9 -> V_206 ;
F_16 ( & V_12 -> V_9 -> V_150 ) ;
V_13 = F_69 ( V_12 , & V_373 -> V_148 ,
V_207 ) ;
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
struct V_456 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_266 V_267 ;
T_1 V_179 = 0 ;
if ( ! F_72 ( V_12 -> V_15 . V_165 . V_181 , V_12 ) )
return - V_59 ;
V_267 = F_54 ( V_12 ) ;
if ( V_7 -> V_457 >= 0 ) {
V_12 -> V_26 . V_213 . V_457 = V_7 -> V_457 ;
V_179 |= V_458 ;
}
if ( V_7 -> V_459 >= 0 ) {
V_12 -> V_26 . V_213 . V_459 =
V_7 -> V_459 ;
V_179 |= V_460 ;
}
if ( ! V_12 -> V_26 . V_213 . V_461 &&
V_267 == V_462 ) {
V_12 -> V_26 . V_213 . V_461 = true ;
V_179 |= V_463 ;
}
if ( V_7 -> V_464 >= 0 ) {
V_12 -> V_26 . V_213 . V_461 =
V_7 -> V_464 ;
V_179 |= V_463 ;
}
if ( V_7 -> V_393 ) {
F_112 ( & V_12 -> V_26 . V_213 . V_148 ,
V_2 -> V_115 [ V_267 ] ,
V_7 -> V_393 ,
V_7 -> V_465 ,
& V_12 -> V_26 . V_213 . V_393 ) ;
V_179 |= V_466 ;
}
if ( V_7 -> V_467 >= 0 ) {
if ( V_7 -> V_467 )
V_12 -> V_5 |= V_468 ;
else
V_12 -> V_5 &= ~ V_468 ;
}
if ( V_7 -> V_442 >= 0 ) {
V_12 -> V_26 . V_213 . V_443 =
( T_2 ) V_7 -> V_442 ;
V_179 |= V_444 ;
}
if ( V_7 -> V_224 >= 0 ) {
V_12 -> V_26 . V_213 . V_222 . V_223 &=
~ V_225 ;
V_12 -> V_26 . V_213 . V_222 . V_223 |=
V_7 -> V_224 & V_225 ;
V_179 |= V_196 ;
}
if ( V_7 -> V_226 > 0 ) {
V_12 -> V_26 . V_213 . V_222 . V_223 |=
V_227 ;
V_179 |= V_196 ;
} else if ( V_7 -> V_226 == 0 ) {
V_12 -> V_26 . V_213 . V_222 . V_223 &=
~ V_227 ;
V_179 |= V_196 ;
}
F_83 ( V_12 , V_179 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_469 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_470 V_471 ;
if ( ! V_9 -> V_472 -> V_473 )
return - V_321 ;
if ( V_9 -> V_114 . V_474 < V_475 )
return - V_321 ;
memset ( & V_471 , 0 , sizeof( V_471 ) ) ;
V_471 . V_476 = V_7 -> V_476 ;
V_471 . V_477 = V_7 -> V_478 ;
V_471 . V_479 = V_7 -> V_480 ;
V_471 . V_481 = V_7 -> V_481 ;
V_471 . V_482 = false ;
V_12 -> V_483 [ V_7 -> V_484 ] = V_471 ;
if ( F_171 ( V_9 , V_12 , V_7 -> V_484 , & V_471 ) ) {
F_172 ( V_9 -> V_114 . V_2 ,
L_2 ,
V_7 -> V_484 ) ;
return - V_48 ;
}
F_83 ( V_12 , V_485 ) ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 ,
struct V_486 * V_487 )
{
return F_174 ( F_2 ( V_2 ) , V_487 ) ;
}
static int F_175 ( struct V_2 * V_2 )
{
return F_176 ( F_2 ( V_2 ) ) ;
}
static int F_177 ( struct V_2 * V_2 ,
struct V_488 * V_489 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_489 -> V_10 ) ;
switch ( F_178 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_66 :
case V_67 :
case V_75 :
case V_72 :
break;
case V_76 :
if ( V_12 -> V_9 -> V_472 -> V_490 )
break;
case V_64 :
if ( V_12 -> V_15 . V_165 . V_181 &&
( ! ( V_2 -> V_491 & V_492 ) ||
! ( V_489 -> V_5 & V_493 ) ) )
return - V_321 ;
break;
default:
return - V_321 ;
}
return F_179 ( V_12 , V_489 ) ;
}
static int
F_180 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_494 * V_489 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_472 -> V_495 )
return - V_321 ;
return F_181 ( V_12 , V_489 ) ;
}
static int
F_182 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_472 -> V_496 )
return - V_321 ;
return F_183 ( V_12 ) ;
}
static int F_184 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_497 * V_489 )
{
return F_185 ( F_9 ( V_18 ) , V_489 ) ;
}
static int F_186 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_498 * V_489 )
{
return F_187 ( F_9 ( V_18 ) , V_489 ) ;
}
static int F_188 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_499 * V_489 )
{
return F_189 ( F_9 ( V_18 ) , V_489 ) ;
}
static int F_190 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_500 * V_489 )
{
return F_191 ( F_9 ( V_18 ) , V_489 ) ;
}
static int F_192 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_501 * V_7 )
{
return F_193 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_195 ( F_9 ( V_18 ) ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 [ V_502 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_213 . V_392 , V_100 ,
sizeof( int ) * V_502 ) ;
return 0 ;
}
static int F_197 ( struct V_2 * V_2 , T_1 V_179 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_179 & V_503 ) {
V_13 = F_198 ( V_9 , V_2 -> V_504 ) ;
if ( V_13 )
return V_13 ;
}
if ( ( V_179 & V_505 ) ||
( V_179 & V_506 ) ) {
T_6 V_507 ;
V_507 = V_179 & V_505 ?
V_2 -> V_507 : - 1 ;
V_13 = F_199 ( V_9 , V_507 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_179 & V_508 ) {
V_13 = F_200 ( V_9 , V_2 -> V_509 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_179 & V_510 ) {
if ( V_2 -> V_511 > V_512 )
return - V_48 ;
V_9 -> V_114 . V_55 . V_513 = V_2 -> V_511 ;
}
if ( V_179 & V_514 ) {
if ( V_2 -> V_515 > V_512 )
return - V_48 ;
V_9 -> V_114 . V_55 . V_516 = V_2 -> V_515 ;
}
if ( V_179 &
( V_510 | V_514 ) )
F_70 ( V_9 , V_517 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_518 type , int V_519 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_520 :
V_12 -> V_521 = V_522 ;
break;
case V_523 :
case V_524 :
if ( V_519 < 0 || ( V_519 % 100 ) )
return - V_321 ;
V_12 -> V_521 = F_202 ( V_519 ) ;
break;
}
F_203 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_520 :
V_9 -> V_521 = V_522 ;
break;
case V_523 :
case V_524 :
if ( V_519 < 0 || ( V_519 % 100 ) )
return - V_321 ;
V_9 -> V_521 = F_202 ( V_519 ) ;
break;
}
F_16 ( & V_9 -> V_151 ) ;
F_80 (sdata, &local->interfaces, list)
V_12 -> V_521 = V_9 -> V_521 ;
F_80 (sdata, &local->interfaces, list)
F_203 ( V_12 ) ;
F_18 ( & V_9 -> V_151 ) ;
return 0 ;
}
static int F_204 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_525 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_152 )
* V_525 = V_9 -> V_114 . V_55 . V_526 ;
else
* V_525 = V_12 -> V_26 . V_213 . V_527 ;
return 0 ;
}
static int F_205 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_142 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_528 . V_529 , V_142 , V_143 ) ;
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
struct V_530 * V_26 = NULL ;
if ( ! V_9 -> V_472 -> V_531 )
return - V_321 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_532 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_472 -> V_531 ( & V_9 -> V_114 , V_26 , V_169 , V_168 ) ;
}
static int F_209 ( struct V_2 * V_2 ,
struct V_245 * V_246 ,
struct V_533 * V_254 ,
void * V_169 , int V_168 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_472 -> V_534 )
return - V_321 ;
return V_9 -> V_472 -> V_534 ( & V_9 -> V_114 , V_246 , V_254 , V_169 , V_168 ) ;
}
int F_210 ( struct V_11 * V_12 ,
enum V_535 V_198 )
{
struct V_37 * V_23 ;
enum V_535 V_536 ;
int V_537 ;
if ( F_34 ( V_12 -> V_26 . type != V_64 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_213 . V_148 . V_538 == V_539 )
return 0 ;
V_536 = V_12 -> V_15 . V_165 . V_328 ;
V_12 -> V_15 . V_165 . V_328 = V_198 ;
if ( V_536 == V_198 ||
V_198 == V_540 )
return 0 ;
if ( ! F_211 ( & V_12 -> V_15 . V_165 . V_326 ) ) {
V_12 -> V_198 = V_198 ;
F_212 ( & V_12 -> V_9 -> V_114 , & V_12 -> V_541 ) ;
return 0 ;
}
F_139 ( V_12 ,
L_3 ,
V_198 , F_211 ( & V_12 -> V_15 . V_165 . V_326 ) ) ;
F_16 ( & V_12 -> V_9 -> V_57 ) ;
for ( V_537 = 0 ; V_537 < V_542 ; V_537 ++ ) {
for ( V_23 = F_66 ( V_12 -> V_9 -> V_543 [ V_537 ] ,
F_67 ( & V_12 -> V_9 -> V_57 ) ) ;
V_23 ;
V_23 = F_66 ( V_23 -> V_544 ,
F_67 ( & V_12 -> V_9 -> V_57 ) ) ) {
if ( V_23 -> V_12 -> V_325 != & V_12 -> V_15 . V_165 )
continue;
if ( F_138 ( V_23 ) == 1 )
continue;
if ( F_31 ( V_23 , V_545 ) &&
! F_213 ( V_23 -> V_327 ,
V_198 ) ) {
F_139 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_142 ) ;
continue;
}
if ( ! F_31 ( V_23 , V_263 ) )
continue;
F_139 ( V_12 , L_5 , V_23 -> V_23 . V_142 ) ;
F_140 ( V_12 , V_198 ,
V_23 -> V_23 . V_142 ,
V_12 -> V_26 . V_213 . V_329 ) ;
}
}
F_18 ( & V_12 -> V_9 -> V_57 ) ;
V_12 -> V_198 = V_198 ;
F_212 ( & V_12 -> V_9 -> V_114 , & V_12 -> V_541 ) ;
return 0 ;
}
int F_214 ( struct V_11 * V_12 ,
enum V_535 V_198 )
{
const T_3 * V_165 ;
enum V_535 V_536 ;
int V_13 ;
F_215 ( & V_12 -> V_10 . V_150 ) ;
if ( F_34 ( V_12 -> V_26 . type != V_24 ) )
return - V_48 ;
V_536 = V_12 -> V_15 . V_25 . V_328 ;
V_12 -> V_15 . V_25 . V_328 = V_198 ;
if ( V_536 == V_198 &&
V_198 != V_540 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_546 ||
V_12 -> V_26 . V_213 . V_148 . V_538 == V_539 )
return 0 ;
V_165 = V_12 -> V_15 . V_25 . V_546 -> V_329 ;
if ( V_198 == V_540 ) {
if ( V_12 -> V_15 . V_25 . V_547 )
V_198 = V_204 ;
else
V_198 = V_200 ;
}
V_13 = F_140 ( V_12 , V_198 ,
V_165 , V_165 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_328 = V_536 ;
return V_13 ;
}
static int F_216 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_548 , int V_549 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_146 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_321 ;
if ( ! ( V_9 -> V_114 . V_5 & V_550 ) )
return - V_321 ;
if ( V_548 == V_12 -> V_15 . V_25 . V_547 &&
V_549 == V_9 -> V_551 )
return 0 ;
V_12 -> V_15 . V_25 . V_547 = V_548 ;
V_9 -> V_551 = V_549 ;
F_217 ( V_12 ) ;
F_214 ( V_12 , V_12 -> V_15 . V_25 . V_328 ) ;
F_218 ( V_12 ) ;
if ( V_9 -> V_114 . V_5 & V_552 )
F_70 ( V_9 , V_553 ) ;
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
return 0 ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_7 V_554 , T_1 V_555 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_530 * V_26 = & V_12 -> V_26 ;
struct V_556 * V_213 = & V_26 -> V_213 ;
if ( V_554 == V_213 -> V_557 &&
V_555 == V_213 -> V_558 )
return 0 ;
V_213 -> V_557 = V_554 ;
V_213 -> V_558 = V_555 ;
if ( V_12 -> V_15 . V_25 . V_546 &&
V_12 -> V_26 . V_559 & V_560 )
F_83 ( V_12 , V_561 ) ;
return 0 ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_142 ,
const struct V_562 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_146 ) ;
int V_537 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
if ( V_9 -> V_114 . V_5 & V_563 ) {
V_19 = F_221 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_537 = 0 ; V_537 < V_502 ; V_537 ++ ) {
struct V_110 * V_111 = V_2 -> V_115 [ V_537 ] ;
int V_564 ;
V_12 -> V_565 [ V_537 ] = V_27 -> V_251 [ V_537 ] . V_118 ;
memcpy ( V_12 -> V_566 [ V_537 ] , V_27 -> V_251 [ V_537 ] . V_567 ,
sizeof( V_27 -> V_251 [ V_537 ] . V_567 ) ) ;
V_12 -> V_568 [ V_537 ] = false ;
if ( ! V_111 )
continue;
for ( V_564 = 0 ; V_564 < V_569 ; V_564 ++ )
if ( ~ V_12 -> V_566 [ V_537 ] [ V_564 ] ) {
V_12 -> V_568 [ V_537 ] = true ;
break;
}
}
return 0 ;
}
static bool F_222 ( struct V_8 * V_9 ,
struct V_570 * V_571 ,
struct V_570 * V_572 )
{
unsigned long V_564 = V_352 ;
unsigned long V_573 = V_572 -> V_574 +
F_223 ( V_572 -> V_575 ) ;
struct V_570 * V_576 ;
int V_577 ;
if ( F_224 ( ! V_572 -> V_578 || ! V_572 -> V_579 ) )
return false ;
if ( F_225 ( V_564 + V_580 , V_573 ) )
return false ;
F_226 ( V_571 ) ;
V_577 = V_571 -> V_575 - F_153 ( V_573 - V_564 ) ;
if ( V_577 <= 0 ) {
F_227 ( & V_571 -> V_581 , & V_572 -> V_582 ) ;
return true ;
}
V_571 -> V_575 = V_577 ;
V_576 = F_228 ( V_572 -> V_581 . V_583 ,
struct V_570 , V_581 ) ;
if ( & V_576 -> V_581 != & V_9 -> V_584 &&
V_576 -> V_585 == V_571 -> V_585 &&
V_576 -> V_12 == V_571 -> V_12 &&
! F_224 ( V_576 -> V_578 ) ) {
F_227 ( & V_571 -> V_581 , & V_576 -> V_582 ) ;
V_576 -> V_575 = F_229 ( V_576 -> V_575 ,
V_571 -> V_575 ) ;
V_576 -> type = F_229 ( V_576 -> type , V_571 -> type ) ;
return true ;
}
F_230 ( & V_571 -> V_581 , & V_572 -> V_581 ) ;
return true ;
}
static int F_231 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_586 * V_587 ,
unsigned int V_575 , T_4 * V_82 ,
struct V_245 * V_588 ,
enum V_589 type )
{
struct V_570 * V_590 , * V_591 ;
bool V_592 = false ;
int V_19 ;
F_215 ( & V_9 -> V_150 ) ;
if ( V_9 -> V_152 && ! V_9 -> V_472 -> V_593 )
return - V_321 ;
V_590 = F_73 ( sizeof( * V_590 ) , V_166 ) ;
if ( ! V_590 )
return - V_167 ;
if ( ! V_575 )
V_575 = 10 ;
V_590 -> V_585 = V_587 ;
V_590 -> V_575 = V_575 ;
V_590 -> V_594 = V_575 ;
V_590 -> V_595 = V_588 ;
V_590 -> type = type ;
V_590 -> V_596 = ( unsigned long ) V_588 ;
V_590 -> V_12 = V_12 ;
F_232 ( & V_590 -> V_597 , V_598 ) ;
F_233 ( & V_590 -> V_582 ) ;
if ( ! V_588 ) {
V_9 -> V_599 ++ ;
V_590 -> V_82 = V_9 -> V_599 ;
if ( F_224 ( V_590 -> V_82 == 0 ) ) {
V_590 -> V_82 = 1 ;
V_9 -> V_599 ++ ;
}
* V_82 = V_590 -> V_82 ;
} else {
* V_82 = ( unsigned long ) V_588 ;
}
if ( ! F_234 ( & V_9 -> V_584 ) ||
V_9 -> V_600 || V_9 -> V_601 )
goto V_602;
if ( ! V_9 -> V_472 -> V_593 ) {
F_235 ( & V_9 -> V_114 , & V_590 -> V_597 , 0 ) ;
goto V_603;
}
V_19 = F_236 ( V_9 , V_12 , V_587 , V_575 , type ) ;
if ( V_19 ) {
F_89 ( V_590 ) ;
return V_19 ;
}
V_590 -> V_578 = true ;
goto V_603;
V_602:
F_80 (tmp, &local->roc_list, list) {
if ( V_591 -> V_585 != V_587 || V_591 -> V_12 != V_12 )
continue;
if ( ! V_591 -> V_578 ) {
F_227 ( & V_590 -> V_581 , & V_591 -> V_582 ) ;
V_591 -> V_575 = F_229 ( V_591 -> V_575 , V_590 -> V_575 ) ;
V_591 -> type = F_229 ( V_591 -> type , V_590 -> type ) ;
V_592 = true ;
break;
}
if ( V_9 -> V_472 -> V_593 ) {
if ( ! V_591 -> V_579 ) {
F_227 ( & V_590 -> V_581 , & V_591 -> V_582 ) ;
V_592 = true ;
break;
}
if ( F_222 ( V_9 , V_590 , V_591 ) )
V_592 = true ;
} else if ( F_237 ( & V_591 -> V_597 . V_604 ) ) {
unsigned long V_605 ;
F_227 ( & V_590 -> V_581 , & V_591 -> V_582 ) ;
V_592 = true ;
V_605 = V_352 + F_223 ( V_590 -> V_575 ) ;
if ( F_225 ( V_605 , V_591 -> V_597 . V_604 . V_606 ) )
F_238 ( & V_591 -> V_597 . V_604 , V_605 ) ;
else
F_239 ( & V_591 -> V_597 . V_604 ) ;
F_226 ( V_590 ) ;
}
break;
}
V_603:
if ( ! V_592 )
F_227 ( & V_590 -> V_581 , & V_9 -> V_584 ) ;
return 0 ;
}
static int F_240 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_586 * V_585 ,
unsigned int V_575 ,
T_4 * V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_150 ) ;
V_19 = F_231 ( V_9 , V_12 , V_585 ,
V_575 , V_82 , NULL ,
V_607 ) ;
F_18 ( & V_9 -> V_150 ) ;
return V_19 ;
}
static int F_241 ( struct V_8 * V_9 ,
T_4 V_82 , bool V_608 )
{
struct V_570 * V_590 , * V_591 , * V_609 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_150 ) ;
F_242 (roc, tmp, &local->roc_list, list) {
struct V_570 * V_610 , * V_611 ;
F_242 (dep, tmp2, &roc->dependents, list) {
if ( ! V_608 && V_610 -> V_82 != V_82 )
continue;
else if ( V_608 && V_610 -> V_596 != V_82 )
continue;
F_243 ( & V_610 -> V_581 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_244 ( V_610 , true ) ;
return 0 ;
}
if ( ! V_608 && V_590 -> V_82 != V_82 )
continue;
else if ( V_608 && V_590 -> V_596 != V_82 )
continue;
V_609 = V_590 ;
break;
}
if ( ! V_609 ) {
F_18 ( & V_9 -> V_150 ) ;
return - V_59 ;
}
if ( V_9 -> V_472 -> V_593 ) {
if ( V_609 -> V_578 ) {
V_19 = F_245 ( V_9 ) ;
if ( F_34 ( V_19 ) ) {
F_18 ( & V_9 -> V_150 ) ;
return V_19 ;
}
}
F_243 ( & V_609 -> V_581 ) ;
if ( V_609 -> V_578 )
F_246 ( V_9 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_244 ( V_609 , true ) ;
} else {
V_609 -> abort = true ;
F_235 ( & V_9 -> V_114 , & V_609 -> V_597 , 0 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_247 ( & V_609 -> V_597 ) ;
F_224 ( ! V_609 -> V_612 ) ;
F_89 ( V_609 ) ;
}
return 0 ;
}
static int F_248 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_241 ( V_9 , V_82 , false ) ;
}
static int F_249 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_147 * V_148 ,
T_1 V_613 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_150 ) ;
if ( ! F_234 ( & V_9 -> V_584 ) || V_9 -> V_600 ) {
V_13 = - V_30 ;
goto V_60;
}
V_12 -> V_198 = V_200 ;
V_12 -> V_205 = V_9 -> V_206 ;
V_13 = F_69 ( V_12 , V_148 ,
V_207 ) ;
if ( V_13 )
goto V_60;
F_235 ( & V_12 -> V_9 -> V_114 ,
& V_12 -> V_238 ,
F_223 ( V_613 ) ) ;
V_60:
F_18 ( & V_9 -> V_150 ) ;
return V_13 ;
}
static struct V_174 *
F_250 ( struct V_174 * V_181 )
{
struct V_174 * V_614 ;
T_3 * V_615 ;
int V_168 ;
V_168 = V_181 -> V_183 + V_181 -> V_185 + V_181 -> V_616 +
V_181 -> V_617 + V_181 -> V_618 +
V_181 -> V_190 ;
V_614 = F_73 ( sizeof( * V_614 ) + V_168 , V_166 ) ;
if ( ! V_614 )
return NULL ;
V_615 = ( T_3 * ) ( V_614 + 1 ) ;
if ( V_181 -> V_183 ) {
V_614 -> V_183 = V_181 -> V_183 ;
V_614 -> V_182 = V_615 ;
memcpy ( V_615 , V_181 -> V_182 , V_181 -> V_183 ) ;
V_615 += V_181 -> V_183 ;
}
if ( V_181 -> V_185 ) {
V_614 -> V_185 = V_181 -> V_185 ;
V_614 -> V_184 = V_615 ;
memcpy ( V_615 , V_181 -> V_184 , V_181 -> V_185 ) ;
V_615 += V_181 -> V_185 ;
}
if ( V_181 -> V_616 ) {
V_614 -> V_616 = V_181 -> V_616 ;
V_614 -> V_619 = V_615 ;
memcpy ( V_615 , V_181 -> V_619 , V_181 -> V_616 ) ;
V_615 += V_181 -> V_616 ;
}
if ( V_181 -> V_617 ) {
V_614 -> V_617 = V_181 -> V_617 ;
V_614 -> V_620 = V_615 ;
memcpy ( V_615 , V_181 -> V_620 , V_181 -> V_617 ) ;
V_615 += V_181 -> V_617 ;
}
if ( V_181 -> V_618 ) {
V_614 -> V_618 = V_181 -> V_618 ;
V_614 -> V_621 = V_615 ;
memcpy ( V_615 , V_181 -> V_621 , V_181 -> V_618 ) ;
V_615 += V_181 -> V_618 ;
}
if ( V_181 -> V_190 ) {
V_614 -> V_190 = V_181 -> V_190 ;
V_181 -> V_162 = V_615 ;
memcpy ( V_615 , V_181 -> V_162 , V_181 -> V_190 ) ;
V_615 += V_181 -> V_190 ;
}
return V_614 ;
}
void F_251 ( struct V_530 * V_26 )
{
struct V_11 * V_12 = F_252 ( V_26 ) ;
F_212 ( & V_12 -> V_9 -> V_114 ,
& V_12 -> V_622 ) ;
}
static int F_253 ( struct V_11 * V_12 ,
T_1 * V_179 )
{
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_13 = F_76 ( V_12 , V_12 -> V_15 . V_165 . V_233 ,
NULL ) ;
F_89 ( V_12 -> V_15 . V_165 . V_233 ) ;
V_12 -> V_15 . V_165 . V_233 = NULL ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
break;
case V_66 :
V_13 = F_254 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
break;
#ifdef F_33
case V_67 :
V_13 = F_255 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
break;
#endif
default:
F_224 ( 1 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_256 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_1 V_179 = 0 ;
int V_13 ;
F_86 ( V_12 ) ;
F_215 ( & V_9 -> V_150 ) ;
F_215 ( & V_9 -> V_31 ) ;
if ( V_12 -> V_623 ) {
if ( V_12 -> V_624 )
return 0 ;
V_13 = F_257 ( V_12 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
if ( ! F_65 ( & V_12 -> V_26 . V_213 . V_148 ,
& V_12 -> V_625 ) )
return - V_48 ;
V_12 -> V_26 . V_228 = false ;
V_13 = F_253 ( V_12 , & V_179 ) ;
if ( V_13 )
return V_13 ;
F_83 ( V_12 , V_179 ) ;
F_258 ( V_12 -> V_18 , & V_12 -> V_625 ) ;
if ( V_12 -> V_231 ) {
F_88 ( V_9 , V_12 ,
V_232 ) ;
V_12 -> V_231 = false ;
}
return 0 ;
}
static void F_259 ( struct V_11 * V_12 )
{
if ( F_256 ( V_12 ) ) {
F_260 ( V_12 , L_6 ) ;
F_261 ( V_12 -> V_9 -> V_114 . V_2 , & V_12 -> V_10 ,
V_166 ) ;
}
}
void F_262 ( struct V_626 * V_597 )
{
struct V_11 * V_12 =
F_160 ( V_597 , struct V_11 ,
V_622 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
F_217 ( V_12 ) ;
F_16 ( & V_9 -> V_150 ) ;
F_16 ( & V_9 -> V_31 ) ;
if ( ! V_12 -> V_26 . V_228 )
goto V_627;
if ( ! F_12 ( V_12 ) )
goto V_627;
F_259 ( V_12 ) ;
V_627:
F_18 ( & V_9 -> V_31 ) ;
F_18 ( & V_9 -> V_150 ) ;
F_218 ( V_12 ) ;
}
static int F_263 ( struct V_11 * V_12 ,
struct V_628 * V_7 ,
T_1 * V_179 )
{
struct V_160 V_161 = {} ;
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_12 -> V_15 . V_165 . V_233 =
F_250 ( & V_7 -> V_629 ) ;
if ( ! V_12 -> V_15 . V_165 . V_233 )
return - V_167 ;
if ( V_7 -> V_187 <= 1 )
break;
if ( ( V_7 -> V_189 >
V_630 ) ||
( V_7 -> V_172 >
V_630 ) )
return - V_48 ;
V_161 . V_188 = V_7 -> V_188 ;
V_161 . V_171 = V_7 -> V_171 ;
V_161 . V_189 = V_7 -> V_189 ;
V_161 . V_172 = V_7 -> V_172 ;
V_161 . V_187 = V_7 -> V_187 ;
V_13 = F_76 ( V_12 , & V_7 -> V_631 , & V_161 ) ;
if ( V_13 < 0 ) {
F_89 ( V_12 -> V_15 . V_165 . V_233 ) ;
return V_13 ;
}
* V_179 |= V_13 ;
break;
case V_66 :
if ( ! V_12 -> V_26 . V_213 . V_632 )
return - V_48 ;
if ( V_7 -> V_148 . V_538 != V_12 -> V_15 . V_633 . V_148 . V_538 )
return - V_48 ;
switch ( V_7 -> V_148 . V_538 ) {
case V_634 :
if ( F_264 ( & V_7 -> V_148 ) !=
F_264 ( & V_12 -> V_15 . V_633 . V_148 ) )
return - V_48 ;
case V_635 :
case V_636 :
case V_539 :
case V_637 :
break;
default:
return - V_48 ;
}
if ( V_12 -> V_15 . V_633 . V_148 . V_585 -> V_267 !=
V_7 -> V_148 . V_585 -> V_267 )
return - V_48 ;
if ( V_7 -> V_187 > 1 ) {
V_13 = F_265 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_179 |= V_13 ;
}
F_266 ( V_12 , V_7 ) ;
break;
#ifdef F_33
case V_67 : {
struct V_370 * V_371 = & V_12 -> V_15 . V_68 ;
if ( V_7 -> V_148 . V_538 != V_12 -> V_26 . V_213 . V_148 . V_538 )
return - V_48 ;
if ( V_12 -> V_26 . V_213 . V_148 . V_585 -> V_267 !=
V_7 -> V_148 . V_585 -> V_267 )
return - V_48 ;
if ( V_371 -> V_638 == V_639 ) {
V_371 -> V_638 = V_640 ;
if ( ! V_371 -> V_641 )
V_371 -> V_641 = 1 ;
else
V_371 -> V_641 ++ ;
}
if ( V_7 -> V_187 > 1 ) {
V_13 = F_267 ( V_12 , V_7 ) ;
if ( V_13 < 0 ) {
V_371 -> V_638 = V_639 ;
return V_13 ;
}
* V_179 |= V_13 ;
}
if ( V_371 -> V_638 == V_640 )
F_266 ( V_12 , V_7 ) ;
break;
}
#endif
default:
return - V_321 ;
}
return 0 ;
}
static int
F_268 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_628 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_642 * V_55 ;
struct V_643 * V_644 ;
int V_13 , V_179 = 0 ;
F_86 ( V_12 ) ;
F_215 ( & V_9 -> V_150 ) ;
if ( ! F_234 ( & V_9 -> V_584 ) || V_9 -> V_600 )
return - V_30 ;
if ( V_12 -> V_10 . V_237 )
return - V_30 ;
if ( F_65 ( & V_7 -> V_148 ,
& V_12 -> V_26 . V_213 . V_148 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_228 )
return - V_30 ;
F_16 ( & V_9 -> V_31 ) ;
V_55 = F_66 ( V_12 -> V_26 . V_645 ,
F_67 ( & V_9 -> V_31 ) ) ;
if ( ! V_55 ) {
V_13 = - V_30 ;
goto V_86;
}
V_644 = F_160 ( V_55 , struct V_643 , V_55 ) ;
if ( ! V_644 ) {
V_13 = - V_30 ;
goto V_86;
}
V_13 = F_269 ( V_12 , & V_7 -> V_148 ,
V_644 -> V_646 ,
V_7 -> V_647 ) ;
if ( V_13 )
goto V_86;
V_13 = F_17 ( V_12 , NULL , V_644 -> V_646 , 0 ) ;
if ( V_13 ) {
F_270 ( V_12 ) ;
goto V_86;
}
V_13 = F_263 ( V_12 , V_7 , & V_179 ) ;
if ( V_13 ) {
F_270 ( V_12 ) ;
goto V_86;
}
V_12 -> V_625 = V_7 -> V_148 ;
V_12 -> V_231 = V_7 -> V_648 ;
V_12 -> V_26 . V_228 = true ;
if ( V_12 -> V_231 )
F_271 ( V_9 , V_12 ,
V_232 ) ;
if ( V_179 ) {
F_83 ( V_12 , V_179 ) ;
F_272 ( V_12 , & V_7 -> V_148 ) ;
} else {
F_259 ( V_12 ) ;
}
V_86:
F_18 ( & V_9 -> V_31 ) ;
return V_13 ;
}
int F_273 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_628 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_150 ) ;
V_13 = F_268 ( V_2 , V_18 , V_7 ) ;
F_18 ( & V_9 -> V_150 ) ;
return V_13 ;
}
static int F_274 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_649 * V_7 ,
T_4 * V_82 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_245 * V_246 ;
struct V_37 * V_23 ;
const struct V_650 * V_651 = ( void * ) V_7 -> V_652 ;
bool V_653 = false ;
T_1 V_5 ;
int V_19 ;
T_3 * V_169 ;
if ( V_7 -> V_654 )
V_5 = V_655 ;
else
V_5 = V_656 |
V_657 ;
if ( V_7 -> V_658 )
V_5 |= V_659 ;
switch ( V_12 -> V_26 . type ) {
case V_66 :
if ( ! V_12 -> V_26 . V_213 . V_632 )
V_653 = true ;
#ifdef F_33
case V_67 :
if ( F_28 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_68 . V_378 )
V_653 = true ;
#endif
case V_64 :
case V_20 :
case V_76 :
if ( V_12 -> V_26 . type != V_66 &&
! F_28 ( & V_12 -> V_26 ) &&
! F_275 ( V_12 -> V_325 -> V_181 ) )
V_653 = true ;
if ( ! F_276 ( V_651 -> V_660 ) ||
V_651 -> V_15 . V_661 . V_662 == V_663 ||
V_651 -> V_15 . V_661 . V_662 == V_664 ||
V_651 -> V_15 . V_661 . V_662 == V_665 )
break;
F_41 () ;
V_23 = F_29 ( V_12 , V_651 -> V_247 ) ;
F_45 () ;
if ( ! V_23 )
return - V_666 ;
break;
case V_24 :
case V_75 :
if ( ! V_12 -> V_15 . V_25 . V_546 )
V_653 = true ;
break;
case V_72 :
V_653 = true ;
break;
default:
return - V_321 ;
}
if ( V_653 && ! V_7 -> V_585 )
return - V_48 ;
F_16 ( & V_9 -> V_150 ) ;
if ( ! V_653 ) {
struct V_642 * V_645 ;
F_41 () ;
V_645 = F_42 ( V_12 -> V_26 . V_645 ) ;
if ( V_645 ) {
V_653 = V_7 -> V_585 &&
( V_7 -> V_585 !=
V_645 -> V_667 . V_585 ) ;
} else if ( ! V_7 -> V_585 ) {
V_19 = - V_48 ;
F_45 () ;
goto V_60;
} else {
V_653 = true ;
}
F_45 () ;
}
if ( V_653 && ! V_7 -> V_668 ) {
V_19 = - V_30 ;
goto V_60;
}
V_246 = F_100 ( V_9 -> V_114 . V_669 + V_7 -> V_168 ) ;
if ( ! V_246 ) {
V_19 = - V_167 ;
goto V_60;
}
F_277 ( V_246 , V_9 -> V_114 . V_669 ) ;
V_169 = F_101 ( V_246 , V_7 -> V_168 ) ;
memcpy ( V_169 , V_7 -> V_652 , V_7 -> V_168 ) ;
if ( V_12 -> V_26 . V_228 &&
( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_66 ) &&
V_7 -> V_670 ) {
int V_537 ;
struct V_175 * V_181 = NULL ;
F_41 () ;
if ( V_12 -> V_26 . type == V_64 )
V_181 = F_42 ( V_12 -> V_15 . V_165 . V_181 ) ;
else if ( V_12 -> V_26 . type == V_66 )
V_181 = F_42 ( V_12 -> V_15 . V_633 . V_671 ) ;
else if ( F_28 ( & V_12 -> V_26 ) )
V_181 = F_42 ( V_12 -> V_15 . V_68 . V_181 ) ;
if ( V_181 )
for ( V_537 = 0 ; V_537 < V_7 -> V_670 ; V_537 ++ )
V_169 [ V_7 -> V_672 [ V_537 ] ] =
V_181 -> V_186 ;
F_45 () ;
}
F_278 ( V_246 ) -> V_5 = V_5 ;
V_246 -> V_18 = V_12 -> V_18 ;
if ( ! V_653 ) {
* V_82 = ( unsigned long ) V_246 ;
F_279 ( V_12 , V_246 ) ;
V_19 = 0 ;
goto V_60;
}
F_278 ( V_246 ) -> V_5 |= V_673 |
V_674 ;
if ( V_9 -> V_114 . V_5 & V_675 )
F_278 ( V_246 ) -> V_676 =
V_9 -> V_114 . V_677 ;
V_19 = F_231 ( V_9 , V_12 , V_7 -> V_585 ,
V_7 -> V_678 , V_82 , V_246 ,
V_679 ) ;
if ( V_19 )
F_280 ( V_246 ) ;
V_60:
F_18 ( & V_9 -> V_150 ) ;
return V_19 ;
}
static int F_281 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_82 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_241 ( V_9 , V_82 , true ) ;
}
static void F_282 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_680 , bool V_681 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_680 ) {
case V_682 | V_683 :
if ( V_681 )
V_9 -> V_684 ++ ;
else
V_9 -> V_684 -- ;
if ( ! V_9 -> V_155 )
break;
F_212 ( & V_9 -> V_114 , & V_9 -> V_685 ) ;
break;
default:
break;
}
}
static int F_283 ( struct V_2 * V_2 , T_1 V_686 , T_1 V_687 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_578 )
return - V_321 ;
return F_284 ( V_9 , V_686 , V_687 ) ;
}
static int F_285 ( struct V_2 * V_2 , T_1 * V_686 , T_1 * V_687 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_286 ( V_9 , V_686 , V_687 ) ;
}
static int F_287 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_688 * V_169 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_472 -> V_689 )
return - V_321 ;
F_288 ( V_9 , V_12 , V_169 ) ;
return 0 ;
}
static int F_289 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_690 , T_4 * V_82 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_691 * V_692 ;
struct V_245 * V_246 ;
int V_178 = sizeof( * V_692 ) ;
T_8 V_693 ;
bool V_694 ;
struct V_695 * V_696 ;
struct V_37 * V_23 ;
struct V_642 * V_645 ;
enum V_266 V_267 ;
F_41 () ;
V_645 = F_42 ( V_12 -> V_26 . V_645 ) ;
if ( F_224 ( ! V_645 ) ) {
F_45 () ;
return - V_48 ;
}
V_267 = V_645 -> V_667 . V_585 -> V_267 ;
V_23 = F_30 ( V_12 , V_690 ) ;
if ( V_23 ) {
V_694 = V_23 -> V_23 . V_274 ;
} else {
F_45 () ;
return - V_666 ;
}
if ( V_694 ) {
V_693 = F_290 ( V_697 |
V_698 |
V_699 ) ;
} else {
V_178 -= 2 ;
V_693 = F_290 ( V_697 |
V_700 |
V_699 ) ;
}
V_246 = F_100 ( V_9 -> V_114 . V_669 + V_178 ) ;
if ( ! V_246 ) {
F_45 () ;
return - V_167 ;
}
V_246 -> V_18 = V_18 ;
F_277 ( V_246 , V_9 -> V_114 . V_669 ) ;
V_692 = ( void * ) F_101 ( V_246 , V_178 ) ;
V_692 -> V_660 = V_693 ;
V_692 -> V_701 = 0 ;
memcpy ( V_692 -> V_702 , V_23 -> V_23 . V_142 , V_143 ) ;
memcpy ( V_692 -> V_703 , V_12 -> V_26 . V_142 , V_143 ) ;
memcpy ( V_692 -> V_704 , V_12 -> V_26 . V_142 , V_143 ) ;
V_692 -> V_705 = 0 ;
V_696 = F_278 ( V_246 ) ;
V_696 -> V_5 |= V_657 |
V_656 ;
F_291 ( V_246 , V_706 ) ;
V_246 -> V_707 = 7 ;
if ( V_694 )
V_692 -> V_708 = F_290 ( 7 ) ;
F_292 () ;
F_293 ( V_12 , V_246 , V_267 ) ;
F_294 () ;
F_45 () ;
* V_82 = ( unsigned long ) V_246 ;
return 0 ;
}
static int F_295 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_147 * V_148 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_642 * V_645 ;
int V_19 = - V_709 ;
F_41 () ;
V_645 = F_42 ( V_12 -> V_26 . V_645 ) ;
if ( V_645 ) {
* V_148 = V_12 -> V_26 . V_213 . V_148 ;
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
static void F_296 ( struct V_2 * V_2 , bool V_548 )
{
F_297 ( F_2 ( V_2 ) , V_548 ) ;
}
static int F_298 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_710 * V_711 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_712 * V_713 , * V_714 ;
if ( V_711 ) {
V_713 = F_73 ( sizeof( * V_713 ) , V_166 ) ;
if ( ! V_713 )
return - V_167 ;
memcpy ( & V_713 -> V_711 , V_711 , sizeof( * V_711 ) ) ;
} else {
V_713 = NULL ;
}
V_714 = F_72 ( V_12 -> V_711 , V_12 ) ;
F_74 ( V_12 -> V_711 , V_713 ) ;
if ( V_714 )
F_75 ( V_714 , V_173 ) ;
return 0 ;
}
static int F_299 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_147 * V_148 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
T_1 V_179 = 0 ;
V_19 = F_300 ( V_12 , V_148 , & V_179 ) ;
if ( V_19 == 0 )
F_83 ( V_12 , V_179 ) ;
return V_19 ;
}
