static struct V_1 * F_1 ( struct V_2 * V_2 , char * V_3 ,
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
struct V_17 * V_18 ,
T_2 V_29 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
V_12 -> V_29 = V_29 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_2 , struct V_17 * V_18 ,
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
if ( F_17 ( V_12 -> V_9 -> V_42 ) )
return - V_43 ;
break;
default:
break;
}
V_36 = F_18 ( V_7 -> V_38 , V_30 , V_7 -> V_44 ,
V_7 -> V_36 , V_7 -> V_45 , V_7 -> V_46 ) ;
if ( F_17 ( V_36 ) )
return F_19 ( V_36 ) ;
if ( V_31 )
V_36 -> V_47 . V_5 |= V_48 ;
F_20 ( & V_12 -> V_9 -> V_49 ) ;
if ( V_32 ) {
if ( F_21 ( & V_12 -> V_26 ) )
V_23 = F_22 ( V_12 , V_32 ) ;
else
V_23 = F_23 ( V_12 , V_32 ) ;
if ( ! V_23 ) {
F_24 ( V_12 -> V_9 , V_36 ) ;
V_13 = - V_50 ;
goto V_51;
}
}
V_13 = F_25 ( V_36 , V_12 , V_23 ) ;
if ( V_13 )
F_24 ( V_12 -> V_9 , V_36 ) ;
V_51:
F_26 ( & V_12 -> V_9 -> V_49 ) ;
return V_13 ;
}
static int F_27 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
struct V_35 * V_36 = NULL ;
int V_19 ;
F_20 ( & V_9 -> V_49 ) ;
F_20 ( & V_9 -> V_52 ) ;
if ( V_32 ) {
V_19 = - V_50 ;
V_23 = F_23 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_51;
if ( V_31 )
V_36 = F_28 ( V_9 , V_23 -> V_53 ) ;
else
V_36 = F_28 ( V_9 , V_23 -> V_54 [ V_30 ] ) ;
} else
V_36 = F_28 ( V_9 , V_12 -> V_55 [ V_30 ] ) ;
if ( ! V_36 ) {
V_19 = - V_50 ;
goto V_51;
}
F_29 ( V_36 ) ;
V_19 = 0 ;
V_51:
F_26 ( & V_9 -> V_52 ) ;
F_26 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_30 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 V_30 , bool V_31 , const T_3 * V_32 ,
void * V_56 ,
void (* F_31)( void * V_56 ,
struct V_33 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_34 * V_23 = NULL ;
T_3 V_46 [ 6 ] = { 0 } ;
struct V_33 V_7 ;
struct V_35 * V_36 = NULL ;
T_4 V_57 ;
T_1 V_58 ;
T_2 V_59 ;
int V_13 = - V_50 ;
V_12 = F_9 ( V_18 ) ;
F_32 () ;
if ( V_32 ) {
V_23 = F_23 ( V_12 , V_32 ) ;
if ( ! V_23 )
goto V_60;
if ( V_31 )
V_36 = F_33 ( V_23 -> V_53 ) ;
else if ( V_30 < V_61 )
V_36 = F_33 ( V_23 -> V_54 [ V_30 ] ) ;
} else
V_36 = F_33 ( V_12 -> V_55 [ V_30 ] ) ;
if ( ! V_36 )
goto V_60;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_38 = V_36 -> V_47 . V_38 ;
switch ( V_36 -> V_47 . V_38 ) {
case V_40 :
V_58 = V_36 -> V_15 . V_62 . V_63 . V_58 ;
V_59 = V_36 -> V_15 . V_62 . V_63 . V_59 ;
if ( V_36 -> V_5 & V_64 )
F_34 ( V_12 -> V_9 ,
V_36 -> V_47 . V_65 ,
& V_58 , & V_59 ) ;
V_46 [ 0 ] = V_59 & 0xff ;
V_46 [ 1 ] = ( V_59 >> 8 ) & 0xff ;
V_46 [ 2 ] = V_58 & 0xff ;
V_46 [ 3 ] = ( V_58 >> 8 ) & 0xff ;
V_46 [ 4 ] = ( V_58 >> 16 ) & 0xff ;
V_46 [ 5 ] = ( V_58 >> 24 ) & 0xff ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_66 :
V_57 = F_35 ( & V_36 -> V_15 . V_67 . V_68 ) ;
V_46 [ 0 ] = V_57 ;
V_46 [ 1 ] = V_57 >> 8 ;
V_46 [ 2 ] = V_57 >> 16 ;
V_46 [ 3 ] = V_57 >> 24 ;
V_46 [ 4 ] = V_57 >> 32 ;
V_46 [ 5 ] = V_57 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
case V_69 :
V_57 = F_35 ( & V_36 -> V_15 . V_70 . V_68 ) ;
V_46 [ 0 ] = V_57 ;
V_46 [ 1 ] = V_57 >> 8 ;
V_46 [ 2 ] = V_57 >> 16 ;
V_46 [ 3 ] = V_57 >> 24 ;
V_46 [ 4 ] = V_57 >> 32 ;
V_46 [ 5 ] = V_57 >> 40 ;
V_7 . V_46 = V_46 ;
V_7 . V_45 = 6 ;
break;
}
V_7 . V_36 = V_36 -> V_47 . V_36 ;
V_7 . V_44 = V_36 -> V_47 . V_71 ;
F_31 ( V_56 , & V_7 ) ;
V_13 = 0 ;
V_60:
F_36 () ;
return V_13 ;
}
static int F_37 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_30 , bool V_72 ,
bool V_73 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_38 ( V_12 , V_30 , V_72 , V_73 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 V_30 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_40 ( V_12 , V_30 ) ;
return 0 ;
}
static void F_41 ( struct V_74 * V_75 , struct V_34 * V_23 , int V_76 )
{
if ( ! ( V_75 -> V_5 & V_77 ) ) {
struct V_78 * V_79 ;
V_79 = V_23 -> V_9 -> V_80 . V_2 -> V_81 [
V_23 -> V_9 -> V_80 . V_47 . V_82 -> V_83 ] ;
V_75 -> V_84 = V_79 -> V_85 [ V_76 ] . V_86 ;
} else
V_75 -> V_87 = V_76 ;
}
void F_42 ( struct V_34 * V_23 ,
const struct V_88 * V_75 ,
struct V_74 * V_89 )
{
V_89 -> V_5 = 0 ;
if ( V_75 -> V_5 & V_90 )
V_89 -> V_5 |= V_77 ;
if ( V_75 -> V_5 & V_91 )
V_89 -> V_5 |= V_92 ;
if ( V_75 -> V_5 & V_93 )
V_89 -> V_5 |= V_94 ;
F_41 ( V_89 , V_23 , V_75 -> V_76 ) ;
}
static void F_43 ( struct V_34 * V_23 , struct V_95 * V_96 )
{
struct V_11 * V_12 = V_23 -> V_12 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_97 V_98 ;
V_96 -> V_99 = V_12 -> V_9 -> V_100 ;
V_96 -> V_101 = V_102 |
V_103 |
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ;
F_44 ( & V_98 ) ;
V_96 -> V_116 = V_98 . V_117 - V_23 -> V_118 ;
V_96 -> V_119 = F_45 ( V_120 - V_23 -> V_121 ) ;
V_96 -> V_122 = V_23 -> V_122 ;
V_96 -> V_123 = V_23 -> V_123 ;
V_96 -> V_124 = V_23 -> V_124 ;
V_96 -> V_125 = V_23 -> V_125 ;
V_96 -> V_126 = V_23 -> V_127 ;
V_96 -> V_128 = V_23 -> V_129 ;
V_96 -> V_130 = V_23 -> V_131 ;
V_96 -> V_132 = V_23 -> V_132 ;
if ( ( V_23 -> V_9 -> V_80 . V_5 & V_133 ) ||
( V_23 -> V_9 -> V_80 . V_5 & V_134 ) ) {
V_96 -> V_101 |= V_135 | V_136 ;
if ( ! V_9 -> V_137 -> V_138 ||
F_46 ( V_9 , V_12 , & V_23 -> V_23 , & V_96 -> signal ) )
V_96 -> signal = ( V_139 ) V_23 -> V_140 ;
V_96 -> V_141 = ( V_139 ) - F_47 ( & V_23 -> V_142 ) ;
}
F_42 ( V_23 , & V_23 -> V_143 , & V_96 -> V_144 ) ;
V_96 -> V_145 . V_5 = 0 ;
if ( V_23 -> V_146 & V_147 )
V_96 -> V_145 . V_5 |= V_77 ;
if ( V_23 -> V_146 & V_148 )
V_96 -> V_145 . V_5 |= V_92 ;
if ( V_23 -> V_146 & V_149 )
V_96 -> V_145 . V_5 |= V_94 ;
F_41 ( & V_96 -> V_145 , V_23 , V_23 -> V_150 ) ;
if ( F_21 ( & V_12 -> V_26 ) ) {
#ifdef F_48
V_96 -> V_101 |= V_151 |
V_152 |
V_153 ;
V_96 -> V_154 = F_49 ( V_23 -> V_154 ) ;
V_96 -> V_155 = F_49 ( V_23 -> V_155 ) ;
V_96 -> V_156 = V_23 -> V_156 ;
if ( F_50 ( V_23 , V_157 ) ) {
V_96 -> V_101 |= V_158 ;
V_96 -> V_159 = V_23 -> V_159 ;
}
#endif
}
V_96 -> V_160 . V_5 = 0 ;
if ( V_12 -> V_26 . V_161 . V_162 )
V_96 -> V_160 . V_5 |= V_163 ;
if ( V_12 -> V_26 . V_161 . V_164 )
V_96 -> V_160 . V_5 |= V_165 ;
if ( V_12 -> V_26 . V_161 . V_166 )
V_96 -> V_160 . V_5 |= V_167 ;
V_96 -> V_160 . V_168 = V_12 -> V_9 -> V_80 . V_47 . V_169 ;
V_96 -> V_160 . V_170 = V_12 -> V_26 . V_161 . V_171 ;
V_96 -> V_172 . V_173 = 0 ;
V_96 -> V_172 . V_174 = F_51 ( V_175 ) |
F_51 ( V_176 ) |
F_51 ( V_177 ) |
F_51 ( V_178 ) |
F_51 ( V_179 ) |
F_51 ( V_180 ) ;
if ( F_50 ( V_23 , V_181 ) )
V_96 -> V_172 . V_173 |= F_51 ( V_175 ) ;
if ( F_50 ( V_23 , V_182 ) )
V_96 -> V_172 . V_173 |= F_51 ( V_176 ) ;
if ( F_50 ( V_23 , V_183 ) )
V_96 -> V_172 . V_173 |= F_51 ( V_177 ) ;
if ( F_50 ( V_23 , V_184 ) )
V_96 -> V_172 . V_173 |= F_51 ( V_178 ) ;
if ( F_50 ( V_23 , V_185 ) )
V_96 -> V_172 . V_173 |= F_51 ( V_179 ) ;
if ( F_50 ( V_23 , V_186 ) )
V_96 -> V_172 . V_173 |= F_51 ( V_180 ) ;
}
static int F_52 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
int V_187 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_188 = 0 ;
if ( V_187 == V_189 )
V_188 += V_190 ;
V_188 += F_53 ( V_12 , V_187 ) ;
if ( V_188 == 0 )
return - V_191 ;
return V_188 ;
}
static void F_54 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_192 * V_193 ,
T_4 * V_194 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_34 * V_23 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_95 V_96 ;
struct V_195 V_196 ;
int V_197 , V_198 ;
#define F_55 7
memset ( V_194 , 0 , sizeof( T_4 ) * V_190 ) ;
#define F_56 ( V_23 ) \
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
F_20 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 ) {
V_23 = F_23 ( V_12 , V_12 -> V_15 . V_25 . V_199 ) ;
if ( ! ( V_23 && ! F_57 ( V_23 -> V_12 -> V_18 != V_18 ) ) )
goto V_200;
V_197 = 0 ;
F_56 ( V_23 ) ;
V_194 [ V_197 ++ ] = V_23 -> V_201 ;
V_96 . V_101 = 0 ;
F_43 ( V_23 , & V_96 ) ;
if ( V_96 . V_101 & V_109 )
V_194 [ V_197 ] = 100000 *
F_58 ( & V_96 . V_144 ) ;
V_197 ++ ;
if ( V_96 . V_101 & V_110 )
V_194 [ V_197 ] = 100000 *
F_58 ( & V_96 . V_145 ) ;
V_197 ++ ;
if ( V_96 . V_101 & V_136 )
V_194 [ V_197 ] = ( T_3 ) V_96 . V_141 ;
V_197 ++ ;
} else {
F_59 (sta, &local->sta_list, list) {
if ( V_23 -> V_12 -> V_18 != V_18 )
continue;
V_197 = 0 ;
F_56 ( V_23 ) ;
}
}
V_200:
V_197 = V_190 - F_55 ;
V_198 = 0 ;
while ( true ) {
V_196 . V_101 = 0 ;
if ( F_60 ( V_9 , V_198 , & V_196 ) != 0 ) {
V_196 . V_101 = 0 ;
break;
}
if ( V_196 . V_82 &&
( V_9 -> V_202 -> V_203 ==
V_196 . V_82 -> V_203 ) )
break;
V_198 ++ ;
}
if ( V_196 . V_101 )
V_194 [ V_197 ++ ] = V_196 . V_82 -> V_203 ;
else
V_194 [ V_197 ++ ] = 0 ;
if ( V_196 . V_101 & V_204 )
V_194 [ V_197 ++ ] = ( T_3 ) V_196 . V_205 ;
else
V_194 [ V_197 ++ ] = - 1LL ;
if ( V_196 . V_101 & V_206 )
V_194 [ V_197 ++ ] = V_196 . V_207 ;
else
V_194 [ V_197 ++ ] = - 1LL ;
if ( V_196 . V_101 & V_208 )
V_194 [ V_197 ++ ] = V_196 . V_209 ;
else
V_194 [ V_197 ++ ] = - 1LL ;
if ( V_196 . V_101 & V_210 )
V_194 [ V_197 ++ ] = V_196 . V_211 ;
else
V_194 [ V_197 ++ ] = - 1LL ;
if ( V_196 . V_101 & V_212 )
V_194 [ V_197 ++ ] = V_196 . V_213 ;
else
V_194 [ V_197 ++ ] = - 1LL ;
if ( V_196 . V_101 & V_214 )
V_194 [ V_197 ++ ] = V_196 . V_215 ;
else
V_194 [ V_197 ++ ] = - 1LL ;
F_26 ( & V_9 -> V_49 ) ;
if ( F_57 ( V_197 != V_190 ) )
return;
F_61 ( V_12 , V_193 , & ( V_194 [ V_190 ] ) ) ;
}
static void F_62 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_1 V_187 , T_3 * V_194 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
int V_216 = 0 ;
if ( V_187 == V_189 ) {
V_216 = sizeof( V_217 ) ;
memcpy ( V_194 , * V_217 , V_216 ) ;
}
F_63 ( V_12 , V_187 , & ( V_194 [ V_216 ] ) ) ;
}
static int F_64 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_76 , T_3 * V_218 , struct V_95 * V_96 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_50 ;
F_20 ( & V_9 -> V_49 ) ;
V_23 = F_65 ( V_12 , V_76 ) ;
if ( V_23 ) {
V_19 = 0 ;
memcpy ( V_218 , V_23 -> V_23 . V_219 , V_220 ) ;
F_43 ( V_23 , V_96 ) ;
}
F_26 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_66 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_76 , struct V_195 * V_196 )
{
struct V_8 * V_9 = F_67 ( V_18 -> V_221 ) ;
return F_60 ( V_9 , V_76 , V_196 ) ;
}
static int F_68 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_218 , struct V_95 * V_96 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_34 * V_23 ;
int V_19 = - V_50 ;
F_20 ( & V_9 -> V_49 ) ;
V_23 = F_23 ( V_12 , V_218 ) ;
if ( V_23 ) {
V_19 = 0 ;
F_43 ( V_23 , V_96 ) ;
}
F_26 ( & V_9 -> V_49 ) ;
return V_19 ;
}
static int F_69 ( struct V_2 * V_2 ,
struct V_17 * V_222 ,
struct V_223 * V_224 ,
enum V_225 V_226 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
if ( V_222 )
V_12 = F_9 ( V_222 ) ;
switch ( F_70 ( V_9 , NULL ) ) {
case V_227 :
return - V_28 ;
case V_228 :
if ( V_9 -> V_202 != V_224 ||
( ! V_12 && V_9 -> V_229 != V_226 ) )
return - V_28 ;
if ( ! V_12 && V_9 -> V_229 == V_226 )
return 0 ;
break;
case V_230 :
break;
}
if ( ! F_71 ( V_9 , V_12 , V_226 ) )
return - V_28 ;
V_9 -> V_202 = V_224 ;
F_72 ( V_9 , 0 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_2 ,
struct V_223 * V_224 ,
enum V_225 V_226 )
{
return F_69 ( V_2 , NULL , V_224 , V_226 ) ;
}
static int F_74 ( struct V_11 * V_12 ,
const T_3 * V_231 , T_5 V_232 )
{
struct V_233 * V_234 , * V_235 ;
if ( ! V_231 || ! V_232 )
return 1 ;
V_235 = F_75 ( V_12 -> V_15 . V_236 . V_237 ) ;
V_234 = F_76 ( V_232 ) ;
if ( ! V_234 )
return - V_238 ;
memcpy ( F_77 ( V_234 , V_232 ) , V_231 , V_232 ) ;
F_78 ( V_12 -> V_15 . V_236 . V_237 , V_234 ) ;
if ( V_235 ) {
F_79 () ;
F_80 ( V_235 ) ;
}
return 0 ;
}
static int F_81 ( struct V_11 * V_12 ,
struct V_239 * V_7 )
{
struct V_240 * V_234 , * V_235 ;
int V_241 , V_242 ;
int V_243 , V_13 ;
T_1 V_244 = V_245 ;
V_235 = F_75 ( V_12 -> V_15 . V_236 . V_246 ) ;
if ( ! V_7 -> V_247 && ! V_235 )
return - V_43 ;
if ( V_7 -> V_247 )
V_241 = V_7 -> V_248 ;
else
V_241 = V_235 -> V_248 ;
if ( V_7 -> V_249 || ! V_235 )
V_242 = V_7 -> V_250 ;
else
V_242 = V_235 -> V_250 ;
V_243 = sizeof( * V_234 ) + V_241 + V_242 ;
V_234 = F_82 ( V_243 , V_251 ) ;
if ( ! V_234 )
return - V_238 ;
V_234 -> V_247 = ( ( T_3 * ) V_234 ) + sizeof( * V_234 ) ;
V_234 -> V_249 = V_234 -> V_247 + V_241 ;
V_234 -> V_248 = V_241 ;
V_234 -> V_250 = V_242 ;
if ( V_7 -> V_247 )
memcpy ( V_234 -> V_247 , V_7 -> V_247 , V_241 ) ;
else
memcpy ( V_234 -> V_247 , V_235 -> V_247 , V_241 ) ;
if ( V_7 -> V_249 )
memcpy ( V_234 -> V_249 , V_7 -> V_249 , V_242 ) ;
else
if ( V_235 )
memcpy ( V_234 -> V_249 , V_235 -> V_249 , V_242 ) ;
V_13 = F_74 ( V_12 , V_7 -> V_237 ,
V_7 -> V_252 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_244 |= V_253 ;
F_78 ( V_12 -> V_15 . V_236 . V_246 , V_234 ) ;
if ( V_235 )
F_83 ( V_235 , V_254 ) ;
return V_244 ;
}
static int F_84 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_255 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_240 * V_235 ;
struct V_11 * V_22 ;
T_1 V_244 = V_256 |
V_257 |
V_245 |
V_258 ;
int V_13 ;
V_235 = F_75 ( V_12 -> V_15 . V_236 . V_246 ) ;
if ( V_235 )
return - V_259 ;
V_13 = F_69 ( V_2 , V_18 , V_7 -> V_82 ,
V_7 -> V_226 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_260 = V_7 -> V_261 . V_262 ;
V_12 -> V_263 = V_7 -> V_261 . V_263 ;
F_59 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_22 -> V_260 =
V_7 -> V_261 . V_262 ;
V_22 -> V_263 =
V_7 -> V_261 . V_263 ;
}
V_12 -> V_26 . V_161 . V_171 = V_7 -> V_170 ;
V_12 -> V_26 . V_161 . V_168 = V_7 -> V_168 ;
V_12 -> V_26 . V_161 . V_264 = V_7 -> V_264 ;
if ( V_7 -> V_264 )
memcpy ( V_12 -> V_26 . V_161 . V_265 , V_7 -> V_265 ,
V_7 -> V_264 ) ;
V_12 -> V_26 . V_161 . V_266 =
( V_7 -> V_266 != V_267 ) ;
V_13 = F_81 ( V_12 , & V_7 -> V_246 ) ;
if ( V_13 < 0 )
return V_13 ;
V_244 |= V_13 ;
F_85 ( V_12 , V_244 ) ;
F_86 ( V_18 ) ;
F_59 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_86 ( V_22 -> V_18 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_239 * V_7 )
{
struct V_11 * V_12 ;
struct V_240 * V_235 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
V_235 = F_75 ( V_12 -> V_15 . V_236 . V_246 ) ;
if ( ! V_235 )
return - V_50 ;
V_13 = F_81 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_85 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 , * V_22 ;
struct V_240 * V_235 ;
V_12 = F_9 ( V_18 ) ;
V_235 = F_75 ( V_12 -> V_15 . V_236 . V_246 ) ;
if ( ! V_235 )
return - V_50 ;
F_59 (vlan, &sdata->u.ap.vlans, u.vlan.list)
F_89 ( V_22 -> V_18 ) ;
F_89 ( V_18 ) ;
F_11 ( V_12 -> V_15 . V_236 . V_246 , NULL ) ;
F_83 ( V_235 , V_254 ) ;
F_90 ( V_12 -> V_9 , V_12 ) ;
F_85 ( V_12 , V_257 ) ;
return 0 ;
}
static void F_91 ( struct V_34 * V_23 )
{
struct V_268 * V_269 ;
struct V_233 * V_270 ;
V_270 = F_76 ( sizeof( * V_269 ) ) ;
if ( ! V_270 )
return;
V_269 = (struct V_268 * ) F_77 ( V_270 , sizeof( * V_269 ) ) ;
memset ( V_269 -> V_271 , 0xff , V_220 ) ;
memcpy ( V_269 -> V_272 , V_23 -> V_23 . V_219 , V_220 ) ;
V_269 -> V_273 = F_92 ( 6 ) ;
V_269 -> V_274 = 0 ;
V_269 -> V_275 = 0x01 ;
V_269 -> V_276 = 0xaf ;
V_269 -> V_277 [ 0 ] = 0x81 ;
V_269 -> V_277 [ 1 ] = 1 ;
V_269 -> V_277 [ 2 ] = 0 ;
V_270 -> V_18 = V_23 -> V_12 -> V_18 ;
V_270 -> V_278 = F_93 ( V_270 , V_23 -> V_12 -> V_18 ) ;
memset ( V_270 -> V_279 , 0 , sizeof( V_270 -> V_279 ) ) ;
F_94 ( V_270 ) ;
}
static int F_95 ( struct V_8 * V_9 ,
struct V_34 * V_23 ,
struct V_280 * V_7 )
{
int V_19 = 0 ;
T_1 V_281 ;
int V_197 , V_282 ;
struct V_78 * V_79 ;
struct V_11 * V_12 = V_23 -> V_12 ;
T_1 V_174 , V_173 ;
V_79 = V_9 -> V_80 . V_2 -> V_81 [ V_9 -> V_202 -> V_83 ] ;
V_174 = V_7 -> V_283 ;
V_173 = V_7 -> V_284 ;
if ( V_174 & F_51 ( V_179 ) ) {
if ( F_57 ( ! F_21 ( & V_12 -> V_26 ) ) )
return - V_43 ;
if ( V_173 & F_51 ( V_179 ) &&
! F_50 ( V_23 , V_185 ) ) {
V_19 = F_96 ( V_23 , V_285 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_96 ( V_23 , V_286 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_174 & F_51 ( V_175 ) ) {
if ( V_173 & F_51 ( V_175 ) )
V_19 = F_96 ( V_23 , V_287 ) ;
else if ( F_50 ( V_23 , V_181 ) )
V_19 = F_96 ( V_23 , V_286 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_174 & F_51 ( V_179 ) ) {
if ( F_57 ( ! F_21 ( & V_12 -> V_26 ) ) )
return - V_43 ;
if ( ! ( V_173 & F_51 ( V_179 ) ) &&
F_50 ( V_23 , V_185 ) ) {
V_19 = F_96 ( V_23 , V_285 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_96 ( V_23 , V_288 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_174 & F_51 ( V_176 ) ) {
if ( V_173 & F_51 ( V_176 ) )
F_97 ( V_23 , V_182 ) ;
else
F_98 ( V_23 , V_182 ) ;
}
if ( V_174 & F_51 ( V_177 ) ) {
if ( V_173 & F_51 ( V_177 ) ) {
F_97 ( V_23 , V_183 ) ;
V_23 -> V_23 . V_289 = true ;
} else {
F_98 ( V_23 , V_183 ) ;
V_23 -> V_23 . V_289 = false ;
}
}
if ( V_174 & F_51 ( V_178 ) ) {
if ( V_173 & F_51 ( V_178 ) )
F_97 ( V_23 , V_184 ) ;
else
F_98 ( V_23 , V_184 ) ;
}
if ( V_174 & F_51 ( V_180 ) ) {
if ( V_173 & F_51 ( V_180 ) )
F_97 ( V_23 , V_186 ) ;
else
F_98 ( V_23 , V_186 ) ;
}
if ( V_7 -> V_290 & V_291 ) {
V_23 -> V_23 . V_292 = V_7 -> V_292 ;
V_23 -> V_23 . V_293 = V_7 -> V_293 ;
}
if ( V_7 -> V_294 )
V_23 -> V_23 . V_294 = V_7 -> V_294 ;
if ( V_7 -> V_295 >= 0 )
V_23 -> V_295 = V_7 -> V_295 ;
if ( V_7 -> V_296 ) {
V_281 = 0 ;
for ( V_197 = 0 ; V_197 < V_7 -> V_297 ; V_197 ++ ) {
int V_75 = ( V_7 -> V_296 [ V_197 ] & 0x7f ) * 5 ;
for ( V_282 = 0 ; V_282 < V_79 -> V_298 ; V_282 ++ ) {
if ( V_79 -> V_85 [ V_282 ] . V_86 == V_75 )
V_281 |= F_51 ( V_282 ) ;
}
}
V_23 -> V_23 . V_299 [ V_9 -> V_202 -> V_83 ] = V_281 ;
}
if ( V_7 -> V_300 )
F_99 ( V_12 , V_79 ,
V_7 -> V_300 ,
& V_23 -> V_23 . V_301 ) ;
if ( F_21 ( & V_12 -> V_26 ) ) {
#ifdef F_48
if ( V_12 -> V_15 . V_302 . V_303 & V_304 )
switch ( V_7 -> V_156 ) {
case V_305 :
case V_306 :
case V_307 :
V_23 -> V_156 = V_7 -> V_156 ;
break;
default:
break;
}
else
switch ( V_7 -> V_308 ) {
case V_309 :
F_100 ( V_23 ) ;
break;
case V_310 :
F_101 ( V_23 ) ;
break;
}
#endif
}
return 0 ;
}
static int F_102 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_218 , struct V_280 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_12 ;
int V_13 ;
int V_311 ;
if ( V_7 -> V_22 ) {
V_12 = F_9 ( V_7 -> V_22 ) ;
if ( V_12 -> V_26 . type != V_20 &&
V_12 -> V_26 . type != V_312 )
return - V_43 ;
} else
V_12 = F_9 ( V_18 ) ;
if ( F_103 ( V_218 , V_12 -> V_26 . V_219 ) )
return - V_43 ;
if ( F_104 ( V_218 ) )
return - V_43 ;
V_23 = F_105 ( V_12 , V_218 , V_251 ) ;
if ( ! V_23 )
return - V_238 ;
F_106 ( V_23 , V_285 ) ;
F_106 ( V_23 , V_286 ) ;
V_13 = F_95 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_107 ( V_9 , V_23 ) ;
return V_13 ;
}
if ( ! F_50 ( V_23 , V_186 ) )
F_108 ( V_23 ) ;
V_311 = V_12 -> V_26 . type == V_20 ||
V_12 -> V_26 . type == V_312 ;
V_13 = F_109 ( V_23 ) ;
if ( V_13 ) {
F_36 () ;
return V_13 ;
}
if ( V_311 )
F_91 ( V_23 ) ;
F_36 () ;
return 0 ;
}
static int F_110 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_218 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
if ( V_218 )
return F_111 ( V_12 , V_218 ) ;
F_90 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_218 ,
struct V_280 * V_7 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_34 * V_23 ;
struct V_11 * V_313 ;
int V_13 ;
F_20 ( & V_9 -> V_49 ) ;
V_23 = F_23 ( V_12 , V_218 ) ;
if ( ! V_23 ) {
F_26 ( & V_9 -> V_49 ) ;
return - V_50 ;
}
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_296 &&
! F_50 ( V_23 , V_186 ) ) {
F_26 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 && V_7 -> V_22 != V_23 -> V_12 -> V_18 ) {
bool V_314 = false ;
bool V_315 = false ;
V_313 = F_9 ( V_7 -> V_22 ) ;
if ( V_313 -> V_26 . type != V_20 &&
V_313 -> V_26 . type != V_312 ) {
F_26 ( & V_9 -> V_49 ) ;
return - V_43 ;
}
if ( V_7 -> V_22 -> V_221 -> V_21 ) {
if ( V_313 -> V_15 . V_22 . V_23 ) {
F_26 ( & V_9 -> V_49 ) ;
return - V_28 ;
}
F_78 ( V_313 -> V_15 . V_22 . V_23 , V_23 ) ;
V_315 = true ;
}
if ( V_23 -> V_12 -> V_26 . type == V_20 &&
V_23 -> V_12 -> V_15 . V_22 . V_23 ) {
F_78 ( V_23 -> V_12 -> V_15 . V_22 . V_23 , NULL ) ;
V_314 = true ;
}
V_23 -> V_12 = V_313 ;
if ( V_23 -> V_201 == V_287 &&
V_314 != V_315 ) {
if ( V_315 )
F_113 ( & V_23 -> V_12 -> V_316 -> V_317 ) ;
else
F_114 ( & V_23 -> V_12 -> V_316 -> V_317 ) ;
}
F_91 ( V_23 ) ;
}
V_13 = F_95 ( V_9 , V_23 , V_7 ) ;
if ( V_13 ) {
F_26 ( & V_9 -> V_49 ) ;
return V_13 ;
}
if ( F_50 ( V_23 , V_186 ) && V_7 -> V_296 )
F_108 ( V_23 ) ;
F_26 ( & V_9 -> V_49 ) ;
if ( V_12 -> V_26 . type == V_24 &&
V_7 -> V_283 & F_51 ( V_175 ) )
F_115 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_318 , T_3 * V_319 )
{
struct V_11 * V_12 ;
struct V_320 * V_321 ;
struct V_34 * V_23 ;
int V_13 ;
V_12 = F_9 ( V_18 ) ;
F_32 () ;
V_23 = F_22 ( V_12 , V_319 ) ;
if ( ! V_23 ) {
F_36 () ;
return - V_50 ;
}
V_13 = F_117 ( V_318 , V_12 ) ;
if ( V_13 ) {
F_36 () ;
return V_13 ;
}
V_321 = F_118 ( V_318 , V_12 ) ;
if ( ! V_321 ) {
F_36 () ;
return - V_322 ;
}
F_119 ( V_321 , V_23 ) ;
F_36 () ;
return 0 ;
}
static int F_120 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_318 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( V_318 )
return F_121 ( V_318 , V_12 ) ;
F_122 ( V_12 ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_3 * V_318 , T_3 * V_319 )
{
struct V_11 * V_12 ;
struct V_320 * V_321 ;
struct V_34 * V_23 ;
V_12 = F_9 ( V_18 ) ;
F_32 () ;
V_23 = F_22 ( V_12 , V_319 ) ;
if ( ! V_23 ) {
F_36 () ;
return - V_50 ;
}
V_321 = F_118 ( V_318 , V_12 ) ;
if ( ! V_321 ) {
F_36 () ;
return - V_50 ;
}
F_119 ( V_321 , V_23 ) ;
F_36 () ;
return 0 ;
}
static void F_124 ( struct V_320 * V_321 , T_3 * V_319 ,
struct V_323 * V_324 )
{
struct V_34 * V_325 = F_33 ( V_321 -> V_319 ) ;
if ( V_325 )
memcpy ( V_319 , V_325 -> V_23 . V_219 , V_220 ) ;
else
memset ( V_319 , 0 , V_220 ) ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
V_324 -> V_99 = V_326 ;
V_324 -> V_101 = V_327 |
V_328 |
V_329 |
V_330 |
V_331 |
V_332 |
V_333 ;
V_324 -> V_334 = V_321 -> V_335 . V_336 ;
V_324 -> V_337 = V_321 -> V_337 ;
V_324 -> V_338 = V_321 -> V_338 ;
if ( F_125 ( V_120 , V_321 -> V_339 ) )
V_324 -> V_340 = F_45 ( V_321 -> V_339 - V_120 ) ;
V_324 -> V_341 =
F_45 ( V_321 -> V_341 ) ;
V_324 -> V_342 = V_321 -> V_342 ;
if ( V_321 -> V_5 & V_343 )
V_324 -> V_5 |= V_344 ;
if ( V_321 -> V_5 & V_345 )
V_324 -> V_5 |= V_346 ;
if ( V_321 -> V_5 & V_347 )
V_324 -> V_5 |= V_348 ;
if ( V_321 -> V_5 & V_349 )
V_324 -> V_5 |= V_350 ;
if ( V_321 -> V_5 & V_351 )
V_324 -> V_5 |= V_352 ;
}
static int F_126 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_318 , T_3 * V_319 , struct V_323 * V_324 )
{
struct V_11 * V_12 ;
struct V_320 * V_321 ;
V_12 = F_9 ( V_18 ) ;
F_32 () ;
V_321 = F_118 ( V_318 , V_12 ) ;
if ( ! V_321 ) {
F_36 () ;
return - V_50 ;
}
memcpy ( V_318 , V_321 -> V_318 , V_220 ) ;
F_124 ( V_321 , V_319 , V_324 ) ;
F_36 () ;
return 0 ;
}
static int F_127 ( struct V_2 * V_2 , struct V_17 * V_18 ,
int V_76 , T_3 * V_318 , T_3 * V_319 ,
struct V_323 * V_324 )
{
struct V_11 * V_12 ;
struct V_320 * V_321 ;
V_12 = F_9 ( V_18 ) ;
F_32 () ;
V_321 = F_128 ( V_76 , V_12 ) ;
if ( ! V_321 ) {
F_36 () ;
return - V_50 ;
}
memcpy ( V_318 , V_321 -> V_318 , V_220 ) ;
F_124 ( V_321 , V_319 , V_324 ) ;
F_36 () ;
return 0 ;
}
static int F_129 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_353 * V_47 )
{
struct V_11 * V_12 ;
V_12 = F_9 ( V_18 ) ;
memcpy ( V_47 , & ( V_12 -> V_15 . V_302 . V_354 ) , sizeof( struct V_353 ) ) ;
return 0 ;
}
static inline bool F_130 ( enum V_355 V_356 , T_1 V_174 )
{
return ( V_174 >> ( V_356 - 1 ) ) & 0x1 ;
}
static int F_131 ( struct V_357 * V_358 ,
const struct V_359 * V_360 )
{
T_3 * V_361 ;
const T_3 * V_362 ;
struct V_11 * V_12 = F_132 ( V_358 ,
struct V_11 , V_15 . V_302 ) ;
V_361 = NULL ;
V_362 = V_358 -> V_363 ;
if ( V_360 -> V_364 ) {
V_361 = F_133 ( V_360 -> V_363 , V_360 -> V_364 ,
V_251 ) ;
if ( ! V_361 )
return - V_238 ;
}
V_358 -> V_364 = V_360 -> V_364 ;
V_358 -> V_363 = V_361 ;
F_134 ( V_362 ) ;
V_358 -> V_365 = V_360 -> V_365 ;
memcpy ( V_358 -> V_366 , V_360 -> V_366 , V_358 -> V_365 ) ;
V_358 -> V_367 = V_360 -> V_368 ;
V_358 -> V_369 = V_360 -> V_370 ;
V_358 -> V_371 = V_360 -> V_372 ;
V_358 -> V_303 = V_373 ;
if ( V_360 -> V_374 )
V_358 -> V_303 |= V_375 ;
if ( V_360 -> V_376 )
V_358 -> V_303 |= V_304 ;
memcpy ( V_12 -> V_26 . V_161 . V_377 , V_360 -> V_377 ,
sizeof( V_360 -> V_377 ) ) ;
return 0 ;
}
static int F_135 ( struct V_2 * V_2 ,
struct V_17 * V_18 , T_1 V_174 ,
const struct V_353 * V_378 )
{
struct V_353 * V_47 ;
struct V_11 * V_12 ;
struct V_357 * V_358 ;
V_12 = F_9 ( V_18 ) ;
V_358 = & V_12 -> V_15 . V_302 ;
V_47 = & ( V_12 -> V_15 . V_302 . V_354 ) ;
if ( F_130 ( V_379 , V_174 ) )
V_47 -> V_380 = V_378 -> V_380 ;
if ( F_130 ( V_381 , V_174 ) )
V_47 -> V_382 = V_378 -> V_382 ;
if ( F_130 ( V_383 , V_174 ) )
V_47 -> V_384 = V_378 -> V_384 ;
if ( F_130 ( V_385 , V_174 ) )
V_47 -> V_386 = V_378 -> V_386 ;
if ( F_130 ( V_387 , V_174 ) )
V_47 -> V_388 = V_378 -> V_388 ;
if ( F_130 ( V_389 , V_174 ) )
V_47 -> V_390 = V_378 -> V_390 ;
if ( F_130 ( V_391 , V_174 ) )
V_47 -> V_392 = V_378 -> V_392 ;
if ( F_130 ( V_393 , V_174 ) )
V_47 -> V_394 = V_378 -> V_394 ;
if ( F_130 ( V_395 , V_174 ) )
V_47 -> V_396 =
V_378 -> V_396 ;
if ( F_130 ( V_397 , V_174 ) )
V_47 -> V_398 =
V_378 -> V_398 ;
if ( F_130 ( V_399 , V_174 ) )
V_47 -> V_400 = V_378 -> V_400 ;
if ( F_130 ( V_401 , V_174 ) )
V_47 -> V_402 = V_378 -> V_402 ;
if ( F_130 ( V_403 , V_174 ) )
V_47 -> V_404 =
V_378 -> V_404 ;
if ( F_130 ( V_405 , V_174 ) )
V_47 -> V_406 =
V_378 -> V_406 ;
if ( F_130 ( V_407 , V_174 ) )
V_47 -> V_408 =
V_378 -> V_408 ;
if ( F_130 ( V_409 ,
V_174 ) )
V_47 -> V_410 =
V_378 -> V_410 ;
if ( F_130 ( V_411 , V_174 ) ) {
V_47 -> V_412 = V_378 -> V_412 ;
F_136 ( V_358 ) ;
}
if ( F_130 ( V_413 , V_174 ) ) {
if ( V_378 -> V_414 &&
! ( V_47 -> V_412 > V_415 ) ) {
V_47 -> V_412 = V_416 ;
F_136 ( V_358 ) ;
}
V_47 -> V_414 =
V_378 -> V_414 ;
}
if ( F_130 ( V_417 , V_174 ) )
V_47 -> V_418 =
V_378 -> V_418 ;
if ( F_130 ( V_419 , V_174 ) )
V_47 -> V_420 = V_378 -> V_420 ;
if ( F_130 ( V_421 , V_174 ) ) {
if ( ! ( V_12 -> V_9 -> V_80 . V_5 & V_133 ) )
return - V_422 ;
V_47 -> V_423 = V_378 -> V_423 ;
}
if ( F_130 ( V_424 , V_174 ) ) {
V_47 -> V_425 = V_378 -> V_425 ;
V_12 -> V_26 . V_161 . V_426 = V_378 -> V_425 ;
F_85 ( V_12 , V_427 ) ;
}
if ( F_130 ( V_428 , V_174 ) )
V_47 -> V_429 =
V_378 -> V_429 ;
if ( F_130 ( V_430 , V_174 ) )
V_47 -> V_431 =
V_378 -> V_431 ;
if ( F_130 ( V_432 , V_174 ) )
V_47 -> V_433 =
V_378 -> V_433 ;
return 0 ;
}
static int F_137 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const struct V_353 * V_47 ,
const struct V_359 * V_360 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_357 * V_358 = & V_12 -> V_15 . V_302 ;
int V_13 ;
memcpy ( & V_358 -> V_354 , V_47 , sizeof( struct V_353 ) ) ;
V_13 = F_131 ( V_358 , V_360 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_69 ( V_2 , V_18 , V_360 -> V_82 ,
V_360 -> V_226 ) ;
if ( V_13 )
return V_13 ;
F_138 ( V_12 ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
F_140 ( V_12 ) ;
return 0 ;
}
static int F_141 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_434 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_244 = 0 ;
V_12 = F_9 ( V_18 ) ;
if ( V_7 -> V_162 >= 0 ) {
V_12 -> V_26 . V_161 . V_162 = V_7 -> V_162 ;
V_244 |= V_435 ;
}
if ( V_7 -> V_164 >= 0 ) {
V_12 -> V_26 . V_161 . V_164 =
V_7 -> V_164 ;
V_244 |= V_436 ;
}
if ( ! V_12 -> V_26 . V_161 . V_166 &&
V_12 -> V_9 -> V_80 . V_47 . V_82 -> V_83 == V_437 ) {
V_12 -> V_26 . V_161 . V_166 = true ;
V_244 |= V_438 ;
}
if ( V_7 -> V_439 >= 0 ) {
V_12 -> V_26 . V_161 . V_166 =
V_7 -> V_439 ;
V_244 |= V_438 ;
}
if ( V_7 -> V_440 ) {
int V_197 , V_282 ;
T_1 V_281 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_78 * V_79 =
V_2 -> V_81 [ V_9 -> V_202 -> V_83 ] ;
for ( V_197 = 0 ; V_197 < V_7 -> V_441 ; V_197 ++ ) {
int V_75 = ( V_7 -> V_440 [ V_197 ] & 0x7f ) * 5 ;
for ( V_282 = 0 ; V_282 < V_79 -> V_298 ; V_282 ++ ) {
if ( V_79 -> V_85 [ V_282 ] . V_86 == V_75 )
V_281 |= F_51 ( V_282 ) ;
}
}
V_12 -> V_26 . V_161 . V_440 = V_281 ;
V_244 |= V_442 ;
}
if ( V_7 -> V_443 >= 0 ) {
if ( V_7 -> V_443 )
V_12 -> V_5 |= V_444 ;
else
V_12 -> V_5 &= ~ V_444 ;
}
if ( V_7 -> V_425 >= 0 ) {
V_12 -> V_26 . V_161 . V_426 =
( T_2 ) V_7 -> V_425 ;
V_244 |= V_427 ;
}
F_85 ( V_12 , V_244 ) ;
return 0 ;
}
static int F_142 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_445 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_446 V_447 ;
if ( ! V_9 -> V_137 -> V_448 )
return - V_191 ;
if ( V_9 -> V_80 . V_449 < V_450 )
return - V_191 ;
memset ( & V_447 , 0 , sizeof( V_447 ) ) ;
V_447 . V_451 = V_7 -> V_451 ;
V_447 . V_452 = V_7 -> V_453 ;
V_447 . V_454 = V_7 -> V_455 ;
V_447 . V_456 = V_7 -> V_456 ;
V_447 . V_457 = false ;
V_12 -> V_458 [ V_7 -> V_459 ] = V_447 ;
if ( F_143 ( V_9 , V_12 , V_7 -> V_459 , & V_447 ) ) {
F_144 ( V_9 -> V_80 . V_2 ,
L_1 ,
V_7 -> V_459 ) ;
return - V_43 ;
}
F_85 ( V_12 , V_460 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_2 ,
struct V_461 * V_462 )
{
return F_146 ( F_2 ( V_2 ) , V_462 ) ;
}
static int F_147 ( struct V_2 * V_2 )
{
return F_148 ( F_2 ( V_2 ) ) ;
}
static int F_149 ( struct V_2 * V_2 ,
struct V_463 * V_464 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_464 -> V_10 ) ;
switch ( F_150 ( & V_12 -> V_26 ) ) {
case V_24 :
case V_465 :
case V_466 :
case V_467 :
break;
case V_468 :
if ( V_12 -> V_9 -> V_137 -> V_469 )
break;
case V_312 :
if ( V_12 -> V_15 . V_236 . V_246 )
return - V_191 ;
break;
default:
return - V_191 ;
}
return F_151 ( V_12 , V_464 ) ;
}
static int
F_152 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_470 * V_464 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_137 -> V_471 )
return - V_191 ;
return F_153 ( V_12 , V_464 ) ;
}
static int
F_154 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_12 -> V_9 -> V_137 -> V_472 )
return - V_191 ;
return F_155 ( V_12 ) ;
}
static int F_156 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_473 * V_464 )
{
return F_157 ( F_9 ( V_18 ) , V_464 ) ;
}
static int F_158 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_474 * V_464 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
switch ( F_70 ( V_9 , V_12 ) ) {
case V_227 :
return - V_28 ;
case V_228 :
if ( V_9 -> V_202 == V_464 -> V_316 -> V_82 )
break;
return - V_28 ;
case V_230 :
break;
}
return F_159 ( F_9 ( V_18 ) , V_464 ) ;
}
static int F_160 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_475 * V_464 )
{
return F_161 ( F_9 ( V_18 ) , V_464 ) ;
}
static int F_162 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_476 * V_464 )
{
return F_163 ( F_9 ( V_18 ) , V_464 ) ;
}
static int F_164 ( struct V_2 * V_2 , struct V_17 * V_18 ,
struct V_477 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
switch ( F_70 ( V_9 , V_12 ) ) {
case V_227 :
return - V_28 ;
case V_228 :
if ( ! V_7 -> V_478 )
return - V_28 ;
if ( V_9 -> V_202 == V_7 -> V_82 )
break;
return - V_28 ;
case V_230 :
break;
}
return F_165 ( V_12 , V_7 ) ;
}
static int F_166 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
return F_167 ( V_12 ) ;
}
static int F_168 ( struct V_2 * V_2 , T_1 V_244 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_244 & V_479 ) {
V_13 = F_169 ( V_9 , V_2 -> V_480 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_244 & V_481 ) {
V_13 = F_170 ( V_9 , V_2 -> V_482 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_244 & V_483 ) {
V_13 = F_171 ( V_9 , V_2 -> V_484 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_244 & V_485 )
V_9 -> V_80 . V_47 . V_486 = V_2 -> V_487 ;
if ( V_244 & V_488 )
V_9 -> V_80 . V_47 . V_489 = V_2 -> V_490 ;
if ( V_244 &
( V_485 | V_488 ) )
F_72 ( V_9 , V_491 ) ;
return 0 ;
}
static int F_172 ( struct V_2 * V_2 ,
enum V_492 type , int V_493 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_223 * V_224 = V_9 -> V_80 . V_47 . V_82 ;
T_1 V_494 = 0 ;
switch ( type ) {
case V_495 :
V_9 -> V_496 = - 1 ;
break;
case V_497 :
if ( V_493 < 0 || ( V_493 % 100 ) )
return - V_191 ;
V_9 -> V_496 = F_173 ( V_493 ) ;
break;
case V_498 :
if ( V_493 < 0 || ( V_493 % 100 ) )
return - V_191 ;
if ( F_173 ( V_493 ) > V_224 -> V_499 )
return - V_43 ;
V_9 -> V_496 = F_173 ( V_493 ) ;
break;
}
F_72 ( V_9 , V_494 ) ;
return 0 ;
}
static int F_174 ( struct V_2 * V_2 , int * V_500 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_500 = V_9 -> V_80 . V_47 . V_501 ;
return 0 ;
}
static int F_175 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_219 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
memcpy ( & V_12 -> V_15 . V_502 . V_503 , V_219 , V_220 ) ;
return 0 ;
}
static void F_176 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_177 ( V_9 ) ;
}
static int F_178 ( struct V_2 * V_2 , void * V_194 , int V_273 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_137 -> V_504 )
return - V_191 ;
return V_9 -> V_137 -> V_504 ( & V_9 -> V_80 , V_194 , V_273 ) ;
}
static int F_179 ( struct V_2 * V_2 ,
struct V_233 * V_270 ,
struct V_505 * V_279 ,
void * V_194 , int V_273 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_137 -> V_506 )
return - V_191 ;
return V_9 -> V_137 -> V_506 ( & V_9 -> V_80 , V_270 , V_279 , V_194 , V_273 ) ;
}
int F_180 ( struct V_11 * V_12 ,
enum V_507 V_508 )
{
const T_3 * V_236 ;
enum V_507 V_509 ;
int V_13 ;
F_181 ( & V_12 -> V_15 . V_25 . V_510 ) ;
V_509 = V_12 -> V_15 . V_25 . V_511 ;
V_12 -> V_15 . V_25 . V_511 = V_508 ;
if ( V_509 == V_508 &&
V_508 != V_512 )
return 0 ;
if ( ! V_12 -> V_15 . V_25 . V_513 ||
V_12 -> V_26 . V_161 . V_226 == V_514 ) {
F_20 ( & V_12 -> V_9 -> V_515 ) ;
F_182 ( V_12 -> V_9 ) ;
F_26 ( & V_12 -> V_9 -> V_515 ) ;
return 0 ;
}
V_236 = V_12 -> V_15 . V_25 . V_513 -> V_199 ;
if ( V_508 == V_512 ) {
if ( V_12 -> V_15 . V_25 . V_516 )
V_508 = V_517 ;
else
V_508 = V_518 ;
}
V_13 = F_183 ( V_12 , V_508 ,
V_236 , V_236 ) ;
if ( V_13 )
V_12 -> V_15 . V_25 . V_511 = V_509 ;
return V_13 ;
}
static int F_184 ( struct V_2 * V_2 , struct V_17 * V_18 ,
bool V_519 , int V_520 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_67 ( V_18 -> V_221 ) ;
if ( V_12 -> V_26 . type != V_24 )
return - V_191 ;
if ( ! ( V_9 -> V_80 . V_5 & V_521 ) )
return - V_191 ;
if ( V_519 == V_12 -> V_15 . V_25 . V_516 &&
V_520 == V_9 -> V_522 )
return 0 ;
V_12 -> V_15 . V_25 . V_516 = V_519 ;
V_9 -> V_522 = V_520 ;
F_20 ( & V_12 -> V_15 . V_25 . V_510 ) ;
F_180 ( V_12 , V_12 -> V_15 . V_25 . V_511 ) ;
F_26 ( & V_12 -> V_15 . V_25 . V_510 ) ;
if ( V_9 -> V_80 . V_5 & V_523 )
F_72 ( V_9 , V_524 ) ;
F_115 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_185 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
T_6 V_525 , T_1 V_526 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_527 * V_26 = & V_12 -> V_26 ;
struct V_528 * V_161 = & V_26 -> V_161 ;
if ( V_525 == V_161 -> V_529 &&
V_526 == V_161 -> V_530 )
return 0 ;
V_161 -> V_529 = V_525 ;
V_161 -> V_530 = V_526 ;
if ( V_12 -> V_15 . V_25 . V_513 &&
V_12 -> V_26 . V_531 & V_532 )
F_85 ( V_12 , V_533 ) ;
return 0 ;
}
static int F_186 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
const T_3 * V_219 ,
const struct V_534 * V_174 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = F_67 ( V_18 -> V_221 ) ;
int V_197 , V_19 ;
if ( ! F_12 ( V_12 ) )
return - V_37 ;
if ( V_9 -> V_80 . V_5 & V_535 ) {
V_19 = F_187 ( V_9 , V_12 , V_174 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_197 = 0 ; V_197 < V_536 ; V_197 ++ ) {
V_12 -> V_537 [ V_197 ] = V_174 -> V_276 [ V_197 ] . V_84 ;
memcpy ( V_12 -> V_538 [ V_197 ] , V_174 -> V_276 [ V_197 ] . V_87 ,
sizeof( V_174 -> V_276 [ V_197 ] . V_87 ) ) ;
}
return 0 ;
}
static int F_188 ( struct V_8 * V_9 ,
struct V_11 * V_12 ,
struct V_223 * V_82 ,
enum V_225 V_226 ,
unsigned int V_539 , T_4 * V_56 ,
struct V_233 * V_540 )
{
struct V_541 * V_542 , * V_543 ;
bool V_544 = false ;
int V_19 ;
F_181 ( & V_9 -> V_510 ) ;
V_542 = F_82 ( sizeof( * V_542 ) , V_251 ) ;
if ( ! V_542 )
return - V_238 ;
V_542 -> V_224 = V_82 ;
V_542 -> V_545 = V_226 ;
V_542 -> V_539 = V_539 ;
V_542 -> V_546 = V_539 ;
V_542 -> V_547 = V_540 ;
V_542 -> V_548 = ( unsigned long ) V_540 ;
V_542 -> V_12 = V_12 ;
F_189 ( & V_542 -> V_549 , V_550 ) ;
F_190 ( & V_542 -> V_551 ) ;
if ( ! F_191 ( & V_9 -> V_552 ) || V_9 -> V_553 )
goto V_554;
if ( ! V_9 -> V_137 -> V_555 ) {
F_192 ( & V_9 -> V_80 , & V_542 -> V_549 , 0 ) ;
goto V_556;
}
if ( ! V_539 )
V_539 = 10 ;
V_19 = F_193 ( V_9 , V_82 , V_226 , V_539 ) ;
if ( V_19 ) {
F_134 ( V_542 ) ;
return V_19 ;
}
V_542 -> V_557 = true ;
goto V_556;
V_554:
F_59 (tmp, &local->roc_list, list) {
if ( V_543 -> V_224 != V_82 || V_543 -> V_545 != V_226 )
continue;
if ( ! V_543 -> V_557 ) {
F_194 ( & V_542 -> V_558 , & V_543 -> V_551 ) ;
V_543 -> V_539 = F_195 ( V_543 -> V_539 , V_542 -> V_539 ) ;
V_544 = true ;
break;
}
if ( V_9 -> V_137 -> V_555 ) {
unsigned long V_282 = V_120 ;
if ( ! V_543 -> V_559 ) {
F_194 ( & V_542 -> V_558 , & V_543 -> V_551 ) ;
V_544 = true ;
break;
}
if ( F_125 ( V_282 + V_560 ,
V_543 -> V_561 +
F_196 ( V_543 -> V_539 ) ) ) {
int V_562 ;
F_197 ( V_542 ) ;
V_562 = V_542 -> V_539 -
F_45 ( V_543 -> V_561 +
F_196 (
V_543 -> V_539 ) -
V_282 ) ;
if ( V_562 > 0 ) {
F_198 ( & V_542 -> V_558 , & V_543 -> V_558 ) ;
} else {
F_194 ( & V_542 -> V_558 ,
& V_543 -> V_551 ) ;
}
V_544 = true ;
}
} else if ( F_199 ( & V_543 -> V_549 . V_563 ) ) {
unsigned long V_564 ;
F_194 ( & V_542 -> V_558 , & V_543 -> V_551 ) ;
V_544 = true ;
V_564 = V_120 + F_196 ( V_542 -> V_539 ) ;
if ( F_200 ( V_564 , V_543 -> V_549 . V_563 . V_565 ) )
F_201 ( & V_543 -> V_549 . V_563 , V_564 ) ;
else
F_202 ( & V_543 -> V_549 . V_563 ) ;
F_197 ( V_542 ) ;
}
break;
}
V_556:
if ( ! V_544 )
F_194 ( & V_542 -> V_558 , & V_9 -> V_552 ) ;
if ( V_540 )
* V_56 = ( unsigned long ) V_540 ;
else
* V_56 = ( unsigned long ) V_542 ;
return 0 ;
}
static int F_203 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_223 * V_224 ,
enum V_225 V_226 ,
unsigned int V_539 ,
T_4 * V_56 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
int V_19 ;
F_20 ( & V_9 -> V_510 ) ;
V_19 = F_188 ( V_9 , V_12 , V_224 , V_226 ,
V_539 , V_56 , NULL ) ;
F_26 ( & V_9 -> V_510 ) ;
return V_19 ;
}
static int F_204 ( struct V_8 * V_9 ,
T_4 V_56 , bool V_566 )
{
struct V_541 * V_542 , * V_543 , * V_567 = NULL ;
int V_19 ;
F_20 ( & V_9 -> V_510 ) ;
F_205 (roc, tmp, &local->roc_list, list) {
struct V_541 * V_568 , * V_569 ;
F_205 (dep, tmp2, &roc->dependents, list) {
if ( ! V_566 && ( unsigned long ) V_568 != V_56 )
continue;
else if ( V_566 && V_568 -> V_548 != V_56 )
continue;
F_206 ( & V_568 -> V_558 ) ;
F_26 ( & V_9 -> V_510 ) ;
F_207 ( V_568 ) ;
return 0 ;
}
if ( ! V_566 && ( unsigned long ) V_542 != V_56 )
continue;
else if ( V_566 && V_542 -> V_548 != V_56 )
continue;
V_567 = V_542 ;
break;
}
if ( ! V_567 ) {
F_26 ( & V_9 -> V_510 ) ;
return - V_50 ;
}
if ( V_9 -> V_137 -> V_555 ) {
if ( V_567 -> V_557 ) {
V_19 = F_208 ( V_9 ) ;
if ( F_209 ( V_19 ) ) {
F_26 ( & V_9 -> V_510 ) ;
return V_19 ;
}
}
F_206 ( & V_567 -> V_558 ) ;
if ( V_567 -> V_557 )
F_210 ( V_9 ) ;
F_26 ( & V_9 -> V_510 ) ;
F_207 ( V_567 ) ;
} else {
V_567 -> abort = true ;
F_192 ( & V_9 -> V_80 , & V_567 -> V_549 , 0 ) ;
F_26 ( & V_9 -> V_510 ) ;
F_211 ( & V_567 -> V_549 ) ;
}
return 0 ;
}
static int F_212 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_56 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
return F_204 ( V_9 , V_56 , false ) ;
}
static int F_213 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_223 * V_224 , bool V_570 ,
enum V_225 V_226 ,
bool V_571 , unsigned int V_572 ,
const T_3 * V_573 , T_5 V_273 , bool V_574 ,
bool V_575 , T_4 * V_56 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_233 * V_270 ;
struct V_34 * V_23 ;
const struct V_576 * V_577 = ( void * ) V_573 ;
bool V_578 = false ;
T_1 V_5 ;
int V_19 ;
if ( V_575 )
V_5 = V_579 ;
else
V_5 = V_580 |
V_581 ;
if ( V_574 )
V_5 |= V_582 ;
switch ( V_12 -> V_26 . type ) {
case V_465 :
if ( ! V_12 -> V_26 . V_161 . V_583 )
V_578 = true ;
#ifdef F_48
case V_466 :
if ( F_21 ( & V_12 -> V_26 ) &&
! V_12 -> V_15 . V_302 . V_365 )
V_578 = true ;
#endif
case V_312 :
case V_20 :
case V_468 :
if ( V_12 -> V_26 . type != V_465 &&
! F_21 ( & V_12 -> V_26 ) &&
! F_214 ( V_12 -> V_316 -> V_246 ) )
V_578 = true ;
if ( ! F_215 ( V_577 -> V_584 ) ||
V_577 -> V_15 . V_585 . V_586 == V_587 )
break;
F_32 () ;
V_23 = F_22 ( V_12 , V_577 -> V_271 ) ;
F_36 () ;
if ( ! V_23 )
return - V_588 ;
break;
case V_24 :
case V_467 :
if ( ! V_12 -> V_15 . V_25 . V_513 )
V_578 = true ;
break;
default:
return - V_191 ;
}
F_20 ( & V_9 -> V_510 ) ;
if ( ! V_578 ) {
V_578 = V_224 != V_9 -> V_202 ;
if ( V_571 &&
V_226 != V_9 -> V_229 )
V_578 = true ;
}
if ( V_578 && ! V_570 ) {
V_19 = - V_28 ;
goto V_51;
}
V_270 = F_76 ( V_9 -> V_80 . V_589 + V_273 ) ;
if ( ! V_270 ) {
V_19 = - V_238 ;
goto V_51;
}
F_216 ( V_270 , V_9 -> V_80 . V_589 ) ;
memcpy ( F_77 ( V_270 , V_273 ) , V_573 , V_273 ) ;
F_217 ( V_270 ) -> V_5 = V_5 ;
V_270 -> V_18 = V_12 -> V_18 ;
if ( ! V_578 ) {
* V_56 = ( unsigned long ) V_270 ;
F_218 ( V_12 , V_270 ) ;
V_19 = 0 ;
goto V_51;
}
F_217 ( V_270 ) -> V_5 |= V_590 ;
if ( V_9 -> V_80 . V_5 & V_591 )
F_217 ( V_270 ) -> V_592 =
V_9 -> V_80 . V_593 ;
V_19 = F_188 ( V_9 , V_12 , V_224 , V_226 ,
V_572 , V_56 , V_270 ) ;
if ( V_19 )
F_219 ( V_270 ) ;
V_51:
F_26 ( & V_9 -> V_510 ) ;
return V_19 ;
}
static int F_220 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_56 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_204 ( V_9 , V_56 , true ) ;
}
static void F_221 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_594 , bool V_595 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( V_594 ) {
case V_596 | V_597 :
if ( V_12 -> V_26 . type == V_465 ) {
struct V_598 * V_599 = & V_12 -> V_15 . V_600 ;
if ( V_595 )
V_599 -> V_601 ++ ;
else
V_599 -> V_601 -- ;
}
break;
case V_596 | V_602 :
if ( V_595 )
V_9 -> V_603 ++ ;
else
V_9 -> V_603 -- ;
F_222 ( & V_9 -> V_80 , & V_9 -> V_604 ) ;
break;
default:
break;
}
}
static int F_223 ( struct V_2 * V_2 , T_1 V_605 , T_1 V_606 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_557 )
return - V_191 ;
return F_224 ( V_9 , V_605 , V_606 ) ;
}
static int F_225 ( struct V_2 * V_2 , T_1 * V_605 , T_1 * V_606 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_226 ( V_9 , V_605 , V_606 ) ;
}
static int F_227 ( struct V_2 * V_2 , T_1 V_63 , T_1 V_607 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_228 ( V_9 , V_63 , V_607 ) ;
}
static void F_229 ( struct V_2 * V_2 ,
T_1 * V_63 , T_1 * V_608 , T_1 * V_607 , T_1 * V_609 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_230 ( V_9 , V_63 , V_608 , V_607 , V_609 ) ;
}
static int F_231 ( struct V_2 * V_2 ,
struct V_17 * V_18 ,
struct V_610 * V_194 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! V_9 -> V_137 -> V_611 )
return - V_191 ;
F_232 ( V_9 , V_12 , V_194 ) ;
return 0 ;
}
static void F_233 ( struct V_233 * V_270 )
{
T_3 * V_612 = ( void * ) F_77 ( V_270 , 7 ) ;
* V_612 ++ = V_613 ;
* V_612 ++ = 5 ;
* V_612 ++ = 0x0 ;
* V_612 ++ = 0x0 ;
* V_612 ++ = 0x0 ;
* V_612 ++ = 0x0 ;
* V_612 ++ = V_614 ;
}
static T_2 F_234 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_615 ;
V_615 = 0 ;
if ( V_9 -> V_202 -> V_83 != V_616 )
return V_615 ;
if ( ! ( V_9 -> V_80 . V_5 & V_617 ) )
V_615 |= V_618 ;
if ( ! ( V_9 -> V_80 . V_5 & V_619 ) )
V_615 |= V_620 ;
return V_615 ;
}
static void F_235 ( struct V_233 * V_270 , T_3 * V_621 ,
T_3 * V_622 , T_3 * V_199 )
{
struct V_623 * V_624 ;
V_624 = ( void * ) F_77 ( V_270 , sizeof( struct V_623 ) ) ;
V_624 -> V_625 = V_626 ;
V_624 -> V_364 = sizeof( struct V_623 ) - 2 ;
memcpy ( V_624 -> V_199 , V_199 , V_220 ) ;
memcpy ( V_624 -> V_627 , V_621 , V_220 ) ;
memcpy ( V_624 -> V_628 , V_622 , V_220 ) ;
}
static int
F_236 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_622 , T_3 V_629 , T_3 V_630 ,
T_2 V_631 , struct V_233 * V_270 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_632 * V_633 ;
V_633 = ( void * ) F_77 ( V_270 , F_237 ( struct V_632 , V_15 ) ) ;
memcpy ( V_633 -> V_271 , V_622 , V_220 ) ;
memcpy ( V_633 -> V_272 , V_12 -> V_26 . V_219 , V_220 ) ;
V_633 -> V_634 = F_238 ( V_635 ) ;
V_633 -> V_636 = V_637 ;
switch ( V_629 ) {
case V_638 :
V_633 -> V_586 = V_639 ;
V_633 -> V_629 = V_638 ;
F_77 ( V_270 , sizeof( V_633 -> V_15 . V_640 ) ) ;
V_633 -> V_15 . V_640 . V_630 = V_630 ;
V_633 -> V_15 . V_640 . V_641 =
F_239 ( F_234 ( V_12 ) ) ;
F_240 ( V_12 , V_270 , false ) ;
F_241 ( V_12 , V_270 , false ) ;
F_233 ( V_270 ) ;
break;
case V_642 :
V_633 -> V_586 = V_639 ;
V_633 -> V_629 = V_642 ;
F_77 ( V_270 , sizeof( V_633 -> V_15 . V_643 ) ) ;
V_633 -> V_15 . V_643 . V_631 = F_239 ( V_631 ) ;
V_633 -> V_15 . V_643 . V_630 = V_630 ;
V_633 -> V_15 . V_643 . V_641 =
F_239 ( F_234 ( V_12 ) ) ;
F_240 ( V_12 , V_270 , false ) ;
F_241 ( V_12 , V_270 , false ) ;
F_233 ( V_270 ) ;
break;
case V_644 :
V_633 -> V_586 = V_639 ;
V_633 -> V_629 = V_644 ;
F_77 ( V_270 , sizeof( V_633 -> V_15 . V_645 ) ) ;
V_633 -> V_15 . V_645 . V_631 = F_239 ( V_631 ) ;
V_633 -> V_15 . V_645 . V_630 = V_630 ;
break;
case V_646 :
V_633 -> V_586 = V_639 ;
V_633 -> V_629 = V_646 ;
F_77 ( V_270 , sizeof( V_633 -> V_15 . V_647 ) ) ;
V_633 -> V_15 . V_647 . V_648 = F_239 ( V_631 ) ;
break;
case V_649 :
V_633 -> V_586 = V_639 ;
V_633 -> V_629 = V_649 ;
F_77 ( V_270 , sizeof( V_633 -> V_15 . V_650 ) ) ;
V_633 -> V_15 . V_650 . V_630 = V_630 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int
F_242 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_622 , T_3 V_629 , T_3 V_630 ,
T_2 V_631 , struct V_233 * V_270 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_576 * V_577 ;
V_577 = ( void * ) F_77 ( V_270 , 24 ) ;
memset ( V_577 , 0 , 24 ) ;
memcpy ( V_577 -> V_271 , V_622 , V_220 ) ;
memcpy ( V_577 -> V_272 , V_12 -> V_26 . V_219 , V_220 ) ;
memcpy ( V_577 -> V_199 , V_12 -> V_15 . V_25 . V_199 , V_220 ) ;
V_577 -> V_584 = F_239 ( V_596 |
V_651 ) ;
switch ( V_629 ) {
case V_652 :
F_77 ( V_270 , 1 + sizeof( V_577 -> V_15 . V_585 . V_15 . V_653 ) ) ;
V_577 -> V_15 . V_585 . V_586 = V_587 ;
V_577 -> V_15 . V_585 . V_15 . V_653 . V_629 =
V_652 ;
V_577 -> V_15 . V_585 . V_15 . V_653 . V_630 =
V_630 ;
V_577 -> V_15 . V_585 . V_15 . V_653 . V_641 =
F_239 ( F_234 ( V_12 ) ) ;
F_240 ( V_12 , V_270 , false ) ;
F_241 ( V_12 , V_270 , false ) ;
F_233 ( V_270 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_243 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_622 , T_3 V_629 , T_3 V_630 ,
T_2 V_631 , const T_3 * V_654 ,
T_5 V_655 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_656 * V_657 ;
struct V_233 * V_270 = NULL ;
bool V_658 ;
int V_19 ;
if ( ! ( V_2 -> V_5 & V_659 ) )
return - V_422 ;
if ( V_12 -> V_26 . type != V_24 ||
! V_12 -> V_15 . V_25 . V_513 )
return - V_43 ;
F_244 ( V_12 , L_2 ,
V_629 , V_622 ) ;
V_270 = F_76 ( V_9 -> V_80 . V_589 +
F_195 ( sizeof( struct V_576 ) ,
sizeof( struct V_632 ) ) +
50 +
7 +
V_655 +
sizeof( struct V_623 ) ) ;
if ( ! V_270 )
return - V_238 ;
V_657 = F_217 ( V_270 ) ;
F_216 ( V_270 , V_9 -> V_80 . V_589 ) ;
switch ( V_629 ) {
case V_638 :
case V_642 :
case V_644 :
case V_646 :
case V_649 :
V_19 = F_236 ( V_2 , V_18 , V_622 ,
V_629 , V_630 ,
V_631 , V_270 ) ;
V_658 = false ;
break;
case V_652 :
V_19 = F_242 ( V_2 , V_18 , V_622 , V_629 ,
V_630 , V_631 ,
V_270 ) ;
V_658 = true ;
break;
default:
V_19 = - V_422 ;
break;
}
if ( V_19 < 0 )
goto V_660;
if ( V_655 )
memcpy ( F_77 ( V_270 , V_655 ) , V_654 , V_655 ) ;
switch ( V_629 ) {
case V_638 :
case V_644 :
case V_646 :
case V_649 :
F_235 ( V_270 , V_12 -> V_26 . V_219 , V_622 ,
V_12 -> V_15 . V_25 . V_199 ) ;
break;
case V_642 :
case V_652 :
F_235 ( V_270 , V_622 , V_12 -> V_26 . V_219 ,
V_12 -> V_15 . V_25 . V_199 ) ;
break;
default:
V_19 = - V_422 ;
goto V_660;
}
if ( V_658 ) {
F_218 ( V_12 , V_270 ) ;
return 0 ;
}
switch ( V_629 ) {
case V_638 :
case V_642 :
F_245 ( V_270 , V_661 ) ;
V_270 -> V_662 = 2 ;
break;
default:
F_245 ( V_270 , V_663 ) ;
V_270 -> V_662 = 5 ;
break;
}
F_246 () ;
V_19 = F_247 ( V_270 , V_18 ) ;
F_248 () ;
return V_19 ;
V_660:
F_80 ( V_270 ) ;
return V_19 ;
}
static int F_249 ( struct V_2 * V_2 , struct V_17 * V_18 ,
T_3 * V_622 , enum V_664 V_665 )
{
struct V_34 * V_23 ;
struct V_11 * V_12 = F_9 ( V_18 ) ;
if ( ! ( V_2 -> V_5 & V_659 ) )
return - V_422 ;
if ( V_12 -> V_26 . type != V_24 )
return - V_43 ;
F_244 ( V_12 , L_3 , V_665 , V_622 ) ;
switch ( V_665 ) {
case V_666 :
F_32 () ;
V_23 = F_22 ( V_12 , V_622 ) ;
if ( ! V_23 ) {
F_36 () ;
return - V_588 ;
}
F_97 ( V_23 , V_667 ) ;
F_36 () ;
break;
case V_668 :
return F_250 ( V_12 , V_622 ) ;
case V_669 :
case V_670 :
case V_671 :
return - V_422 ;
default:
return - V_422 ;
}
return 0 ;
}
static int F_251 ( struct V_2 * V_2 , struct V_17 * V_18 ,
const T_3 * V_622 , T_4 * V_56 )
{
struct V_11 * V_12 = F_9 ( V_18 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_672 * V_673 ;
struct V_233 * V_270 ;
int V_243 = sizeof( * V_673 ) ;
T_7 V_674 ;
bool V_675 ;
struct V_656 * V_657 ;
struct V_34 * V_23 ;
F_32 () ;
V_23 = F_22 ( V_12 , V_622 ) ;
if ( V_23 ) {
V_675 = F_50 ( V_23 , V_183 ) ;
F_36 () ;
} else {
F_36 () ;
return - V_588 ;
}
if ( V_675 ) {
V_674 = F_239 ( V_676 |
V_677 |
V_678 ) ;
} else {
V_243 -= 2 ;
V_674 = F_239 ( V_676 |
V_679 |
V_678 ) ;
}
V_270 = F_76 ( V_9 -> V_80 . V_589 + V_243 ) ;
if ( ! V_270 )
return - V_238 ;
V_270 -> V_18 = V_18 ;
F_216 ( V_270 , V_9 -> V_80 . V_589 ) ;
V_673 = ( void * ) F_77 ( V_270 , V_243 ) ;
V_673 -> V_584 = V_674 ;
V_673 -> V_680 = 0 ;
memcpy ( V_673 -> V_681 , V_23 -> V_23 . V_219 , V_220 ) ;
memcpy ( V_673 -> V_682 , V_12 -> V_26 . V_219 , V_220 ) ;
memcpy ( V_673 -> V_683 , V_12 -> V_26 . V_219 , V_220 ) ;
V_673 -> V_684 = 0 ;
V_657 = F_217 ( V_270 ) ;
V_657 -> V_5 |= V_581 |
V_580 ;
F_245 ( V_270 , V_685 ) ;
V_270 -> V_662 = 7 ;
if ( V_675 )
V_673 -> V_686 = F_239 ( 7 ) ;
F_246 () ;
F_252 ( V_12 , V_270 ) ;
F_248 () ;
* V_56 = ( unsigned long ) V_270 ;
return 0 ;
}
static struct V_223 *
F_253 ( struct V_2 * V_2 , struct V_1 * V_10 ,
enum V_225 * type )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* type = V_9 -> V_229 ;
return V_9 -> V_202 ;
}
static void F_254 ( struct V_2 * V_2 , bool V_519 )
{
F_255 ( F_2 ( V_2 ) , V_519 ) ;
}
