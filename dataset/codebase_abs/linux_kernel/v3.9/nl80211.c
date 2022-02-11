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
. V_378 =
V_46 -> V_18 . V_351 . V_378 ,
} ;
if ( F_58 ( V_58 , V_379 ,
sizeof( V_372 ) , & V_372 ) )
goto V_63;
}
F_51 ( V_58 , V_353 ) ;
}
#endif
if ( F_49 ( V_58 , V_380 ,
V_46 -> V_18 . V_381 ) )
goto V_63;
if ( F_52 ( & V_46 -> V_18 , V_58 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_382 ) &&
F_34 ( V_58 , V_383 ,
V_46 -> V_18 . V_384 ) )
goto V_63;
if ( F_34 ( V_58 , V_385 ,
V_46 -> V_18 . V_386 ) )
goto V_63;
if ( V_46 -> V_18 . V_387 &&
F_58 ( V_58 , V_388 ,
sizeof( * V_46 -> V_18 . V_387 ) ,
V_46 -> V_18 . V_387 ) )
goto V_63;
if ( V_46 -> V_18 . V_56 & V_382 &&
V_46 -> V_18 . V_389 &&
F_34 ( V_58 , V_390 ,
V_46 -> V_18 . V_389 ) )
goto V_63;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_391 ;
}
static int F_65 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_88 = 0 , V_392 ;
int V_393 = V_35 -> args [ 0 ] ;
struct V_6 * V_46 ;
F_8 ( & V_32 ) ;
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_66 ( F_7 ( & V_46 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( ++ V_88 <= V_393 )
continue;
V_392 = F_53 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_394 , V_395 ,
V_46 ) ;
if ( V_392 < 0 ) {
if ( ( V_392 == - V_74 || V_392 == - V_391 ) &&
! V_45 -> V_52 &&
V_35 -> V_396 < 4096 ) {
V_35 -> V_396 = 4096 ;
F_9 ( & V_32 ) ;
return 1 ;
}
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
struct V_6 * V_46 = V_31 -> V_397 [ 0 ] ;
V_58 = F_69 ( 4096 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_53 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 , V_46 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_72 ( struct V_4 * V_78 [] ,
struct V_400 * V_401 )
{
if ( ! V_78 [ V_402 ] || ! V_78 [ V_403 ] ||
! V_78 [ V_404 ] || ! V_78 [ V_405 ] ||
! V_78 [ V_406 ] )
return - V_16 ;
V_401 -> V_407 = F_39 ( V_78 [ V_402 ] ) ;
V_401 -> V_408 = F_73 ( V_78 [ V_403 ] ) ;
V_401 -> V_409 = F_73 ( V_78 [ V_404 ] ) ;
V_401 -> V_410 = F_73 ( V_78 [ V_405 ] ) ;
V_401 -> V_411 = F_39 ( V_78 [ V_406 ] ) ;
if ( V_401 -> V_407 >= V_412 )
return - V_16 ;
return 0 ;
}
static bool F_74 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_124 == V_125 ||
V_17 -> V_124 == V_128 ||
V_17 -> V_124 == V_413 ||
V_17 -> V_124 == V_127 ;
}
static int F_75 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_414 * V_415 )
{
V_23 V_416 ;
if ( ! V_31 -> V_5 [ V_417 ] )
return - V_16 ;
V_416 = F_4 ( V_31 -> V_5 [ V_417 ] ) ;
V_415 -> V_60 = F_76 ( & V_7 -> V_18 , V_416 ) ;
V_415 -> V_418 = V_419 ;
V_415 -> V_420 = V_416 ;
V_415 -> V_421 = 0 ;
if ( ! V_415 -> V_60 || V_415 -> V_60 -> V_56 & V_64 )
return - V_16 ;
if ( V_31 -> V_5 [ V_422 ] ) {
enum V_423 V_424 ;
V_424 = F_4 (
V_31 -> V_5 [ V_422 ] ) ;
switch ( V_424 ) {
case V_425 :
case V_426 :
case V_427 :
case V_428 :
F_77 ( V_415 , V_415 -> V_60 ,
V_424 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_31 -> V_5 [ V_429 ] ) {
V_415 -> V_418 =
F_4 ( V_31 -> V_5 [ V_429 ] ) ;
if ( V_31 -> V_5 [ V_430 ] )
V_415 -> V_420 =
F_4 (
V_31 -> V_5 [ V_430 ] ) ;
if ( V_31 -> V_5 [ V_431 ] )
V_415 -> V_421 =
F_4 (
V_31 -> V_5 [ V_431 ] ) ;
}
if ( ! F_78 ( V_415 ) )
return - V_16 ;
if ( ! F_79 ( & V_7 -> V_18 , V_415 ,
V_64 ) )
return - V_16 ;
return 0 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_30 * V_31 )
{
struct V_414 V_415 ;
int V_8 ;
enum V_342 V_124 = V_413 ;
if ( V_17 )
V_124 = V_17 -> V_124 ;
if ( ! F_74 ( V_17 ) )
return - V_432 ;
V_8 = F_75 ( V_7 , V_31 , & V_415 ) ;
if ( V_8 )
return V_8 ;
F_8 ( & V_7 -> V_19 ) ;
switch ( V_124 ) {
case V_125 :
case V_127 :
if ( V_17 -> V_433 ) {
V_8 = - V_434 ;
break;
}
if ( ! F_81 ( & V_7 -> V_18 , & V_415 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_435 = V_415 ;
V_8 = 0 ;
break;
case V_128 :
V_8 = F_82 ( V_7 , V_17 , & V_415 ) ;
break;
case V_413 :
V_8 = F_83 ( V_7 , & V_415 ) ;
break;
default:
V_8 = - V_16 ;
}
F_9 ( & V_7 -> V_19 ) ;
return V_8 ;
}
static int F_84 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_20 = V_31 -> V_397 [ 1 ] ;
return F_80 ( V_7 , V_20 -> V_29 , V_31 ) ;
}
static int F_85 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
const T_2 * V_436 ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( F_86 ( V_46 ) )
return - V_434 ;
if ( ! V_7 -> V_226 -> V_310 )
return - V_432 ;
if ( V_17 -> V_124 != V_438 )
return - V_432 ;
V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
return F_87 ( V_7 , V_46 , V_436 ) ;
}
static int F_88 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_26 * V_20 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_439 = 0 ;
struct V_4 * V_440 ;
V_23 V_441 ;
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
goto V_442;
if ( V_31 -> V_5 [ V_443 ] ) {
struct V_400 V_401 ;
struct V_4 * V_78 [ V_444 + 1 ] ;
if ( ! V_7 -> V_226 -> V_445 ) {
V_8 = - V_432 ;
goto V_442;
}
if ( ! V_20 ) {
V_8 = - V_16 ;
goto V_442;
}
if ( V_20 -> V_29 -> V_124 != V_125 &&
V_20 -> V_29 -> V_124 != V_127 ) {
V_8 = - V_16 ;
goto V_442;
}
if ( ! F_86 ( V_20 ) ) {
V_8 = - V_446 ;
goto V_442;
}
F_44 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_91 ( V_78 , V_444 ,
F_29 ( V_440 ) ,
F_30 ( V_440 ) ,
V_447 ) ;
V_8 = F_72 ( V_78 , & V_401 ) ;
if ( V_8 )
goto V_442;
V_8 = F_92 ( V_7 , V_20 ,
& V_401 ) ;
if ( V_8 )
goto V_442;
}
}
if ( V_31 -> V_5 [ V_417 ] ) {
V_8 = F_80 ( V_7 ,
F_74 ( V_17 ) ? V_17 : NULL ,
V_31 ) ;
if ( V_8 )
goto V_442;
}
if ( V_31 -> V_5 [ V_448 ] ) {
struct V_1 * V_449 = V_17 ;
enum V_450 type ;
int V_88 , V_451 = 0 ;
if ( ! ( V_7 -> V_18 . V_386 & V_452 ) )
V_449 = NULL ;
if ( ! V_7 -> V_226 -> V_453 ) {
V_8 = - V_432 ;
goto V_442;
}
V_88 = V_448 ;
type = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
if ( ! V_31 -> V_5 [ V_454 ] &&
( type != V_455 ) ) {
V_8 = - V_16 ;
goto V_442;
}
if ( type != V_455 ) {
V_88 = V_454 ;
V_451 = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
}
V_8 = F_93 ( V_7 , V_449 , type , V_451 ) ;
if ( V_8 )
goto V_442;
}
if ( V_31 -> V_5 [ V_230 ] &&
V_31 -> V_5 [ V_231 ] ) {
V_23 V_228 , V_229 ;
if ( ( ! V_7 -> V_18 . V_220 &&
! V_7 -> V_18 . V_222 ) ||
! V_7 -> V_226 -> V_456 ) {
V_8 = - V_432 ;
goto V_442;
}
V_228 = F_4 ( V_31 -> V_5 [ V_230 ] ) ;
V_229 = F_4 ( V_31 -> V_5 [ V_231 ] ) ;
if ( ( ~ V_228 && ( V_228 & ~ V_7 -> V_18 . V_220 ) ) ||
( ~ V_229 && ( V_229 & ~ V_7 -> V_18 . V_222 ) ) ) {
V_8 = - V_16 ;
goto V_442;
}
V_228 = V_228 & V_7 -> V_18 . V_220 ;
V_229 = V_229 & V_7 -> V_18 . V_222 ;
V_8 = F_94 ( V_7 , V_228 , V_229 ) ;
if ( V_8 )
goto V_442;
}
V_441 = 0 ;
if ( V_31 -> V_5 [ V_180 ] ) {
V_181 = F_39 (
V_31 -> V_5 [ V_180 ] ) ;
if ( V_181 == 0 ) {
V_8 = - V_16 ;
goto V_442;
}
V_441 |= V_457 ;
}
if ( V_31 -> V_5 [ V_182 ] ) {
V_183 = F_39 (
V_31 -> V_5 [ V_182 ] ) ;
if ( V_183 == 0 ) {
V_8 = - V_16 ;
goto V_442;
}
V_441 |= V_458 ;
}
if ( V_31 -> V_5 [ V_184 ] ) {
V_185 = F_4 (
V_31 -> V_5 [ V_184 ] ) ;
if ( V_185 < 256 ) {
V_8 = - V_16 ;
goto V_442;
}
if ( V_185 != ( V_23 ) - 1 ) {
V_185 &= ~ 0x1 ;
}
V_441 |= V_459 ;
}
if ( V_31 -> V_5 [ V_186 ] ) {
V_187 = F_4 (
V_31 -> V_5 [ V_186 ] ) ;
V_441 |= V_460 ;
}
if ( V_31 -> V_5 [ V_188 ] ) {
V_189 = F_39 (
V_31 -> V_5 [ V_188 ] ) ;
V_441 |= V_461 ;
}
if ( V_441 ) {
T_2 V_462 , V_463 ;
V_23 V_464 , V_465 ;
T_2 V_466 ;
if ( ! V_7 -> V_226 -> V_467 ) {
V_8 = - V_432 ;
goto V_442;
}
V_462 = V_7 -> V_18 . V_181 ;
V_463 = V_7 -> V_18 . V_183 ;
V_464 = V_7 -> V_18 . V_185 ;
V_465 = V_7 -> V_18 . V_187 ;
V_466 = V_7 -> V_18 . V_189 ;
if ( V_441 & V_457 )
V_7 -> V_18 . V_181 = V_181 ;
if ( V_441 & V_458 )
V_7 -> V_18 . V_183 = V_183 ;
if ( V_441 & V_459 )
V_7 -> V_18 . V_185 = V_185 ;
if ( V_441 & V_460 )
V_7 -> V_18 . V_187 = V_187 ;
if ( V_441 & V_461 )
V_7 -> V_18 . V_189 = V_189 ;
V_8 = F_95 ( V_7 , V_441 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_181 = V_462 ;
V_7 -> V_18 . V_183 = V_463 ;
V_7 -> V_18 . V_185 = V_464 ;
V_7 -> V_18 . V_187 = V_465 ;
V_7 -> V_18 . V_189 = V_466 ;
}
}
V_442:
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
struct V_414 * V_415 )
{
F_97 ( ! F_78 ( V_415 ) ) ;
if ( F_34 ( V_58 , V_417 ,
V_415 -> V_60 -> V_62 ) )
return - V_74 ;
switch ( V_415 -> V_418 ) {
case V_419 :
case V_468 :
case V_469 :
if ( F_34 ( V_58 , V_422 ,
F_98 ( V_415 ) ) )
return - V_74 ;
break;
default:
break;
}
if ( F_34 ( V_58 , V_429 , V_415 -> V_418 ) )
return - V_74 ;
if ( F_34 ( V_58 , V_430 , V_415 -> V_420 ) )
return - V_74 ;
if ( V_415 -> V_421 &&
F_34 ( V_58 , V_431 , V_415 -> V_421 ) )
return - V_74 ;
return 0 ;
}
static int F_99 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 , int V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_26 * V_46 = V_17 -> V_20 ;
void * V_162 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_470 ) ;
if ( ! V_162 )
return - 1 ;
if ( V_46 &&
( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_54 ( V_58 , V_471 , V_46 -> V_472 ) ) )
goto V_63;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_473 , V_17 -> V_124 ) ||
F_100 ( V_58 , V_12 , V_13 ( V_17 ) ) ||
F_58 ( V_58 , V_437 , V_474 , F_101 ( V_17 ) ) ||
F_34 ( V_58 , V_178 ,
V_7 -> V_475 ^
( V_179 << 2 ) ) )
goto V_63;
if ( V_7 -> V_226 -> V_476 ) {
int V_392 ;
struct V_414 V_415 ;
V_392 = F_102 ( V_7 , V_17 , & V_415 ) ;
if ( V_392 == 0 ) {
if ( F_96 ( V_58 , & V_415 ) )
goto V_63;
}
}
if ( V_17 -> V_477 ) {
if ( F_58 ( V_58 , V_478 , V_17 -> V_477 , V_17 -> V_479 ) )
goto V_63;
}
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_391 ;
}
static int F_103 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_480 = 0 ;
int V_481 = 0 ;
int V_482 = V_35 -> args [ 0 ] ;
int V_483 = V_35 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_8 ( & V_32 ) ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_66 ( F_7 ( & V_7 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( V_480 < V_482 ) {
V_480 ++ ;
continue;
}
V_481 = 0 ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_481 < V_483 ) {
V_481 ++ ;
continue;
}
if ( F_99 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_394 , V_395 ,
V_7 , V_17 ) < 0 ) {
F_9 ( & V_7 -> V_19 ) ;
goto V_484;
}
V_481 ++ ;
}
F_9 ( & V_7 -> V_19 ) ;
V_480 ++ ;
}
V_484:
F_9 ( & V_32 ) ;
V_35 -> args [ 0 ] = V_480 ;
V_35 -> args [ 1 ] = V_481 ;
return V_45 -> V_52 ;
}
static int F_104 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
struct V_6 * V_46 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_99 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_46 , V_17 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_105 ( struct V_4 * V_486 , V_23 * V_487 )
{
struct V_4 * V_56 [ V_488 + 1 ] ;
int V_489 ;
* V_487 = 0 ;
if ( ! V_486 )
return - V_16 ;
if ( F_38 ( V_56 , V_488 ,
V_486 , V_490 ) )
return - V_16 ;
for ( V_489 = 1 ; V_489 <= V_488 ; V_489 ++ )
if ( V_56 [ V_489 ] )
* V_487 |= ( 1 << V_489 ) ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_2 V_491 ,
enum V_342 V_124 )
{
if ( ! V_491 ) {
if ( V_20 && ( V_20 -> V_492 & V_493 ) )
return - V_434 ;
return 0 ;
}
switch ( V_124 ) {
case V_126 :
if ( V_7 -> V_18 . V_56 & V_494 )
return 0 ;
break;
case V_132 :
if ( V_7 -> V_18 . V_56 & V_495 )
return 0 ;
break;
default:
break;
}
return - V_432 ;
}
static int F_107 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_496 V_120 ;
int V_47 ;
enum V_342 V_497 , V_498 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
V_23 V_499 , * V_56 = NULL ;
bool V_500 = false ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_497 = V_498 = V_46 -> V_29 -> V_124 ;
if ( V_31 -> V_5 [ V_473 ] ) {
V_498 = F_4 ( V_31 -> V_5 [ V_473 ] ) ;
if ( V_497 != V_498 )
V_500 = true ;
if ( V_498 > V_501 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_502 ] ) {
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_498 != V_128 )
return - V_16 ;
if ( F_86 ( V_46 ) )
return - V_434 ;
F_108 ( V_17 ) ;
F_109 ( V_503 !=
V_504 ) ;
V_17 -> V_505 =
F_30 ( V_31 -> V_5 [ V_502 ] ) ;
memcpy ( V_17 -> V_479 , F_29 ( V_31 -> V_5 [ V_502 ] ) ,
V_17 -> V_505 ) ;
F_110 ( V_17 ) ;
}
if ( V_31 -> V_5 [ V_506 ] ) {
V_120 . V_491 = ! ! F_39 ( V_31 -> V_5 [ V_506 ] ) ;
V_500 = true ;
V_47 = F_106 ( V_7 , V_46 , V_120 . V_491 , V_498 ) ;
if ( V_47 )
return V_47 ;
} else {
V_120 . V_491 = - 1 ;
}
if ( V_31 -> V_5 [ V_507 ] ) {
if ( V_498 != V_413 )
return - V_16 ;
V_47 = F_105 ( V_31 -> V_5 [ V_507 ] ,
& V_499 ) ;
if ( V_47 )
return V_47 ;
V_56 = & V_499 ;
V_500 = true ;
}
if ( V_500 )
V_47 = F_111 ( V_7 , V_46 , V_498 , V_56 , & V_120 ) ;
else
V_47 = 0 ;
if ( ! V_47 && V_120 . V_491 != - 1 )
V_46 -> V_29 -> V_491 = V_120 . V_491 ;
return V_47 ;
}
static int F_112 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_496 V_120 ;
struct V_1 * V_17 ;
struct V_44 * V_58 ;
int V_47 ;
enum V_342 type = V_508 ;
V_23 V_56 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
if ( ! V_31 -> V_5 [ V_471 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_473 ] ) {
type = F_4 ( V_31 -> V_5 [ V_473 ] ) ;
if ( type > V_501 )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_263 ||
! ( V_7 -> V_18 . V_233 & ( 1 << type ) ) )
return - V_432 ;
if ( type == V_509 && V_31 -> V_5 [ V_437 ] ) {
F_113 ( V_120 . V_510 , V_31 -> V_5 [ V_437 ] ,
V_474 ) ;
if ( ! F_114 ( V_120 . V_510 ) )
return - V_511 ;
}
if ( V_31 -> V_5 [ V_506 ] ) {
V_120 . V_491 = ! ! F_39 ( V_31 -> V_5 [ V_506 ] ) ;
V_47 = F_106 ( V_7 , NULL , V_120 . V_491 , type ) ;
if ( V_47 )
return V_47 ;
}
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_47 = F_105 ( type == V_413 ?
V_31 -> V_5 [ V_507 ] : NULL ,
& V_56 ) ;
V_17 = F_115 ( V_7 ,
F_29 ( V_31 -> V_5 [ V_471 ] ) ,
type , V_47 ? NULL : & V_56 , & V_120 ) ;
if ( F_16 ( V_17 ) ) {
F_70 ( V_58 ) ;
return F_24 ( V_17 ) ;
}
switch ( type ) {
case V_128 :
if ( ! V_31 -> V_5 [ V_502 ] )
break;
F_108 ( V_17 ) ;
F_109 ( V_503 !=
V_504 ) ;
V_17 -> V_505 =
F_30 ( V_31 -> V_5 [ V_502 ] ) ;
memcpy ( V_17 -> V_479 , F_29 ( V_31 -> V_5 [ V_502 ] ) ,
V_17 -> V_505 ) ;
F_110 ( V_17 ) ;
break;
case V_509 :
F_116 ( & V_17 -> V_33 ) ;
F_117 ( & V_17 -> V_512 ) ;
F_118 ( & V_17 -> V_513 ) ;
F_117 ( & V_17 -> V_514 ) ;
F_118 ( & V_17 -> V_515 ) ;
F_8 ( & V_7 -> V_19 ) ;
V_17 -> V_22 = ++ V_7 -> V_13 ;
F_119 ( & V_17 -> V_516 , & V_7 -> V_517 ) ;
V_7 -> V_475 ++ ;
F_9 ( & V_7 -> V_19 ) ;
break;
default:
break;
}
if ( F_99 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_7 , V_17 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_120 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
if ( ! V_7 -> V_226 -> V_518 )
return - V_432 ;
if ( ! V_17 -> V_20 )
V_31 -> V_397 [ 1 ] = NULL ;
return F_121 ( V_7 , V_17 ) ;
}
static int F_122 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_3 V_519 ;
if ( ! V_31 -> V_5 [ V_520 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_321 )
return - V_432 ;
V_519 = F_73 ( V_31 -> V_5 [ V_520 ] ) ;
return F_123 ( V_7 , V_46 , V_519 ) ;
}
static void F_124 ( void * V_144 , struct V_521 * V_120 )
{
struct V_4 * V_75 ;
struct V_522 * V_523 = V_144 ;
if ( ( V_120 -> V_75 &&
F_58 ( V_523 -> V_58 , V_104 ,
V_120 -> V_91 , V_120 -> V_75 ) ) ||
( V_120 -> V_55 &&
F_58 ( V_523 -> V_58 , V_105 ,
V_120 -> V_93 , V_120 -> V_55 ) ) ||
( V_120 -> V_95 &&
F_34 ( V_523 -> V_58 , V_107 ,
V_120 -> V_95 ) ) )
goto V_63;
V_75 = F_50 ( V_523 -> V_58 , V_112 ) ;
if ( ! V_75 )
goto V_63;
if ( ( V_120 -> V_75 &&
F_58 ( V_523 -> V_58 , V_89 ,
V_120 -> V_91 , V_120 -> V_75 ) ) ||
( V_120 -> V_55 &&
F_58 ( V_523 -> V_58 , V_92 ,
V_120 -> V_93 , V_120 -> V_55 ) ) ||
( V_120 -> V_95 &&
F_34 ( V_523 -> V_58 , V_94 ,
V_120 -> V_95 ) ) )
goto V_63;
if ( F_56 ( V_523 -> V_58 , V_106 , V_523 -> V_88 ) )
goto V_63;
F_51 ( V_523 -> V_58 , V_75 ) ;
return;
V_63:
V_523 -> error = 1 ;
}
static int F_125 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 V_524 = 0 ;
const T_2 * V_525 = NULL ;
bool V_526 ;
struct V_522 V_523 = {
. error = 0 ,
} ;
void * V_162 ;
struct V_44 * V_58 ;
if ( V_31 -> V_5 [ V_106 ] )
V_524 = F_39 ( V_31 -> V_5 [ V_106 ] ) ;
if ( V_524 > 5 )
return - V_16 ;
if ( V_31 -> V_5 [ V_437 ] )
V_525 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_526 = ! ! V_525 ;
if ( V_31 -> V_5 [ V_110 ] ) {
V_23 V_527 = F_4 ( V_31 -> V_5 [ V_110 ] ) ;
if ( V_527 >= V_97 )
return - V_16 ;
if ( V_527 != V_528 &&
V_527 != V_529 )
return - V_16 ;
V_526 = V_527 == V_529 ;
}
if ( ! V_7 -> V_226 -> V_530 )
return - V_432 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_531 ) ;
if ( F_16 ( V_162 ) )
return F_24 ( V_162 ) ;
V_523 . V_58 = V_58 ;
V_523 . V_88 = V_524 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_56 ( V_58 , V_106 , V_524 ) )
goto V_63;
if ( V_525 &&
F_58 ( V_58 , V_437 , V_474 , V_525 ) )
goto V_63;
if ( V_526 && V_525 &&
! ( V_7 -> V_18 . V_56 & V_200 ) )
return - V_532 ;
V_47 = F_126 ( V_7 , V_46 , V_524 , V_526 , V_525 , & V_523 ,
F_124 ) ;
if ( V_47 )
goto V_533;
if ( V_523 . error )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_533:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_127 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_76 V_75 ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 < 0 )
return - V_16 ;
if ( ! V_75 . V_81 && ! V_75 . V_83 )
return - V_16 ;
F_108 ( V_46 -> V_29 ) ;
if ( V_75 . V_81 ) {
if ( ! V_7 -> V_226 -> V_534 ) {
V_47 = - V_432 ;
goto V_484;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_484;
V_47 = F_128 ( V_7 , V_46 , V_75 . V_88 ,
V_75 . V_85 , V_75 . V_86 ) ;
if ( V_47 )
goto V_484;
#ifdef F_129
V_46 -> V_29 -> V_535 . V_536 = V_75 . V_88 ;
#endif
} else {
if ( V_75 . V_85 || ! V_75 . V_86 ) {
V_47 = - V_16 ;
goto V_484;
}
if ( ! V_7 -> V_226 -> V_537 ) {
V_47 = - V_432 ;
goto V_484;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_484;
V_47 = F_130 ( V_7 , V_46 , V_75 . V_88 ) ;
if ( V_47 )
goto V_484;
#ifdef F_129
V_46 -> V_29 -> V_535 . V_538 = V_75 . V_88 ;
#endif
}
V_484:
F_110 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_131 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_76 V_75 ;
const T_2 * V_525 = NULL ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_75 . V_90 . V_75 )
return - V_16 ;
if ( V_31 -> V_5 [ V_437 ] )
V_525 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_525 )
V_75 . type = V_529 ;
else
V_75 . type = V_528 ;
}
if ( V_75 . type != V_529 &&
V_75 . type != V_528 )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_267 )
return - V_432 ;
if ( F_45 ( V_7 , & V_75 . V_90 , V_75 . V_88 ,
V_75 . type == V_529 ,
V_525 ) )
return - V_16 ;
F_108 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( ! V_47 )
V_47 = F_132 ( V_7 , V_46 , V_75 . V_88 ,
V_75 . type == V_529 ,
V_525 , & V_75 . V_90 ) ;
F_110 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_133 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 * V_525 = NULL ;
struct V_76 V_75 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_437 ] )
V_525 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_525 )
V_75 . type = V_529 ;
else
V_75 . type = V_528 ;
}
if ( V_75 . type != V_529 &&
V_75 . type != V_528 )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_539 )
return - V_432 ;
F_108 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_75 . type == V_529 && V_525 &&
! ( V_7 -> V_18 . V_56 & V_200 ) )
V_47 = - V_532 ;
if ( ! V_47 )
V_47 = F_134 ( V_7 , V_46 , V_75 . V_88 ,
V_75 . type == V_529 ,
V_525 ) ;
#ifdef F_129
if ( ! V_47 ) {
if ( V_75 . V_88 == V_46 -> V_29 -> V_535 . V_536 )
V_46 -> V_29 -> V_535 . V_536 = - 1 ;
else if ( V_75 . V_88 == V_46 -> V_29 -> V_535 . V_538 )
V_46 -> V_29 -> V_535 . V_538 = - 1 ;
}
#endif
F_110 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_135 ( struct V_4 * V_540 )
{
struct V_4 * V_50 ;
int V_541 = 0 , V_25 ;
F_44 (attr, nl_attr, tmp) {
if ( F_30 ( V_50 ) != V_474 )
return - V_16 ;
V_541 ++ ;
}
return V_541 ;
}
static struct V_542 * F_136 ( struct V_18 * V_18 ,
struct V_30 * V_31 )
{
enum V_543 V_544 ;
struct V_4 * V_50 ;
struct V_542 * V_545 ;
int V_138 = 0 , V_541 , V_25 ;
if ( ! V_18 -> V_389 )
return F_3 ( - V_432 ) ;
if ( ! V_31 -> V_5 [ V_546 ] )
return F_3 ( - V_16 ) ;
V_544 = F_4 ( V_31 -> V_5 [ V_546 ] ) ;
if ( V_544 != V_547 &&
V_544 != V_548 )
return F_3 ( - V_16 ) ;
if ( ! V_31 -> V_5 [ V_549 ] )
return F_3 ( - V_16 ) ;
V_541 = F_135 ( V_31 -> V_5 [ V_549 ] ) ;
if ( V_541 < 0 )
return F_3 ( V_541 ) ;
if ( V_541 > V_18 -> V_389 )
return F_3 ( - V_550 ) ;
V_545 = F_43 ( sizeof( * V_545 ) + ( sizeof( struct V_551 ) * V_541 ) ,
V_118 ) ;
if ( ! V_545 )
return F_3 ( - V_119 ) ;
F_44 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_545 -> V_552 [ V_138 ] . V_553 , F_29 ( V_50 ) , V_474 ) ;
V_138 ++ ;
}
V_545 -> V_554 = V_541 ;
V_545 -> V_544 = V_544 ;
return V_545 ;
}
static int F_137 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_542 * V_545 ;
int V_47 ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_432 ;
if ( ! V_46 -> V_29 -> V_433 )
return - V_16 ;
V_545 = F_136 ( & V_7 -> V_18 , V_31 ) ;
if ( F_16 ( V_545 ) )
return F_24 ( V_545 ) ;
V_47 = F_138 ( V_7 , V_46 , V_545 ) ;
F_46 ( V_545 ) ;
return V_47 ;
}
static int F_139 ( struct V_30 * V_31 ,
struct V_555 * V_556 )
{
bool V_557 = false ;
if ( ! F_28 ( V_31 -> V_5 [ V_558 ] ) ||
! F_28 ( V_31 -> V_5 [ V_559 ] ) ||
! F_28 ( V_31 -> V_5 [ V_560 ] ) ||
! F_28 ( V_31 -> V_5 [ V_561 ] ) )
return - V_16 ;
memset ( V_556 , 0 , sizeof( * V_556 ) ) ;
if ( V_31 -> V_5 [ V_562 ] ) {
V_556 -> V_563 = F_29 ( V_31 -> V_5 [ V_562 ] ) ;
V_556 -> V_564 = F_30 ( V_31 -> V_5 [ V_562 ] ) ;
if ( ! V_556 -> V_564 )
return - V_16 ;
V_557 = true ;
}
if ( V_31 -> V_5 [ V_558 ] ) {
V_556 -> V_565 = F_29 ( V_31 -> V_5 [ V_558 ] ) ;
V_556 -> V_566 =
F_30 ( V_31 -> V_5 [ V_558 ] ) ;
V_557 = true ;
}
if ( ! V_557 )
return - V_16 ;
if ( V_31 -> V_5 [ V_559 ] ) {
V_556 -> V_567 = F_29 ( V_31 -> V_5 [ V_559 ] ) ;
V_556 -> V_568 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
}
if ( V_31 -> V_5 [ V_560 ] ) {
V_556 -> V_569 =
F_29 ( V_31 -> V_5 [ V_560 ] ) ;
V_556 -> V_570 =
F_30 ( V_31 -> V_5 [ V_560 ] ) ;
}
if ( V_31 -> V_5 [ V_561 ] ) {
V_556 -> V_571 =
F_29 ( V_31 -> V_5 [ V_561 ] ) ;
V_556 -> V_572 =
F_30 ( V_31 -> V_5 [ V_561 ] ) ;
}
if ( V_31 -> V_5 [ V_573 ] ) {
V_556 -> V_574 =
F_29 ( V_31 -> V_5 [ V_573 ] ) ;
V_556 -> V_575 =
F_30 ( V_31 -> V_5 [ V_573 ] ) ;
}
return 0 ;
}
static bool F_140 ( struct V_6 * V_7 ,
struct V_576 * V_120 )
{
struct V_1 * V_17 ;
bool V_392 = false ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_124 != V_125 &&
V_17 -> V_124 != V_127 )
continue;
if ( ! V_17 -> V_435 . V_60 )
continue;
V_120 -> V_415 = V_17 -> V_435 ;
V_392 = true ;
break;
}
F_9 ( & V_7 -> V_19 ) ;
return V_392 ;
}
static bool F_141 ( struct V_6 * V_7 ,
enum V_577 V_578 ,
enum V_579 V_57 )
{
if ( V_578 > V_580 )
return false ;
switch ( V_57 ) {
case V_581 :
if ( ! ( V_7 -> V_18 . V_386 & V_582 ) &&
V_578 == V_583 )
return false ;
return true ;
case V_332 :
case V_584 :
if ( V_578 == V_583 )
return false ;
return true ;
default:
return false ;
}
}
static int F_142 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_576 V_120 ;
int V_47 ;
T_2 V_585 = 0 ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_432 ;
if ( ! V_7 -> V_226 -> V_269 )
return - V_432 ;
if ( V_17 -> V_433 )
return - V_586 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
if ( ! V_31 -> V_5 [ V_587 ] ||
! V_31 -> V_5 [ V_588 ] ||
! V_31 -> V_5 [ V_562 ] )
return - V_16 ;
V_47 = F_139 ( V_31 , & V_120 . V_589 ) ;
if ( V_47 )
return V_47 ;
V_120 . V_433 =
F_4 ( V_31 -> V_5 [ V_587 ] ) ;
V_120 . V_590 =
F_4 ( V_31 -> V_5 [ V_588 ] ) ;
V_47 = F_143 ( V_7 , V_120 . V_433 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_478 ] ) {
V_120 . V_479 = F_29 ( V_31 -> V_5 [ V_478 ] ) ;
V_120 . V_477 =
F_30 ( V_31 -> V_5 [ V_478 ] ) ;
if ( V_120 . V_477 == 0 ||
V_120 . V_477 > V_503 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_591 ] ) {
V_120 . V_592 = F_4 (
V_31 -> V_5 [ V_591 ] ) ;
if ( V_120 . V_592 != V_593 &&
V_120 . V_592 != V_594 &&
V_120 . V_592 != V_595 )
return - V_16 ;
}
V_120 . V_596 = ! ! V_31 -> V_5 [ V_597 ] ;
if ( V_31 -> V_5 [ V_598 ] ) {
V_120 . V_578 = F_4 (
V_31 -> V_5 [ V_598 ] ) ;
if ( ! F_141 ( V_7 , V_120 . V_578 ,
V_584 ) )
return - V_16 ;
} else
V_120 . V_578 = V_599 ;
V_47 = F_144 ( V_7 , V_31 , & V_120 . V_600 ,
V_601 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_602 ] ) {
if ( ! ( V_7 -> V_18 . V_386 & V_603 ) )
return - V_432 ;
V_120 . V_604 = F_73 (
V_31 -> V_5 [ V_602 ] ) ;
}
if ( V_31 -> V_5 [ V_605 ] ) {
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_120 . V_606 =
F_39 ( V_31 -> V_5 [ V_605 ] ) ;
if ( V_120 . V_606 > 127 )
return - V_16 ;
if ( V_120 . V_606 != 0 &&
! ( V_7 -> V_18 . V_386 & V_607 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_608 ] ) {
T_2 V_25 ;
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_25 = F_39 ( V_31 -> V_5 [ V_608 ] ) ;
if ( V_25 > 1 )
return - V_16 ;
V_120 . V_609 = V_25 ;
if ( V_120 . V_609 != 0 &&
! ( V_7 -> V_18 . V_386 & V_610 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_417 ] ) {
V_47 = F_75 ( V_7 , V_31 , & V_120 . V_415 ) ;
if ( V_47 )
return V_47 ;
} else if ( V_17 -> V_435 . V_60 ) {
V_120 . V_415 = V_17 -> V_435 ;
} else if ( ! F_140 ( V_7 , & V_120 ) )
return - V_16 ;
if ( ! F_81 ( & V_7 -> V_18 , & V_120 . V_415 ) )
return - V_16 ;
V_47 = F_145 ( V_17 -> V_18 , & V_120 . V_415 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_47 ) {
V_585 = F_146 ( V_120 . V_415 . V_418 ) ;
V_120 . V_611 = true ;
}
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_147 ( V_7 , V_17 , V_17 -> V_124 ,
V_120 . V_415 . V_60 ,
V_612 ,
V_585 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_546 ] ) {
V_120 . V_545 = F_136 ( & V_7 -> V_18 , V_31 ) ;
if ( F_16 ( V_120 . V_545 ) )
return F_24 ( V_120 . V_545 ) ;
}
V_47 = F_148 ( V_7 , V_46 , & V_120 ) ;
if ( ! V_47 ) {
V_17 -> V_435 = V_120 . V_415 ;
V_17 -> V_433 = V_120 . V_433 ;
V_17 -> V_613 = V_120 . V_415 . V_60 ;
V_17 -> V_477 = V_120 . V_477 ;
memcpy ( V_17 -> V_479 , V_120 . V_479 , V_17 -> V_477 ) ;
}
F_46 ( V_120 . V_545 ) ;
return V_47 ;
}
static int F_149 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_555 V_120 ;
int V_47 ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_432 ;
if ( ! V_7 -> V_226 -> V_614 )
return - V_432 ;
if ( ! V_17 -> V_433 )
return - V_16 ;
V_47 = F_139 ( V_31 , & V_120 ) ;
if ( V_47 )
return V_47 ;
return F_150 ( V_7 , V_46 , & V_120 ) ;
}
static int F_151 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
return F_152 ( V_7 , V_46 ) ;
}
static int F_153 ( struct V_30 * V_31 ,
enum V_342 V_124 ,
struct V_615 * V_120 )
{
struct V_4 * V_56 [ V_616 + 1 ] ;
struct V_4 * V_486 ;
int V_489 ;
V_486 = V_31 -> V_5 [ V_617 ] ;
if ( V_486 ) {
struct V_618 * V_619 ;
V_619 = F_29 ( V_486 ) ;
V_120 -> V_620 = V_619 -> V_621 ;
V_120 -> V_622 = V_619 -> V_623 ;
if ( ( V_120 -> V_620 |
V_120 -> V_622 ) & F_146 ( V_624 ) )
return - V_16 ;
return 0 ;
}
V_486 = V_31 -> V_5 [ V_625 ] ;
if ( ! V_486 )
return 0 ;
if ( F_38 ( V_56 , V_616 ,
V_486 , V_626 ) )
return - V_16 ;
switch ( V_124 ) {
case V_125 :
case V_126 :
case V_127 :
V_120 -> V_620 = F_146 ( V_627 ) |
F_146 ( V_628 ) |
F_146 ( V_629 ) |
F_146 ( V_630 ) ;
break;
case V_133 :
case V_132 :
V_120 -> V_620 = F_146 ( V_627 ) |
F_146 ( V_631 ) ;
break;
case V_128 :
V_120 -> V_620 = F_146 ( V_632 ) |
F_146 ( V_630 ) |
F_146 ( V_627 ) ;
default:
return - V_16 ;
}
for ( V_489 = 1 ; V_489 <= V_616 ; V_489 ++ ) {
if ( V_56 [ V_489 ] ) {
V_120 -> V_622 |= ( 1 << V_489 ) ;
if ( V_489 > V_633 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_154 ( struct V_44 * V_58 , struct V_634 * V_31 ,
int V_50 )
{
struct V_4 * V_173 ;
V_23 V_259 ;
T_3 V_635 ;
V_173 = F_50 ( V_58 , V_50 ) ;
if ( ! V_173 )
return false ;
V_259 = F_155 ( V_31 ) ;
V_635 = V_259 < ( 1UL << 16 ) ? V_259 : 0 ;
if ( V_259 > 0 &&
F_34 ( V_58 , V_636 , V_259 ) )
return false ;
if ( V_635 > 0 &&
F_57 ( V_58 , V_637 , V_635 ) )
return false ;
if ( V_31 -> V_56 & V_638 ) {
if ( F_56 ( V_58 , V_639 , V_31 -> V_240 ) )
return false ;
if ( V_31 -> V_56 & V_640 &&
F_35 ( V_58 , V_641 ) )
return false ;
if ( V_31 -> V_56 & V_642 &&
F_35 ( V_58 , V_643 ) )
return false ;
} else if ( V_31 -> V_56 & V_644 ) {
if ( F_56 ( V_58 , V_645 , V_31 -> V_240 ) )
return false ;
if ( F_56 ( V_58 , V_646 , V_31 -> V_647 ) )
return false ;
if ( V_31 -> V_56 & V_640 &&
F_35 ( V_58 , V_641 ) )
return false ;
if ( V_31 -> V_56 & V_648 &&
F_35 ( V_58 , V_649 ) )
return false ;
if ( V_31 -> V_56 & V_650 &&
F_35 ( V_58 , V_651 ) )
return false ;
if ( V_31 -> V_56 & V_652 &&
F_35 ( V_58 , V_653 ) )
return false ;
if ( V_31 -> V_56 & V_642 &&
F_35 ( V_58 , V_643 ) )
return false ;
}
F_51 ( V_58 , V_173 ) ;
return true ;
}
static int F_156 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 ,
struct V_6 * V_7 ,
struct V_26 * V_46 ,
const T_2 * V_525 , struct V_654 * V_655 )
{
void * V_162 ;
struct V_4 * V_656 , * V_657 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_658 ) ;
if ( ! V_162 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_525 ) ||
F_34 ( V_58 , V_178 , V_655 -> V_659 ) )
goto V_63;
V_656 = F_50 ( V_58 , V_660 ) ;
if ( ! V_656 )
goto V_63;
if ( ( V_655 -> V_661 & V_662 ) &&
F_34 ( V_58 , V_663 ,
V_655 -> V_664 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_665 ) &&
F_34 ( V_58 , V_666 ,
V_655 -> V_667 ) )
goto V_63;
if ( ( V_655 -> V_661 & ( V_668 |
V_669 ) ) &&
F_34 ( V_58 , V_670 ,
( V_23 ) V_655 -> V_671 ) )
goto V_63;
if ( ( V_655 -> V_661 & ( V_672 |
V_673 ) ) &&
F_34 ( V_58 , V_674 ,
( V_23 ) V_655 -> V_675 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_669 ) &&
F_100 ( V_58 , V_676 ,
V_655 -> V_671 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_677 ) &&
F_100 ( V_58 , V_673 ,
V_655 -> V_675 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_678 ) &&
F_57 ( V_58 , V_679 , V_655 -> V_680 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_681 ) &&
F_57 ( V_58 , V_682 , V_655 -> V_683 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_684 ) &&
F_56 ( V_58 , V_685 ,
V_655 -> V_686 ) )
goto V_63;
switch ( V_7 -> V_18 . V_687 ) {
case V_688 :
if ( ( V_655 -> V_661 & V_689 ) &&
F_56 ( V_58 , V_690 ,
V_655 -> signal ) )
goto V_63;
if ( ( V_655 -> V_661 & V_691 ) &&
F_56 ( V_58 , V_692 ,
V_655 -> V_693 ) )
goto V_63;
break;
default:
break;
}
if ( V_655 -> V_661 & V_694 ) {
if ( ! F_154 ( V_58 , & V_655 -> V_695 ,
V_696 ) )
goto V_63;
}
if ( V_655 -> V_661 & V_697 ) {
if ( ! F_154 ( V_58 , & V_655 -> V_698 ,
V_699 ) )
goto V_63;
}
if ( ( V_655 -> V_661 & V_700 ) &&
F_34 ( V_58 , V_701 ,
V_655 -> V_702 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_703 ) &&
F_34 ( V_58 , V_704 ,
V_655 -> V_705 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_706 ) &&
F_34 ( V_58 , V_707 ,
V_655 -> V_708 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_709 ) &&
F_34 ( V_58 , V_710 ,
V_655 -> V_711 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_712 ) &&
F_34 ( V_58 , V_713 ,
V_655 -> V_714 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_715 ) &&
F_34 ( V_58 , V_716 ,
V_655 -> V_717 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_718 ) &&
F_34 ( V_58 , V_719 ,
V_655 -> V_720 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_721 ) &&
F_34 ( V_58 , V_722 ,
V_655 -> V_723 ) )
goto V_63;
if ( V_655 -> V_661 & V_724 ) {
V_657 = F_50 ( V_58 , V_725 ) ;
if ( ! V_657 )
goto V_63;
if ( ( ( V_655 -> V_657 . V_56 & V_726 ) &&
F_35 ( V_58 , V_727 ) ) ||
( ( V_655 -> V_657 . V_56 & V_728 ) &&
F_35 ( V_58 , V_729 ) ) ||
( ( V_655 -> V_657 . V_56 & V_730 ) &&
F_35 ( V_58 , V_731 ) ) ||
F_56 ( V_58 , V_732 ,
V_655 -> V_657 . V_590 ) ||
F_57 ( V_58 , V_733 ,
V_655 -> V_657 . V_433 ) )
goto V_63;
F_51 ( V_58 , V_657 ) ;
}
if ( ( V_655 -> V_661 & V_734 ) &&
F_58 ( V_58 , V_735 ,
sizeof( struct V_618 ) ,
& V_655 -> V_619 ) )
goto V_63;
if ( ( V_655 -> V_661 & V_736 ) &&
F_100 ( V_58 , V_737 ,
V_655 -> V_738 ) )
goto V_63;
F_51 ( V_58 , V_656 ) ;
if ( ( V_655 -> V_661 & V_739 ) &&
F_58 ( V_58 , V_559 , V_655 -> V_740 ,
V_655 -> V_741 ) )
goto V_63;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_391 ;
}
static int F_157 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_654 V_655 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_525 [ V_474 ] ;
int V_742 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_226 -> V_743 ) {
V_47 = - V_432 ;
goto V_744;
}
while ( 1 ) {
memset ( & V_655 , 0 , sizeof( V_655 ) ) ;
V_47 = F_158 ( V_46 , V_20 , V_742 ,
V_525 , & V_655 ) ;
if ( V_47 == - V_532 )
break;
if ( V_47 )
goto V_744;
if ( F_156 ( V_45 ,
F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_394 , V_395 ,
V_46 , V_20 , V_525 ,
& V_655 ) < 0 )
goto V_484;
V_742 ++ ;
}
V_484:
V_35 -> args [ 1 ] = V_742 ;
V_47 = V_45 -> V_52 ;
V_744:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_159 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_654 V_655 ;
struct V_44 * V_58 ;
T_2 * V_525 = NULL ;
int V_47 ;
memset ( & V_655 , 0 , sizeof( V_655 ) ) ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
V_525 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( ! V_7 -> V_226 -> V_745 )
return - V_432 ;
V_47 = F_160 ( V_7 , V_46 , V_525 , & V_655 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_156 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_7 , V_46 , V_525 , & V_655 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static struct V_26 * F_161 ( struct V_30 * V_31 ,
struct V_6 * V_7 )
{
struct V_4 * V_746 = V_31 -> V_5 [ V_747 ] ;
struct V_26 * V_748 ;
int V_392 ;
if ( ! V_746 )
return NULL ;
V_748 = F_12 ( F_89 ( V_31 ) , F_4 ( V_746 ) ) ;
if ( ! V_748 )
return F_3 ( - V_24 ) ;
if ( ! V_748 -> V_29 || V_748 -> V_29 -> V_18 != & V_7 -> V_18 ) {
V_392 = - V_16 ;
goto error;
}
if ( ! F_86 ( V_748 ) ) {
V_392 = - V_446 ;
goto error;
}
return V_748 ;
error:
F_14 ( V_748 ) ;
return F_3 ( V_392 ) ;
}
static int F_162 ( struct V_30 * V_31 ,
struct V_615 * V_120 )
{
struct V_4 * V_78 [ V_749 + 1 ] ;
struct V_4 * V_486 ;
int V_47 ;
if ( V_31 -> V_5 [ V_750 ] )
V_120 -> V_751 =
F_29 ( V_31 -> V_5 [ V_750 ] ) ;
if ( V_31 -> V_5 [ V_752 ] )
V_120 -> V_753 =
F_29 ( V_31 -> V_5 [ V_752 ] ) ;
if ( ! V_31 -> V_5 [ V_754 ] )
return 0 ;
V_486 = V_31 -> V_5 [ V_754 ] ;
V_47 = F_38 ( V_78 , V_749 , V_486 ,
V_755 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_756 ] )
V_120 -> V_757 = F_39 (
V_78 [ V_756 ] ) ;
if ( V_120 -> V_757 & ~ V_758 )
return - V_16 ;
if ( V_78 [ V_759 ] )
V_120 -> V_760 = F_39 ( V_78 [ V_759 ] ) ;
if ( V_120 -> V_760 & ~ V_761 )
return - V_16 ;
V_120 -> V_762 |= V_763 ;
return 0 ;
}
static int F_163 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_615 V_120 ;
T_2 * V_525 = NULL ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_764 = - 1 ;
V_120 . V_686 = - 1 ;
if ( V_31 -> V_5 [ V_765 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
V_525 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( V_31 -> V_5 [ V_766 ] ) {
V_120 . V_767 =
F_29 ( V_31 -> V_5 [ V_766 ] ) ;
V_120 . V_768 =
F_30 ( V_31 -> V_5 [ V_766 ] ) ;
}
if ( V_31 -> V_5 [ V_769 ] ) {
V_120 . V_770 =
F_73 ( V_31 -> V_5 [ V_769 ] ) ;
V_120 . V_762 |= V_771 ;
}
if ( V_31 -> V_5 [ V_772 ] ) {
V_120 . V_773 =
F_29 ( V_31 -> V_5 [ V_772 ] ) ;
V_120 . V_774 =
F_30 ( V_31 -> V_5 [ V_772 ] ) ;
}
if ( V_31 -> V_5 [ V_775 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_776 )
return - V_432 ;
if ( F_153 ( V_31 , V_46 -> V_29 -> V_124 , & V_120 ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_777 ] )
V_120 . V_778 =
F_39 ( V_31 -> V_5 [ V_777 ] ) ;
if ( V_31 -> V_5 [ V_779 ] )
V_120 . V_686 =
F_39 ( V_31 -> V_5 [ V_779 ] ) ;
if ( V_31 -> V_5 [ V_780 ] ) {
enum V_781 V_782 = F_4 (
V_31 -> V_5 [ V_780 ] ) ;
if ( V_782 <= V_783 ||
V_782 > V_784 )
return - V_16 ;
V_120 . V_717 = V_782 ;
}
switch ( V_46 -> V_29 -> V_124 ) {
case V_125 :
case V_126 :
case V_127 :
if ( V_120 . V_778 )
return - V_16 ;
if ( V_120 . V_717 )
return - V_16 ;
if ( V_120 . V_622 & F_146 ( V_631 ) )
return - V_16 ;
V_120 . V_620 &= ~ F_146 ( V_631 ) ;
if ( V_120 . V_620 &
~ ( F_146 ( V_627 ) |
F_146 ( V_632 ) |
F_146 ( V_785 ) |
F_146 ( V_628 ) |
F_146 ( V_629 ) |
F_146 ( V_630 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_386 &
V_786 ) &&
V_120 . V_620 &
( F_146 ( V_632 ) |
F_146 ( V_785 ) ) )
return - V_16 ;
if ( V_120 . V_767 )
return - V_16 ;
if ( V_31 -> V_5 [ V_769 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_772 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_750 ] ||
V_31 -> V_5 [ V_752 ] )
return - V_16 ;
V_120 . V_787 = F_161 ( V_31 , V_7 ) ;
if ( F_16 ( V_120 . V_787 ) )
return F_24 ( V_120 . V_787 ) ;
break;
case V_133 :
case V_132 :
V_120 . V_620 &= ~ F_146 ( V_631 ) ;
V_47 = F_162 ( V_31 , & V_120 ) ;
if ( V_47 )
return V_47 ;
if ( V_120 . V_778 )
return - V_16 ;
if ( V_120 . V_717 )
return - V_16 ;
if ( V_120 . V_620 & ~ ( F_146 ( V_627 ) |
F_146 ( V_629 ) ) )
return - V_16 ;
break;
case V_129 :
if ( V_120 . V_778 )
return - V_16 ;
if ( V_120 . V_717 )
return - V_16 ;
if ( V_31 -> V_5 [ V_750 ] ||
V_31 -> V_5 [ V_752 ] )
return - V_16 ;
if ( V_120 . V_620 & ~ F_146 ( V_627 ) )
return - V_16 ;
break;
case V_128 :
if ( V_120 . V_787 )
return - V_16 ;
if ( V_120 . V_767 )
return - V_16 ;
if ( V_31 -> V_5 [ V_769 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_772 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_750 ] ||
V_31 -> V_5 [ V_752 ] )
return - V_16 ;
if ( V_120 . V_620 &
~ ( F_146 ( V_632 ) |
F_146 ( V_630 ) |
F_146 ( V_627 ) ) )
return - V_16 ;
break;
default:
return - V_432 ;
}
V_47 = F_164 ( V_7 , V_46 , V_525 , & V_120 ) ;
if ( V_120 . V_787 )
F_14 ( V_120 . V_787 ) ;
return V_47 ;
}
static int F_165 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_615 V_120 ;
T_2 * V_525 = NULL ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_775 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_766 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_765 ] )
return - V_16 ;
V_525 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_120 . V_767 =
F_29 ( V_31 -> V_5 [ V_766 ] ) ;
V_120 . V_768 =
F_30 ( V_31 -> V_5 [ V_766 ] ) ;
V_120 . V_764 =
F_73 ( V_31 -> V_5 [ V_775 ] ) ;
V_120 . V_788 = F_73 ( V_31 -> V_5 [ V_765 ] ) ;
if ( ! V_120 . V_788 || V_120 . V_788 > V_789 )
return - V_16 ;
if ( V_31 -> V_5 [ V_769 ] ) {
V_120 . V_770 =
F_73 ( V_31 -> V_5 [ V_769 ] ) ;
V_120 . V_762 |= V_771 ;
}
if ( V_31 -> V_5 [ V_772 ] ) {
V_120 . V_773 =
F_29 ( V_31 -> V_5 [ V_772 ] ) ;
V_120 . V_774 =
F_30 ( V_31 -> V_5 [ V_772 ] ) ;
}
if ( V_31 -> V_5 [ V_750 ] )
V_120 . V_751 =
F_29 ( V_31 -> V_5 [ V_750 ] ) ;
if ( V_31 -> V_5 [ V_752 ] )
V_120 . V_753 =
F_29 ( V_31 -> V_5 [ V_752 ] ) ;
if ( V_31 -> V_5 [ V_777 ] )
V_120 . V_778 =
F_39 ( V_31 -> V_5 [ V_777 ] ) ;
if ( ! V_7 -> V_226 -> V_271 )
return - V_432 ;
if ( F_153 ( V_31 , V_46 -> V_29 -> V_124 , & V_120 ) )
return - V_16 ;
switch ( V_46 -> V_29 -> V_124 ) {
case V_125 :
case V_126 :
case V_127 :
if ( ( V_7 -> V_18 . V_56 & V_204 ) &&
( V_120 . V_622 & F_146 ( V_629 ) ) &&
V_31 -> V_5 [ V_754 ] ) {
struct V_4 * V_78 [ V_749 + 1 ] ;
struct V_4 * V_486 ;
V_486 = V_31 -> V_5 [ V_754 ] ;
V_47 = F_38 ( V_78 , V_749 , V_486 ,
V_755 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_756 ] )
V_120 . V_757 =
F_39 ( V_78 [ V_756 ] ) ;
if ( V_120 . V_757 &
~ V_758 )
return - V_16 ;
if ( V_78 [ V_759 ] )
V_120 . V_760 =
F_39 ( V_78 [ V_759 ] ) ;
if ( V_120 . V_760 &
~ V_761 )
return - V_16 ;
V_120 . V_762 |= V_763 ;
}
if ( V_120 . V_622 & F_146 ( V_631 ) )
return - V_16 ;
V_120 . V_620 &= ~ F_146 ( V_631 ) ;
if ( ! ( V_7 -> V_18 . V_386 &
V_786 ) &&
V_120 . V_620 &
( F_146 ( V_632 ) |
F_146 ( V_785 ) ) )
return - V_16 ;
V_120 . V_787 = F_161 ( V_31 , V_7 ) ;
if ( F_16 ( V_120 . V_787 ) )
return F_24 ( V_120 . V_787 ) ;
break;
case V_128 :
if ( V_120 . V_620 & F_146 ( V_785 ) )
return - V_16 ;
if ( V_120 . V_622 & F_146 ( V_631 ) )
return - V_16 ;
break;
case V_132 :
if ( V_120 . V_620 & F_146 ( V_785 ) )
return - V_16 ;
if ( ! ( V_120 . V_622 & F_146 ( V_631 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_56 & V_208 ) )
return - V_432 ;
if ( ! ( V_7 -> V_18 . V_56 & V_210 ) )
return - V_432 ;
break;
default:
return - V_432 ;
}
V_47 = F_166 ( V_7 , V_46 , V_525 , & V_120 ) ;
if ( V_120 . V_787 )
F_14 ( V_120 . V_787 ) ;
return V_47 ;
}
static int F_167 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 * V_525 = NULL ;
if ( V_31 -> V_5 [ V_437 ] )
V_525 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_126 &&
V_46 -> V_29 -> V_124 != V_128 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_790 )
return - V_432 ;
return F_168 ( V_7 , V_46 , V_525 ) ;
}
static int F_169 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
T_2 * V_791 , T_2 * V_792 ,
struct V_793 * V_794 )
{
void * V_162 ;
struct V_4 * V_795 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_658 ) ;
if ( ! V_162 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_791 ) ||
F_58 ( V_58 , V_796 , V_474 , V_792 ) ||
F_34 ( V_58 , V_178 , V_794 -> V_659 ) )
goto V_63;
V_795 = F_50 ( V_58 , V_797 ) ;
if ( ! V_795 )
goto V_63;
if ( ( V_794 -> V_661 & V_798 ) &&
F_34 ( V_58 , V_799 ,
V_794 -> V_800 ) )
goto V_63;
if ( ( ( V_794 -> V_661 & V_801 ) &&
F_34 ( V_58 , V_802 , V_794 -> V_803 ) ) ||
( ( V_794 -> V_661 & V_804 ) &&
F_34 ( V_58 , V_805 ,
V_794 -> V_806 ) ) ||
( ( V_794 -> V_661 & V_807 ) &&
F_34 ( V_58 , V_808 ,
V_794 -> V_809 ) ) ||
( ( V_794 -> V_661 & V_810 ) &&
F_56 ( V_58 , V_811 ,
V_794 -> V_56 ) ) ||
( ( V_794 -> V_661 & V_812 ) &&
F_34 ( V_58 , V_813 ,
V_794 -> V_814 ) ) ||
( ( V_794 -> V_661 & V_815 ) &&
F_56 ( V_58 , V_816 ,
V_794 -> V_817 ) ) )
goto V_63;
F_51 ( V_58 , V_795 ) ;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_391 ;
}
static int F_170 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_793 V_794 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_791 [ V_474 ] ;
T_2 V_792 [ V_474 ] ;
int V_818 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_226 -> V_819 ) {
V_47 = - V_432 ;
goto V_744;
}
if ( V_20 -> V_29 -> V_124 != V_128 ) {
V_47 = - V_432 ;
goto V_744;
}
while ( 1 ) {
V_47 = F_171 ( V_46 , V_20 , V_818 , V_791 , V_792 ,
& V_794 ) ;
if ( V_47 == - V_532 )
break;
if ( V_47 )
goto V_744;
if ( F_169 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_394 , V_395 ,
V_20 , V_791 , V_792 ,
& V_794 ) < 0 )
goto V_484;
V_818 ++ ;
}
V_484:
V_35 -> args [ 1 ] = V_818 ;
V_47 = V_45 -> V_52 ;
V_744:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_172 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_793 V_794 ;
struct V_44 * V_58 ;
T_2 * V_791 = NULL ;
T_2 V_792 [ V_474 ] ;
memset ( & V_794 , 0 , sizeof( V_794 ) ) ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
V_791 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( ! V_7 -> V_226 -> V_820 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_128 )
return - V_432 ;
V_47 = F_173 ( V_7 , V_46 , V_791 , V_792 , & V_794 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
if ( F_169 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_46 , V_791 , V_792 , & V_794 ) < 0 ) {
F_70 ( V_58 ) ;
return - V_74 ;
}
return F_71 ( V_58 , V_31 ) ;
}
static int F_174 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 * V_791 = NULL ;
T_2 * V_792 = NULL ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_796 ] )
return - V_16 ;
V_791 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_792 = F_29 ( V_31 -> V_5 [ V_796 ] ) ;
if ( ! V_7 -> V_226 -> V_821 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_128 )
return - V_432 ;
return F_175 ( V_7 , V_46 , V_791 , V_792 ) ;
}
static int F_176 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 * V_791 = NULL ;
T_2 * V_792 = NULL ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_796 ] )
return - V_16 ;
V_791 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_792 = F_29 ( V_31 -> V_5 [ V_796 ] ) ;
if ( ! V_7 -> V_226 -> V_273 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_128 )
return - V_432 ;
return F_177 ( V_7 , V_46 , V_791 , V_792 ) ;
}
static int F_178 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 * V_791 = NULL ;
if ( V_31 -> V_5 [ V_437 ] )
V_791 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( ! V_7 -> V_226 -> V_822 )
return - V_432 ;
return F_179 ( V_7 , V_46 , V_791 ) ;
}
static int F_180 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_823 V_120 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_120 . V_824 = - 1 ;
V_120 . V_825 = - 1 ;
V_120 . V_826 = - 1 ;
V_120 . V_827 = - 1 ;
V_120 . V_828 = - 1 ;
V_120 . V_606 = - 1 ;
V_120 . V_609 = - 1 ;
if ( V_31 -> V_5 [ V_829 ] )
V_120 . V_824 =
F_39 ( V_31 -> V_5 [ V_829 ] ) ;
if ( V_31 -> V_5 [ V_830 ] )
V_120 . V_825 =
F_39 ( V_31 -> V_5 [ V_830 ] ) ;
if ( V_31 -> V_5 [ V_831 ] )
V_120 . V_826 =
F_39 ( V_31 -> V_5 [ V_831 ] ) ;
if ( V_31 -> V_5 [ V_832 ] ) {
V_120 . V_833 =
F_29 ( V_31 -> V_5 [ V_832 ] ) ;
V_120 . V_834 =
F_30 ( V_31 -> V_5 [ V_832 ] ) ;
}
if ( V_31 -> V_5 [ V_835 ] )
V_120 . V_827 = ! ! F_39 ( V_31 -> V_5 [ V_835 ] ) ;
if ( V_31 -> V_5 [ V_836 ] )
V_120 . V_828 =
F_73 ( V_31 -> V_5 [ V_836 ] ) ;
if ( V_31 -> V_5 [ V_605 ] ) {
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_120 . V_606 =
F_181 ( V_31 -> V_5 [ V_605 ] ) ;
if ( V_120 . V_606 < 0 )
return - V_16 ;
if ( V_120 . V_606 != 0 &&
! ( V_7 -> V_18 . V_386 & V_607 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_608 ] ) {
T_2 V_25 ;
if ( V_46 -> V_29 -> V_124 != V_127 )
return - V_16 ;
V_25 = F_39 ( V_31 -> V_5 [ V_608 ] ) ;
if ( V_25 > 1 )
return - V_16 ;
V_120 . V_609 = V_25 ;
if ( V_120 . V_609 &&
! ( V_7 -> V_18 . V_386 & V_610 ) )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_277 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_125 &&
V_46 -> V_29 -> V_124 != V_127 )
return - V_432 ;
return F_182 ( V_7 , V_46 , & V_120 ) ;
}
static int F_183 ( struct V_4 * V_78 [] ,
struct V_837 * V_838 )
{
struct V_839 * V_840 = & V_838 -> V_840 ;
struct V_841 * V_842 = & V_838 -> V_842 ;
if ( ! V_78 [ V_843 ] )
return - V_16 ;
if ( ! V_78 [ V_844 ] )
return - V_16 ;
if ( ! V_78 [ V_845 ] )
return - V_16 ;
if ( ! V_78 [ V_846 ] )
return - V_16 ;
if ( ! V_78 [ V_847 ] )
return - V_16 ;
V_838 -> V_56 = F_4 ( V_78 [ V_843 ] ) ;
V_840 -> V_848 =
F_4 ( V_78 [ V_844 ] ) ;
V_840 -> V_849 =
F_4 ( V_78 [ V_845 ] ) ;
V_840 -> V_850 =
F_4 ( V_78 [ V_846 ] ) ;
V_842 -> V_851 =
F_4 ( V_78 [ V_847 ] ) ;
if ( V_78 [ V_852 ] )
V_842 -> V_853 =
F_4 ( V_78 [ V_852 ] ) ;
return 0 ;
}
static int F_184 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
int V_854 ;
char * V_121 = NULL ;
enum V_855 V_856 ;
if ( F_185 ( ! F_186 ( V_857 ) ) )
return - V_858 ;
if ( ! V_31 -> V_5 [ V_859 ] )
return - V_16 ;
V_121 = F_29 ( V_31 -> V_5 [ V_859 ] ) ;
if ( V_31 -> V_5 [ V_860 ] )
V_856 =
F_4 ( V_31 -> V_5 [ V_860 ] ) ;
else
V_856 = V_861 ;
switch ( V_856 ) {
case V_861 :
case V_862 :
break;
default:
return - V_16 ;
}
V_854 = F_187 ( V_121 , V_856 ) ;
return V_854 ;
}
static int F_188 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_863 V_864 ;
int V_47 = 0 ;
void * V_162 ;
struct V_4 * V_795 ;
struct V_44 * V_58 ;
if ( V_17 -> V_124 != V_128 )
return - V_432 ;
if ( ! V_7 -> V_226 -> V_865 )
return - V_432 ;
F_108 ( V_17 ) ;
if ( ! V_17 -> V_866 )
memcpy ( & V_864 , & V_867 , sizeof( V_864 ) ) ;
else
V_47 = F_189 ( V_7 , V_46 , & V_864 ) ;
F_110 ( V_17 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_868 ) ;
if ( ! V_162 )
goto V_484;
V_795 = F_50 ( V_58 , V_869 ) ;
if ( ! V_795 )
goto V_63;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_57 ( V_58 , V_870 ,
V_864 . V_871 ) ||
F_57 ( V_58 , V_872 ,
V_864 . V_873 ) ||
F_57 ( V_58 , V_874 ,
V_864 . V_875 ) ||
F_57 ( V_58 , V_876 ,
V_864 . V_877 ) ||
F_56 ( V_58 , V_878 ,
V_864 . V_879 ) ||
F_56 ( V_58 , V_880 ,
V_864 . V_881 ) ||
F_56 ( V_58 , V_882 ,
V_864 . V_883 ) ||
F_56 ( V_58 , V_884 ,
V_864 . V_885 ) ||
F_34 ( V_58 , V_886 ,
V_864 . V_887 ) ||
F_56 ( V_58 , V_888 ,
V_864 . V_889 ) ||
F_34 ( V_58 , V_890 ,
V_864 . V_891 ) ||
F_57 ( V_58 , V_892 ,
V_864 . V_893 ) ||
F_34 ( V_58 , V_894 ,
V_864 . V_895 ) ||
F_57 ( V_58 , V_896 ,
V_864 . V_897 ) ||
F_57 ( V_58 , V_898 ,
V_864 . V_899 ) ||
F_57 ( V_58 , V_900 ,
V_864 . V_901 ) ||
F_56 ( V_58 , V_902 ,
V_864 . V_903 ) ||
F_57 ( V_58 , V_904 ,
V_864 . V_905 ) ||
F_56 ( V_58 , V_906 ,
V_864 . V_907 ) ||
F_56 ( V_58 , V_908 ,
V_864 . V_909 ) ||
F_34 ( V_58 , V_910 ,
V_864 . V_911 ) ||
F_34 ( V_58 , V_912 ,
V_864 . V_828 ) ||
F_34 ( V_58 , V_913 ,
V_864 . V_914 ) ||
F_57 ( V_58 , V_915 ,
V_864 . V_916 ) ||
F_57 ( V_58 , V_917 ,
V_864 . V_918 ) ||
F_34 ( V_58 , V_919 ,
V_864 . V_920 ) ||
F_57 ( V_58 , V_921 ,
V_864 . V_922 ) )
goto V_63;
F_51 ( V_58 , V_795 ) ;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
V_484:
F_70 ( V_58 ) ;
return - V_74 ;
}
static int F_190 ( struct V_30 * V_31 ,
struct V_863 * V_923 ,
V_23 * V_924 )
{
struct V_4 * V_78 [ V_925 + 1 ] ;
V_23 V_621 = 0 ;
#define F_191 ( V_78 , V_923 , T_6 , T_7 , V_153 , V_621 , V_50 , T_8 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_31 -> V_5 [ V_869 ] )
return - V_16 ;
if ( F_38 ( V_78 , V_925 ,
V_31 -> V_5 [ V_869 ] ,
V_926 ) )
return - V_16 ;
F_109 ( V_925 > 32 ) ;
F_191 ( V_78 , V_923 , V_871 , 1 , 255 ,
V_621 , V_870 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_873 , 1 , 255 ,
V_621 , V_872 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_875 , 1 , 255 ,
V_621 , V_874 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_877 , 0 , 255 ,
V_621 , V_876 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_879 , 0 , 16 ,
V_621 , V_878 ,
F_39 ) ;
F_191 ( V_78 , V_923 , V_881 , 1 , 255 ,
V_621 , V_880 , F_39 ) ;
F_191 ( V_78 , V_923 , V_883 , 1 , 255 ,
V_621 , V_882 ,
F_39 ) ;
F_191 ( V_78 , V_923 , V_885 , 0 , 1 ,
V_621 , V_884 ,
F_39 ) ;
F_191 ( V_78 , V_923 , V_887 ,
1 , 255 , V_621 ,
V_886 ,
F_4 ) ;
F_191 ( V_78 , V_923 , V_889 , 0 , 255 ,
V_621 , V_888 ,
F_39 ) ;
F_191 ( V_78 , V_923 , V_891 , 1 , 65535 ,
V_621 , V_890 ,
F_4 ) ;
F_191 ( V_78 , V_923 , V_893 , 1 , 65535 ,
V_621 , V_892 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_895 ,
1 , 65535 , V_621 ,
V_894 ,
F_4 ) ;
F_191 ( V_78 , V_923 , V_897 ,
1 , 65535 , V_621 ,
V_896 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_899 ,
1 , 65535 , V_621 ,
V_898 ,
F_73 ) ;
F_191 ( V_78 , V_923 ,
V_901 ,
1 , 65535 , V_621 ,
V_900 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_903 , 0 , 4 ,
V_621 , V_902 ,
F_39 ) ;
F_191 ( V_78 , V_923 , V_905 , 1 , 65535 ,
V_621 , V_904 ,
F_73 ) ;
F_191 ( V_78 , V_923 ,
V_907 , 0 , 1 ,
V_621 , V_906 ,
F_39 ) ;
F_191 ( V_78 , V_923 , V_909 , 0 , 1 ,
V_621 , V_908 ,
F_39 ) ;
F_191 ( V_78 , V_923 , V_911 , 1 , 255 ,
V_621 , V_910 ,
F_4 ) ;
F_191 ( V_78 , V_923 , V_828 , 0 , 16 ,
V_621 , V_912 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_914 ,
1 , 65535 , V_621 ,
V_913 ,
F_4 ) ;
F_191 ( V_78 , V_923 , V_916 , 1 , 65535 ,
V_621 , V_915 ,
F_73 ) ;
F_191 ( V_78 , V_923 ,
V_918 ,
1 , 65535 , V_621 ,
V_917 ,
F_73 ) ;
F_191 ( V_78 , V_923 , V_920 ,
V_927 ,
V_784 ,
V_621 , V_919 ,
F_4 ) ;
F_191 ( V_78 , V_923 , V_922 ,
0 , 65535 , V_621 ,
V_921 , F_73 ) ;
if ( V_924 )
* V_924 = V_621 ;
return 0 ;
#undef F_191
}
static int F_192 ( struct V_30 * V_31 ,
struct V_928 * V_929 )
{
struct V_4 * V_78 [ V_930 + 1 ] ;
if ( ! V_31 -> V_5 [ V_931 ] )
return - V_16 ;
if ( F_38 ( V_78 , V_930 ,
V_31 -> V_5 [ V_931 ] ,
V_932 ) )
return - V_16 ;
if ( V_78 [ V_933 ] )
V_929 -> V_934 =
( F_39 ( V_78 [ V_933 ] ) ) ?
V_935 :
V_936 ;
if ( V_78 [ V_937 ] )
V_929 -> V_938 =
( F_39 ( V_78 [ V_937 ] ) ) ?
V_939 :
V_940 ;
if ( V_78 [ V_941 ] )
V_929 -> V_942 =
( F_39 ( V_78 [ V_941 ] ) ) ?
V_943 :
V_944 ;
if ( V_78 [ V_945 ] ) {
struct V_4 * V_946 =
V_78 [ V_945 ] ;
if ( ! F_28 ( V_946 ) )
return - V_16 ;
V_929 -> V_947 = F_29 ( V_946 ) ;
V_929 -> V_948 = F_30 ( V_946 ) ;
}
V_929 -> V_949 = F_193 ( V_78 [ V_950 ] ) ;
V_929 -> V_951 = F_193 ( V_78 [ V_952 ] ) ;
return 0 ;
}
static int F_194 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_863 V_923 ;
V_23 V_621 ;
int V_47 ;
if ( V_17 -> V_124 != V_128 )
return - V_432 ;
if ( ! V_7 -> V_226 -> V_275 )
return - V_432 ;
V_47 = F_190 ( V_31 , & V_923 , & V_621 ) ;
if ( V_47 )
return V_47 ;
F_108 ( V_17 ) ;
if ( ! V_17 -> V_866 )
V_47 = - V_131 ;
if ( ! V_47 )
V_47 = F_195 ( V_7 , V_46 , V_621 , & V_923 ) ;
F_110 ( V_17 ) ;
return V_47 ;
}
static int F_196 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
const struct V_953 * V_954 ;
struct V_44 * V_58 ;
void * V_162 = NULL ;
struct V_4 * V_955 ;
unsigned int V_138 ;
int V_47 = - V_16 ;
F_8 ( & V_32 ) ;
if ( ! V_857 )
goto V_484;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 ) {
V_47 = - V_74 ;
goto V_484;
}
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_956 ) ;
if ( ! V_162 )
goto V_957;
if ( F_197 () &&
F_34 ( V_58 , V_860 ,
V_862 ) )
goto V_63;
F_198 () ;
V_954 = F_199 ( V_857 ) ;
if ( F_54 ( V_58 , V_859 , V_954 -> V_958 ) ||
( V_954 -> V_959 &&
F_56 ( V_58 , V_960 , V_954 -> V_959 ) ) )
goto V_961;
V_955 = F_50 ( V_58 , V_962 ) ;
if ( ! V_955 )
goto V_961;
for ( V_138 = 0 ; V_138 < V_954 -> V_963 ; V_138 ++ ) {
struct V_4 * V_964 ;
const struct V_837 * V_838 ;
const struct V_839 * V_840 ;
const struct V_841 * V_842 ;
V_838 = & V_954 -> V_965 [ V_138 ] ;
V_840 = & V_838 -> V_840 ;
V_842 = & V_838 -> V_842 ;
V_964 = F_50 ( V_58 , V_138 ) ;
if ( ! V_964 )
goto V_961;
if ( F_34 ( V_58 , V_843 ,
V_838 -> V_56 ) ||
F_34 ( V_58 , V_844 ,
V_840 -> V_848 ) ||
F_34 ( V_58 , V_845 ,
V_840 -> V_849 ) ||
F_34 ( V_58 , V_846 ,
V_840 -> V_850 ) ||
F_34 ( V_58 , V_852 ,
V_842 -> V_853 ) ||
F_34 ( V_58 , V_847 ,
V_842 -> V_851 ) )
goto V_961;
F_51 ( V_58 , V_964 ) ;
}
F_200 () ;
F_51 ( V_58 , V_955 ) ;
F_63 ( V_58 , V_162 ) ;
V_47 = F_71 ( V_58 , V_31 ) ;
goto V_484;
V_961:
F_200 () ;
V_63:
F_64 ( V_58 , V_162 ) ;
V_957:
F_70 ( V_58 ) ;
V_47 = - V_391 ;
V_484:
F_9 ( & V_32 ) ;
return V_47 ;
}
static int F_201 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_966 + 1 ] ;
struct V_4 * V_964 ;
char * V_958 = NULL ;
int V_967 = 0 , V_854 = 0 ;
V_23 V_968 = 0 , V_969 = 0 , V_970 ;
T_2 V_959 = 0 ;
struct V_953 * V_971 = NULL ;
if ( ! V_31 -> V_5 [ V_859 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_962 ] )
return - V_16 ;
V_958 = F_29 ( V_31 -> V_5 [ V_859 ] ) ;
if ( V_31 -> V_5 [ V_960 ] )
V_959 = F_39 ( V_31 -> V_5 [ V_960 ] ) ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_968 ++ ;
if ( V_968 > V_972 )
return - V_16 ;
}
V_970 = sizeof( struct V_953 ) +
V_968 * sizeof( struct V_837 ) ;
V_971 = F_43 ( V_970 , V_118 ) ;
if ( ! V_971 )
return - V_119 ;
V_971 -> V_963 = V_968 ;
V_971 -> V_958 [ 0 ] = V_958 [ 0 ] ;
V_971 -> V_958 [ 1 ] = V_958 [ 1 ] ;
if ( F_202 ( V_959 ) )
V_971 -> V_959 = V_959 ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_91 ( V_78 , V_966 ,
F_29 ( V_964 ) , F_30 ( V_964 ) ,
V_973 ) ;
V_854 = F_183 ( V_78 , & V_971 -> V_965 [ V_969 ] ) ;
if ( V_854 )
goto V_974;
V_969 ++ ;
if ( V_969 > V_972 ) {
V_854 = - V_16 ;
goto V_974;
}
}
F_8 ( & V_32 ) ;
V_854 = F_203 ( V_971 ) ;
V_971 = NULL ;
F_9 ( & V_32 ) ;
V_974:
F_46 ( V_971 ) ;
return V_854 ;
}
static int F_204 ( struct V_4 * V_975 )
{
struct V_4 * V_976 , * V_977 ;
int V_253 = 0 , V_978 , V_979 ;
F_44 (attr1, freqs, tmp1) {
V_253 ++ ;
F_44 (attr2, freqs, tmp2)
if ( V_976 != V_977 &&
F_4 ( V_976 ) == F_4 ( V_977 ) )
return 0 ;
}
return V_253 ;
}
static int F_205 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
struct V_980 * V_981 ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_982 = 0 , V_253 , V_138 ;
T_9 V_948 ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_226 -> V_983 )
return - V_432 ;
F_8 ( & V_7 -> V_984 ) ;
if ( V_7 -> V_985 ) {
V_47 = - V_434 ;
goto V_986;
}
if ( V_31 -> V_5 [ V_987 ] ) {
V_253 = F_204 (
V_31 -> V_5 [ V_987 ] ) ;
if ( ! V_253 ) {
V_47 = - V_16 ;
goto V_986;
}
} else {
enum V_170 V_171 ;
V_253 = 0 ;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ )
if ( V_18 -> V_236 [ V_171 ] )
V_253 += V_18 -> V_236 [ V_171 ] -> V_253 ;
}
if ( V_31 -> V_5 [ V_988 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_982 ++ ;
if ( V_982 > V_18 -> V_191 ) {
V_47 = - V_16 ;
goto V_986;
}
if ( V_31 -> V_5 [ V_559 ] )
V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
else
V_948 = 0 ;
if ( V_948 > V_18 -> V_195 ) {
V_47 = - V_16 ;
goto V_986;
}
V_981 = F_43 ( sizeof( * V_981 )
+ sizeof( * V_981 -> V_989 ) * V_982
+ sizeof( * V_981 -> V_254 ) * V_253
+ V_948 , V_118 ) ;
if ( ! V_981 ) {
V_47 = - V_119 ;
goto V_986;
}
if ( V_982 )
V_981 -> V_989 = ( void * ) & V_981 -> V_254 [ V_253 ] ;
V_981 -> V_982 = V_982 ;
if ( V_948 ) {
if ( V_981 -> V_989 )
V_981 -> V_947 = ( void * ) ( V_981 -> V_989 + V_982 ) ;
else
V_981 -> V_947 = ( void * ) ( V_981 -> V_254 + V_253 ) ;
}
V_138 = 0 ;
if ( V_31 -> V_5 [ V_987 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_59 * V_60 ;
V_60 = F_76 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_990;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_981 -> V_254 [ V_138 ] = V_60 ;
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
V_981 -> V_254 [ V_138 ] = V_60 ;
V_138 ++ ;
}
}
}
if ( ! V_138 ) {
V_47 = - V_16 ;
goto V_990;
}
V_981 -> V_253 = V_138 ;
V_138 = 0 ;
if ( V_31 -> V_5 [ V_988 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_30 ( V_50 ) > V_503 ) {
V_47 = - V_16 ;
goto V_990;
}
V_981 -> V_989 [ V_138 ] . V_477 = F_30 ( V_50 ) ;
memcpy ( V_981 -> V_989 [ V_138 ] . V_479 , F_29 ( V_50 ) , F_30 ( V_50 ) ) ;
V_138 ++ ;
}
}
if ( V_31 -> V_5 [ V_559 ] ) {
V_981 -> V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
memcpy ( ( void * ) V_981 -> V_947 ,
F_29 ( V_31 -> V_5 [ V_559 ] ) ,
V_981 -> V_948 ) ;
}
for ( V_138 = 0 ; V_138 < V_235 ; V_138 ++ )
if ( V_18 -> V_236 [ V_138 ] )
V_981 -> V_991 [ V_138 ] =
( 1 << V_18 -> V_236 [ V_138 ] -> V_256 ) - 1 ;
if ( V_31 -> V_5 [ V_992 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_170 V_171 = F_206 ( V_50 ) ;
if ( V_171 < 0 || V_171 >= V_235 ) {
V_47 = - V_16 ;
goto V_990;
}
V_47 = F_207 ( V_18 -> V_236 [ V_171 ] ,
F_29 ( V_50 ) ,
F_30 ( V_50 ) ,
& V_981 -> V_991 [ V_171 ] ) ;
if ( V_47 )
goto V_990;
}
}
if ( V_31 -> V_5 [ V_993 ] ) {
V_981 -> V_56 = F_4 (
V_31 -> V_5 [ V_993 ] ) ;
if ( ( ( V_981 -> V_56 & V_994 ) &&
! ( V_18 -> V_386 & V_995 ) ) ||
( ( V_981 -> V_56 & V_996 ) &&
! ( V_18 -> V_386 & V_997 ) ) ) {
V_47 = - V_432 ;
goto V_990;
}
}
V_981 -> V_998 =
F_193 ( V_31 -> V_5 [ V_999 ] ) ;
V_981 -> V_17 = V_17 ;
V_981 -> V_18 = & V_7 -> V_18 ;
V_981 -> V_1000 = V_1001 ;
V_7 -> V_985 = V_981 ;
V_47 = F_208 ( V_7 , V_981 ) ;
if ( ! V_47 ) {
F_209 ( V_7 , V_17 ) ;
if ( V_17 -> V_20 )
F_210 ( V_17 -> V_20 ) ;
} else {
V_990:
V_7 -> V_985 = NULL ;
F_46 ( V_981 ) ;
}
V_986:
F_9 ( & V_7 -> V_984 ) ;
return V_47 ;
}
static int F_211 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_1002 * V_981 ;
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_982 = 0 , V_1003 = 0 , V_253 , V_138 ;
V_23 V_1004 ;
enum V_170 V_171 ;
T_9 V_948 ;
struct V_4 * V_78 [ V_1005 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_56 & V_316 ) ||
! V_7 -> V_226 -> V_317 )
return - V_432 ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1006 ] )
return - V_16 ;
V_1004 = F_4 ( V_31 -> V_5 [ V_1006 ] ) ;
if ( V_1004 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_987 ] ) {
V_253 = F_204 (
V_31 -> V_5 [ V_987 ] ) ;
if ( ! V_253 )
return - V_16 ;
} else {
V_253 = 0 ;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ )
if ( V_18 -> V_236 [ V_171 ] )
V_253 += V_18 -> V_236 [ V_171 ] -> V_253 ;
}
if ( V_31 -> V_5 [ V_988 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_982 ++ ;
if ( V_982 > V_18 -> V_193 )
return - V_16 ;
if ( V_31 -> V_5 [ V_1007 ] )
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_1003 ++ ;
if ( V_1003 > V_18 -> V_199 )
return - V_16 ;
if ( V_31 -> V_5 [ V_559 ] )
V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
else
V_948 = 0 ;
if ( V_948 > V_18 -> V_197 )
return - V_16 ;
F_8 ( & V_7 -> V_984 ) ;
if ( V_7 -> V_1008 ) {
V_47 = - V_858 ;
goto V_484;
}
V_981 = F_43 ( sizeof( * V_981 )
+ sizeof( * V_981 -> V_989 ) * V_982
+ sizeof( * V_981 -> V_1009 ) * V_1003
+ sizeof( * V_981 -> V_254 ) * V_253
+ V_948 , V_118 ) ;
if ( ! V_981 ) {
V_47 = - V_119 ;
goto V_484;
}
if ( V_982 )
V_981 -> V_989 = ( void * ) & V_981 -> V_254 [ V_253 ] ;
V_981 -> V_982 = V_982 ;
if ( V_948 ) {
if ( V_981 -> V_989 )
V_981 -> V_947 = ( void * ) ( V_981 -> V_989 + V_982 ) ;
else
V_981 -> V_947 = ( void * ) ( V_981 -> V_254 + V_253 ) ;
}
if ( V_1003 ) {
if ( V_981 -> V_947 )
V_981 -> V_1009 = ( void * ) ( V_981 -> V_947 + V_948 ) ;
else if ( V_981 -> V_989 )
V_981 -> V_1009 =
( void * ) ( V_981 -> V_989 + V_982 ) ;
else
V_981 -> V_1009 =
( void * ) ( V_981 -> V_254 + V_253 ) ;
}
V_981 -> V_1003 = V_1003 ;
V_138 = 0 ;
if ( V_31 -> V_5 [ V_987 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_59 * V_60 ;
V_60 = F_76 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_990;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_981 -> V_254 [ V_138 ] = V_60 ;
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
V_981 -> V_254 [ V_138 ] = V_60 ;
V_138 ++ ;
}
}
}
if ( ! V_138 ) {
V_47 = - V_16 ;
goto V_990;
}
V_981 -> V_253 = V_138 ;
V_138 = 0 ;
if ( V_31 -> V_5 [ V_988 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_30 ( V_50 ) > V_503 ) {
V_47 = - V_16 ;
goto V_990;
}
V_981 -> V_989 [ V_138 ] . V_477 = F_30 ( V_50 ) ;
memcpy ( V_981 -> V_989 [ V_138 ] . V_479 , F_29 ( V_50 ) ,
F_30 ( V_50 ) ) ;
V_138 ++ ;
}
}
V_138 = 0 ;
if ( V_31 -> V_5 [ V_1007 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_479 , * V_1010 ;
F_91 ( V_78 , V_1005 ,
F_29 ( V_50 ) , F_30 ( V_50 ) ,
V_1011 ) ;
V_479 = V_78 [ V_1012 ] ;
if ( V_479 ) {
if ( F_30 ( V_479 ) > V_503 ) {
V_47 = - V_16 ;
goto V_990;
}
memcpy ( V_981 -> V_1009 [ V_138 ] . V_479 . V_479 ,
F_29 ( V_479 ) , F_30 ( V_479 ) ) ;
V_981 -> V_1009 [ V_138 ] . V_479 . V_477 =
F_30 ( V_479 ) ;
}
V_1010 = V_78 [ V_1013 ] ;
if ( V_1010 )
V_981 -> V_1014 = F_4 ( V_1010 ) ;
else
V_981 -> V_1014 =
V_1015 ;
V_138 ++ ;
}
}
if ( V_31 -> V_5 [ V_559 ] ) {
V_981 -> V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
memcpy ( ( void * ) V_981 -> V_947 ,
F_29 ( V_31 -> V_5 [ V_559 ] ) ,
V_981 -> V_948 ) ;
}
if ( V_31 -> V_5 [ V_993 ] ) {
V_981 -> V_56 = F_4 (
V_31 -> V_5 [ V_993 ] ) ;
if ( ( ( V_981 -> V_56 & V_994 ) &&
! ( V_18 -> V_386 & V_995 ) ) ||
( ( V_981 -> V_56 & V_996 ) &&
! ( V_18 -> V_386 & V_997 ) ) ) {
V_47 = - V_432 ;
goto V_990;
}
}
V_981 -> V_46 = V_46 ;
V_981 -> V_18 = & V_7 -> V_18 ;
V_981 -> V_1004 = V_1004 ;
V_981 -> V_1000 = V_1001 ;
V_47 = F_212 ( V_7 , V_46 , V_981 ) ;
if ( ! V_47 ) {
V_7 -> V_1008 = V_981 ;
F_213 ( V_7 , V_46 ,
V_1016 ) ;
goto V_484;
}
V_990:
F_46 ( V_981 ) ;
V_484:
F_9 ( & V_7 -> V_984 ) ;
return V_47 ;
}
static int F_214 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
if ( ! ( V_7 -> V_18 . V_56 & V_316 ) ||
! V_7 -> V_226 -> V_1017 )
return - V_432 ;
F_8 ( & V_7 -> V_984 ) ;
V_47 = F_215 ( V_7 , false ) ;
F_9 ( & V_7 -> V_984 ) ;
return V_47 ;
}
static int F_216 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_414 V_415 ;
int V_47 ;
V_47 = F_75 ( V_7 , V_31 , & V_415 ) ;
if ( V_47 )
return V_47 ;
if ( V_17 -> V_1018 )
return - V_434 ;
V_47 = F_145 ( V_17 -> V_18 , & V_415 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_47 == 0 )
return - V_16 ;
if ( V_415 . V_60 -> V_1019 != V_1020 )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_1021 )
return - V_432 ;
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_147 ( V_7 , V_17 , V_17 -> V_124 ,
V_415 . V_60 , V_612 ,
F_146 ( V_415 . V_418 ) ) ;
if ( V_47 )
goto V_1022;
V_47 = V_7 -> V_226 -> V_1021 ( & V_7 -> V_18 , V_46 , & V_415 ) ;
if ( ! V_47 ) {
V_17 -> V_613 = V_415 . V_60 ;
V_17 -> V_1018 = true ;
V_17 -> V_1023 = V_1001 ;
}
V_1022:
F_9 ( & V_7 -> V_19 ) ;
return V_47 ;
}
static int F_217 ( struct V_44 * V_58 , struct V_34 * V_35 ,
V_23 V_55 , int V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1024 * V_1025 )
{
struct V_1026 * V_36 = & V_1025 -> V_1027 ;
const struct V_1028 * V_1029 ;
void * V_162 ;
struct V_4 * V_1030 ;
bool V_1031 = false ;
F_48 ( V_17 ) ;
V_162 = F_31 ( V_58 , F_67 ( V_35 -> V_45 ) . V_54 , V_55 , V_56 ,
V_1032 ) ;
if ( ! V_162 )
return - 1 ;
F_218 ( V_35 , V_162 , & V_39 ) ;
if ( F_34 ( V_58 , V_178 , V_7 -> V_1033 ) ||
F_34 ( V_58 , V_10 , V_17 -> V_20 -> V_21 ) )
goto V_63;
V_1030 = F_50 ( V_58 , V_1034 ) ;
if ( ! V_1030 )
goto V_63;
if ( ( ! F_219 ( V_36 -> V_436 ) &&
F_58 ( V_58 , V_1035 , V_474 , V_36 -> V_436 ) ) )
goto V_63;
F_198 () ;
V_1029 = F_199 ( V_36 -> V_1029 ) ;
if ( V_1029 ) {
if ( F_100 ( V_58 , V_1036 , V_1029 -> V_1031 ) )
goto V_1037;
V_1031 = true ;
if ( V_1029 -> V_52 && F_58 ( V_58 , V_1038 ,
V_1029 -> V_52 , V_1029 -> V_121 ) )
goto V_1037;
}
V_1029 = F_199 ( V_36 -> V_567 ) ;
if ( V_1029 ) {
if ( ! V_1031 && F_100 ( V_58 , V_1036 , V_1029 -> V_1031 ) )
goto V_1037;
if ( V_1029 -> V_52 && F_58 ( V_58 , V_1039 ,
V_1029 -> V_52 , V_1029 -> V_121 ) )
goto V_1037;
}
F_200 () ;
if ( V_36 -> V_433 &&
F_57 ( V_58 , V_1040 , V_36 -> V_433 ) )
goto V_63;
if ( F_57 ( V_58 , V_1041 , V_36 -> V_770 ) ||
F_34 ( V_58 , V_1042 , V_36 -> V_613 -> V_62 ) ||
F_34 ( V_58 , V_1043 ,
F_220 ( V_1001 - V_1025 -> V_1044 ) ) )
goto V_63;
switch ( V_7 -> V_18 . V_687 ) {
case V_688 :
if ( F_34 ( V_58 , V_1045 , V_36 -> signal ) )
goto V_63;
break;
case V_1046 :
if ( F_56 ( V_58 , V_1047 , V_36 -> signal ) )
goto V_63;
break;
default:
break;
}
switch ( V_17 -> V_124 ) {
case V_133 :
case V_132 :
if ( V_1025 == V_17 -> V_130 &&
F_34 ( V_58 , V_1048 ,
V_1049 ) )
goto V_63;
break;
case V_129 :
if ( V_1025 == V_17 -> V_130 &&
F_34 ( V_58 , V_1048 ,
V_1050 ) )
goto V_63;
break;
default:
break;
}
F_51 ( V_58 , V_1030 ) ;
return F_63 ( V_58 , V_162 ) ;
V_1037:
F_200 () ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_391 ;
}
static int F_221 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
struct V_26 * V_46 ;
struct V_1024 * V_983 ;
struct V_1 * V_17 ;
int V_393 = V_35 -> args [ 1 ] , V_88 = 0 ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_7 , & V_46 ) ;
if ( V_47 )
return V_47 ;
V_17 = V_46 -> V_29 ;
F_108 ( V_17 ) ;
F_222 ( & V_7 -> V_1051 ) ;
F_223 ( V_7 ) ;
V_35 -> V_55 = V_7 -> V_1033 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_88 <= V_393 )
continue;
if ( F_217 ( V_45 , V_35 ,
V_35 -> V_37 -> V_394 , V_395 ,
V_7 , V_17 , V_983 ) < 0 ) {
V_88 -- ;
break;
}
}
F_224 ( & V_7 -> V_1051 ) ;
F_110 ( V_17 ) ;
V_35 -> args [ 1 ] = V_88 ;
F_26 ( V_7 ) ;
return V_45 -> V_52 ;
}
static int F_225 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
struct V_1052 * V_1053 )
{
void * V_162 ;
struct V_4 * V_1054 ;
V_162 = F_31 ( V_58 , V_54 , V_55 , V_56 ,
V_1055 ) ;
if ( ! V_162 )
return - V_119 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) )
goto V_63;
V_1054 = F_50 ( V_58 , V_1056 ) ;
if ( ! V_1054 )
goto V_63;
if ( F_34 ( V_58 , V_1057 ,
V_1053 -> V_613 -> V_62 ) )
goto V_63;
if ( ( V_1053 -> V_661 & V_1058 ) &&
F_56 ( V_58 , V_1059 , V_1053 -> V_1060 ) )
goto V_63;
if ( ( V_1053 -> V_661 & V_1061 ) &&
F_35 ( V_58 , V_1062 ) )
goto V_63;
if ( ( V_1053 -> V_661 & V_1063 ) &&
F_100 ( V_58 , V_1064 ,
V_1053 -> V_1065 ) )
goto V_63;
if ( ( V_1053 -> V_661 & V_1066 ) &&
F_100 ( V_58 , V_1067 ,
V_1053 -> V_1068 ) )
goto V_63;
if ( ( V_1053 -> V_661 & V_1069 ) &&
F_100 ( V_58 , V_1070 ,
V_1053 -> V_1071 ) )
goto V_63;
if ( ( V_1053 -> V_661 & V_1072 ) &&
F_100 ( V_58 , V_1073 ,
V_1053 -> V_1074 ) )
goto V_63;
if ( ( V_1053 -> V_661 & V_1075 ) &&
F_100 ( V_58 , V_1076 ,
V_1053 -> V_1077 ) )
goto V_63;
F_51 ( V_58 , V_1054 ) ;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_391 ;
}
static int F_226 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_1052 V_1053 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
int V_1078 = V_35 -> args [ 1 ] ;
int V_36 ;
V_36 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_46 -> V_226 -> V_1079 ) {
V_36 = - V_432 ;
goto V_744;
}
while ( 1 ) {
struct V_59 * V_60 ;
V_36 = F_227 ( V_46 , V_20 , V_1078 , & V_1053 ) ;
if ( V_36 == - V_532 )
break;
if ( V_36 )
goto V_744;
if ( ! V_1053 . V_613 ) {
V_36 = - V_16 ;
goto V_484;
}
V_60 = F_76 ( & V_46 -> V_18 ,
V_1053 . V_613 -> V_62 ) ;
if ( ! V_60 || V_60 -> V_56 & V_64 ) {
V_1078 ++ ;
continue;
}
if ( F_225 ( V_45 ,
F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_394 , V_395 ,
V_20 ,
& V_1053 ) < 0 )
goto V_484;
V_1078 ++ ;
}
V_484:
V_35 -> args [ 1 ] = V_1078 ;
V_36 = V_45 -> V_52 ;
V_744:
F_26 ( V_46 ) ;
return V_36 ;
}
static bool F_228 ( V_23 V_1080 )
{
return ! ( V_1080 & ~ ( V_1081 |
V_1082 ) ) ;
}
static int F_229 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_59 * V_60 ;
const T_2 * V_436 , * V_479 , * V_947 = NULL , * V_1083 = NULL ;
int V_47 , V_477 , V_948 = 0 , V_1084 = 0 ;
enum V_577 V_578 ;
struct V_76 V_75 ;
bool V_1085 ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_598 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_478 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_417 ] )
return - V_16 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 >= 0 ) {
if ( V_75 . type != - 1 && V_75 . type != V_528 )
return - V_16 ;
if ( ! V_75 . V_90 . V_75 || ! V_75 . V_90 . V_91 )
return - V_16 ;
if ( ( V_75 . V_90 . V_95 != V_122 ||
V_75 . V_90 . V_91 != V_1086 ) &&
( V_75 . V_90 . V_95 != V_123 ||
V_75 . V_90 . V_91 != V_1087 ) )
return - V_16 ;
if ( V_75 . V_88 > 4 )
return - V_16 ;
} else {
V_75 . V_90 . V_91 = 0 ;
V_75 . V_90 . V_75 = NULL ;
}
if ( V_75 . V_88 >= 0 ) {
int V_138 ;
bool V_1088 = false ;
for ( V_138 = 0 ; V_138 < V_7 -> V_18 . V_213 ; V_138 ++ ) {
if ( V_75 . V_90 . V_95 == V_7 -> V_18 . V_214 [ V_138 ] ) {
V_1088 = true ;
break;
}
}
if ( ! V_1088 )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_279 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_60 = F_76 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_417 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_479 = F_29 ( V_31 -> V_5 [ V_478 ] ) ;
V_477 = F_30 ( V_31 -> V_5 [ V_478 ] ) ;
if ( V_31 -> V_5 [ V_559 ] ) {
V_947 = F_29 ( V_31 -> V_5 [ V_559 ] ) ;
V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
}
V_578 = F_4 ( V_31 -> V_5 [ V_598 ] ) ;
if ( ! F_141 ( V_7 , V_578 , V_581 ) )
return - V_16 ;
if ( V_578 == V_583 &&
! V_31 -> V_5 [ V_1089 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_1089 ] ) {
if ( V_578 != V_583 )
return - V_16 ;
V_1083 = F_29 ( V_31 -> V_5 [ V_1089 ] ) ;
V_1084 = F_30 ( V_31 -> V_5 [ V_1089 ] ) ;
if ( V_1084 < 4 )
return - V_16 ;
}
V_1085 = ! ! V_31 -> V_5 [ V_1090 ] ;
if ( V_1085 )
return 0 ;
return F_230 ( V_7 , V_46 , V_60 , V_578 , V_436 ,
V_479 , V_477 , V_947 , V_948 ,
V_75 . V_90 . V_75 , V_75 . V_90 . V_91 , V_75 . V_88 ,
V_1083 , V_1084 ) ;
}
static int F_144 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_1091 * V_1092 ,
int V_1093 )
{
memset ( V_1092 , 0 , sizeof( * V_1092 ) ) ;
V_1092 -> V_1094 = V_31 -> V_5 [ V_1095 ] ;
if ( V_31 -> V_5 [ V_218 ] ) {
T_3 V_1096 ;
V_1096 = F_73 (
V_31 -> V_5 [ V_218 ] ) ;
V_1092 -> V_1097 = F_231 ( V_1096 ) ;
if ( ! ( V_7 -> V_18 . V_56 & V_217 ) &&
V_1096 != V_1098 )
return - V_16 ;
if ( V_31 -> V_5 [ V_1099 ] )
V_1092 -> V_1100 = true ;
} else
V_1092 -> V_1097 = F_231 ( V_1098 ) ;
if ( V_31 -> V_5 [ V_1101 ] ) {
void * V_121 ;
int V_52 , V_138 ;
V_121 = F_29 ( V_31 -> V_5 [ V_1101 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_1101 ] ) ;
V_1092 -> V_1102 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_1092 -> V_1102 > V_1093 )
return - V_16 ;
memcpy ( V_1092 -> V_1103 , V_121 , V_52 ) ;
for ( V_138 = 0 ; V_138 < V_1092 -> V_1102 ; V_138 ++ )
if ( ! F_232 (
& V_7 -> V_18 ,
V_1092 -> V_1103 [ V_138 ] ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1104 ] ) {
V_1092 -> V_1105 =
F_4 ( V_31 -> V_5 [ V_1104 ] ) ;
if ( ! F_232 ( & V_7 -> V_18 ,
V_1092 -> V_1105 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1106 ] ) {
V_1092 -> V_1080 =
F_4 ( V_31 -> V_5 [ V_1106 ] ) ;
if ( ! F_228 ( V_1092 -> V_1080 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1107 ] ) {
void * V_121 ;
int V_52 ;
V_121 = F_29 ( V_31 -> V_5 [ V_1107 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_1107 ] ) ;
V_1092 -> V_1108 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_1092 -> V_1108 > V_1109 )
return - V_16 ;
memcpy ( V_1092 -> V_1110 , V_121 , V_52 ) ;
}
return 0 ;
}
static int F_233 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1091 V_600 ;
struct V_59 * V_60 ;
const T_2 * V_436 , * V_479 , * V_947 = NULL , * V_1111 = NULL ;
int V_47 , V_477 , V_948 = 0 ;
bool V_1112 = false ;
V_23 V_56 = 0 ;
struct V_1113 * V_751 = NULL ;
struct V_1113 * V_1114 = NULL ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_437 ] ||
! V_31 -> V_5 [ V_478 ] ||
! V_31 -> V_5 [ V_417 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_281 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_60 = F_76 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_417 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_479 = F_29 ( V_31 -> V_5 [ V_478 ] ) ;
V_477 = F_30 ( V_31 -> V_5 [ V_478 ] ) ;
if ( V_31 -> V_5 [ V_559 ] ) {
V_947 = F_29 ( V_31 -> V_5 [ V_559 ] ) ;
V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
}
if ( V_31 -> V_5 [ V_1115 ] ) {
enum V_1116 V_1117 =
F_4 ( V_31 -> V_5 [ V_1115 ] ) ;
if ( V_1117 == V_1118 )
V_1112 = true ;
else if ( V_1117 != V_1119 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1120 ] )
V_1111 = F_29 ( V_31 -> V_5 [ V_1120 ] ) ;
if ( F_193 ( V_31 -> V_5 [ V_1121 ] ) )
V_56 |= V_1122 ;
if ( V_31 -> V_5 [ V_388 ] )
V_1114 =
F_29 ( V_31 -> V_5 [ V_388 ] ) ;
if ( V_31 -> V_5 [ V_750 ] ) {
if ( ! V_1114 )
return - V_16 ;
V_751 = F_29 ( V_31 -> V_5 [ V_750 ] ) ;
}
V_47 = F_144 ( V_7 , V_31 , & V_600 , 1 ) ;
if ( ! V_47 )
V_47 = F_234 ( V_7 , V_46 , V_60 , V_436 , V_1111 ,
V_479 , V_477 , V_947 , V_948 , V_1112 ,
& V_600 , V_56 , V_751 ,
V_1114 ) ;
return V_47 ;
}
static int F_235 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
const T_2 * V_947 = NULL , * V_436 ;
int V_948 = 0 ;
T_3 V_1123 ;
bool V_1085 ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1124 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_283 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_1123 = F_73 ( V_31 -> V_5 [ V_1124 ] ) ;
if ( V_1123 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_559 ] ) {
V_947 = F_29 ( V_31 -> V_5 [ V_559 ] ) ;
V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
}
V_1085 = ! ! V_31 -> V_5 [ V_1090 ] ;
return F_236 ( V_7 , V_46 , V_436 , V_947 , V_948 , V_1123 ,
V_1085 ) ;
}
static int F_237 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
const T_2 * V_947 = NULL , * V_436 ;
int V_948 = 0 ;
T_3 V_1123 ;
bool V_1085 ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1124 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_285 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_1123 = F_73 ( V_31 -> V_5 [ V_1124 ] ) ;
if ( V_1123 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_559 ] ) {
V_947 = F_29 ( V_31 -> V_5 [ V_559 ] ) ;
V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
}
V_1085 = ! ! V_31 -> V_5 [ V_1090 ] ;
return F_238 ( V_7 , V_46 , V_436 , V_947 , V_948 , V_1123 ,
V_1085 ) ;
}
static bool
F_239 ( struct V_6 * V_7 ,
int V_1125 [ V_235 ] ,
int V_1126 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_28 = false ;
int V_171 , V_138 ;
for ( V_171 = 0 ; V_171 < V_235 ; V_171 ++ ) {
struct V_1127 * V_1128 ;
V_1128 = V_18 -> V_236 [ V_171 ] ;
if ( ! V_1128 )
continue;
for ( V_138 = 0 ; V_138 < V_1128 -> V_256 ; V_138 ++ ) {
if ( V_1128 -> V_257 [ V_138 ] . V_259 == V_1126 ) {
V_1125 [ V_171 ] = V_138 + 1 ;
V_28 = true ;
break;
}
}
}
return V_28 ;
}
static int F_240 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1129 V_1130 ;
struct V_18 * V_18 ;
struct V_113 * V_1131 = NULL ;
int V_47 ;
memset ( & V_1130 , 0 , sizeof( V_1130 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_478 ] ||
! F_30 ( V_31 -> V_5 [ V_478 ] ) )
return - V_16 ;
V_1130 . V_433 = 100 ;
if ( V_31 -> V_5 [ V_587 ] ) {
V_1130 . V_433 =
F_4 ( V_31 -> V_5 [ V_587 ] ) ;
if ( V_1130 . V_433 < 1 || V_1130 . V_433 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_226 -> V_287 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_129 )
return - V_432 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_437 ] ) {
V_1130 . V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( ! F_114 ( V_1130 . V_436 ) )
return - V_16 ;
}
V_1130 . V_479 = F_29 ( V_31 -> V_5 [ V_478 ] ) ;
V_1130 . V_477 = F_30 ( V_31 -> V_5 [ V_478 ] ) ;
if ( V_31 -> V_5 [ V_559 ] ) {
V_1130 . V_947 = F_29 ( V_31 -> V_5 [ V_559 ] ) ;
V_1130 . V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
}
V_47 = F_75 ( V_7 , V_31 , & V_1130 . V_415 ) ;
if ( V_47 )
return V_47 ;
if ( ! F_81 ( & V_7 -> V_18 , & V_1130 . V_415 ) )
return - V_16 ;
if ( V_1130 . V_415 . V_418 > V_469 )
return - V_16 ;
if ( V_1130 . V_415 . V_418 != V_419 &&
! ( V_7 -> V_18 . V_386 & V_1132 ) )
return - V_16 ;
V_1130 . V_1133 = ! ! V_31 -> V_5 [ V_1134 ] ;
V_1130 . V_596 = ! ! V_31 -> V_5 [ V_597 ] ;
if ( V_31 -> V_5 [ V_832 ] ) {
T_2 * V_991 =
F_29 ( V_31 -> V_5 [ V_832 ] ) ;
int V_1135 =
F_30 ( V_31 -> V_5 [ V_832 ] ) ;
struct V_1127 * V_1128 =
V_18 -> V_236 [ V_1130 . V_415 . V_60 -> V_171 ] ;
V_47 = F_207 ( V_1128 , V_991 , V_1135 ,
& V_1130 . V_833 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_1136 ] &&
! F_239 ( V_7 , V_1130 . V_1125 ,
F_4 ( V_31 -> V_5 [ V_1136 ] ) ) )
return - V_16 ;
if ( V_1130 . V_596 && V_31 -> V_5 [ V_1137 ] ) {
bool V_115 = false ;
V_1131 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1137 ] ,
& V_115 ) ;
if ( F_16 ( V_1131 ) )
return F_24 ( V_1131 ) ;
if ( ( V_1130 . V_415 . V_418 != V_419 ) &&
V_115 ) {
F_46 ( V_1131 ) ;
return - V_16 ;
}
}
V_1130 . V_1094 =
F_193 ( V_31 -> V_5 [ V_1095 ] ) ;
V_47 = F_241 ( V_7 , V_46 , & V_1130 , V_1131 ) ;
if ( V_47 )
F_46 ( V_1131 ) ;
return V_47 ;
}
static int F_242 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
if ( ! V_7 -> V_226 -> V_1138 )
return - V_432 ;
if ( V_46 -> V_29 -> V_124 != V_129 )
return - V_432 ;
return F_243 ( V_7 , V_46 , false ) ;
}
static int F_244 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
int V_1125 [ V_235 ] ;
V_23 V_1139 ;
int V_47 ;
if ( V_46 -> V_29 -> V_124 != V_129 &&
V_46 -> V_29 -> V_124 != V_128 )
return - V_432 ;
if ( ! V_7 -> V_226 -> V_327 )
return - V_432 ;
memset ( V_1125 , 0 , sizeof( V_1125 ) ) ;
if ( ! V_31 -> V_5 [ V_1136 ] )
return - V_16 ;
V_1139 = F_4 ( V_31 -> V_5 [ V_1136 ] ) ;
if ( ! F_239 ( V_7 , V_1125 , V_1139 ) )
return - V_16 ;
V_47 = V_7 -> V_226 -> V_327 ( & V_7 -> V_18 , V_46 , V_1125 ) ;
return V_47 ;
}
static int F_245 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1140 ] )
return - V_16 ;
V_47 = - V_432 ;
if ( V_7 -> V_226 -> V_329 ) {
V_7 -> V_1141 = V_31 ;
V_47 = F_246 ( V_7 ,
F_29 ( V_31 -> V_5 [ V_1140 ] ) ,
F_30 ( V_31 -> V_5 [ V_1140 ] ) ) ;
V_7 -> V_1141 = NULL ;
}
return V_47 ;
}
static int F_247 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
int V_47 ;
long V_1142 ;
void * V_121 = NULL ;
int V_1143 = 0 ;
if ( V_35 -> args [ 0 ] ) {
V_1142 = V_35 -> args [ 0 ] - 1 ;
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
V_1142 = V_7 -> V_14 ;
V_7 = NULL ;
F_9 ( & V_32 ) ;
if ( V_39 . V_41 [ V_1140 ] )
V_35 -> args [ 1 ] =
( long ) V_39 . V_41 [ V_1140 ] ;
}
if ( V_35 -> args [ 1 ] ) {
V_121 = F_29 ( ( void * ) V_35 -> args [ 1 ] ) ;
V_1143 = F_30 ( ( void * ) V_35 -> args [ 1 ] ) ;
}
F_8 ( & V_32 ) ;
V_7 = F_11 ( V_1142 ) ;
if ( ! V_7 ) {
F_9 ( & V_32 ) ;
return - V_532 ;
}
F_248 ( V_7 ) ;
F_9 ( & V_32 ) ;
if ( ! V_7 -> V_226 -> V_1144 ) {
V_47 = - V_432 ;
goto V_744;
}
while ( 1 ) {
void * V_162 = F_31 ( V_45 , F_67 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_394 , V_395 ,
V_1145 ) ;
struct V_4 * V_1146 ;
if ( F_34 ( V_45 , V_27 , V_1142 ) ) {
F_64 ( V_45 , V_162 ) ;
break;
}
V_1146 = F_50 ( V_45 , V_1140 ) ;
if ( ! V_1146 ) {
F_64 ( V_45 , V_162 ) ;
break;
}
V_47 = F_249 ( V_7 , V_45 , V_35 , V_121 , V_1143 ) ;
F_51 ( V_45 , V_1146 ) ;
if ( V_47 == - V_74 || V_47 == - V_532 ) {
F_64 ( V_45 , V_162 ) ;
break;
} else if ( V_47 ) {
F_64 ( V_45 , V_162 ) ;
goto V_744;
}
F_63 ( V_45 , V_162 ) ;
}
V_47 = V_45 -> V_52 ;
V_35 -> args [ 0 ] = V_1142 + 1 ;
V_744:
F_27 ( V_7 ) ;
return V_47 ;
}
static struct V_44 *
F_250 ( struct V_6 * V_7 ,
int V_1147 , V_23 V_54 , V_23 V_55 , T_10 V_1148 )
{
struct V_44 * V_45 ;
void * V_162 ;
struct V_4 * V_121 ;
V_45 = F_69 ( V_1147 + 100 , V_1148 ) ;
if ( ! V_45 )
return NULL ;
V_162 = F_31 ( V_45 , V_54 , V_55 , 0 , V_1145 ) ;
if ( ! V_162 ) {
F_251 ( V_45 ) ;
return NULL ;
}
if ( F_34 ( V_45 , V_27 , V_7 -> V_14 ) )
goto V_63;
V_121 = F_50 ( V_45 , V_1140 ) ;
( ( void * * ) V_45 -> V_35 ) [ 0 ] = V_7 ;
( ( void * * ) V_45 -> V_35 ) [ 1 ] = V_162 ;
( ( void * * ) V_45 -> V_35 ) [ 2 ] = V_121 ;
return V_45 ;
V_63:
F_251 ( V_45 ) ;
return NULL ;
}
struct V_44 * F_252 ( struct V_18 * V_18 ,
int V_1147 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
if ( F_97 ( ! V_7 -> V_1141 ) )
return NULL ;
return F_250 ( V_7 , V_1147 ,
V_7 -> V_1141 -> V_398 ,
V_7 -> V_1141 -> V_399 ,
V_118 ) ;
}
int F_253 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = ( ( void * * ) V_45 -> V_35 ) [ 0 ] ;
void * V_162 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_121 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
if ( F_97 ( ! V_7 -> V_1141 ) ) {
F_251 ( V_45 ) ;
return - V_16 ;
}
F_51 ( V_45 , V_121 ) ;
F_63 ( V_45 , V_162 ) ;
return F_71 ( V_45 , V_7 -> V_1141 ) ;
}
struct V_44 * F_254 ( struct V_18 * V_18 ,
int V_1147 , T_10 V_1148 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
return F_250 ( V_7 , V_1147 , 0 , 0 , V_1148 ) ;
}
void F_255 ( struct V_44 * V_45 , T_10 V_1148 )
{
void * V_162 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_121 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
F_51 ( V_45 , V_121 ) ;
F_63 ( V_45 , V_162 ) ;
F_256 ( V_45 , 0 , V_1149 . V_1150 , V_1148 ) ;
}
static int F_257 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1151 V_331 ;
struct V_18 * V_18 ;
struct V_113 * V_1131 = NULL ;
int V_47 ;
memset ( & V_331 , 0 , sizeof( V_331 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_559 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_478 ] ||
! F_30 ( V_31 -> V_5 [ V_478 ] ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_598 ] ) {
V_331 . V_578 =
F_4 ( V_31 -> V_5 [ V_598 ] ) ;
if ( ! F_141 ( V_7 , V_331 . V_578 ,
V_332 ) )
return - V_16 ;
} else
V_331 . V_578 = V_599 ;
V_331 . V_596 = V_31 -> V_5 [ V_597 ] ;
V_47 = F_144 ( V_7 , V_31 , & V_331 . V_600 ,
V_601 ) ;
if ( V_47 )
return V_47 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
V_18 = & V_7 -> V_18 ;
V_331 . V_1152 = - 1 ;
if ( V_31 -> V_5 [ V_1153 ] &&
( V_18 -> V_56 & V_206 ) ) {
V_331 . V_1152 =
F_73 ( V_31 -> V_5 [ V_1153 ] ) ;
}
if ( V_31 -> V_5 [ V_437 ] )
V_331 . V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_331 . V_479 = F_29 ( V_31 -> V_5 [ V_478 ] ) ;
V_331 . V_477 = F_30 ( V_31 -> V_5 [ V_478 ] ) ;
if ( V_31 -> V_5 [ V_559 ] ) {
V_331 . V_947 = F_29 ( V_31 -> V_5 [ V_559 ] ) ;
V_331 . V_948 = F_30 ( V_31 -> V_5 [ V_559 ] ) ;
}
if ( V_31 -> V_5 [ V_1115 ] ) {
V_331 . V_1117 = F_4 ( V_31 -> V_5 [ V_1115 ] ) ;
if ( V_331 . V_1117 != V_1118 &&
V_331 . V_1117 != V_1119 )
return - V_16 ;
} else {
V_331 . V_1117 = V_1119 ;
}
if ( V_31 -> V_5 [ V_417 ] ) {
V_331 . V_613 =
F_76 ( V_18 ,
F_4 ( V_31 -> V_5 [ V_417 ] ) ) ;
if ( ! V_331 . V_613 ||
V_331 . V_613 -> V_56 & V_64 )
return - V_16 ;
}
if ( V_331 . V_596 && V_31 -> V_5 [ V_1137 ] ) {
V_1131 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1137 ] , NULL ) ;
if ( F_16 ( V_1131 ) )
return F_24 ( V_1131 ) ;
}
if ( F_193 ( V_31 -> V_5 [ V_1121 ] ) )
V_331 . V_56 |= V_1122 ;
if ( V_31 -> V_5 [ V_388 ] )
memcpy ( & V_331 . V_1114 ,
F_29 ( V_31 -> V_5 [ V_388 ] ) ,
sizeof( V_331 . V_1114 ) ) ;
if ( V_31 -> V_5 [ V_750 ] ) {
if ( ! V_31 -> V_5 [ V_388 ] ) {
F_46 ( V_1131 ) ;
return - V_16 ;
}
memcpy ( & V_331 . V_751 ,
F_29 ( V_31 -> V_5 [ V_750 ] ) ,
sizeof( V_331 . V_751 ) ) ;
}
V_47 = F_258 ( V_7 , V_46 , & V_331 , V_1131 ) ;
if ( V_47 )
F_46 ( V_1131 ) ;
return V_47 ;
}
static int F_259 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_3 V_1154 ;
if ( ! V_31 -> V_5 [ V_1124 ] )
V_1154 = V_1155 ;
else
V_1154 = F_73 ( V_31 -> V_5 [ V_1124 ] ) ;
if ( V_1154 == 0 )
return - V_16 ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
return F_260 ( V_7 , V_46 , V_1154 , true ) ;
}
static int F_261 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_2 * V_2 ;
int V_47 ;
V_23 V_1156 ;
if ( ! V_31 -> V_5 [ V_1157 ] )
return - V_16 ;
V_1156 = F_4 ( V_31 -> V_5 [ V_1157 ] ) ;
V_2 = F_262 ( V_1156 ) ;
if ( F_16 ( V_2 ) )
return F_24 ( V_2 ) ;
V_47 = 0 ;
if ( ! F_66 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_47 = F_263 ( V_7 , V_2 ) ;
F_264 ( V_2 ) ;
return V_47 ;
}
static int F_265 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
int (* F_266)( struct V_18 * V_18 , struct V_26 * V_46 ,
struct V_1158 * V_1159 ) = NULL ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1158 V_1159 ;
memset ( & V_1159 , 0 , sizeof( struct V_1158 ) ) ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1160 ] )
return - V_16 ;
V_1159 . V_1161 = F_29 ( V_31 -> V_5 [ V_1160 ] ) ;
V_1159 . V_436 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
switch ( V_31 -> V_1162 -> V_57 ) {
case V_1163 :
F_266 = V_7 -> V_226 -> V_291 ;
break;
case V_1164 :
F_266 = V_7 -> V_226 -> V_293 ;
break;
default:
F_97 ( 1 ) ;
break;
}
if ( ! F_266 )
return - V_432 ;
return F_266 ( & V_7 -> V_18 , V_46 , & V_1159 ) ;
}
static int F_267 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
if ( V_46 -> V_29 -> V_124 != V_132 &&
V_46 -> V_29 -> V_124 != V_133 )
return - V_432 ;
if ( ! V_7 -> V_226 -> V_295 )
return - V_432 ;
return F_268 ( V_7 , V_46 ) ;
}
static int F_269 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 V_1165 , V_1166 ;
T_3 V_1167 ;
T_2 * V_1168 ;
if ( ! ( V_7 -> V_18 . V_56 & V_208 ) ||
! V_7 -> V_226 -> V_312 )
return - V_432 ;
if ( ! V_31 -> V_5 [ V_1169 ] ||
! V_31 -> V_5 [ V_1170 ] ||
! V_31 -> V_5 [ V_1171 ] ||
! V_31 -> V_5 [ V_559 ] ||
! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
V_1168 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_1165 = F_39 ( V_31 -> V_5 [ V_1169 ] ) ;
V_1167 = F_73 ( V_31 -> V_5 [ V_1170 ] ) ;
V_1166 = F_39 ( V_31 -> V_5 [ V_1171 ] ) ;
return F_270 ( V_7 , V_46 , V_1168 , V_1165 ,
V_1166 , V_1167 ,
F_29 ( V_31 -> V_5 [ V_559 ] ) ,
F_30 ( V_31 -> V_5 [ V_559 ] ) ) ;
}
static int F_271 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
enum V_1172 V_1173 ;
T_2 * V_1168 ;
if ( ! ( V_7 -> V_18 . V_56 & V_208 ) ||
! V_7 -> V_226 -> V_314 )
return - V_432 ;
if ( ! V_31 -> V_5 [ V_1174 ] ||
! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
V_1173 = F_39 ( V_31 -> V_5 [ V_1174 ] ) ;
V_1168 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
return F_272 ( V_7 , V_46 , V_1168 , V_1173 ) ;
}
static int F_273 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
struct V_414 V_415 ;
struct V_44 * V_58 ;
void * V_162 ;
T_1 V_523 ;
V_23 V_1175 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_417 ] ||
! V_31 -> V_5 [ V_1176 ] )
return - V_16 ;
V_1175 = F_4 ( V_31 -> V_5 [ V_1176 ] ) ;
if ( ! V_7 -> V_226 -> V_298 ||
! ( V_7 -> V_18 . V_56 & V_297 ) )
return - V_432 ;
if ( V_1175 < V_1177 ||
V_1175 > V_7 -> V_18 . V_336 )
return - V_16 ;
V_47 = F_75 ( V_7 , V_31 , & V_415 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_1178 ) ;
if ( F_16 ( V_162 ) ) {
V_47 = F_24 ( V_162 ) ;
goto V_533;
}
V_47 = F_274 ( V_7 , V_17 , V_415 . V_60 ,
V_1175 , & V_523 ) ;
if ( V_47 )
goto V_533;
if ( F_100 ( V_58 , V_1179 , V_523 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_533:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_275 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
T_1 V_523 ;
if ( ! V_31 -> V_5 [ V_1179 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_1180 )
return - V_432 ;
V_523 = F_5 ( V_31 -> V_5 [ V_1179 ] ) ;
return F_276 ( V_7 , V_17 , V_523 ) ;
}
static V_23 F_277 ( struct V_1127 * V_1128 ,
T_2 * V_991 , T_2 V_1181 )
{
T_2 V_138 ;
V_23 V_621 = 0 ;
for ( V_138 = 0 ; V_138 < V_1181 ; V_138 ++ ) {
int V_173 = ( V_991 [ V_138 ] & 0x7f ) * 5 ;
int V_1182 ;
for ( V_1182 = 0 ; V_1182 < V_1128 -> V_256 ; V_1182 ++ ) {
struct V_172 * V_1183 =
& V_1128 -> V_257 [ V_1182 ] ;
if ( V_173 == V_1183 -> V_259 ) {
V_621 |= 1 << V_1182 ;
break;
}
}
if ( V_1182 == V_1128 -> V_256 )
return 0 ;
}
return V_621 ;
}
static bool F_278 ( struct V_1127 * V_1128 ,
T_2 * V_991 , T_2 V_1181 ,
T_2 V_240 [ V_1184 ] )
{
T_2 V_138 ;
memset ( V_240 , 0 , V_1184 ) ;
for ( V_138 = 0 ; V_138 < V_1181 ; V_138 ++ ) {
int V_1182 , V_1185 ;
V_1182 = V_991 [ V_138 ] / 8 ;
V_1185 = F_146 ( V_991 [ V_138 ] % 8 ) ;
if ( ( V_1182 < 0 ) || ( V_1182 >= V_1184 ) )
return false ;
if ( V_1128 -> V_237 . V_240 . V_1186 [ V_1182 ] & V_1185 )
V_240 [ V_1182 ] |= V_1185 ;
else
return false ;
}
return true ;
}
static int F_279 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_1187 + 1 ] ;
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1188 V_621 ;
int V_117 , V_138 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_4 * V_1189 ;
struct V_1127 * V_1128 ;
if ( V_31 -> V_5 [ V_1190 ] == NULL )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_300 )
return - V_432 ;
memset ( & V_621 , 0 , sizeof( V_621 ) ) ;
for ( V_138 = 0 ; V_138 < V_235 ; V_138 ++ ) {
V_1128 = V_7 -> V_18 . V_236 [ V_138 ] ;
V_621 . V_1191 [ V_138 ] . V_1192 =
V_1128 ? ( 1 << V_1128 -> V_256 ) - 1 : 0 ;
if ( V_1128 )
memcpy ( V_621 . V_1191 [ V_138 ] . V_240 ,
V_1128 -> V_237 . V_240 . V_1186 ,
sizeof( V_621 . V_1191 [ V_138 ] . V_240 ) ) ;
else
memset ( V_621 . V_1191 [ V_138 ] . V_240 , 0 ,
sizeof( V_621 . V_1191 [ V_138 ] . V_240 ) ) ;
}
F_109 ( V_1193 > V_1184 * 8 ) ;
F_44 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_170 V_171 = F_206 ( V_1189 ) ;
if ( V_171 < 0 || V_171 >= V_235 )
return - V_16 ;
V_1128 = V_7 -> V_18 . V_236 [ V_171 ] ;
if ( V_1128 == NULL )
return - V_16 ;
F_91 ( V_78 , V_1187 , F_29 ( V_1189 ) ,
F_30 ( V_1189 ) , V_1194 ) ;
if ( V_78 [ V_1195 ] ) {
V_621 . V_1191 [ V_171 ] . V_1192 = F_277 (
V_1128 ,
F_29 ( V_78 [ V_1195 ] ) ,
F_30 ( V_78 [ V_1195 ] ) ) ;
if ( ( V_621 . V_1191 [ V_171 ] . V_1192 == 0 ) &&
F_30 ( V_78 [ V_1195 ] ) )
return - V_16 ;
}
if ( V_78 [ V_1196 ] ) {
if ( ! F_278 (
V_1128 ,
F_29 ( V_78 [ V_1196 ] ) ,
F_30 ( V_78 [ V_1196 ] ) ,
V_621 . V_1191 [ V_171 ] . V_240 ) )
return - V_16 ;
}
if ( V_621 . V_1191 [ V_171 ] . V_1192 == 0 ) {
if ( ! V_7 -> V_18 . V_236 [ V_171 ] -> V_237 . V_238 )
return - V_16 ;
for ( V_138 = 0 ; V_138 < V_1184 ; V_138 ++ )
if ( V_621 . V_1191 [ V_171 ] . V_240 [ V_138 ] )
break;
if ( V_138 == V_1184 )
return - V_16 ;
}
}
return F_280 ( V_7 , V_46 , NULL , & V_621 ) ;
}
static int F_281 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
T_3 V_1197 = V_348 | V_1198 ;
if ( ! V_31 -> V_5 [ V_1199 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_347 ] )
V_1197 = F_73 ( V_31 -> V_5 [ V_347 ] ) ;
switch ( V_17 -> V_124 ) {
case V_132 :
case V_129 :
case V_133 :
case V_125 :
case V_126 :
case V_128 :
case V_127 :
case V_509 :
break;
default:
return - V_432 ;
}
if ( ! V_7 -> V_226 -> V_302 )
return - V_432 ;
return F_282 ( V_17 , V_31 -> V_398 , V_1197 ,
F_29 ( V_31 -> V_5 [ V_1199 ] ) ,
F_30 ( V_31 -> V_5 [ V_1199 ] ) ) ;
}
static int F_283 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
struct V_414 V_415 ;
int V_47 ;
void * V_162 = NULL ;
T_1 V_523 ;
struct V_44 * V_58 = NULL ;
unsigned int V_1200 = 0 ;
bool V_1201 , V_998 , V_1202 ;
V_1202 = V_31 -> V_5 [ V_1203 ] ;
if ( ! V_31 -> V_5 [ V_1204 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_302 )
return - V_432 ;
switch ( V_17 -> V_124 ) {
case V_132 :
case V_129 :
case V_133 :
case V_125 :
case V_126 :
case V_128 :
case V_127 :
case V_509 :
break;
default:
return - V_432 ;
}
if ( V_31 -> V_5 [ V_1176 ] ) {
if ( ! ( V_7 -> V_18 . V_56 & V_337 ) )
return - V_16 ;
V_1200 = F_4 ( V_31 -> V_5 [ V_1176 ] ) ;
if ( V_1200 < V_1177 ||
V_1200 > V_7 -> V_18 . V_336 )
return - V_16 ;
}
V_1201 = V_31 -> V_5 [ V_338 ] ;
if ( V_1201 && ! ( V_7 -> V_18 . V_56 & V_337 ) )
return - V_16 ;
V_998 = F_193 ( V_31 -> V_5 [ V_999 ] ) ;
V_47 = F_75 ( V_7 , V_31 , & V_415 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_1202 ) {
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_1205 ) ;
if ( F_16 ( V_162 ) ) {
V_47 = F_24 ( V_162 ) ;
goto V_533;
}
}
V_47 = F_284 ( V_7 , V_17 , V_415 . V_60 , V_1201 , V_1200 ,
F_29 ( V_31 -> V_5 [ V_1204 ] ) ,
F_30 ( V_31 -> V_5 [ V_1204 ] ) ,
V_998 , V_1202 , & V_523 ) ;
if ( V_47 )
goto V_533;
if ( V_58 ) {
if ( F_100 ( V_58 , V_1179 , V_523 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
}
return 0 ;
V_63:
V_47 = - V_74 ;
V_533:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_285 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
T_1 V_523 ;
if ( ! V_31 -> V_5 [ V_1179 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_304 )
return - V_432 ;
switch ( V_17 -> V_124 ) {
case V_132 :
case V_129 :
case V_133 :
case V_125 :
case V_126 :
case V_127 :
case V_509 :
break;
default:
return - V_432 ;
}
V_523 = F_5 ( V_31 -> V_5 [ V_1179 ] ) ;
return F_286 ( V_7 , V_17 , V_523 ) ;
}
static int F_287 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
T_2 V_1206 ;
bool V_1207 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1208 ] )
return - V_16 ;
V_1206 = F_4 ( V_31 -> V_5 [ V_1208 ] ) ;
if ( V_1206 != V_1209 && V_1206 != V_1210 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1211 )
return - V_432 ;
V_1207 = ( V_1206 == V_1210 ) ? true : false ;
if ( V_1207 == V_17 -> V_1212 )
return 0 ;
V_47 = F_288 ( V_7 , V_46 , V_1207 , V_17 -> V_1213 ) ;
if ( ! V_47 )
V_17 -> V_1212 = V_1207 ;
return V_47 ;
}
static int F_289 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
enum V_1214 V_1206 ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1211 )
return - V_432 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_1215 ) ;
if ( ! V_162 ) {
V_47 = - V_74 ;
goto V_533;
}
if ( V_17 -> V_1212 )
V_1206 = V_1210 ;
else
V_1206 = V_1209 ;
if ( F_34 ( V_58 , V_1208 , V_1206 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_533:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_290 ( struct V_30 * V_31 ,
V_23 V_173 , V_23 V_1216 , V_23 V_1217 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
if ( V_173 > 100 || V_1217 > V_1218 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1219 )
return - V_432 ;
if ( V_17 -> V_124 != V_132 &&
V_17 -> V_124 != V_133 )
return - V_432 ;
return F_291 ( V_7 , V_46 , V_173 , V_1216 , V_1217 ) ;
}
static int F_292 ( struct V_30 * V_31 ,
T_11 V_1220 , V_23 V_1221 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
if ( V_1220 > 0 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_226 -> V_1222 )
return - V_432 ;
if ( V_17 -> V_124 != V_132 &&
V_17 -> V_124 != V_133 )
return - V_432 ;
return F_293 ( V_7 , V_46 , V_1220 , V_1221 ) ;
}
static int F_294 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_5 [ V_1223 + 1 ] ;
struct V_4 * V_1224 ;
int V_47 ;
V_1224 = V_31 -> V_5 [ V_1225 ] ;
if ( ! V_1224 ) {
V_47 = - V_16 ;
goto V_484;
}
V_47 = F_38 ( V_5 , V_1223 , V_1224 ,
V_1226 ) ;
if ( V_47 )
goto V_484;
if ( V_5 [ V_1227 ] &&
V_5 [ V_1228 ] ) {
T_11 V_1220 ;
V_23 V_1221 ;
V_1220 = F_4 ( V_5 [ V_1227 ] ) ;
V_1221 = F_4 ( V_5 [ V_1228 ] ) ;
V_47 = F_292 ( V_31 , V_1220 , V_1221 ) ;
} else if ( V_5 [ V_1229 ] &&
V_5 [ V_1230 ] &&
V_5 [ V_1231 ] ) {
V_23 V_173 , V_1216 , V_1217 ;
V_173 = F_4 ( V_5 [ V_1229 ] ) ;
V_1216 = F_4 ( V_5 [ V_1230 ] ) ;
V_1217 = F_4 ( V_5 [ V_1231 ] ) ;
V_47 = F_290 ( V_31 , V_173 , V_1216 , V_1217 ) ;
} else
V_47 = - V_16 ;
V_484:
return V_47 ;
}
static int F_295 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_863 V_923 ;
struct V_928 V_929 ;
int V_47 ;
memcpy ( & V_923 , & V_867 , sizeof( V_923 ) ) ;
memcpy ( & V_929 , & V_1232 , sizeof( V_929 ) ) ;
if ( V_31 -> V_5 [ V_869 ] ) {
V_47 = F_190 ( V_31 , & V_923 , NULL ) ;
if ( V_47 )
return V_47 ;
}
if ( ! V_31 -> V_5 [ V_502 ] ||
! F_30 ( V_31 -> V_5 [ V_502 ] ) )
return - V_16 ;
V_929 . V_1233 = F_29 ( V_31 -> V_5 [ V_502 ] ) ;
V_929 . V_866 = F_30 ( V_31 -> V_5 [ V_502 ] ) ;
if ( V_31 -> V_5 [ V_1136 ] &&
! F_239 ( V_7 , V_929 . V_1125 ,
F_4 ( V_31 -> V_5 [ V_1136 ] ) ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_587 ] ) {
V_929 . V_433 =
F_4 ( V_31 -> V_5 [ V_587 ] ) ;
if ( V_929 . V_433 < 10 ||
V_929 . V_433 > 10000 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_588 ] ) {
V_929 . V_590 =
F_4 ( V_31 -> V_5 [ V_588 ] ) ;
if ( V_929 . V_590 < 1 || V_929 . V_590 > 100 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_931 ] ) {
V_47 = F_192 ( V_31 , & V_929 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_417 ] ) {
V_47 = F_75 ( V_7 , V_31 , & V_929 . V_415 ) ;
if ( V_47 )
return V_47 ;
} else {
V_929 . V_415 . V_60 = NULL ;
}
return F_296 ( V_7 , V_46 , & V_929 , & V_923 ) ;
}
static int F_297 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
return F_298 ( V_7 , V_46 ) ;
}
static int F_299 ( struct V_44 * V_58 ,
struct V_6 * V_7 )
{
struct V_4 * V_1234 , * V_1235 ;
int V_138 , V_1236 ;
if ( ! V_7 -> V_351 -> V_352 )
return 0 ;
V_1234 = F_50 ( V_58 , V_379 ) ;
if ( ! V_1234 )
return - V_74 ;
for ( V_138 = 0 ; V_138 < V_7 -> V_351 -> V_352 ; V_138 ++ ) {
V_1235 = F_50 ( V_58 , V_138 + 1 ) ;
if ( ! V_1235 )
return - V_74 ;
V_1236 = V_7 -> V_351 -> V_1237 [ V_138 ] . V_1238 ;
if ( F_58 ( V_58 , V_1239 ,
F_300 ( V_1236 , 8 ) ,
V_7 -> V_351 -> V_1237 [ V_138 ] . V_621 ) ||
F_58 ( V_58 , V_1240 ,
V_1236 , V_7 -> V_351 -> V_1237 [ V_138 ] . V_1241 ) ||
F_34 ( V_58 , V_1242 ,
V_7 -> V_351 -> V_1237 [ V_138 ] . V_1243 ) )
return - V_74 ;
F_51 ( V_58 , V_1235 ) ;
}
F_51 ( V_58 , V_1234 ) ;
return 0 ;
}
static int F_301 ( struct V_44 * V_58 ,
struct V_1244 * V_1245 )
{
struct V_4 * V_1246 ;
if ( ! V_1245 )
return 0 ;
V_1246 = F_50 ( V_58 , V_1247 ) ;
if ( ! V_1246 )
return - V_74 ;
if ( F_302 ( V_58 , V_1248 , V_1245 -> V_1249 ) ||
F_302 ( V_58 , V_1250 , V_1245 -> V_791 ) ||
F_58 ( V_58 , V_1251 , V_474 , V_1245 -> V_1252 ) ||
F_57 ( V_58 , V_1253 , V_1245 -> V_1254 ) ||
F_57 ( V_58 , V_1255 , V_1245 -> V_1256 ) ||
F_58 ( V_58 , V_1257 ,
V_1245 -> V_1258 , V_1245 -> V_1259 ) ||
F_34 ( V_58 , V_1260 ,
V_1245 -> V_1261 ) ||
F_58 ( V_58 , V_1262 ,
V_1245 -> V_1263 , V_1245 -> V_1264 ) ||
F_58 ( V_58 , V_1265 ,
F_300 ( V_1245 -> V_1263 , 8 ) , V_1245 -> V_1266 ) )
return - V_74 ;
if ( V_1245 -> V_1267 . V_52 &&
F_58 ( V_58 , V_1268 ,
sizeof( V_1245 -> V_1267 ) , & V_1245 -> V_1267 ) )
return - V_74 ;
if ( V_1245 -> V_1269 . V_52 &&
F_58 ( V_58 , V_1270 ,
sizeof( V_1245 -> V_1269 ) + V_1245 -> V_1271 ,
& V_1245 -> V_1269 ) )
return - V_74 ;
return 0 ;
}
static int F_303 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_44 * V_58 ;
void * V_162 ;
V_23 V_1272 = V_485 ;
if ( ! V_7 -> V_18 . V_351 . V_56 && ! V_7 -> V_18 . V_351 . V_352 &&
! V_7 -> V_18 . V_351 . V_1245 )
return - V_432 ;
if ( V_7 -> V_351 && V_7 -> V_351 -> V_1245 ) {
V_1272 += V_7 -> V_351 -> V_1245 -> V_1271 +
V_7 -> V_351 -> V_1245 -> V_1258 +
V_7 -> V_351 -> V_1245 -> V_1263 +
V_7 -> V_351 -> V_1245 -> V_1263 / 8 ;
}
V_58 = F_69 ( V_1272 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_1273 ) ;
if ( ! V_162 )
goto V_63;
if ( V_7 -> V_351 ) {
struct V_4 * V_353 ;
V_353 = F_50 ( V_58 , V_1274 ) ;
if ( ! V_353 )
goto V_63;
if ( ( V_7 -> V_351 -> V_1275 &&
F_35 ( V_58 , V_356 ) ) ||
( V_7 -> V_351 -> V_333 &&
F_35 ( V_58 , V_358 ) ) ||
( V_7 -> V_351 -> V_1276 &&
F_35 ( V_58 , V_360 ) ) ||
( V_7 -> V_351 -> V_1277 &&
F_35 ( V_58 , V_364 ) ) ||
( V_7 -> V_351 -> V_1278 &&
F_35 ( V_58 , V_366 ) ) ||
( V_7 -> V_351 -> V_1279 &&
F_35 ( V_58 , V_368 ) ) ||
( V_7 -> V_351 -> V_1280 &&
F_35 ( V_58 , V_370 ) ) )
goto V_63;
if ( F_299 ( V_58 , V_7 ) )
goto V_63;
if ( F_301 ( V_58 , V_7 -> V_351 -> V_1245 ) )
goto V_63;
F_51 ( V_58 , V_353 ) ;
}
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
F_70 ( V_58 ) ;
return - V_74 ;
}
static int F_304 ( struct V_6 * V_7 ,
struct V_4 * V_50 ,
struct V_1281 * V_1282 )
{
struct V_4 * V_78 [ V_1283 ] ;
struct V_1244 * V_923 ;
struct V_1284 * V_1285 = NULL ;
struct V_1286 * V_55 = NULL ;
V_23 V_1272 ;
V_23 V_1287 , V_1288 , V_1271 = 0 , V_1289 ;
int V_47 , V_1290 ;
if ( ! V_7 -> V_18 . V_351 . V_1245 )
return - V_16 ;
V_47 = F_91 ( V_78 , V_1291 ,
F_29 ( V_50 ) , F_30 ( V_50 ) ,
V_1292 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_78 [ V_1248 ] ||
! V_78 [ V_1250 ] ||
! V_78 [ V_1251 ] ||
! V_78 [ V_1255 ] ||
! V_78 [ V_1257 ] ||
! V_78 [ V_1260 ] ||
! V_78 [ V_1262 ] ||
! V_78 [ V_1265 ] )
return - V_16 ;
V_1287 = F_30 ( V_78 [ V_1257 ] ) ;
if ( V_1287 > V_7 -> V_18 . V_351 . V_1245 -> V_1293 )
return - V_16 ;
if ( F_4 ( V_78 [ V_1260 ] ) >
V_7 -> V_18 . V_351 . V_1245 -> V_1294 )
return - V_16 ;
V_1288 = F_30 ( V_78 [ V_1262 ] ) ;
if ( V_1288 > V_7 -> V_18 . V_351 . V_1245 -> V_1295 )
return - V_16 ;
V_1289 = F_30 ( V_78 [ V_1265 ] ) ;
if ( V_1289 != F_300 ( V_1288 , 8 ) )
return - V_16 ;
if ( V_78 [ V_1270 ] ) {
V_23 V_1296 = F_30 ( V_78 [ V_1270 ] ) ;
V_1285 = F_29 ( V_78 [ V_1270 ] ) ;
V_1271 = V_1296 - sizeof( * V_1285 ) ;
if ( ! V_1285 -> V_52 || V_1271 % V_1285 -> V_52 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_351 . V_1245 -> V_1285 )
return - V_16 ;
if ( V_1285 -> V_52 > V_7 -> V_18 . V_351 . V_1245 -> V_1285 -> V_1297 )
return - V_16 ;
if ( V_1285 -> V_52 < V_7 -> V_18 . V_351 . V_1245 -> V_1285 -> V_1298 )
return - V_16 ;
if ( V_1271 > V_7 -> V_18 . V_351 . V_1245 -> V_1285 -> V_1299 )
return - V_16 ;
if ( V_1285 -> V_1300 + V_1285 -> V_52 > V_1287 )
return - V_16 ;
}
if ( V_78 [ V_1268 ] ) {
V_55 = F_29 ( V_78 [ V_1268 ] ) ;
if ( ! V_7 -> V_18 . V_351 . V_1245 -> V_55 )
return - V_16 ;
if ( V_55 -> V_52 == 0 || V_55 -> V_52 > 4 )
return - V_16 ;
if ( V_55 -> V_52 + V_55 -> V_1300 > V_1287 )
return - V_16 ;
}
V_1272 = sizeof( * V_923 ) ;
V_1272 += V_1287 ;
V_1272 += V_1288 + V_1289 ;
V_1272 += V_1271 ;
V_923 = F_43 ( V_1272 , V_118 ) ;
if ( ! V_923 )
return - V_119 ;
V_923 -> V_1249 = F_305 ( V_78 [ V_1248 ] ) ;
V_923 -> V_791 = F_305 ( V_78 [ V_1250 ] ) ;
memcpy ( V_923 -> V_1252 , F_29 ( V_78 [ V_1251 ] ) ,
V_474 ) ;
if ( V_78 [ V_1253 ] )
V_1290 = F_73 ( V_78 [ V_1253 ] ) ;
else
V_1290 = 0 ;
#ifdef F_306
V_47 = F_307 ( F_7 ( & V_7 -> V_18 ) , V_1301 , V_1302 ,
V_1303 , & V_923 -> V_1304 , 1 ) ;
if ( V_47 ) {
F_46 ( V_923 ) ;
return V_47 ;
}
if ( F_308 ( V_923 -> V_1304 -> V_48 , V_1290 ) ) {
F_309 ( V_923 -> V_1304 ) ;
F_46 ( V_923 ) ;
return - V_1305 ;
}
V_923 -> V_1254 = F_310 ( V_923 -> V_1304 -> V_48 ) -> V_1306 ;
#else
if ( ! V_1290 ) {
F_46 ( V_923 ) ;
return - V_16 ;
}
V_923 -> V_1254 = V_1290 ;
#endif
V_923 -> V_1256 = F_73 ( V_78 [ V_1255 ] ) ;
V_923 -> V_1258 = V_1287 ;
V_923 -> V_1259 = ( T_2 * ) V_923 + sizeof( * V_923 ) + V_1271 ;
memcpy ( ( void * ) V_923 -> V_1259 ,
F_29 ( V_78 [ V_1257 ] ) ,
V_1287 ) ;
if ( V_55 )
V_923 -> V_1267 = * V_55 ;
V_923 -> V_1261 = F_4 ( V_78 [ V_1260 ] ) ;
V_923 -> V_1263 = V_1288 ;
V_923 -> V_1264 = ( T_2 * ) V_923 + sizeof( * V_923 ) + V_1271 + V_1287 ;
memcpy ( ( void * ) V_923 -> V_1264 ,
F_29 ( V_78 [ V_1262 ] ) ,
V_1288 ) ;
V_923 -> V_1266 = ( T_2 * ) V_923 + sizeof( * V_923 ) + V_1271 +
V_1287 + V_1288 ;
memcpy ( ( void * ) V_923 -> V_1266 ,
F_29 ( V_78 [ V_1265 ] ) ,
V_1289 ) ;
if ( V_1285 ) {
V_923 -> V_1271 = V_1271 ;
memcpy ( & V_923 -> V_1269 , V_1285 , sizeof( * V_1285 ) + V_1271 ) ;
}
V_1282 -> V_1245 = V_923 ;
return 0 ;
}
static int F_311 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_4 * V_78 [ V_1307 ] ;
struct V_1281 V_1308 = {} ;
struct V_1281 * V_1309 ;
struct V_1310 * V_351 = & V_7 -> V_18 . V_351 ;
int V_47 , V_138 ;
bool V_1311 = V_7 -> V_351 ;
if ( ! V_7 -> V_18 . V_351 . V_56 && ! V_7 -> V_18 . V_351 . V_352 &&
! V_7 -> V_18 . V_351 . V_1245 )
return - V_432 ;
if ( ! V_31 -> V_5 [ V_1274 ] ) {
F_312 ( V_7 ) ;
V_7 -> V_351 = NULL ;
goto V_1312;
}
V_47 = F_91 ( V_78 , V_1313 ,
F_29 ( V_31 -> V_5 [ V_1274 ] ) ,
F_30 ( V_31 -> V_5 [ V_1274 ] ) ,
V_1314 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_356 ] ) {
if ( ! ( V_351 -> V_56 & V_355 ) )
return - V_16 ;
V_1308 . V_1275 = true ;
}
if ( V_78 [ V_358 ] ) {
if ( ! ( V_351 -> V_56 & V_357 ) )
return - V_16 ;
V_1308 . V_333 = true ;
}
if ( V_78 [ V_360 ] ) {
if ( ! ( V_351 -> V_56 & V_359 ) )
return - V_16 ;
V_1308 . V_1276 = true ;
}
if ( V_78 [ V_362 ] )
return - V_16 ;
if ( V_78 [ V_364 ] ) {
if ( ! ( V_351 -> V_56 & V_363 ) )
return - V_16 ;
V_1308 . V_1277 = true ;
}
if ( V_78 [ V_366 ] ) {
if ( ! ( V_351 -> V_56 & V_365 ) )
return - V_16 ;
V_1308 . V_1278 = true ;
}
if ( V_78 [ V_368 ] ) {
if ( ! ( V_351 -> V_56 & V_367 ) )
return - V_16 ;
V_1308 . V_1279 = true ;
}
if ( V_78 [ V_370 ] ) {
if ( ! ( V_351 -> V_56 & V_369 ) )
return - V_16 ;
V_1308 . V_1280 = true ;
}
if ( V_78 [ V_379 ] ) {
struct V_4 * V_372 ;
int V_352 = 0 ;
int V_117 , V_1236 , V_1315 , V_1243 ;
struct V_4 * V_1316 [ V_1317 ] ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_352 ++ ;
if ( V_352 > V_351 -> V_352 )
return - V_16 ;
V_1308 . V_1237 = F_313 ( V_352 ,
sizeof( V_1308 . V_1237 [ 0 ] ) ,
V_118 ) ;
if ( ! V_1308 . V_1237 )
return - V_119 ;
V_1308 . V_352 = V_352 ;
V_138 = 0 ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_91 ( V_1316 , V_1318 ,
F_29 ( V_372 ) , F_30 ( V_372 ) , NULL ) ;
V_47 = - V_16 ;
if ( ! V_1316 [ V_1239 ] ||
! V_1316 [ V_1240 ] )
goto error;
V_1236 = F_30 ( V_1316 [ V_1240 ] ) ;
V_1315 = F_300 ( V_1236 , 8 ) ;
if ( F_30 ( V_1316 [ V_1239 ] ) !=
V_1315 )
goto error;
if ( V_1236 > V_351 -> V_377 ||
V_1236 < V_351 -> V_375 )
goto error;
if ( ! V_1316 [ V_1242 ] )
V_1243 = 0 ;
else
V_1243 = F_4 (
V_1316 [ V_1242 ] ) ;
if ( V_1243 > V_351 -> V_378 )
goto error;
V_1308 . V_1237 [ V_138 ] . V_1243 = V_1243 ;
V_1308 . V_1237 [ V_138 ] . V_621 =
F_314 ( V_1315 + V_1236 , V_118 ) ;
if ( ! V_1308 . V_1237 [ V_138 ] . V_621 ) {
V_47 = - V_119 ;
goto error;
}
V_1308 . V_1237 [ V_138 ] . V_1241 =
V_1308 . V_1237 [ V_138 ] . V_621 + V_1315 ;
memcpy ( V_1308 . V_1237 [ V_138 ] . V_621 ,
F_29 ( V_1316 [ V_1239 ] ) ,
V_1315 ) ;
V_1308 . V_1237 [ V_138 ] . V_1238 = V_1236 ;
memcpy ( V_1308 . V_1237 [ V_138 ] . V_1241 ,
F_29 ( V_1316 [ V_1240 ] ) ,
V_1236 ) ;
V_138 ++ ;
}
}
if ( V_78 [ V_1247 ] ) {
V_47 = F_304 (
V_7 , V_78 [ V_1247 ] ,
& V_1308 ) ;
if ( V_47 )
goto error;
}
V_1309 = F_315 ( & V_1308 , sizeof( V_1308 ) , V_118 ) ;
if ( ! V_1309 ) {
V_47 = - V_119 ;
goto error;
}
F_312 ( V_7 ) ;
V_7 -> V_351 = V_1309 ;
V_1312:
if ( V_7 -> V_226 -> V_1312 && V_1311 != ! ! V_7 -> V_351 )
F_316 ( V_7 , V_7 -> V_351 ) ;
return 0 ;
error:
for ( V_138 = 0 ; V_138 < V_1308 . V_352 ; V_138 ++ )
F_46 ( V_1308 . V_1237 [ V_138 ] . V_621 ) ;
F_46 ( V_1308 . V_1237 ) ;
if ( V_1308 . V_1245 && V_1308 . V_1245 -> V_1304 )
F_309 ( V_1308 . V_1245 -> V_1304 ) ;
F_46 ( V_1308 . V_1245 ) ;
return V_47 ;
}
static int F_317 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_4 * V_78 [ V_1319 ] ;
struct V_1320 V_1321 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1322 ] )
return - V_16 ;
V_47 = F_91 ( V_78 , V_1323 ,
F_29 ( V_31 -> V_5 [ V_1322 ] ) ,
F_30 ( V_31 -> V_5 [ V_1322 ] ) ,
V_1324 ) ;
if ( V_47 )
return V_47 ;
if ( F_30 ( V_78 [ V_1325 ] ) != V_1326 )
return - V_1327 ;
if ( F_30 ( V_78 [ V_1328 ] ) != V_1329 )
return - V_1327 ;
if ( F_30 ( V_78 [ V_1330 ] ) != V_1331 )
return - V_1327 ;
memcpy ( V_1321 . V_1332 , F_29 ( V_78 [ V_1328 ] ) ,
V_1329 ) ;
memcpy ( V_1321 . V_1333 , F_29 ( V_78 [ V_1330 ] ) ,
V_1331 ) ;
memcpy ( V_1321 . V_1334 ,
F_29 ( V_78 [ V_1325 ] ) ,
V_1326 ) ;
F_108 ( V_17 ) ;
if ( ! V_17 -> V_130 ) {
V_47 = - V_1335 ;
goto V_484;
}
if ( ! V_7 -> V_226 -> V_1336 ) {
V_47 = - V_432 ;
goto V_484;
}
V_47 = F_318 ( V_7 , V_46 , & V_1321 ) ;
V_484:
F_110 ( V_17 ) ;
return V_47 ;
}
static int F_319 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_17 -> V_124 != V_125 &&
V_17 -> V_124 != V_127 )
return - V_16 ;
if ( V_17 -> V_1337 )
return - V_434 ;
V_17 -> V_1337 = V_31 -> V_398 ;
return 0 ;
}
static int F_320 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_397 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_44 * V_58 ;
void * V_162 ;
const T_2 * V_553 ;
T_1 V_523 ;
int V_47 ;
if ( V_17 -> V_124 != V_125 &&
V_17 -> V_124 != V_127 )
return - V_432 ;
if ( ! V_31 -> V_5 [ V_437 ] )
return - V_16 ;
if ( ! V_7 -> V_226 -> V_319 )
return - V_432 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , V_31 -> V_398 , V_31 -> V_399 , 0 ,
V_1338 ) ;
if ( F_16 ( V_162 ) ) {
V_47 = F_24 ( V_162 ) ;
goto V_533;
}
V_553 = F_29 ( V_31 -> V_5 [ V_437 ] ) ;
V_47 = F_321 ( V_7 , V_46 , V_553 , & V_523 ) ;
if ( V_47 )
goto V_533;
if ( F_100 ( V_58 , V_1179 , V_523 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_71 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_533:
F_70 ( V_58 ) ;
return V_47 ;
}
static int F_322 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1339 * V_1340 , * V_1341 ;
int V_1342 ;
if ( ! ( V_7 -> V_18 . V_56 & V_323 ) )
return - V_432 ;
V_1341 = F_43 ( sizeof( * V_1341 ) , V_118 ) ;
if ( ! V_1341 )
return - V_119 ;
F_222 ( & V_7 -> V_1343 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1340 -> V_1344 == V_31 -> V_398 ) {
V_1342 = - V_586 ;
goto V_744;
}
}
V_1341 -> V_1344 = V_31 -> V_398 ;
F_323 ( & V_1341 -> V_516 , & V_7 -> V_1345 ) ;
F_224 ( & V_7 -> V_1343 ) ;
return 0 ;
V_744:
F_224 ( & V_7 -> V_1343 ) ;
F_46 ( V_1341 ) ;
return V_1342 ;
}
static int F_324 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
int V_47 ;
if ( ! V_7 -> V_226 -> V_325 )
return - V_432 ;
if ( V_17 -> V_124 != V_509 )
return - V_432 ;
if ( V_17 -> V_1346 )
return 0 ;
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_325 ( V_7 , V_17 -> V_124 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_326 ( V_7 , V_17 ) ;
if ( V_47 )
return V_47 ;
V_17 -> V_1346 = true ;
F_8 ( & V_7 -> V_19 ) ;
V_7 -> V_1347 ++ ;
F_9 ( & V_7 -> V_19 ) ;
return 0 ;
}
static int F_327 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_397 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
if ( V_17 -> V_124 != V_509 )
return - V_432 ;
if ( ! V_7 -> V_226 -> V_1348 )
return - V_432 ;
F_8 ( & V_7 -> V_984 ) ;
F_328 ( V_7 , V_17 ) ;
F_9 ( & V_7 -> V_984 ) ;
return 0 ;
}
static int F_329 ( struct V_1349 * V_226 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_26 * V_46 ;
bool V_1350 = V_226 -> V_1351 & V_1352 ;
if ( V_1350 )
F_20 () ;
if ( V_226 -> V_1351 & V_1353 ) {
V_7 = F_15 ( F_89 ( V_31 ) , V_31 ) ;
if ( F_16 ( V_7 ) ) {
if ( V_1350 )
F_25 () ;
return F_24 ( V_7 ) ;
}
V_31 -> V_397 [ 0 ] = V_7 ;
} else if ( V_226 -> V_1351 & V_1354 ||
V_226 -> V_1351 & V_1355 ) {
F_8 ( & V_32 ) ;
V_17 = F_1 ( F_89 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_17 ) ) {
F_9 ( & V_32 ) ;
if ( V_1350 )
F_25 () ;
return F_24 ( V_17 ) ;
}
V_46 = V_17 -> V_20 ;
V_7 = F_13 ( V_17 -> V_18 ) ;
if ( V_226 -> V_1351 & V_1354 ) {
if ( ! V_46 ) {
F_9 ( & V_32 ) ;
if ( V_1350 )
F_25 () ;
return - V_16 ;
}
V_31 -> V_397 [ 1 ] = V_46 ;
} else {
V_31 -> V_397 [ 1 ] = V_17 ;
}
if ( V_46 ) {
if ( V_226 -> V_1351 & V_1356 &&
! F_86 ( V_46 ) ) {
F_9 ( & V_32 ) ;
if ( V_1350 )
F_25 () ;
return - V_446 ;
}
F_210 ( V_46 ) ;
} else if ( V_226 -> V_1351 & V_1356 ) {
if ( ! V_17 -> V_1346 ) {
F_9 ( & V_32 ) ;
if ( V_1350 )
F_25 () ;
return - V_446 ;
}
}
F_248 ( V_7 ) ;
F_9 ( & V_32 ) ;
V_31 -> V_397 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_330 ( struct V_1349 * V_226 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
if ( V_31 -> V_397 [ 0 ] )
F_27 ( V_31 -> V_397 [ 0 ] ) ;
if ( V_31 -> V_397 [ 1 ] ) {
if ( V_226 -> V_1351 & V_1355 ) {
struct V_1 * V_17 = V_31 -> V_397 [ 1 ] ;
if ( V_17 -> V_20 )
F_14 ( V_17 -> V_20 ) ;
} else {
F_14 ( V_31 -> V_397 [ 1 ] ) ;
}
}
if ( V_226 -> V_1351 & V_1352 )
F_25 () ;
}
void F_331 ( struct V_6 * V_7 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_53 ( V_58 , 0 , 0 , 0 , V_7 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1357 . V_1150 , V_118 ) ;
}
static int F_333 ( struct V_44 * V_58 ,
struct V_6 * V_7 )
{
struct V_980 * V_1358 = V_7 -> V_985 ;
struct V_4 * V_1359 ;
int V_138 ;
F_334 ( & V_7 -> V_984 ) ;
if ( F_97 ( ! V_1358 ) )
return 0 ;
V_1359 = F_50 ( V_58 , V_988 ) ;
if ( ! V_1359 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_1358 -> V_982 ; V_138 ++ ) {
if ( F_58 ( V_58 , V_138 , V_1358 -> V_989 [ V_138 ] . V_477 , V_1358 -> V_989 [ V_138 ] . V_479 ) )
goto V_63;
}
F_51 ( V_58 , V_1359 ) ;
V_1359 = F_50 ( V_58 , V_987 ) ;
if ( ! V_1359 )
goto V_63;
for ( V_138 = 0 ; V_138 < V_1358 -> V_253 ; V_138 ++ ) {
if ( F_34 ( V_58 , V_138 , V_1358 -> V_254 [ V_138 ] -> V_62 ) )
goto V_63;
}
F_51 ( V_58 , V_1359 ) ;
if ( V_1358 -> V_947 &&
F_58 ( V_58 , V_559 , V_1358 -> V_948 , V_1358 -> V_947 ) )
goto V_63;
if ( V_1358 -> V_56 )
F_34 ( V_58 , V_993 , V_1358 -> V_56 ) ;
return 0 ;
V_63:
return - V_74 ;
}
static int F_335 ( struct V_44 * V_58 ,
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
F_333 ( V_58 , V_7 ) ;
return F_63 ( V_58 , V_162 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
return - V_391 ;
}
static int
F_336 ( struct V_44 * V_58 ,
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
return - V_391 ;
}
void F_209 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_335 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1360 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1361 . V_1150 , V_118 ) ;
}
void F_337 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_335 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1032 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1361 . V_1150 , V_118 ) ;
}
void F_338 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_335 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1362 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1361 . V_1150 , V_118 ) ;
}
void F_339 ( struct V_6 * V_7 ,
struct V_26 * V_20 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_336 ( V_58 , V_7 , V_20 , 0 , 0 , 0 ,
V_1363 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1361 . V_1150 , V_118 ) ;
}
void F_213 ( struct V_6 * V_7 ,
struct V_26 * V_20 , V_23 V_57 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
if ( F_336 ( V_58 , V_7 , V_20 , 0 , 0 , 0 , V_57 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1361 . V_1150 , V_118 ) ;
}
void F_340 ( struct V_1364 * V_981 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1365 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_56 ( V_58 , V_1366 , V_981 -> V_1367 ) )
goto V_63;
if ( V_981 -> V_958 [ 0 ] == '0' && V_981 -> V_958 [ 1 ] == '0' ) {
if ( F_56 ( V_58 , V_1368 ,
V_1369 ) )
goto V_63;
} else if ( V_981 -> V_958 [ 0 ] == '9' && V_981 -> V_958 [ 1 ] == '9' ) {
if ( F_56 ( V_58 , V_1368 ,
V_1370 ) )
goto V_63;
} else if ( ( V_981 -> V_958 [ 0 ] == '9' && V_981 -> V_958 [ 1 ] == '8' ) ||
V_981 -> V_1371 ) {
if ( F_56 ( V_58 , V_1368 ,
V_1372 ) )
goto V_63;
} else {
if ( F_56 ( V_58 , V_1368 ,
V_1373 ) ||
F_54 ( V_58 , V_859 ,
V_981 -> V_958 ) )
goto V_63;
}
if ( V_981 -> V_14 != V_1374 &&
F_34 ( V_58 , V_27 , V_981 -> V_14 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_198 () ;
F_341 ( V_58 , 0 , V_1375 . V_1150 ,
V_1376 ) ;
F_200 () ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static void F_342 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1377 , T_9 V_52 ,
enum V_579 V_57 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_1204 , V_52 , V_1377 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_343 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1377 ,
T_9 V_52 , T_10 V_1148 )
{
F_342 ( V_7 , V_20 , V_1377 , V_52 ,
V_581 , V_1148 ) ;
}
void F_344 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1377 ,
T_9 V_52 , T_10 V_1148 )
{
F_342 ( V_7 , V_20 , V_1377 , V_52 ,
V_1379 , V_1148 ) ;
}
void F_345 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1377 ,
T_9 V_52 , T_10 V_1148 )
{
F_342 ( V_7 , V_20 , V_1377 , V_52 ,
V_1380 , V_1148 ) ;
}
void F_346 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1377 ,
T_9 V_52 , T_10 V_1148 )
{
F_342 ( V_7 , V_20 , V_1377 , V_52 ,
V_1381 , V_1148 ) ;
}
void F_347 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1377 ,
T_9 V_52 , T_10 V_1148 )
{
F_342 ( V_7 , V_20 , V_1377 , V_52 ,
V_1382 , V_1148 ) ;
}
void F_348 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1377 ,
T_9 V_52 , T_10 V_1148 )
{
F_342 ( V_7 , V_20 , V_1377 , V_52 ,
V_1383 , V_1148 ) ;
}
static void F_349 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_57 ,
const T_2 * V_553 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_35 ( V_58 , V_1384 ) ||
F_58 ( V_58 , V_437 , V_474 , V_553 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_350 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_553 ,
T_10 V_1148 )
{
F_349 ( V_7 , V_20 , V_581 ,
V_553 , V_1148 ) ;
}
void F_351 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_553 ,
T_10 V_1148 )
{
F_349 ( V_7 , V_20 , V_1379 ,
V_553 , V_1148 ) ;
}
void F_352 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_436 ,
const T_2 * V_1385 , T_9 V_1386 ,
const T_2 * V_1387 , T_9 V_1388 ,
T_3 V_1389 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_332 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_436 && F_58 ( V_58 , V_437 , V_474 , V_436 ) ) ||
F_57 ( V_58 , V_1170 , V_1389 ) ||
( V_1385 &&
F_58 ( V_58 , V_1390 , V_1386 , V_1385 ) ) ||
( V_1387 &&
F_58 ( V_58 , V_1391 , V_1388 , V_1387 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_353 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_436 ,
const T_2 * V_1385 , T_9 V_1386 ,
const T_2 * V_1387 , T_9 V_1388 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1392 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_436 ) ||
( V_1385 &&
F_58 ( V_58 , V_1390 , V_1386 , V_1385 ) ) ||
( V_1387 &&
F_58 ( V_58 , V_1391 , V_1388 , V_1387 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_354 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_3 V_1154 ,
const T_2 * V_947 , T_9 V_948 , bool V_1393 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_118 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_334 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_1393 && V_1154 &&
F_57 ( V_58 , V_1124 , V_1154 ) ) ||
( V_1393 &&
F_35 ( V_58 , V_1394 ) ) ||
( V_947 && F_58 ( V_58 , V_559 , V_948 , V_947 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_118 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_355 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_436 ,
T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1395 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_436 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_356 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_510 , const T_2 * V_947 , T_2 V_948 ,
T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1396 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_510 ) ||
( V_948 && V_947 &&
F_58 ( V_58 , V_559 , V_948 , V_947 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_357 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_553 ,
enum V_1397 V_1398 , int V_1399 ,
const T_2 * V_1400 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1401 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_553 && F_58 ( V_58 , V_437 , V_474 , V_553 ) ) ||
F_34 ( V_58 , V_110 , V_1398 ) ||
( V_1399 != - 1 &&
F_56 ( V_58 , V_106 , V_1399 ) ) ||
( V_1400 && F_58 ( V_58 , V_105 , 6 , V_1400 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_358 ( struct V_18 * V_18 ,
struct V_59 * V_1402 ,
struct V_59 * V_1403 )
{
struct V_44 * V_58 ;
void * V_162 ;
struct V_4 * V_166 ;
V_58 = F_69 ( V_485 , V_1376 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1404 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , F_359 ( V_18 ) ) )
goto V_63;
V_166 = F_50 ( V_58 , V_1405 ) ;
if ( ! V_166 )
goto V_63;
if ( F_33 ( V_58 , V_1402 ) )
goto V_63;
F_51 ( V_58 , V_166 ) ;
V_166 = F_50 ( V_58 , V_1406 ) ;
if ( ! V_166 )
goto V_63;
if ( F_33 ( V_58 , V_1403 ) )
goto V_63;
F_51 ( V_58 , V_166 ) ;
F_63 ( V_58 , V_162 ) ;
F_198 () ;
F_341 ( V_58 , 0 , V_1375 . V_1150 ,
V_1376 ) ;
F_200 () ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static void F_360 (
int V_57 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_523 ,
struct V_59 * V_60 ,
unsigned int V_1175 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
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
F_34 ( V_58 , V_417 , V_60 -> V_62 ) ||
F_34 ( V_58 , V_422 ,
V_425 ) ||
F_100 ( V_58 , V_1179 , V_523 ) )
goto V_63;
if ( V_57 == V_1178 &&
F_34 ( V_58 , V_1176 , V_1175 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_361 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_523 ,
struct V_59 * V_60 ,
unsigned int V_1175 , T_10 V_1148 )
{
F_360 ( V_1178 ,
V_7 , V_17 , V_523 , V_60 ,
V_1175 , V_1148 ) ;
}
void F_362 (
struct V_6 * V_7 ,
struct V_1 * V_17 ,
T_1 V_523 , struct V_59 * V_60 , T_10 V_1148 )
{
F_360 ( V_1407 ,
V_7 , V_17 , V_523 , V_60 , 0 , V_1148 ) ;
}
void F_363 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_525 ,
struct V_654 * V_655 , T_10 V_1148 )
{
struct V_44 * V_58 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
if ( F_156 ( V_58 , 0 , 0 , 0 ,
V_7 , V_46 , V_525 , V_655 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
}
void F_364 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_525 ,
T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1408 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_525 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_365 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_525 ,
enum V_1409 V_1154 ,
T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_1410 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1411 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_525 ) ||
F_34 ( V_58 , V_1412 , V_1154 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static bool F_366 ( struct V_26 * V_46 , T_2 V_57 ,
const T_2 * V_553 , T_10 V_1148 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
V_23 V_1344 = F_367 ( V_17 -> V_1337 ) ;
if ( ! V_1344 )
return false ;
V_58 = F_69 ( 100 , V_1148 ) ;
if ( ! V_58 )
return true ;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return true ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_553 ) )
goto V_63;
V_47 = F_63 ( V_58 , V_162 ) ;
if ( V_47 < 0 ) {
F_70 ( V_58 ) ;
return true ;
}
F_368 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1344 ) ;
return true ;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
return true ;
}
bool F_369 ( struct V_26 * V_46 , const T_2 * V_553 , T_10 V_1148 )
{
return F_366 ( V_46 , V_1413 ,
V_553 , V_1148 ) ;
}
bool F_370 ( struct V_26 * V_46 ,
const T_2 * V_553 , T_10 V_1148 )
{
return F_366 ( V_46 ,
V_1414 ,
V_553 , V_1148 ) ;
}
int F_371 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_23 V_1344 ,
int V_1415 , int V_1416 ,
const T_2 * V_1377 , T_9 V_52 , T_10 V_1148 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return - V_119 ;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1205 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return - V_119 ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_34 ( V_58 , V_417 , V_1415 ) ||
( V_1416 &&
F_34 ( V_58 , V_1417 , V_1416 ) ) ||
F_58 ( V_58 , V_1204 , V_52 , V_1377 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
return F_368 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1344 ) ;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
return - V_74 ;
}
void F_372 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_523 ,
const T_2 * V_1377 , T_9 V_52 , bool V_1418 ,
T_10 V_1148 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1419 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_58 ( V_58 , V_1204 , V_52 , V_1377 ) ||
F_100 ( V_58 , V_1179 , V_523 ) ||
( V_1418 && F_35 ( V_58 , V_1420 ) ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_256 ( V_58 , 0 , V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void
F_373 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
enum V_1421 V_1422 ,
T_10 V_1148 )
{
struct V_44 * V_58 ;
struct V_4 * V_795 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1423 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_795 = F_50 ( V_58 , V_1225 ) ;
if ( ! V_795 )
goto V_63;
if ( F_34 ( V_58 , V_1424 ,
V_1422 ) )
goto V_63;
F_51 ( V_58 , V_795 ) ;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_374 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_436 ,
const T_2 * V_1334 , T_10 V_1148 )
{
struct V_44 * V_58 ;
struct V_4 * V_1425 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1426 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_436 ) )
goto V_63;
V_1425 = F_50 ( V_58 , V_1322 ) ;
if ( ! V_1425 )
goto V_63;
if ( F_58 ( V_58 , V_1325 ,
V_1326 , V_1334 ) )
goto V_63;
F_51 ( V_58 , V_1425 ) ;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_375 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_1427 ,
const T_2 * V_436 , bool V_1428 , T_10 V_1148 )
{
struct V_44 * V_58 ;
struct V_4 * V_50 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1429 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_50 = F_50 ( V_58 , V_1430 ) ;
if ( ! V_50 )
goto V_63;
if ( F_34 ( V_58 , V_1431 , V_1427 ) ||
F_58 ( V_58 , V_1432 , V_474 , V_436 ) ||
( V_1428 &&
F_35 ( V_58 , V_1433 ) ) )
goto V_63;
F_51 ( V_58 , V_50 ) ;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_376 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
struct V_414 * V_415 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1434 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
if ( F_96 ( V_58 , V_415 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void
F_377 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1168 ,
V_23 V_1435 , V_23 V_173 , V_23 V_1217 , T_10 V_1148 )
{
struct V_44 * V_58 ;
struct V_4 * V_795 ;
void * V_162 ;
V_58 = F_69 ( V_1410 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1423 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_1168 ) )
goto V_63;
V_795 = F_50 ( V_58 , V_1225 ) ;
if ( ! V_795 )
goto V_63;
if ( F_34 ( V_58 , V_1230 , V_1435 ) )
goto V_63;
if ( F_34 ( V_58 , V_1229 , V_173 ) )
goto V_63;
if ( F_34 ( V_58 , V_1231 , V_1217 ) )
goto V_63;
F_51 ( V_58 , V_795 ) ;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void
F_378 ( struct V_6 * V_7 ,
struct V_414 * V_415 ,
enum V_1436 V_1437 ,
struct V_26 * V_20 , T_10 V_1148 )
{
struct V_44 * V_58 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1438 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) )
goto V_63;
if ( V_20 ) {
struct V_1 * V_17 = V_20 -> V_29 ;
if ( F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_100 ( V_58 , V_12 , V_13 ( V_17 ) ) )
goto V_63;
}
if ( F_34 ( V_58 , V_1439 , V_1437 ) )
goto V_63;
if ( F_96 ( V_58 , V_415 ) )
goto V_63;
if ( F_63 ( V_58 , V_162 ) < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void
F_379 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1168 ,
V_23 V_1435 , T_10 V_1148 )
{
struct V_44 * V_58 ;
struct V_4 * V_795 ;
void * V_162 ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1423 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_1168 ) )
goto V_63;
V_795 = F_50 ( V_58 , V_1225 ) ;
if ( ! V_795 )
goto V_63;
if ( F_34 ( V_58 , V_1440 , V_1435 ) )
goto V_63;
F_51 ( V_58 , V_795 ) ;
F_63 ( V_58 , V_162 ) ;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_380 ( struct V_26 * V_46 , const T_2 * V_553 ,
T_1 V_523 , bool V_1441 , T_10 V_1148 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
F_381 ( V_46 , V_553 , V_523 , V_1441 ) ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1338 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_437 , V_474 , V_553 ) ||
F_100 ( V_58 , V_1179 , V_523 ) ||
( V_1441 && F_35 ( V_58 , V_1420 ) ) )
goto V_63;
V_47 = F_63 ( V_58 , V_162 ) ;
if ( V_47 < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_382 ( struct V_18 * V_18 ,
const T_2 * V_1442 , T_9 V_52 ,
int V_1415 , int V_1416 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
struct V_1339 * V_1340 ;
F_383 ( V_18 , V_1442 , V_52 , V_1415 , V_1416 ) ;
F_222 ( & V_7 -> V_1343 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_58 = F_69 ( V_52 + 100 , V_1376 ) ;
if ( ! V_58 ) {
F_224 ( & V_7 -> V_1343 ) ;
return;
}
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1205 ) ;
if ( ! V_162 )
goto V_63;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_1415 &&
F_34 ( V_58 , V_417 , V_1415 ) ) ||
( V_1416 &&
F_34 ( V_58 , V_1417 , V_1416 ) ) ||
F_58 ( V_58 , V_1204 , V_52 , V_1442 ) )
goto V_63;
F_63 ( V_58 , V_162 ) ;
F_368 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1340 -> V_1344 ) ;
}
F_224 ( & V_7 -> V_1343 ) ;
return;
V_63:
F_224 ( & V_7 -> V_1343 ) ;
if ( V_162 )
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
void F_384 ( struct V_1 * V_17 ,
struct V_1443 * V_1444 ,
T_10 V_1148 )
{
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 , V_1272 = 200 ;
F_385 ( V_17 -> V_18 , V_17 , V_1444 ) ;
if ( V_1444 )
V_1272 += V_1444 -> V_1445 ;
V_58 = F_69 ( V_1272 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1446 ) ;
if ( ! V_162 )
goto V_533;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_100 ( V_58 , V_12 , V_13 ( V_17 ) ) )
goto V_533;
if ( V_17 -> V_20 && F_34 ( V_58 , V_10 ,
V_17 -> V_20 -> V_21 ) )
goto V_533;
if ( V_1444 ) {
struct V_4 * V_1447 ;
V_1447 = F_50 ( V_58 , V_1274 ) ;
if ( V_1444 -> V_333 &&
F_35 ( V_58 , V_358 ) )
goto V_533;
if ( V_1444 -> V_1276 &&
F_35 ( V_58 , V_360 ) )
goto V_533;
if ( V_1444 -> V_1277 &&
F_35 ( V_58 , V_364 ) )
goto V_533;
if ( V_1444 -> V_1278 &&
F_35 ( V_58 , V_366 ) )
goto V_533;
if ( V_1444 -> V_1279 &&
F_35 ( V_58 , V_368 ) )
goto V_533;
if ( V_1444 -> V_1280 &&
F_35 ( V_58 , V_370 ) )
goto V_533;
if ( V_1444 -> V_1448 >= 0 &&
F_34 ( V_58 , V_379 ,
V_1444 -> V_1448 ) )
goto V_533;
if ( V_1444 -> V_1449 )
F_35 ( V_58 , V_1450 ) ;
if ( V_1444 -> V_1451 )
F_35 ( V_58 ,
V_1452 ) ;
if ( V_1444 -> V_1453 )
F_35 ( V_58 ,
V_1454 ) ;
if ( V_1444 -> V_1455 ) {
V_23 V_1456 = V_1457 ;
V_23 V_1458 = V_1459 ;
if ( ! V_1444 -> V_1460 ) {
V_1456 =
V_1461 ;
V_1458 =
V_1462 ;
}
if ( V_1444 -> V_1463 &&
F_34 ( V_58 , V_1458 , V_1444 -> V_1463 ) )
goto V_533;
if ( F_58 ( V_58 , V_1456 , V_1444 -> V_1445 ,
V_1444 -> V_1455 ) )
goto V_533;
}
F_51 ( V_58 , V_1447 ) ;
}
V_47 = F_63 ( V_58 , V_162 ) ;
if ( V_47 < 0 )
goto V_533;
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_533:
F_70 ( V_58 ) ;
}
void F_386 ( struct V_26 * V_46 , const T_2 * V_1168 ,
enum V_1172 V_1464 ,
T_3 V_1123 , T_10 V_1148 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_162 ;
int V_47 ;
F_387 ( V_17 -> V_18 , V_46 , V_1168 , V_1464 ,
V_1123 ) ;
V_58 = F_69 ( V_485 , V_1148 ) ;
if ( ! V_58 )
return;
V_162 = F_31 ( V_58 , 0 , 0 , 0 , V_1465 ) ;
if ( ! V_162 ) {
F_70 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_56 ( V_58 , V_1174 , V_1464 ) ||
F_58 ( V_58 , V_437 , V_474 , V_1168 ) ||
( V_1123 > 0 &&
F_57 ( V_58 , V_1124 , V_1123 ) ) )
goto V_63;
V_47 = F_63 ( V_58 , V_162 ) ;
if ( V_47 < 0 ) {
F_70 ( V_58 ) ;
return;
}
F_332 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1378 . V_1150 , V_1148 ) ;
return;
V_63:
F_64 ( V_58 , V_162 ) ;
F_70 ( V_58 ) ;
}
static int F_388 ( struct V_1466 * V_1467 ,
unsigned long V_1207 ,
void * V_1468 )
{
struct V_1469 * V_1470 = V_1468 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1339 * V_1340 , * V_25 ;
if ( V_1207 != V_1471 )
return V_1472 ;
F_198 () ;
F_389 (rdev, &cfg80211_rdev_list, list) {
F_389 (wdev, &rdev->wdev_list, list)
F_390 ( V_17 , V_1470 -> V_54 ) ;
F_222 ( & V_7 -> V_1343 ) ;
F_391 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1340 -> V_1344 == V_1470 -> V_54 ) {
F_392 ( & V_1340 -> V_516 ) ;
F_46 ( V_1340 ) ;
break;
}
}
F_224 ( & V_7 -> V_1343 ) ;
}
F_200 () ;
return V_1472 ;
}
int F_393 ( void )
{
int V_47 ;
V_47 = F_394 ( & V_39 ,
V_1473 , F_395 ( V_1473 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_396 ( & V_39 , & V_1357 ) ;
if ( V_47 )
goto V_1474;
V_47 = F_396 ( & V_39 , & V_1361 ) ;
if ( V_47 )
goto V_1474;
V_47 = F_396 ( & V_39 , & V_1375 ) ;
if ( V_47 )
goto V_1474;
V_47 = F_396 ( & V_39 , & V_1378 ) ;
if ( V_47 )
goto V_1474;
#ifdef F_61
V_47 = F_396 ( & V_39 , & V_1149 ) ;
if ( V_47 )
goto V_1474;
#endif
V_47 = F_397 ( & V_1475 ) ;
if ( V_47 )
goto V_1474;
return 0 ;
V_1474:
F_398 ( & V_39 ) ;
return V_47 ;
}
void F_399 ( void )
{
F_400 ( & V_1475 ) ;
F_398 ( & V_39 ) ;
}
