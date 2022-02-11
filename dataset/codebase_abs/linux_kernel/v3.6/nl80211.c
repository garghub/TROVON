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
struct V_4 * V_114 )
{
struct V_76 V_115 ;
struct V_4 * V_75 ;
struct V_113 * V_8 ;
int V_116 , V_47 , V_81 = 0 ;
V_8 = F_43 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return F_3 ( - V_118 ) ;
V_8 -> V_81 = - 1 ;
V_8 -> V_83 = - 1 ;
F_44 (key, keys, rem) {
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_88 = - 1 ;
V_47 = F_37 ( V_75 , & V_115 ) ;
if ( V_47 )
goto error;
V_47 = - V_16 ;
if ( ! V_115 . V_90 . V_75 )
goto error;
if ( V_115 . V_88 < 0 || V_115 . V_88 > 4 )
goto error;
if ( V_115 . V_81 ) {
if ( V_81 )
goto error;
V_81 = 1 ;
V_8 -> V_81 = V_115 . V_88 ;
if ( ! V_115 . V_85 || ! V_115 . V_86 )
goto error;
} else if ( V_115 . V_83 )
goto error;
V_47 = F_45 ( V_7 , & V_115 . V_90 ,
V_115 . V_88 , false , NULL ) ;
if ( V_47 )
goto error;
V_8 -> V_119 [ V_115 . V_88 ] . V_95 = V_115 . V_90 . V_95 ;
V_8 -> V_119 [ V_115 . V_88 ] . V_91 = V_115 . V_90 . V_91 ;
V_8 -> V_119 [ V_115 . V_88 ] . V_75 = V_8 -> V_120 [ V_115 . V_88 ] ;
memcpy ( V_8 -> V_120 [ V_115 . V_88 ] , V_115 . V_90 . V_75 , V_115 . V_90 . V_91 ) ;
}
return V_8 ;
error:
F_46 ( V_8 ) ;
return F_3 ( V_47 ) ;
}
static int F_47 ( struct V_1 * V_17 )
{
F_48 ( V_17 ) ;
switch ( V_17 -> V_121 ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
break;
case V_126 :
if ( ! V_17 -> V_127 )
return - V_128 ;
break;
case V_129 :
case V_130 :
if ( V_17 -> V_131 != V_132 )
return - V_128 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_49 ( struct V_44 * V_58 , V_23 V_50 , T_3 V_133 )
{
struct V_4 * V_134 = F_50 ( V_58 , V_50 ) ;
int V_135 ;
if ( ! V_134 )
goto V_63;
V_135 = 0 ;
while ( V_133 ) {
if ( ( V_133 & 1 ) && F_35 ( V_58 , V_135 ) )
goto V_63;
V_133 >>= 1 ;
V_135 ++ ;
}
F_51 ( V_58 , V_134 ) ;
return 0 ;
V_63:
return - V_74 ;
}
static int F_52 ( struct V_18 * V_18 ,
struct V_44 * V_58 )
{
struct V_4 * V_136 ;
int V_135 , V_137 ;
V_136 = F_50 ( V_58 ,
V_138 ) ;
if ( ! V_136 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_18 -> V_139 ; V_135 ++ ) {
const struct V_140 * V_141 ;
struct V_4 * V_142 , * V_143 ;
V_141 = & V_18 -> V_144 [ V_135 ] ;
V_142 = F_50 ( V_58 , V_135 + 1 ) ;
if ( ! V_142 )
goto V_63;
V_143 = F_50 ( V_58 , V_145 ) ;
if ( ! V_143 )
goto V_63;
for ( V_137 = 0 ; V_137 < V_141 -> V_146 ; V_137 ++ ) {
struct V_4 * V_147 ;
V_147 = F_50 ( V_58 , V_137 + 1 ) ;
if ( ! V_147 )
goto V_63;
if ( F_34 ( V_58 , V_148 ,
V_141 -> V_149 [ V_137 ] . V_150 ) )
goto V_63;
if ( F_49 ( V_58 , V_151 ,
V_141 -> V_149 [ V_137 ] . V_152 ) )
goto V_63;
F_51 ( V_58 , V_147 ) ;
}
F_51 ( V_58 , V_143 ) ;
if ( V_141 -> V_153 &&
F_35 ( V_58 , V_154 ) )
goto V_63;
if ( F_34 ( V_58 , V_155 ,
V_141 -> V_156 ) ||
F_34 ( V_58 , V_157 ,
V_141 -> V_158 ) )
goto V_63;
F_51 ( V_58 , V_142 ) ;
}
F_51 ( V_58 , V_136 ) ;
return 0 ;
V_63:
return - V_74 ;
}
static int F_53 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 , int V_56 ,
struct V_6 * V_46 )
{
void * V_159 ;
struct V_4 * V_160 , * V_161 ;
struct V_4 * V_162 , * V_163 ;
struct V_4 * V_164 , * V_165 ;
struct V_4 * V_166 ;
enum V_167 V_168 ;
struct V_59 * V_60 ;
struct V_169 * V_170 ;
int V_135 ;
const struct V_171 * V_172 =
V_46 -> V_18 . V_172 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_173 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_34 ( V_58 , V_27 , V_46 -> V_14 ) ||
F_54 ( V_58 , V_174 , F_55 ( & V_46 -> V_18 ) ) ||
F_34 ( V_58 , V_175 ,
V_176 ) ||
F_56 ( V_58 , V_177 ,
V_46 -> V_18 . V_178 ) ||
F_56 ( V_58 , V_179 ,
V_46 -> V_18 . V_180 ) ||
F_34 ( V_58 , V_181 ,
V_46 -> V_18 . V_182 ) ||
F_34 ( V_58 , V_183 ,
V_46 -> V_18 . V_184 ) ||
F_56 ( V_58 , V_185 ,
V_46 -> V_18 . V_186 ) ||
F_56 ( V_58 , V_187 ,
V_46 -> V_18 . V_188 ) ||
F_56 ( V_58 , V_189 ,
V_46 -> V_18 . V_190 ) ||
F_57 ( V_58 , V_191 ,
V_46 -> V_18 . V_192 ) ||
F_57 ( V_58 , V_193 ,
V_46 -> V_18 . V_194 ) ||
F_56 ( V_58 , V_195 ,
V_46 -> V_18 . V_196 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_197 ) &&
F_35 ( V_58 , V_198 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_199 ) &&
F_35 ( V_58 , V_200 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_201 ) &&
F_35 ( V_58 , V_202 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_203 ) &&
F_35 ( V_58 , V_204 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_205 ) &&
F_35 ( V_58 , V_206 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_207 ) &&
F_35 ( V_58 , V_208 ) )
goto V_63;
if ( F_58 ( V_58 , V_209 ,
sizeof( V_23 ) * V_46 -> V_18 . V_210 ,
V_46 -> V_18 . V_211 ) )
goto V_63;
if ( F_56 ( V_58 , V_212 ,
V_46 -> V_18 . V_213 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_214 ) &&
F_35 ( V_58 , V_215 ) )
goto V_63;
if ( F_34 ( V_58 , V_216 ,
V_46 -> V_18 . V_217 ) ||
F_34 ( V_58 , V_218 ,
V_46 -> V_18 . V_219 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_220 ) &&
F_34 ( V_58 , V_221 ,
V_46 -> V_18 . V_222 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_217 ||
V_46 -> V_18 . V_219 ) && V_46 -> V_223 -> V_224 ) {
V_23 V_225 = 0 , V_226 = 0 ;
int V_36 ;
V_36 = V_46 -> V_223 -> V_224 ( & V_46 -> V_18 , & V_225 , & V_226 ) ;
if ( ! V_36 ) {
if ( F_34 ( V_58 , V_227 ,
V_225 ) ||
F_34 ( V_58 , V_228 ,
V_226 ) )
goto V_63;
}
}
if ( F_49 ( V_58 , V_229 ,
V_46 -> V_18 . V_230 ) )
goto V_63;
V_160 = F_50 ( V_58 , V_231 ) ;
if ( ! V_160 )
goto V_63;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ ) {
if ( ! V_46 -> V_18 . V_233 [ V_168 ] )
continue;
V_161 = F_50 ( V_58 , V_168 ) ;
if ( ! V_161 )
goto V_63;
if ( V_46 -> V_18 . V_233 [ V_168 ] -> V_234 . V_235 &&
( F_58 ( V_58 , V_236 ,
sizeof( V_46 -> V_18 . V_233 [ V_168 ] -> V_234 . V_237 ) ,
& V_46 -> V_18 . V_233 [ V_168 ] -> V_234 . V_237 ) ||
F_57 ( V_58 , V_238 ,
V_46 -> V_18 . V_233 [ V_168 ] -> V_234 . V_239 ) ||
F_56 ( V_58 , V_240 ,
V_46 -> V_18 . V_233 [ V_168 ] -> V_234 . V_241 ) ||
F_56 ( V_58 , V_242 ,
V_46 -> V_18 . V_233 [ V_168 ] -> V_234 . V_243 ) ) )
goto V_63;
if ( V_46 -> V_18 . V_233 [ V_168 ] -> V_244 . V_245 &&
( F_58 ( V_58 , V_246 ,
sizeof( V_46 -> V_18 . V_233 [ V_168 ] -> V_244 . V_247 ) ,
& V_46 -> V_18 . V_233 [ V_168 ] -> V_244 . V_247 ) ||
F_34 ( V_58 , V_248 ,
V_46 -> V_18 . V_233 [ V_168 ] -> V_244 . V_239 ) ) )
goto V_63;
V_162 = F_50 ( V_58 , V_249 ) ;
if ( ! V_162 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_46 -> V_18 . V_233 [ V_168 ] -> V_250 ; V_135 ++ ) {
V_163 = F_50 ( V_58 , V_135 ) ;
if ( ! V_163 )
goto V_63;
V_60 = & V_46 -> V_18 . V_233 [ V_168 ] -> V_251 [ V_135 ] ;
if ( F_33 ( V_58 , V_60 ) )
goto V_63;
F_51 ( V_58 , V_163 ) ;
}
F_51 ( V_58 , V_162 ) ;
V_164 = F_50 ( V_58 , V_252 ) ;
if ( ! V_164 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_46 -> V_18 . V_233 [ V_168 ] -> V_253 ; V_135 ++ ) {
V_165 = F_50 ( V_58 , V_135 ) ;
if ( ! V_165 )
goto V_63;
V_170 = & V_46 -> V_18 . V_233 [ V_168 ] -> V_254 [ V_135 ] ;
if ( F_34 ( V_58 , V_255 ,
V_170 -> V_256 ) )
goto V_63;
if ( ( V_170 -> V_56 & V_257 ) &&
F_35 ( V_58 ,
V_258 ) )
goto V_63;
F_51 ( V_58 , V_165 ) ;
}
F_51 ( V_58 , V_164 ) ;
F_51 ( V_58 , V_161 ) ;
}
F_51 ( V_58 , V_160 ) ;
V_166 = F_50 ( V_58 , V_259 ) ;
if ( ! V_166 )
goto V_63;
V_135 = 0 ;
#define F_59 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_59 ( V_260 , V_261 ) ;
F_59 ( V_262 , V_263 ) ;
F_59 ( V_264 , V_265 ) ;
F_59 ( V_266 , V_267 ) ;
F_59 ( V_268 , V_269 ) ;
F_59 ( V_270 , V_271 ) ;
F_59 ( V_272 , V_273 ) ;
F_59 ( V_274 , V_275 ) ;
F_59 ( V_276 , V_277 ) ;
F_59 ( V_278 , V_279 ) ;
F_59 ( V_280 , V_281 ) ;
F_59 ( V_282 , V_283 ) ;
F_59 ( V_284 , V_285 ) ;
F_59 ( V_286 , V_287 ) ;
F_59 ( V_288 , V_289 ) ;
F_59 ( V_290 , V_291 ) ;
F_59 ( V_292 , V_293 ) ;
if ( V_46 -> V_18 . V_56 & V_294 )
F_59 ( V_295 , V_296 ) ;
F_59 ( V_297 , V_298 ) ;
F_59 ( V_299 , V_300 ) ;
F_59 ( V_301 , V_302 ) ;
if ( V_46 -> V_18 . V_56 & V_303 ) {
V_135 ++ ;
if ( F_34 ( V_58 , V_135 , V_304 ) )
goto V_63;
}
if ( V_46 -> V_223 -> V_305 || V_46 -> V_223 -> V_266 ||
V_46 -> V_223 -> V_286 ) {
V_135 ++ ;
if ( F_34 ( V_58 , V_135 , V_306 ) )
goto V_63;
}
F_59 ( V_307 , V_308 ) ;
if ( V_46 -> V_18 . V_56 & V_205 ) {
F_59 ( V_309 , V_310 ) ;
F_59 ( V_311 , V_312 ) ;
}
if ( V_46 -> V_18 . V_56 & V_313 )
F_59 ( V_314 , V_315 ) ;
F_59 ( V_316 , V_317 ) ;
F_59 ( V_318 , V_319 ) ;
if ( V_46 -> V_18 . V_56 & V_320 ) {
V_135 ++ ;
if ( F_34 ( V_58 , V_135 , V_321 ) )
goto V_63;
}
#ifdef F_60
F_59 ( V_322 , V_323 ) ;
#endif
#undef F_59
if ( V_46 -> V_223 -> V_324 || V_46 -> V_223 -> V_276 ) {
V_135 ++ ;
if ( F_34 ( V_58 , V_135 , V_325 ) )
goto V_63;
}
if ( V_46 -> V_223 -> V_326 || V_46 -> V_223 -> V_280 ) {
V_135 ++ ;
if ( F_34 ( V_58 , V_135 , V_327 ) )
goto V_63;
}
F_51 ( V_58 , V_166 ) ;
if ( V_46 -> V_223 -> V_295 &&
( V_46 -> V_18 . V_56 & V_294 ) &&
F_34 ( V_58 , V_328 ,
V_46 -> V_18 . V_329 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_330 ) &&
F_35 ( V_58 , V_331 ) )
goto V_63;
if ( V_172 ) {
T_3 V_332 ;
struct V_4 * V_333 , * V_334 ;
enum V_335 V_336 ;
V_334 = F_50 ( V_58 , V_337 ) ;
if ( ! V_334 )
goto V_63;
for ( V_336 = 0 ; V_336 < V_338 ; V_336 ++ ) {
V_333 = F_50 ( V_58 , V_336 ) ;
if ( ! V_333 )
goto V_63;
V_135 = 0 ;
V_332 = V_172 [ V_336 ] . V_339 ;
while ( V_332 ) {
if ( ( V_332 & 1 ) &&
F_57 ( V_58 , V_340 ,
( V_135 << 4 ) | V_341 ) )
goto V_63;
V_332 >>= 1 ;
V_135 ++ ;
}
F_51 ( V_58 , V_333 ) ;
}
F_51 ( V_58 , V_334 ) ;
V_334 = F_50 ( V_58 , V_342 ) ;
if ( ! V_334 )
goto V_63;
for ( V_336 = 0 ; V_336 < V_338 ; V_336 ++ ) {
V_333 = F_50 ( V_58 , V_336 ) ;
if ( ! V_333 )
goto V_63;
V_135 = 0 ;
V_332 = V_172 [ V_336 ] . V_343 ;
while ( V_332 ) {
if ( ( V_332 & 1 ) &&
F_57 ( V_58 , V_340 ,
( V_135 << 4 ) | V_341 ) )
goto V_63;
V_332 >>= 1 ;
V_135 ++ ;
}
F_51 ( V_58 , V_333 ) ;
}
F_51 ( V_58 , V_334 ) ;
}
#ifdef F_61
if ( V_46 -> V_18 . V_344 . V_56 || V_46 -> V_18 . V_344 . V_345 ) {
struct V_4 * V_346 ;
V_346 = F_50 ( V_58 ,
V_347 ) ;
if ( ! V_346 )
goto V_63;
if ( ( ( V_46 -> V_18 . V_344 . V_56 & V_348 ) &&
F_35 ( V_58 , V_349 ) ) ||
( ( V_46 -> V_18 . V_344 . V_56 & V_350 ) &&
F_35 ( V_58 , V_351 ) ) ||
( ( V_46 -> V_18 . V_344 . V_56 & V_352 ) &&
F_35 ( V_58 , V_353 ) ) ||
( ( V_46 -> V_18 . V_344 . V_56 & V_354 ) &&
F_35 ( V_58 , V_355 ) ) ||
( ( V_46 -> V_18 . V_344 . V_56 & V_356 ) &&
F_35 ( V_58 , V_357 ) ) ||
( ( V_46 -> V_18 . V_344 . V_56 & V_358 ) &&
F_35 ( V_58 , V_359 ) ) ||
( ( V_46 -> V_18 . V_344 . V_56 & V_360 ) &&
F_35 ( V_58 , V_361 ) ) ||
( ( V_46 -> V_18 . V_344 . V_56 & V_362 ) &&
F_35 ( V_58 , V_363 ) ) )
goto V_63;
if ( V_46 -> V_18 . V_344 . V_345 ) {
struct V_364 V_365 = {
. V_366 = V_46 -> V_18 . V_344 . V_345 ,
. V_367 =
V_46 -> V_18 . V_344 . V_368 ,
. V_369 =
V_46 -> V_18 . V_344 . V_370 ,
} ;
if ( F_58 ( V_58 , V_371 ,
sizeof( V_365 ) , & V_365 ) )
goto V_63;
}
F_51 ( V_58 , V_346 ) ;
}
#endif
if ( F_49 ( V_58 , V_372 ,
V_46 -> V_18 . V_373 ) )
goto V_63;
if ( F_52 ( & V_46 -> V_18 , V_58 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_374 ) &&
F_34 ( V_58 , V_375 ,
V_46 -> V_18 . V_376 ) )
goto V_63;
if ( F_34 ( V_58 , V_377 ,
V_46 -> V_18 . V_378 ) )
goto V_63;
if ( V_46 -> V_18 . V_379 &&
F_58 ( V_58 , V_380 ,
sizeof( * V_46 -> V_18 . V_379 ) ,
V_46 -> V_18 . V_379 ) )
goto V_63;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
static int F_64 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_88 = 0 ;
int V_382 = V_35 -> args [ 0 ] ;
struct V_6 * V_46 ;
F_8 ( & V_32 ) ;
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_65 ( F_7 ( & V_46 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( ++ V_88 <= V_382 )
continue;
if ( F_53 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_383 , V_384 ,
V_46 ) < 0 ) {
V_88 -- ;
break;
}
}
F_9 ( & V_32 ) ;
V_35 -> args [ 0 ] = V_88 ;
return V_45 -> V_52 ;
}
static int F_67 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
struct V_6 * V_46 = V_31 -> V_385 [ 0 ] ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_53 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 , V_46 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_71 ( struct V_4 * V_78 [] ,
struct V_389 * V_390 )
{
if ( ! V_78 [ V_391 ] || ! V_78 [ V_392 ] ||
! V_78 [ V_393 ] || ! V_78 [ V_394 ] ||
! V_78 [ V_395 ] )
return - V_16 ;
V_390 -> V_396 = F_39 ( V_78 [ V_391 ] ) ;
V_390 -> V_397 = F_72 ( V_78 [ V_392 ] ) ;
V_390 -> V_398 = F_72 ( V_78 [ V_393 ] ) ;
V_390 -> V_399 = F_72 ( V_78 [ V_394 ] ) ;
V_390 -> V_400 = F_39 ( V_78 [ V_395 ] ) ;
if ( V_390 -> V_396 >= V_401 )
return - V_16 ;
return 0 ;
}
static bool F_73 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_121 == V_122 ||
V_17 -> V_121 == V_125 ||
V_17 -> V_121 == V_402 ||
V_17 -> V_121 == V_124 ;
}
static bool F_74 ( struct V_30 * V_31 ,
enum V_403 * V_404 )
{
enum V_403 V_25 ;
if ( ! V_31 -> V_5 [ V_405 ] )
return false ;
V_25 = F_4 ( V_31 -> V_5 [ V_405 ] ) ;
if ( V_25 != V_406 &&
V_25 != V_407 &&
V_25 != V_408 &&
V_25 != V_409 )
return false ;
if ( V_404 )
* V_404 = V_25 ;
return true ;
}
static int F_75 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_30 * V_31 )
{
struct V_59 * V_410 ;
enum V_403 V_404 = V_406 ;
V_23 V_411 ;
int V_8 ;
enum V_335 V_121 = V_402 ;
if ( V_17 )
V_121 = V_17 -> V_121 ;
if ( ! V_31 -> V_5 [ V_412 ] )
return - V_16 ;
if ( ! F_73 ( V_17 ) )
return - V_413 ;
if ( V_31 -> V_5 [ V_405 ] &&
! F_74 ( V_31 , & V_404 ) )
return - V_16 ;
V_411 = F_4 ( V_31 -> V_5 [ V_412 ] ) ;
F_8 ( & V_7 -> V_19 ) ;
switch ( V_121 ) {
case V_122 :
case V_124 :
if ( V_17 -> V_414 ) {
V_8 = - V_415 ;
break;
}
V_410 = F_76 ( V_7 , V_411 , V_404 ) ;
if ( ! V_410 || ! F_77 ( & V_7 -> V_18 ,
V_410 ,
V_404 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_416 = V_410 ;
V_17 -> V_417 = V_404 ;
V_8 = 0 ;
break;
case V_125 :
V_8 = F_78 ( V_7 , V_17 , V_411 , V_404 ) ;
break;
case V_402 :
V_8 = F_79 ( V_7 , V_411 , V_404 ) ;
break;
default:
V_8 = - V_16 ;
}
F_9 ( & V_7 -> V_19 ) ;
return V_8 ;
}
static int F_80 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_20 = V_31 -> V_385 [ 1 ] ;
return F_75 ( V_7 , V_20 -> V_29 , V_31 ) ;
}
static int F_81 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
const T_2 * V_418 ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( F_82 ( V_46 ) )
return - V_415 ;
if ( ! V_7 -> V_223 -> V_307 )
return - V_413 ;
if ( V_17 -> V_121 != V_420 )
return - V_413 ;
V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
return V_7 -> V_223 -> V_307 ( V_17 -> V_18 , V_46 , V_418 ) ;
}
static int F_83 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_26 * V_20 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_421 = 0 ;
struct V_4 * V_422 ;
V_23 V_423 ;
T_2 V_178 = 0 , V_180 = 0 ;
V_23 V_182 = 0 , V_184 = 0 ;
T_2 V_186 = 0 ;
F_8 ( & V_32 ) ;
if ( V_31 -> V_5 [ V_10 ] ) {
int V_21 = F_4 ( V_31 -> V_5 [ V_10 ] ) ;
V_20 = F_12 ( F_84 ( V_31 ) , V_21 ) ;
if ( V_20 && V_20 -> V_29 ) {
V_7 = F_13 ( V_20 -> V_29 -> V_18 ) ;
F_8 ( & V_7 -> V_33 ) ;
} else
V_20 = NULL ;
}
if ( ! V_20 ) {
V_7 = F_10 ( F_84 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_7 ) ) {
F_9 ( & V_32 ) ;
return F_24 ( V_7 ) ;
}
V_17 = NULL ;
V_20 = NULL ;
V_8 = 0 ;
F_8 ( & V_7 -> V_33 ) ;
} else if ( F_73 ( V_20 -> V_29 ) )
V_17 = V_20 -> V_29 ;
else
V_17 = NULL ;
if ( V_31 -> V_5 [ V_174 ] )
V_8 = F_85 (
V_7 , F_29 ( V_31 -> V_5 [ V_174 ] ) ) ;
F_9 ( & V_32 ) ;
if ( V_8 )
goto V_424;
if ( V_31 -> V_5 [ V_425 ] ) {
struct V_389 V_390 ;
struct V_4 * V_78 [ V_426 + 1 ] ;
if ( ! V_7 -> V_223 -> V_427 ) {
V_8 = - V_413 ;
goto V_424;
}
if ( ! V_20 ) {
V_8 = - V_16 ;
goto V_424;
}
if ( V_20 -> V_29 -> V_121 != V_122 &&
V_20 -> V_29 -> V_121 != V_124 ) {
V_8 = - V_16 ;
goto V_424;
}
if ( ! F_82 ( V_20 ) ) {
V_8 = - V_428 ;
goto V_424;
}
F_44 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_86 ( V_78 , V_426 ,
F_29 ( V_422 ) ,
F_30 ( V_422 ) ,
V_429 ) ;
V_8 = F_71 ( V_78 , & V_390 ) ;
if ( V_8 )
goto V_424;
V_8 = V_7 -> V_223 -> V_427 ( & V_7 -> V_18 ,
V_20 ,
& V_390 ) ;
if ( V_8 )
goto V_424;
}
}
if ( V_31 -> V_5 [ V_412 ] ) {
V_8 = F_75 ( V_7 , V_17 , V_31 ) ;
if ( V_8 )
goto V_424;
}
if ( V_31 -> V_5 [ V_430 ] ) {
enum V_431 type ;
int V_88 , V_432 = 0 ;
if ( ! V_7 -> V_223 -> V_433 ) {
V_8 = - V_413 ;
goto V_424;
}
V_88 = V_430 ;
type = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
if ( ! V_31 -> V_5 [ V_434 ] &&
( type != V_435 ) ) {
V_8 = - V_16 ;
goto V_424;
}
if ( type != V_435 ) {
V_88 = V_434 ;
V_432 = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
}
V_8 = V_7 -> V_223 -> V_433 ( & V_7 -> V_18 , type , V_432 ) ;
if ( V_8 )
goto V_424;
}
if ( V_31 -> V_5 [ V_227 ] &&
V_31 -> V_5 [ V_228 ] ) {
V_23 V_225 , V_226 ;
if ( ( ! V_7 -> V_18 . V_217 &&
! V_7 -> V_18 . V_219 ) ||
! V_7 -> V_223 -> V_436 ) {
V_8 = - V_413 ;
goto V_424;
}
V_225 = F_4 ( V_31 -> V_5 [ V_227 ] ) ;
V_226 = F_4 ( V_31 -> V_5 [ V_228 ] ) ;
if ( ( ~ V_225 && ( V_225 & ~ V_7 -> V_18 . V_217 ) ) ||
( ~ V_226 && ( V_226 & ~ V_7 -> V_18 . V_219 ) ) ) {
V_8 = - V_16 ;
goto V_424;
}
V_225 = V_225 & V_7 -> V_18 . V_217 ;
V_226 = V_226 & V_7 -> V_18 . V_219 ;
V_8 = V_7 -> V_223 -> V_436 ( & V_7 -> V_18 , V_225 , V_226 ) ;
if ( V_8 )
goto V_424;
}
V_423 = 0 ;
if ( V_31 -> V_5 [ V_177 ] ) {
V_178 = F_39 (
V_31 -> V_5 [ V_177 ] ) ;
if ( V_178 == 0 ) {
V_8 = - V_16 ;
goto V_424;
}
V_423 |= V_437 ;
}
if ( V_31 -> V_5 [ V_179 ] ) {
V_180 = F_39 (
V_31 -> V_5 [ V_179 ] ) ;
if ( V_180 == 0 ) {
V_8 = - V_16 ;
goto V_424;
}
V_423 |= V_438 ;
}
if ( V_31 -> V_5 [ V_181 ] ) {
V_182 = F_4 (
V_31 -> V_5 [ V_181 ] ) ;
if ( V_182 < 256 ) {
V_8 = - V_16 ;
goto V_424;
}
if ( V_182 != ( V_23 ) - 1 ) {
V_182 &= ~ 0x1 ;
}
V_423 |= V_439 ;
}
if ( V_31 -> V_5 [ V_183 ] ) {
V_184 = F_4 (
V_31 -> V_5 [ V_183 ] ) ;
V_423 |= V_440 ;
}
if ( V_31 -> V_5 [ V_185 ] ) {
V_186 = F_39 (
V_31 -> V_5 [ V_185 ] ) ;
V_423 |= V_441 ;
}
if ( V_423 ) {
T_2 V_442 , V_443 ;
V_23 V_444 , V_445 ;
T_2 V_446 ;
if ( ! V_7 -> V_223 -> V_447 ) {
V_8 = - V_413 ;
goto V_424;
}
V_442 = V_7 -> V_18 . V_178 ;
V_443 = V_7 -> V_18 . V_180 ;
V_444 = V_7 -> V_18 . V_182 ;
V_445 = V_7 -> V_18 . V_184 ;
V_446 = V_7 -> V_18 . V_186 ;
if ( V_423 & V_437 )
V_7 -> V_18 . V_178 = V_178 ;
if ( V_423 & V_438 )
V_7 -> V_18 . V_180 = V_180 ;
if ( V_423 & V_439 )
V_7 -> V_18 . V_182 = V_182 ;
if ( V_423 & V_440 )
V_7 -> V_18 . V_184 = V_184 ;
if ( V_423 & V_441 )
V_7 -> V_18 . V_186 = V_186 ;
V_8 = V_7 -> V_223 -> V_447 ( & V_7 -> V_18 , V_423 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_178 = V_442 ;
V_7 -> V_18 . V_180 = V_443 ;
V_7 -> V_18 . V_182 = V_444 ;
V_7 -> V_18 . V_184 = V_445 ;
V_7 -> V_18 . V_186 = V_446 ;
}
}
V_424:
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
static int F_87 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 , int V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_26 * V_46 = V_17 -> V_20 ;
void * V_159 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_448 ) ;
if ( ! V_159 )
return - 1 ;
if ( V_46 &&
( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_54 ( V_58 , V_449 , V_46 -> V_450 ) ||
F_58 ( V_58 , V_419 , V_451 , V_46 -> V_452 ) ) )
goto V_63;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_453 , V_17 -> V_121 ) ||
F_88 ( V_58 , V_12 , V_13 ( V_17 ) ) ||
F_34 ( V_58 , V_175 ,
V_7 -> V_454 ^
( V_176 << 2 ) ) )
goto V_63;
if ( V_7 -> V_223 -> V_455 ) {
struct V_59 * V_60 ;
enum V_403 V_404 ;
V_60 = V_7 -> V_223 -> V_455 ( & V_7 -> V_18 , V_17 ,
& V_404 ) ;
if ( V_60 &&
( F_34 ( V_58 , V_412 ,
V_60 -> V_62 ) ||
F_34 ( V_58 , V_405 ,
V_404 ) ) )
goto V_63;
}
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
static int F_89 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_456 = 0 ;
int V_457 = 0 ;
int V_458 = V_35 -> args [ 0 ] ;
int V_459 = V_35 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_8 ( & V_32 ) ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_65 ( F_7 ( & V_7 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( V_456 < V_458 ) {
V_456 ++ ;
continue;
}
V_457 = 0 ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_457 < V_459 ) {
V_457 ++ ;
continue;
}
if ( F_87 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_383 , V_384 ,
V_7 , V_17 ) < 0 ) {
F_9 ( & V_7 -> V_19 ) ;
goto V_460;
}
V_457 ++ ;
}
F_9 ( & V_7 -> V_19 ) ;
V_456 ++ ;
}
V_460:
F_9 ( & V_32 ) ;
V_35 -> args [ 0 ] = V_456 ;
V_35 -> args [ 1 ] = V_457 ;
return V_45 -> V_52 ;
}
static int F_90 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
struct V_6 * V_46 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_87 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_46 , V_17 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_91 ( struct V_4 * V_461 , V_23 * V_462 )
{
struct V_4 * V_56 [ V_463 + 1 ] ;
int V_464 ;
* V_462 = 0 ;
if ( ! V_461 )
return - V_16 ;
if ( F_38 ( V_56 , V_463 ,
V_461 , V_465 ) )
return - V_16 ;
for ( V_464 = 1 ; V_464 <= V_463 ; V_464 ++ )
if ( V_56 [ V_464 ] )
* V_462 |= ( 1 << V_464 ) ;
return 0 ;
}
static int F_92 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_2 V_466 ,
enum V_335 V_121 )
{
if ( ! V_466 ) {
if ( V_20 && ( V_20 -> V_467 & V_468 ) )
return - V_415 ;
return 0 ;
}
switch ( V_121 ) {
case V_123 :
if ( V_7 -> V_18 . V_56 & V_469 )
return 0 ;
break;
case V_129 :
if ( V_7 -> V_18 . V_56 & V_470 )
return 0 ;
break;
default:
break;
}
return - V_413 ;
}
static int F_93 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_471 V_119 ;
int V_47 ;
enum V_335 V_472 , V_473 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
V_23 V_474 , * V_56 = NULL ;
bool V_475 = false ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_472 = V_473 = V_46 -> V_29 -> V_121 ;
if ( V_31 -> V_5 [ V_453 ] ) {
V_473 = F_4 ( V_31 -> V_5 [ V_453 ] ) ;
if ( V_472 != V_473 )
V_475 = true ;
if ( V_473 > V_476 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_477 ] ) {
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_473 != V_125 )
return - V_16 ;
if ( F_82 ( V_46 ) )
return - V_415 ;
F_94 ( V_17 ) ;
F_95 ( V_478 !=
V_479 ) ;
V_17 -> V_480 =
F_30 ( V_31 -> V_5 [ V_477 ] ) ;
memcpy ( V_17 -> V_481 , F_29 ( V_31 -> V_5 [ V_477 ] ) ,
V_17 -> V_480 ) ;
F_96 ( V_17 ) ;
}
if ( V_31 -> V_5 [ V_482 ] ) {
V_119 . V_466 = ! ! F_39 ( V_31 -> V_5 [ V_482 ] ) ;
V_475 = true ;
V_47 = F_92 ( V_7 , V_46 , V_119 . V_466 , V_473 ) ;
if ( V_47 )
return V_47 ;
} else {
V_119 . V_466 = - 1 ;
}
if ( V_31 -> V_5 [ V_483 ] ) {
if ( V_473 != V_402 )
return - V_16 ;
V_47 = F_91 ( V_31 -> V_5 [ V_483 ] ,
& V_474 ) ;
if ( V_47 )
return V_47 ;
V_56 = & V_474 ;
V_475 = true ;
}
if ( V_475 )
V_47 = F_97 ( V_7 , V_46 , V_473 , V_56 , & V_119 ) ;
else
V_47 = 0 ;
if ( ! V_47 && V_119 . V_466 != - 1 )
V_46 -> V_29 -> V_466 = V_119 . V_466 ;
return V_47 ;
}
static int F_98 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_471 V_119 ;
struct V_1 * V_17 ;
struct V_44 * V_58 ;
int V_47 ;
enum V_335 type = V_484 ;
V_23 V_56 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
if ( ! V_31 -> V_5 [ V_449 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_453 ] ) {
type = F_4 ( V_31 -> V_5 [ V_453 ] ) ;
if ( type > V_476 )
return - V_16 ;
}
if ( ! V_7 -> V_223 -> V_260 ||
! ( V_7 -> V_18 . V_230 & ( 1 << type ) ) )
return - V_413 ;
if ( V_31 -> V_5 [ V_482 ] ) {
V_119 . V_466 = ! ! F_39 ( V_31 -> V_5 [ V_482 ] ) ;
V_47 = F_92 ( V_7 , NULL , V_119 . V_466 , type ) ;
if ( V_47 )
return V_47 ;
}
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_47 = F_91 ( type == V_402 ?
V_31 -> V_5 [ V_483 ] : NULL ,
& V_56 ) ;
V_17 = V_7 -> V_223 -> V_260 ( & V_7 -> V_18 ,
F_29 ( V_31 -> V_5 [ V_449 ] ) ,
type , V_47 ? NULL : & V_56 , & V_119 ) ;
if ( F_16 ( V_17 ) ) {
F_69 ( V_58 ) ;
return F_24 ( V_17 ) ;
}
if ( type == V_125 &&
V_31 -> V_5 [ V_477 ] ) {
F_94 ( V_17 ) ;
F_95 ( V_478 !=
V_479 ) ;
V_17 -> V_480 =
F_30 ( V_31 -> V_5 [ V_477 ] ) ;
memcpy ( V_17 -> V_481 , F_29 ( V_31 -> V_5 [ V_477 ] ) ,
V_17 -> V_480 ) ;
F_96 ( V_17 ) ;
}
if ( F_87 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_7 , V_17 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_99 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
if ( ! V_7 -> V_223 -> V_485 )
return - V_413 ;
if ( ! V_17 -> V_20 )
V_31 -> V_385 [ 1 ] = NULL ;
return V_7 -> V_223 -> V_485 ( & V_7 -> V_18 , V_17 ) ;
}
static int F_100 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_3 V_486 ;
if ( ! V_31 -> V_5 [ V_487 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_318 )
return - V_413 ;
V_486 = F_72 ( V_31 -> V_5 [ V_487 ] ) ;
return V_7 -> V_223 -> V_318 ( & V_7 -> V_18 , V_46 , V_486 ) ;
}
static void F_101 ( void * V_141 , struct V_488 * V_119 )
{
struct V_4 * V_75 ;
struct V_489 * V_490 = V_141 ;
if ( ( V_119 -> V_75 &&
F_58 ( V_490 -> V_58 , V_104 ,
V_119 -> V_91 , V_119 -> V_75 ) ) ||
( V_119 -> V_55 &&
F_58 ( V_490 -> V_58 , V_105 ,
V_119 -> V_93 , V_119 -> V_55 ) ) ||
( V_119 -> V_95 &&
F_34 ( V_490 -> V_58 , V_107 ,
V_119 -> V_95 ) ) )
goto V_63;
V_75 = F_50 ( V_490 -> V_58 , V_112 ) ;
if ( ! V_75 )
goto V_63;
if ( ( V_119 -> V_75 &&
F_58 ( V_490 -> V_58 , V_89 ,
V_119 -> V_91 , V_119 -> V_75 ) ) ||
( V_119 -> V_55 &&
F_58 ( V_490 -> V_58 , V_92 ,
V_119 -> V_93 , V_119 -> V_55 ) ) ||
( V_119 -> V_95 &&
F_34 ( V_490 -> V_58 , V_94 ,
V_119 -> V_95 ) ) )
goto V_63;
if ( F_56 ( V_490 -> V_58 , V_106 , V_490 -> V_88 ) )
goto V_63;
F_51 ( V_490 -> V_58 , V_75 ) ;
return;
V_63:
V_490 -> error = 1 ;
}
static int F_102 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 V_491 = 0 ;
const T_2 * V_492 = NULL ;
bool V_493 ;
struct V_489 V_490 = {
. error = 0 ,
} ;
void * V_159 ;
struct V_44 * V_58 ;
if ( V_31 -> V_5 [ V_106 ] )
V_491 = F_39 ( V_31 -> V_5 [ V_106 ] ) ;
if ( V_491 > 5 )
return - V_16 ;
if ( V_31 -> V_5 [ V_419 ] )
V_492 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_493 = ! ! V_492 ;
if ( V_31 -> V_5 [ V_110 ] ) {
V_23 V_494 = F_4 ( V_31 -> V_5 [ V_110 ] ) ;
if ( V_494 >= V_97 )
return - V_16 ;
if ( V_494 != V_495 &&
V_494 != V_496 )
return - V_16 ;
V_493 = V_494 == V_496 ;
}
if ( ! V_7 -> V_223 -> V_497 )
return - V_413 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_498 ) ;
if ( F_16 ( V_159 ) )
return F_24 ( V_159 ) ;
V_490 . V_58 = V_58 ;
V_490 . V_88 = V_491 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_56 ( V_58 , V_106 , V_491 ) )
goto V_63;
if ( V_492 &&
F_58 ( V_58 , V_419 , V_451 , V_492 ) )
goto V_63;
if ( V_493 && V_492 &&
! ( V_7 -> V_18 . V_56 & V_197 ) )
return - V_499 ;
V_47 = V_7 -> V_223 -> V_497 ( & V_7 -> V_18 , V_46 , V_491 , V_493 ,
V_492 , & V_490 , F_101 ) ;
if ( V_47 )
goto V_500;
if ( V_490 . error )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_500:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_103 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_76 V_75 ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 < 0 )
return - V_16 ;
if ( ! V_75 . V_81 && ! V_75 . V_83 )
return - V_16 ;
F_94 ( V_46 -> V_29 ) ;
if ( V_75 . V_81 ) {
if ( ! V_7 -> V_223 -> V_501 ) {
V_47 = - V_413 ;
goto V_460;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_460;
V_47 = V_7 -> V_223 -> V_501 ( & V_7 -> V_18 , V_46 , V_75 . V_88 ,
V_75 . V_85 , V_75 . V_86 ) ;
if ( V_47 )
goto V_460;
#ifdef F_104
V_46 -> V_29 -> V_502 . V_503 = V_75 . V_88 ;
#endif
} else {
if ( V_75 . V_85 || ! V_75 . V_86 ) {
V_47 = - V_16 ;
goto V_460;
}
if ( ! V_7 -> V_223 -> V_504 ) {
V_47 = - V_413 ;
goto V_460;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_460;
V_47 = V_7 -> V_223 -> V_504 ( & V_7 -> V_18 ,
V_46 , V_75 . V_88 ) ;
if ( V_47 )
goto V_460;
#ifdef F_104
V_46 -> V_29 -> V_502 . V_505 = V_75 . V_88 ;
#endif
}
V_460:
F_96 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_105 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_76 V_75 ;
const T_2 * V_492 = NULL ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_75 . V_90 . V_75 )
return - V_16 ;
if ( V_31 -> V_5 [ V_419 ] )
V_492 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_492 )
V_75 . type = V_496 ;
else
V_75 . type = V_495 ;
}
if ( V_75 . type != V_496 &&
V_75 . type != V_495 )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_264 )
return - V_413 ;
if ( F_45 ( V_7 , & V_75 . V_90 , V_75 . V_88 ,
V_75 . type == V_496 ,
V_492 ) )
return - V_16 ;
F_94 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( ! V_47 )
V_47 = V_7 -> V_223 -> V_264 ( & V_7 -> V_18 , V_46 , V_75 . V_88 ,
V_75 . type == V_496 ,
V_492 , & V_75 . V_90 ) ;
F_96 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_106 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 * V_492 = NULL ;
struct V_76 V_75 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_419 ] )
V_492 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_492 )
V_75 . type = V_496 ;
else
V_75 . type = V_495 ;
}
if ( V_75 . type != V_496 &&
V_75 . type != V_495 )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_506 )
return - V_413 ;
F_94 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_75 . type == V_496 && V_492 &&
! ( V_7 -> V_18 . V_56 & V_197 ) )
V_47 = - V_499 ;
if ( ! V_47 )
V_47 = V_7 -> V_223 -> V_506 ( & V_7 -> V_18 , V_46 , V_75 . V_88 ,
V_75 . type == V_496 ,
V_492 ) ;
#ifdef F_104
if ( ! V_47 ) {
if ( V_75 . V_88 == V_46 -> V_29 -> V_502 . V_503 )
V_46 -> V_29 -> V_502 . V_503 = - 1 ;
else if ( V_75 . V_88 == V_46 -> V_29 -> V_502 . V_505 )
V_46 -> V_29 -> V_502 . V_505 = - 1 ;
}
#endif
F_96 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_107 ( struct V_30 * V_31 ,
struct V_507 * V_508 )
{
bool V_509 = false ;
if ( ! F_28 ( V_31 -> V_5 [ V_510 ] ) ||
! F_28 ( V_31 -> V_5 [ V_511 ] ) ||
! F_28 ( V_31 -> V_5 [ V_512 ] ) ||
! F_28 ( V_31 -> V_5 [ V_513 ] ) )
return - V_16 ;
memset ( V_508 , 0 , sizeof( * V_508 ) ) ;
if ( V_31 -> V_5 [ V_514 ] ) {
V_508 -> V_515 = F_29 ( V_31 -> V_5 [ V_514 ] ) ;
V_508 -> V_516 = F_30 ( V_31 -> V_5 [ V_514 ] ) ;
if ( ! V_508 -> V_516 )
return - V_16 ;
V_509 = true ;
}
if ( V_31 -> V_5 [ V_510 ] ) {
V_508 -> V_517 = F_29 ( V_31 -> V_5 [ V_510 ] ) ;
V_508 -> V_518 =
F_30 ( V_31 -> V_5 [ V_510 ] ) ;
V_509 = true ;
}
if ( ! V_509 )
return - V_16 ;
if ( V_31 -> V_5 [ V_511 ] ) {
V_508 -> V_519 = F_29 ( V_31 -> V_5 [ V_511 ] ) ;
V_508 -> V_520 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
}
if ( V_31 -> V_5 [ V_512 ] ) {
V_508 -> V_521 =
F_29 ( V_31 -> V_5 [ V_512 ] ) ;
V_508 -> V_522 =
F_30 ( V_31 -> V_5 [ V_512 ] ) ;
}
if ( V_31 -> V_5 [ V_513 ] ) {
V_508 -> V_523 =
F_29 ( V_31 -> V_5 [ V_513 ] ) ;
V_508 -> V_524 =
F_30 ( V_31 -> V_5 [ V_513 ] ) ;
}
if ( V_31 -> V_5 [ V_525 ] ) {
V_508 -> V_526 =
F_29 ( V_31 -> V_5 [ V_525 ] ) ;
V_508 -> V_527 =
F_30 ( V_31 -> V_5 [ V_525 ] ) ;
}
return 0 ;
}
static bool F_108 ( struct V_6 * V_7 ,
struct V_528 * V_119 )
{
struct V_1 * V_17 ;
bool V_529 = false ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_121 != V_122 &&
V_17 -> V_121 != V_124 )
continue;
if ( ! V_17 -> V_416 )
continue;
V_119 -> V_410 = V_17 -> V_416 ;
V_119 -> V_404 = V_17 -> V_417 ;
V_529 = true ;
break;
}
F_9 ( & V_7 -> V_19 ) ;
return V_529 ;
}
static int F_109 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_528 V_119 ;
int V_47 ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_413 ;
if ( ! V_7 -> V_223 -> V_266 )
return - V_413 ;
if ( V_17 -> V_414 )
return - V_530 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
if ( ! V_31 -> V_5 [ V_531 ] ||
! V_31 -> V_5 [ V_532 ] ||
! V_31 -> V_5 [ V_514 ] )
return - V_16 ;
V_47 = F_107 ( V_31 , & V_119 . V_533 ) ;
if ( V_47 )
return V_47 ;
V_119 . V_414 =
F_4 ( V_31 -> V_5 [ V_531 ] ) ;
V_119 . V_534 =
F_4 ( V_31 -> V_5 [ V_532 ] ) ;
V_47 = F_110 ( V_7 , V_119 . V_414 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_535 ] ) {
V_119 . V_481 = F_29 ( V_31 -> V_5 [ V_535 ] ) ;
V_119 . V_536 =
F_30 ( V_31 -> V_5 [ V_535 ] ) ;
if ( V_119 . V_536 == 0 ||
V_119 . V_536 > V_478 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_537 ] ) {
V_119 . V_538 = F_4 (
V_31 -> V_5 [ V_537 ] ) ;
if ( V_119 . V_538 != V_539 &&
V_119 . V_538 != V_540 &&
V_119 . V_538 != V_541 )
return - V_16 ;
}
V_119 . V_542 = ! ! V_31 -> V_5 [ V_543 ] ;
if ( V_31 -> V_5 [ V_544 ] ) {
V_119 . V_545 = F_4 (
V_31 -> V_5 [ V_544 ] ) ;
if ( ! F_111 ( V_119 . V_545 ) )
return - V_16 ;
} else
V_119 . V_545 = V_546 ;
V_47 = F_112 ( V_7 , V_31 , & V_119 . V_547 ,
V_548 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_549 ] ) {
if ( ! ( V_7 -> V_18 . V_378 & V_550 ) )
return - V_413 ;
V_119 . V_551 = F_72 (
V_31 -> V_5 [ V_549 ] ) ;
}
if ( V_31 -> V_5 [ V_412 ] ) {
enum V_403 V_404 = V_406 ;
if ( V_31 -> V_5 [ V_405 ] &&
! F_74 ( V_31 , & V_404 ) )
return - V_16 ;
V_119 . V_410 = F_76 ( V_7 ,
F_4 ( V_31 -> V_5 [ V_412 ] ) ,
V_404 ) ;
if ( ! V_119 . V_410 )
return - V_16 ;
V_119 . V_404 = V_404 ;
} else if ( V_17 -> V_416 ) {
V_119 . V_410 = V_17 -> V_416 ;
V_119 . V_404 = V_17 -> V_417 ;
} else if ( ! F_108 ( V_7 , & V_119 ) )
return - V_16 ;
if ( ! F_77 ( & V_7 -> V_18 , V_119 . V_410 ,
V_119 . V_404 ) )
return - V_16 ;
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_113 ( V_7 , V_17 , V_119 . V_410 ,
V_552 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_47 )
return V_47 ;
V_47 = V_7 -> V_223 -> V_266 ( & V_7 -> V_18 , V_46 , & V_119 ) ;
if ( ! V_47 ) {
V_17 -> V_416 = V_119 . V_410 ;
V_17 -> V_417 = V_119 . V_404 ;
V_17 -> V_414 = V_119 . V_414 ;
V_17 -> V_410 = V_119 . V_410 ;
}
return V_47 ;
}
static int F_114 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_507 V_119 ;
int V_47 ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_413 ;
if ( ! V_7 -> V_223 -> V_553 )
return - V_413 ;
if ( ! V_17 -> V_414 )
return - V_16 ;
V_47 = F_107 ( V_31 , & V_119 ) ;
if ( V_47 )
return V_47 ;
return V_7 -> V_223 -> V_553 ( & V_7 -> V_18 , V_46 , & V_119 ) ;
}
static int F_115 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
return F_116 ( V_7 , V_46 ) ;
}
static int F_117 ( struct V_30 * V_31 ,
enum V_335 V_121 ,
struct V_554 * V_119 )
{
struct V_4 * V_56 [ V_555 + 1 ] ;
struct V_4 * V_461 ;
int V_464 ;
V_461 = V_31 -> V_5 [ V_556 ] ;
if ( V_461 ) {
struct V_557 * V_558 ;
V_558 = F_29 ( V_461 ) ;
V_119 -> V_559 = V_558 -> V_560 ;
V_119 -> V_561 = V_558 -> V_562 ;
if ( ( V_119 -> V_559 |
V_119 -> V_561 ) & F_118 ( V_563 ) )
return - V_16 ;
return 0 ;
}
V_461 = V_31 -> V_5 [ V_564 ] ;
if ( ! V_461 )
return 0 ;
if ( F_38 ( V_56 , V_555 ,
V_461 , V_565 ) )
return - V_16 ;
switch ( V_121 ) {
case V_122 :
case V_123 :
case V_124 :
V_119 -> V_559 = F_118 ( V_566 ) |
F_118 ( V_567 ) |
F_118 ( V_568 ) |
F_118 ( V_569 ) ;
break;
case V_130 :
case V_129 :
V_119 -> V_559 = F_118 ( V_566 ) |
F_118 ( V_570 ) ;
break;
case V_125 :
V_119 -> V_559 = F_118 ( V_571 ) |
F_118 ( V_569 ) |
F_118 ( V_566 ) ;
default:
return - V_16 ;
}
for ( V_464 = 1 ; V_464 <= V_555 ; V_464 ++ ) {
if ( V_56 [ V_464 ] ) {
V_119 -> V_561 |= ( 1 << V_464 ) ;
if ( V_464 > V_572 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_119 ( struct V_44 * V_58 , struct V_573 * V_31 ,
int V_50 )
{
struct V_4 * V_170 ;
V_23 V_256 ;
T_3 V_574 ;
V_170 = F_50 ( V_58 , V_50 ) ;
if ( ! V_170 )
goto V_63;
V_256 = F_120 ( V_31 ) ;
V_574 = V_256 < ( 1UL << 16 ) ? V_256 : 0 ;
if ( ( V_256 > 0 &&
F_34 ( V_58 , V_575 , V_256 ) ) ||
( V_574 > 0 &&
F_57 ( V_58 , V_576 , V_574 ) ) ||
( ( V_31 -> V_56 & V_577 ) &&
F_56 ( V_58 , V_578 , V_31 -> V_237 ) ) ||
( ( V_31 -> V_56 & V_579 ) &&
F_35 ( V_58 , V_580 ) ) ||
( ( V_31 -> V_56 & V_581 ) &&
F_35 ( V_58 , V_582 ) ) )
goto V_63;
F_51 ( V_58 , V_170 ) ;
return true ;
V_63:
return false ;
}
static int F_121 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 ,
struct V_6 * V_7 ,
struct V_26 * V_46 ,
const T_2 * V_492 , struct V_583 * V_584 )
{
void * V_159 ;
struct V_4 * V_585 , * V_586 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_587 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_492 ) ||
F_34 ( V_58 , V_175 , V_584 -> V_588 ) )
goto V_63;
V_585 = F_50 ( V_58 , V_589 ) ;
if ( ! V_585 )
goto V_63;
if ( ( V_584 -> V_590 & V_591 ) &&
F_34 ( V_58 , V_592 ,
V_584 -> V_593 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_594 ) &&
F_34 ( V_58 , V_595 ,
V_584 -> V_596 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_597 ) &&
F_34 ( V_58 , V_598 ,
V_584 -> V_599 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_600 ) &&
F_34 ( V_58 , V_601 ,
V_584 -> V_602 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_603 ) &&
F_57 ( V_58 , V_604 , V_584 -> V_605 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_606 ) &&
F_57 ( V_58 , V_607 , V_584 -> V_608 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_609 ) &&
F_56 ( V_58 , V_610 ,
V_584 -> V_611 ) )
goto V_63;
switch ( V_7 -> V_18 . V_612 ) {
case V_613 :
if ( ( V_584 -> V_590 & V_614 ) &&
F_56 ( V_58 , V_615 ,
V_584 -> signal ) )
goto V_63;
if ( ( V_584 -> V_590 & V_616 ) &&
F_56 ( V_58 , V_617 ,
V_584 -> V_618 ) )
goto V_63;
break;
default:
break;
}
if ( V_584 -> V_590 & V_619 ) {
if ( ! F_119 ( V_58 , & V_584 -> V_620 ,
V_621 ) )
goto V_63;
}
if ( V_584 -> V_590 & V_622 ) {
if ( ! F_119 ( V_58 , & V_584 -> V_623 ,
V_624 ) )
goto V_63;
}
if ( ( V_584 -> V_590 & V_625 ) &&
F_34 ( V_58 , V_626 ,
V_584 -> V_627 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_628 ) &&
F_34 ( V_58 , V_629 ,
V_584 -> V_630 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_631 ) &&
F_34 ( V_58 , V_632 ,
V_584 -> V_633 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_634 ) &&
F_34 ( V_58 , V_635 ,
V_584 -> V_636 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_637 ) &&
F_34 ( V_58 , V_638 ,
V_584 -> V_639 ) )
goto V_63;
if ( V_584 -> V_590 & V_640 ) {
V_586 = F_50 ( V_58 , V_641 ) ;
if ( ! V_586 )
goto V_63;
if ( ( ( V_584 -> V_586 . V_56 & V_642 ) &&
F_35 ( V_58 , V_643 ) ) ||
( ( V_584 -> V_586 . V_56 & V_644 ) &&
F_35 ( V_58 , V_645 ) ) ||
( ( V_584 -> V_586 . V_56 & V_646 ) &&
F_35 ( V_58 , V_647 ) ) ||
F_56 ( V_58 , V_648 ,
V_584 -> V_586 . V_534 ) ||
F_57 ( V_58 , V_649 ,
V_584 -> V_586 . V_414 ) )
goto V_63;
F_51 ( V_58 , V_586 ) ;
}
if ( ( V_584 -> V_590 & V_650 ) &&
F_58 ( V_58 , V_651 ,
sizeof( struct V_557 ) ,
& V_584 -> V_558 ) )
goto V_63;
if ( ( V_584 -> V_590 & V_652 ) &&
F_88 ( V_58 , V_653 ,
V_584 -> V_654 ) )
goto V_63;
F_51 ( V_58 , V_585 ) ;
if ( ( V_584 -> V_590 & V_655 ) &&
F_58 ( V_58 , V_511 , V_584 -> V_656 ,
V_584 -> V_657 ) )
goto V_63;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
static int F_122 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_583 V_584 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_492 [ V_451 ] ;
int V_658 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_223 -> V_659 ) {
V_47 = - V_413 ;
goto V_660;
}
while ( 1 ) {
memset ( & V_584 , 0 , sizeof( V_584 ) ) ;
V_47 = V_46 -> V_223 -> V_659 ( & V_46 -> V_18 , V_20 , V_658 ,
V_492 , & V_584 ) ;
if ( V_47 == - V_499 )
break;
if ( V_47 )
goto V_660;
if ( F_121 ( V_45 ,
F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_383 , V_384 ,
V_46 , V_20 , V_492 ,
& V_584 ) < 0 )
goto V_460;
V_658 ++ ;
}
V_460:
V_35 -> args [ 1 ] = V_658 ;
V_47 = V_45 -> V_52 ;
V_660:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_123 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_583 V_584 ;
struct V_44 * V_58 ;
T_2 * V_492 = NULL ;
int V_47 ;
memset ( & V_584 , 0 , sizeof( V_584 ) ) ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
V_492 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( ! V_7 -> V_223 -> V_661 )
return - V_413 ;
V_47 = V_7 -> V_223 -> V_661 ( & V_7 -> V_18 , V_46 , V_492 , & V_584 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_121 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_7 , V_46 , V_492 , & V_584 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static struct V_26 * F_124 ( struct V_30 * V_31 ,
struct V_6 * V_7 )
{
struct V_4 * V_662 = V_31 -> V_5 [ V_663 ] ;
struct V_26 * V_664 ;
int V_529 ;
if ( ! V_662 )
return NULL ;
V_664 = F_12 ( F_84 ( V_31 ) , F_4 ( V_662 ) ) ;
if ( ! V_664 )
return F_3 ( - V_24 ) ;
if ( ! V_664 -> V_29 || V_664 -> V_29 -> V_18 != & V_7 -> V_18 ) {
V_529 = - V_16 ;
goto error;
}
if ( ! F_82 ( V_664 ) ) {
V_529 = - V_428 ;
goto error;
}
return V_664 ;
error:
F_14 ( V_664 ) ;
return F_3 ( V_529 ) ;
}
static int F_125 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_554 V_119 ;
T_2 * V_492 = NULL ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_665 = - 1 ;
V_119 . V_611 = - 1 ;
if ( V_31 -> V_5 [ V_666 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
V_492 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( V_31 -> V_5 [ V_667 ] ) {
V_119 . V_668 =
F_29 ( V_31 -> V_5 [ V_667 ] ) ;
V_119 . V_669 =
F_30 ( V_31 -> V_5 [ V_667 ] ) ;
}
if ( V_31 -> V_5 [ V_670 ] )
V_119 . V_665 =
F_72 ( V_31 -> V_5 [ V_670 ] ) ;
if ( V_31 -> V_5 [ V_671 ] )
V_119 . V_672 =
F_29 ( V_31 -> V_5 [ V_671 ] ) ;
if ( ! V_7 -> V_223 -> V_673 )
return - V_413 ;
if ( F_117 ( V_31 , V_46 -> V_29 -> V_121 , & V_119 ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_674 ] )
V_119 . V_675 =
F_39 ( V_31 -> V_5 [ V_674 ] ) ;
if ( V_31 -> V_5 [ V_676 ] )
V_119 . V_611 =
F_39 ( V_31 -> V_5 [ V_676 ] ) ;
switch ( V_46 -> V_29 -> V_121 ) {
case V_122 :
case V_123 :
case V_124 :
if ( V_119 . V_675 )
return - V_16 ;
if ( V_119 . V_561 & F_118 ( V_570 ) )
return - V_16 ;
V_119 . V_559 &= ~ F_118 ( V_570 ) ;
if ( V_119 . V_559 &
~ ( F_118 ( V_566 ) |
F_118 ( V_567 ) |
F_118 ( V_568 ) |
F_118 ( V_569 ) ) )
return - V_16 ;
V_119 . V_677 = F_124 ( V_31 , V_7 ) ;
if ( F_16 ( V_119 . V_677 ) )
return F_24 ( V_119 . V_677 ) ;
break;
case V_130 :
case V_129 :
V_119 . V_559 &= ~ F_118 ( V_570 ) ;
case V_126 :
if ( V_119 . V_675 )
return - V_16 ;
if ( V_119 . V_672 )
return - V_16 ;
if ( V_119 . V_665 >= 0 )
return - V_16 ;
if ( V_119 . V_559 & ~ F_118 ( V_566 ) )
return - V_16 ;
break;
case V_125 :
if ( V_119 . V_677 )
return - V_16 ;
if ( V_119 . V_672 )
return - V_16 ;
if ( V_119 . V_665 >= 0 )
return - V_16 ;
if ( V_119 . V_559 &
~ ( F_118 ( V_571 ) |
F_118 ( V_569 ) |
F_118 ( V_566 ) ) )
return - V_16 ;
break;
default:
return - V_413 ;
}
V_47 = V_7 -> V_223 -> V_673 ( & V_7 -> V_18 , V_46 , V_492 , & V_119 ) ;
if ( V_119 . V_677 )
F_14 ( V_119 . V_677 ) ;
return V_47 ;
}
static int F_126 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_554 V_119 ;
T_2 * V_492 = NULL ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_670 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_667 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_666 ] )
return - V_16 ;
V_492 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_119 . V_668 =
F_29 ( V_31 -> V_5 [ V_667 ] ) ;
V_119 . V_669 =
F_30 ( V_31 -> V_5 [ V_667 ] ) ;
V_119 . V_665 =
F_72 ( V_31 -> V_5 [ V_670 ] ) ;
V_119 . V_678 = F_72 ( V_31 -> V_5 [ V_666 ] ) ;
if ( ! V_119 . V_678 || V_119 . V_678 > V_679 )
return - V_16 ;
if ( V_31 -> V_5 [ V_671 ] )
V_119 . V_672 =
F_29 ( V_31 -> V_5 [ V_671 ] ) ;
if ( V_31 -> V_5 [ V_674 ] )
V_119 . V_675 =
F_39 ( V_31 -> V_5 [ V_674 ] ) ;
if ( ! V_7 -> V_223 -> V_268 )
return - V_413 ;
if ( F_117 ( V_31 , V_46 -> V_29 -> V_121 , & V_119 ) )
return - V_16 ;
switch ( V_46 -> V_29 -> V_121 ) {
case V_122 :
case V_123 :
case V_124 :
if ( ( V_7 -> V_18 . V_56 & V_201 ) &&
( V_119 . V_561 & F_118 ( V_568 ) ) &&
V_31 -> V_5 [ V_680 ] ) {
struct V_4 * V_78 [ V_681 + 1 ] ;
struct V_4 * V_461 ;
V_461 = V_31 -> V_5 [ V_680 ] ;
V_47 = F_38 ( V_78 , V_681 , V_461 ,
V_682 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_683 ] )
V_119 . V_684 =
F_39 ( V_78 [ V_683 ] ) ;
if ( V_119 . V_684 &
~ V_685 )
return - V_16 ;
if ( V_78 [ V_686 ] )
V_119 . V_687 =
F_39 ( V_78 [ V_686 ] ) ;
if ( V_119 . V_687 &
~ V_688 )
return - V_16 ;
V_119 . V_689 |= V_690 ;
}
if ( V_119 . V_561 & F_118 ( V_570 ) )
return - V_16 ;
V_119 . V_559 &= ~ F_118 ( V_570 ) ;
V_119 . V_677 = F_124 ( V_31 , V_7 ) ;
if ( F_16 ( V_119 . V_677 ) )
return F_24 ( V_119 . V_677 ) ;
break;
case V_125 :
if ( V_119 . V_561 & F_118 ( V_570 ) )
return - V_16 ;
break;
case V_129 :
if ( ! ( V_119 . V_561 & F_118 ( V_570 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_56 & V_205 ) )
return - V_413 ;
if ( ! ( V_7 -> V_18 . V_56 & V_207 ) )
return - V_413 ;
break;
default:
return - V_413 ;
}
V_47 = V_7 -> V_223 -> V_268 ( & V_7 -> V_18 , V_46 , V_492 , & V_119 ) ;
if ( V_119 . V_677 )
F_14 ( V_119 . V_677 ) ;
return V_47 ;
}
static int F_127 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 * V_492 = NULL ;
if ( V_31 -> V_5 [ V_419 ] )
V_492 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_123 &&
V_46 -> V_29 -> V_121 != V_125 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_691 )
return - V_413 ;
return V_7 -> V_223 -> V_691 ( & V_7 -> V_18 , V_46 , V_492 ) ;
}
static int F_128 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
T_2 * V_692 , T_2 * V_693 ,
struct V_694 * V_695 )
{
void * V_159 ;
struct V_4 * V_696 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_587 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_692 ) ||
F_58 ( V_58 , V_697 , V_451 , V_693 ) ||
F_34 ( V_58 , V_175 , V_695 -> V_588 ) )
goto V_63;
V_696 = F_50 ( V_58 , V_698 ) ;
if ( ! V_696 )
goto V_63;
if ( ( V_695 -> V_590 & V_699 ) &&
F_34 ( V_58 , V_700 ,
V_695 -> V_701 ) )
goto V_63;
if ( ( ( V_695 -> V_590 & V_702 ) &&
F_34 ( V_58 , V_703 , V_695 -> V_704 ) ) ||
( ( V_695 -> V_590 & V_705 ) &&
F_34 ( V_58 , V_706 ,
V_695 -> V_707 ) ) ||
( ( V_695 -> V_590 & V_708 ) &&
F_34 ( V_58 , V_709 ,
V_695 -> V_710 ) ) ||
( ( V_695 -> V_590 & V_711 ) &&
F_56 ( V_58 , V_712 ,
V_695 -> V_56 ) ) ||
( ( V_695 -> V_590 & V_713 ) &&
F_34 ( V_58 , V_714 ,
V_695 -> V_715 ) ) ||
( ( V_695 -> V_590 & V_716 ) &&
F_56 ( V_58 , V_717 ,
V_695 -> V_718 ) ) )
goto V_63;
F_51 ( V_58 , V_696 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
static int F_129 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_694 V_695 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_692 [ V_451 ] ;
T_2 V_693 [ V_451 ] ;
int V_719 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_223 -> V_720 ) {
V_47 = - V_413 ;
goto V_660;
}
if ( V_20 -> V_29 -> V_121 != V_125 ) {
V_47 = - V_413 ;
goto V_660;
}
while ( 1 ) {
V_47 = V_46 -> V_223 -> V_720 ( & V_46 -> V_18 , V_20 , V_719 ,
V_692 , V_693 , & V_695 ) ;
if ( V_47 == - V_499 )
break;
if ( V_47 )
goto V_660;
if ( F_128 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_383 , V_384 ,
V_20 , V_692 , V_693 ,
& V_695 ) < 0 )
goto V_460;
V_719 ++ ;
}
V_460:
V_35 -> args [ 1 ] = V_719 ;
V_47 = V_45 -> V_52 ;
V_660:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_130 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_694 V_695 ;
struct V_44 * V_58 ;
T_2 * V_692 = NULL ;
T_2 V_693 [ V_451 ] ;
memset ( & V_695 , 0 , sizeof( V_695 ) ) ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
V_692 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( ! V_7 -> V_223 -> V_721 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_125 )
return - V_413 ;
V_47 = V_7 -> V_223 -> V_721 ( & V_7 -> V_18 , V_46 , V_692 , V_693 , & V_695 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_128 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_46 , V_692 , V_693 , & V_695 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_131 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 * V_692 = NULL ;
T_2 * V_693 = NULL ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_697 ] )
return - V_16 ;
V_692 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_693 = F_29 ( V_31 -> V_5 [ V_697 ] ) ;
if ( ! V_7 -> V_223 -> V_722 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_125 )
return - V_413 ;
return V_7 -> V_223 -> V_722 ( & V_7 -> V_18 , V_46 , V_692 , V_693 ) ;
}
static int F_132 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 * V_692 = NULL ;
T_2 * V_693 = NULL ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_697 ] )
return - V_16 ;
V_692 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_693 = F_29 ( V_31 -> V_5 [ V_697 ] ) ;
if ( ! V_7 -> V_223 -> V_270 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_125 )
return - V_413 ;
return V_7 -> V_223 -> V_270 ( & V_7 -> V_18 , V_46 , V_692 , V_693 ) ;
}
static int F_133 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 * V_692 = NULL ;
if ( V_31 -> V_5 [ V_419 ] )
V_692 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( ! V_7 -> V_223 -> V_723 )
return - V_413 ;
return V_7 -> V_223 -> V_723 ( & V_7 -> V_18 , V_46 , V_692 ) ;
}
static int F_134 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_724 V_119 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_725 = - 1 ;
V_119 . V_726 = - 1 ;
V_119 . V_727 = - 1 ;
V_119 . V_728 = - 1 ;
V_119 . V_729 = - 1 ;
if ( V_31 -> V_5 [ V_730 ] )
V_119 . V_725 =
F_39 ( V_31 -> V_5 [ V_730 ] ) ;
if ( V_31 -> V_5 [ V_731 ] )
V_119 . V_726 =
F_39 ( V_31 -> V_5 [ V_731 ] ) ;
if ( V_31 -> V_5 [ V_732 ] )
V_119 . V_727 =
F_39 ( V_31 -> V_5 [ V_732 ] ) ;
if ( V_31 -> V_5 [ V_733 ] ) {
V_119 . V_734 =
F_29 ( V_31 -> V_5 [ V_733 ] ) ;
V_119 . V_735 =
F_30 ( V_31 -> V_5 [ V_733 ] ) ;
}
if ( V_31 -> V_5 [ V_736 ] )
V_119 . V_728 = ! ! F_39 ( V_31 -> V_5 [ V_736 ] ) ;
if ( V_31 -> V_5 [ V_737 ] )
V_119 . V_729 =
F_72 ( V_31 -> V_5 [ V_737 ] ) ;
if ( ! V_7 -> V_223 -> V_274 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_413 ;
return V_7 -> V_223 -> V_274 ( & V_7 -> V_18 , V_46 , & V_119 ) ;
}
static int F_135 ( struct V_4 * V_78 [] ,
struct V_738 * V_739 )
{
struct V_740 * V_741 = & V_739 -> V_741 ;
struct V_742 * V_743 = & V_739 -> V_743 ;
if ( ! V_78 [ V_744 ] )
return - V_16 ;
if ( ! V_78 [ V_745 ] )
return - V_16 ;
if ( ! V_78 [ V_746 ] )
return - V_16 ;
if ( ! V_78 [ V_747 ] )
return - V_16 ;
if ( ! V_78 [ V_748 ] )
return - V_16 ;
V_739 -> V_56 = F_4 ( V_78 [ V_744 ] ) ;
V_741 -> V_749 =
F_4 ( V_78 [ V_745 ] ) ;
V_741 -> V_750 =
F_4 ( V_78 [ V_746 ] ) ;
V_741 -> V_751 =
F_4 ( V_78 [ V_747 ] ) ;
V_743 -> V_752 =
F_4 ( V_78 [ V_748 ] ) ;
if ( V_78 [ V_753 ] )
V_743 -> V_754 =
F_4 ( V_78 [ V_753 ] ) ;
return 0 ;
}
static int F_136 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
int V_755 ;
char * V_120 = NULL ;
enum V_756 V_757 ;
F_8 ( & V_32 ) ;
if ( F_137 ( ! V_758 ) ) {
F_9 ( & V_32 ) ;
return - V_759 ;
}
F_9 ( & V_32 ) ;
if ( ! V_31 -> V_5 [ V_760 ] )
return - V_16 ;
V_120 = F_29 ( V_31 -> V_5 [ V_760 ] ) ;
if ( V_31 -> V_5 [ V_761 ] )
V_757 =
F_4 ( V_31 -> V_5 [ V_761 ] ) ;
else
V_757 = V_762 ;
switch ( V_757 ) {
case V_762 :
case V_763 :
break;
default:
return - V_16 ;
}
V_755 = F_138 ( V_120 , V_757 ) ;
return V_755 ;
}
static int F_139 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_764 V_765 ;
int V_47 = 0 ;
void * V_159 ;
struct V_4 * V_696 ;
struct V_44 * V_58 ;
if ( V_17 -> V_121 != V_125 )
return - V_413 ;
if ( ! V_7 -> V_223 -> V_766 )
return - V_413 ;
F_94 ( V_17 ) ;
if ( ! V_17 -> V_767 )
memcpy ( & V_765 , & V_768 , sizeof( V_765 ) ) ;
else
V_47 = V_7 -> V_223 -> V_766 ( & V_7 -> V_18 , V_46 ,
& V_765 ) ;
F_96 ( V_17 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_769 ) ;
if ( ! V_159 )
goto V_460;
V_696 = F_50 ( V_58 , V_770 ) ;
if ( ! V_696 )
goto V_63;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_57 ( V_58 , V_771 ,
V_765 . V_772 ) ||
F_57 ( V_58 , V_773 ,
V_765 . V_774 ) ||
F_57 ( V_58 , V_775 ,
V_765 . V_776 ) ||
F_57 ( V_58 , V_777 ,
V_765 . V_778 ) ||
F_56 ( V_58 , V_779 ,
V_765 . V_780 ) ||
F_56 ( V_58 , V_781 ,
V_765 . V_782 ) ||
F_56 ( V_58 , V_783 ,
V_765 . V_784 ) ||
F_56 ( V_58 , V_785 ,
V_765 . V_786 ) ||
F_34 ( V_58 , V_787 ,
V_765 . V_788 ) ||
F_56 ( V_58 , V_789 ,
V_765 . V_790 ) ||
F_34 ( V_58 , V_791 ,
V_765 . V_792 ) ||
F_57 ( V_58 , V_793 ,
V_765 . V_794 ) ||
F_34 ( V_58 , V_795 ,
V_765 . V_796 ) ||
F_57 ( V_58 , V_797 ,
V_765 . V_798 ) ||
F_57 ( V_58 , V_799 ,
V_765 . V_800 ) ||
F_57 ( V_58 , V_801 ,
V_765 . V_802 ) ||
F_56 ( V_58 , V_803 ,
V_765 . V_804 ) ||
F_57 ( V_58 , V_805 ,
V_765 . V_806 ) ||
F_56 ( V_58 , V_807 ,
V_765 . V_808 ) ||
F_56 ( V_58 , V_809 ,
V_765 . V_810 ) ||
F_34 ( V_58 , V_811 ,
V_765 . V_812 ) ||
F_34 ( V_58 , V_813 ,
V_765 . V_729 ) ||
F_34 ( V_58 , V_814 ,
V_765 . V_815 ) ||
F_57 ( V_58 , V_816 ,
V_765 . V_817 ) ||
F_57 ( V_58 , V_818 ,
V_765 . V_819 ) )
goto V_63;
F_51 ( V_58 , V_696 ) ;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
V_460:
F_69 ( V_58 ) ;
return - V_74 ;
}
static int F_140 ( struct V_30 * V_31 ,
struct V_764 * V_820 ,
V_23 * V_821 )
{
struct V_4 * V_78 [ V_822 + 1 ] ;
V_23 V_560 = 0 ;
#define F_141 ( T_6 , V_820 , T_7 , V_560 , T_8 , T_9 ) \
do {\
if (table[attr_num]) {\
cfg->param = nla_fn(table[attr_num]); \
mask |= (1 << (attr_num - 1)); \
} \
} while (0);\
if (!info->attrs[NL80211_ATTR_MESH_CONFIG])
return - V_16 ;
if ( F_38 ( V_78 , V_822 ,
V_31 -> V_5 [ V_770 ] ,
V_823 ) )
return - V_16 ;
F_95 ( V_822 > 32 ) ;
F_141 ( V_78 , V_820 , V_772 ,
V_560 , V_771 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_774 ,
V_560 , V_773 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_776 ,
V_560 , V_775 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_778 ,
V_560 , V_777 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_780 ,
V_560 , V_779 ,
F_39 ) ;
F_141 ( V_78 , V_820 , V_782 ,
V_560 , V_781 , F_39 ) ;
F_141 ( V_78 , V_820 , V_784 ,
V_560 , V_783 ,
F_39 ) ;
F_141 ( V_78 , V_820 , V_786 ,
V_560 , V_785 ,
F_39 ) ;
F_141 ( V_78 , V_820 , V_788 , V_560 ,
V_787 ,
F_4 ) ;
F_141 ( V_78 , V_820 , V_790 ,
V_560 , V_789 ,
F_39 ) ;
F_141 ( V_78 , V_820 , V_792 ,
V_560 , V_791 ,
F_4 ) ;
F_141 ( V_78 , V_820 , V_794 ,
V_560 , V_793 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_796 , V_560 ,
V_795 ,
F_4 ) ;
F_141 ( V_78 , V_820 , V_798 ,
V_560 , V_797 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_800 ,
V_560 , V_799 ,
F_72 ) ;
F_141 ( V_78 , V_820 ,
V_802 , V_560 ,
V_801 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_804 , V_560 ,
V_803 , F_39 ) ;
F_141 ( V_78 , V_820 , V_806 , V_560 ,
V_805 ,
F_72 ) ;
F_141 ( V_78 , V_820 ,
V_808 , V_560 ,
V_807 ,
F_39 ) ;
F_141 ( V_78 , V_820 , V_810 ,
V_560 , V_809 ,
F_39 ) ;
F_141 ( V_78 , V_820 , V_812 ,
V_560 , V_811 ,
F_4 ) ;
F_141 ( V_78 , V_820 , V_729 ,
V_560 , V_813 ,
F_72 ) ;
F_141 ( V_78 , V_820 , V_815 ,
V_560 ,
V_814 ,
F_4 ) ;
F_141 ( V_78 , V_820 , V_817 ,
V_560 , V_816 ,
F_72 ) ;
F_141 ( V_78 , V_820 ,
V_819 , V_560 ,
V_818 ,
F_72 ) ;
if ( V_821 )
* V_821 = V_560 ;
return 0 ;
#undef F_141
}
static int F_142 ( struct V_30 * V_31 ,
struct V_824 * V_825 )
{
struct V_4 * V_78 [ V_826 + 1 ] ;
if ( ! V_31 -> V_5 [ V_827 ] )
return - V_16 ;
if ( F_38 ( V_78 , V_826 ,
V_31 -> V_5 [ V_827 ] ,
V_828 ) )
return - V_16 ;
if ( V_78 [ V_829 ] )
V_825 -> V_830 =
( F_39 ( V_78 [ V_829 ] ) ) ?
V_831 :
V_832 ;
if ( V_78 [ V_833 ] )
V_825 -> V_834 =
( F_39 ( V_78 [ V_833 ] ) ) ?
V_835 :
V_836 ;
if ( V_78 [ V_837 ] )
V_825 -> V_838 =
( F_39 ( V_78 [ V_837 ] ) ) ?
V_839 :
V_840 ;
if ( V_78 [ V_841 ] ) {
struct V_4 * V_842 =
V_78 [ V_841 ] ;
if ( ! F_28 ( V_842 ) )
return - V_16 ;
V_825 -> V_843 = F_29 ( V_842 ) ;
V_825 -> V_844 = F_30 ( V_842 ) ;
}
V_825 -> V_845 = F_143 ( V_78 [ V_846 ] ) ;
V_825 -> V_847 = F_143 ( V_78 [ V_848 ] ) ;
return 0 ;
}
static int F_144 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_764 V_820 ;
V_23 V_560 ;
int V_47 ;
if ( V_17 -> V_121 != V_125 )
return - V_413 ;
if ( ! V_7 -> V_223 -> V_272 )
return - V_413 ;
V_47 = F_140 ( V_31 , & V_820 , & V_560 ) ;
if ( V_47 )
return V_47 ;
F_94 ( V_17 ) ;
if ( ! V_17 -> V_767 )
V_47 = - V_128 ;
if ( ! V_47 )
V_47 = V_7 -> V_223 -> V_272 ( & V_7 -> V_18 , V_46 ,
V_560 , & V_820 ) ;
F_96 ( V_17 ) ;
return V_47 ;
}
static int F_145 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
void * V_159 = NULL ;
struct V_4 * V_849 ;
unsigned int V_135 ;
int V_47 = - V_16 ;
F_8 ( & V_32 ) ;
if ( ! V_758 )
goto V_460;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 ) {
V_47 = - V_74 ;
goto V_460;
}
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_850 ) ;
if ( ! V_159 )
goto V_851;
if ( F_54 ( V_58 , V_760 ,
V_758 -> V_852 ) ||
( V_758 -> V_853 &&
F_56 ( V_58 , V_854 ,
V_758 -> V_853 ) ) )
goto V_63;
if ( F_146 () &&
F_34 ( V_58 , V_761 ,
V_763 ) )
goto V_63;
V_849 = F_50 ( V_58 , V_855 ) ;
if ( ! V_849 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_758 -> V_856 ; V_135 ++ ) {
struct V_4 * V_857 ;
const struct V_738 * V_739 ;
const struct V_740 * V_741 ;
const struct V_742 * V_743 ;
V_739 = & V_758 -> V_858 [ V_135 ] ;
V_741 = & V_739 -> V_741 ;
V_743 = & V_739 -> V_743 ;
V_857 = F_50 ( V_58 , V_135 ) ;
if ( ! V_857 )
goto V_63;
if ( F_34 ( V_58 , V_744 ,
V_739 -> V_56 ) ||
F_34 ( V_58 , V_745 ,
V_741 -> V_749 ) ||
F_34 ( V_58 , V_746 ,
V_741 -> V_750 ) ||
F_34 ( V_58 , V_747 ,
V_741 -> V_751 ) ||
F_34 ( V_58 , V_753 ,
V_743 -> V_754 ) ||
F_34 ( V_58 , V_748 ,
V_743 -> V_752 ) )
goto V_63;
F_51 ( V_58 , V_857 ) ;
}
F_51 ( V_58 , V_849 ) ;
F_62 ( V_58 , V_159 ) ;
V_47 = F_70 ( V_58 , V_31 ) ;
goto V_460;
V_63:
F_63 ( V_58 , V_159 ) ;
V_851:
F_69 ( V_58 ) ;
V_47 = - V_381 ;
V_460:
F_9 ( & V_32 ) ;
return V_47 ;
}
static int F_147 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_859 + 1 ] ;
struct V_4 * V_857 ;
char * V_852 = NULL ;
int V_860 = 0 , V_755 = 0 ;
V_23 V_861 = 0 , V_862 = 0 , V_863 ;
T_2 V_853 = 0 ;
struct V_864 * V_865 = NULL ;
if ( ! V_31 -> V_5 [ V_760 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_855 ] )
return - V_16 ;
V_852 = F_29 ( V_31 -> V_5 [ V_760 ] ) ;
if ( V_31 -> V_5 [ V_854 ] )
V_853 = F_39 ( V_31 -> V_5 [ V_854 ] ) ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_861 ++ ;
if ( V_861 > V_866 )
return - V_16 ;
}
F_8 ( & V_32 ) ;
if ( ! F_148 ( V_852 ) ) {
V_755 = - V_16 ;
goto V_867;
}
V_863 = sizeof( struct V_864 ) +
( V_861 * sizeof( struct V_738 ) ) ;
V_865 = F_43 ( V_863 , V_117 ) ;
if ( ! V_865 ) {
V_755 = - V_118 ;
goto V_867;
}
V_865 -> V_856 = V_861 ;
V_865 -> V_852 [ 0 ] = V_852 [ 0 ] ;
V_865 -> V_852 [ 1 ] = V_852 [ 1 ] ;
if ( F_149 ( V_853 ) )
V_865 -> V_853 = V_853 ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_86 ( V_78 , V_859 ,
F_29 ( V_857 ) , F_30 ( V_857 ) ,
V_868 ) ;
V_755 = F_135 ( V_78 , & V_865 -> V_858 [ V_862 ] ) ;
if ( V_755 )
goto V_867;
V_862 ++ ;
if ( V_862 > V_866 ) {
V_755 = - V_16 ;
goto V_867;
}
}
F_150 ( V_862 != V_861 ) ;
V_755 = F_151 ( V_865 ) ;
F_9 ( & V_32 ) ;
return V_755 ;
V_867:
F_9 ( & V_32 ) ;
F_46 ( V_865 ) ;
return V_755 ;
}
static int F_152 ( struct V_4 * V_869 )
{
struct V_4 * V_870 , * V_871 ;
int V_250 = 0 , V_872 , V_873 ;
F_44 (attr1, freqs, tmp1) {
V_250 ++ ;
F_44 (attr2, freqs, tmp2)
if ( V_870 != V_871 &&
F_4 ( V_870 ) == F_4 ( V_871 ) )
return 0 ;
}
return V_250 ;
}
static int F_153 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
struct V_874 * V_875 ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_876 = 0 , V_250 , V_135 ;
T_10 V_844 ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_223 -> V_877 )
return - V_413 ;
if ( V_7 -> V_878 )
return - V_415 ;
if ( V_31 -> V_5 [ V_879 ] ) {
V_250 = F_152 (
V_31 -> V_5 [ V_879 ] ) ;
if ( ! V_250 )
return - V_16 ;
} else {
enum V_167 V_168 ;
V_250 = 0 ;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ )
if ( V_18 -> V_233 [ V_168 ] )
V_250 += V_18 -> V_233 [ V_168 ] -> V_250 ;
}
if ( V_31 -> V_5 [ V_880 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_876 ++ ;
if ( V_876 > V_18 -> V_188 )
return - V_16 ;
if ( V_31 -> V_5 [ V_511 ] )
V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
else
V_844 = 0 ;
if ( V_844 > V_18 -> V_192 )
return - V_16 ;
V_875 = F_43 ( sizeof( * V_875 )
+ sizeof( * V_875 -> V_881 ) * V_876
+ sizeof( * V_875 -> V_251 ) * V_250
+ V_844 , V_117 ) ;
if ( ! V_875 )
return - V_118 ;
if ( V_876 )
V_875 -> V_881 = ( void * ) & V_875 -> V_251 [ V_250 ] ;
V_875 -> V_876 = V_876 ;
if ( V_844 ) {
if ( V_875 -> V_881 )
V_875 -> V_843 = ( void * ) ( V_875 -> V_881 + V_876 ) ;
else
V_875 -> V_843 = ( void * ) ( V_875 -> V_251 + V_250 ) ;
}
V_135 = 0 ;
if ( V_31 -> V_5 [ V_879 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_59 * V_60 ;
V_60 = F_154 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_882;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_875 -> V_251 [ V_135 ] = V_60 ;
V_135 ++ ;
}
} else {
enum V_167 V_168 ;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ ) {
int V_137 ;
if ( ! V_18 -> V_233 [ V_168 ] )
continue;
for ( V_137 = 0 ; V_137 < V_18 -> V_233 [ V_168 ] -> V_250 ; V_137 ++ ) {
struct V_59 * V_60 ;
V_60 = & V_18 -> V_233 [ V_168 ] -> V_251 [ V_137 ] ;
if ( V_60 -> V_56 & V_64 )
continue;
V_875 -> V_251 [ V_135 ] = V_60 ;
V_135 ++ ;
}
}
}
if ( ! V_135 ) {
V_47 = - V_16 ;
goto V_882;
}
V_875 -> V_250 = V_135 ;
V_135 = 0 ;
if ( V_31 -> V_5 [ V_880 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_30 ( V_50 ) > V_478 ) {
V_47 = - V_16 ;
goto V_882;
}
V_875 -> V_881 [ V_135 ] . V_536 = F_30 ( V_50 ) ;
memcpy ( V_875 -> V_881 [ V_135 ] . V_481 , F_29 ( V_50 ) , F_30 ( V_50 ) ) ;
V_135 ++ ;
}
}
if ( V_31 -> V_5 [ V_511 ] ) {
V_875 -> V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
memcpy ( ( void * ) V_875 -> V_843 ,
F_29 ( V_31 -> V_5 [ V_511 ] ) ,
V_875 -> V_844 ) ;
}
for ( V_135 = 0 ; V_135 < V_232 ; V_135 ++ )
if ( V_18 -> V_233 [ V_135 ] )
V_875 -> V_883 [ V_135 ] =
( 1 << V_18 -> V_233 [ V_135 ] -> V_253 ) - 1 ;
if ( V_31 -> V_5 [ V_884 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_167 V_168 = F_155 ( V_50 ) ;
if ( V_168 < 0 || V_168 >= V_232 ) {
V_47 = - V_16 ;
goto V_882;
}
V_47 = F_156 ( V_18 -> V_233 [ V_168 ] ,
F_29 ( V_50 ) ,
F_30 ( V_50 ) ,
& V_875 -> V_883 [ V_168 ] ) ;
if ( V_47 )
goto V_882;
}
}
V_875 -> V_885 =
F_143 ( V_31 -> V_5 [ V_886 ] ) ;
V_875 -> V_17 = V_17 ;
V_875 -> V_18 = & V_7 -> V_18 ;
V_7 -> V_878 = V_875 ;
V_47 = V_7 -> V_223 -> V_877 ( & V_7 -> V_18 , V_875 ) ;
if ( ! V_47 ) {
F_157 ( V_7 , V_17 ) ;
if ( V_17 -> V_20 )
F_158 ( V_17 -> V_20 ) ;
} else {
V_882:
V_7 -> V_878 = NULL ;
F_46 ( V_875 ) ;
}
return V_47 ;
}
static int F_159 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_887 * V_875 ;
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_876 = 0 , V_888 = 0 , V_250 , V_135 ;
V_23 V_889 ;
enum V_167 V_168 ;
T_10 V_844 ;
struct V_4 * V_78 [ V_890 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_56 & V_313 ) ||
! V_7 -> V_223 -> V_314 )
return - V_413 ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_891 ] )
return - V_16 ;
V_889 = F_4 ( V_31 -> V_5 [ V_891 ] ) ;
if ( V_889 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_879 ] ) {
V_250 = F_152 (
V_31 -> V_5 [ V_879 ] ) ;
if ( ! V_250 )
return - V_16 ;
} else {
V_250 = 0 ;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ )
if ( V_18 -> V_233 [ V_168 ] )
V_250 += V_18 -> V_233 [ V_168 ] -> V_250 ;
}
if ( V_31 -> V_5 [ V_880 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_876 ++ ;
if ( V_876 > V_18 -> V_190 )
return - V_16 ;
if ( V_31 -> V_5 [ V_892 ] )
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_888 ++ ;
if ( V_888 > V_18 -> V_196 )
return - V_16 ;
if ( V_31 -> V_5 [ V_511 ] )
V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
else
V_844 = 0 ;
if ( V_844 > V_18 -> V_194 )
return - V_16 ;
F_8 ( & V_7 -> V_893 ) ;
if ( V_7 -> V_894 ) {
V_47 = - V_759 ;
goto V_460;
}
V_875 = F_43 ( sizeof( * V_875 )
+ sizeof( * V_875 -> V_881 ) * V_876
+ sizeof( * V_875 -> V_895 ) * V_888
+ sizeof( * V_875 -> V_251 ) * V_250
+ V_844 , V_117 ) ;
if ( ! V_875 ) {
V_47 = - V_118 ;
goto V_460;
}
if ( V_876 )
V_875 -> V_881 = ( void * ) & V_875 -> V_251 [ V_250 ] ;
V_875 -> V_876 = V_876 ;
if ( V_844 ) {
if ( V_875 -> V_881 )
V_875 -> V_843 = ( void * ) ( V_875 -> V_881 + V_876 ) ;
else
V_875 -> V_843 = ( void * ) ( V_875 -> V_251 + V_250 ) ;
}
if ( V_888 ) {
if ( V_875 -> V_843 )
V_875 -> V_895 = ( void * ) ( V_875 -> V_843 + V_844 ) ;
else if ( V_875 -> V_881 )
V_875 -> V_895 =
( void * ) ( V_875 -> V_881 + V_876 ) ;
else
V_875 -> V_895 =
( void * ) ( V_875 -> V_251 + V_250 ) ;
}
V_875 -> V_888 = V_888 ;
V_135 = 0 ;
if ( V_31 -> V_5 [ V_879 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_59 * V_60 ;
V_60 = F_154 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_882;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_875 -> V_251 [ V_135 ] = V_60 ;
V_135 ++ ;
}
} else {
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ ) {
int V_137 ;
if ( ! V_18 -> V_233 [ V_168 ] )
continue;
for ( V_137 = 0 ; V_137 < V_18 -> V_233 [ V_168 ] -> V_250 ; V_137 ++ ) {
struct V_59 * V_60 ;
V_60 = & V_18 -> V_233 [ V_168 ] -> V_251 [ V_137 ] ;
if ( V_60 -> V_56 & V_64 )
continue;
V_875 -> V_251 [ V_135 ] = V_60 ;
V_135 ++ ;
}
}
}
if ( ! V_135 ) {
V_47 = - V_16 ;
goto V_882;
}
V_875 -> V_250 = V_135 ;
V_135 = 0 ;
if ( V_31 -> V_5 [ V_880 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_30 ( V_50 ) > V_478 ) {
V_47 = - V_16 ;
goto V_882;
}
V_875 -> V_881 [ V_135 ] . V_536 = F_30 ( V_50 ) ;
memcpy ( V_875 -> V_881 [ V_135 ] . V_481 , F_29 ( V_50 ) ,
F_30 ( V_50 ) ) ;
V_135 ++ ;
}
}
V_135 = 0 ;
if ( V_31 -> V_5 [ V_892 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_481 , * V_896 ;
F_86 ( V_78 , V_890 ,
F_29 ( V_50 ) , F_30 ( V_50 ) ,
V_897 ) ;
V_481 = V_78 [ V_898 ] ;
if ( V_481 ) {
if ( F_30 ( V_481 ) > V_478 ) {
V_47 = - V_16 ;
goto V_882;
}
memcpy ( V_875 -> V_895 [ V_135 ] . V_481 . V_481 ,
F_29 ( V_481 ) , F_30 ( V_481 ) ) ;
V_875 -> V_895 [ V_135 ] . V_481 . V_536 =
F_30 ( V_481 ) ;
}
V_896 = V_78 [ V_899 ] ;
if ( V_896 )
V_875 -> V_900 = F_4 ( V_896 ) ;
else
V_875 -> V_900 =
V_901 ;
V_135 ++ ;
}
}
if ( V_31 -> V_5 [ V_511 ] ) {
V_875 -> V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
memcpy ( ( void * ) V_875 -> V_843 ,
F_29 ( V_31 -> V_5 [ V_511 ] ) ,
V_875 -> V_844 ) ;
}
V_875 -> V_46 = V_46 ;
V_875 -> V_18 = & V_7 -> V_18 ;
V_875 -> V_889 = V_889 ;
V_47 = V_7 -> V_223 -> V_314 ( & V_7 -> V_18 , V_46 , V_875 ) ;
if ( ! V_47 ) {
V_7 -> V_894 = V_875 ;
F_160 ( V_7 , V_46 ,
V_902 ) ;
goto V_460;
}
V_882:
F_46 ( V_875 ) ;
V_460:
F_9 ( & V_7 -> V_893 ) ;
return V_47 ;
}
static int F_161 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
if ( ! ( V_7 -> V_18 . V_56 & V_313 ) ||
! V_7 -> V_223 -> V_903 )
return - V_413 ;
F_8 ( & V_7 -> V_893 ) ;
V_47 = F_162 ( V_7 , false ) ;
F_9 ( & V_7 -> V_893 ) ;
return V_47 ;
}
static int F_163 ( struct V_44 * V_58 , struct V_34 * V_35 ,
V_23 V_55 , int V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_904 * V_905 )
{
struct V_906 * V_36 = & V_905 -> V_907 ;
void * V_159 ;
struct V_4 * V_908 ;
F_48 ( V_17 ) ;
V_159 = F_31 ( V_58 , F_66 ( V_35 -> V_45 ) . V_54 , V_55 , V_56 ,
V_909 ) ;
if ( ! V_159 )
return - 1 ;
F_164 ( V_35 , V_159 , & V_39 ) ;
if ( F_34 ( V_58 , V_175 , V_7 -> V_910 ) ||
F_34 ( V_58 , V_10 , V_17 -> V_20 -> V_21 ) )
goto V_63;
V_908 = F_50 ( V_58 , V_911 ) ;
if ( ! V_908 )
goto V_63;
if ( ( ! F_165 ( V_36 -> V_418 ) &&
F_58 ( V_58 , V_912 , V_451 , V_36 -> V_418 ) ) ||
( V_36 -> V_913 && V_36 -> V_914 &&
F_58 ( V_58 , V_915 ,
V_36 -> V_914 ,
V_36 -> V_913 ) ) ||
( V_36 -> V_519 && V_36 -> V_916 &&
V_36 -> V_519 != V_36 -> V_913 &&
F_58 ( V_58 , V_917 ,
V_36 -> V_916 , V_36 -> V_519 ) ) )
goto V_63;
if ( V_36 -> V_918 &&
F_88 ( V_58 , V_919 , V_36 -> V_918 ) )
goto V_63;
if ( V_36 -> V_414 &&
F_57 ( V_58 , V_920 , V_36 -> V_414 ) )
goto V_63;
if ( F_57 ( V_58 , V_921 , V_36 -> V_922 ) ||
F_34 ( V_58 , V_923 , V_36 -> V_410 -> V_62 ) ||
F_34 ( V_58 , V_924 ,
F_166 ( V_925 - V_905 -> V_926 ) ) )
goto V_63;
switch ( V_7 -> V_18 . V_612 ) {
case V_613 :
if ( F_34 ( V_58 , V_927 , V_36 -> signal ) )
goto V_63;
break;
case V_928 :
if ( F_56 ( V_58 , V_929 , V_36 -> signal ) )
goto V_63;
break;
default:
break;
}
switch ( V_17 -> V_121 ) {
case V_130 :
case V_129 :
if ( V_905 == V_17 -> V_127 &&
F_34 ( V_58 , V_930 ,
V_931 ) )
goto V_63;
break;
case V_126 :
if ( V_905 == V_17 -> V_127 &&
F_34 ( V_58 , V_930 ,
V_932 ) )
goto V_63;
break;
default:
break;
}
F_51 ( V_58 , V_908 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
static int F_167 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
struct V_26 * V_46 ;
struct V_904 * V_877 ;
struct V_1 * V_17 ;
int V_382 = V_35 -> args [ 1 ] , V_88 = 0 ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_7 , & V_46 ) ;
if ( V_47 )
return V_47 ;
V_17 = V_46 -> V_29 ;
F_94 ( V_17 ) ;
F_168 ( & V_7 -> V_933 ) ;
F_169 ( V_7 ) ;
V_35 -> V_55 = V_7 -> V_910 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_88 <= V_382 )
continue;
if ( F_163 ( V_45 , V_35 ,
V_35 -> V_37 -> V_383 , V_384 ,
V_7 , V_17 , V_877 ) < 0 ) {
V_88 -- ;
break;
}
}
F_170 ( & V_7 -> V_933 ) ;
F_96 ( V_17 ) ;
V_35 -> args [ 1 ] = V_88 ;
F_26 ( V_7 ) ;
return V_45 -> V_52 ;
}
static int F_171 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
struct V_934 * V_935 )
{
void * V_159 ;
struct V_4 * V_936 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 ,
V_937 ) ;
if ( ! V_159 )
return - V_118 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) )
goto V_63;
V_936 = F_50 ( V_58 , V_938 ) ;
if ( ! V_936 )
goto V_63;
if ( F_34 ( V_58 , V_939 ,
V_935 -> V_410 -> V_62 ) )
goto V_63;
if ( ( V_935 -> V_590 & V_940 ) &&
F_56 ( V_58 , V_941 , V_935 -> V_942 ) )
goto V_63;
if ( ( V_935 -> V_590 & V_943 ) &&
F_35 ( V_58 , V_944 ) )
goto V_63;
if ( ( V_935 -> V_590 & V_945 ) &&
F_88 ( V_58 , V_946 ,
V_935 -> V_947 ) )
goto V_63;
if ( ( V_935 -> V_590 & V_948 ) &&
F_88 ( V_58 , V_949 ,
V_935 -> V_950 ) )
goto V_63;
if ( ( V_935 -> V_590 & V_951 ) &&
F_88 ( V_58 , V_952 ,
V_935 -> V_953 ) )
goto V_63;
if ( ( V_935 -> V_590 & V_954 ) &&
F_88 ( V_58 , V_955 ,
V_935 -> V_956 ) )
goto V_63;
if ( ( V_935 -> V_590 & V_957 ) &&
F_88 ( V_58 , V_958 ,
V_935 -> V_959 ) )
goto V_63;
F_51 ( V_58 , V_936 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
static int F_172 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_934 V_935 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
int V_960 = V_35 -> args [ 1 ] ;
int V_36 ;
V_36 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_46 -> V_223 -> V_961 ) {
V_36 = - V_413 ;
goto V_660;
}
while ( 1 ) {
struct V_59 * V_60 ;
V_36 = V_46 -> V_223 -> V_961 ( & V_46 -> V_18 , V_20 , V_960 ,
& V_935 ) ;
if ( V_36 == - V_499 )
break;
if ( V_36 )
goto V_660;
if ( ! V_935 . V_410 ) {
V_36 = - V_16 ;
goto V_460;
}
V_60 = F_154 ( & V_46 -> V_18 ,
V_935 . V_410 -> V_62 ) ;
if ( ! V_60 || V_60 -> V_56 & V_64 ) {
V_960 ++ ;
continue;
}
if ( F_171 ( V_45 ,
F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_383 , V_384 ,
V_20 ,
& V_935 ) < 0 )
goto V_460;
V_960 ++ ;
}
V_460:
V_35 -> args [ 1 ] = V_960 ;
V_36 = V_45 -> V_52 ;
V_660:
F_26 ( V_46 ) ;
return V_36 ;
}
static bool F_111 ( enum V_962 V_545 )
{
return V_545 <= V_963 ;
}
static bool F_173 ( V_23 V_964 )
{
return ! ( V_964 & ~ ( V_965 |
V_966 ) ) ;
}
static int F_174 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_59 * V_60 ;
const T_2 * V_418 , * V_481 , * V_843 = NULL ;
int V_47 , V_536 , V_844 = 0 ;
enum V_962 V_545 ;
struct V_76 V_75 ;
bool V_967 ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_544 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_535 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_412 ] )
return - V_16 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 >= 0 ) {
if ( V_75 . type != - 1 && V_75 . type != V_495 )
return - V_16 ;
if ( ! V_75 . V_90 . V_75 || ! V_75 . V_90 . V_91 )
return - V_16 ;
if ( ( V_75 . V_90 . V_95 != V_968 ||
V_75 . V_90 . V_91 != V_969 ) &&
( V_75 . V_90 . V_95 != V_970 ||
V_75 . V_90 . V_91 != V_971 ) )
return - V_16 ;
if ( V_75 . V_88 > 4 )
return - V_16 ;
} else {
V_75 . V_90 . V_91 = 0 ;
V_75 . V_90 . V_75 = NULL ;
}
if ( V_75 . V_88 >= 0 ) {
int V_135 ;
bool V_972 = false ;
for ( V_135 = 0 ; V_135 < V_7 -> V_18 . V_210 ; V_135 ++ ) {
if ( V_75 . V_90 . V_95 == V_7 -> V_18 . V_211 [ V_135 ] ) {
V_972 = true ;
break;
}
}
if ( ! V_972 )
return - V_16 ;
}
if ( ! V_7 -> V_223 -> V_276 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_60 = F_154 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_412 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_481 = F_29 ( V_31 -> V_5 [ V_535 ] ) ;
V_536 = F_30 ( V_31 -> V_5 [ V_535 ] ) ;
if ( V_31 -> V_5 [ V_511 ] ) {
V_843 = F_29 ( V_31 -> V_5 [ V_511 ] ) ;
V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
}
V_545 = F_4 ( V_31 -> V_5 [ V_544 ] ) ;
if ( ! F_111 ( V_545 ) )
return - V_16 ;
V_967 = ! ! V_31 -> V_5 [ V_973 ] ;
if ( V_967 )
return 0 ;
return F_175 ( V_7 , V_46 , V_60 , V_545 , V_418 ,
V_481 , V_536 , V_843 , V_844 ,
V_75 . V_90 . V_75 , V_75 . V_90 . V_91 , V_75 . V_88 ) ;
}
static int F_112 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_974 * V_975 ,
int V_976 )
{
memset ( V_975 , 0 , sizeof( * V_975 ) ) ;
V_975 -> V_977 = V_31 -> V_5 [ V_978 ] ;
if ( V_31 -> V_5 [ V_215 ] ) {
T_3 V_979 ;
V_979 = F_72 (
V_31 -> V_5 [ V_215 ] ) ;
V_975 -> V_980 = F_176 ( V_979 ) ;
if ( ! ( V_7 -> V_18 . V_56 & V_214 ) &&
V_979 != V_981 )
return - V_16 ;
if ( V_31 -> V_5 [ V_982 ] )
V_975 -> V_983 = true ;
} else
V_975 -> V_980 = F_176 ( V_981 ) ;
if ( V_31 -> V_5 [ V_984 ] ) {
void * V_120 ;
int V_52 , V_135 ;
V_120 = F_29 ( V_31 -> V_5 [ V_984 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_984 ] ) ;
V_975 -> V_985 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_975 -> V_985 > V_976 )
return - V_16 ;
memcpy ( V_975 -> V_986 , V_120 , V_52 ) ;
for ( V_135 = 0 ; V_135 < V_975 -> V_985 ; V_135 ++ )
if ( ! F_177 (
& V_7 -> V_18 ,
V_975 -> V_986 [ V_135 ] ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_987 ] ) {
V_975 -> V_988 =
F_4 ( V_31 -> V_5 [ V_987 ] ) ;
if ( ! F_177 ( & V_7 -> V_18 ,
V_975 -> V_988 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_989 ] ) {
V_975 -> V_964 =
F_4 ( V_31 -> V_5 [ V_989 ] ) ;
if ( ! F_173 ( V_975 -> V_964 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_990 ] ) {
void * V_120 ;
int V_52 ;
V_120 = F_29 ( V_31 -> V_5 [ V_990 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_990 ] ) ;
V_975 -> V_991 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_975 -> V_991 > V_992 )
return - V_16 ;
memcpy ( V_975 -> V_993 , V_120 , V_52 ) ;
}
return 0 ;
}
static int F_178 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_974 V_547 ;
struct V_59 * V_60 ;
const T_2 * V_418 , * V_481 , * V_843 = NULL , * V_994 = NULL ;
int V_47 , V_536 , V_844 = 0 ;
bool V_995 = false ;
V_23 V_56 = 0 ;
struct V_996 * V_672 = NULL ;
struct V_996 * V_997 = NULL ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_419 ] ||
! V_31 -> V_5 [ V_535 ] ||
! V_31 -> V_5 [ V_412 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_278 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_60 = F_154 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_412 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_481 = F_29 ( V_31 -> V_5 [ V_535 ] ) ;
V_536 = F_30 ( V_31 -> V_5 [ V_535 ] ) ;
if ( V_31 -> V_5 [ V_511 ] ) {
V_843 = F_29 ( V_31 -> V_5 [ V_511 ] ) ;
V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
}
if ( V_31 -> V_5 [ V_998 ] ) {
enum V_999 V_1000 =
F_4 ( V_31 -> V_5 [ V_998 ] ) ;
if ( V_1000 == V_1001 )
V_995 = true ;
else if ( V_1000 != V_1002 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1003 ] )
V_994 = F_29 ( V_31 -> V_5 [ V_1003 ] ) ;
if ( F_143 ( V_31 -> V_5 [ V_1004 ] ) )
V_56 |= V_1005 ;
if ( V_31 -> V_5 [ V_380 ] )
V_997 =
F_29 ( V_31 -> V_5 [ V_380 ] ) ;
if ( V_31 -> V_5 [ V_671 ] ) {
if ( ! V_997 )
return - V_16 ;
V_672 = F_29 ( V_31 -> V_5 [ V_671 ] ) ;
}
V_47 = F_112 ( V_7 , V_31 , & V_547 , 1 ) ;
if ( ! V_47 )
V_47 = F_179 ( V_7 , V_46 , V_60 , V_418 , V_994 ,
V_481 , V_536 , V_843 , V_844 , V_995 ,
& V_547 , V_56 , V_672 ,
V_997 ) ;
return V_47 ;
}
static int F_180 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
const T_2 * V_843 = NULL , * V_418 ;
int V_844 = 0 ;
T_3 V_1006 ;
bool V_967 ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1007 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_280 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_1006 = F_72 ( V_31 -> V_5 [ V_1007 ] ) ;
if ( V_1006 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_511 ] ) {
V_843 = F_29 ( V_31 -> V_5 [ V_511 ] ) ;
V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
}
V_967 = ! ! V_31 -> V_5 [ V_973 ] ;
return F_181 ( V_7 , V_46 , V_418 , V_843 , V_844 , V_1006 ,
V_967 ) ;
}
static int F_182 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
const T_2 * V_843 = NULL , * V_418 ;
int V_844 = 0 ;
T_3 V_1006 ;
bool V_967 ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1007 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_282 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_1006 = F_72 ( V_31 -> V_5 [ V_1007 ] ) ;
if ( V_1006 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_511 ] ) {
V_843 = F_29 ( V_31 -> V_5 [ V_511 ] ) ;
V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
}
V_967 = ! ! V_31 -> V_5 [ V_973 ] ;
return F_183 ( V_7 , V_46 , V_418 , V_843 , V_844 , V_1006 ,
V_967 ) ;
}
static bool
F_184 ( struct V_6 * V_7 ,
int V_1008 [ V_232 ] ,
int V_1009 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_28 = false ;
int V_168 , V_135 ;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ ) {
struct V_1010 * V_1011 ;
V_1011 = V_18 -> V_233 [ V_168 ] ;
if ( ! V_1011 )
continue;
for ( V_135 = 0 ; V_135 < V_1011 -> V_253 ; V_135 ++ ) {
if ( V_1011 -> V_254 [ V_135 ] . V_256 == V_1009 ) {
V_1008 [ V_168 ] = V_135 + 1 ;
V_28 = true ;
break;
}
}
}
return V_28 ;
}
static int F_185 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1012 V_1013 ;
struct V_18 * V_18 ;
struct V_113 * V_1014 = NULL ;
int V_47 ;
memset ( & V_1013 , 0 , sizeof( V_1013 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_412 ] ||
! V_31 -> V_5 [ V_535 ] ||
! F_30 ( V_31 -> V_5 [ V_535 ] ) )
return - V_16 ;
V_1013 . V_414 = 100 ;
if ( V_31 -> V_5 [ V_531 ] ) {
V_1013 . V_414 =
F_4 ( V_31 -> V_5 [ V_531 ] ) ;
if ( V_1013 . V_414 < 1 || V_1013 . V_414 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_223 -> V_284 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_126 )
return - V_413 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_419 ] ) {
V_1013 . V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( ! F_186 ( V_1013 . V_418 ) )
return - V_16 ;
}
V_1013 . V_481 = F_29 ( V_31 -> V_5 [ V_535 ] ) ;
V_1013 . V_536 = F_30 ( V_31 -> V_5 [ V_535 ] ) ;
if ( V_31 -> V_5 [ V_511 ] ) {
V_1013 . V_843 = F_29 ( V_31 -> V_5 [ V_511 ] ) ;
V_1013 . V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
}
if ( V_31 -> V_5 [ V_405 ] ) {
enum V_403 V_404 ;
if ( ! F_74 ( V_31 , & V_404 ) )
return - V_16 ;
if ( V_404 != V_406 &&
! ( V_18 -> V_378 & V_1015 ) )
return - V_16 ;
V_1013 . V_404 = V_404 ;
} else {
V_1013 . V_404 = V_406 ;
}
V_1013 . V_410 = F_76 ( V_7 ,
F_4 ( V_31 -> V_5 [ V_412 ] ) ,
V_1013 . V_404 ) ;
if ( ! V_1013 . V_410 ||
V_1013 . V_410 -> V_56 & V_68 ||
V_1013 . V_410 -> V_56 & V_64 )
return - V_16 ;
if ( ( V_1013 . V_404 == V_408 ||
V_1013 . V_404 == V_409 ) &&
! F_77 ( & V_7 -> V_18 , V_1013 . V_410 ,
V_1013 . V_404 ) )
return - V_16 ;
V_1013 . V_1016 = ! ! V_31 -> V_5 [ V_1017 ] ;
V_1013 . V_542 = ! ! V_31 -> V_5 [ V_543 ] ;
if ( V_31 -> V_5 [ V_733 ] ) {
T_2 * V_883 =
F_29 ( V_31 -> V_5 [ V_733 ] ) ;
int V_1018 =
F_30 ( V_31 -> V_5 [ V_733 ] ) ;
struct V_1010 * V_1011 =
V_18 -> V_233 [ V_1013 . V_410 -> V_168 ] ;
V_47 = F_156 ( V_1011 , V_883 , V_1018 ,
& V_1013 . V_734 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_1019 ] &&
! F_184 ( V_7 , V_1013 . V_1008 ,
F_4 ( V_31 -> V_5 [ V_1019 ] ) ) )
return - V_16 ;
if ( V_1013 . V_542 && V_31 -> V_5 [ V_1020 ] ) {
V_1014 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1020 ] ) ;
if ( F_16 ( V_1014 ) )
return F_24 ( V_1014 ) ;
}
V_1013 . V_977 =
F_143 ( V_31 -> V_5 [ V_978 ] ) ;
V_47 = F_187 ( V_7 , V_46 , & V_1013 , V_1014 ) ;
if ( V_47 )
F_46 ( V_1014 ) ;
return V_47 ;
}
static int F_188 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
if ( ! V_7 -> V_223 -> V_1021 )
return - V_413 ;
if ( V_46 -> V_29 -> V_121 != V_126 )
return - V_413 ;
return F_189 ( V_7 , V_46 , false ) ;
}
static int F_190 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1022 ] )
return - V_16 ;
V_47 = - V_413 ;
if ( V_7 -> V_223 -> V_322 ) {
V_7 -> V_1023 = V_31 ;
V_47 = V_7 -> V_223 -> V_322 ( & V_7 -> V_18 ,
F_29 ( V_31 -> V_5 [ V_1022 ] ) ,
F_30 ( V_31 -> V_5 [ V_1022 ] ) ) ;
V_7 -> V_1023 = NULL ;
}
return V_47 ;
}
static int F_191 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
int V_47 ;
long V_1024 ;
void * V_120 = NULL ;
int V_1025 = 0 ;
if ( V_35 -> args [ 0 ] ) {
V_1024 = V_35 -> args [ 0 ] - 1 ;
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
V_1024 = V_7 -> V_14 ;
V_7 = NULL ;
F_9 ( & V_32 ) ;
if ( V_39 . V_41 [ V_1022 ] )
V_35 -> args [ 1 ] =
( long ) V_39 . V_41 [ V_1022 ] ;
}
if ( V_35 -> args [ 1 ] ) {
V_120 = F_29 ( ( void * ) V_35 -> args [ 1 ] ) ;
V_1025 = F_30 ( ( void * ) V_35 -> args [ 1 ] ) ;
}
F_8 ( & V_32 ) ;
V_7 = F_11 ( V_1024 ) ;
if ( ! V_7 ) {
F_9 ( & V_32 ) ;
return - V_499 ;
}
F_192 ( V_7 ) ;
F_9 ( & V_32 ) ;
if ( ! V_7 -> V_223 -> V_1026 ) {
V_47 = - V_413 ;
goto V_660;
}
while ( 1 ) {
void * V_159 = F_31 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_383 , V_384 ,
V_1027 ) ;
struct V_4 * V_1028 ;
if ( F_34 ( V_45 , V_27 , V_1024 ) ) {
F_63 ( V_45 , V_159 ) ;
break;
}
V_1028 = F_50 ( V_45 , V_1022 ) ;
if ( ! V_1028 ) {
F_63 ( V_45 , V_159 ) ;
break;
}
V_47 = V_7 -> V_223 -> V_1026 ( & V_7 -> V_18 , V_45 , V_35 ,
V_120 , V_1025 ) ;
F_51 ( V_45 , V_1028 ) ;
if ( V_47 == - V_74 || V_47 == - V_499 ) {
F_63 ( V_45 , V_159 ) ;
break;
} else if ( V_47 ) {
F_63 ( V_45 , V_159 ) ;
goto V_660;
}
F_62 ( V_45 , V_159 ) ;
}
V_47 = V_45 -> V_52 ;
V_35 -> args [ 0 ] = V_1024 + 1 ;
V_660:
F_27 ( V_7 ) ;
return V_47 ;
}
static struct V_44 *
F_193 ( struct V_6 * V_7 ,
int V_1029 , V_23 V_54 , V_23 V_55 , T_11 V_1030 )
{
struct V_44 * V_45 ;
void * V_159 ;
struct V_4 * V_120 ;
V_45 = F_68 ( V_1029 + 100 , V_1030 ) ;
if ( ! V_45 )
return NULL ;
V_159 = F_31 ( V_45 , V_54 , V_55 , 0 , V_1027 ) ;
if ( ! V_159 ) {
F_194 ( V_45 ) ;
return NULL ;
}
if ( F_34 ( V_45 , V_27 , V_7 -> V_14 ) )
goto V_63;
V_120 = F_50 ( V_45 , V_1022 ) ;
( ( void * * ) V_45 -> V_35 ) [ 0 ] = V_7 ;
( ( void * * ) V_45 -> V_35 ) [ 1 ] = V_159 ;
( ( void * * ) V_45 -> V_35 ) [ 2 ] = V_120 ;
return V_45 ;
V_63:
F_194 ( V_45 ) ;
return NULL ;
}
struct V_44 * F_195 ( struct V_18 * V_18 ,
int V_1029 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
if ( F_196 ( ! V_7 -> V_1023 ) )
return NULL ;
return F_193 ( V_7 , V_1029 ,
V_7 -> V_1023 -> V_387 ,
V_7 -> V_1023 -> V_388 ,
V_117 ) ;
}
int F_197 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = ( ( void * * ) V_45 -> V_35 ) [ 0 ] ;
void * V_159 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_120 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
if ( F_196 ( ! V_7 -> V_1023 ) ) {
F_194 ( V_45 ) ;
return - V_16 ;
}
F_51 ( V_45 , V_120 ) ;
F_62 ( V_45 , V_159 ) ;
return F_70 ( V_45 , V_7 -> V_1023 ) ;
}
struct V_44 * F_198 ( struct V_18 * V_18 ,
int V_1029 , T_11 V_1030 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
return F_193 ( V_7 , V_1029 , 0 , 0 , V_1030 ) ;
}
void F_199 ( struct V_44 * V_45 , T_11 V_1030 )
{
void * V_159 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_120 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
F_51 ( V_45 , V_120 ) ;
F_62 ( V_45 , V_159 ) ;
F_200 ( V_45 , 0 , V_1031 . V_1032 , V_1030 ) ;
}
static int F_201 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1033 V_324 ;
struct V_18 * V_18 ;
struct V_113 * V_1014 = NULL ;
int V_47 ;
memset ( & V_324 , 0 , sizeof( V_324 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_511 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_535 ] ||
! F_30 ( V_31 -> V_5 [ V_535 ] ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_544 ] ) {
V_324 . V_545 =
F_4 ( V_31 -> V_5 [ V_544 ] ) ;
if ( ! F_111 ( V_324 . V_545 ) )
return - V_16 ;
} else
V_324 . V_545 = V_546 ;
V_324 . V_542 = V_31 -> V_5 [ V_543 ] ;
V_47 = F_112 ( V_7 , V_31 , & V_324 . V_547 ,
V_548 ) ;
if ( V_47 )
return V_47 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
V_18 = & V_7 -> V_18 ;
V_324 . V_1034 = - 1 ;
if ( V_31 -> V_5 [ V_1035 ] &&
( V_18 -> V_56 & V_203 ) ) {
V_324 . V_1034 =
F_72 ( V_31 -> V_5 [ V_1035 ] ) ;
}
if ( V_31 -> V_5 [ V_419 ] )
V_324 . V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_324 . V_481 = F_29 ( V_31 -> V_5 [ V_535 ] ) ;
V_324 . V_536 = F_30 ( V_31 -> V_5 [ V_535 ] ) ;
if ( V_31 -> V_5 [ V_511 ] ) {
V_324 . V_843 = F_29 ( V_31 -> V_5 [ V_511 ] ) ;
V_324 . V_844 = F_30 ( V_31 -> V_5 [ V_511 ] ) ;
}
if ( V_31 -> V_5 [ V_412 ] ) {
V_324 . V_410 =
F_154 ( V_18 ,
F_4 ( V_31 -> V_5 [ V_412 ] ) ) ;
if ( ! V_324 . V_410 ||
V_324 . V_410 -> V_56 & V_64 )
return - V_16 ;
}
if ( V_324 . V_542 && V_31 -> V_5 [ V_1020 ] ) {
V_1014 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1020 ] ) ;
if ( F_16 ( V_1014 ) )
return F_24 ( V_1014 ) ;
}
if ( F_143 ( V_31 -> V_5 [ V_1004 ] ) )
V_324 . V_56 |= V_1005 ;
if ( V_31 -> V_5 [ V_380 ] )
memcpy ( & V_324 . V_997 ,
F_29 ( V_31 -> V_5 [ V_380 ] ) ,
sizeof( V_324 . V_997 ) ) ;
if ( V_31 -> V_5 [ V_671 ] ) {
if ( ! V_31 -> V_5 [ V_380 ] ) {
F_46 ( V_1014 ) ;
return - V_16 ;
}
memcpy ( & V_324 . V_672 ,
F_29 ( V_31 -> V_5 [ V_671 ] ) ,
sizeof( V_324 . V_672 ) ) ;
}
V_47 = F_202 ( V_7 , V_46 , & V_324 , V_1014 ) ;
if ( V_47 )
F_46 ( V_1014 ) ;
return V_47 ;
}
static int F_203 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_3 V_1036 ;
if ( ! V_31 -> V_5 [ V_1007 ] )
V_1036 = V_1037 ;
else
V_1036 = F_72 ( V_31 -> V_5 [ V_1007 ] ) ;
if ( V_1036 == 0 )
return - V_16 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
return F_204 ( V_7 , V_46 , V_1036 , true ) ;
}
static int F_205 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_2 * V_2 ;
int V_47 ;
V_23 V_54 ;
if ( ! V_31 -> V_5 [ V_1038 ] )
return - V_16 ;
V_54 = F_4 ( V_31 -> V_5 [ V_1038 ] ) ;
V_2 = F_206 ( V_54 ) ;
if ( F_16 ( V_2 ) )
return F_24 ( V_2 ) ;
V_47 = 0 ;
if ( ! F_65 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_47 = F_207 ( V_7 , V_2 ) ;
F_208 ( V_2 ) ;
return V_47 ;
}
static int F_209 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
int (* F_210)( struct V_18 * V_18 , struct V_26 * V_46 ,
struct V_1039 * V_1040 ) = NULL ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1039 V_1040 ;
memset ( & V_1040 , 0 , sizeof( struct V_1039 ) ) ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1041 ] )
return - V_16 ;
V_1040 . V_1042 = F_29 ( V_31 -> V_5 [ V_1041 ] ) ;
V_1040 . V_418 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
switch ( V_31 -> V_1043 -> V_57 ) {
case V_1044 :
F_210 = V_7 -> V_223 -> V_288 ;
break;
case V_1045 :
F_210 = V_7 -> V_223 -> V_290 ;
break;
default:
F_196 ( 1 ) ;
break;
}
if ( ! F_210 )
return - V_413 ;
return F_210 ( & V_7 -> V_18 , V_46 , & V_1040 ) ;
}
static int F_211 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_413 ;
if ( ! V_7 -> V_223 -> V_292 )
return - V_413 ;
return V_7 -> V_223 -> V_292 ( & V_7 -> V_18 , V_46 ) ;
}
static int F_212 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 V_1046 , V_1047 ;
T_3 V_1048 ;
T_2 * V_1049 ;
if ( ! ( V_7 -> V_18 . V_56 & V_205 ) ||
! V_7 -> V_223 -> V_309 )
return - V_413 ;
if ( ! V_31 -> V_5 [ V_1050 ] ||
! V_31 -> V_5 [ V_1051 ] ||
! V_31 -> V_5 [ V_1052 ] ||
! V_31 -> V_5 [ V_511 ] ||
! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
V_1049 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_1046 = F_39 ( V_31 -> V_5 [ V_1050 ] ) ;
V_1048 = F_72 ( V_31 -> V_5 [ V_1051 ] ) ;
V_1047 = F_39 ( V_31 -> V_5 [ V_1052 ] ) ;
return V_7 -> V_223 -> V_309 ( & V_7 -> V_18 , V_46 , V_1049 , V_1046 ,
V_1047 , V_1048 ,
F_29 ( V_31 -> V_5 [ V_511 ] ) ,
F_30 ( V_31 -> V_5 [ V_511 ] ) ) ;
}
static int F_213 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
enum V_1053 V_1054 ;
T_2 * V_1049 ;
if ( ! ( V_7 -> V_18 . V_56 & V_205 ) ||
! V_7 -> V_223 -> V_311 )
return - V_413 ;
if ( ! V_31 -> V_5 [ V_1055 ] ||
! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
V_1054 = F_39 ( V_31 -> V_5 [ V_1055 ] ) ;
V_1049 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
return V_7 -> V_223 -> V_311 ( & V_7 -> V_18 , V_46 , V_1049 , V_1054 ) ;
}
static int F_214 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
struct V_59 * V_60 ;
struct V_44 * V_58 ;
void * V_159 ;
T_1 V_490 ;
enum V_403 V_404 = V_406 ;
V_23 V_411 , V_1056 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_412 ] ||
! V_31 -> V_5 [ V_1057 ] )
return - V_16 ;
V_1056 = F_4 ( V_31 -> V_5 [ V_1057 ] ) ;
if ( ! V_7 -> V_223 -> V_295 ||
! ( V_7 -> V_18 . V_56 & V_294 ) )
return - V_413 ;
if ( V_1056 < V_1058 ||
V_1056 > V_7 -> V_18 . V_329 )
return - V_16 ;
if ( V_31 -> V_5 [ V_405 ] &&
! F_74 ( V_31 , & V_404 ) )
return - V_16 ;
V_411 = F_4 ( V_31 -> V_5 [ V_412 ] ) ;
V_60 = F_76 ( V_7 , V_411 , V_404 ) ;
if ( V_60 == NULL )
return - V_16 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_1059 ) ;
if ( F_16 ( V_159 ) ) {
V_47 = F_24 ( V_159 ) ;
goto V_500;
}
V_47 = V_7 -> V_223 -> V_295 ( & V_7 -> V_18 , V_17 , V_60 ,
V_404 , V_1056 , & V_490 ) ;
if ( V_47 )
goto V_500;
if ( F_88 ( V_58 , V_1060 , V_490 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_500:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_215 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
T_1 V_490 ;
if ( ! V_31 -> V_5 [ V_1060 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_1061 )
return - V_413 ;
V_490 = F_5 ( V_31 -> V_5 [ V_1060 ] ) ;
return V_7 -> V_223 -> V_1061 ( & V_7 -> V_18 , V_17 , V_490 ) ;
}
static V_23 F_216 ( struct V_1010 * V_1011 ,
T_2 * V_883 , T_2 V_1062 )
{
T_2 V_135 ;
V_23 V_560 = 0 ;
for ( V_135 = 0 ; V_135 < V_1062 ; V_135 ++ ) {
int V_170 = ( V_883 [ V_135 ] & 0x7f ) * 5 ;
int V_1063 ;
for ( V_1063 = 0 ; V_1063 < V_1011 -> V_253 ; V_1063 ++ ) {
struct V_169 * V_1064 =
& V_1011 -> V_254 [ V_1063 ] ;
if ( V_170 == V_1064 -> V_256 ) {
V_560 |= 1 << V_1063 ;
break;
}
}
if ( V_1063 == V_1011 -> V_253 )
return 0 ;
}
return V_560 ;
}
static bool F_217 ( struct V_1010 * V_1011 ,
T_2 * V_883 , T_2 V_1062 ,
T_2 V_237 [ V_1065 ] )
{
T_2 V_135 ;
memset ( V_237 , 0 , V_1065 ) ;
for ( V_135 = 0 ; V_135 < V_1062 ; V_135 ++ ) {
int V_1063 , V_1066 ;
V_1063 = V_883 [ V_135 ] / 8 ;
V_1066 = F_118 ( V_883 [ V_135 ] % 8 ) ;
if ( ( V_1063 < 0 ) || ( V_1063 >= V_1065 ) )
return false ;
if ( V_1011 -> V_234 . V_237 . V_1067 [ V_1063 ] & V_1066 )
V_237 [ V_1063 ] |= V_1066 ;
else
return false ;
}
return true ;
}
static int F_218 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_1068 + 1 ] ;
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1069 V_560 ;
int V_116 , V_135 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_4 * V_1070 ;
struct V_1010 * V_1011 ;
if ( V_31 -> V_5 [ V_1071 ] == NULL )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_297 )
return - V_413 ;
memset ( & V_560 , 0 , sizeof( V_560 ) ) ;
for ( V_135 = 0 ; V_135 < V_232 ; V_135 ++ ) {
V_1011 = V_7 -> V_18 . V_233 [ V_135 ] ;
V_560 . V_1072 [ V_135 ] . V_1073 =
V_1011 ? ( 1 << V_1011 -> V_253 ) - 1 : 0 ;
if ( V_1011 )
memcpy ( V_560 . V_1072 [ V_135 ] . V_237 ,
V_1011 -> V_234 . V_237 . V_1067 ,
sizeof( V_560 . V_1072 [ V_135 ] . V_237 ) ) ;
else
memset ( V_560 . V_1072 [ V_135 ] . V_237 , 0 ,
sizeof( V_560 . V_1072 [ V_135 ] . V_237 ) ) ;
}
F_95 ( V_1074 > V_1065 * 8 ) ;
F_44 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_167 V_168 = F_155 ( V_1070 ) ;
if ( V_168 < 0 || V_168 >= V_232 )
return - V_16 ;
V_1011 = V_7 -> V_18 . V_233 [ V_168 ] ;
if ( V_1011 == NULL )
return - V_16 ;
F_86 ( V_78 , V_1068 , F_29 ( V_1070 ) ,
F_30 ( V_1070 ) , V_1075 ) ;
if ( V_78 [ V_1076 ] ) {
V_560 . V_1072 [ V_168 ] . V_1073 = F_216 (
V_1011 ,
F_29 ( V_78 [ V_1076 ] ) ,
F_30 ( V_78 [ V_1076 ] ) ) ;
if ( ( V_560 . V_1072 [ V_168 ] . V_1073 == 0 ) &&
F_30 ( V_78 [ V_1076 ] ) )
return - V_16 ;
}
if ( V_78 [ V_1077 ] ) {
if ( ! F_217 (
V_1011 ,
F_29 ( V_78 [ V_1077 ] ) ,
F_30 ( V_78 [ V_1077 ] ) ,
V_560 . V_1072 [ V_168 ] . V_237 ) )
return - V_16 ;
}
if ( V_560 . V_1072 [ V_168 ] . V_1073 == 0 ) {
if ( ! V_7 -> V_18 . V_233 [ V_168 ] -> V_234 . V_235 )
return - V_16 ;
for ( V_135 = 0 ; V_135 < V_1065 ; V_135 ++ )
if ( V_560 . V_1072 [ V_168 ] . V_237 [ V_135 ] )
break;
if ( V_135 == V_1065 )
return - V_16 ;
}
}
return V_7 -> V_223 -> V_297 ( & V_7 -> V_18 , V_46 , NULL , & V_560 ) ;
}
static int F_219 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
T_3 V_1078 = V_341 | V_1079 ;
if ( ! V_31 -> V_5 [ V_1080 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_340 ] )
V_1078 = F_72 ( V_31 -> V_5 [ V_340 ] ) ;
switch ( V_17 -> V_121 ) {
case V_129 :
case V_126 :
case V_130 :
case V_122 :
case V_123 :
case V_125 :
case V_124 :
break;
default:
return - V_413 ;
}
if ( ! V_7 -> V_223 -> V_299 )
return - V_413 ;
return F_220 ( V_17 , V_31 -> V_387 , V_1078 ,
F_29 ( V_31 -> V_5 [ V_1080 ] ) ,
F_30 ( V_31 -> V_5 [ V_1080 ] ) ) ;
}
static int F_221 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
struct V_59 * V_60 ;
enum V_403 V_404 = V_406 ;
bool V_1081 = false ;
V_23 V_411 ;
int V_47 ;
void * V_159 = NULL ;
T_1 V_490 ;
struct V_44 * V_58 = NULL ;
unsigned int V_1082 = 0 ;
bool V_1083 , V_885 , V_1084 ;
V_1084 = V_31 -> V_5 [ V_1085 ] ;
if ( ! V_31 -> V_5 [ V_1086 ] ||
! V_31 -> V_5 [ V_412 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_299 )
return - V_413 ;
switch ( V_17 -> V_121 ) {
case V_129 :
case V_126 :
case V_130 :
case V_122 :
case V_123 :
case V_125 :
case V_124 :
break;
default:
return - V_413 ;
}
if ( V_31 -> V_5 [ V_1057 ] ) {
if ( ! ( V_7 -> V_18 . V_56 & V_330 ) )
return - V_16 ;
V_1082 = F_4 ( V_31 -> V_5 [ V_1057 ] ) ;
if ( V_1082 < V_1058 ||
V_1082 > V_7 -> V_18 . V_329 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_405 ] ) {
if ( ! F_74 ( V_31 , & V_404 ) )
return - V_16 ;
V_1081 = true ;
}
V_1083 = V_31 -> V_5 [ V_331 ] ;
if ( V_1083 && ! ( V_7 -> V_18 . V_56 & V_330 ) )
return - V_16 ;
V_885 = F_143 ( V_31 -> V_5 [ V_886 ] ) ;
V_411 = F_4 ( V_31 -> V_5 [ V_412 ] ) ;
V_60 = F_76 ( V_7 , V_411 , V_404 ) ;
if ( V_60 == NULL )
return - V_16 ;
if ( ! V_1084 ) {
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_1087 ) ;
if ( F_16 ( V_159 ) ) {
V_47 = F_24 ( V_159 ) ;
goto V_500;
}
}
V_47 = F_222 ( V_7 , V_17 , V_60 , V_1083 , V_404 ,
V_1081 , V_1082 ,
F_29 ( V_31 -> V_5 [ V_1086 ] ) ,
F_30 ( V_31 -> V_5 [ V_1086 ] ) ,
V_885 , V_1084 , & V_490 ) ;
if ( V_47 )
goto V_500;
if ( V_58 ) {
if ( F_88 ( V_58 , V_1060 , V_490 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
}
return 0 ;
V_63:
V_47 = - V_74 ;
V_500:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_223 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
T_1 V_490 ;
if ( ! V_31 -> V_5 [ V_1060 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_301 )
return - V_413 ;
switch ( V_17 -> V_121 ) {
case V_129 :
case V_126 :
case V_130 :
case V_122 :
case V_123 :
case V_124 :
break;
default:
return - V_413 ;
}
V_490 = F_5 ( V_31 -> V_5 [ V_1060 ] ) ;
return V_7 -> V_223 -> V_301 ( & V_7 -> V_18 , V_17 , V_490 ) ;
}
static int F_224 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
T_2 V_1088 ;
bool V_1089 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1090 ] )
return - V_16 ;
V_1088 = F_4 ( V_31 -> V_5 [ V_1090 ] ) ;
if ( V_1088 != V_1091 && V_1088 != V_1092 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1093 )
return - V_413 ;
V_1089 = ( V_1088 == V_1092 ) ? true : false ;
if ( V_1089 == V_17 -> V_1094 )
return 0 ;
V_47 = V_7 -> V_223 -> V_1093 ( V_17 -> V_18 , V_46 , V_1089 ,
V_17 -> V_1095 ) ;
if ( ! V_47 )
V_17 -> V_1094 = V_1089 ;
return V_47 ;
}
static int F_225 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
enum V_1096 V_1088 ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_44 * V_58 ;
void * V_159 ;
int V_47 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1093 )
return - V_413 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_1097 ) ;
if ( ! V_159 ) {
V_47 = - V_74 ;
goto V_500;
}
if ( V_17 -> V_1094 )
V_1088 = V_1092 ;
else
V_1088 = V_1091 ;
if ( F_34 ( V_58 , V_1090 , V_1088 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_500:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_226 ( struct V_30 * V_31 ,
V_23 V_170 , V_23 V_1098 , V_23 V_1099 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
if ( ( V_170 < 0 || V_170 > 100 ) ||
( V_1099 < 0 || V_1099 > V_1100 ) )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1101 )
return - V_413 ;
if ( V_17 -> V_121 != V_129 &&
V_17 -> V_121 != V_130 )
return - V_413 ;
return V_7 -> V_223 -> V_1101 ( V_17 -> V_18 , V_46 ,
V_170 , V_1098 , V_1099 ) ;
}
static int F_227 ( struct V_30 * V_31 ,
T_12 V_1102 , V_23 V_1103 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
if ( V_1102 > 0 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1104 )
return - V_413 ;
if ( V_17 -> V_121 != V_129 &&
V_17 -> V_121 != V_130 )
return - V_413 ;
return V_7 -> V_223 -> V_1104 ( V_17 -> V_18 , V_46 ,
V_1102 , V_1103 ) ;
}
static int F_228 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_5 [ V_1105 + 1 ] ;
struct V_4 * V_1106 ;
int V_47 ;
V_1106 = V_31 -> V_5 [ V_1107 ] ;
if ( ! V_1106 ) {
V_47 = - V_16 ;
goto V_460;
}
V_47 = F_38 ( V_5 , V_1105 , V_1106 ,
V_1108 ) ;
if ( V_47 )
goto V_460;
if ( V_5 [ V_1109 ] &&
V_5 [ V_1110 ] ) {
T_12 V_1102 ;
V_23 V_1103 ;
V_1102 = F_4 ( V_5 [ V_1109 ] ) ;
V_1103 = F_4 ( V_5 [ V_1110 ] ) ;
V_47 = F_227 ( V_31 , V_1102 , V_1103 ) ;
} else if ( V_5 [ V_1111 ] &&
V_5 [ V_1112 ] &&
V_5 [ V_1113 ] ) {
V_23 V_170 , V_1098 , V_1099 ;
V_170 = F_4 ( V_5 [ V_1111 ] ) ;
V_1098 = F_4 ( V_5 [ V_1112 ] ) ;
V_1099 = F_4 ( V_5 [ V_1113 ] ) ;
V_47 = F_226 ( V_31 , V_170 , V_1098 , V_1099 ) ;
} else
V_47 = - V_16 ;
V_460:
return V_47 ;
}
static int F_229 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_764 V_820 ;
struct V_824 V_825 ;
int V_47 ;
memcpy ( & V_820 , & V_768 , sizeof( V_820 ) ) ;
memcpy ( & V_825 , & V_1114 , sizeof( V_825 ) ) ;
if ( V_31 -> V_5 [ V_770 ] ) {
V_47 = F_140 ( V_31 , & V_820 , NULL ) ;
if ( V_47 )
return V_47 ;
}
if ( ! V_31 -> V_5 [ V_477 ] ||
! F_30 ( V_31 -> V_5 [ V_477 ] ) )
return - V_16 ;
V_825 . V_1115 = F_29 ( V_31 -> V_5 [ V_477 ] ) ;
V_825 . V_767 = F_30 ( V_31 -> V_5 [ V_477 ] ) ;
if ( V_31 -> V_5 [ V_1019 ] &&
! F_184 ( V_7 , V_825 . V_1008 ,
F_4 ( V_31 -> V_5 [ V_1019 ] ) ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_827 ] ) {
V_47 = F_142 ( V_31 , & V_825 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_412 ] ) {
enum V_403 V_404 = V_406 ;
if ( V_31 -> V_5 [ V_405 ] &&
! F_74 ( V_31 , & V_404 ) )
return - V_16 ;
V_825 . V_410 = F_76 ( V_7 ,
F_4 ( V_31 -> V_5 [ V_412 ] ) ,
V_404 ) ;
if ( ! V_825 . V_410 )
return - V_16 ;
V_825 . V_404 = V_404 ;
} else {
V_825 . V_410 = NULL ;
}
return F_230 ( V_7 , V_46 , & V_825 , & V_820 ) ;
}
static int F_231 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
return F_232 ( V_7 , V_46 ) ;
}
static int F_233 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_44 * V_58 ;
void * V_159 ;
if ( ! V_7 -> V_18 . V_344 . V_56 && ! V_7 -> V_18 . V_344 . V_345 )
return - V_413 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_1116 ) ;
if ( ! V_159 )
goto V_63;
if ( V_7 -> V_344 ) {
struct V_4 * V_346 ;
V_346 = F_50 ( V_58 , V_1117 ) ;
if ( ! V_346 )
goto V_63;
if ( ( V_7 -> V_344 -> V_1118 &&
F_35 ( V_58 , V_349 ) ) ||
( V_7 -> V_344 -> V_326 &&
F_35 ( V_58 , V_351 ) ) ||
( V_7 -> V_344 -> V_1119 &&
F_35 ( V_58 , V_353 ) ) ||
( V_7 -> V_344 -> V_1120 &&
F_35 ( V_58 , V_357 ) ) ||
( V_7 -> V_344 -> V_1121 &&
F_35 ( V_58 , V_359 ) ) ||
( V_7 -> V_344 -> V_1122 &&
F_35 ( V_58 , V_361 ) ) ||
( V_7 -> V_344 -> V_1123 &&
F_35 ( V_58 , V_363 ) ) )
goto V_63;
if ( V_7 -> V_344 -> V_345 ) {
struct V_4 * V_1124 , * V_1125 ;
int V_135 , V_1126 ;
V_1124 = F_50 ( V_58 ,
V_371 ) ;
if ( ! V_1124 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_7 -> V_344 -> V_345 ; V_135 ++ ) {
V_1125 = F_50 ( V_58 , V_135 + 1 ) ;
if ( ! V_1125 )
goto V_63;
V_1126 = V_7 -> V_344 -> V_1127 [ V_135 ] . V_1128 ;
if ( F_58 ( V_58 , V_1129 ,
F_234 ( V_1126 , 8 ) ,
V_7 -> V_344 -> V_1127 [ V_135 ] . V_560 ) ||
F_58 ( V_58 , V_1130 ,
V_1126 ,
V_7 -> V_344 -> V_1127 [ V_135 ] . V_1131 ) )
goto V_63;
F_51 ( V_58 , V_1125 ) ;
}
F_51 ( V_58 , V_1124 ) ;
}
F_51 ( V_58 , V_346 ) ;
}
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
F_69 ( V_58 ) ;
return - V_74 ;
}
static int F_235 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_4 * V_78 [ V_1132 ] ;
struct V_1133 V_1134 = {} ;
struct V_1133 * V_1135 ;
struct V_1136 * V_344 = & V_7 -> V_18 . V_344 ;
int V_47 , V_135 ;
bool V_1137 = V_7 -> V_344 ;
if ( ! V_7 -> V_18 . V_344 . V_56 && ! V_7 -> V_18 . V_344 . V_345 )
return - V_413 ;
if ( ! V_31 -> V_5 [ V_1117 ] ) {
F_236 ( V_7 ) ;
V_7 -> V_344 = NULL ;
goto V_1138;
}
V_47 = F_86 ( V_78 , V_1139 ,
F_29 ( V_31 -> V_5 [ V_1117 ] ) ,
F_30 ( V_31 -> V_5 [ V_1117 ] ) ,
V_1140 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_349 ] ) {
if ( ! ( V_344 -> V_56 & V_348 ) )
return - V_16 ;
V_1134 . V_1118 = true ;
}
if ( V_78 [ V_351 ] ) {
if ( ! ( V_344 -> V_56 & V_350 ) )
return - V_16 ;
V_1134 . V_326 = true ;
}
if ( V_78 [ V_353 ] ) {
if ( ! ( V_344 -> V_56 & V_352 ) )
return - V_16 ;
V_1134 . V_1119 = true ;
}
if ( V_78 [ V_355 ] )
return - V_16 ;
if ( V_78 [ V_357 ] ) {
if ( ! ( V_344 -> V_56 & V_356 ) )
return - V_16 ;
V_1134 . V_1120 = true ;
}
if ( V_78 [ V_359 ] ) {
if ( ! ( V_344 -> V_56 & V_358 ) )
return - V_16 ;
V_1134 . V_1121 = true ;
}
if ( V_78 [ V_361 ] ) {
if ( ! ( V_344 -> V_56 & V_360 ) )
return - V_16 ;
V_1134 . V_1122 = true ;
}
if ( V_78 [ V_363 ] ) {
if ( ! ( V_344 -> V_56 & V_362 ) )
return - V_16 ;
V_1134 . V_1123 = true ;
}
if ( V_78 [ V_371 ] ) {
struct V_4 * V_365 ;
int V_345 = 0 ;
int V_116 , V_1126 , V_1141 ;
struct V_4 * V_1142 [ V_1143 ] ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_345 ++ ;
if ( V_345 > V_344 -> V_345 )
return - V_16 ;
V_1134 . V_1127 = F_237 ( V_345 ,
sizeof( V_1134 . V_1127 [ 0 ] ) ,
V_117 ) ;
if ( ! V_1134 . V_1127 )
return - V_118 ;
V_1134 . V_345 = V_345 ;
V_135 = 0 ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_86 ( V_1142 , V_1144 ,
F_29 ( V_365 ) , F_30 ( V_365 ) , NULL ) ;
V_47 = - V_16 ;
if ( ! V_1142 [ V_1129 ] ||
! V_1142 [ V_1130 ] )
goto error;
V_1126 = F_30 ( V_1142 [ V_1130 ] ) ;
V_1141 = F_234 ( V_1126 , 8 ) ;
if ( F_30 ( V_1142 [ V_1129 ] ) !=
V_1141 )
goto error;
if ( V_1126 > V_344 -> V_370 ||
V_1126 < V_344 -> V_368 )
goto error;
V_1134 . V_1127 [ V_135 ] . V_560 =
F_238 ( V_1141 + V_1126 , V_117 ) ;
if ( ! V_1134 . V_1127 [ V_135 ] . V_560 ) {
V_47 = - V_118 ;
goto error;
}
V_1134 . V_1127 [ V_135 ] . V_1131 =
V_1134 . V_1127 [ V_135 ] . V_560 + V_1141 ;
memcpy ( V_1134 . V_1127 [ V_135 ] . V_560 ,
F_29 ( V_1142 [ V_1129 ] ) ,
V_1141 ) ;
V_1134 . V_1127 [ V_135 ] . V_1128 = V_1126 ;
memcpy ( V_1134 . V_1127 [ V_135 ] . V_1131 ,
F_29 ( V_1142 [ V_1130 ] ) ,
V_1126 ) ;
V_135 ++ ;
}
}
V_1135 = F_239 ( & V_1134 , sizeof( V_1134 ) , V_117 ) ;
if ( ! V_1135 ) {
V_47 = - V_118 ;
goto error;
}
F_236 ( V_7 ) ;
V_7 -> V_344 = V_1135 ;
V_1138:
if ( V_7 -> V_223 -> V_1138 && V_1137 != ! ! V_7 -> V_344 )
V_7 -> V_223 -> V_1138 ( & V_7 -> V_18 , V_7 -> V_344 ) ;
return 0 ;
error:
for ( V_135 = 0 ; V_135 < V_1134 . V_345 ; V_135 ++ )
F_46 ( V_1134 . V_1127 [ V_135 ] . V_560 ) ;
F_46 ( V_1134 . V_1127 ) ;
return V_47 ;
}
static int F_240 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_4 * V_78 [ V_1145 ] ;
struct V_1146 V_1147 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1148 ] )
return - V_16 ;
V_47 = F_86 ( V_78 , V_1149 ,
F_29 ( V_31 -> V_5 [ V_1148 ] ) ,
F_30 ( V_31 -> V_5 [ V_1148 ] ) ,
V_1150 ) ;
if ( V_47 )
return V_47 ;
if ( F_30 ( V_78 [ V_1151 ] ) != V_1152 )
return - V_1153 ;
if ( F_30 ( V_78 [ V_1154 ] ) != V_1155 )
return - V_1153 ;
if ( F_30 ( V_78 [ V_1156 ] ) != V_1157 )
return - V_1153 ;
memcpy ( V_1147 . V_1158 , F_29 ( V_78 [ V_1154 ] ) ,
V_1155 ) ;
memcpy ( V_1147 . V_1159 , F_29 ( V_78 [ V_1156 ] ) ,
V_1157 ) ;
memcpy ( V_1147 . V_1160 ,
F_29 ( V_78 [ V_1151 ] ) ,
V_1152 ) ;
F_94 ( V_17 ) ;
if ( ! V_17 -> V_127 ) {
V_47 = - V_1161 ;
goto V_460;
}
if ( ! V_7 -> V_223 -> V_1162 ) {
V_47 = - V_413 ;
goto V_460;
}
V_47 = V_7 -> V_223 -> V_1162 ( & V_7 -> V_18 , V_46 , & V_1147 ) ;
V_460:
F_96 ( V_17 ) ;
return V_47 ;
}
static int F_241 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_17 -> V_121 != V_122 &&
V_17 -> V_121 != V_124 )
return - V_16 ;
if ( V_17 -> V_1163 )
return - V_415 ;
V_17 -> V_1163 = V_31 -> V_387 ;
return 0 ;
}
static int F_242 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_385 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_44 * V_58 ;
void * V_159 ;
const T_2 * V_1164 ;
T_1 V_490 ;
int V_47 ;
if ( V_17 -> V_121 != V_122 &&
V_17 -> V_121 != V_124 )
return - V_413 ;
if ( ! V_31 -> V_5 [ V_419 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_316 )
return - V_413 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_387 , V_31 -> V_388 , 0 ,
V_1165 ) ;
if ( F_16 ( V_159 ) ) {
V_47 = F_24 ( V_159 ) ;
goto V_500;
}
V_1164 = F_29 ( V_31 -> V_5 [ V_419 ] ) ;
V_47 = V_7 -> V_223 -> V_316 ( & V_7 -> V_18 , V_46 , V_1164 , & V_490 ) ;
if ( V_47 )
goto V_500;
if ( F_88 ( V_58 , V_1060 , V_490 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_500:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_243 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_385 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_56 & V_320 ) )
return - V_413 ;
if ( V_7 -> V_1166 )
return - V_415 ;
V_7 -> V_1166 = V_31 -> V_387 ;
return 0 ;
}
static int F_244 ( struct V_1167 * V_223 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_26 * V_46 ;
bool V_1168 = V_223 -> V_1169 & V_1170 ;
if ( V_1168 )
F_20 () ;
if ( V_223 -> V_1169 & V_1171 ) {
V_7 = F_15 ( F_84 ( V_31 ) , V_31 ) ;
if ( F_16 ( V_7 ) ) {
if ( V_1168 )
F_25 () ;
return F_24 ( V_7 ) ;
}
V_31 -> V_385 [ 0 ] = V_7 ;
} else if ( V_223 -> V_1169 & V_1172 ||
V_223 -> V_1169 & V_1173 ) {
F_8 ( & V_32 ) ;
V_17 = F_1 ( F_84 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_17 ) ) {
F_9 ( & V_32 ) ;
if ( V_1168 )
F_25 () ;
return F_24 ( V_17 ) ;
}
V_46 = V_17 -> V_20 ;
V_7 = F_13 ( V_17 -> V_18 ) ;
if ( V_223 -> V_1169 & V_1172 ) {
if ( ! V_46 ) {
F_9 ( & V_32 ) ;
if ( V_1168 )
F_25 () ;
return - V_16 ;
}
V_31 -> V_385 [ 1 ] = V_46 ;
} else {
V_31 -> V_385 [ 1 ] = V_17 ;
}
if ( V_46 ) {
if ( V_223 -> V_1169 & V_1174 &&
! F_82 ( V_46 ) ) {
F_9 ( & V_32 ) ;
if ( V_1168 )
F_25 () ;
return - V_428 ;
}
F_158 ( V_46 ) ;
}
F_192 ( V_7 ) ;
F_9 ( & V_32 ) ;
V_31 -> V_385 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_245 ( struct V_1167 * V_223 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
if ( V_31 -> V_385 [ 0 ] )
F_27 ( V_31 -> V_385 [ 0 ] ) ;
if ( V_31 -> V_385 [ 1 ] ) {
if ( V_223 -> V_1169 & V_1173 ) {
struct V_1 * V_17 = V_31 -> V_385 [ 1 ] ;
if ( V_17 -> V_20 )
F_14 ( V_17 -> V_20 ) ;
} else {
F_14 ( V_31 -> V_385 [ 1 ] ) ;
}
}
if ( V_223 -> V_1169 & V_1170 )
F_25 () ;
}
void F_246 ( struct V_6 * V_7 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_53 ( V_58 , 0 , 0 , 0 , V_7 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1175 . V_1032 , V_117 ) ;
}
static int F_248 ( struct V_44 * V_58 ,
struct V_6 * V_7 )
{
struct V_874 * V_1176 = V_7 -> V_878 ;
struct V_4 * V_1177 ;
int V_135 ;
F_249 ( V_7 ) ;
if ( F_196 ( ! V_1176 ) )
return 0 ;
V_1177 = F_50 ( V_58 , V_880 ) ;
if ( ! V_1177 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_1176 -> V_876 ; V_135 ++ ) {
if ( F_58 ( V_58 , V_135 , V_1176 -> V_881 [ V_135 ] . V_536 , V_1176 -> V_881 [ V_135 ] . V_481 ) )
goto V_63;
}
F_51 ( V_58 , V_1177 ) ;
V_1177 = F_50 ( V_58 , V_879 ) ;
if ( ! V_1177 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_1176 -> V_250 ; V_135 ++ ) {
if ( F_34 ( V_58 , V_135 , V_1176 -> V_251 [ V_135 ] -> V_62 ) )
goto V_63;
}
F_51 ( V_58 , V_1177 ) ;
if ( V_1176 -> V_843 &&
F_58 ( V_58 , V_511 , V_1176 -> V_844 , V_1176 -> V_843 ) )
goto V_63;
return 0 ;
V_63:
return - V_74 ;
}
static int F_250 ( struct V_44 * V_58 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_23 V_54 , V_23 V_55 , int V_56 ,
V_23 V_57 )
{
void * V_159 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_57 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_17 -> V_20 && F_34 ( V_58 , V_10 ,
V_17 -> V_20 -> V_21 ) ) ||
F_88 ( V_58 , V_12 , V_13 ( V_17 ) ) )
goto V_63;
F_248 ( V_58 , V_7 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
static int
F_251 ( struct V_44 * V_58 ,
struct V_6 * V_7 ,
struct V_26 * V_20 ,
V_23 V_54 , V_23 V_55 , int V_56 , V_23 V_57 )
{
void * V_159 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_57 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_381 ;
}
void F_157 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_250 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1178 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1179 . V_1032 , V_117 ) ;
}
void F_252 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_250 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_909 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1179 . V_1032 , V_117 ) ;
}
void F_253 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_250 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1180 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1179 . V_1032 , V_117 ) ;
}
void F_254 ( struct V_6 * V_7 ,
struct V_26 * V_20 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_251 ( V_58 , V_7 , V_20 , 0 , 0 , 0 ,
V_1181 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1179 . V_1032 , V_117 ) ;
}
void F_160 ( struct V_6 * V_7 ,
struct V_26 * V_20 , V_23 V_57 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_251 ( V_58 , V_7 , V_20 , 0 , 0 , 0 , V_57 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1179 . V_1032 , V_117 ) ;
}
void F_255 ( struct V_1182 * V_875 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1183 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_56 ( V_58 , V_1184 , V_875 -> V_1185 ) )
goto V_63;
if ( V_875 -> V_852 [ 0 ] == '0' && V_875 -> V_852 [ 1 ] == '0' ) {
if ( F_56 ( V_58 , V_1186 ,
V_1187 ) )
goto V_63;
} else if ( V_875 -> V_852 [ 0 ] == '9' && V_875 -> V_852 [ 1 ] == '9' ) {
if ( F_56 ( V_58 , V_1186 ,
V_1188 ) )
goto V_63;
} else if ( ( V_875 -> V_852 [ 0 ] == '9' && V_875 -> V_852 [ 1 ] == '8' ) ||
V_875 -> V_1189 ) {
if ( F_56 ( V_58 , V_1186 ,
V_1190 ) )
goto V_63;
} else {
if ( F_56 ( V_58 , V_1186 ,
V_1191 ) ||
F_54 ( V_58 , V_760 ,
V_875 -> V_852 ) )
goto V_63;
}
if ( F_256 ( V_875 -> V_14 ) &&
F_34 ( V_58 , V_27 , V_875 -> V_14 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_257 () ;
F_258 ( V_58 , 0 , V_1192 . V_1032 ,
V_1193 ) ;
F_259 () ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static void F_260 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1194 , T_10 V_52 ,
enum V_1195 V_57 , T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_1086 , V_52 , V_1194 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_261 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1194 ,
T_10 V_52 , T_11 V_1030 )
{
F_260 ( V_7 , V_20 , V_1194 , V_52 ,
V_1197 , V_1030 ) ;
}
void F_262 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1194 ,
T_10 V_52 , T_11 V_1030 )
{
F_260 ( V_7 , V_20 , V_1194 , V_52 ,
V_1198 , V_1030 ) ;
}
void F_263 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1194 ,
T_10 V_52 , T_11 V_1030 )
{
F_260 ( V_7 , V_20 , V_1194 , V_52 ,
V_1199 , V_1030 ) ;
}
void F_264 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1194 ,
T_10 V_52 , T_11 V_1030 )
{
F_260 ( V_7 , V_20 , V_1194 , V_52 ,
V_1200 , V_1030 ) ;
}
void F_265 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1194 ,
T_10 V_52 , T_11 V_1030 )
{
F_260 ( V_7 , V_20 , V_1194 , V_52 ,
V_1201 , V_1030 ) ;
}
void F_266 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1194 ,
T_10 V_52 , T_11 V_1030 )
{
F_260 ( V_7 , V_20 , V_1194 , V_52 ,
V_1202 , V_1030 ) ;
}
static void F_267 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_57 ,
const T_2 * V_1164 , T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_35 ( V_58 , V_1203 ) ||
F_58 ( V_58 , V_419 , V_451 , V_1164 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_268 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1164 ,
T_11 V_1030 )
{
F_267 ( V_7 , V_20 , V_1197 ,
V_1164 , V_1030 ) ;
}
void F_269 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1164 ,
T_11 V_1030 )
{
F_267 ( V_7 , V_20 , V_1198 ,
V_1164 , V_1030 ) ;
}
void F_270 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_418 ,
const T_2 * V_1204 , T_10 V_1205 ,
const T_2 * V_1206 , T_10 V_1207 ,
T_3 V_1208 , T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_325 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_418 && F_58 ( V_58 , V_419 , V_451 , V_418 ) ) ||
F_57 ( V_58 , V_1051 , V_1208 ) ||
( V_1204 &&
F_58 ( V_58 , V_1209 , V_1205 , V_1204 ) ) ||
( V_1206 &&
F_58 ( V_58 , V_1210 , V_1207 , V_1206 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_271 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_418 ,
const T_2 * V_1204 , T_10 V_1205 ,
const T_2 * V_1206 , T_10 V_1207 , T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1211 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_418 ) ||
( V_1204 &&
F_58 ( V_58 , V_1209 , V_1205 , V_1204 ) ) ||
( V_1206 &&
F_58 ( V_58 , V_1210 , V_1207 , V_1206 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_272 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_3 V_1036 ,
const T_2 * V_843 , T_10 V_844 , bool V_1212 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_117 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_327 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_1212 && V_1036 &&
F_57 ( V_58 , V_1007 , V_1036 ) ) ||
( V_1212 &&
F_35 ( V_58 , V_1213 ) ) ||
( V_843 && F_58 ( V_58 , V_511 , V_844 , V_843 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_117 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_273 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_418 ,
T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1214 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_418 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_274 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1215 , const T_2 * V_843 , T_2 V_844 ,
T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1216 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_1215 ) ||
( V_844 && V_843 &&
F_58 ( V_58 , V_511 , V_844 , V_843 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_275 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1164 ,
enum V_1217 V_1218 , int V_1219 ,
const T_2 * V_1220 , T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1221 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_1164 && F_58 ( V_58 , V_419 , V_451 , V_1164 ) ) ||
F_34 ( V_58 , V_110 , V_1218 ) ||
( V_1219 != - 1 &&
F_56 ( V_58 , V_106 , V_1219 ) ) ||
( V_1220 && F_58 ( V_58 , V_105 , 6 , V_1220 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_276 ( struct V_18 * V_18 ,
struct V_59 * V_1222 ,
struct V_59 * V_1223 )
{
struct V_44 * V_58 ;
void * V_159 ;
struct V_4 * V_163 ;
V_58 = F_68 ( V_386 , V_1193 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1224 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , F_277 ( V_18 ) ) )
goto V_63;
V_163 = F_50 ( V_58 , V_1225 ) ;
if ( ! V_163 )
goto V_63;
if ( F_33 ( V_58 , V_1222 ) )
goto V_63;
F_51 ( V_58 , V_163 ) ;
V_163 = F_50 ( V_58 , V_1226 ) ;
if ( ! V_163 )
goto V_63;
if ( F_33 ( V_58 , V_1223 ) )
goto V_63;
F_51 ( V_58 , V_163 ) ;
F_62 ( V_58 , V_159 ) ;
F_257 () ;
F_258 ( V_58 , 0 , V_1192 . V_1032 ,
V_1193 ) ;
F_259 () ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static void F_278 (
int V_57 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_490 ,
struct V_59 * V_60 ,
enum V_403 V_404 ,
unsigned int V_1056 , T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_17 -> V_20 && F_34 ( V_58 , V_10 ,
V_17 -> V_20 -> V_21 ) ) ||
F_88 ( V_58 , V_12 , V_13 ( V_17 ) ) ||
F_34 ( V_58 , V_412 , V_60 -> V_62 ) ||
F_34 ( V_58 , V_405 , V_404 ) ||
F_88 ( V_58 , V_1060 , V_490 ) )
goto V_63;
if ( V_57 == V_1059 &&
F_34 ( V_58 , V_1057 , V_1056 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_279 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_490 ,
struct V_59 * V_60 ,
enum V_403 V_404 ,
unsigned int V_1056 , T_11 V_1030 )
{
F_278 ( V_1059 ,
V_7 , V_17 , V_490 , V_60 ,
V_404 , V_1056 , V_1030 ) ;
}
void F_280 (
struct V_6 * V_7 ,
struct V_1 * V_17 ,
T_1 V_490 , struct V_59 * V_60 ,
enum V_403 V_404 , T_11 V_1030 )
{
F_278 ( V_1227 ,
V_7 , V_17 , V_490 , V_60 ,
V_404 , 0 , V_1030 ) ;
}
void F_281 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_492 ,
struct V_583 * V_584 , T_11 V_1030 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
if ( F_121 ( V_58 , 0 , 0 , 0 ,
V_7 , V_46 , V_492 , V_584 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
}
void F_282 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_492 ,
T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1228 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_492 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static bool F_283 ( struct V_26 * V_46 , T_2 V_57 ,
const T_2 * V_1164 , T_11 V_1030 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_159 ;
int V_47 ;
V_23 V_1229 = F_284 ( V_17 -> V_1163 ) ;
if ( ! V_1229 )
return false ;
V_58 = F_68 ( 100 , V_1030 ) ;
if ( ! V_58 )
return true ;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return true ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_1164 ) )
goto V_63;
V_47 = F_62 ( V_58 , V_159 ) ;
if ( V_47 < 0 ) {
F_69 ( V_58 ) ;
return true ;
}
F_285 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1229 ) ;
return true ;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
return true ;
}
bool F_286 ( struct V_26 * V_46 , const T_2 * V_1164 , T_11 V_1030 )
{
return F_283 ( V_46 , V_1230 ,
V_1164 , V_1030 ) ;
}
bool F_287 ( struct V_26 * V_46 ,
const T_2 * V_1164 , T_11 V_1030 )
{
return F_283 ( V_46 ,
V_1231 ,
V_1164 , V_1030 ) ;
}
int F_288 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_23 V_1229 ,
int V_411 , int V_1232 ,
const T_2 * V_1194 , T_10 V_52 , T_11 V_1030 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1087 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return - V_118 ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_34 ( V_58 , V_412 , V_411 ) ||
( V_1232 &&
F_34 ( V_58 , V_1233 , V_1232 ) ) ||
F_58 ( V_58 , V_1086 , V_52 , V_1194 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_285 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1229 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
return - V_74 ;
}
void F_289 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_490 ,
const T_2 * V_1194 , T_10 V_52 , bool V_1234 ,
T_11 V_1030 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1235 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_58 ( V_58 , V_1086 , V_52 , V_1194 ) ||
F_88 ( V_58 , V_1060 , V_490 ) ||
( V_1234 && F_35 ( V_58 , V_1236 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_200 ( V_58 , 0 , V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void
F_290 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
enum V_1237 V_1238 ,
T_11 V_1030 )
{
struct V_44 * V_58 ;
struct V_4 * V_696 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1239 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_696 = F_50 ( V_58 , V_1107 ) ;
if ( ! V_696 )
goto V_63;
if ( F_34 ( V_58 , V_1240 ,
V_1238 ) )
goto V_63;
F_51 ( V_58 , V_696 ) ;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_291 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_418 ,
const T_2 * V_1160 , T_11 V_1030 )
{
struct V_44 * V_58 ;
struct V_4 * V_1241 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1242 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_418 ) )
goto V_63;
V_1241 = F_50 ( V_58 , V_1148 ) ;
if ( ! V_1241 )
goto V_63;
if ( F_58 ( V_58 , V_1151 ,
V_1152 , V_1160 ) )
goto V_63;
F_51 ( V_58 , V_1241 ) ;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_292 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_1243 ,
const T_2 * V_418 , bool V_1244 , T_11 V_1030 )
{
struct V_44 * V_58 ;
struct V_4 * V_50 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1245 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_50 = F_50 ( V_58 , V_1246 ) ;
if ( ! V_50 )
goto V_63;
if ( F_34 ( V_58 , V_1247 , V_1243 ) ||
F_58 ( V_58 , V_1248 , V_451 , V_418 ) ||
( V_1244 &&
F_35 ( V_58 , V_1249 ) ) )
goto V_63;
F_51 ( V_58 , V_50 ) ;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_293 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_411 ,
enum V_403 type , T_11 V_1030 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1250 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_34 ( V_58 , V_412 , V_411 ) ||
F_34 ( V_58 , V_405 , type ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void
F_294 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1049 ,
V_23 V_1251 , V_23 V_170 , V_23 V_1099 , T_11 V_1030 )
{
struct V_44 * V_58 ;
struct V_4 * V_696 ;
void * V_159 ;
V_58 = F_68 ( V_1252 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1239 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_1049 ) )
goto V_63;
V_696 = F_50 ( V_58 , V_1107 ) ;
if ( ! V_696 )
goto V_63;
if ( F_34 ( V_58 , V_1112 , V_1251 ) )
goto V_63;
if ( F_34 ( V_58 , V_1111 , V_170 ) )
goto V_63;
if ( F_34 ( V_58 , V_1113 , V_1099 ) )
goto V_63;
F_51 ( V_58 , V_696 ) ;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void
F_295 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1049 ,
V_23 V_1251 , T_11 V_1030 )
{
struct V_44 * V_58 ;
struct V_4 * V_696 ;
void * V_159 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1239 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_1049 ) )
goto V_63;
V_696 = F_50 ( V_58 , V_1107 ) ;
if ( ! V_696 )
goto V_63;
if ( F_34 ( V_58 , V_1253 , V_1251 ) )
goto V_63;
F_51 ( V_58 , V_696 ) ;
F_62 ( V_58 , V_159 ) ;
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_296 ( struct V_26 * V_46 , const T_2 * V_1164 ,
T_1 V_490 , bool V_1254 , T_11 V_1030 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_159 ;
int V_47 ;
V_58 = F_68 ( V_386 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1165 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_419 , V_451 , V_1164 ) ||
F_88 ( V_58 , V_1060 , V_490 ) ||
( V_1254 && F_35 ( V_58 , V_1236 ) ) )
goto V_63;
V_47 = F_62 ( V_58 , V_159 ) ;
if ( V_47 < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_247 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1196 . V_1032 , V_1030 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_297 ( struct V_18 * V_18 ,
const T_2 * V_1255 , T_10 V_52 ,
int V_411 , int V_1232 , T_11 V_1030 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_44 * V_58 ;
void * V_159 ;
V_23 V_1229 = F_284 ( V_7 -> V_1166 ) ;
if ( ! V_1229 )
return;
V_58 = F_68 ( V_52 + 100 , V_1030 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1087 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_411 &&
F_34 ( V_58 , V_412 , V_411 ) ) ||
( V_1232 &&
F_34 ( V_58 , V_1233 , V_1232 ) ) ||
F_58 ( V_58 , V_1086 , V_52 , V_1255 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_285 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1229 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static int F_298 ( struct V_1256 * V_1257 ,
unsigned long V_1089 ,
void * V_1258 )
{
struct V_1259 * V_1260 = V_1258 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
if ( V_1089 != V_1261 )
return V_1262 ;
F_257 () ;
F_299 (rdev, &cfg80211_rdev_list, list) {
F_299 (wdev, &rdev->wdev_list, list)
F_300 ( V_17 , V_1260 -> V_54 ) ;
if ( V_7 -> V_1166 == V_1260 -> V_54 )
V_7 -> V_1166 = 0 ;
}
F_259 () ;
return V_1262 ;
}
int F_301 ( void )
{
int V_47 ;
V_47 = F_302 ( & V_39 ,
V_1263 , F_303 ( V_1263 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_304 ( & V_39 , & V_1175 ) ;
if ( V_47 )
goto V_1264;
V_47 = F_304 ( & V_39 , & V_1179 ) ;
if ( V_47 )
goto V_1264;
V_47 = F_304 ( & V_39 , & V_1192 ) ;
if ( V_47 )
goto V_1264;
V_47 = F_304 ( & V_39 , & V_1196 ) ;
if ( V_47 )
goto V_1264;
#ifdef F_60
V_47 = F_304 ( & V_39 , & V_1031 ) ;
if ( V_47 )
goto V_1264;
#endif
V_47 = F_305 ( & V_1265 ) ;
if ( V_47 )
goto V_1264;
return 0 ;
V_1264:
F_306 ( & V_39 ) ;
return V_47 ;
}
void F_307 ( void )
{
F_308 ( & V_1265 ) ;
F_306 ( & V_39 ) ;
}
