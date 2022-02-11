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
F_59 ( V_322 , V_323 ) ;
#ifdef F_60
F_59 ( V_324 , V_325 ) ;
#endif
#undef F_59
if ( V_46 -> V_223 -> V_326 || V_46 -> V_223 -> V_276 ) {
V_135 ++ ;
if ( F_34 ( V_58 , V_135 , V_327 ) )
goto V_63;
}
if ( V_46 -> V_223 -> V_328 || V_46 -> V_223 -> V_280 ) {
V_135 ++ ;
if ( F_34 ( V_58 , V_135 , V_329 ) )
goto V_63;
}
F_51 ( V_58 , V_166 ) ;
if ( V_46 -> V_223 -> V_295 &&
( V_46 -> V_18 . V_56 & V_294 ) &&
F_34 ( V_58 , V_330 ,
V_46 -> V_18 . V_331 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_332 ) &&
F_35 ( V_58 , V_333 ) )
goto V_63;
if ( V_172 ) {
T_3 V_334 ;
struct V_4 * V_335 , * V_336 ;
enum V_337 V_338 ;
V_336 = F_50 ( V_58 , V_339 ) ;
if ( ! V_336 )
goto V_63;
for ( V_338 = 0 ; V_338 < V_340 ; V_338 ++ ) {
V_335 = F_50 ( V_58 , V_338 ) ;
if ( ! V_335 )
goto V_63;
V_135 = 0 ;
V_334 = V_172 [ V_338 ] . V_341 ;
while ( V_334 ) {
if ( ( V_334 & 1 ) &&
F_57 ( V_58 , V_342 ,
( V_135 << 4 ) | V_343 ) )
goto V_63;
V_334 >>= 1 ;
V_135 ++ ;
}
F_51 ( V_58 , V_335 ) ;
}
F_51 ( V_58 , V_336 ) ;
V_336 = F_50 ( V_58 , V_344 ) ;
if ( ! V_336 )
goto V_63;
for ( V_338 = 0 ; V_338 < V_340 ; V_338 ++ ) {
V_335 = F_50 ( V_58 , V_338 ) ;
if ( ! V_335 )
goto V_63;
V_135 = 0 ;
V_334 = V_172 [ V_338 ] . V_345 ;
while ( V_334 ) {
if ( ( V_334 & 1 ) &&
F_57 ( V_58 , V_342 ,
( V_135 << 4 ) | V_343 ) )
goto V_63;
V_334 >>= 1 ;
V_135 ++ ;
}
F_51 ( V_58 , V_335 ) ;
}
F_51 ( V_58 , V_336 ) ;
}
#ifdef F_61
if ( V_46 -> V_18 . V_346 . V_56 || V_46 -> V_18 . V_346 . V_347 ) {
struct V_4 * V_348 ;
V_348 = F_50 ( V_58 ,
V_349 ) ;
if ( ! V_348 )
goto V_63;
if ( ( ( V_46 -> V_18 . V_346 . V_56 & V_350 ) &&
F_35 ( V_58 , V_351 ) ) ||
( ( V_46 -> V_18 . V_346 . V_56 & V_352 ) &&
F_35 ( V_58 , V_353 ) ) ||
( ( V_46 -> V_18 . V_346 . V_56 & V_354 ) &&
F_35 ( V_58 , V_355 ) ) ||
( ( V_46 -> V_18 . V_346 . V_56 & V_356 ) &&
F_35 ( V_58 , V_357 ) ) ||
( ( V_46 -> V_18 . V_346 . V_56 & V_358 ) &&
F_35 ( V_58 , V_359 ) ) ||
( ( V_46 -> V_18 . V_346 . V_56 & V_360 ) &&
F_35 ( V_58 , V_361 ) ) ||
( ( V_46 -> V_18 . V_346 . V_56 & V_362 ) &&
F_35 ( V_58 , V_363 ) ) ||
( ( V_46 -> V_18 . V_346 . V_56 & V_364 ) &&
F_35 ( V_58 , V_365 ) ) )
goto V_63;
if ( V_46 -> V_18 . V_346 . V_347 ) {
struct V_366 V_367 = {
. V_368 = V_46 -> V_18 . V_346 . V_347 ,
. V_369 =
V_46 -> V_18 . V_346 . V_370 ,
. V_371 =
V_46 -> V_18 . V_346 . V_372 ,
} ;
if ( F_58 ( V_58 , V_373 ,
sizeof( V_367 ) , & V_367 ) )
goto V_63;
}
F_51 ( V_58 , V_348 ) ;
}
#endif
if ( F_49 ( V_58 , V_374 ,
V_46 -> V_18 . V_375 ) )
goto V_63;
if ( F_52 ( & V_46 -> V_18 , V_58 ) )
goto V_63;
if ( ( V_46 -> V_18 . V_56 & V_376 ) &&
F_34 ( V_58 , V_377 ,
V_46 -> V_18 . V_378 ) )
goto V_63;
if ( F_34 ( V_58 , V_379 ,
V_46 -> V_18 . V_380 ) )
goto V_63;
if ( V_46 -> V_18 . V_381 &&
F_58 ( V_58 , V_382 ,
sizeof( * V_46 -> V_18 . V_381 ) ,
V_46 -> V_18 . V_381 ) )
goto V_63;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_383 ;
}
static int F_64 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_88 = 0 ;
int V_384 = V_35 -> args [ 0 ] ;
struct V_6 * V_46 ;
F_8 ( & V_32 ) ;
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_65 ( F_7 ( & V_46 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( ++ V_88 <= V_384 )
continue;
if ( F_53 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_385 , V_386 ,
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
struct V_6 * V_46 = V_31 -> V_387 [ 0 ] ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_53 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 , V_46 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_71 ( struct V_4 * V_78 [] ,
struct V_391 * V_392 )
{
if ( ! V_78 [ V_393 ] || ! V_78 [ V_394 ] ||
! V_78 [ V_395 ] || ! V_78 [ V_396 ] ||
! V_78 [ V_397 ] )
return - V_16 ;
V_392 -> V_398 = F_39 ( V_78 [ V_393 ] ) ;
V_392 -> V_399 = F_72 ( V_78 [ V_394 ] ) ;
V_392 -> V_400 = F_72 ( V_78 [ V_395 ] ) ;
V_392 -> V_401 = F_72 ( V_78 [ V_396 ] ) ;
V_392 -> V_402 = F_39 ( V_78 [ V_397 ] ) ;
if ( V_392 -> V_398 >= V_403 )
return - V_16 ;
return 0 ;
}
static bool F_73 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_121 == V_122 ||
V_17 -> V_121 == V_125 ||
V_17 -> V_121 == V_404 ||
V_17 -> V_121 == V_124 ;
}
static bool F_74 ( struct V_30 * V_31 ,
enum V_405 * V_406 )
{
enum V_405 V_25 ;
if ( ! V_31 -> V_5 [ V_407 ] )
return false ;
V_25 = F_4 ( V_31 -> V_5 [ V_407 ] ) ;
if ( V_25 != V_408 &&
V_25 != V_409 &&
V_25 != V_410 &&
V_25 != V_411 )
return false ;
if ( V_406 )
* V_406 = V_25 ;
return true ;
}
static int F_75 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_30 * V_31 )
{
struct V_59 * V_412 ;
enum V_405 V_406 = V_408 ;
V_23 V_413 ;
int V_8 ;
enum V_337 V_121 = V_404 ;
if ( V_17 )
V_121 = V_17 -> V_121 ;
if ( ! V_31 -> V_5 [ V_414 ] )
return - V_16 ;
if ( ! F_73 ( V_17 ) )
return - V_415 ;
if ( V_31 -> V_5 [ V_407 ] &&
! F_74 ( V_31 , & V_406 ) )
return - V_16 ;
V_413 = F_4 ( V_31 -> V_5 [ V_414 ] ) ;
F_8 ( & V_7 -> V_19 ) ;
switch ( V_121 ) {
case V_122 :
case V_124 :
if ( V_17 -> V_416 ) {
V_8 = - V_417 ;
break;
}
V_412 = F_76 ( V_7 , V_413 , V_406 ) ;
if ( ! V_412 || ! F_77 ( & V_7 -> V_18 ,
V_412 ,
V_406 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_418 = V_412 ;
V_17 -> V_419 = V_406 ;
V_8 = 0 ;
break;
case V_125 :
V_8 = F_78 ( V_7 , V_17 , V_413 , V_406 ) ;
break;
case V_404 :
V_8 = F_79 ( V_7 , V_413 , V_406 ) ;
break;
default:
V_8 = - V_16 ;
}
F_9 ( & V_7 -> V_19 ) ;
return V_8 ;
}
static int F_80 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_20 = V_31 -> V_387 [ 1 ] ;
return F_75 ( V_7 , V_20 -> V_29 , V_31 ) ;
}
static int F_81 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
const T_2 * V_420 ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( F_82 ( V_46 ) )
return - V_417 ;
if ( ! V_7 -> V_223 -> V_307 )
return - V_415 ;
if ( V_17 -> V_121 != V_422 )
return - V_415 ;
V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
return V_7 -> V_223 -> V_307 ( V_17 -> V_18 , V_46 , V_420 ) ;
}
static int F_83 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_26 * V_20 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_423 = 0 ;
struct V_4 * V_424 ;
V_23 V_425 ;
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
goto V_426;
if ( V_31 -> V_5 [ V_427 ] ) {
struct V_391 V_392 ;
struct V_4 * V_78 [ V_428 + 1 ] ;
if ( ! V_7 -> V_223 -> V_429 ) {
V_8 = - V_415 ;
goto V_426;
}
if ( ! V_20 ) {
V_8 = - V_16 ;
goto V_426;
}
if ( V_20 -> V_29 -> V_121 != V_122 &&
V_20 -> V_29 -> V_121 != V_124 ) {
V_8 = - V_16 ;
goto V_426;
}
if ( ! F_82 ( V_20 ) ) {
V_8 = - V_430 ;
goto V_426;
}
F_44 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_86 ( V_78 , V_428 ,
F_29 ( V_424 ) ,
F_30 ( V_424 ) ,
V_431 ) ;
V_8 = F_71 ( V_78 , & V_392 ) ;
if ( V_8 )
goto V_426;
V_8 = V_7 -> V_223 -> V_429 ( & V_7 -> V_18 ,
V_20 ,
& V_392 ) ;
if ( V_8 )
goto V_426;
}
}
if ( V_31 -> V_5 [ V_414 ] ) {
V_8 = F_75 ( V_7 , V_17 , V_31 ) ;
if ( V_8 )
goto V_426;
}
if ( V_31 -> V_5 [ V_432 ] ) {
enum V_433 type ;
int V_88 , V_434 = 0 ;
if ( ! V_7 -> V_223 -> V_435 ) {
V_8 = - V_415 ;
goto V_426;
}
V_88 = V_432 ;
type = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
if ( ! V_31 -> V_5 [ V_436 ] &&
( type != V_437 ) ) {
V_8 = - V_16 ;
goto V_426;
}
if ( type != V_437 ) {
V_88 = V_436 ;
V_434 = F_4 ( V_31 -> V_5 [ V_88 ] ) ;
}
V_8 = V_7 -> V_223 -> V_435 ( & V_7 -> V_18 , type , V_434 ) ;
if ( V_8 )
goto V_426;
}
if ( V_31 -> V_5 [ V_227 ] &&
V_31 -> V_5 [ V_228 ] ) {
V_23 V_225 , V_226 ;
if ( ( ! V_7 -> V_18 . V_217 &&
! V_7 -> V_18 . V_219 ) ||
! V_7 -> V_223 -> V_438 ) {
V_8 = - V_415 ;
goto V_426;
}
V_225 = F_4 ( V_31 -> V_5 [ V_227 ] ) ;
V_226 = F_4 ( V_31 -> V_5 [ V_228 ] ) ;
if ( ( ~ V_225 && ( V_225 & ~ V_7 -> V_18 . V_217 ) ) ||
( ~ V_226 && ( V_226 & ~ V_7 -> V_18 . V_219 ) ) ) {
V_8 = - V_16 ;
goto V_426;
}
V_225 = V_225 & V_7 -> V_18 . V_217 ;
V_226 = V_226 & V_7 -> V_18 . V_219 ;
V_8 = V_7 -> V_223 -> V_438 ( & V_7 -> V_18 , V_225 , V_226 ) ;
if ( V_8 )
goto V_426;
}
V_425 = 0 ;
if ( V_31 -> V_5 [ V_177 ] ) {
V_178 = F_39 (
V_31 -> V_5 [ V_177 ] ) ;
if ( V_178 == 0 ) {
V_8 = - V_16 ;
goto V_426;
}
V_425 |= V_439 ;
}
if ( V_31 -> V_5 [ V_179 ] ) {
V_180 = F_39 (
V_31 -> V_5 [ V_179 ] ) ;
if ( V_180 == 0 ) {
V_8 = - V_16 ;
goto V_426;
}
V_425 |= V_440 ;
}
if ( V_31 -> V_5 [ V_181 ] ) {
V_182 = F_4 (
V_31 -> V_5 [ V_181 ] ) ;
if ( V_182 < 256 ) {
V_8 = - V_16 ;
goto V_426;
}
if ( V_182 != ( V_23 ) - 1 ) {
V_182 &= ~ 0x1 ;
}
V_425 |= V_441 ;
}
if ( V_31 -> V_5 [ V_183 ] ) {
V_184 = F_4 (
V_31 -> V_5 [ V_183 ] ) ;
V_425 |= V_442 ;
}
if ( V_31 -> V_5 [ V_185 ] ) {
V_186 = F_39 (
V_31 -> V_5 [ V_185 ] ) ;
V_425 |= V_443 ;
}
if ( V_425 ) {
T_2 V_444 , V_445 ;
V_23 V_446 , V_447 ;
T_2 V_448 ;
if ( ! V_7 -> V_223 -> V_449 ) {
V_8 = - V_415 ;
goto V_426;
}
V_444 = V_7 -> V_18 . V_178 ;
V_445 = V_7 -> V_18 . V_180 ;
V_446 = V_7 -> V_18 . V_182 ;
V_447 = V_7 -> V_18 . V_184 ;
V_448 = V_7 -> V_18 . V_186 ;
if ( V_425 & V_439 )
V_7 -> V_18 . V_178 = V_178 ;
if ( V_425 & V_440 )
V_7 -> V_18 . V_180 = V_180 ;
if ( V_425 & V_441 )
V_7 -> V_18 . V_182 = V_182 ;
if ( V_425 & V_442 )
V_7 -> V_18 . V_184 = V_184 ;
if ( V_425 & V_443 )
V_7 -> V_18 . V_186 = V_186 ;
V_8 = V_7 -> V_223 -> V_449 ( & V_7 -> V_18 , V_425 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_178 = V_444 ;
V_7 -> V_18 . V_180 = V_445 ;
V_7 -> V_18 . V_182 = V_446 ;
V_7 -> V_18 . V_184 = V_447 ;
V_7 -> V_18 . V_186 = V_448 ;
}
}
V_426:
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
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_450 ) ;
if ( ! V_159 )
return - 1 ;
if ( V_46 &&
( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_54 ( V_58 , V_451 , V_46 -> V_452 ) ) )
goto V_63;
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_453 , V_17 -> V_121 ) ||
F_88 ( V_58 , V_12 , V_13 ( V_17 ) ) ||
F_58 ( V_58 , V_421 , V_454 , F_89 ( V_17 ) ) ||
F_34 ( V_58 , V_175 ,
V_7 -> V_455 ^
( V_176 << 2 ) ) )
goto V_63;
if ( V_7 -> V_223 -> V_456 ) {
struct V_59 * V_60 ;
enum V_405 V_406 ;
V_60 = V_7 -> V_223 -> V_456 ( & V_7 -> V_18 , V_17 ,
& V_406 ) ;
if ( V_60 &&
( F_34 ( V_58 , V_414 ,
V_60 -> V_62 ) ||
F_34 ( V_58 , V_407 ,
V_406 ) ) )
goto V_63;
}
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_383 ;
}
static int F_90 ( struct V_44 * V_45 , struct V_34 * V_35 )
{
int V_457 = 0 ;
int V_458 = 0 ;
int V_459 = V_35 -> args [ 0 ] ;
int V_460 = V_35 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_8 ( & V_32 ) ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_65 ( F_7 ( & V_7 -> V_18 ) , F_22 ( V_45 -> V_48 ) ) )
continue;
if ( V_457 < V_459 ) {
V_457 ++ ;
continue;
}
V_458 = 0 ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_458 < V_460 ) {
V_458 ++ ;
continue;
}
if ( F_87 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_385 , V_386 ,
V_7 , V_17 ) < 0 ) {
F_9 ( & V_7 -> V_19 ) ;
goto V_461;
}
V_458 ++ ;
}
F_9 ( & V_7 -> V_19 ) ;
V_457 ++ ;
}
V_461:
F_9 ( & V_32 ) ;
V_35 -> args [ 0 ] = V_457 ;
V_35 -> args [ 1 ] = V_458 ;
return V_45 -> V_52 ;
}
static int F_91 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
struct V_6 * V_46 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_87 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_46 , V_17 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_92 ( struct V_4 * V_462 , V_23 * V_463 )
{
struct V_4 * V_56 [ V_464 + 1 ] ;
int V_465 ;
* V_463 = 0 ;
if ( ! V_462 )
return - V_16 ;
if ( F_38 ( V_56 , V_464 ,
V_462 , V_466 ) )
return - V_16 ;
for ( V_465 = 1 ; V_465 <= V_464 ; V_465 ++ )
if ( V_56 [ V_465 ] )
* V_463 |= ( 1 << V_465 ) ;
return 0 ;
}
static int F_93 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_2 V_467 ,
enum V_337 V_121 )
{
if ( ! V_467 ) {
if ( V_20 && ( V_20 -> V_468 & V_469 ) )
return - V_417 ;
return 0 ;
}
switch ( V_121 ) {
case V_123 :
if ( V_7 -> V_18 . V_56 & V_470 )
return 0 ;
break;
case V_129 :
if ( V_7 -> V_18 . V_56 & V_471 )
return 0 ;
break;
default:
break;
}
return - V_415 ;
}
static int F_94 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_472 V_119 ;
int V_47 ;
enum V_337 V_473 , V_474 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
V_23 V_475 , * V_56 = NULL ;
bool V_476 = false ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_473 = V_474 = V_46 -> V_29 -> V_121 ;
if ( V_31 -> V_5 [ V_453 ] ) {
V_474 = F_4 ( V_31 -> V_5 [ V_453 ] ) ;
if ( V_473 != V_474 )
V_476 = true ;
if ( V_474 > V_477 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_478 ] ) {
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_474 != V_125 )
return - V_16 ;
if ( F_82 ( V_46 ) )
return - V_417 ;
F_95 ( V_17 ) ;
F_96 ( V_479 !=
V_480 ) ;
V_17 -> V_481 =
F_30 ( V_31 -> V_5 [ V_478 ] ) ;
memcpy ( V_17 -> V_482 , F_29 ( V_31 -> V_5 [ V_478 ] ) ,
V_17 -> V_481 ) ;
F_97 ( V_17 ) ;
}
if ( V_31 -> V_5 [ V_483 ] ) {
V_119 . V_467 = ! ! F_39 ( V_31 -> V_5 [ V_483 ] ) ;
V_476 = true ;
V_47 = F_93 ( V_7 , V_46 , V_119 . V_467 , V_474 ) ;
if ( V_47 )
return V_47 ;
} else {
V_119 . V_467 = - 1 ;
}
if ( V_31 -> V_5 [ V_484 ] ) {
if ( V_474 != V_404 )
return - V_16 ;
V_47 = F_92 ( V_31 -> V_5 [ V_484 ] ,
& V_475 ) ;
if ( V_47 )
return V_47 ;
V_56 = & V_475 ;
V_476 = true ;
}
if ( V_476 )
V_47 = F_98 ( V_7 , V_46 , V_474 , V_56 , & V_119 ) ;
else
V_47 = 0 ;
if ( ! V_47 && V_119 . V_467 != - 1 )
V_46 -> V_29 -> V_467 = V_119 . V_467 ;
return V_47 ;
}
static int F_99 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_472 V_119 ;
struct V_1 * V_17 ;
struct V_44 * V_58 ;
int V_47 ;
enum V_337 type = V_485 ;
V_23 V_56 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
if ( ! V_31 -> V_5 [ V_451 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_453 ] ) {
type = F_4 ( V_31 -> V_5 [ V_453 ] ) ;
if ( type > V_477 )
return - V_16 ;
}
if ( ! V_7 -> V_223 -> V_260 ||
! ( V_7 -> V_18 . V_230 & ( 1 << type ) ) )
return - V_415 ;
if ( V_31 -> V_5 [ V_483 ] ) {
V_119 . V_467 = ! ! F_39 ( V_31 -> V_5 [ V_483 ] ) ;
V_47 = F_93 ( V_7 , NULL , V_119 . V_467 , type ) ;
if ( V_47 )
return V_47 ;
}
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_47 = F_92 ( type == V_404 ?
V_31 -> V_5 [ V_484 ] : NULL ,
& V_56 ) ;
V_17 = V_7 -> V_223 -> V_260 ( & V_7 -> V_18 ,
F_29 ( V_31 -> V_5 [ V_451 ] ) ,
type , V_47 ? NULL : & V_56 , & V_119 ) ;
if ( F_16 ( V_17 ) ) {
F_69 ( V_58 ) ;
return F_24 ( V_17 ) ;
}
switch ( type ) {
case V_125 :
if ( ! V_31 -> V_5 [ V_478 ] )
break;
F_95 ( V_17 ) ;
F_96 ( V_479 !=
V_480 ) ;
V_17 -> V_481 =
F_30 ( V_31 -> V_5 [ V_478 ] ) ;
memcpy ( V_17 -> V_482 , F_29 ( V_31 -> V_5 [ V_478 ] ) ,
V_17 -> V_481 ) ;
F_97 ( V_17 ) ;
break;
case V_486 :
F_100 ( & V_17 -> V_33 ) ;
F_101 ( & V_17 -> V_487 ) ;
F_102 ( & V_17 -> V_488 ) ;
F_101 ( & V_17 -> V_489 ) ;
F_102 ( & V_17 -> V_490 ) ;
F_8 ( & V_7 -> V_19 ) ;
V_17 -> V_22 = ++ V_7 -> V_13 ;
F_103 ( & V_17 -> V_491 , & V_7 -> V_492 ) ;
V_7 -> V_455 ++ ;
F_9 ( & V_7 -> V_19 ) ;
break;
default:
break;
}
if ( F_87 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_7 , V_17 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_104 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
if ( ! V_7 -> V_223 -> V_493 )
return - V_415 ;
if ( ! V_17 -> V_20 )
V_31 -> V_387 [ 1 ] = NULL ;
return V_7 -> V_223 -> V_493 ( & V_7 -> V_18 , V_17 ) ;
}
static int F_105 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_3 V_494 ;
if ( ! V_31 -> V_5 [ V_495 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_318 )
return - V_415 ;
V_494 = F_72 ( V_31 -> V_5 [ V_495 ] ) ;
return V_7 -> V_223 -> V_318 ( & V_7 -> V_18 , V_46 , V_494 ) ;
}
static void F_106 ( void * V_141 , struct V_496 * V_119 )
{
struct V_4 * V_75 ;
struct V_497 * V_498 = V_141 ;
if ( ( V_119 -> V_75 &&
F_58 ( V_498 -> V_58 , V_104 ,
V_119 -> V_91 , V_119 -> V_75 ) ) ||
( V_119 -> V_55 &&
F_58 ( V_498 -> V_58 , V_105 ,
V_119 -> V_93 , V_119 -> V_55 ) ) ||
( V_119 -> V_95 &&
F_34 ( V_498 -> V_58 , V_107 ,
V_119 -> V_95 ) ) )
goto V_63;
V_75 = F_50 ( V_498 -> V_58 , V_112 ) ;
if ( ! V_75 )
goto V_63;
if ( ( V_119 -> V_75 &&
F_58 ( V_498 -> V_58 , V_89 ,
V_119 -> V_91 , V_119 -> V_75 ) ) ||
( V_119 -> V_55 &&
F_58 ( V_498 -> V_58 , V_92 ,
V_119 -> V_93 , V_119 -> V_55 ) ) ||
( V_119 -> V_95 &&
F_34 ( V_498 -> V_58 , V_94 ,
V_119 -> V_95 ) ) )
goto V_63;
if ( F_56 ( V_498 -> V_58 , V_106 , V_498 -> V_88 ) )
goto V_63;
F_51 ( V_498 -> V_58 , V_75 ) ;
return;
V_63:
V_498 -> error = 1 ;
}
static int F_107 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 V_499 = 0 ;
const T_2 * V_500 = NULL ;
bool V_501 ;
struct V_497 V_498 = {
. error = 0 ,
} ;
void * V_159 ;
struct V_44 * V_58 ;
if ( V_31 -> V_5 [ V_106 ] )
V_499 = F_39 ( V_31 -> V_5 [ V_106 ] ) ;
if ( V_499 > 5 )
return - V_16 ;
if ( V_31 -> V_5 [ V_421 ] )
V_500 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_501 = ! ! V_500 ;
if ( V_31 -> V_5 [ V_110 ] ) {
V_23 V_502 = F_4 ( V_31 -> V_5 [ V_110 ] ) ;
if ( V_502 >= V_97 )
return - V_16 ;
if ( V_502 != V_503 &&
V_502 != V_504 )
return - V_16 ;
V_501 = V_502 == V_504 ;
}
if ( ! V_7 -> V_223 -> V_505 )
return - V_415 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_506 ) ;
if ( F_16 ( V_159 ) )
return F_24 ( V_159 ) ;
V_498 . V_58 = V_58 ;
V_498 . V_88 = V_499 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_56 ( V_58 , V_106 , V_499 ) )
goto V_63;
if ( V_500 &&
F_58 ( V_58 , V_421 , V_454 , V_500 ) )
goto V_63;
if ( V_501 && V_500 &&
! ( V_7 -> V_18 . V_56 & V_197 ) )
return - V_507 ;
V_47 = V_7 -> V_223 -> V_505 ( & V_7 -> V_18 , V_46 , V_499 , V_501 ,
V_500 , & V_498 , F_106 ) ;
if ( V_47 )
goto V_508;
if ( V_498 . error )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_508:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_108 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_76 V_75 ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 < 0 )
return - V_16 ;
if ( ! V_75 . V_81 && ! V_75 . V_83 )
return - V_16 ;
F_95 ( V_46 -> V_29 ) ;
if ( V_75 . V_81 ) {
if ( ! V_7 -> V_223 -> V_509 ) {
V_47 = - V_415 ;
goto V_461;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_461;
V_47 = V_7 -> V_223 -> V_509 ( & V_7 -> V_18 , V_46 , V_75 . V_88 ,
V_75 . V_85 , V_75 . V_86 ) ;
if ( V_47 )
goto V_461;
#ifdef F_109
V_46 -> V_29 -> V_510 . V_511 = V_75 . V_88 ;
#endif
} else {
if ( V_75 . V_85 || ! V_75 . V_86 ) {
V_47 = - V_16 ;
goto V_461;
}
if ( ! V_7 -> V_223 -> V_512 ) {
V_47 = - V_415 ;
goto V_461;
}
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_47 )
goto V_461;
V_47 = V_7 -> V_223 -> V_512 ( & V_7 -> V_18 ,
V_46 , V_75 . V_88 ) ;
if ( V_47 )
goto V_461;
#ifdef F_109
V_46 -> V_29 -> V_510 . V_513 = V_75 . V_88 ;
#endif
}
V_461:
F_97 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_110 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_76 V_75 ;
const T_2 * V_500 = NULL ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_75 . V_90 . V_75 )
return - V_16 ;
if ( V_31 -> V_5 [ V_421 ] )
V_500 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_500 )
V_75 . type = V_504 ;
else
V_75 . type = V_503 ;
}
if ( V_75 . type != V_504 &&
V_75 . type != V_503 )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_264 )
return - V_415 ;
if ( F_45 ( V_7 , & V_75 . V_90 , V_75 . V_88 ,
V_75 . type == V_504 ,
V_500 ) )
return - V_16 ;
F_95 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( ! V_47 )
V_47 = V_7 -> V_223 -> V_264 ( & V_7 -> V_18 , V_46 , V_75 . V_88 ,
V_75 . type == V_504 ,
V_500 , & V_75 . V_90 ) ;
F_97 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_111 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 * V_500 = NULL ;
struct V_76 V_75 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_421 ] )
V_500 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( V_75 . type == - 1 ) {
if ( V_500 )
V_75 . type = V_504 ;
else
V_75 . type = V_503 ;
}
if ( V_75 . type != V_504 &&
V_75 . type != V_503 )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_514 )
return - V_415 ;
F_95 ( V_46 -> V_29 ) ;
V_47 = F_47 ( V_46 -> V_29 ) ;
if ( V_75 . type == V_504 && V_500 &&
! ( V_7 -> V_18 . V_56 & V_197 ) )
V_47 = - V_507 ;
if ( ! V_47 )
V_47 = V_7 -> V_223 -> V_514 ( & V_7 -> V_18 , V_46 , V_75 . V_88 ,
V_75 . type == V_504 ,
V_500 ) ;
#ifdef F_109
if ( ! V_47 ) {
if ( V_75 . V_88 == V_46 -> V_29 -> V_510 . V_511 )
V_46 -> V_29 -> V_510 . V_511 = - 1 ;
else if ( V_75 . V_88 == V_46 -> V_29 -> V_510 . V_513 )
V_46 -> V_29 -> V_510 . V_513 = - 1 ;
}
#endif
F_97 ( V_46 -> V_29 ) ;
return V_47 ;
}
static int F_112 ( struct V_30 * V_31 ,
struct V_515 * V_516 )
{
bool V_517 = false ;
if ( ! F_28 ( V_31 -> V_5 [ V_518 ] ) ||
! F_28 ( V_31 -> V_5 [ V_519 ] ) ||
! F_28 ( V_31 -> V_5 [ V_520 ] ) ||
! F_28 ( V_31 -> V_5 [ V_521 ] ) )
return - V_16 ;
memset ( V_516 , 0 , sizeof( * V_516 ) ) ;
if ( V_31 -> V_5 [ V_522 ] ) {
V_516 -> V_523 = F_29 ( V_31 -> V_5 [ V_522 ] ) ;
V_516 -> V_524 = F_30 ( V_31 -> V_5 [ V_522 ] ) ;
if ( ! V_516 -> V_524 )
return - V_16 ;
V_517 = true ;
}
if ( V_31 -> V_5 [ V_518 ] ) {
V_516 -> V_525 = F_29 ( V_31 -> V_5 [ V_518 ] ) ;
V_516 -> V_526 =
F_30 ( V_31 -> V_5 [ V_518 ] ) ;
V_517 = true ;
}
if ( ! V_517 )
return - V_16 ;
if ( V_31 -> V_5 [ V_519 ] ) {
V_516 -> V_527 = F_29 ( V_31 -> V_5 [ V_519 ] ) ;
V_516 -> V_528 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
}
if ( V_31 -> V_5 [ V_520 ] ) {
V_516 -> V_529 =
F_29 ( V_31 -> V_5 [ V_520 ] ) ;
V_516 -> V_530 =
F_30 ( V_31 -> V_5 [ V_520 ] ) ;
}
if ( V_31 -> V_5 [ V_521 ] ) {
V_516 -> V_531 =
F_29 ( V_31 -> V_5 [ V_521 ] ) ;
V_516 -> V_532 =
F_30 ( V_31 -> V_5 [ V_521 ] ) ;
}
if ( V_31 -> V_5 [ V_533 ] ) {
V_516 -> V_534 =
F_29 ( V_31 -> V_5 [ V_533 ] ) ;
V_516 -> V_535 =
F_30 ( V_31 -> V_5 [ V_533 ] ) ;
}
return 0 ;
}
static bool F_113 ( struct V_6 * V_7 ,
struct V_536 * V_119 )
{
struct V_1 * V_17 ;
bool V_537 = false ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_121 != V_122 &&
V_17 -> V_121 != V_124 )
continue;
if ( ! V_17 -> V_418 )
continue;
V_119 -> V_412 = V_17 -> V_418 ;
V_119 -> V_406 = V_17 -> V_419 ;
V_537 = true ;
break;
}
F_9 ( & V_7 -> V_19 ) ;
return V_537 ;
}
static int F_114 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_536 V_119 ;
int V_47 ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_415 ;
if ( ! V_7 -> V_223 -> V_266 )
return - V_415 ;
if ( V_17 -> V_416 )
return - V_538 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
if ( ! V_31 -> V_5 [ V_539 ] ||
! V_31 -> V_5 [ V_540 ] ||
! V_31 -> V_5 [ V_522 ] )
return - V_16 ;
V_47 = F_112 ( V_31 , & V_119 . V_541 ) ;
if ( V_47 )
return V_47 ;
V_119 . V_416 =
F_4 ( V_31 -> V_5 [ V_539 ] ) ;
V_119 . V_542 =
F_4 ( V_31 -> V_5 [ V_540 ] ) ;
V_47 = F_115 ( V_7 , V_119 . V_416 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_543 ] ) {
V_119 . V_482 = F_29 ( V_31 -> V_5 [ V_543 ] ) ;
V_119 . V_544 =
F_30 ( V_31 -> V_5 [ V_543 ] ) ;
if ( V_119 . V_544 == 0 ||
V_119 . V_544 > V_479 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_545 ] ) {
V_119 . V_546 = F_4 (
V_31 -> V_5 [ V_545 ] ) ;
if ( V_119 . V_546 != V_547 &&
V_119 . V_546 != V_548 &&
V_119 . V_546 != V_549 )
return - V_16 ;
}
V_119 . V_550 = ! ! V_31 -> V_5 [ V_551 ] ;
if ( V_31 -> V_5 [ V_552 ] ) {
V_119 . V_553 = F_4 (
V_31 -> V_5 [ V_552 ] ) ;
if ( ! F_116 ( V_119 . V_553 ) )
return - V_16 ;
} else
V_119 . V_553 = V_554 ;
V_47 = F_117 ( V_7 , V_31 , & V_119 . V_555 ,
V_556 ) ;
if ( V_47 )
return V_47 ;
if ( V_31 -> V_5 [ V_557 ] ) {
if ( ! ( V_7 -> V_18 . V_380 & V_558 ) )
return - V_415 ;
V_119 . V_559 = F_72 (
V_31 -> V_5 [ V_557 ] ) ;
}
if ( V_31 -> V_5 [ V_414 ] ) {
enum V_405 V_406 = V_408 ;
if ( V_31 -> V_5 [ V_407 ] &&
! F_74 ( V_31 , & V_406 ) )
return - V_16 ;
V_119 . V_412 = F_76 ( V_7 ,
F_4 ( V_31 -> V_5 [ V_414 ] ) ,
V_406 ) ;
if ( ! V_119 . V_412 )
return - V_16 ;
V_119 . V_406 = V_406 ;
} else if ( V_17 -> V_418 ) {
V_119 . V_412 = V_17 -> V_418 ;
V_119 . V_406 = V_17 -> V_419 ;
} else if ( ! F_113 ( V_7 , & V_119 ) )
return - V_16 ;
if ( ! F_77 ( & V_7 -> V_18 , V_119 . V_412 ,
V_119 . V_406 ) )
return - V_16 ;
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_118 ( V_7 , V_17 , V_119 . V_412 ,
V_560 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_47 )
return V_47 ;
V_47 = V_7 -> V_223 -> V_266 ( & V_7 -> V_18 , V_46 , & V_119 ) ;
if ( ! V_47 ) {
V_17 -> V_418 = V_119 . V_412 ;
V_17 -> V_419 = V_119 . V_406 ;
V_17 -> V_416 = V_119 . V_416 ;
V_17 -> V_412 = V_119 . V_412 ;
}
return V_47 ;
}
static int F_119 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_515 V_119 ;
int V_47 ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_415 ;
if ( ! V_7 -> V_223 -> V_561 )
return - V_415 ;
if ( ! V_17 -> V_416 )
return - V_16 ;
V_47 = F_112 ( V_31 , & V_119 ) ;
if ( V_47 )
return V_47 ;
return V_7 -> V_223 -> V_561 ( & V_7 -> V_18 , V_46 , & V_119 ) ;
}
static int F_120 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
return F_121 ( V_7 , V_46 ) ;
}
static int F_122 ( struct V_30 * V_31 ,
enum V_337 V_121 ,
struct V_562 * V_119 )
{
struct V_4 * V_56 [ V_563 + 1 ] ;
struct V_4 * V_462 ;
int V_465 ;
V_462 = V_31 -> V_5 [ V_564 ] ;
if ( V_462 ) {
struct V_565 * V_566 ;
V_566 = F_29 ( V_462 ) ;
V_119 -> V_567 = V_566 -> V_568 ;
V_119 -> V_569 = V_566 -> V_570 ;
if ( ( V_119 -> V_567 |
V_119 -> V_569 ) & F_123 ( V_571 ) )
return - V_16 ;
return 0 ;
}
V_462 = V_31 -> V_5 [ V_572 ] ;
if ( ! V_462 )
return 0 ;
if ( F_38 ( V_56 , V_563 ,
V_462 , V_573 ) )
return - V_16 ;
switch ( V_121 ) {
case V_122 :
case V_123 :
case V_124 :
V_119 -> V_567 = F_123 ( V_574 ) |
F_123 ( V_575 ) |
F_123 ( V_576 ) |
F_123 ( V_577 ) ;
break;
case V_130 :
case V_129 :
V_119 -> V_567 = F_123 ( V_574 ) |
F_123 ( V_578 ) ;
break;
case V_125 :
V_119 -> V_567 = F_123 ( V_579 ) |
F_123 ( V_577 ) |
F_123 ( V_574 ) ;
default:
return - V_16 ;
}
for ( V_465 = 1 ; V_465 <= V_563 ; V_465 ++ ) {
if ( V_56 [ V_465 ] ) {
V_119 -> V_569 |= ( 1 << V_465 ) ;
if ( V_465 > V_580 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_124 ( struct V_44 * V_58 , struct V_581 * V_31 ,
int V_50 )
{
struct V_4 * V_170 ;
V_23 V_256 ;
T_3 V_582 ;
V_170 = F_50 ( V_58 , V_50 ) ;
if ( ! V_170 )
goto V_63;
V_256 = F_125 ( V_31 ) ;
V_582 = V_256 < ( 1UL << 16 ) ? V_256 : 0 ;
if ( ( V_256 > 0 &&
F_34 ( V_58 , V_583 , V_256 ) ) ||
( V_582 > 0 &&
F_57 ( V_58 , V_584 , V_582 ) ) ||
( ( V_31 -> V_56 & V_585 ) &&
F_56 ( V_58 , V_586 , V_31 -> V_237 ) ) ||
( ( V_31 -> V_56 & V_587 ) &&
F_35 ( V_58 , V_588 ) ) ||
( ( V_31 -> V_56 & V_589 ) &&
F_35 ( V_58 , V_590 ) ) )
goto V_63;
F_51 ( V_58 , V_170 ) ;
return true ;
V_63:
return false ;
}
static int F_126 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 ,
struct V_6 * V_7 ,
struct V_26 * V_46 ,
const T_2 * V_500 , struct V_591 * V_592 )
{
void * V_159 ;
struct V_4 * V_593 , * V_594 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_595 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_500 ) ||
F_34 ( V_58 , V_175 , V_592 -> V_596 ) )
goto V_63;
V_593 = F_50 ( V_58 , V_597 ) ;
if ( ! V_593 )
goto V_63;
if ( ( V_592 -> V_598 & V_599 ) &&
F_34 ( V_58 , V_600 ,
V_592 -> V_601 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_602 ) &&
F_34 ( V_58 , V_603 ,
V_592 -> V_604 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_605 ) &&
F_34 ( V_58 , V_606 ,
V_592 -> V_607 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_608 ) &&
F_34 ( V_58 , V_609 ,
V_592 -> V_610 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_611 ) &&
F_57 ( V_58 , V_612 , V_592 -> V_613 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_614 ) &&
F_57 ( V_58 , V_615 , V_592 -> V_616 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_617 ) &&
F_56 ( V_58 , V_618 ,
V_592 -> V_619 ) )
goto V_63;
switch ( V_7 -> V_18 . V_620 ) {
case V_621 :
if ( ( V_592 -> V_598 & V_622 ) &&
F_56 ( V_58 , V_623 ,
V_592 -> signal ) )
goto V_63;
if ( ( V_592 -> V_598 & V_624 ) &&
F_56 ( V_58 , V_625 ,
V_592 -> V_626 ) )
goto V_63;
break;
default:
break;
}
if ( V_592 -> V_598 & V_627 ) {
if ( ! F_124 ( V_58 , & V_592 -> V_628 ,
V_629 ) )
goto V_63;
}
if ( V_592 -> V_598 & V_630 ) {
if ( ! F_124 ( V_58 , & V_592 -> V_631 ,
V_632 ) )
goto V_63;
}
if ( ( V_592 -> V_598 & V_633 ) &&
F_34 ( V_58 , V_634 ,
V_592 -> V_635 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_636 ) &&
F_34 ( V_58 , V_637 ,
V_592 -> V_638 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_639 ) &&
F_34 ( V_58 , V_640 ,
V_592 -> V_641 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_642 ) &&
F_34 ( V_58 , V_643 ,
V_592 -> V_644 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_645 ) &&
F_34 ( V_58 , V_646 ,
V_592 -> V_647 ) )
goto V_63;
if ( V_592 -> V_598 & V_648 ) {
V_594 = F_50 ( V_58 , V_649 ) ;
if ( ! V_594 )
goto V_63;
if ( ( ( V_592 -> V_594 . V_56 & V_650 ) &&
F_35 ( V_58 , V_651 ) ) ||
( ( V_592 -> V_594 . V_56 & V_652 ) &&
F_35 ( V_58 , V_653 ) ) ||
( ( V_592 -> V_594 . V_56 & V_654 ) &&
F_35 ( V_58 , V_655 ) ) ||
F_56 ( V_58 , V_656 ,
V_592 -> V_594 . V_542 ) ||
F_57 ( V_58 , V_657 ,
V_592 -> V_594 . V_416 ) )
goto V_63;
F_51 ( V_58 , V_594 ) ;
}
if ( ( V_592 -> V_598 & V_658 ) &&
F_58 ( V_58 , V_659 ,
sizeof( struct V_565 ) ,
& V_592 -> V_566 ) )
goto V_63;
if ( ( V_592 -> V_598 & V_660 ) &&
F_88 ( V_58 , V_661 ,
V_592 -> V_662 ) )
goto V_63;
F_51 ( V_58 , V_593 ) ;
if ( ( V_592 -> V_598 & V_663 ) &&
F_58 ( V_58 , V_519 , V_592 -> V_664 ,
V_592 -> V_665 ) )
goto V_63;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_383 ;
}
static int F_127 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_591 V_592 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_500 [ V_454 ] ;
int V_666 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_223 -> V_667 ) {
V_47 = - V_415 ;
goto V_668;
}
while ( 1 ) {
memset ( & V_592 , 0 , sizeof( V_592 ) ) ;
V_47 = V_46 -> V_223 -> V_667 ( & V_46 -> V_18 , V_20 , V_666 ,
V_500 , & V_592 ) ;
if ( V_47 == - V_507 )
break;
if ( V_47 )
goto V_668;
if ( F_126 ( V_45 ,
F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_385 , V_386 ,
V_46 , V_20 , V_500 ,
& V_592 ) < 0 )
goto V_461;
V_666 ++ ;
}
V_461:
V_35 -> args [ 1 ] = V_666 ;
V_47 = V_45 -> V_52 ;
V_668:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_128 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_591 V_592 ;
struct V_44 * V_58 ;
T_2 * V_500 = NULL ;
int V_47 ;
memset ( & V_592 , 0 , sizeof( V_592 ) ) ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
V_500 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( ! V_7 -> V_223 -> V_669 )
return - V_415 ;
V_47 = V_7 -> V_223 -> V_669 ( & V_7 -> V_18 , V_46 , V_500 , & V_592 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_126 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_7 , V_46 , V_500 , & V_592 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static struct V_26 * F_129 ( struct V_30 * V_31 ,
struct V_6 * V_7 )
{
struct V_4 * V_670 = V_31 -> V_5 [ V_671 ] ;
struct V_26 * V_672 ;
int V_537 ;
if ( ! V_670 )
return NULL ;
V_672 = F_12 ( F_84 ( V_31 ) , F_4 ( V_670 ) ) ;
if ( ! V_672 )
return F_3 ( - V_24 ) ;
if ( ! V_672 -> V_29 || V_672 -> V_29 -> V_18 != & V_7 -> V_18 ) {
V_537 = - V_16 ;
goto error;
}
if ( ! F_82 ( V_672 ) ) {
V_537 = - V_430 ;
goto error;
}
return V_672 ;
error:
F_14 ( V_672 ) ;
return F_3 ( V_537 ) ;
}
static int F_130 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_562 V_119 ;
T_2 * V_500 = NULL ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_673 = - 1 ;
V_119 . V_619 = - 1 ;
if ( V_31 -> V_5 [ V_674 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
V_500 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( V_31 -> V_5 [ V_675 ] ) {
V_119 . V_676 =
F_29 ( V_31 -> V_5 [ V_675 ] ) ;
V_119 . V_677 =
F_30 ( V_31 -> V_5 [ V_675 ] ) ;
}
if ( V_31 -> V_5 [ V_678 ] )
V_119 . V_673 =
F_72 ( V_31 -> V_5 [ V_678 ] ) ;
if ( V_31 -> V_5 [ V_679 ] )
V_119 . V_680 =
F_29 ( V_31 -> V_5 [ V_679 ] ) ;
if ( ! V_7 -> V_223 -> V_681 )
return - V_415 ;
if ( F_122 ( V_31 , V_46 -> V_29 -> V_121 , & V_119 ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_682 ] )
V_119 . V_683 =
F_39 ( V_31 -> V_5 [ V_682 ] ) ;
if ( V_31 -> V_5 [ V_684 ] )
V_119 . V_619 =
F_39 ( V_31 -> V_5 [ V_684 ] ) ;
switch ( V_46 -> V_29 -> V_121 ) {
case V_122 :
case V_123 :
case V_124 :
if ( V_119 . V_683 )
return - V_16 ;
if ( V_119 . V_569 & F_123 ( V_578 ) )
return - V_16 ;
V_119 . V_567 &= ~ F_123 ( V_578 ) ;
if ( V_119 . V_567 &
~ ( F_123 ( V_574 ) |
F_123 ( V_575 ) |
F_123 ( V_576 ) |
F_123 ( V_577 ) ) )
return - V_16 ;
V_119 . V_685 = F_129 ( V_31 , V_7 ) ;
if ( F_16 ( V_119 . V_685 ) )
return F_24 ( V_119 . V_685 ) ;
break;
case V_130 :
case V_129 :
V_119 . V_567 &= ~ F_123 ( V_578 ) ;
case V_126 :
if ( V_119 . V_683 )
return - V_16 ;
if ( V_119 . V_680 )
return - V_16 ;
if ( V_119 . V_673 >= 0 )
return - V_16 ;
if ( V_119 . V_567 & ~ F_123 ( V_574 ) )
return - V_16 ;
break;
case V_125 :
if ( V_119 . V_685 )
return - V_16 ;
if ( V_119 . V_680 )
return - V_16 ;
if ( V_119 . V_673 >= 0 )
return - V_16 ;
if ( V_119 . V_567 &
~ ( F_123 ( V_579 ) |
F_123 ( V_577 ) |
F_123 ( V_574 ) ) )
return - V_16 ;
break;
default:
return - V_415 ;
}
V_47 = V_7 -> V_223 -> V_681 ( & V_7 -> V_18 , V_46 , V_500 , & V_119 ) ;
if ( V_119 . V_685 )
F_14 ( V_119 . V_685 ) ;
return V_47 ;
}
static int F_131 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_562 V_119 ;
T_2 * V_500 = NULL ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_678 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_675 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_674 ] )
return - V_16 ;
V_500 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_119 . V_676 =
F_29 ( V_31 -> V_5 [ V_675 ] ) ;
V_119 . V_677 =
F_30 ( V_31 -> V_5 [ V_675 ] ) ;
V_119 . V_673 =
F_72 ( V_31 -> V_5 [ V_678 ] ) ;
V_119 . V_686 = F_72 ( V_31 -> V_5 [ V_674 ] ) ;
if ( ! V_119 . V_686 || V_119 . V_686 > V_687 )
return - V_16 ;
if ( V_31 -> V_5 [ V_679 ] )
V_119 . V_680 =
F_29 ( V_31 -> V_5 [ V_679 ] ) ;
if ( V_31 -> V_5 [ V_682 ] )
V_119 . V_683 =
F_39 ( V_31 -> V_5 [ V_682 ] ) ;
if ( ! V_7 -> V_223 -> V_268 )
return - V_415 ;
if ( F_122 ( V_31 , V_46 -> V_29 -> V_121 , & V_119 ) )
return - V_16 ;
switch ( V_46 -> V_29 -> V_121 ) {
case V_122 :
case V_123 :
case V_124 :
if ( ( V_7 -> V_18 . V_56 & V_201 ) &&
( V_119 . V_569 & F_123 ( V_576 ) ) &&
V_31 -> V_5 [ V_688 ] ) {
struct V_4 * V_78 [ V_689 + 1 ] ;
struct V_4 * V_462 ;
V_462 = V_31 -> V_5 [ V_688 ] ;
V_47 = F_38 ( V_78 , V_689 , V_462 ,
V_690 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_691 ] )
V_119 . V_692 =
F_39 ( V_78 [ V_691 ] ) ;
if ( V_119 . V_692 &
~ V_693 )
return - V_16 ;
if ( V_78 [ V_694 ] )
V_119 . V_695 =
F_39 ( V_78 [ V_694 ] ) ;
if ( V_119 . V_695 &
~ V_696 )
return - V_16 ;
V_119 . V_697 |= V_698 ;
}
if ( V_119 . V_569 & F_123 ( V_578 ) )
return - V_16 ;
V_119 . V_567 &= ~ F_123 ( V_578 ) ;
V_119 . V_685 = F_129 ( V_31 , V_7 ) ;
if ( F_16 ( V_119 . V_685 ) )
return F_24 ( V_119 . V_685 ) ;
break;
case V_125 :
if ( V_119 . V_569 & F_123 ( V_578 ) )
return - V_16 ;
break;
case V_129 :
if ( ! ( V_119 . V_569 & F_123 ( V_578 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_56 & V_205 ) )
return - V_415 ;
if ( ! ( V_7 -> V_18 . V_56 & V_207 ) )
return - V_415 ;
break;
default:
return - V_415 ;
}
V_47 = V_7 -> V_223 -> V_268 ( & V_7 -> V_18 , V_46 , V_500 , & V_119 ) ;
if ( V_119 . V_685 )
F_14 ( V_119 . V_685 ) ;
return V_47 ;
}
static int F_132 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 * V_500 = NULL ;
if ( V_31 -> V_5 [ V_421 ] )
V_500 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_123 &&
V_46 -> V_29 -> V_121 != V_125 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_699 )
return - V_415 ;
return V_7 -> V_223 -> V_699 ( & V_7 -> V_18 , V_46 , V_500 ) ;
}
static int F_133 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
T_2 * V_700 , T_2 * V_701 ,
struct V_702 * V_703 )
{
void * V_159 ;
struct V_4 * V_704 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 , V_595 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_700 ) ||
F_58 ( V_58 , V_705 , V_454 , V_701 ) ||
F_34 ( V_58 , V_175 , V_703 -> V_596 ) )
goto V_63;
V_704 = F_50 ( V_58 , V_706 ) ;
if ( ! V_704 )
goto V_63;
if ( ( V_703 -> V_598 & V_707 ) &&
F_34 ( V_58 , V_708 ,
V_703 -> V_709 ) )
goto V_63;
if ( ( ( V_703 -> V_598 & V_710 ) &&
F_34 ( V_58 , V_711 , V_703 -> V_712 ) ) ||
( ( V_703 -> V_598 & V_713 ) &&
F_34 ( V_58 , V_714 ,
V_703 -> V_715 ) ) ||
( ( V_703 -> V_598 & V_716 ) &&
F_34 ( V_58 , V_717 ,
V_703 -> V_718 ) ) ||
( ( V_703 -> V_598 & V_719 ) &&
F_56 ( V_58 , V_720 ,
V_703 -> V_56 ) ) ||
( ( V_703 -> V_598 & V_721 ) &&
F_34 ( V_58 , V_722 ,
V_703 -> V_723 ) ) ||
( ( V_703 -> V_598 & V_724 ) &&
F_56 ( V_58 , V_725 ,
V_703 -> V_726 ) ) )
goto V_63;
F_51 ( V_58 , V_704 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_383 ;
}
static int F_134 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_702 V_703 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
T_2 V_700 [ V_454 ] ;
T_2 V_701 [ V_454 ] ;
int V_727 = V_35 -> args [ 1 ] ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_46 -> V_223 -> V_728 ) {
V_47 = - V_415 ;
goto V_668;
}
if ( V_20 -> V_29 -> V_121 != V_125 ) {
V_47 = - V_415 ;
goto V_668;
}
while ( 1 ) {
V_47 = V_46 -> V_223 -> V_728 ( & V_46 -> V_18 , V_20 , V_727 ,
V_700 , V_701 , & V_703 ) ;
if ( V_47 == - V_507 )
break;
if ( V_47 )
goto V_668;
if ( F_133 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_385 , V_386 ,
V_20 , V_700 , V_701 ,
& V_703 ) < 0 )
goto V_461;
V_727 ++ ;
}
V_461:
V_35 -> args [ 1 ] = V_727 ;
V_47 = V_45 -> V_52 ;
V_668:
F_26 ( V_46 ) ;
return V_47 ;
}
static int F_135 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_702 V_703 ;
struct V_44 * V_58 ;
T_2 * V_700 = NULL ;
T_2 V_701 [ V_454 ] ;
memset ( & V_703 , 0 , sizeof( V_703 ) ) ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
V_700 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( ! V_7 -> V_223 -> V_729 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_125 )
return - V_415 ;
V_47 = V_7 -> V_223 -> V_729 ( & V_7 -> V_18 , V_46 , V_700 , V_701 , & V_703 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
if ( F_133 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_46 , V_700 , V_701 , & V_703 ) < 0 ) {
F_69 ( V_58 ) ;
return - V_74 ;
}
return F_70 ( V_58 , V_31 ) ;
}
static int F_136 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 * V_700 = NULL ;
T_2 * V_701 = NULL ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_705 ] )
return - V_16 ;
V_700 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_701 = F_29 ( V_31 -> V_5 [ V_705 ] ) ;
if ( ! V_7 -> V_223 -> V_730 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_125 )
return - V_415 ;
return V_7 -> V_223 -> V_730 ( & V_7 -> V_18 , V_46 , V_700 , V_701 ) ;
}
static int F_137 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 * V_700 = NULL ;
T_2 * V_701 = NULL ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_705 ] )
return - V_16 ;
V_700 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_701 = F_29 ( V_31 -> V_5 [ V_705 ] ) ;
if ( ! V_7 -> V_223 -> V_270 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_125 )
return - V_415 ;
return V_7 -> V_223 -> V_270 ( & V_7 -> V_18 , V_46 , V_700 , V_701 ) ;
}
static int F_138 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 * V_700 = NULL ;
if ( V_31 -> V_5 [ V_421 ] )
V_700 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( ! V_7 -> V_223 -> V_731 )
return - V_415 ;
return V_7 -> V_223 -> V_731 ( & V_7 -> V_18 , V_46 , V_700 ) ;
}
static int F_139 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_732 V_119 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_733 = - 1 ;
V_119 . V_734 = - 1 ;
V_119 . V_735 = - 1 ;
V_119 . V_736 = - 1 ;
V_119 . V_737 = - 1 ;
if ( V_31 -> V_5 [ V_738 ] )
V_119 . V_733 =
F_39 ( V_31 -> V_5 [ V_738 ] ) ;
if ( V_31 -> V_5 [ V_739 ] )
V_119 . V_734 =
F_39 ( V_31 -> V_5 [ V_739 ] ) ;
if ( V_31 -> V_5 [ V_740 ] )
V_119 . V_735 =
F_39 ( V_31 -> V_5 [ V_740 ] ) ;
if ( V_31 -> V_5 [ V_741 ] ) {
V_119 . V_742 =
F_29 ( V_31 -> V_5 [ V_741 ] ) ;
V_119 . V_743 =
F_30 ( V_31 -> V_5 [ V_741 ] ) ;
}
if ( V_31 -> V_5 [ V_744 ] )
V_119 . V_736 = ! ! F_39 ( V_31 -> V_5 [ V_744 ] ) ;
if ( V_31 -> V_5 [ V_745 ] )
V_119 . V_737 =
F_72 ( V_31 -> V_5 [ V_745 ] ) ;
if ( ! V_7 -> V_223 -> V_274 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_122 &&
V_46 -> V_29 -> V_121 != V_124 )
return - V_415 ;
return V_7 -> V_223 -> V_274 ( & V_7 -> V_18 , V_46 , & V_119 ) ;
}
static int F_140 ( struct V_4 * V_78 [] ,
struct V_746 * V_747 )
{
struct V_748 * V_749 = & V_747 -> V_749 ;
struct V_750 * V_751 = & V_747 -> V_751 ;
if ( ! V_78 [ V_752 ] )
return - V_16 ;
if ( ! V_78 [ V_753 ] )
return - V_16 ;
if ( ! V_78 [ V_754 ] )
return - V_16 ;
if ( ! V_78 [ V_755 ] )
return - V_16 ;
if ( ! V_78 [ V_756 ] )
return - V_16 ;
V_747 -> V_56 = F_4 ( V_78 [ V_752 ] ) ;
V_749 -> V_757 =
F_4 ( V_78 [ V_753 ] ) ;
V_749 -> V_758 =
F_4 ( V_78 [ V_754 ] ) ;
V_749 -> V_759 =
F_4 ( V_78 [ V_755 ] ) ;
V_751 -> V_760 =
F_4 ( V_78 [ V_756 ] ) ;
if ( V_78 [ V_761 ] )
V_751 -> V_762 =
F_4 ( V_78 [ V_761 ] ) ;
return 0 ;
}
static int F_141 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
int V_763 ;
char * V_120 = NULL ;
enum V_764 V_765 ;
F_8 ( & V_32 ) ;
if ( F_142 ( ! V_766 ) ) {
F_9 ( & V_32 ) ;
return - V_767 ;
}
F_9 ( & V_32 ) ;
if ( ! V_31 -> V_5 [ V_768 ] )
return - V_16 ;
V_120 = F_29 ( V_31 -> V_5 [ V_768 ] ) ;
if ( V_31 -> V_5 [ V_769 ] )
V_765 =
F_4 ( V_31 -> V_5 [ V_769 ] ) ;
else
V_765 = V_770 ;
switch ( V_765 ) {
case V_770 :
case V_771 :
break;
default:
return - V_16 ;
}
V_763 = F_143 ( V_120 , V_765 ) ;
return V_763 ;
}
static int F_144 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_772 V_773 ;
int V_47 = 0 ;
void * V_159 ;
struct V_4 * V_704 ;
struct V_44 * V_58 ;
if ( V_17 -> V_121 != V_125 )
return - V_415 ;
if ( ! V_7 -> V_223 -> V_774 )
return - V_415 ;
F_95 ( V_17 ) ;
if ( ! V_17 -> V_775 )
memcpy ( & V_773 , & V_776 , sizeof( V_773 ) ) ;
else
V_47 = V_7 -> V_223 -> V_774 ( & V_7 -> V_18 , V_46 ,
& V_773 ) ;
F_97 ( V_17 ) ;
if ( V_47 )
return V_47 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_777 ) ;
if ( ! V_159 )
goto V_461;
V_704 = F_50 ( V_58 , V_778 ) ;
if ( ! V_704 )
goto V_63;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_57 ( V_58 , V_779 ,
V_773 . V_780 ) ||
F_57 ( V_58 , V_781 ,
V_773 . V_782 ) ||
F_57 ( V_58 , V_783 ,
V_773 . V_784 ) ||
F_57 ( V_58 , V_785 ,
V_773 . V_786 ) ||
F_56 ( V_58 , V_787 ,
V_773 . V_788 ) ||
F_56 ( V_58 , V_789 ,
V_773 . V_790 ) ||
F_56 ( V_58 , V_791 ,
V_773 . V_792 ) ||
F_56 ( V_58 , V_793 ,
V_773 . V_794 ) ||
F_34 ( V_58 , V_795 ,
V_773 . V_796 ) ||
F_56 ( V_58 , V_797 ,
V_773 . V_798 ) ||
F_34 ( V_58 , V_799 ,
V_773 . V_800 ) ||
F_57 ( V_58 , V_801 ,
V_773 . V_802 ) ||
F_34 ( V_58 , V_803 ,
V_773 . V_804 ) ||
F_57 ( V_58 , V_805 ,
V_773 . V_806 ) ||
F_57 ( V_58 , V_807 ,
V_773 . V_808 ) ||
F_57 ( V_58 , V_809 ,
V_773 . V_810 ) ||
F_56 ( V_58 , V_811 ,
V_773 . V_812 ) ||
F_57 ( V_58 , V_813 ,
V_773 . V_814 ) ||
F_56 ( V_58 , V_815 ,
V_773 . V_816 ) ||
F_56 ( V_58 , V_817 ,
V_773 . V_818 ) ||
F_34 ( V_58 , V_819 ,
V_773 . V_820 ) ||
F_34 ( V_58 , V_821 ,
V_773 . V_737 ) ||
F_34 ( V_58 , V_822 ,
V_773 . V_823 ) ||
F_57 ( V_58 , V_824 ,
V_773 . V_825 ) ||
F_57 ( V_58 , V_826 ,
V_773 . V_827 ) )
goto V_63;
F_51 ( V_58 , V_704 ) ;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
V_461:
F_69 ( V_58 ) ;
return - V_74 ;
}
static int F_145 ( struct V_30 * V_31 ,
struct V_772 * V_828 ,
V_23 * V_829 )
{
struct V_4 * V_78 [ V_830 + 1 ] ;
V_23 V_568 = 0 ;
#define F_146 ( T_6 , V_828 , T_7 , V_568 , T_8 , T_9 ) \
do {\
if (table[attr_num]) {\
cfg->param = nla_fn(table[attr_num]); \
mask |= (1 << (attr_num - 1)); \
} \
} while (0);\
if (!info->attrs[NL80211_ATTR_MESH_CONFIG])
return - V_16 ;
if ( F_38 ( V_78 , V_830 ,
V_31 -> V_5 [ V_778 ] ,
V_831 ) )
return - V_16 ;
F_96 ( V_830 > 32 ) ;
F_146 ( V_78 , V_828 , V_780 ,
V_568 , V_779 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_782 ,
V_568 , V_781 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_784 ,
V_568 , V_783 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_786 ,
V_568 , V_785 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_788 ,
V_568 , V_787 ,
F_39 ) ;
F_146 ( V_78 , V_828 , V_790 ,
V_568 , V_789 , F_39 ) ;
F_146 ( V_78 , V_828 , V_792 ,
V_568 , V_791 ,
F_39 ) ;
F_146 ( V_78 , V_828 , V_794 ,
V_568 , V_793 ,
F_39 ) ;
F_146 ( V_78 , V_828 , V_796 , V_568 ,
V_795 ,
F_4 ) ;
F_146 ( V_78 , V_828 , V_798 ,
V_568 , V_797 ,
F_39 ) ;
F_146 ( V_78 , V_828 , V_800 ,
V_568 , V_799 ,
F_4 ) ;
F_146 ( V_78 , V_828 , V_802 ,
V_568 , V_801 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_804 , V_568 ,
V_803 ,
F_4 ) ;
F_146 ( V_78 , V_828 , V_806 ,
V_568 , V_805 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_808 ,
V_568 , V_807 ,
F_72 ) ;
F_146 ( V_78 , V_828 ,
V_810 , V_568 ,
V_809 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_812 , V_568 ,
V_811 , F_39 ) ;
F_146 ( V_78 , V_828 , V_814 , V_568 ,
V_813 ,
F_72 ) ;
F_146 ( V_78 , V_828 ,
V_816 , V_568 ,
V_815 ,
F_39 ) ;
F_146 ( V_78 , V_828 , V_818 ,
V_568 , V_817 ,
F_39 ) ;
F_146 ( V_78 , V_828 , V_820 ,
V_568 , V_819 ,
F_4 ) ;
F_146 ( V_78 , V_828 , V_737 ,
V_568 , V_821 ,
F_72 ) ;
F_146 ( V_78 , V_828 , V_823 ,
V_568 ,
V_822 ,
F_4 ) ;
F_146 ( V_78 , V_828 , V_825 ,
V_568 , V_824 ,
F_72 ) ;
F_146 ( V_78 , V_828 ,
V_827 , V_568 ,
V_826 ,
F_72 ) ;
if ( V_829 )
* V_829 = V_568 ;
return 0 ;
#undef F_146
}
static int F_147 ( struct V_30 * V_31 ,
struct V_832 * V_833 )
{
struct V_4 * V_78 [ V_834 + 1 ] ;
if ( ! V_31 -> V_5 [ V_835 ] )
return - V_16 ;
if ( F_38 ( V_78 , V_834 ,
V_31 -> V_5 [ V_835 ] ,
V_836 ) )
return - V_16 ;
if ( V_78 [ V_837 ] )
V_833 -> V_838 =
( F_39 ( V_78 [ V_837 ] ) ) ?
V_839 :
V_840 ;
if ( V_78 [ V_841 ] )
V_833 -> V_842 =
( F_39 ( V_78 [ V_841 ] ) ) ?
V_843 :
V_844 ;
if ( V_78 [ V_845 ] )
V_833 -> V_846 =
( F_39 ( V_78 [ V_845 ] ) ) ?
V_847 :
V_848 ;
if ( V_78 [ V_849 ] ) {
struct V_4 * V_850 =
V_78 [ V_849 ] ;
if ( ! F_28 ( V_850 ) )
return - V_16 ;
V_833 -> V_851 = F_29 ( V_850 ) ;
V_833 -> V_852 = F_30 ( V_850 ) ;
}
V_833 -> V_853 = F_148 ( V_78 [ V_854 ] ) ;
V_833 -> V_855 = F_148 ( V_78 [ V_856 ] ) ;
return 0 ;
}
static int F_149 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_772 V_828 ;
V_23 V_568 ;
int V_47 ;
if ( V_17 -> V_121 != V_125 )
return - V_415 ;
if ( ! V_7 -> V_223 -> V_272 )
return - V_415 ;
V_47 = F_145 ( V_31 , & V_828 , & V_568 ) ;
if ( V_47 )
return V_47 ;
F_95 ( V_17 ) ;
if ( ! V_17 -> V_775 )
V_47 = - V_128 ;
if ( ! V_47 )
V_47 = V_7 -> V_223 -> V_272 ( & V_7 -> V_18 , V_46 ,
V_568 , & V_828 ) ;
F_97 ( V_17 ) ;
return V_47 ;
}
static int F_150 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_44 * V_58 ;
void * V_159 = NULL ;
struct V_4 * V_857 ;
unsigned int V_135 ;
int V_47 = - V_16 ;
F_8 ( & V_32 ) ;
if ( ! V_766 )
goto V_461;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 ) {
V_47 = - V_74 ;
goto V_461;
}
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_858 ) ;
if ( ! V_159 )
goto V_859;
if ( F_54 ( V_58 , V_768 ,
V_766 -> V_860 ) ||
( V_766 -> V_861 &&
F_56 ( V_58 , V_862 ,
V_766 -> V_861 ) ) )
goto V_63;
if ( F_151 () &&
F_34 ( V_58 , V_769 ,
V_771 ) )
goto V_63;
V_857 = F_50 ( V_58 , V_863 ) ;
if ( ! V_857 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_766 -> V_864 ; V_135 ++ ) {
struct V_4 * V_865 ;
const struct V_746 * V_747 ;
const struct V_748 * V_749 ;
const struct V_750 * V_751 ;
V_747 = & V_766 -> V_866 [ V_135 ] ;
V_749 = & V_747 -> V_749 ;
V_751 = & V_747 -> V_751 ;
V_865 = F_50 ( V_58 , V_135 ) ;
if ( ! V_865 )
goto V_63;
if ( F_34 ( V_58 , V_752 ,
V_747 -> V_56 ) ||
F_34 ( V_58 , V_753 ,
V_749 -> V_757 ) ||
F_34 ( V_58 , V_754 ,
V_749 -> V_758 ) ||
F_34 ( V_58 , V_755 ,
V_749 -> V_759 ) ||
F_34 ( V_58 , V_761 ,
V_751 -> V_762 ) ||
F_34 ( V_58 , V_756 ,
V_751 -> V_760 ) )
goto V_63;
F_51 ( V_58 , V_865 ) ;
}
F_51 ( V_58 , V_857 ) ;
F_62 ( V_58 , V_159 ) ;
V_47 = F_70 ( V_58 , V_31 ) ;
goto V_461;
V_63:
F_63 ( V_58 , V_159 ) ;
V_859:
F_69 ( V_58 ) ;
V_47 = - V_383 ;
V_461:
F_9 ( & V_32 ) ;
return V_47 ;
}
static int F_152 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_867 + 1 ] ;
struct V_4 * V_865 ;
char * V_860 = NULL ;
int V_868 = 0 , V_763 = 0 ;
V_23 V_869 = 0 , V_870 = 0 , V_871 ;
T_2 V_861 = 0 ;
struct V_872 * V_873 = NULL ;
if ( ! V_31 -> V_5 [ V_768 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_863 ] )
return - V_16 ;
V_860 = F_29 ( V_31 -> V_5 [ V_768 ] ) ;
if ( V_31 -> V_5 [ V_862 ] )
V_861 = F_39 ( V_31 -> V_5 [ V_862 ] ) ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_869 ++ ;
if ( V_869 > V_874 )
return - V_16 ;
}
F_8 ( & V_32 ) ;
if ( ! F_153 ( V_860 ) ) {
V_763 = - V_16 ;
goto V_875;
}
V_871 = sizeof( struct V_872 ) +
( V_869 * sizeof( struct V_746 ) ) ;
V_873 = F_43 ( V_871 , V_117 ) ;
if ( ! V_873 ) {
V_763 = - V_118 ;
goto V_875;
}
V_873 -> V_864 = V_869 ;
V_873 -> V_860 [ 0 ] = V_860 [ 0 ] ;
V_873 -> V_860 [ 1 ] = V_860 [ 1 ] ;
if ( F_154 ( V_861 ) )
V_873 -> V_861 = V_861 ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_86 ( V_78 , V_867 ,
F_29 ( V_865 ) , F_30 ( V_865 ) ,
V_876 ) ;
V_763 = F_140 ( V_78 , & V_873 -> V_866 [ V_870 ] ) ;
if ( V_763 )
goto V_875;
V_870 ++ ;
if ( V_870 > V_874 ) {
V_763 = - V_16 ;
goto V_875;
}
}
F_155 ( V_870 != V_869 ) ;
V_763 = F_156 ( V_873 ) ;
F_9 ( & V_32 ) ;
return V_763 ;
V_875:
F_9 ( & V_32 ) ;
F_46 ( V_873 ) ;
return V_763 ;
}
static int F_157 ( struct V_4 * V_877 )
{
struct V_4 * V_878 , * V_879 ;
int V_250 = 0 , V_880 , V_881 ;
F_44 (attr1, freqs, tmp1) {
V_250 ++ ;
F_44 (attr2, freqs, tmp2)
if ( V_878 != V_879 &&
F_4 ( V_878 ) == F_4 ( V_879 ) )
return 0 ;
}
return V_250 ;
}
static int F_158 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
struct V_882 * V_883 ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_884 = 0 , V_250 , V_135 ;
T_10 V_852 ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_223 -> V_885 )
return - V_415 ;
if ( V_7 -> V_886 )
return - V_417 ;
if ( V_31 -> V_5 [ V_887 ] ) {
V_250 = F_157 (
V_31 -> V_5 [ V_887 ] ) ;
if ( ! V_250 )
return - V_16 ;
} else {
enum V_167 V_168 ;
V_250 = 0 ;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ )
if ( V_18 -> V_233 [ V_168 ] )
V_250 += V_18 -> V_233 [ V_168 ] -> V_250 ;
}
if ( V_31 -> V_5 [ V_888 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_884 ++ ;
if ( V_884 > V_18 -> V_188 )
return - V_16 ;
if ( V_31 -> V_5 [ V_519 ] )
V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
else
V_852 = 0 ;
if ( V_852 > V_18 -> V_192 )
return - V_16 ;
V_883 = F_43 ( sizeof( * V_883 )
+ sizeof( * V_883 -> V_889 ) * V_884
+ sizeof( * V_883 -> V_251 ) * V_250
+ V_852 , V_117 ) ;
if ( ! V_883 )
return - V_118 ;
if ( V_884 )
V_883 -> V_889 = ( void * ) & V_883 -> V_251 [ V_250 ] ;
V_883 -> V_884 = V_884 ;
if ( V_852 ) {
if ( V_883 -> V_889 )
V_883 -> V_851 = ( void * ) ( V_883 -> V_889 + V_884 ) ;
else
V_883 -> V_851 = ( void * ) ( V_883 -> V_251 + V_250 ) ;
}
V_135 = 0 ;
if ( V_31 -> V_5 [ V_887 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_59 * V_60 ;
V_60 = F_159 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_890;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_883 -> V_251 [ V_135 ] = V_60 ;
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
V_883 -> V_251 [ V_135 ] = V_60 ;
V_135 ++ ;
}
}
}
if ( ! V_135 ) {
V_47 = - V_16 ;
goto V_890;
}
V_883 -> V_250 = V_135 ;
V_135 = 0 ;
if ( V_31 -> V_5 [ V_888 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_30 ( V_50 ) > V_479 ) {
V_47 = - V_16 ;
goto V_890;
}
V_883 -> V_889 [ V_135 ] . V_544 = F_30 ( V_50 ) ;
memcpy ( V_883 -> V_889 [ V_135 ] . V_482 , F_29 ( V_50 ) , F_30 ( V_50 ) ) ;
V_135 ++ ;
}
}
if ( V_31 -> V_5 [ V_519 ] ) {
V_883 -> V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
memcpy ( ( void * ) V_883 -> V_851 ,
F_29 ( V_31 -> V_5 [ V_519 ] ) ,
V_883 -> V_852 ) ;
}
for ( V_135 = 0 ; V_135 < V_232 ; V_135 ++ )
if ( V_18 -> V_233 [ V_135 ] )
V_883 -> V_891 [ V_135 ] =
( 1 << V_18 -> V_233 [ V_135 ] -> V_253 ) - 1 ;
if ( V_31 -> V_5 [ V_892 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_167 V_168 = F_160 ( V_50 ) ;
if ( V_168 < 0 || V_168 >= V_232 ) {
V_47 = - V_16 ;
goto V_890;
}
V_47 = F_161 ( V_18 -> V_233 [ V_168 ] ,
F_29 ( V_50 ) ,
F_30 ( V_50 ) ,
& V_883 -> V_891 [ V_168 ] ) ;
if ( V_47 )
goto V_890;
}
}
V_883 -> V_893 =
F_148 ( V_31 -> V_5 [ V_894 ] ) ;
V_883 -> V_17 = V_17 ;
V_883 -> V_18 = & V_7 -> V_18 ;
V_7 -> V_886 = V_883 ;
V_47 = V_7 -> V_223 -> V_885 ( & V_7 -> V_18 , V_883 ) ;
if ( ! V_47 ) {
F_162 ( V_7 , V_17 ) ;
if ( V_17 -> V_20 )
F_163 ( V_17 -> V_20 ) ;
} else {
V_890:
V_7 -> V_886 = NULL ;
F_46 ( V_883 ) ;
}
return V_47 ;
}
static int F_164 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_895 * V_883 ;
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_4 * V_50 ;
struct V_18 * V_18 ;
int V_47 , V_25 , V_884 = 0 , V_896 = 0 , V_250 , V_135 ;
V_23 V_897 ;
enum V_167 V_168 ;
T_10 V_852 ;
struct V_4 * V_78 [ V_898 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_56 & V_313 ) ||
! V_7 -> V_223 -> V_314 )
return - V_415 ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_899 ] )
return - V_16 ;
V_897 = F_4 ( V_31 -> V_5 [ V_899 ] ) ;
if ( V_897 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_887 ] ) {
V_250 = F_157 (
V_31 -> V_5 [ V_887 ] ) ;
if ( ! V_250 )
return - V_16 ;
} else {
V_250 = 0 ;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ )
if ( V_18 -> V_233 [ V_168 ] )
V_250 += V_18 -> V_233 [ V_168 ] -> V_250 ;
}
if ( V_31 -> V_5 [ V_888 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_884 ++ ;
if ( V_884 > V_18 -> V_190 )
return - V_16 ;
if ( V_31 -> V_5 [ V_900 ] )
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_896 ++ ;
if ( V_896 > V_18 -> V_196 )
return - V_16 ;
if ( V_31 -> V_5 [ V_519 ] )
V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
else
V_852 = 0 ;
if ( V_852 > V_18 -> V_194 )
return - V_16 ;
F_8 ( & V_7 -> V_901 ) ;
if ( V_7 -> V_902 ) {
V_47 = - V_767 ;
goto V_461;
}
V_883 = F_43 ( sizeof( * V_883 )
+ sizeof( * V_883 -> V_889 ) * V_884
+ sizeof( * V_883 -> V_903 ) * V_896
+ sizeof( * V_883 -> V_251 ) * V_250
+ V_852 , V_117 ) ;
if ( ! V_883 ) {
V_47 = - V_118 ;
goto V_461;
}
if ( V_884 )
V_883 -> V_889 = ( void * ) & V_883 -> V_251 [ V_250 ] ;
V_883 -> V_884 = V_884 ;
if ( V_852 ) {
if ( V_883 -> V_889 )
V_883 -> V_851 = ( void * ) ( V_883 -> V_889 + V_884 ) ;
else
V_883 -> V_851 = ( void * ) ( V_883 -> V_251 + V_250 ) ;
}
if ( V_896 ) {
if ( V_883 -> V_851 )
V_883 -> V_903 = ( void * ) ( V_883 -> V_851 + V_852 ) ;
else if ( V_883 -> V_889 )
V_883 -> V_903 =
( void * ) ( V_883 -> V_889 + V_884 ) ;
else
V_883 -> V_903 =
( void * ) ( V_883 -> V_251 + V_250 ) ;
}
V_883 -> V_896 = V_896 ;
V_135 = 0 ;
if ( V_31 -> V_5 [ V_887 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_59 * V_60 ;
V_60 = F_159 ( V_18 , F_4 ( V_50 ) ) ;
if ( ! V_60 ) {
V_47 = - V_16 ;
goto V_890;
}
if ( V_60 -> V_56 & V_64 )
continue;
V_883 -> V_251 [ V_135 ] = V_60 ;
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
V_883 -> V_251 [ V_135 ] = V_60 ;
V_135 ++ ;
}
}
}
if ( ! V_135 ) {
V_47 = - V_16 ;
goto V_890;
}
V_883 -> V_250 = V_135 ;
V_135 = 0 ;
if ( V_31 -> V_5 [ V_888 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_30 ( V_50 ) > V_479 ) {
V_47 = - V_16 ;
goto V_890;
}
V_883 -> V_889 [ V_135 ] . V_544 = F_30 ( V_50 ) ;
memcpy ( V_883 -> V_889 [ V_135 ] . V_482 , F_29 ( V_50 ) ,
F_30 ( V_50 ) ) ;
V_135 ++ ;
}
}
V_135 = 0 ;
if ( V_31 -> V_5 [ V_900 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_482 , * V_904 ;
F_86 ( V_78 , V_898 ,
F_29 ( V_50 ) , F_30 ( V_50 ) ,
V_905 ) ;
V_482 = V_78 [ V_906 ] ;
if ( V_482 ) {
if ( F_30 ( V_482 ) > V_479 ) {
V_47 = - V_16 ;
goto V_890;
}
memcpy ( V_883 -> V_903 [ V_135 ] . V_482 . V_482 ,
F_29 ( V_482 ) , F_30 ( V_482 ) ) ;
V_883 -> V_903 [ V_135 ] . V_482 . V_544 =
F_30 ( V_482 ) ;
}
V_904 = V_78 [ V_907 ] ;
if ( V_904 )
V_883 -> V_908 = F_4 ( V_904 ) ;
else
V_883 -> V_908 =
V_909 ;
V_135 ++ ;
}
}
if ( V_31 -> V_5 [ V_519 ] ) {
V_883 -> V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
memcpy ( ( void * ) V_883 -> V_851 ,
F_29 ( V_31 -> V_5 [ V_519 ] ) ,
V_883 -> V_852 ) ;
}
V_883 -> V_46 = V_46 ;
V_883 -> V_18 = & V_7 -> V_18 ;
V_883 -> V_897 = V_897 ;
V_47 = V_7 -> V_223 -> V_314 ( & V_7 -> V_18 , V_46 , V_883 ) ;
if ( ! V_47 ) {
V_7 -> V_902 = V_883 ;
F_165 ( V_7 , V_46 ,
V_910 ) ;
goto V_461;
}
V_890:
F_46 ( V_883 ) ;
V_461:
F_9 ( & V_7 -> V_901 ) ;
return V_47 ;
}
static int F_166 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
if ( ! ( V_7 -> V_18 . V_56 & V_313 ) ||
! V_7 -> V_223 -> V_911 )
return - V_415 ;
F_8 ( & V_7 -> V_901 ) ;
V_47 = F_167 ( V_7 , false ) ;
F_9 ( & V_7 -> V_901 ) ;
return V_47 ;
}
static int F_168 ( struct V_44 * V_58 , struct V_34 * V_35 ,
V_23 V_55 , int V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_912 * V_913 )
{
struct V_914 * V_36 = & V_913 -> V_915 ;
void * V_159 ;
struct V_4 * V_916 ;
F_48 ( V_17 ) ;
V_159 = F_31 ( V_58 , F_66 ( V_35 -> V_45 ) . V_54 , V_55 , V_56 ,
V_917 ) ;
if ( ! V_159 )
return - 1 ;
F_169 ( V_35 , V_159 , & V_39 ) ;
if ( F_34 ( V_58 , V_175 , V_7 -> V_918 ) ||
F_34 ( V_58 , V_10 , V_17 -> V_20 -> V_21 ) )
goto V_63;
V_916 = F_50 ( V_58 , V_919 ) ;
if ( ! V_916 )
goto V_63;
if ( ( ! F_170 ( V_36 -> V_420 ) &&
F_58 ( V_58 , V_920 , V_454 , V_36 -> V_420 ) ) ||
( V_36 -> V_921 && V_36 -> V_922 &&
F_58 ( V_58 , V_923 ,
V_36 -> V_922 ,
V_36 -> V_921 ) ) ||
( V_36 -> V_527 && V_36 -> V_924 &&
V_36 -> V_527 != V_36 -> V_921 &&
F_58 ( V_58 , V_925 ,
V_36 -> V_924 , V_36 -> V_527 ) ) )
goto V_63;
if ( V_36 -> V_926 &&
F_88 ( V_58 , V_927 , V_36 -> V_926 ) )
goto V_63;
if ( V_36 -> V_416 &&
F_57 ( V_58 , V_928 , V_36 -> V_416 ) )
goto V_63;
if ( F_57 ( V_58 , V_929 , V_36 -> V_930 ) ||
F_34 ( V_58 , V_931 , V_36 -> V_412 -> V_62 ) ||
F_34 ( V_58 , V_932 ,
F_171 ( V_933 - V_913 -> V_934 ) ) )
goto V_63;
switch ( V_7 -> V_18 . V_620 ) {
case V_621 :
if ( F_34 ( V_58 , V_935 , V_36 -> signal ) )
goto V_63;
break;
case V_936 :
if ( F_56 ( V_58 , V_937 , V_36 -> signal ) )
goto V_63;
break;
default:
break;
}
switch ( V_17 -> V_121 ) {
case V_130 :
case V_129 :
if ( V_913 == V_17 -> V_127 &&
F_34 ( V_58 , V_938 ,
V_939 ) )
goto V_63;
break;
case V_126 :
if ( V_913 == V_17 -> V_127 &&
F_34 ( V_58 , V_938 ,
V_940 ) )
goto V_63;
break;
default:
break;
}
F_51 ( V_58 , V_916 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_383 ;
}
static int F_172 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
struct V_26 * V_46 ;
struct V_912 * V_885 ;
struct V_1 * V_17 ;
int V_384 = V_35 -> args [ 1 ] , V_88 = 0 ;
int V_47 ;
V_47 = F_19 ( V_45 , V_35 , & V_7 , & V_46 ) ;
if ( V_47 )
return V_47 ;
V_17 = V_46 -> V_29 ;
F_95 ( V_17 ) ;
F_173 ( & V_7 -> V_941 ) ;
F_174 ( V_7 ) ;
V_35 -> V_55 = V_7 -> V_918 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_88 <= V_384 )
continue;
if ( F_168 ( V_45 , V_35 ,
V_35 -> V_37 -> V_385 , V_386 ,
V_7 , V_17 , V_885 ) < 0 ) {
V_88 -- ;
break;
}
}
F_175 ( & V_7 -> V_941 ) ;
F_97 ( V_17 ) ;
V_35 -> args [ 1 ] = V_88 ;
F_26 ( V_7 ) ;
return V_45 -> V_52 ;
}
static int F_176 ( struct V_44 * V_58 , V_23 V_54 , V_23 V_55 ,
int V_56 , struct V_26 * V_46 ,
struct V_942 * V_943 )
{
void * V_159 ;
struct V_4 * V_944 ;
V_159 = F_31 ( V_58 , V_54 , V_55 , V_56 ,
V_945 ) ;
if ( ! V_159 )
return - V_118 ;
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) )
goto V_63;
V_944 = F_50 ( V_58 , V_946 ) ;
if ( ! V_944 )
goto V_63;
if ( F_34 ( V_58 , V_947 ,
V_943 -> V_412 -> V_62 ) )
goto V_63;
if ( ( V_943 -> V_598 & V_948 ) &&
F_56 ( V_58 , V_949 , V_943 -> V_950 ) )
goto V_63;
if ( ( V_943 -> V_598 & V_951 ) &&
F_35 ( V_58 , V_952 ) )
goto V_63;
if ( ( V_943 -> V_598 & V_953 ) &&
F_88 ( V_58 , V_954 ,
V_943 -> V_955 ) )
goto V_63;
if ( ( V_943 -> V_598 & V_956 ) &&
F_88 ( V_58 , V_957 ,
V_943 -> V_958 ) )
goto V_63;
if ( ( V_943 -> V_598 & V_959 ) &&
F_88 ( V_58 , V_960 ,
V_943 -> V_961 ) )
goto V_63;
if ( ( V_943 -> V_598 & V_962 ) &&
F_88 ( V_58 , V_963 ,
V_943 -> V_964 ) )
goto V_63;
if ( ( V_943 -> V_598 & V_965 ) &&
F_88 ( V_58 , V_966 ,
V_943 -> V_967 ) )
goto V_63;
F_51 ( V_58 , V_944 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_383 ;
}
static int F_177 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_942 V_943 ;
struct V_6 * V_46 ;
struct V_26 * V_20 ;
int V_968 = V_35 -> args [ 1 ] ;
int V_36 ;
V_36 = F_19 ( V_45 , V_35 , & V_46 , & V_20 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_46 -> V_223 -> V_969 ) {
V_36 = - V_415 ;
goto V_668;
}
while ( 1 ) {
struct V_59 * V_60 ;
V_36 = V_46 -> V_223 -> V_969 ( & V_46 -> V_18 , V_20 , V_968 ,
& V_943 ) ;
if ( V_36 == - V_507 )
break;
if ( V_36 )
goto V_668;
if ( ! V_943 . V_412 ) {
V_36 = - V_16 ;
goto V_461;
}
V_60 = F_159 ( & V_46 -> V_18 ,
V_943 . V_412 -> V_62 ) ;
if ( ! V_60 || V_60 -> V_56 & V_64 ) {
V_968 ++ ;
continue;
}
if ( F_176 ( V_45 ,
F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_385 , V_386 ,
V_20 ,
& V_943 ) < 0 )
goto V_461;
V_968 ++ ;
}
V_461:
V_35 -> args [ 1 ] = V_968 ;
V_36 = V_45 -> V_52 ;
V_668:
F_26 ( V_46 ) ;
return V_36 ;
}
static bool F_116 ( enum V_970 V_553 )
{
return V_553 <= V_971 ;
}
static bool F_178 ( V_23 V_972 )
{
return ! ( V_972 & ~ ( V_973 |
V_974 ) ) ;
}
static int F_179 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_59 * V_60 ;
const T_2 * V_420 , * V_482 , * V_851 = NULL ;
int V_47 , V_544 , V_852 = 0 ;
enum V_970 V_553 ;
struct V_76 V_75 ;
bool V_975 ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_552 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_543 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_414 ] )
return - V_16 ;
V_47 = F_41 ( V_31 , & V_75 ) ;
if ( V_47 )
return V_47 ;
if ( V_75 . V_88 >= 0 ) {
if ( V_75 . type != - 1 && V_75 . type != V_503 )
return - V_16 ;
if ( ! V_75 . V_90 . V_75 || ! V_75 . V_90 . V_91 )
return - V_16 ;
if ( ( V_75 . V_90 . V_95 != V_976 ||
V_75 . V_90 . V_91 != V_977 ) &&
( V_75 . V_90 . V_95 != V_978 ||
V_75 . V_90 . V_91 != V_979 ) )
return - V_16 ;
if ( V_75 . V_88 > 4 )
return - V_16 ;
} else {
V_75 . V_90 . V_91 = 0 ;
V_75 . V_90 . V_75 = NULL ;
}
if ( V_75 . V_88 >= 0 ) {
int V_135 ;
bool V_980 = false ;
for ( V_135 = 0 ; V_135 < V_7 -> V_18 . V_210 ; V_135 ++ ) {
if ( V_75 . V_90 . V_95 == V_7 -> V_18 . V_211 [ V_135 ] ) {
V_980 = true ;
break;
}
}
if ( ! V_980 )
return - V_16 ;
}
if ( ! V_7 -> V_223 -> V_276 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_60 = F_159 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_414 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_482 = F_29 ( V_31 -> V_5 [ V_543 ] ) ;
V_544 = F_30 ( V_31 -> V_5 [ V_543 ] ) ;
if ( V_31 -> V_5 [ V_519 ] ) {
V_851 = F_29 ( V_31 -> V_5 [ V_519 ] ) ;
V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
}
V_553 = F_4 ( V_31 -> V_5 [ V_552 ] ) ;
if ( ! F_116 ( V_553 ) )
return - V_16 ;
V_975 = ! ! V_31 -> V_5 [ V_981 ] ;
if ( V_975 )
return 0 ;
return F_180 ( V_7 , V_46 , V_60 , V_553 , V_420 ,
V_482 , V_544 , V_851 , V_852 ,
V_75 . V_90 . V_75 , V_75 . V_90 . V_91 , V_75 . V_88 ) ;
}
static int F_117 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_982 * V_983 ,
int V_984 )
{
memset ( V_983 , 0 , sizeof( * V_983 ) ) ;
V_983 -> V_985 = V_31 -> V_5 [ V_986 ] ;
if ( V_31 -> V_5 [ V_215 ] ) {
T_3 V_987 ;
V_987 = F_72 (
V_31 -> V_5 [ V_215 ] ) ;
V_983 -> V_988 = F_181 ( V_987 ) ;
if ( ! ( V_7 -> V_18 . V_56 & V_214 ) &&
V_987 != V_989 )
return - V_16 ;
if ( V_31 -> V_5 [ V_990 ] )
V_983 -> V_991 = true ;
} else
V_983 -> V_988 = F_181 ( V_989 ) ;
if ( V_31 -> V_5 [ V_992 ] ) {
void * V_120 ;
int V_52 , V_135 ;
V_120 = F_29 ( V_31 -> V_5 [ V_992 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_992 ] ) ;
V_983 -> V_993 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_983 -> V_993 > V_984 )
return - V_16 ;
memcpy ( V_983 -> V_994 , V_120 , V_52 ) ;
for ( V_135 = 0 ; V_135 < V_983 -> V_993 ; V_135 ++ )
if ( ! F_182 (
& V_7 -> V_18 ,
V_983 -> V_994 [ V_135 ] ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_995 ] ) {
V_983 -> V_996 =
F_4 ( V_31 -> V_5 [ V_995 ] ) ;
if ( ! F_182 ( & V_7 -> V_18 ,
V_983 -> V_996 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_997 ] ) {
V_983 -> V_972 =
F_4 ( V_31 -> V_5 [ V_997 ] ) ;
if ( ! F_178 ( V_983 -> V_972 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_998 ] ) {
void * V_120 ;
int V_52 ;
V_120 = F_29 ( V_31 -> V_5 [ V_998 ] ) ;
V_52 = F_30 ( V_31 -> V_5 [ V_998 ] ) ;
V_983 -> V_999 = V_52 / sizeof( V_23 ) ;
if ( V_52 % sizeof( V_23 ) )
return - V_16 ;
if ( V_983 -> V_999 > V_1000 )
return - V_16 ;
memcpy ( V_983 -> V_1001 , V_120 , V_52 ) ;
}
return 0 ;
}
static int F_183 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_982 V_555 ;
struct V_59 * V_60 ;
const T_2 * V_420 , * V_482 , * V_851 = NULL , * V_1002 = NULL ;
int V_47 , V_544 , V_852 = 0 ;
bool V_1003 = false ;
V_23 V_56 = 0 ;
struct V_1004 * V_680 = NULL ;
struct V_1004 * V_1005 = NULL ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_421 ] ||
! V_31 -> V_5 [ V_543 ] ||
! V_31 -> V_5 [ V_414 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_278 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_60 = F_159 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_414 ] ) ) ;
if ( ! V_60 || ( V_60 -> V_56 & V_64 ) )
return - V_16 ;
V_482 = F_29 ( V_31 -> V_5 [ V_543 ] ) ;
V_544 = F_30 ( V_31 -> V_5 [ V_543 ] ) ;
if ( V_31 -> V_5 [ V_519 ] ) {
V_851 = F_29 ( V_31 -> V_5 [ V_519 ] ) ;
V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
}
if ( V_31 -> V_5 [ V_1006 ] ) {
enum V_1007 V_1008 =
F_4 ( V_31 -> V_5 [ V_1006 ] ) ;
if ( V_1008 == V_1009 )
V_1003 = true ;
else if ( V_1008 != V_1010 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1011 ] )
V_1002 = F_29 ( V_31 -> V_5 [ V_1011 ] ) ;
if ( F_148 ( V_31 -> V_5 [ V_1012 ] ) )
V_56 |= V_1013 ;
if ( V_31 -> V_5 [ V_382 ] )
V_1005 =
F_29 ( V_31 -> V_5 [ V_382 ] ) ;
if ( V_31 -> V_5 [ V_679 ] ) {
if ( ! V_1005 )
return - V_16 ;
V_680 = F_29 ( V_31 -> V_5 [ V_679 ] ) ;
}
V_47 = F_117 ( V_7 , V_31 , & V_555 , 1 ) ;
if ( ! V_47 )
V_47 = F_184 ( V_7 , V_46 , V_60 , V_420 , V_1002 ,
V_482 , V_544 , V_851 , V_852 , V_1003 ,
& V_555 , V_56 , V_680 ,
V_1005 ) ;
return V_47 ;
}
static int F_185 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
const T_2 * V_851 = NULL , * V_420 ;
int V_852 = 0 ;
T_3 V_1014 ;
bool V_975 ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1015 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_280 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_1014 = F_72 ( V_31 -> V_5 [ V_1015 ] ) ;
if ( V_1014 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_519 ] ) {
V_851 = F_29 ( V_31 -> V_5 [ V_519 ] ) ;
V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
}
V_975 = ! ! V_31 -> V_5 [ V_981 ] ;
return F_186 ( V_7 , V_46 , V_420 , V_851 , V_852 , V_1014 ,
V_975 ) ;
}
static int F_187 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
const T_2 * V_851 = NULL , * V_420 ;
int V_852 = 0 ;
T_3 V_1014 ;
bool V_975 ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1015 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_282 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_1014 = F_72 ( V_31 -> V_5 [ V_1015 ] ) ;
if ( V_1014 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_519 ] ) {
V_851 = F_29 ( V_31 -> V_5 [ V_519 ] ) ;
V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
}
V_975 = ! ! V_31 -> V_5 [ V_981 ] ;
return F_188 ( V_7 , V_46 , V_420 , V_851 , V_852 , V_1014 ,
V_975 ) ;
}
static bool
F_189 ( struct V_6 * V_7 ,
int V_1016 [ V_232 ] ,
int V_1017 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_28 = false ;
int V_168 , V_135 ;
for ( V_168 = 0 ; V_168 < V_232 ; V_168 ++ ) {
struct V_1018 * V_1019 ;
V_1019 = V_18 -> V_233 [ V_168 ] ;
if ( ! V_1019 )
continue;
for ( V_135 = 0 ; V_135 < V_1019 -> V_253 ; V_135 ++ ) {
if ( V_1019 -> V_254 [ V_135 ] . V_256 == V_1017 ) {
V_1016 [ V_168 ] = V_135 + 1 ;
V_28 = true ;
break;
}
}
}
return V_28 ;
}
static int F_190 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1020 V_1021 ;
struct V_18 * V_18 ;
struct V_113 * V_1022 = NULL ;
int V_47 ;
memset ( & V_1021 , 0 , sizeof( V_1021 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_414 ] ||
! V_31 -> V_5 [ V_543 ] ||
! F_30 ( V_31 -> V_5 [ V_543 ] ) )
return - V_16 ;
V_1021 . V_416 = 100 ;
if ( V_31 -> V_5 [ V_539 ] ) {
V_1021 . V_416 =
F_4 ( V_31 -> V_5 [ V_539 ] ) ;
if ( V_1021 . V_416 < 1 || V_1021 . V_416 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_223 -> V_284 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_126 )
return - V_415 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_421 ] ) {
V_1021 . V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( ! F_191 ( V_1021 . V_420 ) )
return - V_16 ;
}
V_1021 . V_482 = F_29 ( V_31 -> V_5 [ V_543 ] ) ;
V_1021 . V_544 = F_30 ( V_31 -> V_5 [ V_543 ] ) ;
if ( V_31 -> V_5 [ V_519 ] ) {
V_1021 . V_851 = F_29 ( V_31 -> V_5 [ V_519 ] ) ;
V_1021 . V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
}
if ( V_31 -> V_5 [ V_407 ] ) {
enum V_405 V_406 ;
if ( ! F_74 ( V_31 , & V_406 ) )
return - V_16 ;
if ( V_406 != V_408 &&
! ( V_18 -> V_380 & V_1023 ) )
return - V_16 ;
V_1021 . V_406 = V_406 ;
} else {
V_1021 . V_406 = V_408 ;
}
V_1021 . V_412 = F_76 ( V_7 ,
F_4 ( V_31 -> V_5 [ V_414 ] ) ,
V_1021 . V_406 ) ;
if ( ! V_1021 . V_412 ||
V_1021 . V_412 -> V_56 & V_68 ||
V_1021 . V_412 -> V_56 & V_64 )
return - V_16 ;
if ( ( V_1021 . V_406 == V_410 ||
V_1021 . V_406 == V_411 ) &&
! F_77 ( & V_7 -> V_18 , V_1021 . V_412 ,
V_1021 . V_406 ) )
return - V_16 ;
V_1021 . V_1024 = ! ! V_31 -> V_5 [ V_1025 ] ;
V_1021 . V_550 = ! ! V_31 -> V_5 [ V_551 ] ;
if ( V_31 -> V_5 [ V_741 ] ) {
T_2 * V_891 =
F_29 ( V_31 -> V_5 [ V_741 ] ) ;
int V_1026 =
F_30 ( V_31 -> V_5 [ V_741 ] ) ;
struct V_1018 * V_1019 =
V_18 -> V_233 [ V_1021 . V_412 -> V_168 ] ;
V_47 = F_161 ( V_1019 , V_891 , V_1026 ,
& V_1021 . V_742 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_1027 ] &&
! F_189 ( V_7 , V_1021 . V_1016 ,
F_4 ( V_31 -> V_5 [ V_1027 ] ) ) )
return - V_16 ;
if ( V_1021 . V_550 && V_31 -> V_5 [ V_1028 ] ) {
V_1022 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1028 ] ) ;
if ( F_16 ( V_1022 ) )
return F_24 ( V_1022 ) ;
}
V_1021 . V_985 =
F_148 ( V_31 -> V_5 [ V_986 ] ) ;
V_47 = F_192 ( V_7 , V_46 , & V_1021 , V_1022 ) ;
if ( V_47 )
F_46 ( V_1022 ) ;
return V_47 ;
}
static int F_193 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
if ( ! V_7 -> V_223 -> V_1029 )
return - V_415 ;
if ( V_46 -> V_29 -> V_121 != V_126 )
return - V_415 ;
return F_194 ( V_7 , V_46 , false ) ;
}
static int F_195 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1030 ] )
return - V_16 ;
V_47 = - V_415 ;
if ( V_7 -> V_223 -> V_324 ) {
V_7 -> V_1031 = V_31 ;
V_47 = V_7 -> V_223 -> V_324 ( & V_7 -> V_18 ,
F_29 ( V_31 -> V_5 [ V_1030 ] ) ,
F_30 ( V_31 -> V_5 [ V_1030 ] ) ) ;
V_7 -> V_1031 = NULL ;
}
return V_47 ;
}
static int F_196 ( struct V_44 * V_45 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 ;
int V_47 ;
long V_1032 ;
void * V_120 = NULL ;
int V_1033 = 0 ;
if ( V_35 -> args [ 0 ] ) {
V_1032 = V_35 -> args [ 0 ] - 1 ;
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
V_1032 = V_7 -> V_14 ;
V_7 = NULL ;
F_9 ( & V_32 ) ;
if ( V_39 . V_41 [ V_1030 ] )
V_35 -> args [ 1 ] =
( long ) V_39 . V_41 [ V_1030 ] ;
}
if ( V_35 -> args [ 1 ] ) {
V_120 = F_29 ( ( void * ) V_35 -> args [ 1 ] ) ;
V_1033 = F_30 ( ( void * ) V_35 -> args [ 1 ] ) ;
}
F_8 ( & V_32 ) ;
V_7 = F_11 ( V_1032 ) ;
if ( ! V_7 ) {
F_9 ( & V_32 ) ;
return - V_507 ;
}
F_197 ( V_7 ) ;
F_9 ( & V_32 ) ;
if ( ! V_7 -> V_223 -> V_1034 ) {
V_47 = - V_415 ;
goto V_668;
}
while ( 1 ) {
void * V_159 = F_31 ( V_45 , F_66 ( V_35 -> V_45 ) . V_54 ,
V_35 -> V_37 -> V_385 , V_386 ,
V_1035 ) ;
struct V_4 * V_1036 ;
if ( F_34 ( V_45 , V_27 , V_1032 ) ) {
F_63 ( V_45 , V_159 ) ;
break;
}
V_1036 = F_50 ( V_45 , V_1030 ) ;
if ( ! V_1036 ) {
F_63 ( V_45 , V_159 ) ;
break;
}
V_47 = V_7 -> V_223 -> V_1034 ( & V_7 -> V_18 , V_45 , V_35 ,
V_120 , V_1033 ) ;
F_51 ( V_45 , V_1036 ) ;
if ( V_47 == - V_74 || V_47 == - V_507 ) {
F_63 ( V_45 , V_159 ) ;
break;
} else if ( V_47 ) {
F_63 ( V_45 , V_159 ) ;
goto V_668;
}
F_62 ( V_45 , V_159 ) ;
}
V_47 = V_45 -> V_52 ;
V_35 -> args [ 0 ] = V_1032 + 1 ;
V_668:
F_27 ( V_7 ) ;
return V_47 ;
}
static struct V_44 *
F_198 ( struct V_6 * V_7 ,
int V_1037 , V_23 V_54 , V_23 V_55 , T_11 V_1038 )
{
struct V_44 * V_45 ;
void * V_159 ;
struct V_4 * V_120 ;
V_45 = F_68 ( V_1037 + 100 , V_1038 ) ;
if ( ! V_45 )
return NULL ;
V_159 = F_31 ( V_45 , V_54 , V_55 , 0 , V_1035 ) ;
if ( ! V_159 ) {
F_199 ( V_45 ) ;
return NULL ;
}
if ( F_34 ( V_45 , V_27 , V_7 -> V_14 ) )
goto V_63;
V_120 = F_50 ( V_45 , V_1030 ) ;
( ( void * * ) V_45 -> V_35 ) [ 0 ] = V_7 ;
( ( void * * ) V_45 -> V_35 ) [ 1 ] = V_159 ;
( ( void * * ) V_45 -> V_35 ) [ 2 ] = V_120 ;
return V_45 ;
V_63:
F_199 ( V_45 ) ;
return NULL ;
}
struct V_44 * F_200 ( struct V_18 * V_18 ,
int V_1037 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
if ( F_201 ( ! V_7 -> V_1031 ) )
return NULL ;
return F_198 ( V_7 , V_1037 ,
V_7 -> V_1031 -> V_389 ,
V_7 -> V_1031 -> V_390 ,
V_117 ) ;
}
int F_202 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = ( ( void * * ) V_45 -> V_35 ) [ 0 ] ;
void * V_159 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_120 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
if ( F_201 ( ! V_7 -> V_1031 ) ) {
F_199 ( V_45 ) ;
return - V_16 ;
}
F_51 ( V_45 , V_120 ) ;
F_62 ( V_45 , V_159 ) ;
return F_70 ( V_45 , V_7 -> V_1031 ) ;
}
struct V_44 * F_203 ( struct V_18 * V_18 ,
int V_1037 , T_11 V_1038 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
return F_198 ( V_7 , V_1037 , 0 , 0 , V_1038 ) ;
}
void F_204 ( struct V_44 * V_45 , T_11 V_1038 )
{
void * V_159 = ( ( void * * ) V_45 -> V_35 ) [ 1 ] ;
struct V_4 * V_120 = ( ( void * * ) V_45 -> V_35 ) [ 2 ] ;
F_51 ( V_45 , V_120 ) ;
F_62 ( V_45 , V_159 ) ;
F_205 ( V_45 , 0 , V_1039 . V_1040 , V_1038 ) ;
}
static int F_206 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1041 V_326 ;
struct V_18 * V_18 ;
struct V_113 * V_1022 = NULL ;
int V_47 ;
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
if ( ! F_28 ( V_31 -> V_5 [ V_519 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_543 ] ||
! F_30 ( V_31 -> V_5 [ V_543 ] ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_552 ] ) {
V_326 . V_553 =
F_4 ( V_31 -> V_5 [ V_552 ] ) ;
if ( ! F_116 ( V_326 . V_553 ) )
return - V_16 ;
} else
V_326 . V_553 = V_554 ;
V_326 . V_550 = V_31 -> V_5 [ V_551 ] ;
V_47 = F_117 ( V_7 , V_31 , & V_326 . V_555 ,
V_556 ) ;
if ( V_47 )
return V_47 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
V_18 = & V_7 -> V_18 ;
V_326 . V_1042 = - 1 ;
if ( V_31 -> V_5 [ V_1043 ] &&
( V_18 -> V_56 & V_203 ) ) {
V_326 . V_1042 =
F_72 ( V_31 -> V_5 [ V_1043 ] ) ;
}
if ( V_31 -> V_5 [ V_421 ] )
V_326 . V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_326 . V_482 = F_29 ( V_31 -> V_5 [ V_543 ] ) ;
V_326 . V_544 = F_30 ( V_31 -> V_5 [ V_543 ] ) ;
if ( V_31 -> V_5 [ V_519 ] ) {
V_326 . V_851 = F_29 ( V_31 -> V_5 [ V_519 ] ) ;
V_326 . V_852 = F_30 ( V_31 -> V_5 [ V_519 ] ) ;
}
if ( V_31 -> V_5 [ V_414 ] ) {
V_326 . V_412 =
F_159 ( V_18 ,
F_4 ( V_31 -> V_5 [ V_414 ] ) ) ;
if ( ! V_326 . V_412 ||
V_326 . V_412 -> V_56 & V_64 )
return - V_16 ;
}
if ( V_326 . V_550 && V_31 -> V_5 [ V_1028 ] ) {
V_1022 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1028 ] ) ;
if ( F_16 ( V_1022 ) )
return F_24 ( V_1022 ) ;
}
if ( F_148 ( V_31 -> V_5 [ V_1012 ] ) )
V_326 . V_56 |= V_1013 ;
if ( V_31 -> V_5 [ V_382 ] )
memcpy ( & V_326 . V_1005 ,
F_29 ( V_31 -> V_5 [ V_382 ] ) ,
sizeof( V_326 . V_1005 ) ) ;
if ( V_31 -> V_5 [ V_679 ] ) {
if ( ! V_31 -> V_5 [ V_382 ] ) {
F_46 ( V_1022 ) ;
return - V_16 ;
}
memcpy ( & V_326 . V_680 ,
F_29 ( V_31 -> V_5 [ V_679 ] ) ,
sizeof( V_326 . V_680 ) ) ;
}
V_47 = F_207 ( V_7 , V_46 , & V_326 , V_1022 ) ;
if ( V_47 )
F_46 ( V_1022 ) ;
return V_47 ;
}
static int F_208 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_3 V_1044 ;
if ( ! V_31 -> V_5 [ V_1015 ] )
V_1044 = V_1045 ;
else
V_1044 = F_72 ( V_31 -> V_5 [ V_1015 ] ) ;
if ( V_1044 == 0 )
return - V_16 ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
return F_209 ( V_7 , V_46 , V_1044 , true ) ;
}
static int F_210 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_2 * V_2 ;
int V_47 ;
V_23 V_1046 ;
if ( ! V_31 -> V_5 [ V_1047 ] )
return - V_16 ;
V_1046 = F_4 ( V_31 -> V_5 [ V_1047 ] ) ;
V_2 = F_211 ( V_1046 ) ;
if ( F_16 ( V_2 ) )
return F_24 ( V_2 ) ;
V_47 = 0 ;
if ( ! F_65 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_47 = F_212 ( V_7 , V_2 ) ;
F_213 ( V_2 ) ;
return V_47 ;
}
static int F_214 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
int (* F_215)( struct V_18 * V_18 , struct V_26 * V_46 ,
struct V_1048 * V_1049 ) = NULL ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1048 V_1049 ;
memset ( & V_1049 , 0 , sizeof( struct V_1048 ) ) ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1050 ] )
return - V_16 ;
V_1049 . V_1051 = F_29 ( V_31 -> V_5 [ V_1050 ] ) ;
V_1049 . V_420 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
switch ( V_31 -> V_1052 -> V_57 ) {
case V_1053 :
F_215 = V_7 -> V_223 -> V_288 ;
break;
case V_1054 :
F_215 = V_7 -> V_223 -> V_290 ;
break;
default:
F_201 ( 1 ) ;
break;
}
if ( ! F_215 )
return - V_415 ;
return F_215 ( & V_7 -> V_18 , V_46 , & V_1049 ) ;
}
static int F_216 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
if ( V_46 -> V_29 -> V_121 != V_129 &&
V_46 -> V_29 -> V_121 != V_130 )
return - V_415 ;
if ( ! V_7 -> V_223 -> V_292 )
return - V_415 ;
return V_7 -> V_223 -> V_292 ( & V_7 -> V_18 , V_46 ) ;
}
static int F_217 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 V_1055 , V_1056 ;
T_3 V_1057 ;
T_2 * V_1058 ;
if ( ! ( V_7 -> V_18 . V_56 & V_205 ) ||
! V_7 -> V_223 -> V_309 )
return - V_415 ;
if ( ! V_31 -> V_5 [ V_1059 ] ||
! V_31 -> V_5 [ V_1060 ] ||
! V_31 -> V_5 [ V_1061 ] ||
! V_31 -> V_5 [ V_519 ] ||
! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
V_1058 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_1055 = F_39 ( V_31 -> V_5 [ V_1059 ] ) ;
V_1057 = F_72 ( V_31 -> V_5 [ V_1060 ] ) ;
V_1056 = F_39 ( V_31 -> V_5 [ V_1061 ] ) ;
return V_7 -> V_223 -> V_309 ( & V_7 -> V_18 , V_46 , V_1058 , V_1055 ,
V_1056 , V_1057 ,
F_29 ( V_31 -> V_5 [ V_519 ] ) ,
F_30 ( V_31 -> V_5 [ V_519 ] ) ) ;
}
static int F_218 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
enum V_1062 V_1063 ;
T_2 * V_1058 ;
if ( ! ( V_7 -> V_18 . V_56 & V_205 ) ||
! V_7 -> V_223 -> V_311 )
return - V_415 ;
if ( ! V_31 -> V_5 [ V_1064 ] ||
! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
V_1063 = F_39 ( V_31 -> V_5 [ V_1064 ] ) ;
V_1058 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
return V_7 -> V_223 -> V_311 ( & V_7 -> V_18 , V_46 , V_1058 , V_1063 ) ;
}
static int F_219 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
struct V_59 * V_60 ;
struct V_44 * V_58 ;
void * V_159 ;
T_1 V_498 ;
enum V_405 V_406 = V_408 ;
V_23 V_413 , V_1065 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_414 ] ||
! V_31 -> V_5 [ V_1066 ] )
return - V_16 ;
V_1065 = F_4 ( V_31 -> V_5 [ V_1066 ] ) ;
if ( ! V_7 -> V_223 -> V_295 ||
! ( V_7 -> V_18 . V_56 & V_294 ) )
return - V_415 ;
if ( V_1065 < V_1067 ||
V_1065 > V_7 -> V_18 . V_331 )
return - V_16 ;
if ( V_31 -> V_5 [ V_407 ] &&
! F_74 ( V_31 , & V_406 ) )
return - V_16 ;
V_413 = F_4 ( V_31 -> V_5 [ V_414 ] ) ;
V_60 = F_76 ( V_7 , V_413 , V_406 ) ;
if ( V_60 == NULL )
return - V_16 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_1068 ) ;
if ( F_16 ( V_159 ) ) {
V_47 = F_24 ( V_159 ) ;
goto V_508;
}
V_47 = V_7 -> V_223 -> V_295 ( & V_7 -> V_18 , V_17 , V_60 ,
V_406 , V_1065 , & V_498 ) ;
if ( V_47 )
goto V_508;
if ( F_88 ( V_58 , V_1069 , V_498 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_508:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_220 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
T_1 V_498 ;
if ( ! V_31 -> V_5 [ V_1069 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_1070 )
return - V_415 ;
V_498 = F_5 ( V_31 -> V_5 [ V_1069 ] ) ;
return V_7 -> V_223 -> V_1070 ( & V_7 -> V_18 , V_17 , V_498 ) ;
}
static V_23 F_221 ( struct V_1018 * V_1019 ,
T_2 * V_891 , T_2 V_1071 )
{
T_2 V_135 ;
V_23 V_568 = 0 ;
for ( V_135 = 0 ; V_135 < V_1071 ; V_135 ++ ) {
int V_170 = ( V_891 [ V_135 ] & 0x7f ) * 5 ;
int V_1072 ;
for ( V_1072 = 0 ; V_1072 < V_1019 -> V_253 ; V_1072 ++ ) {
struct V_169 * V_1073 =
& V_1019 -> V_254 [ V_1072 ] ;
if ( V_170 == V_1073 -> V_256 ) {
V_568 |= 1 << V_1072 ;
break;
}
}
if ( V_1072 == V_1019 -> V_253 )
return 0 ;
}
return V_568 ;
}
static bool F_222 ( struct V_1018 * V_1019 ,
T_2 * V_891 , T_2 V_1071 ,
T_2 V_237 [ V_1074 ] )
{
T_2 V_135 ;
memset ( V_237 , 0 , V_1074 ) ;
for ( V_135 = 0 ; V_135 < V_1071 ; V_135 ++ ) {
int V_1072 , V_1075 ;
V_1072 = V_891 [ V_135 ] / 8 ;
V_1075 = F_123 ( V_891 [ V_135 ] % 8 ) ;
if ( ( V_1072 < 0 ) || ( V_1072 >= V_1074 ) )
return false ;
if ( V_1019 -> V_234 . V_237 . V_1076 [ V_1072 ] & V_1075 )
V_237 [ V_1072 ] |= V_1075 ;
else
return false ;
}
return true ;
}
static int F_223 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_4 * V_78 [ V_1077 + 1 ] ;
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1078 V_568 ;
int V_116 , V_135 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_4 * V_1079 ;
struct V_1018 * V_1019 ;
if ( V_31 -> V_5 [ V_1080 ] == NULL )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_297 )
return - V_415 ;
memset ( & V_568 , 0 , sizeof( V_568 ) ) ;
for ( V_135 = 0 ; V_135 < V_232 ; V_135 ++ ) {
V_1019 = V_7 -> V_18 . V_233 [ V_135 ] ;
V_568 . V_1081 [ V_135 ] . V_1082 =
V_1019 ? ( 1 << V_1019 -> V_253 ) - 1 : 0 ;
if ( V_1019 )
memcpy ( V_568 . V_1081 [ V_135 ] . V_237 ,
V_1019 -> V_234 . V_237 . V_1076 ,
sizeof( V_568 . V_1081 [ V_135 ] . V_237 ) ) ;
else
memset ( V_568 . V_1081 [ V_135 ] . V_237 , 0 ,
sizeof( V_568 . V_1081 [ V_135 ] . V_237 ) ) ;
}
F_96 ( V_1083 > V_1074 * 8 ) ;
F_44 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_167 V_168 = F_160 ( V_1079 ) ;
if ( V_168 < 0 || V_168 >= V_232 )
return - V_16 ;
V_1019 = V_7 -> V_18 . V_233 [ V_168 ] ;
if ( V_1019 == NULL )
return - V_16 ;
F_86 ( V_78 , V_1077 , F_29 ( V_1079 ) ,
F_30 ( V_1079 ) , V_1084 ) ;
if ( V_78 [ V_1085 ] ) {
V_568 . V_1081 [ V_168 ] . V_1082 = F_221 (
V_1019 ,
F_29 ( V_78 [ V_1085 ] ) ,
F_30 ( V_78 [ V_1085 ] ) ) ;
if ( ( V_568 . V_1081 [ V_168 ] . V_1082 == 0 ) &&
F_30 ( V_78 [ V_1085 ] ) )
return - V_16 ;
}
if ( V_78 [ V_1086 ] ) {
if ( ! F_222 (
V_1019 ,
F_29 ( V_78 [ V_1086 ] ) ,
F_30 ( V_78 [ V_1086 ] ) ,
V_568 . V_1081 [ V_168 ] . V_237 ) )
return - V_16 ;
}
if ( V_568 . V_1081 [ V_168 ] . V_1082 == 0 ) {
if ( ! V_7 -> V_18 . V_233 [ V_168 ] -> V_234 . V_235 )
return - V_16 ;
for ( V_135 = 0 ; V_135 < V_1074 ; V_135 ++ )
if ( V_568 . V_1081 [ V_168 ] . V_237 [ V_135 ] )
break;
if ( V_135 == V_1074 )
return - V_16 ;
}
}
return V_7 -> V_223 -> V_297 ( & V_7 -> V_18 , V_46 , NULL , & V_568 ) ;
}
static int F_224 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
T_3 V_1087 = V_343 | V_1088 ;
if ( ! V_31 -> V_5 [ V_1089 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_342 ] )
V_1087 = F_72 ( V_31 -> V_5 [ V_342 ] ) ;
switch ( V_17 -> V_121 ) {
case V_129 :
case V_126 :
case V_130 :
case V_122 :
case V_123 :
case V_125 :
case V_124 :
case V_486 :
break;
default:
return - V_415 ;
}
if ( ! V_7 -> V_223 -> V_299 )
return - V_415 ;
return F_225 ( V_17 , V_31 -> V_389 , V_1087 ,
F_29 ( V_31 -> V_5 [ V_1089 ] ) ,
F_30 ( V_31 -> V_5 [ V_1089 ] ) ) ;
}
static int F_226 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
struct V_59 * V_60 ;
enum V_405 V_406 = V_408 ;
bool V_1090 = false ;
V_23 V_413 ;
int V_47 ;
void * V_159 = NULL ;
T_1 V_498 ;
struct V_44 * V_58 = NULL ;
unsigned int V_1091 = 0 ;
bool V_1092 , V_893 , V_1093 ;
V_1093 = V_31 -> V_5 [ V_1094 ] ;
if ( ! V_31 -> V_5 [ V_1095 ] ||
! V_31 -> V_5 [ V_414 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_299 )
return - V_415 ;
switch ( V_17 -> V_121 ) {
case V_129 :
case V_126 :
case V_130 :
case V_122 :
case V_123 :
case V_125 :
case V_124 :
case V_486 :
break;
default:
return - V_415 ;
}
if ( V_31 -> V_5 [ V_1066 ] ) {
if ( ! ( V_7 -> V_18 . V_56 & V_332 ) )
return - V_16 ;
V_1091 = F_4 ( V_31 -> V_5 [ V_1066 ] ) ;
if ( V_1091 < V_1067 ||
V_1091 > V_7 -> V_18 . V_331 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_407 ] ) {
if ( ! F_74 ( V_31 , & V_406 ) )
return - V_16 ;
V_1090 = true ;
}
V_1092 = V_31 -> V_5 [ V_333 ] ;
if ( V_1092 && ! ( V_7 -> V_18 . V_56 & V_332 ) )
return - V_16 ;
V_893 = F_148 ( V_31 -> V_5 [ V_894 ] ) ;
V_413 = F_4 ( V_31 -> V_5 [ V_414 ] ) ;
V_60 = F_76 ( V_7 , V_413 , V_406 ) ;
if ( V_60 == NULL )
return - V_16 ;
if ( ! V_1093 ) {
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_1096 ) ;
if ( F_16 ( V_159 ) ) {
V_47 = F_24 ( V_159 ) ;
goto V_508;
}
}
V_47 = F_227 ( V_7 , V_17 , V_60 , V_1092 , V_406 ,
V_1090 , V_1091 ,
F_29 ( V_31 -> V_5 [ V_1095 ] ) ,
F_30 ( V_31 -> V_5 [ V_1095 ] ) ,
V_893 , V_1093 , & V_498 ) ;
if ( V_47 )
goto V_508;
if ( V_58 ) {
if ( F_88 ( V_58 , V_1069 , V_498 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
}
return 0 ;
V_63:
V_47 = - V_74 ;
V_508:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_228 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
T_1 V_498 ;
if ( ! V_31 -> V_5 [ V_1069 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_301 )
return - V_415 ;
switch ( V_17 -> V_121 ) {
case V_129 :
case V_126 :
case V_130 :
case V_122 :
case V_123 :
case V_124 :
case V_486 :
break;
default:
return - V_415 ;
}
V_498 = F_5 ( V_31 -> V_5 [ V_1069 ] ) ;
return V_7 -> V_223 -> V_301 ( & V_7 -> V_18 , V_17 , V_498 ) ;
}
static int F_229 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
T_2 V_1097 ;
bool V_1098 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1099 ] )
return - V_16 ;
V_1097 = F_4 ( V_31 -> V_5 [ V_1099 ] ) ;
if ( V_1097 != V_1100 && V_1097 != V_1101 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1102 )
return - V_415 ;
V_1098 = ( V_1097 == V_1101 ) ? true : false ;
if ( V_1098 == V_17 -> V_1103 )
return 0 ;
V_47 = V_7 -> V_223 -> V_1102 ( V_17 -> V_18 , V_46 , V_1098 ,
V_17 -> V_1104 ) ;
if ( ! V_47 )
V_17 -> V_1103 = V_1098 ;
return V_47 ;
}
static int F_230 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
enum V_1105 V_1097 ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_44 * V_58 ;
void * V_159 ;
int V_47 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1102 )
return - V_415 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_1106 ) ;
if ( ! V_159 ) {
V_47 = - V_74 ;
goto V_508;
}
if ( V_17 -> V_1103 )
V_1097 = V_1101 ;
else
V_1097 = V_1100 ;
if ( F_34 ( V_58 , V_1099 , V_1097 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_508:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_231 ( struct V_30 * V_31 ,
V_23 V_170 , V_23 V_1107 , V_23 V_1108 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
if ( ( V_170 < 0 || V_170 > 100 ) ||
( V_1108 < 0 || V_1108 > V_1109 ) )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1110 )
return - V_415 ;
if ( V_17 -> V_121 != V_129 &&
V_17 -> V_121 != V_130 )
return - V_415 ;
return V_7 -> V_223 -> V_1110 ( V_17 -> V_18 , V_46 ,
V_170 , V_1107 , V_1108 ) ;
}
static int F_232 ( struct V_30 * V_31 ,
T_12 V_1111 , V_23 V_1112 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
if ( V_1111 > 0 )
return - V_16 ;
V_17 = V_46 -> V_29 ;
if ( ! V_7 -> V_223 -> V_1113 )
return - V_415 ;
if ( V_17 -> V_121 != V_129 &&
V_17 -> V_121 != V_130 )
return - V_415 ;
return V_7 -> V_223 -> V_1113 ( V_17 -> V_18 , V_46 ,
V_1111 , V_1112 ) ;
}
static int F_233 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_4 * V_5 [ V_1114 + 1 ] ;
struct V_4 * V_1115 ;
int V_47 ;
V_1115 = V_31 -> V_5 [ V_1116 ] ;
if ( ! V_1115 ) {
V_47 = - V_16 ;
goto V_461;
}
V_47 = F_38 ( V_5 , V_1114 , V_1115 ,
V_1117 ) ;
if ( V_47 )
goto V_461;
if ( V_5 [ V_1118 ] &&
V_5 [ V_1119 ] ) {
T_12 V_1111 ;
V_23 V_1112 ;
V_1111 = F_4 ( V_5 [ V_1118 ] ) ;
V_1112 = F_4 ( V_5 [ V_1119 ] ) ;
V_47 = F_232 ( V_31 , V_1111 , V_1112 ) ;
} else if ( V_5 [ V_1120 ] &&
V_5 [ V_1121 ] &&
V_5 [ V_1122 ] ) {
V_23 V_170 , V_1107 , V_1108 ;
V_170 = F_4 ( V_5 [ V_1120 ] ) ;
V_1107 = F_4 ( V_5 [ V_1121 ] ) ;
V_1108 = F_4 ( V_5 [ V_1122 ] ) ;
V_47 = F_231 ( V_31 , V_170 , V_1107 , V_1108 ) ;
} else
V_47 = - V_16 ;
V_461:
return V_47 ;
}
static int F_234 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_772 V_828 ;
struct V_832 V_833 ;
int V_47 ;
memcpy ( & V_828 , & V_776 , sizeof( V_828 ) ) ;
memcpy ( & V_833 , & V_1123 , sizeof( V_833 ) ) ;
if ( V_31 -> V_5 [ V_778 ] ) {
V_47 = F_145 ( V_31 , & V_828 , NULL ) ;
if ( V_47 )
return V_47 ;
}
if ( ! V_31 -> V_5 [ V_478 ] ||
! F_30 ( V_31 -> V_5 [ V_478 ] ) )
return - V_16 ;
V_833 . V_1124 = F_29 ( V_31 -> V_5 [ V_478 ] ) ;
V_833 . V_775 = F_30 ( V_31 -> V_5 [ V_478 ] ) ;
if ( V_31 -> V_5 [ V_1027 ] &&
! F_189 ( V_7 , V_833 . V_1016 ,
F_4 ( V_31 -> V_5 [ V_1027 ] ) ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_835 ] ) {
V_47 = F_147 ( V_31 , & V_833 ) ;
if ( V_47 )
return V_47 ;
}
if ( V_31 -> V_5 [ V_414 ] ) {
enum V_405 V_406 = V_408 ;
if ( V_31 -> V_5 [ V_407 ] &&
! F_74 ( V_31 , & V_406 ) )
return - V_16 ;
V_833 . V_412 = F_76 ( V_7 ,
F_4 ( V_31 -> V_5 [ V_414 ] ) ,
V_406 ) ;
if ( ! V_833 . V_412 )
return - V_16 ;
V_833 . V_406 = V_406 ;
} else {
V_833 . V_412 = NULL ;
}
return F_235 ( V_7 , V_46 , & V_833 , & V_828 ) ;
}
static int F_236 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
return F_237 ( V_7 , V_46 ) ;
}
static int F_238 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_44 * V_58 ;
void * V_159 ;
if ( ! V_7 -> V_18 . V_346 . V_56 && ! V_7 -> V_18 . V_346 . V_347 )
return - V_415 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_1125 ) ;
if ( ! V_159 )
goto V_63;
if ( V_7 -> V_346 ) {
struct V_4 * V_348 ;
V_348 = F_50 ( V_58 , V_1126 ) ;
if ( ! V_348 )
goto V_63;
if ( ( V_7 -> V_346 -> V_1127 &&
F_35 ( V_58 , V_351 ) ) ||
( V_7 -> V_346 -> V_328 &&
F_35 ( V_58 , V_353 ) ) ||
( V_7 -> V_346 -> V_1128 &&
F_35 ( V_58 , V_355 ) ) ||
( V_7 -> V_346 -> V_1129 &&
F_35 ( V_58 , V_359 ) ) ||
( V_7 -> V_346 -> V_1130 &&
F_35 ( V_58 , V_361 ) ) ||
( V_7 -> V_346 -> V_1131 &&
F_35 ( V_58 , V_363 ) ) ||
( V_7 -> V_346 -> V_1132 &&
F_35 ( V_58 , V_365 ) ) )
goto V_63;
if ( V_7 -> V_346 -> V_347 ) {
struct V_4 * V_1133 , * V_1134 ;
int V_135 , V_1135 ;
V_1133 = F_50 ( V_58 ,
V_373 ) ;
if ( ! V_1133 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_7 -> V_346 -> V_347 ; V_135 ++ ) {
V_1134 = F_50 ( V_58 , V_135 + 1 ) ;
if ( ! V_1134 )
goto V_63;
V_1135 = V_7 -> V_346 -> V_1136 [ V_135 ] . V_1137 ;
if ( F_58 ( V_58 , V_1138 ,
F_239 ( V_1135 , 8 ) ,
V_7 -> V_346 -> V_1136 [ V_135 ] . V_568 ) ||
F_58 ( V_58 , V_1139 ,
V_1135 ,
V_7 -> V_346 -> V_1136 [ V_135 ] . V_1140 ) )
goto V_63;
F_51 ( V_58 , V_1134 ) ;
}
F_51 ( V_58 , V_1133 ) ;
}
F_51 ( V_58 , V_348 ) ;
}
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
F_69 ( V_58 ) ;
return - V_74 ;
}
static int F_240 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_4 * V_78 [ V_1141 ] ;
struct V_1142 V_1143 = {} ;
struct V_1142 * V_1144 ;
struct V_1145 * V_346 = & V_7 -> V_18 . V_346 ;
int V_47 , V_135 ;
bool V_1146 = V_7 -> V_346 ;
if ( ! V_7 -> V_18 . V_346 . V_56 && ! V_7 -> V_18 . V_346 . V_347 )
return - V_415 ;
if ( ! V_31 -> V_5 [ V_1126 ] ) {
F_241 ( V_7 ) ;
V_7 -> V_346 = NULL ;
goto V_1147;
}
V_47 = F_86 ( V_78 , V_1148 ,
F_29 ( V_31 -> V_5 [ V_1126 ] ) ,
F_30 ( V_31 -> V_5 [ V_1126 ] ) ,
V_1149 ) ;
if ( V_47 )
return V_47 ;
if ( V_78 [ V_351 ] ) {
if ( ! ( V_346 -> V_56 & V_350 ) )
return - V_16 ;
V_1143 . V_1127 = true ;
}
if ( V_78 [ V_353 ] ) {
if ( ! ( V_346 -> V_56 & V_352 ) )
return - V_16 ;
V_1143 . V_328 = true ;
}
if ( V_78 [ V_355 ] ) {
if ( ! ( V_346 -> V_56 & V_354 ) )
return - V_16 ;
V_1143 . V_1128 = true ;
}
if ( V_78 [ V_357 ] )
return - V_16 ;
if ( V_78 [ V_359 ] ) {
if ( ! ( V_346 -> V_56 & V_358 ) )
return - V_16 ;
V_1143 . V_1129 = true ;
}
if ( V_78 [ V_361 ] ) {
if ( ! ( V_346 -> V_56 & V_360 ) )
return - V_16 ;
V_1143 . V_1130 = true ;
}
if ( V_78 [ V_363 ] ) {
if ( ! ( V_346 -> V_56 & V_362 ) )
return - V_16 ;
V_1143 . V_1131 = true ;
}
if ( V_78 [ V_365 ] ) {
if ( ! ( V_346 -> V_56 & V_364 ) )
return - V_16 ;
V_1143 . V_1132 = true ;
}
if ( V_78 [ V_373 ] ) {
struct V_4 * V_367 ;
int V_347 = 0 ;
int V_116 , V_1135 , V_1150 ;
struct V_4 * V_1151 [ V_1152 ] ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_347 ++ ;
if ( V_347 > V_346 -> V_347 )
return - V_16 ;
V_1143 . V_1136 = F_242 ( V_347 ,
sizeof( V_1143 . V_1136 [ 0 ] ) ,
V_117 ) ;
if ( ! V_1143 . V_1136 )
return - V_118 ;
V_1143 . V_347 = V_347 ;
V_135 = 0 ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_86 ( V_1151 , V_1153 ,
F_29 ( V_367 ) , F_30 ( V_367 ) , NULL ) ;
V_47 = - V_16 ;
if ( ! V_1151 [ V_1138 ] ||
! V_1151 [ V_1139 ] )
goto error;
V_1135 = F_30 ( V_1151 [ V_1139 ] ) ;
V_1150 = F_239 ( V_1135 , 8 ) ;
if ( F_30 ( V_1151 [ V_1138 ] ) !=
V_1150 )
goto error;
if ( V_1135 > V_346 -> V_372 ||
V_1135 < V_346 -> V_370 )
goto error;
V_1143 . V_1136 [ V_135 ] . V_568 =
F_243 ( V_1150 + V_1135 , V_117 ) ;
if ( ! V_1143 . V_1136 [ V_135 ] . V_568 ) {
V_47 = - V_118 ;
goto error;
}
V_1143 . V_1136 [ V_135 ] . V_1140 =
V_1143 . V_1136 [ V_135 ] . V_568 + V_1150 ;
memcpy ( V_1143 . V_1136 [ V_135 ] . V_568 ,
F_29 ( V_1151 [ V_1138 ] ) ,
V_1150 ) ;
V_1143 . V_1136 [ V_135 ] . V_1137 = V_1135 ;
memcpy ( V_1143 . V_1136 [ V_135 ] . V_1140 ,
F_29 ( V_1151 [ V_1139 ] ) ,
V_1135 ) ;
V_135 ++ ;
}
}
V_1144 = F_244 ( & V_1143 , sizeof( V_1143 ) , V_117 ) ;
if ( ! V_1144 ) {
V_47 = - V_118 ;
goto error;
}
F_241 ( V_7 ) ;
V_7 -> V_346 = V_1144 ;
V_1147:
if ( V_7 -> V_223 -> V_1147 && V_1146 != ! ! V_7 -> V_346 )
V_7 -> V_223 -> V_1147 ( & V_7 -> V_18 , V_7 -> V_346 ) ;
return 0 ;
error:
for ( V_135 = 0 ; V_135 < V_1143 . V_347 ; V_135 ++ )
F_46 ( V_1143 . V_1136 [ V_135 ] . V_568 ) ;
F_46 ( V_1143 . V_1136 ) ;
return V_47 ;
}
static int F_245 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_4 * V_78 [ V_1154 ] ;
struct V_1155 V_1156 ;
int V_47 ;
if ( ! V_31 -> V_5 [ V_1157 ] )
return - V_16 ;
V_47 = F_86 ( V_78 , V_1158 ,
F_29 ( V_31 -> V_5 [ V_1157 ] ) ,
F_30 ( V_31 -> V_5 [ V_1157 ] ) ,
V_1159 ) ;
if ( V_47 )
return V_47 ;
if ( F_30 ( V_78 [ V_1160 ] ) != V_1161 )
return - V_1162 ;
if ( F_30 ( V_78 [ V_1163 ] ) != V_1164 )
return - V_1162 ;
if ( F_30 ( V_78 [ V_1165 ] ) != V_1166 )
return - V_1162 ;
memcpy ( V_1156 . V_1167 , F_29 ( V_78 [ V_1163 ] ) ,
V_1164 ) ;
memcpy ( V_1156 . V_1168 , F_29 ( V_78 [ V_1165 ] ) ,
V_1166 ) ;
memcpy ( V_1156 . V_1169 ,
F_29 ( V_78 [ V_1160 ] ) ,
V_1161 ) ;
F_95 ( V_17 ) ;
if ( ! V_17 -> V_127 ) {
V_47 = - V_1170 ;
goto V_461;
}
if ( ! V_7 -> V_223 -> V_1171 ) {
V_47 = - V_415 ;
goto V_461;
}
V_47 = V_7 -> V_223 -> V_1171 ( & V_7 -> V_18 , V_46 , & V_1156 ) ;
V_461:
F_97 ( V_17 ) ;
return V_47 ;
}
static int F_246 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
if ( V_17 -> V_121 != V_122 &&
V_17 -> V_121 != V_124 )
return - V_16 ;
if ( V_17 -> V_1172 )
return - V_417 ;
V_17 -> V_1172 = V_31 -> V_389 ;
return 0 ;
}
static int F_247 ( struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_26 * V_46 = V_31 -> V_387 [ 1 ] ;
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_44 * V_58 ;
void * V_159 ;
const T_2 * V_1173 ;
T_1 V_498 ;
int V_47 ;
if ( V_17 -> V_121 != V_122 &&
V_17 -> V_121 != V_124 )
return - V_415 ;
if ( ! V_31 -> V_5 [ V_421 ] )
return - V_16 ;
if ( ! V_7 -> V_223 -> V_316 )
return - V_415 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , V_31 -> V_389 , V_31 -> V_390 , 0 ,
V_1174 ) ;
if ( F_16 ( V_159 ) ) {
V_47 = F_24 ( V_159 ) ;
goto V_508;
}
V_1173 = F_29 ( V_31 -> V_5 [ V_421 ] ) ;
V_47 = V_7 -> V_223 -> V_316 ( & V_7 -> V_18 , V_46 , V_1173 , & V_498 ) ;
if ( V_47 )
goto V_508;
if ( F_88 ( V_58 , V_1069 , V_498 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_70 ( V_58 , V_31 ) ;
V_63:
V_47 = - V_74 ;
V_508:
F_69 ( V_58 ) ;
return V_47 ;
}
static int F_248 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_56 & V_320 ) )
return - V_415 ;
if ( V_7 -> V_1175 )
return - V_417 ;
V_7 -> V_1175 = V_31 -> V_389 ;
return 0 ;
}
static int F_249 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
int V_47 ;
if ( ! V_7 -> V_223 -> V_322 )
return - V_415 ;
if ( V_17 -> V_121 != V_486 )
return - V_415 ;
if ( V_17 -> V_1176 )
return 0 ;
F_8 ( & V_7 -> V_19 ) ;
V_47 = F_250 ( V_7 , V_17 -> V_121 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_47 )
return V_47 ;
V_47 = V_7 -> V_223 -> V_322 ( & V_7 -> V_18 , V_17 ) ;
if ( V_47 )
return V_47 ;
V_17 -> V_1176 = true ;
F_8 ( & V_7 -> V_19 ) ;
V_7 -> V_1177 ++ ;
F_9 ( & V_7 -> V_19 ) ;
return 0 ;
}
static int F_251 ( struct V_44 * V_45 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_387 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
if ( V_17 -> V_121 != V_486 )
return - V_415 ;
if ( ! V_7 -> V_223 -> V_1178 )
return - V_415 ;
if ( ! V_17 -> V_1176 )
return 0 ;
V_7 -> V_223 -> V_1178 ( & V_7 -> V_18 , V_17 ) ;
V_17 -> V_1176 = false ;
F_8 ( & V_7 -> V_19 ) ;
V_7 -> V_1177 -- ;
F_9 ( & V_7 -> V_19 ) ;
if ( F_201 ( V_7 -> V_886 && V_7 -> V_886 -> V_17 == V_17 ) ) {
V_7 -> V_886 -> V_1179 = true ;
F_252 ( V_7 , true ) ;
}
return 0 ;
}
static int F_253 ( struct V_1180 * V_223 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_26 * V_46 ;
bool V_1181 = V_223 -> V_1182 & V_1183 ;
if ( V_1181 )
F_20 () ;
if ( V_223 -> V_1182 & V_1184 ) {
V_7 = F_15 ( F_84 ( V_31 ) , V_31 ) ;
if ( F_16 ( V_7 ) ) {
if ( V_1181 )
F_25 () ;
return F_24 ( V_7 ) ;
}
V_31 -> V_387 [ 0 ] = V_7 ;
} else if ( V_223 -> V_1182 & V_1185 ||
V_223 -> V_1182 & V_1186 ) {
F_8 ( & V_32 ) ;
V_17 = F_1 ( F_84 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_17 ) ) {
F_9 ( & V_32 ) ;
if ( V_1181 )
F_25 () ;
return F_24 ( V_17 ) ;
}
V_46 = V_17 -> V_20 ;
V_7 = F_13 ( V_17 -> V_18 ) ;
if ( V_223 -> V_1182 & V_1185 ) {
if ( ! V_46 ) {
F_9 ( & V_32 ) ;
if ( V_1181 )
F_25 () ;
return - V_16 ;
}
V_31 -> V_387 [ 1 ] = V_46 ;
} else {
V_31 -> V_387 [ 1 ] = V_17 ;
}
if ( V_46 ) {
if ( V_223 -> V_1182 & V_1187 &&
! F_82 ( V_46 ) ) {
F_9 ( & V_32 ) ;
if ( V_1181 )
F_25 () ;
return - V_430 ;
}
F_163 ( V_46 ) ;
} else if ( V_223 -> V_1182 & V_1187 ) {
if ( ! V_17 -> V_1176 ) {
F_9 ( & V_32 ) ;
if ( V_1181 )
F_25 () ;
return - V_430 ;
}
}
F_197 ( V_7 ) ;
F_9 ( & V_32 ) ;
V_31 -> V_387 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_254 ( struct V_1180 * V_223 , struct V_44 * V_45 ,
struct V_30 * V_31 )
{
if ( V_31 -> V_387 [ 0 ] )
F_27 ( V_31 -> V_387 [ 0 ] ) ;
if ( V_31 -> V_387 [ 1 ] ) {
if ( V_223 -> V_1182 & V_1186 ) {
struct V_1 * V_17 = V_31 -> V_387 [ 1 ] ;
if ( V_17 -> V_20 )
F_14 ( V_17 -> V_20 ) ;
} else {
F_14 ( V_31 -> V_387 [ 1 ] ) ;
}
}
if ( V_223 -> V_1182 & V_1183 )
F_25 () ;
}
void F_255 ( struct V_6 * V_7 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_53 ( V_58 , 0 , 0 , 0 , V_7 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1188 . V_1040 , V_117 ) ;
}
static int F_257 ( struct V_44 * V_58 ,
struct V_6 * V_7 )
{
struct V_882 * V_1189 = V_7 -> V_886 ;
struct V_4 * V_1190 ;
int V_135 ;
F_258 ( V_7 ) ;
if ( F_201 ( ! V_1189 ) )
return 0 ;
V_1190 = F_50 ( V_58 , V_888 ) ;
if ( ! V_1190 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_1189 -> V_884 ; V_135 ++ ) {
if ( F_58 ( V_58 , V_135 , V_1189 -> V_889 [ V_135 ] . V_544 , V_1189 -> V_889 [ V_135 ] . V_482 ) )
goto V_63;
}
F_51 ( V_58 , V_1190 ) ;
V_1190 = F_50 ( V_58 , V_887 ) ;
if ( ! V_1190 )
goto V_63;
for ( V_135 = 0 ; V_135 < V_1189 -> V_250 ; V_135 ++ ) {
if ( F_34 ( V_58 , V_135 , V_1189 -> V_251 [ V_135 ] -> V_62 ) )
goto V_63;
}
F_51 ( V_58 , V_1190 ) ;
if ( V_1189 -> V_851 &&
F_58 ( V_58 , V_519 , V_1189 -> V_852 , V_1189 -> V_851 ) )
goto V_63;
return 0 ;
V_63:
return - V_74 ;
}
static int F_259 ( struct V_44 * V_58 ,
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
F_257 ( V_58 , V_7 ) ;
return F_62 ( V_58 , V_159 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
return - V_383 ;
}
static int
F_260 ( struct V_44 * V_58 ,
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
return - V_383 ;
}
void F_162 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_259 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1191 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1192 . V_1040 , V_117 ) ;
}
void F_261 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_259 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_917 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1192 . V_1040 , V_117 ) ;
}
void F_262 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_259 ( V_58 , V_7 , V_17 , 0 , 0 , 0 ,
V_1193 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1192 . V_1040 , V_117 ) ;
}
void F_263 ( struct V_6 * V_7 ,
struct V_26 * V_20 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_260 ( V_58 , V_7 , V_20 , 0 , 0 , 0 ,
V_1194 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1192 . V_1040 , V_117 ) ;
}
void F_165 ( struct V_6 * V_7 ,
struct V_26 * V_20 , V_23 V_57 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
if ( F_260 ( V_58 , V_7 , V_20 , 0 , 0 , 0 , V_57 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1192 . V_1040 , V_117 ) ;
}
void F_264 ( struct V_1195 * V_883 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1196 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_56 ( V_58 , V_1197 , V_883 -> V_1198 ) )
goto V_63;
if ( V_883 -> V_860 [ 0 ] == '0' && V_883 -> V_860 [ 1 ] == '0' ) {
if ( F_56 ( V_58 , V_1199 ,
V_1200 ) )
goto V_63;
} else if ( V_883 -> V_860 [ 0 ] == '9' && V_883 -> V_860 [ 1 ] == '9' ) {
if ( F_56 ( V_58 , V_1199 ,
V_1201 ) )
goto V_63;
} else if ( ( V_883 -> V_860 [ 0 ] == '9' && V_883 -> V_860 [ 1 ] == '8' ) ||
V_883 -> V_1202 ) {
if ( F_56 ( V_58 , V_1199 ,
V_1203 ) )
goto V_63;
} else {
if ( F_56 ( V_58 , V_1199 ,
V_1204 ) ||
F_54 ( V_58 , V_768 ,
V_883 -> V_860 ) )
goto V_63;
}
if ( F_265 ( V_883 -> V_14 ) &&
F_34 ( V_58 , V_27 , V_883 -> V_14 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_266 () ;
F_267 ( V_58 , 0 , V_1205 . V_1040 ,
V_1206 ) ;
F_268 () ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static void F_269 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1207 , T_10 V_52 ,
enum V_1208 V_57 , T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_1095 , V_52 , V_1207 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_270 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1207 ,
T_10 V_52 , T_11 V_1038 )
{
F_269 ( V_7 , V_20 , V_1207 , V_52 ,
V_1210 , V_1038 ) ;
}
void F_271 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1207 ,
T_10 V_52 , T_11 V_1038 )
{
F_269 ( V_7 , V_20 , V_1207 , V_52 ,
V_1211 , V_1038 ) ;
}
void F_272 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1207 ,
T_10 V_52 , T_11 V_1038 )
{
F_269 ( V_7 , V_20 , V_1207 , V_52 ,
V_1212 , V_1038 ) ;
}
void F_273 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1207 ,
T_10 V_52 , T_11 V_1038 )
{
F_269 ( V_7 , V_20 , V_1207 , V_52 ,
V_1213 , V_1038 ) ;
}
void F_274 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1207 ,
T_10 V_52 , T_11 V_1038 )
{
F_269 ( V_7 , V_20 , V_1207 , V_52 ,
V_1214 , V_1038 ) ;
}
void F_275 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1207 ,
T_10 V_52 , T_11 V_1038 )
{
F_269 ( V_7 , V_20 , V_1207 , V_52 ,
V_1215 , V_1038 ) ;
}
static void F_276 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_57 ,
const T_2 * V_1173 , T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_35 ( V_58 , V_1216 ) ||
F_58 ( V_58 , V_421 , V_454 , V_1173 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_277 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1173 ,
T_11 V_1038 )
{
F_276 ( V_7 , V_20 , V_1210 ,
V_1173 , V_1038 ) ;
}
void F_278 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1173 ,
T_11 V_1038 )
{
F_276 ( V_7 , V_20 , V_1211 ,
V_1173 , V_1038 ) ;
}
void F_279 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_420 ,
const T_2 * V_1217 , T_10 V_1218 ,
const T_2 * V_1219 , T_10 V_1220 ,
T_3 V_1221 , T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_327 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_420 && F_58 ( V_58 , V_421 , V_454 , V_420 ) ) ||
F_57 ( V_58 , V_1060 , V_1221 ) ||
( V_1217 &&
F_58 ( V_58 , V_1222 , V_1218 , V_1217 ) ) ||
( V_1219 &&
F_58 ( V_58 , V_1223 , V_1220 , V_1219 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_280 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_420 ,
const T_2 * V_1217 , T_10 V_1218 ,
const T_2 * V_1219 , T_10 V_1220 , T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1224 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_420 ) ||
( V_1217 &&
F_58 ( V_58 , V_1222 , V_1218 , V_1217 ) ) ||
( V_1219 &&
F_58 ( V_58 , V_1223 , V_1220 , V_1219 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_281 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_3 V_1044 ,
const T_2 * V_851 , T_10 V_852 , bool V_1225 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_117 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_329 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_1225 && V_1044 &&
F_57 ( V_58 , V_1015 , V_1044 ) ) ||
( V_1225 &&
F_35 ( V_58 , V_1226 ) ) ||
( V_851 && F_58 ( V_58 , V_519 , V_852 , V_851 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_117 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_282 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_420 ,
T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1227 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_420 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_283 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1228 , const T_2 * V_851 , T_2 V_852 ,
T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1229 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_1228 ) ||
( V_852 && V_851 &&
F_58 ( V_58 , V_519 , V_852 , V_851 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_284 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1173 ,
enum V_1230 V_1231 , int V_1232 ,
const T_2 * V_1233 , T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1234 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
( V_1173 && F_58 ( V_58 , V_421 , V_454 , V_1173 ) ) ||
F_34 ( V_58 , V_110 , V_1231 ) ||
( V_1232 != - 1 &&
F_56 ( V_58 , V_106 , V_1232 ) ) ||
( V_1233 && F_58 ( V_58 , V_105 , 6 , V_1233 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_285 ( struct V_18 * V_18 ,
struct V_59 * V_1235 ,
struct V_59 * V_1236 )
{
struct V_44 * V_58 ;
void * V_159 ;
struct V_4 * V_163 ;
V_58 = F_68 ( V_388 , V_1206 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1237 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , F_286 ( V_18 ) ) )
goto V_63;
V_163 = F_50 ( V_58 , V_1238 ) ;
if ( ! V_163 )
goto V_63;
if ( F_33 ( V_58 , V_1235 ) )
goto V_63;
F_51 ( V_58 , V_163 ) ;
V_163 = F_50 ( V_58 , V_1239 ) ;
if ( ! V_163 )
goto V_63;
if ( F_33 ( V_58 , V_1236 ) )
goto V_63;
F_51 ( V_58 , V_163 ) ;
F_62 ( V_58 , V_159 ) ;
F_266 () ;
F_267 ( V_58 , 0 , V_1205 . V_1040 ,
V_1206 ) ;
F_268 () ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static void F_287 (
int V_57 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_498 ,
struct V_59 * V_60 ,
enum V_405 V_406 ,
unsigned int V_1065 , T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
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
F_34 ( V_58 , V_414 , V_60 -> V_62 ) ||
F_34 ( V_58 , V_407 , V_406 ) ||
F_88 ( V_58 , V_1069 , V_498 ) )
goto V_63;
if ( V_57 == V_1068 &&
F_34 ( V_58 , V_1066 , V_1065 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_288 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_498 ,
struct V_59 * V_60 ,
enum V_405 V_406 ,
unsigned int V_1065 , T_11 V_1038 )
{
F_287 ( V_1068 ,
V_7 , V_17 , V_498 , V_60 ,
V_406 , V_1065 , V_1038 ) ;
}
void F_289 (
struct V_6 * V_7 ,
struct V_1 * V_17 ,
T_1 V_498 , struct V_59 * V_60 ,
enum V_405 V_406 , T_11 V_1038 )
{
F_287 ( V_1240 ,
V_7 , V_17 , V_498 , V_60 ,
V_406 , 0 , V_1038 ) ;
}
void F_290 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_500 ,
struct V_591 * V_592 , T_11 V_1038 )
{
struct V_44 * V_58 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
if ( F_126 ( V_58 , 0 , 0 , 0 ,
V_7 , V_46 , V_500 , V_592 ) < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
}
void F_291 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_500 ,
T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1241 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_500 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_292 ( struct V_6 * V_7 ,
struct V_26 * V_46 , const T_2 * V_500 ,
enum V_1242 V_1044 ,
T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_1243 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1244 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_500 ) ||
F_34 ( V_58 , V_1245 , V_1044 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static bool F_293 ( struct V_26 * V_46 , T_2 V_57 ,
const T_2 * V_1173 , T_11 V_1038 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_159 ;
int V_47 ;
V_23 V_1246 = F_294 ( V_17 -> V_1172 ) ;
if ( ! V_1246 )
return false ;
V_58 = F_68 ( 100 , V_1038 ) ;
if ( ! V_58 )
return true ;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_57 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return true ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_1173 ) )
goto V_63;
V_47 = F_62 ( V_58 , V_159 ) ;
if ( V_47 < 0 ) {
F_69 ( V_58 ) ;
return true ;
}
F_295 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1246 ) ;
return true ;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
return true ;
}
bool F_296 ( struct V_26 * V_46 , const T_2 * V_1173 , T_11 V_1038 )
{
return F_293 ( V_46 , V_1247 ,
V_1173 , V_1038 ) ;
}
bool F_297 ( struct V_26 * V_46 ,
const T_2 * V_1173 , T_11 V_1038 )
{
return F_293 ( V_46 ,
V_1248 ,
V_1173 , V_1038 ) ;
}
int F_298 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_23 V_1246 ,
int V_413 , int V_1249 ,
const T_2 * V_1207 , T_10 V_52 , T_11 V_1038 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return - V_118 ;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1096 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return - V_118 ;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_34 ( V_58 , V_414 , V_413 ) ||
( V_1249 &&
F_34 ( V_58 , V_1250 , V_1249 ) ) ||
F_58 ( V_58 , V_1095 , V_52 , V_1207 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
return F_295 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1246 ) ;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
return - V_74 ;
}
void F_299 ( struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_498 ,
const T_2 * V_1207 , T_10 V_52 , bool V_1251 ,
T_11 V_1038 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1252 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_34 ( V_58 , V_10 ,
V_20 -> V_21 ) ) ||
F_58 ( V_58 , V_1095 , V_52 , V_1207 ) ||
F_88 ( V_58 , V_1069 , V_498 ) ||
( V_1251 && F_35 ( V_58 , V_1253 ) ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_205 ( V_58 , 0 , V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void
F_300 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
enum V_1254 V_1255 ,
T_11 V_1038 )
{
struct V_44 * V_58 ;
struct V_4 * V_704 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1256 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_704 = F_50 ( V_58 , V_1116 ) ;
if ( ! V_704 )
goto V_63;
if ( F_34 ( V_58 , V_1257 ,
V_1255 ) )
goto V_63;
F_51 ( V_58 , V_704 ) ;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_301 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_420 ,
const T_2 * V_1169 , T_11 V_1038 )
{
struct V_44 * V_58 ;
struct V_4 * V_1258 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1259 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_420 ) )
goto V_63;
V_1258 = F_50 ( V_58 , V_1157 ) ;
if ( ! V_1258 )
goto V_63;
if ( F_58 ( V_58 , V_1160 ,
V_1161 , V_1169 ) )
goto V_63;
F_51 ( V_58 , V_1258 ) ;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_302 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_1260 ,
const T_2 * V_420 , bool V_1261 , T_11 V_1038 )
{
struct V_44 * V_58 ;
struct V_4 * V_50 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1262 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) )
goto V_63;
V_50 = F_50 ( V_58 , V_1263 ) ;
if ( ! V_50 )
goto V_63;
if ( F_34 ( V_58 , V_1264 , V_1260 ) ||
F_58 ( V_58 , V_1265 , V_454 , V_420 ) ||
( V_1261 &&
F_35 ( V_58 , V_1266 ) ) )
goto V_63;
F_51 ( V_58 , V_50 ) ;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_303 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_413 ,
enum V_405 type , T_11 V_1038 )
{
struct V_44 * V_58 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1267 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_34 ( V_58 , V_414 , V_413 ) ||
F_34 ( V_58 , V_407 , type ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void
F_304 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1058 ,
V_23 V_1268 , V_23 V_170 , V_23 V_1108 , T_11 V_1038 )
{
struct V_44 * V_58 ;
struct V_4 * V_704 ;
void * V_159 ;
V_58 = F_68 ( V_1243 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1256 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_1058 ) )
goto V_63;
V_704 = F_50 ( V_58 , V_1116 ) ;
if ( ! V_704 )
goto V_63;
if ( F_34 ( V_58 , V_1121 , V_1268 ) )
goto V_63;
if ( F_34 ( V_58 , V_1120 , V_170 ) )
goto V_63;
if ( F_34 ( V_58 , V_1122 , V_1108 ) )
goto V_63;
F_51 ( V_58 , V_704 ) ;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void
F_305 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1058 ,
V_23 V_1268 , T_11 V_1038 )
{
struct V_44 * V_58 ;
struct V_4 * V_704 ;
void * V_159 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1256 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_20 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_1058 ) )
goto V_63;
V_704 = F_50 ( V_58 , V_1116 ) ;
if ( ! V_704 )
goto V_63;
if ( F_34 ( V_58 , V_1269 , V_1268 ) )
goto V_63;
F_51 ( V_58 , V_704 ) ;
F_62 ( V_58 , V_159 ) ;
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_306 ( struct V_26 * V_46 , const T_2 * V_1173 ,
T_1 V_498 , bool V_1270 , T_11 V_1038 )
{
struct V_1 * V_17 = V_46 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_44 * V_58 ;
void * V_159 ;
int V_47 ;
V_58 = F_68 ( V_388 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1174 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
F_34 ( V_58 , V_10 , V_46 -> V_21 ) ||
F_58 ( V_58 , V_421 , V_454 , V_1173 ) ||
F_88 ( V_58 , V_1069 , V_498 ) ||
( V_1270 && F_35 ( V_58 , V_1253 ) ) )
goto V_63;
V_47 = F_62 ( V_58 , V_159 ) ;
if ( V_47 < 0 ) {
F_69 ( V_58 ) ;
return;
}
F_256 ( F_7 ( & V_7 -> V_18 ) , V_58 , 0 ,
V_1209 . V_1040 , V_1038 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
void F_307 ( struct V_18 * V_18 ,
const T_2 * V_1271 , T_10 V_52 ,
int V_413 , int V_1249 , T_11 V_1038 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_44 * V_58 ;
void * V_159 ;
V_23 V_1246 = F_294 ( V_7 -> V_1175 ) ;
if ( ! V_1246 )
return;
V_58 = F_68 ( V_52 + 100 , V_1038 ) ;
if ( ! V_58 )
return;
V_159 = F_31 ( V_58 , 0 , 0 , 0 , V_1096 ) ;
if ( ! V_159 ) {
F_69 ( V_58 ) ;
return;
}
if ( F_34 ( V_58 , V_27 , V_7 -> V_14 ) ||
( V_413 &&
F_34 ( V_58 , V_414 , V_413 ) ) ||
( V_1249 &&
F_34 ( V_58 , V_1250 , V_1249 ) ) ||
F_58 ( V_58 , V_1095 , V_52 , V_1271 ) )
goto V_63;
F_62 ( V_58 , V_159 ) ;
F_295 ( F_7 ( & V_7 -> V_18 ) , V_58 , V_1246 ) ;
return;
V_63:
F_63 ( V_58 , V_159 ) ;
F_69 ( V_58 ) ;
}
static int F_308 ( struct V_1272 * V_1273 ,
unsigned long V_1098 ,
void * V_1274 )
{
struct V_1275 * V_1276 = V_1274 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
if ( V_1098 != V_1277 )
return V_1278 ;
F_266 () ;
F_309 (rdev, &cfg80211_rdev_list, list) {
F_309 (wdev, &rdev->wdev_list, list)
F_310 ( V_17 , V_1276 -> V_54 ) ;
if ( V_7 -> V_1175 == V_1276 -> V_54 )
V_7 -> V_1175 = 0 ;
}
F_268 () ;
return V_1278 ;
}
int F_311 ( void )
{
int V_47 ;
V_47 = F_312 ( & V_39 ,
V_1279 , F_313 ( V_1279 ) ) ;
if ( V_47 )
return V_47 ;
V_47 = F_314 ( & V_39 , & V_1188 ) ;
if ( V_47 )
goto V_1280;
V_47 = F_314 ( & V_39 , & V_1192 ) ;
if ( V_47 )
goto V_1280;
V_47 = F_314 ( & V_39 , & V_1205 ) ;
if ( V_47 )
goto V_1280;
V_47 = F_314 ( & V_39 , & V_1209 ) ;
if ( V_47 )
goto V_1280;
#ifdef F_60
V_47 = F_314 ( & V_39 , & V_1039 ) ;
if ( V_47 )
goto V_1280;
#endif
V_47 = F_315 ( & V_1281 ) ;
if ( V_47 )
goto V_1280;
return 0 ;
V_1280:
F_316 ( & V_39 ) ;
return V_47 ;
}
void F_317 ( void )
{
F_318 ( & V_1281 ) ;
F_316 ( & V_39 ) ;
}
