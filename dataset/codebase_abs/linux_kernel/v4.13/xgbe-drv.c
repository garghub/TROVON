static void * F_1 ( T_1 V_1 , int V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_1 , V_4 , V_2 ) ;
if ( ! V_3 )
V_3 = F_3 ( V_1 , V_4 ) ;
return V_3 ;
}
static void F_4 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_6 -> V_8 ) ; V_7 ++ ) {
if ( ! V_6 -> V_8 [ V_7 ] )
continue;
F_6 ( V_6 -> V_8 [ V_7 ] -> V_9 ) ;
F_6 ( V_6 -> V_8 [ V_7 ] -> V_10 ) ;
F_6 ( V_6 -> V_8 [ V_7 ] ) ;
V_6 -> V_8 [ V_7 ] = NULL ;
}
V_6 -> V_11 = 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_12 * V_8 ;
struct V_13 * V_14 ;
unsigned int V_15 , V_7 ;
unsigned int V_16 ;
int V_2 ;
V_15 = F_8 (unsigned int, pdata->tx_ring_count, pdata->rx_ring_count) ;
for ( V_7 = 0 ; V_7 < V_15 ; V_7 ++ ) {
V_16 = F_9 ( V_7 , F_10 ( V_6 -> V_17 ) ) ;
V_2 = F_11 ( V_16 ) ;
V_8 = F_1 ( sizeof( * V_8 ) , V_2 ) ;
if ( ! V_8 )
goto V_18;
V_6 -> V_8 [ V_7 ] = V_8 ;
snprintf ( V_8 -> V_19 , sizeof( V_8 -> V_19 ) , L_1 , V_7 ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_20 = V_7 ;
V_8 -> V_21 = V_6 -> V_22 + V_23 +
( V_24 * V_7 ) ;
V_8 -> V_2 = V_2 ;
F_12 ( V_16 , & V_8 -> V_25 ) ;
if ( V_6 -> V_26 )
V_8 -> V_27 = V_6 -> V_28 [ V_7 ] ;
if ( V_7 < V_6 -> V_29 ) {
V_14 = F_1 ( sizeof( * V_14 ) , V_2 ) ;
if ( ! V_14 )
goto V_18;
F_13 ( & V_14 -> V_30 ) ;
V_14 -> V_2 = V_2 ;
V_8 -> V_10 = V_14 ;
}
if ( V_7 < V_6 -> V_31 ) {
V_14 = F_1 ( sizeof( * V_14 ) , V_2 ) ;
if ( ! V_14 )
goto V_18;
F_13 ( & V_14 -> V_30 ) ;
V_14 -> V_2 = V_2 ;
V_8 -> V_9 = V_14 ;
}
F_14 ( V_6 , V_32 , V_6 -> V_33 ,
L_2 , V_8 -> V_19 , V_16 , V_2 ) ;
F_14 ( V_6 , V_32 , V_6 -> V_33 ,
L_3 ,
V_8 -> V_19 , V_8 -> V_21 , V_8 -> V_27 ,
V_8 -> V_10 , V_8 -> V_9 ) ;
}
V_6 -> V_11 = V_15 ;
return 0 ;
V_18:
F_4 ( V_6 ) ;
return - V_34 ;
}
static inline unsigned int F_15 ( struct V_13 * V_14 )
{
return ( V_14 -> V_35 - ( V_14 -> V_36 - V_14 -> V_37 ) ) ;
}
static inline unsigned int F_16 ( struct V_13 * V_14 )
{
return ( V_14 -> V_36 - V_14 -> V_37 ) ;
}
static int F_17 ( struct V_12 * V_8 ,
struct V_13 * V_14 , unsigned int V_15 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
if ( V_15 > F_15 ( V_14 ) ) {
F_18 ( V_6 , V_32 , V_6 -> V_33 ,
L_4 ) ;
F_19 ( V_6 -> V_33 , V_8 -> V_20 ) ;
V_14 -> V_38 . V_39 = 1 ;
if ( V_14 -> V_38 . V_40 )
V_6 -> V_41 . V_42 ( V_8 , V_14 ) ;
return V_43 ;
}
return 0 ;
}
static int F_20 ( struct V_44 * V_33 , unsigned int V_45 )
{
unsigned int V_46 ;
V_46 = V_45 + V_47 + V_48 + V_49 ;
V_46 = F_21 ( V_46 , V_50 , V_51 ) ;
V_46 = ( V_46 + V_52 - 1 ) &
~ ( V_52 - 1 ) ;
return V_46 ;
}
static void F_22 ( struct V_5 * V_6 ,
struct V_12 * V_8 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
enum V_54 V_55 ;
if ( V_8 -> V_10 && V_8 -> V_9 )
V_55 = V_56 ;
else if ( V_8 -> V_10 )
V_55 = V_57 ;
else if ( V_8 -> V_9 )
V_55 = V_58 ;
else
return;
V_41 -> V_59 ( V_8 , V_55 ) ;
}
static void F_23 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ )
F_22 ( V_6 , V_6 -> V_8 [ V_7 ] ) ;
}
static void F_24 ( struct V_5 * V_6 ,
struct V_12 * V_8 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
enum V_54 V_55 ;
if ( V_8 -> V_10 && V_8 -> V_9 )
V_55 = V_56 ;
else if ( V_8 -> V_10 )
V_55 = V_57 ;
else if ( V_8 -> V_9 )
V_55 = V_58 ;
else
return;
V_41 -> V_60 ( V_8 , V_55 ) ;
}
static void F_25 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ )
F_24 ( V_6 , V_6 -> V_8 [ V_7 ] ) ;
}
static bool F_26 ( struct V_5 * V_6 , unsigned long * V_61 ,
unsigned int * V_15 , const char * V_62 )
{
if ( F_27 ( V_63 , * V_61 ) ) {
( * V_15 ) ++ ;
} else {
* V_61 = V_63 + ( V_64 * V_65 ) ;
* V_15 = 1 ;
}
if ( * V_15 > V_66 )
F_28 ( V_6 -> V_17 ,
L_5 ,
V_62 ) ;
if ( * V_15 > V_67 ) {
F_28 ( V_6 -> V_17 ,
L_6 ,
V_62 ) ;
return true ;
}
return false ;
}
static bool F_29 ( struct V_5 * V_6 , unsigned long * V_61 ,
unsigned int * V_15 , const char * V_62 )
{
if ( F_27 ( V_63 , * V_61 ) ) {
( * V_15 ) ++ ;
} else {
* V_61 = V_63 + ( V_68 * V_65 ) ;
* V_15 = 1 ;
}
if ( * V_15 > V_69 ) {
F_30 ( V_6 -> V_33 ,
L_7 ,
V_62 ) ;
return true ;
}
return false ;
}
static void F_31 ( unsigned long V_70 )
{
struct V_5 * V_6 = (struct V_5 * ) V_70 ;
unsigned int V_71 ;
bool V_72 = false ;
V_71 = F_32 ( V_6 , V_73 ) ;
V_71 &= F_32 ( V_6 , V_74 ) ;
F_14 ( V_6 , V_75 , V_6 -> V_33 , L_8 , V_71 ) ;
if ( F_33 ( V_71 , V_73 , V_76 ) ) {
V_72 |= F_29 ( V_6 , & V_6 -> V_77 ,
& V_6 -> V_78 , L_9 ) ;
}
if ( F_33 ( V_71 , V_73 , V_79 ) ) {
V_72 |= F_29 ( V_6 , & V_6 -> V_80 ,
& V_6 -> V_81 , L_10 ) ;
}
if ( F_33 ( V_71 , V_73 , V_82 ) ) {
V_72 |= F_29 ( V_6 , & V_6 -> V_83 ,
& V_6 -> V_84 ,
L_11 ) ;
}
if ( V_72 ) {
V_6 -> V_41 . V_85 ( V_6 ) ;
F_34 ( & V_6 -> V_86 ) ;
goto V_87;
}
if ( F_33 ( V_71 , V_73 , V_88 ) ) {
if ( F_26 ( V_6 , & V_6 -> V_89 ,
& V_6 -> V_90 , L_9 ) )
V_6 -> V_41 . V_91 ( V_6 , V_92 ) ;
}
if ( F_33 ( V_71 , V_73 , V_93 ) )
if ( F_26 ( V_6 , & V_6 -> V_94 ,
& V_6 -> V_95 , L_10 ) )
V_6 -> V_41 . V_91 ( V_6 , V_96 ) ;
if ( F_33 ( V_71 , V_73 , V_97 ) )
if ( F_26 ( V_6 , & V_6 -> V_98 ,
& V_6 -> V_99 , L_11 ) )
V_6 -> V_41 . V_91 ( V_6 , V_100 ) ;
V_87:
F_35 ( V_6 , V_73 , V_71 ) ;
if ( V_6 -> V_101 -> V_102 )
F_35 ( V_6 , V_103 , 1 << 1 ) ;
}
static T_2 F_36 ( int V_104 , void * V_70 )
{
struct V_5 * V_6 = V_70 ;
if ( V_6 -> V_105 )
F_37 ( & V_6 -> V_106 ) ;
else
F_31 ( ( unsigned long ) V_6 ) ;
return V_107 ;
}
static void F_38 ( unsigned long V_70 )
{
struct V_5 * V_6 = (struct V_5 * ) V_70 ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_12 * V_8 ;
unsigned int V_108 , V_109 ;
unsigned int V_110 , V_111 , V_112 ;
unsigned int V_7 ;
V_108 = F_39 ( V_6 , V_113 ) ;
if ( ! V_108 )
goto V_114;
F_14 ( V_6 , V_75 , V_6 -> V_33 , L_12 , V_108 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
if ( ! ( V_108 & ( 1 << V_7 ) ) )
continue;
V_8 = V_6 -> V_8 [ V_7 ] ;
V_109 = F_40 ( V_8 , V_115 ) ;
F_14 ( V_6 , V_75 , V_6 -> V_33 , L_13 ,
V_7 , V_109 ) ;
if ( ! V_6 -> V_26 &&
( F_41 ( V_109 , V_115 , V_116 ) ||
F_41 ( V_109 , V_115 , V_117 ) ) ) {
if ( F_42 ( & V_6 -> V_118 ) ) {
F_25 ( V_6 ) ;
F_43 ( & V_6 -> V_118 ) ;
}
} else {
F_44 ( V_109 , V_115 , V_116 , 0 ) ;
F_44 ( V_109 , V_115 , V_117 , 0 ) ;
}
if ( F_41 ( V_109 , V_115 , V_119 ) )
V_6 -> V_120 . V_121 ++ ;
if ( F_41 ( V_109 , V_115 , V_122 ) )
F_34 ( & V_6 -> V_123 ) ;
F_45 ( V_8 , V_115 , V_109 ) ;
}
if ( F_41 ( V_108 , V_113 , V_124 ) ) {
V_110 = F_39 ( V_6 , V_125 ) ;
F_14 ( V_6 , V_75 , V_6 -> V_33 , L_14 ,
V_110 ) ;
if ( F_41 ( V_110 , V_125 , V_126 ) )
V_41 -> V_127 ( V_6 ) ;
if ( F_41 ( V_110 , V_125 , V_128 ) )
V_41 -> V_129 ( V_6 ) ;
if ( F_41 ( V_110 , V_125 , V_130 ) ) {
V_111 = F_39 ( V_6 , V_131 ) ;
F_14 ( V_6 , V_75 , V_6 -> V_33 ,
L_15 , V_111 ) ;
if ( F_41 ( V_111 , V_131 , V_132 ) ) {
V_6 -> V_133 =
V_41 -> V_134 ( V_6 ) ;
F_46 ( V_6 -> V_135 ,
& V_6 -> V_136 ) ;
}
}
if ( F_41 ( V_110 , V_125 , V_137 ) ) {
V_112 = F_39 ( V_6 , V_138 ) ;
F_14 ( V_6 , V_75 , V_6 -> V_33 ,
L_16 , V_112 ) ;
if ( F_41 ( V_112 , V_138 ,
V_139 ) )
F_47 ( & V_6 -> V_140 ) ;
}
}
V_114:
if ( V_6 -> V_141 == V_6 -> V_142 )
V_6 -> V_143 . V_144 ( V_6 ) ;
if ( V_6 -> V_101 -> V_145 && ( V_6 -> V_141 == V_6 -> V_146 ) )
F_31 ( ( unsigned long ) V_6 ) ;
if ( V_6 -> V_101 -> V_147 && ( V_6 -> V_141 == V_6 -> V_148 ) )
V_6 -> V_149 . V_150 ( V_6 ) ;
if ( V_6 -> V_101 -> V_102 ) {
unsigned int V_151 ;
V_151 = 1 << 0 ;
if ( ! V_6 -> V_26 )
V_151 |= 0xffff < 4 ;
F_35 ( V_6 , V_103 , V_151 ) ;
}
}
static T_2 F_48 ( int V_104 , void * V_70 )
{
struct V_5 * V_6 = V_70 ;
if ( V_6 -> V_105 )
F_37 ( & V_6 -> V_152 ) ;
else
F_38 ( ( unsigned long ) V_6 ) ;
return V_107 ;
}
static T_2 F_49 ( int V_104 , void * V_70 )
{
struct V_12 * V_8 = V_70 ;
struct V_5 * V_6 = V_8 -> V_6 ;
unsigned int V_153 ;
if ( F_42 ( & V_8 -> V_118 ) ) {
if ( V_6 -> V_154 )
F_24 ( V_6 , V_8 ) ;
else
F_50 ( V_8 -> V_27 ) ;
F_43 ( & V_8 -> V_118 ) ;
}
V_153 = 0 ;
F_44 ( V_153 , V_115 , V_116 , 1 ) ;
F_44 ( V_153 , V_115 , V_117 , 1 ) ;
F_45 ( V_8 , V_115 , V_153 ) ;
return V_107 ;
}
static void F_51 ( unsigned long V_70 )
{
struct V_12 * V_8 = (struct V_12 * ) V_70 ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_155 * V_118 ;
F_52 ( L_17 ) ;
V_118 = ( V_6 -> V_26 ) ? & V_8 -> V_118 : & V_6 -> V_118 ;
if ( F_42 ( V_118 ) ) {
if ( V_6 -> V_26 )
if ( V_6 -> V_154 )
F_24 ( V_6 , V_8 ) ;
else
F_50 ( V_8 -> V_27 ) ;
else
F_25 ( V_6 ) ;
F_53 ( V_118 ) ;
}
V_8 -> V_156 = 0 ;
F_52 ( L_18 ) ;
}
static void F_54 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = F_55 ( V_158 ,
struct V_5 ,
V_159 ) ;
V_6 -> V_143 . V_160 ( V_6 ) ;
}
static void F_56 ( unsigned long V_70 )
{
struct V_5 * V_6 = (struct V_5 * ) V_70 ;
F_46 ( V_6 -> V_135 , & V_6 -> V_159 ) ;
F_57 ( & V_6 -> V_161 , V_63 + V_65 ) ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
F_59 ( & V_6 -> V_161 , F_56 ,
( unsigned long ) V_6 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
if ( ! V_8 -> V_10 )
break;
F_59 ( & V_8 -> V_162 , F_51 ,
( unsigned long ) V_8 ) ;
}
}
static void F_60 ( struct V_5 * V_6 )
{
F_57 ( & V_6 -> V_161 , V_63 + V_65 ) ;
}
static void F_61 ( struct V_5 * V_6 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
F_62 ( & V_6 -> V_161 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
if ( ! V_8 -> V_10 )
break;
F_62 ( & V_8 -> V_162 ) ;
}
}
void F_63 ( struct V_5 * V_6 )
{
unsigned int V_163 , V_164 , V_165 ;
struct V_166 * V_167 = & V_6 -> V_167 ;
F_52 ( L_19 ) ;
V_163 = F_39 ( V_6 , V_168 ) ;
V_164 = F_39 ( V_6 , V_169 ) ;
V_165 = F_39 ( V_6 , V_170 ) ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
V_167 -> V_171 = F_39 ( V_6 , V_172 ) ;
V_167 -> V_173 = F_41 ( V_163 , V_168 , V_174 ) ;
V_167 -> V_175 = F_41 ( V_163 , V_168 , V_176 ) ;
V_167 -> V_177 = F_41 ( V_163 , V_168 , V_178 ) ;
V_167 -> V_179 = F_41 ( V_163 , V_168 , V_180 ) ;
V_167 -> V_181 = F_41 ( V_163 , V_168 , V_182 ) ;
V_167 -> V_183 = F_41 ( V_163 , V_168 , V_184 ) ;
V_167 -> V_185 = F_41 ( V_163 , V_168 , V_186 ) ;
V_167 -> V_187 = F_41 ( V_163 , V_168 , V_188 ) ;
V_167 -> V_189 = F_41 ( V_163 , V_168 , V_190 ) ;
V_167 -> V_191 = F_41 ( V_163 , V_168 , V_192 ) ;
V_167 -> V_193 = F_41 ( V_163 , V_168 , V_194 ) ;
V_167 -> V_195 = F_41 ( V_163 , V_168 ,
V_196 ) ;
V_167 -> V_197 = F_41 ( V_163 , V_168 , V_198 ) ;
V_167 -> V_199 = F_41 ( V_163 , V_168 , V_200 ) ;
V_167 -> V_201 = F_41 ( V_164 , V_169 ,
V_202 ) ;
V_167 -> V_203 = F_41 ( V_164 , V_169 ,
V_204 ) ;
V_167 -> V_205 = F_41 ( V_164 , V_169 , V_206 ) ;
V_167 -> V_207 = F_41 ( V_164 , V_169 , V_208 ) ;
V_167 -> V_209 = F_41 ( V_164 , V_169 , V_210 ) ;
V_167 -> V_211 = F_41 ( V_164 , V_169 , V_212 ) ;
V_167 -> V_213 = F_41 ( V_164 , V_169 , V_214 ) ;
V_167 -> V_215 = F_41 ( V_164 , V_169 , V_216 ) ;
V_167 -> V_217 = F_41 ( V_164 , V_169 , V_218 ) ;
V_167 -> V_219 = F_41 ( V_164 , V_169 , V_220 ) ;
V_167 -> V_221 = F_41 ( V_164 , V_169 ,
V_222 ) ;
V_167 -> V_223 = F_41 ( V_164 , V_169 ,
V_224 ) ;
V_167 -> V_225 = F_41 ( V_165 , V_170 , V_226 ) ;
V_167 -> V_227 = F_41 ( V_165 , V_170 , V_228 ) ;
V_167 -> V_229 = F_41 ( V_165 , V_170 , V_230 ) ;
V_167 -> V_231 = F_41 ( V_165 , V_170 , V_232 ) ;
V_167 -> V_233 = F_41 ( V_165 , V_170 , V_234 ) ;
V_167 -> V_235 = F_41 ( V_165 , V_170 , V_236 ) ;
switch ( V_167 -> V_221 ) {
case 0 :
break;
case 1 :
V_167 -> V_221 = 64 ;
break;
case 2 :
V_167 -> V_221 = 128 ;
break;
case 3 :
V_167 -> V_221 = 256 ;
break;
}
switch ( V_167 -> V_207 ) {
case 0 :
V_167 -> V_207 = 32 ;
break;
case 1 :
V_167 -> V_207 = 40 ;
break;
case 2 :
V_167 -> V_207 = 48 ;
break;
default:
V_167 -> V_207 = 32 ;
}
V_167 -> V_225 ++ ;
V_167 -> V_227 ++ ;
V_167 -> V_229 ++ ;
V_167 -> V_231 ++ ;
V_167 -> V_219 ++ ;
V_167 -> V_201 = 1 << ( V_167 -> V_201 + 7 ) ;
V_167 -> V_203 = 1 << ( V_167 -> V_203 + 7 ) ;
F_52 ( L_20 ) ;
}
static void F_64 ( struct V_5 * V_6 , unsigned int V_237 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
if ( V_6 -> V_26 ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
if ( V_237 )
F_65 ( V_6 -> V_33 , & V_8 -> V_118 ,
V_238 , V_239 ) ;
F_66 ( & V_8 -> V_118 ) ;
}
} else {
if ( V_237 )
F_65 ( V_6 -> V_33 , & V_6 -> V_118 ,
V_240 , V_239 ) ;
F_66 ( & V_6 -> V_118 ) ;
}
}
static void F_67 ( struct V_5 * V_6 , unsigned int V_241 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
if ( V_6 -> V_26 ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_68 ( & V_8 -> V_118 ) ;
if ( V_241 )
F_69 ( & V_8 -> V_118 ) ;
}
} else {
F_68 ( & V_6 -> V_118 ) ;
if ( V_241 )
F_69 ( & V_6 -> V_118 ) ;
}
}
static int F_70 ( struct V_5 * V_6 )
{
struct V_12 * V_8 ;
struct V_44 * V_33 = V_6 -> V_33 ;
unsigned int V_7 ;
int V_242 ;
F_71 ( & V_6 -> V_152 , F_38 , ( unsigned long ) V_6 ) ;
F_71 ( & V_6 -> V_106 , F_31 ,
( unsigned long ) V_6 ) ;
V_242 = F_72 ( V_6 -> V_17 , V_6 -> V_141 , F_48 , 0 ,
V_33 -> V_19 , V_6 ) ;
if ( V_242 ) {
F_30 ( V_33 , L_21 ,
V_6 -> V_141 ) ;
return V_242 ;
}
if ( V_6 -> V_101 -> V_145 && ( V_6 -> V_141 != V_6 -> V_146 ) ) {
V_242 = F_72 ( V_6 -> V_17 , V_6 -> V_146 , F_36 ,
0 , V_6 -> V_243 , V_6 ) ;
if ( V_242 ) {
F_30 ( V_33 , L_22 ,
V_6 -> V_146 ) ;
goto V_244;
}
}
if ( ! V_6 -> V_26 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
snprintf ( V_8 -> V_245 ,
sizeof( V_8 -> V_245 ) - 1 ,
L_23 , F_73 ( V_33 ) ,
V_8 -> V_20 ) ;
V_242 = F_72 ( V_6 -> V_17 , V_8 -> V_27 ,
F_49 , 0 ,
V_8 -> V_245 , V_8 ) ;
if ( V_242 ) {
F_30 ( V_33 , L_21 ,
V_8 -> V_27 ) ;
goto V_246;
}
F_74 ( V_8 -> V_27 ,
& V_8 -> V_25 ) ;
}
return 0 ;
V_246:
for ( V_7 -- ; V_7 < V_6 -> V_11 ; V_7 -- ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_74 ( V_8 -> V_27 , NULL ) ;
F_75 ( V_6 -> V_17 , V_8 -> V_27 , V_8 ) ;
}
if ( V_6 -> V_101 -> V_145 && ( V_6 -> V_141 != V_6 -> V_146 ) )
F_75 ( V_6 -> V_17 , V_6 -> V_146 , V_6 ) ;
V_244:
F_75 ( V_6 -> V_17 , V_6 -> V_141 , V_6 ) ;
return V_242 ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
F_75 ( V_6 -> V_17 , V_6 -> V_141 , V_6 ) ;
if ( V_6 -> V_101 -> V_145 && ( V_6 -> V_141 != V_6 -> V_146 ) )
F_75 ( V_6 -> V_17 , V_6 -> V_146 , V_6 ) ;
if ( ! V_6 -> V_26 )
return;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_74 ( V_8 -> V_27 , NULL ) ;
F_75 ( V_6 -> V_17 , V_8 -> V_27 , V_8 ) ;
}
}
void F_77 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_24 ) ;
V_6 -> V_247 = V_248 ;
V_6 -> V_249 = V_250 ;
V_41 -> V_251 ( V_6 ) ;
F_52 ( L_25 ) ;
}
void F_78 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_26 ) ;
V_6 -> V_252 = V_41 -> V_253 ( V_6 , V_254 ) ;
V_6 -> V_255 = V_254 ;
V_6 -> V_256 = V_257 ;
V_41 -> V_258 ( V_6 ) ;
F_52 ( L_27 ) ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_259 * V_260 = & V_6 -> V_260 ;
struct V_13 * V_14 ;
struct V_261 * V_262 ;
unsigned int V_7 , V_263 ;
F_52 ( L_28 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] -> V_10 ;
if ( ! V_14 )
break;
for ( V_263 = 0 ; V_263 < V_14 -> V_35 ; V_263 ++ ) {
V_262 = F_80 ( V_14 , V_263 ) ;
V_260 -> V_264 ( V_6 , V_262 ) ;
}
}
F_52 ( L_29 ) ;
}
static void F_81 ( struct V_5 * V_6 )
{
struct V_259 * V_260 = & V_6 -> V_260 ;
struct V_13 * V_14 ;
struct V_261 * V_262 ;
unsigned int V_7 , V_263 ;
F_52 ( L_30 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] -> V_9 ;
if ( ! V_14 )
break;
for ( V_263 = 0 ; V_263 < V_14 -> V_35 ; V_263 ++ ) {
V_262 = F_80 ( V_14 , V_263 ) ;
V_260 -> V_264 ( V_6 , V_262 ) ;
}
}
F_52 ( L_31 ) ;
}
static int F_82 ( struct V_5 * V_6 )
{
V_6 -> V_265 = - 1 ;
V_6 -> V_266 = V_267 ;
return V_6 -> V_143 . V_268 ( V_6 ) ;
}
int F_83 ( struct V_44 * V_33 , unsigned int V_269 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
unsigned long V_270 ;
F_52 ( L_32 ) ;
if ( ! F_85 ( V_33 ) ||
( V_269 == V_271 && V_6 -> V_272 ) ) {
F_30 ( V_33 , L_33 ) ;
F_52 ( L_34 ) ;
return - V_273 ;
}
F_86 ( & V_6 -> V_30 , V_270 ) ;
if ( V_269 == V_274 )
F_87 ( V_33 ) ;
F_88 ( V_33 ) ;
F_61 ( V_6 ) ;
F_89 ( V_6 -> V_135 ) ;
V_41 -> V_275 ( V_6 ) ;
V_41 -> V_276 ( V_6 ) ;
F_67 ( V_6 , 0 ) ;
V_6 -> V_272 = 1 ;
F_90 ( & V_6 -> V_30 , V_270 ) ;
F_52 ( L_34 ) ;
return 0 ;
}
int F_91 ( struct V_44 * V_33 , unsigned int V_269 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
unsigned long V_270 ;
F_52 ( L_35 ) ;
if ( ! F_85 ( V_33 ) ||
( V_269 == V_271 && ! V_6 -> V_272 ) ) {
F_30 ( V_33 , L_36 ) ;
F_52 ( L_37 ) ;
return - V_273 ;
}
F_86 ( & V_6 -> V_30 , V_270 ) ;
V_6 -> V_272 = 0 ;
F_64 ( V_6 , 0 ) ;
V_41 -> V_277 ( V_6 ) ;
V_41 -> V_278 ( V_6 ) ;
if ( V_269 == V_274 )
F_92 ( V_33 ) ;
F_93 ( V_33 ) ;
F_60 ( V_6 ) ;
F_90 ( & V_6 -> V_30 , V_270 ) ;
F_52 ( L_37 ) ;
return 0 ;
}
static int F_94 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_279 * V_143 = & V_6 -> V_143 ;
struct V_44 * V_33 = V_6 -> V_33 ;
int V_242 ;
F_52 ( L_38 ) ;
V_242 = V_41 -> V_280 ( V_6 ) ;
if ( V_242 )
return V_242 ;
F_64 ( V_6 , 1 ) ;
V_242 = F_70 ( V_6 ) ;
if ( V_242 )
goto V_281;
V_242 = V_143 -> V_282 ( V_6 ) ;
if ( V_242 )
goto V_283;
V_41 -> V_284 ( V_6 ) ;
V_41 -> V_285 ( V_6 ) ;
F_93 ( V_33 ) ;
F_60 ( V_6 ) ;
F_46 ( V_6 -> V_135 , & V_6 -> V_159 ) ;
F_95 ( V_286 , & V_6 -> V_287 ) ;
F_52 ( L_39 ) ;
return 0 ;
V_283:
F_76 ( V_6 ) ;
V_281:
F_67 ( V_6 , 1 ) ;
V_41 -> exit ( V_6 ) ;
return V_242 ;
}
static void F_96 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_279 * V_143 = & V_6 -> V_143 ;
struct V_12 * V_8 ;
struct V_44 * V_33 = V_6 -> V_33 ;
struct V_288 * V_289 ;
unsigned int V_7 ;
F_52 ( L_40 ) ;
if ( F_97 ( V_286 , & V_6 -> V_287 ) )
return;
F_88 ( V_33 ) ;
F_61 ( V_6 ) ;
F_89 ( V_6 -> V_135 ) ;
V_41 -> V_290 ( V_6 ) ;
V_41 -> V_291 ( V_6 ) ;
V_143 -> V_292 ( V_6 ) ;
F_76 ( V_6 ) ;
F_67 ( V_6 , 1 ) ;
V_41 -> exit ( V_6 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
if ( ! V_8 -> V_10 )
continue;
V_289 = F_98 ( V_33 , V_8 -> V_20 ) ;
F_99 ( V_289 ) ;
}
F_100 ( V_286 , & V_6 -> V_287 ) ;
F_52 ( L_41 ) ;
}
static void F_101 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = F_55 ( V_158 ,
struct V_5 ,
V_86 ) ;
F_102 () ;
F_96 ( V_6 ) ;
F_79 ( V_6 ) ;
F_81 ( V_6 ) ;
F_103 () ;
F_30 ( V_6 -> V_33 , L_42 ) ;
}
static void F_104 ( struct V_5 * V_6 )
{
F_52 ( L_43 ) ;
if ( ! F_85 ( V_6 -> V_33 ) )
return;
F_96 ( V_6 ) ;
F_79 ( V_6 ) ;
F_81 ( V_6 ) ;
F_94 ( V_6 ) ;
F_52 ( L_44 ) ;
}
static void F_105 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = F_55 ( V_158 ,
struct V_5 ,
V_123 ) ;
F_102 () ;
F_104 ( V_6 ) ;
F_103 () ;
}
static void F_106 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = F_55 ( V_158 ,
struct V_5 ,
V_136 ) ;
struct V_293 V_294 ;
T_3 V_295 ;
unsigned long V_270 ;
F_86 ( & V_6 -> V_296 , V_270 ) ;
if ( ! V_6 -> V_297 )
goto V_298;
if ( V_6 -> V_133 ) {
V_295 = F_107 ( & V_6 -> V_299 ,
V_6 -> V_133 ) ;
memset ( & V_294 , 0 , sizeof( V_294 ) ) ;
V_294 . V_300 = F_108 ( V_295 ) ;
F_109 ( V_6 -> V_297 , & V_294 ) ;
}
F_110 ( V_6 -> V_297 ) ;
V_6 -> V_297 = NULL ;
V_298:
F_90 ( & V_6 -> V_296 , V_270 ) ;
}
static int F_111 ( struct V_5 * V_6 ,
struct V_301 * V_301 )
{
if ( F_112 ( V_301 -> V_302 , & V_6 -> V_303 ,
sizeof( V_6 -> V_303 ) ) )
return - V_304 ;
return 0 ;
}
static int F_113 ( struct V_5 * V_6 ,
struct V_301 * V_301 )
{
struct V_305 V_306 ;
unsigned int V_307 ;
if ( F_114 ( & V_306 , V_301 -> V_302 , sizeof( V_306 ) ) )
return - V_304 ;
if ( V_306 . V_270 )
return - V_273 ;
V_307 = 0 ;
switch ( V_306 . V_308 ) {
case V_309 :
break;
case V_310 :
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
default:
return - V_313 ;
}
switch ( V_306 . V_314 ) {
case V_315 :
break;
case V_316 :
case V_317 :
F_44 ( V_307 , V_311 , V_318 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_319 :
F_44 ( V_307 , V_311 , V_320 , 1 ) ;
case V_321 :
F_44 ( V_307 , V_311 , V_322 , 1 ) ;
F_44 ( V_307 , V_311 , V_323 , 1 ) ;
F_44 ( V_307 , V_311 , V_324 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_325 :
F_44 ( V_307 , V_311 , V_320 , 1 ) ;
case V_326 :
F_44 ( V_307 , V_311 , V_322 , 1 ) ;
F_44 ( V_307 , V_311 , V_323 , 1 ) ;
F_44 ( V_307 , V_311 , V_327 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_328 :
F_44 ( V_307 , V_311 , V_320 , 1 ) ;
case V_329 :
F_44 ( V_307 , V_311 , V_322 , 1 ) ;
F_44 ( V_307 , V_311 , V_323 , 1 ) ;
F_44 ( V_307 , V_311 , V_327 , 1 ) ;
F_44 ( V_307 , V_311 , V_330 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_331 :
F_44 ( V_307 , V_311 , V_332 , 1 ) ;
F_44 ( V_307 , V_311 , V_324 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_333 :
F_44 ( V_307 , V_311 , V_332 , 1 ) ;
F_44 ( V_307 , V_311 , V_327 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_334 :
F_44 ( V_307 , V_311 , V_332 , 1 ) ;
F_44 ( V_307 , V_311 , V_330 , 1 ) ;
F_44 ( V_307 , V_311 , V_327 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_335 :
F_44 ( V_307 , V_311 , V_320 , 1 ) ;
F_44 ( V_307 , V_311 , V_336 , 1 ) ;
F_44 ( V_307 , V_311 , V_322 , 1 ) ;
F_44 ( V_307 , V_311 , V_323 , 1 ) ;
F_44 ( V_307 , V_311 , V_324 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_337 :
F_44 ( V_307 , V_311 , V_320 , 1 ) ;
F_44 ( V_307 , V_311 , V_336 , 1 ) ;
F_44 ( V_307 , V_311 , V_322 , 1 ) ;
F_44 ( V_307 , V_311 , V_323 , 1 ) ;
F_44 ( V_307 , V_311 , V_327 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
case V_338 :
F_44 ( V_307 , V_311 , V_320 , 1 ) ;
F_44 ( V_307 , V_311 , V_336 , 1 ) ;
F_44 ( V_307 , V_311 , V_322 , 1 ) ;
F_44 ( V_307 , V_311 , V_323 , 1 ) ;
F_44 ( V_307 , V_311 , V_330 , 1 ) ;
F_44 ( V_307 , V_311 , V_327 , 1 ) ;
F_44 ( V_307 , V_311 , V_312 , 1 ) ;
break;
default:
return - V_313 ;
}
V_6 -> V_41 . V_339 ( V_6 , V_307 ) ;
memcpy ( & V_6 -> V_303 , & V_306 , sizeof( V_306 ) ) ;
return 0 ;
}
static void F_115 ( struct V_5 * V_6 ,
struct V_340 * V_341 ,
struct V_342 * V_343 )
{
unsigned long V_270 ;
if ( F_41 ( V_343 -> V_344 , V_345 , V_346 ) ) {
F_86 ( & V_6 -> V_296 , V_270 ) ;
if ( V_6 -> V_297 ) {
F_44 ( V_343 -> V_344 ,
V_345 , V_346 , 0 ) ;
} else {
V_6 -> V_297 = F_116 ( V_341 ) ;
F_117 ( V_341 ) -> V_347 |= V_348 ;
}
F_90 ( & V_6 -> V_296 , V_270 ) ;
}
F_118 ( V_341 ) ;
}
static void F_119 ( struct V_340 * V_341 , struct V_342 * V_343 )
{
if ( F_120 ( V_341 ) )
V_343 -> V_349 = F_121 ( V_341 ) ;
}
static int F_122 ( struct V_340 * V_341 , struct V_342 * V_343 )
{
int V_242 ;
if ( ! F_41 ( V_343 -> V_344 , V_345 ,
V_350 ) )
return 0 ;
V_242 = F_123 ( V_341 , 0 ) ;
if ( V_242 )
return V_242 ;
V_343 -> V_351 = F_124 ( V_341 ) + F_125 ( V_341 ) ;
V_343 -> V_352 = F_125 ( V_341 ) ;
V_343 -> V_353 = V_341 -> V_354 - V_343 -> V_351 ;
V_343 -> V_355 = F_117 ( V_341 ) -> V_356 ;
F_52 ( L_45 , V_343 -> V_351 ) ;
F_52 ( L_46 ,
V_343 -> V_352 , V_343 -> V_353 ) ;
F_52 ( L_47 , V_343 -> V_355 ) ;
V_343 -> V_357 = F_117 ( V_341 ) -> V_358 ;
V_343 -> V_359 += ( V_343 -> V_357 - 1 ) * V_343 -> V_351 ;
return 0 ;
}
static int F_126 ( struct V_340 * V_341 )
{
if ( V_341 -> V_360 != V_361 )
return 0 ;
if ( ! F_127 ( V_341 ) )
return 0 ;
F_52 ( L_48 ) ;
return 1 ;
}
static void F_128 ( struct V_5 * V_6 ,
struct V_13 * V_14 , struct V_340 * V_341 ,
struct V_342 * V_343 )
{
struct V_362 * V_363 ;
unsigned int V_364 ;
unsigned int V_354 ;
unsigned int V_7 ;
V_343 -> V_341 = V_341 ;
V_364 = 0 ;
V_343 -> V_35 = 0 ;
V_343 -> V_357 = 1 ;
V_343 -> V_359 = V_341 -> V_354 ;
if ( F_126 ( V_341 ) ) {
if ( F_117 ( V_341 ) -> V_356 != V_14 -> V_38 . V_365 ) {
V_364 = 1 ;
V_343 -> V_35 ++ ;
}
V_343 -> V_35 ++ ;
F_44 ( V_343 -> V_344 , V_345 ,
V_350 , 1 ) ;
F_44 ( V_343 -> V_344 , V_345 ,
V_366 , 1 ) ;
} else if ( V_341 -> V_360 == V_361 )
F_44 ( V_343 -> V_344 , V_345 ,
V_366 , 1 ) ;
if ( F_120 ( V_341 ) ) {
if ( F_121 ( V_341 ) != V_14 -> V_38 . V_367 )
if ( ! V_364 ) {
V_364 = 1 ;
V_343 -> V_35 ++ ;
}
F_44 ( V_343 -> V_344 , V_345 ,
V_368 , 1 ) ;
}
if ( ( F_117 ( V_341 ) -> V_347 & V_369 ) &&
( V_6 -> V_303 . V_308 == V_310 ) )
F_44 ( V_343 -> V_344 , V_345 ,
V_346 , 1 ) ;
for ( V_354 = F_129 ( V_341 ) ; V_354 ; ) {
V_343 -> V_35 ++ ;
V_354 -= F_130 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_7 = 0 ; V_7 < F_117 ( V_341 ) -> V_370 ; V_7 ++ ) {
V_363 = & F_117 ( V_341 ) -> V_371 [ V_7 ] ;
for ( V_354 = F_131 ( V_363 ) ; V_354 ; ) {
V_343 -> V_35 ++ ;
V_354 -= F_130 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_132 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_259 * V_260 = & V_6 -> V_260 ;
int V_242 ;
F_52 ( L_49 ) ;
V_242 = F_82 ( V_6 ) ;
if ( V_242 )
return V_242 ;
V_242 = F_133 ( V_6 -> V_372 ) ;
if ( V_242 ) {
F_30 ( V_33 , L_50 ) ;
return V_242 ;
}
V_242 = F_133 ( V_6 -> V_373 ) ;
if ( V_242 ) {
F_30 ( V_33 , L_51 ) ;
goto V_374;
}
V_242 = F_20 ( V_33 , V_33 -> V_45 ) ;
if ( V_242 < 0 )
goto V_375;
V_6 -> V_46 = V_242 ;
V_242 = F_7 ( V_6 ) ;
if ( V_242 )
goto V_375;
V_242 = V_260 -> V_376 ( V_6 ) ;
if ( V_242 )
goto V_377;
F_134 ( & V_6 -> V_159 , F_54 ) ;
F_134 ( & V_6 -> V_123 , F_105 ) ;
F_134 ( & V_6 -> V_86 , F_101 ) ;
F_134 ( & V_6 -> V_136 , F_106 ) ;
F_58 ( V_6 ) ;
V_242 = F_94 ( V_6 ) ;
if ( V_242 )
goto V_378;
F_95 ( V_379 , & V_6 -> V_287 ) ;
F_52 ( L_52 ) ;
return 0 ;
V_378:
V_260 -> V_380 ( V_6 ) ;
V_377:
F_4 ( V_6 ) ;
V_375:
F_135 ( V_6 -> V_373 ) ;
V_374:
F_135 ( V_6 -> V_372 ) ;
return V_242 ;
}
static int F_136 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_259 * V_260 = & V_6 -> V_260 ;
F_52 ( L_53 ) ;
F_96 ( V_6 ) ;
V_260 -> V_380 ( V_6 ) ;
F_4 ( V_6 ) ;
F_135 ( V_6 -> V_373 ) ;
F_135 ( V_6 -> V_372 ) ;
F_100 ( V_379 , & V_6 -> V_287 ) ;
F_52 ( L_54 ) ;
return 0 ;
}
static int F_137 ( struct V_340 * V_341 , struct V_44 * V_33 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_259 * V_260 = & V_6 -> V_260 ;
struct V_12 * V_8 ;
struct V_13 * V_14 ;
struct V_342 * V_343 ;
struct V_288 * V_289 ;
int V_242 ;
F_52 ( L_55 , V_341 -> V_354 ) ;
V_8 = V_6 -> V_8 [ V_341 -> V_381 ] ;
V_289 = F_98 ( V_33 , V_8 -> V_20 ) ;
V_14 = V_8 -> V_10 ;
V_343 = & V_14 -> V_382 ;
V_242 = V_383 ;
if ( V_341 -> V_354 == 0 ) {
F_138 ( V_6 , V_384 , V_33 ,
L_56 ) ;
F_110 ( V_341 ) ;
goto V_385;
}
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
F_128 ( V_6 , V_14 , V_341 , V_343 ) ;
V_242 = F_17 ( V_8 , V_14 , V_343 -> V_35 ) ;
if ( V_242 )
goto V_385;
V_242 = F_122 ( V_341 , V_343 ) ;
if ( V_242 ) {
F_138 ( V_6 , V_384 , V_33 ,
L_57 ) ;
F_110 ( V_341 ) ;
goto V_385;
}
F_119 ( V_341 , V_343 ) ;
if ( ! V_260 -> V_386 ( V_8 , V_341 ) ) {
F_110 ( V_341 ) ;
goto V_385;
}
F_115 ( V_6 , V_341 , V_343 ) ;
F_139 ( V_289 , V_343 -> V_359 ) ;
V_41 -> V_387 ( V_8 ) ;
if ( F_140 ( V_6 ) )
F_141 ( V_33 , V_341 , true ) ;
F_17 ( V_8 , V_14 , V_388 ) ;
V_242 = V_383 ;
V_385:
return V_242 ;
}
static void F_142 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_58 ) ;
V_41 -> V_389 ( V_6 ) ;
F_52 ( L_59 ) ;
}
static int F_143 ( struct V_44 * V_33 , void * V_390 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_391 * V_392 = V_390 ;
F_52 ( L_60 ) ;
if ( ! F_144 ( V_392 -> V_393 ) )
return - V_394 ;
memcpy ( V_33 -> V_395 , V_392 -> V_393 , V_33 -> V_396 ) ;
V_41 -> V_397 ( V_6 , V_33 -> V_395 ) ;
F_52 ( L_61 ) ;
return 0 ;
}
static int F_145 ( struct V_44 * V_33 , struct V_301 * V_301 , int V_398 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
int V_242 ;
switch ( V_398 ) {
case V_399 :
V_242 = F_111 ( V_6 , V_301 ) ;
break;
case V_400 :
V_242 = F_113 ( V_6 , V_301 ) ;
break;
default:
V_242 = - V_401 ;
}
return V_242 ;
}
static int F_146 ( struct V_44 * V_33 , int V_45 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
int V_242 ;
F_52 ( L_62 ) ;
V_242 = F_20 ( V_33 , V_45 ) ;
if ( V_242 < 0 )
return V_242 ;
V_6 -> V_46 = V_242 ;
V_33 -> V_45 = V_45 ;
F_104 ( V_6 ) ;
F_52 ( L_63 ) ;
return 0 ;
}
static void F_147 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
F_148 ( V_33 , L_64 ) ;
F_34 ( & V_6 -> V_123 ) ;
}
static void F_149 ( struct V_44 * V_33 ,
struct V_402 * V_403 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_404 * V_405 = & V_6 -> V_406 ;
F_52 ( L_65 , V_407 ) ;
V_6 -> V_41 . V_408 ( V_6 ) ;
V_403 -> V_409 = V_405 -> V_410 ;
V_403 -> V_411 = V_405 -> V_412 ;
V_403 -> V_413 = V_405 -> V_410 -
V_405 -> V_414 -
V_405 -> V_415 -
V_405 -> V_416 ;
V_403 -> V_417 = V_405 -> V_415 ;
V_403 -> V_418 = V_405 -> V_419 ;
V_403 -> V_420 = V_405 -> V_421 ;
V_403 -> V_422 = V_405 -> V_423 ;
V_403 -> V_357 = V_405 -> V_424 ;
V_403 -> V_359 = V_405 -> V_425 ;
V_403 -> V_426 = V_405 -> V_424 - V_405 -> V_427 ;
V_403 -> V_428 = V_33 -> V_429 . V_428 ;
F_52 ( L_66 , V_407 ) ;
}
static int F_150 ( struct V_44 * V_33 , T_4 V_430 ,
T_5 V_431 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_65 , V_407 ) ;
F_100 ( V_431 , V_6 -> V_432 ) ;
V_41 -> V_433 ( V_6 ) ;
F_52 ( L_66 , V_407 ) ;
return 0 ;
}
static int F_151 ( struct V_44 * V_33 , T_4 V_430 ,
T_5 V_431 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_65 , V_407 ) ;
F_95 ( V_431 , V_6 -> V_432 ) ;
V_41 -> V_433 ( V_6 ) ;
F_52 ( L_66 , V_407 ) ;
return 0 ;
}
static void F_152 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_12 * V_8 ;
unsigned int V_7 ;
F_52 ( L_67 ) ;
if ( V_6 -> V_26 ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_49 ( V_8 -> V_27 , V_8 ) ;
}
} else {
F_153 ( V_6 -> V_141 ) ;
F_48 ( V_6 -> V_141 , V_6 ) ;
F_154 ( V_6 -> V_141 ) ;
}
F_52 ( L_68 ) ;
}
static int F_155 ( struct V_44 * V_33 , T_6 V_434 , T_6 V_435 ,
T_4 V_430 ,
struct V_436 * V_436 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
T_7 V_437 ;
if ( V_436 -> type != V_438 )
return - V_273 ;
V_436 -> V_439 -> V_440 = V_441 ;
V_437 = V_436 -> V_439 -> V_442 ;
if ( V_437 > V_6 -> V_167 . V_219 )
return - V_273 ;
V_6 -> V_443 = V_437 ;
V_6 -> V_41 . V_444 ( V_6 ) ;
return 0 ;
}
static int F_156 ( struct V_44 * V_33 ,
T_8 V_445 )
{
struct V_5 * V_6 = F_84 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
T_8 V_446 , V_447 , V_448 , V_449 ;
int V_242 = 0 ;
V_446 = V_6 -> V_450 & V_451 ;
V_447 = V_6 -> V_450 & V_452 ;
V_448 = V_6 -> V_450 & V_453 ;
V_449 = V_6 -> V_450 & V_454 ;
if ( ( V_445 & V_451 ) && ! V_446 )
V_242 = V_41 -> V_455 ( V_6 ) ;
else if ( ! ( V_445 & V_451 ) && V_446 )
V_242 = V_41 -> V_456 ( V_6 ) ;
if ( V_242 )
return V_242 ;
if ( ( V_445 & V_452 ) && ! V_447 )
V_41 -> V_457 ( V_6 ) ;
else if ( ! ( V_445 & V_452 ) && V_447 )
V_41 -> V_458 ( V_6 ) ;
if ( ( V_445 & V_453 ) && ! V_448 )
V_41 -> V_459 ( V_6 ) ;
else if ( ! ( V_445 & V_453 ) && V_448 )
V_41 -> V_460 ( V_6 ) ;
if ( ( V_445 & V_454 ) && ! V_449 )
V_41 -> V_461 ( V_6 ) ;
else if ( ! ( V_445 & V_454 ) && V_449 )
V_41 -> V_462 ( V_6 ) ;
V_6 -> V_450 = V_445 ;
F_52 ( L_69 ) ;
return 0 ;
}
const struct V_463 * F_157 ( void )
{
return & V_464 ;
}
static void F_158 ( struct V_12 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_259 * V_260 = & V_6 -> V_260 ;
struct V_13 * V_14 = V_8 -> V_9 ;
struct V_261 * V_262 ;
while ( V_14 -> V_37 != V_14 -> V_36 ) {
V_262 = F_80 ( V_14 , V_14 -> V_37 ) ;
V_260 -> V_264 ( V_6 , V_262 ) ;
if ( V_260 -> V_465 ( V_6 , V_14 , V_262 ) )
break;
V_41 -> V_466 ( V_6 , V_262 , V_14 -> V_37 ) ;
V_14 -> V_37 ++ ;
}
F_159 () ;
V_262 = F_80 ( V_14 , V_14 -> V_37 - 1 ) ;
F_45 ( V_8 , V_467 ,
F_160 ( V_262 -> V_468 ) ) ;
}
static struct V_340 * F_161 ( struct V_5 * V_6 ,
struct V_155 * V_118 ,
struct V_261 * V_262 ,
unsigned int V_354 )
{
struct V_340 * V_341 ;
T_7 * V_343 ;
V_341 = F_162 ( V_118 , V_262 -> V_469 . V_470 . V_471 ) ;
if ( ! V_341 )
return NULL ;
F_163 ( V_6 -> V_17 , V_262 -> V_469 . V_470 . V_472 ,
V_262 -> V_469 . V_470 . V_473 ,
V_262 -> V_469 . V_470 . V_471 , V_474 ) ;
V_343 = F_164 ( V_262 -> V_469 . V_470 . V_475 . V_476 ) +
V_262 -> V_469 . V_470 . V_475 . V_477 ;
F_165 ( V_341 , V_343 , V_354 ) ;
F_166 ( V_341 , V_354 ) ;
return V_341 ;
}
static unsigned int F_167 ( struct V_261 * V_262 ,
struct V_342 * V_343 )
{
if ( ! F_41 ( V_343 -> V_344 , V_478 , V_479 ) )
return 0 ;
if ( V_262 -> V_469 . V_480 )
return V_262 -> V_469 . V_480 ;
if ( ! F_41 ( V_343 -> V_344 , V_478 , V_481 ) )
return V_262 -> V_469 . V_470 . V_471 ;
return F_130 (unsigned int, rdata->rx.hdr.dma_len, rdata->rx.len) ;
}
static unsigned int F_168 ( struct V_261 * V_262 ,
struct V_342 * V_343 ,
unsigned int V_354 )
{
if ( ! F_41 ( V_343 -> V_344 , V_478 , V_481 ) )
return V_262 -> V_469 . V_482 . V_471 ;
return V_262 -> V_469 . V_354 - V_354 ;
}
static int F_169 ( struct V_12 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_259 * V_260 = & V_6 -> V_260 ;
struct V_13 * V_14 = V_8 -> V_10 ;
struct V_261 * V_262 ;
struct V_483 * V_484 ;
struct V_44 * V_33 = V_6 -> V_33 ;
struct V_288 * V_289 ;
int V_485 = 0 ;
unsigned int V_357 = 0 , V_359 = 0 ;
unsigned int V_36 ;
F_52 ( L_70 ) ;
if ( ! V_14 )
return 0 ;
V_36 = V_14 -> V_36 ;
F_170 () ;
V_289 = F_98 ( V_33 , V_8 -> V_20 ) ;
while ( ( V_485 < V_486 ) &&
( V_14 -> V_37 != V_36 ) ) {
V_262 = F_80 ( V_14 , V_14 -> V_37 ) ;
V_484 = V_262 -> V_484 ;
if ( ! V_41 -> V_487 ( V_484 ) )
break;
F_171 () ;
if ( F_172 ( V_6 ) )
F_173 ( V_6 , V_14 , V_14 -> V_37 , 1 , 0 ) ;
if ( V_41 -> V_488 ( V_484 ) ) {
V_357 += V_262 -> V_38 . V_489 ;
V_359 += V_262 -> V_38 . V_490 ;
}
V_260 -> V_264 ( V_6 , V_262 ) ;
V_41 -> V_491 ( V_262 ) ;
V_485 ++ ;
V_14 -> V_37 ++ ;
}
if ( ! V_485 )
return 0 ;
F_174 ( V_289 , V_357 , V_359 ) ;
if ( ( V_14 -> V_38 . V_39 == 1 ) &&
( F_15 ( V_14 ) > V_492 ) ) {
V_14 -> V_38 . V_39 = 0 ;
F_175 ( V_289 ) ;
}
F_52 ( L_71 , V_485 ) ;
return V_485 ;
}
static int F_176 ( struct V_12 * V_8 , int V_493 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_13 * V_14 = V_8 -> V_9 ;
struct V_261 * V_262 ;
struct V_342 * V_343 ;
struct V_44 * V_33 = V_6 -> V_33 ;
struct V_155 * V_118 ;
struct V_340 * V_341 ;
struct V_293 * V_294 ;
unsigned int V_494 , error , V_495 , V_496 ;
unsigned int V_354 , V_497 , V_498 , V_499 ;
unsigned int V_500 = 0 ;
int V_501 = 0 ;
F_52 ( L_72 , V_493 ) ;
if ( ! V_14 )
return 0 ;
V_494 = 0 ;
V_495 = 0 ;
V_118 = ( V_6 -> V_26 ) ? & V_8 -> V_118 : & V_6 -> V_118 ;
V_262 = F_80 ( V_14 , V_14 -> V_36 ) ;
V_343 = & V_14 -> V_382 ;
while ( V_501 < V_493 ) {
F_52 ( L_73 , V_14 -> V_36 ) ;
if ( ! V_500 && V_262 -> V_502 ) {
V_341 = V_262 -> V_503 . V_341 ;
error = V_262 -> V_503 . error ;
V_354 = V_262 -> V_503 . V_354 ;
} else {
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
V_341 = NULL ;
error = 0 ;
V_354 = 0 ;
}
V_504:
V_262 = F_80 ( V_14 , V_14 -> V_36 ) ;
if ( F_16 ( V_14 ) > ( V_505 >> 3 ) )
F_158 ( V_8 ) ;
if ( V_41 -> V_506 ( V_8 ) )
break;
V_500 ++ ;
V_14 -> V_36 ++ ;
V_494 = F_41 ( V_343 -> V_344 , V_478 ,
V_481 ) ;
V_495 = F_41 ( V_343 -> V_344 ,
V_478 ,
V_507 ) ;
V_496 = F_41 ( V_343 -> V_344 ,
V_478 ,
V_508 ) ;
if ( ( ! V_494 || V_495 ) && error )
goto V_504;
if ( error || V_343 -> V_509 ) {
if ( V_343 -> V_509 )
F_138 ( V_6 , V_510 , V_33 ,
L_74 ) ;
F_177 ( V_341 ) ;
goto V_511;
}
if ( ! V_496 ) {
V_497 = F_167 ( V_262 , V_343 ) ;
V_354 += V_497 ;
V_498 = F_168 ( V_262 , V_343 , V_354 ) ;
V_354 += V_498 ;
if ( ! V_341 ) {
V_341 = F_161 ( V_6 , V_118 , V_262 ,
V_497 ) ;
if ( ! V_341 ) {
error = 1 ;
goto V_512;
}
}
if ( V_498 ) {
F_163 ( V_6 -> V_17 ,
V_262 -> V_469 . V_482 . V_472 ,
V_262 -> V_469 . V_482 . V_473 ,
V_262 -> V_469 . V_482 . V_471 ,
V_474 ) ;
F_178 ( V_341 , F_117 ( V_341 ) -> V_370 ,
V_262 -> V_469 . V_482 . V_475 . V_476 ,
V_262 -> V_469 . V_482 . V_475 . V_477 ,
V_498 ,
V_262 -> V_469 . V_482 . V_471 ) ;
V_262 -> V_469 . V_482 . V_475 . V_476 = NULL ;
}
}
V_512:
if ( ! V_494 || V_495 )
goto V_504;
if ( ! V_341 )
goto V_511;
V_499 = V_33 -> V_45 + V_47 ;
if ( ! ( V_33 -> V_445 & V_453 ) &&
( V_341 -> V_513 == F_179 ( V_514 ) ) )
V_499 += V_49 ;
if ( V_341 -> V_354 > V_499 ) {
F_138 ( V_6 , V_510 , V_33 ,
L_75 ) ;
F_177 ( V_341 ) ;
goto V_511;
}
if ( F_140 ( V_6 ) )
F_141 ( V_33 , V_341 , false ) ;
F_180 ( V_341 ) ;
if ( F_41 ( V_343 -> V_344 ,
V_478 , V_515 ) )
V_341 -> V_360 = V_516 ;
if ( F_41 ( V_343 -> V_344 ,
V_478 , V_368 ) )
F_181 ( V_341 , F_179 ( V_514 ) ,
V_343 -> V_349 ) ;
if ( F_41 ( V_343 -> V_344 ,
V_478 , V_517 ) ) {
T_3 V_295 ;
V_295 = F_107 ( & V_6 -> V_299 ,
V_343 -> V_518 ) ;
V_294 = F_182 ( V_341 ) ;
V_294 -> V_300 = F_108 ( V_295 ) ;
}
if ( F_41 ( V_343 -> V_344 ,
V_478 , V_519 ) )
F_183 ( V_341 , V_343 -> V_520 ,
V_343 -> V_521 ) ;
V_341 -> V_17 = V_33 ;
V_341 -> V_513 = F_184 ( V_341 , V_33 ) ;
F_185 ( V_341 , V_8 -> V_20 ) ;
F_186 ( V_118 , V_341 ) ;
V_511:
V_501 ++ ;
}
if ( V_500 && ( ! V_494 || V_495 ) ) {
V_262 = F_80 ( V_14 , V_14 -> V_36 ) ;
V_262 -> V_502 = 1 ;
V_262 -> V_503 . V_341 = V_341 ;
V_262 -> V_503 . V_354 = V_354 ;
V_262 -> V_503 . error = error ;
}
F_52 ( L_76 , V_501 ) ;
return V_501 ;
}
static int V_238 ( struct V_155 * V_118 , int V_493 )
{
struct V_12 * V_8 = F_55 ( V_118 , struct V_12 ,
V_118 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
int V_485 = 0 ;
F_52 ( L_77 , V_493 ) ;
F_169 ( V_8 ) ;
V_485 = F_176 ( V_8 , V_493 ) ;
if ( ( V_485 < V_493 ) && F_187 ( V_118 , V_485 ) ) {
if ( V_6 -> V_154 )
F_22 ( V_6 , V_8 ) ;
else
F_154 ( V_8 -> V_27 ) ;
}
F_52 ( L_78 , V_485 ) ;
return V_485 ;
}
static int V_240 ( struct V_155 * V_118 , int V_493 )
{
struct V_5 * V_6 = F_55 ( V_118 , struct V_5 ,
V_118 ) ;
struct V_12 * V_8 ;
int V_522 ;
int V_485 , V_523 ;
unsigned int V_7 ;
F_52 ( L_79 , V_493 ) ;
V_485 = 0 ;
V_522 = V_493 / V_6 -> V_31 ;
do {
V_523 = V_485 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_169 ( V_8 ) ;
if ( V_522 > ( V_493 - V_485 ) )
V_522 = V_493 - V_485 ;
V_485 += F_176 ( V_8 , V_522 ) ;
}
} while ( ( V_485 < V_493 ) && ( V_485 != V_523 ) );
if ( ( V_485 < V_493 ) && F_187 ( V_118 , V_485 ) ) {
F_23 ( V_6 ) ;
}
F_52 ( L_80 , V_485 ) ;
return V_485 ;
}
void F_173 ( struct V_5 * V_6 , struct V_13 * V_14 ,
unsigned int V_524 , unsigned int V_15 , unsigned int V_525 )
{
struct V_261 * V_262 ;
struct V_483 * V_484 ;
while ( V_15 -- ) {
V_262 = F_80 ( V_14 , V_524 ) ;
V_484 = V_262 -> V_484 ;
F_188 ( V_6 -> V_33 ,
L_81 , V_524 ,
( V_525 == 1 ) ? L_82 : L_83 ,
F_189 ( V_484 -> V_526 ) ,
F_189 ( V_484 -> V_527 ) ,
F_189 ( V_484 -> V_528 ) ,
F_189 ( V_484 -> V_529 ) ) ;
V_524 ++ ;
}
}
void F_190 ( struct V_5 * V_6 , struct V_13 * V_14 ,
unsigned int V_524 )
{
struct V_261 * V_262 ;
struct V_483 * V_484 ;
V_262 = F_80 ( V_14 , V_524 ) ;
V_484 = V_262 -> V_484 ;
F_188 ( V_6 -> V_33 ,
L_84 ,
V_524 , F_189 ( V_484 -> V_526 ) , F_189 ( V_484 -> V_527 ) ,
F_189 ( V_484 -> V_528 ) , F_189 ( V_484 -> V_529 ) ) ;
}
void F_141 ( struct V_44 * V_33 , struct V_340 * V_341 , bool V_530 )
{
struct V_531 * V_532 = (struct V_531 * ) V_341 -> V_70 ;
unsigned char * V_482 = V_341 -> V_70 ;
unsigned char V_533 [ 128 ] ;
unsigned int V_7 , V_263 ;
F_188 ( V_33 , L_85 ) ;
F_188 ( V_33 , L_86 ,
( V_530 ? L_87 : L_88 ) , V_341 -> V_354 ) ;
F_188 ( V_33 , L_89 , V_532 -> V_534 ) ;
F_188 ( V_33 , L_90 , V_532 -> V_535 ) ;
F_188 ( V_33 , L_91 , F_191 ( V_532 -> V_536 ) ) ;
for ( V_7 = 0 , V_263 = 0 ; V_7 < V_341 -> V_354 ; ) {
V_263 += snprintf ( V_533 + V_263 , sizeof( V_533 ) - V_263 , L_92 ,
V_482 [ V_7 ++ ] ) ;
if ( ( V_7 % 32 ) == 0 ) {
F_188 ( V_33 , L_93 , V_7 - 32 , V_533 ) ;
V_263 = 0 ;
} else if ( ( V_7 % 16 ) == 0 ) {
V_533 [ V_263 ++ ] = ' ' ;
V_533 [ V_263 ++ ] = ' ' ;
} else if ( ( V_7 % 4 ) == 0 ) {
V_533 [ V_263 ++ ] = ' ' ;
}
}
if ( V_7 % 32 )
F_188 ( V_33 , L_93 , V_7 - ( V_7 % 32 ) , V_533 ) ;
F_188 ( V_33 , L_85 ) ;
}
