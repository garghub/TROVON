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
case V_77 :
F_34 ( 1 ) ;
break;
}
if ( V_23 )
V_23 -> V_78 = V_39 ;
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
F_16 ( & V_9 -> V_79 ) ;
if ( V_35 ) {
V_19 = - V_59 ;
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_60;
if ( V_34 )
V_41 = F_37 ( V_9 , V_23 -> V_80 [ V_33 ] ) ;
else
V_41 = F_37 ( V_9 , V_23 -> V_81 [ V_33 ] ) ;
} else
V_41 = F_37 ( V_9 , V_12 -> V_82 [ V_33 ] ) ;
if ( ! V_41 ) {
V_19 = - V_59 ;
goto V_60;
}
F_38 ( V_41 , true ) ;
V_19 = 0 ;
V_60:
F_18 ( & V_9 -> V_79 ) ;
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_39 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_33 , bool V_34 , const T_3 * V_35 ,
void * V_83 ,
void (* F_40)( void * V_83 ,
struct V_36 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_37 * V_23 = NULL ;
T_3 V_54 [ 6 ] = { 0 } ;
struct V_36 V_7 ;
struct V_40 * V_41 = NULL ;
T_4 V_84 ;
T_1 V_85 ;
T_2 V_86 ;
int V_13 = - V_59 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
if ( V_35 ) {
V_23 = F_30 ( V_12 , V_35 ) ;
if ( ! V_23 )
goto V_87;
if ( V_34 && V_33 < V_88 )
V_41 = F_42 ( V_23 -> V_80 [ V_33 ] ) ;
else if ( ! V_34 &&
V_33 < V_88 + V_89 )
V_41 = F_42 ( V_23 -> V_81 [ V_33 ] ) ;
} else
V_41 = F_42 ( V_12 -> V_82 [ V_33 ] ) ;
if ( ! V_41 )
goto V_87;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_43 = V_41 -> V_55 . V_43 ;
switch ( V_41 -> V_55 . V_43 ) {
case V_45 :
V_85 = V_41 -> V_15 . V_90 . V_91 . V_85 ;
V_86 = V_41 -> V_15 . V_90 . V_91 . V_86 ;
if ( V_41 -> V_5 & V_92 )
F_43 ( V_12 -> V_9 ,
V_41 -> V_55 . V_93 ,
& V_85 , & V_86 ) ;
V_54 [ 0 ] = V_86 & 0xff ;
V_54 [ 1 ] = ( V_86 >> 8 ) & 0xff ;
V_54 [ 2 ] = V_85 & 0xff ;
V_54 [ 3 ] = ( V_85 >> 8 ) & 0xff ;
V_54 [ 4 ] = ( V_85 >> 16 ) & 0xff ;
V_54 [ 5 ] = ( V_85 >> 24 ) & 0xff ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
case V_49 :
V_84 = F_44 ( & V_41 -> V_15 . V_94 . V_95 ) ;
V_54 [ 0 ] = V_84 ;
V_54 [ 1 ] = V_84 >> 8 ;
V_54 [ 2 ] = V_84 >> 16 ;
V_54 [ 3 ] = V_84 >> 24 ;
V_54 [ 4 ] = V_84 >> 32 ;
V_54 [ 5 ] = V_84 >> 40 ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
case V_50 :
V_84 = F_44 ( & V_41 -> V_15 . V_96 . V_95 ) ;
V_54 [ 0 ] = V_84 ;
V_54 [ 1 ] = V_84 >> 8 ;
V_54 [ 2 ] = V_84 >> 16 ;
V_54 [ 3 ] = V_84 >> 24 ;
V_54 [ 4 ] = V_84 >> 32 ;
V_54 [ 5 ] = V_84 >> 40 ;
V_7 . V_54 = V_54 ;
V_7 . V_53 = 6 ;
break;
}
V_7 . V_41 = V_41 -> V_55 . V_41 ;
V_7 . V_52 = V_41 -> V_55 . V_97 ;
F_40 ( V_83 , & V_7 ) ;
V_13 = 0 ;
V_87:
F_45 () ;
return V_13 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_33 , bool V_98 ,
bool V_99 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_33 , V_98 , V_99 ) ;
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
const struct V_100 * V_101 ,
struct V_102 * V_103 )
{
V_103 -> V_5 = 0 ;
if ( V_101 -> V_5 & V_104 ) {
V_103 -> V_5 |= V_105 ;
V_103 -> V_106 = V_101 -> V_107 ;
} else if ( V_101 -> V_5 & V_108 ) {
V_103 -> V_5 |= V_109 ;
V_103 -> V_106 = F_51 ( V_101 ) ;
V_103 -> V_110 = F_52 ( V_101 ) ;
} else {
struct V_111 * V_112 ;
int V_113 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_114 ;
V_112 = V_23 -> V_9 -> V_115 . V_2 -> V_116 [
F_54 ( V_23 -> V_12 ) ] ;
V_114 = V_112 -> V_117 [ V_101 -> V_107 ] . V_118 ;
V_103 -> V_119 = F_55 ( V_114 , 1 << V_113 ) ;
}
if ( V_101 -> V_5 & V_120 )
V_103 -> V_5 |= V_121 ;
if ( V_101 -> V_5 & V_122 )
V_103 -> V_5 |= V_123 ;
if ( V_101 -> V_5 & V_124 )
V_103 -> V_5 |= V_125 ;
if ( V_101 -> V_5 & V_126 )
V_103 -> V_5 |= V_127 ;
}
void F_56 ( struct V_37 * V_23 , struct V_102 * V_103 )
{
V_103 -> V_5 = 0 ;
if ( V_23 -> V_128 & V_129 ) {
V_103 -> V_5 |= V_105 ;
V_103 -> V_106 = V_23 -> V_130 ;
} else if ( V_23 -> V_128 & V_131 ) {
V_103 -> V_5 |= V_109 ;
V_103 -> V_110 = V_23 -> V_132 ;
V_103 -> V_106 = V_23 -> V_130 ;
} else {
struct V_111 * V_112 ;
int V_113 = F_53 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_114 ;
V_112 = V_23 -> V_9 -> V_115 . V_2 -> V_116 [
F_54 ( V_23 -> V_12 ) ] ;
V_114 = V_112 -> V_117 [ V_23 -> V_130 ] . V_118 ;
V_103 -> V_119 = F_55 ( V_114 , 1 << V_113 ) ;
}
if ( V_23 -> V_128 & V_133 )
V_103 -> V_5 |= V_121 ;
if ( V_23 -> V_128 & V_134 )
V_103 -> V_5 |= V_127 ;
if ( V_23 -> V_135 & V_136 )
V_103 -> V_5 |= V_123 ;
if ( V_23 -> V_135 & V_137 )
V_103 -> V_5 |= V_138 ;
if ( V_23 -> V_135 & V_139 )
V_103 -> V_5 |= V_125 ;
}
static int F_57 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_107 , T_3 * V_140 , struct V_141 * V_142 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_59 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_58 ( V_12 , V_107 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_140 , V_23 -> V_23 . V_143 , V_144 ) ;
F_59 ( V_23 , V_142 ) ;
}
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_60 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_107 , struct V_145 * V_146 )
{
struct V_8 * V_9 = F_61 ( V_18 -> V_147 ) ;
return F_62 ( V_9 , V_107 , V_146 ) ;
}
static int F_63 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_140 , struct V_141 * V_142 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_37 * V_23 ;
int V_19 = - V_59 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_30 ( V_12 , V_140 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_59 ( V_23 , V_142 ) ;
}
F_18 ( & V_9 -> V_57 ) ;
return V_19 ;
}
static int F_64 ( struct V_2 * V_2 ,
struct V_148 * V_149 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_65 ( & V_9 -> V_150 , V_149 ) )
return 0 ;
F_16 ( & V_9 -> V_151 ) ;
F_16 ( & V_9 -> V_152 ) ;
if ( V_9 -> V_153 ) {
V_12 = F_66 (
V_9 -> V_154 ,
F_67 ( & V_9 -> V_152 ) ) ;
if ( V_12 ) {
F_68 ( V_12 ) ;
V_19 = F_69 ( V_12 , V_149 ,
V_155 ) ;
}
} else if ( V_9 -> V_156 == V_9 -> V_157 ) {
V_9 -> V_158 = * V_149 ;
F_70 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_150 = * V_149 ;
F_18 ( & V_9 -> V_152 ) ;
F_18 ( & V_9 -> V_151 ) ;
return V_19 ;
}
static int F_71 ( struct V_11 * V_12 ,
const T_3 * V_159 , T_5 V_160 ,
const struct V_161 * V_162 )
{
struct V_163 * V_164 , * V_165 ;
if ( ! V_159 || ! V_160 )
return 1 ;
V_165 = F_72 ( V_12 -> V_15 . V_166 . V_163 , V_12 ) ;
V_164 = F_73 ( sizeof( struct V_163 ) + V_160 , V_167 ) ;
if ( ! V_164 )
return - V_168 ;
V_164 -> V_169 = V_160 ;
memcpy ( V_164 -> V_170 , V_159 , V_160 ) ;
if ( V_162 )
memcpy ( V_164 -> V_171 , V_162 -> V_172 ,
V_162 -> V_173 *
sizeof( V_164 -> V_171 [ 0 ] ) ) ;
F_74 ( V_12 -> V_15 . V_166 . V_163 , V_164 ) ;
if ( V_165 )
F_75 ( V_165 , V_174 ) ;
return 0 ;
}
static int F_76 ( struct V_11 * V_12 ,
struct V_175 * V_7 ,
const struct V_161 * V_162 )
{
struct V_176 * V_164 , * V_165 ;
int V_177 , V_178 ;
int V_179 , V_13 ;
T_1 V_180 = V_181 ;
V_165 = F_72 ( V_12 -> V_15 . V_166 . V_182 , V_12 ) ;
if ( ! V_7 -> V_183 && ! V_165 )
return - V_48 ;
if ( V_7 -> V_183 )
V_177 = V_7 -> V_184 ;
else
V_177 = V_165 -> V_184 ;
if ( V_7 -> V_185 || ! V_165 )
V_178 = V_7 -> V_186 ;
else
V_178 = V_165 -> V_186 ;
V_179 = sizeof( * V_164 ) + V_177 + V_178 ;
V_164 = F_73 ( V_179 , V_167 ) ;
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
if ( V_7 -> V_183 )
memcpy ( V_164 -> V_183 , V_7 -> V_183 , V_177 ) ;
else
memcpy ( V_164 -> V_183 , V_165 -> V_183 , V_177 ) ;
if ( V_7 -> V_185 )
memcpy ( V_164 -> V_185 , V_7 -> V_185 , V_178 ) ;
else
if ( V_165 )
memcpy ( V_164 -> V_185 , V_165 -> V_185 , V_178 ) ;
V_13 = F_71 ( V_12 , V_7 -> V_163 ,
V_7 -> V_191 , V_162 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_180 |= V_192 ;
F_74 ( V_12 -> V_15 . V_166 . V_182 , V_164 ) ;
if ( V_165 )
F_75 ( V_165 , V_174 ) ;
return V_180 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_193 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_176 * V_165 ;
struct V_11 * V_22 ;
T_1 V_180 = V_194 |
V_195 |
V_181 |
V_196 |
V_197 ;
int V_13 ;
V_165 = F_72 ( V_12 -> V_15 . V_166 . V_182 , V_12 ) ;
if ( V_165 )
return - V_198 ;
switch ( V_7 -> V_199 ) {
case V_200 :
V_12 -> V_199 = V_201 ;
break;
case V_202 :
V_12 -> V_199 = V_203 ;
break;
case V_204 :
V_12 -> V_199 = V_205 ;
break;
default:
return - V_48 ;
}
V_12 -> V_206 = V_12 -> V_9 -> V_207 ;
F_16 ( & V_9 -> V_151 ) ;
V_13 = F_69 ( V_12 , & V_7 -> V_149 ,
V_208 ) ;
if ( ! V_13 )
F_78 ( V_12 , false ) ;
F_18 ( & V_9 -> V_151 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_209 = V_7 -> V_210 . V_211 ;
V_12 -> V_212 = V_7 -> V_210 . V_212 ;
V_12 -> V_213 = F_79 ( V_12 -> V_9 ,
& V_7 -> V_210 ,
V_12 -> V_26 . type ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_209 =
V_7 -> V_210 . V_211 ;
V_22 -> V_212 =
V_7 -> V_210 . V_212 ;
V_22 -> V_213 =
F_79 ( V_12 -> V_9 ,
& V_7 -> V_210 ,
V_22 -> V_26 . type ) ;
}
V_12 -> V_26 . V_214 . V_215 = V_7 -> V_216 ;
V_12 -> V_26 . V_214 . V_217 = V_7 -> V_217 ;
V_12 -> V_26 . V_214 . V_218 = true ;
V_12 -> V_26 . V_214 . V_219 = V_7 -> V_219 ;
if ( V_7 -> V_219 )
memcpy ( V_12 -> V_26 . V_214 . V_220 , V_7 -> V_220 ,
V_7 -> V_219 ) ;
V_12 -> V_26 . V_214 . V_221 =
( V_7 -> V_221 != V_222 ) ;
memset ( & V_12 -> V_26 . V_214 . V_223 , 0 ,
sizeof( V_12 -> V_26 . V_214 . V_223 ) ) ;
V_12 -> V_26 . V_214 . V_223 . V_224 =
V_7 -> V_225 & V_226 ;
if ( V_7 -> V_227 )
V_12 -> V_26 . V_214 . V_223 . V_224 |=
V_228 ;
V_13 = F_76 ( V_12 , & V_7 -> V_182 , NULL ) ;
if ( V_13 < 0 ) {
F_68 ( V_12 ) ;
return V_13 ;
}
V_180 |= V_13 ;
V_13 = F_81 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_165 = F_72 ( V_12 -> V_15 . V_166 . V_182 , V_12 ) ;
if ( V_165 )
F_75 ( V_165 , V_174 ) ;
F_11 ( V_12 -> V_15 . V_166 . V_182 , NULL ) ;
F_68 ( V_12 ) ;
return V_13 ;
}
F_82 ( V_9 , V_12 ) ;
F_83 ( V_12 , V_180 ) ;
F_84 ( V_18 ) ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_84 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_175 * V_7 )
{
struct V_11 * V_12 ;
struct V_176 * V_165 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_86 ( V_12 ) ;
if ( V_12 -> V_26 . V_229 )
return - V_30 ;
V_165 = F_72 ( V_12 -> V_15 . V_166 . V_182 , V_12 ) ;
if ( ! V_165 )
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
struct V_176 * V_230 ;
struct V_163 * V_231 ;
struct V_148 V_149 ;
F_86 ( V_12 ) ;
V_230 = F_72 ( V_12 -> V_15 . V_166 . V_182 , V_12 ) ;
if ( ! V_230 )
return - V_59 ;
V_231 = F_72 ( V_12 -> V_15 . V_166 . V_163 , V_12 ) ;
F_16 ( & V_9 -> V_151 ) ;
V_12 -> V_26 . V_229 = false ;
if ( V_12 -> V_232 ) {
F_88 ( V_9 , V_12 ,
V_233 ) ;
V_12 -> V_232 = false ;
}
F_18 ( & V_9 -> V_151 ) ;
F_89 ( V_12 -> V_15 . V_166 . V_234 ) ;
V_12 -> V_15 . V_166 . V_234 = NULL ;
F_80 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_90 ( V_22 -> V_18 ) ;
F_90 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_166 . V_182 , NULL ) ;
F_11 ( V_12 -> V_15 . V_166 . V_163 , NULL ) ;
F_75 ( V_230 , V_174 ) ;
if ( V_231 )
F_75 ( V_231 , V_174 ) ;
V_12 -> V_15 . V_166 . V_235 = V_201 ;
F_91 ( V_12 , true ) ;
F_92 ( V_12 , true ) ;
V_12 -> V_26 . V_214 . V_218 = false ;
V_12 -> V_26 . V_214 . V_219 = 0 ;
F_93 ( V_236 , & V_12 -> V_237 ) ;
F_83 ( V_12 , V_195 ) ;
if ( V_12 -> V_10 . V_238 ) {
V_149 = V_12 -> V_26 . V_214 . V_149 ;
F_94 ( & V_12 -> V_239 ) ;
F_95 ( V_12 -> V_18 , & V_149 ,
V_240 ,
V_167 ) ;
}
F_96 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_241 -= F_97 ( & V_12 -> V_15 . V_166 . V_242 . V_243 ) ;
F_98 ( & V_12 -> V_15 . V_166 . V_242 . V_243 ) ;
F_16 ( & V_9 -> V_151 ) ;
F_78 ( V_12 , true ) ;
F_68 ( V_12 ) ;
F_18 ( & V_9 -> V_151 ) ;
return 0 ;
}
static void F_99 ( struct V_37 * V_23 )
{
struct V_244 * V_245 ;
struct V_246 * V_247 ;
V_247 = F_100 ( sizeof( * V_245 ) ) ;
if ( ! V_247 )
return;
V_245 = (struct V_244 * ) F_101 ( V_247 , sizeof( * V_245 ) ) ;
F_102 ( V_245 -> V_248 ) ;
memcpy ( V_245 -> V_249 , V_23 -> V_23 . V_143 , V_144 ) ;
V_245 -> V_169 = F_103 ( 6 ) ;
V_245 -> V_250 = 0 ;
V_245 -> V_251 = 0x01 ;
V_245 -> V_252 = 0xaf ;
V_245 -> V_253 [ 0 ] = 0x81 ;
V_245 -> V_253 [ 1 ] = 1 ;
V_245 -> V_253 [ 2 ] = 0 ;
V_247 -> V_18 = V_23 -> V_12 -> V_18 ;
V_247 -> V_254 = F_104 ( V_247 , V_23 -> V_12 -> V_18 ) ;
memset ( V_247 -> V_255 , 0 , sizeof( V_247 -> V_255 ) ) ;
F_105 ( V_247 ) ;
}
static int F_106 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
T_1 V_27 , T_1 V_256 )
{
int V_19 ;
if ( V_27 & F_107 ( V_257 ) &&
V_256 & F_107 ( V_257 ) &&
! F_31 ( V_23 , V_258 ) ) {
V_19 = F_108 ( V_23 , V_259 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_260 ) &&
V_256 & F_107 ( V_260 ) &&
! F_31 ( V_23 , V_58 ) ) {
V_19 = F_108 ( V_23 , V_261 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_262 ) ) {
if ( V_256 & F_107 ( V_262 ) )
V_19 = F_108 ( V_23 , V_263 ) ;
else if ( F_31 ( V_23 , V_264 ) )
V_19 = F_108 ( V_23 , V_261 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_260 ) &&
! ( V_256 & F_107 ( V_260 ) ) &&
F_31 ( V_23 , V_58 ) ) {
V_19 = F_108 ( V_23 , V_259 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_257 ) &&
! ( V_256 & F_107 ( V_257 ) ) &&
F_31 ( V_23 , V_258 ) ) {
V_19 = F_108 ( V_23 , V_265 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_109 ( struct V_8 * V_9 ,
struct V_37 * V_23 ,
struct V_266 * V_7 )
{
int V_19 = 0 ;
struct V_111 * V_112 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_267 V_268 = F_54 ( V_12 ) ;
T_1 V_27 , V_256 ;
V_112 = V_9 -> V_115 . V_2 -> V_116 [ V_268 ] ;
V_27 = V_7 -> V_269 ;
V_256 = V_7 -> V_270 ;
if ( F_28 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_107 ( V_257 ) )
V_27 |= F_107 ( V_260 ) ;
if ( V_256 & F_107 ( V_257 ) )
V_256 |= F_107 ( V_260 ) ;
} else if ( F_31 ( V_23 , V_271 ) ) {
if ( V_256 & F_107 ( V_262 ) ) {
V_256 |= F_107 ( V_257 ) |
F_107 ( V_260 ) ;
V_27 |= F_107 ( V_257 ) |
F_107 ( V_260 ) ;
}
}
if ( ! F_31 ( V_23 , V_271 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_256 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_107 ( V_272 ) ) {
if ( V_256 & F_107 ( V_272 ) )
F_110 ( V_23 , V_273 ) ;
else
F_111 ( V_23 , V_273 ) ;
}
if ( V_27 & F_107 ( V_274 ) )
V_23 -> V_23 . V_275 = V_256 & F_107 ( V_274 ) ;
if ( V_27 & F_107 ( V_276 ) ) {
if ( V_256 & F_107 ( V_276 ) )
F_110 ( V_23 , V_65 ) ;
else
F_111 ( V_23 , V_65 ) ;
}
if ( V_27 & F_107 ( V_277 ) ) {
if ( V_256 & F_107 ( V_277 ) )
F_110 ( V_23 , V_271 ) ;
else
F_111 ( V_23 , V_271 ) ;
}
if ( F_31 ( V_23 , V_271 ) &&
! V_12 -> V_15 . V_25 . V_278 &&
V_7 -> V_279 >= 4 &&
V_7 -> V_280 [ 3 ] & V_281 )
F_110 ( V_23 , V_282 ) ;
if ( V_7 -> V_283 & V_284 ) {
V_23 -> V_23 . V_285 = V_7 -> V_285 ;
V_23 -> V_23 . V_286 = V_7 -> V_286 ;
}
if ( V_7 -> V_287 )
V_23 -> V_23 . V_287 = V_7 -> V_287 ;
if ( V_7 -> V_288 >= 0 )
V_23 -> V_288 = V_7 -> V_288 ;
if ( V_7 -> V_289 ) {
F_112 ( & V_12 -> V_26 . V_214 . V_149 ,
V_112 , V_7 -> V_289 ,
V_7 -> V_290 ,
& V_23 -> V_23 . V_291 [ V_268 ] ) ;
}
if ( V_7 -> V_292 )
F_113 ( V_12 , V_112 ,
V_7 -> V_292 , V_23 ) ;
if ( V_7 -> V_293 )
F_114 ( V_12 , V_112 ,
V_7 -> V_293 , V_23 ) ;
if ( V_7 -> V_294 ) {
F_115 ( V_12 , V_23 ,
V_7 -> V_295 ,
V_268 , false ) ;
}
if ( F_28 ( & V_12 -> V_26 ) ) {
#ifdef F_33
T_1 V_180 = 0 ;
if ( V_7 -> V_283 & V_296 ) {
switch ( V_7 -> V_297 ) {
case V_298 :
if ( V_23 -> V_297 != V_298 )
V_180 = F_116 (
V_12 ) ;
V_23 -> V_297 = V_7 -> V_297 ;
F_117 ( V_23 ) ;
V_180 |= F_118 ( V_23 ,
V_12 -> V_15 . V_68 . V_299 . V_300 ) ;
break;
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_306 :
if ( V_23 -> V_297 == V_298 )
V_180 = F_119 (
V_12 ) ;
V_23 -> V_297 = V_7 -> V_297 ;
F_117 ( V_23 ) ;
V_180 |= F_118 ( V_23 ,
V_307 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_308 ) {
case V_309 :
break;
case V_310 :
V_180 |= F_120 ( V_23 ) ;
break;
case V_311 :
V_180 |= F_121 ( V_23 ) ;
break;
}
if ( V_7 -> V_312 )
V_180 |=
F_118 ( V_23 ,
V_7 -> V_312 ) ;
F_122 ( V_12 , V_180 ) ;
#endif
}
if ( F_31 ( V_23 , V_271 ) ) {
V_19 = F_106 ( V_9 , V_23 , V_27 , V_256 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_123 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_140 ,
struct V_266 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_313 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_64 )
return - V_48 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_124 ( V_140 , V_12 -> V_26 . V_143 ) )
return - V_48 ;
if ( F_125 ( V_140 ) )
return - V_48 ;
V_23 = F_126 ( V_12 , V_140 , V_167 ) ;
if ( ! V_23 )
return - V_168 ;
if ( ! ( V_7 -> V_270 & F_107 ( V_277 ) ) ) {
F_127 ( V_23 , V_259 ) ;
F_127 ( V_23 , V_261 ) ;
} else {
V_23 -> V_23 . V_314 = true ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_128 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_31 ( V_23 , V_271 ) )
F_129 ( V_23 ) ;
V_313 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_64 ;
V_13 = F_130 ( V_23 ) ;
if ( V_13 ) {
F_45 () ;
return V_13 ;
}
if ( V_313 )
F_99 ( V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_315 * V_7 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_7 -> V_140 )
return F_132 ( V_12 , V_7 -> V_140 ) ;
F_133 ( V_12 ) ;
return 0 ;
}
static int F_134 ( struct V_2 * V_2 ,
struct V_17 * V_18 , const T_3 * V_140 ,
struct V_266 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_37 * V_23 ;
struct V_11 * V_316 ;
enum V_317 V_318 ;
int V_13 ;
F_16 ( & V_9 -> V_57 ) ;
V_23 = F_30 ( V_12 , V_140 ) ;
if ( ! V_23 ) {
V_13 = - V_59 ;
goto V_319;
}
switch ( V_12 -> V_26 . type ) {
case V_67 :
if ( V_12 -> V_15 . V_68 . V_320 )
V_318 = V_321 ;
else
V_318 = V_322 ;
break;
case V_66 :
V_318 = V_323 ;
break;
case V_24 :
if ( ! F_31 ( V_23 , V_271 ) ) {
V_318 = V_324 ;
break;
}
if ( F_31 ( V_23 , V_264 ) )
V_318 = V_325 ;
else
V_318 = V_326 ;
break;
case V_64 :
case V_20 :
V_318 = V_327 ;
break;
default:
V_13 = - V_328 ;
goto V_319;
}
V_13 = F_135 ( V_2 , V_7 , V_318 ) ;
if ( V_13 )
goto V_319;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_329 = false ;
bool V_330 = false ;
V_316 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_147 -> V_21 ) {
if ( V_316 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_319;
}
F_74 ( V_316 -> V_15 . V_22 . V_23 , V_23 ) ;
V_330 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_11 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_329 = true ;
}
V_23 -> V_12 = V_316 ;
if ( V_23 -> V_331 == V_263 &&
V_329 != V_330 ) {
if ( V_330 )
F_136 ( & V_23 -> V_12 -> V_332 -> V_333 ) ;
else
F_137 ( & V_23 -> V_12 -> V_332 -> V_333 ) ;
}
F_99 ( V_23 ) ;
}
V_13 = F_109 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_319;
if ( F_31 ( V_23 , V_271 ) &&
F_31 ( V_23 , V_264 ) )
F_129 ( V_23 ) ;
F_18 ( & V_9 -> V_57 ) ;
if ( ( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_334 != V_23 -> V_12 -> V_332 -> V_335 &&
F_31 ( V_23 , V_264 ) &&
F_138 ( V_23 ) != 1 ) {
F_139 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_143 ) ;
F_140 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_332 -> V_335 ,
V_23 -> V_23 . V_143 ,
V_23 -> V_12 -> V_26 . V_214 . V_336 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_269 & F_107 ( V_262 ) ) {
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
}
return 0 ;
V_319:
F_18 ( & V_9 -> V_57 ) ;
return V_13 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_337 , const T_3 * V_338 )
{
struct V_11 * V_12 ;
struct V_339 * V_340 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_338 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_340 = F_144 ( V_12 , V_337 ) ;
if ( F_24 ( V_340 ) ) {
F_45 () ;
return F_27 ( V_340 ) ;
}
F_145 ( V_340 , V_23 ) ;
F_45 () ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_337 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_337 )
return F_147 ( V_12 , V_337 ) ;
F_148 ( V_12 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_337 , const T_3 * V_338 )
{
struct V_11 * V_12 ;
struct V_339 * V_340 ;
struct V_37 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_23 = F_29 ( V_12 , V_338 ) ;
if ( ! V_23 ) {
F_45 () ;
return - V_59 ;
}
V_340 = F_150 ( V_12 , V_337 ) ;
if ( ! V_340 ) {
F_45 () ;
return - V_59 ;
}
F_145 ( V_340 , V_23 ) ;
F_45 () ;
return 0 ;
}
static void F_151 ( struct V_339 * V_340 , T_3 * V_338 ,
struct V_341 * V_342 )
{
struct V_37 * V_343 = F_42 ( V_340 -> V_338 ) ;
if ( V_343 )
memcpy ( V_338 , V_343 -> V_23 . V_143 , V_144 ) ;
else
memset ( V_338 , 0 , V_144 ) ;
memset ( V_342 , 0 , sizeof( * V_342 ) ) ;
V_342 -> V_344 = V_345 ;
V_342 -> V_346 = V_347 |
V_348 |
V_349 |
V_350 |
V_351 |
V_352 |
V_353 ;
V_342 -> V_354 = V_340 -> V_355 . V_356 ;
V_342 -> V_357 = V_340 -> V_357 ;
V_342 -> V_358 = V_340 -> V_358 ;
if ( F_152 ( V_359 , V_340 -> V_360 ) )
V_342 -> V_361 = F_153 ( V_340 -> V_360 - V_359 ) ;
V_342 -> V_362 =
F_153 ( V_340 -> V_362 ) ;
V_342 -> V_363 = V_340 -> V_363 ;
if ( V_340 -> V_5 & V_364 )
V_342 -> V_5 |= V_365 ;
if ( V_340 -> V_5 & V_366 )
V_342 -> V_5 |= V_367 ;
if ( V_340 -> V_5 & V_368 )
V_342 -> V_5 |= V_369 ;
if ( V_340 -> V_5 & V_370 )
V_342 -> V_5 |= V_371 ;
if ( V_340 -> V_5 & V_372 )
V_342 -> V_5 |= V_373 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_337 , T_3 * V_338 , struct V_341 * V_342 )
{
struct V_11 * V_12 ;
struct V_339 * V_340 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_340 = F_150 ( V_12 , V_337 ) ;
if ( ! V_340 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_337 , V_340 -> V_337 , V_144 ) ;
F_151 ( V_340 , V_338 , V_342 ) ;
F_45 () ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_107 , T_3 * V_337 , T_3 * V_338 ,
struct V_341 * V_342 )
{
struct V_11 * V_12 ;
struct V_339 * V_340 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_340 = F_156 ( V_12 , V_107 ) ;
if ( ! V_340 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_337 , V_340 -> V_337 , V_144 ) ;
F_151 ( V_340 , V_338 , V_342 ) ;
F_45 () ;
return 0 ;
}
static void F_157 ( struct V_339 * V_340 , T_3 * V_374 ,
struct V_341 * V_342 )
{
memset ( V_342 , 0 , sizeof( * V_342 ) ) ;
memcpy ( V_374 , V_340 -> V_374 , V_144 ) ;
V_342 -> V_344 = V_375 ;
}
static int F_158 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_337 , T_3 * V_374 , struct V_341 * V_342 )
{
struct V_11 * V_12 ;
struct V_339 * V_340 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_340 = F_159 ( V_12 , V_337 ) ;
if ( ! V_340 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_337 , V_340 -> V_337 , V_144 ) ;
F_157 ( V_340 , V_374 , V_342 ) ;
F_45 () ;
return 0 ;
}
static int F_160 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_107 , T_3 * V_337 , T_3 * V_374 ,
struct V_341 * V_342 )
{
struct V_11 * V_12 ;
struct V_339 * V_340 ;
V_12 = F_9 ( V_18 ) ;
F_41 () ;
V_340 = F_161 ( V_12 , V_107 ) ;
if ( ! V_340 ) {
F_45 () ;
return - V_59 ;
}
memcpy ( V_337 , V_340 -> V_337 , V_144 ) ;
F_157 ( V_340 , V_374 , V_342 ) ;
F_45 () ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_376 * V_55 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_55 , & ( V_12 -> V_15 . V_68 . V_299 ) , sizeof( struct V_376 ) ) ;
return 0 ;
}
static inline bool F_163 ( enum V_377 V_378 , T_1 V_27 )
{
return ( V_27 >> ( V_378 - 1 ) ) & 0x1 ;
}
static int F_164 ( struct V_379 * V_380 ,
const struct V_381 * V_382 )
{
T_3 * V_383 ;
const T_3 * V_384 ;
struct V_11 * V_12 = F_165 ( V_380 ,
struct V_11 , V_15 . V_68 ) ;
V_383 = NULL ;
V_384 = V_380 -> V_385 ;
if ( V_382 -> V_386 ) {
V_383 = F_166 ( V_382 -> V_385 , V_382 -> V_386 ,
V_167 ) ;
if ( ! V_383 )
return - V_168 ;
}
V_380 -> V_386 = V_382 -> V_386 ;
V_380 -> V_385 = V_383 ;
F_89 ( V_384 ) ;
V_380 -> V_387 = V_382 -> V_387 ;
memcpy ( V_380 -> V_388 , V_382 -> V_388 , V_380 -> V_387 ) ;
V_380 -> V_389 = V_382 -> V_390 ;
V_380 -> V_391 = V_382 -> V_392 ;
V_380 -> V_393 = V_382 -> V_394 ;
V_380 -> V_320 = V_382 -> V_320 ;
V_380 -> V_395 = V_382 -> V_396 ;
V_380 -> V_69 = V_70 ;
if ( V_382 -> V_397 )
V_380 -> V_69 |= V_398 ;
if ( V_382 -> V_399 )
V_380 -> V_69 |= V_400 ;
memcpy ( V_12 -> V_26 . V_214 . V_401 , V_382 -> V_401 ,
sizeof( V_382 -> V_401 ) ) ;
V_12 -> V_26 . V_214 . V_402 = V_382 -> V_402 ;
V_12 -> V_26 . V_214 . V_215 = V_382 -> V_216 ;
V_12 -> V_26 . V_214 . V_217 = V_382 -> V_217 ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_376 * V_403 )
{
struct V_376 * V_55 ;
struct V_11 * V_12 ;
struct V_379 * V_380 ;
V_12 = F_9 ( V_18 ) ;
V_380 = & V_12 -> V_15 . V_68 ;
V_55 = & ( V_12 -> V_15 . V_68 . V_299 ) ;
if ( F_163 ( V_404 , V_27 ) )
V_55 -> V_405 = V_403 -> V_405 ;
if ( F_163 ( V_406 , V_27 ) )
V_55 -> V_407 = V_403 -> V_407 ;
if ( F_163 ( V_408 , V_27 ) )
V_55 -> V_409 = V_403 -> V_409 ;
if ( F_163 ( V_410 , V_27 ) )
V_55 -> V_411 = V_403 -> V_411 ;
if ( F_163 ( V_412 , V_27 ) )
V_55 -> V_413 = V_403 -> V_413 ;
if ( F_163 ( V_414 , V_27 ) )
V_55 -> V_415 = V_403 -> V_415 ;
if ( F_163 ( V_416 , V_27 ) )
V_55 -> V_417 = V_403 -> V_417 ;
if ( F_163 ( V_418 , V_27 ) ) {
if ( V_380 -> V_320 )
return - V_30 ;
V_55 -> V_419 = V_403 -> V_419 ;
}
if ( F_163 ( V_420 , V_27 ) )
V_55 -> V_421 =
V_403 -> V_421 ;
if ( F_163 ( V_422 , V_27 ) )
V_55 -> V_423 =
V_403 -> V_423 ;
if ( F_163 ( V_424 , V_27 ) )
V_55 -> V_425 = V_403 -> V_425 ;
if ( F_163 ( V_426 , V_27 ) )
V_55 -> V_427 = V_403 -> V_427 ;
if ( F_163 ( V_428 , V_27 ) )
V_55 -> V_429 =
V_403 -> V_429 ;
if ( F_163 ( V_430 , V_27 ) )
V_55 -> V_431 =
V_403 -> V_431 ;
if ( F_163 ( V_432 , V_27 ) )
V_55 -> V_433 =
V_403 -> V_433 ;
if ( F_163 ( V_434 ,
V_27 ) )
V_55 -> V_435 =
V_403 -> V_435 ;
if ( F_163 ( V_436 , V_27 ) ) {
V_55 -> V_437 = V_403 -> V_437 ;
F_168 ( V_380 ) ;
}
if ( F_163 ( V_438 , V_27 ) ) {
if ( V_403 -> V_439 &&
! ( V_55 -> V_437 > V_440 ) ) {
V_55 -> V_437 = V_441 ;
F_168 ( V_380 ) ;
}
V_55 -> V_439 =
V_403 -> V_439 ;
}
if ( F_163 ( V_442 , V_27 ) )
V_55 -> V_443 =
V_403 -> V_443 ;
if ( F_163 ( V_444 , V_27 ) )
V_55 -> V_445 = V_403 -> V_445 ;
if ( F_163 ( V_446 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_115 . V_5 & V_447 ) )
return - V_448 ;
V_55 -> V_449 = V_403 -> V_449 ;
}
if ( F_163 ( V_450 , V_27 ) ) {
V_55 -> V_451 = V_403 -> V_451 ;
V_12 -> V_26 . V_214 . V_452 = V_403 -> V_451 ;
F_83 ( V_12 , V_453 ) ;
}
if ( F_163 ( V_454 , V_27 ) )
V_55 -> V_455 =
V_403 -> V_455 ;
if ( F_163 ( V_456 , V_27 ) )
V_55 -> V_457 =
V_403 -> V_457 ;
if ( F_163 ( V_458 , V_27 ) )
V_55 -> V_459 =
V_403 -> V_459 ;
if ( F_163 ( V_460 , V_27 ) ) {
V_55 -> V_300 = V_403 -> V_300 ;
F_169 ( V_12 ) ;
}
if ( F_163 ( V_461 , V_27 ) )
V_55 -> V_462 =
V_403 -> V_462 ;
if ( F_163 ( V_463 , V_27 ) )
V_55 -> V_464 = V_403 -> V_464 ;
F_122 ( V_12 , V_181 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_376 * V_55 ,
const struct V_381 * V_382 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_379 * V_380 = & V_12 -> V_15 . V_68 ;
int V_13 ;
memcpy ( & V_380 -> V_299 , V_55 , sizeof( struct V_376 ) ) ;
V_13 = F_164 ( V_380 , V_382 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_199 = V_201 ;
V_12 -> V_206 = V_12 -> V_9 -> V_207 ;
F_16 ( & V_12 -> V_9 -> V_151 ) ;
V_13 = F_69 ( V_12 , & V_382 -> V_149 ,
V_208 ) ;
F_18 ( & V_12 -> V_9 -> V_151 ) ;
if ( V_13 )
return V_13 ;
return F_171 ( V_12 ) ;
}
static int F_172 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_173 ( V_12 ) ;
F_16 ( & V_12 -> V_9 -> V_151 ) ;
F_68 ( V_12 ) ;
F_18 ( & V_12 -> V_9 -> V_151 ) ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_465 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_267 V_268 ;
T_1 V_180 = 0 ;
if ( ! F_72 ( V_12 -> V_15 . V_166 . V_182 , V_12 ) )
return - V_59 ;
V_268 = F_54 ( V_12 ) ;
if ( V_7 -> V_466 >= 0 ) {
V_12 -> V_26 . V_214 . V_466 = V_7 -> V_466 ;
V_180 |= V_467 ;
}
if ( V_7 -> V_468 >= 0 ) {
V_12 -> V_26 . V_214 . V_468 =
V_7 -> V_468 ;
V_180 |= V_469 ;
}
if ( ! V_12 -> V_26 . V_214 . V_470 &&
V_268 == V_471 ) {
V_12 -> V_26 . V_214 . V_470 = true ;
V_180 |= V_472 ;
}
if ( V_7 -> V_473 >= 0 ) {
V_12 -> V_26 . V_214 . V_470 =
V_7 -> V_473 ;
V_180 |= V_472 ;
}
if ( V_7 -> V_402 ) {
F_112 ( & V_12 -> V_26 . V_214 . V_149 ,
V_2 -> V_116 [ V_268 ] ,
V_7 -> V_402 ,
V_7 -> V_474 ,
& V_12 -> V_26 . V_214 . V_402 ) ;
V_180 |= V_475 ;
}
if ( V_7 -> V_476 >= 0 ) {
if ( V_7 -> V_476 )
V_12 -> V_5 |= V_477 ;
else
V_12 -> V_5 &= ~ V_477 ;
}
if ( V_7 -> V_451 >= 0 ) {
V_12 -> V_26 . V_214 . V_452 =
( T_2 ) V_7 -> V_451 ;
V_180 |= V_453 ;
}
if ( V_7 -> V_225 >= 0 ) {
V_12 -> V_26 . V_214 . V_223 . V_224 &=
~ V_226 ;
V_12 -> V_26 . V_214 . V_223 . V_224 |=
V_7 -> V_225 & V_226 ;
V_180 |= V_197 ;
}
if ( V_7 -> V_227 > 0 ) {
V_12 -> V_26 . V_214 . V_223 . V_224 |=
V_228 ;
V_180 |= V_197 ;
} else if ( V_7 -> V_227 == 0 ) {
V_12 -> V_26 . V_214 . V_223 . V_224 &=
~ V_228 ;
V_180 |= V_197 ;
}
F_83 ( V_12 , V_180 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_478 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_479 V_480 ;
if ( ! V_9 -> V_481 -> V_482 )
return - V_328 ;
if ( V_9 -> V_115 . V_483 < V_484 )
return - V_328 ;
memset ( & V_480 , 0 , sizeof( V_480 ) ) ;
V_480 . V_485 = V_7 -> V_485 ;
V_480 . V_486 = V_7 -> V_487 ;
V_480 . V_488 = V_7 -> V_489 ;
V_480 . V_490 = V_7 -> V_490 ;
V_480 . V_491 = false ;
V_12 -> V_492 [ V_7 -> V_493 ] = V_480 ;
if ( F_176 ( V_9 , V_12 , V_7 -> V_493 , & V_480 ) ) {
F_177 ( V_9 -> V_115 . V_2 ,
L_2 ,
V_7 -> V_493 ) ;
return - V_48 ;
}
F_83 ( V_12 , V_494 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 ,
struct V_495 * V_496 )
{
return F_179 ( F_2 ( V_2 ) , V_496 ) ;
}
static int F_180 ( struct V_2 * V_2 )
{
return F_181 ( F_2 ( V_2 ) ) ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_497 * V_498 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_498 -> V_10 ) ;
switch ( F_183 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_66 :
case V_67 :
case V_75 :
case V_72 :
break;
case V_76 :
if ( V_12 -> V_9 -> V_481 -> V_499 )
break;
case V_64 :
if ( V_12 -> V_15 . V_166 . V_182 &&
( ! ( V_2 -> V_500 & V_501 ) ||
! ( V_498 -> V_5 & V_502 ) ) )
return - V_328 ;
break;
default:
return - V_328 ;
}
return F_184 ( V_12 , V_498 ) ;
}
static int
F_185 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_503 * V_498 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_481 -> V_504 )
return - V_328 ;
return F_186 ( V_12 , V_498 ) ;
}
static int
F_187 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_481 -> V_505 )
return - V_328 ;
return F_188 ( V_12 ) ;
}
static int F_189 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_506 * V_498 )
{
return F_190 ( F_9 ( V_18 ) , V_498 ) ;
}
static int F_191 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_507 * V_498 )
{
return F_192 ( F_9 ( V_18 ) , V_498 ) ;
}
static int F_193 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_508 * V_498 )
{
return F_194 ( F_9 ( V_18 ) , V_498 ) ;
}
static int F_195 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_509 * V_498 )
{
return F_196 ( F_9 ( V_18 ) , V_498 ) ;
}
static int F_197 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_510 * V_7 )
{
return F_198 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_200 ( F_9 ( V_18 ) ) ;
}
static int F_201 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_511 * V_382 )
{
return F_202 ( F_9 ( V_18 ) , V_382 ) ;
}
static int F_203 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_204 ( F_9 ( V_18 ) ) ;
}
static int F_205 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_101 [ V_512 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_214 . V_401 , V_101 ,
sizeof( int ) * V_512 ) ;
return 0 ;
}
static int F_206 ( struct V_2 * V_2 , T_1 V_180 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_180 & V_513 ) {
V_13 = F_207 ( V_9 , V_2 -> V_514 ) ;
if ( V_13 )
return V_13 ;
}
if ( ( V_180 & V_515 ) ||
( V_180 & V_516 ) ) {
T_6 V_517 ;
V_517 = V_180 & V_515 ?
V_2 -> V_517 : - 1 ;
V_13 = F_208 ( V_9 , V_517 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_180 & V_518 ) {
V_13 = F_209 ( V_9 , V_2 -> V_519 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_180 & V_520 ) {
if ( V_2 -> V_521 > V_522 )
return - V_48 ;
V_9 -> V_115 . V_55 . V_523 = V_2 -> V_521 ;
}
if ( V_180 & V_524 ) {
if ( V_2 -> V_525 > V_522 )
return - V_48 ;
V_9 -> V_115 . V_55 . V_526 = V_2 -> V_525 ;
}
if ( V_180 &
( V_520 | V_524 ) )
F_70 ( V_9 , V_527 ) ;
return 0 ;
}
static int F_210 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_528 type , int V_529 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_530 :
V_12 -> V_531 = V_532 ;
break;
case V_533 :
case V_534 :
if ( V_529 < 0 || ( V_529 % 100 ) )
return - V_328 ;
V_12 -> V_531 = F_211 ( V_529 ) ;
break;
}
F_212 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_530 :
V_9 -> V_531 = V_532 ;
break;
case V_533 :
case V_534 :
if ( V_529 < 0 || ( V_529 % 100 ) )
return - V_328 ;
V_9 -> V_531 = F_211 ( V_529 ) ;
break;
}
F_16 ( & V_9 -> V_152 ) ;
F_80 (sdata, &local->interfaces, list)
V_12 -> V_531 = V_9 -> V_531 ;
F_80 (sdata, &local->interfaces, list)
F_212 ( V_12 ) ;
F_18 ( & V_9 -> V_152 ) ;
return 0 ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_535 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_9 -> V_481 -> V_536 )
return F_214 ( V_9 , V_12 , V_535 ) ;
if ( ! V_9 -> V_153 )
* V_535 = V_9 -> V_115 . V_55 . V_537 ;
else
* V_535 = V_12 -> V_26 . V_214 . V_538 ;
return 0 ;
}
static int F_215 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_143 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_539 . V_540 , V_143 , V_144 ) ;
return 0 ;
}
static void F_216 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_217 ( V_9 ) ;
}
static int F_218 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_170 , int V_169 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_541 * V_26 = NULL ;
if ( ! V_9 -> V_481 -> V_542 )
return - V_328 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_543 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_481 -> V_542 ( & V_9 -> V_115 , V_26 , V_170 , V_169 ) ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_246 * V_247 ,
struct V_544 * V_255 ,
void * V_170 , int V_169 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_481 -> V_545 )
return - V_328 ;
return V_9 -> V_481 -> V_545 ( & V_9 -> V_115 , V_247 , V_255 , V_170 , V_169 ) ;
}
int F_220 ( struct V_11 * V_12 ,
enum V_546 V_199 )
{
struct V_37 * V_23 ;
enum V_546 V_547 ;
int V_548 ;
if ( F_34 ( V_12 -> V_26 . type != V_64 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_214 . V_149 . V_549 == V_550 )
return 0 ;
V_547 = V_12 -> V_15 . V_166 . V_335 ;
V_12 -> V_15 . V_166 . V_335 = V_199 ;
if ( V_547 == V_199 ||
V_199 == V_551 )
return 0 ;
if ( ! F_221 ( & V_12 -> V_15 . V_166 . V_333 ) ) {
V_12 -> V_199 = V_199 ;
F_222 ( & V_12 -> V_9 -> V_115 , & V_12 -> V_552 ) ;
return 0 ;
}
F_139 ( V_12 ,
L_3 ,
V_199 , F_221 ( & V_12 -> V_15 . V_166 . V_333 ) ) ;
F_16 ( & V_12 -> V_9 -> V_57 ) ;
for ( V_548 = 0 ; V_548 < V_553 ; V_548 ++ ) {
for ( V_23 = F_66 ( V_12 -> V_9 -> V_554 [ V_548 ] ,
F_67 ( & V_12 -> V_9 -> V_57 ) ) ;
V_23 ;
V_23 = F_66 ( V_23 -> V_555 ,
F_67 ( & V_12 -> V_9 -> V_57 ) ) ) {
if ( V_23 -> V_12 -> V_332 != & V_12 -> V_15 . V_166 )
continue;
if ( F_138 ( V_23 ) == 1 )
continue;
if ( F_31 ( V_23 , V_556 ) &&
! F_223 ( V_23 -> V_334 ,
V_199 ) ) {
F_139 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_143 ) ;
continue;
}
if ( ! F_31 ( V_23 , V_264 ) )
continue;
F_139 ( V_12 , L_5 , V_23 -> V_23 . V_143 ) ;
F_140 ( V_12 , V_199 ,
V_23 -> V_23 . V_143 ,
V_12 -> V_26 . V_214 . V_336 ) ;
}
}
F_18 ( & V_12 -> V_9 -> V_57 ) ;
V_12 -> V_199 = V_199 ;
F_222 ( & V_12 -> V_9 -> V_115 , & V_12 -> V_552 ) ;
return 0 ;
}
int F_224 ( struct V_11 * V_12 ,
enum V_546 V_199 )
{
const T_3 * V_166 ;
enum V_546 V_547 ;
int V_13 ;
F_225 ( & V_12 -> V_10 . V_151 ) ;
if ( F_34 ( V_12 -> V_26 . type != V_24 ) )
return - V_48 ;
V_547 = V_12 -> V_15 . V_25 . V_335 ;
V_12 -> V_15 . V_25 . V_335 = V_199 ;
if ( V_547 == V_199 &&
V_199 != V_551 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_557 ||
V_12 -> V_26 . V_214 . V_149 . V_549 == V_550 )
return 0 ;
V_166 = V_12 -> V_15 . V_25 . V_557 -> V_336 ;
if ( V_199 == V_551 ) {
if ( V_12 -> V_15 . V_25 . V_558 )
V_199 = V_205 ;
else
V_199 = V_201 ;
}
V_13 = F_140 ( V_12 , V_199 ,
V_166 , V_166 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_335 = V_547 ;
return V_13 ;
}
static int F_226 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_559 , int V_560 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_147 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_328 ;
if ( ! ( V_9 -> V_115 . V_5 & V_561 ) )
return - V_328 ;
if ( V_559 == V_12 -> V_15 . V_25 . V_558 &&
V_560 == V_9 -> V_562 )
return 0 ;
V_12 -> V_15 . V_25 . V_558 = V_559 ;
V_9 -> V_562 = V_560 ;
F_227 ( V_12 ) ;
F_224 ( V_12 , V_12 -> V_15 . V_25 . V_335 ) ;
F_228 ( V_12 ) ;
if ( V_9 -> V_115 . V_5 & V_563 )
F_70 ( V_9 , V_564 ) ;
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
return 0 ;
}
static int F_229 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_7 V_565 , T_1 V_566 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_541 * V_26 = & V_12 -> V_26 ;
struct V_567 * V_214 = & V_26 -> V_214 ;
if ( V_565 == V_214 -> V_568 &&
V_566 == V_214 -> V_569 )
return 0 ;
V_214 -> V_568 = V_565 ;
V_214 -> V_569 = V_566 ;
if ( V_12 -> V_15 . V_25 . V_557 &&
V_12 -> V_26 . V_570 & V_571 )
F_83 ( V_12 , V_572 ) ;
return 0 ;
}
static int F_230 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_143 ,
const struct V_573 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_61 ( V_18 -> V_147 ) ;
int V_548 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_42 ;
if ( V_9 -> V_115 . V_5 & V_574 ) {
V_19 = F_231 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_548 = 0 ; V_548 < V_512 ; V_548 ++ ) {
struct V_111 * V_112 = V_2 -> V_116 [ V_548 ] ;
int V_575 ;
V_12 -> V_576 [ V_548 ] = V_27 -> V_252 [ V_548 ] . V_119 ;
memcpy ( V_12 -> V_577 [ V_548 ] , V_27 -> V_252 [ V_548 ] . V_578 ,
sizeof( V_27 -> V_252 [ V_548 ] . V_578 ) ) ;
V_12 -> V_579 [ V_548 ] = false ;
if ( ! V_112 )
continue;
for ( V_575 = 0 ; V_575 < V_580 ; V_575 ++ )
if ( ~ V_12 -> V_577 [ V_548 ] [ V_575 ] ) {
V_12 -> V_579 [ V_548 ] = true ;
break;
}
}
return 0 ;
}
static bool F_232 ( struct V_8 * V_9 ,
struct V_581 * V_582 ,
struct V_581 * V_583 )
{
unsigned long V_575 = V_359 ;
unsigned long V_584 = V_583 -> V_585 +
F_233 ( V_583 -> V_586 ) ;
struct V_581 * V_587 ;
int V_588 ;
if ( F_234 ( ! V_583 -> V_589 || ! V_583 -> V_590 ) )
return false ;
if ( F_235 ( V_575 + V_591 , V_584 ) )
return false ;
F_236 ( V_582 ) ;
V_588 = V_582 -> V_586 - F_153 ( V_584 - V_575 ) ;
if ( V_588 <= 0 ) {
F_237 ( & V_582 -> V_592 , & V_583 -> V_593 ) ;
return true ;
}
V_582 -> V_586 = V_588 ;
V_587 = F_238 ( V_583 -> V_592 . V_594 ,
struct V_581 , V_592 ) ;
if ( & V_587 -> V_592 != & V_9 -> V_595 &&
V_587 -> V_596 == V_582 -> V_596 &&
V_587 -> V_12 == V_582 -> V_12 &&
! F_234 ( V_587 -> V_589 ) ) {
F_237 ( & V_582 -> V_592 , & V_587 -> V_593 ) ;
V_587 -> V_586 = F_239 ( V_587 -> V_586 ,
V_582 -> V_586 ) ;
V_587 -> type = F_239 ( V_587 -> type , V_582 -> type ) ;
return true ;
}
F_240 ( & V_582 -> V_592 , & V_583 -> V_592 ) ;
return true ;
}
static int F_241 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_597 * V_598 ,
unsigned int V_586 , T_4 * V_83 ,
struct V_246 * V_599 ,
enum V_600 type )
{
struct V_581 * V_601 , * V_602 ;
bool V_603 = false ;
int V_19 ;
F_225 ( & V_9 -> V_151 ) ;
if ( V_9 -> V_153 && ! V_9 -> V_481 -> V_604 )
return - V_328 ;
V_601 = F_73 ( sizeof( * V_601 ) , V_167 ) ;
if ( ! V_601 )
return - V_168 ;
if ( ! V_586 )
V_586 = 10 ;
V_601 -> V_596 = V_598 ;
V_601 -> V_586 = V_586 ;
V_601 -> V_605 = V_586 ;
V_601 -> V_606 = V_599 ;
V_601 -> type = type ;
V_601 -> V_607 = ( unsigned long ) V_599 ;
V_601 -> V_12 = V_12 ;
F_242 ( & V_601 -> V_608 , V_609 ) ;
F_243 ( & V_601 -> V_593 ) ;
if ( ! V_599 ) {
V_9 -> V_610 ++ ;
V_601 -> V_83 = V_9 -> V_610 ;
if ( F_234 ( V_601 -> V_83 == 0 ) ) {
V_601 -> V_83 = 1 ;
V_9 -> V_610 ++ ;
}
* V_83 = V_601 -> V_83 ;
} else {
* V_83 = ( unsigned long ) V_599 ;
}
if ( ! F_244 ( & V_9 -> V_595 ) ||
V_9 -> V_611 || V_9 -> V_612 )
goto V_613;
if ( ! V_9 -> V_481 -> V_604 ) {
F_245 ( & V_9 -> V_115 , & V_601 -> V_608 , 0 ) ;
goto V_614;
}
V_19 = F_246 ( V_9 , V_12 , V_598 , V_586 , type ) ;
if ( V_19 ) {
F_89 ( V_601 ) ;
return V_19 ;
}
V_601 -> V_589 = true ;
goto V_614;
V_613:
F_80 (tmp, &local->roc_list, list) {
if ( V_602 -> V_596 != V_598 || V_602 -> V_12 != V_12 )
continue;
if ( ! V_602 -> V_589 ) {
F_237 ( & V_601 -> V_592 , & V_602 -> V_593 ) ;
V_602 -> V_586 = F_239 ( V_602 -> V_586 , V_601 -> V_586 ) ;
V_602 -> type = F_239 ( V_602 -> type , V_601 -> type ) ;
V_603 = true ;
break;
}
if ( V_9 -> V_481 -> V_604 ) {
if ( ! V_602 -> V_590 ) {
F_237 ( & V_601 -> V_592 , & V_602 -> V_593 ) ;
V_603 = true ;
break;
}
if ( F_232 ( V_9 , V_601 , V_602 ) )
V_603 = true ;
} else if ( F_247 ( & V_602 -> V_608 . V_615 ) ) {
unsigned long V_616 ;
F_237 ( & V_601 -> V_592 , & V_602 -> V_593 ) ;
V_603 = true ;
V_616 = V_359 + F_233 ( V_601 -> V_586 ) ;
if ( F_235 ( V_616 , V_602 -> V_608 . V_615 . V_617 ) )
F_248 ( & V_602 -> V_608 . V_615 , V_616 ) ;
else
F_249 ( & V_602 -> V_608 . V_615 ) ;
F_236 ( V_601 ) ;
}
break;
}
V_614:
if ( ! V_603 )
F_237 ( & V_601 -> V_592 , & V_9 -> V_595 ) ;
return 0 ;
}
static int F_250 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_597 * V_596 ,
unsigned int V_586 ,
T_4 * V_83 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_16 ( & V_9 -> V_151 ) ;
V_19 = F_241 ( V_9 , V_12 , V_596 ,
V_586 , V_83 , NULL ,
V_618 ) ;
F_18 ( & V_9 -> V_151 ) ;
return V_19 ;
}
static int F_251 ( struct V_8 * V_9 ,
T_4 V_83 , bool V_619 )
{
struct V_581 * V_601 , * V_602 , * V_620 = NULL ;
int V_19 ;
F_16 ( & V_9 -> V_151 ) ;
F_252 (roc, tmp, &local->roc_list, list) {
struct V_581 * V_621 , * V_622 ;
F_252 (dep, tmp2, &roc->dependents, list) {
if ( ! V_619 && V_621 -> V_83 != V_83 )
continue;
else if ( V_619 && V_621 -> V_607 != V_83 )
continue;
F_253 ( & V_621 -> V_592 ) ;
F_18 ( & V_9 -> V_151 ) ;
F_254 ( V_621 , true ) ;
return 0 ;
}
if ( ! V_619 && V_601 -> V_83 != V_83 )
continue;
else if ( V_619 && V_601 -> V_607 != V_83 )
continue;
V_620 = V_601 ;
break;
}
if ( ! V_620 ) {
F_18 ( & V_9 -> V_151 ) ;
return - V_59 ;
}
if ( V_9 -> V_481 -> V_604 ) {
if ( V_620 -> V_589 ) {
V_19 = F_255 ( V_9 ) ;
if ( F_34 ( V_19 ) ) {
F_18 ( & V_9 -> V_151 ) ;
return V_19 ;
}
}
F_253 ( & V_620 -> V_592 ) ;
if ( V_620 -> V_589 )
F_256 ( V_9 ) ;
F_18 ( & V_9 -> V_151 ) ;
F_254 ( V_620 , true ) ;
} else {
V_620 -> abort = true ;
F_245 ( & V_9 -> V_115 , & V_620 -> V_608 , 0 ) ;
F_18 ( & V_9 -> V_151 ) ;
F_257 ( & V_620 -> V_608 ) ;
F_234 ( ! V_620 -> V_623 ) ;
F_89 ( V_620 ) ;
}
return 0 ;
}
static int F_258 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_83 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_251 ( V_9 , V_83 , false ) ;
}
static int F_259 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_148 * V_149 ,
T_1 V_624 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_151 ) ;
if ( ! F_244 ( & V_9 -> V_595 ) || V_9 -> V_611 ) {
V_13 = - V_30 ;
goto V_60;
}
V_12 -> V_199 = V_201 ;
V_12 -> V_206 = V_9 -> V_207 ;
V_13 = F_69 ( V_12 , V_149 ,
V_208 ) ;
if ( V_13 )
goto V_60;
F_245 ( & V_12 -> V_9 -> V_115 ,
& V_12 -> V_239 ,
F_233 ( V_624 ) ) ;
V_60:
F_18 ( & V_9 -> V_151 ) ;
return V_13 ;
}
static struct V_175 *
F_260 ( struct V_175 * V_182 )
{
struct V_175 * V_625 ;
T_3 * V_626 ;
int V_169 ;
V_169 = V_182 -> V_184 + V_182 -> V_186 + V_182 -> V_627 +
V_182 -> V_628 + V_182 -> V_629 +
V_182 -> V_191 ;
V_625 = F_73 ( sizeof( * V_625 ) + V_169 , V_167 ) ;
if ( ! V_625 )
return NULL ;
V_626 = ( T_3 * ) ( V_625 + 1 ) ;
if ( V_182 -> V_184 ) {
V_625 -> V_184 = V_182 -> V_184 ;
V_625 -> V_183 = V_626 ;
memcpy ( V_626 , V_182 -> V_183 , V_182 -> V_184 ) ;
V_626 += V_182 -> V_184 ;
}
if ( V_182 -> V_186 ) {
V_625 -> V_186 = V_182 -> V_186 ;
V_625 -> V_185 = V_626 ;
memcpy ( V_626 , V_182 -> V_185 , V_182 -> V_186 ) ;
V_626 += V_182 -> V_186 ;
}
if ( V_182 -> V_627 ) {
V_625 -> V_627 = V_182 -> V_627 ;
V_625 -> V_630 = V_626 ;
memcpy ( V_626 , V_182 -> V_630 , V_182 -> V_627 ) ;
V_626 += V_182 -> V_627 ;
}
if ( V_182 -> V_628 ) {
V_625 -> V_628 = V_182 -> V_628 ;
V_625 -> V_631 = V_626 ;
memcpy ( V_626 , V_182 -> V_631 , V_182 -> V_628 ) ;
V_626 += V_182 -> V_628 ;
}
if ( V_182 -> V_629 ) {
V_625 -> V_629 = V_182 -> V_629 ;
V_625 -> V_632 = V_626 ;
memcpy ( V_626 , V_182 -> V_632 , V_182 -> V_629 ) ;
V_626 += V_182 -> V_629 ;
}
if ( V_182 -> V_191 ) {
V_625 -> V_191 = V_182 -> V_191 ;
V_182 -> V_163 = V_626 ;
memcpy ( V_626 , V_182 -> V_163 , V_182 -> V_191 ) ;
V_626 += V_182 -> V_191 ;
}
return V_625 ;
}
void F_261 ( struct V_541 * V_26 )
{
struct V_11 * V_12 = F_262 ( V_26 ) ;
F_222 ( & V_12 -> V_9 -> V_115 ,
& V_12 -> V_633 ) ;
}
static int F_263 ( struct V_11 * V_12 ,
T_1 * V_180 )
{
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_13 = F_76 ( V_12 , V_12 -> V_15 . V_166 . V_234 ,
NULL ) ;
F_89 ( V_12 -> V_15 . V_166 . V_234 ) ;
V_12 -> V_15 . V_166 . V_234 = NULL ;
if ( V_13 < 0 )
return V_13 ;
* V_180 |= V_13 ;
break;
case V_66 :
V_13 = F_264 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_180 |= V_13 ;
break;
#ifdef F_33
case V_67 :
V_13 = F_265 ( V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_180 |= V_13 ;
break;
#endif
default:
F_234 ( 1 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_266 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_1 V_180 = 0 ;
int V_13 ;
F_86 ( V_12 ) ;
F_225 ( & V_9 -> V_151 ) ;
F_225 ( & V_9 -> V_31 ) ;
if ( V_12 -> V_634 ) {
if ( V_12 -> V_635 )
return 0 ;
return F_267 ( V_12 ) ;
}
if ( ! F_65 ( & V_12 -> V_26 . V_214 . V_149 ,
& V_12 -> V_636 ) )
return - V_48 ;
V_12 -> V_26 . V_229 = false ;
V_13 = F_263 ( V_12 , & V_180 ) ;
if ( V_13 )
return V_13 ;
F_83 ( V_12 , V_180 ) ;
if ( V_12 -> V_232 ) {
F_88 ( V_9 , V_12 ,
V_233 ) ;
V_12 -> V_232 = false ;
}
V_13 = F_268 ( V_12 ) ;
if ( V_13 )
return V_13 ;
F_269 ( V_12 -> V_18 , & V_12 -> V_636 ) ;
return 0 ;
}
static void F_270 ( struct V_11 * V_12 )
{
if ( F_266 ( V_12 ) ) {
F_271 ( V_12 , L_6 ) ;
F_272 ( V_12 -> V_9 -> V_115 . V_2 , & V_12 -> V_10 ,
V_167 ) ;
}
}
void F_273 ( struct V_637 * V_608 )
{
struct V_11 * V_12 =
F_165 ( V_608 , struct V_11 ,
V_633 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
F_227 ( V_12 ) ;
F_16 ( & V_9 -> V_151 ) ;
F_16 ( & V_9 -> V_31 ) ;
if ( ! V_12 -> V_26 . V_229 )
goto V_638;
if ( ! F_12 ( V_12 ) )
goto V_638;
F_270 ( V_12 ) ;
V_638:
F_18 ( & V_9 -> V_31 ) ;
F_18 ( & V_9 -> V_151 ) ;
F_228 ( V_12 ) ;
}
static int F_274 ( struct V_11 * V_12 ,
struct V_639 * V_7 ,
T_1 * V_180 )
{
struct V_161 V_162 = {} ;
int V_13 ;
switch ( V_12 -> V_26 . type ) {
case V_64 :
V_12 -> V_15 . V_166 . V_234 =
F_260 ( & V_7 -> V_640 ) ;
if ( ! V_12 -> V_15 . V_166 . V_234 )
return - V_168 ;
if ( V_7 -> V_188 <= 1 )
break;
if ( ( V_7 -> V_190 >
V_641 ) ||
( V_7 -> V_173 >
V_641 ) )
return - V_48 ;
V_162 . V_189 = V_7 -> V_189 ;
V_162 . V_172 = V_7 -> V_172 ;
V_162 . V_190 = V_7 -> V_190 ;
V_162 . V_173 = V_7 -> V_173 ;
V_162 . V_188 = V_7 -> V_188 ;
V_13 = F_76 ( V_12 , & V_7 -> V_642 , & V_162 ) ;
if ( V_13 < 0 ) {
F_89 ( V_12 -> V_15 . V_166 . V_234 ) ;
return V_13 ;
}
* V_180 |= V_13 ;
break;
case V_66 :
if ( ! V_12 -> V_26 . V_214 . V_643 )
return - V_48 ;
if ( V_7 -> V_149 . V_549 != V_12 -> V_15 . V_644 . V_149 . V_549 )
return - V_48 ;
switch ( V_7 -> V_149 . V_549 ) {
case V_645 :
if ( F_275 ( & V_7 -> V_149 ) !=
F_275 ( & V_12 -> V_15 . V_644 . V_149 ) )
return - V_48 ;
case V_646 :
case V_647 :
case V_550 :
case V_648 :
break;
default:
return - V_48 ;
}
if ( V_12 -> V_15 . V_644 . V_149 . V_596 -> V_268 !=
V_7 -> V_149 . V_596 -> V_268 )
return - V_48 ;
if ( V_7 -> V_188 > 1 ) {
V_13 = F_276 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_180 |= V_13 ;
}
F_277 ( V_12 , V_7 ) ;
break;
#ifdef F_33
case V_67 : {
struct V_379 * V_380 = & V_12 -> V_15 . V_68 ;
if ( V_7 -> V_149 . V_549 != V_12 -> V_26 . V_214 . V_149 . V_549 )
return - V_48 ;
if ( V_12 -> V_26 . V_214 . V_149 . V_596 -> V_268 !=
V_7 -> V_149 . V_596 -> V_268 )
return - V_48 ;
if ( V_380 -> V_649 == V_650 ) {
V_380 -> V_649 = V_651 ;
if ( ! V_380 -> V_652 )
V_380 -> V_652 = 1 ;
else
V_380 -> V_652 ++ ;
}
if ( V_7 -> V_188 > 1 ) {
V_13 = F_278 ( V_12 , V_7 ) ;
if ( V_13 < 0 ) {
V_380 -> V_649 = V_650 ;
return V_13 ;
}
* V_180 |= V_13 ;
}
if ( V_380 -> V_649 == V_651 )
F_277 ( V_12 , V_7 ) ;
break;
}
#endif
default:
return - V_328 ;
}
return 0 ;
}
static int
F_279 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_639 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_653 V_654 ;
struct V_655 * V_55 ;
struct V_656 * V_657 ;
T_1 V_180 = 0 ;
int V_13 ;
F_86 ( V_12 ) ;
F_225 ( & V_9 -> V_151 ) ;
if ( ! F_244 ( & V_9 -> V_595 ) || V_9 -> V_611 )
return - V_30 ;
if ( V_12 -> V_10 . V_238 )
return - V_30 ;
if ( F_65 ( & V_7 -> V_149 ,
& V_12 -> V_26 . V_214 . V_149 ) )
return - V_48 ;
if ( V_12 -> V_26 . V_229 )
return - V_30 ;
F_16 ( & V_9 -> V_31 ) ;
V_55 = F_66 ( V_12 -> V_26 . V_658 ,
F_67 ( & V_9 -> V_31 ) ) ;
if ( ! V_55 ) {
V_13 = - V_30 ;
goto V_87;
}
V_657 = F_165 ( V_55 , struct V_656 , V_55 ) ;
if ( ! V_657 ) {
V_13 = - V_30 ;
goto V_87;
}
V_654 . V_659 = 0 ;
V_654 . V_660 = 0 ;
V_654 . V_661 = V_7 -> V_661 ;
V_654 . V_149 = V_7 -> V_149 ;
V_654 . V_188 = V_7 -> V_188 ;
V_13 = F_280 ( V_12 , & V_654 ) ;
if ( V_13 )
goto V_87;
V_13 = F_281 ( V_12 , & V_7 -> V_149 ,
V_657 -> V_662 ,
V_7 -> V_663 ) ;
if ( V_13 )
goto V_87;
V_13 = F_17 ( V_12 , NULL , V_657 -> V_662 , 0 ) ;
if ( V_13 ) {
F_282 ( V_12 ) ;
goto V_87;
}
V_13 = F_274 ( V_12 , V_7 , & V_180 ) ;
if ( V_13 ) {
F_282 ( V_12 ) ;
goto V_87;
}
V_12 -> V_636 = V_7 -> V_149 ;
V_12 -> V_232 = V_7 -> V_661 ;
V_12 -> V_26 . V_229 = true ;
if ( V_12 -> V_232 )
F_283 ( V_9 , V_12 ,
V_233 ) ;
F_284 ( V_12 -> V_18 , & V_12 -> V_636 ,
V_7 -> V_188 ) ;
if ( V_180 ) {
F_83 ( V_12 , V_180 ) ;
F_285 ( V_12 , & V_7 -> V_149 ) ;
} else {
F_270 ( V_12 ) ;
}
V_87:
F_18 ( & V_9 -> V_31 ) ;
return V_13 ;
}
int V_653 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_639 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 ;
F_16 ( & V_9 -> V_151 ) ;
V_13 = F_279 ( V_2 , V_18 , V_7 ) ;
F_18 ( & V_9 -> V_151 ) ;
return V_13 ;
}
static int F_286 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_664 * V_7 ,
T_4 * V_83 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_246 * V_247 ;
struct V_37 * V_23 ;
const struct V_665 * V_666 = ( void * ) V_7 -> V_667 ;
bool V_668 = false ;
T_1 V_5 ;
int V_19 ;
T_3 * V_170 ;
if ( V_7 -> V_669 )
V_5 = V_670 ;
else
V_5 = V_671 |
V_672 ;
if ( V_7 -> V_673 )
V_5 |= V_674 ;
switch ( V_12 -> V_26 . type ) {
case V_66 :
if ( ! V_12 -> V_26 . V_214 . V_643 )
V_668 = true ;
#ifdef F_33
case V_67 :
if ( F_28 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_68 . V_387 )
V_668 = true ;
#endif
case V_64 :
case V_20 :
case V_76 :
if ( V_12 -> V_26 . type != V_66 &&
! F_28 ( & V_12 -> V_26 ) &&
! F_287 ( V_12 -> V_332 -> V_182 ) )
V_668 = true ;
if ( ! F_288 ( V_666 -> V_675 ) ||
V_666 -> V_15 . V_676 . V_677 == V_678 ||
V_666 -> V_15 . V_676 . V_677 == V_679 ||
V_666 -> V_15 . V_676 . V_677 == V_680 )
break;
F_41 () ;
V_23 = F_29 ( V_12 , V_666 -> V_248 ) ;
F_45 () ;
if ( ! V_23 )
return - V_681 ;
break;
case V_24 :
case V_75 :
if ( ! V_12 -> V_15 . V_25 . V_557 )
V_668 = true ;
break;
case V_72 :
V_668 = true ;
break;
default:
return - V_328 ;
}
if ( V_668 && ! V_7 -> V_596 )
return - V_48 ;
F_16 ( & V_9 -> V_151 ) ;
if ( ! V_668 ) {
struct V_655 * V_658 ;
F_41 () ;
V_658 = F_42 ( V_12 -> V_26 . V_658 ) ;
if ( V_658 ) {
V_668 = V_7 -> V_596 &&
( V_7 -> V_596 !=
V_658 -> V_682 . V_596 ) ;
} else if ( ! V_7 -> V_596 ) {
V_19 = - V_48 ;
F_45 () ;
goto V_60;
} else {
V_668 = true ;
}
F_45 () ;
}
if ( V_668 && ! V_7 -> V_683 ) {
V_19 = - V_30 ;
goto V_60;
}
V_247 = F_100 ( V_9 -> V_115 . V_684 + V_7 -> V_169 ) ;
if ( ! V_247 ) {
V_19 = - V_168 ;
goto V_60;
}
F_289 ( V_247 , V_9 -> V_115 . V_684 ) ;
V_170 = F_101 ( V_247 , V_7 -> V_169 ) ;
memcpy ( V_170 , V_7 -> V_667 , V_7 -> V_169 ) ;
if ( V_12 -> V_26 . V_229 &&
( V_12 -> V_26 . type == V_64 ||
V_12 -> V_26 . type == V_66 ) &&
V_7 -> V_685 ) {
int V_548 ;
struct V_176 * V_182 = NULL ;
F_41 () ;
if ( V_12 -> V_26 . type == V_64 )
V_182 = F_42 ( V_12 -> V_15 . V_166 . V_182 ) ;
else if ( V_12 -> V_26 . type == V_66 )
V_182 = F_42 ( V_12 -> V_15 . V_644 . V_686 ) ;
else if ( F_28 ( & V_12 -> V_26 ) )
V_182 = F_42 ( V_12 -> V_15 . V_68 . V_182 ) ;
if ( V_182 )
for ( V_548 = 0 ; V_548 < V_7 -> V_685 ; V_548 ++ )
V_170 [ V_7 -> V_687 [ V_548 ] ] =
V_182 -> V_187 ;
F_45 () ;
}
F_290 ( V_247 ) -> V_5 = V_5 ;
V_247 -> V_18 = V_12 -> V_18 ;
if ( ! V_668 ) {
* V_83 = ( unsigned long ) V_247 ;
F_291 ( V_12 , V_247 ) ;
V_19 = 0 ;
goto V_60;
}
F_290 ( V_247 ) -> V_5 |= V_688 |
V_689 ;
if ( V_9 -> V_115 . V_5 & V_690 )
F_290 ( V_247 ) -> V_691 =
V_9 -> V_115 . V_692 ;
V_19 = F_241 ( V_9 , V_12 , V_7 -> V_596 ,
V_7 -> V_693 , V_83 , V_247 ,
V_694 ) ;
if ( V_19 )
F_292 ( V_247 ) ;
V_60:
F_18 ( & V_9 -> V_151 ) ;
return V_19 ;
}
static int F_293 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_83 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_251 ( V_9 , V_83 , true ) ;
}
static void F_294 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_695 , bool V_696 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_695 ) {
case V_697 | V_698 :
if ( V_696 )
V_9 -> V_699 ++ ;
else
V_9 -> V_699 -- ;
if ( ! V_9 -> V_156 )
break;
F_222 ( & V_9 -> V_115 , & V_9 -> V_700 ) ;
break;
default:
break;
}
}
static int F_295 ( struct V_2 * V_2 , T_1 V_701 , T_1 V_702 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_589 )
return - V_328 ;
return F_296 ( V_9 , V_701 , V_702 ) ;
}
static int F_297 ( struct V_2 * V_2 , T_1 * V_701 , T_1 * V_702 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_298 ( V_9 , V_701 , V_702 ) ;
}
static int F_299 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_703 * V_170 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_481 -> V_704 )
return - V_328 ;
F_300 ( V_9 , V_12 , V_170 ) ;
return 0 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_705 , T_4 * V_83 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_706 * V_707 ;
struct V_246 * V_247 ;
int V_179 = sizeof( * V_707 ) ;
T_8 V_708 ;
bool V_709 ;
struct V_710 * V_711 ;
struct V_37 * V_23 ;
struct V_655 * V_658 ;
enum V_267 V_268 ;
F_41 () ;
V_658 = F_42 ( V_12 -> V_26 . V_658 ) ;
if ( F_234 ( ! V_658 ) ) {
F_45 () ;
return - V_48 ;
}
V_268 = V_658 -> V_682 . V_596 -> V_268 ;
V_23 = F_30 ( V_12 , V_705 ) ;
if ( V_23 ) {
V_709 = V_23 -> V_23 . V_275 ;
} else {
F_45 () ;
return - V_681 ;
}
if ( V_709 ) {
V_708 = F_302 ( V_712 |
V_713 |
V_714 ) ;
} else {
V_179 -= 2 ;
V_708 = F_302 ( V_712 |
V_715 |
V_714 ) ;
}
V_247 = F_100 ( V_9 -> V_115 . V_684 + V_179 ) ;
if ( ! V_247 ) {
F_45 () ;
return - V_168 ;
}
V_247 -> V_18 = V_18 ;
F_289 ( V_247 , V_9 -> V_115 . V_684 ) ;
V_707 = ( void * ) F_101 ( V_247 , V_179 ) ;
V_707 -> V_675 = V_708 ;
V_707 -> V_716 = 0 ;
memcpy ( V_707 -> V_717 , V_23 -> V_23 . V_143 , V_144 ) ;
memcpy ( V_707 -> V_718 , V_12 -> V_26 . V_143 , V_144 ) ;
memcpy ( V_707 -> V_719 , V_12 -> V_26 . V_143 , V_144 ) ;
V_707 -> V_720 = 0 ;
V_711 = F_290 ( V_247 ) ;
V_711 -> V_5 |= V_672 |
V_671 ;
V_711 -> V_268 = V_268 ;
F_303 ( V_247 , V_721 ) ;
V_247 -> V_722 = 7 ;
if ( V_709 )
V_707 -> V_723 = F_302 ( 7 ) ;
F_304 () ;
F_305 ( V_12 , V_247 ) ;
F_306 () ;
F_45 () ;
* V_83 = ( unsigned long ) V_247 ;
return 0 ;
}
static int F_307 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_148 * V_149 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_655 * V_658 ;
int V_19 = - V_724 ;
F_41 () ;
V_658 = F_42 ( V_12 -> V_26 . V_658 ) ;
if ( V_658 ) {
* V_149 = V_12 -> V_26 . V_214 . V_149 ;
V_19 = 0 ;
} else if ( V_9 -> V_156 > 0 &&
V_9 -> V_156 == V_9 -> V_157 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_153 )
* V_149 = V_9 -> V_150 ;
else
* V_149 = V_9 -> V_158 ;
V_19 = 0 ;
}
F_45 () ;
return V_19 ;
}
static void F_308 ( struct V_2 * V_2 , bool V_559 )
{
F_309 ( F_2 ( V_2 ) , V_559 ) ;
}
static int F_310 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_725 * V_726 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_727 * V_728 , * V_729 ;
if ( V_726 ) {
V_728 = F_73 ( sizeof( * V_728 ) , V_167 ) ;
if ( ! V_728 )
return - V_168 ;
memcpy ( & V_728 -> V_726 , V_726 , sizeof( * V_726 ) ) ;
} else {
V_728 = NULL ;
}
V_729 = F_72 ( V_12 -> V_726 , V_12 ) ;
F_74 ( V_12 -> V_726 , V_728 ) ;
if ( V_729 )
F_75 ( V_729 , V_174 ) ;
return 0 ;
}
static int F_311 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_148 * V_149 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_19 ;
T_1 V_180 = 0 ;
V_19 = F_312 ( V_12 , V_149 , & V_180 ) ;
if ( V_19 == 0 )
F_83 ( V_12 , V_180 ) ;
return V_19 ;
}
static int F_313 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_730 , const T_3 * V_705 , T_3 V_731 ,
T_2 V_732 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_733 * V_734 = & V_12 -> V_15 . V_25 ;
int V_493 = V_735 [ V_731 ] ;
if ( V_12 -> V_26 . type != V_24 )
return - V_328 ;
if ( ! ( V_12 -> V_736 & F_107 ( V_731 ) ) )
return - V_48 ;
if ( V_734 -> V_737 [ V_493 ] . V_732 )
return - V_30 ;
if ( V_732 ) {
V_734 -> V_737 [ V_493 ] . V_732 = 32 * V_732 ;
V_734 -> V_737 [ V_493 ] . V_730 = V_730 ;
V_734 -> V_737 [ V_493 ] . V_731 = V_731 ;
}
return 0 ;
}
static int F_314 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_730 , const T_3 * V_705 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_733 * V_734 = & V_12 -> V_15 . V_25 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_493 ;
for ( V_493 = 0 ; V_493 < V_484 ; V_493 ++ ) {
struct V_738 * V_737 = & V_734 -> V_737 [ V_493 ] ;
if ( ! V_737 -> V_732 )
continue;
if ( V_737 -> V_730 != V_730 )
continue;
V_737 -> V_731 = - 1 ;
F_315 () ;
F_316 ( V_9 , V_12 ) ;
V_737 -> V_676 = V_739 ;
V_737 -> V_740 = false ;
F_317 ( V_12 ) ;
memset ( V_737 , 0 , sizeof( * V_737 ) ) ;
return 0 ;
}
return - V_59 ;
}
