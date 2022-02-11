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
static int F_17 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
int V_38 ;
F_18 () ;
F_8 ( & V_32 ) ;
if ( ! V_37 -> args [ 0 ] ) {
V_38 = F_19 ( V_37 -> V_39 , V_40 + V_41 . V_42 ,
V_41 . V_43 , V_41 . V_44 ,
V_45 ) ;
if ( V_38 )
goto V_46;
* V_17 = F_1 ( F_20 ( V_35 -> V_47 ) ,
V_41 . V_43 ) ;
if ( F_16 ( * V_17 ) ) {
V_38 = F_21 ( * V_17 ) ;
goto V_46;
}
* V_7 = F_13 ( ( * V_17 ) -> V_18 ) ;
V_37 -> args [ 0 ] = ( * V_7 ) -> V_14 ;
V_37 -> args [ 1 ] = ( * V_17 ) -> V_22 ;
} else {
struct V_18 * V_18 = F_22 ( V_37 -> args [ 0 ] ) ;
struct V_1 * V_25 ;
if ( ! V_18 ) {
V_38 = - V_24 ;
goto V_46;
}
* V_7 = F_13 ( V_18 ) ;
* V_17 = NULL ;
F_8 ( & ( * V_7 ) -> V_19 ) ;
F_6 (tmp, &(*rdev)->wdev_list, list) {
if ( V_25 -> V_22 == V_37 -> args [ 1 ] ) {
* V_17 = V_25 ;
break;
}
}
F_9 ( & ( * V_7 ) -> V_19 ) ;
if ( ! * V_17 ) {
V_38 = - V_24 ;
goto V_46;
}
}
F_23 ( * V_7 ) ;
F_9 ( & V_32 ) ;
return 0 ;
V_46:
F_9 ( & V_32 ) ;
F_24 () ;
return V_38 ;
}
static void F_25 ( struct V_6 * V_7 )
{
F_26 ( V_7 ) ;
F_24 () ;
}
static bool F_27 ( const struct V_4 * V_48 )
{
const T_2 * V_49 ;
int V_50 ;
if ( ! V_48 )
return true ;
V_49 = F_28 ( V_48 ) ;
V_50 = F_29 ( V_48 ) ;
while ( V_50 ) {
T_2 V_51 ;
if ( V_50 < 2 )
return false ;
V_50 -= 2 ;
V_51 = V_49 [ 1 ] ;
if ( V_51 > V_50 )
return false ;
V_50 -= V_51 ;
V_49 += 2 + V_51 ;
}
return true ;
}
static inline void * F_30 ( struct V_34 * V_35 , V_23 V_52 , V_23 V_53 ,
int V_54 , T_2 V_55 )
{
return F_31 ( V_35 , V_52 , V_53 , & V_41 , V_54 , V_55 ) ;
}
static int F_32 ( struct V_34 * V_56 ,
struct V_57 * V_58 ,
bool V_59 )
{
if ( F_33 ( V_56 , V_60 ,
V_58 -> V_61 ) )
goto V_62;
if ( ( V_58 -> V_54 & V_63 ) &&
F_34 ( V_56 , V_64 ) )
goto V_62;
if ( ( V_58 -> V_54 & V_65 ) &&
F_34 ( V_56 , V_66 ) )
goto V_62;
if ( ( V_58 -> V_54 & V_67 ) &&
F_34 ( V_56 , V_68 ) )
goto V_62;
if ( V_58 -> V_54 & V_69 ) {
if ( F_34 ( V_56 , V_70 ) )
goto V_62;
if ( V_59 ) {
V_23 time ;
time = F_35 ( V_58 -> V_71 ) ;
if ( F_33 ( V_56 , V_72 ,
V_58 -> V_73 ) )
goto V_62;
if ( F_33 ( V_56 , V_74 ,
time ) )
goto V_62;
}
}
if ( V_59 ) {
if ( ( V_58 -> V_54 & V_75 ) &&
F_34 ( V_56 , V_76 ) )
goto V_62;
if ( ( V_58 -> V_54 & V_77 ) &&
F_34 ( V_56 , V_78 ) )
goto V_62;
if ( ( V_58 -> V_54 & V_79 ) &&
F_34 ( V_56 , V_80 ) )
goto V_62;
if ( ( V_58 -> V_54 & V_81 ) &&
F_34 ( V_56 , V_82 ) )
goto V_62;
}
if ( F_33 ( V_56 , V_83 ,
F_36 ( V_58 -> V_84 ) ) )
goto V_62;
return 0 ;
V_62:
return - V_85 ;
}
static int F_37 ( struct V_4 * V_86 , struct V_87 * V_88 )
{
struct V_4 * V_89 [ V_90 + 1 ] ;
int V_38 = F_38 ( V_89 , V_90 , V_86 ,
V_91 ) ;
if ( V_38 )
return V_38 ;
V_88 -> V_92 = ! ! V_89 [ V_93 ] ;
V_88 -> V_94 = ! ! V_89 [ V_95 ] ;
if ( V_88 -> V_92 ) {
V_88 -> V_96 = true ;
V_88 -> V_97 = true ;
}
if ( V_88 -> V_94 )
V_88 -> V_97 = true ;
if ( V_89 [ V_98 ] )
V_88 -> V_99 = F_39 ( V_89 [ V_98 ] ) ;
if ( V_89 [ V_100 ] ) {
V_88 -> V_101 . V_86 = F_28 ( V_89 [ V_100 ] ) ;
V_88 -> V_101 . V_102 = F_29 ( V_89 [ V_100 ] ) ;
}
if ( V_89 [ V_103 ] ) {
V_88 -> V_101 . V_53 = F_28 ( V_89 [ V_103 ] ) ;
V_88 -> V_101 . V_104 = F_29 ( V_89 [ V_103 ] ) ;
}
if ( V_89 [ V_105 ] )
V_88 -> V_101 . V_106 = F_4 ( V_89 [ V_105 ] ) ;
if ( V_89 [ V_107 ] ) {
V_88 -> type = F_4 ( V_89 [ V_107 ] ) ;
if ( V_88 -> type < 0 || V_88 -> type >= V_108 )
return - V_16 ;
}
if ( V_89 [ V_109 ] ) {
struct V_4 * V_110 [ V_111 ] ;
V_38 = F_38 ( V_110 , V_111 - 1 ,
V_89 [ V_109 ] ,
V_112 ) ;
if ( V_38 )
return V_38 ;
V_88 -> V_96 = V_110 [ V_113 ] ;
V_88 -> V_97 = V_110 [ V_114 ] ;
}
return 0 ;
}
static int F_40 ( struct V_30 * V_31 , struct V_87 * V_88 )
{
if ( V_31 -> V_5 [ V_115 ] ) {
V_88 -> V_101 . V_86 = F_28 ( V_31 -> V_5 [ V_115 ] ) ;
V_88 -> V_101 . V_102 = F_29 ( V_31 -> V_5 [ V_115 ] ) ;
}
if ( V_31 -> V_5 [ V_116 ] ) {
V_88 -> V_101 . V_53 = F_28 ( V_31 -> V_5 [ V_116 ] ) ;
V_88 -> V_101 . V_104 = F_29 ( V_31 -> V_5 [ V_116 ] ) ;
}
if ( V_31 -> V_5 [ V_117 ] )
V_88 -> V_99 = F_39 ( V_31 -> V_5 [ V_117 ] ) ;
if ( V_31 -> V_5 [ V_118 ] )
V_88 -> V_101 . V_106 = F_4 ( V_31 -> V_5 [ V_118 ] ) ;
V_88 -> V_92 = ! ! V_31 -> V_5 [ V_119 ] ;
V_88 -> V_94 = ! ! V_31 -> V_5 [ V_120 ] ;
if ( V_88 -> V_92 ) {
V_88 -> V_96 = true ;
V_88 -> V_97 = true ;
}
if ( V_88 -> V_94 )
V_88 -> V_97 = true ;
if ( V_31 -> V_5 [ V_121 ] ) {
V_88 -> type = F_4 ( V_31 -> V_5 [ V_121 ] ) ;
if ( V_88 -> type < 0 || V_88 -> type >= V_108 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_122 ] ) {
struct V_4 * V_110 [ V_111 ] ;
int V_38 = F_38 (
V_110 , V_111 - 1 ,
V_31 -> V_5 [ V_122 ] ,
V_112 ) ;
if ( V_38 )
return V_38 ;
V_88 -> V_96 = V_110 [ V_113 ] ;
V_88 -> V_97 = V_110 [ V_114 ] ;
}
return 0 ;
}
static int F_41 ( struct V_30 * V_31 , struct V_87 * V_88 )
{
int V_38 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
V_88 -> V_99 = - 1 ;
V_88 -> type = - 1 ;
if ( V_31 -> V_5 [ V_123 ] )
V_38 = F_37 ( V_31 -> V_5 [ V_123 ] , V_88 ) ;
else
V_38 = F_40 ( V_31 , V_88 ) ;
if ( V_38 )
return V_38 ;
if ( V_88 -> V_92 && V_88 -> V_94 )
return - V_16 ;
if ( V_88 -> V_94 ) {
if ( V_88 -> V_96 || ! V_88 -> V_97 )
return - V_16 ;
}
if ( V_88 -> V_99 != - 1 ) {
if ( V_88 -> V_94 ) {
if ( V_88 -> V_99 < 4 || V_88 -> V_99 > 5 )
return - V_16 ;
} else if ( V_88 -> V_92 ) {
if ( V_88 -> V_99 < 0 || V_88 -> V_99 > 3 )
return - V_16 ;
} else {
if ( V_88 -> V_99 < 0 || V_88 -> V_99 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_124 *
F_42 ( struct V_6 * V_7 ,
struct V_4 * V_125 , bool * V_126 )
{
struct V_87 V_127 ;
struct V_4 * V_86 ;
struct V_124 * V_8 ;
int V_128 , V_38 , V_92 = 0 ;
V_8 = F_43 ( sizeof( * V_8 ) , V_129 ) ;
if ( ! V_8 )
return F_3 ( - V_130 ) ;
V_8 -> V_92 = - 1 ;
V_8 -> V_94 = - 1 ;
F_44 (key, keys, rem) {
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_99 = - 1 ;
V_38 = F_37 ( V_86 , & V_127 ) ;
if ( V_38 )
goto error;
V_38 = - V_16 ;
if ( ! V_127 . V_101 . V_86 )
goto error;
if ( V_127 . V_99 < 0 || V_127 . V_99 > 4 )
goto error;
if ( V_127 . V_92 ) {
if ( V_92 )
goto error;
V_92 = 1 ;
V_8 -> V_92 = V_127 . V_99 ;
if ( ! V_127 . V_96 || ! V_127 . V_97 )
goto error;
} else if ( V_127 . V_94 )
goto error;
V_38 = F_45 ( V_7 , & V_127 . V_101 ,
V_127 . V_99 , false , NULL ) ;
if ( V_38 )
goto error;
V_8 -> V_131 [ V_127 . V_99 ] . V_106 = V_127 . V_101 . V_106 ;
V_8 -> V_131 [ V_127 . V_99 ] . V_102 = V_127 . V_101 . V_102 ;
V_8 -> V_131 [ V_127 . V_99 ] . V_86 = V_8 -> V_132 [ V_127 . V_99 ] ;
memcpy ( V_8 -> V_132 [ V_127 . V_99 ] , V_127 . V_101 . V_86 , V_127 . V_101 . V_102 ) ;
if ( V_127 . V_101 . V_106 == V_133 ||
V_127 . V_101 . V_106 == V_134 ) {
if ( V_126 )
* V_126 = true ;
}
}
return V_8 ;
error:
F_46 ( V_8 ) ;
return F_3 ( V_38 ) ;
}
static int F_47 ( struct V_1 * V_17 )
{
F_48 ( V_17 ) ;
switch ( V_17 -> V_135 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
break;
case V_140 :
if ( ! V_17 -> V_141 )
return - V_142 ;
break;
case V_143 :
case V_144 :
if ( V_17 -> V_145 != V_146 )
return - V_142 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_49 ( struct V_34 * V_56 , V_23 V_48 , T_3 V_147 )
{
struct V_4 * V_148 = F_50 ( V_56 , V_48 ) ;
int V_149 ;
if ( ! V_148 )
goto V_62;
V_149 = 0 ;
while ( V_147 ) {
if ( ( V_147 & 1 ) && F_34 ( V_56 , V_149 ) )
goto V_62;
V_147 >>= 1 ;
V_149 ++ ;
}
F_51 ( V_56 , V_148 ) ;
return 0 ;
V_62:
return - V_85 ;
}
static int F_52 ( struct V_18 * V_18 ,
struct V_34 * V_56 ,
bool V_59 )
{
struct V_4 * V_150 ;
int V_149 , V_151 ;
V_150 = F_50 ( V_56 ,
V_152 ) ;
if ( ! V_150 )
goto V_62;
for ( V_149 = 0 ; V_149 < V_18 -> V_153 ; V_149 ++ ) {
const struct V_154 * V_155 ;
struct V_4 * V_156 , * V_157 ;
V_155 = & V_18 -> V_158 [ V_149 ] ;
V_156 = F_50 ( V_56 , V_149 + 1 ) ;
if ( ! V_156 )
goto V_62;
V_157 = F_50 ( V_56 , V_159 ) ;
if ( ! V_157 )
goto V_62;
for ( V_151 = 0 ; V_151 < V_155 -> V_160 ; V_151 ++ ) {
struct V_4 * V_161 ;
V_161 = F_50 ( V_56 , V_151 + 1 ) ;
if ( ! V_161 )
goto V_62;
if ( F_33 ( V_56 , V_162 ,
V_155 -> V_163 [ V_151 ] . V_164 ) )
goto V_62;
if ( F_49 ( V_56 , V_165 ,
V_155 -> V_163 [ V_151 ] . V_166 ) )
goto V_62;
F_51 ( V_56 , V_161 ) ;
}
F_51 ( V_56 , V_157 ) ;
if ( V_155 -> V_167 &&
F_34 ( V_56 , V_168 ) )
goto V_62;
if ( F_33 ( V_56 , V_169 ,
V_155 -> V_170 ) ||
F_33 ( V_56 , V_171 ,
V_155 -> V_172 ) )
goto V_62;
if ( V_59 &&
F_33 ( V_56 , V_173 ,
V_155 -> V_174 ) )
goto V_62;
F_51 ( V_56 , V_156 ) ;
}
F_51 ( V_56 , V_150 ) ;
return 0 ;
V_62:
return - V_85 ;
}
static int F_53 ( struct V_6 * V_7 ,
struct V_34 * V_56 )
{
const struct V_175 * V_176 = V_7 -> V_18 . V_177 . V_176 ;
struct V_4 * V_178 ;
if ( ! V_176 )
return 0 ;
V_178 = F_50 ( V_56 , V_179 ) ;
if ( ! V_178 )
return - V_85 ;
if ( F_33 ( V_56 , V_180 ,
V_176 -> V_181 ) )
return - V_85 ;
if ( F_33 ( V_56 , V_180 ,
V_176 -> V_181 ) )
return - V_85 ;
if ( V_176 -> V_53 && F_34 ( V_56 , V_182 ) )
return - V_85 ;
if ( V_176 -> V_183 && F_54 ( V_56 , V_184 ,
sizeof( * V_176 -> V_183 ) , V_176 -> V_183 ) )
return - V_85 ;
if ( F_33 ( V_56 , V_185 ,
V_176 -> V_186 ) )
return - V_85 ;
if ( F_33 ( V_56 , V_187 ,
V_176 -> V_188 ) )
return - V_85 ;
F_51 ( V_56 , V_178 ) ;
return 0 ;
}
static int F_55 ( struct V_34 * V_56 ,
struct V_6 * V_189 ,
bool V_59 )
{
struct V_4 * V_190 ;
if ( ! V_189 -> V_18 . V_177 . V_54 && ! V_189 -> V_18 . V_177 . V_191 )
return 0 ;
V_190 = F_50 ( V_56 , V_192 ) ;
if ( ! V_190 )
return - V_85 ;
if ( ( ( V_189 -> V_18 . V_177 . V_54 & V_193 ) &&
F_34 ( V_56 , V_194 ) ) ||
( ( V_189 -> V_18 . V_177 . V_54 & V_195 ) &&
F_34 ( V_56 , V_196 ) ) ||
( ( V_189 -> V_18 . V_177 . V_54 & V_197 ) &&
F_34 ( V_56 , V_198 ) ) ||
( ( V_189 -> V_18 . V_177 . V_54 & V_199 ) &&
F_34 ( V_56 , V_200 ) ) ||
( ( V_189 -> V_18 . V_177 . V_54 & V_201 ) &&
F_34 ( V_56 , V_202 ) ) ||
( ( V_189 -> V_18 . V_177 . V_54 & V_203 ) &&
F_34 ( V_56 , V_204 ) ) ||
( ( V_189 -> V_18 . V_177 . V_54 & V_205 ) &&
F_34 ( V_56 , V_206 ) ) ||
( ( V_189 -> V_18 . V_177 . V_54 & V_207 ) &&
F_34 ( V_56 , V_208 ) ) )
return - V_85 ;
if ( V_189 -> V_18 . V_177 . V_191 ) {
struct V_209 V_210 = {
. V_211 = V_189 -> V_18 . V_177 . V_191 ,
. V_212 = V_189 -> V_18 . V_177 . V_213 ,
. V_214 = V_189 -> V_18 . V_177 . V_215 ,
. V_216 = V_189 -> V_18 . V_177 . V_216 ,
} ;
if ( F_54 ( V_56 , V_217 ,
sizeof( V_210 ) , & V_210 ) )
return - V_85 ;
}
if ( V_59 && F_53 ( V_189 , V_56 ) )
return - V_85 ;
F_51 ( V_56 , V_190 ) ;
return 0 ;
}
static int F_56 ( struct V_34 * V_56 ,
struct V_218 * V_219 )
{
struct V_4 * V_220 , * V_221 ;
struct V_222 * V_223 ;
int V_149 ;
if ( V_219 -> V_224 . V_225 &&
( F_54 ( V_56 , V_226 ,
sizeof( V_219 -> V_224 . V_227 ) ,
& V_219 -> V_224 . V_227 ) ||
F_57 ( V_56 , V_228 ,
V_219 -> V_224 . V_229 ) ||
F_58 ( V_56 , V_230 ,
V_219 -> V_224 . V_231 ) ||
F_58 ( V_56 , V_232 ,
V_219 -> V_224 . V_233 ) ) )
return - V_85 ;
if ( V_219 -> V_234 . V_235 &&
( F_54 ( V_56 , V_236 ,
sizeof( V_219 -> V_234 . V_237 ) ,
& V_219 -> V_234 . V_237 ) ||
F_33 ( V_56 , V_238 ,
V_219 -> V_234 . V_229 ) ) )
return - V_85 ;
V_220 = F_50 ( V_56 , V_239 ) ;
if ( ! V_220 )
return - V_85 ;
for ( V_149 = 0 ; V_149 < V_219 -> V_240 ; V_149 ++ ) {
V_221 = F_50 ( V_56 , V_149 ) ;
if ( ! V_221 )
return - V_85 ;
V_223 = & V_219 -> V_241 [ V_149 ] ;
if ( F_33 ( V_56 , V_242 ,
V_223 -> V_243 ) )
return - V_85 ;
if ( ( V_223 -> V_54 & V_244 ) &&
F_34 ( V_56 ,
V_245 ) )
return - V_85 ;
F_51 ( V_56 , V_221 ) ;
}
F_51 ( V_56 , V_220 ) ;
return 0 ;
}
static int
F_59 ( struct V_34 * V_56 ,
const struct V_246 * V_247 )
{
T_3 V_248 ;
struct V_4 * V_249 , * V_250 ;
enum V_251 V_252 ;
int V_149 ;
if ( ! V_247 )
return 0 ;
V_250 = F_50 ( V_56 , V_253 ) ;
if ( ! V_250 )
return - V_85 ;
for ( V_252 = 0 ; V_252 < V_254 ; V_252 ++ ) {
V_249 = F_50 ( V_56 , V_252 ) ;
if ( ! V_249 )
return - V_85 ;
V_149 = 0 ;
V_248 = V_247 [ V_252 ] . V_255 ;
while ( V_248 ) {
if ( ( V_248 & 1 ) &&
F_57 ( V_56 , V_256 ,
( V_149 << 4 ) | V_257 ) )
return - V_85 ;
V_248 >>= 1 ;
V_149 ++ ;
}
F_51 ( V_56 , V_249 ) ;
}
F_51 ( V_56 , V_250 ) ;
V_250 = F_50 ( V_56 , V_258 ) ;
if ( ! V_250 )
return - V_85 ;
for ( V_252 = 0 ; V_252 < V_254 ; V_252 ++ ) {
V_249 = F_50 ( V_56 , V_252 ) ;
if ( ! V_249 )
return - V_85 ;
V_149 = 0 ;
V_248 = V_247 [ V_252 ] . V_259 ;
while ( V_248 ) {
if ( ( V_248 & 1 ) &&
F_57 ( V_56 , V_256 ,
( V_149 << 4 ) | V_257 ) )
return - V_85 ;
V_248 >>= 1 ;
V_149 ++ ;
}
F_51 ( V_56 , V_249 ) ;
}
F_51 ( V_56 , V_250 ) ;
return 0 ;
}
static int F_60 ( struct V_6 * V_189 ,
struct V_34 * V_56 , V_23 V_52 , V_23 V_53 ,
int V_54 , bool V_260 , long * V_261 ,
long * V_262 , long * V_263 )
{
void * V_264 ;
struct V_4 * V_265 , * V_266 ;
struct V_4 * V_267 , * V_268 ;
struct V_4 * V_269 ;
enum V_270 V_271 ;
struct V_57 * V_58 ;
int V_149 ;
const struct V_246 * V_247 =
V_189 -> V_18 . V_247 ;
long V_272 = 0 , V_273 = 0 , V_274 = 0 ;
V_23 V_275 ;
V_264 = F_30 ( V_56 , V_52 , V_53 , V_54 , V_276 ) ;
if ( ! V_264 )
return - V_85 ;
if ( ! V_260 ) {
V_261 = & V_272 ;
V_262 = & V_274 ;
V_263 = & V_273 ;
}
if ( F_33 ( V_56 , V_27 , V_189 -> V_14 ) ||
F_61 ( V_56 , V_277 ,
F_62 ( & V_189 -> V_18 ) ) ||
F_33 ( V_56 , V_278 ,
V_279 ) )
goto V_62;
switch ( * V_261 ) {
case 0 :
if ( F_58 ( V_56 , V_280 ,
V_189 -> V_18 . V_281 ) ||
F_58 ( V_56 , V_282 ,
V_189 -> V_18 . V_283 ) ||
F_33 ( V_56 , V_284 ,
V_189 -> V_18 . V_285 ) ||
F_33 ( V_56 , V_286 ,
V_189 -> V_18 . V_287 ) ||
F_58 ( V_56 , V_288 ,
V_189 -> V_18 . V_289 ) ||
F_58 ( V_56 , V_290 ,
V_189 -> V_18 . V_291 ) ||
F_58 ( V_56 , V_292 ,
V_189 -> V_18 . V_293 ) ||
F_57 ( V_56 , V_294 ,
V_189 -> V_18 . V_295 ) ||
F_57 ( V_56 , V_296 ,
V_189 -> V_18 . V_297 ) ||
F_58 ( V_56 , V_298 ,
V_189 -> V_18 . V_299 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_300 ) &&
F_34 ( V_56 , V_301 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_302 ) &&
F_34 ( V_56 , V_303 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_304 ) &&
F_34 ( V_56 , V_305 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_306 ) &&
F_34 ( V_56 , V_307 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_308 ) &&
F_34 ( V_56 , V_309 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_310 ) &&
F_34 ( V_56 , V_311 ) )
goto V_62;
( * V_261 ) ++ ;
if ( V_260 )
break;
case 1 :
if ( F_54 ( V_56 , V_312 ,
sizeof( V_23 ) * V_189 -> V_18 . V_313 ,
V_189 -> V_18 . V_314 ) )
goto V_62;
if ( F_58 ( V_56 , V_315 ,
V_189 -> V_18 . V_316 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_317 ) &&
F_34 ( V_56 , V_318 ) )
goto V_62;
if ( F_33 ( V_56 , V_319 ,
V_189 -> V_18 . V_320 ) ||
F_33 ( V_56 , V_321 ,
V_189 -> V_18 . V_322 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_323 ) &&
F_33 ( V_56 , V_324 ,
V_189 -> V_18 . V_325 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_320 ||
V_189 -> V_18 . V_322 ) &&
V_189 -> V_326 -> V_327 ) {
V_23 V_328 = 0 , V_329 = 0 ;
int V_330 ;
V_330 = F_63 ( V_189 , & V_328 , & V_329 ) ;
if ( ! V_330 ) {
if ( F_33 ( V_56 ,
V_331 ,
V_328 ) ||
F_33 ( V_56 ,
V_332 ,
V_329 ) )
goto V_62;
}
}
( * V_261 ) ++ ;
if ( V_260 )
break;
case 2 :
if ( F_49 ( V_56 , V_333 ,
V_189 -> V_18 . V_334 ) )
goto V_62;
( * V_261 ) ++ ;
if ( V_260 )
break;
case 3 :
V_265 = F_50 ( V_56 , V_335 ) ;
if ( ! V_265 )
goto V_62;
for ( V_271 = * V_262 ; V_271 < V_336 ; V_271 ++ ) {
struct V_218 * V_219 ;
V_219 = V_189 -> V_18 . V_337 [ V_271 ] ;
if ( ! V_219 )
continue;
V_266 = F_50 ( V_56 , V_271 ) ;
if ( ! V_266 )
goto V_62;
switch ( * V_263 ) {
case 0 :
if ( F_56 ( V_56 , V_219 ) )
goto V_62;
( * V_263 ) ++ ;
if ( V_260 )
break;
default:
V_267 = F_50 (
V_56 , V_338 ) ;
if ( ! V_267 )
goto V_62;
for ( V_149 = * V_263 - 1 ;
V_149 < V_219 -> V_339 ;
V_149 ++ ) {
V_268 = F_50 ( V_56 , V_149 ) ;
if ( ! V_268 )
goto V_62;
V_58 = & V_219 -> V_340 [ V_149 ] ;
if ( F_32 ( V_56 , V_58 ,
V_260 ) )
goto V_62;
F_51 ( V_56 , V_268 ) ;
if ( V_260 )
break;
}
if ( V_149 < V_219 -> V_339 )
* V_263 = V_149 + 2 ;
else
* V_263 = 0 ;
F_51 ( V_56 , V_267 ) ;
}
F_51 ( V_56 , V_266 ) ;
if ( V_260 ) {
if ( * V_263 )
V_271 -- ;
break;
}
}
F_51 ( V_56 , V_265 ) ;
if ( V_271 < V_336 )
* V_262 = V_271 + 1 ;
else
* V_262 = 0 ;
if ( * V_262 == 0 && * V_263 == 0 )
( * V_261 ) ++ ;
if ( V_260 )
break;
case 4 :
V_269 = F_50 ( V_56 , V_341 ) ;
if ( ! V_269 )
goto V_62;
V_149 = 0 ;
#define F_64 ( T_4 , T_5 ) \
do { \
if (dev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_64 ( V_342 , V_343 ) ;
F_64 ( V_344 , V_345 ) ;
F_64 ( V_346 , V_347 ) ;
F_64 ( V_348 , V_349 ) ;
F_64 ( V_350 , V_351 ) ;
F_64 ( V_352 , V_353 ) ;
F_64 ( V_354 , V_355 ) ;
F_64 ( V_356 , V_357 ) ;
F_64 ( V_358 , V_359 ) ;
F_64 ( V_360 , V_361 ) ;
F_64 ( V_362 , V_363 ) ;
F_64 ( V_364 , V_365 ) ;
F_64 ( V_366 , V_367 ) ;
F_64 ( V_368 , V_369 ) ;
F_64 ( V_370 , V_371 ) ;
F_64 ( V_372 , V_373 ) ;
F_64 ( V_374 , V_375 ) ;
if ( V_189 -> V_18 . V_54 & V_376 )
F_64 ( V_377 , V_378 ) ;
F_64 ( V_379 , V_380 ) ;
F_64 ( V_381 , V_382 ) ;
F_64 ( V_383 , V_384 ) ;
if ( V_189 -> V_18 . V_54 & V_385 ) {
V_149 ++ ;
if ( F_33 ( V_56 , V_149 , V_386 ) )
goto V_62;
}
if ( V_189 -> V_326 -> V_387 || V_189 -> V_326 -> V_348 ||
V_189 -> V_326 -> V_368 ) {
V_149 ++ ;
if ( F_33 ( V_56 , V_149 , V_388 ) )
goto V_62;
}
F_64 ( V_389 , V_390 ) ;
if ( V_189 -> V_18 . V_54 & V_308 ) {
F_64 ( V_391 , V_392 ) ;
F_64 ( V_393 , V_394 ) ;
}
if ( V_189 -> V_18 . V_54 & V_395 )
F_64 ( V_396 , V_397 ) ;
F_64 ( V_398 , V_399 ) ;
F_64 ( V_400 , V_401 ) ;
if ( V_189 -> V_18 . V_54 & V_402 ) {
V_149 ++ ;
if ( F_33 ( V_56 , V_149 , V_403 ) )
goto V_62;
}
F_64 ( V_404 , V_405 ) ;
F_64 ( V_406 , V_407 ) ;
if ( V_260 ) {
F_64 ( V_408 , V_409 ) ;
F_64 ( V_410 , V_411 ) ;
}
#ifdef F_65
F_64 ( V_412 , V_413 ) ;
#endif
#undef F_64
if ( V_189 -> V_326 -> V_414 || V_189 -> V_326 -> V_358 ) {
V_149 ++ ;
if ( F_33 ( V_56 , V_149 , V_415 ) )
goto V_62;
}
if ( V_189 -> V_326 -> V_416 || V_189 -> V_326 -> V_362 ) {
V_149 ++ ;
if ( F_33 ( V_56 , V_149 , V_417 ) )
goto V_62;
}
F_51 ( V_56 , V_269 ) ;
( * V_261 ) ++ ;
if ( V_260 )
break;
case 5 :
if ( V_189 -> V_326 -> V_377 &&
( V_189 -> V_18 . V_54 & V_376 ) &&
F_33 ( V_56 ,
V_418 ,
V_189 -> V_18 . V_419 ) )
goto V_62;
if ( ( V_189 -> V_18 . V_54 & V_420 ) &&
F_34 ( V_56 , V_421 ) )
goto V_62;
if ( F_59 ( V_56 , V_247 ) )
goto V_62;
( * V_261 ) ++ ;
if ( V_260 )
break;
case 6 :
#ifdef F_66
if ( F_55 ( V_56 , V_189 , V_260 ) )
goto V_62;
( * V_261 ) ++ ;
if ( V_260 )
break;
#else
( * V_261 ) ++ ;
#endif
case 7 :
if ( F_49 ( V_56 , V_422 ,
V_189 -> V_18 . V_423 ) )
goto V_62;
if ( F_52 ( & V_189 -> V_18 , V_56 , V_260 ) )
goto V_62;
( * V_261 ) ++ ;
if ( V_260 )
break;
case 8 :
if ( ( V_189 -> V_18 . V_54 & V_424 ) &&
F_33 ( V_56 , V_425 ,
V_189 -> V_18 . V_426 ) )
goto V_62;
V_275 = V_189 -> V_18 . V_275 ;
if ( V_260 )
V_275 |= V_427 ;
if ( F_33 ( V_56 , V_428 , V_275 ) )
goto V_62;
if ( V_189 -> V_18 . V_429 &&
F_54 ( V_56 , V_430 ,
sizeof( * V_189 -> V_18 . V_429 ) ,
V_189 -> V_18 . V_429 ) )
goto V_62;
if ( V_189 -> V_18 . V_54 & V_424 &&
V_189 -> V_18 . V_431 &&
F_33 ( V_56 , V_432 ,
V_189 -> V_18 . V_431 ) )
goto V_62;
( * V_261 ) ++ ;
break;
case 9 :
if ( V_189 -> V_18 . V_433 &&
( F_54 ( V_56 , V_434 ,
V_189 -> V_18 . V_435 ,
V_189 -> V_18 . V_433 ) ||
F_54 ( V_56 , V_436 ,
V_189 -> V_18 . V_435 ,
V_189 -> V_18 . V_437 ) ) )
goto V_62;
if ( V_189 -> V_18 . V_438 &&
F_54 ( V_56 , V_439 ,
sizeof( * V_189 -> V_18 . V_438 ) ,
V_189 -> V_18 . V_438 ) )
goto V_62;
* V_261 = 0 ;
break;
}
return F_67 ( V_56 , V_264 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
static int F_69 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
int V_99 = 0 , V_441 ;
int V_272 = V_37 -> args [ 0 ] ;
struct V_6 * V_189 ;
T_6 V_442 = - 1 ;
bool V_260 = false ;
struct V_4 * * V_89 ;
int V_330 ;
V_89 = F_70 ( sizeof( * V_89 ) * ( V_443 + 1 ) , V_129 ) ;
if ( ! V_89 )
return - V_130 ;
F_8 ( & V_32 ) ;
V_330 = F_19 ( V_37 -> V_39 , V_40 + V_41 . V_42 ,
V_89 , V_443 , V_45 ) ;
if ( V_330 == 0 ) {
V_260 = V_89 [ V_444 ] ;
if ( V_89 [ V_27 ] )
V_442 = F_4 ( V_89 [ V_27 ] ) ;
if ( V_89 [ V_12 ] )
V_442 = F_5 ( V_89 [ V_12 ] ) >> 32 ;
if ( V_89 [ V_10 ] ) {
struct V_26 * V_20 ;
int V_15 = F_4 ( V_89 [ V_10 ] ) ;
V_20 = F_12 ( F_20 ( V_35 -> V_47 ) , V_15 ) ;
if ( ! V_20 ) {
F_9 ( & V_32 ) ;
F_46 ( V_89 ) ;
return - V_24 ;
}
if ( V_20 -> V_29 ) {
V_189 = F_13 (
V_20 -> V_29 -> V_18 ) ;
V_442 = V_189 -> V_14 ;
}
F_14 ( V_20 ) ;
}
}
F_46 ( V_89 ) ;
F_6 (dev, &cfg80211_rdev_list, list) {
if ( ! F_71 ( F_7 ( & V_189 -> V_18 ) , F_20 ( V_35 -> V_47 ) ) )
continue;
if ( ++ V_99 <= V_272 )
continue;
if ( V_442 != - 1 && V_189 -> V_14 != V_442 )
continue;
do {
V_441 = F_60 ( V_189 , V_35 ,
F_72 ( V_37 -> V_35 ) . V_52 ,
V_37 -> V_39 -> V_445 ,
V_446 ,
V_260 , & V_37 -> args [ 1 ] ,
& V_37 -> args [ 2 ] ,
& V_37 -> args [ 3 ] ) ;
if ( V_441 < 0 ) {
if ( ( V_441 == - V_85 || V_441 == - V_440 ) &&
! V_35 -> V_50 &&
V_37 -> V_447 < 4096 ) {
V_37 -> V_447 = 4096 ;
F_9 ( & V_32 ) ;
return 1 ;
}
V_99 -- ;
break;
}
} while ( V_37 -> args [ 1 ] > 0 );
break;
}
F_9 ( & V_32 ) ;
V_37 -> args [ 0 ] = V_99 ;
return V_35 -> V_50 ;
}
static int F_73 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_34 * V_56 ;
struct V_6 * V_189 = V_31 -> V_448 [ 0 ] ;
V_56 = F_74 ( 4096 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
if ( F_60 ( V_189 , V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
false , NULL , NULL , NULL ) < 0 ) {
F_75 ( V_56 ) ;
return - V_85 ;
}
return F_76 ( V_56 , V_31 ) ;
}
static int F_77 ( struct V_4 * V_89 [] ,
struct V_451 * V_452 )
{
if ( ! V_89 [ V_453 ] || ! V_89 [ V_454 ] ||
! V_89 [ V_455 ] || ! V_89 [ V_456 ] ||
! V_89 [ V_457 ] )
return - V_16 ;
V_452 -> V_458 = F_39 ( V_89 [ V_453 ] ) ;
V_452 -> V_459 = F_78 ( V_89 [ V_454 ] ) ;
V_452 -> V_460 = F_78 ( V_89 [ V_455 ] ) ;
V_452 -> V_461 = F_78 ( V_89 [ V_456 ] ) ;
V_452 -> V_462 = F_39 ( V_89 [ V_457 ] ) ;
if ( V_452 -> V_458 >= V_463 )
return - V_16 ;
return 0 ;
}
static bool F_79 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_135 == V_136 ||
V_17 -> V_135 == V_139 ||
V_17 -> V_135 == V_464 ||
V_17 -> V_135 == V_138 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_465 * V_466 )
{
V_23 V_467 ;
if ( ! V_31 -> V_5 [ V_468 ] )
return - V_16 ;
V_467 = F_4 ( V_31 -> V_5 [ V_468 ] ) ;
V_466 -> V_58 = F_81 ( & V_7 -> V_18 , V_467 ) ;
V_466 -> V_469 = V_470 ;
V_466 -> V_471 = V_467 ;
V_466 -> V_472 = 0 ;
if ( ! V_466 -> V_58 || V_466 -> V_58 -> V_54 & V_63 )
return - V_16 ;
if ( V_31 -> V_5 [ V_473 ] ) {
enum V_474 V_475 ;
V_475 = F_4 (
V_31 -> V_5 [ V_473 ] ) ;
switch ( V_475 ) {
case V_476 :
case V_477 :
case V_478 :
case V_479 :
F_82 ( V_466 , V_466 -> V_58 ,
V_475 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_31 -> V_5 [ V_480 ] ) {
V_466 -> V_469 =
F_4 ( V_31 -> V_5 [ V_480 ] ) ;
if ( V_31 -> V_5 [ V_481 ] )
V_466 -> V_471 =
F_4 (
V_31 -> V_5 [ V_481 ] ) ;
if ( V_31 -> V_5 [ V_482 ] )
V_466 -> V_472 =
F_4 (
V_31 -> V_5 [ V_482 ] ) ;
}
if ( ! F_83 ( V_466 ) )
return - V_16 ;
if ( ! F_84 ( & V_7 -> V_18 , V_466 ,
V_63 ) )
return - V_16 ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_30 * V_31 )
{
struct V_465 V_466 ;
int V_8 ;
enum V_251 V_135 = V_464 ;
if ( V_17 )
V_135 = V_17 -> V_135 ;
if ( ! F_79 ( V_17 ) )
return - V_483 ;
V_8 = F_80 ( V_7 , V_31 , & V_466 ) ;
if ( V_8 )
return V_8 ;
F_8 ( & V_7 -> V_19 ) ;
switch ( V_135 ) {
case V_136 :
case V_138 :
if ( V_17 -> V_484 ) {
V_8 = - V_485 ;
break;
}
if ( ! F_86 ( & V_7 -> V_18 , & V_466 ) ) {
V_8 = - V_16 ;
break;
}
V_17 -> V_486 = V_466 ;
V_8 = 0 ;
break;
case V_139 :
V_8 = F_87 ( V_7 , V_17 , & V_466 ) ;
break;
case V_464 :
V_8 = F_88 ( V_7 , & V_466 ) ;
break;
default:
V_8 = - V_16 ;
}
F_9 ( & V_7 -> V_19 ) ;
return V_8 ;
}
static int F_89 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_20 = V_31 -> V_448 [ 1 ] ;
return F_85 ( V_7 , V_20 -> V_29 , V_31 ) ;
}
static int F_90 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
const T_2 * V_487 ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( F_91 ( V_189 ) )
return - V_485 ;
if ( ! V_7 -> V_326 -> V_389 )
return - V_483 ;
if ( V_17 -> V_135 != V_489 )
return - V_483 ;
V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
return F_92 ( V_7 , V_189 , V_487 ) ;
}
static int F_93 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_26 * V_20 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_490 = 0 ;
struct V_4 * V_491 ;
V_23 V_492 ;
T_2 V_281 = 0 , V_283 = 0 ;
V_23 V_285 = 0 , V_287 = 0 ;
T_2 V_289 = 0 ;
F_8 ( & V_32 ) ;
if ( V_31 -> V_5 [ V_10 ] ) {
int V_21 = F_4 ( V_31 -> V_5 [ V_10 ] ) ;
V_20 = F_12 ( F_94 ( V_31 ) , V_21 ) ;
if ( V_20 && V_20 -> V_29 ) {
V_7 = F_13 ( V_20 -> V_29 -> V_18 ) ;
F_8 ( & V_7 -> V_33 ) ;
} else
V_20 = NULL ;
}
if ( ! V_20 ) {
V_7 = F_10 ( F_94 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_7 ) ) {
F_9 ( & V_32 ) ;
return F_21 ( V_7 ) ;
}
V_17 = NULL ;
V_20 = NULL ;
V_8 = 0 ;
F_8 ( & V_7 -> V_33 ) ;
} else
V_17 = V_20 -> V_29 ;
if ( V_31 -> V_5 [ V_277 ] )
V_8 = F_95 (
V_7 , F_28 ( V_31 -> V_5 [ V_277 ] ) ) ;
F_9 ( & V_32 ) ;
if ( V_8 )
goto V_493;
if ( V_31 -> V_5 [ V_494 ] ) {
struct V_451 V_452 ;
struct V_4 * V_89 [ V_495 + 1 ] ;
if ( ! V_7 -> V_326 -> V_496 ) {
V_8 = - V_483 ;
goto V_493;
}
if ( ! V_20 ) {
V_8 = - V_16 ;
goto V_493;
}
if ( V_20 -> V_29 -> V_135 != V_136 &&
V_20 -> V_29 -> V_135 != V_138 ) {
V_8 = - V_16 ;
goto V_493;
}
if ( ! F_91 ( V_20 ) ) {
V_8 = - V_497 ;
goto V_493;
}
F_44 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
F_96 ( V_89 , V_495 ,
F_28 ( V_491 ) ,
F_29 ( V_491 ) ,
V_498 ) ;
V_8 = F_77 ( V_89 , & V_452 ) ;
if ( V_8 )
goto V_493;
V_8 = F_97 ( V_7 , V_20 ,
& V_452 ) ;
if ( V_8 )
goto V_493;
}
}
if ( V_31 -> V_5 [ V_468 ] ) {
V_8 = F_85 ( V_7 ,
F_79 ( V_17 ) ? V_17 : NULL ,
V_31 ) ;
if ( V_8 )
goto V_493;
}
if ( V_31 -> V_5 [ V_499 ] ) {
struct V_1 * V_500 = V_17 ;
enum V_501 type ;
int V_99 , V_502 = 0 ;
if ( ! ( V_7 -> V_18 . V_275 & V_503 ) )
V_500 = NULL ;
if ( ! V_7 -> V_326 -> V_504 ) {
V_8 = - V_483 ;
goto V_493;
}
V_99 = V_499 ;
type = F_4 ( V_31 -> V_5 [ V_99 ] ) ;
if ( ! V_31 -> V_5 [ V_505 ] &&
( type != V_506 ) ) {
V_8 = - V_16 ;
goto V_493;
}
if ( type != V_506 ) {
V_99 = V_505 ;
V_502 = F_4 ( V_31 -> V_5 [ V_99 ] ) ;
}
V_8 = F_98 ( V_7 , V_500 , type , V_502 ) ;
if ( V_8 )
goto V_493;
}
if ( V_31 -> V_5 [ V_331 ] &&
V_31 -> V_5 [ V_332 ] ) {
V_23 V_328 , V_329 ;
if ( ( ! V_7 -> V_18 . V_320 &&
! V_7 -> V_18 . V_322 ) ||
! V_7 -> V_326 -> V_507 ) {
V_8 = - V_483 ;
goto V_493;
}
V_328 = F_4 ( V_31 -> V_5 [ V_331 ] ) ;
V_329 = F_4 ( V_31 -> V_5 [ V_332 ] ) ;
if ( ( ~ V_328 && ( V_328 & ~ V_7 -> V_18 . V_320 ) ) ||
( ~ V_329 && ( V_329 & ~ V_7 -> V_18 . V_322 ) ) ) {
V_8 = - V_16 ;
goto V_493;
}
V_328 = V_328 & V_7 -> V_18 . V_320 ;
V_329 = V_329 & V_7 -> V_18 . V_322 ;
V_8 = F_99 ( V_7 , V_328 , V_329 ) ;
if ( V_8 )
goto V_493;
}
V_492 = 0 ;
if ( V_31 -> V_5 [ V_280 ] ) {
V_281 = F_39 (
V_31 -> V_5 [ V_280 ] ) ;
if ( V_281 == 0 ) {
V_8 = - V_16 ;
goto V_493;
}
V_492 |= V_508 ;
}
if ( V_31 -> V_5 [ V_282 ] ) {
V_283 = F_39 (
V_31 -> V_5 [ V_282 ] ) ;
if ( V_283 == 0 ) {
V_8 = - V_16 ;
goto V_493;
}
V_492 |= V_509 ;
}
if ( V_31 -> V_5 [ V_284 ] ) {
V_285 = F_4 (
V_31 -> V_5 [ V_284 ] ) ;
if ( V_285 < 256 ) {
V_8 = - V_16 ;
goto V_493;
}
if ( V_285 != ( V_23 ) - 1 ) {
V_285 &= ~ 0x1 ;
}
V_492 |= V_510 ;
}
if ( V_31 -> V_5 [ V_286 ] ) {
V_287 = F_4 (
V_31 -> V_5 [ V_286 ] ) ;
V_492 |= V_511 ;
}
if ( V_31 -> V_5 [ V_288 ] ) {
V_289 = F_39 (
V_31 -> V_5 [ V_288 ] ) ;
V_492 |= V_512 ;
}
if ( V_492 ) {
T_2 V_513 , V_514 ;
V_23 V_515 , V_516 ;
T_2 V_517 ;
if ( ! V_7 -> V_326 -> V_518 ) {
V_8 = - V_483 ;
goto V_493;
}
V_513 = V_7 -> V_18 . V_281 ;
V_514 = V_7 -> V_18 . V_283 ;
V_515 = V_7 -> V_18 . V_285 ;
V_516 = V_7 -> V_18 . V_287 ;
V_517 = V_7 -> V_18 . V_289 ;
if ( V_492 & V_508 )
V_7 -> V_18 . V_281 = V_281 ;
if ( V_492 & V_509 )
V_7 -> V_18 . V_283 = V_283 ;
if ( V_492 & V_510 )
V_7 -> V_18 . V_285 = V_285 ;
if ( V_492 & V_511 )
V_7 -> V_18 . V_287 = V_287 ;
if ( V_492 & V_512 )
V_7 -> V_18 . V_289 = V_289 ;
V_8 = F_100 ( V_7 , V_492 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_281 = V_513 ;
V_7 -> V_18 . V_283 = V_514 ;
V_7 -> V_18 . V_285 = V_515 ;
V_7 -> V_18 . V_287 = V_516 ;
V_7 -> V_18 . V_289 = V_517 ;
}
}
V_493:
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
static int F_101 ( struct V_34 * V_56 ,
struct V_465 * V_466 )
{
F_102 ( ! F_83 ( V_466 ) ) ;
if ( F_33 ( V_56 , V_468 ,
V_466 -> V_58 -> V_61 ) )
return - V_85 ;
switch ( V_466 -> V_469 ) {
case V_470 :
case V_519 :
case V_520 :
if ( F_33 ( V_56 , V_473 ,
F_103 ( V_466 ) ) )
return - V_85 ;
break;
default:
break;
}
if ( F_33 ( V_56 , V_480 , V_466 -> V_469 ) )
return - V_85 ;
if ( F_33 ( V_56 , V_481 , V_466 -> V_471 ) )
return - V_85 ;
if ( V_466 -> V_472 &&
F_33 ( V_56 , V_482 , V_466 -> V_472 ) )
return - V_85 ;
return 0 ;
}
static int F_104 ( struct V_34 * V_56 , V_23 V_52 , V_23 V_53 , int V_54 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_26 * V_189 = V_17 -> V_20 ;
void * V_264 ;
V_264 = F_30 ( V_56 , V_52 , V_53 , V_54 , V_521 ) ;
if ( ! V_264 )
return - 1 ;
if ( V_189 &&
( F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_61 ( V_56 , V_522 , V_189 -> V_523 ) ) )
goto V_62;
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_524 , V_17 -> V_135 ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) ||
F_54 ( V_56 , V_488 , V_525 , F_106 ( V_17 ) ) ||
F_33 ( V_56 , V_278 ,
V_7 -> V_526 ^
( V_279 << 2 ) ) )
goto V_62;
if ( V_7 -> V_326 -> V_527 ) {
int V_441 ;
struct V_465 V_466 ;
V_441 = F_107 ( V_7 , V_17 , & V_466 ) ;
if ( V_441 == 0 ) {
if ( F_101 ( V_56 , & V_466 ) )
goto V_62;
}
}
if ( V_17 -> V_528 ) {
if ( F_54 ( V_56 , V_529 , V_17 -> V_528 , V_17 -> V_530 ) )
goto V_62;
}
return F_67 ( V_56 , V_264 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
static int F_108 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
int V_531 = 0 ;
int V_532 = 0 ;
int V_533 = V_37 -> args [ 0 ] ;
int V_534 = V_37 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_8 ( & V_32 ) ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , F_20 ( V_35 -> V_47 ) ) )
continue;
if ( V_531 < V_533 ) {
V_531 ++ ;
continue;
}
V_532 = 0 ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_532 < V_534 ) {
V_532 ++ ;
continue;
}
if ( F_104 ( V_35 , F_72 ( V_37 -> V_35 ) . V_52 ,
V_37 -> V_39 -> V_445 , V_446 ,
V_7 , V_17 ) < 0 ) {
F_9 ( & V_7 -> V_19 ) ;
goto V_535;
}
V_532 ++ ;
}
F_9 ( & V_7 -> V_19 ) ;
V_531 ++ ;
}
V_535:
F_9 ( & V_32 ) ;
V_37 -> args [ 0 ] = V_531 ;
V_37 -> args [ 1 ] = V_532 ;
return V_35 -> V_50 ;
}
static int F_109 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_34 * V_56 ;
struct V_6 * V_189 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
if ( F_104 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_189 , V_17 ) < 0 ) {
F_75 ( V_56 ) ;
return - V_85 ;
}
return F_76 ( V_56 , V_31 ) ;
}
static int F_110 ( struct V_4 * V_537 , V_23 * V_538 )
{
struct V_4 * V_54 [ V_539 + 1 ] ;
int V_540 ;
* V_538 = 0 ;
if ( ! V_537 )
return - V_16 ;
if ( F_38 ( V_54 , V_539 ,
V_537 , V_541 ) )
return - V_16 ;
for ( V_540 = 1 ; V_540 <= V_539 ; V_540 ++ )
if ( V_54 [ V_540 ] )
* V_538 |= ( 1 << V_540 ) ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_2 V_542 ,
enum V_251 V_135 )
{
if ( ! V_542 ) {
if ( V_20 && ( V_20 -> V_543 & V_544 ) )
return - V_485 ;
return 0 ;
}
switch ( V_135 ) {
case V_137 :
if ( V_7 -> V_18 . V_54 & V_545 )
return 0 ;
break;
case V_143 :
if ( V_7 -> V_18 . V_54 & V_546 )
return 0 ;
break;
default:
break;
}
return - V_483 ;
}
static int F_112 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_547 V_131 ;
int V_38 ;
enum V_251 V_548 , V_549 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
V_23 V_550 , * V_54 = NULL ;
bool V_551 = false ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_548 = V_549 = V_189 -> V_29 -> V_135 ;
if ( V_31 -> V_5 [ V_524 ] ) {
V_549 = F_4 ( V_31 -> V_5 [ V_524 ] ) ;
if ( V_548 != V_549 )
V_551 = true ;
if ( V_549 > V_552 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_553 ] ) {
struct V_1 * V_17 = V_189 -> V_29 ;
if ( V_549 != V_139 )
return - V_16 ;
if ( F_91 ( V_189 ) )
return - V_485 ;
F_113 ( V_17 ) ;
F_114 ( V_554 !=
V_555 ) ;
V_17 -> V_556 =
F_29 ( V_31 -> V_5 [ V_553 ] ) ;
memcpy ( V_17 -> V_530 , F_28 ( V_31 -> V_5 [ V_553 ] ) ,
V_17 -> V_556 ) ;
F_115 ( V_17 ) ;
}
if ( V_31 -> V_5 [ V_557 ] ) {
V_131 . V_542 = ! ! F_39 ( V_31 -> V_5 [ V_557 ] ) ;
V_551 = true ;
V_38 = F_111 ( V_7 , V_189 , V_131 . V_542 , V_549 ) ;
if ( V_38 )
return V_38 ;
} else {
V_131 . V_542 = - 1 ;
}
if ( V_31 -> V_5 [ V_558 ] ) {
if ( V_549 != V_464 )
return - V_16 ;
V_38 = F_110 ( V_31 -> V_5 [ V_558 ] ,
& V_550 ) ;
if ( V_38 )
return V_38 ;
V_54 = & V_550 ;
V_551 = true ;
}
if ( V_551 )
V_38 = F_116 ( V_7 , V_189 , V_549 , V_54 , & V_131 ) ;
else
V_38 = 0 ;
if ( ! V_38 && V_131 . V_542 != - 1 )
V_189 -> V_29 -> V_542 = V_131 . V_542 ;
return V_38 ;
}
static int F_117 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_547 V_131 ;
struct V_1 * V_17 ;
struct V_34 * V_56 ;
int V_38 ;
enum V_251 type = V_559 ;
V_23 V_54 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
if ( ! V_31 -> V_5 [ V_522 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_524 ] ) {
type = F_4 ( V_31 -> V_5 [ V_524 ] ) ;
if ( type > V_552 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_342 ||
! ( V_7 -> V_18 . V_334 & ( 1 << type ) ) )
return - V_483 ;
if ( type == V_560 && V_31 -> V_5 [ V_488 ] ) {
F_118 ( V_131 . V_561 , V_31 -> V_5 [ V_488 ] ,
V_525 ) ;
if ( ! F_119 ( V_131 . V_561 ) )
return - V_562 ;
}
if ( V_31 -> V_5 [ V_557 ] ) {
V_131 . V_542 = ! ! F_39 ( V_31 -> V_5 [ V_557 ] ) ;
V_38 = F_111 ( V_7 , NULL , V_131 . V_542 , type ) ;
if ( V_38 )
return V_38 ;
}
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_38 = F_110 ( type == V_464 ?
V_31 -> V_5 [ V_558 ] : NULL ,
& V_54 ) ;
V_17 = F_120 ( V_7 ,
F_28 ( V_31 -> V_5 [ V_522 ] ) ,
type , V_38 ? NULL : & V_54 , & V_131 ) ;
if ( F_16 ( V_17 ) ) {
F_75 ( V_56 ) ;
return F_21 ( V_17 ) ;
}
switch ( type ) {
case V_139 :
if ( ! V_31 -> V_5 [ V_553 ] )
break;
F_113 ( V_17 ) ;
F_114 ( V_554 !=
V_555 ) ;
V_17 -> V_556 =
F_29 ( V_31 -> V_5 [ V_553 ] ) ;
memcpy ( V_17 -> V_530 , F_28 ( V_31 -> V_5 [ V_553 ] ) ,
V_17 -> V_556 ) ;
F_115 ( V_17 ) ;
break;
case V_560 :
F_121 ( & V_17 -> V_33 ) ;
F_122 ( & V_17 -> V_563 ) ;
F_123 ( & V_17 -> V_564 ) ;
F_122 ( & V_17 -> V_565 ) ;
F_123 ( & V_17 -> V_566 ) ;
F_8 ( & V_7 -> V_19 ) ;
V_17 -> V_22 = ++ V_7 -> V_13 ;
F_124 ( & V_17 -> V_567 , & V_7 -> V_568 ) ;
V_7 -> V_526 ++ ;
F_9 ( & V_7 -> V_19 ) ;
break;
default:
break;
}
if ( F_104 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_7 , V_17 ) < 0 ) {
F_75 ( V_56 ) ;
return - V_85 ;
}
return F_76 ( V_56 , V_31 ) ;
}
static int F_125 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_569 )
return - V_483 ;
if ( ! V_17 -> V_20 )
V_31 -> V_448 [ 1 ] = NULL ;
return F_126 ( V_7 , V_17 ) ;
}
static int F_127 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_3 V_570 ;
if ( ! V_31 -> V_5 [ V_571 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_400 )
return - V_483 ;
V_570 = F_78 ( V_31 -> V_5 [ V_571 ] ) ;
return F_128 ( V_7 , V_189 , V_570 ) ;
}
static void F_129 ( void * V_155 , struct V_572 * V_131 )
{
struct V_4 * V_86 ;
struct V_573 * V_574 = V_155 ;
if ( ( V_131 -> V_86 &&
F_54 ( V_574 -> V_56 , V_115 ,
V_131 -> V_102 , V_131 -> V_86 ) ) ||
( V_131 -> V_53 &&
F_54 ( V_574 -> V_56 , V_116 ,
V_131 -> V_104 , V_131 -> V_53 ) ) ||
( V_131 -> V_106 &&
F_33 ( V_574 -> V_56 , V_118 ,
V_131 -> V_106 ) ) )
goto V_62;
V_86 = F_50 ( V_574 -> V_56 , V_123 ) ;
if ( ! V_86 )
goto V_62;
if ( ( V_131 -> V_86 &&
F_54 ( V_574 -> V_56 , V_100 ,
V_131 -> V_102 , V_131 -> V_86 ) ) ||
( V_131 -> V_53 &&
F_54 ( V_574 -> V_56 , V_103 ,
V_131 -> V_104 , V_131 -> V_53 ) ) ||
( V_131 -> V_106 &&
F_33 ( V_574 -> V_56 , V_105 ,
V_131 -> V_106 ) ) )
goto V_62;
if ( F_58 ( V_574 -> V_56 , V_117 , V_574 -> V_99 ) )
goto V_62;
F_51 ( V_574 -> V_56 , V_86 ) ;
return;
V_62:
V_574 -> error = 1 ;
}
static int F_130 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int V_38 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 V_575 = 0 ;
const T_2 * V_576 = NULL ;
bool V_577 ;
struct V_573 V_574 = {
. error = 0 ,
} ;
void * V_264 ;
struct V_34 * V_56 ;
if ( V_31 -> V_5 [ V_117 ] )
V_575 = F_39 ( V_31 -> V_5 [ V_117 ] ) ;
if ( V_575 > 5 )
return - V_16 ;
if ( V_31 -> V_5 [ V_488 ] )
V_576 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_577 = ! ! V_576 ;
if ( V_31 -> V_5 [ V_121 ] ) {
V_23 V_578 = F_4 ( V_31 -> V_5 [ V_121 ] ) ;
if ( V_578 >= V_108 )
return - V_16 ;
if ( V_578 != V_579 &&
V_578 != V_580 )
return - V_16 ;
V_577 = V_578 == V_580 ;
}
if ( ! V_7 -> V_326 -> V_581 )
return - V_483 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_582 ) ;
if ( F_16 ( V_264 ) )
return F_21 ( V_264 ) ;
V_574 . V_56 = V_56 ;
V_574 . V_99 = V_575 ;
if ( F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_58 ( V_56 , V_117 , V_575 ) )
goto V_62;
if ( V_576 &&
F_54 ( V_56 , V_488 , V_525 , V_576 ) )
goto V_62;
if ( V_577 && V_576 &&
! ( V_7 -> V_18 . V_54 & V_300 ) )
return - V_583 ;
V_38 = F_131 ( V_7 , V_189 , V_575 , V_577 , V_576 , & V_574 ,
F_129 ) ;
if ( V_38 )
goto V_584;
if ( V_574 . error )
goto V_62;
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
V_62:
V_38 = - V_85 ;
V_584:
F_75 ( V_56 ) ;
return V_38 ;
}
static int F_132 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_87 V_86 ;
int V_38 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
V_38 = F_41 ( V_31 , & V_86 ) ;
if ( V_38 )
return V_38 ;
if ( V_86 . V_99 < 0 )
return - V_16 ;
if ( ! V_86 . V_92 && ! V_86 . V_94 )
return - V_16 ;
F_113 ( V_189 -> V_29 ) ;
if ( V_86 . V_92 ) {
if ( ! V_7 -> V_326 -> V_585 ) {
V_38 = - V_483 ;
goto V_535;
}
V_38 = F_47 ( V_189 -> V_29 ) ;
if ( V_38 )
goto V_535;
V_38 = F_133 ( V_7 , V_189 , V_86 . V_99 ,
V_86 . V_96 , V_86 . V_97 ) ;
if ( V_38 )
goto V_535;
#ifdef F_134
V_189 -> V_29 -> V_586 . V_587 = V_86 . V_99 ;
#endif
} else {
if ( V_86 . V_96 || ! V_86 . V_97 ) {
V_38 = - V_16 ;
goto V_535;
}
if ( ! V_7 -> V_326 -> V_588 ) {
V_38 = - V_483 ;
goto V_535;
}
V_38 = F_47 ( V_189 -> V_29 ) ;
if ( V_38 )
goto V_535;
V_38 = F_135 ( V_7 , V_189 , V_86 . V_99 ) ;
if ( V_38 )
goto V_535;
#ifdef F_134
V_189 -> V_29 -> V_586 . V_589 = V_86 . V_99 ;
#endif
}
V_535:
F_115 ( V_189 -> V_29 ) ;
return V_38 ;
}
static int F_136 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int V_38 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_87 V_86 ;
const T_2 * V_576 = NULL ;
V_38 = F_41 ( V_31 , & V_86 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_86 . V_101 . V_86 )
return - V_16 ;
if ( V_31 -> V_5 [ V_488 ] )
V_576 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( V_86 . type == - 1 ) {
if ( V_576 )
V_86 . type = V_580 ;
else
V_86 . type = V_579 ;
}
if ( V_86 . type != V_580 &&
V_86 . type != V_579 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_346 )
return - V_483 ;
if ( F_45 ( V_7 , & V_86 . V_101 , V_86 . V_99 ,
V_86 . type == V_580 ,
V_576 ) )
return - V_16 ;
F_113 ( V_189 -> V_29 ) ;
V_38 = F_47 ( V_189 -> V_29 ) ;
if ( ! V_38 )
V_38 = F_137 ( V_7 , V_189 , V_86 . V_99 ,
V_86 . type == V_580 ,
V_576 , & V_86 . V_101 ) ;
F_115 ( V_189 -> V_29 ) ;
return V_38 ;
}
static int F_138 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int V_38 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 * V_576 = NULL ;
struct V_87 V_86 ;
V_38 = F_41 ( V_31 , & V_86 ) ;
if ( V_38 )
return V_38 ;
if ( V_31 -> V_5 [ V_488 ] )
V_576 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( V_86 . type == - 1 ) {
if ( V_576 )
V_86 . type = V_580 ;
else
V_86 . type = V_579 ;
}
if ( V_86 . type != V_580 &&
V_86 . type != V_579 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_590 )
return - V_483 ;
F_113 ( V_189 -> V_29 ) ;
V_38 = F_47 ( V_189 -> V_29 ) ;
if ( V_86 . type == V_580 && V_576 &&
! ( V_7 -> V_18 . V_54 & V_300 ) )
V_38 = - V_583 ;
if ( ! V_38 )
V_38 = F_139 ( V_7 , V_189 , V_86 . V_99 ,
V_86 . type == V_580 ,
V_576 ) ;
#ifdef F_134
if ( ! V_38 ) {
if ( V_86 . V_99 == V_189 -> V_29 -> V_586 . V_587 )
V_189 -> V_29 -> V_586 . V_587 = - 1 ;
else if ( V_86 . V_99 == V_189 -> V_29 -> V_586 . V_589 )
V_189 -> V_29 -> V_586 . V_589 = - 1 ;
}
#endif
F_115 ( V_189 -> V_29 ) ;
return V_38 ;
}
static int F_140 ( struct V_4 * V_591 )
{
struct V_4 * V_48 ;
int V_592 = 0 , V_25 ;
F_44 (attr, nl_attr, tmp) {
if ( F_29 ( V_48 ) != V_525 )
return - V_16 ;
V_592 ++ ;
}
return V_592 ;
}
static struct V_593 * F_141 ( struct V_18 * V_18 ,
struct V_30 * V_31 )
{
enum V_594 V_595 ;
struct V_4 * V_48 ;
struct V_593 * V_596 ;
int V_149 = 0 , V_592 , V_25 ;
if ( ! V_18 -> V_431 )
return F_3 ( - V_483 ) ;
if ( ! V_31 -> V_5 [ V_597 ] )
return F_3 ( - V_16 ) ;
V_595 = F_4 ( V_31 -> V_5 [ V_597 ] ) ;
if ( V_595 != V_598 &&
V_595 != V_599 )
return F_3 ( - V_16 ) ;
if ( ! V_31 -> V_5 [ V_600 ] )
return F_3 ( - V_16 ) ;
V_592 = F_140 ( V_31 -> V_5 [ V_600 ] ) ;
if ( V_592 < 0 )
return F_3 ( V_592 ) ;
if ( V_592 > V_18 -> V_431 )
return F_3 ( - V_601 ) ;
V_596 = F_43 ( sizeof( * V_596 ) + ( sizeof( struct V_602 ) * V_592 ) ,
V_129 ) ;
if ( ! V_596 )
return F_3 ( - V_130 ) ;
F_44 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_596 -> V_603 [ V_149 ] . V_604 , F_28 ( V_48 ) , V_525 ) ;
V_149 ++ ;
}
V_596 -> V_605 = V_592 ;
V_596 -> V_595 = V_595 ;
return V_596 ;
}
static int F_142 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_593 * V_596 ;
int V_38 ;
if ( V_189 -> V_29 -> V_135 != V_136 &&
V_189 -> V_29 -> V_135 != V_138 )
return - V_483 ;
if ( ! V_189 -> V_29 -> V_484 )
return - V_16 ;
V_596 = F_141 ( & V_7 -> V_18 , V_31 ) ;
if ( F_16 ( V_596 ) )
return F_21 ( V_596 ) ;
V_38 = F_143 ( V_7 , V_189 , V_596 ) ;
F_46 ( V_596 ) ;
return V_38 ;
}
static int F_144 ( struct V_30 * V_31 ,
struct V_606 * V_607 )
{
bool V_608 = false ;
if ( ! F_27 ( V_31 -> V_5 [ V_609 ] ) ||
! F_27 ( V_31 -> V_5 [ V_610 ] ) ||
! F_27 ( V_31 -> V_5 [ V_611 ] ) ||
! F_27 ( V_31 -> V_5 [ V_612 ] ) )
return - V_16 ;
memset ( V_607 , 0 , sizeof( * V_607 ) ) ;
if ( V_31 -> V_5 [ V_613 ] ) {
V_607 -> V_614 = F_28 ( V_31 -> V_5 [ V_613 ] ) ;
V_607 -> V_615 = F_29 ( V_31 -> V_5 [ V_613 ] ) ;
if ( ! V_607 -> V_615 )
return - V_16 ;
V_608 = true ;
}
if ( V_31 -> V_5 [ V_609 ] ) {
V_607 -> V_616 = F_28 ( V_31 -> V_5 [ V_609 ] ) ;
V_607 -> V_617 =
F_29 ( V_31 -> V_5 [ V_609 ] ) ;
V_608 = true ;
}
if ( ! V_608 )
return - V_16 ;
if ( V_31 -> V_5 [ V_610 ] ) {
V_607 -> V_618 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_607 -> V_619 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
}
if ( V_31 -> V_5 [ V_611 ] ) {
V_607 -> V_620 =
F_28 ( V_31 -> V_5 [ V_611 ] ) ;
V_607 -> V_621 =
F_29 ( V_31 -> V_5 [ V_611 ] ) ;
}
if ( V_31 -> V_5 [ V_612 ] ) {
V_607 -> V_622 =
F_28 ( V_31 -> V_5 [ V_612 ] ) ;
V_607 -> V_623 =
F_29 ( V_31 -> V_5 [ V_612 ] ) ;
}
if ( V_31 -> V_5 [ V_624 ] ) {
V_607 -> V_625 =
F_28 ( V_31 -> V_5 [ V_624 ] ) ;
V_607 -> V_626 =
F_29 ( V_31 -> V_5 [ V_624 ] ) ;
}
return 0 ;
}
static bool F_145 ( struct V_6 * V_7 ,
struct V_627 * V_131 )
{
struct V_1 * V_17 ;
bool V_441 = false ;
F_8 ( & V_7 -> V_19 ) ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_135 != V_136 &&
V_17 -> V_135 != V_138 )
continue;
if ( ! V_17 -> V_486 . V_58 )
continue;
V_131 -> V_466 = V_17 -> V_486 ;
V_441 = true ;
break;
}
F_9 ( & V_7 -> V_19 ) ;
return V_441 ;
}
static bool F_146 ( struct V_6 * V_7 ,
enum V_628 V_629 ,
enum V_630 V_55 )
{
if ( V_629 > V_631 )
return false ;
switch ( V_55 ) {
case V_632 :
if ( ! ( V_7 -> V_18 . V_275 & V_633 ) &&
V_629 == V_634 )
return false ;
return true ;
case V_415 :
case V_635 :
if ( V_629 == V_634 )
return false ;
return true ;
default:
return false ;
}
}
static int F_147 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_627 V_131 ;
int V_38 ;
T_2 V_636 = 0 ;
if ( V_189 -> V_29 -> V_135 != V_136 &&
V_189 -> V_29 -> V_135 != V_138 )
return - V_483 ;
if ( ! V_7 -> V_326 -> V_348 )
return - V_483 ;
if ( V_17 -> V_484 )
return - V_637 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
if ( ! V_31 -> V_5 [ V_638 ] ||
! V_31 -> V_5 [ V_639 ] ||
! V_31 -> V_5 [ V_613 ] )
return - V_16 ;
V_38 = F_144 ( V_31 , & V_131 . V_640 ) ;
if ( V_38 )
return V_38 ;
V_131 . V_484 =
F_4 ( V_31 -> V_5 [ V_638 ] ) ;
V_131 . V_641 =
F_4 ( V_31 -> V_5 [ V_639 ] ) ;
V_38 = F_148 ( V_7 , V_131 . V_484 ) ;
if ( V_38 )
return V_38 ;
if ( V_31 -> V_5 [ V_529 ] ) {
V_131 . V_530 = F_28 ( V_31 -> V_5 [ V_529 ] ) ;
V_131 . V_528 =
F_29 ( V_31 -> V_5 [ V_529 ] ) ;
if ( V_131 . V_528 == 0 ||
V_131 . V_528 > V_554 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_642 ] ) {
V_131 . V_643 = F_4 (
V_31 -> V_5 [ V_642 ] ) ;
if ( V_131 . V_643 != V_644 &&
V_131 . V_643 != V_645 &&
V_131 . V_643 != V_646 )
return - V_16 ;
}
V_131 . V_647 = ! ! V_31 -> V_5 [ V_648 ] ;
if ( V_31 -> V_5 [ V_649 ] ) {
V_131 . V_629 = F_4 (
V_31 -> V_5 [ V_649 ] ) ;
if ( ! F_146 ( V_7 , V_131 . V_629 ,
V_635 ) )
return - V_16 ;
} else
V_131 . V_629 = V_650 ;
V_38 = F_149 ( V_7 , V_31 , & V_131 . V_651 ,
V_652 ) ;
if ( V_38 )
return V_38 ;
if ( V_31 -> V_5 [ V_653 ] ) {
if ( ! ( V_7 -> V_18 . V_275 & V_654 ) )
return - V_483 ;
V_131 . V_655 = F_78 (
V_31 -> V_5 [ V_653 ] ) ;
}
if ( V_31 -> V_5 [ V_656 ] ) {
if ( V_189 -> V_29 -> V_135 != V_138 )
return - V_16 ;
V_131 . V_657 =
F_39 ( V_31 -> V_5 [ V_656 ] ) ;
if ( V_131 . V_657 > 127 )
return - V_16 ;
if ( V_131 . V_657 != 0 &&
! ( V_7 -> V_18 . V_275 & V_658 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_659 ] ) {
T_2 V_25 ;
if ( V_189 -> V_29 -> V_135 != V_138 )
return - V_16 ;
V_25 = F_39 ( V_31 -> V_5 [ V_659 ] ) ;
if ( V_25 > 1 )
return - V_16 ;
V_131 . V_660 = V_25 ;
if ( V_131 . V_660 != 0 &&
! ( V_7 -> V_18 . V_275 & V_661 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_468 ] ) {
V_38 = F_80 ( V_7 , V_31 , & V_131 . V_466 ) ;
if ( V_38 )
return V_38 ;
} else if ( V_17 -> V_486 . V_58 ) {
V_131 . V_466 = V_17 -> V_486 ;
} else if ( ! F_145 ( V_7 , & V_131 ) )
return - V_16 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_131 . V_466 ) )
return - V_16 ;
V_38 = F_150 ( V_17 -> V_18 , & V_131 . V_466 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 ) {
V_636 = F_151 ( V_131 . V_466 . V_469 ) ;
V_131 . V_662 = true ;
}
F_8 ( & V_7 -> V_19 ) ;
V_38 = F_152 ( V_7 , V_17 , V_17 -> V_135 ,
V_131 . V_466 . V_58 ,
V_663 ,
V_636 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_38 )
return V_38 ;
if ( V_31 -> V_5 [ V_597 ] ) {
V_131 . V_596 = F_141 ( & V_7 -> V_18 , V_31 ) ;
if ( F_16 ( V_131 . V_596 ) )
return F_21 ( V_131 . V_596 ) ;
}
V_38 = F_153 ( V_7 , V_189 , & V_131 ) ;
if ( ! V_38 ) {
V_17 -> V_486 = V_131 . V_466 ;
V_17 -> V_484 = V_131 . V_484 ;
V_17 -> V_664 = V_131 . V_466 . V_58 ;
V_17 -> V_528 = V_131 . V_528 ;
memcpy ( V_17 -> V_530 , V_131 . V_530 , V_17 -> V_528 ) ;
}
F_46 ( V_131 . V_596 ) ;
return V_38 ;
}
static int F_154 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_606 V_131 ;
int V_38 ;
if ( V_189 -> V_29 -> V_135 != V_136 &&
V_189 -> V_29 -> V_135 != V_138 )
return - V_483 ;
if ( ! V_7 -> V_326 -> V_665 )
return - V_483 ;
if ( ! V_17 -> V_484 )
return - V_16 ;
V_38 = F_144 ( V_31 , & V_131 ) ;
if ( V_38 )
return V_38 ;
return F_155 ( V_7 , V_189 , & V_131 ) ;
}
static int F_156 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
return F_157 ( V_7 , V_189 ) ;
}
static int F_158 ( struct V_30 * V_31 ,
enum V_251 V_135 ,
struct V_666 * V_131 )
{
struct V_4 * V_54 [ V_667 + 1 ] ;
struct V_4 * V_537 ;
int V_540 ;
V_537 = V_31 -> V_5 [ V_668 ] ;
if ( V_537 ) {
struct V_669 * V_670 ;
V_670 = F_28 ( V_537 ) ;
V_131 -> V_671 = V_670 -> V_672 ;
V_131 -> V_673 = V_670 -> V_674 ;
V_131 -> V_673 &= V_131 -> V_671 ;
if ( ( V_131 -> V_671 |
V_131 -> V_673 ) & F_151 ( V_675 ) )
return - V_16 ;
return 0 ;
}
V_537 = V_31 -> V_5 [ V_676 ] ;
if ( ! V_537 )
return 0 ;
if ( F_38 ( V_54 , V_667 ,
V_537 , V_677 ) )
return - V_16 ;
switch ( V_135 ) {
case V_136 :
case V_137 :
case V_138 :
V_131 -> V_671 = F_151 ( V_678 ) |
F_151 ( V_679 ) |
F_151 ( V_680 ) |
F_151 ( V_681 ) ;
break;
case V_144 :
case V_143 :
V_131 -> V_671 = F_151 ( V_678 ) |
F_151 ( V_682 ) ;
break;
case V_139 :
V_131 -> V_671 = F_151 ( V_683 ) |
F_151 ( V_681 ) |
F_151 ( V_678 ) ;
default:
return - V_16 ;
}
for ( V_540 = 1 ; V_540 <= V_667 ; V_540 ++ ) {
if ( V_54 [ V_540 ] ) {
V_131 -> V_673 |= ( 1 << V_540 ) ;
if ( V_540 > V_684 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_159 ( struct V_34 * V_56 , struct V_685 * V_31 ,
int V_48 )
{
struct V_4 * V_223 ;
V_23 V_243 ;
T_3 V_686 ;
V_223 = F_50 ( V_56 , V_48 ) ;
if ( ! V_223 )
return false ;
V_243 = F_160 ( V_31 ) ;
V_686 = V_243 < ( 1UL << 16 ) ? V_243 : 0 ;
if ( V_243 > 0 &&
F_33 ( V_56 , V_687 , V_243 ) )
return false ;
if ( V_686 > 0 &&
F_57 ( V_56 , V_688 , V_686 ) )
return false ;
if ( V_31 -> V_54 & V_689 ) {
if ( F_58 ( V_56 , V_690 , V_31 -> V_227 ) )
return false ;
if ( V_31 -> V_54 & V_691 &&
F_34 ( V_56 , V_692 ) )
return false ;
if ( V_31 -> V_54 & V_693 &&
F_34 ( V_56 , V_694 ) )
return false ;
} else if ( V_31 -> V_54 & V_695 ) {
if ( F_58 ( V_56 , V_696 , V_31 -> V_227 ) )
return false ;
if ( F_58 ( V_56 , V_697 , V_31 -> V_698 ) )
return false ;
if ( V_31 -> V_54 & V_691 &&
F_34 ( V_56 , V_692 ) )
return false ;
if ( V_31 -> V_54 & V_699 &&
F_34 ( V_56 , V_700 ) )
return false ;
if ( V_31 -> V_54 & V_701 &&
F_34 ( V_56 , V_702 ) )
return false ;
if ( V_31 -> V_54 & V_703 &&
F_34 ( V_56 , V_704 ) )
return false ;
if ( V_31 -> V_54 & V_693 &&
F_34 ( V_56 , V_694 ) )
return false ;
}
F_51 ( V_56 , V_223 ) ;
return true ;
}
static int F_161 ( struct V_34 * V_56 , V_23 V_52 , V_23 V_53 ,
int V_54 ,
struct V_6 * V_7 ,
struct V_26 * V_189 ,
const T_2 * V_576 , struct V_705 * V_706 )
{
void * V_264 ;
struct V_4 * V_707 , * V_708 ;
V_264 = F_30 ( V_56 , V_52 , V_53 , V_54 , V_709 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_576 ) ||
F_33 ( V_56 , V_278 , V_706 -> V_710 ) )
goto V_62;
V_707 = F_50 ( V_56 , V_711 ) ;
if ( ! V_707 )
goto V_62;
if ( ( V_706 -> V_712 & V_713 ) &&
F_33 ( V_56 , V_714 ,
V_706 -> V_715 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_716 ) &&
F_33 ( V_56 , V_717 ,
V_706 -> V_718 ) )
goto V_62;
if ( ( V_706 -> V_712 & ( V_719 |
V_720 ) ) &&
F_33 ( V_56 , V_721 ,
( V_23 ) V_706 -> V_722 ) )
goto V_62;
if ( ( V_706 -> V_712 & ( V_723 |
V_724 ) ) &&
F_33 ( V_56 , V_725 ,
( V_23 ) V_706 -> V_726 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_720 ) &&
F_105 ( V_56 , V_727 ,
V_706 -> V_722 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_724 ) &&
F_105 ( V_56 , V_728 ,
V_706 -> V_726 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_729 ) &&
F_57 ( V_56 , V_730 , V_706 -> V_731 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_732 ) &&
F_57 ( V_56 , V_733 , V_706 -> V_734 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_735 ) &&
F_58 ( V_56 , V_736 ,
V_706 -> V_737 ) )
goto V_62;
switch ( V_7 -> V_18 . V_738 ) {
case V_739 :
if ( ( V_706 -> V_712 & V_740 ) &&
F_58 ( V_56 , V_741 ,
V_706 -> signal ) )
goto V_62;
if ( ( V_706 -> V_712 & V_742 ) &&
F_58 ( V_56 , V_743 ,
V_706 -> V_744 ) )
goto V_62;
break;
default:
break;
}
if ( V_706 -> V_712 & V_745 ) {
if ( ! F_159 ( V_56 , & V_706 -> V_746 ,
V_747 ) )
goto V_62;
}
if ( V_706 -> V_712 & V_748 ) {
if ( ! F_159 ( V_56 , & V_706 -> V_749 ,
V_750 ) )
goto V_62;
}
if ( ( V_706 -> V_712 & V_751 ) &&
F_33 ( V_56 , V_752 ,
V_706 -> V_753 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_754 ) &&
F_33 ( V_56 , V_755 ,
V_706 -> V_756 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_757 ) &&
F_33 ( V_56 , V_758 ,
V_706 -> V_759 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_760 ) &&
F_33 ( V_56 , V_761 ,
V_706 -> V_762 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_763 ) &&
F_33 ( V_56 , V_764 ,
V_706 -> V_765 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_766 ) &&
F_33 ( V_56 , V_767 ,
V_706 -> V_768 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_769 ) &&
F_33 ( V_56 , V_770 ,
V_706 -> V_771 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_772 ) &&
F_33 ( V_56 , V_773 ,
V_706 -> V_774 ) )
goto V_62;
if ( V_706 -> V_712 & V_775 ) {
V_708 = F_50 ( V_56 , V_776 ) ;
if ( ! V_708 )
goto V_62;
if ( ( ( V_706 -> V_708 . V_54 & V_777 ) &&
F_34 ( V_56 , V_778 ) ) ||
( ( V_706 -> V_708 . V_54 & V_779 ) &&
F_34 ( V_56 , V_780 ) ) ||
( ( V_706 -> V_708 . V_54 & V_781 ) &&
F_34 ( V_56 , V_782 ) ) ||
F_58 ( V_56 , V_783 ,
V_706 -> V_708 . V_641 ) ||
F_57 ( V_56 , V_784 ,
V_706 -> V_708 . V_484 ) )
goto V_62;
F_51 ( V_56 , V_708 ) ;
}
if ( ( V_706 -> V_712 & V_785 ) &&
F_54 ( V_56 , V_786 ,
sizeof( struct V_669 ) ,
& V_706 -> V_670 ) )
goto V_62;
if ( ( V_706 -> V_712 & V_787 ) &&
F_105 ( V_56 , V_788 ,
V_706 -> V_789 ) )
goto V_62;
F_51 ( V_56 , V_707 ) ;
if ( ( V_706 -> V_712 & V_790 ) &&
F_54 ( V_56 , V_610 , V_706 -> V_791 ,
V_706 -> V_792 ) )
goto V_62;
return F_67 ( V_56 , V_264 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
static int F_162 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_705 V_706 ;
struct V_6 * V_189 ;
struct V_1 * V_17 ;
T_2 V_576 [ V_525 ] ;
int V_793 = V_37 -> args [ 2 ] ;
int V_38 ;
V_38 = F_17 ( V_35 , V_37 , & V_189 , & V_17 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_17 -> V_20 ) {
V_38 = - V_16 ;
goto V_794;
}
if ( ! V_189 -> V_326 -> V_795 ) {
V_38 = - V_483 ;
goto V_794;
}
while ( 1 ) {
memset ( & V_706 , 0 , sizeof( V_706 ) ) ;
V_38 = F_163 ( V_189 , V_17 -> V_20 , V_793 ,
V_576 , & V_706 ) ;
if ( V_38 == - V_583 )
break;
if ( V_38 )
goto V_794;
if ( F_161 ( V_35 ,
F_72 ( V_37 -> V_35 ) . V_52 ,
V_37 -> V_39 -> V_445 , V_446 ,
V_189 , V_17 -> V_20 , V_576 ,
& V_706 ) < 0 )
goto V_535;
V_793 ++ ;
}
V_535:
V_37 -> args [ 2 ] = V_793 ;
V_38 = V_35 -> V_50 ;
V_794:
F_25 ( V_189 ) ;
return V_38 ;
}
static int F_164 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_705 V_706 ;
struct V_34 * V_56 ;
T_2 * V_576 = NULL ;
int V_38 ;
memset ( & V_706 , 0 , sizeof( V_706 ) ) ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
V_576 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( ! V_7 -> V_326 -> V_796 )
return - V_483 ;
V_38 = F_165 ( V_7 , V_189 , V_576 , & V_706 ) ;
if ( V_38 )
return V_38 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
if ( F_161 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_7 , V_189 , V_576 , & V_706 ) < 0 ) {
F_75 ( V_56 ) ;
return - V_85 ;
}
return F_76 ( V_56 , V_31 ) ;
}
int F_166 ( struct V_18 * V_18 ,
struct V_666 * V_131 ,
enum V_797 V_798 )
{
if ( V_131 -> V_799 != - 1 )
return - V_16 ;
if ( V_131 -> V_800 )
return - V_16 ;
F_114 ( V_667 != 7 ) ;
switch ( V_798 ) {
case V_801 :
case V_802 :
if ( V_131 -> V_671 &
~ ( F_151 ( V_683 ) |
F_151 ( V_681 ) |
F_151 ( V_678 ) ) )
return - V_16 ;
break;
case V_803 :
case V_804 :
if ( ! ( V_131 -> V_673 & F_151 ( V_682 ) ) )
return - V_16 ;
V_131 -> V_671 &= ~ F_151 ( V_682 ) ;
break;
default:
if ( V_131 -> V_805 != V_806 )
return - V_16 ;
if ( V_131 -> V_768 )
return - V_16 ;
if ( V_131 -> V_807 & V_808 )
return - V_16 ;
}
if ( V_798 != V_803 &&
V_798 != V_804 ) {
if ( V_131 -> V_673 & F_151 ( V_682 ) )
return - V_16 ;
V_131 -> V_671 &= ~ F_151 ( V_682 ) ;
}
if ( V_798 != V_803 ) {
if ( V_131 -> V_807 & V_809 )
return - V_16 ;
if ( V_131 -> V_807 & V_810 )
return - V_16 ;
if ( V_131 -> V_811 )
return - V_16 ;
if ( V_131 -> V_812 || V_131 -> V_813 || V_131 -> V_814 )
return - V_16 ;
}
if ( V_798 != V_815 ) {
if ( V_131 -> V_816 )
return - V_16 ;
}
switch ( V_798 ) {
case V_817 :
if ( ! ( V_131 -> V_671 & F_151 ( V_678 ) ) )
return - V_483 ;
break;
case V_815 :
if ( V_131 -> V_671 &
~ ( F_151 ( V_678 ) |
F_151 ( V_683 ) |
F_151 ( V_818 ) |
F_151 ( V_679 ) |
F_151 ( V_680 ) |
F_151 ( V_681 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_275 & V_819 ) &&
V_131 -> V_671 &
( F_151 ( V_683 ) |
F_151 ( V_818 ) ) )
return - V_16 ;
break;
case V_820 :
case V_821 :
if ( V_131 -> V_671 & ~ F_151 ( V_678 ) )
return - V_16 ;
break;
case V_803 :
if ( V_131 -> V_671 & ~ ( F_151 ( V_678 ) |
F_151 ( V_680 ) ) )
return - V_16 ;
if ( V_131 -> V_673 & F_151 ( V_678 ) &&
! V_131 -> V_811 )
return - V_16 ;
break;
case V_804 :
return - V_16 ;
case V_801 :
if ( V_131 -> V_807 & V_808 )
return - V_16 ;
break;
case V_802 :
if ( V_131 -> V_805 != V_806 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_26 * F_167 ( struct V_30 * V_31 ,
struct V_6 * V_7 )
{
struct V_4 * V_822 = V_31 -> V_5 [ V_823 ] ;
struct V_26 * V_824 ;
int V_441 ;
if ( ! V_822 )
return NULL ;
V_824 = F_12 ( F_94 ( V_31 ) , F_4 ( V_822 ) ) ;
if ( ! V_824 )
return F_3 ( - V_24 ) ;
if ( ! V_824 -> V_29 || V_824 -> V_29 -> V_18 != & V_7 -> V_18 ) {
V_441 = - V_16 ;
goto error;
}
if ( V_824 -> V_29 -> V_135 != V_137 &&
V_824 -> V_29 -> V_135 != V_136 &&
V_824 -> V_29 -> V_135 != V_138 ) {
V_441 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_824 ) ) {
V_441 = - V_497 ;
goto error;
}
return V_824 ;
error:
F_14 ( V_824 ) ;
return F_3 ( V_441 ) ;
}
static int F_168 ( struct V_30 * V_31 ,
struct V_666 * V_131 )
{
struct V_4 * V_89 [ V_825 + 1 ] ;
struct V_4 * V_537 ;
int V_38 ;
if ( ! V_31 -> V_5 [ V_826 ] )
return 0 ;
V_537 = V_31 -> V_5 [ V_826 ] ;
V_38 = F_38 ( V_89 , V_825 , V_537 ,
V_827 ) ;
if ( V_38 )
return V_38 ;
if ( V_89 [ V_828 ] )
V_131 -> V_829 = F_39 (
V_89 [ V_828 ] ) ;
if ( V_131 -> V_829 & ~ V_830 )
return - V_16 ;
if ( V_89 [ V_831 ] )
V_131 -> V_832 = F_39 ( V_89 [ V_831 ] ) ;
if ( V_131 -> V_832 & ~ V_833 )
return - V_16 ;
V_131 -> V_807 |= V_809 ;
return 0 ;
}
static int F_169 ( struct V_30 * V_31 ,
struct V_666 * V_131 )
{
if ( V_31 -> V_5 [ V_834 ] )
V_131 -> V_813 =
F_28 ( V_31 -> V_5 [ V_834 ] ) ;
if ( V_31 -> V_5 [ V_835 ] )
V_131 -> V_814 =
F_28 ( V_31 -> V_5 [ V_835 ] ) ;
return F_168 ( V_31 , V_131 ) ;
}
static int F_170 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_666 V_131 ;
T_2 * V_576 ;
int V_38 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_799 = - 1 ;
if ( ! V_7 -> V_326 -> V_836 )
return - V_483 ;
if ( V_31 -> V_5 [ V_837 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
V_576 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( V_31 -> V_5 [ V_838 ] ) {
V_131 . V_811 =
F_28 ( V_31 -> V_5 [ V_838 ] ) ;
V_131 . V_839 =
F_29 ( V_31 -> V_5 [ V_838 ] ) ;
}
if ( V_31 -> V_5 [ V_840 ] ) {
V_131 . V_841 =
F_78 ( V_31 -> V_5 [ V_840 ] ) ;
V_131 . V_807 |= V_810 ;
}
if ( V_31 -> V_5 [ V_842 ] ) {
V_131 . V_812 =
F_28 ( V_31 -> V_5 [ V_842 ] ) ;
V_131 . V_843 =
F_29 ( V_31 -> V_5 [ V_842 ] ) ;
}
if ( V_31 -> V_5 [ V_844 ] )
return - V_16 ;
if ( F_158 ( V_31 , V_189 -> V_29 -> V_135 , & V_131 ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_845 ] ) {
V_131 . V_805 =
F_39 ( V_31 -> V_5 [ V_845 ] ) ;
if ( V_131 . V_805 >= V_846 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_847 ] ) {
V_131 . V_737 =
F_39 ( V_31 -> V_5 [ V_847 ] ) ;
if ( V_131 . V_737 >= V_848 )
return - V_16 ;
V_131 . V_807 |= V_808 ;
}
if ( V_31 -> V_5 [ V_849 ] ) {
enum V_850 V_851 = F_4 (
V_31 -> V_5 [ V_849 ] ) ;
if ( V_851 <= V_852 ||
V_851 > V_853 )
return - V_16 ;
V_131 . V_768 = V_851 ;
}
V_38 = F_169 ( V_31 , & V_131 ) ;
if ( V_38 )
return V_38 ;
V_131 . V_816 = F_167 ( V_31 , V_7 ) ;
if ( F_16 ( V_131 . V_816 ) )
return F_21 ( V_131 . V_816 ) ;
switch ( V_189 -> V_29 -> V_135 ) {
case V_136 :
case V_137 :
case V_138 :
case V_144 :
case V_143 :
case V_140 :
case V_139 :
break;
default:
V_38 = - V_483 ;
goto V_854;
}
V_38 = F_171 ( V_7 , V_189 , V_576 , & V_131 ) ;
V_854:
if ( V_131 . V_816 )
F_14 ( V_131 . V_816 ) ;
return V_38 ;
}
static int F_172 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int V_38 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_666 V_131 ;
T_2 * V_576 = NULL ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
if ( ! V_7 -> V_326 -> V_350 )
return - V_483 ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_844 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_838 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_837 ] )
return - V_16 ;
V_576 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_131 . V_811 =
F_28 ( V_31 -> V_5 [ V_838 ] ) ;
V_131 . V_839 =
F_29 ( V_31 -> V_5 [ V_838 ] ) ;
V_131 . V_799 =
F_78 ( V_31 -> V_5 [ V_844 ] ) ;
V_131 . V_800 = F_78 ( V_31 -> V_5 [ V_837 ] ) ;
if ( ! V_131 . V_800 || V_131 . V_800 > V_855 )
return - V_16 ;
if ( V_31 -> V_5 [ V_840 ] ) {
V_131 . V_841 =
F_78 ( V_31 -> V_5 [ V_840 ] ) ;
V_131 . V_807 |= V_810 ;
}
if ( V_31 -> V_5 [ V_842 ] ) {
V_131 . V_812 =
F_28 ( V_31 -> V_5 [ V_842 ] ) ;
V_131 . V_843 =
F_29 ( V_31 -> V_5 [ V_842 ] ) ;
}
if ( V_31 -> V_5 [ V_834 ] )
V_131 . V_813 =
F_28 ( V_31 -> V_5 [ V_834 ] ) ;
if ( V_31 -> V_5 [ V_835 ] )
V_131 . V_814 =
F_28 ( V_31 -> V_5 [ V_835 ] ) ;
if ( V_31 -> V_5 [ V_845 ] ) {
V_131 . V_805 =
F_39 ( V_31 -> V_5 [ V_845 ] ) ;
if ( V_131 . V_805 >= V_846 )
return - V_16 ;
}
V_38 = F_168 ( V_31 , & V_131 ) ;
if ( V_38 )
return V_38 ;
if ( F_158 ( V_31 , V_189 -> V_29 -> V_135 , & V_131 ) )
return - V_16 ;
F_114 ( V_667 != 7 ) ;
switch ( V_189 -> V_29 -> V_135 ) {
case V_136 :
case V_137 :
case V_138 :
if ( ! ( V_7 -> V_18 . V_54 & V_304 ) ||
! ( V_131 . V_673 & F_151 ( V_680 ) ) )
V_131 . V_807 &= ~ V_809 ;
if ( V_131 . V_673 & F_151 ( V_682 ) )
return - V_16 ;
V_131 . V_671 &= ~ F_151 ( V_682 ) ;
if ( ! ( V_7 -> V_18 . V_275 &
V_819 ) &&
V_131 . V_671 &
( F_151 ( V_683 ) |
F_151 ( V_818 ) ) )
return - V_16 ;
V_131 . V_816 = F_167 ( V_31 , V_7 ) ;
if ( F_16 ( V_131 . V_816 ) )
return F_21 ( V_131 . V_816 ) ;
break;
case V_139 :
V_131 . V_807 &= ~ V_809 ;
if ( V_131 . V_671 & F_151 ( V_818 ) )
return - V_16 ;
if ( V_131 . V_673 & F_151 ( V_682 ) )
return - V_16 ;
break;
case V_143 :
case V_144 :
V_131 . V_807 &= ~ V_809 ;
if ( V_131 . V_671 &
( F_151 ( V_818 ) |
F_151 ( V_683 ) ) )
return - V_16 ;
if ( ! ( V_131 . V_673 & F_151 ( V_682 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_54 & V_308 ) )
return - V_483 ;
if ( ! ( V_7 -> V_18 . V_54 & V_310 ) )
return - V_483 ;
V_131 . V_671 &= ~ F_151 ( V_678 ) ;
break;
default:
return - V_483 ;
}
V_38 = F_173 ( V_7 , V_189 , V_576 , & V_131 ) ;
if ( V_131 . V_816 )
F_14 ( V_131 . V_816 ) ;
return V_38 ;
}
static int F_174 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 * V_576 = NULL ;
if ( V_31 -> V_5 [ V_488 ] )
V_576 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( V_189 -> V_29 -> V_135 != V_136 &&
V_189 -> V_29 -> V_135 != V_137 &&
V_189 -> V_29 -> V_135 != V_139 &&
V_189 -> V_29 -> V_135 != V_138 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_856 )
return - V_483 ;
return F_175 ( V_7 , V_189 , V_576 ) ;
}
static int F_176 ( struct V_34 * V_56 , V_23 V_52 , V_23 V_53 ,
int V_54 , struct V_26 * V_189 ,
T_2 * V_857 , T_2 * V_858 ,
struct V_859 * V_860 )
{
void * V_264 ;
struct V_4 * V_861 ;
V_264 = F_30 ( V_56 , V_52 , V_53 , V_54 , V_709 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_857 ) ||
F_54 ( V_56 , V_862 , V_525 , V_858 ) ||
F_33 ( V_56 , V_278 , V_860 -> V_710 ) )
goto V_62;
V_861 = F_50 ( V_56 , V_863 ) ;
if ( ! V_861 )
goto V_62;
if ( ( V_860 -> V_712 & V_864 ) &&
F_33 ( V_56 , V_865 ,
V_860 -> V_866 ) )
goto V_62;
if ( ( ( V_860 -> V_712 & V_867 ) &&
F_33 ( V_56 , V_868 , V_860 -> V_869 ) ) ||
( ( V_860 -> V_712 & V_870 ) &&
F_33 ( V_56 , V_871 ,
V_860 -> V_872 ) ) ||
( ( V_860 -> V_712 & V_873 ) &&
F_33 ( V_56 , V_874 ,
V_860 -> V_875 ) ) ||
( ( V_860 -> V_712 & V_876 ) &&
F_58 ( V_56 , V_877 ,
V_860 -> V_54 ) ) ||
( ( V_860 -> V_712 & V_878 ) &&
F_33 ( V_56 , V_879 ,
V_860 -> V_880 ) ) ||
( ( V_860 -> V_712 & V_881 ) &&
F_58 ( V_56 , V_882 ,
V_860 -> V_883 ) ) )
goto V_62;
F_51 ( V_56 , V_861 ) ;
return F_67 ( V_56 , V_264 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
static int F_177 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_859 V_860 ;
struct V_6 * V_189 ;
struct V_1 * V_17 ;
T_2 V_857 [ V_525 ] ;
T_2 V_858 [ V_525 ] ;
int V_884 = V_37 -> args [ 2 ] ;
int V_38 ;
V_38 = F_17 ( V_35 , V_37 , & V_189 , & V_17 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_189 -> V_326 -> V_885 ) {
V_38 = - V_483 ;
goto V_794;
}
if ( V_17 -> V_135 != V_139 ) {
V_38 = - V_483 ;
goto V_794;
}
while ( 1 ) {
V_38 = F_178 ( V_189 , V_17 -> V_20 , V_884 , V_857 ,
V_858 , & V_860 ) ;
if ( V_38 == - V_583 )
break;
if ( V_38 )
goto V_794;
if ( F_176 ( V_35 , F_72 ( V_37 -> V_35 ) . V_52 ,
V_37 -> V_39 -> V_445 , V_446 ,
V_17 -> V_20 , V_857 , V_858 ,
& V_860 ) < 0 )
goto V_535;
V_884 ++ ;
}
V_535:
V_37 -> args [ 2 ] = V_884 ;
V_38 = V_35 -> V_50 ;
V_794:
F_25 ( V_189 ) ;
return V_38 ;
}
static int F_179 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int V_38 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_859 V_860 ;
struct V_34 * V_56 ;
T_2 * V_857 = NULL ;
T_2 V_858 [ V_525 ] ;
memset ( & V_860 , 0 , sizeof( V_860 ) ) ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
V_857 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( ! V_7 -> V_326 -> V_886 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_139 )
return - V_483 ;
V_38 = F_180 ( V_7 , V_189 , V_857 , V_858 , & V_860 ) ;
if ( V_38 )
return V_38 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
if ( F_176 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_189 , V_857 , V_858 , & V_860 ) < 0 ) {
F_75 ( V_56 ) ;
return - V_85 ;
}
return F_76 ( V_56 , V_31 ) ;
}
static int F_181 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 * V_857 = NULL ;
T_2 * V_858 = NULL ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_862 ] )
return - V_16 ;
V_857 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_858 = F_28 ( V_31 -> V_5 [ V_862 ] ) ;
if ( ! V_7 -> V_326 -> V_887 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_139 )
return - V_483 ;
return F_182 ( V_7 , V_189 , V_857 , V_858 ) ;
}
static int F_183 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 * V_857 = NULL ;
T_2 * V_858 = NULL ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_862 ] )
return - V_16 ;
V_857 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_858 = F_28 ( V_31 -> V_5 [ V_862 ] ) ;
if ( ! V_7 -> V_326 -> V_352 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_139 )
return - V_483 ;
return F_184 ( V_7 , V_189 , V_857 , V_858 ) ;
}
static int F_185 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 * V_857 = NULL ;
if ( V_31 -> V_5 [ V_488 ] )
V_857 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( ! V_7 -> V_326 -> V_888 )
return - V_483 ;
return F_186 ( V_7 , V_189 , V_857 ) ;
}
static int F_187 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_889 V_131 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_890 = - 1 ;
V_131 . V_891 = - 1 ;
V_131 . V_892 = - 1 ;
V_131 . V_893 = - 1 ;
V_131 . V_894 = - 1 ;
V_131 . V_657 = - 1 ;
V_131 . V_660 = - 1 ;
if ( V_31 -> V_5 [ V_895 ] )
V_131 . V_890 =
F_39 ( V_31 -> V_5 [ V_895 ] ) ;
if ( V_31 -> V_5 [ V_896 ] )
V_131 . V_891 =
F_39 ( V_31 -> V_5 [ V_896 ] ) ;
if ( V_31 -> V_5 [ V_897 ] )
V_131 . V_892 =
F_39 ( V_31 -> V_5 [ V_897 ] ) ;
if ( V_31 -> V_5 [ V_898 ] ) {
V_131 . V_899 =
F_28 ( V_31 -> V_5 [ V_898 ] ) ;
V_131 . V_900 =
F_29 ( V_31 -> V_5 [ V_898 ] ) ;
}
if ( V_31 -> V_5 [ V_901 ] )
V_131 . V_893 = ! ! F_39 ( V_31 -> V_5 [ V_901 ] ) ;
if ( V_31 -> V_5 [ V_902 ] )
V_131 . V_894 =
F_78 ( V_31 -> V_5 [ V_902 ] ) ;
if ( V_31 -> V_5 [ V_656 ] ) {
if ( V_189 -> V_29 -> V_135 != V_138 )
return - V_16 ;
V_131 . V_657 =
F_188 ( V_31 -> V_5 [ V_656 ] ) ;
if ( V_131 . V_657 < 0 )
return - V_16 ;
if ( V_131 . V_657 != 0 &&
! ( V_7 -> V_18 . V_275 & V_658 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_659 ] ) {
T_2 V_25 ;
if ( V_189 -> V_29 -> V_135 != V_138 )
return - V_16 ;
V_25 = F_39 ( V_31 -> V_5 [ V_659 ] ) ;
if ( V_25 > 1 )
return - V_16 ;
V_131 . V_660 = V_25 ;
if ( V_131 . V_660 &&
! ( V_7 -> V_18 . V_275 & V_661 ) )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_356 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_136 &&
V_189 -> V_29 -> V_135 != V_138 )
return - V_483 ;
return F_189 ( V_7 , V_189 , & V_131 ) ;
}
static int F_190 ( struct V_4 * V_89 [] ,
struct V_903 * V_904 )
{
struct V_905 * V_906 = & V_904 -> V_906 ;
struct V_907 * V_908 = & V_904 -> V_908 ;
if ( ! V_89 [ V_909 ] )
return - V_16 ;
if ( ! V_89 [ V_910 ] )
return - V_16 ;
if ( ! V_89 [ V_911 ] )
return - V_16 ;
if ( ! V_89 [ V_912 ] )
return - V_16 ;
if ( ! V_89 [ V_913 ] )
return - V_16 ;
V_904 -> V_54 = F_4 ( V_89 [ V_909 ] ) ;
V_906 -> V_914 =
F_4 ( V_89 [ V_910 ] ) ;
V_906 -> V_915 =
F_4 ( V_89 [ V_911 ] ) ;
V_906 -> V_916 =
F_4 ( V_89 [ V_912 ] ) ;
V_908 -> V_917 =
F_4 ( V_89 [ V_913 ] ) ;
if ( V_89 [ V_918 ] )
V_908 -> V_919 =
F_4 ( V_89 [ V_918 ] ) ;
return 0 ;
}
static int F_191 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
int V_920 ;
char * V_132 = NULL ;
enum V_921 V_922 ;
if ( F_192 ( ! F_193 ( V_923 ) ) )
return - V_924 ;
if ( ! V_31 -> V_5 [ V_925 ] )
return - V_16 ;
V_132 = F_28 ( V_31 -> V_5 [ V_925 ] ) ;
if ( V_31 -> V_5 [ V_926 ] )
V_922 =
F_4 ( V_31 -> V_5 [ V_926 ] ) ;
else
V_922 = V_927 ;
switch ( V_922 ) {
case V_927 :
case V_928 :
break;
default:
return - V_16 ;
}
V_920 = F_194 ( V_132 , V_922 ) ;
return V_920 ;
}
static int F_195 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_929 V_930 ;
int V_38 = 0 ;
void * V_264 ;
struct V_4 * V_861 ;
struct V_34 * V_56 ;
if ( V_17 -> V_135 != V_139 )
return - V_483 ;
if ( ! V_7 -> V_326 -> V_931 )
return - V_483 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_932 )
memcpy ( & V_930 , & V_933 , sizeof( V_930 ) ) ;
else
V_38 = F_196 ( V_7 , V_189 , & V_930 ) ;
F_115 ( V_17 ) ;
if ( V_38 )
return V_38 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_934 ) ;
if ( ! V_264 )
goto V_535;
V_861 = F_50 ( V_56 , V_935 ) ;
if ( ! V_861 )
goto V_62;
if ( F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_57 ( V_56 , V_936 ,
V_930 . V_937 ) ||
F_57 ( V_56 , V_938 ,
V_930 . V_939 ) ||
F_57 ( V_56 , V_940 ,
V_930 . V_941 ) ||
F_57 ( V_56 , V_942 ,
V_930 . V_943 ) ||
F_58 ( V_56 , V_944 ,
V_930 . V_945 ) ||
F_58 ( V_56 , V_946 ,
V_930 . V_947 ) ||
F_58 ( V_56 , V_948 ,
V_930 . V_949 ) ||
F_58 ( V_56 , V_950 ,
V_930 . V_951 ) ||
F_33 ( V_56 , V_952 ,
V_930 . V_953 ) ||
F_58 ( V_56 , V_954 ,
V_930 . V_955 ) ||
F_33 ( V_56 , V_956 ,
V_930 . V_957 ) ||
F_57 ( V_56 , V_958 ,
V_930 . V_959 ) ||
F_33 ( V_56 , V_960 ,
V_930 . V_961 ) ||
F_57 ( V_56 , V_962 ,
V_930 . V_963 ) ||
F_57 ( V_56 , V_964 ,
V_930 . V_965 ) ||
F_57 ( V_56 , V_966 ,
V_930 . V_967 ) ||
F_58 ( V_56 , V_968 ,
V_930 . V_969 ) ||
F_57 ( V_56 , V_970 ,
V_930 . V_971 ) ||
F_58 ( V_56 , V_972 ,
V_930 . V_973 ) ||
F_58 ( V_56 , V_974 ,
V_930 . V_975 ) ||
F_33 ( V_56 , V_976 ,
V_930 . V_977 ) ||
F_33 ( V_56 , V_978 ,
V_930 . V_894 ) ||
F_33 ( V_56 , V_979 ,
V_930 . V_980 ) ||
F_57 ( V_56 , V_981 ,
V_930 . V_982 ) ||
F_57 ( V_56 , V_983 ,
V_930 . V_984 ) ||
F_33 ( V_56 , V_985 ,
V_930 . V_986 ) ||
F_57 ( V_56 , V_987 ,
V_930 . V_988 ) )
goto V_62;
F_51 ( V_56 , V_861 ) ;
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
V_535:
F_75 ( V_56 ) ;
return - V_85 ;
}
static int F_197 ( struct V_30 * V_31 ,
struct V_929 * V_989 ,
V_23 * V_990 )
{
struct V_4 * V_89 [ V_991 + 1 ] ;
V_23 V_672 = 0 ;
#define F_198 ( V_89 , V_989 , T_7 , T_8 , V_164 , V_672 , V_48 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_31 -> V_5 [ V_935 ] )
return - V_16 ;
if ( F_38 ( V_89 , V_991 ,
V_31 -> V_5 [ V_935 ] ,
V_992 ) )
return - V_16 ;
F_114 ( V_991 > 32 ) ;
F_198 ( V_89 , V_989 , V_937 , 1 , 255 ,
V_672 , V_936 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_939 , 1 , 255 ,
V_672 , V_938 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_941 , 1 , 255 ,
V_672 , V_940 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_943 , 0 , 255 ,
V_672 , V_942 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_945 , 0 , 16 ,
V_672 , V_944 ,
F_39 ) ;
F_198 ( V_89 , V_989 , V_947 , 1 , 255 ,
V_672 , V_946 , F_39 ) ;
F_198 ( V_89 , V_989 , V_949 , 1 , 255 ,
V_672 , V_948 ,
F_39 ) ;
F_198 ( V_89 , V_989 , V_951 , 0 , 1 ,
V_672 , V_950 ,
F_39 ) ;
F_198 ( V_89 , V_989 , V_953 ,
1 , 255 , V_672 ,
V_952 ,
F_4 ) ;
F_198 ( V_89 , V_989 , V_955 , 0 , 255 ,
V_672 , V_954 ,
F_39 ) ;
F_198 ( V_89 , V_989 , V_957 , 1 , 65535 ,
V_672 , V_956 ,
F_4 ) ;
F_198 ( V_89 , V_989 , V_959 , 1 , 65535 ,
V_672 , V_958 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_961 ,
1 , 65535 , V_672 ,
V_960 ,
F_4 ) ;
F_198 ( V_89 , V_989 , V_963 ,
1 , 65535 , V_672 ,
V_962 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_965 ,
1 , 65535 , V_672 ,
V_964 ,
F_78 ) ;
F_198 ( V_89 , V_989 ,
V_967 ,
1 , 65535 , V_672 ,
V_966 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_969 , 0 , 4 ,
V_672 , V_968 ,
F_39 ) ;
F_198 ( V_89 , V_989 , V_971 , 1 , 65535 ,
V_672 , V_970 ,
F_78 ) ;
F_198 ( V_89 , V_989 ,
V_973 , 0 , 1 ,
V_672 , V_972 ,
F_39 ) ;
F_198 ( V_89 , V_989 , V_975 , 0 , 1 ,
V_672 , V_974 ,
F_39 ) ;
F_198 ( V_89 , V_989 , V_977 , 1 , 255 ,
V_672 , V_976 ,
F_4 ) ;
F_198 ( V_89 , V_989 , V_894 , 0 , 16 ,
V_672 , V_978 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_980 ,
1 , 65535 , V_672 ,
V_979 ,
F_4 ) ;
F_198 ( V_89 , V_989 , V_982 , 1 , 65535 ,
V_672 , V_981 ,
F_78 ) ;
F_198 ( V_89 , V_989 ,
V_984 ,
1 , 65535 , V_672 ,
V_983 ,
F_78 ) ;
F_198 ( V_89 , V_989 , V_986 ,
V_993 ,
V_853 ,
V_672 , V_985 ,
F_4 ) ;
F_198 ( V_89 , V_989 , V_988 ,
0 , 65535 , V_672 ,
V_987 , F_78 ) ;
if ( V_990 )
* V_990 = V_672 ;
return 0 ;
#undef F_198
}
static int F_199 ( struct V_30 * V_31 ,
struct V_994 * V_995 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_4 * V_89 [ V_996 + 1 ] ;
if ( ! V_31 -> V_5 [ V_997 ] )
return - V_16 ;
if ( F_38 ( V_89 , V_996 ,
V_31 -> V_5 [ V_997 ] ,
V_998 ) )
return - V_16 ;
if ( V_89 [ V_999 ] )
V_995 -> V_1000 =
( F_39 ( V_89 [ V_999 ] ) ) ?
V_1001 :
V_1002 ;
if ( V_89 [ V_1003 ] )
V_995 -> V_1004 =
( F_39 ( V_89 [ V_1003 ] ) ) ?
V_1005 :
V_1006 ;
if ( V_89 [ V_1007 ] )
V_995 -> V_1008 =
( F_39 ( V_89 [ V_1007 ] ) ) ?
V_1009 :
V_1010 ;
if ( V_89 [ V_1011 ] ) {
struct V_4 * V_1012 =
V_89 [ V_1011 ] ;
if ( ! F_27 ( V_1012 ) )
return - V_16 ;
V_995 -> V_1013 = F_28 ( V_1012 ) ;
V_995 -> V_1014 = F_29 ( V_1012 ) ;
}
if ( V_89 [ V_1015 ] &&
! ( V_7 -> V_18 . V_275 & V_1016 ) )
return - V_16 ;
V_995 -> V_1017 = F_200 ( V_89 [ V_1015 ] ) ;
V_995 -> V_1018 = F_200 ( V_89 [ V_1019 ] ) ;
V_995 -> V_1020 = F_200 ( V_89 [ V_1021 ] ) ;
if ( V_995 -> V_1020 )
V_995 -> V_1017 = true ;
return 0 ;
}
static int F_201 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_929 V_989 ;
V_23 V_672 ;
int V_38 ;
if ( V_17 -> V_135 != V_139 )
return - V_483 ;
if ( ! V_7 -> V_326 -> V_354 )
return - V_483 ;
V_38 = F_197 ( V_31 , & V_989 , & V_672 ) ;
if ( V_38 )
return V_38 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_932 )
V_38 = - V_142 ;
if ( ! V_38 )
V_38 = F_202 ( V_7 , V_189 , V_672 , & V_989 ) ;
F_115 ( V_17 ) ;
return V_38 ;
}
static int F_203 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
const struct V_1022 * V_1023 ;
struct V_34 * V_56 ;
void * V_264 = NULL ;
struct V_4 * V_1024 ;
unsigned int V_149 ;
int V_38 = - V_16 ;
F_8 ( & V_32 ) ;
if ( ! V_923 )
goto V_535;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 ) {
V_38 = - V_85 ;
goto V_535;
}
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_1025 ) ;
if ( ! V_264 )
goto V_1026;
if ( F_204 () &&
F_33 ( V_56 , V_926 ,
V_928 ) )
goto V_62;
F_205 () ;
V_1023 = F_206 ( V_923 ) ;
if ( F_61 ( V_56 , V_925 , V_1023 -> V_1027 ) ||
( V_1023 -> V_1028 &&
F_58 ( V_56 , V_1029 , V_1023 -> V_1028 ) ) )
goto V_1030;
V_1024 = F_50 ( V_56 , V_1031 ) ;
if ( ! V_1024 )
goto V_1030;
for ( V_149 = 0 ; V_149 < V_1023 -> V_1032 ; V_149 ++ ) {
struct V_4 * V_1033 ;
const struct V_903 * V_904 ;
const struct V_905 * V_906 ;
const struct V_907 * V_908 ;
V_904 = & V_1023 -> V_1034 [ V_149 ] ;
V_906 = & V_904 -> V_906 ;
V_908 = & V_904 -> V_908 ;
V_1033 = F_50 ( V_56 , V_149 ) ;
if ( ! V_1033 )
goto V_1030;
if ( F_33 ( V_56 , V_909 ,
V_904 -> V_54 ) ||
F_33 ( V_56 , V_910 ,
V_906 -> V_914 ) ||
F_33 ( V_56 , V_911 ,
V_906 -> V_915 ) ||
F_33 ( V_56 , V_912 ,
V_906 -> V_916 ) ||
F_33 ( V_56 , V_918 ,
V_908 -> V_919 ) ||
F_33 ( V_56 , V_913 ,
V_908 -> V_917 ) )
goto V_1030;
F_51 ( V_56 , V_1033 ) ;
}
F_207 () ;
F_51 ( V_56 , V_1024 ) ;
F_67 ( V_56 , V_264 ) ;
V_38 = F_76 ( V_56 , V_31 ) ;
goto V_535;
V_1030:
F_207 () ;
V_62:
F_68 ( V_56 , V_264 ) ;
V_1026:
F_75 ( V_56 ) ;
V_38 = - V_440 ;
V_535:
F_9 ( & V_32 ) ;
return V_38 ;
}
static int F_208 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_4 * V_89 [ V_1035 + 1 ] ;
struct V_4 * V_1033 ;
char * V_1027 = NULL ;
int V_1036 = 0 , V_920 = 0 ;
V_23 V_1037 = 0 , V_1038 = 0 , V_1039 ;
T_2 V_1028 = 0 ;
struct V_1022 * V_1040 = NULL ;
if ( ! V_31 -> V_5 [ V_925 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1031 ] )
return - V_16 ;
V_1027 = F_28 ( V_31 -> V_5 [ V_925 ] ) ;
if ( V_31 -> V_5 [ V_1029 ] )
V_1028 = F_39 ( V_31 -> V_5 [ V_1029 ] ) ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1037 ++ ;
if ( V_1037 > V_1041 )
return - V_16 ;
}
V_1039 = sizeof( struct V_1022 ) +
V_1037 * sizeof( struct V_903 ) ;
V_1040 = F_43 ( V_1039 , V_129 ) ;
if ( ! V_1040 )
return - V_130 ;
V_1040 -> V_1032 = V_1037 ;
V_1040 -> V_1027 [ 0 ] = V_1027 [ 0 ] ;
V_1040 -> V_1027 [ 1 ] = V_1027 [ 1 ] ;
if ( F_209 ( V_1028 ) )
V_1040 -> V_1028 = V_1028 ;
F_44 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
F_96 ( V_89 , V_1035 ,
F_28 ( V_1033 ) , F_29 ( V_1033 ) ,
V_1042 ) ;
V_920 = F_190 ( V_89 , & V_1040 -> V_1034 [ V_1038 ] ) ;
if ( V_920 )
goto V_1043;
V_1038 ++ ;
if ( V_1038 > V_1041 ) {
V_920 = - V_16 ;
goto V_1043;
}
}
F_8 ( & V_32 ) ;
V_920 = F_210 ( V_1040 ) ;
V_1040 = NULL ;
F_9 ( & V_32 ) ;
V_1043:
F_46 ( V_1040 ) ;
return V_920 ;
}
static int F_211 ( struct V_4 * V_1044 )
{
struct V_4 * V_1045 , * V_1046 ;
int V_339 = 0 , V_1047 , V_1048 ;
F_44 (attr1, freqs, tmp1) {
V_339 ++ ;
F_44 (attr2, freqs, tmp2)
if ( V_1045 != V_1046 &&
F_4 ( V_1045 ) == F_4 ( V_1046 ) )
return 0 ;
}
return V_339 ;
}
static int F_212 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
struct V_1049 * V_1050 ;
struct V_4 * V_48 ;
struct V_18 * V_18 ;
int V_38 , V_25 , V_1051 = 0 , V_339 , V_149 ;
T_10 V_1014 ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_326 -> V_1052 )
return - V_483 ;
F_8 ( & V_7 -> V_1053 ) ;
if ( V_7 -> V_1054 ) {
V_38 = - V_485 ;
goto V_1055;
}
if ( V_31 -> V_5 [ V_1056 ] ) {
V_339 = F_211 (
V_31 -> V_5 [ V_1056 ] ) ;
if ( ! V_339 ) {
V_38 = - V_16 ;
goto V_1055;
}
} else {
enum V_270 V_271 ;
V_339 = 0 ;
for ( V_271 = 0 ; V_271 < V_336 ; V_271 ++ )
if ( V_18 -> V_337 [ V_271 ] )
V_339 += V_18 -> V_337 [ V_271 ] -> V_339 ;
}
if ( V_31 -> V_5 [ V_1057 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1051 ++ ;
if ( V_1051 > V_18 -> V_291 ) {
V_38 = - V_16 ;
goto V_1055;
}
if ( V_31 -> V_5 [ V_610 ] )
V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
else
V_1014 = 0 ;
if ( V_1014 > V_18 -> V_295 ) {
V_38 = - V_16 ;
goto V_1055;
}
V_1050 = F_43 ( sizeof( * V_1050 )
+ sizeof( * V_1050 -> V_1058 ) * V_1051
+ sizeof( * V_1050 -> V_340 ) * V_339
+ V_1014 , V_129 ) ;
if ( ! V_1050 ) {
V_38 = - V_130 ;
goto V_1055;
}
if ( V_1051 )
V_1050 -> V_1058 = ( void * ) & V_1050 -> V_340 [ V_339 ] ;
V_1050 -> V_1051 = V_1051 ;
if ( V_1014 ) {
if ( V_1050 -> V_1058 )
V_1050 -> V_1013 = ( void * ) ( V_1050 -> V_1058 + V_1051 ) ;
else
V_1050 -> V_1013 = ( void * ) ( V_1050 -> V_340 + V_339 ) ;
}
V_149 = 0 ;
if ( V_31 -> V_5 [ V_1056 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_57 * V_58 ;
V_58 = F_81 ( V_18 , F_4 ( V_48 ) ) ;
if ( ! V_58 ) {
V_38 = - V_16 ;
goto V_1059;
}
if ( V_58 -> V_54 & V_63 )
continue;
V_1050 -> V_340 [ V_149 ] = V_58 ;
V_149 ++ ;
}
} else {
enum V_270 V_271 ;
for ( V_271 = 0 ; V_271 < V_336 ; V_271 ++ ) {
int V_151 ;
if ( ! V_18 -> V_337 [ V_271 ] )
continue;
for ( V_151 = 0 ; V_151 < V_18 -> V_337 [ V_271 ] -> V_339 ; V_151 ++ ) {
struct V_57 * V_58 ;
V_58 = & V_18 -> V_337 [ V_271 ] -> V_340 [ V_151 ] ;
if ( V_58 -> V_54 & V_63 )
continue;
V_1050 -> V_340 [ V_149 ] = V_58 ;
V_149 ++ ;
}
}
}
if ( ! V_149 ) {
V_38 = - V_16 ;
goto V_1059;
}
V_1050 -> V_339 = V_149 ;
V_149 = 0 ;
if ( V_31 -> V_5 [ V_1057 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_29 ( V_48 ) > V_554 ) {
V_38 = - V_16 ;
goto V_1059;
}
V_1050 -> V_1058 [ V_149 ] . V_528 = F_29 ( V_48 ) ;
memcpy ( V_1050 -> V_1058 [ V_149 ] . V_530 , F_28 ( V_48 ) , F_29 ( V_48 ) ) ;
V_149 ++ ;
}
}
if ( V_31 -> V_5 [ V_610 ] ) {
V_1050 -> V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
memcpy ( ( void * ) V_1050 -> V_1013 ,
F_28 ( V_31 -> V_5 [ V_610 ] ) ,
V_1050 -> V_1014 ) ;
}
for ( V_149 = 0 ; V_149 < V_336 ; V_149 ++ )
if ( V_18 -> V_337 [ V_149 ] )
V_1050 -> V_1060 [ V_149 ] =
( 1 << V_18 -> V_337 [ V_149 ] -> V_240 ) - 1 ;
if ( V_31 -> V_5 [ V_1061 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_270 V_271 = F_213 ( V_48 ) ;
if ( V_271 < 0 || V_271 >= V_336 ) {
V_38 = - V_16 ;
goto V_1059;
}
V_38 = F_214 ( V_18 -> V_337 [ V_271 ] ,
F_28 ( V_48 ) ,
F_29 ( V_48 ) ,
& V_1050 -> V_1060 [ V_271 ] ) ;
if ( V_38 )
goto V_1059;
}
}
if ( V_31 -> V_5 [ V_1062 ] ) {
V_1050 -> V_54 = F_4 (
V_31 -> V_5 [ V_1062 ] ) ;
if ( ( ( V_1050 -> V_54 & V_1063 ) &&
! ( V_18 -> V_275 & V_1064 ) ) ||
( ( V_1050 -> V_54 & V_1065 ) &&
! ( V_18 -> V_275 & V_1066 ) ) ) {
V_38 = - V_483 ;
goto V_1059;
}
}
V_1050 -> V_1067 =
F_200 ( V_31 -> V_5 [ V_1068 ] ) ;
V_1050 -> V_17 = V_17 ;
V_1050 -> V_18 = & V_7 -> V_18 ;
V_1050 -> V_1069 = V_1070 ;
V_7 -> V_1054 = V_1050 ;
V_38 = F_215 ( V_7 , V_1050 ) ;
if ( ! V_38 ) {
F_216 ( V_7 , V_17 ) ;
if ( V_17 -> V_20 )
F_217 ( V_17 -> V_20 ) ;
} else {
V_1059:
V_7 -> V_1054 = NULL ;
F_46 ( V_1050 ) ;
}
V_1055:
F_9 ( & V_7 -> V_1053 ) ;
return V_38 ;
}
static int F_218 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_1071 * V_1050 ;
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_4 * V_48 ;
struct V_18 * V_18 ;
int V_38 , V_25 , V_1051 = 0 , V_1072 = 0 , V_339 , V_149 ;
V_23 V_1073 ;
enum V_270 V_271 ;
T_10 V_1014 ;
struct V_4 * V_89 [ V_1074 + 1 ] ;
if ( ! ( V_7 -> V_18 . V_54 & V_395 ) ||
! V_7 -> V_326 -> V_396 )
return - V_483 ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1075 ] )
return - V_16 ;
V_1073 = F_4 ( V_31 -> V_5 [ V_1075 ] ) ;
if ( V_1073 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_1056 ] ) {
V_339 = F_211 (
V_31 -> V_5 [ V_1056 ] ) ;
if ( ! V_339 )
return - V_16 ;
} else {
V_339 = 0 ;
for ( V_271 = 0 ; V_271 < V_336 ; V_271 ++ )
if ( V_18 -> V_337 [ V_271 ] )
V_339 += V_18 -> V_337 [ V_271 ] -> V_339 ;
}
if ( V_31 -> V_5 [ V_1057 ] )
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1051 ++ ;
if ( V_1051 > V_18 -> V_293 )
return - V_16 ;
if ( V_31 -> V_5 [ V_1076 ] )
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp)
V_1072 ++ ;
if ( V_1072 > V_18 -> V_299 )
return - V_16 ;
if ( V_31 -> V_5 [ V_610 ] )
V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
else
V_1014 = 0 ;
if ( V_1014 > V_18 -> V_297 )
return - V_16 ;
F_8 ( & V_7 -> V_1053 ) ;
if ( V_7 -> V_1077 ) {
V_38 = - V_924 ;
goto V_535;
}
V_1050 = F_43 ( sizeof( * V_1050 )
+ sizeof( * V_1050 -> V_1058 ) * V_1051
+ sizeof( * V_1050 -> V_1078 ) * V_1072
+ sizeof( * V_1050 -> V_340 ) * V_339
+ V_1014 , V_129 ) ;
if ( ! V_1050 ) {
V_38 = - V_130 ;
goto V_535;
}
if ( V_1051 )
V_1050 -> V_1058 = ( void * ) & V_1050 -> V_340 [ V_339 ] ;
V_1050 -> V_1051 = V_1051 ;
if ( V_1014 ) {
if ( V_1050 -> V_1058 )
V_1050 -> V_1013 = ( void * ) ( V_1050 -> V_1058 + V_1051 ) ;
else
V_1050 -> V_1013 = ( void * ) ( V_1050 -> V_340 + V_339 ) ;
}
if ( V_1072 ) {
if ( V_1050 -> V_1013 )
V_1050 -> V_1078 = ( void * ) ( V_1050 -> V_1013 + V_1014 ) ;
else if ( V_1050 -> V_1058 )
V_1050 -> V_1078 =
( void * ) ( V_1050 -> V_1058 + V_1051 ) ;
else
V_1050 -> V_1078 =
( void * ) ( V_1050 -> V_340 + V_339 ) ;
}
V_1050 -> V_1072 = V_1072 ;
V_149 = 0 ;
if ( V_31 -> V_5 [ V_1056 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_57 * V_58 ;
V_58 = F_81 ( V_18 , F_4 ( V_48 ) ) ;
if ( ! V_58 ) {
V_38 = - V_16 ;
goto V_1059;
}
if ( V_58 -> V_54 & V_63 )
continue;
V_1050 -> V_340 [ V_149 ] = V_58 ;
V_149 ++ ;
}
} else {
for ( V_271 = 0 ; V_271 < V_336 ; V_271 ++ ) {
int V_151 ;
if ( ! V_18 -> V_337 [ V_271 ] )
continue;
for ( V_151 = 0 ; V_151 < V_18 -> V_337 [ V_271 ] -> V_339 ; V_151 ++ ) {
struct V_57 * V_58 ;
V_58 = & V_18 -> V_337 [ V_271 ] -> V_340 [ V_151 ] ;
if ( V_58 -> V_54 & V_63 )
continue;
V_1050 -> V_340 [ V_149 ] = V_58 ;
V_149 ++ ;
}
}
}
if ( ! V_149 ) {
V_38 = - V_16 ;
goto V_1059;
}
V_1050 -> V_339 = V_149 ;
V_149 = 0 ;
if ( V_31 -> V_5 [ V_1057 ] ) {
F_44 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_29 ( V_48 ) > V_554 ) {
V_38 = - V_16 ;
goto V_1059;
}
V_1050 -> V_1058 [ V_149 ] . V_528 = F_29 ( V_48 ) ;
memcpy ( V_1050 -> V_1058 [ V_149 ] . V_530 , F_28 ( V_48 ) ,
F_29 ( V_48 ) ) ;
V_149 ++ ;
}
}
V_149 = 0 ;
if ( V_31 -> V_5 [ V_1076 ] ) {
F_44 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_530 , * V_1079 ;
F_96 ( V_89 , V_1074 ,
F_28 ( V_48 ) , F_29 ( V_48 ) ,
V_1080 ) ;
V_530 = V_89 [ V_1081 ] ;
if ( V_530 ) {
if ( F_29 ( V_530 ) > V_554 ) {
V_38 = - V_16 ;
goto V_1059;
}
memcpy ( V_1050 -> V_1078 [ V_149 ] . V_530 . V_530 ,
F_28 ( V_530 ) , F_29 ( V_530 ) ) ;
V_1050 -> V_1078 [ V_149 ] . V_530 . V_528 =
F_29 ( V_530 ) ;
}
V_1079 = V_89 [ V_1082 ] ;
if ( V_1079 )
V_1050 -> V_1083 = F_4 ( V_1079 ) ;
else
V_1050 -> V_1083 =
V_1084 ;
V_149 ++ ;
}
}
if ( V_31 -> V_5 [ V_610 ] ) {
V_1050 -> V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
memcpy ( ( void * ) V_1050 -> V_1013 ,
F_28 ( V_31 -> V_5 [ V_610 ] ) ,
V_1050 -> V_1014 ) ;
}
if ( V_31 -> V_5 [ V_1062 ] ) {
V_1050 -> V_54 = F_4 (
V_31 -> V_5 [ V_1062 ] ) ;
if ( ( ( V_1050 -> V_54 & V_1063 ) &&
! ( V_18 -> V_275 & V_1064 ) ) ||
( ( V_1050 -> V_54 & V_1065 ) &&
! ( V_18 -> V_275 & V_1066 ) ) ) {
V_38 = - V_483 ;
goto V_1059;
}
}
V_1050 -> V_189 = V_189 ;
V_1050 -> V_18 = & V_7 -> V_18 ;
V_1050 -> V_1073 = V_1073 ;
V_1050 -> V_1069 = V_1070 ;
V_38 = F_219 ( V_7 , V_189 , V_1050 ) ;
if ( ! V_38 ) {
V_7 -> V_1077 = V_1050 ;
F_220 ( V_7 , V_189 ,
V_1085 ) ;
goto V_535;
}
V_1059:
F_46 ( V_1050 ) ;
V_535:
F_9 ( & V_7 -> V_1053 ) ;
return V_38 ;
}
static int F_221 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int V_38 ;
if ( ! ( V_7 -> V_18 . V_54 & V_395 ) ||
! V_7 -> V_326 -> V_1086 )
return - V_483 ;
F_8 ( & V_7 -> V_1053 ) ;
V_38 = F_222 ( V_7 , false ) ;
F_9 ( & V_7 -> V_1053 ) ;
return V_38 ;
}
static int F_223 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_465 V_466 ;
int V_38 ;
V_38 = F_80 ( V_7 , V_31 , & V_466 ) ;
if ( V_38 )
return V_38 ;
if ( V_17 -> V_1087 )
return - V_485 ;
V_38 = F_150 ( V_17 -> V_18 , & V_466 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 == 0 )
return - V_16 ;
if ( V_466 . V_58 -> V_73 != V_1088 )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1089 )
return - V_483 ;
F_8 ( & V_7 -> V_19 ) ;
V_38 = F_152 ( V_7 , V_17 , V_17 -> V_135 ,
V_466 . V_58 , V_663 ,
F_151 ( V_466 . V_469 ) ) ;
if ( V_38 )
goto V_1090;
V_38 = V_7 -> V_326 -> V_1089 ( & V_7 -> V_18 , V_189 , & V_466 ) ;
if ( ! V_38 ) {
V_17 -> V_664 = V_466 . V_58 ;
V_17 -> V_1087 = true ;
V_17 -> V_1091 = V_1070 ;
}
V_1090:
F_9 ( & V_7 -> V_19 ) ;
return V_38 ;
}
static int F_224 ( struct V_34 * V_56 , struct V_36 * V_37 ,
V_23 V_53 , int V_54 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1092 * V_1093 )
{
struct V_1094 * V_330 = & V_1093 -> V_1095 ;
const struct V_1096 * V_1097 ;
void * V_264 ;
struct V_4 * V_1098 ;
bool V_1099 = false ;
F_48 ( V_17 ) ;
V_264 = F_30 ( V_56 , F_72 ( V_37 -> V_35 ) . V_52 , V_53 , V_54 ,
V_1100 ) ;
if ( ! V_264 )
return - 1 ;
F_225 ( V_37 , V_264 , & V_41 ) ;
if ( F_33 ( V_56 , V_278 , V_7 -> V_1101 ) )
goto V_62;
if ( V_17 -> V_20 &&
F_33 ( V_56 , V_10 , V_17 -> V_20 -> V_21 ) )
goto V_62;
if ( F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) )
goto V_62;
V_1098 = F_50 ( V_56 , V_1102 ) ;
if ( ! V_1098 )
goto V_62;
if ( ( ! F_226 ( V_330 -> V_487 ) &&
F_54 ( V_56 , V_1103 , V_525 , V_330 -> V_487 ) ) )
goto V_62;
F_205 () ;
V_1097 = F_206 ( V_330 -> V_1097 ) ;
if ( V_1097 ) {
if ( F_105 ( V_56 , V_1104 , V_1097 -> V_1099 ) )
goto V_1105;
V_1099 = true ;
if ( V_1097 -> V_50 && F_54 ( V_56 , V_1106 ,
V_1097 -> V_50 , V_1097 -> V_132 ) )
goto V_1105;
}
V_1097 = F_206 ( V_330 -> V_618 ) ;
if ( V_1097 ) {
if ( ! V_1099 && F_105 ( V_56 , V_1104 , V_1097 -> V_1099 ) )
goto V_1105;
if ( V_1097 -> V_50 && F_54 ( V_56 , V_1107 ,
V_1097 -> V_50 , V_1097 -> V_132 ) )
goto V_1105;
}
F_207 () ;
if ( V_330 -> V_484 &&
F_57 ( V_56 , V_1108 , V_330 -> V_484 ) )
goto V_62;
if ( F_57 ( V_56 , V_1109 , V_330 -> V_841 ) ||
F_33 ( V_56 , V_1110 , V_330 -> V_664 -> V_61 ) ||
F_33 ( V_56 , V_1111 ,
F_227 ( V_1070 - V_1093 -> V_1112 ) ) )
goto V_62;
switch ( V_7 -> V_18 . V_738 ) {
case V_739 :
if ( F_33 ( V_56 , V_1113 , V_330 -> signal ) )
goto V_62;
break;
case V_1114 :
if ( F_58 ( V_56 , V_1115 , V_330 -> signal ) )
goto V_62;
break;
default:
break;
}
switch ( V_17 -> V_135 ) {
case V_144 :
case V_143 :
if ( V_1093 == V_17 -> V_141 &&
F_33 ( V_56 , V_1116 ,
V_1117 ) )
goto V_62;
break;
case V_140 :
if ( V_1093 == V_17 -> V_141 &&
F_33 ( V_56 , V_1116 ,
V_1118 ) )
goto V_62;
break;
default:
break;
}
F_51 ( V_56 , V_1098 ) ;
return F_67 ( V_56 , V_264 ) ;
V_1105:
F_207 () ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
static int F_228 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_6 * V_7 ;
struct V_1092 * V_1052 ;
struct V_1 * V_17 ;
int V_272 = V_37 -> args [ 2 ] , V_99 = 0 ;
int V_38 ;
V_38 = F_17 ( V_35 , V_37 , & V_7 , & V_17 ) ;
if ( V_38 )
return V_38 ;
F_113 ( V_17 ) ;
F_229 ( & V_7 -> V_1119 ) ;
F_230 ( V_7 ) ;
V_37 -> V_53 = V_7 -> V_1101 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_99 <= V_272 )
continue;
if ( F_224 ( V_35 , V_37 ,
V_37 -> V_39 -> V_445 , V_446 ,
V_7 , V_17 , V_1052 ) < 0 ) {
V_99 -- ;
break;
}
}
F_231 ( & V_7 -> V_1119 ) ;
F_115 ( V_17 ) ;
V_37 -> args [ 2 ] = V_99 ;
F_25 ( V_7 ) ;
return V_35 -> V_50 ;
}
static int F_232 ( struct V_34 * V_56 , V_23 V_52 , V_23 V_53 ,
int V_54 , struct V_26 * V_189 ,
struct V_1120 * V_1121 )
{
void * V_264 ;
struct V_4 * V_1122 ;
V_264 = F_30 ( V_56 , V_52 , V_53 , V_54 ,
V_1123 ) ;
if ( ! V_264 )
return - V_130 ;
if ( F_33 ( V_56 , V_10 , V_189 -> V_21 ) )
goto V_62;
V_1122 = F_50 ( V_56 , V_1124 ) ;
if ( ! V_1122 )
goto V_62;
if ( F_33 ( V_56 , V_1125 ,
V_1121 -> V_664 -> V_61 ) )
goto V_62;
if ( ( V_1121 -> V_712 & V_1126 ) &&
F_58 ( V_56 , V_1127 , V_1121 -> V_1128 ) )
goto V_62;
if ( ( V_1121 -> V_712 & V_1129 ) &&
F_34 ( V_56 , V_1130 ) )
goto V_62;
if ( ( V_1121 -> V_712 & V_1131 ) &&
F_105 ( V_56 , V_1132 ,
V_1121 -> V_1133 ) )
goto V_62;
if ( ( V_1121 -> V_712 & V_1134 ) &&
F_105 ( V_56 , V_1135 ,
V_1121 -> V_1136 ) )
goto V_62;
if ( ( V_1121 -> V_712 & V_1137 ) &&
F_105 ( V_56 , V_1138 ,
V_1121 -> V_1139 ) )
goto V_62;
if ( ( V_1121 -> V_712 & V_1140 ) &&
F_105 ( V_56 , V_1141 ,
V_1121 -> V_1142 ) )
goto V_62;
if ( ( V_1121 -> V_712 & V_1143 ) &&
F_105 ( V_56 , V_1144 ,
V_1121 -> V_1145 ) )
goto V_62;
F_51 ( V_56 , V_1122 ) ;
return F_67 ( V_56 , V_264 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
static int F_233 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_1120 V_1121 ;
struct V_6 * V_189 ;
struct V_1 * V_17 ;
int V_1146 = V_37 -> args [ 2 ] ;
int V_330 ;
V_330 = F_17 ( V_35 , V_37 , & V_189 , & V_17 ) ;
if ( V_330 )
return V_330 ;
if ( ! V_17 -> V_20 ) {
V_330 = - V_16 ;
goto V_794;
}
if ( ! V_189 -> V_326 -> V_1147 ) {
V_330 = - V_483 ;
goto V_794;
}
while ( 1 ) {
struct V_57 * V_58 ;
V_330 = F_234 ( V_189 , V_17 -> V_20 , V_1146 , & V_1121 ) ;
if ( V_330 == - V_583 )
break;
if ( V_330 )
goto V_794;
if ( ! V_1121 . V_664 ) {
V_330 = - V_16 ;
goto V_535;
}
V_58 = F_81 ( & V_189 -> V_18 ,
V_1121 . V_664 -> V_61 ) ;
if ( ! V_58 || V_58 -> V_54 & V_63 ) {
V_1146 ++ ;
continue;
}
if ( F_232 ( V_35 ,
F_72 ( V_37 -> V_35 ) . V_52 ,
V_37 -> V_39 -> V_445 , V_446 ,
V_17 -> V_20 , & V_1121 ) < 0 )
goto V_535;
V_1146 ++ ;
}
V_535:
V_37 -> args [ 2 ] = V_1146 ;
V_330 = V_35 -> V_50 ;
V_794:
F_25 ( V_189 ) ;
return V_330 ;
}
static bool F_235 ( V_23 V_1148 )
{
return ! ( V_1148 & ~ ( V_1149 |
V_1150 ) ) ;
}
static int F_236 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_57 * V_58 ;
const T_2 * V_487 , * V_530 , * V_1013 = NULL , * V_1151 = NULL ;
int V_38 , V_528 , V_1014 = 0 , V_1152 = 0 ;
enum V_628 V_629 ;
struct V_87 V_86 ;
bool V_1153 ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_649 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_468 ] )
return - V_16 ;
V_38 = F_41 ( V_31 , & V_86 ) ;
if ( V_38 )
return V_38 ;
if ( V_86 . V_99 >= 0 ) {
if ( V_86 . type != - 1 && V_86 . type != V_579 )
return - V_16 ;
if ( ! V_86 . V_101 . V_86 || ! V_86 . V_101 . V_102 )
return - V_16 ;
if ( ( V_86 . V_101 . V_106 != V_133 ||
V_86 . V_101 . V_102 != V_1154 ) &&
( V_86 . V_101 . V_106 != V_134 ||
V_86 . V_101 . V_102 != V_1155 ) )
return - V_16 ;
if ( V_86 . V_99 > 4 )
return - V_16 ;
} else {
V_86 . V_101 . V_102 = 0 ;
V_86 . V_101 . V_86 = NULL ;
}
if ( V_86 . V_99 >= 0 ) {
int V_149 ;
bool V_1156 = false ;
for ( V_149 = 0 ; V_149 < V_7 -> V_18 . V_313 ; V_149 ++ ) {
if ( V_86 . V_101 . V_106 == V_7 -> V_18 . V_314 [ V_149 ] ) {
V_1156 = true ;
break;
}
}
if ( ! V_1156 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_358 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_58 = F_81 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_468 ] ) ) ;
if ( ! V_58 || ( V_58 -> V_54 & V_63 ) )
return - V_16 ;
V_530 = F_28 ( V_31 -> V_5 [ V_529 ] ) ;
V_528 = F_29 ( V_31 -> V_5 [ V_529 ] ) ;
if ( V_31 -> V_5 [ V_610 ] ) {
V_1013 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
}
V_629 = F_4 ( V_31 -> V_5 [ V_649 ] ) ;
if ( ! F_146 ( V_7 , V_629 , V_632 ) )
return - V_16 ;
if ( V_629 == V_634 &&
! V_31 -> V_5 [ V_1157 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_1157 ] ) {
if ( V_629 != V_634 )
return - V_16 ;
V_1151 = F_28 ( V_31 -> V_5 [ V_1157 ] ) ;
V_1152 = F_29 ( V_31 -> V_5 [ V_1157 ] ) ;
if ( V_1152 < 4 )
return - V_16 ;
}
V_1153 = ! ! V_31 -> V_5 [ V_1158 ] ;
if ( V_1153 )
return 0 ;
return F_237 ( V_7 , V_189 , V_58 , V_629 , V_487 ,
V_530 , V_528 , V_1013 , V_1014 ,
V_86 . V_101 . V_86 , V_86 . V_101 . V_102 , V_86 . V_99 ,
V_1151 , V_1152 ) ;
}
static int F_149 ( struct V_6 * V_7 ,
struct V_30 * V_31 ,
struct V_1159 * V_1160 ,
int V_1161 )
{
memset ( V_1160 , 0 , sizeof( * V_1160 ) ) ;
V_1160 -> V_1162 = V_31 -> V_5 [ V_1163 ] ;
if ( V_31 -> V_5 [ V_318 ] ) {
T_3 V_1164 ;
V_1164 = F_78 (
V_31 -> V_5 [ V_318 ] ) ;
V_1160 -> V_1165 = F_238 ( V_1164 ) ;
if ( ! ( V_7 -> V_18 . V_54 & V_317 ) &&
V_1164 != V_1166 )
return - V_16 ;
if ( V_31 -> V_5 [ V_1167 ] )
V_1160 -> V_1168 = true ;
} else
V_1160 -> V_1165 = F_238 ( V_1166 ) ;
if ( V_31 -> V_5 [ V_1169 ] ) {
void * V_132 ;
int V_50 , V_149 ;
V_132 = F_28 ( V_31 -> V_5 [ V_1169 ] ) ;
V_50 = F_29 ( V_31 -> V_5 [ V_1169 ] ) ;
V_1160 -> V_1170 = V_50 / sizeof( V_23 ) ;
if ( V_50 % sizeof( V_23 ) )
return - V_16 ;
if ( V_1160 -> V_1170 > V_1161 )
return - V_16 ;
memcpy ( V_1160 -> V_1171 , V_132 , V_50 ) ;
for ( V_149 = 0 ; V_149 < V_1160 -> V_1170 ; V_149 ++ )
if ( ! F_239 (
& V_7 -> V_18 ,
V_1160 -> V_1171 [ V_149 ] ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1172 ] ) {
V_1160 -> V_1173 =
F_4 ( V_31 -> V_5 [ V_1172 ] ) ;
if ( ! F_239 ( & V_7 -> V_18 ,
V_1160 -> V_1173 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1174 ] ) {
V_1160 -> V_1148 =
F_4 ( V_31 -> V_5 [ V_1174 ] ) ;
if ( ! F_235 ( V_1160 -> V_1148 ) )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1175 ] ) {
void * V_132 ;
int V_50 ;
V_132 = F_28 ( V_31 -> V_5 [ V_1175 ] ) ;
V_50 = F_29 ( V_31 -> V_5 [ V_1175 ] ) ;
V_1160 -> V_1176 = V_50 / sizeof( V_23 ) ;
if ( V_50 % sizeof( V_23 ) )
return - V_16 ;
if ( V_1160 -> V_1176 > V_1177 )
return - V_16 ;
memcpy ( V_1160 -> V_1178 , V_132 , V_50 ) ;
}
return 0 ;
}
static int F_240 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_57 * V_58 ;
struct V_1179 V_1180 = {} ;
const T_2 * V_487 , * V_530 ;
int V_38 , V_528 = 0 ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_488 ] ||
! V_31 -> V_5 [ V_529 ] ||
! V_31 -> V_5 [ V_468 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_360 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_58 = F_81 ( & V_7 -> V_18 ,
F_4 ( V_31 -> V_5 [ V_468 ] ) ) ;
if ( ! V_58 || ( V_58 -> V_54 & V_63 ) )
return - V_16 ;
V_530 = F_28 ( V_31 -> V_5 [ V_529 ] ) ;
V_528 = F_29 ( V_31 -> V_5 [ V_529 ] ) ;
if ( V_31 -> V_5 [ V_610 ] ) {
V_1180 . V_1013 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_1180 . V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
}
if ( V_31 -> V_5 [ V_1181 ] ) {
enum V_1182 V_1183 =
F_4 ( V_31 -> V_5 [ V_1181 ] ) ;
if ( V_1183 == V_1184 )
V_1180 . V_1185 = true ;
else if ( V_1183 != V_1186 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_1187 ] )
V_1180 . V_1188 = F_28 ( V_31 -> V_5 [ V_1187 ] ) ;
if ( F_200 ( V_31 -> V_5 [ V_1189 ] ) )
V_1180 . V_54 |= V_1190 ;
if ( V_31 -> V_5 [ V_430 ] )
memcpy ( & V_1180 . V_1191 ,
F_28 ( V_31 -> V_5 [ V_430 ] ) ,
sizeof( V_1180 . V_1191 ) ) ;
if ( V_31 -> V_5 [ V_834 ] ) {
if ( ! V_31 -> V_5 [ V_430 ] )
return - V_16 ;
memcpy ( & V_1180 . V_813 ,
F_28 ( V_31 -> V_5 [ V_834 ] ) ,
sizeof( V_1180 . V_813 ) ) ;
}
if ( F_200 ( V_31 -> V_5 [ V_1192 ] ) )
V_1180 . V_54 |= V_1193 ;
if ( V_31 -> V_5 [ V_439 ] )
memcpy ( & V_1180 . V_1194 ,
F_28 ( V_31 -> V_5 [ V_439 ] ) ,
sizeof( V_1180 . V_1194 ) ) ;
if ( V_31 -> V_5 [ V_835 ] ) {
if ( ! V_31 -> V_5 [ V_439 ] )
return - V_16 ;
memcpy ( & V_1180 . V_814 ,
F_28 ( V_31 -> V_5 [ V_835 ] ) ,
sizeof( V_1180 . V_814 ) ) ;
}
V_38 = F_149 ( V_7 , V_31 , & V_1180 . V_651 , 1 ) ;
if ( ! V_38 )
V_38 = F_241 ( V_7 , V_189 , V_58 , V_487 ,
V_530 , V_528 , & V_1180 ) ;
return V_38 ;
}
static int F_242 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
const T_2 * V_1013 = NULL , * V_487 ;
int V_1014 = 0 ;
T_3 V_1195 ;
bool V_1153 ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1196 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_362 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_1195 = F_78 ( V_31 -> V_5 [ V_1196 ] ) ;
if ( V_1195 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_610 ] ) {
V_1013 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
}
V_1153 = ! ! V_31 -> V_5 [ V_1158 ] ;
return F_243 ( V_7 , V_189 , V_487 , V_1013 , V_1014 , V_1195 ,
V_1153 ) ;
}
static int F_244 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
const T_2 * V_1013 = NULL , * V_487 ;
int V_1014 = 0 ;
T_3 V_1195 ;
bool V_1153 ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1196 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_364 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_1195 = F_78 ( V_31 -> V_5 [ V_1196 ] ) ;
if ( V_1195 == 0 ) {
return - V_16 ;
}
if ( V_31 -> V_5 [ V_610 ] ) {
V_1013 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
}
V_1153 = ! ! V_31 -> V_5 [ V_1158 ] ;
return F_245 ( V_7 , V_189 , V_487 , V_1013 , V_1014 , V_1195 ,
V_1153 ) ;
}
static bool
F_246 ( struct V_6 * V_7 ,
int V_1197 [ V_336 ] ,
int V_1198 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_28 = false ;
int V_271 , V_149 ;
for ( V_271 = 0 ; V_271 < V_336 ; V_271 ++ ) {
struct V_218 * V_219 ;
V_219 = V_18 -> V_337 [ V_271 ] ;
if ( ! V_219 )
continue;
for ( V_149 = 0 ; V_149 < V_219 -> V_240 ; V_149 ++ ) {
if ( V_219 -> V_241 [ V_149 ] . V_243 == V_1198 ) {
V_1197 [ V_271 ] = V_149 + 1 ;
V_28 = true ;
break;
}
}
}
return V_28 ;
}
static int F_247 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1199 V_1200 ;
struct V_18 * V_18 ;
struct V_124 * V_1201 = NULL ;
int V_38 ;
memset ( & V_1200 , 0 , sizeof( V_1200 ) ) ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_529 ] ||
! F_29 ( V_31 -> V_5 [ V_529 ] ) )
return - V_16 ;
V_1200 . V_484 = 100 ;
if ( V_31 -> V_5 [ V_638 ] ) {
V_1200 . V_484 =
F_4 ( V_31 -> V_5 [ V_638 ] ) ;
if ( V_1200 . V_484 < 1 || V_1200 . V_484 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_326 -> V_366 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_140 )
return - V_483 ;
V_18 = & V_7 -> V_18 ;
if ( V_31 -> V_5 [ V_488 ] ) {
V_1200 . V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( ! F_119 ( V_1200 . V_487 ) )
return - V_16 ;
}
V_1200 . V_530 = F_28 ( V_31 -> V_5 [ V_529 ] ) ;
V_1200 . V_528 = F_29 ( V_31 -> V_5 [ V_529 ] ) ;
if ( V_31 -> V_5 [ V_610 ] ) {
V_1200 . V_1013 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_1200 . V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
}
V_38 = F_80 ( V_7 , V_31 , & V_1200 . V_466 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_86 ( & V_7 -> V_18 , & V_1200 . V_466 ) )
return - V_16 ;
if ( V_1200 . V_466 . V_469 > V_520 )
return - V_16 ;
if ( V_1200 . V_466 . V_469 != V_470 &&
! ( V_7 -> V_18 . V_275 & V_1202 ) )
return - V_16 ;
V_1200 . V_1203 = ! ! V_31 -> V_5 [ V_1204 ] ;
V_1200 . V_647 = ! ! V_31 -> V_5 [ V_648 ] ;
if ( V_31 -> V_5 [ V_898 ] ) {
T_2 * V_1060 =
F_28 ( V_31 -> V_5 [ V_898 ] ) ;
int V_1205 =
F_29 ( V_31 -> V_5 [ V_898 ] ) ;
struct V_218 * V_219 =
V_18 -> V_337 [ V_1200 . V_466 . V_58 -> V_271 ] ;
V_38 = F_214 ( V_219 , V_1060 , V_1205 ,
& V_1200 . V_899 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_31 -> V_5 [ V_1206 ] &&
! F_246 ( V_7 , V_1200 . V_1197 ,
F_4 ( V_31 -> V_5 [ V_1206 ] ) ) )
return - V_16 ;
if ( V_1200 . V_647 && V_31 -> V_5 [ V_1207 ] ) {
bool V_126 = false ;
V_1201 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1207 ] ,
& V_126 ) ;
if ( F_16 ( V_1201 ) )
return F_21 ( V_1201 ) ;
if ( ( V_1200 . V_466 . V_469 != V_470 ) &&
V_126 ) {
F_46 ( V_1201 ) ;
return - V_16 ;
}
}
V_1200 . V_1162 =
F_200 ( V_31 -> V_5 [ V_1163 ] ) ;
V_38 = F_248 ( V_7 , V_189 , & V_1200 , V_1201 ) ;
if ( V_38 )
F_46 ( V_1201 ) ;
return V_38 ;
}
static int F_249 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_1208 )
return - V_483 ;
if ( V_189 -> V_29 -> V_135 != V_140 )
return - V_483 ;
return F_250 ( V_7 , V_189 , false ) ;
}
static int F_251 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
int V_1197 [ V_336 ] ;
V_23 V_1209 ;
int V_38 ;
if ( V_189 -> V_29 -> V_135 != V_140 &&
V_189 -> V_29 -> V_135 != V_139 )
return - V_483 ;
if ( ! V_7 -> V_326 -> V_406 )
return - V_483 ;
memset ( V_1197 , 0 , sizeof( V_1197 ) ) ;
if ( ! V_31 -> V_5 [ V_1206 ] )
return - V_16 ;
V_1209 = F_4 ( V_31 -> V_5 [ V_1206 ] ) ;
if ( ! F_246 ( V_7 , V_1197 , V_1209 ) )
return - V_16 ;
V_38 = V_7 -> V_326 -> V_406 ( & V_7 -> V_18 , V_189 , V_1197 ) ;
return V_38 ;
}
static int F_252 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int V_38 ;
if ( ! V_31 -> V_5 [ V_1210 ] )
return - V_16 ;
V_38 = - V_483 ;
if ( V_7 -> V_326 -> V_412 ) {
V_7 -> V_1211 = V_31 ;
V_38 = F_253 ( V_7 ,
F_28 ( V_31 -> V_5 [ V_1210 ] ) ,
F_29 ( V_31 -> V_5 [ V_1210 ] ) ) ;
V_7 -> V_1211 = NULL ;
}
return V_38 ;
}
static int F_254 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_6 * V_7 ;
int V_38 ;
long V_1212 ;
void * V_132 = NULL ;
int V_1213 = 0 ;
if ( V_37 -> args [ 0 ] ) {
V_1212 = V_37 -> args [ 0 ] - 1 ;
} else {
V_38 = F_19 ( V_37 -> V_39 , V_40 + V_41 . V_42 ,
V_41 . V_43 , V_41 . V_44 ,
V_45 ) ;
if ( V_38 )
return V_38 ;
F_8 ( & V_32 ) ;
V_7 = F_10 ( F_20 ( V_35 -> V_47 ) ,
V_41 . V_43 ) ;
if ( F_16 ( V_7 ) ) {
F_9 ( & V_32 ) ;
return F_21 ( V_7 ) ;
}
V_1212 = V_7 -> V_14 ;
V_7 = NULL ;
F_9 ( & V_32 ) ;
if ( V_41 . V_43 [ V_1210 ] )
V_37 -> args [ 1 ] =
( long ) V_41 . V_43 [ V_1210 ] ;
}
if ( V_37 -> args [ 1 ] ) {
V_132 = F_28 ( ( void * ) V_37 -> args [ 1 ] ) ;
V_1213 = F_29 ( ( void * ) V_37 -> args [ 1 ] ) ;
}
F_8 ( & V_32 ) ;
V_7 = F_11 ( V_1212 ) ;
if ( ! V_7 ) {
F_9 ( & V_32 ) ;
return - V_583 ;
}
F_23 ( V_7 ) ;
F_9 ( & V_32 ) ;
if ( ! V_7 -> V_326 -> V_1214 ) {
V_38 = - V_483 ;
goto V_794;
}
while ( 1 ) {
void * V_264 = F_30 ( V_35 , F_72 ( V_37 -> V_35 ) . V_52 ,
V_37 -> V_39 -> V_445 , V_446 ,
V_1215 ) ;
struct V_4 * V_1216 ;
if ( F_33 ( V_35 , V_27 , V_1212 ) ) {
F_68 ( V_35 , V_264 ) ;
break;
}
V_1216 = F_50 ( V_35 , V_1210 ) ;
if ( ! V_1216 ) {
F_68 ( V_35 , V_264 ) ;
break;
}
V_38 = F_255 ( V_7 , V_35 , V_37 , V_132 , V_1213 ) ;
F_51 ( V_35 , V_1216 ) ;
if ( V_38 == - V_85 || V_38 == - V_583 ) {
F_68 ( V_35 , V_264 ) ;
break;
} else if ( V_38 ) {
F_68 ( V_35 , V_264 ) ;
goto V_794;
}
F_67 ( V_35 , V_264 ) ;
}
V_38 = V_35 -> V_50 ;
V_37 -> args [ 0 ] = V_1212 + 1 ;
V_794:
F_26 ( V_7 ) ;
return V_38 ;
}
static struct V_34 *
F_256 ( struct V_6 * V_7 ,
int V_1217 , V_23 V_52 , V_23 V_53 , T_11 V_1218 )
{
struct V_34 * V_35 ;
void * V_264 ;
struct V_4 * V_132 ;
V_35 = F_74 ( V_1217 + 100 , V_1218 ) ;
if ( ! V_35 )
return NULL ;
V_264 = F_30 ( V_35 , V_52 , V_53 , 0 , V_1215 ) ;
if ( ! V_264 ) {
F_257 ( V_35 ) ;
return NULL ;
}
if ( F_33 ( V_35 , V_27 , V_7 -> V_14 ) )
goto V_62;
V_132 = F_50 ( V_35 , V_1210 ) ;
( ( void * * ) V_35 -> V_37 ) [ 0 ] = V_7 ;
( ( void * * ) V_35 -> V_37 ) [ 1 ] = V_264 ;
( ( void * * ) V_35 -> V_37 ) [ 2 ] = V_132 ;
return V_35 ;
V_62:
F_257 ( V_35 ) ;
return NULL ;
}
struct V_34 * F_258 ( struct V_18 * V_18 ,
int V_1217 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
if ( F_102 ( ! V_7 -> V_1211 ) )
return NULL ;
return F_256 ( V_7 , V_1217 ,
V_7 -> V_1211 -> V_449 ,
V_7 -> V_1211 -> V_450 ,
V_129 ) ;
}
int F_259 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = ( ( void * * ) V_35 -> V_37 ) [ 0 ] ;
void * V_264 = ( ( void * * ) V_35 -> V_37 ) [ 1 ] ;
struct V_4 * V_132 = ( ( void * * ) V_35 -> V_37 ) [ 2 ] ;
if ( F_102 ( ! V_7 -> V_1211 ) ) {
F_257 ( V_35 ) ;
return - V_16 ;
}
F_51 ( V_35 , V_132 ) ;
F_67 ( V_35 , V_264 ) ;
return F_76 ( V_35 , V_7 -> V_1211 ) ;
}
struct V_34 * F_260 ( struct V_18 * V_18 ,
int V_1217 , T_11 V_1218 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
return F_256 ( V_7 , V_1217 , 0 , 0 , V_1218 ) ;
}
void F_261 ( struct V_34 * V_35 , T_11 V_1218 )
{
void * V_264 = ( ( void * * ) V_35 -> V_37 ) [ 1 ] ;
struct V_4 * V_132 = ( ( void * * ) V_35 -> V_37 ) [ 2 ] ;
F_51 ( V_35 , V_132 ) ;
F_67 ( V_35 , V_264 ) ;
F_262 ( V_35 , 0 , V_1219 . V_1220 , V_1218 ) ;
}
static int F_263 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1221 V_414 ;
struct V_18 * V_18 ;
struct V_124 * V_1201 = NULL ;
int V_38 ;
memset ( & V_414 , 0 , sizeof( V_414 ) ) ;
if ( ! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_529 ] ||
! F_29 ( V_31 -> V_5 [ V_529 ] ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_649 ] ) {
V_414 . V_629 =
F_4 ( V_31 -> V_5 [ V_649 ] ) ;
if ( ! F_146 ( V_7 , V_414 . V_629 ,
V_415 ) )
return - V_16 ;
} else
V_414 . V_629 = V_650 ;
V_414 . V_647 = V_31 -> V_5 [ V_648 ] ;
V_38 = F_149 ( V_7 , V_31 , & V_414 . V_651 ,
V_652 ) ;
if ( V_38 )
return V_38 ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
V_18 = & V_7 -> V_18 ;
V_414 . V_1222 = - 1 ;
if ( V_31 -> V_5 [ V_1223 ] &&
( V_18 -> V_54 & V_306 ) ) {
V_414 . V_1222 =
F_78 ( V_31 -> V_5 [ V_1223 ] ) ;
}
if ( V_31 -> V_5 [ V_488 ] )
V_414 . V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_414 . V_530 = F_28 ( V_31 -> V_5 [ V_529 ] ) ;
V_414 . V_528 = F_29 ( V_31 -> V_5 [ V_529 ] ) ;
if ( V_31 -> V_5 [ V_610 ] ) {
V_414 . V_1013 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_414 . V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
}
if ( V_31 -> V_5 [ V_1181 ] ) {
V_414 . V_1183 = F_4 ( V_31 -> V_5 [ V_1181 ] ) ;
if ( V_414 . V_1183 != V_1184 &&
V_414 . V_1183 != V_1186 )
return - V_16 ;
} else {
V_414 . V_1183 = V_1186 ;
}
if ( V_31 -> V_5 [ V_468 ] ) {
V_414 . V_664 =
F_81 ( V_18 ,
F_4 ( V_31 -> V_5 [ V_468 ] ) ) ;
if ( ! V_414 . V_664 ||
V_414 . V_664 -> V_54 & V_63 )
return - V_16 ;
}
if ( V_414 . V_647 && V_31 -> V_5 [ V_1207 ] ) {
V_1201 = F_42 ( V_7 ,
V_31 -> V_5 [ V_1207 ] , NULL ) ;
if ( F_16 ( V_1201 ) )
return F_21 ( V_1201 ) ;
}
if ( F_200 ( V_31 -> V_5 [ V_1189 ] ) )
V_414 . V_54 |= V_1190 ;
if ( V_31 -> V_5 [ V_430 ] )
memcpy ( & V_414 . V_1191 ,
F_28 ( V_31 -> V_5 [ V_430 ] ) ,
sizeof( V_414 . V_1191 ) ) ;
if ( V_31 -> V_5 [ V_834 ] ) {
if ( ! V_31 -> V_5 [ V_430 ] ) {
F_46 ( V_1201 ) ;
return - V_16 ;
}
memcpy ( & V_414 . V_813 ,
F_28 ( V_31 -> V_5 [ V_834 ] ) ,
sizeof( V_414 . V_813 ) ) ;
}
if ( F_200 ( V_31 -> V_5 [ V_1192 ] ) )
V_414 . V_54 |= V_1193 ;
if ( V_31 -> V_5 [ V_439 ] )
memcpy ( & V_414 . V_1194 ,
F_28 ( V_31 -> V_5 [ V_439 ] ) ,
sizeof( V_414 . V_1194 ) ) ;
if ( V_31 -> V_5 [ V_835 ] ) {
if ( ! V_31 -> V_5 [ V_439 ] ) {
F_46 ( V_1201 ) ;
return - V_16 ;
}
memcpy ( & V_414 . V_814 ,
F_28 ( V_31 -> V_5 [ V_835 ] ) ,
sizeof( V_414 . V_814 ) ) ;
}
V_38 = F_264 ( V_7 , V_189 , & V_414 , V_1201 ) ;
if ( V_38 )
F_46 ( V_1201 ) ;
return V_38 ;
}
static int F_265 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_3 V_1224 ;
if ( ! V_31 -> V_5 [ V_1196 ] )
V_1224 = V_1225 ;
else
V_1224 = F_78 ( V_31 -> V_5 [ V_1196 ] ) ;
if ( V_1224 == 0 )
return - V_16 ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
return F_266 ( V_7 , V_189 , V_1224 , true ) ;
}
static int F_267 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_2 * V_2 ;
int V_38 ;
V_23 V_1226 ;
if ( ! V_31 -> V_5 [ V_1227 ] )
return - V_16 ;
V_1226 = F_4 ( V_31 -> V_5 [ V_1227 ] ) ;
V_2 = F_268 ( V_1226 ) ;
if ( F_16 ( V_2 ) )
return F_21 ( V_2 ) ;
V_38 = 0 ;
if ( ! F_71 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_38 = F_269 ( V_7 , V_2 ) ;
F_270 ( V_2 ) ;
return V_38 ;
}
static int F_271 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
int (* F_272)( struct V_18 * V_18 , struct V_26 * V_189 ,
struct V_1228 * V_1229 ) = NULL ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1228 V_1229 ;
memset ( & V_1229 , 0 , sizeof( struct V_1228 ) ) ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1230 ] )
return - V_16 ;
V_1229 . V_1231 = F_28 ( V_31 -> V_5 [ V_1230 ] ) ;
V_1229 . V_487 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
switch ( V_31 -> V_1232 -> V_55 ) {
case V_1233 :
F_272 = V_7 -> V_326 -> V_370 ;
break;
case V_1234 :
F_272 = V_7 -> V_326 -> V_372 ;
break;
default:
F_102 ( 1 ) ;
break;
}
if ( ! F_272 )
return - V_483 ;
return F_272 ( & V_7 -> V_18 , V_189 , & V_1229 ) ;
}
static int F_273 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
if ( V_189 -> V_29 -> V_135 != V_143 &&
V_189 -> V_29 -> V_135 != V_144 )
return - V_483 ;
if ( ! V_7 -> V_326 -> V_374 )
return - V_483 ;
return F_274 ( V_7 , V_189 ) ;
}
static int F_275 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 V_1235 , V_1236 ;
T_3 V_1237 ;
T_2 * V_1238 ;
if ( ! ( V_7 -> V_18 . V_54 & V_308 ) ||
! V_7 -> V_326 -> V_391 )
return - V_483 ;
if ( ! V_31 -> V_5 [ V_1239 ] ||
! V_31 -> V_5 [ V_1240 ] ||
! V_31 -> V_5 [ V_1241 ] ||
! V_31 -> V_5 [ V_610 ] ||
! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
V_1238 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_1235 = F_39 ( V_31 -> V_5 [ V_1239 ] ) ;
V_1237 = F_78 ( V_31 -> V_5 [ V_1240 ] ) ;
V_1236 = F_39 ( V_31 -> V_5 [ V_1241 ] ) ;
return F_276 ( V_7 , V_189 , V_1238 , V_1235 ,
V_1236 , V_1237 ,
F_28 ( V_31 -> V_5 [ V_610 ] ) ,
F_29 ( V_31 -> V_5 [ V_610 ] ) ) ;
}
static int F_277 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
enum V_1242 V_1243 ;
T_2 * V_1238 ;
if ( ! ( V_7 -> V_18 . V_54 & V_308 ) ||
! V_7 -> V_326 -> V_393 )
return - V_483 ;
if ( ! V_31 -> V_5 [ V_1244 ] ||
! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
V_1243 = F_39 ( V_31 -> V_5 [ V_1244 ] ) ;
V_1238 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
return F_278 ( V_7 , V_189 , V_1238 , V_1243 ) ;
}
static int F_279 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
struct V_465 V_466 ;
struct V_34 * V_56 ;
void * V_264 ;
T_1 V_574 ;
V_23 V_1245 ;
int V_38 ;
if ( ! V_31 -> V_5 [ V_468 ] ||
! V_31 -> V_5 [ V_1246 ] )
return - V_16 ;
V_1245 = F_4 ( V_31 -> V_5 [ V_1246 ] ) ;
if ( ! V_7 -> V_326 -> V_377 ||
! ( V_7 -> V_18 . V_54 & V_376 ) )
return - V_483 ;
if ( V_1245 < V_1247 ||
V_1245 > V_7 -> V_18 . V_419 )
return - V_16 ;
V_38 = F_80 ( V_7 , V_31 , & V_466 ) ;
if ( V_38 )
return V_38 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_1248 ) ;
if ( F_16 ( V_264 ) ) {
V_38 = F_21 ( V_264 ) ;
goto V_584;
}
V_38 = F_280 ( V_7 , V_17 , V_466 . V_58 ,
V_1245 , & V_574 ) ;
if ( V_38 )
goto V_584;
if ( F_105 ( V_56 , V_1249 , V_574 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
V_62:
V_38 = - V_85 ;
V_584:
F_75 ( V_56 ) ;
return V_38 ;
}
static int F_281 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
T_1 V_574 ;
if ( ! V_31 -> V_5 [ V_1249 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_1250 )
return - V_483 ;
V_574 = F_5 ( V_31 -> V_5 [ V_1249 ] ) ;
return F_282 ( V_7 , V_17 , V_574 ) ;
}
static V_23 F_283 ( struct V_218 * V_219 ,
T_2 * V_1060 , T_2 V_1251 )
{
T_2 V_149 ;
V_23 V_672 = 0 ;
for ( V_149 = 0 ; V_149 < V_1251 ; V_149 ++ ) {
int V_223 = ( V_1060 [ V_149 ] & 0x7f ) * 5 ;
int V_1252 ;
for ( V_1252 = 0 ; V_1252 < V_219 -> V_240 ; V_1252 ++ ) {
struct V_222 * V_1253 =
& V_219 -> V_241 [ V_1252 ] ;
if ( V_223 == V_1253 -> V_243 ) {
V_672 |= 1 << V_1252 ;
break;
}
}
if ( V_1252 == V_219 -> V_240 )
return 0 ;
}
return V_672 ;
}
static bool F_284 ( struct V_218 * V_219 ,
T_2 * V_1060 , T_2 V_1251 ,
T_2 V_227 [ V_1254 ] )
{
T_2 V_149 ;
memset ( V_227 , 0 , V_1254 ) ;
for ( V_149 = 0 ; V_149 < V_1251 ; V_149 ++ ) {
int V_1252 , V_1255 ;
V_1252 = V_1060 [ V_149 ] / 8 ;
V_1255 = F_151 ( V_1060 [ V_149 ] % 8 ) ;
if ( ( V_1252 < 0 ) || ( V_1252 >= V_1254 ) )
return false ;
if ( V_219 -> V_224 . V_227 . V_1256 [ V_1252 ] & V_1255 )
V_227 [ V_1252 ] |= V_1255 ;
else
return false ;
}
return true ;
}
static int F_285 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_4 * V_89 [ V_1257 + 1 ] ;
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1258 V_672 ;
int V_128 , V_149 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_4 * V_1259 ;
struct V_218 * V_219 ;
if ( V_31 -> V_5 [ V_1260 ] == NULL )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_379 )
return - V_483 ;
memset ( & V_672 , 0 , sizeof( V_672 ) ) ;
for ( V_149 = 0 ; V_149 < V_336 ; V_149 ++ ) {
V_219 = V_7 -> V_18 . V_337 [ V_149 ] ;
V_672 . V_1261 [ V_149 ] . V_1262 =
V_219 ? ( 1 << V_219 -> V_240 ) - 1 : 0 ;
if ( V_219 )
memcpy ( V_672 . V_1261 [ V_149 ] . V_227 ,
V_219 -> V_224 . V_227 . V_1256 ,
sizeof( V_672 . V_1261 [ V_149 ] . V_227 ) ) ;
else
memset ( V_672 . V_1261 [ V_149 ] . V_227 , 0 ,
sizeof( V_672 . V_1261 [ V_149 ] . V_227 ) ) ;
}
F_114 ( V_1263 > V_1254 * 8 ) ;
F_44 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem)
{
enum V_270 V_271 = F_213 ( V_1259 ) ;
if ( V_271 < 0 || V_271 >= V_336 )
return - V_16 ;
V_219 = V_7 -> V_18 . V_337 [ V_271 ] ;
if ( V_219 == NULL )
return - V_16 ;
F_96 ( V_89 , V_1257 , F_28 ( V_1259 ) ,
F_29 ( V_1259 ) , V_1264 ) ;
if ( V_89 [ V_1265 ] ) {
V_672 . V_1261 [ V_271 ] . V_1262 = F_283 (
V_219 ,
F_28 ( V_89 [ V_1265 ] ) ,
F_29 ( V_89 [ V_1265 ] ) ) ;
if ( ( V_672 . V_1261 [ V_271 ] . V_1262 == 0 ) &&
F_29 ( V_89 [ V_1265 ] ) )
return - V_16 ;
}
if ( V_89 [ V_1266 ] ) {
if ( ! F_284 (
V_219 ,
F_28 ( V_89 [ V_1266 ] ) ,
F_29 ( V_89 [ V_1266 ] ) ,
V_672 . V_1261 [ V_271 ] . V_227 ) )
return - V_16 ;
}
if ( V_672 . V_1261 [ V_271 ] . V_1262 == 0 ) {
if ( ! V_7 -> V_18 . V_337 [ V_271 ] -> V_224 . V_225 )
return - V_16 ;
for ( V_149 = 0 ; V_149 < V_1254 ; V_149 ++ )
if ( V_672 . V_1261 [ V_271 ] . V_227 [ V_149 ] )
break;
if ( V_149 == V_1254 )
return - V_16 ;
}
}
return F_286 ( V_7 , V_189 , NULL , & V_672 ) ;
}
static int F_287 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
T_3 V_1267 = V_257 | V_1268 ;
if ( ! V_31 -> V_5 [ V_1269 ] )
return - V_16 ;
if ( V_31 -> V_5 [ V_256 ] )
V_1267 = F_78 ( V_31 -> V_5 [ V_256 ] ) ;
switch ( V_17 -> V_135 ) {
case V_143 :
case V_140 :
case V_144 :
case V_136 :
case V_137 :
case V_139 :
case V_138 :
case V_560 :
break;
default:
return - V_483 ;
}
if ( ! V_7 -> V_326 -> V_381 )
return - V_483 ;
return F_288 ( V_17 , V_31 -> V_449 , V_1267 ,
F_28 ( V_31 -> V_5 [ V_1269 ] ) ,
F_29 ( V_31 -> V_5 [ V_1269 ] ) ) ;
}
static int F_289 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
struct V_465 V_466 ;
int V_38 ;
void * V_264 = NULL ;
T_1 V_574 ;
struct V_34 * V_56 = NULL ;
unsigned int V_1270 = 0 ;
bool V_1271 , V_1067 , V_1272 ;
V_1272 = V_31 -> V_5 [ V_1273 ] ;
if ( ! V_31 -> V_5 [ V_1274 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_381 )
return - V_483 ;
switch ( V_17 -> V_135 ) {
case V_143 :
case V_140 :
case V_144 :
case V_136 :
case V_137 :
case V_139 :
case V_138 :
case V_560 :
break;
default:
return - V_483 ;
}
if ( V_31 -> V_5 [ V_1246 ] ) {
if ( ! ( V_7 -> V_18 . V_54 & V_420 ) )
return - V_16 ;
V_1270 = F_4 ( V_31 -> V_5 [ V_1246 ] ) ;
if ( V_1270 < V_1247 ||
V_1270 > V_7 -> V_18 . V_419 )
return - V_16 ;
}
V_1271 = V_31 -> V_5 [ V_421 ] ;
if ( V_1271 && ! ( V_7 -> V_18 . V_54 & V_420 ) )
return - V_16 ;
V_1067 = F_200 ( V_31 -> V_5 [ V_1068 ] ) ;
V_38 = F_80 ( V_7 , V_31 , & V_466 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_1272 ) {
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_1275 ) ;
if ( F_16 ( V_264 ) ) {
V_38 = F_21 ( V_264 ) ;
goto V_584;
}
}
V_38 = F_290 ( V_7 , V_17 , V_466 . V_58 , V_1271 , V_1270 ,
F_28 ( V_31 -> V_5 [ V_1274 ] ) ,
F_29 ( V_31 -> V_5 [ V_1274 ] ) ,
V_1067 , V_1272 , & V_574 ) ;
if ( V_38 )
goto V_584;
if ( V_56 ) {
if ( F_105 ( V_56 , V_1249 , V_574 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
}
return 0 ;
V_62:
V_38 = - V_85 ;
V_584:
F_75 ( V_56 ) ;
return V_38 ;
}
static int F_291 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
T_1 V_574 ;
if ( ! V_31 -> V_5 [ V_1249 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_383 )
return - V_483 ;
switch ( V_17 -> V_135 ) {
case V_143 :
case V_140 :
case V_144 :
case V_136 :
case V_137 :
case V_138 :
case V_560 :
break;
default:
return - V_483 ;
}
V_574 = F_5 ( V_31 -> V_5 [ V_1249 ] ) ;
return F_292 ( V_7 , V_17 , V_574 ) ;
}
static int F_293 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
T_2 V_1276 ;
bool V_1277 ;
int V_38 ;
if ( ! V_31 -> V_5 [ V_1278 ] )
return - V_16 ;
V_1276 = F_4 ( V_31 -> V_5 [ V_1278 ] ) ;
if ( V_1276 != V_1279 && V_1276 != V_1280 )
return - V_16 ;
V_17 = V_189 -> V_29 ;
if ( ! V_7 -> V_326 -> V_1281 )
return - V_483 ;
V_1277 = ( V_1276 == V_1280 ) ? true : false ;
if ( V_1277 == V_17 -> V_1282 )
return 0 ;
V_38 = F_294 ( V_7 , V_189 , V_1277 , V_17 -> V_1283 ) ;
if ( ! V_38 )
V_17 -> V_1282 = V_1277 ;
return V_38 ;
}
static int F_295 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
enum V_1284 V_1276 ;
struct V_1 * V_17 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_34 * V_56 ;
void * V_264 ;
int V_38 ;
V_17 = V_189 -> V_29 ;
if ( ! V_7 -> V_326 -> V_1281 )
return - V_483 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_1285 ) ;
if ( ! V_264 ) {
V_38 = - V_85 ;
goto V_584;
}
if ( V_17 -> V_1282 )
V_1276 = V_1280 ;
else
V_1276 = V_1279 ;
if ( F_33 ( V_56 , V_1278 , V_1276 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
V_62:
V_38 = - V_85 ;
V_584:
F_75 ( V_56 ) ;
return V_38 ;
}
static int F_296 ( struct V_30 * V_31 ,
V_23 V_223 , V_23 V_1286 , V_23 V_1287 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
if ( V_223 > 100 || V_1287 > V_1288 )
return - V_16 ;
V_17 = V_189 -> V_29 ;
if ( ! V_7 -> V_326 -> V_1289 )
return - V_483 ;
if ( V_17 -> V_135 != V_143 &&
V_17 -> V_135 != V_144 )
return - V_483 ;
return F_297 ( V_7 , V_189 , V_223 , V_1286 , V_1287 ) ;
}
static int F_298 ( struct V_30 * V_31 ,
T_12 V_1290 , V_23 V_1291 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
if ( V_1290 > 0 )
return - V_16 ;
V_17 = V_189 -> V_29 ;
if ( ! V_7 -> V_326 -> V_1292 )
return - V_483 ;
if ( V_17 -> V_135 != V_143 &&
V_17 -> V_135 != V_144 )
return - V_483 ;
return F_299 ( V_7 , V_189 , V_1290 , V_1291 ) ;
}
static int F_300 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_4 * V_5 [ V_1293 + 1 ] ;
struct V_4 * V_1294 ;
int V_38 ;
V_1294 = V_31 -> V_5 [ V_1295 ] ;
if ( ! V_1294 ) {
V_38 = - V_16 ;
goto V_535;
}
V_38 = F_38 ( V_5 , V_1293 , V_1294 ,
V_1296 ) ;
if ( V_38 )
goto V_535;
if ( V_5 [ V_1297 ] &&
V_5 [ V_1298 ] ) {
T_12 V_1290 ;
V_23 V_1291 ;
V_1290 = F_4 ( V_5 [ V_1297 ] ) ;
V_1291 = F_4 ( V_5 [ V_1298 ] ) ;
V_38 = F_298 ( V_31 , V_1290 , V_1291 ) ;
} else if ( V_5 [ V_1299 ] &&
V_5 [ V_1300 ] &&
V_5 [ V_1301 ] ) {
V_23 V_223 , V_1286 , V_1287 ;
V_223 = F_4 ( V_5 [ V_1299 ] ) ;
V_1286 = F_4 ( V_5 [ V_1300 ] ) ;
V_1287 = F_4 ( V_5 [ V_1301 ] ) ;
V_38 = F_296 ( V_31 , V_223 , V_1286 , V_1287 ) ;
} else
V_38 = - V_16 ;
V_535:
return V_38 ;
}
static int F_301 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_929 V_989 ;
struct V_994 V_995 ;
int V_38 ;
memcpy ( & V_989 , & V_933 , sizeof( V_989 ) ) ;
memcpy ( & V_995 , & V_1302 , sizeof( V_995 ) ) ;
if ( V_31 -> V_5 [ V_935 ] ) {
V_38 = F_197 ( V_31 , & V_989 , NULL ) ;
if ( V_38 )
return V_38 ;
}
if ( ! V_31 -> V_5 [ V_553 ] ||
! F_29 ( V_31 -> V_5 [ V_553 ] ) )
return - V_16 ;
V_995 . V_1303 = F_28 ( V_31 -> V_5 [ V_553 ] ) ;
V_995 . V_932 = F_29 ( V_31 -> V_5 [ V_553 ] ) ;
if ( V_31 -> V_5 [ V_1206 ] &&
! F_246 ( V_7 , V_995 . V_1197 ,
F_4 ( V_31 -> V_5 [ V_1206 ] ) ) )
return - V_16 ;
if ( V_31 -> V_5 [ V_638 ] ) {
V_995 . V_484 =
F_4 ( V_31 -> V_5 [ V_638 ] ) ;
if ( V_995 . V_484 < 10 ||
V_995 . V_484 > 10000 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_639 ] ) {
V_995 . V_641 =
F_4 ( V_31 -> V_5 [ V_639 ] ) ;
if ( V_995 . V_641 < 1 || V_995 . V_641 > 100 )
return - V_16 ;
}
if ( V_31 -> V_5 [ V_997 ] ) {
V_38 = F_199 ( V_31 , & V_995 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_995 . V_1017 )
V_989 . V_951 = false ;
if ( V_31 -> V_5 [ V_468 ] ) {
V_38 = F_80 ( V_7 , V_31 , & V_995 . V_466 ) ;
if ( V_38 )
return V_38 ;
} else {
V_995 . V_466 . V_58 = NULL ;
}
return F_302 ( V_7 , V_189 , & V_995 , & V_989 ) ;
}
static int F_303 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
return F_304 ( V_7 , V_189 ) ;
}
static int F_305 ( struct V_34 * V_56 ,
struct V_6 * V_7 )
{
struct V_4 * V_1304 , * V_1305 ;
int V_149 , V_1306 ;
if ( ! V_7 -> V_177 -> V_191 )
return 0 ;
V_1304 = F_50 ( V_56 , V_217 ) ;
if ( ! V_1304 )
return - V_85 ;
for ( V_149 = 0 ; V_149 < V_7 -> V_177 -> V_191 ; V_149 ++ ) {
V_1305 = F_50 ( V_56 , V_149 + 1 ) ;
if ( ! V_1305 )
return - V_85 ;
V_1306 = V_7 -> V_177 -> V_1307 [ V_149 ] . V_1308 ;
if ( F_54 ( V_56 , V_1309 ,
F_306 ( V_1306 , 8 ) ,
V_7 -> V_177 -> V_1307 [ V_149 ] . V_672 ) ||
F_54 ( V_56 , V_1310 ,
V_1306 , V_7 -> V_177 -> V_1307 [ V_149 ] . V_1311 ) ||
F_33 ( V_56 , V_1312 ,
V_7 -> V_177 -> V_1307 [ V_149 ] . V_1313 ) )
return - V_85 ;
F_51 ( V_56 , V_1305 ) ;
}
F_51 ( V_56 , V_1304 ) ;
return 0 ;
}
static int F_307 ( struct V_34 * V_56 ,
struct V_1314 * V_176 )
{
struct V_4 * V_178 ;
if ( ! V_176 )
return 0 ;
V_178 = F_50 ( V_56 , V_179 ) ;
if ( ! V_178 )
return - V_85 ;
if ( F_308 ( V_56 , V_1315 , V_176 -> V_1316 ) ||
F_308 ( V_56 , V_1317 , V_176 -> V_857 ) ||
F_54 ( V_56 , V_1318 , V_525 , V_176 -> V_1319 ) ||
F_57 ( V_56 , V_1320 , V_176 -> V_1321 ) ||
F_57 ( V_56 , V_1322 , V_176 -> V_1323 ) ||
F_54 ( V_56 , V_180 ,
V_176 -> V_1324 , V_176 -> V_1325 ) ||
F_33 ( V_56 , V_185 ,
V_176 -> V_1326 ) ||
F_54 ( V_56 , V_187 ,
V_176 -> V_1327 , V_176 -> V_1328 ) ||
F_54 ( V_56 , V_1329 ,
F_306 ( V_176 -> V_1327 , 8 ) , V_176 -> V_1330 ) )
return - V_85 ;
if ( V_176 -> V_1331 . V_50 &&
F_54 ( V_56 , V_182 ,
sizeof( V_176 -> V_1331 ) , & V_176 -> V_1331 ) )
return - V_85 ;
if ( V_176 -> V_1332 . V_50 &&
F_54 ( V_56 , V_184 ,
sizeof( V_176 -> V_1332 ) + V_176 -> V_1333 ,
& V_176 -> V_1332 ) )
return - V_85 ;
F_51 ( V_56 , V_178 ) ;
return 0 ;
}
static int F_309 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_34 * V_56 ;
void * V_264 ;
V_23 V_1334 = V_536 ;
if ( ! V_7 -> V_18 . V_177 . V_54 && ! V_7 -> V_18 . V_177 . V_191 &&
! V_7 -> V_18 . V_177 . V_176 )
return - V_483 ;
if ( V_7 -> V_177 && V_7 -> V_177 -> V_176 ) {
V_1334 += V_7 -> V_177 -> V_176 -> V_1333 +
V_7 -> V_177 -> V_176 -> V_1324 +
V_7 -> V_177 -> V_176 -> V_1327 +
V_7 -> V_177 -> V_176 -> V_1327 / 8 ;
}
V_56 = F_74 ( V_1334 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_1335 ) ;
if ( ! V_264 )
goto V_62;
if ( V_7 -> V_177 ) {
struct V_4 * V_190 ;
V_190 = F_50 ( V_56 , V_1336 ) ;
if ( ! V_190 )
goto V_62;
if ( ( V_7 -> V_177 -> V_1337 &&
F_34 ( V_56 , V_194 ) ) ||
( V_7 -> V_177 -> V_416 &&
F_34 ( V_56 , V_196 ) ) ||
( V_7 -> V_177 -> V_1338 &&
F_34 ( V_56 , V_198 ) ) ||
( V_7 -> V_177 -> V_1339 &&
F_34 ( V_56 , V_202 ) ) ||
( V_7 -> V_177 -> V_1340 &&
F_34 ( V_56 , V_204 ) ) ||
( V_7 -> V_177 -> V_1341 &&
F_34 ( V_56 , V_206 ) ) ||
( V_7 -> V_177 -> V_1342 &&
F_34 ( V_56 , V_208 ) ) )
goto V_62;
if ( F_305 ( V_56 , V_7 ) )
goto V_62;
if ( F_307 ( V_56 , V_7 -> V_177 -> V_176 ) )
goto V_62;
F_51 ( V_56 , V_190 ) ;
}
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
V_62:
F_75 ( V_56 ) ;
return - V_85 ;
}
static int F_310 ( struct V_6 * V_7 ,
struct V_4 * V_48 ,
struct V_1343 * V_1344 )
{
struct V_4 * V_89 [ V_1345 ] ;
struct V_1314 * V_989 ;
struct V_1346 * V_183 = NULL ;
struct V_1347 * V_53 = NULL ;
V_23 V_1334 ;
V_23 V_1348 , V_1349 , V_1333 = 0 , V_1350 ;
int V_38 , V_1351 ;
if ( ! V_7 -> V_18 . V_177 . V_176 )
return - V_16 ;
V_38 = F_96 ( V_89 , V_1352 ,
F_28 ( V_48 ) , F_29 ( V_48 ) ,
V_1353 ) ;
if ( V_38 )
return V_38 ;
if ( ! V_89 [ V_1315 ] ||
! V_89 [ V_1317 ] ||
! V_89 [ V_1318 ] ||
! V_89 [ V_1322 ] ||
! V_89 [ V_180 ] ||
! V_89 [ V_185 ] ||
! V_89 [ V_187 ] ||
! V_89 [ V_1329 ] )
return - V_16 ;
V_1348 = F_29 ( V_89 [ V_180 ] ) ;
if ( V_1348 > V_7 -> V_18 . V_177 . V_176 -> V_181 )
return - V_16 ;
if ( F_4 ( V_89 [ V_185 ] ) >
V_7 -> V_18 . V_177 . V_176 -> V_186 ||
F_4 ( V_89 [ V_185 ] ) == 0 )
return - V_16 ;
V_1349 = F_29 ( V_89 [ V_187 ] ) ;
if ( V_1349 > V_7 -> V_18 . V_177 . V_176 -> V_188 )
return - V_16 ;
V_1350 = F_29 ( V_89 [ V_1329 ] ) ;
if ( V_1350 != F_306 ( V_1349 , 8 ) )
return - V_16 ;
if ( V_89 [ V_184 ] ) {
V_23 V_1354 = F_29 ( V_89 [ V_184 ] ) ;
V_183 = F_28 ( V_89 [ V_184 ] ) ;
V_1333 = V_1354 - sizeof( * V_183 ) ;
if ( ! V_183 -> V_50 || V_1333 % V_183 -> V_50 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_177 . V_176 -> V_183 )
return - V_16 ;
if ( V_183 -> V_50 > V_7 -> V_18 . V_177 . V_176 -> V_183 -> V_1355 )
return - V_16 ;
if ( V_183 -> V_50 < V_7 -> V_18 . V_177 . V_176 -> V_183 -> V_1356 )
return - V_16 ;
if ( V_1333 > V_7 -> V_18 . V_177 . V_176 -> V_183 -> V_1357 )
return - V_16 ;
if ( V_183 -> V_1358 + V_183 -> V_50 > V_1348 )
return - V_16 ;
}
if ( V_89 [ V_182 ] ) {
V_53 = F_28 ( V_89 [ V_182 ] ) ;
if ( ! V_7 -> V_18 . V_177 . V_176 -> V_53 )
return - V_16 ;
if ( V_53 -> V_50 == 0 || V_53 -> V_50 > 4 )
return - V_16 ;
if ( V_53 -> V_50 + V_53 -> V_1358 > V_1348 )
return - V_16 ;
}
V_1334 = sizeof( * V_989 ) ;
V_1334 += V_1348 ;
V_1334 += V_1349 + V_1350 ;
V_1334 += V_1333 ;
V_989 = F_43 ( V_1334 , V_129 ) ;
if ( ! V_989 )
return - V_130 ;
V_989 -> V_1316 = F_311 ( V_89 [ V_1315 ] ) ;
V_989 -> V_857 = F_311 ( V_89 [ V_1317 ] ) ;
memcpy ( V_989 -> V_1319 , F_28 ( V_89 [ V_1318 ] ) ,
V_525 ) ;
if ( V_89 [ V_1320 ] )
V_1351 = F_78 ( V_89 [ V_1320 ] ) ;
else
V_1351 = 0 ;
#ifdef F_312
V_38 = F_313 ( F_7 ( & V_7 -> V_18 ) , V_1359 , V_1360 ,
V_1361 , & V_989 -> V_1362 , 1 ) ;
if ( V_38 ) {
F_46 ( V_989 ) ;
return V_38 ;
}
if ( F_314 ( V_989 -> V_1362 -> V_47 , V_1351 ) ) {
F_315 ( V_989 -> V_1362 ) ;
F_46 ( V_989 ) ;
return - V_1363 ;
}
V_989 -> V_1321 = F_316 ( V_989 -> V_1362 -> V_47 ) -> V_1364 ;
#else
if ( ! V_1351 ) {
F_46 ( V_989 ) ;
return - V_16 ;
}
V_989 -> V_1321 = V_1351 ;
#endif
V_989 -> V_1323 = F_78 ( V_89 [ V_1322 ] ) ;
V_989 -> V_1324 = V_1348 ;
V_989 -> V_1325 = ( T_2 * ) V_989 + sizeof( * V_989 ) + V_1333 ;
memcpy ( ( void * ) V_989 -> V_1325 ,
F_28 ( V_89 [ V_180 ] ) ,
V_1348 ) ;
if ( V_53 )
V_989 -> V_1331 = * V_53 ;
V_989 -> V_1326 = F_4 ( V_89 [ V_185 ] ) ;
V_989 -> V_1327 = V_1349 ;
V_989 -> V_1328 = ( T_2 * ) V_989 + sizeof( * V_989 ) + V_1333 + V_1348 ;
memcpy ( ( void * ) V_989 -> V_1328 ,
F_28 ( V_89 [ V_187 ] ) ,
V_1349 ) ;
V_989 -> V_1330 = ( T_2 * ) V_989 + sizeof( * V_989 ) + V_1333 +
V_1348 + V_1349 ;
memcpy ( ( void * ) V_989 -> V_1330 ,
F_28 ( V_89 [ V_1329 ] ) ,
V_1350 ) ;
if ( V_183 ) {
V_989 -> V_1333 = V_1333 ;
memcpy ( & V_989 -> V_1332 , V_183 , sizeof( * V_183 ) + V_1333 ) ;
}
V_1344 -> V_176 = V_989 ;
return 0 ;
}
static int F_317 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_4 * V_89 [ V_1365 ] ;
struct V_1343 V_1366 = {} ;
struct V_1343 * V_1367 ;
struct V_1368 * V_177 = & V_7 -> V_18 . V_177 ;
int V_38 , V_149 ;
bool V_1369 = V_7 -> V_177 ;
if ( ! V_7 -> V_18 . V_177 . V_54 && ! V_7 -> V_18 . V_177 . V_191 &&
! V_7 -> V_18 . V_177 . V_176 )
return - V_483 ;
if ( ! V_31 -> V_5 [ V_1336 ] ) {
F_318 ( V_7 ) ;
V_7 -> V_177 = NULL ;
goto V_1370;
}
V_38 = F_96 ( V_89 , V_1371 ,
F_28 ( V_31 -> V_5 [ V_1336 ] ) ,
F_29 ( V_31 -> V_5 [ V_1336 ] ) ,
V_1372 ) ;
if ( V_38 )
return V_38 ;
if ( V_89 [ V_194 ] ) {
if ( ! ( V_177 -> V_54 & V_193 ) )
return - V_16 ;
V_1366 . V_1337 = true ;
}
if ( V_89 [ V_196 ] ) {
if ( ! ( V_177 -> V_54 & V_195 ) )
return - V_16 ;
V_1366 . V_416 = true ;
}
if ( V_89 [ V_198 ] ) {
if ( ! ( V_177 -> V_54 & V_197 ) )
return - V_16 ;
V_1366 . V_1338 = true ;
}
if ( V_89 [ V_200 ] )
return - V_16 ;
if ( V_89 [ V_202 ] ) {
if ( ! ( V_177 -> V_54 & V_201 ) )
return - V_16 ;
V_1366 . V_1339 = true ;
}
if ( V_89 [ V_204 ] ) {
if ( ! ( V_177 -> V_54 & V_203 ) )
return - V_16 ;
V_1366 . V_1340 = true ;
}
if ( V_89 [ V_206 ] ) {
if ( ! ( V_177 -> V_54 & V_205 ) )
return - V_16 ;
V_1366 . V_1341 = true ;
}
if ( V_89 [ V_208 ] ) {
if ( ! ( V_177 -> V_54 & V_207 ) )
return - V_16 ;
V_1366 . V_1342 = true ;
}
if ( V_89 [ V_217 ] ) {
struct V_4 * V_210 ;
int V_191 = 0 ;
int V_128 , V_1306 , V_1373 , V_1313 ;
struct V_4 * V_1374 [ V_1375 ] ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_191 ++ ;
if ( V_191 > V_177 -> V_191 )
return - V_16 ;
V_1366 . V_1307 = F_319 ( V_191 ,
sizeof( V_1366 . V_1307 [ 0 ] ) ,
V_129 ) ;
if ( ! V_1366 . V_1307 )
return - V_130 ;
V_1366 . V_191 = V_191 ;
V_149 = 0 ;
F_44 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
F_96 ( V_1374 , V_1376 ,
F_28 ( V_210 ) , F_29 ( V_210 ) , NULL ) ;
V_38 = - V_16 ;
if ( ! V_1374 [ V_1309 ] ||
! V_1374 [ V_1310 ] )
goto error;
V_1306 = F_29 ( V_1374 [ V_1310 ] ) ;
V_1373 = F_306 ( V_1306 , 8 ) ;
if ( F_29 ( V_1374 [ V_1309 ] ) !=
V_1373 )
goto error;
if ( V_1306 > V_177 -> V_215 ||
V_1306 < V_177 -> V_213 )
goto error;
if ( ! V_1374 [ V_1312 ] )
V_1313 = 0 ;
else
V_1313 = F_4 (
V_1374 [ V_1312 ] ) ;
if ( V_1313 > V_177 -> V_216 )
goto error;
V_1366 . V_1307 [ V_149 ] . V_1313 = V_1313 ;
V_1366 . V_1307 [ V_149 ] . V_672 =
F_70 ( V_1373 + V_1306 , V_129 ) ;
if ( ! V_1366 . V_1307 [ V_149 ] . V_672 ) {
V_38 = - V_130 ;
goto error;
}
V_1366 . V_1307 [ V_149 ] . V_1311 =
V_1366 . V_1307 [ V_149 ] . V_672 + V_1373 ;
memcpy ( V_1366 . V_1307 [ V_149 ] . V_672 ,
F_28 ( V_1374 [ V_1309 ] ) ,
V_1373 ) ;
V_1366 . V_1307 [ V_149 ] . V_1308 = V_1306 ;
memcpy ( V_1366 . V_1307 [ V_149 ] . V_1311 ,
F_28 ( V_1374 [ V_1310 ] ) ,
V_1306 ) ;
V_149 ++ ;
}
}
if ( V_89 [ V_179 ] ) {
V_38 = F_310 (
V_7 , V_89 [ V_179 ] ,
& V_1366 ) ;
if ( V_38 )
goto error;
}
V_1367 = F_320 ( & V_1366 , sizeof( V_1366 ) , V_129 ) ;
if ( ! V_1367 ) {
V_38 = - V_130 ;
goto error;
}
F_318 ( V_7 ) ;
V_7 -> V_177 = V_1367 ;
V_1370:
if ( V_7 -> V_326 -> V_1370 && V_1369 != ! ! V_7 -> V_177 )
F_321 ( V_7 , V_7 -> V_177 ) ;
return 0 ;
error:
for ( V_149 = 0 ; V_149 < V_1366 . V_191 ; V_149 ++ )
F_46 ( V_1366 . V_1307 [ V_149 ] . V_672 ) ;
F_46 ( V_1366 . V_1307 ) ;
if ( V_1366 . V_176 && V_1366 . V_176 -> V_1362 )
F_315 ( V_1366 . V_176 -> V_1362 ) ;
F_46 ( V_1366 . V_176 ) ;
return V_38 ;
}
static int F_322 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_4 * V_89 [ V_1377 ] ;
struct V_1378 V_1379 ;
int V_38 ;
if ( ! V_31 -> V_5 [ V_1380 ] )
return - V_16 ;
V_38 = F_96 ( V_89 , V_1381 ,
F_28 ( V_31 -> V_5 [ V_1380 ] ) ,
F_29 ( V_31 -> V_5 [ V_1380 ] ) ,
V_1382 ) ;
if ( V_38 )
return V_38 ;
if ( F_29 ( V_89 [ V_1383 ] ) != V_1384 )
return - V_1385 ;
if ( F_29 ( V_89 [ V_1386 ] ) != V_1387 )
return - V_1385 ;
if ( F_29 ( V_89 [ V_1388 ] ) != V_1389 )
return - V_1385 ;
memcpy ( V_1379 . V_1390 , F_28 ( V_89 [ V_1386 ] ) ,
V_1387 ) ;
memcpy ( V_1379 . V_1391 , F_28 ( V_89 [ V_1388 ] ) ,
V_1389 ) ;
memcpy ( V_1379 . V_1392 ,
F_28 ( V_89 [ V_1383 ] ) ,
V_1384 ) ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_141 ) {
V_38 = - V_1393 ;
goto V_535;
}
if ( ! V_7 -> V_326 -> V_1394 ) {
V_38 = - V_483 ;
goto V_535;
}
V_38 = F_323 ( V_7 , V_189 , & V_1379 ) ;
V_535:
F_115 ( V_17 ) ;
return V_38 ;
}
static int F_324 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
if ( V_17 -> V_135 != V_136 &&
V_17 -> V_135 != V_138 )
return - V_16 ;
if ( V_17 -> V_1395 )
return - V_485 ;
V_17 -> V_1395 = V_31 -> V_449 ;
return 0 ;
}
static int F_325 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_34 * V_56 ;
void * V_264 ;
const T_2 * V_604 ;
T_1 V_574 ;
int V_38 ;
if ( V_17 -> V_135 != V_136 &&
V_17 -> V_135 != V_138 )
return - V_483 ;
if ( ! V_31 -> V_5 [ V_488 ] )
return - V_16 ;
if ( ! V_7 -> V_326 -> V_398 )
return - V_483 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_1396 ) ;
if ( F_16 ( V_264 ) ) {
V_38 = F_21 ( V_264 ) ;
goto V_584;
}
V_604 = F_28 ( V_31 -> V_5 [ V_488 ] ) ;
V_38 = F_326 ( V_7 , V_189 , V_604 , & V_574 ) ;
if ( V_38 )
goto V_584;
if ( F_105 ( V_56 , V_1249 , V_574 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
V_62:
V_38 = - V_85 ;
V_584:
F_75 ( V_56 ) ;
return V_38 ;
}
static int F_327 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1397 * V_1398 , * V_1399 ;
int V_1400 ;
if ( ! ( V_7 -> V_18 . V_54 & V_402 ) )
return - V_483 ;
V_1399 = F_43 ( sizeof( * V_1399 ) , V_129 ) ;
if ( ! V_1399 )
return - V_130 ;
F_229 ( & V_7 -> V_1401 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1398 -> V_1402 == V_31 -> V_449 ) {
V_1400 = - V_637 ;
goto V_794;
}
}
V_1399 -> V_1402 = V_31 -> V_449 ;
F_328 ( & V_1399 -> V_567 , & V_7 -> V_1403 ) ;
F_231 ( & V_7 -> V_1401 ) ;
return 0 ;
V_794:
F_231 ( & V_7 -> V_1401 ) ;
F_46 ( V_1399 ) ;
return V_1400 ;
}
static int F_329 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
int V_38 ;
if ( ! V_7 -> V_326 -> V_404 )
return - V_483 ;
if ( V_17 -> V_135 != V_560 )
return - V_483 ;
if ( V_17 -> V_1404 )
return 0 ;
F_8 ( & V_7 -> V_19 ) ;
V_38 = F_330 ( V_7 , V_17 -> V_135 ) ;
F_9 ( & V_7 -> V_19 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_331 ( V_7 , V_17 ) ;
if ( V_38 )
return V_38 ;
V_17 -> V_1404 = true ;
F_8 ( & V_7 -> V_19 ) ;
V_7 -> V_1405 ++ ;
F_9 ( & V_7 -> V_19 ) ;
return 0 ;
}
static int F_332 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
if ( V_17 -> V_135 != V_560 )
return - V_483 ;
if ( ! V_7 -> V_326 -> V_1406 )
return - V_483 ;
F_8 ( & V_7 -> V_19 ) ;
F_8 ( & V_7 -> V_1053 ) ;
F_333 ( V_7 , V_17 ) ;
F_9 ( & V_7 -> V_1053 ) ;
F_9 ( & V_7 -> V_19 ) ;
return 0 ;
}
static int F_334 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
void * V_264 ;
struct V_34 * V_56 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , V_31 -> V_449 , V_31 -> V_450 , 0 ,
V_1407 ) ;
if ( ! V_264 )
goto V_62;
if ( F_33 ( V_56 , V_1408 ,
V_1409 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
return F_76 ( V_56 , V_31 ) ;
V_62:
F_257 ( V_56 ) ;
return - V_85 ;
}
static int F_335 ( struct V_34 * V_35 , struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1410 V_1411 ;
struct V_26 * V_189 = V_31 -> V_448 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_1412 )
return - V_483 ;
if ( ! V_31 -> V_5 [ V_1413 ] ||
! F_27 ( V_31 -> V_5 [ V_610 ] ) )
return - V_16 ;
memset ( & V_1411 , 0 , sizeof( V_1411 ) ) ;
V_1411 . V_1414 = F_78 ( V_31 -> V_5 [ V_1413 ] ) ;
V_1411 . V_1013 = F_28 ( V_31 -> V_5 [ V_610 ] ) ;
V_1411 . V_1014 = F_29 ( V_31 -> V_5 [ V_610 ] ) ;
return F_336 ( V_7 , V_189 , & V_1411 ) ;
}
static int F_337 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
enum V_1415 V_1164 = V_1416 ;
T_3 V_1245 ;
int V_441 ;
if ( ! V_7 -> V_326 -> V_408 )
return - V_483 ;
if ( F_102 ( ! V_7 -> V_326 -> V_410 ) )
return - V_16 ;
if ( V_7 -> V_1417 )
return - V_485 ;
if ( V_31 -> V_5 [ V_1418 ] )
V_1164 = F_78 ( V_31 -> V_5 [ V_1418 ] ) ;
if ( V_1164 >= V_1419 )
return - V_16 ;
if ( ! V_31 -> V_5 [ V_1420 ] )
return - V_16 ;
V_1245 =
F_78 ( V_31 -> V_5 [ V_1420 ] ) ;
if ( V_1245 > V_1421 )
return - V_1385 ;
V_441 = F_338 ( V_7 , V_17 , V_1164 , V_1245 ) ;
if ( ! V_441 )
V_7 -> V_1417 = V_31 -> V_449 ;
return V_441 ;
}
static int F_339 ( struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = V_31 -> V_448 [ 0 ] ;
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
if ( ! V_7 -> V_326 -> V_410 )
return - V_483 ;
if ( V_7 -> V_1417 ) {
V_7 -> V_1417 = 0 ;
F_340 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_341 ( struct V_1422 * V_326 , struct V_34 * V_35 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_26 * V_189 ;
bool V_1423 = V_326 -> V_1424 & V_1425 ;
if ( V_1423 )
F_18 () ;
if ( V_326 -> V_1424 & V_1426 ) {
V_7 = F_15 ( F_94 ( V_31 ) , V_31 ) ;
if ( F_16 ( V_7 ) ) {
if ( V_1423 )
F_24 () ;
return F_21 ( V_7 ) ;
}
V_31 -> V_448 [ 0 ] = V_7 ;
} else if ( V_326 -> V_1424 & V_1427 ||
V_326 -> V_1424 & V_1428 ) {
F_8 ( & V_32 ) ;
V_17 = F_1 ( F_94 ( V_31 ) ,
V_31 -> V_5 ) ;
if ( F_16 ( V_17 ) ) {
F_9 ( & V_32 ) ;
if ( V_1423 )
F_24 () ;
return F_21 ( V_17 ) ;
}
V_189 = V_17 -> V_20 ;
V_7 = F_13 ( V_17 -> V_18 ) ;
if ( V_326 -> V_1424 & V_1427 ) {
if ( ! V_189 ) {
F_9 ( & V_32 ) ;
if ( V_1423 )
F_24 () ;
return - V_16 ;
}
V_31 -> V_448 [ 1 ] = V_189 ;
} else {
V_31 -> V_448 [ 1 ] = V_17 ;
}
if ( V_189 ) {
if ( V_326 -> V_1424 & V_1429 &&
! F_91 ( V_189 ) ) {
F_9 ( & V_32 ) ;
if ( V_1423 )
F_24 () ;
return - V_497 ;
}
F_217 ( V_189 ) ;
} else if ( V_326 -> V_1424 & V_1429 ) {
if ( ! V_17 -> V_1404 ) {
F_9 ( & V_32 ) ;
if ( V_1423 )
F_24 () ;
return - V_497 ;
}
}
F_23 ( V_7 ) ;
F_9 ( & V_32 ) ;
V_31 -> V_448 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_342 ( struct V_1422 * V_326 , struct V_34 * V_35 ,
struct V_30 * V_31 )
{
if ( V_31 -> V_448 [ 0 ] )
F_26 ( V_31 -> V_448 [ 0 ] ) ;
if ( V_31 -> V_448 [ 1 ] ) {
if ( V_326 -> V_1424 & V_1428 ) {
struct V_1 * V_17 = V_31 -> V_448 [ 1 ] ;
if ( V_17 -> V_20 )
F_14 ( V_17 -> V_20 ) ;
} else {
F_14 ( V_31 -> V_448 [ 1 ] ) ;
}
}
if ( V_326 -> V_1424 & V_1425 )
F_24 () ;
}
void F_343 ( struct V_6 * V_7 )
{
struct V_34 * V_56 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
if ( F_60 ( V_7 , V_56 , 0 , 0 , 0 ,
false , NULL , NULL , NULL ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1430 . V_1220 , V_129 ) ;
}
static int F_345 ( struct V_34 * V_56 ,
struct V_6 * V_7 )
{
struct V_1049 * V_1180 = V_7 -> V_1054 ;
struct V_4 * V_1431 ;
int V_149 ;
F_346 ( & V_7 -> V_1053 ) ;
if ( F_102 ( ! V_1180 ) )
return 0 ;
V_1431 = F_50 ( V_56 , V_1057 ) ;
if ( ! V_1431 )
goto V_62;
for ( V_149 = 0 ; V_149 < V_1180 -> V_1051 ; V_149 ++ ) {
if ( F_54 ( V_56 , V_149 , V_1180 -> V_1058 [ V_149 ] . V_528 , V_1180 -> V_1058 [ V_149 ] . V_530 ) )
goto V_62;
}
F_51 ( V_56 , V_1431 ) ;
V_1431 = F_50 ( V_56 , V_1056 ) ;
if ( ! V_1431 )
goto V_62;
for ( V_149 = 0 ; V_149 < V_1180 -> V_339 ; V_149 ++ ) {
if ( F_33 ( V_56 , V_149 , V_1180 -> V_340 [ V_149 ] -> V_61 ) )
goto V_62;
}
F_51 ( V_56 , V_1431 ) ;
if ( V_1180 -> V_1013 &&
F_54 ( V_56 , V_610 , V_1180 -> V_1014 , V_1180 -> V_1013 ) )
goto V_62;
if ( V_1180 -> V_54 )
F_33 ( V_56 , V_1062 , V_1180 -> V_54 ) ;
return 0 ;
V_62:
return - V_85 ;
}
static int F_347 ( struct V_34 * V_56 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_23 V_52 , V_23 V_53 , int V_54 ,
V_23 V_55 )
{
void * V_264 ;
V_264 = F_30 ( V_56 , V_52 , V_53 , V_54 , V_55 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
( V_17 -> V_20 && F_33 ( V_56 , V_10 ,
V_17 -> V_20 -> V_21 ) ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) )
goto V_62;
F_345 ( V_56 , V_7 ) ;
return F_67 ( V_56 , V_264 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
static int
F_348 ( struct V_34 * V_56 ,
struct V_6 * V_7 ,
struct V_26 * V_20 ,
V_23 V_52 , V_23 V_53 , int V_54 , V_23 V_55 )
{
void * V_264 ;
V_264 = F_30 ( V_56 , V_52 , V_53 , V_54 , V_55 ) ;
if ( ! V_264 )
return - 1 ;
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) )
goto V_62;
return F_67 ( V_56 , V_264 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
return - V_440 ;
}
void F_216 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_34 * V_56 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
if ( F_347 ( V_56 , V_7 , V_17 , 0 , 0 , 0 ,
V_1432 ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1433 . V_1220 , V_129 ) ;
}
void F_349 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_34 * V_56 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
if ( F_347 ( V_56 , V_7 , V_17 , 0 , 0 , 0 ,
V_1100 ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1433 . V_1220 , V_129 ) ;
}
void F_350 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_34 * V_56 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
if ( F_347 ( V_56 , V_7 , V_17 , 0 , 0 , 0 ,
V_1434 ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1433 . V_1220 , V_129 ) ;
}
void F_351 ( struct V_6 * V_7 ,
struct V_26 * V_20 )
{
struct V_34 * V_56 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
if ( F_348 ( V_56 , V_7 , V_20 , 0 , 0 , 0 ,
V_1435 ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1433 . V_1220 , V_129 ) ;
}
void F_220 ( struct V_6 * V_7 ,
struct V_26 * V_20 , V_23 V_55 )
{
struct V_34 * V_56 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
if ( F_348 ( V_56 , V_7 , V_20 , 0 , 0 , 0 , V_55 ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1433 . V_1220 , V_129 ) ;
}
void F_352 ( struct V_1436 * V_1050 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1437 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_58 ( V_56 , V_1438 , V_1050 -> V_1439 ) )
goto V_62;
if ( V_1050 -> V_1027 [ 0 ] == '0' && V_1050 -> V_1027 [ 1 ] == '0' ) {
if ( F_58 ( V_56 , V_1440 ,
V_1441 ) )
goto V_62;
} else if ( V_1050 -> V_1027 [ 0 ] == '9' && V_1050 -> V_1027 [ 1 ] == '9' ) {
if ( F_58 ( V_56 , V_1440 ,
V_1442 ) )
goto V_62;
} else if ( ( V_1050 -> V_1027 [ 0 ] == '9' && V_1050 -> V_1027 [ 1 ] == '8' ) ||
V_1050 -> V_1443 ) {
if ( F_58 ( V_56 , V_1440 ,
V_1444 ) )
goto V_62;
} else {
if ( F_58 ( V_56 , V_1440 ,
V_1445 ) ||
F_61 ( V_56 , V_925 ,
V_1050 -> V_1027 ) )
goto V_62;
}
if ( V_1050 -> V_14 != V_1446 &&
F_33 ( V_56 , V_27 , V_1050 -> V_14 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_205 () ;
F_353 ( V_56 , 0 , V_1447 . V_1220 ,
V_1448 ) ;
F_207 () ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
static void F_354 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
const T_2 * V_1449 , T_10 V_50 ,
enum V_630 V_55 , T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_55 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
F_54 ( V_56 , V_1274 , V_50 , V_1449 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_355 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1449 ,
T_10 V_50 , T_11 V_1218 )
{
F_354 ( V_7 , V_20 , V_1449 , V_50 ,
V_632 , V_1218 ) ;
}
void F_356 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1449 ,
T_10 V_50 , T_11 V_1218 )
{
F_354 ( V_7 , V_20 , V_1449 , V_50 ,
V_1451 , V_1218 ) ;
}
void F_357 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1449 ,
T_10 V_50 , T_11 V_1218 )
{
F_354 ( V_7 , V_20 , V_1449 , V_50 ,
V_1452 , V_1218 ) ;
}
void F_358 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_1449 ,
T_10 V_50 , T_11 V_1218 )
{
F_354 ( V_7 , V_20 , V_1449 , V_50 ,
V_1453 , V_1218 ) ;
}
void F_359 ( struct V_26 * V_189 , const T_2 * V_1449 ,
T_10 V_50 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
F_360 ( V_189 ) ;
F_354 ( V_7 , V_189 , V_1449 , V_50 ,
V_1454 , V_1448 ) ;
}
void F_361 ( struct V_26 * V_189 , const T_2 * V_1449 ,
T_10 V_50 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
F_362 ( V_189 ) ;
F_354 ( V_7 , V_189 , V_1449 , V_50 ,
V_1455 , V_1448 ) ;
}
static void F_363 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_55 ,
const T_2 * V_604 , T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_55 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
F_34 ( V_56 , V_1456 ) ||
F_54 ( V_56 , V_488 , V_525 , V_604 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_364 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_604 ,
T_11 V_1218 )
{
F_363 ( V_7 , V_20 , V_632 ,
V_604 , V_1218 ) ;
}
void F_365 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_604 ,
T_11 V_1218 )
{
F_363 ( V_7 , V_20 , V_1451 ,
V_604 , V_1218 ) ;
}
void F_366 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_487 ,
const T_2 * V_1457 , T_10 V_1458 ,
const T_2 * V_1459 , T_10 V_1460 ,
T_3 V_1461 , T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_415 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
( V_487 && F_54 ( V_56 , V_488 , V_525 , V_487 ) ) ||
F_57 ( V_56 , V_1240 , V_1461 ) ||
( V_1457 &&
F_54 ( V_56 , V_1462 , V_1458 , V_1457 ) ) ||
( V_1459 &&
F_54 ( V_56 , V_1463 , V_1460 , V_1459 ) ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_367 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_487 ,
const T_2 * V_1457 , T_10 V_1458 ,
const T_2 * V_1459 , T_10 V_1460 , T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1464 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_487 ) ||
( V_1457 &&
F_54 ( V_56 , V_1462 , V_1458 , V_1457 ) ) ||
( V_1459 &&
F_54 ( V_56 , V_1463 , V_1460 , V_1459 ) ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_368 ( struct V_6 * V_7 ,
struct V_26 * V_20 , T_3 V_1224 ,
const T_2 * V_1013 , T_10 V_1014 , bool V_1465 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_417 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
( V_1465 && V_1224 &&
F_57 ( V_56 , V_1196 , V_1224 ) ) ||
( V_1465 &&
F_34 ( V_56 , V_1466 ) ) ||
( V_1013 && F_54 ( V_56 , V_610 , V_1014 , V_1013 ) ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_129 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_369 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_487 ,
T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1467 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_487 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_370 ( struct V_26 * V_189 , const T_2 * V_604 ,
const T_2 * V_1013 , T_2 V_1014 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
if ( F_102 ( V_17 -> V_135 != V_139 ) )
return;
F_371 ( V_189 , V_604 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1468 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_604 ) ||
( V_1014 && V_1013 &&
F_54 ( V_56 , V_610 , V_1014 , V_1013 ) ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_372 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_604 ,
enum V_1469 V_1470 , int V_1471 ,
const T_2 * V_1472 , T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1473 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
( V_604 && F_54 ( V_56 , V_488 , V_525 , V_604 ) ) ||
F_33 ( V_56 , V_121 , V_1470 ) ||
( V_1471 != - 1 &&
F_58 ( V_56 , V_117 , V_1471 ) ) ||
( V_1472 && F_54 ( V_56 , V_116 , 6 , V_1472 ) ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_373 ( struct V_18 * V_18 ,
struct V_57 * V_1474 ,
struct V_57 * V_1475 )
{
struct V_34 * V_56 ;
void * V_264 ;
struct V_4 * V_268 ;
V_56 = F_74 ( V_536 , V_1448 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1476 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , F_374 ( V_18 ) ) )
goto V_62;
V_268 = F_50 ( V_56 , V_1477 ) ;
if ( ! V_268 )
goto V_62;
if ( F_32 ( V_56 , V_1474 , false ) )
goto V_62;
F_51 ( V_56 , V_268 ) ;
V_268 = F_50 ( V_56 , V_1478 ) ;
if ( ! V_268 )
goto V_62;
if ( F_32 ( V_56 , V_1475 , false ) )
goto V_62;
F_51 ( V_56 , V_268 ) ;
F_67 ( V_56 , V_264 ) ;
F_205 () ;
F_353 ( V_56 , 0 , V_1447 . V_1220 ,
V_1448 ) ;
F_207 () ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
static void F_375 (
int V_55 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_574 ,
struct V_57 * V_58 ,
unsigned int V_1245 , T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_55 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
( V_17 -> V_20 && F_33 ( V_56 , V_10 ,
V_17 -> V_20 -> V_21 ) ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) ||
F_33 ( V_56 , V_468 , V_58 -> V_61 ) ||
F_33 ( V_56 , V_473 ,
V_476 ) ||
F_105 ( V_56 , V_1249 , V_574 ) )
goto V_62;
if ( V_55 == V_1248 &&
F_33 ( V_56 , V_1246 , V_1245 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_376 ( struct V_1 * V_17 , T_1 V_574 ,
struct V_57 * V_58 ,
unsigned int V_1245 , T_11 V_1218 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
F_377 ( V_17 , V_574 , V_58 , V_1245 ) ;
F_375 ( V_1248 ,
V_7 , V_17 , V_574 , V_58 ,
V_1245 , V_1218 ) ;
}
void F_378 ( struct V_1 * V_17 , T_1 V_574 ,
struct V_57 * V_58 ,
T_11 V_1218 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
F_379 ( V_17 , V_574 , V_58 ) ;
F_375 ( V_1479 ,
V_7 , V_17 , V_574 , V_58 , 0 , V_1218 ) ;
}
void F_380 ( struct V_26 * V_189 , const T_2 * V_576 ,
struct V_705 * V_706 , T_11 V_1218 )
{
struct V_18 * V_18 = V_189 -> V_29 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
F_381 ( V_189 , V_576 , V_706 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
if ( F_161 ( V_56 , 0 , 0 , 0 ,
V_7 , V_189 , V_576 , V_706 ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
}
void F_382 ( struct V_26 * V_189 , const T_2 * V_576 , T_11 V_1218 )
{
struct V_18 * V_18 = V_189 -> V_29 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
F_383 ( V_189 , V_576 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1480 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_576 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_384 ( struct V_26 * V_189 , const T_2 * V_576 ,
enum V_1481 V_1224 ,
T_11 V_1218 )
{
struct V_18 * V_18 = V_189 -> V_29 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_1482 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1483 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_576 ) ||
F_33 ( V_56 , V_1484 , V_1224 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
static bool F_385 ( struct V_26 * V_189 , T_2 V_55 ,
const T_2 * V_604 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
int V_38 ;
V_23 V_1402 = F_386 ( V_17 -> V_1395 ) ;
if ( ! V_1402 )
return false ;
V_56 = F_74 ( 100 , V_1218 ) ;
if ( ! V_56 )
return true ;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_55 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return true ;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_604 ) )
goto V_62;
V_38 = F_67 ( V_56 , V_264 ) ;
if ( V_38 < 0 ) {
F_75 ( V_56 ) ;
return true ;
}
F_387 ( F_7 ( & V_7 -> V_18 ) , V_56 , V_1402 ) ;
return true ;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
return true ;
}
bool F_388 ( struct V_26 * V_189 ,
const T_2 * V_604 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
bool V_441 ;
F_389 ( V_189 , V_604 ) ;
if ( F_102 ( V_17 -> V_135 != V_136 &&
V_17 -> V_135 != V_138 ) ) {
F_390 ( false ) ;
return false ;
}
V_441 = F_385 ( V_189 , V_1485 ,
V_604 , V_1218 ) ;
F_390 ( V_441 ) ;
return V_441 ;
}
bool F_391 ( struct V_26 * V_189 ,
const T_2 * V_604 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
bool V_441 ;
F_392 ( V_189 , V_604 ) ;
if ( F_102 ( V_17 -> V_135 != V_136 &&
V_17 -> V_135 != V_138 &&
V_17 -> V_135 != V_137 ) ) {
F_390 ( false ) ;
return false ;
}
V_441 = F_385 ( V_189 ,
V_1486 ,
V_604 , V_1218 ) ;
F_390 ( V_441 ) ;
return V_441 ;
}
int F_393 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_23 V_1402 ,
int V_1487 , int V_1488 ,
const T_2 * V_1449 , T_10 V_50 , T_11 V_1218 )
{
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return - V_130 ;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1275 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return - V_130 ;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_33 ( V_56 , V_10 ,
V_20 -> V_21 ) ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) ||
F_33 ( V_56 , V_468 , V_1487 ) ||
( V_1488 &&
F_33 ( V_56 , V_1489 , V_1488 ) ) ||
F_54 ( V_56 , V_1274 , V_50 , V_1449 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
return F_387 ( F_7 ( & V_7 -> V_18 ) , V_56 , V_1402 ) ;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
return - V_85 ;
}
void F_394 ( struct V_1 * V_17 , T_1 V_574 ,
const T_2 * V_1449 , T_10 V_50 , bool V_1490 , T_11 V_1218 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_26 * V_20 = V_17 -> V_20 ;
struct V_34 * V_56 ;
void * V_264 ;
F_395 ( V_17 , V_574 , V_1490 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1491 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
( V_20 && F_33 ( V_56 , V_10 ,
V_20 -> V_21 ) ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) ||
F_54 ( V_56 , V_1274 , V_50 , V_1449 ) ||
F_105 ( V_56 , V_1249 , V_574 ) ||
( V_1490 && F_34 ( V_56 , V_1492 ) ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_262 ( V_56 , 0 , V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_396 ( struct V_26 * V_189 ,
enum V_1493 V_1494 ,
T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
struct V_4 * V_861 ;
void * V_264 ;
F_397 ( V_189 , V_1494 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1495 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_189 -> V_21 ) )
goto V_62;
V_861 = F_50 ( V_56 , V_1295 ) ;
if ( ! V_861 )
goto V_62;
if ( F_33 ( V_56 , V_1496 ,
V_1494 ) )
goto V_62;
F_51 ( V_56 , V_861 ) ;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
static void F_398 ( struct V_6 * V_7 ,
struct V_26 * V_20 , const T_2 * V_487 ,
const T_2 * V_1392 , T_11 V_1218 )
{
struct V_34 * V_56 ;
struct V_4 * V_1497 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1498 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_487 ) )
goto V_62;
V_1497 = F_50 ( V_56 , V_1380 ) ;
if ( ! V_1497 )
goto V_62;
if ( F_54 ( V_56 , V_1383 ,
V_1384 , V_1392 ) )
goto V_62;
F_51 ( V_56 , V_1497 ) ;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_399 ( struct V_26 * V_189 , const T_2 * V_487 ,
const T_2 * V_1392 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
F_400 ( V_189 , V_487 ) ;
F_398 ( V_7 , V_189 , V_487 , V_1392 , V_1218 ) ;
}
static void
F_401 ( struct V_6 * V_7 ,
struct V_26 * V_20 , int V_1499 ,
const T_2 * V_487 , bool V_1500 , T_11 V_1218 )
{
struct V_34 * V_56 ;
struct V_4 * V_48 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1501 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_20 -> V_21 ) )
goto V_62;
V_48 = F_50 ( V_56 , V_1502 ) ;
if ( ! V_48 )
goto V_62;
if ( F_33 ( V_56 , V_1503 , V_1499 ) ||
F_54 ( V_56 , V_1504 , V_525 , V_487 ) ||
( V_1500 &&
F_34 ( V_56 , V_1505 ) ) )
goto V_62;
F_51 ( V_56 , V_48 ) ;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_402 ( struct V_26 * V_189 , int V_1499 ,
const T_2 * V_487 , bool V_1500 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
F_403 ( V_189 , V_1499 , V_487 , V_1500 ) ;
F_401 ( V_7 , V_189 , V_1499 , V_487 , V_1500 , V_1218 ) ;
}
static void F_404 ( struct V_6 * V_7 ,
struct V_26 * V_20 ,
struct V_465 * V_466 ,
T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1506 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_10 , V_20 -> V_21 ) )
goto V_62;
if ( F_101 ( V_56 , V_466 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_405 ( struct V_26 * V_189 ,
struct V_465 * V_466 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
F_406 ( V_189 , V_466 ) ;
F_113 ( V_17 ) ;
if ( F_102 ( V_17 -> V_135 != V_136 &&
V_17 -> V_135 != V_138 ) )
goto V_535;
V_17 -> V_664 = V_466 -> V_58 ;
F_404 ( V_7 , V_189 , V_466 , V_129 ) ;
V_535:
F_115 ( V_17 ) ;
return;
}
void F_407 ( struct V_26 * V_189 ,
const T_2 * V_1238 , V_23 V_1507 ,
V_23 V_223 , V_23 V_1287 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
struct V_4 * V_861 ;
void * V_264 ;
V_56 = F_74 ( V_1482 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1495 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_1238 ) )
goto V_62;
V_861 = F_50 ( V_56 , V_1295 ) ;
if ( ! V_861 )
goto V_62;
if ( F_33 ( V_56 , V_1300 , V_1507 ) )
goto V_62;
if ( F_33 ( V_56 , V_1299 , V_223 ) )
goto V_62;
if ( F_33 ( V_56 , V_1301 , V_1287 ) )
goto V_62;
F_51 ( V_56 , V_861 ) ;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void
F_408 ( struct V_6 * V_7 ,
struct V_465 * V_466 ,
enum V_1508 V_1509 ,
struct V_26 * V_20 , T_11 V_1218 )
{
struct V_34 * V_56 ;
void * V_264 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1510 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) )
goto V_62;
if ( V_20 ) {
struct V_1 * V_17 = V_20 -> V_29 ;
if ( F_33 ( V_56 , V_10 , V_20 -> V_21 ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) )
goto V_62;
}
if ( F_33 ( V_56 , V_1511 , V_1509 ) )
goto V_62;
if ( F_101 ( V_56 , V_466 ) )
goto V_62;
if ( F_67 ( V_56 , V_264 ) < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_409 ( struct V_26 * V_189 ,
const T_2 * V_1238 , V_23 V_1507 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
struct V_4 * V_861 ;
void * V_264 ;
F_410 ( V_189 , V_1238 , V_1507 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1495 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_1238 ) )
goto V_62;
V_861 = F_50 ( V_56 , V_1295 ) ;
if ( ! V_861 )
goto V_62;
if ( F_33 ( V_56 , V_1512 , V_1507 ) )
goto V_62;
F_51 ( V_56 , V_861 ) ;
F_67 ( V_56 , V_264 ) ;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_411 ( struct V_26 * V_189 , const T_2 * V_604 ,
T_1 V_574 , bool V_1513 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
int V_38 ;
F_412 ( V_189 , V_604 , V_574 , V_1513 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1396 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_54 ( V_56 , V_488 , V_525 , V_604 ) ||
F_105 ( V_56 , V_1249 , V_574 ) ||
( V_1513 && F_34 ( V_56 , V_1492 ) ) )
goto V_62;
V_38 = F_67 ( V_56 , V_264 ) ;
if ( V_38 < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_413 ( struct V_18 * V_18 ,
const T_2 * V_1514 , T_10 V_50 ,
int V_1487 , int V_1488 )
{
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
struct V_1397 * V_1398 ;
F_414 ( V_18 , V_1514 , V_50 , V_1487 , V_1488 ) ;
F_229 ( & V_7 -> V_1401 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_56 = F_74 ( V_50 + 100 , V_1448 ) ;
if ( ! V_56 ) {
F_231 ( & V_7 -> V_1401 ) ;
return;
}
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1275 ) ;
if ( ! V_264 )
goto V_62;
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
( V_1487 &&
F_33 ( V_56 , V_468 , V_1487 ) ) ||
( V_1488 &&
F_33 ( V_56 , V_1489 , V_1488 ) ) ||
F_54 ( V_56 , V_1274 , V_50 , V_1514 ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_387 ( F_7 ( & V_7 -> V_18 ) , V_56 , V_1398 -> V_1402 ) ;
}
F_231 ( & V_7 -> V_1401 ) ;
return;
V_62:
F_231 ( & V_7 -> V_1401 ) ;
if ( V_264 )
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
void F_415 ( struct V_1 * V_17 ,
struct V_1515 * V_1516 ,
T_11 V_1218 )
{
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
int V_38 , V_1334 = 200 ;
F_416 ( V_17 -> V_18 , V_17 , V_1516 ) ;
if ( V_1516 )
V_1334 += V_1516 -> V_1517 ;
V_56 = F_74 ( V_1334 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1518 ) ;
if ( ! V_264 )
goto V_584;
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) )
goto V_584;
if ( V_17 -> V_20 && F_33 ( V_56 , V_10 ,
V_17 -> V_20 -> V_21 ) )
goto V_584;
if ( V_1516 ) {
struct V_4 * V_1519 ;
V_1519 = F_50 ( V_56 , V_1336 ) ;
if ( V_1516 -> V_416 &&
F_34 ( V_56 , V_196 ) )
goto V_584;
if ( V_1516 -> V_1338 &&
F_34 ( V_56 , V_198 ) )
goto V_584;
if ( V_1516 -> V_1339 &&
F_34 ( V_56 , V_202 ) )
goto V_584;
if ( V_1516 -> V_1340 &&
F_34 ( V_56 , V_204 ) )
goto V_584;
if ( V_1516 -> V_1341 &&
F_34 ( V_56 , V_206 ) )
goto V_584;
if ( V_1516 -> V_1342 &&
F_34 ( V_56 , V_208 ) )
goto V_584;
if ( V_1516 -> V_1520 >= 0 &&
F_33 ( V_56 , V_217 ,
V_1516 -> V_1520 ) )
goto V_584;
if ( V_1516 -> V_1521 )
F_34 ( V_56 , V_1522 ) ;
if ( V_1516 -> V_1523 )
F_34 ( V_56 ,
V_1524 ) ;
if ( V_1516 -> V_1525 )
F_34 ( V_56 ,
V_1526 ) ;
if ( V_1516 -> V_1527 ) {
V_23 V_1528 = V_1529 ;
V_23 V_1530 = V_1531 ;
if ( ! V_1516 -> V_1532 ) {
V_1528 =
V_1533 ;
V_1530 =
V_1534 ;
}
if ( V_1516 -> V_1535 &&
F_33 ( V_56 , V_1530 , V_1516 -> V_1535 ) )
goto V_584;
if ( F_54 ( V_56 , V_1528 , V_1516 -> V_1517 ,
V_1516 -> V_1527 ) )
goto V_584;
}
F_51 ( V_56 , V_1519 ) ;
}
V_38 = F_67 ( V_56 , V_264 ) ;
if ( V_38 < 0 )
goto V_584;
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_584:
F_75 ( V_56 ) ;
}
void F_417 ( struct V_26 * V_189 , const T_2 * V_1238 ,
enum V_1242 V_1536 ,
T_3 V_1195 , T_11 V_1218 )
{
struct V_1 * V_17 = V_189 -> V_29 ;
struct V_6 * V_7 = F_13 ( V_17 -> V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
int V_38 ;
F_418 ( V_17 -> V_18 , V_189 , V_1238 , V_1536 ,
V_1195 ) ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1537 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_33 ( V_56 , V_10 , V_189 -> V_21 ) ||
F_58 ( V_56 , V_1244 , V_1536 ) ||
F_54 ( V_56 , V_488 , V_525 , V_1238 ) ||
( V_1195 > 0 &&
F_57 ( V_56 , V_1196 , V_1195 ) ) )
goto V_62;
V_38 = F_67 ( V_56 , V_264 ) ;
if ( V_38 < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_1218 ) ;
return;
V_62:
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
static int F_419 ( struct V_1538 * V_1539 ,
unsigned long V_1277 ,
void * V_1540 )
{
struct V_1541 * V_1542 = V_1540 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1397 * V_1398 , * V_25 ;
if ( V_1277 != V_1543 )
return V_1544 ;
F_205 () ;
F_420 (rdev, &cfg80211_rdev_list, list) {
F_420 (wdev, &rdev->wdev_list, list)
F_421 ( V_17 , V_1542 -> V_52 ) ;
F_229 ( & V_7 -> V_1401 ) ;
F_422 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1398 -> V_1402 == V_1542 -> V_52 ) {
F_423 ( & V_1398 -> V_567 ) ;
F_46 ( V_1398 ) ;
break;
}
}
F_231 ( & V_7 -> V_1401 ) ;
}
F_207 () ;
return V_1544 ;
}
void F_424 ( struct V_26 * V_20 ,
struct V_1545 * V_1546 )
{
struct V_18 * V_18 = V_20 -> V_29 -> V_18 ;
struct V_6 * V_7 = F_13 ( V_18 ) ;
struct V_34 * V_56 ;
void * V_264 ;
int V_38 ;
F_425 ( V_18 , V_20 , V_1546 ) ;
if ( ! V_1546 -> V_1547 )
return;
V_56 = F_74 ( V_536 , V_129 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1548 ) ;
if ( ! V_264 ) {
F_75 ( V_56 ) ;
return;
}
F_33 ( V_56 , V_27 , V_7 -> V_14 ) ;
F_33 ( V_56 , V_10 , V_20 -> V_21 ) ;
F_54 ( V_56 , V_488 , V_525 , V_1546 -> V_1547 ) ;
if ( V_1546 -> V_1097 )
F_54 ( V_56 , V_610 , V_1546 -> V_1549 , V_1546 -> V_1097 ) ;
if ( V_1546 -> V_1550 )
F_54 ( V_56 , V_1551 , V_1546 -> V_1552 ,
V_1546 -> V_1550 ) ;
V_38 = F_67 ( V_56 , V_264 ) ;
if ( V_38 < 0 ) {
F_75 ( V_56 ) ;
return;
}
F_344 ( F_7 ( & V_7 -> V_18 ) , V_56 , 0 ,
V_1450 . V_1220 , V_129 ) ;
}
void F_426 ( struct V_1 * V_17 , T_11 V_1218 )
{
struct V_6 * V_7 ;
struct V_34 * V_56 ;
void * V_264 ;
V_23 V_1402 ;
V_7 = F_13 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1417 )
return;
V_1402 = V_7 -> V_1417 ;
V_7 -> V_1417 = 0 ;
V_56 = F_74 ( V_536 , V_1218 ) ;
if ( ! V_56 )
return;
V_264 = F_30 ( V_56 , 0 , 0 , 0 , V_1553 ) ;
if ( ! V_264 )
goto V_62;
if ( F_33 ( V_56 , V_27 , V_7 -> V_14 ) ||
F_105 ( V_56 , V_12 , V_13 ( V_17 ) ) )
goto V_62;
F_67 ( V_56 , V_264 ) ;
F_387 ( F_7 ( & V_7 -> V_18 ) , V_56 , V_1402 ) ;
return;
V_62:
if ( V_264 )
F_68 ( V_56 , V_264 ) ;
F_75 ( V_56 ) ;
}
int F_427 ( void )
{
int V_38 ;
V_38 = F_428 ( & V_41 ,
V_1554 , F_429 ( V_1554 ) ) ;
if ( V_38 )
return V_38 ;
V_38 = F_430 ( & V_41 , & V_1430 ) ;
if ( V_38 )
goto V_1555;
V_38 = F_430 ( & V_41 , & V_1433 ) ;
if ( V_38 )
goto V_1555;
V_38 = F_430 ( & V_41 , & V_1447 ) ;
if ( V_38 )
goto V_1555;
V_38 = F_430 ( & V_41 , & V_1450 ) ;
if ( V_38 )
goto V_1555;
#ifdef F_65
V_38 = F_430 ( & V_41 , & V_1219 ) ;
if ( V_38 )
goto V_1555;
#endif
V_38 = F_431 ( & V_1556 ) ;
if ( V_38 )
goto V_1555;
return 0 ;
V_1555:
F_432 ( & V_41 ) ;
return V_38 ;
}
void F_433 ( void )
{
F_434 ( & V_1556 ) ;
F_432 ( & V_41 ) ;
}
