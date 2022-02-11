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
if ( ! V_23 ) {
F_28 ( V_12 -> V_9 , V_36 ) ;
V_13 = - V_50 ;
goto V_51;
}
}
switch ( V_12 -> V_26 . type ) {
case V_24 :
if ( V_12 -> V_15 . V_25 . V_52 != V_53 )
V_36 -> V_47 . V_5 |= V_54 ;
break;
case V_55 :
case V_20 :
if ( V_36 -> V_23 && F_29 ( V_36 -> V_23 , V_56 ) )
V_36 -> V_47 . V_5 |= V_54 ;
break;
case V_57 :
break;
case V_58 :
#ifdef F_30
if ( V_12 -> V_15 . V_59 . V_60 != V_61 )
V_36 -> V_47 . V_5 |= V_54 ;
break;
#endif
case V_62 :
case V_14 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_31 ( 1 ) ;
break;
}
V_13 = F_32 ( V_36 , V_12 , V_23 ) ;
if ( V_13 )
F_28 ( V_12 -> V_9 , V_36 ) ;
V_51:
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
F_24 ( & V_9 -> V_68 ) ;
if ( V_32 ) {
V_19 = - V_50 ;
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_51;
if ( V_31 )
V_36 = F_35 ( V_9 , V_23 -> V_69 ) ;
else
V_36 = F_35 ( V_9 , V_23 -> V_70 [ V_30 ] ) ;
} else
V_36 = F_35 ( V_9 , V_12 -> V_71 [ V_30 ] ) ;
if ( ! V_36 ) {
V_19 = - V_50 ;
goto V_51;
}
F_36 ( V_36 ) ;
V_19 = 0 ;
V_51:
F_33 ( & V_9 -> V_68 ) ;
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_37 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 ,
void * V_72 ,
void (* F_38)( void * V_72 ,
struct V_33 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_34 * V_23 = NULL ;
T_3 V_46 [ 6 ] = { 0 } ;
struct V_33 V_7 ;
struct V_35 * V_36 = NULL ;
T_4 V_73 ;
T_1 V_74 ;
T_2 V_75 ;
int V_13 = - V_50 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
if ( V_32 ) {
V_23 = F_27 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_76;
if ( V_31 )
V_36 = F_40 ( V_23 -> V_69 ) ;
else if ( V_30 < V_77 )
V_36 = F_40 ( V_23 -> V_70 [ V_30 ] ) ;
} else
V_36 = F_40 ( V_12 -> V_71 [ V_30 ] ) ;
if ( ! V_36 )
goto V_76;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_38 = V_36 -> V_47 . V_38 ;
switch ( V_36 -> V_47 . V_38 ) {
case V_40 :
V_74 = V_36 -> V_15 . V_78 . V_79 . V_74 ;
V_75 = V_36 -> V_15 . V_78 . V_79 . V_75 ;
if ( V_36 -> V_5 & V_80 )
F_41 ( V_12 -> V_9 ,
V_36 -> V_47 . V_81 ,
& V_74 , & V_75 ) ;
V_46 [ 0 ] = V_75 & 0xff ;
V_46 [ 1 ] = ( V_75 >> 8 ) & 0xff ;
V_46 [ 2 ] = V_74 & 0xff ;
V_46 [ 3 ] = ( V_74 >> 8 ) & 0xff ;
V_46 [ 4 ] = ( V_74 >> 16 ) & 0xff ;
V_46 [ 5 ] = ( V_74 >> 24 ) & 0xff ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_82 :
V_73 = F_42 ( & V_36 -> V_15 . V_83 . V_84 ) ;
V_46 [ 0 ] = V_73 ;
V_46 [ 1 ] = V_73 >> 8 ;
V_46 [ 2 ] = V_73 >> 16 ;
V_46 [ 3 ] = V_73 >> 24 ;
V_46 [ 4 ] = V_73 >> 32 ;
V_46 [ 5 ] = V_73 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_85 :
V_73 = F_42 ( & V_36 -> V_15 . V_86 . V_84 ) ;
V_46 [ 0 ] = V_73 ;
V_46 [ 1 ] = V_73 >> 8 ;
V_46 [ 2 ] = V_73 >> 16 ;
V_46 [ 3 ] = V_73 >> 24 ;
V_46 [ 4 ] = V_73 >> 32 ;
V_46 [ 5 ] = V_73 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
}
V_7 . V_36 = V_36 -> V_47 . V_36 ;
V_7 . V_44 = V_36 -> V_47 . V_87 ;
F_38 ( V_72 , & V_7 ) ;
V_13 = 0 ;
V_76:
F_43 () ;
return V_13 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_30 , bool V_88 ,
bool V_89 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_45 ( V_12 , V_30 , V_88 , V_89 ) ;
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
static void F_48 ( struct V_90 * V_91 , struct V_34 * V_23 , int V_92 )
{
if ( ! ( V_91 -> V_5 & V_93 ) ) {
struct V_94 * V_95 ;
V_95 = V_23 -> V_9 -> V_96 . V_2 -> V_97 [
V_23 -> V_9 -> V_98 -> V_99 ] ;
V_91 -> V_100 = V_95 -> V_101 [ V_92 ] . V_102 ;
} else
V_91 -> V_103 = V_92 ;
}
void F_49 ( struct V_34 * V_23 ,
const struct V_104 * V_91 ,
struct V_90 * V_105 )
{
V_105 -> V_5 = 0 ;
if ( V_91 -> V_5 & V_106 )
V_105 -> V_5 |= V_93 ;
if ( V_91 -> V_5 & V_107 )
V_105 -> V_5 |= V_108 ;
if ( V_91 -> V_5 & V_109 )
V_105 -> V_5 |= V_110 ;
F_48 ( V_105 , V_23 , V_91 -> V_92 ) ;
}
static void F_50 ( struct V_34 * V_23 , struct V_111 * V_112 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_113 V_114 ;
V_112 -> V_115 = V_12 -> V_9 -> V_116 ;
V_112 -> V_117 = V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 ;
F_51 ( & V_114 ) ;
V_112 -> V_132 = V_114 . V_133 - V_23 -> V_134 ;
V_112 -> V_135 = F_52 ( V_136 - V_23 -> V_137 ) ;
V_112 -> V_138 = V_23 -> V_138 ;
V_112 -> V_139 = V_23 -> V_139 ;
V_112 -> V_140 = V_23 -> V_140 ;
V_112 -> V_141 = V_23 -> V_141 ;
V_112 -> V_142 = V_23 -> V_143 ;
V_112 -> V_144 = V_23 -> V_145 ;
V_112 -> V_146 = V_23 -> V_147 ;
V_112 -> V_148 = V_23 -> V_148 ;
if ( ( V_23 -> V_9 -> V_96 . V_5 & V_149 ) ||
( V_23 -> V_9 -> V_96 . V_5 & V_150 ) ) {
V_112 -> V_117 |= V_151 | V_152 ;
if ( ! V_9 -> V_153 -> V_154 ||
F_53 ( V_9 , V_12 , & V_23 -> V_23 , & V_112 -> signal ) )
V_112 -> signal = ( V_155 ) V_23 -> V_156 ;
V_112 -> V_157 = ( V_155 ) - F_54 ( & V_23 -> V_158 ) ;
}
F_49 ( V_23 , & V_23 -> V_159 , & V_112 -> V_160 ) ;
V_112 -> V_161 . V_5 = 0 ;
if ( V_23 -> V_162 & V_163 )
V_112 -> V_161 . V_5 |= V_93 ;
if ( V_23 -> V_162 & V_164 )
V_112 -> V_161 . V_5 |= V_108 ;
if ( V_23 -> V_162 & V_165 )
V_112 -> V_161 . V_5 |= V_110 ;
F_48 ( & V_112 -> V_161 , V_23 , V_23 -> V_166 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
V_112 -> V_117 |= V_167 |
V_168 |
V_169 ;
V_112 -> V_170 = F_55 ( V_23 -> V_170 ) ;
V_112 -> V_171 = F_55 ( V_23 -> V_171 ) ;
V_112 -> V_172 = V_23 -> V_172 ;
if ( F_29 ( V_23 , V_173 ) ) {
V_112 -> V_117 |= V_174 ;
V_112 -> V_175 = V_23 -> V_175 ;
}
#endif
}
V_112 -> V_176 . V_5 = 0 ;
if ( V_12 -> V_26 . V_177 . V_178 )
V_112 -> V_176 . V_5 |= V_179 ;
if ( V_12 -> V_26 . V_177 . V_180 )
V_112 -> V_176 . V_5 |= V_181 ;
if ( V_12 -> V_26 . V_177 . V_182 )
V_112 -> V_176 . V_5 |= V_183 ;
V_112 -> V_176 . V_184 = V_12 -> V_9 -> V_96 . V_47 . V_185 ;
V_112 -> V_176 . V_186 = V_12 -> V_26 . V_177 . V_187 ;
V_112 -> V_188 . V_189 = 0 ;
V_112 -> V_188 . V_190 = F_56 ( V_191 ) |
F_56 ( V_192 ) |
F_56 ( V_193 ) |
F_56 ( V_194 ) |
F_56 ( V_195 ) |
F_56 ( V_196 ) ;
if ( F_29 ( V_23 , V_197 ) )
V_112 -> V_188 . V_189 |= F_56 ( V_191 ) ;
if ( F_29 ( V_23 , V_198 ) )
V_112 -> V_188 . V_189 |= F_56 ( V_192 ) ;
if ( F_29 ( V_23 , V_199 ) )
V_112 -> V_188 . V_189 |= F_56 ( V_193 ) ;
if ( F_29 ( V_23 , V_56 ) )
V_112 -> V_188 . V_189 |= F_56 ( V_194 ) ;
if ( F_29 ( V_23 , V_200 ) )
V_112 -> V_188 . V_189 |= F_56 ( V_195 ) ;
if ( F_29 ( V_23 , V_201 ) )
V_112 -> V_188 . V_189 |= F_56 ( V_196 ) ;
}
static int F_57 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_202 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_203 = 0 ;
if ( V_202 == V_204 )
V_203 += V_205 ;
V_203 += F_58 ( V_12 , V_202 ) ;
if ( V_203 == 0 )
return - V_206 ;
return V_203 ;
}
static void F_59 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_207 * V_208 ,
T_4 * V_209 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_34 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_111 V_112 ;
struct V_210 V_211 ;
int V_212 , V_213 ;
#define F_60 7
memset ( V_209 , 0 , sizeof( T_4 ) * V_205 ) ;
#define F_61 ( V_23 ) \
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
V_23 = F_27 ( V_12 , V_12 -> V_15 . V_25 . V_214 ) ;
if ( ! ( V_23 && ! F_62 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_215;
V_212 = 0 ;
F_61 ( V_23 ) ;
V_209 [ V_212 ++ ] = V_23 -> V_216 ;
V_112 . V_117 = 0 ;
F_50 ( V_23 , & V_112 ) ;
if ( V_112 . V_117 & V_125 )
V_209 [ V_212 ] = 100000 *
F_63 ( & V_112 . V_160 ) ;
V_212 ++ ;
if ( V_112 . V_117 & V_126 )
V_209 [ V_212 ] = 100000 *
F_63 ( & V_112 . V_161 ) ;
V_212 ++ ;
if ( V_112 . V_117 & V_152 )
V_209 [ V_212 ] = ( T_3 ) V_112 . V_157 ;
V_212 ++ ;
} else {
F_64 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_212 = 0 ;
F_61 ( V_23 ) ;
}
}
V_215:
V_212 = V_205 - F_60 ;
V_213 = 0 ;
while ( true ) {
V_211 . V_117 = 0 ;
if ( F_65 ( V_9 , V_213 , & V_211 ) != 0 ) {
V_211 . V_117 = 0 ;
break;
}
if ( V_211 . V_217 &&
( V_9 -> V_98 -> V_218 ==
V_211 . V_217 -> V_218 ) )
break;
V_213 ++ ;
}
if ( V_211 . V_117 )
V_209 [ V_212 ++ ] = V_211 . V_217 -> V_218 ;
else
V_209 [ V_212 ++ ] = 0 ;
if ( V_211 . V_117 & V_219 )
V_209 [ V_212 ++ ] = ( T_3 ) V_211 . V_220 ;
else
V_209 [ V_212 ++ ] = - 1LL ;
if ( V_211 . V_117 & V_221 )
V_209 [ V_212 ++ ] = V_211 . V_222 ;
else
V_209 [ V_212 ++ ] = - 1LL ;
if ( V_211 . V_117 & V_223 )
V_209 [ V_212 ++ ] = V_211 . V_224 ;
else
V_209 [ V_212 ++ ] = - 1LL ;
if ( V_211 . V_117 & V_225 )
V_209 [ V_212 ++ ] = V_211 . V_226 ;
else
V_209 [ V_212 ++ ] = - 1LL ;
if ( V_211 . V_117 & V_227 )
V_209 [ V_212 ++ ] = V_211 . V_228 ;
else
V_209 [ V_212 ++ ] = - 1LL ;
if ( V_211 . V_117 & V_229 )
V_209 [ V_212 ++ ] = V_211 . V_230 ;
else
V_209 [ V_212 ++ ] = - 1LL ;
F_33 ( & V_9 -> V_49 ) ;
if ( F_62 ( V_212 != V_205 ) )
return;
F_66 ( V_12 , V_208 , & ( V_209 [ V_205 ] ) ) ;
}
static void F_67 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_202 , T_3 * V_209 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_231 = 0 ;
if ( V_202 == V_204 ) {
V_231 = sizeof( V_232 ) ;
memcpy ( V_209 , * V_232 , V_231 ) ;
}
F_68 ( V_12 , V_202 , & ( V_209 [ V_231 ] ) ) ;
}
static int F_69 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_92 , T_3 * V_233 , struct V_111 * V_112 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_50 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_70 ( V_12 , V_92 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_233 , V_23 -> V_23 . V_234 , V_235 ) ;
F_50 ( V_23 , V_112 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_71 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_92 , struct V_210 * V_211 )
{
struct V_8 * V_9 = F_72 ( V_18 -> V_236 ) ;
return F_65 ( V_9 , V_92 , V_211 ) ;
}
static int F_73 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_233 , struct V_111 * V_112 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_50 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_233 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_50 ( V_23 , V_112 ) ;
}
F_33 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_74 ( struct V_2 * V_2 ,
struct V_17 * V_237 ,
struct V_238 * V_239 ,
enum V_240 V_241 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
if ( V_237 )
V_12 = F_9 ( V_237 ) ;
switch ( F_75 ( V_9 , NULL ) ) {
case V_242 :
return - V_28 ;
case V_243 :
if ( V_9 -> V_98 != V_239 ||
( ! V_12 && V_9 -> V_244 != V_241 ) )
return - V_28 ;
if ( ! V_12 && V_9 -> V_244 == V_241 )
return 0 ;
break;
case V_245 :
break;
}
if ( ! F_76 ( V_9 , V_12 , V_241 ) )
return - V_28 ;
V_9 -> V_98 = V_239 ;
F_77 ( V_9 , 0 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_2 ,
struct V_238 * V_239 ,
enum V_240 V_241 )
{
return F_74 ( V_2 , NULL , V_239 , V_241 ) ;
}
static int F_79 ( struct V_11 * V_12 ,
const T_3 * V_246 , T_5 V_247 )
{
struct V_248 * V_249 , * V_250 ;
if ( ! V_246 || ! V_247 )
return 1 ;
V_250 = F_80 ( V_12 -> V_15 . V_251 . V_248 ) ;
V_249 = F_81 ( sizeof( struct V_248 ) + V_247 , V_252 ) ;
if ( ! V_249 )
return - V_253 ;
V_249 -> V_254 = V_247 ;
memcpy ( V_249 -> V_209 , V_246 , V_247 ) ;
F_82 ( V_12 -> V_15 . V_251 . V_248 , V_249 ) ;
if ( V_250 )
F_83 ( V_250 , V_255 ) ;
return 0 ;
}
static int F_84 ( struct V_11 * V_12 ,
struct V_256 * V_7 )
{
struct V_257 * V_249 , * V_250 ;
int V_258 , V_259 ;
int V_260 , V_13 ;
T_1 V_261 = V_262 ;
V_250 = F_80 ( V_12 -> V_15 . V_251 . V_263 ) ;
if ( ! V_7 -> V_264 && ! V_250 )
return - V_43 ;
if ( V_7 -> V_264 )
V_258 = V_7 -> V_265 ;
else
V_258 = V_250 -> V_265 ;
if ( V_7 -> V_266 || ! V_250 )
V_259 = V_7 -> V_267 ;
else
V_259 = V_250 -> V_267 ;
V_260 = sizeof( * V_249 ) + V_258 + V_259 ;
V_249 = F_81 ( V_260 , V_252 ) ;
if ( ! V_249 )
return - V_253 ;
V_249 -> V_264 = ( ( T_3 * ) V_249 ) + sizeof( * V_249 ) ;
V_249 -> V_266 = V_249 -> V_264 + V_258 ;
V_249 -> V_265 = V_258 ;
V_249 -> V_267 = V_259 ;
if ( V_7 -> V_264 )
memcpy ( V_249 -> V_264 , V_7 -> V_264 , V_258 ) ;
else
memcpy ( V_249 -> V_264 , V_250 -> V_264 , V_258 ) ;
if ( V_7 -> V_266 )
memcpy ( V_249 -> V_266 , V_7 -> V_266 , V_259 ) ;
else
if ( V_250 )
memcpy ( V_249 -> V_266 , V_250 -> V_266 , V_259 ) ;
V_13 = F_79 ( V_12 , V_7 -> V_248 ,
V_7 -> V_268 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_261 |= V_269 ;
F_82 ( V_12 -> V_15 . V_251 . V_263 , V_249 ) ;
if ( V_250 )
F_83 ( V_250 , V_255 ) ;
return V_261 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_270 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_257 * V_250 ;
struct V_11 * V_22 ;
T_1 V_261 = V_271 |
V_272 |
V_262 |
V_273 ;
int V_13 ;
V_250 = F_80 ( V_12 -> V_15 . V_251 . V_263 ) ;
if ( V_250 )
return - V_274 ;
V_13 = F_74 ( V_2 , V_18 , V_7 -> V_217 ,
V_7 -> V_241 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_275 = V_7 -> V_276 . V_277 ;
V_12 -> V_278 = V_7 -> V_276 . V_278 ;
F_64 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_275 =
V_7 -> V_276 . V_277 ;
V_22 -> V_278 =
V_7 -> V_276 . V_278 ;
}
V_12 -> V_26 . V_177 . V_187 = V_7 -> V_186 ;
V_12 -> V_26 . V_177 . V_184 = V_7 -> V_184 ;
V_12 -> V_26 . V_177 . V_279 = V_7 -> V_279 ;
if ( V_7 -> V_279 )
memcpy ( V_12 -> V_26 . V_177 . V_280 , V_7 -> V_280 ,
V_7 -> V_279 ) ;
V_12 -> V_26 . V_177 . V_281 =
( V_7 -> V_281 != V_282 ) ;
V_13 = F_84 ( V_12 , & V_7 -> V_263 ) ;
if ( V_13 < 0 )
return V_13 ;
V_261 |= V_13 ;
F_86 ( V_12 , V_261 ) ;
F_87 ( V_18 ) ;
F_64 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_87 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_256 * V_7 )
{
struct V_11 * V_12 ;
struct V_257 * V_250 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
V_250 = F_80 ( V_12 -> V_15 . V_251 . V_263 ) ;
if ( ! V_250 )
return - V_50 ;
V_13 = F_84 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_86 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 , * V_22 ;
struct V_257 * V_250 ;
V_12 = F_9 ( V_18 ) ;
V_250 = F_80 ( V_12 -> V_15 . V_251 . V_263 ) ;
if ( ! V_250 )
return - V_50 ;
F_64 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_90 ( V_22 -> V_18 ) ;
F_90 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_251 . V_263 , NULL ) ;
F_83 ( V_250 , V_255 ) ;
F_91 ( V_12 -> V_9 , V_12 ) ;
F_86 ( V_12 , V_272 ) ;
return 0 ;
}
static void F_92 ( struct V_34 * V_23 )
{
struct V_283 * V_284 ;
struct V_285 * V_286 ;
V_286 = F_93 ( sizeof( * V_284 ) ) ;
if ( ! V_286 )
return;
V_284 = (struct V_283 * ) F_94 ( V_286 , sizeof( * V_284 ) ) ;
F_95 ( V_284 -> V_287 ) ;
memcpy ( V_284 -> V_288 , V_23 -> V_23 . V_234 , V_235 ) ;
V_284 -> V_254 = F_96 ( 6 ) ;
V_284 -> V_289 = 0 ;
V_284 -> V_290 = 0x01 ;
V_284 -> V_291 = 0xaf ;
V_284 -> V_292 [ 0 ] = 0x81 ;
V_284 -> V_292 [ 1 ] = 1 ;
V_284 -> V_292 [ 2 ] = 0 ;
V_286 -> V_18 = V_23 -> V_12 -> V_18 ;
V_286 -> V_293 = F_97 ( V_286 , V_23 -> V_12 -> V_18 ) ;
memset ( V_286 -> V_294 , 0 , sizeof( V_286 -> V_294 ) ) ;
F_98 ( V_286 ) ;
}
static int F_99 ( struct V_8 * V_9 ,
struct V_34 * V_23 ,
struct V_295 * V_7 )
{
int V_19 = 0 ;
T_1 V_296 ;
int V_212 , V_297 ;
struct V_94 * V_95 ;
struct V_11 * V_12 = V_23 -> V_12 ;
T_1 V_190 , V_189 ;
V_95 = V_9 -> V_96 . V_2 -> V_97 [ V_9 -> V_98 -> V_99 ] ;
V_190 = V_7 -> V_298 ;
V_189 = V_7 -> V_299 ;
if ( V_190 & F_56 ( V_195 ) ) {
if ( F_62 ( ! F_25 ( & V_12 -> V_26 ) ) )
return - V_43 ;
if ( V_189 & F_56 ( V_195 ) &&
! F_29 ( V_23 , V_200 ) ) {
V_19 = F_100 ( V_23 , V_300 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_100 ( V_23 , V_301 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_190 & F_56 ( V_191 ) ) {
if ( V_189 & F_56 ( V_191 ) )
V_19 = F_100 ( V_23 , V_302 ) ;
else if ( F_29 ( V_23 , V_197 ) )
V_19 = F_100 ( V_23 , V_301 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_190 & F_56 ( V_195 ) ) {
if ( F_62 ( ! F_25 ( & V_12 -> V_26 ) ) )
return - V_43 ;
if ( ! ( V_189 & F_56 ( V_195 ) ) &&
F_29 ( V_23 , V_200 ) ) {
V_19 = F_100 ( V_23 , V_300 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_100 ( V_23 , V_303 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_190 & F_56 ( V_192 ) ) {
if ( V_189 & F_56 ( V_192 ) )
F_101 ( V_23 , V_198 ) ;
else
F_102 ( V_23 , V_198 ) ;
}
if ( V_190 & F_56 ( V_193 ) ) {
if ( V_189 & F_56 ( V_193 ) ) {
F_101 ( V_23 , V_199 ) ;
V_23 -> V_23 . V_304 = true ;
} else {
F_102 ( V_23 , V_199 ) ;
V_23 -> V_23 . V_304 = false ;
}
}
if ( V_190 & F_56 ( V_194 ) ) {
if ( V_189 & F_56 ( V_194 ) )
F_101 ( V_23 , V_56 ) ;
else
F_102 ( V_23 , V_56 ) ;
}
if ( V_190 & F_56 ( V_196 ) ) {
if ( V_189 & F_56 ( V_196 ) )
F_101 ( V_23 , V_201 ) ;
else
F_102 ( V_23 , V_201 ) ;
}
if ( V_7 -> V_305 & V_306 ) {
V_23 -> V_23 . V_307 = V_7 -> V_307 ;
V_23 -> V_23 . V_308 = V_7 -> V_308 ;
}
if ( V_7 -> V_309 )
V_23 -> V_23 . V_309 = V_7 -> V_309 ;
if ( V_7 -> V_310 >= 0 )
V_23 -> V_310 = V_7 -> V_310 ;
if ( V_7 -> V_311 ) {
V_296 = 0 ;
for ( V_212 = 0 ; V_212 < V_7 -> V_312 ; V_212 ++ ) {
int V_91 = ( V_7 -> V_311 [ V_212 ] & 0x7f ) * 5 ;
for ( V_297 = 0 ; V_297 < V_95 -> V_313 ; V_297 ++ ) {
if ( V_95 -> V_101 [ V_297 ] . V_102 == V_91 )
V_296 |= F_56 ( V_297 ) ;
}
}
V_23 -> V_23 . V_314 [ V_9 -> V_98 -> V_99 ] = V_296 ;
}
if ( V_7 -> V_315 )
F_103 ( V_12 , V_95 ,
V_7 -> V_315 ,
& V_23 -> V_23 . V_316 ) ;
if ( F_25 ( & V_12 -> V_26 ) ) {
#ifdef F_30
if ( V_12 -> V_15 . V_59 . V_60 & V_317 )
switch ( V_7 -> V_172 ) {
case V_318 :
case V_319 :
case V_320 :
V_23 -> V_172 = V_7 -> V_172 ;
break;
default:
break;
}
else
switch ( V_7 -> V_321 ) {
case V_322 :
F_104 ( V_23 ) ;
break;
case V_323 :
F_105 ( V_23 ) ;
break;
}
#endif
}
return 0 ;
}
static int F_106 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_233 , struct V_295 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_324 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_55 )
return - V_43 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_107 ( V_233 , V_12 -> V_26 . V_234 ) )
return - V_43 ;
if ( F_108 ( V_233 ) )
return - V_43 ;
V_23 = F_109 ( V_12 , V_233 , V_252 ) ;
if ( ! V_23 )
return - V_253 ;
F_110 ( V_23 , V_300 ) ;
F_110 ( V_23 , V_301 ) ;
V_13 = F_99 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_111 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_29 ( V_23 , V_201 ) )
F_112 ( V_23 ) ;
V_324 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_55 ;
V_13 = F_113 ( V_23 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
if ( V_324 )
F_92 ( V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_114 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_233 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_233 )
return F_115 ( V_12 , V_233 ) ;
F_91 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_233 ,
struct V_295 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_325 ;
int V_13 ;
F_24 ( & V_9 -> V_49 ) ;
V_23 = F_27 ( V_12 , V_233 ) ;
if ( ! V_23 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_50 ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_311 &&
! F_29 ( V_23 , V_201 ) ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_326 = false ;
bool V_327 = false ;
V_325 = F_9 ( V_7 -> V_22 ) ;
if ( V_325 -> V_26 . type != V_20 &&
V_325 -> V_26 . type != V_55 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 -> V_236 -> V_21 ) {
if ( V_325 -> V_15 . V_22 . V_23 ) {
F_33 ( & V_9 -> V_49 ) ;
return - V_28 ;
}
F_82 ( V_325 -> V_15 . V_22 . V_23 , V_23 ) ;
V_327 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_82 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_326 = true ;
}
V_23 -> V_12 = V_325 ;
if ( V_23 -> V_216 == V_302 &&
V_326 != V_327 ) {
if ( V_327 )
F_117 ( & V_23 -> V_12 -> V_328 -> V_329 ) ;
else
F_118 ( & V_23 -> V_12 -> V_328 -> V_329 ) ;
}
F_92 ( V_23 ) ;
}
V_13 = F_99 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_33 ( & V_9 -> V_49 ) ;
return V_13 ;
}
if ( F_29 ( V_23 , V_201 ) && V_7 -> V_311 )
F_112 ( V_23 ) ;
F_33 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_298 & F_56 ( V_191 ) ) {
F_119 ( V_9 , - 1 ) ;
F_120 ( V_12 ) ;
}
return 0 ;
}
static int F_121 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_330 , T_3 * V_331 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
struct V_34 * V_23 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_331 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_50 ;
}
V_13 = F_122 ( V_330 , V_12 ) ;
if ( V_13 ) {
F_43 () ;
return V_13 ;
}
V_333 = F_123 ( V_330 , V_12 ) ;
if ( ! V_333 ) {
F_43 () ;
return - V_334 ;
}
F_124 ( V_333 , V_23 ) ;
F_43 () ;
return 0 ;
}
static int F_125 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_330 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_330 )
return F_126 ( V_330 , V_12 ) ;
F_127 ( V_12 ) ;
return 0 ;
}
static int F_128 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_330 , T_3 * V_331 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
struct V_34 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_23 = F_26 ( V_12 , V_331 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_50 ;
}
V_333 = F_123 ( V_330 , V_12 ) ;
if ( ! V_333 ) {
F_43 () ;
return - V_50 ;
}
F_124 ( V_333 , V_23 ) ;
F_43 () ;
return 0 ;
}
static void F_129 ( struct V_332 * V_333 , T_3 * V_331 ,
struct V_335 * V_336 )
{
struct V_34 * V_337 = F_40 ( V_333 -> V_331 ) ;
if ( V_337 )
memcpy ( V_331 , V_337 -> V_23 . V_234 , V_235 ) ;
else
memset ( V_331 , 0 , V_235 ) ;
memset ( V_336 , 0 , sizeof( * V_336 ) ) ;
V_336 -> V_115 = V_338 ;
V_336 -> V_117 = V_339 |
V_340 |
V_341 |
V_342 |
V_343 |
V_344 |
V_345 ;
V_336 -> V_346 = V_333 -> V_347 . V_348 ;
V_336 -> V_349 = V_333 -> V_349 ;
V_336 -> V_350 = V_333 -> V_350 ;
if ( F_130 ( V_136 , V_333 -> V_351 ) )
V_336 -> V_352 = F_52 ( V_333 -> V_351 - V_136 ) ;
V_336 -> V_353 =
F_52 ( V_333 -> V_353 ) ;
V_336 -> V_354 = V_333 -> V_354 ;
if ( V_333 -> V_5 & V_355 )
V_336 -> V_5 |= V_356 ;
if ( V_333 -> V_5 & V_357 )
V_336 -> V_5 |= V_358 ;
if ( V_333 -> V_5 & V_359 )
V_336 -> V_5 |= V_360 ;
if ( V_333 -> V_5 & V_361 )
V_336 -> V_5 |= V_362 ;
if ( V_333 -> V_5 & V_363 )
V_336 -> V_5 |= V_364 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_330 , T_3 * V_331 , struct V_335 * V_336 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_333 = F_123 ( V_330 , V_12 ) ;
if ( ! V_333 ) {
F_43 () ;
return - V_50 ;
}
memcpy ( V_330 , V_333 -> V_330 , V_235 ) ;
F_129 ( V_333 , V_331 , V_336 ) ;
F_43 () ;
return 0 ;
}
static int F_132 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_92 , T_3 * V_330 , T_3 * V_331 ,
struct V_335 * V_336 )
{
struct V_11 * V_12 ;
struct V_332 * V_333 ;
V_12 = F_9 ( V_18 ) ;
F_39 () ;
V_333 = F_133 ( V_92 , V_12 ) ;
if ( ! V_333 ) {
F_43 () ;
return - V_50 ;
}
memcpy ( V_330 , V_333 -> V_330 , V_235 ) ;
F_129 ( V_333 , V_331 , V_336 ) ;
F_43 () ;
return 0 ;
}
static int F_134 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_365 * V_47 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_47 , & ( V_12 -> V_15 . V_59 . V_366 ) , sizeof( struct V_365 ) ) ;
return 0 ;
}
static inline bool F_135 ( enum V_367 V_368 , T_1 V_190 )
{
return ( V_190 >> ( V_368 - 1 ) ) & 0x1 ;
}
static int F_136 ( struct V_369 * V_370 ,
const struct V_371 * V_372 )
{
T_3 * V_373 ;
const T_3 * V_374 ;
struct V_11 * V_12 = F_137 ( V_370 ,
struct V_11 , V_15 . V_59 ) ;
V_373 = NULL ;
V_374 = V_370 -> V_375 ;
if ( V_372 -> V_376 ) {
V_373 = F_138 ( V_372 -> V_375 , V_372 -> V_376 ,
V_252 ) ;
if ( ! V_373 )
return - V_253 ;
}
V_370 -> V_376 = V_372 -> V_376 ;
V_370 -> V_375 = V_373 ;
F_139 ( V_374 ) ;
V_370 -> V_377 = V_372 -> V_377 ;
memcpy ( V_370 -> V_378 , V_372 -> V_378 , V_370 -> V_377 ) ;
V_370 -> V_379 = V_372 -> V_380 ;
V_370 -> V_381 = V_372 -> V_382 ;
V_370 -> V_383 = V_372 -> V_384 ;
V_370 -> V_60 = V_61 ;
if ( V_372 -> V_385 )
V_370 -> V_60 |= V_386 ;
if ( V_372 -> V_387 )
V_370 -> V_60 |= V_317 ;
memcpy ( V_12 -> V_26 . V_177 . V_388 , V_372 -> V_388 ,
sizeof( V_372 -> V_388 ) ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_190 ,
const struct V_365 * V_389 )
{
struct V_365 * V_47 ;
struct V_11 * V_12 ;
struct V_369 * V_370 ;
V_12 = F_9 ( V_18 ) ;
V_370 = & V_12 -> V_15 . V_59 ;
V_47 = & ( V_12 -> V_15 . V_59 . V_366 ) ;
if ( F_135 ( V_390 , V_190 ) )
V_47 -> V_391 = V_389 -> V_391 ;
if ( F_135 ( V_392 , V_190 ) )
V_47 -> V_393 = V_389 -> V_393 ;
if ( F_135 ( V_394 , V_190 ) )
V_47 -> V_395 = V_389 -> V_395 ;
if ( F_135 ( V_396 , V_190 ) )
V_47 -> V_397 = V_389 -> V_397 ;
if ( F_135 ( V_398 , V_190 ) )
V_47 -> V_399 = V_389 -> V_399 ;
if ( F_135 ( V_400 , V_190 ) )
V_47 -> V_401 = V_389 -> V_401 ;
if ( F_135 ( V_402 , V_190 ) )
V_47 -> V_403 = V_389 -> V_403 ;
if ( F_135 ( V_404 , V_190 ) )
V_47 -> V_405 = V_389 -> V_405 ;
if ( F_135 ( V_406 , V_190 ) )
V_47 -> V_407 =
V_389 -> V_407 ;
if ( F_135 ( V_408 , V_190 ) )
V_47 -> V_409 =
V_389 -> V_409 ;
if ( F_135 ( V_410 , V_190 ) )
V_47 -> V_411 = V_389 -> V_411 ;
if ( F_135 ( V_412 , V_190 ) )
V_47 -> V_413 = V_389 -> V_413 ;
if ( F_135 ( V_414 , V_190 ) )
V_47 -> V_415 =
V_389 -> V_415 ;
if ( F_135 ( V_416 , V_190 ) )
V_47 -> V_417 =
V_389 -> V_417 ;
if ( F_135 ( V_418 , V_190 ) )
V_47 -> V_419 =
V_389 -> V_419 ;
if ( F_135 ( V_420 ,
V_190 ) )
V_47 -> V_421 =
V_389 -> V_421 ;
if ( F_135 ( V_422 , V_190 ) ) {
V_47 -> V_423 = V_389 -> V_423 ;
F_141 ( V_370 ) ;
}
if ( F_135 ( V_424 , V_190 ) ) {
if ( V_389 -> V_425 &&
! ( V_47 -> V_423 > V_426 ) ) {
V_47 -> V_423 = V_427 ;
F_141 ( V_370 ) ;
}
V_47 -> V_425 =
V_389 -> V_425 ;
}
if ( F_135 ( V_428 , V_190 ) )
V_47 -> V_429 =
V_389 -> V_429 ;
if ( F_135 ( V_430 , V_190 ) )
V_47 -> V_431 = V_389 -> V_431 ;
if ( F_135 ( V_432 , V_190 ) ) {
if ( ! ( V_12 -> V_9 -> V_96 . V_5 & V_149 ) )
return - V_433 ;
V_47 -> V_434 = V_389 -> V_434 ;
}
if ( F_135 ( V_435 , V_190 ) ) {
V_47 -> V_436 = V_389 -> V_436 ;
V_12 -> V_26 . V_177 . V_437 = V_389 -> V_436 ;
F_86 ( V_12 , V_438 ) ;
}
if ( F_135 ( V_439 , V_190 ) )
V_47 -> V_440 =
V_389 -> V_440 ;
if ( F_135 ( V_441 , V_190 ) )
V_47 -> V_442 =
V_389 -> V_442 ;
if ( F_135 ( V_443 , V_190 ) )
V_47 -> V_444 =
V_389 -> V_444 ;
return 0 ;
}
static int F_142 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_365 * V_47 ,
const struct V_371 * V_372 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_369 * V_370 = & V_12 -> V_15 . V_59 ;
int V_13 ;
memcpy ( & V_370 -> V_366 , V_47 , sizeof( struct V_365 ) ) ;
V_13 = F_136 ( V_370 , V_372 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_74 ( V_2 , V_18 , V_372 -> V_217 ,
V_372 -> V_241 ) ;
if ( V_13 )
return V_13 ;
F_143 ( V_12 ) ;
return 0 ;
}
static int F_144 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_145 ( V_12 ) ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_445 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_261 = 0 ;
V_12 = F_9 ( V_18 ) ;
if ( V_7 -> V_178 >= 0 ) {
V_12 -> V_26 . V_177 . V_178 = V_7 -> V_178 ;
V_261 |= V_446 ;
}
if ( V_7 -> V_180 >= 0 ) {
V_12 -> V_26 . V_177 . V_180 =
V_7 -> V_180 ;
V_261 |= V_447 ;
}
if ( ! V_12 -> V_26 . V_177 . V_182 &&
V_12 -> V_9 -> V_98 -> V_99 == V_448 ) {
V_12 -> V_26 . V_177 . V_182 = true ;
V_261 |= V_449 ;
}
if ( V_7 -> V_450 >= 0 ) {
V_12 -> V_26 . V_177 . V_182 =
V_7 -> V_450 ;
V_261 |= V_449 ;
}
if ( V_7 -> V_451 ) {
int V_212 , V_297 ;
T_1 V_296 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_94 * V_95 =
V_2 -> V_97 [ V_9 -> V_98 -> V_99 ] ;
for ( V_212 = 0 ; V_212 < V_7 -> V_452 ; V_212 ++ ) {
int V_91 = ( V_7 -> V_451 [ V_212 ] & 0x7f ) * 5 ;
for ( V_297 = 0 ; V_297 < V_95 -> V_313 ; V_297 ++ ) {
if ( V_95 -> V_101 [ V_297 ] . V_102 == V_91 )
V_296 |= F_56 ( V_297 ) ;
}
}
V_12 -> V_26 . V_177 . V_451 = V_296 ;
V_261 |= V_453 ;
}
if ( V_7 -> V_454 >= 0 ) {
if ( V_7 -> V_454 )
V_12 -> V_5 |= V_455 ;
else
V_12 -> V_5 &= ~ V_455 ;
}
if ( V_7 -> V_436 >= 0 ) {
V_12 -> V_26 . V_177 . V_437 =
( T_2 ) V_7 -> V_436 ;
V_261 |= V_438 ;
}
F_86 ( V_12 , V_261 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_456 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_457 V_458 ;
if ( ! V_9 -> V_153 -> V_459 )
return - V_206 ;
if ( V_9 -> V_96 . V_460 < V_461 )
return - V_206 ;
memset ( & V_458 , 0 , sizeof( V_458 ) ) ;
V_458 . V_462 = V_7 -> V_462 ;
V_458 . V_463 = V_7 -> V_464 ;
V_458 . V_465 = V_7 -> V_466 ;
V_458 . V_467 = V_7 -> V_467 ;
V_458 . V_468 = false ;
V_12 -> V_469 [ V_7 -> V_470 ] = V_458 ;
if ( F_148 ( V_9 , V_12 , V_7 -> V_470 , & V_458 ) ) {
F_149 ( V_9 -> V_96 . V_2 ,
L_1 ,
V_7 -> V_470 ) ;
return - V_43 ;
}
F_86 ( V_12 , V_471 ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_2 ,
struct V_472 * V_473 )
{
return F_151 ( F_2 ( V_2 ) , V_473 ) ;
}
static int F_152 ( struct V_2 * V_2 )
{
return F_153 ( F_2 ( V_2 ) ) ;
}
static int F_154 ( struct V_2 * V_2 ,
struct V_474 * V_475 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_475 -> V_10 ) ;
switch ( F_155 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_57 :
case V_58 :
case V_66 :
case V_63 :
break;
case V_67 :
if ( V_12 -> V_9 -> V_153 -> V_476 )
break;
case V_55 :
if ( V_12 -> V_15 . V_251 . V_263 )
return - V_206 ;
break;
default:
return - V_206 ;
}
return F_156 ( V_12 , V_475 ) ;
}
static int
F_157 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_477 * V_475 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_153 -> V_478 )
return - V_206 ;
return F_158 ( V_12 , V_475 ) ;
}
static int
F_159 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_153 -> V_479 )
return - V_206 ;
return F_160 ( V_12 ) ;
}
static int F_161 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_480 * V_475 )
{
return F_162 ( F_9 ( V_18 ) , V_475 ) ;
}
static int F_163 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_481 * V_475 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
switch ( F_75 ( V_9 , V_12 ) ) {
case V_242 :
return - V_28 ;
case V_243 :
if ( V_9 -> V_98 == V_475 -> V_328 -> V_217 )
break;
return - V_28 ;
case V_245 :
break;
}
return F_164 ( F_9 ( V_18 ) , V_475 ) ;
}
static int F_165 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_482 * V_475 )
{
return F_166 ( F_9 ( V_18 ) , V_475 ) ;
}
static int F_167 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_483 * V_475 )
{
return F_168 ( F_9 ( V_18 ) , V_475 ) ;
}
static int F_169 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_484 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
switch ( F_75 ( V_9 , V_12 ) ) {
case V_242 :
return - V_28 ;
case V_243 :
if ( ! V_7 -> V_485 )
return - V_28 ;
if ( V_9 -> V_98 == V_7 -> V_217 )
break;
return - V_28 ;
case V_245 :
break;
}
return F_170 ( V_12 , V_7 ) ;
}
static int F_171 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
return F_172 ( V_12 ) ;
}
static int F_173 ( struct V_2 * V_2 , T_1 V_261 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_261 & V_486 ) {
V_13 = F_174 ( V_9 , V_2 -> V_487 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_261 & V_488 ) {
V_13 = F_175 ( V_9 , V_2 -> V_489 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_261 & V_490 ) {
V_13 = F_176 ( V_9 , V_2 -> V_491 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_261 & V_492 )
V_9 -> V_96 . V_47 . V_493 = V_2 -> V_494 ;
if ( V_261 & V_495 )
V_9 -> V_96 . V_47 . V_496 = V_2 -> V_497 ;
if ( V_261 &
( V_492 | V_495 ) )
F_77 ( V_9 , V_498 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_2 ,
enum V_499 type , int V_500 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_238 * V_239 = V_9 -> V_98 ;
T_1 V_501 = 0 ;
switch ( type ) {
case V_502 :
V_9 -> V_503 = - 1 ;
break;
case V_504 :
if ( V_500 < 0 || ( V_500 % 100 ) )
return - V_206 ;
V_9 -> V_503 = F_178 ( V_500 ) ;
break;
case V_505 :
if ( V_500 < 0 || ( V_500 % 100 ) )
return - V_206 ;
if ( F_178 ( V_500 ) > V_239 -> V_506 )
return - V_43 ;
V_9 -> V_503 = F_178 ( V_500 ) ;
break;
}
F_77 ( V_9 , V_501 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 , int * V_507 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_507 = V_9 -> V_96 . V_47 . V_508 ;
return 0 ;
}
static int F_180 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_234 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_509 . V_510 , V_234 , V_235 ) ;
return 0 ;
}
static void F_181 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_182 ( V_9 ) ;
}
static int F_183 ( struct V_2 * V_2 , void * V_209 , int V_254 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_153 -> V_511 )
return - V_206 ;
return V_9 -> V_153 -> V_511 ( & V_9 -> V_96 , V_209 , V_254 ) ;
}
static int F_184 ( struct V_2 * V_2 ,
struct V_285 * V_286 ,
struct V_512 * V_294 ,
void * V_209 , int V_254 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_153 -> V_513 )
return - V_206 ;
return V_9 -> V_153 -> V_513 ( & V_9 -> V_96 , V_286 , V_294 , V_209 , V_254 ) ;
}
int F_185 ( struct V_11 * V_12 ,
enum V_514 V_515 )
{
const T_3 * V_251 ;
enum V_514 V_516 ;
int V_13 ;
F_186 ( & V_12 -> V_15 . V_25 . V_517 ) ;
V_516 = V_12 -> V_15 . V_25 . V_518 ;
V_12 -> V_15 . V_25 . V_518 = V_515 ;
if ( V_516 == V_515 &&
V_515 != V_519 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_520 ||
V_12 -> V_26 . V_177 . V_241 == V_521 ) {
F_187 ( V_12 -> V_9 ) ;
return 0 ;
}
V_251 = V_12 -> V_15 . V_25 . V_520 -> V_214 ;
if ( V_515 == V_519 ) {
if ( V_12 -> V_15 . V_25 . V_522 )
V_515 = V_523 ;
else
V_515 = V_524 ;
}
V_13 = F_188 ( V_12 , V_515 ,
V_251 , V_251 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_518 = V_516 ;
return V_13 ;
}
static int F_189 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_525 , int V_526 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_72 ( V_18 -> V_236 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_206 ;
if ( ! ( V_9 -> V_96 . V_5 & V_527 ) )
return - V_206 ;
if ( V_525 == V_12 -> V_15 . V_25 . V_522 &&
V_526 == V_9 -> V_528 )
return 0 ;
V_12 -> V_15 . V_25 . V_522 = V_525 ;
V_9 -> V_528 = V_526 ;
F_24 ( & V_12 -> V_15 . V_25 . V_517 ) ;
F_185 ( V_12 , V_12 -> V_15 . V_25 . V_518 ) ;
F_33 ( & V_12 -> V_15 . V_25 . V_517 ) ;
if ( V_9 -> V_96 . V_5 & V_529 )
F_77 ( V_9 , V_530 ) ;
F_119 ( V_9 , - 1 ) ;
F_120 ( V_12 ) ;
return 0 ;
}
static int F_190 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_531 , T_1 V_532 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_533 * V_26 = & V_12 -> V_26 ;
struct V_534 * V_177 = & V_26 -> V_177 ;
if ( V_531 == V_177 -> V_535 &&
V_532 == V_177 -> V_536 )
return 0 ;
V_177 -> V_535 = V_531 ;
V_177 -> V_536 = V_532 ;
if ( V_12 -> V_15 . V_25 . V_520 &&
V_12 -> V_26 . V_537 & V_538 )
F_86 ( V_12 , V_539 ) ;
return 0 ;
}
static int F_191 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_234 ,
const struct V_540 * V_190 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_72 ( V_18 -> V_236 ) ;
int V_212 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_37 ;
if ( V_9 -> V_96 . V_5 & V_541 ) {
V_19 = F_192 ( V_9 , V_12 , V_190 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_212 = 0 ; V_212 < V_542 ; V_212 ++ ) {
V_12 -> V_543 [ V_212 ] = V_190 -> V_291 [ V_212 ] . V_100 ;
memcpy ( V_12 -> V_544 [ V_212 ] , V_190 -> V_291 [ V_212 ] . V_103 ,
sizeof( V_190 -> V_291 [ V_212 ] . V_103 ) ) ;
}
return 0 ;
}
static int F_193 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_238 * V_217 ,
enum V_240 V_241 ,
unsigned int V_545 , T_4 * V_72 ,
struct V_285 * V_546 )
{
struct V_547 * V_548 , * V_549 ;
bool V_550 = false ;
int V_19 ;
F_186 ( & V_9 -> V_517 ) ;
V_548 = F_81 ( sizeof( * V_548 ) , V_252 ) ;
if ( ! V_548 )
return - V_253 ;
V_548 -> V_239 = V_217 ;
V_548 -> V_551 = V_241 ;
V_548 -> V_545 = V_545 ;
V_548 -> V_552 = V_545 ;
V_548 -> V_553 = V_546 ;
V_548 -> V_554 = ( unsigned long ) V_546 ;
V_548 -> V_12 = V_12 ;
F_194 ( & V_548 -> V_555 , V_556 ) ;
F_195 ( & V_548 -> V_557 ) ;
if ( ! F_196 ( & V_9 -> V_558 ) || V_9 -> V_559 )
goto V_560;
if ( ! V_9 -> V_153 -> V_561 ) {
F_197 ( & V_9 -> V_96 , & V_548 -> V_555 , 0 ) ;
goto V_562;
}
if ( ! V_545 )
V_545 = 10 ;
V_19 = F_198 ( V_9 , V_217 , V_241 , V_545 ) ;
if ( V_19 ) {
F_139 ( V_548 ) ;
return V_19 ;
}
V_548 -> V_563 = true ;
goto V_562;
V_560:
F_64 (tmp, &local->roc_list, list) {
if ( V_549 -> V_239 != V_217 || V_549 -> V_551 != V_241 )
continue;
if ( ! V_549 -> V_563 ) {
F_199 ( & V_548 -> V_564 , & V_549 -> V_557 ) ;
V_549 -> V_545 = F_200 ( V_549 -> V_545 , V_548 -> V_545 ) ;
V_550 = true ;
break;
}
if ( V_9 -> V_153 -> V_561 ) {
unsigned long V_297 = V_136 ;
if ( ! V_549 -> V_565 ) {
F_199 ( & V_548 -> V_564 , & V_549 -> V_557 ) ;
V_550 = true ;
break;
}
if ( F_130 ( V_297 + V_566 ,
V_549 -> V_567 +
F_201 ( V_549 -> V_545 ) ) ) {
int V_568 ;
F_202 ( V_548 ) ;
V_568 = V_548 -> V_545 -
F_52 ( V_549 -> V_567 +
F_201 (
V_549 -> V_545 ) -
V_297 ) ;
if ( V_568 > 0 ) {
F_203 ( & V_548 -> V_564 , & V_549 -> V_564 ) ;
} else {
F_199 ( & V_548 -> V_564 ,
& V_549 -> V_557 ) ;
}
V_550 = true ;
}
} else if ( F_204 ( & V_549 -> V_555 . V_569 ) ) {
unsigned long V_570 ;
F_199 ( & V_548 -> V_564 , & V_549 -> V_557 ) ;
V_550 = true ;
V_570 = V_136 + F_201 ( V_548 -> V_545 ) ;
if ( F_205 ( V_570 , V_549 -> V_555 . V_569 . V_571 ) )
F_206 ( & V_549 -> V_555 . V_569 , V_570 ) ;
else
F_207 ( & V_549 -> V_555 . V_569 ) ;
F_202 ( V_548 ) ;
}
break;
}
V_562:
if ( ! V_550 )
F_199 ( & V_548 -> V_564 , & V_9 -> V_558 ) ;
if ( V_546 )
* V_72 = ( unsigned long ) V_546 ;
else
* V_72 = ( unsigned long ) V_548 ;
return 0 ;
}
static int F_208 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_238 * V_239 ,
enum V_240 V_241 ,
unsigned int V_545 ,
T_4 * V_72 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_24 ( & V_9 -> V_517 ) ;
V_19 = F_193 ( V_9 , V_12 , V_239 , V_241 ,
V_545 , V_72 , NULL ) ;
F_33 ( & V_9 -> V_517 ) ;
return V_19 ;
}
static int F_209 ( struct V_8 * V_9 ,
T_4 V_72 , bool V_572 )
{
struct V_547 * V_548 , * V_549 , * V_573 = NULL ;
int V_19 ;
F_24 ( & V_9 -> V_517 ) ;
F_210 (roc, tmp, &local->roc_list, list) {
struct V_547 * V_574 , * V_575 ;
F_210 (dep, tmp2, &roc->dependents, list) {
if ( ! V_572 && ( unsigned long ) V_574 != V_72 )
continue;
else if ( V_572 && V_574 -> V_554 != V_72 )
continue;
F_211 ( & V_574 -> V_564 ) ;
F_33 ( & V_9 -> V_517 ) ;
F_212 ( V_574 ) ;
return 0 ;
}
if ( ! V_572 && ( unsigned long ) V_548 != V_72 )
continue;
else if ( V_572 && V_548 -> V_554 != V_72 )
continue;
V_573 = V_548 ;
break;
}
if ( ! V_573 ) {
F_33 ( & V_9 -> V_517 ) ;
return - V_50 ;
}
if ( V_9 -> V_153 -> V_561 ) {
if ( V_573 -> V_563 ) {
V_19 = F_213 ( V_9 ) ;
if ( F_31 ( V_19 ) ) {
F_33 ( & V_9 -> V_517 ) ;
return V_19 ;
}
}
F_211 ( & V_573 -> V_564 ) ;
if ( V_573 -> V_563 )
F_214 ( V_9 ) ;
F_33 ( & V_9 -> V_517 ) ;
F_212 ( V_573 ) ;
} else {
V_573 -> abort = true ;
F_197 ( & V_9 -> V_96 , & V_573 -> V_555 , 0 ) ;
F_33 ( & V_9 -> V_517 ) ;
F_215 ( & V_573 -> V_555 ) ;
}
return 0 ;
}
static int F_216 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_72 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_209 ( V_9 , V_72 , false ) ;
}
static int F_217 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_238 * V_239 , bool V_576 ,
enum V_240 V_241 ,
bool V_577 , unsigned int V_578 ,
const T_3 * V_579 , T_5 V_254 , bool V_580 ,
bool V_581 , T_4 * V_72 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_285 * V_286 ;
struct V_34 * V_23 ;
const struct V_582 * V_583 = ( void * ) V_579 ;
bool V_584 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_581 )
V_5 = V_585 ;
else
V_5 = V_586 |
V_587 ;
if ( V_580 )
V_5 |= V_588 ;
switch ( V_12 -> V_26 . type ) {
case V_57 :
if ( ! V_12 -> V_26 . V_177 . V_589 )
V_584 = true ;
#ifdef F_30
case V_58 :
if ( F_25 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_59 . V_377 )
V_584 = true ;
#endif
case V_55 :
case V_20 :
case V_67 :
if ( V_12 -> V_26 . type != V_57 &&
! F_25 ( & V_12 -> V_26 ) &&
! F_218 ( V_12 -> V_328 -> V_263 ) )
V_584 = true ;
if ( ! F_219 ( V_583 -> V_590 ) ||
V_583 -> V_15 . V_591 . V_592 == V_593 )
break;
F_39 () ;
V_23 = F_26 ( V_12 , V_583 -> V_287 ) ;
F_43 () ;
if ( ! V_23 )
return - V_594 ;
break;
case V_24 :
case V_66 :
if ( ! V_12 -> V_15 . V_25 . V_520 )
V_584 = true ;
break;
case V_63 :
V_584 = true ;
break;
default:
return - V_206 ;
}
F_24 ( & V_9 -> V_517 ) ;
if ( ! V_584 ) {
V_584 = V_239 != V_9 -> V_98 ;
if ( V_577 &&
V_241 != V_9 -> V_244 )
V_584 = true ;
}
if ( V_584 && ! V_576 ) {
V_19 = - V_28 ;
goto V_51;
}
V_286 = F_93 ( V_9 -> V_96 . V_595 + V_254 ) ;
if ( ! V_286 ) {
V_19 = - V_253 ;
goto V_51;
}
F_220 ( V_286 , V_9 -> V_96 . V_595 ) ;
memcpy ( F_94 ( V_286 , V_254 ) , V_579 , V_254 ) ;
F_221 ( V_286 ) -> V_5 = V_5 ;
V_286 -> V_18 = V_12 -> V_18 ;
if ( ! V_584 ) {
* V_72 = ( unsigned long ) V_286 ;
F_222 ( V_12 , V_286 ) ;
V_19 = 0 ;
goto V_51;
}
F_221 ( V_286 ) -> V_5 |= V_596 ;
if ( V_9 -> V_96 . V_5 & V_597 )
F_221 ( V_286 ) -> V_598 =
V_9 -> V_96 . V_599 ;
V_19 = F_193 ( V_9 , V_12 , V_239 , V_241 ,
V_578 , V_72 , V_286 ) ;
if ( V_19 )
F_223 ( V_286 ) ;
V_51:
F_33 ( & V_9 -> V_517 ) ;
return V_19 ;
}
static int F_224 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_72 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_209 ( V_9 , V_72 , true ) ;
}
static void F_225 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_600 , bool V_601 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( V_600 ) {
case V_602 | V_603 :
if ( V_12 -> V_26 . type == V_57 ) {
struct V_604 * V_605 = & V_12 -> V_15 . V_606 ;
if ( V_601 )
V_605 -> V_607 ++ ;
else
V_605 -> V_607 -- ;
}
break;
case V_602 | V_608 :
if ( V_601 )
V_9 -> V_609 ++ ;
else
V_9 -> V_609 -- ;
if ( ! V_9 -> V_610 )
break;
F_226 ( & V_9 -> V_96 , & V_9 -> V_611 ) ;
break;
default:
break;
}
}
static int F_227 ( struct V_2 * V_2 , T_1 V_612 , T_1 V_613 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_563 )
return - V_206 ;
return F_228 ( V_9 , V_612 , V_613 ) ;
}
static int F_229 ( struct V_2 * V_2 , T_1 * V_612 , T_1 * V_613 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_230 ( V_9 , V_612 , V_613 ) ;
}
static int F_231 ( struct V_2 * V_2 , T_1 V_79 , T_1 V_614 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_232 ( V_9 , V_79 , V_614 ) ;
}
static void F_233 ( struct V_2 * V_2 ,
T_1 * V_79 , T_1 * V_615 , T_1 * V_614 , T_1 * V_616 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_234 ( V_9 , V_79 , V_615 , V_614 , V_616 ) ;
}
static int F_235 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_617 * V_209 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_153 -> V_618 )
return - V_206 ;
F_236 ( V_9 , V_12 , V_209 ) ;
return 0 ;
}
static void F_237 ( struct V_285 * V_286 )
{
T_3 * V_619 = ( void * ) F_94 ( V_286 , 7 ) ;
* V_619 ++ = V_620 ;
* V_619 ++ = 5 ;
* V_619 ++ = 0x0 ;
* V_619 ++ = 0x0 ;
* V_619 ++ = 0x0 ;
* V_619 ++ = 0x0 ;
* V_619 ++ = V_621 ;
}
static T_2 F_238 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_622 ;
V_622 = 0 ;
if ( V_9 -> V_98 -> V_99 != V_623 )
return V_622 ;
if ( ! ( V_9 -> V_96 . V_5 & V_624 ) )
V_622 |= V_625 ;
if ( ! ( V_9 -> V_96 . V_5 & V_626 ) )
V_622 |= V_627 ;
return V_622 ;
}
static void F_239 ( struct V_285 * V_286 , T_3 * V_628 ,
T_3 * V_629 , T_3 * V_214 )
{
struct V_630 * V_631 ;
V_631 = ( void * ) F_94 ( V_286 , sizeof( struct V_630 ) ) ;
V_631 -> V_632 = V_633 ;
V_631 -> V_376 = sizeof( struct V_630 ) - 2 ;
memcpy ( V_631 -> V_214 , V_214 , V_235 ) ;
memcpy ( V_631 -> V_634 , V_628 , V_235 ) ;
memcpy ( V_631 -> V_635 , V_629 , V_235 ) ;
}
static int
F_240 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_629 , T_3 V_636 , T_3 V_637 ,
T_2 V_638 , struct V_285 * V_286 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_639 * V_640 ;
V_640 = ( void * ) F_94 ( V_286 , F_241 ( struct V_639 , V_15 ) ) ;
memcpy ( V_640 -> V_287 , V_629 , V_235 ) ;
memcpy ( V_640 -> V_288 , V_12 -> V_26 . V_234 , V_235 ) ;
V_640 -> V_641 = F_242 ( V_642 ) ;
V_640 -> V_643 = V_644 ;
switch ( V_636 ) {
case V_645 :
V_640 -> V_592 = V_646 ;
V_640 -> V_636 = V_645 ;
F_94 ( V_286 , sizeof( V_640 -> V_15 . V_647 ) ) ;
V_640 -> V_15 . V_647 . V_637 = V_637 ;
V_640 -> V_15 . V_647 . V_648 =
F_243 ( F_238 ( V_12 ) ) ;
F_244 ( V_12 , V_286 , false ,
V_9 -> V_98 -> V_99 ) ;
F_245 ( V_12 , V_286 , false ,
V_9 -> V_98 -> V_99 ) ;
F_237 ( V_286 ) ;
break;
case V_649 :
V_640 -> V_592 = V_646 ;
V_640 -> V_636 = V_649 ;
F_94 ( V_286 , sizeof( V_640 -> V_15 . V_650 ) ) ;
V_640 -> V_15 . V_650 . V_638 = F_243 ( V_638 ) ;
V_640 -> V_15 . V_650 . V_637 = V_637 ;
V_640 -> V_15 . V_650 . V_648 =
F_243 ( F_238 ( V_12 ) ) ;
F_244 ( V_12 , V_286 , false ,
V_9 -> V_98 -> V_99 ) ;
F_245 ( V_12 , V_286 , false ,
V_9 -> V_98 -> V_99 ) ;
F_237 ( V_286 ) ;
break;
case V_651 :
V_640 -> V_592 = V_646 ;
V_640 -> V_636 = V_651 ;
F_94 ( V_286 , sizeof( V_640 -> V_15 . V_652 ) ) ;
V_640 -> V_15 . V_652 . V_638 = F_243 ( V_638 ) ;
V_640 -> V_15 . V_652 . V_637 = V_637 ;
break;
case V_653 :
V_640 -> V_592 = V_646 ;
V_640 -> V_636 = V_653 ;
F_94 ( V_286 , sizeof( V_640 -> V_15 . V_654 ) ) ;
V_640 -> V_15 . V_654 . V_655 = F_243 ( V_638 ) ;
break;
case V_656 :
V_640 -> V_592 = V_646 ;
V_640 -> V_636 = V_656 ;
F_94 ( V_286 , sizeof( V_640 -> V_15 . V_657 ) ) ;
V_640 -> V_15 . V_657 . V_637 = V_637 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int
F_246 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_629 , T_3 V_636 , T_3 V_637 ,
T_2 V_638 , struct V_285 * V_286 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_582 * V_583 ;
V_583 = ( void * ) F_94 ( V_286 , 24 ) ;
memset ( V_583 , 0 , 24 ) ;
memcpy ( V_583 -> V_287 , V_629 , V_235 ) ;
memcpy ( V_583 -> V_288 , V_12 -> V_26 . V_234 , V_235 ) ;
memcpy ( V_583 -> V_214 , V_12 -> V_15 . V_25 . V_214 , V_235 ) ;
V_583 -> V_590 = F_243 ( V_602 |
V_658 ) ;
switch ( V_636 ) {
case V_659 :
F_94 ( V_286 , 1 + sizeof( V_583 -> V_15 . V_591 . V_15 . V_660 ) ) ;
V_583 -> V_15 . V_591 . V_592 = V_593 ;
V_583 -> V_15 . V_591 . V_15 . V_660 . V_636 =
V_659 ;
V_583 -> V_15 . V_591 . V_15 . V_660 . V_637 =
V_637 ;
V_583 -> V_15 . V_591 . V_15 . V_660 . V_648 =
F_243 ( F_238 ( V_12 ) ) ;
F_244 ( V_12 , V_286 , false ,
V_9 -> V_98 -> V_99 ) ;
F_245 ( V_12 , V_286 , false ,
V_9 -> V_98 -> V_99 ) ;
F_237 ( V_286 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_247 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_629 , T_3 V_636 , T_3 V_637 ,
T_2 V_638 , const T_3 * V_661 ,
T_5 V_662 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_663 * V_664 ;
struct V_285 * V_286 = NULL ;
bool V_665 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_666 ) )
return - V_433 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_520 )
return - V_43 ;
F_248 ( V_12 , L_2 ,
V_636 , V_629 ) ;
V_286 = F_93 ( V_9 -> V_96 . V_595 +
F_200 ( sizeof( struct V_582 ) ,
sizeof( struct V_639 ) ) +
50 +
7 +
V_662 +
sizeof( struct V_630 ) ) ;
if ( ! V_286 )
return - V_253 ;
V_664 = F_221 ( V_286 ) ;
F_220 ( V_286 , V_9 -> V_96 . V_595 ) ;
switch ( V_636 ) {
case V_645 :
case V_649 :
case V_651 :
case V_653 :
case V_656 :
V_19 = F_240 ( V_2 , V_18 , V_629 ,
V_636 , V_637 ,
V_638 , V_286 ) ;
V_665 = false ;
break;
case V_659 :
V_19 = F_246 ( V_2 , V_18 , V_629 , V_636 ,
V_637 , V_638 ,
V_286 ) ;
V_665 = true ;
break;
default:
V_19 = - V_433 ;
break;
}
if ( V_19 < 0 )
goto V_667;
if ( V_662 )
memcpy ( F_94 ( V_286 , V_662 ) , V_661 , V_662 ) ;
switch ( V_636 ) {
case V_645 :
case V_651 :
case V_653 :
case V_656 :
F_239 ( V_286 , V_12 -> V_26 . V_234 , V_629 ,
V_12 -> V_15 . V_25 . V_214 ) ;
break;
case V_649 :
case V_659 :
F_239 ( V_286 , V_629 , V_12 -> V_26 . V_234 ,
V_12 -> V_15 . V_25 . V_214 ) ;
break;
default:
V_19 = - V_433 ;
goto V_667;
}
if ( V_665 ) {
F_222 ( V_12 , V_286 ) ;
return 0 ;
}
switch ( V_636 ) {
case V_645 :
case V_649 :
F_249 ( V_286 , V_668 ) ;
V_286 -> V_669 = 2 ;
break;
default:
F_249 ( V_286 , V_670 ) ;
V_286 -> V_669 = 5 ;
break;
}
F_250 () ;
V_19 = F_251 ( V_286 , V_18 ) ;
F_252 () ;
return V_19 ;
V_667:
F_253 ( V_286 ) ;
return V_19 ;
}
static int F_254 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_629 , enum V_671 V_672 )
{
struct V_34 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_666 ) )
return - V_433 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_43 ;
F_248 ( V_12 , L_3 , V_672 , V_629 ) ;
switch ( V_672 ) {
case V_673 :
F_39 () ;
V_23 = F_26 ( V_12 , V_629 ) ;
if ( ! V_23 ) {
F_43 () ;
return - V_594 ;
}
F_101 ( V_23 , V_674 ) ;
F_43 () ;
break;
case V_675 :
return F_255 ( V_12 , V_629 ) ;
case V_676 :
case V_677 :
case V_678 :
return - V_433 ;
default:
return - V_433 ;
}
return 0 ;
}
static int F_256 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_629 , T_4 * V_72 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_679 * V_680 ;
struct V_285 * V_286 ;
int V_260 = sizeof( * V_680 ) ;
T_7 V_681 ;
bool V_682 ;
struct V_663 * V_664 ;
struct V_34 * V_23 ;
F_39 () ;
V_23 = F_26 ( V_12 , V_629 ) ;
if ( V_23 ) {
V_682 = F_29 ( V_23 , V_199 ) ;
F_43 () ;
} else {
F_43 () ;
return - V_594 ;
}
if ( V_682 ) {
V_681 = F_243 ( V_683 |
V_684 |
V_685 ) ;
} else {
V_260 -= 2 ;
V_681 = F_243 ( V_683 |
V_686 |
V_685 ) ;
}
V_286 = F_93 ( V_9 -> V_96 . V_595 + V_260 ) ;
if ( ! V_286 )
return - V_253 ;
V_286 -> V_18 = V_18 ;
F_220 ( V_286 , V_9 -> V_96 . V_595 ) ;
V_680 = ( void * ) F_94 ( V_286 , V_260 ) ;
V_680 -> V_590 = V_681 ;
V_680 -> V_687 = 0 ;
memcpy ( V_680 -> V_688 , V_23 -> V_23 . V_234 , V_235 ) ;
memcpy ( V_680 -> V_689 , V_12 -> V_26 . V_234 , V_235 ) ;
memcpy ( V_680 -> V_690 , V_12 -> V_26 . V_234 , V_235 ) ;
V_680 -> V_691 = 0 ;
V_664 = F_221 ( V_286 ) ;
V_664 -> V_5 |= V_587 |
V_586 ;
F_249 ( V_286 , V_692 ) ;
V_286 -> V_669 = 7 ;
if ( V_682 )
V_680 -> V_693 = F_243 ( 7 ) ;
F_250 () ;
F_257 ( V_12 , V_286 ) ;
F_252 () ;
* V_72 = ( unsigned long ) V_286 ;
return 0 ;
}
static struct V_238 *
F_258 ( struct V_2 * V_2 , struct V_1 * V_10 ,
enum V_240 * type )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* type = V_9 -> V_244 ;
return V_9 -> V_98 ;
}
static void F_259 ( struct V_2 * V_2 , bool V_525 )
{
F_260 ( F_2 ( V_2 ) , V_525 ) ;
}
