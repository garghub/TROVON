static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * V_5 )
{
if ( V_4 -> V_6 ) {
struct V_7 * V_8 ;
V_8 = V_4 -> V_6 ;
* V_5 = V_8 -> V_9 ;
return 1 ;
}
return 0 ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_5 )
{
void * V_10 = V_2 -> V_11 ;
F_3 ( V_5 , V_10 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_5 )
{
F_2 ( V_2 , V_5 ) ;
}
void F_5 ( struct V_1 * V_2 , unsigned int V_5 )
{
void * V_10 = V_2 -> V_11 ;
F_6 ( V_5 , V_10 ) ;
}
inline int F_7 ( struct V_1 * V_2 , T_1 * V_12 )
{
unsigned int V_13 , V_5 ;
void * V_10 = V_2 -> V_11 ;
V_13 = F_8 ( V_10 , V_2 -> V_14 ) ;
V_5 = V_13 ;
if ( V_5 >= V_2 -> V_14 )
return - V_15 ;
F_5 ( V_2 , V_5 ) ;
* V_12 = V_5 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_14 ; ++ V_16 )
F_2 ( V_2 , V_16 ) ;
}
struct V_1 * F_10 ( struct V_17 * V_18 )
{
unsigned long V_16 = 0 , V_19 = 0 , V_20 = 0 ;
struct V_21 * V_22 = V_18 -> V_23 -> V_24 ;
struct V_1 * V_2 = NULL ;
struct V_25 * V_26 ;
while ( V_22 -> V_27 [ V_16 ] ) {
if ( V_22 -> V_27 [ V_16 ] == V_18 -> V_23 ) {
V_26 = F_11 ( V_22 -> V_27 [ V_16 ] -> V_28 . V_29 ,
struct V_25 , V_30 ) ;
V_19 = 0 ;
while ( V_22 -> V_31 [ V_19 ] ) {
if ( V_22 -> V_31 [ V_19 ] == V_26 )
break;
V_19 ++ ;
}
break;
}
V_16 ++ ;
}
V_20 = V_19 / ( (struct V_32 * ) V_22 -> V_33 ) -> V_34 ;
V_2 = ( (struct V_32 * ) V_22 -> V_33 ) -> V_2 [ V_20 ] ;
return V_2 ;
}
int F_12 ( struct V_17 * V_18 , int * V_35 )
{
unsigned long V_16 = 0 , V_19 = 0 , V_36 = 0 , V_37 = 0 ;
struct V_38 * V_39 = (struct V_38 * ) V_18 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_41 ;
struct V_21 * V_22 = V_18 -> V_23 -> V_24 ;
while ( V_22 -> V_27 [ V_16 ] ) {
if ( V_22 -> V_27 [ V_16 ] == V_18 -> V_23 ) {
struct V_25 * V_26 ;
F_13 (phy,
&sha->sas_port[i]->phy_list, port_phy_el) {
V_19 = 0 ;
while ( V_22 -> V_31 [ V_19 ] ) {
if ( V_22 -> V_31 [ V_19 ] == V_26 )
break;
V_19 ++ ;
}
V_35 [ V_36 ] = ( V_19 >= V_2 -> V_42 -> V_34 ) ?
( V_19 - V_2 -> V_42 -> V_34 ) : V_19 ;
V_37 ++ ;
V_36 ++ ;
}
break;
}
V_16 ++ ;
}
return V_37 ;
}
struct V_38 * F_14 ( struct V_1 * V_2 ,
T_2 V_43 )
{
T_1 V_44 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
if ( V_2 -> V_46 [ V_44 ] . V_47 == V_48 )
continue;
if ( V_2 -> V_46 [ V_44 ] . V_47 == V_43 )
return & V_2 -> V_46 [ V_44 ] ;
}
return NULL ;
}
static inline void F_15 ( struct V_1 * V_2 ,
struct V_38 * V_18 )
{
if ( ! V_18 ) {
F_16 ( L_1 ) ;
return;
}
if ( V_18 -> V_47 == V_48 )
return;
V_49 -> V_50 ( V_2 , & V_18 -> V_47 ) ;
}
static inline T_2 F_17 ( struct V_1 * V_2 ,
struct V_38 * V_18 )
{
if ( V_18 -> V_47 != V_48 )
return 0 ;
return V_49 -> V_51 ( V_2 , & V_18 -> V_47 ) ;
}
void F_18 ( struct V_1 * V_2 , T_1 V_52 , int V_53 )
{
T_1 V_54 ;
F_19 (phy_mask, phy_mask, no) {
if ( ! ( V_52 & 1 ) )
continue;
V_49 -> V_55 ( V_2 , V_54 , V_53 ) ;
}
}
int F_20 ( struct V_25 * V_31 , enum V_56 V_57 ,
void * V_58 )
{
int V_59 = 0 , V_60 = V_31 -> V_61 ;
T_1 V_62 , V_16 = 0 , V_20 ;
struct V_21 * V_22 = V_31 -> V_24 ;
struct V_1 * V_2 = NULL ;
while ( V_22 -> V_31 [ V_16 ] ) {
if ( V_22 -> V_31 [ V_16 ] == V_31 )
break;
V_16 ++ ;
}
V_20 = V_16 / ( (struct V_32 * ) V_22 -> V_33 ) -> V_34 ;
V_2 = ( (struct V_32 * ) V_22 -> V_33 ) -> V_2 [ V_20 ] ;
switch ( V_57 ) {
case V_63 :
V_49 -> V_64 ( V_2 , V_60 , V_58 ) ;
break;
case V_65 :
V_62 = V_49 -> V_66 ( V_2 , V_60 ) ;
if ( V_62 & V_67 )
break;
V_49 -> V_55 ( V_2 , V_60 , V_68 ) ;
break;
case V_69 :
V_49 -> V_70 ( V_2 , V_60 ) ;
V_49 -> V_55 ( V_2 , V_60 , V_71 ) ;
break;
case V_72 :
V_49 -> V_73 ( V_2 , V_60 ) ;
break;
case V_74 :
default:
V_59 = - V_75 ;
}
F_21 ( 200 ) ;
return V_59 ;
}
void F_22 ( struct V_1 * V_2 , int V_76 , T_1 V_77 ,
T_1 V_78 , T_3 V_79 )
{
T_1 V_80 = ( T_1 ) V_79 ;
T_1 V_20 = ( T_1 ) ( V_79 >> 32 ) ;
V_49 -> V_81 ( V_2 , V_76 , V_77 ) ;
V_49 -> V_82 ( V_2 , V_76 , V_80 ) ;
V_49 -> V_81 ( V_2 , V_76 , V_78 ) ;
V_49 -> V_82 ( V_2 , V_76 , V_20 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_16 )
{
struct V_83 * V_26 = & V_2 -> V_26 [ V_16 ] ;
struct V_25 * V_31 = & V_26 -> V_31 ;
struct V_21 * V_84 ;
if ( ! V_26 -> V_85 )
return;
if ( ! ( V_26 -> V_86 & V_87 )
&& V_26 -> V_88 & V_89 ) {
return;
}
V_84 = V_2 -> V_90 ;
V_84 -> V_91 ( V_31 , V_92 ) ;
if ( V_31 -> V_26 ) {
struct V_31 * V_93 = V_31 -> V_26 ;
V_93 -> V_94 = V_31 -> V_95 ;
V_93 -> V_96 = V_26 -> V_96 ;
V_93 -> V_97 = V_98 ;
V_93 -> V_99 = V_26 -> V_99 ;
V_93 -> V_100 = V_49 -> V_101 () ;
}
if ( V_26 -> V_88 & V_89 ) {
struct V_102 * V_61 ;
V_61 = (struct V_102 * ) V_26 -> V_103 ;
V_61 -> V_104 = V_26 -> V_105 . V_106 ;
V_61 -> V_107 = V_108 ;
V_61 -> V_109 = V_26 -> V_105 . V_110 ;
if ( V_26 -> V_86 & V_111 ) {
V_49 -> V_81 ( V_2 , V_16 , V_112 ) ;
V_49 -> V_82 ( V_2 , V_16 , 0x00 ) ;
}
} else if ( V_26 -> V_88 & V_113 ) {
}
F_24 ( L_2 , V_16 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ) ;
V_31 -> V_114 = V_26 -> V_114 ;
V_2 -> V_90 -> V_115 ( V_31 ,
V_116 ) ;
}
void F_25 ( struct V_117 * V_118 )
{
int V_16 , V_19 ;
unsigned short V_119 ;
struct V_1 * V_2 ;
struct V_21 * V_22 = F_26 ( V_118 ) ;
struct V_32 * V_120 = V_22 -> V_33 ;
V_119 = ( (struct V_32 * ) V_22 -> V_33 ) -> V_121 ;
for ( V_19 = 0 ; V_19 < V_119 ; V_19 ++ ) {
V_2 = ( (struct V_32 * ) V_22 -> V_33 ) -> V_2 [ V_19 ] ;
for ( V_16 = 0 ; V_16 < V_2 -> V_42 -> V_34 ; ++ V_16 )
F_23 ( V_2 , V_16 ) ;
}
V_120 -> V_122 = 1 ;
}
int F_27 ( struct V_117 * V_118 , unsigned long time )
{
struct V_21 * V_22 = F_26 ( V_118 ) ;
struct V_32 * V_120 = V_22 -> V_33 ;
if ( V_120 -> V_122 == 0 )
return 0 ;
F_28 ( V_22 ) ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
int V_125 , V_59 , V_16 ;
struct V_21 * V_22 = V_2 -> V_90 ;
struct V_3 * V_4 = V_124 -> V_4 ;
struct V_126 * V_127 = V_124 -> V_127 ;
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_128 * V_27 = V_18 -> V_23 ;
struct V_31 * V_93 = V_18 -> V_26 ;
struct V_25 * V_31 = V_22 -> V_31 [ V_93 -> V_129 ] ;
struct V_130 * V_131 , * V_132 ;
T_1 V_133 , V_134 , V_5 = V_124 -> V_5 ;
void * V_135 ;
T_2 * V_136 ;
T_4 V_137 ;
void * V_138 ;
struct V_7 * V_8 = & V_2 -> V_139 [ V_5 ] ;
T_1 V_140 = ( V_124 -> V_141 << V_142 ) ;
V_131 = & V_4 -> V_143 . V_144 ;
V_125 = F_30 ( V_2 -> V_18 , V_131 , 1 , V_145 ) ;
if ( ! V_125 )
return - V_146 ;
V_133 = F_31 ( V_131 ) ;
V_132 = & V_4 -> V_143 . V_147 ;
V_125 = F_30 ( V_2 -> V_18 , V_132 , 1 , V_148 ) ;
if ( ! V_125 ) {
V_59 = - V_146 ;
goto V_149;
}
V_134 = V_150 ;
if ( ( V_133 & 0x3 ) || ( V_134 & 0x3 ) ) {
V_59 = - V_151 ;
goto V_152;
}
V_135 = V_8 -> V_153 ;
V_137 = V_8 -> V_154 ;
V_127 -> V_155 = F_32 ( F_33 ( V_131 ) ) ;
V_136 = V_135 ;
V_127 -> V_156 = F_32 ( V_137 ) ;
V_135 += V_157 ;
V_137 += V_157 ;
V_138 = V_135 ;
if ( V_124 -> V_141 )
V_127 -> V_158 = F_32 ( V_137 ) ;
else
V_127 -> V_158 = 0 ;
V_16 = V_49 -> V_159 () * V_124 -> V_141 ;
V_135 += V_16 ;
V_137 += V_16 ;
V_8 -> V_160 = V_135 ;
V_127 -> V_161 = F_32 ( V_137 ) ;
if ( V_2 -> V_140 & V_162 )
V_127 -> V_163 [ 0 ] = 0 ;
V_8 -> V_164 = V_2 -> V_165 ;
V_2 -> V_164 [ V_2 -> V_165 ] = F_34 ( ( V_166 << V_167 ) |
V_168 | V_5 |
( V_169 << V_170 ) ) ;
V_127 -> V_140 |= V_140 ;
V_127 -> V_171 = F_34 ( ( ( V_134 / 4 ) << 16 ) | ( ( V_133 - 4 ) / 4 ) ) ;
V_127 -> V_11 = F_34 ( V_5 ) ;
V_127 -> V_172 = 0 ;
V_136 [ 0 ] = ( 1 << 7 ) | ( V_173 << 4 ) | 0x01 ;
V_136 [ 1 ] = F_35 ( V_27 -> V_95 , V_18 -> V_95 ) & 0xf ;
* ( V_174 * ) ( V_136 + 2 ) = 0xFFFF ;
memcpy ( V_136 + 4 , V_18 -> V_79 , V_175 ) ;
V_49 -> V_176 ( V_4 -> V_177 , V_124 -> V_141 , V_138 ) ;
return 0 ;
V_152:
F_36 ( V_2 -> V_18 , & V_124 -> V_4 -> V_143 . V_147 , 1 ,
V_148 ) ;
V_149:
F_36 ( V_2 -> V_18 , & V_124 -> V_4 -> V_143 . V_144 , 1 ,
V_145 ) ;
return V_59 ;
}
static T_1 F_37 ( struct V_3 * V_4 , T_1 * V_5 )
{
struct V_178 * V_179 = V_4 -> V_180 ;
if ( V_179 ) {
if ( V_179 -> V_181 . V_182 == V_183 ||
V_179 -> V_181 . V_182 == V_184 ) {
* V_5 = V_179 -> V_5 ;
return 1 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
struct V_3 * V_4 = V_124 -> V_4 ;
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_38 * V_39 = V_18 -> V_40 ;
struct V_126 * V_127 = V_124 -> V_127 ;
struct V_128 * V_27 = V_18 -> V_23 ;
struct V_7 * V_8 ;
void * V_138 ;
T_1 V_5 = V_124 -> V_5 , V_185 ;
T_1 V_140 , V_186 ;
void * V_135 ;
T_2 * V_187 , * V_136 ;
T_4 V_137 ;
T_1 V_16 , V_133 , V_134 ;
const T_1 V_188 = V_150 ;
if ( F_17 ( V_2 , V_39 ) == V_48 ) {
F_24 ( L_3 ,
V_39 -> V_189 ) ;
return - V_190 ;
}
V_8 = & V_2 -> V_139 [ V_5 ] ;
V_8 -> V_164 = V_2 -> V_165 ;
V_186 = V_168 | V_5 |
( V_191 << V_167 ) |
( ( V_27 -> V_52 & V_192 ) << V_170 ) |
( V_39 -> V_47 << V_193 ) ;
V_2 -> V_164 [ V_2 -> V_165 ] = F_34 ( V_186 ) ;
if ( V_4 -> V_194 == V_195 )
V_140 = ( V_49 -> V_196 () << V_142 ) ;
else
V_140 = ( V_124 -> V_141 << V_142 ) ;
if ( V_4 -> V_197 . V_198 )
V_140 |= V_199 ;
if ( V_18 -> V_200 . V_201 == V_202 ) {
if ( V_4 -> V_197 . V_203 . V_182 != V_204 )
V_140 |= V_205 ;
}
V_127 -> V_140 = F_34 ( V_140 ) ;
if ( V_4 -> V_197 . V_198 && F_37 ( V_4 , & V_185 ) )
V_4 -> V_197 . V_203 . V_206 |= ( T_2 ) ( V_185 << 3 ) ;
else
V_185 = V_5 ;
V_127 -> V_11 = F_34 ( V_185 ) ;
V_127 -> V_172 = F_34 ( V_4 -> V_207 ) ;
V_187 = V_135 = V_8 -> V_153 ;
V_137 = V_8 -> V_154 ;
V_127 -> V_155 = F_32 ( V_137 ) ;
V_135 += V_208 ;
V_137 += V_208 ;
V_136 = V_135 ;
V_127 -> V_156 = F_32 ( V_137 ) ;
V_135 += V_157 ;
V_137 += V_157 ;
V_138 = V_135 ;
if ( V_124 -> V_141 )
V_127 -> V_158 = F_32 ( V_137 ) ;
else
V_127 -> V_158 = 0 ;
V_16 = V_49 -> V_159 () * V_49 -> V_196 () ;
V_135 += V_16 ;
V_137 += V_16 ;
V_8 -> V_160 = V_135 ;
V_127 -> V_161 = F_32 ( V_137 ) ;
if ( V_2 -> V_140 & V_162 )
V_127 -> V_163 [ 0 ] = 0 ;
V_133 = sizeof( struct V_209 ) ;
V_134 = V_210 - V_208 -
sizeof( struct V_211 ) - V_16 ;
V_134 = F_35 ( V_134 , V_188 ) ;
V_127 -> V_171 = F_34 ( ( ( V_134 / 4 ) << 16 ) | ( V_133 / 4 ) ) ;
if ( F_39 ( ! V_4 -> V_197 . V_212 ) )
V_4 -> V_197 . V_203 . V_140 |= 0x80 ;
memcpy ( V_187 , & V_4 -> V_197 . V_203 , sizeof( struct V_209 ) ) ;
if ( V_18 -> V_200 . V_201 == V_202 )
memcpy ( V_187 + V_213 ,
V_4 -> V_197 . V_214 , 16 ) ;
V_136 [ 0 ] = ( 1 << 7 ) | ( V_215 << 4 ) | 0x1 ;
V_136 [ 1 ] = F_35 ( V_27 -> V_95 , V_18 -> V_95 ) & 0xf ;
* ( V_174 * ) ( V_136 + 2 ) = F_40 ( V_39 -> V_189 + 1 ) ;
memcpy ( V_136 + 4 , V_18 -> V_79 , V_175 ) ;
V_49 -> V_176 ( V_4 -> V_177 , V_124 -> V_141 , V_138 ) ;
if ( V_4 -> V_194 == V_195 )
V_49 -> V_216 ( V_2 , V_27 -> V_52 ,
V_217 , V_124 -> V_141 , V_138 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_123 * V_124 , int V_218 ,
struct V_219 * V_220 )
{
struct V_3 * V_4 = V_124 -> V_4 ;
struct V_126 * V_127 = V_124 -> V_127 ;
struct V_221 * V_23 = V_124 -> V_23 ;
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_38 * V_39 = V_18 -> V_40 ;
struct V_128 * V_27 = V_18 -> V_23 ;
struct V_7 * V_8 ;
void * V_138 ;
struct V_222 * V_223 ;
void * V_135 ;
T_2 * V_187 , * V_136 , V_224 = 0 ;
T_4 V_137 ;
T_1 V_140 ;
T_1 V_134 , V_133 , V_16 , V_5 = V_124 -> V_5 ;
const T_1 V_188 = V_150 ;
T_1 V_52 ;
V_8 = & V_2 -> V_139 [ V_5 ] ;
V_52 = ( ( V_23 -> V_225 ) ? V_23 -> V_225 :
V_27 -> V_52 ) & V_192 ;
V_8 -> V_164 = V_2 -> V_165 ;
V_2 -> V_164 [ V_2 -> V_165 ] = F_34 ( V_168 | V_5 |
( V_226 << V_167 ) |
( V_52 << V_170 ) ) ;
V_140 = V_227 ;
if ( V_4 -> V_228 . V_229 ) {
V_140 |= V_230 ;
V_224 = ( 1 << 7 ) ;
}
if ( V_218 )
V_140 |= ( V_231 << V_232 ) ;
else
V_140 |= ( V_233 << V_232 ) ;
V_127 -> V_140 = F_34 ( V_140 | ( V_124 -> V_141 << V_142 ) ) ;
V_127 -> V_11 = F_34 ( V_5 ) ;
V_127 -> V_172 = F_34 ( V_4 -> V_207 ) ;
V_187 = V_135 = V_8 -> V_153 ;
V_137 = V_8 -> V_154 ;
V_127 -> V_155 = F_32 ( V_137 ) ;
V_135 += V_234 ;
V_137 += V_234 ;
V_136 = V_135 ;
V_127 -> V_156 = F_32 ( V_137 ) ;
V_135 += V_157 ;
V_137 += V_157 ;
V_138 = V_135 ;
if ( V_124 -> V_141 )
V_127 -> V_158 = F_32 ( V_137 ) ;
else
V_127 -> V_158 = 0 ;
V_16 = V_49 -> V_159 () * V_124 -> V_141 ;
V_135 += V_16 ;
V_137 += V_16 ;
V_8 -> V_160 = V_135 ;
V_127 -> V_161 = F_32 ( V_137 ) ;
if ( V_2 -> V_140 & V_162 )
V_127 -> V_163 [ 0 ] = 0 ;
V_134 = V_210 - V_234 - V_157 -
sizeof( struct V_211 ) - V_16 ;
V_134 = F_35 ( V_134 , V_188 ) ;
V_133 = sizeof( struct V_222 ) + 28 ;
V_127 -> V_171 = F_34 ( ( ( V_134 / 4 ) << 16 ) | ( V_133 / 4 ) ) ;
V_136 [ 0 ] = ( 1 << 7 ) | ( V_235 << 4 ) | 0x1 ;
V_136 [ 1 ] = F_35 ( V_27 -> V_95 , V_18 -> V_95 ) & 0xf ;
* ( V_174 * ) ( V_136 + 2 ) = F_40 ( V_39 -> V_189 + 1 ) ;
memcpy ( V_136 + 4 , V_18 -> V_79 , V_175 ) ;
V_223 = (struct V_222 * ) V_187 ;
if ( V_218 )
V_223 -> V_236 = V_237 ;
else
V_223 -> V_236 = V_238 ;
memcpy ( V_223 -> V_239 , V_18 -> V_240 ,
V_241 ) ;
memcpy ( V_223 -> V_242 ,
V_18 -> V_240 , V_241 ) ;
V_223 -> V_5 = F_40 ( V_5 ) ;
V_187 += sizeof( * V_223 ) ;
memcpy ( V_187 , & V_4 -> V_228 . V_243 , 8 ) ;
if ( V_223 -> V_236 != V_237 ) {
V_187 [ 9 ] = V_224 | V_4 -> V_228 . V_244 |
( V_4 -> V_228 . V_245 << 3 ) ;
memcpy ( V_187 + 12 , V_4 -> V_228 . V_246 -> V_247 ,
V_4 -> V_228 . V_246 -> V_248 ) ;
} else{
V_187 [ 10 ] = V_220 -> V_220 ;
switch ( V_220 -> V_220 ) {
case V_249 :
case V_250 :
V_187 [ 12 ] =
( V_220 -> V_251 >> 8 ) & 0xff ;
V_187 [ 13 ] =
V_220 -> V_251 & 0xff ;
break;
default:
break;
}
}
V_49 -> V_176 ( V_4 -> V_177 , V_124 -> V_141 , V_138 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , struct V_1 * V_2 , int V_218 ,
struct V_219 * V_220 , int * V_252 )
{
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_38 * V_39 = V_18 -> V_40 ;
struct V_123 V_124 ;
struct V_7 * V_8 ;
T_1 V_5 = 0xdeadbeef , V_141 = 0 ;
int V_59 = 0 ;
if ( ! V_18 -> V_23 ) {
struct V_253 * V_254 = & V_4 -> V_255 ;
V_254 -> V_256 = V_257 ;
V_254 -> V_258 = V_259 ;
if ( V_18 -> V_104 != V_260 )
V_4 -> V_261 ( V_4 ) ;
return V_59 ;
}
if ( F_43 ( V_39 ) ) {
if ( V_39 )
F_24 ( L_4 ,
V_39 -> V_189 ) ;
else
F_24 ( L_5 ,
F_44 ( V_18 -> V_79 ) ) ;
V_59 = V_259 ;
return V_59 ;
}
V_124 . V_23 = V_18 -> V_23 -> V_262 ;
if ( V_124 . V_23 && ! V_124 . V_23 -> V_263 && ! V_220 ) {
if ( F_45 ( V_4 -> V_264 ) ) {
struct V_253 * V_265 = & V_4 -> V_255 ;
F_24 ( L_6
L_7 , V_18 -> V_23 -> V_61 ) ;
V_265 -> V_256 = V_266 ;
V_265 -> V_258 = V_259 ;
V_4 -> V_261 ( V_4 ) ;
} else {
struct V_253 * V_265 = & V_4 -> V_255 ;
F_24 ( L_8
L_7 , V_18 -> V_23 -> V_61 ) ;
V_265 -> V_256 = V_257 ;
V_265 -> V_258 = V_259 ;
V_4 -> V_261 ( V_4 ) ;
}
return V_59 ;
}
if ( ! F_45 ( V_4 -> V_264 ) ) {
if ( V_4 -> V_267 ) {
V_141 = F_30 ( V_2 -> V_18 ,
V_4 -> V_177 ,
V_4 -> V_267 ,
V_4 -> V_194 ) ;
if ( ! V_141 ) {
V_59 = - V_146 ;
goto V_268;
}
}
} else {
V_141 = V_4 -> V_267 ;
}
V_59 = F_7 ( V_2 , & V_5 ) ;
if ( V_59 )
goto V_149;
V_8 = & V_2 -> V_139 [ V_5 ] ;
V_4 -> V_6 = NULL ;
V_8 -> V_141 = V_141 ;
V_8 -> V_9 = V_5 ;
V_8 -> V_153 = F_46 ( V_2 -> V_269 , V_270 , & V_8 -> V_154 ) ;
if ( ! V_8 -> V_153 )
goto V_271;
memset ( V_8 -> V_153 , 0 , V_210 ) ;
V_124 . V_4 = V_4 ;
V_124 . V_127 = & V_2 -> V_8 [ V_5 ] ;
V_124 . V_5 = V_5 ;
V_124 . V_141 = V_141 ;
switch ( V_4 -> V_264 ) {
case V_272 :
V_59 = F_29 ( V_2 , & V_124 ) ;
break;
case V_273 :
V_59 = F_41 ( V_2 , & V_124 , V_218 , V_220 ) ;
break;
case V_274 :
case V_275 :
case V_274 | V_275 :
V_59 = F_38 ( V_2 , & V_124 ) ;
break;
default:
F_47 ( V_276 , V_2 -> V_18 ,
L_9 ,
V_4 -> V_264 ) ;
V_59 = - V_151 ;
break;
}
if ( V_59 ) {
F_24 ( L_10 , V_59 ) ;
goto V_277;
}
V_8 -> V_4 = V_4 ;
V_8 -> V_23 = V_124 . V_23 ;
V_4 -> V_6 = V_8 ;
F_48 ( & V_8 -> V_278 , & V_124 . V_23 -> V_279 ) ;
F_49 ( & V_4 -> V_280 ) ;
V_4 -> V_281 |= V_282 ;
F_50 ( & V_4 -> V_280 ) ;
V_39 -> V_283 ++ ;
++ ( * V_252 ) ;
V_2 -> V_165 = ( V_2 -> V_165 + 1 ) & ( V_284 - 1 ) ;
return V_59 ;
V_277:
F_51 ( V_2 -> V_269 , V_8 -> V_153 , V_8 -> V_154 ) ;
V_271:
F_4 ( V_2 , V_5 ) ;
V_149:
F_47 ( V_276 , V_2 -> V_18 , L_11 , V_59 ) ;
if ( ! F_45 ( V_4 -> V_264 ) )
if ( V_141 )
F_36 ( V_2 -> V_18 , V_4 -> V_177 , V_141 ,
V_4 -> V_194 ) ;
V_268:
return V_59 ;
}
static int F_52 ( struct V_3 * V_4 , T_5 V_285 ,
struct V_286 * V_286 , int V_218 ,
struct V_219 * V_220 )
{
struct V_1 * V_2 = NULL ;
T_1 V_59 = 0 ;
T_1 V_252 = 0 ;
unsigned long V_140 = 0 ;
V_2 = ( (struct V_38 * ) V_4 -> V_18 -> V_40 ) -> V_41 ;
F_53 ( & V_2 -> V_287 , V_140 ) ;
V_59 = F_42 ( V_4 , V_2 , V_218 , V_220 , & V_252 ) ;
if ( V_59 )
F_47 ( V_276 , V_2 -> V_18 , L_12 , V_59 ) ;
if ( F_39 ( V_252 ) )
V_49 -> V_288 ( V_2 , ( V_2 -> V_165 - 1 ) &
( V_284 - 1 ) ) ;
F_54 ( & V_2 -> V_287 , V_140 ) ;
return V_59 ;
}
int F_55 ( struct V_3 * V_4 , T_5 V_285 )
{
return F_52 ( V_4 , V_285 , NULL , 0 , NULL ) ;
}
static void F_56 ( struct V_1 * V_2 , T_1 V_289 )
{
T_1 V_290 = V_289 & V_291 ;
F_2 ( V_2 , V_290 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , T_1 V_290 )
{
if ( ! V_8 )
return;
if ( ! V_8 -> V_4 )
return;
if ( ! F_45 ( V_4 -> V_264 ) )
if ( V_8 -> V_141 )
F_36 ( V_2 -> V_18 , V_4 -> V_177 ,
V_8 -> V_141 , V_4 -> V_194 ) ;
switch ( V_4 -> V_264 ) {
case V_272 :
F_36 ( V_2 -> V_18 , & V_4 -> V_143 . V_147 , 1 ,
V_148 ) ;
F_36 ( V_2 -> V_18 , & V_4 -> V_143 . V_144 , 1 ,
V_145 ) ;
break;
case V_274 :
case V_275 :
case V_273 :
default:
break;
}
if ( V_8 -> V_153 ) {
F_51 ( V_2 -> V_269 , V_8 -> V_153 , V_8 -> V_154 ) ;
V_8 -> V_153 = NULL ;
}
F_58 ( & V_8 -> V_278 ) ;
V_4 -> V_6 = NULL ;
V_8 -> V_4 = NULL ;
V_8 -> V_23 = NULL ;
V_8 -> V_9 = 0xFFFFFFFF ;
F_56 ( V_2 , V_290 ) ;
}
static void F_59 ( struct V_1 * V_2 , int V_292 )
{
struct V_83 * V_26 = & V_2 -> V_26 [ V_292 ] ;
struct V_221 * V_23 = V_26 -> V_23 ;
int V_19 , V_54 ;
F_19 (port->wide_port_phymap, j, no) {
if ( V_19 & 1 ) {
V_49 -> V_81 ( V_2 , V_54 ,
V_293 ) ;
V_49 -> V_82 ( V_2 , V_54 ,
V_23 -> V_225 ) ;
} else {
V_49 -> V_81 ( V_2 , V_54 ,
V_293 ) ;
V_49 -> V_82 ( V_2 , V_54 ,
0 ) ;
}
}
}
static T_1 F_60 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_62 ;
struct V_83 * V_26 = & V_2 -> V_26 [ V_16 ] ;
struct V_221 * V_23 = V_26 -> V_23 ;
V_62 = V_49 -> V_66 ( V_2 , V_16 ) ;
if ( ( V_62 & V_294 ) && ! ( V_26 -> V_295 & V_296 ) ) {
if ( ! V_23 )
V_26 -> V_85 = 1 ;
return V_62 ;
}
if ( V_23 ) {
if ( V_26 -> V_88 & V_89 ) {
V_23 -> V_225 &= ~ ( 1U << V_16 ) ;
if ( ! V_23 -> V_225 )
V_23 -> V_263 = 0 ;
F_59 ( V_2 , V_16 ) ;
} else if ( V_26 -> V_88 & V_113 )
V_23 -> V_263 = 0 ;
V_26 -> V_23 = NULL ;
V_26 -> V_85 = 0 ;
V_26 -> V_88 &= ~ ( V_89 | V_113 ) ;
}
return 0 ;
}
static void * F_61 ( struct V_1 * V_2 , int V_16 , void * V_153 )
{
T_1 * V_297 = ( T_1 * ) V_153 ;
if ( ! V_297 )
return NULL ;
V_49 -> V_81 ( V_2 , V_16 , V_298 ) ;
V_297 [ 3 ] = F_34 ( V_49 -> V_299 ( V_2 , V_16 ) ) ;
V_49 -> V_81 ( V_2 , V_16 , V_300 ) ;
V_297 [ 2 ] = F_34 ( V_49 -> V_299 ( V_2 , V_16 ) ) ;
V_49 -> V_81 ( V_2 , V_16 , V_301 ) ;
V_297 [ 1 ] = F_34 ( V_49 -> V_299 ( V_2 , V_16 ) ) ;
V_49 -> V_81 ( V_2 , V_16 , V_302 ) ;
V_297 [ 0 ] = F_34 ( V_49 -> V_299 ( V_2 , V_16 ) ) ;
if ( ( ( V_297 [ 1 ] & 0x00FFFFFF ) == 0x00EB1401 ) && ( * ( T_2 * ) & V_297 [ 3 ] == 0x01 ) )
V_297 [ 1 ] = 0x00EB1401 | ( * ( ( T_2 * ) & V_297 [ 1 ] + 3 ) & 0x10 ) ;
return V_297 ;
}
static T_1 F_62 ( T_1 V_295 )
{
return V_295 & V_303 ;
}
static void F_63 ( struct V_83 * V_26 )
{
if ( V_26 -> V_304 . V_305 )
F_64 ( & V_26 -> V_304 ) ;
V_26 -> V_304 . V_305 = NULL ;
}
void F_65 ( struct V_1 * V_2 , int V_16 , int V_306 )
{
struct V_83 * V_26 = & V_2 -> V_26 [ V_16 ] ;
struct V_102 * V_61 ;
V_61 = (struct V_102 * ) V_26 -> V_103 ;
if ( V_306 ) {
V_26 -> V_295 = V_49 -> V_307 ( V_2 , V_16 ) ;
V_26 -> V_308 = F_60 ( V_2 , V_16 ) ;
}
if ( V_26 -> V_308 ) {
int V_309 = 0 ;
struct V_25 * V_31 = & V_2 -> V_26 [ V_16 ] . V_31 ;
V_309 = V_49 -> V_309 ( V_2 , V_16 ) ;
V_49 -> V_310 ( V_2 , V_16 , V_61 ) ;
if ( V_26 -> V_88 & V_113 ) {
V_26 -> V_105 . V_110 = V_275 ;
if ( F_62 ( V_26 -> V_295 ) ) {
F_63 ( V_26 ) ;
V_26 -> V_85 = 1 ;
V_26 -> V_311 =
V_16 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ;
if ( V_309 )
V_31 -> V_312 = V_313 ;
V_26 -> V_114 =
sizeof( struct V_314 ) ;
F_61 ( V_2 , V_16 , V_61 ) ;
} else {
T_1 V_62 ;
F_47 ( V_315 , V_2 -> V_18 ,
L_13 , V_16 ) ;
V_62 = V_49 -> V_316 ( V_2 , V_16 ) ;
V_49 -> V_317 ( V_2 , V_16 ,
V_62 | V_303 ) ;
V_26 -> V_85 = 0 ;
V_26 -> V_88 &= ~ V_113 ;
goto V_318;
}
} else if ( V_26 -> V_88 & V_89
|| V_26 -> V_86 & V_319 ) {
V_26 -> V_85 = 1 ;
V_26 -> V_105 . V_106 =
V_26 -> V_86 & V_320 ;
if ( V_26 -> V_105 . V_106 == V_321 )
V_26 -> V_105 . V_110 =
V_273 ;
else if ( V_26 -> V_105 . V_106 != V_322 )
V_26 -> V_105 . V_110 =
V_272 ;
if ( V_309 )
V_31 -> V_312 = V_323 ;
V_26 -> V_114 =
sizeof( struct V_102 ) ;
}
memcpy ( V_31 -> V_324 ,
& V_26 -> V_311 , V_175 ) ;
if ( V_49 -> V_325 )
V_49 -> V_325 ( V_2 , V_16 ) ;
}
F_24 ( L_14 ,
V_16 + V_2 -> V_61 * V_2 -> V_42 -> V_34 , V_26 -> V_86 ) ;
F_24 ( L_15 ,
V_16 + V_2 -> V_61 * V_2 -> V_42 -> V_34 , V_26 -> V_311 ) ;
V_318:
if ( V_306 )
V_49 -> V_326 ( V_2 , V_16 , V_26 -> V_295 ) ;
}
static void F_66 ( struct V_25 * V_31 , int V_287 )
{
struct V_21 * V_84 = V_31 -> V_24 ;
struct V_1 * V_2 = NULL ; int V_16 = 0 , V_20 ;
struct V_83 * V_26 = V_31 -> V_327 ;
struct V_128 * V_27 = V_31 -> V_23 ;
struct V_221 * V_23 ;
unsigned long V_140 = 0 ;
if ( ! V_27 )
return;
while ( V_84 -> V_31 [ V_16 ] ) {
if ( V_84 -> V_31 [ V_16 ] == V_31 )
break;
V_16 ++ ;
}
V_20 = V_16 / ( (struct V_32 * ) V_84 -> V_33 ) -> V_34 ;
V_2 = ( (struct V_32 * ) V_84 -> V_33 ) -> V_2 [ V_20 ] ;
if ( V_16 >= V_2 -> V_42 -> V_34 )
V_23 = & V_2 -> V_23 [ V_16 - V_2 -> V_42 -> V_34 ] ;
else
V_23 = & V_2 -> V_23 [ V_16 ] ;
if ( V_287 )
F_53 ( & V_2 -> V_287 , V_140 ) ;
V_23 -> V_263 = 1 ;
V_26 -> V_23 = V_23 ;
V_27 -> V_262 = V_23 ;
if ( V_26 -> V_88 & V_89 ) {
V_23 -> V_225 = V_27 -> V_52 ;
F_16 ( L_16 , V_27 -> V_52 ) ;
F_59 ( V_2 , V_31 -> V_61 ) ;
if ( V_26 -> V_86 & V_111 ) {
V_49 -> V_81 ( V_2 , V_16 , V_112 ) ;
V_49 -> V_82 ( V_2 , V_16 , 0x04 ) ;
}
}
if ( V_287 )
F_54 ( & V_2 -> V_287 , V_140 ) ;
}
static void F_67 ( struct V_25 * V_31 , int V_287 )
{
struct V_17 * V_18 ;
struct V_83 * V_26 = V_31 -> V_327 ;
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_128 * V_23 = V_31 -> V_23 ;
int V_292 = 0 ;
while ( V_26 != & V_2 -> V_26 [ V_292 ] ) {
V_292 ++ ;
if ( V_292 >= V_328 )
return;
}
F_13 (dev, &port->dev_list, dev_list_node)
F_68 ( V_26 -> V_2 , V_292 , V_18 ) ;
}
void F_69 ( struct V_25 * V_31 )
{
F_66 ( V_31 , 1 ) ;
}
void F_70 ( struct V_25 * V_31 )
{
F_67 ( V_31 , 1 ) ;
}
struct V_38 * F_71 ( struct V_1 * V_2 )
{
T_1 V_18 ;
for ( V_18 = 0 ; V_18 < V_45 ; V_18 ++ ) {
if ( V_2 -> V_46 [ V_18 ] . V_104 == V_322 ) {
V_2 -> V_46 [ V_18 ] . V_189 = V_18 ;
return & V_2 -> V_46 [ V_18 ] ;
}
}
if ( V_18 == V_45 )
F_16 ( L_17 ,
V_45 ) ;
return NULL ;
}
void F_72 ( struct V_38 * V_39 )
{
T_1 V_61 = V_39 -> V_189 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_189 = V_61 ;
V_39 -> V_104 = V_322 ;
V_39 -> V_329 = V_330 ;
V_39 -> V_47 = V_48 ;
}
int F_73 ( struct V_17 * V_18 , int V_287 )
{
unsigned long V_140 = 0 ;
int V_331 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_17 * V_332 = V_18 -> V_333 ;
struct V_38 * V_334 ;
V_2 = F_10 ( V_18 ) ;
if ( V_287 )
F_53 ( & V_2 -> V_287 , V_140 ) ;
V_334 = F_71 ( V_2 ) ;
if ( ! V_334 ) {
V_331 = - 1 ;
goto V_335;
}
V_18 -> V_40 = V_334 ;
V_334 -> V_329 = V_330 ;
V_334 -> V_104 = V_18 -> V_104 ;
V_334 -> V_41 = V_2 ;
V_334 -> V_336 = V_18 ;
if ( V_332 && F_74 ( V_332 -> V_104 ) ) {
int V_60 ;
T_2 V_337 = V_332 -> V_338 . V_339 ;
struct V_340 * V_26 ;
for ( V_60 = 0 ; V_60 < V_337 ; V_60 ++ ) {
V_26 = & V_332 -> V_338 . V_340 [ V_60 ] ;
if ( F_44 ( V_26 -> V_324 ) ==
F_44 ( V_18 -> V_79 ) ) {
V_334 -> V_341 = V_60 ;
break;
}
}
if ( V_60 == V_337 ) {
F_16 ( L_18
L_19 ,
F_44 ( V_18 -> V_79 ) ,
F_44 ( V_332 -> V_79 ) ) ;
V_331 = - 1 ;
}
}
V_335:
if ( V_287 )
F_54 ( & V_2 -> V_287 , V_140 ) ;
return V_331 ;
}
int F_75 ( struct V_17 * V_18 )
{
return F_73 ( V_18 , 1 ) ;
}
void F_76 ( struct V_17 * V_18 )
{
unsigned long V_140 = 0 ;
struct V_38 * V_39 = V_18 -> V_40 ;
struct V_1 * V_2 ;
if ( ! V_39 ) {
F_24 ( L_20 ) ;
return;
}
V_2 = V_39 -> V_41 ;
F_53 ( & V_2 -> V_287 , V_140 ) ;
F_24 ( L_21 ,
V_39 -> V_189 , V_39 -> V_104 ) ;
F_77 ( V_2 , V_18 ) ;
F_15 ( V_2 , V_39 ) ;
F_72 ( V_39 ) ;
V_18 -> V_40 = NULL ;
V_39 -> V_336 = NULL ;
F_54 ( & V_2 -> V_287 , V_140 ) ;
}
void F_78 ( struct V_17 * V_18 )
{
F_76 ( V_18 ) ;
}
static void F_79 ( struct V_3 * V_4 )
{
if ( ! F_64 ( & V_4 -> V_342 -> V_304 ) )
return;
F_80 ( & V_4 -> V_342 -> V_286 ) ;
}
static void F_81 ( unsigned long V_343 )
{
struct V_3 * V_4 = (struct V_3 * ) V_343 ;
V_4 -> V_281 |= V_344 ;
F_80 ( & V_4 -> V_342 -> V_286 ) ;
}
static int F_82 ( struct V_17 * V_18 ,
void * V_345 , T_1 V_346 , struct V_219 * V_220 )
{
int V_331 , V_347 ;
struct V_3 * V_4 = NULL ;
for ( V_347 = 0 ; V_347 < 3 ; V_347 ++ ) {
V_4 = F_83 ( V_348 ) ;
if ( ! V_4 )
return - V_146 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_264 = V_18 -> V_349 ;
memcpy ( & V_4 -> V_228 , V_345 , V_346 ) ;
V_4 -> V_261 = F_79 ;
V_4 -> V_342 -> V_304 . V_343 = ( unsigned long ) V_4 ;
V_4 -> V_342 -> V_304 . V_305 = F_81 ;
V_4 -> V_342 -> V_304 . V_350 = V_351 + V_352 * V_353 ;
F_84 ( & V_4 -> V_342 -> V_304 ) ;
V_331 = F_52 ( V_4 , V_348 , NULL , 1 , V_220 ) ;
if ( V_331 ) {
F_64 ( & V_4 -> V_342 -> V_304 ) ;
F_16 ( L_22 , V_331 ) ;
goto V_354;
}
F_85 ( & V_4 -> V_342 -> V_286 ) ;
V_331 = V_355 ;
if ( ( V_4 -> V_281 & V_344 ) ) {
if ( ! ( V_4 -> V_281 & V_356 ) ) {
F_16 ( L_23 , V_220 -> V_220 ) ;
goto V_354;
}
}
if ( V_4 -> V_255 . V_256 == V_266 &&
V_4 -> V_255 . V_258 == V_357 ) {
V_331 = V_358 ;
break;
}
if ( V_4 -> V_255 . V_256 == V_266 &&
V_4 -> V_255 . V_258 == V_359 ) {
V_331 = V_4 -> V_255 . V_360 ;
break;
}
if ( V_4 -> V_255 . V_256 == V_266 &&
V_4 -> V_255 . V_258 == V_361 ) {
F_24 ( L_24 ) ;
V_331 = - V_362 ;
break;
} else {
F_24 ( L_25
L_26 ,
F_44 ( V_18 -> V_79 ) ,
V_4 -> V_255 . V_256 ,
V_4 -> V_255 . V_258 ) ;
F_86 ( V_4 ) ;
V_4 = NULL ;
}
}
V_354:
F_87 ( V_347 == 3 && V_4 != NULL ) ;
F_86 ( V_4 ) ;
return V_331 ;
}
static int F_88 ( struct V_17 * V_18 ,
T_2 * V_363 , struct V_219 * V_220 )
{
struct V_364 V_228 ;
if ( ! ( V_18 -> V_349 & V_273 ) )
return V_365 ;
memcpy ( V_228 . V_243 , V_363 , 8 ) ;
return F_82 ( V_18 , & V_228 ,
sizeof( V_228 ) , V_220 ) ;
}
static int F_89 ( struct V_17 * V_18 )
{
int V_59 ;
struct V_31 * V_26 = F_90 ( V_18 ) ;
int V_366 = ( V_18 -> V_104 == V_260 ||
( V_18 -> V_349 & V_275 ) ) ? 0 : 1 ;
V_59 = F_91 ( V_26 , V_366 ) ;
F_92 ( V_26 ) ;
F_21 ( 2000 ) ;
return V_59 ;
}
int F_93 ( struct V_17 * V_18 , T_2 * V_363 )
{
unsigned long V_140 ;
int V_59 = V_355 ;
struct V_219 V_367 ;
struct V_38 * V_39 = V_18 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_41 ;
V_367 . V_220 = V_368 ;
V_39 -> V_329 = V_369 ;
V_59 = F_88 ( V_18 , V_363 , & V_367 ) ;
if ( V_59 == V_358 ) {
F_53 ( & V_2 -> V_287 , V_140 ) ;
F_77 ( V_2 , V_18 ) ;
F_54 ( & V_2 -> V_287 , V_140 ) ;
}
F_16 ( L_27 , V_370 ,
V_39 -> V_189 , V_59 ) ;
return V_59 ;
}
int F_94 ( struct V_17 * V_18 )
{
unsigned long V_140 ;
int V_59 = V_355 ;
struct V_38 * V_39 = (struct V_38 * ) V_18 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_41 ;
if ( V_39 -> V_329 != V_369 )
return V_358 ;
else
V_39 -> V_329 = V_330 ;
V_59 = F_89 ( V_18 ) ;
F_16 ( L_27 ,
V_370 , V_39 -> V_189 , V_59 ) ;
F_53 ( & V_2 -> V_287 , V_140 ) ;
F_77 ( V_2 , V_18 ) ;
F_54 ( & V_2 -> V_287 , V_140 ) ;
return V_59 ;
}
int F_95 ( struct V_3 * V_4 )
{
T_1 V_5 ;
struct V_371 V_363 ;
struct V_219 V_367 ;
int V_59 = V_355 ;
if ( V_4 -> V_6 && V_4 -> V_264 & V_273 ) {
struct V_372 * V_247 = (struct V_372 * ) V_4 -> V_180 ;
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_38 * V_39 = (struct V_38 * ) V_18 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_41 ;
F_96 ( V_247 -> V_373 -> V_363 , & V_363 ) ;
V_59 = F_1 ( V_2 , V_4 , & V_5 ) ;
if ( V_59 == 0 ) {
V_59 = V_355 ;
return V_59 ;
}
V_367 . V_220 = V_250 ;
V_367 . V_251 = F_97 ( V_5 ) ;
V_59 = F_88 ( V_18 , V_363 . V_371 , & V_367 ) ;
switch ( V_59 ) {
case V_374 :
case V_355 :
case V_358 :
break;
}
}
F_16 ( L_28 , V_370 , V_59 ) ;
return V_59 ;
}
int F_98 ( struct V_3 * V_4 )
{
struct V_371 V_363 ;
struct V_219 V_367 ;
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_38 * V_39 = (struct V_38 * ) V_18 -> V_40 ;
struct V_1 * V_2 ;
int V_59 = V_355 ;
unsigned long V_140 ;
T_1 V_5 ;
if ( ! V_39 ) {
F_16 ( L_29 ) ;
return V_355 ;
}
V_2 = V_39 -> V_41 ;
F_53 ( & V_4 -> V_280 , V_140 ) ;
if ( V_4 -> V_281 & V_356 ) {
F_54 ( & V_4 -> V_280 , V_140 ) ;
V_59 = V_358 ;
goto V_375;
}
F_54 ( & V_4 -> V_280 , V_140 ) ;
V_39 -> V_329 = V_369 ;
if ( V_4 -> V_6 && V_4 -> V_264 & V_273 ) {
struct V_372 * V_247 = (struct V_372 * ) V_4 -> V_180 ;
F_96 ( V_247 -> V_373 -> V_363 , & V_363 ) ;
V_59 = F_1 ( V_2 , V_4 , & V_5 ) ;
if ( V_59 == 0 ) {
F_16 ( L_30 , V_370 ) ;
V_59 = V_355 ;
return V_59 ;
}
V_367 . V_220 = V_249 ;
V_367 . V_251 = F_97 ( V_5 ) ;
V_59 = F_88 ( V_18 , V_363 . V_371 , & V_367 ) ;
if ( V_59 == V_358 ) {
T_1 V_376 ;
struct V_7 * V_8 ;
if ( V_4 -> V_6 ) {
V_8 = V_4 -> V_6 ;
V_376 = ( T_1 ) ( V_8 - V_2 -> V_139 ) ;
F_53 ( & V_2 -> V_287 , V_140 ) ;
F_99 ( V_2 , V_376 , 1 ) ;
F_54 ( & V_2 -> V_287 , V_140 ) ;
}
}
} else if ( V_4 -> V_264 & V_274 ||
V_4 -> V_264 & V_275 ) {
if ( V_260 == V_18 -> V_104 ) {
struct V_7 * V_8 = V_4 -> V_6 ;
T_1 V_290 = ( T_1 ) ( V_8 - V_2 -> V_139 ) ;
F_24 ( L_31
L_32 ,
V_2 , V_4 , V_8 , V_290 ) ;
V_4 -> V_281 |= V_344 ;
F_57 ( V_2 , V_4 , V_8 , V_290 ) ;
V_59 = V_358 ;
goto V_375;
}
}
V_375:
if ( V_59 != V_358 )
F_16 ( L_28 , V_370 , V_59 ) ;
return V_59 ;
}
int F_100 ( struct V_17 * V_18 , T_2 * V_363 )
{
int V_59 = V_355 ;
struct V_219 V_367 ;
V_367 . V_220 = V_377 ;
V_59 = F_88 ( V_18 , V_363 , & V_367 ) ;
return V_59 ;
}
int F_101 ( struct V_17 * V_18 , T_2 * V_363 )
{
int V_59 = V_355 ;
struct V_219 V_367 ;
V_367 . V_220 = V_378 ;
V_59 = F_88 ( V_18 , V_363 , & V_367 ) ;
return V_59 ;
}
int F_102 ( struct V_17 * V_18 , T_2 * V_363 )
{
int V_59 = V_355 ;
struct V_219 V_367 ;
V_367 . V_220 = V_379 ;
V_59 = F_88 ( V_18 , V_363 , & V_367 ) ;
return V_59 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_290 , int V_380 )
{
struct V_38 * V_39 = V_4 -> V_18 -> V_40 ;
struct V_253 * V_381 = & V_4 -> V_255 ;
struct V_382 * V_256 = (struct V_382 * ) V_381 -> V_153 ;
int V_258 = V_357 ;
V_256 -> V_383 = sizeof( struct V_314 ) ;
memcpy ( & V_256 -> V_384 [ 0 ] ,
F_104 ( V_39 -> V_47 ) ,
sizeof( struct V_314 ) ) ;
V_381 -> V_385 = sizeof( * V_256 ) ;
if ( F_105 ( V_380 ) ) {
if ( F_105 ( V_380 & V_386 ) )
V_258 = V_387 ;
else
V_258 = V_388 ;
}
return V_258 ;
}
void F_106 ( T_2 * V_389 , int V_390 , int V_391 ,
int V_392 , int V_393 , int V_394 )
{
memset ( V_389 , 0 , V_390 ) ;
if ( V_391 ) {
if ( V_390 < 4 ) {
F_16 ( L_33
L_34 , V_390 , V_392 , V_393 , V_394 ) ;
}
V_389 [ 0 ] = 0x72 ;
if ( V_390 > 1 )
V_389 [ 1 ] = V_392 ;
if ( V_390 > 2 )
V_389 [ 2 ] = V_393 ;
if ( V_390 > 3 )
V_389 [ 3 ] = V_394 ;
} else {
if ( V_390 < 14 ) {
F_16 ( L_33
L_34 , V_390 , V_392 , V_393 , V_394 ) ;
}
V_389 [ 0 ] = 0x70 ;
if ( V_390 > 2 )
V_389 [ 2 ] = V_392 ;
if ( V_390 > 7 )
V_389 [ 7 ] = 0x0a ;
if ( V_390 > 12 )
V_389 [ 12 ] = V_393 ;
if ( V_390 > 13 )
V_389 [ 13 ] = V_394 ;
}
return;
}
void F_107 ( struct V_395 * V_396 ,
T_2 V_392 , T_2 V_393 , T_2 V_397 )
{
V_396 -> V_398 = 2 ;
V_396 -> V_399 = 0 ;
V_396 -> V_400 = 17 ;
V_396 -> V_401 = 02 ;
F_106 ( V_396 -> V_402 , 17 , 0 ,
V_392 , V_393 , V_397 ) ;
}
static int F_108 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_290 )
{
struct V_7 * V_8 = & V_2 -> V_139 [ V_290 ] ;
int V_258 ;
T_1 V_403 = F_109 ( * ( T_1 * ) V_8 -> V_160 ) ;
T_1 V_404 = F_109 ( * ( ( T_1 * ) V_8 -> V_160 + 1 ) ) ;
T_1 V_405 = 0 ;
enum V_406 type = V_89 ;
if ( V_403 & V_386 )
V_49 -> V_407 ( V_2 , type , V_405 ) ;
V_49 -> V_408 ( V_2 , V_290 ) ;
V_258 = V_409 ;
switch ( V_4 -> V_264 ) {
case V_273 :
{
V_258 = V_410 ;
if ( ( V_403 & V_411 ) || V_404 & F_110 ( 31 ) ) {
struct V_395 * V_396 = V_8 -> V_160 +
sizeof( struct V_211 ) ;
F_107 ( V_396 , V_412 , 0x04 , 01 ) ;
F_111 ( V_2 -> V_18 , V_4 , V_396 ) ;
V_258 = V_409 ;
}
if ( V_404 & F_110 ( 31 ) )
F_16 ( L_35 ) ;
break;
}
case V_272 :
V_258 = V_409 ;
break;
case V_274 :
case V_275 :
case V_274 | V_275 :
{
V_4 -> V_197 . V_198 = 0 ;
V_258 = V_388 ;
F_103 ( V_2 , V_4 , V_290 , V_403 ) ;
}
break;
default:
break;
}
return V_258 ;
}
int F_99 ( struct V_1 * V_2 , T_1 V_289 , T_1 V_140 )
{
T_1 V_290 = V_289 & V_291 ;
struct V_7 * V_8 = & V_2 -> V_139 [ V_290 ] ;
struct V_3 * V_4 = V_8 -> V_4 ;
struct V_38 * V_39 = NULL ;
struct V_253 * V_381 ;
struct V_17 * V_18 ;
T_1 V_413 ;
void * V_414 ;
enum V_415 V_416 ;
if ( F_105 ( ! V_4 || ! V_4 -> V_6 || ! V_4 -> V_18 ) )
return - 1 ;
V_381 = & V_4 -> V_255 ;
V_18 = V_4 -> V_18 ;
V_39 = V_18 -> V_40 ;
F_49 ( & V_4 -> V_280 ) ;
V_4 -> V_281 &=
~ ( V_417 | V_282 ) ;
V_4 -> V_281 |= V_356 ;
V_413 = V_4 -> V_281 & V_344 ;
F_50 ( & V_4 -> V_280 ) ;
memset ( V_381 , 0 , sizeof( * V_381 ) ) ;
V_381 -> V_256 = V_266 ;
if ( F_105 ( V_413 ) ) {
V_381 -> V_258 = V_410 ;
if ( V_39 && V_39 -> V_283 )
V_39 -> V_283 -- ;
if ( F_45 ( V_4 -> V_264 ) )
F_15 ( V_2 , V_39 ) ;
F_57 ( V_2 , V_4 , V_8 , V_290 ) ;
return - 1 ;
}
if ( F_105 ( ! V_39 || V_140 ) ) {
if ( ! V_39 )
F_24 ( L_36 ) ;
V_381 -> V_258 = V_259 ;
goto V_375;
}
if ( F_105 ( ( V_289 & V_418 )
&& ( * ( ( T_1 * ) V_8 -> V_160 )
|| * ( ( ( T_1 * ) V_8 -> V_160 ) + 1 ) ) ) ) {
F_24 ( L_37
L_38 , V_8 -> V_23 -> V_27 . V_61 , V_290 ,
V_289 , F_112 ( V_8 -> V_160 ) ) ;
V_381 -> V_258 = F_108 ( V_2 , V_4 , V_290 ) ;
V_381 -> V_256 = V_266 ;
goto V_375;
}
switch ( V_4 -> V_264 ) {
case V_273 :
if ( V_289 & V_419 ) {
V_381 -> V_258 = V_357 ;
V_381 -> V_256 = V_266 ;
}
else if ( V_289 & V_420 ) {
struct V_395 * V_396 = V_8 -> V_160 +
sizeof( struct V_211 ) ;
F_111 ( V_2 -> V_18 , V_4 , V_396 ) ;
} else
V_381 -> V_258 = V_409 ;
break;
case V_272 : {
struct V_130 * V_132 = & V_4 -> V_143 . V_147 ;
V_381 -> V_258 = V_357 ;
V_414 = F_113 ( F_114 ( V_132 ) ) ;
memcpy ( V_414 + V_132 -> V_421 ,
V_8 -> V_160 + sizeof( struct V_211 ) ,
F_31 ( V_132 ) ) ;
F_115 ( V_414 ) ;
break;
}
case V_274 :
case V_275 :
case V_274 | V_275 : {
V_381 -> V_258 = F_103 ( V_2 , V_4 , V_290 , 0 ) ;
break;
}
default:
V_381 -> V_258 = V_409 ;
break;
}
if ( ! V_8 -> V_23 -> V_263 ) {
F_24 ( L_39 , V_8 -> V_23 -> V_27 . V_61 ) ;
V_381 -> V_258 = V_259 ;
}
V_375:
if ( V_39 && V_39 -> V_283 ) {
V_39 -> V_283 -- ;
if ( F_45 ( V_4 -> V_264 ) && ! V_39 -> V_283 )
F_15 ( V_2 , V_39 ) ;
}
F_57 ( V_2 , V_4 , V_8 , V_290 ) ;
V_416 = V_381 -> V_258 ;
F_50 ( & V_2 -> V_287 ) ;
if ( V_4 -> V_261 )
V_4 -> V_261 ( V_4 ) ;
F_49 ( & V_2 -> V_287 ) ;
return V_416 ;
}
void F_68 ( struct V_1 * V_2 ,
int V_292 , struct V_17 * V_18 )
{
T_1 V_290 ;
struct V_83 * V_26 ;
struct V_221 * V_23 ;
struct V_7 * V_8 , * V_422 ;
V_26 = & V_2 -> V_26 [ V_292 ] ;
V_23 = V_26 -> V_23 ;
if ( ! V_23 )
return;
F_116 ( V_2 , false ) ;
F_117 (slot, slot2, &port->list, entry) {
struct V_3 * V_4 ;
V_290 = ( T_1 ) ( V_8 - V_2 -> V_139 ) ;
V_4 = V_8 -> V_4 ;
if ( V_18 && V_4 -> V_18 != V_18 )
continue;
F_16 ( L_40 ,
V_290 , V_8 -> V_9 , V_4 ) ;
V_49 -> V_408 ( V_2 , V_290 ) ;
F_99 ( V_2 , V_290 , 1 ) ;
}
}
void F_77 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_16 , V_35 [ V_423 ] , V_37 ;
V_37 = F_12 ( V_18 , V_35 ) ;
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ )
F_68 ( V_2 , V_35 [ V_16 ] , V_18 ) ;
}
static void F_118 ( struct V_83 * V_26 )
{
V_26 -> V_85 = 0 ;
V_26 -> V_86 = 0 ;
V_26 -> V_311 = 0 ;
}
static void F_119 ( struct V_424 * V_425 )
{
struct V_426 * V_427 = F_11 ( V_425 , struct V_426 , V_425 ) ;
struct V_428 * V_429 = F_11 ( V_427 , struct V_428 , V_430 ) ;
struct V_1 * V_2 = V_429 -> V_2 ;
unsigned long V_140 ;
T_1 V_292 = ( unsigned long ) V_429 -> V_343 ;
struct V_21 * V_84 = V_2 -> V_90 ;
struct V_83 * V_26 = & V_2 -> V_26 [ V_292 ] ;
struct V_25 * V_31 = & V_26 -> V_31 ;
F_53 ( & V_2 -> V_287 , V_140 ) ;
if ( V_429 -> V_431 & V_432 ) {
if ( V_26 -> V_433 & V_434 ) {
T_1 V_62 ;
struct V_102 * V_61 ;
V_61 = (struct V_102 * ) V_26 -> V_103 ;
V_62 = V_49 -> V_66 ( V_2 , V_292 ) ;
V_26 -> V_433 &= ~ V_434 ;
if ( ! ( V_62 & V_294 ) ) {
F_120 ( V_31 ) ;
F_118 ( V_26 ) ;
V_84 -> V_91 ( V_31 ,
V_435 ) ;
F_24 ( L_41 , V_292 ) ;
} else {
V_49 -> V_436 ( V_2 , V_292 ) ;
F_65 ( V_2 , V_292 , 1 ) ;
F_23 ( V_2 , V_292 ) ;
F_66 ( V_31 , 0 ) ;
F_24 ( L_42 , V_292 ) ;
}
}
} else if ( V_429 -> V_431 & V_437 ) {
V_26 -> V_433 &= ~ V_437 ;
V_84 -> V_115 ( V_31 ,
V_438 ) ;
F_24 ( L_43 , V_292 ) ;
}
F_121 ( & V_429 -> V_278 ) ;
F_54 ( & V_2 -> V_287 , V_140 ) ;
F_122 ( V_429 ) ;
}
static int F_123 ( struct V_1 * V_2 , void * V_343 , int V_431 )
{
struct V_428 * V_429 ;
int V_439 = 0 ;
V_429 = F_124 ( sizeof( struct V_428 ) , V_270 ) ;
if ( V_429 ) {
V_429 -> V_2 = V_2 ;
V_429 -> V_343 = V_343 ;
V_429 -> V_431 = V_431 ;
F_125 ( & V_429 -> V_430 , F_119 , V_429 ) ;
F_48 ( & V_429 -> V_278 , & V_2 -> V_440 ) ;
F_126 ( & V_429 -> V_430 , V_353 * 2 ) ;
} else
V_439 = - V_146 ;
return V_439 ;
}
static void F_127 ( unsigned long V_441 )
{
struct V_83 * V_26 = (struct V_83 * ) V_441 ;
struct V_1 * V_2 = V_26 -> V_2 ;
T_2 V_292 ;
for ( V_292 = 0 ; V_292 < V_2 -> V_42 -> V_34 ; V_292 ++ ) {
if ( & V_2 -> V_26 [ V_292 ] == V_26 ) {
F_24 ( L_44 ,
V_292 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ) ;
V_49 -> V_55 ( V_2 , V_292 , V_68 ) ;
}
}
}
void F_128 ( struct V_1 * V_2 , int V_292 , T_1 V_442 )
{
T_1 V_62 ;
struct V_83 * V_26 = & V_2 -> V_26 [ V_292 ] ;
V_26 -> V_295 = V_49 -> V_307 ( V_2 , V_292 ) ;
V_49 -> V_326 ( V_2 , V_292 , V_26 -> V_295 ) ;
F_24 ( L_45 , V_292 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ,
V_49 -> V_66 ( V_2 , V_292 ) ) ;
F_24 ( L_46 , V_292 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ,
V_26 -> V_295 ) ;
if ( V_26 -> V_295 & V_443 ) {
F_24 ( L_47 ,
V_292 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ) ;
}
if ( V_26 -> V_295 & V_296 ) {
F_129 ( 500 ) ;
if ( ! ( V_26 -> V_433 & V_434 ) ) {
int V_444 = V_26 -> V_88 & V_113 ;
int V_445 ;
F_68 ( V_2 , V_292 , NULL ) ;
V_26 -> V_433 |= V_434 ;
V_49 -> V_446 ( V_2 , 0 , 1 ) ;
F_123 ( V_2 ,
( void * ) ( unsigned long ) V_292 ,
V_432 ) ;
V_445 = F_60 ( V_2 , V_292 ) ;
if ( V_445 || V_444 ) {
if ( V_49 -> V_447 )
V_49 -> V_447 ( V_2 ,
V_292 ) ;
else
V_49 -> V_55 ( V_2 ,
V_292 , V_71 ) ;
return;
}
}
}
if ( V_26 -> V_295 & V_448 ) {
V_62 = V_49 -> V_316 ( V_2 , V_292 ) ;
V_49 -> V_317 ( V_2 , V_292 ,
V_62 | V_303 ) ;
if ( V_26 -> V_304 . V_305 == NULL ) {
V_26 -> V_304 . V_343 = ( unsigned long ) V_26 ;
V_26 -> V_304 . V_305 = F_127 ;
V_26 -> V_304 . V_350 = V_351 + 5 * V_353 ;
F_84 ( & V_26 -> V_304 ) ;
}
}
if ( V_26 -> V_295 & ( V_303 | V_449 ) ) {
V_26 -> V_308 = F_60 ( V_2 , V_292 ) ;
F_24 ( L_48 , V_292 ) ;
if ( V_26 -> V_308 ) {
F_129 ( 10 ) ;
V_49 -> V_436 ( V_2 , V_292 ) ;
if ( V_26 -> V_88 & V_113 ) {
V_62 = V_49 -> V_316 (
V_2 , V_292 ) ;
V_62 &= ~ V_303 ;
V_49 -> V_317 ( V_2 ,
V_292 , V_62 ) ;
}
F_65 ( V_2 , V_292 , 0 ) ;
if ( V_26 -> V_88 & V_89 ) {
V_49 -> V_55 ( V_2 , V_292 , V_450 ) ;
F_129 ( 10 ) ;
}
F_23 ( V_2 , V_292 ) ;
if ( V_26 -> V_433 & V_434 ) {
F_66 ( & V_26 -> V_31 , 0 ) ;
V_26 -> V_433 &= ~ V_434 ;
}
} else {
F_24 ( L_49 ,
V_292 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ) ;
}
} else if ( V_26 -> V_295 & V_451 ) {
F_24 ( L_50 ,
V_292 + V_2 -> V_61 * V_2 -> V_42 -> V_34 ) ;
F_123 ( V_2 , ( void * ) ( unsigned long ) V_292 ,
V_437 ) ;
}
}
int F_116 ( struct V_1 * V_2 , bool V_452 )
{
T_1 V_453 , V_289 ;
bool V_454 = false ;
V_453 = V_2 -> V_455 ;
V_2 -> V_455 = F_109 ( V_2 -> V_456 [ 0 ] ) ;
if ( V_2 -> V_455 == 0xfff )
return 0 ;
if ( F_105 ( V_2 -> V_455 == V_453 ) )
V_2 -> V_455 = V_49 -> V_457 ( V_2 ) & V_458 ;
if ( V_2 -> V_455 == V_453 )
return 0 ;
while ( V_2 -> V_455 != V_453 ) {
V_453 = ( V_453 + 1 ) & ( V_459 - 1 ) ;
V_289 = F_109 ( V_2 -> V_456 [ V_453 + 1 ] ) ;
if ( F_39 ( V_289 & V_460 ) )
F_99 ( V_2 , V_289 , 0 ) ;
if ( V_289 & V_461 ) {
V_454 = true ;
} else if ( V_289 & V_418 ) {
if ( ! ( V_289 & V_460 ) )
F_99 ( V_2 , V_289 , 0 ) ;
} else if ( V_289 & V_462 ) {
F_56 ( V_2 , V_289 ) ;
}
}
if ( V_454 && V_452 )
V_49 -> V_463 ( V_2 ) ;
return 0 ;
}
