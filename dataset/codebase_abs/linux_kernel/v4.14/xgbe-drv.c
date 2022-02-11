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
V_167 -> V_201 = F_41 ( V_163 , V_168 , V_202 ) ;
V_167 -> V_203 = F_41 ( V_164 , V_169 ,
V_204 ) ;
V_167 -> V_205 = F_41 ( V_164 , V_169 ,
V_206 ) ;
V_167 -> V_207 = F_41 ( V_164 , V_169 , V_208 ) ;
V_167 -> V_209 = F_41 ( V_164 , V_169 , V_210 ) ;
V_167 -> V_211 = F_41 ( V_164 , V_169 , V_212 ) ;
V_167 -> V_213 = F_41 ( V_164 , V_169 , V_214 ) ;
V_167 -> V_215 = F_41 ( V_164 , V_169 , V_216 ) ;
V_167 -> V_217 = F_41 ( V_164 , V_169 , V_218 ) ;
V_167 -> V_219 = F_41 ( V_164 , V_169 , V_220 ) ;
V_167 -> V_221 = F_41 ( V_164 , V_169 , V_222 ) ;
V_167 -> V_223 = F_41 ( V_164 , V_169 ,
V_224 ) ;
V_167 -> V_225 = F_41 ( V_164 , V_169 ,
V_226 ) ;
V_167 -> V_227 = F_41 ( V_165 , V_170 , V_228 ) ;
V_167 -> V_229 = F_41 ( V_165 , V_170 , V_230 ) ;
V_167 -> V_231 = F_41 ( V_165 , V_170 , V_232 ) ;
V_167 -> V_233 = F_41 ( V_165 , V_170 , V_234 ) ;
V_167 -> V_235 = F_41 ( V_165 , V_170 , V_236 ) ;
V_167 -> V_237 = F_41 ( V_165 , V_170 , V_238 ) ;
switch ( V_167 -> V_223 ) {
case 0 :
break;
case 1 :
V_167 -> V_223 = 64 ;
break;
case 2 :
V_167 -> V_223 = 128 ;
break;
case 3 :
V_167 -> V_223 = 256 ;
break;
}
switch ( V_167 -> V_209 ) {
case 0 :
V_167 -> V_209 = 32 ;
break;
case 1 :
V_167 -> V_209 = 40 ;
break;
case 2 :
V_167 -> V_209 = 48 ;
break;
default:
V_167 -> V_209 = 32 ;
}
V_167 -> V_227 ++ ;
V_167 -> V_229 ++ ;
V_167 -> V_231 ++ ;
V_167 -> V_233 ++ ;
V_167 -> V_221 ++ ;
V_167 -> V_203 = 1 << ( V_167 -> V_203 + 7 ) ;
V_167 -> V_205 = 1 << ( V_167 -> V_205 + 7 ) ;
if ( F_64 ( V_6 ) ) {
F_65 ( V_6 -> V_17 , L_19 ) ;
F_65 ( V_6 -> V_17 , L_20 ,
V_167 -> V_173 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_23 ,
V_167 -> V_175 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_24 ,
V_167 -> V_177 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_25 ,
V_167 -> V_179 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_26 ,
V_167 -> V_181 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_27 ,
V_167 -> V_183 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_28 ,
V_167 -> V_185 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_29 ,
V_167 -> V_187 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_30 ,
V_167 -> V_189 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_31 ,
V_167 -> V_191 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_32 ,
V_167 -> V_193 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_33 ,
V_167 -> V_195 ) ;
F_65 ( V_6 -> V_17 , L_34 ,
( V_167 -> V_197 == 1 ) ? L_35 :
( V_167 -> V_197 == 2 ) ? L_36 :
( V_167 -> V_197 == 3 ) ? L_37 : L_38 ) ;
F_65 ( V_6 -> V_17 , L_39 ,
V_167 -> V_199 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_40 ,
V_167 -> V_201 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_41 ,
V_167 -> V_203 ) ;
F_65 ( V_6 -> V_17 , L_42 ,
V_167 -> V_205 ) ;
F_65 ( V_6 -> V_17 , L_43 ,
V_167 -> V_207 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_44 ,
V_167 -> V_209 ) ;
F_65 ( V_6 -> V_17 , L_45 ,
V_167 -> V_211 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_46 ,
V_167 -> V_213 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_47 ,
V_167 -> V_215 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_48 ,
V_167 -> V_217 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_49 ,
V_167 -> V_219 ? L_21 : L_22 ) ;
F_65 ( V_6 -> V_17 , L_50 ,
V_167 -> V_221 ) ;
F_65 ( V_6 -> V_17 , L_51 ,
V_167 -> V_223 ) ;
F_65 ( V_6 -> V_17 , L_52 ,
V_167 -> V_225 ) ;
F_65 ( V_6 -> V_17 , L_53 ,
V_167 -> V_227 ) ;
F_65 ( V_6 -> V_17 , L_54 ,
V_167 -> V_229 ) ;
F_65 ( V_6 -> V_17 , L_55 ,
V_167 -> V_231 ) ;
F_65 ( V_6 -> V_17 , L_56 ,
V_167 -> V_231 ) ;
F_65 ( V_6 -> V_17 , L_57 ,
V_167 -> V_235 ) ;
F_65 ( V_6 -> V_17 , L_58 ,
V_167 -> V_237 ) ;
}
}
static void F_66 ( struct V_5 * V_6 )
{
struct V_44 * V_33 = V_6 -> V_33 ;
if ( ! V_6 -> V_239 )
return;
F_67 ( V_33 , L_59 ) ;
V_33 -> V_240 &= ~ ( V_241 |
V_242 |
V_243 |
V_244 |
V_245 |
V_246 |
V_247 |
V_248 |
V_249 ) ;
V_33 -> V_250 &= ~ ( V_248 |
V_249 ) ;
V_6 -> V_239 = 0 ;
}
static void F_68 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_251 )
return;
V_6 -> V_41 . V_252 ( V_6 ) ;
V_6 -> V_251 = 0 ;
V_6 -> V_253 = 0 ;
}
static void F_69 ( struct V_5 * V_6 )
{
F_66 ( V_6 ) ;
F_68 ( V_6 ) ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_44 * V_33 = V_6 -> V_33 ;
if ( V_6 -> V_239 )
return;
F_67 ( V_33 , L_60 ) ;
V_33 -> V_240 |= V_241 |
V_242 |
V_243 |
V_244 |
V_245 |
V_246 |
V_247 |
V_6 -> V_254 ;
V_33 -> V_250 |= V_6 -> V_254 ;
V_6 -> V_239 = 1 ;
}
static void F_71 ( struct V_5 * V_6 )
{
struct V_255 * V_101 ;
if ( V_6 -> V_251 )
return;
if ( F_72 ( & V_6 -> V_256 ) )
return;
V_101 = F_73 ( & V_6 -> V_256 ,
struct V_255 , V_257 ) ;
V_6 -> V_251 = 1 ;
V_6 -> V_253 = F_74 ( V_101 -> V_258 ) ;
V_6 -> V_41 . V_259 ( V_6 ) ;
}
static void F_75 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_254 )
return;
if ( V_6 -> V_260 )
return;
F_71 ( V_6 ) ;
F_70 ( V_6 ) ;
}
static void F_76 ( struct V_5 * V_6 )
{
F_68 ( V_6 ) ;
if ( V_6 -> V_254 )
F_70 ( V_6 ) ;
V_6 -> V_260 = 0 ;
}
static void F_77 ( struct V_5 * V_6 , unsigned int V_261 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
if ( V_6 -> V_26 ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
if ( V_261 )
F_78 ( V_6 -> V_33 , & V_8 -> V_118 ,
V_262 , V_263 ) ;
F_79 ( & V_8 -> V_118 ) ;
}
} else {
if ( V_261 )
F_78 ( V_6 -> V_33 , & V_6 -> V_118 ,
V_264 , V_263 ) ;
F_79 ( & V_6 -> V_118 ) ;
}
}
static void F_80 ( struct V_5 * V_6 , unsigned int V_265 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
if ( V_6 -> V_26 ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_81 ( & V_8 -> V_118 ) ;
if ( V_265 )
F_82 ( & V_8 -> V_118 ) ;
}
} else {
F_81 ( & V_6 -> V_118 ) ;
if ( V_265 )
F_82 ( & V_6 -> V_118 ) ;
}
}
static int F_83 ( struct V_5 * V_6 )
{
struct V_12 * V_8 ;
struct V_44 * V_33 = V_6 -> V_33 ;
unsigned int V_7 ;
int V_266 ;
F_84 ( & V_6 -> V_152 , F_38 , ( unsigned long ) V_6 ) ;
F_84 ( & V_6 -> V_106 , F_31 ,
( unsigned long ) V_6 ) ;
V_266 = F_85 ( V_6 -> V_17 , V_6 -> V_141 , F_48 , 0 ,
F_86 ( V_33 ) , V_6 ) ;
if ( V_266 ) {
F_30 ( V_33 , L_61 ,
V_6 -> V_141 ) ;
return V_266 ;
}
if ( V_6 -> V_101 -> V_145 && ( V_6 -> V_141 != V_6 -> V_146 ) ) {
V_266 = F_85 ( V_6 -> V_17 , V_6 -> V_146 , F_36 ,
0 , V_6 -> V_267 , V_6 ) ;
if ( V_266 ) {
F_30 ( V_33 , L_62 ,
V_6 -> V_146 ) ;
goto V_268;
}
}
if ( ! V_6 -> V_26 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
snprintf ( V_8 -> V_269 ,
sizeof( V_8 -> V_269 ) - 1 ,
L_63 , F_86 ( V_33 ) ,
V_8 -> V_20 ) ;
V_266 = F_85 ( V_6 -> V_17 , V_8 -> V_27 ,
F_49 , 0 ,
V_8 -> V_269 , V_8 ) ;
if ( V_266 ) {
F_30 ( V_33 , L_61 ,
V_8 -> V_27 ) ;
goto V_270;
}
F_87 ( V_8 -> V_27 ,
& V_8 -> V_25 ) ;
}
return 0 ;
V_270:
for ( V_7 -- ; V_7 < V_6 -> V_11 ; V_7 -- ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_87 ( V_8 -> V_27 , NULL ) ;
F_88 ( V_6 -> V_17 , V_8 -> V_27 , V_8 ) ;
}
if ( V_6 -> V_101 -> V_145 && ( V_6 -> V_141 != V_6 -> V_146 ) )
F_88 ( V_6 -> V_17 , V_6 -> V_146 , V_6 ) ;
V_268:
F_88 ( V_6 -> V_17 , V_6 -> V_141 , V_6 ) ;
return V_266 ;
}
static void F_89 ( struct V_5 * V_6 )
{
struct V_12 * V_8 ;
unsigned int V_7 ;
F_88 ( V_6 -> V_17 , V_6 -> V_141 , V_6 ) ;
if ( V_6 -> V_101 -> V_145 && ( V_6 -> V_141 != V_6 -> V_146 ) )
F_88 ( V_6 -> V_17 , V_6 -> V_146 , V_6 ) ;
if ( ! V_6 -> V_26 )
return;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_87 ( V_8 -> V_27 , NULL ) ;
F_88 ( V_6 -> V_17 , V_8 -> V_27 , V_8 ) ;
}
}
void F_90 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_64 ) ;
V_6 -> V_271 = V_272 ;
V_6 -> V_273 = V_274 ;
V_41 -> V_275 ( V_6 ) ;
F_52 ( L_65 ) ;
}
void F_91 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_66 ) ;
V_6 -> V_276 = V_41 -> V_277 ( V_6 , V_278 ) ;
V_6 -> V_279 = V_278 ;
V_6 -> V_280 = V_281 ;
V_41 -> V_282 ( V_6 ) ;
F_52 ( L_67 ) ;
}
static void F_92 ( struct V_5 * V_6 )
{
struct V_283 * V_284 = & V_6 -> V_284 ;
struct V_13 * V_14 ;
struct V_285 * V_286 ;
unsigned int V_7 , V_287 ;
F_52 ( L_68 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] -> V_10 ;
if ( ! V_14 )
break;
for ( V_287 = 0 ; V_287 < V_14 -> V_35 ; V_287 ++ ) {
V_286 = F_93 ( V_14 , V_287 ) ;
V_284 -> V_288 ( V_6 , V_286 ) ;
}
}
F_52 ( L_69 ) ;
}
static void F_94 ( struct V_5 * V_6 )
{
struct V_283 * V_284 = & V_6 -> V_284 ;
struct V_13 * V_14 ;
struct V_285 * V_286 ;
unsigned int V_7 , V_287 ;
F_52 ( L_70 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_14 = V_6 -> V_8 [ V_7 ] -> V_9 ;
if ( ! V_14 )
break;
for ( V_287 = 0 ; V_287 < V_14 -> V_35 ; V_287 ++ ) {
V_286 = F_93 ( V_14 , V_287 ) ;
V_284 -> V_288 ( V_6 , V_286 ) ;
}
}
F_52 ( L_71 ) ;
}
static int F_95 ( struct V_5 * V_6 )
{
V_6 -> V_289 = - 1 ;
V_6 -> V_290 = V_291 ;
return V_6 -> V_143 . V_292 ( V_6 ) ;
}
int F_96 ( struct V_44 * V_33 , unsigned int V_293 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
unsigned long V_294 ;
F_52 ( L_72 ) ;
if ( ! F_98 ( V_33 ) ||
( V_293 == V_295 && V_6 -> V_296 ) ) {
F_30 ( V_33 , L_73 ) ;
F_52 ( L_74 ) ;
return - V_297 ;
}
F_99 ( & V_6 -> V_30 , V_294 ) ;
if ( V_293 == V_298 )
F_100 ( V_33 ) ;
F_101 ( V_33 ) ;
F_61 ( V_6 ) ;
F_102 ( V_6 -> V_135 ) ;
V_41 -> V_299 ( V_6 ) ;
V_41 -> V_300 ( V_6 ) ;
F_80 ( V_6 , 0 ) ;
V_6 -> V_296 = 1 ;
F_103 ( & V_6 -> V_30 , V_294 ) ;
F_52 ( L_74 ) ;
return 0 ;
}
int F_104 ( struct V_44 * V_33 , unsigned int V_293 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
unsigned long V_294 ;
F_52 ( L_75 ) ;
if ( ! F_98 ( V_33 ) ||
( V_293 == V_295 && ! V_6 -> V_296 ) ) {
F_30 ( V_33 , L_76 ) ;
F_52 ( L_77 ) ;
return - V_297 ;
}
F_99 ( & V_6 -> V_30 , V_294 ) ;
V_6 -> V_296 = 0 ;
F_77 ( V_6 , 0 ) ;
V_41 -> V_301 ( V_6 ) ;
V_41 -> V_302 ( V_6 ) ;
if ( V_293 == V_298 )
F_105 ( V_33 ) ;
F_106 ( V_33 ) ;
F_60 ( V_6 ) ;
F_103 ( & V_6 -> V_30 , V_294 ) ;
F_52 ( L_77 ) ;
return 0 ;
}
static int F_107 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_303 * V_143 = & V_6 -> V_143 ;
struct V_44 * V_33 = V_6 -> V_33 ;
int V_266 ;
F_52 ( L_78 ) ;
V_266 = V_41 -> V_304 ( V_6 ) ;
if ( V_266 )
return V_266 ;
F_77 ( V_6 , 1 ) ;
V_266 = F_83 ( V_6 ) ;
if ( V_266 )
goto V_305;
V_266 = V_143 -> V_306 ( V_6 ) ;
if ( V_266 )
goto V_307;
V_41 -> V_308 ( V_6 ) ;
V_41 -> V_309 ( V_6 ) ;
F_108 ( V_33 ) ;
F_106 ( V_33 ) ;
F_60 ( V_6 ) ;
F_46 ( V_6 -> V_135 , & V_6 -> V_159 ) ;
F_109 ( V_310 , & V_6 -> V_311 ) ;
F_52 ( L_79 ) ;
return 0 ;
V_307:
F_89 ( V_6 ) ;
V_305:
F_80 ( V_6 , 1 ) ;
V_41 -> exit ( V_6 ) ;
return V_266 ;
}
static void F_110 ( struct V_5 * V_6 )
{
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_303 * V_143 = & V_6 -> V_143 ;
struct V_12 * V_8 ;
struct V_44 * V_33 = V_6 -> V_33 ;
struct V_312 * V_313 ;
unsigned int V_7 ;
F_52 ( L_80 ) ;
if ( F_111 ( V_310 , & V_6 -> V_311 ) )
return;
F_101 ( V_33 ) ;
F_61 ( V_6 ) ;
F_102 ( V_6 -> V_135 ) ;
F_76 ( V_6 ) ;
V_41 -> V_314 ( V_6 ) ;
V_41 -> V_315 ( V_6 ) ;
V_143 -> V_316 ( V_6 ) ;
F_89 ( V_6 ) ;
F_80 ( V_6 , 1 ) ;
V_41 -> exit ( V_6 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
if ( ! V_8 -> V_10 )
continue;
V_313 = F_112 ( V_33 , V_8 -> V_20 ) ;
F_113 ( V_313 ) ;
}
F_114 ( V_310 , & V_6 -> V_311 ) ;
F_52 ( L_81 ) ;
}
static void F_115 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = F_55 ( V_158 ,
struct V_5 ,
V_86 ) ;
F_116 () ;
F_110 ( V_6 ) ;
F_92 ( V_6 ) ;
F_94 ( V_6 ) ;
F_117 () ;
F_30 ( V_6 -> V_33 , L_82 ) ;
}
static void F_118 ( struct V_5 * V_6 )
{
F_52 ( L_83 ) ;
if ( ! F_98 ( V_6 -> V_33 ) )
return;
F_110 ( V_6 ) ;
F_92 ( V_6 ) ;
F_94 ( V_6 ) ;
F_107 ( V_6 ) ;
F_52 ( L_84 ) ;
}
static void F_119 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = F_55 ( V_158 ,
struct V_5 ,
V_123 ) ;
F_116 () ;
F_118 ( V_6 ) ;
F_117 () ;
}
static void F_120 ( struct V_157 * V_158 )
{
struct V_5 * V_6 = F_55 ( V_158 ,
struct V_5 ,
V_136 ) ;
struct V_317 V_318 ;
T_3 V_319 ;
unsigned long V_294 ;
F_99 ( & V_6 -> V_320 , V_294 ) ;
if ( ! V_6 -> V_321 )
goto V_322;
if ( V_6 -> V_133 ) {
V_319 = F_121 ( & V_6 -> V_323 ,
V_6 -> V_133 ) ;
memset ( & V_318 , 0 , sizeof( V_318 ) ) ;
V_318 . V_324 = F_122 ( V_319 ) ;
F_123 ( V_6 -> V_321 , & V_318 ) ;
}
F_124 ( V_6 -> V_321 ) ;
V_6 -> V_321 = NULL ;
V_322:
F_103 ( & V_6 -> V_320 , V_294 ) ;
}
static int F_125 ( struct V_5 * V_6 ,
struct V_325 * V_325 )
{
if ( F_126 ( V_325 -> V_326 , & V_6 -> V_327 ,
sizeof( V_6 -> V_327 ) ) )
return - V_328 ;
return 0 ;
}
static int F_127 ( struct V_5 * V_6 ,
struct V_325 * V_325 )
{
struct V_329 V_330 ;
unsigned int V_331 ;
if ( F_128 ( & V_330 , V_325 -> V_326 , sizeof( V_330 ) ) )
return - V_328 ;
if ( V_330 . V_294 )
return - V_297 ;
V_331 = 0 ;
switch ( V_330 . V_332 ) {
case V_333 :
break;
case V_334 :
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
default:
return - V_337 ;
}
switch ( V_330 . V_338 ) {
case V_339 :
break;
case V_340 :
case V_341 :
F_44 ( V_331 , V_335 , V_342 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_343 :
F_44 ( V_331 , V_335 , V_344 , 1 ) ;
case V_345 :
F_44 ( V_331 , V_335 , V_346 , 1 ) ;
F_44 ( V_331 , V_335 , V_347 , 1 ) ;
F_44 ( V_331 , V_335 , V_348 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_349 :
F_44 ( V_331 , V_335 , V_344 , 1 ) ;
case V_350 :
F_44 ( V_331 , V_335 , V_346 , 1 ) ;
F_44 ( V_331 , V_335 , V_347 , 1 ) ;
F_44 ( V_331 , V_335 , V_351 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_352 :
F_44 ( V_331 , V_335 , V_344 , 1 ) ;
case V_353 :
F_44 ( V_331 , V_335 , V_346 , 1 ) ;
F_44 ( V_331 , V_335 , V_347 , 1 ) ;
F_44 ( V_331 , V_335 , V_351 , 1 ) ;
F_44 ( V_331 , V_335 , V_354 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_355 :
F_44 ( V_331 , V_335 , V_356 , 1 ) ;
F_44 ( V_331 , V_335 , V_348 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_357 :
F_44 ( V_331 , V_335 , V_356 , 1 ) ;
F_44 ( V_331 , V_335 , V_351 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_358 :
F_44 ( V_331 , V_335 , V_356 , 1 ) ;
F_44 ( V_331 , V_335 , V_354 , 1 ) ;
F_44 ( V_331 , V_335 , V_351 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_359 :
F_44 ( V_331 , V_335 , V_344 , 1 ) ;
F_44 ( V_331 , V_335 , V_360 , 1 ) ;
F_44 ( V_331 , V_335 , V_346 , 1 ) ;
F_44 ( V_331 , V_335 , V_347 , 1 ) ;
F_44 ( V_331 , V_335 , V_348 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_361 :
F_44 ( V_331 , V_335 , V_344 , 1 ) ;
F_44 ( V_331 , V_335 , V_360 , 1 ) ;
F_44 ( V_331 , V_335 , V_346 , 1 ) ;
F_44 ( V_331 , V_335 , V_347 , 1 ) ;
F_44 ( V_331 , V_335 , V_351 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
case V_362 :
F_44 ( V_331 , V_335 , V_344 , 1 ) ;
F_44 ( V_331 , V_335 , V_360 , 1 ) ;
F_44 ( V_331 , V_335 , V_346 , 1 ) ;
F_44 ( V_331 , V_335 , V_347 , 1 ) ;
F_44 ( V_331 , V_335 , V_354 , 1 ) ;
F_44 ( V_331 , V_335 , V_351 , 1 ) ;
F_44 ( V_331 , V_335 , V_336 , 1 ) ;
break;
default:
return - V_337 ;
}
V_6 -> V_41 . V_363 ( V_6 , V_331 ) ;
memcpy ( & V_6 -> V_327 , & V_330 , sizeof( V_330 ) ) ;
return 0 ;
}
static void F_129 ( struct V_5 * V_6 ,
struct V_364 * V_365 ,
struct V_366 * V_367 )
{
unsigned long V_294 ;
if ( F_41 ( V_367 -> V_368 , V_369 , V_370 ) ) {
F_99 ( & V_6 -> V_320 , V_294 ) ;
if ( V_6 -> V_321 ) {
F_44 ( V_367 -> V_368 ,
V_369 , V_370 , 0 ) ;
} else {
V_6 -> V_321 = F_130 ( V_365 ) ;
F_131 ( V_365 ) -> V_371 |= V_372 ;
}
F_103 ( & V_6 -> V_320 , V_294 ) ;
}
F_132 ( V_365 ) ;
}
static void F_133 ( struct V_364 * V_365 , struct V_366 * V_367 )
{
if ( F_134 ( V_365 ) )
V_367 -> V_373 = F_135 ( V_365 ) ;
}
static int F_136 ( struct V_364 * V_365 , struct V_366 * V_367 )
{
int V_266 ;
if ( ! F_41 ( V_367 -> V_368 , V_369 ,
V_374 ) )
return 0 ;
V_266 = F_137 ( V_365 , 0 ) ;
if ( V_266 )
return V_266 ;
if ( F_41 ( V_367 -> V_368 , V_369 , V_375 ) ) {
V_367 -> V_376 = F_138 ( V_365 ) +
F_139 ( V_365 ) ;
V_367 -> V_377 = F_139 ( V_365 ) ;
} else {
V_367 -> V_376 = F_140 ( V_365 ) +
F_141 ( V_365 ) ;
V_367 -> V_377 = F_141 ( V_365 ) ;
}
V_367 -> V_378 = V_365 -> V_379 - V_367 -> V_376 ;
V_367 -> V_380 = F_131 ( V_365 ) -> V_381 ;
F_52 ( L_85 , V_367 -> V_376 ) ;
F_52 ( L_86 ,
V_367 -> V_377 , V_367 -> V_378 ) ;
F_52 ( L_87 , V_367 -> V_380 ) ;
V_367 -> V_382 = F_131 ( V_365 ) -> V_383 ;
V_367 -> V_384 += ( V_367 -> V_382 - 1 ) * V_367 -> V_376 ;
return 0 ;
}
static bool F_142 ( struct V_5 * V_6 , struct V_364 * V_365 )
{
struct V_255 * V_101 ;
if ( V_6 -> V_260 )
return false ;
if ( ! V_365 -> V_385 )
return false ;
if ( V_365 -> V_386 != V_387 )
return false ;
switch ( V_365 -> V_388 ) {
case F_143 ( V_389 ) :
if ( F_144 ( V_365 ) -> V_388 != V_390 )
return false ;
break;
case F_143 ( V_391 ) :
if ( F_145 ( V_365 ) -> V_392 != V_390 )
return false ;
break;
default:
return false ;
}
F_146 (vdata, &pdata->vxlan_ports, list) {
if ( ( V_365 -> V_388 == F_143 ( V_389 ) ) &&
( V_101 -> V_393 == V_394 ) &&
( V_101 -> V_258 == F_147 ( V_365 ) -> V_395 ) )
return true ;
else if ( ( V_365 -> V_388 == F_143 ( V_391 ) ) &&
( V_101 -> V_393 == V_396 ) &&
( V_101 -> V_258 == F_147 ( V_365 ) -> V_395 ) )
return true ;
}
return false ;
}
static int F_148 ( struct V_364 * V_365 )
{
if ( V_365 -> V_386 != V_387 )
return 0 ;
if ( ! F_149 ( V_365 ) )
return 0 ;
F_52 ( L_88 ) ;
return 1 ;
}
static void F_150 ( struct V_5 * V_6 ,
struct V_13 * V_14 , struct V_364 * V_365 ,
struct V_366 * V_367 )
{
struct V_397 * V_398 ;
unsigned int V_399 ;
unsigned int V_379 ;
unsigned int V_7 ;
V_367 -> V_365 = V_365 ;
V_399 = 0 ;
V_367 -> V_35 = 0 ;
V_367 -> V_382 = 1 ;
V_367 -> V_384 = V_365 -> V_379 ;
if ( F_148 ( V_365 ) ) {
if ( F_131 ( V_365 ) -> V_381 != V_14 -> V_38 . V_400 ) {
V_399 = 1 ;
V_367 -> V_35 ++ ;
}
V_367 -> V_35 ++ ;
F_44 ( V_367 -> V_368 , V_369 ,
V_374 , 1 ) ;
F_44 ( V_367 -> V_368 , V_369 ,
V_401 , 1 ) ;
} else if ( V_365 -> V_386 == V_387 )
F_44 ( V_367 -> V_368 , V_369 ,
V_401 , 1 ) ;
if ( F_142 ( V_6 , V_365 ) )
F_44 ( V_367 -> V_368 , V_369 ,
V_375 , 1 ) ;
if ( F_134 ( V_365 ) ) {
if ( F_135 ( V_365 ) != V_14 -> V_38 . V_402 )
if ( ! V_399 ) {
V_399 = 1 ;
V_367 -> V_35 ++ ;
}
F_44 ( V_367 -> V_368 , V_369 ,
V_403 , 1 ) ;
}
if ( ( F_131 ( V_365 ) -> V_371 & V_404 ) &&
( V_6 -> V_327 . V_332 == V_334 ) )
F_44 ( V_367 -> V_368 , V_369 ,
V_370 , 1 ) ;
for ( V_379 = F_151 ( V_365 ) ; V_379 ; ) {
V_367 -> V_35 ++ ;
V_379 -= F_152 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_7 = 0 ; V_7 < F_131 ( V_365 ) -> V_405 ; V_7 ++ ) {
V_398 = & F_131 ( V_365 ) -> V_406 [ V_7 ] ;
for ( V_379 = F_153 ( V_398 ) ; V_379 ; ) {
V_367 -> V_35 ++ ;
V_379 -= F_152 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_154 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_283 * V_284 = & V_6 -> V_284 ;
int V_266 ;
F_52 ( L_89 ) ;
snprintf ( V_6 -> V_407 , sizeof( V_6 -> V_407 ) - 1 , L_90 ,
F_86 ( V_33 ) ) ;
snprintf ( V_6 -> V_267 , sizeof( V_6 -> V_267 ) - 1 , L_91 ,
F_86 ( V_33 ) ) ;
snprintf ( V_6 -> V_408 , sizeof( V_6 -> V_408 ) - 1 , L_92 ,
F_86 ( V_33 ) ) ;
V_6 -> V_135 =
F_155 ( F_86 ( V_33 ) ) ;
if ( ! V_6 -> V_135 ) {
F_156 ( V_33 , L_93 ) ;
return - V_34 ;
}
V_6 -> V_409 =
F_155 ( V_6 -> V_407 ) ;
if ( ! V_6 -> V_409 ) {
F_156 ( V_33 , L_94 ) ;
V_266 = - V_34 ;
goto V_410;
}
V_266 = F_95 ( V_6 ) ;
if ( V_266 )
goto V_411;
V_266 = F_157 ( V_6 -> V_412 ) ;
if ( V_266 ) {
F_30 ( V_33 , L_95 ) ;
goto V_411;
}
V_266 = F_157 ( V_6 -> V_413 ) ;
if ( V_266 ) {
F_30 ( V_33 , L_96 ) ;
goto V_414;
}
V_266 = F_20 ( V_33 , V_33 -> V_45 ) ;
if ( V_266 < 0 )
goto V_415;
V_6 -> V_46 = V_266 ;
V_266 = F_7 ( V_6 ) ;
if ( V_266 )
goto V_415;
V_266 = V_284 -> V_416 ( V_6 ) ;
if ( V_266 )
goto V_417;
F_158 ( & V_6 -> V_159 , F_54 ) ;
F_158 ( & V_6 -> V_123 , F_119 ) ;
F_158 ( & V_6 -> V_86 , F_115 ) ;
F_158 ( & V_6 -> V_136 , F_120 ) ;
F_58 ( V_6 ) ;
V_266 = F_107 ( V_6 ) ;
if ( V_266 )
goto V_418;
F_109 ( V_419 , & V_6 -> V_311 ) ;
F_52 ( L_97 ) ;
return 0 ;
V_418:
V_284 -> V_420 ( V_6 ) ;
V_417:
F_4 ( V_6 ) ;
V_415:
F_159 ( V_6 -> V_413 ) ;
V_414:
F_159 ( V_6 -> V_412 ) ;
V_411:
F_160 ( V_6 -> V_409 ) ;
V_410:
F_160 ( V_6 -> V_135 ) ;
return V_266 ;
}
static int F_161 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_283 * V_284 = & V_6 -> V_284 ;
F_52 ( L_98 ) ;
F_110 ( V_6 ) ;
V_284 -> V_420 ( V_6 ) ;
F_4 ( V_6 ) ;
F_159 ( V_6 -> V_413 ) ;
F_159 ( V_6 -> V_412 ) ;
F_102 ( V_6 -> V_409 ) ;
F_160 ( V_6 -> V_409 ) ;
F_102 ( V_6 -> V_135 ) ;
F_160 ( V_6 -> V_135 ) ;
F_114 ( V_419 , & V_6 -> V_311 ) ;
F_52 ( L_99 ) ;
return 0 ;
}
static int F_162 ( struct V_364 * V_365 , struct V_44 * V_33 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_283 * V_284 = & V_6 -> V_284 ;
struct V_12 * V_8 ;
struct V_13 * V_14 ;
struct V_366 * V_367 ;
struct V_312 * V_313 ;
int V_266 ;
F_52 ( L_100 , V_365 -> V_379 ) ;
V_8 = V_6 -> V_8 [ V_365 -> V_421 ] ;
V_313 = F_112 ( V_33 , V_8 -> V_20 ) ;
V_14 = V_8 -> V_10 ;
V_367 = & V_14 -> V_422 ;
V_266 = V_423 ;
if ( V_365 -> V_379 == 0 ) {
F_163 ( V_6 , V_424 , V_33 ,
L_101 ) ;
F_124 ( V_365 ) ;
goto V_425;
}
memset ( V_367 , 0 , sizeof( * V_367 ) ) ;
F_150 ( V_6 , V_14 , V_365 , V_367 ) ;
V_266 = F_17 ( V_8 , V_14 , V_367 -> V_35 ) ;
if ( V_266 )
goto V_425;
V_266 = F_136 ( V_365 , V_367 ) ;
if ( V_266 ) {
F_163 ( V_6 , V_424 , V_33 ,
L_102 ) ;
F_124 ( V_365 ) ;
goto V_425;
}
F_133 ( V_365 , V_367 ) ;
if ( ! V_284 -> V_426 ( V_8 , V_365 ) ) {
F_124 ( V_365 ) ;
goto V_425;
}
F_129 ( V_6 , V_365 , V_367 ) ;
F_164 ( V_313 , V_367 -> V_384 ) ;
V_41 -> V_427 ( V_8 ) ;
if ( F_165 ( V_6 ) )
F_166 ( V_33 , V_365 , true ) ;
F_17 ( V_8 , V_14 , V_428 ) ;
V_266 = V_423 ;
V_425:
return V_266 ;
}
static void F_167 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_103 ) ;
V_41 -> V_429 ( V_6 ) ;
F_52 ( L_104 ) ;
}
static int F_168 ( struct V_44 * V_33 , void * V_430 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_431 * V_432 = V_430 ;
F_52 ( L_105 ) ;
if ( ! F_169 ( V_432 -> V_433 ) )
return - V_434 ;
memcpy ( V_33 -> V_435 , V_432 -> V_433 , V_33 -> V_436 ) ;
V_41 -> V_437 ( V_6 , V_33 -> V_435 ) ;
F_52 ( L_106 ) ;
return 0 ;
}
static int F_170 ( struct V_44 * V_33 , struct V_325 * V_325 , int V_438 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
int V_266 ;
switch ( V_438 ) {
case V_439 :
V_266 = F_125 ( V_6 , V_325 ) ;
break;
case V_440 :
V_266 = F_127 ( V_6 , V_325 ) ;
break;
default:
V_266 = - V_441 ;
}
return V_266 ;
}
static int F_171 ( struct V_44 * V_33 , int V_45 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
int V_266 ;
F_52 ( L_107 ) ;
V_266 = F_20 ( V_33 , V_45 ) ;
if ( V_266 < 0 )
return V_266 ;
V_6 -> V_46 = V_266 ;
V_33 -> V_45 = V_45 ;
F_118 ( V_6 ) ;
F_52 ( L_108 ) ;
return 0 ;
}
static void F_172 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
F_173 ( V_33 , L_109 ) ;
F_34 ( & V_6 -> V_123 ) ;
}
static void F_174 ( struct V_44 * V_33 ,
struct V_442 * V_443 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_444 * V_445 = & V_6 -> V_446 ;
F_52 ( L_110 , V_447 ) ;
V_6 -> V_41 . V_448 ( V_6 ) ;
V_443 -> V_449 = V_445 -> V_450 ;
V_443 -> V_451 = V_445 -> V_452 ;
V_443 -> V_453 = V_445 -> V_450 -
V_445 -> V_454 -
V_445 -> V_455 -
V_445 -> V_456 ;
V_443 -> V_457 = V_445 -> V_455 ;
V_443 -> V_458 = V_445 -> V_459 ;
V_443 -> V_460 = V_445 -> V_461 ;
V_443 -> V_462 = V_445 -> V_463 ;
V_443 -> V_382 = V_445 -> V_464 ;
V_443 -> V_384 = V_445 -> V_465 ;
V_443 -> V_466 = V_445 -> V_464 - V_445 -> V_467 ;
V_443 -> V_468 = V_33 -> V_469 . V_468 ;
F_52 ( L_111 , V_447 ) ;
}
static int F_175 ( struct V_44 * V_33 , T_4 V_470 ,
T_5 V_471 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_110 , V_447 ) ;
F_114 ( V_471 , V_6 -> V_472 ) ;
V_41 -> V_473 ( V_6 ) ;
F_52 ( L_111 , V_447 ) ;
return 0 ;
}
static int F_176 ( struct V_44 * V_33 , T_4 V_470 ,
T_5 V_471 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
F_52 ( L_110 , V_447 ) ;
F_109 ( V_471 , V_6 -> V_472 ) ;
V_41 -> V_473 ( V_6 ) ;
F_52 ( L_111 , V_447 ) ;
return 0 ;
}
static void F_177 ( struct V_44 * V_33 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_12 * V_8 ;
unsigned int V_7 ;
F_52 ( L_112 ) ;
if ( V_6 -> V_26 ) {
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_49 ( V_8 -> V_27 , V_8 ) ;
}
} else {
F_178 ( V_6 -> V_141 ) ;
F_48 ( V_6 -> V_141 , V_6 ) ;
F_179 ( V_6 -> V_141 ) ;
}
F_52 ( L_113 ) ;
}
static int F_180 ( struct V_44 * V_33 , enum V_474 type ,
void * V_475 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_476 * V_477 = V_475 ;
T_6 V_478 ;
if ( type != V_479 )
return - V_441 ;
V_477 -> V_480 = V_481 ;
V_478 = V_477 -> V_482 ;
if ( V_478 > V_6 -> V_167 . V_221 )
return - V_297 ;
V_6 -> V_483 = V_478 ;
V_6 -> V_41 . V_484 ( V_6 ) ;
return 0 ;
}
static T_7 F_181 ( struct V_44 * V_33 ,
T_7 V_250 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
T_7 V_485 , V_486 ;
V_485 = V_248 | V_487 ;
V_486 = V_485 | V_249 ;
V_6 -> V_254 = V_250 & V_486 ;
if ( ! V_6 -> V_254 )
return V_250 ;
if ( ! V_6 -> V_167 . V_201 )
return V_250 & ~ V_486 ;
if ( ( V_250 & V_249 ) &&
! ( V_250 & V_248 ) ) {
F_182 ( V_33 ,
L_114 ) ;
V_250 |= V_248 ;
}
if ( ( V_250 & V_485 ) != V_485 ) {
F_182 ( V_33 ,
L_115 ) ;
V_250 |= V_485 ;
}
if ( V_250 & ( V_242 | V_243 ) ) {
if ( ! ( V_250 & V_249 ) ) {
F_182 ( V_33 ,
L_116 ) ;
V_250 |= V_249 ;
}
} else {
if ( V_250 & V_249 ) {
F_182 ( V_33 ,
L_117 ) ;
V_250 &= ~ V_249 ;
}
}
V_6 -> V_254 = V_250 & V_486 ;
if ( V_6 -> V_260 ) {
F_182 ( V_33 ,
L_118 ) ;
V_250 &= ~ V_486 ;
}
return V_250 ;
}
static int F_183 ( struct V_44 * V_33 ,
T_7 V_250 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_53 * V_41 = & V_6 -> V_41 ;
T_7 V_488 , V_489 , V_490 , V_491 ;
T_7 V_492 ;
int V_266 = 0 ;
V_488 = V_6 -> V_493 & V_494 ;
V_489 = V_6 -> V_493 & V_244 ;
V_490 = V_6 -> V_493 & V_495 ;
V_491 = V_6 -> V_493 & V_496 ;
V_492 = V_6 -> V_493 & V_248 ;
if ( ( V_250 & V_494 ) && ! V_488 )
V_266 = V_41 -> V_497 ( V_6 ) ;
else if ( ! ( V_250 & V_494 ) && V_488 )
V_266 = V_41 -> V_498 ( V_6 ) ;
if ( V_266 )
return V_266 ;
if ( ( V_250 & V_244 ) && ! V_489 )
V_41 -> V_499 ( V_6 ) ;
else if ( ! ( V_250 & V_244 ) && V_489 )
V_41 -> V_500 ( V_6 ) ;
if ( ( V_250 & V_495 ) && ! V_490 )
V_41 -> V_501 ( V_6 ) ;
else if ( ! ( V_250 & V_495 ) && V_490 )
V_41 -> V_502 ( V_6 ) ;
if ( ( V_250 & V_496 ) && ! V_491 )
V_41 -> V_503 ( V_6 ) ;
else if ( ! ( V_250 & V_496 ) && V_491 )
V_41 -> V_504 ( V_6 ) ;
if ( ( V_250 & V_248 ) && ! V_492 )
F_75 ( V_6 ) ;
else if ( ! ( V_250 & V_248 ) && V_492 )
F_69 ( V_6 ) ;
V_6 -> V_493 = V_250 ;
F_52 ( L_119 ) ;
return 0 ;
}
static void F_184 ( struct V_44 * V_33 ,
struct V_505 * V_506 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_255 * V_101 ;
if ( ! V_6 -> V_167 . V_201 )
return;
if ( V_506 -> type != V_507 )
return;
V_6 -> V_508 ++ ;
F_14 ( V_6 , V_32 , V_33 ,
L_120 ,
V_506 -> V_393 , F_74 ( V_506 -> V_258 ) ) ;
if ( V_6 -> V_260 )
return;
V_101 = F_3 ( sizeof( * V_101 ) , V_509 ) ;
if ( ! V_101 ) {
V_6 -> V_260 = 1 ;
F_14 ( V_6 , V_32 , V_33 ,
L_121 ) ;
F_69 ( V_6 ) ;
return;
}
V_101 -> V_393 = V_506 -> V_393 ;
V_101 -> V_258 = V_506 -> V_258 ;
F_185 ( & V_101 -> V_257 , & V_6 -> V_256 ) ;
if ( V_6 -> V_508 == 1 ) {
F_75 ( V_6 ) ;
return;
}
}
static void F_186 ( struct V_44 * V_33 ,
struct V_505 * V_506 )
{
struct V_5 * V_6 = F_97 ( V_33 ) ;
struct V_255 * V_101 ;
if ( ! V_6 -> V_167 . V_201 )
return;
if ( V_506 -> type != V_507 )
return;
F_14 ( V_6 , V_32 , V_33 ,
L_122 ,
V_506 -> V_393 , F_74 ( V_506 -> V_258 ) ) ;
F_146 (vdata, &pdata->vxlan_ports, list) {
if ( V_101 -> V_393 != V_506 -> V_393 )
continue;
if ( V_101 -> V_258 != V_506 -> V_258 )
continue;
F_187 ( & V_101 -> V_257 ) ;
F_6 ( V_101 ) ;
break;
}
V_6 -> V_508 -- ;
if ( ! V_6 -> V_508 ) {
F_76 ( V_6 ) ;
return;
}
if ( V_6 -> V_260 )
return;
V_101 = F_73 ( & V_6 -> V_256 ,
struct V_255 , V_257 ) ;
if ( V_6 -> V_253 == F_74 ( V_101 -> V_258 ) )
return;
V_6 -> V_253 = F_74 ( V_101 -> V_258 ) ;
V_6 -> V_41 . V_510 ( V_6 ) ;
}
static T_7 F_188 ( struct V_364 * V_365 ,
struct V_44 * V_33 ,
T_7 V_250 )
{
V_250 = F_189 ( V_365 , V_250 ) ;
V_250 = F_190 ( V_365 , V_250 ) ;
return V_250 ;
}
const struct V_511 * F_191 ( void )
{
return & V_512 ;
}
static void F_192 ( struct V_12 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_283 * V_284 = & V_6 -> V_284 ;
struct V_13 * V_14 = V_8 -> V_9 ;
struct V_285 * V_286 ;
while ( V_14 -> V_37 != V_14 -> V_36 ) {
V_286 = F_93 ( V_14 , V_14 -> V_37 ) ;
V_284 -> V_288 ( V_6 , V_286 ) ;
if ( V_284 -> V_513 ( V_6 , V_14 , V_286 ) )
break;
V_41 -> V_514 ( V_6 , V_286 , V_14 -> V_37 ) ;
V_14 -> V_37 ++ ;
}
F_193 () ;
V_286 = F_93 ( V_14 , V_14 -> V_37 - 1 ) ;
F_45 ( V_8 , V_515 ,
F_194 ( V_286 -> V_516 ) ) ;
}
static struct V_364 * F_195 ( struct V_5 * V_6 ,
struct V_155 * V_118 ,
struct V_285 * V_286 ,
unsigned int V_379 )
{
struct V_364 * V_365 ;
T_6 * V_367 ;
V_365 = F_196 ( V_118 , V_286 -> V_517 . V_518 . V_519 ) ;
if ( ! V_365 )
return NULL ;
F_197 ( V_6 -> V_17 , V_286 -> V_517 . V_518 . V_520 ,
V_286 -> V_517 . V_518 . V_521 ,
V_286 -> V_517 . V_518 . V_519 , V_522 ) ;
V_367 = F_198 ( V_286 -> V_517 . V_518 . V_523 . V_524 ) +
V_286 -> V_517 . V_518 . V_523 . V_525 ;
F_199 ( V_365 , V_367 , V_379 ) ;
F_200 ( V_365 , V_379 ) ;
return V_365 ;
}
static unsigned int F_201 ( struct V_285 * V_286 ,
struct V_366 * V_367 )
{
if ( ! F_41 ( V_367 -> V_368 , V_526 , V_527 ) )
return 0 ;
if ( V_286 -> V_517 . V_528 )
return V_286 -> V_517 . V_528 ;
if ( ! F_41 ( V_367 -> V_368 , V_526 , V_529 ) )
return V_286 -> V_517 . V_518 . V_519 ;
return F_152 (unsigned int, rdata->rx.hdr.dma_len, rdata->rx.len) ;
}
static unsigned int F_202 ( struct V_285 * V_286 ,
struct V_366 * V_367 ,
unsigned int V_379 )
{
if ( ! F_41 ( V_367 -> V_368 , V_526 , V_529 ) )
return V_286 -> V_517 . V_530 . V_519 ;
return V_286 -> V_517 . V_379 - V_379 ;
}
static int F_203 ( struct V_12 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_283 * V_284 = & V_6 -> V_284 ;
struct V_13 * V_14 = V_8 -> V_10 ;
struct V_285 * V_286 ;
struct V_531 * V_532 ;
struct V_44 * V_33 = V_6 -> V_33 ;
struct V_312 * V_313 ;
int V_533 = 0 ;
unsigned int V_382 = 0 , V_384 = 0 ;
unsigned int V_36 ;
F_52 ( L_123 ) ;
if ( ! V_14 )
return 0 ;
V_36 = V_14 -> V_36 ;
F_204 () ;
V_313 = F_112 ( V_33 , V_8 -> V_20 ) ;
while ( ( V_533 < V_534 ) &&
( V_14 -> V_37 != V_36 ) ) {
V_286 = F_93 ( V_14 , V_14 -> V_37 ) ;
V_532 = V_286 -> V_532 ;
if ( ! V_41 -> V_535 ( V_532 ) )
break;
F_205 () ;
if ( F_206 ( V_6 ) )
F_207 ( V_6 , V_14 , V_14 -> V_37 , 1 , 0 ) ;
if ( V_41 -> V_536 ( V_532 ) ) {
V_382 += V_286 -> V_38 . V_537 ;
V_384 += V_286 -> V_38 . V_538 ;
}
V_284 -> V_288 ( V_6 , V_286 ) ;
V_41 -> V_539 ( V_286 ) ;
V_533 ++ ;
V_14 -> V_37 ++ ;
}
if ( ! V_533 )
return 0 ;
F_208 ( V_313 , V_382 , V_384 ) ;
if ( ( V_14 -> V_38 . V_39 == 1 ) &&
( F_15 ( V_14 ) > V_540 ) ) {
V_14 -> V_38 . V_39 = 0 ;
F_209 ( V_313 ) ;
}
F_52 ( L_124 , V_533 ) ;
return V_533 ;
}
static int F_210 ( struct V_12 * V_8 , int V_541 )
{
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_53 * V_41 = & V_6 -> V_41 ;
struct V_13 * V_14 = V_8 -> V_9 ;
struct V_285 * V_286 ;
struct V_366 * V_367 ;
struct V_44 * V_33 = V_6 -> V_33 ;
struct V_155 * V_118 ;
struct V_364 * V_365 ;
struct V_317 * V_318 ;
unsigned int V_542 , error , V_543 , V_544 ;
unsigned int V_379 , V_545 , V_546 , V_547 ;
unsigned int V_548 = 0 ;
int V_549 = 0 ;
F_52 ( L_125 , V_541 ) ;
if ( ! V_14 )
return 0 ;
V_542 = 0 ;
V_543 = 0 ;
V_118 = ( V_6 -> V_26 ) ? & V_8 -> V_118 : & V_6 -> V_118 ;
V_286 = F_93 ( V_14 , V_14 -> V_36 ) ;
V_367 = & V_14 -> V_422 ;
while ( V_549 < V_541 ) {
F_52 ( L_126 , V_14 -> V_36 ) ;
if ( ! V_548 && V_286 -> V_550 ) {
V_365 = V_286 -> V_551 . V_365 ;
error = V_286 -> V_551 . error ;
V_379 = V_286 -> V_551 . V_379 ;
} else {
memset ( V_367 , 0 , sizeof( * V_367 ) ) ;
V_365 = NULL ;
error = 0 ;
V_379 = 0 ;
}
V_552:
V_286 = F_93 ( V_14 , V_14 -> V_36 ) ;
if ( F_16 ( V_14 ) > ( V_553 >> 3 ) )
F_192 ( V_8 ) ;
if ( V_41 -> V_554 ( V_8 ) )
break;
V_548 ++ ;
V_14 -> V_36 ++ ;
V_542 = F_41 ( V_367 -> V_368 , V_526 ,
V_529 ) ;
V_543 = F_41 ( V_367 -> V_368 ,
V_526 ,
V_555 ) ;
V_544 = F_41 ( V_367 -> V_368 ,
V_526 ,
V_556 ) ;
if ( ( ! V_542 || V_543 ) && error )
goto V_552;
if ( error || V_367 -> V_557 ) {
if ( V_367 -> V_557 )
F_163 ( V_6 , V_558 , V_33 ,
L_127 ) ;
F_211 ( V_365 ) ;
goto V_559;
}
if ( ! V_544 ) {
V_545 = F_201 ( V_286 , V_367 ) ;
V_379 += V_545 ;
V_546 = F_202 ( V_286 , V_367 , V_379 ) ;
V_379 += V_546 ;
if ( ! V_365 ) {
V_365 = F_195 ( V_6 , V_118 , V_286 ,
V_545 ) ;
if ( ! V_365 ) {
error = 1 ;
goto V_560;
}
}
if ( V_546 ) {
F_197 ( V_6 -> V_17 ,
V_286 -> V_517 . V_530 . V_520 ,
V_286 -> V_517 . V_530 . V_521 ,
V_286 -> V_517 . V_530 . V_519 ,
V_522 ) ;
F_212 ( V_365 , F_131 ( V_365 ) -> V_405 ,
V_286 -> V_517 . V_530 . V_523 . V_524 ,
V_286 -> V_517 . V_530 . V_523 . V_525 ,
V_546 ,
V_286 -> V_517 . V_530 . V_519 ) ;
V_286 -> V_517 . V_530 . V_523 . V_524 = NULL ;
}
}
V_560:
if ( ! V_542 || V_543 )
goto V_552;
if ( ! V_365 )
goto V_559;
V_547 = V_33 -> V_45 + V_47 ;
if ( ! ( V_33 -> V_250 & V_495 ) &&
( V_365 -> V_388 == F_143 ( V_561 ) ) )
V_547 += V_49 ;
if ( V_365 -> V_379 > V_547 ) {
F_163 ( V_6 , V_558 , V_33 ,
L_128 ) ;
F_211 ( V_365 ) ;
goto V_559;
}
if ( F_165 ( V_6 ) )
F_166 ( V_33 , V_365 , false ) ;
F_213 ( V_365 ) ;
if ( F_41 ( V_367 -> V_368 ,
V_526 , V_562 ) )
V_365 -> V_386 = V_563 ;
if ( F_41 ( V_367 -> V_368 ,
V_526 , V_564 ) ) {
V_365 -> V_385 = 1 ;
if ( F_41 ( V_367 -> V_368 ,
V_526 , V_565 ) )
V_365 -> V_566 = 1 ;
}
if ( F_41 ( V_367 -> V_368 ,
V_526 , V_403 ) )
F_214 ( V_365 , F_143 ( V_561 ) ,
V_367 -> V_373 ) ;
if ( F_41 ( V_367 -> V_368 ,
V_526 , V_567 ) ) {
T_3 V_319 ;
V_319 = F_121 ( & V_6 -> V_323 ,
V_367 -> V_568 ) ;
V_318 = F_215 ( V_365 ) ;
V_318 -> V_324 = F_122 ( V_319 ) ;
}
if ( F_41 ( V_367 -> V_368 ,
V_526 , V_569 ) )
F_216 ( V_365 , V_367 -> V_570 ,
V_367 -> V_571 ) ;
V_365 -> V_17 = V_33 ;
V_365 -> V_388 = F_217 ( V_365 , V_33 ) ;
F_218 ( V_365 , V_8 -> V_20 ) ;
F_219 ( V_118 , V_365 ) ;
V_559:
V_549 ++ ;
}
if ( V_548 && ( ! V_542 || V_543 ) ) {
V_286 = F_93 ( V_14 , V_14 -> V_36 ) ;
V_286 -> V_550 = 1 ;
V_286 -> V_551 . V_365 = V_365 ;
V_286 -> V_551 . V_379 = V_379 ;
V_286 -> V_551 . error = error ;
}
F_52 ( L_129 , V_549 ) ;
return V_549 ;
}
static int V_262 ( struct V_155 * V_118 , int V_541 )
{
struct V_12 * V_8 = F_55 ( V_118 , struct V_12 ,
V_118 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
int V_533 = 0 ;
F_52 ( L_130 , V_541 ) ;
F_203 ( V_8 ) ;
V_533 = F_210 ( V_8 , V_541 ) ;
if ( ( V_533 < V_541 ) && F_220 ( V_118 , V_533 ) ) {
if ( V_6 -> V_154 )
F_22 ( V_6 , V_8 ) ;
else
F_179 ( V_8 -> V_27 ) ;
}
F_52 ( L_131 , V_533 ) ;
return V_533 ;
}
static int V_264 ( struct V_155 * V_118 , int V_541 )
{
struct V_5 * V_6 = F_55 ( V_118 , struct V_5 ,
V_118 ) ;
struct V_12 * V_8 ;
int V_572 ;
int V_533 , V_573 ;
unsigned int V_7 ;
F_52 ( L_132 , V_541 ) ;
V_533 = 0 ;
V_572 = V_541 / V_6 -> V_31 ;
do {
V_573 = V_533 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_11 ; V_7 ++ ) {
V_8 = V_6 -> V_8 [ V_7 ] ;
F_203 ( V_8 ) ;
if ( V_572 > ( V_541 - V_533 ) )
V_572 = V_541 - V_533 ;
V_533 += F_210 ( V_8 , V_572 ) ;
}
} while ( ( V_533 < V_541 ) && ( V_533 != V_573 ) );
if ( ( V_533 < V_541 ) && F_220 ( V_118 , V_533 ) ) {
F_23 ( V_6 ) ;
}
F_52 ( L_133 , V_533 ) ;
return V_533 ;
}
void F_207 ( struct V_5 * V_6 , struct V_13 * V_14 ,
unsigned int V_574 , unsigned int V_15 , unsigned int V_575 )
{
struct V_285 * V_286 ;
struct V_531 * V_532 ;
while ( V_15 -- ) {
V_286 = F_93 ( V_14 , V_574 ) ;
V_532 = V_286 -> V_532 ;
F_221 ( V_6 -> V_33 ,
L_134 , V_574 ,
( V_575 == 1 ) ? L_135 : L_136 ,
F_222 ( V_532 -> V_576 ) ,
F_222 ( V_532 -> V_577 ) ,
F_222 ( V_532 -> V_578 ) ,
F_222 ( V_532 -> V_579 ) ) ;
V_574 ++ ;
}
}
void F_223 ( struct V_5 * V_6 , struct V_13 * V_14 ,
unsigned int V_574 )
{
struct V_285 * V_286 ;
struct V_531 * V_532 ;
V_286 = F_93 ( V_14 , V_574 ) ;
V_532 = V_286 -> V_532 ;
F_221 ( V_6 -> V_33 ,
L_137 ,
V_574 , F_222 ( V_532 -> V_576 ) , F_222 ( V_532 -> V_577 ) ,
F_222 ( V_532 -> V_578 ) , F_222 ( V_532 -> V_579 ) ) ;
}
void F_166 ( struct V_44 * V_33 , struct V_364 * V_365 , bool V_580 )
{
struct V_581 * V_582 = (struct V_581 * ) V_365 -> V_70 ;
unsigned char * V_530 = V_365 -> V_70 ;
unsigned char V_583 [ 128 ] ;
unsigned int V_7 , V_287 ;
F_221 ( V_33 , L_138 ) ;
F_221 ( V_33 , L_139 ,
( V_580 ? L_140 : L_141 ) , V_365 -> V_379 ) ;
F_221 ( V_33 , L_142 , V_582 -> V_584 ) ;
F_221 ( V_33 , L_143 , V_582 -> V_585 ) ;
F_221 ( V_33 , L_144 , F_224 ( V_582 -> V_586 ) ) ;
for ( V_7 = 0 , V_287 = 0 ; V_7 < V_365 -> V_379 ; ) {
V_287 += snprintf ( V_583 + V_287 , sizeof( V_583 ) - V_287 , L_145 ,
V_530 [ V_7 ++ ] ) ;
if ( ( V_7 % 32 ) == 0 ) {
F_221 ( V_33 , L_146 , V_7 - 32 , V_583 ) ;
V_287 = 0 ;
} else if ( ( V_7 % 16 ) == 0 ) {
V_583 [ V_287 ++ ] = ' ' ;
V_583 [ V_287 ++ ] = ' ' ;
} else if ( ( V_7 % 4 ) == 0 ) {
V_583 [ V_287 ++ ] = ' ' ;
}
}
if ( V_7 % 32 )
F_221 ( V_33 , L_146 , V_7 - ( V_7 % 32 ) , V_583 ) ;
F_221 ( V_33 , L_138 ) ;
}
