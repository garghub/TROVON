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
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_43;
* V_17 = F_1 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( * V_17 ) ) {
V_35 = F_18 ( * V_17 ) ;
goto V_43;
}
* V_7 = F_11 ( ( * V_17 ) -> V_18 ) ;
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = ( * V_17 ) -> V_21 ;
} else {
struct V_18 * V_18 = F_19 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 ) {
V_35 = - V_23 ;
goto V_43;
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
goto V_43;
}
}
return 0 ;
V_43:
F_20 () ;
return V_35 ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_20 () ;
}
static bool F_22 ( const struct V_4 * V_45 )
{
const T_2 * V_46 ;
int V_47 ;
if ( ! V_45 )
return true ;
V_46 = F_23 ( V_45 ) ;
V_47 = F_24 ( V_45 ) ;
while ( V_47 ) {
T_2 V_48 ;
if ( V_47 < 2 )
return false ;
V_47 -= 2 ;
V_48 = V_46 [ 1 ] ;
if ( V_48 > V_47 )
return false ;
V_47 -= V_48 ;
V_46 += 2 + V_48 ;
}
return true ;
}
static inline void * F_25 ( struct V_31 * V_32 , V_22 V_49 , V_22 V_50 ,
int V_51 , T_2 V_52 )
{
return F_26 ( V_32 , V_49 , V_50 , & V_38 , V_51 , V_52 ) ;
}
static int F_27 ( struct V_31 * V_53 ,
struct V_54 * V_55 ,
bool V_56 )
{
if ( ! V_56 && V_55 -> V_51 &
( V_57 | V_58 ) )
return 0 ;
if ( F_28 ( V_53 , V_59 ,
V_55 -> V_60 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_62 ) &&
F_29 ( V_53 , V_63 ) )
goto V_61;
if ( V_55 -> V_51 & V_64 ) {
if ( F_29 ( V_53 , V_65 ) )
goto V_61;
if ( F_29 ( V_53 , V_66 ) )
goto V_61;
}
if ( V_55 -> V_51 & V_67 ) {
if ( F_29 ( V_53 , V_68 ) )
goto V_61;
if ( V_56 ) {
V_22 time ;
time = F_30 ( V_55 -> V_69 ) ;
if ( F_28 ( V_53 , V_70 ,
V_55 -> V_71 ) )
goto V_61;
if ( F_28 ( V_53 , V_72 ,
time ) )
goto V_61;
if ( F_28 ( V_53 ,
V_73 ,
V_55 -> V_74 ) )
goto V_61;
}
}
if ( V_56 ) {
if ( ( V_55 -> V_51 & V_75 ) &&
F_29 ( V_53 , V_76 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_77 ) &&
F_29 ( V_53 , V_78 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_79 ) &&
F_29 ( V_53 , V_80 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_81 ) &&
F_29 ( V_53 , V_82 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_83 ) &&
F_29 ( V_53 , V_84 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_85 ) &&
F_29 ( V_53 , V_86 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_58 ) &&
F_29 ( V_53 , V_87 ) )
goto V_61;
if ( ( V_55 -> V_51 & V_57 ) &&
F_29 ( V_53 , V_88 ) )
goto V_61;
}
if ( F_28 ( V_53 , V_89 ,
F_31 ( V_55 -> V_90 ) ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_32 ( struct V_4 * V_92 , struct V_93 * V_94 )
{
struct V_4 * V_95 [ V_96 + 1 ] ;
int V_35 = F_33 ( V_95 , V_96 , V_92 ,
V_97 ) ;
if ( V_35 )
return V_35 ;
V_94 -> V_98 = ! ! V_95 [ V_99 ] ;
V_94 -> V_100 = ! ! V_95 [ V_101 ] ;
if ( V_94 -> V_98 ) {
V_94 -> V_102 = true ;
V_94 -> V_103 = true ;
}
if ( V_94 -> V_100 )
V_94 -> V_103 = true ;
if ( V_95 [ V_104 ] )
V_94 -> V_105 = F_34 ( V_95 [ V_104 ] ) ;
if ( V_95 [ V_106 ] ) {
V_94 -> V_107 . V_92 = F_23 ( V_95 [ V_106 ] ) ;
V_94 -> V_107 . V_108 = F_24 ( V_95 [ V_106 ] ) ;
}
if ( V_95 [ V_109 ] ) {
V_94 -> V_107 . V_50 = F_23 ( V_95 [ V_109 ] ) ;
V_94 -> V_107 . V_110 = F_24 ( V_95 [ V_109 ] ) ;
}
if ( V_95 [ V_111 ] )
V_94 -> V_107 . V_112 = F_4 ( V_95 [ V_111 ] ) ;
if ( V_95 [ V_113 ] ) {
V_94 -> type = F_4 ( V_95 [ V_113 ] ) ;
if ( V_94 -> type < 0 || V_94 -> type >= V_114 )
return - V_16 ;
}
if ( V_95 [ V_115 ] ) {
struct V_4 * V_116 [ V_117 ] ;
V_35 = F_33 ( V_116 , V_117 - 1 ,
V_95 [ V_115 ] ,
V_118 ) ;
if ( V_35 )
return V_35 ;
V_94 -> V_102 = V_116 [ V_119 ] ;
V_94 -> V_103 = V_116 [ V_120 ] ;
}
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , struct V_93 * V_94 )
{
if ( V_30 -> V_5 [ V_121 ] ) {
V_94 -> V_107 . V_92 = F_23 ( V_30 -> V_5 [ V_121 ] ) ;
V_94 -> V_107 . V_108 = F_24 ( V_30 -> V_5 [ V_121 ] ) ;
}
if ( V_30 -> V_5 [ V_122 ] ) {
V_94 -> V_107 . V_50 = F_23 ( V_30 -> V_5 [ V_122 ] ) ;
V_94 -> V_107 . V_110 = F_24 ( V_30 -> V_5 [ V_122 ] ) ;
}
if ( V_30 -> V_5 [ V_123 ] )
V_94 -> V_105 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_30 -> V_5 [ V_124 ] )
V_94 -> V_107 . V_112 = F_4 ( V_30 -> V_5 [ V_124 ] ) ;
V_94 -> V_98 = ! ! V_30 -> V_5 [ V_125 ] ;
V_94 -> V_100 = ! ! V_30 -> V_5 [ V_126 ] ;
if ( V_94 -> V_98 ) {
V_94 -> V_102 = true ;
V_94 -> V_103 = true ;
}
if ( V_94 -> V_100 )
V_94 -> V_103 = true ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_94 -> type = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_94 -> type < 0 || V_94 -> type >= V_114 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_128 ] ) {
struct V_4 * V_116 [ V_117 ] ;
int V_35 = F_33 (
V_116 , V_117 - 1 ,
V_30 -> V_5 [ V_128 ] ,
V_118 ) ;
if ( V_35 )
return V_35 ;
V_94 -> V_102 = V_116 [ V_119 ] ;
V_94 -> V_103 = V_116 [ V_120 ] ;
}
return 0 ;
}
static int F_36 ( struct V_29 * V_30 , struct V_93 * V_94 )
{
int V_35 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_105 = - 1 ;
V_94 -> type = - 1 ;
if ( V_30 -> V_5 [ V_129 ] )
V_35 = F_32 ( V_30 -> V_5 [ V_129 ] , V_94 ) ;
else
V_35 = F_35 ( V_30 , V_94 ) ;
if ( V_35 )
return V_35 ;
if ( V_94 -> V_98 && V_94 -> V_100 )
return - V_16 ;
if ( V_94 -> V_100 ) {
if ( V_94 -> V_102 || ! V_94 -> V_103 )
return - V_16 ;
}
if ( V_94 -> V_105 != - 1 ) {
if ( V_94 -> V_100 ) {
if ( V_94 -> V_105 < 4 || V_94 -> V_105 > 5 )
return - V_16 ;
} else if ( V_94 -> V_98 ) {
if ( V_94 -> V_105 < 0 || V_94 -> V_105 > 3 )
return - V_16 ;
} else {
if ( V_94 -> V_105 < 0 || V_94 -> V_105 > 5 )
return - V_16 ;
}
}
return 0 ;
}
static struct V_130 *
F_37 ( struct V_6 * V_7 ,
struct V_4 * V_131 , bool * V_132 )
{
struct V_93 V_133 ;
struct V_4 * V_92 ;
struct V_130 * V_8 ;
int V_134 , V_35 , V_98 = 0 ;
bool V_135 = false ;
F_38 (key, keys, rem) {
V_135 = true ;
break;
}
if ( ! V_135 )
return NULL ;
V_8 = F_39 ( sizeof( * V_8 ) , V_136 ) ;
if ( ! V_8 )
return F_3 ( - V_137 ) ;
V_8 -> V_98 = - 1 ;
F_38 (key, keys, rem) {
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_105 = - 1 ;
V_35 = F_32 ( V_92 , & V_133 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_133 . V_107 . V_92 )
goto error;
if ( V_133 . V_105 < 0 || V_133 . V_105 > 3 )
goto error;
if ( V_133 . V_98 ) {
if ( V_98 )
goto error;
V_98 = 1 ;
V_8 -> V_98 = V_133 . V_105 ;
if ( ! V_133 . V_102 || ! V_133 . V_103 )
goto error;
} else if ( V_133 . V_100 )
goto error;
V_35 = F_40 ( V_7 , & V_133 . V_107 ,
V_133 . V_105 , false , NULL ) ;
if ( V_35 )
goto error;
if ( V_133 . V_107 . V_112 != V_138 &&
V_133 . V_107 . V_112 != V_139 ) {
V_35 = - V_16 ;
goto error;
}
V_8 -> V_140 [ V_133 . V_105 ] . V_112 = V_133 . V_107 . V_112 ;
V_8 -> V_140 [ V_133 . V_105 ] . V_108 = V_133 . V_107 . V_108 ;
V_8 -> V_140 [ V_133 . V_105 ] . V_92 = V_8 -> V_141 [ V_133 . V_105 ] ;
memcpy ( V_8 -> V_141 [ V_133 . V_105 ] , V_133 . V_107 . V_92 , V_133 . V_107 . V_108 ) ;
if ( V_132 )
* V_132 = true ;
}
if ( V_8 -> V_98 < 0 ) {
V_35 = - V_16 ;
goto error;
}
return V_8 ;
error:
F_41 ( V_8 ) ;
return F_3 ( V_35 ) ;
}
static int F_42 ( struct V_1 * V_17 )
{
F_43 ( V_17 ) ;
switch ( V_17 -> V_142 ) {
case V_143 :
case V_144 :
case V_145 :
case V_146 :
break;
case V_147 :
case V_148 :
case V_149 :
if ( ! V_17 -> V_150 )
return - V_151 ;
break;
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
return - V_16 ;
}
return 0 ;
}
static struct V_54 * F_44 ( struct V_18 * V_18 ,
struct V_4 * V_95 )
{
struct V_54 * V_55 ;
if ( V_95 == NULL )
return NULL ;
V_55 = F_45 ( V_18 , F_4 ( V_95 ) ) ;
if ( ! V_55 || V_55 -> V_51 & V_62 )
return NULL ;
return V_55 ;
}
static int F_46 ( struct V_31 * V_53 , V_22 V_45 , T_3 V_159 )
{
struct V_4 * V_160 = F_47 ( V_53 , V_45 ) ;
int V_161 ;
if ( ! V_160 )
goto V_61;
V_161 = 0 ;
while ( V_159 ) {
if ( ( V_159 & 1 ) && F_29 ( V_53 , V_161 ) )
goto V_61;
V_159 >>= 1 ;
V_161 ++ ;
}
F_48 ( V_53 , V_160 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_49 ( struct V_18 * V_18 ,
struct V_31 * V_53 ,
bool V_56 )
{
struct V_4 * V_162 ;
int V_161 , V_163 ;
V_162 = F_47 ( V_53 ,
V_164 ) ;
if ( ! V_162 )
goto V_61;
for ( V_161 = 0 ; V_161 < V_18 -> V_165 ; V_161 ++ ) {
const struct V_166 * V_167 ;
struct V_4 * V_168 , * V_169 ;
V_167 = & V_18 -> V_170 [ V_161 ] ;
V_168 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_168 )
goto V_61;
V_169 = F_47 ( V_53 , V_171 ) ;
if ( ! V_169 )
goto V_61;
for ( V_163 = 0 ; V_163 < V_167 -> V_172 ; V_163 ++ ) {
struct V_4 * V_173 ;
V_173 = F_47 ( V_53 , V_163 + 1 ) ;
if ( ! V_173 )
goto V_61;
if ( F_28 ( V_53 , V_174 ,
V_167 -> V_175 [ V_163 ] . V_176 ) )
goto V_61;
if ( F_46 ( V_53 , V_177 ,
V_167 -> V_175 [ V_163 ] . V_178 ) )
goto V_61;
F_48 ( V_53 , V_173 ) ;
}
F_48 ( V_53 , V_169 ) ;
if ( V_167 -> V_179 &&
F_29 ( V_53 , V_180 ) )
goto V_61;
if ( F_28 ( V_53 , V_181 ,
V_167 -> V_182 ) ||
F_28 ( V_53 , V_183 ,
V_167 -> V_184 ) )
goto V_61;
if ( V_56 &&
( F_28 ( V_53 , V_185 ,
V_167 -> V_186 ) ||
F_28 ( V_53 , V_187 ,
V_167 -> V_188 ) ) )
goto V_61;
F_48 ( V_53 , V_168 ) ;
}
F_48 ( V_53 , V_162 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
const struct V_189 * V_190 = V_7 -> V_18 . V_191 -> V_190 ;
struct V_4 * V_192 ;
if ( ! V_190 )
return 0 ;
V_192 = F_47 ( V_53 , V_193 ) ;
if ( ! V_192 )
return - V_91 ;
if ( F_28 ( V_53 , V_194 ,
V_190 -> V_195 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_194 ,
V_190 -> V_195 ) )
return - V_91 ;
if ( V_190 -> V_50 && F_29 ( V_53 , V_196 ) )
return - V_91 ;
if ( V_190 -> V_197 && F_51 ( V_53 , V_198 ,
sizeof( * V_190 -> V_197 ) , V_190 -> V_197 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_199 ,
V_190 -> V_200 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_201 ,
V_190 -> V_202 ) )
return - V_91 ;
F_48 ( V_53 , V_192 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
bool V_56 )
{
struct V_4 * V_203 ;
if ( ! V_7 -> V_18 . V_191 )
return 0 ;
V_203 = F_47 ( V_53 , V_204 ) ;
if ( ! V_203 )
return - V_91 ;
if ( ( ( V_7 -> V_18 . V_191 -> V_51 & V_205 ) &&
F_29 ( V_53 , V_206 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_51 & V_207 ) &&
F_29 ( V_53 , V_208 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_51 & V_209 ) &&
F_29 ( V_53 , V_210 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_51 & V_211 ) &&
F_29 ( V_53 , V_212 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_51 & V_213 ) &&
F_29 ( V_53 , V_214 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_51 & V_215 ) &&
F_29 ( V_53 , V_216 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_51 & V_217 ) &&
F_29 ( V_53 , V_218 ) ) ||
( ( V_7 -> V_18 . V_191 -> V_51 & V_219 ) &&
F_29 ( V_53 , V_220 ) ) )
return - V_91 ;
if ( V_7 -> V_18 . V_191 -> V_221 ) {
struct V_222 V_223 = {
. V_224 = V_7 -> V_18 . V_191 -> V_221 ,
. V_225 = V_7 -> V_18 . V_191 -> V_226 ,
. V_227 = V_7 -> V_18 . V_191 -> V_228 ,
. V_229 = V_7 -> V_18 . V_191 -> V_229 ,
} ;
if ( F_51 ( V_53 , V_230 ,
sizeof( V_223 ) , & V_223 ) )
return - V_91 ;
}
if ( ( V_7 -> V_18 . V_191 -> V_51 & V_231 ) &&
F_28 ( V_53 , V_232 ,
V_7 -> V_18 . V_191 -> V_233 ) )
return - V_91 ;
if ( V_56 && F_50 ( V_7 , V_53 ) )
return - V_91 ;
F_48 ( V_53 , V_203 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_234 V_235 ;
if ( ! V_7 -> V_18 . V_236 )
return 0 ;
V_235 . V_237 = V_7 -> V_18 . V_236 -> V_238 ;
V_235 . V_239 = V_7 -> V_18 . V_236 -> V_239 ;
V_235 . V_223 . V_224 = V_7 -> V_18 . V_236 -> V_221 ;
V_235 . V_223 . V_225 = V_7 -> V_18 . V_236 -> V_226 ;
V_235 . V_223 . V_227 = V_7 -> V_18 . V_236 -> V_228 ;
V_235 . V_223 . V_229 = V_7 -> V_18 . V_236 -> V_229 ;
if ( F_51 ( V_53 , V_240 , sizeof( V_235 ) , & V_235 ) )
return - V_91 ;
return 0 ;
}
static int F_54 ( struct V_31 * V_53 ,
struct V_241 * V_242 )
{
struct V_4 * V_243 , * V_244 ;
struct V_245 * V_246 ;
int V_161 ;
if ( V_242 -> V_247 . V_248 &&
( F_51 ( V_53 , V_249 ,
sizeof( V_242 -> V_247 . V_250 ) ,
& V_242 -> V_247 . V_250 ) ||
F_55 ( V_53 , V_251 ,
V_242 -> V_247 . V_252 ) ||
F_56 ( V_53 , V_253 ,
V_242 -> V_247 . V_254 ) ||
F_56 ( V_53 , V_255 ,
V_242 -> V_247 . V_256 ) ) )
return - V_91 ;
if ( V_242 -> V_257 . V_258 &&
( F_51 ( V_53 , V_259 ,
sizeof( V_242 -> V_257 . V_260 ) ,
& V_242 -> V_257 . V_260 ) ||
F_28 ( V_53 , V_261 ,
V_242 -> V_257 . V_252 ) ) )
return - V_91 ;
V_243 = F_47 ( V_53 , V_262 ) ;
if ( ! V_243 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_242 -> V_263 ; V_161 ++ ) {
V_244 = F_47 ( V_53 , V_161 ) ;
if ( ! V_244 )
return - V_91 ;
V_246 = & V_242 -> V_264 [ V_161 ] ;
if ( F_28 ( V_53 , V_265 ,
V_246 -> V_266 ) )
return - V_91 ;
if ( ( V_246 -> V_51 & V_267 ) &&
F_29 ( V_53 ,
V_268 ) )
return - V_91 ;
F_48 ( V_53 , V_244 ) ;
}
F_48 ( V_53 , V_243 ) ;
return 0 ;
}
static int
F_57 ( struct V_31 * V_53 ,
const struct V_269 * V_270 )
{
T_3 V_271 ;
struct V_4 * V_272 , * V_273 ;
enum V_274 V_275 ;
int V_161 ;
if ( ! V_270 )
return 0 ;
V_273 = F_47 ( V_53 , V_276 ) ;
if ( ! V_273 )
return - V_91 ;
for ( V_275 = 0 ; V_275 < V_158 ; V_275 ++ ) {
V_272 = F_47 ( V_53 , V_275 ) ;
if ( ! V_272 )
return - V_91 ;
V_161 = 0 ;
V_271 = V_270 [ V_275 ] . V_277 ;
while ( V_271 ) {
if ( ( V_271 & 1 ) &&
F_55 ( V_53 , V_278 ,
( V_161 << 4 ) | V_279 ) )
return - V_91 ;
V_271 >>= 1 ;
V_161 ++ ;
}
F_48 ( V_53 , V_272 ) ;
}
F_48 ( V_53 , V_273 ) ;
V_273 = F_47 ( V_53 , V_280 ) ;
if ( ! V_273 )
return - V_91 ;
for ( V_275 = 0 ; V_275 < V_158 ; V_275 ++ ) {
V_272 = F_47 ( V_53 , V_275 ) ;
if ( ! V_272 )
return - V_91 ;
V_161 = 0 ;
V_271 = V_270 [ V_275 ] . V_281 ;
while ( V_271 ) {
if ( ( V_271 & 1 ) &&
F_55 ( V_53 , V_278 ,
( V_161 << 4 ) | V_279 ) )
return - V_91 ;
V_271 >>= 1 ;
V_161 ++ ;
}
F_48 ( V_53 , V_272 ) ;
}
F_48 ( V_53 , V_273 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
enum V_282 V_52 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_283 * V_284 )
{
void * V_285 ;
struct V_4 * V_286 , * V_287 ;
struct V_4 * V_288 , * V_289 ;
struct V_4 * V_290 ;
enum V_291 V_292 ;
struct V_54 * V_55 ;
int V_161 ;
const struct V_269 * V_270 =
V_7 -> V_18 . V_270 ;
V_22 V_293 ;
V_285 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_285 )
return - V_91 ;
if ( F_59 ( ! V_284 ) )
return - V_16 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_60 ( V_53 , V_294 ,
F_61 ( & V_7 -> V_18 ) ) ||
F_28 ( V_53 , V_295 ,
V_296 ) )
goto V_61;
if ( V_52 != V_297 )
goto V_298;
switch ( V_284 -> V_299 ) {
case 0 :
if ( F_56 ( V_53 , V_300 ,
V_7 -> V_18 . V_301 ) ||
F_56 ( V_53 , V_302 ,
V_7 -> V_18 . V_303 ) ||
F_28 ( V_53 , V_304 ,
V_7 -> V_18 . V_305 ) ||
F_28 ( V_53 , V_306 ,
V_7 -> V_18 . V_307 ) ||
F_56 ( V_53 , V_308 ,
V_7 -> V_18 . V_309 ) ||
F_56 ( V_53 , V_310 ,
V_7 -> V_18 . V_311 ) ||
F_56 ( V_53 , V_312 ,
V_7 -> V_18 . V_313 ) ||
F_55 ( V_53 , V_314 ,
V_7 -> V_18 . V_315 ) ||
F_55 ( V_53 , V_316 ,
V_7 -> V_18 . V_317 ) ||
F_56 ( V_53 , V_318 ,
V_7 -> V_18 . V_319 ) ||
F_28 ( V_53 , V_320 ,
V_7 -> V_18 . V_321 ) ||
F_28 ( V_53 , V_322 ,
V_7 -> V_18 . V_323 ) ||
F_28 ( V_53 , V_324 ,
V_7 -> V_18 . V_325 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_326 ) &&
F_29 ( V_53 , V_327 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_328 ) &&
F_29 ( V_53 , V_329 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_330 ) &&
F_29 ( V_53 , V_331 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_332 ) &&
F_29 ( V_53 , V_333 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_334 ) &&
F_29 ( V_53 , V_335 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_336 ) &&
F_29 ( V_53 , V_337 ) )
goto V_61;
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
case 1 :
if ( F_51 ( V_53 , V_339 ,
sizeof( V_22 ) * V_7 -> V_18 . V_340 ,
V_7 -> V_18 . V_341 ) )
goto V_61;
if ( F_56 ( V_53 , V_342 ,
V_7 -> V_18 . V_343 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_344 ) &&
F_29 ( V_53 , V_345 ) )
goto V_61;
if ( F_28 ( V_53 , V_346 ,
V_7 -> V_18 . V_347 ) ||
F_28 ( V_53 , V_348 ,
V_7 -> V_18 . V_349 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_350 ) &&
F_28 ( V_53 , V_351 ,
V_7 -> V_18 . V_352 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_347 ||
V_7 -> V_18 . V_349 ) &&
V_7 -> V_353 -> V_354 ) {
V_22 V_355 = 0 , V_356 = 0 ;
int V_357 ;
V_357 = F_62 ( V_7 , & V_355 , & V_356 ) ;
if ( ! V_357 ) {
if ( F_28 ( V_53 ,
V_358 ,
V_355 ) ||
F_28 ( V_53 ,
V_359 ,
V_356 ) )
goto V_61;
}
}
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
case 2 :
if ( F_46 ( V_53 , V_360 ,
V_7 -> V_18 . V_361 ) )
goto V_61;
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
case 3 :
V_286 = F_47 ( V_53 , V_362 ) ;
if ( ! V_286 )
goto V_61;
for ( V_292 = V_284 -> V_363 ;
V_292 < V_364 ; V_292 ++ ) {
struct V_241 * V_242 ;
V_242 = V_7 -> V_18 . V_365 [ V_292 ] ;
if ( ! V_242 )
continue;
V_287 = F_47 ( V_53 , V_292 ) ;
if ( ! V_287 )
goto V_61;
switch ( V_284 -> V_366 ) {
case 0 :
if ( F_54 ( V_53 , V_242 ) )
goto V_61;
V_284 -> V_366 ++ ;
if ( V_284 -> V_338 )
break;
default:
V_288 = F_47 (
V_53 , V_367 ) ;
if ( ! V_288 )
goto V_61;
for ( V_161 = V_284 -> V_366 - 1 ;
V_161 < V_242 -> V_368 ;
V_161 ++ ) {
V_289 = F_47 ( V_53 , V_161 ) ;
if ( ! V_289 )
goto V_61;
V_55 = & V_242 -> V_369 [ V_161 ] ;
if ( F_27 (
V_53 , V_55 ,
V_284 -> V_338 ) )
goto V_61;
F_48 ( V_53 , V_289 ) ;
if ( V_284 -> V_338 )
break;
}
if ( V_161 < V_242 -> V_368 )
V_284 -> V_366 = V_161 + 2 ;
else
V_284 -> V_366 = 0 ;
F_48 ( V_53 , V_288 ) ;
}
F_48 ( V_53 , V_287 ) ;
if ( V_284 -> V_338 ) {
if ( V_284 -> V_366 )
V_292 -- ;
break;
}
}
F_48 ( V_53 , V_286 ) ;
if ( V_292 < V_364 )
V_284 -> V_363 = V_292 + 1 ;
else
V_284 -> V_363 = 0 ;
if ( V_284 -> V_363 == 0 && V_284 -> V_366 == 0 )
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
case 4 :
V_290 = F_47 ( V_53 , V_370 ) ;
if ( ! V_290 )
goto V_61;
V_161 = 0 ;
#define F_63 ( T_4 , T_5 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_63 ( V_371 , V_372 ) ;
F_63 ( V_373 , V_374 ) ;
F_63 ( V_375 , V_376 ) ;
F_63 ( V_377 , V_378 ) ;
F_63 ( V_379 , V_380 ) ;
F_63 ( V_381 , V_382 ) ;
F_63 ( V_383 , V_384 ) ;
F_63 ( V_385 , V_386 ) ;
F_63 ( V_387 , V_388 ) ;
F_63 ( V_389 , V_390 ) ;
F_63 ( V_391 , V_392 ) ;
F_63 ( V_393 , V_394 ) ;
F_63 ( V_395 , V_396 ) ;
F_63 ( V_397 , V_398 ) ;
F_63 ( V_399 , V_400 ) ;
F_63 ( V_401 , V_402 ) ;
F_63 ( V_403 , V_404 ) ;
if ( V_7 -> V_18 . V_51 & V_405 )
F_63 ( V_406 , V_407 ) ;
F_63 ( V_408 , V_409 ) ;
F_63 ( V_410 , V_411 ) ;
F_63 ( V_412 , V_413 ) ;
if ( V_7 -> V_18 . V_51 & V_414 ) {
V_161 ++ ;
if ( F_28 ( V_53 , V_161 , V_415 ) )
goto V_61;
}
if ( V_7 -> V_353 -> V_416 || V_7 -> V_353 -> V_377 ||
V_7 -> V_353 -> V_397 ) {
V_161 ++ ;
if ( F_28 ( V_53 , V_161 , V_417 ) )
goto V_61;
}
F_63 ( V_418 , V_419 ) ;
if ( V_7 -> V_18 . V_51 & V_334 ) {
F_63 ( V_420 , V_421 ) ;
F_63 ( V_422 , V_423 ) ;
}
if ( V_7 -> V_18 . V_51 & V_424 )
F_63 ( V_425 , V_426 ) ;
F_63 ( V_427 , V_428 ) ;
F_63 ( V_429 , V_430 ) ;
if ( V_7 -> V_18 . V_51 & V_431 ) {
V_161 ++ ;
if ( F_28 ( V_53 , V_161 , V_432 ) )
goto V_61;
}
F_63 ( V_433 , V_434 ) ;
F_63 ( V_435 , V_436 ) ;
#ifdef F_64
F_63 ( V_437 , V_438 ) ;
#endif
if ( V_284 -> V_338 ) {
F_63 ( V_439 , V_440 ) ;
F_63 ( V_441 , V_442 ) ;
if ( V_7 -> V_18 . V_51 & V_443 )
F_63 ( V_444 , V_445 ) ;
F_63 ( V_446 , V_447 ) ;
if ( V_7 -> V_18 . V_293 &
V_448 )
F_63 ( V_449 , V_450 ) ;
}
#undef F_63
if ( V_7 -> V_353 -> V_451 || V_7 -> V_353 -> V_387 ) {
V_161 ++ ;
if ( F_28 ( V_53 , V_161 , V_452 ) )
goto V_61;
}
if ( V_7 -> V_353 -> V_453 || V_7 -> V_353 -> V_391 ) {
V_161 ++ ;
if ( F_28 ( V_53 , V_161 , V_454 ) )
goto V_61;
}
F_48 ( V_53 , V_290 ) ;
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
case 5 :
if ( V_7 -> V_353 -> V_406 &&
( V_7 -> V_18 . V_51 & V_405 ) &&
F_28 ( V_53 ,
V_455 ,
V_7 -> V_18 . V_456 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_457 ) &&
F_29 ( V_53 , V_458 ) )
goto V_61;
if ( F_57 ( V_53 , V_270 ) )
goto V_61;
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
case 6 :
#ifdef F_65
if ( F_52 ( V_53 , V_7 , V_284 -> V_338 ) )
goto V_61;
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
#else
V_284 -> V_299 ++ ;
#endif
case 7 :
if ( F_46 ( V_53 , V_459 ,
V_7 -> V_18 . V_460 ) )
goto V_61;
if ( F_49 ( & V_7 -> V_18 , V_53 ,
V_284 -> V_338 ) )
goto V_61;
V_284 -> V_299 ++ ;
if ( V_284 -> V_338 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_51 & V_461 ) &&
F_28 ( V_53 , V_462 ,
V_7 -> V_18 . V_463 ) )
goto V_61;
V_293 = V_7 -> V_18 . V_293 ;
if ( V_284 -> V_338 )
V_293 |= V_464 ;
if ( F_28 ( V_53 , V_465 , V_293 ) )
goto V_61;
if ( V_7 -> V_18 . V_466 &&
F_51 ( V_53 , V_467 ,
sizeof( * V_7 -> V_18 . V_466 ) ,
V_7 -> V_18 . V_466 ) )
goto V_61;
if ( V_7 -> V_18 . V_51 & V_461 &&
V_7 -> V_18 . V_468 &&
F_28 ( V_53 , V_469 ,
V_7 -> V_18 . V_468 ) )
goto V_61;
V_284 -> V_299 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_470 &&
( F_51 ( V_53 , V_471 ,
V_7 -> V_18 . V_472 ,
V_7 -> V_18 . V_470 ) ||
F_51 ( V_53 , V_473 ,
V_7 -> V_18 . V_472 ,
V_7 -> V_18 . V_474 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_475 &&
F_51 ( V_53 , V_476 ,
sizeof( * V_7 -> V_18 . V_475 ) ,
V_7 -> V_18 . V_475 ) )
goto V_61;
V_284 -> V_299 ++ ;
break;
case 10 :
if ( F_53 ( V_53 , V_7 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_477 ) &&
( F_29 ( V_53 , V_478 ) ||
F_29 ( V_53 , V_479 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_480 &&
F_28 ( V_53 , V_481 ,
V_7 -> V_18 . V_480 ) )
goto V_61;
V_284 -> V_299 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_482 ) {
const struct V_483 * V_30 ;
struct V_4 * V_484 ;
V_484 = F_47 ( V_53 , V_485 ) ;
if ( ! V_484 )
goto V_61;
for ( V_161 = 0 ; V_161 < V_7 -> V_18 . V_482 ; V_161 ++ ) {
V_30 = & V_7 -> V_18 . V_486 [ V_161 ] . V_30 ;
if ( F_51 ( V_53 , V_161 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_484 ) ;
}
if ( V_7 -> V_18 . V_487 ) {
const struct V_483 * V_30 ;
struct V_4 * V_484 ;
V_484 = F_47 ( V_53 ,
V_488 ) ;
if ( ! V_484 )
goto V_61;
for ( V_161 = 0 ; V_161 < V_7 -> V_18 . V_487 ; V_161 ++ ) {
V_30 = & V_7 -> V_18 . V_489 [ V_161 ] ;
if ( F_51 ( V_53 , V_161 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_484 ) ;
}
V_284 -> V_299 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_51 & V_443 &&
F_56 ( V_53 , V_490 ,
V_7 -> V_18 . V_491 ) )
goto V_61;
if ( V_7 -> V_18 . V_492 & V_493 &&
F_29 ( V_53 , V_494 ) )
goto V_61;
if ( F_51 ( V_53 , V_495 ,
sizeof( V_7 -> V_18 . V_496 ) ,
V_7 -> V_18 . V_496 ) )
goto V_61;
if ( V_7 -> V_18 . V_497 ) {
struct V_4 * V_484 ;
V_22 V_497 = V_7 -> V_18 . V_497 ;
V_484 = F_47 ( V_53 , V_498 ) ;
if ( ! V_484 )
goto V_61;
V_161 = 0 ;
while ( V_497 ) {
if ( ( V_497 & 1 ) &&
F_29 ( V_53 , V_161 ) )
goto V_61;
V_161 ++ ;
V_497 >>= 1 ;
}
F_48 ( V_53 , V_484 ) ;
}
V_284 -> V_299 ++ ;
break;
case 13 :
if ( V_7 -> V_18 . V_499 &&
V_7 -> V_18 . V_500 ) {
struct V_4 * V_501 , * V_484 ;
V_484 = F_47 ( V_53 ,
V_502 ) ;
if ( ! V_484 )
goto V_61;
for ( V_161 = V_284 -> V_503 ;
V_161 < V_7 -> V_18 . V_499 ; V_161 ++ ) {
const struct V_504 * V_505 ;
V_505 = & V_7 -> V_18 . V_500 [ V_161 ] ;
V_501 = F_47 ( V_53 , V_161 ) ;
if ( ! V_501 ||
F_28 ( V_53 , V_506 ,
V_505 -> V_142 ) ||
F_51 ( V_53 , V_471 ,
V_505 -> V_472 ,
V_505 -> V_470 ) ||
F_51 ( V_53 , V_473 ,
V_505 -> V_472 ,
V_505 -> V_474 ) )
goto V_61;
F_48 ( V_53 , V_501 ) ;
if ( V_284 -> V_338 )
break;
}
F_48 ( V_53 , V_484 ) ;
if ( V_161 < V_7 -> V_18 . V_499 ) {
V_284 -> V_503 = V_161 + 1 ;
break;
}
}
V_284 -> V_299 = 0 ;
break;
}
V_298:
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_283 * V_284 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_508 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_508 )
return 0 ;
V_284 -> V_338 = V_95 [ V_509 ] ;
if ( V_95 [ V_26 ] )
V_284 -> V_510 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_284 -> V_510 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
if ( V_95 [ V_10 ] ) {
struct V_25 * V_19 ;
struct V_6 * V_7 ;
int V_15 = F_4 ( V_95 [ V_10 ] ) ;
V_19 = F_10 ( F_16 ( V_32 -> V_44 ) , V_15 ) ;
if ( ! V_19 )
return - V_23 ;
if ( V_19 -> V_28 ) {
V_7 = F_11 (
V_19 -> V_28 -> V_18 ) ;
V_284 -> V_510 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_508 ;
struct V_283 * V_284 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_284 ) {
V_284 = F_39 ( sizeof( * V_284 ) , V_136 ) ;
if ( ! V_284 ) {
F_20 () ;
return - V_137 ;
}
V_284 -> V_510 = - 1 ;
V_508 = F_68 ( V_32 , V_34 , V_284 ) ;
if ( V_508 ) {
F_41 ( V_284 ) ;
F_20 () ;
return V_508 ;
}
V_34 -> args [ 0 ] = ( long ) V_284 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_284 -> V_511 )
continue;
if ( V_284 -> V_510 != - 1 &&
V_284 -> V_510 != V_7 -> V_14 )
continue;
do {
V_508 = F_58 ( V_7 , V_297 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 ,
V_513 , V_284 ) ;
if ( V_508 < 0 ) {
if ( ( V_508 == - V_91 || V_508 == - V_507 ) &&
! V_32 -> V_47 && ! V_284 -> V_338 &&
V_34 -> V_514 < 4096 ) {
V_34 -> V_514 = 4096 ;
V_284 -> V_299 = 0 ;
F_20 () ;
return 1 ;
}
V_105 -- ;
break;
}
} while ( V_284 -> V_299 > 0 );
break;
}
F_20 () ;
V_284 -> V_511 = V_105 ;
return V_32 -> V_47 ;
}
static int F_72 ( struct V_33 * V_34 )
{
F_41 ( ( void * ) V_34 -> args [ 0 ] ) ;
return 0 ;
}
static int F_73 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_283 V_284 = {} ;
V_53 = F_74 ( 4096 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
if ( F_58 ( V_7 , V_297 , V_53 ,
V_30 -> V_516 , V_30 -> V_517 , 0 ,
& V_284 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_518 * V_519 )
{
if ( ! V_95 [ V_520 ] || ! V_95 [ V_521 ] ||
! V_95 [ V_522 ] || ! V_95 [ V_523 ] ||
! V_95 [ V_524 ] )
return - V_16 ;
V_519 -> V_525 = F_34 ( V_95 [ V_520 ] ) ;
V_519 -> V_526 = F_78 ( V_95 [ V_521 ] ) ;
V_519 -> V_527 = F_78 ( V_95 [ V_522 ] ) ;
V_519 -> V_528 = F_78 ( V_95 [ V_523 ] ) ;
V_519 -> V_529 = F_34 ( V_95 [ V_524 ] ) ;
if ( V_519 -> V_525 >= V_530 )
return - V_16 ;
return 0 ;
}
static bool F_79 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_142 == V_143 ||
V_17 -> V_142 == V_146 ||
V_17 -> V_142 == V_154 ||
V_17 -> V_142 == V_145 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_531 * V_532 )
{
V_22 V_533 ;
if ( ! V_30 -> V_5 [ V_534 ] )
return - V_16 ;
V_533 = F_4 ( V_30 -> V_5 [ V_534 ] ) ;
V_532 -> V_55 = F_45 ( & V_7 -> V_18 , V_533 ) ;
V_532 -> V_535 = V_536 ;
V_532 -> V_537 = V_533 ;
V_532 -> V_538 = 0 ;
if ( ! V_532 -> V_55 || V_532 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_539 ] ) {
enum V_540 V_541 ;
V_541 = F_4 (
V_30 -> V_5 [ V_539 ] ) ;
switch ( V_541 ) {
case V_542 :
case V_543 :
case V_544 :
case V_545 :
F_81 ( V_532 , V_532 -> V_55 ,
V_541 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_546 ] ) {
V_532 -> V_535 =
F_4 ( V_30 -> V_5 [ V_546 ] ) ;
if ( V_30 -> V_5 [ V_547 ] )
V_532 -> V_537 =
F_4 (
V_30 -> V_5 [ V_547 ] ) ;
if ( V_30 -> V_5 [ V_548 ] )
V_532 -> V_538 =
F_4 (
V_30 -> V_5 [ V_548 ] ) ;
}
if ( ! F_82 ( V_532 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_532 ,
V_62 ) )
return - V_16 ;
if ( ( V_532 -> V_535 == V_549 ||
V_532 -> V_535 == V_550 ) &&
! ( V_7 -> V_18 . V_51 & V_477 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_551 ,
struct V_29 * V_30 )
{
struct V_531 V_532 ;
int V_8 ;
enum V_274 V_142 = V_154 ;
struct V_1 * V_17 = NULL ;
if ( V_551 )
V_17 = V_551 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_552 ;
if ( V_17 )
V_142 = V_17 -> V_142 ;
V_8 = F_80 ( V_7 , V_30 , & V_532 ) ;
if ( V_8 )
return V_8 ;
switch ( V_142 ) {
case V_143 :
case V_145 :
if ( ! F_85 ( & V_7 -> V_18 , & V_532 ,
V_142 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_553 ) {
if ( ! V_551 || ! V_7 -> V_353 -> V_554 ||
! ( V_7 -> V_18 . V_293 &
V_555 ) ) {
V_8 = - V_556 ;
break;
}
if ( V_532 . V_55 != V_17 -> V_557 . V_55 ) {
V_8 = - V_556 ;
break;
}
V_8 = F_86 ( V_7 , V_551 , & V_532 ) ;
if ( V_8 )
break;
}
V_17 -> V_557 = V_532 ;
V_8 = 0 ;
break;
case V_146 :
V_8 = F_87 ( V_7 , V_17 , & V_532 ) ;
break;
case V_154 :
V_8 = F_88 ( V_7 , & V_532 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_515 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
const T_2 * V_558 ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( F_91 ( V_551 ) )
return - V_556 ;
if ( ! V_7 -> V_353 -> V_418 )
return - V_552 ;
if ( V_17 -> V_142 != V_157 )
return - V_552 ;
V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
return F_92 ( V_7 , V_551 , V_558 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_560 = 0 ;
struct V_4 * V_561 ;
V_22 V_562 ;
T_2 V_301 = 0 , V_303 = 0 ;
V_22 V_305 = 0 , V_307 = 0 ;
T_2 V_309 = 0 ;
F_2 () ;
if ( V_30 -> V_5 [ V_10 ] ) {
int V_20 = F_4 ( V_30 -> V_5 [ V_10 ] ) ;
V_19 = F_10 ( F_94 ( V_30 ) , V_20 ) ;
if ( V_19 && V_19 -> V_28 )
V_7 = F_11 ( V_19 -> V_28 -> V_18 ) ;
else
V_19 = NULL ;
}
if ( ! V_19 ) {
V_7 = F_8 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_7 ) )
return F_18 ( V_7 ) ;
V_17 = NULL ;
V_19 = NULL ;
V_8 = 0 ;
} else
V_17 = V_19 -> V_28 ;
if ( V_30 -> V_5 [ V_294 ] )
V_8 = F_95 (
V_7 , F_23 ( V_30 -> V_5 [ V_294 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_563 ] ) {
struct V_518 V_519 ;
struct V_4 * V_95 [ V_564 + 1 ] ;
if ( ! V_7 -> V_353 -> V_565 )
return - V_552 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_142 != V_143 &&
V_19 -> V_28 -> V_142 != V_145 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_566 ;
F_38 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_564 ,
F_23 ( V_561 ) ,
F_24 ( V_561 ) ,
V_567 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_519 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_519 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_534 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_568 ] ) {
struct V_1 * V_569 = V_17 ;
enum V_570 type ;
int V_105 , V_571 = 0 ;
if ( ! ( V_7 -> V_18 . V_293 & V_572 ) )
V_569 = NULL ;
if ( ! V_7 -> V_353 -> V_573 )
return - V_552 ;
V_105 = V_568 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_574 ] &&
( type != V_575 ) )
return - V_16 ;
if ( type != V_575 ) {
V_105 = V_574 ;
V_571 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_569 , type , V_571 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_358 ] &&
V_30 -> V_5 [ V_359 ] ) {
V_22 V_355 , V_356 ;
if ( ( ! V_7 -> V_18 . V_347 &&
! V_7 -> V_18 . V_349 ) ||
! V_7 -> V_353 -> V_576 )
return - V_552 ;
V_355 = F_4 ( V_30 -> V_5 [ V_358 ] ) ;
V_356 = F_4 ( V_30 -> V_5 [ V_359 ] ) ;
if ( ( ~ V_355 && ( V_355 & ~ V_7 -> V_18 . V_347 ) ) ||
( ~ V_356 && ( V_356 & ~ V_7 -> V_18 . V_349 ) ) )
return - V_16 ;
V_355 = V_355 & V_7 -> V_18 . V_347 ;
V_356 = V_356 & V_7 -> V_18 . V_349 ;
V_8 = F_99 ( V_7 , V_355 , V_356 ) ;
if ( V_8 )
return V_8 ;
}
V_562 = 0 ;
if ( V_30 -> V_5 [ V_300 ] ) {
V_301 = F_34 (
V_30 -> V_5 [ V_300 ] ) ;
if ( V_301 == 0 )
return - V_16 ;
V_562 |= V_577 ;
}
if ( V_30 -> V_5 [ V_302 ] ) {
V_303 = F_34 (
V_30 -> V_5 [ V_302 ] ) ;
if ( V_303 == 0 )
return - V_16 ;
V_562 |= V_578 ;
}
if ( V_30 -> V_5 [ V_304 ] ) {
V_305 = F_4 (
V_30 -> V_5 [ V_304 ] ) ;
if ( V_305 < 256 )
return - V_16 ;
if ( V_305 != ( V_22 ) - 1 ) {
V_305 &= ~ 0x1 ;
}
V_562 |= V_579 ;
}
if ( V_30 -> V_5 [ V_306 ] ) {
V_307 = F_4 (
V_30 -> V_5 [ V_306 ] ) ;
V_562 |= V_580 ;
}
if ( V_30 -> V_5 [ V_308 ] ) {
if ( V_30 -> V_5 [ V_581 ] )
return - V_16 ;
V_309 = F_34 (
V_30 -> V_5 [ V_308 ] ) ;
V_562 |= V_582 ;
}
if ( V_30 -> V_5 [ V_581 ] ) {
if ( ! ( V_7 -> V_18 . V_293 & V_583 ) )
return - V_552 ;
V_562 |= V_584 ;
}
if ( V_562 ) {
T_2 V_585 , V_586 ;
V_22 V_587 , V_588 ;
T_2 V_589 ;
if ( ! V_7 -> V_353 -> V_590 )
return - V_552 ;
V_585 = V_7 -> V_18 . V_301 ;
V_586 = V_7 -> V_18 . V_303 ;
V_587 = V_7 -> V_18 . V_305 ;
V_588 = V_7 -> V_18 . V_307 ;
V_589 = V_7 -> V_18 . V_309 ;
if ( V_562 & V_577 )
V_7 -> V_18 . V_301 = V_301 ;
if ( V_562 & V_578 )
V_7 -> V_18 . V_303 = V_303 ;
if ( V_562 & V_579 )
V_7 -> V_18 . V_305 = V_305 ;
if ( V_562 & V_580 )
V_7 -> V_18 . V_307 = V_307 ;
if ( V_562 & V_582 )
V_7 -> V_18 . V_309 = V_309 ;
V_8 = F_100 ( V_7 , V_562 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_301 = V_585 ;
V_7 -> V_18 . V_303 = V_586 ;
V_7 -> V_18 . V_305 = V_587 ;
V_7 -> V_18 . V_307 = V_588 ;
V_7 -> V_18 . V_309 = V_589 ;
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
static int F_101 ( struct V_31 * V_53 ,
const struct V_531 * V_532 )
{
if ( F_59 ( ! F_82 ( V_532 ) ) )
return - V_16 ;
if ( F_28 ( V_53 , V_534 ,
V_532 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_532 -> V_535 ) {
case V_536 :
case V_591 :
case V_592 :
if ( F_28 ( V_53 , V_539 ,
F_102 ( V_532 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_546 , V_532 -> V_535 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_547 , V_532 -> V_537 ) )
return - V_91 ;
if ( V_532 -> V_538 &&
F_28 ( V_53 , V_548 , V_532 -> V_538 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_593 )
{
struct V_25 * V_551 = V_17 -> V_19 ;
T_2 V_52 = V_594 ;
void * V_285 ;
if ( V_593 )
V_52 = V_595 ;
V_285 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_285 )
return - 1 ;
if ( V_551 &&
( F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_60 ( V_53 , V_596 , V_551 -> V_597 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_506 , V_17 -> V_142 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) ||
F_51 ( V_53 , V_559 , V_599 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_295 ,
V_7 -> V_600 ^
( V_296 << 2 ) ) )
goto V_61;
if ( V_7 -> V_353 -> V_601 ) {
int V_508 ;
struct V_531 V_532 ;
V_508 = F_106 ( V_7 , V_17 , & V_532 ) ;
if ( V_508 == 0 ) {
if ( F_101 ( V_53 , & V_532 ) )
goto V_61;
}
}
if ( V_7 -> V_353 -> V_602 ) {
int V_603 , V_508 ;
V_508 = F_107 ( V_7 , V_17 , & V_603 ) ;
if ( V_508 == 0 &&
F_28 ( V_53 , V_574 ,
F_31 ( V_603 ) ) )
goto V_61;
}
if ( V_17 -> V_604 ) {
if ( F_51 ( V_53 , V_605 , V_17 -> V_604 , V_17 -> V_606 ) )
goto V_61;
}
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_607 = 0 ;
int V_608 = 0 ;
int V_609 = V_34 -> args [ 0 ] ;
int V_610 = V_34 -> args [ 1 ] ;
int V_510 = - 1 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
if ( ! V_34 -> args [ 2 ] ) {
struct V_283 V_284 = {
. V_510 = - 1 ,
} ;
int V_508 ;
V_508 = F_68 ( V_32 , V_34 , & V_284 ) ;
if ( V_508 )
return V_508 ;
V_510 = V_284 . V_510 ;
if ( V_510 >= 0 )
V_34 -> args [ 2 ] = V_510 + 1 ;
else
V_34 -> args [ 2 ] = - 1 ;
} else if ( V_34 -> args [ 2 ] > 0 ) {
V_510 = V_34 -> args [ 2 ] - 1 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_607 < V_609 ) {
V_607 ++ ;
continue;
}
if ( V_510 >= 0 && V_510 != V_7 -> V_14 )
continue;
V_608 = 0 ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_608 < V_610 ) {
V_608 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_7 , V_17 , false ) < 0 ) {
goto V_611;
}
V_608 ++ ;
}
V_607 ++ ;
}
V_611:
F_20 () ;
V_34 -> args [ 0 ] = V_607 ;
V_34 -> args [ 1 ] = V_608 ;
return V_32 -> V_47 ;
}
static int F_109 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
if ( F_103 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_110 ( struct V_4 * V_613 , V_22 * V_614 )
{
struct V_4 * V_51 [ V_615 + 1 ] ;
int V_616 ;
* V_614 = 0 ;
if ( ! V_613 )
return - V_16 ;
if ( F_33 ( V_51 , V_615 ,
V_613 , V_617 ) )
return - V_16 ;
for ( V_616 = 1 ; V_616 <= V_615 ; V_616 ++ )
if ( V_51 [ V_616 ] )
* V_614 |= ( 1 << V_616 ) ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_618 ,
enum V_274 V_142 )
{
if ( ! V_618 ) {
if ( V_19 && ( V_19 -> V_619 & V_620 ) )
return - V_556 ;
return 0 ;
}
switch ( V_142 ) {
case V_144 :
if ( V_7 -> V_18 . V_51 & V_621 )
return 0 ;
break;
case V_148 :
if ( V_7 -> V_18 . V_51 & V_622 )
return 0 ;
break;
default:
break;
}
return - V_552 ;
}
static int F_112 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_623 V_140 ;
int V_35 ;
enum V_274 V_624 , V_625 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
V_22 V_626 , * V_51 = NULL ;
bool V_627 = false ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_624 = V_625 = V_551 -> V_28 -> V_142 ;
if ( V_30 -> V_5 [ V_506 ] ) {
V_625 = F_4 ( V_30 -> V_5 [ V_506 ] ) ;
if ( V_624 != V_625 )
V_627 = true ;
if ( V_625 > V_628 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_629 ] ) {
struct V_1 * V_17 = V_551 -> V_28 ;
if ( V_625 != V_146 )
return - V_16 ;
if ( F_91 ( V_551 ) )
return - V_556 ;
F_113 ( V_17 ) ;
F_114 ( V_630 !=
V_631 ) ;
V_17 -> V_632 =
F_24 ( V_30 -> V_5 [ V_629 ] ) ;
memcpy ( V_17 -> V_606 , F_23 ( V_30 -> V_5 [ V_629 ] ) ,
V_17 -> V_632 ) ;
F_115 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_633 ] ) {
V_140 . V_618 = ! ! F_34 ( V_30 -> V_5 [ V_633 ] ) ;
V_627 = true ;
V_35 = F_111 ( V_7 , V_551 , V_140 . V_618 , V_625 ) ;
if ( V_35 )
return V_35 ;
} else {
V_140 . V_618 = - 1 ;
}
if ( V_30 -> V_5 [ V_634 ] ) {
if ( V_625 != V_154 )
return - V_16 ;
V_35 = F_110 ( V_30 -> V_5 [ V_634 ] ,
& V_626 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_626 ;
V_627 = true ;
}
if ( V_30 -> V_5 [ V_635 ] ) {
const T_2 * V_636 ;
V_22 V_637 = V_638 ;
if ( ! F_116 ( & V_7 -> V_18 , V_637 ) )
return - V_552 ;
V_636 =
F_23 ( V_30 -> V_5 [ V_635 ] ) ;
if ( ( V_636 [ 0 ] & F_117 ( 7 ) ) ||
( V_636 [ V_639 - 1 ] & F_117 ( 0 ) ) )
return - V_16 ;
memcpy ( V_140 . V_640 , V_636 ,
V_639 ) ;
V_627 = true ;
}
if ( V_30 -> V_5 [ V_641 ] ) {
V_22 V_637 = V_638 ;
if ( ! F_116 ( & V_7 -> V_18 , V_637 ) )
return - V_552 ;
F_118 ( V_140 . V_642 ,
V_30 -> V_5 [ V_641 ] ,
V_599 ) ;
V_627 = true ;
}
if ( V_51 && ( * V_51 & V_643 ) &&
! ( V_7 -> V_18 . V_293 & V_644 ) )
return - V_552 ;
if ( V_627 )
V_35 = F_119 ( V_7 , V_551 , V_625 , V_51 , & V_140 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_140 . V_618 != - 1 )
V_551 -> V_28 -> V_618 = V_140 . V_618 ;
return V_35 ;
}
static int F_120 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_623 V_140 ;
struct V_1 * V_17 ;
struct V_31 * V_53 ;
int V_35 ;
enum V_274 type = V_152 ;
V_22 V_51 ;
F_121 ( V_7 ) ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( ! V_30 -> V_5 [ V_596 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_506 ] ) {
type = F_4 ( V_30 -> V_5 [ V_506 ] ) ;
if ( type > V_628 )
return - V_16 ;
}
if ( ! V_7 -> V_353 -> V_371 ||
! ( V_7 -> V_18 . V_361 & ( 1 << type ) ) )
return - V_552 ;
if ( ( type == V_156 || type == V_155 ||
V_7 -> V_18 . V_293 & V_645 ) &&
V_30 -> V_5 [ V_559 ] ) {
F_118 ( V_140 . V_642 , V_30 -> V_5 [ V_559 ] ,
V_599 ) ;
if ( ! F_122 ( V_140 . V_642 ) )
return - V_646 ;
}
if ( V_30 -> V_5 [ V_633 ] ) {
V_140 . V_618 = ! ! F_34 ( V_30 -> V_5 [ V_633 ] ) ;
V_35 = F_111 ( V_7 , NULL , V_140 . V_618 , type ) ;
if ( V_35 )
return V_35 ;
}
V_35 = F_110 ( type == V_154 ?
V_30 -> V_5 [ V_634 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_643 ) &&
! ( V_7 -> V_18 . V_293 & V_644 ) )
return - V_552 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_17 = F_123 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_596 ] ) ,
V_647 , type , V_35 ? NULL : & V_51 ,
& V_140 ) ;
if ( F_59 ( ! V_17 ) ) {
F_75 ( V_53 ) ;
return - V_648 ;
} else if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_649 ] )
V_17 -> V_650 = V_30 -> V_516 ;
switch ( type ) {
case V_146 :
if ( ! V_30 -> V_5 [ V_629 ] )
break;
F_113 ( V_17 ) ;
F_114 ( V_630 !=
V_631 ) ;
V_17 -> V_632 =
F_24 ( V_30 -> V_5 [ V_629 ] ) ;
memcpy ( V_17 -> V_606 , F_23 ( V_30 -> V_5 [ V_629 ] ) ,
V_17 -> V_632 ) ;
F_115 ( V_17 ) ;
break;
case V_155 :
case V_156 :
F_124 ( & V_17 -> V_651 ) ;
F_125 ( & V_17 -> V_652 ) ;
F_126 ( & V_17 -> V_653 ) ;
F_125 ( & V_17 -> V_654 ) ;
F_126 ( & V_17 -> V_655 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_127 ( & V_17 -> V_656 , & V_7 -> V_18 . V_657 ) ;
V_7 -> V_600 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_7 , V_17 , false ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
if ( ! V_17 -> V_19 )
F_128 ( V_7 , V_17 , V_594 ) ;
return F_76 ( V_53 , V_30 ) ;
}
static int F_129 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
if ( ! V_7 -> V_353 -> V_658 )
return - V_552 ;
if ( ! V_17 -> V_19 )
V_30 -> V_515 [ 1 ] = NULL ;
return F_130 ( V_7 , V_17 ) ;
}
static int F_131 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_3 V_659 ;
if ( ! V_30 -> V_5 [ V_660 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_429 )
return - V_552 ;
V_659 = F_78 ( V_30 -> V_5 [ V_660 ] ) ;
return F_132 ( V_7 , V_551 , V_659 ) ;
}
static void F_133 ( void * V_167 , struct V_661 * V_140 )
{
struct V_4 * V_92 ;
struct V_662 * V_663 = V_167 ;
if ( ( V_140 -> V_92 &&
F_51 ( V_663 -> V_53 , V_121 ,
V_140 -> V_108 , V_140 -> V_92 ) ) ||
( V_140 -> V_50 &&
F_51 ( V_663 -> V_53 , V_122 ,
V_140 -> V_110 , V_140 -> V_50 ) ) ||
( V_140 -> V_112 &&
F_28 ( V_663 -> V_53 , V_124 ,
V_140 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_663 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_140 -> V_92 &&
F_51 ( V_663 -> V_53 , V_106 ,
V_140 -> V_108 , V_140 -> V_92 ) ) ||
( V_140 -> V_50 &&
F_51 ( V_663 -> V_53 , V_109 ,
V_140 -> V_110 , V_140 -> V_50 ) ) ||
( V_140 -> V_112 &&
F_28 ( V_663 -> V_53 , V_111 ,
V_140 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_663 -> V_53 , V_123 , V_663 -> V_105 ) )
goto V_61;
F_48 ( V_663 -> V_53 , V_92 ) ;
return;
V_61:
V_663 -> error = 1 ;
}
static int F_134 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int V_35 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 V_664 = 0 ;
const T_2 * V_665 = NULL ;
bool V_666 ;
struct V_662 V_663 = {
. error = 0 ,
} ;
void * V_285 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_664 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_664 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_559 ] )
V_665 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_666 = ! ! V_665 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_667 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_667 >= V_114 )
return - V_16 ;
if ( V_667 != V_668 &&
V_667 != V_669 )
return - V_16 ;
V_666 = V_667 == V_669 ;
}
if ( ! V_7 -> V_353 -> V_670 )
return - V_552 ;
if ( ! V_666 && V_665 && ! ( V_7 -> V_18 . V_51 & V_326 ) )
return - V_671 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_672 ) ;
if ( ! V_285 )
goto V_61;
V_663 . V_53 = V_53 ;
V_663 . V_105 = V_664 ;
if ( F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_664 ) )
goto V_61;
if ( V_665 &&
F_51 ( V_53 , V_559 , V_599 , V_665 ) )
goto V_61;
V_35 = F_135 ( V_7 , V_551 , V_664 , V_666 , V_665 , & V_663 ,
F_133 ) ;
if ( V_35 )
goto V_673;
if ( V_663 . error )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_673:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_136 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_113 ( V_551 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_353 -> V_674 ) {
V_35 = - V_552 ;
goto V_611;
}
V_35 = F_42 ( V_551 -> V_28 ) ;
if ( V_35 )
goto V_611;
V_35 = F_137 ( V_7 , V_551 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_611;
#ifdef F_138
V_551 -> V_28 -> V_675 . V_676 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_611;
}
if ( ! V_7 -> V_353 -> V_677 ) {
V_35 = - V_552 ;
goto V_611;
}
V_35 = F_42 ( V_551 -> V_28 ) ;
if ( V_35 )
goto V_611;
V_35 = F_139 ( V_7 , V_551 , V_92 . V_105 ) ;
if ( V_35 )
goto V_611;
#ifdef F_138
V_551 -> V_28 -> V_675 . V_678 = V_92 . V_105 ;
#endif
}
V_611:
F_115 ( V_551 -> V_28 ) ;
return V_35 ;
}
static int F_140 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int V_35 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_665 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_559 ] )
V_665 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_665 )
V_92 . type = V_669 ;
else
V_92 . type = V_668 ;
}
if ( V_92 . type != V_669 &&
V_92 . type != V_668 )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_375 )
return - V_552 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_669 ,
V_665 ) )
return - V_16 ;
F_113 ( V_551 -> V_28 ) ;
V_35 = F_42 ( V_551 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_141 ( V_7 , V_551 , V_92 . V_105 ,
V_92 . type == V_669 ,
V_665 , & V_92 . V_107 ) ;
F_115 ( V_551 -> V_28 ) ;
return V_35 ;
}
static int F_142 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int V_35 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 * V_665 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_559 ] )
V_665 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_665 )
V_92 . type = V_669 ;
else
V_92 . type = V_668 ;
}
if ( V_92 . type != V_669 &&
V_92 . type != V_668 )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_679 )
return - V_552 ;
F_113 ( V_551 -> V_28 ) ;
V_35 = F_42 ( V_551 -> V_28 ) ;
if ( V_92 . type == V_668 && V_665 &&
! ( V_7 -> V_18 . V_51 & V_326 ) )
V_35 = - V_671 ;
if ( ! V_35 )
V_35 = F_143 ( V_7 , V_551 , V_92 . V_105 ,
V_92 . type == V_669 ,
V_665 ) ;
#ifdef F_138
if ( ! V_35 ) {
if ( V_92 . V_105 == V_551 -> V_28 -> V_675 . V_676 )
V_551 -> V_28 -> V_675 . V_676 = - 1 ;
else if ( V_92 . V_105 == V_551 -> V_28 -> V_675 . V_678 )
V_551 -> V_28 -> V_675 . V_678 = - 1 ;
}
#endif
F_115 ( V_551 -> V_28 ) ;
return V_35 ;
}
static int F_144 ( struct V_4 * V_680 )
{
struct V_4 * V_45 ;
int V_681 = 0 , V_24 ;
F_38 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_599 )
return - V_16 ;
V_681 ++ ;
}
return V_681 ;
}
static struct V_682 * F_145 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_683 V_684 ;
struct V_4 * V_45 ;
struct V_682 * V_685 ;
int V_161 = 0 , V_681 , V_24 ;
if ( ! V_18 -> V_468 )
return F_3 ( - V_552 ) ;
if ( ! V_30 -> V_5 [ V_686 ] )
return F_3 ( - V_16 ) ;
V_684 = F_4 ( V_30 -> V_5 [ V_686 ] ) ;
if ( V_684 != V_687 &&
V_684 != V_688 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_689 ] )
return F_3 ( - V_16 ) ;
V_681 = F_144 ( V_30 -> V_5 [ V_689 ] ) ;
if ( V_681 < 0 )
return F_3 ( V_681 ) ;
if ( V_681 > V_18 -> V_468 )
return F_3 ( - V_690 ) ;
V_685 = F_39 ( sizeof( * V_685 ) + ( sizeof( struct V_691 ) * V_681 ) ,
V_136 ) ;
if ( ! V_685 )
return F_3 ( - V_137 ) ;
F_38 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_685 -> V_692 [ V_161 ] . V_693 , F_23 ( V_45 ) , V_599 ) ;
V_161 ++ ;
}
V_685 -> V_694 = V_681 ;
V_685 -> V_684 = V_684 ;
return V_685 ;
}
static int F_146 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_682 * V_685 ;
int V_35 ;
if ( V_551 -> V_28 -> V_142 != V_143 &&
V_551 -> V_28 -> V_142 != V_145 )
return - V_552 ;
if ( ! V_551 -> V_28 -> V_553 )
return - V_16 ;
V_685 = F_145 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_685 ) )
return F_18 ( V_685 ) ;
V_35 = F_147 ( V_7 , V_551 , V_685 ) ;
F_41 ( V_685 ) ;
return V_35 ;
}
static V_22 F_148 ( struct V_241 * V_242 ,
T_2 * V_695 , T_2 V_696 )
{
T_2 V_161 ;
V_22 V_697 = 0 ;
for ( V_161 = 0 ; V_161 < V_696 ; V_161 ++ ) {
int V_246 = ( V_695 [ V_161 ] & 0x7f ) * 5 ;
int V_698 ;
for ( V_698 = 0 ; V_698 < V_242 -> V_263 ; V_698 ++ ) {
struct V_245 * V_699 =
& V_242 -> V_264 [ V_698 ] ;
if ( V_246 == V_699 -> V_266 ) {
V_697 |= 1 << V_698 ;
break;
}
}
if ( V_698 == V_242 -> V_263 )
return 0 ;
}
return V_697 ;
}
static bool F_149 ( struct V_241 * V_242 ,
T_2 * V_695 , T_2 V_696 ,
T_2 V_250 [ V_700 ] )
{
T_2 V_161 ;
memset ( V_250 , 0 , V_700 ) ;
for ( V_161 = 0 ; V_161 < V_696 ; V_161 ++ ) {
int V_698 , V_701 ;
V_698 = V_695 [ V_161 ] / 8 ;
V_701 = F_117 ( V_695 [ V_161 ] % 8 ) ;
if ( ( V_698 < 0 ) || ( V_698 >= V_700 ) )
return false ;
if ( V_242 -> V_247 . V_250 . V_702 [ V_698 ] & V_701 )
V_250 [ V_698 ] |= V_701 ;
else
return false ;
}
return true ;
}
static T_3 F_150 ( T_2 V_703 )
{
T_3 V_704 = 0 ;
switch ( V_703 ) {
case V_705 :
break;
case V_706 :
V_704 = 0x00FF ;
break;
case V_707 :
V_704 = 0x01FF ;
break;
case V_708 :
V_704 = 0x03FF ;
break;
default:
break;
}
return V_704 ;
}
static void F_151 ( T_3 V_703 ,
T_3 V_709 [ V_710 ] )
{
T_2 V_711 ;
for ( V_711 = 0 ; V_711 < V_710 ; V_711 ++ ) {
V_709 [ V_711 ] = F_150 ( V_703 & 0x03 ) ;
V_703 >>= 2 ;
}
}
static bool F_152 ( struct V_241 * V_242 ,
struct V_712 * V_713 ,
T_3 V_250 [ V_710 ] )
{
T_3 V_714 = F_153 ( V_242 -> V_257 . V_260 . V_714 ) ;
T_3 V_715 [ V_710 ] = {} ;
T_2 V_161 ;
if ( ! V_242 -> V_257 . V_258 )
return false ;
memset ( V_250 , 0 , sizeof( T_3 ) * V_710 ) ;
F_151 ( V_714 , V_715 ) ;
for ( V_161 = 0 ; V_161 < V_710 ; V_161 ++ ) {
if ( ( V_715 [ V_161 ] & V_713 -> V_250 [ V_161 ] ) == V_713 -> V_250 [ V_161 ] )
V_250 [ V_161 ] = V_713 -> V_250 [ V_161 ] ;
else
return false ;
}
return true ;
}
static int F_154 ( struct V_29 * V_30 ,
struct V_716 * V_697 )
{
struct V_4 * V_95 [ V_717 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int V_134 , V_161 ;
struct V_4 * V_718 ;
struct V_241 * V_242 ;
T_3 V_719 ;
memset ( V_697 , 0 , sizeof( * V_697 ) ) ;
for ( V_161 = 0 ; V_161 < V_364 ; V_161 ++ ) {
V_242 = V_7 -> V_18 . V_365 [ V_161 ] ;
if ( ! V_242 )
continue;
V_697 -> V_720 [ V_161 ] . V_721 = ( 1 << V_242 -> V_263 ) - 1 ;
memcpy ( V_697 -> V_720 [ V_161 ] . V_722 ,
V_242 -> V_247 . V_250 . V_702 ,
sizeof( V_697 -> V_720 [ V_161 ] . V_722 ) ) ;
if ( ! V_242 -> V_257 . V_258 )
continue;
V_719 = F_153 ( V_242 -> V_257 . V_260 . V_714 ) ;
F_151 ( V_719 , V_697 -> V_720 [ V_161 ] . V_260 ) ;
}
if ( ! V_30 -> V_5 [ V_723 ] )
goto V_611;
F_114 ( V_724 > V_700 * 8 ) ;
F_38 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_291 V_292 = F_155 ( V_718 ) ;
int V_35 ;
if ( V_292 < 0 || V_292 >= V_364 )
return - V_16 ;
V_242 = V_7 -> V_18 . V_365 [ V_292 ] ;
if ( V_242 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_717 , F_23 ( V_718 ) ,
F_24 ( V_718 ) , V_725 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_726 ] ) {
V_697 -> V_720 [ V_292 ] . V_721 = F_148 (
V_242 ,
F_23 ( V_95 [ V_726 ] ) ,
F_24 ( V_95 [ V_726 ] ) ) ;
if ( ( V_697 -> V_720 [ V_292 ] . V_721 == 0 ) &&
F_24 ( V_95 [ V_726 ] ) )
return - V_16 ;
}
if ( V_95 [ V_727 ] ) {
if ( ! F_149 (
V_242 ,
F_23 ( V_95 [ V_727 ] ) ,
F_24 ( V_95 [ V_727 ] ) ,
V_697 -> V_720 [ V_292 ] . V_722 ) )
return - V_16 ;
}
if ( V_95 [ V_728 ] ) {
if ( ! F_152 (
V_242 ,
F_23 ( V_95 [ V_728 ] ) ,
V_697 -> V_720 [ V_292 ] . V_260 ) )
return - V_16 ;
}
if ( V_95 [ V_729 ] ) {
V_697 -> V_720 [ V_292 ] . V_730 =
F_34 ( V_95 [ V_729 ] ) ;
if ( V_697 -> V_720 [ V_292 ] . V_730 > V_731 )
return - V_16 ;
}
if ( V_697 -> V_720 [ V_292 ] . V_721 == 0 ) {
if ( ! ( V_7 -> V_18 . V_365 [ V_292 ] -> V_247 . V_248 ||
V_7 -> V_18 . V_365 [ V_292 ] -> V_257 . V_258 ) )
return - V_16 ;
for ( V_161 = 0 ; V_161 < V_700 ; V_161 ++ )
if ( V_697 -> V_720 [ V_292 ] . V_722 [ V_161 ] )
goto V_611;
for ( V_161 = 0 ; V_161 < V_710 ; V_161 ++ )
if ( V_697 -> V_720 [ V_292 ] . V_260 [ V_161 ] )
goto V_611;
return - V_16 ;
}
}
V_611:
return 0 ;
}
static int F_156 ( struct V_6 * V_7 ,
enum V_291 V_292 ,
struct V_716 * V_732 )
{
V_22 V_733 , V_734 , V_161 ;
V_22 V_246 = V_732 -> V_720 [ V_292 ] . V_721 ;
if ( F_157 ( V_246 ) > 1 )
return - V_16 ;
V_733 = 0 ;
for ( V_161 = 0 ; V_161 < V_700 ; V_161 ++ ) {
if ( F_158 ( V_732 -> V_720 [ V_292 ] . V_722 [ V_161 ] ) > 1 ) {
return - V_16 ;
} else if ( V_732 -> V_720 [ V_292 ] . V_722 [ V_161 ] ) {
V_733 ++ ;
if ( V_733 > 1 )
return - V_16 ;
}
if ( V_733 && V_246 )
return - V_16 ;
}
V_734 = 0 ;
for ( V_161 = 0 ; V_161 < V_710 ; V_161 ++ ) {
if ( F_159 ( V_732 -> V_720 [ V_292 ] . V_260 [ V_161 ] ) > 1 ) {
return - V_16 ;
} else if ( V_732 -> V_720 [ V_292 ] . V_260 [ V_161 ] ) {
V_734 ++ ;
if ( V_734 > 1 )
return - V_16 ;
}
if ( V_734 && V_246 )
return - V_16 ;
}
if ( ( V_733 && V_734 ) || ( ! V_246 && ! V_733 && ! V_734 ) )
return - V_16 ;
if ( V_246 &&
! F_116 ( & V_7 -> V_18 ,
V_735 ) )
return - V_16 ;
if ( V_733 &&
! F_116 ( & V_7 -> V_18 ,
V_736 ) )
return - V_16 ;
if ( V_734 &&
! F_116 ( & V_7 -> V_18 ,
V_737 ) )
return - V_16 ;
return 0 ;
}
static int F_160 ( struct V_4 * V_5 [] ,
struct V_738 * V_739 )
{
bool V_740 = false ;
if ( ! F_22 ( V_5 [ V_741 ] ) ||
! F_22 ( V_5 [ V_742 ] ) ||
! F_22 ( V_5 [ V_743 ] ) ||
! F_22 ( V_5 [ V_744 ] ) )
return - V_16 ;
memset ( V_739 , 0 , sizeof( * V_739 ) ) ;
if ( V_5 [ V_745 ] ) {
V_739 -> V_746 = F_23 ( V_5 [ V_745 ] ) ;
V_739 -> V_747 = F_24 ( V_5 [ V_745 ] ) ;
if ( ! V_739 -> V_747 )
return - V_16 ;
V_740 = true ;
}
if ( V_5 [ V_741 ] ) {
V_739 -> V_748 = F_23 ( V_5 [ V_741 ] ) ;
V_739 -> V_749 = F_24 ( V_5 [ V_741 ] ) ;
V_740 = true ;
}
if ( ! V_740 )
return - V_16 ;
if ( V_5 [ V_742 ] ) {
V_739 -> V_750 = F_23 ( V_5 [ V_742 ] ) ;
V_739 -> V_751 = F_24 ( V_5 [ V_742 ] ) ;
}
if ( V_5 [ V_743 ] ) {
V_739 -> V_752 =
F_23 ( V_5 [ V_743 ] ) ;
V_739 -> V_753 =
F_24 ( V_5 [ V_743 ] ) ;
}
if ( V_5 [ V_744 ] ) {
V_739 -> V_754 =
F_23 ( V_5 [ V_744 ] ) ;
V_739 -> V_755 =
F_24 ( V_5 [ V_744 ] ) ;
}
if ( V_5 [ V_756 ] ) {
V_739 -> V_757 = F_23 ( V_5 [ V_756 ] ) ;
V_739 -> V_758 = F_24 ( V_5 [ V_756 ] ) ;
}
return 0 ;
}
static bool F_161 ( struct V_6 * V_7 ,
struct V_759 * V_140 )
{
struct V_1 * V_17 ;
bool V_508 = false ;
F_6 (wdev, &rdev->wiphy.wdev_list, list) {
if ( V_17 -> V_142 != V_143 &&
V_17 -> V_142 != V_145 )
continue;
if ( ! V_17 -> V_557 . V_55 )
continue;
V_140 -> V_532 = V_17 -> V_557 ;
V_508 = true ;
break;
}
return V_508 ;
}
static bool F_162 ( struct V_6 * V_7 ,
enum V_760 V_761 ,
enum V_282 V_52 )
{
if ( V_761 > V_762 )
return false ;
switch ( V_52 ) {
case V_763 :
if ( ! ( V_7 -> V_18 . V_293 & V_764 ) &&
V_761 == V_765 )
return false ;
return true ;
case V_452 :
case V_766 :
if ( V_761 == V_765 )
return false ;
return true ;
default:
return false ;
}
}
static int F_163 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_759 V_140 ;
int V_35 ;
if ( V_551 -> V_28 -> V_142 != V_143 &&
V_551 -> V_28 -> V_142 != V_145 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_377 )
return - V_552 ;
if ( V_17 -> V_553 )
return - V_767 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( ! V_30 -> V_5 [ V_768 ] ||
! V_30 -> V_5 [ V_769 ] ||
! V_30 -> V_5 [ V_745 ] )
return - V_16 ;
V_35 = F_160 ( V_30 -> V_5 , & V_140 . V_770 ) ;
if ( V_35 )
return V_35 ;
V_140 . V_553 =
F_4 ( V_30 -> V_5 [ V_768 ] ) ;
V_140 . V_771 =
F_4 ( V_30 -> V_5 [ V_769 ] ) ;
V_35 = F_164 ( V_7 , V_140 . V_553 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_605 ] ) {
V_140 . V_606 = F_23 ( V_30 -> V_5 [ V_605 ] ) ;
V_140 . V_604 =
F_24 ( V_30 -> V_5 [ V_605 ] ) ;
if ( V_140 . V_604 == 0 ||
V_140 . V_604 > V_630 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_772 ] ) {
V_140 . V_773 = F_4 (
V_30 -> V_5 [ V_772 ] ) ;
if ( V_140 . V_773 != V_774 &&
V_140 . V_773 != V_775 &&
V_140 . V_773 != V_776 )
return - V_16 ;
}
V_140 . V_777 = ! ! V_30 -> V_5 [ V_778 ] ;
if ( V_30 -> V_5 [ V_779 ] ) {
V_140 . V_761 = F_4 (
V_30 -> V_5 [ V_779 ] ) ;
if ( ! F_162 ( V_7 , V_140 . V_761 ,
V_766 ) )
return - V_16 ;
} else
V_140 . V_761 = V_780 ;
V_35 = F_165 ( V_7 , V_30 , & V_140 . V_781 ,
V_782 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_783 ] ) {
if ( ! ( V_7 -> V_18 . V_293 & V_784 ) )
return - V_552 ;
V_140 . V_785 = F_78 (
V_30 -> V_5 [ V_783 ] ) ;
}
if ( V_30 -> V_5 [ V_786 ] ) {
if ( V_551 -> V_28 -> V_142 != V_145 )
return - V_16 ;
V_140 . V_787 =
F_34 ( V_30 -> V_5 [ V_786 ] ) ;
if ( V_140 . V_787 > 127 )
return - V_16 ;
if ( V_140 . V_787 != 0 &&
! ( V_7 -> V_18 . V_293 & V_788 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_789 ] ) {
T_2 V_24 ;
if ( V_551 -> V_28 -> V_142 != V_145 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_789 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_140 . V_790 = V_24 ;
if ( V_140 . V_790 != 0 &&
! ( V_7 -> V_18 . V_293 & V_791 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_534 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_140 . V_532 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_557 . V_55 ) {
V_140 . V_532 = V_17 -> V_557 ;
} else if ( ! F_161 ( V_7 , & V_140 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_140 . V_532 ,
V_17 -> V_142 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_723 ] ) {
V_35 = F_154 ( V_30 , & V_140 . V_732 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_156 ( V_7 , V_140 . V_532 . V_55 -> V_292 ,
& V_140 . V_732 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_792 ] ) {
V_140 . V_793 =
F_34 ( V_30 -> V_5 [ V_792 ] ) ;
switch ( V_140 . V_793 ) {
case V_794 :
break;
case V_795 :
if ( ! ( V_7 -> V_18 . V_293 &
V_796 ) )
return - V_16 ;
break;
case V_797 :
if ( ! ( V_7 -> V_18 . V_293 &
V_798 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_140 . V_793 = V_794 ;
}
V_140 . V_799 = F_166 ( V_30 -> V_5 [ V_800 ] ) ;
if ( V_140 . V_799 && ! V_7 -> V_18 . V_365 [ V_801 ] )
return - V_552 ;
if ( V_30 -> V_5 [ V_686 ] ) {
V_140 . V_685 = F_145 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_140 . V_685 ) )
return F_18 ( V_140 . V_685 ) ;
}
F_113 ( V_17 ) ;
V_35 = F_167 ( V_7 , V_551 , & V_140 ) ;
if ( ! V_35 ) {
V_17 -> V_557 = V_140 . V_532 ;
V_17 -> V_553 = V_140 . V_553 ;
V_17 -> V_532 = V_140 . V_532 ;
V_17 -> V_604 = V_140 . V_604 ;
memcpy ( V_17 -> V_606 , V_140 . V_606 , V_17 -> V_604 ) ;
}
F_115 ( V_17 ) ;
F_41 ( V_140 . V_685 ) ;
return V_35 ;
}
static int F_168 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_738 V_140 ;
int V_35 ;
if ( V_551 -> V_28 -> V_142 != V_143 &&
V_551 -> V_28 -> V_142 != V_145 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_802 )
return - V_552 ;
if ( ! V_17 -> V_553 )
return - V_16 ;
V_35 = F_160 ( V_30 -> V_5 , & V_140 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
V_35 = F_169 ( V_7 , V_551 , & V_140 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_170 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
return F_171 ( V_7 , V_551 , false ) ;
}
static int F_172 ( struct V_29 * V_30 ,
enum V_274 V_142 ,
struct V_803 * V_140 )
{
struct V_4 * V_51 [ V_804 + 1 ] ;
struct V_4 * V_613 ;
int V_616 ;
V_613 = V_30 -> V_5 [ V_805 ] ;
if ( V_613 ) {
struct V_806 * V_807 ;
V_807 = F_23 ( V_613 ) ;
V_140 -> V_808 = V_807 -> V_697 ;
V_140 -> V_809 = V_807 -> V_810 ;
V_140 -> V_809 &= V_140 -> V_808 ;
if ( ( V_140 -> V_808 |
V_140 -> V_809 ) & F_117 ( V_811 ) )
return - V_16 ;
return 0 ;
}
V_613 = V_30 -> V_5 [ V_812 ] ;
if ( ! V_613 )
return 0 ;
if ( F_33 ( V_51 , V_804 ,
V_613 , V_813 ) )
return - V_16 ;
switch ( V_142 ) {
case V_143 :
case V_144 :
case V_145 :
V_140 -> V_808 = F_117 ( V_814 ) |
F_117 ( V_815 ) |
F_117 ( V_816 ) |
F_117 ( V_817 ) ;
break;
case V_149 :
case V_148 :
V_140 -> V_808 = F_117 ( V_814 ) |
F_117 ( V_818 ) ;
break;
case V_146 :
V_140 -> V_808 = F_117 ( V_819 ) |
F_117 ( V_817 ) |
F_117 ( V_814 ) ;
default:
return - V_16 ;
}
for ( V_616 = 1 ; V_616 <= V_804 ; V_616 ++ ) {
if ( V_51 [ V_616 ] ) {
V_140 -> V_809 |= ( 1 << V_616 ) ;
if ( V_616 > V_820 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_173 ( struct V_31 * V_53 , struct V_821 * V_30 ,
int V_45 )
{
struct V_4 * V_246 ;
V_22 V_266 ;
T_3 V_822 ;
enum V_823 V_824 ;
V_246 = F_47 ( V_53 , V_45 ) ;
if ( ! V_246 )
return false ;
V_266 = F_174 ( V_30 ) ;
V_822 = V_266 < ( 1UL << 16 ) ? V_266 : 0 ;
if ( V_266 > 0 &&
F_28 ( V_53 , V_825 , V_266 ) )
return false ;
if ( V_822 > 0 &&
F_55 ( V_53 , V_826 , V_822 ) )
return false ;
switch ( V_30 -> V_827 ) {
case V_828 :
V_824 = V_829 ;
break;
case V_830 :
V_824 = V_831 ;
break;
default:
F_59 ( 1 ) ;
case V_832 :
V_824 = 0 ;
break;
case V_833 :
V_824 = V_834 ;
break;
case V_835 :
V_824 = V_836 ;
break;
case V_837 :
V_824 = V_838 ;
break;
}
if ( V_824 && F_29 ( V_53 , V_824 ) )
return false ;
if ( V_30 -> V_51 & V_839 ) {
if ( F_56 ( V_53 , V_840 , V_30 -> V_250 ) )
return false ;
if ( V_30 -> V_51 & V_841 &&
F_29 ( V_53 , V_842 ) )
return false ;
} else if ( V_30 -> V_51 & V_843 ) {
if ( F_56 ( V_53 , V_844 , V_30 -> V_250 ) )
return false ;
if ( F_56 ( V_53 , V_845 , V_30 -> V_711 ) )
return false ;
if ( V_30 -> V_51 & V_841 &&
F_29 ( V_53 , V_842 ) )
return false ;
}
F_48 ( V_53 , V_246 ) ;
return true ;
}
static bool F_175 ( struct V_31 * V_53 , T_2 V_697 , T_6 * signal ,
int V_846 )
{
void * V_45 ;
int V_161 = 0 ;
if ( ! V_697 )
return true ;
V_45 = F_47 ( V_53 , V_846 ) ;
if ( ! V_45 )
return false ;
for ( V_161 = 0 ; V_161 < V_847 ; V_161 ++ ) {
if ( ! ( V_697 & F_117 ( V_161 ) ) )
continue;
if ( F_56 ( V_53 , V_161 , signal [ V_161 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_176 ( struct V_31 * V_53 , V_22 V_52 , V_22 V_49 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_551 ,
const T_2 * V_665 , struct V_848 * V_849 )
{
void * V_285 ;
struct V_4 * V_850 , * V_851 ;
V_285 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_285 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_665 ) ||
F_28 ( V_53 , V_295 , V_849 -> V_852 ) )
goto V_61;
V_850 = F_47 ( V_53 , V_853 ) ;
if ( ! V_850 )
goto V_61;
#define F_177 ( V_45 , T_7 , type ) do { \
BUILD_BUG_ON(sizeof(type) == sizeof(u64)); \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_ ## type(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb)) \
goto nla_put_failure; \
} while (0)
#define F_178 ( V_45 , T_7 ) do { \
if (sinfo->filled & (1ULL << NL80211_STA_INFO_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_STA_INFO_ ## attr, \
sinfo->memb, NL80211_STA_INFO_PAD)) \
goto nla_put_failure; \
} while (0)
F_177 ( V_854 , V_855 , V_22 ) ;
F_177 ( V_856 , V_857 , V_22 ) ;
if ( V_849 -> V_858 & ( F_117 ( V_859 ) |
F_117 ( V_860 ) ) &&
F_28 ( V_53 , V_859 ,
( V_22 ) V_849 -> V_861 ) )
goto V_61;
if ( V_849 -> V_858 & ( F_117 ( V_862 ) |
F_117 ( V_863 ) ) &&
F_28 ( V_53 , V_862 ,
( V_22 ) V_849 -> V_864 ) )
goto V_61;
F_178 ( V_865 , V_861 ) ;
F_178 ( V_866 , V_864 ) ;
F_177 ( V_867 , V_868 , T_3 ) ;
F_177 ( V_869 , V_870 , T_3 ) ;
F_177 ( V_871 , V_872 , T_2 ) ;
F_178 ( V_873 , V_874 ) ;
switch ( V_7 -> V_18 . V_875 ) {
case V_876 :
F_177 ( SIGNAL , signal , T_2 ) ;
F_177 ( V_877 , V_878 , T_2 ) ;
break;
default:
break;
}
if ( V_849 -> V_858 & F_117 ( V_879 ) ) {
if ( ! F_175 ( V_53 , V_849 -> V_880 ,
V_849 -> V_881 ,
V_879 ) )
goto V_61;
}
if ( V_849 -> V_858 & F_117 ( V_882 ) ) {
if ( ! F_175 ( V_53 , V_849 -> V_880 ,
V_849 -> V_883 ,
V_882 ) )
goto V_61;
}
if ( V_849 -> V_858 & F_117 ( V_884 ) ) {
if ( ! F_173 ( V_53 , & V_849 -> V_713 ,
V_884 ) )
goto V_61;
}
if ( V_849 -> V_858 & F_117 ( V_885 ) ) {
if ( ! F_173 ( V_53 , & V_849 -> V_886 ,
V_885 ) )
goto V_61;
}
F_177 ( V_887 , V_888 , V_22 ) ;
F_177 ( V_889 , V_890 , V_22 ) ;
F_177 ( V_891 , V_892 , V_22 ) ;
F_177 ( V_893 , V_894 , V_22 ) ;
F_177 ( V_895 , V_896 , V_22 ) ;
F_177 ( V_897 , V_898 , V_22 ) ;
F_177 ( V_899 , V_900 , V_22 ) ;
F_177 ( V_901 , V_902 , V_22 ) ;
F_177 ( V_903 , V_904 , V_22 ) ;
if ( V_849 -> V_858 & F_117 ( V_905 ) ) {
V_851 = F_47 ( V_53 , V_905 ) ;
if ( ! V_851 )
goto V_61;
if ( ( ( V_849 -> V_851 . V_51 & V_906 ) &&
F_29 ( V_53 , V_907 ) ) ||
( ( V_849 -> V_851 . V_51 & V_908 ) &&
F_29 ( V_53 , V_909 ) ) ||
( ( V_849 -> V_851 . V_51 & V_910 ) &&
F_29 ( V_53 , V_911 ) ) ||
F_56 ( V_53 , V_912 ,
V_849 -> V_851 . V_771 ) ||
F_55 ( V_53 , V_913 ,
V_849 -> V_851 . V_553 ) )
goto V_61;
F_48 ( V_53 , V_851 ) ;
}
if ( ( V_849 -> V_858 & F_117 ( V_914 ) ) &&
F_51 ( V_53 , V_914 ,
sizeof( struct V_806 ) ,
& V_849 -> V_807 ) )
goto V_61;
F_178 ( V_915 , V_916 ) ;
F_178 ( V_917 , V_918 ) ;
F_178 ( V_919 , V_920 ) ;
F_177 ( V_921 , V_922 , T_2 ) ;
#undef F_177
#undef F_178
if ( V_849 -> V_858 & F_117 ( V_923 ) ) {
struct V_4 * V_924 ;
int V_925 ;
V_924 = F_47 ( V_53 , V_923 ) ;
if ( ! V_924 )
goto V_61;
for ( V_925 = 0 ; V_925 < V_926 + 1 ; V_925 ++ ) {
struct V_927 * V_928 ;
struct V_4 * V_929 ;
V_928 = & V_849 -> V_930 [ V_925 ] ;
if ( ! V_928 -> V_858 )
continue;
V_929 = F_47 ( V_53 , V_925 + 1 ) ;
if ( ! V_929 )
goto V_61;
#define F_179 ( V_45 , T_7 ) do { \
if (tidstats->filled & BIT(NL80211_TID_STATS_ ## attr) && \
nla_put_u64_64bit(msg, NL80211_TID_STATS_ ## attr, \
tidstats->memb, NL80211_TID_STATS_PAD)) \
goto nla_put_failure; \
} while (0)
F_179 ( V_931 , V_932 ) ;
F_179 ( V_933 , V_934 ) ;
F_179 ( V_935 , V_936 ) ;
F_179 ( V_937 , V_938 ) ;
#undef F_179
F_48 ( V_53 , V_929 ) ;
}
F_48 ( V_53 , V_924 ) ;
}
F_48 ( V_53 , V_850 ) ;
if ( V_849 -> V_939 &&
F_51 ( V_53 , V_742 , V_849 -> V_939 ,
V_849 -> V_940 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int F_180 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_848 V_849 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_665 [ V_599 ] ;
int V_941 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_942;
}
if ( ! V_7 -> V_353 -> V_943 ) {
V_35 = - V_552 ;
goto V_942;
}
while ( 1 ) {
memset ( & V_849 , 0 , sizeof( V_849 ) ) ;
V_35 = F_181 ( V_7 , V_17 -> V_19 , V_941 ,
V_665 , & V_849 ) ;
if ( V_35 == - V_671 )
break;
if ( V_35 )
goto V_942;
if ( F_176 ( V_32 , V_944 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_7 , V_17 -> V_19 , V_665 ,
& V_849 ) < 0 )
goto V_611;
V_941 ++ ;
}
V_611:
V_34 -> args [ 2 ] = V_941 ;
V_35 = V_32 -> V_47 ;
V_942:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_182 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_848 V_849 ;
struct V_31 * V_53 ;
T_2 * V_665 = NULL ;
int V_35 ;
memset ( & V_849 , 0 , sizeof( V_849 ) ) ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_665 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( ! V_7 -> V_353 -> V_945 )
return - V_552 ;
V_35 = F_183 ( V_7 , V_551 , V_665 , & V_849 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
if ( F_176 ( V_53 , V_944 ,
V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_7 , V_551 , V_665 , & V_849 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_184 ( struct V_18 * V_18 ,
struct V_803 * V_140 ,
enum V_946 V_947 )
{
if ( V_140 -> V_948 != - 1 &&
V_947 != V_949 )
return - V_16 ;
if ( V_140 -> V_950 != - 1 &&
V_947 != V_949 )
return - V_16 ;
if ( V_140 -> V_951 &&
! ( V_140 -> V_809 & F_117 ( V_818 ) ) &&
V_947 != V_949 )
return - V_16 ;
F_114 ( V_804 != 7 ) ;
switch ( V_947 ) {
case V_952 :
case V_953 :
if ( V_140 -> V_808 &
~ ( F_117 ( V_819 ) |
F_117 ( V_817 ) |
F_117 ( V_814 ) ) )
return - V_16 ;
break;
case V_954 :
case V_955 :
if ( ! ( V_140 -> V_809 & F_117 ( V_818 ) ) )
return - V_16 ;
V_140 -> V_808 &= ~ F_117 ( V_818 ) ;
break;
default:
if ( V_140 -> V_956 != V_957 )
return - V_16 ;
if ( V_140 -> V_900 )
return - V_16 ;
if ( V_140 -> V_958 & V_959 )
return - V_16 ;
}
if ( V_947 != V_954 &&
V_947 != V_955 ) {
if ( V_140 -> V_809 & F_117 ( V_818 ) )
return - V_16 ;
V_140 -> V_808 &= ~ F_117 ( V_818 ) ;
}
if ( V_947 != V_954 &&
V_947 != V_949 ) {
if ( V_140 -> V_958 & V_960 )
return - V_16 ;
if ( V_140 -> V_958 & V_961 )
return - V_16 ;
if ( V_140 -> V_962 )
return - V_16 ;
if ( V_140 -> V_963 || V_140 -> V_964 || V_140 -> V_965 )
return - V_16 ;
}
if ( V_947 != V_966 &&
V_947 != V_949 ) {
if ( V_140 -> V_967 )
return - V_16 ;
}
switch ( V_947 ) {
case V_968 :
if ( ! ( V_140 -> V_808 & F_117 ( V_814 ) ) )
return - V_552 ;
break;
case V_966 :
case V_949 :
if ( V_140 -> V_808 &
~ ( F_117 ( V_814 ) |
F_117 ( V_819 ) |
F_117 ( V_969 ) |
F_117 ( V_815 ) |
F_117 ( V_816 ) |
F_117 ( V_817 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_293 & V_970 ) &&
V_140 -> V_808 &
( F_117 ( V_819 ) |
F_117 ( V_969 ) ) )
return - V_16 ;
break;
case V_971 :
case V_972 :
if ( V_140 -> V_808 & ~ F_117 ( V_814 ) )
return - V_16 ;
break;
case V_954 :
if ( V_140 -> V_808 & ~ ( F_117 ( V_814 ) |
F_117 ( V_816 ) ) )
return - V_16 ;
if ( V_140 -> V_809 & F_117 ( V_814 ) &&
! V_140 -> V_962 )
return - V_16 ;
break;
case V_955 :
return - V_16 ;
case V_952 :
if ( V_140 -> V_958 & V_959 )
return - V_16 ;
break;
case V_953 :
if ( V_140 -> V_956 != V_957 &&
V_140 -> V_956 != V_973 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_185 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_974 = V_30 -> V_5 [ V_975 ] ;
struct V_25 * V_976 ;
int V_508 ;
if ( ! V_974 )
return NULL ;
V_976 = F_186 ( F_94 ( V_30 ) , F_4 ( V_974 ) ) ;
if ( ! V_976 )
return F_3 ( - V_23 ) ;
if ( ! V_976 -> V_28 || V_976 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_508 = - V_16 ;
goto error;
}
if ( V_976 -> V_28 -> V_142 != V_144 &&
V_976 -> V_28 -> V_142 != V_143 &&
V_976 -> V_28 -> V_142 != V_145 ) {
V_508 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_976 ) ) {
V_508 = - V_566 ;
goto error;
}
return V_976 ;
error:
F_187 ( V_976 ) ;
return F_3 ( V_508 ) ;
}
static int F_188 ( struct V_29 * V_30 ,
struct V_803 * V_140 )
{
struct V_4 * V_95 [ V_977 + 1 ] ;
struct V_4 * V_613 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_978 ] )
return 0 ;
V_613 = V_30 -> V_5 [ V_978 ] ;
V_35 = F_33 ( V_95 , V_977 , V_613 ,
V_979 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_980 ] )
V_140 -> V_981 = F_34 (
V_95 [ V_980 ] ) ;
if ( V_140 -> V_981 & ~ V_982 )
return - V_16 ;
if ( V_95 [ V_983 ] )
V_140 -> V_984 = F_34 ( V_95 [ V_983 ] ) ;
if ( V_140 -> V_984 & ~ V_985 )
return - V_16 ;
V_140 -> V_958 |= V_960 ;
return 0 ;
}
static int F_189 ( struct V_29 * V_30 ,
struct V_803 * V_140 )
{
if ( V_30 -> V_5 [ V_986 ] ) {
V_140 -> V_987 =
F_23 ( V_30 -> V_5 [ V_986 ] ) ;
V_140 -> V_988 =
F_24 ( V_30 -> V_5 [ V_986 ] ) ;
if ( V_140 -> V_988 < 2 )
return - V_16 ;
if ( V_140 -> V_988 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_989 ] ) {
V_140 -> V_990 =
F_23 ( V_30 -> V_5 [ V_989 ] ) ;
V_140 -> V_991 =
F_24 ( V_30 -> V_5 [ V_989 ] ) ;
if ( V_140 -> V_991 < 2 ||
V_140 -> V_991 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_190 ( struct V_29 * V_30 ,
struct V_803 * V_140 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_992 ] )
V_140 -> V_951 = F_78 ( V_30 -> V_5 [ V_992 ] ) ;
if ( V_30 -> V_5 [ V_993 ] )
V_140 -> V_964 =
F_23 ( V_30 -> V_5 [ V_993 ] ) ;
if ( V_30 -> V_5 [ V_994 ] )
V_140 -> V_965 =
F_23 ( V_30 -> V_5 [ V_994 ] ) ;
V_35 = F_189 ( V_30 , V_140 ) ;
if ( V_35 )
return V_35 ;
return F_188 ( V_30 , V_140 ) ;
}
static int F_191 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_803 V_140 ;
T_2 * V_665 ;
int V_35 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( ! V_7 -> V_353 -> V_995 )
return - V_552 ;
if ( V_30 -> V_5 [ V_996 ] )
V_140 . V_951 = F_78 ( V_30 -> V_5 [ V_996 ] ) ;
if ( V_30 -> V_5 [ V_997 ] )
V_140 . V_948 =
F_78 ( V_30 -> V_5 [ V_997 ] ) ;
else
V_140 . V_948 = - 1 ;
if ( V_30 -> V_5 [ V_998 ] ) {
T_2 V_24 ;
V_24 = F_34 ( V_30 -> V_5 [ V_998 ] ) ;
if ( V_24 >= V_999 )
return - V_16 ;
V_140 . V_950 = V_24 ;
} else {
V_140 . V_950 = - 1 ;
}
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_665 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( V_30 -> V_5 [ V_1000 ] ) {
V_140 . V_962 =
F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
V_140 . V_1001 =
F_24 ( V_30 -> V_5 [ V_1000 ] ) ;
}
if ( V_30 -> V_5 [ V_1002 ] ) {
V_140 . V_1003 =
F_78 ( V_30 -> V_5 [ V_1002 ] ) ;
V_140 . V_958 |= V_961 ;
}
if ( V_30 -> V_5 [ V_1004 ] ) {
V_140 . V_963 =
F_23 ( V_30 -> V_5 [ V_1004 ] ) ;
V_140 . V_1005 =
F_24 ( V_30 -> V_5 [ V_1004 ] ) ;
}
if ( F_172 ( V_30 , V_551 -> V_28 -> V_142 , & V_140 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_1006 ] ) {
V_140 . V_956 =
F_34 ( V_30 -> V_5 [ V_1006 ] ) ;
if ( V_140 . V_956 >= V_1007 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1008 ] ) {
V_140 . V_872 =
F_34 ( V_30 -> V_5 [ V_1008 ] ) ;
if ( V_140 . V_872 >= V_1009 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1010 ] ) {
V_140 . V_1011 = F_78 (
V_30 -> V_5 [ V_1010 ] ) ;
if ( V_140 . V_1011 > V_1012 )
return - V_16 ;
}
V_140 . V_958 |= V_959 ;
}
if ( V_30 -> V_5 [ V_1013 ] ) {
enum V_1014 V_1015 = F_4 (
V_30 -> V_5 [ V_1013 ] ) ;
if ( V_1015 <= V_1016 ||
V_1015 > V_1017 )
return - V_16 ;
V_140 . V_900 = V_1015 ;
}
V_35 = F_190 ( V_30 , & V_140 ) ;
if ( V_35 )
return V_35 ;
V_140 . V_967 = F_185 ( V_30 , V_7 ) ;
if ( F_17 ( V_140 . V_967 ) )
return F_18 ( V_140 . V_967 ) ;
switch ( V_551 -> V_28 -> V_142 ) {
case V_143 :
case V_144 :
case V_145 :
case V_149 :
case V_148 :
case V_147 :
case V_146 :
break;
default:
V_35 = - V_552 ;
goto V_1018;
}
V_35 = F_192 ( V_7 , V_551 , V_665 , & V_140 ) ;
V_1018:
if ( V_140 . V_967 )
F_187 ( V_140 . V_967 ) ;
return V_35 ;
}
static int F_193 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int V_35 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_803 V_140 ;
T_2 * V_665 = NULL ;
V_22 V_1019 = F_117 ( V_819 ) |
F_117 ( V_969 ) ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( ! V_7 -> V_353 -> V_379 )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_997 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1000 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_996 ] &&
! V_30 -> V_5 [ V_992 ] )
return - V_16 ;
V_665 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_140 . V_962 =
F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
V_140 . V_1001 =
F_24 ( V_30 -> V_5 [ V_1000 ] ) ;
V_140 . V_948 =
F_78 ( V_30 -> V_5 [ V_997 ] ) ;
if ( V_30 -> V_5 [ V_998 ] ) {
T_2 V_24 ;
V_24 = F_34 ( V_30 -> V_5 [ V_998 ] ) ;
if ( V_24 >= V_999 )
return - V_16 ;
V_140 . V_950 = V_24 ;
} else {
V_140 . V_950 =
V_551 -> V_28 -> V_142 == V_145 ;
}
if ( V_30 -> V_5 [ V_992 ] )
V_140 . V_951 = F_78 ( V_30 -> V_5 [ V_992 ] ) ;
else
V_140 . V_951 = F_78 ( V_30 -> V_5 [ V_996 ] ) ;
if ( ! V_140 . V_951 || V_140 . V_951 > V_1012 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1002 ] ) {
V_140 . V_1003 =
F_78 ( V_30 -> V_5 [ V_1002 ] ) ;
V_140 . V_958 |= V_961 ;
}
if ( V_30 -> V_5 [ V_1004 ] ) {
V_140 . V_963 =
F_23 ( V_30 -> V_5 [ V_1004 ] ) ;
V_140 . V_1005 =
F_24 ( V_30 -> V_5 [ V_1004 ] ) ;
}
if ( V_30 -> V_5 [ V_993 ] )
V_140 . V_964 =
F_23 ( V_30 -> V_5 [ V_993 ] ) ;
if ( V_30 -> V_5 [ V_994 ] )
V_140 . V_965 =
F_23 ( V_30 -> V_5 [ V_994 ] ) ;
if ( V_30 -> V_5 [ V_1020 ] ) {
V_140 . V_1021 = true ;
V_140 . V_1022 =
F_34 ( V_30 -> V_5 [ V_1020 ] ) ;
}
if ( V_30 -> V_5 [ V_1006 ] ) {
V_140 . V_956 =
F_34 ( V_30 -> V_5 [ V_1006 ] ) ;
if ( V_140 . V_956 >= V_1007 )
return - V_16 ;
}
V_35 = F_189 ( V_30 , & V_140 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_188 ( V_30 , & V_140 ) ;
if ( V_35 )
return V_35 ;
if ( F_172 ( V_30 , V_551 -> V_28 -> V_142 , & V_140 ) )
return - V_16 ;
if ( ! ( V_140 . V_809 & F_117 ( V_816 ) ) ) {
V_140 . V_964 = NULL ;
V_140 . V_965 = NULL ;
}
F_114 ( V_804 != 7 ) ;
switch ( V_551 -> V_28 -> V_142 ) {
case V_143 :
case V_144 :
case V_145 :
if ( ! ( V_7 -> V_18 . V_51 & V_330 ) ||
! ( V_140 . V_809 & F_117 ( V_816 ) ) )
V_140 . V_958 &= ~ V_960 ;
if ( ( V_140 . V_809 & F_117 ( V_818 ) ) ||
V_30 -> V_5 [ V_992 ] )
return - V_16 ;
V_140 . V_808 &= ~ F_117 ( V_818 ) ;
if ( ! ( V_7 -> V_18 . V_293 &
V_970 ) &&
V_140 . V_808 & V_1019 )
return - V_16 ;
if ( ! ( V_140 . V_808 & V_1019 ) ) {
V_140 . V_808 |= V_1019 ;
V_140 . V_809 |= V_1019 ;
}
V_140 . V_967 = F_185 ( V_30 , V_7 ) ;
if ( F_17 ( V_140 . V_967 ) )
return F_18 ( V_140 . V_967 ) ;
break;
case V_146 :
V_140 . V_958 &= ~ V_960 ;
if ( V_140 . V_808 & F_117 ( V_969 ) )
return - V_16 ;
if ( ( V_140 . V_809 & F_117 ( V_818 ) ) ||
V_30 -> V_5 [ V_992 ] )
return - V_16 ;
break;
case V_148 :
case V_149 :
V_140 . V_958 &= ~ V_960 ;
if ( V_140 . V_808 &
( F_117 ( V_969 ) |
F_117 ( V_819 ) ) )
return - V_16 ;
if ( ! ( V_140 . V_809 & F_117 ( V_818 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_334 ) )
return - V_552 ;
if ( ! ( V_7 -> V_18 . V_51 & V_336 ) )
return - V_552 ;
V_140 . V_808 &= ~ F_117 ( V_814 ) ;
break;
default:
return - V_552 ;
}
V_35 = F_194 ( V_7 , V_551 , V_665 , & V_140 ) ;
if ( V_140 . V_967 )
F_187 ( V_140 . V_967 ) ;
return V_35 ;
}
static int F_195 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1023 V_140 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( V_30 -> V_5 [ V_559 ] )
V_140 . V_1024 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( V_551 -> V_28 -> V_142 != V_143 &&
V_551 -> V_28 -> V_142 != V_144 &&
V_551 -> V_28 -> V_142 != V_146 &&
V_551 -> V_28 -> V_142 != V_145 )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_1025 )
return - V_552 ;
if ( V_30 -> V_5 [ V_1026 ] ) {
V_140 . V_1027 =
F_34 ( V_30 -> V_5 [ V_1026 ] ) ;
if ( V_140 . V_1027 != V_1028 >> 4 &&
V_140 . V_1027 != V_1029 >> 4 )
return - V_16 ;
} else {
V_140 . V_1027 = V_1029 >> 4 ;
}
if ( V_30 -> V_5 [ V_1030 ] ) {
V_140 . V_1031 =
F_78 ( V_30 -> V_5 [ V_1030 ] ) ;
if ( V_140 . V_1031 == 0 )
return - V_16 ;
} else {
V_140 . V_1031 = V_1032 ;
}
return F_196 ( V_7 , V_551 , & V_140 ) ;
}
static int F_197 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_551 ,
T_2 * V_1033 , T_2 * V_1034 ,
struct V_1035 * V_1036 )
{
void * V_285 ;
struct V_4 * V_1037 ;
V_285 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_1038 ) ;
if ( ! V_285 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_1033 ) ||
F_51 ( V_53 , V_1039 , V_599 , V_1034 ) ||
F_28 ( V_53 , V_295 , V_1036 -> V_852 ) )
goto V_61;
V_1037 = F_47 ( V_53 , V_1040 ) ;
if ( ! V_1037 )
goto V_61;
if ( ( V_1036 -> V_858 & V_1041 ) &&
F_28 ( V_53 , V_1042 ,
V_1036 -> V_1043 ) )
goto V_61;
if ( ( ( V_1036 -> V_858 & V_1044 ) &&
F_28 ( V_53 , V_1045 , V_1036 -> V_1046 ) ) ||
( ( V_1036 -> V_858 & V_1047 ) &&
F_28 ( V_53 , V_1048 ,
V_1036 -> V_1049 ) ) ||
( ( V_1036 -> V_858 & V_1050 ) &&
F_28 ( V_53 , V_1051 ,
V_1036 -> V_1052 ) ) ||
( ( V_1036 -> V_858 & V_1053 ) &&
F_56 ( V_53 , V_1054 ,
V_1036 -> V_51 ) ) ||
( ( V_1036 -> V_858 & V_1055 ) &&
F_28 ( V_53 , V_1056 ,
V_1036 -> V_1057 ) ) ||
( ( V_1036 -> V_858 & V_1058 ) &&
F_56 ( V_53 , V_1059 ,
V_1036 -> V_1060 ) ) )
goto V_61;
F_48 ( V_53 , V_1037 ) ;
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int F_198 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1035 V_1036 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1033 [ V_599 ] ;
T_2 V_1034 [ V_599 ] ;
int V_1061 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_353 -> V_1062 ) {
V_35 = - V_552 ;
goto V_942;
}
if ( V_17 -> V_142 != V_146 ) {
V_35 = - V_552 ;
goto V_942;
}
while ( 1 ) {
V_35 = F_199 ( V_7 , V_17 -> V_19 , V_1061 , V_1033 ,
V_1034 , & V_1036 ) ;
if ( V_35 == - V_671 )
break;
if ( V_35 )
goto V_942;
if ( F_197 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_17 -> V_19 , V_1033 , V_1034 ,
& V_1036 ) < 0 )
goto V_611;
V_1061 ++ ;
}
V_611:
V_34 -> args [ 2 ] = V_1061 ;
V_35 = V_32 -> V_47 ;
V_942:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_200 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int V_35 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1035 V_1036 ;
struct V_31 * V_53 ;
T_2 * V_1033 = NULL ;
T_2 V_1034 [ V_599 ] ;
memset ( & V_1036 , 0 , sizeof( V_1036 ) ) ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_1033 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( ! V_7 -> V_353 -> V_1063 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_146 )
return - V_552 ;
V_35 = F_201 ( V_7 , V_551 , V_1033 , V_1034 , & V_1036 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
if ( F_197 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_551 , V_1033 , V_1034 , & V_1036 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_202 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 * V_1033 = NULL ;
T_2 * V_1034 = NULL ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1039 ] )
return - V_16 ;
V_1033 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_1034 = F_23 ( V_30 -> V_5 [ V_1039 ] ) ;
if ( ! V_7 -> V_353 -> V_1064 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_146 )
return - V_552 ;
return F_203 ( V_7 , V_551 , V_1033 , V_1034 ) ;
}
static int F_204 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 * V_1033 = NULL ;
T_2 * V_1034 = NULL ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1039 ] )
return - V_16 ;
V_1033 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_1034 = F_23 ( V_30 -> V_5 [ V_1039 ] ) ;
if ( ! V_7 -> V_353 -> V_381 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_146 )
return - V_552 ;
return F_205 ( V_7 , V_551 , V_1033 , V_1034 ) ;
}
static int F_206 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 * V_1033 = NULL ;
if ( V_30 -> V_5 [ V_559 ] )
V_1033 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( ! V_7 -> V_353 -> V_1065 )
return - V_552 ;
return F_207 ( V_7 , V_551 , V_1033 ) ;
}
static int F_208 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int V_35 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1035 V_1036 ;
struct V_31 * V_53 ;
T_2 * V_1033 = NULL ;
T_2 V_1066 [ V_599 ] ;
memset ( & V_1036 , 0 , sizeof( V_1036 ) ) ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_1033 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( ! V_7 -> V_353 -> V_1067 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_146 )
return - V_552 ;
V_35 = F_209 ( V_7 , V_551 , V_1033 , V_1066 , & V_1036 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
if ( F_197 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_551 , V_1033 , V_1066 , & V_1036 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_210 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1035 V_1036 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_1033 [ V_599 ] ;
T_2 V_1066 [ V_599 ] ;
int V_1061 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_353 -> V_1068 ) {
V_35 = - V_552 ;
goto V_942;
}
if ( V_17 -> V_142 != V_146 ) {
V_35 = - V_552 ;
goto V_942;
}
while ( 1 ) {
V_35 = F_211 ( V_7 , V_17 -> V_19 , V_1061 , V_1033 ,
V_1066 , & V_1036 ) ;
if ( V_35 == - V_671 )
break;
if ( V_35 )
goto V_942;
if ( F_197 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_17 -> V_19 , V_1033 , V_1066 ,
& V_1036 ) < 0 )
goto V_611;
V_1061 ++ ;
}
V_611:
V_34 -> args [ 2 ] = V_1061 ;
V_35 = V_32 -> V_47 ;
V_942:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_212 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_1069 V_140 ;
int V_35 ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_1070 = - 1 ;
V_140 . V_1071 = - 1 ;
V_140 . V_1072 = - 1 ;
V_140 . V_1073 = - 1 ;
V_140 . V_1074 = - 1 ;
V_140 . V_787 = - 1 ;
V_140 . V_790 = - 1 ;
if ( V_30 -> V_5 [ V_1075 ] )
V_140 . V_1070 =
F_34 ( V_30 -> V_5 [ V_1075 ] ) ;
if ( V_30 -> V_5 [ V_1076 ] )
V_140 . V_1071 =
F_34 ( V_30 -> V_5 [ V_1076 ] ) ;
if ( V_30 -> V_5 [ V_1077 ] )
V_140 . V_1072 =
F_34 ( V_30 -> V_5 [ V_1077 ] ) ;
if ( V_30 -> V_5 [ V_1078 ] ) {
V_140 . V_1079 =
F_23 ( V_30 -> V_5 [ V_1078 ] ) ;
V_140 . V_1080 =
F_24 ( V_30 -> V_5 [ V_1078 ] ) ;
}
if ( V_30 -> V_5 [ V_1081 ] )
V_140 . V_1073 = ! ! F_34 ( V_30 -> V_5 [ V_1081 ] ) ;
if ( V_30 -> V_5 [ V_1082 ] )
V_140 . V_1074 =
F_78 ( V_30 -> V_5 [ V_1082 ] ) ;
if ( V_30 -> V_5 [ V_786 ] ) {
if ( V_551 -> V_28 -> V_142 != V_145 )
return - V_16 ;
V_140 . V_787 =
F_213 ( V_30 -> V_5 [ V_786 ] ) ;
if ( V_140 . V_787 < 0 )
return - V_16 ;
if ( V_140 . V_787 != 0 &&
! ( V_7 -> V_18 . V_293 & V_788 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_789 ] ) {
T_2 V_24 ;
if ( V_551 -> V_28 -> V_142 != V_145 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_789 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_140 . V_790 = V_24 ;
if ( V_140 . V_790 &&
! ( V_7 -> V_18 . V_293 & V_791 ) )
return - V_16 ;
}
if ( ! V_7 -> V_353 -> V_385 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_143 &&
V_551 -> V_28 -> V_142 != V_145 )
return - V_552 ;
F_113 ( V_17 ) ;
V_35 = F_214 ( V_7 , V_551 , & V_140 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_215 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_141 = NULL ;
bool V_1083 ;
enum V_1084 V_1085 ;
V_22 V_650 ;
if ( F_216 ( ! F_217 ( V_1086 ) ) )
return - V_1087 ;
if ( V_30 -> V_5 [ V_1088 ] )
V_1085 =
F_4 ( V_30 -> V_5 [ V_1088 ] ) ;
else
V_1085 = V_1089 ;
switch ( V_1085 ) {
case V_1089 :
case V_1090 :
if ( ! V_30 -> V_5 [ V_1091 ] )
return - V_16 ;
V_141 = F_23 ( V_30 -> V_5 [ V_1091 ] ) ;
return F_218 ( V_141 , V_1085 ) ;
case V_1092 :
if ( V_30 -> V_5 [ V_649 ] ) {
V_650 = V_30 -> V_516 ;
V_1083 = ! ! V_30 -> V_5 [ V_1093 ] ;
} else {
V_650 = 0 ;
V_1083 = true ;
}
return F_219 ( V_1083 , V_650 ) ;
default:
return - V_16 ;
}
}
static int F_220 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_1094 V_1095 ;
int V_35 = 0 ;
void * V_285 ;
struct V_4 * V_1037 ;
struct V_31 * V_53 ;
if ( V_17 -> V_142 != V_146 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_1096 )
return - V_552 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1097 )
memcpy ( & V_1095 , & V_1098 , sizeof( V_1095 ) ) ;
else
V_35 = F_221 ( V_7 , V_551 , & V_1095 ) ;
F_115 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1099 ) ;
if ( ! V_285 )
goto V_611;
V_1037 = F_47 ( V_53 , V_1100 ) ;
if ( ! V_1037 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_55 ( V_53 , V_1101 ,
V_1095 . V_1102 ) ||
F_55 ( V_53 , V_1103 ,
V_1095 . V_1104 ) ||
F_55 ( V_53 , V_1105 ,
V_1095 . V_1106 ) ||
F_55 ( V_53 , V_1107 ,
V_1095 . V_1108 ) ||
F_56 ( V_53 , V_1109 ,
V_1095 . V_1110 ) ||
F_56 ( V_53 , V_1111 ,
V_1095 . V_1112 ) ||
F_56 ( V_53 , V_1113 ,
V_1095 . V_1114 ) ||
F_56 ( V_53 , V_1115 ,
V_1095 . V_1116 ) ||
F_28 ( V_53 , V_1117 ,
V_1095 . V_1118 ) ||
F_56 ( V_53 , V_1119 ,
V_1095 . V_1120 ) ||
F_28 ( V_53 , V_1121 ,
V_1095 . V_1122 ) ||
F_55 ( V_53 , V_1123 ,
V_1095 . V_1124 ) ||
F_28 ( V_53 , V_1125 ,
V_1095 . V_1126 ) ||
F_55 ( V_53 , V_1127 ,
V_1095 . V_1128 ) ||
F_55 ( V_53 , V_1129 ,
V_1095 . V_1130 ) ||
F_55 ( V_53 , V_1131 ,
V_1095 . V_1132 ) ||
F_56 ( V_53 , V_1133 ,
V_1095 . V_1134 ) ||
F_55 ( V_53 , V_1135 ,
V_1095 . V_1136 ) ||
F_56 ( V_53 , V_1137 ,
V_1095 . V_1138 ) ||
F_56 ( V_53 , V_1139 ,
V_1095 . V_1140 ) ||
F_28 ( V_53 , V_1141 ,
V_1095 . V_1142 ) ||
F_28 ( V_53 , V_1143 ,
V_1095 . V_1074 ) ||
F_28 ( V_53 , V_1144 ,
V_1095 . V_1145 ) ||
F_55 ( V_53 , V_1146 ,
V_1095 . V_1147 ) ||
F_55 ( V_53 , V_1148 ,
V_1095 . V_1149 ) ||
F_28 ( V_53 , V_1150 ,
V_1095 . V_1151 ) ||
F_55 ( V_53 , V_1152 ,
V_1095 . V_1153 ) ||
F_28 ( V_53 , V_1154 ,
V_1095 . V_1155 ) )
goto V_61;
F_48 ( V_53 , V_1037 ) ;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_285 ) ;
V_611:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_222 ( const struct V_4 * V_613 , T_2 V_1156 , T_2 V_176 , bool * V_611 )
{
T_2 V_1157 = F_34 ( V_613 ) ;
if ( V_1157 < V_1156 || V_1157 > V_176 )
return - V_16 ;
* V_611 = V_1157 ;
return 0 ;
}
static int F_223 ( const struct V_4 * V_613 , T_2 V_1156 , T_2 V_176 , T_2 * V_611 )
{
T_2 V_1157 = F_34 ( V_613 ) ;
if ( V_1157 < V_1156 || V_1157 > V_176 )
return - V_16 ;
* V_611 = V_1157 ;
return 0 ;
}
static int F_224 ( const struct V_4 * V_613 , T_3 V_1156 , T_3 V_176 , T_3 * V_611 )
{
T_3 V_1157 = F_78 ( V_613 ) ;
if ( V_1157 < V_1156 || V_1157 > V_176 )
return - V_16 ;
* V_611 = V_1157 ;
return 0 ;
}
static int F_225 ( const struct V_4 * V_613 , V_22 V_1156 , V_22 V_176 , V_22 * V_611 )
{
V_22 V_1157 = F_4 ( V_613 ) ;
if ( V_1157 < V_1156 || V_1157 > V_176 )
return - V_16 ;
* V_611 = V_1157 ;
return 0 ;
}
static int F_226 ( const struct V_4 * V_613 , T_8 V_1156 , T_8 V_176 , T_8 * V_611 )
{
T_8 V_1157 = F_227 ( V_613 ) ;
if ( V_1157 < V_1156 || V_1157 > V_176 )
return - V_16 ;
* V_611 = V_1157 ;
return 0 ;
}
static int F_228 ( const struct V_4 * V_613 ,
enum V_1014 V_1156 ,
enum V_1014 V_176 ,
enum V_1014 * V_611 )
{
V_22 V_1157 = F_4 ( V_613 ) ;
if ( V_1157 < V_1156 || V_1157 > V_176 )
return - V_16 ;
* V_611 = V_1157 ;
return 0 ;
}
static int F_229 ( struct V_29 * V_30 ,
struct V_1094 * V_1158 ,
V_22 * V_1159 )
{
struct V_4 * V_95 [ V_1160 + 1 ] ;
V_22 V_697 = 0 ;
T_3 V_1074 ;
#define F_230 ( V_95 , V_1158 , T_9 , V_1156 , V_176 , V_697 , V_45 , T_10 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr], min, max, &cfg->param)) \
return -EINVAL; \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1100 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1160 ,
V_30 -> V_5 [ V_1100 ] ,
V_1161 ) )
return - V_16 ;
F_114 ( V_1160 > 32 ) ;
F_230 ( V_95 , V_1158 , V_1102 , 1 , 255 ,
V_697 , V_1101 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1104 , 1 , 255 ,
V_697 , V_1103 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1106 , 1 , 255 ,
V_697 , V_1105 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1108 , 0 , 255 ,
V_697 , V_1107 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1110 , 0 , 16 ,
V_697 , V_1109 ,
F_223 ) ;
F_230 ( V_95 , V_1158 , V_1112 , 1 , 255 ,
V_697 , V_1111 , F_223 ) ;
F_230 ( V_95 , V_1158 , V_1114 , 1 , 255 ,
V_697 , V_1113 ,
F_223 ) ;
F_230 ( V_95 , V_1158 , V_1116 , 0 , 1 ,
V_697 , V_1115 ,
F_222 ) ;
F_230 ( V_95 , V_1158 , V_1118 ,
1 , 255 , V_697 ,
V_1117 ,
F_225 ) ;
F_230 ( V_95 , V_1158 , V_1120 , 0 , 255 ,
V_697 , V_1119 ,
F_223 ) ;
F_230 ( V_95 , V_1158 , V_1122 , 1 , 65535 ,
V_697 , V_1121 ,
F_225 ) ;
F_230 ( V_95 , V_1158 , V_1124 , 1 , 65535 ,
V_697 , V_1123 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1126 ,
1 , 65535 , V_697 ,
V_1125 ,
F_225 ) ;
F_230 ( V_95 , V_1158 , V_1128 ,
1 , 65535 , V_697 ,
V_1127 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1130 ,
1 , 65535 , V_697 ,
V_1129 ,
F_224 ) ;
F_230 ( V_95 , V_1158 ,
V_1132 ,
1 , 65535 , V_697 ,
V_1131 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1134 , 0 , 4 ,
V_697 , V_1133 ,
F_223 ) ;
F_230 ( V_95 , V_1158 , V_1136 , 1 , 65535 ,
V_697 , V_1135 ,
F_224 ) ;
F_230 ( V_95 , V_1158 ,
V_1138 , 0 , 1 ,
V_697 , V_1137 ,
F_222 ) ;
F_230 ( V_95 , V_1158 , V_1140 , 0 , 1 ,
V_697 , V_1139 ,
F_222 ) ;
F_230 ( V_95 , V_1158 , V_1142 , - 255 , 0 ,
V_697 , V_1141 ,
F_226 ) ;
if ( V_95 [ V_1143 ] ) {
V_1074 = F_78 ( V_95 [ V_1143 ] ) ;
if ( V_1074 & ~ ( V_1162 |
V_1163 |
V_1164 ) )
return - V_16 ;
if ( ( V_1074 & V_1163 ) &&
( V_1074 & V_1164 ) )
return - V_16 ;
switch ( V_1074 & V_1162 ) {
case V_1165 :
case V_1166 :
if ( V_1074 & V_1164 )
return - V_16 ;
break;
case V_1167 :
case V_1168 :
if ( ! ( V_1074 & V_1164 ) )
return - V_16 ;
break;
}
V_1158 -> V_1074 = V_1074 ;
}
F_230 ( V_95 , V_1158 , V_1145 ,
1 , 65535 , V_697 ,
V_1144 ,
F_225 ) ;
F_230 ( V_95 , V_1158 , V_1147 , 1 , 65535 ,
V_697 , V_1146 ,
F_224 ) ;
F_230 ( V_95 , V_1158 ,
V_1149 ,
1 , 65535 , V_697 ,
V_1148 ,
F_224 ) ;
F_230 ( V_95 , V_1158 , V_1151 ,
V_1169 ,
V_1017 ,
V_697 , V_1150 ,
F_228 ) ;
F_230 ( V_95 , V_1158 , V_1153 ,
0 , 65535 , V_697 ,
V_1152 , F_224 ) ;
F_230 ( V_95 , V_1158 , V_1155 , 0 , 0xffffffff ,
V_697 , V_1154 ,
F_225 ) ;
if ( V_1159 )
* V_1159 = V_697 ;
return 0 ;
#undef F_230
}
static int F_231 ( struct V_29 * V_30 ,
struct V_1170 * V_1171 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_4 * V_95 [ V_1172 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1173 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1172 ,
V_30 -> V_5 [ V_1173 ] ,
V_1174 ) )
return - V_16 ;
if ( V_95 [ V_1175 ] )
V_1171 -> V_1176 =
( F_34 ( V_95 [ V_1175 ] ) ) ?
V_1177 :
V_1178 ;
if ( V_95 [ V_1179 ] )
V_1171 -> V_1180 =
( F_34 ( V_95 [ V_1179 ] ) ) ?
V_1181 :
V_1182 ;
if ( V_95 [ V_1183 ] )
V_1171 -> V_1184 =
( F_34 ( V_95 [ V_1183 ] ) ) ?
V_1185 :
V_1186 ;
if ( V_95 [ V_1187 ] ) {
struct V_4 * V_1188 =
V_95 [ V_1187 ] ;
if ( ! F_22 ( V_1188 ) )
return - V_16 ;
V_1171 -> V_1189 = F_23 ( V_1188 ) ;
V_1171 -> V_1190 = F_24 ( V_1188 ) ;
}
if ( V_95 [ V_1191 ] &&
! ( V_7 -> V_18 . V_293 & V_1192 ) )
return - V_16 ;
V_1171 -> V_1193 = F_166 ( V_95 [ V_1191 ] ) ;
V_1171 -> V_1194 = F_166 ( V_95 [ V_1195 ] ) ;
V_1171 -> V_1196 = F_166 ( V_95 [ V_1197 ] ) ;
if ( V_1171 -> V_1196 )
V_1171 -> V_1193 = true ;
if ( V_95 [ V_1198 ] ) {
if ( ! V_1171 -> V_1193 )
return - V_16 ;
V_1171 -> V_1199 =
F_34 ( V_95 [ V_1198 ] ) ;
}
return 0 ;
}
static int F_232 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_1094 V_1158 ;
V_22 V_697 ;
int V_35 ;
if ( V_17 -> V_142 != V_146 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_383 )
return - V_552 ;
V_35 = F_229 ( V_30 , & V_1158 , & V_697 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_1097 )
V_35 = - V_151 ;
if ( ! V_35 )
V_35 = F_233 ( V_7 , V_551 , V_697 , & V_1158 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_234 ( const struct V_1200 * V_1201 ,
struct V_31 * V_53 )
{
struct V_4 * V_1202 ;
unsigned int V_161 ;
if ( F_60 ( V_53 , V_1091 , V_1201 -> V_1203 ) ||
( V_1201 -> V_1204 &&
F_56 ( V_53 , V_1205 , V_1201 -> V_1204 ) ) )
goto V_61;
V_1202 = F_47 ( V_53 , V_1206 ) ;
if ( ! V_1202 )
goto V_61;
for ( V_161 = 0 ; V_161 < V_1201 -> V_1207 ; V_161 ++ ) {
struct V_4 * V_1208 ;
const struct V_1209 * V_1210 ;
const struct V_1211 * V_1212 ;
const struct V_1213 * V_1214 ;
unsigned int V_1215 ;
V_1210 = & V_1201 -> V_1216 [ V_161 ] ;
V_1212 = & V_1210 -> V_1212 ;
V_1214 = & V_1210 -> V_1214 ;
V_1208 = F_47 ( V_53 , V_161 ) ;
if ( ! V_1208 )
goto V_61;
V_1215 = V_1212 -> V_1215 ;
if ( ! V_1215 )
V_1215 = F_235 ( V_1201 ,
V_1210 ) ;
if ( F_28 ( V_53 , V_1217 ,
V_1210 -> V_51 ) ||
F_28 ( V_53 , V_1218 ,
V_1212 -> V_1219 ) ||
F_28 ( V_53 , V_1220 ,
V_1212 -> V_1221 ) ||
F_28 ( V_53 , V_1222 ,
V_1215 ) ||
F_28 ( V_53 , V_1223 ,
V_1214 -> V_1224 ) ||
F_28 ( V_53 , V_1225 ,
V_1214 -> V_1226 ) ||
F_28 ( V_53 , V_1227 ,
V_1210 -> V_74 ) )
goto V_61;
F_48 ( V_53 , V_1208 ) ;
}
F_48 ( V_53 , V_1202 ) ;
return 0 ;
V_61:
return - V_507 ;
}
static int F_236 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1200 * V_1201 = NULL ;
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_91 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1228 ) ;
if ( ! V_285 )
goto V_1229;
if ( V_30 -> V_5 [ V_26 ] ) {
bool V_1230 ;
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_7 ) ;
}
V_18 = & V_7 -> V_18 ;
V_1230 = V_18 -> V_492 &
V_493 ;
V_1201 = F_237 ( V_18 ) ;
if ( F_59 ( ! V_1201 && V_1230 ) ) {
F_75 ( V_53 ) ;
return - V_16 ;
}
if ( V_1201 &&
F_28 ( V_53 , V_26 , F_238 ( V_18 ) ) )
goto V_61;
}
if ( ! V_18 && F_239 () &&
F_28 ( V_53 , V_1088 ,
V_1090 ) )
goto V_61;
F_240 () ;
if ( ! V_1201 )
V_1201 = F_241 ( V_1086 ) ;
if ( F_234 ( V_1201 , V_53 ) )
goto V_1231;
F_242 () ;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1231:
F_242 () ;
V_61:
F_67 ( V_53 , V_285 ) ;
V_1229:
F_75 ( V_53 ) ;
return - V_507 ;
}
static int F_243 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 , struct V_18 * V_18 ,
const struct V_1200 * V_1201 )
{
void * V_285 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1228 ) ;
if ( ! V_285 )
return - 1 ;
F_244 ( V_34 , V_285 , & V_38 ) ;
if ( F_234 ( V_1201 , V_53 ) )
goto V_61;
if ( ! V_18 && F_239 () &&
F_28 ( V_53 , V_1088 ,
V_1090 ) )
goto V_61;
if ( V_18 &&
F_28 ( V_53 , V_26 , F_238 ( V_18 ) ) )
goto V_61;
if ( V_18 && V_18 -> V_492 & V_493 &&
F_29 ( V_53 , V_494 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int F_245 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
const struct V_1200 * V_1201 = NULL ;
struct V_6 * V_7 ;
int V_35 , V_1232 , V_511 = V_34 -> args [ 2 ] ;
F_14 () ;
if ( V_1086 && V_511 == 0 ) {
V_35 = F_243 ( V_32 , V_34 , V_34 -> V_36 -> V_512 ,
V_513 , NULL ,
F_246 ( V_1086 ) ) ;
if ( V_35 < 0 )
goto V_942;
}
V_1232 = 1 ;
F_6 (rdev, &cfg80211_rdev_list, list) {
V_1201 = F_237 ( & V_7 -> V_18 ) ;
if ( ! V_1201 )
continue;
if ( ++ V_1232 <= V_511 )
continue;
V_35 = F_243 ( V_32 , V_34 , V_34 -> V_36 -> V_512 ,
V_513 , & V_7 -> V_18 , V_1201 ) ;
if ( V_35 < 0 ) {
V_1232 -- ;
break;
}
}
V_34 -> args [ 2 ] = V_1232 ;
V_35 = V_32 -> V_47 ;
V_942:
F_20 () ;
return V_35 ;
}
static int F_247 ( struct V_4 * V_95 [] ,
struct V_1209 * V_1210 )
{
struct V_1211 * V_1212 = & V_1210 -> V_1212 ;
struct V_1213 * V_1214 = & V_1210 -> V_1214 ;
if ( ! V_95 [ V_1217 ] )
return - V_16 ;
if ( ! V_95 [ V_1218 ] )
return - V_16 ;
if ( ! V_95 [ V_1220 ] )
return - V_16 ;
if ( ! V_95 [ V_1222 ] )
return - V_16 ;
if ( ! V_95 [ V_1225 ] )
return - V_16 ;
V_1210 -> V_51 = F_4 ( V_95 [ V_1217 ] ) ;
V_1212 -> V_1219 =
F_4 ( V_95 [ V_1218 ] ) ;
V_1212 -> V_1221 =
F_4 ( V_95 [ V_1220 ] ) ;
V_1212 -> V_1215 =
F_4 ( V_95 [ V_1222 ] ) ;
V_1214 -> V_1226 =
F_4 ( V_95 [ V_1225 ] ) ;
if ( V_95 [ V_1223 ] )
V_1214 -> V_1224 =
F_4 ( V_95 [ V_1223 ] ) ;
if ( V_95 [ V_1227 ] )
V_1210 -> V_74 =
F_4 ( V_95 [ V_1227 ] ) ;
return 0 ;
}
static int F_248 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1233 + 1 ] ;
struct V_4 * V_1208 ;
char * V_1203 ;
int V_1234 , V_1235 ;
V_22 V_1236 = 0 , V_1237 = 0 , V_1238 ;
enum V_1239 V_1204 = V_1240 ;
struct V_1200 * V_1241 ;
if ( ! V_30 -> V_5 [ V_1091 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1206 ] )
return - V_16 ;
V_1203 = F_23 ( V_30 -> V_5 [ V_1091 ] ) ;
if ( V_30 -> V_5 [ V_1205 ] )
V_1204 = F_34 ( V_30 -> V_5 [ V_1205 ] ) ;
F_38 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1236 ++ ;
if ( V_1236 > V_1242 )
return - V_16 ;
}
if ( ! F_249 ( V_1203 ) )
return - V_16 ;
V_1238 = sizeof( struct V_1200 ) +
V_1236 * sizeof( struct V_1209 ) ;
V_1241 = F_39 ( V_1238 , V_136 ) ;
if ( ! V_1241 )
return - V_137 ;
V_1241 -> V_1207 = V_1236 ;
V_1241 -> V_1203 [ 0 ] = V_1203 [ 0 ] ;
V_1241 -> V_1203 [ 1 ] = V_1203 [ 1 ] ;
if ( F_250 ( V_1204 ) )
V_1241 -> V_1204 = V_1204 ;
F_38 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1235 = F_96 ( V_95 , V_1233 ,
F_23 ( V_1208 ) , F_24 ( V_1208 ) ,
V_1243 ) ;
if ( V_1235 )
goto V_1244;
V_1235 = F_247 ( V_95 , & V_1241 -> V_1216 [ V_1237 ] ) ;
if ( V_1235 )
goto V_1244;
V_1237 ++ ;
if ( V_1237 > V_1242 ) {
V_1235 = - V_16 ;
goto V_1244;
}
}
return F_251 ( V_1241 , V_1245 ) ;
V_1244:
F_41 ( V_1241 ) ;
return V_1235 ;
}
static int F_252 ( struct V_4 * V_1246 )
{
struct V_4 * V_1247 , * V_1248 ;
int V_368 = 0 , V_1249 , V_1250 ;
F_38 (attr1, freqs, tmp1) {
V_368 ++ ;
F_38 (attr2, freqs, tmp2)
if ( V_1247 != V_1248 &&
F_4 ( V_1247 ) == F_4 ( V_1248 ) )
return 0 ;
}
return V_368 ;
}
static bool F_253 ( struct V_18 * V_18 , enum V_291 V_1251 )
{
return V_1251 < V_364 && V_18 -> V_365 [ V_1251 ] ;
}
static int F_254 ( struct V_4 * V_613 , struct V_18 * V_18 ,
struct V_1252 * V_1253 )
{
struct V_4 * V_45 [ V_1254 + 1 ] ;
struct V_4 * V_1255 ;
int V_35 ;
bool V_27 = false ;
int V_161 ;
V_1255 = F_23 ( V_613 ) ;
if ( ! F_255 ( V_1255 , F_24 ( V_1255 ) ) )
return - V_16 ;
V_35 = F_96 ( V_45 , V_1254 , F_23 ( V_1255 ) ,
F_24 ( V_1255 ) , V_1256 ) ;
if ( V_35 )
return V_35 ;
for ( V_161 = 0 ; V_161 <= V_1254 ; V_161 ++ ) {
if ( V_45 [ V_161 ] ) {
if ( V_27 )
return - V_16 ;
V_27 = true ;
}
}
V_1253 -> V_1257 = V_1258 ;
if ( V_45 [ V_1259 ] )
V_1253 -> V_1257 = V_1259 ;
if ( V_45 [ V_1260 ] ) {
V_1253 -> V_1257 = V_1260 ;
V_1253 -> T_9 . V_1261 =
F_4 ( V_45 [ V_1260 ] ) ;
if ( ! F_253 ( V_18 , V_1253 -> T_9 . V_1261 ) )
return - V_16 ;
}
if ( V_45 [ V_1262 ] ) {
struct V_1263 * V_1264 ;
V_1264 = F_23 ( V_45 [ V_1262 ] ) ;
V_1253 -> V_1257 = V_1262 ;
V_1253 -> T_9 . V_1265 . V_292 = V_1264 -> V_292 ;
V_1253 -> T_9 . V_1265 . V_1266 = V_1264 -> V_1266 ;
if ( ! F_253 ( V_18 , V_1253 -> T_9 . V_1265 . V_292 ) )
return - V_16 ;
}
if ( V_1253 -> V_1257 == V_1258 )
return - V_16 ;
if ( ! ( V_18 -> V_497 & F_117 ( V_1253 -> V_1257 ) ) )
return - V_16 ;
return 0 ;
}
static int F_256 ( struct V_4 * * V_5 ,
T_2 * V_665 , T_2 * V_1267 )
{
int V_161 ;
if ( ! V_5 [ V_559 ] && ! V_5 [ V_1268 ] ) {
F_257 ( V_665 ) ;
F_257 ( V_1267 ) ;
V_665 [ 0 ] = 0x2 ;
V_1267 [ 0 ] = 0x3 ;
return 0 ;
}
if ( ! V_5 [ V_559 ] || ! V_5 [ V_1268 ] )
return - V_16 ;
memcpy ( V_665 , F_23 ( V_5 [ V_559 ] ) , V_599 ) ;
memcpy ( V_1267 , F_23 ( V_5 [ V_1268 ] ) , V_599 ) ;
if ( ! F_258 ( V_1267 ) ||
F_258 ( V_665 ) )
return - V_16 ;
for ( V_161 = 0 ; V_161 < V_599 ; V_161 ++ )
V_665 [ V_161 ] &= V_1267 [ V_161 ] ;
return 0 ;
}
static int F_259 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
struct V_1269 * V_1270 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1271 = 0 , V_368 , V_161 ;
T_11 V_1190 ;
if ( ! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_17 -> V_142 == V_155 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_1272 )
return - V_552 ;
if ( V_7 -> V_1273 || V_7 -> V_1274 ) {
V_35 = - V_556 ;
goto V_1275;
}
if ( V_30 -> V_5 [ V_1276 ] ) {
V_368 = F_252 (
V_30 -> V_5 [ V_1276 ] ) ;
if ( ! V_368 ) {
V_35 = - V_16 ;
goto V_1275;
}
} else {
V_368 = F_260 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1277 ] )
F_38 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1271 ++ ;
if ( V_1271 > V_18 -> V_311 ) {
V_35 = - V_16 ;
goto V_1275;
}
if ( V_30 -> V_5 [ V_742 ] )
V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
else
V_1190 = 0 ;
if ( V_1190 > V_18 -> V_315 ) {
V_35 = - V_16 ;
goto V_1275;
}
V_1270 = F_39 ( sizeof( * V_1270 )
+ sizeof( * V_1270 -> V_1278 ) * V_1271
+ sizeof( * V_1270 -> V_369 ) * V_368
+ V_1190 , V_136 ) ;
if ( ! V_1270 ) {
V_35 = - V_137 ;
goto V_1275;
}
if ( V_1271 )
V_1270 -> V_1278 = ( void * ) & V_1270 -> V_369 [ V_368 ] ;
V_1270 -> V_1271 = V_1271 ;
if ( V_1190 ) {
if ( V_1271 )
V_1270 -> V_1189 = ( void * ) ( V_1270 -> V_1278 + V_1271 ) ;
else
V_1270 -> V_1189 = ( void * ) ( V_1270 -> V_369 + V_368 ) ;
}
V_161 = 0 ;
if ( V_30 -> V_5 [ V_1276 ] ) {
F_38 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1279;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1270 -> V_369 [ V_161 ] = V_55 ;
V_161 ++ ;
}
} else {
enum V_291 V_292 ;
for ( V_292 = 0 ; V_292 < V_364 ; V_292 ++ ) {
int V_163 ;
if ( ! V_18 -> V_365 [ V_292 ] )
continue;
for ( V_163 = 0 ; V_163 < V_18 -> V_365 [ V_292 ] -> V_368 ; V_163 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_365 [ V_292 ] -> V_369 [ V_163 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1270 -> V_369 [ V_161 ] = V_55 ;
V_161 ++ ;
}
}
}
if ( ! V_161 ) {
V_35 = - V_16 ;
goto V_1279;
}
V_1270 -> V_368 = V_161 ;
V_161 = 0 ;
if ( V_1271 ) {
F_38 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_630 ) {
V_35 = - V_16 ;
goto V_1279;
}
V_1270 -> V_1278 [ V_161 ] . V_604 = F_24 ( V_45 ) ;
memcpy ( V_1270 -> V_1278 [ V_161 ] . V_606 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_161 ++ ;
}
}
if ( V_30 -> V_5 [ V_742 ] ) {
V_1270 -> V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
memcpy ( ( void * ) V_1270 -> V_1189 ,
F_23 ( V_30 -> V_5 [ V_742 ] ) ,
V_1270 -> V_1190 ) ;
}
for ( V_161 = 0 ; V_161 < V_364 ; V_161 ++ )
if ( V_18 -> V_365 [ V_161 ] )
V_1270 -> V_695 [ V_161 ] =
( 1 << V_18 -> V_365 [ V_161 ] -> V_263 ) - 1 ;
if ( V_30 -> V_5 [ V_1280 ] ) {
F_38 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_291 V_292 = F_155 ( V_45 ) ;
if ( V_292 < 0 || V_292 >= V_364 ) {
V_35 = - V_16 ;
goto V_1279;
}
if ( ! V_18 -> V_365 [ V_292 ] )
continue;
V_35 = F_261 ( V_18 -> V_365 [ V_292 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1270 -> V_695 [ V_292 ] ) ;
if ( V_35 )
goto V_1279;
}
}
if ( V_30 -> V_5 [ V_1281 ] ) {
if ( ! F_116 ( V_18 ,
V_1282 ) ) {
V_35 = - V_552 ;
goto V_1279;
}
V_1270 -> V_1283 =
F_78 ( V_30 -> V_5 [ V_1281 ] ) ;
V_1270 -> V_1284 =
F_166 ( V_30 -> V_5 [ V_1285 ] ) ;
}
if ( V_30 -> V_5 [ V_1286 ] ) {
V_1270 -> V_51 = F_4 (
V_30 -> V_5 [ V_1286 ] ) ;
if ( ( V_1270 -> V_51 & V_1287 ) &&
! ( V_18 -> V_293 & V_1288 ) ) {
V_35 = - V_552 ;
goto V_1279;
}
if ( V_1270 -> V_51 & V_1289 ) {
if ( ! ( V_18 -> V_293 &
V_1290 ) ) {
V_35 = - V_552 ;
goto V_1279;
}
if ( V_17 -> V_150 ) {
V_35 = - V_552 ;
goto V_1279;
}
V_35 = F_256 ( V_30 -> V_5 ,
V_1270 -> V_665 ,
V_1270 -> V_1267 ) ;
if ( V_35 )
goto V_1279;
}
}
V_1270 -> V_1291 =
F_166 ( V_30 -> V_5 [ V_1292 ] ) ;
if ( V_30 -> V_5 [ V_559 ] )
memcpy ( V_1270 -> V_558 , F_23 ( V_30 -> V_5 [ V_559 ] ) ,
V_599 ) ;
else
F_262 ( V_1270 -> V_558 ) ;
V_1270 -> V_17 = V_17 ;
V_1270 -> V_18 = & V_7 -> V_18 ;
V_1270 -> V_1293 = V_1294 ;
V_7 -> V_1273 = V_1270 ;
V_35 = F_263 ( V_7 , V_1270 ) ;
if ( ! V_35 ) {
F_264 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_265 ( V_17 -> V_19 ) ;
} else {
V_1279:
V_7 -> V_1273 = NULL ;
F_41 ( V_1270 ) ;
}
V_1275:
return V_35 ;
}
static int F_266 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
if ( ! V_7 -> V_353 -> V_1295 )
return - V_552 ;
if ( V_7 -> V_1274 )
return 0 ;
if ( ! V_7 -> V_1273 )
return - V_671 ;
F_267 ( V_7 , V_17 ) ;
return 0 ;
}
static int
F_268 ( struct V_18 * V_18 , int V_1296 ,
struct V_1297 * V_1270 ,
struct V_4 * * V_5 )
{
int V_24 , V_35 , V_161 = 0 ;
struct V_4 * V_45 ;
if ( ! V_5 [ V_1298 ] ) {
V_22 V_1299 ;
if ( ! V_5 [ V_1300 ] )
return - V_16 ;
V_1299 = F_4 ( V_5 [ V_1300 ] ) ;
if ( ! V_1299 )
return - V_16 ;
V_1270 -> V_1301 [ 0 ] . V_1299 =
F_269 ( V_1299 , V_1302 ) ;
if ( ! V_1270 -> V_1301 [ 0 ] . V_1299 )
return - V_16 ;
if ( V_1270 -> V_1301 [ 0 ] . V_1299 >
V_18 -> V_323 )
V_1270 -> V_1301 [ 0 ] . V_1299 =
V_18 -> V_323 ;
return 0 ;
}
F_38 (attr, attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp) {
struct V_4 * V_1303 [ V_1304 + 1 ] ;
if ( F_59 ( V_161 >= V_1296 ) )
return - V_16 ;
V_35 = F_96 ( V_1303 , V_1304 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1305 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1303 [ V_1306 ] )
return - V_16 ;
V_1270 -> V_1301 [ V_161 ] . V_1299 =
F_4 ( V_1303 [ V_1306 ] ) ;
if ( ! V_1270 -> V_1301 [ V_161 ] . V_1299 ||
V_1270 -> V_1301 [ V_161 ] . V_1299 >
V_18 -> V_323 )
return - V_16 ;
if ( V_1303 [ V_1307 ] ) {
V_1270 -> V_1301 [ V_161 ] . V_1308 =
F_4 ( V_1303 [ V_1307 ] ) ;
if ( ! V_1270 -> V_1301 [ V_161 ] . V_1308 ||
( V_1270 -> V_1301 [ V_161 ] . V_1308 >
V_18 -> V_325 ) )
return - V_16 ;
} else if ( V_161 < V_1296 - 1 ) {
return - V_16 ;
}
V_161 ++ ;
}
if ( V_1270 -> V_1301 [ V_1296 - 1 ] . V_1308 )
return - V_16 ;
return 0 ;
}
static struct V_1297 *
F_270 ( struct V_18 * V_18 , struct V_1 * V_17 ,
struct V_4 * * V_5 )
{
struct V_1297 * V_1270 ;
struct V_4 * V_45 ;
int V_35 , V_24 , V_1271 = 0 , V_1309 = 0 , V_368 , V_161 , V_1296 = 0 ;
enum V_291 V_292 ;
T_11 V_1190 ;
struct V_4 * V_95 [ V_1310 + 1 ] ;
T_8 V_1311 = V_1312 ;
if ( ! F_22 ( V_5 [ V_742 ] ) )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1276 ] ) {
V_368 = F_252 (
V_5 [ V_1276 ] ) ;
if ( ! V_368 )
return F_3 ( - V_16 ) ;
} else {
V_368 = F_260 ( V_18 ) ;
}
if ( V_5 [ V_1277 ] )
F_38 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1271 ++ ;
if ( V_1271 > V_18 -> V_313 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1313 ] ) {
F_38 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1314 ;
V_35 = F_96 ( V_95 , V_1310 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1315 ) ;
if ( V_35 )
return F_3 ( V_35 ) ;
if ( V_95 [ V_1316 ] ) {
V_1309 ++ ;
continue;
}
V_1314 = V_95 [ V_1317 ] ;
if ( V_1314 )
V_1311 = F_227 ( V_1314 ) ;
}
}
if ( ! V_1309 && V_1311 != V_1312 )
V_1309 = 1 ;
if ( V_1309 > V_18 -> V_319 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_742 ] )
V_1190 = F_24 ( V_5 [ V_742 ] ) ;
else
V_1190 = 0 ;
if ( V_1190 > V_18 -> V_317 )
return F_3 ( - V_16 ) ;
if ( V_5 [ V_1298 ] ) {
if ( V_5 [ V_1300 ] )
return F_3 ( - V_16 ) ;
F_38 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_PLANS], tmp)
V_1296 ++ ;
} else {
if ( ! V_5 [ V_1300 ] )
return F_3 ( - V_16 ) ;
V_1296 = 1 ;
}
if ( ! V_1296 || V_1296 > V_18 -> V_321 )
return F_3 ( - V_16 ) ;
V_1270 = F_39 ( sizeof( * V_1270 )
+ sizeof( * V_1270 -> V_1278 ) * V_1271
+ sizeof( * V_1270 -> V_1318 ) * V_1309
+ sizeof( * V_1270 -> V_1301 ) * V_1296
+ sizeof( * V_1270 -> V_369 ) * V_368
+ V_1190 , V_136 ) ;
if ( ! V_1270 )
return F_3 ( - V_137 ) ;
if ( V_1271 )
V_1270 -> V_1278 = ( void * ) & V_1270 -> V_369 [ V_368 ] ;
V_1270 -> V_1271 = V_1271 ;
if ( V_1190 ) {
if ( V_1271 )
V_1270 -> V_1189 = ( void * ) ( V_1270 -> V_1278 + V_1271 ) ;
else
V_1270 -> V_1189 = ( void * ) ( V_1270 -> V_369 + V_368 ) ;
}
if ( V_1309 ) {
if ( V_1270 -> V_1189 )
V_1270 -> V_1318 = ( void * ) ( V_1270 -> V_1189 + V_1190 ) ;
else if ( V_1271 )
V_1270 -> V_1318 =
( void * ) ( V_1270 -> V_1278 + V_1271 ) ;
else
V_1270 -> V_1318 =
( void * ) ( V_1270 -> V_369 + V_368 ) ;
}
V_1270 -> V_1309 = V_1309 ;
if ( V_1309 )
V_1270 -> V_1301 = ( void * ) ( V_1270 -> V_1318 +
V_1309 ) ;
else if ( V_1270 -> V_1189 )
V_1270 -> V_1301 = ( void * ) ( V_1270 -> V_1189 + V_1190 ) ;
else if ( V_1271 )
V_1270 -> V_1301 = ( void * ) ( V_1270 -> V_1278 + V_1271 ) ;
else
V_1270 -> V_1301 = ( void * ) ( V_1270 -> V_369 + V_368 ) ;
V_1270 -> V_1319 = V_1296 ;
V_161 = 0 ;
if ( V_5 [ V_1276 ] ) {
F_38 (attr,
attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1279;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1270 -> V_369 [ V_161 ] = V_55 ;
V_161 ++ ;
}
} else {
for ( V_292 = 0 ; V_292 < V_364 ; V_292 ++ ) {
int V_163 ;
if ( ! V_18 -> V_365 [ V_292 ] )
continue;
for ( V_163 = 0 ; V_163 < V_18 -> V_365 [ V_292 ] -> V_368 ; V_163 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_365 [ V_292 ] -> V_369 [ V_163 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1270 -> V_369 [ V_161 ] = V_55 ;
V_161 ++ ;
}
}
}
if ( ! V_161 ) {
V_35 = - V_16 ;
goto V_1279;
}
V_1270 -> V_368 = V_161 ;
V_161 = 0 ;
if ( V_1271 ) {
F_38 (attr, attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_630 ) {
V_35 = - V_16 ;
goto V_1279;
}
V_1270 -> V_1278 [ V_161 ] . V_604 = F_24 ( V_45 ) ;
memcpy ( V_1270 -> V_1278 [ V_161 ] . V_606 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_161 ++ ;
}
}
V_161 = 0 ;
if ( V_5 [ V_1313 ] ) {
F_38 (attr,
attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_606 , * V_1314 ;
V_35 = F_96 ( V_95 , V_1310 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1315 ) ;
if ( V_35 )
goto V_1279;
V_606 = V_95 [ V_1316 ] ;
if ( V_606 ) {
if ( F_59 ( V_161 >= V_1309 ) ) {
V_35 = - V_16 ;
goto V_1279;
}
if ( F_24 ( V_606 ) > V_630 ) {
V_35 = - V_16 ;
goto V_1279;
}
memcpy ( V_1270 -> V_1318 [ V_161 ] . V_606 . V_606 ,
F_23 ( V_606 ) , F_24 ( V_606 ) ) ;
V_1270 -> V_1318 [ V_161 ] . V_606 . V_604 =
F_24 ( V_606 ) ;
V_1270 -> V_1318 [ V_161 ] . V_1320 =
V_1311 ;
V_1314 = V_95 [ V_1317 ] ;
if ( V_1314 )
V_1270 -> V_1318 [ V_161 ] . V_1320 =
F_227 ( V_1314 ) ;
}
V_161 ++ ;
}
if ( V_161 == 0 && V_1309 )
V_1270 -> V_1318 [ 0 ] . V_1320 = V_1311 ;
V_1270 -> V_1321 = V_1322 ;
for ( V_161 = 0 ; V_161 < V_1309 ; V_161 ++ )
V_1270 -> V_1321 =
V_1156 ( V_1270 -> V_1318 [ V_161 ] . V_1320 ,
V_1270 -> V_1321 ) ;
} else {
V_1270 -> V_1321 = V_1312 ;
}
if ( V_1190 ) {
V_1270 -> V_1190 = V_1190 ;
memcpy ( ( void * ) V_1270 -> V_1189 ,
F_23 ( V_5 [ V_742 ] ) ,
V_1270 -> V_1190 ) ;
}
if ( V_5 [ V_1286 ] ) {
V_1270 -> V_51 = F_4 (
V_5 [ V_1286 ] ) ;
if ( ( V_1270 -> V_51 & V_1287 ) &&
! ( V_18 -> V_293 & V_1288 ) ) {
V_35 = - V_552 ;
goto V_1279;
}
if ( V_1270 -> V_51 & V_1289 ) {
V_22 V_1323 = V_1324 ;
if ( ! V_17 )
V_1323 = V_1325 ;
if ( ! ( V_18 -> V_293 & V_1323 ) ) {
V_35 = - V_552 ;
goto V_1279;
}
if ( V_17 && V_17 -> V_150 ) {
V_35 = - V_552 ;
goto V_1279;
}
V_35 = F_256 ( V_5 , V_1270 -> V_665 ,
V_1270 -> V_1267 ) ;
if ( V_35 )
goto V_1279;
}
}
if ( V_5 [ V_1326 ] )
V_1270 -> V_1327 =
F_4 ( V_5 [ V_1326 ] ) ;
V_35 = F_268 ( V_18 , V_1296 , V_1270 , V_5 ) ;
if ( V_35 )
goto V_1279;
V_1270 -> V_1293 = V_1294 ;
return V_1270 ;
V_1279:
F_41 ( V_1270 ) ;
return F_3 ( V_35 ) ;
}
static int F_271 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_1297 * V_1328 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_424 ) ||
! V_7 -> V_353 -> V_425 )
return - V_552 ;
if ( V_7 -> V_1328 )
return - V_1087 ;
V_1328 = F_270 ( & V_7 -> V_18 , V_17 ,
V_30 -> V_5 ) ;
V_35 = F_272 ( V_1328 ) ;
if ( V_35 )
goto V_942;
V_35 = F_273 ( V_7 , V_551 , V_1328 ) ;
if ( V_35 )
goto V_1279;
V_1328 -> V_551 = V_551 ;
V_1328 -> V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_649 ] )
V_1328 -> V_650 = V_30 -> V_516 ;
F_274 ( V_7 -> V_1328 , V_1328 ) ;
F_275 ( V_7 , V_551 ,
V_1329 ) ;
return 0 ;
V_1279:
F_41 ( V_1328 ) ;
V_942:
return V_35 ;
}
static int F_276 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_424 ) ||
! V_7 -> V_353 -> V_1330 )
return - V_552 ;
return F_277 ( V_7 , false ) ;
}
static int F_278 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_531 V_532 ;
enum V_1239 V_1204 ;
unsigned int V_1331 ;
int V_35 ;
V_1204 = F_279 ( V_17 -> V_18 ) ;
if ( V_1204 == V_1240 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_532 ) ;
if ( V_35 )
return V_35 ;
if ( F_280 ( V_551 ) )
return - V_556 ;
if ( V_17 -> V_1332 )
return - V_556 ;
V_35 = F_281 ( V_17 -> V_18 , & V_532 ,
V_17 -> V_142 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_282 ( V_17 -> V_18 , & V_532 ) )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_1333 )
return - V_552 ;
V_1331 = F_283 ( & V_7 -> V_18 , & V_532 ) ;
if ( F_59 ( ! V_1331 ) )
V_1331 = V_1334 ;
V_35 = F_284 ( V_7 , V_551 , & V_532 , V_1331 ) ;
if ( ! V_35 ) {
V_17 -> V_532 = V_532 ;
V_17 -> V_1332 = true ;
V_17 -> V_1335 = V_1294 ;
V_17 -> V_1331 = V_1331 ;
}
return V_35 ;
}
static int F_285 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_1336 V_140 ;
static struct V_4 * V_1337 [ V_1338 + 1 ] ;
int V_35 ;
bool V_1339 = false ;
int V_47 , V_161 ;
V_22 V_1340 ;
if ( ! V_7 -> V_353 -> V_444 ||
! ( V_7 -> V_18 . V_51 & V_443 ) )
return - V_552 ;
switch ( V_551 -> V_28 -> V_142 ) {
case V_143 :
case V_145 :
V_1339 = true ;
if ( ! V_17 -> V_553 )
return - V_1341 ;
break;
case V_147 :
if ( ! V_17 -> V_604 )
return - V_1341 ;
break;
case V_146 :
if ( ! V_17 -> V_1097 )
return - V_1341 ;
break;
default:
return - V_552 ;
}
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
if ( ! V_30 -> V_5 [ V_534 ] ||
! V_30 -> V_5 [ V_1342 ] )
return - V_16 ;
if ( V_1339 && ! V_30 -> V_5 [ V_1343 ] )
return - V_16 ;
V_1340 = F_4 ( V_30 -> V_5 [ V_1342 ] ) ;
if ( V_1340 > 255 )
return - V_16 ;
V_140 . V_1344 = V_1340 ;
if ( ! V_1339 )
goto V_1345;
V_35 = F_160 ( V_30 -> V_5 , & V_140 . V_1346 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1337 , V_1338 ,
V_30 -> V_5 [ V_1343 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_160 ( V_1337 , & V_140 . V_1347 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1337 [ V_1348 ] )
return - V_16 ;
V_47 = F_24 ( V_1337 [ V_1348 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_140 . V_1349 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_491 &&
( V_140 . V_1349 >
V_7 -> V_18 . V_491 ) )
return - V_16 ;
V_140 . V_1350 =
F_23 ( V_1337 [ V_1348 ] ) ;
for ( V_161 = 0 ; V_161 < V_140 . V_1349 ; V_161 ++ ) {
T_3 V_1351 = V_140 . V_1350 [ V_161 ] ;
if ( V_1351 >= V_140 . V_1347 . V_749 )
return - V_16 ;
if ( V_140 . V_1347 . V_748 [ V_1351 ] != V_140 . V_1344 )
return - V_16 ;
}
if ( V_1337 [ V_1352 ] ) {
V_47 = F_24 ( V_1337 [ V_1352 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_140 . V_1353 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_491 &&
( V_140 . V_1353 >
V_7 -> V_18 . V_491 ) )
return - V_16 ;
V_140 . V_1354 =
F_23 ( V_1337 [ V_1352 ] ) ;
for ( V_161 = 0 ; V_161 < V_140 . V_1353 ; V_161 ++ ) {
T_3 V_1351 = V_140 . V_1354 [ V_161 ] ;
if ( V_1351 >= V_140 . V_1347 . V_758 )
return - V_16 ;
if ( V_140 . V_1347 . V_757 [ V_1351 ] !=
V_140 . V_1344 )
return - V_16 ;
}
}
V_1345:
V_35 = F_80 ( V_7 , V_30 , & V_140 . V_532 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_140 . V_532 ,
V_17 -> V_142 ) )
return - V_16 ;
V_35 = F_281 ( V_17 -> V_18 ,
& V_140 . V_532 ,
V_17 -> V_142 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 )
V_140 . V_1355 = true ;
if ( V_30 -> V_5 [ V_1356 ] )
V_140 . V_1357 = true ;
F_113 ( V_17 ) ;
V_35 = F_286 ( V_7 , V_551 , & V_140 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_287 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1358 * V_1359 )
{
struct V_1360 * V_357 = & V_1359 -> V_1361 ;
const struct V_1362 * V_1363 ;
void * V_285 ;
struct V_4 * V_1364 ;
F_43 ( V_17 ) ;
V_285 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1365 ) ;
if ( ! V_285 )
return - 1 ;
F_244 ( V_34 , V_285 , & V_38 ) ;
if ( F_28 ( V_53 , V_295 , V_7 -> V_1366 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_61;
V_1364 = F_47 ( V_53 , V_1367 ) ;
if ( ! V_1364 )
goto V_61;
if ( ( ! F_288 ( V_357 -> V_558 ) &&
F_51 ( V_53 , V_1368 , V_599 , V_357 -> V_558 ) ) )
goto V_61;
F_240 () ;
if ( F_217 ( V_357 -> V_752 ) &&
F_29 ( V_53 , V_1369 ) )
goto V_1370;
V_1363 = F_241 ( V_357 -> V_1363 ) ;
if ( V_1363 ) {
if ( F_104 ( V_53 , V_1371 , V_1363 -> V_1372 ,
V_1373 ) )
goto V_1370;
if ( V_1363 -> V_47 && F_51 ( V_53 , V_1374 ,
V_1363 -> V_47 , V_1363 -> V_141 ) )
goto V_1370;
}
V_1363 = F_241 ( V_357 -> V_750 ) ;
if ( V_1363 && V_1363 -> V_1375 ) {
if ( F_104 ( V_53 , V_1376 , V_1363 -> V_1372 ,
V_1373 ) )
goto V_1370;
if ( V_1363 -> V_47 && F_51 ( V_53 , V_1377 ,
V_1363 -> V_47 , V_1363 -> V_141 ) )
goto V_1370;
}
F_242 () ;
if ( V_357 -> V_553 &&
F_55 ( V_53 , V_1378 , V_357 -> V_553 ) )
goto V_61;
if ( F_55 ( V_53 , V_1379 , V_357 -> V_1003 ) ||
F_28 ( V_53 , V_1380 , V_357 -> V_1381 -> V_60 ) ||
F_28 ( V_53 , V_1382 , V_357 -> V_1383 ) ||
F_28 ( V_53 , V_1384 ,
F_289 ( V_1294 - V_1359 -> V_1385 ) ) )
goto V_61;
if ( V_1359 -> V_1386 &&
( F_104 ( V_53 , V_1387 ,
V_1359 -> V_1386 , V_1373 ) ||
F_51 ( V_53 , V_1388 , V_599 ,
V_1359 -> V_1389 ) ) )
goto V_61;
if ( V_1359 -> V_1390 &&
F_104 ( V_53 , V_1391 ,
V_1359 -> V_1390 , V_1373 ) )
goto V_61;
switch ( V_7 -> V_18 . V_875 ) {
case V_876 :
if ( F_28 ( V_53 , V_1392 , V_357 -> signal ) )
goto V_61;
break;
case V_1393 :
if ( F_56 ( V_53 , V_1394 , V_357 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_142 ) {
case V_149 :
case V_148 :
if ( V_1359 == V_17 -> V_150 &&
F_28 ( V_53 , V_1395 ,
V_1396 ) )
goto V_61;
break;
case V_147 :
if ( V_1359 == V_17 -> V_150 &&
F_28 ( V_53 , V_1395 ,
V_1397 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1364 ) ;
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_1370:
F_242 () ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int F_290 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1358 * V_1272 ;
struct V_1 * V_17 ;
int V_511 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_113 ( V_17 ) ;
F_291 ( & V_7 -> V_1398 ) ;
F_292 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1366 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_511 )
continue;
if ( F_287 ( V_32 , V_34 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_7 , V_17 , V_1272 ) < 0 ) {
V_105 -- ;
break;
}
}
F_293 ( & V_7 -> V_1398 ) ;
F_115 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_294 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_551 ,
bool V_1399 ,
struct V_1400 * V_1401 )
{
void * V_285 ;
struct V_4 * V_1402 ;
if ( ! V_1401 -> V_1381 && ! V_1399 )
return 0 ;
V_285 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1403 ) ;
if ( ! V_285 )
return - V_137 ;
if ( F_28 ( V_53 , V_10 , V_551 -> V_20 ) )
goto V_61;
V_1402 = F_47 ( V_53 , V_1404 ) ;
if ( ! V_1402 )
goto V_61;
if ( V_1401 -> V_1381 &&
F_28 ( V_53 , V_1405 ,
V_1401 -> V_1381 -> V_60 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1406 ) &&
F_56 ( V_53 , V_1407 , V_1401 -> V_1408 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1409 ) &&
F_29 ( V_53 , V_1410 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1411 ) &&
F_104 ( V_53 , V_1412 ,
V_1401 -> time , V_1413 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1414 ) &&
F_104 ( V_53 , V_1415 ,
V_1401 -> V_1416 , V_1413 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1417 ) &&
F_104 ( V_53 , V_1418 ,
V_1401 -> V_1419 , V_1413 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1420 ) &&
F_104 ( V_53 , V_1421 ,
V_1401 -> V_1422 , V_1413 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1423 ) &&
F_104 ( V_53 , V_1424 ,
V_1401 -> V_1425 , V_1413 ) )
goto V_61;
if ( ( V_1401 -> V_858 & V_1426 ) &&
F_104 ( V_53 , V_1427 ,
V_1401 -> V_1428 , V_1413 ) )
goto V_61;
F_48 ( V_53 , V_1402 ) ;
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int F_295 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1400 V_1401 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1429 = V_34 -> args [ 2 ] ;
int V_357 ;
bool V_1430 ;
V_357 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_357 )
return V_357 ;
V_1430 = V_38 . V_40 [ V_1431 ] ;
if ( ! V_17 -> V_19 ) {
V_357 = - V_16 ;
goto V_942;
}
if ( ! V_7 -> V_353 -> V_1432 ) {
V_357 = - V_552 ;
goto V_942;
}
while ( 1 ) {
V_357 = F_296 ( V_7 , V_17 -> V_19 , V_1429 , & V_1401 ) ;
if ( V_357 == - V_671 )
break;
if ( V_357 )
goto V_942;
if ( V_1401 . V_1381 &&
V_1401 . V_1381 -> V_51 & V_62 ) {
V_1429 ++ ;
continue;
}
if ( F_294 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_17 -> V_19 , V_1430 , & V_1401 ) < 0 )
goto V_611;
V_1429 ++ ;
}
V_611:
V_34 -> args [ 2 ] = V_1429 ;
V_357 = V_32 -> V_47 ;
V_942:
F_21 ( V_7 ) ;
return V_357 ;
}
static bool F_297 ( V_22 V_1433 )
{
return ! ( V_1433 & ~ ( V_1434 |
V_1435 ) ) ;
}
static int F_298 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_558 , * V_606 , * V_1189 = NULL , * V_1436 = NULL ;
int V_35 , V_604 , V_1190 = 0 , V_1437 = 0 ;
enum V_760 V_761 ;
struct V_93 V_92 ;
bool V_1438 ;
if ( ! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_779 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_605 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_534 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_668 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_138 ||
V_92 . V_107 . V_108 != V_1439 ) &&
( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1440 ) )
return - V_16 ;
if ( V_92 . V_105 > 3 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_161 ;
bool V_1441 = false ;
for ( V_161 = 0 ; V_161 < V_7 -> V_18 . V_340 ; V_161 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_341 [ V_161 ] ) {
V_1441 = true ;
break;
}
}
if ( ! V_1441 )
return - V_16 ;
}
if ( ! V_7 -> V_353 -> V_387 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_534 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_606 = F_23 ( V_30 -> V_5 [ V_605 ] ) ;
V_604 = F_24 ( V_30 -> V_5 [ V_605 ] ) ;
if ( V_30 -> V_5 [ V_742 ] ) {
V_1189 = F_23 ( V_30 -> V_5 [ V_742 ] ) ;
V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
}
V_761 = F_4 ( V_30 -> V_5 [ V_779 ] ) ;
if ( ! F_162 ( V_7 , V_761 , V_763 ) )
return - V_16 ;
if ( V_761 == V_765 &&
! V_30 -> V_5 [ V_1442 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1442 ] ) {
if ( V_761 != V_765 )
return - V_16 ;
V_1436 = F_23 ( V_30 -> V_5 [ V_1442 ] ) ;
V_1437 = F_24 ( V_30 -> V_5 [ V_1442 ] ) ;
if ( V_1437 < 4 )
return - V_16 ;
}
V_1438 = ! ! V_30 -> V_5 [ V_1443 ] ;
if ( V_1438 )
return 0 ;
F_113 ( V_551 -> V_28 ) ;
V_35 = F_299 ( V_7 , V_551 , V_55 , V_761 , V_558 ,
V_606 , V_604 , V_1189 , V_1190 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1436 , V_1437 ) ;
F_115 ( V_551 -> V_28 ) ;
return V_35 ;
}
static int F_165 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1444 * V_1445 ,
int V_1446 )
{
memset ( V_1445 , 0 , sizeof( * V_1445 ) ) ;
V_1445 -> V_1447 = V_30 -> V_5 [ V_1448 ] ;
if ( V_30 -> V_5 [ V_345 ] ) {
T_3 V_1449 ;
V_1449 = F_78 (
V_30 -> V_5 [ V_345 ] ) ;
V_1445 -> V_1450 = F_300 ( V_1449 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_344 ) &&
V_1449 != V_1451 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1452 ] )
V_1445 -> V_1453 = true ;
} else
V_1445 -> V_1450 = F_300 ( V_1451 ) ;
if ( V_30 -> V_5 [ V_1454 ] ) {
void * V_141 ;
int V_47 , V_161 ;
V_141 = F_23 ( V_30 -> V_5 [ V_1454 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1454 ] ) ;
V_1445 -> V_1455 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1445 -> V_1455 > V_1446 )
return - V_16 ;
memcpy ( V_1445 -> V_1456 , V_141 , V_47 ) ;
for ( V_161 = 0 ; V_161 < V_1445 -> V_1455 ; V_161 ++ )
if ( ! F_301 (
& V_7 -> V_18 ,
V_1445 -> V_1456 [ V_161 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1457 ] ) {
V_1445 -> V_1458 =
F_4 ( V_30 -> V_5 [ V_1457 ] ) ;
if ( ! F_301 ( & V_7 -> V_18 ,
V_1445 -> V_1458 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1459 ] ) {
V_1445 -> V_1433 =
F_4 ( V_30 -> V_5 [ V_1459 ] ) ;
if ( ! F_297 ( V_1445 -> V_1433 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1460 ] ) {
void * V_141 ;
int V_47 ;
V_141 = F_23 ( V_30 -> V_5 [ V_1460 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1460 ] ) ;
V_1445 -> V_1461 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1445 -> V_1461 > V_1462 )
return - V_16 ;
memcpy ( V_1445 -> V_1463 , V_141 , V_47 ) ;
}
return 0 ;
}
static int F_302 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1464 V_1465 = {} ;
const T_2 * V_558 , * V_606 ;
int V_35 , V_604 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_559 ] ||
! V_30 -> V_5 [ V_605 ] ||
! V_30 -> V_5 [ V_534 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_389 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_534 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_606 = F_23 ( V_30 -> V_5 [ V_605 ] ) ;
V_604 = F_24 ( V_30 -> V_5 [ V_605 ] ) ;
if ( V_30 -> V_5 [ V_742 ] ) {
V_1465 . V_1189 = F_23 ( V_30 -> V_5 [ V_742 ] ) ;
V_1465 . V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
}
if ( V_30 -> V_5 [ V_1466 ] ) {
enum V_1467 V_1468 =
F_4 ( V_30 -> V_5 [ V_1466 ] ) ;
if ( V_1468 == V_1469 )
V_1465 . V_1470 = true ;
else if ( V_1468 != V_1471 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1472 ] )
V_1465 . V_1473 = F_23 ( V_30 -> V_5 [ V_1472 ] ) ;
if ( F_166 ( V_30 -> V_5 [ V_1474 ] ) )
V_1465 . V_51 |= V_1475 ;
if ( V_30 -> V_5 [ V_467 ] )
memcpy ( & V_1465 . V_1476 ,
F_23 ( V_30 -> V_5 [ V_467 ] ) ,
sizeof( V_1465 . V_1476 ) ) ;
if ( V_30 -> V_5 [ V_993 ] ) {
if ( ! V_30 -> V_5 [ V_467 ] )
return - V_16 ;
memcpy ( & V_1465 . V_964 ,
F_23 ( V_30 -> V_5 [ V_993 ] ) ,
sizeof( V_1465 . V_964 ) ) ;
}
if ( F_166 ( V_30 -> V_5 [ V_1477 ] ) )
V_1465 . V_51 |= V_1478 ;
if ( V_30 -> V_5 [ V_476 ] )
memcpy ( & V_1465 . V_1479 ,
F_23 ( V_30 -> V_5 [ V_476 ] ) ,
sizeof( V_1465 . V_1479 ) ) ;
if ( V_30 -> V_5 [ V_994 ] ) {
if ( ! V_30 -> V_5 [ V_476 ] )
return - V_16 ;
memcpy ( & V_1465 . V_965 ,
F_23 ( V_30 -> V_5 [ V_994 ] ) ,
sizeof( V_1465 . V_965 ) ) ;
}
if ( F_166 ( V_30 -> V_5 [ V_1480 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_293 &
V_1481 ) &&
( V_7 -> V_18 . V_293 & V_1482 ) ) &&
! F_116 ( & V_7 -> V_18 ,
V_1483 ) )
return - V_16 ;
V_1465 . V_51 |= V_1484 ;
}
V_35 = F_165 ( V_7 , V_30 , & V_1465 . V_781 , 1 ) ;
if ( ! V_35 ) {
F_113 ( V_551 -> V_28 ) ;
V_35 = F_303 ( V_7 , V_551 , V_55 , V_558 ,
V_606 , V_604 , & V_1465 ) ;
F_115 ( V_551 -> V_28 ) ;
}
return V_35 ;
}
static int F_304 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
const T_2 * V_1189 = NULL , * V_558 ;
int V_1190 = 0 , V_35 ;
T_3 V_1031 ;
bool V_1438 ;
if ( ! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1030 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_391 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_1031 = F_78 ( V_30 -> V_5 [ V_1030 ] ) ;
if ( V_1031 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_742 ] ) {
V_1189 = F_23 ( V_30 -> V_5 [ V_742 ] ) ;
V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
}
V_1438 = ! ! V_30 -> V_5 [ V_1443 ] ;
F_113 ( V_551 -> V_28 ) ;
V_35 = F_305 ( V_7 , V_551 , V_558 , V_1189 , V_1190 , V_1031 ,
V_1438 ) ;
F_115 ( V_551 -> V_28 ) ;
return V_35 ;
}
static int F_306 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
const T_2 * V_1189 = NULL , * V_558 ;
int V_1190 = 0 , V_35 ;
T_3 V_1031 ;
bool V_1438 ;
if ( ! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1030 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_393 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_1031 = F_78 ( V_30 -> V_5 [ V_1030 ] ) ;
if ( V_1031 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_742 ] ) {
V_1189 = F_23 ( V_30 -> V_5 [ V_742 ] ) ;
V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
}
V_1438 = ! ! V_30 -> V_5 [ V_1443 ] ;
F_113 ( V_551 -> V_28 ) ;
V_35 = F_307 ( V_7 , V_551 , V_558 , V_1189 , V_1190 , V_1031 ,
V_1438 ) ;
F_115 ( V_551 -> V_28 ) ;
return V_35 ;
}
static bool
F_308 ( struct V_6 * V_7 ,
int V_1485 [ V_364 ] ,
int V_1486 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_292 , V_161 ;
for ( V_292 = 0 ; V_292 < V_364 ; V_292 ++ ) {
struct V_241 * V_242 ;
V_242 = V_18 -> V_365 [ V_292 ] ;
if ( ! V_242 )
continue;
for ( V_161 = 0 ; V_161 < V_242 -> V_263 ; V_161 ++ ) {
if ( V_242 -> V_264 [ V_161 ] . V_266 == V_1486 ) {
V_1485 [ V_292 ] = V_161 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_309 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1487 V_1488 ;
struct V_18 * V_18 ;
struct V_130 * V_1489 = NULL ;
int V_35 ;
memset ( & V_1488 , 0 , sizeof( V_1488 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_605 ] ||
! F_24 ( V_30 -> V_5 [ V_605 ] ) )
return - V_16 ;
V_1488 . V_553 = 100 ;
if ( V_30 -> V_5 [ V_768 ] )
V_1488 . V_553 =
F_4 ( V_30 -> V_5 [ V_768 ] ) ;
V_35 = F_164 ( V_7 , V_1488 . V_553 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_353 -> V_395 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_147 )
return - V_552 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_559 ] ) {
V_1488 . V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( ! F_122 ( V_1488 . V_558 ) )
return - V_16 ;
}
V_1488 . V_606 = F_23 ( V_30 -> V_5 [ V_605 ] ) ;
V_1488 . V_604 = F_24 ( V_30 -> V_5 [ V_605 ] ) ;
if ( V_30 -> V_5 [ V_742 ] ) {
V_1488 . V_1189 = F_23 ( V_30 -> V_5 [ V_742 ] ) ;
V_1488 . V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1488 . V_532 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_310 ( & V_7 -> V_18 , & V_1488 . V_532 ,
V_147 ) )
return - V_16 ;
switch ( V_1488 . V_532 . V_535 ) {
case V_549 :
case V_550 :
case V_536 :
break;
case V_591 :
case V_592 :
if ( ! ( V_7 -> V_18 . V_293 & V_1490 ) )
return - V_16 ;
break;
case V_1491 :
case V_1492 :
case V_1493 :
if ( ! ( V_7 -> V_18 . V_293 & V_1490 ) )
return - V_16 ;
if ( ! F_116 ( & V_7 -> V_18 ,
V_1494 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
V_1488 . V_1495 = ! ! V_30 -> V_5 [ V_1496 ] ;
V_1488 . V_777 = ! ! V_30 -> V_5 [ V_778 ] ;
if ( V_30 -> V_5 [ V_1078 ] ) {
T_2 * V_695 =
F_23 ( V_30 -> V_5 [ V_1078 ] ) ;
int V_1497 =
F_24 ( V_30 -> V_5 [ V_1078 ] ) ;
struct V_241 * V_242 =
V_18 -> V_365 [ V_1488 . V_532 . V_55 -> V_292 ] ;
V_35 = F_261 ( V_242 , V_695 , V_1497 ,
& V_1488 . V_1079 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_467 ] )
memcpy ( & V_1488 . V_1476 ,
F_23 ( V_30 -> V_5 [ V_467 ] ) ,
sizeof( V_1488 . V_1476 ) ) ;
if ( V_30 -> V_5 [ V_993 ] ) {
if ( ! V_30 -> V_5 [ V_467 ] )
return - V_16 ;
memcpy ( & V_1488 . V_964 ,
F_23 ( V_30 -> V_5 [ V_993 ] ) ,
sizeof( V_1488 . V_964 ) ) ;
}
if ( V_30 -> V_5 [ V_1498 ] &&
! F_308 ( V_7 , V_1488 . V_1485 ,
F_4 ( V_30 -> V_5 [ V_1498 ] ) ) )
return - V_16 ;
if ( V_1488 . V_777 && V_30 -> V_5 [ V_1499 ] ) {
bool V_132 = false ;
V_1489 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1499 ] ,
& V_132 ) ;
if ( F_17 ( V_1489 ) )
return F_18 ( V_1489 ) ;
if ( ( V_1488 . V_532 . V_535 != V_536 ) &&
V_132 ) {
F_311 ( V_1489 ) ;
return - V_16 ;
}
}
V_1488 . V_1447 =
F_166 ( V_30 -> V_5 [ V_1448 ] ) ;
V_1488 . V_1500 =
F_166 ( V_30 -> V_5 [ V_1501 ] ) ;
V_35 = F_312 ( V_7 , V_551 , & V_1488 , V_1489 ) ;
if ( V_35 )
F_311 ( V_1489 ) ;
return V_35 ;
}
static int F_313 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
if ( ! V_7 -> V_353 -> V_1502 )
return - V_552 ;
if ( V_551 -> V_28 -> V_142 != V_147 )
return - V_552 ;
return F_314 ( V_7 , V_551 , false ) ;
}
static int F_315 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
int V_1485 [ V_364 ] ;
V_22 V_1503 ;
int V_35 ;
if ( V_551 -> V_28 -> V_142 != V_147 &&
V_551 -> V_28 -> V_142 != V_146 &&
V_551 -> V_28 -> V_142 != V_153 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_435 )
return - V_552 ;
memset ( V_1485 , 0 , sizeof( V_1485 ) ) ;
if ( ! V_30 -> V_5 [ V_1498 ] )
return - V_16 ;
V_1503 = F_4 ( V_30 -> V_5 [ V_1498 ] ) ;
if ( ! F_308 ( V_7 , V_1485 , V_1503 ) )
return - V_16 ;
V_35 = F_316 ( V_7 , V_551 , V_1485 ) ;
return V_35 ;
}
static struct V_31 *
F_317 ( struct V_6 * V_7 ,
struct V_1 * V_17 , int V_1504 ,
V_22 V_49 , V_22 V_50 , enum V_282 V_52 ,
enum V_823 V_45 ,
const struct V_483 * V_30 ,
T_12 V_1505 )
{
struct V_31 * V_32 ;
void * V_285 ;
struct V_4 * V_141 ;
V_32 = F_74 ( V_1504 + 100 , V_1505 ) ;
if ( ! V_32 )
return NULL ;
V_285 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_285 ) {
F_318 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1506 ,
V_30 -> V_1507 ) )
goto V_61;
if ( F_28 ( V_32 , V_1508 ,
V_30 -> V_1509 ) )
goto V_61;
}
if ( V_17 ) {
if ( F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) , V_598 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_32 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_61;
}
V_141 = F_47 ( V_32 , V_45 ) ;
if ( ! V_141 )
goto V_61;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_285 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_141 ;
return V_32 ;
V_61:
F_318 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_319 ( struct V_18 * V_18 ,
struct V_1 * V_17 ,
enum V_282 V_52 ,
enum V_823 V_45 ,
int V_1510 ,
int V_1504 , T_12 V_1505 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_483 * V_30 ;
switch ( V_52 ) {
case V_1511 :
if ( F_59 ( V_1510 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1512 :
if ( F_59 ( V_1510 < 0 ||
V_1510 >= V_18 -> V_487 ) )
return NULL ;
V_30 = & V_18 -> V_489 [ V_1510 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_317 ( V_7 , V_17 , V_1504 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1505 ) ;
}
void F_320 ( struct V_31 * V_32 , T_12 V_1505 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_285 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_141 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1513 V_1514 = V_1515 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_141 ) ;
F_66 ( V_32 , V_285 ) ;
if ( V_141 -> F_155 == V_485 )
V_1514 = V_1516 ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1514 , V_1505 ) ;
}
static int F_322 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_353 -> V_437 )
return - V_552 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1517 ] )
return - V_16 ;
V_7 -> V_1518 = V_30 ;
V_35 = F_323 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1517 ] ) ,
F_24 ( V_30 -> V_5 [ V_1517 ] ) ) ;
V_7 -> V_1518 = NULL ;
return V_35 ;
}
static int F_324 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1519 ;
void * V_141 = NULL ;
int V_1520 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1519 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_942;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_942;
}
V_1519 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1517 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1517 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_141 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1520 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1519 ) ;
if ( ! V_7 ) {
V_35 = - V_671 ;
goto V_942;
}
if ( ! V_7 -> V_353 -> V_1521 ) {
V_35 = - V_552 ;
goto V_942;
}
while ( 1 ) {
void * V_285 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_1511 ) ;
struct V_4 * V_1522 ;
if ( ! V_285 )
break;
if ( F_28 ( V_32 , V_26 , V_1519 ) ) {
F_67 ( V_32 , V_285 ) ;
break;
}
V_1522 = F_47 ( V_32 , V_1517 ) ;
if ( ! V_1522 ) {
F_67 ( V_32 , V_285 ) ;
break;
}
V_35 = F_325 ( V_7 , V_32 , V_34 , V_141 , V_1520 ) ;
F_48 ( V_32 , V_1522 ) ;
if ( V_35 == - V_91 || V_35 == - V_671 ) {
F_67 ( V_32 , V_285 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_285 ) ;
goto V_942;
}
F_66 ( V_32 , V_285 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1519 + 1 ;
V_942:
F_20 () ;
return V_35 ;
}
static int F_326 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1523 V_451 ;
struct V_18 * V_18 ;
struct V_130 * V_1489 = NULL ;
int V_35 ;
memset ( & V_451 , 0 , sizeof( V_451 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_605 ] ||
! F_24 ( V_30 -> V_5 [ V_605 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_779 ] ) {
V_451 . V_761 =
F_4 ( V_30 -> V_5 [ V_779 ] ) ;
if ( ! F_162 ( V_7 , V_451 . V_761 ,
V_452 ) )
return - V_16 ;
} else
V_451 . V_761 = V_780 ;
V_451 . V_777 = V_30 -> V_5 [ V_778 ] ;
V_35 = F_165 ( V_7 , V_30 , & V_451 . V_781 ,
V_782 ) ;
if ( V_35 )
return V_35 ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
V_18 = & V_7 -> V_18 ;
V_451 . V_1524 = - 1 ;
if ( V_30 -> V_5 [ V_1525 ] &&
( V_18 -> V_51 & V_332 ) ) {
V_451 . V_1524 =
F_78 ( V_30 -> V_5 [ V_1525 ] ) ;
}
if ( V_30 -> V_5 [ V_559 ] )
V_451 . V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
else if ( V_30 -> V_5 [ V_1526 ] )
V_451 . V_1527 =
F_23 ( V_30 -> V_5 [ V_1526 ] ) ;
V_451 . V_606 = F_23 ( V_30 -> V_5 [ V_605 ] ) ;
V_451 . V_604 = F_24 ( V_30 -> V_5 [ V_605 ] ) ;
if ( V_30 -> V_5 [ V_742 ] ) {
V_451 . V_1189 = F_23 ( V_30 -> V_5 [ V_742 ] ) ;
V_451 . V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
}
if ( V_30 -> V_5 [ V_1466 ] ) {
V_451 . V_1468 = F_4 ( V_30 -> V_5 [ V_1466 ] ) ;
if ( V_451 . V_1468 != V_1469 &&
V_451 . V_1468 != V_1471 )
return - V_16 ;
} else {
V_451 . V_1468 = V_1471 ;
}
if ( V_30 -> V_5 [ V_1472 ] )
V_451 . V_1473 =
F_23 ( V_30 -> V_5 [ V_1472 ] ) ;
if ( V_30 -> V_5 [ V_534 ] ) {
V_451 . V_1381 = F_44 (
V_18 , V_30 -> V_5 [ V_534 ] ) ;
if ( ! V_451 . V_1381 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1528 ] ) {
V_451 . V_1529 = F_44 (
V_18 , V_30 -> V_5 [ V_1528 ] ) ;
if ( ! V_451 . V_1529 )
return - V_16 ;
}
if ( V_451 . V_777 && V_30 -> V_5 [ V_1499 ] ) {
V_1489 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1499 ] , NULL ) ;
if ( F_17 ( V_1489 ) )
return F_18 ( V_1489 ) ;
}
if ( F_166 ( V_30 -> V_5 [ V_1474 ] ) )
V_451 . V_51 |= V_1475 ;
if ( V_30 -> V_5 [ V_467 ] )
memcpy ( & V_451 . V_1476 ,
F_23 ( V_30 -> V_5 [ V_467 ] ) ,
sizeof( V_451 . V_1476 ) ) ;
if ( V_30 -> V_5 [ V_993 ] ) {
if ( ! V_30 -> V_5 [ V_467 ] ) {
F_311 ( V_1489 ) ;
return - V_16 ;
}
memcpy ( & V_451 . V_964 ,
F_23 ( V_30 -> V_5 [ V_993 ] ) ,
sizeof( V_451 . V_964 ) ) ;
}
if ( F_166 ( V_30 -> V_5 [ V_1477 ] ) )
V_451 . V_51 |= V_1478 ;
if ( V_30 -> V_5 [ V_476 ] )
memcpy ( & V_451 . V_1479 ,
F_23 ( V_30 -> V_5 [ V_476 ] ) ,
sizeof( V_451 . V_1479 ) ) ;
if ( V_30 -> V_5 [ V_994 ] ) {
if ( ! V_30 -> V_5 [ V_476 ] ) {
F_311 ( V_1489 ) ;
return - V_16 ;
}
memcpy ( & V_451 . V_965 ,
F_23 ( V_30 -> V_5 [ V_994 ] ) ,
sizeof( V_451 . V_965 ) ) ;
}
if ( F_166 ( V_30 -> V_5 [ V_1480 ] ) ) {
if ( ! ( ( V_7 -> V_18 . V_293 &
V_1481 ) &&
( V_7 -> V_18 . V_293 & V_1482 ) ) &&
! F_116 ( & V_7 -> V_18 ,
V_1483 ) ) {
F_311 ( V_1489 ) ;
return - V_16 ;
}
V_451 . V_51 |= V_1484 ;
}
V_451 . V_799 = F_166 ( V_30 -> V_5 [ V_800 ] ) ;
if ( V_451 . V_799 && ! V_7 -> V_18 . V_365 [ V_801 ] ) {
F_311 ( V_1489 ) ;
return - V_552 ;
}
if ( V_30 -> V_5 [ V_498 ] ) {
if ( V_451 . V_558 ) {
F_311 ( V_1489 ) ;
return - V_16 ;
}
V_35 = F_254 ( V_30 -> V_5 [ V_498 ] ,
V_18 , & V_451 . V_1253 ) ;
if ( V_35 ) {
F_311 ( V_1489 ) ;
return V_35 ;
}
}
F_113 ( V_551 -> V_28 ) ;
V_35 = F_327 ( V_7 , V_551 , & V_451 , V_1489 ,
V_451 . V_1473 ) ;
F_115 ( V_551 -> V_28 ) ;
if ( V_35 )
F_311 ( V_1489 ) ;
return V_35 ;
}
static int F_328 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_3 V_1530 ;
int V_508 ;
if ( ! V_30 -> V_5 [ V_1030 ] )
V_1530 = V_1531 ;
else
V_1530 = F_78 ( V_30 -> V_5 [ V_1030 ] ) ;
if ( V_1530 == 0 )
return - V_16 ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
F_113 ( V_551 -> V_28 ) ;
V_508 = F_329 ( V_7 , V_551 , V_1530 , true ) ;
F_115 ( V_551 -> V_28 ) ;
return V_508 ;
}
static int F_330 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
if ( V_30 -> V_5 [ V_1532 ] ) {
V_22 V_1533 = F_4 ( V_30 -> V_5 [ V_1532 ] ) ;
V_2 = F_331 ( V_1533 ) ;
} else if ( V_30 -> V_5 [ V_1534 ] ) {
V_22 V_1535 = F_4 ( V_30 -> V_5 [ V_1534 ] ) ;
V_2 = F_332 ( V_1535 ) ;
} else {
return - V_16 ;
}
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_333 ( V_7 , V_2 ) ;
F_334 ( V_2 ) ;
return V_35 ;
}
static int F_335 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
int (* F_336)( struct V_18 * V_18 , struct V_25 * V_551 ,
struct V_1536 * V_1537 ) = NULL ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1536 V_1537 ;
memset ( & V_1537 , 0 , sizeof( struct V_1536 ) ) ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1538 ] )
return - V_16 ;
V_1537 . V_1539 = F_23 ( V_30 -> V_5 [ V_1538 ] ) ;
V_1537 . V_558 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
switch ( V_30 -> V_1540 -> V_52 ) {
case V_1541 :
F_336 = V_7 -> V_353 -> V_399 ;
break;
case V_1542 :
F_336 = V_7 -> V_353 -> V_401 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_336 )
return - V_552 ;
return F_336 ( & V_7 -> V_18 , V_551 , & V_1537 ) ;
}
static int F_337 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
if ( V_551 -> V_28 -> V_142 != V_148 &&
V_551 -> V_28 -> V_142 != V_149 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_403 )
return - V_552 ;
return F_338 ( V_7 , V_551 ) ;
}
static int F_339 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 V_1543 , V_1544 ;
V_22 V_1545 = 0 ;
T_3 V_1546 ;
T_2 * V_1547 ;
bool V_1548 ;
if ( ! ( V_7 -> V_18 . V_51 & V_334 ) ||
! V_7 -> V_353 -> V_420 )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_1549 ] ||
! V_30 -> V_5 [ V_1550 ] ||
! V_30 -> V_5 [ V_1551 ] ||
! V_30 -> V_5 [ V_742 ] ||
! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_1547 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_1543 = F_34 ( V_30 -> V_5 [ V_1549 ] ) ;
V_1546 = F_78 ( V_30 -> V_5 [ V_1550 ] ) ;
V_1544 = F_34 ( V_30 -> V_5 [ V_1551 ] ) ;
V_1548 = F_166 ( V_30 -> V_5 [ V_1552 ] ) ;
if ( V_30 -> V_5 [ V_1553 ] )
V_1545 =
F_4 ( V_30 -> V_5 [ V_1553 ] ) ;
return F_340 ( V_7 , V_551 , V_1547 , V_1543 ,
V_1544 , V_1546 , V_1545 ,
V_1548 ,
F_23 ( V_30 -> V_5 [ V_742 ] ) ,
F_24 ( V_30 -> V_5 [ V_742 ] ) ) ;
}
static int F_341 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
enum V_1554 V_1555 ;
T_2 * V_1547 ;
if ( ! ( V_7 -> V_18 . V_51 & V_334 ) ||
! V_7 -> V_353 -> V_422 )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_1556 ] ||
! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_1555 = F_34 ( V_30 -> V_5 [ V_1556 ] ) ;
V_1547 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
return F_342 ( V_7 , V_551 , V_1547 , V_1555 ) ;
}
static int F_343 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
struct V_531 V_532 ;
struct V_31 * V_53 ;
void * V_285 ;
T_1 V_663 ;
V_22 V_1283 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_534 ] ||
! V_30 -> V_5 [ V_1557 ] )
return - V_16 ;
V_1283 = F_4 ( V_30 -> V_5 [ V_1557 ] ) ;
if ( ! V_7 -> V_353 -> V_406 ||
! ( V_7 -> V_18 . V_51 & V_405 ) )
return - V_552 ;
if ( V_1283 < V_1558 ||
V_1283 > V_7 -> V_18 . V_456 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_532 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1559 ) ;
if ( ! V_285 ) {
V_35 = - V_91 ;
goto V_673;
}
V_35 = F_344 ( V_7 , V_17 , V_532 . V_55 ,
V_1283 , & V_663 ) ;
if ( V_35 )
goto V_673;
if ( F_104 ( V_53 , V_1560 , V_663 ,
V_598 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_673:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_345 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
T_1 V_663 ;
if ( ! V_30 -> V_5 [ V_1560 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_1561 )
return - V_552 ;
V_663 = F_5 ( V_30 -> V_5 [ V_1560 ] ) ;
return F_346 ( V_7 , V_17 , V_663 ) ;
}
static int F_347 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_716 V_697 ;
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_353 -> V_408 )
return - V_552 ;
V_35 = F_154 ( V_30 , & V_697 ) ;
if ( V_35 )
return V_35 ;
return F_348 ( V_7 , V_551 , NULL , & V_697 ) ;
}
static int F_349 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
T_3 V_1562 = V_279 | V_1563 ;
if ( ! V_30 -> V_5 [ V_1564 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_278 ] )
V_1562 = F_78 ( V_30 -> V_5 [ V_278 ] ) ;
switch ( V_17 -> V_142 ) {
case V_148 :
case V_147 :
case V_149 :
case V_143 :
case V_144 :
case V_146 :
case V_145 :
case V_156 :
break;
case V_155 :
default:
return - V_552 ;
}
if ( ! V_7 -> V_353 -> V_410 )
return - V_552 ;
return F_350 ( V_17 , V_30 -> V_516 , V_1562 ,
F_23 ( V_30 -> V_5 [ V_1564 ] ) ,
F_24 ( V_30 -> V_5 [ V_1564 ] ) ) ;
}
static int F_351 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
struct V_531 V_532 ;
int V_35 ;
void * V_285 = NULL ;
T_1 V_663 ;
struct V_31 * V_53 = NULL ;
struct V_1565 V_140 = {
. V_1566 =
V_30 -> V_5 [ V_1567 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1568 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_410 )
return - V_552 ;
switch ( V_17 -> V_142 ) {
case V_156 :
if ( ! V_30 -> V_5 [ V_534 ] )
return - V_16 ;
case V_148 :
case V_147 :
case V_149 :
case V_143 :
case V_144 :
case V_146 :
case V_145 :
break;
case V_155 :
default:
return - V_552 ;
}
if ( V_30 -> V_5 [ V_1557 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_457 ) )
return - V_16 ;
V_140 . V_1569 = F_4 ( V_30 -> V_5 [ V_1557 ] ) ;
if ( V_140 . V_1569 < V_1558 ||
V_140 . V_1569 > V_7 -> V_18 . V_456 )
return - V_16 ;
}
V_140 . V_1570 = V_30 -> V_5 [ V_458 ] ;
if ( V_140 . V_1570 && ! ( V_7 -> V_18 . V_51 & V_457 ) )
return - V_16 ;
V_140 . V_1291 = F_166 ( V_30 -> V_5 [ V_1292 ] ) ;
V_532 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_534 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_532 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_532 . V_55 && V_140 . V_1570 )
return - V_16 ;
V_140 . V_1571 = F_23 ( V_30 -> V_5 [ V_1568 ] ) ;
V_140 . V_47 = F_24 ( V_30 -> V_5 [ V_1568 ] ) ;
if ( V_30 -> V_5 [ V_1572 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1572 ] ) ;
int V_161 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_140 . V_1573 = V_47 / sizeof( T_3 ) ;
V_140 . V_1574 =
F_23 ( V_30 -> V_5 [ V_1572 ] ) ;
for ( V_161 = 0 ; V_161 < V_140 . V_1573 ; V_161 ++ ) {
if ( V_140 . V_1574 [ V_161 ] >= V_140 . V_47 )
return - V_16 ;
}
}
if ( ! V_140 . V_1566 ) {
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1575 ) ;
if ( ! V_285 ) {
V_35 = - V_91 ;
goto V_673;
}
}
V_140 . V_55 = V_532 . V_55 ;
V_35 = F_352 ( V_7 , V_17 , & V_140 , & V_663 ) ;
if ( V_35 )
goto V_673;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1560 , V_663 ,
V_598 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_673:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_353 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
T_1 V_663 ;
if ( ! V_30 -> V_5 [ V_1560 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_412 )
return - V_552 ;
switch ( V_17 -> V_142 ) {
case V_148 :
case V_147 :
case V_149 :
case V_143 :
case V_144 :
case V_145 :
case V_156 :
break;
case V_155 :
default:
return - V_552 ;
}
V_663 = F_5 ( V_30 -> V_5 [ V_1560 ] ) ;
return F_354 ( V_7 , V_17 , V_663 ) ;
}
static int F_355 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 V_1576 ;
bool V_284 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1577 ] )
return - V_16 ;
V_1576 = F_4 ( V_30 -> V_5 [ V_1577 ] ) ;
if ( V_1576 != V_1578 && V_1576 != V_1579 )
return - V_16 ;
V_17 = V_551 -> V_28 ;
if ( ! V_7 -> V_353 -> V_1580 )
return - V_552 ;
V_284 = ( V_1576 == V_1579 ) ? true : false ;
if ( V_284 == V_17 -> V_1581 )
return 0 ;
V_35 = F_356 ( V_7 , V_551 , V_284 , V_17 -> V_1582 ) ;
if ( ! V_35 )
V_17 -> V_1581 = V_284 ;
return V_35 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
enum V_1583 V_1576 ;
struct V_1 * V_17 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_31 * V_53 ;
void * V_285 ;
int V_35 ;
V_17 = V_551 -> V_28 ;
if ( ! V_7 -> V_353 -> V_1580 )
return - V_552 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1584 ) ;
if ( ! V_285 ) {
V_35 = - V_91 ;
goto V_673;
}
if ( V_17 -> V_1581 )
V_1576 = V_1579 ;
else
V_1576 = V_1578 ;
if ( F_28 ( V_53 , V_1577 , V_1576 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_673:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_358 ( struct V_29 * V_30 ,
V_22 V_246 , V_22 V_1585 , V_22 V_1586 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
if ( V_246 > 100 || V_1586 > V_1587 )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_1588 )
return - V_552 ;
if ( V_17 -> V_142 != V_148 &&
V_17 -> V_142 != V_149 )
return - V_552 ;
return F_359 ( V_7 , V_551 , V_246 , V_1585 , V_1586 ) ;
}
static int F_360 ( struct V_29 * V_30 ,
T_8 V_1589 , V_22 V_1590 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
if ( V_1589 > 0 )
return - V_16 ;
if ( V_1589 == 0 )
V_1590 = 0 ;
if ( ! V_7 -> V_353 -> V_1591 )
return - V_552 ;
if ( V_17 -> V_142 != V_148 &&
V_17 -> V_142 != V_149 )
return - V_552 ;
return F_361 ( V_7 , V_551 , V_1589 , V_1590 ) ;
}
static int F_362 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1592 + 1 ] ;
struct V_4 * V_1593 ;
int V_35 ;
V_1593 = V_30 -> V_5 [ V_1594 ] ;
if ( ! V_1593 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1592 , V_1593 ,
V_1595 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1596 ] &&
V_5 [ V_1597 ] ) {
T_8 V_1589 = F_227 ( V_5 [ V_1596 ] ) ;
V_22 V_1590 = F_4 ( V_5 [ V_1597 ] ) ;
return F_360 ( V_30 , V_1589 , V_1590 ) ;
}
if ( V_5 [ V_1598 ] &&
V_5 [ V_1599 ] &&
V_5 [ V_1600 ] ) {
V_22 V_246 = F_4 ( V_5 [ V_1598 ] ) ;
V_22 V_1585 = F_4 ( V_5 [ V_1599 ] ) ;
V_22 V_1586 = F_4 ( V_5 [ V_1600 ] ) ;
return F_358 ( V_30 , V_246 , V_1585 , V_1586 ) ;
}
return - V_16 ;
}
static int F_363 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1601 V_1171 = {} ;
int V_35 ;
V_35 = F_80 ( V_7 , V_30 , & V_1171 . V_532 ) ;
if ( V_35 )
return V_35 ;
return F_364 ( V_7 , V_551 , & V_1171 ) ;
}
static int F_365 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
return F_366 ( V_7 , V_551 ) ;
}
static int F_367 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1094 V_1158 ;
struct V_1170 V_1171 ;
int V_35 ;
memcpy ( & V_1158 , & V_1098 , sizeof( V_1158 ) ) ;
memcpy ( & V_1171 , & V_1602 , sizeof( V_1171 ) ) ;
if ( V_30 -> V_5 [ V_1100 ] ) {
V_35 = F_229 ( V_30 , & V_1158 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_629 ] ||
! F_24 ( V_30 -> V_5 [ V_629 ] ) )
return - V_16 ;
V_1171 . V_1603 = F_23 ( V_30 -> V_5 [ V_629 ] ) ;
V_1171 . V_1097 = F_24 ( V_30 -> V_5 [ V_629 ] ) ;
if ( V_30 -> V_5 [ V_1498 ] &&
! F_308 ( V_7 , V_1171 . V_1485 ,
F_4 ( V_30 -> V_5 [ V_1498 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_768 ] ) {
V_1171 . V_553 =
F_4 ( V_30 -> V_5 [ V_768 ] ) ;
V_35 = F_164 ( V_7 , V_1171 . V_553 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_769 ] ) {
V_1171 . V_771 =
F_4 ( V_30 -> V_5 [ V_769 ] ) ;
if ( V_1171 . V_771 < 1 || V_1171 . V_771 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1173 ] ) {
V_35 = F_231 ( V_30 , & V_1171 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1171 . V_1193 )
V_1158 . V_1116 = false ;
if ( V_30 -> V_5 [ V_534 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1171 . V_532 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1171 . V_532 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_1078 ] ) {
T_2 * V_695 = F_23 ( V_30 -> V_5 [ V_1078 ] ) ;
int V_1497 =
F_24 ( V_30 -> V_5 [ V_1078 ] ) ;
struct V_241 * V_242 ;
if ( ! V_1171 . V_532 . V_55 )
return - V_16 ;
V_242 = V_7 -> V_18 . V_365 [ V_1171 . V_532 . V_55 -> V_292 ] ;
V_35 = F_261 ( V_242 , V_695 , V_1497 ,
& V_1171 . V_1079 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_723 ] ) {
V_35 = F_154 ( V_30 , & V_1171 . V_732 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_156 ( V_7 , V_1171 . V_532 . V_55 -> V_292 ,
& V_1171 . V_732 ) ;
if ( V_35 )
return V_35 ;
}
return F_368 ( V_7 , V_551 , & V_1171 , & V_1158 ) ;
}
static int F_369 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
return F_370 ( V_7 , V_551 ) ;
}
static int F_371 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1604 * V_191 = V_7 -> V_18 . V_1605 ;
struct V_4 * V_1606 , * V_1607 ;
int V_161 , V_1608 ;
if ( ! V_191 -> V_221 )
return 0 ;
V_1606 = F_47 ( V_53 , V_230 ) ;
if ( ! V_1606 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_191 -> V_221 ; V_161 ++ ) {
V_1607 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1607 )
return - V_91 ;
V_1608 = V_191 -> V_1609 [ V_161 ] . V_1610 ;
if ( F_51 ( V_53 , V_1611 , F_269 ( V_1608 , 8 ) ,
V_191 -> V_1609 [ V_161 ] . V_697 ) ||
F_51 ( V_53 , V_1612 , V_1608 ,
V_191 -> V_1609 [ V_161 ] . V_1613 ) ||
F_28 ( V_53 , V_1614 ,
V_191 -> V_1609 [ V_161 ] . V_1615 ) )
return - V_91 ;
F_48 ( V_53 , V_1607 ) ;
}
F_48 ( V_53 , V_1606 ) ;
return 0 ;
}
static int F_372 ( struct V_31 * V_53 ,
struct V_1616 * V_190 )
{
struct V_4 * V_192 ;
if ( ! V_190 )
return 0 ;
V_192 = F_47 ( V_53 , V_193 ) ;
if ( ! V_192 )
return - V_91 ;
if ( F_373 ( V_53 , V_1617 , V_190 -> V_1618 ) ||
F_373 ( V_53 , V_1619 , V_190 -> V_1033 ) ||
F_51 ( V_53 , V_1620 , V_599 , V_190 -> V_1621 ) ||
F_55 ( V_53 , V_1622 , V_190 -> V_1623 ) ||
F_55 ( V_53 , V_1624 , V_190 -> V_1625 ) ||
F_51 ( V_53 , V_194 ,
V_190 -> V_1626 , V_190 -> V_1627 ) ||
F_28 ( V_53 , V_199 ,
V_190 -> V_1628 ) ||
F_51 ( V_53 , V_201 ,
V_190 -> V_1629 , V_190 -> V_1630 ) ||
F_51 ( V_53 , V_1631 ,
F_269 ( V_190 -> V_1629 , 8 ) , V_190 -> V_1632 ) )
return - V_91 ;
if ( V_190 -> V_1633 . V_47 &&
F_51 ( V_53 , V_196 ,
sizeof( V_190 -> V_1633 ) , & V_190 -> V_1633 ) )
return - V_91 ;
if ( V_190 -> V_1634 . V_47 &&
F_51 ( V_53 , V_198 ,
sizeof( V_190 -> V_1634 ) + V_190 -> V_1635 ,
& V_190 -> V_1634 ) )
return - V_91 ;
F_48 ( V_53 , V_192 ) ;
return 0 ;
}
static int F_374 ( struct V_31 * V_53 ,
struct V_1297 * V_1465 )
{
struct V_4 * V_1636 , * V_1246 , * V_1637 , * V_1638 , * V_1301 , * V_1639 ;
int V_161 ;
if ( ! V_1465 )
return 0 ;
V_1636 = F_47 ( V_53 , V_232 ) ;
if ( ! V_1636 )
return - V_91 ;
if ( V_1465 -> V_1319 == 1 &&
F_28 ( V_53 , V_1300 ,
V_1465 -> V_1301 [ 0 ] . V_1299 * 1000 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1326 , V_1465 -> V_1327 ) )
return - V_91 ;
V_1246 = F_47 ( V_53 , V_1276 ) ;
if ( ! V_1246 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_1465 -> V_368 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1465 -> V_369 [ V_161 ] -> V_60 ) )
return - V_91 ;
}
F_48 ( V_53 , V_1246 ) ;
if ( V_1465 -> V_1309 ) {
V_1637 = F_47 ( V_53 , V_1313 ) ;
if ( ! V_1637 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_1465 -> V_1309 ; V_161 ++ ) {
V_1638 = F_47 ( V_53 , V_161 ) ;
if ( ! V_1638 )
return - V_91 ;
if ( F_51 ( V_53 , V_1316 ,
V_1465 -> V_1318 [ V_161 ] . V_606 . V_604 ,
V_1465 -> V_1318 [ V_161 ] . V_606 . V_606 ) )
return - V_91 ;
F_48 ( V_53 , V_1638 ) ;
}
F_48 ( V_53 , V_1637 ) ;
}
V_1301 = F_47 ( V_53 , V_1298 ) ;
if ( ! V_1301 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_1465 -> V_1319 ; V_161 ++ ) {
V_1639 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1639 )
return - V_91 ;
if ( ! V_1639 ||
F_28 ( V_53 , V_1306 ,
V_1465 -> V_1301 [ V_161 ] . V_1299 ) ||
( V_1465 -> V_1301 [ V_161 ] . V_1308 &&
F_28 ( V_53 , V_1307 ,
V_1465 -> V_1301 [ V_161 ] . V_1308 ) ) )
return - V_91 ;
F_48 ( V_53 , V_1639 ) ;
}
F_48 ( V_53 , V_1301 ) ;
F_48 ( V_53 , V_1636 ) ;
return 0 ;
}
static int F_375 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_31 * V_53 ;
void * V_285 ;
V_22 V_1640 = V_612 ;
if ( ! V_7 -> V_18 . V_191 )
return - V_552 ;
if ( V_7 -> V_18 . V_1605 && V_7 -> V_18 . V_1605 -> V_190 ) {
V_1640 += V_7 -> V_18 . V_1605 -> V_190 -> V_1635 +
V_7 -> V_18 . V_1605 -> V_190 -> V_1626 +
V_7 -> V_18 . V_1605 -> V_190 -> V_1629 +
V_7 -> V_18 . V_1605 -> V_190 -> V_1629 / 8 ;
}
V_53 = F_74 ( V_1640 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1641 ) ;
if ( ! V_285 )
goto V_61;
if ( V_7 -> V_18 . V_1605 ) {
struct V_4 * V_203 ;
V_203 = F_47 ( V_53 , V_1642 ) ;
if ( ! V_203 )
goto V_61;
if ( ( V_7 -> V_18 . V_1605 -> V_1643 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1605 -> V_453 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1605 -> V_1644 &&
F_29 ( V_53 , V_210 ) ) ||
( V_7 -> V_18 . V_1605 -> V_1645 &&
F_29 ( V_53 , V_214 ) ) ||
( V_7 -> V_18 . V_1605 -> V_1646 &&
F_29 ( V_53 , V_216 ) ) ||
( V_7 -> V_18 . V_1605 -> V_1647 &&
F_29 ( V_53 , V_218 ) ) ||
( V_7 -> V_18 . V_1605 -> V_1648 &&
F_29 ( V_53 , V_220 ) ) )
goto V_61;
if ( F_371 ( V_53 , V_7 ) )
goto V_61;
if ( F_372 ( V_53 ,
V_7 -> V_18 . V_1605 -> V_190 ) )
goto V_61;
if ( F_374 (
V_53 ,
V_7 -> V_18 . V_1605 -> V_1649 ) )
goto V_61;
F_48 ( V_53 , V_203 ) ;
}
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_376 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1604 * V_1650 )
{
struct V_4 * V_95 [ V_1651 ] ;
struct V_1616 * V_1158 ;
struct V_1652 * V_197 = NULL ;
struct V_1653 * V_50 = NULL ;
V_22 V_1640 ;
V_22 V_1654 , V_1655 , V_1635 = 0 , V_1656 ;
int V_35 , V_1657 ;
if ( ! V_7 -> V_18 . V_191 -> V_190 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1658 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1659 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1617 ] ||
! V_95 [ V_1619 ] ||
! V_95 [ V_1620 ] ||
! V_95 [ V_1624 ] ||
! V_95 [ V_194 ] ||
! V_95 [ V_199 ] ||
! V_95 [ V_201 ] ||
! V_95 [ V_1631 ] )
return - V_16 ;
V_1654 = F_24 ( V_95 [ V_194 ] ) ;
if ( V_1654 > V_7 -> V_18 . V_191 -> V_190 -> V_195 )
return - V_16 ;
if ( F_4 ( V_95 [ V_199 ] ) >
V_7 -> V_18 . V_191 -> V_190 -> V_200 ||
F_4 ( V_95 [ V_199 ] ) == 0 )
return - V_16 ;
V_1655 = F_24 ( V_95 [ V_201 ] ) ;
if ( V_1655 > V_7 -> V_18 . V_191 -> V_190 -> V_202 )
return - V_16 ;
V_1656 = F_24 ( V_95 [ V_1631 ] ) ;
if ( V_1656 != F_269 ( V_1655 , 8 ) )
return - V_16 ;
if ( V_95 [ V_198 ] ) {
V_22 V_1660 = F_24 ( V_95 [ V_198 ] ) ;
V_197 = F_23 ( V_95 [ V_198 ] ) ;
V_1635 = V_1660 - sizeof( * V_197 ) ;
if ( ! V_197 -> V_47 || V_1635 % V_197 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_191 -> V_190 -> V_197 )
return - V_16 ;
if ( V_197 -> V_47 > V_7 -> V_18 . V_191 -> V_190 -> V_197 -> V_1661 )
return - V_16 ;
if ( V_197 -> V_47 < V_7 -> V_18 . V_191 -> V_190 -> V_197 -> V_1662 )
return - V_16 ;
if ( V_1635 > V_7 -> V_18 . V_191 -> V_190 -> V_197 -> V_1663 )
return - V_16 ;
if ( V_197 -> V_1351 + V_197 -> V_47 > V_1654 )
return - V_16 ;
}
if ( V_95 [ V_196 ] ) {
V_50 = F_23 ( V_95 [ V_196 ] ) ;
if ( ! V_7 -> V_18 . V_191 -> V_190 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1351 > V_1654 )
return - V_16 ;
}
V_1640 = sizeof( * V_1158 ) ;
V_1640 += V_1654 ;
V_1640 += V_1655 + V_1656 ;
V_1640 += V_1635 ;
V_1158 = F_39 ( V_1640 , V_136 ) ;
if ( ! V_1158 )
return - V_137 ;
V_1158 -> V_1618 = F_377 ( V_95 [ V_1617 ] ) ;
V_1158 -> V_1033 = F_377 ( V_95 [ V_1619 ] ) ;
memcpy ( V_1158 -> V_1621 , F_23 ( V_95 [ V_1620 ] ) ,
V_599 ) ;
if ( V_95 [ V_1622 ] )
V_1657 = F_78 ( V_95 [ V_1622 ] ) ;
else
V_1657 = 0 ;
#ifdef F_378
V_35 = F_379 ( F_7 ( & V_7 -> V_18 ) , V_1664 , V_1665 ,
V_1666 , & V_1158 -> V_1667 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1158 ) ;
return V_35 ;
}
if ( F_380 ( V_1158 -> V_1667 -> V_44 , V_1657 ) ) {
F_381 ( V_1158 -> V_1667 ) ;
F_41 ( V_1158 ) ;
return - V_1668 ;
}
V_1158 -> V_1623 = F_382 ( V_1158 -> V_1667 -> V_44 ) -> V_1669 ;
#else
if ( ! V_1657 ) {
F_41 ( V_1158 ) ;
return - V_16 ;
}
V_1158 -> V_1623 = V_1657 ;
#endif
V_1158 -> V_1625 = F_78 ( V_95 [ V_1624 ] ) ;
V_1158 -> V_1626 = V_1654 ;
V_1158 -> V_1627 = ( T_2 * ) V_1158 + sizeof( * V_1158 ) + V_1635 ;
memcpy ( ( void * ) V_1158 -> V_1627 ,
F_23 ( V_95 [ V_194 ] ) ,
V_1654 ) ;
if ( V_50 )
V_1158 -> V_1633 = * V_50 ;
V_1158 -> V_1628 = F_4 ( V_95 [ V_199 ] ) ;
V_1158 -> V_1629 = V_1655 ;
V_1158 -> V_1630 = ( T_2 * ) V_1158 + sizeof( * V_1158 ) + V_1635 + V_1654 ;
memcpy ( ( void * ) V_1158 -> V_1630 ,
F_23 ( V_95 [ V_201 ] ) ,
V_1655 ) ;
V_1158 -> V_1632 = ( T_2 * ) V_1158 + sizeof( * V_1158 ) + V_1635 +
V_1654 + V_1655 ;
memcpy ( ( void * ) V_1158 -> V_1632 ,
F_23 ( V_95 [ V_1631 ] ) ,
V_1656 ) ;
if ( V_197 ) {
V_1158 -> V_1635 = V_1635 ;
memcpy ( & V_1158 -> V_1634 , V_197 , sizeof( * V_197 ) + V_1635 ) ;
}
V_1650 -> V_190 = V_1158 ;
return 0 ;
}
static int F_383 ( struct V_6 * V_7 ,
const struct V_1670 * V_191 ,
struct V_4 * V_45 ,
struct V_1604 * V_1650 )
{
struct V_4 * * V_95 ;
int V_35 ;
V_95 = F_39 ( V_1671 * sizeof( * V_95 ) , V_136 ) ;
if ( ! V_95 )
return - V_137 ;
if ( ! ( V_191 -> V_51 & V_231 ) ) {
V_35 = - V_552 ;
goto V_611;
}
V_35 = F_96 ( V_95 , V_1338 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_42 ) ;
if ( V_35 )
goto V_611;
V_1650 -> V_1649 = F_270 ( & V_7 -> V_18 , NULL , V_95 ) ;
V_35 = F_272 ( V_1650 -> V_1649 ) ;
if ( V_35 )
V_1650 -> V_1649 = NULL ;
V_611:
F_41 ( V_95 ) ;
return V_35 ;
}
static int F_384 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_4 * V_95 [ V_1672 ] ;
struct V_1604 V_1673 = {} ;
struct V_1604 * V_1674 ;
const struct V_1670 * V_191 = V_7 -> V_18 . V_191 ;
int V_35 , V_161 ;
bool V_1675 = V_7 -> V_18 . V_1605 ;
bool V_1676 = false ;
if ( ! V_191 )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_1642 ] ) {
F_385 ( V_7 ) ;
V_7 -> V_18 . V_1605 = NULL ;
goto V_1677;
}
V_35 = F_96 ( V_95 , V_1678 ,
F_23 ( V_30 -> V_5 [ V_1642 ] ) ,
F_24 ( V_30 -> V_5 [ V_1642 ] ) ,
V_1679 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_206 ] ) {
if ( ! ( V_191 -> V_51 & V_205 ) )
return - V_16 ;
V_1673 . V_1643 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_191 -> V_51 & V_207 ) )
return - V_16 ;
V_1673 . V_453 = true ;
V_1676 = true ;
}
if ( V_95 [ V_210 ] ) {
if ( ! ( V_191 -> V_51 & V_209 ) )
return - V_16 ;
V_1673 . V_1644 = true ;
V_1676 = true ;
}
if ( V_95 [ V_212 ] )
return - V_16 ;
if ( V_95 [ V_214 ] ) {
if ( ! ( V_191 -> V_51 & V_213 ) )
return - V_16 ;
V_1673 . V_1645 = true ;
V_1676 = true ;
}
if ( V_95 [ V_216 ] ) {
if ( ! ( V_191 -> V_51 & V_215 ) )
return - V_16 ;
V_1673 . V_1646 = true ;
V_1676 = true ;
}
if ( V_95 [ V_218 ] ) {
if ( ! ( V_191 -> V_51 & V_217 ) )
return - V_16 ;
V_1673 . V_1647 = true ;
V_1676 = true ;
}
if ( V_95 [ V_220 ] ) {
if ( ! ( V_191 -> V_51 & V_219 ) )
return - V_16 ;
V_1673 . V_1648 = true ;
V_1676 = true ;
}
if ( V_95 [ V_230 ] ) {
struct V_4 * V_223 ;
int V_221 = 0 ;
int V_134 , V_1608 , V_1680 , V_1615 ;
struct V_4 * V_1681 [ V_1682 ] ;
V_1676 = true ;
F_38 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_221 ++ ;
if ( V_221 > V_191 -> V_221 )
return - V_16 ;
V_1673 . V_1609 = F_386 ( V_221 ,
sizeof( V_1673 . V_1609 [ 0 ] ) ,
V_136 ) ;
if ( ! V_1673 . V_1609 )
return - V_137 ;
V_1673 . V_221 = V_221 ;
V_161 = 0 ;
F_38 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1683 ;
F_96 ( V_1681 , V_1684 , F_23 ( V_223 ) ,
F_24 ( V_223 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1681 [ V_1611 ] ||
! V_1681 [ V_1612 ] )
goto error;
V_1608 = F_24 ( V_1681 [ V_1612 ] ) ;
V_1680 = F_269 ( V_1608 , 8 ) ;
if ( F_24 ( V_1681 [ V_1611 ] ) != V_1680 )
goto error;
if ( V_1608 > V_191 -> V_228 ||
V_1608 < V_191 -> V_226 )
goto error;
if ( ! V_1681 [ V_1614 ] )
V_1615 = 0 ;
else
V_1615 = F_4 (
V_1681 [ V_1614 ] ) ;
if ( V_1615 > V_191 -> V_229 )
goto error;
V_1673 . V_1609 [ V_161 ] . V_1615 = V_1615 ;
V_1683 = F_387 ( V_1680 + V_1608 , V_136 ) ;
if ( ! V_1683 ) {
V_35 = - V_137 ;
goto error;
}
V_1673 . V_1609 [ V_161 ] . V_697 = V_1683 ;
memcpy ( V_1683 , F_23 ( V_1681 [ V_1611 ] ) ,
V_1680 ) ;
V_1683 += V_1680 ;
V_1673 . V_1609 [ V_161 ] . V_1613 = V_1683 ;
V_1673 . V_1609 [ V_161 ] . V_1610 = V_1608 ;
memcpy ( V_1683 ,
F_23 ( V_1681 [ V_1612 ] ) ,
V_1608 ) ;
V_161 ++ ;
}
}
if ( V_95 [ V_193 ] ) {
V_1676 = true ;
V_35 = F_376 (
V_7 , V_95 [ V_193 ] ,
& V_1673 ) ;
if ( V_35 )
goto error;
}
if ( V_95 [ V_232 ] ) {
V_1676 = true ;
V_35 = F_383 (
V_7 , V_191 , V_95 [ V_232 ] ,
& V_1673 ) ;
if ( V_35 )
goto error;
}
if ( V_1673 . V_1643 && V_1676 ) {
V_35 = - V_16 ;
goto error;
}
V_1674 = F_388 ( & V_1673 , sizeof( V_1673 ) , V_136 ) ;
if ( ! V_1674 ) {
V_35 = - V_137 ;
goto error;
}
F_385 ( V_7 ) ;
V_7 -> V_18 . V_1605 = V_1674 ;
V_1677:
if ( V_7 -> V_353 -> V_1677 &&
V_1675 != ! ! V_7 -> V_18 . V_1605 )
F_389 ( V_7 , V_7 -> V_18 . V_1605 ) ;
return 0 ;
error:
for ( V_161 = 0 ; V_161 < V_1673 . V_221 ; V_161 ++ )
F_41 ( V_1673 . V_1609 [ V_161 ] . V_697 ) ;
F_41 ( V_1673 . V_1609 ) ;
if ( V_1673 . V_190 && V_1673 . V_190 -> V_1667 )
F_381 ( V_1673 . V_190 -> V_1667 ) ;
F_41 ( V_1673 . V_190 ) ;
F_41 ( V_1673 . V_1649 ) ;
return V_35 ;
}
static int F_390 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1606 , * V_1607 , * V_1685 , * V_1686 ;
int V_161 , V_163 , V_1608 ;
struct V_1687 * V_235 ;
if ( ! V_7 -> V_236 -> V_238 )
return 0 ;
V_1686 = F_47 ( V_53 , V_240 ) ;
if ( ! V_1686 )
return - V_91 ;
for ( V_161 = 0 ; V_161 < V_7 -> V_236 -> V_238 ; V_161 ++ ) {
V_1685 = F_47 ( V_53 , V_161 + 1 ) ;
if ( ! V_1685 )
return - V_91 ;
V_235 = & V_7 -> V_236 -> V_1688 [ V_161 ] ;
if ( F_28 ( V_53 , V_1689 ,
V_235 -> V_1327 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1690 ,
V_235 -> V_1691 ) )
return - V_91 ;
V_1606 = F_47 ( V_53 ,
V_1692 ) ;
if ( ! V_1606 )
return - V_91 ;
for ( V_163 = 0 ; V_163 < V_235 -> V_221 ; V_163 ++ ) {
V_1607 = F_47 ( V_53 , V_163 + 1 ) ;
if ( ! V_1607 )
return - V_91 ;
V_1608 = V_235 -> V_1609 [ V_163 ] . V_1610 ;
if ( F_51 ( V_53 , V_1611 ,
F_269 ( V_1608 , 8 ) ,
V_235 -> V_1609 [ V_163 ] . V_697 ) ||
F_51 ( V_53 , V_1612 , V_1608 ,
V_235 -> V_1609 [ V_163 ] . V_1613 ) ||
F_28 ( V_53 , V_1614 ,
V_235 -> V_1609 [ V_163 ] . V_1615 ) )
return - V_91 ;
F_48 ( V_53 , V_1607 ) ;
}
F_48 ( V_53 , V_1606 ) ;
F_48 ( V_53 , V_1685 ) ;
}
F_48 ( V_53 , V_1686 ) ;
return 0 ;
}
static int F_391 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_31 * V_53 ;
void * V_285 ;
if ( ! V_7 -> V_18 . V_236 )
return - V_552 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1693 ) ;
if ( ! V_285 )
goto V_61;
if ( V_7 -> V_236 && F_390 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_392 ( struct V_6 * V_7 )
{
struct V_1694 * V_236 = V_7 -> V_236 ;
int V_161 , V_163 ;
struct V_1687 * V_235 ;
if ( ! V_236 )
return;
for ( V_161 = 0 ; V_161 < V_236 -> V_238 ; V_161 ++ ) {
V_235 = & V_236 -> V_1688 [ V_161 ] ;
for ( V_163 = 0 ; V_163 < V_235 -> V_221 ; V_163 ++ )
F_41 ( V_235 -> V_1609 [ V_163 ] . V_697 ) ;
F_41 ( V_235 -> V_1609 ) ;
}
F_41 ( V_236 -> V_1688 ) ;
F_41 ( V_236 ) ;
V_7 -> V_236 = NULL ;
}
static int F_393 ( struct V_6 * V_7 ,
struct V_4 * V_235 ,
struct V_1687 * V_1695 )
{
int V_35 , V_161 ;
const struct V_1696 * V_236 = V_7 -> V_18 . V_236 ;
struct V_4 * V_95 [ V_1697 ] , * V_223 ;
int V_134 , V_1608 , V_1680 , V_1615 , V_221 = 0 ;
struct V_4 * V_1681 [ V_1682 ] ;
V_35 = F_96 ( V_95 , V_1698 , F_23 ( V_235 ) ,
F_24 ( V_235 ) , V_1699 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1689 ] )
V_1695 -> V_1327 =
F_4 ( V_95 [ V_1689 ] ) ;
if ( V_1695 -> V_1327 > V_236 -> V_239 )
return - V_16 ;
if ( V_95 [ V_1690 ] )
V_1695 -> V_1691 =
F_4 ( V_95 [ V_1690 ] ) ;
if ( V_1695 -> V_1691 != V_1700 &&
V_1695 -> V_1691 != V_1701 )
return - V_16 ;
if ( ! V_95 [ V_1692 ] )
return - V_16 ;
F_38 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_221 ++ ;
if ( V_221 > V_236 -> V_221 )
return - V_16 ;
V_1695 -> V_1609 = F_386 ( V_221 , sizeof( V_1695 -> V_1609 [ 0 ] ) ,
V_136 ) ;
if ( ! V_1695 -> V_1609 )
return - V_137 ;
V_1695 -> V_221 = V_221 ;
V_161 = 0 ;
F_38 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1683 ;
F_96 ( V_1681 , V_1684 , F_23 ( V_223 ) ,
F_24 ( V_223 ) , NULL ) ;
if ( ! V_1681 [ V_1611 ] ||
! V_1681 [ V_1612 ] )
return - V_16 ;
V_1608 = F_24 ( V_1681 [ V_1612 ] ) ;
V_1680 = F_269 ( V_1608 , 8 ) ;
if ( F_24 ( V_1681 [ V_1611 ] ) != V_1680 )
return - V_16 ;
if ( V_1608 > V_236 -> V_228 ||
V_1608 < V_236 -> V_226 )
return - V_16 ;
if ( ! V_1681 [ V_1614 ] )
V_1615 = 0 ;
else
V_1615 = F_4 ( V_1681 [ V_1614 ] ) ;
if ( V_1615 > V_236 -> V_229 )
return - V_16 ;
V_1695 -> V_1609 [ V_161 ] . V_1615 = V_1615 ;
V_1683 = F_387 ( V_1680 + V_1608 , V_136 ) ;
if ( ! V_1683 )
return - V_137 ;
V_1695 -> V_1609 [ V_161 ] . V_697 = V_1683 ;
memcpy ( V_1683 , F_23 ( V_1681 [ V_1611 ] ) ,
V_1680 ) ;
V_1683 += V_1680 ;
V_1695 -> V_1609 [ V_161 ] . V_1613 = V_1683 ;
V_1695 -> V_1609 [ V_161 ] . V_1610 = V_1608 ;
memcpy ( V_1683 , F_23 ( V_1681 [ V_1612 ] ) ,
V_1608 ) ;
V_161 ++ ;
}
return 0 ;
}
static int F_394 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
const struct V_1696 * V_236 = V_7 -> V_18 . V_236 ;
struct V_1694 V_1702 = {} ;
struct V_1694 * V_1703 ;
int V_35 , V_1704 , V_238 = 0 , V_161 , V_163 ;
struct V_4 * V_235 ;
struct V_1687 * V_1705 ;
if ( ! V_7 -> V_18 . V_236 || ! V_7 -> V_353 -> V_1706 )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_240 ] ) {
F_392 ( V_7 ) ;
F_395 ( V_7 , NULL ) ;
return 0 ;
}
F_38 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_238 ++ ;
if ( V_238 > V_236 -> V_238 )
return - V_16 ;
V_1702 . V_1688 = F_386 ( V_238 , sizeof( V_1702 . V_1688 [ 0 ] ) ,
V_136 ) ;
if ( ! V_1702 . V_1688 )
return - V_137 ;
V_1702 . V_238 = V_238 ;
V_161 = 0 ;
F_38 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_393 ( V_7 , V_235 ,
& V_1702 . V_1688 [ V_161 ] ) ;
if ( V_35 )
goto error;
V_161 ++ ;
}
V_35 = F_395 ( V_7 , & V_1702 ) ;
if ( V_35 )
goto error;
V_1703 = F_388 ( & V_1702 , sizeof( V_1702 ) , V_136 ) ;
if ( ! V_1703 ) {
V_35 = - V_137 ;
goto error;
}
F_392 ( V_7 ) ;
V_7 -> V_236 = V_1703 ;
return 0 ;
error:
for ( V_161 = 0 ; V_161 < V_1702 . V_238 ; V_161 ++ ) {
V_1705 = & V_1702 . V_1688 [ V_161 ] ;
for ( V_163 = 0 ; V_163 < V_1705 -> V_221 ; V_163 ++ )
F_41 ( V_1705 -> V_1609 [ V_163 ] . V_697 ) ;
F_41 ( V_1705 -> V_1609 ) ;
}
F_41 ( V_1702 . V_1688 ) ;
return V_35 ;
}
static int F_396 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_4 * V_95 [ V_1707 ] ;
struct V_1708 V_1709 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1710 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1711 ,
F_23 ( V_30 -> V_5 [ V_1710 ] ) ,
F_24 ( V_30 -> V_5 [ V_1710 ] ) ,
V_1712 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1713 ] ) != V_1714 )
return - V_1715 ;
if ( F_24 ( V_95 [ V_1716 ] ) != V_1717 )
return - V_1715 ;
if ( F_24 ( V_95 [ V_1718 ] ) != V_1719 )
return - V_1715 ;
V_1709 . V_1720 = F_23 ( V_95 [ V_1716 ] ) ;
V_1709 . V_1721 = F_23 ( V_95 [ V_1718 ] ) ;
V_1709 . V_1722 = F_23 ( V_95 [ V_1713 ] ) ;
F_113 ( V_17 ) ;
if ( ! V_17 -> V_150 ) {
V_35 = - V_1341 ;
goto V_611;
}
if ( ! V_7 -> V_353 -> V_1723 ) {
V_35 = - V_552 ;
goto V_611;
}
V_35 = F_397 ( V_7 , V_551 , & V_1709 ) ;
V_611:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_398 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
if ( V_17 -> V_142 != V_143 &&
V_17 -> V_142 != V_145 )
return - V_16 ;
if ( V_17 -> V_1724 )
return - V_556 ;
V_17 -> V_1724 = V_30 -> V_516 ;
return 0 ;
}
static int F_399 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_31 * V_53 ;
void * V_285 ;
const T_2 * V_693 ;
T_1 V_663 ;
int V_35 ;
if ( V_17 -> V_142 != V_143 &&
V_17 -> V_142 != V_145 )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
if ( ! V_7 -> V_353 -> V_427 )
return - V_552 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1725 ) ;
if ( ! V_285 ) {
V_35 = - V_91 ;
goto V_673;
}
V_693 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_35 = F_400 ( V_7 , V_551 , V_693 , & V_663 ) ;
if ( V_35 )
goto V_673;
if ( F_104 ( V_53 , V_1560 , V_663 ,
V_598 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_673:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_401 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1726 * V_1727 , * V_1728 ;
int V_1729 ;
if ( ! ( V_7 -> V_18 . V_51 & V_431 ) )
return - V_552 ;
V_1728 = F_39 ( sizeof( * V_1728 ) , V_136 ) ;
if ( ! V_1728 )
return - V_137 ;
F_291 ( & V_7 -> V_1730 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1727 -> V_1731 == V_30 -> V_516 ) {
V_1729 = - V_767 ;
goto V_942;
}
}
V_1728 -> V_1731 = V_30 -> V_516 ;
F_402 ( & V_1728 -> V_656 , & V_7 -> V_1732 ) ;
F_293 ( & V_7 -> V_1730 ) ;
return 0 ;
V_942:
F_293 ( & V_7 -> V_1730 ) ;
F_41 ( V_1728 ) ;
return V_1729 ;
}
static int F_403 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_353 -> V_433 )
return - V_552 ;
if ( V_17 -> V_142 != V_156 )
return - V_552 ;
if ( V_17 -> V_1733 )
return 0 ;
if ( F_404 ( V_7 -> V_1734 ) )
return - V_1735 ;
V_35 = F_405 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1733 = true ;
V_7 -> V_1736 ++ ;
return 0 ;
}
static int F_406 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
if ( V_17 -> V_142 != V_156 )
return - V_552 ;
if ( ! V_7 -> V_353 -> V_1737 )
return - V_552 ;
F_407 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_408 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
struct V_1738 V_1739 = {} ;
int V_35 ;
if ( V_17 -> V_142 != V_155 )
return - V_552 ;
if ( V_17 -> V_1740 )
return - V_1741 ;
if ( F_404 ( V_7 -> V_1734 ) )
return - V_1735 ;
if ( ! V_30 -> V_5 [ V_1742 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1743 ] )
return - V_16 ;
V_1739 . V_1744 =
F_34 ( V_30 -> V_5 [ V_1742 ] ) ;
if ( ! V_1739 . V_1744 )
return - V_16 ;
V_1739 . V_1745 = F_34 ( V_30 -> V_5 [ V_1743 ] ) ;
V_35 = F_409 ( V_7 , V_17 , & V_1739 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1740 = true ;
V_7 -> V_1736 ++ ;
return 0 ;
}
static int F_410 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
if ( V_17 -> V_142 != V_155 )
return - V_552 ;
F_411 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_412 ( struct V_4 * V_1746 )
{
struct V_4 * V_45 ;
int V_47 = 0 , V_681 = 0 , V_134 ;
F_38 (attr, filter_attr, rem) {
V_47 += F_24 ( V_45 ) ;
V_681 ++ ;
}
if ( V_47 >= V_1747 )
return - V_16 ;
return V_681 ;
}
static int F_413 ( struct V_4 * V_1748 ,
struct V_1749 * V_1750 ,
bool V_277 )
{
struct V_4 * V_45 ;
int V_681 , V_134 , V_161 ;
struct V_1751 * V_1752 ;
V_681 = F_412 ( V_1748 ) ;
if ( V_681 < 0 )
return V_681 ;
F_114 ( sizeof( * V_1750 -> V_1753 ) != sizeof( * V_1750 -> V_1754 ) ) ;
V_1752 = F_386 ( V_681 , sizeof( * V_1750 -> V_1753 ) , V_136 ) ;
if ( ! V_1752 )
return - V_137 ;
V_161 = 0 ;
F_38 (attr, attr_filter, rem) {
V_1752 [ V_161 ] . V_1752 = F_388 ( F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_136 ) ;
V_1752 [ V_161 ] . V_47 = F_24 ( V_45 ) ;
V_161 ++ ;
}
if ( V_277 ) {
V_1750 -> V_1755 = V_681 ;
V_1750 -> V_1754 = V_1752 ;
} else {
V_1750 -> V_1756 = V_681 ;
V_1750 -> V_1753 = V_1752 ;
}
return 0 ;
}
static int F_414 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
struct V_4 * V_95 [ V_1757 ] , * V_1758 ;
struct V_1749 * V_1750 ;
struct V_31 * V_53 = NULL ;
void * V_285 = NULL ;
int V_35 = 0 ;
if ( V_17 -> V_142 != V_155 )
return - V_552 ;
if ( ! V_17 -> V_1740 )
return - V_1341 ;
if ( ! V_30 -> V_5 [ V_1759 ] )
return - V_16 ;
if ( V_17 -> V_650 &&
V_17 -> V_650 != V_30 -> V_516 )
return - V_1341 ;
V_35 = F_96 ( V_95 , V_1760 ,
F_23 ( V_30 -> V_5 [ V_1759 ] ) ,
F_24 ( V_30 -> V_5 [ V_1759 ] ) ,
V_1761 ) ;
if ( V_35 )
return V_35 ;
V_1750 = F_39 ( sizeof( * V_1750 ) , V_136 ) ;
if ( ! V_1750 )
return - V_137 ;
V_1750 -> V_663 = V_17 -> V_18 -> V_1762 ++ ;
if ( ! V_95 [ V_1763 ] ||
F_34 ( V_95 [ V_1763 ] ) > V_1764 ) {
V_35 = - V_16 ;
goto V_611;
}
V_1750 -> type = F_34 ( V_95 [ V_1763 ] ) ;
if ( ! V_95 [ V_1765 ] ) {
V_35 = - V_16 ;
goto V_611;
}
memcpy ( V_1750 -> V_1766 , F_23 ( V_95 [ V_1765 ] ) ,
sizeof( V_1750 -> V_1766 ) ) ;
V_1750 -> V_1767 =
F_166 ( V_95 [ V_1768 ] ) ;
if ( V_95 [ V_1769 ] ) {
V_1750 -> V_1770 =
F_24 ( V_95 [ V_1769 ] ) ;
V_1750 -> V_1771 =
F_388 ( F_23 ( V_95 [ V_1769 ] ) ,
V_1750 -> V_1770 ,
V_136 ) ;
if ( ! V_1750 -> V_1771 ) {
V_35 = - V_137 ;
goto V_611;
}
}
if ( V_95 [ V_1772 ] )
V_1750 -> V_1773 = F_4 ( V_95 [ V_1772 ] ) ;
switch ( V_1750 -> type ) {
case V_1774 :
if ( ! V_95 [ V_1775 ] ) {
V_35 = - V_16 ;
goto V_611;
}
V_1750 -> V_1776 =
F_34 ( V_95 [ V_1775 ] ) ;
V_1750 -> V_1777 =
F_166 ( V_95 [ V_1778 ] ) ;
if ( ( ! ( V_1750 -> V_1776 & V_1779 ) ) &&
V_1750 -> V_1777 ) {
V_35 = - V_16 ;
goto V_611;
}
break;
case V_1780 :
V_1750 -> V_1781 =
F_166 ( V_95 [ V_1782 ] ) ;
break;
case V_1783 :
if ( ! V_95 [ V_1784 ] ||
! V_95 [ V_1785 ] ) {
V_35 = - V_16 ;
goto V_611;
}
V_1750 -> V_1786 =
F_34 ( V_95 [ V_1784 ] ) ;
V_1750 -> V_1787 =
F_34 ( V_95 [ V_1785 ] ) ;
memcpy ( V_1750 -> V_1788 . V_693 ,
F_23 ( V_95 [ V_1789 ] ) ,
sizeof( V_1750 -> V_1788 . V_693 ) ) ;
if ( V_1750 -> V_1773 ) {
V_35 = - V_16 ;
goto V_611;
}
break;
default:
V_35 = - V_16 ;
goto V_611;
}
if ( V_95 [ V_1790 ] ) {
struct V_4 * V_1791 [ V_1792 ] ;
V_35 = F_96 ( V_1791 , V_1793 ,
F_23 ( V_95 [ V_1790 ] ) ,
F_24 ( V_95 [ V_1790 ] ) , NULL ) ;
if ( V_35 )
goto V_611;
V_1750 -> V_1794 =
F_166 ( V_1791 [ V_1795 ] ) ;
if ( V_1791 [ V_1796 ] ) {
if ( V_1791 [ V_1797 ] ||
! V_1791 [ V_1798 ] ) {
V_35 = - V_16 ;
goto V_611;
}
V_1750 -> V_1799 =
F_24 ( V_1791 [ V_1796 ] ) ;
V_1750 -> V_1800 =
F_388 ( F_23 ( V_1791 [ V_1796 ] ) ,
V_1750 -> V_1799 , V_136 ) ;
if ( ! V_1750 -> V_1800 ) {
V_35 = - V_137 ;
goto V_611;
}
V_1750 -> V_1801 =
F_34 ( V_1791 [ V_1798 ] ) ;
} else {
struct V_4 * V_45 , * V_1802 =
V_1791 [ V_1797 ] ;
int V_681 , V_134 , V_161 = 0 ;
if ( ! V_1802 ) {
V_35 = - V_16 ;
goto V_611;
}
V_681 = F_144 ( V_1802 ) ;
if ( V_681 <= 0 ) {
V_35 = - V_16 ;
goto V_611;
}
V_1750 -> V_1803 = V_681 ;
V_1750 -> V_1804 =
F_39 ( sizeof( * V_1750 -> V_1804 ) * V_681 ,
V_136 ) ;
if ( ! V_1750 -> V_1804 ) {
V_35 = - V_137 ;
goto V_611;
}
F_38 (attr, mac_attr, rem)
memcpy ( V_1750 -> V_1804 [ V_161 ++ ] . V_693 , F_23 ( V_45 ) ,
sizeof( * V_1750 -> V_1804 ) ) ;
}
}
if ( V_95 [ V_1805 ] ) {
V_35 = F_413 ( V_95 [ V_1805 ] ,
V_1750 , true ) ;
if ( V_35 )
goto V_611;
}
if ( V_95 [ V_1806 ] ) {
V_35 = F_413 ( V_95 [ V_1806 ] ,
V_1750 , false ) ;
if ( V_35 )
goto V_611;
}
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 ) {
V_35 = - V_137 ;
goto V_611;
}
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1807 ) ;
if ( F_59 ( ! V_285 ) ) {
V_35 = - V_137 ;
goto V_611;
}
V_35 = F_415 ( V_7 , V_17 , V_1750 ) ;
V_611:
if ( V_35 < 0 ) {
F_416 ( V_1750 ) ;
F_75 ( V_53 ) ;
return V_35 ;
}
if ( F_104 ( V_53 , V_1560 , V_1750 -> V_663 ,
V_598 ) )
goto V_61;
V_1758 = F_47 ( V_53 , V_1759 ) ;
if ( ! V_1758 )
goto V_61;
if ( F_56 ( V_53 , V_1808 ,
V_1750 -> V_1809 ) )
goto V_61;
F_48 ( V_53 , V_1758 ) ;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_417 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
T_1 V_663 ;
if ( V_17 -> V_142 != V_155 )
return - V_552 ;
if ( ! V_17 -> V_1740 )
return - V_1341 ;
if ( ! V_30 -> V_5 [ V_1560 ] )
return - V_16 ;
if ( V_17 -> V_650 &&
V_17 -> V_650 != V_30 -> V_516 )
return - V_1341 ;
V_663 = F_5 ( V_30 -> V_5 [ V_1560 ] ) ;
F_418 ( V_7 , V_17 , V_663 ) ;
return 0 ;
}
static int F_419 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
struct V_1738 V_1739 = {} ;
V_22 V_562 = 0 ;
if ( V_17 -> V_142 != V_155 )
return - V_552 ;
if ( ! V_17 -> V_1740 )
return - V_1341 ;
if ( V_30 -> V_5 [ V_1742 ] ) {
V_1739 . V_1744 =
F_34 ( V_30 -> V_5 [ V_1742 ] ) ;
if ( V_1739 . V_1744 <= 1 || V_1739 . V_1744 == 255 )
return - V_16 ;
V_562 |= V_1810 ;
}
if ( V_30 -> V_5 [ V_1743 ] ) {
V_1739 . V_1745 = F_34 ( V_30 -> V_5 [ V_1743 ] ) ;
V_562 |= V_1811 ;
}
if ( ! V_562 )
return - V_16 ;
return F_420 ( V_7 , V_17 , & V_1739 , V_562 ) ;
}
void F_421 ( struct V_1 * V_17 ,
struct V_1812 * V_1638 , T_12 V_1505 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_4 * V_1813 , * V_1814 , * V_1815 ;
struct V_31 * V_53 ;
void * V_285 ;
if ( F_59 ( ! V_1638 -> V_1816 || ! V_1638 -> V_1817 || ! V_1638 -> V_693 ) )
return;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1818 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_61;
if ( F_104 ( V_53 , V_1560 , V_1638 -> V_663 ,
V_598 ) ||
F_51 ( V_53 , V_559 , V_599 , V_1638 -> V_693 ) )
goto V_61;
V_1813 = F_47 ( V_53 , V_1819 ) ;
if ( ! V_1813 )
goto V_61;
V_1814 = F_47 ( V_53 , V_1820 ) ;
if ( ! V_1814 )
goto V_61;
if ( F_56 ( V_53 , V_1808 , V_1638 -> V_1816 ) )
goto V_61;
F_48 ( V_53 , V_1814 ) ;
V_1815 = F_47 ( V_53 , V_1821 ) ;
if ( ! V_1815 )
goto V_61;
if ( F_56 ( V_53 , V_1763 , V_1638 -> type ) ||
F_56 ( V_53 , V_1808 , V_1638 -> V_1817 ) )
goto V_61;
if ( V_1638 -> V_30 && V_1638 -> V_1822 &&
F_51 ( V_53 , V_1769 , V_1638 -> V_1822 ,
V_1638 -> V_30 ) )
goto V_61;
F_48 ( V_53 , V_1815 ) ;
F_48 ( V_53 , V_1813 ) ;
F_66 ( V_53 , V_285 ) ;
if ( ! V_17 -> V_650 )
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_1823 , V_1505 ) ;
else
F_422 ( F_7 ( & V_7 -> V_18 ) , V_53 ,
V_17 -> V_650 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_423 ( struct V_1 * V_17 ,
T_2 V_1816 ,
enum V_1824 V_1530 ,
T_1 V_663 , T_12 V_1505 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_1758 ;
void * V_285 ;
if ( F_59 ( ! V_1816 ) )
return;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1825 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_61;
if ( F_104 ( V_53 , V_1560 , V_663 ,
V_598 ) )
goto V_61;
V_1758 = F_47 ( V_53 , V_1759 ) ;
if ( ! V_1758 )
goto V_61;
if ( F_56 ( V_53 , V_1808 , V_1816 ) ||
F_56 ( V_53 , V_1826 , V_1530 ) )
goto V_61;
F_48 ( V_53 , V_1758 ) ;
F_66 ( V_53 , V_285 ) ;
if ( ! V_17 -> V_650 )
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) ,
V_53 , 0 , V_1823 , V_1505 ) ;
else
F_422 ( F_7 ( & V_7 -> V_18 ) , V_53 ,
V_17 -> V_650 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static int F_424 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_285 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , V_30 -> V_516 , V_30 -> V_517 , 0 ,
V_1827 ) ;
if ( ! V_285 )
goto V_61;
if ( F_28 ( V_53 , V_1828 ,
V_1829 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_318 ( V_53 ) ;
return - V_91 ;
}
static int F_425 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1830 V_1831 ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
if ( ! V_7 -> V_353 -> V_1832 )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_1833 ] ||
! F_22 ( V_30 -> V_5 [ V_742 ] ) )
return - V_16 ;
memset ( & V_1831 , 0 , sizeof( V_1831 ) ) ;
V_1831 . V_1834 = F_78 ( V_30 -> V_5 [ V_1833 ] ) ;
V_1831 . V_1189 = F_23 ( V_30 -> V_5 [ V_742 ] ) ;
V_1831 . V_1190 = F_24 ( V_30 -> V_5 [ V_742 ] ) ;
return F_426 ( V_7 , V_551 , & V_1831 ) ;
}
static int F_427 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
enum V_1835 V_1449 = V_1836 ;
T_3 V_1283 ;
int V_508 ;
if ( ! V_7 -> V_353 -> V_439 )
return - V_552 ;
if ( F_59 ( ! V_7 -> V_353 -> V_441 ) )
return - V_16 ;
if ( V_7 -> V_1837 )
return - V_556 ;
if ( V_30 -> V_5 [ V_1838 ] )
V_1449 = F_78 ( V_30 -> V_5 [ V_1838 ] ) ;
if ( V_1449 >= V_1839 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1840 ] )
return - V_16 ;
V_1283 =
F_78 ( V_30 -> V_5 [ V_1840 ] ) ;
if ( V_1283 > V_1841 )
return - V_1715 ;
V_508 = F_428 ( V_7 , V_17 , V_1449 , V_1283 ) ;
if ( ! V_508 )
V_7 -> V_1837 = V_30 -> V_516 ;
return V_508 ;
}
static int F_429 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
if ( ! V_7 -> V_353 -> V_441 )
return - V_552 ;
if ( V_7 -> V_1837 ) {
V_7 -> V_1837 = 0 ;
F_430 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_431 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_161 , V_35 ;
V_22 V_1842 , V_1509 ;
if ( ! V_7 -> V_18 . V_486 )
return - V_552 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1506 ] ||
! V_30 -> V_5 [ V_1508 ] )
return - V_16 ;
V_1842 = F_4 ( V_30 -> V_5 [ V_1506 ] ) ;
V_1509 = F_4 ( V_30 -> V_5 [ V_1508 ] ) ;
for ( V_161 = 0 ; V_161 < V_7 -> V_18 . V_482 ; V_161 ++ ) {
const struct V_1843 * V_1844 ;
void * V_141 = NULL ;
int V_47 = 0 ;
V_1844 = & V_7 -> V_18 . V_486 [ V_161 ] ;
if ( V_1844 -> V_30 . V_1507 != V_1842 || V_1844 -> V_30 . V_1509 != V_1509 )
continue;
if ( V_1844 -> V_51 & ( V_1845 |
V_1846 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1844 -> V_51 & V_1846 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1844 -> V_51 & V_1847 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_566 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1733 )
return - V_566 ;
}
if ( ! V_1844 -> V_1848 )
return - V_552 ;
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_485 ] ) {
V_141 = F_23 ( V_30 -> V_5 [ V_485 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_485 ] ) ;
}
V_7 -> V_1518 = V_30 ;
V_35 = V_7 -> V_18 . V_486 [ V_161 ] . V_1848 ( & V_7 -> V_18 , V_17 ,
V_141 , V_47 ) ;
V_7 -> V_1518 = NULL ;
return V_35 ;
}
return - V_552 ;
}
static int F_432 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_6 * * V_7 ,
struct V_1 * * V_17 )
{
V_22 V_1842 , V_1509 ;
unsigned int V_161 ;
int V_1849 = - 1 ;
int V_35 ;
void * V_141 = NULL ;
unsigned int V_1520 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
struct V_18 * V_18 = F_19 ( V_34 -> args [ 0 ] - 1 ) ;
struct V_1 * V_24 ;
if ( ! V_18 ) {
V_35 = - V_23 ;
goto V_43;
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
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_43;
if ( ! V_38 . V_40 [ V_1506 ] ||
! V_38 . V_40 [ V_1508 ] ) {
V_35 = - V_16 ;
goto V_43;
}
* V_17 = F_1 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( * V_17 ) )
* V_17 = NULL ;
* V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( * V_7 ) ) {
V_35 = F_18 ( * V_7 ) ;
goto V_43;
}
V_1842 = F_4 ( V_38 . V_40 [ V_1506 ] ) ;
V_1509 = F_4 ( V_38 . V_40 [ V_1508 ] ) ;
for ( V_161 = 0 ; V_161 < ( * V_7 ) -> V_18 . V_482 ; V_161 ++ ) {
const struct V_1843 * V_1844 ;
V_1844 = & ( * V_7 ) -> V_18 . V_486 [ V_161 ] ;
if ( V_1844 -> V_30 . V_1507 != V_1842 || V_1844 -> V_30 . V_1509 != V_1509 )
continue;
if ( ! V_1844 -> V_1850 ) {
V_35 = - V_552 ;
goto V_43;
}
V_1849 = V_161 ;
break;
}
if ( V_1849 < 0 ) {
V_35 = - V_552 ;
goto V_43;
}
if ( V_38 . V_40 [ V_485 ] ) {
V_141 = F_23 ( V_38 . V_40 [ V_485 ] ) ;
V_1520 = F_24 ( V_38 . V_40 [ V_485 ] ) ;
}
V_34 -> args [ 0 ] = ( * V_7 ) -> V_14 + 1 ;
V_34 -> args [ 1 ] = * V_17 ? ( * V_17 ) -> V_21 + 1 : 0 ;
V_34 -> args [ 2 ] = V_1849 ;
V_34 -> args [ 3 ] = ( unsigned long ) V_141 ;
V_34 -> args [ 4 ] = V_1520 ;
return 0 ;
V_43:
F_20 () ;
return V_35 ;
}
static int F_433 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
unsigned int V_1849 ;
const struct V_1843 * V_1844 ;
void * V_141 ;
int V_1520 ;
int V_35 ;
struct V_4 * V_1851 ;
V_35 = F_432 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
V_1849 = V_34 -> args [ 2 ] ;
V_141 = ( void * ) V_34 -> args [ 3 ] ;
V_1520 = V_34 -> args [ 4 ] ;
V_1844 = & V_7 -> V_18 . V_486 [ V_1849 ] ;
if ( V_1844 -> V_51 & ( V_1845 |
V_1846 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1844 -> V_51 & V_1846 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1844 -> V_51 & V_1847 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_566 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1733 )
return - V_566 ;
}
}
while ( 1 ) {
void * V_285 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_512 , V_513 ,
V_1512 ) ;
if ( ! V_285 )
break;
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) ||
( V_17 && F_104 ( V_32 , V_12 ,
V_13 ( V_17 ) ,
V_598 ) ) ) {
F_67 ( V_32 , V_285 ) ;
break;
}
V_1851 = F_47 ( V_32 , V_485 ) ;
if ( ! V_1851 ) {
F_67 ( V_32 , V_285 ) ;
break;
}
V_35 = V_1844 -> V_1850 ( & V_7 -> V_18 , V_17 , V_32 , V_141 , V_1520 ,
( unsigned long * ) & V_34 -> args [ 5 ] ) ;
F_48 ( V_32 , V_1851 ) ;
if ( V_35 == - V_91 || V_35 == - V_671 ) {
F_67 ( V_32 , V_285 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_285 ) ;
goto V_611;
}
F_66 ( V_32 , V_285 ) ;
}
V_35 = V_32 -> V_47 ;
V_611:
F_20 () ;
return V_35 ;
}
struct V_31 * F_434 ( struct V_18 * V_18 ,
enum V_282 V_52 ,
enum V_823 V_45 ,
int V_1504 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1518 ) )
return NULL ;
return F_317 ( V_7 , NULL , V_1504 ,
V_7 -> V_1518 -> V_516 ,
V_7 -> V_1518 -> V_517 ,
V_52 , V_45 , NULL , V_136 ) ;
}
int F_435 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_285 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_141 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1518 ) ) {
F_318 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_141 ) ;
F_66 ( V_32 , V_285 ) ;
return F_76 ( V_32 , V_7 -> V_1518 ) ;
}
static int F_436 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_1852 * V_1853 = NULL ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
T_2 * V_46 , V_47 , V_1854 , V_1855 , V_1856 ;
int V_508 ;
if ( ! V_7 -> V_353 -> V_446 )
return - V_552 ;
if ( V_30 -> V_5 [ V_1857 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1857 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1857 ] ) ;
if ( V_47 % 2 || V_47 < V_1858 ||
V_47 > V_1859 )
return - V_16 ;
V_1853 = F_39 ( sizeof( struct V_1852 ) , V_136 ) ;
if ( ! V_1853 )
return - V_137 ;
V_1854 = ( V_47 - V_1858 ) >> 1 ;
if ( V_1854 ) {
V_1855 = V_1854 *
sizeof( struct V_1860 ) ;
memcpy ( V_1853 -> V_1861 , V_46 , V_1855 ) ;
V_1853 -> V_1854 = V_1854 ;
for ( V_1856 = 0 ; V_1856 < V_1854 ; V_1856 ++ ) {
if ( V_1853 -> V_1861 [ V_1856 ] . V_1862 > 7 ) {
F_41 ( V_1853 ) ;
return - V_16 ;
}
}
V_46 += V_1855 ;
}
memcpy ( V_1853 -> V_1862 , V_46 , V_1858 ) ;
}
F_113 ( V_551 -> V_28 ) ;
V_508 = F_42 ( V_551 -> V_28 ) ;
if ( ! V_508 )
V_508 = F_437 ( V_7 , V_551 , V_1853 ) ;
F_115 ( V_551 -> V_28 ) ;
F_41 ( V_1853 ) ;
return V_508 ;
}
static int F_438 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
const T_2 * V_1547 ;
T_2 V_1863 , V_1862 ;
T_3 V_1864 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_293 & V_448 ) )
return - V_552 ;
if ( ! V_30 -> V_5 [ V_1865 ] || ! V_30 -> V_5 [ V_559 ] ||
! V_30 -> V_5 [ V_1866 ] )
return - V_16 ;
V_1863 = F_34 ( V_30 -> V_5 [ V_1865 ] ) ;
if ( V_1863 >= V_926 )
return - V_16 ;
V_1862 = F_34 ( V_30 -> V_5 [ V_1866 ] ) ;
if ( V_1862 >= V_1867 )
return - V_16 ;
if ( V_1863 >= V_1868 ) {
return - V_16 ;
}
V_1547 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
if ( V_30 -> V_5 [ V_1869 ] ) {
V_1864 =
F_78 ( V_30 -> V_5 [ V_1869 ] ) ;
if ( ! V_1864 )
return - V_16 ;
}
F_113 ( V_17 ) ;
switch ( V_17 -> V_142 ) {
case V_148 :
case V_149 :
if ( V_17 -> V_150 )
break;
V_35 = - V_1341 ;
goto V_611;
default:
V_35 = - V_552 ;
goto V_611;
}
V_35 = F_439 ( V_7 , V_551 , V_1863 , V_1547 , V_1862 , V_1864 ) ;
V_611:
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_440 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
const T_2 * V_1547 ;
T_2 V_1863 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1865 ] || ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_1863 = F_34 ( V_30 -> V_5 [ V_1865 ] ) ;
V_1547 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_441 ( V_7 , V_551 , V_1863 , V_1547 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_442 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_531 V_532 = {} ;
const T_2 * V_693 ;
T_2 V_1870 ;
int V_35 ;
if ( ! V_7 -> V_353 -> V_1871 ||
! ( V_7 -> V_18 . V_293 & V_1872 ) )
return - V_552 ;
switch ( V_551 -> V_28 -> V_142 ) {
case V_148 :
case V_149 :
break;
default:
return - V_552 ;
}
if ( ! V_30 -> V_5 [ V_559 ] ||
! V_30 -> V_5 [ V_1873 ] )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_532 ) ;
if ( V_35 )
return V_35 ;
if ( V_532 . V_55 -> V_292 == V_1874 &&
V_532 . V_535 != V_536 &&
V_532 . V_535 != V_591 )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_532 ,
V_17 -> V_142 ) )
return - V_16 ;
if ( F_281 ( V_17 -> V_18 , & V_532 , V_17 -> V_142 ) )
return - V_16 ;
V_693 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
V_1870 = F_34 ( V_30 -> V_5 [ V_1873 ] ) ;
F_113 ( V_17 ) ;
V_35 = F_443 ( V_7 , V_551 , V_693 , V_1870 , & V_532 ) ;
F_115 ( V_17 ) ;
return V_35 ;
}
static int F_444 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_515 [ 0 ] ;
struct V_25 * V_551 = V_30 -> V_515 [ 1 ] ;
struct V_1 * V_17 = V_551 -> V_28 ;
const T_2 * V_693 ;
if ( ! V_7 -> V_353 -> V_1871 ||
! V_7 -> V_353 -> V_1875 ||
! ( V_7 -> V_18 . V_293 & V_1872 ) )
return - V_552 ;
switch ( V_551 -> V_28 -> V_142 ) {
case V_148 :
case V_149 :
break;
default:
return - V_552 ;
}
if ( ! V_30 -> V_5 [ V_559 ] )
return - V_16 ;
V_693 = F_23 ( V_30 -> V_5 [ V_559 ] ) ;
F_113 ( V_17 ) ;
F_445 ( V_7 , V_551 , V_693 ) ;
F_115 ( V_17 ) ;
return 0 ;
}
static int F_446 ( const struct V_1876 * V_353 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_551 ;
bool V_1877 = V_353 -> V_1878 & V_1879 ;
if ( V_1877 )
F_14 () ;
if ( V_353 -> V_1878 & V_1880 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1877 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_515 [ 0 ] = V_7 ;
} else if ( V_353 -> V_1878 & V_1881 ||
V_353 -> V_1878 & V_1882 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1877 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_551 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_353 -> V_1878 & V_1881 ) {
if ( ! V_551 ) {
if ( V_1877 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_515 [ 1 ] = V_551 ;
} else {
V_30 -> V_515 [ 1 ] = V_17 ;
}
if ( V_551 ) {
if ( V_353 -> V_1878 & V_1883 &&
! F_91 ( V_551 ) ) {
if ( V_1877 )
F_20 () ;
return - V_566 ;
}
F_265 ( V_551 ) ;
} else if ( V_353 -> V_1878 & V_1883 ) {
if ( V_17 -> V_142 == V_156 &&
! V_17 -> V_1733 ) {
if ( V_1877 )
F_20 () ;
return - V_566 ;
}
if ( V_17 -> V_142 == V_155 &&
! V_17 -> V_1740 ) {
if ( V_1877 )
F_20 () ;
return - V_566 ;
}
}
V_30 -> V_515 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_447 ( const struct V_1876 * V_353 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_515 [ 1 ] ) {
if ( V_353 -> V_1878 & V_1882 ) {
struct V_1 * V_17 = V_30 -> V_515 [ 1 ] ;
if ( V_17 -> V_19 )
F_187 ( V_17 -> V_19 ) ;
} else {
F_187 ( V_30 -> V_515 [ 1 ] ) ;
}
}
if ( V_353 -> V_1878 & V_1879 )
F_20 () ;
if ( V_353 -> V_1878 & V_1884 ) {
struct V_1885 * V_36 = F_448 ( V_32 ) ;
memset ( F_449 ( V_36 ) , 0 , F_450 ( V_36 ) ) ;
}
}
void F_451 ( struct V_6 * V_7 ,
enum V_282 V_52 )
{
struct V_31 * V_53 ;
struct V_283 V_284 = {} ;
F_59 ( V_52 != V_297 &&
V_52 != V_1886 ) ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_284 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1887 , V_136 ) ;
}
void F_128 ( struct V_6 * V_7 ,
struct V_1 * V_17 ,
enum V_282 V_52 )
{
struct V_31 * V_53 ;
F_59 ( V_52 != V_594 &&
V_52 != V_595 ) ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
if ( F_103 ( V_53 , 0 , 0 , 0 , V_7 , V_17 ,
V_52 == V_595 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1887 , V_136 ) ;
}
static int F_452 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1269 * V_1465 = V_7 -> V_1273 ;
struct V_4 * V_1255 ;
int V_161 ;
if ( F_59 ( ! V_1465 ) )
return 0 ;
V_1255 = F_47 ( V_53 , V_1277 ) ;
if ( ! V_1255 )
goto V_61;
for ( V_161 = 0 ; V_161 < V_1465 -> V_1271 ; V_161 ++ ) {
if ( F_51 ( V_53 , V_161 , V_1465 -> V_1278 [ V_161 ] . V_604 , V_1465 -> V_1278 [ V_161 ] . V_606 ) )
goto V_61;
}
F_48 ( V_53 , V_1255 ) ;
V_1255 = F_47 ( V_53 , V_1276 ) ;
if ( ! V_1255 )
goto V_61;
for ( V_161 = 0 ; V_161 < V_1465 -> V_368 ; V_161 ++ ) {
if ( F_28 ( V_53 , V_161 , V_1465 -> V_369 [ V_161 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1255 ) ;
if ( V_1465 -> V_1189 &&
F_51 ( V_53 , V_742 , V_1465 -> V_1190 , V_1465 -> V_1189 ) )
goto V_61;
if ( V_1465 -> V_51 &&
F_28 ( V_53 , V_1286 , V_1465 -> V_51 ) )
goto V_61;
if ( V_1465 -> V_30 . V_1888 &&
( F_104 ( V_53 , V_1889 ,
V_1465 -> V_30 . V_1888 , V_1373 ) ||
F_51 ( V_53 , V_1890 , V_599 ,
V_1465 -> V_30 . V_1891 ) ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_453 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_285 ;
V_285 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_285 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_61;
F_452 ( V_53 , V_7 ) ;
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
static int
F_454 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_285 ;
V_285 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_285 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return 0 ;
V_61:
F_67 ( V_53 , V_285 ) ;
return - V_507 ;
}
void F_264 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
if ( F_453 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1892 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1893 , V_136 ) ;
}
struct V_31 * F_455 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1894 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return NULL ;
if ( F_453 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1894 ? V_1895 :
V_1365 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_456 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1893 , V_136 ) ;
}
void F_457 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
if ( F_454 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1896 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1893 , V_136 ) ;
}
void F_275 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
if ( F_454 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1893 , V_136 ) ;
}
static bool F_458 ( struct V_31 * V_53 ,
struct V_1897 * V_1270 )
{
if ( F_56 ( V_53 , V_1898 , V_1270 -> V_1548 ) )
goto V_61;
if ( V_1270 -> V_1203 [ 0 ] == '0' && V_1270 -> V_1203 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1899 ,
V_1900 ) )
goto V_61;
} else if ( V_1270 -> V_1203 [ 0 ] == '9' && V_1270 -> V_1203 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1899 ,
V_1901 ) )
goto V_61;
} else if ( ( V_1270 -> V_1203 [ 0 ] == '9' && V_1270 -> V_1203 [ 1 ] == '8' ) ||
V_1270 -> V_1902 ) {
if ( F_56 ( V_53 , V_1899 ,
V_1903 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1899 ,
V_1904 ) ||
F_60 ( V_53 , V_1091 ,
V_1270 -> V_1203 ) )
goto V_61;
}
if ( V_1270 -> V_14 != V_1905 ) {
struct V_18 * V_18 = F_19 ( V_1270 -> V_14 ) ;
if ( V_18 &&
F_28 ( V_53 , V_26 , V_1270 -> V_14 ) )
goto V_61;
if ( V_18 &&
V_18 -> V_492 & V_493 &&
F_29 ( V_53 , V_494 ) )
goto V_61;
}
return true ;
V_61:
return false ;
}
void F_459 ( enum V_282 V_1906 ,
struct V_1897 * V_1270 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1906 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_458 ( V_53 , V_1270 ) == false )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_240 () ;
F_460 ( & V_38 , V_53 , 0 ,
V_1907 , V_1908 ) ;
F_242 () ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
static void F_461 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1571 , T_11 V_47 ,
enum V_282 V_52 , T_12 V_1505 ,
int V_981 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1568 , V_47 , V_1571 ) )
goto V_61;
if ( V_981 >= 0 ) {
struct V_4 * V_1909 =
F_47 ( V_53 , V_978 ) ;
if ( ! V_1909 )
goto V_61;
if ( F_56 ( V_53 , V_980 ,
V_981 ) )
goto V_61;
F_48 ( V_53 , V_1909 ) ;
}
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_462 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1571 ,
T_11 V_47 , T_12 V_1505 )
{
F_461 ( V_7 , V_19 , V_1571 , V_47 ,
V_763 , V_1505 , - 1 ) ;
}
void F_463 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1571 ,
T_11 V_47 , T_12 V_1505 , int V_981 )
{
F_461 ( V_7 , V_19 , V_1571 , V_47 ,
V_1911 , V_1505 , V_981 ) ;
}
void F_464 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1571 ,
T_11 V_47 , T_12 V_1505 )
{
F_461 ( V_7 , V_19 , V_1571 , V_47 ,
V_1912 , V_1505 , - 1 ) ;
}
void F_465 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1571 ,
T_11 V_47 , T_12 V_1505 )
{
F_461 ( V_7 , V_19 , V_1571 , V_47 ,
V_1913 , V_1505 , - 1 ) ;
}
void F_466 ( struct V_25 * V_551 , const T_2 * V_1571 ,
T_11 V_47 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1914 * V_1915 = ( void * ) V_1571 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_467 ( V_1915 -> V_1916 ) )
V_52 = V_1917 ;
else
V_52 = V_1918 ;
F_468 ( V_551 , V_1571 , V_47 ) ;
F_461 ( V_7 , V_551 , V_1571 , V_47 , V_52 , V_1908 , - 1 ) ;
}
static void F_469 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_693 , T_12 V_1505 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1919 ) ||
F_51 ( V_53 , V_559 , V_599 , V_693 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_470 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_693 ,
T_12 V_1505 )
{
F_469 ( V_7 , V_19 , V_763 ,
V_693 , V_1505 ) ;
}
void F_471 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_693 ,
T_12 V_1505 )
{
F_469 ( V_7 , V_19 , V_1911 ,
V_693 , V_1505 ) ;
}
void F_472 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_558 ,
const T_2 * V_1920 , T_11 V_1921 ,
const T_2 * V_1922 , T_11 V_1923 ,
int V_1924 , T_12 V_1505 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_452 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_558 && F_51 ( V_53 , V_559 , V_599 , V_558 ) ) ||
F_55 ( V_53 , V_1550 ,
V_1924 < 0 ? V_1925 :
V_1924 ) ||
( V_1924 < 0 && F_29 ( V_53 , V_1919 ) ) ||
( V_1920 &&
F_51 ( V_53 , V_1926 , V_1921 , V_1920 ) ) ||
( V_1922 &&
F_51 ( V_53 , V_1927 , V_1923 , V_1922 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_473 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_558 ,
const T_2 * V_1920 , T_11 V_1921 ,
const T_2 * V_1922 , T_11 V_1923 , T_12 V_1505 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1928 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_558 ) ||
( V_1920 &&
F_51 ( V_53 , V_1926 , V_1921 , V_1920 ) ) ||
( V_1922 &&
F_51 ( V_53 , V_1927 , V_1923 , V_1922 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_474 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1530 ,
const T_2 * V_1189 , T_11 V_1190 , bool V_1929 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_454 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1929 && V_1530 &&
F_55 ( V_53 , V_1030 , V_1530 ) ) ||
( V_1929 &&
F_29 ( V_53 , V_1930 ) ) ||
( V_1189 && F_51 ( V_53 , V_742 , V_1190 , V_1189 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_136 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_475 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_558 ,
T_12 V_1505 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1931 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_558 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_476 ( struct V_25 * V_551 , const T_2 * V_693 ,
const T_2 * V_1189 , T_2 V_1190 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
if ( F_59 ( V_17 -> V_142 != V_146 ) )
return;
F_477 ( V_551 , V_693 ) ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1932 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_693 ) ||
( V_1190 && V_1189 &&
F_51 ( V_53 , V_742 , V_1190 , V_1189 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_478 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_693 ,
enum V_1933 V_1934 , int V_1935 ,
const T_2 * V_1936 , T_12 V_1505 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1937 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_693 && F_51 ( V_53 , V_559 , V_599 , V_693 ) ) ||
F_28 ( V_53 , V_127 , V_1934 ) ||
( V_1935 != - 1 &&
F_56 ( V_53 , V_123 , V_1935 ) ) ||
( V_1936 && F_51 ( V_53 , V_122 , 6 , V_1936 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_479 ( struct V_18 * V_18 ,
struct V_54 * V_1938 ,
struct V_54 * V_1939 )
{
struct V_31 * V_53 ;
void * V_285 ;
struct V_4 * V_289 ;
V_53 = F_74 ( V_612 , V_1908 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1940 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_238 ( V_18 ) ) )
goto V_61;
V_289 = F_47 ( V_53 , V_1941 ) ;
if ( ! V_289 )
goto V_61;
if ( F_27 ( V_53 , V_1938 , false ) )
goto V_61;
F_48 ( V_53 , V_289 ) ;
V_289 = F_47 ( V_53 , V_1942 ) ;
if ( ! V_289 )
goto V_61;
if ( F_27 ( V_53 , V_1939 , false ) )
goto V_61;
F_48 ( V_53 , V_289 ) ;
F_66 ( V_53 , V_285 ) ;
F_240 () ;
F_460 ( & V_38 , V_53 , 0 ,
V_1907 , V_1908 ) ;
F_242 () ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
static void F_480 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_663 ,
struct V_54 * V_55 ,
unsigned int V_1283 , T_12 V_1505 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) ||
F_28 ( V_53 , V_534 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_539 ,
V_542 ) ||
F_104 ( V_53 , V_1560 , V_663 ,
V_598 ) )
goto V_61;
if ( V_52 == V_1559 &&
F_28 ( V_53 , V_1557 , V_1283 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_481 ( struct V_1 * V_17 , T_1 V_663 ,
struct V_54 * V_55 ,
unsigned int V_1283 , T_12 V_1505 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_482 ( V_17 , V_663 , V_55 , V_1283 ) ;
F_480 ( V_1559 ,
V_7 , V_17 , V_663 , V_55 ,
V_1283 , V_1505 ) ;
}
void F_483 ( struct V_1 * V_17 , T_1 V_663 ,
struct V_54 * V_55 ,
T_12 V_1505 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_484 ( V_17 , V_663 , V_55 ) ;
F_480 ( V_1943 ,
V_7 , V_17 , V_663 , V_55 , 0 , V_1505 ) ;
}
void F_485 ( struct V_25 * V_551 , const T_2 * V_665 ,
struct V_848 * V_849 , T_12 V_1505 )
{
struct V_18 * V_18 = V_551 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_486 ( V_551 , V_665 , V_849 ) ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
if ( F_176 ( V_53 , V_944 , 0 , 0 , 0 ,
V_7 , V_551 , V_665 , V_849 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
}
void F_487 ( struct V_25 * V_551 , const T_2 * V_665 ,
struct V_848 * V_849 , T_12 V_1505 )
{
struct V_18 * V_18 = V_551 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_848 V_1944 = {} ;
if ( ! V_849 )
V_849 = & V_1944 ;
F_488 ( V_551 , V_665 ) ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
if ( F_176 ( V_53 , V_1945 , 0 , 0 , 0 ,
V_7 , V_551 , V_665 , V_849 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
}
void F_489 ( struct V_25 * V_551 , const T_2 * V_665 ,
enum V_1946 V_1530 ,
T_12 V_1505 )
{
struct V_18 * V_18 = V_551 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_1947 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1948 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_665 ) ||
F_28 ( V_53 , V_1949 , V_1530 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
static bool F_490 ( struct V_25 * V_551 , T_2 V_52 ,
const T_2 * V_693 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
V_22 V_1731 = F_491 ( V_17 -> V_1724 ) ;
if ( ! V_1731 )
return false ;
V_53 = F_74 ( 100 , V_1505 ) ;
if ( ! V_53 )
return true ;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_693 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_422 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1731 ) ;
return true ;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_492 ( struct V_25 * V_551 ,
const T_2 * V_693 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
bool V_508 ;
F_493 ( V_551 , V_693 ) ;
if ( F_59 ( V_17 -> V_142 != V_143 &&
V_17 -> V_142 != V_145 ) ) {
F_494 ( false ) ;
return false ;
}
V_508 = F_490 ( V_551 , V_1950 ,
V_693 , V_1505 ) ;
F_494 ( V_508 ) ;
return V_508 ;
}
bool F_495 ( struct V_25 * V_551 ,
const T_2 * V_693 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
bool V_508 ;
F_496 ( V_551 , V_693 ) ;
if ( F_59 ( V_17 -> V_142 != V_143 &&
V_17 -> V_142 != V_145 &&
V_17 -> V_142 != V_144 ) ) {
F_494 ( false ) ;
return false ;
}
V_508 = F_490 ( V_551 ,
V_1951 ,
V_693 , V_1505 ) ;
F_494 ( V_508 ) ;
return V_508 ;
}
int F_497 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1731 ,
int V_1952 , int V_1953 ,
const T_2 * V_1571 , T_11 V_47 , V_22 V_51 , T_12 V_1505 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return - V_137 ;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1575 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return - V_137 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) ||
F_28 ( V_53 , V_534 , V_1952 ) ||
( V_1953 &&
F_28 ( V_53 , V_1954 , V_1953 ) ) ||
F_51 ( V_53 , V_1568 , V_47 , V_1571 ) ||
( V_51 &&
F_28 ( V_53 , V_1955 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
return F_422 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1731 ) ;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_498 ( struct V_1 * V_17 , T_1 V_663 ,
const T_2 * V_1571 , T_11 V_47 , bool V_1956 , T_12 V_1505 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_285 ;
F_499 ( V_17 , V_663 , V_1956 ) ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1957 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) ||
F_51 ( V_53 , V_1568 , V_47 , V_1571 ) ||
F_104 ( V_53 , V_1560 , V_663 ,
V_598 ) ||
( V_1956 && F_29 ( V_53 , V_1958 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
static struct V_31 * F_500 ( struct V_25 * V_551 ,
const char * V_1024 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 = F_74 ( V_612 , V_1505 ) ;
void * * V_34 ;
if ( ! V_53 )
return NULL ;
V_34 = ( void * * ) V_53 -> V_34 ;
V_34 [ 0 ] = F_25 ( V_53 , 0 , 0 , 0 , V_1959 ) ;
if ( ! V_34 [ 0 ] ) {
F_75 ( V_53 ) ;
return NULL ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_551 -> V_20 ) )
goto V_61;
if ( V_1024 && F_51 ( V_53 , V_559 , V_599 , V_1024 ) )
goto V_61;
V_34 [ 1 ] = F_47 ( V_53 , V_1594 ) ;
if ( ! V_34 [ 1 ] )
goto V_61;
V_34 [ 2 ] = V_7 ;
return V_53 ;
V_61:
F_75 ( V_53 ) ;
return NULL ;
}
static void F_501 ( struct V_31 * V_53 , T_12 V_1505 )
{
void * * V_34 = ( void * * ) V_53 -> V_34 ;
struct V_6 * V_7 = V_34 [ 2 ] ;
F_48 ( V_53 , V_34 [ 1 ] ) ;
F_66 ( V_53 , V_34 [ 0 ] ) ;
memset ( V_53 -> V_34 , 0 , sizeof( V_53 -> V_34 ) ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
}
void F_502 ( struct V_25 * V_551 ,
enum V_1960 V_1961 ,
T_12 V_1505 )
{
struct V_31 * V_53 ;
F_503 ( V_551 , V_1961 ) ;
if ( F_59 ( V_1961 != V_1962 &&
V_1961 != V_1963 ) )
return;
V_53 = F_500 ( V_551 , NULL , V_1505 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1964 ,
V_1961 ) )
goto V_61;
F_501 ( V_53 , V_1505 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_504 ( struct V_25 * V_551 ,
const T_2 * V_1547 , V_22 V_1965 ,
V_22 V_246 , V_22 V_1586 , T_12 V_1505 )
{
struct V_31 * V_53 ;
V_53 = F_500 ( V_551 , V_1547 , V_1505 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1599 , V_1965 ) )
goto V_61;
if ( F_28 ( V_53 , V_1598 , V_246 ) )
goto V_61;
if ( F_28 ( V_53 , V_1600 , V_1586 ) )
goto V_61;
F_501 ( V_53 , V_1505 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_505 ( struct V_25 * V_551 ,
const T_2 * V_1547 , V_22 V_1965 , T_12 V_1505 )
{
struct V_31 * V_53 ;
F_506 ( V_551 , V_1547 , V_1965 ) ;
V_53 = F_500 ( V_551 , V_1547 , V_1505 ) ;
if ( ! V_53 )
return;
if ( F_28 ( V_53 , V_1966 , V_1965 ) )
goto V_61;
F_501 ( V_53 , V_1505 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
void F_507 ( struct V_25 * V_551 , T_12 V_1505 )
{
struct V_31 * V_53 ;
V_53 = F_500 ( V_551 , NULL , V_1505 ) ;
if ( ! V_53 )
return;
if ( F_29 ( V_53 , V_1967 ) )
goto V_61;
F_501 ( V_53 , V_1505 ) ;
return;
V_61:
F_75 ( V_53 ) ;
}
static void F_508 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_558 ,
const T_2 * V_1722 , T_12 V_1505 )
{
struct V_31 * V_53 ;
struct V_4 * V_1968 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1969 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_558 ) )
goto V_61;
V_1968 = F_47 ( V_53 , V_1710 ) ;
if ( ! V_1968 )
goto V_61;
if ( F_51 ( V_53 , V_1713 ,
V_1714 , V_1722 ) )
goto V_61;
F_48 ( V_53 , V_1968 ) ;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_509 ( struct V_25 * V_551 , const T_2 * V_558 ,
const T_2 * V_1722 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_510 ( V_551 , V_558 ) ;
F_508 ( V_7 , V_551 , V_558 , V_1722 , V_1505 ) ;
}
static void
F_511 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1970 ,
const T_2 * V_558 , bool V_1971 , T_12 V_1505 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1972 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1973 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1974 , V_1970 ) ||
F_51 ( V_53 , V_1975 , V_599 , V_558 ) ||
( V_1971 &&
F_29 ( V_53 , V_1976 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_512 ( struct V_25 * V_551 , int V_1970 ,
const T_2 * V_558 , bool V_1971 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_513 ( V_551 , V_1970 , V_558 , V_1971 ) ;
F_511 ( V_7 , V_551 , V_1970 , V_558 , V_1971 , V_1505 ) ;
}
static void F_514 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_531 * V_532 ,
T_12 V_1505 ,
enum V_282 V_1977 ,
T_2 V_1344 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1977 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_532 ) )
goto V_61;
if ( ( V_1977 == V_1978 ) &&
( F_28 ( V_53 , V_1342 , V_1344 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_515 ( struct V_25 * V_551 ,
struct V_531 * V_532 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_516 ( V_551 , V_532 ) ;
V_17 -> V_532 = * V_532 ;
V_17 -> V_557 = * V_532 ;
F_514 ( V_7 , V_551 , V_532 , V_136 ,
V_1979 , 0 ) ;
}
void F_517 ( struct V_25 * V_551 ,
struct V_531 * V_532 ,
T_2 V_1344 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_518 ( V_551 , V_532 ) ;
F_514 ( V_7 , V_551 , V_532 , V_136 ,
V_1978 , V_1344 ) ;
}
void
F_519 ( struct V_6 * V_7 ,
const struct V_531 * V_532 ,
enum V_1980 V_1981 ,
struct V_25 * V_19 , T_12 V_1505 )
{
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1982 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_61;
}
if ( F_28 ( V_53 , V_1983 , V_1981 ) )
goto V_61;
if ( F_101 ( V_53 , V_532 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_520 ( struct V_25 * V_551 , const T_2 * V_693 ,
T_1 V_663 , bool V_1984 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
F_521 ( V_551 , V_693 , V_663 , V_1984 ) ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1725 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_693 ) ||
F_104 ( V_53 , V_1560 , V_663 ,
V_598 ) ||
( V_1984 && F_29 ( V_53 , V_1958 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_522 ( struct V_18 * V_18 ,
const T_2 * V_1985 , T_11 V_47 ,
int V_1952 , int V_1953 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
struct V_1726 * V_1727 ;
F_523 ( V_18 , V_1985 , V_47 , V_1952 , V_1953 ) ;
F_291 ( & V_7 -> V_1730 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1908 ) ;
if ( ! V_53 ) {
F_293 ( & V_7 -> V_1730 ) ;
return;
}
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1575 ) ;
if ( ! V_285 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1952 &&
F_28 ( V_53 , V_534 , V_1952 ) ) ||
( V_1953 &&
F_28 ( V_53 , V_1954 , V_1953 ) ) ||
F_51 ( V_53 , V_1568 , V_47 , V_1985 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_422 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1727 -> V_1731 ) ;
}
F_293 ( & V_7 -> V_1730 ) ;
return;
V_61:
F_293 ( & V_7 -> V_1730 ) ;
if ( V_285 )
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
static int F_524 ( struct V_31 * V_53 ,
struct V_1986 * V_1987 )
{
struct V_1988 * V_1636 = V_1987 -> V_1989 ;
struct V_4 * V_1990 , * V_1991 , * V_288 ;
int V_161 , V_163 ;
V_1990 = F_47 (
V_53 , V_1992 ) ;
if ( ! V_1990 )
return - V_507 ;
for ( V_161 = 0 ; V_161 < V_1636 -> V_1993 ; V_161 ++ ) {
struct V_1994 * V_1638 = V_1636 -> V_1637 [ V_161 ] ;
V_1991 = F_47 ( V_53 , V_161 ) ;
if ( ! V_1991 )
break;
if ( F_51 ( V_53 , V_605 , V_1638 -> V_606 . V_604 ,
V_1638 -> V_606 . V_606 ) ) {
F_525 ( V_53 , V_1991 ) ;
goto V_611;
}
if ( V_1638 -> V_368 ) {
V_288 = F_47 (
V_53 , V_1276 ) ;
if ( ! V_288 ) {
F_525 ( V_53 , V_1991 ) ;
goto V_611;
}
for ( V_163 = 0 ; V_163 < V_1638 -> V_368 ; V_163 ++ ) {
if ( F_28 ( V_53 , V_163 , V_1638 -> V_369 [ V_163 ] ) ) {
F_525 ( V_53 , V_288 ) ;
F_525 ( V_53 , V_1991 ) ;
goto V_611;
}
}
F_48 ( V_53 , V_288 ) ;
}
F_48 ( V_53 , V_1991 ) ;
}
V_611:
F_48 ( V_53 , V_1990 ) ;
return 0 ;
}
void F_526 ( struct V_1 * V_17 ,
struct V_1986 * V_1987 ,
T_12 V_1505 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
int V_1640 = 200 ;
F_527 ( V_17 -> V_18 , V_17 , V_1987 ) ;
if ( V_1987 )
V_1640 += V_1987 -> V_1995 ;
V_53 = F_74 ( V_1640 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_1996 ) ;
if ( ! V_285 )
goto V_673;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_673;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_673;
if ( V_1987 ) {
struct V_4 * V_1997 ;
V_1997 = F_47 ( V_53 , V_1642 ) ;
if ( ! V_1997 )
goto V_673;
if ( V_1987 -> V_453 &&
F_29 ( V_53 , V_208 ) )
goto V_673;
if ( V_1987 -> V_1644 &&
F_29 ( V_53 , V_210 ) )
goto V_673;
if ( V_1987 -> V_1645 &&
F_29 ( V_53 , V_214 ) )
goto V_673;
if ( V_1987 -> V_1646 &&
F_29 ( V_53 , V_216 ) )
goto V_673;
if ( V_1987 -> V_1647 &&
F_29 ( V_53 , V_218 ) )
goto V_673;
if ( V_1987 -> V_1648 &&
F_29 ( V_53 , V_220 ) )
goto V_673;
if ( V_1987 -> V_1998 >= 0 &&
F_28 ( V_53 , V_230 ,
V_1987 -> V_1998 ) )
goto V_673;
if ( V_1987 -> V_1999 &&
F_29 ( V_53 , V_2000 ) )
goto V_673;
if ( V_1987 -> V_2001 &&
F_29 ( V_53 , V_2002 ) )
goto V_673;
if ( V_1987 -> V_2003 &&
F_29 ( V_53 ,
V_2004 ) )
goto V_673;
if ( V_1987 -> V_2005 ) {
V_22 V_2006 = V_2007 ;
V_22 V_2008 = V_2009 ;
if ( ! V_1987 -> V_2010 ) {
V_2006 =
V_2011 ;
V_2008 =
V_2012 ;
}
if ( V_1987 -> V_2013 &&
F_28 ( V_53 , V_2008 , V_1987 -> V_2013 ) )
goto V_673;
if ( F_51 ( V_53 , V_2006 , V_1987 -> V_1995 ,
V_1987 -> V_2005 ) )
goto V_673;
}
if ( V_1987 -> V_1989 &&
F_524 ( V_53 , V_1987 ) )
goto V_673;
F_48 ( V_53 , V_1997 ) ;
}
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_673:
F_75 ( V_53 ) ;
}
void F_528 ( struct V_25 * V_551 , const T_2 * V_1547 ,
enum V_1554 V_2014 ,
T_3 V_1031 , T_12 V_1505 )
{
struct V_1 * V_17 = V_551 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
F_529 ( V_17 -> V_18 , V_551 , V_1547 , V_2014 ,
V_1031 ) ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_2015 ) ;
if ( ! V_285 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_551 -> V_20 ) ||
F_56 ( V_53 , V_1556 , V_2014 ) ||
F_51 ( V_53 , V_559 , V_599 , V_1547 ) ||
( V_1031 > 0 &&
F_55 ( V_53 , V_1030 , V_1031 ) ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_1505 ) ;
return;
V_61:
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
static int F_530 ( struct V_2016 * V_2017 ,
unsigned long V_284 ,
void * V_2018 )
{
struct V_2019 * V_2020 = V_2018 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1726 * V_1727 , * V_24 ;
if ( V_284 != V_2021 || V_2020 -> V_2022 != V_2023 )
return V_2024 ;
F_240 () ;
F_531 (rdev, &cfg80211_rdev_list, list) {
bool V_2025 = false ;
bool V_2026 = false ;
struct V_1297 * V_1328 =
F_241 ( V_7 -> V_1328 ) ;
if ( V_1328 && V_2020 -> V_49 &&
V_1328 -> V_650 == V_2020 -> V_49 )
V_2026 = true ;
F_531 (wdev, &rdev->wiphy.wdev_list, list) {
F_532 ( V_17 , V_2020 -> V_49 ) ;
if ( V_17 -> V_650 == V_2020 -> V_49 )
V_2025 = true ;
}
F_291 ( & V_7 -> V_1730 ) ;
F_533 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1727 -> V_1731 == V_2020 -> V_49 ) {
F_534 ( & V_1727 -> V_656 ) ;
F_41 ( V_1727 ) ;
break;
}
}
F_293 ( & V_7 -> V_1730 ) ;
if ( V_2025 ) {
struct V_2027 * V_2028 ;
V_2028 = F_39 ( sizeof( * V_2028 ) , V_1908 ) ;
if ( V_2028 ) {
V_2028 -> V_1731 = V_2020 -> V_49 ;
F_535 ( & V_7 -> V_2029 ) ;
F_402 ( & V_2028 -> V_656 , & V_7 -> V_2030 ) ;
F_536 ( & V_7 -> V_2029 ) ;
F_537 ( & V_7 -> V_2031 ) ;
}
} else if ( V_2026 ) {
V_1328 -> V_650 = 0 ;
if ( V_7 -> V_353 -> V_1330 &&
V_7 -> V_18 . V_51 & V_424 )
F_537 ( & V_7 -> V_2032 ) ;
}
}
F_242 () ;
F_538 ( V_2020 -> V_49 ) ;
return V_2033 ;
}
void F_539 ( struct V_25 * V_19 ,
struct V_2034 * V_2035 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
F_540 ( V_18 , V_19 , V_2035 ) ;
if ( ! V_2035 -> V_2036 )
return;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_2037 ) ;
if ( ! V_285 )
goto V_611;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_559 , V_599 , V_2035 -> V_2036 ) )
goto V_611;
if ( V_2035 -> V_1363 &&
F_51 ( V_53 , V_742 , V_2035 -> V_2038 , V_2035 -> V_1363 ) )
goto V_611;
if ( V_2035 -> V_2039 &&
F_51 ( V_53 , V_2040 , V_2035 -> V_2041 ,
V_2035 -> V_2039 ) )
goto V_611;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1910 , V_136 ) ;
return;
V_611:
F_75 ( V_53 ) ;
}
void F_541 ( struct V_1 * V_17 , T_12 V_1505 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_285 ;
V_22 V_1731 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1837 )
return;
V_1731 = V_7 -> V_1837 ;
V_7 -> V_1837 = 0 ;
V_53 = F_74 ( V_612 , V_1505 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_2042 ) ;
if ( ! V_285 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_61;
F_66 ( V_53 , V_285 ) ;
F_422 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1731 ) ;
return;
V_61:
if ( V_285 )
F_67 ( V_53 , V_285 ) ;
F_75 ( V_53 ) ;
}
void F_542 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_285 ;
V_53 = F_74 ( V_612 , V_136 ) ;
if ( ! V_53 )
return;
V_285 = F_25 ( V_53 , 0 , 0 , 0 , V_2043 ) ;
if ( ! V_285 )
goto V_611;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ,
V_598 ) )
goto V_611;
F_66 ( V_53 , V_285 ) ;
F_321 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1910 , V_136 ) ;
return;
V_611:
F_75 ( V_53 ) ;
}
int F_543 ( void )
{
int V_35 ;
V_35 = F_544 ( & V_38 , V_2044 ,
V_2045 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_545 ( & V_2046 ) ;
if ( V_35 )
goto V_2047;
return 0 ;
V_2047:
F_546 ( & V_38 ) ;
return V_35 ;
}
void F_547 ( void )
{
F_548 ( & V_2046 ) ;
F_546 ( & V_38 ) ;
}
