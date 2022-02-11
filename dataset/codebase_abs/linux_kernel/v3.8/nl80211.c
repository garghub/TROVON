static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_8 = NULL ;
bool V_9 = V_5 [ V_10 ] ;
bool V_11 = V_5 [ V_12 ] ;
T_1 V_13 ;
int V_14 = - 1 ;
int V_15 = - 1 ;
F_2 () ;
if ( ! V_9 && ! V_11 )
return F_3 ( - V_16 ) ;
if ( V_9 )
V_15 = F_4 ( V_5 [ V_10 ] ) ;
if ( V_11 ) {
V_13 = F_5 ( V_5 [ V_12 ] ) ;
V_14 = V_13 >> 32 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
struct V_1 * V_17 ;
if ( F_7 ( & V_7 -> V_18 ) != V_3 )
continue;
if ( V_11 && V_7 -> V_14 != V_14 )
continue;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_9 && V_17 -> V_20 &&
V_17 -> V_20 -> V_21 == V_15 ) {
V_8 = V_17 ;
break;
}
if ( V_11 && V_17 -> V_22 == ( V_23 ) V_13 ) {
V_8 = V_17 ;
break;
}
}
F_9 ( & V_7 -> V_19 ) ;
if ( V_8 )
break;
}
if ( V_8 )
return V_8 ;
return F_3 ( - V_24 ) ;
}
static struct V_6 *
F_10 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = NULL , * V_25 ;
struct V_26 * V_20 ;
F_2 () ;
if ( ! V_5 [ V_27 ] &&
! V_5 [ V_10 ] &&
! V_5 [ V_12 ] )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_27 ] )
V_7 = F_11 (
F_4 ( V_5 [ V_27 ] ) ) ;
if ( V_5 [ V_12 ] ) {
T_1 V_13 = F_5 ( V_5 [ V_12 ] ) ;
struct V_1 * V_17 ;
bool V_28 = false ;
V_25 = F_11 ( V_13 >> 32 ) ;
if ( V_25 ) {
F_8 ( & V_25 -> V_19 ) ;
F_6 (wdev, &tmp->wdev_list, list) {
if ( V_17 -> V_22 != ( V_23 ) V_13 )
continue;
V_28 = true ;
break;
}
F_9 ( & V_25 -> V_19 ) ;
if ( ! V_28 )
V_25 = NULL ;
if ( V_7 && V_25 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_25 ;
}
}
if ( V_5 [ V_10 ] ) {
int V_21 = F_4 ( V_5 [ V_10 ] ) ;
V_20 = F_12 ( V_3 , V_21 ) ;
if ( V_20 ) {
if ( V_20 -> V_29 )
V_25 = F_13 (
V_20 -> V_29 -> V_18 ) ;
else
V_25 = NULL ;
F_14 ( V_20 ) ;
if ( ! V_25 )
return F_3 ( - V_16 ) ;
if ( V_7 && V_25 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_25 ;
}
}
if ( ! V_7 )
return F_3 ( - V_24 ) ;
if ( V_3 != F_7 ( & V_7 -> V_18 ) )
return F_3 ( - V_24 ) ;
return V_7 ;
}
static struct V_6 *
F_15 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
struct V_6 * V_7 ;
F_8 ( & V_32 ) ;
V_7 = F_10 ( V_3 , V_31 -> V_5 ) ;
if ( ! F_16 ( V_7 ) )
F_8 ( & V_7 -> V_33 ) ;
F_9 ( & V_32 ) ;
return V_7 ;
}
static int F_17 ( struct V_34 * V_35 )
{
int V_36 ;
V_36 = F_18 ( V_35 -> V_37 , V_38 + V_39 . V_40 ,
V_39 . V_41 , V_39 . V_42 ,
V_43 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_39 . V_41 [ V_10 ] )
return - V_16 ;
V_36 = F_4 ( V_39 . V_41 [ V_10 ] ) ;
if ( ! V_36 )
return - V_16 ;
return V_36 ;
}
static int F_19 ( struct V_44 * V_45 ,
struct V_34 * V_35 ,
struct V_6 * * V_7 ,
struct V_26 * * V_46 )
{
int V_15 = V_35 -> args [ 0 ] ;
int V_47 ;
if ( ! V_15 )
V_15 = F_17 ( V_35 ) ;
if ( V_15 < 0 )
return V_15 ;
V_35 -> args [ 0 ] = V_15 ;
F_20 () ;
* V_46 = F_21 ( F_22 ( V_45 -> V_48 ) , V_15 ) ;
if ( ! * V_46 ) {
V_47 = - V_24 ;
goto V_49;
}
* V_7 = F_23 ( F_22 ( V_45 -> V_48 ) , V_15 ) ;
if ( F_16 ( * V_7 ) ) {
V_47 = F_24 ( * V_7 ) ;
goto V_49;
}
return 0 ;
V_49:
F_25 () ;
return V_47 ;
}
static void F_26 ( struct V_6 * V_7 )
{
F_27 ( V_7 ) ;
F_25 () ;
}
static bool F_28 ( const struct V_4 * V_50 )
{
const T_2 * V_51 ;
int V_52 ;
if ( ! V_50 )
return true ;
V_51 = F_29 ( V_50 ) ;
V_52 = F_30 ( V_50 ) ;
while ( V_52 ) {
T_2 V_53 ;
if ( V_52 < 2 )
return false ;
V_52 -= 2 ;
V_53 = V_51 [ 1 ] ;
if ( V_53 > V_52 )
return false ;
V_52 -= V_53 ;
V_51 += 2 + V_53 ;
}
return true ;
}
static inline void * F_31 ( struct V_44 * V_45 , V_23 V_54 , V_23 V_55 ,
int V_56 , T_2 V_57 )
{
return F_32 ( V_45 , V_54 , V_55 , & V_39 , V_56 , V_57 ) ;
}
static int F_33 ( struct V_44 * V_58 ,
struct V_59 * V_60 )
{
if ( F_34 ( V_58 , V_61 ,
V_60 -> V_62 ) )
goto V_63;
if ( ( V_60 -> V_56 & V_64 ) &&
F_35 ( V_58 , V_65 ) )
goto V_63;
if ( ( V_60 -> V_56 & V_66 ) &&
F_35 ( V_58 , V_67 ) )
goto V_63;
if ( ( V_60 -> V_56 & V_68 ) &&
F_35 ( V_58 , V_69 ) )
goto V_63;
if ( ( V_60 -> V_56 & V_70 ) &&
F_35 ( V_58 , V_71 ) )
goto V_63;
if ( F_34 ( V_58 , V_72 ,
F_36 ( V_60 -> V_73 ) ) )
goto V_63;
return 0 ;
V_63:
return - V_74 ;
}
static int F_37 ( struct V_4 * V_75 , struct V_76 * V_77 )
{
struct V_4 * V_78 [ V_79 + 1 ] ;
int V_47 = F_38 ( V_78 , V_79 , V_75 ,
V_80 ) ;
if ( V_47 )
return V_47 ;
V_77 -> V_81 = ! ! V_78 [ V_82 ] ;
V_77 -> V_83 = ! ! V_78 [ V_84 ] ;
if ( V_77 -> V_81 ) {
V_77 -> V_85 = true ;
V_77 -> V_86 = true ;
}
if ( V_77 -> V_83 )
V_77 -> V_86 = true ;
if ( V_78 [ V_87 ] )
V_77 -> V_88 = F_39 ( V_78 [ V_87 ] ) ;
if ( V_78 [ V_89 ] ) {
V_77 -> V_90 . V_75 = F_29 ( V_78 [ V_89 ] ) ;
V_77 -> V_90 . V_91 = F_30 ( V_78 [ V_89 ] ) ;
}
if ( V_78 [ V_92 ] ) {
V_77 -> V_90 . V_55 = F_29 ( V_78 [ V_92 ] ) ;
V_77 -> V_90 . V_93 = F_30 ( V_78 [ V_92 ] ) ;
}
if ( V_78 [ V_94 ] )
V_77 -> V_90 . V_95 = F_4 ( V_78 [ V_94 ] ) ;
if ( V_78 [ V_96 ] ) {
V_77 -> type = F_4 ( V_78 [ V_96 ] ) ;
if ( V_77 -> type < 0 || V_77 -> type >= V_97 )
return - V_16 ;
}
if ( V_78 [ V_98 ] ) {
struct V_4 * V_99 [ V_100 ] ;
V_47 = F_38 ( V_99 , V_100 - 1 ,
V_78 [ V_98 ] ,
V_101 ) ;
if ( V_47 )
return V_47 ;
V_77 -> V_85 = V_99 [ V_102 ] ;
V_77 -> V_86 = V_99 [ V_103 ] ;
}
return 0 ;
}
static int F_40 ( struct V_30 * V_31 , struct V_76 * V_77 )
{
if ( V_31 -> V_5 [ V_104 ] ) {
V_77 -> V_90 . V_75 = F_29 ( V_31 -> V_5 [ V_104 ] ) ;
V_77 -> V_90 . V_91 = F_30 ( V_31 -> V_5 [ V_104 ] ) ;
}
if ( V_31 -> V_5 [ V_105 ] ) {
V_77 -> V_90 . V_55 = F_29 ( V_31 -> V_5 [ V_105 ] ) ;
V_77 -> V_90 . V_93 = F_30 ( V_31 -> V_5 [ V_105 ] ) ;
}
if ( V_31 -> V_5 [ V_106 ] )
V_77 -> V_88 = F_39 ( V_31 -> V_5 [ V_106 ] ) ;
if ( V_31 -> V_5 [ V_107 ] )
V_77 -> V_90 . V_95 = F_4 ( V_31 -> V_5 [ V_107 ] ) ;
V_77 -> V_81 = ! ! V_31 -> V_5 [ V_108 ] ;
V_77 -> V_83 = ! ! V_31 -> V_5 [ V_109 ] ;
if ( V_77 -> V_81 ) {
V_77 -> V_85 = true ;
V_77 -> V_86 = true ;
}
if ( V_77 -> V_83 )
V_77 -> V_86 = true ;
if ( V_31 -> V_5 [ V_110 ] ) {
V_77 -> type = F_4 ( V_31 -> V_5 [ V_110 ] ) ;
if ( V_77 -> type < 0 || V_77 -> type >= V_97 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_111 ] ) {
struct V_4 * V_99 [ V_100 ] ;
int V_47 = F_38 (
V_99 , V_100 - 1 ,
V_31 -> V_5 [ V_111 ] ,
V_101 ) ;
if ( V_47 )
return V_47 ;
V_77 -> V_85 = V_99 [ V_102 ] ;
V_77 -> V_86 = V_99 [ V_103 ] ;
}
return 0 ;
}
static int F_41 ( struct V_30 * V_31 , struct V_76 * V_77 )
{
int V_47 ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_77 -> V_88 = - 1 ;
V_77 -> type = - 1 ;
if ( V_31 -> V_5 [ V_112 ] )
V_47 = F_37 ( V_31 -> V_5 [ V_112 ] , V_77 ) ;
else
V_47 = F_40 ( V_31 , V_77 ) ;
if ( V_47 )
return V_47 ;
if ( V_77 -> V_81 && V_77 -> V_83 )
return - V_16 ;
if ( V_77 -> V_83 ) {
if ( V_77 -> V_85 || ! V_77 -> V_86 )
return - V_16 ;
}
if ( V_77 -> V_88 != - 1 ) {
if ( V_77 -> V_83 ) {
if ( V_77 -> V_88 < 4 || V_77 -> V_88 > 5 )
return - V_16 ;
} else if ( V_77 -> V_81 ) {
if ( V_77 -> V_88 < 0 || V_77 -> V_88 > 3 )
return - V_16 ;
} else {
if ( V_77 -> V_88 < 0 || V_77 -> V_88 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_113 *
F_42 ( struct V_6 * V_7 ,
struct V_4 * V_114 , bool * V_115 )
{
struct V_76 V_116 ;
struct V_4 * V_75 ;
struct V_113 * V_8 ;
int V_117 , V_47 , V_81 = 0 ;
V_8 = F_43 ( sizeof( * V_8 ) , V_118 ) ;
if ( ! V_8 )
return F_3 ( - V_119 ) ;
V_8 -> V_81 = - 1 ;
V_8 -> V_83 = - 1 ;
F_44 (key, keys, rem) {
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_88 = - 1 ;
V_47 = F_37 ( V_75 , & V_116 ) ;
if ( V_47 )
goto error;
V_47 = - V_16 ;
if ( ! V_116 . V_90 . V_75 )
goto error;
if ( V_116 . V_88 < 0 || V_116 . V_88 > 4 )
goto error;
if ( V_116 . V_81 ) {
if ( V_81 )
goto error;
V_81 = 1 ;
V_8 -> V_81 = V_116 . V_88 ;
if ( ! V_116 . V_85 || ! V_116 . V_86 )
goto error;
} else if ( V_116 . V_83 )
goto error;
V_47 = F_45 ( V_7 , & V_116 . V_90 ,
V_116 . V_88 , false , NULL ) ;
if ( V_47 )
goto error;
V_8 -> V_120 [ V_116 . V_88 ] . V_95 = V_116 . V_90 . V_95 ;
V_8 -> V_120 [ V_116 . V_88 ] . V_91 = V_116 . V_90 . V_91 ;
V_8 -> V_120 [ V_116 . V_88 ] . V_75 = V_8 -> V_121 [ V_116 . V_88 ] ;
memcpy ( V_8 -> V_121 [ V_116 . V_88 ] , V_116 . V_90 . V_75 , V_116 . V_90 . V_91 ) ;
if ( V_116 . V_90 . V_95 == V_122 ||
V_116 . V_90 . V_95 == V_123 ) {
if ( V_115 )
* V_115 = true ;
}
}
return V_8 ;
error:
F_46 ( V_8 ) ;
return F_3 ( V_47 ) ;
}
static int F_47 ( struct V_1 * V_17 )
{
F_48 ( V_17 ) ;
switch ( V_17 -> V_124 ) {
case V_125 :
case V_126 :
case V_127 :
case V_128 :
break;
case V_129 :
if ( ! V_17 -> V_130 )
return - V_131 ;
break;
case V_132 :
case V_133 :
if ( V_17 -> V_134 != V_135 )
return - V_131 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_49 ( struct V_44 * V_58 , V_23 V_50 , T_3 V_136 )
{
struct V_4 * V_137 = F_50 ( V_58 , V_50 ) ;
int V_138 ;
if ( ! V_137 )
goto V_63;
V_138 = 0 ;
while ( V_136 ) {
if ( ( V_136 & 1 ) && F_35 ( V_58 , V_138 ) )
goto V_63;
V_136 >>= 1 ;
V_138 ++ ;
}
F_51 ( V_58 , V_137 ) ;
return 0 ;
V_63:
return - V_74 ;
}
static int F_52 ( struct V_18 * V_18 ,
struct V_44 * V_58 )
{
struct V_4 * V_139 ;
int V_138 , V_140 ;
V_139 = F_50 ( V_58 ,
V_141 ) ;
if ( ! V_139 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_18 -> V_142 ; V_138 ++ ) {
const struct V_143 * V_144 ;
struct V_4 * V_145 , * V_146 ;
V_144 = & V_18 -> V_147 [ V_138 ] ;
V_145 = F_50 ( V_58 , V_138 + 1 ) ;
if ( ! V_145 )
goto V_63;
V_146 = F_50 ( V_58 , V_148 ) ;
if ( ! V_146 )
goto V_63;
for ( V_140 = 0 ; V_140 < V_144 -> V_149 ; V_140 ++ ) {
struct V_4 * V_150 ;
V_150 = F_50 ( V_58 , V_140 + 1 ) ;
if ( ! V_150 )
goto V_63;
if ( F_34 ( V_58 , V_151 ,
V_144 -> V_152 [ V_140 ] . V_153 ) )
goto V_63;
if ( F_49 ( V_58 , V_154 ,
V_144 -> V_152 [ V_140 ] . V_155 ) )
goto V_63;
F_51 ( V_58 , V_150 ) ;
}
F_51 ( V_58 , V_146 ) ;
if ( V_144 -> V_156 &&
F_35 ( V_58 , V_157 ) )
goto V_63;
if ( F_34 ( V_58 , V_158 ,
V_144 -> V_159 ) ||
F_34 ( V_58 , V_160 ,
V_144 -> V_161 ) )
goto V_63;
F_51 ( V_58 , V_145 ) ;
}
F_51 ( V_58 , V_139 ) ;
return 0 ;
V_63:
return - V_74 ;
}
static int F_53 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 , int V_56 ,
struct V_6 * V_46 )
{
void * V_162 ;
struct V_4 * V_163 , * V_164 ;
struct V_4 * V_165 , * V_166 ;
struct V_4 * V_167 , * V_168 ;
struct V_4 * V_169 ;
enum V_170 V_171 ;
struct V_59 * V_60 ;
struct V_172 * V_173 ;
int V_138 ;
const struct V_174 * V_175 =
V_46 -> V_18 . V_175 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_176 ) ;
if ( ! V_162 )
return - 1 ;
if ( F_34 ( V_58 , V_27 , V_46 -> V_14 ) ||
F_54 ( V_58 , V_177 , F_55 ( & V_46 -> V_18 ) ) ||
F_34 ( V_58 , V_178 ,
V_179 ) ||
F_56 ( V_58 , V_180 ,
V_46 -> V_18 . V_181 ) ||
F_56 ( V_58 , V_182 ,
V_46 -> V_18 . V_183 ) ||
F_34 ( V_58 , V_184 ,
V_46 -> V_18 . V_185 ) ||
F_34 ( V_58 , V_186 ,
V_46 -> V_18 . V_187 ) ||
F_56 ( V_58 , V_188 ,
V_46 -> V_18 . V_189 ) ||
F_56 ( V_58 , V_190 ,
V_46 -> V_18 . V_191 ) ||
F_56 ( V_58 , V_192 ,
V_46 -> V_18 . V_193 ) ||
F_57 ( V_58 , V_194 ,
V_46 -> V_18 . V_195 ) ||
F_57 ( V_58 , V_196 ,
V_46 -> V_18 . V_197 ) ||
F_56 ( V_58 , V_198 ,
V_46 -> V_18 . V_199 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_200 ) &&
F_35 ( V_58 , V_201 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_202 ) &&
F_35 ( V_58 , V_203 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_204 ) &&
F_35 ( V_58 , V_205 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_206 ) &&
F_35 ( V_58 , V_207 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_208 ) &&
F_35 ( V_58 , V_209 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_210 ) &&
F_35 ( V_58 , V_211 ) )
goto V_63;
if ( F_58 ( V_58 , V_212 ,
sizeof( V_23 ) * V_46 -> V_18 . V_213 ,
V_46 -> V_18 . V_214 ) )
goto V_63;
if ( F_56 ( V_58 , V_215 ,
V_46 -> V_18 . V_216 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_217 ) &&
F_35 ( V_58 , V_218 ) )
goto V_63;
if ( F_34 ( V_58 , V_219 ,
V_46 -> V_18 . V_220 ) ||
F_34 ( V_58 , V_221 ,
V_46 -> V_18 . V_222 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_223 ) &&
F_34 ( V_58 , V_224 ,
V_46 -> V_18 . V_225 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_220 ||
V_46 -> V_18 . V_222 ) && V_46 -> V_226 -> V_227 ) {
V_23 V_228 = 0 , V_229 = 0 ;
int V_36 ;
V_36 = F_59 ( V_46 , & V_228 , & V_229 ) ;
if ( ! V_36 ) {
if ( F_34 ( V_58 , V_230 ,
V_228 ) ||
F_34 ( V_58 , V_231 ,
V_229 ) )
goto V_63;
}
}
if ( F_49 ( V_58 , V_232 ,
V_46 -> V_18 . V_233 ) )
goto V_63;
V_163 = F_50 ( V_58 , V_234 ) ;
if ( ! V_163 )
goto V_63;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ ) {
if ( ! V_46 -> V_18 . V_236 [ V_171 ] )
continue;
V_164 = F_50 ( V_58 , V_171 ) ;
if ( ! V_164 )
goto V_63;
if ( V_46 -> V_18 . V_236 [ V_171 ] -> V_237 . V_238 &&
( F_58 ( V_58 , V_239 ,
sizeof( V_46 -> V_18 . V_236 [ V_171 ] -> V_237 . V_240 ) ,
& V_46 -> V_18 . V_236 [ V_171 ] -> V_237 . V_240 ) ||
F_57 ( V_58 , V_241 ,
V_46 -> V_18 . V_236 [ V_171 ] -> V_237 . V_242 ) ||
F_56 ( V_58 , V_243 ,
V_46 -> V_18 . V_236 [ V_171 ] -> V_237 . V_244 ) ||
F_56 ( V_58 , V_245 ,
V_46 -> V_18 . V_236 [ V_171 ] -> V_237 . V_246 ) ) )
goto V_63;
if ( V_46 -> V_18 . V_236 [ V_171 ] -> V_247 . V_248 &&
( F_58 ( V_58 , V_249 ,
sizeof( V_46 -> V_18 . V_236 [ V_171 ] -> V_247 . V_250 ) ,
& V_46 -> V_18 . V_236 [ V_171 ] -> V_247 . V_250 ) ||
F_34 ( V_58 , V_251 ,
V_46 -> V_18 . V_236 [ V_171 ] -> V_247 . V_242 ) ) )
goto V_63;
V_165 = F_50 ( V_58 , V_252 ) ;
if ( ! V_165 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_46 -> V_18 . V_236 [ V_171 ] -> V_253 ; V_138 ++ ) {
V_166 = F_50 ( V_58 , V_138 ) ;
if ( ! V_166 )
goto V_63;
V_60 = & V_46 -> V_18 . V_236 [ V_171 ] -> V_254 [ V_138 ] ;
if ( F_33 ( V_58 , V_60 ) )
goto V_63;
F_51 ( V_58 , V_166 ) ;
}
F_51 ( V_58 , V_165 ) ;
V_167 = F_50 ( V_58 , V_255 ) ;
if ( ! V_167 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_46 -> V_18 . V_236 [ V_171 ] -> V_256 ; V_138 ++ ) {
V_168 = F_50 ( V_58 , V_138 ) ;
if ( ! V_168 )
goto V_63;
V_173 = & V_46 -> V_18 . V_236 [ V_171 ] -> V_257 [ V_138 ] ;
if ( F_34 ( V_58 , V_258 ,
V_173 -> V_259 ) )
goto V_63;
if ( ( V_173 -> V_56 & V_260 ) &&
F_35 ( V_58 ,
V_261 ) )
goto V_63;
F_51 ( V_58 , V_168 ) ;
}
F_51 ( V_58 , V_167 ) ;
F_51 ( V_58 , V_164 ) ;
}
F_51 ( V_58 , V_163 ) ;
V_169 = F_50 ( V_58 , V_262 ) ;
if ( ! V_169 )
goto V_63;
V_138 = 0 ;
#define F_60 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_60 ( V_263 , V_264 ) ;
F_60 ( V_265 , V_266 ) ;
F_60 ( V_267 , V_268 ) ;
F_60 ( V_269 , V_270 ) ;
F_60 ( V_271 , V_272 ) ;
F_60 ( V_273 , V_274 ) ;
F_60 ( V_275 , V_276 ) ;
F_60 ( V_277 , V_278 ) ;
F_60 ( V_279 , V_280 ) ;
F_60 ( V_281 , V_282 ) ;
F_60 ( V_283 , V_284 ) ;
F_60 ( V_285 , V_286 ) ;
F_60 ( V_287 , V_288 ) ;
F_60 ( V_289 , V_290 ) ;
F_60 ( V_291 , V_292 ) ;
F_60 ( V_293 , V_294 ) ;
F_60 ( V_295 , V_296 ) ;
if ( V_46 -> V_18 . V_56 & V_297 )
F_60 ( V_298 , V_299 ) ;
F_60 ( V_300 , V_301 ) ;
F_60 ( V_302 , V_303 ) ;
F_60 ( V_304 , V_305 ) ;
if ( V_46 -> V_18 . V_56 & V_306 ) {
V_138 ++ ;
if ( F_34 ( V_58 , V_138 , V_307 ) )
goto V_63;
}
if ( V_46 -> V_226 -> V_308 || V_46 -> V_226 -> V_269 ||
V_46 -> V_226 -> V_289 ) {
V_138 ++ ;
if ( F_34 ( V_58 , V_138 , V_309 ) )
goto V_63;
}
F_60 ( V_310 , V_311 ) ;
if ( V_46 -> V_18 . V_56 & V_208 ) {
F_60 ( V_312 , V_313 ) ;
F_60 ( V_314 , V_315 ) ;
}
if ( V_46 -> V_18 . V_56 & V_316 )
F_60 ( V_317 , V_318 ) ;
F_60 ( V_319 , V_320 ) ;
F_60 ( V_321 , V_322 ) ;
if ( V_46 -> V_18 . V_56 & V_323 ) {
V_138 ++ ;
if ( F_34 ( V_58 , V_138 , V_324 ) )
goto V_63;
}
F_60 ( V_325 , V_326 ) ;
F_60 ( V_327 , V_328 ) ;
#ifdef F_61
F_60 ( V_329 , V_330 ) ;
#endif
#undef F_60
if ( V_46 -> V_226 -> V_331 || V_46 -> V_226 -> V_279 ) {
V_138 ++ ;
if ( F_34 ( V_58 , V_138 , V_332 ) )
goto V_63;
}
if ( V_46 -> V_226 -> V_333 || V_46 -> V_226 -> V_283 ) {
V_138 ++ ;
if ( F_34 ( V_58 , V_138 , V_334 ) )
goto V_63;
}
F_51 ( V_58 , V_169 ) ;
if ( V_46 -> V_226 -> V_298 &&
( V_46 -> V_18 . V_56 & V_297 ) &&
F_34 ( V_58 , V_335 ,
V_46 -> V_18 . V_336 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_337 ) &&
F_35 ( V_58 , V_338 ) )
goto V_63;
if ( V_175 ) {
T_3 V_339 ;
struct V_4 * V_340 , * V_341 ;
enum V_342 V_343 ;
V_341 = F_50 ( V_58 , V_344 ) ;
if ( ! V_341 )
goto V_63;
for ( V_343 = 0 ; V_343 < V_345 ; V_343 ++ ) {
V_340 = F_50 ( V_58 , V_343 ) ;
if ( ! V_340 )
goto V_63;
V_138 = 0 ;
V_339 = V_175 [ V_343 ] . V_346 ;
while ( V_339 ) {
if ( ( V_339 & 1 ) &&
F_57 ( V_58 , V_347 ,
( V_138 << 4 ) | V_348 ) )
goto V_63;
V_339 >>= 1 ;
V_138 ++ ;
}
F_51 ( V_58 , V_340 ) ;
}
F_51 ( V_58 , V_341 ) ;
V_341 = F_50 ( V_58 , V_349 ) ;
if ( ! V_341 )
goto V_63;
for ( V_343 = 0 ; V_343 < V_345 ; V_343 ++ ) {
V_340 = F_50 ( V_58 , V_343 ) ;
if ( ! V_340 )
goto V_63;
V_138 = 0 ;
V_339 = V_175 [ V_343 ] . V_350 ;
while ( V_339 ) {
if ( ( V_339 & 1 ) &&
F_57 ( V_58 , V_347 ,
( V_138 << 4 ) | V_348 ) )
goto V_63;
V_339 >>= 1 ;
V_138 ++ ;
}
F_51 ( V_58 , V_340 ) ;
}
F_51 ( V_58 , V_341 ) ;
}
#ifdef F_62
if ( V_46 -> V_18 . V_351 . V_56 || V_46 -> V_18 . V_351 . V_352 ) {
struct V_4 * V_353 ;
V_353 = F_50 ( V_58 ,
V_354 ) ;
if ( ! V_353 )
goto V_63;
if ( ( ( V_46 -> V_18 . V_351 . V_56 & V_355 ) &&
F_35 ( V_58 , V_356 ) ) ||
( ( V_46 -> V_18 . V_351 . V_56 & V_357 ) &&
F_35 ( V_58 , V_358 ) ) ||
( ( V_46 -> V_18 . V_351 . V_56 & V_359 ) &&
F_35 ( V_58 , V_360 ) ) ||
( ( V_46 -> V_18 . V_351 . V_56 & V_361 ) &&
F_35 ( V_58 , V_362 ) ) ||
( ( V_46 -> V_18 . V_351 . V_56 & V_363 ) &&
F_35 ( V_58 , V_364 ) ) ||
( ( V_46 -> V_18 . V_351 . V_56 & V_365 ) &&
F_35 ( V_58 , V_366 ) ) ||
( ( V_46 -> V_18 . V_351 . V_56 & V_367 ) &&
F_35 ( V_58 , V_368 ) ) ||
( ( V_46 -> V_18 . V_351 . V_56 & V_369 ) &&
F_35 ( V_58 , V_370 ) ) )
goto V_63;
if ( V_46 -> V_18 . V_351 . V_352 ) {
struct V_371 V_372 = {
. V_373 = V_46 -> V_18 . V_351 . V_352 ,
. V_374 =
V_46 -> V_18 . V_351 . V_375 ,
. V_376 =
V_46 -> V_18 . V_351 . V_377 ,
} ;
if ( F_58 ( V_58 , V_378 ,
sizeof( V_372 ) , & V_372 ) )
goto V_63;
}
F_51 ( V_58 , V_353 ) ;
}
#endif
if ( F_49 ( V_58 , V_379 ,
V_46 -> V_18 . V_380 ) )
goto V_63;
if ( F_52 ( & V_46 -> V_18 , V_58 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_381 ) &&
F_34 ( V_58 , V_382 ,
V_46 -> V_18 . V_383 ) )
goto V_63;
if ( F_34 ( V_58 , V_384 ,
V_46 -> V_18 . V_385 ) )
goto V_63;
if ( V_46 -> V_18 . V_386 &&
F_58 ( V_58 , V_387 ,
sizeof( * V_46 -> V_18 . V_386 ) ,
V_46 -> V_18 . V_386 ) )
goto V_63;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
static int F_65 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_88 = 0 ;
int V_389 = V_35 -> args [ 0 ] ;
struct V_6 * V_46 ;
F_8 ( & V_32 ) ;
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_66 ( F_7 ( & V_46 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( ++ V_88 <= V_389 )
continue;
if ( F_53 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_390 , V_391 ,
V_46 ) < 0 ) {
V_88 -- ;
break;
}
}
F_9 ( & V_32 ) ;
V_35 -> args [ 0 ] = V_88 ;
return V_45 -> V_52 ;
}
static int F_68 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
struct V_6 * V_46 = V_31 -> V_392 [ 0 ] ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_53 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 , V_46 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_72 ( struct V_4 * V_78 [] ,
struct V_396 * V_397 )
{
if ( ! V_78 [ V_398 ] || ! V_78 [ V_399 ] ||
! V_78 [ V_400 ] || ! V_78 [ V_401 ] ||
! V_78 [ V_402 ] )
return - V_16 ;
V_397 -> V_403 = F_39 ( V_78 [ V_398 ] ) ;
V_397 -> V_404 = F_73 ( V_78 [ V_399 ] ) ;
V_397 -> V_405 = F_73 ( V_78 [ V_400 ] ) ;
V_397 -> V_406 = F_73 ( V_78 [ V_401 ] ) ;
V_397 -> V_407 = F_39 ( V_78 [ V_402 ] ) ;
if ( V_397 -> V_403 >= V_408 )
return - V_16 ;
return 0 ;
}
static bool F_74 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_124 == V_125 ||
V_17 -> V_124 == V_128 ||
V_17 -> V_124 == V_409 ||
V_17 -> V_124 == V_127 ;
}
static int F_75 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_410 * V_411 )
{
V_23 V_412 ;
if ( ! V_31 -> V_5 [ V_413 ] )
return - V_16 ;
V_412 = F_4 ( V_31 -> V_5 [ V_413 ] ) ;
V_411 -> V_60 = F_76 ( & V_7 -> V_18 , V_412 ) ;
V_411 -> V_414 = V_415 ;
V_411 -> V_416 = V_412 ;
V_411 -> V_417 = 0 ;
if ( ! V_411 -> V_60 || V_411 -> V_60 -> V_56 & V_64 )
return - V_16 ;
if ( V_31 -> V_5 [ V_418 ] ) {
enum V_419 V_420 ;
V_420 = F_4 (
V_31 -> V_5 [ V_418 ] ) ;
switch ( V_420 ) {
case V_421 :
case V_422 :
case V_423 :
case V_424 :
F_77 ( V_411 , V_411 -> V_60 ,
V_420 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_31 -> V_5 [ V_425 ] ) {
V_411 -> V_414 =
F_4 ( V_31 -> V_5 [ V_425 ] ) ;
if ( V_31 -> V_5 [ V_426 ] )
V_411 -> V_416 =
F_4 (
V_31 -> V_5 [ V_426 ] ) ;
if ( V_31 -> V_5 [ V_427 ] )
V_411 -> V_417 =
F_4 (
V_31 -> V_5 [ V_427 ] ) ;
}
if ( ! F_78 ( V_411 ) )
return - V_16 ;
if ( ! F_79 ( & V_7 -> V_18 , V_411 ,
V_64 ) )
return - V_16 ;
return 0 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_30 * V_31 )
{
struct V_410 V_411 ;
int V_8 ;
enum V_342 V_124 = V_409 ;
if ( V_17 )
V_124 = V_17 -> V_124 ;
if ( ! F_74 ( V_17 ) )
return - V_428 ;
V_8 = F_75 ( V_7 , V_31 , & V_411 ) ;
if ( V_8 )
return V_8 ;
F_8 ( & V_7 -> V_19 ) ;
switch ( V_124 ) {
case V_125 :
case V_127 :
if ( V_17 -> V_429 ) {
V_8 = - V_430 ;
break;
}
if ( ! F_81 ( & V_7 -> V_18 , & V_411 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_431 = V_411 ;
V_8 = 0 ;
break;
case V_128 :
V_8 = F_82 ( V_7 , V_17 , & V_411 ) ;
break;
case V_409 :
V_8 = F_83 ( V_7 , & V_411 ) ;
break;
default:
V_8 = - V_16 ;
}
F_9 ( & V_7 -> V_19 ) ;
return V_8 ;
}
static int F_84 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_20 = V_31 -> V_392 [ 1 ] ;
return F_80 ( V_7 , V_20 -> V_29 , V_31 ) ;
}
static int F_85 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
const T_2 * V_432 ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( F_86 ( V_46 ) )
return - V_430 ;
if ( ! V_7 -> V_226 -> V_310 )
return - V_428 ;
if ( V_17 -> V_124 != V_434 )
return - V_428 ;
V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
return F_87 ( V_7 , V_46 , V_432 ) ;
}
static int F_88 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_26 * V_20 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_435 = 0 ;
struct V_4 * V_436 ;
V_23 V_437 ;
T_2 V_181 = 0 , V_183 = 0 ;
V_23 V_185 = 0 , V_187 = 0 ;
T_2 V_189 = 0 ;
F_8 ( & V_32 ) ;
if ( V_31 -> V_5 [ V_10 ] ) {
int V_21 = F_4 ( V_31 -> V_5 [ V_10 ] ) ;
V_20 = F_12 ( F_89 ( V_31 ) , V_21 ) ;
if ( V_20 && V_20 -> V_29 ) {
V_7 = F_13 ( V_20 -> V_29 -> V_18 ) ;
F_8 ( & V_7 -> V_33 ) ;
} else
V_20 = NULL ;
}
if ( ! V_20 ) {
V_7 = F_10 ( F_89 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_7 ) ) {
F_9 ( & V_32 ) ;
return F_24 ( V_7 ) ;
}
V_17 = NULL ;
V_20 = NULL ;
V_8 = 0 ;
F_8 ( & V_7 -> V_33 ) ;
} else
V_17 = V_20 -> V_29 ;
if ( V_31 -> V_5 [ V_177 ] )
V_8 = F_90 (
V_7 , F_29 ( V_31 -> V_5 [ V_177 ] ) ) ;
F_9 ( & V_32 ) ;
if ( V_8 )
goto V_438;
if ( V_31 -> V_5 [ V_439 ] ) {
struct V_396 V_397 ;
struct V_4 * V_78 [ V_440 + 1 ] ;
if ( ! V_7 -> V_226 -> V_441 ) {
V_8 = - V_428 ;
goto V_438;
}
if ( ! V_20 ) {
V_8 = - V_16 ;
goto V_438;
}
if ( V_20 -> V_29 -> V_124 != V_125 &&
V_20 -> V_29 -> V_124 != V_127 ) {
V_8 = - V_16 ;
goto V_438;
}
if ( ! F_86 ( V_20 ) ) {
V_8 = - V_442 ;
goto V_438;
}
F_44 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_91 ( V_78 , V_440 ,
F_29 ( V_436 ) ,
F_30 ( V_436 ) ,
V_443 ) ;
V_8 = F_72 ( V_78 , & V_397 ) ;
if ( V_8 )
goto V_438;
V_8 = F_92 ( V_7 , V_20 ,
& V_397 ) ;
if ( V_8 )
goto V_438;
}
}
if ( V_31 -> V_5 [ V_413 ] ) {
V_8 = F_80 ( V_7 ,
F_74 ( V_17 ) ? V_17 : NULL ,
V_31 ) ;
if ( V_8 )
goto V_438;
}
if ( V_31 -> V_5 [ V_444 ] ) {
struct V_1 * V_445 = V_17 ;
enum V_446 type ;
int V_88 , V_447 = 0 ;
if ( ! ( V_7 -> V_18 . V_385 & V_448 ) )
V_445 = NULL ;
if ( ! V_7 -> V_226 -> V_449 ) {
V_8 = - V_428 ;
goto V_438;
}
V_88 = V_444 ;
type = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
if ( ! V_31 -> V_5 [ V_450 ] &&
( type != V_451 ) ) {
V_8 = - V_16 ;
goto V_438;
}
if ( type != V_451 ) {
V_88 = V_450 ;
V_447 = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
}
V_8 = F_93 ( V_7 , V_445 , type , V_447 ) ;
if ( V_8 )
goto V_438;
}
if ( V_31 -> V_5 [ V_230 ] &&
V_31 -> V_5 [ V_231 ] ) {
V_23 V_228 , V_229 ;
if ( ( ! V_7 -> V_18 . V_220 &&
! V_7 -> V_18 . V_222 ) ||
! V_7 -> V_226 -> V_452 ) {
V_8 = - V_428 ;
goto V_438;
}
V_228 = F_4 ( V_31 -> V_5 [ V_230 ] ) ;
V_229 = F_4 ( V_31 -> V_5 [ V_231 ] ) ;
if ( ( ~ V_228 && ( V_228 & ~ V_7 -> V_18 . V_220 ) ) ||
( ~ V_229 && ( V_229 & ~ V_7 -> V_18 . V_222 ) ) ) {
V_8 = - V_16 ;
goto V_438;
}
V_228 = V_228 & V_7 -> V_18 . V_220 ;
V_229 = V_229 & V_7 -> V_18 . V_222 ;
V_8 = F_94 ( V_7 , V_228 , V_229 ) ;
if ( V_8 )
goto V_438;
}
V_437 = 0 ;
if ( V_31 -> V_5 [ V_180 ] ) {
V_181 = F_39 (
V_31 -> V_5 [ V_180 ] ) ;
if ( V_181 == 0 ) {
V_8 = - V_16 ;
goto V_438;
}
V_437 |= V_453 ;
}
if ( V_31 -> V_5 [ V_182 ] ) {
V_183 = F_39 (
V_31 -> V_5 [ V_182 ] ) ;
if ( V_183 == 0 ) {
V_8 = - V_16 ;
goto V_438;
}
V_437 |= V_454 ;
}
if ( V_31 -> V_5 [ V_184 ] ) {
V_185 = F_4 (
V_31 -> V_5 [ V_184 ] ) ;
if ( V_185 < 256 ) {
V_8 = - V_16 ;
goto V_438;
}
if ( V_185 != ( V_23 ) - 1 ) {
V_185 &= ~ 0x1 ;
}
V_437 |= V_455 ;
}
if ( V_31 -> V_5 [ V_186 ] ) {
V_187 = F_4 (
V_31 -> V_5 [ V_186 ] ) ;
V_437 |= V_456 ;
}
if ( V_31 -> V_5 [ V_188 ] ) {
V_189 = F_39 (
V_31 -> V_5 [ V_188 ] ) ;
V_437 |= V_457 ;
}
if ( V_437 ) {
T_2 V_458 , V_459 ;
V_23 V_460 , V_461 ;
T_2 V_462 ;
if ( ! V_7 -> V_226 -> V_463 ) {
V_8 = - V_428 ;
goto V_438;
}
V_458 = V_7 -> V_18 . V_181 ;
V_459 = V_7 -> V_18 . V_183 ;
V_460 = V_7 -> V_18 . V_185 ;
V_461 = V_7 -> V_18 . V_187 ;
V_462 = V_7 -> V_18 . V_189 ;
if ( V_437 & V_453 )
V_7 -> V_18 . V_181 = V_181 ;
if ( V_437 & V_454 )
V_7 -> V_18 . V_183 = V_183 ;
if ( V_437 & V_455 )
V_7 -> V_18 . V_185 = V_185 ;
if ( V_437 & V_456 )
V_7 -> V_18 . V_187 = V_187 ;
if ( V_437 & V_457 )
V_7 -> V_18 . V_189 = V_189 ;
V_8 = F_95 ( V_7 , V_437 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_181 = V_458 ;
V_7 -> V_18 . V_183 = V_459 ;
V_7 -> V_18 . V_185 = V_460 ;
V_7 -> V_18 . V_187 = V_461 ;
V_7 -> V_18 . V_189 = V_462 ;
}
}
V_438:
F_9 ( & V_7 -> V_33 ) ;
if ( V_20 )
F_14 ( V_20 ) ;
return V_8 ;
}
static inline T_1 V_13 ( struct V_1 * V_17 )
{
return ( T_1 ) V_17 -> V_22 |
( ( T_1 ) F_13 ( V_17 -> V_18 ) -> V_14 << 32 ) ;
}
static int F_96 ( struct V_44 * V_58 ,
struct V_410 * V_411 )
{
F_97 ( ! F_78 ( V_411 ) ) ;
if ( F_34 ( V_58 , V_413 ,
V_411 -> V_60 -> V_62 ) )
return - V_74 ;
switch ( V_411 -> V_414 ) {
case V_415 :
case V_464 :
case V_465 :
if ( F_34 ( V_58 , V_418 ,
F_98 ( V_411 ) ) )
return - V_74 ;
break;
default:
break;
}
if ( F_34 ( V_58 , V_425 , V_411 -> V_414 ) )
return - V_74 ;
if ( F_34 ( V_58 , V_426 , V_411 -> V_416 ) )
return - V_74 ;
if ( V_411 -> V_417 &&
F_34 ( V_58 , V_427 , V_411 -> V_417 ) )
return - V_74 ;
return 0 ;
}
static int F_99 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 , int V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_26 * V_46 = V_17 -> V_20 ;
void * V_162 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_466 ) ;
if ( ! V_162 )
return - 1 ;
if ( V_46 &&
( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_54 ( V_58 , V_467 , V_46 -> V_468 ) ) )
goto V_63;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_469 , V_17 -> V_124 ) ||
F_100 ( V_58 , V_12 , V_13 ( V_17 ) ) ||
F_58 ( V_58 , V_433 , V_470 , F_101 ( V_17 ) ) ||
F_34 ( V_58 , V_178 ,
V_7 -> V_471 ^
( V_179 << 2 ) ) )
goto V_63;
if ( V_7 -> V_226 -> V_472 ) {
int V_473 ;
struct V_410 V_411 ;
V_473 = F_102 ( V_7 , V_17 , & V_411 ) ;
if ( V_473 == 0 ) {
if ( F_96 ( V_58 , & V_411 ) )
goto V_63;
}
}
if ( V_17 -> V_474 ) {
if ( F_58 ( V_58 , V_475 , V_17 -> V_474 , V_17 -> V_476 ) )
goto V_63;
}
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
static int F_103 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_477 = 0 ;
int V_478 = 0 ;
int V_479 = V_35 -> args [ 0 ] ;
int V_480 = V_35 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_8 ( & V_32 ) ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_66 ( F_7 ( & V_7 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( V_477 < V_479 ) {
V_477 ++ ;
continue;
}
V_478 = 0 ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_478 < V_480 ) {
V_478 ++ ;
continue;
}
if ( F_99 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_390 , V_391 ,
V_7 , V_17 ) < 0 ) {
F_9 ( & V_7 -> V_19 ) ;
goto V_481;
}
V_478 ++ ;
}
F_9 ( & V_7 -> V_19 ) ;
V_477 ++ ;
}
V_481:
F_9 ( & V_32 ) ;
V_35 -> args [ 0 ] = V_477 ;
V_35 -> args [ 1 ] = V_478 ;
return V_45 -> V_52 ;
}
static int F_104 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
struct V_6 * V_46 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_99 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_46 , V_17 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_105 ( struct V_4 * V_482 , V_23 * V_483 )
{
struct V_4 * V_56 [ V_484 + 1 ] ;
int V_485 ;
* V_483 = 0 ;
if ( ! V_482 )
return - V_16 ;
if ( F_38 ( V_56 , V_484 ,
V_482 , V_486 ) )
return - V_16 ;
for ( V_485 = 1 ; V_485 <= V_484 ; V_485 ++ )
if ( V_56 [ V_485 ] )
* V_483 |= ( 1 << V_485 ) ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_2 V_487 ,
enum V_342 V_124 )
{
if ( ! V_487 ) {
if ( V_20 && ( V_20 -> V_488 & V_489 ) )
return - V_430 ;
return 0 ;
}
switch ( V_124 ) {
case V_126 :
if ( V_7 -> V_18 . V_56 & V_490 )
return 0 ;
break;
case V_132 :
if ( V_7 -> V_18 . V_56 & V_491 )
return 0 ;
break;
default:
break;
}
return - V_428 ;
}
static int F_107 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_492 V_120 ;
int V_47 ;
enum V_342 V_493 , V_494 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
V_23 V_495 , * V_56 = NULL ;
bool V_496 = false ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_493 = V_494 = V_46 -> V_29 -> V_124 ;
if ( V_31 -> V_5 [ V_469 ] ) {
V_494 = F_4 ( V_31 -> V_5 [ V_469 ] ) ;
if ( V_493 != V_494 )
V_496 = true ;
if ( V_494 > V_497 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_498 ] ) {
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_494 != V_128 )
return - V_16 ;
if ( F_86 ( V_46 ) )
return - V_430 ;
F_108 ( V_17 ) ;
F_109 ( V_499 !=
V_500 ) ;
V_17 -> V_501 =
F_30 ( V_31 -> V_5 [ V_498 ] ) ;
memcpy ( V_17 -> V_476 , F_29 ( V_31 -> V_5 [ V_498 ] ) ,
V_17 -> V_501 ) ;
F_110 ( V_17 ) ;
}
if ( V_31 -> V_5 [ V_502 ] ) {
V_120 . V_487 = ! ! F_39 ( V_31 -> V_5 [ V_502 ] ) ;
V_496 = true ;
V_47 = F_106 ( V_7 , V_46 , V_120 . V_487 , V_494 ) ;
if ( V_47 )
return V_47 ;
} else {
V_120 . V_487 = - 1 ;
}
if ( V_31 -> V_5 [ V_503 ] ) {
if ( V_494 != V_409 )
return - V_16 ;
V_47 = F_105 ( V_31 -> V_5 [ V_503 ] ,
& V_495 ) ;
if ( V_47 )
return V_47 ;
V_56 = & V_495 ;
V_496 = true ;
}
if ( V_496 )
V_47 = F_111 ( V_7 , V_46 , V_494 , V_56 , & V_120 ) ;
else
V_47 = 0 ;
if ( ! V_47 && V_120 . V_487 != - 1 )
V_46 -> V_29 -> V_487 = V_120 . V_487 ;
return V_47 ;
}
static int F_112 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_492 V_120 ;
struct V_1 * V_17 ;
struct V_44 * V_58 ;
int V_47 ;
enum V_342 type = V_504 ;
V_23 V_56 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
if ( ! V_31 -> V_5 [ V_467 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_469 ] ) {
type = F_4 ( V_31 -> V_5 [ V_469 ] ) ;
if ( type > V_497 )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_263 ||
! ( V_7 -> V_18 . V_233 & ( 1 << type ) ) )
return - V_428 ;
if ( V_31 -> V_5 [ V_502 ] ) {
V_120 . V_487 = ! ! F_39 ( V_31 -> V_5 [ V_502 ] ) ;
V_47 = F_106 ( V_7 , NULL , V_120 . V_487 , type ) ;
if ( V_47 )
return V_47 ;
}
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_47 = F_105 ( type == V_409 ?
V_31 -> V_5 [ V_503 ] : NULL ,
& V_56 ) ;
V_17 = F_113 ( V_7 ,
F_29 ( V_31 -> V_5 [ V_467 ] ) ,
type , V_47 ? NULL : & V_56 , & V_120 ) ;
if ( F_16 ( V_17 ) ) {
F_70 ( V_58 ) ;
return F_24 ( V_17 ) ;
}
switch ( type ) {
case V_128 :
if ( ! V_31 -> V_5 [ V_498 ] )
break;
F_108 ( V_17 ) ;
F_109 ( V_499 !=
V_500 ) ;
V_17 -> V_501 =
F_30 ( V_31 -> V_5 [ V_498 ] ) ;
memcpy ( V_17 -> V_476 , F_29 ( V_31 -> V_5 [ V_498 ] ) ,
V_17 -> V_501 ) ;
F_110 ( V_17 ) ;
break;
case V_505 :
F_114 ( & V_17 -> V_33 ) ;
F_115 ( & V_17 -> V_506 ) ;
F_116 ( & V_17 -> V_507 ) ;
F_115 ( & V_17 -> V_508 ) ;
F_116 ( & V_17 -> V_509 ) ;
F_8 ( & V_7 -> V_19 ) ;
V_17 -> V_22 = ++ V_7 -> V_13 ;
F_117 ( & V_17 -> V_510 , & V_7 -> V_511 ) ;
V_7 -> V_471 ++ ;
F_9 ( & V_7 -> V_19 ) ;
break;
default:
break;
}
if ( F_99 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_7 , V_17 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_118 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
if ( ! V_7 -> V_226 -> V_512 )
return - V_428 ;
if ( ! V_17 -> V_20 )
V_31 -> V_392 [ 1 ] = NULL ;
return F_119 ( V_7 , V_17 ) ;
}
static int F_120 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_3 V_513 ;
if ( ! V_31 -> V_5 [ V_514 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_321 )
return - V_428 ;
V_513 = F_73 ( V_31 -> V_5 [ V_514 ] ) ;
return F_121 ( V_7 , V_46 , V_513 ) ;
}
static void F_122 ( void * V_144 , struct V_515 * V_120 )
{
struct V_4 * V_75 ;
struct V_516 * V_517 = V_144 ;
if ( ( V_120 -> V_75 &&
F_58 ( V_517 -> V_58 , V_104 ,
V_120 -> V_91 , V_120 -> V_75 ) ) ||
( V_120 -> V_55 &&
F_58 ( V_517 -> V_58 , V_105 ,
V_120 -> V_93 , V_120 -> V_55 ) ) ||
( V_120 -> V_95 &&
F_34 ( V_517 -> V_58 , V_107 ,
V_120 -> V_95 ) ) )
goto V_63;
V_75 = F_50 ( V_517 -> V_58 , V_112 ) ;
if ( ! V_75 )
goto V_63;
if ( ( V_120 -> V_75 &&
F_58 ( V_517 -> V_58 , V_89 ,
V_120 -> V_91 , V_120 -> V_75 ) ) ||
( V_120 -> V_55 &&
F_58 ( V_517 -> V_58 , V_92 ,
V_120 -> V_93 , V_120 -> V_55 ) ) ||
( V_120 -> V_95 &&
F_34 ( V_517 -> V_58 , V_94 ,
V_120 -> V_95 ) ) )
goto V_63;
if ( F_56 ( V_517 -> V_58 , V_106 , V_517 -> V_88 ) )
goto V_63;
F_51 ( V_517 -> V_58 , V_75 ) ;
return;
V_63:
V_517 -> error = 1 ;
}
static int F_123 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 V_518 = 0 ;
const T_2 * V_519 = NULL ;
bool V_520 ;
struct V_516 V_517 = {
. error = 0 ,
} ;
void * V_162 ;
struct V_44 * V_58 ;
if ( V_31 -> V_5 [ V_106 ] )
V_518 = F_39 ( V_31 -> V_5 [ V_106 ] ) ;
if ( V_518 > 5 )
return - V_16 ;
if ( V_31 -> V_5 [ V_433 ] )
V_519 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_520 = ! ! V_519 ;
if ( V_31 -> V_5 [ V_110 ] ) {
V_23 V_521 = F_4 ( V_31 -> V_5 [ V_110 ] ) ;
if ( V_521 >= V_97 )
return - V_16 ;
if ( V_521 != V_522 &&
V_521 != V_523 )
return - V_16 ;
V_520 = V_521 == V_523 ;
}
if ( ! V_7 -> V_226 -> V_524 )
return - V_428 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_525 ) ;
if ( F_16 ( V_162 ) )
return F_24 ( V_162 ) ;
V_517 . V_58 = V_58 ;
V_517 . V_88 = V_518 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_56 ( V_58 , V_106 , V_518 ) )
goto V_63;
if ( V_519 &&
F_58 ( V_58 , V_433 , V_470 , V_519 ) )
goto V_63;
if ( V_520 && V_519 &&
! ( V_7 -> V_18 . V_56 & V_200 ) )
return - V_526 ;
V_47 = F_124 ( V_7 , V_46 , V_518 , V_520 , V_519 , & V_517 ,
F_122 ) ;
if ( V_47 )
goto V_527;
if ( V_517 . error )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_527:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_125 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_76 V_75 ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 < 0 )
return - V_16 ;
if ( ! V_75 . V_81 && ! V_75 . V_83 )
return - V_16 ;
F_108 ( V_46 -> V_29 ) ;
if ( V_75 . V_81 ) {
if ( ! V_7 -> V_226 -> V_528 ) {
V_47 = - V_428 ;
goto V_481;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_481;
V_47 = F_126 ( V_7 , V_46 , V_75 . V_88 ,
V_75 . V_85 , V_75 . V_86 ) ;
if ( V_47 )
goto V_481;
#ifdef F_127
V_46 -> V_29 -> V_529 . V_530 = V_75 . V_88 ;
#endif
} else {
if ( V_75 . V_85 || ! V_75 . V_86 ) {
V_47 = - V_16 ;
goto V_481;
}
if ( ! V_7 -> V_226 -> V_531 ) {
V_47 = - V_428 ;
goto V_481;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_481;
V_47 = F_128 ( V_7 , V_46 , V_75 . V_88 ) ;
if ( V_47 )
goto V_481;
#ifdef F_127
V_46 -> V_29 -> V_529 . V_532 = V_75 . V_88 ;
#endif
}
V_481:
F_110 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_129 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_76 V_75 ;
const T_2 * V_519 = NULL ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_75 . V_90 . V_75 )
return - V_16 ;
if ( V_31 -> V_5 [ V_433 ] )
V_519 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_519 )
V_75 . type = V_523 ;
else
V_75 . type = V_522 ;
}
if ( V_75 . type != V_523 &&
V_75 . type != V_522 )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_267 )
return - V_428 ;
if ( F_45 ( V_7 , & V_75 . V_90 , V_75 . V_88 ,
V_75 . type == V_523 ,
V_519 ) )
return - V_16 ;
F_108 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( ! V_47 )
V_47 = F_130 ( V_7 , V_46 , V_75 . V_88 ,
V_75 . type == V_523 ,
V_519 , & V_75 . V_90 ) ;
F_110 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_131 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 * V_519 = NULL ;
struct V_76 V_75 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_433 ] )
V_519 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_519 )
V_75 . type = V_523 ;
else
V_75 . type = V_522 ;
}
if ( V_75 . type != V_523 &&
V_75 . type != V_522 )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_533 )
return - V_428 ;
F_108 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_75 . type == V_523 && V_519 &&
! ( V_7 -> V_18 . V_56 & V_200 ) )
V_47 = - V_526 ;
if ( ! V_47 )
V_47 = F_132 ( V_7 , V_46 , V_75 . V_88 ,
V_75 . type == V_523 ,
V_519 ) ;
#ifdef F_127
if ( ! V_47 ) {
if ( V_75 . V_88 == V_46 -> V_29 -> V_529 . V_530 )
V_46 -> V_29 -> V_529 . V_530 = - 1 ;
else if ( V_75 . V_88 == V_46 -> V_29 -> V_529 . V_532 )
V_46 -> V_29 -> V_529 . V_532 = - 1 ;
}
#endif
F_110 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_133 ( struct V_30 * V_31 ,
struct V_534 * V_535 )
{
bool V_536 = false ;
if ( ! F_28 ( V_31 -> V_5 [ V_537 ] ) ||
! F_28 ( V_31 -> V_5 [ V_538 ] ) ||
! F_28 ( V_31 -> V_5 [ V_539 ] ) ||
! F_28 ( V_31 -> V_5 [ V_540 ] ) )
return - V_16 ;
memset ( V_535 , 0 , sizeof( * V_535 ) ) ;
if ( V_31 -> V_5 [ V_541 ] ) {
V_535 -> V_542 = F_29 ( V_31 -> V_5 [ V_541 ] ) ;
V_535 -> V_543 = F_30 ( V_31 -> V_5 [ V_541 ] ) ;
if ( ! V_535 -> V_543 )
return - V_16 ;
V_536 = true ;
}
if ( V_31 -> V_5 [ V_537 ] ) {
V_535 -> V_544 = F_29 ( V_31 -> V_5 [ V_537 ] ) ;
V_535 -> V_545 =
F_30 ( V_31 -> V_5 [ V_537 ] ) ;
V_536 = true ;
}
if ( ! V_536 )
return - V_16 ;
if ( V_31 -> V_5 [ V_538 ] ) {
V_535 -> V_546 = F_29 ( V_31 -> V_5 [ V_538 ] ) ;
V_535 -> V_547 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
}
if ( V_31 -> V_5 [ V_539 ] ) {
V_535 -> V_548 =
F_29 ( V_31 -> V_5 [ V_539 ] ) ;
V_535 -> V_549 =
F_30 ( V_31 -> V_5 [ V_539 ] ) ;
}
if ( V_31 -> V_5 [ V_540 ] ) {
V_535 -> V_550 =
F_29 ( V_31 -> V_5 [ V_540 ] ) ;
V_535 -> V_551 =
F_30 ( V_31 -> V_5 [ V_540 ] ) ;
}
if ( V_31 -> V_5 [ V_552 ] ) {
V_535 -> V_553 =
F_29 ( V_31 -> V_5 [ V_552 ] ) ;
V_535 -> V_554 =
F_30 ( V_31 -> V_5 [ V_552 ] ) ;
}
return 0 ;
}
static bool F_134 ( struct V_6 * V_7 ,
struct V_555 * V_120 )
{
struct V_1 * V_17 ;
bool V_473 = false ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_124 != V_125 &&
V_17 -> V_124 != V_127 )
continue;
if ( ! V_17 -> V_431 . V_60 )
continue;
V_120 -> V_411 = V_17 -> V_431 ;
V_473 = true ;
break;
}
F_9 ( & V_7 -> V_19 ) ;
return V_473 ;
}
static bool F_135 ( struct V_6 * V_7 ,
enum V_556 V_557 ,
enum V_558 V_57 )
{
if ( V_557 > V_559 )
return false ;
switch ( V_57 ) {
case V_560 :
if ( ! ( V_7 -> V_18 . V_385 & V_561 ) &&
V_557 == V_562 )
return false ;
return true ;
case V_332 :
case V_563 :
if ( V_557 == V_562 )
return false ;
return true ;
default:
return false ;
}
}
static int F_136 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_555 V_120 ;
int V_47 ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_428 ;
if ( ! V_7 -> V_226 -> V_269 )
return - V_428 ;
if ( V_17 -> V_429 )
return - V_564 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
if ( ! V_31 -> V_5 [ V_565 ] ||
! V_31 -> V_5 [ V_566 ] ||
! V_31 -> V_5 [ V_541 ] )
return - V_16 ;
V_47 = F_133 ( V_31 , & V_120 . V_567 ) ;
if ( V_47 )
return V_47 ;
V_120 . V_429 =
F_4 ( V_31 -> V_5 [ V_565 ] ) ;
V_120 . V_568 =
F_4 ( V_31 -> V_5 [ V_566 ] ) ;
V_47 = F_137 ( V_7 , V_120 . V_429 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_475 ] ) {
V_120 . V_476 = F_29 ( V_31 -> V_5 [ V_475 ] ) ;
V_120 . V_474 =
F_30 ( V_31 -> V_5 [ V_475 ] ) ;
if ( V_120 . V_474 == 0 ||
V_120 . V_474 > V_499 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_569 ] ) {
V_120 . V_570 = F_4 (
V_31 -> V_5 [ V_569 ] ) ;
if ( V_120 . V_570 != V_571 &&
V_120 . V_570 != V_572 &&
V_120 . V_570 != V_573 )
return - V_16 ;
}
V_120 . V_574 = ! ! V_31 -> V_5 [ V_575 ] ;
if ( V_31 -> V_5 [ V_576 ] ) {
V_120 . V_557 = F_4 (
V_31 -> V_5 [ V_576 ] ) ;
if ( ! F_135 ( V_7 , V_120 . V_557 ,
V_563 ) )
return - V_16 ;
} else
V_120 . V_557 = V_577 ;
V_47 = F_138 ( V_7 , V_31 , & V_120 . V_578 ,
V_579 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_580 ] ) {
if ( ! ( V_7 -> V_18 . V_385 & V_581 ) )
return - V_428 ;
V_120 . V_582 = F_73 (
V_31 -> V_5 [ V_580 ] ) ;
}
if ( V_31 -> V_5 [ V_583 ] ) {
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_120 . V_584 =
F_39 ( V_31 -> V_5 [ V_583 ] ) ;
if ( V_120 . V_584 > 127 )
return - V_16 ;
if ( V_120 . V_584 != 0 &&
! ( V_7 -> V_18 . V_385 & V_585 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_586 ] ) {
T_2 V_25 ;
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_25 = F_39 ( V_31 -> V_5 [ V_586 ] ) ;
if ( V_25 > 1 )
return - V_16 ;
V_120 . V_587 = V_25 ;
if ( V_120 . V_587 != 0 &&
! ( V_7 -> V_18 . V_385 & V_588 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_413 ] ) {
V_47 = F_75 ( V_7 , V_31 , & V_120 . V_411 ) ;
if ( V_47 )
return V_47 ;
} else if ( V_17 -> V_431 . V_60 ) {
V_120 . V_411 = V_17 -> V_431 ;
} else if ( ! F_134 ( V_7 , & V_120 ) )
return - V_16 ;
if ( ! F_81 ( & V_7 -> V_18 , & V_120 . V_411 ) )
return - V_16 ;
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_139 ( V_7 , V_17 , V_120 . V_411 . V_60 ,
V_589 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_140 ( V_7 , V_46 , & V_120 ) ;
if ( ! V_47 ) {
V_17 -> V_431 = V_120 . V_411 ;
V_17 -> V_429 = V_120 . V_429 ;
V_17 -> V_590 = V_120 . V_411 . V_60 ;
V_17 -> V_474 = V_120 . V_474 ;
memcpy ( V_17 -> V_476 , V_120 . V_476 , V_17 -> V_474 ) ;
}
return V_47 ;
}
static int F_141 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_534 V_120 ;
int V_47 ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_428 ;
if ( ! V_7 -> V_226 -> V_591 )
return - V_428 ;
if ( ! V_17 -> V_429 )
return - V_16 ;
V_47 = F_133 ( V_31 , & V_120 ) ;
if ( V_47 )
return V_47 ;
return F_142 ( V_7 , V_46 , & V_120 ) ;
}
static int F_143 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
return F_144 ( V_7 , V_46 ) ;
}
static int F_145 ( struct V_30 * V_31 ,
enum V_342 V_124 ,
struct V_592 * V_120 )
{
struct V_4 * V_56 [ V_593 + 1 ] ;
struct V_4 * V_482 ;
int V_485 ;
V_482 = V_31 -> V_5 [ V_594 ] ;
if ( V_482 ) {
struct V_595 * V_596 ;
V_596 = F_29 ( V_482 ) ;
V_120 -> V_597 = V_596 -> V_598 ;
V_120 -> V_599 = V_596 -> V_600 ;
if ( ( V_120 -> V_597 |
V_120 -> V_599 ) & F_146 ( V_601 ) )
return - V_16 ;
return 0 ;
}
V_482 = V_31 -> V_5 [ V_602 ] ;
if ( ! V_482 )
return 0 ;
if ( F_38 ( V_56 , V_593 ,
V_482 , V_603 ) )
return - V_16 ;
switch ( V_124 ) {
case V_125 :
case V_126 :
case V_127 :
V_120 -> V_597 = F_146 ( V_604 ) |
F_146 ( V_605 ) |
F_146 ( V_606 ) |
F_146 ( V_607 ) ;
break;
case V_133 :
case V_132 :
V_120 -> V_597 = F_146 ( V_604 ) |
F_146 ( V_608 ) ;
break;
case V_128 :
V_120 -> V_597 = F_146 ( V_609 ) |
F_146 ( V_607 ) |
F_146 ( V_604 ) ;
default:
return - V_16 ;
}
for ( V_485 = 1 ; V_485 <= V_593 ; V_485 ++ ) {
if ( V_56 [ V_485 ] ) {
V_120 -> V_599 |= ( 1 << V_485 ) ;
if ( V_485 > V_610 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_147 ( struct V_44 * V_58 , struct V_611 * V_31 ,
int V_50 )
{
struct V_4 * V_173 ;
V_23 V_259 ;
T_3 V_612 ;
V_173 = F_50 ( V_58 , V_50 ) ;
if ( ! V_173 )
return false ;
V_259 = F_148 ( V_31 ) ;
V_612 = V_259 < ( 1UL << 16 ) ? V_259 : 0 ;
if ( V_259 > 0 &&
F_34 ( V_58 , V_613 , V_259 ) )
return false ;
if ( V_612 > 0 &&
F_57 ( V_58 , V_614 , V_612 ) )
return false ;
if ( V_31 -> V_56 & V_615 ) {
if ( F_56 ( V_58 , V_616 , V_31 -> V_240 ) )
return false ;
if ( V_31 -> V_56 & V_617 &&
F_35 ( V_58 , V_618 ) )
return false ;
if ( V_31 -> V_56 & V_619 &&
F_35 ( V_58 , V_620 ) )
return false ;
} else if ( V_31 -> V_56 & V_621 ) {
if ( F_56 ( V_58 , V_622 , V_31 -> V_240 ) )
return false ;
if ( F_56 ( V_58 , V_623 , V_31 -> V_624 ) )
return false ;
if ( V_31 -> V_56 & V_617 &&
F_35 ( V_58 , V_618 ) )
return false ;
if ( V_31 -> V_56 & V_625 &&
F_35 ( V_58 , V_626 ) )
return false ;
if ( V_31 -> V_56 & V_627 &&
F_35 ( V_58 , V_628 ) )
return false ;
if ( V_31 -> V_56 & V_629 &&
F_35 ( V_58 , V_630 ) )
return false ;
if ( V_31 -> V_56 & V_619 &&
F_35 ( V_58 , V_620 ) )
return false ;
}
F_51 ( V_58 , V_173 ) ;
return true ;
}
static int F_149 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 ,
struct V_6 * V_7 ,
struct V_26 * V_46 ,
const T_2 * V_519 , struct V_631 * V_632 )
{
void * V_162 ;
struct V_4 * V_633 , * V_634 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_635 ) ;
if ( ! V_162 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_519 ) ||
F_34 ( V_58 , V_178 , V_632 -> V_636 ) )
goto V_63;
V_633 = F_50 ( V_58 , V_637 ) ;
if ( ! V_633 )
goto V_63;
if ( ( V_632 -> V_638 & V_639 ) &&
F_34 ( V_58 , V_640 ,
V_632 -> V_641 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_642 ) &&
F_34 ( V_58 , V_643 ,
V_632 -> V_644 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_645 ) &&
F_34 ( V_58 , V_646 ,
V_632 -> V_647 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_648 ) &&
F_34 ( V_58 , V_649 ,
V_632 -> V_650 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_651 ) &&
F_57 ( V_58 , V_652 , V_632 -> V_653 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_654 ) &&
F_57 ( V_58 , V_655 , V_632 -> V_656 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_657 ) &&
F_56 ( V_58 , V_658 ,
V_632 -> V_659 ) )
goto V_63;
switch ( V_7 -> V_18 . V_660 ) {
case V_661 :
if ( ( V_632 -> V_638 & V_662 ) &&
F_56 ( V_58 , V_663 ,
V_632 -> signal ) )
goto V_63;
if ( ( V_632 -> V_638 & V_664 ) &&
F_56 ( V_58 , V_665 ,
V_632 -> V_666 ) )
goto V_63;
break;
default:
break;
}
if ( V_632 -> V_638 & V_667 ) {
if ( ! F_147 ( V_58 , & V_632 -> V_668 ,
V_669 ) )
goto V_63;
}
if ( V_632 -> V_638 & V_670 ) {
if ( ! F_147 ( V_58 , & V_632 -> V_671 ,
V_672 ) )
goto V_63;
}
if ( ( V_632 -> V_638 & V_673 ) &&
F_34 ( V_58 , V_674 ,
V_632 -> V_675 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_676 ) &&
F_34 ( V_58 , V_677 ,
V_632 -> V_678 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_679 ) &&
F_34 ( V_58 , V_680 ,
V_632 -> V_681 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_682 ) &&
F_34 ( V_58 , V_683 ,
V_632 -> V_684 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_685 ) &&
F_34 ( V_58 , V_686 ,
V_632 -> V_687 ) )
goto V_63;
if ( V_632 -> V_638 & V_688 ) {
V_634 = F_50 ( V_58 , V_689 ) ;
if ( ! V_634 )
goto V_63;
if ( ( ( V_632 -> V_634 . V_56 & V_690 ) &&
F_35 ( V_58 , V_691 ) ) ||
( ( V_632 -> V_634 . V_56 & V_692 ) &&
F_35 ( V_58 , V_693 ) ) ||
( ( V_632 -> V_634 . V_56 & V_694 ) &&
F_35 ( V_58 , V_695 ) ) ||
F_56 ( V_58 , V_696 ,
V_632 -> V_634 . V_568 ) ||
F_57 ( V_58 , V_697 ,
V_632 -> V_634 . V_429 ) )
goto V_63;
F_51 ( V_58 , V_634 ) ;
}
if ( ( V_632 -> V_638 & V_698 ) &&
F_58 ( V_58 , V_699 ,
sizeof( struct V_595 ) ,
& V_632 -> V_596 ) )
goto V_63;
if ( ( V_632 -> V_638 & V_700 ) &&
F_100 ( V_58 , V_701 ,
V_632 -> V_702 ) )
goto V_63;
F_51 ( V_58 , V_633 ) ;
if ( ( V_632 -> V_638 & V_703 ) &&
F_58 ( V_58 , V_538 , V_632 -> V_704 ,
V_632 -> V_705 ) )
goto V_63;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
static int F_150 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_631 V_632 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_519 [ V_470 ] ;
int V_706 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_226 -> V_707 ) {
V_47 = - V_428 ;
goto V_708;
}
while ( 1 ) {
memset ( & V_632 , 0 , sizeof( V_632 ) ) ;
V_47 = F_151 ( V_46 , V_20 , V_706 ,
V_519 , & V_632 ) ;
if ( V_47 == - V_526 )
break;
if ( V_47 )
goto V_708;
if ( F_149 ( V_45 ,
F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_390 , V_391 ,
V_46 , V_20 , V_519 ,
& V_632 ) < 0 )
goto V_481;
V_706 ++ ;
}
V_481:
V_35 -> args [ 1 ] = V_706 ;
V_47 = V_45 -> V_52 ;
V_708:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_152 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_631 V_632 ;
struct V_44 * V_58 ;
T_2 * V_519 = NULL ;
int V_47 ;
memset ( & V_632 , 0 , sizeof( V_632 ) ) ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
V_519 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( ! V_7 -> V_226 -> V_709 )
return - V_428 ;
V_47 = F_153 ( V_7 , V_46 , V_519 , & V_632 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_149 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_7 , V_46 , V_519 , & V_632 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static struct V_26 * F_154 ( struct V_30 * V_31 ,
struct V_6 * V_7 )
{
struct V_4 * V_710 = V_31 -> V_5 [ V_711 ] ;
struct V_26 * V_712 ;
int V_473 ;
if ( ! V_710 )
return NULL ;
V_712 = F_12 ( F_89 ( V_31 ) , F_4 ( V_710 ) ) ;
if ( ! V_712 )
return F_3 ( - V_24 ) ;
if ( ! V_712 -> V_29 || V_712 -> V_29 -> V_18 != & V_7 -> V_18 ) {
V_473 = - V_16 ;
goto error;
}
if ( ! F_86 ( V_712 ) ) {
V_473 = - V_442 ;
goto error;
}
return V_712 ;
error:
F_14 ( V_712 ) ;
return F_3 ( V_473 ) ;
}
static int F_155 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_592 V_120 ;
T_2 * V_519 = NULL ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_713 = - 1 ;
V_120 . V_659 = - 1 ;
if ( V_31 -> V_5 [ V_714 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
V_519 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( V_31 -> V_5 [ V_715 ] ) {
V_120 . V_716 =
F_29 ( V_31 -> V_5 [ V_715 ] ) ;
V_120 . V_717 =
F_30 ( V_31 -> V_5 [ V_715 ] ) ;
}
if ( V_31 -> V_5 [ V_718 ] )
V_120 . V_713 =
F_73 ( V_31 -> V_5 [ V_718 ] ) ;
if ( V_31 -> V_5 [ V_719 ] )
V_120 . V_720 =
F_29 ( V_31 -> V_5 [ V_719 ] ) ;
if ( ! V_7 -> V_226 -> V_721 )
return - V_428 ;
if ( F_145 ( V_31 , V_46 -> V_29 -> V_124 , & V_120 ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_722 ] )
V_120 . V_723 =
F_39 ( V_31 -> V_5 [ V_722 ] ) ;
if ( V_31 -> V_5 [ V_724 ] )
V_120 . V_659 =
F_39 ( V_31 -> V_5 [ V_724 ] ) ;
switch ( V_46 -> V_29 -> V_124 ) {
case V_125 :
case V_126 :
case V_127 :
if ( V_120 . V_723 )
return - V_16 ;
if ( V_120 . V_599 & F_146 ( V_608 ) )
return - V_16 ;
V_120 . V_597 &= ~ F_146 ( V_608 ) ;
if ( V_120 . V_597 &
~ ( F_146 ( V_604 ) |
F_146 ( V_605 ) |
F_146 ( V_606 ) |
F_146 ( V_607 ) ) )
return - V_16 ;
V_120 . V_725 = F_154 ( V_31 , V_7 ) ;
if ( F_16 ( V_120 . V_725 ) )
return F_24 ( V_120 . V_725 ) ;
break;
case V_133 :
case V_132 :
V_120 . V_597 &= ~ F_146 ( V_608 ) ;
case V_129 :
if ( V_120 . V_723 )
return - V_16 ;
if ( V_120 . V_720 )
return - V_16 ;
if ( V_120 . V_713 >= 0 )
return - V_16 ;
if ( V_120 . V_597 & ~ F_146 ( V_604 ) )
return - V_16 ;
break;
case V_128 :
if ( V_120 . V_725 )
return - V_16 ;
if ( V_120 . V_720 )
return - V_16 ;
if ( V_120 . V_713 >= 0 )
return - V_16 ;
if ( V_120 . V_597 &
~ ( F_146 ( V_609 ) |
F_146 ( V_607 ) |
F_146 ( V_604 ) ) )
return - V_16 ;
break;
default:
return - V_428 ;
}
V_47 = F_156 ( V_7 , V_46 , V_519 , & V_120 ) ;
if ( V_120 . V_725 )
F_14 ( V_120 . V_725 ) ;
return V_47 ;
}
static int F_157 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_592 V_120 ;
T_2 * V_519 = NULL ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_718 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_715 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_714 ] )
return - V_16 ;
V_519 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_120 . V_716 =
F_29 ( V_31 -> V_5 [ V_715 ] ) ;
V_120 . V_717 =
F_30 ( V_31 -> V_5 [ V_715 ] ) ;
V_120 . V_713 =
F_73 ( V_31 -> V_5 [ V_718 ] ) ;
V_120 . V_726 = F_73 ( V_31 -> V_5 [ V_714 ] ) ;
if ( ! V_120 . V_726 || V_120 . V_726 > V_727 )
return - V_16 ;
if ( V_31 -> V_5 [ V_719 ] )
V_120 . V_720 =
F_29 ( V_31 -> V_5 [ V_719 ] ) ;
if ( V_31 -> V_5 [ V_728 ] )
V_120 . V_729 =
F_29 ( V_31 -> V_5 [ V_728 ] ) ;
if ( V_31 -> V_5 [ V_722 ] )
V_120 . V_723 =
F_39 ( V_31 -> V_5 [ V_722 ] ) ;
if ( ! V_7 -> V_226 -> V_271 )
return - V_428 ;
if ( F_145 ( V_31 , V_46 -> V_29 -> V_124 , & V_120 ) )
return - V_16 ;
switch ( V_46 -> V_29 -> V_124 ) {
case V_125 :
case V_126 :
case V_127 :
if ( ( V_7 -> V_18 . V_56 & V_204 ) &&
( V_120 . V_599 & F_146 ( V_606 ) ) &&
V_31 -> V_5 [ V_730 ] ) {
struct V_4 * V_78 [ V_731 + 1 ] ;
struct V_4 * V_482 ;
V_482 = V_31 -> V_5 [ V_730 ] ;
V_47 = F_38 ( V_78 , V_731 , V_482 ,
V_732 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_733 ] )
V_120 . V_734 =
F_39 ( V_78 [ V_733 ] ) ;
if ( V_120 . V_734 &
~ V_735 )
return - V_16 ;
if ( V_78 [ V_736 ] )
V_120 . V_737 =
F_39 ( V_78 [ V_736 ] ) ;
if ( V_120 . V_737 &
~ V_738 )
return - V_16 ;
V_120 . V_739 |= V_740 ;
}
if ( V_120 . V_599 & F_146 ( V_608 ) )
return - V_16 ;
V_120 . V_597 &= ~ F_146 ( V_608 ) ;
V_120 . V_725 = F_154 ( V_31 , V_7 ) ;
if ( F_16 ( V_120 . V_725 ) )
return F_24 ( V_120 . V_725 ) ;
break;
case V_128 :
if ( V_120 . V_599 & F_146 ( V_608 ) )
return - V_16 ;
break;
case V_132 :
if ( ! ( V_120 . V_599 & F_146 ( V_608 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_56 & V_208 ) )
return - V_428 ;
if ( ! ( V_7 -> V_18 . V_56 & V_210 ) )
return - V_428 ;
break;
default:
return - V_428 ;
}
V_47 = F_158 ( V_7 , V_46 , V_519 , & V_120 ) ;
if ( V_120 . V_725 )
F_14 ( V_120 . V_725 ) ;
return V_47 ;
}
static int F_159 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 * V_519 = NULL ;
if ( V_31 -> V_5 [ V_433 ] )
V_519 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_126 &&
V_46 -> V_29 -> V_124 != V_128 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_741 )
return - V_428 ;
return F_160 ( V_7 , V_46 , V_519 ) ;
}
static int F_161 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
T_2 * V_742 , T_2 * V_743 ,
struct V_744 * V_745 )
{
void * V_162 ;
struct V_4 * V_746 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_635 ) ;
if ( ! V_162 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_742 ) ||
F_58 ( V_58 , V_747 , V_470 , V_743 ) ||
F_34 ( V_58 , V_178 , V_745 -> V_636 ) )
goto V_63;
V_746 = F_50 ( V_58 , V_748 ) ;
if ( ! V_746 )
goto V_63;
if ( ( V_745 -> V_638 & V_749 ) &&
F_34 ( V_58 , V_750 ,
V_745 -> V_751 ) )
goto V_63;
if ( ( ( V_745 -> V_638 & V_752 ) &&
F_34 ( V_58 , V_753 , V_745 -> V_754 ) ) ||
( ( V_745 -> V_638 & V_755 ) &&
F_34 ( V_58 , V_756 ,
V_745 -> V_757 ) ) ||
( ( V_745 -> V_638 & V_758 ) &&
F_34 ( V_58 , V_759 ,
V_745 -> V_760 ) ) ||
( ( V_745 -> V_638 & V_761 ) &&
F_56 ( V_58 , V_762 ,
V_745 -> V_56 ) ) ||
( ( V_745 -> V_638 & V_763 ) &&
F_34 ( V_58 , V_764 ,
V_745 -> V_765 ) ) ||
( ( V_745 -> V_638 & V_766 ) &&
F_56 ( V_58 , V_767 ,
V_745 -> V_768 ) ) )
goto V_63;
F_51 ( V_58 , V_746 ) ;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
static int F_162 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_744 V_745 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_742 [ V_470 ] ;
T_2 V_743 [ V_470 ] ;
int V_769 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_226 -> V_770 ) {
V_47 = - V_428 ;
goto V_708;
}
if ( V_20 -> V_29 -> V_124 != V_128 ) {
V_47 = - V_428 ;
goto V_708;
}
while ( 1 ) {
V_47 = F_163 ( V_46 , V_20 , V_769 , V_742 , V_743 ,
& V_745 ) ;
if ( V_47 == - V_526 )
break;
if ( V_47 )
goto V_708;
if ( F_161 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_390 , V_391 ,
V_20 , V_742 , V_743 ,
& V_745 ) < 0 )
goto V_481;
V_769 ++ ;
}
V_481:
V_35 -> args [ 1 ] = V_769 ;
V_47 = V_45 -> V_52 ;
V_708:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_164 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_744 V_745 ;
struct V_44 * V_58 ;
T_2 * V_742 = NULL ;
T_2 V_743 [ V_470 ] ;
memset ( & V_745 , 0 , sizeof( V_745 ) ) ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
V_742 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( ! V_7 -> V_226 -> V_771 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_128 )
return - V_428 ;
V_47 = F_165 ( V_7 , V_46 , V_742 , V_743 , & V_745 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_161 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_46 , V_742 , V_743 , & V_745 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_166 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 * V_742 = NULL ;
T_2 * V_743 = NULL ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_747 ] )
return - V_16 ;
V_742 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_743 = F_29 ( V_31 -> V_5 [ V_747 ] ) ;
if ( ! V_7 -> V_226 -> V_772 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_128 )
return - V_428 ;
return F_167 ( V_7 , V_46 , V_742 , V_743 ) ;
}
static int F_168 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 * V_742 = NULL ;
T_2 * V_743 = NULL ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_747 ] )
return - V_16 ;
V_742 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_743 = F_29 ( V_31 -> V_5 [ V_747 ] ) ;
if ( ! V_7 -> V_226 -> V_273 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_128 )
return - V_428 ;
return F_169 ( V_7 , V_46 , V_742 , V_743 ) ;
}
static int F_170 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 * V_742 = NULL ;
if ( V_31 -> V_5 [ V_433 ] )
V_742 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( ! V_7 -> V_226 -> V_773 )
return - V_428 ;
return F_171 ( V_7 , V_46 , V_742 ) ;
}
static int F_172 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_774 V_120 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_775 = - 1 ;
V_120 . V_776 = - 1 ;
V_120 . V_777 = - 1 ;
V_120 . V_778 = - 1 ;
V_120 . V_779 = - 1 ;
V_120 . V_584 = - 1 ;
V_120 . V_587 = - 1 ;
if ( V_31 -> V_5 [ V_780 ] )
V_120 . V_775 =
F_39 ( V_31 -> V_5 [ V_780 ] ) ;
if ( V_31 -> V_5 [ V_781 ] )
V_120 . V_776 =
F_39 ( V_31 -> V_5 [ V_781 ] ) ;
if ( V_31 -> V_5 [ V_782 ] )
V_120 . V_777 =
F_39 ( V_31 -> V_5 [ V_782 ] ) ;
if ( V_31 -> V_5 [ V_783 ] ) {
V_120 . V_784 =
F_29 ( V_31 -> V_5 [ V_783 ] ) ;
V_120 . V_785 =
F_30 ( V_31 -> V_5 [ V_783 ] ) ;
}
if ( V_31 -> V_5 [ V_786 ] )
V_120 . V_778 = ! ! F_39 ( V_31 -> V_5 [ V_786 ] ) ;
if ( V_31 -> V_5 [ V_787 ] )
V_120 . V_779 =
F_73 ( V_31 -> V_5 [ V_787 ] ) ;
if ( V_31 -> V_5 [ V_583 ] ) {
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_120 . V_584 =
F_173 ( V_31 -> V_5 [ V_583 ] ) ;
if ( V_120 . V_584 < 0 )
return - V_16 ;
if ( V_120 . V_584 != 0 &&
! ( V_7 -> V_18 . V_385 & V_585 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_586 ] ) {
T_2 V_25 ;
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_25 = F_39 ( V_31 -> V_5 [ V_586 ] ) ;
if ( V_25 > 1 )
return - V_16 ;
V_120 . V_587 = V_25 ;
if ( V_120 . V_587 &&
! ( V_7 -> V_18 . V_385 & V_588 ) )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_277 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_428 ;
return F_174 ( V_7 , V_46 , & V_120 ) ;
}
static int F_175 ( struct V_4 * V_78 [] ,
struct V_788 * V_789 )
{
struct V_790 * V_791 = & V_789 -> V_791 ;
struct V_792 * V_793 = & V_789 -> V_793 ;
if ( ! V_78 [ V_794 ] )
return - V_16 ;
if ( ! V_78 [ V_795 ] )
return - V_16 ;
if ( ! V_78 [ V_796 ] )
return - V_16 ;
if ( ! V_78 [ V_797 ] )
return - V_16 ;
if ( ! V_78 [ V_798 ] )
return - V_16 ;
V_789 -> V_56 = F_4 ( V_78 [ V_794 ] ) ;
V_791 -> V_799 =
F_4 ( V_78 [ V_795 ] ) ;
V_791 -> V_800 =
F_4 ( V_78 [ V_796 ] ) ;
V_791 -> V_801 =
F_4 ( V_78 [ V_797 ] ) ;
V_793 -> V_802 =
F_4 ( V_78 [ V_798 ] ) ;
if ( V_78 [ V_803 ] )
V_793 -> V_804 =
F_4 ( V_78 [ V_803 ] ) ;
return 0 ;
}
static int F_176 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
int V_805 ;
char * V_121 = NULL ;
enum V_806 V_807 ;
F_8 ( & V_32 ) ;
if ( F_177 ( ! V_808 ) ) {
F_9 ( & V_32 ) ;
return - V_809 ;
}
F_9 ( & V_32 ) ;
if ( ! V_31 -> V_5 [ V_810 ] )
return - V_16 ;
V_121 = F_29 ( V_31 -> V_5 [ V_810 ] ) ;
if ( V_31 -> V_5 [ V_811 ] )
V_807 =
F_4 ( V_31 -> V_5 [ V_811 ] ) ;
else
V_807 = V_812 ;
switch ( V_807 ) {
case V_812 :
case V_813 :
break;
default:
return - V_16 ;
}
V_805 = F_178 ( V_121 , V_807 ) ;
return V_805 ;
}
static int F_179 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_814 V_815 ;
int V_47 = 0 ;
void * V_162 ;
struct V_4 * V_746 ;
struct V_44 * V_58 ;
if ( V_17 -> V_124 != V_128 )
return - V_428 ;
if ( ! V_7 -> V_226 -> V_816 )
return - V_428 ;
F_108 ( V_17 ) ;
if ( ! V_17 -> V_817 )
memcpy ( & V_815 , & V_818 , sizeof( V_815 ) ) ;
else
V_47 = F_180 ( V_7 , V_46 , & V_815 ) ;
F_110 ( V_17 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_819 ) ;
if ( ! V_162 )
goto V_481;
V_746 = F_50 ( V_58 , V_820 ) ;
if ( ! V_746 )
goto V_63;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_57 ( V_58 , V_821 ,
V_815 . V_822 ) ||
F_57 ( V_58 , V_823 ,
V_815 . V_824 ) ||
F_57 ( V_58 , V_825 ,
V_815 . V_826 ) ||
F_57 ( V_58 , V_827 ,
V_815 . V_828 ) ||
F_56 ( V_58 , V_829 ,
V_815 . V_830 ) ||
F_56 ( V_58 , V_831 ,
V_815 . V_832 ) ||
F_56 ( V_58 , V_833 ,
V_815 . V_834 ) ||
F_56 ( V_58 , V_835 ,
V_815 . V_836 ) ||
F_34 ( V_58 , V_837 ,
V_815 . V_838 ) ||
F_56 ( V_58 , V_839 ,
V_815 . V_840 ) ||
F_34 ( V_58 , V_841 ,
V_815 . V_842 ) ||
F_57 ( V_58 , V_843 ,
V_815 . V_844 ) ||
F_34 ( V_58 , V_845 ,
V_815 . V_846 ) ||
F_57 ( V_58 , V_847 ,
V_815 . V_848 ) ||
F_57 ( V_58 , V_849 ,
V_815 . V_850 ) ||
F_57 ( V_58 , V_851 ,
V_815 . V_852 ) ||
F_56 ( V_58 , V_853 ,
V_815 . V_854 ) ||
F_57 ( V_58 , V_855 ,
V_815 . V_856 ) ||
F_56 ( V_58 , V_857 ,
V_815 . V_858 ) ||
F_56 ( V_58 , V_859 ,
V_815 . V_860 ) ||
F_34 ( V_58 , V_861 ,
V_815 . V_862 ) ||
F_34 ( V_58 , V_863 ,
V_815 . V_779 ) ||
F_34 ( V_58 , V_864 ,
V_815 . V_865 ) ||
F_57 ( V_58 , V_866 ,
V_815 . V_867 ) ||
F_57 ( V_58 , V_868 ,
V_815 . V_869 ) )
goto V_63;
F_51 ( V_58 , V_746 ) ;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
V_481:
F_70 ( V_58 ) ;
return - V_74 ;
}
static int F_181 ( struct V_30 * V_31 ,
struct V_814 * V_870 ,
V_23 * V_871 )
{
struct V_4 * V_78 [ V_872 + 1 ] ;
V_23 V_598 = 0 ;
#define F_182 ( T_6 , V_870 , T_7 , V_598 , T_8 , T_9 ) \
do {\
if (table[attr_num]) {\
cfg->param = nla_fn(table[attr_num]); \
mask |= (1 << (attr_num - 1)); \
} \
} while (0);\
if (!info->attrs[NL80211_ATTR_MESH_CONFIG])
return - V_16 ;
if ( F_38 ( V_78 , V_872 ,
V_31 -> V_5 [ V_820 ] ,
V_873 ) )
return - V_16 ;
F_109 ( V_872 > 32 ) ;
F_182 ( V_78 , V_870 , V_822 ,
V_598 , V_821 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_824 ,
V_598 , V_823 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_826 ,
V_598 , V_825 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_828 ,
V_598 , V_827 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_830 ,
V_598 , V_829 ,
F_39 ) ;
F_182 ( V_78 , V_870 , V_832 ,
V_598 , V_831 , F_39 ) ;
F_182 ( V_78 , V_870 , V_834 ,
V_598 , V_833 ,
F_39 ) ;
F_182 ( V_78 , V_870 , V_836 ,
V_598 , V_835 ,
F_39 ) ;
F_182 ( V_78 , V_870 , V_838 , V_598 ,
V_837 ,
F_4 ) ;
F_182 ( V_78 , V_870 , V_840 ,
V_598 , V_839 ,
F_39 ) ;
F_182 ( V_78 , V_870 , V_842 ,
V_598 , V_841 ,
F_4 ) ;
F_182 ( V_78 , V_870 , V_844 ,
V_598 , V_843 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_846 , V_598 ,
V_845 ,
F_4 ) ;
F_182 ( V_78 , V_870 , V_848 ,
V_598 , V_847 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_850 ,
V_598 , V_849 ,
F_73 ) ;
F_182 ( V_78 , V_870 ,
V_852 , V_598 ,
V_851 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_854 , V_598 ,
V_853 , F_39 ) ;
F_182 ( V_78 , V_870 , V_856 , V_598 ,
V_855 ,
F_73 ) ;
F_182 ( V_78 , V_870 ,
V_858 , V_598 ,
V_857 ,
F_39 ) ;
F_182 ( V_78 , V_870 , V_860 ,
V_598 , V_859 ,
F_39 ) ;
F_182 ( V_78 , V_870 , V_862 ,
V_598 , V_861 ,
F_4 ) ;
F_182 ( V_78 , V_870 , V_779 ,
V_598 , V_863 ,
F_73 ) ;
F_182 ( V_78 , V_870 , V_865 ,
V_598 ,
V_864 ,
F_4 ) ;
F_182 ( V_78 , V_870 , V_867 ,
V_598 , V_866 ,
F_73 ) ;
F_182 ( V_78 , V_870 ,
V_869 , V_598 ,
V_868 ,
F_73 ) ;
if ( V_871 )
* V_871 = V_598 ;
return 0 ;
#undef F_182
}
static int F_183 ( struct V_30 * V_31 ,
struct V_874 * V_875 )
{
struct V_4 * V_78 [ V_876 + 1 ] ;
if ( ! V_31 -> V_5 [ V_877 ] )
return - V_16 ;
if ( F_38 ( V_78 , V_876 ,
V_31 -> V_5 [ V_877 ] ,
V_878 ) )
return - V_16 ;
if ( V_78 [ V_879 ] )
V_875 -> V_880 =
( F_39 ( V_78 [ V_879 ] ) ) ?
V_881 :
V_882 ;
if ( V_78 [ V_883 ] )
V_875 -> V_884 =
( F_39 ( V_78 [ V_883 ] ) ) ?
V_885 :
V_886 ;
if ( V_78 [ V_887 ] )
V_875 -> V_888 =
( F_39 ( V_78 [ V_887 ] ) ) ?
V_889 :
V_890 ;
if ( V_78 [ V_891 ] ) {
struct V_4 * V_892 =
V_78 [ V_891 ] ;
if ( ! F_28 ( V_892 ) )
return - V_16 ;
V_875 -> V_893 = F_29 ( V_892 ) ;
V_875 -> V_894 = F_30 ( V_892 ) ;
}
V_875 -> V_895 = F_184 ( V_78 [ V_896 ] ) ;
V_875 -> V_897 = F_184 ( V_78 [ V_898 ] ) ;
return 0 ;
}
static int F_185 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_814 V_870 ;
V_23 V_598 ;
int V_47 ;
if ( V_17 -> V_124 != V_128 )
return - V_428 ;
if ( ! V_7 -> V_226 -> V_275 )
return - V_428 ;
V_47 = F_181 ( V_31 , & V_870 , & V_598 ) ;
if ( V_47 )
return V_47 ;
F_108 ( V_17 ) ;
if ( ! V_17 -> V_817 )
V_47 = - V_131 ;
if ( ! V_47 )
V_47 = F_186 ( V_7 , V_46 , V_598 , & V_870 ) ;
F_110 ( V_17 ) ;
return V_47 ;
}
static int F_187 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
void * V_162 = NULL ;
struct V_4 * V_899 ;
unsigned int V_138 ;
int V_47 = - V_16 ;
F_8 ( & V_32 ) ;
if ( ! V_808 )
goto V_481;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 ) {
V_47 = - V_74 ;
goto V_481;
}
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_900 ) ;
if ( ! V_162 )
goto V_901;
if ( F_54 ( V_58 , V_810 ,
V_808 -> V_902 ) ||
( V_808 -> V_903 &&
F_56 ( V_58 , V_904 ,
V_808 -> V_903 ) ) )
goto V_63;
if ( F_188 () &&
F_34 ( V_58 , V_811 ,
V_813 ) )
goto V_63;
V_899 = F_50 ( V_58 , V_905 ) ;
if ( ! V_899 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_808 -> V_906 ; V_138 ++ ) {
struct V_4 * V_907 ;
const struct V_788 * V_789 ;
const struct V_790 * V_791 ;
const struct V_792 * V_793 ;
V_789 = & V_808 -> V_908 [ V_138 ] ;
V_791 = & V_789 -> V_791 ;
V_793 = & V_789 -> V_793 ;
V_907 = F_50 ( V_58 , V_138 ) ;
if ( ! V_907 )
goto V_63;
if ( F_34 ( V_58 , V_794 ,
V_789 -> V_56 ) ||
F_34 ( V_58 , V_795 ,
V_791 -> V_799 ) ||
F_34 ( V_58 , V_796 ,
V_791 -> V_800 ) ||
F_34 ( V_58 , V_797 ,
V_791 -> V_801 ) ||
F_34 ( V_58 , V_803 ,
V_793 -> V_804 ) ||
F_34 ( V_58 , V_798 ,
V_793 -> V_802 ) )
goto V_63;
F_51 ( V_58 , V_907 ) ;
}
F_51 ( V_58 , V_899 ) ;
F_63 ( V_58 , V_162 ) ;
V_47 = F_71 ( V_58 , V_31 ) ;
goto V_481;
V_63:
F_64 ( V_58 , V_162 ) ;
V_901:
F_70 ( V_58 ) ;
V_47 = - V_388 ;
V_481:
F_9 ( & V_32 ) ;
return V_47 ;
}
static int F_189 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_909 + 1 ] ;
struct V_4 * V_907 ;
char * V_902 = NULL ;
int V_910 = 0 , V_805 = 0 ;
V_23 V_911 = 0 , V_912 = 0 , V_913 ;
T_2 V_903 = 0 ;
struct V_914 * V_915 = NULL ;
if ( ! V_31 -> V_5 [ V_810 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_905 ] )
return - V_16 ;
V_902 = F_29 ( V_31 -> V_5 [ V_810 ] ) ;
if ( V_31 -> V_5 [ V_904 ] )
V_903 = F_39 ( V_31 -> V_5 [ V_904 ] ) ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_911 ++ ;
if ( V_911 > V_916 )
return - V_16 ;
}
F_8 ( & V_32 ) ;
if ( ! F_190 ( V_902 ) ) {
V_805 = - V_16 ;
goto V_917;
}
V_913 = sizeof( struct V_914 ) +
( V_911 * sizeof( struct V_788 ) ) ;
V_915 = F_43 ( V_913 , V_118 ) ;
if ( ! V_915 ) {
V_805 = - V_119 ;
goto V_917;
}
V_915 -> V_906 = V_911 ;
V_915 -> V_902 [ 0 ] = V_902 [ 0 ] ;
V_915 -> V_902 [ 1 ] = V_902 [ 1 ] ;
if ( F_191 ( V_903 ) )
V_915 -> V_903 = V_903 ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_91 ( V_78 , V_909 ,
F_29 ( V_907 ) , F_30 ( V_907 ) ,
V_918 ) ;
V_805 = F_175 ( V_78 , & V_915 -> V_908 [ V_912 ] ) ;
if ( V_805 )
goto V_917;
V_912 ++ ;
if ( V_912 > V_916 ) {
V_805 = - V_16 ;
goto V_917;
}
}
F_192 ( V_912 != V_911 ) ;
V_805 = F_193 ( V_915 ) ;
F_9 ( & V_32 ) ;
return V_805 ;
V_917:
F_9 ( & V_32 ) ;
F_46 ( V_915 ) ;
return V_805 ;
}
static int F_194 ( struct V_4 * V_919 )
{
struct V_4 * V_920 , * V_921 ;
int V_253 = 0 , V_922 , V_923 ;
F_44 (attr1, freqs, tmp1) {
V_253 ++ ;
F_44 (attr2, freqs, tmp2)
if ( V_920 != V_921 &&
F_4 ( V_920 ) == F_4 ( V_921 ) )
return 0 ;
}
return V_253 ;
}
static int F_195 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
struct V_924 * V_925 ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_926 = 0 , V_253 , V_138 ;
T_10 V_894 ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_226 -> V_927 )
return - V_428 ;
if ( V_7 -> V_928 )
return - V_430 ;
if ( V_31 -> V_5 [ V_929 ] ) {
V_253 = F_194 (
V_31 -> V_5 [ V_929 ] ) ;
if ( ! V_253 )
return - V_16 ;
} else {
enum V_170 V_171 ;
V_253 = 0 ;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ )
if ( V_18 -> V_236 [ V_171 ] )
V_253 += V_18 -> V_236 [ V_171 ] -> V_253 ;
}
if ( V_31 -> V_5 [ V_930 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_926 ++ ;
if ( V_926 > V_18 -> V_191 )
return - V_16 ;
if ( V_31 -> V_5 [ V_538 ] )
V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
else
V_894 = 0 ;
if ( V_894 > V_18 -> V_195 )
return - V_16 ;
V_925 = F_43 ( sizeof( * V_925 )
+ sizeof( * V_925 -> V_931 ) * V_926
+ sizeof( * V_925 -> V_254 ) * V_253
+ V_894 , V_118 ) ;
if ( ! V_925 )
return - V_119 ;
if ( V_926 )
V_925 -> V_931 = ( void * ) & V_925 -> V_254 [ V_253 ] ;
V_925 -> V_926 = V_926 ;
if ( V_894 ) {
if ( V_925 -> V_931 )
V_925 -> V_893 = ( void * ) ( V_925 -> V_931 + V_926 ) ;
else
V_925 -> V_893 = ( void * ) ( V_925 -> V_254 + V_253 ) ;
}
V_138 = 0 ;
if ( V_31 -> V_5 [ V_929 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_59 * V_60 ;
V_60 = F_76 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_932;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_925 -> V_254 [ V_138 ] = V_60 ;
V_138 ++ ;
}
} else {
enum V_170 V_171 ;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ ) {
int V_140 ;
if ( ! V_18 -> V_236 [ V_171 ] )
continue;
for ( V_140 = 0 ; V_140 < V_18 -> V_236 [ V_171 ] -> V_253 ; V_140 ++ ) {
struct V_59 * V_60 ;
V_60 = & V_18 -> V_236 [ V_171 ] -> V_254 [ V_140 ] ;
if ( V_60 -> V_56 & V_64 )
continue;
V_925 -> V_254 [ V_138 ] = V_60 ;
V_138 ++ ;
}
}
}
if ( ! V_138 ) {
V_47 = - V_16 ;
goto V_932;
}
V_925 -> V_253 = V_138 ;
V_138 = 0 ;
if ( V_31 -> V_5 [ V_930 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_30 ( V_50 ) > V_499 ) {
V_47 = - V_16 ;
goto V_932;
}
V_925 -> V_931 [ V_138 ] . V_474 = F_30 ( V_50 ) ;
memcpy ( V_925 -> V_931 [ V_138 ] . V_476 , F_29 ( V_50 ) , F_30 ( V_50 ) ) ;
V_138 ++ ;
}
}
if ( V_31 -> V_5 [ V_538 ] ) {
V_925 -> V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
memcpy ( ( void * ) V_925 -> V_893 ,
F_29 ( V_31 -> V_5 [ V_538 ] ) ,
V_925 -> V_894 ) ;
}
for ( V_138 = 0 ; V_138 < V_235 ; V_138 ++ )
if ( V_18 -> V_236 [ V_138 ] )
V_925 -> V_933 [ V_138 ] =
( 1 << V_18 -> V_236 [ V_138 ] -> V_256 ) - 1 ;
if ( V_31 -> V_5 [ V_934 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_170 V_171 = F_196 ( V_50 ) ;
if ( V_171 < 0 || V_171 >= V_235 ) {
V_47 = - V_16 ;
goto V_932;
}
V_47 = F_197 ( V_18 -> V_236 [ V_171 ] ,
F_29 ( V_50 ) ,
F_30 ( V_50 ) ,
& V_925 -> V_933 [ V_171 ] ) ;
if ( V_47 )
goto V_932;
}
}
if ( V_31 -> V_5 [ V_935 ] ) {
V_925 -> V_56 = F_4 (
V_31 -> V_5 [ V_935 ] ) ;
if ( ( ( V_925 -> V_56 & V_936 ) &&
! ( V_18 -> V_385 & V_937 ) ) ||
( ( V_925 -> V_56 & V_938 ) &&
! ( V_18 -> V_385 & V_939 ) ) ) {
V_47 = - V_428 ;
goto V_932;
}
}
V_925 -> V_940 =
F_184 ( V_31 -> V_5 [ V_941 ] ) ;
V_925 -> V_17 = V_17 ;
V_925 -> V_18 = & V_7 -> V_18 ;
V_925 -> V_942 = V_943 ;
V_7 -> V_928 = V_925 ;
V_47 = F_198 ( V_7 , V_925 ) ;
if ( ! V_47 ) {
F_199 ( V_7 , V_17 ) ;
if ( V_17 -> V_20 )
F_200 ( V_17 -> V_20 ) ;
} else {
V_932:
V_7 -> V_928 = NULL ;
F_46 ( V_925 ) ;
}
return V_47 ;
}
static int F_201 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_944 * V_925 ;
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_926 = 0 , V_945 = 0 , V_253 , V_138 ;
V_23 V_946 ;
enum V_170 V_171 ;
T_10 V_894 ;
struct V_4 * V_78 [ V_947 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_56 & V_316 ) ||
! V_7 -> V_226 -> V_317 )
return - V_428 ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_948 ] )
return - V_16 ;
V_946 = F_4 ( V_31 -> V_5 [ V_948 ] ) ;
if ( V_946 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_929 ] ) {
V_253 = F_194 (
V_31 -> V_5 [ V_929 ] ) ;
if ( ! V_253 )
return - V_16 ;
} else {
V_253 = 0 ;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ )
if ( V_18 -> V_236 [ V_171 ] )
V_253 += V_18 -> V_236 [ V_171 ] -> V_253 ;
}
if ( V_31 -> V_5 [ V_930 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_926 ++ ;
if ( V_926 > V_18 -> V_193 )
return - V_16 ;
if ( V_31 -> V_5 [ V_949 ] )
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_945 ++ ;
if ( V_945 > V_18 -> V_199 )
return - V_16 ;
if ( V_31 -> V_5 [ V_538 ] )
V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
else
V_894 = 0 ;
if ( V_894 > V_18 -> V_197 )
return - V_16 ;
F_8 ( & V_7 -> V_950 ) ;
if ( V_7 -> V_951 ) {
V_47 = - V_809 ;
goto V_481;
}
V_925 = F_43 ( sizeof( * V_925 )
+ sizeof( * V_925 -> V_931 ) * V_926
+ sizeof( * V_925 -> V_952 ) * V_945
+ sizeof( * V_925 -> V_254 ) * V_253
+ V_894 , V_118 ) ;
if ( ! V_925 ) {
V_47 = - V_119 ;
goto V_481;
}
if ( V_926 )
V_925 -> V_931 = ( void * ) & V_925 -> V_254 [ V_253 ] ;
V_925 -> V_926 = V_926 ;
if ( V_894 ) {
if ( V_925 -> V_931 )
V_925 -> V_893 = ( void * ) ( V_925 -> V_931 + V_926 ) ;
else
V_925 -> V_893 = ( void * ) ( V_925 -> V_254 + V_253 ) ;
}
if ( V_945 ) {
if ( V_925 -> V_893 )
V_925 -> V_952 = ( void * ) ( V_925 -> V_893 + V_894 ) ;
else if ( V_925 -> V_931 )
V_925 -> V_952 =
( void * ) ( V_925 -> V_931 + V_926 ) ;
else
V_925 -> V_952 =
( void * ) ( V_925 -> V_254 + V_253 ) ;
}
V_925 -> V_945 = V_945 ;
V_138 = 0 ;
if ( V_31 -> V_5 [ V_929 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_59 * V_60 ;
V_60 = F_76 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_932;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_925 -> V_254 [ V_138 ] = V_60 ;
V_138 ++ ;
}
} else {
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ ) {
int V_140 ;
if ( ! V_18 -> V_236 [ V_171 ] )
continue;
for ( V_140 = 0 ; V_140 < V_18 -> V_236 [ V_171 ] -> V_253 ; V_140 ++ ) {
struct V_59 * V_60 ;
V_60 = & V_18 -> V_236 [ V_171 ] -> V_254 [ V_140 ] ;
if ( V_60 -> V_56 & V_64 )
continue;
V_925 -> V_254 [ V_138 ] = V_60 ;
V_138 ++ ;
}
}
}
if ( ! V_138 ) {
V_47 = - V_16 ;
goto V_932;
}
V_925 -> V_253 = V_138 ;
V_138 = 0 ;
if ( V_31 -> V_5 [ V_930 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_30 ( V_50 ) > V_499 ) {
V_47 = - V_16 ;
goto V_932;
}
V_925 -> V_931 [ V_138 ] . V_474 = F_30 ( V_50 ) ;
memcpy ( V_925 -> V_931 [ V_138 ] . V_476 , F_29 ( V_50 ) ,
F_30 ( V_50 ) ) ;
V_138 ++ ;
}
}
V_138 = 0 ;
if ( V_31 -> V_5 [ V_949 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_476 , * V_953 ;
F_91 ( V_78 , V_947 ,
F_29 ( V_50 ) , F_30 ( V_50 ) ,
V_954 ) ;
V_476 = V_78 [ V_955 ] ;
if ( V_476 ) {
if ( F_30 ( V_476 ) > V_499 ) {
V_47 = - V_16 ;
goto V_932;
}
memcpy ( V_925 -> V_952 [ V_138 ] . V_476 . V_476 ,
F_29 ( V_476 ) , F_30 ( V_476 ) ) ;
V_925 -> V_952 [ V_138 ] . V_476 . V_474 =
F_30 ( V_476 ) ;
}
V_953 = V_78 [ V_956 ] ;
if ( V_953 )
V_925 -> V_957 = F_4 ( V_953 ) ;
else
V_925 -> V_957 =
V_958 ;
V_138 ++ ;
}
}
if ( V_31 -> V_5 [ V_538 ] ) {
V_925 -> V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
memcpy ( ( void * ) V_925 -> V_893 ,
F_29 ( V_31 -> V_5 [ V_538 ] ) ,
V_925 -> V_894 ) ;
}
if ( V_31 -> V_5 [ V_935 ] ) {
V_925 -> V_56 = F_4 (
V_31 -> V_5 [ V_935 ] ) ;
if ( ( ( V_925 -> V_56 & V_936 ) &&
! ( V_18 -> V_385 & V_937 ) ) ||
( ( V_925 -> V_56 & V_938 ) &&
! ( V_18 -> V_385 & V_939 ) ) ) {
V_47 = - V_428 ;
goto V_932;
}
}
V_925 -> V_46 = V_46 ;
V_925 -> V_18 = & V_7 -> V_18 ;
V_925 -> V_946 = V_946 ;
V_925 -> V_942 = V_943 ;
V_47 = F_202 ( V_7 , V_46 , V_925 ) ;
if ( ! V_47 ) {
V_7 -> V_951 = V_925 ;
F_203 ( V_7 , V_46 ,
V_959 ) ;
goto V_481;
}
V_932:
F_46 ( V_925 ) ;
V_481:
F_9 ( & V_7 -> V_950 ) ;
return V_47 ;
}
static int F_204 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
if ( ! ( V_7 -> V_18 . V_56 & V_316 ) ||
! V_7 -> V_226 -> V_960 )
return - V_428 ;
F_8 ( & V_7 -> V_950 ) ;
V_47 = F_205 ( V_7 , false ) ;
F_9 ( & V_7 -> V_950 ) ;
return V_47 ;
}
static int F_206 ( struct V_44 * V_58 , struct V_34 * V_35 ,
V_23 V_55 , int V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_961 * V_962 )
{
struct V_963 * V_36 = & V_962 -> V_964 ;
const struct V_965 * V_966 ;
void * V_162 ;
struct V_4 * V_967 ;
F_48 ( V_17 ) ;
V_162 = F_31 ( V_58 , F_67 ( V_35 -> V_45 ) . V_54 , V_55 , V_56 ,
V_968 ) ;
if ( ! V_162 )
return - 1 ;
F_207 ( V_35 , V_162 , & V_39 ) ;
if ( F_34 ( V_58 , V_178 , V_7 -> V_969 ) ||
F_34 ( V_58 , V_10 , V_17 -> V_20 -> V_21 ) )
goto V_63;
V_967 = F_50 ( V_58 , V_970 ) ;
if ( ! V_967 )
goto V_63;
if ( ( ! F_208 ( V_36 -> V_432 ) &&
F_58 ( V_58 , V_971 , V_470 , V_36 -> V_432 ) ) )
goto V_63;
F_209 () ;
V_966 = F_210 ( V_36 -> V_966 ) ;
if ( V_966 && V_966 -> V_52 && F_58 ( V_58 , V_972 ,
V_966 -> V_52 , V_966 -> V_121 ) ) {
F_211 () ;
goto V_63;
}
V_966 = F_210 ( V_36 -> V_546 ) ;
if ( V_966 && V_966 -> V_52 && F_58 ( V_58 , V_973 ,
V_966 -> V_52 , V_966 -> V_121 ) ) {
F_211 () ;
goto V_63;
}
F_211 () ;
if ( V_36 -> V_974 &&
F_100 ( V_58 , V_975 , V_36 -> V_974 ) )
goto V_63;
if ( V_36 -> V_429 &&
F_57 ( V_58 , V_976 , V_36 -> V_429 ) )
goto V_63;
if ( F_57 ( V_58 , V_977 , V_36 -> V_978 ) ||
F_34 ( V_58 , V_979 , V_36 -> V_590 -> V_62 ) ||
F_34 ( V_58 , V_980 ,
F_212 ( V_943 - V_962 -> V_981 ) ) )
goto V_63;
switch ( V_7 -> V_18 . V_660 ) {
case V_661 :
if ( F_34 ( V_58 , V_982 , V_36 -> signal ) )
goto V_63;
break;
case V_983 :
if ( F_56 ( V_58 , V_984 , V_36 -> signal ) )
goto V_63;
break;
default:
break;
}
switch ( V_17 -> V_124 ) {
case V_133 :
case V_132 :
if ( V_962 == V_17 -> V_130 &&
F_34 ( V_58 , V_985 ,
V_986 ) )
goto V_63;
break;
case V_129 :
if ( V_962 == V_17 -> V_130 &&
F_34 ( V_58 , V_985 ,
V_987 ) )
goto V_63;
break;
default:
break;
}
F_51 ( V_58 , V_967 ) ;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
static int F_213 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
struct V_26 * V_46 ;
struct V_961 * V_927 ;
struct V_1 * V_17 ;
int V_389 = V_35 -> args [ 1 ] , V_88 = 0 ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_7 , & V_46 ) ;
if ( V_47 )
return V_47 ;
V_17 = V_46 -> V_29 ;
F_108 ( V_17 ) ;
F_214 ( & V_7 -> V_988 ) ;
F_215 ( V_7 ) ;
V_35 -> V_55 = V_7 -> V_969 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_88 <= V_389 )
continue;
if ( F_206 ( V_45 , V_35 ,
V_35 -> V_37 -> V_390 , V_391 ,
V_7 , V_17 , V_927 ) < 0 ) {
V_88 -- ;
break;
}
}
F_216 ( & V_7 -> V_988 ) ;
F_110 ( V_17 ) ;
V_35 -> args [ 1 ] = V_88 ;
F_26 ( V_7 ) ;
return V_45 -> V_52 ;
}
static int F_217 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
struct V_989 * V_990 )
{
void * V_162 ;
struct V_4 * V_991 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 ,
V_992 ) ;
if ( ! V_162 )
return - V_119 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) )
goto V_63;
V_991 = F_50 ( V_58 , V_993 ) ;
if ( ! V_991 )
goto V_63;
if ( F_34 ( V_58 , V_994 ,
V_990 -> V_590 -> V_62 ) )
goto V_63;
if ( ( V_990 -> V_638 & V_995 ) &&
F_56 ( V_58 , V_996 , V_990 -> V_997 ) )
goto V_63;
if ( ( V_990 -> V_638 & V_998 ) &&
F_35 ( V_58 , V_999 ) )
goto V_63;
if ( ( V_990 -> V_638 & V_1000 ) &&
F_100 ( V_58 , V_1001 ,
V_990 -> V_1002 ) )
goto V_63;
if ( ( V_990 -> V_638 & V_1003 ) &&
F_100 ( V_58 , V_1004 ,
V_990 -> V_1005 ) )
goto V_63;
if ( ( V_990 -> V_638 & V_1006 ) &&
F_100 ( V_58 , V_1007 ,
V_990 -> V_1008 ) )
goto V_63;
if ( ( V_990 -> V_638 & V_1009 ) &&
F_100 ( V_58 , V_1010 ,
V_990 -> V_1011 ) )
goto V_63;
if ( ( V_990 -> V_638 & V_1012 ) &&
F_100 ( V_58 , V_1013 ,
V_990 -> V_1014 ) )
goto V_63;
F_51 ( V_58 , V_991 ) ;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
static int F_218 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_989 V_990 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
int V_1015 = V_35 -> args [ 1 ] ;
int V_36 ;
V_36 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_46 -> V_226 -> V_1016 ) {
V_36 = - V_428 ;
goto V_708;
}
while ( 1 ) {
struct V_59 * V_60 ;
V_36 = F_219 ( V_46 , V_20 , V_1015 , & V_990 ) ;
if ( V_36 == - V_526 )
break;
if ( V_36 )
goto V_708;
if ( ! V_990 . V_590 ) {
V_36 = - V_16 ;
goto V_481;
}
V_60 = F_76 ( & V_46 -> V_18 ,
V_990 . V_590 -> V_62 ) ;
if ( ! V_60 || V_60 -> V_56 & V_64 ) {
V_1015 ++ ;
continue;
}
if ( F_217 ( V_45 ,
F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_390 , V_391 ,
V_20 ,
& V_990 ) < 0 )
goto V_481;
V_1015 ++ ;
}
V_481:
V_35 -> args [ 1 ] = V_1015 ;
V_36 = V_45 -> V_52 ;
V_708:
F_26 ( V_46 ) ;
return V_36 ;
}
static bool F_220 ( V_23 V_1017 )
{
return ! ( V_1017 & ~ ( V_1018 |
V_1019 ) ) ;
}
static int F_221 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_59 * V_60 ;
const T_2 * V_432 , * V_476 , * V_893 = NULL , * V_1020 = NULL ;
int V_47 , V_474 , V_894 = 0 , V_1021 = 0 ;
enum V_556 V_557 ;
struct V_76 V_75 ;
bool V_1022 ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_576 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_475 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_413 ] )
return - V_16 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 >= 0 ) {
if ( V_75 . type != - 1 && V_75 . type != V_522 )
return - V_16 ;
if ( ! V_75 . V_90 . V_75 || ! V_75 . V_90 . V_91 )
return - V_16 ;
if ( ( V_75 . V_90 . V_95 != V_122 ||
V_75 . V_90 . V_91 != V_1023 ) &&
( V_75 . V_90 . V_95 != V_123 ||
V_75 . V_90 . V_91 != V_1024 ) )
return - V_16 ;
if ( V_75 . V_88 > 4 )
return - V_16 ;
} else {
V_75 . V_90 . V_91 = 0 ;
V_75 . V_90 . V_75 = NULL ;
}
if ( V_75 . V_88 >= 0 ) {
int V_138 ;
bool V_1025 = false ;
for ( V_138 = 0 ; V_138 < V_7 -> V_18 . V_213 ; V_138 ++ ) {
if ( V_75 . V_90 . V_95 == V_7 -> V_18 . V_214 [ V_138 ] ) {
V_1025 = true ;
break;
}
}
if ( ! V_1025 )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_279 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_60 = F_76 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_413 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_476 = F_29 ( V_31 -> V_5 [ V_475 ] ) ;
V_474 = F_30 ( V_31 -> V_5 [ V_475 ] ) ;
if ( V_31 -> V_5 [ V_538 ] ) {
V_893 = F_29 ( V_31 -> V_5 [ V_538 ] ) ;
V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
}
V_557 = F_4 ( V_31 -> V_5 [ V_576 ] ) ;
if ( ! F_135 ( V_7 , V_557 , V_560 ) )
return - V_16 ;
if ( V_557 == V_562 &&
! V_31 -> V_5 [ V_1026 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_1026 ] ) {
if ( V_557 != V_562 )
return - V_16 ;
V_1020 = F_29 ( V_31 -> V_5 [ V_1026 ] ) ;
V_1021 = F_30 ( V_31 -> V_5 [ V_1026 ] ) ;
if ( V_1021 < 4 )
return - V_16 ;
}
V_1022 = ! ! V_31 -> V_5 [ V_1027 ] ;
if ( V_1022 )
return 0 ;
return F_222 ( V_7 , V_46 , V_60 , V_557 , V_432 ,
V_476 , V_474 , V_893 , V_894 ,
V_75 . V_90 . V_75 , V_75 . V_90 . V_91 , V_75 . V_88 ,
V_1020 , V_1021 ) ;
}
static int F_138 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_1028 * V_1029 ,
int V_1030 )
{
memset ( V_1029 , 0 , sizeof( * V_1029 ) ) ;
V_1029 -> V_1031 = V_31 -> V_5 [ V_1032 ] ;
if ( V_31 -> V_5 [ V_218 ] ) {
T_3 V_1033 ;
V_1033 = F_73 (
V_31 -> V_5 [ V_218 ] ) ;
V_1029 -> V_1034 = F_223 ( V_1033 ) ;
if ( ! ( V_7 -> V_18 . V_56 & V_217 ) &&
V_1033 != V_1035 )
return - V_16 ;
if ( V_31 -> V_5 [ V_1036 ] )
V_1029 -> V_1037 = true ;
} else
V_1029 -> V_1034 = F_223 ( V_1035 ) ;
if ( V_31 -> V_5 [ V_1038 ] ) {
void * V_121 ;
int V_52 , V_138 ;
V_121 = F_29 ( V_31 -> V_5 [ V_1038 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_1038 ] ) ;
V_1029 -> V_1039 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_1029 -> V_1039 > V_1030 )
return - V_16 ;
memcpy ( V_1029 -> V_1040 , V_121 , V_52 ) ;
for ( V_138 = 0 ; V_138 < V_1029 -> V_1039 ; V_138 ++ )
if ( ! F_224 (
& V_7 -> V_18 ,
V_1029 -> V_1040 [ V_138 ] ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1041 ] ) {
V_1029 -> V_1042 =
F_4 ( V_31 -> V_5 [ V_1041 ] ) ;
if ( ! F_224 ( & V_7 -> V_18 ,
V_1029 -> V_1042 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1043 ] ) {
V_1029 -> V_1017 =
F_4 ( V_31 -> V_5 [ V_1043 ] ) ;
if ( ! F_220 ( V_1029 -> V_1017 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1044 ] ) {
void * V_121 ;
int V_52 ;
V_121 = F_29 ( V_31 -> V_5 [ V_1044 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_1044 ] ) ;
V_1029 -> V_1045 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_1029 -> V_1045 > V_1046 )
return - V_16 ;
memcpy ( V_1029 -> V_1047 , V_121 , V_52 ) ;
}
return 0 ;
}
static int F_225 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1028 V_578 ;
struct V_59 * V_60 ;
const T_2 * V_432 , * V_476 , * V_893 = NULL , * V_1048 = NULL ;
int V_47 , V_474 , V_894 = 0 ;
bool V_1049 = false ;
V_23 V_56 = 0 ;
struct V_1050 * V_720 = NULL ;
struct V_1050 * V_1051 = NULL ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_433 ] ||
! V_31 -> V_5 [ V_475 ] ||
! V_31 -> V_5 [ V_413 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_281 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_60 = F_76 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_413 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_476 = F_29 ( V_31 -> V_5 [ V_475 ] ) ;
V_474 = F_30 ( V_31 -> V_5 [ V_475 ] ) ;
if ( V_31 -> V_5 [ V_538 ] ) {
V_893 = F_29 ( V_31 -> V_5 [ V_538 ] ) ;
V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
}
if ( V_31 -> V_5 [ V_1052 ] ) {
enum V_1053 V_1054 =
F_4 ( V_31 -> V_5 [ V_1052 ] ) ;
if ( V_1054 == V_1055 )
V_1049 = true ;
else if ( V_1054 != V_1056 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1057 ] )
V_1048 = F_29 ( V_31 -> V_5 [ V_1057 ] ) ;
if ( F_184 ( V_31 -> V_5 [ V_1058 ] ) )
V_56 |= V_1059 ;
if ( V_31 -> V_5 [ V_387 ] )
V_1051 =
F_29 ( V_31 -> V_5 [ V_387 ] ) ;
if ( V_31 -> V_5 [ V_719 ] ) {
if ( ! V_1051 )
return - V_16 ;
V_720 = F_29 ( V_31 -> V_5 [ V_719 ] ) ;
}
V_47 = F_138 ( V_7 , V_31 , & V_578 , 1 ) ;
if ( ! V_47 )
V_47 = F_226 ( V_7 , V_46 , V_60 , V_432 , V_1048 ,
V_476 , V_474 , V_893 , V_894 , V_1049 ,
& V_578 , V_56 , V_720 ,
V_1051 ) ;
return V_47 ;
}
static int F_227 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
const T_2 * V_893 = NULL , * V_432 ;
int V_894 = 0 ;
T_3 V_1060 ;
bool V_1022 ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1061 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_283 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_1060 = F_73 ( V_31 -> V_5 [ V_1061 ] ) ;
if ( V_1060 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_538 ] ) {
V_893 = F_29 ( V_31 -> V_5 [ V_538 ] ) ;
V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
}
V_1022 = ! ! V_31 -> V_5 [ V_1027 ] ;
return F_228 ( V_7 , V_46 , V_432 , V_893 , V_894 , V_1060 ,
V_1022 ) ;
}
static int F_229 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
const T_2 * V_893 = NULL , * V_432 ;
int V_894 = 0 ;
T_3 V_1060 ;
bool V_1022 ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1061 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_285 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_1060 = F_73 ( V_31 -> V_5 [ V_1061 ] ) ;
if ( V_1060 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_538 ] ) {
V_893 = F_29 ( V_31 -> V_5 [ V_538 ] ) ;
V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
}
V_1022 = ! ! V_31 -> V_5 [ V_1027 ] ;
return F_230 ( V_7 , V_46 , V_432 , V_893 , V_894 , V_1060 ,
V_1022 ) ;
}
static bool
F_231 ( struct V_6 * V_7 ,
int V_1062 [ V_235 ] ,
int V_1063 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_28 = false ;
int V_171 , V_138 ;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ ) {
struct V_1064 * V_1065 ;
V_1065 = V_18 -> V_236 [ V_171 ] ;
if ( ! V_1065 )
continue;
for ( V_138 = 0 ; V_138 < V_1065 -> V_256 ; V_138 ++ ) {
if ( V_1065 -> V_257 [ V_138 ] . V_259 == V_1063 ) {
V_1062 [ V_171 ] = V_138 + 1 ;
V_28 = true ;
break;
}
}
}
return V_28 ;
}
static int F_232 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1066 V_1067 ;
struct V_18 * V_18 ;
struct V_113 * V_1068 = NULL ;
int V_47 ;
memset ( & V_1067 , 0 , sizeof( V_1067 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_475 ] ||
! F_30 ( V_31 -> V_5 [ V_475 ] ) )
return - V_16 ;
V_1067 . V_429 = 100 ;
if ( V_31 -> V_5 [ V_565 ] ) {
V_1067 . V_429 =
F_4 ( V_31 -> V_5 [ V_565 ] ) ;
if ( V_1067 . V_429 < 1 || V_1067 . V_429 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_287 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_129 )
return - V_428 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_433 ] ) {
V_1067 . V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( ! F_233 ( V_1067 . V_432 ) )
return - V_16 ;
}
V_1067 . V_476 = F_29 ( V_31 -> V_5 [ V_475 ] ) ;
V_1067 . V_474 = F_30 ( V_31 -> V_5 [ V_475 ] ) ;
if ( V_31 -> V_5 [ V_538 ] ) {
V_1067 . V_893 = F_29 ( V_31 -> V_5 [ V_538 ] ) ;
V_1067 . V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
}
V_47 = F_75 ( V_7 , V_31 , & V_1067 . V_411 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_81 ( & V_7 -> V_18 , & V_1067 . V_411 ) )
return - V_16 ;
if ( V_1067 . V_411 . V_414 > V_465 )
return - V_16 ;
if ( V_1067 . V_411 . V_414 != V_415 &&
! ( V_7 -> V_18 . V_385 & V_1069 ) )
return - V_16 ;
V_1067 . V_1070 = ! ! V_31 -> V_5 [ V_1071 ] ;
V_1067 . V_574 = ! ! V_31 -> V_5 [ V_575 ] ;
if ( V_31 -> V_5 [ V_783 ] ) {
T_2 * V_933 =
F_29 ( V_31 -> V_5 [ V_783 ] ) ;
int V_1072 =
F_30 ( V_31 -> V_5 [ V_783 ] ) ;
struct V_1064 * V_1065 =
V_18 -> V_236 [ V_1067 . V_411 . V_60 -> V_171 ] ;
V_47 = F_197 ( V_1065 , V_933 , V_1072 ,
& V_1067 . V_784 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_1073 ] &&
! F_231 ( V_7 , V_1067 . V_1062 ,
F_4 ( V_31 -> V_5 [ V_1073 ] ) ) )
return - V_16 ;
if ( V_1067 . V_574 && V_31 -> V_5 [ V_1074 ] ) {
bool V_115 = false ;
V_1068 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1074 ] ,
& V_115 ) ;
if ( F_16 ( V_1068 ) )
return F_24 ( V_1068 ) ;
if ( ( V_1067 . V_411 . V_414 != V_415 ) &&
V_115 ) {
F_46 ( V_1068 ) ;
return - V_16 ;
}
}
V_1067 . V_1031 =
F_184 ( V_31 -> V_5 [ V_1032 ] ) ;
V_47 = F_234 ( V_7 , V_46 , & V_1067 , V_1068 ) ;
if ( V_47 )
F_46 ( V_1068 ) ;
return V_47 ;
}
static int F_235 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
if ( ! V_7 -> V_226 -> V_1075 )
return - V_428 ;
if ( V_46 -> V_29 -> V_124 != V_129 )
return - V_428 ;
return F_236 ( V_7 , V_46 , false ) ;
}
static int F_237 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
int V_1062 [ V_235 ] ;
V_23 V_1076 ;
int V_47 ;
if ( V_46 -> V_29 -> V_124 != V_129 &&
V_46 -> V_29 -> V_124 != V_128 )
return - V_428 ;
if ( ! V_7 -> V_226 -> V_327 )
return - V_428 ;
memset ( V_1062 , 0 , sizeof( V_1062 ) ) ;
if ( ! V_31 -> V_5 [ V_1073 ] )
return - V_16 ;
V_1076 = F_4 ( V_31 -> V_5 [ V_1073 ] ) ;
if ( ! F_231 ( V_7 , V_1062 , V_1076 ) )
return - V_16 ;
V_47 = V_7 -> V_226 -> V_327 ( & V_7 -> V_18 , V_46 , V_1062 ) ;
return V_47 ;
}
static int F_238 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1077 ] )
return - V_16 ;
V_47 = - V_428 ;
if ( V_7 -> V_226 -> V_329 ) {
V_7 -> V_1078 = V_31 ;
V_47 = F_239 ( V_7 ,
F_29 ( V_31 -> V_5 [ V_1077 ] ) ,
F_30 ( V_31 -> V_5 [ V_1077 ] ) ) ;
V_7 -> V_1078 = NULL ;
}
return V_47 ;
}
static int F_240 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
int V_47 ;
long V_1079 ;
void * V_121 = NULL ;
int V_1080 = 0 ;
if ( V_35 -> args [ 0 ] ) {
V_1079 = V_35 -> args [ 0 ] - 1 ;
} else {
V_47 = F_18 ( V_35 -> V_37 , V_38 + V_39 . V_40 ,
V_39 . V_41 , V_39 . V_42 ,
V_43 ) ;
if ( V_47 )
return V_47 ;
F_8 ( & V_32 ) ;
V_7 = F_10 ( F_22 ( V_45 -> V_48 ) ,
V_39 . V_41 ) ;
if ( F_16 ( V_7 ) ) {
F_9 ( & V_32 ) ;
return F_24 ( V_7 ) ;
}
V_1079 = V_7 -> V_14 ;
V_7 = NULL ;
F_9 ( & V_32 ) ;
if ( V_39 . V_41 [ V_1077 ] )
V_35 -> args [ 1 ] =
( long ) V_39 . V_41 [ V_1077 ] ;
}
if ( V_35 -> args [ 1 ] ) {
V_121 = F_29 ( ( void * ) V_35 -> args [ 1 ] ) ;
V_1080 = F_30 ( ( void * ) V_35 -> args [ 1 ] ) ;
}
F_8 ( & V_32 ) ;
V_7 = F_11 ( V_1079 ) ;
if ( ! V_7 ) {
F_9 ( & V_32 ) ;
return - V_526 ;
}
F_241 ( V_7 ) ;
F_9 ( & V_32 ) ;
if ( ! V_7 -> V_226 -> V_1081 ) {
V_47 = - V_428 ;
goto V_708;
}
while ( 1 ) {
void * V_162 = F_31 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_390 , V_391 ,
V_1082 ) ;
struct V_4 * V_1083 ;
if ( F_34 ( V_45 , V_27 , V_1079 ) ) {
F_64 ( V_45 , V_162 ) ;
break;
}
V_1083 = F_50 ( V_45 , V_1077 ) ;
if ( ! V_1083 ) {
F_64 ( V_45 , V_162 ) ;
break;
}
V_47 = F_242 ( V_7 , V_45 , V_35 , V_121 , V_1080 ) ;
F_51 ( V_45 , V_1083 ) ;
if ( V_47 == - V_74 || V_47 == - V_526 ) {
F_64 ( V_45 , V_162 ) ;
break;
} else if ( V_47 ) {
F_64 ( V_45 , V_162 ) ;
goto V_708;
}
F_63 ( V_45 , V_162 ) ;
}
V_47 = V_45 -> V_52 ;
V_35 -> args [ 0 ] = V_1079 + 1 ;
V_708:
F_27 ( V_7 ) ;
return V_47 ;
}
static struct V_44 *
F_243 ( struct V_6 * V_7 ,
int V_1084 , V_23 V_54 , V_23 V_55 , T_11 V_1085 )
{
struct V_44 * V_45 ;
void * V_162 ;
struct V_4 * V_121 ;
V_45 = F_69 ( V_1084 + 100 , V_1085 ) ;
if ( ! V_45 )
return NULL ;
V_162 = F_31 ( V_45 , V_54 , V_55 , 0 , V_1082 ) ;
if ( ! V_162 ) {
F_244 ( V_45 ) ;
return NULL ;
}
if ( F_34 ( V_45 , V_27 , V_7 -> V_14 ) )
goto V_63;
V_121 = F_50 ( V_45 , V_1077 ) ;
( ( void * * ) V_45 -> V_35 ) [ 0 ] = V_7 ;
( ( void * * ) V_45 -> V_35 ) [ 1 ] = V_162 ;
( ( void * * ) V_45 -> V_35 ) [ 2 ] = V_121 ;
return V_45 ;
V_63:
F_244 ( V_45 ) ;
return NULL ;
}
struct V_44 * F_245 ( struct V_18 * V_18 ,
int V_1084 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
if ( F_97 ( ! V_7 -> V_1078 ) )
return NULL ;
return F_243 ( V_7 , V_1084 ,
V_7 -> V_1078 -> V_394 ,
V_7 -> V_1078 -> V_395 ,
V_118 ) ;
}
int F_246 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = ( ( void * * ) V_45 -> V_35 ) [ 0 ] ;
void * V_162 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_121 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
if ( F_97 ( ! V_7 -> V_1078 ) ) {
F_244 ( V_45 ) ;
return - V_16 ;
}
F_51 ( V_45 , V_121 ) ;
F_63 ( V_45 , V_162 ) ;
return F_71 ( V_45 , V_7 -> V_1078 ) ;
}
struct V_44 * F_247 ( struct V_18 * V_18 ,
int V_1084 , T_11 V_1085 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
return F_243 ( V_7 , V_1084 , 0 , 0 , V_1085 ) ;
}
void F_248 ( struct V_44 * V_45 , T_11 V_1085 )
{
void * V_162 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_121 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
F_51 ( V_45 , V_121 ) ;
F_63 ( V_45 , V_162 ) ;
F_249 ( V_45 , 0 , V_1086 . V_1087 , V_1085 ) ;
}
static int F_250 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1088 V_331 ;
struct V_18 * V_18 ;
struct V_113 * V_1068 = NULL ;
int V_47 ;
memset ( & V_331 , 0 , sizeof( V_331 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_538 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_475 ] ||
! F_30 ( V_31 -> V_5 [ V_475 ] ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_576 ] ) {
V_331 . V_557 =
F_4 ( V_31 -> V_5 [ V_576 ] ) ;
if ( ! F_135 ( V_7 , V_331 . V_557 ,
V_332 ) )
return - V_16 ;
} else
V_331 . V_557 = V_577 ;
V_331 . V_574 = V_31 -> V_5 [ V_575 ] ;
V_47 = F_138 ( V_7 , V_31 , & V_331 . V_578 ,
V_579 ) ;
if ( V_47 )
return V_47 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
V_18 = & V_7 -> V_18 ;
V_331 . V_1089 = - 1 ;
if ( V_31 -> V_5 [ V_1090 ] &&
( V_18 -> V_56 & V_206 ) ) {
V_331 . V_1089 =
F_73 ( V_31 -> V_5 [ V_1090 ] ) ;
}
if ( V_31 -> V_5 [ V_433 ] )
V_331 . V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_331 . V_476 = F_29 ( V_31 -> V_5 [ V_475 ] ) ;
V_331 . V_474 = F_30 ( V_31 -> V_5 [ V_475 ] ) ;
if ( V_31 -> V_5 [ V_538 ] ) {
V_331 . V_893 = F_29 ( V_31 -> V_5 [ V_538 ] ) ;
V_331 . V_894 = F_30 ( V_31 -> V_5 [ V_538 ] ) ;
}
if ( V_31 -> V_5 [ V_413 ] ) {
V_331 . V_590 =
F_76 ( V_18 ,
F_4 ( V_31 -> V_5 [ V_413 ] ) ) ;
if ( ! V_331 . V_590 ||
V_331 . V_590 -> V_56 & V_64 )
return - V_16 ;
}
if ( V_331 . V_574 && V_31 -> V_5 [ V_1074 ] ) {
V_1068 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1074 ] , NULL ) ;
if ( F_16 ( V_1068 ) )
return F_24 ( V_1068 ) ;
}
if ( F_184 ( V_31 -> V_5 [ V_1058 ] ) )
V_331 . V_56 |= V_1059 ;
if ( V_31 -> V_5 [ V_387 ] )
memcpy ( & V_331 . V_1051 ,
F_29 ( V_31 -> V_5 [ V_387 ] ) ,
sizeof( V_331 . V_1051 ) ) ;
if ( V_31 -> V_5 [ V_719 ] ) {
if ( ! V_31 -> V_5 [ V_387 ] ) {
F_46 ( V_1068 ) ;
return - V_16 ;
}
memcpy ( & V_331 . V_720 ,
F_29 ( V_31 -> V_5 [ V_719 ] ) ,
sizeof( V_331 . V_720 ) ) ;
}
V_47 = F_251 ( V_7 , V_46 , & V_331 , V_1068 ) ;
if ( V_47 )
F_46 ( V_1068 ) ;
return V_47 ;
}
static int F_252 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_3 V_1091 ;
if ( ! V_31 -> V_5 [ V_1061 ] )
V_1091 = V_1092 ;
else
V_1091 = F_73 ( V_31 -> V_5 [ V_1061 ] ) ;
if ( V_1091 == 0 )
return - V_16 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
return F_253 ( V_7 , V_46 , V_1091 , true ) ;
}
static int F_254 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_2 * V_2 ;
int V_47 ;
V_23 V_1093 ;
if ( ! V_31 -> V_5 [ V_1094 ] )
return - V_16 ;
V_1093 = F_4 ( V_31 -> V_5 [ V_1094 ] ) ;
V_2 = F_255 ( V_1093 ) ;
if ( F_16 ( V_2 ) )
return F_24 ( V_2 ) ;
V_47 = 0 ;
if ( ! F_66 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_47 = F_256 ( V_7 , V_2 ) ;
F_257 ( V_2 ) ;
return V_47 ;
}
static int F_258 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
int (* F_259)( struct V_18 * V_18 , struct V_26 * V_46 ,
struct V_1095 * V_1096 ) = NULL ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1095 V_1096 ;
memset ( & V_1096 , 0 , sizeof( struct V_1095 ) ) ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1097 ] )
return - V_16 ;
V_1096 . V_1098 = F_29 ( V_31 -> V_5 [ V_1097 ] ) ;
V_1096 . V_432 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
switch ( V_31 -> V_1099 -> V_57 ) {
case V_1100 :
F_259 = V_7 -> V_226 -> V_291 ;
break;
case V_1101 :
F_259 = V_7 -> V_226 -> V_293 ;
break;
default:
F_97 ( 1 ) ;
break;
}
if ( ! F_259 )
return - V_428 ;
return F_259 ( & V_7 -> V_18 , V_46 , & V_1096 ) ;
}
static int F_260 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_428 ;
if ( ! V_7 -> V_226 -> V_295 )
return - V_428 ;
return F_261 ( V_7 , V_46 ) ;
}
static int F_262 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 V_1102 , V_1103 ;
T_3 V_1104 ;
T_2 * V_1105 ;
if ( ! ( V_7 -> V_18 . V_56 & V_208 ) ||
! V_7 -> V_226 -> V_312 )
return - V_428 ;
if ( ! V_31 -> V_5 [ V_1106 ] ||
! V_31 -> V_5 [ V_1107 ] ||
! V_31 -> V_5 [ V_1108 ] ||
! V_31 -> V_5 [ V_538 ] ||
! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
V_1105 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_1102 = F_39 ( V_31 -> V_5 [ V_1106 ] ) ;
V_1104 = F_73 ( V_31 -> V_5 [ V_1107 ] ) ;
V_1103 = F_39 ( V_31 -> V_5 [ V_1108 ] ) ;
return F_263 ( V_7 , V_46 , V_1105 , V_1102 ,
V_1103 , V_1104 ,
F_29 ( V_31 -> V_5 [ V_538 ] ) ,
F_30 ( V_31 -> V_5 [ V_538 ] ) ) ;
}
static int F_264 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
enum V_1109 V_1110 ;
T_2 * V_1105 ;
if ( ! ( V_7 -> V_18 . V_56 & V_208 ) ||
! V_7 -> V_226 -> V_314 )
return - V_428 ;
if ( ! V_31 -> V_5 [ V_1111 ] ||
! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
V_1110 = F_39 ( V_31 -> V_5 [ V_1111 ] ) ;
V_1105 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
return F_265 ( V_7 , V_46 , V_1105 , V_1110 ) ;
}
static int F_266 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
struct V_410 V_411 ;
struct V_44 * V_58 ;
void * V_162 ;
T_1 V_517 ;
V_23 V_1112 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_413 ] ||
! V_31 -> V_5 [ V_1113 ] )
return - V_16 ;
V_1112 = F_4 ( V_31 -> V_5 [ V_1113 ] ) ;
if ( ! V_7 -> V_226 -> V_298 ||
! ( V_7 -> V_18 . V_56 & V_297 ) )
return - V_428 ;
if ( V_1112 < V_1114 ||
V_1112 > V_7 -> V_18 . V_336 )
return - V_16 ;
V_47 = F_75 ( V_7 , V_31 , & V_411 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_1115 ) ;
if ( F_16 ( V_162 ) ) {
V_47 = F_24 ( V_162 ) ;
goto V_527;
}
V_47 = F_267 ( V_7 , V_17 , V_411 . V_60 ,
V_1112 , & V_517 ) ;
if ( V_47 )
goto V_527;
if ( F_100 ( V_58 , V_1116 , V_517 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_527:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_268 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
T_1 V_517 ;
if ( ! V_31 -> V_5 [ V_1116 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_1117 )
return - V_428 ;
V_517 = F_5 ( V_31 -> V_5 [ V_1116 ] ) ;
return F_269 ( V_7 , V_17 , V_517 ) ;
}
static V_23 F_270 ( struct V_1064 * V_1065 ,
T_2 * V_933 , T_2 V_1118 )
{
T_2 V_138 ;
V_23 V_598 = 0 ;
for ( V_138 = 0 ; V_138 < V_1118 ; V_138 ++ ) {
int V_173 = ( V_933 [ V_138 ] & 0x7f ) * 5 ;
int V_1119 ;
for ( V_1119 = 0 ; V_1119 < V_1065 -> V_256 ; V_1119 ++ ) {
struct V_172 * V_1120 =
& V_1065 -> V_257 [ V_1119 ] ;
if ( V_173 == V_1120 -> V_259 ) {
V_598 |= 1 << V_1119 ;
break;
}
}
if ( V_1119 == V_1065 -> V_256 )
return 0 ;
}
return V_598 ;
}
static bool F_271 ( struct V_1064 * V_1065 ,
T_2 * V_933 , T_2 V_1118 ,
T_2 V_240 [ V_1121 ] )
{
T_2 V_138 ;
memset ( V_240 , 0 , V_1121 ) ;
for ( V_138 = 0 ; V_138 < V_1118 ; V_138 ++ ) {
int V_1119 , V_1122 ;
V_1119 = V_933 [ V_138 ] / 8 ;
V_1122 = F_146 ( V_933 [ V_138 ] % 8 ) ;
if ( ( V_1119 < 0 ) || ( V_1119 >= V_1121 ) )
return false ;
if ( V_1065 -> V_237 . V_240 . V_1123 [ V_1119 ] & V_1122 )
V_240 [ V_1119 ] |= V_1122 ;
else
return false ;
}
return true ;
}
static int F_272 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_1124 + 1 ] ;
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1125 V_598 ;
int V_117 , V_138 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_4 * V_1126 ;
struct V_1064 * V_1065 ;
if ( V_31 -> V_5 [ V_1127 ] == NULL )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_300 )
return - V_428 ;
memset ( & V_598 , 0 , sizeof( V_598 ) ) ;
for ( V_138 = 0 ; V_138 < V_235 ; V_138 ++ ) {
V_1065 = V_7 -> V_18 . V_236 [ V_138 ] ;
V_598 . V_1128 [ V_138 ] . V_1129 =
V_1065 ? ( 1 << V_1065 -> V_256 ) - 1 : 0 ;
if ( V_1065 )
memcpy ( V_598 . V_1128 [ V_138 ] . V_240 ,
V_1065 -> V_237 . V_240 . V_1123 ,
sizeof( V_598 . V_1128 [ V_138 ] . V_240 ) ) ;
else
memset ( V_598 . V_1128 [ V_138 ] . V_240 , 0 ,
sizeof( V_598 . V_1128 [ V_138 ] . V_240 ) ) ;
}
F_109 ( V_1130 > V_1121 * 8 ) ;
F_44 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_170 V_171 = F_196 ( V_1126 ) ;
if ( V_171 < 0 || V_171 >= V_235 )
return - V_16 ;
V_1065 = V_7 -> V_18 . V_236 [ V_171 ] ;
if ( V_1065 == NULL )
return - V_16 ;
F_91 ( V_78 , V_1124 , F_29 ( V_1126 ) ,
F_30 ( V_1126 ) , V_1131 ) ;
if ( V_78 [ V_1132 ] ) {
V_598 . V_1128 [ V_171 ] . V_1129 = F_270 (
V_1065 ,
F_29 ( V_78 [ V_1132 ] ) ,
F_30 ( V_78 [ V_1132 ] ) ) ;
if ( ( V_598 . V_1128 [ V_171 ] . V_1129 == 0 ) &&
F_30 ( V_78 [ V_1132 ] ) )
return - V_16 ;
}
if ( V_78 [ V_1133 ] ) {
if ( ! F_271 (
V_1065 ,
F_29 ( V_78 [ V_1133 ] ) ,
F_30 ( V_78 [ V_1133 ] ) ,
V_598 . V_1128 [ V_171 ] . V_240 ) )
return - V_16 ;
}
if ( V_598 . V_1128 [ V_171 ] . V_1129 == 0 ) {
if ( ! V_7 -> V_18 . V_236 [ V_171 ] -> V_237 . V_238 )
return - V_16 ;
for ( V_138 = 0 ; V_138 < V_1121 ; V_138 ++ )
if ( V_598 . V_1128 [ V_171 ] . V_240 [ V_138 ] )
break;
if ( V_138 == V_1121 )
return - V_16 ;
}
}
return F_273 ( V_7 , V_46 , NULL , & V_598 ) ;
}
static int F_274 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
T_3 V_1134 = V_348 | V_1135 ;
if ( ! V_31 -> V_5 [ V_1136 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_347 ] )
V_1134 = F_73 ( V_31 -> V_5 [ V_347 ] ) ;
switch ( V_17 -> V_124 ) {
case V_132 :
case V_129 :
case V_133 :
case V_125 :
case V_126 :
case V_128 :
case V_127 :
case V_505 :
break;
default:
return - V_428 ;
}
if ( ! V_7 -> V_226 -> V_302 )
return - V_428 ;
return F_275 ( V_17 , V_31 -> V_394 , V_1134 ,
F_29 ( V_31 -> V_5 [ V_1136 ] ) ,
F_30 ( V_31 -> V_5 [ V_1136 ] ) ) ;
}
static int F_276 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
struct V_410 V_411 ;
int V_47 ;
void * V_162 = NULL ;
T_1 V_517 ;
struct V_44 * V_58 = NULL ;
unsigned int V_1137 = 0 ;
bool V_1138 , V_940 , V_1139 ;
V_1139 = V_31 -> V_5 [ V_1140 ] ;
if ( ! V_31 -> V_5 [ V_1141 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_302 )
return - V_428 ;
switch ( V_17 -> V_124 ) {
case V_132 :
case V_129 :
case V_133 :
case V_125 :
case V_126 :
case V_128 :
case V_127 :
case V_505 :
break;
default:
return - V_428 ;
}
if ( V_31 -> V_5 [ V_1113 ] ) {
if ( ! ( V_7 -> V_18 . V_56 & V_337 ) )
return - V_16 ;
V_1137 = F_4 ( V_31 -> V_5 [ V_1113 ] ) ;
if ( V_1137 < V_1114 ||
V_1137 > V_7 -> V_18 . V_336 )
return - V_16 ;
}
V_1138 = V_31 -> V_5 [ V_338 ] ;
if ( V_1138 && ! ( V_7 -> V_18 . V_56 & V_337 ) )
return - V_16 ;
V_940 = F_184 ( V_31 -> V_5 [ V_941 ] ) ;
V_47 = F_75 ( V_7 , V_31 , & V_411 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_1139 ) {
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_1142 ) ;
if ( F_16 ( V_162 ) ) {
V_47 = F_24 ( V_162 ) ;
goto V_527;
}
}
V_47 = F_277 ( V_7 , V_17 , V_411 . V_60 , V_1138 , V_1137 ,
F_29 ( V_31 -> V_5 [ V_1141 ] ) ,
F_30 ( V_31 -> V_5 [ V_1141 ] ) ,
V_940 , V_1139 , & V_517 ) ;
if ( V_47 )
goto V_527;
if ( V_58 ) {
if ( F_100 ( V_58 , V_1116 , V_517 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
}
return 0 ;
V_63:
V_47 = - V_74 ;
V_527:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_278 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
T_1 V_517 ;
if ( ! V_31 -> V_5 [ V_1116 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_304 )
return - V_428 ;
switch ( V_17 -> V_124 ) {
case V_132 :
case V_129 :
case V_133 :
case V_125 :
case V_126 :
case V_127 :
case V_505 :
break;
default:
return - V_428 ;
}
V_517 = F_5 ( V_31 -> V_5 [ V_1116 ] ) ;
return F_279 ( V_7 , V_17 , V_517 ) ;
}
static int F_280 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
T_2 V_1143 ;
bool V_1144 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1145 ] )
return - V_16 ;
V_1143 = F_4 ( V_31 -> V_5 [ V_1145 ] ) ;
if ( V_1143 != V_1146 && V_1143 != V_1147 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1148 )
return - V_428 ;
V_1144 = ( V_1143 == V_1147 ) ? true : false ;
if ( V_1144 == V_17 -> V_1149 )
return 0 ;
V_47 = F_281 ( V_7 , V_46 , V_1144 , V_17 -> V_1150 ) ;
if ( ! V_47 )
V_17 -> V_1149 = V_1144 ;
return V_47 ;
}
static int F_282 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
enum V_1151 V_1143 ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1148 )
return - V_428 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_1152 ) ;
if ( ! V_162 ) {
V_47 = - V_74 ;
goto V_527;
}
if ( V_17 -> V_1149 )
V_1143 = V_1147 ;
else
V_1143 = V_1146 ;
if ( F_34 ( V_58 , V_1145 , V_1143 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_527:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_283 ( struct V_30 * V_31 ,
V_23 V_173 , V_23 V_1153 , V_23 V_1154 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
if ( V_173 > 100 || V_1154 > V_1155 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1156 )
return - V_428 ;
if ( V_17 -> V_124 != V_132 &&
V_17 -> V_124 != V_133 )
return - V_428 ;
return F_284 ( V_7 , V_46 , V_173 , V_1153 , V_1154 ) ;
}
static int F_285 ( struct V_30 * V_31 ,
T_12 V_1157 , V_23 V_1158 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
if ( V_1157 > 0 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1159 )
return - V_428 ;
if ( V_17 -> V_124 != V_132 &&
V_17 -> V_124 != V_133 )
return - V_428 ;
return F_286 ( V_7 , V_46 , V_1157 , V_1158 ) ;
}
static int F_287 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_5 [ V_1160 + 1 ] ;
struct V_4 * V_1161 ;
int V_47 ;
V_1161 = V_31 -> V_5 [ V_1162 ] ;
if ( ! V_1161 ) {
V_47 = - V_16 ;
goto V_481;
}
V_47 = F_38 ( V_5 , V_1160 , V_1161 ,
V_1163 ) ;
if ( V_47 )
goto V_481;
if ( V_5 [ V_1164 ] &&
V_5 [ V_1165 ] ) {
T_12 V_1157 ;
V_23 V_1158 ;
V_1157 = F_4 ( V_5 [ V_1164 ] ) ;
V_1158 = F_4 ( V_5 [ V_1165 ] ) ;
V_47 = F_285 ( V_31 , V_1157 , V_1158 ) ;
} else if ( V_5 [ V_1166 ] &&
V_5 [ V_1167 ] &&
V_5 [ V_1168 ] ) {
V_23 V_173 , V_1153 , V_1154 ;
V_173 = F_4 ( V_5 [ V_1166 ] ) ;
V_1153 = F_4 ( V_5 [ V_1167 ] ) ;
V_1154 = F_4 ( V_5 [ V_1168 ] ) ;
V_47 = F_283 ( V_31 , V_173 , V_1153 , V_1154 ) ;
} else
V_47 = - V_16 ;
V_481:
return V_47 ;
}
static int F_288 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_814 V_870 ;
struct V_874 V_875 ;
int V_47 ;
memcpy ( & V_870 , & V_818 , sizeof( V_870 ) ) ;
memcpy ( & V_875 , & V_1169 , sizeof( V_875 ) ) ;
if ( V_31 -> V_5 [ V_820 ] ) {
V_47 = F_181 ( V_31 , & V_870 , NULL ) ;
if ( V_47 )
return V_47 ;
}
if ( ! V_31 -> V_5 [ V_498 ] ||
! F_30 ( V_31 -> V_5 [ V_498 ] ) )
return - V_16 ;
V_875 . V_1170 = F_29 ( V_31 -> V_5 [ V_498 ] ) ;
V_875 . V_817 = F_30 ( V_31 -> V_5 [ V_498 ] ) ;
if ( V_31 -> V_5 [ V_1073 ] &&
! F_231 ( V_7 , V_875 . V_1062 ,
F_4 ( V_31 -> V_5 [ V_1073 ] ) ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_877 ] ) {
V_47 = F_183 ( V_31 , & V_875 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_413 ] ) {
V_47 = F_75 ( V_7 , V_31 , & V_875 . V_411 ) ;
if ( V_47 )
return V_47 ;
} else {
V_875 . V_411 . V_60 = NULL ;
}
return F_289 ( V_7 , V_46 , & V_875 , & V_870 ) ;
}
static int F_290 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
return F_291 ( V_7 , V_46 ) ;
}
static int F_292 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_44 * V_58 ;
void * V_162 ;
if ( ! V_7 -> V_18 . V_351 . V_56 && ! V_7 -> V_18 . V_351 . V_352 )
return - V_428 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_1171 ) ;
if ( ! V_162 )
goto V_63;
if ( V_7 -> V_351 ) {
struct V_4 * V_353 ;
V_353 = F_50 ( V_58 , V_1172 ) ;
if ( ! V_353 )
goto V_63;
if ( ( V_7 -> V_351 -> V_1173 &&
F_35 ( V_58 , V_356 ) ) ||
( V_7 -> V_351 -> V_333 &&
F_35 ( V_58 , V_358 ) ) ||
( V_7 -> V_351 -> V_1174 &&
F_35 ( V_58 , V_360 ) ) ||
( V_7 -> V_351 -> V_1175 &&
F_35 ( V_58 , V_364 ) ) ||
( V_7 -> V_351 -> V_1176 &&
F_35 ( V_58 , V_366 ) ) ||
( V_7 -> V_351 -> V_1177 &&
F_35 ( V_58 , V_368 ) ) ||
( V_7 -> V_351 -> V_1178 &&
F_35 ( V_58 , V_370 ) ) )
goto V_63;
if ( V_7 -> V_351 -> V_352 ) {
struct V_4 * V_1179 , * V_1180 ;
int V_138 , V_1181 ;
V_1179 = F_50 ( V_58 ,
V_378 ) ;
if ( ! V_1179 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_7 -> V_351 -> V_352 ; V_138 ++ ) {
V_1180 = F_50 ( V_58 , V_138 + 1 ) ;
if ( ! V_1180 )
goto V_63;
V_1181 = V_7 -> V_351 -> V_1182 [ V_138 ] . V_1183 ;
if ( F_58 ( V_58 , V_1184 ,
F_293 ( V_1181 , 8 ) ,
V_7 -> V_351 -> V_1182 [ V_138 ] . V_598 ) ||
F_58 ( V_58 , V_1185 ,
V_1181 ,
V_7 -> V_351 -> V_1182 [ V_138 ] . V_1186 ) )
goto V_63;
F_51 ( V_58 , V_1180 ) ;
}
F_51 ( V_58 , V_1179 ) ;
}
F_51 ( V_58 , V_353 ) ;
}
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
F_70 ( V_58 ) ;
return - V_74 ;
}
static int F_294 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_4 * V_78 [ V_1187 ] ;
struct V_1188 V_1189 = {} ;
struct V_1188 * V_1190 ;
struct V_1191 * V_351 = & V_7 -> V_18 . V_351 ;
int V_47 , V_138 ;
bool V_1192 = V_7 -> V_351 ;
if ( ! V_7 -> V_18 . V_351 . V_56 && ! V_7 -> V_18 . V_351 . V_352 )
return - V_428 ;
if ( ! V_31 -> V_5 [ V_1172 ] ) {
F_295 ( V_7 ) ;
V_7 -> V_351 = NULL ;
goto V_1193;
}
V_47 = F_91 ( V_78 , V_1194 ,
F_29 ( V_31 -> V_5 [ V_1172 ] ) ,
F_30 ( V_31 -> V_5 [ V_1172 ] ) ,
V_1195 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_356 ] ) {
if ( ! ( V_351 -> V_56 & V_355 ) )
return - V_16 ;
V_1189 . V_1173 = true ;
}
if ( V_78 [ V_358 ] ) {
if ( ! ( V_351 -> V_56 & V_357 ) )
return - V_16 ;
V_1189 . V_333 = true ;
}
if ( V_78 [ V_360 ] ) {
if ( ! ( V_351 -> V_56 & V_359 ) )
return - V_16 ;
V_1189 . V_1174 = true ;
}
if ( V_78 [ V_362 ] )
return - V_16 ;
if ( V_78 [ V_364 ] ) {
if ( ! ( V_351 -> V_56 & V_363 ) )
return - V_16 ;
V_1189 . V_1175 = true ;
}
if ( V_78 [ V_366 ] ) {
if ( ! ( V_351 -> V_56 & V_365 ) )
return - V_16 ;
V_1189 . V_1176 = true ;
}
if ( V_78 [ V_368 ] ) {
if ( ! ( V_351 -> V_56 & V_367 ) )
return - V_16 ;
V_1189 . V_1177 = true ;
}
if ( V_78 [ V_370 ] ) {
if ( ! ( V_351 -> V_56 & V_369 ) )
return - V_16 ;
V_1189 . V_1178 = true ;
}
if ( V_78 [ V_378 ] ) {
struct V_4 * V_372 ;
int V_352 = 0 ;
int V_117 , V_1181 , V_1196 ;
struct V_4 * V_1197 [ V_1198 ] ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_352 ++ ;
if ( V_352 > V_351 -> V_352 )
return - V_16 ;
V_1189 . V_1182 = F_296 ( V_352 ,
sizeof( V_1189 . V_1182 [ 0 ] ) ,
V_118 ) ;
if ( ! V_1189 . V_1182 )
return - V_119 ;
V_1189 . V_352 = V_352 ;
V_138 = 0 ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_91 ( V_1197 , V_1199 ,
F_29 ( V_372 ) , F_30 ( V_372 ) , NULL ) ;
V_47 = - V_16 ;
if ( ! V_1197 [ V_1184 ] ||
! V_1197 [ V_1185 ] )
goto error;
V_1181 = F_30 ( V_1197 [ V_1185 ] ) ;
V_1196 = F_293 ( V_1181 , 8 ) ;
if ( F_30 ( V_1197 [ V_1184 ] ) !=
V_1196 )
goto error;
if ( V_1181 > V_351 -> V_377 ||
V_1181 < V_351 -> V_375 )
goto error;
V_1189 . V_1182 [ V_138 ] . V_598 =
F_297 ( V_1196 + V_1181 , V_118 ) ;
if ( ! V_1189 . V_1182 [ V_138 ] . V_598 ) {
V_47 = - V_119 ;
goto error;
}
V_1189 . V_1182 [ V_138 ] . V_1186 =
V_1189 . V_1182 [ V_138 ] . V_598 + V_1196 ;
memcpy ( V_1189 . V_1182 [ V_138 ] . V_598 ,
F_29 ( V_1197 [ V_1184 ] ) ,
V_1196 ) ;
V_1189 . V_1182 [ V_138 ] . V_1183 = V_1181 ;
memcpy ( V_1189 . V_1182 [ V_138 ] . V_1186 ,
F_29 ( V_1197 [ V_1185 ] ) ,
V_1181 ) ;
V_138 ++ ;
}
}
V_1190 = F_298 ( & V_1189 , sizeof( V_1189 ) , V_118 ) ;
if ( ! V_1190 ) {
V_47 = - V_119 ;
goto error;
}
F_295 ( V_7 ) ;
V_7 -> V_351 = V_1190 ;
V_1193:
if ( V_7 -> V_226 -> V_1193 && V_1192 != ! ! V_7 -> V_351 )
F_299 ( V_7 , V_7 -> V_351 ) ;
return 0 ;
error:
for ( V_138 = 0 ; V_138 < V_1189 . V_352 ; V_138 ++ )
F_46 ( V_1189 . V_1182 [ V_138 ] . V_598 ) ;
F_46 ( V_1189 . V_1182 ) ;
return V_47 ;
}
static int F_300 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_4 * V_78 [ V_1200 ] ;
struct V_1201 V_1202 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1203 ] )
return - V_16 ;
V_47 = F_91 ( V_78 , V_1204 ,
F_29 ( V_31 -> V_5 [ V_1203 ] ) ,
F_30 ( V_31 -> V_5 [ V_1203 ] ) ,
V_1205 ) ;
if ( V_47 )
return V_47 ;
if ( F_30 ( V_78 [ V_1206 ] ) != V_1207 )
return - V_1208 ;
if ( F_30 ( V_78 [ V_1209 ] ) != V_1210 )
return - V_1208 ;
if ( F_30 ( V_78 [ V_1211 ] ) != V_1212 )
return - V_1208 ;
memcpy ( V_1202 . V_1213 , F_29 ( V_78 [ V_1209 ] ) ,
V_1210 ) ;
memcpy ( V_1202 . V_1214 , F_29 ( V_78 [ V_1211 ] ) ,
V_1212 ) ;
memcpy ( V_1202 . V_1215 ,
F_29 ( V_78 [ V_1206 ] ) ,
V_1207 ) ;
F_108 ( V_17 ) ;
if ( ! V_17 -> V_130 ) {
V_47 = - V_1216 ;
goto V_481;
}
if ( ! V_7 -> V_226 -> V_1217 ) {
V_47 = - V_428 ;
goto V_481;
}
V_47 = F_301 ( V_7 , V_46 , & V_1202 ) ;
V_481:
F_110 ( V_17 ) ;
return V_47 ;
}
static int F_302 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_17 -> V_124 != V_125 &&
V_17 -> V_124 != V_127 )
return - V_16 ;
if ( V_17 -> V_1218 )
return - V_430 ;
V_17 -> V_1218 = V_31 -> V_394 ;
return 0 ;
}
static int F_303 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_392 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_44 * V_58 ;
void * V_162 ;
const T_2 * V_1219 ;
T_1 V_517 ;
int V_47 ;
if ( V_17 -> V_124 != V_125 &&
V_17 -> V_124 != V_127 )
return - V_428 ;
if ( ! V_31 -> V_5 [ V_433 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_319 )
return - V_428 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_394 , V_31 -> V_395 , 0 ,
V_1220 ) ;
if ( F_16 ( V_162 ) ) {
V_47 = F_24 ( V_162 ) ;
goto V_527;
}
V_1219 = F_29 ( V_31 -> V_5 [ V_433 ] ) ;
V_47 = F_304 ( V_7 , V_46 , V_1219 , & V_517 ) ;
if ( V_47 )
goto V_527;
if ( F_100 ( V_58 , V_1116 , V_517 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_527:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_305 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1221 * V_1222 , * V_1223 ;
int V_1224 ;
if ( ! ( V_7 -> V_18 . V_56 & V_323 ) )
return - V_428 ;
V_1223 = F_43 ( sizeof( * V_1223 ) , V_118 ) ;
if ( ! V_1223 )
return - V_119 ;
F_214 ( & V_7 -> V_1225 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1222 -> V_1226 == V_31 -> V_394 ) {
V_1224 = - V_564 ;
goto V_708;
}
}
V_1223 -> V_1226 = V_31 -> V_394 ;
F_306 ( & V_1223 -> V_510 , & V_7 -> V_1227 ) ;
F_216 ( & V_7 -> V_1225 ) ;
return 0 ;
V_708:
F_216 ( & V_7 -> V_1225 ) ;
F_46 ( V_1223 ) ;
return V_1224 ;
}
static int F_307 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
int V_47 ;
if ( ! V_7 -> V_226 -> V_325 )
return - V_428 ;
if ( V_17 -> V_124 != V_505 )
return - V_428 ;
if ( V_17 -> V_1228 )
return 0 ;
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_308 ( V_7 , V_17 -> V_124 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_309 ( V_7 , V_17 ) ;
if ( V_47 )
return V_47 ;
V_17 -> V_1228 = true ;
F_8 ( & V_7 -> V_19 ) ;
V_7 -> V_1229 ++ ;
F_9 ( & V_7 -> V_19 ) ;
return 0 ;
}
static int F_310 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_392 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
if ( V_17 -> V_124 != V_505 )
return - V_428 ;
if ( ! V_7 -> V_226 -> V_1230 )
return - V_428 ;
if ( ! V_17 -> V_1228 )
return 0 ;
F_311 ( V_7 , V_17 ) ;
V_17 -> V_1228 = false ;
F_8 ( & V_7 -> V_19 ) ;
V_7 -> V_1229 -- ;
F_9 ( & V_7 -> V_19 ) ;
if ( F_97 ( V_7 -> V_928 && V_7 -> V_928 -> V_17 == V_17 ) ) {
V_7 -> V_928 -> V_1231 = true ;
F_312 ( V_7 , true ) ;
}
return 0 ;
}
static int F_313 ( struct V_1232 * V_226 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_26 * V_46 ;
bool V_1233 = V_226 -> V_1234 & V_1235 ;
if ( V_1233 )
F_20 () ;
if ( V_226 -> V_1234 & V_1236 ) {
V_7 = F_15 ( F_89 ( V_31 ) , V_31 ) ;
if ( F_16 ( V_7 ) ) {
if ( V_1233 )
F_25 () ;
return F_24 ( V_7 ) ;
}
V_31 -> V_392 [ 0 ] = V_7 ;
} else if ( V_226 -> V_1234 & V_1237 ||
V_226 -> V_1234 & V_1238 ) {
F_8 ( & V_32 ) ;
V_17 = F_1 ( F_89 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_17 ) ) {
F_9 ( & V_32 ) ;
if ( V_1233 )
F_25 () ;
return F_24 ( V_17 ) ;
}
V_46 = V_17 -> V_20 ;
V_7 = F_13 ( V_17 -> V_18 ) ;
if ( V_226 -> V_1234 & V_1237 ) {
if ( ! V_46 ) {
F_9 ( & V_32 ) ;
if ( V_1233 )
F_25 () ;
return - V_16 ;
}
V_31 -> V_392 [ 1 ] = V_46 ;
} else {
V_31 -> V_392 [ 1 ] = V_17 ;
}
if ( V_46 ) {
if ( V_226 -> V_1234 & V_1239 &&
! F_86 ( V_46 ) ) {
F_9 ( & V_32 ) ;
if ( V_1233 )
F_25 () ;
return - V_442 ;
}
F_200 ( V_46 ) ;
} else if ( V_226 -> V_1234 & V_1239 ) {
if ( ! V_17 -> V_1228 ) {
F_9 ( & V_32 ) ;
if ( V_1233 )
F_25 () ;
return - V_442 ;
}
}
F_241 ( V_7 ) ;
F_9 ( & V_32 ) ;
V_31 -> V_392 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_314 ( struct V_1232 * V_226 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
if ( V_31 -> V_392 [ 0 ] )
F_27 ( V_31 -> V_392 [ 0 ] ) ;
if ( V_31 -> V_392 [ 1 ] ) {
if ( V_226 -> V_1234 & V_1238 ) {
struct V_1 * V_17 = V_31 -> V_392 [ 1 ] ;
if ( V_17 -> V_20 )
F_14 ( V_17 -> V_20 ) ;
} else {
F_14 ( V_31 -> V_392 [ 1 ] ) ;
}
}
if ( V_226 -> V_1234 & V_1235 )
F_25 () ;
}
void F_315 ( struct V_6 * V_7 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_53 ( V_58 , 0 , 0 , 0 , V_7 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1240 . V_1087 , V_118 ) ;
}
static int F_317 ( struct V_44 * V_58 ,
struct V_6 * V_7 )
{
struct V_924 * V_1241 = V_7 -> V_928 ;
struct V_4 * V_1242 ;
int V_138 ;
F_318 ( V_7 ) ;
if ( F_97 ( ! V_1241 ) )
return 0 ;
V_1242 = F_50 ( V_58 , V_930 ) ;
if ( ! V_1242 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_1241 -> V_926 ; V_138 ++ ) {
if ( F_58 ( V_58 , V_138 , V_1241 -> V_931 [ V_138 ] . V_474 , V_1241 -> V_931 [ V_138 ] . V_476 ) )
goto V_63;
}
F_51 ( V_58 , V_1242 ) ;
V_1242 = F_50 ( V_58 , V_929 ) ;
if ( ! V_1242 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_1241 -> V_253 ; V_138 ++ ) {
if ( F_34 ( V_58 , V_138 , V_1241 -> V_254 [ V_138 ] -> V_62 ) )
goto V_63;
}
F_51 ( V_58 , V_1242 ) ;
if ( V_1241 -> V_893 &&
F_58 ( V_58 , V_538 , V_1241 -> V_894 , V_1241 -> V_893 ) )
goto V_63;
if ( V_1241 -> V_56 )
F_34 ( V_58 , V_935 , V_1241 -> V_56 ) ;
return 0 ;
V_63:
return - V_74 ;
}
static int F_319 ( struct V_44 * V_58 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_23 V_54 , V_23 V_55 , int V_56 ,
V_23 V_57 )
{
void * V_162 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_57 ) ;
if ( ! V_162 )
return - 1 ;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_17 -> V_20 && F_34 ( V_58 , V_10 ,
V_17 -> V_20 -> V_21 ) ) ||
F_100 ( V_58 , V_12 , V_13 ( V_17 ) ) )
goto V_63;
F_317 ( V_58 , V_7 ) ;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
static int
F_320 ( struct V_44 * V_58 ,
struct V_6 * V_7 ,
struct V_26 * V_20 ,
V_23 V_54 , V_23 V_55 , int V_56 , V_23 V_57 )
{
void * V_162 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_57 ) ;
if ( ! V_162 )
return - 1 ;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_388 ;
}
void F_199 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_319 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1243 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1244 . V_1087 , V_118 ) ;
}
void F_321 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_319 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_968 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1244 . V_1087 , V_118 ) ;
}
void F_322 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_319 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1245 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1244 . V_1087 , V_118 ) ;
}
void F_323 ( struct V_6 * V_7 ,
struct V_26 * V_20 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_320 ( V_58 , V_7 , V_20 , 0 , 0 , 0 ,
V_1246 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1244 . V_1087 , V_118 ) ;
}
void F_203 ( struct V_6 * V_7 ,
struct V_26 * V_20 , V_23 V_57 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_320 ( V_58 , V_7 , V_20 , 0 , 0 , 0 , V_57 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1244 . V_1087 , V_118 ) ;
}
void F_324 ( struct V_1247 * V_925 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1248 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_56 ( V_58 , V_1249 , V_925 -> V_1250 ) )
goto V_63;
if ( V_925 -> V_902 [ 0 ] == '0' && V_925 -> V_902 [ 1 ] == '0' ) {
if ( F_56 ( V_58 , V_1251 ,
V_1252 ) )
goto V_63;
} else if ( V_925 -> V_902 [ 0 ] == '9' && V_925 -> V_902 [ 1 ] == '9' ) {
if ( F_56 ( V_58 , V_1251 ,
V_1253 ) )
goto V_63;
} else if ( ( V_925 -> V_902 [ 0 ] == '9' && V_925 -> V_902 [ 1 ] == '8' ) ||
V_925 -> V_1254 ) {
if ( F_56 ( V_58 , V_1251 ,
V_1255 ) )
goto V_63;
} else {
if ( F_56 ( V_58 , V_1251 ,
V_1256 ) ||
F_54 ( V_58 , V_810 ,
V_925 -> V_902 ) )
goto V_63;
}
if ( F_325 ( V_925 -> V_14 ) &&
F_34 ( V_58 , V_27 , V_925 -> V_14 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_209 () ;
F_326 ( V_58 , 0 , V_1257 . V_1087 ,
V_1258 ) ;
F_211 () ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static void F_327 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1259 , T_10 V_52 ,
enum V_558 V_57 , T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_1141 , V_52 , V_1259 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_328 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1259 ,
T_10 V_52 , T_11 V_1085 )
{
F_327 ( V_7 , V_20 , V_1259 , V_52 ,
V_560 , V_1085 ) ;
}
void F_329 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1259 ,
T_10 V_52 , T_11 V_1085 )
{
F_327 ( V_7 , V_20 , V_1259 , V_52 ,
V_1261 , V_1085 ) ;
}
void F_330 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1259 ,
T_10 V_52 , T_11 V_1085 )
{
F_327 ( V_7 , V_20 , V_1259 , V_52 ,
V_1262 , V_1085 ) ;
}
void F_331 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1259 ,
T_10 V_52 , T_11 V_1085 )
{
F_327 ( V_7 , V_20 , V_1259 , V_52 ,
V_1263 , V_1085 ) ;
}
void F_332 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1259 ,
T_10 V_52 , T_11 V_1085 )
{
F_327 ( V_7 , V_20 , V_1259 , V_52 ,
V_1264 , V_1085 ) ;
}
void F_333 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1259 ,
T_10 V_52 , T_11 V_1085 )
{
F_327 ( V_7 , V_20 , V_1259 , V_52 ,
V_1265 , V_1085 ) ;
}
static void F_334 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_57 ,
const T_2 * V_1219 , T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_35 ( V_58 , V_1266 ) ||
F_58 ( V_58 , V_433 , V_470 , V_1219 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_335 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1219 ,
T_11 V_1085 )
{
F_334 ( V_7 , V_20 , V_560 ,
V_1219 , V_1085 ) ;
}
void F_336 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1219 ,
T_11 V_1085 )
{
F_334 ( V_7 , V_20 , V_1261 ,
V_1219 , V_1085 ) ;
}
void F_337 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_432 ,
const T_2 * V_1267 , T_10 V_1268 ,
const T_2 * V_1269 , T_10 V_1270 ,
T_3 V_1271 , T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_332 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_432 && F_58 ( V_58 , V_433 , V_470 , V_432 ) ) ||
F_57 ( V_58 , V_1107 , V_1271 ) ||
( V_1267 &&
F_58 ( V_58 , V_1272 , V_1268 , V_1267 ) ) ||
( V_1269 &&
F_58 ( V_58 , V_1273 , V_1270 , V_1269 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_338 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_432 ,
const T_2 * V_1267 , T_10 V_1268 ,
const T_2 * V_1269 , T_10 V_1270 , T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1274 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_432 ) ||
( V_1267 &&
F_58 ( V_58 , V_1272 , V_1268 , V_1267 ) ) ||
( V_1269 &&
F_58 ( V_58 , V_1273 , V_1270 , V_1269 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_339 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_3 V_1091 ,
const T_2 * V_893 , T_10 V_894 , bool V_1275 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_118 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_334 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_1275 && V_1091 &&
F_57 ( V_58 , V_1061 , V_1091 ) ) ||
( V_1275 &&
F_35 ( V_58 , V_1276 ) ) ||
( V_893 && F_58 ( V_58 , V_538 , V_894 , V_893 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_118 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_340 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_432 ,
T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1277 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_432 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_341 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1278 , const T_2 * V_893 , T_2 V_894 ,
T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1279 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_1278 ) ||
( V_894 && V_893 &&
F_58 ( V_58 , V_538 , V_894 , V_893 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_342 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1219 ,
enum V_1280 V_1281 , int V_1282 ,
const T_2 * V_1283 , T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1284 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_1219 && F_58 ( V_58 , V_433 , V_470 , V_1219 ) ) ||
F_34 ( V_58 , V_110 , V_1281 ) ||
( V_1282 != - 1 &&
F_56 ( V_58 , V_106 , V_1282 ) ) ||
( V_1283 && F_58 ( V_58 , V_105 , 6 , V_1283 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_343 ( struct V_18 * V_18 ,
struct V_59 * V_1285 ,
struct V_59 * V_1286 )
{
struct V_44 * V_58 ;
void * V_162 ;
struct V_4 * V_166 ;
V_58 = F_69 ( V_393 , V_1258 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1287 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , F_344 ( V_18 ) ) )
goto V_63;
V_166 = F_50 ( V_58 , V_1288 ) ;
if ( ! V_166 )
goto V_63;
if ( F_33 ( V_58 , V_1285 ) )
goto V_63;
F_51 ( V_58 , V_166 ) ;
V_166 = F_50 ( V_58 , V_1289 ) ;
if ( ! V_166 )
goto V_63;
if ( F_33 ( V_58 , V_1286 ) )
goto V_63;
F_51 ( V_58 , V_166 ) ;
F_63 ( V_58 , V_162 ) ;
F_209 () ;
F_326 ( V_58 , 0 , V_1257 . V_1087 ,
V_1258 ) ;
F_211 () ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static void F_345 (
int V_57 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_517 ,
struct V_59 * V_60 ,
unsigned int V_1112 , T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_17 -> V_20 && F_34 ( V_58 , V_10 ,
V_17 -> V_20 -> V_21 ) ) ||
F_100 ( V_58 , V_12 , V_13 ( V_17 ) ) ||
F_34 ( V_58 , V_413 , V_60 -> V_62 ) ||
F_34 ( V_58 , V_418 ,
V_421 ) ||
F_100 ( V_58 , V_1116 , V_517 ) )
goto V_63;
if ( V_57 == V_1115 &&
F_34 ( V_58 , V_1113 , V_1112 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_346 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_517 ,
struct V_59 * V_60 ,
unsigned int V_1112 , T_11 V_1085 )
{
F_345 ( V_1115 ,
V_7 , V_17 , V_517 , V_60 ,
V_1112 , V_1085 ) ;
}
void F_347 (
struct V_6 * V_7 ,
struct V_1 * V_17 ,
T_1 V_517 , struct V_59 * V_60 , T_11 V_1085 )
{
F_345 ( V_1290 ,
V_7 , V_17 , V_517 , V_60 , 0 , V_1085 ) ;
}
void F_348 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_519 ,
struct V_631 * V_632 , T_11 V_1085 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
if ( F_149 ( V_58 , 0 , 0 , 0 ,
V_7 , V_46 , V_519 , V_632 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
}
void F_349 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_519 ,
T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1291 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_519 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_350 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_519 ,
enum V_1292 V_1091 ,
T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_1293 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1294 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_519 ) ||
F_34 ( V_58 , V_1295 , V_1091 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static bool F_351 ( struct V_26 * V_46 , T_2 V_57 ,
const T_2 * V_1219 , T_11 V_1085 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
V_23 V_1226 = F_352 ( V_17 -> V_1218 ) ;
if ( ! V_1226 )
return false ;
V_58 = F_69 ( 100 , V_1085 ) ;
if ( ! V_58 )
return true ;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return true ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_1219 ) )
goto V_63;
V_47 = F_63 ( V_58 , V_162 ) ;
if ( V_47 < 0 ) {
F_70 ( V_58 ) ;
return true ;
}
F_353 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1226 ) ;
return true ;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
return true ;
}
bool F_354 ( struct V_26 * V_46 , const T_2 * V_1219 , T_11 V_1085 )
{
return F_351 ( V_46 , V_1296 ,
V_1219 , V_1085 ) ;
}
bool F_355 ( struct V_26 * V_46 ,
const T_2 * V_1219 , T_11 V_1085 )
{
return F_351 ( V_46 ,
V_1297 ,
V_1219 , V_1085 ) ;
}
int F_356 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_23 V_1226 ,
int V_1298 , int V_1299 ,
const T_2 * V_1259 , T_10 V_52 , T_11 V_1085 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1142 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return - V_119 ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_34 ( V_58 , V_413 , V_1298 ) ||
( V_1299 &&
F_34 ( V_58 , V_1300 , V_1299 ) ) ||
F_58 ( V_58 , V_1141 , V_52 , V_1259 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_353 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1226 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
return - V_74 ;
}
void F_357 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_517 ,
const T_2 * V_1259 , T_10 V_52 , bool V_1301 ,
T_11 V_1085 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1302 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_58 ( V_58 , V_1141 , V_52 , V_1259 ) ||
F_100 ( V_58 , V_1116 , V_517 ) ||
( V_1301 && F_35 ( V_58 , V_1303 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_249 ( V_58 , 0 , V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void
F_358 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
enum V_1304 V_1305 ,
T_11 V_1085 )
{
struct V_44 * V_58 ;
struct V_4 * V_746 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1306 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_746 = F_50 ( V_58 , V_1162 ) ;
if ( ! V_746 )
goto V_63;
if ( F_34 ( V_58 , V_1307 ,
V_1305 ) )
goto V_63;
F_51 ( V_58 , V_746 ) ;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_359 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_432 ,
const T_2 * V_1215 , T_11 V_1085 )
{
struct V_44 * V_58 ;
struct V_4 * V_1308 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1309 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_432 ) )
goto V_63;
V_1308 = F_50 ( V_58 , V_1203 ) ;
if ( ! V_1308 )
goto V_63;
if ( F_58 ( V_58 , V_1206 ,
V_1207 , V_1215 ) )
goto V_63;
F_51 ( V_58 , V_1308 ) ;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_360 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_1310 ,
const T_2 * V_432 , bool V_1311 , T_11 V_1085 )
{
struct V_44 * V_58 ;
struct V_4 * V_50 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1312 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_50 = F_50 ( V_58 , V_1313 ) ;
if ( ! V_50 )
goto V_63;
if ( F_34 ( V_58 , V_1314 , V_1310 ) ||
F_58 ( V_58 , V_1315 , V_470 , V_432 ) ||
( V_1311 &&
F_35 ( V_58 , V_1316 ) ) )
goto V_63;
F_51 ( V_58 , V_50 ) ;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_361 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
struct V_410 * V_411 , T_11 V_1085 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1317 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
if ( F_96 ( V_58 , V_411 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void
F_362 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1105 ,
V_23 V_1318 , V_23 V_173 , V_23 V_1154 , T_11 V_1085 )
{
struct V_44 * V_58 ;
struct V_4 * V_746 ;
void * V_162 ;
V_58 = F_69 ( V_1293 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1306 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_1105 ) )
goto V_63;
V_746 = F_50 ( V_58 , V_1162 ) ;
if ( ! V_746 )
goto V_63;
if ( F_34 ( V_58 , V_1167 , V_1318 ) )
goto V_63;
if ( F_34 ( V_58 , V_1166 , V_173 ) )
goto V_63;
if ( F_34 ( V_58 , V_1168 , V_1154 ) )
goto V_63;
F_51 ( V_58 , V_746 ) ;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void
F_363 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1105 ,
V_23 V_1318 , T_11 V_1085 )
{
struct V_44 * V_58 ;
struct V_4 * V_746 ;
void * V_162 ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1306 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_1105 ) )
goto V_63;
V_746 = F_50 ( V_58 , V_1162 ) ;
if ( ! V_746 )
goto V_63;
if ( F_34 ( V_58 , V_1319 , V_1318 ) )
goto V_63;
F_51 ( V_58 , V_746 ) ;
F_63 ( V_58 , V_162 ) ;
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_364 ( struct V_26 * V_46 , const T_2 * V_1219 ,
T_1 V_517 , bool V_1320 , T_11 V_1085 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
F_365 ( V_46 , V_1219 , V_517 , V_1320 ) ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1220 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_433 , V_470 , V_1219 ) ||
F_100 ( V_58 , V_1116 , V_517 ) ||
( V_1320 && F_35 ( V_58 , V_1303 ) ) )
goto V_63;
V_47 = F_63 ( V_58 , V_162 ) ;
if ( V_47 < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_366 ( struct V_18 * V_18 ,
const T_2 * V_1321 , T_10 V_52 ,
int V_1298 , int V_1299 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
struct V_1221 * V_1222 ;
F_367 ( V_18 , V_1321 , V_52 , V_1298 , V_1299 ) ;
F_214 ( & V_7 -> V_1225 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_58 = F_69 ( V_52 + 100 , V_1258 ) ;
if ( ! V_58 ) {
F_216 ( & V_7 -> V_1225 ) ;
return;
}
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1142 ) ;
if ( ! V_162 )
goto V_63;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_1298 &&
F_34 ( V_58 , V_413 , V_1298 ) ) ||
( V_1299 &&
F_34 ( V_58 , V_1300 , V_1299 ) ) ||
F_58 ( V_58 , V_1141 , V_52 , V_1321 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_353 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1222 -> V_1226 ) ;
}
F_216 ( & V_7 -> V_1225 ) ;
return;
V_63:
F_216 ( & V_7 -> V_1225 ) ;
if ( V_162 )
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_368 ( struct V_26 * V_46 , const T_2 * V_1105 ,
enum V_1109 V_1322 ,
T_3 V_1060 , T_11 V_1085 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
F_369 ( V_17 -> V_18 , V_46 , V_1105 , V_1322 ,
V_1060 ) ;
V_58 = F_69 ( V_393 , V_1085 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1323 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_56 ( V_58 , V_1111 , V_1322 ) ||
F_58 ( V_58 , V_433 , V_470 , V_1105 ) ||
( V_1060 > 0 &&
F_57 ( V_58 , V_1061 , V_1060 ) ) )
goto V_63;
V_47 = F_63 ( V_58 , V_162 ) ;
if ( V_47 < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_316 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1260 . V_1087 , V_1085 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static int F_370 ( struct V_1324 * V_1325 ,
unsigned long V_1144 ,
void * V_1326 )
{
struct V_1327 * V_1328 = V_1326 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1221 * V_1222 , * V_25 ;
if ( V_1144 != V_1329 )
return V_1330 ;
F_209 () ;
F_371 (rdev, &cfg80211_rdev_list, list) {
F_371 (wdev, &rdev->wdev_list, list)
F_372 ( V_17 , V_1328 -> V_54 ) ;
F_214 ( & V_7 -> V_1225 ) ;
F_373 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1222 -> V_1226 == V_1328 -> V_54 ) {
F_374 ( & V_1222 -> V_510 ) ;
F_46 ( V_1222 ) ;
break;
}
}
F_216 ( & V_7 -> V_1225 ) ;
}
F_211 () ;
return V_1330 ;
}
int F_375 ( void )
{
int V_47 ;
V_47 = F_376 ( & V_39 ,
V_1331 , F_377 ( V_1331 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_378 ( & V_39 , & V_1240 ) ;
if ( V_47 )
goto V_1332;
V_47 = F_378 ( & V_39 , & V_1244 ) ;
if ( V_47 )
goto V_1332;
V_47 = F_378 ( & V_39 , & V_1257 ) ;
if ( V_47 )
goto V_1332;
V_47 = F_378 ( & V_39 , & V_1260 ) ;
if ( V_47 )
goto V_1332;
#ifdef F_61
V_47 = F_378 ( & V_39 , & V_1086 ) ;
if ( V_47 )
goto V_1332;
#endif
V_47 = F_379 ( & V_1333 ) ;
if ( V_47 )
goto V_1332;
return 0 ;
V_1332:
F_380 ( & V_39 ) ;
return V_47 ;
}
void F_381 ( void )
{
F_382 ( & V_1333 ) ;
F_380 ( & V_39 ) ;
}
