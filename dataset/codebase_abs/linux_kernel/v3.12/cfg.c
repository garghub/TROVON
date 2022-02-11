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
int V_106 = F_51 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_107 ;
V_105 = V_23 -> V_9 -> V_108 . V_2 -> V_109 [
F_52 ( V_23 -> V_12 ) ] ;
V_107 = V_105 -> V_110 [ V_94 -> V_100 ] . V_111 ;
V_96 -> V_112 = F_53 ( V_107 , 1 << V_106 ) ;
}
if ( V_94 -> V_5 & V_113 )
V_96 -> V_5 |= V_114 ;
if ( V_94 -> V_5 & V_115 )
V_96 -> V_5 |= V_116 ;
if ( V_94 -> V_5 & V_117 )
V_96 -> V_5 |= V_118 ;
if ( V_94 -> V_5 & V_119 )
V_96 -> V_5 |= V_120 ;
}
void F_54 ( struct V_36 * V_23 , struct V_95 * V_96 )
{
V_96 -> V_5 = 0 ;
if ( V_23 -> V_121 & V_122 ) {
V_96 -> V_5 |= V_98 ;
V_96 -> V_99 = V_23 -> V_123 ;
} else if ( V_23 -> V_121 & V_124 ) {
V_96 -> V_5 |= V_102 ;
V_96 -> V_103 = V_23 -> V_125 ;
V_96 -> V_99 = V_23 -> V_123 ;
} else {
struct V_104 * V_105 ;
int V_106 = F_51 ( & V_23 -> V_12 -> V_26 ) ;
T_2 V_107 ;
V_105 = V_23 -> V_9 -> V_108 . V_2 -> V_109 [
F_52 ( V_23 -> V_12 ) ] ;
V_107 = V_105 -> V_110 [ V_23 -> V_123 ] . V_111 ;
V_96 -> V_112 = F_53 ( V_107 , 1 << V_106 ) ;
}
if ( V_23 -> V_121 & V_126 )
V_96 -> V_5 |= V_114 ;
if ( V_23 -> V_121 & V_127 )
V_96 -> V_5 |= V_120 ;
if ( V_23 -> V_121 & V_128 )
V_96 -> V_5 |= V_116 ;
if ( V_23 -> V_121 & V_129 )
V_96 -> V_5 |= V_130 ;
if ( V_23 -> V_121 & V_131 )
V_96 -> V_5 |= V_118 ;
}
static void F_55 ( struct V_36 * V_23 , struct V_132 * V_133 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_134 V_135 ;
T_4 V_136 = 0 ;
int V_137 , V_138 ;
V_133 -> V_139 = V_12 -> V_9 -> V_140 ;
V_133 -> V_141 = V_142 |
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
V_153 |
V_154 |
V_155 ;
F_56 ( & V_135 ) ;
V_133 -> V_156 = V_135 . V_157 - V_23 -> V_158 ;
V_133 -> V_159 = F_57 ( V_160 - V_23 -> V_161 ) ;
V_133 -> V_162 = 0 ;
for ( V_138 = 0 ; V_138 < V_163 ; V_138 ++ ) {
V_133 -> V_162 += V_23 -> V_162 [ V_138 ] ;
V_136 += V_23 -> V_164 [ V_138 ] ;
}
V_133 -> V_164 = V_136 ;
V_133 -> V_165 = V_23 -> V_165 ;
V_133 -> V_166 = V_23 -> V_166 ;
V_133 -> V_167 = V_23 -> V_168 ;
V_133 -> V_169 = V_23 -> V_170 ;
V_133 -> V_171 = V_23 -> V_172 ;
V_133 -> V_173 = V_23 -> V_173 ;
if ( ( V_23 -> V_9 -> V_108 . V_5 & V_174 ) ||
( V_23 -> V_9 -> V_108 . V_5 & V_175 ) ) {
V_133 -> V_141 |= V_176 | V_177 ;
if ( ! V_9 -> V_178 -> V_179 ||
F_58 ( V_9 , V_12 , & V_23 -> V_23 , & V_133 -> signal ) )
V_133 -> signal = ( V_180 ) V_23 -> V_181 ;
V_133 -> V_182 = ( V_180 ) - F_59 ( & V_23 -> V_183 ) ;
}
if ( V_23 -> V_184 ) {
V_133 -> V_141 |= V_185 |
V_186 ;
V_133 -> V_184 = V_23 -> V_184 ;
for ( V_137 = 0 ; V_137 < F_60 ( V_133 -> V_187 ) ; V_137 ++ ) {
V_133 -> V_187 [ V_137 ] = V_23 -> V_188 [ V_137 ] ;
V_133 -> V_189 [ V_137 ] =
( V_180 ) - F_59 ( & V_23 -> V_189 [ V_137 ] ) ;
}
}
F_48 ( V_23 , & V_23 -> V_190 , & V_133 -> V_191 ) ;
F_54 ( V_23 , & V_133 -> V_192 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
V_133 -> V_141 |= V_193 |
V_194 |
V_195 |
V_196 |
V_197 |
V_198 ;
V_133 -> V_199 = F_61 ( V_23 -> V_199 ) ;
V_133 -> V_200 = F_61 ( V_23 -> V_200 ) ;
V_133 -> V_201 = V_23 -> V_201 ;
if ( F_28 ( V_23 , V_202 ) ) {
V_133 -> V_141 |= V_203 ;
V_133 -> V_204 = V_23 -> V_204 ;
}
V_133 -> V_205 = V_23 -> V_205 ;
V_133 -> V_206 = V_23 -> V_206 ;
V_133 -> V_207 = V_23 -> V_207 ;
#endif
}
V_133 -> V_208 . V_5 = 0 ;
if ( V_12 -> V_26 . V_209 . V_210 )
V_133 -> V_208 . V_5 |= V_211 ;
if ( V_12 -> V_26 . V_209 . V_212 )
V_133 -> V_208 . V_5 |= V_213 ;
if ( V_12 -> V_26 . V_209 . V_214 )
V_133 -> V_208 . V_5 |= V_215 ;
V_133 -> V_208 . V_216 = V_12 -> V_9 -> V_108 . V_49 . V_217 ;
V_133 -> V_208 . V_218 = V_12 -> V_26 . V_209 . V_219 ;
V_133 -> V_220 . V_221 = 0 ;
V_133 -> V_220 . V_27 = F_62 ( V_222 ) |
F_62 ( V_223 ) |
F_62 ( V_224 ) |
F_62 ( V_225 ) |
F_62 ( V_226 ) |
F_62 ( V_227 ) |
F_62 ( V_228 ) ;
if ( F_28 ( V_23 , V_229 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_222 ) ;
if ( F_28 ( V_23 , V_230 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_223 ) ;
if ( F_28 ( V_23 , V_231 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_224 ) ;
if ( F_28 ( V_23 , V_59 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_225 ) ;
if ( F_28 ( V_23 , V_232 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_226 ) ;
if ( F_28 ( V_23 , V_52 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_227 ) ;
if ( F_28 ( V_23 , V_233 ) )
V_133 -> V_220 . V_221 |= F_62 ( V_228 ) ;
}
static int F_63 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_234 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_235 = 0 ;
if ( V_234 == V_236 )
V_235 += V_237 ;
V_235 += F_64 ( V_12 , V_234 ) ;
if ( V_235 == 0 )
return - V_238 ;
return V_235 ;
}
static void F_65 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_239 * V_240 ,
T_4 * V_241 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_242 * V_243 ;
struct V_244 * V_245 ;
struct V_36 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_132 V_133 ;
struct V_246 V_247 ;
int V_137 , V_248 ;
#define F_66 7
memset ( V_241 , 0 , sizeof( T_4 ) * V_237 ) ;
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
F_24 ( & V_9 -> V_51 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_27 ( V_12 , V_12 -> V_15 . V_25 . V_249 ) ;
if ( ! ( V_23 && ! F_68 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_250;
V_133 . V_141 = 0 ;
F_55 ( V_23 , & V_133 ) ;
V_137 = 0 ;
F_67 ( V_23 ) ;
V_241 [ V_137 ++ ] = V_23 -> V_251 ;
if ( V_133 . V_141 & V_149 )
V_241 [ V_137 ] = 100000 *
F_69 ( & V_133 . V_191 ) ;
V_137 ++ ;
if ( V_133 . V_141 & V_150 )
V_241 [ V_137 ] = 100000 *
F_69 ( & V_133 . V_192 ) ;
V_137 ++ ;
if ( V_133 . V_141 & V_177 )
V_241 [ V_137 ] = ( T_3 ) V_133 . V_182 ;
V_137 ++ ;
} else {
F_70 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_133 . V_141 = 0 ;
F_55 ( V_23 , & V_133 ) ;
V_137 = 0 ;
F_67 ( V_23 ) ;
}
}
V_250:
V_137 = V_237 - F_66 ;
V_247 . V_141 = 0 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( V_243 )
V_245 = V_243 -> V_252 . V_253 ;
else
V_245 = NULL ;
F_43 () ;
if ( V_245 ) {
V_248 = 0 ;
do {
V_247 . V_141 = 0 ;
if ( F_71 ( V_9 , V_248 , & V_247 ) != 0 ) {
V_247 . V_141 = 0 ;
break;
}
V_248 ++ ;
} while ( V_245 != V_247 . V_245 );
}
if ( V_247 . V_141 )
V_241 [ V_137 ++ ] = V_247 . V_245 -> V_254 ;
else
V_241 [ V_137 ++ ] = 0 ;
if ( V_247 . V_141 & V_255 )
V_241 [ V_137 ++ ] = ( T_3 ) V_247 . V_256 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_257 )
V_241 [ V_137 ++ ] = V_247 . V_258 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_259 )
V_241 [ V_137 ++ ] = V_247 . V_260 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_261 )
V_241 [ V_137 ++ ] = V_247 . V_262 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_263 )
V_241 [ V_137 ++ ] = V_247 . V_264 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
if ( V_247 . V_141 & V_265 )
V_241 [ V_137 ++ ] = V_247 . V_266 ;
else
V_241 [ V_137 ++ ] = - 1LL ;
F_33 ( & V_9 -> V_51 ) ;
if ( F_68 ( V_137 != V_237 ) )
return;
F_72 ( V_12 , V_240 , & ( V_241 [ V_237 ] ) ) ;
}
static void F_73 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_234 , T_3 * V_241 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_267 = 0 ;
if ( V_234 == V_236 ) {
V_267 = sizeof( V_268 ) ;
memcpy ( V_241 , V_268 , V_267 ) ;
}
F_74 ( V_12 , V_234 , & ( V_241 [ V_267 ] ) ) ;
}
static int F_75 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , T_3 * V_269 , struct V_132 * V_133 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_53 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_76 ( V_12 , V_100 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_269 , V_23 -> V_23 . V_270 , V_271 ) ;
F_55 ( V_23 , V_133 ) ;
}
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_77 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , struct V_246 * V_247 )
{
struct V_8 * V_9 = F_78 ( V_18 -> V_272 ) ;
return F_71 ( V_9 , V_100 , V_247 ) ;
}
static int F_79 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_269 , struct V_132 * V_133 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_36 * V_23 ;
int V_19 = - V_53 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_27 ( V_12 , V_269 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_55 ( V_23 , V_133 ) ;
}
F_33 ( & V_9 -> V_51 ) ;
return V_19 ;
}
static int F_80 ( struct V_2 * V_2 ,
struct V_273 * V_274 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_81 ( & V_9 -> V_275 , V_274 ) )
return 0 ;
F_24 ( & V_9 -> V_276 ) ;
if ( V_9 -> V_277 ) {
V_12 = F_82 (
V_9 -> V_278 ,
F_83 ( & V_9 -> V_276 ) ) ;
if ( V_12 ) {
F_84 ( V_12 ) ;
V_19 = F_85 ( V_12 , V_274 ,
V_279 ) ;
}
} else if ( V_9 -> V_280 == V_9 -> V_281 ) {
V_9 -> V_282 = * V_274 ;
F_86 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_275 = * V_274 ;
F_33 ( & V_9 -> V_276 ) ;
return V_19 ;
}
static int F_87 ( struct V_11 * V_12 ,
const T_3 * V_283 , T_5 V_284 )
{
struct V_285 * V_286 , * V_287 ;
if ( ! V_283 || ! V_284 )
return 1 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_285 ) ;
V_286 = F_89 ( sizeof( struct V_285 ) + V_284 , V_289 ) ;
if ( ! V_286 )
return - V_290 ;
V_286 -> V_291 = V_284 ;
memcpy ( V_286 -> V_241 , V_283 , V_284 ) ;
F_90 ( V_12 -> V_15 . V_288 . V_285 , V_286 ) ;
if ( V_287 )
F_91 ( V_287 , V_292 ) ;
return 0 ;
}
int F_92 ( struct V_11 * V_12 ,
struct V_293 * V_7 )
{
struct V_294 * V_286 , * V_287 ;
int V_295 , V_296 ;
int V_297 , V_13 ;
T_1 V_298 = V_299 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( ! V_7 -> V_301 && ! V_287 )
return - V_45 ;
if ( V_7 -> V_301 )
V_295 = V_7 -> V_302 ;
else
V_295 = V_287 -> V_302 ;
if ( V_7 -> V_303 || ! V_287 )
V_296 = V_7 -> V_304 ;
else
V_296 = V_287 -> V_304 ;
V_297 = sizeof( * V_286 ) + V_295 + V_296 ;
V_286 = F_89 ( V_297 , V_289 ) ;
if ( ! V_286 )
return - V_290 ;
V_286 -> V_301 = ( ( T_3 * ) V_286 ) + sizeof( * V_286 ) ;
V_286 -> V_303 = V_286 -> V_301 + V_295 ;
V_286 -> V_302 = V_295 ;
V_286 -> V_304 = V_296 ;
if ( V_7 -> V_301 )
memcpy ( V_286 -> V_301 , V_7 -> V_301 , V_295 ) ;
else
memcpy ( V_286 -> V_301 , V_287 -> V_301 , V_295 ) ;
if ( V_7 -> V_303 )
memcpy ( V_286 -> V_303 , V_7 -> V_303 , V_296 ) ;
else
if ( V_287 )
memcpy ( V_286 -> V_303 , V_287 -> V_303 , V_296 ) ;
V_13 = F_87 ( V_12 , V_7 -> V_285 ,
V_7 -> V_305 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_298 |= V_306 ;
F_90 ( V_12 -> V_15 . V_288 . V_300 , V_286 ) ;
if ( V_287 )
F_91 ( V_287 , V_292 ) ;
return V_298 ;
}
static int F_93 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_307 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_294 * V_287 ;
struct V_11 * V_22 ;
T_1 V_298 = V_308 |
V_309 |
V_299 |
V_310 |
V_311 ;
int V_13 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( V_287 )
return - V_312 ;
V_12 -> V_313 = V_314 ;
V_12 -> V_315 = V_12 -> V_9 -> V_316 ;
V_12 -> V_317 = V_7 -> V_317 ;
V_13 = F_85 ( V_12 , & V_7 -> V_274 ,
V_318 ) ;
if ( V_13 )
return V_13 ;
F_94 ( V_12 , false ) ;
V_12 -> V_319 = V_7 -> V_320 . V_321 ;
V_12 -> V_322 = V_7 -> V_320 . V_322 ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_319 =
V_7 -> V_320 . V_321 ;
V_22 -> V_322 =
V_7 -> V_320 . V_322 ;
}
V_12 -> V_26 . V_209 . V_219 = V_7 -> V_218 ;
V_12 -> V_26 . V_209 . V_216 = V_7 -> V_216 ;
V_12 -> V_26 . V_209 . V_323 = true ;
V_12 -> V_26 . V_209 . V_324 = V_7 -> V_324 ;
if ( V_7 -> V_324 )
memcpy ( V_12 -> V_26 . V_209 . V_325 , V_7 -> V_325 ,
V_7 -> V_324 ) ;
V_12 -> V_26 . V_209 . V_326 =
( V_7 -> V_326 != V_327 ) ;
memset ( & V_12 -> V_26 . V_209 . V_328 , 0 ,
sizeof( V_12 -> V_26 . V_209 . V_328 ) ) ;
V_12 -> V_26 . V_209 . V_328 . V_329 =
V_7 -> V_330 & V_331 ;
if ( V_7 -> V_332 )
V_12 -> V_26 . V_209 . V_328 . V_329 |=
V_333 ;
V_13 = F_92 ( V_12 , & V_7 -> V_300 ) ;
if ( V_13 < 0 )
return V_13 ;
V_298 |= V_13 ;
V_13 = F_95 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( V_287 )
F_91 ( V_287 , V_292 ) ;
F_11 ( V_12 -> V_15 . V_288 . V_300 , NULL ) ;
return V_13 ;
}
F_96 ( V_12 , V_298 ) ;
F_97 ( V_18 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_97 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_98 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_293 * V_7 )
{
struct V_11 * V_12 ;
struct V_294 * V_287 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
if ( V_12 -> V_26 . V_334 )
return - V_30 ;
V_287 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( ! V_287 )
return - V_53 ;
V_13 = F_92 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_96 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_11 * V_22 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_294 * V_335 ;
struct V_285 * V_336 ;
V_335 = F_88 ( V_12 -> V_15 . V_288 . V_300 ) ;
if ( ! V_335 )
return - V_53 ;
V_336 = F_88 ( V_12 -> V_15 . V_288 . V_285 ) ;
V_12 -> V_26 . V_334 = false ;
F_100 ( & V_12 -> V_337 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_101 ( V_22 -> V_18 ) ;
F_101 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_288 . V_300 , NULL ) ;
F_11 ( V_12 -> V_15 . V_288 . V_285 , NULL ) ;
F_91 ( V_335 , V_292 ) ;
if ( V_336 )
F_91 ( V_336 , V_292 ) ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_102 ( V_22 ) ;
F_102 ( V_12 ) ;
F_103 () ;
F_104 () ;
F_70 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
F_105 ( V_22 ) ;
F_106 ( V_22 ) ;
}
F_105 ( V_12 ) ;
F_106 ( V_12 ) ;
V_12 -> V_26 . V_209 . V_323 = false ;
V_12 -> V_26 . V_209 . V_324 = 0 ;
F_107 ( V_338 , & V_12 -> V_339 ) ;
F_96 ( V_12 , V_309 ) ;
if ( V_12 -> V_10 . V_340 ) {
F_108 ( & V_12 -> V_341 ) ;
F_109 ( V_12 -> V_18 , V_342 ,
V_289 ) ;
}
F_110 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_343 -= F_111 ( & V_12 -> V_15 . V_288 . V_344 . V_345 ) ;
F_112 ( & V_12 -> V_15 . V_288 . V_344 . V_345 ) ;
F_94 ( V_12 , true ) ;
F_84 ( V_12 ) ;
return 0 ;
}
static void F_113 ( struct V_36 * V_23 )
{
struct V_346 * V_347 ;
struct V_348 * V_349 ;
V_349 = F_114 ( sizeof( * V_347 ) ) ;
if ( ! V_349 )
return;
V_347 = (struct V_346 * ) F_115 ( V_349 , sizeof( * V_347 ) ) ;
F_116 ( V_347 -> V_350 ) ;
memcpy ( V_347 -> V_351 , V_23 -> V_23 . V_270 , V_271 ) ;
V_347 -> V_291 = F_117 ( 6 ) ;
V_347 -> V_352 = 0 ;
V_347 -> V_353 = 0x01 ;
V_347 -> V_354 = 0xaf ;
V_347 -> V_355 [ 0 ] = 0x81 ;
V_347 -> V_355 [ 1 ] = 1 ;
V_347 -> V_355 [ 2 ] = 0 ;
V_349 -> V_18 = V_23 -> V_12 -> V_18 ;
V_349 -> V_356 = F_118 ( V_349 , V_23 -> V_12 -> V_18 ) ;
memset ( V_349 -> V_357 , 0 , sizeof( V_349 -> V_357 ) ) ;
F_119 ( V_349 ) ;
}
static int F_120 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
T_1 V_27 , T_1 V_221 )
{
int V_19 ;
if ( V_27 & F_62 ( V_226 ) &&
V_221 & F_62 ( V_226 ) &&
! F_28 ( V_23 , V_232 ) ) {
V_19 = F_121 ( V_23 , V_358 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_227 ) &&
V_221 & F_62 ( V_227 ) &&
! F_28 ( V_23 , V_52 ) ) {
V_19 = F_121 ( V_23 , V_359 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_222 ) ) {
if ( V_221 & F_62 ( V_222 ) )
V_19 = F_121 ( V_23 , V_360 ) ;
else if ( F_28 ( V_23 , V_229 ) )
V_19 = F_121 ( V_23 , V_359 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_227 ) &&
! ( V_221 & F_62 ( V_227 ) ) &&
F_28 ( V_23 , V_52 ) ) {
V_19 = F_121 ( V_23 , V_358 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_27 & F_62 ( V_226 ) &&
! ( V_221 & F_62 ( V_226 ) ) &&
F_28 ( V_23 , V_232 ) ) {
V_19 = F_121 ( V_23 , V_361 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_122 ( struct V_8 * V_9 ,
struct V_36 * V_23 ,
struct V_362 * V_7 )
{
int V_19 = 0 ;
struct V_104 * V_105 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_363 V_364 = F_52 ( V_12 ) ;
T_1 V_27 , V_221 ;
V_105 = V_9 -> V_108 . V_2 -> V_109 [ V_364 ] ;
V_27 = V_7 -> V_365 ;
V_221 = V_7 -> V_366 ;
if ( F_25 ( & V_12 -> V_26 ) ) {
if ( V_27 & F_62 ( V_226 ) )
V_27 |= F_62 ( V_227 ) ;
if ( V_221 & F_62 ( V_226 ) )
V_221 |= F_62 ( V_227 ) ;
} else if ( F_28 ( V_23 , V_233 ) ) {
if ( V_221 & F_62 ( V_222 ) ) {
V_221 |= F_62 ( V_226 ) |
F_62 ( V_227 ) ;
V_27 |= F_62 ( V_226 ) |
F_62 ( V_227 ) ;
}
}
V_19 = F_120 ( V_9 , V_23 , V_27 , V_221 ) ;
if ( V_19 )
return V_19 ;
if ( V_27 & F_62 ( V_223 ) ) {
if ( V_221 & F_62 ( V_223 ) )
F_123 ( V_23 , V_230 ) ;
else
F_124 ( V_23 , V_230 ) ;
}
if ( V_27 & F_62 ( V_224 ) ) {
if ( V_221 & F_62 ( V_224 ) ) {
F_123 ( V_23 , V_231 ) ;
V_23 -> V_23 . V_367 = true ;
} else {
F_124 ( V_23 , V_231 ) ;
V_23 -> V_23 . V_367 = false ;
}
}
if ( V_27 & F_62 ( V_225 ) ) {
if ( V_221 & F_62 ( V_225 ) )
F_123 ( V_23 , V_59 ) ;
else
F_124 ( V_23 , V_59 ) ;
}
if ( V_27 & F_62 ( V_228 ) ) {
if ( V_221 & F_62 ( V_228 ) )
F_123 ( V_23 , V_233 ) ;
else
F_124 ( V_23 , V_233 ) ;
}
if ( V_7 -> V_368 & V_369 ) {
V_23 -> V_23 . V_370 = V_7 -> V_370 ;
V_23 -> V_23 . V_371 = V_7 -> V_371 ;
}
if ( V_7 -> V_372 )
V_23 -> V_23 . V_372 = V_7 -> V_372 ;
if ( V_7 -> V_373 >= 0 )
V_23 -> V_373 = V_7 -> V_373 ;
if ( V_7 -> V_374 ) {
F_125 ( & V_12 -> V_26 . V_209 . V_274 ,
V_105 , V_7 -> V_374 ,
V_7 -> V_375 ,
& V_23 -> V_23 . V_376 [ V_364 ] ) ;
}
if ( V_7 -> V_377 )
F_126 ( V_12 , V_105 ,
V_7 -> V_377 , V_23 ) ;
if ( V_7 -> V_378 )
F_127 ( V_12 , V_105 ,
V_7 -> V_378 , V_23 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
T_1 V_298 = 0 ;
if ( V_7 -> V_368 & V_379 ) {
switch ( V_7 -> V_201 ) {
case V_380 :
if ( V_23 -> V_201 != V_380 )
V_298 = F_128 (
V_12 ) ;
V_23 -> V_201 = V_7 -> V_201 ;
F_129 ( V_23 ) ;
V_298 |= F_130 ( V_23 ,
V_12 -> V_15 . V_62 . V_381 . V_382 ) ;
break;
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
if ( V_23 -> V_201 == V_380 )
V_298 = F_131 (
V_12 ) ;
V_23 -> V_201 = V_7 -> V_201 ;
F_129 ( V_23 ) ;
V_298 |=
F_132 ( V_12 ) ;
break;
default:
break;
}
}
switch ( V_7 -> V_389 ) {
case V_390 :
break;
case V_391 :
V_298 |= F_133 ( V_23 ) ;
break;
case V_392 :
V_298 |= F_134 ( V_23 ) ;
break;
}
if ( V_7 -> V_205 )
V_298 |=
F_130 ( V_23 ,
V_7 -> V_205 ) ;
F_96 ( V_12 , V_298 ) ;
#endif
}
return 0 ;
}
static int F_135 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_269 , struct V_362 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_393 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_58 )
return - V_45 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_136 ( V_269 , V_12 -> V_26 . V_270 ) )
return - V_45 ;
if ( F_137 ( V_269 ) )
return - V_45 ;
V_23 = F_138 ( V_12 , V_269 , V_289 ) ;
if ( ! V_23 )
return - V_290 ;
if ( ! ( V_7 -> V_366 & F_62 ( V_228 ) ) ) {
F_139 ( V_23 , V_358 ) ;
F_139 ( V_23 , V_359 ) ;
}
V_13 = F_122 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_140 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_28 ( V_23 , V_233 ) )
F_141 ( V_23 ) ;
V_393 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_58 ;
V_13 = F_142 ( V_23 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
if ( V_393 )
F_113 ( V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_269 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_269 )
return F_144 ( V_12 , V_269 ) ;
F_145 ( V_12 ) ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_3 * V_269 ,
struct V_362 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_36 * V_23 ;
struct V_11 * V_394 ;
enum V_395 V_396 ;
int V_13 ;
F_24 ( & V_9 -> V_51 ) ;
V_23 = F_27 ( V_12 , V_269 ) ;
if ( ! V_23 ) {
V_13 = - V_53 ;
goto V_397;
}
switch ( V_12 -> V_26 . type ) {
case V_61 :
if ( V_12 -> V_15 . V_62 . V_398 )
V_396 = V_399 ;
else
V_396 = V_400 ;
break;
case V_60 :
V_396 = V_401 ;
break;
case V_24 :
if ( ! F_28 ( V_23 , V_233 ) ) {
V_396 = V_402 ;
break;
}
if ( F_28 ( V_23 , V_229 ) )
V_396 = V_403 ;
else
V_396 = V_404 ;
break;
case V_58 :
case V_20 :
V_396 = V_405 ;
break;
default:
V_13 = - V_238 ;
goto V_397;
}
V_13 = F_147 ( V_2 , V_7 , V_396 ) ;
if ( V_13 )
goto V_397;
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_406 = false ;
bool V_407 = false ;
V_394 = F_9 ( V_7 -> V_22 ) ;
if ( V_7 -> V_22 -> V_272 -> V_21 ) {
if ( V_394 -> V_15 . V_22 . V_23 ) {
V_13 = - V_30 ;
goto V_397;
}
F_90 ( V_394 -> V_15 . V_22 . V_23 , V_23 ) ;
V_407 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_90 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_406 = true ;
}
V_23 -> V_12 = V_394 ;
if ( V_23 -> V_251 == V_360 &&
V_406 != V_407 ) {
if ( V_407 )
F_148 ( & V_23 -> V_12 -> V_408 -> V_409 ) ;
else
F_149 ( & V_23 -> V_12 -> V_408 -> V_409 ) ;
}
F_113 ( V_23 ) ;
}
V_13 = F_122 ( V_9 , V_23 , V_7 ) ;
if ( V_13 )
goto V_397;
if ( F_28 ( V_23 , V_233 ) &&
F_28 ( V_23 , V_229 ) )
F_141 ( V_23 ) ;
F_33 ( & V_9 -> V_51 ) ;
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_365 & F_62 ( V_222 ) ) {
F_150 ( V_9 , - 1 ) ;
F_151 ( V_12 ) ;
}
return 0 ;
V_397:
F_33 ( & V_9 -> V_51 ) ;
return V_13 ;
}
static int F_152 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_410 , T_3 * V_411 )
{
struct V_11 * V_12 ;
struct V_412 * V_413 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_411 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_53 ;
}
V_413 = F_153 ( V_12 , V_410 ) ;
if ( F_21 ( V_413 ) ) {
F_43 () ;
return F_23 ( V_413 ) ;
}
F_154 ( V_413 , V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_410 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_410 )
return F_156 ( V_12 , V_410 ) ;
F_157 ( V_12 ) ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_410 , T_3 * V_411 )
{
struct V_11 * V_12 ;
struct V_412 * V_413 ;
struct V_36 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_411 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_53 ;
}
V_413 = F_159 ( V_12 , V_410 ) ;
if ( ! V_413 ) {
F_43 () ;
return - V_53 ;
}
F_154 ( V_413 , V_23 ) ;
F_43 () ;
return 0 ;
}
static void F_160 ( struct V_412 * V_413 , T_3 * V_411 ,
struct V_414 * V_415 )
{
struct V_36 * V_416 = F_40 ( V_413 -> V_411 ) ;
if ( V_416 )
memcpy ( V_411 , V_416 -> V_23 . V_270 , V_271 ) ;
else
memset ( V_411 , 0 , V_271 ) ;
memset ( V_415 , 0 , sizeof( * V_415 ) ) ;
V_415 -> V_139 = V_417 ;
V_415 -> V_141 = V_418 |
V_419 |
V_420 |
V_421 |
V_422 |
V_423 |
V_424 ;
V_415 -> V_425 = V_413 -> V_426 . V_427 ;
V_415 -> V_428 = V_413 -> V_428 ;
V_415 -> V_429 = V_413 -> V_429 ;
if ( F_161 ( V_160 , V_413 -> V_430 ) )
V_415 -> V_431 = F_57 ( V_413 -> V_430 - V_160 ) ;
V_415 -> V_432 =
F_57 ( V_413 -> V_432 ) ;
V_415 -> V_433 = V_413 -> V_433 ;
if ( V_413 -> V_5 & V_434 )
V_415 -> V_5 |= V_435 ;
if ( V_413 -> V_5 & V_436 )
V_415 -> V_5 |= V_437 ;
if ( V_413 -> V_5 & V_438 )
V_415 -> V_5 |= V_439 ;
if ( V_413 -> V_5 & V_440 )
V_415 -> V_5 |= V_441 ;
if ( V_413 -> V_5 & V_442 )
V_415 -> V_5 |= V_443 ;
}
static int F_162 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_410 , T_3 * V_411 , struct V_414 * V_415 )
{
struct V_11 * V_12 ;
struct V_412 * V_413 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_413 = F_159 ( V_12 , V_410 ) ;
if ( ! V_413 ) {
F_43 () ;
return - V_53 ;
}
memcpy ( V_410 , V_413 -> V_410 , V_271 ) ;
F_160 ( V_413 , V_411 , V_415 ) ;
F_43 () ;
return 0 ;
}
static int F_163 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_100 , T_3 * V_410 , T_3 * V_411 ,
struct V_414 * V_415 )
{
struct V_11 * V_12 ;
struct V_412 * V_413 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_413 = F_164 ( V_12 , V_100 ) ;
if ( ! V_413 ) {
F_43 () ;
return - V_53 ;
}
memcpy ( V_410 , V_413 -> V_410 , V_271 ) ;
F_160 ( V_413 , V_411 , V_415 ) ;
F_43 () ;
return 0 ;
}
static int F_165 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_444 * V_49 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_49 , & ( V_12 -> V_15 . V_62 . V_381 ) , sizeof( struct V_444 ) ) ;
return 0 ;
}
static inline bool F_166 ( enum V_445 V_446 , T_1 V_27 )
{
return ( V_27 >> ( V_446 - 1 ) ) & 0x1 ;
}
static int F_167 ( struct V_447 * V_448 ,
const struct V_449 * V_450 )
{
T_3 * V_451 ;
const T_3 * V_452 ;
struct V_11 * V_12 = F_168 ( V_448 ,
struct V_11 , V_15 . V_62 ) ;
V_451 = NULL ;
V_452 = V_448 -> V_453 ;
if ( V_450 -> V_454 ) {
V_451 = F_169 ( V_450 -> V_453 , V_450 -> V_454 ,
V_289 ) ;
if ( ! V_451 )
return - V_290 ;
}
V_448 -> V_454 = V_450 -> V_454 ;
V_448 -> V_453 = V_451 ;
F_170 ( V_452 ) ;
V_448 -> V_455 = V_450 -> V_455 ;
memcpy ( V_448 -> V_456 , V_450 -> V_456 , V_448 -> V_455 ) ;
V_448 -> V_457 = V_450 -> V_458 ;
V_448 -> V_459 = V_450 -> V_460 ;
V_448 -> V_461 = V_450 -> V_462 ;
V_448 -> V_398 = V_450 -> V_398 ;
V_448 -> V_463 = V_450 -> V_464 ;
V_448 -> V_63 = V_64 ;
if ( V_450 -> V_465 )
V_448 -> V_63 |= V_466 ;
if ( V_450 -> V_467 )
V_448 -> V_63 |= V_468 ;
memcpy ( V_12 -> V_26 . V_209 . V_469 , V_450 -> V_469 ,
sizeof( V_450 -> V_469 ) ) ;
V_12 -> V_26 . V_209 . V_470 = V_450 -> V_470 ;
V_12 -> V_26 . V_209 . V_219 = V_450 -> V_218 ;
V_12 -> V_26 . V_209 . V_216 = V_450 -> V_216 ;
return 0 ;
}
static int F_171 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_27 ,
const struct V_444 * V_471 )
{
struct V_444 * V_49 ;
struct V_11 * V_12 ;
struct V_447 * V_448 ;
V_12 = F_9 ( V_18 ) ;
V_448 = & V_12 -> V_15 . V_62 ;
V_49 = & ( V_12 -> V_15 . V_62 . V_381 ) ;
if ( F_166 ( V_472 , V_27 ) )
V_49 -> V_473 = V_471 -> V_473 ;
if ( F_166 ( V_474 , V_27 ) )
V_49 -> V_475 = V_471 -> V_475 ;
if ( F_166 ( V_476 , V_27 ) )
V_49 -> V_477 = V_471 -> V_477 ;
if ( F_166 ( V_478 , V_27 ) )
V_49 -> V_479 = V_471 -> V_479 ;
if ( F_166 ( V_480 , V_27 ) )
V_49 -> V_481 = V_471 -> V_481 ;
if ( F_166 ( V_482 , V_27 ) )
V_49 -> V_483 = V_471 -> V_483 ;
if ( F_166 ( V_484 , V_27 ) )
V_49 -> V_485 = V_471 -> V_485 ;
if ( F_166 ( V_486 , V_27 ) ) {
if ( V_448 -> V_398 )
return - V_30 ;
V_49 -> V_487 = V_471 -> V_487 ;
}
if ( F_166 ( V_488 , V_27 ) )
V_49 -> V_489 =
V_471 -> V_489 ;
if ( F_166 ( V_490 , V_27 ) )
V_49 -> V_491 =
V_471 -> V_491 ;
if ( F_166 ( V_492 , V_27 ) )
V_49 -> V_493 = V_471 -> V_493 ;
if ( F_166 ( V_494 , V_27 ) )
V_49 -> V_495 = V_471 -> V_495 ;
if ( F_166 ( V_496 , V_27 ) )
V_49 -> V_497 =
V_471 -> V_497 ;
if ( F_166 ( V_498 , V_27 ) )
V_49 -> V_499 =
V_471 -> V_499 ;
if ( F_166 ( V_500 , V_27 ) )
V_49 -> V_501 =
V_471 -> V_501 ;
if ( F_166 ( V_502 ,
V_27 ) )
V_49 -> V_503 =
V_471 -> V_503 ;
if ( F_166 ( V_504 , V_27 ) ) {
V_49 -> V_505 = V_471 -> V_505 ;
F_172 ( V_448 ) ;
}
if ( F_166 ( V_506 , V_27 ) ) {
if ( V_471 -> V_507 &&
! ( V_49 -> V_505 > V_508 ) ) {
V_49 -> V_505 = V_509 ;
F_172 ( V_448 ) ;
}
V_49 -> V_507 =
V_471 -> V_507 ;
}
if ( F_166 ( V_510 , V_27 ) )
V_49 -> V_511 =
V_471 -> V_511 ;
if ( F_166 ( V_512 , V_27 ) )
V_49 -> V_513 = V_471 -> V_513 ;
if ( F_166 ( V_514 , V_27 ) ) {
if ( ! ( V_12 -> V_9 -> V_108 . V_5 & V_174 ) )
return - V_515 ;
V_49 -> V_516 = V_471 -> V_516 ;
}
if ( F_166 ( V_517 , V_27 ) ) {
V_49 -> V_518 = V_471 -> V_518 ;
V_12 -> V_26 . V_209 . V_519 = V_471 -> V_518 ;
F_96 ( V_12 , V_520 ) ;
}
if ( F_166 ( V_521 , V_27 ) )
V_49 -> V_522 =
V_471 -> V_522 ;
if ( F_166 ( V_523 , V_27 ) )
V_49 -> V_524 =
V_471 -> V_524 ;
if ( F_166 ( V_525 , V_27 ) )
V_49 -> V_526 =
V_471 -> V_526 ;
if ( F_166 ( V_527 , V_27 ) ) {
V_49 -> V_382 = V_471 -> V_382 ;
F_132 ( V_12 ) ;
}
if ( F_166 ( V_528 , V_27 ) )
V_49 -> V_529 =
V_471 -> V_529 ;
if ( F_166 ( V_530 , V_27 ) )
V_49 -> V_531 = V_471 -> V_531 ;
F_173 ( V_12 , V_299 ) ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_444 * V_49 ,
const struct V_449 * V_450 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_447 * V_448 = & V_12 -> V_15 . V_62 ;
int V_13 ;
memcpy ( & V_448 -> V_381 , V_49 , sizeof( struct V_444 ) ) ;
V_13 = F_167 ( V_448 , V_450 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_313 = V_314 ;
V_12 -> V_315 = V_12 -> V_9 -> V_316 ;
V_13 = F_85 ( V_12 , & V_450 -> V_274 ,
V_318 ) ;
if ( V_13 )
return V_13 ;
return F_175 ( V_12 ) ;
}
static int F_176 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_177 ( V_12 ) ;
F_84 ( V_12 ) ;
return 0 ;
}
static int F_178 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_532 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_363 V_364 ;
T_1 V_298 = 0 ;
if ( ! F_88 ( V_12 -> V_15 . V_288 . V_300 ) )
return - V_53 ;
V_364 = F_52 ( V_12 ) ;
if ( V_7 -> V_210 >= 0 ) {
V_12 -> V_26 . V_209 . V_210 = V_7 -> V_210 ;
V_298 |= V_533 ;
}
if ( V_7 -> V_212 >= 0 ) {
V_12 -> V_26 . V_209 . V_212 =
V_7 -> V_212 ;
V_298 |= V_534 ;
}
if ( ! V_12 -> V_26 . V_209 . V_214 &&
V_364 == V_535 ) {
V_12 -> V_26 . V_209 . V_214 = true ;
V_298 |= V_536 ;
}
if ( V_7 -> V_537 >= 0 ) {
V_12 -> V_26 . V_209 . V_214 =
V_7 -> V_537 ;
V_298 |= V_536 ;
}
if ( V_7 -> V_470 ) {
F_125 ( & V_12 -> V_26 . V_209 . V_274 ,
V_2 -> V_109 [ V_364 ] ,
V_7 -> V_470 ,
V_7 -> V_538 ,
& V_12 -> V_26 . V_209 . V_470 ) ;
V_298 |= V_539 ;
}
if ( V_7 -> V_540 >= 0 ) {
if ( V_7 -> V_540 )
V_12 -> V_5 |= V_541 ;
else
V_12 -> V_5 &= ~ V_541 ;
}
if ( V_7 -> V_518 >= 0 ) {
V_12 -> V_26 . V_209 . V_519 =
( T_2 ) V_7 -> V_518 ;
V_298 |= V_520 ;
}
if ( V_7 -> V_330 >= 0 ) {
V_12 -> V_26 . V_209 . V_328 . V_329 &=
~ V_331 ;
V_12 -> V_26 . V_209 . V_328 . V_329 |=
V_7 -> V_330 & V_331 ;
V_298 |= V_311 ;
}
if ( V_7 -> V_332 > 0 ) {
V_12 -> V_26 . V_209 . V_328 . V_329 |=
V_333 ;
V_298 |= V_311 ;
} else if ( V_7 -> V_332 == 0 ) {
V_12 -> V_26 . V_209 . V_328 . V_329 &=
~ V_333 ;
V_298 |= V_311 ;
}
F_96 ( V_12 , V_298 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_542 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_543 V_544 ;
if ( ! V_9 -> V_178 -> V_545 )
return - V_238 ;
if ( V_9 -> V_108 . V_546 < V_163 )
return - V_238 ;
memset ( & V_544 , 0 , sizeof( V_544 ) ) ;
V_544 . V_547 = V_7 -> V_547 ;
V_544 . V_548 = V_7 -> V_549 ;
V_544 . V_550 = V_7 -> V_551 ;
V_544 . V_552 = V_7 -> V_552 ;
V_544 . V_553 = false ;
V_12 -> V_554 [ V_7 -> V_138 ] = V_544 ;
if ( F_180 ( V_9 , V_12 , V_7 -> V_138 , & V_544 ) ) {
F_181 ( V_9 -> V_108 . V_2 ,
L_1 ,
V_7 -> V_138 ) ;
return - V_45 ;
}
F_96 ( V_12 , V_555 ) ;
return 0 ;
}
static int F_182 ( struct V_2 * V_2 ,
struct V_556 * V_557 )
{
return F_183 ( F_2 ( V_2 ) , V_557 ) ;
}
static int F_184 ( struct V_2 * V_2 )
{
return F_185 ( F_2 ( V_2 ) ) ;
}
static int F_186 ( struct V_2 * V_2 ,
struct V_558 * V_559 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_559 -> V_10 ) ;
switch ( F_187 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_60 :
case V_61 :
case V_69 :
case V_66 :
break;
case V_70 :
if ( V_12 -> V_9 -> V_178 -> V_560 )
break;
case V_58 :
if ( V_12 -> V_15 . V_288 . V_300 &&
( ! ( V_2 -> V_561 & V_562 ) ||
! ( V_559 -> V_5 & V_563 ) ) )
return - V_238 ;
break;
default:
return - V_238 ;
}
return F_188 ( V_12 , V_559 ) ;
}
static int
F_189 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_564 * V_559 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_178 -> V_565 )
return - V_238 ;
return F_190 ( V_12 , V_559 ) ;
}
static int
F_191 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_178 -> V_566 )
return - V_238 ;
return F_192 ( V_12 ) ;
}
static int F_193 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_567 * V_559 )
{
return F_194 ( F_9 ( V_18 ) , V_559 ) ;
}
static int F_195 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_568 * V_559 )
{
return F_196 ( F_9 ( V_18 ) , V_559 ) ;
}
static int F_197 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_569 * V_559 )
{
return F_198 ( F_9 ( V_18 ) , V_559 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_570 * V_559 )
{
return F_200 ( F_9 ( V_18 ) , V_559 ) ;
}
static int F_201 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_571 * V_7 )
{
return F_202 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_203 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_204 ( F_9 ( V_18 ) ) ;
}
static int F_205 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_94 [ V_572 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_209 . V_469 , V_94 ,
sizeof( int ) * V_572 ) ;
return 0 ;
}
static int F_206 ( struct V_2 * V_2 , T_1 V_298 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_298 & V_573 ) {
V_13 = F_207 ( V_9 , V_2 -> V_574 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_298 & V_575 ) {
V_13 = F_208 ( V_9 , V_2 -> V_576 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_298 & V_577 ) {
V_13 = F_209 ( V_9 , V_2 -> V_578 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_298 & V_579 ) {
if ( V_2 -> V_580 > V_581 )
return - V_45 ;
V_9 -> V_108 . V_49 . V_582 = V_2 -> V_580 ;
}
if ( V_298 & V_583 ) {
if ( V_2 -> V_584 > V_581 )
return - V_45 ;
V_9 -> V_108 . V_49 . V_585 = V_2 -> V_584 ;
}
if ( V_298 &
( V_579 | V_583 ) )
F_86 ( V_9 , V_586 ) ;
return 0 ;
}
static int F_210 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_587 type , int V_588 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_589 :
V_12 -> V_590 = V_591 ;
break;
case V_592 :
case V_593 :
if ( V_588 < 0 || ( V_588 % 100 ) )
return - V_238 ;
V_12 -> V_590 = F_211 ( V_588 ) ;
break;
}
F_212 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_589 :
V_9 -> V_590 = V_591 ;
break;
case V_592 :
case V_593 :
if ( V_588 < 0 || ( V_588 % 100 ) )
return - V_238 ;
V_9 -> V_590 = F_211 ( V_588 ) ;
break;
}
F_24 ( & V_9 -> V_276 ) ;
F_70 (sdata, &local->interfaces, list)
V_12 -> V_590 = V_9 -> V_590 ;
F_70 (sdata, &local->interfaces, list)
F_212 ( V_12 ) ;
F_33 ( & V_9 -> V_276 ) ;
return 0 ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_594 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_277 )
* V_594 = V_9 -> V_108 . V_49 . V_595 ;
else
* V_594 = V_12 -> V_26 . V_209 . V_596 ;
return 0 ;
}
static int F_214 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_270 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_597 . V_598 , V_270 , V_271 ) ;
return 0 ;
}
static void F_215 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_216 ( V_9 ) ;
}
static int F_217 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
void * V_241 , int V_291 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_599 * V_26 = NULL ;
if ( ! V_9 -> V_178 -> V_600 )
return - V_238 ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_5 & V_601 )
V_26 = & V_12 -> V_26 ;
}
return V_9 -> V_178 -> V_600 ( & V_9 -> V_108 , V_26 , V_241 , V_291 ) ;
}
static int F_218 ( struct V_2 * V_2 ,
struct V_348 * V_349 ,
struct V_602 * V_357 ,
void * V_241 , int V_291 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_178 -> V_603 )
return - V_238 ;
return V_9 -> V_178 -> V_603 ( & V_9 -> V_108 , V_349 , V_357 , V_241 , V_291 ) ;
}
int F_219 ( struct V_11 * V_12 ,
enum V_604 V_313 )
{
const T_3 * V_288 ;
enum V_604 V_605 ;
int V_13 ;
F_220 ( & V_12 -> V_10 . V_606 ) ;
V_605 = V_12 -> V_15 . V_25 . V_607 ;
V_12 -> V_15 . V_25 . V_607 = V_313 ;
if ( V_605 == V_313 &&
V_313 != V_608 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_609 ||
V_12 -> V_26 . V_209 . V_274 . V_610 == V_611 )
return 0 ;
V_288 = V_12 -> V_15 . V_25 . V_609 -> V_249 ;
if ( V_313 == V_608 ) {
if ( V_12 -> V_15 . V_25 . V_612 )
V_313 = V_613 ;
else
V_313 = V_314 ;
}
V_13 = F_221 ( V_12 , V_313 ,
V_288 , V_288 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_607 = V_605 ;
return V_13 ;
}
static int F_222 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_614 , int V_615 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_272 ) ;
if ( V_12 -> V_26 . type != V_24 &&
V_12 -> V_26 . type != V_61 )
return - V_238 ;
if ( ! ( V_9 -> V_108 . V_5 & V_616 ) )
return - V_238 ;
if ( V_614 == V_12 -> V_15 . V_25 . V_612 &&
V_615 == V_9 -> V_617 )
return 0 ;
V_12 -> V_15 . V_25 . V_612 = V_614 ;
V_9 -> V_617 = V_615 ;
F_223 ( V_12 ) ;
F_219 ( V_12 , V_12 -> V_15 . V_25 . V_607 ) ;
F_224 ( V_12 ) ;
if ( V_9 -> V_108 . V_5 & V_618 )
F_86 ( V_9 , V_619 ) ;
F_150 ( V_9 , - 1 ) ;
F_151 ( V_12 ) ;
return 0 ;
}
static int F_225 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_620 , T_1 V_621 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_599 * V_26 = & V_12 -> V_26 ;
struct V_622 * V_209 = & V_26 -> V_209 ;
if ( V_620 == V_209 -> V_623 &&
V_621 == V_209 -> V_624 )
return 0 ;
V_209 -> V_623 = V_620 ;
V_209 -> V_624 = V_621 ;
if ( V_12 -> V_15 . V_25 . V_609 &&
V_12 -> V_26 . V_625 & V_626 )
F_96 ( V_12 , V_627 ) ;
return 0 ;
}
static int F_226 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_270 ,
const struct V_628 * V_27 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_78 ( V_18 -> V_272 ) ;
int V_137 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_39 ;
if ( V_9 -> V_108 . V_5 & V_629 ) {
V_19 = F_227 ( V_9 , V_12 , V_27 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_137 = 0 ; V_137 < V_572 ; V_137 ++ ) {
struct V_104 * V_105 = V_2 -> V_109 [ V_137 ] ;
int V_630 ;
V_12 -> V_631 [ V_137 ] = V_27 -> V_354 [ V_137 ] . V_112 ;
memcpy ( V_12 -> V_632 [ V_137 ] , V_27 -> V_354 [ V_137 ] . V_99 ,
sizeof( V_27 -> V_354 [ V_137 ] . V_99 ) ) ;
V_12 -> V_633 [ V_137 ] = false ;
if ( ! V_105 )
continue;
for ( V_630 = 0 ; V_630 < V_634 ; V_630 ++ )
if ( ~ V_12 -> V_632 [ V_137 ] [ V_630 ] ) {
V_12 -> V_633 [ V_137 ] = true ;
break;
}
}
return 0 ;
}
static int F_228 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_244 * V_245 ,
unsigned int V_635 , T_4 * V_75 ,
struct V_348 * V_636 ,
enum V_637 type )
{
struct V_638 * V_639 , * V_640 ;
bool V_641 = false ;
int V_19 ;
F_220 ( & V_9 -> V_606 ) ;
if ( V_9 -> V_277 && ! V_9 -> V_178 -> V_642 )
return - V_238 ;
V_639 = F_89 ( sizeof( * V_639 ) , V_289 ) ;
if ( ! V_639 )
return - V_290 ;
V_639 -> V_253 = V_245 ;
V_639 -> V_635 = V_635 ;
V_639 -> V_643 = V_635 ;
V_639 -> V_644 = V_636 ;
V_639 -> type = type ;
V_639 -> V_645 = ( unsigned long ) V_636 ;
V_639 -> V_12 = V_12 ;
F_229 ( & V_639 -> V_646 , V_647 ) ;
F_230 ( & V_639 -> V_648 ) ;
if ( ! F_231 ( & V_9 -> V_649 ) ||
V_9 -> V_650 || V_9 -> V_651 )
goto V_652;
if ( ! V_9 -> V_178 -> V_642 ) {
F_232 ( & V_9 -> V_108 , & V_639 -> V_646 , 0 ) ;
goto V_653;
}
if ( ! V_635 )
V_635 = 10 ;
V_19 = F_233 ( V_9 , V_12 , V_245 , V_635 , type ) ;
if ( V_19 ) {
F_170 ( V_639 ) ;
return V_19 ;
}
V_639 -> V_654 = true ;
goto V_653;
V_652:
F_70 (tmp, &local->roc_list, list) {
if ( V_640 -> V_253 != V_245 || V_640 -> V_12 != V_12 )
continue;
if ( ! V_640 -> V_654 ) {
F_234 ( & V_639 -> V_655 , & V_640 -> V_648 ) ;
V_640 -> V_635 = F_235 ( V_640 -> V_635 , V_639 -> V_635 ) ;
V_640 -> type = F_235 ( V_640 -> type , V_639 -> type ) ;
V_641 = true ;
break;
}
if ( V_9 -> V_178 -> V_642 ) {
unsigned long V_630 = V_160 ;
if ( ! V_640 -> V_656 ) {
F_234 ( & V_639 -> V_655 , & V_640 -> V_648 ) ;
V_641 = true ;
break;
}
if ( F_161 ( V_630 + V_657 ,
V_640 -> V_658 +
F_236 ( V_640 -> V_635 ) ) ) {
int V_659 ;
F_237 ( V_639 ) ;
V_659 = V_639 -> V_635 -
F_57 ( V_640 -> V_658 +
F_236 (
V_640 -> V_635 ) -
V_630 ) ;
if ( V_659 > 0 ) {
F_238 ( & V_639 -> V_655 , & V_640 -> V_655 ) ;
} else {
F_234 ( & V_639 -> V_655 ,
& V_640 -> V_648 ) ;
}
V_641 = true ;
}
} else if ( F_239 ( & V_640 -> V_646 . V_660 ) ) {
unsigned long V_661 ;
F_234 ( & V_639 -> V_655 , & V_640 -> V_648 ) ;
V_641 = true ;
V_661 = V_160 + F_236 ( V_639 -> V_635 ) ;
if ( F_240 ( V_661 , V_640 -> V_646 . V_660 . V_662 ) )
F_241 ( & V_640 -> V_646 . V_660 , V_661 ) ;
else
F_242 ( & V_640 -> V_646 . V_660 ) ;
F_237 ( V_639 ) ;
}
break;
}
V_653:
if ( ! V_641 )
F_234 ( & V_639 -> V_655 , & V_9 -> V_649 ) ;
if ( ! V_636 ) {
V_9 -> V_663 ++ ;
V_639 -> V_75 = V_9 -> V_663 ;
if ( F_68 ( V_639 -> V_75 == 0 ) ) {
V_639 -> V_75 = 1 ;
V_9 -> V_663 ++ ;
}
* V_75 = V_639 -> V_75 ;
} else {
* V_75 = ( unsigned long ) V_636 ;
}
return 0 ;
}
static int F_243 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_244 * V_253 ,
unsigned int V_635 ,
T_4 * V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_24 ( & V_9 -> V_606 ) ;
V_19 = F_228 ( V_9 , V_12 , V_253 ,
V_635 , V_75 , NULL ,
V_664 ) ;
F_33 ( & V_9 -> V_606 ) ;
return V_19 ;
}
static int F_244 ( struct V_8 * V_9 ,
T_4 V_75 , bool V_665 )
{
struct V_638 * V_639 , * V_640 , * V_666 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_606 ) ;
F_245 (roc, tmp, &local->roc_list, list) {
struct V_638 * V_667 , * V_668 ;
F_245 (dep, tmp2, &roc->dependents, list) {
if ( ! V_665 && V_667 -> V_75 != V_75 )
continue;
else if ( V_665 && V_667 -> V_645 != V_75 )
continue;
F_246 ( & V_667 -> V_655 ) ;
F_33 ( & V_9 -> V_606 ) ;
F_247 ( V_667 , true ) ;
return 0 ;
}
if ( ! V_665 && V_639 -> V_75 != V_75 )
continue;
else if ( V_665 && V_639 -> V_645 != V_75 )
continue;
V_666 = V_639 ;
break;
}
if ( ! V_666 ) {
F_33 ( & V_9 -> V_606 ) ;
return - V_53 ;
}
if ( V_9 -> V_178 -> V_642 ) {
if ( V_666 -> V_654 ) {
V_19 = F_248 ( V_9 ) ;
if ( F_31 ( V_19 ) ) {
F_33 ( & V_9 -> V_606 ) ;
return V_19 ;
}
}
F_246 ( & V_666 -> V_655 ) ;
if ( V_666 -> V_654 )
F_249 ( V_9 ) ;
F_33 ( & V_9 -> V_606 ) ;
F_247 ( V_666 , true ) ;
} else {
V_666 -> abort = true ;
F_232 ( & V_9 -> V_108 , & V_666 -> V_646 , 0 ) ;
F_33 ( & V_9 -> V_606 ) ;
F_250 ( & V_666 -> V_646 ) ;
F_68 ( ! V_666 -> V_669 ) ;
F_170 ( V_666 ) ;
}
return 0 ;
}
static int F_251 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_244 ( V_9 , V_75 , false ) ;
}
static int F_252 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_273 * V_274 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
unsigned long V_615 ;
int V_13 ;
if ( ! F_231 ( & V_9 -> V_649 ) || V_9 -> V_650 )
return - V_30 ;
V_12 -> V_313 = V_314 ;
V_12 -> V_315 = V_9 -> V_316 ;
V_12 -> V_317 = true ;
F_24 ( & V_9 -> V_276 ) ;
V_13 = F_85 ( V_12 , V_274 ,
V_318 ) ;
F_33 ( & V_9 -> V_276 ) ;
if ( V_13 )
return V_13 ;
V_615 = F_236 ( V_670 ) ;
F_232 ( & V_12 -> V_9 -> V_108 ,
& V_12 -> V_341 , V_615 ) ;
return 0 ;
}
static struct V_293 *
F_253 ( struct V_293 * V_300 )
{
struct V_293 * V_671 ;
T_3 * V_672 ;
int V_291 ;
V_291 = V_300 -> V_302 + V_300 -> V_304 + V_300 -> V_673 +
V_300 -> V_674 + V_300 -> V_675 +
V_300 -> V_305 ;
V_671 = F_89 ( sizeof( * V_671 ) + V_291 , V_289 ) ;
if ( ! V_671 )
return NULL ;
V_672 = ( T_3 * ) ( V_671 + 1 ) ;
if ( V_300 -> V_302 ) {
V_671 -> V_302 = V_300 -> V_302 ;
V_671 -> V_301 = V_672 ;
memcpy ( V_672 , V_300 -> V_301 , V_300 -> V_302 ) ;
V_672 += V_300 -> V_302 ;
}
if ( V_300 -> V_304 ) {
V_671 -> V_304 = V_300 -> V_304 ;
V_671 -> V_303 = V_672 ;
memcpy ( V_672 , V_300 -> V_303 , V_300 -> V_304 ) ;
V_672 += V_300 -> V_304 ;
}
if ( V_300 -> V_673 ) {
V_671 -> V_673 = V_300 -> V_673 ;
V_671 -> V_676 = V_672 ;
memcpy ( V_672 , V_300 -> V_676 , V_300 -> V_673 ) ;
V_672 += V_300 -> V_673 ;
}
if ( V_300 -> V_674 ) {
V_671 -> V_674 = V_300 -> V_674 ;
V_671 -> V_677 = V_672 ;
memcpy ( V_672 , V_300 -> V_677 , V_300 -> V_674 ) ;
V_672 += V_300 -> V_674 ;
}
if ( V_300 -> V_675 ) {
V_671 -> V_675 = V_300 -> V_675 ;
V_671 -> V_678 = V_672 ;
memcpy ( V_672 , V_300 -> V_678 , V_300 -> V_675 ) ;
V_672 += V_300 -> V_675 ;
}
if ( V_300 -> V_305 ) {
V_671 -> V_305 = V_300 -> V_305 ;
V_300 -> V_285 = V_672 ;
memcpy ( V_672 , V_300 -> V_285 , V_300 -> V_305 ) ;
V_672 += V_300 -> V_305 ;
}
return V_671 ;
}
void F_254 ( struct V_679 * V_646 )
{
struct V_11 * V_12 =
F_168 ( V_646 , struct V_11 ,
V_337 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_13 , V_298 ;
if ( ! F_12 ( V_12 ) )
return;
if ( F_68 ( V_12 -> V_26 . type != V_58 ) )
return;
V_12 -> V_317 = V_12 -> V_680 ;
V_13 = F_255 ( V_12 , & V_9 -> V_681 ,
& V_298 ) ;
if ( F_68 ( V_13 < 0 ) )
return;
V_13 = F_92 ( V_12 , V_12 -> V_15 . V_288 . V_682 ) ;
if ( V_13 < 0 )
return;
V_298 |= V_13 ;
F_170 ( V_12 -> V_15 . V_288 . V_682 ) ;
V_12 -> V_15 . V_288 . V_682 = NULL ;
V_12 -> V_26 . V_334 = false ;
F_256 ( & V_12 -> V_9 -> V_108 ,
V_683 ,
V_684 ) ;
F_96 ( V_12 , V_298 ) ;
F_257 ( V_12 -> V_18 , & V_9 -> V_681 ) ;
}
static int F_258 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_685 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_242 * V_243 ;
struct V_686 * V_687 ;
int V_13 , V_688 ;
if ( ! F_231 ( & V_9 -> V_649 ) || V_9 -> V_650 )
return - V_30 ;
if ( V_12 -> V_10 . V_340 )
return - V_30 ;
if ( F_81 ( & V_7 -> V_274 ,
& V_12 -> V_26 . V_209 . V_274 ) )
return - V_45 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( ! V_243 ) {
F_43 () ;
return - V_30 ;
}
V_687 = F_168 ( V_243 , struct V_686 , V_49 ) ;
if ( V_687 -> V_689 > 1 ) {
F_43 () ;
return - V_30 ;
}
V_688 = 0 ;
F_259 (chanctx, &local->chanctx_list, list)
V_688 ++ ;
F_43 () ;
if ( V_688 > 1 )
return - V_30 ;
if ( V_12 -> V_26 . V_334 )
return - V_30 ;
switch ( V_12 -> V_26 . type ) {
case V_58 :
break;
default:
return - V_238 ;
}
V_12 -> V_15 . V_288 . V_682 = F_253 ( & V_7 -> V_690 ) ;
if ( ! V_12 -> V_15 . V_288 . V_682 )
return - V_290 ;
V_12 -> V_691 = V_7 -> V_692 ;
V_12 -> V_693 = V_7 -> V_694 ;
V_12 -> V_680 = V_7 -> V_317 ;
if ( V_7 -> V_695 )
F_260 ( & V_9 -> V_108 ,
V_683 ,
V_684 ) ;
V_13 = F_92 ( V_12 , & V_7 -> V_696 ) ;
if ( V_13 < 0 )
return V_13 ;
V_9 -> V_681 = V_7 -> V_274 ;
V_12 -> V_26 . V_334 = true ;
F_96 ( V_12 , V_13 ) ;
F_261 ( V_12 , & V_7 -> V_274 ) ;
return 0 ;
}
static int F_262 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_244 * V_253 , bool V_697 ,
unsigned int V_698 , const T_3 * V_699 , T_5 V_291 ,
bool V_700 , bool V_701 , T_4 * V_75 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_348 * V_349 ;
struct V_36 * V_23 ;
const struct V_702 * V_703 = ( void * ) V_699 ;
bool V_704 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_701 )
V_5 = V_705 ;
else
V_5 = V_706 |
V_707 ;
if ( V_700 )
V_5 |= V_708 ;
switch ( V_12 -> V_26 . type ) {
case V_60 :
if ( ! V_12 -> V_26 . V_209 . V_709 )
V_704 = true ;
#ifdef F_30
case V_61 :
if ( F_25 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_62 . V_455 )
V_704 = true ;
#endif
case V_58 :
case V_20 :
case V_70 :
if ( V_12 -> V_26 . type != V_60 &&
! F_25 ( & V_12 -> V_26 ) &&
! F_263 ( V_12 -> V_408 -> V_300 ) )
V_704 = true ;
if ( ! F_264 ( V_703 -> V_710 ) ||
V_703 -> V_15 . V_711 . V_712 == V_713 ||
V_703 -> V_15 . V_711 . V_712 == V_714 )
break;
F_39 () ;
V_23 = F_26 ( V_12 , V_703 -> V_350 ) ;
F_43 () ;
if ( ! V_23 )
return - V_715 ;
break;
case V_24 :
case V_69 :
if ( ! V_12 -> V_15 . V_25 . V_609 )
V_704 = true ;
break;
case V_66 :
V_704 = true ;
break;
default:
return - V_238 ;
}
if ( V_704 && ! V_253 )
return - V_45 ;
F_24 ( & V_9 -> V_606 ) ;
if ( ! V_704 ) {
struct V_242 * V_243 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( V_243 ) {
V_704 = V_253 && ( V_253 != V_243 -> V_252 . V_253 ) ;
} else if ( ! V_253 ) {
V_19 = - V_45 ;
F_43 () ;
goto V_54;
} else {
V_704 = true ;
}
F_43 () ;
}
if ( V_704 && ! V_697 ) {
V_19 = - V_30 ;
goto V_54;
}
V_349 = F_114 ( V_9 -> V_108 . V_716 + V_291 ) ;
if ( ! V_349 ) {
V_19 = - V_290 ;
goto V_54;
}
F_265 ( V_349 , V_9 -> V_108 . V_716 ) ;
memcpy ( F_115 ( V_349 , V_291 ) , V_699 , V_291 ) ;
F_266 ( V_349 ) -> V_5 = V_5 ;
V_349 -> V_18 = V_12 -> V_18 ;
if ( ! V_704 ) {
* V_75 = ( unsigned long ) V_349 ;
F_267 ( V_12 , V_349 ) ;
V_19 = 0 ;
goto V_54;
}
F_266 ( V_349 ) -> V_5 |= V_717 |
V_718 ;
if ( V_9 -> V_108 . V_5 & V_719 )
F_266 ( V_349 ) -> V_720 =
V_9 -> V_108 . V_721 ;
V_19 = F_228 ( V_9 , V_12 , V_253 ,
V_698 , V_75 , V_349 ,
V_722 ) ;
if ( V_19 )
F_268 ( V_349 ) ;
V_54:
F_33 ( & V_9 -> V_606 ) ;
return V_19 ;
}
static int F_269 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_75 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_244 ( V_9 , V_75 , true ) ;
}
static void F_270 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_723 , bool V_724 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_723 ) {
case V_725 | V_726 :
if ( V_724 )
V_9 -> V_727 ++ ;
else
V_9 -> V_727 -- ;
if ( ! V_9 -> V_280 )
break;
F_271 ( & V_9 -> V_108 , & V_9 -> V_728 ) ;
break;
default:
break;
}
}
static int F_272 ( struct V_2 * V_2 , T_1 V_729 , T_1 V_730 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_654 )
return - V_238 ;
return F_273 ( V_9 , V_729 , V_730 ) ;
}
static int F_274 ( struct V_2 * V_2 , T_1 * V_729 , T_1 * V_730 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_275 ( V_9 , V_729 , V_730 ) ;
}
static int F_276 ( struct V_2 * V_2 , T_1 V_82 , T_1 V_731 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_277 ( V_9 , V_82 , V_731 ) ;
}
static void F_278 ( struct V_2 * V_2 ,
T_1 * V_82 , T_1 * V_732 , T_1 * V_731 , T_1 * V_733 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_279 ( V_9 , V_82 , V_732 , V_731 , V_733 ) ;
}
static int F_280 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_734 * V_241 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_178 -> V_735 )
return - V_238 ;
F_281 ( V_9 , V_12 , V_241 ) ;
return 0 ;
}
static void F_282 ( struct V_348 * V_349 )
{
T_3 * V_672 = ( void * ) F_115 ( V_349 , 7 ) ;
* V_672 ++ = V_736 ;
* V_672 ++ = 5 ;
* V_672 ++ = 0x0 ;
* V_672 ++ = 0x0 ;
* V_672 ++ = 0x0 ;
* V_672 ++ = 0x0 ;
* V_672 ++ = V_737 ;
}
static T_2 F_283 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_738 ;
V_738 = 0 ;
if ( F_52 ( V_12 ) != V_739 )
return V_738 ;
if ( ! ( V_9 -> V_108 . V_5 & V_740 ) )
V_738 |= V_741 ;
if ( ! ( V_9 -> V_108 . V_5 & V_742 ) )
V_738 |= V_743 ;
return V_738 ;
}
static void F_284 ( struct V_348 * V_349 , T_3 * V_744 ,
T_3 * V_745 , T_3 * V_249 )
{
struct V_746 * V_747 ;
V_747 = ( void * ) F_115 ( V_349 , sizeof( struct V_746 ) ) ;
V_747 -> V_748 = V_749 ;
V_747 -> V_454 = sizeof( struct V_746 ) - 2 ;
memcpy ( V_747 -> V_249 , V_249 , V_271 ) ;
memcpy ( V_747 -> V_750 , V_744 , V_271 ) ;
memcpy ( V_747 -> V_751 , V_745 , V_271 ) ;
}
static int
F_285 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_745 , T_3 V_752 , T_3 V_753 ,
T_2 V_754 , struct V_348 * V_349 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_363 V_364 = F_52 ( V_12 ) ;
struct V_755 * V_756 ;
V_756 = ( void * ) F_115 ( V_349 , F_286 ( struct V_755 , V_15 ) ) ;
memcpy ( V_756 -> V_350 , V_745 , V_271 ) ;
memcpy ( V_756 -> V_351 , V_12 -> V_26 . V_270 , V_271 ) ;
V_756 -> V_757 = F_287 ( V_758 ) ;
V_756 -> V_759 = V_760 ;
switch ( V_752 ) {
case V_761 :
V_756 -> V_712 = V_762 ;
V_756 -> V_752 = V_761 ;
F_115 ( V_349 , sizeof( V_756 -> V_15 . V_763 ) ) ;
V_756 -> V_15 . V_763 . V_753 = V_753 ;
V_756 -> V_15 . V_763 . V_764 =
F_288 ( F_283 ( V_12 ) ) ;
F_289 ( V_12 , V_349 , false , V_364 ) ;
F_290 ( V_12 , V_349 , false , V_364 ) ;
F_282 ( V_349 ) ;
break;
case V_765 :
V_756 -> V_712 = V_762 ;
V_756 -> V_752 = V_765 ;
F_115 ( V_349 , sizeof( V_756 -> V_15 . V_766 ) ) ;
V_756 -> V_15 . V_766 . V_754 = F_288 ( V_754 ) ;
V_756 -> V_15 . V_766 . V_753 = V_753 ;
V_756 -> V_15 . V_766 . V_764 =
F_288 ( F_283 ( V_12 ) ) ;
F_289 ( V_12 , V_349 , false , V_364 ) ;
F_290 ( V_12 , V_349 , false , V_364 ) ;
F_282 ( V_349 ) ;
break;
case V_767 :
V_756 -> V_712 = V_762 ;
V_756 -> V_752 = V_767 ;
F_115 ( V_349 , sizeof( V_756 -> V_15 . V_768 ) ) ;
V_756 -> V_15 . V_768 . V_754 = F_288 ( V_754 ) ;
V_756 -> V_15 . V_768 . V_753 = V_753 ;
break;
case V_769 :
V_756 -> V_712 = V_762 ;
V_756 -> V_752 = V_769 ;
F_115 ( V_349 , sizeof( V_756 -> V_15 . V_770 ) ) ;
V_756 -> V_15 . V_770 . V_771 = F_288 ( V_754 ) ;
break;
case V_772 :
V_756 -> V_712 = V_762 ;
V_756 -> V_752 = V_772 ;
F_115 ( V_349 , sizeof( V_756 -> V_15 . V_773 ) ) ;
V_756 -> V_15 . V_773 . V_753 = V_753 ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int
F_291 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_745 , T_3 V_752 , T_3 V_753 ,
T_2 V_754 , struct V_348 * V_349 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_363 V_364 = F_52 ( V_12 ) ;
struct V_702 * V_703 ;
V_703 = ( void * ) F_115 ( V_349 , 24 ) ;
memset ( V_703 , 0 , 24 ) ;
memcpy ( V_703 -> V_350 , V_745 , V_271 ) ;
memcpy ( V_703 -> V_351 , V_12 -> V_26 . V_270 , V_271 ) ;
memcpy ( V_703 -> V_249 , V_12 -> V_15 . V_25 . V_249 , V_271 ) ;
V_703 -> V_710 = F_288 ( V_725 |
V_774 ) ;
switch ( V_752 ) {
case V_775 :
F_115 ( V_349 , 1 + sizeof( V_703 -> V_15 . V_711 . V_15 . V_776 ) ) ;
V_703 -> V_15 . V_711 . V_712 = V_713 ;
V_703 -> V_15 . V_711 . V_15 . V_776 . V_752 =
V_775 ;
V_703 -> V_15 . V_711 . V_15 . V_776 . V_753 =
V_753 ;
V_703 -> V_15 . V_711 . V_15 . V_776 . V_764 =
F_288 ( F_283 ( V_12 ) ) ;
F_289 ( V_12 , V_349 , false , V_364 ) ;
F_290 ( V_12 , V_349 , false , V_364 ) ;
F_282 ( V_349 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_292 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_745 , T_3 V_752 , T_3 V_753 ,
T_2 V_754 , const T_3 * V_777 ,
T_5 V_778 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_348 * V_349 = NULL ;
bool V_779 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_780 ) )
return - V_515 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_609 )
return - V_45 ;
F_293 ( V_12 , L_2 ,
V_752 , V_745 ) ;
V_349 = F_114 ( V_9 -> V_108 . V_716 +
F_235 ( sizeof( struct V_702 ) ,
sizeof( struct V_755 ) ) +
50 +
7 +
V_778 +
sizeof( struct V_746 ) ) ;
if ( ! V_349 )
return - V_290 ;
F_265 ( V_349 , V_9 -> V_108 . V_716 ) ;
switch ( V_752 ) {
case V_761 :
case V_765 :
case V_767 :
case V_769 :
case V_772 :
V_19 = F_285 ( V_2 , V_18 , V_745 ,
V_752 , V_753 ,
V_754 , V_349 ) ;
V_779 = false ;
break;
case V_775 :
V_19 = F_291 ( V_2 , V_18 , V_745 , V_752 ,
V_753 , V_754 ,
V_349 ) ;
V_779 = true ;
break;
default:
V_19 = - V_515 ;
break;
}
if ( V_19 < 0 )
goto V_781;
if ( V_778 )
memcpy ( F_115 ( V_349 , V_778 ) , V_777 , V_778 ) ;
switch ( V_752 ) {
case V_761 :
case V_767 :
case V_769 :
case V_772 :
F_284 ( V_349 , V_12 -> V_26 . V_270 , V_745 ,
V_12 -> V_15 . V_25 . V_249 ) ;
break;
case V_765 :
case V_775 :
F_284 ( V_349 , V_745 , V_12 -> V_26 . V_270 ,
V_12 -> V_15 . V_25 . V_249 ) ;
break;
default:
V_19 = - V_515 ;
goto V_781;
}
if ( V_779 ) {
F_267 ( V_12 , V_349 ) ;
return 0 ;
}
switch ( V_752 ) {
case V_761 :
case V_765 :
F_294 ( V_349 , V_782 ) ;
V_349 -> V_783 = 2 ;
break;
default:
F_294 ( V_349 , V_784 ) ;
V_349 -> V_783 = 5 ;
break;
}
F_295 () ;
V_19 = F_296 ( V_349 , V_18 ) ;
F_297 () ;
return V_19 ;
V_781:
F_298 ( V_349 ) ;
return V_19 ;
}
static int F_299 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_745 , enum V_785 V_786 )
{
struct V_36 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_780 ) )
return - V_515 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_45 ;
F_293 ( V_12 , L_3 , V_786 , V_745 ) ;
switch ( V_786 ) {
case V_787 :
F_39 () ;
V_23 = F_26 ( V_12 , V_745 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_715 ;
}
F_123 ( V_23 , V_788 ) ;
F_43 () ;
break;
case V_789 :
return F_300 ( V_12 , V_745 ) ;
case V_790 :
case V_791 :
case V_792 :
return - V_515 ;
default:
return - V_515 ;
}
return 0 ;
}
static int F_301 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_745 , T_4 * V_75 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_793 * V_794 ;
struct V_348 * V_349 ;
int V_297 = sizeof( * V_794 ) ;
T_7 V_795 ;
bool V_796 ;
struct V_797 * V_798 ;
struct V_36 * V_23 ;
struct V_242 * V_243 ;
enum V_363 V_364 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( F_68 ( ! V_243 ) ) {
F_43 () ;
return - V_45 ;
}
V_364 = V_243 -> V_252 . V_253 -> V_364 ;
V_23 = F_27 ( V_12 , V_745 ) ;
if ( V_23 ) {
V_796 = F_28 ( V_23 , V_231 ) ;
} else {
F_43 () ;
return - V_715 ;
}
if ( V_796 ) {
V_795 = F_288 ( V_799 |
V_800 |
V_801 ) ;
} else {
V_297 -= 2 ;
V_795 = F_288 ( V_799 |
V_802 |
V_801 ) ;
}
V_349 = F_114 ( V_9 -> V_108 . V_716 + V_297 ) ;
if ( ! V_349 ) {
F_43 () ;
return - V_290 ;
}
V_349 -> V_18 = V_18 ;
F_265 ( V_349 , V_9 -> V_108 . V_716 ) ;
V_794 = ( void * ) F_115 ( V_349 , V_297 ) ;
V_794 -> V_710 = V_795 ;
V_794 -> V_803 = 0 ;
memcpy ( V_794 -> V_804 , V_23 -> V_23 . V_270 , V_271 ) ;
memcpy ( V_794 -> V_805 , V_12 -> V_26 . V_270 , V_271 ) ;
memcpy ( V_794 -> V_806 , V_12 -> V_26 . V_270 , V_271 ) ;
V_794 -> V_807 = 0 ;
V_798 = F_266 ( V_349 ) ;
V_798 -> V_5 |= V_707 |
V_706 ;
F_294 ( V_349 , V_808 ) ;
V_349 -> V_783 = 7 ;
if ( V_796 )
V_794 -> V_809 = F_288 ( 7 ) ;
F_295 () ;
F_302 ( V_12 , V_349 , V_364 ) ;
F_297 () ;
F_43 () ;
* V_75 = ( unsigned long ) V_349 ;
return 0 ;
}
static int F_303 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_273 * V_274 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_242 * V_243 ;
int V_19 = - V_810 ;
F_39 () ;
V_243 = F_40 ( V_12 -> V_26 . V_243 ) ;
if ( V_243 ) {
* V_274 = V_243 -> V_252 ;
V_19 = 0 ;
} else if ( V_9 -> V_280 > 0 &&
V_9 -> V_280 == V_9 -> V_281 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_277 )
* V_274 = V_9 -> V_275 ;
else
* V_274 = V_9 -> V_282 ;
V_19 = 0 ;
}
F_43 () ;
return V_19 ;
}
static void F_304 ( struct V_2 * V_2 , bool V_614 )
{
F_305 ( F_2 ( V_2 ) , V_614 ) ;
}
