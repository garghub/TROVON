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
void * V_10 = & V_2 -> V_11 ;
F_3 ( V_5 , V_10 ) ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_5 )
{
F_2 ( V_2 , V_5 ) ;
}
void F_5 ( struct V_1 * V_2 , unsigned int V_5 )
{
void * V_10 = & V_2 -> V_11 ;
F_6 ( V_5 , V_10 ) ;
}
inline int F_7 ( struct V_1 * V_2 , T_1 * V_12 )
{
unsigned int V_13 , V_5 ;
void * V_10 = & V_2 -> V_11 ;
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
void F_10 ( T_1 V_17 , T_2 * V_18 , T_1 V_19 )
{
T_1 V_16 ;
T_1 V_20 ;
T_1 V_21 ;
V_21 = 0 ;
while ( V_17 ) {
F_11 ( V_22 L_1 , V_19 + V_21 ) ;
if ( V_17 >= 16 )
V_20 = 16 ;
else
V_20 = V_17 ;
V_17 -= V_20 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
if ( V_16 < V_20 )
F_11 ( V_22 L_2 , ( T_1 ) V_18 [ V_16 ] ) ;
else
F_11 ( V_22 L_3 ) ;
}
F_11 ( V_22 L_4 ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ )
F_11 ( V_22 L_5 ,
isalnum ( V_18 [ V_16 ] ) ? V_18 [ V_16 ] : '.' ) ;
F_11 ( V_22 L_6 ) ;
V_18 = & V_18 [ 16 ] ;
V_21 += V_20 ;
}
F_11 ( V_22 L_6 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_5 ,
enum V_23 V_24 )
{
T_1 V_21 ;
struct V_7 * V_8 = & V_2 -> V_25 [ V_5 ] ;
V_21 = V_8 -> V_26 + V_27 +
V_28 -> V_29 () * V_8 -> V_30 ;
F_13 ( V_22 , V_2 -> V_31 , L_7 ,
V_5 ) ;
F_10 ( 32 , ( T_2 * ) V_8 -> V_32 ,
( T_1 ) V_8 -> V_33 + V_21 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_5 ,
enum V_23 V_24 )
{
#if ( V_34 > 1 )
T_1 V_35 , V_36 ;
T_3 V_37 ;
struct V_7 * V_8 = & V_2 -> V_25 [ V_5 ] ;
V_35 = V_38 ;
V_36 = V_8 -> V_39 ;
V_37 = V_2 -> V_40 ;
F_13 ( V_22 , V_2 -> V_31 ,
L_8 , V_35 , V_36 ) ;
F_13 ( V_22 , V_2 -> V_31 ,
L_9
L_10 ,
V_37 , ( unsigned long long ) V_2 -> V_40 , V_36 ) ;
F_10 ( sizeof( T_1 ) , ( T_2 * ) ( & V_2 -> V_39 [ V_2 -> V_41 ] ) ,
( T_1 ) V_2 -> V_40 + sizeof( T_1 ) * V_36 ) ;
V_37 = V_2 -> V_42 ;
F_13 ( V_22 , V_2 -> V_31 ,
L_11
L_12 ,
V_37 , ( unsigned long long ) V_8 -> V_33 , V_5 ) ;
F_13 ( V_22 , V_2 -> V_31 , L_13 , V_5 ) ;
F_10 ( sizeof( struct V_43 ) , ( T_2 * ) ( & V_2 -> V_8 [ V_5 ] ) ,
( T_1 ) V_2 -> V_42 + V_5 * sizeof( struct V_43 ) ) ;
F_13 ( V_22 , V_2 -> V_31 , L_14 ) ;
F_10 ( V_8 -> V_26 , ( T_2 * ) V_8 -> V_44 , ( T_1 ) V_8 -> V_33 ) ;
F_13 ( V_22 , V_2 -> V_31 , L_15 ) ;
F_10 ( V_27 , ( T_2 * ) V_8 -> V_44 + V_8 -> V_26 ,
( T_1 ) V_8 -> V_33 + V_8 -> V_26 ) ;
F_12 ( V_2 , V_5 , V_24 ) ;
F_13 ( V_22 , V_2 -> V_31 , L_16 ) ;
F_10 ( V_28 -> V_29 () * V_8 -> V_30 ,
( T_2 * ) V_8 -> V_44 + V_8 -> V_26 + V_27 ,
( T_1 ) V_8 -> V_33 + V_8 -> V_26 + V_27 ) ;
#endif
}
static void F_15 ( struct V_1 * V_2 )
{
#if ( V_34 > 2 )
T_3 V_37 ;
void T_4 * V_45 = V_2 -> V_45 ;
T_1 V_46 = V_2 -> V_47 + 1 ;
T_1 V_48 = F_16 ( V_2 -> V_49 [ V_46 ] ) ;
V_37 = F_17 ( V_50 ) << 16 << 16 | F_17 ( V_51 ) ;
F_13 ( V_22 , V_2 -> V_31 , L_17 ,
V_2 -> V_25 [ V_48 & V_52 ] . V_4 ) ;
F_13 ( V_22 , V_2 -> V_31 ,
L_18
L_19 ,
V_37 , V_46 - 1 , V_2 -> V_49 [ 0 ] ) ;
F_10 ( sizeof( T_1 ) , ( T_2 * ) ( & V_48 ) ,
V_2 -> V_53 + sizeof( T_1 ) * V_46 ) ;
#endif
}
void F_18 ( void * V_44 , T_1 V_54 )
{
}
struct V_1 * F_19 ( struct V_55 * V_31 )
{
unsigned long V_16 = 0 , V_56 = 0 , V_57 = 0 ;
struct V_58 * V_59 = V_31 -> V_60 -> V_61 ;
struct V_1 * V_2 = NULL ;
struct V_62 * V_63 ;
while ( V_59 -> V_64 [ V_16 ] ) {
if ( V_59 -> V_64 [ V_16 ] == V_31 -> V_60 ) {
V_63 = F_20 ( V_59 -> V_64 [ V_16 ] -> V_65 . V_66 ,
struct V_62 , V_67 ) ;
V_56 = 0 ;
while ( V_59 -> V_68 [ V_56 ] ) {
if ( V_59 -> V_68 [ V_56 ] == V_63 )
break;
V_56 ++ ;
}
break;
}
V_16 ++ ;
}
V_57 = V_56 / ( (struct V_69 * ) V_59 -> V_70 ) -> V_71 ;
V_2 = ( (struct V_69 * ) V_59 -> V_70 ) -> V_2 [ V_57 ] ;
return V_2 ;
}
int F_21 ( struct V_55 * V_31 , int * V_72 )
{
unsigned long V_16 = 0 , V_56 = 0 , V_73 = 0 , V_74 = 0 ;
struct V_75 * V_76 = (struct V_75 * ) V_31 -> V_77 ;
struct V_1 * V_2 = V_76 -> V_78 ;
struct V_58 * V_59 = V_31 -> V_60 -> V_61 ;
while ( V_59 -> V_64 [ V_16 ] ) {
if ( V_59 -> V_64 [ V_16 ] == V_31 -> V_60 ) {
struct V_62 * V_63 ;
F_22 (phy,
&sha->sas_port[i]->phy_list, port_phy_el) {
V_56 = 0 ;
while ( V_59 -> V_68 [ V_56 ] ) {
if ( V_59 -> V_68 [ V_56 ] == V_63 )
break;
V_56 ++ ;
}
V_72 [ V_73 ] = ( V_56 >= V_2 -> V_79 -> V_71 ) ?
( V_56 - V_2 -> V_79 -> V_71 ) : V_56 ;
V_74 ++ ;
V_73 ++ ;
}
break;
}
V_16 ++ ;
}
return V_74 ;
}
static inline void F_23 ( struct V_1 * V_2 ,
struct V_75 * V_31 )
{
if ( ! V_31 ) {
F_24 ( L_20 ) ;
return;
}
if ( V_31 -> V_80 == V_81 )
return;
V_28 -> V_82 ( V_2 , & V_31 -> V_80 ) ;
}
static inline T_2 F_25 ( struct V_1 * V_2 ,
struct V_75 * V_31 )
{
if ( V_31 -> V_80 != V_81 )
return 0 ;
return V_28 -> V_83 ( V_2 , & V_31 -> V_80 ) ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_84 , int V_85 )
{
T_1 V_86 ;
F_27 (phy_mask, phy_mask, no) {
if ( ! ( V_84 & 1 ) )
continue;
V_28 -> V_87 ( V_2 , V_86 , V_85 ) ;
}
}
int F_28 ( struct V_62 * V_68 , enum V_88 V_89 ,
void * V_90 )
{
int V_91 = 0 , V_92 = V_68 -> V_93 ;
T_1 V_94 , V_16 = 0 , V_57 ;
struct V_58 * V_59 = V_68 -> V_61 ;
struct V_1 * V_2 = NULL ;
while ( V_59 -> V_68 [ V_16 ] ) {
if ( V_59 -> V_68 [ V_16 ] == V_68 )
break;
V_16 ++ ;
}
V_57 = V_16 / ( (struct V_69 * ) V_59 -> V_70 ) -> V_71 ;
V_2 = ( (struct V_69 * ) V_59 -> V_70 ) -> V_2 [ V_57 ] ;
switch ( V_89 ) {
case V_95 :
V_28 -> V_96 ( V_2 , V_92 , V_90 ) ;
break;
case V_97 :
V_94 = V_28 -> V_98 ( V_2 , V_92 ) ;
if ( V_94 & V_99 )
break;
V_28 -> V_87 ( V_2 , V_92 , 1 ) ;
break;
case V_100 :
V_28 -> V_101 ( V_2 , V_92 ) ;
V_28 -> V_87 ( V_2 , V_92 , 0 ) ;
break;
case V_102 :
V_28 -> V_103 ( V_2 , V_92 ) ;
break;
case V_104 :
default:
V_91 = - V_105 ;
}
F_29 ( 200 ) ;
return V_91 ;
}
void T_5 F_30 ( struct V_1 * V_2 , int V_106 ,
T_1 V_107 , T_1 V_108 , T_3 V_109 )
{
T_1 V_110 = ( T_1 ) V_109 ;
T_1 V_57 = ( T_1 ) ( V_109 >> 32 ) ;
V_28 -> V_111 ( V_2 , V_106 , V_107 ) ;
V_28 -> V_112 ( V_2 , V_106 , V_110 ) ;
V_28 -> V_111 ( V_2 , V_106 , V_108 ) ;
V_28 -> V_112 ( V_2 , V_106 , V_57 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_16 )
{
struct V_113 * V_63 = & V_2 -> V_63 [ V_16 ] ;
struct V_62 * V_68 = & V_63 -> V_68 ;
struct V_58 * V_114 ;
if ( ! V_63 -> V_115 )
return;
if ( ! ( V_63 -> V_116 & V_117 )
&& V_63 -> V_118 & V_119 ) {
return;
}
V_114 = V_2 -> V_120 ;
V_114 -> V_121 ( V_68 , V_122 ) ;
if ( V_68 -> V_63 ) {
struct V_68 * V_123 = V_68 -> V_63 ;
V_123 -> V_124 = V_68 -> V_125 ;
V_123 -> V_126 = V_63 -> V_126 ;
V_123 -> V_127 = V_128 ;
V_123 -> V_129 = V_63 -> V_129 ;
V_123 -> V_130 = V_28 -> V_131 () ;
}
if ( V_63 -> V_118 & V_119 ) {
struct V_132 * V_93 ;
V_93 = (struct V_132 * ) V_63 -> V_133 ;
V_93 -> V_134 = V_63 -> V_135 . V_136 ;
V_93 -> V_137 = V_138 ;
V_93 -> V_139 = V_63 -> V_135 . V_140 ;
} else if ( V_63 -> V_118 & V_141 ) {
}
F_32 ( L_21 , V_16 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ) ;
V_68 -> V_142 = V_63 -> V_142 ;
V_2 -> V_120 -> V_143 ( V_68 ,
V_144 ) ;
}
int F_33 ( struct V_145 * V_146 )
{
struct V_55 * V_31 = F_34 ( V_146 ) ;
if ( F_35 ( V_31 ) ) {
if ( V_146 -> V_147 > 0 )
return - V_148 ;
V_146 -> V_149 = 1 ;
}
return F_36 ( V_146 ) ;
}
int F_37 ( struct V_145 * V_150 )
{
struct V_55 * V_31 = F_34 ( V_150 ) ;
int V_151 = F_38 ( V_150 ) ;
if ( V_151 )
return V_151 ;
if ( F_35 ( V_31 ) ) {
#if V_152
struct V_153 * V_154 = V_31 -> V_155 . V_154 ;
struct V_156 * V_157 = V_154 -> V_158 . V_159 ;
V_157 -> V_160 |= V_161 ;
F_39 ( V_150 , V_162 , 1 ) ;
#endif
}
return 0 ;
}
void F_40 ( struct V_163 * V_164 )
{
int V_16 , V_56 ;
unsigned short V_165 ;
struct V_1 * V_2 ;
struct V_58 * V_59 = F_41 ( V_164 ) ;
V_165 = ( (struct V_69 * ) V_59 -> V_70 ) -> V_166 ;
for ( V_56 = 0 ; V_56 < V_165 ; V_56 ++ ) {
V_2 = ( (struct V_69 * ) V_59 -> V_70 ) -> V_2 [ V_56 ] ;
for ( V_16 = 0 ; V_16 < V_2 -> V_79 -> V_71 ; ++ V_16 )
F_31 ( V_2 , V_16 ) ;
}
}
int F_42 ( struct V_163 * V_164 , unsigned long time )
{
if ( time < V_167 )
return 0 ;
F_43 ( V_164 ) ;
return 1 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
int V_170 , V_91 , V_16 ;
struct V_3 * V_4 = V_169 -> V_4 ;
struct V_43 * V_171 = V_169 -> V_171 ;
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_172 * V_64 = V_31 -> V_60 ;
struct V_173 * V_174 , * V_175 ;
T_1 V_176 , V_177 , V_5 = V_169 -> V_5 ;
void * V_178 ;
T_2 * V_179 ;
T_6 V_180 ;
void * V_181 ;
struct V_7 * V_8 = & V_2 -> V_25 [ V_5 ] ;
T_1 V_160 = ( V_169 -> V_30 << V_182 ) ;
#if V_34
T_2 * V_183 ;
void * V_184 ;
#endif
V_174 = & V_4 -> V_185 . V_186 ;
V_170 = F_45 ( V_2 -> V_31 , V_174 , 1 , V_187 ) ;
if ( ! V_170 )
return - V_188 ;
V_176 = F_46 ( V_174 ) ;
V_175 = & V_4 -> V_185 . V_189 ;
V_170 = F_45 ( V_2 -> V_31 , V_175 , 1 , V_190 ) ;
if ( ! V_170 ) {
V_91 = - V_188 ;
goto V_191;
}
V_177 = V_192 ;
if ( ( V_176 & 0x3 ) || ( V_177 & 0x3 ) ) {
V_91 = - V_193 ;
goto V_194;
}
V_178 = V_8 -> V_44 ;
V_180 = V_8 -> V_33 ;
#if V_34
V_183 = V_178 ;
V_171 -> V_195 = F_47 ( V_180 ) ;
V_178 += V_176 ;
V_180 += V_176 ;
V_8 -> V_26 = V_176 ;
#else
V_171 -> V_195 = F_47 ( F_48 ( V_174 ) ) ;
#endif
V_179 = V_178 ;
V_171 -> V_196 = F_47 ( V_180 ) ;
V_178 += V_27 ;
V_180 += V_27 ;
V_181 = V_178 ;
if ( V_169 -> V_30 )
V_171 -> V_197 = F_47 ( V_180 ) ;
else
V_171 -> V_197 = 0 ;
V_16 = V_28 -> V_29 () * V_169 -> V_30 ;
V_178 += V_16 ;
V_180 += V_16 ;
V_8 -> V_32 = V_178 ;
V_171 -> V_198 = F_47 ( V_180 ) ;
if ( V_2 -> V_160 & V_199 )
V_171 -> V_200 [ 0 ] = 0 ;
V_8 -> V_39 = V_2 -> V_41 ;
V_2 -> V_39 [ V_2 -> V_41 ] = F_49 ( ( V_201 << V_202 ) |
V_203 | V_5 |
( V_64 -> V_84 << V_204 ) ) ;
V_171 -> V_160 |= V_160 ;
V_171 -> V_205 = F_49 ( ( ( V_177 / 4 ) << 16 ) | ( ( V_176 - 4 ) / 4 ) ) ;
V_171 -> V_11 = F_49 ( V_5 ) ;
V_171 -> V_206 = 0 ;
V_179 [ 0 ] = ( 1 << 7 ) | ( V_207 << 4 ) | 0x01 ;
V_179 [ 1 ] = V_31 -> V_125 & 0xf ;
* ( V_208 * ) ( V_179 + 2 ) = 0xFFFF ;
memcpy ( V_179 + 4 , V_31 -> V_109 , V_209 ) ;
V_28 -> V_210 ( V_4 -> V_211 , V_169 -> V_30 , V_181 ) ;
#if V_34
V_184 = F_50 ( F_51 ( V_174 ) , V_212 ) ;
memcpy ( V_183 , V_184 + V_174 -> V_21 , V_176 ) ;
F_52 ( V_184 , V_212 ) ;
#endif
return 0 ;
V_194:
F_53 ( V_2 -> V_31 , & V_169 -> V_4 -> V_185 . V_189 , 1 ,
V_190 ) ;
V_191:
F_53 ( V_2 -> V_31 , & V_169 -> V_4 -> V_185 . V_186 , 1 ,
V_187 ) ;
return V_91 ;
}
static T_1 F_54 ( struct V_3 * V_4 , T_1 * V_5 )
{
struct V_213 * V_214 = V_4 -> V_215 ;
if ( V_214 ) {
if ( V_214 -> V_216 . V_217 == V_218 ||
V_214 -> V_216 . V_217 == V_219 ) {
* V_5 = V_214 -> V_5 ;
return 1 ;
}
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
struct V_3 * V_4 = V_169 -> V_4 ;
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_75 * V_76 = V_31 -> V_77 ;
struct V_43 * V_171 = V_169 -> V_171 ;
struct V_172 * V_64 = V_31 -> V_60 ;
struct V_7 * V_8 ;
void * V_181 ;
T_1 V_5 = V_169 -> V_5 , V_220 ;
T_1 V_160 , V_221 ;
void * V_178 ;
T_2 * V_183 , * V_179 ;
T_6 V_180 ;
T_1 V_16 , V_176 , V_177 ;
const T_1 V_222 = V_192 ;
if ( F_25 ( V_2 , V_76 ) == V_81 ) {
F_32 ( L_22 ,
V_76 -> V_223 ) ;
return - V_224 ;
}
V_8 = & V_2 -> V_25 [ V_5 ] ;
V_8 -> V_39 = V_2 -> V_41 ;
V_221 = V_203 | V_5 |
( V_225 << V_202 ) |
( V_64 -> V_84 << V_204 ) |
( V_76 -> V_80 << V_226 ) ;
V_2 -> V_39 [ V_2 -> V_41 ] = F_49 ( V_221 ) ;
#ifndef F_56
if ( V_4 -> V_227 == V_228 )
V_160 = ( V_28 -> V_229 () << V_182 ) ;
else
V_160 = ( V_169 -> V_30 << V_182 ) ;
#else
V_160 = ( V_169 -> V_30 << V_182 ) ;
#endif
if ( V_4 -> V_230 . V_231 )
V_160 |= V_232 ;
if ( V_31 -> V_155 . V_233 == V_234 ) {
if ( V_4 -> V_230 . V_235 . V_217 != V_236 )
V_160 |= V_237 ;
}
V_171 -> V_160 = F_49 ( V_160 ) ;
if ( V_4 -> V_230 . V_231 && F_54 ( V_4 , & V_220 ) )
V_4 -> V_230 . V_235 . V_238 |= ( T_2 ) ( V_220 << 3 ) ;
else
V_220 = V_5 ;
V_171 -> V_11 = F_49 ( V_220 ) ;
V_171 -> V_206 = F_49 ( V_4 -> V_239 ) ;
V_183 = V_178 = V_8 -> V_44 ;
V_180 = V_8 -> V_33 ;
V_171 -> V_195 = F_47 ( V_180 ) ;
V_178 += V_240 ;
V_180 += V_240 ;
#if V_34
V_8 -> V_26 = V_240 ;
#endif
V_179 = V_178 ;
V_171 -> V_196 = F_47 ( V_180 ) ;
V_178 += V_27 ;
V_180 += V_27 ;
V_181 = V_178 ;
if ( V_169 -> V_30 )
V_171 -> V_197 = F_47 ( V_180 ) ;
else
V_171 -> V_197 = 0 ;
V_16 = V_28 -> V_29 () * V_28 -> V_229 () ;
V_178 += V_16 ;
V_180 += V_16 ;
V_8 -> V_32 = V_178 ;
V_171 -> V_198 = F_47 ( V_180 ) ;
if ( V_2 -> V_160 & V_199 )
V_171 -> V_200 [ 0 ] = 0 ;
V_176 = sizeof( struct V_241 ) ;
V_177 = V_242 - V_240 -
sizeof( struct V_243 ) - V_16 ;
V_177 = F_57 ( V_177 , V_222 ) ;
V_171 -> V_205 = F_49 ( ( ( V_177 / 4 ) << 16 ) | ( V_176 / 4 ) ) ;
if ( F_58 ( ! V_4 -> V_230 . V_244 ) )
V_4 -> V_230 . V_235 . V_160 |= 0x80 ;
memcpy ( V_183 , & V_4 -> V_230 . V_235 , sizeof( struct V_241 ) ) ;
if ( V_31 -> V_155 . V_233 == V_234 )
memcpy ( V_183 + V_245 ,
V_4 -> V_230 . V_246 , 16 ) ;
V_179 [ 0 ] = ( 1 << 7 ) | ( V_247 << 4 ) | 0x1 ;
V_179 [ 1 ] = V_31 -> V_125 & 0xf ;
* ( V_208 * ) ( V_179 + 2 ) = F_59 ( V_76 -> V_223 + 1 ) ;
memcpy ( V_179 + 4 , V_31 -> V_109 , V_209 ) ;
V_28 -> V_210 ( V_4 -> V_211 , V_169 -> V_30 , V_181 ) ;
#ifndef F_56
if ( V_4 -> V_227 == V_228 )
V_28 -> V_248 ( V_2 -> V_249 ,
V_250 , V_169 -> V_30 , V_181 ) ;
#endif
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_168 * V_169 , int V_251 ,
struct V_252 * V_253 )
{
struct V_3 * V_4 = V_169 -> V_4 ;
struct V_43 * V_171 = V_169 -> V_171 ;
struct V_254 * V_60 = V_169 -> V_60 ;
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_75 * V_76 = V_31 -> V_77 ;
struct V_172 * V_64 = V_31 -> V_60 ;
struct V_7 * V_8 ;
void * V_181 ;
struct V_255 * V_256 ;
void * V_178 ;
T_2 * V_183 , * V_179 , V_257 = 0 ;
T_6 V_180 ;
T_1 V_160 ;
T_1 V_177 , V_176 , V_16 , V_5 = V_169 -> V_5 ;
const T_1 V_222 = V_192 ;
T_1 V_84 ;
V_8 = & V_2 -> V_25 [ V_5 ] ;
V_84 = ( ( V_60 -> V_258 ) ? V_60 -> V_258 :
V_64 -> V_84 ) & V_259 ;
V_8 -> V_39 = V_2 -> V_41 ;
V_2 -> V_39 [ V_2 -> V_41 ] = F_49 ( V_203 | V_5 |
( V_260 << V_202 ) |
( V_84 << V_204 ) ) ;
V_160 = V_261 ;
if ( V_4 -> V_262 . V_263 ) {
V_160 |= V_264 ;
V_257 = ( 1 << 7 ) ;
}
if ( V_251 )
V_160 |= ( V_265 << V_266 ) ;
V_171 -> V_160 = F_49 ( V_160 | ( V_169 -> V_30 << V_182 ) ) ;
V_171 -> V_11 = F_49 ( V_5 ) ;
V_171 -> V_206 = F_49 ( V_4 -> V_239 ) ;
V_183 = V_178 = V_8 -> V_44 ;
V_180 = V_8 -> V_33 ;
V_171 -> V_195 = F_47 ( V_180 ) ;
V_178 += V_267 ;
V_180 += V_267 ;
#if V_34
V_8 -> V_26 = V_267 ;
#endif
V_179 = V_178 ;
V_171 -> V_196 = F_47 ( V_180 ) ;
V_178 += V_27 ;
V_180 += V_27 ;
V_181 = V_178 ;
if ( V_169 -> V_30 )
V_171 -> V_197 = F_47 ( V_180 ) ;
else
V_171 -> V_197 = 0 ;
V_16 = V_28 -> V_29 () * V_169 -> V_30 ;
V_178 += V_16 ;
V_180 += V_16 ;
V_8 -> V_32 = V_178 ;
V_171 -> V_198 = F_47 ( V_180 ) ;
if ( V_2 -> V_160 & V_199 )
V_171 -> V_200 [ 0 ] = 0 ;
V_177 = V_242 - V_267 - V_27 -
sizeof( struct V_243 ) - V_16 ;
V_177 = F_57 ( V_177 , V_222 ) ;
V_176 = sizeof( struct V_255 ) + 28 ;
V_171 -> V_205 = F_49 ( ( ( V_177 / 4 ) << 16 ) | ( V_176 / 4 ) ) ;
V_179 [ 0 ] = ( 1 << 7 ) | ( V_268 << 4 ) | 0x1 ;
V_179 [ 1 ] = V_31 -> V_125 & 0xf ;
* ( V_208 * ) ( V_179 + 2 ) = F_59 ( V_76 -> V_223 + 1 ) ;
memcpy ( V_179 + 4 , V_31 -> V_109 , V_209 ) ;
V_256 = (struct V_255 * ) V_183 ;
if ( V_251 )
V_256 -> V_269 = V_270 ;
else
V_256 -> V_269 = V_271 ;
memcpy ( V_256 -> V_272 , V_31 -> V_273 ,
V_274 ) ;
memcpy ( V_256 -> V_275 ,
V_31 -> V_273 , V_274 ) ;
V_256 -> V_5 = F_59 ( V_5 ) ;
V_183 += sizeof( * V_256 ) ;
memcpy ( V_183 , & V_4 -> V_262 . V_276 , 8 ) ;
if ( V_256 -> V_269 != V_270 ) {
V_183 [ 9 ] = V_257 | V_4 -> V_262 . V_277 |
( V_4 -> V_262 . V_278 << 3 ) ;
memcpy ( V_183 + 12 , & V_4 -> V_262 . V_279 , 16 ) ;
} else{
V_183 [ 10 ] = V_253 -> V_253 ;
switch ( V_253 -> V_253 ) {
case V_280 :
case V_281 :
V_183 [ 12 ] =
( V_253 -> V_282 >> 8 ) & 0xff ;
V_183 [ 13 ] =
V_253 -> V_282 & 0xff ;
break;
default:
break;
}
}
V_28 -> V_210 ( V_4 -> V_211 , V_169 -> V_30 , V_181 ) ;
return 0 ;
}
static int F_61 ( struct V_3 * V_4 , struct V_1 * V_2 , int V_251 ,
struct V_252 * V_253 , int * V_283 )
{
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_75 * V_76 = V_31 -> V_77 ;
struct V_168 V_169 ;
struct V_7 * V_8 ;
T_1 V_5 = 0xdeadbeef , V_30 = 0 ;
int V_91 = 0 ;
if ( ! V_31 -> V_60 ) {
struct V_284 * V_285 = & V_4 -> V_286 ;
V_285 -> V_287 = V_288 ;
V_285 -> V_289 = V_290 ;
if ( V_31 -> V_134 != V_291 )
V_4 -> V_292 ( V_4 ) ;
return V_91 ;
}
if ( F_62 ( V_76 ) ) {
if ( V_76 )
F_32 ( L_23 ,
V_76 -> V_223 ) ;
else
F_32 ( L_24 ,
F_63 ( V_31 -> V_109 ) ) ;
V_91 = V_290 ;
return V_91 ;
}
V_169 . V_60 = V_31 -> V_60 -> V_293 ;
if ( V_169 . V_60 && ! V_169 . V_60 -> V_294 && ! V_253 ) {
if ( F_64 ( V_4 -> V_295 ) ) {
struct V_284 * V_296 = & V_4 -> V_286 ;
F_32 ( L_25
L_26 , V_31 -> V_60 -> V_93 ) ;
V_296 -> V_287 = V_297 ;
V_296 -> V_289 = V_290 ;
V_4 -> V_292 ( V_4 ) ;
} else {
struct V_284 * V_296 = & V_4 -> V_286 ;
F_32 ( L_27
L_26 , V_31 -> V_60 -> V_93 ) ;
V_296 -> V_287 = V_288 ;
V_296 -> V_289 = V_290 ;
V_4 -> V_292 ( V_4 ) ;
}
return V_91 ;
}
if ( ! F_64 ( V_4 -> V_295 ) ) {
if ( V_4 -> V_298 ) {
V_30 = F_45 ( V_2 -> V_31 ,
V_4 -> V_211 ,
V_4 -> V_298 ,
V_4 -> V_227 ) ;
if ( ! V_30 ) {
V_91 = - V_188 ;
goto V_299;
}
}
} else {
V_30 = V_4 -> V_298 ;
}
V_91 = F_7 ( V_2 , & V_5 ) ;
if ( V_91 )
goto V_191;
V_8 = & V_2 -> V_25 [ V_5 ] ;
V_4 -> V_6 = NULL ;
V_8 -> V_30 = V_30 ;
V_8 -> V_9 = V_5 ;
V_8 -> V_44 = F_65 ( V_2 -> V_300 , V_301 , & V_8 -> V_33 ) ;
if ( ! V_8 -> V_44 )
goto V_302;
memset ( V_8 -> V_44 , 0 , V_242 ) ;
V_169 . V_4 = V_4 ;
V_169 . V_171 = & V_2 -> V_8 [ V_5 ] ;
V_169 . V_5 = V_5 ;
V_169 . V_30 = V_30 ;
switch ( V_4 -> V_295 ) {
case V_303 :
V_91 = F_44 ( V_2 , & V_169 ) ;
break;
case V_304 :
V_91 = F_60 ( V_2 , & V_169 , V_251 , V_253 ) ;
break;
case V_305 :
case V_306 :
case V_305 | V_306 :
V_91 = F_55 ( V_2 , & V_169 ) ;
break;
default:
F_13 ( V_307 , V_2 -> V_31 ,
L_28 ,
V_4 -> V_295 ) ;
V_91 = - V_193 ;
break;
}
if ( V_91 ) {
F_32 ( L_29 , V_91 ) ;
goto V_308;
}
V_8 -> V_4 = V_4 ;
V_8 -> V_60 = V_169 . V_60 ;
V_4 -> V_6 = V_8 ;
F_66 ( & V_8 -> V_46 , & V_169 . V_60 -> V_309 ) ;
F_67 ( & V_4 -> V_310 ) ;
V_4 -> V_311 |= V_312 ;
F_68 ( & V_4 -> V_310 ) ;
F_14 ( V_2 , V_5 , V_4 -> V_295 ) ;
V_76 -> V_313 ++ ;
++ ( * V_283 ) ;
V_2 -> V_41 = ( V_2 -> V_41 + 1 ) & ( V_38 - 1 ) ;
return V_91 ;
V_308:
F_69 ( V_2 -> V_300 , V_8 -> V_44 , V_8 -> V_33 ) ;
V_302:
F_4 ( V_2 , V_5 ) ;
V_191:
F_13 ( V_307 , V_2 -> V_31 , L_30 , V_91 ) ;
if ( ! F_64 ( V_4 -> V_295 ) )
if ( V_30 )
F_53 ( V_2 -> V_31 , V_4 -> V_211 , V_30 ,
V_4 -> V_227 ) ;
V_299:
return V_91 ;
}
static struct V_314 * F_70 ( int * V_74 , T_7 V_315 )
{
struct V_314 * V_316 = NULL ;
for (; * V_74 > 0 ; -- * V_74 ) {
struct V_314 * V_317 = F_71 ( V_318 , V_315 ) ;
if ( ! V_317 )
break;
F_72 ( & V_317 -> V_309 ) ;
if ( ! V_316 )
V_316 = V_317 ;
else
F_66 ( & V_317 -> V_309 , & V_316 -> V_309 ) ;
}
return V_316 ;
}
static inline void F_73 ( struct V_314 * V_317 )
{
F_74 ( V_309 ) ;
struct V_319 * V_320 , * V_321 ;
struct V_314 * V_322 = NULL ;
F_75 ( & V_309 , V_317 -> V_309 . V_323 , & V_317 -> V_309 ) ;
F_76 (pos, a, &list) {
F_77 ( V_320 ) ;
V_322 = F_78 ( V_320 , struct V_314 , V_309 ) ;
F_79 ( V_318 , V_322 ) ;
}
}
static int F_80 ( struct V_3 * V_4 , const int V_74 , T_7 V_315 ,
struct V_324 * V_324 , int V_251 ,
struct V_252 * V_253 )
{
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_1 * V_2 = NULL ;
T_1 V_91 = 0 ;
T_1 V_283 = 0 ;
unsigned long V_160 = 0 ;
V_2 = ( (struct V_75 * ) V_4 -> V_31 -> V_77 ) -> V_78 ;
if ( ( V_31 -> V_134 == V_291 ) && ( V_31 -> V_155 . V_154 != NULL ) )
F_81 ( V_31 -> V_155 . V_154 -> V_325 ) ;
F_82 ( & V_2 -> V_325 , V_160 ) ;
V_91 = F_61 ( V_4 , V_2 , V_251 , V_253 , & V_283 ) ;
if ( V_91 )
F_13 ( V_307 , V_2 -> V_31 , L_31 , V_91 ) ;
if ( F_58 ( V_283 ) )
V_28 -> V_326 ( V_2 , ( V_2 -> V_41 - 1 ) &
( V_38 - 1 ) ) ;
F_83 ( & V_2 -> V_325 , V_160 ) ;
if ( ( V_31 -> V_134 == V_291 ) && ( V_31 -> V_155 . V_154 != NULL ) )
F_84 ( V_31 -> V_155 . V_154 -> V_325 ) ;
return V_91 ;
}
static int F_85 ( struct V_3 * V_4 , const int V_74 , T_7 V_315 ,
struct V_324 * V_324 , int V_251 ,
struct V_252 * V_253 )
{
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_69 * V_327 = V_31 -> V_60 -> V_61 -> V_70 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_328 = V_4 ;
struct V_314 * V_317 = NULL , * V_321 ;
F_74 ( V_329 ) ;
int V_283 [ 2 ] = { 0 } ;
T_1 V_91 = 0 ;
T_1 V_73 = V_74 ;
unsigned long V_160 = 0 ;
V_317 = F_70 ( & V_73 , V_315 ) ;
if ( V_73 ) {
F_11 ( V_307 L_32 , V_330 ) ;
V_91 = - V_188 ;
goto V_331;
}
F_75 ( & V_329 , V_317 -> V_309 . V_323 , & V_317 -> V_309 ) ;
F_22 (a, &q, list) {
V_321 -> V_4 = V_328 ;
V_328 = F_78 ( V_328 -> V_309 . V_66 , struct V_3 , V_309 ) ;
}
F_22 (a, &q , list) {
V_328 = V_321 -> V_4 ;
V_2 = ( (struct V_75 * ) V_328 -> V_31 -> V_77 ) -> V_78 ;
F_82 ( & V_2 -> V_325 , V_160 ) ;
V_91 = F_61 ( V_328 , V_2 , V_251 , V_253 , & V_283 [ V_2 -> V_93 ] ) ;
if ( V_91 )
F_13 ( V_307 , V_2 -> V_31 , L_31 , V_91 ) ;
F_83 ( & V_2 -> V_325 , V_160 ) ;
}
if ( F_58 ( V_283 [ 0 ] ) )
V_28 -> V_326 ( V_327 -> V_2 [ 0 ] ,
( V_327 -> V_2 [ 0 ] -> V_41 - 1 ) & ( V_38 - 1 ) ) ;
if ( F_58 ( V_283 [ 1 ] ) )
V_28 -> V_326 ( V_327 -> V_2 [ 1 ] ,
( V_327 -> V_2 [ 1 ] -> V_41 - 1 ) & ( V_38 - 1 ) ) ;
F_77 ( & V_329 ) ;
V_331:
if ( V_317 )
F_73 ( V_317 ) ;
return V_91 ;
}
int F_86 ( struct V_3 * V_4 , const int V_74 ,
T_7 V_315 )
{
struct V_75 * V_76 = V_4 -> V_31 -> V_77 ;
struct V_58 * V_120 = V_76 -> V_78 -> V_120 ;
if ( V_120 -> V_332 < 2 )
return F_80 ( V_4 , V_74 , V_315 , NULL , 0 , NULL ) ;
else
return F_85 ( V_4 , V_74 , V_315 , NULL , 0 , NULL ) ;
}
static void F_87 ( struct V_1 * V_2 , T_1 V_48 )
{
T_1 V_333 = V_48 & V_52 ;
F_2 ( V_2 , V_333 ) ;
}
static void F_88 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , T_1 V_333 )
{
if ( ! V_8 -> V_4 )
return;
if ( ! F_64 ( V_4 -> V_295 ) )
if ( V_8 -> V_30 )
F_53 ( V_2 -> V_31 , V_4 -> V_211 ,
V_8 -> V_30 , V_4 -> V_227 ) ;
switch ( V_4 -> V_295 ) {
case V_303 :
F_53 ( V_2 -> V_31 , & V_4 -> V_185 . V_189 , 1 ,
V_190 ) ;
F_53 ( V_2 -> V_31 , & V_4 -> V_185 . V_186 , 1 ,
V_187 ) ;
break;
case V_305 :
case V_306 :
case V_304 :
default:
break;
}
if ( V_8 -> V_44 ) {
F_69 ( V_2 -> V_300 , V_8 -> V_44 , V_8 -> V_33 ) ;
V_8 -> V_44 = NULL ;
}
F_77 ( & V_8 -> V_46 ) ;
V_4 -> V_6 = NULL ;
V_8 -> V_4 = NULL ;
V_8 -> V_60 = NULL ;
V_8 -> V_9 = 0xFFFFFFFF ;
F_87 ( V_2 , V_333 ) ;
}
static void F_89 ( struct V_1 * V_2 , int V_16 )
{
struct V_113 * V_63 = & V_2 -> V_63 [ V_16 ] ;
struct V_254 * V_60 = V_63 -> V_60 ;
int V_56 , V_86 ;
F_27 (port->wide_port_phymap, j, no) {
if ( V_56 & 1 ) {
V_28 -> V_111 ( V_2 , V_86 ,
V_334 ) ;
V_28 -> V_112 ( V_2 , V_86 ,
V_60 -> V_258 ) ;
} else {
V_28 -> V_111 ( V_2 , V_86 ,
V_334 ) ;
V_28 -> V_112 ( V_2 , V_86 ,
0 ) ;
}
}
}
static T_1 F_90 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_94 ;
struct V_113 * V_63 = & V_2 -> V_63 [ V_16 ] ;
struct V_254 * V_60 = V_63 -> V_60 ;
V_94 = V_28 -> V_98 ( V_2 , V_16 ) ;
if ( ( V_94 & V_335 ) && ! ( V_63 -> V_336 & V_337 ) ) {
if ( ! V_60 )
V_63 -> V_115 = 1 ;
return V_94 ;
}
if ( V_60 ) {
if ( V_63 -> V_118 & V_119 ) {
V_60 -> V_258 &= ~ ( 1U << V_16 ) ;
if ( ! V_60 -> V_258 )
V_60 -> V_294 = 0 ;
F_89 ( V_2 , V_16 ) ;
} else if ( V_63 -> V_118 & V_141 )
V_60 -> V_294 = 0 ;
V_63 -> V_60 = NULL ;
V_63 -> V_115 = 0 ;
V_63 -> V_118 &= ~ ( V_119 | V_141 ) ;
}
return 0 ;
}
static void * F_91 ( struct V_1 * V_2 , int V_16 , void * V_44 )
{
T_1 * V_338 = ( T_1 * ) V_44 ;
if ( ! V_338 )
return NULL ;
V_28 -> V_111 ( V_2 , V_16 , V_339 ) ;
V_338 [ 3 ] = V_28 -> V_340 ( V_2 , V_16 ) ;
V_28 -> V_111 ( V_2 , V_16 , V_341 ) ;
V_338 [ 2 ] = V_28 -> V_340 ( V_2 , V_16 ) ;
V_28 -> V_111 ( V_2 , V_16 , V_342 ) ;
V_338 [ 1 ] = V_28 -> V_340 ( V_2 , V_16 ) ;
V_28 -> V_111 ( V_2 , V_16 , V_343 ) ;
V_338 [ 0 ] = V_28 -> V_340 ( V_2 , V_16 ) ;
if ( ( ( V_338 [ 1 ] & 0x00FFFFFF ) == 0x00EB1401 ) && ( * ( T_2 * ) & V_338 [ 3 ] == 0x01 ) )
V_338 [ 1 ] = 0x00EB1401 | ( * ( ( T_2 * ) & V_338 [ 1 ] + 3 ) & 0x10 ) ;
return V_338 ;
}
static T_1 F_92 ( T_1 V_336 )
{
return V_336 & V_344 ;
}
void F_93 ( struct V_1 * V_2 , int V_16 , int V_345 )
{
struct V_113 * V_63 = & V_2 -> V_63 [ V_16 ] ;
struct V_132 * V_93 ;
V_93 = (struct V_132 * ) V_63 -> V_133 ;
if ( V_345 ) {
V_63 -> V_336 = V_28 -> V_346 ( V_2 , V_16 ) ;
V_63 -> V_347 = F_90 ( V_2 , V_16 ) ;
}
if ( V_63 -> V_347 ) {
int V_348 = 0 ;
struct V_62 * V_68 = & V_2 -> V_63 [ V_16 ] . V_68 ;
V_348 = V_28 -> V_348 ( V_2 , V_16 ) ;
V_28 -> V_349 ( V_2 , V_16 , V_93 ) ;
if ( V_63 -> V_118 & V_141 ) {
V_63 -> V_135 . V_140 = V_306 ;
if ( F_92 ( V_63 -> V_336 ) ) {
V_63 -> V_115 = 1 ;
V_63 -> V_350 =
V_16 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ;
if ( V_348 )
V_68 -> V_351 = V_352 ;
V_63 -> V_142 =
sizeof( struct V_353 ) ;
F_91 ( V_2 , V_16 , V_93 ) ;
} else {
T_1 V_94 ;
F_13 ( V_22 , V_2 -> V_31 ,
L_33 , V_16 ) ;
V_94 = V_28 -> V_354 ( V_2 , V_16 ) ;
V_28 -> V_355 ( V_2 , V_16 ,
V_94 | V_344 ) ;
V_63 -> V_115 = 0 ;
V_63 -> V_118 &= ~ V_141 ;
V_28 -> V_87 ( V_2 , V_16 , 0 ) ;
goto V_356;
}
} else if ( V_63 -> V_118 & V_119
|| V_63 -> V_116 & V_357 ) {
V_63 -> V_115 = 1 ;
V_63 -> V_135 . V_136 =
V_63 -> V_116 & V_358 ;
if ( V_63 -> V_135 . V_136 == V_359 )
V_63 -> V_135 . V_140 =
V_304 ;
else if ( V_63 -> V_135 . V_136 != V_360 )
V_63 -> V_135 . V_140 =
V_303 ;
if ( V_348 )
V_68 -> V_351 = V_361 ;
V_63 -> V_142 =
sizeof( struct V_132 ) ;
}
memcpy ( V_68 -> V_362 ,
& V_63 -> V_350 , V_209 ) ;
if ( V_28 -> V_363 )
V_28 -> V_363 ( V_2 , V_16 ) ;
}
F_32 ( L_34 ,
V_16 + V_2 -> V_93 * V_2 -> V_79 -> V_71 , V_63 -> V_116 ) ;
F_32 ( L_35 ,
V_16 + V_2 -> V_93 * V_2 -> V_79 -> V_71 , V_63 -> V_350 ) ;
V_356:
if ( V_345 )
V_28 -> V_364 ( V_2 , V_16 , V_63 -> V_336 ) ;
}
static void F_94 ( struct V_62 * V_68 , int V_325 )
{
struct V_58 * V_114 = V_68 -> V_61 ;
struct V_1 * V_2 = NULL ; int V_16 = 0 , V_57 ;
struct V_113 * V_63 = V_68 -> V_365 ;
struct V_172 * V_64 = V_68 -> V_60 ;
struct V_254 * V_60 ;
unsigned long V_160 = 0 ;
if ( ! V_64 )
return;
while ( V_114 -> V_68 [ V_16 ] ) {
if ( V_114 -> V_68 [ V_16 ] == V_68 )
break;
V_16 ++ ;
}
V_57 = V_16 / ( (struct V_69 * ) V_114 -> V_70 ) -> V_71 ;
V_2 = ( (struct V_69 * ) V_114 -> V_70 ) -> V_2 [ V_57 ] ;
if ( V_64 -> V_93 >= V_2 -> V_79 -> V_71 )
V_60 = & V_2 -> V_60 [ V_64 -> V_93 - V_2 -> V_79 -> V_71 ] ;
else
V_60 = & V_2 -> V_60 [ V_64 -> V_93 ] ;
if ( V_325 )
F_82 ( & V_2 -> V_325 , V_160 ) ;
V_60 -> V_294 = 1 ;
V_63 -> V_60 = V_60 ;
V_64 -> V_293 = V_60 ;
if ( V_63 -> V_118 & V_119 ) {
V_60 -> V_258 = V_64 -> V_84 ;
F_24 ( L_36 , V_64 -> V_84 ) ;
F_89 ( V_2 , V_68 -> V_93 ) ;
}
if ( V_325 )
F_83 ( & V_2 -> V_325 , V_160 ) ;
}
static void F_95 ( struct V_62 * V_68 , int V_325 )
{
struct V_55 * V_31 ;
struct V_113 * V_63 = V_68 -> V_365 ;
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_172 * V_60 = V_68 -> V_60 ;
int V_366 = 0 ;
while ( V_63 != & V_2 -> V_63 [ V_366 ] ) {
V_366 ++ ;
if ( V_366 >= V_367 )
return;
}
F_22 (dev, &port->dev_list, dev_list_node)
F_96 ( V_63 -> V_2 , V_366 , NULL ) ;
}
void F_97 ( struct V_62 * V_68 )
{
F_94 ( V_68 , 1 ) ;
}
void F_98 ( struct V_62 * V_68 )
{
F_95 ( V_68 , 1 ) ;
}
struct V_75 * F_99 ( struct V_1 * V_2 )
{
T_1 V_31 ;
for ( V_31 = 0 ; V_31 < V_368 ; V_31 ++ ) {
if ( V_2 -> V_369 [ V_31 ] . V_134 == V_360 ) {
V_2 -> V_369 [ V_31 ] . V_223 = V_31 ;
return & V_2 -> V_369 [ V_31 ] ;
}
}
if ( V_31 == V_368 )
F_24 ( L_37 ,
V_368 ) ;
return NULL ;
}
void F_100 ( struct V_75 * V_76 )
{
T_1 V_93 = V_76 -> V_223 ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_223 = V_93 ;
V_76 -> V_134 = V_360 ;
V_76 -> V_370 = V_371 ;
V_76 -> V_80 = V_81 ;
}
int F_101 ( struct V_55 * V_31 , int V_325 )
{
unsigned long V_160 = 0 ;
int V_372 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_55 * V_373 = V_31 -> V_374 ;
struct V_75 * V_375 ;
V_2 = F_19 ( V_31 ) ;
if ( V_325 )
F_82 ( & V_2 -> V_325 , V_160 ) ;
V_375 = F_99 ( V_2 ) ;
if ( ! V_375 ) {
V_372 = - 1 ;
goto V_376;
}
V_31 -> V_77 = V_375 ;
V_375 -> V_370 = V_371 ;
V_375 -> V_134 = V_31 -> V_134 ;
V_375 -> V_78 = V_2 ;
if ( V_373 && F_102 ( V_373 -> V_134 ) ) {
int V_92 ;
T_2 V_377 = V_373 -> V_378 . V_379 ;
struct V_380 * V_63 ;
for ( V_92 = 0 ; V_92 < V_377 ; V_92 ++ ) {
V_63 = & V_373 -> V_378 . V_380 [ V_92 ] ;
if ( F_63 ( V_63 -> V_362 ) ==
F_63 ( V_31 -> V_109 ) ) {
V_375 -> V_381 = V_92 ;
break;
}
}
if ( V_92 == V_377 ) {
F_24 ( L_38
L_39 ,
F_63 ( V_31 -> V_109 ) ,
F_63 ( V_373 -> V_109 ) ) ;
V_372 = - 1 ;
}
}
V_376:
if ( V_325 )
F_83 ( & V_2 -> V_325 , V_160 ) ;
return V_372 ;
}
int F_103 ( struct V_55 * V_31 )
{
return F_101 ( V_31 , 1 ) ;
}
void F_104 ( struct V_55 * V_31 )
{
unsigned long V_160 = 0 ;
struct V_75 * V_76 = V_31 -> V_77 ;
struct V_1 * V_2 = V_76 -> V_78 ;
F_82 ( & V_2 -> V_325 , V_160 ) ;
if ( V_76 ) {
F_32 ( L_40 ,
V_76 -> V_223 , V_76 -> V_134 ) ;
F_105 ( V_2 , V_31 ) ;
F_23 ( V_2 , V_76 ) ;
F_100 ( V_76 ) ;
} else {
F_32 ( L_41 ) ;
}
V_31 -> V_77 = NULL ;
F_83 ( & V_2 -> V_325 , V_160 ) ;
}
void F_106 ( struct V_55 * V_31 )
{
F_104 ( V_31 ) ;
}
static struct V_3 * F_107 ( void )
{
struct V_3 * V_4 = F_108 ( sizeof( struct V_3 ) , V_382 ) ;
if ( V_4 ) {
F_72 ( & V_4 -> V_309 ) ;
F_109 ( & V_4 -> V_310 ) ;
V_4 -> V_311 = V_383 ;
F_110 ( & V_4 -> V_384 ) ;
F_111 ( & V_4 -> V_324 ) ;
}
return V_4 ;
}
static void F_112 ( struct V_3 * V_4 )
{
if ( V_4 ) {
F_113 ( ! F_114 ( & V_4 -> V_309 ) ) ;
F_115 ( V_4 ) ;
}
}
static void F_116 ( struct V_3 * V_4 )
{
if ( ! F_117 ( & V_4 -> V_384 ) )
return;
F_118 ( & V_4 -> V_324 ) ;
}
static void F_119 ( unsigned long V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) V_18 ;
V_4 -> V_311 |= V_385 ;
F_118 ( & V_4 -> V_324 ) ;
}
static int F_120 ( struct V_55 * V_31 ,
void * V_386 , T_1 V_387 , struct V_252 * V_253 )
{
int V_372 , V_388 ;
struct V_3 * V_4 = NULL ;
for ( V_388 = 0 ; V_388 < 3 ; V_388 ++ ) {
V_4 = F_107 () ;
if ( ! V_4 )
return - V_188 ;
V_4 -> V_31 = V_31 ;
V_4 -> V_295 = V_31 -> V_389 ;
memcpy ( & V_4 -> V_262 , V_386 , V_387 ) ;
V_4 -> V_292 = F_116 ;
V_4 -> V_384 . V_18 = ( unsigned long ) V_4 ;
V_4 -> V_384 . V_390 = F_119 ;
V_4 -> V_384 . V_391 = V_392 + V_393 * V_167 ;
F_121 ( & V_4 -> V_384 ) ;
V_372 = F_80 ( V_4 , 1 , V_382 , NULL , 1 , V_253 ) ;
if ( V_372 ) {
F_117 ( & V_4 -> V_384 ) ;
F_24 ( L_42 , V_372 ) ;
goto V_394;
}
F_122 ( & V_4 -> V_324 ) ;
V_372 = - V_395 ;
if ( ( V_4 -> V_311 & V_385 ) ) {
if ( ! ( V_4 -> V_311 & V_396 ) ) {
F_24 ( L_43 , V_253 -> V_253 ) ;
goto V_394;
}
}
if ( V_4 -> V_286 . V_287 == V_297 &&
V_4 -> V_286 . V_289 == V_397 ) {
V_372 = V_398 ;
break;
}
if ( V_4 -> V_286 . V_287 == V_297 &&
V_4 -> V_286 . V_289 == V_399 ) {
V_372 = V_4 -> V_286 . V_400 ;
break;
}
if ( V_4 -> V_286 . V_287 == V_297 &&
V_4 -> V_286 . V_289 == V_401 ) {
F_32 ( L_44 ) ;
V_372 = - V_402 ;
break;
} else {
F_32 ( L_45
L_46 ,
F_63 ( V_31 -> V_109 ) ,
V_4 -> V_286 . V_287 ,
V_4 -> V_286 . V_289 ) ;
F_112 ( V_4 ) ;
V_4 = NULL ;
}
}
V_394:
F_113 ( V_388 == 3 && V_4 != NULL ) ;
if ( V_4 != NULL )
F_112 ( V_4 ) ;
return V_372 ;
}
static int F_123 ( struct V_55 * V_31 ,
T_2 * V_147 , struct V_252 * V_253 )
{
struct V_403 V_262 ;
F_124 ( V_324 ) ;
if ( ! ( V_31 -> V_389 & V_304 ) )
return V_404 ;
strncpy ( ( T_2 * ) & V_262 . V_276 , V_147 , 8 ) ;
return F_120 ( V_31 , & V_262 ,
sizeof( V_262 ) , V_253 ) ;
}
static int F_125 ( struct V_55 * V_31 )
{
int V_91 ;
struct V_68 * V_63 = F_126 ( V_31 ) ;
int V_405 = ( V_31 -> V_134 == V_291 ||
( V_31 -> V_389 & V_306 ) ) ? 0 : 1 ;
V_91 = F_127 ( V_63 , V_405 ) ;
F_29 ( 2000 ) ;
return V_91 ;
}
int F_128 ( struct V_55 * V_31 , T_2 * V_147 )
{
unsigned long V_160 ;
int V_16 , V_72 [ V_406 ] , V_74 , V_91 = V_395 ;
struct V_252 V_407 ;
struct V_75 * V_76 = V_31 -> V_77 ;
struct V_1 * V_2 = V_76 -> V_78 ;
V_407 . V_253 = V_408 ;
V_76 -> V_370 = V_409 ;
V_91 = F_123 ( V_31 , V_147 , & V_407 ) ;
if ( V_91 == V_398 ) {
V_74 = F_21 ( V_31 , V_72 ) ;
F_82 ( & V_2 -> V_325 , V_160 ) ;
for ( V_16 = 0 ; V_16 < V_74 ; V_16 ++ )
F_105 ( V_2 , V_31 ) ;
F_83 ( & V_2 -> V_325 , V_160 ) ;
}
F_24 ( L_47 , V_330 ,
V_76 -> V_223 , V_91 ) ;
return V_91 ;
}
int F_129 ( struct V_55 * V_31 )
{
unsigned long V_160 ;
int V_91 = V_395 ;
struct V_75 * V_76 = (struct V_75 * ) V_31 -> V_77 ;
struct V_1 * V_2 = V_76 -> V_78 ;
if ( V_76 -> V_370 != V_409 )
return V_398 ;
V_91 = F_125 ( V_31 ) ;
F_24 ( L_47 ,
V_330 , V_76 -> V_223 , V_91 ) ;
F_82 ( & V_2 -> V_325 , V_160 ) ;
F_105 ( V_2 , V_31 ) ;
F_83 ( & V_2 -> V_325 , V_160 ) ;
return V_91 ;
}
int F_130 ( struct V_3 * V_4 )
{
T_1 V_5 ;
struct V_410 V_147 ;
struct V_252 V_407 ;
int V_91 = V_395 ;
if ( V_4 -> V_6 && V_4 -> V_295 & V_304 ) {
struct V_411 * V_412 = (struct V_411 * ) V_4 -> V_215 ;
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_75 * V_76 = (struct V_75 * ) V_31 -> V_77 ;
struct V_1 * V_2 = V_76 -> V_78 ;
F_131 ( V_412 -> V_159 -> V_147 , & V_147 ) ;
V_91 = F_1 ( V_2 , V_4 , & V_5 ) ;
if ( V_91 == 0 ) {
V_91 = V_395 ;
return V_91 ;
}
V_407 . V_253 = V_281 ;
V_407 . V_282 = F_132 ( V_5 ) ;
V_91 = F_123 ( V_31 , V_147 . V_410 , & V_407 ) ;
switch ( V_91 ) {
case V_413 :
case V_395 :
case V_398 :
break;
default:
V_91 = V_398 ;
break;
}
}
F_24 ( L_48 , V_330 , V_91 ) ;
return V_91 ;
}
int F_133 ( struct V_3 * V_4 )
{
struct V_410 V_147 ;
struct V_252 V_407 ;
struct V_55 * V_31 = V_4 -> V_31 ;
struct V_75 * V_76 = (struct V_75 * ) V_31 -> V_77 ;
struct V_1 * V_2 ;
int V_91 = V_395 ;
unsigned long V_160 ;
T_1 V_5 ;
if ( ! V_76 ) {
F_24 ( L_49 , V_330 , __LINE__ ) ;
V_91 = V_395 ;
}
V_2 = V_76 -> V_78 ;
F_82 ( & V_4 -> V_310 , V_160 ) ;
if ( V_4 -> V_311 & V_396 ) {
F_83 ( & V_4 -> V_310 , V_160 ) ;
V_91 = V_398 ;
goto V_414;
}
F_83 ( & V_4 -> V_310 , V_160 ) ;
V_76 -> V_370 = V_409 ;
if ( V_4 -> V_6 && V_4 -> V_295 & V_304 ) {
struct V_411 * V_412 = (struct V_411 * ) V_4 -> V_215 ;
F_131 ( V_412 -> V_159 -> V_147 , & V_147 ) ;
V_91 = F_1 ( V_2 , V_4 , & V_5 ) ;
if ( V_91 == 0 ) {
F_24 ( L_50 , V_330 ) ;
V_91 = V_395 ;
return V_91 ;
}
V_407 . V_253 = V_280 ;
V_407 . V_282 = F_132 ( V_5 ) ;
V_91 = F_123 ( V_31 , V_147 . V_410 , & V_407 ) ;
if ( V_91 == V_398 ) {
T_1 V_415 ;
struct V_7 * V_8 ;
if ( V_4 -> V_6 ) {
V_8 = V_4 -> V_6 ;
V_415 = ( T_1 ) ( V_8 - V_2 -> V_25 ) ;
F_82 ( & V_2 -> V_325 , V_160 ) ;
F_134 ( V_2 , V_415 , 1 ) ;
F_83 ( & V_2 -> V_325 , V_160 ) ;
}
}
} else if ( V_4 -> V_295 & V_305 ||
V_4 -> V_295 & V_306 ) {
if ( V_291 == V_31 -> V_134 ) {
struct V_7 * V_8 = V_4 -> V_6 ;
struct V_284 * V_416 ;
T_1 V_333 = ( T_1 ) ( V_8 - V_2 -> V_25 ) ;
V_416 = & V_4 -> V_286 ;
F_32 ( V_22 L_51
L_52 ,
V_2 , V_4 , V_8 , V_333 ) ;
V_416 -> V_289 = V_417 ;
if ( V_76 && V_76 -> V_313 )
V_76 -> V_313 -- ;
if ( F_64 ( V_4 -> V_295 ) )
F_23 ( V_2 , V_76 ) ;
F_88 ( V_2 , V_4 , V_8 , V_333 ) ;
return - 1 ;
}
} else {
}
V_414:
if ( V_91 != V_398 )
F_24 ( L_48 , V_330 , V_91 ) ;
return V_91 ;
}
int F_135 ( struct V_55 * V_31 , T_2 * V_147 )
{
int V_91 = V_395 ;
struct V_252 V_407 ;
V_407 . V_253 = V_418 ;
V_91 = F_123 ( V_31 , V_147 , & V_407 ) ;
return V_91 ;
}
int F_136 ( struct V_55 * V_31 , T_2 * V_147 )
{
int V_91 = V_395 ;
struct V_252 V_407 ;
V_407 . V_253 = V_419 ;
V_91 = F_123 ( V_31 , V_147 , & V_407 ) ;
return V_91 ;
}
int F_137 ( struct V_55 * V_31 , T_2 * V_147 )
{
int V_91 = V_395 ;
struct V_252 V_407 ;
V_407 . V_253 = V_420 ;
V_91 = F_123 ( V_31 , V_147 , & V_407 ) ;
return V_91 ;
}
static int F_138 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_333 , int V_421 )
{
struct V_75 * V_76 = V_4 -> V_31 -> V_77 ;
struct V_284 * V_416 = & V_4 -> V_286 ;
struct V_422 * V_287 = (struct V_422 * ) V_416 -> V_44 ;
int V_289 = V_397 ;
V_287 -> V_423 = sizeof( struct V_353 ) ;
memcpy ( & V_287 -> V_424 [ 0 ] ,
F_139 ( V_76 -> V_80 ) ,
sizeof( struct V_353 ) ) ;
V_416 -> V_425 = sizeof( * V_287 ) ;
if ( F_140 ( V_421 ) ) {
if ( F_140 ( V_421 & V_426 ) )
V_289 = V_427 ;
else
V_289 = V_428 ;
}
return V_289 ;
}
static int F_141 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_333 )
{
struct V_7 * V_8 = & V_2 -> V_25 [ V_333 ] ;
int V_289 ;
T_1 V_429 = F_16 ( * ( T_1 * ) ( V_8 -> V_32 ) ) ;
T_1 V_430 = 0 ;
enum V_431 type = V_119 ;
if ( V_429 & V_426 )
V_28 -> V_432 ( V_2 , type , V_430 ) ;
V_28 -> V_433 ( V_2 , V_333 ) ;
V_289 = V_434 ;
switch ( V_4 -> V_295 ) {
case V_304 :
V_289 = V_417 ;
break;
case V_303 :
V_289 = V_434 ;
break;
case V_305 :
case V_306 :
case V_305 | V_306 :
{
if ( V_429 == 0x80400002 )
F_24 ( L_53 ) ;
V_4 -> V_230 . V_231 = 0 ;
F_138 ( V_2 , V_4 , V_333 , V_429 ) ;
}
break;
default:
break;
}
return V_289 ;
}
int F_134 ( struct V_1 * V_2 , T_1 V_48 , T_1 V_160 )
{
T_1 V_333 = V_48 & V_52 ;
struct V_7 * V_8 = & V_2 -> V_25 [ V_333 ] ;
struct V_3 * V_4 = V_8 -> V_4 ;
struct V_75 * V_76 = NULL ;
struct V_284 * V_416 ;
struct V_55 * V_31 ;
T_1 V_435 ;
void * V_436 ;
enum V_437 V_438 ;
if ( V_2 -> V_439 )
V_2 -> V_439 -- ;
if ( F_140 ( ! V_4 || ! V_4 -> V_6 || ! V_4 -> V_31 ) )
return - 1 ;
V_416 = & V_4 -> V_286 ;
V_31 = V_4 -> V_31 ;
V_76 = V_31 -> V_77 ;
F_15 ( V_2 ) ;
F_67 ( & V_4 -> V_310 ) ;
V_4 -> V_311 &=
~ ( V_383 | V_312 ) ;
V_4 -> V_311 |= V_396 ;
V_435 = V_4 -> V_311 & V_385 ;
F_68 ( & V_4 -> V_310 ) ;
memset ( V_416 , 0 , sizeof( * V_416 ) ) ;
V_416 -> V_287 = V_297 ;
if ( F_140 ( V_435 ) ) {
V_416 -> V_289 = V_417 ;
if ( V_76 && V_76 -> V_313 )
V_76 -> V_313 -- ;
if ( F_64 ( V_4 -> V_295 ) )
F_23 ( V_2 , V_76 ) ;
F_88 ( V_2 , V_4 , V_8 , V_333 ) ;
return - 1 ;
}
if ( F_140 ( ! V_76 || V_160 ) ) {
if ( ! V_76 )
F_32 ( L_54 ) ;
V_416 -> V_289 = V_290 ;
goto V_414;
}
if ( F_140 ( ( V_48 & V_440 ) && ( * ( T_3 * ) V_8 -> V_32 ) ) ) {
V_416 -> V_289 = F_141 ( V_2 , V_4 , V_333 ) ;
V_416 -> V_287 = V_297 ;
goto V_414;
}
switch ( V_4 -> V_295 ) {
case V_304 :
if ( V_48 & V_441 ) {
V_416 -> V_289 = V_397 ;
V_416 -> V_287 = V_297 ;
}
else if ( V_48 & V_442 ) {
struct V_443 * V_444 = V_8 -> V_32 +
sizeof( struct V_243 ) ;
F_142 ( V_2 -> V_31 , V_4 , V_444 ) ;
} else
V_416 -> V_289 = V_434 ;
break;
case V_303 : {
struct V_173 * V_175 = & V_4 -> V_185 . V_189 ;
V_416 -> V_289 = V_397 ;
V_436 = F_50 ( F_51 ( V_175 ) , V_212 ) ;
memcpy ( V_436 + V_175 -> V_21 ,
V_8 -> V_32 + sizeof( struct V_243 ) ,
F_46 ( V_175 ) ) ;
F_52 ( V_436 , V_212 ) ;
break;
}
case V_305 :
case V_306 :
case V_305 | V_306 : {
V_416 -> V_289 = F_138 ( V_2 , V_4 , V_333 , 0 ) ;
break;
}
default:
V_416 -> V_289 = V_434 ;
break;
}
if ( ! V_8 -> V_60 -> V_294 ) {
F_32 ( L_55 , V_8 -> V_60 -> V_64 . V_93 ) ;
V_416 -> V_289 = V_290 ;
}
V_414:
if ( V_76 && V_76 -> V_313 ) {
V_76 -> V_313 -- ;
if ( F_64 ( V_4 -> V_295 ) && ! V_76 -> V_313 )
F_23 ( V_2 , V_76 ) ;
}
F_88 ( V_2 , V_4 , V_8 , V_333 ) ;
V_438 = V_416 -> V_289 ;
F_68 ( & V_2 -> V_325 ) ;
if ( V_4 -> V_292 )
V_4 -> V_292 ( V_4 ) ;
else
F_32 ( L_56 ) ;
F_67 ( & V_2 -> V_325 ) ;
return V_438 ;
}
void F_96 ( struct V_1 * V_2 ,
int V_366 , struct V_55 * V_31 )
{
T_1 V_333 ;
struct V_113 * V_63 ;
struct V_254 * V_60 ;
struct V_7 * V_8 , * V_445 ;
V_63 = & V_2 -> V_63 [ V_366 ] ;
V_60 = V_63 -> V_60 ;
if ( ! V_60 )
return;
F_143 ( V_2 , false ) ;
F_144 (slot, slot2, &port->list, entry) {
struct V_3 * V_4 ;
V_333 = ( T_1 ) ( V_8 - V_2 -> V_25 ) ;
V_4 = V_8 -> V_4 ;
if ( V_31 && V_4 -> V_31 != V_31 )
continue;
F_24 ( L_57 ,
V_333 , V_8 -> V_9 , V_4 ) ;
V_28 -> V_433 ( V_2 , V_333 ) ;
F_134 ( V_2 , V_333 , 1 ) ;
}
}
void F_105 ( struct V_1 * V_2 ,
struct V_55 * V_31 )
{
int V_16 , V_72 [ V_406 ] , V_74 ;
V_74 = F_21 ( V_31 , V_72 ) ;
for ( V_16 = 0 ; V_16 < V_74 ; V_16 ++ )
F_96 ( V_2 , V_72 [ V_16 ] , V_31 ) ;
}
static void F_145 ( struct V_113 * V_63 )
{
V_63 -> V_115 = 0 ;
V_63 -> V_116 = 0 ;
V_63 -> V_350 = 0 ;
}
static void F_146 ( struct V_446 * V_447 )
{
struct V_448 * V_449 = F_20 ( V_447 , struct V_448 , V_447 ) ;
struct V_450 * V_451 = F_20 ( V_449 , struct V_450 , V_452 ) ;
struct V_1 * V_2 = V_451 -> V_2 ;
unsigned long V_160 ;
F_82 ( & V_2 -> V_325 , V_160 ) ;
if ( V_451 -> V_453 & V_454 ) {
T_1 V_366 = ( unsigned long ) V_451 -> V_18 ;
struct V_58 * V_114 = V_2 -> V_120 ;
struct V_113 * V_63 = & V_2 -> V_63 [ V_366 ] ;
struct V_62 * V_68 = & V_63 -> V_68 ;
if ( V_63 -> V_455 & V_456 ) {
T_1 V_94 ;
struct V_132 * V_93 ;
V_93 = (struct V_132 * ) V_63 -> V_133 ;
V_94 = V_28 -> V_98 ( V_2 , V_366 ) ;
V_63 -> V_455 &= ~ V_456 ;
if ( ! ( V_94 & V_335 ) ) {
F_147 ( V_68 ) ;
F_145 ( V_63 ) ;
V_114 -> V_121 ( V_68 ,
V_457 ) ;
F_32 ( L_58 , V_366 ) ;
} else {
V_28 -> V_458 ( V_2 , V_366 ) ;
F_93 ( V_2 , V_366 , 1 ) ;
F_31 ( V_2 , V_366 ) ;
F_94 ( V_68 , 0 ) ;
F_32 ( L_59 , V_366 ) ;
}
}
}
F_148 ( & V_451 -> V_46 ) ;
F_83 ( & V_2 -> V_325 , V_160 ) ;
F_115 ( V_451 ) ;
}
static int F_149 ( struct V_1 * V_2 , void * V_18 , int V_453 )
{
struct V_450 * V_451 ;
int V_151 = 0 ;
V_451 = F_150 ( sizeof( struct V_450 ) , V_301 ) ;
if ( V_451 ) {
V_451 -> V_2 = V_2 ;
V_451 -> V_18 = V_18 ;
V_451 -> V_453 = V_453 ;
F_151 ( & V_451 -> V_452 , F_146 , V_451 ) ;
F_66 ( & V_451 -> V_46 , & V_2 -> V_459 ) ;
F_152 ( & V_451 -> V_452 , V_167 * 2 ) ;
} else
V_151 = - V_188 ;
return V_151 ;
}
static void F_153 ( unsigned long V_460 )
{
struct V_113 * V_63 = (struct V_113 * ) V_460 ;
struct V_1 * V_2 = V_63 -> V_2 ;
T_2 V_366 ;
for ( V_366 = 0 ; V_366 < V_2 -> V_79 -> V_71 ; V_366 ++ ) {
if ( & V_2 -> V_63 [ V_366 ] == V_63 ) {
F_32 ( L_60 ,
V_366 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ) ;
V_28 -> V_87 ( V_2 , V_366 , 1 ) ;
}
}
}
static void F_154 ( struct V_113 * V_63 )
{
if ( V_63 -> V_384 . V_390 )
F_117 ( & V_63 -> V_384 ) ;
V_63 -> V_384 . V_390 = NULL ;
}
void F_155 ( struct V_1 * V_2 , int V_366 , T_1 V_461 )
{
T_1 V_94 ;
struct V_58 * V_114 = V_2 -> V_120 ;
struct V_113 * V_63 = & V_2 -> V_63 [ V_366 ] ;
struct V_62 * V_68 = & V_63 -> V_68 ;
V_63 -> V_336 = V_28 -> V_346 ( V_2 , V_366 ) ;
F_32 ( L_61 , V_366 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ,
V_28 -> V_98 ( V_2 , V_366 ) ) ;
F_32 ( L_62 , V_366 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ,
V_63 -> V_336 ) ;
if ( V_63 -> V_336 & V_462 ) {
F_32 ( L_63 ,
V_366 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ) ;
}
if ( V_63 -> V_336 & V_337 ) {
if ( ! ( V_63 -> V_455 & V_456 ) ) {
int V_463 = V_63 -> V_118 & V_141 ;
int V_464 ;
F_96 ( V_2 , V_366 , NULL ) ;
V_63 -> V_455 |= V_456 ;
V_28 -> V_465 ( V_2 , 0 , 1 ) ;
F_149 ( V_2 ,
( void * ) ( unsigned long ) V_366 ,
V_454 ) ;
V_464 = F_90 ( V_2 , V_366 ) ;
if ( ! V_464 )
F_32 ( L_64 ,
V_366 +
V_2 -> V_93 * V_2 -> V_79 -> V_71 ) ;
if ( V_464 || V_463 ) {
if ( V_28 -> V_466 )
V_28 -> V_466 ( V_2 ,
V_366 ) ;
else
V_28 -> V_87 ( V_2 ,
V_366 , 0 ) ;
return;
}
}
}
if ( V_63 -> V_336 & V_467 ) {
V_94 = V_28 -> V_354 ( V_2 , V_366 ) ;
V_28 -> V_355 ( V_2 , V_366 ,
V_94 | V_344 ) ;
if ( V_63 -> V_384 . V_390 == NULL ) {
V_63 -> V_384 . V_18 = ( unsigned long ) V_63 ;
V_63 -> V_384 . V_390 = F_153 ;
V_63 -> V_384 . V_391 = V_392 + 10 * V_167 ;
F_121 ( & V_63 -> V_384 ) ;
}
}
if ( V_63 -> V_336 & ( V_344 | V_468 ) ) {
V_63 -> V_347 = F_90 ( V_2 , V_366 ) ;
F_154 ( V_63 ) ;
F_32 ( L_65 , V_366 ) ;
if ( V_63 -> V_347 ) {
F_156 ( 10 ) ;
V_28 -> V_458 ( V_2 , V_366 ) ;
if ( V_63 -> V_118 & V_141 ) {
V_94 = V_28 -> V_354 (
V_2 , V_366 ) ;
V_94 &= ~ V_344 ;
V_28 -> V_355 ( V_2 ,
V_366 , V_94 ) ;
}
F_93 ( V_2 , V_366 , 0 ) ;
if ( V_63 -> V_118 & V_119 ) {
V_28 -> V_87 ( V_2 , V_366 , 2 ) ;
F_156 ( 10 ) ;
}
F_31 ( V_2 , V_366 ) ;
if ( V_63 -> V_455 & V_456 ) {
F_94 ( V_68 , 0 ) ;
V_63 -> V_455 &= ~ V_456 ;
}
} else {
F_32 ( L_66 ,
V_366 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ) ;
}
} else if ( V_63 -> V_336 & V_469 ) {
F_32 ( L_67 ,
V_366 + V_2 -> V_93 * V_2 -> V_79 -> V_71 ) ;
F_156 ( 1000 ) ;
V_114 -> V_143 ( V_68 , V_470 ) ;
}
V_28 -> V_364 ( V_2 , V_366 , V_63 -> V_336 ) ;
}
int F_143 ( struct V_1 * V_2 , bool V_471 )
{
T_1 V_472 , V_48 ;
bool V_473 = false ;
V_472 = V_2 -> V_47 ;
V_2 -> V_47 = F_16 ( V_2 -> V_49 [ 0 ] ) ;
if ( V_2 -> V_47 == 0xfff )
return 0 ;
if ( F_140 ( V_2 -> V_47 == V_472 ) )
V_2 -> V_47 = V_28 -> V_474 ( V_2 ) & V_475 ;
if ( V_2 -> V_47 == V_472 )
return 0 ;
while ( V_2 -> V_47 != V_472 ) {
V_472 = ( V_472 + 1 ) & ( V_476 - 1 ) ;
V_48 = F_16 ( V_2 -> V_49 [ V_472 + 1 ] ) ;
if ( F_58 ( V_48 & V_477 ) )
F_134 ( V_2 , V_48 , 0 ) ;
if ( V_48 & V_478 ) {
V_473 = true ;
} else if ( V_48 & V_440 ) {
if ( ! ( V_48 & V_477 ) )
F_134 ( V_2 , V_48 , 0 ) ;
} else if ( V_48 & V_479 ) {
F_87 ( V_2 , V_48 ) ;
}
}
if ( V_473 && V_471 )
V_28 -> V_480 ( V_2 ) ;
return 0 ;
}
