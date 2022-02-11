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
F_6 (wdev, &rdev->wdev_list, list) {
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
F_6 (wdev, &tmp->wdev_list, list) {
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
F_6 (tmp, &(*rdev)->wdev_list, list) {
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
V_8 = F_38 ( sizeof( * V_8 ) , V_135 ) ;
if ( ! V_8 )
return F_3 ( - V_136 ) ;
V_8 -> V_98 = - 1 ;
V_8 -> V_100 = - 1 ;
F_39 (key, keys, rem) {
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_105 = - 1 ;
V_35 = F_32 ( V_92 , & V_133 ) ;
if ( V_35 )
goto error;
V_35 = - V_16 ;
if ( ! V_133 . V_107 . V_92 )
goto error;
if ( V_133 . V_105 < 0 || V_133 . V_105 > 4 )
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
V_8 -> V_137 [ V_133 . V_105 ] . V_112 = V_133 . V_107 . V_112 ;
V_8 -> V_137 [ V_133 . V_105 ] . V_108 = V_133 . V_107 . V_108 ;
V_8 -> V_137 [ V_133 . V_105 ] . V_92 = V_8 -> V_138 [ V_133 . V_105 ] ;
memcpy ( V_8 -> V_138 [ V_133 . V_105 ] , V_133 . V_107 . V_92 , V_133 . V_107 . V_108 ) ;
if ( V_133 . V_107 . V_112 == V_139 ||
V_133 . V_107 . V_112 == V_140 ) {
if ( V_132 )
* V_132 = true ;
}
}
return V_8 ;
error:
F_41 ( V_8 ) ;
return F_3 ( V_35 ) ;
}
static int F_42 ( struct V_1 * V_17 )
{
F_43 ( V_17 ) ;
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
default:
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
static int F_46 ( struct V_31 * V_53 , V_22 V_45 , T_3 V_151 )
{
struct V_4 * V_152 = F_47 ( V_53 , V_45 ) ;
int V_153 ;
if ( ! V_152 )
goto V_61;
V_153 = 0 ;
while ( V_151 ) {
if ( ( V_151 & 1 ) && F_29 ( V_53 , V_153 ) )
goto V_61;
V_151 >>= 1 ;
V_153 ++ ;
}
F_48 ( V_53 , V_152 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_49 ( struct V_18 * V_18 ,
struct V_31 * V_53 ,
bool V_56 )
{
struct V_4 * V_154 ;
int V_153 , V_155 ;
V_154 = F_47 ( V_53 ,
V_156 ) ;
if ( ! V_154 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_18 -> V_157 ; V_153 ++ ) {
const struct V_158 * V_159 ;
struct V_4 * V_160 , * V_161 ;
V_159 = & V_18 -> V_162 [ V_153 ] ;
V_160 = F_47 ( V_53 , V_153 + 1 ) ;
if ( ! V_160 )
goto V_61;
V_161 = F_47 ( V_53 , V_163 ) ;
if ( ! V_161 )
goto V_61;
for ( V_155 = 0 ; V_155 < V_159 -> V_164 ; V_155 ++ ) {
struct V_4 * V_165 ;
V_165 = F_47 ( V_53 , V_155 + 1 ) ;
if ( ! V_165 )
goto V_61;
if ( F_28 ( V_53 , V_166 ,
V_159 -> V_167 [ V_155 ] . V_168 ) )
goto V_61;
if ( F_46 ( V_53 , V_169 ,
V_159 -> V_167 [ V_155 ] . V_170 ) )
goto V_61;
F_48 ( V_53 , V_165 ) ;
}
F_48 ( V_53 , V_161 ) ;
if ( V_159 -> V_171 &&
F_29 ( V_53 , V_172 ) )
goto V_61;
if ( F_28 ( V_53 , V_173 ,
V_159 -> V_174 ) ||
F_28 ( V_53 , V_175 ,
V_159 -> V_176 ) )
goto V_61;
if ( V_56 &&
( F_28 ( V_53 , V_177 ,
V_159 -> V_178 ) ||
F_28 ( V_53 , V_179 ,
V_159 -> V_180 ) ) )
goto V_61;
F_48 ( V_53 , V_160 ) ;
}
F_48 ( V_53 , V_154 ) ;
return 0 ;
V_61:
return - V_91 ;
}
static int F_50 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
const struct V_181 * V_182 = V_7 -> V_18 . V_183 -> V_182 ;
struct V_4 * V_184 ;
if ( ! V_182 )
return 0 ;
V_184 = F_47 ( V_53 , V_185 ) ;
if ( ! V_184 )
return - V_91 ;
if ( F_28 ( V_53 , V_186 ,
V_182 -> V_187 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_186 ,
V_182 -> V_187 ) )
return - V_91 ;
if ( V_182 -> V_50 && F_29 ( V_53 , V_188 ) )
return - V_91 ;
if ( V_182 -> V_189 && F_51 ( V_53 , V_190 ,
sizeof( * V_182 -> V_189 ) , V_182 -> V_189 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_191 ,
V_182 -> V_192 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_193 ,
V_182 -> V_194 ) )
return - V_91 ;
F_48 ( V_53 , V_184 ) ;
return 0 ;
}
static int F_52 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
bool V_56 )
{
struct V_4 * V_195 ;
if ( ! V_7 -> V_18 . V_183 )
return 0 ;
V_195 = F_47 ( V_53 , V_196 ) ;
if ( ! V_195 )
return - V_91 ;
if ( ( ( V_7 -> V_18 . V_183 -> V_51 & V_197 ) &&
F_29 ( V_53 , V_198 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_199 ) &&
F_29 ( V_53 , V_200 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_201 ) &&
F_29 ( V_53 , V_202 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_203 ) &&
F_29 ( V_53 , V_204 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_205 ) &&
F_29 ( V_53 , V_206 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_207 ) &&
F_29 ( V_53 , V_208 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_209 ) &&
F_29 ( V_53 , V_210 ) ) ||
( ( V_7 -> V_18 . V_183 -> V_51 & V_211 ) &&
F_29 ( V_53 , V_212 ) ) )
return - V_91 ;
if ( V_7 -> V_18 . V_183 -> V_213 ) {
struct V_214 V_215 = {
. V_216 = V_7 -> V_18 . V_183 -> V_213 ,
. V_217 = V_7 -> V_18 . V_183 -> V_218 ,
. V_219 = V_7 -> V_18 . V_183 -> V_220 ,
. V_221 = V_7 -> V_18 . V_183 -> V_221 ,
} ;
if ( F_51 ( V_53 , V_222 ,
sizeof( V_215 ) , & V_215 ) )
return - V_91 ;
}
if ( V_56 && F_50 ( V_7 , V_53 ) )
return - V_91 ;
F_48 ( V_53 , V_195 ) ;
return 0 ;
}
static int F_53 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_223 V_224 ;
if ( ! V_7 -> V_18 . V_225 )
return 0 ;
V_224 . V_226 = V_7 -> V_18 . V_225 -> V_227 ;
V_224 . V_228 = V_7 -> V_18 . V_225 -> V_228 ;
V_224 . V_215 . V_216 = V_7 -> V_18 . V_225 -> V_213 ;
V_224 . V_215 . V_217 = V_7 -> V_18 . V_225 -> V_218 ;
V_224 . V_215 . V_219 = V_7 -> V_18 . V_225 -> V_220 ;
V_224 . V_215 . V_221 = V_7 -> V_18 . V_225 -> V_221 ;
if ( F_51 ( V_53 , V_229 , sizeof( V_224 ) , & V_224 ) )
return - V_91 ;
return 0 ;
}
static int F_54 ( struct V_31 * V_53 ,
struct V_230 * V_231 )
{
struct V_4 * V_232 , * V_233 ;
struct V_234 * V_235 ;
int V_153 ;
if ( V_231 -> V_236 . V_237 &&
( F_51 ( V_53 , V_238 ,
sizeof( V_231 -> V_236 . V_239 ) ,
& V_231 -> V_236 . V_239 ) ||
F_55 ( V_53 , V_240 ,
V_231 -> V_236 . V_241 ) ||
F_56 ( V_53 , V_242 ,
V_231 -> V_236 . V_243 ) ||
F_56 ( V_53 , V_244 ,
V_231 -> V_236 . V_245 ) ) )
return - V_91 ;
if ( V_231 -> V_246 . V_247 &&
( F_51 ( V_53 , V_248 ,
sizeof( V_231 -> V_246 . V_249 ) ,
& V_231 -> V_246 . V_249 ) ||
F_28 ( V_53 , V_250 ,
V_231 -> V_246 . V_241 ) ) )
return - V_91 ;
V_232 = F_47 ( V_53 , V_251 ) ;
if ( ! V_232 )
return - V_91 ;
for ( V_153 = 0 ; V_153 < V_231 -> V_252 ; V_153 ++ ) {
V_233 = F_47 ( V_53 , V_153 ) ;
if ( ! V_233 )
return - V_91 ;
V_235 = & V_231 -> V_253 [ V_153 ] ;
if ( F_28 ( V_53 , V_254 ,
V_235 -> V_255 ) )
return - V_91 ;
if ( ( V_235 -> V_51 & V_256 ) &&
F_29 ( V_53 ,
V_257 ) )
return - V_91 ;
F_48 ( V_53 , V_233 ) ;
}
F_48 ( V_53 , V_232 ) ;
return 0 ;
}
static int
F_57 ( struct V_31 * V_53 ,
const struct V_258 * V_259 )
{
T_3 V_260 ;
struct V_4 * V_261 , * V_262 ;
enum V_263 V_264 ;
int V_153 ;
if ( ! V_259 )
return 0 ;
V_262 = F_47 ( V_53 , V_265 ) ;
if ( ! V_262 )
return - V_91 ;
for ( V_264 = 0 ; V_264 < V_266 ; V_264 ++ ) {
V_261 = F_47 ( V_53 , V_264 ) ;
if ( ! V_261 )
return - V_91 ;
V_153 = 0 ;
V_260 = V_259 [ V_264 ] . V_267 ;
while ( V_260 ) {
if ( ( V_260 & 1 ) &&
F_55 ( V_53 , V_268 ,
( V_153 << 4 ) | V_269 ) )
return - V_91 ;
V_260 >>= 1 ;
V_153 ++ ;
}
F_48 ( V_53 , V_261 ) ;
}
F_48 ( V_53 , V_262 ) ;
V_262 = F_47 ( V_53 , V_270 ) ;
if ( ! V_262 )
return - V_91 ;
for ( V_264 = 0 ; V_264 < V_266 ; V_264 ++ ) {
V_261 = F_47 ( V_53 , V_264 ) ;
if ( ! V_261 )
return - V_91 ;
V_153 = 0 ;
V_260 = V_259 [ V_264 ] . V_271 ;
while ( V_260 ) {
if ( ( V_260 & 1 ) &&
F_55 ( V_53 , V_268 ,
( V_153 << 4 ) | V_269 ) )
return - V_91 ;
V_260 >>= 1 ;
V_153 ++ ;
}
F_48 ( V_53 , V_261 ) ;
}
F_48 ( V_53 , V_262 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
enum V_272 V_52 ,
struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_273 * V_274 )
{
void * V_275 ;
struct V_4 * V_276 , * V_277 ;
struct V_4 * V_278 , * V_279 ;
struct V_4 * V_280 ;
enum V_281 V_282 ;
struct V_54 * V_55 ;
int V_153 ;
const struct V_258 * V_259 =
V_7 -> V_18 . V_259 ;
V_22 V_283 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_275 )
return - V_91 ;
if ( F_59 ( ! V_274 ) )
return - V_16 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_60 ( V_53 , V_284 ,
F_61 ( & V_7 -> V_18 ) ) ||
F_28 ( V_53 , V_285 ,
V_286 ) )
goto V_61;
if ( V_52 != V_287 )
goto V_288;
switch ( V_274 -> V_289 ) {
case 0 :
if ( F_56 ( V_53 , V_290 ,
V_7 -> V_18 . V_291 ) ||
F_56 ( V_53 , V_292 ,
V_7 -> V_18 . V_293 ) ||
F_28 ( V_53 , V_294 ,
V_7 -> V_18 . V_295 ) ||
F_28 ( V_53 , V_296 ,
V_7 -> V_18 . V_297 ) ||
F_56 ( V_53 , V_298 ,
V_7 -> V_18 . V_299 ) ||
F_56 ( V_53 , V_300 ,
V_7 -> V_18 . V_301 ) ||
F_56 ( V_53 , V_302 ,
V_7 -> V_18 . V_303 ) ||
F_55 ( V_53 , V_304 ,
V_7 -> V_18 . V_305 ) ||
F_55 ( V_53 , V_306 ,
V_7 -> V_18 . V_307 ) ||
F_56 ( V_53 , V_308 ,
V_7 -> V_18 . V_309 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_310 ) &&
F_29 ( V_53 , V_311 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_312 ) &&
F_29 ( V_53 , V_313 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_314 ) &&
F_29 ( V_53 , V_315 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_316 ) &&
F_29 ( V_53 , V_317 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_318 ) &&
F_29 ( V_53 , V_319 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_320 ) &&
F_29 ( V_53 , V_321 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 1 :
if ( F_51 ( V_53 , V_323 ,
sizeof( V_22 ) * V_7 -> V_18 . V_324 ,
V_7 -> V_18 . V_325 ) )
goto V_61;
if ( F_56 ( V_53 , V_326 ,
V_7 -> V_18 . V_327 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_328 ) &&
F_29 ( V_53 , V_329 ) )
goto V_61;
if ( F_28 ( V_53 , V_330 ,
V_7 -> V_18 . V_331 ) ||
F_28 ( V_53 , V_332 ,
V_7 -> V_18 . V_333 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_334 ) &&
F_28 ( V_53 , V_335 ,
V_7 -> V_18 . V_336 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_331 ||
V_7 -> V_18 . V_333 ) &&
V_7 -> V_337 -> V_338 ) {
V_22 V_339 = 0 , V_340 = 0 ;
int V_341 ;
V_341 = F_62 ( V_7 , & V_339 , & V_340 ) ;
if ( ! V_341 ) {
if ( F_28 ( V_53 ,
V_342 ,
V_339 ) ||
F_28 ( V_53 ,
V_343 ,
V_340 ) )
goto V_61;
}
}
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 2 :
if ( F_46 ( V_53 , V_344 ,
V_7 -> V_18 . V_345 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 3 :
V_276 = F_47 ( V_53 , V_346 ) ;
if ( ! V_276 )
goto V_61;
for ( V_282 = V_274 -> V_347 ;
V_282 < V_348 ; V_282 ++ ) {
struct V_230 * V_231 ;
V_231 = V_7 -> V_18 . V_349 [ V_282 ] ;
if ( ! V_231 )
continue;
V_277 = F_47 ( V_53 , V_282 ) ;
if ( ! V_277 )
goto V_61;
switch ( V_274 -> V_350 ) {
case 0 :
if ( F_54 ( V_53 , V_231 ) )
goto V_61;
V_274 -> V_350 ++ ;
if ( V_274 -> V_322 )
break;
default:
V_278 = F_47 (
V_53 , V_351 ) ;
if ( ! V_278 )
goto V_61;
for ( V_153 = V_274 -> V_350 - 1 ;
V_153 < V_231 -> V_352 ;
V_153 ++ ) {
V_279 = F_47 ( V_53 , V_153 ) ;
if ( ! V_279 )
goto V_61;
V_55 = & V_231 -> V_353 [ V_153 ] ;
if ( F_27 (
V_53 , V_55 ,
V_274 -> V_322 ) )
goto V_61;
F_48 ( V_53 , V_279 ) ;
if ( V_274 -> V_322 )
break;
}
if ( V_153 < V_231 -> V_352 )
V_274 -> V_350 = V_153 + 2 ;
else
V_274 -> V_350 = 0 ;
F_48 ( V_53 , V_278 ) ;
}
F_48 ( V_53 , V_277 ) ;
if ( V_274 -> V_322 ) {
if ( V_274 -> V_350 )
V_282 -- ;
break;
}
}
F_48 ( V_53 , V_276 ) ;
if ( V_282 < V_348 )
V_274 -> V_347 = V_282 + 1 ;
else
V_274 -> V_347 = 0 ;
if ( V_274 -> V_347 == 0 && V_274 -> V_350 == 0 )
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 4 :
V_280 = F_47 ( V_53 , V_354 ) ;
if ( ! V_280 )
goto V_61;
V_153 = 0 ;
#define F_63 ( T_4 , T_5 ) \
do { \
if (rdev->ops->op) { \
i++; \
if (nla_put_u32(msg, i, NL80211_CMD_ ## n)) \
goto nla_put_failure; \
} \
} while (0)
F_63 ( V_355 , V_356 ) ;
F_63 ( V_357 , V_358 ) ;
F_63 ( V_359 , V_360 ) ;
F_63 ( V_361 , V_362 ) ;
F_63 ( V_363 , V_364 ) ;
F_63 ( V_365 , V_366 ) ;
F_63 ( V_367 , V_368 ) ;
F_63 ( V_369 , V_370 ) ;
F_63 ( V_371 , V_372 ) ;
F_63 ( V_373 , V_374 ) ;
F_63 ( V_375 , V_376 ) ;
F_63 ( V_377 , V_378 ) ;
F_63 ( V_379 , V_380 ) ;
F_63 ( V_381 , V_382 ) ;
F_63 ( V_383 , V_384 ) ;
F_63 ( V_385 , V_386 ) ;
F_63 ( V_387 , V_388 ) ;
if ( V_7 -> V_18 . V_51 & V_389 )
F_63 ( V_390 , V_391 ) ;
F_63 ( V_392 , V_393 ) ;
F_63 ( V_394 , V_395 ) ;
F_63 ( V_396 , V_397 ) ;
if ( V_7 -> V_18 . V_51 & V_398 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_399 ) )
goto V_61;
}
if ( V_7 -> V_337 -> V_400 || V_7 -> V_337 -> V_361 ||
V_7 -> V_337 -> V_381 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_401 ) )
goto V_61;
}
F_63 ( V_402 , V_403 ) ;
if ( V_7 -> V_18 . V_51 & V_318 ) {
F_63 ( V_404 , V_405 ) ;
F_63 ( V_406 , V_407 ) ;
}
if ( V_7 -> V_18 . V_51 & V_408 )
F_63 ( V_409 , V_410 ) ;
F_63 ( V_411 , V_412 ) ;
F_63 ( V_413 , V_414 ) ;
if ( V_7 -> V_18 . V_51 & V_415 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_416 ) )
goto V_61;
}
F_63 ( V_417 , V_418 ) ;
F_63 ( V_419 , V_420 ) ;
#ifdef F_64
F_63 ( V_421 , V_422 ) ;
#endif
if ( V_274 -> V_322 ) {
F_63 ( V_423 , V_424 ) ;
F_63 ( V_425 , V_426 ) ;
if ( V_7 -> V_18 . V_51 & V_427 )
F_63 ( V_428 , V_429 ) ;
F_63 ( V_430 , V_431 ) ;
if ( V_7 -> V_18 . V_51 &
V_432 )
F_63 ( V_433 , V_434 ) ;
}
#undef F_63
if ( V_7 -> V_337 -> V_435 || V_7 -> V_337 -> V_371 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_436 ) )
goto V_61;
}
if ( V_7 -> V_337 -> V_437 || V_7 -> V_337 -> V_375 ) {
V_153 ++ ;
if ( F_28 ( V_53 , V_153 , V_438 ) )
goto V_61;
}
F_48 ( V_53 , V_280 ) ;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 5 :
if ( V_7 -> V_337 -> V_390 &&
( V_7 -> V_18 . V_51 & V_389 ) &&
F_28 ( V_53 ,
V_439 ,
V_7 -> V_18 . V_440 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_441 ) &&
F_29 ( V_53 , V_442 ) )
goto V_61;
if ( F_57 ( V_53 , V_259 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 6 :
#ifdef F_65
if ( F_52 ( V_53 , V_7 , V_274 -> V_322 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
#else
V_274 -> V_289 ++ ;
#endif
case 7 :
if ( F_46 ( V_53 , V_443 ,
V_7 -> V_18 . V_444 ) )
goto V_61;
if ( F_49 ( & V_7 -> V_18 , V_53 ,
V_274 -> V_322 ) )
goto V_61;
V_274 -> V_289 ++ ;
if ( V_274 -> V_322 )
break;
case 8 :
if ( ( V_7 -> V_18 . V_51 & V_445 ) &&
F_28 ( V_53 , V_446 ,
V_7 -> V_18 . V_447 ) )
goto V_61;
V_283 = V_7 -> V_18 . V_283 ;
if ( V_274 -> V_322 )
V_283 |= V_448 ;
if ( F_28 ( V_53 , V_449 , V_283 ) )
goto V_61;
if ( V_7 -> V_18 . V_450 &&
F_51 ( V_53 , V_451 ,
sizeof( * V_7 -> V_18 . V_450 ) ,
V_7 -> V_18 . V_450 ) )
goto V_61;
if ( V_7 -> V_18 . V_51 & V_445 &&
V_7 -> V_18 . V_452 &&
F_28 ( V_53 , V_453 ,
V_7 -> V_18 . V_452 ) )
goto V_61;
V_274 -> V_289 ++ ;
break;
case 9 :
if ( V_7 -> V_18 . V_454 &&
( F_51 ( V_53 , V_455 ,
V_7 -> V_18 . V_456 ,
V_7 -> V_18 . V_454 ) ||
F_51 ( V_53 , V_457 ,
V_7 -> V_18 . V_456 ,
V_7 -> V_18 . V_458 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_459 &&
F_51 ( V_53 , V_460 ,
sizeof( * V_7 -> V_18 . V_459 ) ,
V_7 -> V_18 . V_459 ) )
goto V_61;
V_274 -> V_289 ++ ;
break;
case 10 :
if ( F_53 ( V_53 , V_7 ) )
goto V_61;
if ( ( V_7 -> V_18 . V_51 & V_461 ) &&
( F_29 ( V_53 , V_462 ) ||
F_29 ( V_53 , V_463 ) ) )
goto V_61;
if ( V_7 -> V_18 . V_464 &&
F_28 ( V_53 , V_465 ,
V_7 -> V_18 . V_464 ) )
goto V_61;
V_274 -> V_289 ++ ;
break;
case 11 :
if ( V_7 -> V_18 . V_466 ) {
const struct V_467 * V_30 ;
struct V_4 * V_468 ;
V_468 = F_47 ( V_53 , V_469 ) ;
if ( ! V_468 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_466 ; V_153 ++ ) {
V_30 = & V_7 -> V_18 . V_470 [ V_153 ] . V_30 ;
if ( F_51 ( V_53 , V_153 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_468 ) ;
}
if ( V_7 -> V_18 . V_471 ) {
const struct V_467 * V_30 ;
struct V_4 * V_468 ;
V_468 = F_47 ( V_53 ,
V_472 ) ;
if ( ! V_468 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_471 ; V_153 ++ ) {
V_30 = & V_7 -> V_18 . V_473 [ V_153 ] ;
if ( F_51 ( V_53 , V_153 + 1 , sizeof( * V_30 ) , V_30 ) )
goto V_61;
}
F_48 ( V_53 , V_468 ) ;
}
V_274 -> V_289 ++ ;
break;
case 12 :
if ( V_7 -> V_18 . V_51 & V_427 &&
F_56 ( V_53 , V_474 ,
V_7 -> V_18 . V_475 ) )
goto V_61;
V_274 -> V_289 = 0 ;
break;
}
V_288:
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
static int F_68 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_273 * V_274 )
{
struct V_4 * * V_95 = V_38 . V_40 ;
int V_477 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_95 , V_38 . V_41 , V_42 ) ;
if ( V_477 )
return 0 ;
V_274 -> V_322 = V_95 [ V_478 ] ;
if ( V_95 [ V_26 ] )
V_274 -> V_479 = F_4 ( V_95 [ V_26 ] ) ;
if ( V_95 [ V_12 ] )
V_274 -> V_479 = F_5 ( V_95 [ V_12 ] ) >> 32 ;
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
V_274 -> V_479 = V_7 -> V_14 ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_105 = 0 , V_477 ;
struct V_273 * V_274 = ( void * ) V_34 -> args [ 0 ] ;
struct V_6 * V_7 ;
F_14 () ;
if ( ! V_274 ) {
V_274 = F_38 ( sizeof( * V_274 ) , V_135 ) ;
if ( ! V_274 ) {
F_20 () ;
return - V_136 ;
}
V_274 -> V_479 = - 1 ;
V_477 = F_68 ( V_32 , V_34 , V_274 ) ;
if ( V_477 ) {
F_41 ( V_274 ) ;
F_20 () ;
return V_477 ;
}
V_34 -> args [ 0 ] = ( long ) V_274 ;
}
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( ++ V_105 <= V_274 -> V_480 )
continue;
if ( V_274 -> V_479 != - 1 &&
V_274 -> V_479 != V_7 -> V_14 )
continue;
do {
V_477 = F_58 ( V_7 , V_287 ,
V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_481 ,
V_482 , V_274 ) ;
if ( V_477 < 0 ) {
if ( ( V_477 == - V_91 || V_477 == - V_476 ) &&
! V_32 -> V_47 && ! V_274 -> V_322 &&
V_34 -> V_483 < 4096 ) {
V_34 -> V_483 = 4096 ;
V_274 -> V_289 = 0 ;
F_20 () ;
return 1 ;
}
V_105 -- ;
break;
}
} while ( V_274 -> V_289 > 0 );
break;
}
F_20 () ;
V_274 -> V_480 = V_105 ;
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
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_273 V_274 = {} ;
V_53 = F_74 ( 4096 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_58 ( V_7 , V_287 , V_53 ,
V_30 -> V_485 , V_30 -> V_486 , 0 ,
& V_274 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_95 [] ,
struct V_487 * V_488 )
{
if ( ! V_95 [ V_489 ] || ! V_95 [ V_490 ] ||
! V_95 [ V_491 ] || ! V_95 [ V_492 ] ||
! V_95 [ V_493 ] )
return - V_16 ;
V_488 -> V_494 = F_34 ( V_95 [ V_489 ] ) ;
V_488 -> V_495 = F_78 ( V_95 [ V_490 ] ) ;
V_488 -> V_496 = F_78 ( V_95 [ V_491 ] ) ;
V_488 -> V_497 = F_78 ( V_95 [ V_492 ] ) ;
V_488 -> V_498 = F_34 ( V_95 [ V_493 ] ) ;
if ( V_488 -> V_494 >= V_499 )
return - V_16 ;
return 0 ;
}
static bool F_79 ( struct V_1 * V_17 )
{
return ! V_17 ||
V_17 -> V_141 == V_142 ||
V_17 -> V_141 == V_145 ||
V_17 -> V_141 == V_500 ||
V_17 -> V_141 == V_144 ;
}
static int F_80 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_501 * V_502 )
{
V_22 V_503 ;
if ( ! V_30 -> V_5 [ V_504 ] )
return - V_16 ;
V_503 = F_4 ( V_30 -> V_5 [ V_504 ] ) ;
V_502 -> V_55 = F_45 ( & V_7 -> V_18 , V_503 ) ;
V_502 -> V_505 = V_506 ;
V_502 -> V_507 = V_503 ;
V_502 -> V_508 = 0 ;
if ( ! V_502 -> V_55 || V_502 -> V_55 -> V_51 & V_62 )
return - V_16 ;
if ( V_30 -> V_5 [ V_509 ] ) {
enum V_510 V_511 ;
V_511 = F_4 (
V_30 -> V_5 [ V_509 ] ) ;
switch ( V_511 ) {
case V_512 :
case V_513 :
case V_514 :
case V_515 :
F_81 ( V_502 , V_502 -> V_55 ,
V_511 ) ;
break;
default:
return - V_16 ;
}
} else if ( V_30 -> V_5 [ V_516 ] ) {
V_502 -> V_505 =
F_4 ( V_30 -> V_5 [ V_516 ] ) ;
if ( V_30 -> V_5 [ V_517 ] )
V_502 -> V_507 =
F_4 (
V_30 -> V_5 [ V_517 ] ) ;
if ( V_30 -> V_5 [ V_518 ] )
V_502 -> V_508 =
F_4 (
V_30 -> V_5 [ V_518 ] ) ;
}
if ( ! F_82 ( V_502 ) )
return - V_16 ;
if ( ! F_83 ( & V_7 -> V_18 , V_502 ,
V_62 ) )
return - V_16 ;
if ( ( V_502 -> V_505 == V_519 ||
V_502 -> V_505 == V_520 ) &&
! ( V_7 -> V_18 . V_51 & V_461 ) )
return - V_16 ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 ,
struct V_25 * V_521 ,
struct V_29 * V_30 )
{
struct V_501 V_502 ;
int V_8 ;
enum V_263 V_141 = V_500 ;
struct V_1 * V_17 = NULL ;
if ( V_521 )
V_17 = V_521 -> V_28 ;
if ( ! F_79 ( V_17 ) )
return - V_522 ;
if ( V_17 )
V_141 = V_17 -> V_141 ;
V_8 = F_80 ( V_7 , V_30 , & V_502 ) ;
if ( V_8 )
return V_8 ;
switch ( V_141 ) {
case V_142 :
case V_144 :
if ( ! F_85 ( & V_7 -> V_18 , & V_502 , V_141 ) ) {
V_8 = - V_16 ;
break;
}
if ( V_17 -> V_523 ) {
if ( ! V_521 || ! V_7 -> V_337 -> V_524 ||
! ( V_7 -> V_18 . V_283 &
V_525 ) ) {
V_8 = - V_526 ;
break;
}
if ( V_502 . V_55 != V_17 -> V_527 . V_55 ) {
V_8 = - V_526 ;
break;
}
V_8 = F_86 ( V_7 , V_521 , & V_502 ) ;
if ( V_8 )
break;
}
V_17 -> V_527 = V_502 ;
V_8 = 0 ;
break;
case V_145 :
V_8 = F_87 ( V_7 , V_17 , & V_502 ) ;
break;
case V_500 :
V_8 = F_88 ( V_7 , & V_502 ) ;
break;
default:
V_8 = - V_16 ;
}
return V_8 ;
}
static int F_89 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_19 = V_30 -> V_484 [ 1 ] ;
return F_84 ( V_7 , V_19 , V_30 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
const T_2 * V_528 ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( F_91 ( V_521 ) )
return - V_526 ;
if ( ! V_7 -> V_337 -> V_402 )
return - V_522 ;
if ( V_17 -> V_141 != V_530 )
return - V_522 ;
V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
return F_92 ( V_7 , V_521 , V_528 ) ;
}
static int F_93 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_25 * V_19 = NULL ;
struct V_1 * V_17 ;
int V_8 = 0 , V_531 = 0 ;
struct V_4 * V_532 ;
V_22 V_533 ;
T_2 V_291 = 0 , V_293 = 0 ;
V_22 V_295 = 0 , V_297 = 0 ;
T_2 V_299 = 0 ;
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
if ( V_30 -> V_5 [ V_284 ] )
V_8 = F_95 (
V_7 , F_23 ( V_30 -> V_5 [ V_284 ] ) ) ;
if ( V_8 )
return V_8 ;
if ( V_30 -> V_5 [ V_534 ] ) {
struct V_487 V_488 ;
struct V_4 * V_95 [ V_535 + 1 ] ;
if ( ! V_7 -> V_337 -> V_536 )
return - V_522 ;
if ( ! V_19 )
return - V_16 ;
if ( V_19 -> V_28 -> V_141 != V_142 &&
V_19 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! F_91 ( V_19 ) )
return - V_537 ;
F_39 (nl_txq_params,
info->attrs[NL80211_ATTR_WIPHY_TXQ_PARAMS],
rem_txq_params) {
V_8 = F_96 ( V_95 , V_535 ,
F_23 ( V_532 ) ,
F_24 ( V_532 ) ,
V_538 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 ( V_95 , & V_488 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_97 ( V_7 , V_19 ,
& V_488 ) ;
if ( V_8 )
return V_8 ;
}
}
if ( V_30 -> V_5 [ V_504 ] ) {
V_8 = F_84 (
V_7 ,
F_79 ( V_17 ) ? V_19 : NULL ,
V_30 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_539 ] ) {
struct V_1 * V_540 = V_17 ;
enum V_541 type ;
int V_105 , V_542 = 0 ;
if ( ! ( V_7 -> V_18 . V_283 & V_543 ) )
V_540 = NULL ;
if ( ! V_7 -> V_337 -> V_544 )
return - V_522 ;
V_105 = V_539 ;
type = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
if ( ! V_30 -> V_5 [ V_545 ] &&
( type != V_546 ) )
return - V_16 ;
if ( type != V_546 ) {
V_105 = V_545 ;
V_542 = F_4 ( V_30 -> V_5 [ V_105 ] ) ;
}
V_8 = F_98 ( V_7 , V_540 , type , V_542 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_30 -> V_5 [ V_342 ] &&
V_30 -> V_5 [ V_343 ] ) {
V_22 V_339 , V_340 ;
if ( ( ! V_7 -> V_18 . V_331 &&
! V_7 -> V_18 . V_333 ) ||
! V_7 -> V_337 -> V_547 )
return - V_522 ;
V_339 = F_4 ( V_30 -> V_5 [ V_342 ] ) ;
V_340 = F_4 ( V_30 -> V_5 [ V_343 ] ) ;
if ( ( ~ V_339 && ( V_339 & ~ V_7 -> V_18 . V_331 ) ) ||
( ~ V_340 && ( V_340 & ~ V_7 -> V_18 . V_333 ) ) )
return - V_16 ;
V_339 = V_339 & V_7 -> V_18 . V_331 ;
V_340 = V_340 & V_7 -> V_18 . V_333 ;
V_8 = F_99 ( V_7 , V_339 , V_340 ) ;
if ( V_8 )
return V_8 ;
}
V_533 = 0 ;
if ( V_30 -> V_5 [ V_290 ] ) {
V_291 = F_34 (
V_30 -> V_5 [ V_290 ] ) ;
if ( V_291 == 0 )
return - V_16 ;
V_533 |= V_548 ;
}
if ( V_30 -> V_5 [ V_292 ] ) {
V_293 = F_34 (
V_30 -> V_5 [ V_292 ] ) ;
if ( V_293 == 0 )
return - V_16 ;
V_533 |= V_549 ;
}
if ( V_30 -> V_5 [ V_294 ] ) {
V_295 = F_4 (
V_30 -> V_5 [ V_294 ] ) ;
if ( V_295 < 256 )
return - V_16 ;
if ( V_295 != ( V_22 ) - 1 ) {
V_295 &= ~ 0x1 ;
}
V_533 |= V_550 ;
}
if ( V_30 -> V_5 [ V_296 ] ) {
V_297 = F_4 (
V_30 -> V_5 [ V_296 ] ) ;
V_533 |= V_551 ;
}
if ( V_30 -> V_5 [ V_298 ] ) {
if ( V_30 -> V_5 [ V_552 ] )
return - V_16 ;
V_299 = F_34 (
V_30 -> V_5 [ V_298 ] ) ;
V_533 |= V_553 ;
}
if ( V_30 -> V_5 [ V_552 ] ) {
if ( ! ( V_7 -> V_18 . V_283 & V_554 ) )
return - V_522 ;
V_533 |= V_555 ;
}
if ( V_533 ) {
T_2 V_556 , V_557 ;
V_22 V_558 , V_559 ;
T_2 V_560 ;
if ( ! V_7 -> V_337 -> V_561 )
return - V_522 ;
V_556 = V_7 -> V_18 . V_291 ;
V_557 = V_7 -> V_18 . V_293 ;
V_558 = V_7 -> V_18 . V_295 ;
V_559 = V_7 -> V_18 . V_297 ;
V_560 = V_7 -> V_18 . V_299 ;
if ( V_533 & V_548 )
V_7 -> V_18 . V_291 = V_291 ;
if ( V_533 & V_549 )
V_7 -> V_18 . V_293 = V_293 ;
if ( V_533 & V_550 )
V_7 -> V_18 . V_295 = V_295 ;
if ( V_533 & V_551 )
V_7 -> V_18 . V_297 = V_297 ;
if ( V_533 & V_553 )
V_7 -> V_18 . V_299 = V_299 ;
V_8 = F_100 ( V_7 , V_533 ) ;
if ( V_8 ) {
V_7 -> V_18 . V_291 = V_556 ;
V_7 -> V_18 . V_293 = V_557 ;
V_7 -> V_18 . V_295 = V_558 ;
V_7 -> V_18 . V_297 = V_559 ;
V_7 -> V_18 . V_299 = V_560 ;
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
const struct V_501 * V_502 )
{
F_59 ( ! F_82 ( V_502 ) ) ;
if ( F_28 ( V_53 , V_504 ,
V_502 -> V_55 -> V_60 ) )
return - V_91 ;
switch ( V_502 -> V_505 ) {
case V_506 :
case V_562 :
case V_563 :
if ( F_28 ( V_53 , V_509 ,
F_102 ( V_502 ) ) )
return - V_91 ;
break;
default:
break;
}
if ( F_28 ( V_53 , V_516 , V_502 -> V_505 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_517 , V_502 -> V_507 ) )
return - V_91 ;
if ( V_502 -> V_508 &&
F_28 ( V_53 , V_518 , V_502 -> V_508 ) )
return - V_91 ;
return 0 ;
}
static int F_103 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_25 * V_521 = V_17 -> V_19 ;
void * V_275 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_564 ) ;
if ( ! V_275 )
return - 1 ;
if ( V_521 &&
( F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_60 ( V_53 , V_565 , V_521 -> V_566 ) ) )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_567 , V_17 -> V_141 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_529 , V_568 , F_105 ( V_17 ) ) ||
F_28 ( V_53 , V_285 ,
V_7 -> V_569 ^
( V_286 << 2 ) ) )
goto V_61;
if ( V_7 -> V_337 -> V_570 ) {
int V_477 ;
struct V_501 V_502 ;
V_477 = F_106 ( V_7 , V_17 , & V_502 ) ;
if ( V_477 == 0 ) {
if ( F_101 ( V_53 , & V_502 ) )
goto V_61;
}
}
if ( V_17 -> V_571 ) {
if ( F_51 ( V_53 , V_572 , V_17 -> V_571 , V_17 -> V_573 ) )
goto V_61;
}
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
static int F_107 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
int V_574 = 0 ;
int V_575 = 0 ;
int V_576 = V_34 -> args [ 0 ] ;
int V_577 = V_34 -> args [ 1 ] ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
F_14 () ;
F_6 (rdev, &cfg80211_rdev_list, list) {
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , F_16 ( V_32 -> V_44 ) ) )
continue;
if ( V_574 < V_576 ) {
V_574 ++ ;
continue;
}
V_575 = 0 ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_575 < V_577 ) {
V_575 ++ ;
continue;
}
if ( F_103 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_481 , V_482 ,
V_7 , V_17 ) < 0 ) {
goto V_578;
}
V_575 ++ ;
}
V_574 ++ ;
}
V_578:
F_20 () ;
V_34 -> args [ 0 ] = V_574 ;
V_34 -> args [ 1 ] = V_575 ;
return V_32 -> V_47 ;
}
static int F_108 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_31 * V_53 ;
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_103 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_7 , V_17 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_109 ( struct V_4 * V_580 , V_22 * V_581 )
{
struct V_4 * V_51 [ V_582 + 1 ] ;
int V_583 ;
* V_581 = 0 ;
if ( ! V_580 )
return - V_16 ;
if ( F_33 ( V_51 , V_582 ,
V_580 , V_584 ) )
return - V_16 ;
for ( V_583 = 1 ; V_583 <= V_582 ; V_583 ++ )
if ( V_51 [ V_583 ] )
* V_581 |= ( 1 << V_583 ) ;
return 0 ;
}
static int F_110 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_2 V_585 ,
enum V_263 V_141 )
{
if ( ! V_585 ) {
if ( V_19 && ( V_19 -> V_586 & V_587 ) )
return - V_526 ;
return 0 ;
}
switch ( V_141 ) {
case V_143 :
if ( V_7 -> V_18 . V_51 & V_588 )
return 0 ;
break;
case V_147 :
if ( V_7 -> V_18 . V_51 & V_589 )
return 0 ;
break;
default:
break;
}
return - V_522 ;
}
static int F_111 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_590 V_137 ;
int V_35 ;
enum V_263 V_591 , V_592 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
V_22 V_593 , * V_51 = NULL ;
bool V_594 = false ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_591 = V_592 = V_521 -> V_28 -> V_141 ;
if ( V_30 -> V_5 [ V_567 ] ) {
V_592 = F_4 ( V_30 -> V_5 [ V_567 ] ) ;
if ( V_591 != V_592 )
V_594 = true ;
if ( V_592 > V_595 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_596 ] ) {
struct V_1 * V_17 = V_521 -> V_28 ;
if ( V_592 != V_145 )
return - V_16 ;
if ( F_91 ( V_521 ) )
return - V_526 ;
F_112 ( V_17 ) ;
F_113 ( V_597 !=
V_598 ) ;
V_17 -> V_599 =
F_24 ( V_30 -> V_5 [ V_596 ] ) ;
memcpy ( V_17 -> V_573 , F_23 ( V_30 -> V_5 [ V_596 ] ) ,
V_17 -> V_599 ) ;
F_114 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_600 ] ) {
V_137 . V_585 = ! ! F_34 ( V_30 -> V_5 [ V_600 ] ) ;
V_594 = true ;
V_35 = F_110 ( V_7 , V_521 , V_137 . V_585 , V_592 ) ;
if ( V_35 )
return V_35 ;
} else {
V_137 . V_585 = - 1 ;
}
if ( V_30 -> V_5 [ V_601 ] ) {
if ( V_592 != V_500 )
return - V_16 ;
V_35 = F_109 ( V_30 -> V_5 [ V_601 ] ,
& V_593 ) ;
if ( V_35 )
return V_35 ;
V_51 = & V_593 ;
V_594 = true ;
}
if ( V_51 && ( * V_51 & V_602 ) &&
! ( V_7 -> V_18 . V_283 & V_603 ) )
return - V_522 ;
if ( V_594 )
V_35 = F_115 ( V_7 , V_521 , V_592 , V_51 , & V_137 ) ;
else
V_35 = 0 ;
if ( ! V_35 && V_137 . V_585 != - 1 )
V_521 -> V_28 -> V_585 = V_137 . V_585 ;
return V_35 ;
}
static int F_116 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_590 V_137 ;
struct V_1 * V_17 ;
struct V_31 * V_53 ;
int V_35 ;
enum V_263 type = V_604 ;
V_22 V_51 ;
F_117 ( V_7 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_565 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_567 ] ) {
type = F_4 ( V_30 -> V_5 [ V_567 ] ) ;
if ( type > V_595 )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_355 ||
! ( V_7 -> V_18 . V_345 & ( 1 << type ) ) )
return - V_522 ;
if ( type == V_605 && V_30 -> V_5 [ V_529 ] ) {
F_118 ( V_137 . V_606 , V_30 -> V_5 [ V_529 ] ,
V_568 ) ;
if ( ! F_119 ( V_137 . V_606 ) )
return - V_607 ;
}
if ( V_30 -> V_5 [ V_600 ] ) {
V_137 . V_585 = ! ! F_34 ( V_30 -> V_5 [ V_600 ] ) ;
V_35 = F_110 ( V_7 , NULL , V_137 . V_585 , type ) ;
if ( V_35 )
return V_35 ;
}
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_35 = F_109 ( type == V_500 ?
V_30 -> V_5 [ V_601 ] : NULL ,
& V_51 ) ;
if ( ! V_35 && ( V_51 & V_602 ) &&
! ( V_7 -> V_18 . V_283 & V_603 ) )
return - V_522 ;
V_17 = F_120 ( V_7 ,
F_23 ( V_30 -> V_5 [ V_565 ] ) ,
type , V_35 ? NULL : & V_51 , & V_137 ) ;
if ( F_17 ( V_17 ) ) {
F_75 ( V_53 ) ;
return F_18 ( V_17 ) ;
}
if ( V_30 -> V_5 [ V_608 ] )
V_17 -> V_609 = V_30 -> V_485 ;
switch ( type ) {
case V_145 :
if ( ! V_30 -> V_5 [ V_596 ] )
break;
F_112 ( V_17 ) ;
F_113 ( V_597 !=
V_598 ) ;
V_17 -> V_599 =
F_24 ( V_30 -> V_5 [ V_596 ] ) ;
memcpy ( V_17 -> V_573 , F_23 ( V_30 -> V_5 [ V_596 ] ) ,
V_17 -> V_599 ) ;
F_114 ( V_17 ) ;
break;
case V_605 :
F_121 ( & V_17 -> V_610 ) ;
F_122 ( & V_17 -> V_611 ) ;
F_123 ( & V_17 -> V_612 ) ;
F_122 ( & V_17 -> V_613 ) ;
F_123 ( & V_17 -> V_614 ) ;
V_17 -> V_21 = ++ V_7 -> V_13 ;
F_124 ( & V_17 -> V_615 , & V_7 -> V_616 ) ;
V_7 -> V_569 ++ ;
break;
default:
break;
}
if ( F_103 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_7 , V_17 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_125 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_617 )
return - V_522 ;
if ( ! V_17 -> V_19 )
V_30 -> V_484 [ 1 ] = NULL ;
return F_126 ( V_7 , V_17 ) ;
}
static int F_127 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_3 V_618 ;
if ( ! V_30 -> V_5 [ V_619 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_413 )
return - V_522 ;
V_618 = F_78 ( V_30 -> V_5 [ V_619 ] ) ;
return F_128 ( V_7 , V_521 , V_618 ) ;
}
static void F_129 ( void * V_159 , struct V_620 * V_137 )
{
struct V_4 * V_92 ;
struct V_621 * V_622 = V_159 ;
if ( ( V_137 -> V_92 &&
F_51 ( V_622 -> V_53 , V_121 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_622 -> V_53 , V_122 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_622 -> V_53 , V_124 ,
V_137 -> V_112 ) ) )
goto V_61;
V_92 = F_47 ( V_622 -> V_53 , V_129 ) ;
if ( ! V_92 )
goto V_61;
if ( ( V_137 -> V_92 &&
F_51 ( V_622 -> V_53 , V_106 ,
V_137 -> V_108 , V_137 -> V_92 ) ) ||
( V_137 -> V_50 &&
F_51 ( V_622 -> V_53 , V_109 ,
V_137 -> V_110 , V_137 -> V_50 ) ) ||
( V_137 -> V_112 &&
F_28 ( V_622 -> V_53 , V_111 ,
V_137 -> V_112 ) ) )
goto V_61;
if ( F_56 ( V_622 -> V_53 , V_123 , V_622 -> V_105 ) )
goto V_61;
F_48 ( V_622 -> V_53 , V_92 ) ;
return;
V_61:
V_622 -> error = 1 ;
}
static int F_130 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
int V_35 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 V_623 = 0 ;
const T_2 * V_624 = NULL ;
bool V_625 ;
struct V_621 V_622 = {
. error = 0 ,
} ;
void * V_275 ;
struct V_31 * V_53 ;
if ( V_30 -> V_5 [ V_123 ] )
V_623 = F_34 ( V_30 -> V_5 [ V_123 ] ) ;
if ( V_623 > 5 )
return - V_16 ;
if ( V_30 -> V_5 [ V_529 ] )
V_624 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_625 = ! ! V_624 ;
if ( V_30 -> V_5 [ V_127 ] ) {
V_22 V_626 = F_4 ( V_30 -> V_5 [ V_127 ] ) ;
if ( V_626 >= V_114 )
return - V_16 ;
if ( V_626 != V_627 &&
V_626 != V_628 )
return - V_16 ;
V_625 = V_626 == V_628 ;
}
if ( ! V_7 -> V_337 -> V_629 )
return - V_522 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_630 ) ;
if ( ! V_275 )
goto V_61;
V_622 . V_53 = V_53 ;
V_622 . V_105 = V_623 ;
if ( F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_56 ( V_53 , V_123 , V_623 ) )
goto V_61;
if ( V_624 &&
F_51 ( V_53 , V_529 , V_568 , V_624 ) )
goto V_61;
if ( V_625 && V_624 &&
! ( V_7 -> V_18 . V_51 & V_310 ) )
return - V_631 ;
V_35 = F_131 ( V_7 , V_521 , V_623 , V_625 , V_624 , & V_622 ,
F_129 ) ;
if ( V_35 )
goto V_632;
if ( V_622 . error )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_632:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_132 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_93 V_92 ;
int V_35 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 < 0 )
return - V_16 ;
if ( ! V_92 . V_98 && ! V_92 . V_100 )
return - V_16 ;
F_112 ( V_521 -> V_28 ) ;
if ( V_92 . V_98 ) {
if ( ! V_7 -> V_337 -> V_633 ) {
V_35 = - V_522 ;
goto V_578;
}
V_35 = F_42 ( V_521 -> V_28 ) ;
if ( V_35 )
goto V_578;
V_35 = F_133 ( V_7 , V_521 , V_92 . V_105 ,
V_92 . V_102 , V_92 . V_103 ) ;
if ( V_35 )
goto V_578;
#ifdef F_134
V_521 -> V_28 -> V_634 . V_635 = V_92 . V_105 ;
#endif
} else {
if ( V_92 . V_102 || ! V_92 . V_103 ) {
V_35 = - V_16 ;
goto V_578;
}
if ( ! V_7 -> V_337 -> V_636 ) {
V_35 = - V_522 ;
goto V_578;
}
V_35 = F_42 ( V_521 -> V_28 ) ;
if ( V_35 )
goto V_578;
V_35 = F_135 ( V_7 , V_521 , V_92 . V_105 ) ;
if ( V_35 )
goto V_578;
#ifdef F_134
V_521 -> V_28 -> V_634 . V_637 = V_92 . V_105 ;
#endif
}
V_578:
F_114 ( V_521 -> V_28 ) ;
return V_35 ;
}
static int F_136 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
int V_35 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_93 V_92 ;
const T_2 * V_624 = NULL ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_92 . V_107 . V_92 )
return - V_16 ;
if ( V_30 -> V_5 [ V_529 ] )
V_624 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_624 )
V_92 . type = V_628 ;
else
V_92 . type = V_627 ;
}
if ( V_92 . type != V_628 &&
V_92 . type != V_627 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_359 )
return - V_522 ;
if ( F_40 ( V_7 , & V_92 . V_107 , V_92 . V_105 ,
V_92 . type == V_628 ,
V_624 ) )
return - V_16 ;
F_112 ( V_521 -> V_28 ) ;
V_35 = F_42 ( V_521 -> V_28 ) ;
if ( ! V_35 )
V_35 = F_137 ( V_7 , V_521 , V_92 . V_105 ,
V_92 . type == V_628 ,
V_624 , & V_92 . V_107 ) ;
F_114 ( V_521 -> V_28 ) ;
return V_35 ;
}
static int F_138 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
int V_35 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 * V_624 = NULL ;
struct V_93 V_92 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_529 ] )
V_624 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( V_92 . type == - 1 ) {
if ( V_624 )
V_92 . type = V_628 ;
else
V_92 . type = V_627 ;
}
if ( V_92 . type != V_628 &&
V_92 . type != V_627 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_638 )
return - V_522 ;
F_112 ( V_521 -> V_28 ) ;
V_35 = F_42 ( V_521 -> V_28 ) ;
if ( V_92 . type == V_628 && V_624 &&
! ( V_7 -> V_18 . V_51 & V_310 ) )
V_35 = - V_631 ;
if ( ! V_35 )
V_35 = F_139 ( V_7 , V_521 , V_92 . V_105 ,
V_92 . type == V_628 ,
V_624 ) ;
#ifdef F_134
if ( ! V_35 ) {
if ( V_92 . V_105 == V_521 -> V_28 -> V_634 . V_635 )
V_521 -> V_28 -> V_634 . V_635 = - 1 ;
else if ( V_92 . V_105 == V_521 -> V_28 -> V_634 . V_637 )
V_521 -> V_28 -> V_634 . V_637 = - 1 ;
}
#endif
F_114 ( V_521 -> V_28 ) ;
return V_35 ;
}
static int F_140 ( struct V_4 * V_639 )
{
struct V_4 * V_45 ;
int V_640 = 0 , V_24 ;
F_39 (attr, nl_attr, tmp) {
if ( F_24 ( V_45 ) != V_568 )
return - V_16 ;
V_640 ++ ;
}
return V_640 ;
}
static struct V_641 * F_141 ( struct V_18 * V_18 ,
struct V_29 * V_30 )
{
enum V_642 V_643 ;
struct V_4 * V_45 ;
struct V_641 * V_644 ;
int V_153 = 0 , V_640 , V_24 ;
if ( ! V_18 -> V_452 )
return F_3 ( - V_522 ) ;
if ( ! V_30 -> V_5 [ V_645 ] )
return F_3 ( - V_16 ) ;
V_643 = F_4 ( V_30 -> V_5 [ V_645 ] ) ;
if ( V_643 != V_646 &&
V_643 != V_647 )
return F_3 ( - V_16 ) ;
if ( ! V_30 -> V_5 [ V_648 ] )
return F_3 ( - V_16 ) ;
V_640 = F_140 ( V_30 -> V_5 [ V_648 ] ) ;
if ( V_640 < 0 )
return F_3 ( V_640 ) ;
if ( V_640 > V_18 -> V_452 )
return F_3 ( - V_649 ) ;
V_644 = F_38 ( sizeof( * V_644 ) + ( sizeof( struct V_650 ) * V_640 ) ,
V_135 ) ;
if ( ! V_644 )
return F_3 ( - V_136 ) ;
F_39 (attr, info->attrs[NL80211_ATTR_MAC_ADDRS], tmp) {
memcpy ( V_644 -> V_651 [ V_153 ] . V_652 , F_23 ( V_45 ) , V_568 ) ;
V_153 ++ ;
}
V_644 -> V_653 = V_640 ;
V_644 -> V_643 = V_643 ;
return V_644 ;
}
static int F_142 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_641 * V_644 ;
int V_35 ;
if ( V_521 -> V_28 -> V_141 != V_142 &&
V_521 -> V_28 -> V_141 != V_144 )
return - V_522 ;
if ( ! V_521 -> V_28 -> V_523 )
return - V_16 ;
V_644 = F_141 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_644 ) )
return F_18 ( V_644 ) ;
V_35 = F_143 ( V_7 , V_521 , V_644 ) ;
F_41 ( V_644 ) ;
return V_35 ;
}
static int F_144 ( struct V_4 * V_5 [] ,
struct V_654 * V_655 )
{
bool V_656 = false ;
if ( ! F_22 ( V_5 [ V_657 ] ) ||
! F_22 ( V_5 [ V_658 ] ) ||
! F_22 ( V_5 [ V_659 ] ) ||
! F_22 ( V_5 [ V_660 ] ) )
return - V_16 ;
memset ( V_655 , 0 , sizeof( * V_655 ) ) ;
if ( V_5 [ V_661 ] ) {
V_655 -> V_662 = F_23 ( V_5 [ V_661 ] ) ;
V_655 -> V_663 = F_24 ( V_5 [ V_661 ] ) ;
if ( ! V_655 -> V_663 )
return - V_16 ;
V_656 = true ;
}
if ( V_5 [ V_657 ] ) {
V_655 -> V_664 = F_23 ( V_5 [ V_657 ] ) ;
V_655 -> V_665 = F_24 ( V_5 [ V_657 ] ) ;
V_656 = true ;
}
if ( ! V_656 )
return - V_16 ;
if ( V_5 [ V_658 ] ) {
V_655 -> V_666 = F_23 ( V_5 [ V_658 ] ) ;
V_655 -> V_667 = F_24 ( V_5 [ V_658 ] ) ;
}
if ( V_5 [ V_659 ] ) {
V_655 -> V_668 =
F_23 ( V_5 [ V_659 ] ) ;
V_655 -> V_669 =
F_24 ( V_5 [ V_659 ] ) ;
}
if ( V_5 [ V_660 ] ) {
V_655 -> V_670 =
F_23 ( V_5 [ V_660 ] ) ;
V_655 -> V_671 =
F_24 ( V_5 [ V_660 ] ) ;
}
if ( V_5 [ V_672 ] ) {
V_655 -> V_673 = F_23 ( V_5 [ V_672 ] ) ;
V_655 -> V_674 = F_24 ( V_5 [ V_672 ] ) ;
}
return 0 ;
}
static bool F_145 ( struct V_6 * V_7 ,
struct V_675 * V_137 )
{
struct V_1 * V_17 ;
bool V_477 = false ;
F_6 (wdev, &rdev->wdev_list, list) {
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
continue;
if ( ! V_17 -> V_527 . V_55 )
continue;
V_137 -> V_502 = V_17 -> V_527 ;
V_477 = true ;
break;
}
return V_477 ;
}
static bool F_146 ( struct V_6 * V_7 ,
enum V_676 V_677 ,
enum V_272 V_52 )
{
if ( V_677 > V_678 )
return false ;
switch ( V_52 ) {
case V_679 :
if ( ! ( V_7 -> V_18 . V_283 & V_680 ) &&
V_677 == V_681 )
return false ;
return true ;
case V_436 :
case V_682 :
if ( V_677 == V_681 )
return false ;
return true ;
default:
return false ;
}
}
static int F_147 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_675 V_137 ;
int V_35 ;
if ( V_521 -> V_28 -> V_141 != V_142 &&
V_521 -> V_28 -> V_141 != V_144 )
return - V_522 ;
if ( ! V_7 -> V_337 -> V_361 )
return - V_522 ;
if ( V_17 -> V_523 )
return - V_683 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_684 ] ||
! V_30 -> V_5 [ V_685 ] ||
! V_30 -> V_5 [ V_661 ] )
return - V_16 ;
V_35 = F_144 ( V_30 -> V_5 , & V_137 . V_686 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_523 =
F_4 ( V_30 -> V_5 [ V_684 ] ) ;
V_137 . V_687 =
F_4 ( V_30 -> V_5 [ V_685 ] ) ;
V_35 = F_148 ( V_7 , V_137 . V_523 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_572 ] ) {
V_137 . V_573 = F_23 ( V_30 -> V_5 [ V_572 ] ) ;
V_137 . V_571 =
F_24 ( V_30 -> V_5 [ V_572 ] ) ;
if ( V_137 . V_571 == 0 ||
V_137 . V_571 > V_597 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_688 ] ) {
V_137 . V_689 = F_4 (
V_30 -> V_5 [ V_688 ] ) ;
if ( V_137 . V_689 != V_690 &&
V_137 . V_689 != V_691 &&
V_137 . V_689 != V_692 )
return - V_16 ;
}
V_137 . V_693 = ! ! V_30 -> V_5 [ V_694 ] ;
if ( V_30 -> V_5 [ V_695 ] ) {
V_137 . V_677 = F_4 (
V_30 -> V_5 [ V_695 ] ) ;
if ( ! F_146 ( V_7 , V_137 . V_677 ,
V_682 ) )
return - V_16 ;
} else
V_137 . V_677 = V_696 ;
V_35 = F_149 ( V_7 , V_30 , & V_137 . V_697 ,
V_698 ) ;
if ( V_35 )
return V_35 ;
if ( V_30 -> V_5 [ V_699 ] ) {
if ( ! ( V_7 -> V_18 . V_283 & V_700 ) )
return - V_522 ;
V_137 . V_701 = F_78 (
V_30 -> V_5 [ V_699 ] ) ;
}
if ( V_30 -> V_5 [ V_702 ] ) {
if ( V_521 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_703 =
F_34 ( V_30 -> V_5 [ V_702 ] ) ;
if ( V_137 . V_703 > 127 )
return - V_16 ;
if ( V_137 . V_703 != 0 &&
! ( V_7 -> V_18 . V_283 & V_704 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_705 ] ) {
T_2 V_24 ;
if ( V_521 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_705 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_706 = V_24 ;
if ( V_137 . V_706 != 0 &&
! ( V_7 -> V_18 . V_283 & V_707 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_504 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_502 ) ;
if ( V_35 )
return V_35 ;
} else if ( V_17 -> V_527 . V_55 ) {
V_137 . V_502 = V_17 -> V_527 ;
} else if ( ! F_145 ( V_7 , & V_137 ) )
return - V_16 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_502 ,
V_17 -> V_141 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_645 ] ) {
V_137 . V_644 = F_141 ( & V_7 -> V_18 , V_30 ) ;
if ( F_17 ( V_137 . V_644 ) )
return F_18 ( V_137 . V_644 ) ;
}
if ( V_30 -> V_5 [ V_708 ] ) {
V_137 . V_709 =
F_34 ( V_30 -> V_5 [ V_708 ] ) ;
switch ( V_137 . V_709 ) {
case V_710 :
break;
case V_711 :
if ( ! ( V_7 -> V_18 . V_283 &
V_712 ) )
return - V_16 ;
break;
case V_713 :
if ( ! ( V_7 -> V_18 . V_283 &
V_714 ) )
return - V_16 ;
break;
default:
return - V_16 ;
}
} else {
V_137 . V_709 = V_710 ;
}
F_112 ( V_17 ) ;
V_35 = F_150 ( V_7 , V_521 , & V_137 ) ;
if ( ! V_35 ) {
V_17 -> V_527 = V_137 . V_502 ;
V_17 -> V_523 = V_137 . V_523 ;
V_17 -> V_502 = V_137 . V_502 ;
V_17 -> V_571 = V_137 . V_571 ;
memcpy ( V_17 -> V_573 , V_137 . V_573 , V_17 -> V_571 ) ;
}
F_114 ( V_17 ) ;
F_41 ( V_137 . V_644 ) ;
return V_35 ;
}
static int F_151 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_654 V_137 ;
int V_35 ;
if ( V_521 -> V_28 -> V_141 != V_142 &&
V_521 -> V_28 -> V_141 != V_144 )
return - V_522 ;
if ( ! V_7 -> V_337 -> V_715 )
return - V_522 ;
if ( ! V_17 -> V_523 )
return - V_16 ;
V_35 = F_144 ( V_30 -> V_5 , & V_137 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
V_35 = F_152 ( V_7 , V_521 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_153 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
return F_154 ( V_7 , V_521 , false ) ;
}
static int F_155 ( struct V_29 * V_30 ,
enum V_263 V_141 ,
struct V_716 * V_137 )
{
struct V_4 * V_51 [ V_717 + 1 ] ;
struct V_4 * V_580 ;
int V_583 ;
V_580 = V_30 -> V_5 [ V_718 ] ;
if ( V_580 ) {
struct V_719 * V_720 ;
V_720 = F_23 ( V_580 ) ;
V_137 -> V_721 = V_720 -> V_722 ;
V_137 -> V_723 = V_720 -> V_724 ;
V_137 -> V_723 &= V_137 -> V_721 ;
if ( ( V_137 -> V_721 |
V_137 -> V_723 ) & F_156 ( V_725 ) )
return - V_16 ;
return 0 ;
}
V_580 = V_30 -> V_5 [ V_726 ] ;
if ( ! V_580 )
return 0 ;
if ( F_33 ( V_51 , V_717 ,
V_580 , V_727 ) )
return - V_16 ;
switch ( V_141 ) {
case V_142 :
case V_143 :
case V_144 :
V_137 -> V_721 = F_156 ( V_728 ) |
F_156 ( V_729 ) |
F_156 ( V_730 ) |
F_156 ( V_731 ) ;
break;
case V_148 :
case V_147 :
V_137 -> V_721 = F_156 ( V_728 ) |
F_156 ( V_732 ) ;
break;
case V_145 :
V_137 -> V_721 = F_156 ( V_733 ) |
F_156 ( V_731 ) |
F_156 ( V_728 ) ;
default:
return - V_16 ;
}
for ( V_583 = 1 ; V_583 <= V_717 ; V_583 ++ ) {
if ( V_51 [ V_583 ] ) {
V_137 -> V_723 |= ( 1 << V_583 ) ;
if ( V_583 > V_734 )
return - V_16 ;
}
}
return 0 ;
}
static bool F_157 ( struct V_31 * V_53 , struct V_735 * V_30 ,
int V_45 )
{
struct V_4 * V_235 ;
V_22 V_255 ;
T_3 V_736 ;
V_235 = F_47 ( V_53 , V_45 ) ;
if ( ! V_235 )
return false ;
V_255 = F_158 ( V_30 ) ;
V_736 = V_255 < ( 1UL << 16 ) ? V_255 : 0 ;
if ( V_255 > 0 &&
F_28 ( V_53 , V_737 , V_255 ) )
return false ;
if ( V_736 > 0 &&
F_55 ( V_53 , V_738 , V_736 ) )
return false ;
if ( V_30 -> V_51 & V_739 ) {
if ( F_56 ( V_53 , V_740 , V_30 -> V_239 ) )
return false ;
if ( V_30 -> V_51 & V_741 &&
F_29 ( V_53 , V_742 ) )
return false ;
if ( V_30 -> V_51 & V_743 &&
F_29 ( V_53 , V_744 ) )
return false ;
} else if ( V_30 -> V_51 & V_745 ) {
if ( F_56 ( V_53 , V_746 , V_30 -> V_239 ) )
return false ;
if ( F_56 ( V_53 , V_747 , V_30 -> V_748 ) )
return false ;
if ( V_30 -> V_51 & V_741 &&
F_29 ( V_53 , V_742 ) )
return false ;
if ( V_30 -> V_51 & V_749 &&
F_29 ( V_53 , V_750 ) )
return false ;
if ( V_30 -> V_51 & V_751 &&
F_29 ( V_53 , V_752 ) )
return false ;
if ( V_30 -> V_51 & V_753 &&
F_29 ( V_53 , V_754 ) )
return false ;
if ( V_30 -> V_51 & V_743 &&
F_29 ( V_53 , V_744 ) )
return false ;
}
F_48 ( V_53 , V_235 ) ;
return true ;
}
static bool F_159 ( struct V_31 * V_53 , T_2 V_722 , T_6 * signal ,
int V_755 )
{
void * V_45 ;
int V_153 = 0 ;
if ( ! V_722 )
return true ;
V_45 = F_47 ( V_53 , V_755 ) ;
if ( ! V_45 )
return false ;
for ( V_153 = 0 ; V_153 < V_756 ; V_153 ++ ) {
if ( ! ( V_722 & F_156 ( V_153 ) ) )
continue;
if ( F_56 ( V_53 , V_153 , signal [ V_153 ] ) )
return false ;
}
F_48 ( V_53 , V_45 ) ;
return true ;
}
static int F_160 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 ,
struct V_6 * V_7 ,
struct V_25 * V_521 ,
const T_2 * V_624 , struct V_757 * V_758 )
{
void * V_275 ;
struct V_4 * V_759 , * V_760 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_761 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_624 ) ||
F_28 ( V_53 , V_285 , V_758 -> V_762 ) )
goto V_61;
V_759 = F_47 ( V_53 , V_763 ) ;
if ( ! V_759 )
goto V_61;
if ( ( V_758 -> V_764 & V_765 ) &&
F_28 ( V_53 , V_766 ,
V_758 -> V_767 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_768 ) &&
F_28 ( V_53 , V_769 ,
V_758 -> V_770 ) )
goto V_61;
if ( ( V_758 -> V_764 & ( V_771 |
V_772 ) ) &&
F_28 ( V_53 , V_773 ,
( V_22 ) V_758 -> V_774 ) )
goto V_61;
if ( ( V_758 -> V_764 & ( V_775 |
V_776 ) ) &&
F_28 ( V_53 , V_777 ,
( V_22 ) V_758 -> V_778 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_772 ) &&
F_104 ( V_53 , V_779 ,
V_758 -> V_774 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_776 ) &&
F_104 ( V_53 , V_780 ,
V_758 -> V_778 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_781 ) &&
F_55 ( V_53 , V_782 , V_758 -> V_783 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_784 ) &&
F_55 ( V_53 , V_785 , V_758 -> V_786 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_787 ) &&
F_56 ( V_53 , V_788 ,
V_758 -> V_789 ) )
goto V_61;
switch ( V_7 -> V_18 . V_790 ) {
case V_791 :
if ( ( V_758 -> V_764 & V_792 ) &&
F_56 ( V_53 , V_793 ,
V_758 -> signal ) )
goto V_61;
if ( ( V_758 -> V_764 & V_794 ) &&
F_56 ( V_53 , V_795 ,
V_758 -> V_796 ) )
goto V_61;
break;
default:
break;
}
if ( V_758 -> V_764 & V_797 ) {
if ( ! F_159 ( V_53 , V_758 -> V_798 ,
V_758 -> V_799 ,
V_800 ) )
goto V_61;
}
if ( V_758 -> V_764 & V_801 ) {
if ( ! F_159 ( V_53 , V_758 -> V_798 ,
V_758 -> V_802 ,
V_803 ) )
goto V_61;
}
if ( V_758 -> V_764 & V_804 ) {
if ( ! F_157 ( V_53 , & V_758 -> V_805 ,
V_806 ) )
goto V_61;
}
if ( V_758 -> V_764 & V_807 ) {
if ( ! F_157 ( V_53 , & V_758 -> V_808 ,
V_809 ) )
goto V_61;
}
if ( ( V_758 -> V_764 & V_810 ) &&
F_28 ( V_53 , V_811 ,
V_758 -> V_812 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_813 ) &&
F_28 ( V_53 , V_814 ,
V_758 -> V_815 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_816 ) &&
F_28 ( V_53 , V_817 ,
V_758 -> V_818 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_819 ) &&
F_28 ( V_53 , V_820 ,
V_758 -> V_821 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_822 ) &&
F_28 ( V_53 , V_823 ,
V_758 -> V_824 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_825 ) &&
F_28 ( V_53 , V_826 ,
V_758 -> V_827 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_828 ) &&
F_28 ( V_53 , V_829 ,
V_758 -> V_830 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_831 ) &&
F_28 ( V_53 , V_832 ,
V_758 -> V_833 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_834 ) &&
F_28 ( V_53 , V_835 ,
V_758 -> V_836 ) )
goto V_61;
if ( V_758 -> V_764 & V_837 ) {
V_760 = F_47 ( V_53 , V_838 ) ;
if ( ! V_760 )
goto V_61;
if ( ( ( V_758 -> V_760 . V_51 & V_839 ) &&
F_29 ( V_53 , V_840 ) ) ||
( ( V_758 -> V_760 . V_51 & V_841 ) &&
F_29 ( V_53 , V_842 ) ) ||
( ( V_758 -> V_760 . V_51 & V_843 ) &&
F_29 ( V_53 , V_844 ) ) ||
F_56 ( V_53 , V_845 ,
V_758 -> V_760 . V_687 ) ||
F_55 ( V_53 , V_846 ,
V_758 -> V_760 . V_523 ) )
goto V_61;
F_48 ( V_53 , V_760 ) ;
}
if ( ( V_758 -> V_764 & V_847 ) &&
F_51 ( V_53 , V_848 ,
sizeof( struct V_719 ) ,
& V_758 -> V_720 ) )
goto V_61;
if ( ( V_758 -> V_764 & V_849 ) &&
F_104 ( V_53 , V_850 ,
V_758 -> V_851 ) )
goto V_61;
F_48 ( V_53 , V_759 ) ;
if ( ( V_758 -> V_764 & V_852 ) &&
F_51 ( V_53 , V_658 , V_758 -> V_853 ,
V_758 -> V_854 ) )
goto V_61;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
static int F_161 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_757 V_758 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_624 [ V_568 ] ;
int V_855 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_17 -> V_19 ) {
V_35 = - V_16 ;
goto V_856;
}
if ( ! V_7 -> V_337 -> V_857 ) {
V_35 = - V_522 ;
goto V_856;
}
while ( 1 ) {
memset ( & V_758 , 0 , sizeof( V_758 ) ) ;
V_35 = F_162 ( V_7 , V_17 -> V_19 , V_855 ,
V_624 , & V_758 ) ;
if ( V_35 == - V_631 )
break;
if ( V_35 )
goto V_856;
if ( F_160 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_481 , V_482 ,
V_7 , V_17 -> V_19 , V_624 ,
& V_758 ) < 0 )
goto V_578;
V_855 ++ ;
}
V_578:
V_34 -> args [ 2 ] = V_855 ;
V_35 = V_32 -> V_47 ;
V_856:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_163 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_757 V_758 ;
struct V_31 * V_53 ;
T_2 * V_624 = NULL ;
int V_35 ;
memset ( & V_758 , 0 , sizeof( V_758 ) ) ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
V_624 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( ! V_7 -> V_337 -> V_858 )
return - V_522 ;
V_35 = F_164 ( V_7 , V_521 , V_624 , & V_758 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_160 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_7 , V_521 , V_624 , & V_758 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
int F_165 ( struct V_18 * V_18 ,
struct V_716 * V_137 ,
enum V_859 V_860 )
{
if ( V_137 -> V_861 != - 1 )
return - V_16 ;
if ( V_137 -> V_862 &&
! ( V_137 -> V_723 & F_156 ( V_732 ) ) )
return - V_16 ;
F_113 ( V_717 != 7 ) ;
switch ( V_860 ) {
case V_863 :
case V_864 :
if ( V_137 -> V_721 &
~ ( F_156 ( V_733 ) |
F_156 ( V_731 ) |
F_156 ( V_728 ) ) )
return - V_16 ;
break;
case V_865 :
case V_866 :
if ( ! ( V_137 -> V_723 & F_156 ( V_732 ) ) )
return - V_16 ;
V_137 -> V_721 &= ~ F_156 ( V_732 ) ;
break;
default:
if ( V_137 -> V_867 != V_868 )
return - V_16 ;
if ( V_137 -> V_830 )
return - V_16 ;
if ( V_137 -> V_869 & V_870 )
return - V_16 ;
}
if ( V_860 != V_865 &&
V_860 != V_866 ) {
if ( V_137 -> V_723 & F_156 ( V_732 ) )
return - V_16 ;
V_137 -> V_721 &= ~ F_156 ( V_732 ) ;
}
if ( V_860 != V_865 ) {
if ( V_137 -> V_869 & V_871 )
return - V_16 ;
if ( V_137 -> V_869 & V_872 )
return - V_16 ;
if ( V_137 -> V_873 )
return - V_16 ;
if ( V_137 -> V_874 || V_137 -> V_875 || V_137 -> V_876 )
return - V_16 ;
}
if ( V_860 != V_877 ) {
if ( V_137 -> V_878 )
return - V_16 ;
}
switch ( V_860 ) {
case V_879 :
if ( ! ( V_137 -> V_721 & F_156 ( V_728 ) ) )
return - V_522 ;
break;
case V_877 :
if ( V_137 -> V_721 &
~ ( F_156 ( V_728 ) |
F_156 ( V_733 ) |
F_156 ( V_880 ) |
F_156 ( V_729 ) |
F_156 ( V_730 ) |
F_156 ( V_731 ) ) )
return - V_16 ;
if ( ! ( V_18 -> V_283 & V_881 ) &&
V_137 -> V_721 &
( F_156 ( V_733 ) |
F_156 ( V_880 ) ) )
return - V_16 ;
break;
case V_882 :
case V_883 :
if ( V_137 -> V_721 & ~ F_156 ( V_728 ) )
return - V_16 ;
break;
case V_865 :
if ( V_137 -> V_721 & ~ ( F_156 ( V_728 ) |
F_156 ( V_730 ) ) )
return - V_16 ;
if ( V_137 -> V_723 & F_156 ( V_728 ) &&
! V_137 -> V_873 )
return - V_16 ;
break;
case V_866 :
return - V_16 ;
case V_863 :
if ( V_137 -> V_869 & V_870 )
return - V_16 ;
break;
case V_864 :
if ( V_137 -> V_867 != V_868 )
return - V_16 ;
break;
}
return 0 ;
}
static struct V_25 * F_166 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_4 * V_884 = V_30 -> V_5 [ V_885 ] ;
struct V_25 * V_886 ;
int V_477 ;
if ( ! V_884 )
return NULL ;
V_886 = F_167 ( F_94 ( V_30 ) , F_4 ( V_884 ) ) ;
if ( ! V_886 )
return F_3 ( - V_23 ) ;
if ( ! V_886 -> V_28 || V_886 -> V_28 -> V_18 != & V_7 -> V_18 ) {
V_477 = - V_16 ;
goto error;
}
if ( V_886 -> V_28 -> V_141 != V_143 &&
V_886 -> V_28 -> V_141 != V_142 &&
V_886 -> V_28 -> V_141 != V_144 ) {
V_477 = - V_16 ;
goto error;
}
if ( ! F_91 ( V_886 ) ) {
V_477 = - V_537 ;
goto error;
}
return V_886 ;
error:
F_168 ( V_886 ) ;
return F_3 ( V_477 ) ;
}
static int F_169 ( struct V_29 * V_30 ,
struct V_716 * V_137 )
{
struct V_4 * V_95 [ V_887 + 1 ] ;
struct V_4 * V_580 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_888 ] )
return 0 ;
V_580 = V_30 -> V_5 [ V_888 ] ;
V_35 = F_33 ( V_95 , V_887 , V_580 ,
V_889 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_890 ] )
V_137 -> V_891 = F_34 (
V_95 [ V_890 ] ) ;
if ( V_137 -> V_891 & ~ V_892 )
return - V_16 ;
if ( V_95 [ V_893 ] )
V_137 -> V_894 = F_34 ( V_95 [ V_893 ] ) ;
if ( V_137 -> V_894 & ~ V_895 )
return - V_16 ;
V_137 -> V_869 |= V_871 ;
return 0 ;
}
static int F_170 ( struct V_29 * V_30 ,
struct V_716 * V_137 )
{
if ( V_30 -> V_5 [ V_896 ] ) {
V_137 -> V_897 =
F_23 ( V_30 -> V_5 [ V_896 ] ) ;
V_137 -> V_898 =
F_24 ( V_30 -> V_5 [ V_896 ] ) ;
if ( V_137 -> V_898 < 2 )
return - V_16 ;
if ( V_137 -> V_898 % 2 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_899 ] ) {
V_137 -> V_900 =
F_23 ( V_30 -> V_5 [ V_899 ] ) ;
V_137 -> V_901 =
F_24 ( V_30 -> V_5 [ V_899 ] ) ;
if ( V_137 -> V_901 < 2 ||
V_137 -> V_901 > 253 )
return - V_16 ;
}
return 0 ;
}
static int F_171 ( struct V_29 * V_30 ,
struct V_716 * V_137 )
{
int V_35 ;
if ( V_30 -> V_5 [ V_902 ] )
V_137 -> V_862 = F_78 ( V_30 -> V_5 [ V_902 ] ) ;
if ( V_30 -> V_5 [ V_903 ] )
V_137 -> V_875 =
F_23 ( V_30 -> V_5 [ V_903 ] ) ;
if ( V_30 -> V_5 [ V_904 ] )
V_137 -> V_876 =
F_23 ( V_30 -> V_5 [ V_904 ] ) ;
V_35 = F_170 ( V_30 , V_137 ) ;
if ( V_35 )
return V_35 ;
return F_169 ( V_30 , V_137 ) ;
}
static int F_172 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_716 V_137 ;
T_2 * V_624 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_861 = - 1 ;
if ( ! V_7 -> V_337 -> V_905 )
return - V_522 ;
if ( V_30 -> V_5 [ V_906 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
V_624 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( V_30 -> V_5 [ V_907 ] ) {
V_137 . V_873 =
F_23 ( V_30 -> V_5 [ V_907 ] ) ;
V_137 . V_908 =
F_24 ( V_30 -> V_5 [ V_907 ] ) ;
}
if ( V_30 -> V_5 [ V_909 ] ) {
V_137 . V_910 =
F_78 ( V_30 -> V_5 [ V_909 ] ) ;
V_137 . V_869 |= V_872 ;
}
if ( V_30 -> V_5 [ V_911 ] ) {
V_137 . V_874 =
F_23 ( V_30 -> V_5 [ V_911 ] ) ;
V_137 . V_912 =
F_24 ( V_30 -> V_5 [ V_911 ] ) ;
}
if ( V_30 -> V_5 [ V_913 ] )
return - V_16 ;
if ( F_155 ( V_30 , V_521 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_914 ] ) {
V_137 . V_867 =
F_34 ( V_30 -> V_5 [ V_914 ] ) ;
if ( V_137 . V_867 >= V_915 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_916 ] ) {
V_137 . V_789 =
F_34 ( V_30 -> V_5 [ V_916 ] ) ;
if ( V_137 . V_789 >= V_917 )
return - V_16 ;
V_137 . V_869 |= V_870 ;
}
if ( V_30 -> V_5 [ V_918 ] ) {
enum V_919 V_920 = F_4 (
V_30 -> V_5 [ V_918 ] ) ;
if ( V_920 <= V_921 ||
V_920 > V_922 )
return - V_16 ;
V_137 . V_830 = V_920 ;
}
V_35 = F_171 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_137 . V_878 = F_166 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_878 ) )
return F_18 ( V_137 . V_878 ) ;
switch ( V_521 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
case V_148 :
case V_147 :
case V_146 :
case V_145 :
break;
default:
V_35 = - V_522 ;
goto V_923;
}
V_35 = F_173 ( V_7 , V_521 , V_624 , & V_137 ) ;
V_923:
if ( V_137 . V_878 )
F_168 ( V_137 . V_878 ) ;
return V_35 ;
}
static int F_174 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
int V_35 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_716 V_137 ;
T_2 * V_624 = NULL ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_7 -> V_337 -> V_363 )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_913 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_907 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_906 ] &&
! V_30 -> V_5 [ V_902 ] )
return - V_16 ;
V_624 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_137 . V_873 =
F_23 ( V_30 -> V_5 [ V_907 ] ) ;
V_137 . V_908 =
F_24 ( V_30 -> V_5 [ V_907 ] ) ;
V_137 . V_861 =
F_78 ( V_30 -> V_5 [ V_913 ] ) ;
if ( V_30 -> V_5 [ V_902 ] )
V_137 . V_862 = F_78 ( V_30 -> V_5 [ V_902 ] ) ;
else
V_137 . V_862 = F_78 ( V_30 -> V_5 [ V_906 ] ) ;
if ( ! V_137 . V_862 || V_137 . V_862 > V_924 )
return - V_16 ;
if ( V_30 -> V_5 [ V_909 ] ) {
V_137 . V_910 =
F_78 ( V_30 -> V_5 [ V_909 ] ) ;
V_137 . V_869 |= V_872 ;
}
if ( V_30 -> V_5 [ V_911 ] ) {
V_137 . V_874 =
F_23 ( V_30 -> V_5 [ V_911 ] ) ;
V_137 . V_912 =
F_24 ( V_30 -> V_5 [ V_911 ] ) ;
}
if ( V_30 -> V_5 [ V_903 ] )
V_137 . V_875 =
F_23 ( V_30 -> V_5 [ V_903 ] ) ;
if ( V_30 -> V_5 [ V_904 ] )
V_137 . V_876 =
F_23 ( V_30 -> V_5 [ V_904 ] ) ;
if ( V_30 -> V_5 [ V_925 ] ) {
V_137 . V_926 = true ;
V_137 . V_927 =
F_34 ( V_30 -> V_5 [ V_925 ] ) ;
}
if ( V_30 -> V_5 [ V_914 ] ) {
V_137 . V_867 =
F_34 ( V_30 -> V_5 [ V_914 ] ) ;
if ( V_137 . V_867 >= V_915 )
return - V_16 ;
}
V_35 = F_170 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_169 ( V_30 , & V_137 ) ;
if ( V_35 )
return V_35 ;
if ( F_155 ( V_30 , V_521 -> V_28 -> V_141 , & V_137 ) )
return - V_16 ;
F_113 ( V_717 != 7 ) ;
switch ( V_521 -> V_28 -> V_141 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! ( V_7 -> V_18 . V_51 & V_314 ) ||
! ( V_137 . V_723 & F_156 ( V_730 ) ) )
V_137 . V_869 &= ~ V_871 ;
if ( ( V_137 . V_723 & F_156 ( V_732 ) ) ||
V_30 -> V_5 [ V_902 ] )
return - V_16 ;
V_137 . V_721 &= ~ F_156 ( V_732 ) ;
if ( ! ( V_7 -> V_18 . V_283 &
V_881 ) &&
V_137 . V_721 &
( F_156 ( V_733 ) |
F_156 ( V_880 ) ) )
return - V_16 ;
V_137 . V_878 = F_166 ( V_30 , V_7 ) ;
if ( F_17 ( V_137 . V_878 ) )
return F_18 ( V_137 . V_878 ) ;
break;
case V_145 :
V_137 . V_869 &= ~ V_871 ;
if ( V_137 . V_721 & F_156 ( V_880 ) )
return - V_16 ;
if ( ( V_137 . V_723 & F_156 ( V_732 ) ) ||
V_30 -> V_5 [ V_902 ] )
return - V_16 ;
break;
case V_147 :
case V_148 :
V_137 . V_869 &= ~ V_871 ;
if ( V_137 . V_721 &
( F_156 ( V_880 ) |
F_156 ( V_733 ) ) )
return - V_16 ;
if ( ! ( V_137 . V_723 & F_156 ( V_732 ) ) )
return - V_16 ;
if ( ! ( V_7 -> V_18 . V_51 & V_318 ) )
return - V_522 ;
if ( ! ( V_7 -> V_18 . V_51 & V_320 ) )
return - V_522 ;
V_137 . V_721 &= ~ F_156 ( V_728 ) ;
break;
default:
return - V_522 ;
}
V_35 = F_175 ( V_7 , V_521 , V_624 , & V_137 ) ;
if ( V_137 . V_878 )
F_168 ( V_137 . V_878 ) ;
return V_35 ;
}
static int F_176 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 * V_624 = NULL ;
if ( V_30 -> V_5 [ V_529 ] )
V_624 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( V_521 -> V_28 -> V_141 != V_142 &&
V_521 -> V_28 -> V_141 != V_143 &&
V_521 -> V_28 -> V_141 != V_145 &&
V_521 -> V_28 -> V_141 != V_144 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_928 )
return - V_522 ;
return F_177 ( V_7 , V_521 , V_624 ) ;
}
static int F_178 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_521 ,
T_2 * V_929 , T_2 * V_930 ,
struct V_931 * V_932 )
{
void * V_275 ;
struct V_4 * V_933 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_761 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_929 ) ||
F_51 ( V_53 , V_934 , V_568 , V_930 ) ||
F_28 ( V_53 , V_285 , V_932 -> V_762 ) )
goto V_61;
V_933 = F_47 ( V_53 , V_935 ) ;
if ( ! V_933 )
goto V_61;
if ( ( V_932 -> V_764 & V_936 ) &&
F_28 ( V_53 , V_937 ,
V_932 -> V_938 ) )
goto V_61;
if ( ( ( V_932 -> V_764 & V_939 ) &&
F_28 ( V_53 , V_940 , V_932 -> V_941 ) ) ||
( ( V_932 -> V_764 & V_942 ) &&
F_28 ( V_53 , V_943 ,
V_932 -> V_944 ) ) ||
( ( V_932 -> V_764 & V_945 ) &&
F_28 ( V_53 , V_946 ,
V_932 -> V_947 ) ) ||
( ( V_932 -> V_764 & V_948 ) &&
F_56 ( V_53 , V_949 ,
V_932 -> V_51 ) ) ||
( ( V_932 -> V_764 & V_950 ) &&
F_28 ( V_53 , V_951 ,
V_932 -> V_952 ) ) ||
( ( V_932 -> V_764 & V_953 ) &&
F_56 ( V_53 , V_954 ,
V_932 -> V_955 ) ) )
goto V_61;
F_48 ( V_53 , V_933 ) ;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
static int F_179 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_931 V_932 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
T_2 V_929 [ V_568 ] ;
T_2 V_930 [ V_568 ] ;
int V_956 = V_34 -> args [ 2 ] ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_7 -> V_337 -> V_957 ) {
V_35 = - V_522 ;
goto V_856;
}
if ( V_17 -> V_141 != V_145 ) {
V_35 = - V_522 ;
goto V_856;
}
while ( 1 ) {
V_35 = F_180 ( V_7 , V_17 -> V_19 , V_956 , V_929 ,
V_930 , & V_932 ) ;
if ( V_35 == - V_631 )
break;
if ( V_35 )
goto V_856;
if ( F_178 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_481 , V_482 ,
V_17 -> V_19 , V_929 , V_930 ,
& V_932 ) < 0 )
goto V_578;
V_956 ++ ;
}
V_578:
V_34 -> args [ 2 ] = V_956 ;
V_35 = V_32 -> V_47 ;
V_856:
F_21 ( V_7 ) ;
return V_35 ;
}
static int F_181 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
int V_35 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_931 V_932 ;
struct V_31 * V_53 ;
T_2 * V_929 = NULL ;
T_2 V_930 [ V_568 ] ;
memset ( & V_932 , 0 , sizeof( V_932 ) ) ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
V_929 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( ! V_7 -> V_337 -> V_958 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_145 )
return - V_522 ;
V_35 = F_182 ( V_7 , V_521 , V_929 , V_930 , & V_932 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
if ( F_178 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_521 , V_929 , V_930 , & V_932 ) < 0 ) {
F_75 ( V_53 ) ;
return - V_91 ;
}
return F_76 ( V_53 , V_30 ) ;
}
static int F_183 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 * V_929 = NULL ;
T_2 * V_930 = NULL ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_934 ] )
return - V_16 ;
V_929 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_930 = F_23 ( V_30 -> V_5 [ V_934 ] ) ;
if ( ! V_7 -> V_337 -> V_959 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_145 )
return - V_522 ;
return F_184 ( V_7 , V_521 , V_929 , V_930 ) ;
}
static int F_185 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 * V_929 = NULL ;
T_2 * V_930 = NULL ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_934 ] )
return - V_16 ;
V_929 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_930 = F_23 ( V_30 -> V_5 [ V_934 ] ) ;
if ( ! V_7 -> V_337 -> V_365 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_145 )
return - V_522 ;
return F_186 ( V_7 , V_521 , V_929 , V_930 ) ;
}
static int F_187 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 * V_929 = NULL ;
if ( V_30 -> V_5 [ V_529 ] )
V_929 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( ! V_7 -> V_337 -> V_960 )
return - V_522 ;
return F_188 ( V_7 , V_521 , V_929 ) ;
}
static int F_189 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_961 V_137 ;
int V_35 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_962 = - 1 ;
V_137 . V_963 = - 1 ;
V_137 . V_964 = - 1 ;
V_137 . V_965 = - 1 ;
V_137 . V_966 = - 1 ;
V_137 . V_703 = - 1 ;
V_137 . V_706 = - 1 ;
if ( V_30 -> V_5 [ V_967 ] )
V_137 . V_962 =
F_34 ( V_30 -> V_5 [ V_967 ] ) ;
if ( V_30 -> V_5 [ V_968 ] )
V_137 . V_963 =
F_34 ( V_30 -> V_5 [ V_968 ] ) ;
if ( V_30 -> V_5 [ V_969 ] )
V_137 . V_964 =
F_34 ( V_30 -> V_5 [ V_969 ] ) ;
if ( V_30 -> V_5 [ V_970 ] ) {
V_137 . V_971 =
F_23 ( V_30 -> V_5 [ V_970 ] ) ;
V_137 . V_972 =
F_24 ( V_30 -> V_5 [ V_970 ] ) ;
}
if ( V_30 -> V_5 [ V_973 ] )
V_137 . V_965 = ! ! F_34 ( V_30 -> V_5 [ V_973 ] ) ;
if ( V_30 -> V_5 [ V_974 ] )
V_137 . V_966 =
F_78 ( V_30 -> V_5 [ V_974 ] ) ;
if ( V_30 -> V_5 [ V_702 ] ) {
if ( V_521 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_137 . V_703 =
F_190 ( V_30 -> V_5 [ V_702 ] ) ;
if ( V_137 . V_703 < 0 )
return - V_16 ;
if ( V_137 . V_703 != 0 &&
! ( V_7 -> V_18 . V_283 & V_704 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_705 ] ) {
T_2 V_24 ;
if ( V_521 -> V_28 -> V_141 != V_144 )
return - V_16 ;
V_24 = F_34 ( V_30 -> V_5 [ V_705 ] ) ;
if ( V_24 > 1 )
return - V_16 ;
V_137 . V_706 = V_24 ;
if ( V_137 . V_706 &&
! ( V_7 -> V_18 . V_283 & V_707 ) )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_369 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_142 &&
V_521 -> V_28 -> V_141 != V_144 )
return - V_522 ;
F_112 ( V_17 ) ;
V_35 = F_191 ( V_7 , V_521 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_192 ( struct V_4 * V_95 [] ,
struct V_975 * V_976 )
{
struct V_977 * V_978 = & V_976 -> V_978 ;
struct V_979 * V_980 = & V_976 -> V_980 ;
if ( ! V_95 [ V_981 ] )
return - V_16 ;
if ( ! V_95 [ V_982 ] )
return - V_16 ;
if ( ! V_95 [ V_983 ] )
return - V_16 ;
if ( ! V_95 [ V_984 ] )
return - V_16 ;
if ( ! V_95 [ V_985 ] )
return - V_16 ;
V_976 -> V_51 = F_4 ( V_95 [ V_981 ] ) ;
V_978 -> V_986 =
F_4 ( V_95 [ V_982 ] ) ;
V_978 -> V_987 =
F_4 ( V_95 [ V_983 ] ) ;
V_978 -> V_988 =
F_4 ( V_95 [ V_984 ] ) ;
V_980 -> V_989 =
F_4 ( V_95 [ V_985 ] ) ;
if ( V_95 [ V_990 ] )
V_980 -> V_991 =
F_4 ( V_95 [ V_990 ] ) ;
if ( V_95 [ V_992 ] )
V_976 -> V_74 =
F_4 ( V_95 [ V_992 ] ) ;
return 0 ;
}
static int F_193 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
char * V_138 = NULL ;
enum V_993 V_994 ;
if ( F_194 ( ! F_195 ( V_995 ) ) )
return - V_996 ;
if ( V_30 -> V_5 [ V_997 ] )
V_994 =
F_4 ( V_30 -> V_5 [ V_997 ] ) ;
else
V_994 = V_998 ;
switch ( V_994 ) {
case V_998 :
case V_999 :
if ( ! V_30 -> V_5 [ V_1000 ] )
return - V_16 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
return F_196 ( V_138 , V_994 ) ;
case V_1001 :
return F_197 () ;
default:
return - V_16 ;
}
}
static int F_198 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_1002 V_1003 ;
int V_35 = 0 ;
void * V_275 ;
struct V_4 * V_933 ;
struct V_31 * V_53 ;
if ( V_17 -> V_141 != V_145 )
return - V_522 ;
if ( ! V_7 -> V_337 -> V_1004 )
return - V_522 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1005 )
memcpy ( & V_1003 , & V_1006 , sizeof( V_1003 ) ) ;
else
V_35 = F_199 ( V_7 , V_521 , & V_1003 ) ;
F_114 ( V_17 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1007 ) ;
if ( ! V_275 )
goto V_578;
V_933 = F_47 ( V_53 , V_1008 ) ;
if ( ! V_933 )
goto V_61;
if ( F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_55 ( V_53 , V_1009 ,
V_1003 . V_1010 ) ||
F_55 ( V_53 , V_1011 ,
V_1003 . V_1012 ) ||
F_55 ( V_53 , V_1013 ,
V_1003 . V_1014 ) ||
F_55 ( V_53 , V_1015 ,
V_1003 . V_1016 ) ||
F_56 ( V_53 , V_1017 ,
V_1003 . V_1018 ) ||
F_56 ( V_53 , V_1019 ,
V_1003 . V_1020 ) ||
F_56 ( V_53 , V_1021 ,
V_1003 . V_1022 ) ||
F_56 ( V_53 , V_1023 ,
V_1003 . V_1024 ) ||
F_28 ( V_53 , V_1025 ,
V_1003 . V_1026 ) ||
F_56 ( V_53 , V_1027 ,
V_1003 . V_1028 ) ||
F_28 ( V_53 , V_1029 ,
V_1003 . V_1030 ) ||
F_55 ( V_53 , V_1031 ,
V_1003 . V_1032 ) ||
F_28 ( V_53 , V_1033 ,
V_1003 . V_1034 ) ||
F_55 ( V_53 , V_1035 ,
V_1003 . V_1036 ) ||
F_55 ( V_53 , V_1037 ,
V_1003 . V_1038 ) ||
F_55 ( V_53 , V_1039 ,
V_1003 . V_1040 ) ||
F_56 ( V_53 , V_1041 ,
V_1003 . V_1042 ) ||
F_55 ( V_53 , V_1043 ,
V_1003 . V_1044 ) ||
F_56 ( V_53 , V_1045 ,
V_1003 . V_1046 ) ||
F_56 ( V_53 , V_1047 ,
V_1003 . V_1048 ) ||
F_28 ( V_53 , V_1049 ,
V_1003 . V_1050 ) ||
F_28 ( V_53 , V_1051 ,
V_1003 . V_966 ) ||
F_28 ( V_53 , V_1052 ,
V_1003 . V_1053 ) ||
F_55 ( V_53 , V_1054 ,
V_1003 . V_1055 ) ||
F_55 ( V_53 , V_1056 ,
V_1003 . V_1057 ) ||
F_28 ( V_53 , V_1058 ,
V_1003 . V_1059 ) ||
F_55 ( V_53 , V_1060 ,
V_1003 . V_1061 ) ||
F_28 ( V_53 , V_1062 ,
V_1003 . V_1063 ) )
goto V_61;
F_48 ( V_53 , V_933 ) ;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
V_578:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_200 ( struct V_29 * V_30 ,
struct V_1002 * V_1064 ,
V_22 * V_1065 )
{
struct V_4 * V_95 [ V_1066 + 1 ] ;
V_22 V_722 = 0 ;
#define F_201 ( V_95 , V_1064 , T_7 , T_8 , V_168 , V_722 , V_45 , T_9 ) \
do { \
if (tb[attr]) { \
if (fn(tb[attr]) < min || fn(tb[attr]) > max) \
return -EINVAL; \
cfg->param = fn(tb[attr]); \
mask |= (1 << (attr - 1)); \
} \
} while (0)
if ( ! V_30 -> V_5 [ V_1008 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1066 ,
V_30 -> V_5 [ V_1008 ] ,
V_1067 ) )
return - V_16 ;
F_113 ( V_1066 > 32 ) ;
F_201 ( V_95 , V_1064 , V_1010 , 1 , 255 ,
V_722 , V_1009 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1012 , 1 , 255 ,
V_722 , V_1011 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1014 , 1 , 255 ,
V_722 , V_1013 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1016 , 0 , 255 ,
V_722 , V_1015 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1018 , 0 , 16 ,
V_722 , V_1017 ,
F_34 ) ;
F_201 ( V_95 , V_1064 , V_1020 , 1 , 255 ,
V_722 , V_1019 , F_34 ) ;
F_201 ( V_95 , V_1064 , V_1022 , 1 , 255 ,
V_722 , V_1021 ,
F_34 ) ;
F_201 ( V_95 , V_1064 , V_1024 , 0 , 1 ,
V_722 , V_1023 ,
F_34 ) ;
F_201 ( V_95 , V_1064 , V_1026 ,
1 , 255 , V_722 ,
V_1025 ,
F_4 ) ;
F_201 ( V_95 , V_1064 , V_1028 , 0 , 255 ,
V_722 , V_1027 ,
F_34 ) ;
F_201 ( V_95 , V_1064 , V_1030 , 1 , 65535 ,
V_722 , V_1029 ,
F_4 ) ;
F_201 ( V_95 , V_1064 , V_1032 , 1 , 65535 ,
V_722 , V_1031 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1034 ,
1 , 65535 , V_722 ,
V_1033 ,
F_4 ) ;
F_201 ( V_95 , V_1064 , V_1036 ,
1 , 65535 , V_722 ,
V_1035 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1038 ,
1 , 65535 , V_722 ,
V_1037 ,
F_78 ) ;
F_201 ( V_95 , V_1064 ,
V_1040 ,
1 , 65535 , V_722 ,
V_1039 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1042 , 0 , 4 ,
V_722 , V_1041 ,
F_34 ) ;
F_201 ( V_95 , V_1064 , V_1044 , 1 , 65535 ,
V_722 , V_1043 ,
F_78 ) ;
F_201 ( V_95 , V_1064 ,
V_1046 , 0 , 1 ,
V_722 , V_1045 ,
F_34 ) ;
F_201 ( V_95 , V_1064 , V_1048 , 0 , 1 ,
V_722 , V_1047 ,
F_34 ) ;
F_201 ( V_95 , V_1064 , V_1050 , - 255 , 0 ,
V_722 , V_1049 ,
V_1068 ) ;
F_201 ( V_95 , V_1064 , V_966 , 0 , 16 ,
V_722 , V_1051 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1053 ,
1 , 65535 , V_722 ,
V_1052 ,
F_4 ) ;
F_201 ( V_95 , V_1064 , V_1055 , 1 , 65535 ,
V_722 , V_1054 ,
F_78 ) ;
F_201 ( V_95 , V_1064 ,
V_1057 ,
1 , 65535 , V_722 ,
V_1056 ,
F_78 ) ;
F_201 ( V_95 , V_1064 , V_1059 ,
V_1069 ,
V_922 ,
V_722 , V_1058 ,
F_4 ) ;
F_201 ( V_95 , V_1064 , V_1061 ,
0 , 65535 , V_722 ,
V_1060 , F_78 ) ;
F_201 ( V_95 , V_1064 , V_1063 , 1 , 0xffffffff ,
V_722 , V_1062 ,
F_4 ) ;
if ( V_1065 )
* V_1065 = V_722 ;
return 0 ;
#undef F_201
}
static int F_202 ( struct V_29 * V_30 ,
struct V_1070 * V_1071 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_4 * V_95 [ V_1072 + 1 ] ;
if ( ! V_30 -> V_5 [ V_1073 ] )
return - V_16 ;
if ( F_33 ( V_95 , V_1072 ,
V_30 -> V_5 [ V_1073 ] ,
V_1074 ) )
return - V_16 ;
if ( V_95 [ V_1075 ] )
V_1071 -> V_1076 =
( F_34 ( V_95 [ V_1075 ] ) ) ?
V_1077 :
V_1078 ;
if ( V_95 [ V_1079 ] )
V_1071 -> V_1080 =
( F_34 ( V_95 [ V_1079 ] ) ) ?
V_1081 :
V_1082 ;
if ( V_95 [ V_1083 ] )
V_1071 -> V_1084 =
( F_34 ( V_95 [ V_1083 ] ) ) ?
V_1085 :
V_1086 ;
if ( V_95 [ V_1087 ] ) {
struct V_4 * V_1088 =
V_95 [ V_1087 ] ;
if ( ! F_22 ( V_1088 ) )
return - V_16 ;
V_1071 -> V_1089 = F_23 ( V_1088 ) ;
V_1071 -> V_1090 = F_24 ( V_1088 ) ;
}
if ( V_95 [ V_1091 ] &&
! ( V_7 -> V_18 . V_283 & V_1092 ) )
return - V_16 ;
V_1071 -> V_1093 = F_203 ( V_95 [ V_1091 ] ) ;
V_1071 -> V_1094 = F_203 ( V_95 [ V_1095 ] ) ;
V_1071 -> V_1096 = F_203 ( V_95 [ V_1097 ] ) ;
if ( V_1071 -> V_1096 )
V_1071 -> V_1093 = true ;
if ( V_95 [ V_1098 ] ) {
if ( ! V_1071 -> V_1093 )
return - V_16 ;
V_1071 -> V_1099 =
F_34 ( V_95 [ V_1098 ] ) ;
}
return 0 ;
}
static int F_204 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_1002 V_1064 ;
V_22 V_722 ;
int V_35 ;
if ( V_17 -> V_141 != V_145 )
return - V_522 ;
if ( ! V_7 -> V_337 -> V_367 )
return - V_522 ;
V_35 = F_200 ( V_30 , & V_1064 , & V_722 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_1005 )
V_35 = - V_150 ;
if ( ! V_35 )
V_35 = F_205 ( V_7 , V_521 , V_722 , & V_1064 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_206 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
const struct V_1100 * V_1101 ;
struct V_31 * V_53 ;
void * V_275 = NULL ;
struct V_4 * V_1102 ;
unsigned int V_153 ;
if ( ! V_995 )
return - V_16 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_91 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1103 ) ;
if ( ! V_275 )
goto V_1104;
if ( F_207 () &&
F_28 ( V_53 , V_997 ,
V_999 ) )
goto V_61;
F_208 () ;
V_1101 = F_209 ( V_995 ) ;
if ( F_60 ( V_53 , V_1000 , V_1101 -> V_1105 ) ||
( V_1101 -> V_1106 &&
F_56 ( V_53 , V_1107 , V_1101 -> V_1106 ) ) )
goto V_1108;
V_1102 = F_47 ( V_53 , V_1109 ) ;
if ( ! V_1102 )
goto V_1108;
for ( V_153 = 0 ; V_153 < V_1101 -> V_1110 ; V_153 ++ ) {
struct V_4 * V_1111 ;
const struct V_975 * V_976 ;
const struct V_977 * V_978 ;
const struct V_979 * V_980 ;
unsigned int V_988 ;
V_976 = & V_1101 -> V_1112 [ V_153 ] ;
V_978 = & V_976 -> V_978 ;
V_980 = & V_976 -> V_980 ;
V_1111 = F_47 ( V_53 , V_153 ) ;
if ( ! V_1111 )
goto V_1108;
V_988 = V_978 -> V_988 ;
if ( ! V_988 )
V_988 = F_210 ( V_1101 ,
V_976 ) ;
if ( F_28 ( V_53 , V_981 ,
V_976 -> V_51 ) ||
F_28 ( V_53 , V_982 ,
V_978 -> V_986 ) ||
F_28 ( V_53 , V_983 ,
V_978 -> V_987 ) ||
F_28 ( V_53 , V_984 ,
V_988 ) ||
F_28 ( V_53 , V_990 ,
V_980 -> V_991 ) ||
F_28 ( V_53 , V_985 ,
V_980 -> V_989 ) ||
F_28 ( V_53 , V_992 ,
V_976 -> V_74 ) )
goto V_1108;
F_48 ( V_53 , V_1111 ) ;
}
F_211 () ;
F_48 ( V_53 , V_1102 ) ;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_1108:
F_211 () ;
V_61:
F_67 ( V_53 , V_275 ) ;
V_1104:
F_75 ( V_53 ) ;
return - V_476 ;
}
static int F_212 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1113 + 1 ] ;
struct V_4 * V_1111 ;
char * V_1105 = NULL ;
int V_1114 = 0 , V_1115 = 0 ;
V_22 V_1116 = 0 , V_1117 = 0 , V_1118 ;
enum V_1119 V_1106 = V_1120 ;
struct V_1100 * V_1121 = NULL ;
if ( ! V_30 -> V_5 [ V_1000 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1109 ] )
return - V_16 ;
V_1105 = F_23 ( V_30 -> V_5 [ V_1000 ] ) ;
if ( V_30 -> V_5 [ V_1107 ] )
V_1106 = F_34 ( V_30 -> V_5 [ V_1107 ] ) ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1116 ++ ;
if ( V_1116 > V_1122 )
return - V_16 ;
}
if ( ! F_213 ( V_1105 ) )
return - V_16 ;
V_1118 = sizeof( struct V_1100 ) +
V_1116 * sizeof( struct V_975 ) ;
V_1121 = F_38 ( V_1118 , V_135 ) ;
if ( ! V_1121 )
return - V_136 ;
V_1121 -> V_1110 = V_1116 ;
V_1121 -> V_1105 [ 0 ] = V_1105 [ 0 ] ;
V_1121 -> V_1105 [ 1 ] = V_1105 [ 1 ] ;
if ( F_214 ( V_1106 ) )
V_1121 -> V_1106 = V_1106 ;
F_39 (nl_reg_rule, info->attrs[NL80211_ATTR_REG_RULES],
rem_reg_rules) {
V_1115 = F_96 ( V_95 , V_1113 ,
F_23 ( V_1111 ) , F_24 ( V_1111 ) ,
V_1123 ) ;
if ( V_1115 )
goto V_1124;
V_1115 = F_192 ( V_95 , & V_1121 -> V_1112 [ V_1117 ] ) ;
if ( V_1115 )
goto V_1124;
V_1117 ++ ;
if ( V_1117 > V_1122 ) {
V_1115 = - V_16 ;
goto V_1124;
}
}
V_1115 = F_215 ( V_1121 ) ;
V_1121 = NULL ;
V_1124:
F_41 ( V_1121 ) ;
return V_1115 ;
}
static int F_216 ( struct V_4 * V_1125 )
{
struct V_4 * V_1126 , * V_1127 ;
int V_352 = 0 , V_1128 , V_1129 ;
F_39 (attr1, freqs, tmp1) {
V_352 ++ ;
F_39 (attr2, freqs, tmp2)
if ( V_1126 != V_1127 &&
F_4 ( V_1126 ) == F_4 ( V_1127 ) )
return 0 ;
}
return V_352 ;
}
static int F_217 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
struct V_1130 * V_1131 ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1132 = 0 , V_352 , V_153 ;
T_10 V_1090 ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( ! V_7 -> V_337 -> V_1133 )
return - V_522 ;
if ( V_7 -> V_1134 || V_7 -> V_1135 ) {
V_35 = - V_526 ;
goto V_1136;
}
if ( V_30 -> V_5 [ V_1137 ] ) {
V_352 = F_216 (
V_30 -> V_5 [ V_1137 ] ) ;
if ( ! V_352 ) {
V_35 = - V_16 ;
goto V_1136;
}
} else {
V_352 = F_218 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1138 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp)
V_1132 ++ ;
if ( V_1132 > V_18 -> V_301 ) {
V_35 = - V_16 ;
goto V_1136;
}
if ( V_30 -> V_5 [ V_658 ] )
V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
else
V_1090 = 0 ;
if ( V_1090 > V_18 -> V_305 ) {
V_35 = - V_16 ;
goto V_1136;
}
V_1131 = F_38 ( sizeof( * V_1131 )
+ sizeof( * V_1131 -> V_1139 ) * V_1132
+ sizeof( * V_1131 -> V_353 ) * V_352
+ V_1090 , V_135 ) ;
if ( ! V_1131 ) {
V_35 = - V_136 ;
goto V_1136;
}
if ( V_1132 )
V_1131 -> V_1139 = ( void * ) & V_1131 -> V_353 [ V_352 ] ;
V_1131 -> V_1132 = V_1132 ;
if ( V_1090 ) {
if ( V_1131 -> V_1139 )
V_1131 -> V_1089 = ( void * ) ( V_1131 -> V_1139 + V_1132 ) ;
else
V_1131 -> V_1089 = ( void * ) ( V_1131 -> V_353 + V_352 ) ;
}
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1137 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_FREQUENCIES], tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1140;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1131 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
} else {
enum V_281 V_282 ;
for ( V_282 = 0 ; V_282 < V_348 ; V_282 ++ ) {
int V_155 ;
if ( ! V_18 -> V_349 [ V_282 ] )
continue;
for ( V_155 = 0 ; V_155 < V_18 -> V_349 [ V_282 ] -> V_352 ; V_155 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_349 [ V_282 ] -> V_353 [ V_155 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1131 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
}
}
if ( ! V_153 ) {
V_35 = - V_16 ;
goto V_1140;
}
V_1131 -> V_352 = V_153 ;
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1138 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS], tmp) {
if ( F_24 ( V_45 ) > V_597 ) {
V_35 = - V_16 ;
goto V_1140;
}
V_1131 -> V_1139 [ V_153 ] . V_571 = F_24 ( V_45 ) ;
memcpy ( V_1131 -> V_1139 [ V_153 ] . V_573 , F_23 ( V_45 ) , F_24 ( V_45 ) ) ;
V_153 ++ ;
}
}
if ( V_30 -> V_5 [ V_658 ] ) {
V_1131 -> V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
memcpy ( ( void * ) V_1131 -> V_1089 ,
F_23 ( V_30 -> V_5 [ V_658 ] ) ,
V_1131 -> V_1090 ) ;
}
for ( V_153 = 0 ; V_153 < V_348 ; V_153 ++ )
if ( V_18 -> V_349 [ V_153 ] )
V_1131 -> V_1141 [ V_153 ] =
( 1 << V_18 -> V_349 [ V_153 ] -> V_252 ) - 1 ;
if ( V_30 -> V_5 [ V_1142 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_SUPP_RATES],
tmp) {
enum V_281 V_282 = F_219 ( V_45 ) ;
if ( V_282 < 0 || V_282 >= V_348 ) {
V_35 = - V_16 ;
goto V_1140;
}
if ( ! V_18 -> V_349 [ V_282 ] )
continue;
V_35 = F_220 ( V_18 -> V_349 [ V_282 ] ,
F_23 ( V_45 ) ,
F_24 ( V_45 ) ,
& V_1131 -> V_1141 [ V_282 ] ) ;
if ( V_35 )
goto V_1140;
}
}
if ( V_30 -> V_5 [ V_1143 ] ) {
V_1131 -> V_51 = F_4 (
V_30 -> V_5 [ V_1143 ] ) ;
if ( ( V_1131 -> V_51 & V_1144 ) &&
! ( V_18 -> V_283 & V_1145 ) ) {
V_35 = - V_522 ;
goto V_1140;
}
}
V_1131 -> V_1146 =
F_203 ( V_30 -> V_5 [ V_1147 ] ) ;
V_1131 -> V_17 = V_17 ;
V_1131 -> V_18 = & V_7 -> V_18 ;
V_1131 -> V_1148 = V_1149 ;
V_7 -> V_1134 = V_1131 ;
V_35 = F_221 ( V_7 , V_1131 ) ;
if ( ! V_35 ) {
F_222 ( V_7 , V_17 ) ;
if ( V_17 -> V_19 )
F_223 ( V_17 -> V_19 ) ;
} else {
V_1140:
V_7 -> V_1134 = NULL ;
F_41 ( V_1131 ) ;
}
V_1136:
return V_35 ;
}
static int F_224 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_1150 * V_1131 ;
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_4 * V_45 ;
struct V_18 * V_18 ;
int V_35 , V_24 , V_1132 = 0 , V_1151 = 0 , V_352 , V_153 ;
V_22 V_1152 ;
enum V_281 V_282 ;
T_10 V_1090 ;
struct V_4 * V_95 [ V_1153 + 1 ] ;
T_11 V_1154 = V_1155 ;
if ( ! ( V_7 -> V_18 . V_51 & V_408 ) ||
! V_7 -> V_337 -> V_409 )
return - V_522 ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1156 ] )
return - V_16 ;
V_1152 = F_4 ( V_30 -> V_5 [ V_1156 ] ) ;
if ( V_1152 == 0 )
return - V_16 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_1137 ] ) {
V_352 = F_216 (
V_30 -> V_5 [ V_1137 ] ) ;
if ( ! V_352 )
return - V_16 ;
} else {
V_352 = F_218 ( V_18 ) ;
}
if ( V_30 -> V_5 [ V_1138 ] )
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp)
V_1132 ++ ;
if ( V_1132 > V_18 -> V_303 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1157 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_1158 ;
V_35 = F_96 ( V_95 , V_1153 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1159 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1160 ] ) {
V_1151 ++ ;
continue;
}
V_1158 = V_95 [ V_1161 ] ;
if ( V_1158 )
V_1154 = V_1068 ( V_1158 ) ;
}
}
if ( ! V_1151 && V_1154 != V_1155 )
V_1151 = 1 ;
if ( V_1151 > V_18 -> V_309 )
return - V_16 ;
if ( V_30 -> V_5 [ V_658 ] )
V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
else
V_1090 = 0 ;
if ( V_1090 > V_18 -> V_307 )
return - V_16 ;
if ( V_7 -> V_1162 ) {
V_35 = - V_996 ;
goto V_578;
}
V_1131 = F_38 ( sizeof( * V_1131 )
+ sizeof( * V_1131 -> V_1139 ) * V_1132
+ sizeof( * V_1131 -> V_1163 ) * V_1151
+ sizeof( * V_1131 -> V_353 ) * V_352
+ V_1090 , V_135 ) ;
if ( ! V_1131 ) {
V_35 = - V_136 ;
goto V_578;
}
if ( V_1132 )
V_1131 -> V_1139 = ( void * ) & V_1131 -> V_353 [ V_352 ] ;
V_1131 -> V_1132 = V_1132 ;
if ( V_1090 ) {
if ( V_1131 -> V_1139 )
V_1131 -> V_1089 = ( void * ) ( V_1131 -> V_1139 + V_1132 ) ;
else
V_1131 -> V_1089 = ( void * ) ( V_1131 -> V_353 + V_352 ) ;
}
if ( V_1151 ) {
if ( V_1131 -> V_1089 )
V_1131 -> V_1163 = ( void * ) ( V_1131 -> V_1089 + V_1090 ) ;
else if ( V_1131 -> V_1139 )
V_1131 -> V_1163 =
( void * ) ( V_1131 -> V_1139 + V_1132 ) ;
else
V_1131 -> V_1163 =
( void * ) ( V_1131 -> V_353 + V_352 ) ;
}
V_1131 -> V_1151 = V_1151 ;
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1137 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCAN_FREQUENCIES],
tmp) {
struct V_54 * V_55 ;
V_55 = F_45 ( V_18 , F_4 ( V_45 ) ) ;
if ( ! V_55 ) {
V_35 = - V_16 ;
goto V_1140;
}
if ( V_55 -> V_51 & V_62 )
continue;
V_1131 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
} else {
for ( V_282 = 0 ; V_282 < V_348 ; V_282 ++ ) {
int V_155 ;
if ( ! V_18 -> V_349 [ V_282 ] )
continue;
for ( V_155 = 0 ; V_155 < V_18 -> V_349 [ V_282 ] -> V_352 ; V_155 ++ ) {
struct V_54 * V_55 ;
V_55 = & V_18 -> V_349 [ V_282 ] -> V_353 [ V_155 ] ;
if ( V_55 -> V_51 & V_62 )
continue;
V_1131 -> V_353 [ V_153 ] = V_55 ;
V_153 ++ ;
}
}
}
if ( ! V_153 ) {
V_35 = - V_16 ;
goto V_1140;
}
V_1131 -> V_352 = V_153 ;
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1138 ] ) {
F_39 (attr, info->attrs[NL80211_ATTR_SCAN_SSIDS],
tmp) {
if ( F_24 ( V_45 ) > V_597 ) {
V_35 = - V_16 ;
goto V_1140;
}
V_1131 -> V_1139 [ V_153 ] . V_571 = F_24 ( V_45 ) ;
memcpy ( V_1131 -> V_1139 [ V_153 ] . V_573 , F_23 ( V_45 ) ,
F_24 ( V_45 ) ) ;
V_153 ++ ;
}
}
V_153 = 0 ;
if ( V_30 -> V_5 [ V_1157 ] ) {
F_39 (attr,
info->attrs[NL80211_ATTR_SCHED_SCAN_MATCH],
tmp) {
struct V_4 * V_573 , * V_1158 ;
V_35 = F_96 ( V_95 , V_1153 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1159 ) ;
if ( V_35 )
goto V_1140;
V_573 = V_95 [ V_1160 ] ;
if ( V_573 ) {
if ( F_59 ( V_153 >= V_1151 ) ) {
V_35 = - V_16 ;
goto V_1140;
}
if ( F_24 ( V_573 ) > V_597 ) {
V_35 = - V_16 ;
goto V_1140;
}
memcpy ( V_1131 -> V_1163 [ V_153 ] . V_573 . V_573 ,
F_23 ( V_573 ) , F_24 ( V_573 ) ) ;
V_1131 -> V_1163 [ V_153 ] . V_573 . V_571 =
F_24 ( V_573 ) ;
V_1131 -> V_1163 [ V_153 ] . V_1164 =
V_1154 ;
V_1158 = V_95 [ V_1161 ] ;
if ( V_1158 )
V_1131 -> V_1163 [ V_153 ] . V_1164 =
V_1068 ( V_1158 ) ;
}
V_153 ++ ;
}
if ( V_153 == 0 )
V_1131 -> V_1163 [ 0 ] . V_1164 = V_1154 ;
V_1131 -> V_1165 = V_1166 ;
for ( V_153 = 0 ; V_153 < V_1151 ; V_153 ++ )
V_1131 -> V_1165 =
T_8 ( V_1131 -> V_1163 [ V_153 ] . V_1164 ,
V_1131 -> V_1165 ) ;
} else {
V_1131 -> V_1165 = V_1155 ;
}
if ( V_1090 ) {
V_1131 -> V_1090 = V_1090 ;
memcpy ( ( void * ) V_1131 -> V_1089 ,
F_23 ( V_30 -> V_5 [ V_658 ] ) ,
V_1131 -> V_1090 ) ;
}
if ( V_30 -> V_5 [ V_1143 ] ) {
V_1131 -> V_51 = F_4 (
V_30 -> V_5 [ V_1143 ] ) ;
if ( ( V_1131 -> V_51 & V_1144 ) &&
! ( V_18 -> V_283 & V_1145 ) ) {
V_35 = - V_522 ;
goto V_1140;
}
}
V_1131 -> V_521 = V_521 ;
V_1131 -> V_18 = & V_7 -> V_18 ;
V_1131 -> V_1152 = V_1152 ;
V_1131 -> V_1148 = V_1149 ;
V_35 = F_225 ( V_7 , V_521 , V_1131 ) ;
if ( ! V_35 ) {
V_7 -> V_1162 = V_1131 ;
F_226 ( V_7 , V_521 ,
V_1167 ) ;
goto V_578;
}
V_1140:
F_41 ( V_1131 ) ;
V_578:
return V_35 ;
}
static int F_227 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
if ( ! ( V_7 -> V_18 . V_51 & V_408 ) ||
! V_7 -> V_337 -> V_1168 )
return - V_522 ;
return F_228 ( V_7 , false ) ;
}
static int F_229 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_501 V_502 ;
enum V_1119 V_1106 ;
unsigned int V_1169 ;
int V_35 ;
V_1106 = F_230 ( V_17 -> V_18 ) ;
if ( V_1106 == V_1120 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_502 ) ;
if ( V_35 )
return V_35 ;
if ( F_231 ( V_521 ) )
return - V_526 ;
if ( V_17 -> V_1170 )
return - V_526 ;
V_35 = F_232 ( V_17 -> V_18 , & V_502 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 == 0 )
return - V_16 ;
if ( ! F_233 ( V_17 -> V_18 , & V_502 ) )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_1171 )
return - V_522 ;
V_1169 = F_234 ( & V_7 -> V_18 , & V_502 ) ;
if ( F_59 ( ! V_1169 ) )
V_1169 = V_1172 ;
V_35 = V_7 -> V_337 -> V_1171 ( & V_7 -> V_18 , V_521 , & V_502 ,
V_1169 ) ;
if ( ! V_35 ) {
V_17 -> V_502 = V_502 ;
V_17 -> V_1170 = true ;
V_17 -> V_1173 = V_1149 ;
V_17 -> V_1169 = V_1169 ;
}
return V_35 ;
}
static int F_235 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_1174 V_137 ;
static struct V_4 * V_1175 [ V_1176 + 1 ] ;
T_2 V_1177 = 0 ;
int V_35 ;
bool V_1178 = false ;
int V_47 , V_153 ;
V_22 V_1179 ;
if ( ! V_7 -> V_337 -> V_428 ||
! ( V_7 -> V_18 . V_51 & V_427 ) )
return - V_522 ;
switch ( V_521 -> V_28 -> V_141 ) {
case V_142 :
case V_144 :
V_1178 = true ;
if ( ! V_17 -> V_523 )
return - V_1180 ;
break;
case V_146 :
if ( ! V_17 -> V_571 )
return - V_1180 ;
break;
case V_145 :
if ( ! V_17 -> V_1005 )
return - V_1180 ;
break;
default:
return - V_522 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( ! V_30 -> V_5 [ V_504 ] ||
! V_30 -> V_5 [ V_1181 ] )
return - V_16 ;
if ( V_1178 && ! V_30 -> V_5 [ V_1182 ] )
return - V_16 ;
V_1179 = F_4 ( V_30 -> V_5 [ V_1181 ] ) ;
if ( V_1179 > 255 )
return - V_16 ;
V_137 . V_1183 = V_1179 ;
if ( ! V_1178 )
goto V_1184;
V_35 = F_144 ( V_30 -> V_5 , & V_137 . V_1185 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_1175 , V_1176 ,
V_30 -> V_5 [ V_1182 ] ,
V_42 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_144 ( V_1175 , & V_137 . V_1186 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_1175 [ V_1187 ] )
return - V_16 ;
V_47 = F_24 ( V_1175 [ V_1187 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1188 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_475 &&
( V_137 . V_1188 >
V_7 -> V_18 . V_475 ) )
return - V_16 ;
V_137 . V_1189 =
F_23 ( V_1175 [ V_1187 ] ) ;
for ( V_153 = 0 ; V_153 < V_137 . V_1188 ; V_153 ++ ) {
T_3 V_1190 = V_137 . V_1189 [ V_153 ] ;
if ( V_1190 >= V_137 . V_1186 . V_665 )
return - V_16 ;
if ( V_137 . V_1186 . V_664 [ V_1190 ] != V_137 . V_1183 )
return - V_16 ;
}
if ( V_1175 [ V_1191 ] ) {
V_47 = F_24 ( V_1175 [ V_1191 ] ) ;
if ( ! V_47 || ( V_47 % sizeof( T_3 ) ) )
return - V_16 ;
V_137 . V_1192 = V_47 / sizeof( T_3 ) ;
if ( V_7 -> V_18 . V_475 &&
( V_137 . V_1188 >
V_7 -> V_18 . V_475 ) )
return - V_16 ;
V_137 . V_1193 =
F_23 ( V_1175 [ V_1191 ] ) ;
for ( V_153 = 0 ; V_153 < V_137 . V_1192 ; V_153 ++ ) {
T_3 V_1190 = V_137 . V_1193 [ V_153 ] ;
if ( V_1190 >= V_137 . V_1186 . V_674 )
return - V_16 ;
if ( V_137 . V_1186 . V_673 [ V_1190 ] !=
V_137 . V_1183 )
return - V_16 ;
}
}
V_1184:
V_35 = F_80 ( V_7 , V_30 , & V_137 . V_502 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_137 . V_502 ,
V_17 -> V_141 ) )
return - V_16 ;
V_35 = F_232 ( V_17 -> V_18 ,
& V_137 . V_502 ,
V_17 -> V_141 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 > 0 ) {
V_1177 = F_156 ( V_137 . V_502 . V_505 ) ;
V_137 . V_1194 = true ;
}
if ( V_30 -> V_5 [ V_1195 ] )
V_137 . V_1196 = true ;
F_112 ( V_17 ) ;
V_35 = F_236 ( V_7 , V_521 , & V_137 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_237 ( struct V_31 * V_53 , struct V_33 * V_34 ,
V_22 V_50 , int V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
struct V_1197 * V_1198 )
{
struct V_1199 * V_341 = & V_1198 -> V_1200 ;
const struct V_1201 * V_1202 ;
void * V_275 ;
struct V_4 * V_1203 ;
F_43 ( V_17 ) ;
V_275 = F_25 ( V_53 , F_71 ( V_34 -> V_32 ) . V_49 , V_50 , V_51 ,
V_1204 ) ;
if ( ! V_275 )
return - 1 ;
F_238 ( V_34 , V_275 , & V_38 ) ;
if ( F_28 ( V_53 , V_285 , V_7 -> V_1205 ) )
goto V_61;
if ( V_17 -> V_19 &&
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) )
goto V_61;
if ( F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
V_1203 = F_47 ( V_53 , V_1206 ) ;
if ( ! V_1203 )
goto V_61;
if ( ( ! F_239 ( V_341 -> V_528 ) &&
F_51 ( V_53 , V_1207 , V_568 , V_341 -> V_528 ) ) )
goto V_61;
F_208 () ;
if ( F_195 ( V_341 -> V_668 ) &&
F_29 ( V_53 , V_1208 ) )
goto V_1209;
V_1202 = F_209 ( V_341 -> V_1202 ) ;
if ( V_1202 ) {
if ( F_104 ( V_53 , V_1210 , V_1202 -> V_1211 ) )
goto V_1209;
if ( V_1202 -> V_47 && F_51 ( V_53 , V_1212 ,
V_1202 -> V_47 , V_1202 -> V_138 ) )
goto V_1209;
}
V_1202 = F_209 ( V_341 -> V_666 ) ;
if ( V_1202 && V_1202 -> V_1213 ) {
if ( F_104 ( V_53 , V_1214 , V_1202 -> V_1211 ) )
goto V_1209;
if ( V_1202 -> V_47 && F_51 ( V_53 , V_1215 ,
V_1202 -> V_47 , V_1202 -> V_138 ) )
goto V_1209;
}
F_211 () ;
if ( V_341 -> V_523 &&
F_55 ( V_53 , V_1216 , V_341 -> V_523 ) )
goto V_61;
if ( F_55 ( V_53 , V_1217 , V_341 -> V_910 ) ||
F_28 ( V_53 , V_1218 , V_341 -> V_1219 -> V_60 ) ||
F_28 ( V_53 , V_1220 , V_341 -> V_1221 ) ||
F_28 ( V_53 , V_1222 ,
F_240 ( V_1149 - V_1198 -> V_1223 ) ) )
goto V_61;
switch ( V_7 -> V_18 . V_790 ) {
case V_791 :
if ( F_28 ( V_53 , V_1224 , V_341 -> signal ) )
goto V_61;
break;
case V_1225 :
if ( F_56 ( V_53 , V_1226 , V_341 -> signal ) )
goto V_61;
break;
default:
break;
}
switch ( V_17 -> V_141 ) {
case V_148 :
case V_147 :
if ( V_1198 == V_17 -> V_149 &&
F_28 ( V_53 , V_1227 ,
V_1228 ) )
goto V_61;
break;
case V_146 :
if ( V_1198 == V_17 -> V_149 &&
F_28 ( V_53 , V_1227 ,
V_1229 ) )
goto V_61;
break;
default:
break;
}
F_48 ( V_53 , V_1203 ) ;
return F_66 ( V_53 , V_275 ) ;
V_1209:
F_211 () ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
static int F_241 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_1197 * V_1133 ;
struct V_1 * V_17 ;
int V_480 = V_34 -> args [ 2 ] , V_105 = 0 ;
int V_35 ;
V_35 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_35 )
return V_35 ;
F_112 ( V_17 ) ;
F_242 ( & V_7 -> V_1230 ) ;
F_243 ( V_7 ) ;
V_34 -> V_50 = V_7 -> V_1205 ;
F_6 (scan, &rdev->bss_list, list) {
if ( ++ V_105 <= V_480 )
continue;
if ( F_237 ( V_32 , V_34 ,
V_34 -> V_36 -> V_481 , V_482 ,
V_7 , V_17 , V_1133 ) < 0 ) {
V_105 -- ;
break;
}
}
F_244 ( & V_7 -> V_1230 ) ;
F_114 ( V_17 ) ;
V_34 -> args [ 2 ] = V_105 ;
F_21 ( V_7 ) ;
return V_32 -> V_47 ;
}
static int F_245 ( struct V_31 * V_53 , V_22 V_49 , V_22 V_50 ,
int V_51 , struct V_25 * V_521 ,
struct V_1231 * V_1232 )
{
void * V_275 ;
struct V_4 * V_1233 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 ,
V_1234 ) ;
if ( ! V_275 )
return - V_136 ;
if ( F_28 ( V_53 , V_10 , V_521 -> V_20 ) )
goto V_61;
V_1233 = F_47 ( V_53 , V_1235 ) ;
if ( ! V_1233 )
goto V_61;
if ( F_28 ( V_53 , V_1236 ,
V_1232 -> V_1219 -> V_60 ) )
goto V_61;
if ( ( V_1232 -> V_764 & V_1237 ) &&
F_56 ( V_53 , V_1238 , V_1232 -> V_1239 ) )
goto V_61;
if ( ( V_1232 -> V_764 & V_1240 ) &&
F_29 ( V_53 , V_1241 ) )
goto V_61;
if ( ( V_1232 -> V_764 & V_1242 ) &&
F_104 ( V_53 , V_1243 ,
V_1232 -> V_1244 ) )
goto V_61;
if ( ( V_1232 -> V_764 & V_1245 ) &&
F_104 ( V_53 , V_1246 ,
V_1232 -> V_1247 ) )
goto V_61;
if ( ( V_1232 -> V_764 & V_1248 ) &&
F_104 ( V_53 , V_1249 ,
V_1232 -> V_1250 ) )
goto V_61;
if ( ( V_1232 -> V_764 & V_1251 ) &&
F_104 ( V_53 , V_1252 ,
V_1232 -> V_1253 ) )
goto V_61;
if ( ( V_1232 -> V_764 & V_1254 ) &&
F_104 ( V_53 , V_1255 ,
V_1232 -> V_1256 ) )
goto V_61;
F_48 ( V_53 , V_1233 ) ;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
static int F_246 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_1231 V_1232 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
int V_1257 = V_34 -> args [ 2 ] ;
int V_341 ;
V_341 = F_13 ( V_32 , V_34 , & V_7 , & V_17 ) ;
if ( V_341 )
return V_341 ;
if ( ! V_17 -> V_19 ) {
V_341 = - V_16 ;
goto V_856;
}
if ( ! V_7 -> V_337 -> V_1258 ) {
V_341 = - V_522 ;
goto V_856;
}
while ( 1 ) {
struct V_54 * V_55 ;
V_341 = F_247 ( V_7 , V_17 -> V_19 , V_1257 , & V_1232 ) ;
if ( V_341 == - V_631 )
break;
if ( V_341 )
goto V_856;
if ( ! V_1232 . V_1219 ) {
V_341 = - V_16 ;
goto V_578;
}
V_55 = F_45 ( & V_7 -> V_18 ,
V_1232 . V_1219 -> V_60 ) ;
if ( ! V_55 || V_55 -> V_51 & V_62 ) {
V_1257 ++ ;
continue;
}
if ( F_245 ( V_32 ,
F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_481 , V_482 ,
V_17 -> V_19 , & V_1232 ) < 0 )
goto V_578;
V_1257 ++ ;
}
V_578:
V_34 -> args [ 2 ] = V_1257 ;
V_341 = V_32 -> V_47 ;
V_856:
F_21 ( V_7 ) ;
return V_341 ;
}
static bool F_248 ( V_22 V_1259 )
{
return ! ( V_1259 & ~ ( V_1260 |
V_1261 ) ) ;
}
static int F_249 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_54 * V_55 ;
const T_2 * V_528 , * V_573 , * V_1089 = NULL , * V_1262 = NULL ;
int V_35 , V_571 , V_1090 = 0 , V_1263 = 0 ;
enum V_676 V_677 ;
struct V_93 V_92 ;
bool V_1264 ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_695 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_572 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_504 ] )
return - V_16 ;
V_35 = F_36 ( V_30 , & V_92 ) ;
if ( V_35 )
return V_35 ;
if ( V_92 . V_105 >= 0 ) {
if ( V_92 . type != - 1 && V_92 . type != V_627 )
return - V_16 ;
if ( ! V_92 . V_107 . V_92 || ! V_92 . V_107 . V_108 )
return - V_16 ;
if ( ( V_92 . V_107 . V_112 != V_139 ||
V_92 . V_107 . V_108 != V_1265 ) &&
( V_92 . V_107 . V_112 != V_140 ||
V_92 . V_107 . V_108 != V_1266 ) )
return - V_16 ;
if ( V_92 . V_105 > 4 )
return - V_16 ;
} else {
V_92 . V_107 . V_108 = 0 ;
V_92 . V_107 . V_92 = NULL ;
}
if ( V_92 . V_105 >= 0 ) {
int V_153 ;
bool V_1267 = false ;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_324 ; V_153 ++ ) {
if ( V_92 . V_107 . V_112 == V_7 -> V_18 . V_325 [ V_153 ] ) {
V_1267 = true ;
break;
}
}
if ( ! V_1267 )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_371 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_504 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_573 = F_23 ( V_30 -> V_5 [ V_572 ] ) ;
V_571 = F_24 ( V_30 -> V_5 [ V_572 ] ) ;
if ( V_30 -> V_5 [ V_658 ] ) {
V_1089 = F_23 ( V_30 -> V_5 [ V_658 ] ) ;
V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
}
V_677 = F_4 ( V_30 -> V_5 [ V_695 ] ) ;
if ( ! F_146 ( V_7 , V_677 , V_679 ) )
return - V_16 ;
if ( V_677 == V_681 &&
! V_30 -> V_5 [ V_1268 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_1268 ] ) {
if ( V_677 != V_681 )
return - V_16 ;
V_1262 = F_23 ( V_30 -> V_5 [ V_1268 ] ) ;
V_1263 = F_24 ( V_30 -> V_5 [ V_1268 ] ) ;
if ( V_1263 < 4 )
return - V_16 ;
}
V_1264 = ! ! V_30 -> V_5 [ V_1269 ] ;
if ( V_1264 )
return 0 ;
F_112 ( V_521 -> V_28 ) ;
V_35 = F_250 ( V_7 , V_521 , V_55 , V_677 , V_528 ,
V_573 , V_571 , V_1089 , V_1090 ,
V_92 . V_107 . V_92 , V_92 . V_107 . V_108 , V_92 . V_105 ,
V_1262 , V_1263 ) ;
F_114 ( V_521 -> V_28 ) ;
return V_35 ;
}
static int F_149 ( struct V_6 * V_7 ,
struct V_29 * V_30 ,
struct V_1270 * V_1271 ,
int V_1272 )
{
memset ( V_1271 , 0 , sizeof( * V_1271 ) ) ;
V_1271 -> V_1273 = V_30 -> V_5 [ V_1274 ] ;
if ( V_30 -> V_5 [ V_329 ] ) {
T_3 V_1275 ;
V_1275 = F_78 (
V_30 -> V_5 [ V_329 ] ) ;
V_1271 -> V_1276 = F_251 ( V_1275 ) ;
if ( ! ( V_7 -> V_18 . V_51 & V_328 ) &&
V_1275 != V_1277 )
return - V_16 ;
if ( V_30 -> V_5 [ V_1278 ] )
V_1271 -> V_1279 = true ;
} else
V_1271 -> V_1276 = F_251 ( V_1277 ) ;
if ( V_30 -> V_5 [ V_1280 ] ) {
void * V_138 ;
int V_47 , V_153 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1280 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1280 ] ) ;
V_1271 -> V_1281 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1271 -> V_1281 > V_1272 )
return - V_16 ;
memcpy ( V_1271 -> V_1282 , V_138 , V_47 ) ;
for ( V_153 = 0 ; V_153 < V_1271 -> V_1281 ; V_153 ++ )
if ( ! F_252 (
& V_7 -> V_18 ,
V_1271 -> V_1282 [ V_153 ] ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1283 ] ) {
V_1271 -> V_1284 =
F_4 ( V_30 -> V_5 [ V_1283 ] ) ;
if ( ! F_252 ( & V_7 -> V_18 ,
V_1271 -> V_1284 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1285 ] ) {
V_1271 -> V_1259 =
F_4 ( V_30 -> V_5 [ V_1285 ] ) ;
if ( ! F_248 ( V_1271 -> V_1259 ) )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1286 ] ) {
void * V_138 ;
int V_47 ;
V_138 = F_23 ( V_30 -> V_5 [ V_1286 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1286 ] ) ;
V_1271 -> V_1287 = V_47 / sizeof( V_22 ) ;
if ( V_47 % sizeof( V_22 ) )
return - V_16 ;
if ( V_1271 -> V_1287 > V_1288 )
return - V_16 ;
memcpy ( V_1271 -> V_1289 , V_138 , V_47 ) ;
}
return 0 ;
}
static int F_253 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_54 * V_55 ;
struct V_1290 V_1291 = {} ;
const T_2 * V_528 , * V_573 ;
int V_35 , V_571 = 0 ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_529 ] ||
! V_30 -> V_5 [ V_572 ] ||
! V_30 -> V_5 [ V_504 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_373 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_55 = F_44 ( & V_7 -> V_18 ,
V_30 -> V_5 [ V_504 ] ) ;
if ( ! V_55 )
return - V_16 ;
V_573 = F_23 ( V_30 -> V_5 [ V_572 ] ) ;
V_571 = F_24 ( V_30 -> V_5 [ V_572 ] ) ;
if ( V_30 -> V_5 [ V_658 ] ) {
V_1291 . V_1089 = F_23 ( V_30 -> V_5 [ V_658 ] ) ;
V_1291 . V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
}
if ( V_30 -> V_5 [ V_1292 ] ) {
enum V_1293 V_1294 =
F_4 ( V_30 -> V_5 [ V_1292 ] ) ;
if ( V_1294 == V_1295 )
V_1291 . V_1296 = true ;
else if ( V_1294 != V_1297 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1298 ] )
V_1291 . V_1299 = F_23 ( V_30 -> V_5 [ V_1298 ] ) ;
if ( F_203 ( V_30 -> V_5 [ V_1300 ] ) )
V_1291 . V_51 |= V_1301 ;
if ( V_30 -> V_5 [ V_451 ] )
memcpy ( & V_1291 . V_1302 ,
F_23 ( V_30 -> V_5 [ V_451 ] ) ,
sizeof( V_1291 . V_1302 ) ) ;
if ( V_30 -> V_5 [ V_903 ] ) {
if ( ! V_30 -> V_5 [ V_451 ] )
return - V_16 ;
memcpy ( & V_1291 . V_875 ,
F_23 ( V_30 -> V_5 [ V_903 ] ) ,
sizeof( V_1291 . V_875 ) ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1303 ] ) )
V_1291 . V_51 |= V_1304 ;
if ( V_30 -> V_5 [ V_460 ] )
memcpy ( & V_1291 . V_1305 ,
F_23 ( V_30 -> V_5 [ V_460 ] ) ,
sizeof( V_1291 . V_1305 ) ) ;
if ( V_30 -> V_5 [ V_904 ] ) {
if ( ! V_30 -> V_5 [ V_460 ] )
return - V_16 ;
memcpy ( & V_1291 . V_876 ,
F_23 ( V_30 -> V_5 [ V_904 ] ) ,
sizeof( V_1291 . V_876 ) ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1306 ] ) ) {
if ( ! ( V_7 -> V_18 . V_283 &
V_1307 ) ||
! ( V_7 -> V_18 . V_283 & V_1308 ) )
return - V_16 ;
V_1291 . V_51 |= V_1309 ;
}
V_35 = F_149 ( V_7 , V_30 , & V_1291 . V_697 , 1 ) ;
if ( ! V_35 ) {
F_112 ( V_521 -> V_28 ) ;
V_35 = F_254 ( V_7 , V_521 , V_55 , V_528 ,
V_573 , V_571 , & V_1291 ) ;
F_114 ( V_521 -> V_28 ) ;
}
return V_35 ;
}
static int F_255 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
const T_2 * V_1089 = NULL , * V_528 ;
int V_1090 = 0 , V_35 ;
T_3 V_1310 ;
bool V_1264 ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1311 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_375 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_1310 = F_78 ( V_30 -> V_5 [ V_1311 ] ) ;
if ( V_1310 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_658 ] ) {
V_1089 = F_23 ( V_30 -> V_5 [ V_658 ] ) ;
V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
}
V_1264 = ! ! V_30 -> V_5 [ V_1269 ] ;
F_112 ( V_521 -> V_28 ) ;
V_35 = F_256 ( V_7 , V_521 , V_528 , V_1089 , V_1090 , V_1310 ,
V_1264 ) ;
F_114 ( V_521 -> V_28 ) ;
return V_35 ;
}
static int F_257 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
const T_2 * V_1089 = NULL , * V_528 ;
int V_1090 = 0 , V_35 ;
T_3 V_1310 ;
bool V_1264 ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1311 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_377 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_1310 = F_78 ( V_30 -> V_5 [ V_1311 ] ) ;
if ( V_1310 == 0 ) {
return - V_16 ;
}
if ( V_30 -> V_5 [ V_658 ] ) {
V_1089 = F_23 ( V_30 -> V_5 [ V_658 ] ) ;
V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
}
V_1264 = ! ! V_30 -> V_5 [ V_1269 ] ;
F_112 ( V_521 -> V_28 ) ;
V_35 = F_258 ( V_7 , V_521 , V_528 , V_1089 , V_1090 , V_1310 ,
V_1264 ) ;
F_114 ( V_521 -> V_28 ) ;
return V_35 ;
}
static bool
F_259 ( struct V_6 * V_7 ,
int V_1312 [ V_348 ] ,
int V_1313 )
{
struct V_18 * V_18 = & V_7 -> V_18 ;
bool V_27 = false ;
int V_282 , V_153 ;
for ( V_282 = 0 ; V_282 < V_348 ; V_282 ++ ) {
struct V_230 * V_231 ;
V_231 = V_18 -> V_349 [ V_282 ] ;
if ( ! V_231 )
continue;
for ( V_153 = 0 ; V_153 < V_231 -> V_252 ; V_153 ++ ) {
if ( V_231 -> V_253 [ V_153 ] . V_255 == V_1313 ) {
V_1312 [ V_282 ] = V_153 + 1 ;
V_27 = true ;
break;
}
}
}
return V_27 ;
}
static int F_260 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1314 V_1315 ;
struct V_18 * V_18 ;
struct V_130 * V_1316 = NULL ;
int V_35 ;
memset ( & V_1315 , 0 , sizeof( V_1315 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_572 ] ||
! F_24 ( V_30 -> V_5 [ V_572 ] ) )
return - V_16 ;
V_1315 . V_523 = 100 ;
if ( V_30 -> V_5 [ V_684 ] ) {
V_1315 . V_523 =
F_4 ( V_30 -> V_5 [ V_684 ] ) ;
if ( V_1315 . V_523 < 1 || V_1315 . V_523 > 10000 )
return - V_16 ;
}
if ( ! V_7 -> V_337 -> V_379 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_146 )
return - V_522 ;
V_18 = & V_7 -> V_18 ;
if ( V_30 -> V_5 [ V_529 ] ) {
V_1315 . V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( ! F_119 ( V_1315 . V_528 ) )
return - V_16 ;
}
V_1315 . V_573 = F_23 ( V_30 -> V_5 [ V_572 ] ) ;
V_1315 . V_571 = F_24 ( V_30 -> V_5 [ V_572 ] ) ;
if ( V_30 -> V_5 [ V_658 ] ) {
V_1315 . V_1089 = F_23 ( V_30 -> V_5 [ V_658 ] ) ;
V_1315 . V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
}
V_35 = F_80 ( V_7 , V_30 , & V_1315 . V_502 ) ;
if ( V_35 )
return V_35 ;
if ( ! F_85 ( & V_7 -> V_18 , & V_1315 . V_502 ,
V_146 ) )
return - V_16 ;
switch ( V_1315 . V_502 . V_505 ) {
case V_519 :
case V_520 :
case V_506 :
break;
case V_562 :
case V_563 :
if ( V_7 -> V_18 . V_283 & V_1317 )
break;
default:
return - V_16 ;
}
V_1315 . V_1318 = ! ! V_30 -> V_5 [ V_1319 ] ;
V_1315 . V_693 = ! ! V_30 -> V_5 [ V_694 ] ;
if ( V_30 -> V_5 [ V_970 ] ) {
T_2 * V_1141 =
F_23 ( V_30 -> V_5 [ V_970 ] ) ;
int V_1320 =
F_24 ( V_30 -> V_5 [ V_970 ] ) ;
struct V_230 * V_231 =
V_18 -> V_349 [ V_1315 . V_502 . V_55 -> V_282 ] ;
V_35 = F_220 ( V_231 , V_1141 , V_1320 ,
& V_1315 . V_971 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_30 -> V_5 [ V_451 ] )
memcpy ( & V_1315 . V_1302 ,
F_23 ( V_30 -> V_5 [ V_451 ] ) ,
sizeof( V_1315 . V_1302 ) ) ;
if ( V_30 -> V_5 [ V_903 ] ) {
if ( ! V_30 -> V_5 [ V_451 ] )
return - V_16 ;
memcpy ( & V_1315 . V_875 ,
F_23 ( V_30 -> V_5 [ V_903 ] ) ,
sizeof( V_1315 . V_875 ) ) ;
}
if ( V_30 -> V_5 [ V_1321 ] &&
! F_259 ( V_7 , V_1315 . V_1312 ,
F_4 ( V_30 -> V_5 [ V_1321 ] ) ) )
return - V_16 ;
if ( V_1315 . V_693 && V_30 -> V_5 [ V_1322 ] ) {
bool V_132 = false ;
V_1316 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1322 ] ,
& V_132 ) ;
if ( F_17 ( V_1316 ) )
return F_18 ( V_1316 ) ;
if ( ( V_1315 . V_502 . V_505 != V_506 ) &&
V_132 ) {
F_41 ( V_1316 ) ;
return - V_16 ;
}
}
V_1315 . V_1273 =
F_203 ( V_30 -> V_5 [ V_1274 ] ) ;
V_1315 . V_1323 =
F_203 ( V_30 -> V_5 [ V_1324 ] ) ;
V_35 = F_261 ( V_7 , V_521 , & V_1315 , V_1316 ) ;
if ( V_35 )
F_262 ( V_1316 ) ;
return V_35 ;
}
static int F_263 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_1325 )
return - V_522 ;
if ( V_521 -> V_28 -> V_141 != V_146 )
return - V_522 ;
return F_264 ( V_7 , V_521 , false ) ;
}
static int F_265 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
int V_1312 [ V_348 ] ;
V_22 V_1326 ;
int V_35 ;
if ( V_521 -> V_28 -> V_141 != V_146 &&
V_521 -> V_28 -> V_141 != V_145 )
return - V_522 ;
if ( ! V_7 -> V_337 -> V_419 )
return - V_522 ;
memset ( V_1312 , 0 , sizeof( V_1312 ) ) ;
if ( ! V_30 -> V_5 [ V_1321 ] )
return - V_16 ;
V_1326 = F_4 ( V_30 -> V_5 [ V_1321 ] ) ;
if ( ! F_259 ( V_7 , V_1312 , V_1326 ) )
return - V_16 ;
V_35 = V_7 -> V_337 -> V_419 ( & V_7 -> V_18 , V_521 , V_1312 ) ;
return V_35 ;
}
static struct V_31 *
F_266 ( struct V_6 * V_7 ,
int V_1327 , V_22 V_49 , V_22 V_50 ,
enum V_272 V_52 ,
enum V_1328 V_45 ,
const struct V_467 * V_30 ,
T_12 V_1329 )
{
struct V_31 * V_32 ;
void * V_275 ;
struct V_4 * V_138 ;
V_32 = F_74 ( V_1327 + 100 , V_1329 ) ;
if ( ! V_32 )
return NULL ;
V_275 = F_25 ( V_32 , V_49 , V_50 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_267 ( V_32 ) ;
return NULL ;
}
if ( F_28 ( V_32 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_30 ) {
if ( F_28 ( V_32 , V_1330 ,
V_30 -> V_1331 ) )
goto V_61;
if ( F_28 ( V_32 , V_1332 ,
V_30 -> V_1333 ) )
goto V_61;
}
V_138 = F_47 ( V_32 , V_45 ) ;
( ( void * * ) V_32 -> V_34 ) [ 0 ] = V_7 ;
( ( void * * ) V_32 -> V_34 ) [ 1 ] = V_275 ;
( ( void * * ) V_32 -> V_34 ) [ 2 ] = V_138 ;
return V_32 ;
V_61:
F_267 ( V_32 ) ;
return NULL ;
}
struct V_31 * F_268 ( struct V_18 * V_18 ,
enum V_272 V_52 ,
enum V_1328 V_45 ,
int V_1334 ,
int V_1327 , T_12 V_1329 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_467 * V_30 ;
switch ( V_52 ) {
case V_1335 :
if ( F_59 ( V_1334 != - 1 ) )
return NULL ;
V_30 = NULL ;
break;
case V_1336 :
if ( F_59 ( V_1334 < 0 ||
V_1334 >= V_18 -> V_471 ) )
return NULL ;
V_30 = & V_18 -> V_473 [ V_1334 ] ;
break;
default:
F_59 ( 1 ) ;
return NULL ;
}
return F_266 ( V_7 , V_1327 , 0 , 0 ,
V_52 , V_45 , V_30 , V_1329 ) ;
}
void F_269 ( struct V_31 * V_32 , T_12 V_1329 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_275 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
enum V_1337 V_1338 = V_1339 ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_275 ) ;
if ( V_138 -> F_219 == V_469 )
V_1338 = V_1340 ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_32 , 0 ,
V_1338 , V_1329 ) ;
}
static int F_271 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_35 ;
if ( ! V_7 -> V_337 -> V_421 )
return - V_522 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1341 ] )
return - V_16 ;
V_7 -> V_1342 = V_30 ;
V_35 = F_272 ( V_7 , V_17 ,
F_23 ( V_30 -> V_5 [ V_1341 ] ) ,
F_24 ( V_30 -> V_5 [ V_1341 ] ) ) ;
V_7 -> V_1342 = NULL ;
return V_35 ;
}
static int F_273 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
int V_35 ;
long V_1343 ;
void * V_138 = NULL ;
int V_1344 = 0 ;
F_14 () ;
if ( V_34 -> args [ 0 ] ) {
V_1343 = V_34 -> args [ 0 ] - 1 ;
} else {
V_35 = F_15 ( V_34 -> V_36 , V_37 + V_38 . V_39 ,
V_38 . V_40 , V_38 . V_41 ,
V_42 ) ;
if ( V_35 )
goto V_856;
V_7 = F_8 ( F_16 ( V_32 -> V_44 ) ,
V_38 . V_40 ) ;
if ( F_17 ( V_7 ) ) {
V_35 = F_18 ( V_7 ) ;
goto V_856;
}
V_1343 = V_7 -> V_14 ;
V_7 = NULL ;
if ( V_38 . V_40 [ V_1341 ] )
V_34 -> args [ 1 ] =
( long ) V_38 . V_40 [ V_1341 ] ;
}
if ( V_34 -> args [ 1 ] ) {
V_138 = F_23 ( ( void * ) V_34 -> args [ 1 ] ) ;
V_1344 = F_24 ( ( void * ) V_34 -> args [ 1 ] ) ;
}
V_7 = F_9 ( V_1343 ) ;
if ( ! V_7 ) {
V_35 = - V_631 ;
goto V_856;
}
if ( ! V_7 -> V_337 -> V_1345 ) {
V_35 = - V_522 ;
goto V_856;
}
while ( 1 ) {
void * V_275 = F_25 ( V_32 , F_71 ( V_34 -> V_32 ) . V_49 ,
V_34 -> V_36 -> V_481 , V_482 ,
V_1335 ) ;
struct V_4 * V_1346 ;
if ( ! V_275 )
break;
if ( F_28 ( V_32 , V_26 , V_1343 ) ) {
F_67 ( V_32 , V_275 ) ;
break;
}
V_1346 = F_47 ( V_32 , V_1341 ) ;
if ( ! V_1346 ) {
F_67 ( V_32 , V_275 ) ;
break;
}
V_35 = F_274 ( V_7 , V_32 , V_34 , V_138 , V_1344 ) ;
F_48 ( V_32 , V_1346 ) ;
if ( V_35 == - V_91 || V_35 == - V_631 ) {
F_67 ( V_32 , V_275 ) ;
break;
} else if ( V_35 ) {
F_67 ( V_32 , V_275 ) ;
goto V_856;
}
F_66 ( V_32 , V_275 ) ;
}
V_35 = V_32 -> V_47 ;
V_34 -> args [ 0 ] = V_1343 + 1 ;
V_856:
F_20 () ;
return V_35 ;
}
static int F_275 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1347 V_435 ;
struct V_18 * V_18 ;
struct V_130 * V_1316 = NULL ;
int V_35 ;
memset ( & V_435 , 0 , sizeof( V_435 ) ) ;
if ( ! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_572 ] ||
! F_24 ( V_30 -> V_5 [ V_572 ] ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_695 ] ) {
V_435 . V_677 =
F_4 ( V_30 -> V_5 [ V_695 ] ) ;
if ( ! F_146 ( V_7 , V_435 . V_677 ,
V_436 ) )
return - V_16 ;
} else
V_435 . V_677 = V_696 ;
V_435 . V_693 = V_30 -> V_5 [ V_694 ] ;
V_35 = F_149 ( V_7 , V_30 , & V_435 . V_697 ,
V_698 ) ;
if ( V_35 )
return V_35 ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
V_18 = & V_7 -> V_18 ;
V_435 . V_1348 = - 1 ;
if ( V_30 -> V_5 [ V_1349 ] &&
( V_18 -> V_51 & V_316 ) ) {
V_435 . V_1348 =
F_78 ( V_30 -> V_5 [ V_1349 ] ) ;
}
if ( V_30 -> V_5 [ V_529 ] )
V_435 . V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
else if ( V_30 -> V_5 [ V_1350 ] )
V_435 . V_1351 =
F_23 ( V_30 -> V_5 [ V_1350 ] ) ;
V_435 . V_573 = F_23 ( V_30 -> V_5 [ V_572 ] ) ;
V_435 . V_571 = F_24 ( V_30 -> V_5 [ V_572 ] ) ;
if ( V_30 -> V_5 [ V_658 ] ) {
V_435 . V_1089 = F_23 ( V_30 -> V_5 [ V_658 ] ) ;
V_435 . V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
}
if ( V_30 -> V_5 [ V_1292 ] ) {
V_435 . V_1294 = F_4 ( V_30 -> V_5 [ V_1292 ] ) ;
if ( V_435 . V_1294 != V_1295 &&
V_435 . V_1294 != V_1297 )
return - V_16 ;
} else {
V_435 . V_1294 = V_1297 ;
}
if ( V_30 -> V_5 [ V_504 ] ) {
V_435 . V_1219 = F_44 (
V_18 , V_30 -> V_5 [ V_504 ] ) ;
if ( ! V_435 . V_1219 )
return - V_16 ;
} else if ( V_30 -> V_5 [ V_1352 ] ) {
V_435 . V_1353 = F_44 (
V_18 , V_30 -> V_5 [ V_1352 ] ) ;
if ( ! V_435 . V_1353 )
return - V_16 ;
}
if ( V_435 . V_693 && V_30 -> V_5 [ V_1322 ] ) {
V_1316 = F_37 ( V_7 ,
V_30 -> V_5 [ V_1322 ] , NULL ) ;
if ( F_17 ( V_1316 ) )
return F_18 ( V_1316 ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1300 ] ) )
V_435 . V_51 |= V_1301 ;
if ( V_30 -> V_5 [ V_451 ] )
memcpy ( & V_435 . V_1302 ,
F_23 ( V_30 -> V_5 [ V_451 ] ) ,
sizeof( V_435 . V_1302 ) ) ;
if ( V_30 -> V_5 [ V_903 ] ) {
if ( ! V_30 -> V_5 [ V_451 ] ) {
F_262 ( V_1316 ) ;
return - V_16 ;
}
memcpy ( & V_435 . V_875 ,
F_23 ( V_30 -> V_5 [ V_903 ] ) ,
sizeof( V_435 . V_875 ) ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1303 ] ) )
V_435 . V_51 |= V_1304 ;
if ( V_30 -> V_5 [ V_460 ] )
memcpy ( & V_435 . V_1305 ,
F_23 ( V_30 -> V_5 [ V_460 ] ) ,
sizeof( V_435 . V_1305 ) ) ;
if ( V_30 -> V_5 [ V_904 ] ) {
if ( ! V_30 -> V_5 [ V_460 ] ) {
F_262 ( V_1316 ) ;
return - V_16 ;
}
memcpy ( & V_435 . V_876 ,
F_23 ( V_30 -> V_5 [ V_904 ] ) ,
sizeof( V_435 . V_876 ) ) ;
}
if ( F_203 ( V_30 -> V_5 [ V_1306 ] ) ) {
if ( ! ( V_7 -> V_18 . V_283 &
V_1307 ) ||
! ( V_7 -> V_18 . V_283 & V_1308 ) )
return - V_16 ;
V_435 . V_51 |= V_1309 ;
}
F_112 ( V_521 -> V_28 ) ;
V_35 = F_276 ( V_7 , V_521 , & V_435 , V_1316 , NULL ) ;
F_114 ( V_521 -> V_28 ) ;
if ( V_35 )
F_262 ( V_1316 ) ;
return V_35 ;
}
static int F_277 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_3 V_1354 ;
int V_477 ;
if ( ! V_30 -> V_5 [ V_1311 ] )
V_1354 = V_1355 ;
else
V_1354 = F_78 ( V_30 -> V_5 [ V_1311 ] ) ;
if ( V_1354 == 0 )
return - V_16 ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
F_112 ( V_521 -> V_28 ) ;
V_477 = F_278 ( V_7 , V_521 , V_1354 , true ) ;
F_114 ( V_521 -> V_28 ) ;
return V_477 ;
}
static int F_279 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_2 * V_2 ;
int V_35 ;
V_22 V_1356 ;
if ( ! V_30 -> V_5 [ V_1357 ] )
return - V_16 ;
V_1356 = F_4 ( V_30 -> V_5 [ V_1357 ] ) ;
V_2 = F_280 ( V_1356 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
V_35 = 0 ;
if ( ! F_70 ( F_7 ( & V_7 -> V_18 ) , V_2 ) )
V_35 = F_281 ( V_7 , V_2 ) ;
F_282 ( V_2 ) ;
return V_35 ;
}
static int F_283 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
int (* F_284)( struct V_18 * V_18 , struct V_25 * V_521 ,
struct V_1358 * V_1359 ) = NULL ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1358 V_1359 ;
memset ( & V_1359 , 0 , sizeof( struct V_1358 ) ) ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1360 ] )
return - V_16 ;
V_1359 . V_1361 = F_23 ( V_30 -> V_5 [ V_1360 ] ) ;
V_1359 . V_528 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
switch ( V_30 -> V_1362 -> V_52 ) {
case V_1363 :
F_284 = V_7 -> V_337 -> V_383 ;
break;
case V_1364 :
F_284 = V_7 -> V_337 -> V_385 ;
break;
default:
F_59 ( 1 ) ;
break;
}
if ( ! F_284 )
return - V_522 ;
return F_284 ( & V_7 -> V_18 , V_521 , & V_1359 ) ;
}
static int F_285 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
if ( V_521 -> V_28 -> V_141 != V_147 &&
V_521 -> V_28 -> V_141 != V_148 )
return - V_522 ;
if ( ! V_7 -> V_337 -> V_387 )
return - V_522 ;
return F_286 ( V_7 , V_521 ) ;
}
static int F_287 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 V_1365 , V_1366 ;
V_22 V_1367 = 0 ;
T_3 V_1368 ;
T_2 * V_1369 ;
bool V_1370 ;
if ( ! ( V_7 -> V_18 . V_51 & V_318 ) ||
! V_7 -> V_337 -> V_404 )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_1371 ] ||
! V_30 -> V_5 [ V_1372 ] ||
! V_30 -> V_5 [ V_1373 ] ||
! V_30 -> V_5 [ V_658 ] ||
! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
V_1369 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_1365 = F_34 ( V_30 -> V_5 [ V_1371 ] ) ;
V_1368 = F_78 ( V_30 -> V_5 [ V_1372 ] ) ;
V_1366 = F_34 ( V_30 -> V_5 [ V_1373 ] ) ;
V_1370 = F_203 ( V_30 -> V_5 [ V_1374 ] ) ;
if ( V_30 -> V_5 [ V_1375 ] )
V_1367 =
F_4 ( V_30 -> V_5 [ V_1375 ] ) ;
return F_288 ( V_7 , V_521 , V_1369 , V_1365 ,
V_1366 , V_1368 , V_1367 ,
V_1370 ,
F_23 ( V_30 -> V_5 [ V_658 ] ) ,
F_24 ( V_30 -> V_5 [ V_658 ] ) ) ;
}
static int F_289 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
enum V_1376 V_1377 ;
T_2 * V_1369 ;
if ( ! ( V_7 -> V_18 . V_51 & V_318 ) ||
! V_7 -> V_337 -> V_406 )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_1378 ] ||
! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
V_1377 = F_34 ( V_30 -> V_5 [ V_1378 ] ) ;
V_1369 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
return F_290 ( V_7 , V_521 , V_1369 , V_1377 ) ;
}
static int F_291 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
struct V_501 V_502 ;
struct V_31 * V_53 ;
void * V_275 ;
T_1 V_622 ;
V_22 V_1379 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_504 ] ||
! V_30 -> V_5 [ V_1380 ] )
return - V_16 ;
V_1379 = F_4 ( V_30 -> V_5 [ V_1380 ] ) ;
if ( ! V_7 -> V_337 -> V_390 ||
! ( V_7 -> V_18 . V_51 & V_389 ) )
return - V_522 ;
if ( V_1379 < V_1381 ||
V_1379 > V_7 -> V_18 . V_440 )
return - V_16 ;
V_35 = F_80 ( V_7 , V_30 , & V_502 ) ;
if ( V_35 )
return V_35 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1382 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_632;
}
V_35 = F_292 ( V_7 , V_17 , V_502 . V_55 ,
V_1379 , & V_622 ) ;
if ( V_35 )
goto V_632;
if ( F_104 ( V_53 , V_1383 , V_622 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_632:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_293 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
T_1 V_622 ;
if ( ! V_30 -> V_5 [ V_1383 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_1384 )
return - V_522 ;
V_622 = F_5 ( V_30 -> V_5 [ V_1383 ] ) ;
return F_294 ( V_7 , V_17 , V_622 ) ;
}
static V_22 F_295 ( struct V_230 * V_231 ,
T_2 * V_1141 , T_2 V_1385 )
{
T_2 V_153 ;
V_22 V_722 = 0 ;
for ( V_153 = 0 ; V_153 < V_1385 ; V_153 ++ ) {
int V_235 = ( V_1141 [ V_153 ] & 0x7f ) * 5 ;
int V_1386 ;
for ( V_1386 = 0 ; V_1386 < V_231 -> V_252 ; V_1386 ++ ) {
struct V_234 * V_1387 =
& V_231 -> V_253 [ V_1386 ] ;
if ( V_235 == V_1387 -> V_255 ) {
V_722 |= 1 << V_1386 ;
break;
}
}
if ( V_1386 == V_231 -> V_252 )
return 0 ;
}
return V_722 ;
}
static bool F_296 ( struct V_230 * V_231 ,
T_2 * V_1141 , T_2 V_1385 ,
T_2 V_239 [ V_1388 ] )
{
T_2 V_153 ;
memset ( V_239 , 0 , V_1388 ) ;
for ( V_153 = 0 ; V_153 < V_1385 ; V_153 ++ ) {
int V_1386 , V_1389 ;
V_1386 = V_1141 [ V_153 ] / 8 ;
V_1389 = F_156 ( V_1141 [ V_153 ] % 8 ) ;
if ( ( V_1386 < 0 ) || ( V_1386 >= V_1388 ) )
return false ;
if ( V_231 -> V_236 . V_239 . V_1390 [ V_1386 ] & V_1389 )
V_239 [ V_1386 ] |= V_1389 ;
else
return false ;
}
return true ;
}
static T_3 F_297 ( T_2 V_1391 )
{
T_3 V_1392 = 0 ;
switch ( V_1391 ) {
case V_1393 :
break;
case V_1394 :
V_1392 = 0x00FF ;
break;
case V_1395 :
V_1392 = 0x01FF ;
break;
case V_1396 :
V_1392 = 0x03FF ;
break;
default:
break;
}
return V_1392 ;
}
static void F_298 ( T_3 V_1391 ,
T_3 V_1397 [ V_1398 ] )
{
T_2 V_748 ;
for ( V_748 = 0 ; V_748 < V_1398 ; V_748 ++ ) {
V_1397 [ V_748 ] = F_297 ( V_1391 & 0x03 ) ;
V_1391 >>= 2 ;
}
}
static bool F_299 ( struct V_230 * V_231 ,
struct V_1399 * V_805 ,
T_3 V_239 [ V_1398 ] )
{
T_3 V_1400 = F_300 ( V_231 -> V_246 . V_249 . V_1400 ) ;
T_3 V_1401 [ V_1398 ] = {} ;
T_2 V_153 ;
if ( ! V_231 -> V_246 . V_247 )
return false ;
memset ( V_239 , 0 , sizeof( T_3 ) * V_1398 ) ;
F_298 ( V_1400 , V_1401 ) ;
for ( V_153 = 0 ; V_153 < V_1398 ; V_153 ++ ) {
if ( ( V_1401 [ V_153 ] & V_805 -> V_239 [ V_153 ] ) == V_805 -> V_239 [ V_153 ] )
V_239 [ V_153 ] = V_805 -> V_239 [ V_153 ] ;
else
return false ;
}
return true ;
}
static int F_301 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_4 * V_95 [ V_1402 + 1 ] ;
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1403 V_722 ;
int V_134 , V_153 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_4 * V_1404 ;
struct V_230 * V_231 ;
T_3 V_1405 ;
if ( ! V_7 -> V_337 -> V_392 )
return - V_522 ;
memset ( & V_722 , 0 , sizeof( V_722 ) ) ;
for ( V_153 = 0 ; V_153 < V_348 ; V_153 ++ ) {
V_231 = V_7 -> V_18 . V_349 [ V_153 ] ;
if ( ! V_231 )
continue;
V_722 . V_1406 [ V_153 ] . V_1407 = ( 1 << V_231 -> V_252 ) - 1 ;
memcpy ( V_722 . V_1406 [ V_153 ] . V_1408 ,
V_231 -> V_236 . V_239 . V_1390 ,
sizeof( V_722 . V_1406 [ V_153 ] . V_1408 ) ) ;
if ( ! V_231 -> V_246 . V_247 )
continue;
V_1405 = F_300 ( V_231 -> V_246 . V_249 . V_1400 ) ;
F_298 ( V_1405 , V_722 . V_1406 [ V_153 ] . V_249 ) ;
}
if ( ! V_30 -> V_5 [ V_1409 ] )
goto V_578;
F_113 ( V_1410 > V_1388 * 8 ) ;
F_39 (tx_rates, info->attrs[NL80211_ATTR_TX_RATES], rem) {
enum V_281 V_282 = F_219 ( V_1404 ) ;
int V_35 ;
if ( V_282 < 0 || V_282 >= V_348 )
return - V_16 ;
V_231 = V_7 -> V_18 . V_349 [ V_282 ] ;
if ( V_231 == NULL )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1402 , F_23 ( V_1404 ) ,
F_24 ( V_1404 ) , V_1411 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1412 ] ) {
V_722 . V_1406 [ V_282 ] . V_1407 = F_295 (
V_231 ,
F_23 ( V_95 [ V_1412 ] ) ,
F_24 ( V_95 [ V_1412 ] ) ) ;
if ( ( V_722 . V_1406 [ V_282 ] . V_1407 == 0 ) &&
F_24 ( V_95 [ V_1412 ] ) )
return - V_16 ;
}
if ( V_95 [ V_1413 ] ) {
if ( ! F_296 (
V_231 ,
F_23 ( V_95 [ V_1413 ] ) ,
F_24 ( V_95 [ V_1413 ] ) ,
V_722 . V_1406 [ V_282 ] . V_1408 ) )
return - V_16 ;
}
if ( V_95 [ V_1414 ] ) {
if ( ! F_299 (
V_231 ,
F_23 ( V_95 [ V_1414 ] ) ,
V_722 . V_1406 [ V_282 ] . V_249 ) )
return - V_16 ;
}
if ( V_95 [ V_1415 ] ) {
V_722 . V_1406 [ V_282 ] . V_1416 =
F_34 ( V_95 [ V_1415 ] ) ;
if ( V_722 . V_1406 [ V_282 ] . V_1416 > V_1417 )
return - V_16 ;
}
if ( V_722 . V_1406 [ V_282 ] . V_1407 == 0 ) {
if ( ! ( V_7 -> V_18 . V_349 [ V_282 ] -> V_236 . V_237 ||
V_7 -> V_18 . V_349 [ V_282 ] -> V_246 . V_247 ) )
return - V_16 ;
for ( V_153 = 0 ; V_153 < V_1388 ; V_153 ++ )
if ( V_722 . V_1406 [ V_282 ] . V_1408 [ V_153 ] )
goto V_578;
for ( V_153 = 0 ; V_153 < V_1398 ; V_153 ++ )
if ( V_722 . V_1406 [ V_282 ] . V_249 [ V_153 ] )
goto V_578;
return - V_16 ;
}
}
V_578:
return F_302 ( V_7 , V_521 , NULL , & V_722 ) ;
}
static int F_303 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
T_3 V_1418 = V_269 | V_1419 ;
if ( ! V_30 -> V_5 [ V_1420 ] )
return - V_16 ;
if ( V_30 -> V_5 [ V_268 ] )
V_1418 = F_78 ( V_30 -> V_5 [ V_268 ] ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
case V_605 :
break;
default:
return - V_522 ;
}
if ( ! V_7 -> V_337 -> V_394 )
return - V_522 ;
return F_304 ( V_17 , V_30 -> V_485 , V_1418 ,
F_23 ( V_30 -> V_5 [ V_1420 ] ) ,
F_24 ( V_30 -> V_5 [ V_1420 ] ) ) ;
}
static int F_305 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
struct V_501 V_502 ;
int V_35 ;
void * V_275 = NULL ;
T_1 V_622 ;
struct V_31 * V_53 = NULL ;
struct V_1421 V_137 = {
. V_1422 =
V_30 -> V_5 [ V_1423 ] ,
} ;
if ( ! V_30 -> V_5 [ V_1424 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_394 )
return - V_522 ;
switch ( V_17 -> V_141 ) {
case V_605 :
if ( ! V_30 -> V_5 [ V_504 ] )
return - V_16 ;
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_145 :
case V_144 :
break;
default:
return - V_522 ;
}
if ( V_30 -> V_5 [ V_1380 ] ) {
if ( ! ( V_7 -> V_18 . V_51 & V_441 ) )
return - V_16 ;
V_137 . V_1425 = F_4 ( V_30 -> V_5 [ V_1380 ] ) ;
if ( V_137 . V_1425 < V_1381 ||
V_137 . V_1425 > V_7 -> V_18 . V_440 )
return - V_16 ;
}
V_137 . V_1426 = V_30 -> V_5 [ V_442 ] ;
if ( V_137 . V_1426 && ! ( V_7 -> V_18 . V_51 & V_441 ) )
return - V_16 ;
V_137 . V_1146 = F_203 ( V_30 -> V_5 [ V_1147 ] ) ;
V_502 . V_55 = NULL ;
if ( V_30 -> V_5 [ V_504 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_502 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_502 . V_55 && V_137 . V_1426 )
return - V_16 ;
V_137 . V_1427 = F_23 ( V_30 -> V_5 [ V_1424 ] ) ;
V_137 . V_47 = F_24 ( V_30 -> V_5 [ V_1424 ] ) ;
if ( V_30 -> V_5 [ V_1428 ] ) {
int V_47 = F_24 ( V_30 -> V_5 [ V_1428 ] ) ;
int V_153 ;
if ( V_47 % sizeof( T_3 ) )
return - V_16 ;
V_137 . V_1429 = V_47 / sizeof( T_3 ) ;
V_137 . V_1430 =
F_23 ( V_30 -> V_5 [ V_1428 ] ) ;
for ( V_153 = 0 ; V_153 < V_137 . V_1429 ; V_153 ++ ) {
if ( V_137 . V_1430 [ V_153 ] >= V_137 . V_47 )
return - V_16 ;
}
}
if ( ! V_137 . V_1422 ) {
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1431 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_632;
}
}
V_137 . V_55 = V_502 . V_55 ;
V_35 = F_306 ( V_7 , V_17 , & V_137 , & V_622 ) ;
if ( V_35 )
goto V_632;
if ( V_53 ) {
if ( F_104 ( V_53 , V_1383 , V_622 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
}
return 0 ;
V_61:
V_35 = - V_91 ;
V_632:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_307 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
T_1 V_622 ;
if ( ! V_30 -> V_5 [ V_1383 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_396 )
return - V_522 ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_146 :
case V_148 :
case V_142 :
case V_143 :
case V_144 :
case V_605 :
break;
default:
return - V_522 ;
}
V_622 = F_5 ( V_30 -> V_5 [ V_1383 ] ) ;
return F_308 ( V_7 , V_17 , V_622 ) ;
}
static int F_309 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 V_1432 ;
bool V_274 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1433 ] )
return - V_16 ;
V_1432 = F_4 ( V_30 -> V_5 [ V_1433 ] ) ;
if ( V_1432 != V_1434 && V_1432 != V_1435 )
return - V_16 ;
V_17 = V_521 -> V_28 ;
if ( ! V_7 -> V_337 -> V_1436 )
return - V_522 ;
V_274 = ( V_1432 == V_1435 ) ? true : false ;
if ( V_274 == V_17 -> V_1437 )
return 0 ;
V_35 = F_310 ( V_7 , V_521 , V_274 , V_17 -> V_1438 ) ;
if ( ! V_35 )
V_17 -> V_1437 = V_274 ;
return V_35 ;
}
static int F_311 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
enum V_1439 V_1432 ;
struct V_1 * V_17 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_31 * V_53 ;
void * V_275 ;
int V_35 ;
V_17 = V_521 -> V_28 ;
if ( ! V_7 -> V_337 -> V_1436 )
return - V_522 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1440 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_632;
}
if ( V_17 -> V_1437 )
V_1432 = V_1435 ;
else
V_1432 = V_1434 ;
if ( F_28 ( V_53 , V_1433 , V_1432 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_632:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_312 ( struct V_29 * V_30 ,
V_22 V_235 , V_22 V_1441 , V_22 V_1442 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
if ( V_235 > 100 || V_1442 > V_1443 )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_1444 )
return - V_522 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_522 ;
return F_313 ( V_7 , V_521 , V_235 , V_1441 , V_1442 ) ;
}
static int F_314 ( struct V_29 * V_30 ,
T_11 V_1445 , V_22 V_1446 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
if ( V_1445 > 0 )
return - V_16 ;
if ( V_1445 == 0 )
V_1446 = 0 ;
if ( ! V_7 -> V_337 -> V_1447 )
return - V_522 ;
if ( V_17 -> V_141 != V_147 &&
V_17 -> V_141 != V_148 )
return - V_522 ;
return F_315 ( V_7 , V_521 , V_1445 , V_1446 ) ;
}
static int F_316 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_4 * V_5 [ V_1448 + 1 ] ;
struct V_4 * V_1449 ;
int V_35 ;
V_1449 = V_30 -> V_5 [ V_1450 ] ;
if ( ! V_1449 )
return - V_16 ;
V_35 = F_33 ( V_5 , V_1448 , V_1449 ,
V_1451 ) ;
if ( V_35 )
return V_35 ;
if ( V_5 [ V_1452 ] &&
V_5 [ V_1453 ] ) {
T_11 V_1445 = V_1068 ( V_5 [ V_1452 ] ) ;
V_22 V_1446 = F_4 ( V_5 [ V_1453 ] ) ;
return F_314 ( V_30 , V_1445 , V_1446 ) ;
}
if ( V_5 [ V_1454 ] &&
V_5 [ V_1455 ] &&
V_5 [ V_1456 ] ) {
V_22 V_235 = F_4 ( V_5 [ V_1454 ] ) ;
V_22 V_1441 = F_4 ( V_5 [ V_1455 ] ) ;
V_22 V_1442 = F_4 ( V_5 [ V_1456 ] ) ;
return F_312 ( V_30 , V_235 , V_1441 , V_1442 ) ;
}
return - V_16 ;
}
static int F_317 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1002 V_1064 ;
struct V_1070 V_1071 ;
int V_35 ;
memcpy ( & V_1064 , & V_1006 , sizeof( V_1064 ) ) ;
memcpy ( & V_1071 , & V_1457 , sizeof( V_1071 ) ) ;
if ( V_30 -> V_5 [ V_1008 ] ) {
V_35 = F_200 ( V_30 , & V_1064 , NULL ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_30 -> V_5 [ V_596 ] ||
! F_24 ( V_30 -> V_5 [ V_596 ] ) )
return - V_16 ;
V_1071 . V_1458 = F_23 ( V_30 -> V_5 [ V_596 ] ) ;
V_1071 . V_1005 = F_24 ( V_30 -> V_5 [ V_596 ] ) ;
if ( V_30 -> V_5 [ V_1321 ] &&
! F_259 ( V_7 , V_1071 . V_1312 ,
F_4 ( V_30 -> V_5 [ V_1321 ] ) ) )
return - V_16 ;
if ( V_30 -> V_5 [ V_684 ] ) {
V_1071 . V_523 =
F_4 ( V_30 -> V_5 [ V_684 ] ) ;
if ( V_1071 . V_523 < 10 ||
V_1071 . V_523 > 10000 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_685 ] ) {
V_1071 . V_687 =
F_4 ( V_30 -> V_5 [ V_685 ] ) ;
if ( V_1071 . V_687 < 1 || V_1071 . V_687 > 100 )
return - V_16 ;
}
if ( V_30 -> V_5 [ V_1073 ] ) {
V_35 = F_202 ( V_30 , & V_1071 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_1071 . V_1093 )
V_1064 . V_1024 = false ;
if ( V_30 -> V_5 [ V_504 ] ) {
V_35 = F_80 ( V_7 , V_30 , & V_1071 . V_502 ) ;
if ( V_35 )
return V_35 ;
} else {
V_1071 . V_502 . V_55 = NULL ;
}
if ( V_30 -> V_5 [ V_970 ] ) {
T_2 * V_1141 = F_23 ( V_30 -> V_5 [ V_970 ] ) ;
int V_1320 =
F_24 ( V_30 -> V_5 [ V_970 ] ) ;
struct V_230 * V_231 ;
if ( ! V_1071 . V_502 . V_55 )
return - V_16 ;
V_231 = V_7 -> V_18 . V_349 [ V_1071 . V_502 . V_55 -> V_282 ] ;
V_35 = F_220 ( V_231 , V_1141 , V_1320 ,
& V_1071 . V_971 ) ;
if ( V_35 )
return V_35 ;
}
return F_318 ( V_7 , V_521 , & V_1071 , & V_1064 ) ;
}
static int F_319 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
return F_320 ( V_7 , V_521 ) ;
}
static int F_321 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1459 * V_183 = V_7 -> V_18 . V_1460 ;
struct V_4 * V_1461 , * V_1462 ;
int V_153 , V_1463 ;
if ( ! V_183 -> V_213 )
return 0 ;
V_1461 = F_47 ( V_53 , V_222 ) ;
if ( ! V_1461 )
return - V_91 ;
for ( V_153 = 0 ; V_153 < V_183 -> V_213 ; V_153 ++ ) {
V_1462 = F_47 ( V_53 , V_153 + 1 ) ;
if ( ! V_1462 )
return - V_91 ;
V_1463 = V_183 -> V_1464 [ V_153 ] . V_1465 ;
if ( F_51 ( V_53 , V_1466 , F_322 ( V_1463 , 8 ) ,
V_183 -> V_1464 [ V_153 ] . V_722 ) ||
F_51 ( V_53 , V_1467 , V_1463 ,
V_183 -> V_1464 [ V_153 ] . V_1468 ) ||
F_28 ( V_53 , V_1469 ,
V_183 -> V_1464 [ V_153 ] . V_1470 ) )
return - V_91 ;
F_48 ( V_53 , V_1462 ) ;
}
F_48 ( V_53 , V_1461 ) ;
return 0 ;
}
static int F_323 ( struct V_31 * V_53 ,
struct V_1471 * V_182 )
{
struct V_4 * V_184 ;
if ( ! V_182 )
return 0 ;
V_184 = F_47 ( V_53 , V_185 ) ;
if ( ! V_184 )
return - V_91 ;
if ( F_324 ( V_53 , V_1472 , V_182 -> V_1473 ) ||
F_324 ( V_53 , V_1474 , V_182 -> V_929 ) ||
F_51 ( V_53 , V_1475 , V_568 , V_182 -> V_1476 ) ||
F_55 ( V_53 , V_1477 , V_182 -> V_1478 ) ||
F_55 ( V_53 , V_1479 , V_182 -> V_1480 ) ||
F_51 ( V_53 , V_186 ,
V_182 -> V_1481 , V_182 -> V_1482 ) ||
F_28 ( V_53 , V_191 ,
V_182 -> V_1483 ) ||
F_51 ( V_53 , V_193 ,
V_182 -> V_1484 , V_182 -> V_1485 ) ||
F_51 ( V_53 , V_1486 ,
F_322 ( V_182 -> V_1484 , 8 ) , V_182 -> V_1487 ) )
return - V_91 ;
if ( V_182 -> V_1488 . V_47 &&
F_51 ( V_53 , V_188 ,
sizeof( V_182 -> V_1488 ) , & V_182 -> V_1488 ) )
return - V_91 ;
if ( V_182 -> V_1489 . V_47 &&
F_51 ( V_53 , V_190 ,
sizeof( V_182 -> V_1489 ) + V_182 -> V_1490 ,
& V_182 -> V_1489 ) )
return - V_91 ;
F_48 ( V_53 , V_184 ) ;
return 0 ;
}
static int F_325 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_31 * V_53 ;
void * V_275 ;
V_22 V_1491 = V_579 ;
if ( ! V_7 -> V_18 . V_183 )
return - V_522 ;
if ( V_7 -> V_18 . V_1460 && V_7 -> V_18 . V_1460 -> V_182 ) {
V_1491 += V_7 -> V_18 . V_1460 -> V_182 -> V_1490 +
V_7 -> V_18 . V_1460 -> V_182 -> V_1481 +
V_7 -> V_18 . V_1460 -> V_182 -> V_1484 +
V_7 -> V_18 . V_1460 -> V_182 -> V_1484 / 8 ;
}
V_53 = F_74 ( V_1491 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1492 ) ;
if ( ! V_275 )
goto V_61;
if ( V_7 -> V_18 . V_1460 ) {
struct V_4 * V_195 ;
V_195 = F_47 ( V_53 , V_1493 ) ;
if ( ! V_195 )
goto V_61;
if ( ( V_7 -> V_18 . V_1460 -> V_1494 &&
F_29 ( V_53 , V_198 ) ) ||
( V_7 -> V_18 . V_1460 -> V_437 &&
F_29 ( V_53 , V_200 ) ) ||
( V_7 -> V_18 . V_1460 -> V_1495 &&
F_29 ( V_53 , V_202 ) ) ||
( V_7 -> V_18 . V_1460 -> V_1496 &&
F_29 ( V_53 , V_206 ) ) ||
( V_7 -> V_18 . V_1460 -> V_1497 &&
F_29 ( V_53 , V_208 ) ) ||
( V_7 -> V_18 . V_1460 -> V_1498 &&
F_29 ( V_53 , V_210 ) ) ||
( V_7 -> V_18 . V_1460 -> V_1499 &&
F_29 ( V_53 , V_212 ) ) )
goto V_61;
if ( F_321 ( V_53 , V_7 ) )
goto V_61;
if ( F_323 ( V_53 ,
V_7 -> V_18 . V_1460 -> V_182 ) )
goto V_61;
F_48 ( V_53 , V_195 ) ;
}
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
static int F_326 ( struct V_6 * V_7 ,
struct V_4 * V_45 ,
struct V_1459 * V_1500 )
{
struct V_4 * V_95 [ V_1501 ] ;
struct V_1471 * V_1064 ;
struct V_1502 * V_189 = NULL ;
struct V_1503 * V_50 = NULL ;
V_22 V_1491 ;
V_22 V_1504 , V_1505 , V_1490 = 0 , V_1506 ;
int V_35 , V_1507 ;
if ( ! V_7 -> V_18 . V_183 -> V_182 )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1508 ,
F_23 ( V_45 ) , F_24 ( V_45 ) ,
V_1509 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_95 [ V_1472 ] ||
! V_95 [ V_1474 ] ||
! V_95 [ V_1475 ] ||
! V_95 [ V_1479 ] ||
! V_95 [ V_186 ] ||
! V_95 [ V_191 ] ||
! V_95 [ V_193 ] ||
! V_95 [ V_1486 ] )
return - V_16 ;
V_1504 = F_24 ( V_95 [ V_186 ] ) ;
if ( V_1504 > V_7 -> V_18 . V_183 -> V_182 -> V_187 )
return - V_16 ;
if ( F_4 ( V_95 [ V_191 ] ) >
V_7 -> V_18 . V_183 -> V_182 -> V_192 ||
F_4 ( V_95 [ V_191 ] ) == 0 )
return - V_16 ;
V_1505 = F_24 ( V_95 [ V_193 ] ) ;
if ( V_1505 > V_7 -> V_18 . V_183 -> V_182 -> V_194 )
return - V_16 ;
V_1506 = F_24 ( V_95 [ V_1486 ] ) ;
if ( V_1506 != F_322 ( V_1505 , 8 ) )
return - V_16 ;
if ( V_95 [ V_190 ] ) {
V_22 V_1510 = F_24 ( V_95 [ V_190 ] ) ;
V_189 = F_23 ( V_95 [ V_190 ] ) ;
V_1490 = V_1510 - sizeof( * V_189 ) ;
if ( ! V_189 -> V_47 || V_1490 % V_189 -> V_47 )
return - V_16 ;
if ( ! V_7 -> V_18 . V_183 -> V_182 -> V_189 )
return - V_16 ;
if ( V_189 -> V_47 > V_7 -> V_18 . V_183 -> V_182 -> V_189 -> V_1511 )
return - V_16 ;
if ( V_189 -> V_47 < V_7 -> V_18 . V_183 -> V_182 -> V_189 -> V_1512 )
return - V_16 ;
if ( V_1490 > V_7 -> V_18 . V_183 -> V_182 -> V_189 -> V_1513 )
return - V_16 ;
if ( V_189 -> V_1190 + V_189 -> V_47 > V_1504 )
return - V_16 ;
}
if ( V_95 [ V_188 ] ) {
V_50 = F_23 ( V_95 [ V_188 ] ) ;
if ( ! V_7 -> V_18 . V_183 -> V_182 -> V_50 )
return - V_16 ;
if ( V_50 -> V_47 == 0 || V_50 -> V_47 > 4 )
return - V_16 ;
if ( V_50 -> V_47 + V_50 -> V_1190 > V_1504 )
return - V_16 ;
}
V_1491 = sizeof( * V_1064 ) ;
V_1491 += V_1504 ;
V_1491 += V_1505 + V_1506 ;
V_1491 += V_1490 ;
V_1064 = F_38 ( V_1491 , V_135 ) ;
if ( ! V_1064 )
return - V_136 ;
V_1064 -> V_1473 = F_327 ( V_95 [ V_1472 ] ) ;
V_1064 -> V_929 = F_327 ( V_95 [ V_1474 ] ) ;
memcpy ( V_1064 -> V_1476 , F_23 ( V_95 [ V_1475 ] ) ,
V_568 ) ;
if ( V_95 [ V_1477 ] )
V_1507 = F_78 ( V_95 [ V_1477 ] ) ;
else
V_1507 = 0 ;
#ifdef F_328
V_35 = F_329 ( F_7 ( & V_7 -> V_18 ) , V_1514 , V_1515 ,
V_1516 , & V_1064 -> V_1517 , 1 ) ;
if ( V_35 ) {
F_41 ( V_1064 ) ;
return V_35 ;
}
if ( F_330 ( V_1064 -> V_1517 -> V_44 , V_1507 ) ) {
F_331 ( V_1064 -> V_1517 ) ;
F_41 ( V_1064 ) ;
return - V_1518 ;
}
V_1064 -> V_1478 = F_332 ( V_1064 -> V_1517 -> V_44 ) -> V_1519 ;
#else
if ( ! V_1507 ) {
F_41 ( V_1064 ) ;
return - V_16 ;
}
V_1064 -> V_1478 = V_1507 ;
#endif
V_1064 -> V_1480 = F_78 ( V_95 [ V_1479 ] ) ;
V_1064 -> V_1481 = V_1504 ;
V_1064 -> V_1482 = ( T_2 * ) V_1064 + sizeof( * V_1064 ) + V_1490 ;
memcpy ( ( void * ) V_1064 -> V_1482 ,
F_23 ( V_95 [ V_186 ] ) ,
V_1504 ) ;
if ( V_50 )
V_1064 -> V_1488 = * V_50 ;
V_1064 -> V_1483 = F_4 ( V_95 [ V_191 ] ) ;
V_1064 -> V_1484 = V_1505 ;
V_1064 -> V_1485 = ( T_2 * ) V_1064 + sizeof( * V_1064 ) + V_1490 + V_1504 ;
memcpy ( ( void * ) V_1064 -> V_1485 ,
F_23 ( V_95 [ V_193 ] ) ,
V_1505 ) ;
V_1064 -> V_1487 = ( T_2 * ) V_1064 + sizeof( * V_1064 ) + V_1490 +
V_1504 + V_1505 ;
memcpy ( ( void * ) V_1064 -> V_1487 ,
F_23 ( V_95 [ V_1486 ] ) ,
V_1506 ) ;
if ( V_189 ) {
V_1064 -> V_1490 = V_1490 ;
memcpy ( & V_1064 -> V_1489 , V_189 , sizeof( * V_189 ) + V_1490 ) ;
}
V_1500 -> V_182 = V_1064 ;
return 0 ;
}
static int F_333 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_4 * V_95 [ V_1520 ] ;
struct V_1459 V_1521 = {} ;
struct V_1459 * V_1522 ;
const struct V_1523 * V_183 = V_7 -> V_18 . V_183 ;
int V_35 , V_153 ;
bool V_1524 = V_7 -> V_18 . V_1460 ;
if ( ! V_183 )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_1493 ] ) {
F_334 ( V_7 ) ;
V_7 -> V_18 . V_1460 = NULL ;
goto V_1525;
}
V_35 = F_96 ( V_95 , V_1526 ,
F_23 ( V_30 -> V_5 [ V_1493 ] ) ,
F_24 ( V_30 -> V_5 [ V_1493 ] ) ,
V_1527 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_198 ] ) {
if ( ! ( V_183 -> V_51 & V_197 ) )
return - V_16 ;
V_1521 . V_1494 = true ;
}
if ( V_95 [ V_200 ] ) {
if ( ! ( V_183 -> V_51 & V_199 ) )
return - V_16 ;
V_1521 . V_437 = true ;
}
if ( V_95 [ V_202 ] ) {
if ( ! ( V_183 -> V_51 & V_201 ) )
return - V_16 ;
V_1521 . V_1495 = true ;
}
if ( V_95 [ V_204 ] )
return - V_16 ;
if ( V_95 [ V_206 ] ) {
if ( ! ( V_183 -> V_51 & V_205 ) )
return - V_16 ;
V_1521 . V_1496 = true ;
}
if ( V_95 [ V_208 ] ) {
if ( ! ( V_183 -> V_51 & V_207 ) )
return - V_16 ;
V_1521 . V_1497 = true ;
}
if ( V_95 [ V_210 ] ) {
if ( ! ( V_183 -> V_51 & V_209 ) )
return - V_16 ;
V_1521 . V_1498 = true ;
}
if ( V_95 [ V_212 ] ) {
if ( ! ( V_183 -> V_51 & V_211 ) )
return - V_16 ;
V_1521 . V_1499 = true ;
}
if ( V_95 [ V_222 ] ) {
struct V_4 * V_215 ;
int V_213 = 0 ;
int V_134 , V_1463 , V_1528 , V_1470 ;
struct V_4 * V_1529 [ V_1530 ] ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem)
V_213 ++ ;
if ( V_213 > V_183 -> V_213 )
return - V_16 ;
V_1521 . V_1464 = F_335 ( V_213 ,
sizeof( V_1521 . V_1464 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1521 . V_1464 )
return - V_136 ;
V_1521 . V_213 = V_213 ;
V_153 = 0 ;
F_39 (pat, tb[NL80211_WOWLAN_TRIG_PKT_PATTERN],
rem) {
T_2 * V_1531 ;
F_96 ( V_1529 , V_1532 , F_23 ( V_215 ) ,
F_24 ( V_215 ) , NULL ) ;
V_35 = - V_16 ;
if ( ! V_1529 [ V_1466 ] ||
! V_1529 [ V_1467 ] )
goto error;
V_1463 = F_24 ( V_1529 [ V_1467 ] ) ;
V_1528 = F_322 ( V_1463 , 8 ) ;
if ( F_24 ( V_1529 [ V_1466 ] ) != V_1528 )
goto error;
if ( V_1463 > V_183 -> V_220 ||
V_1463 < V_183 -> V_218 )
goto error;
if ( ! V_1529 [ V_1469 ] )
V_1470 = 0 ;
else
V_1470 = F_4 (
V_1529 [ V_1469 ] ) ;
if ( V_1470 > V_183 -> V_221 )
goto error;
V_1521 . V_1464 [ V_153 ] . V_1470 = V_1470 ;
V_1531 = F_336 ( V_1528 + V_1463 , V_135 ) ;
if ( ! V_1531 ) {
V_35 = - V_136 ;
goto error;
}
V_1521 . V_1464 [ V_153 ] . V_722 = V_1531 ;
memcpy ( V_1531 , F_23 ( V_1529 [ V_1466 ] ) ,
V_1528 ) ;
V_1531 += V_1528 ;
V_1521 . V_1464 [ V_153 ] . V_1468 = V_1531 ;
V_1521 . V_1464 [ V_153 ] . V_1465 = V_1463 ;
memcpy ( V_1531 ,
F_23 ( V_1529 [ V_1467 ] ) ,
V_1463 ) ;
V_153 ++ ;
}
}
if ( V_95 [ V_185 ] ) {
V_35 = F_326 (
V_7 , V_95 [ V_185 ] ,
& V_1521 ) ;
if ( V_35 )
goto error;
}
V_1522 = F_337 ( & V_1521 , sizeof( V_1521 ) , V_135 ) ;
if ( ! V_1522 ) {
V_35 = - V_136 ;
goto error;
}
F_334 ( V_7 ) ;
V_7 -> V_18 . V_1460 = V_1522 ;
V_1525:
if ( V_7 -> V_337 -> V_1525 &&
V_1524 != ! ! V_7 -> V_18 . V_1460 )
F_338 ( V_7 , V_7 -> V_18 . V_1460 ) ;
return 0 ;
error:
for ( V_153 = 0 ; V_153 < V_1521 . V_213 ; V_153 ++ )
F_41 ( V_1521 . V_1464 [ V_153 ] . V_722 ) ;
F_41 ( V_1521 . V_1464 ) ;
if ( V_1521 . V_182 && V_1521 . V_182 -> V_1517 )
F_331 ( V_1521 . V_182 -> V_1517 ) ;
F_41 ( V_1521 . V_182 ) ;
return V_35 ;
}
static int F_339 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_4 * V_1461 , * V_1462 , * V_1533 , * V_1534 ;
int V_153 , V_155 , V_1463 ;
struct V_1535 * V_224 ;
if ( ! V_7 -> V_225 -> V_227 )
return 0 ;
V_1534 = F_47 ( V_53 , V_229 ) ;
if ( ! V_1534 )
return - V_91 ;
for ( V_153 = 0 ; V_153 < V_7 -> V_225 -> V_227 ; V_153 ++ ) {
V_1533 = F_47 ( V_53 , V_153 + 1 ) ;
if ( ! V_1533 )
return - V_91 ;
V_224 = & V_7 -> V_225 -> V_1536 [ V_153 ] ;
if ( F_28 ( V_53 , V_1537 ,
V_224 -> V_1538 ) )
return - V_91 ;
if ( F_28 ( V_53 , V_1539 ,
V_224 -> V_1540 ) )
return - V_91 ;
V_1461 = F_47 ( V_53 ,
V_1541 ) ;
if ( ! V_1461 )
return - V_91 ;
for ( V_155 = 0 ; V_155 < V_224 -> V_213 ; V_155 ++ ) {
V_1462 = F_47 ( V_53 , V_155 + 1 ) ;
if ( ! V_1462 )
return - V_91 ;
V_1463 = V_224 -> V_1464 [ V_155 ] . V_1465 ;
if ( F_51 ( V_53 , V_1466 ,
F_322 ( V_1463 , 8 ) ,
V_224 -> V_1464 [ V_155 ] . V_722 ) ||
F_51 ( V_53 , V_1467 , V_1463 ,
V_224 -> V_1464 [ V_155 ] . V_1468 ) ||
F_28 ( V_53 , V_1469 ,
V_224 -> V_1464 [ V_155 ] . V_1470 ) )
return - V_91 ;
F_48 ( V_53 , V_1462 ) ;
}
F_48 ( V_53 , V_1461 ) ;
F_48 ( V_53 , V_1533 ) ;
}
F_48 ( V_53 , V_1534 ) ;
return 0 ;
}
static int F_340 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_31 * V_53 ;
void * V_275 ;
if ( ! V_7 -> V_18 . V_225 )
return - V_522 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1542 ) ;
if ( ! V_275 )
goto V_61;
if ( V_7 -> V_225 && F_339 ( V_53 , V_7 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_341 ( struct V_6 * V_7 )
{
struct V_1543 * V_225 = V_7 -> V_225 ;
int V_153 , V_155 ;
struct V_1535 * V_224 ;
if ( ! V_225 )
return;
for ( V_153 = 0 ; V_153 < V_225 -> V_227 ; V_153 ++ ) {
V_224 = & V_225 -> V_1536 [ V_153 ] ;
for ( V_155 = 0 ; V_155 < V_224 -> V_213 ; V_155 ++ )
F_41 ( V_224 -> V_1464 [ V_155 ] . V_722 ) ;
F_41 ( V_224 -> V_1464 ) ;
}
F_41 ( V_225 -> V_1536 ) ;
F_41 ( V_225 ) ;
V_7 -> V_225 = NULL ;
}
static int F_342 ( struct V_6 * V_7 ,
struct V_4 * V_224 ,
struct V_1535 * V_1544 )
{
int V_35 , V_153 ;
const struct V_1545 * V_225 = V_7 -> V_18 . V_225 ;
struct V_4 * V_95 [ V_1546 ] , * V_215 ;
int V_134 , V_1463 , V_1528 , V_1470 , V_213 = 0 ;
struct V_4 * V_1529 [ V_1530 ] ;
V_35 = F_96 ( V_95 , V_1547 , F_23 ( V_224 ) ,
F_24 ( V_224 ) , V_1548 ) ;
if ( V_35 )
return V_35 ;
if ( V_95 [ V_1537 ] )
V_1544 -> V_1538 =
F_4 ( V_95 [ V_1537 ] ) ;
if ( V_1544 -> V_1538 > V_225 -> V_228 )
return - V_16 ;
if ( V_95 [ V_1539 ] )
V_1544 -> V_1540 =
F_4 ( V_95 [ V_1539 ] ) ;
if ( V_1544 -> V_1540 != V_1549 &&
V_1544 -> V_1540 != V_1550 )
return - V_16 ;
if ( ! V_95 [ V_1541 ] )
return - V_16 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem)
V_213 ++ ;
if ( V_213 > V_225 -> V_213 )
return - V_16 ;
V_1544 -> V_1464 = F_335 ( V_213 , sizeof( V_1544 -> V_1464 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1544 -> V_1464 )
return - V_136 ;
V_1544 -> V_213 = V_213 ;
V_153 = 0 ;
F_39 (pat, tb[NL80211_ATTR_COALESCE_RULE_PKT_PATTERN],
rem) {
T_2 * V_1531 ;
F_96 ( V_1529 , V_1532 , F_23 ( V_215 ) ,
F_24 ( V_215 ) , NULL ) ;
if ( ! V_1529 [ V_1466 ] ||
! V_1529 [ V_1467 ] )
return - V_16 ;
V_1463 = F_24 ( V_1529 [ V_1467 ] ) ;
V_1528 = F_322 ( V_1463 , 8 ) ;
if ( F_24 ( V_1529 [ V_1466 ] ) != V_1528 )
return - V_16 ;
if ( V_1463 > V_225 -> V_220 ||
V_1463 < V_225 -> V_218 )
return - V_16 ;
if ( ! V_1529 [ V_1469 ] )
V_1470 = 0 ;
else
V_1470 = F_4 ( V_1529 [ V_1469 ] ) ;
if ( V_1470 > V_225 -> V_221 )
return - V_16 ;
V_1544 -> V_1464 [ V_153 ] . V_1470 = V_1470 ;
V_1531 = F_336 ( V_1528 + V_1463 , V_135 ) ;
if ( ! V_1531 )
return - V_136 ;
V_1544 -> V_1464 [ V_153 ] . V_722 = V_1531 ;
memcpy ( V_1531 , F_23 ( V_1529 [ V_1466 ] ) ,
V_1528 ) ;
V_1531 += V_1528 ;
V_1544 -> V_1464 [ V_153 ] . V_1468 = V_1531 ;
V_1544 -> V_1464 [ V_153 ] . V_1465 = V_1463 ;
memcpy ( V_1531 , F_23 ( V_1529 [ V_1467 ] ) ,
V_1463 ) ;
V_153 ++ ;
}
return 0 ;
}
static int F_343 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
const struct V_1545 * V_225 = V_7 -> V_18 . V_225 ;
struct V_1543 V_1551 = {} ;
struct V_1543 * V_1552 ;
int V_35 , V_1553 , V_227 = 0 , V_153 , V_155 ;
struct V_4 * V_224 ;
struct V_1535 * V_1554 ;
if ( ! V_7 -> V_18 . V_225 || ! V_7 -> V_337 -> V_1555 )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_229 ] ) {
F_341 ( V_7 ) ;
V_7 -> V_337 -> V_1555 ( & V_7 -> V_18 , NULL ) ;
return 0 ;
}
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule)
V_227 ++ ;
if ( V_227 > V_225 -> V_227 )
return - V_16 ;
V_1551 . V_1536 = F_335 ( V_227 , sizeof( V_1551 . V_1536 [ 0 ] ) ,
V_135 ) ;
if ( ! V_1551 . V_1536 )
return - V_136 ;
V_1551 . V_227 = V_227 ;
V_153 = 0 ;
F_39 (rule, info->attrs[NL80211_ATTR_COALESCE_RULE],
rem_rule) {
V_35 = F_342 ( V_7 , V_224 ,
& V_1551 . V_1536 [ V_153 ] ) ;
if ( V_35 )
goto error;
V_153 ++ ;
}
V_35 = V_7 -> V_337 -> V_1555 ( & V_7 -> V_18 , & V_1551 ) ;
if ( V_35 )
goto error;
V_1552 = F_337 ( & V_1551 , sizeof( V_1551 ) , V_135 ) ;
if ( ! V_1552 ) {
V_35 = - V_136 ;
goto error;
}
F_341 ( V_7 ) ;
V_7 -> V_225 = V_1552 ;
return 0 ;
error:
for ( V_153 = 0 ; V_153 < V_1551 . V_227 ; V_153 ++ ) {
V_1554 = & V_1551 . V_1536 [ V_153 ] ;
for ( V_155 = 0 ; V_155 < V_1554 -> V_213 ; V_155 ++ )
F_41 ( V_1554 -> V_1464 [ V_155 ] . V_722 ) ;
F_41 ( V_1554 -> V_1464 ) ;
}
F_41 ( V_1551 . V_1536 ) ;
return V_35 ;
}
static int F_344 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_4 * V_95 [ V_1556 ] ;
struct V_1557 V_1558 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1559 ] )
return - V_16 ;
V_35 = F_96 ( V_95 , V_1560 ,
F_23 ( V_30 -> V_5 [ V_1559 ] ) ,
F_24 ( V_30 -> V_5 [ V_1559 ] ) ,
V_1561 ) ;
if ( V_35 )
return V_35 ;
if ( F_24 ( V_95 [ V_1562 ] ) != V_1563 )
return - V_1564 ;
if ( F_24 ( V_95 [ V_1565 ] ) != V_1566 )
return - V_1564 ;
if ( F_24 ( V_95 [ V_1567 ] ) != V_1568 )
return - V_1564 ;
V_1558 . V_1569 = F_23 ( V_95 [ V_1565 ] ) ;
V_1558 . V_1570 = F_23 ( V_95 [ V_1567 ] ) ;
V_1558 . V_1571 = F_23 ( V_95 [ V_1562 ] ) ;
F_112 ( V_17 ) ;
if ( ! V_17 -> V_149 ) {
V_35 = - V_1180 ;
goto V_578;
}
if ( ! V_7 -> V_337 -> V_1572 ) {
V_35 = - V_522 ;
goto V_578;
}
V_35 = F_345 ( V_7 , V_521 , & V_1558 ) ;
V_578:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_346 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_16 ;
if ( V_17 -> V_1573 )
return - V_526 ;
V_17 -> V_1573 = V_30 -> V_485 ;
return 0 ;
}
static int F_347 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_31 * V_53 ;
void * V_275 ;
const T_2 * V_652 ;
T_1 V_622 ;
int V_35 ;
if ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
if ( ! V_7 -> V_337 -> V_411 )
return - V_522 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1574 ) ;
if ( ! V_275 ) {
V_35 = - V_91 ;
goto V_632;
}
V_652 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
V_35 = F_348 ( V_7 , V_521 , V_652 , & V_622 ) ;
if ( V_35 )
goto V_632;
if ( F_104 ( V_53 , V_1383 , V_622 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
V_35 = - V_91 ;
V_632:
F_75 ( V_53 ) ;
return V_35 ;
}
static int F_349 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1575 * V_1576 , * V_1577 ;
int V_1578 ;
if ( ! ( V_7 -> V_18 . V_51 & V_415 ) )
return - V_522 ;
V_1577 = F_38 ( sizeof( * V_1577 ) , V_135 ) ;
if ( ! V_1577 )
return - V_136 ;
F_242 ( & V_7 -> V_1579 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
if ( V_1576 -> V_1580 == V_30 -> V_485 ) {
V_1578 = - V_683 ;
goto V_856;
}
}
V_1577 -> V_1580 = V_30 -> V_485 ;
F_350 ( & V_1577 -> V_615 , & V_7 -> V_1581 ) ;
F_244 ( & V_7 -> V_1579 ) ;
return 0 ;
V_856:
F_244 ( & V_7 -> V_1579 ) ;
F_41 ( V_1577 ) ;
return V_1578 ;
}
static int F_351 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
int V_35 ;
if ( ! V_7 -> V_337 -> V_417 )
return - V_522 ;
if ( V_17 -> V_141 != V_605 )
return - V_522 ;
if ( V_17 -> V_1582 )
return 0 ;
if ( F_352 ( V_7 -> V_1583 ) )
return - V_1584 ;
V_35 = F_353 ( V_7 , V_17 ) ;
if ( V_35 )
return V_35 ;
V_17 -> V_1582 = true ;
V_7 -> V_1585 ++ ;
return 0 ;
}
static int F_354 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
if ( V_17 -> V_141 != V_605 )
return - V_522 ;
if ( ! V_7 -> V_337 -> V_1586 )
return - V_522 ;
F_355 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_356 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
void * V_275 ;
struct V_31 * V_53 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , V_30 -> V_485 , V_30 -> V_486 , 0 ,
V_1587 ) ;
if ( ! V_275 )
goto V_61;
if ( F_28 ( V_53 , V_1588 ,
V_1589 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_76 ( V_53 , V_30 ) ;
V_61:
F_267 ( V_53 ) ;
return - V_91 ;
}
static int F_357 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1590 V_1591 ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_1592 )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_1593 ] ||
! F_22 ( V_30 -> V_5 [ V_658 ] ) )
return - V_16 ;
memset ( & V_1591 , 0 , sizeof( V_1591 ) ) ;
V_1591 . V_1594 = F_78 ( V_30 -> V_5 [ V_1593 ] ) ;
V_1591 . V_1089 = F_23 ( V_30 -> V_5 [ V_658 ] ) ;
V_1591 . V_1090 = F_24 ( V_30 -> V_5 [ V_658 ] ) ;
return F_358 ( V_7 , V_521 , & V_1591 ) ;
}
static int F_359 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
enum V_1595 V_1275 = V_1596 ;
T_3 V_1379 ;
int V_477 ;
if ( ! V_7 -> V_337 -> V_423 )
return - V_522 ;
if ( F_59 ( ! V_7 -> V_337 -> V_425 ) )
return - V_16 ;
if ( V_7 -> V_1597 )
return - V_526 ;
if ( V_30 -> V_5 [ V_1598 ] )
V_1275 = F_78 ( V_30 -> V_5 [ V_1598 ] ) ;
if ( V_1275 >= V_1599 )
return - V_16 ;
if ( ! V_30 -> V_5 [ V_1600 ] )
return - V_16 ;
V_1379 =
F_78 ( V_30 -> V_5 [ V_1600 ] ) ;
if ( V_1379 > V_1601 )
return - V_1564 ;
V_477 = F_360 ( V_7 , V_17 , V_1275 , V_1379 ) ;
if ( ! V_477 )
V_7 -> V_1597 = V_30 -> V_485 ;
return V_477 ;
}
static int F_361 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
if ( ! V_7 -> V_337 -> V_425 )
return - V_522 ;
if ( V_7 -> V_1597 ) {
V_7 -> V_1597 = 0 ;
F_362 ( V_7 , V_17 ) ;
}
return 0 ;
}
static int F_363 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1 * V_17 =
F_1 ( F_94 ( V_30 ) , V_30 -> V_5 ) ;
int V_153 , V_35 ;
V_22 V_1602 , V_1333 ;
if ( ! V_7 -> V_18 . V_470 )
return - V_522 ;
if ( F_17 ( V_17 ) ) {
V_35 = F_18 ( V_17 ) ;
if ( V_35 != - V_16 )
return V_35 ;
V_17 = NULL ;
} else if ( V_17 -> V_18 != & V_7 -> V_18 ) {
return - V_16 ;
}
if ( ! V_30 -> V_5 [ V_1330 ] ||
! V_30 -> V_5 [ V_1332 ] )
return - V_16 ;
V_1602 = F_4 ( V_30 -> V_5 [ V_1330 ] ) ;
V_1333 = F_4 ( V_30 -> V_5 [ V_1332 ] ) ;
for ( V_153 = 0 ; V_153 < V_7 -> V_18 . V_466 ; V_153 ++ ) {
const struct V_1603 * V_1604 ;
void * V_138 = NULL ;
int V_47 = 0 ;
V_1604 = & V_7 -> V_18 . V_470 [ V_153 ] ;
if ( V_1604 -> V_30 . V_1331 != V_1602 || V_1604 -> V_30 . V_1333 != V_1333 )
continue;
if ( V_1604 -> V_51 & ( V_1605 |
V_1606 ) ) {
if ( ! V_17 )
return - V_16 ;
if ( V_1604 -> V_51 & V_1606 &&
! V_17 -> V_19 )
return - V_16 ;
if ( V_1604 -> V_51 & V_1607 ) {
if ( V_17 -> V_19 &&
! F_91 ( V_17 -> V_19 ) )
return - V_537 ;
if ( ! V_17 -> V_19 && ! V_17 -> V_1582 )
return - V_537 ;
}
} else {
V_17 = NULL ;
}
if ( V_30 -> V_5 [ V_469 ] ) {
V_138 = F_23 ( V_30 -> V_5 [ V_469 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_469 ] ) ;
}
V_7 -> V_1342 = V_30 ;
V_35 = V_7 -> V_18 . V_470 [ V_153 ] . F_364 ( & V_7 -> V_18 , V_17 ,
V_138 , V_47 ) ;
V_7 -> V_1342 = NULL ;
return V_35 ;
}
return - V_522 ;
}
struct V_31 * F_365 ( struct V_18 * V_18 ,
enum V_272 V_52 ,
enum V_1328 V_45 ,
int V_1327 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
if ( F_59 ( ! V_7 -> V_1342 ) )
return NULL ;
return F_266 ( V_7 , V_1327 ,
V_7 -> V_1342 -> V_485 ,
V_7 -> V_1342 -> V_486 ,
V_52 , V_45 , NULL , V_135 ) ;
}
int F_366 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = ( ( void * * ) V_32 -> V_34 ) [ 0 ] ;
void * V_275 = ( ( void * * ) V_32 -> V_34 ) [ 1 ] ;
struct V_4 * V_138 = ( ( void * * ) V_32 -> V_34 ) [ 2 ] ;
memset ( V_32 -> V_34 , 0 , sizeof( V_32 -> V_34 ) ) ;
if ( F_59 ( ! V_7 -> V_1342 ) ) {
F_267 ( V_32 ) ;
return - V_16 ;
}
F_48 ( V_32 , V_138 ) ;
F_66 ( V_32 , V_275 ) ;
return F_76 ( V_32 , V_7 -> V_1342 ) ;
}
static int F_367 ( struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_1608 * V_1609 = NULL ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
T_2 * V_46 , V_47 , V_1610 , V_1611 , V_1612 ;
int V_477 ;
if ( ! V_7 -> V_337 -> V_430 )
return - V_522 ;
if ( V_30 -> V_5 [ V_1613 ] ) {
V_46 = F_23 ( V_30 -> V_5 [ V_1613 ] ) ;
V_47 = F_24 ( V_30 -> V_5 [ V_1613 ] ) ;
if ( V_47 % 2 || V_47 < V_1614 ||
V_47 > V_1615 )
return - V_16 ;
V_1609 = F_38 ( sizeof( struct V_1608 ) , V_135 ) ;
if ( ! V_1609 )
return - V_136 ;
V_1610 = ( V_47 - V_1614 ) >> 1 ;
if ( V_1610 ) {
V_1611 = V_1610 *
sizeof( struct V_1616 ) ;
memcpy ( V_1609 -> V_1617 , V_46 , V_1611 ) ;
V_1609 -> V_1610 = V_1610 ;
for ( V_1612 = 0 ; V_1612 < V_1610 ; V_1612 ++ ) {
if ( V_1609 -> V_1617 [ V_1612 ] . V_1618 > 7 ) {
F_41 ( V_1609 ) ;
return - V_16 ;
}
}
V_46 += V_1611 ;
}
memcpy ( V_1609 -> V_1618 , V_46 , V_1614 ) ;
}
F_112 ( V_521 -> V_28 ) ;
V_477 = F_42 ( V_521 -> V_28 ) ;
if ( ! V_477 )
V_477 = F_368 ( V_7 , V_521 , V_1609 ) ;
F_114 ( V_521 -> V_28 ) ;
F_41 ( V_1609 ) ;
return V_477 ;
}
static int F_369 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
const T_2 * V_1369 ;
T_2 V_1619 , V_1618 ;
T_3 V_1620 = 0 ;
int V_35 ;
if ( ! ( V_7 -> V_18 . V_51 & V_432 ) )
return - V_522 ;
if ( ! V_30 -> V_5 [ V_1621 ] || ! V_30 -> V_5 [ V_529 ] ||
! V_30 -> V_5 [ V_1622 ] )
return - V_16 ;
V_1619 = F_34 ( V_30 -> V_5 [ V_1621 ] ) ;
if ( V_1619 >= V_1623 )
return - V_16 ;
V_1618 = F_34 ( V_30 -> V_5 [ V_1622 ] ) ;
if ( V_1618 >= V_1624 )
return - V_16 ;
if ( V_1619 < V_1625 ) {
if ( ! ( V_7 -> V_18 . V_51 & V_432 ) )
return - V_16 ;
} else {
return - V_16 ;
}
V_1369 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
if ( V_30 -> V_5 [ V_1626 ] ) {
V_1620 =
F_78 ( V_30 -> V_5 [ V_1626 ] ) ;
if ( ! V_1620 )
return - V_16 ;
}
F_112 ( V_17 ) ;
switch ( V_17 -> V_141 ) {
case V_147 :
case V_148 :
if ( V_17 -> V_149 )
break;
V_35 = - V_1180 ;
goto V_578;
default:
V_35 = - V_522 ;
goto V_578;
}
V_35 = F_370 ( V_7 , V_521 , V_1619 , V_1369 , V_1618 , V_1620 ) ;
V_578:
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_371 ( struct V_31 * V_32 , struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_484 [ 0 ] ;
struct V_25 * V_521 = V_30 -> V_484 [ 1 ] ;
struct V_1 * V_17 = V_521 -> V_28 ;
const T_2 * V_1369 ;
T_2 V_1619 ;
int V_35 ;
if ( ! V_30 -> V_5 [ V_1621 ] || ! V_30 -> V_5 [ V_529 ] )
return - V_16 ;
V_1619 = F_34 ( V_30 -> V_5 [ V_1621 ] ) ;
V_1369 = F_23 ( V_30 -> V_5 [ V_529 ] ) ;
F_112 ( V_17 ) ;
V_35 = F_372 ( V_7 , V_521 , V_1619 , V_1369 ) ;
F_114 ( V_17 ) ;
return V_35 ;
}
static int F_373 ( const struct V_1627 * V_337 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_25 * V_521 ;
bool V_1628 = V_337 -> V_1629 & V_1630 ;
if ( V_1628 )
F_14 () ;
if ( V_337 -> V_1629 & V_1631 ) {
V_7 = F_12 ( F_94 ( V_30 ) , V_30 ) ;
if ( F_17 ( V_7 ) ) {
if ( V_1628 )
F_20 () ;
return F_18 ( V_7 ) ;
}
V_30 -> V_484 [ 0 ] = V_7 ;
} else if ( V_337 -> V_1629 & V_1632 ||
V_337 -> V_1629 & V_1633 ) {
F_2 () ;
V_17 = F_1 ( F_94 ( V_30 ) ,
V_30 -> V_5 ) ;
if ( F_17 ( V_17 ) ) {
if ( V_1628 )
F_20 () ;
return F_18 ( V_17 ) ;
}
V_521 = V_17 -> V_19 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( V_337 -> V_1629 & V_1632 ) {
if ( ! V_521 ) {
if ( V_1628 )
F_20 () ;
return - V_16 ;
}
V_30 -> V_484 [ 1 ] = V_521 ;
} else {
V_30 -> V_484 [ 1 ] = V_17 ;
}
if ( V_521 ) {
if ( V_337 -> V_1629 & V_1634 &&
! F_91 ( V_521 ) ) {
if ( V_1628 )
F_20 () ;
return - V_537 ;
}
F_223 ( V_521 ) ;
} else if ( V_337 -> V_1629 & V_1634 ) {
if ( ! V_17 -> V_1582 ) {
if ( V_1628 )
F_20 () ;
return - V_537 ;
}
}
V_30 -> V_484 [ 0 ] = V_7 ;
}
return 0 ;
}
static void F_374 ( const struct V_1627 * V_337 , struct V_31 * V_32 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_484 [ 1 ] ) {
if ( V_337 -> V_1629 & V_1633 ) {
struct V_1 * V_17 = V_30 -> V_484 [ 1 ] ;
if ( V_17 -> V_19 )
F_168 ( V_17 -> V_19 ) ;
} else {
F_168 ( V_30 -> V_484 [ 1 ] ) ;
}
}
if ( V_337 -> V_1629 & V_1630 )
F_20 () ;
if ( V_337 -> V_1629 & V_1635 ) {
struct V_1636 * V_36 = F_375 ( V_32 ) ;
memset ( F_376 ( V_36 ) , 0 , F_377 ( V_36 ) ) ;
}
}
void F_378 ( struct V_6 * V_7 ,
enum V_272 V_52 )
{
struct V_31 * V_53 ;
struct V_273 V_274 = {} ;
F_59 ( V_52 != V_287 &&
V_52 != V_1637 ) ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_58 ( V_7 , V_52 , V_53 , 0 , 0 , 0 , & V_274 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1638 , V_135 ) ;
}
static int F_379 ( struct V_31 * V_53 ,
struct V_6 * V_7 )
{
struct V_1130 * V_1291 = V_7 -> V_1134 ;
struct V_4 * V_1639 ;
int V_153 ;
if ( F_59 ( ! V_1291 ) )
return 0 ;
V_1639 = F_47 ( V_53 , V_1138 ) ;
if ( ! V_1639 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_1291 -> V_1132 ; V_153 ++ ) {
if ( F_51 ( V_53 , V_153 , V_1291 -> V_1139 [ V_153 ] . V_571 , V_1291 -> V_1139 [ V_153 ] . V_573 ) )
goto V_61;
}
F_48 ( V_53 , V_1639 ) ;
V_1639 = F_47 ( V_53 , V_1137 ) ;
if ( ! V_1639 )
goto V_61;
for ( V_153 = 0 ; V_153 < V_1291 -> V_352 ; V_153 ++ ) {
if ( F_28 ( V_53 , V_153 , V_1291 -> V_353 [ V_153 ] -> V_60 ) )
goto V_61;
}
F_48 ( V_53 , V_1639 ) ;
if ( V_1291 -> V_1089 &&
F_51 ( V_53 , V_658 , V_1291 -> V_1090 , V_1291 -> V_1089 ) )
goto V_61;
if ( V_1291 -> V_51 &&
F_28 ( V_53 , V_1143 , V_1291 -> V_51 ) )
goto V_61;
return 0 ;
V_61:
return - V_91 ;
}
static int F_380 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_1 * V_17 ,
V_22 V_49 , V_22 V_50 , int V_51 ,
V_22 V_52 )
{
void * V_275 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_379 ( V_53 , V_7 ) ;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
static int
F_381 ( struct V_31 * V_53 ,
struct V_6 * V_7 ,
struct V_25 * V_19 ,
V_22 V_49 , V_22 V_50 , int V_51 , V_22 V_52 )
{
void * V_275 ;
V_275 = F_25 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
if ( ! V_275 )
return - 1 ;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
return F_66 ( V_53 , V_275 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
return - V_476 ;
}
void F_222 ( struct V_6 * V_7 ,
struct V_1 * V_17 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_380 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1640 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1641 , V_135 ) ;
}
struct V_31 * F_382 ( struct V_6 * V_7 ,
struct V_1 * V_17 , bool V_1642 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return NULL ;
if ( F_380 ( V_53 , V_7 , V_17 , 0 , 0 , 0 ,
V_1642 ? V_1643 :
V_1204 ) < 0 ) {
F_75 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
void F_383 ( struct V_6 * V_7 ,
struct V_31 * V_53 )
{
if ( ! V_53 )
return;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1641 , V_135 ) ;
}
void F_384 ( struct V_6 * V_7 ,
struct V_25 * V_19 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_381 ( V_53 , V_7 , V_19 , 0 , 0 , 0 ,
V_1644 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1641 , V_135 ) ;
}
void F_226 ( struct V_6 * V_7 ,
struct V_25 * V_19 , V_22 V_52 )
{
struct V_31 * V_53 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
if ( F_381 ( V_53 , V_7 , V_19 , 0 , 0 , 0 , V_52 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1641 , V_135 ) ;
}
void F_385 ( struct V_1645 * V_1131 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1646 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_56 ( V_53 , V_1647 , V_1131 -> V_1370 ) )
goto V_61;
if ( V_1131 -> V_1105 [ 0 ] == '0' && V_1131 -> V_1105 [ 1 ] == '0' ) {
if ( F_56 ( V_53 , V_1648 ,
V_1649 ) )
goto V_61;
} else if ( V_1131 -> V_1105 [ 0 ] == '9' && V_1131 -> V_1105 [ 1 ] == '9' ) {
if ( F_56 ( V_53 , V_1648 ,
V_1650 ) )
goto V_61;
} else if ( ( V_1131 -> V_1105 [ 0 ] == '9' && V_1131 -> V_1105 [ 1 ] == '8' ) ||
V_1131 -> V_1651 ) {
if ( F_56 ( V_53 , V_1648 ,
V_1652 ) )
goto V_61;
} else {
if ( F_56 ( V_53 , V_1648 ,
V_1653 ) ||
F_60 ( V_53 , V_1000 ,
V_1131 -> V_1105 ) )
goto V_61;
}
if ( V_1131 -> V_14 != V_1654 &&
F_28 ( V_53 , V_26 , V_1131 -> V_14 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_208 () ;
F_386 ( & V_38 , V_53 , 0 ,
V_1655 , V_1656 ) ;
F_211 () ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static void F_387 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
const T_2 * V_1427 , T_10 V_47 ,
enum V_272 V_52 , T_12 V_1329 ,
int V_891 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_1424 , V_47 , V_1427 ) )
goto V_61;
if ( V_891 >= 0 ) {
struct V_4 * V_1657 =
F_47 ( V_53 , V_888 ) ;
if ( ! V_1657 )
goto V_61;
if ( F_56 ( V_53 , V_890 ,
V_891 ) )
goto V_61;
F_48 ( V_53 , V_1657 ) ;
}
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_388 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1427 ,
T_10 V_47 , T_12 V_1329 )
{
F_387 ( V_7 , V_19 , V_1427 , V_47 ,
V_679 , V_1329 , - 1 ) ;
}
void F_389 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1427 ,
T_10 V_47 , T_12 V_1329 , int V_891 )
{
F_387 ( V_7 , V_19 , V_1427 , V_47 ,
V_1659 , V_1329 , V_891 ) ;
}
void F_390 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1427 ,
T_10 V_47 , T_12 V_1329 )
{
F_387 ( V_7 , V_19 , V_1427 , V_47 ,
V_1660 , V_1329 , - 1 ) ;
}
void F_391 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_1427 ,
T_10 V_47 , T_12 V_1329 )
{
F_387 ( V_7 , V_19 , V_1427 , V_47 ,
V_1661 , V_1329 , - 1 ) ;
}
void F_392 ( struct V_25 * V_521 , const T_2 * V_1427 ,
T_10 V_47 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
const struct V_1662 * V_1663 = ( void * ) V_1427 ;
V_22 V_52 ;
if ( F_59 ( V_47 < 2 ) )
return;
if ( F_393 ( V_1663 -> V_1664 ) )
V_52 = V_1665 ;
else
V_52 = V_1666 ;
F_394 ( V_521 , V_1427 , V_47 ) ;
F_387 ( V_7 , V_521 , V_1427 , V_47 , V_52 , V_1656 , - 1 ) ;
}
static void F_395 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_52 ,
const T_2 * V_652 , T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_29 ( V_53 , V_1667 ) ||
F_51 ( V_53 , V_529 , V_568 , V_652 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_396 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_652 ,
T_12 V_1329 )
{
F_395 ( V_7 , V_19 , V_679 ,
V_652 , V_1329 ) ;
}
void F_397 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_652 ,
T_12 V_1329 )
{
F_395 ( V_7 , V_19 , V_1659 ,
V_652 , V_1329 ) ;
}
void F_398 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_528 ,
const T_2 * V_1668 , T_10 V_1669 ,
const T_2 * V_1670 , T_10 V_1671 ,
T_3 V_1672 , T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_436 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_528 && F_51 ( V_53 , V_529 , V_568 , V_528 ) ) ||
F_55 ( V_53 , V_1372 , V_1672 ) ||
( V_1668 &&
F_51 ( V_53 , V_1673 , V_1669 , V_1668 ) ) ||
( V_1670 &&
F_51 ( V_53 , V_1674 , V_1671 , V_1670 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_399 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_528 ,
const T_2 * V_1668 , T_10 V_1669 ,
const T_2 * V_1670 , T_10 V_1671 , T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1675 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_528 ) ||
( V_1668 &&
F_51 ( V_53 , V_1673 , V_1669 , V_1668 ) ) ||
( V_1670 &&
F_51 ( V_53 , V_1674 , V_1671 , V_1670 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_400 ( struct V_6 * V_7 ,
struct V_25 * V_19 , T_3 V_1354 ,
const T_2 * V_1089 , T_10 V_1090 , bool V_1676 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_438 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_1676 && V_1354 &&
F_55 ( V_53 , V_1311 , V_1354 ) ) ||
( V_1676 &&
F_29 ( V_53 , V_1677 ) ) ||
( V_1089 && F_51 ( V_53 , V_658 , V_1090 , V_1089 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_135 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_401 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_528 ,
T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1678 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_528 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_402 ( struct V_25 * V_521 , const T_2 * V_652 ,
const T_2 * V_1089 , T_2 V_1090 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
if ( F_59 ( V_17 -> V_141 != V_145 ) )
return;
F_403 ( V_521 , V_652 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1679 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_652 ) ||
( V_1090 && V_1089 &&
F_51 ( V_53 , V_658 , V_1090 , V_1089 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_404 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_652 ,
enum V_1680 V_1681 , int V_1682 ,
const T_2 * V_1683 , T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1684 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
( V_652 && F_51 ( V_53 , V_529 , V_568 , V_652 ) ) ||
F_28 ( V_53 , V_127 , V_1681 ) ||
( V_1682 != - 1 &&
F_56 ( V_53 , V_123 , V_1682 ) ) ||
( V_1683 && F_51 ( V_53 , V_122 , 6 , V_1683 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_405 ( struct V_18 * V_18 ,
struct V_54 * V_1685 ,
struct V_54 * V_1686 )
{
struct V_31 * V_53 ;
void * V_275 ;
struct V_4 * V_279 ;
V_53 = F_74 ( V_579 , V_1656 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1687 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , F_406 ( V_18 ) ) )
goto V_61;
V_279 = F_47 ( V_53 , V_1688 ) ;
if ( ! V_279 )
goto V_61;
if ( F_27 ( V_53 , V_1685 , false ) )
goto V_61;
F_48 ( V_53 , V_279 ) ;
V_279 = F_47 ( V_53 , V_1689 ) ;
if ( ! V_279 )
goto V_61;
if ( F_27 ( V_53 , V_1686 , false ) )
goto V_61;
F_48 ( V_53 , V_279 ) ;
F_66 ( V_53 , V_275 ) ;
F_208 () ;
F_386 ( & V_38 , V_53 , 0 ,
V_1655 , V_1656 ) ;
F_211 () ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static void F_407 (
int V_52 , struct V_6 * V_7 ,
struct V_1 * V_17 , T_1 V_622 ,
struct V_54 * V_55 ,
unsigned int V_1379 , T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_504 , V_55 -> V_60 ) ||
F_28 ( V_53 , V_509 ,
V_512 ) ||
F_104 ( V_53 , V_1383 , V_622 ) )
goto V_61;
if ( V_52 == V_1382 &&
F_28 ( V_53 , V_1380 , V_1379 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_408 ( struct V_1 * V_17 , T_1 V_622 ,
struct V_54 * V_55 ,
unsigned int V_1379 , T_12 V_1329 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_409 ( V_17 , V_622 , V_55 , V_1379 ) ;
F_407 ( V_1382 ,
V_7 , V_17 , V_622 , V_55 ,
V_1379 , V_1329 ) ;
}
void F_410 ( struct V_1 * V_17 , T_1 V_622 ,
struct V_54 * V_55 ,
T_12 V_1329 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_411 ( V_17 , V_622 , V_55 ) ;
F_407 ( V_1690 ,
V_7 , V_17 , V_622 , V_55 , 0 , V_1329 ) ;
}
void F_412 ( struct V_25 * V_521 , const T_2 * V_624 ,
struct V_757 * V_758 , T_12 V_1329 )
{
struct V_18 * V_18 = V_521 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
F_413 ( V_521 , V_624 , V_758 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
if ( F_160 ( V_53 , 0 , 0 , 0 ,
V_7 , V_521 , V_624 , V_758 ) < 0 ) {
F_75 ( V_53 ) ;
return;
}
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
}
void F_414 ( struct V_25 * V_521 , const T_2 * V_624 , T_12 V_1329 )
{
struct V_18 * V_18 = V_521 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_415 ( V_521 , V_624 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1691 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_624 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_416 ( struct V_25 * V_521 , const T_2 * V_624 ,
enum V_1692 V_1354 ,
T_12 V_1329 )
{
struct V_18 * V_18 = V_521 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_1693 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1694 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_624 ) ||
F_28 ( V_53 , V_1695 , V_1354 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static bool F_417 ( struct V_25 * V_521 , T_2 V_52 ,
const T_2 * V_652 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
V_22 V_1580 = F_418 ( V_17 -> V_1573 ) ;
if ( ! V_1580 )
return false ;
V_53 = F_74 ( 100 , V_1329 ) ;
if ( ! V_53 )
return true ;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_52 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return true ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_652 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_419 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1580 ) ;
return true ;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
return true ;
}
bool F_420 ( struct V_25 * V_521 ,
const T_2 * V_652 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
bool V_477 ;
F_421 ( V_521 , V_652 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 ) ) {
F_422 ( false ) ;
return false ;
}
V_477 = F_417 ( V_521 , V_1696 ,
V_652 , V_1329 ) ;
F_422 ( V_477 ) ;
return V_477 ;
}
bool F_423 ( struct V_25 * V_521 ,
const T_2 * V_652 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
bool V_477 ;
F_424 ( V_521 , V_652 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_143 ) ) {
F_422 ( false ) ;
return false ;
}
V_477 = F_417 ( V_521 ,
V_1697 ,
V_652 , V_1329 ) ;
F_422 ( V_477 ) ;
return V_477 ;
}
int F_425 ( struct V_6 * V_7 ,
struct V_1 * V_17 , V_22 V_1580 ,
int V_1698 , int V_1699 ,
const T_2 * V_1427 , T_10 V_47 , V_22 V_51 , T_12 V_1329 )
{
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return - V_136 ;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1431 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return - V_136 ;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_28 ( V_53 , V_504 , V_1698 ) ||
( V_1699 &&
F_28 ( V_53 , V_1700 , V_1699 ) ) ||
F_51 ( V_53 , V_1424 , V_47 , V_1427 ) ||
( V_51 &&
F_28 ( V_53 , V_1701 , V_51 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
return F_419 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1580 ) ;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
return - V_91 ;
}
void F_426 ( struct V_1 * V_17 , T_1 V_622 ,
const T_2 * V_1427 , T_10 V_47 , bool V_1702 , T_12 V_1329 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_25 * V_19 = V_17 -> V_19 ;
struct V_31 * V_53 ;
void * V_275 ;
F_427 ( V_17 , V_622 , V_1702 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1703 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_19 && F_28 ( V_53 , V_10 ,
V_19 -> V_20 ) ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) ||
F_51 ( V_53 , V_1424 , V_47 , V_1427 ) ||
F_104 ( V_53 , V_1383 , V_622 ) ||
( V_1702 && F_29 ( V_53 , V_1704 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_428 ( struct V_25 * V_521 ,
enum V_1705 V_1706 ,
T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_933 ;
void * V_275 ;
F_429 ( V_521 , V_1706 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1707 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_521 -> V_20 ) )
goto V_61;
V_933 = F_47 ( V_53 , V_1450 ) ;
if ( ! V_933 )
goto V_61;
if ( F_28 ( V_53 , V_1708 ,
V_1706 ) )
goto V_61;
F_48 ( V_53 , V_933 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static void F_430 ( struct V_6 * V_7 ,
struct V_25 * V_19 , const T_2 * V_528 ,
const T_2 * V_1571 , T_12 V_1329 )
{
struct V_31 * V_53 ;
struct V_4 * V_1709 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1710 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_528 ) )
goto V_61;
V_1709 = F_47 ( V_53 , V_1559 ) ;
if ( ! V_1709 )
goto V_61;
if ( F_51 ( V_53 , V_1562 ,
V_1563 , V_1571 ) )
goto V_61;
F_48 ( V_53 , V_1709 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_431 ( struct V_25 * V_521 , const T_2 * V_528 ,
const T_2 * V_1571 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_432 ( V_521 , V_528 ) ;
F_430 ( V_7 , V_521 , V_528 , V_1571 , V_1329 ) ;
}
static void
F_433 ( struct V_6 * V_7 ,
struct V_25 * V_19 , int V_1711 ,
const T_2 * V_528 , bool V_1712 , T_12 V_1329 )
{
struct V_31 * V_53 ;
struct V_4 * V_45 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1713 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
V_45 = F_47 ( V_53 , V_1714 ) ;
if ( ! V_45 )
goto V_61;
if ( F_28 ( V_53 , V_1715 , V_1711 ) ||
F_51 ( V_53 , V_1716 , V_568 , V_528 ) ||
( V_1712 &&
F_29 ( V_53 , V_1717 ) ) )
goto V_61;
F_48 ( V_53 , V_45 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_434 ( struct V_25 * V_521 , int V_1711 ,
const T_2 * V_528 , bool V_1712 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_435 ( V_521 , V_1711 , V_528 , V_1712 ) ;
F_433 ( V_7 , V_521 , V_1711 , V_528 , V_1712 , V_1329 ) ;
}
static void F_436 ( struct V_6 * V_7 ,
struct V_25 * V_19 ,
struct V_501 * V_502 ,
T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1718 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) )
goto V_61;
if ( F_101 ( V_53 , V_502 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_437 ( struct V_25 * V_521 ,
struct V_501 * V_502 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
F_43 ( V_17 ) ;
F_438 ( V_521 , V_502 ) ;
if ( F_59 ( V_17 -> V_141 != V_142 &&
V_17 -> V_141 != V_144 &&
V_17 -> V_141 != V_146 &&
V_17 -> V_141 != V_145 ) )
return;
V_17 -> V_502 = * V_502 ;
V_17 -> V_527 = * V_502 ;
F_436 ( V_7 , V_521 , V_502 , V_135 ) ;
}
void F_439 ( struct V_25 * V_521 ,
const T_2 * V_1369 , V_22 V_1719 ,
V_22 V_235 , V_22 V_1442 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_933 ;
void * V_275 ;
V_53 = F_74 ( V_1693 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1707 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_1369 ) )
goto V_61;
V_933 = F_47 ( V_53 , V_1450 ) ;
if ( ! V_933 )
goto V_61;
if ( F_28 ( V_53 , V_1455 , V_1719 ) )
goto V_61;
if ( F_28 ( V_53 , V_1454 , V_235 ) )
goto V_61;
if ( F_28 ( V_53 , V_1456 , V_1442 ) )
goto V_61;
F_48 ( V_53 , V_933 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void
F_440 ( struct V_6 * V_7 ,
const struct V_501 * V_502 ,
enum V_1720 V_1721 ,
struct V_25 * V_19 , T_12 V_1329 )
{
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1722 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) )
goto V_61;
if ( V_19 ) {
struct V_1 * V_17 = V_19 -> V_28 ;
if ( F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
}
if ( F_28 ( V_53 , V_1723 , V_1721 ) )
goto V_61;
if ( F_101 ( V_53 , V_502 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_441 ( struct V_25 * V_521 ,
const T_2 * V_1369 , V_22 V_1719 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
struct V_4 * V_933 ;
void * V_275 ;
F_442 ( V_521 , V_1369 , V_1719 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1707 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_1369 ) )
goto V_61;
V_933 = F_47 ( V_53 , V_1450 ) ;
if ( ! V_933 )
goto V_61;
if ( F_28 ( V_53 , V_1724 , V_1719 ) )
goto V_61;
F_48 ( V_53 , V_933 ) ;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_443 ( struct V_25 * V_521 , const T_2 * V_652 ,
T_1 V_622 , bool V_1725 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_444 ( V_521 , V_652 , V_622 , V_1725 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1574 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_652 ) ||
F_104 ( V_53 , V_1383 , V_622 ) ||
( V_1725 && F_29 ( V_53 , V_1704 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_445 ( struct V_18 * V_18 ,
const T_2 * V_1726 , T_10 V_47 ,
int V_1698 , int V_1699 )
{
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
struct V_1575 * V_1576 ;
F_446 ( V_18 , V_1726 , V_47 , V_1698 , V_1699 ) ;
F_242 ( & V_7 -> V_1579 ) ;
F_6 (reg, &rdev->beacon_registrations, list) {
V_53 = F_74 ( V_47 + 100 , V_1656 ) ;
if ( ! V_53 ) {
F_244 ( & V_7 -> V_1579 ) ;
return;
}
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1431 ) ;
if ( ! V_275 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
( V_1698 &&
F_28 ( V_53 , V_504 , V_1698 ) ) ||
( V_1699 &&
F_28 ( V_53 , V_1700 , V_1699 ) ) ||
F_51 ( V_53 , V_1424 , V_47 , V_1726 ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_419 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1576 -> V_1580 ) ;
}
F_244 ( & V_7 -> V_1579 ) ;
return;
V_61:
F_244 ( & V_7 -> V_1579 ) ;
if ( V_275 )
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_447 ( struct V_1 * V_17 ,
struct V_1727 * V_1728 ,
T_12 V_1329 )
{
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
int V_1491 = 200 ;
F_448 ( V_17 -> V_18 , V_17 , V_1728 ) ;
if ( V_1728 )
V_1491 += V_1728 -> V_1729 ;
V_53 = F_74 ( V_1491 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1730 ) ;
if ( ! V_275 )
goto V_632;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_632;
if ( V_17 -> V_19 && F_28 ( V_53 , V_10 ,
V_17 -> V_19 -> V_20 ) )
goto V_632;
if ( V_1728 ) {
struct V_4 * V_1731 ;
V_1731 = F_47 ( V_53 , V_1493 ) ;
if ( ! V_1731 )
goto V_632;
if ( V_1728 -> V_437 &&
F_29 ( V_53 , V_200 ) )
goto V_632;
if ( V_1728 -> V_1495 &&
F_29 ( V_53 , V_202 ) )
goto V_632;
if ( V_1728 -> V_1496 &&
F_29 ( V_53 , V_206 ) )
goto V_632;
if ( V_1728 -> V_1497 &&
F_29 ( V_53 , V_208 ) )
goto V_632;
if ( V_1728 -> V_1498 &&
F_29 ( V_53 , V_210 ) )
goto V_632;
if ( V_1728 -> V_1499 &&
F_29 ( V_53 , V_212 ) )
goto V_632;
if ( V_1728 -> V_1732 >= 0 &&
F_28 ( V_53 , V_222 ,
V_1728 -> V_1732 ) )
goto V_632;
if ( V_1728 -> V_1733 &&
F_29 ( V_53 , V_1734 ) )
goto V_632;
if ( V_1728 -> V_1735 &&
F_29 ( V_53 , V_1736 ) )
goto V_632;
if ( V_1728 -> V_1737 &&
F_29 ( V_53 ,
V_1738 ) )
goto V_632;
if ( V_1728 -> V_1739 ) {
V_22 V_1740 = V_1741 ;
V_22 V_1742 = V_1743 ;
if ( ! V_1728 -> V_1744 ) {
V_1740 =
V_1745 ;
V_1742 =
V_1746 ;
}
if ( V_1728 -> V_1747 &&
F_28 ( V_53 , V_1742 , V_1728 -> V_1747 ) )
goto V_632;
if ( F_51 ( V_53 , V_1740 , V_1728 -> V_1729 ,
V_1728 -> V_1739 ) )
goto V_632;
}
F_48 ( V_53 , V_1731 ) ;
}
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_632:
F_75 ( V_53 ) ;
}
void F_449 ( struct V_25 * V_521 , const T_2 * V_1369 ,
enum V_1376 V_1748 ,
T_3 V_1310 , T_12 V_1329 )
{
struct V_1 * V_17 = V_521 -> V_28 ;
struct V_6 * V_7 = F_11 ( V_17 -> V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_450 ( V_17 -> V_18 , V_521 , V_1369 , V_1748 ,
V_1310 ) ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1749 ) ;
if ( ! V_275 ) {
F_75 ( V_53 ) ;
return;
}
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_521 -> V_20 ) ||
F_56 ( V_53 , V_1378 , V_1748 ) ||
F_51 ( V_53 , V_529 , V_568 , V_1369 ) ||
( V_1310 > 0 &&
F_55 ( V_53 , V_1311 , V_1310 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_1329 ) ;
return;
V_61:
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
static int F_451 ( struct V_1750 * V_1751 ,
unsigned long V_274 ,
void * V_1752 )
{
struct V_1753 * V_1754 = V_1752 ;
struct V_6 * V_7 ;
struct V_1 * V_17 ;
struct V_1575 * V_1576 , * V_24 ;
if ( V_274 != V_1755 )
return V_1756 ;
F_208 () ;
F_452 (rdev, &cfg80211_rdev_list, list) {
bool V_1757 = false ;
F_452 (wdev, &rdev->wdev_list, list) {
F_453 ( V_17 , V_1754 -> V_49 ) ;
if ( V_17 -> V_609 == V_1754 -> V_49 )
V_1757 = true ;
}
F_242 ( & V_7 -> V_1579 ) ;
F_454 (reg, tmp, &rdev->beacon_registrations,
list) {
if ( V_1576 -> V_1580 == V_1754 -> V_49 ) {
F_455 ( & V_1576 -> V_615 ) ;
F_41 ( V_1576 ) ;
break;
}
}
F_244 ( & V_7 -> V_1579 ) ;
if ( V_1757 ) {
struct V_1758 * V_1759 ;
V_1759 = F_38 ( sizeof( * V_1759 ) , V_1656 ) ;
if ( V_1759 ) {
V_1759 -> V_1580 = V_1754 -> V_49 ;
F_456 ( & V_7 -> V_1760 ) ;
F_350 ( & V_1759 -> V_615 , & V_7 -> V_1761 ) ;
F_457 ( & V_7 -> V_1760 ) ;
F_458 ( & V_7 -> V_1762 ) ;
}
}
}
F_211 () ;
return V_1763 ;
}
void F_459 ( struct V_25 * V_19 ,
struct V_1764 * V_1765 )
{
struct V_18 * V_18 = V_19 -> V_28 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
F_460 ( V_18 , V_19 , V_1765 ) ;
if ( ! V_1765 -> V_1766 )
return;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1767 ) ;
if ( ! V_275 )
goto V_578;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_19 -> V_20 ) ||
F_51 ( V_53 , V_529 , V_568 , V_1765 -> V_1766 ) )
goto V_578;
if ( V_1765 -> V_1202 &&
F_51 ( V_53 , V_658 , V_1765 -> V_1768 , V_1765 -> V_1202 ) )
goto V_578;
if ( V_1765 -> V_1769 &&
F_51 ( V_53 , V_1770 , V_1765 -> V_1771 ,
V_1765 -> V_1769 ) )
goto V_578;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( & V_7 -> V_18 ) , V_53 , 0 ,
V_1658 , V_135 ) ;
return;
V_578:
F_75 ( V_53 ) ;
}
void F_461 ( struct V_1 * V_17 , T_12 V_1329 )
{
struct V_6 * V_7 ;
struct V_31 * V_53 ;
void * V_275 ;
V_22 V_1580 ;
V_7 = F_11 ( V_17 -> V_18 ) ;
if ( ! V_7 -> V_1597 )
return;
V_1580 = V_7 -> V_1597 ;
V_7 -> V_1597 = 0 ;
V_53 = F_74 ( V_579 , V_1329 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1772 ) ;
if ( ! V_275 )
goto V_61;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_61;
F_66 ( V_53 , V_275 ) ;
F_419 ( F_7 ( & V_7 -> V_18 ) , V_53 , V_1580 ) ;
return;
V_61:
if ( V_275 )
F_67 ( V_53 , V_275 ) ;
F_75 ( V_53 ) ;
}
void F_462 ( struct V_1 * V_17 )
{
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_6 * V_7 = F_11 ( V_18 ) ;
struct V_31 * V_53 ;
void * V_275 ;
V_53 = F_74 ( V_579 , V_135 ) ;
if ( ! V_53 )
return;
V_275 = F_25 ( V_53 , 0 , 0 , 0 , V_1773 ) ;
if ( ! V_275 )
goto V_578;
if ( F_28 ( V_53 , V_26 , V_7 -> V_14 ) ||
F_28 ( V_53 , V_10 , V_17 -> V_19 -> V_20 ) ||
F_104 ( V_53 , V_12 , V_13 ( V_17 ) ) )
goto V_578;
F_66 ( V_53 , V_275 ) ;
F_270 ( & V_38 , F_7 ( V_18 ) , V_53 , 0 ,
V_1658 , V_135 ) ;
return;
V_578:
F_75 ( V_53 ) ;
}
int F_463 ( void )
{
int V_35 ;
V_35 = F_464 ( & V_38 , V_1774 ,
V_1775 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_465 ( & V_1776 ) ;
if ( V_35 )
goto V_1777;
return 0 ;
V_1777:
F_466 ( & V_38 ) ;
return V_35 ;
}
void F_467 ( void )
{
F_468 ( & V_1776 ) ;
F_466 ( & V_38 ) ;
}
