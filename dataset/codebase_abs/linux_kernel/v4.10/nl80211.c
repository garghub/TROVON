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
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_9 && V_17 -> V_19 &&
V_17 -> V_19 -> V_20 == V_15 ) {
V_8 = V_17 ;
break;
}
if ( V_11 && V_17 -> V_21 == ( V_22 ) V_13 ) {
V_8 = V_17 ;
break;
}
}
if ( V_8 )
break;
}
if ( V_8 )
return V_8 ;
return F_3 ( - V_23 ) ;
}
static struct V_6 *
F_8 ( struct V_2 * V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 = NULL , * V_24 ;
struct V_25 * V_19 ;
F_2 () ;
if ( ! V_5 [ V_26 ] &&
! V_5 [ V_10 ] &&
! V_5 [ V_12 ] )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_26 ] )
V_7 = F_9 (
F_4 ( V_5 [ V_26 ] ) ) ;
if ( V_5 [ V_12 ] ) {
T_1 V_13 = F_5 ( V_5 [ V_12 ] ) ;
struct V_1 * V_17 ;
bool V_27 = false ;
V_24 = F_9 ( V_13 >> 32 ) ;
if ( V_24 ) {
F_6 (wdev, &tmp->wiphy.wdev_list, list) {
if ( V_17 -> V_21 != ( V_22 ) V_13 )
continue;
V_27 = true ;
break;
}
if ( ! V_27 )
V_24 = NULL ;
if ( V_7 && V_24 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_24 ;
}
}
if ( V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_5 [ V_10 ] ) ;
V_19 = F_10 ( V_3 , V_20 ) ;
if ( V_19 ) {
if ( V_19 -> V_28 )
V_24 = F_11 (
V_19 -> V_28 -> V_18 ) ;
else
V_24 = NULL ;
if ( ! V_24 )
return F_3 ( - V_16 ) ;
if ( V_7 && V_24 != V_7 )
return F_3 ( - V_16 ) ;
V_7 = V_24 ;
}
}
if ( ! V_7 )
return F_3 ( - V_23 ) ;
if ( V_3 != F_7 ( & V_7 -> V_18 ) )
return F_3 ( - V_23 ) ;
return V_7 ;
}
static struct V_6 *
F_12 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
return F_8 ( V_3 , V_30 -> V_5 ) ;
}
static int F_13 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
int V_35 ;
F_14 () ;
if ( ! V_34 -> args [ 0 ] ) {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
F_16 ( & V_38 ) ,
V_38 . V_40 , V_41 ) ;
if ( V_35 )
goto V_42;
* V_17 = F_1 (
F_17 ( V_32 -> V_43 ) ,
F_16 ( & V_38 ) ) ;
if ( F_18 ( * V_17 ) ) {
V_35 = F_19 ( * V_17 ) ;
goto V_42;
}
* V_7 = F_11 ( ( * V_17 ) -> V_18 ) ;
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = ( * V_17 ) -> V_21 ;
} else {
struct V_18 * V_18 = F_20 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 ) {
V_35 = - V_23 ;
goto V_42;
}
* V_7 = F_11 ( V_18 ) ;
* V_17 = NULL ;
F_6 (tmp, &(*rdev)->wiphy.wdev_list, list) {
if ( V_24 -> V_21 == V_34 -> args [ 1 ] ) {
* V_17 = V_24 ;
break;
}
}
if ( ! * V_17 ) {
V_35 = - V_23 ;
goto V_42;
}
}
return 0 ;
V_42:
F_21 () ;
return V_35 ;
}
static void F_22 ( struct V_6 * V_7 )
{
F_21 () ;
}
static bool F_23 ( const struct V_4 * V_44 )
{
const T_2 * V_45 ;
int V_46 ;
if ( ! V_44 )
return true ;
V_45 = F_24 ( V_44 ) ;
V_46 = F_25 ( V_44 ) ;
while ( V_46 ) {
T_2 V_47 ;
if ( V_46 < 2 )
return false ;
V_46 -= 2 ;
V_47 = V_45 [ 1 ] ;
if ( V_47 > V_46 )
return false ;
V_46 -= V_47 ;
V_45 += 2 + V_47 ;
}
return true ;
}
static inline void * F_26 ( struct V_31 * V_32 , V_22 V_48 , V_22 V_49 ,
int V_50 , T_2 V_51 )
{
return F_27 ( V_32 , V_48 , V_49 , & V_38 , V_50 , V_51 ) ;
}
static int F_28 ( struct V_31 * V_52 ,
struct V_53 * V_54 ,
bool V_55 )
{
if ( ! V_55 && V_54 -> V_50 &
( V_56 | V_57 ) )
return 0 ;
if ( F_29 ( V_52 , V_58 ,
V_54 -> V_59 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_61 ) &&
F_30 ( V_52 , V_62 ) )
goto V_60;
if ( V_54 -> V_50 & V_63 ) {
if ( F_30 ( V_52 , V_64 ) )
goto V_60;
if ( F_30 ( V_52 , V_65 ) )
goto V_60;
}
if ( V_54 -> V_50 & V_66 ) {
if ( F_30 ( V_52 , V_67 ) )
goto V_60;
if ( V_55 ) {
V_22 time ;
time = F_31 ( V_54 -> V_68 ) ;
if ( F_29 ( V_52 , V_69 ,
V_54 -> V_70 ) )
goto V_60;
if ( F_29 ( V_52 , V_71 ,
time ) )
goto V_60;
if ( F_29 ( V_52 ,
V_72 ,
V_54 -> V_73 ) )
goto V_60;
}
}
if ( V_55 ) {
if ( ( V_54 -> V_50 & V_74 ) &&
F_30 ( V_52 , V_75 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_76 ) &&
F_30 ( V_52 , V_77 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_78 ) &&
F_30 ( V_52 , V_79 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_80 ) &&
F_30 ( V_52 , V_81 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_82 ) &&
F_30 ( V_52 , V_83 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_84 ) &&
F_30 ( V_52 , V_85 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_57 ) &&
F_30 ( V_52 , V_86 ) )
goto V_60;
if ( ( V_54 -> V_50 & V_56 ) &&
F_30 ( V_52 , V_87 ) )
goto V_60;
}
if ( F_29 ( V_52 , V_88 ,
F_32 ( V_54 -> V_89 ) ) )
goto V_60;
return 0 ;
V_60:
return - V_90 ;
}
static int F_33 ( struct V_4 * V_91 , struct V_92 * V_93 )
{
struct V_4 * V_94 [ V_95 + 1 ] ;
int V_35 = F_34 ( V_94 , V_95 , V_91 ,
V_96 ) ;
if ( V_35 )
return V_35 ;
V_93 -> V_97 = ! ! V_94 [ V_98 ] ;
V_93 -> V_99 = ! ! V_94 [ V_100 ] ;
if ( V_93 -> V_97 ) {
V_93 -> V_101 = true ;
V_93 -> V_102 = true ;
}
if ( V_93 -> V_99 )
V_93 -> V_102 = true ;
if ( V_94 [ V_103 ] )
V_93 -> V_104 = F_35 ( V_94 [ V_103 ] ) ;
if ( V_94 [ V_105 ] ) {
V_93 -> V_106 . V_91 = F_24 ( V_94 [ V_105 ] ) ;
V_93 -> V_106 . V_107 = F_25 ( V_94 [ V_105 ] ) ;
}
if ( V_94 [ V_108 ] ) {
V_93 -> V_106 . V_49 = F_24 ( V_94 [ V_108 ] ) ;
V_93 -> V_106 . V_109 = F_25 ( V_94 [ V_108 ] ) ;
}
if ( V_94 [ V_110 ] )
V_93 -> V_106 . V_111 = F_4 ( V_94 [ V_110 ] ) ;
if ( V_94 [ V_112 ] ) {
V_93 -> type = F_4 ( V_94 [ V_112 ] ) ;
if ( V_93 -> type < 0 || V_93 -> type >= V_113 )
return - V_16 ;
}
if ( V_94 [ V_114 ] ) {
struct V_4 * V_115 [ V_116 ] ;
V_35 = F_34 ( V_115 , V_116 - 1 ,
V_94 [ V_114 ] ,
V_117 ) ;
if ( V_35 )
return V_35 ;
V_93 -> V_101 = V_115 [ V_118 ] ;
V_93 -> V_102 = V_115 [ V_119 ] ;
}
return 0 ;
}
static int F_36 ( struct V_29 * V_30 , struct V_92 * V_93 )
{
if ( V_30 -> V_5 [ V_120 ] ) {
V_93 -> V_106 . V_91 = F_24 ( V_30 -> V_5 [ V_120 ] ) ;
V_93 -> V_106 . V_107 = F_25 ( V_30 -> V_5 [ V_120 ] ) ;
}
if ( V_30 -> V_5 [ V_121 ] ) {
V_93 -> V_106 . V_49 = F_24 ( V_30 -> V_5 [ V_121 ] ) ;
V_93 -> V_106 . V_109 = F_25 ( V_30 -> V_5 [ V_121 ] ) ;
}
if ( V_30 -> V_5 [ V_122 ] )
V_93 -> V_104 = F_35 ( V_30 -> V_5 [ V_122 ] ) ;
if ( V_30 -> V_5 [ V_123 ] )
V_93 -> V_106 . V_111 = F_4 ( V_30 -> V_5 [ V_123 ] ) ;
V_93 -> V_97 = ! ! V_30 -> V_5 [ V_124 ] ;
V_93 -> V_99 = ! ! V_30 -> V_5 [ V_125 ] ;
if ( V_93 -> V_97 ) {
V_93 -> V_101 = true ;
V_93 -> V_102 = true ;
}
if ( V_93 -> V_99 )
V_93 -> V_102 = true ;
if ( V_30 -> V_5 [ V_126 ] ) {
V_93 -> type = F_4 ( V_30 -> V_5 [ V_126 ] ) ;
if ( V_93 -> type < 0 || V_93 -> type >= V_113 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_127 ] ) {
struct V_4 * V_115 [ V_116 ] ;
int V_35 = F_34 (
V_115 , V_116 - 1 ,
V_30 -> V_5 [ V_127 ] ,
V_117 ) ;
if ( V_35 )
return V_35 ;
V_93 -> V_101 = V_115 [ V_118 ] ;
V_93 -> V_102 = V_115 [ V_119 ] ;
}
return 0 ;
}
static int F_37 ( struct V_29 * V_30 , struct V_92 * V_93 )
{
int V_35 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_93 -> V_104 = - 1 ;
V_93 -> type = - 1 ;
if ( V_30 -> V_5 [ V_128 ] )
V_35 = F_33 ( V_30 -> V_5 [ V_128 ] , V_93 ) ;
else
V_35 = F_36 ( V_30 , V_93 ) ;
if ( V_35 )
return V_35 ;
if ( V_93 -> V_97 && V_93 -> V_99 )
return - V_16 ;
if ( V_93 -> V_99 ) {
if ( V_93 -> V_101 || ! V_93 -> V_102 )
return - V_16 ;
}
if ( V_93 -> V_104 != - 1 ) {
if ( V_93 -> V_99 ) {
if ( V_93 -> V_104 < 4 || V_93 -> V_104 > 5 )
return - V_16 ;
} else if ( V_93 -> V_97 ) {
if ( V_93 -> V_104 < 0 || V_93 -> V_104 > 3 )
return - V_16 ;
} else {
if ( V_93 -> V_104 < 0 || V_93 -> V_104 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_129 *
F_38 ( struct V_6 * V_7 ,
struct V_4 * V_130 , bool * V_131 )
{
struct V_92 V_132 ;
struct V_4 * V_91 ;
struct V_129 * V_8 ;
int V_133 , V_35 , V_97 = 0 ;
bool V_134 = false ;
F_39 (key, keys, rem) {
V_134 = true ;
break;
}
if ( ! V_134 )
return NULL ;
V_8 = F_40 ( sizeof( * V_8 ) , V_135 ) ;
if ( ! V_8 )
return F_3 ( - V_136 ) ;
V_8 -> V_97 = - 1 ;
F_39 (key, keys, rem) {
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
V_132 . V_104 = - 1 ;
V_35 = F_33 ( V_91 , & V_132 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_132 . V_106 . V_91 )
goto error;
if ( V_132 . V_104 < 0 || V_132 . V_104 > 3 )
goto error;
if ( V_132 . V_97 ) {
if ( V_97 )
goto error;
V_97 = 1 ;
V_8 -> V_97 = V_132 . V_104 ;
if ( ! V_132 . V_101 || ! V_132 . V_102 )
goto error;
} else if ( V_132 . V_99 )
goto error;
V_35 = F_41 ( V_7 , & V_132 . V_106 ,
V_132 . V_104 , false , NULL ) ;
if ( V_35 )
goto error;
if ( V_132 . V_106 . V_111 != V_137 &&
V_132 . V_106 . V_111 != V_138 ) {
V_35 = - V_16 ;
goto error;
}
V_8 -> V_139 [ V_132 . V_104 ] . V_111 = V_132 . V_106 . V_111 ;
V_8 -> V_139 [ V_132 . V_104 ] . V_107 = V_132 . V_106 . V_107 ;
V_8 -> V_139 [ V_132 . V_104 ] . V_91 = V_8 -> V_140 [ V_132 . V_104 ] ;
memcpy ( V_8 -> V_140 [ V_132 . V_104 ] , V_132 . V_106 . V_91 , V_132 . V_106 . V_107 ) ;
if ( V_131 )
* V_131 = true ;
}
if ( V_8 -> V_97 < 0 ) {
V_35 = - V_16 ;
goto error;
}
return V_8 ;
error:
F_42 ( V_8 ) ;
return F_3 ( V_35 ) ;
}
static int F_43 ( struct V_1 * V_17 )
{
F_44 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_145 :
break;
case V_146 :
case V_147 :
case V_148 :
if ( ! V_17 -> V_149 )
return - V_150 ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
return - V_16 ;
}
return 0 ;
}
static struct V_53 * F_45 ( struct V_18 * V_18 ,
struct V_4 * V_94 )
{
struct V_53 * V_54 ;
if ( V_94 == NULL )
return NULL ;
V_54 = F_46 ( V_18 , F_4 ( V_94 ) ) ;
if ( ! V_54 || V_54 -> V_50 & V_61 )
return NULL ;
return V_54 ;
}
static int F_47 ( struct V_31 * V_52 , V_22 V_44 , T_3 V_158 )
{
struct V_4 * V_159 = F_48 ( V_52 , V_44 ) ;
int V_160 ;
if ( ! V_159 )
goto V_60;
V_160 = 0 ;
while ( V_158 ) {
if ( ( V_158 & 1 ) && F_30 ( V_52 , V_160 ) )
goto V_60;
V_158 >>= 1 ;
V_160 ++ ;
}
F_49 ( V_52 , V_159 ) ;
return 0 ;
V_60:
return - V_90 ;
}
static int F_50 ( struct V_18 * V_18 ,
struct V_31 * V_52 ,
bool V_55 )
{
struct V_4 * V_161 ;
int V_160 , V_162 ;
V_161 = F_48 ( V_52 ,
V_163 ) ;
if ( ! V_161 )
goto V_60;
for ( V_160 = 0 ; V_160 < V_18 -> V_164 ; V_160 ++ ) {
const struct V_165 * V_166 ;
struct V_4 * V_167 , * V_168 ;
V_166 = & V_18 -> V_169 [ V_160 ] ;
V_167 = F_48 ( V_52 , V_160 + 1 ) ;
if ( ! V_167 )
goto V_60;
V_168 = F_48 ( V_52 , V_170 ) ;
if ( ! V_168 )
goto V_60;
for ( V_162 = 0 ; V_162 < V_166 -> V_171 ; V_162 ++ ) {
struct V_4 * V_172 ;
V_172 = F_48 ( V_52 , V_162 + 1 ) ;
if ( ! V_172 )
goto V_60;
if ( F_29 ( V_52 , V_173 ,
V_166 -> V_174 [ V_162 ] . V_175 ) )
goto V_60;
if ( F_47 ( V_52 , V_176 ,
V_166 -> V_174 [ V_162 ] . V_177 ) )
goto V_60;
F_49 ( V_52 , V_172 ) ;
}
F_49 ( V_52 , V_168 ) ;
if ( V_166 -> V_178 &&
F_30 ( V_52 , V_179 ) )
goto V_60;
if ( F_29 ( V_52 , V_180 ,
V_166 -> V_181 ) ||
F_29 ( V_52 , V_182 ,
V_166 -> V_183 ) )
goto V_60;
if ( V_55 &&
( F_29 ( V_52 , V_184 ,
V_166 -> V_185 ) ||
F_29 ( V_52 , V_186 ,
V_166 -> V_187 ) ) )
goto V_60;
if ( V_166 -> V_188 &&
F_29 ( V_52 , V_189 ,
V_166 -> V_188 ) )
goto V_60;
F_49 ( V_52 , V_167 ) ;
}
F_49 ( V_52 , V_161 ) ;
return 0 ;
V_60:
return - V_90 ;
}
static int F_51 ( struct V_6 * V_7 ,
struct V_31 * V_52 )
{
const struct V_190 * V_191 = V_7 -> V_18 . V_192 -> V_191 ;
struct V_4 * V_193 ;
if ( ! V_191 )
return 0 ;
V_193 = F_48 ( V_52 , V_194 ) ;
if ( ! V_193 )
return - V_90 ;
if ( F_29 ( V_52 , V_195 ,
V_191 -> V_196 ) )
return - V_90 ;
if ( F_29 ( V_52 , V_195 ,
V_191 -> V_196 ) )
return - V_90 ;
if ( V_191 -> V_49 && F_30 ( V_52 , V_197 ) )
return - V_90 ;
if ( V_191 -> V_198 && F_52 ( V_52 , V_199 ,
sizeof( * V_191 -> V_198 ) , V_191 -> V_198 ) )
return - V_90 ;
if ( F_29 ( V_52 , V_200 ,
V_191 -> V_201 ) )
return - V_90 ;
if ( F_29 ( V_52 , V_202 ,
V_191 -> V_203 ) )
return - V_90 ;
F_49 ( V_52 , V_193 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_52 ,
struct V_6 * V_7 ,
bool V_55 )
{
struct V_4 * V_204 ;
if ( ! V_7 -> V_18 . V_192 )
return 0 ;
V_204 = F_48 ( V_52 , V_205 ) ;
if ( ! V_204 )
return - V_90 ;
if ( ( ( V_7 -> V_18 . V_192 -> V_50 & V_206 ) &&
F_30 ( V_52 , V_207 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_50 & V_208 ) &&
F_30 ( V_52 , V_209 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_50 & V_210 ) &&
F_30 ( V_52 , V_211 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_50 & V_212 ) &&
F_30 ( V_52 , V_213 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_50 & V_214 ) &&
F_30 ( V_52 , V_215 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_50 & V_216 ) &&
F_30 ( V_52 , V_217 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_50 & V_218 ) &&
F_30 ( V_52 , V_219 ) ) ||
( ( V_7 -> V_18 . V_192 -> V_50 & V_220 ) &&
F_30 ( V_52 , V_221 ) ) )
return - V_90 ;
if ( V_7 -> V_18 . V_192 -> V_222 ) {
struct V_223 V_224 = {
. V_225 = V_7 -> V_18 . V_192 -> V_222 ,
. V_226 = V_7 -> V_18 . V_192 -> V_227 ,
. V_228 = V_7 -> V_18 . V_192 -> V_229 ,
. V_230 = V_7 -> V_18 . V_192 -> V_230 ,
} ;
if ( F_52 ( V_52 , V_231 ,
sizeof( V_224 ) , & V_224 ) )
return - V_90 ;
}
if ( ( V_7 -> V_18 . V_192 -> V_50 & V_232 ) &&
F_29 ( V_52 , V_233 ,
V_7 -> V_18 . V_192 -> V_234 ) )
return - V_90 ;
if ( V_55 && F_51 ( V_7 , V_52 ) )
return - V_90 ;
F_49 ( V_52 , V_204 ) ;
return 0 ;
}
static int F_54 ( struct V_31 * V_52 ,
struct V_6 * V_7 )
{
struct V_235 V_236 ;
if ( ! V_7 -> V_18 . V_237 )
return 0 ;
V_236 . V_238 = V_7 -> V_18 . V_237 -> V_239 ;
V_236 . V_240 = V_7 -> V_18 . V_237 -> V_240 ;
V_236 . V_224 . V_225 = V_7 -> V_18 . V_237 -> V_222 ;
V_236 . V_224 . V_226 = V_7 -> V_18 . V_237 -> V_227 ;
V_236 . V_224 . V_228 = V_7 -> V_18 . V_237 -> V_229 ;
V_236 . V_224 . V_230 = V_7 -> V_18 . V_237 -> V_230 ;
if ( F_52 ( V_52 , V_241 , sizeof( V_236 ) , & V_236 ) )
return - V_90 ;
return 0 ;
}
static int F_55 ( struct V_31 * V_52 ,
struct V_242 * V_243 )
{
struct V_4 * V_244 , * V_245 ;
struct V_246 * V_247 ;
int V_160 ;
if ( V_243 -> V_248 . V_249 &&
( F_52 ( V_52 , V_250 ,
sizeof( V_243 -> V_248 . V_251 ) ,
& V_243 -> V_248 . V_251 ) ||
F_56 ( V_52 , V_252 ,
V_243 -> V_248 . V_253 ) ||
F_57 ( V_52 , V_254 ,
V_243 -> V_248 . V_255 ) ||
F_57 ( V_52 , V_256 ,
V_243 -> V_248 . V_257 ) ) )
return - V_90 ;
if ( V_243 -> V_258 . V_259 &&
( F_52 ( V_52 , V_260 ,
sizeof( V_243 -> V_258 . V_261 ) ,
& V_243 -> V_258 . V_261 ) ||
F_29 ( V_52 , V_262 ,
V_243 -> V_258 . V_253 ) ) )
return - V_90 ;
V_244 = F_48 ( V_52 , V_263 ) ;
if ( ! V_244 )
return - V_90 ;
for ( V_160 = 0 ; V_160 < V_243 -> V_264 ; V_160 ++ ) {
V_245 = F_48 ( V_52 , V_160 ) ;
if ( ! V_245 )
return - V_90 ;
V_247 = & V_243 -> V_265 [ V_160 ] ;
if ( F_29 ( V_52 , V_266 ,
V_247 -> V_267 ) )
return - V_90 ;
if ( ( V_247 -> V_50 & V_268 ) &&
F_30 ( V_52 ,
V_269 ) )
return - V_90 ;
F_49 ( V_52 , V_245 ) ;
}
F_49 ( V_52 , V_244 ) ;
return 0 ;
}
static int
F_58 ( struct V_31 * V_52 ,
const struct V_270 * V_271 )
{
T_3 V_272 ;
struct V_4 * V_273 , * V_274 ;
enum V_275 V_276 ;
int V_160 ;
if ( ! V_271 )
return 0 ;
V_274 = F_48 ( V_52 , V_277 ) ;
if ( ! V_274 )
return - V_90 ;
for ( V_276 = 0 ; V_276 < V_157 ; V_276 ++ ) {
V_273 = F_48 ( V_52 , V_276 ) ;
if ( ! V_273 )
return - V_90 ;
V_160 = 0 ;
V_272 = V_271 [ V_276 ] . V_278 ;
while ( V_272 ) {
if ( ( V_272 & 1 ) &&
F_56 ( V_52 , V_279 ,
( V_160 << 4 ) | V_280 ) )
return - V_90 ;
V_272 >>= 1 ;
V_160 ++ ;
}
F_49 ( V_52 , V_273 ) ;
}
F_49 ( V_52 , V_274 ) ;
V_274 = F_48 ( V_52 , V_281 ) ;
if ( ! V_274 )
return - V_90 ;
for ( V_276 = 0 ; V_276 < V_157 ; V_276 ++ ) {
V_273 = F_48 ( V_52 , V_276 ) ;
if ( ! V_273 )
return - V_90 ;
V_160 = 0 ;
V_272 = V_271 [ V_276 ] . V_282 ;
while ( V_272 ) {
if ( ( V_272 & 1 ) &&
F_56 ( V_52 , V_279 ,
( V_160 << 4 ) | V_280 ) )
return - V_90 ;
V_272 >>= 1 ;
V_160 ++ ;
}
F_49 ( V_52 , V_273 ) ;
}
F_49 ( V_52 , V_274 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_31 * V_52 )
{
int V_160 = 0 ;
F_60 ( V_283 , V_284 ) ;
F_60 ( V_285 , V_286 ) ;
F_60 ( V_287 , V_288 ) ;
F_60 ( V_289 , V_290 ) ;
F_60 ( V_291 , V_292 ) ;
F_60 ( V_293 , V_294 ) ;
F_60 ( V_295 , V_296 ) ;
F_60 ( V_297 , V_298 ) ;
F_60 ( V_299 , V_300 ) ;
F_60 ( V_301 , V_302 ) ;
F_60 ( V_303 , V_304 ) ;
F_60 ( V_305 , V_306 ) ;
F_60 ( V_307 , V_308 ) ;
F_60 ( V_309 , V_310 ) ;
F_60 ( V_311 , V_312 ) ;
F_60 ( V_313 , V_314 ) ;
F_60 ( V_315 , V_316 ) ;
if ( V_7 -> V_18 . V_50 & V_317 )
F_60 ( V_318 , V_319 ) ;
F_60 ( V_320 , V_321 ) ;
F_60 ( V_322 , V_323 ) ;
F_60 ( V_324 , V_325 ) ;
if ( V_7 -> V_18 . V_50 & V_326 ) {
V_160 ++ ;
if ( F_29 ( V_52 , V_160 , V_327 ) )
goto V_60;
}
if ( V_7 -> V_328 -> V_329 || V_7 -> V_328 -> V_289 ||
V_7 -> V_328 -> V_309 ) {
V_160 ++ ;
if ( F_29 ( V_52 , V_160 , V_330 ) )
goto V_60;
}
F_60 ( V_331 , V_332 ) ;
if ( V_7 -> V_18 . V_50 & V_333 ) {
F_60 ( V_334 , V_335 ) ;
F_60 ( V_336 , V_337 ) ;
}
if ( V_7 -> V_18 . V_50 & V_338 )
F_60 ( V_339 , V_340 ) ;
F_60 ( V_341 , V_342 ) ;
F_60 ( V_343 , V_344 ) ;
if ( V_7 -> V_18 . V_50 & V_345 ) {
V_160 ++ ;
if ( F_29 ( V_52 , V_160 , V_346 ) )
goto V_60;
}
F_60 ( V_347 , V_348 ) ;
F_60 ( V_349 , V_350 ) ;
#ifdef F_61
F_60 ( V_351 , V_352 ) ;
#endif
if ( V_7 -> V_328 -> V_353 || V_7 -> V_328 -> V_299 ) {
V_160 ++ ;
if ( F_29 ( V_52 , V_160 , V_354 ) )
goto V_60;
}
if ( V_7 -> V_328 -> V_355 || V_7 -> V_328 -> V_303 ) {
V_160 ++ ;
if ( F_29 ( V_52 , V_160 , V_356 ) )
goto V_60;
}
return V_160 ;
V_60:
return - V_90 ;
}
static int F_62 ( struct V_6 * V_7 ,
enum V_357 V_51 ,
struct V_31 * V_52 , V_22 V_48 , V_22 V_49 ,
int V_50 , struct V_358 * V_359 )
{
void * V_360 ;
struct V_4 * V_361 , * V_362 ;
struct V_4 * V_363 , * V_364 ;
struct V_4 * V_365 ;
enum V_366 V_367 ;
struct V_53 * V_54 ;
int V_160 ;
const struct V_270 * V_271 =
V_7 -> V_18 . V_271 ;
V_22 V_368 ;
V_360 = F_26 ( V_52 , V_48 , V_49 , V_50 , V_51 ) ;
if ( ! V_360 )
return - V_90 ;
if ( F_63 ( ! V_359 ) )
return - V_16 ;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_64 ( V_52 , V_369 ,
F_65 ( & V_7 -> V_18 ) ) ||
F_29 ( V_52 , V_370 ,
V_371 ) )
goto V_60;
if ( V_51 != V_372 )
goto V_373;
switch ( V_359 -> V_374 ) {
case 0 :
if ( F_57 ( V_52 , V_375 ,
V_7 -> V_18 . V_376 ) ||
F_57 ( V_52 , V_377 ,
V_7 -> V_18 . V_378 ) ||
F_29 ( V_52 , V_379 ,
V_7 -> V_18 . V_380 ) ||
F_29 ( V_52 , V_381 ,
V_7 -> V_18 . V_382 ) ||
F_57 ( V_52 , V_383 ,
V_7 -> V_18 . V_384 ) ||
F_57 ( V_52 , V_385 ,
V_7 -> V_18 . V_386 ) ||
F_57 ( V_52 , V_387 ,
V_7 -> V_18 . V_388 ) ||
F_56 ( V_52 , V_389 ,
V_7 -> V_18 . V_390 ) ||
F_56 ( V_52 , V_391 ,
V_7 -> V_18 . V_392 ) ||
F_57 ( V_52 , V_393 ,
V_7 -> V_18 . V_394 ) ||
F_29 ( V_52 , V_395 ,
V_7 -> V_18 . V_396 ) ||
F_29 ( V_52 , V_397 ,
V_7 -> V_18 . V_398 ) ||
F_29 ( V_52 , V_399 ,
V_7 -> V_18 . V_400 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_401 ) &&
F_30 ( V_52 , V_402 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_403 ) &&
F_30 ( V_52 , V_404 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_405 ) &&
F_30 ( V_52 , V_406 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_407 ) &&
F_30 ( V_52 , V_408 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_333 ) &&
F_30 ( V_52 , V_409 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_410 ) &&
F_30 ( V_52 , V_411 ) )
goto V_60;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 1 :
if ( F_52 ( V_52 , V_413 ,
sizeof( V_22 ) * V_7 -> V_18 . V_414 ,
V_7 -> V_18 . V_415 ) )
goto V_60;
if ( F_57 ( V_52 , V_416 ,
V_7 -> V_18 . V_417 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_418 ) &&
F_30 ( V_52 , V_419 ) )
goto V_60;
if ( F_29 ( V_52 , V_420 ,
V_7 -> V_18 . V_421 ) ||
F_29 ( V_52 , V_422 ,
V_7 -> V_18 . V_423 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_424 ) &&
F_29 ( V_52 , V_425 ,
V_7 -> V_18 . V_426 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_421 ||
V_7 -> V_18 . V_423 ) &&
V_7 -> V_328 -> V_427 ) {
V_22 V_428 = 0 , V_429 = 0 ;
int V_430 ;
V_430 = F_66 ( V_7 , & V_428 , & V_429 ) ;
if ( ! V_430 ) {
if ( F_29 ( V_52 ,
V_431 ,
V_428 ) ||
F_29 ( V_52 ,
V_432 ,
V_429 ) )
goto V_60;
}
}
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 2 :
if ( F_47 ( V_52 , V_433 ,
V_7 -> V_18 . V_434 ) )
goto V_60;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 3 :
V_361 = F_48 ( V_52 , V_435 ) ;
if ( ! V_361 )
goto V_60;
for ( V_367 = V_359 -> V_436 ;
V_367 < V_437 ; V_367 ++ ) {
struct V_242 * V_243 ;
V_243 = V_7 -> V_18 . V_438 [ V_367 ] ;
if ( ! V_243 )
continue;
V_362 = F_48 ( V_52 , V_367 ) ;
if ( ! V_362 )
goto V_60;
switch ( V_359 -> V_439 ) {
case 0 :
if ( F_55 ( V_52 , V_243 ) )
goto V_60;
V_359 -> V_439 ++ ;
if ( V_359 -> V_412 )
break;
default:
V_363 = F_48 (
V_52 , V_440 ) ;
if ( ! V_363 )
goto V_60;
for ( V_160 = V_359 -> V_439 - 1 ;
V_160 < V_243 -> V_441 ;
V_160 ++ ) {
V_364 = F_48 ( V_52 , V_160 ) ;
if ( ! V_364 )
goto V_60;
V_54 = & V_243 -> V_442 [ V_160 ] ;
if ( F_28 (
V_52 , V_54 ,
V_359 -> V_412 ) )
goto V_60;
F_49 ( V_52 , V_364 ) ;
if ( V_359 -> V_412 )
break;
}
if ( V_160 < V_243 -> V_441 )
V_359 -> V_439 = V_160 + 2 ;
else
V_359 -> V_439 = 0 ;
F_49 ( V_52 , V_363 ) ;
}
F_49 ( V_52 , V_362 ) ;
if ( V_359 -> V_412 ) {
if ( V_359 -> V_439 )
V_367 -- ;
break;
}
}
F_49 ( V_52 , V_361 ) ;
if ( V_367 < V_437 )
V_359 -> V_436 = V_367 + 1 ;
else
V_359 -> V_436 = 0 ;
if ( V_359 -> V_436 == 0 && V_359 -> V_439 == 0 )
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 4 :
V_365 = F_48 ( V_52 , V_443 ) ;
if ( ! V_365 )
goto V_60;
V_160 = F_59 ( V_7 , V_52 ) ;
if ( V_160 < 0 )
goto V_60;
if ( V_359 -> V_412 ) {
F_60 ( V_444 , V_445 ) ;
F_60 ( V_446 , V_447 ) ;
if ( V_7 -> V_18 . V_50 & V_448 )
F_60 ( V_449 , V_450 ) ;
F_60 ( V_451 , V_452 ) ;
if ( V_7 -> V_18 . V_368 &
V_453 )
F_60 ( V_454 , V_455 ) ;
F_60 ( V_456 , V_457 ) ;
F_60 ( V_458 , V_459 ) ;
}
#undef F_60
F_49 ( V_52 , V_365 ) ;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 5 :
if ( V_7 -> V_328 -> V_318 &&
( V_7 -> V_18 . V_50 & V_317 ) &&
F_29 ( V_52 ,
V_460 ,
V_7 -> V_18 . V_461 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_462 ) &&
F_30 ( V_52 , V_463 ) )
goto V_60;
if ( F_58 ( V_52 , V_271 ) )
goto V_60;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 6 :
#ifdef F_67
if ( F_53 ( V_52 , V_7 , V_359 -> V_412 ) )
goto V_60;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
#else
V_359 -> V_374 ++ ;
#endif
case 7 :
if ( F_47 ( V_52 , V_464 ,
V_7 -> V_18 . V_465 ) )
goto V_60;
if ( F_50 ( & V_7 -> V_18 , V_52 ,
V_359 -> V_412 ) )
goto V_60;
V_359 -> V_374 ++ ;
if ( V_359 -> V_412 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_50 & V_466 ) &&
F_29 ( V_52 , V_467 ,
V_7 -> V_18 . V_468 ) )
goto V_60;
V_368 = V_7 -> V_18 . V_368 ;
if ( V_359 -> V_412 )
V_368 |= V_469 ;
if ( F_29 ( V_52 , V_470 , V_368 ) )
goto V_60;
if ( V_7 -> V_18 . V_471 &&
F_52 ( V_52 , V_472 ,
sizeof( * V_7 -> V_18 . V_471 ) ,
V_7 -> V_18 . V_471 ) )
goto V_60;
if ( V_7 -> V_18 . V_50 & V_466 &&
V_7 -> V_18 . V_473 &&
F_29 ( V_52 , V_474 ,
V_7 -> V_18 . V_473 ) )
goto V_60;
V_359 -> V_374 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_475 &&
( F_52 ( V_52 , V_476 ,
V_7 -> V_18 . V_477 ,
V_7 -> V_18 . V_475 ) ||
F_52 ( V_52 , V_478 ,
V_7 -> V_18 . V_477 ,
V_7 -> V_18 . V_479 ) ) )
goto V_60;
if ( V_7 -> V_18 . V_480 &&
F_52 ( V_52 , V_481 ,
sizeof( * V_7 -> V_18 . V_480 ) ,
V_7 -> V_18 . V_480 ) )
goto V_60;
V_359 -> V_374 ++ ;
break;
case 10 :
if ( F_54 ( V_52 , V_7 ) )
goto V_60;
if ( ( V_7 -> V_18 . V_50 & V_482 ) &&
( F_30 ( V_52 , V_483 ) ||
F_30 ( V_52 , V_484 ) ) )
goto V_60;
if ( V_7 -> V_18 . V_485 &&
F_29 ( V_52 , V_486 ,
V_7 -> V_18 . V_485 ) )
goto V_60;
V_359 -> V_374 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_487 ) {
const struct V_488 * V_30 ;
struct V_4 * V_489 ;
V_489 = F_48 ( V_52 , V_490 ) ;
if ( ! V_489 )
goto V_60;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_487 ; V_160 ++ ) {
V_30 = & V_7 -> V_18 . V_491 [ V_160 ] . V_30 ;
if ( F_52 ( V_52 , V_160 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_60;
}
F_49 ( V_52 , V_489 ) ;
}
if ( V_7 -> V_18 . V_492 ) {
const struct V_488 * V_30 ;
struct V_4 * V_489 ;
V_489 = F_48 ( V_52 ,
V_493 ) ;
if ( ! V_489 )
goto V_60;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_492 ; V_160 ++ ) {
V_30 = & V_7 -> V_18 . V_494 [ V_160 ] ;
if ( F_52 ( V_52 , V_160 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_60;
}
F_49 ( V_52 , V_489 ) ;
}
V_359 -> V_374 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_50 & V_448 &&
F_57 ( V_52 , V_495 ,
V_7 -> V_18 . V_496 ) )
goto V_60;
if ( V_7 -> V_18 . V_497 & V_498 &&
F_30 ( V_52 , V_499 ) )
goto V_60;
if ( F_52 ( V_52 , V_500 ,
sizeof( V_7 -> V_18 . V_501 ) ,
V_7 -> V_18 . V_501 ) )
goto V_60;
if ( V_7 -> V_18 . V_502 ) {
struct V_4 * V_489 ;
V_22 V_502 = V_7 -> V_18 . V_502 ;
V_489 = F_48 ( V_52 , V_503 ) ;
if ( ! V_489 )
goto V_60;
V_160 = 0 ;
while ( V_502 ) {
if ( ( V_502 & 1 ) &&
F_30 ( V_52 , V_160 ) )
goto V_60;
V_160 ++ ;
V_502 >>= 1 ;
}
F_49 ( V_52 , V_489 ) ;
}
V_359 -> V_374 ++ ;
break;
case 13 :
if ( V_7 -> V_18 . V_504 &&
V_7 -> V_18 . V_505 ) {
struct V_4 * V_506 , * V_489 ;
V_489 = F_48 ( V_52 ,
V_507 ) ;
if ( ! V_489 )
goto V_60;
for ( V_160 = V_359 -> V_508 ;
V_160 < V_7 -> V_18 . V_504 ; V_160 ++ ) {
const struct V_509 * V_510 ;
V_510 = & V_7 -> V_18 . V_505 [ V_160 ] ;
V_506 = F_48 ( V_52 , V_160 ) ;
if ( ! V_506 ||
F_29 ( V_52 , V_511 ,
V_510 -> V_141 ) ||
F_52 ( V_52 , V_476 ,
V_510 -> V_477 ,
V_510 -> V_475 ) ||
F_52 ( V_52 , V_478 ,
V_510 -> V_477 ,
V_510 -> V_479 ) )
goto V_60;
F_49 ( V_52 , V_506 ) ;
if ( V_359 -> V_412 )
break;
}
F_49 ( V_52 , V_489 ) ;
if ( V_160 < V_7 -> V_18 . V_504 ) {
V_359 -> V_508 = V_160 + 1 ;
break;
}
}
V_359 -> V_374 = 0 ;
break;
}
V_373:
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int F_70 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_358 * V_359 )
{
struct V_4 * * V_94 = F_16 ( & V_38 ) ;
int V_513 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_94 , V_38 . V_40 , V_41 ) ;
if ( V_513 )
return 0 ;
V_359 -> V_412 = V_94 [ V_514 ] ;
if ( V_94 [ V_26 ] )
V_359 -> V_515 = F_4 ( V_94 [ V_26 ] ) ;
if ( V_94 [ V_12 ] )
V_359 -> V_515 = F_5 ( V_94 [ V_12 ] ) >> 32 ;
if ( V_94 [ V_10 ] ) {
struct V_25 * V_19 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_94 [ V_10 ] ) ;
V_19 = F_10 ( F_17 ( V_32 -> V_43 ) , V_15 ) ;
if ( ! V_19 )
return - V_23 ;
if ( V_19 -> V_28 ) {
V_7 = F_11 (
V_19 -> V_28 -> V_18 ) ;
V_359 -> V_515 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_71 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_104 = 0 , V_513 ;
struct V_358 * V_359 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_359 ) {
V_359 = F_40 ( sizeof( * V_359 ) , V_135 ) ;
if ( ! V_359 ) {
F_21 () ;
return - V_136 ;
}
V_359 -> V_515 = - 1 ;
V_513 = F_70 ( V_32 , V_34 , V_359 ) ;
if ( V_513 ) {
F_42 ( V_359 ) ;
F_21 () ;
return V_513 ;
}
V_34 -> args [ 0 ] = ( long ) V_359 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_72 ( F_7 ( & V_7 -> V_18 ) , F_17 ( V_32 -> V_43 ) ) )
continue;
if ( ++ V_104 <= V_359 -> V_516 )
continue;
if ( V_359 -> V_515 != - 1 &&
V_359 -> V_515 != V_7 -> V_14 )
continue;
do {
V_513 = F_62 ( V_7 , V_372 ,
V_32 ,
F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 ,
V_518 , V_359 ) ;
if ( V_513 < 0 ) {
if ( ( V_513 == - V_90 || V_513 == - V_512 ) &&
! V_32 -> V_46 && ! V_359 -> V_412 &&
V_34 -> V_519 < 4096 ) {
V_34 -> V_519 = 4096 ;
V_359 -> V_374 = 0 ;
F_21 () ;
return 1 ;
}
V_104 -- ;
break;
}
} while ( V_359 -> V_374 > 0 );
break;
}
F_21 () ;
V_359 -> V_516 = V_104 ;
return V_32 -> V_46 ;
}
static int F_74 ( struct V_33 * V_34 )
{
F_42 ( ( void * ) V_34 -> args [ 0 ] ) ;
return 0 ;
}
static int F_75 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_52 ;
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_358 V_359 = {} ;
V_52 = F_76 ( 4096 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
if ( F_62 ( V_7 , V_372 , V_52 ,
V_30 -> V_521 , V_30 -> V_522 , 0 ,
& V_359 ) < 0 ) {
F_77 ( V_52 ) ;
return - V_90 ;
}
return F_78 ( V_52 , V_30 ) ;
}
static int F_79 ( struct V_4 * V_94 [] ,
struct V_523 * V_524 )
{
if ( ! V_94 [ V_525 ] || ! V_94 [ V_526 ] ||
! V_94 [ V_527 ] || ! V_94 [ V_528 ] ||
! V_94 [ V_529 ] )
return - V_16 ;
V_524 -> V_530 = F_35 ( V_94 [ V_525 ] ) ;
V_524 -> V_531 = F_80 ( V_94 [ V_526 ] ) ;
V_524 -> V_532 = F_80 ( V_94 [ V_527 ] ) ;
V_524 -> V_533 = F_80 ( V_94 [ V_528 ] ) ;
V_524 -> V_534 = F_35 ( V_94 [ V_529 ] ) ;
if ( V_524 -> V_530 >= V_535 )
return - V_16 ;
return 0 ;
}
static bool F_81 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_141 == V_142 ||
V_17 -> V_141 == V_145 ||
V_17 -> V_141 == V_153 ||
V_17 -> V_141 == V_144 ;
}
static int F_82 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_536 * V_537 )
{
V_22 V_538 ;
if ( ! V_30 -> V_5 [ V_539 ] )
return - V_16 ;
V_538 = F_4 ( V_30 -> V_5 [ V_539 ] ) ;
V_537 -> V_54 = F_46 ( & V_7 -> V_18 , V_538 ) ;
V_537 -> V_540 = V_541 ;
V_537 -> V_542 = V_538 ;
V_537 -> V_543 = 0 ;
if ( ! V_537 -> V_54 || V_537 -> V_54 -> V_50 & V_61 )
return - V_16 ;
if ( V_30 -> V_5 [ V_544 ] ) {
enum V_545 V_546 ;
V_546 = F_4 (
V_30 -> V_5 [ V_544 ] ) ;
switch ( V_546 ) {
case V_547 :
case V_548 :
case V_549 :
case V_550 :
F_83 ( V_537 , V_537 -> V_54 ,
V_546 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_551 ] ) {
V_537 -> V_540 =
F_4 ( V_30 -> V_5 [ V_551 ] ) ;
if ( V_30 -> V_5 [ V_552 ] )
V_537 -> V_542 =
F_4 (
V_30 -> V_5 [ V_552 ] ) ;
if ( V_30 -> V_5 [ V_553 ] )
V_537 -> V_543 =
F_4 (
V_30 -> V_5 [ V_553 ] ) ;
}
if ( ! F_84 ( V_537 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , V_537 ,
V_61 ) )
return - V_16 ;
if ( ( V_537 -> V_540 == V_554 ||
V_537 -> V_540 == V_555 ) &&
! ( V_7 -> V_18 . V_50 & V_482 ) )
return - V_16 ;
return 0 ;
}
static int F_86 ( struct V_6 * V_7 ,
struct V_25 * V_556 ,
struct V_29 * V_30 )
{
struct V_536 V_537 ;
int V_8 ;
enum V_275 V_141 = V_153 ;
struct V_1 * V_17 = NULL ;
if ( V_556 )
V_17 = V_556 -> V_28 ;
if ( ! F_81 ( V_17 ) )
return - V_557 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_82 ( V_7 , V_30 , & V_537 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_87 ( & V_7 -> V_18 , & V_537 ,
V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_558 ) {
if ( ! V_556 || ! V_7 -> V_328 -> V_559 ||
! ( V_7 -> V_18 . V_368 &
V_560 ) ) {
V_8 = - V_561 ;
break;
}
if ( V_537 . V_54 != V_17 -> V_562 . V_54 ) {
V_8 = - V_561 ;
break;
}
V_8 = F_88 ( V_7 , V_556 , & V_537 ) ;
if ( V_8 )
break;
}
V_17 -> V_562 = V_537 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_89 ( V_7 , V_17 , & V_537 ) ;
break;
case V_153 :
V_8 = F_90 ( V_7 , & V_537 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_91 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_520 [ 1 ] ;
return F_86 ( V_7 , V_19 , V_30 ) ;
}
static int F_92 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
const T_2 * V_563 ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( F_93 ( V_556 ) )
return - V_561 ;
if ( ! V_7 -> V_328 -> V_331 )
return - V_557 ;
if ( V_17 -> V_141 != V_156 )
return - V_557 ;
V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
return F_94 ( V_7 , V_556 , V_563 ) ;
}
static int F_95 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_565 = 0 ;
struct V_4 * V_566 ;
V_22 V_567 ;
T_2 V_376 = 0 , V_378 = 0 ;
V_22 V_380 = 0 , V_382 = 0 ;
T_2 V_384 = 0 ;
F_2 () ;
if ( V_30 -> V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_30 -> V_5 [ V_10 ] ) ;
V_19 = F_10 ( F_96 ( V_30 ) , V_20 ) ;
if ( V_19 && V_19 -> V_28 )
V_7 = F_11 ( V_19 -> V_28 -> V_18 ) ;
else
V_19 = NULL ;
}
if ( ! V_19 ) {
V_7 = F_8 ( F_96 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_18 ( V_7 ) )
return F_19 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_369 ] )
V_8 = F_97 (
V_7 , F_24 ( V_30 -> V_5 [ V_369 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_568 ] ) {
struct V_523 V_524 ;
struct V_4 * V_94 [ V_569 + 1 ] ;
if ( ! V_7 -> V_328 -> V_570 )
return - V_557 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_93 ( V_19 ) )
return - V_571 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_34 ( V_94 , V_569 ,
V_566 ,
V_572 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_79 ( V_94 , & V_524 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_98 ( V_7 , V_19 ,
& V_524 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_539 ] ) {
V_8 = F_86 (
V_7 ,
F_81 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_573 ] ) {
struct V_1 * V_574 = V_17 ;
enum V_575 type ;
int V_104 , V_576 = 0 ;
if ( ! ( V_7 -> V_18 . V_368 & V_577 ) )
V_574 = NULL ;
if ( ! V_7 -> V_328 -> V_578 )
return - V_557 ;
V_104 = V_573 ;
type = F_4 ( V_30 -> V_5 [ V_104 ] ) ;
if ( ! V_30 -> V_5 [ V_579 ] &&
( type != V_580 ) )
return - V_16 ;
if ( type != V_580 ) {
V_104 = V_579 ;
V_576 = F_4 ( V_30 -> V_5 [ V_104 ] ) ;
}
V_8 = F_99 ( V_7 , V_574 , type , V_576 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_431 ] &&
V_30 -> V_5 [ V_432 ] ) {
V_22 V_428 , V_429 ;
if ( ( ! V_7 -> V_18 . V_421 &&
! V_7 -> V_18 . V_423 ) ||
! V_7 -> V_328 -> V_581 )
return - V_557 ;
V_428 = F_4 ( V_30 -> V_5 [ V_431 ] ) ;
V_429 = F_4 ( V_30 -> V_5 [ V_432 ] ) ;
if ( ( ~ V_428 && ( V_428 & ~ V_7 -> V_18 . V_421 ) ) ||
( ~ V_429 && ( V_429 & ~ V_7 -> V_18 . V_423 ) ) )
return - V_16 ;
V_428 = V_428 & V_7 -> V_18 . V_421 ;
V_429 = V_429 & V_7 -> V_18 . V_423 ;
V_8 = F_100 ( V_7 , V_428 , V_429 ) ;
if ( V_8 )
return V_8 ;
}
V_567 = 0 ;
if ( V_30 -> V_5 [ V_375 ] ) {
V_376 = F_35 (
V_30 -> V_5 [ V_375 ] ) ;
if ( V_376 == 0 )
return - V_16 ;
V_567 |= V_582 ;
}
if ( V_30 -> V_5 [ V_377 ] ) {
V_378 = F_35 (
V_30 -> V_5 [ V_377 ] ) ;
if ( V_378 == 0 )
return - V_16 ;
V_567 |= V_583 ;
}
if ( V_30 -> V_5 [ V_379 ] ) {
V_380 = F_4 (
V_30 -> V_5 [ V_379 ] ) ;
if ( V_380 < 256 )
return - V_16 ;
if ( V_380 != ( V_22 ) - 1 ) {
V_380 &= ~ 0x1 ;
}
V_567 |= V_584 ;
}
if ( V_30 -> V_5 [ V_381 ] ) {
V_382 = F_4 (
V_30 -> V_5 [ V_381 ] ) ;
V_567 |= V_585 ;
}
if ( V_30 -> V_5 [ V_383 ] ) {
if ( V_30 -> V_5 [ V_586 ] )
return - V_16 ;
V_384 = F_35 (
V_30 -> V_5 [ V_383 ] ) ;
V_567 |= V_587 ;
}
if ( V_30 -> V_5 [ V_586 ] ) {
if ( ! ( V_7 -> V_18 . V_368 & V_588 ) )
return - V_557 ;
V_567 |= V_589 ;
}
if ( V_567 ) {
T_2 V_590 , V_591 ;
V_22 V_592 , V_593 ;
T_2 V_594 ;
if ( ! V_7 -> V_328 -> V_595 )
return - V_557 ;
V_590 = V_7 -> V_18 . V_376 ;
V_591 = V_7 -> V_18 . V_378 ;
V_592 = V_7 -> V_18 . V_380 ;
V_593 = V_7 -> V_18 . V_382 ;
V_594 = V_7 -> V_18 . V_384 ;
if ( V_567 & V_582 )
V_7 -> V_18 . V_376 = V_376 ;
if ( V_567 & V_583 )
V_7 -> V_18 . V_378 = V_378 ;
if ( V_567 & V_584 )
V_7 -> V_18 . V_380 = V_380 ;
if ( V_567 & V_585 )
V_7 -> V_18 . V_382 = V_382 ;
if ( V_567 & V_587 )
V_7 -> V_18 . V_384 = V_384 ;
V_8 = F_101 ( V_7 , V_567 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_376 = V_590 ;
V_7 -> V_18 . V_378 = V_591 ;
V_7 -> V_18 . V_380 = V_592 ;
V_7 -> V_18 . V_382 = V_593 ;
V_7 -> V_18 . V_384 = V_594 ;
return V_8 ;
}
}
return 0 ;
}
static inline T_1 V_13 ( struct V_1 * V_17 )
{
return ( T_1 ) V_17 -> V_21 |
( ( T_1 ) F_11 ( V_17 -> V_18 ) -> V_14 << 32 ) ;
}
static int F_102 ( struct V_31 * V_52 ,
const struct V_536 * V_537 )
{
if ( F_63 ( ! F_84 ( V_537 ) ) )
return - V_16 ;
if ( F_29 ( V_52 , V_539 ,
V_537 -> V_54 -> V_59 ) )
return - V_90 ;
switch ( V_537 -> V_540 ) {
case V_541 :
case V_596 :
case V_597 :
if ( F_29 ( V_52 , V_544 ,
F_103 ( V_537 ) ) )
return - V_90 ;
break;
default:
break;
}
if ( F_29 ( V_52 , V_551 , V_537 -> V_540 ) )
return - V_90 ;
if ( F_29 ( V_52 , V_552 , V_537 -> V_542 ) )
return - V_90 ;
if ( V_537 -> V_543 &&
F_29 ( V_52 , V_553 , V_537 -> V_543 ) )
return - V_90 ;
return 0 ;
}
static int F_104 ( struct V_31 * V_52 , V_22 V_48 , V_22 V_49 , int V_50 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_598 )
{
struct V_25 * V_556 = V_17 -> V_19 ;
T_2 V_51 = V_599 ;
void * V_360 ;
if ( V_598 )
V_51 = V_600 ;
V_360 = F_26 ( V_52 , V_48 , V_49 , V_50 , V_51 ) ;
if ( ! V_360 )
return - 1 ;
if ( V_556 &&
( F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_64 ( V_52 , V_601 , V_556 -> V_602 ) ) )
goto V_60;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_511 , V_17 -> V_141 ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) ||
F_52 ( V_52 , V_564 , V_604 , F_106 ( V_17 ) ) ||
F_29 ( V_52 , V_370 ,
V_7 -> V_605 ^
( V_371 << 2 ) ) )
goto V_60;
if ( V_7 -> V_328 -> V_606 ) {
int V_513 ;
struct V_536 V_537 ;
V_513 = F_107 ( V_7 , V_17 , & V_537 ) ;
if ( V_513 == 0 ) {
if ( F_102 ( V_52 , & V_537 ) )
goto V_60;
}
}
if ( V_7 -> V_328 -> V_607 ) {
int V_608 , V_513 ;
V_513 = F_108 ( V_7 , V_17 , & V_608 ) ;
if ( V_513 == 0 &&
F_29 ( V_52 , V_579 ,
F_32 ( V_608 ) ) )
goto V_60;
}
if ( V_17 -> V_609 ) {
if ( F_52 ( V_52 , V_610 , V_17 -> V_609 , V_17 -> V_611 ) )
goto V_60;
}
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_612 = 0 ;
int V_613 = 0 ;
int V_614 = V_34 -> args [ 0 ] ;
int V_615 = V_34 -> args [ 1 ] ;
int V_515 = - 1 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
if ( ! V_34 -> args [ 2 ] ) {
struct V_358 V_359 = {
. V_515 = - 1 ,
} ;
int V_513 ;
V_513 = F_70 ( V_32 , V_34 , & V_359 ) ;
if ( V_513 )
return V_513 ;
V_515 = V_359 . V_515 ;
if ( V_515 >= 0 )
V_34 -> args [ 2 ] = V_515 + 1 ;
else
V_34 -> args [ 2 ] = - 1 ;
} else if ( V_34 -> args [ 2 ] > 0 ) {
V_515 = V_34 -> args [ 2 ] - 1 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_72 ( F_7 ( & V_7 -> V_18 ) , F_17 ( V_32 -> V_43 ) ) )
continue;
if ( V_612 < V_614 ) {
V_612 ++ ;
continue;
}
if ( V_515 >= 0 && V_515 != V_7 -> V_14 )
continue;
V_613 = 0 ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_613 < V_615 ) {
V_613 ++ ;
continue;
}
if ( F_104 ( V_32 , F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_7 , V_17 , false ) < 0 ) {
goto V_616;
}
V_613 ++ ;
}
V_612 ++ ;
}
V_616:
F_21 () ;
V_34 -> args [ 0 ] = V_612 ;
V_34 -> args [ 1 ] = V_613 ;
return V_32 -> V_46 ;
}
static int F_110 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_52 ;
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
if ( F_104 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_77 ( V_52 ) ;
return - V_90 ;
}
return F_78 ( V_52 , V_30 ) ;
}
static int F_111 ( struct V_4 * V_618 , V_22 * V_619 )
{
struct V_4 * V_50 [ V_620 + 1 ] ;
int V_621 ;
* V_619 = 0 ;
if ( ! V_618 )
return - V_16 ;
if ( F_34 ( V_50 , V_620 ,
V_618 , V_622 ) )
return - V_16 ;
for ( V_621 = 1 ; V_621 <= V_620 ; V_621 ++ )
if ( V_50 [ V_621 ] )
* V_619 |= ( 1 << V_621 ) ;
return 0 ;
}
static int F_112 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_623 ,
enum V_275 V_141 )
{
if ( ! V_623 ) {
if ( V_19 && ( V_19 -> V_624 & V_625 ) )
return - V_561 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_50 & V_626 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_50 & V_627 )
return 0 ;
break;
default:
break;
}
return - V_557 ;
}
static int F_113 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_628 V_139 ;
int V_35 ;
enum V_275 V_629 , V_630 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
V_22 V_631 , * V_50 = NULL ;
bool V_632 = false ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_629 = V_630 = V_556 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_511 ] ) {
V_630 = F_4 ( V_30 -> V_5 [ V_511 ] ) ;
if ( V_629 != V_630 )
V_632 = true ;
if ( V_630 > V_633 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_634 ] ) {
struct V_1 * V_17 = V_556 -> V_28 ;
if ( V_630 != V_145 )
return - V_16 ;
if ( F_93 ( V_556 ) )
return - V_561 ;
F_114 ( V_17 ) ;
F_115 ( V_635 !=
V_636 ) ;
V_17 -> V_637 =
F_25 ( V_30 -> V_5 [ V_634 ] ) ;
memcpy ( V_17 -> V_611 , F_24 ( V_30 -> V_5 [ V_634 ] ) ,
V_17 -> V_637 ) ;
F_116 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_638 ] ) {
V_139 . V_623 = ! ! F_35 ( V_30 -> V_5 [ V_638 ] ) ;
V_632 = true ;
V_35 = F_112 ( V_7 , V_556 , V_139 . V_623 , V_630 ) ;
if ( V_35 )
return V_35 ;
} else {
V_139 . V_623 = - 1 ;
}
if ( V_30 -> V_5 [ V_639 ] ) {
if ( V_630 != V_153 )
return - V_16 ;
V_35 = F_111 ( V_30 -> V_5 [ V_639 ] ,
& V_631 ) ;
if ( V_35 )
return V_35 ;
V_50 = & V_631 ;
V_632 = true ;
}
if ( V_30 -> V_5 [ V_640 ] ) {
const T_2 * V_641 ;
V_22 V_642 = V_643 ;
if ( ! F_117 ( & V_7 -> V_18 , V_642 ) )
return - V_557 ;
V_641 =
F_24 ( V_30 -> V_5 [ V_640 ] ) ;
if ( ( V_641 [ 0 ] & F_118 ( 7 ) ) ||
( V_641 [ V_644 - 1 ] & F_118 ( 0 ) ) )
return - V_16 ;
memcpy ( V_139 . V_645 , V_641 ,
V_644 ) ;
V_632 = true ;
}
if ( V_30 -> V_5 [ V_646 ] ) {
V_22 V_642 = V_643 ;
if ( ! F_117 ( & V_7 -> V_18 , V_642 ) )
return - V_557 ;
F_119 ( V_139 . V_647 ,
V_30 -> V_5 [ V_646 ] ,
V_604 ) ;
V_632 = true ;
}
if ( V_50 && ( * V_50 & V_648 ) &&
! ( V_7 -> V_18 . V_368 & V_649 ) )
return - V_557 ;
if ( V_632 )
V_35 = F_120 ( V_7 , V_556 , V_630 , V_50 , & V_139 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_139 . V_623 != - 1 )
V_556 -> V_28 -> V_623 = V_139 . V_623 ;
return V_35 ;
}
static int F_121 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_628 V_139 ;
struct V_1 * V_17 ;
struct V_31 * V_52 ;
int V_35 ;
enum V_275 type = V_151 ;
V_22 V_50 ;
F_122 ( V_7 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_30 -> V_5 [ V_601 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_511 ] ) {
type = F_4 ( V_30 -> V_5 [ V_511 ] ) ;
if ( type > V_633 )
return - V_16 ;
}
if ( ! V_7 -> V_328 -> V_283 ||
! ( V_7 -> V_18 . V_434 & ( 1 << type ) ) )
return - V_557 ;
if ( ( type == V_155 || type == V_154 ||
V_7 -> V_18 . V_368 & V_650 ) &&
V_30 -> V_5 [ V_564 ] ) {
F_119 ( V_139 . V_647 , V_30 -> V_5 [ V_564 ] ,
V_604 ) ;
if ( ! F_123 ( V_139 . V_647 ) )
return - V_651 ;
}
if ( V_30 -> V_5 [ V_638 ] ) {
V_139 . V_623 = ! ! F_35 ( V_30 -> V_5 [ V_638 ] ) ;
V_35 = F_112 ( V_7 , NULL , V_139 . V_623 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_111 ( type == V_153 ?
V_30 -> V_5 [ V_639 ] : NULL ,
& V_50 ) ;
if ( ! V_35 && ( V_50 & V_648 ) &&
! ( V_7 -> V_18 . V_368 & V_649 ) )
return - V_557 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_17 = F_124 ( V_7 ,
F_24 ( V_30 -> V_5 [ V_601 ] ) ,
V_652 , type , V_35 ? NULL : & V_50 ,
& V_139 ) ;
if ( F_63 ( ! V_17 ) ) {
F_77 ( V_52 ) ;
return - V_653 ;
} else if ( F_18 ( V_17 ) ) {
F_77 ( V_52 ) ;
return F_19 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_654 ] )
V_17 -> V_655 = V_30 -> V_521 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_634 ] )
break;
F_114 ( V_17 ) ;
F_115 ( V_635 !=
V_636 ) ;
V_17 -> V_637 =
F_25 ( V_30 -> V_5 [ V_634 ] ) ;
memcpy ( V_17 -> V_611 , F_24 ( V_30 -> V_5 [ V_634 ] ) ,
V_17 -> V_637 ) ;
F_116 ( V_17 ) ;
break;
case V_154 :
case V_155 :
F_125 ( & V_17 -> V_656 ) ;
F_126 ( & V_17 -> V_657 ) ;
F_127 ( & V_17 -> V_658 ) ;
F_126 ( & V_17 -> V_659 ) ;
F_127 ( & V_17 -> V_660 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_128 ( & V_17 -> V_661 , & V_7 -> V_18 . V_662 ) ;
V_7 -> V_605 ++ ;
break;
default:
break;
}
if ( F_104 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_77 ( V_52 ) ;
return - V_90 ;
}
if ( ! V_17 -> V_19 )
F_129 ( V_7 , V_17 , V_599 ) ;
return F_78 ( V_52 , V_30 ) ;
}
static int F_130 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_663 )
return - V_557 ;
if ( ! V_17 -> V_19 )
V_30 -> V_520 [ 1 ] = NULL ;
return F_131 ( V_7 , V_17 ) ;
}
static int F_132 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_3 V_664 ;
if ( ! V_30 -> V_5 [ V_665 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_343 )
return - V_557 ;
V_664 = F_80 ( V_30 -> V_5 [ V_665 ] ) ;
return F_133 ( V_7 , V_556 , V_664 ) ;
}
static void F_134 ( void * V_166 , struct V_666 * V_139 )
{
struct V_4 * V_91 ;
struct V_667 * V_668 = V_166 ;
if ( ( V_139 -> V_91 &&
F_52 ( V_668 -> V_52 , V_120 ,
V_139 -> V_107 , V_139 -> V_91 ) ) ||
( V_139 -> V_49 &&
F_52 ( V_668 -> V_52 , V_121 ,
V_139 -> V_109 , V_139 -> V_49 ) ) ||
( V_139 -> V_111 &&
F_29 ( V_668 -> V_52 , V_123 ,
V_139 -> V_111 ) ) )
goto V_60;
V_91 = F_48 ( V_668 -> V_52 , V_128 ) ;
if ( ! V_91 )
goto V_60;
if ( ( V_139 -> V_91 &&
F_52 ( V_668 -> V_52 , V_105 ,
V_139 -> V_107 , V_139 -> V_91 ) ) ||
( V_139 -> V_49 &&
F_52 ( V_668 -> V_52 , V_108 ,
V_139 -> V_109 , V_139 -> V_49 ) ) ||
( V_139 -> V_111 &&
F_29 ( V_668 -> V_52 , V_110 ,
V_139 -> V_111 ) ) )
goto V_60;
if ( F_57 ( V_668 -> V_52 , V_122 , V_668 -> V_104 ) )
goto V_60;
F_49 ( V_668 -> V_52 , V_91 ) ;
return;
V_60:
V_668 -> error = 1 ;
}
static int F_135 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int V_35 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 V_669 = 0 ;
const T_2 * V_670 = NULL ;
bool V_671 ;
struct V_667 V_668 = {
. error = 0 ,
} ;
void * V_360 ;
struct V_31 * V_52 ;
if ( V_30 -> V_5 [ V_122 ] )
V_669 = F_35 ( V_30 -> V_5 [ V_122 ] ) ;
if ( V_669 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_564 ] )
V_670 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_671 = ! ! V_670 ;
if ( V_30 -> V_5 [ V_126 ] ) {
V_22 V_672 = F_4 ( V_30 -> V_5 [ V_126 ] ) ;
if ( V_672 >= V_113 )
return - V_16 ;
if ( V_672 != V_673 &&
V_672 != V_674 )
return - V_16 ;
V_671 = V_672 == V_674 ;
}
if ( ! V_7 -> V_328 -> V_675 )
return - V_557 ;
if ( ! V_671 && V_670 && ! ( V_7 -> V_18 . V_50 & V_401 ) )
return - V_676 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_677 ) ;
if ( ! V_360 )
goto V_60;
V_668 . V_52 = V_52 ;
V_668 . V_104 = V_669 ;
if ( F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_57 ( V_52 , V_122 , V_669 ) )
goto V_60;
if ( V_670 &&
F_52 ( V_52 , V_564 , V_604 , V_670 ) )
goto V_60;
V_35 = F_136 ( V_7 , V_556 , V_669 , V_671 , V_670 , & V_668 ,
F_134 ) ;
if ( V_35 )
goto V_678;
if ( V_668 . error )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
V_35 = - V_90 ;
V_678:
F_77 ( V_52 ) ;
return V_35 ;
}
static int F_137 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_92 V_91 ;
int V_35 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
V_35 = F_37 ( V_30 , & V_91 ) ;
if ( V_35 )
return V_35 ;
if ( V_91 . V_104 < 0 )
return - V_16 ;
if ( ! V_91 . V_97 && ! V_91 . V_99 )
return - V_16 ;
F_114 ( V_556 -> V_28 ) ;
if ( V_91 . V_97 ) {
if ( ! V_7 -> V_328 -> V_679 ) {
V_35 = - V_557 ;
goto V_616;
}
V_35 = F_43 ( V_556 -> V_28 ) ;
if ( V_35 )
goto V_616;
V_35 = F_138 ( V_7 , V_556 , V_91 . V_104 ,
V_91 . V_101 , V_91 . V_102 ) ;
if ( V_35 )
goto V_616;
#ifdef F_139
V_556 -> V_28 -> V_680 . V_681 = V_91 . V_104 ;
#endif
} else {
if ( V_91 . V_101 || ! V_91 . V_102 ) {
V_35 = - V_16 ;
goto V_616;
}
if ( ! V_7 -> V_328 -> V_682 ) {
V_35 = - V_557 ;
goto V_616;
}
V_35 = F_43 ( V_556 -> V_28 ) ;
if ( V_35 )
goto V_616;
V_35 = F_140 ( V_7 , V_556 , V_91 . V_104 ) ;
if ( V_35 )
goto V_616;
#ifdef F_139
V_556 -> V_28 -> V_680 . V_683 = V_91 . V_104 ;
#endif
}
V_616:
F_116 ( V_556 -> V_28 ) ;
return V_35 ;
}
static int F_141 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int V_35 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_92 V_91 ;
const T_2 * V_670 = NULL ;
V_35 = F_37 ( V_30 , & V_91 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_91 . V_106 . V_91 )
return - V_16 ;
if ( V_30 -> V_5 [ V_564 ] )
V_670 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( V_91 . type == - 1 ) {
if ( V_670 )
V_91 . type = V_674 ;
else
V_91 . type = V_673 ;
}
if ( V_91 . type != V_674 &&
V_91 . type != V_673 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_287 )
return - V_557 ;
if ( F_41 ( V_7 , & V_91 . V_106 , V_91 . V_104 ,
V_91 . type == V_674 ,
V_670 ) )
return - V_16 ;
F_114 ( V_556 -> V_28 ) ;
V_35 = F_43 ( V_556 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_142 ( V_7 , V_556 , V_91 . V_104 ,
V_91 . type == V_674 ,
V_670 , & V_91 . V_106 ) ;
F_116 ( V_556 -> V_28 ) ;
return V_35 ;
}
static int F_143 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int V_35 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 * V_670 = NULL ;
struct V_92 V_91 ;
V_35 = F_37 ( V_30 , & V_91 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_564 ] )
V_670 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( V_91 . type == - 1 ) {
if ( V_670 )
V_91 . type = V_674 ;
else
V_91 . type = V_673 ;
}
if ( V_91 . type != V_674 &&
V_91 . type != V_673 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_684 )
return - V_557 ;
F_114 ( V_556 -> V_28 ) ;
V_35 = F_43 ( V_556 -> V_28 ) ;
if ( V_91 . type == V_673 && V_670 &&
! ( V_7 -> V_18 . V_50 & V_401 ) )
V_35 = - V_676 ;
if ( ! V_35 )
V_35 = F_144 ( V_7 , V_556 , V_91 . V_104 ,
V_91 . type == V_674 ,
V_670 ) ;
#ifdef F_139
if ( ! V_35 ) {
if ( V_91 . V_104 == V_556 -> V_28 -> V_680 . V_681 )
V_556 -> V_28 -> V_680 . V_681 = - 1 ;
else if ( V_91 . V_104 == V_556 -> V_28 -> V_680 . V_683 )
V_556 -> V_28 -> V_680 . V_683 = - 1 ;
}
#endif
F_116 ( V_556 -> V_28 ) ;
return V_35 ;
}
static int F_145 ( struct V_4 * V_685 )
{
struct V_4 * V_44 ;
int V_686 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_25 ( V_44 ) != V_604 )
return - V_16 ;
V_686 ++ ;
}
return V_686 ;
}
static struct V_687 * F_146 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_688 V_689 ;
struct V_4 * V_44 ;
struct V_687 * V_690 ;
int V_160 = 0 , V_686 , V_24 ;
if ( ! V_18 -> V_473 )
return F_3 ( - V_557 ) ;
if ( ! V_30 -> V_5 [ V_691 ] )
return F_3 ( - V_16 ) ;
V_689 = F_4 ( V_30 -> V_5 [ V_691 ] ) ;
if ( V_689 != V_692 &&
V_689 != V_693 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_694 ] )
return F_3 ( - V_16 ) ;
V_686 = F_145 ( V_30 -> V_5 [ V_694 ] ) ;
if ( V_686 < 0 )
return F_3 ( V_686 ) ;
if ( V_686 > V_18 -> V_473 )
return F_3 ( - V_695 ) ;
V_690 = F_40 ( sizeof( * V_690 ) + ( sizeof( struct V_696 ) * V_686 ) ,
V_135 ) ;
if ( ! V_690 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_690 -> V_697 [ V_160 ] . V_698 , F_24 ( V_44 ) , V_604 ) ;
V_160 ++ ;
}
V_690 -> V_699 = V_686 ;
V_690 -> V_689 = V_689 ;
return V_690 ;
}
static int F_147 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_687 * V_690 ;
int V_35 ;
if ( V_556 -> V_28 -> V_141 != V_142 &&
V_556 -> V_28 -> V_141 != V_144 )
return - V_557 ;
if ( ! V_556 -> V_28 -> V_558 )
return - V_16 ;
V_690 = F_146 ( & V_7 -> V_18 , V_30 ) ;
if ( F_18 ( V_690 ) )
return F_19 ( V_690 ) ;
V_35 = F_148 ( V_7 , V_556 , V_690 ) ;
F_42 ( V_690 ) ;
return V_35 ;
}
static V_22 F_149 ( struct V_242 * V_243 ,
T_2 * V_700 , T_2 V_701 )
{
T_2 V_160 ;
V_22 V_702 = 0 ;
for ( V_160 = 0 ; V_160 < V_701 ; V_160 ++ ) {
int V_247 = ( V_700 [ V_160 ] & 0x7f ) * 5 ;
int V_703 ;
for ( V_703 = 0 ; V_703 < V_243 -> V_264 ; V_703 ++ ) {
struct V_246 * V_704 =
& V_243 -> V_265 [ V_703 ] ;
if ( V_247 == V_704 -> V_267 ) {
V_702 |= 1 << V_703 ;
break;
}
}
if ( V_703 == V_243 -> V_264 )
return 0 ;
}
return V_702 ;
}
static bool F_150 ( struct V_242 * V_243 ,
T_2 * V_700 , T_2 V_701 ,
T_2 V_251 [ V_705 ] )
{
T_2 V_160 ;
memset ( V_251 , 0 , V_705 ) ;
for ( V_160 = 0 ; V_160 < V_701 ; V_160 ++ ) {
int V_703 , V_706 ;
V_703 = V_700 [ V_160 ] / 8 ;
V_706 = F_118 ( V_700 [ V_160 ] % 8 ) ;
if ( ( V_703 < 0 ) || ( V_703 >= V_705 ) )
return false ;
if ( V_243 -> V_248 . V_251 . V_707 [ V_703 ] & V_706 )
V_251 [ V_703 ] |= V_706 ;
else
return false ;
}
return true ;
}
static T_3 F_151 ( T_2 V_708 )
{
T_3 V_709 = 0 ;
switch ( V_708 ) {
case V_710 :
break;
case V_711 :
V_709 = 0x00FF ;
break;
case V_712 :
V_709 = 0x01FF ;
break;
case V_713 :
V_709 = 0x03FF ;
break;
default:
break;
}
return V_709 ;
}
static void F_152 ( T_3 V_708 ,
T_3 V_714 [ V_715 ] )
{
T_2 V_716 ;
for ( V_716 = 0 ; V_716 < V_715 ; V_716 ++ ) {
V_714 [ V_716 ] = F_151 ( V_708 & 0x03 ) ;
V_708 >>= 2 ;
}
}
static bool F_153 ( struct V_242 * V_243 ,
struct V_717 * V_718 ,
T_3 V_251 [ V_715 ] )
{
T_3 V_719 = F_154 ( V_243 -> V_258 . V_261 . V_719 ) ;
T_3 V_720 [ V_715 ] = {} ;
T_2 V_160 ;
if ( ! V_243 -> V_258 . V_259 )
return false ;
memset ( V_251 , 0 , sizeof( T_3 ) * V_715 ) ;
F_152 ( V_719 , V_720 ) ;
for ( V_160 = 0 ; V_160 < V_715 ; V_160 ++ ) {
if ( ( V_720 [ V_160 ] & V_718 -> V_251 [ V_160 ] ) == V_718 -> V_251 [ V_160 ] )
V_251 [ V_160 ] = V_718 -> V_251 [ V_160 ] ;
else
return false ;
}
return true ;
}
static int F_155 ( struct V_29 * V_30 ,
struct V_721 * V_702 )
{
struct V_4 * V_94 [ V_722 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int V_133 , V_160 ;
struct V_4 * V_723 ;
struct V_242 * V_243 ;
T_3 V_724 ;
memset ( V_702 , 0 , sizeof( * V_702 ) ) ;
for ( V_160 = 0 ; V_160 < V_437 ; V_160 ++ ) {
V_243 = V_7 -> V_18 . V_438 [ V_160 ] ;
if ( ! V_243 )
continue;
V_702 -> V_725 [ V_160 ] . V_726 = ( 1 << V_243 -> V_264 ) - 1 ;
memcpy ( V_702 -> V_725 [ V_160 ] . V_727 ,
V_243 -> V_248 . V_251 . V_707 ,
sizeof( V_702 -> V_725 [ V_160 ] . V_727 ) ) ;
if ( ! V_243 -> V_258 . V_259 )
continue;
V_724 = F_154 ( V_243 -> V_258 . V_261 . V_719 ) ;
F_152 ( V_724 , V_702 -> V_725 [ V_160 ] . V_261 ) ;
}
if ( ! V_30 -> V_5 [ V_728 ] )
goto V_616;
F_115 ( V_729 > V_705 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_366 V_367 = F_156 ( V_723 ) ;
int V_35 ;
if ( V_367 < 0 || V_367 >= V_437 )
return - V_16 ;
V_243 = V_7 -> V_18 . V_438 [ V_367 ] ;
if ( V_243 == NULL )
return - V_16 ;
V_35 = F_34 ( V_94 , V_722 , V_723 ,
V_730 ) ;
if ( V_35 )
return V_35 ;
if ( V_94 [ V_731 ] ) {
V_702 -> V_725 [ V_367 ] . V_726 = F_149 (
V_243 ,
F_24 ( V_94 [ V_731 ] ) ,
F_25 ( V_94 [ V_731 ] ) ) ;
if ( ( V_702 -> V_725 [ V_367 ] . V_726 == 0 ) &&
F_25 ( V_94 [ V_731 ] ) )
return - V_16 ;
}
if ( V_94 [ V_732 ] ) {
if ( ! F_150 (
V_243 ,
F_24 ( V_94 [ V_732 ] ) ,
F_25 ( V_94 [ V_732 ] ) ,
V_702 -> V_725 [ V_367 ] . V_727 ) )
return - V_16 ;
}
if ( V_94 [ V_733 ] ) {
if ( ! F_153 (
V_243 ,
F_24 ( V_94 [ V_733 ] ) ,
V_702 -> V_725 [ V_367 ] . V_261 ) )
return - V_16 ;
}
if ( V_94 [ V_734 ] ) {
V_702 -> V_725 [ V_367 ] . V_735 =
F_35 ( V_94 [ V_734 ] ) ;
if ( V_702 -> V_725 [ V_367 ] . V_735 > V_736 )
return - V_16 ;
}
if ( V_702 -> V_725 [ V_367 ] . V_726 == 0 ) {
if ( ! ( V_7 -> V_18 . V_438 [ V_367 ] -> V_248 . V_249 ||
V_7 -> V_18 . V_438 [ V_367 ] -> V_258 . V_259 ) )
return - V_16 ;
for ( V_160 = 0 ; V_160 < V_705 ; V_160 ++ )
if ( V_702 -> V_725 [ V_367 ] . V_727 [ V_160 ] )
goto V_616;
for ( V_160 = 0 ; V_160 < V_715 ; V_160 ++ )
if ( V_702 -> V_725 [ V_367 ] . V_261 [ V_160 ] )
goto V_616;
return - V_16 ;
}
}
V_616:
return 0 ;
}
static int F_157 ( struct V_6 * V_7 ,
enum V_366 V_367 ,
struct V_721 * V_737 )
{
V_22 V_738 , V_739 , V_160 ;
V_22 V_247 = V_737 -> V_725 [ V_367 ] . V_726 ;
if ( F_158 ( V_247 ) > 1 )
return - V_16 ;
V_738 = 0 ;
for ( V_160 = 0 ; V_160 < V_705 ; V_160 ++ ) {
if ( F_159 ( V_737 -> V_725 [ V_367 ] . V_727 [ V_160 ] ) > 1 ) {
return - V_16 ;
} else if ( V_737 -> V_725 [ V_367 ] . V_727 [ V_160 ] ) {
V_738 ++ ;
if ( V_738 > 1 )
return - V_16 ;
}
if ( V_738 && V_247 )
return - V_16 ;
}
V_739 = 0 ;
for ( V_160 = 0 ; V_160 < V_715 ; V_160 ++ ) {
if ( F_160 ( V_737 -> V_725 [ V_367 ] . V_261 [ V_160 ] ) > 1 ) {
return - V_16 ;
} else if ( V_737 -> V_725 [ V_367 ] . V_261 [ V_160 ] ) {
V_739 ++ ;
if ( V_739 > 1 )
return - V_16 ;
}
if ( V_739 && V_247 )
return - V_16 ;
}
if ( ( V_738 && V_739 ) || ( ! V_247 && ! V_738 && ! V_739 ) )
return - V_16 ;
if ( V_247 &&
! F_117 ( & V_7 -> V_18 ,
V_740 ) )
return - V_16 ;
if ( V_738 &&
! F_117 ( & V_7 -> V_18 ,
V_741 ) )
return - V_16 ;
if ( V_739 &&
! F_117 ( & V_7 -> V_18 ,
V_742 ) )
return - V_16 ;
return 0 ;
}
static int F_161 ( struct V_4 * V_5 [] ,
struct V_743 * V_744 )
{
bool V_745 = false ;
if ( ! F_23 ( V_5 [ V_746 ] ) ||
! F_23 ( V_5 [ V_747 ] ) ||
! F_23 ( V_5 [ V_748 ] ) ||
! F_23 ( V_5 [ V_749 ] ) )
return - V_16 ;
memset ( V_744 , 0 , sizeof( * V_744 ) ) ;
if ( V_5 [ V_750 ] ) {
V_744 -> V_751 = F_24 ( V_5 [ V_750 ] ) ;
V_744 -> V_752 = F_25 ( V_5 [ V_750 ] ) ;
if ( ! V_744 -> V_752 )
return - V_16 ;
V_745 = true ;
}
if ( V_5 [ V_746 ] ) {
V_744 -> V_753 = F_24 ( V_5 [ V_746 ] ) ;
V_744 -> V_754 = F_25 ( V_5 [ V_746 ] ) ;
V_745 = true ;
}
if ( ! V_745 )
return - V_16 ;
if ( V_5 [ V_747 ] ) {
V_744 -> V_755 = F_24 ( V_5 [ V_747 ] ) ;
V_744 -> V_756 = F_25 ( V_5 [ V_747 ] ) ;
}
if ( V_5 [ V_748 ] ) {
V_744 -> V_757 =
F_24 ( V_5 [ V_748 ] ) ;
V_744 -> V_758 =
F_25 ( V_5 [ V_748 ] ) ;
}
if ( V_5 [ V_749 ] ) {
V_744 -> V_759 =
F_24 ( V_5 [ V_749 ] ) ;
V_744 -> V_760 =
F_25 ( V_5 [ V_749 ] ) ;
}
if ( V_5 [ V_761 ] ) {
V_744 -> V_762 = F_24 ( V_5 [ V_761 ] ) ;
V_744 -> V_763 = F_25 ( V_5 [ V_761 ] ) ;
}
return 0 ;
}
static bool F_162 ( struct V_6 * V_7 ,
struct V_764 * V_139 )
{
struct V_1 * V_17 ;
bool V_513 = false ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_562 . V_54 )
continue;
V_139 -> V_537 = V_17 -> V_562 ;
V_513 = true ;
break;
}
return V_513 ;
}
static bool F_163 ( struct V_6 * V_7 ,
enum V_765 V_766 ,
enum V_357 V_51 )
{
if ( V_766 > V_767 )
return false ;
switch ( V_51 ) {
case V_768 :
if ( ! ( V_7 -> V_18 . V_368 & V_769 ) &&
V_766 == V_770 )
return false ;
if ( ! F_117 ( & V_7 -> V_18 ,
V_771 ) &&
( V_766 == V_772 ||
V_766 == V_773 ||
V_766 == V_774 ) )
return false ;
return true ;
case V_354 :
case V_775 :
if ( V_766 == V_770 )
return false ;
if ( V_766 == V_772 ||
V_766 == V_773 ||
V_766 == V_774 )
return false ;
return true ;
default:
return false ;
}
}
static int F_164 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_764 V_139 ;
int V_35 ;
if ( V_556 -> V_28 -> V_141 != V_142 &&
V_556 -> V_28 -> V_141 != V_144 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_289 )
return - V_557 ;
if ( V_17 -> V_558 )
return - V_776 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_30 -> V_5 [ V_777 ] ||
! V_30 -> V_5 [ V_778 ] ||
! V_30 -> V_5 [ V_750 ] )
return - V_16 ;
V_35 = F_161 ( V_30 -> V_5 , & V_139 . V_779 ) ;
if ( V_35 )
return V_35 ;
V_139 . V_558 =
F_4 ( V_30 -> V_5 [ V_777 ] ) ;
V_139 . V_780 =
F_4 ( V_30 -> V_5 [ V_778 ] ) ;
V_35 = F_165 ( V_7 , V_556 -> V_28 -> V_141 ,
V_139 . V_558 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_610 ] ) {
V_139 . V_611 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_139 . V_609 =
F_25 ( V_30 -> V_5 [ V_610 ] ) ;
if ( V_139 . V_609 == 0 ||
V_139 . V_609 > V_635 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_781 ] ) {
V_139 . V_782 = F_4 (
V_30 -> V_5 [ V_781 ] ) ;
if ( V_139 . V_782 != V_783 &&
V_139 . V_782 != V_784 &&
V_139 . V_782 != V_785 )
return - V_16 ;
}
V_139 . V_786 = ! ! V_30 -> V_5 [ V_787 ] ;
if ( V_30 -> V_5 [ V_788 ] ) {
V_139 . V_766 = F_4 (
V_30 -> V_5 [ V_788 ] ) ;
if ( ! F_163 ( V_7 , V_139 . V_766 ,
V_775 ) )
return - V_16 ;
} else
V_139 . V_766 = V_789 ;
V_35 = F_166 ( V_7 , V_30 , & V_139 . V_790 ,
V_791 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_792 ] ) {
if ( ! ( V_7 -> V_18 . V_368 & V_793 ) )
return - V_557 ;
V_139 . V_794 = F_80 (
V_30 -> V_5 [ V_792 ] ) ;
}
if ( V_30 -> V_5 [ V_795 ] ) {
if ( V_556 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_139 . V_796 =
F_35 ( V_30 -> V_5 [ V_795 ] ) ;
if ( V_139 . V_796 > 127 )
return - V_16 ;
if ( V_139 . V_796 != 0 &&
! ( V_7 -> V_18 . V_368 & V_797 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_798 ] ) {
T_2 V_24 ;
if ( V_556 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_35 ( V_30 -> V_5 [ V_798 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_139 . V_799 = V_24 ;
if ( V_139 . V_799 != 0 &&
! ( V_7 -> V_18 . V_368 & V_800 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_539 ] ) {
V_35 = F_82 ( V_7 , V_30 , & V_139 . V_537 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_562 . V_54 ) {
V_139 . V_537 = V_17 -> V_562 ;
} else if ( ! F_162 ( V_7 , & V_139 ) )
return - V_16 ;
if ( ! F_87 ( & V_7 -> V_18 , & V_139 . V_537 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_728 ] ) {
V_35 = F_155 ( V_30 , & V_139 . V_737 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_157 ( V_7 , V_139 . V_537 . V_54 -> V_367 ,
& V_139 . V_737 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_801 ] ) {
V_139 . V_802 =
F_35 ( V_30 -> V_5 [ V_801 ] ) ;
switch ( V_139 . V_802 ) {
case V_803 :
break;
case V_804 :
if ( ! ( V_7 -> V_18 . V_368 &
V_805 ) )
return - V_16 ;
break;
case V_806 :
if ( ! ( V_7 -> V_18 . V_368 &
V_807 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_139 . V_802 = V_803 ;
}
V_139 . V_808 = F_167 ( V_30 -> V_5 [ V_809 ] ) ;
if ( V_139 . V_808 && ! V_7 -> V_18 . V_438 [ V_810 ] )
return - V_557 ;
if ( V_30 -> V_5 [ V_691 ] ) {
V_139 . V_690 = F_146 ( & V_7 -> V_18 , V_30 ) ;
if ( F_18 ( V_139 . V_690 ) )
return F_19 ( V_139 . V_690 ) ;
}
F_114 ( V_17 ) ;
V_35 = F_168 ( V_7 , V_556 , & V_139 ) ;
if ( ! V_35 ) {
V_17 -> V_562 = V_139 . V_537 ;
V_17 -> V_558 = V_139 . V_558 ;
V_17 -> V_537 = V_139 . V_537 ;
V_17 -> V_609 = V_139 . V_609 ;
memcpy ( V_17 -> V_611 , V_139 . V_611 , V_17 -> V_609 ) ;
}
F_116 ( V_17 ) ;
F_42 ( V_139 . V_690 ) ;
return V_35 ;
}
static int F_169 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_743 V_139 ;
int V_35 ;
if ( V_556 -> V_28 -> V_141 != V_142 &&
V_556 -> V_28 -> V_141 != V_144 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_811 )
return - V_557 ;
if ( ! V_17 -> V_558 )
return - V_16 ;
V_35 = F_161 ( V_30 -> V_5 , & V_139 ) ;
if ( V_35 )
return V_35 ;
F_114 ( V_17 ) ;
V_35 = F_170 ( V_7 , V_556 , & V_139 ) ;
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_171 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
return F_172 ( V_7 , V_556 , false ) ;
}
static int F_173 ( struct V_29 * V_30 ,
enum V_275 V_141 ,
struct V_812 * V_139 )
{
struct V_4 * V_50 [ V_813 + 1 ] ;
struct V_4 * V_618 ;
int V_621 ;
V_618 = V_30 -> V_5 [ V_814 ] ;
if ( V_618 ) {
struct V_815 * V_816 ;
V_816 = F_24 ( V_618 ) ;
V_139 -> V_817 = V_816 -> V_702 ;
V_139 -> V_818 = V_816 -> V_819 ;
V_139 -> V_818 &= V_139 -> V_817 ;
if ( ( V_139 -> V_817 |
V_139 -> V_818 ) & F_118 ( V_820 ) )
return - V_16 ;
return 0 ;
}
V_618 = V_30 -> V_5 [ V_821 ] ;
if ( ! V_618 )
return 0 ;
if ( F_34 ( V_50 , V_813 ,
V_618 , V_822 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_139 -> V_817 = F_118 ( V_823 ) |
F_118 ( V_824 ) |
F_118 ( V_825 ) |
F_118 ( V_826 ) ;
break;
case V_148 :
case V_147 :
V_139 -> V_817 = F_118 ( V_823 ) |
F_118 ( V_827 ) ;
break;
case V_145 :
V_139 -> V_817 = F_118 ( V_828 ) |
F_118 ( V_826 ) |
F_118 ( V_823 ) ;
default:
return - V_16 ;
}
for ( V_621 = 1 ; V_621 <= V_813 ; V_621 ++ ) {
if ( V_50 [ V_621 ] ) {
V_139 -> V_818 |= ( 1 << V_621 ) ;
if ( V_621 > V_829 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_174 ( struct V_31 * V_52 , struct V_830 * V_30 ,
int V_44 )
{
struct V_4 * V_247 ;
V_22 V_267 ;
T_3 V_831 ;
enum V_832 V_833 ;
V_247 = F_48 ( V_52 , V_44 ) ;
if ( ! V_247 )
return false ;
V_267 = F_175 ( V_30 ) ;
V_831 = V_267 < ( 1UL << 16 ) ? V_267 : 0 ;
if ( V_267 > 0 &&
F_29 ( V_52 , V_834 , V_267 ) )
return false ;
if ( V_831 > 0 &&
F_56 ( V_52 , V_835 , V_831 ) )
return false ;
switch ( V_30 -> V_836 ) {
case V_837 :
V_833 = V_838 ;
break;
case V_839 :
V_833 = V_840 ;
break;
default:
F_63 ( 1 ) ;
case V_841 :
V_833 = 0 ;
break;
case V_842 :
V_833 = V_843 ;
break;
case V_844 :
V_833 = V_845 ;
break;
case V_846 :
V_833 = V_847 ;
break;
}
if ( V_833 && F_30 ( V_52 , V_833 ) )
return false ;
if ( V_30 -> V_50 & V_848 ) {
if ( F_57 ( V_52 , V_849 , V_30 -> V_251 ) )
return false ;
if ( V_30 -> V_50 & V_850 &&
F_30 ( V_52 , V_851 ) )
return false ;
} else if ( V_30 -> V_50 & V_852 ) {
if ( F_57 ( V_52 , V_853 , V_30 -> V_251 ) )
return false ;
if ( F_57 ( V_52 , V_854 , V_30 -> V_716 ) )
return false ;
if ( V_30 -> V_50 & V_850 &&
F_30 ( V_52 , V_851 ) )
return false ;
}
F_49 ( V_52 , V_247 ) ;
return true ;
}
static bool F_176 ( struct V_31 * V_52 , T_2 V_702 , T_4 * signal ,
int V_855 )
{
void * V_44 ;
int V_160 = 0 ;
if ( ! V_702 )
return true ;
V_44 = F_48 ( V_52 , V_855 ) ;
if ( ! V_44 )
return false ;
for ( V_160 = 0 ; V_160 < V_856 ; V_160 ++ ) {
if ( ! ( V_702 & F_118 ( V_160 ) ) )
continue;
if ( F_57 ( V_52 , V_160 , signal [ V_160 ] ) )
return false ;
}
F_49 ( V_52 , V_44 ) ;
return true ;
}
static int F_177 ( struct V_31 * V_52 , V_22 V_51 , V_22 V_48 ,
V_22 V_49 , int V_50 ,
struct V_6 * V_7 ,
struct V_25 * V_556 ,
const T_2 * V_670 , struct V_857 * V_858 )
{
void * V_360 ;
struct V_4 * V_859 , * V_860 ;
V_360 = F_26 ( V_52 , V_48 , V_49 , V_50 , V_51 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_670 ) ||
F_29 ( V_52 , V_370 , V_858 -> V_861 ) )
goto V_60;
V_859 = F_48 ( V_52 , V_862 ) ;
if ( ! V_859 )
goto V_60;
#define F_178 ( V_44 , T_5 , type ) do { \
BUILD_BUG_ON(sizeof(type) == sizeof(u64)); \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
#define F_179 ( V_44 , T_5 ) do { \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb, NL80211_STA_INFO_PAD)) \
goto nla_put_failure; \
} while (0)
F_178 ( V_863 , V_864 , V_22 ) ;
F_178 ( V_865 , V_866 , V_22 ) ;
if ( V_858 -> V_867 & ( F_118 ( V_868 ) |
F_118 ( V_869 ) ) &&
F_29 ( V_52 , V_868 ,
( V_22 ) V_858 -> V_870 ) )
goto V_60;
if ( V_858 -> V_867 & ( F_118 ( V_871 ) |
F_118 ( V_872 ) ) &&
F_29 ( V_52 , V_871 ,
( V_22 ) V_858 -> V_873 ) )
goto V_60;
F_179 ( V_874 , V_870 ) ;
F_179 ( V_875 , V_873 ) ;
F_178 ( V_876 , V_877 , T_3 ) ;
F_178 ( V_878 , V_879 , T_3 ) ;
F_178 ( V_880 , V_881 , T_2 ) ;
F_179 ( V_882 , V_883 ) ;
switch ( V_7 -> V_18 . V_884 ) {
case V_885 :
F_178 ( SIGNAL , signal , T_2 ) ;
F_178 ( V_886 , V_887 , T_2 ) ;
break;
default:
break;
}
if ( V_858 -> V_867 & F_118 ( V_888 ) ) {
if ( ! F_176 ( V_52 , V_858 -> V_889 ,
V_858 -> V_890 ,
V_888 ) )
goto V_60;
}
if ( V_858 -> V_867 & F_118 ( V_891 ) ) {
if ( ! F_176 ( V_52 , V_858 -> V_889 ,
V_858 -> V_892 ,
V_891 ) )
goto V_60;
}
if ( V_858 -> V_867 & F_118 ( V_893 ) ) {
if ( ! F_174 ( V_52 , & V_858 -> V_718 ,
V_893 ) )
goto V_60;
}
if ( V_858 -> V_867 & F_118 ( V_894 ) ) {
if ( ! F_174 ( V_52 , & V_858 -> V_895 ,
V_894 ) )
goto V_60;
}
F_178 ( V_896 , V_897 , V_22 ) ;
F_178 ( V_898 , V_899 , V_22 ) ;
F_178 ( V_900 , V_901 , V_22 ) ;
F_178 ( V_902 , V_903 , V_22 ) ;
F_178 ( V_904 , V_905 , V_22 ) ;
F_178 ( V_906 , V_907 , V_22 ) ;
F_178 ( V_908 , V_909 , V_22 ) ;
F_178 ( V_910 , V_911 , V_22 ) ;
F_178 ( V_912 , V_913 , V_22 ) ;
if ( V_858 -> V_867 & F_118 ( V_914 ) ) {
V_860 = F_48 ( V_52 , V_914 ) ;
if ( ! V_860 )
goto V_60;
if ( ( ( V_858 -> V_860 . V_50 & V_915 ) &&
F_30 ( V_52 , V_916 ) ) ||
( ( V_858 -> V_860 . V_50 & V_917 ) &&
F_30 ( V_52 , V_918 ) ) ||
( ( V_858 -> V_860 . V_50 & V_919 ) &&
F_30 ( V_52 , V_920 ) ) ||
F_57 ( V_52 , V_921 ,
V_858 -> V_860 . V_780 ) ||
F_56 ( V_52 , V_922 ,
V_858 -> V_860 . V_558 ) )
goto V_60;
F_49 ( V_52 , V_860 ) ;
}
if ( ( V_858 -> V_867 & F_118 ( V_923 ) ) &&
F_52 ( V_52 , V_923 ,
sizeof( struct V_815 ) ,
& V_858 -> V_816 ) )
goto V_60;
F_179 ( V_924 , V_925 ) ;
F_179 ( V_926 , V_927 ) ;
F_179 ( V_928 , V_929 ) ;
F_178 ( V_930 , V_931 , T_2 ) ;
#undef F_178
#undef F_179
if ( V_858 -> V_867 & F_118 ( V_932 ) ) {
struct V_4 * V_933 ;
int V_934 ;
V_933 = F_48 ( V_52 , V_932 ) ;
if ( ! V_933 )
goto V_60;
for ( V_934 = 0 ; V_934 < V_935 + 1 ; V_934 ++ ) {
struct V_936 * V_937 ;
struct V_4 * V_938 ;
V_937 = & V_858 -> V_939 [ V_934 ] ;
if ( ! V_937 -> V_867 )
continue;
V_938 = F_48 ( V_52 , V_934 + 1 ) ;
if ( ! V_938 )
goto V_60;
#define F_180 ( V_44 , T_5 ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb, NL80211_TID_STATS_PAD)) \
goto nla_put_failure; \
} while (0)
F_180 ( V_940 , V_941 ) ;
F_180 ( V_942 , V_943 ) ;
F_180 ( V_944 , V_945 ) ;
F_180 ( V_946 , V_947 ) ;
#undef F_180
F_49 ( V_52 , V_938 ) ;
}
F_49 ( V_52 , V_933 ) ;
}
F_49 ( V_52 , V_859 ) ;
if ( V_858 -> V_948 &&
F_52 ( V_52 , V_747 , V_858 -> V_948 ,
V_858 -> V_949 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int F_181 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_857 V_858 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_670 [ V_604 ] ;
int V_950 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_951;
}
if ( ! V_7 -> V_328 -> V_952 ) {
V_35 = - V_557 ;
goto V_951;
}
while ( 1 ) {
memset ( & V_858 , 0 , sizeof( V_858 ) ) ;
V_35 = F_182 ( V_7 , V_17 -> V_19 , V_950 ,
V_670 , & V_858 ) ;
if ( V_35 == - V_676 )
break;
if ( V_35 )
goto V_951;
if ( F_177 ( V_32 , V_953 ,
F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_7 , V_17 -> V_19 , V_670 ,
& V_858 ) < 0 )
goto V_616;
V_950 ++ ;
}
V_616:
V_34 -> args [ 2 ] = V_950 ;
V_35 = V_32 -> V_46 ;
V_951:
F_22 ( V_7 ) ;
return V_35 ;
}
static int F_183 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_857 V_858 ;
struct V_31 * V_52 ;
T_2 * V_670 = NULL ;
int V_35 ;
memset ( & V_858 , 0 , sizeof( V_858 ) ) ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_670 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( ! V_7 -> V_328 -> V_954 )
return - V_557 ;
V_35 = F_184 ( V_7 , V_556 , V_670 , & V_858 ) ;
if ( V_35 )
return V_35 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
if ( F_177 ( V_52 , V_953 ,
V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_7 , V_556 , V_670 , & V_858 ) < 0 ) {
F_77 ( V_52 ) ;
return - V_90 ;
}
return F_78 ( V_52 , V_30 ) ;
}
int F_185 ( struct V_18 * V_18 ,
struct V_812 * V_139 ,
enum V_955 V_956 )
{
if ( V_139 -> V_957 != - 1 &&
V_956 != V_958 )
return - V_16 ;
if ( V_139 -> V_959 != - 1 &&
V_956 != V_958 )
return - V_16 ;
if ( V_139 -> V_960 &&
! ( V_139 -> V_818 & F_118 ( V_827 ) ) &&
V_956 != V_958 )
return - V_16 ;
F_115 ( V_813 != 7 ) ;
switch ( V_956 ) {
case V_961 :
case V_962 :
if ( V_139 -> V_817 &
~ ( F_118 ( V_828 ) |
F_118 ( V_826 ) |
F_118 ( V_823 ) ) )
return - V_16 ;
break;
case V_963 :
case V_964 :
if ( ! ( V_139 -> V_818 & F_118 ( V_827 ) ) )
return - V_16 ;
V_139 -> V_817 &= ~ F_118 ( V_827 ) ;
break;
default:
if ( V_139 -> V_965 != V_966 )
return - V_16 ;
if ( V_139 -> V_909 )
return - V_16 ;
if ( V_139 -> V_967 & V_968 )
return - V_16 ;
}
if ( V_956 != V_963 &&
V_956 != V_964 ) {
if ( V_139 -> V_818 & F_118 ( V_827 ) )
return - V_16 ;
V_139 -> V_817 &= ~ F_118 ( V_827 ) ;
}
if ( V_956 != V_963 &&
V_956 != V_958 ) {
if ( V_139 -> V_967 & V_969 )
return - V_16 ;
if ( V_139 -> V_967 & V_970 )
return - V_16 ;
if ( V_139 -> V_971 )
return - V_16 ;
if ( V_139 -> V_972 || V_139 -> V_973 || V_139 -> V_974 )
return - V_16 ;
}
if ( V_956 != V_975 &&
V_956 != V_958 ) {
if ( V_139 -> V_976 )
return - V_16 ;
}
switch ( V_956 ) {
case V_977 :
if ( ! ( V_139 -> V_817 & F_118 ( V_823 ) ) )
return - V_557 ;
break;
case V_975 :
case V_958 :
if ( V_139 -> V_817 &
~ ( F_118 ( V_823 ) |
F_118 ( V_828 ) |
F_118 ( V_978 ) |
F_118 ( V_824 ) |
F_118 ( V_825 ) |
F_118 ( V_826 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_368 & V_979 ) &&
V_139 -> V_817 &
( F_118 ( V_828 ) |
F_118 ( V_978 ) ) )
return - V_16 ;
break;
case V_980 :
case V_981 :
if ( V_139 -> V_817 & ~ F_118 ( V_823 ) )
return - V_16 ;
break;
case V_963 :
if ( V_139 -> V_817 & ~ ( F_118 ( V_823 ) |
F_118 ( V_825 ) ) )
return - V_16 ;
if ( V_139 -> V_818 & F_118 ( V_823 ) &&
! V_139 -> V_971 )
return - V_16 ;
break;
case V_964 :
return - V_16 ;
case V_961 :
if ( V_139 -> V_967 & V_968 )
return - V_16 ;
break;
case V_962 :
if ( V_139 -> V_965 != V_966 &&
V_139 -> V_965 != V_982 )
return - V_16 ;
break;
}
if ( V_956 != V_958 &&
V_956 != V_963 )
V_139 -> V_983 = false ;
return 0 ;
}
static struct V_25 * F_186 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_984 = V_30 -> V_5 [ V_985 ] ;
struct V_25 * V_986 ;
int V_513 ;
if ( ! V_984 )
return NULL ;
V_986 = F_187 ( F_96 ( V_30 ) , F_4 ( V_984 ) ) ;
if ( ! V_986 )
return F_3 ( - V_23 ) ;
if ( ! V_986 -> V_28 || V_986 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_513 = - V_16 ;
goto error;
}
if ( V_986 -> V_28 -> V_141 != V_143 &&
V_986 -> V_28 -> V_141 != V_142 &&
V_986 -> V_28 -> V_141 != V_144 ) {
V_513 = - V_16 ;
goto error;
}
if ( ! F_93 ( V_986 ) ) {
V_513 = - V_571 ;
goto error;
}
return V_986 ;
error:
F_188 ( V_986 ) ;
return F_3 ( V_513 ) ;
}
static int F_189 ( struct V_29 * V_30 ,
struct V_812 * V_139 )
{
struct V_4 * V_94 [ V_987 + 1 ] ;
struct V_4 * V_618 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_988 ] )
return 0 ;
V_618 = V_30 -> V_5 [ V_988 ] ;
V_35 = F_34 ( V_94 , V_987 , V_618 ,
V_989 ) ;
if ( V_35 )
return V_35 ;
if ( V_94 [ V_990 ] )
V_139 -> V_991 = F_35 (
V_94 [ V_990 ] ) ;
if ( V_139 -> V_991 & ~ V_992 )
return - V_16 ;
if ( V_94 [ V_993 ] )
V_139 -> V_994 = F_35 ( V_94 [ V_993 ] ) ;
if ( V_139 -> V_994 & ~ V_995 )
return - V_16 ;
V_139 -> V_967 |= V_969 ;
return 0 ;
}
static int F_190 ( struct V_29 * V_30 ,
struct V_812 * V_139 )
{
if ( V_30 -> V_5 [ V_996 ] ) {
V_139 -> V_997 =
F_24 ( V_30 -> V_5 [ V_996 ] ) ;
V_139 -> V_998 =
F_25 ( V_30 -> V_5 [ V_996 ] ) ;
if ( V_139 -> V_998 < 2 )
return - V_16 ;
if ( V_139 -> V_998 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_999 ] ) {
V_139 -> V_1000 =
F_24 ( V_30 -> V_5 [ V_999 ] ) ;
V_139 -> V_1001 =
F_25 ( V_30 -> V_5 [ V_999 ] ) ;
if ( V_139 -> V_1001 < 2 ||
V_139 -> V_1001 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_191 ( struct V_29 * V_30 ,
struct V_812 * V_139 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_1002 ] )
V_139 -> V_960 = F_80 ( V_30 -> V_5 [ V_1002 ] ) ;
if ( V_30 -> V_5 [ V_1003 ] )
V_139 -> V_973 =
F_24 ( V_30 -> V_5 [ V_1003 ] ) ;
if ( V_30 -> V_5 [ V_1004 ] )
V_139 -> V_974 =
F_24 ( V_30 -> V_5 [ V_1004 ] ) ;
V_35 = F_190 ( V_30 , V_139 ) ;
if ( V_35 )
return V_35 ;
return F_189 ( V_30 , V_139 ) ;
}
static int F_192 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_812 V_139 ;
T_2 * V_670 ;
int V_35 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_7 -> V_328 -> V_1005 )
return - V_557 ;
if ( V_30 -> V_5 [ V_1006 ] )
V_139 . V_960 = F_80 ( V_30 -> V_5 [ V_1006 ] ) ;
if ( V_30 -> V_5 [ V_1007 ] )
V_139 . V_957 =
F_80 ( V_30 -> V_5 [ V_1007 ] ) ;
else
V_139 . V_957 = - 1 ;
if ( V_30 -> V_5 [ V_1008 ] ) {
T_2 V_24 ;
V_24 = F_35 ( V_30 -> V_5 [ V_1008 ] ) ;
if ( V_24 >= V_1009 )
return - V_16 ;
V_139 . V_959 = V_24 ;
} else {
V_139 . V_959 = - 1 ;
}
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_670 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( V_30 -> V_5 [ V_1010 ] ) {
V_139 . V_971 =
F_24 ( V_30 -> V_5 [ V_1010 ] ) ;
V_139 . V_1011 =
F_25 ( V_30 -> V_5 [ V_1010 ] ) ;
}
if ( V_30 -> V_5 [ V_1012 ] ) {
V_139 . V_1013 =
F_80 ( V_30 -> V_5 [ V_1012 ] ) ;
V_139 . V_967 |= V_970 ;
}
if ( V_30 -> V_5 [ V_1014 ] ) {
V_139 . V_972 =
F_24 ( V_30 -> V_5 [ V_1014 ] ) ;
V_139 . V_1015 =
F_25 ( V_30 -> V_5 [ V_1014 ] ) ;
}
if ( F_173 ( V_30 , V_556 -> V_28 -> V_141 , & V_139 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_1016 ] ) {
V_139 . V_965 =
F_35 ( V_30 -> V_5 [ V_1016 ] ) ;
if ( V_139 . V_965 >= V_1017 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1018 ] ) {
V_139 . V_881 =
F_35 ( V_30 -> V_5 [ V_1018 ] ) ;
if ( V_139 . V_881 >= V_1019 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1020 ] ) {
V_139 . V_1021 = F_80 (
V_30 -> V_5 [ V_1020 ] ) ;
if ( V_139 . V_1021 > V_1022 )
return - V_16 ;
}
V_139 . V_967 |= V_968 ;
}
if ( V_30 -> V_5 [ V_1023 ] ) {
enum V_1024 V_1025 = F_4 (
V_30 -> V_5 [ V_1023 ] ) ;
if ( V_1025 <= V_1026 ||
V_1025 > V_1027 )
return - V_16 ;
V_139 . V_909 = V_1025 ;
}
if ( V_30 -> V_5 [ V_1028 ] ) {
V_139 . V_983 = true ;
V_139 . V_1029 =
F_35 ( V_30 -> V_5 [ V_1028 ] ) ;
}
V_35 = F_191 ( V_30 , & V_139 ) ;
if ( V_35 )
return V_35 ;
V_139 . V_976 = F_186 ( V_30 , V_7 ) ;
if ( F_18 ( V_139 . V_976 ) )
return F_19 ( V_139 . V_976 ) ;
switch ( V_556 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_557 ;
goto V_1030;
}
V_35 = F_193 ( V_7 , V_556 , V_670 , & V_139 ) ;
V_1030:
if ( V_139 . V_976 )
F_188 ( V_139 . V_976 ) ;
return V_35 ;
}
static int F_194 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int V_35 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_812 V_139 ;
T_2 * V_670 = NULL ;
V_22 V_1031 = F_118 ( V_828 ) |
F_118 ( V_978 ) ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_7 -> V_328 -> V_291 )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1007 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1010 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1006 ] &&
! V_30 -> V_5 [ V_1002 ] )
return - V_16 ;
V_670 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_139 . V_971 =
F_24 ( V_30 -> V_5 [ V_1010 ] ) ;
V_139 . V_1011 =
F_25 ( V_30 -> V_5 [ V_1010 ] ) ;
V_139 . V_957 =
F_80 ( V_30 -> V_5 [ V_1007 ] ) ;
if ( V_30 -> V_5 [ V_1008 ] ) {
T_2 V_24 ;
V_24 = F_35 ( V_30 -> V_5 [ V_1008 ] ) ;
if ( V_24 >= V_1009 )
return - V_16 ;
V_139 . V_959 = V_24 ;
} else {
V_139 . V_959 =
V_556 -> V_28 -> V_141 == V_144 ;
}
if ( V_30 -> V_5 [ V_1002 ] )
V_139 . V_960 = F_80 ( V_30 -> V_5 [ V_1002 ] ) ;
else
V_139 . V_960 = F_80 ( V_30 -> V_5 [ V_1006 ] ) ;
if ( ! V_139 . V_960 || V_139 . V_960 > V_1022 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1012 ] ) {
V_139 . V_1013 =
F_80 ( V_30 -> V_5 [ V_1012 ] ) ;
V_139 . V_967 |= V_970 ;
}
if ( V_30 -> V_5 [ V_1014 ] ) {
V_139 . V_972 =
F_24 ( V_30 -> V_5 [ V_1014 ] ) ;
V_139 . V_1015 =
F_25 ( V_30 -> V_5 [ V_1014 ] ) ;
}
if ( V_30 -> V_5 [ V_1003 ] )
V_139 . V_973 =
F_24 ( V_30 -> V_5 [ V_1003 ] ) ;
if ( V_30 -> V_5 [ V_1004 ] )
V_139 . V_974 =
F_24 ( V_30 -> V_5 [ V_1004 ] ) ;
if ( V_30 -> V_5 [ V_1028 ] ) {
V_139 . V_983 = true ;
V_139 . V_1029 =
F_35 ( V_30 -> V_5 [ V_1028 ] ) ;
}
if ( V_30 -> V_5 [ V_1016 ] ) {
V_139 . V_965 =
F_35 ( V_30 -> V_5 [ V_1016 ] ) ;
if ( V_139 . V_965 >= V_1017 )
return - V_16 ;
}
V_35 = F_190 ( V_30 , & V_139 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_189 ( V_30 , & V_139 ) ;
if ( V_35 )
return V_35 ;
if ( F_173 ( V_30 , V_556 -> V_28 -> V_141 , & V_139 ) )
return - V_16 ;
if ( ! ( V_139 . V_818 & F_118 ( V_825 ) ) ) {
V_139 . V_973 = NULL ;
V_139 . V_974 = NULL ;
}
F_115 ( V_813 != 7 ) ;
switch ( V_556 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_50 & V_405 ) ||
! ( V_139 . V_818 & F_118 ( V_825 ) ) )
V_139 . V_967 &= ~ V_969 ;
if ( ( V_139 . V_818 & F_118 ( V_827 ) ) ||
V_30 -> V_5 [ V_1002 ] )
return - V_16 ;
V_139 . V_817 &= ~ F_118 ( V_827 ) ;
if ( ! ( V_7 -> V_18 . V_368 &
V_979 ) &&
V_139 . V_817 & V_1031 )
return - V_16 ;
if ( ! ( V_139 . V_817 & V_1031 ) ) {
V_139 . V_817 |= V_1031 ;
V_139 . V_818 |= V_1031 ;
}
V_139 . V_976 = F_186 ( V_30 , V_7 ) ;
if ( F_18 ( V_139 . V_976 ) )
return F_19 ( V_139 . V_976 ) ;
break;
case V_145 :
V_139 . V_967 &= ~ V_969 ;
if ( V_139 . V_817 & F_118 ( V_978 ) )
return - V_16 ;
if ( ( V_139 . V_818 & F_118 ( V_827 ) ) ||
V_30 -> V_5 [ V_1002 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_139 . V_967 &= ~ V_969 ;
if ( V_139 . V_817 &
( F_118 ( V_978 ) |
F_118 ( V_828 ) ) )
return - V_16 ;
if ( ! ( V_139 . V_818 & F_118 ( V_827 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_50 & V_333 ) )
return - V_557 ;
if ( ! ( V_7 -> V_18 . V_50 & V_410 ) )
return - V_557 ;
V_139 . V_817 &= ~ F_118 ( V_823 ) ;
break;
default:
return - V_557 ;
}
V_35 = F_195 ( V_7 , V_556 , V_670 , & V_139 ) ;
if ( V_139 . V_976 )
F_188 ( V_139 . V_976 ) ;
return V_35 ;
}
static int F_196 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1032 V_139 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( V_30 -> V_5 [ V_564 ] )
V_139 . V_1033 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( V_556 -> V_28 -> V_141 != V_142 &&
V_556 -> V_28 -> V_141 != V_143 &&
V_556 -> V_28 -> V_141 != V_145 &&
V_556 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1034 )
return - V_557 ;
if ( V_30 -> V_5 [ V_1035 ] ) {
V_139 . V_1036 =
F_35 ( V_30 -> V_5 [ V_1035 ] ) ;
if ( V_139 . V_1036 != V_1037 >> 4 &&
V_139 . V_1036 != V_1038 >> 4 )
return - V_16 ;
} else {
V_139 . V_1036 = V_1038 >> 4 ;
}
if ( V_30 -> V_5 [ V_1039 ] ) {
V_139 . V_1040 =
F_80 ( V_30 -> V_5 [ V_1039 ] ) ;
if ( V_139 . V_1040 == 0 )
return - V_16 ;
} else {
V_139 . V_1040 = V_1041 ;
}
return F_197 ( V_7 , V_556 , & V_139 ) ;
}
static int F_198 ( struct V_31 * V_52 , V_22 V_48 , V_22 V_49 ,
int V_50 , struct V_25 * V_556 ,
T_2 * V_1042 , T_2 * V_1043 ,
struct V_1044 * V_1045 )
{
void * V_360 ;
struct V_4 * V_1046 ;
V_360 = F_26 ( V_52 , V_48 , V_49 , V_50 , V_1047 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_1042 ) ||
F_52 ( V_52 , V_1048 , V_604 , V_1043 ) ||
F_29 ( V_52 , V_370 , V_1045 -> V_861 ) )
goto V_60;
V_1046 = F_48 ( V_52 , V_1049 ) ;
if ( ! V_1046 )
goto V_60;
if ( ( V_1045 -> V_867 & V_1050 ) &&
F_29 ( V_52 , V_1051 ,
V_1045 -> V_1052 ) )
goto V_60;
if ( ( ( V_1045 -> V_867 & V_1053 ) &&
F_29 ( V_52 , V_1054 , V_1045 -> V_1055 ) ) ||
( ( V_1045 -> V_867 & V_1056 ) &&
F_29 ( V_52 , V_1057 ,
V_1045 -> V_1058 ) ) ||
( ( V_1045 -> V_867 & V_1059 ) &&
F_29 ( V_52 , V_1060 ,
V_1045 -> V_1061 ) ) ||
( ( V_1045 -> V_867 & V_1062 ) &&
F_57 ( V_52 , V_1063 ,
V_1045 -> V_50 ) ) ||
( ( V_1045 -> V_867 & V_1064 ) &&
F_29 ( V_52 , V_1065 ,
V_1045 -> V_1066 ) ) ||
( ( V_1045 -> V_867 & V_1067 ) &&
F_57 ( V_52 , V_1068 ,
V_1045 -> V_1069 ) ) )
goto V_60;
F_49 ( V_52 , V_1046 ) ;
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int F_199 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1044 V_1045 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1042 [ V_604 ] ;
T_2 V_1043 [ V_604 ] ;
int V_1070 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_328 -> V_1071 ) {
V_35 = - V_557 ;
goto V_951;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_557 ;
goto V_951;
}
while ( 1 ) {
V_35 = F_200 ( V_7 , V_17 -> V_19 , V_1070 , V_1042 ,
V_1043 , & V_1045 ) ;
if ( V_35 == - V_676 )
break;
if ( V_35 )
goto V_951;
if ( F_198 ( V_32 , F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_17 -> V_19 , V_1042 , V_1043 ,
& V_1045 ) < 0 )
goto V_616;
V_1070 ++ ;
}
V_616:
V_34 -> args [ 2 ] = V_1070 ;
V_35 = V_32 -> V_46 ;
V_951:
F_22 ( V_7 ) ;
return V_35 ;
}
static int F_201 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int V_35 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1044 V_1045 ;
struct V_31 * V_52 ;
T_2 * V_1042 = NULL ;
T_2 V_1043 [ V_604 ] ;
memset ( & V_1045 , 0 , sizeof( V_1045 ) ) ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_1042 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( ! V_7 -> V_328 -> V_1072 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_145 )
return - V_557 ;
V_35 = F_202 ( V_7 , V_556 , V_1042 , V_1043 , & V_1045 ) ;
if ( V_35 )
return V_35 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
if ( F_198 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_556 , V_1042 , V_1043 , & V_1045 ) < 0 ) {
F_77 ( V_52 ) ;
return - V_90 ;
}
return F_78 ( V_52 , V_30 ) ;
}
static int F_203 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 * V_1042 = NULL ;
T_2 * V_1043 = NULL ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1048 ] )
return - V_16 ;
V_1042 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_1043 = F_24 ( V_30 -> V_5 [ V_1048 ] ) ;
if ( ! V_7 -> V_328 -> V_1073 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_145 )
return - V_557 ;
return F_204 ( V_7 , V_556 , V_1042 , V_1043 ) ;
}
static int F_205 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 * V_1042 = NULL ;
T_2 * V_1043 = NULL ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1048 ] )
return - V_16 ;
V_1042 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_1043 = F_24 ( V_30 -> V_5 [ V_1048 ] ) ;
if ( ! V_7 -> V_328 -> V_293 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_145 )
return - V_557 ;
return F_206 ( V_7 , V_556 , V_1042 , V_1043 ) ;
}
static int F_207 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 * V_1042 = NULL ;
if ( V_30 -> V_5 [ V_564 ] )
V_1042 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( ! V_7 -> V_328 -> V_1074 )
return - V_557 ;
return F_208 ( V_7 , V_556 , V_1042 ) ;
}
static int F_209 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int V_35 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1044 V_1045 ;
struct V_31 * V_52 ;
T_2 * V_1042 = NULL ;
T_2 V_1075 [ V_604 ] ;
memset ( & V_1045 , 0 , sizeof( V_1045 ) ) ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_1042 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( ! V_7 -> V_328 -> V_1076 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_145 )
return - V_557 ;
V_35 = F_210 ( V_7 , V_556 , V_1042 , V_1075 , & V_1045 ) ;
if ( V_35 )
return V_35 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
if ( F_198 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_556 , V_1042 , V_1075 , & V_1045 ) < 0 ) {
F_77 ( V_52 ) ;
return - V_90 ;
}
return F_78 ( V_52 , V_30 ) ;
}
static int F_211 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1044 V_1045 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1042 [ V_604 ] ;
T_2 V_1075 [ V_604 ] ;
int V_1070 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_328 -> V_1077 ) {
V_35 = - V_557 ;
goto V_951;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_557 ;
goto V_951;
}
while ( 1 ) {
V_35 = F_212 ( V_7 , V_17 -> V_19 , V_1070 , V_1042 ,
V_1075 , & V_1045 ) ;
if ( V_35 == - V_676 )
break;
if ( V_35 )
goto V_951;
if ( F_198 ( V_32 , F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_17 -> V_19 , V_1042 , V_1075 ,
& V_1045 ) < 0 )
goto V_616;
V_1070 ++ ;
}
V_616:
V_34 -> args [ 2 ] = V_1070 ;
V_35 = V_32 -> V_46 ;
V_951:
F_22 ( V_7 ) ;
return V_35 ;
}
static int F_213 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_1078 V_139 ;
int V_35 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_1079 = - 1 ;
V_139 . V_1080 = - 1 ;
V_139 . V_1081 = - 1 ;
V_139 . V_1082 = - 1 ;
V_139 . V_1083 = - 1 ;
V_139 . V_796 = - 1 ;
V_139 . V_799 = - 1 ;
if ( V_30 -> V_5 [ V_1084 ] )
V_139 . V_1079 =
F_35 ( V_30 -> V_5 [ V_1084 ] ) ;
if ( V_30 -> V_5 [ V_1085 ] )
V_139 . V_1080 =
F_35 ( V_30 -> V_5 [ V_1085 ] ) ;
if ( V_30 -> V_5 [ V_1086 ] )
V_139 . V_1081 =
F_35 ( V_30 -> V_5 [ V_1086 ] ) ;
if ( V_30 -> V_5 [ V_1087 ] ) {
V_139 . V_1088 =
F_24 ( V_30 -> V_5 [ V_1087 ] ) ;
V_139 . V_1089 =
F_25 ( V_30 -> V_5 [ V_1087 ] ) ;
}
if ( V_30 -> V_5 [ V_1090 ] )
V_139 . V_1082 = ! ! F_35 ( V_30 -> V_5 [ V_1090 ] ) ;
if ( V_30 -> V_5 [ V_1091 ] )
V_139 . V_1083 =
F_80 ( V_30 -> V_5 [ V_1091 ] ) ;
if ( V_30 -> V_5 [ V_795 ] ) {
if ( V_556 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_139 . V_796 =
F_214 ( V_30 -> V_5 [ V_795 ] ) ;
if ( V_139 . V_796 < 0 )
return - V_16 ;
if ( V_139 . V_796 != 0 &&
! ( V_7 -> V_18 . V_368 & V_797 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_798 ] ) {
T_2 V_24 ;
if ( V_556 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_35 ( V_30 -> V_5 [ V_798 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_139 . V_799 = V_24 ;
if ( V_139 . V_799 &&
! ( V_7 -> V_18 . V_368 & V_800 ) )
return - V_16 ;
}
if ( ! V_7 -> V_328 -> V_297 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_142 &&
V_556 -> V_28 -> V_141 != V_144 )
return - V_557 ;
F_114 ( V_17 ) ;
V_35 = F_215 ( V_7 , V_556 , & V_139 ) ;
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_216 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_140 = NULL ;
bool V_1092 ;
enum V_1093 V_1094 ;
V_22 V_655 ;
if ( F_217 ( ! F_218 ( V_1095 ) ) )
return - V_1096 ;
if ( V_30 -> V_5 [ V_1097 ] )
V_1094 =
F_4 ( V_30 -> V_5 [ V_1097 ] ) ;
else
V_1094 = V_1098 ;
switch ( V_1094 ) {
case V_1098 :
case V_1099 :
if ( ! V_30 -> V_5 [ V_1100 ] )
return - V_16 ;
V_140 = F_24 ( V_30 -> V_5 [ V_1100 ] ) ;
return F_219 ( V_140 , V_1094 ) ;
case V_1101 :
if ( V_30 -> V_5 [ V_654 ] ) {
V_655 = V_30 -> V_521 ;
V_1092 = ! ! V_30 -> V_5 [ V_1102 ] ;
} else {
V_655 = 0 ;
V_1092 = true ;
}
return F_220 ( V_1092 , V_655 ) ;
default:
return - V_16 ;
}
}
static int F_221 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_1103 V_1104 ;
int V_35 = 0 ;
void * V_360 ;
struct V_4 * V_1046 ;
struct V_31 * V_52 ;
if ( V_17 -> V_141 != V_145 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_1105 )
return - V_557 ;
F_114 ( V_17 ) ;
if ( ! V_17 -> V_1106 )
memcpy ( & V_1104 , & V_1107 , sizeof( V_1104 ) ) ;
else
V_35 = F_222 ( V_7 , V_556 , & V_1104 ) ;
F_116 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1108 ) ;
if ( ! V_360 )
goto V_616;
V_1046 = F_48 ( V_52 , V_1109 ) ;
if ( ! V_1046 )
goto V_60;
if ( F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_56 ( V_52 , V_1110 ,
V_1104 . V_1111 ) ||
F_56 ( V_52 , V_1112 ,
V_1104 . V_1113 ) ||
F_56 ( V_52 , V_1114 ,
V_1104 . V_1115 ) ||
F_56 ( V_52 , V_1116 ,
V_1104 . V_1117 ) ||
F_57 ( V_52 , V_1118 ,
V_1104 . V_1119 ) ||
F_57 ( V_52 , V_1120 ,
V_1104 . V_1121 ) ||
F_57 ( V_52 , V_1122 ,
V_1104 . V_1123 ) ||
F_57 ( V_52 , V_1124 ,
V_1104 . V_1125 ) ||
F_29 ( V_52 , V_1126 ,
V_1104 . V_1127 ) ||
F_57 ( V_52 , V_1128 ,
V_1104 . V_1129 ) ||
F_29 ( V_52 , V_1130 ,
V_1104 . V_1131 ) ||
F_56 ( V_52 , V_1132 ,
V_1104 . V_1133 ) ||
F_29 ( V_52 , V_1134 ,
V_1104 . V_1135 ) ||
F_56 ( V_52 , V_1136 ,
V_1104 . V_1137 ) ||
F_56 ( V_52 , V_1138 ,
V_1104 . V_1139 ) ||
F_56 ( V_52 , V_1140 ,
V_1104 . V_1141 ) ||
F_57 ( V_52 , V_1142 ,
V_1104 . V_1143 ) ||
F_56 ( V_52 , V_1144 ,
V_1104 . V_1145 ) ||
F_57 ( V_52 , V_1146 ,
V_1104 . V_1147 ) ||
F_57 ( V_52 , V_1148 ,
V_1104 . V_1149 ) ||
F_29 ( V_52 , V_1150 ,
V_1104 . V_1151 ) ||
F_29 ( V_52 , V_1152 ,
V_1104 . V_1083 ) ||
F_29 ( V_52 , V_1153 ,
V_1104 . V_1154 ) ||
F_56 ( V_52 , V_1155 ,
V_1104 . V_1156 ) ||
F_56 ( V_52 , V_1157 ,
V_1104 . V_1158 ) ||
F_29 ( V_52 , V_1159 ,
V_1104 . V_1160 ) ||
F_56 ( V_52 , V_1161 ,
V_1104 . V_1162 ) ||
F_29 ( V_52 , V_1163 ,
V_1104 . V_1164 ) )
goto V_60;
F_49 ( V_52 , V_1046 ) ;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
F_69 ( V_52 , V_360 ) ;
V_616:
F_77 ( V_52 ) ;
return - V_90 ;
}
static int F_223 ( const struct V_4 * V_618 , T_2 V_1165 , T_2 V_175 , bool * V_616 )
{
T_2 V_1166 = F_35 ( V_618 ) ;
if ( V_1166 < V_1165 || V_1166 > V_175 )
return - V_16 ;
* V_616 = V_1166 ;
return 0 ;
}
static int F_224 ( const struct V_4 * V_618 , T_2 V_1165 , T_2 V_175 , T_2 * V_616 )
{
T_2 V_1166 = F_35 ( V_618 ) ;
if ( V_1166 < V_1165 || V_1166 > V_175 )
return - V_16 ;
* V_616 = V_1166 ;
return 0 ;
}
static int F_225 ( const struct V_4 * V_618 , T_3 V_1165 , T_3 V_175 , T_3 * V_616 )
{
T_3 V_1166 = F_80 ( V_618 ) ;
if ( V_1166 < V_1165 || V_1166 > V_175 )
return - V_16 ;
* V_616 = V_1166 ;
return 0 ;
}
static int F_226 ( const struct V_4 * V_618 , V_22 V_1165 , V_22 V_175 , V_22 * V_616 )
{
V_22 V_1166 = F_4 ( V_618 ) ;
if ( V_1166 < V_1165 || V_1166 > V_175 )
return - V_16 ;
* V_616 = V_1166 ;
return 0 ;
}
static int F_227 ( const struct V_4 * V_618 , T_6 V_1165 , T_6 V_175 , T_6 * V_616 )
{
T_6 V_1166 = F_228 ( V_618 ) ;
if ( V_1166 < V_1165 || V_1166 > V_175 )
return - V_16 ;
* V_616 = V_1166 ;
return 0 ;
}
static int F_229 ( const struct V_4 * V_618 ,
enum V_1024 V_1165 ,
enum V_1024 V_175 ,
enum V_1024 * V_616 )
{
V_22 V_1166 = F_4 ( V_618 ) ;
if ( V_1166 < V_1165 || V_1166 > V_175 )
return - V_16 ;
* V_616 = V_1166 ;
return 0 ;
}
static int F_230 ( struct V_29 * V_30 ,
struct V_1103 * V_1167 ,
V_22 * V_1168 )
{
struct V_4 * V_94 [ V_1169 + 1 ] ;
V_22 V_702 = 0 ;
T_3 V_1083 ;
#define F_231 ( V_94 , V_1167 , T_7 , V_1165 , V_175 , V_702 , V_44 , T_8 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr], min, max, &cfg->param)) \
return -EINVAL; \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1109 ] )
return - V_16 ;
if ( F_34 ( V_94 , V_1169 ,
V_30 -> V_5 [ V_1109 ] ,
V_1170 ) )
return - V_16 ;
F_115 ( V_1169 > 32 ) ;
F_231 ( V_94 , V_1167 , V_1111 , 1 , 255 ,
V_702 , V_1110 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1113 , 1 , 255 ,
V_702 , V_1112 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1115 , 1 , 255 ,
V_702 , V_1114 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1117 , 0 , 255 ,
V_702 , V_1116 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1119 , 0 , 16 ,
V_702 , V_1118 ,
F_224 ) ;
F_231 ( V_94 , V_1167 , V_1121 , 1 , 255 ,
V_702 , V_1120 , F_224 ) ;
F_231 ( V_94 , V_1167 , V_1123 , 1 , 255 ,
V_702 , V_1122 ,
F_224 ) ;
F_231 ( V_94 , V_1167 , V_1125 , 0 , 1 ,
V_702 , V_1124 ,
F_223 ) ;
F_231 ( V_94 , V_1167 , V_1127 ,
1 , 255 , V_702 ,
V_1126 ,
F_226 ) ;
F_231 ( V_94 , V_1167 , V_1129 , 0 , 255 ,
V_702 , V_1128 ,
F_224 ) ;
F_231 ( V_94 , V_1167 , V_1131 , 1 , 65535 ,
V_702 , V_1130 ,
F_226 ) ;
F_231 ( V_94 , V_1167 , V_1133 , 1 , 65535 ,
V_702 , V_1132 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1135 ,
1 , 65535 , V_702 ,
V_1134 ,
F_226 ) ;
F_231 ( V_94 , V_1167 , V_1137 ,
1 , 65535 , V_702 ,
V_1136 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1139 ,
1 , 65535 , V_702 ,
V_1138 ,
F_225 ) ;
F_231 ( V_94 , V_1167 ,
V_1141 ,
1 , 65535 , V_702 ,
V_1140 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1143 , 0 , 4 ,
V_702 , V_1142 ,
F_224 ) ;
F_231 ( V_94 , V_1167 , V_1145 , 1 , 65535 ,
V_702 , V_1144 ,
F_225 ) ;
F_231 ( V_94 , V_1167 ,
V_1147 , 0 , 1 ,
V_702 , V_1146 ,
F_223 ) ;
F_231 ( V_94 , V_1167 , V_1149 , 0 , 1 ,
V_702 , V_1148 ,
F_223 ) ;
F_231 ( V_94 , V_1167 , V_1151 , - 255 , 0 ,
V_702 , V_1150 ,
F_227 ) ;
if ( V_94 [ V_1152 ] ) {
V_1083 = F_80 ( V_94 [ V_1152 ] ) ;
if ( V_1083 & ~ ( V_1171 |
V_1172 |
V_1173 ) )
return - V_16 ;
if ( ( V_1083 & V_1172 ) &&
( V_1083 & V_1173 ) )
return - V_16 ;
switch ( V_1083 & V_1171 ) {
case V_1174 :
case V_1175 :
if ( V_1083 & V_1173 )
return - V_16 ;
break;
case V_1176 :
case V_1177 :
if ( ! ( V_1083 & V_1173 ) )
return - V_16 ;
break;
}
V_1167 -> V_1083 = V_1083 ;
V_702 |= ( 1 << ( V_1152 - 1 ) ) ;
}
F_231 ( V_94 , V_1167 , V_1154 ,
1 , 65535 , V_702 ,
V_1153 ,
F_226 ) ;
F_231 ( V_94 , V_1167 , V_1156 , 1 , 65535 ,
V_702 , V_1155 ,
F_225 ) ;
F_231 ( V_94 , V_1167 ,
V_1158 ,
1 , 65535 , V_702 ,
V_1157 ,
F_225 ) ;
F_231 ( V_94 , V_1167 , V_1160 ,
V_1178 ,
V_1027 ,
V_702 , V_1159 ,
F_229 ) ;
F_231 ( V_94 , V_1167 , V_1162 ,
0 , 65535 , V_702 ,
V_1161 , F_225 ) ;
F_231 ( V_94 , V_1167 , V_1164 , 0 , 0xffffffff ,
V_702 , V_1163 ,
F_226 ) ;
if ( V_1168 )
* V_1168 = V_702 ;
return 0 ;
#undef F_231
}
static int F_232 ( struct V_29 * V_30 ,
struct V_1179 * V_1180 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_4 * V_94 [ V_1181 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1182 ] )
return - V_16 ;
if ( F_34 ( V_94 , V_1181 ,
V_30 -> V_5 [ V_1182 ] ,
V_1183 ) )
return - V_16 ;
if ( V_94 [ V_1184 ] )
V_1180 -> V_1185 =
( F_35 ( V_94 [ V_1184 ] ) ) ?
V_1186 :
V_1187 ;
if ( V_94 [ V_1188 ] )
V_1180 -> V_1189 =
( F_35 ( V_94 [ V_1188 ] ) ) ?
V_1190 :
V_1191 ;
if ( V_94 [ V_1192 ] )
V_1180 -> V_1193 =
( F_35 ( V_94 [ V_1192 ] ) ) ?
V_1194 :
V_1195 ;
if ( V_94 [ V_1196 ] ) {
struct V_4 * V_1197 =
V_94 [ V_1196 ] ;
if ( ! F_23 ( V_1197 ) )
return - V_16 ;
V_1180 -> V_1198 = F_24 ( V_1197 ) ;
V_1180 -> V_1199 = F_25 ( V_1197 ) ;
}
if ( V_94 [ V_1200 ] &&
! ( V_7 -> V_18 . V_368 & V_1201 ) )
return - V_16 ;
V_1180 -> V_1202 = F_167 ( V_94 [ V_1200 ] ) ;
V_1180 -> V_1203 = F_167 ( V_94 [ V_1204 ] ) ;
V_1180 -> V_1205 = F_167 ( V_94 [ V_1206 ] ) ;
if ( V_1180 -> V_1205 )
V_1180 -> V_1202 = true ;
if ( V_94 [ V_1207 ] ) {
if ( ! V_1180 -> V_1202 )
return - V_16 ;
V_1180 -> V_1208 =
F_35 ( V_94 [ V_1207 ] ) ;
}
return 0 ;
}
static int F_233 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_1103 V_1167 ;
V_22 V_702 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_295 )
return - V_557 ;
V_35 = F_230 ( V_30 , & V_1167 , & V_702 ) ;
if ( V_35 )
return V_35 ;
F_114 ( V_17 ) ;
if ( ! V_17 -> V_1106 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_234 ( V_7 , V_556 , V_702 , & V_1167 ) ;
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_235 ( const struct V_1209 * V_1210 ,
struct V_31 * V_52 )
{
struct V_4 * V_1211 ;
unsigned int V_160 ;
if ( F_64 ( V_52 , V_1100 , V_1210 -> V_1212 ) ||
( V_1210 -> V_1213 &&
F_57 ( V_52 , V_1214 , V_1210 -> V_1213 ) ) )
goto V_60;
V_1211 = F_48 ( V_52 , V_1215 ) ;
if ( ! V_1211 )
goto V_60;
for ( V_160 = 0 ; V_160 < V_1210 -> V_1216 ; V_160 ++ ) {
struct V_4 * V_1217 ;
const struct V_1218 * V_1219 ;
const struct V_1220 * V_1221 ;
const struct V_1222 * V_1223 ;
unsigned int V_1224 ;
V_1219 = & V_1210 -> V_1225 [ V_160 ] ;
V_1221 = & V_1219 -> V_1221 ;
V_1223 = & V_1219 -> V_1223 ;
V_1217 = F_48 ( V_52 , V_160 ) ;
if ( ! V_1217 )
goto V_60;
V_1224 = V_1221 -> V_1224 ;
if ( ! V_1224 )
V_1224 = F_236 ( V_1210 ,
V_1219 ) ;
if ( F_29 ( V_52 , V_1226 ,
V_1219 -> V_50 ) ||
F_29 ( V_52 , V_1227 ,
V_1221 -> V_1228 ) ||
F_29 ( V_52 , V_1229 ,
V_1221 -> V_1230 ) ||
F_29 ( V_52 , V_1231 ,
V_1224 ) ||
F_29 ( V_52 , V_1232 ,
V_1223 -> V_1233 ) ||
F_29 ( V_52 , V_1234 ,
V_1223 -> V_1235 ) ||
F_29 ( V_52 , V_1236 ,
V_1219 -> V_73 ) )
goto V_60;
F_49 ( V_52 , V_1217 ) ;
}
F_49 ( V_52 , V_1211 ) ;
return 0 ;
V_60:
return - V_512 ;
}
static int F_237 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1209 * V_1210 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_90 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1237 ) ;
if ( ! V_360 )
goto V_1238;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1239 ;
V_7 = F_12 ( F_96 ( V_30 ) , V_30 ) ;
if ( F_18 ( V_7 ) ) {
F_77 ( V_52 ) ;
return F_19 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1239 = V_18 -> V_497 &
V_498 ;
V_1210 = F_238 ( V_18 ) ;
if ( F_63 ( ! V_1210 && V_1239 ) ) {
F_77 ( V_52 ) ;
return - V_16 ;
}
if ( V_1210 &&
F_29 ( V_52 , V_26 , F_239 ( V_18 ) ) )
goto V_60;
}
if ( ! V_18 && F_240 () &&
F_29 ( V_52 , V_1097 ,
V_1099 ) )
goto V_60;
F_241 () ;
if ( ! V_1210 )
V_1210 = F_242 ( V_1095 ) ;
if ( F_235 ( V_1210 , V_52 ) )
goto V_1240;
F_243 () ;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_1240:
F_243 () ;
V_60:
F_69 ( V_52 , V_360 ) ;
V_1238:
F_77 ( V_52 ) ;
return - V_512 ;
}
static int F_244 ( struct V_31 * V_52 , struct V_33 * V_34 ,
V_22 V_49 , int V_50 , struct V_18 * V_18 ,
const struct V_1209 * V_1210 )
{
void * V_360 = F_26 ( V_52 , F_73 ( V_34 -> V_32 ) . V_48 , V_49 , V_50 ,
V_1237 ) ;
if ( ! V_360 )
return - 1 ;
F_245 ( V_34 , V_360 , & V_38 ) ;
if ( F_235 ( V_1210 , V_52 ) )
goto V_60;
if ( ! V_18 && F_240 () &&
F_29 ( V_52 , V_1097 ,
V_1099 ) )
goto V_60;
if ( V_18 &&
F_29 ( V_52 , V_26 , F_239 ( V_18 ) ) )
goto V_60;
if ( V_18 && V_18 -> V_497 & V_498 &&
F_30 ( V_52 , V_499 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int F_246 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1209 * V_1210 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1241 , V_516 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1095 && V_516 == 0 ) {
V_35 = F_244 ( V_32 , V_34 , V_34 -> V_36 -> V_517 ,
V_518 , NULL ,
F_247 ( V_1095 ) ) ;
if ( V_35 < 0 )
goto V_951;
}
V_1241 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1210 = F_238 ( & V_7 -> V_18 ) ;
if ( ! V_1210 )
continue;
if ( ++ V_1241 <= V_516 )
continue;
V_35 = F_244 ( V_32 , V_34 , V_34 -> V_36 -> V_517 ,
V_518 , & V_7 -> V_18 , V_1210 ) ;
if ( V_35 < 0 ) {
V_1241 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1241 ;
V_35 = V_32 -> V_46 ;
V_951:
F_21 () ;
return V_35 ;
}
static int F_248 ( struct V_4 * V_94 [] ,
struct V_1218 * V_1219 )
{
struct V_1220 * V_1221 = & V_1219 -> V_1221 ;
struct V_1222 * V_1223 = & V_1219 -> V_1223 ;
if ( ! V_94 [ V_1226 ] )
return - V_16 ;
if ( ! V_94 [ V_1227 ] )
return - V_16 ;
if ( ! V_94 [ V_1229 ] )
return - V_16 ;
if ( ! V_94 [ V_1231 ] )
return - V_16 ;
if ( ! V_94 [ V_1234 ] )
return - V_16 ;
V_1219 -> V_50 = F_4 ( V_94 [ V_1226 ] ) ;
V_1221 -> V_1228 =
F_4 ( V_94 [ V_1227 ] ) ;
V_1221 -> V_1230 =
F_4 ( V_94 [ V_1229 ] ) ;
V_1221 -> V_1224 =
F_4 ( V_94 [ V_1231 ] ) ;
V_1223 -> V_1235 =
F_4 ( V_94 [ V_1234 ] ) ;
if ( V_94 [ V_1232 ] )
V_1223 -> V_1233 =
F_4 ( V_94 [ V_1232 ] ) ;
if ( V_94 [ V_1236 ] )
V_1219 -> V_73 =
F_4 ( V_94 [ V_1236 ] ) ;
return 0 ;
}
static int F_249 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_94 [ V_1242 + 1 ] ;
struct V_4 * V_1217 ;
char * V_1212 ;
int V_1243 , V_1244 ;
V_22 V_1245 = 0 , V_1246 = 0 , V_1247 ;
enum V_1248 V_1213 = V_1249 ;
struct V_1209 * V_1250 ;
if ( ! V_30 -> V_5 [ V_1100 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1215 ] )
return - V_16 ;
V_1212 = F_24 ( V_30 -> V_5 [ V_1100 ] ) ;
if ( V_30 -> V_5 [ V_1214 ] )
V_1213 = F_35 ( V_30 -> V_5 [ V_1214 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1245 ++ ;
if ( V_1245 > V_1251 )
return - V_16 ;
}
if ( ! F_250 ( V_1212 ) )
return - V_16 ;
V_1247 = sizeof( struct V_1209 ) +
V_1245 * sizeof( struct V_1218 ) ;
V_1250 = F_40 ( V_1247 , V_135 ) ;
if ( ! V_1250 )
return - V_136 ;
V_1250 -> V_1216 = V_1245 ;
V_1250 -> V_1212 [ 0 ] = V_1212 [ 0 ] ;
V_1250 -> V_1212 [ 1 ] = V_1212 [ 1 ] ;
if ( F_251 ( V_1213 ) )
V_1250 -> V_1213 = V_1213 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1244 = F_34 ( V_94 , V_1242 ,
V_1217 , V_1252 ) ;
if ( V_1244 )
goto V_1253;
V_1244 = F_248 ( V_94 , & V_1250 -> V_1225 [ V_1246 ] ) ;
if ( V_1244 )
goto V_1253;
V_1246 ++ ;
if ( V_1246 > V_1251 ) {
V_1244 = - V_16 ;
goto V_1253;
}
}
return F_252 ( V_1250 , V_1254 ) ;
V_1253:
F_42 ( V_1250 ) ;
return V_1244 ;
}
static int F_253 ( struct V_4 * V_1255 )
{
struct V_4 * V_1256 , * V_1257 ;
int V_441 = 0 , V_1258 , V_1259 ;
F_39 (attr1, freqs, tmp1) {
V_441 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1256 != V_1257 &&
F_4 ( V_1256 ) == F_4 ( V_1257 ) )
return 0 ;
}
return V_441 ;
}
static bool F_254 ( struct V_18 * V_18 , enum V_366 V_1260 )
{
return V_1260 < V_437 && V_18 -> V_438 [ V_1260 ] ;
}
static int F_255 ( struct V_4 * V_618 , struct V_18 * V_18 ,
struct V_1261 * V_1262 )
{
struct V_4 * V_44 [ V_1263 + 1 ] ;
struct V_4 * V_1264 ;
int V_35 ;
bool V_27 = false ;
int V_160 ;
V_1264 = F_24 ( V_618 ) ;
if ( ! F_256 ( V_1264 , F_25 ( V_1264 ) ) )
return - V_16 ;
V_35 = F_34 ( V_44 , V_1263 , V_1264 ,
V_1265 ) ;
if ( V_35 )
return V_35 ;
for ( V_160 = 0 ; V_160 <= V_1263 ; V_160 ++ ) {
if ( V_44 [ V_160 ] ) {
if ( V_27 )
return - V_16 ;
V_27 = true ;
}
}
V_1262 -> V_1266 = V_1267 ;
if ( V_44 [ V_1268 ] )
V_1262 -> V_1266 = V_1268 ;
if ( V_44 [ V_1269 ] ) {
V_1262 -> V_1266 = V_1269 ;
V_1262 -> T_7 . V_1270 =
F_4 ( V_44 [ V_1269 ] ) ;
if ( ! F_254 ( V_18 , V_1262 -> T_7 . V_1270 ) )
return - V_16 ;
}
if ( V_44 [ V_1271 ] ) {
struct V_1272 * V_1273 ;
V_1273 = F_24 ( V_44 [ V_1271 ] ) ;
V_1262 -> V_1266 = V_1271 ;
V_1262 -> T_7 . V_1274 . V_367 = V_1273 -> V_367 ;
V_1262 -> T_7 . V_1274 . V_1275 = V_1273 -> V_1275 ;
if ( ! F_254 ( V_18 , V_1262 -> T_7 . V_1274 . V_367 ) )
return - V_16 ;
}
if ( V_1262 -> V_1266 == V_1267 )
return - V_16 ;
if ( ! ( V_18 -> V_502 & F_118 ( V_1262 -> V_1266 ) ) )
return - V_16 ;
return 0 ;
}
static int F_257 ( struct V_4 * * V_5 ,
T_2 * V_670 , T_2 * V_1276 )
{
int V_160 ;
if ( ! V_5 [ V_564 ] && ! V_5 [ V_1277 ] ) {
F_258 ( V_670 ) ;
F_258 ( V_1276 ) ;
V_670 [ 0 ] = 0x2 ;
V_1276 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_564 ] || ! V_5 [ V_1277 ] )
return - V_16 ;
memcpy ( V_670 , F_24 ( V_5 [ V_564 ] ) , V_604 ) ;
memcpy ( V_1276 , F_24 ( V_5 [ V_1277 ] ) , V_604 ) ;
if ( ! F_259 ( V_1276 ) ||
F_259 ( V_670 ) )
return - V_16 ;
for ( V_160 = 0 ; V_160 < V_604 ; V_160 ++ )
V_670 [ V_160 ] &= V_1276 [ V_160 ] ;
return 0 ;
}
static int F_260 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
struct V_1278 * V_1279 ;
struct V_4 * V_44 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1280 = 0 , V_441 , V_160 ;
T_9 V_1199 ;
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_17 -> V_141 == V_154 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_1281 )
return - V_557 ;
if ( V_7 -> V_1282 || V_7 -> V_1283 ) {
V_35 = - V_561 ;
goto V_1284;
}
if ( V_30 -> V_5 [ V_1285 ] ) {
V_441 = F_253 (
V_30 -> V_5 [ V_1285 ] ) ;
if ( ! V_441 ) {
V_35 = - V_16 ;
goto V_1284;
}
} else {
V_441 = F_261 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1286 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1280 ++ ;
if ( V_1280 > V_18 -> V_386 ) {
V_35 = - V_16 ;
goto V_1284;
}
if ( V_30 -> V_5 [ V_747 ] )
V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
else
V_1199 = 0 ;
if ( V_1199 > V_18 -> V_390 ) {
V_35 = - V_16 ;
goto V_1284;
}
V_1279 = F_40 ( sizeof( * V_1279 )
+ sizeof( * V_1279 -> V_1287 ) * V_1280
+ sizeof( * V_1279 -> V_442 ) * V_441
+ V_1199 , V_135 ) ;
if ( ! V_1279 ) {
V_35 = - V_136 ;
goto V_1284;
}
if ( V_1280 )
V_1279 -> V_1287 = ( void * ) & V_1279 -> V_442 [ V_441 ] ;
V_1279 -> V_1280 = V_1280 ;
if ( V_1199 ) {
if ( V_1280 )
V_1279 -> V_1198 = ( void * ) ( V_1279 -> V_1287 + V_1280 ) ;
else
V_1279 -> V_1198 = ( void * ) ( V_1279 -> V_442 + V_441 ) ;
}
V_160 = 0 ;
if ( V_30 -> V_5 [ V_1285 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_53 * V_54 ;
V_54 = F_46 ( V_18 , F_4 ( V_44 ) ) ;
if ( ! V_54 ) {
V_35 = - V_16 ;
goto V_1288;
}
if ( V_54 -> V_50 & V_61 )
continue;
V_1279 -> V_442 [ V_160 ] = V_54 ;
V_160 ++ ;
}
} else {
enum V_366 V_367 ;
for ( V_367 = 0 ; V_367 < V_437 ; V_367 ++ ) {
int V_162 ;
if ( ! V_18 -> V_438 [ V_367 ] )
continue;
for ( V_162 = 0 ; V_162 < V_18 -> V_438 [ V_367 ] -> V_441 ; V_162 ++ ) {
struct V_53 * V_54 ;
V_54 = & V_18 -> V_438 [ V_367 ] -> V_442 [ V_162 ] ;
if ( V_54 -> V_50 & V_61 )
continue;
V_1279 -> V_442 [ V_160 ] = V_54 ;
V_160 ++ ;
}
}
}
if ( ! V_160 ) {
V_35 = - V_16 ;
goto V_1288;
}
V_1279 -> V_441 = V_160 ;
V_160 = 0 ;
if ( V_1280 ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_25 ( V_44 ) > V_635 ) {
V_35 = - V_16 ;
goto V_1288;
}
V_1279 -> V_1287 [ V_160 ] . V_609 = F_25 ( V_44 ) ;
memcpy ( V_1279 -> V_1287 [ V_160 ] . V_611 , F_24 ( V_44 ) , F_25 ( V_44 ) ) ;
V_160 ++ ;
}
}
if ( V_30 -> V_5 [ V_747 ] ) {
V_1279 -> V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
memcpy ( ( void * ) V_1279 -> V_1198 ,
F_24 ( V_30 -> V_5 [ V_747 ] ) ,
V_1279 -> V_1199 ) ;
}
for ( V_160 = 0 ; V_160 < V_437 ; V_160 ++ )
if ( V_18 -> V_438 [ V_160 ] )
V_1279 -> V_700 [ V_160 ] =
( 1 << V_18 -> V_438 [ V_160 ] -> V_264 ) - 1 ;
if ( V_30 -> V_5 [ V_1289 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_366 V_367 = F_156 ( V_44 ) ;
if ( V_367 < 0 || V_367 >= V_437 ) {
V_35 = - V_16 ;
goto V_1288;
}
if ( ! V_18 -> V_438 [ V_367 ] )
continue;
V_35 = F_262 ( V_18 -> V_438 [ V_367 ] ,
F_24 ( V_44 ) ,
F_25 ( V_44 ) ,
& V_1279 -> V_700 [ V_367 ] ) ;
if ( V_35 )
goto V_1288;
}
}
if ( V_30 -> V_5 [ V_1290 ] ) {
if ( ! F_117 ( V_18 ,
V_1291 ) ) {
V_35 = - V_557 ;
goto V_1288;
}
V_1279 -> V_1292 =
F_80 ( V_30 -> V_5 [ V_1290 ] ) ;
V_1279 -> V_1293 =
F_167 ( V_30 -> V_5 [ V_1294 ] ) ;
}
if ( V_30 -> V_5 [ V_1295 ] ) {
V_1279 -> V_50 = F_4 (
V_30 -> V_5 [ V_1295 ] ) ;
if ( ( V_1279 -> V_50 & V_1296 ) &&
! ( V_18 -> V_368 & V_1297 ) ) {
V_35 = - V_557 ;
goto V_1288;
}
if ( V_1279 -> V_50 & V_1298 ) {
if ( ! ( V_18 -> V_368 &
V_1299 ) ) {
V_35 = - V_557 ;
goto V_1288;
}
if ( V_17 -> V_149 ) {
V_35 = - V_557 ;
goto V_1288;
}
V_35 = F_257 ( V_30 -> V_5 ,
V_1279 -> V_670 ,
V_1279 -> V_1276 ) ;
if ( V_35 )
goto V_1288;
}
}
V_1279 -> V_1300 =
F_167 ( V_30 -> V_5 [ V_1301 ] ) ;
if ( V_30 -> V_5 [ V_1302 ] )
memcpy ( V_1279 -> V_563 ,
F_24 ( V_30 -> V_5 [ V_1302 ] ) , V_604 ) ;
else if ( ! ( V_1279 -> V_50 & V_1298 ) &&
V_30 -> V_5 [ V_564 ] )
memcpy ( V_1279 -> V_563 , F_24 ( V_30 -> V_5 [ V_564 ] ) ,
V_604 ) ;
else
F_263 ( V_1279 -> V_563 ) ;
V_1279 -> V_17 = V_17 ;
V_1279 -> V_18 = & V_7 -> V_18 ;
V_1279 -> V_1303 = V_1304 ;
V_7 -> V_1282 = V_1279 ;
V_35 = F_264 ( V_7 , V_1279 ) ;
if ( ! V_35 ) {
F_265 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_266 ( V_17 -> V_19 ) ;
} else {
V_1288:
V_7 -> V_1282 = NULL ;
F_42 ( V_1279 ) ;
}
V_1284:
return V_35 ;
}
static int F_267 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_1305 )
return - V_557 ;
if ( V_7 -> V_1283 )
return 0 ;
if ( ! V_7 -> V_1282 )
return - V_676 ;
F_268 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_269 ( struct V_18 * V_18 , int V_1306 ,
struct V_1307 * V_1279 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_160 = 0 ;
struct V_4 * V_44 ;
if ( ! V_5 [ V_1308 ] ) {
V_22 V_1309 ;
if ( ! V_5 [ V_1310 ] )
return - V_16 ;
V_1309 = F_4 ( V_5 [ V_1310 ] ) ;
if ( ! V_1309 )
return - V_16 ;
V_1279 -> V_1311 [ 0 ] . V_1309 =
F_270 ( V_1309 , V_1312 ) ;
if ( ! V_1279 -> V_1311 [ 0 ] . V_1309 )
return - V_16 ;
if ( V_1279 -> V_1311 [ 0 ] . V_1309 >
V_18 -> V_398 )
V_1279 -> V_1311 [ 0 ] . V_1309 =
V_18 -> V_398 ;
return 0 ;
}
F_39 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1313 [ V_1314 + 1 ] ;
if ( F_63 ( V_160 >= V_1306 ) )
return - V_16 ;
V_35 = F_34 ( V_1313 , V_1314 ,
V_44 , V_1315 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1313 [ V_1316 ] )
return - V_16 ;
V_1279 -> V_1311 [ V_160 ] . V_1309 =
F_4 ( V_1313 [ V_1316 ] ) ;
if ( ! V_1279 -> V_1311 [ V_160 ] . V_1309 ||
V_1279 -> V_1311 [ V_160 ] . V_1309 >
V_18 -> V_398 )
return - V_16 ;
if ( V_1313 [ V_1317 ] ) {
V_1279 -> V_1311 [ V_160 ] . V_1318 =
F_4 ( V_1313 [ V_1317 ] ) ;
if ( ! V_1279 -> V_1311 [ V_160 ] . V_1318 ||
( V_1279 -> V_1311 [ V_160 ] . V_1318 >
V_18 -> V_400 ) )
return - V_16 ;
} else if ( V_160 < V_1306 - 1 ) {
return - V_16 ;
}
V_160 ++ ;
}
if ( V_1279 -> V_1311 [ V_1306 - 1 ] . V_1318 )
return - V_16 ;
return 0 ;
}
static struct V_1307 *
F_271 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1307 * V_1279 ;
struct V_4 * V_44 ;
int V_35 , V_24 , V_1280 = 0 , V_1319 = 0 , V_441 , V_160 , V_1306 = 0 ;
enum V_366 V_367 ;
T_9 V_1199 ;
struct V_4 * V_94 [ V_1320 + 1 ] ;
T_6 V_1321 = V_1322 ;
if ( ! F_23 ( V_5 [ V_747 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1285 ] ) {
V_441 = F_253 (
V_5 [ V_1285 ] ) ;
if ( ! V_441 )
return F_3 ( - V_16 ) ;
} else {
V_441 = F_261 ( V_18 ) ;
}
if ( V_5 [ V_1286 ] )
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1280 ++ ;
if ( V_1280 > V_18 -> V_388 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1323 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1324 ;
V_35 = F_34 ( V_94 ,
V_1320 ,
V_44 , V_1325 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_94 [ V_1326 ] ) {
V_1319 ++ ;
continue;
}
V_1324 = V_94 [ V_1327 ] ;
if ( V_1324 )
V_1321 = F_228 ( V_1324 ) ;
}
}
if ( ! V_1319 && V_1321 != V_1322 )
V_1319 = 1 ;
if ( V_1319 > V_18 -> V_394 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_747 ] )
V_1199 = F_25 ( V_5 [ V_747 ] ) ;
else
V_1199 = 0 ;
if ( V_1199 > V_18 -> V_392 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1308 ] ) {
if ( V_5 [ V_1310 ] )
return F_3 ( - V_16 ) ;
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1306 ++ ;
} else {
if ( ! V_5 [ V_1310 ] )
return F_3 ( - V_16 ) ;
V_1306 = 1 ;
}
if ( ! V_1306 || V_1306 > V_18 -> V_396 )
return F_3 ( - V_16 ) ;
V_1279 = F_40 ( sizeof( * V_1279 )
+ sizeof( * V_1279 -> V_1287 ) * V_1280
+ sizeof( * V_1279 -> V_1328 ) * V_1319
+ sizeof( * V_1279 -> V_1311 ) * V_1306
+ sizeof( * V_1279 -> V_442 ) * V_441
+ V_1199 , V_135 ) ;
if ( ! V_1279 )
return F_3 ( - V_136 ) ;
if ( V_1280 )
V_1279 -> V_1287 = ( void * ) & V_1279 -> V_442 [ V_441 ] ;
V_1279 -> V_1280 = V_1280 ;
if ( V_1199 ) {
if ( V_1280 )
V_1279 -> V_1198 = ( void * ) ( V_1279 -> V_1287 + V_1280 ) ;
else
V_1279 -> V_1198 = ( void * ) ( V_1279 -> V_442 + V_441 ) ;
}
if ( V_1319 ) {
if ( V_1279 -> V_1198 )
V_1279 -> V_1328 = ( void * ) ( V_1279 -> V_1198 + V_1199 ) ;
else if ( V_1280 )
V_1279 -> V_1328 =
( void * ) ( V_1279 -> V_1287 + V_1280 ) ;
else
V_1279 -> V_1328 =
( void * ) ( V_1279 -> V_442 + V_441 ) ;
}
V_1279 -> V_1319 = V_1319 ;
if ( V_1319 )
V_1279 -> V_1311 = ( void * ) ( V_1279 -> V_1328 +
V_1319 ) ;
else if ( V_1279 -> V_1198 )
V_1279 -> V_1311 = ( void * ) ( V_1279 -> V_1198 + V_1199 ) ;
else if ( V_1280 )
V_1279 -> V_1311 = ( void * ) ( V_1279 -> V_1287 + V_1280 ) ;
else
V_1279 -> V_1311 = ( void * ) ( V_1279 -> V_442 + V_441 ) ;
V_1279 -> V_1329 = V_1306 ;
V_160 = 0 ;
if ( V_5 [ V_1285 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_53 * V_54 ;
V_54 = F_46 ( V_18 , F_4 ( V_44 ) ) ;
if ( ! V_54 ) {
V_35 = - V_16 ;
goto V_1288;
}
if ( V_54 -> V_50 & V_61 )
continue;
V_1279 -> V_442 [ V_160 ] = V_54 ;
V_160 ++ ;
}
} else {
for ( V_367 = 0 ; V_367 < V_437 ; V_367 ++ ) {
int V_162 ;
if ( ! V_18 -> V_438 [ V_367 ] )
continue;
for ( V_162 = 0 ; V_162 < V_18 -> V_438 [ V_367 ] -> V_441 ; V_162 ++ ) {
struct V_53 * V_54 ;
V_54 = & V_18 -> V_438 [ V_367 ] -> V_442 [ V_162 ] ;
if ( V_54 -> V_50 & V_61 )
continue;
V_1279 -> V_442 [ V_160 ] = V_54 ;
V_160 ++ ;
}
}
}
if ( ! V_160 ) {
V_35 = - V_16 ;
goto V_1288;
}
V_1279 -> V_441 = V_160 ;
V_160 = 0 ;
if ( V_1280 ) {
F_39 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_25 ( V_44 ) > V_635 ) {
V_35 = - V_16 ;
goto V_1288;
}
V_1279 -> V_1287 [ V_160 ] . V_609 = F_25 ( V_44 ) ;
memcpy ( V_1279 -> V_1287 [ V_160 ] . V_611 , F_24 ( V_44 ) ,
F_25 ( V_44 ) ) ;
V_160 ++ ;
}
}
V_160 = 0 ;
if ( V_5 [ V_1323 ] ) {
F_39 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_611 , * V_1324 ;
V_35 = F_34 ( V_94 ,
V_1320 ,
V_44 , V_1325 ) ;
if ( V_35 )
goto V_1288;
V_611 = V_94 [ V_1326 ] ;
if ( V_611 ) {
if ( F_63 ( V_160 >= V_1319 ) ) {
V_35 = - V_16 ;
goto V_1288;
}
if ( F_25 ( V_611 ) > V_635 ) {
V_35 = - V_16 ;
goto V_1288;
}
memcpy ( V_1279 -> V_1328 [ V_160 ] . V_611 . V_611 ,
F_24 ( V_611 ) , F_25 ( V_611 ) ) ;
V_1279 -> V_1328 [ V_160 ] . V_611 . V_609 =
F_25 ( V_611 ) ;
V_1279 -> V_1328 [ V_160 ] . V_1330 =
V_1321 ;
V_1324 = V_94 [ V_1327 ] ;
if ( V_1324 )
V_1279 -> V_1328 [ V_160 ] . V_1330 =
F_228 ( V_1324 ) ;
}
V_160 ++ ;
}
if ( V_160 == 0 && V_1319 )
V_1279 -> V_1328 [ 0 ] . V_1330 = V_1321 ;
V_1279 -> V_1331 = V_1332 ;
for ( V_160 = 0 ; V_160 < V_1319 ; V_160 ++ )
V_1279 -> V_1331 =
V_1165 ( V_1279 -> V_1328 [ V_160 ] . V_1330 ,
V_1279 -> V_1331 ) ;
} else {
V_1279 -> V_1331 = V_1322 ;
}
if ( V_1199 ) {
V_1279 -> V_1199 = V_1199 ;
memcpy ( ( void * ) V_1279 -> V_1198 ,
F_24 ( V_5 [ V_747 ] ) ,
V_1279 -> V_1199 ) ;
}
if ( V_5 [ V_1295 ] ) {
V_1279 -> V_50 = F_4 (
V_5 [ V_1295 ] ) ;
if ( ( V_1279 -> V_50 & V_1296 ) &&
! ( V_18 -> V_368 & V_1297 ) ) {
V_35 = - V_557 ;
goto V_1288;
}
if ( V_1279 -> V_50 & V_1298 ) {
V_22 V_1333 = V_1334 ;
if ( ! V_17 )
V_1333 = V_1335 ;
if ( ! ( V_18 -> V_368 & V_1333 ) ) {
V_35 = - V_557 ;
goto V_1288;
}
if ( V_17 && V_17 -> V_149 ) {
V_35 = - V_557 ;
goto V_1288;
}
V_35 = F_257 ( V_5 , V_1279 -> V_670 ,
V_1279 -> V_1276 ) ;
if ( V_35 )
goto V_1288;
}
}
if ( V_5 [ V_1336 ] )
V_1279 -> V_1337 =
F_4 ( V_5 [ V_1336 ] ) ;
V_35 = F_269 ( V_18 , V_1306 , V_1279 , V_5 ) ;
if ( V_35 )
goto V_1288;
V_1279 -> V_1303 = V_1304 ;
return V_1279 ;
V_1288:
F_42 ( V_1279 ) ;
return F_3 ( V_35 ) ;
}
static int F_272 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_1307 * V_1338 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_50 & V_338 ) ||
! V_7 -> V_328 -> V_339 )
return - V_557 ;
if ( V_7 -> V_1338 )
return - V_1096 ;
V_1338 = F_271 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_273 ( V_1338 ) ;
if ( V_35 )
goto V_951;
V_35 = F_274 ( V_7 , V_556 , V_1338 ) ;
if ( V_35 )
goto V_1288;
V_1338 -> V_556 = V_556 ;
V_1338 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_654 ] )
V_1338 -> V_655 = V_30 -> V_521 ;
F_275 ( V_7 -> V_1338 , V_1338 ) ;
F_276 ( V_7 , V_556 ,
V_1339 ) ;
return 0 ;
V_1288:
F_42 ( V_1338 ) ;
V_951:
return V_35 ;
}
static int F_277 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_50 & V_338 ) ||
! V_7 -> V_328 -> V_1340 )
return - V_557 ;
return F_278 ( V_7 , false ) ;
}
static int F_279 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_536 V_537 ;
enum V_1248 V_1213 ;
unsigned int V_1341 ;
int V_35 ;
V_1213 = F_280 ( V_17 -> V_18 ) ;
if ( V_1213 == V_1249 )
return - V_16 ;
V_35 = F_82 ( V_7 , V_30 , & V_537 ) ;
if ( V_35 )
return V_35 ;
if ( F_281 ( V_556 ) )
return - V_561 ;
if ( V_17 -> V_1342 )
return - V_561 ;
V_35 = F_282 ( V_17 -> V_18 , & V_537 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_283 ( V_17 -> V_18 , & V_537 ) )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1343 )
return - V_557 ;
V_1341 = F_284 ( & V_7 -> V_18 , & V_537 ) ;
if ( F_63 ( ! V_1341 ) )
V_1341 = V_1344 ;
V_35 = F_285 ( V_7 , V_556 , & V_537 , V_1341 ) ;
if ( ! V_35 ) {
V_17 -> V_537 = V_537 ;
V_17 -> V_1342 = true ;
V_17 -> V_1345 = V_1304 ;
V_17 -> V_1341 = V_1341 ;
}
return V_35 ;
}
static int F_286 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_1346 V_139 ;
static struct V_4 * V_1347 [ V_1348 + 1 ] ;
int V_35 ;
bool V_1349 = false ;
int V_46 , V_160 ;
V_22 V_1350 ;
if ( ! V_7 -> V_328 -> V_449 ||
! ( V_7 -> V_18 . V_50 & V_448 ) )
return - V_557 ;
switch ( V_556 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1349 = true ;
if ( ! V_17 -> V_558 )
return - V_1351 ;
break;
case V_146 :
if ( ! V_17 -> V_609 )
return - V_1351 ;
break;
case V_145 :
if ( ! V_17 -> V_1106 )
return - V_1351 ;
break;
default:
return - V_557 ;
}
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( ! V_30 -> V_5 [ V_539 ] ||
! V_30 -> V_5 [ V_1352 ] )
return - V_16 ;
if ( V_1349 && ! V_30 -> V_5 [ V_1353 ] )
return - V_16 ;
V_1350 = F_4 ( V_30 -> V_5 [ V_1352 ] ) ;
if ( V_1350 > 255 )
return - V_16 ;
V_139 . V_1354 = V_1350 ;
if ( ! V_1349 )
goto V_1355;
V_35 = F_161 ( V_30 -> V_5 , & V_139 . V_1356 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_34 ( V_1347 , V_1348 ,
V_30 -> V_5 [ V_1353 ] ,
V_41 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_161 ( V_1347 , & V_139 . V_1357 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1347 [ V_1358 ] )
return - V_16 ;
V_46 = F_25 ( V_1347 [ V_1358 ] ) ;
if ( ! V_46 || ( V_46 % sizeof( T_3 ) ) )
return - V_16 ;
V_139 . V_1359 = V_46 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_496 &&
( V_139 . V_1359 >
V_7 -> V_18 . V_496 ) )
return - V_16 ;
V_139 . V_1360 =
F_24 ( V_1347 [ V_1358 ] ) ;
for ( V_160 = 0 ; V_160 < V_139 . V_1359 ; V_160 ++ ) {
T_3 V_1361 = V_139 . V_1360 [ V_160 ] ;
if ( V_1361 >= V_139 . V_1357 . V_754 )
return - V_16 ;
if ( V_139 . V_1357 . V_753 [ V_1361 ] != V_139 . V_1354 )
return - V_16 ;
}
if ( V_1347 [ V_1362 ] ) {
V_46 = F_25 ( V_1347 [ V_1362 ] ) ;
if ( ! V_46 || ( V_46 % sizeof( T_3 ) ) )
return - V_16 ;
V_139 . V_1363 = V_46 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_496 &&
( V_139 . V_1363 >
V_7 -> V_18 . V_496 ) )
return - V_16 ;
V_139 . V_1364 =
F_24 ( V_1347 [ V_1362 ] ) ;
for ( V_160 = 0 ; V_160 < V_139 . V_1363 ; V_160 ++ ) {
T_3 V_1361 = V_139 . V_1364 [ V_160 ] ;
if ( V_1361 >= V_139 . V_1357 . V_763 )
return - V_16 ;
if ( V_139 . V_1357 . V_762 [ V_1361 ] !=
V_139 . V_1354 )
return - V_16 ;
}
}
V_1355:
V_35 = F_82 ( V_7 , V_30 , & V_139 . V_537 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_87 ( & V_7 -> V_18 , & V_139 . V_537 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_282 ( V_17 -> V_18 ,
& V_139 . V_537 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_139 . V_1365 = true ;
if ( V_30 -> V_5 [ V_1366 ] )
V_139 . V_1367 = true ;
F_114 ( V_17 ) ;
V_35 = F_287 ( V_7 , V_556 , & V_139 ) ;
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_288 ( struct V_31 * V_52 , struct V_33 * V_34 ,
V_22 V_49 , int V_50 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1368 * V_1369 )
{
struct V_1370 * V_430 = & V_1369 -> V_1371 ;
const struct V_1372 * V_1373 ;
void * V_360 ;
struct V_4 * V_1374 ;
F_44 ( V_17 ) ;
V_360 = F_26 ( V_52 , F_73 ( V_34 -> V_32 ) . V_48 , V_49 , V_50 ,
V_1375 ) ;
if ( ! V_360 )
return - 1 ;
F_245 ( V_34 , V_360 , & V_38 ) ;
if ( F_29 ( V_52 , V_370 , V_7 -> V_1376 ) )
goto V_60;
if ( V_17 -> V_19 &&
F_29 ( V_52 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_60;
if ( F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_60;
V_1374 = F_48 ( V_52 , V_1377 ) ;
if ( ! V_1374 )
goto V_60;
if ( ( ! F_289 ( V_430 -> V_563 ) &&
F_52 ( V_52 , V_1378 , V_604 , V_430 -> V_563 ) ) )
goto V_60;
F_241 () ;
if ( F_218 ( V_430 -> V_757 ) &&
F_30 ( V_52 , V_1379 ) )
goto V_1380;
V_1373 = F_242 ( V_430 -> V_1373 ) ;
if ( V_1373 ) {
if ( F_105 ( V_52 , V_1381 , V_1373 -> V_1382 ,
V_1383 ) )
goto V_1380;
if ( V_1373 -> V_46 && F_52 ( V_52 , V_1384 ,
V_1373 -> V_46 , V_1373 -> V_140 ) )
goto V_1380;
}
V_1373 = F_242 ( V_430 -> V_755 ) ;
if ( V_1373 && V_1373 -> V_1385 ) {
if ( F_105 ( V_52 , V_1386 , V_1373 -> V_1382 ,
V_1383 ) )
goto V_1380;
if ( V_1373 -> V_46 && F_52 ( V_52 , V_1387 ,
V_1373 -> V_46 , V_1373 -> V_140 ) )
goto V_1380;
}
F_243 () ;
if ( V_430 -> V_558 &&
F_56 ( V_52 , V_1388 , V_430 -> V_558 ) )
goto V_60;
if ( F_56 ( V_52 , V_1389 , V_430 -> V_1013 ) ||
F_29 ( V_52 , V_1390 , V_430 -> V_1391 -> V_59 ) ||
F_29 ( V_52 , V_1392 , V_430 -> V_1393 ) ||
F_29 ( V_52 , V_1394 ,
F_290 ( V_1304 - V_1369 -> V_1395 ) ) )
goto V_60;
if ( V_1369 -> V_1396 &&
( F_105 ( V_52 , V_1397 ,
V_1369 -> V_1396 , V_1383 ) ||
F_52 ( V_52 , V_1398 , V_604 ,
V_1369 -> V_1399 ) ) )
goto V_60;
if ( V_1369 -> V_1400 &&
F_105 ( V_52 , V_1401 ,
V_1369 -> V_1400 , V_1383 ) )
goto V_60;
switch ( V_7 -> V_18 . V_884 ) {
case V_885 :
if ( F_29 ( V_52 , V_1402 , V_430 -> signal ) )
goto V_60;
break;
case V_1403 :
if ( F_57 ( V_52 , V_1404 , V_430 -> signal ) )
goto V_60;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1369 == V_17 -> V_149 &&
F_29 ( V_52 , V_1405 ,
V_1406 ) )
goto V_60;
break;
case V_146 :
if ( V_1369 == V_17 -> V_149 &&
F_29 ( V_52 , V_1405 ,
V_1407 ) )
goto V_60;
break;
default:
break;
}
F_49 ( V_52 , V_1374 ) ;
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_1380:
F_243 () ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int F_291 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1368 * V_1281 ;
struct V_1 * V_17 ;
int V_516 = V_34 -> args [ 2 ] , V_104 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_114 ( V_17 ) ;
F_292 ( & V_7 -> V_1408 ) ;
F_293 ( V_7 ) ;
V_34 -> V_49 = V_7 -> V_1376 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_104 <= V_516 )
continue;
if ( F_288 ( V_32 , V_34 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_7 , V_17 , V_1281 ) < 0 ) {
V_104 -- ;
break;
}
}
F_294 ( & V_7 -> V_1408 ) ;
F_116 ( V_17 ) ;
V_34 -> args [ 2 ] = V_104 ;
F_22 ( V_7 ) ;
return V_32 -> V_46 ;
}
static int F_295 ( struct V_31 * V_52 , V_22 V_48 , V_22 V_49 ,
int V_50 , struct V_25 * V_556 ,
bool V_1409 ,
struct V_1410 * V_1411 )
{
void * V_360 ;
struct V_4 * V_1412 ;
if ( ! V_1411 -> V_1391 && ! V_1409 )
return 0 ;
V_360 = F_26 ( V_52 , V_48 , V_49 , V_50 ,
V_1413 ) ;
if ( ! V_360 )
return - V_136 ;
if ( F_29 ( V_52 , V_10 , V_556 -> V_20 ) )
goto V_60;
V_1412 = F_48 ( V_52 , V_1414 ) ;
if ( ! V_1412 )
goto V_60;
if ( V_1411 -> V_1391 &&
F_29 ( V_52 , V_1415 ,
V_1411 -> V_1391 -> V_59 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1416 ) &&
F_57 ( V_52 , V_1417 , V_1411 -> V_1418 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1419 ) &&
F_30 ( V_52 , V_1420 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1421 ) &&
F_105 ( V_52 , V_1422 ,
V_1411 -> time , V_1423 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1424 ) &&
F_105 ( V_52 , V_1425 ,
V_1411 -> V_1426 , V_1423 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1427 ) &&
F_105 ( V_52 , V_1428 ,
V_1411 -> V_1429 , V_1423 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1430 ) &&
F_105 ( V_52 , V_1431 ,
V_1411 -> V_1432 , V_1423 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1433 ) &&
F_105 ( V_52 , V_1434 ,
V_1411 -> V_1435 , V_1423 ) )
goto V_60;
if ( ( V_1411 -> V_867 & V_1436 ) &&
F_105 ( V_52 , V_1437 ,
V_1411 -> V_1438 , V_1423 ) )
goto V_60;
F_49 ( V_52 , V_1412 ) ;
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int F_296 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_4 * * V_1439 = F_16 ( & V_38 ) ;
struct V_1410 V_1411 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1440 = V_34 -> args [ 2 ] ;
int V_430 ;
bool V_1441 ;
V_430 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_430 )
return V_430 ;
V_1441 = V_1439 [ V_1442 ] ;
if ( ! V_17 -> V_19 ) {
V_430 = - V_16 ;
goto V_951;
}
if ( ! V_7 -> V_328 -> V_1443 ) {
V_430 = - V_557 ;
goto V_951;
}
while ( 1 ) {
V_430 = F_297 ( V_7 , V_17 -> V_19 , V_1440 , & V_1411 ) ;
if ( V_430 == - V_676 )
break;
if ( V_430 )
goto V_951;
if ( V_1411 . V_1391 &&
V_1411 . V_1391 -> V_50 & V_61 ) {
V_1440 ++ ;
continue;
}
if ( F_295 ( V_32 ,
F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_17 -> V_19 , V_1441 , & V_1411 ) < 0 )
goto V_616;
V_1440 ++ ;
}
V_616:
V_34 -> args [ 2 ] = V_1440 ;
V_430 = V_32 -> V_46 ;
V_951:
F_22 ( V_7 ) ;
return V_430 ;
}
static bool F_298 ( V_22 V_1444 )
{
return ! ( V_1444 & ~ ( V_1445 |
V_1446 ) ) ;
}
static int F_299 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_53 * V_54 ;
const T_2 * V_563 , * V_611 , * V_1198 = NULL , * V_1447 = NULL ;
int V_35 , V_609 , V_1199 = 0 , V_1448 = 0 ;
enum V_765 V_766 ;
struct V_92 V_91 ;
bool V_1449 ;
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_788 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_610 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_539 ] )
return - V_16 ;
V_35 = F_37 ( V_30 , & V_91 ) ;
if ( V_35 )
return V_35 ;
if ( V_91 . V_104 >= 0 ) {
if ( V_91 . type != - 1 && V_91 . type != V_673 )
return - V_16 ;
if ( ! V_91 . V_106 . V_91 || ! V_91 . V_106 . V_107 )
return - V_16 ;
if ( ( V_91 . V_106 . V_111 != V_137 ||
V_91 . V_106 . V_107 != V_1450 ) &&
( V_91 . V_106 . V_111 != V_138 ||
V_91 . V_106 . V_107 != V_1451 ) )
return - V_16 ;
if ( V_91 . V_104 > 3 )
return - V_16 ;
} else {
V_91 . V_106 . V_107 = 0 ;
V_91 . V_106 . V_91 = NULL ;
}
if ( V_91 . V_104 >= 0 ) {
int V_160 ;
bool V_1452 = false ;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_414 ; V_160 ++ ) {
if ( V_91 . V_106 . V_111 == V_7 -> V_18 . V_415 [ V_160 ] ) {
V_1452 = true ;
break;
}
}
if ( ! V_1452 )
return - V_16 ;
}
if ( ! V_7 -> V_328 -> V_299 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_54 = F_45 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_539 ] ) ;
if ( ! V_54 )
return - V_16 ;
V_611 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_609 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
if ( V_30 -> V_5 [ V_747 ] ) {
V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
}
V_766 = F_4 ( V_30 -> V_5 [ V_788 ] ) ;
if ( ! F_163 ( V_7 , V_766 , V_768 ) )
return - V_16 ;
if ( ( V_766 == V_770 ||
V_766 == V_772 ||
V_766 == V_773 ||
V_766 == V_774 ) &&
! V_30 -> V_5 [ V_1453 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1453 ] ) {
if ( V_766 != V_770 &&
V_766 != V_772 &&
V_766 != V_773 &&
V_766 != V_774 )
return - V_16 ;
V_1447 = F_24 ( V_30 -> V_5 [ V_1453 ] ) ;
V_1448 = F_25 ( V_30 -> V_5 [ V_1453 ] ) ;
if ( V_1448 < 4 )
return - V_16 ;
}
V_1449 = ! ! V_30 -> V_5 [ V_1454 ] ;
if ( V_1449 )
return 0 ;
F_114 ( V_556 -> V_28 ) ;
V_35 = F_300 ( V_7 , V_556 , V_54 , V_766 , V_563 ,
V_611 , V_609 , V_1198 , V_1199 ,
V_91 . V_106 . V_91 , V_91 . V_106 . V_107 , V_91 . V_104 ,
V_1447 , V_1448 ) ;
F_116 ( V_556 -> V_28 ) ;
return V_35 ;
}
static int F_166 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1455 * V_1456 ,
int V_1457 )
{
memset ( V_1456 , 0 , sizeof( * V_1456 ) ) ;
V_1456 -> V_1458 = V_30 -> V_5 [ V_1459 ] ;
if ( V_30 -> V_5 [ V_419 ] ) {
T_3 V_1460 ;
V_1460 = F_80 (
V_30 -> V_5 [ V_419 ] ) ;
V_1456 -> V_1461 = F_301 ( V_1460 ) ;
if ( ! ( V_7 -> V_18 . V_50 & V_418 ) &&
V_1460 != V_1462 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1463 ] )
V_1456 -> V_1464 = true ;
} else
V_1456 -> V_1461 = F_301 ( V_1462 ) ;
if ( V_30 -> V_5 [ V_1465 ] ) {
void * V_140 ;
int V_46 , V_160 ;
V_140 = F_24 ( V_30 -> V_5 [ V_1465 ] ) ;
V_46 = F_25 ( V_30 -> V_5 [ V_1465 ] ) ;
V_1456 -> V_1466 = V_46 / sizeof( V_22 ) ;
if ( V_46 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1456 -> V_1466 > V_1457 )
return - V_16 ;
memcpy ( V_1456 -> V_1467 , V_140 , V_46 ) ;
for ( V_160 = 0 ; V_160 < V_1456 -> V_1466 ; V_160 ++ )
if ( ! F_302 (
& V_7 -> V_18 ,
V_1456 -> V_1467 [ V_160 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1468 ] ) {
V_1456 -> V_1469 =
F_4 ( V_30 -> V_5 [ V_1468 ] ) ;
if ( ! F_302 ( & V_7 -> V_18 ,
V_1456 -> V_1469 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1470 ] ) {
V_1456 -> V_1444 =
F_4 ( V_30 -> V_5 [ V_1470 ] ) ;
if ( ! F_298 ( V_1456 -> V_1444 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1471 ] ) {
void * V_140 ;
int V_46 ;
V_140 = F_24 ( V_30 -> V_5 [ V_1471 ] ) ;
V_46 = F_25 ( V_30 -> V_5 [ V_1471 ] ) ;
V_1456 -> V_1472 = V_46 / sizeof( V_22 ) ;
if ( V_46 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1456 -> V_1472 > V_1473 )
return - V_16 ;
memcpy ( V_1456 -> V_1474 , V_140 , V_46 ) ;
}
return 0 ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_53 * V_54 ;
struct V_1475 V_1476 = {} ;
const T_2 * V_563 , * V_611 ;
int V_35 , V_609 = 0 ;
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_564 ] ||
! V_30 -> V_5 [ V_610 ] ||
! V_30 -> V_5 [ V_539 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_301 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_54 = F_45 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_539 ] ) ;
if ( ! V_54 )
return - V_16 ;
V_611 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_609 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
if ( V_30 -> V_5 [ V_747 ] ) {
V_1476 . V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_1476 . V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
}
if ( V_30 -> V_5 [ V_1477 ] ) {
enum V_1478 V_1479 =
F_4 ( V_30 -> V_5 [ V_1477 ] ) ;
if ( V_1479 == V_1480 )
V_1476 . V_1481 = true ;
else if ( V_1479 != V_1482 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1483 ] )
V_1476 . V_1484 = F_24 ( V_30 -> V_5 [ V_1483 ] ) ;
if ( F_167 ( V_30 -> V_5 [ V_1485 ] ) )
V_1476 . V_50 |= V_1486 ;
if ( V_30 -> V_5 [ V_472 ] )
memcpy ( & V_1476 . V_1487 ,
F_24 ( V_30 -> V_5 [ V_472 ] ) ,
sizeof( V_1476 . V_1487 ) ) ;
if ( V_30 -> V_5 [ V_1003 ] ) {
if ( ! V_30 -> V_5 [ V_472 ] )
return - V_16 ;
memcpy ( & V_1476 . V_973 ,
F_24 ( V_30 -> V_5 [ V_1003 ] ) ,
sizeof( V_1476 . V_973 ) ) ;
}
if ( F_167 ( V_30 -> V_5 [ V_1488 ] ) )
V_1476 . V_50 |= V_1489 ;
if ( V_30 -> V_5 [ V_481 ] )
memcpy ( & V_1476 . V_1490 ,
F_24 ( V_30 -> V_5 [ V_481 ] ) ,
sizeof( V_1476 . V_1490 ) ) ;
if ( V_30 -> V_5 [ V_1004 ] ) {
if ( ! V_30 -> V_5 [ V_481 ] )
return - V_16 ;
memcpy ( & V_1476 . V_974 ,
F_24 ( V_30 -> V_5 [ V_1004 ] ) ,
sizeof( V_1476 . V_974 ) ) ;
}
if ( F_167 ( V_30 -> V_5 [ V_1491 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_368 &
V_1492 ) &&
( V_7 -> V_18 . V_368 & V_1493 ) ) &&
! F_117 ( & V_7 -> V_18 ,
V_1494 ) )
return - V_16 ;
V_1476 . V_50 |= V_1495 ;
}
if ( V_30 -> V_5 [ V_1496 ] ) {
V_1476 . V_1497 = F_24 ( V_30 -> V_5 [ V_1496 ] ) ;
V_1476 . V_1498 = F_25 ( V_30 -> V_5 [ V_1496 ] ) ;
if ( ! V_30 -> V_5 [ V_1499 ] )
return - V_16 ;
V_1476 . V_1500 =
F_24 ( V_30 -> V_5 [ V_1499 ] ) ;
}
V_35 = F_166 ( V_7 , V_30 , & V_1476 . V_790 , 1 ) ;
if ( ! V_35 ) {
F_114 ( V_556 -> V_28 ) ;
V_35 = F_304 ( V_7 , V_556 , V_54 , V_563 ,
V_611 , V_609 , & V_1476 ) ;
F_116 ( V_556 -> V_28 ) ;
}
return V_35 ;
}
static int F_305 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
const T_2 * V_1198 = NULL , * V_563 ;
int V_1199 = 0 , V_35 ;
T_3 V_1040 ;
bool V_1449 ;
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1039 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_303 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_1040 = F_80 ( V_30 -> V_5 [ V_1039 ] ) ;
if ( V_1040 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_747 ] ) {
V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
}
V_1449 = ! ! V_30 -> V_5 [ V_1454 ] ;
F_114 ( V_556 -> V_28 ) ;
V_35 = F_306 ( V_7 , V_556 , V_563 , V_1198 , V_1199 , V_1040 ,
V_1449 ) ;
F_116 ( V_556 -> V_28 ) ;
return V_35 ;
}
static int F_307 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
const T_2 * V_1198 = NULL , * V_563 ;
int V_1199 = 0 , V_35 ;
T_3 V_1040 ;
bool V_1449 ;
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1039 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_305 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_1040 = F_80 ( V_30 -> V_5 [ V_1039 ] ) ;
if ( V_1040 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_747 ] ) {
V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
}
V_1449 = ! ! V_30 -> V_5 [ V_1454 ] ;
F_114 ( V_556 -> V_28 ) ;
V_35 = F_308 ( V_7 , V_556 , V_563 , V_1198 , V_1199 , V_1040 ,
V_1449 ) ;
F_116 ( V_556 -> V_28 ) ;
return V_35 ;
}
static bool
F_309 ( struct V_6 * V_7 ,
int V_1501 [ V_437 ] ,
int V_1502 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_367 , V_160 ;
for ( V_367 = 0 ; V_367 < V_437 ; V_367 ++ ) {
struct V_242 * V_243 ;
V_243 = V_18 -> V_438 [ V_367 ] ;
if ( ! V_243 )
continue;
for ( V_160 = 0 ; V_160 < V_243 -> V_264 ; V_160 ++ ) {
if ( V_243 -> V_265 [ V_160 ] . V_267 == V_1502 ) {
V_1501 [ V_367 ] = V_160 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_310 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1503 V_1504 ;
struct V_18 * V_18 ;
struct V_129 * V_1505 = NULL ;
int V_35 ;
memset ( & V_1504 , 0 , sizeof( V_1504 ) ) ;
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_610 ] ||
! F_25 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
V_1504 . V_558 = 100 ;
if ( V_30 -> V_5 [ V_777 ] )
V_1504 . V_558 =
F_4 ( V_30 -> V_5 [ V_777 ] ) ;
V_35 = F_165 ( V_7 , V_146 ,
V_1504 . V_558 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_328 -> V_307 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_146 )
return - V_557 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_564 ] ) {
V_1504 . V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( ! F_123 ( V_1504 . V_563 ) )
return - V_16 ;
}
V_1504 . V_611 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_1504 . V_609 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
if ( V_30 -> V_5 [ V_747 ] ) {
V_1504 . V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_1504 . V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
}
V_35 = F_82 ( V_7 , V_30 , & V_1504 . V_537 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_311 ( & V_7 -> V_18 , & V_1504 . V_537 ,
V_146 ) )
return - V_16 ;
switch ( V_1504 . V_537 . V_540 ) {
case V_554 :
case V_555 :
case V_541 :
break;
case V_596 :
case V_597 :
if ( ! ( V_7 -> V_18 . V_368 & V_1506 ) )
return - V_16 ;
break;
case V_1507 :
case V_1508 :
case V_1509 :
if ( ! ( V_7 -> V_18 . V_368 & V_1506 ) )
return - V_16 ;
if ( ! F_117 ( & V_7 -> V_18 ,
V_1510 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1504 . V_1511 = ! ! V_30 -> V_5 [ V_1512 ] ;
V_1504 . V_786 = ! ! V_30 -> V_5 [ V_787 ] ;
if ( V_30 -> V_5 [ V_1087 ] ) {
T_2 * V_700 =
F_24 ( V_30 -> V_5 [ V_1087 ] ) ;
int V_1513 =
F_25 ( V_30 -> V_5 [ V_1087 ] ) ;
struct V_242 * V_243 =
V_18 -> V_438 [ V_1504 . V_537 . V_54 -> V_367 ] ;
V_35 = F_262 ( V_243 , V_700 , V_1513 ,
& V_1504 . V_1088 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_472 ] )
memcpy ( & V_1504 . V_1487 ,
F_24 ( V_30 -> V_5 [ V_472 ] ) ,
sizeof( V_1504 . V_1487 ) ) ;
if ( V_30 -> V_5 [ V_1003 ] ) {
if ( ! V_30 -> V_5 [ V_472 ] )
return - V_16 ;
memcpy ( & V_1504 . V_973 ,
F_24 ( V_30 -> V_5 [ V_1003 ] ) ,
sizeof( V_1504 . V_973 ) ) ;
}
if ( V_30 -> V_5 [ V_1514 ] &&
! F_309 ( V_7 , V_1504 . V_1501 ,
F_4 ( V_30 -> V_5 [ V_1514 ] ) ) )
return - V_16 ;
if ( V_1504 . V_786 && V_30 -> V_5 [ V_1515 ] ) {
bool V_131 = false ;
V_1505 = F_38 ( V_7 ,
V_30 -> V_5 [ V_1515 ] ,
& V_131 ) ;
if ( F_18 ( V_1505 ) )
return F_19 ( V_1505 ) ;
if ( ( V_1504 . V_537 . V_540 != V_541 ) &&
V_131 ) {
F_312 ( V_1505 ) ;
return - V_16 ;
}
}
V_1504 . V_1458 =
F_167 ( V_30 -> V_5 [ V_1459 ] ) ;
V_1504 . V_1516 =
F_167 ( V_30 -> V_5 [ V_1517 ] ) ;
V_35 = F_313 ( V_7 , V_556 , & V_1504 , V_1505 ) ;
if ( V_35 )
F_312 ( V_1505 ) ;
return V_35 ;
}
static int F_314 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_1518 )
return - V_557 ;
if ( V_556 -> V_28 -> V_141 != V_146 )
return - V_557 ;
return F_315 ( V_7 , V_556 , false ) ;
}
static int F_316 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
int V_1501 [ V_437 ] ;
V_22 V_1519 ;
int V_35 ;
if ( V_556 -> V_28 -> V_141 != V_146 &&
V_556 -> V_28 -> V_141 != V_145 &&
V_556 -> V_28 -> V_141 != V_152 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_349 )
return - V_557 ;
memset ( V_1501 , 0 , sizeof( V_1501 ) ) ;
if ( ! V_30 -> V_5 [ V_1514 ] )
return - V_16 ;
V_1519 = F_4 ( V_30 -> V_5 [ V_1514 ] ) ;
if ( ! F_309 ( V_7 , V_1501 , V_1519 ) )
return - V_16 ;
V_35 = F_317 ( V_7 , V_556 , V_1501 ) ;
return V_35 ;
}
static struct V_31 *
F_318 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1520 ,
V_22 V_48 , V_22 V_49 , enum V_357 V_51 ,
enum V_832 V_44 ,
const struct V_488 * V_30 ,
T_10 V_1521 )
{
struct V_31 * V_32 ;
void * V_360 ;
struct V_4 * V_140 ;
V_32 = F_76 ( V_1520 + 100 , V_1521 ) ;
if ( ! V_32 )
return NULL ;
V_360 = F_26 ( V_32 , V_48 , V_49 , 0 , V_51 ) ;
if ( ! V_360 ) {
F_319 ( V_32 ) ;
return NULL ;
}
if ( F_29 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_60;
if ( V_30 ) {
if ( F_29 ( V_32 , V_1522 ,
V_30 -> V_1523 ) )
goto V_60;
if ( F_29 ( V_32 , V_1524 ,
V_30 -> V_1525 ) )
goto V_60;
}
if ( V_17 ) {
if ( F_105 ( V_32 , V_12 ,
V_13 ( V_17 ) , V_603 ) )
goto V_60;
if ( V_17 -> V_19 &&
F_29 ( V_32 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_60;
}
V_140 = F_48 ( V_32 , V_44 ) ;
if ( ! V_140 )
goto V_60;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_360 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_140 ;
return V_32 ;
V_60:
F_319 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_320 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_357 V_51 ,
enum V_832 V_44 ,
int V_1526 ,
int V_1520 , T_10 V_1521 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_488 * V_30 ;
switch ( V_51 ) {
case V_1527 :
if ( F_63 ( V_1526 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1528 :
if ( F_63 ( V_1526 < 0 ||
V_1526 >= V_18 -> V_492 ) )
return NULL ;
V_30 = & V_18 -> V_494 [ V_1526 ] ;
break;
default:
F_63 ( 1 ) ;
return NULL ;
}
return F_318 ( V_7 , V_17 , V_1520 , 0 , 0 ,
V_51 , V_44 , V_30 , V_1521 ) ;
}
void F_321 ( struct V_31 * V_32 , T_10 V_1521 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_360 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_140 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1529 V_1530 = V_1531 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_49 ( V_32 , V_140 ) ;
F_68 ( V_32 , V_360 ) ;
if ( V_140 -> F_156 == V_490 )
V_1530 = V_1532 ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1530 , V_1521 ) ;
}
static int F_323 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_96 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_351 )
return - V_557 ;
if ( F_18 ( V_17 ) ) {
V_35 = F_19 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1533 ] )
return - V_16 ;
V_7 -> V_1534 = V_30 ;
V_35 = F_324 ( V_7 , V_17 ,
F_24 ( V_30 -> V_5 [ V_1533 ] ) ,
F_25 ( V_30 -> V_5 [ V_1533 ] ) ) ;
V_7 -> V_1534 = NULL ;
return V_35 ;
}
static int F_325 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1535 ;
void * V_140 = NULL ;
int V_1536 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1535 = V_34 -> args [ 0 ] - 1 ;
} else {
struct V_4 * * V_1439 = F_16 ( & V_38 ) ;
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_1439 , V_38 . V_40 , V_41 ) ;
if ( V_35 )
goto V_951;
V_7 = F_8 ( F_17 ( V_32 -> V_43 ) , V_1439 ) ;
if ( F_18 ( V_7 ) ) {
V_35 = F_19 ( V_7 ) ;
goto V_951;
}
V_1535 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_1439 [ V_1533 ] )
V_34 -> args [ 1 ] = ( long ) V_1439 [ V_1533 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_140 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1536 = F_25 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1535 ) ;
if ( ! V_7 ) {
V_35 = - V_676 ;
goto V_951;
}
if ( ! V_7 -> V_328 -> V_1537 ) {
V_35 = - V_557 ;
goto V_951;
}
while ( 1 ) {
void * V_360 = F_26 ( V_32 , F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_1527 ) ;
struct V_4 * V_1538 ;
if ( ! V_360 )
break;
if ( F_29 ( V_32 , V_26 , V_1535 ) ) {
F_69 ( V_32 , V_360 ) ;
break;
}
V_1538 = F_48 ( V_32 , V_1533 ) ;
if ( ! V_1538 ) {
F_69 ( V_32 , V_360 ) ;
break;
}
V_35 = F_326 ( V_7 , V_32 , V_34 , V_140 , V_1536 ) ;
F_49 ( V_32 , V_1538 ) ;
if ( V_35 == - V_90 || V_35 == - V_676 ) {
F_69 ( V_32 , V_360 ) ;
break;
} else if ( V_35 ) {
F_69 ( V_32 , V_360 ) ;
goto V_951;
}
F_68 ( V_32 , V_360 ) ;
}
V_35 = V_32 -> V_46 ;
V_34 -> args [ 0 ] = V_1535 + 1 ;
V_951:
F_21 () ;
return V_35 ;
}
static int F_327 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1539 V_353 ;
struct V_18 * V_18 ;
struct V_129 * V_1505 = NULL ;
int V_35 ;
memset ( & V_353 , 0 , sizeof( V_353 ) ) ;
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_610 ] ||
! F_25 ( V_30 -> V_5 [ V_610 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_788 ] ) {
V_353 . V_766 =
F_4 ( V_30 -> V_5 [ V_788 ] ) ;
if ( ! F_163 ( V_7 , V_353 . V_766 ,
V_354 ) )
return - V_16 ;
} else
V_353 . V_766 = V_789 ;
V_353 . V_786 = V_30 -> V_5 [ V_787 ] ;
V_35 = F_166 ( V_7 , V_30 , & V_353 . V_790 ,
V_791 ) ;
if ( V_35 )
return V_35 ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
V_18 = & V_7 -> V_18 ;
V_353 . V_1540 = - 1 ;
if ( V_30 -> V_5 [ V_1541 ] &&
( V_18 -> V_50 & V_407 ) ) {
V_353 . V_1540 =
F_80 ( V_30 -> V_5 [ V_1541 ] ) ;
}
if ( V_30 -> V_5 [ V_564 ] )
V_353 . V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
else if ( V_30 -> V_5 [ V_1542 ] )
V_353 . V_1543 =
F_24 ( V_30 -> V_5 [ V_1542 ] ) ;
V_353 . V_611 = F_24 ( V_30 -> V_5 [ V_610 ] ) ;
V_353 . V_609 = F_25 ( V_30 -> V_5 [ V_610 ] ) ;
if ( V_30 -> V_5 [ V_747 ] ) {
V_353 . V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_353 . V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
}
if ( V_30 -> V_5 [ V_1477 ] ) {
V_353 . V_1479 = F_4 ( V_30 -> V_5 [ V_1477 ] ) ;
if ( V_353 . V_1479 != V_1480 &&
V_353 . V_1479 != V_1482 )
return - V_16 ;
} else {
V_353 . V_1479 = V_1482 ;
}
if ( V_30 -> V_5 [ V_1483 ] )
V_353 . V_1484 =
F_24 ( V_30 -> V_5 [ V_1483 ] ) ;
if ( V_30 -> V_5 [ V_539 ] ) {
V_353 . V_1391 = F_45 (
V_18 , V_30 -> V_5 [ V_539 ] ) ;
if ( ! V_353 . V_1391 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1544 ] ) {
V_353 . V_1545 = F_45 (
V_18 , V_30 -> V_5 [ V_1544 ] ) ;
if ( ! V_353 . V_1545 )
return - V_16 ;
}
if ( V_353 . V_786 && V_30 -> V_5 [ V_1515 ] ) {
V_1505 = F_38 ( V_7 ,
V_30 -> V_5 [ V_1515 ] , NULL ) ;
if ( F_18 ( V_1505 ) )
return F_19 ( V_1505 ) ;
}
if ( F_167 ( V_30 -> V_5 [ V_1485 ] ) )
V_353 . V_50 |= V_1486 ;
if ( V_30 -> V_5 [ V_472 ] )
memcpy ( & V_353 . V_1487 ,
F_24 ( V_30 -> V_5 [ V_472 ] ) ,
sizeof( V_353 . V_1487 ) ) ;
if ( V_30 -> V_5 [ V_1003 ] ) {
if ( ! V_30 -> V_5 [ V_472 ] ) {
F_312 ( V_1505 ) ;
return - V_16 ;
}
memcpy ( & V_353 . V_973 ,
F_24 ( V_30 -> V_5 [ V_1003 ] ) ,
sizeof( V_353 . V_973 ) ) ;
}
if ( F_167 ( V_30 -> V_5 [ V_1488 ] ) )
V_353 . V_50 |= V_1489 ;
if ( V_30 -> V_5 [ V_481 ] )
memcpy ( & V_353 . V_1490 ,
F_24 ( V_30 -> V_5 [ V_481 ] ) ,
sizeof( V_353 . V_1490 ) ) ;
if ( V_30 -> V_5 [ V_1004 ] ) {
if ( ! V_30 -> V_5 [ V_481 ] ) {
F_312 ( V_1505 ) ;
return - V_16 ;
}
memcpy ( & V_353 . V_974 ,
F_24 ( V_30 -> V_5 [ V_1004 ] ) ,
sizeof( V_353 . V_974 ) ) ;
}
if ( F_167 ( V_30 -> V_5 [ V_1491 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_368 &
V_1492 ) &&
( V_7 -> V_18 . V_368 & V_1493 ) ) &&
! F_117 ( & V_7 -> V_18 ,
V_1494 ) ) {
F_312 ( V_1505 ) ;
return - V_16 ;
}
V_353 . V_50 |= V_1495 ;
}
V_353 . V_808 = F_167 ( V_30 -> V_5 [ V_809 ] ) ;
if ( V_353 . V_808 && ! V_7 -> V_18 . V_438 [ V_810 ] ) {
F_312 ( V_1505 ) ;
return - V_557 ;
}
if ( V_30 -> V_5 [ V_503 ] ) {
if ( V_353 . V_563 ) {
F_312 ( V_1505 ) ;
return - V_16 ;
}
V_35 = F_255 ( V_30 -> V_5 [ V_503 ] ,
V_18 , & V_353 . V_1262 ) ;
if ( V_35 ) {
F_312 ( V_1505 ) ;
return V_35 ;
}
}
F_114 ( V_556 -> V_28 ) ;
V_35 = F_328 ( V_7 , V_556 , & V_353 , V_1505 ,
V_353 . V_1484 ) ;
F_116 ( V_556 -> V_28 ) ;
if ( V_35 )
F_312 ( V_1505 ) ;
return V_35 ;
}
static int F_329 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1539 V_353 = {} ;
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
V_22 V_567 = 0 ;
int V_513 ;
if ( ! V_7 -> V_328 -> V_458 )
return - V_557 ;
if ( V_30 -> V_5 [ V_747 ] ) {
if ( ! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
V_353 . V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_353 . V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
V_567 |= V_1546 ;
}
F_114 ( V_556 -> V_28 ) ;
if ( ! V_17 -> V_149 )
V_513 = - V_150 ;
else
V_513 = F_330 ( V_7 , V_556 , & V_353 , V_567 ) ;
F_116 ( V_556 -> V_28 ) ;
return V_513 ;
}
static int F_331 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_3 V_1547 ;
int V_513 ;
if ( ! V_30 -> V_5 [ V_1039 ] )
V_1547 = V_1548 ;
else
V_1547 = F_80 ( V_30 -> V_5 [ V_1039 ] ) ;
if ( V_1547 == 0 )
return - V_16 ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
F_114 ( V_556 -> V_28 ) ;
V_513 = F_332 ( V_7 , V_556 , V_1547 , true ) ;
F_116 ( V_556 -> V_28 ) ;
return V_513 ;
}
static int F_333 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1549 ] ) {
V_22 V_1550 = F_4 ( V_30 -> V_5 [ V_1549 ] ) ;
V_2 = F_334 ( V_1550 ) ;
} else if ( V_30 -> V_5 [ V_1551 ] ) {
V_22 V_1552 = F_4 ( V_30 -> V_5 [ V_1551 ] ) ;
V_2 = F_335 ( V_1552 ) ;
} else {
return - V_16 ;
}
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_72 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_336 ( V_7 , V_2 ) ;
F_337 ( V_2 ) ;
return V_35 ;
}
static int F_338 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
int (* F_339)( struct V_18 * V_18 , struct V_25 * V_556 ,
struct V_1553 * V_1554 ) = NULL ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1553 V_1554 ;
memset ( & V_1554 , 0 , sizeof( struct V_1553 ) ) ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1555 ] )
return - V_16 ;
V_1554 . V_1556 = F_24 ( V_30 -> V_5 [ V_1555 ] ) ;
V_1554 . V_563 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
switch ( V_30 -> V_1557 -> V_51 ) {
case V_1558 :
F_339 = V_7 -> V_328 -> V_311 ;
break;
case V_1559 :
F_339 = V_7 -> V_328 -> V_313 ;
break;
default:
F_63 ( 1 ) ;
break;
}
if ( ! F_339 )
return - V_557 ;
return F_339 ( & V_7 -> V_18 , V_556 , & V_1554 ) ;
}
static int F_340 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
if ( V_556 -> V_28 -> V_141 != V_147 &&
V_556 -> V_28 -> V_141 != V_148 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_315 )
return - V_557 ;
return F_341 ( V_7 , V_556 ) ;
}
static int F_342 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 V_1560 , V_1561 ;
V_22 V_1562 = 0 ;
T_3 V_1563 ;
T_2 * V_1564 ;
bool V_1565 ;
if ( ! ( V_7 -> V_18 . V_50 & V_333 ) ||
! V_7 -> V_328 -> V_334 )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_1566 ] ||
! V_30 -> V_5 [ V_1567 ] ||
! V_30 -> V_5 [ V_1568 ] ||
! V_30 -> V_5 [ V_747 ] ||
! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_1564 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_1560 = F_35 ( V_30 -> V_5 [ V_1566 ] ) ;
V_1563 = F_80 ( V_30 -> V_5 [ V_1567 ] ) ;
V_1561 = F_35 ( V_30 -> V_5 [ V_1568 ] ) ;
V_1565 = F_167 ( V_30 -> V_5 [ V_1569 ] ) ;
if ( V_30 -> V_5 [ V_1570 ] )
V_1562 =
F_4 ( V_30 -> V_5 [ V_1570 ] ) ;
return F_343 ( V_7 , V_556 , V_1564 , V_1560 ,
V_1561 , V_1563 , V_1562 ,
V_1565 ,
F_24 ( V_30 -> V_5 [ V_747 ] ) ,
F_25 ( V_30 -> V_5 [ V_747 ] ) ) ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
enum V_1571 V_1572 ;
T_2 * V_1564 ;
if ( ! ( V_7 -> V_18 . V_50 & V_333 ) ||
! V_7 -> V_328 -> V_336 )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_1573 ] ||
! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_1572 = F_35 ( V_30 -> V_5 [ V_1573 ] ) ;
V_1564 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
return F_345 ( V_7 , V_556 , V_1564 , V_1572 ) ;
}
static int F_346 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
struct V_536 V_537 ;
struct V_31 * V_52 ;
void * V_360 ;
T_1 V_668 ;
V_22 V_1292 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_539 ] ||
! V_30 -> V_5 [ V_1574 ] )
return - V_16 ;
V_1292 = F_4 ( V_30 -> V_5 [ V_1574 ] ) ;
if ( ! V_7 -> V_328 -> V_318 ||
! ( V_7 -> V_18 . V_50 & V_317 ) )
return - V_557 ;
if ( V_1292 < V_1575 ||
V_1292 > V_7 -> V_18 . V_461 )
return - V_16 ;
V_35 = F_82 ( V_7 , V_30 , & V_537 ) ;
if ( V_35 )
return V_35 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1576 ) ;
if ( ! V_360 ) {
V_35 = - V_90 ;
goto V_678;
}
V_35 = F_347 ( V_7 , V_17 , V_537 . V_54 ,
V_1292 , & V_668 ) ;
if ( V_35 )
goto V_678;
if ( F_105 ( V_52 , V_1577 , V_668 ,
V_603 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
V_35 = - V_90 ;
V_678:
F_77 ( V_52 ) ;
return V_35 ;
}
static int F_348 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
T_1 V_668 ;
if ( ! V_30 -> V_5 [ V_1577 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1578 )
return - V_557 ;
V_668 = F_5 ( V_30 -> V_5 [ V_1577 ] ) ;
return F_349 ( V_7 , V_17 , V_668 ) ;
}
static int F_350 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_721 V_702 ;
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_320 )
return - V_557 ;
V_35 = F_155 ( V_30 , & V_702 ) ;
if ( V_35 )
return V_35 ;
return F_351 ( V_7 , V_556 , NULL , & V_702 ) ;
}
static int F_352 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
T_3 V_1579 = V_280 | V_1580 ;
if ( ! V_30 -> V_5 [ V_1581 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_279 ] )
V_1579 = F_80 ( V_30 -> V_5 [ V_279 ] ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
case V_155 :
break;
case V_154 :
default:
return - V_557 ;
}
if ( ! V_7 -> V_328 -> V_322 )
return - V_557 ;
return F_353 ( V_17 , V_30 -> V_521 , V_1579 ,
F_24 ( V_30 -> V_5 [ V_1581 ] ) ,
F_25 ( V_30 -> V_5 [ V_1581 ] ) ) ;
}
static int F_354 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
struct V_536 V_537 ;
int V_35 ;
void * V_360 = NULL ;
T_1 V_668 ;
struct V_31 * V_52 = NULL ;
struct V_1582 V_139 = {
. V_1583 =
V_30 -> V_5 [ V_1584 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1585 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_322 )
return - V_557 ;
switch ( V_17 -> V_141 ) {
case V_155 :
if ( ! V_30 -> V_5 [ V_539 ] )
return - V_16 ;
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
break;
case V_154 :
default:
return - V_557 ;
}
if ( V_30 -> V_5 [ V_1574 ] ) {
if ( ! ( V_7 -> V_18 . V_50 & V_462 ) )
return - V_16 ;
V_139 . V_1586 = F_4 ( V_30 -> V_5 [ V_1574 ] ) ;
if ( V_139 . V_1586 < V_1575 ||
V_139 . V_1586 > V_7 -> V_18 . V_461 )
return - V_16 ;
}
V_139 . V_1587 = V_30 -> V_5 [ V_463 ] ;
if ( V_139 . V_1587 && ! ( V_7 -> V_18 . V_50 & V_462 ) )
return - V_16 ;
V_139 . V_1300 = F_167 ( V_30 -> V_5 [ V_1301 ] ) ;
V_537 . V_54 = NULL ;
if ( V_30 -> V_5 [ V_539 ] ) {
V_35 = F_82 ( V_7 , V_30 , & V_537 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_537 . V_54 && V_139 . V_1587 )
return - V_16 ;
V_139 . V_1588 = F_24 ( V_30 -> V_5 [ V_1585 ] ) ;
V_139 . V_46 = F_25 ( V_30 -> V_5 [ V_1585 ] ) ;
if ( V_30 -> V_5 [ V_1589 ] ) {
int V_46 = F_25 ( V_30 -> V_5 [ V_1589 ] ) ;
int V_160 ;
if ( V_46 % sizeof( T_3 ) )
return - V_16 ;
V_139 . V_1590 = V_46 / sizeof( T_3 ) ;
V_139 . V_1591 =
F_24 ( V_30 -> V_5 [ V_1589 ] ) ;
for ( V_160 = 0 ; V_160 < V_139 . V_1590 ; V_160 ++ ) {
if ( V_139 . V_1591 [ V_160 ] >= V_139 . V_46 )
return - V_16 ;
}
}
if ( ! V_139 . V_1583 ) {
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1592 ) ;
if ( ! V_360 ) {
V_35 = - V_90 ;
goto V_678;
}
}
V_139 . V_54 = V_537 . V_54 ;
V_35 = F_355 ( V_7 , V_17 , & V_139 , & V_668 ) ;
if ( V_35 )
goto V_678;
if ( V_52 ) {
if ( F_105 ( V_52 , V_1577 , V_668 ,
V_603 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
}
return 0 ;
V_60:
V_35 = - V_90 ;
V_678:
F_77 ( V_52 ) ;
return V_35 ;
}
static int F_356 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
T_1 V_668 ;
if ( ! V_30 -> V_5 [ V_1577 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_324 )
return - V_557 ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_144 :
case V_155 :
break;
case V_154 :
default:
return - V_557 ;
}
V_668 = F_5 ( V_30 -> V_5 [ V_1577 ] ) ;
return F_357 ( V_7 , V_17 , V_668 ) ;
}
static int F_358 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 V_1593 ;
bool V_359 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1594 ] )
return - V_16 ;
V_1593 = F_4 ( V_30 -> V_5 [ V_1594 ] ) ;
if ( V_1593 != V_1595 && V_1593 != V_1596 )
return - V_16 ;
V_17 = V_556 -> V_28 ;
if ( ! V_7 -> V_328 -> V_1597 )
return - V_557 ;
V_359 = ( V_1593 == V_1596 ) ? true : false ;
if ( V_359 == V_17 -> V_1598 )
return 0 ;
V_35 = F_359 ( V_7 , V_556 , V_359 , V_17 -> V_1599 ) ;
if ( ! V_35 )
V_17 -> V_1598 = V_359 ;
return V_35 ;
}
static int F_360 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
enum V_1600 V_1593 ;
struct V_1 * V_17 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_31 * V_52 ;
void * V_360 ;
int V_35 ;
V_17 = V_556 -> V_28 ;
if ( ! V_7 -> V_328 -> V_1597 )
return - V_557 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1601 ) ;
if ( ! V_360 ) {
V_35 = - V_90 ;
goto V_678;
}
if ( V_17 -> V_1598 )
V_1593 = V_1596 ;
else
V_1593 = V_1595 ;
if ( F_29 ( V_52 , V_1594 , V_1593 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
V_35 = - V_90 ;
V_678:
F_77 ( V_52 ) ;
return V_35 ;
}
static int F_361 ( struct V_29 * V_30 ,
V_22 V_247 , V_22 V_1602 , V_22 V_1603 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
if ( V_247 > 100 || V_1603 > V_1604 )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_1605 )
return - V_557 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_557 ;
return F_362 ( V_7 , V_556 , V_247 , V_1602 , V_1603 ) ;
}
static int F_363 ( struct V_29 * V_30 ,
T_6 V_1606 , V_22 V_1607 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
if ( V_1606 > 0 )
return - V_16 ;
if ( V_1606 == 0 )
V_1607 = 0 ;
if ( ! V_7 -> V_328 -> V_1608 )
return - V_557 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_557 ;
return F_364 ( V_7 , V_556 , V_1606 , V_1607 ) ;
}
static int F_365 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1609 + 1 ] ;
struct V_4 * V_1610 ;
int V_35 ;
V_1610 = V_30 -> V_5 [ V_1611 ] ;
if ( ! V_1610 )
return - V_16 ;
V_35 = F_34 ( V_5 , V_1609 , V_1610 ,
V_1612 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1613 ] &&
V_5 [ V_1614 ] ) {
T_6 V_1606 = F_228 ( V_5 [ V_1613 ] ) ;
V_22 V_1607 = F_4 ( V_5 [ V_1614 ] ) ;
return F_363 ( V_30 , V_1606 , V_1607 ) ;
}
if ( V_5 [ V_1615 ] &&
V_5 [ V_1616 ] &&
V_5 [ V_1617 ] ) {
V_22 V_247 = F_4 ( V_5 [ V_1615 ] ) ;
V_22 V_1602 = F_4 ( V_5 [ V_1616 ] ) ;
V_22 V_1603 = F_4 ( V_5 [ V_1617 ] ) ;
return F_361 ( V_30 , V_247 , V_1602 , V_1603 ) ;
}
return - V_16 ;
}
static int F_366 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1618 V_1180 = {} ;
int V_35 ;
V_35 = F_82 ( V_7 , V_30 , & V_1180 . V_537 ) ;
if ( V_35 )
return V_35 ;
return F_367 ( V_7 , V_556 , & V_1180 ) ;
}
static int F_368 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
return F_369 ( V_7 , V_556 ) ;
}
static int F_370 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1103 V_1167 ;
struct V_1179 V_1180 ;
int V_35 ;
memcpy ( & V_1167 , & V_1107 , sizeof( V_1167 ) ) ;
memcpy ( & V_1180 , & V_1619 , sizeof( V_1180 ) ) ;
if ( V_30 -> V_5 [ V_1109 ] ) {
V_35 = F_230 ( V_30 , & V_1167 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_634 ] ||
! F_25 ( V_30 -> V_5 [ V_634 ] ) )
return - V_16 ;
V_1180 . V_1620 = F_24 ( V_30 -> V_5 [ V_634 ] ) ;
V_1180 . V_1106 = F_25 ( V_30 -> V_5 [ V_634 ] ) ;
if ( V_30 -> V_5 [ V_1514 ] &&
! F_309 ( V_7 , V_1180 . V_1501 ,
F_4 ( V_30 -> V_5 [ V_1514 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_777 ] ) {
V_1180 . V_558 =
F_4 ( V_30 -> V_5 [ V_777 ] ) ;
V_35 = F_165 ( V_7 ,
V_145 ,
V_1180 . V_558 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_778 ] ) {
V_1180 . V_780 =
F_4 ( V_30 -> V_5 [ V_778 ] ) ;
if ( V_1180 . V_780 < 1 || V_1180 . V_780 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1182 ] ) {
V_35 = F_232 ( V_30 , & V_1180 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1180 . V_1202 )
V_1167 . V_1125 = false ;
if ( V_30 -> V_5 [ V_539 ] ) {
V_35 = F_82 ( V_7 , V_30 , & V_1180 . V_537 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1180 . V_537 . V_54 = NULL ;
}
if ( V_30 -> V_5 [ V_1087 ] ) {
T_2 * V_700 = F_24 ( V_30 -> V_5 [ V_1087 ] ) ;
int V_1513 =
F_25 ( V_30 -> V_5 [ V_1087 ] ) ;
struct V_242 * V_243 ;
if ( ! V_1180 . V_537 . V_54 )
return - V_16 ;
V_243 = V_7 -> V_18 . V_438 [ V_1180 . V_537 . V_54 -> V_367 ] ;
V_35 = F_262 ( V_243 , V_700 , V_1513 ,
& V_1180 . V_1088 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_728 ] ) {
V_35 = F_155 ( V_30 , & V_1180 . V_737 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_157 ( V_7 , V_1180 . V_537 . V_54 -> V_367 ,
& V_1180 . V_737 ) ;
if ( V_35 )
return V_35 ;
}
return F_371 ( V_7 , V_556 , & V_1180 , & V_1167 ) ;
}
static int F_372 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
return F_373 ( V_7 , V_556 ) ;
}
static int F_374 ( struct V_31 * V_52 ,
struct V_6 * V_7 )
{
struct V_1621 * V_192 = V_7 -> V_18 . V_1622 ;
struct V_4 * V_1623 , * V_1624 ;
int V_160 , V_1625 ;
if ( ! V_192 -> V_222 )
return 0 ;
V_1623 = F_48 ( V_52 , V_231 ) ;
if ( ! V_1623 )
return - V_90 ;
for ( V_160 = 0 ; V_160 < V_192 -> V_222 ; V_160 ++ ) {
V_1624 = F_48 ( V_52 , V_160 + 1 ) ;
if ( ! V_1624 )
return - V_90 ;
V_1625 = V_192 -> V_1626 [ V_160 ] . V_1627 ;
if ( F_52 ( V_52 , V_1628 , F_270 ( V_1625 , 8 ) ,
V_192 -> V_1626 [ V_160 ] . V_702 ) ||
F_52 ( V_52 , V_1629 , V_1625 ,
V_192 -> V_1626 [ V_160 ] . V_1630 ) ||
F_29 ( V_52 , V_1631 ,
V_192 -> V_1626 [ V_160 ] . V_1632 ) )
return - V_90 ;
F_49 ( V_52 , V_1624 ) ;
}
F_49 ( V_52 , V_1623 ) ;
return 0 ;
}
static int F_375 ( struct V_31 * V_52 ,
struct V_1633 * V_191 )
{
struct V_4 * V_193 ;
if ( ! V_191 )
return 0 ;
V_193 = F_48 ( V_52 , V_194 ) ;
if ( ! V_193 )
return - V_90 ;
if ( F_376 ( V_52 , V_1634 , V_191 -> V_1635 ) ||
F_376 ( V_52 , V_1636 , V_191 -> V_1042 ) ||
F_52 ( V_52 , V_1637 , V_604 , V_191 -> V_1638 ) ||
F_56 ( V_52 , V_1639 , V_191 -> V_1640 ) ||
F_56 ( V_52 , V_1641 , V_191 -> V_1642 ) ||
F_52 ( V_52 , V_195 ,
V_191 -> V_1643 , V_191 -> V_1644 ) ||
F_29 ( V_52 , V_200 ,
V_191 -> V_1645 ) ||
F_52 ( V_52 , V_202 ,
V_191 -> V_1646 , V_191 -> V_1647 ) ||
F_52 ( V_52 , V_1648 ,
F_270 ( V_191 -> V_1646 , 8 ) , V_191 -> V_1649 ) )
return - V_90 ;
if ( V_191 -> V_1650 . V_46 &&
F_52 ( V_52 , V_197 ,
sizeof( V_191 -> V_1650 ) , & V_191 -> V_1650 ) )
return - V_90 ;
if ( V_191 -> V_1651 . V_46 &&
F_52 ( V_52 , V_199 ,
sizeof( V_191 -> V_1651 ) + V_191 -> V_1652 ,
& V_191 -> V_1651 ) )
return - V_90 ;
F_49 ( V_52 , V_193 ) ;
return 0 ;
}
static int F_377 ( struct V_31 * V_52 ,
struct V_1307 * V_1476 )
{
struct V_4 * V_1653 , * V_1255 , * V_1654 , * V_1655 , * V_1311 , * V_1656 ;
int V_160 ;
if ( ! V_1476 )
return 0 ;
V_1653 = F_48 ( V_52 , V_233 ) ;
if ( ! V_1653 )
return - V_90 ;
if ( V_1476 -> V_1329 == 1 &&
F_29 ( V_52 , V_1310 ,
V_1476 -> V_1311 [ 0 ] . V_1309 * 1000 ) )
return - V_90 ;
if ( F_29 ( V_52 , V_1336 , V_1476 -> V_1337 ) )
return - V_90 ;
V_1255 = F_48 ( V_52 , V_1285 ) ;
if ( ! V_1255 )
return - V_90 ;
for ( V_160 = 0 ; V_160 < V_1476 -> V_441 ; V_160 ++ ) {
if ( F_29 ( V_52 , V_160 , V_1476 -> V_442 [ V_160 ] -> V_59 ) )
return - V_90 ;
}
F_49 ( V_52 , V_1255 ) ;
if ( V_1476 -> V_1319 ) {
V_1654 = F_48 ( V_52 , V_1323 ) ;
if ( ! V_1654 )
return - V_90 ;
for ( V_160 = 0 ; V_160 < V_1476 -> V_1319 ; V_160 ++ ) {
V_1655 = F_48 ( V_52 , V_160 ) ;
if ( ! V_1655 )
return - V_90 ;
if ( F_52 ( V_52 , V_1326 ,
V_1476 -> V_1328 [ V_160 ] . V_611 . V_609 ,
V_1476 -> V_1328 [ V_160 ] . V_611 . V_611 ) )
return - V_90 ;
F_49 ( V_52 , V_1655 ) ;
}
F_49 ( V_52 , V_1654 ) ;
}
V_1311 = F_48 ( V_52 , V_1308 ) ;
if ( ! V_1311 )
return - V_90 ;
for ( V_160 = 0 ; V_160 < V_1476 -> V_1329 ; V_160 ++ ) {
V_1656 = F_48 ( V_52 , V_160 + 1 ) ;
if ( ! V_1656 )
return - V_90 ;
if ( ! V_1656 ||
F_29 ( V_52 , V_1316 ,
V_1476 -> V_1311 [ V_160 ] . V_1309 ) ||
( V_1476 -> V_1311 [ V_160 ] . V_1318 &&
F_29 ( V_52 , V_1317 ,
V_1476 -> V_1311 [ V_160 ] . V_1318 ) ) )
return - V_90 ;
F_49 ( V_52 , V_1656 ) ;
}
F_49 ( V_52 , V_1311 ) ;
F_49 ( V_52 , V_1653 ) ;
return 0 ;
}
static int F_378 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_31 * V_52 ;
void * V_360 ;
V_22 V_1657 = V_617 ;
if ( ! V_7 -> V_18 . V_192 )
return - V_557 ;
if ( V_7 -> V_18 . V_1622 && V_7 -> V_18 . V_1622 -> V_191 ) {
V_1657 += V_7 -> V_18 . V_1622 -> V_191 -> V_1652 +
V_7 -> V_18 . V_1622 -> V_191 -> V_1643 +
V_7 -> V_18 . V_1622 -> V_191 -> V_1646 +
V_7 -> V_18 . V_1622 -> V_191 -> V_1646 / 8 ;
}
V_52 = F_76 ( V_1657 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1658 ) ;
if ( ! V_360 )
goto V_60;
if ( V_7 -> V_18 . V_1622 ) {
struct V_4 * V_204 ;
V_204 = F_48 ( V_52 , V_1659 ) ;
if ( ! V_204 )
goto V_60;
if ( ( V_7 -> V_18 . V_1622 -> V_1660 &&
F_30 ( V_52 , V_207 ) ) ||
( V_7 -> V_18 . V_1622 -> V_355 &&
F_30 ( V_52 , V_209 ) ) ||
( V_7 -> V_18 . V_1622 -> V_1661 &&
F_30 ( V_52 , V_211 ) ) ||
( V_7 -> V_18 . V_1622 -> V_1662 &&
F_30 ( V_52 , V_215 ) ) ||
( V_7 -> V_18 . V_1622 -> V_1663 &&
F_30 ( V_52 , V_217 ) ) ||
( V_7 -> V_18 . V_1622 -> V_1664 &&
F_30 ( V_52 , V_219 ) ) ||
( V_7 -> V_18 . V_1622 -> V_1665 &&
F_30 ( V_52 , V_221 ) ) )
goto V_60;
if ( F_374 ( V_52 , V_7 ) )
goto V_60;
if ( F_375 ( V_52 ,
V_7 -> V_18 . V_1622 -> V_191 ) )
goto V_60;
if ( F_377 (
V_52 ,
V_7 -> V_18 . V_1622 -> V_1666 ) )
goto V_60;
F_49 ( V_52 , V_204 ) ;
}
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
F_77 ( V_52 ) ;
return - V_90 ;
}
static int F_379 ( struct V_6 * V_7 ,
struct V_4 * V_44 ,
struct V_1621 * V_1667 )
{
struct V_4 * V_94 [ V_1668 ] ;
struct V_1633 * V_1167 ;
struct V_1669 * V_198 = NULL ;
struct V_1670 * V_49 = NULL ;
V_22 V_1657 ;
V_22 V_1671 , V_1672 , V_1652 = 0 , V_1673 ;
int V_35 , V_1674 ;
if ( ! V_7 -> V_18 . V_192 -> V_191 )
return - V_16 ;
V_35 = F_34 ( V_94 , V_1675 , V_44 ,
V_1676 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_94 [ V_1634 ] ||
! V_94 [ V_1636 ] ||
! V_94 [ V_1637 ] ||
! V_94 [ V_1641 ] ||
! V_94 [ V_195 ] ||
! V_94 [ V_200 ] ||
! V_94 [ V_202 ] ||
! V_94 [ V_1648 ] )
return - V_16 ;
V_1671 = F_25 ( V_94 [ V_195 ] ) ;
if ( V_1671 > V_7 -> V_18 . V_192 -> V_191 -> V_196 )
return - V_16 ;
if ( F_4 ( V_94 [ V_200 ] ) >
V_7 -> V_18 . V_192 -> V_191 -> V_201 ||
F_4 ( V_94 [ V_200 ] ) == 0 )
return - V_16 ;
V_1672 = F_25 ( V_94 [ V_202 ] ) ;
if ( V_1672 > V_7 -> V_18 . V_192 -> V_191 -> V_203 )
return - V_16 ;
V_1673 = F_25 ( V_94 [ V_1648 ] ) ;
if ( V_1673 != F_270 ( V_1672 , 8 ) )
return - V_16 ;
if ( V_94 [ V_199 ] ) {
V_22 V_1677 = F_25 ( V_94 [ V_199 ] ) ;
V_198 = F_24 ( V_94 [ V_199 ] ) ;
V_1652 = V_1677 - sizeof( * V_198 ) ;
if ( ! V_198 -> V_46 || V_1652 % V_198 -> V_46 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_192 -> V_191 -> V_198 )
return - V_16 ;
if ( V_198 -> V_46 > V_7 -> V_18 . V_192 -> V_191 -> V_198 -> V_1678 )
return - V_16 ;
if ( V_198 -> V_46 < V_7 -> V_18 . V_192 -> V_191 -> V_198 -> V_1679 )
return - V_16 ;
if ( V_1652 > V_7 -> V_18 . V_192 -> V_191 -> V_198 -> V_1680 )
return - V_16 ;
if ( V_198 -> V_1361 + V_198 -> V_46 > V_1671 )
return - V_16 ;
}
if ( V_94 [ V_197 ] ) {
V_49 = F_24 ( V_94 [ V_197 ] ) ;
if ( ! V_7 -> V_18 . V_192 -> V_191 -> V_49 )
return - V_16 ;
if ( V_49 -> V_46 == 0 || V_49 -> V_46 > 4 )
return - V_16 ;
if ( V_49 -> V_46 + V_49 -> V_1361 > V_1671 )
return - V_16 ;
}
V_1657 = sizeof( * V_1167 ) ;
V_1657 += V_1671 ;
V_1657 += V_1672 + V_1673 ;
V_1657 += V_1652 ;
V_1167 = F_40 ( V_1657 , V_135 ) ;
if ( ! V_1167 )
return - V_136 ;
V_1167 -> V_1635 = F_380 ( V_94 [ V_1634 ] ) ;
V_1167 -> V_1042 = F_380 ( V_94 [ V_1636 ] ) ;
memcpy ( V_1167 -> V_1638 , F_24 ( V_94 [ V_1637 ] ) ,
V_604 ) ;
if ( V_94 [ V_1639 ] )
V_1674 = F_80 ( V_94 [ V_1639 ] ) ;
else
V_1674 = 0 ;
#ifdef F_381
V_35 = F_382 ( F_7 ( & V_7 -> V_18 ) , V_1681 , V_1682 ,
V_1683 , & V_1167 -> V_1684 , 1 ) ;
if ( V_35 ) {
F_42 ( V_1167 ) ;
return V_35 ;
}
if ( F_383 ( V_1167 -> V_1684 -> V_43 , V_1674 ) ) {
F_384 ( V_1167 -> V_1684 ) ;
F_42 ( V_1167 ) ;
return - V_1685 ;
}
V_1167 -> V_1640 = F_385 ( V_1167 -> V_1684 -> V_43 ) -> V_1686 ;
#else
if ( ! V_1674 ) {
F_42 ( V_1167 ) ;
return - V_16 ;
}
V_1167 -> V_1640 = V_1674 ;
#endif
V_1167 -> V_1642 = F_80 ( V_94 [ V_1641 ] ) ;
V_1167 -> V_1643 = V_1671 ;
V_1167 -> V_1644 = ( T_2 * ) V_1167 + sizeof( * V_1167 ) + V_1652 ;
memcpy ( ( void * ) V_1167 -> V_1644 ,
F_24 ( V_94 [ V_195 ] ) ,
V_1671 ) ;
if ( V_49 )
V_1167 -> V_1650 = * V_49 ;
V_1167 -> V_1645 = F_4 ( V_94 [ V_200 ] ) ;
V_1167 -> V_1646 = V_1672 ;
V_1167 -> V_1647 = ( T_2 * ) V_1167 + sizeof( * V_1167 ) + V_1652 + V_1671 ;
memcpy ( ( void * ) V_1167 -> V_1647 ,
F_24 ( V_94 [ V_202 ] ) ,
V_1672 ) ;
V_1167 -> V_1649 = ( T_2 * ) V_1167 + sizeof( * V_1167 ) + V_1652 +
V_1671 + V_1672 ;
memcpy ( ( void * ) V_1167 -> V_1649 ,
F_24 ( V_94 [ V_1648 ] ) ,
V_1673 ) ;
if ( V_198 ) {
V_1167 -> V_1652 = V_1652 ;
memcpy ( & V_1167 -> V_1651 , V_198 , sizeof( * V_198 ) + V_1652 ) ;
}
V_1667 -> V_191 = V_1167 ;
return 0 ;
}
static int F_386 ( struct V_6 * V_7 ,
const struct V_1687 * V_192 ,
struct V_4 * V_44 ,
struct V_1621 * V_1667 )
{
struct V_4 * * V_94 ;
int V_35 ;
V_94 = F_40 ( V_1688 * sizeof( * V_94 ) , V_135 ) ;
if ( ! V_94 )
return - V_136 ;
if ( ! ( V_192 -> V_50 & V_232 ) ) {
V_35 = - V_557 ;
goto V_616;
}
V_35 = F_34 ( V_94 , V_1348 , V_44 , V_41 ) ;
if ( V_35 )
goto V_616;
V_1667 -> V_1666 = F_271 ( & V_7 -> V_18 , NULL , V_94 ) ;
V_35 = F_273 ( V_1667 -> V_1666 ) ;
if ( V_35 )
V_1667 -> V_1666 = NULL ;
V_616:
F_42 ( V_94 ) ;
return V_35 ;
}
static int F_387 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_4 * V_94 [ V_1689 ] ;
struct V_1621 V_1690 = {} ;
struct V_1621 * V_1691 ;
const struct V_1687 * V_192 = V_7 -> V_18 . V_192 ;
int V_35 , V_160 ;
bool V_1692 = V_7 -> V_18 . V_1622 ;
bool V_1693 = false ;
if ( ! V_192 )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_1659 ] ) {
F_388 ( V_7 ) ;
V_7 -> V_18 . V_1622 = NULL ;
goto V_1694;
}
V_35 = F_34 ( V_94 , V_1695 ,
V_30 -> V_5 [ V_1659 ] ,
V_1696 ) ;
if ( V_35 )
return V_35 ;
if ( V_94 [ V_207 ] ) {
if ( ! ( V_192 -> V_50 & V_206 ) )
return - V_16 ;
V_1690 . V_1660 = true ;
}
if ( V_94 [ V_209 ] ) {
if ( ! ( V_192 -> V_50 & V_208 ) )
return - V_16 ;
V_1690 . V_355 = true ;
V_1693 = true ;
}
if ( V_94 [ V_211 ] ) {
if ( ! ( V_192 -> V_50 & V_210 ) )
return - V_16 ;
V_1690 . V_1661 = true ;
V_1693 = true ;
}
if ( V_94 [ V_213 ] )
return - V_16 ;
if ( V_94 [ V_215 ] ) {
if ( ! ( V_192 -> V_50 & V_214 ) )
return - V_16 ;
V_1690 . V_1662 = true ;
V_1693 = true ;
}
if ( V_94 [ V_217 ] ) {
if ( ! ( V_192 -> V_50 & V_216 ) )
return - V_16 ;
V_1690 . V_1663 = true ;
V_1693 = true ;
}
if ( V_94 [ V_219 ] ) {
if ( ! ( V_192 -> V_50 & V_218 ) )
return - V_16 ;
V_1690 . V_1664 = true ;
V_1693 = true ;
}
if ( V_94 [ V_221 ] ) {
if ( ! ( V_192 -> V_50 & V_220 ) )
return - V_16 ;
V_1690 . V_1665 = true ;
V_1693 = true ;
}
if ( V_94 [ V_231 ] ) {
struct V_4 * V_224 ;
int V_222 = 0 ;
int V_133 , V_1625 , V_1697 , V_1632 ;
struct V_4 * V_1698 [ V_1699 ] ;
V_1693 = true ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_222 ++ ;
if ( V_222 > V_192 -> V_222 )
return - V_16 ;
V_1690 . V_1626 = F_389 ( V_222 ,
sizeof( V_1690 . V_1626 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1690 . V_1626 )
return - V_136 ;
V_1690 . V_222 = V_222 ;
V_160 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1700 ;
F_34 ( V_1698 , V_1701 , V_224 ,
NULL ) ;
V_35 = - V_16 ;
if ( ! V_1698 [ V_1628 ] ||
! V_1698 [ V_1629 ] )
goto error;
V_1625 = F_25 ( V_1698 [ V_1629 ] ) ;
V_1697 = F_270 ( V_1625 , 8 ) ;
if ( F_25 ( V_1698 [ V_1628 ] ) != V_1697 )
goto error;
if ( V_1625 > V_192 -> V_229 ||
V_1625 < V_192 -> V_227 )
goto error;
if ( ! V_1698 [ V_1631 ] )
V_1632 = 0 ;
else
V_1632 = F_4 (
V_1698 [ V_1631 ] ) ;
if ( V_1632 > V_192 -> V_230 )
goto error;
V_1690 . V_1626 [ V_160 ] . V_1632 = V_1632 ;
V_1700 = F_390 ( V_1697 + V_1625 , V_135 ) ;
if ( ! V_1700 ) {
V_35 = - V_136 ;
goto error;
}
V_1690 . V_1626 [ V_160 ] . V_702 = V_1700 ;
memcpy ( V_1700 , F_24 ( V_1698 [ V_1628 ] ) ,
V_1697 ) ;
V_1700 += V_1697 ;
V_1690 . V_1626 [ V_160 ] . V_1630 = V_1700 ;
V_1690 . V_1626 [ V_160 ] . V_1627 = V_1625 ;
memcpy ( V_1700 ,
F_24 ( V_1698 [ V_1629 ] ) ,
V_1625 ) ;
V_160 ++ ;
}
}
if ( V_94 [ V_194 ] ) {
V_1693 = true ;
V_35 = F_379 (
V_7 , V_94 [ V_194 ] ,
& V_1690 ) ;
if ( V_35 )
goto error;
}
if ( V_94 [ V_233 ] ) {
V_1693 = true ;
V_35 = F_386 (
V_7 , V_192 , V_94 [ V_233 ] ,
& V_1690 ) ;
if ( V_35 )
goto error;
}
if ( V_1690 . V_1660 && V_1693 ) {
V_35 = - V_16 ;
goto error;
}
V_1691 = F_391 ( & V_1690 , sizeof( V_1690 ) , V_135 ) ;
if ( ! V_1691 ) {
V_35 = - V_136 ;
goto error;
}
F_388 ( V_7 ) ;
V_7 -> V_18 . V_1622 = V_1691 ;
V_1694:
if ( V_7 -> V_328 -> V_1694 &&
V_1692 != ! ! V_7 -> V_18 . V_1622 )
F_392 ( V_7 , V_7 -> V_18 . V_1622 ) ;
return 0 ;
error:
for ( V_160 = 0 ; V_160 < V_1690 . V_222 ; V_160 ++ )
F_42 ( V_1690 . V_1626 [ V_160 ] . V_702 ) ;
F_42 ( V_1690 . V_1626 ) ;
if ( V_1690 . V_191 && V_1690 . V_191 -> V_1684 )
F_384 ( V_1690 . V_191 -> V_1684 ) ;
F_42 ( V_1690 . V_191 ) ;
F_42 ( V_1690 . V_1666 ) ;
return V_35 ;
}
static int F_393 ( struct V_31 * V_52 ,
struct V_6 * V_7 )
{
struct V_4 * V_1623 , * V_1624 , * V_1702 , * V_1703 ;
int V_160 , V_162 , V_1625 ;
struct V_1704 * V_236 ;
if ( ! V_7 -> V_237 -> V_239 )
return 0 ;
V_1703 = F_48 ( V_52 , V_241 ) ;
if ( ! V_1703 )
return - V_90 ;
for ( V_160 = 0 ; V_160 < V_7 -> V_237 -> V_239 ; V_160 ++ ) {
V_1702 = F_48 ( V_52 , V_160 + 1 ) ;
if ( ! V_1702 )
return - V_90 ;
V_236 = & V_7 -> V_237 -> V_1705 [ V_160 ] ;
if ( F_29 ( V_52 , V_1706 ,
V_236 -> V_1337 ) )
return - V_90 ;
if ( F_29 ( V_52 , V_1707 ,
V_236 -> V_1708 ) )
return - V_90 ;
V_1623 = F_48 ( V_52 ,
V_1709 ) ;
if ( ! V_1623 )
return - V_90 ;
for ( V_162 = 0 ; V_162 < V_236 -> V_222 ; V_162 ++ ) {
V_1624 = F_48 ( V_52 , V_162 + 1 ) ;
if ( ! V_1624 )
return - V_90 ;
V_1625 = V_236 -> V_1626 [ V_162 ] . V_1627 ;
if ( F_52 ( V_52 , V_1628 ,
F_270 ( V_1625 , 8 ) ,
V_236 -> V_1626 [ V_162 ] . V_702 ) ||
F_52 ( V_52 , V_1629 , V_1625 ,
V_236 -> V_1626 [ V_162 ] . V_1630 ) ||
F_29 ( V_52 , V_1631 ,
V_236 -> V_1626 [ V_162 ] . V_1632 ) )
return - V_90 ;
F_49 ( V_52 , V_1624 ) ;
}
F_49 ( V_52 , V_1623 ) ;
F_49 ( V_52 , V_1702 ) ;
}
F_49 ( V_52 , V_1703 ) ;
return 0 ;
}
static int F_394 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_31 * V_52 ;
void * V_360 ;
if ( ! V_7 -> V_18 . V_237 )
return - V_557 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1710 ) ;
if ( ! V_360 )
goto V_60;
if ( V_7 -> V_237 && F_393 ( V_52 , V_7 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
F_77 ( V_52 ) ;
return - V_90 ;
}
void F_395 ( struct V_6 * V_7 )
{
struct V_1711 * V_237 = V_7 -> V_237 ;
int V_160 , V_162 ;
struct V_1704 * V_236 ;
if ( ! V_237 )
return;
for ( V_160 = 0 ; V_160 < V_237 -> V_239 ; V_160 ++ ) {
V_236 = & V_237 -> V_1705 [ V_160 ] ;
for ( V_162 = 0 ; V_162 < V_236 -> V_222 ; V_162 ++ )
F_42 ( V_236 -> V_1626 [ V_162 ] . V_702 ) ;
F_42 ( V_236 -> V_1626 ) ;
}
F_42 ( V_237 -> V_1705 ) ;
F_42 ( V_237 ) ;
V_7 -> V_237 = NULL ;
}
static int F_396 ( struct V_6 * V_7 ,
struct V_4 * V_236 ,
struct V_1704 * V_1712 )
{
int V_35 , V_160 ;
const struct V_1713 * V_237 = V_7 -> V_18 . V_237 ;
struct V_4 * V_94 [ V_1714 ] , * V_224 ;
int V_133 , V_1625 , V_1697 , V_1632 , V_222 = 0 ;
struct V_4 * V_1698 [ V_1699 ] ;
V_35 = F_34 ( V_94 , V_1715 , V_236 ,
V_1716 ) ;
if ( V_35 )
return V_35 ;
if ( V_94 [ V_1706 ] )
V_1712 -> V_1337 =
F_4 ( V_94 [ V_1706 ] ) ;
if ( V_1712 -> V_1337 > V_237 -> V_240 )
return - V_16 ;
if ( V_94 [ V_1707 ] )
V_1712 -> V_1708 =
F_4 ( V_94 [ V_1707 ] ) ;
if ( V_1712 -> V_1708 != V_1717 &&
V_1712 -> V_1708 != V_1718 )
return - V_16 ;
if ( ! V_94 [ V_1709 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_222 ++ ;
if ( V_222 > V_237 -> V_222 )
return - V_16 ;
V_1712 -> V_1626 = F_389 ( V_222 , sizeof( V_1712 -> V_1626 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1712 -> V_1626 )
return - V_136 ;
V_1712 -> V_222 = V_222 ;
V_160 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1700 ;
F_34 ( V_1698 , V_1701 , V_224 , NULL ) ;
if ( ! V_1698 [ V_1628 ] ||
! V_1698 [ V_1629 ] )
return - V_16 ;
V_1625 = F_25 ( V_1698 [ V_1629 ] ) ;
V_1697 = F_270 ( V_1625 , 8 ) ;
if ( F_25 ( V_1698 [ V_1628 ] ) != V_1697 )
return - V_16 ;
if ( V_1625 > V_237 -> V_229 ||
V_1625 < V_237 -> V_227 )
return - V_16 ;
if ( ! V_1698 [ V_1631 ] )
V_1632 = 0 ;
else
V_1632 = F_4 ( V_1698 [ V_1631 ] ) ;
if ( V_1632 > V_237 -> V_230 )
return - V_16 ;
V_1712 -> V_1626 [ V_160 ] . V_1632 = V_1632 ;
V_1700 = F_390 ( V_1697 + V_1625 , V_135 ) ;
if ( ! V_1700 )
return - V_136 ;
V_1712 -> V_1626 [ V_160 ] . V_702 = V_1700 ;
memcpy ( V_1700 , F_24 ( V_1698 [ V_1628 ] ) ,
V_1697 ) ;
V_1700 += V_1697 ;
V_1712 -> V_1626 [ V_160 ] . V_1630 = V_1700 ;
V_1712 -> V_1626 [ V_160 ] . V_1627 = V_1625 ;
memcpy ( V_1700 , F_24 ( V_1698 [ V_1629 ] ) ,
V_1625 ) ;
V_160 ++ ;
}
return 0 ;
}
static int F_397 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
const struct V_1713 * V_237 = V_7 -> V_18 . V_237 ;
struct V_1711 V_1719 = {} ;
struct V_1711 * V_1720 ;
int V_35 , V_1721 , V_239 = 0 , V_160 , V_162 ;
struct V_4 * V_236 ;
struct V_1704 * V_1722 ;
if ( ! V_7 -> V_18 . V_237 || ! V_7 -> V_328 -> V_1723 )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_241 ] ) {
F_395 ( V_7 ) ;
F_398 ( V_7 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_239 ++ ;
if ( V_239 > V_237 -> V_239 )
return - V_16 ;
V_1719 . V_1705 = F_389 ( V_239 , sizeof( V_1719 . V_1705 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1719 . V_1705 )
return - V_136 ;
V_1719 . V_239 = V_239 ;
V_160 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_396 ( V_7 , V_236 ,
& V_1719 . V_1705 [ V_160 ] ) ;
if ( V_35 )
goto error;
V_160 ++ ;
}
V_35 = F_398 ( V_7 , & V_1719 ) ;
if ( V_35 )
goto error;
V_1720 = F_391 ( & V_1719 , sizeof( V_1719 ) , V_135 ) ;
if ( ! V_1720 ) {
V_35 = - V_136 ;
goto error;
}
F_395 ( V_7 ) ;
V_7 -> V_237 = V_1720 ;
return 0 ;
error:
for ( V_160 = 0 ; V_160 < V_1719 . V_239 ; V_160 ++ ) {
V_1722 = & V_1719 . V_1705 [ V_160 ] ;
for ( V_162 = 0 ; V_162 < V_1722 -> V_222 ; V_162 ++ )
F_42 ( V_1722 -> V_1626 [ V_162 ] . V_702 ) ;
F_42 ( V_1722 -> V_1626 ) ;
}
F_42 ( V_1719 . V_1705 ) ;
return V_35 ;
}
static int F_399 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_4 * V_94 [ V_1724 ] ;
struct V_1725 V_1726 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1727 ] )
return - V_16 ;
V_35 = F_34 ( V_94 , V_1728 ,
V_30 -> V_5 [ V_1727 ] ,
V_1729 ) ;
if ( V_35 )
return V_35 ;
if ( F_25 ( V_94 [ V_1730 ] ) != V_1731 )
return - V_1732 ;
if ( F_25 ( V_94 [ V_1733 ] ) != V_1734 )
return - V_1732 ;
if ( F_25 ( V_94 [ V_1735 ] ) != V_1736 )
return - V_1732 ;
V_1726 . V_1737 = F_24 ( V_94 [ V_1733 ] ) ;
V_1726 . V_1738 = F_24 ( V_94 [ V_1735 ] ) ;
V_1726 . V_1739 = F_24 ( V_94 [ V_1730 ] ) ;
F_114 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1351 ;
goto V_616;
}
if ( ! V_7 -> V_328 -> V_1740 ) {
V_35 = - V_557 ;
goto V_616;
}
V_35 = F_400 ( V_7 , V_556 , & V_1726 ) ;
V_616:
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_401 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1741 )
return - V_561 ;
V_17 -> V_1741 = V_30 -> V_521 ;
return 0 ;
}
static int F_402 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_31 * V_52 ;
void * V_360 ;
const T_2 * V_698 ;
T_1 V_668 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
if ( ! V_7 -> V_328 -> V_341 )
return - V_557 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1742 ) ;
if ( ! V_360 ) {
V_35 = - V_90 ;
goto V_678;
}
V_698 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_35 = F_403 ( V_7 , V_556 , V_698 , & V_668 ) ;
if ( V_35 )
goto V_678;
if ( F_105 ( V_52 , V_1577 , V_668 ,
V_603 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
V_35 = - V_90 ;
V_678:
F_77 ( V_52 ) ;
return V_35 ;
}
static int F_404 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1743 * V_1744 , * V_1745 ;
int V_1746 ;
if ( ! ( V_7 -> V_18 . V_50 & V_345 ) )
return - V_557 ;
V_1745 = F_40 ( sizeof( * V_1745 ) , V_135 ) ;
if ( ! V_1745 )
return - V_136 ;
F_292 ( & V_7 -> V_1747 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1744 -> V_1748 == V_30 -> V_521 ) {
V_1746 = - V_776 ;
goto V_951;
}
}
V_1745 -> V_1748 = V_30 -> V_521 ;
F_405 ( & V_1745 -> V_661 , & V_7 -> V_1749 ) ;
F_294 ( & V_7 -> V_1747 ) ;
return 0 ;
V_951:
F_294 ( & V_7 -> V_1747 ) ;
F_42 ( V_1745 ) ;
return V_1746 ;
}
static int F_406 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_347 )
return - V_557 ;
if ( V_17 -> V_141 != V_155 )
return - V_557 ;
if ( F_407 ( V_17 ) )
return 0 ;
if ( F_408 ( V_7 -> V_1750 ) )
return - V_1751 ;
V_35 = F_409 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1752 = true ;
V_7 -> V_1753 ++ ;
return 0 ;
}
static int F_410 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
if ( V_17 -> V_141 != V_155 )
return - V_557 ;
if ( ! V_7 -> V_328 -> V_1754 )
return - V_557 ;
F_411 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_412 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
struct V_1755 V_1756 = {} ;
int V_35 ;
if ( V_17 -> V_141 != V_154 )
return - V_557 ;
if ( F_407 ( V_17 ) )
return - V_1757 ;
if ( F_408 ( V_7 -> V_1750 ) )
return - V_1751 ;
if ( ! V_30 -> V_5 [ V_1758 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1759 ] )
return - V_16 ;
V_1756 . V_1760 =
F_35 ( V_30 -> V_5 [ V_1758 ] ) ;
if ( ! V_1756 . V_1760 )
return - V_16 ;
V_1756 . V_1761 = F_35 ( V_30 -> V_5 [ V_1759 ] ) ;
V_35 = F_413 ( V_7 , V_17 , & V_1756 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1752 = true ;
V_7 -> V_1753 ++ ;
return 0 ;
}
static int F_414 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
if ( V_17 -> V_141 != V_154 )
return - V_557 ;
F_415 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_416 ( struct V_4 * V_1762 )
{
struct V_4 * V_44 ;
int V_46 = 0 , V_686 = 0 , V_133 ;
F_39 (attr, filter_attr, rem) {
V_46 += F_25 ( V_44 ) ;
V_686 ++ ;
}
if ( V_46 >= V_1763 )
return - V_16 ;
return V_686 ;
}
static int F_417 ( struct V_4 * V_1764 ,
struct V_1765 * V_1766 ,
bool V_278 )
{
struct V_4 * V_44 ;
int V_686 , V_133 , V_160 ;
struct V_1767 * V_1768 ;
V_686 = F_416 ( V_1764 ) ;
if ( V_686 < 0 )
return V_686 ;
F_115 ( sizeof( * V_1766 -> V_1769 ) != sizeof( * V_1766 -> V_1770 ) ) ;
V_1768 = F_389 ( V_686 , sizeof( * V_1766 -> V_1769 ) , V_135 ) ;
if ( ! V_1768 )
return - V_136 ;
V_160 = 0 ;
F_39 (attr, attr_filter, rem) {
V_1768 [ V_160 ] . V_1768 = F_418 ( V_44 , V_135 ) ;
V_1768 [ V_160 ] . V_46 = F_25 ( V_44 ) ;
V_160 ++ ;
}
if ( V_278 ) {
V_1766 -> V_1771 = V_686 ;
V_1766 -> V_1770 = V_1768 ;
} else {
V_1766 -> V_1772 = V_686 ;
V_1766 -> V_1769 = V_1768 ;
}
return 0 ;
}
static int F_419 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
struct V_4 * V_94 [ V_1773 ] , * V_1774 ;
struct V_1765 * V_1766 ;
struct V_31 * V_52 = NULL ;
void * V_360 = NULL ;
int V_35 = 0 ;
if ( V_17 -> V_141 != V_154 )
return - V_557 ;
if ( ! F_407 ( V_17 ) )
return - V_1351 ;
if ( ! V_30 -> V_5 [ V_1775 ] )
return - V_16 ;
if ( V_17 -> V_655 &&
V_17 -> V_655 != V_30 -> V_521 )
return - V_1351 ;
V_35 = F_34 ( V_94 , V_1776 ,
V_30 -> V_5 [ V_1775 ] ,
V_1777 ) ;
if ( V_35 )
return V_35 ;
V_1766 = F_40 ( sizeof( * V_1766 ) , V_135 ) ;
if ( ! V_1766 )
return - V_136 ;
V_1766 -> V_668 = V_17 -> V_18 -> V_1778 ++ ;
if ( ! V_94 [ V_1779 ] ||
F_35 ( V_94 [ V_1779 ] ) > V_1780 ) {
V_35 = - V_16 ;
goto V_616;
}
V_1766 -> type = F_35 ( V_94 [ V_1779 ] ) ;
if ( ! V_94 [ V_1781 ] ) {
V_35 = - V_16 ;
goto V_616;
}
memcpy ( V_1766 -> V_1782 , F_24 ( V_94 [ V_1781 ] ) ,
sizeof( V_1766 -> V_1782 ) ) ;
V_1766 -> V_1783 =
F_167 ( V_94 [ V_1784 ] ) ;
if ( V_94 [ V_1785 ] ) {
V_1766 -> V_1786 =
F_25 ( V_94 [ V_1785 ] ) ;
V_1766 -> V_1787 =
F_391 ( F_24 ( V_94 [ V_1785 ] ) ,
V_1766 -> V_1786 ,
V_135 ) ;
if ( ! V_1766 -> V_1787 ) {
V_35 = - V_136 ;
goto V_616;
}
}
if ( V_94 [ V_1788 ] )
V_1766 -> V_1789 = F_4 ( V_94 [ V_1788 ] ) ;
switch ( V_1766 -> type ) {
case V_1790 :
if ( ! V_94 [ V_1791 ] ) {
V_35 = - V_16 ;
goto V_616;
}
V_1766 -> V_1792 =
F_35 ( V_94 [ V_1791 ] ) ;
V_1766 -> V_1793 =
F_167 ( V_94 [ V_1794 ] ) ;
if ( ( ! ( V_1766 -> V_1792 & V_1795 ) ) &&
V_1766 -> V_1793 ) {
V_35 = - V_16 ;
goto V_616;
}
break;
case V_1796 :
V_1766 -> V_1797 =
F_167 ( V_94 [ V_1798 ] ) ;
break;
case V_1799 :
if ( ! V_94 [ V_1800 ] ||
! V_94 [ V_1801 ] ) {
V_35 = - V_16 ;
goto V_616;
}
V_1766 -> V_1802 =
F_35 ( V_94 [ V_1800 ] ) ;
V_1766 -> V_1803 =
F_35 ( V_94 [ V_1801 ] ) ;
memcpy ( V_1766 -> V_1804 . V_698 ,
F_24 ( V_94 [ V_1805 ] ) ,
sizeof( V_1766 -> V_1804 . V_698 ) ) ;
if ( V_1766 -> V_1789 ) {
V_35 = - V_16 ;
goto V_616;
}
break;
default:
V_35 = - V_16 ;
goto V_616;
}
if ( V_94 [ V_1806 ] ) {
struct V_4 * V_1807 [ V_1808 ] ;
V_35 = F_34 ( V_1807 , V_1809 ,
V_94 [ V_1806 ] ,
V_1810 ) ;
if ( V_35 )
goto V_616;
V_1766 -> V_1811 =
F_167 ( V_1807 [ V_1812 ] ) ;
if ( V_1807 [ V_1813 ] ) {
if ( V_1807 [ V_1814 ] ||
! V_1807 [ V_1815 ] ) {
V_35 = - V_16 ;
goto V_616;
}
V_1766 -> V_1816 =
F_25 ( V_1807 [ V_1813 ] ) ;
V_1766 -> V_1817 =
F_391 ( F_24 ( V_1807 [ V_1813 ] ) ,
V_1766 -> V_1816 , V_135 ) ;
if ( ! V_1766 -> V_1817 ) {
V_35 = - V_136 ;
goto V_616;
}
V_1766 -> V_1818 =
F_35 ( V_1807 [ V_1815 ] ) ;
} else {
struct V_4 * V_44 , * V_1819 =
V_1807 [ V_1814 ] ;
int V_686 , V_133 , V_160 = 0 ;
if ( ! V_1819 ) {
V_35 = - V_16 ;
goto V_616;
}
V_686 = F_145 ( V_1819 ) ;
if ( V_686 <= 0 ) {
V_35 = - V_16 ;
goto V_616;
}
V_1766 -> V_1820 = V_686 ;
V_1766 -> V_1821 =
F_40 ( sizeof( * V_1766 -> V_1821 ) * V_686 ,
V_135 ) ;
if ( ! V_1766 -> V_1821 ) {
V_35 = - V_136 ;
goto V_616;
}
F_39 (attr, mac_attr, rem)
memcpy ( V_1766 -> V_1821 [ V_160 ++ ] . V_698 , F_24 ( V_44 ) ,
sizeof( * V_1766 -> V_1821 ) ) ;
}
}
if ( V_94 [ V_1822 ] ) {
V_35 = F_417 ( V_94 [ V_1822 ] ,
V_1766 , true ) ;
if ( V_35 )
goto V_616;
}
if ( V_94 [ V_1823 ] ) {
V_35 = F_417 ( V_94 [ V_1823 ] ,
V_1766 , false ) ;
if ( V_35 )
goto V_616;
}
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 ) {
V_35 = - V_136 ;
goto V_616;
}
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1824 ) ;
if ( F_63 ( ! V_360 ) ) {
V_35 = - V_136 ;
goto V_616;
}
V_35 = F_420 ( V_7 , V_17 , V_1766 ) ;
V_616:
if ( V_35 < 0 ) {
F_421 ( V_1766 ) ;
F_77 ( V_52 ) ;
return V_35 ;
}
if ( F_105 ( V_52 , V_1577 , V_1766 -> V_668 ,
V_603 ) )
goto V_60;
V_1774 = F_48 ( V_52 , V_1775 ) ;
if ( ! V_1774 )
goto V_60;
if ( F_57 ( V_52 , V_1825 ,
V_1766 -> V_1826 ) )
goto V_60;
F_49 ( V_52 , V_1774 ) ;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
F_77 ( V_52 ) ;
return - V_90 ;
}
static int F_422 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
T_1 V_668 ;
if ( V_17 -> V_141 != V_154 )
return - V_557 ;
if ( ! F_407 ( V_17 ) )
return - V_1351 ;
if ( ! V_30 -> V_5 [ V_1577 ] )
return - V_16 ;
if ( V_17 -> V_655 &&
V_17 -> V_655 != V_30 -> V_521 )
return - V_1351 ;
V_668 = F_5 ( V_30 -> V_5 [ V_1577 ] ) ;
F_423 ( V_7 , V_17 , V_668 ) ;
return 0 ;
}
static int F_424 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
struct V_1755 V_1756 = {} ;
V_22 V_567 = 0 ;
if ( V_17 -> V_141 != V_154 )
return - V_557 ;
if ( ! F_407 ( V_17 ) )
return - V_1351 ;
if ( V_30 -> V_5 [ V_1758 ] ) {
V_1756 . V_1760 =
F_35 ( V_30 -> V_5 [ V_1758 ] ) ;
if ( V_1756 . V_1760 <= 1 || V_1756 . V_1760 == 255 )
return - V_16 ;
V_567 |= V_1827 ;
}
if ( V_30 -> V_5 [ V_1759 ] ) {
V_1756 . V_1761 = F_35 ( V_30 -> V_5 [ V_1759 ] ) ;
V_567 |= V_1828 ;
}
if ( ! V_567 )
return - V_16 ;
return F_425 ( V_7 , V_17 , & V_1756 , V_567 ) ;
}
void F_426 ( struct V_1 * V_17 ,
struct V_1829 * V_1655 , T_10 V_1521 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_4 * V_1830 , * V_1831 , * V_1832 ;
struct V_31 * V_52 ;
void * V_360 ;
if ( F_63 ( ! V_1655 -> V_1833 || ! V_1655 -> V_1834 || ! V_1655 -> V_698 ) )
return;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1835 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_52 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_60;
if ( F_105 ( V_52 , V_1577 , V_1655 -> V_668 ,
V_603 ) ||
F_52 ( V_52 , V_564 , V_604 , V_1655 -> V_698 ) )
goto V_60;
V_1830 = F_48 ( V_52 , V_1836 ) ;
if ( ! V_1830 )
goto V_60;
V_1831 = F_48 ( V_52 , V_1837 ) ;
if ( ! V_1831 )
goto V_60;
if ( F_57 ( V_52 , V_1825 , V_1655 -> V_1833 ) )
goto V_60;
F_49 ( V_52 , V_1831 ) ;
V_1832 = F_48 ( V_52 , V_1838 ) ;
if ( ! V_1832 )
goto V_60;
if ( F_57 ( V_52 , V_1779 , V_1655 -> type ) ||
F_57 ( V_52 , V_1825 , V_1655 -> V_1834 ) )
goto V_60;
if ( V_1655 -> V_30 && V_1655 -> V_1839 &&
F_52 ( V_52 , V_1785 , V_1655 -> V_1839 ,
V_1655 -> V_30 ) )
goto V_60;
F_49 ( V_52 , V_1832 ) ;
F_49 ( V_52 , V_1830 ) ;
F_68 ( V_52 , V_360 ) ;
if ( ! V_17 -> V_655 )
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_52 , 0 , V_1840 , V_1521 ) ;
else
F_427 ( F_7 ( & V_7 -> V_18 ) , V_52 ,
V_17 -> V_655 ) ;
return;
V_60:
F_77 ( V_52 ) ;
}
void F_428 ( struct V_1 * V_17 ,
T_2 V_1833 ,
enum V_1841 V_1547 ,
T_1 V_668 , T_10 V_1521 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_52 ;
struct V_4 * V_1774 ;
void * V_360 ;
if ( F_63 ( ! V_1833 ) )
return;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1842 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_52 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_60;
if ( F_105 ( V_52 , V_1577 , V_668 ,
V_603 ) )
goto V_60;
V_1774 = F_48 ( V_52 , V_1775 ) ;
if ( ! V_1774 )
goto V_60;
if ( F_57 ( V_52 , V_1825 , V_1833 ) ||
F_57 ( V_52 , V_1843 , V_1547 ) )
goto V_60;
F_49 ( V_52 , V_1774 ) ;
F_68 ( V_52 , V_360 ) ;
if ( ! V_17 -> V_655 )
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_52 , 0 , V_1840 , V_1521 ) ;
else
F_427 ( F_7 ( & V_7 -> V_18 ) , V_52 ,
V_17 -> V_655 ) ;
return;
V_60:
F_77 ( V_52 ) ;
}
static int F_429 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_360 ;
struct V_31 * V_52 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , V_30 -> V_521 , V_30 -> V_522 , 0 ,
V_1844 ) ;
if ( ! V_360 )
goto V_60;
if ( F_29 ( V_52 , V_1845 ,
V_1846 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_78 ( V_52 , V_30 ) ;
V_60:
F_319 ( V_52 ) ;
return - V_90 ;
}
static int F_430 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1847 V_1848 ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_1849 )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_1850 ] ||
! F_23 ( V_30 -> V_5 [ V_747 ] ) )
return - V_16 ;
memset ( & V_1848 , 0 , sizeof( V_1848 ) ) ;
V_1848 . V_1851 = F_80 ( V_30 -> V_5 [ V_1850 ] ) ;
V_1848 . V_1198 = F_24 ( V_30 -> V_5 [ V_747 ] ) ;
V_1848 . V_1199 = F_25 ( V_30 -> V_5 [ V_747 ] ) ;
return F_431 ( V_7 , V_556 , & V_1848 ) ;
}
static int F_432 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
enum V_1852 V_1460 = V_1853 ;
T_3 V_1292 ;
int V_513 ;
if ( ! V_7 -> V_328 -> V_444 )
return - V_557 ;
if ( F_63 ( ! V_7 -> V_328 -> V_446 ) )
return - V_16 ;
if ( V_7 -> V_1854 )
return - V_561 ;
if ( V_30 -> V_5 [ V_1855 ] )
V_1460 = F_80 ( V_30 -> V_5 [ V_1855 ] ) ;
if ( V_1460 >= V_1856 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1857 ] )
return - V_16 ;
V_1292 =
F_80 ( V_30 -> V_5 [ V_1857 ] ) ;
if ( V_1292 > V_1858 )
return - V_1732 ;
V_513 = F_433 ( V_7 , V_17 , V_1460 , V_1292 ) ;
if ( ! V_513 )
V_7 -> V_1854 = V_30 -> V_521 ;
return V_513 ;
}
static int F_434 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
if ( ! V_7 -> V_328 -> V_446 )
return - V_557 ;
if ( V_7 -> V_1854 ) {
V_7 -> V_1854 = 0 ;
F_435 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_436 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_96 ( V_30 ) , V_30 -> V_5 ) ;
int V_160 , V_35 ;
V_22 V_1859 , V_1525 ;
if ( ! V_7 -> V_18 . V_491 )
return - V_557 ;
if ( F_18 ( V_17 ) ) {
V_35 = F_19 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1522 ] ||
! V_30 -> V_5 [ V_1524 ] )
return - V_16 ;
V_1859 = F_4 ( V_30 -> V_5 [ V_1522 ] ) ;
V_1525 = F_4 ( V_30 -> V_5 [ V_1524 ] ) ;
for ( V_160 = 0 ; V_160 < V_7 -> V_18 . V_487 ; V_160 ++ ) {
const struct V_1860 * V_1861 ;
void * V_140 = NULL ;
int V_46 = 0 ;
V_1861 = & V_7 -> V_18 . V_491 [ V_160 ] ;
if ( V_1861 -> V_30 . V_1523 != V_1859 || V_1861 -> V_30 . V_1525 != V_1525 )
continue;
if ( V_1861 -> V_50 & ( V_1862 |
V_1863 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1861 -> V_50 & V_1863 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1861 -> V_50 & V_1864 ) {
if ( ! F_407 ( V_17 ) )
return - V_571 ;
}
if ( ! V_1861 -> V_1865 )
return - V_557 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_490 ] ) {
V_140 = F_24 ( V_30 -> V_5 [ V_490 ] ) ;
V_46 = F_25 ( V_30 -> V_5 [ V_490 ] ) ;
}
V_7 -> V_1534 = V_30 ;
V_35 = V_7 -> V_18 . V_491 [ V_160 ] . V_1865 ( & V_7 -> V_18 , V_17 ,
V_140 , V_46 ) ;
V_7 -> V_1534 = NULL ;
return V_35 ;
}
return - V_557 ;
}
static int F_437 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
struct V_4 * * V_1439 = F_16 ( & V_38 ) ;
V_22 V_1859 , V_1525 ;
unsigned int V_160 ;
int V_1866 = - 1 ;
int V_35 ;
void * V_140 = NULL ;
unsigned int V_1536 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
struct V_18 * V_18 = F_20 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 ) {
V_35 = - V_23 ;
goto V_42;
}
* V_7 = F_11 ( V_18 ) ;
* V_17 = NULL ;
if ( V_34 -> args [ 1 ] ) {
F_6 (tmp, &wiphy->wdev_list, list) {
if ( V_24 -> V_21 == V_34 -> args [ 1 ] - 1 ) {
* V_17 = V_24 ;
break;
}
}
}
return 0 ;
}
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_1439 , V_38 . V_40 , V_41 ) ;
if ( V_35 )
goto V_42;
if ( ! V_1439 [ V_1522 ] ||
! V_1439 [ V_1524 ] ) {
V_35 = - V_16 ;
goto V_42;
}
* V_17 = F_1 ( F_17 ( V_32 -> V_43 ) , V_1439 ) ;
if ( F_18 ( * V_17 ) )
* V_17 = NULL ;
* V_7 = F_8 ( F_17 ( V_32 -> V_43 ) , V_1439 ) ;
if ( F_18 ( * V_7 ) ) {
V_35 = F_19 ( * V_7 ) ;
goto V_42;
}
V_1859 = F_4 ( V_1439 [ V_1522 ] ) ;
V_1525 = F_4 ( V_1439 [ V_1524 ] ) ;
for ( V_160 = 0 ; V_160 < ( * V_7 ) -> V_18 . V_487 ; V_160 ++ ) {
const struct V_1860 * V_1861 ;
V_1861 = & ( * V_7 ) -> V_18 . V_491 [ V_160 ] ;
if ( V_1861 -> V_30 . V_1523 != V_1859 || V_1861 -> V_30 . V_1525 != V_1525 )
continue;
if ( ! V_1861 -> V_1867 ) {
V_35 = - V_557 ;
goto V_42;
}
V_1866 = V_160 ;
break;
}
if ( V_1866 < 0 ) {
V_35 = - V_557 ;
goto V_42;
}
if ( V_1439 [ V_490 ] ) {
V_140 = F_24 ( V_1439 [ V_490 ] ) ;
V_1536 = F_25 ( V_1439 [ V_490 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1866 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_140 ;
V_34 -> args [ 4 ] = V_1536 ;
return 0 ;
V_42:
F_21 () ;
return V_35 ;
}
static int F_438 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
unsigned int V_1866 ;
const struct V_1860 * V_1861 ;
void * V_140 ;
int V_1536 ;
int V_35 ;
struct V_4 * V_1868 ;
V_35 = F_437 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
V_1866 = V_34 -> args [ 2 ] ;
V_140 = ( void * ) V_34 -> args [ 3 ] ;
V_1536 = V_34 -> args [ 4 ] ;
V_1861 = & V_7 -> V_18 . V_491 [ V_1866 ] ;
if ( V_1861 -> V_50 & ( V_1862 |
V_1863 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1861 -> V_50 & V_1863 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1861 -> V_50 & V_1864 ) {
if ( ! F_407 ( V_17 ) )
return - V_571 ;
}
}
while ( 1 ) {
void * V_360 = F_26 ( V_32 , F_73 ( V_34 -> V_32 ) . V_48 ,
V_34 -> V_36 -> V_517 , V_518 ,
V_1528 ) ;
if ( ! V_360 )
break;
if ( F_29 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_105 ( V_32 , V_12 ,
V_13 ( V_17 ) ,
V_603 ) ) ) {
F_69 ( V_32 , V_360 ) ;
break;
}
V_1868 = F_48 ( V_32 , V_490 ) ;
if ( ! V_1868 ) {
F_69 ( V_32 , V_360 ) ;
break;
}
V_35 = V_1861 -> V_1867 ( & V_7 -> V_18 , V_17 , V_32 , V_140 , V_1536 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_49 ( V_32 , V_1868 ) ;
if ( V_35 == - V_90 || V_35 == - V_676 ) {
F_69 ( V_32 , V_360 ) ;
break;
} else if ( V_35 ) {
F_69 ( V_32 , V_360 ) ;
goto V_616;
}
F_68 ( V_32 , V_360 ) ;
}
V_35 = V_32 -> V_46 ;
V_616:
F_21 () ;
return V_35 ;
}
struct V_31 * F_439 ( struct V_18 * V_18 ,
enum V_357 V_51 ,
enum V_832 V_44 ,
int V_1520 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_63 ( ! V_7 -> V_1534 ) )
return NULL ;
return F_318 ( V_7 , NULL , V_1520 ,
V_7 -> V_1534 -> V_521 ,
V_7 -> V_1534 -> V_522 ,
V_51 , V_44 , NULL , V_135 ) ;
}
int F_440 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_360 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_140 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_63 ( ! V_7 -> V_1534 ) ) {
F_319 ( V_32 ) ;
return - V_16 ;
}
F_49 ( V_32 , V_140 ) ;
F_68 ( V_32 , V_360 ) ;
return F_78 ( V_32 , V_7 -> V_1534 ) ;
}
static int F_441 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_1869 * V_1870 = NULL ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
T_2 * V_45 , V_46 , V_1871 , V_1872 , V_1873 ;
int V_513 ;
if ( ! V_7 -> V_328 -> V_451 )
return - V_557 ;
if ( V_30 -> V_5 [ V_1874 ] ) {
V_45 = F_24 ( V_30 -> V_5 [ V_1874 ] ) ;
V_46 = F_25 ( V_30 -> V_5 [ V_1874 ] ) ;
if ( V_46 % 2 || V_46 < V_1875 ||
V_46 > V_1876 )
return - V_16 ;
V_1870 = F_40 ( sizeof( struct V_1869 ) , V_135 ) ;
if ( ! V_1870 )
return - V_136 ;
V_1871 = ( V_46 - V_1875 ) >> 1 ;
if ( V_1871 ) {
V_1872 = V_1871 *
sizeof( struct V_1877 ) ;
memcpy ( V_1870 -> V_1878 , V_45 , V_1872 ) ;
V_1870 -> V_1871 = V_1871 ;
for ( V_1873 = 0 ; V_1873 < V_1871 ; V_1873 ++ ) {
if ( V_1870 -> V_1878 [ V_1873 ] . V_1879 > 7 ) {
F_42 ( V_1870 ) ;
return - V_16 ;
}
}
V_45 += V_1872 ;
}
memcpy ( V_1870 -> V_1879 , V_45 , V_1875 ) ;
}
F_114 ( V_556 -> V_28 ) ;
V_513 = F_43 ( V_556 -> V_28 ) ;
if ( ! V_513 )
V_513 = F_442 ( V_7 , V_556 , V_1870 ) ;
F_116 ( V_556 -> V_28 ) ;
F_42 ( V_1870 ) ;
return V_513 ;
}
static int F_443 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
const T_2 * V_1564 ;
T_2 V_1880 , V_1879 ;
T_3 V_1881 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_368 & V_453 ) )
return - V_557 ;
if ( ! V_30 -> V_5 [ V_1882 ] || ! V_30 -> V_5 [ V_564 ] ||
! V_30 -> V_5 [ V_1883 ] )
return - V_16 ;
V_1880 = F_35 ( V_30 -> V_5 [ V_1882 ] ) ;
if ( V_1880 >= V_935 )
return - V_16 ;
V_1879 = F_35 ( V_30 -> V_5 [ V_1883 ] ) ;
if ( V_1879 >= V_1884 )
return - V_16 ;
if ( V_1880 >= V_1885 ) {
return - V_16 ;
}
V_1564 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
if ( V_30 -> V_5 [ V_1886 ] ) {
V_1881 =
F_80 ( V_30 -> V_5 [ V_1886 ] ) ;
if ( ! V_1881 )
return - V_16 ;
}
F_114 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1351 ;
goto V_616;
default:
V_35 = - V_557 ;
goto V_616;
}
V_35 = F_444 ( V_7 , V_556 , V_1880 , V_1564 , V_1879 , V_1881 ) ;
V_616:
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_445 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
const T_2 * V_1564 ;
T_2 V_1880 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1882 ] || ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_1880 = F_35 ( V_30 -> V_5 [ V_1882 ] ) ;
V_1564 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
F_114 ( V_17 ) ;
V_35 = F_446 ( V_7 , V_556 , V_1880 , V_1564 ) ;
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_447 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_536 V_537 = {} ;
const T_2 * V_698 ;
T_2 V_1887 ;
int V_35 ;
if ( ! V_7 -> V_328 -> V_1888 ||
! ( V_7 -> V_18 . V_368 & V_1889 ) )
return - V_557 ;
switch ( V_556 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_557 ;
}
if ( ! V_30 -> V_5 [ V_564 ] ||
! V_30 -> V_5 [ V_1890 ] )
return - V_16 ;
V_35 = F_82 ( V_7 , V_30 , & V_537 ) ;
if ( V_35 )
return V_35 ;
if ( V_537 . V_54 -> V_367 == V_1891 &&
V_537 . V_540 != V_541 &&
V_537 . V_540 != V_596 )
return - V_16 ;
if ( ! F_87 ( & V_7 -> V_18 , & V_537 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( F_282 ( V_17 -> V_18 , & V_537 , V_17 -> V_141 ) )
return - V_16 ;
V_698 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
V_1887 = F_35 ( V_30 -> V_5 [ V_1890 ] ) ;
F_114 ( V_17 ) ;
V_35 = F_448 ( V_7 , V_556 , V_698 , V_1887 , & V_537 ) ;
F_116 ( V_17 ) ;
return V_35 ;
}
static int F_449 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
const T_2 * V_698 ;
if ( ! V_7 -> V_328 -> V_1888 ||
! V_7 -> V_328 -> V_1892 ||
! ( V_7 -> V_18 . V_368 & V_1889 ) )
return - V_557 ;
switch ( V_556 -> V_28 -> V_141 ) {
case V_147 :
case V_148 :
break;
default:
return - V_557 ;
}
if ( ! V_30 -> V_5 [ V_564 ] )
return - V_16 ;
V_698 = F_24 ( V_30 -> V_5 [ V_564 ] ) ;
F_114 ( V_17 ) ;
F_450 ( V_7 , V_556 , V_698 ) ;
F_116 ( V_17 ) ;
return 0 ;
}
static int F_451 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_520 [ 0 ] ;
struct V_25 * V_556 = V_30 -> V_520 [ 1 ] ;
struct V_1 * V_17 = V_556 -> V_28 ;
const struct V_4 * V_618 ;
bool V_1893 ;
if ( F_93 ( V_556 ) )
return - V_561 ;
if ( ! V_7 -> V_328 -> V_456 )
return - V_557 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_557 ;
V_618 = V_30 -> V_5 [ V_1894 ] ;
V_1893 = F_167 ( V_618 ) ;
return F_452 ( V_7 , V_556 , V_1893 ) ;
}
static int F_453 ( const struct V_1895 * V_328 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_556 ;
bool V_1896 = V_328 -> V_1897 & V_1898 ;
if ( V_1896 )
F_14 () ;
if ( V_328 -> V_1897 & V_1899 ) {
V_7 = F_12 ( F_96 ( V_30 ) , V_30 ) ;
if ( F_18 ( V_7 ) ) {
if ( V_1896 )
F_21 () ;
return F_19 ( V_7 ) ;
}
V_30 -> V_520 [ 0 ] = V_7 ;
} else if ( V_328 -> V_1897 & V_1900 ||
V_328 -> V_1897 & V_1901 ) {
F_2 () ;
V_17 = F_1 ( F_96 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_18 ( V_17 ) ) {
if ( V_1896 )
F_21 () ;
return F_19 ( V_17 ) ;
}
V_556 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_328 -> V_1897 & V_1900 ) {
if ( ! V_556 ) {
if ( V_1896 )
F_21 () ;
return - V_16 ;
}
V_30 -> V_520 [ 1 ] = V_556 ;
} else {
V_30 -> V_520 [ 1 ] = V_17 ;
}
if ( V_328 -> V_1897 & V_1902 &&
! F_407 ( V_17 ) ) {
if ( V_1896 )
F_21 () ;
return - V_571 ;
}
if ( V_556 )
F_266 ( V_556 ) ;
V_30 -> V_520 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_454 ( const struct V_1895 * V_328 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_520 [ 1 ] ) {
if ( V_328 -> V_1897 & V_1901 ) {
struct V_1 * V_17 = V_30 -> V_520 [ 1 ] ;
if ( V_17 -> V_19 )
F_188 ( V_17 -> V_19 ) ;
} else {
F_188 ( V_30 -> V_520 [ 1 ] ) ;
}
}
if ( V_328 -> V_1897 & V_1898 )
F_21 () ;
if ( V_328 -> V_1897 & V_1903 ) {
struct V_1904 * V_36 = F_455 ( V_32 ) ;
memset ( F_456 ( V_36 ) , 0 , F_457 ( V_36 ) ) ;
}
}
void F_458 ( struct V_6 * V_7 ,
enum V_357 V_51 )
{
struct V_31 * V_52 ;
struct V_358 V_359 = {} ;
F_63 ( V_51 != V_372 &&
V_51 != V_1905 ) ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
if ( F_62 ( V_7 , V_51 , V_52 , 0 , 0 , 0 , & V_359 ) < 0 ) {
F_77 ( V_52 ) ;
return;
}
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1906 , V_135 ) ;
}
void F_129 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
enum V_357 V_51 )
{
struct V_31 * V_52 ;
F_63 ( V_51 != V_599 &&
V_51 != V_600 ) ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
if ( F_104 ( V_52 , 0 , 0 , 0 , V_7 , V_17 ,
V_51 == V_600 ) < 0 ) {
F_77 ( V_52 ) ;
return;
}
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1906 , V_135 ) ;
}
static int F_459 ( struct V_31 * V_52 ,
struct V_6 * V_7 )
{
struct V_1278 * V_1476 = V_7 -> V_1282 ;
struct V_4 * V_1264 ;
int V_160 ;
if ( F_63 ( ! V_1476 ) )
return 0 ;
V_1264 = F_48 ( V_52 , V_1286 ) ;
if ( ! V_1264 )
goto V_60;
for ( V_160 = 0 ; V_160 < V_1476 -> V_1280 ; V_160 ++ ) {
if ( F_52 ( V_52 , V_160 , V_1476 -> V_1287 [ V_160 ] . V_609 , V_1476 -> V_1287 [ V_160 ] . V_611 ) )
goto V_60;
}
F_49 ( V_52 , V_1264 ) ;
V_1264 = F_48 ( V_52 , V_1285 ) ;
if ( ! V_1264 )
goto V_60;
for ( V_160 = 0 ; V_160 < V_1476 -> V_441 ; V_160 ++ ) {
if ( F_29 ( V_52 , V_160 , V_1476 -> V_442 [ V_160 ] -> V_59 ) )
goto V_60;
}
F_49 ( V_52 , V_1264 ) ;
if ( V_1476 -> V_1198 &&
F_52 ( V_52 , V_747 , V_1476 -> V_1199 , V_1476 -> V_1198 ) )
goto V_60;
if ( V_1476 -> V_50 &&
F_29 ( V_52 , V_1295 , V_1476 -> V_50 ) )
goto V_60;
if ( V_1476 -> V_30 . V_1907 &&
( F_105 ( V_52 , V_1908 ,
V_1476 -> V_30 . V_1907 , V_1383 ) ||
F_52 ( V_52 , V_1909 , V_604 ,
V_1476 -> V_30 . V_1910 ) ) )
goto V_60;
return 0 ;
V_60:
return - V_90 ;
}
static int F_460 ( struct V_31 * V_52 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_48 , V_22 V_49 , int V_50 ,
V_22 V_51 )
{
void * V_360 ;
V_360 = F_26 ( V_52 , V_48 , V_49 , V_50 , V_51 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_52 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_60;
F_459 ( V_52 , V_7 ) ;
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
static int
F_461 ( struct V_31 * V_52 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_48 , V_22 V_49 , int V_50 , V_22 V_51 )
{
void * V_360 ;
V_360 = F_26 ( V_52 , V_48 , V_49 , V_50 , V_51 ) ;
if ( ! V_360 )
return - 1 ;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return 0 ;
V_60:
F_69 ( V_52 , V_360 ) ;
return - V_512 ;
}
void F_265 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_52 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
if ( F_460 ( V_52 , V_7 , V_17 , 0 , 0 , 0 ,
V_1911 ) < 0 ) {
F_77 ( V_52 ) ;
return;
}
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1912 , V_135 ) ;
}
struct V_31 * F_462 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1913 )
{
struct V_31 * V_52 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return NULL ;
if ( F_460 ( V_52 , V_7 , V_17 , 0 , 0 , 0 ,
V_1913 ? V_1914 :
V_1375 ) < 0 ) {
F_77 ( V_52 ) ;
return NULL ;
}
return V_52 ;
}
void F_463 ( struct V_6 * V_7 ,
struct V_31 * V_52 )
{
if ( ! V_52 )
return;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1912 , V_135 ) ;
}
void F_464 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_52 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
if ( F_461 ( V_52 , V_7 , V_19 , 0 , 0 , 0 ,
V_1915 ) < 0 ) {
F_77 ( V_52 ) ;
return;
}
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1912 , V_135 ) ;
}
void F_276 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_51 )
{
struct V_31 * V_52 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
if ( F_461 ( V_52 , V_7 , V_19 , 0 , 0 , 0 , V_51 ) < 0 ) {
F_77 ( V_52 ) ;
return;
}
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1912 , V_135 ) ;
}
static bool F_465 ( struct V_31 * V_52 ,
struct V_1916 * V_1279 )
{
if ( F_57 ( V_52 , V_1917 , V_1279 -> V_1565 ) )
goto V_60;
if ( V_1279 -> V_1212 [ 0 ] == '0' && V_1279 -> V_1212 [ 1 ] == '0' ) {
if ( F_57 ( V_52 , V_1918 ,
V_1919 ) )
goto V_60;
} else if ( V_1279 -> V_1212 [ 0 ] == '9' && V_1279 -> V_1212 [ 1 ] == '9' ) {
if ( F_57 ( V_52 , V_1918 ,
V_1920 ) )
goto V_60;
} else if ( ( V_1279 -> V_1212 [ 0 ] == '9' && V_1279 -> V_1212 [ 1 ] == '8' ) ||
V_1279 -> V_1921 ) {
if ( F_57 ( V_52 , V_1918 ,
V_1922 ) )
goto V_60;
} else {
if ( F_57 ( V_52 , V_1918 ,
V_1923 ) ||
F_64 ( V_52 , V_1100 ,
V_1279 -> V_1212 ) )
goto V_60;
}
if ( V_1279 -> V_14 != V_1924 ) {
struct V_18 * V_18 = F_20 ( V_1279 -> V_14 ) ;
if ( V_18 &&
F_29 ( V_52 , V_26 , V_1279 -> V_14 ) )
goto V_60;
if ( V_18 &&
V_18 -> V_497 & V_498 &&
F_30 ( V_52 , V_499 ) )
goto V_60;
}
return true ;
V_60:
return false ;
}
void F_466 ( enum V_357 V_1925 ,
struct V_1916 * V_1279 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1925 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_465 ( V_52 , V_1279 ) == false )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_241 () ;
F_467 ( & V_38 , V_52 , 0 ,
V_1926 , V_1927 ) ;
F_243 () ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
static void F_468 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1588 , T_9 V_46 ,
enum V_357 V_51 , T_10 V_1521 ,
int V_991 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_51 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
F_52 ( V_52 , V_1585 , V_46 , V_1588 ) )
goto V_60;
if ( V_991 >= 0 ) {
struct V_4 * V_1928 =
F_48 ( V_52 , V_988 ) ;
if ( ! V_1928 )
goto V_60;
if ( F_57 ( V_52 , V_990 ,
V_991 ) )
goto V_60;
F_49 ( V_52 , V_1928 ) ;
}
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_469 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1588 ,
T_9 V_46 , T_10 V_1521 )
{
F_468 ( V_7 , V_19 , V_1588 , V_46 ,
V_768 , V_1521 , - 1 ) ;
}
void F_470 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1588 ,
T_9 V_46 , T_10 V_1521 , int V_991 )
{
F_468 ( V_7 , V_19 , V_1588 , V_46 ,
V_1930 , V_1521 , V_991 ) ;
}
void F_471 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1588 ,
T_9 V_46 , T_10 V_1521 )
{
F_468 ( V_7 , V_19 , V_1588 , V_46 ,
V_1931 , V_1521 , - 1 ) ;
}
void F_472 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1588 ,
T_9 V_46 , T_10 V_1521 )
{
F_468 ( V_7 , V_19 , V_1588 , V_46 ,
V_1932 , V_1521 , - 1 ) ;
}
void F_473 ( struct V_25 * V_556 , const T_2 * V_1588 ,
T_9 V_46 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1933 * V_1934 = ( void * ) V_1588 ;
V_22 V_51 ;
if ( F_63 ( V_46 < 2 ) )
return;
if ( F_474 ( V_1934 -> V_1935 ) )
V_51 = V_1936 ;
else
V_51 = V_1937 ;
F_475 ( V_556 , V_1588 , V_46 ) ;
F_468 ( V_7 , V_556 , V_1588 , V_46 , V_51 , V_1927 , - 1 ) ;
}
static void F_476 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_51 ,
const T_2 * V_698 , T_10 V_1521 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_51 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
F_30 ( V_52 , V_1938 ) ||
F_52 ( V_52 , V_564 , V_604 , V_698 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_477 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_698 ,
T_10 V_1521 )
{
F_476 ( V_7 , V_19 , V_768 ,
V_698 , V_1521 ) ;
}
void F_478 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_698 ,
T_10 V_1521 )
{
F_476 ( V_7 , V_19 , V_1930 ,
V_698 , V_1521 ) ;
}
void F_479 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_563 ,
const T_2 * V_1939 , T_9 V_1940 ,
const T_2 * V_1941 , T_9 V_1942 ,
int V_1943 , T_10 V_1521 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_354 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
( V_563 && F_52 ( V_52 , V_564 , V_604 , V_563 ) ) ||
F_56 ( V_52 , V_1567 ,
V_1943 < 0 ? V_1944 :
V_1943 ) ||
( V_1943 < 0 && F_30 ( V_52 , V_1938 ) ) ||
( V_1939 &&
F_52 ( V_52 , V_1945 , V_1940 , V_1939 ) ) ||
( V_1941 &&
F_52 ( V_52 , V_1946 , V_1942 , V_1941 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_480 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_563 ,
const T_2 * V_1939 , T_9 V_1940 ,
const T_2 * V_1941 , T_9 V_1942 , T_10 V_1521 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1947 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_563 ) ||
( V_1939 &&
F_52 ( V_52 , V_1945 , V_1940 , V_1939 ) ) ||
( V_1941 &&
F_52 ( V_52 , V_1946 , V_1942 , V_1941 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_481 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1547 ,
const T_2 * V_1198 , T_9 V_1199 , bool V_1948 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_356 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
( V_1948 && V_1547 &&
F_56 ( V_52 , V_1039 , V_1547 ) ) ||
( V_1948 &&
F_30 ( V_52 , V_1949 ) ) ||
( V_1198 && F_52 ( V_52 , V_747 , V_1199 , V_1198 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_135 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_482 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_563 ,
T_10 V_1521 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1950 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_563 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_483 ( struct V_25 * V_556 , const T_2 * V_698 ,
const T_2 * V_1198 , T_2 V_1199 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
if ( F_63 ( V_17 -> V_141 != V_145 ) )
return;
F_484 ( V_556 , V_698 ) ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1951 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_698 ) ||
( V_1199 && V_1198 &&
F_52 ( V_52 , V_747 , V_1199 , V_1198 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_485 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_698 ,
enum V_1952 V_1953 , int V_1954 ,
const T_2 * V_1955 , T_10 V_1521 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1956 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
( V_698 && F_52 ( V_52 , V_564 , V_604 , V_698 ) ) ||
F_29 ( V_52 , V_126 , V_1953 ) ||
( V_1954 != - 1 &&
F_57 ( V_52 , V_122 , V_1954 ) ) ||
( V_1955 && F_52 ( V_52 , V_121 , 6 , V_1955 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_486 ( struct V_18 * V_18 ,
struct V_53 * V_1957 ,
struct V_53 * V_1958 )
{
struct V_31 * V_52 ;
void * V_360 ;
struct V_4 * V_364 ;
V_52 = F_76 ( V_617 , V_1927 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1959 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , F_239 ( V_18 ) ) )
goto V_60;
V_364 = F_48 ( V_52 , V_1960 ) ;
if ( ! V_364 )
goto V_60;
if ( F_28 ( V_52 , V_1957 , false ) )
goto V_60;
F_49 ( V_52 , V_364 ) ;
V_364 = F_48 ( V_52 , V_1961 ) ;
if ( ! V_364 )
goto V_60;
if ( F_28 ( V_52 , V_1958 , false ) )
goto V_60;
F_49 ( V_52 , V_364 ) ;
F_68 ( V_52 , V_360 ) ;
F_241 () ;
F_467 ( & V_38 , V_52 , 0 ,
V_1926 , V_1927 ) ;
F_243 () ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
static void F_487 (
int V_51 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_668 ,
struct V_53 * V_54 ,
unsigned int V_1292 , T_10 V_1521 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_51 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_29 ( V_52 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) ||
F_29 ( V_52 , V_539 , V_54 -> V_59 ) ||
F_29 ( V_52 , V_544 ,
V_547 ) ||
F_105 ( V_52 , V_1577 , V_668 ,
V_603 ) )
goto V_60;
if ( V_51 == V_1576 &&
F_29 ( V_52 , V_1574 , V_1292 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_488 ( struct V_1 * V_17 , T_1 V_668 ,
struct V_53 * V_54 ,
unsigned int V_1292 , T_10 V_1521 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_489 ( V_17 , V_668 , V_54 , V_1292 ) ;
F_487 ( V_1576 ,
V_7 , V_17 , V_668 , V_54 ,
V_1292 , V_1521 ) ;
}
void F_490 ( struct V_1 * V_17 , T_1 V_668 ,
struct V_53 * V_54 ,
T_10 V_1521 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_491 ( V_17 , V_668 , V_54 ) ;
F_487 ( V_1962 ,
V_7 , V_17 , V_668 , V_54 , 0 , V_1521 ) ;
}
void F_492 ( struct V_25 * V_556 , const T_2 * V_670 ,
struct V_857 * V_858 , T_10 V_1521 )
{
struct V_18 * V_18 = V_556 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_52 ;
F_493 ( V_556 , V_670 , V_858 ) ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
if ( F_177 ( V_52 , V_953 , 0 , 0 , 0 ,
V_7 , V_556 , V_670 , V_858 ) < 0 ) {
F_77 ( V_52 ) ;
return;
}
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
}
void F_494 ( struct V_25 * V_556 , const T_2 * V_670 ,
struct V_857 * V_858 , T_10 V_1521 )
{
struct V_18 * V_18 = V_556 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_52 ;
struct V_857 V_1963 = {} ;
if ( ! V_858 )
V_858 = & V_1963 ;
F_495 ( V_556 , V_670 ) ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
if ( F_177 ( V_52 , V_1964 , 0 , 0 , 0 ,
V_7 , V_556 , V_670 , V_858 ) < 0 ) {
F_77 ( V_52 ) ;
return;
}
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
}
void F_496 ( struct V_25 * V_556 , const T_2 * V_670 ,
enum V_1965 V_1547 ,
T_10 V_1521 )
{
struct V_18 * V_18 = V_556 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_1966 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1967 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_670 ) ||
F_29 ( V_52 , V_1968 , V_1547 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
static bool F_497 ( struct V_25 * V_556 , T_2 V_51 ,
const T_2 * V_698 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
V_22 V_1748 = F_498 ( V_17 -> V_1741 ) ;
if ( ! V_1748 )
return false ;
V_52 = F_76 ( 100 , V_1521 ) ;
if ( ! V_52 )
return true ;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_51 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return true ;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_698 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_427 ( F_7 ( & V_7 -> V_18 ) , V_52 , V_1748 ) ;
return true ;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
return true ;
}
bool F_499 ( struct V_25 * V_556 ,
const T_2 * V_698 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
bool V_513 ;
F_500 ( V_556 , V_698 ) ;
if ( F_63 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_501 ( false ) ;
return false ;
}
V_513 = F_497 ( V_556 , V_1969 ,
V_698 , V_1521 ) ;
F_501 ( V_513 ) ;
return V_513 ;
}
bool F_502 ( struct V_25 * V_556 ,
const T_2 * V_698 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
bool V_513 ;
F_503 ( V_556 , V_698 ) ;
if ( F_63 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_501 ( false ) ;
return false ;
}
V_513 = F_497 ( V_556 ,
V_1970 ,
V_698 , V_1521 ) ;
F_501 ( V_513 ) ;
return V_513 ;
}
int F_504 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1748 ,
int V_1971 , int V_1972 ,
const T_2 * V_1588 , T_9 V_46 , V_22 V_50 , T_10 V_1521 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return - V_136 ;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1592 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return - V_136 ;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_29 ( V_52 , V_10 ,
V_19 -> V_20 ) ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) ||
F_29 ( V_52 , V_539 , V_1971 ) ||
( V_1972 &&
F_29 ( V_52 , V_1973 , V_1972 ) ) ||
F_52 ( V_52 , V_1585 , V_46 , V_1588 ) ||
( V_50 &&
F_29 ( V_52 , V_1974 , V_50 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
return F_427 ( F_7 ( & V_7 -> V_18 ) , V_52 , V_1748 ) ;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
return - V_90 ;
}
void F_505 ( struct V_1 * V_17 , T_1 V_668 ,
const T_2 * V_1588 , T_9 V_46 , bool V_1975 , T_10 V_1521 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_52 ;
void * V_360 ;
F_506 ( V_17 , V_668 , V_1975 ) ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1976 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_29 ( V_52 , V_10 ,
V_19 -> V_20 ) ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) ||
F_52 ( V_52 , V_1585 , V_46 , V_1588 ) ||
F_105 ( V_52 , V_1577 , V_668 ,
V_603 ) ||
( V_1975 && F_30 ( V_52 , V_1977 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
static struct V_31 * F_507 ( struct V_25 * V_556 ,
const char * V_1033 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_52 = F_76 ( V_617 , V_1521 ) ;
void * * V_34 ;
if ( ! V_52 )
return NULL ;
V_34 = ( void * * ) V_52 -> V_34 ;
V_34 [ 0 ] = F_26 ( V_52 , 0 , 0 , 0 , V_1978 ) ;
if ( ! V_34 [ 0 ] ) {
F_77 ( V_52 ) ;
return NULL ;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_556 -> V_20 ) )
goto V_60;
if ( V_1033 && F_52 ( V_52 , V_564 , V_604 , V_1033 ) )
goto V_60;
V_34 [ 1 ] = F_48 ( V_52 , V_1611 ) ;
if ( ! V_34 [ 1 ] )
goto V_60;
V_34 [ 2 ] = V_7 ;
return V_52 ;
V_60:
F_77 ( V_52 ) ;
return NULL ;
}
static void F_508 ( struct V_31 * V_52 , T_10 V_1521 )
{
void * * V_34 = ( void * * ) V_52 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_49 ( V_52 , V_34 [ 1 ] ) ;
F_68 ( V_52 , V_34 [ 0 ] ) ;
memset ( V_52 -> V_34 , 0 , sizeof( V_52 -> V_34 ) ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
}
void F_509 ( struct V_25 * V_556 ,
enum V_1979 V_1980 ,
T_10 V_1521 )
{
struct V_31 * V_52 ;
F_510 ( V_556 , V_1980 ) ;
if ( F_63 ( V_1980 != V_1981 &&
V_1980 != V_1982 ) )
return;
V_52 = F_507 ( V_556 , NULL , V_1521 ) ;
if ( ! V_52 )
return;
if ( F_29 ( V_52 , V_1983 ,
V_1980 ) )
goto V_60;
F_508 ( V_52 , V_1521 ) ;
return;
V_60:
F_77 ( V_52 ) ;
}
void F_511 ( struct V_25 * V_556 ,
const T_2 * V_1564 , V_22 V_1984 ,
V_22 V_247 , V_22 V_1603 , T_10 V_1521 )
{
struct V_31 * V_52 ;
V_52 = F_507 ( V_556 , V_1564 , V_1521 ) ;
if ( ! V_52 )
return;
if ( F_29 ( V_52 , V_1616 , V_1984 ) )
goto V_60;
if ( F_29 ( V_52 , V_1615 , V_247 ) )
goto V_60;
if ( F_29 ( V_52 , V_1617 , V_1603 ) )
goto V_60;
F_508 ( V_52 , V_1521 ) ;
return;
V_60:
F_77 ( V_52 ) ;
}
void F_512 ( struct V_25 * V_556 ,
const T_2 * V_1564 , V_22 V_1984 , T_10 V_1521 )
{
struct V_31 * V_52 ;
F_513 ( V_556 , V_1564 , V_1984 ) ;
V_52 = F_507 ( V_556 , V_1564 , V_1521 ) ;
if ( ! V_52 )
return;
if ( F_29 ( V_52 , V_1985 , V_1984 ) )
goto V_60;
F_508 ( V_52 , V_1521 ) ;
return;
V_60:
F_77 ( V_52 ) ;
}
void F_514 ( struct V_25 * V_556 , T_10 V_1521 )
{
struct V_31 * V_52 ;
V_52 = F_507 ( V_556 , NULL , V_1521 ) ;
if ( ! V_52 )
return;
if ( F_30 ( V_52 , V_1986 ) )
goto V_60;
F_508 ( V_52 , V_1521 ) ;
return;
V_60:
F_77 ( V_52 ) ;
}
static void F_515 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_563 ,
const T_2 * V_1739 , T_10 V_1521 )
{
struct V_31 * V_52 ;
struct V_4 * V_1987 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1988 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_563 ) )
goto V_60;
V_1987 = F_48 ( V_52 , V_1727 ) ;
if ( ! V_1987 )
goto V_60;
if ( F_52 ( V_52 , V_1730 ,
V_1731 , V_1739 ) )
goto V_60;
F_49 ( V_52 , V_1987 ) ;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_516 ( struct V_25 * V_556 , const T_2 * V_563 ,
const T_2 * V_1739 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_517 ( V_556 , V_563 ) ;
F_515 ( V_7 , V_556 , V_563 , V_1739 , V_1521 ) ;
}
static void
F_518 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1989 ,
const T_2 * V_563 , bool V_1990 , T_10 V_1521 )
{
struct V_31 * V_52 ;
struct V_4 * V_44 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1991 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) )
goto V_60;
V_44 = F_48 ( V_52 , V_1992 ) ;
if ( ! V_44 )
goto V_60;
if ( F_29 ( V_52 , V_1993 , V_1989 ) ||
F_52 ( V_52 , V_1994 , V_604 , V_563 ) ||
( V_1990 &&
F_30 ( V_52 , V_1995 ) ) )
goto V_60;
F_49 ( V_52 , V_44 ) ;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_519 ( struct V_25 * V_556 , int V_1989 ,
const T_2 * V_563 , bool V_1990 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_520 ( V_556 , V_1989 , V_563 , V_1990 ) ;
F_518 ( V_7 , V_556 , V_1989 , V_563 , V_1990 , V_1521 ) ;
}
static void F_521 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_536 * V_537 ,
T_10 V_1521 ,
enum V_357 V_1996 ,
T_2 V_1354 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1996 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_10 , V_19 -> V_20 ) )
goto V_60;
if ( F_102 ( V_52 , V_537 ) )
goto V_60;
if ( ( V_1996 == V_1997 ) &&
( F_29 ( V_52 , V_1352 , V_1354 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_522 ( struct V_25 * V_556 ,
struct V_536 * V_537 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_44 ( V_17 ) ;
F_523 ( V_556 , V_537 ) ;
V_17 -> V_537 = * V_537 ;
V_17 -> V_562 = * V_537 ;
F_521 ( V_7 , V_556 , V_537 , V_135 ,
V_1998 , 0 ) ;
}
void F_524 ( struct V_25 * V_556 ,
struct V_536 * V_537 ,
T_2 V_1354 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_525 ( V_556 , V_537 ) ;
F_521 ( V_7 , V_556 , V_537 , V_135 ,
V_1997 , V_1354 ) ;
}
void
F_526 ( struct V_6 * V_7 ,
const struct V_536 * V_537 ,
enum V_1999 V_2000 ,
struct V_25 * V_19 , T_10 V_1521 )
{
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_2001 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) )
goto V_60;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_60;
}
if ( F_29 ( V_52 , V_2002 , V_2000 ) )
goto V_60;
if ( F_102 ( V_52 , V_537 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_527 ( struct V_25 * V_556 , const T_2 * V_698 ,
T_1 V_668 , bool V_2003 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
F_528 ( V_556 , V_698 , V_668 , V_2003 ) ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1742 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_698 ) ||
F_105 ( V_52 , V_1577 , V_668 ,
V_603 ) ||
( V_2003 && F_30 ( V_52 , V_1977 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_529 ( struct V_18 * V_18 ,
const T_2 * V_2004 , T_9 V_46 ,
int V_1971 , int V_1972 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
struct V_1743 * V_1744 ;
F_530 ( V_18 , V_2004 , V_46 , V_1971 , V_1972 ) ;
F_292 ( & V_7 -> V_1747 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_52 = F_76 ( V_46 + 100 , V_1927 ) ;
if ( ! V_52 ) {
F_294 ( & V_7 -> V_1747 ) ;
return;
}
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_1592 ) ;
if ( ! V_360 )
goto V_60;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
( V_1971 &&
F_29 ( V_52 , V_539 , V_1971 ) ) ||
( V_1972 &&
F_29 ( V_52 , V_1973 , V_1972 ) ) ||
F_52 ( V_52 , V_1585 , V_46 , V_2004 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_427 ( F_7 ( & V_7 -> V_18 ) , V_52 , V_1744 -> V_1748 ) ;
}
F_294 ( & V_7 -> V_1747 ) ;
return;
V_60:
F_294 ( & V_7 -> V_1747 ) ;
if ( V_360 )
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
static int F_531 ( struct V_31 * V_52 ,
struct V_2005 * V_2006 )
{
struct V_2007 * V_1653 = V_2006 -> V_2008 ;
struct V_4 * V_2009 , * V_2010 , * V_363 ;
int V_160 , V_162 ;
V_2009 = F_48 (
V_52 , V_2011 ) ;
if ( ! V_2009 )
return - V_512 ;
for ( V_160 = 0 ; V_160 < V_1653 -> V_2012 ; V_160 ++ ) {
struct V_2013 * V_1655 = V_1653 -> V_1654 [ V_160 ] ;
V_2010 = F_48 ( V_52 , V_160 ) ;
if ( ! V_2010 )
break;
if ( F_52 ( V_52 , V_610 , V_1655 -> V_611 . V_609 ,
V_1655 -> V_611 . V_611 ) ) {
F_532 ( V_52 , V_2010 ) ;
goto V_616;
}
if ( V_1655 -> V_441 ) {
V_363 = F_48 (
V_52 , V_1285 ) ;
if ( ! V_363 ) {
F_532 ( V_52 , V_2010 ) ;
goto V_616;
}
for ( V_162 = 0 ; V_162 < V_1655 -> V_441 ; V_162 ++ ) {
if ( F_29 ( V_52 , V_162 , V_1655 -> V_442 [ V_162 ] ) ) {
F_532 ( V_52 , V_363 ) ;
F_532 ( V_52 , V_2010 ) ;
goto V_616;
}
}
F_49 ( V_52 , V_363 ) ;
}
F_49 ( V_52 , V_2010 ) ;
}
V_616:
F_49 ( V_52 , V_2009 ) ;
return 0 ;
}
void F_533 ( struct V_1 * V_17 ,
struct V_2005 * V_2006 ,
T_10 V_1521 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
int V_1657 = 200 ;
F_534 ( V_17 -> V_18 , V_17 , V_2006 ) ;
if ( V_2006 )
V_1657 += V_2006 -> V_2014 ;
V_52 = F_76 ( V_1657 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_2015 ) ;
if ( ! V_360 )
goto V_678;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_678;
if ( V_17 -> V_19 && F_29 ( V_52 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_678;
if ( V_2006 ) {
struct V_4 * V_2016 ;
V_2016 = F_48 ( V_52 , V_1659 ) ;
if ( ! V_2016 )
goto V_678;
if ( V_2006 -> V_355 &&
F_30 ( V_52 , V_209 ) )
goto V_678;
if ( V_2006 -> V_1661 &&
F_30 ( V_52 , V_211 ) )
goto V_678;
if ( V_2006 -> V_1662 &&
F_30 ( V_52 , V_215 ) )
goto V_678;
if ( V_2006 -> V_1663 &&
F_30 ( V_52 , V_217 ) )
goto V_678;
if ( V_2006 -> V_1664 &&
F_30 ( V_52 , V_219 ) )
goto V_678;
if ( V_2006 -> V_1665 &&
F_30 ( V_52 , V_221 ) )
goto V_678;
if ( V_2006 -> V_2017 >= 0 &&
F_29 ( V_52 , V_231 ,
V_2006 -> V_2017 ) )
goto V_678;
if ( V_2006 -> V_2018 &&
F_30 ( V_52 , V_2019 ) )
goto V_678;
if ( V_2006 -> V_2020 &&
F_30 ( V_52 , V_2021 ) )
goto V_678;
if ( V_2006 -> V_2022 &&
F_30 ( V_52 ,
V_2023 ) )
goto V_678;
if ( V_2006 -> V_2024 ) {
V_22 V_2025 = V_2026 ;
V_22 V_2027 = V_2028 ;
if ( ! V_2006 -> V_2029 ) {
V_2025 =
V_2030 ;
V_2027 =
V_2031 ;
}
if ( V_2006 -> V_2032 &&
F_29 ( V_52 , V_2027 , V_2006 -> V_2032 ) )
goto V_678;
if ( F_52 ( V_52 , V_2025 , V_2006 -> V_2014 ,
V_2006 -> V_2024 ) )
goto V_678;
}
if ( V_2006 -> V_2008 &&
F_531 ( V_52 , V_2006 ) )
goto V_678;
F_49 ( V_52 , V_2016 ) ;
}
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_678:
F_77 ( V_52 ) ;
}
void F_535 ( struct V_25 * V_556 , const T_2 * V_1564 ,
enum V_1571 V_2033 ,
T_3 V_1040 , T_10 V_1521 )
{
struct V_1 * V_17 = V_556 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
F_536 ( V_17 -> V_18 , V_556 , V_1564 , V_2033 ,
V_1040 ) ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_2034 ) ;
if ( ! V_360 ) {
F_77 ( V_52 ) ;
return;
}
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_556 -> V_20 ) ||
F_57 ( V_52 , V_1573 , V_2033 ) ||
F_52 ( V_52 , V_564 , V_604 , V_1564 ) ||
( V_1040 > 0 &&
F_56 ( V_52 , V_1039 , V_1040 ) ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_1521 ) ;
return;
V_60:
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
static int F_537 ( struct V_2035 * V_2036 ,
unsigned long V_359 ,
void * V_2037 )
{
struct V_2038 * V_2039 = V_2037 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1743 * V_1744 , * V_24 ;
if ( V_359 != V_2040 || V_2039 -> V_2041 != V_2042 )
return V_2043 ;
F_241 () ;
F_538 (rdev, &cfg80211_rdev_list, list) {
bool V_2044 = false ;
struct V_1307 * V_1338 =
F_242 ( V_7 -> V_1338 ) ;
if ( V_1338 && V_2039 -> V_48 &&
V_1338 -> V_655 == V_2039 -> V_48 ) {
V_1338 -> V_655 = 0 ;
if ( V_7 -> V_328 -> V_1340 &&
V_7 -> V_18 . V_50 & V_338 )
F_539 ( & V_7 -> V_2045 ) ;
}
F_538 (wdev, &rdev->wiphy.wdev_list, list) {
F_540 ( V_17 , V_2039 -> V_48 ) ;
if ( V_17 -> V_655 == V_2039 -> V_48 )
V_2044 = true ;
}
F_292 ( & V_7 -> V_1747 ) ;
F_541 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1744 -> V_1748 == V_2039 -> V_48 ) {
F_542 ( & V_1744 -> V_661 ) ;
F_42 ( V_1744 ) ;
break;
}
}
F_294 ( & V_7 -> V_1747 ) ;
if ( V_2044 ) {
struct V_2046 * V_2047 ;
V_2047 = F_40 ( sizeof( * V_2047 ) , V_1927 ) ;
if ( V_2047 ) {
V_2047 -> V_1748 = V_2039 -> V_48 ;
F_543 ( & V_7 -> V_2048 ) ;
F_405 ( & V_2047 -> V_661 , & V_7 -> V_2049 ) ;
F_544 ( & V_7 -> V_2048 ) ;
F_539 ( & V_7 -> V_2050 ) ;
}
}
}
F_243 () ;
F_545 ( V_2039 -> V_48 ) ;
return V_2051 ;
}
void F_546 ( struct V_25 * V_19 ,
struct V_2052 * V_2053 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
F_547 ( V_18 , V_19 , V_2053 ) ;
if ( ! V_2053 -> V_2054 )
return;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_2055 ) ;
if ( ! V_360 )
goto V_616;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_19 -> V_20 ) ||
F_52 ( V_52 , V_564 , V_604 , V_2053 -> V_2054 ) )
goto V_616;
if ( V_2053 -> V_1373 &&
F_52 ( V_52 , V_747 , V_2053 -> V_2056 , V_2053 -> V_1373 ) )
goto V_616;
if ( V_2053 -> V_2057 &&
F_52 ( V_52 , V_2058 , V_2053 -> V_2059 ,
V_2053 -> V_2057 ) )
goto V_616;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_52 , 0 ,
V_1929 , V_135 ) ;
return;
V_616:
F_77 ( V_52 ) ;
}
void F_548 ( struct V_1 * V_17 , T_10 V_1521 )
{
struct V_6 * V_7 ;
struct V_31 * V_52 ;
void * V_360 ;
V_22 V_1748 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1854 )
return;
V_1748 = V_7 -> V_1854 ;
V_7 -> V_1854 = 0 ;
V_52 = F_76 ( V_617 , V_1521 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_2060 ) ;
if ( ! V_360 )
goto V_60;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_60;
F_68 ( V_52 , V_360 ) ;
F_427 ( F_7 ( & V_7 -> V_18 ) , V_52 , V_1748 ) ;
return;
V_60:
if ( V_360 )
F_69 ( V_52 , V_360 ) ;
F_77 ( V_52 ) ;
}
void F_549 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_52 ;
void * V_360 ;
V_52 = F_76 ( V_617 , V_135 ) ;
if ( ! V_52 )
return;
V_360 = F_26 ( V_52 , 0 , 0 , 0 , V_2061 ) ;
if ( ! V_360 )
goto V_616;
if ( F_29 ( V_52 , V_26 , V_7 -> V_14 ) ||
F_29 ( V_52 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_105 ( V_52 , V_12 , V_13 ( V_17 ) ,
V_603 ) )
goto V_616;
F_68 ( V_52 , V_360 ) ;
F_322 ( & V_38 , F_7 ( V_18 ) , V_52 , 0 ,
V_1929 , V_135 ) ;
return;
V_616:
F_77 ( V_52 ) ;
}
int T_11 F_550 ( void )
{
int V_35 ;
V_35 = F_551 ( & V_38 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_552 ( & V_2062 ) ;
if ( V_35 )
goto V_2063;
return 0 ;
V_2063:
F_553 ( & V_38 ) ;
return V_35 ;
}
void F_554 ( void )
{
F_555 ( & V_2062 ) ;
F_553 ( & V_38 ) ;
}
