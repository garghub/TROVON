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
if ( ( * V_5 & V_27 ) !=
( V_12 -> V_15 . V_16 & V_27 ) )
return - V_28 ;
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
T_2 V_29 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_29 = V_29 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 ,
struct V_33 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_34 * V_23 = NULL ;
struct V_35 * V_36 ;
int V_13 ;
if ( ! F_12 ( V_12 ) )
return - V_37 ;
switch ( V_7 -> V_38 ) {
case V_39 :
case V_40 :
case V_41 :
if ( F_21 ( V_12 -> V_9 -> V_42 ) )
return - V_43 ;
break;
default:
break;
}
V_36 = F_22 ( V_7 -> V_38 , V_30 , V_7 -> V_44 ,
V_7 -> V_36 , V_7 -> V_45 , V_7 -> V_46 ) ;
if ( F_21 ( V_36 ) )
return F_23 ( V_36 ) ;
if ( V_31 )
V_36 -> V_47 . V_5 |= V_48 ;
F_24 ( & V_12 -> V_9 -> V_49 ) ;
if ( V_32 ) {
if ( F_25 ( & V_12 -> V_26 ) )
V_23 = F_26 ( V_12 , V_32 ) ;
else
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 || ! F_28 ( V_23 , V_50 ) ) {
F_29 ( V_12 -> V_9 , V_36 ) ;
V_13 = - V_51 ;
goto V_52;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_53 != V_54 )
V_36 -> V_47 . V_5 |= V_55 ;
break;
case V_56 :
case V_20 :
if ( V_36 -> V_23 && F_28 ( V_36 -> V_23 , V_57 ) )
V_36 -> V_47 . V_5 |= V_55 ;
break;
case V_58 :
break;
case V_59 :
#ifdef F_30
if ( V_12 -> V_15 . V_60 . V_61 != V_62 )
V_36 -> V_47 . V_5 |= V_55 ;
break;
#endif
case V_63 :
case V_14 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
F_31 ( 1 ) ;
break;
}
V_13 = F_32 ( V_36 , V_12 , V_23 ) ;
if ( V_13 )
F_29 ( V_12 -> V_9 , V_36 ) ;
V_52:
F_33 ( & V_12 -> V_9 -> V_49 ) ;
return V_13 ;
}
static int F_34 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
struct V_35 * V_36 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_49 ) ;
F_24 ( & V_9 -> V_69 ) ;
if ( V_32 ) {
V_19 = - V_51 ;
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_52;
if ( V_31 )
V_36 = F_35 ( V_9 , V_23 -> V_70 ) ;
else
V_36 = F_35 ( V_9 , V_23 -> V_71 [ V_30 ] ) ;
} else
V_36 = F_35 ( V_9 , V_12 -> V_72 [ V_30 ] ) ;
if ( ! V_36 ) {
V_19 = - V_51 ;
goto V_52;
}
F_36 ( V_36 ) ;
V_19 = 0 ;
V_52:
F_33 ( & V_9 -> V_69 ) ;
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 ,
void * V_73 ,
void (* F_38)( void * V_73 ,
struct V_33 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_34 * V_23 = NULL ;
T_3 V_46 [ 6 ] = { 0 } ;
struct V_33 V_7 ;
struct V_35 * V_36 = NULL ;
T_4 V_74 ;
T_1 V_75 ;
T_2 V_76 ;
int V_13 = - V_51 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
if ( V_32 ) {
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_77;
if ( V_31 )
V_36 = F_40 ( V_23 -> V_70 ) ;
else if ( V_30 < V_78 )
V_36 = F_40 ( V_23 -> V_71 [ V_30 ] ) ;
} else
V_36 = F_40 ( V_12 -> V_72 [ V_30 ] ) ;
if ( ! V_36 )
goto V_77;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_38 = V_36 -> V_47 . V_38 ;
switch ( V_36 -> V_47 . V_38 ) {
case V_40 :
V_75 = V_36 -> V_15 . V_79 . V_80 . V_75 ;
V_76 = V_36 -> V_15 . V_79 . V_80 . V_76 ;
if ( V_36 -> V_5 & V_81 )
F_41 ( V_12 -> V_9 ,
V_36 -> V_47 . V_82 ,
& V_75 , & V_76 ) ;
V_46 [ 0 ] = V_76 & 0xff ;
V_46 [ 1 ] = ( V_76 >> 8 ) & 0xff ;
V_46 [ 2 ] = V_75 & 0xff ;
V_46 [ 3 ] = ( V_75 >> 8 ) & 0xff ;
V_46 [ 4 ] = ( V_75 >> 16 ) & 0xff ;
V_46 [ 5 ] = ( V_75 >> 24 ) & 0xff ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_83 :
V_74 = F_42 ( & V_36 -> V_15 . V_84 . V_85 ) ;
V_46 [ 0 ] = V_74 ;
V_46 [ 1 ] = V_74 >> 8 ;
V_46 [ 2 ] = V_74 >> 16 ;
V_46 [ 3 ] = V_74 >> 24 ;
V_46 [ 4 ] = V_74 >> 32 ;
V_46 [ 5 ] = V_74 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_86 :
V_74 = F_42 ( & V_36 -> V_15 . V_87 . V_85 ) ;
V_46 [ 0 ] = V_74 ;
V_46 [ 1 ] = V_74 >> 8 ;
V_46 [ 2 ] = V_74 >> 16 ;
V_46 [ 3 ] = V_74 >> 24 ;
V_46 [ 4 ] = V_74 >> 32 ;
V_46 [ 5 ] = V_74 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
}
V_7 . V_36 = V_36 -> V_47 . V_36 ;
V_7 . V_44 = V_36 -> V_47 . V_88 ;
F_38 ( V_73 , & V_7 ) ;
V_13 = 0 ;
V_77:
F_43 () ;
return V_13 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_30 , bool V_89 ,
bool V_90 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_45 ( V_12 , V_30 , V_89 , V_90 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_30 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_47 ( V_12 , V_30 ) ;
return 0 ;
}
void F_48 ( struct V_34 * V_23 ,
const struct V_91 * V_92 ,
struct V_93 * V_94 )
{
V_94 -> V_5 = 0 ;
if ( V_92 -> V_5 & V_95 ) {
V_94 -> V_5 |= V_96 ;
V_94 -> V_97 = V_92 -> V_98 ;
} else if ( V_92 -> V_5 & V_99 ) {
V_94 -> V_5 |= V_100 ;
V_94 -> V_97 = F_49 ( V_92 ) ;
V_94 -> V_101 = F_50 ( V_92 ) ;
} else {
struct V_102 * V_103 ;
V_103 = V_23 -> V_9 -> V_104 . V_2 -> V_105 [
F_51 ( V_23 -> V_12 ) ] ;
V_94 -> V_106 = V_103 -> V_107 [ V_92 -> V_98 ] . V_108 ;
}
if ( V_92 -> V_5 & V_109 )
V_94 -> V_5 |= V_110 ;
if ( V_92 -> V_5 & V_111 )
V_94 -> V_5 |= V_112 ;
if ( V_92 -> V_5 & V_113 )
V_94 -> V_5 |= V_114 ;
if ( V_92 -> V_5 & V_115 )
V_94 -> V_5 |= V_116 ;
}
void F_52 ( struct V_34 * V_23 , struct V_93 * V_94 )
{
V_94 -> V_5 = 0 ;
if ( V_23 -> V_117 & V_118 ) {
V_94 -> V_5 |= V_96 ;
V_94 -> V_97 = V_23 -> V_119 ;
} else if ( V_23 -> V_117 & V_120 ) {
V_94 -> V_5 |= V_100 ;
V_94 -> V_101 = V_23 -> V_121 ;
V_94 -> V_97 = V_23 -> V_119 ;
} else {
struct V_102 * V_103 ;
V_103 = V_23 -> V_9 -> V_104 . V_2 -> V_105 [
F_51 ( V_23 -> V_12 ) ] ;
V_94 -> V_106 =
V_103 -> V_107 [ V_23 -> V_119 ] . V_108 ;
}
if ( V_23 -> V_117 & V_122 )
V_94 -> V_5 |= V_110 ;
if ( V_23 -> V_117 & V_123 )
V_94 -> V_5 |= V_116 ;
if ( V_23 -> V_117 & V_124 )
V_94 -> V_5 |= V_112 ;
if ( V_23 -> V_117 & V_125 )
V_94 -> V_5 |= V_126 ;
if ( V_23 -> V_117 & V_127 )
V_94 -> V_5 |= V_114 ;
}
static void F_53 ( struct V_34 * V_23 , struct V_128 * V_129 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_130 V_131 ;
V_129 -> V_132 = V_12 -> V_9 -> V_133 ;
V_129 -> V_134 = V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 ;
F_54 ( & V_131 ) ;
V_129 -> V_149 = V_131 . V_150 - V_23 -> V_151 ;
V_129 -> V_152 = F_55 ( V_153 - V_23 -> V_154 ) ;
V_129 -> V_155 = V_23 -> V_155 ;
V_129 -> V_156 = V_23 -> V_156 ;
V_129 -> V_157 = V_23 -> V_157 ;
V_129 -> V_158 = V_23 -> V_158 ;
V_129 -> V_159 = V_23 -> V_160 ;
V_129 -> V_161 = V_23 -> V_162 ;
V_129 -> V_163 = V_23 -> V_164 ;
V_129 -> V_165 = V_23 -> V_165 ;
if ( ( V_23 -> V_9 -> V_104 . V_5 & V_166 ) ||
( V_23 -> V_9 -> V_104 . V_5 & V_167 ) ) {
V_129 -> V_134 |= V_168 | V_169 ;
if ( ! V_9 -> V_170 -> V_171 ||
F_56 ( V_9 , V_12 , & V_23 -> V_23 , & V_129 -> signal ) )
V_129 -> signal = ( V_172 ) V_23 -> V_173 ;
V_129 -> V_174 = ( V_172 ) - F_57 ( & V_23 -> V_175 ) ;
}
F_48 ( V_23 , & V_23 -> V_176 , & V_129 -> V_177 ) ;
F_52 ( V_23 , & V_129 -> V_178 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
V_129 -> V_134 |= V_179 |
V_180 |
V_181 |
V_182 |
V_183 |
V_184 ;
V_129 -> V_185 = F_58 ( V_23 -> V_185 ) ;
V_129 -> V_186 = F_58 ( V_23 -> V_186 ) ;
V_129 -> V_187 = V_23 -> V_187 ;
if ( F_28 ( V_23 , V_188 ) ) {
V_129 -> V_134 |= V_189 ;
V_129 -> V_190 = V_23 -> V_190 ;
}
V_129 -> V_191 = V_23 -> V_191 ;
V_129 -> V_192 = V_23 -> V_192 ;
V_129 -> V_193 = V_23 -> V_193 ;
#endif
}
V_129 -> V_194 . V_5 = 0 ;
if ( V_12 -> V_26 . V_195 . V_196 )
V_129 -> V_194 . V_5 |= V_197 ;
if ( V_12 -> V_26 . V_195 . V_198 )
V_129 -> V_194 . V_5 |= V_199 ;
if ( V_12 -> V_26 . V_195 . V_200 )
V_129 -> V_194 . V_5 |= V_201 ;
V_129 -> V_194 . V_202 = V_12 -> V_9 -> V_104 . V_47 . V_203 ;
V_129 -> V_194 . V_204 = V_12 -> V_26 . V_195 . V_205 ;
V_129 -> V_206 . V_207 = 0 ;
V_129 -> V_206 . V_208 = F_59 ( V_209 ) |
F_59 ( V_210 ) |
F_59 ( V_211 ) |
F_59 ( V_212 ) |
F_59 ( V_213 ) |
F_59 ( V_214 ) |
F_59 ( V_215 ) ;
if ( F_28 ( V_23 , V_216 ) )
V_129 -> V_206 . V_207 |= F_59 ( V_209 ) ;
if ( F_28 ( V_23 , V_217 ) )
V_129 -> V_206 . V_207 |= F_59 ( V_210 ) ;
if ( F_28 ( V_23 , V_218 ) )
V_129 -> V_206 . V_207 |= F_59 ( V_211 ) ;
if ( F_28 ( V_23 , V_57 ) )
V_129 -> V_206 . V_207 |= F_59 ( V_212 ) ;
if ( F_28 ( V_23 , V_219 ) )
V_129 -> V_206 . V_207 |= F_59 ( V_213 ) ;
if ( F_28 ( V_23 , V_50 ) )
V_129 -> V_206 . V_207 |= F_59 ( V_214 ) ;
if ( F_28 ( V_23 , V_220 ) )
V_129 -> V_206 . V_207 |= F_59 ( V_215 ) ;
}
static int F_60 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_221 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_222 = 0 ;
if ( V_221 == V_223 )
V_222 += V_224 ;
V_222 += F_61 ( V_12 , V_221 ) ;
if ( V_222 == 0 )
return - V_225 ;
return V_222 ;
}
static void F_62 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_226 * V_227 ,
T_4 * V_228 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_229 * V_230 ;
struct V_231 * V_232 ;
struct V_34 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_128 V_129 ;
struct V_233 V_234 ;
int V_235 , V_236 ;
#define F_63 7
memset ( V_228 , 0 , sizeof( T_4 ) * V_224 ) ;
#define F_64 ( V_23 ) \
do { \
data[i++] += sta->rx_packets; \
data[i++] += sta->rx_bytes; \
data[i++] += sta->wep_weak_iv_count; \
data[i++] += sta->num_duplicates; \
data[i++] += sta->rx_fragments; \
data[i++] += sta->rx_dropped; \
\
data[i++] += sta->tx_packets; \
data[i++] += sta->tx_bytes; \
data[i++] += sta->tx_fragments; \
data[i++] += sta->tx_filtered_count; \
data[i++] += sta->tx_retry_failed; \
data[i++] += sta->tx_retry_count; \
data[i++] += sta->beacon_loss_count; \
} while (0)
F_24 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_27 ( V_12 , V_12 -> V_15 . V_25 . V_237 ) ;
if ( ! ( V_23 && ! F_65 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_238;
V_235 = 0 ;
F_64 ( V_23 ) ;
V_228 [ V_235 ++ ] = V_23 -> V_239 ;
V_129 . V_134 = 0 ;
F_53 ( V_23 , & V_129 ) ;
if ( V_129 . V_134 & V_142 )
V_228 [ V_235 ] = 100000 *
F_66 ( & V_129 . V_177 ) ;
V_235 ++ ;
if ( V_129 . V_134 & V_143 )
V_228 [ V_235 ] = 100000 *
F_66 ( & V_129 . V_178 ) ;
V_235 ++ ;
if ( V_129 . V_134 & V_169 )
V_228 [ V_235 ] = ( T_3 ) V_129 . V_174 ;
V_235 ++ ;
} else {
F_67 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_235 = 0 ;
F_64 ( V_23 ) ;
}
}
V_238:
V_235 = V_224 - F_63 ;
V_234 . V_134 = 0 ;
F_39 () ;
V_230 = F_40 ( V_12 -> V_26 . V_230 ) ;
if ( V_230 )
V_232 = V_230 -> V_240 . V_241 ;
else
V_232 = NULL ;
F_43 () ;
if ( V_232 ) {
V_236 = 0 ;
do {
V_234 . V_134 = 0 ;
if ( F_68 ( V_9 , V_236 , & V_234 ) != 0 ) {
V_234 . V_134 = 0 ;
break;
}
V_236 ++ ;
} while ( V_232 != V_234 . V_232 );
}
if ( V_234 . V_134 )
V_228 [ V_235 ++ ] = V_234 . V_232 -> V_242 ;
else
V_228 [ V_235 ++ ] = 0 ;
if ( V_234 . V_134 & V_243 )
V_228 [ V_235 ++ ] = ( T_3 ) V_234 . V_244 ;
else
V_228 [ V_235 ++ ] = - 1LL ;
if ( V_234 . V_134 & V_245 )
V_228 [ V_235 ++ ] = V_234 . V_246 ;
else
V_228 [ V_235 ++ ] = - 1LL ;
if ( V_234 . V_134 & V_247 )
V_228 [ V_235 ++ ] = V_234 . V_248 ;
else
V_228 [ V_235 ++ ] = - 1LL ;
if ( V_234 . V_134 & V_249 )
V_228 [ V_235 ++ ] = V_234 . V_250 ;
else
V_228 [ V_235 ++ ] = - 1LL ;
if ( V_234 . V_134 & V_251 )
V_228 [ V_235 ++ ] = V_234 . V_252 ;
else
V_228 [ V_235 ++ ] = - 1LL ;
if ( V_234 . V_134 & V_253 )
V_228 [ V_235 ++ ] = V_234 . V_254 ;
else
V_228 [ V_235 ++ ] = - 1LL ;
F_33 ( & V_9 -> V_49 ) ;
if ( F_65 ( V_235 != V_224 ) )
return;
F_69 ( V_12 , V_227 , & ( V_228 [ V_224 ] ) ) ;
}
static void F_70 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_221 , T_3 * V_228 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_255 = 0 ;
if ( V_221 == V_223 ) {
V_255 = sizeof( V_256 ) ;
memcpy ( V_228 , * V_256 , V_255 ) ;
}
F_71 ( V_12 , V_221 , & ( V_228 [ V_255 ] ) ) ;
}
static int F_72 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , T_3 * V_257 , struct V_128 * V_129 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_51 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_73 ( V_12 , V_98 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_257 , V_23 -> V_23 . V_258 , V_259 ) ;
F_53 ( V_23 , V_129 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_74 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , struct V_233 * V_234 )
{
struct V_8 * V_9 = F_75 ( V_18 -> V_260 ) ;
return F_68 ( V_9 , V_98 , V_234 ) ;
}
static int F_76 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_257 , struct V_128 * V_129 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_51 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_257 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_53 ( V_23 , V_129 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_77 ( struct V_2 * V_2 ,
struct V_261 * V_262 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
int V_19 = 0 ;
if ( F_78 ( & V_9 -> V_263 , V_262 ) )
return 0 ;
F_24 ( & V_9 -> V_264 ) ;
if ( V_9 -> V_265 ) {
V_12 = F_79 (
V_9 -> V_266 ,
F_80 ( & V_9 -> V_264 ) ) ;
if ( V_12 ) {
F_81 ( V_12 ) ;
V_19 = F_82 ( V_12 , V_262 ,
V_267 ) ;
}
} else if ( V_9 -> V_268 == V_9 -> V_269 ) {
V_9 -> V_270 = V_262 -> V_241 ;
V_9 -> V_271 = F_83 ( V_262 ) ;
F_84 ( V_9 , 0 ) ;
}
if ( V_19 == 0 )
V_9 -> V_263 = * V_262 ;
F_33 ( & V_9 -> V_264 ) ;
return V_19 ;
}
static int F_85 ( struct V_11 * V_12 ,
const T_3 * V_272 , T_5 V_273 )
{
struct V_274 * V_275 , * V_276 ;
if ( ! V_272 || ! V_273 )
return 1 ;
V_276 = F_86 ( V_12 -> V_15 . V_277 . V_274 ) ;
V_275 = F_87 ( sizeof( struct V_274 ) + V_273 , V_278 ) ;
if ( ! V_275 )
return - V_279 ;
V_275 -> V_280 = V_273 ;
memcpy ( V_275 -> V_228 , V_272 , V_273 ) ;
F_88 ( V_12 -> V_15 . V_277 . V_274 , V_275 ) ;
if ( V_276 )
F_89 ( V_276 , V_281 ) ;
return 0 ;
}
static int F_90 ( struct V_11 * V_12 ,
struct V_282 * V_7 )
{
struct V_283 * V_275 , * V_276 ;
int V_284 , V_285 ;
int V_286 , V_13 ;
T_1 V_287 = V_288 ;
V_276 = F_86 ( V_12 -> V_15 . V_277 . V_289 ) ;
if ( ! V_7 -> V_290 && ! V_276 )
return - V_43 ;
if ( V_7 -> V_290 )
V_284 = V_7 -> V_291 ;
else
V_284 = V_276 -> V_291 ;
if ( V_7 -> V_292 || ! V_276 )
V_285 = V_7 -> V_293 ;
else
V_285 = V_276 -> V_293 ;
V_286 = sizeof( * V_275 ) + V_284 + V_285 ;
V_275 = F_87 ( V_286 , V_278 ) ;
if ( ! V_275 )
return - V_279 ;
V_275 -> V_290 = ( ( T_3 * ) V_275 ) + sizeof( * V_275 ) ;
V_275 -> V_292 = V_275 -> V_290 + V_284 ;
V_275 -> V_291 = V_284 ;
V_275 -> V_293 = V_285 ;
if ( V_7 -> V_290 )
memcpy ( V_275 -> V_290 , V_7 -> V_290 , V_284 ) ;
else
memcpy ( V_275 -> V_290 , V_276 -> V_290 , V_284 ) ;
if ( V_7 -> V_292 )
memcpy ( V_275 -> V_292 , V_7 -> V_292 , V_285 ) ;
else
if ( V_276 )
memcpy ( V_275 -> V_292 , V_276 -> V_292 , V_285 ) ;
V_13 = F_85 ( V_12 , V_7 -> V_274 ,
V_7 -> V_294 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_287 |= V_295 ;
F_88 ( V_12 -> V_15 . V_277 . V_289 , V_275 ) ;
if ( V_276 )
F_89 ( V_276 , V_281 ) ;
return V_287 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_296 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_283 * V_276 ;
struct V_11 * V_22 ;
T_1 V_287 = V_297 |
V_298 |
V_288 |
V_299 |
V_300 ;
int V_13 ;
V_276 = F_86 ( V_12 -> V_15 . V_277 . V_289 ) ;
if ( V_276 )
return - V_301 ;
V_12 -> V_302 = V_303 ;
V_12 -> V_304 = V_12 -> V_9 -> V_305 ;
V_12 -> V_306 = V_7 -> V_306 ;
V_13 = F_82 ( V_12 , & V_7 -> V_262 ,
V_307 ) ;
if ( V_13 )
return V_13 ;
F_92 ( V_12 , false ) ;
V_12 -> V_308 = V_7 -> V_309 . V_310 ;
V_12 -> V_311 = V_7 -> V_309 . V_311 ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_308 =
V_7 -> V_309 . V_310 ;
V_22 -> V_311 =
V_7 -> V_309 . V_311 ;
}
V_12 -> V_26 . V_195 . V_205 = V_7 -> V_204 ;
V_12 -> V_26 . V_195 . V_202 = V_7 -> V_202 ;
V_12 -> V_26 . V_195 . V_312 = true ;
V_12 -> V_26 . V_195 . V_313 = V_7 -> V_313 ;
if ( V_7 -> V_313 )
memcpy ( V_12 -> V_26 . V_195 . V_314 , V_7 -> V_314 ,
V_7 -> V_313 ) ;
V_12 -> V_26 . V_195 . V_315 =
( V_7 -> V_315 != V_316 ) ;
V_12 -> V_26 . V_195 . V_317 = V_7 -> V_317 ;
V_12 -> V_26 . V_195 . V_318 = V_7 -> V_319 ;
V_13 = F_90 ( V_12 , & V_7 -> V_289 ) ;
if ( V_13 < 0 )
return V_13 ;
V_287 |= V_13 ;
V_13 = F_93 ( V_12 -> V_9 , V_12 ) ;
if ( V_13 ) {
V_276 = F_86 ( V_12 -> V_15 . V_277 . V_289 ) ;
if ( V_276 )
F_89 ( V_276 , V_281 ) ;
F_11 ( V_12 -> V_15 . V_277 . V_289 , NULL ) ;
return V_13 ;
}
F_94 ( V_12 , V_287 ) ;
F_95 ( V_18 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_95 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_282 * V_7 )
{
struct V_11 * V_12 ;
struct V_283 * V_276 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
V_276 = F_86 ( V_12 -> V_15 . V_277 . V_289 ) ;
if ( ! V_276 )
return - V_51 ;
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
struct V_283 * V_320 ;
struct V_274 * V_321 ;
V_320 = F_86 ( V_12 -> V_15 . V_277 . V_289 ) ;
if ( ! V_320 )
return - V_51 ;
V_321 = F_86 ( V_12 -> V_15 . V_277 . V_274 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_98 ( V_22 -> V_18 ) ;
F_98 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_277 . V_289 , NULL ) ;
F_11 ( V_12 -> V_15 . V_277 . V_274 , NULL ) ;
F_89 ( V_320 , V_281 ) ;
if ( V_321 )
F_89 ( V_321 , V_281 ) ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_99 ( V_22 ) ;
F_99 ( V_12 ) ;
F_100 () ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_101 ( V_22 ) ;
F_101 ( V_12 ) ;
V_12 -> V_26 . V_195 . V_312 = false ;
F_102 ( V_322 , & V_12 -> V_323 ) ;
F_94 ( V_12 , V_298 ) ;
F_103 ( V_12 -> V_9 , V_12 ) ;
V_9 -> V_324 -= F_104 ( & V_12 -> V_15 . V_277 . V_325 . V_326 ) ;
F_105 ( & V_12 -> V_15 . V_277 . V_325 . V_326 ) ;
F_92 ( V_12 , true ) ;
F_81 ( V_12 ) ;
return 0 ;
}
static void F_106 ( struct V_34 * V_23 )
{
struct V_327 * V_328 ;
struct V_329 * V_330 ;
V_330 = F_107 ( sizeof( * V_328 ) ) ;
if ( ! V_330 )
return;
V_328 = (struct V_327 * ) F_108 ( V_330 , sizeof( * V_328 ) ) ;
F_109 ( V_328 -> V_331 ) ;
memcpy ( V_328 -> V_332 , V_23 -> V_23 . V_258 , V_259 ) ;
V_328 -> V_280 = F_110 ( 6 ) ;
V_328 -> V_333 = 0 ;
V_328 -> V_334 = 0x01 ;
V_328 -> V_335 = 0xaf ;
V_328 -> V_336 [ 0 ] = 0x81 ;
V_328 -> V_336 [ 1 ] = 1 ;
V_328 -> V_336 [ 2 ] = 0 ;
V_330 -> V_18 = V_23 -> V_12 -> V_18 ;
V_330 -> V_337 = F_111 ( V_330 , V_23 -> V_12 -> V_18 ) ;
memset ( V_330 -> V_338 , 0 , sizeof( V_330 -> V_338 ) ) ;
F_112 ( V_330 ) ;
}
static int F_113 ( struct V_8 * V_9 ,
struct V_34 * V_23 ,
T_1 V_208 , T_1 V_207 )
{
int V_19 ;
if ( V_208 & F_59 ( V_213 ) &&
V_207 & F_59 ( V_213 ) &&
! F_28 ( V_23 , V_219 ) ) {
V_19 = F_114 ( V_23 , V_339 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_208 & F_59 ( V_214 ) &&
V_207 & F_59 ( V_214 ) &&
! F_28 ( V_23 , V_50 ) ) {
V_19 = F_114 ( V_23 , V_340 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_208 & F_59 ( V_209 ) ) {
if ( V_207 & F_59 ( V_209 ) )
V_19 = F_114 ( V_23 , V_341 ) ;
else if ( F_28 ( V_23 , V_216 ) )
V_19 = F_114 ( V_23 , V_340 ) ;
else
V_19 = 0 ;
if ( V_19 )
return V_19 ;
}
if ( V_208 & F_59 ( V_214 ) &&
! ( V_207 & F_59 ( V_214 ) ) &&
F_28 ( V_23 , V_50 ) ) {
V_19 = F_114 ( V_23 , V_339 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_208 & F_59 ( V_213 ) &&
! ( V_207 & F_59 ( V_213 ) ) &&
F_28 ( V_23 , V_219 ) ) {
V_19 = F_114 ( V_23 , V_342 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_115 ( struct V_8 * V_9 ,
struct V_34 * V_23 ,
struct V_343 * V_7 )
{
int V_19 = 0 ;
T_1 V_344 ;
int V_235 , V_345 ;
struct V_102 * V_103 ;
struct V_11 * V_12 = V_23 -> V_12 ;
enum V_346 V_347 = F_51 ( V_12 ) ;
T_1 V_208 , V_207 ;
V_103 = V_9 -> V_104 . V_2 -> V_105 [ V_347 ] ;
V_208 = V_7 -> V_348 ;
V_207 = V_7 -> V_349 ;
if ( F_25 ( & V_12 -> V_26 ) ) {
if ( V_208 & F_59 ( V_213 ) )
V_208 |= F_59 ( V_214 ) ;
if ( V_207 & F_59 ( V_213 ) )
V_207 |= F_59 ( V_214 ) ;
}
V_19 = F_113 ( V_9 , V_23 , V_208 , V_207 ) ;
if ( V_19 )
return V_19 ;
if ( V_208 & F_59 ( V_210 ) ) {
if ( V_207 & F_59 ( V_210 ) )
F_116 ( V_23 , V_217 ) ;
else
F_117 ( V_23 , V_217 ) ;
}
if ( V_208 & F_59 ( V_211 ) ) {
if ( V_207 & F_59 ( V_211 ) ) {
F_116 ( V_23 , V_218 ) ;
V_23 -> V_23 . V_350 = true ;
} else {
F_117 ( V_23 , V_218 ) ;
V_23 -> V_23 . V_350 = false ;
}
}
if ( V_208 & F_59 ( V_212 ) ) {
if ( V_207 & F_59 ( V_212 ) )
F_116 ( V_23 , V_57 ) ;
else
F_117 ( V_23 , V_57 ) ;
}
if ( V_208 & F_59 ( V_215 ) ) {
if ( V_207 & F_59 ( V_215 ) )
F_116 ( V_23 , V_220 ) ;
else
F_117 ( V_23 , V_220 ) ;
}
if ( V_7 -> V_351 & V_352 ) {
V_23 -> V_23 . V_353 = V_7 -> V_353 ;
V_23 -> V_23 . V_354 = V_7 -> V_354 ;
}
if ( V_7 -> V_355 )
V_23 -> V_23 . V_355 = V_7 -> V_355 ;
if ( V_7 -> V_356 >= 0 )
V_23 -> V_356 = V_7 -> V_356 ;
if ( V_7 -> V_357 ) {
V_344 = 0 ;
for ( V_235 = 0 ; V_235 < V_7 -> V_358 ; V_235 ++ ) {
int V_92 = ( V_7 -> V_357 [ V_235 ] & 0x7f ) * 5 ;
for ( V_345 = 0 ; V_345 < V_103 -> V_359 ; V_345 ++ ) {
if ( V_103 -> V_107 [ V_345 ] . V_108 == V_92 )
V_344 |= F_59 ( V_345 ) ;
}
}
V_23 -> V_23 . V_360 [ V_347 ] = V_344 ;
}
if ( V_7 -> V_361 )
F_118 ( V_12 , V_103 ,
V_7 -> V_361 , V_23 ) ;
if ( V_7 -> V_362 )
F_119 ( V_12 , V_103 ,
V_7 -> V_362 , V_23 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
T_1 V_287 = 0 ;
if ( V_12 -> V_15 . V_60 . V_61 & V_363 ) {
switch ( V_7 -> V_187 ) {
case V_364 :
if ( V_23 -> V_187 != V_364 )
V_287 = F_120 (
V_12 ) ;
V_23 -> V_187 = V_7 -> V_187 ;
F_121 ( V_23 ) ;
V_287 |= F_122 ( V_23 ,
V_12 -> V_15 . V_60 . V_365 . V_366 ) ;
break;
case V_367 :
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
if ( V_23 -> V_187 == V_364 )
V_287 = F_123 (
V_12 ) ;
V_23 -> V_187 = V_7 -> V_187 ;
F_121 ( V_23 ) ;
V_287 |=
F_124 ( V_12 ) ;
break;
default:
break;
}
} else {
switch ( V_7 -> V_373 ) {
case V_374 :
V_287 |= F_125 ( V_23 ) ;
break;
case V_375 :
V_287 |= F_126 ( V_23 ) ;
break;
}
}
if ( V_7 -> V_191 )
V_287 |=
F_122 ( V_23 ,
V_7 -> V_191 ) ;
F_94 ( V_12 , V_287 ) ;
#endif
}
return 0 ;
}
static int F_127 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_257 , struct V_343 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_376 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_56 )
return - V_43 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_128 ( V_257 , V_12 -> V_26 . V_258 ) )
return - V_43 ;
if ( F_129 ( V_257 ) )
return - V_43 ;
V_23 = F_130 ( V_12 , V_257 , V_278 ) ;
if ( ! V_23 )
return - V_279 ;
F_131 ( V_23 , V_339 ) ;
F_131 ( V_23 , V_340 ) ;
V_13 = F_115 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_132 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_28 ( V_23 , V_220 ) )
F_133 ( V_23 ) ;
V_376 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_56 ;
V_13 = F_134 ( V_23 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
if ( V_376 )
F_106 ( V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_135 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_257 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_257 )
return F_136 ( V_12 , V_257 ) ;
F_137 ( V_12 ) ;
return 0 ;
}
static int F_138 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_257 ,
struct V_343 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_377 ;
int V_13 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_257 ) ;
if ( ! V_23 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_51 ;
}
if ( V_12 -> V_26 . type == V_24 &&
( V_7 -> V_357 || V_7 -> V_361 || V_7 -> V_362 ||
V_7 -> V_351 ||
( V_7 -> V_348 & F_59 ( V_211 ) ) ) &&
! F_28 ( V_23 , V_220 ) ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_378 = false ;
bool V_379 = false ;
V_377 = F_9 ( V_7 -> V_22 ) ;
if ( V_377 -> V_26 . type != V_20 &&
V_377 -> V_26 . type != V_56 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 -> V_260 -> V_21 ) {
if ( V_377 -> V_15 . V_22 . V_23 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_28 ;
}
F_88 ( V_377 -> V_15 . V_22 . V_23 , V_23 ) ;
V_379 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_88 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_378 = true ;
}
V_23 -> V_12 = V_377 ;
if ( V_23 -> V_239 == V_341 &&
V_378 != V_379 ) {
if ( V_379 )
F_139 ( & V_23 -> V_12 -> V_380 -> V_381 ) ;
else
F_140 ( & V_23 -> V_12 -> V_380 -> V_381 ) ;
}
F_106 ( V_23 ) ;
}
V_13 = F_115 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_33 ( & V_9 -> V_49 ) ;
return V_13 ;
}
if ( F_28 ( V_23 , V_220 ) && V_7 -> V_357 )
F_133 ( V_23 ) ;
F_33 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_348 & F_59 ( V_209 ) ) {
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
}
return 0 ;
}
static int F_143 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_382 , T_3 * V_383 )
{
struct V_11 * V_12 ;
struct V_384 * V_385 ;
struct V_34 * V_23 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_383 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_51 ;
}
V_13 = F_144 ( V_12 , V_382 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
V_385 = F_145 ( V_12 , V_382 ) ;
if ( ! V_385 ) {
F_43 () ;
return - V_386 ;
}
F_146 ( V_385 , V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_147 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_382 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_382 )
return F_148 ( V_12 , V_382 ) ;
F_149 ( V_12 ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_382 , T_3 * V_383 )
{
struct V_11 * V_12 ;
struct V_384 * V_385 ;
struct V_34 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_383 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_51 ;
}
V_385 = F_145 ( V_12 , V_382 ) ;
if ( ! V_385 ) {
F_43 () ;
return - V_51 ;
}
F_146 ( V_385 , V_23 ) ;
F_43 () ;
return 0 ;
}
static void F_151 ( struct V_384 * V_385 , T_3 * V_383 ,
struct V_387 * V_388 )
{
struct V_34 * V_389 = F_40 ( V_385 -> V_383 ) ;
if ( V_389 )
memcpy ( V_383 , V_389 -> V_23 . V_258 , V_259 ) ;
else
memset ( V_383 , 0 , V_259 ) ;
memset ( V_388 , 0 , sizeof( * V_388 ) ) ;
V_388 -> V_132 = V_390 ;
V_388 -> V_134 = V_391 |
V_392 |
V_393 |
V_394 |
V_395 |
V_396 |
V_397 ;
V_388 -> V_398 = V_385 -> V_399 . V_400 ;
V_388 -> V_401 = V_385 -> V_401 ;
V_388 -> V_402 = V_385 -> V_402 ;
if ( F_152 ( V_153 , V_385 -> V_403 ) )
V_388 -> V_404 = F_55 ( V_385 -> V_403 - V_153 ) ;
V_388 -> V_405 =
F_55 ( V_385 -> V_405 ) ;
V_388 -> V_406 = V_385 -> V_406 ;
if ( V_385 -> V_5 & V_407 )
V_388 -> V_5 |= V_408 ;
if ( V_385 -> V_5 & V_409 )
V_388 -> V_5 |= V_410 ;
if ( V_385 -> V_5 & V_411 )
V_388 -> V_5 |= V_412 ;
if ( V_385 -> V_5 & V_413 )
V_388 -> V_5 |= V_414 ;
if ( V_385 -> V_5 & V_415 )
V_388 -> V_5 |= V_416 ;
}
static int F_153 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_382 , T_3 * V_383 , struct V_387 * V_388 )
{
struct V_11 * V_12 ;
struct V_384 * V_385 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_385 = F_145 ( V_12 , V_382 ) ;
if ( ! V_385 ) {
F_43 () ;
return - V_51 ;
}
memcpy ( V_382 , V_385 -> V_382 , V_259 ) ;
F_151 ( V_385 , V_383 , V_388 ) ;
F_43 () ;
return 0 ;
}
static int F_154 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_98 , T_3 * V_382 , T_3 * V_383 ,
struct V_387 * V_388 )
{
struct V_11 * V_12 ;
struct V_384 * V_385 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_385 = F_155 ( V_12 , V_98 ) ;
if ( ! V_385 ) {
F_43 () ;
return - V_51 ;
}
memcpy ( V_382 , V_385 -> V_382 , V_259 ) ;
F_151 ( V_385 , V_383 , V_388 ) ;
F_43 () ;
return 0 ;
}
static int F_156 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_417 * V_47 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_47 , & ( V_12 -> V_15 . V_60 . V_365 ) , sizeof( struct V_417 ) ) ;
return 0 ;
}
static inline bool F_157 ( enum V_418 V_419 , T_1 V_208 )
{
return ( V_208 >> ( V_419 - 1 ) ) & 0x1 ;
}
static int F_158 ( struct V_420 * V_421 ,
const struct V_422 * V_423 )
{
T_3 * V_424 ;
const T_3 * V_425 ;
struct V_11 * V_12 = F_159 ( V_421 ,
struct V_11 , V_15 . V_60 ) ;
V_424 = NULL ;
V_425 = V_421 -> V_426 ;
if ( V_423 -> V_427 ) {
V_424 = F_160 ( V_423 -> V_426 , V_423 -> V_427 ,
V_278 ) ;
if ( ! V_424 )
return - V_279 ;
}
V_421 -> V_427 = V_423 -> V_427 ;
V_421 -> V_426 = V_424 ;
F_161 ( V_425 ) ;
V_421 -> V_428 = V_423 -> V_428 ;
memcpy ( V_421 -> V_429 , V_423 -> V_429 , V_421 -> V_428 ) ;
V_421 -> V_430 = V_423 -> V_431 ;
V_421 -> V_432 = V_423 -> V_433 ;
V_421 -> V_434 = V_423 -> V_435 ;
V_421 -> V_61 = V_62 ;
if ( V_423 -> V_436 )
V_421 -> V_61 |= V_437 ;
if ( V_423 -> V_438 )
V_421 -> V_61 |= V_363 ;
memcpy ( V_12 -> V_26 . V_195 . V_439 , V_423 -> V_439 ,
sizeof( V_423 -> V_439 ) ) ;
V_12 -> V_26 . V_195 . V_205 = V_423 -> V_204 ;
V_12 -> V_26 . V_195 . V_202 = V_423 -> V_202 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_208 ,
const struct V_417 * V_440 )
{
struct V_417 * V_47 ;
struct V_11 * V_12 ;
struct V_420 * V_421 ;
V_12 = F_9 ( V_18 ) ;
V_421 = & V_12 -> V_15 . V_60 ;
V_47 = & ( V_12 -> V_15 . V_60 . V_365 ) ;
if ( F_157 ( V_441 , V_208 ) )
V_47 -> V_442 = V_440 -> V_442 ;
if ( F_157 ( V_443 , V_208 ) )
V_47 -> V_444 = V_440 -> V_444 ;
if ( F_157 ( V_445 , V_208 ) )
V_47 -> V_446 = V_440 -> V_446 ;
if ( F_157 ( V_447 , V_208 ) )
V_47 -> V_448 = V_440 -> V_448 ;
if ( F_157 ( V_449 , V_208 ) )
V_47 -> V_450 = V_440 -> V_450 ;
if ( F_157 ( V_451 , V_208 ) )
V_47 -> V_452 = V_440 -> V_452 ;
if ( F_157 ( V_453 , V_208 ) )
V_47 -> V_454 = V_440 -> V_454 ;
if ( F_157 ( V_455 , V_208 ) )
V_47 -> V_456 = V_440 -> V_456 ;
if ( F_157 ( V_457 , V_208 ) )
V_47 -> V_458 =
V_440 -> V_458 ;
if ( F_157 ( V_459 , V_208 ) )
V_47 -> V_460 =
V_440 -> V_460 ;
if ( F_157 ( V_461 , V_208 ) )
V_47 -> V_462 = V_440 -> V_462 ;
if ( F_157 ( V_463 , V_208 ) )
V_47 -> V_464 = V_440 -> V_464 ;
if ( F_157 ( V_465 , V_208 ) )
V_47 -> V_466 =
V_440 -> V_466 ;
if ( F_157 ( V_467 , V_208 ) )
V_47 -> V_468 =
V_440 -> V_468 ;
if ( F_157 ( V_469 , V_208 ) )
V_47 -> V_470 =
V_440 -> V_470 ;
if ( F_157 ( V_471 ,
V_208 ) )
V_47 -> V_472 =
V_440 -> V_472 ;
if ( F_157 ( V_473 , V_208 ) ) {
V_47 -> V_474 = V_440 -> V_474 ;
F_163 ( V_421 ) ;
}
if ( F_157 ( V_475 , V_208 ) ) {
if ( V_440 -> V_476 &&
! ( V_47 -> V_474 > V_477 ) ) {
V_47 -> V_474 = V_478 ;
F_163 ( V_421 ) ;
}
V_47 -> V_476 =
V_440 -> V_476 ;
}
if ( F_157 ( V_479 , V_208 ) )
V_47 -> V_480 =
V_440 -> V_480 ;
if ( F_157 ( V_481 , V_208 ) )
V_47 -> V_482 = V_440 -> V_482 ;
if ( F_157 ( V_483 , V_208 ) ) {
if ( ! ( V_12 -> V_9 -> V_104 . V_5 & V_166 ) )
return - V_484 ;
V_47 -> V_485 = V_440 -> V_485 ;
}
if ( F_157 ( V_486 , V_208 ) ) {
V_47 -> V_487 = V_440 -> V_487 ;
V_12 -> V_26 . V_195 . V_488 = V_440 -> V_487 ;
F_94 ( V_12 , V_489 ) ;
}
if ( F_157 ( V_490 , V_208 ) )
V_47 -> V_491 =
V_440 -> V_491 ;
if ( F_157 ( V_492 , V_208 ) )
V_47 -> V_493 =
V_440 -> V_493 ;
if ( F_157 ( V_494 , V_208 ) )
V_47 -> V_495 =
V_440 -> V_495 ;
if ( F_157 ( V_496 , V_208 ) ) {
V_47 -> V_366 = V_440 -> V_366 ;
F_124 ( V_12 ) ;
}
if ( F_157 ( V_497 , V_208 ) )
V_47 -> V_498 =
V_440 -> V_498 ;
F_164 ( V_12 , V_288 ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_417 * V_47 ,
const struct V_422 * V_423 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_420 * V_421 = & V_12 -> V_15 . V_60 ;
int V_13 ;
memcpy ( & V_421 -> V_365 , V_47 , sizeof( struct V_417 ) ) ;
V_13 = F_158 ( V_421 , V_423 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_302 = V_303 ;
V_12 -> V_304 = V_12 -> V_9 -> V_305 ;
V_13 = F_82 ( V_12 , & V_423 -> V_262 ,
V_307 ) ;
if ( V_13 )
return V_13 ;
return F_166 ( V_12 ) ;
}
static int F_167 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_168 ( V_12 ) ;
F_81 ( V_12 ) ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_499 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_346 V_347 ;
T_1 V_287 = 0 ;
if ( ! F_86 ( V_12 -> V_15 . V_277 . V_289 ) )
return - V_51 ;
V_347 = F_51 ( V_12 ) ;
if ( V_7 -> V_196 >= 0 ) {
V_12 -> V_26 . V_195 . V_196 = V_7 -> V_196 ;
V_287 |= V_500 ;
}
if ( V_7 -> V_198 >= 0 ) {
V_12 -> V_26 . V_195 . V_198 =
V_7 -> V_198 ;
V_287 |= V_501 ;
}
if ( ! V_12 -> V_26 . V_195 . V_200 &&
V_347 == V_502 ) {
V_12 -> V_26 . V_195 . V_200 = true ;
V_287 |= V_503 ;
}
if ( V_7 -> V_504 >= 0 ) {
V_12 -> V_26 . V_195 . V_200 =
V_7 -> V_504 ;
V_287 |= V_503 ;
}
if ( V_7 -> V_505 ) {
int V_235 , V_345 ;
T_1 V_344 = 0 ;
struct V_102 * V_103 = V_2 -> V_105 [ V_347 ] ;
for ( V_235 = 0 ; V_235 < V_7 -> V_506 ; V_235 ++ ) {
int V_92 = ( V_7 -> V_505 [ V_235 ] & 0x7f ) * 5 ;
for ( V_345 = 0 ; V_345 < V_103 -> V_359 ; V_345 ++ ) {
if ( V_103 -> V_107 [ V_345 ] . V_108 == V_92 )
V_344 |= F_59 ( V_345 ) ;
}
}
V_12 -> V_26 . V_195 . V_505 = V_344 ;
V_287 |= V_507 ;
}
if ( V_7 -> V_508 >= 0 ) {
if ( V_7 -> V_508 )
V_12 -> V_5 |= V_509 ;
else
V_12 -> V_5 &= ~ V_509 ;
}
if ( V_7 -> V_487 >= 0 ) {
V_12 -> V_26 . V_195 . V_488 =
( T_2 ) V_7 -> V_487 ;
V_287 |= V_489 ;
}
if ( V_7 -> V_317 >= 0 ) {
V_12 -> V_26 . V_195 . V_317 = V_7 -> V_317 ;
V_287 |= V_300 ;
}
if ( V_7 -> V_319 >= 0 ) {
V_12 -> V_26 . V_195 . V_318 = V_7 -> V_319 ;
V_287 |= V_300 ;
}
F_94 ( V_12 , V_287 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_510 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_511 V_512 ;
if ( ! V_9 -> V_170 -> V_513 )
return - V_225 ;
if ( V_9 -> V_104 . V_514 < V_515 )
return - V_225 ;
memset ( & V_512 , 0 , sizeof( V_512 ) ) ;
V_512 . V_516 = V_7 -> V_516 ;
V_512 . V_517 = V_7 -> V_518 ;
V_512 . V_519 = V_7 -> V_520 ;
V_512 . V_521 = V_7 -> V_521 ;
V_512 . V_522 = false ;
V_12 -> V_523 [ V_7 -> V_524 ] = V_512 ;
if ( F_171 ( V_9 , V_12 , V_7 -> V_524 , & V_512 ) ) {
F_172 ( V_9 -> V_104 . V_2 ,
L_1 ,
V_7 -> V_524 ) ;
return - V_43 ;
}
F_94 ( V_12 , V_525 ) ;
return 0 ;
}
static int F_173 ( struct V_2 * V_2 ,
struct V_526 * V_527 )
{
return F_174 ( F_2 ( V_2 ) , V_527 ) ;
}
static int F_175 ( struct V_2 * V_2 )
{
return F_176 ( F_2 ( V_2 ) ) ;
}
static int F_177 ( struct V_2 * V_2 ,
struct V_528 * V_529 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_529 -> V_10 ) ;
switch ( F_178 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_58 :
case V_59 :
case V_67 :
case V_64 :
break;
case V_68 :
if ( V_12 -> V_9 -> V_170 -> V_530 )
break;
case V_56 :
if ( V_12 -> V_15 . V_277 . V_289 &&
( ! ( V_2 -> V_531 & V_532 ) ||
! ( V_529 -> V_5 & V_533 ) ) )
return - V_225 ;
break;
default:
return - V_225 ;
}
return F_179 ( V_12 , V_529 ) ;
}
static int
F_180 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_534 * V_529 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_170 -> V_535 )
return - V_225 ;
return F_181 ( V_12 , V_529 ) ;
}
static int
F_182 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_170 -> V_536 )
return - V_225 ;
return F_183 ( V_12 ) ;
}
static int F_184 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_537 * V_529 )
{
return F_185 ( F_9 ( V_18 ) , V_529 ) ;
}
static int F_186 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_538 * V_529 )
{
return F_187 ( F_9 ( V_18 ) , V_529 ) ;
}
static int F_188 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_539 * V_529 )
{
return F_189 ( F_9 ( V_18 ) , V_529 ) ;
}
static int F_190 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_540 * V_529 )
{
return F_191 ( F_9 ( V_18 ) , V_529 ) ;
}
static int F_192 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_541 * V_7 )
{
return F_193 ( F_9 ( V_18 ) , V_7 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
return F_195 ( F_9 ( V_18 ) ) ;
}
static int F_196 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_92 [ V_542 ] )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( V_12 -> V_26 . V_195 . V_439 , V_92 ,
sizeof( int ) * V_542 ) ;
return 0 ;
}
static int F_197 ( struct V_2 * V_2 , T_1 V_287 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_287 & V_543 ) {
V_13 = F_198 ( V_9 , V_2 -> V_544 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_287 & V_545 ) {
V_13 = F_199 ( V_9 , V_2 -> V_546 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_287 & V_547 ) {
V_13 = F_200 ( V_9 , V_2 -> V_548 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_287 & V_549 ) {
if ( V_2 -> V_550 > V_551 )
return - V_43 ;
V_9 -> V_104 . V_47 . V_552 = V_2 -> V_550 ;
}
if ( V_287 & V_553 ) {
if ( V_2 -> V_554 > V_551 )
return - V_43 ;
V_9 -> V_104 . V_47 . V_555 = V_2 -> V_554 ;
}
if ( V_287 &
( V_549 | V_553 ) )
F_84 ( V_9 , V_556 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_557 type , int V_558 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
if ( V_10 ) {
V_12 = F_5 ( V_10 ) ;
switch ( type ) {
case V_559 :
V_12 -> V_560 = V_561 ;
break;
case V_562 :
case V_563 :
if ( V_558 < 0 || ( V_558 % 100 ) )
return - V_225 ;
V_12 -> V_560 = F_202 ( V_558 ) ;
break;
}
F_203 ( V_12 ) ;
return 0 ;
}
switch ( type ) {
case V_559 :
V_9 -> V_560 = V_561 ;
break;
case V_562 :
case V_563 :
if ( V_558 < 0 || ( V_558 % 100 ) )
return - V_225 ;
V_9 -> V_560 = F_202 ( V_558 ) ;
break;
}
F_24 ( & V_9 -> V_264 ) ;
F_67 (sdata, &local->interfaces, list)
V_12 -> V_560 = V_9 -> V_560 ;
F_67 (sdata, &local->interfaces, list)
F_203 ( V_12 ) ;
F_33 ( & V_9 -> V_264 ) ;
return 0 ;
}
static int F_204 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
int * V_564 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_265 )
* V_564 = V_9 -> V_104 . V_47 . V_565 ;
else
* V_564 = V_12 -> V_26 . V_195 . V_566 ;
return 0 ;
}
static int F_205 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_258 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_567 . V_568 , V_258 , V_259 ) ;
return 0 ;
}
static void F_206 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_207 ( V_9 ) ;
}
static int F_208 ( struct V_2 * V_2 , void * V_228 , int V_280 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_170 -> V_569 )
return - V_225 ;
return V_9 -> V_170 -> V_569 ( & V_9 -> V_104 , V_228 , V_280 ) ;
}
static int F_209 ( struct V_2 * V_2 ,
struct V_329 * V_330 ,
struct V_570 * V_338 ,
void * V_228 , int V_280 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_170 -> V_571 )
return - V_225 ;
return V_9 -> V_170 -> V_571 ( & V_9 -> V_104 , V_330 , V_338 , V_228 , V_280 ) ;
}
int F_210 ( struct V_11 * V_12 ,
enum V_572 V_302 )
{
const T_3 * V_277 ;
enum V_572 V_573 ;
int V_13 ;
F_211 ( & V_12 -> V_15 . V_25 . V_574 ) ;
V_573 = V_12 -> V_15 . V_25 . V_575 ;
V_12 -> V_15 . V_25 . V_575 = V_302 ;
if ( V_573 == V_302 &&
V_302 != V_576 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_577 ||
V_12 -> V_26 . V_195 . V_262 . V_578 == V_579 )
return 0 ;
V_277 = V_12 -> V_15 . V_25 . V_577 -> V_237 ;
if ( V_302 == V_576 ) {
if ( V_12 -> V_15 . V_25 . V_580 )
V_302 = V_581 ;
else
V_302 = V_303 ;
}
V_13 = F_212 ( V_12 , V_302 ,
V_277 , V_277 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_575 = V_573 ;
return V_13 ;
}
static int F_213 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_582 , int V_583 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_75 ( V_18 -> V_260 ) ;
if ( V_12 -> V_26 . type != V_24 &&
V_12 -> V_26 . type != V_59 )
return - V_225 ;
if ( ! ( V_9 -> V_104 . V_5 & V_584 ) )
return - V_225 ;
if ( V_582 == V_12 -> V_15 . V_25 . V_580 &&
V_583 == V_9 -> V_585 )
return 0 ;
V_12 -> V_15 . V_25 . V_580 = V_582 ;
V_9 -> V_585 = V_583 ;
F_24 ( & V_12 -> V_15 . V_25 . V_574 ) ;
F_210 ( V_12 , V_12 -> V_15 . V_25 . V_575 ) ;
F_33 ( & V_12 -> V_15 . V_25 . V_574 ) ;
if ( V_9 -> V_104 . V_5 & V_586 )
F_84 ( V_9 , V_587 ) ;
F_141 ( V_9 , - 1 ) ;
F_142 ( V_12 ) ;
return 0 ;
}
static int F_214 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_588 , T_1 V_589 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_590 * V_26 = & V_12 -> V_26 ;
struct V_591 * V_195 = & V_26 -> V_195 ;
if ( V_588 == V_195 -> V_592 &&
V_589 == V_195 -> V_593 )
return 0 ;
V_195 -> V_592 = V_588 ;
V_195 -> V_593 = V_589 ;
if ( V_12 -> V_15 . V_25 . V_577 &&
V_12 -> V_26 . V_594 & V_595 )
F_94 ( V_12 , V_596 ) ;
return 0 ;
}
static int F_215 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_258 ,
const struct V_597 * V_208 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_75 ( V_18 -> V_260 ) ;
int V_235 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_37 ;
if ( V_9 -> V_104 . V_5 & V_598 ) {
V_19 = F_216 ( V_9 , V_12 , V_208 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_235 = 0 ; V_235 < V_542 ; V_235 ++ ) {
V_12 -> V_599 [ V_235 ] = V_208 -> V_335 [ V_235 ] . V_106 ;
memcpy ( V_12 -> V_600 [ V_235 ] , V_208 -> V_335 [ V_235 ] . V_97 ,
sizeof( V_208 -> V_335 [ V_235 ] . V_97 ) ) ;
}
return 0 ;
}
static int F_217 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_231 * V_232 ,
unsigned int V_601 , T_4 * V_73 ,
struct V_329 * V_602 )
{
struct V_603 * V_604 , * V_605 ;
bool V_606 = false ;
int V_19 ;
F_211 ( & V_9 -> V_574 ) ;
if ( V_9 -> V_265 && ! V_9 -> V_170 -> V_607 )
return - V_225 ;
V_604 = F_87 ( sizeof( * V_604 ) , V_278 ) ;
if ( ! V_604 )
return - V_279 ;
V_604 -> V_241 = V_232 ;
V_604 -> V_601 = V_601 ;
V_604 -> V_608 = V_601 ;
V_604 -> V_609 = V_602 ;
V_604 -> V_610 = ( unsigned long ) V_602 ;
V_604 -> V_12 = V_12 ;
F_218 ( & V_604 -> V_611 , V_612 ) ;
F_219 ( & V_604 -> V_613 ) ;
if ( ! F_220 ( & V_9 -> V_614 ) ||
V_9 -> V_615 || V_9 -> V_616 )
goto V_617;
if ( ! V_9 -> V_170 -> V_607 ) {
F_221 ( & V_9 -> V_104 , & V_604 -> V_611 , 0 ) ;
goto V_618;
}
if ( ! V_601 )
V_601 = 10 ;
V_19 = F_222 ( V_9 , V_12 , V_232 , V_601 ) ;
if ( V_19 ) {
F_161 ( V_604 ) ;
return V_19 ;
}
V_604 -> V_619 = true ;
goto V_618;
V_617:
F_67 (tmp, &local->roc_list, list) {
if ( V_605 -> V_241 != V_232 || V_605 -> V_12 != V_12 )
continue;
if ( ! V_605 -> V_619 ) {
F_223 ( & V_604 -> V_620 , & V_605 -> V_613 ) ;
V_605 -> V_601 = F_224 ( V_605 -> V_601 , V_604 -> V_601 ) ;
V_606 = true ;
break;
}
if ( V_9 -> V_170 -> V_607 ) {
unsigned long V_345 = V_153 ;
if ( ! V_605 -> V_621 ) {
F_223 ( & V_604 -> V_620 , & V_605 -> V_613 ) ;
V_606 = true ;
break;
}
if ( F_152 ( V_345 + V_622 ,
V_605 -> V_623 +
F_225 ( V_605 -> V_601 ) ) ) {
int V_624 ;
F_226 ( V_604 ) ;
V_624 = V_604 -> V_601 -
F_55 ( V_605 -> V_623 +
F_225 (
V_605 -> V_601 ) -
V_345 ) ;
if ( V_624 > 0 ) {
F_227 ( & V_604 -> V_620 , & V_605 -> V_620 ) ;
} else {
F_223 ( & V_604 -> V_620 ,
& V_605 -> V_613 ) ;
}
V_606 = true ;
}
} else if ( F_228 ( & V_605 -> V_611 . V_625 ) ) {
unsigned long V_626 ;
F_223 ( & V_604 -> V_620 , & V_605 -> V_613 ) ;
V_606 = true ;
V_626 = V_153 + F_225 ( V_604 -> V_601 ) ;
if ( F_229 ( V_626 , V_605 -> V_611 . V_625 . V_627 ) )
F_230 ( & V_605 -> V_611 . V_625 , V_626 ) ;
else
F_231 ( & V_605 -> V_611 . V_625 ) ;
F_226 ( V_604 ) ;
}
break;
}
V_618:
if ( ! V_606 )
F_223 ( & V_604 -> V_620 , & V_9 -> V_614 ) ;
if ( ! V_602 ) {
V_9 -> V_628 ++ ;
V_604 -> V_73 = V_9 -> V_628 ;
if ( F_65 ( V_604 -> V_73 == 0 ) ) {
V_604 -> V_73 = 1 ;
V_9 -> V_628 ++ ;
}
* V_73 = V_604 -> V_73 ;
} else {
* V_73 = ( unsigned long ) V_602 ;
}
return 0 ;
}
static int F_232 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_231 * V_241 ,
unsigned int V_601 ,
T_4 * V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_24 ( & V_9 -> V_574 ) ;
V_19 = F_217 ( V_9 , V_12 , V_241 ,
V_601 , V_73 , NULL ) ;
F_33 ( & V_9 -> V_574 ) ;
return V_19 ;
}
static int F_233 ( struct V_8 * V_9 ,
T_4 V_73 , bool V_629 )
{
struct V_603 * V_604 , * V_605 , * V_630 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_574 ) ;
F_234 (roc, tmp, &local->roc_list, list) {
struct V_603 * V_631 , * V_632 ;
F_234 (dep, tmp2, &roc->dependents, list) {
if ( ! V_629 && V_631 -> V_73 != V_73 )
continue;
else if ( V_629 && V_631 -> V_610 != V_73 )
continue;
F_235 ( & V_631 -> V_620 ) ;
F_33 ( & V_9 -> V_574 ) ;
F_236 ( V_631 , true ) ;
return 0 ;
}
if ( ! V_629 && V_604 -> V_73 != V_73 )
continue;
else if ( V_629 && V_604 -> V_610 != V_73 )
continue;
V_630 = V_604 ;
break;
}
if ( ! V_630 ) {
F_33 ( & V_9 -> V_574 ) ;
return - V_51 ;
}
if ( V_9 -> V_170 -> V_607 ) {
if ( V_630 -> V_619 ) {
V_19 = F_237 ( V_9 ) ;
if ( F_31 ( V_19 ) ) {
F_33 ( & V_9 -> V_574 ) ;
return V_19 ;
}
}
F_235 ( & V_630 -> V_620 ) ;
if ( V_630 -> V_619 )
F_238 ( V_9 ) ;
F_33 ( & V_9 -> V_574 ) ;
F_236 ( V_630 , true ) ;
} else {
V_630 -> abort = true ;
F_221 ( & V_9 -> V_104 , & V_630 -> V_611 , 0 ) ;
F_33 ( & V_9 -> V_574 ) ;
F_239 ( & V_630 -> V_611 ) ;
F_65 ( ! V_630 -> V_633 ) ;
F_161 ( V_630 ) ;
}
return 0 ;
}
static int F_240 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_233 ( V_9 , V_73 , false ) ;
}
static int F_241 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_261 * V_262 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
unsigned long V_583 ;
int V_13 ;
if ( ! F_220 ( & V_9 -> V_614 ) || V_9 -> V_615 )
return - V_28 ;
V_12 -> V_302 = V_303 ;
V_12 -> V_304 = V_9 -> V_305 ;
V_12 -> V_306 = true ;
F_24 ( & V_9 -> V_264 ) ;
V_13 = F_82 ( V_12 , V_262 ,
V_307 ) ;
F_33 ( & V_9 -> V_264 ) ;
if ( V_13 )
return V_13 ;
V_583 = F_225 ( V_634 ) ;
F_221 ( & V_12 -> V_9 -> V_104 ,
& V_12 -> V_635 , V_583 ) ;
return 0 ;
}
static int F_242 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_231 * V_241 , bool V_636 ,
unsigned int V_637 , const T_3 * V_638 , T_5 V_280 ,
bool V_639 , bool V_640 , T_4 * V_73 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_329 * V_330 ;
struct V_34 * V_23 ;
const struct V_641 * V_642 = ( void * ) V_638 ;
bool V_643 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_640 )
V_5 = V_644 ;
else
V_5 = V_645 |
V_646 ;
if ( V_639 )
V_5 |= V_647 ;
switch ( V_12 -> V_26 . type ) {
case V_58 :
if ( ! V_12 -> V_26 . V_195 . V_648 )
V_643 = true ;
#ifdef F_30
case V_59 :
if ( F_25 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_60 . V_428 )
V_643 = true ;
#endif
case V_56 :
case V_20 :
case V_68 :
if ( V_12 -> V_26 . type != V_58 &&
! F_25 ( & V_12 -> V_26 ) &&
! F_243 ( V_12 -> V_380 -> V_289 ) )
V_643 = true ;
if ( ! F_244 ( V_642 -> V_649 ) ||
V_642 -> V_15 . V_650 . V_651 == V_652 )
break;
F_39 () ;
V_23 = F_26 ( V_12 , V_642 -> V_331 ) ;
F_43 () ;
if ( ! V_23 )
return - V_653 ;
break;
case V_24 :
case V_67 :
if ( ! V_12 -> V_15 . V_25 . V_577 )
V_643 = true ;
break;
case V_64 :
V_643 = true ;
break;
default:
return - V_225 ;
}
F_24 ( & V_9 -> V_574 ) ;
if ( ! V_643 ) {
struct V_229 * V_230 ;
F_39 () ;
V_230 = F_40 ( V_12 -> V_26 . V_230 ) ;
if ( V_230 )
V_643 = V_241 != V_230 -> V_240 . V_241 ;
else
V_643 = true ;
F_43 () ;
}
if ( V_643 && ! V_636 ) {
V_19 = - V_28 ;
goto V_52;
}
V_330 = F_107 ( V_9 -> V_104 . V_654 + V_280 ) ;
if ( ! V_330 ) {
V_19 = - V_279 ;
goto V_52;
}
F_245 ( V_330 , V_9 -> V_104 . V_654 ) ;
memcpy ( F_108 ( V_330 , V_280 ) , V_638 , V_280 ) ;
F_246 ( V_330 ) -> V_5 = V_5 ;
V_330 -> V_18 = V_12 -> V_18 ;
if ( ! V_643 ) {
* V_73 = ( unsigned long ) V_330 ;
F_247 ( V_12 , V_330 ) ;
V_19 = 0 ;
goto V_52;
}
F_246 ( V_330 ) -> V_5 |= V_655 |
V_656 ;
if ( V_9 -> V_104 . V_5 & V_657 )
F_246 ( V_330 ) -> V_658 =
V_9 -> V_104 . V_659 ;
V_19 = F_217 ( V_9 , V_12 , V_241 ,
V_637 , V_73 , V_330 ) ;
if ( V_19 )
F_248 ( V_330 ) ;
V_52:
F_33 ( & V_9 -> V_574 ) ;
return V_19 ;
}
static int F_249 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_73 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_233 ( V_9 , V_73 , true ) ;
}
static void F_250 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_660 , bool V_661 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( V_660 ) {
case V_662 | V_663 :
if ( V_12 -> V_26 . type == V_58 ) {
struct V_664 * V_665 = & V_12 -> V_15 . V_666 ;
if ( V_661 )
V_665 -> V_667 ++ ;
else
V_665 -> V_667 -- ;
}
break;
case V_662 | V_668 :
if ( V_661 )
V_9 -> V_669 ++ ;
else
V_9 -> V_669 -- ;
if ( ! V_9 -> V_268 )
break;
F_251 ( & V_9 -> V_104 , & V_9 -> V_670 ) ;
break;
default:
break;
}
}
static int F_252 ( struct V_2 * V_2 , T_1 V_671 , T_1 V_672 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_619 )
return - V_225 ;
return F_253 ( V_9 , V_671 , V_672 ) ;
}
static int F_254 ( struct V_2 * V_2 , T_1 * V_671 , T_1 * V_672 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_255 ( V_9 , V_671 , V_672 ) ;
}
static int F_256 ( struct V_2 * V_2 , T_1 V_80 , T_1 V_673 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_257 ( V_9 , V_80 , V_673 ) ;
}
static void F_258 ( struct V_2 * V_2 ,
T_1 * V_80 , T_1 * V_674 , T_1 * V_673 , T_1 * V_675 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_259 ( V_9 , V_80 , V_674 , V_673 , V_675 ) ;
}
static int F_260 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_676 * V_228 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_170 -> V_677 )
return - V_225 ;
F_261 ( V_9 , V_12 , V_228 ) ;
return 0 ;
}
static void F_262 ( struct V_329 * V_330 )
{
T_3 * V_678 = ( void * ) F_108 ( V_330 , 7 ) ;
* V_678 ++ = V_679 ;
* V_678 ++ = 5 ;
* V_678 ++ = 0x0 ;
* V_678 ++ = 0x0 ;
* V_678 ++ = 0x0 ;
* V_678 ++ = 0x0 ;
* V_678 ++ = V_680 ;
}
static T_2 F_263 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_681 ;
V_681 = 0 ;
if ( F_51 ( V_12 ) != V_682 )
return V_681 ;
if ( ! ( V_9 -> V_104 . V_5 & V_683 ) )
V_681 |= V_684 ;
if ( ! ( V_9 -> V_104 . V_5 & V_685 ) )
V_681 |= V_686 ;
return V_681 ;
}
static void F_264 ( struct V_329 * V_330 , T_3 * V_687 ,
T_3 * V_688 , T_3 * V_237 )
{
struct V_689 * V_690 ;
V_690 = ( void * ) F_108 ( V_330 , sizeof( struct V_689 ) ) ;
V_690 -> V_691 = V_692 ;
V_690 -> V_427 = sizeof( struct V_689 ) - 2 ;
memcpy ( V_690 -> V_237 , V_237 , V_259 ) ;
memcpy ( V_690 -> V_693 , V_687 , V_259 ) ;
memcpy ( V_690 -> V_694 , V_688 , V_259 ) ;
}
static int
F_265 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_688 , T_3 V_695 , T_3 V_696 ,
T_2 V_697 , struct V_329 * V_330 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_346 V_347 = F_51 ( V_12 ) ;
struct V_698 * V_699 ;
V_699 = ( void * ) F_108 ( V_330 , F_266 ( struct V_698 , V_15 ) ) ;
memcpy ( V_699 -> V_331 , V_688 , V_259 ) ;
memcpy ( V_699 -> V_332 , V_12 -> V_26 . V_258 , V_259 ) ;
V_699 -> V_700 = F_267 ( V_701 ) ;
V_699 -> V_702 = V_703 ;
switch ( V_695 ) {
case V_704 :
V_699 -> V_651 = V_705 ;
V_699 -> V_695 = V_704 ;
F_108 ( V_330 , sizeof( V_699 -> V_15 . V_706 ) ) ;
V_699 -> V_15 . V_706 . V_696 = V_696 ;
V_699 -> V_15 . V_706 . V_707 =
F_268 ( F_263 ( V_12 ) ) ;
F_269 ( V_12 , V_330 , false , V_347 ) ;
F_270 ( V_12 , V_330 , false , V_347 ) ;
F_262 ( V_330 ) ;
break;
case V_708 :
V_699 -> V_651 = V_705 ;
V_699 -> V_695 = V_708 ;
F_108 ( V_330 , sizeof( V_699 -> V_15 . V_709 ) ) ;
V_699 -> V_15 . V_709 . V_697 = F_268 ( V_697 ) ;
V_699 -> V_15 . V_709 . V_696 = V_696 ;
V_699 -> V_15 . V_709 . V_707 =
F_268 ( F_263 ( V_12 ) ) ;
F_269 ( V_12 , V_330 , false , V_347 ) ;
F_270 ( V_12 , V_330 , false , V_347 ) ;
F_262 ( V_330 ) ;
break;
case V_710 :
V_699 -> V_651 = V_705 ;
V_699 -> V_695 = V_710 ;
F_108 ( V_330 , sizeof( V_699 -> V_15 . V_711 ) ) ;
V_699 -> V_15 . V_711 . V_697 = F_268 ( V_697 ) ;
V_699 -> V_15 . V_711 . V_696 = V_696 ;
break;
case V_712 :
V_699 -> V_651 = V_705 ;
V_699 -> V_695 = V_712 ;
F_108 ( V_330 , sizeof( V_699 -> V_15 . V_713 ) ) ;
V_699 -> V_15 . V_713 . V_714 = F_268 ( V_697 ) ;
break;
case V_715 :
V_699 -> V_651 = V_705 ;
V_699 -> V_695 = V_715 ;
F_108 ( V_330 , sizeof( V_699 -> V_15 . V_716 ) ) ;
V_699 -> V_15 . V_716 . V_696 = V_696 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int
F_271 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_688 , T_3 V_695 , T_3 V_696 ,
T_2 V_697 , struct V_329 * V_330 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
enum V_346 V_347 = F_51 ( V_12 ) ;
struct V_641 * V_642 ;
V_642 = ( void * ) F_108 ( V_330 , 24 ) ;
memset ( V_642 , 0 , 24 ) ;
memcpy ( V_642 -> V_331 , V_688 , V_259 ) ;
memcpy ( V_642 -> V_332 , V_12 -> V_26 . V_258 , V_259 ) ;
memcpy ( V_642 -> V_237 , V_12 -> V_15 . V_25 . V_237 , V_259 ) ;
V_642 -> V_649 = F_268 ( V_662 |
V_717 ) ;
switch ( V_695 ) {
case V_718 :
F_108 ( V_330 , 1 + sizeof( V_642 -> V_15 . V_650 . V_15 . V_719 ) ) ;
V_642 -> V_15 . V_650 . V_651 = V_652 ;
V_642 -> V_15 . V_650 . V_15 . V_719 . V_695 =
V_718 ;
V_642 -> V_15 . V_650 . V_15 . V_719 . V_696 =
V_696 ;
V_642 -> V_15 . V_650 . V_15 . V_719 . V_707 =
F_268 ( F_263 ( V_12 ) ) ;
F_269 ( V_12 , V_330 , false , V_347 ) ;
F_270 ( V_12 , V_330 , false , V_347 ) ;
F_262 ( V_330 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_272 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_688 , T_3 V_695 , T_3 V_696 ,
T_2 V_697 , const T_3 * V_720 ,
T_5 V_721 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_329 * V_330 = NULL ;
bool V_722 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_723 ) )
return - V_484 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_577 )
return - V_43 ;
F_273 ( V_12 , L_2 ,
V_695 , V_688 ) ;
V_330 = F_107 ( V_9 -> V_104 . V_654 +
F_224 ( sizeof( struct V_641 ) ,
sizeof( struct V_698 ) ) +
50 +
7 +
V_721 +
sizeof( struct V_689 ) ) ;
if ( ! V_330 )
return - V_279 ;
F_245 ( V_330 , V_9 -> V_104 . V_654 ) ;
switch ( V_695 ) {
case V_704 :
case V_708 :
case V_710 :
case V_712 :
case V_715 :
V_19 = F_265 ( V_2 , V_18 , V_688 ,
V_695 , V_696 ,
V_697 , V_330 ) ;
V_722 = false ;
break;
case V_718 :
V_19 = F_271 ( V_2 , V_18 , V_688 , V_695 ,
V_696 , V_697 ,
V_330 ) ;
V_722 = true ;
break;
default:
V_19 = - V_484 ;
break;
}
if ( V_19 < 0 )
goto V_724;
if ( V_721 )
memcpy ( F_108 ( V_330 , V_721 ) , V_720 , V_721 ) ;
switch ( V_695 ) {
case V_704 :
case V_710 :
case V_712 :
case V_715 :
F_264 ( V_330 , V_12 -> V_26 . V_258 , V_688 ,
V_12 -> V_15 . V_25 . V_237 ) ;
break;
case V_708 :
case V_718 :
F_264 ( V_330 , V_688 , V_12 -> V_26 . V_258 ,
V_12 -> V_15 . V_25 . V_237 ) ;
break;
default:
V_19 = - V_484 ;
goto V_724;
}
if ( V_722 ) {
F_247 ( V_12 , V_330 ) ;
return 0 ;
}
switch ( V_695 ) {
case V_704 :
case V_708 :
F_274 ( V_330 , V_725 ) ;
V_330 -> V_726 = 2 ;
break;
default:
F_274 ( V_330 , V_727 ) ;
V_330 -> V_726 = 5 ;
break;
}
F_275 () ;
V_19 = F_276 ( V_330 , V_18 ) ;
F_277 () ;
return V_19 ;
V_724:
F_278 ( V_330 ) ;
return V_19 ;
}
static int F_279 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_688 , enum V_728 V_729 )
{
struct V_34 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_723 ) )
return - V_484 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_43 ;
F_273 ( V_12 , L_3 , V_729 , V_688 ) ;
switch ( V_729 ) {
case V_730 :
F_39 () ;
V_23 = F_26 ( V_12 , V_688 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_653 ;
}
F_116 ( V_23 , V_731 ) ;
F_43 () ;
break;
case V_732 :
return F_280 ( V_12 , V_688 ) ;
case V_733 :
case V_734 :
case V_735 :
return - V_484 ;
default:
return - V_484 ;
}
return 0 ;
}
static int F_281 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_688 , T_4 * V_73 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_736 * V_737 ;
struct V_329 * V_330 ;
int V_286 = sizeof( * V_737 ) ;
T_7 V_738 ;
bool V_739 ;
struct V_740 * V_741 ;
struct V_34 * V_23 ;
struct V_229 * V_230 ;
enum V_346 V_347 ;
F_39 () ;
V_230 = F_40 ( V_12 -> V_26 . V_230 ) ;
if ( F_65 ( ! V_230 ) ) {
F_43 () ;
return - V_43 ;
}
V_347 = V_230 -> V_240 . V_241 -> V_347 ;
V_23 = F_26 ( V_12 , V_688 ) ;
if ( V_23 ) {
V_739 = F_28 ( V_23 , V_218 ) ;
} else {
F_43 () ;
return - V_653 ;
}
if ( V_739 ) {
V_738 = F_268 ( V_742 |
V_743 |
V_744 ) ;
} else {
V_286 -= 2 ;
V_738 = F_268 ( V_742 |
V_745 |
V_744 ) ;
}
V_330 = F_107 ( V_9 -> V_104 . V_654 + V_286 ) ;
if ( ! V_330 ) {
F_43 () ;
return - V_279 ;
}
V_330 -> V_18 = V_18 ;
F_245 ( V_330 , V_9 -> V_104 . V_654 ) ;
V_737 = ( void * ) F_108 ( V_330 , V_286 ) ;
V_737 -> V_649 = V_738 ;
V_737 -> V_746 = 0 ;
memcpy ( V_737 -> V_747 , V_23 -> V_23 . V_258 , V_259 ) ;
memcpy ( V_737 -> V_748 , V_12 -> V_26 . V_258 , V_259 ) ;
memcpy ( V_737 -> V_749 , V_12 -> V_26 . V_258 , V_259 ) ;
V_737 -> V_750 = 0 ;
V_741 = F_246 ( V_330 ) ;
V_741 -> V_5 |= V_646 |
V_645 ;
F_274 ( V_330 , V_751 ) ;
V_330 -> V_726 = 7 ;
if ( V_739 )
V_737 -> V_752 = F_268 ( 7 ) ;
F_275 () ;
F_282 ( V_12 , V_330 , V_347 ) ;
F_277 () ;
F_43 () ;
* V_73 = ( unsigned long ) V_330 ;
return 0 ;
}
static int F_283 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_261 * V_262 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_229 * V_230 ;
int V_19 = - V_753 ;
F_39 () ;
V_230 = F_40 ( V_12 -> V_26 . V_230 ) ;
if ( V_230 ) {
* V_262 = V_230 -> V_240 ;
V_19 = 0 ;
} else if ( V_9 -> V_268 > 0 &&
V_9 -> V_268 == V_9 -> V_269 &&
V_12 -> V_26 . type == V_14 ) {
if ( V_9 -> V_265 )
* V_262 = V_9 -> V_263 ;
else
F_284 ( V_262 ,
V_9 -> V_270 ,
V_9 -> V_271 ) ;
V_19 = 0 ;
}
F_43 () ;
return V_19 ;
}
static void F_285 ( struct V_2 * V_2 , bool V_582 )
{
F_286 ( F_2 ( V_2 ) , V_582 ) ;
}
