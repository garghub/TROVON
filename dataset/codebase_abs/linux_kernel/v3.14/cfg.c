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
return F_16 ( V_10 , true ) ;
}
static void F_17 ( struct V_2 * V_2 ,
struct V_1 * V_10 )
{
F_18 ( F_5 ( V_10 ) ) ;
}
static int F_19 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_2 V_31 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_31 = V_31 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 ,
struct V_35 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 = NULL ;
const struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_41 ;
switch ( V_7 -> V_42 ) {
case V_43 :
case V_44 :
case V_45 :
if ( F_21 ( V_9 -> V_46 ) )
return - V_47 ;
break;
case V_48 :
case V_49 :
case V_50 :
break;
default:
V_38 = F_22 ( V_9 , V_7 -> V_42 , V_12 -> V_26 . type ) ;
break;
}
V_40 = F_23 ( V_7 -> V_42 , V_32 , V_7 -> V_51 ,
V_7 -> V_40 , V_7 -> V_52 , V_7 -> V_53 ,
V_38 ) ;
if ( F_21 ( V_40 ) )
return F_24 ( V_40 ) ;
if ( V_33 )
V_40 -> V_54 . V_5 |= V_55 ;
F_25 ( & V_9 -> V_56 ) ;
if ( V_34 ) {
if ( F_26 ( & V_12 -> V_26 ) )
V_23 = F_27 ( V_12 , V_34 ) ;
else
V_23 = F_28 ( V_12 , V_34 ) ;
if ( ! V_23 || ! F_29 ( V_23 , V_57 ) ) {
F_30 ( V_40 ) ;
V_13 = - V_58 ;
goto V_59;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_60 != V_61 )
V_40 -> V_54 . V_5 |= V_62 ;
break;
case V_63 :
case V_20 :
if ( V_40 -> V_23 && F_29 ( V_40 -> V_23 , V_64 ) )
V_40 -> V_54 . V_5 |= V_62 ;
break;
case V_65 :
break;
case V_66 :
#ifdef F_31
if ( V_12 -> V_15 . V_67 . V_68 != V_69 )
V_40 -> V_54 . V_5 |= V_62 ;
break;
#endif
case V_70 :
case V_14 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
F_32 ( 1 ) ;
break;
}
if ( V_23 )
V_23 -> V_76 = V_38 ;
V_13 = F_33 ( V_40 , V_12 , V_23 ) ;
V_59:
F_34 ( & V_9 -> V_56 ) ;
return V_13 ;
}
static int F_35 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
struct V_39 * V_40 = NULL ;
int V_19 ;
F_25 ( & V_9 -> V_56 ) ;
F_25 ( & V_9 -> V_77 ) ;
if ( V_34 ) {
V_19 = - V_58 ;
V_23 = F_28 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_59;
if ( V_33 )
V_40 = F_36 ( V_9 , V_23 -> V_78 [ V_32 ] ) ;
else
V_40 = F_36 ( V_9 , V_23 -> V_79 [ V_32 ] ) ;
} else
V_40 = F_36 ( V_9 , V_12 -> V_80 [ V_32 ] ) ;
if ( ! V_40 ) {
V_19 = - V_58 ;
goto V_59;
}
F_37 ( V_40 , true ) ;
V_19 = 0 ;
V_59:
F_34 ( & V_9 -> V_77 ) ;
F_34 ( & V_9 -> V_56 ) ;
return V_19 ;
}
static int F_38 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 ,
void * V_81 ,
void (* F_39)( void * V_81 ,
struct V_35 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_36 * V_23 = NULL ;
T_3 V_53 [ 6 ] = { 0 } ;
struct V_35 V_7 ;
struct V_39 * V_40 = NULL ;
T_4 V_82 ;
T_1 V_83 ;
T_2 V_84 ;
int V_13 = - V_58 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
if ( V_34 ) {
V_23 = F_28 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_85;
if ( V_33 && V_32 < V_86 )
V_40 = F_41 ( V_23 -> V_78 [ V_32 ] ) ;
else if ( ! V_33 &&
V_32 < V_86 + V_87 )
V_40 = F_41 ( V_23 -> V_79 [ V_32 ] ) ;
} else
V_40 = F_41 ( V_12 -> V_80 [ V_32 ] ) ;
if ( ! V_40 )
goto V_85;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_42 = V_40 -> V_54 . V_42 ;
switch ( V_40 -> V_54 . V_42 ) {
case V_44 :
V_83 = V_40 -> V_15 . V_88 . V_89 . V_83 ;
V_84 = V_40 -> V_15 . V_88 . V_89 . V_84 ;
if ( V_40 -> V_5 & V_90 )
F_42 ( V_12 -> V_9 ,
V_40 -> V_54 . V_91 ,
& V_83 , & V_84 ) ;
V_53 [ 0 ] = V_84 & 0xff ;
V_53 [ 1 ] = ( V_84 >> 8 ) & 0xff ;
V_53 [ 2 ] = V_83 & 0xff ;
V_53 [ 3 ] = ( V_83 >> 8 ) & 0xff ;
V_53 [ 4 ] = ( V_83 >> 16 ) & 0xff ;
V_53 [ 5 ] = ( V_83 >> 24 ) & 0xff ;
V_7 . V_53 = V_53 ;
V_7 . V_52 = 6 ;
break;
case V_48 :
V_82 = F_43 ( & V_40 -> V_15 . V_92 . V_93 ) ;
V_53 [ 0 ] = V_82 ;
V_53 [ 1 ] = V_82 >> 8 ;
V_53 [ 2 ] = V_82 >> 16 ;
V_53 [ 3 ] = V_82 >> 24 ;
V_53 [ 4 ] = V_82 >> 32 ;
V_53 [ 5 ] = V_82 >> 40 ;
V_7 . V_53 = V_53 ;
V_7 . V_52 = 6 ;
break;
case V_49 :
V_82 = F_43 ( & V_40 -> V_15 . V_94 . V_93 ) ;
V_53 [ 0 ] = V_82 ;
V_53 [ 1 ] = V_82 >> 8 ;
V_53 [ 2 ] = V_82 >> 16 ;
V_53 [ 3 ] = V_82 >> 24 ;
V_53 [ 4 ] = V_82 >> 32 ;
V_53 [ 5 ] = V_82 >> 40 ;
V_7 . V_53 = V_53 ;
V_7 . V_52 = 6 ;
break;
}
V_7 . V_40 = V_40 -> V_54 . V_40 ;
V_7 . V_51 = V_40 -> V_54 . V_95 ;
F_39 ( V_81 , & V_7 ) ;
V_13 = 0 ;
V_85:
F_44 () ;
return V_13 ;
}
static int F_45 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 , bool V_96 ,
bool V_97 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_46 ( V_12 , V_32 , V_96 , V_97 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_48 ( V_12 , V_32 ) ;
return 0 ;
}
void F_49 ( struct V_36 * V_23 ,
const struct V_98 * V_99 ,
struct V_100 * V_101 )
{
V_101 -> V_5 = 0 ;
if ( V_99 -> V_5 & V_102 ) {
V_101 -> V_5 |= V_103 ;
V_101 -> V_104 = V_99 -> V_105 ;
} else if ( V_99 -> V_5 & V_106 ) {
V_101 -> V_5 |= V_107 ;
V_101 -> V_104 = F_50 ( V_99 ) ;
V_101 -> V_108 = F_51 ( V_99 ) ;
} else {
struct V_109 * V_110 ;
int V_111 = F_52 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_112 ;
V_110 = V_23 -> V_9 -> V_113 . V_2 -> V_114 [
F_53 ( V_23 -> V_12 ) ] ;
V_112 = V_110 -> V_115 [ V_99 -> V_105 ] . V_116 ;
V_101 -> V_117 = F_54 ( V_112 , 1 << V_111 ) ;
}
if ( V_99 -> V_5 & V_118 )
V_101 -> V_5 |= V_119 ;
if ( V_99 -> V_5 & V_120 )
V_101 -> V_5 |= V_121 ;
if ( V_99 -> V_5 & V_122 )
V_101 -> V_5 |= V_123 ;
if ( V_99 -> V_5 & V_124 )
V_101 -> V_5 |= V_125 ;
}
void F_55 ( struct V_36 * V_23 , struct V_100 * V_101 )
{
V_101 -> V_5 = 0 ;
if ( V_23 -> V_126 & V_127 ) {
V_101 -> V_5 |= V_103 ;
V_101 -> V_104 = V_23 -> V_128 ;
} else if ( V_23 -> V_126 & V_129 ) {
V_101 -> V_5 |= V_107 ;
V_101 -> V_108 = V_23 -> V_130 ;
V_101 -> V_104 = V_23 -> V_128 ;
} else {
struct V_109 * V_110 ;
int V_111 = F_52 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_112 ;
V_110 = V_23 -> V_9 -> V_113 . V_2 -> V_114 [
F_53 ( V_23 -> V_12 ) ] ;
V_112 = V_110 -> V_115 [ V_23 -> V_128 ] . V_116 ;
V_101 -> V_117 = F_54 ( V_112 , 1 << V_111 ) ;
}
if ( V_23 -> V_126 & V_131 )
V_101 -> V_5 |= V_119 ;
if ( V_23 -> V_126 & V_132 )
V_101 -> V_5 |= V_125 ;
if ( V_23 -> V_126 & V_133 )
V_101 -> V_5 |= V_121 ;
if ( V_23 -> V_126 & V_134 )
V_101 -> V_5 |= V_135 ;
if ( V_23 -> V_126 & V_136 )
V_101 -> V_5 |= V_123 ;
}
static void F_56 ( struct V_36 * V_23 , struct V_137 * V_138 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_139 V_140 ;
T_4 V_141 = 0 ;
int V_142 , V_143 ;
V_138 -> V_144 = V_12 -> V_9 -> V_145 ;
V_138 -> V_146 = V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 |
V_159 |
V_160 ;
F_57 ( & V_140 ) ;
V_138 -> V_161 = V_140 . V_162 - V_23 -> V_163 ;
V_138 -> V_164 = F_58 ( V_165 - V_23 -> V_166 ) ;
V_138 -> V_167 = 0 ;
for ( V_143 = 0 ; V_143 < V_168 ; V_143 ++ ) {
V_138 -> V_167 += V_23 -> V_167 [ V_143 ] ;
V_141 += V_23 -> V_169 [ V_143 ] ;
}
V_138 -> V_169 = V_141 ;
V_138 -> V_170 = V_23 -> V_170 ;
V_138 -> V_171 = V_23 -> V_171 ;
V_138 -> V_172 = V_23 -> V_173 ;
V_138 -> V_174 = V_23 -> V_175 ;
V_138 -> V_176 = V_23 -> V_177 ;
V_138 -> V_178 = V_23 -> V_178 ;
if ( ( V_23 -> V_9 -> V_113 . V_5 & V_179 ) ||
( V_23 -> V_9 -> V_113 . V_5 & V_180 ) ) {
V_138 -> V_146 |= V_181 | V_182 ;
if ( ! V_9 -> V_183 -> V_184 ||
F_59 ( V_9 , V_12 , & V_23 -> V_23 , & V_138 -> signal ) )
V_138 -> signal = ( V_185 ) V_23 -> V_186 ;
V_138 -> V_187 = ( V_185 ) - F_60 ( & V_23 -> V_188 ) ;
}
if ( V_23 -> V_189 ) {
V_138 -> V_146 |= V_190 |
V_191 ;
V_138 -> V_189 = V_23 -> V_189 ;
for ( V_142 = 0 ; V_142 < F_61 ( V_138 -> V_192 ) ; V_142 ++ ) {
V_138 -> V_192 [ V_142 ] = V_23 -> V_193 [ V_142 ] ;
V_138 -> V_194 [ V_142 ] =
( V_185 ) - F_60 ( & V_23 -> V_194 [ V_142 ] ) ;
}
}
F_49 ( V_23 , & V_23 -> V_195 , & V_138 -> V_196 ) ;
F_55 ( V_23 , & V_138 -> V_197 ) ;
if ( F_26 ( & V_12 -> V_26 ) ) {
#ifdef F_31
V_138 -> V_146 |= V_198 |
V_199 |
V_200 |
V_201 |
V_202 |
V_203 ;
V_138 -> V_204 = V_23 -> V_204 ;
V_138 -> V_205 = V_23 -> V_205 ;
V_138 -> V_206 = V_23 -> V_206 ;
if ( F_29 ( V_23 , V_207 ) ) {
V_138 -> V_146 |= V_208 ;
V_138 -> V_209 = V_23 -> V_209 ;
}
V_138 -> V_210 = V_23 -> V_210 ;
V_138 -> V_211 = V_23 -> V_211 ;
V_138 -> V_212 = V_23 -> V_212 ;
#endif
}
V_138 -> V_213 . V_5 = 0 ;
if ( V_12 -> V_26 . V_214 . V_215 )
V_138 -> V_213 . V_5 |= V_216 ;
if ( V_12 -> V_26 . V_214 . V_217 )
V_138 -> V_213 . V_5 |= V_218 ;
if ( V_12 -> V_26 . V_214 . V_219 )
V_138 -> V_213 . V_5 |= V_220 ;
V_138 -> V_213 . V_221 = V_12 -> V_9 -> V_113 . V_54 . V_222 ;
V_138 -> V_213 . V_223 = V_12 -> V_26 . V_214 . V_224 ;
V_138 -> V_225 . V_226 = 0 ;
V_138 -> V_225 . V_27 = F_62 ( V_227 ) |
F_62 ( V_228 ) |
F_62 ( V_229 ) |
F_62 ( V_230 ) |
F_62 ( V_231 ) |
F_62 ( V_232 ) |
F_62 ( V_233 ) ;
if ( F_29 ( V_23 , V_234 ) )
V_138 -> V_225 . V_226 |= F_62 ( V_227 ) ;
if ( F_29 ( V_23 , V_235 ) )
V_138 -> V_225 . V_226 |= F_62 ( V_228 ) ;
if ( F_29 ( V_23 , V_236 ) )
V_138 -> V_225 . V_226 |= F_62 ( V_229 ) ;
if ( F_29 ( V_23 , V_64 ) )
V_138 -> V_225 . V_226 |= F_62 ( V_230 ) ;
if ( F_29 ( V_23 , V_237 ) )
V_138 -> V_225 . V_226 |= F_62 ( V_231 ) ;
if ( F_29 ( V_23 , V_57 ) )
V_138 -> V_225 . V_226 |= F_62 ( V_232 ) ;
if ( F_29 ( V_23 , V_238 ) )
V_138 -> V_225 . V_226 |= F_62 ( V_233 ) ;
}
static int F_63 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_239 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_240 = 0 ;
if ( V_239 == V_241 )
V_240 += V_242 ;
V_240 += F_64 ( V_12 , V_239 ) ;
if ( V_240 == 0 )
return - V_243 ;
return V_240 ;
}
static void F_65 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_244 * V_245 ,
T_4 * V_246 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_247 * V_248 ;
struct V_249 * V_250 ;
struct V_36 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_137 V_138 ;
struct V_251 V_252 ;
int V_142 , V_253 ;
#define F_66 7
memset ( V_246 , 0 , sizeof( T_4 ) * V_242 ) ;
#define F_67 ( V_23 ) \
do { \
data[i++] += sta->rx_packets; \
data[i++] += sta->rx_bytes; \
data[i++] += sta->wep_weak_iv_count; \
data[i++] += sta->num_duplicates; \
data[i++] += sta->rx_fragments; \
data[i++] += sta->rx_dropped; \
\
data[i++] += sinfo.tx_packets; \
data[i++] += sinfo.tx_bytes; \
data[i++] += sta->tx_fragments; \
data[i++] += sta->tx_filtered_count; \
data[i++] += sta->tx_retry_failed; \
data[i++] += sta->tx_retry_count; \
data[i++] += sta->beacon_loss_count; \
} while (0)
F_25 ( & V_9 -> V_56 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_28 ( V_12 , V_12 -> V_15 . V_25 . V_254 ) ;
if ( ! ( V_23 && ! F_68 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_255;
V_138 . V_146 = 0 ;
F_56 ( V_23 , & V_138 ) ;
V_142 = 0 ;
F_67 ( V_23 ) ;
V_246 [ V_142 ++ ] = V_23 -> V_256 ;
if ( V_138 . V_146 & V_154 )
V_246 [ V_142 ] = 100000 *
F_69 ( & V_138 . V_196 ) ;
V_142 ++ ;
if ( V_138 . V_146 & V_155 )
V_246 [ V_142 ] = 100000 *
F_69 ( & V_138 . V_197 ) ;
V_142 ++ ;
if ( V_138 . V_146 & V_182 )
V_246 [ V_142 ] = ( T_3 ) V_138 . V_187 ;
V_142 ++ ;
} else {
F_70 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_138 . V_146 = 0 ;
F_56 ( V_23 , & V_138 ) ;
V_142 = 0 ;
F_67 ( V_23 ) ;
}
}
V_255:
V_142 = V_242 - F_66 ;
V_252 . V_146 = 0 ;
F_40 () ;
V_248 = F_41 ( V_12 -> V_26 . V_248 ) ;
if ( V_248 )
V_250 = V_248 -> V_257 . V_258 ;
else
V_250 = NULL ;
F_44 () ;
if ( V_250 ) {
V_253 = 0 ;
do {
V_252 . V_146 = 0 ;
if ( F_71 ( V_9 , V_253 , & V_252 ) != 0 ) {
V_252 . V_146 = 0 ;
break;
}
V_253 ++ ;
} while ( V_250 != V_252 . V_250 );
}
if ( V_252 . V_146 )
V_246 [ V_142 ++ ] = V_252 . V_250 -> V_259 ;
else
V_246 [ V_142 ++ ] = 0 ;
if ( V_252 . V_146 & V_260 )
V_246 [ V_142 ++ ] = ( T_3 ) V_252 . V_261 ;
else
V_246 [ V_142 ++ ] = - 1LL ;
if ( V_252 . V_146 & V_262 )
V_246 [ V_142 ++ ] = V_252 . V_263 ;
else
V_246 [ V_142 ++ ] = - 1LL ;
if ( V_252 . V_146 & V_264 )
V_246 [ V_142 ++ ] = V_252 . V_265 ;
else
V_246 [ V_142 ++ ] = - 1LL ;
if ( V_252 . V_146 & V_266 )
V_246 [ V_142 ++ ] = V_252 . V_267 ;
else
V_246 [ V_142 ++ ] = - 1LL ;
if ( V_252 . V_146 & V_268 )
V_246 [ V_142 ++ ] = V_252 . V_269 ;
else
V_246 [ V_142 ++ ] = - 1LL ;
if ( V_252 . V_146 & V_270 )
V_246 [ V_142 ++ ] = V_252 . V_271 ;
else
V_246 [ V_142 ++ ] = - 1LL ;
F_34 ( & V_9 -> V_56 ) ;
if ( F_68 ( V_142 != V_242 ) )
return;
F_72 ( V_12 , V_245 , & ( V_246 [ V_242 ] ) ) ;
}
static void F_73 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_239 , T_3 * V_246 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_272 = 0 ;
if ( V_239 == V_241 ) {
V_272 = sizeof( V_273 ) ;
memcpy ( V_246 , V_273 , V_272 ) ;
}
F_74 ( V_12 , V_239 , & ( V_246 [ V_272 ] ) ) ;
}
static int F_75 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_105 , T_3 * V_274 , struct V_137 * V_138 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_58 ;
F_25 ( & V_9 -> V_56 ) ;
V_23 = F_76 ( V_12 , V_105 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_274 , V_23 -> V_23 . V_275 , V_276 ) ;
F_56 ( V_23 , V_138 ) ;
}
F_34 ( & V_9 -> V_56 ) ;
return V_19 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_105 , struct V_251 * V_252 )
{
struct V_8 * V_9 = F_78 ( V_18 -> V_277 ) ;
return F_71 ( V_9 , V_105 , V_252 ) ;
}
static int F_79 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_274 , struct V_137 * V_138 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_58 ;
F_25 ( & V_9 -> V_56 ) ;
V_23 = F_28 ( V_12 , V_274 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_56 ( V_23 , V_138 ) ;
}
F_34 ( & V_9 -> V_56 ) ;
return V_19 ;
}
static int F_80 ( struct V_2 * V_2 ,
struct V_278 * V_279 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_81 ( & V_9 -> V_280 , V_279 ) )
return 0 ;
F_25 ( & V_9 -> V_281 ) ;
F_25 ( & V_9 -> V_282 ) ;
if ( V_9 -> V_283 ) {
V_12 = F_82 (
V_9 -> V_284 ,
F_83 ( & V_9 -> V_282 ) ) ;
if ( V_12 ) {
F_84 ( V_12 ) ;
V_19 = F_85 ( V_12 , V_279 ,
V_285 ) ;
}
} else if ( V_9 -> V_286 == V_9 -> V_287 ) {
V_9 -> V_288 = * V_279 ;
F_86 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_280 = * V_279 ;
F_34 ( & V_9 -> V_282 ) ;
F_34 ( & V_9 -> V_281 ) ;
return V_19 ;
}
static int F_87 ( struct V_11 * V_12 ,
const T_3 * V_289 , T_5 V_290 )
{
struct V_291 * V_292 , * V_293 ;
if ( ! V_289 || ! V_290 )
return 1 ;
V_293 = F_88 ( V_12 -> V_15 . V_294 . V_291 , V_12 ) ;
V_292 = F_89 ( sizeof( struct V_291 ) + V_290 , V_295 ) ;
if ( ! V_292 )
return - V_296 ;
V_292 -> V_297 = V_290 ;
memcpy ( V_292 -> V_246 , V_289 , V_290 ) ;
F_90 ( V_12 -> V_15 . V_294 . V_291 , V_292 ) ;
if ( V_293 )
F_91 ( V_293 , V_298 ) ;
return 0 ;
}
static int F_92 ( struct V_11 * V_12 ,
struct V_299 * V_7 )
{
struct V_300 * V_292 , * V_293 ;
int V_301 , V_302 ;
int V_303 , V_13 ;
T_1 V_304 = V_305 ;
V_293 = F_88 ( V_12 -> V_15 . V_294 . V_306 , V_12 ) ;
if ( ! V_7 -> V_307 && ! V_293 )
return - V_47 ;
if ( V_7 -> V_307 )
V_301 = V_7 -> V_308 ;
else
V_301 = V_293 -> V_308 ;
if ( V_7 -> V_309 || ! V_293 )
V_302 = V_7 -> V_310 ;
else
V_302 = V_293 -> V_310 ;
V_303 = sizeof( * V_292 ) + V_301 + V_302 ;
V_292 = F_89 ( V_303 , V_295 ) ;
if ( ! V_292 )
return - V_296 ;
V_292 -> V_307 = ( ( T_3 * ) V_292 ) + sizeof( * V_292 ) ;
V_292 -> V_309 = V_292 -> V_307 + V_301 ;
V_292 -> V_308 = V_301 ;
V_292 -> V_310 = V_302 ;
if ( V_7 -> V_307 )
memcpy ( V_292 -> V_307 , V_7 -> V_307 , V_301 ) ;
else
memcpy ( V_292 -> V_307 , V_293 -> V_307 , V_301 ) ;
if ( V_7 -> V_309 )
memcpy ( V_292 -> V_309 , V_7 -> V_309 , V_302 ) ;
else
if ( V_293 )
memcpy ( V_292 -> V_309 , V_293 -> V_309 , V_302 ) ;
V_13 = F_87 ( V_12 , V_7 -> V_291 ,
V_7 -> V_311 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_304 |= V_312 ;
F_90 ( V_12 -> V_15 . V_294 . V_306 , V_292 ) ;
if ( V_293 )
F_91 ( V_293 , V_298 ) ;
return V_304 ;
}
static int F_93 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_313 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_300 * V_293 ;
struct V_11 * V_22 ;
T_1 V_304 = V_314 |
V_315 |
V_305 |
V_316 |
V_317 ;
int V_13 ;
V_293 = F_88 ( V_12 -> V_15 . V_294 . V_306 , V_12 ) ;
if ( V_293 )
return - V_318 ;
V_12 -> V_319 = V_320 ;
V_12 -> V_321 = V_12 -> V_9 -> V_322 ;
V_12 -> V_323 = V_7 -> V_323 ;
F_25 ( & V_9 -> V_281 ) ;
V_13 = F_85 ( V_12 , & V_7 -> V_279 ,
V_324 ) ;
F_34 ( & V_9 -> V_281 ) ;
if ( V_13 )
return V_13 ;
F_94 ( V_12 , false ) ;
V_12 -> V_325 = V_7 -> V_326 . V_327 ;
V_12 -> V_328 = V_7 -> V_326 . V_328 ;
V_12 -> V_329 = F_95 ( V_12 -> V_9 ,
& V_7 -> V_326 ,
V_12 -> V_26 . type ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_325 =
V_7 -> V_326 . V_327 ;
V_22 -> V_328 =
V_7 -> V_326 . V_328 ;
V_22 -> V_329 =
F_95 ( V_12 -> V_9 ,
& V_7 -> V_326 ,
V_22 -> V_26 . type ) ;
}
V_12 -> V_26 . V_214 . V_224 = V_7 -> V_223 ;
V_12 -> V_26 . V_214 . V_221 = V_7 -> V_221 ;
V_12 -> V_26 . V_214 . V_330 = true ;
V_12 -> V_26 . V_214 . V_331 = V_7 -> V_331 ;
if ( V_7 -> V_331 )
memcpy ( V_12 -> V_26 . V_214 . V_332 , V_7 -> V_332 ,
V_7 -> V_331 ) ;
V_12 -> V_26 . V_214 . V_333 =
( V_7 -> V_333 != V_334 ) ;
memset ( & V_12 -> V_26 . V_214 . V_335 , 0 ,
sizeof( V_12 -> V_26 . V_214 . V_335 ) ) ;
V_12 -> V_26 . V_214 . V_335 . V_336 =
V_7 -> V_337 & V_338 ;
if ( V_7 -> V_339 )
V_12 -> V_26 . V_214 . V_335 . V_336 |=
V_340 ;
V_13 = F_92 ( V_12 , & V_7 -> V_306 ) ;
if ( V_13 < 0 ) {
F_84 ( V_12 ) ;
return V_13 ;
}
V_304 |= V_13 ;
V_13 = F_96 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_293 = F_88 ( V_12 -> V_15 . V_294 . V_306 , V_12 ) ;
if ( V_293 )
F_91 ( V_293 , V_298 ) ;
F_11 ( V_12 -> V_15 . V_294 . V_306 , NULL ) ;
F_84 ( V_12 ) ;
return V_13 ;
}
F_97 ( V_9 , V_12 ) ;
F_98 ( V_12 , V_304 ) ;
F_99 ( V_18 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_99 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_100 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_299 * V_7 )
{
struct V_11 * V_12 ;
struct V_300 * V_293 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
if ( V_12 -> V_26 . V_341 )
return - V_30 ;
V_293 = F_88 ( V_12 -> V_15 . V_294 . V_306 , V_12 ) ;
if ( ! V_293 )
return - V_58 ;
V_13 = F_92 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_98 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_101 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_300 * V_342 ;
struct V_291 * V_343 ;
struct V_278 V_279 ;
V_342 = F_88 ( V_12 -> V_15 . V_294 . V_306 , V_12 ) ;
if ( ! V_342 )
return - V_58 ;
V_343 = F_88 ( V_12 -> V_15 . V_294 . V_291 , V_12 ) ;
V_12 -> V_26 . V_341 = false ;
F_102 ( V_12 -> V_15 . V_294 . V_344 ) ;
V_12 -> V_15 . V_294 . V_344 = NULL ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_103 ( V_22 -> V_18 ) ;
F_103 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_294 . V_306 , NULL ) ;
F_11 ( V_12 -> V_15 . V_294 . V_291 , NULL ) ;
F_91 ( V_342 , V_298 ) ;
if ( V_343 )
F_91 ( V_343 , V_298 ) ;
V_12 -> V_15 . V_294 . V_345 = V_320 ;
F_104 ( V_12 , true ) ;
F_105 ( V_12 , true ) ;
V_12 -> V_26 . V_214 . V_330 = false ;
V_12 -> V_26 . V_214 . V_331 = 0 ;
F_106 ( V_346 , & V_12 -> V_347 ) ;
F_98 ( V_12 , V_315 ) ;
if ( V_12 -> V_10 . V_348 ) {
V_279 = V_12 -> V_26 . V_214 . V_279 ;
F_107 ( & V_12 -> V_349 ) ;
F_108 ( V_12 -> V_18 , & V_279 ,
V_350 ,
V_295 ) ;
}
F_109 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_351 -= F_110 ( & V_12 -> V_15 . V_294 . V_352 . V_353 ) ;
F_111 ( & V_12 -> V_15 . V_294 . V_352 . V_353 ) ;
F_94 ( V_12 , true ) ;
F_25 ( & V_9 -> V_281 ) ;
F_84 ( V_12 ) ;
F_34 ( & V_9 -> V_281 ) ;
return 0 ;
}
static void F_112 ( struct V_36 * V_23 )
{
struct V_354 * V_355 ;
struct V_356 * V_357 ;
V_357 = F_113 ( sizeof( * V_355 ) ) ;
if ( ! V_357 )
return;
V_355 = (struct V_354 * ) F_114 ( V_357 , sizeof( * V_355 ) ) ;
F_115 ( V_355 -> V_358 ) ;
memcpy ( V_355 -> V_359 , V_23 -> V_23 . V_275 , V_276 ) ;
V_355 -> V_297 = F_116 ( 6 ) ;
V_355 -> V_360 = 0 ;
V_355 -> V_361 = 0x01 ;
V_355 -> V_362 = 0xaf ;
V_355 -> V_363 [ 0 ] = 0x81 ;
V_355 -> V_363 [ 1 ] = 1 ;
V_355 -> V_363 [ 2 ] = 0 ;
V_357 -> V_18 = V_23 -> V_12 -> V_18 ;
V_357 -> V_364 = F_117 ( V_357 , V_23 -> V_12 -> V_18 ) ;
memset ( V_357 -> V_365 , 0 , sizeof( V_357 -> V_365 ) ) ;
F_118 ( V_357 ) ;
}
static int F_119 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
T_1 V_27 , T_1 V_226 )
{
int V_19 ;
if ( V_27 & F_62 ( V_231 ) &&
V_226 & F_62 ( V_231 ) &&
! F_29 ( V_23 , V_237 ) ) {
V_19 = F_120 ( V_23 , V_366 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_232 ) &&
V_226 & F_62 ( V_232 ) &&
! F_29 ( V_23 , V_57 ) ) {
V_19 = F_120 ( V_23 , V_367 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_227 ) ) {
if ( V_226 & F_62 ( V_227 ) )
V_19 = F_120 ( V_23 , V_368 ) ;
else if ( F_29 ( V_23 , V_234 ) )
V_19 = F_120 ( V_23 , V_367 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_232 ) &&
! ( V_226 & F_62 ( V_232 ) ) &&
F_29 ( V_23 , V_57 ) ) {
V_19 = F_120 ( V_23 , V_366 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_231 ) &&
! ( V_226 & F_62 ( V_231 ) ) &&
F_29 ( V_23 , V_237 ) ) {
V_19 = F_120 ( V_23 , V_369 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_121 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
struct V_370 * V_7 )
{
int V_19 = 0 ;
struct V_109 * V_110 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_371 V_372 = F_53 ( V_12 ) ;
T_1 V_27 , V_226 ;
V_110 = V_9 -> V_113 . V_2 -> V_114 [ V_372 ] ;
V_27 = V_7 -> V_373 ;
V_226 = V_7 -> V_374 ;
if ( F_26 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_62 ( V_231 ) )
V_27 |= F_62 ( V_232 ) ;
if ( V_226 & F_62 ( V_231 ) )
V_226 |= F_62 ( V_232 ) ;
} else if ( F_29 ( V_23 , V_238 ) ) {
if ( V_226 & F_62 ( V_227 ) ) {
V_226 |= F_62 ( V_231 ) |
F_62 ( V_232 ) ;
V_27 |= F_62 ( V_231 ) |
F_62 ( V_232 ) ;
}
}
V_19 = F_119 ( V_9 , V_23 , V_27 , V_226 ) ;
if ( V_19 )
return V_19 ;
if ( V_27 & F_62 ( V_228 ) ) {
if ( V_226 & F_62 ( V_228 ) )
F_122 ( V_23 , V_235 ) ;
else
F_123 ( V_23 , V_235 ) ;
}
if ( V_27 & F_62 ( V_229 ) ) {
if ( V_226 & F_62 ( V_229 ) ) {
F_122 ( V_23 , V_236 ) ;
V_23 -> V_23 . V_375 = true ;
} else {
F_123 ( V_23 , V_236 ) ;
V_23 -> V_23 . V_375 = false ;
}
}
if ( V_27 & F_62 ( V_230 ) ) {
if ( V_226 & F_62 ( V_230 ) )
F_122 ( V_23 , V_64 ) ;
else
F_123 ( V_23 , V_64 ) ;
}
if ( V_27 & F_62 ( V_233 ) ) {
if ( V_226 & F_62 ( V_233 ) )
F_122 ( V_23 , V_238 ) ;
else
F_123 ( V_23 , V_238 ) ;
}
if ( V_7 -> V_376 & V_377 ) {
V_23 -> V_23 . V_378 = V_7 -> V_378 ;
V_23 -> V_23 . V_379 = V_7 -> V_379 ;
}
if ( V_7 -> V_380 )
V_23 -> V_23 . V_380 = V_7 -> V_380 ;
if ( V_7 -> V_381 >= 0 )
V_23 -> V_381 = V_7 -> V_381 ;
if ( V_7 -> V_382 ) {
F_124 ( & V_12 -> V_26 . V_214 . V_279 ,
V_110 , V_7 -> V_382 ,
V_7 -> V_383 ,
& V_23 -> V_23 . V_384 [ V_372 ] ) ;
}
if ( V_7 -> V_385 )
F_125 ( V_12 , V_110 ,
V_7 -> V_385 , V_23 ) ;
if ( V_7 -> V_386 )
F_126 ( V_12 , V_110 ,
V_7 -> V_386 , V_23 ) ;
if ( F_26 ( & V_12 -> V_26 ) ) {
#ifdef F_31
T_1 V_304 = 0 ;
if ( V_7 -> V_376 & V_387 ) {
switch ( V_7 -> V_206 ) {
case V_388 :
if ( V_23 -> V_206 != V_388 )
V_304 = F_127 (
V_12 ) ;
V_23 -> V_206 = V_7 -> V_206 ;
F_128 ( V_23 ) ;
V_304 |= F_129 ( V_23 ,
V_12 -> V_15 . V_67 . V_389 . V_390 ) ;
break;
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
if ( V_23 -> V_206 == V_388 )
V_304 = F_130 (
V_12 ) ;
V_23 -> V_206 = V_7 -> V_206 ;
F_128 ( V_23 ) ;
V_304 |= F_129 ( V_23 ,
V_397 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_398 ) {
case V_399 :
break;
case V_400 :
V_304 |= F_131 ( V_23 ) ;
break;
case V_401 :
V_304 |= F_132 ( V_23 ) ;
break;
}
if ( V_7 -> V_210 )
V_304 |=
F_129 ( V_23 ,
V_7 -> V_210 ) ;
F_133 ( V_12 , V_304 ) ;
#endif
}
return 0 ;
}
static int F_134 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_274 , struct V_370 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_402 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_63 )
return - V_47 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_135 ( V_274 , V_12 -> V_26 . V_275 ) )
return - V_47 ;
if ( F_136 ( V_274 ) )
return - V_47 ;
V_23 = F_137 ( V_12 , V_274 , V_295 ) ;
if ( ! V_23 )
return - V_296 ;
if ( ! ( V_7 -> V_374 & F_62 ( V_233 ) ) ) {
F_138 ( V_23 , V_366 ) ;
F_138 ( V_23 , V_367 ) ;
}
V_13 = F_121 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_139 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_29 ( V_23 , V_238 ) )
F_140 ( V_23 ) ;
V_402 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_63 ;
V_13 = F_141 ( V_23 ) ;
if ( V_13 ) {
F_44 () ;
return V_13 ;
}
if ( V_402 )
F_112 ( V_23 ) ;
F_44 () ;
return 0 ;
}
static int F_142 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_274 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_274 )
return F_143 ( V_12 , V_274 ) ;
F_144 ( V_12 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_3 * V_274 ,
struct V_370 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_403 ;
enum V_404 V_405 ;
int V_13 ;
F_25 ( & V_9 -> V_56 ) ;
V_23 = F_28 ( V_12 , V_274 ) ;
if ( ! V_23 ) {
V_13 = - V_58 ;
goto V_406;
}
switch ( V_12 -> V_26 . type ) {
case V_66 :
if ( V_12 -> V_15 . V_67 . V_407 )
V_405 = V_408 ;
else
V_405 = V_409 ;
break;
case V_65 :
V_405 = V_410 ;
break;
case V_24 :
if ( ! F_29 ( V_23 , V_238 ) ) {
V_405 = V_411 ;
break;
}
if ( F_29 ( V_23 , V_234 ) )
V_405 = V_412 ;
else
V_405 = V_413 ;
break;
case V_63 :
case V_20 :
V_405 = V_414 ;
break;
default:
V_13 = - V_243 ;
goto V_406;
}
V_13 = F_146 ( V_2 , V_7 , V_405 ) ;
if ( V_13 )
goto V_406;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_415 = false ;
bool V_416 = false ;
V_403 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_277 -> V_21 ) {
if ( V_403 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_406;
}
F_90 ( V_403 -> V_15 . V_22 . V_23 , V_23 ) ;
V_416 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_90 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_415 = true ;
}
V_23 -> V_12 = V_403 ;
if ( V_23 -> V_256 == V_368 &&
V_415 != V_416 ) {
if ( V_416 )
F_147 ( & V_23 -> V_12 -> V_417 -> V_418 ) ;
else
F_148 ( & V_23 -> V_12 -> V_417 -> V_418 ) ;
}
F_112 ( V_23 ) ;
}
V_13 = F_121 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_406;
if ( F_29 ( V_23 , V_238 ) &&
F_29 ( V_23 , V_234 ) )
F_140 ( V_23 ) ;
F_34 ( & V_9 -> V_56 ) ;
if ( ( V_12 -> V_26 . type == V_63 ||
V_12 -> V_26 . type == V_20 ) &&
V_23 -> V_419 != V_23 -> V_12 -> V_417 -> V_420 &&
F_29 ( V_23 , V_234 ) &&
F_149 ( V_23 ) != 1 ) {
F_150 ( V_23 -> V_12 ,
L_1 ,
V_23 -> V_23 . V_275 ) ;
F_151 ( V_23 -> V_12 ,
V_23 -> V_12 -> V_417 -> V_420 ,
V_23 -> V_23 . V_275 ,
V_23 -> V_12 -> V_26 . V_214 . V_254 ) ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_373 & F_62 ( V_227 ) ) {
F_152 ( V_9 , - 1 ) ;
F_153 ( V_12 ) ;
}
return 0 ;
V_406:
F_34 ( & V_9 -> V_56 ) ;
return V_13 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_421 , T_3 * V_422 )
{
struct V_11 * V_12 ;
struct V_423 * V_424 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_23 = F_27 ( V_12 , V_422 ) ;
if ( ! V_23 ) {
F_44 () ;
return - V_58 ;
}
V_424 = F_155 ( V_12 , V_421 ) ;
if ( F_21 ( V_424 ) ) {
F_44 () ;
return F_24 ( V_424 ) ;
}
F_156 ( V_424 , V_23 ) ;
F_44 () ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_421 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_421 )
return F_158 ( V_12 , V_421 ) ;
F_159 ( V_12 ) ;
return 0 ;
}
static int F_160 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_421 , T_3 * V_422 )
{
struct V_11 * V_12 ;
struct V_423 * V_424 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_23 = F_27 ( V_12 , V_422 ) ;
if ( ! V_23 ) {
F_44 () ;
return - V_58 ;
}
V_424 = F_161 ( V_12 , V_421 ) ;
if ( ! V_424 ) {
F_44 () ;
return - V_58 ;
}
F_156 ( V_424 , V_23 ) ;
F_44 () ;
return 0 ;
}
static void F_162 ( struct V_423 * V_424 , T_3 * V_422 ,
struct V_425 * V_426 )
{
struct V_36 * V_427 = F_41 ( V_424 -> V_422 ) ;
if ( V_427 )
memcpy ( V_422 , V_427 -> V_23 . V_275 , V_276 ) ;
else
memset ( V_422 , 0 , V_276 ) ;
memset ( V_426 , 0 , sizeof( * V_426 ) ) ;
V_426 -> V_144 = V_428 ;
V_426 -> V_146 = V_429 |
V_430 |
V_431 |
V_432 |
V_433 |
V_434 |
V_435 ;
V_426 -> V_436 = V_424 -> V_437 . V_438 ;
V_426 -> V_439 = V_424 -> V_439 ;
V_426 -> V_440 = V_424 -> V_440 ;
if ( F_163 ( V_165 , V_424 -> V_441 ) )
V_426 -> V_442 = F_58 ( V_424 -> V_441 - V_165 ) ;
V_426 -> V_443 =
F_58 ( V_424 -> V_443 ) ;
V_426 -> V_444 = V_424 -> V_444 ;
if ( V_424 -> V_5 & V_445 )
V_426 -> V_5 |= V_446 ;
if ( V_424 -> V_5 & V_447 )
V_426 -> V_5 |= V_448 ;
if ( V_424 -> V_5 & V_449 )
V_426 -> V_5 |= V_450 ;
if ( V_424 -> V_5 & V_451 )
V_426 -> V_5 |= V_452 ;
if ( V_424 -> V_5 & V_453 )
V_426 -> V_5 |= V_454 ;
}
static int F_164 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_421 , T_3 * V_422 , struct V_425 * V_426 )
{
struct V_11 * V_12 ;
struct V_423 * V_424 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_424 = F_161 ( V_12 , V_421 ) ;
if ( ! V_424 ) {
F_44 () ;
return - V_58 ;
}
memcpy ( V_421 , V_424 -> V_421 , V_276 ) ;
F_162 ( V_424 , V_422 , V_426 ) ;
F_44 () ;
return 0 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_105 , T_3 * V_421 , T_3 * V_422 ,
struct V_425 * V_426 )
{
struct V_11 * V_12 ;
struct V_423 * V_424 ;
V_12 = F_9 ( V_18 ) ;
F_40 () ;
V_424 = F_166 ( V_12 , V_105 ) ;
if ( ! V_424 ) {
F_44 () ;
return - V_58 ;
}
memcpy ( V_421 , V_424 -> V_421 , V_276 ) ;
F_162 ( V_424 , V_422 , V_426 ) ;
F_44 () ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_455 * V_54 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_54 , & ( V_12 -> V_15 . V_67 . V_389 ) , sizeof( struct V_455 ) ) ;
return 0 ;
}
static inline bool F_168 ( enum V_456 V_457 , T_1 V_27 )
{
return ( V_27 >> ( V_457 - 1 ) ) & 0x1 ;
}
static int F_169 ( struct V_458 * V_459 ,
const struct V_460 * V_461 )
{
T_3 * V_462 ;
const T_3 * V_463 ;
struct V_11 * V_12 = F_170 ( V_459 ,
struct V_11 , V_15 . V_67 ) ;
V_462 = NULL ;
V_463 = V_459 -> V_464 ;
if ( V_461 -> V_465 ) {
V_462 = F_171 ( V_461 -> V_464 , V_461 -> V_465 ,
V_295 ) ;
if ( ! V_462 )
return - V_296 ;
}
V_459 -> V_465 = V_461 -> V_465 ;
V_459 -> V_464 = V_462 ;
F_102 ( V_463 ) ;
V_459 -> V_466 = V_461 -> V_466 ;
memcpy ( V_459 -> V_467 , V_461 -> V_467 , V_459 -> V_466 ) ;
V_459 -> V_468 = V_461 -> V_469 ;
V_459 -> V_470 = V_461 -> V_471 ;
V_459 -> V_472 = V_461 -> V_473 ;
V_459 -> V_407 = V_461 -> V_407 ;
V_459 -> V_474 = V_461 -> V_475 ;
V_459 -> V_68 = V_69 ;
if ( V_461 -> V_476 )
V_459 -> V_68 |= V_477 ;
if ( V_461 -> V_478 )
V_459 -> V_68 |= V_479 ;
memcpy ( V_12 -> V_26 . V_214 . V_480 , V_461 -> V_480 ,
sizeof( V_461 -> V_480 ) ) ;
V_12 -> V_26 . V_214 . V_481 = V_461 -> V_481 ;
V_12 -> V_26 . V_214 . V_224 = V_461 -> V_223 ;
V_12 -> V_26 . V_214 . V_221 = V_461 -> V_221 ;
return 0 ;
}
static int F_172 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_455 * V_482 )
{
struct V_455 * V_54 ;
struct V_11 * V_12 ;
struct V_458 * V_459 ;
V_12 = F_9 ( V_18 ) ;
V_459 = & V_12 -> V_15 . V_67 ;
V_54 = & ( V_12 -> V_15 . V_67 . V_389 ) ;
if ( F_168 ( V_483 , V_27 ) )
V_54 -> V_484 = V_482 -> V_484 ;
if ( F_168 ( V_485 , V_27 ) )
V_54 -> V_486 = V_482 -> V_486 ;
if ( F_168 ( V_487 , V_27 ) )
V_54 -> V_488 = V_482 -> V_488 ;
if ( F_168 ( V_489 , V_27 ) )
V_54 -> V_490 = V_482 -> V_490 ;
if ( F_168 ( V_491 , V_27 ) )
V_54 -> V_492 = V_482 -> V_492 ;
if ( F_168 ( V_493 , V_27 ) )
V_54 -> V_494 = V_482 -> V_494 ;
if ( F_168 ( V_495 , V_27 ) )
V_54 -> V_496 = V_482 -> V_496 ;
if ( F_168 ( V_497 , V_27 ) ) {
if ( V_459 -> V_407 )
return - V_30 ;
V_54 -> V_498 = V_482 -> V_498 ;
}
if ( F_168 ( V_499 , V_27 ) )
V_54 -> V_500 =
V_482 -> V_500 ;
if ( F_168 ( V_501 , V_27 ) )
V_54 -> V_502 =
V_482 -> V_502 ;
if ( F_168 ( V_503 , V_27 ) )
V_54 -> V_504 = V_482 -> V_504 ;
if ( F_168 ( V_505 , V_27 ) )
V_54 -> V_506 = V_482 -> V_506 ;
if ( F_168 ( V_507 , V_27 ) )
V_54 -> V_508 =
V_482 -> V_508 ;
if ( F_168 ( V_509 , V_27 ) )
V_54 -> V_510 =
V_482 -> V_510 ;
if ( F_168 ( V_511 , V_27 ) )
V_54 -> V_512 =
V_482 -> V_512 ;
if ( F_168 ( V_513 ,
V_27 ) )
V_54 -> V_514 =
V_482 -> V_514 ;
if ( F_168 ( V_515 , V_27 ) ) {
V_54 -> V_516 = V_482 -> V_516 ;
F_173 ( V_459 ) ;
}
if ( F_168 ( V_517 , V_27 ) ) {
if ( V_482 -> V_518 &&
! ( V_54 -> V_516 > V_519 ) ) {
V_54 -> V_516 = V_520 ;
F_173 ( V_459 ) ;
}
V_54 -> V_518 =
V_482 -> V_518 ;
}
if ( F_168 ( V_521 , V_27 ) )
V_54 -> V_522 =
V_482 -> V_522 ;
if ( F_168 ( V_523 , V_27 ) )
V_54 -> V_524 = V_482 -> V_524 ;
if ( F_168 ( V_525 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_113 . V_5 & V_179 ) )
return - V_526 ;
V_54 -> V_527 = V_482 -> V_527 ;
}
if ( F_168 ( V_528 , V_27 ) ) {
V_54 -> V_529 = V_482 -> V_529 ;
V_12 -> V_26 . V_214 . V_530 = V_482 -> V_529 ;
F_98 ( V_12 , V_531 ) ;
}
if ( F_168 ( V_532 , V_27 ) )
V_54 -> V_533 =
V_482 -> V_533 ;
if ( F_168 ( V_534 , V_27 ) )
V_54 -> V_535 =
V_482 -> V_535 ;
if ( F_168 ( V_536 , V_27 ) )
V_54 -> V_537 =
V_482 -> V_537 ;
if ( F_168 ( V_538 , V_27 ) ) {
V_54 -> V_390 = V_482 -> V_390 ;
F_174 ( V_12 ) ;
}
if ( F_168 ( V_539 , V_27 ) )
V_54 -> V_540 =
V_482 -> V_540 ;
if ( F_168 ( V_541 , V_27 ) )
V_54 -> V_542 = V_482 -> V_542 ;
F_133 ( V_12 , V_305 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_455 * V_54 ,
const struct V_460 * V_461 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_458 * V_459 = & V_12 -> V_15 . V_67 ;
int V_13 ;
memcpy ( & V_459 -> V_389 , V_54 , sizeof( struct V_455 ) ) ;
V_13 = F_169 ( V_459 , V_461 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_319 = V_320 ;
V_12 -> V_321 = V_12 -> V_9 -> V_322 ;
F_25 ( & V_12 -> V_9 -> V_281 ) ;
V_13 = F_85 ( V_12 , & V_461 -> V_279 ,
V_324 ) ;
F_34 ( & V_12 -> V_9 -> V_281 ) ;
if ( V_13 )
return V_13 ;
return F_176 ( V_12 ) ;
}
static int F_177 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_178 ( V_12 ) ;
F_25 ( & V_12 -> V_9 -> V_281 ) ;
F_84 ( V_12 ) ;
F_34 ( & V_12 -> V_9 -> V_281 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_543 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_371 V_372 ;
T_1 V_304 = 0 ;
if ( ! F_88 ( V_12 -> V_15 . V_294 . V_306 , V_12 ) )
return - V_58 ;
V_372 = F_53 ( V_12 ) ;
if ( V_7 -> V_215 >= 0 ) {
V_12 -> V_26 . V_214 . V_215 = V_7 -> V_215 ;
V_304 |= V_544 ;
}
if ( V_7 -> V_217 >= 0 ) {
V_12 -> V_26 . V_214 . V_217 =
V_7 -> V_217 ;
V_304 |= V_545 ;
}
if ( ! V_12 -> V_26 . V_214 . V_219 &&
V_372 == V_546 ) {
V_12 -> V_26 . V_214 . V_219 = true ;
V_304 |= V_547 ;
}
if ( V_7 -> V_548 >= 0 ) {
V_12 -> V_26 . V_214 . V_219 =
V_7 -> V_548 ;
V_304 |= V_547 ;
}
if ( V_7 -> V_481 ) {
F_124 ( & V_12 -> V_26 . V_214 . V_279 ,
V_2 -> V_114 [ V_372 ] ,
V_7 -> V_481 ,
V_7 -> V_549 ,
& V_12 -> V_26 . V_214 . V_481 ) ;
V_304 |= V_550 ;
}
if ( V_7 -> V_551 >= 0 ) {
if ( V_7 -> V_551 )
V_12 -> V_5 |= V_552 ;
else
V_12 -> V_5 &= ~ V_552 ;
}
if ( V_7 -> V_529 >= 0 ) {
V_12 -> V_26 . V_214 . V_530 =
( T_2 ) V_7 -> V_529 ;
V_304 |= V_531 ;
}
if ( V_7 -> V_337 >= 0 ) {
V_12 -> V_26 . V_214 . V_335 . V_336 &=
~ V_338 ;
V_12 -> V_26 . V_214 . V_335 . V_336 |=
V_7 -> V_337 & V_338 ;
V_304 |= V_317 ;
}
if ( V_7 -> V_339 > 0 ) {
V_12 -> V_26 . V_214 . V_335 . V_336 |=
V_340 ;
V_304 |= V_317 ;
} else if ( V_7 -> V_339 == 0 ) {
V_12 -> V_26 . V_214 . V_335 . V_336 &=
~ V_340 ;
V_304 |= V_317 ;
}
F_98 ( V_12 , V_304 ) ;
return 0 ;
}
static int F_180 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_553 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_554 V_555 ;
if ( ! V_9 -> V_183 -> V_556 )
return - V_243 ;
if ( V_9 -> V_113 . V_557 < V_168 )
return - V_243 ;
memset ( & V_555 , 0 , sizeof( V_555 ) ) ;
V_555 . V_558 = V_7 -> V_558 ;
V_555 . V_559 = V_7 -> V_560 ;
V_555 . V_561 = V_7 -> V_562 ;
V_555 . V_563 = V_7 -> V_563 ;
V_555 . V_564 = false ;
V_12 -> V_565 [ V_7 -> V_143 ] = V_555 ;
if ( F_181 ( V_9 , V_12 , V_7 -> V_143 , & V_555 ) ) {
F_182 ( V_9 -> V_113 . V_2 ,
L_2 ,
V_7 -> V_143 ) ;
return - V_47 ;
}
F_98 ( V_12 , V_566 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_2 ,
struct V_567 * V_568 )
{
return F_184 ( F_2 ( V_2 ) , V_568 ) ;
}
static int F_185 ( struct V_2 * V_2 )
{
return F_186 ( F_2 ( V_2 ) ) ;
}
static int F_187 ( struct V_2 * V_2 ,
struct V_569 * V_570 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_570 -> V_10 ) ;
switch ( F_188 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_65 :
case V_66 :
case V_74 :
case V_71 :
break;
case V_75 :
if ( V_12 -> V_9 -> V_183 -> V_571 )
break;
case V_63 :
if ( V_12 -> V_15 . V_294 . V_306 &&
( ! ( V_2 -> V_572 & V_573 ) ||
! ( V_570 -> V_5 & V_574 ) ) )
return - V_243 ;
break;
default:
return - V_243 ;
}
return F_189 ( V_12 , V_570 ) ;
}
static int
F_190 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_575 * V_570 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_183 -> V_576 )
return - V_243 ;
return F_191 ( V_12 , V_570 ) ;
}
static int
F_192 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_183 -> V_577 )
return - V_243 ;
return F_193 ( V_12 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_578 * V_570 )
{
return F_195 ( F_9 ( V_18 ) , V_570 ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_579 * V_570 )
{
return F_197 ( F_9 ( V_18 ) , V_570 ) ;
}
static int F_198 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_580 * V_570 )
{
return F_199 ( F_9 ( V_18 ) , V_570 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_581 * V_570 )
{
return F_201 ( F_9 ( V_18 ) , V_570 ) ;
}
static int F_202 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_582 * V_7 )
{
return F_203 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_204 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_205 ( F_9 ( V_18 ) ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_99 [ V_583 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_214 . V_480 , V_99 ,
sizeof( int ) * V_583 ) ;
return 0 ;
}
static int F_207 ( struct V_2 * V_2 , T_1 V_304 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_304 & V_584 ) {
V_13 = F_208 ( V_9 , V_2 -> V_585 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_304 & V_586 ) {
V_13 = F_209 ( V_9 , V_2 -> V_587 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_304 & V_588 ) {
V_13 = F_210 ( V_9 , V_2 -> V_589 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_304 & V_590 ) {
if ( V_2 -> V_591 > V_592 )
return - V_47 ;
V_9 -> V_113 . V_54 . V_593 = V_2 -> V_591 ;
}
if ( V_304 & V_594 ) {
if ( V_2 -> V_595 > V_592 )
return - V_47 ;
V_9 -> V_113 . V_54 . V_596 = V_2 -> V_595 ;
}
if ( V_304 &
( V_590 | V_594 ) )
F_86 ( V_9 , V_597 ) ;
return 0 ;
}
static int F_211 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_598 type , int V_599 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_600 :
V_12 -> V_601 = V_602 ;
break;
case V_603 :
case V_604 :
if ( V_599 < 0 || ( V_599 % 100 ) )
return - V_243 ;
V_12 -> V_601 = F_212 ( V_599 ) ;
break;
}
F_213 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_600 :
V_9 -> V_601 = V_602 ;
break;
case V_603 :
case V_604 :
if ( V_599 < 0 || ( V_599 % 100 ) )
return - V_243 ;
V_9 -> V_601 = F_212 ( V_599 ) ;
break;
}
F_25 ( & V_9 -> V_282 ) ;
F_70 (sdata, &local->interfaces, list)
V_12 -> V_601 = V_9 -> V_601 ;
F_70 (sdata, &local->interfaces, list)
F_213 ( V_12 ) ;
F_34 ( & V_9 -> V_282 ) ;
return 0 ;
}
static int F_214 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_605 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_283 )
* V_605 = V_9 -> V_113 . V_54 . V_606 ;
else
* V_605 = V_12 -> V_26 . V_214 . V_607 ;
return 0 ;
}
static int F_215 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_275 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_608 . V_609 , V_275 , V_276 ) ;
return 0 ;
}
static void F_216 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_217 ( V_9 ) ;
}
static int F_218 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_246 , int V_297 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_610 * V_26 = NULL ;
if ( ! V_9 -> V_183 -> V_611 )
return - V_243 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_612 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_183 -> V_611 ( & V_9 -> V_113 , V_26 , V_246 , V_297 ) ;
}
static int F_219 ( struct V_2 * V_2 ,
struct V_356 * V_357 ,
struct V_613 * V_365 ,
void * V_246 , int V_297 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_183 -> V_614 )
return - V_243 ;
return V_9 -> V_183 -> V_614 ( & V_9 -> V_113 , V_357 , V_365 , V_246 , V_297 ) ;
}
int F_220 ( struct V_11 * V_12 ,
enum V_615 V_319 )
{
struct V_36 * V_23 ;
enum V_615 V_616 ;
int V_142 ;
if ( F_32 ( V_12 -> V_26 . type != V_63 ) )
return - V_47 ;
if ( V_12 -> V_26 . V_214 . V_279 . V_617 == V_618 )
return 0 ;
V_616 = V_12 -> V_15 . V_294 . V_420 ;
V_12 -> V_15 . V_294 . V_420 = V_319 ;
if ( V_616 == V_319 ||
V_319 == V_619 )
return 0 ;
if ( ! F_221 ( & V_12 -> V_15 . V_294 . V_418 ) ) {
V_12 -> V_319 = V_319 ;
F_222 ( & V_12 -> V_9 -> V_113 , & V_12 -> V_620 ) ;
return 0 ;
}
F_150 ( V_12 ,
L_3 ,
V_319 , F_221 ( & V_12 -> V_15 . V_294 . V_418 ) ) ;
F_25 ( & V_12 -> V_9 -> V_56 ) ;
for ( V_142 = 0 ; V_142 < V_621 ; V_142 ++ ) {
for ( V_23 = F_82 ( V_12 -> V_9 -> V_622 [ V_142 ] ,
F_83 ( & V_12 -> V_9 -> V_56 ) ) ;
V_23 ;
V_23 = F_82 ( V_23 -> V_623 ,
F_83 ( & V_12 -> V_9 -> V_56 ) ) ) {
if ( V_23 -> V_12 -> V_417 != & V_12 -> V_15 . V_294 )
continue;
if ( F_149 ( V_23 ) == 1 )
continue;
if ( F_29 ( V_23 , V_624 ) &&
! F_223 ( V_23 -> V_419 ,
V_319 ) ) {
F_150 ( V_12 ,
L_4 ,
V_23 -> V_23 . V_275 ) ;
continue;
}
if ( ! F_29 ( V_23 , V_234 ) )
continue;
F_150 ( V_12 , L_5 , V_23 -> V_23 . V_275 ) ;
F_151 ( V_12 , V_319 ,
V_23 -> V_23 . V_275 ,
V_12 -> V_26 . V_214 . V_254 ) ;
}
}
F_34 ( & V_12 -> V_9 -> V_56 ) ;
V_12 -> V_319 = V_319 ;
F_222 ( & V_12 -> V_9 -> V_113 , & V_12 -> V_620 ) ;
return 0 ;
}
int F_224 ( struct V_11 * V_12 ,
enum V_615 V_319 )
{
const T_3 * V_294 ;
enum V_615 V_616 ;
int V_13 ;
F_225 ( & V_12 -> V_10 . V_281 ) ;
if ( F_32 ( V_12 -> V_26 . type != V_24 ) )
return - V_47 ;
V_616 = V_12 -> V_15 . V_25 . V_420 ;
V_12 -> V_15 . V_25 . V_420 = V_319 ;
if ( V_616 == V_319 &&
V_319 != V_619 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_625 ||
V_12 -> V_26 . V_214 . V_279 . V_617 == V_618 )
return 0 ;
V_294 = V_12 -> V_15 . V_25 . V_625 -> V_254 ;
if ( V_319 == V_619 ) {
if ( V_12 -> V_15 . V_25 . V_626 )
V_319 = V_627 ;
else
V_319 = V_320 ;
}
V_13 = F_151 ( V_12 , V_319 ,
V_294 , V_294 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_420 = V_616 ;
return V_13 ;
}
static int F_226 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_628 , int V_629 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_277 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_243 ;
if ( ! ( V_9 -> V_113 . V_5 & V_630 ) )
return - V_243 ;
if ( V_628 == V_12 -> V_15 . V_25 . V_626 &&
V_629 == V_9 -> V_631 )
return 0 ;
V_12 -> V_15 . V_25 . V_626 = V_628 ;
V_9 -> V_631 = V_629 ;
F_227 ( V_12 ) ;
F_224 ( V_12 , V_12 -> V_15 . V_25 . V_420 ) ;
F_228 ( V_12 ) ;
if ( V_9 -> V_113 . V_5 & V_632 )
F_86 ( V_9 , V_633 ) ;
F_152 ( V_9 , - 1 ) ;
F_153 ( V_12 ) ;
return 0 ;
}
static int F_229 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_634 , T_1 V_635 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_610 * V_26 = & V_12 -> V_26 ;
struct V_636 * V_214 = & V_26 -> V_214 ;
if ( V_634 == V_214 -> V_637 &&
V_635 == V_214 -> V_638 )
return 0 ;
V_214 -> V_637 = V_634 ;
V_214 -> V_638 = V_635 ;
if ( V_12 -> V_15 . V_25 . V_625 &&
V_12 -> V_26 . V_639 & V_640 )
F_98 ( V_12 , V_641 ) ;
return 0 ;
}
static int F_230 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_275 ,
const struct V_642 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_277 ) ;
int V_142 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_41 ;
if ( V_9 -> V_113 . V_5 & V_643 ) {
V_19 = F_231 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_142 = 0 ; V_142 < V_583 ; V_142 ++ ) {
struct V_109 * V_110 = V_2 -> V_114 [ V_142 ] ;
int V_644 ;
V_12 -> V_645 [ V_142 ] = V_27 -> V_362 [ V_142 ] . V_117 ;
memcpy ( V_12 -> V_646 [ V_142 ] , V_27 -> V_362 [ V_142 ] . V_647 ,
sizeof( V_27 -> V_362 [ V_142 ] . V_647 ) ) ;
V_12 -> V_648 [ V_142 ] = false ;
if ( ! V_110 )
continue;
for ( V_644 = 0 ; V_644 < V_649 ; V_644 ++ )
if ( ~ V_12 -> V_646 [ V_142 ] [ V_644 ] ) {
V_12 -> V_648 [ V_142 ] = true ;
break;
}
}
return 0 ;
}
static int F_232 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_249 * V_250 ,
unsigned int V_650 , T_4 * V_81 ,
struct V_356 * V_651 ,
enum V_652 type )
{
struct V_653 * V_654 , * V_655 ;
bool V_656 = false ;
int V_19 ;
F_225 ( & V_9 -> V_281 ) ;
if ( V_9 -> V_283 && ! V_9 -> V_183 -> V_657 )
return - V_243 ;
V_654 = F_89 ( sizeof( * V_654 ) , V_295 ) ;
if ( ! V_654 )
return - V_296 ;
V_654 -> V_258 = V_250 ;
V_654 -> V_650 = V_650 ;
V_654 -> V_658 = V_650 ;
V_654 -> V_659 = V_651 ;
V_654 -> type = type ;
V_654 -> V_660 = ( unsigned long ) V_651 ;
V_654 -> V_12 = V_12 ;
F_233 ( & V_654 -> V_661 , V_662 ) ;
F_234 ( & V_654 -> V_663 ) ;
if ( ! V_651 ) {
V_9 -> V_664 ++ ;
V_654 -> V_81 = V_9 -> V_664 ;
if ( F_68 ( V_654 -> V_81 == 0 ) ) {
V_654 -> V_81 = 1 ;
V_9 -> V_664 ++ ;
}
* V_81 = V_654 -> V_81 ;
} else {
* V_81 = ( unsigned long ) V_651 ;
}
if ( ! F_235 ( & V_9 -> V_665 ) ||
V_9 -> V_666 || V_9 -> V_667 )
goto V_668;
if ( ! V_9 -> V_183 -> V_657 ) {
F_236 ( & V_9 -> V_113 , & V_654 -> V_661 , 0 ) ;
goto V_669;
}
if ( ! V_650 )
V_650 = 10 ;
V_19 = F_237 ( V_9 , V_12 , V_250 , V_650 , type ) ;
if ( V_19 ) {
F_102 ( V_654 ) ;
return V_19 ;
}
V_654 -> V_670 = true ;
goto V_669;
V_668:
F_70 (tmp, &local->roc_list, list) {
if ( V_655 -> V_258 != V_250 || V_655 -> V_12 != V_12 )
continue;
if ( ! V_655 -> V_670 ) {
F_238 ( & V_654 -> V_671 , & V_655 -> V_663 ) ;
V_655 -> V_650 = F_239 ( V_655 -> V_650 , V_654 -> V_650 ) ;
V_655 -> type = F_239 ( V_655 -> type , V_654 -> type ) ;
V_656 = true ;
break;
}
if ( V_9 -> V_183 -> V_657 ) {
unsigned long V_644 = V_165 ;
if ( ! V_655 -> V_672 ) {
F_238 ( & V_654 -> V_671 , & V_655 -> V_663 ) ;
V_656 = true ;
break;
}
if ( F_163 ( V_644 + V_673 ,
V_655 -> V_674 +
F_240 ( V_655 -> V_650 ) ) ) {
int V_675 ;
F_241 ( V_654 ) ;
V_675 = V_654 -> V_650 -
F_58 ( V_655 -> V_674 +
F_240 (
V_655 -> V_650 ) -
V_644 ) ;
if ( V_675 > 0 ) {
F_242 ( & V_654 -> V_671 , & V_655 -> V_671 ) ;
} else {
F_238 ( & V_654 -> V_671 ,
& V_655 -> V_663 ) ;
}
V_656 = true ;
}
} else if ( F_243 ( & V_655 -> V_661 . V_676 ) ) {
unsigned long V_677 ;
F_238 ( & V_654 -> V_671 , & V_655 -> V_663 ) ;
V_656 = true ;
V_677 = V_165 + F_240 ( V_654 -> V_650 ) ;
if ( F_244 ( V_677 , V_655 -> V_661 . V_676 . V_678 ) )
F_245 ( & V_655 -> V_661 . V_676 , V_677 ) ;
else
F_246 ( & V_655 -> V_661 . V_676 ) ;
F_241 ( V_654 ) ;
}
break;
}
V_669:
if ( ! V_656 )
F_238 ( & V_654 -> V_671 , & V_9 -> V_665 ) ;
return 0 ;
}
static int F_247 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_249 * V_258 ,
unsigned int V_650 ,
T_4 * V_81 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_25 ( & V_9 -> V_281 ) ;
V_19 = F_232 ( V_9 , V_12 , V_258 ,
V_650 , V_81 , NULL ,
V_679 ) ;
F_34 ( & V_9 -> V_281 ) ;
return V_19 ;
}
static int F_248 ( struct V_8 * V_9 ,
T_4 V_81 , bool V_680 )
{
struct V_653 * V_654 , * V_655 , * V_681 = NULL ;
int V_19 ;
F_25 ( & V_9 -> V_281 ) ;
F_249 (roc, tmp, &local->roc_list, list) {
struct V_653 * V_682 , * V_683 ;
F_249 (dep, tmp2, &roc->dependents, list) {
if ( ! V_680 && V_682 -> V_81 != V_81 )
continue;
else if ( V_680 && V_682 -> V_660 != V_81 )
continue;
F_250 ( & V_682 -> V_671 ) ;
F_34 ( & V_9 -> V_281 ) ;
F_251 ( V_682 , true ) ;
return 0 ;
}
if ( ! V_680 && V_654 -> V_81 != V_81 )
continue;
else if ( V_680 && V_654 -> V_660 != V_81 )
continue;
V_681 = V_654 ;
break;
}
if ( ! V_681 ) {
F_34 ( & V_9 -> V_281 ) ;
return - V_58 ;
}
if ( V_9 -> V_183 -> V_657 ) {
if ( V_681 -> V_670 ) {
V_19 = F_252 ( V_9 ) ;
if ( F_32 ( V_19 ) ) {
F_34 ( & V_9 -> V_281 ) ;
return V_19 ;
}
}
F_250 ( & V_681 -> V_671 ) ;
if ( V_681 -> V_670 )
F_253 ( V_9 ) ;
F_34 ( & V_9 -> V_281 ) ;
F_251 ( V_681 , true ) ;
} else {
V_681 -> abort = true ;
F_236 ( & V_9 -> V_113 , & V_681 -> V_661 , 0 ) ;
F_34 ( & V_9 -> V_281 ) ;
F_254 ( & V_681 -> V_661 ) ;
F_68 ( ! V_681 -> V_684 ) ;
F_102 ( V_681 ) ;
}
return 0 ;
}
static int F_255 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_81 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_248 ( V_9 , V_81 , false ) ;
}
static int F_256 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_278 * V_279 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
unsigned long V_629 ;
int V_13 ;
F_25 ( & V_9 -> V_281 ) ;
if ( ! F_235 ( & V_9 -> V_665 ) || V_9 -> V_666 ) {
V_13 = - V_30 ;
goto V_59;
}
V_12 -> V_319 = V_320 ;
V_12 -> V_321 = V_9 -> V_322 ;
V_12 -> V_323 = true ;
V_13 = F_85 ( V_12 , V_279 ,
V_324 ) ;
if ( V_13 )
goto V_59;
V_629 = F_240 ( V_685 ) ;
F_236 ( & V_12 -> V_9 -> V_113 ,
& V_12 -> V_349 , V_629 ) ;
V_59:
F_34 ( & V_9 -> V_281 ) ;
return V_13 ;
}
static struct V_299 *
F_257 ( struct V_299 * V_306 )
{
struct V_299 * V_686 ;
T_3 * V_687 ;
int V_297 ;
V_297 = V_306 -> V_308 + V_306 -> V_310 + V_306 -> V_688 +
V_306 -> V_689 + V_306 -> V_690 +
V_306 -> V_311 ;
V_686 = F_89 ( sizeof( * V_686 ) + V_297 , V_295 ) ;
if ( ! V_686 )
return NULL ;
V_687 = ( T_3 * ) ( V_686 + 1 ) ;
if ( V_306 -> V_308 ) {
V_686 -> V_308 = V_306 -> V_308 ;
V_686 -> V_307 = V_687 ;
memcpy ( V_687 , V_306 -> V_307 , V_306 -> V_308 ) ;
V_687 += V_306 -> V_308 ;
}
if ( V_306 -> V_310 ) {
V_686 -> V_310 = V_306 -> V_310 ;
V_686 -> V_309 = V_687 ;
memcpy ( V_687 , V_306 -> V_309 , V_306 -> V_310 ) ;
V_687 += V_306 -> V_310 ;
}
if ( V_306 -> V_688 ) {
V_686 -> V_688 = V_306 -> V_688 ;
V_686 -> V_691 = V_687 ;
memcpy ( V_687 , V_306 -> V_691 , V_306 -> V_688 ) ;
V_687 += V_306 -> V_688 ;
}
if ( V_306 -> V_689 ) {
V_686 -> V_689 = V_306 -> V_689 ;
V_686 -> V_692 = V_687 ;
memcpy ( V_687 , V_306 -> V_692 , V_306 -> V_689 ) ;
V_687 += V_306 -> V_689 ;
}
if ( V_306 -> V_690 ) {
V_686 -> V_690 = V_306 -> V_690 ;
V_686 -> V_693 = V_687 ;
memcpy ( V_687 , V_306 -> V_693 , V_306 -> V_690 ) ;
V_687 += V_306 -> V_690 ;
}
if ( V_306 -> V_311 ) {
V_686 -> V_311 = V_306 -> V_311 ;
V_306 -> V_291 = V_687 ;
memcpy ( V_687 , V_306 -> V_291 , V_306 -> V_311 ) ;
V_687 += V_306 -> V_311 ;
}
return V_686 ;
}
void F_258 ( struct V_694 * V_661 )
{
struct V_11 * V_12 =
F_170 ( V_661 , struct V_11 ,
V_695 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 , V_304 = 0 ;
F_227 ( V_12 ) ;
if ( ! V_12 -> V_26 . V_341 )
goto V_696;
if ( ! F_12 ( V_12 ) )
goto V_696;
V_12 -> V_323 = V_12 -> V_697 ;
F_25 ( & V_9 -> V_281 ) ;
V_13 = F_259 ( V_12 , & V_304 ) ;
F_34 ( & V_9 -> V_281 ) ;
if ( F_68 ( V_13 < 0 ) )
goto V_696;
if ( ! V_9 -> V_283 ) {
V_9 -> V_288 = V_12 -> V_698 ;
F_86 ( V_9 , 0 ) ;
}
F_98 ( V_12 , V_304 ) ;
V_12 -> V_26 . V_341 = false ;
switch ( V_12 -> V_26 . type ) {
case V_63 :
V_13 = F_92 ( V_12 , V_12 -> V_15 . V_294 . V_344 ) ;
if ( V_13 < 0 )
goto V_696;
V_304 |= V_13 ;
F_102 ( V_12 -> V_15 . V_294 . V_344 ) ;
V_12 -> V_15 . V_294 . V_344 = NULL ;
F_98 ( V_12 , V_13 ) ;
break;
case V_65 :
F_260 ( V_12 ) ;
break;
#ifdef F_31
case V_66 :
V_13 = F_261 ( V_12 ) ;
if ( V_13 < 0 )
goto V_696;
break;
#endif
default:
F_68 ( 1 ) ;
goto V_696;
}
F_262 ( & V_12 -> V_9 -> V_113 ,
V_699 ,
V_700 ) ;
F_263 ( V_12 -> V_18 , & V_12 -> V_698 ) ;
V_696:
F_228 ( V_12 ) ;
}
int F_264 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_701 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_247 * V_248 ;
struct V_702 * V_703 ;
struct V_458 T_7 * V_459 ;
int V_13 , V_704 ;
F_225 ( & V_12 -> V_10 . V_281 ) ;
if ( ! F_235 ( & V_9 -> V_665 ) || V_9 -> V_666 )
return - V_30 ;
if ( V_12 -> V_10 . V_348 )
return - V_30 ;
if ( F_81 ( & V_7 -> V_279 ,
& V_12 -> V_26 . V_214 . V_279 ) )
return - V_47 ;
F_40 () ;
V_248 = F_41 ( V_12 -> V_26 . V_248 ) ;
if ( ! V_248 ) {
F_44 () ;
return - V_30 ;
}
V_703 = F_170 ( V_248 , struct V_702 , V_54 ) ;
if ( V_703 -> V_705 > 1 ) {
F_44 () ;
return - V_30 ;
}
V_704 = 0 ;
F_265 (chanctx, &local->chanctx_list, list)
V_704 ++ ;
F_44 () ;
if ( V_704 > 1 )
return - V_30 ;
if ( V_12 -> V_26 . V_341 )
return - V_30 ;
switch ( V_12 -> V_26 . type ) {
case V_63 :
V_12 -> V_706 =
V_7 -> V_707 ;
V_12 -> V_708 = V_7 -> V_709 ;
V_12 -> V_15 . V_294 . V_344 =
F_257 ( & V_7 -> V_710 ) ;
if ( ! V_12 -> V_15 . V_294 . V_344 )
return - V_296 ;
V_13 = F_92 ( V_12 , & V_7 -> V_711 ) ;
if ( V_13 < 0 ) {
F_102 ( V_12 -> V_15 . V_294 . V_344 ) ;
return V_13 ;
}
break;
case V_65 :
if ( ! V_12 -> V_26 . V_214 . V_712 )
return - V_47 ;
if ( V_7 -> V_279 . V_617 != V_12 -> V_15 . V_713 . V_279 . V_617 )
return - V_47 ;
switch ( V_7 -> V_279 . V_617 ) {
case V_714 :
if ( F_266 ( & V_7 -> V_279 ) !=
F_266 ( & V_12 -> V_15 . V_713 . V_279 ) )
return - V_47 ;
case V_715 :
case V_716 :
case V_618 :
case V_717 :
break;
default:
return - V_47 ;
}
if ( V_12 -> V_15 . V_713 . V_279 . V_258 -> V_372 !=
V_7 -> V_279 . V_258 -> V_372 )
return - V_47 ;
V_13 = F_267 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
#ifdef F_31
case V_66 :
V_459 = & V_12 -> V_15 . V_67 ;
if ( ! V_459 -> V_467 )
return - V_47 ;
if ( V_7 -> V_279 . V_617 != V_12 -> V_26 . V_214 . V_279 . V_617 )
return - V_47 ;
if ( V_12 -> V_26 . V_214 . V_279 . V_258 -> V_372 !=
V_7 -> V_279 . V_258 -> V_372 )
return - V_47 ;
V_459 -> V_718 = true ;
if ( ! V_459 -> V_719 )
V_459 -> V_719 = 1 ;
else
V_459 -> V_719 ++ ;
V_13 = F_268 ( V_12 , V_7 , true ) ;
if ( V_13 < 0 ) {
V_459 -> V_718 = false ;
return V_13 ;
}
break;
#endif
default:
return - V_243 ;
}
V_12 -> V_697 = V_7 -> V_323 ;
if ( V_7 -> V_720 )
F_269 ( & V_9 -> V_113 ,
V_699 ,
V_700 ) ;
V_12 -> V_698 = V_7 -> V_279 ;
V_12 -> V_26 . V_341 = true ;
F_98 ( V_12 , V_13 ) ;
F_270 ( V_12 , & V_7 -> V_279 ) ;
return 0 ;
}
static int F_271 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_721 * V_7 ,
T_4 * V_81 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_356 * V_357 ;
struct V_36 * V_23 ;
const struct V_722 * V_723 = ( void * ) V_7 -> V_724 ;
bool V_725 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_7 -> V_726 )
V_5 = V_727 ;
else
V_5 = V_728 |
V_729 ;
if ( V_7 -> V_730 )
V_5 |= V_731 ;
switch ( V_12 -> V_26 . type ) {
case V_65 :
if ( ! V_12 -> V_26 . V_214 . V_712 )
V_725 = true ;
#ifdef F_31
case V_66 :
if ( F_26 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_67 . V_466 )
V_725 = true ;
#endif
case V_63 :
case V_20 :
case V_75 :
if ( V_12 -> V_26 . type != V_65 &&
! F_26 ( & V_12 -> V_26 ) &&
! F_272 ( V_12 -> V_417 -> V_306 ) )
V_725 = true ;
if ( ! F_273 ( V_723 -> V_732 ) ||
V_723 -> V_15 . V_733 . V_734 == V_735 ||
V_723 -> V_15 . V_733 . V_734 == V_736 ||
V_723 -> V_15 . V_733 . V_734 == V_737 )
break;
F_40 () ;
V_23 = F_27 ( V_12 , V_723 -> V_358 ) ;
F_44 () ;
if ( ! V_23 )
return - V_738 ;
break;
case V_24 :
case V_74 :
if ( ! V_12 -> V_15 . V_25 . V_625 )
V_725 = true ;
break;
case V_71 :
V_725 = true ;
break;
default:
return - V_243 ;
}
if ( V_725 && ! V_7 -> V_258 )
return - V_47 ;
F_25 ( & V_9 -> V_281 ) ;
if ( ! V_725 ) {
struct V_247 * V_248 ;
F_40 () ;
V_248 = F_41 ( V_12 -> V_26 . V_248 ) ;
if ( V_248 ) {
V_725 = V_7 -> V_258 &&
( V_7 -> V_258 !=
V_248 -> V_257 . V_258 ) ;
} else if ( ! V_7 -> V_258 ) {
V_19 = - V_47 ;
F_44 () ;
goto V_59;
} else {
V_725 = true ;
}
F_44 () ;
}
if ( V_725 && ! V_7 -> V_739 ) {
V_19 = - V_30 ;
goto V_59;
}
V_357 = F_113 ( V_9 -> V_113 . V_740 + V_7 -> V_297 ) ;
if ( ! V_357 ) {
V_19 = - V_296 ;
goto V_59;
}
F_274 ( V_357 , V_9 -> V_113 . V_740 ) ;
memcpy ( F_114 ( V_357 , V_7 -> V_297 ) , V_7 -> V_724 , V_7 -> V_297 ) ;
F_275 ( V_357 ) -> V_5 = V_5 ;
V_357 -> V_18 = V_12 -> V_18 ;
if ( ! V_725 ) {
* V_81 = ( unsigned long ) V_357 ;
F_276 ( V_12 , V_357 ) ;
V_19 = 0 ;
goto V_59;
}
F_275 ( V_357 ) -> V_5 |= V_741 |
V_742 ;
if ( V_9 -> V_113 . V_5 & V_743 )
F_275 ( V_357 ) -> V_744 =
V_9 -> V_113 . V_745 ;
V_19 = F_232 ( V_9 , V_12 , V_7 -> V_258 ,
V_7 -> V_746 , V_81 , V_357 ,
V_747 ) ;
if ( V_19 )
F_277 ( V_357 ) ;
V_59:
F_34 ( & V_9 -> V_281 ) ;
return V_19 ;
}
static int F_278 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_81 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_248 ( V_9 , V_81 , true ) ;
}
static void F_279 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_748 , bool V_749 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_748 ) {
case V_750 | V_751 :
if ( V_749 )
V_9 -> V_752 ++ ;
else
V_9 -> V_752 -- ;
if ( ! V_9 -> V_286 )
break;
F_222 ( & V_9 -> V_113 , & V_9 -> V_753 ) ;
break;
default:
break;
}
}
static int F_280 ( struct V_2 * V_2 , T_1 V_754 , T_1 V_755 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_670 )
return - V_243 ;
return F_281 ( V_9 , V_754 , V_755 ) ;
}
static int F_282 ( struct V_2 * V_2 , T_1 * V_754 , T_1 * V_755 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_283 ( V_9 , V_754 , V_755 ) ;
}
static int F_284 ( struct V_2 * V_2 , T_1 V_89 , T_1 V_756 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_285 ( V_9 , V_89 , V_756 ) ;
}
static void F_286 ( struct V_2 * V_2 ,
T_1 * V_89 , T_1 * V_757 , T_1 * V_756 , T_1 * V_758 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_287 ( V_9 , V_89 , V_757 , V_756 , V_758 ) ;
}
static int F_288 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_759 * V_246 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_183 -> V_760 )
return - V_243 ;
F_289 ( V_9 , V_12 , V_246 ) ;
return 0 ;
}
static void F_290 ( struct V_356 * V_357 )
{
T_3 * V_687 = ( void * ) F_114 ( V_357 , 7 ) ;
* V_687 ++ = V_761 ;
* V_687 ++ = 5 ;
* V_687 ++ = 0x0 ;
* V_687 ++ = 0x0 ;
* V_687 ++ = 0x0 ;
* V_687 ++ = 0x0 ;
* V_687 ++ = V_762 ;
}
static T_2 F_291 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_763 ;
V_763 = 0 ;
if ( F_53 ( V_12 ) != V_764 )
return V_763 ;
if ( ! ( V_9 -> V_113 . V_5 & V_765 ) )
V_763 |= V_766 ;
if ( ! ( V_9 -> V_113 . V_5 & V_767 ) )
V_763 |= V_768 ;
return V_763 ;
}
static void F_292 ( struct V_356 * V_357 , T_3 * V_769 ,
T_3 * V_770 , T_3 * V_254 )
{
struct V_771 * V_772 ;
V_772 = ( void * ) F_114 ( V_357 , sizeof( struct V_771 ) ) ;
V_772 -> V_773 = V_774 ;
V_772 -> V_465 = sizeof( struct V_771 ) - 2 ;
memcpy ( V_772 -> V_254 , V_254 , V_276 ) ;
memcpy ( V_772 -> V_775 , V_769 , V_276 ) ;
memcpy ( V_772 -> V_776 , V_770 , V_276 ) ;
}
static int
F_293 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_770 , T_3 V_777 , T_3 V_778 ,
T_2 V_779 , struct V_356 * V_357 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_371 V_372 = F_53 ( V_12 ) ;
struct V_780 * V_781 ;
V_781 = ( void * ) F_114 ( V_357 , F_294 ( struct V_780 , V_15 ) ) ;
memcpy ( V_781 -> V_358 , V_770 , V_276 ) ;
memcpy ( V_781 -> V_359 , V_12 -> V_26 . V_275 , V_276 ) ;
V_781 -> V_782 = F_295 ( V_783 ) ;
V_781 -> V_784 = V_785 ;
switch ( V_777 ) {
case V_786 :
V_781 -> V_734 = V_787 ;
V_781 -> V_777 = V_786 ;
F_114 ( V_357 , sizeof( V_781 -> V_15 . V_788 ) ) ;
V_781 -> V_15 . V_788 . V_778 = V_778 ;
V_781 -> V_15 . V_788 . V_789 =
F_296 ( F_291 ( V_12 ) ) ;
F_297 ( V_12 , V_357 , false , V_372 ) ;
F_298 ( V_12 , V_357 , false , V_372 ) ;
F_290 ( V_357 ) ;
break;
case V_790 :
V_781 -> V_734 = V_787 ;
V_781 -> V_777 = V_790 ;
F_114 ( V_357 , sizeof( V_781 -> V_15 . V_791 ) ) ;
V_781 -> V_15 . V_791 . V_779 = F_296 ( V_779 ) ;
V_781 -> V_15 . V_791 . V_778 = V_778 ;
V_781 -> V_15 . V_791 . V_789 =
F_296 ( F_291 ( V_12 ) ) ;
F_297 ( V_12 , V_357 , false , V_372 ) ;
F_298 ( V_12 , V_357 , false , V_372 ) ;
F_290 ( V_357 ) ;
break;
case V_792 :
V_781 -> V_734 = V_787 ;
V_781 -> V_777 = V_792 ;
F_114 ( V_357 , sizeof( V_781 -> V_15 . V_793 ) ) ;
V_781 -> V_15 . V_793 . V_779 = F_296 ( V_779 ) ;
V_781 -> V_15 . V_793 . V_778 = V_778 ;
break;
case V_794 :
V_781 -> V_734 = V_787 ;
V_781 -> V_777 = V_794 ;
F_114 ( V_357 , sizeof( V_781 -> V_15 . V_795 ) ) ;
V_781 -> V_15 . V_795 . V_796 = F_296 ( V_779 ) ;
break;
case V_797 :
V_781 -> V_734 = V_787 ;
V_781 -> V_777 = V_797 ;
F_114 ( V_357 , sizeof( V_781 -> V_15 . V_798 ) ) ;
V_781 -> V_15 . V_798 . V_778 = V_778 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int
F_299 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_770 , T_3 V_777 , T_3 V_778 ,
T_2 V_779 , struct V_356 * V_357 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_371 V_372 = F_53 ( V_12 ) ;
struct V_722 * V_723 ;
V_723 = ( void * ) F_114 ( V_357 , 24 ) ;
memset ( V_723 , 0 , 24 ) ;
memcpy ( V_723 -> V_358 , V_770 , V_276 ) ;
memcpy ( V_723 -> V_359 , V_12 -> V_26 . V_275 , V_276 ) ;
memcpy ( V_723 -> V_254 , V_12 -> V_15 . V_25 . V_254 , V_276 ) ;
V_723 -> V_732 = F_296 ( V_750 |
V_799 ) ;
switch ( V_777 ) {
case V_800 :
F_114 ( V_357 , 1 + sizeof( V_723 -> V_15 . V_733 . V_15 . V_801 ) ) ;
V_723 -> V_15 . V_733 . V_734 = V_735 ;
V_723 -> V_15 . V_733 . V_15 . V_801 . V_777 =
V_800 ;
V_723 -> V_15 . V_733 . V_15 . V_801 . V_778 =
V_778 ;
V_723 -> V_15 . V_733 . V_15 . V_801 . V_789 =
F_296 ( F_291 ( V_12 ) ) ;
F_297 ( V_12 , V_357 , false , V_372 ) ;
F_298 ( V_12 , V_357 , false , V_372 ) ;
F_290 ( V_357 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_300 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_770 , T_3 V_777 , T_3 V_778 ,
T_2 V_779 , const T_3 * V_802 ,
T_5 V_803 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_356 * V_357 = NULL ;
bool V_804 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_805 ) )
return - V_526 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_625 )
return - V_47 ;
F_301 ( V_12 , L_6 ,
V_777 , V_770 ) ;
V_357 = F_113 ( V_9 -> V_113 . V_740 +
F_239 ( sizeof( struct V_722 ) ,
sizeof( struct V_780 ) ) +
50 +
7 +
V_803 +
sizeof( struct V_771 ) ) ;
if ( ! V_357 )
return - V_296 ;
F_274 ( V_357 , V_9 -> V_113 . V_740 ) ;
switch ( V_777 ) {
case V_786 :
case V_790 :
case V_792 :
case V_794 :
case V_797 :
V_19 = F_293 ( V_2 , V_18 , V_770 ,
V_777 , V_778 ,
V_779 , V_357 ) ;
V_804 = false ;
break;
case V_800 :
V_19 = F_299 ( V_2 , V_18 , V_770 , V_777 ,
V_778 , V_779 ,
V_357 ) ;
V_804 = true ;
break;
default:
V_19 = - V_526 ;
break;
}
if ( V_19 < 0 )
goto V_806;
if ( V_803 )
memcpy ( F_114 ( V_357 , V_803 ) , V_802 , V_803 ) ;
switch ( V_777 ) {
case V_786 :
case V_792 :
case V_794 :
case V_797 :
F_292 ( V_357 , V_12 -> V_26 . V_275 , V_770 ,
V_12 -> V_15 . V_25 . V_254 ) ;
break;
case V_790 :
case V_800 :
F_292 ( V_357 , V_770 , V_12 -> V_26 . V_275 ,
V_12 -> V_15 . V_25 . V_254 ) ;
break;
default:
V_19 = - V_526 ;
goto V_806;
}
if ( V_804 ) {
F_276 ( V_12 , V_357 ) ;
return 0 ;
}
switch ( V_777 ) {
case V_786 :
case V_790 :
F_302 ( V_357 , V_807 ) ;
V_357 -> V_808 = 2 ;
break;
default:
F_302 ( V_357 , V_809 ) ;
V_357 -> V_808 = 5 ;
break;
}
F_303 () ;
V_19 = F_304 ( V_357 , V_18 ) ;
F_305 () ;
return V_19 ;
V_806:
F_306 ( V_357 ) ;
return V_19 ;
}
static int F_307 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_770 , enum V_810 V_811 )
{
struct V_36 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_805 ) )
return - V_526 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_47 ;
F_301 ( V_12 , L_7 , V_811 , V_770 ) ;
switch ( V_811 ) {
case V_812 :
F_40 () ;
V_23 = F_27 ( V_12 , V_770 ) ;
if ( ! V_23 ) {
F_44 () ;
return - V_738 ;
}
F_122 ( V_23 , V_813 ) ;
F_44 () ;
break;
case V_814 :
return F_308 ( V_12 , V_770 ) ;
case V_815 :
case V_816 :
case V_817 :
return - V_526 ;
default:
return - V_526 ;
}
return 0 ;
}
static int F_309 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_770 , T_4 * V_81 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_818 * V_819 ;
struct V_356 * V_357 ;
int V_303 = sizeof( * V_819 ) ;
T_8 V_820 ;
bool V_821 ;
struct V_822 * V_823 ;
struct V_36 * V_23 ;
struct V_247 * V_248 ;
enum V_371 V_372 ;
F_40 () ;
V_248 = F_41 ( V_12 -> V_26 . V_248 ) ;
if ( F_68 ( ! V_248 ) ) {
F_44 () ;
return - V_47 ;
}
V_372 = V_248 -> V_257 . V_258 -> V_372 ;
V_23 = F_28 ( V_12 , V_770 ) ;
if ( V_23 ) {
V_821 = F_29 ( V_23 , V_236 ) ;
} else {
F_44 () ;
return - V_738 ;
}
if ( V_821 ) {
V_820 = F_296 ( V_824 |
V_825 |
V_826 ) ;
} else {
V_303 -= 2 ;
V_820 = F_296 ( V_824 |
V_827 |
V_826 ) ;
}
V_357 = F_113 ( V_9 -> V_113 . V_740 + V_303 ) ;
if ( ! V_357 ) {
F_44 () ;
return - V_296 ;
}
V_357 -> V_18 = V_18 ;
F_274 ( V_357 , V_9 -> V_113 . V_740 ) ;
V_819 = ( void * ) F_114 ( V_357 , V_303 ) ;
V_819 -> V_732 = V_820 ;
V_819 -> V_828 = 0 ;
memcpy ( V_819 -> V_829 , V_23 -> V_23 . V_275 , V_276 ) ;
memcpy ( V_819 -> V_830 , V_12 -> V_26 . V_275 , V_276 ) ;
memcpy ( V_819 -> V_831 , V_12 -> V_26 . V_275 , V_276 ) ;
V_819 -> V_832 = 0 ;
V_823 = F_275 ( V_357 ) ;
V_823 -> V_5 |= V_729 |
V_728 ;
F_302 ( V_357 , V_833 ) ;
V_357 -> V_808 = 7 ;
if ( V_821 )
V_819 -> V_834 = F_296 ( 7 ) ;
F_303 () ;
F_310 ( V_12 , V_357 , V_372 ) ;
F_305 () ;
F_44 () ;
* V_81 = ( unsigned long ) V_357 ;
return 0 ;
}
static int F_311 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_278 * V_279 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_247 * V_248 ;
int V_19 = - V_835 ;
F_40 () ;
V_248 = F_41 ( V_12 -> V_26 . V_248 ) ;
if ( V_248 ) {
* V_279 = V_248 -> V_257 ;
V_19 = 0 ;
} else if ( V_9 -> V_286 > 0 &&
V_9 -> V_286 == V_9 -> V_287 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_283 )
* V_279 = V_9 -> V_280 ;
else
* V_279 = V_9 -> V_288 ;
V_19 = 0 ;
}
F_44 () ;
return V_19 ;
}
static void F_312 ( struct V_2 * V_2 , bool V_628 )
{
F_313 ( F_2 ( V_2 ) , V_628 ) ;
}
static int F_314 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_836 * V_837 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_838 * V_839 , * V_840 ;
if ( V_837 ) {
V_839 = F_89 ( sizeof( * V_839 ) , V_295 ) ;
if ( ! V_839 )
return - V_296 ;
memcpy ( & V_839 -> V_837 , V_837 , sizeof( * V_837 ) ) ;
} else {
V_839 = NULL ;
}
V_840 = F_88 ( V_12 -> V_837 , V_12 ) ;
F_90 ( V_12 -> V_837 , V_839 ) ;
if ( V_840 )
F_91 ( V_840 , V_298 ) ;
return 0 ;
}
