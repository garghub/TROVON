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
struct V_36 * V_23 = NULL ;
struct V_37 * V_38 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_39 ;
switch ( V_7 -> V_40 ) {
case V_41 :
case V_42 :
case V_43 :
if ( F_21 ( V_12 -> V_9 -> V_44 ) )
return - V_45 ;
break;
default:
break;
}
V_38 = F_22 ( V_7 -> V_40 , V_32 , V_7 -> V_46 ,
V_7 -> V_38 , V_7 -> V_47 , V_7 -> V_48 ) ;
if ( F_21 ( V_38 ) )
return F_23 ( V_38 ) ;
if ( V_33 )
V_38 -> V_49 . V_5 |= V_50 ;
F_24 ( & V_12 -> V_9 -> V_51 ) ;
if ( V_34 ) {
if ( F_25 ( & V_12 -> V_26 ) )
V_23 = F_26 ( V_12 , V_34 ) ;
else
V_23 = F_27 ( V_12 , V_34 ) ;
if ( ! V_23 || ! F_28 ( V_23 , V_52 ) ) {
F_29 ( V_38 ) ;
V_13 = - V_53 ;
goto V_54;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_55 != V_56 )
V_38 -> V_49 . V_5 |= V_57 ;
break;
case V_58 :
case V_20 :
if ( V_38 -> V_23 && F_28 ( V_38 -> V_23 , V_59 ) )
V_38 -> V_49 . V_5 |= V_57 ;
break;
case V_60 :
break;
case V_61 :
#ifdef F_30
if ( V_12 -> V_15 . V_62 . V_63 != V_64 )
V_38 -> V_49 . V_5 |= V_57 ;
break;
#endif
case V_65 :
case V_14 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
F_31 ( 1 ) ;
break;
}
V_13 = F_32 ( V_38 , V_12 , V_23 ) ;
V_54:
F_33 ( & V_12 -> V_9 -> V_51 ) ;
return V_13 ;
}
static int F_34 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
struct V_37 * V_38 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_51 ) ;
F_24 ( & V_9 -> V_71 ) ;
if ( V_34 ) {
V_19 = - V_53 ;
V_23 = F_27 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_54;
if ( V_33 )
V_38 = F_35 ( V_9 , V_23 -> V_72 ) ;
else
V_38 = F_35 ( V_9 , V_23 -> V_73 [ V_32 ] ) ;
} else
V_38 = F_35 ( V_9 , V_12 -> V_74 [ V_32 ] ) ;
if ( ! V_38 ) {
V_19 = - V_53 ;
goto V_54;
}
F_36 ( V_38 , true ) ;
V_19 = 0 ;
V_54:
F_33 ( & V_9 -> V_71 ) ;
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_32 , bool V_33 , const T_3 * V_34 ,
void * V_75 ,
void (* F_38)( void * V_75 ,
struct V_35 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_36 * V_23 = NULL ;
T_3 V_48 [ 6 ] = { 0 } ;
struct V_35 V_7 ;
struct V_37 * V_38 = NULL ;
T_4 V_76 ;
T_1 V_77 ;
T_2 V_78 ;
int V_13 = - V_53 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
if ( V_34 ) {
V_23 = F_27 ( V_12 , V_34 ) ;
if ( ! V_23 )
goto V_79;
if ( V_33 )
V_38 = F_40 ( V_23 -> V_72 ) ;
else if ( V_32 < V_80 )
V_38 = F_40 ( V_23 -> V_73 [ V_32 ] ) ;
} else
V_38 = F_40 ( V_12 -> V_74 [ V_32 ] ) ;
if ( ! V_38 )
goto V_79;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_40 = V_38 -> V_49 . V_40 ;
switch ( V_38 -> V_49 . V_40 ) {
case V_42 :
V_77 = V_38 -> V_15 . V_81 . V_82 . V_77 ;
V_78 = V_38 -> V_15 . V_81 . V_82 . V_78 ;
if ( V_38 -> V_5 & V_83 )
F_41 ( V_12 -> V_9 ,
V_38 -> V_49 . V_84 ,
& V_77 , & V_78 ) ;
V_48 [ 0 ] = V_78 & 0xff ;
V_48 [ 1 ] = ( V_78 >> 8 ) & 0xff ;
V_48 [ 2 ] = V_77 & 0xff ;
V_48 [ 3 ] = ( V_77 >> 8 ) & 0xff ;
V_48 [ 4 ] = ( V_77 >> 16 ) & 0xff ;
V_48 [ 5 ] = ( V_77 >> 24 ) & 0xff ;
V_7 . V_48 = V_48 ;
V_7 . V_47 = 6 ;
break;
case V_85 :
V_76 = F_42 ( & V_38 -> V_15 . V_86 . V_87 ) ;
V_48 [ 0 ] = V_76 ;
V_48 [ 1 ] = V_76 >> 8 ;
V_48 [ 2 ] = V_76 >> 16 ;
V_48 [ 3 ] = V_76 >> 24 ;
V_48 [ 4 ] = V_76 >> 32 ;
V_48 [ 5 ] = V_76 >> 40 ;
V_7 . V_48 = V_48 ;
V_7 . V_47 = 6 ;
break;
case V_88 :
V_76 = F_42 ( & V_38 -> V_15 . V_89 . V_87 ) ;
V_48 [ 0 ] = V_76 ;
V_48 [ 1 ] = V_76 >> 8 ;
V_48 [ 2 ] = V_76 >> 16 ;
V_48 [ 3 ] = V_76 >> 24 ;
V_48 [ 4 ] = V_76 >> 32 ;
V_48 [ 5 ] = V_76 >> 40 ;
V_7 . V_48 = V_48 ;
V_7 . V_47 = 6 ;
break;
}
V_7 . V_38 = V_38 -> V_49 . V_38 ;
V_7 . V_46 = V_38 -> V_49 . V_90 ;
F_38 ( V_75 , & V_7 ) ;
V_13 = 0 ;
V_79:
F_43 () ;
return V_13 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 , bool V_91 ,
bool V_92 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_45 ( V_12 , V_32 , V_91 , V_92 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_32 ) ;
return 0 ;
}
void F_48 ( struct V_36 * V_23 ,
const struct V_93 * V_94 ,
struct V_95 * V_96 )
{
V_96 -> V_5 = 0 ;
if ( V_94 -> V_5 & V_97 ) {
V_96 -> V_5 |= V_98 ;
V_96 -> V_99 = V_94 -> V_100 ;
} else if ( V_94 -> V_5 & V_101 ) {
V_96 -> V_5 |= V_102 ;
V_96 -> V_99 = F_49 ( V_94 ) ;
V_96 -> V_103 = F_50 ( V_94 ) ;
} else {
struct V_104 * V_105 ;
V_105 = V_23 -> V_9 -> V_106 . V_2 -> V_107 [
F_51 ( V_23 -> V_12 ) ] ;
V_96 -> V_108 = V_105 -> V_109 [ V_94 -> V_100 ] . V_110 ;
}
if ( V_94 -> V_5 & V_111 )
V_96 -> V_5 |= V_112 ;
if ( V_94 -> V_5 & V_113 )
V_96 -> V_5 |= V_114 ;
if ( V_94 -> V_5 & V_115 )
V_96 -> V_5 |= V_116 ;
if ( V_94 -> V_5 & V_117 )
V_96 -> V_5 |= V_118 ;
}
void F_52 ( struct V_36 * V_23 , struct V_95 * V_96 )
{
V_96 -> V_5 = 0 ;
if ( V_23 -> V_119 & V_120 ) {
V_96 -> V_5 |= V_98 ;
V_96 -> V_99 = V_23 -> V_121 ;
} else if ( V_23 -> V_119 & V_122 ) {
V_96 -> V_5 |= V_102 ;
V_96 -> V_103 = V_23 -> V_123 ;
V_96 -> V_99 = V_23 -> V_121 ;
} else {
struct V_104 * V_105 ;
V_105 = V_23 -> V_9 -> V_106 . V_2 -> V_107 [
F_51 ( V_23 -> V_12 ) ] ;
V_96 -> V_108 =
V_105 -> V_109 [ V_23 -> V_121 ] . V_110 ;
}
if ( V_23 -> V_119 & V_124 )
V_96 -> V_5 |= V_112 ;
if ( V_23 -> V_119 & V_125 )
V_96 -> V_5 |= V_118 ;
if ( V_23 -> V_119 & V_126 )
V_96 -> V_5 |= V_114 ;
if ( V_23 -> V_119 & V_127 )
V_96 -> V_5 |= V_128 ;
if ( V_23 -> V_119 & V_129 )
V_96 -> V_5 |= V_116 ;
}
static void F_53 ( struct V_36 * V_23 , struct V_130 * V_131 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_132 V_133 ;
T_4 V_134 = 0 ;
int V_135 , V_136 ;
V_131 -> V_137 = V_12 -> V_9 -> V_138 ;
V_131 -> V_139 = V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 |
V_150 |
V_151 |
V_152 |
V_153 ;
F_54 ( & V_133 ) ;
V_131 -> V_154 = V_133 . V_155 - V_23 -> V_156 ;
V_131 -> V_157 = F_55 ( V_158 - V_23 -> V_159 ) ;
V_131 -> V_160 = 0 ;
for ( V_136 = 0 ; V_136 < V_161 ; V_136 ++ ) {
V_131 -> V_160 += V_23 -> V_160 [ V_136 ] ;
V_134 += V_23 -> V_162 [ V_136 ] ;
}
V_131 -> V_162 = V_134 ;
V_131 -> V_163 = V_23 -> V_163 ;
V_131 -> V_164 = V_23 -> V_164 ;
V_131 -> V_165 = V_23 -> V_166 ;
V_131 -> V_167 = V_23 -> V_168 ;
V_131 -> V_169 = V_23 -> V_170 ;
V_131 -> V_171 = V_23 -> V_171 ;
if ( ( V_23 -> V_9 -> V_106 . V_5 & V_172 ) ||
( V_23 -> V_9 -> V_106 . V_5 & V_173 ) ) {
V_131 -> V_139 |= V_174 | V_175 ;
if ( ! V_9 -> V_176 -> V_177 ||
F_56 ( V_9 , V_12 , & V_23 -> V_23 , & V_131 -> signal ) )
V_131 -> signal = ( V_178 ) V_23 -> V_179 ;
V_131 -> V_180 = ( V_178 ) - F_57 ( & V_23 -> V_181 ) ;
}
if ( V_23 -> V_182 ) {
V_131 -> V_139 |= V_183 |
V_184 ;
V_131 -> V_182 = V_23 -> V_182 ;
for ( V_135 = 0 ; V_135 < F_58 ( V_131 -> V_185 ) ; V_135 ++ ) {
V_131 -> V_185 [ V_135 ] = V_23 -> V_186 [ V_135 ] ;
V_131 -> V_187 [ V_135 ] =
( V_178 ) - F_57 ( & V_23 -> V_187 [ V_135 ] ) ;
}
}
F_48 ( V_23 , & V_23 -> V_188 , & V_131 -> V_189 ) ;
F_52 ( V_23 , & V_131 -> V_190 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
V_131 -> V_139 |= V_191 |
V_192 |
V_193 |
V_194 |
V_195 |
V_196 ;
V_131 -> V_197 = F_59 ( V_23 -> V_197 ) ;
V_131 -> V_198 = F_59 ( V_23 -> V_198 ) ;
V_131 -> V_199 = V_23 -> V_199 ;
if ( F_28 ( V_23 , V_200 ) ) {
V_131 -> V_139 |= V_201 ;
V_131 -> V_202 = V_23 -> V_202 ;
}
V_131 -> V_203 = V_23 -> V_203 ;
V_131 -> V_204 = V_23 -> V_204 ;
V_131 -> V_205 = V_23 -> V_205 ;
#endif
}
V_131 -> V_206 . V_5 = 0 ;
if ( V_12 -> V_26 . V_207 . V_208 )
V_131 -> V_206 . V_5 |= V_209 ;
if ( V_12 -> V_26 . V_207 . V_210 )
V_131 -> V_206 . V_5 |= V_211 ;
if ( V_12 -> V_26 . V_207 . V_212 )
V_131 -> V_206 . V_5 |= V_213 ;
V_131 -> V_206 . V_214 = V_12 -> V_9 -> V_106 . V_49 . V_215 ;
V_131 -> V_206 . V_216 = V_12 -> V_26 . V_207 . V_217 ;
V_131 -> V_218 . V_219 = 0 ;
V_131 -> V_218 . V_27 = F_60 ( V_220 ) |
F_60 ( V_221 ) |
F_60 ( V_222 ) |
F_60 ( V_223 ) |
F_60 ( V_224 ) |
F_60 ( V_225 ) |
F_60 ( V_226 ) ;
if ( F_28 ( V_23 , V_227 ) )
V_131 -> V_218 . V_219 |= F_60 ( V_220 ) ;
if ( F_28 ( V_23 , V_228 ) )
V_131 -> V_218 . V_219 |= F_60 ( V_221 ) ;
if ( F_28 ( V_23 , V_229 ) )
V_131 -> V_218 . V_219 |= F_60 ( V_222 ) ;
if ( F_28 ( V_23 , V_59 ) )
V_131 -> V_218 . V_219 |= F_60 ( V_223 ) ;
if ( F_28 ( V_23 , V_230 ) )
V_131 -> V_218 . V_219 |= F_60 ( V_224 ) ;
if ( F_28 ( V_23 , V_52 ) )
V_131 -> V_218 . V_219 |= F_60 ( V_225 ) ;
if ( F_28 ( V_23 , V_231 ) )
V_131 -> V_218 . V_219 |= F_60 ( V_226 ) ;
}
static int F_61 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_232 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_233 = 0 ;
if ( V_232 == V_234 )
V_233 += V_235 ;
V_233 += F_62 ( V_12 , V_232 ) ;
if ( V_233 == 0 )
return - V_236 ;
return V_233 ;
}
static void F_63 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_237 * V_238 ,
T_4 * V_239 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_240 * V_241 ;
struct V_242 * V_243 ;
struct V_36 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_130 V_131 ;
struct V_244 V_245 ;
int V_135 , V_246 ;
#define F_64 7
memset ( V_239 , 0 , sizeof( T_4 ) * V_235 ) ;
#define F_65 ( V_23 ) \
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
F_24 ( & V_9 -> V_51 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_27 ( V_12 , V_12 -> V_15 . V_25 . V_247 ) ;
if ( ! ( V_23 && ! F_66 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_248;
V_131 . V_139 = 0 ;
F_53 ( V_23 , & V_131 ) ;
V_135 = 0 ;
F_65 ( V_23 ) ;
V_239 [ V_135 ++ ] = V_23 -> V_249 ;
if ( V_131 . V_139 & V_147 )
V_239 [ V_135 ] = 100000 *
F_67 ( & V_131 . V_189 ) ;
V_135 ++ ;
if ( V_131 . V_139 & V_148 )
V_239 [ V_135 ] = 100000 *
F_67 ( & V_131 . V_190 ) ;
V_135 ++ ;
if ( V_131 . V_139 & V_175 )
V_239 [ V_135 ] = ( T_3 ) V_131 . V_180 ;
V_135 ++ ;
} else {
F_68 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_131 . V_139 = 0 ;
F_53 ( V_23 , & V_131 ) ;
V_135 = 0 ;
F_65 ( V_23 ) ;
}
}
V_248:
V_135 = V_235 - F_64 ;
V_245 . V_139 = 0 ;
F_39 () ;
V_241 = F_40 ( V_12 -> V_26 . V_241 ) ;
if ( V_241 )
V_243 = V_241 -> V_250 . V_251 ;
else
V_243 = NULL ;
F_43 () ;
if ( V_243 ) {
V_246 = 0 ;
do {
V_245 . V_139 = 0 ;
if ( F_69 ( V_9 , V_246 , & V_245 ) != 0 ) {
V_245 . V_139 = 0 ;
break;
}
V_246 ++ ;
} while ( V_243 != V_245 . V_243 );
}
if ( V_245 . V_139 )
V_239 [ V_135 ++ ] = V_245 . V_243 -> V_252 ;
else
V_239 [ V_135 ++ ] = 0 ;
if ( V_245 . V_139 & V_253 )
V_239 [ V_135 ++ ] = ( T_3 ) V_245 . V_254 ;
else
V_239 [ V_135 ++ ] = - 1LL ;
if ( V_245 . V_139 & V_255 )
V_239 [ V_135 ++ ] = V_245 . V_256 ;
else
V_239 [ V_135 ++ ] = - 1LL ;
if ( V_245 . V_139 & V_257 )
V_239 [ V_135 ++ ] = V_245 . V_258 ;
else
V_239 [ V_135 ++ ] = - 1LL ;
if ( V_245 . V_139 & V_259 )
V_239 [ V_135 ++ ] = V_245 . V_260 ;
else
V_239 [ V_135 ++ ] = - 1LL ;
if ( V_245 . V_139 & V_261 )
V_239 [ V_135 ++ ] = V_245 . V_262 ;
else
V_239 [ V_135 ++ ] = - 1LL ;
if ( V_245 . V_139 & V_263 )
V_239 [ V_135 ++ ] = V_245 . V_264 ;
else
V_239 [ V_135 ++ ] = - 1LL ;
F_33 ( & V_9 -> V_51 ) ;
if ( F_66 ( V_135 != V_235 ) )
return;
F_70 ( V_12 , V_238 , & ( V_239 [ V_235 ] ) ) ;
}
static void F_71 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_232 , T_3 * V_239 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_265 = 0 ;
if ( V_232 == V_234 ) {
V_265 = sizeof( V_266 ) ;
memcpy ( V_239 , V_266 , V_265 ) ;
}
F_72 ( V_12 , V_232 , & ( V_239 [ V_265 ] ) ) ;
}
static int F_73 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , T_3 * V_267 , struct V_130 * V_131 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_53 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_74 ( V_12 , V_100 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_267 , V_23 -> V_23 . V_268 , V_269 ) ;
F_53 ( V_23 , V_131 ) ;
}
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_75 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , struct V_244 * V_245 )
{
struct V_8 * V_9 = F_76 ( V_18 -> V_270 ) ;
return F_69 ( V_9 , V_100 , V_245 ) ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_267 , struct V_130 * V_131 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_53 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_27 ( V_12 , V_267 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_53 ( V_23 , V_131 ) ;
}
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_78 ( struct V_2 * V_2 ,
struct V_271 * V_272 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_79 ( & V_9 -> V_273 , V_272 ) )
return 0 ;
F_24 ( & V_9 -> V_274 ) ;
if ( V_9 -> V_275 ) {
V_12 = F_80 (
V_9 -> V_276 ,
F_81 ( & V_9 -> V_274 ) ) ;
if ( V_12 ) {
F_82 ( V_12 ) ;
V_19 = F_83 ( V_12 , V_272 ,
V_277 ) ;
}
} else if ( V_9 -> V_278 == V_9 -> V_279 ) {
V_9 -> V_280 = * V_272 ;
F_84 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_273 = * V_272 ;
F_33 ( & V_9 -> V_274 ) ;
return V_19 ;
}
static int F_85 ( struct V_11 * V_12 ,
const T_3 * V_281 , T_5 V_282 )
{
struct V_283 * V_284 , * V_285 ;
if ( ! V_281 || ! V_282 )
return 1 ;
V_285 = F_86 ( V_12 -> V_15 . V_286 . V_283 ) ;
V_284 = F_87 ( sizeof( struct V_283 ) + V_282 , V_287 ) ;
if ( ! V_284 )
return - V_288 ;
V_284 -> V_289 = V_282 ;
memcpy ( V_284 -> V_239 , V_281 , V_282 ) ;
F_88 ( V_12 -> V_15 . V_286 . V_283 , V_284 ) ;
if ( V_285 )
F_89 ( V_285 , V_290 ) ;
return 0 ;
}
static int F_90 ( struct V_11 * V_12 ,
struct V_291 * V_7 )
{
struct V_292 * V_284 , * V_285 ;
int V_293 , V_294 ;
int V_295 , V_13 ;
T_1 V_296 = V_297 ;
V_285 = F_86 ( V_12 -> V_15 . V_286 . V_298 ) ;
if ( ! V_7 -> V_299 && ! V_285 )
return - V_45 ;
if ( V_7 -> V_299 )
V_293 = V_7 -> V_300 ;
else
V_293 = V_285 -> V_300 ;
if ( V_7 -> V_301 || ! V_285 )
V_294 = V_7 -> V_302 ;
else
V_294 = V_285 -> V_302 ;
V_295 = sizeof( * V_284 ) + V_293 + V_294 ;
V_284 = F_87 ( V_295 , V_287 ) ;
if ( ! V_284 )
return - V_288 ;
V_284 -> V_299 = ( ( T_3 * ) V_284 ) + sizeof( * V_284 ) ;
V_284 -> V_301 = V_284 -> V_299 + V_293 ;
V_284 -> V_300 = V_293 ;
V_284 -> V_302 = V_294 ;
if ( V_7 -> V_299 )
memcpy ( V_284 -> V_299 , V_7 -> V_299 , V_293 ) ;
else
memcpy ( V_284 -> V_299 , V_285 -> V_299 , V_293 ) ;
if ( V_7 -> V_301 )
memcpy ( V_284 -> V_301 , V_7 -> V_301 , V_294 ) ;
else
if ( V_285 )
memcpy ( V_284 -> V_301 , V_285 -> V_301 , V_294 ) ;
V_13 = F_85 ( V_12 , V_7 -> V_283 ,
V_7 -> V_303 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_296 |= V_304 ;
F_88 ( V_12 -> V_15 . V_286 . V_298 , V_284 ) ;
if ( V_285 )
F_89 ( V_285 , V_290 ) ;
return V_296 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_305 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_292 * V_285 ;
struct V_11 * V_22 ;
T_1 V_296 = V_306 |
V_307 |
V_297 |
V_308 |
V_309 ;
int V_13 ;
V_285 = F_86 ( V_12 -> V_15 . V_286 . V_298 ) ;
if ( V_285 )
return - V_310 ;
V_12 -> V_311 = V_312 ;
V_12 -> V_313 = V_12 -> V_9 -> V_314 ;
V_12 -> V_315 = V_7 -> V_315 ;
V_13 = F_83 ( V_12 , & V_7 -> V_272 ,
V_316 ) ;
if ( V_13 )
return V_13 ;
F_92 ( V_12 , false ) ;
V_12 -> V_317 = V_7 -> V_318 . V_319 ;
V_12 -> V_320 = V_7 -> V_318 . V_320 ;
F_68 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_317 =
V_7 -> V_318 . V_319 ;
V_22 -> V_320 =
V_7 -> V_318 . V_320 ;
}
V_12 -> V_26 . V_207 . V_217 = V_7 -> V_216 ;
V_12 -> V_26 . V_207 . V_214 = V_7 -> V_214 ;
V_12 -> V_26 . V_207 . V_321 = true ;
V_12 -> V_26 . V_207 . V_322 = V_7 -> V_322 ;
if ( V_7 -> V_322 )
memcpy ( V_12 -> V_26 . V_207 . V_323 , V_7 -> V_323 ,
V_7 -> V_322 ) ;
V_12 -> V_26 . V_207 . V_324 =
( V_7 -> V_324 != V_325 ) ;
memset ( & V_12 -> V_26 . V_207 . V_326 , 0 ,
sizeof( V_12 -> V_26 . V_207 . V_326 ) ) ;
V_12 -> V_26 . V_207 . V_326 . V_327 =
V_7 -> V_328 & V_329 ;
if ( V_7 -> V_330 )
V_12 -> V_26 . V_207 . V_326 . V_327 |=
V_331 ;
V_13 = F_90 ( V_12 , & V_7 -> V_298 ) ;
if ( V_13 < 0 )
return V_13 ;
V_296 |= V_13 ;
V_13 = F_93 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_285 = F_86 ( V_12 -> V_15 . V_286 . V_298 ) ;
if ( V_285 )
F_89 ( V_285 , V_290 ) ;
F_11 ( V_12 -> V_15 . V_286 . V_298 , NULL ) ;
return V_13 ;
}
F_94 ( V_12 , V_296 ) ;
F_95 ( V_18 ) ;
F_68 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_95 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_291 * V_7 )
{
struct V_11 * V_12 ;
struct V_292 * V_285 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
V_285 = F_86 ( V_12 -> V_15 . V_286 . V_298 ) ;
if ( ! V_285 )
return - V_53 ;
V_13 = F_90 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_94 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_97 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_292 * V_332 ;
struct V_283 * V_333 ;
V_332 = F_86 ( V_12 -> V_15 . V_286 . V_298 ) ;
if ( ! V_332 )
return - V_53 ;
V_333 = F_86 ( V_12 -> V_15 . V_286 . V_283 ) ;
F_68 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_98 ( V_22 -> V_18 ) ;
F_98 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_286 . V_298 , NULL ) ;
F_11 ( V_12 -> V_15 . V_286 . V_283 , NULL ) ;
F_89 ( V_332 , V_290 ) ;
if ( V_333 )
F_89 ( V_333 , V_290 ) ;
F_68 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_99 ( V_22 ) ;
F_99 ( V_12 ) ;
F_100 () ;
F_101 () ;
F_68 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
F_102 ( V_22 ) ;
F_103 ( V_22 ) ;
}
F_102 ( V_12 ) ;
F_103 ( V_12 ) ;
V_12 -> V_26 . V_207 . V_321 = false ;
V_12 -> V_26 . V_207 . V_322 = 0 ;
F_104 ( V_334 , & V_12 -> V_335 ) ;
F_94 ( V_12 , V_307 ) ;
if ( V_12 -> V_10 . V_336 ) {
F_105 ( & V_12 -> V_337 ) ;
F_106 ( V_12 -> V_18 , V_338 ,
V_287 ) ;
}
F_107 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_339 -= F_108 ( & V_12 -> V_15 . V_286 . V_340 . V_341 ) ;
F_109 ( & V_12 -> V_15 . V_286 . V_340 . V_341 ) ;
F_92 ( V_12 , true ) ;
F_82 ( V_12 ) ;
return 0 ;
}
static void F_110 ( struct V_36 * V_23 )
{
struct V_342 * V_343 ;
struct V_344 * V_345 ;
V_345 = F_111 ( sizeof( * V_343 ) ) ;
if ( ! V_345 )
return;
V_343 = (struct V_342 * ) F_112 ( V_345 , sizeof( * V_343 ) ) ;
F_113 ( V_343 -> V_346 ) ;
memcpy ( V_343 -> V_347 , V_23 -> V_23 . V_268 , V_269 ) ;
V_343 -> V_289 = F_114 ( 6 ) ;
V_343 -> V_348 = 0 ;
V_343 -> V_349 = 0x01 ;
V_343 -> V_350 = 0xaf ;
V_343 -> V_351 [ 0 ] = 0x81 ;
V_343 -> V_351 [ 1 ] = 1 ;
V_343 -> V_351 [ 2 ] = 0 ;
V_345 -> V_18 = V_23 -> V_12 -> V_18 ;
V_345 -> V_352 = F_115 ( V_345 , V_23 -> V_12 -> V_18 ) ;
memset ( V_345 -> V_353 , 0 , sizeof( V_345 -> V_353 ) ) ;
F_116 ( V_345 ) ;
}
static int F_117 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
T_1 V_27 , T_1 V_219 )
{
int V_19 ;
if ( V_27 & F_60 ( V_224 ) &&
V_219 & F_60 ( V_224 ) &&
! F_28 ( V_23 , V_230 ) ) {
V_19 = F_118 ( V_23 , V_354 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_60 ( V_225 ) &&
V_219 & F_60 ( V_225 ) &&
! F_28 ( V_23 , V_52 ) ) {
V_19 = F_118 ( V_23 , V_355 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_60 ( V_220 ) ) {
if ( V_219 & F_60 ( V_220 ) )
V_19 = F_118 ( V_23 , V_356 ) ;
else if ( F_28 ( V_23 , V_227 ) )
V_19 = F_118 ( V_23 , V_355 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_60 ( V_225 ) &&
! ( V_219 & F_60 ( V_225 ) ) &&
F_28 ( V_23 , V_52 ) ) {
V_19 = F_118 ( V_23 , V_354 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_60 ( V_224 ) &&
! ( V_219 & F_60 ( V_224 ) ) &&
F_28 ( V_23 , V_230 ) ) {
V_19 = F_118 ( V_23 , V_357 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_119 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
struct V_358 * V_7 )
{
int V_19 = 0 ;
T_1 V_359 ;
int V_135 , V_360 ;
struct V_104 * V_105 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_361 V_362 = F_51 ( V_12 ) ;
T_1 V_27 , V_219 ;
V_105 = V_9 -> V_106 . V_2 -> V_107 [ V_362 ] ;
V_27 = V_7 -> V_363 ;
V_219 = V_7 -> V_364 ;
if ( F_25 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_60 ( V_224 ) )
V_27 |= F_60 ( V_225 ) ;
if ( V_219 & F_60 ( V_224 ) )
V_219 |= F_60 ( V_225 ) ;
} else if ( F_28 ( V_23 , V_231 ) ) {
if ( V_219 & F_60 ( V_220 ) ) {
V_219 |= F_60 ( V_224 ) |
F_60 ( V_225 ) ;
V_27 |= F_60 ( V_224 ) |
F_60 ( V_225 ) ;
}
}
V_19 = F_117 ( V_9 , V_23 , V_27 , V_219 ) ;
if ( V_19 )
return V_19 ;
if ( V_27 & F_60 ( V_221 ) ) {
if ( V_219 & F_60 ( V_221 ) )
F_120 ( V_23 , V_228 ) ;
else
F_121 ( V_23 , V_228 ) ;
}
if ( V_27 & F_60 ( V_222 ) ) {
if ( V_219 & F_60 ( V_222 ) ) {
F_120 ( V_23 , V_229 ) ;
V_23 -> V_23 . V_365 = true ;
} else {
F_121 ( V_23 , V_229 ) ;
V_23 -> V_23 . V_365 = false ;
}
}
if ( V_27 & F_60 ( V_223 ) ) {
if ( V_219 & F_60 ( V_223 ) )
F_120 ( V_23 , V_59 ) ;
else
F_121 ( V_23 , V_59 ) ;
}
if ( V_27 & F_60 ( V_226 ) ) {
if ( V_219 & F_60 ( V_226 ) )
F_120 ( V_23 , V_231 ) ;
else
F_121 ( V_23 , V_231 ) ;
}
if ( V_7 -> V_366 & V_367 ) {
V_23 -> V_23 . V_368 = V_7 -> V_368 ;
V_23 -> V_23 . V_369 = V_7 -> V_369 ;
}
if ( V_7 -> V_370 )
V_23 -> V_23 . V_370 = V_7 -> V_370 ;
if ( V_7 -> V_371 >= 0 )
V_23 -> V_371 = V_7 -> V_371 ;
if ( V_7 -> V_372 ) {
V_359 = 0 ;
for ( V_135 = 0 ; V_135 < V_7 -> V_373 ; V_135 ++ ) {
int V_94 = ( V_7 -> V_372 [ V_135 ] & 0x7f ) * 5 ;
for ( V_360 = 0 ; V_360 < V_105 -> V_374 ; V_360 ++ ) {
if ( V_105 -> V_109 [ V_360 ] . V_110 == V_94 )
V_359 |= F_60 ( V_360 ) ;
}
}
V_23 -> V_23 . V_375 [ V_362 ] = V_359 ;
}
if ( V_7 -> V_376 )
F_122 ( V_12 , V_105 ,
V_7 -> V_376 , V_23 ) ;
if ( V_7 -> V_377 )
F_123 ( V_12 , V_105 ,
V_7 -> V_377 , V_23 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
T_1 V_296 = 0 ;
if ( V_7 -> V_366 & V_378 ) {
switch ( V_7 -> V_199 ) {
case V_379 :
if ( V_23 -> V_199 != V_379 )
V_296 = F_124 (
V_12 ) ;
V_23 -> V_199 = V_7 -> V_199 ;
F_125 ( V_23 ) ;
V_296 |= F_126 ( V_23 ,
V_12 -> V_15 . V_62 . V_380 . V_381 ) ;
break;
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
if ( V_23 -> V_199 == V_379 )
V_296 = F_127 (
V_12 ) ;
V_23 -> V_199 = V_7 -> V_199 ;
F_125 ( V_23 ) ;
V_296 |=
F_128 ( V_12 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_388 ) {
case V_389 :
break;
case V_390 :
V_296 |= F_129 ( V_23 ) ;
break;
case V_391 :
V_296 |= F_130 ( V_23 ) ;
break;
}
if ( V_7 -> V_203 )
V_296 |=
F_126 ( V_23 ,
V_7 -> V_203 ) ;
F_94 ( V_12 , V_296 ) ;
#endif
}
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_267 , struct V_358 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_392 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_58 )
return - V_45 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_132 ( V_267 , V_12 -> V_26 . V_268 ) )
return - V_45 ;
if ( F_133 ( V_267 ) )
return - V_45 ;
V_23 = F_134 ( V_12 , V_267 , V_287 ) ;
if ( ! V_23 )
return - V_288 ;
if ( ! ( V_7 -> V_364 & F_60 ( V_226 ) ) ) {
F_135 ( V_23 , V_354 ) ;
F_135 ( V_23 , V_355 ) ;
}
V_13 = F_119 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_136 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_28 ( V_23 , V_231 ) )
F_137 ( V_23 ) ;
V_392 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_58 ;
V_13 = F_138 ( V_23 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
if ( V_392 )
F_110 ( V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_267 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_267 )
return F_140 ( V_12 , V_267 ) ;
F_141 ( V_12 ) ;
return 0 ;
}
static int F_142 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_3 * V_267 ,
struct V_358 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_393 ;
enum V_394 V_395 ;
int V_13 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_27 ( V_12 , V_267 ) ;
if ( ! V_23 ) {
V_13 = - V_53 ;
goto V_396;
}
switch ( V_12 -> V_26 . type ) {
case V_61 :
if ( V_12 -> V_15 . V_62 . V_397 )
V_395 = V_398 ;
else
V_395 = V_399 ;
break;
case V_60 :
V_395 = V_400 ;
break;
case V_24 :
if ( ! F_28 ( V_23 , V_231 ) ) {
V_395 = V_401 ;
break;
}
if ( F_28 ( V_23 , V_227 ) )
V_395 = V_402 ;
else
V_395 = V_403 ;
break;
case V_58 :
case V_20 :
V_395 = V_404 ;
break;
default:
V_13 = - V_236 ;
goto V_396;
}
V_13 = F_143 ( V_2 , V_7 , V_395 ) ;
if ( V_13 )
goto V_396;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_405 = false ;
bool V_406 = false ;
V_393 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_270 -> V_21 ) {
if ( V_393 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_396;
}
F_88 ( V_393 -> V_15 . V_22 . V_23 , V_23 ) ;
V_406 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_88 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_405 = true ;
}
V_23 -> V_12 = V_393 ;
if ( V_23 -> V_249 == V_356 &&
V_405 != V_406 ) {
if ( V_406 )
F_144 ( & V_23 -> V_12 -> V_407 -> V_408 ) ;
else
F_145 ( & V_23 -> V_12 -> V_407 -> V_408 ) ;
}
F_110 ( V_23 ) ;
}
V_13 = F_119 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_396;
if ( F_28 ( V_23 , V_231 ) &&
F_28 ( V_23 , V_227 ) )
F_137 ( V_23 ) ;
F_33 ( & V_9 -> V_51 ) ;
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_363 & F_60 ( V_220 ) ) {
F_146 ( V_9 , - 1 ) ;
F_147 ( V_12 ) ;
}
return 0 ;
V_396:
F_33 ( & V_9 -> V_51 ) ;
return V_13 ;
}
static int F_148 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_409 , T_3 * V_410 )
{
struct V_11 * V_12 ;
struct V_411 * V_412 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_410 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_53 ;
}
V_412 = F_149 ( V_12 , V_409 ) ;
if ( F_21 ( V_412 ) ) {
F_43 () ;
return F_23 ( V_412 ) ;
}
F_150 ( V_412 , V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_151 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_409 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_409 )
return F_152 ( V_12 , V_409 ) ;
F_153 ( V_12 ) ;
return 0 ;
}
static int F_154 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_409 , T_3 * V_410 )
{
struct V_11 * V_12 ;
struct V_411 * V_412 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_410 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_53 ;
}
V_412 = F_155 ( V_12 , V_409 ) ;
if ( ! V_412 ) {
F_43 () ;
return - V_53 ;
}
F_150 ( V_412 , V_23 ) ;
F_43 () ;
return 0 ;
}
static void F_156 ( struct V_411 * V_412 , T_3 * V_410 ,
struct V_413 * V_414 )
{
struct V_36 * V_415 = F_40 ( V_412 -> V_410 ) ;
if ( V_415 )
memcpy ( V_410 , V_415 -> V_23 . V_268 , V_269 ) ;
else
memset ( V_410 , 0 , V_269 ) ;
memset ( V_414 , 0 , sizeof( * V_414 ) ) ;
V_414 -> V_137 = V_416 ;
V_414 -> V_139 = V_417 |
V_418 |
V_419 |
V_420 |
V_421 |
V_422 |
V_423 ;
V_414 -> V_424 = V_412 -> V_425 . V_426 ;
V_414 -> V_427 = V_412 -> V_427 ;
V_414 -> V_428 = V_412 -> V_428 ;
if ( F_157 ( V_158 , V_412 -> V_429 ) )
V_414 -> V_430 = F_55 ( V_412 -> V_429 - V_158 ) ;
V_414 -> V_431 =
F_55 ( V_412 -> V_431 ) ;
V_414 -> V_432 = V_412 -> V_432 ;
if ( V_412 -> V_5 & V_433 )
V_414 -> V_5 |= V_434 ;
if ( V_412 -> V_5 & V_435 )
V_414 -> V_5 |= V_436 ;
if ( V_412 -> V_5 & V_437 )
V_414 -> V_5 |= V_438 ;
if ( V_412 -> V_5 & V_439 )
V_414 -> V_5 |= V_440 ;
if ( V_412 -> V_5 & V_441 )
V_414 -> V_5 |= V_442 ;
}
static int F_158 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_409 , T_3 * V_410 , struct V_413 * V_414 )
{
struct V_11 * V_12 ;
struct V_411 * V_412 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_412 = F_155 ( V_12 , V_409 ) ;
if ( ! V_412 ) {
F_43 () ;
return - V_53 ;
}
memcpy ( V_409 , V_412 -> V_409 , V_269 ) ;
F_156 ( V_412 , V_410 , V_414 ) ;
F_43 () ;
return 0 ;
}
static int F_159 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , T_3 * V_409 , T_3 * V_410 ,
struct V_413 * V_414 )
{
struct V_11 * V_12 ;
struct V_411 * V_412 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_412 = F_160 ( V_12 , V_100 ) ;
if ( ! V_412 ) {
F_43 () ;
return - V_53 ;
}
memcpy ( V_409 , V_412 -> V_409 , V_269 ) ;
F_156 ( V_412 , V_410 , V_414 ) ;
F_43 () ;
return 0 ;
}
static int F_161 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_443 * V_49 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_49 , & ( V_12 -> V_15 . V_62 . V_380 ) , sizeof( struct V_443 ) ) ;
return 0 ;
}
static inline bool F_162 ( enum V_444 V_445 , T_1 V_27 )
{
return ( V_27 >> ( V_445 - 1 ) ) & 0x1 ;
}
static int F_163 ( struct V_446 * V_447 ,
const struct V_448 * V_449 )
{
T_3 * V_450 ;
const T_3 * V_451 ;
struct V_11 * V_12 = F_164 ( V_447 ,
struct V_11 , V_15 . V_62 ) ;
V_450 = NULL ;
V_451 = V_447 -> V_452 ;
if ( V_449 -> V_453 ) {
V_450 = F_165 ( V_449 -> V_452 , V_449 -> V_453 ,
V_287 ) ;
if ( ! V_450 )
return - V_288 ;
}
V_447 -> V_453 = V_449 -> V_453 ;
V_447 -> V_452 = V_450 ;
F_166 ( V_451 ) ;
V_447 -> V_454 = V_449 -> V_454 ;
memcpy ( V_447 -> V_455 , V_449 -> V_455 , V_447 -> V_454 ) ;
V_447 -> V_456 = V_449 -> V_457 ;
V_447 -> V_458 = V_449 -> V_459 ;
V_447 -> V_460 = V_449 -> V_461 ;
V_447 -> V_397 = V_449 -> V_397 ;
V_447 -> V_462 = V_449 -> V_463 ;
V_447 -> V_63 = V_64 ;
if ( V_449 -> V_464 )
V_447 -> V_63 |= V_465 ;
if ( V_449 -> V_466 )
V_447 -> V_63 |= V_467 ;
memcpy ( V_12 -> V_26 . V_207 . V_468 , V_449 -> V_468 ,
sizeof( V_449 -> V_468 ) ) ;
V_12 -> V_26 . V_207 . V_469 = V_449 -> V_469 ;
V_12 -> V_26 . V_207 . V_217 = V_449 -> V_216 ;
V_12 -> V_26 . V_207 . V_214 = V_449 -> V_214 ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_443 * V_470 )
{
struct V_443 * V_49 ;
struct V_11 * V_12 ;
struct V_446 * V_447 ;
V_12 = F_9 ( V_18 ) ;
V_447 = & V_12 -> V_15 . V_62 ;
V_49 = & ( V_12 -> V_15 . V_62 . V_380 ) ;
if ( F_162 ( V_471 , V_27 ) )
V_49 -> V_472 = V_470 -> V_472 ;
if ( F_162 ( V_473 , V_27 ) )
V_49 -> V_474 = V_470 -> V_474 ;
if ( F_162 ( V_475 , V_27 ) )
V_49 -> V_476 = V_470 -> V_476 ;
if ( F_162 ( V_477 , V_27 ) )
V_49 -> V_478 = V_470 -> V_478 ;
if ( F_162 ( V_479 , V_27 ) )
V_49 -> V_480 = V_470 -> V_480 ;
if ( F_162 ( V_481 , V_27 ) )
V_49 -> V_482 = V_470 -> V_482 ;
if ( F_162 ( V_483 , V_27 ) )
V_49 -> V_484 = V_470 -> V_484 ;
if ( F_162 ( V_485 , V_27 ) ) {
if ( V_447 -> V_397 )
return - V_30 ;
V_49 -> V_486 = V_470 -> V_486 ;
}
if ( F_162 ( V_487 , V_27 ) )
V_49 -> V_488 =
V_470 -> V_488 ;
if ( F_162 ( V_489 , V_27 ) )
V_49 -> V_490 =
V_470 -> V_490 ;
if ( F_162 ( V_491 , V_27 ) )
V_49 -> V_492 = V_470 -> V_492 ;
if ( F_162 ( V_493 , V_27 ) )
V_49 -> V_494 = V_470 -> V_494 ;
if ( F_162 ( V_495 , V_27 ) )
V_49 -> V_496 =
V_470 -> V_496 ;
if ( F_162 ( V_497 , V_27 ) )
V_49 -> V_498 =
V_470 -> V_498 ;
if ( F_162 ( V_499 , V_27 ) )
V_49 -> V_500 =
V_470 -> V_500 ;
if ( F_162 ( V_501 ,
V_27 ) )
V_49 -> V_502 =
V_470 -> V_502 ;
if ( F_162 ( V_503 , V_27 ) ) {
V_49 -> V_504 = V_470 -> V_504 ;
F_168 ( V_447 ) ;
}
if ( F_162 ( V_505 , V_27 ) ) {
if ( V_470 -> V_506 &&
! ( V_49 -> V_504 > V_507 ) ) {
V_49 -> V_504 = V_508 ;
F_168 ( V_447 ) ;
}
V_49 -> V_506 =
V_470 -> V_506 ;
}
if ( F_162 ( V_509 , V_27 ) )
V_49 -> V_510 =
V_470 -> V_510 ;
if ( F_162 ( V_511 , V_27 ) )
V_49 -> V_512 = V_470 -> V_512 ;
if ( F_162 ( V_513 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_106 . V_5 & V_172 ) )
return - V_514 ;
V_49 -> V_515 = V_470 -> V_515 ;
}
if ( F_162 ( V_516 , V_27 ) ) {
V_49 -> V_517 = V_470 -> V_517 ;
V_12 -> V_26 . V_207 . V_518 = V_470 -> V_517 ;
F_94 ( V_12 , V_519 ) ;
}
if ( F_162 ( V_520 , V_27 ) )
V_49 -> V_521 =
V_470 -> V_521 ;
if ( F_162 ( V_522 , V_27 ) )
V_49 -> V_523 =
V_470 -> V_523 ;
if ( F_162 ( V_524 , V_27 ) )
V_49 -> V_525 =
V_470 -> V_525 ;
if ( F_162 ( V_526 , V_27 ) ) {
V_49 -> V_381 = V_470 -> V_381 ;
F_128 ( V_12 ) ;
}
if ( F_162 ( V_527 , V_27 ) )
V_49 -> V_528 =
V_470 -> V_528 ;
if ( F_162 ( V_529 , V_27 ) )
V_49 -> V_530 = V_470 -> V_530 ;
F_169 ( V_12 , V_297 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_443 * V_49 ,
const struct V_448 * V_449 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_446 * V_447 = & V_12 -> V_15 . V_62 ;
int V_13 ;
memcpy ( & V_447 -> V_380 , V_49 , sizeof( struct V_443 ) ) ;
V_13 = F_163 ( V_447 , V_449 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_311 = V_312 ;
V_12 -> V_313 = V_12 -> V_9 -> V_314 ;
V_13 = F_83 ( V_12 , & V_449 -> V_272 ,
V_316 ) ;
if ( V_13 )
return V_13 ;
return F_171 ( V_12 ) ;
}
static int F_172 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_173 ( V_12 ) ;
F_82 ( V_12 ) ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_531 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_361 V_362 ;
T_1 V_296 = 0 ;
if ( ! F_86 ( V_12 -> V_15 . V_286 . V_298 ) )
return - V_53 ;
V_362 = F_51 ( V_12 ) ;
if ( V_7 -> V_208 >= 0 ) {
V_12 -> V_26 . V_207 . V_208 = V_7 -> V_208 ;
V_296 |= V_532 ;
}
if ( V_7 -> V_210 >= 0 ) {
V_12 -> V_26 . V_207 . V_210 =
V_7 -> V_210 ;
V_296 |= V_533 ;
}
if ( ! V_12 -> V_26 . V_207 . V_212 &&
V_362 == V_534 ) {
V_12 -> V_26 . V_207 . V_212 = true ;
V_296 |= V_535 ;
}
if ( V_7 -> V_536 >= 0 ) {
V_12 -> V_26 . V_207 . V_212 =
V_7 -> V_536 ;
V_296 |= V_535 ;
}
if ( V_7 -> V_469 ) {
int V_135 , V_360 ;
T_1 V_359 = 0 ;
struct V_104 * V_105 = V_2 -> V_107 [ V_362 ] ;
for ( V_135 = 0 ; V_135 < V_7 -> V_537 ; V_135 ++ ) {
int V_94 = ( V_7 -> V_469 [ V_135 ] & 0x7f ) * 5 ;
for ( V_360 = 0 ; V_360 < V_105 -> V_374 ; V_360 ++ ) {
if ( V_105 -> V_109 [ V_360 ] . V_110 == V_94 )
V_359 |= F_60 ( V_360 ) ;
}
}
V_12 -> V_26 . V_207 . V_469 = V_359 ;
V_296 |= V_538 ;
}
if ( V_7 -> V_539 >= 0 ) {
if ( V_7 -> V_539 )
V_12 -> V_5 |= V_540 ;
else
V_12 -> V_5 &= ~ V_540 ;
}
if ( V_7 -> V_517 >= 0 ) {
V_12 -> V_26 . V_207 . V_518 =
( T_2 ) V_7 -> V_517 ;
V_296 |= V_519 ;
}
if ( V_7 -> V_328 >= 0 ) {
V_12 -> V_26 . V_207 . V_326 . V_327 &=
~ V_329 ;
V_12 -> V_26 . V_207 . V_326 . V_327 |=
V_7 -> V_328 & V_329 ;
V_296 |= V_309 ;
}
if ( V_7 -> V_330 > 0 ) {
V_12 -> V_26 . V_207 . V_326 . V_327 |=
V_331 ;
V_296 |= V_309 ;
} else if ( V_7 -> V_330 == 0 ) {
V_12 -> V_26 . V_207 . V_326 . V_327 &=
~ V_331 ;
V_296 |= V_309 ;
}
F_94 ( V_12 , V_296 ) ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_541 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_542 V_543 ;
if ( ! V_9 -> V_176 -> V_544 )
return - V_236 ;
if ( V_9 -> V_106 . V_545 < V_161 )
return - V_236 ;
memset ( & V_543 , 0 , sizeof( V_543 ) ) ;
V_543 . V_546 = V_7 -> V_546 ;
V_543 . V_547 = V_7 -> V_548 ;
V_543 . V_549 = V_7 -> V_550 ;
V_543 . V_551 = V_7 -> V_551 ;
V_543 . V_552 = false ;
V_12 -> V_553 [ V_7 -> V_136 ] = V_543 ;
if ( F_176 ( V_9 , V_12 , V_7 -> V_136 , & V_543 ) ) {
F_177 ( V_9 -> V_106 . V_2 ,
L_1 ,
V_7 -> V_136 ) ;
return - V_45 ;
}
F_94 ( V_12 , V_554 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 ,
struct V_555 * V_556 )
{
return F_179 ( F_2 ( V_2 ) , V_556 ) ;
}
static int F_180 ( struct V_2 * V_2 )
{
return F_181 ( F_2 ( V_2 ) ) ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_557 * V_558 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_558 -> V_10 ) ;
switch ( F_183 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_60 :
case V_61 :
case V_69 :
case V_66 :
break;
case V_70 :
if ( V_12 -> V_9 -> V_176 -> V_559 )
break;
case V_58 :
if ( V_12 -> V_15 . V_286 . V_298 &&
( ! ( V_2 -> V_560 & V_561 ) ||
! ( V_558 -> V_5 & V_562 ) ) )
return - V_236 ;
break;
default:
return - V_236 ;
}
return F_184 ( V_12 , V_558 ) ;
}
static int
F_185 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_563 * V_558 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_176 -> V_564 )
return - V_236 ;
return F_186 ( V_12 , V_558 ) ;
}
static int
F_187 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_176 -> V_565 )
return - V_236 ;
return F_188 ( V_12 ) ;
}
static int F_189 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_566 * V_558 )
{
return F_190 ( F_9 ( V_18 ) , V_558 ) ;
}
static int F_191 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_567 * V_558 )
{
return F_192 ( F_9 ( V_18 ) , V_558 ) ;
}
static int F_193 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_568 * V_558 )
{
return F_194 ( F_9 ( V_18 ) , V_558 ) ;
}
static int F_195 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_569 * V_558 )
{
return F_196 ( F_9 ( V_18 ) , V_558 ) ;
}
static int F_197 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_570 * V_7 )
{
return F_198 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_200 ( F_9 ( V_18 ) ) ;
}
static int F_201 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_94 [ V_571 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_207 . V_468 , V_94 ,
sizeof( int ) * V_571 ) ;
return 0 ;
}
static int F_202 ( struct V_2 * V_2 , T_1 V_296 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_296 & V_572 ) {
V_13 = F_203 ( V_9 , V_2 -> V_573 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_296 & V_574 ) {
V_13 = F_204 ( V_9 , V_2 -> V_575 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_296 & V_576 ) {
V_13 = F_205 ( V_9 , V_2 -> V_577 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_296 & V_578 ) {
if ( V_2 -> V_579 > V_580 )
return - V_45 ;
V_9 -> V_106 . V_49 . V_581 = V_2 -> V_579 ;
}
if ( V_296 & V_582 ) {
if ( V_2 -> V_583 > V_580 )
return - V_45 ;
V_9 -> V_106 . V_49 . V_584 = V_2 -> V_583 ;
}
if ( V_296 &
( V_578 | V_582 ) )
F_84 ( V_9 , V_585 ) ;
return 0 ;
}
static int F_206 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_586 type , int V_587 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_588 :
V_12 -> V_589 = V_590 ;
break;
case V_591 :
case V_592 :
if ( V_587 < 0 || ( V_587 % 100 ) )
return - V_236 ;
V_12 -> V_589 = F_207 ( V_587 ) ;
break;
}
F_208 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_588 :
V_9 -> V_589 = V_590 ;
break;
case V_591 :
case V_592 :
if ( V_587 < 0 || ( V_587 % 100 ) )
return - V_236 ;
V_9 -> V_589 = F_207 ( V_587 ) ;
break;
}
F_24 ( & V_9 -> V_274 ) ;
F_68 (sdata, &local->interfaces, list)
V_12 -> V_589 = V_9 -> V_589 ;
F_68 (sdata, &local->interfaces, list)
F_208 ( V_12 ) ;
F_33 ( & V_9 -> V_274 ) ;
return 0 ;
}
static int F_209 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_593 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_275 )
* V_593 = V_9 -> V_106 . V_49 . V_594 ;
else
* V_593 = V_12 -> V_26 . V_207 . V_595 ;
return 0 ;
}
static int F_210 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_268 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_596 . V_597 , V_268 , V_269 ) ;
return 0 ;
}
static void F_211 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_212 ( V_9 ) ;
}
static int F_213 ( struct V_2 * V_2 , void * V_239 , int V_289 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_176 -> V_598 )
return - V_236 ;
return V_9 -> V_176 -> V_598 ( & V_9 -> V_106 , V_239 , V_289 ) ;
}
static int F_214 ( struct V_2 * V_2 ,
struct V_344 * V_345 ,
struct V_599 * V_353 ,
void * V_239 , int V_289 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_176 -> V_600 )
return - V_236 ;
return V_9 -> V_176 -> V_600 ( & V_9 -> V_106 , V_345 , V_353 , V_239 , V_289 ) ;
}
int F_215 ( struct V_11 * V_12 ,
enum V_601 V_311 )
{
const T_3 * V_286 ;
enum V_601 V_602 ;
int V_13 ;
F_216 ( & V_12 -> V_10 . V_603 ) ;
V_602 = V_12 -> V_15 . V_25 . V_604 ;
V_12 -> V_15 . V_25 . V_604 = V_311 ;
if ( V_602 == V_311 &&
V_311 != V_605 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_606 ||
V_12 -> V_26 . V_207 . V_272 . V_607 == V_608 )
return 0 ;
V_286 = V_12 -> V_15 . V_25 . V_606 -> V_247 ;
if ( V_311 == V_605 ) {
if ( V_12 -> V_15 . V_25 . V_609 )
V_311 = V_610 ;
else
V_311 = V_312 ;
}
V_13 = F_217 ( V_12 , V_311 ,
V_286 , V_286 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_604 = V_602 ;
return V_13 ;
}
static int F_218 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_611 , int V_612 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_76 ( V_18 -> V_270 ) ;
if ( V_12 -> V_26 . type != V_24 &&
V_12 -> V_26 . type != V_61 )
return - V_236 ;
if ( ! ( V_9 -> V_106 . V_5 & V_613 ) )
return - V_236 ;
if ( V_611 == V_12 -> V_15 . V_25 . V_609 &&
V_612 == V_9 -> V_614 )
return 0 ;
V_12 -> V_15 . V_25 . V_609 = V_611 ;
V_9 -> V_614 = V_612 ;
F_219 ( V_12 ) ;
F_215 ( V_12 , V_12 -> V_15 . V_25 . V_604 ) ;
F_220 ( V_12 ) ;
if ( V_9 -> V_106 . V_5 & V_615 )
F_84 ( V_9 , V_616 ) ;
F_146 ( V_9 , - 1 ) ;
F_147 ( V_12 ) ;
return 0 ;
}
static int F_221 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_617 , T_1 V_618 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_619 * V_26 = & V_12 -> V_26 ;
struct V_620 * V_207 = & V_26 -> V_207 ;
if ( V_617 == V_207 -> V_621 &&
V_618 == V_207 -> V_622 )
return 0 ;
V_207 -> V_621 = V_617 ;
V_207 -> V_622 = V_618 ;
if ( V_12 -> V_15 . V_25 . V_606 &&
V_12 -> V_26 . V_623 & V_624 )
F_94 ( V_12 , V_625 ) ;
return 0 ;
}
static int F_222 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_268 ,
const struct V_626 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_76 ( V_18 -> V_270 ) ;
int V_135 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_39 ;
if ( V_9 -> V_106 . V_5 & V_627 ) {
V_19 = F_223 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_135 = 0 ; V_135 < V_571 ; V_135 ++ ) {
struct V_104 * V_105 = V_2 -> V_107 [ V_135 ] ;
int V_360 ;
V_12 -> V_628 [ V_135 ] = V_27 -> V_350 [ V_135 ] . V_108 ;
memcpy ( V_12 -> V_629 [ V_135 ] , V_27 -> V_350 [ V_135 ] . V_99 ,
sizeof( V_27 -> V_350 [ V_135 ] . V_99 ) ) ;
V_12 -> V_630 [ V_135 ] = false ;
if ( ! V_105 )
continue;
for ( V_360 = 0 ; V_360 < V_631 ; V_360 ++ )
if ( ~ V_12 -> V_629 [ V_135 ] [ V_360 ] ) {
V_12 -> V_630 [ V_135 ] = true ;
break;
}
}
return 0 ;
}
static int F_224 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_242 * V_243 ,
unsigned int V_632 , T_4 * V_75 ,
struct V_344 * V_633 ,
enum V_634 type )
{
struct V_635 * V_636 , * V_637 ;
bool V_638 = false ;
int V_19 ;
F_216 ( & V_9 -> V_603 ) ;
if ( V_9 -> V_275 && ! V_9 -> V_176 -> V_639 )
return - V_236 ;
V_636 = F_87 ( sizeof( * V_636 ) , V_287 ) ;
if ( ! V_636 )
return - V_288 ;
V_636 -> V_251 = V_243 ;
V_636 -> V_632 = V_632 ;
V_636 -> V_640 = V_632 ;
V_636 -> V_641 = V_633 ;
V_636 -> type = type ;
V_636 -> V_642 = ( unsigned long ) V_633 ;
V_636 -> V_12 = V_12 ;
F_225 ( & V_636 -> V_643 , V_644 ) ;
F_226 ( & V_636 -> V_645 ) ;
if ( ! F_227 ( & V_9 -> V_646 ) ||
V_9 -> V_647 || V_9 -> V_648 )
goto V_649;
if ( ! V_9 -> V_176 -> V_639 ) {
F_228 ( & V_9 -> V_106 , & V_636 -> V_643 , 0 ) ;
goto V_650;
}
if ( ! V_632 )
V_632 = 10 ;
V_19 = F_229 ( V_9 , V_12 , V_243 , V_632 , type ) ;
if ( V_19 ) {
F_166 ( V_636 ) ;
return V_19 ;
}
V_636 -> V_651 = true ;
goto V_650;
V_649:
F_68 (tmp, &local->roc_list, list) {
if ( V_637 -> V_251 != V_243 || V_637 -> V_12 != V_12 )
continue;
if ( ! V_637 -> V_651 ) {
F_230 ( & V_636 -> V_652 , & V_637 -> V_645 ) ;
V_637 -> V_632 = F_231 ( V_637 -> V_632 , V_636 -> V_632 ) ;
V_637 -> type = F_231 ( V_637 -> type , V_636 -> type ) ;
V_638 = true ;
break;
}
if ( V_9 -> V_176 -> V_639 ) {
unsigned long V_360 = V_158 ;
if ( ! V_637 -> V_653 ) {
F_230 ( & V_636 -> V_652 , & V_637 -> V_645 ) ;
V_638 = true ;
break;
}
if ( F_157 ( V_360 + V_654 ,
V_637 -> V_655 +
F_232 ( V_637 -> V_632 ) ) ) {
int V_656 ;
F_233 ( V_636 ) ;
V_656 = V_636 -> V_632 -
F_55 ( V_637 -> V_655 +
F_232 (
V_637 -> V_632 ) -
V_360 ) ;
if ( V_656 > 0 ) {
F_234 ( & V_636 -> V_652 , & V_637 -> V_652 ) ;
} else {
F_230 ( & V_636 -> V_652 ,
& V_637 -> V_645 ) ;
}
V_638 = true ;
}
} else if ( F_235 ( & V_637 -> V_643 . V_657 ) ) {
unsigned long V_658 ;
F_230 ( & V_636 -> V_652 , & V_637 -> V_645 ) ;
V_638 = true ;
V_658 = V_158 + F_232 ( V_636 -> V_632 ) ;
if ( F_236 ( V_658 , V_637 -> V_643 . V_657 . V_659 ) )
F_237 ( & V_637 -> V_643 . V_657 , V_658 ) ;
else
F_238 ( & V_637 -> V_643 . V_657 ) ;
F_233 ( V_636 ) ;
}
break;
}
V_650:
if ( ! V_638 )
F_230 ( & V_636 -> V_652 , & V_9 -> V_646 ) ;
if ( ! V_633 ) {
V_9 -> V_660 ++ ;
V_636 -> V_75 = V_9 -> V_660 ;
if ( F_66 ( V_636 -> V_75 == 0 ) ) {
V_636 -> V_75 = 1 ;
V_9 -> V_660 ++ ;
}
* V_75 = V_636 -> V_75 ;
} else {
* V_75 = ( unsigned long ) V_633 ;
}
return 0 ;
}
static int F_239 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_242 * V_251 ,
unsigned int V_632 ,
T_4 * V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_24 ( & V_9 -> V_603 ) ;
V_19 = F_224 ( V_9 , V_12 , V_251 ,
V_632 , V_75 , NULL ,
V_661 ) ;
F_33 ( & V_9 -> V_603 ) ;
return V_19 ;
}
static int F_240 ( struct V_8 * V_9 ,
T_4 V_75 , bool V_662 )
{
struct V_635 * V_636 , * V_637 , * V_663 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_603 ) ;
F_241 (roc, tmp, &local->roc_list, list) {
struct V_635 * V_664 , * V_665 ;
F_241 (dep, tmp2, &roc->dependents, list) {
if ( ! V_662 && V_664 -> V_75 != V_75 )
continue;
else if ( V_662 && V_664 -> V_642 != V_75 )
continue;
F_242 ( & V_664 -> V_652 ) ;
F_33 ( & V_9 -> V_603 ) ;
F_243 ( V_664 , true ) ;
return 0 ;
}
if ( ! V_662 && V_636 -> V_75 != V_75 )
continue;
else if ( V_662 && V_636 -> V_642 != V_75 )
continue;
V_663 = V_636 ;
break;
}
if ( ! V_663 ) {
F_33 ( & V_9 -> V_603 ) ;
return - V_53 ;
}
if ( V_9 -> V_176 -> V_639 ) {
if ( V_663 -> V_651 ) {
V_19 = F_244 ( V_9 ) ;
if ( F_31 ( V_19 ) ) {
F_33 ( & V_9 -> V_603 ) ;
return V_19 ;
}
}
F_242 ( & V_663 -> V_652 ) ;
if ( V_663 -> V_651 )
F_245 ( V_9 ) ;
F_33 ( & V_9 -> V_603 ) ;
F_243 ( V_663 , true ) ;
} else {
V_663 -> abort = true ;
F_228 ( & V_9 -> V_106 , & V_663 -> V_643 , 0 ) ;
F_33 ( & V_9 -> V_603 ) ;
F_246 ( & V_663 -> V_643 ) ;
F_66 ( ! V_663 -> V_666 ) ;
F_166 ( V_663 ) ;
}
return 0 ;
}
static int F_247 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_240 ( V_9 , V_75 , false ) ;
}
static int F_248 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_271 * V_272 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
unsigned long V_612 ;
int V_13 ;
if ( ! F_227 ( & V_9 -> V_646 ) || V_9 -> V_647 )
return - V_30 ;
V_12 -> V_311 = V_312 ;
V_12 -> V_313 = V_9 -> V_314 ;
V_12 -> V_315 = true ;
F_24 ( & V_9 -> V_274 ) ;
V_13 = F_83 ( V_12 , V_272 ,
V_316 ) ;
F_33 ( & V_9 -> V_274 ) ;
if ( V_13 )
return V_13 ;
V_612 = F_232 ( V_667 ) ;
F_228 ( & V_12 -> V_9 -> V_106 ,
& V_12 -> V_337 , V_612 ) ;
return 0 ;
}
static int F_249 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_242 * V_251 , bool V_668 ,
unsigned int V_669 , const T_3 * V_670 , T_5 V_289 ,
bool V_671 , bool V_672 , T_4 * V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_344 * V_345 ;
struct V_36 * V_23 ;
const struct V_673 * V_674 = ( void * ) V_670 ;
bool V_675 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_672 )
V_5 = V_676 ;
else
V_5 = V_677 |
V_678 ;
if ( V_671 )
V_5 |= V_679 ;
switch ( V_12 -> V_26 . type ) {
case V_60 :
if ( ! V_12 -> V_26 . V_207 . V_680 )
V_675 = true ;
#ifdef F_30
case V_61 :
if ( F_25 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_62 . V_454 )
V_675 = true ;
#endif
case V_58 :
case V_20 :
case V_70 :
if ( V_12 -> V_26 . type != V_60 &&
! F_25 ( & V_12 -> V_26 ) &&
! F_250 ( V_12 -> V_407 -> V_298 ) )
V_675 = true ;
if ( ! F_251 ( V_674 -> V_681 ) ||
V_674 -> V_15 . V_682 . V_683 == V_684 ||
V_674 -> V_15 . V_682 . V_683 == V_685 )
break;
F_39 () ;
V_23 = F_26 ( V_12 , V_674 -> V_346 ) ;
F_43 () ;
if ( ! V_23 )
return - V_686 ;
break;
case V_24 :
case V_69 :
if ( ! V_12 -> V_15 . V_25 . V_606 )
V_675 = true ;
break;
case V_66 :
V_675 = true ;
break;
default:
return - V_236 ;
}
if ( V_675 && ! V_251 )
return - V_45 ;
F_24 ( & V_9 -> V_603 ) ;
if ( ! V_675 ) {
struct V_240 * V_241 ;
F_39 () ;
V_241 = F_40 ( V_12 -> V_26 . V_241 ) ;
if ( V_241 ) {
V_675 = V_251 && ( V_251 != V_241 -> V_250 . V_251 ) ;
} else if ( ! V_251 ) {
V_19 = - V_45 ;
F_43 () ;
goto V_54;
} else {
V_675 = true ;
}
F_43 () ;
}
if ( V_675 && ! V_668 ) {
V_19 = - V_30 ;
goto V_54;
}
V_345 = F_111 ( V_9 -> V_106 . V_687 + V_289 ) ;
if ( ! V_345 ) {
V_19 = - V_288 ;
goto V_54;
}
F_252 ( V_345 , V_9 -> V_106 . V_687 ) ;
memcpy ( F_112 ( V_345 , V_289 ) , V_670 , V_289 ) ;
F_253 ( V_345 ) -> V_5 = V_5 ;
V_345 -> V_18 = V_12 -> V_18 ;
if ( ! V_675 ) {
* V_75 = ( unsigned long ) V_345 ;
F_254 ( V_12 , V_345 ) ;
V_19 = 0 ;
goto V_54;
}
F_253 ( V_345 ) -> V_5 |= V_688 |
V_689 ;
if ( V_9 -> V_106 . V_5 & V_690 )
F_253 ( V_345 ) -> V_691 =
V_9 -> V_106 . V_692 ;
V_19 = F_224 ( V_9 , V_12 , V_251 ,
V_669 , V_75 , V_345 ,
V_693 ) ;
if ( V_19 )
F_255 ( V_345 ) ;
V_54:
F_33 ( & V_9 -> V_603 ) ;
return V_19 ;
}
static int F_256 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_75 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_240 ( V_9 , V_75 , true ) ;
}
static void F_257 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_694 , bool V_695 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_694 ) {
case V_696 | V_697 :
if ( V_695 )
V_9 -> V_698 ++ ;
else
V_9 -> V_698 -- ;
if ( ! V_9 -> V_278 )
break;
F_258 ( & V_9 -> V_106 , & V_9 -> V_699 ) ;
break;
default:
break;
}
}
static int F_259 ( struct V_2 * V_2 , T_1 V_700 , T_1 V_701 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_651 )
return - V_236 ;
return F_260 ( V_9 , V_700 , V_701 ) ;
}
static int F_261 ( struct V_2 * V_2 , T_1 * V_700 , T_1 * V_701 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_262 ( V_9 , V_700 , V_701 ) ;
}
static int F_263 ( struct V_2 * V_2 , T_1 V_82 , T_1 V_702 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_264 ( V_9 , V_82 , V_702 ) ;
}
static void F_265 ( struct V_2 * V_2 ,
T_1 * V_82 , T_1 * V_703 , T_1 * V_702 , T_1 * V_704 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_266 ( V_9 , V_82 , V_703 , V_702 , V_704 ) ;
}
static int F_267 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_705 * V_239 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_176 -> V_706 )
return - V_236 ;
F_268 ( V_9 , V_12 , V_239 ) ;
return 0 ;
}
static void F_269 ( struct V_344 * V_345 )
{
T_3 * V_707 = ( void * ) F_112 ( V_345 , 7 ) ;
* V_707 ++ = V_708 ;
* V_707 ++ = 5 ;
* V_707 ++ = 0x0 ;
* V_707 ++ = 0x0 ;
* V_707 ++ = 0x0 ;
* V_707 ++ = 0x0 ;
* V_707 ++ = V_709 ;
}
static T_2 F_270 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_710 ;
V_710 = 0 ;
if ( F_51 ( V_12 ) != V_711 )
return V_710 ;
if ( ! ( V_9 -> V_106 . V_5 & V_712 ) )
V_710 |= V_713 ;
if ( ! ( V_9 -> V_106 . V_5 & V_714 ) )
V_710 |= V_715 ;
return V_710 ;
}
static void F_271 ( struct V_344 * V_345 , T_3 * V_716 ,
T_3 * V_717 , T_3 * V_247 )
{
struct V_718 * V_719 ;
V_719 = ( void * ) F_112 ( V_345 , sizeof( struct V_718 ) ) ;
V_719 -> V_720 = V_721 ;
V_719 -> V_453 = sizeof( struct V_718 ) - 2 ;
memcpy ( V_719 -> V_247 , V_247 , V_269 ) ;
memcpy ( V_719 -> V_722 , V_716 , V_269 ) ;
memcpy ( V_719 -> V_723 , V_717 , V_269 ) ;
}
static int
F_272 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_717 , T_3 V_724 , T_3 V_725 ,
T_2 V_726 , struct V_344 * V_345 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_361 V_362 = F_51 ( V_12 ) ;
struct V_727 * V_728 ;
V_728 = ( void * ) F_112 ( V_345 , F_273 ( struct V_727 , V_15 ) ) ;
memcpy ( V_728 -> V_346 , V_717 , V_269 ) ;
memcpy ( V_728 -> V_347 , V_12 -> V_26 . V_268 , V_269 ) ;
V_728 -> V_729 = F_274 ( V_730 ) ;
V_728 -> V_731 = V_732 ;
switch ( V_724 ) {
case V_733 :
V_728 -> V_683 = V_734 ;
V_728 -> V_724 = V_733 ;
F_112 ( V_345 , sizeof( V_728 -> V_15 . V_735 ) ) ;
V_728 -> V_15 . V_735 . V_725 = V_725 ;
V_728 -> V_15 . V_735 . V_736 =
F_275 ( F_270 ( V_12 ) ) ;
F_276 ( V_12 , V_345 , false , V_362 ) ;
F_277 ( V_12 , V_345 , false , V_362 ) ;
F_269 ( V_345 ) ;
break;
case V_737 :
V_728 -> V_683 = V_734 ;
V_728 -> V_724 = V_737 ;
F_112 ( V_345 , sizeof( V_728 -> V_15 . V_738 ) ) ;
V_728 -> V_15 . V_738 . V_726 = F_275 ( V_726 ) ;
V_728 -> V_15 . V_738 . V_725 = V_725 ;
V_728 -> V_15 . V_738 . V_736 =
F_275 ( F_270 ( V_12 ) ) ;
F_276 ( V_12 , V_345 , false , V_362 ) ;
F_277 ( V_12 , V_345 , false , V_362 ) ;
F_269 ( V_345 ) ;
break;
case V_739 :
V_728 -> V_683 = V_734 ;
V_728 -> V_724 = V_739 ;
F_112 ( V_345 , sizeof( V_728 -> V_15 . V_740 ) ) ;
V_728 -> V_15 . V_740 . V_726 = F_275 ( V_726 ) ;
V_728 -> V_15 . V_740 . V_725 = V_725 ;
break;
case V_741 :
V_728 -> V_683 = V_734 ;
V_728 -> V_724 = V_741 ;
F_112 ( V_345 , sizeof( V_728 -> V_15 . V_742 ) ) ;
V_728 -> V_15 . V_742 . V_743 = F_275 ( V_726 ) ;
break;
case V_744 :
V_728 -> V_683 = V_734 ;
V_728 -> V_724 = V_744 ;
F_112 ( V_345 , sizeof( V_728 -> V_15 . V_745 ) ) ;
V_728 -> V_15 . V_745 . V_725 = V_725 ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int
F_278 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_717 , T_3 V_724 , T_3 V_725 ,
T_2 V_726 , struct V_344 * V_345 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_361 V_362 = F_51 ( V_12 ) ;
struct V_673 * V_674 ;
V_674 = ( void * ) F_112 ( V_345 , 24 ) ;
memset ( V_674 , 0 , 24 ) ;
memcpy ( V_674 -> V_346 , V_717 , V_269 ) ;
memcpy ( V_674 -> V_347 , V_12 -> V_26 . V_268 , V_269 ) ;
memcpy ( V_674 -> V_247 , V_12 -> V_15 . V_25 . V_247 , V_269 ) ;
V_674 -> V_681 = F_275 ( V_696 |
V_746 ) ;
switch ( V_724 ) {
case V_747 :
F_112 ( V_345 , 1 + sizeof( V_674 -> V_15 . V_682 . V_15 . V_748 ) ) ;
V_674 -> V_15 . V_682 . V_683 = V_684 ;
V_674 -> V_15 . V_682 . V_15 . V_748 . V_724 =
V_747 ;
V_674 -> V_15 . V_682 . V_15 . V_748 . V_725 =
V_725 ;
V_674 -> V_15 . V_682 . V_15 . V_748 . V_736 =
F_275 ( F_270 ( V_12 ) ) ;
F_276 ( V_12 , V_345 , false , V_362 ) ;
F_277 ( V_12 , V_345 , false , V_362 ) ;
F_269 ( V_345 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_279 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_717 , T_3 V_724 , T_3 V_725 ,
T_2 V_726 , const T_3 * V_749 ,
T_5 V_750 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_344 * V_345 = NULL ;
bool V_751 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_752 ) )
return - V_514 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_606 )
return - V_45 ;
F_280 ( V_12 , L_2 ,
V_724 , V_717 ) ;
V_345 = F_111 ( V_9 -> V_106 . V_687 +
F_231 ( sizeof( struct V_673 ) ,
sizeof( struct V_727 ) ) +
50 +
7 +
V_750 +
sizeof( struct V_718 ) ) ;
if ( ! V_345 )
return - V_288 ;
F_252 ( V_345 , V_9 -> V_106 . V_687 ) ;
switch ( V_724 ) {
case V_733 :
case V_737 :
case V_739 :
case V_741 :
case V_744 :
V_19 = F_272 ( V_2 , V_18 , V_717 ,
V_724 , V_725 ,
V_726 , V_345 ) ;
V_751 = false ;
break;
case V_747 :
V_19 = F_278 ( V_2 , V_18 , V_717 , V_724 ,
V_725 , V_726 ,
V_345 ) ;
V_751 = true ;
break;
default:
V_19 = - V_514 ;
break;
}
if ( V_19 < 0 )
goto V_753;
if ( V_750 )
memcpy ( F_112 ( V_345 , V_750 ) , V_749 , V_750 ) ;
switch ( V_724 ) {
case V_733 :
case V_739 :
case V_741 :
case V_744 :
F_271 ( V_345 , V_12 -> V_26 . V_268 , V_717 ,
V_12 -> V_15 . V_25 . V_247 ) ;
break;
case V_737 :
case V_747 :
F_271 ( V_345 , V_717 , V_12 -> V_26 . V_268 ,
V_12 -> V_15 . V_25 . V_247 ) ;
break;
default:
V_19 = - V_514 ;
goto V_753;
}
if ( V_751 ) {
F_254 ( V_12 , V_345 ) ;
return 0 ;
}
switch ( V_724 ) {
case V_733 :
case V_737 :
F_281 ( V_345 , V_754 ) ;
V_345 -> V_755 = 2 ;
break;
default:
F_281 ( V_345 , V_756 ) ;
V_345 -> V_755 = 5 ;
break;
}
F_282 () ;
V_19 = F_283 ( V_345 , V_18 ) ;
F_284 () ;
return V_19 ;
V_753:
F_285 ( V_345 ) ;
return V_19 ;
}
static int F_286 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_717 , enum V_757 V_758 )
{
struct V_36 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_752 ) )
return - V_514 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_45 ;
F_280 ( V_12 , L_3 , V_758 , V_717 ) ;
switch ( V_758 ) {
case V_759 :
F_39 () ;
V_23 = F_26 ( V_12 , V_717 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_686 ;
}
F_120 ( V_23 , V_760 ) ;
F_43 () ;
break;
case V_761 :
return F_287 ( V_12 , V_717 ) ;
case V_762 :
case V_763 :
case V_764 :
return - V_514 ;
default:
return - V_514 ;
}
return 0 ;
}
static int F_288 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_717 , T_4 * V_75 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_765 * V_766 ;
struct V_344 * V_345 ;
int V_295 = sizeof( * V_766 ) ;
T_7 V_767 ;
bool V_768 ;
struct V_769 * V_770 ;
struct V_36 * V_23 ;
struct V_240 * V_241 ;
enum V_361 V_362 ;
F_39 () ;
V_241 = F_40 ( V_12 -> V_26 . V_241 ) ;
if ( F_66 ( ! V_241 ) ) {
F_43 () ;
return - V_45 ;
}
V_362 = V_241 -> V_250 . V_251 -> V_362 ;
V_23 = F_26 ( V_12 , V_717 ) ;
if ( V_23 ) {
V_768 = F_28 ( V_23 , V_229 ) ;
} else {
F_43 () ;
return - V_686 ;
}
if ( V_768 ) {
V_767 = F_275 ( V_771 |
V_772 |
V_773 ) ;
} else {
V_295 -= 2 ;
V_767 = F_275 ( V_771 |
V_774 |
V_773 ) ;
}
V_345 = F_111 ( V_9 -> V_106 . V_687 + V_295 ) ;
if ( ! V_345 ) {
F_43 () ;
return - V_288 ;
}
V_345 -> V_18 = V_18 ;
F_252 ( V_345 , V_9 -> V_106 . V_687 ) ;
V_766 = ( void * ) F_112 ( V_345 , V_295 ) ;
V_766 -> V_681 = V_767 ;
V_766 -> V_775 = 0 ;
memcpy ( V_766 -> V_776 , V_23 -> V_23 . V_268 , V_269 ) ;
memcpy ( V_766 -> V_777 , V_12 -> V_26 . V_268 , V_269 ) ;
memcpy ( V_766 -> V_778 , V_12 -> V_26 . V_268 , V_269 ) ;
V_766 -> V_779 = 0 ;
V_770 = F_253 ( V_345 ) ;
V_770 -> V_5 |= V_678 |
V_677 ;
F_281 ( V_345 , V_780 ) ;
V_345 -> V_755 = 7 ;
if ( V_768 )
V_766 -> V_781 = F_275 ( 7 ) ;
F_282 () ;
F_289 ( V_12 , V_345 , V_362 ) ;
F_284 () ;
F_43 () ;
* V_75 = ( unsigned long ) V_345 ;
return 0 ;
}
static int F_290 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_271 * V_272 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_240 * V_241 ;
int V_19 = - V_782 ;
F_39 () ;
V_241 = F_40 ( V_12 -> V_26 . V_241 ) ;
if ( V_241 ) {
* V_272 = V_241 -> V_250 ;
V_19 = 0 ;
} else if ( V_9 -> V_278 > 0 &&
V_9 -> V_278 == V_9 -> V_279 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_275 )
* V_272 = V_9 -> V_273 ;
else
* V_272 = V_9 -> V_280 ;
V_19 = 0 ;
}
F_43 () ;
return V_19 ;
}
static void F_291 ( struct V_2 * V_2 , bool V_611 )
{
F_292 ( F_2 ( V_2 ) , V_611 ) ;
}
