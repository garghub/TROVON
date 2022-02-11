static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 , * V_8 ;
unsigned int V_9 , V_10 ;
int V_11 = - V_12 ;
V_9 = F_2 (unsigned int, pdata->tx_ring_count, pdata->rx_ring_count) ;
V_4 = F_3 ( V_9 , sizeof( struct V_3 ) , V_13 ) ;
if ( ! V_4 )
goto V_14;
V_7 = F_3 ( V_2 -> V_15 , sizeof( struct V_6 ) ,
V_13 ) ;
if ( ! V_7 )
goto V_16;
V_8 = F_3 ( V_2 -> V_17 , sizeof( struct V_6 ) ,
V_13 ) ;
if ( ! V_8 )
goto V_18;
for ( V_10 = 0 , V_5 = V_4 ; V_10 < V_9 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_19 , sizeof( V_5 -> V_19 ) , L_1 , V_10 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_20 = V_10 ;
V_5 -> V_21 = V_2 -> V_22 + V_23 +
( V_24 * V_10 ) ;
if ( V_2 -> V_25 )
V_5 -> V_26 = V_2 -> V_27 [ V_10 ] ;
if ( V_10 < V_2 -> V_15 ) {
F_4 ( & V_7 -> V_28 ) ;
V_5 -> V_7 = V_7 ++ ;
}
if ( V_10 < V_2 -> V_17 ) {
F_4 ( & V_8 -> V_28 ) ;
V_5 -> V_8 = V_8 ++ ;
}
F_5 ( V_2 , V_29 , V_2 -> V_30 ,
L_2 ,
V_5 -> V_19 , V_5 -> V_21 , V_5 -> V_26 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
}
V_2 -> V_5 = V_4 ;
V_2 -> V_31 = V_9 ;
return 0 ;
V_18:
F_6 ( V_7 ) ;
V_16:
F_6 ( V_4 ) ;
V_14:
return V_11 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
return;
F_6 ( V_2 -> V_5 -> V_8 ) ;
F_6 ( V_2 -> V_5 -> V_7 ) ;
F_6 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_31 = 0 ;
}
static inline unsigned int F_8 ( struct V_6 * V_32 )
{
return ( V_32 -> V_33 - ( V_32 -> V_34 - V_32 -> V_35 ) ) ;
}
static inline unsigned int F_9 ( struct V_6 * V_32 )
{
return ( V_32 -> V_34 - V_32 -> V_35 ) ;
}
static int F_10 ( struct V_3 * V_5 ,
struct V_6 * V_32 , unsigned int V_9 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_9 > F_8 ( V_32 ) ) {
F_11 ( V_2 , V_29 , V_2 -> V_30 ,
L_3 ) ;
F_12 ( V_2 -> V_30 , V_5 -> V_20 ) ;
V_32 -> V_36 . V_37 = 1 ;
if ( V_32 -> V_36 . V_38 )
V_2 -> V_39 . V_40 ( V_5 , V_32 ) ;
return V_41 ;
}
return 0 ;
}
static int F_13 ( struct V_42 * V_30 , unsigned int V_43 )
{
unsigned int V_44 ;
V_44 = V_43 + V_45 + V_46 + V_47 ;
V_44 = F_14 ( V_44 , V_48 , V_49 ) ;
V_44 = ( V_44 + V_50 - 1 ) &
~ ( V_50 - 1 ) ;
return V_44 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_51 * V_39 = & V_2 -> V_39 ;
enum V_52 V_53 ;
if ( V_5 -> V_7 && V_5 -> V_8 )
V_53 = V_54 ;
else if ( V_5 -> V_7 )
V_53 = V_55 ;
else if ( V_5 -> V_8 )
V_53 = V_56 ;
else
return;
V_39 -> V_57 ( V_5 , V_53 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_15 ( V_2 , V_5 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_51 * V_39 = & V_2 -> V_39 ;
enum V_52 V_53 ;
if ( V_5 -> V_7 && V_5 -> V_8 )
V_53 = V_54 ;
else if ( V_5 -> V_7 )
V_53 = V_55 ;
else if ( V_5 -> V_8 )
V_53 = V_56 ;
else
return;
V_39 -> V_58 ( V_5 , V_53 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_17 ( V_2 , V_5 ) ;
}
static bool F_19 ( struct V_1 * V_2 , unsigned long * V_59 ,
unsigned int * V_9 , const char * V_60 )
{
if ( F_20 ( V_61 , * V_59 ) ) {
( * V_9 ) ++ ;
} else {
* V_59 = V_61 + ( V_62 * V_63 ) ;
* V_9 = 1 ;
}
if ( * V_9 > V_64 )
F_21 ( V_2 -> V_65 ,
L_4 ,
V_60 ) ;
if ( * V_9 > V_66 ) {
F_21 ( V_2 -> V_65 ,
L_5 ,
V_60 ) ;
return true ;
}
return false ;
}
static bool F_22 ( struct V_1 * V_2 , unsigned long * V_59 ,
unsigned int * V_9 , const char * V_60 )
{
if ( F_20 ( V_61 , * V_59 ) ) {
( * V_9 ) ++ ;
} else {
* V_59 = V_61 + ( V_67 * V_63 ) ;
* V_9 = 1 ;
}
if ( * V_9 > V_68 ) {
F_23 ( V_2 -> V_30 ,
L_6 ,
V_60 ) ;
return true ;
}
return false ;
}
static T_1 F_24 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
unsigned int V_71 ;
bool V_72 = false ;
V_71 = F_25 ( V_2 , V_73 ) ;
V_71 &= F_25 ( V_2 , V_74 ) ;
F_5 ( V_2 , V_75 , V_2 -> V_30 , L_7 , V_71 ) ;
if ( F_26 ( V_71 , V_73 , V_76 ) ) {
V_72 |= F_22 ( V_2 , & V_2 -> V_77 ,
& V_2 -> V_78 , L_8 ) ;
}
if ( F_26 ( V_71 , V_73 , V_79 ) ) {
V_72 |= F_22 ( V_2 , & V_2 -> V_80 ,
& V_2 -> V_81 , L_9 ) ;
}
if ( F_26 ( V_71 , V_73 , V_82 ) ) {
V_72 |= F_22 ( V_2 , & V_2 -> V_83 ,
& V_2 -> V_84 ,
L_10 ) ;
}
if ( V_72 ) {
V_2 -> V_39 . V_85 ( V_2 ) ;
F_27 ( & V_2 -> V_86 ) ;
goto V_87;
}
if ( F_26 ( V_71 , V_73 , V_88 ) ) {
if ( F_19 ( V_2 , & V_2 -> V_89 ,
& V_2 -> V_90 , L_8 ) )
V_2 -> V_39 . V_91 ( V_2 , V_92 ) ;
}
if ( F_26 ( V_71 , V_73 , V_93 ) )
if ( F_19 ( V_2 , & V_2 -> V_94 ,
& V_2 -> V_95 , L_9 ) )
V_2 -> V_39 . V_91 ( V_2 , V_96 ) ;
if ( F_26 ( V_71 , V_73 , V_97 ) )
if ( F_19 ( V_2 , & V_2 -> V_98 ,
& V_2 -> V_99 , L_10 ) )
V_2 -> V_39 . V_91 ( V_2 , V_100 ) ;
V_87:
F_28 ( V_2 , V_73 , V_71 ) ;
return V_101 ;
}
static T_1 F_29 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
unsigned int V_102 , V_103 ;
unsigned int V_104 , V_105 , V_106 ;
unsigned int V_10 ;
V_102 = F_30 ( V_2 , V_107 ) ;
if ( ! V_102 )
goto V_108;
F_5 ( V_2 , V_75 , V_2 -> V_30 , L_11 , V_102 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ ) {
if ( ! ( V_102 & ( 1 << V_10 ) ) )
continue;
V_5 = V_2 -> V_5 + V_10 ;
V_103 = F_31 ( V_5 , V_109 ) ;
F_5 ( V_2 , V_75 , V_2 -> V_30 , L_12 ,
V_10 , V_103 ) ;
if ( ! V_2 -> V_25 &&
( F_32 ( V_103 , V_109 , V_110 ) ||
F_32 ( V_103 , V_109 , V_111 ) ) ) {
if ( F_33 ( & V_2 -> V_112 ) ) {
F_18 ( V_2 ) ;
F_34 ( & V_2 -> V_112 ) ;
}
} else {
F_35 ( V_103 , V_109 , V_110 , 0 ) ;
F_35 ( V_103 , V_109 , V_111 , 0 ) ;
}
if ( F_32 ( V_103 , V_109 , V_113 ) )
V_2 -> V_114 . V_115 ++ ;
if ( F_32 ( V_103 , V_109 , V_116 ) )
F_27 ( & V_2 -> V_117 ) ;
F_36 ( V_5 , V_109 , V_103 ) ;
}
if ( F_32 ( V_102 , V_107 , V_118 ) ) {
V_104 = F_30 ( V_2 , V_119 ) ;
F_5 ( V_2 , V_75 , V_2 -> V_30 , L_13 ,
V_104 ) ;
if ( F_32 ( V_104 , V_119 , V_120 ) )
V_39 -> V_121 ( V_2 ) ;
if ( F_32 ( V_104 , V_119 , V_122 ) )
V_39 -> V_123 ( V_2 ) ;
if ( F_32 ( V_104 , V_119 , V_124 ) ) {
V_105 = F_30 ( V_2 , V_125 ) ;
F_5 ( V_2 , V_75 , V_2 -> V_30 ,
L_14 , V_105 ) ;
if ( F_32 ( V_105 , V_125 , V_126 ) ) {
V_2 -> V_127 =
V_39 -> V_128 ( V_2 ) ;
F_37 ( V_2 -> V_129 ,
& V_2 -> V_130 ) ;
}
}
if ( F_32 ( V_104 , V_119 , V_131 ) ) {
V_106 = F_30 ( V_2 , V_132 ) ;
F_5 ( V_2 , V_75 , V_2 -> V_30 ,
L_15 , V_106 ) ;
if ( F_32 ( V_106 , V_132 ,
V_133 ) )
F_38 ( & V_2 -> V_134 ) ;
}
}
V_108:
if ( V_2 -> V_135 == V_2 -> V_136 )
V_2 -> V_137 . V_138 ( V_69 , V_2 ) ;
if ( V_2 -> V_139 -> V_140 && ( V_2 -> V_135 == V_2 -> V_141 ) )
F_24 ( V_69 , V_2 ) ;
if ( V_2 -> V_139 -> V_142 && ( V_2 -> V_135 == V_2 -> V_143 ) )
V_2 -> V_144 . V_145 ( V_69 , V_2 ) ;
return V_101 ;
}
static T_1 F_39 ( int V_69 , void * V_70 )
{
struct V_3 * V_5 = V_70 ;
struct V_1 * V_2 = V_5 -> V_2 ;
unsigned int V_146 ;
if ( F_33 ( & V_5 -> V_112 ) ) {
if ( V_2 -> V_147 )
F_17 ( V_2 , V_5 ) ;
else
F_40 ( V_5 -> V_26 ) ;
F_34 ( & V_5 -> V_112 ) ;
}
V_146 = 0 ;
F_35 ( V_146 , V_109 , V_110 , 1 ) ;
F_35 ( V_146 , V_109 , V_111 , 1 ) ;
F_36 ( V_5 , V_109 , V_146 ) ;
return V_101 ;
}
static void F_41 ( unsigned long V_70 )
{
struct V_3 * V_5 = (struct V_3 * ) V_70 ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_148 * V_112 ;
F_42 ( L_16 ) ;
V_112 = ( V_2 -> V_25 ) ? & V_5 -> V_112 : & V_2 -> V_112 ;
if ( F_33 ( V_112 ) ) {
if ( V_2 -> V_25 )
if ( V_2 -> V_147 )
F_17 ( V_2 , V_5 ) ;
else
F_40 ( V_5 -> V_26 ) ;
else
F_18 ( V_2 ) ;
F_43 ( V_112 ) ;
}
V_5 -> V_149 = 0 ;
F_42 ( L_17 ) ;
}
static void F_44 ( struct V_150 * V_151 )
{
struct V_1 * V_2 = F_45 ( V_151 ,
struct V_1 ,
V_152 ) ;
V_2 -> V_137 . V_153 ( V_2 ) ;
}
static void F_46 ( unsigned long V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
F_37 ( V_2 -> V_129 , & V_2 -> V_152 ) ;
F_47 ( & V_2 -> V_154 , V_61 + V_63 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_49 ( & V_2 -> V_154 , F_46 ,
( unsigned long ) V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_49 ( & V_5 -> V_155 , F_41 ,
( unsigned long ) V_5 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_154 , V_61 + V_63 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_52 ( & V_2 -> V_154 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_52 ( & V_5 -> V_155 ) ;
}
}
void F_53 ( struct V_1 * V_2 )
{
unsigned int V_156 , V_157 , V_158 ;
struct V_159 * V_160 = & V_2 -> V_160 ;
F_42 ( L_18 ) ;
V_156 = F_30 ( V_2 , V_161 ) ;
V_157 = F_30 ( V_2 , V_162 ) ;
V_158 = F_30 ( V_2 , V_163 ) ;
memset ( V_160 , 0 , sizeof( * V_160 ) ) ;
V_160 -> V_164 = F_30 ( V_2 , V_165 ) ;
V_160 -> V_166 = F_32 ( V_156 , V_161 , V_167 ) ;
V_160 -> V_168 = F_32 ( V_156 , V_161 , V_169 ) ;
V_160 -> V_170 = F_32 ( V_156 , V_161 , V_171 ) ;
V_160 -> V_172 = F_32 ( V_156 , V_161 , V_173 ) ;
V_160 -> V_174 = F_32 ( V_156 , V_161 , V_175 ) ;
V_160 -> V_176 = F_32 ( V_156 , V_161 , V_177 ) ;
V_160 -> V_178 = F_32 ( V_156 , V_161 , V_179 ) ;
V_160 -> V_180 = F_32 ( V_156 , V_161 , V_181 ) ;
V_160 -> V_182 = F_32 ( V_156 , V_161 , V_183 ) ;
V_160 -> V_184 = F_32 ( V_156 , V_161 , V_185 ) ;
V_160 -> V_186 = F_32 ( V_156 , V_161 , V_187 ) ;
V_160 -> V_188 = F_32 ( V_156 , V_161 ,
V_189 ) ;
V_160 -> V_190 = F_32 ( V_156 , V_161 , V_191 ) ;
V_160 -> V_192 = F_32 ( V_156 , V_161 , V_193 ) ;
V_160 -> V_194 = F_32 ( V_157 , V_162 ,
V_195 ) ;
V_160 -> V_196 = F_32 ( V_157 , V_162 ,
V_197 ) ;
V_160 -> V_198 = F_32 ( V_157 , V_162 , V_199 ) ;
V_160 -> V_200 = F_32 ( V_157 , V_162 , V_201 ) ;
V_160 -> V_202 = F_32 ( V_157 , V_162 , V_203 ) ;
V_160 -> V_204 = F_32 ( V_157 , V_162 , V_205 ) ;
V_160 -> V_206 = F_32 ( V_157 , V_162 , V_207 ) ;
V_160 -> V_208 = F_32 ( V_157 , V_162 , V_209 ) ;
V_160 -> V_210 = F_32 ( V_157 , V_162 , V_211 ) ;
V_160 -> V_212 = F_32 ( V_157 , V_162 , V_213 ) ;
V_160 -> V_214 = F_32 ( V_157 , V_162 ,
V_215 ) ;
V_160 -> V_216 = F_32 ( V_157 , V_162 ,
V_217 ) ;
V_160 -> V_218 = F_32 ( V_158 , V_163 , V_219 ) ;
V_160 -> V_220 = F_32 ( V_158 , V_163 , V_221 ) ;
V_160 -> V_222 = F_32 ( V_158 , V_163 , V_223 ) ;
V_160 -> V_224 = F_32 ( V_158 , V_163 , V_225 ) ;
V_160 -> V_226 = F_32 ( V_158 , V_163 , V_227 ) ;
V_160 -> V_228 = F_32 ( V_158 , V_163 , V_229 ) ;
switch ( V_160 -> V_214 ) {
case 0 :
break;
case 1 :
V_160 -> V_214 = 64 ;
break;
case 2 :
V_160 -> V_214 = 128 ;
break;
case 3 :
V_160 -> V_214 = 256 ;
break;
}
switch ( V_160 -> V_200 ) {
case 0 :
V_160 -> V_200 = 32 ;
break;
case 1 :
V_160 -> V_200 = 40 ;
break;
case 2 :
V_160 -> V_200 = 48 ;
break;
default:
V_160 -> V_200 = 32 ;
}
V_160 -> V_218 ++ ;
V_160 -> V_220 ++ ;
V_160 -> V_222 ++ ;
V_160 -> V_224 ++ ;
V_160 -> V_212 ++ ;
V_160 -> V_194 = 1 << ( V_160 -> V_194 + 7 ) ;
V_160 -> V_196 = 1 << ( V_160 -> V_196 + 7 ) ;
F_42 ( L_19 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_230 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_230 )
F_55 ( V_2 -> V_30 , & V_5 -> V_112 ,
V_231 , V_232 ) ;
F_56 ( & V_5 -> V_112 ) ;
}
} else {
if ( V_230 )
F_55 ( V_2 -> V_30 , & V_2 -> V_112 ,
V_233 , V_232 ) ;
F_56 ( & V_2 -> V_112 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , unsigned int V_234 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_58 ( & V_5 -> V_112 ) ;
if ( V_234 )
F_59 ( & V_5 -> V_112 ) ;
}
} else {
F_58 ( & V_2 -> V_112 ) ;
if ( V_234 )
F_59 ( & V_2 -> V_112 ) ;
}
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_42 * V_30 = V_2 -> V_30 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_61 ( V_2 -> V_65 , V_2 -> V_135 , F_29 , 0 ,
V_30 -> V_19 , V_2 ) ;
if ( V_11 ) {
F_23 ( V_30 , L_20 ,
V_2 -> V_135 ) ;
return V_11 ;
}
if ( V_2 -> V_139 -> V_140 && ( V_2 -> V_135 != V_2 -> V_141 ) ) {
V_11 = F_61 ( V_2 -> V_65 , V_2 -> V_141 , F_24 ,
0 , V_2 -> V_235 , V_2 ) ;
if ( V_11 ) {
F_23 ( V_30 , L_21 ,
V_2 -> V_141 ) ;
goto V_236;
}
}
if ( ! V_2 -> V_25 )
return 0 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_237 ,
sizeof( V_5 -> V_237 ) - 1 ,
L_22 , F_62 ( V_30 ) ,
V_5 -> V_20 ) ;
V_11 = F_61 ( V_2 -> V_65 , V_5 -> V_26 ,
F_39 , 0 ,
V_5 -> V_237 , V_5 ) ;
if ( V_11 ) {
F_23 ( V_30 , L_20 ,
V_5 -> V_26 ) ;
goto V_238;
}
}
return 0 ;
V_238:
for ( V_10 -- , V_5 -- ; V_10 < V_2 -> V_31 ; V_10 -- , V_5 -- )
F_63 ( V_2 -> V_65 , V_5 -> V_26 , V_5 ) ;
if ( V_2 -> V_139 -> V_140 && ( V_2 -> V_135 != V_2 -> V_141 ) )
F_63 ( V_2 -> V_65 , V_2 -> V_141 , V_2 ) ;
V_236:
F_63 ( V_2 -> V_65 , V_2 -> V_135 , V_2 ) ;
return V_11 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_63 ( V_2 -> V_65 , V_2 -> V_135 , V_2 ) ;
if ( V_2 -> V_139 -> V_140 && ( V_2 -> V_135 != V_2 -> V_141 ) )
F_63 ( V_2 -> V_65 , V_2 -> V_141 , V_2 ) ;
if ( ! V_2 -> V_25 )
return;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_63 ( V_2 -> V_65 , V_5 -> V_26 , V_5 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = & V_2 -> V_39 ;
F_42 ( L_23 ) ;
V_2 -> V_239 = V_240 ;
V_2 -> V_241 = V_242 ;
V_39 -> V_243 ( V_2 ) ;
F_42 ( L_24 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = & V_2 -> V_39 ;
F_42 ( L_25 ) ;
V_2 -> V_244 = V_39 -> V_245 ( V_2 , V_246 ) ;
V_2 -> V_247 = V_246 ;
V_2 -> V_248 = V_249 ;
V_39 -> V_250 ( V_2 ) ;
F_42 ( L_26 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_251 * V_252 = & V_2 -> V_252 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_253 * V_254 ;
unsigned int V_10 , V_255 ;
F_42 ( L_27 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_7 ;
if ( ! V_32 )
break;
for ( V_255 = 0 ; V_255 < V_32 -> V_33 ; V_255 ++ ) {
V_254 = F_68 ( V_32 , V_255 ) ;
V_252 -> V_256 ( V_2 , V_254 ) ;
}
}
F_42 ( L_28 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_251 * V_252 = & V_2 -> V_252 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_253 * V_254 ;
unsigned int V_10 , V_255 ;
F_42 ( L_29 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_8 ;
if ( ! V_32 )
break;
for ( V_255 = 0 ; V_255 < V_32 -> V_33 ; V_255 ++ ) {
V_254 = F_68 ( V_32 , V_255 ) ;
V_252 -> V_256 ( V_2 , V_254 ) ;
}
}
F_42 ( L_30 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
V_2 -> V_257 = - 1 ;
V_2 -> V_258 = V_259 ;
return V_2 -> V_137 . V_260 ( V_2 ) ;
}
int F_71 ( struct V_42 * V_30 , unsigned int V_261 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
unsigned long V_262 ;
F_42 ( L_31 ) ;
if ( ! F_73 ( V_30 ) ||
( V_261 == V_263 && V_2 -> V_264 ) ) {
F_23 ( V_30 , L_32 ) ;
F_42 ( L_33 ) ;
return - V_265 ;
}
F_74 ( & V_2 -> V_28 , V_262 ) ;
if ( V_261 == V_266 )
F_75 ( V_30 ) ;
F_76 ( V_30 ) ;
F_51 ( V_2 ) ;
F_77 ( V_2 -> V_129 ) ;
V_39 -> V_267 ( V_2 ) ;
V_39 -> V_268 ( V_2 ) ;
F_57 ( V_2 , 0 ) ;
V_2 -> V_264 = 1 ;
F_78 ( & V_2 -> V_28 , V_262 ) ;
F_42 ( L_33 ) ;
return 0 ;
}
int F_79 ( struct V_42 * V_30 , unsigned int V_261 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
unsigned long V_262 ;
F_42 ( L_34 ) ;
if ( ! F_73 ( V_30 ) ||
( V_261 == V_263 && ! V_2 -> V_264 ) ) {
F_23 ( V_30 , L_35 ) ;
F_42 ( L_36 ) ;
return - V_265 ;
}
F_74 ( & V_2 -> V_28 , V_262 ) ;
V_2 -> V_264 = 0 ;
F_54 ( V_2 , 0 ) ;
V_39 -> V_269 ( V_2 ) ;
V_39 -> V_270 ( V_2 ) ;
if ( V_261 == V_266 )
F_80 ( V_30 ) ;
F_81 ( V_30 ) ;
F_50 ( V_2 ) ;
F_78 ( & V_2 -> V_28 , V_262 ) ;
F_42 ( L_36 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_271 * V_137 = & V_2 -> V_137 ;
struct V_42 * V_30 = V_2 -> V_30 ;
int V_11 ;
F_42 ( L_37 ) ;
V_11 = V_39 -> V_272 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_54 ( V_2 , 1 ) ;
V_11 = F_60 ( V_2 ) ;
if ( V_11 )
goto V_273;
V_11 = V_137 -> V_274 ( V_2 ) ;
if ( V_11 )
goto V_275;
V_39 -> V_276 ( V_2 ) ;
V_39 -> V_277 ( V_2 ) ;
F_81 ( V_30 ) ;
F_50 ( V_2 ) ;
F_37 ( V_2 -> V_129 , & V_2 -> V_152 ) ;
F_83 ( V_278 , & V_2 -> V_279 ) ;
F_42 ( L_38 ) ;
return 0 ;
V_275:
F_64 ( V_2 ) ;
V_273:
F_57 ( V_2 , 1 ) ;
V_39 -> exit ( V_2 ) ;
return V_11 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_271 * V_137 = & V_2 -> V_137 ;
struct V_3 * V_5 ;
struct V_42 * V_30 = V_2 -> V_30 ;
struct V_280 * V_281 ;
unsigned int V_10 ;
F_42 ( L_39 ) ;
if ( F_85 ( V_278 , & V_2 -> V_279 ) )
return;
F_76 ( V_30 ) ;
F_51 ( V_2 ) ;
F_77 ( V_2 -> V_129 ) ;
V_39 -> V_282 ( V_2 ) ;
V_39 -> V_283 ( V_2 ) ;
V_137 -> V_284 ( V_2 ) ;
F_64 ( V_2 ) ;
F_57 ( V_2 , 1 ) ;
V_39 -> exit ( V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
continue;
V_281 = F_86 ( V_30 , V_5 -> V_20 ) ;
F_87 ( V_281 ) ;
}
F_88 ( V_278 , & V_2 -> V_279 ) ;
F_42 ( L_40 ) ;
}
static void F_89 ( struct V_150 * V_151 )
{
struct V_1 * V_2 = F_45 ( V_151 ,
struct V_1 ,
V_86 ) ;
F_90 () ;
F_84 ( V_2 ) ;
F_67 ( V_2 ) ;
F_69 ( V_2 ) ;
F_91 () ;
F_23 ( V_2 -> V_30 , L_41 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_42 ( L_42 ) ;
if ( ! F_73 ( V_2 -> V_30 ) )
return;
F_84 ( V_2 ) ;
F_67 ( V_2 ) ;
F_69 ( V_2 ) ;
F_82 ( V_2 ) ;
F_42 ( L_43 ) ;
}
static void F_93 ( struct V_150 * V_151 )
{
struct V_1 * V_2 = F_45 ( V_151 ,
struct V_1 ,
V_117 ) ;
F_90 () ;
F_92 ( V_2 ) ;
F_91 () ;
}
static void F_94 ( struct V_150 * V_151 )
{
struct V_1 * V_2 = F_45 ( V_151 ,
struct V_1 ,
V_130 ) ;
struct V_285 V_286 ;
T_2 V_287 ;
unsigned long V_262 ;
if ( V_2 -> V_127 ) {
V_287 = F_95 ( & V_2 -> V_288 ,
V_2 -> V_127 ) ;
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
V_286 . V_289 = F_96 ( V_287 ) ;
F_97 ( V_2 -> V_290 , & V_286 ) ;
}
F_98 ( V_2 -> V_290 ) ;
F_74 ( & V_2 -> V_291 , V_262 ) ;
V_2 -> V_290 = NULL ;
F_78 ( & V_2 -> V_291 , V_262 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_292 * V_292 )
{
if ( F_100 ( V_292 -> V_293 , & V_2 -> V_294 ,
sizeof( V_2 -> V_294 ) ) )
return - V_295 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_292 * V_292 )
{
struct V_296 V_297 ;
unsigned int V_298 ;
if ( F_102 ( & V_297 , V_292 -> V_293 , sizeof( V_297 ) ) )
return - V_295 ;
if ( V_297 . V_262 )
return - V_265 ;
V_298 = 0 ;
switch ( V_297 . V_299 ) {
case V_300 :
break;
case V_301 :
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
default:
return - V_304 ;
}
switch ( V_297 . V_305 ) {
case V_306 :
break;
case V_307 :
F_35 ( V_298 , V_302 , V_308 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_309 :
F_35 ( V_298 , V_302 , V_310 , 1 ) ;
case V_311 :
F_35 ( V_298 , V_302 , V_312 , 1 ) ;
F_35 ( V_298 , V_302 , V_313 , 1 ) ;
F_35 ( V_298 , V_302 , V_314 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_315 :
F_35 ( V_298 , V_302 , V_310 , 1 ) ;
case V_316 :
F_35 ( V_298 , V_302 , V_312 , 1 ) ;
F_35 ( V_298 , V_302 , V_313 , 1 ) ;
F_35 ( V_298 , V_302 , V_317 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_318 :
F_35 ( V_298 , V_302 , V_310 , 1 ) ;
case V_319 :
F_35 ( V_298 , V_302 , V_312 , 1 ) ;
F_35 ( V_298 , V_302 , V_313 , 1 ) ;
F_35 ( V_298 , V_302 , V_317 , 1 ) ;
F_35 ( V_298 , V_302 , V_320 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_321 :
F_35 ( V_298 , V_302 , V_322 , 1 ) ;
F_35 ( V_298 , V_302 , V_314 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_323 :
F_35 ( V_298 , V_302 , V_322 , 1 ) ;
F_35 ( V_298 , V_302 , V_317 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_324 :
F_35 ( V_298 , V_302 , V_322 , 1 ) ;
F_35 ( V_298 , V_302 , V_320 , 1 ) ;
F_35 ( V_298 , V_302 , V_317 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_325 :
F_35 ( V_298 , V_302 , V_310 , 1 ) ;
F_35 ( V_298 , V_302 , V_326 , 1 ) ;
F_35 ( V_298 , V_302 , V_312 , 1 ) ;
F_35 ( V_298 , V_302 , V_313 , 1 ) ;
F_35 ( V_298 , V_302 , V_314 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_327 :
F_35 ( V_298 , V_302 , V_310 , 1 ) ;
F_35 ( V_298 , V_302 , V_326 , 1 ) ;
F_35 ( V_298 , V_302 , V_312 , 1 ) ;
F_35 ( V_298 , V_302 , V_313 , 1 ) ;
F_35 ( V_298 , V_302 , V_317 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
case V_328 :
F_35 ( V_298 , V_302 , V_310 , 1 ) ;
F_35 ( V_298 , V_302 , V_326 , 1 ) ;
F_35 ( V_298 , V_302 , V_312 , 1 ) ;
F_35 ( V_298 , V_302 , V_313 , 1 ) ;
F_35 ( V_298 , V_302 , V_320 , 1 ) ;
F_35 ( V_298 , V_302 , V_317 , 1 ) ;
F_35 ( V_298 , V_302 , V_303 , 1 ) ;
break;
default:
return - V_304 ;
}
V_2 -> V_39 . V_329 ( V_2 , V_298 ) ;
memcpy ( & V_2 -> V_294 , & V_297 , sizeof( V_297 ) ) ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_330 * V_331 ,
struct V_332 * V_333 )
{
unsigned long V_262 ;
if ( F_32 ( V_333 -> V_334 , V_335 , V_336 ) ) {
F_74 ( & V_2 -> V_291 , V_262 ) ;
if ( V_2 -> V_290 ) {
F_35 ( V_333 -> V_334 ,
V_335 , V_336 , 0 ) ;
} else {
V_2 -> V_290 = F_104 ( V_331 ) ;
F_105 ( V_331 ) -> V_337 |= V_338 ;
}
F_78 ( & V_2 -> V_291 , V_262 ) ;
}
if ( ! F_32 ( V_333 -> V_334 , V_335 , V_336 ) )
F_106 ( V_331 ) ;
}
static void F_107 ( struct V_330 * V_331 , struct V_332 * V_333 )
{
if ( F_108 ( V_331 ) )
V_333 -> V_339 = F_109 ( V_331 ) ;
}
static int F_110 ( struct V_330 * V_331 , struct V_332 * V_333 )
{
int V_11 ;
if ( ! F_32 ( V_333 -> V_334 , V_335 ,
V_340 ) )
return 0 ;
V_11 = F_111 ( V_331 , 0 ) ;
if ( V_11 )
return V_11 ;
V_333 -> V_341 = F_112 ( V_331 ) + F_113 ( V_331 ) ;
V_333 -> V_342 = F_113 ( V_331 ) ;
V_333 -> V_343 = V_331 -> V_344 - V_333 -> V_341 ;
V_333 -> V_345 = F_105 ( V_331 ) -> V_346 ;
F_42 ( L_44 , V_333 -> V_341 ) ;
F_42 ( L_45 ,
V_333 -> V_342 , V_333 -> V_343 ) ;
F_42 ( L_46 , V_333 -> V_345 ) ;
V_333 -> V_347 = F_105 ( V_331 ) -> V_348 ;
V_333 -> V_349 += ( V_333 -> V_347 - 1 ) * V_333 -> V_341 ;
return 0 ;
}
static int F_114 ( struct V_330 * V_331 )
{
if ( V_331 -> V_350 != V_351 )
return 0 ;
if ( ! F_115 ( V_331 ) )
return 0 ;
F_42 ( L_47 ) ;
return 1 ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_6 * V_32 , struct V_330 * V_331 ,
struct V_332 * V_333 )
{
struct V_352 * V_353 ;
unsigned int V_354 ;
unsigned int V_344 ;
unsigned int V_10 ;
V_333 -> V_331 = V_331 ;
V_354 = 0 ;
V_333 -> V_33 = 0 ;
V_333 -> V_347 = 1 ;
V_333 -> V_349 = V_331 -> V_344 ;
if ( F_114 ( V_331 ) ) {
if ( F_105 ( V_331 ) -> V_346 != V_32 -> V_36 . V_355 ) {
V_354 = 1 ;
V_333 -> V_33 ++ ;
}
V_333 -> V_33 ++ ;
F_35 ( V_333 -> V_334 , V_335 ,
V_340 , 1 ) ;
F_35 ( V_333 -> V_334 , V_335 ,
V_356 , 1 ) ;
} else if ( V_331 -> V_350 == V_351 )
F_35 ( V_333 -> V_334 , V_335 ,
V_356 , 1 ) ;
if ( F_108 ( V_331 ) ) {
if ( F_109 ( V_331 ) != V_32 -> V_36 . V_357 )
if ( ! V_354 ) {
V_354 = 1 ;
V_333 -> V_33 ++ ;
}
F_35 ( V_333 -> V_334 , V_335 ,
V_358 , 1 ) ;
}
if ( ( F_105 ( V_331 ) -> V_337 & V_359 ) &&
( V_2 -> V_294 . V_299 == V_301 ) )
F_35 ( V_333 -> V_334 , V_335 ,
V_336 , 1 ) ;
for ( V_344 = F_117 ( V_331 ) ; V_344 ; ) {
V_333 -> V_33 ++ ;
V_344 -= F_118 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_10 = 0 ; V_10 < F_105 ( V_331 ) -> V_360 ; V_10 ++ ) {
V_353 = & F_105 ( V_331 ) -> V_361 [ V_10 ] ;
for ( V_344 = F_119 ( V_353 ) ; V_344 ; ) {
V_333 -> V_33 ++ ;
V_344 -= F_118 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_120 ( struct V_42 * V_30 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_251 * V_252 = & V_2 -> V_252 ;
int V_11 ;
F_42 ( L_48 ) ;
V_11 = F_70 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_121 ( V_2 -> V_362 ) ;
if ( V_11 ) {
F_23 ( V_30 , L_49 ) ;
return V_11 ;
}
V_11 = F_121 ( V_2 -> V_363 ) ;
if ( V_11 ) {
F_23 ( V_30 , L_50 ) ;
goto V_364;
}
V_11 = F_13 ( V_30 , V_30 -> V_43 ) ;
if ( V_11 < 0 )
goto V_365;
V_2 -> V_44 = V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_365;
V_11 = V_252 -> V_366 ( V_2 ) ;
if ( V_11 )
goto V_367;
F_122 ( & V_2 -> V_152 , F_44 ) ;
F_122 ( & V_2 -> V_117 , F_93 ) ;
F_122 ( & V_2 -> V_86 , F_89 ) ;
F_122 ( & V_2 -> V_130 , F_94 ) ;
F_48 ( V_2 ) ;
V_11 = F_82 ( V_2 ) ;
if ( V_11 )
goto V_368;
F_83 ( V_369 , & V_2 -> V_279 ) ;
F_42 ( L_51 ) ;
return 0 ;
V_368:
V_252 -> V_370 ( V_2 ) ;
V_367:
F_7 ( V_2 ) ;
V_365:
F_123 ( V_2 -> V_363 ) ;
V_364:
F_123 ( V_2 -> V_362 ) ;
return V_11 ;
}
static int F_124 ( struct V_42 * V_30 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_251 * V_252 = & V_2 -> V_252 ;
F_42 ( L_52 ) ;
F_84 ( V_2 ) ;
V_252 -> V_370 ( V_2 ) ;
F_7 ( V_2 ) ;
F_123 ( V_2 -> V_363 ) ;
F_123 ( V_2 -> V_362 ) ;
F_88 ( V_369 , & V_2 -> V_279 ) ;
F_42 ( L_53 ) ;
return 0 ;
}
static int F_125 ( struct V_330 * V_331 , struct V_42 * V_30 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_251 * V_252 = & V_2 -> V_252 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_332 * V_333 ;
struct V_280 * V_281 ;
int V_11 ;
F_42 ( L_54 , V_331 -> V_344 ) ;
V_5 = V_2 -> V_5 + V_331 -> V_371 ;
V_281 = F_86 ( V_30 , V_5 -> V_20 ) ;
V_32 = V_5 -> V_7 ;
V_333 = & V_32 -> V_372 ;
V_11 = V_373 ;
if ( V_331 -> V_344 == 0 ) {
F_126 ( V_2 , V_374 , V_30 ,
L_55 ) ;
F_98 ( V_331 ) ;
goto V_375;
}
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
F_116 ( V_2 , V_32 , V_331 , V_333 ) ;
V_11 = F_10 ( V_5 , V_32 , V_333 -> V_33 ) ;
if ( V_11 )
goto V_375;
V_11 = F_110 ( V_331 , V_333 ) ;
if ( V_11 ) {
F_126 ( V_2 , V_374 , V_30 ,
L_56 ) ;
F_98 ( V_331 ) ;
goto V_375;
}
F_107 ( V_331 , V_333 ) ;
if ( ! V_252 -> V_376 ( V_5 , V_331 ) ) {
F_98 ( V_331 ) ;
goto V_375;
}
F_103 ( V_2 , V_331 , V_333 ) ;
F_127 ( V_281 , V_333 -> V_349 ) ;
V_39 -> V_377 ( V_5 ) ;
if ( F_128 ( V_2 ) )
F_129 ( V_30 , V_331 , true ) ;
F_10 ( V_5 , V_32 , V_378 ) ;
V_11 = V_373 ;
V_375:
return V_11 ;
}
static void F_130 ( struct V_42 * V_30 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
F_42 ( L_57 ) ;
V_39 -> V_379 ( V_2 ) ;
F_42 ( L_58 ) ;
}
static int F_131 ( struct V_42 * V_30 , void * V_380 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_381 * V_382 = V_380 ;
F_42 ( L_59 ) ;
if ( ! F_132 ( V_382 -> V_383 ) )
return - V_384 ;
memcpy ( V_30 -> V_385 , V_382 -> V_383 , V_30 -> V_386 ) ;
V_39 -> V_387 ( V_2 , V_30 -> V_385 ) ;
F_42 ( L_60 ) ;
return 0 ;
}
static int F_133 ( struct V_42 * V_30 , struct V_292 * V_292 , int V_388 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
int V_11 ;
switch ( V_388 ) {
case V_389 :
V_11 = F_99 ( V_2 , V_292 ) ;
break;
case V_390 :
V_11 = F_101 ( V_2 , V_292 ) ;
break;
default:
V_11 = - V_391 ;
}
return V_11 ;
}
static int F_134 ( struct V_42 * V_30 , int V_43 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
int V_11 ;
F_42 ( L_61 ) ;
V_11 = F_13 ( V_30 , V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_44 = V_11 ;
V_30 -> V_43 = V_43 ;
F_92 ( V_2 ) ;
F_42 ( L_62 ) ;
return 0 ;
}
static void F_135 ( struct V_42 * V_30 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
F_136 ( V_30 , L_63 ) ;
F_27 ( & V_2 -> V_117 ) ;
}
static void F_137 ( struct V_42 * V_30 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_394 * V_395 = & V_2 -> V_396 ;
F_42 ( L_64 , V_397 ) ;
V_2 -> V_39 . V_398 ( V_2 ) ;
V_393 -> V_399 = V_395 -> V_400 ;
V_393 -> V_401 = V_395 -> V_402 ;
V_393 -> V_403 = V_395 -> V_400 -
V_395 -> V_404 -
V_395 -> V_405 -
V_395 -> V_406 ;
V_393 -> V_407 = V_395 -> V_405 ;
V_393 -> V_408 = V_395 -> V_409 ;
V_393 -> V_410 = V_395 -> V_411 ;
V_393 -> V_412 = V_395 -> V_413 ;
V_393 -> V_347 = V_395 -> V_414 ;
V_393 -> V_349 = V_395 -> V_415 ;
V_393 -> V_416 = V_395 -> V_414 - V_395 -> V_417 ;
V_393 -> V_418 = V_30 -> V_419 . V_418 ;
F_42 ( L_65 , V_397 ) ;
}
static int F_138 ( struct V_42 * V_30 , T_3 V_420 ,
T_4 V_421 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
F_42 ( L_64 , V_397 ) ;
F_88 ( V_421 , V_2 -> V_422 ) ;
V_39 -> V_423 ( V_2 ) ;
F_42 ( L_65 , V_397 ) ;
return 0 ;
}
static int F_139 ( struct V_42 * V_30 , T_3 V_420 ,
T_4 V_421 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
F_42 ( L_64 , V_397 ) ;
F_83 ( V_421 , V_2 -> V_422 ) ;
V_39 -> V_423 ( V_2 ) ;
F_42 ( L_65 , V_397 ) ;
return 0 ;
}
static void F_140 ( struct V_42 * V_30 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_3 * V_5 ;
unsigned int V_10 ;
F_42 ( L_66 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_39 ( V_5 -> V_26 , V_5 ) ;
} else {
F_141 ( V_2 -> V_135 ) ;
F_29 ( V_2 -> V_135 , V_2 ) ;
F_142 ( V_2 -> V_135 ) ;
}
F_42 ( L_67 ) ;
}
static int F_143 ( struct V_42 * V_30 , T_5 V_424 , T_3 V_420 ,
struct V_425 * V_425 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
T_6 V_426 ;
if ( V_425 -> type != V_427 )
return - V_265 ;
V_426 = V_425 -> V_426 ;
if ( V_426 > V_2 -> V_160 . V_212 )
return - V_265 ;
V_2 -> V_428 = V_426 ;
V_2 -> V_39 . V_429 ( V_2 ) ;
return 0 ;
}
static int F_144 ( struct V_42 * V_30 ,
T_7 V_430 )
{
struct V_1 * V_2 = F_72 ( V_30 ) ;
struct V_51 * V_39 = & V_2 -> V_39 ;
T_7 V_431 , V_432 , V_433 , V_434 ;
int V_11 = 0 ;
V_431 = V_2 -> V_435 & V_436 ;
V_432 = V_2 -> V_435 & V_437 ;
V_433 = V_2 -> V_435 & V_438 ;
V_434 = V_2 -> V_435 & V_439 ;
if ( ( V_430 & V_436 ) && ! V_431 )
V_11 = V_39 -> V_440 ( V_2 ) ;
else if ( ! ( V_430 & V_436 ) && V_431 )
V_11 = V_39 -> V_441 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_430 & V_437 ) && ! V_432 )
V_39 -> V_442 ( V_2 ) ;
else if ( ! ( V_430 & V_437 ) && V_432 )
V_39 -> V_443 ( V_2 ) ;
if ( ( V_430 & V_438 ) && ! V_433 )
V_39 -> V_444 ( V_2 ) ;
else if ( ! ( V_430 & V_438 ) && V_433 )
V_39 -> V_445 ( V_2 ) ;
if ( ( V_430 & V_439 ) && ! V_434 )
V_39 -> V_446 ( V_2 ) ;
else if ( ! ( V_430 & V_439 ) && V_434 )
V_39 -> V_447 ( V_2 ) ;
V_2 -> V_435 = V_430 ;
F_42 ( L_68 ) ;
return 0 ;
}
const struct V_448 * F_145 ( void )
{
return & V_449 ;
}
static void F_146 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_251 * V_252 = & V_2 -> V_252 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_253 * V_254 ;
while ( V_32 -> V_35 != V_32 -> V_34 ) {
V_254 = F_68 ( V_32 , V_32 -> V_35 ) ;
V_252 -> V_256 ( V_2 , V_254 ) ;
if ( V_252 -> V_450 ( V_2 , V_32 , V_254 ) )
break;
V_39 -> V_451 ( V_2 , V_254 , V_32 -> V_35 ) ;
V_32 -> V_35 ++ ;
}
F_147 () ;
V_254 = F_68 ( V_32 , V_32 -> V_35 - 1 ) ;
F_36 ( V_5 , V_452 ,
F_148 ( V_254 -> V_453 ) ) ;
}
static struct V_330 * F_149 ( struct V_1 * V_2 ,
struct V_148 * V_112 ,
struct V_253 * V_254 ,
unsigned int V_344 )
{
struct V_330 * V_331 ;
T_6 * V_333 ;
V_331 = F_150 ( V_112 , V_254 -> V_454 . V_455 . V_456 ) ;
if ( ! V_331 )
return NULL ;
F_151 ( V_2 -> V_65 , V_254 -> V_454 . V_455 . V_457 ,
V_254 -> V_454 . V_455 . V_458 ,
V_254 -> V_454 . V_455 . V_456 , V_459 ) ;
V_333 = F_152 ( V_254 -> V_454 . V_455 . V_460 . V_461 ) +
V_254 -> V_454 . V_455 . V_460 . V_462 ;
F_153 ( V_331 , V_333 , V_344 ) ;
F_154 ( V_331 , V_344 ) ;
return V_331 ;
}
static unsigned int F_155 ( struct V_253 * V_254 ,
struct V_332 * V_333 )
{
if ( ! F_32 ( V_333 -> V_334 , V_463 , V_464 ) )
return 0 ;
if ( V_254 -> V_454 . V_465 )
return V_254 -> V_454 . V_465 ;
if ( ! F_32 ( V_333 -> V_334 , V_463 , V_466 ) )
return V_254 -> V_454 . V_455 . V_456 ;
return F_118 (unsigned int, rdata->rx.hdr.dma_len, rdata->rx.len) ;
}
static unsigned int F_156 ( struct V_253 * V_254 ,
struct V_332 * V_333 ,
unsigned int V_344 )
{
if ( ! F_32 ( V_333 -> V_334 , V_463 , V_466 ) )
return V_254 -> V_454 . V_467 . V_456 ;
return V_254 -> V_454 . V_344 - V_344 ;
}
static int F_157 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_251 * V_252 = & V_2 -> V_252 ;
struct V_6 * V_32 = V_5 -> V_7 ;
struct V_253 * V_254 ;
struct V_468 * V_469 ;
struct V_42 * V_30 = V_2 -> V_30 ;
struct V_280 * V_281 ;
int V_470 = 0 ;
unsigned int V_347 = 0 , V_349 = 0 ;
unsigned int V_34 ;
F_42 ( L_69 ) ;
if ( ! V_32 )
return 0 ;
V_34 = V_32 -> V_34 ;
F_158 () ;
V_281 = F_86 ( V_30 , V_5 -> V_20 ) ;
while ( ( V_470 < V_471 ) &&
( V_32 -> V_35 != V_34 ) ) {
V_254 = F_68 ( V_32 , V_32 -> V_35 ) ;
V_469 = V_254 -> V_469 ;
if ( ! V_39 -> V_472 ( V_469 ) )
break;
F_159 () ;
if ( F_160 ( V_2 ) )
F_161 ( V_2 , V_32 , V_32 -> V_35 , 1 , 0 ) ;
if ( V_39 -> V_473 ( V_469 ) ) {
V_347 += V_254 -> V_36 . V_474 ;
V_349 += V_254 -> V_36 . V_475 ;
}
V_252 -> V_256 ( V_2 , V_254 ) ;
V_39 -> V_476 ( V_254 ) ;
V_470 ++ ;
V_32 -> V_35 ++ ;
}
if ( ! V_470 )
return 0 ;
F_162 ( V_281 , V_347 , V_349 ) ;
if ( ( V_32 -> V_36 . V_37 == 1 ) &&
( F_8 ( V_32 ) > V_477 ) ) {
V_32 -> V_36 . V_37 = 0 ;
F_163 ( V_281 ) ;
}
F_42 ( L_70 , V_470 ) ;
return V_470 ;
}
static int F_164 ( struct V_3 * V_5 , int V_478 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_51 * V_39 = & V_2 -> V_39 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_253 * V_254 ;
struct V_332 * V_333 ;
struct V_42 * V_30 = V_2 -> V_30 ;
struct V_148 * V_112 ;
struct V_330 * V_331 ;
struct V_285 * V_286 ;
unsigned int V_479 , error , V_480 , V_481 ;
unsigned int V_344 , V_482 , V_483 , V_484 ;
unsigned int V_485 = 0 ;
int V_486 = 0 ;
F_42 ( L_71 , V_478 ) ;
if ( ! V_32 )
return 0 ;
V_479 = 0 ;
V_480 = 0 ;
V_112 = ( V_2 -> V_25 ) ? & V_5 -> V_112 : & V_2 -> V_112 ;
V_254 = F_68 ( V_32 , V_32 -> V_34 ) ;
V_333 = & V_32 -> V_372 ;
while ( V_486 < V_478 ) {
F_42 ( L_72 , V_32 -> V_34 ) ;
if ( ! V_485 && V_254 -> V_487 ) {
V_331 = V_254 -> V_488 . V_331 ;
error = V_254 -> V_488 . error ;
V_344 = V_254 -> V_488 . V_344 ;
} else {
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
V_331 = NULL ;
error = 0 ;
V_344 = 0 ;
}
V_489:
V_254 = F_68 ( V_32 , V_32 -> V_34 ) ;
if ( F_9 ( V_32 ) > ( V_490 >> 3 ) )
F_146 ( V_5 ) ;
if ( V_39 -> V_491 ( V_5 ) )
break;
V_485 ++ ;
V_32 -> V_34 ++ ;
V_479 = F_32 ( V_333 -> V_334 , V_463 ,
V_466 ) ;
V_480 = F_32 ( V_333 -> V_334 ,
V_463 ,
V_492 ) ;
V_481 = F_32 ( V_333 -> V_334 ,
V_463 ,
V_493 ) ;
if ( ( ! V_479 || V_480 ) && error )
goto V_489;
if ( error || V_333 -> V_494 ) {
if ( V_333 -> V_494 )
F_126 ( V_2 , V_495 , V_30 ,
L_73 ) ;
F_165 ( V_331 ) ;
goto V_496;
}
if ( ! V_481 ) {
V_482 = F_155 ( V_254 , V_333 ) ;
V_344 += V_482 ;
V_483 = F_156 ( V_254 , V_333 , V_344 ) ;
V_344 += V_483 ;
if ( ! V_331 ) {
V_331 = F_149 ( V_2 , V_112 , V_254 ,
V_482 ) ;
if ( ! V_331 ) {
error = 1 ;
goto V_497;
}
}
if ( V_483 ) {
F_151 ( V_2 -> V_65 ,
V_254 -> V_454 . V_467 . V_457 ,
V_254 -> V_454 . V_467 . V_458 ,
V_254 -> V_454 . V_467 . V_456 ,
V_459 ) ;
F_166 ( V_331 , F_105 ( V_331 ) -> V_360 ,
V_254 -> V_454 . V_467 . V_460 . V_461 ,
V_254 -> V_454 . V_467 . V_460 . V_462 ,
V_483 ,
V_254 -> V_454 . V_467 . V_456 ) ;
V_254 -> V_454 . V_467 . V_460 . V_461 = NULL ;
}
}
V_497:
if ( ! V_479 || V_480 )
goto V_489;
if ( ! V_331 )
goto V_496;
V_484 = V_30 -> V_43 + V_45 ;
if ( ! ( V_30 -> V_430 & V_438 ) &&
( V_331 -> V_498 == F_167 ( V_499 ) ) )
V_484 += V_47 ;
if ( V_331 -> V_344 > V_484 ) {
F_126 ( V_2 , V_495 , V_30 ,
L_74 ) ;
F_165 ( V_331 ) ;
goto V_496;
}
if ( F_128 ( V_2 ) )
F_129 ( V_30 , V_331 , false ) ;
F_168 ( V_331 ) ;
if ( F_32 ( V_333 -> V_334 ,
V_463 , V_500 ) )
V_331 -> V_350 = V_501 ;
if ( F_32 ( V_333 -> V_334 ,
V_463 , V_358 ) )
F_169 ( V_331 , F_167 ( V_499 ) ,
V_333 -> V_339 ) ;
if ( F_32 ( V_333 -> V_334 ,
V_463 , V_502 ) ) {
T_2 V_287 ;
V_287 = F_95 ( & V_2 -> V_288 ,
V_333 -> V_503 ) ;
V_286 = F_170 ( V_331 ) ;
V_286 -> V_289 = F_96 ( V_287 ) ;
}
if ( F_32 ( V_333 -> V_334 ,
V_463 , V_504 ) )
F_171 ( V_331 , V_333 -> V_505 ,
V_333 -> V_506 ) ;
V_331 -> V_65 = V_30 ;
V_331 -> V_498 = F_172 ( V_331 , V_30 ) ;
F_173 ( V_331 , V_5 -> V_20 ) ;
F_174 ( V_112 , V_331 ) ;
V_496:
V_486 ++ ;
}
if ( V_485 && ( ! V_479 || V_480 ) ) {
V_254 = F_68 ( V_32 , V_32 -> V_34 ) ;
V_254 -> V_487 = 1 ;
V_254 -> V_488 . V_331 = V_331 ;
V_254 -> V_488 . V_344 = V_344 ;
V_254 -> V_488 . error = error ;
}
F_42 ( L_75 , V_486 ) ;
return V_486 ;
}
static int V_231 ( struct V_148 * V_112 , int V_478 )
{
struct V_3 * V_5 = F_45 ( V_112 , struct V_3 ,
V_112 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
int V_470 = 0 ;
F_42 ( L_76 , V_478 ) ;
F_157 ( V_5 ) ;
V_470 = F_164 ( V_5 , V_478 ) ;
if ( ( V_470 < V_478 ) && F_175 ( V_112 , V_470 ) ) {
if ( V_2 -> V_147 )
F_15 ( V_2 , V_5 ) ;
else
F_142 ( V_5 -> V_26 ) ;
}
F_42 ( L_77 , V_470 ) ;
return V_470 ;
}
static int V_233 ( struct V_148 * V_112 , int V_478 )
{
struct V_1 * V_2 = F_45 ( V_112 , struct V_1 ,
V_112 ) ;
struct V_3 * V_5 ;
int V_507 ;
int V_470 , V_508 ;
unsigned int V_10 ;
F_42 ( L_78 , V_478 ) ;
V_470 = 0 ;
V_507 = V_478 / V_2 -> V_17 ;
do {
V_508 = V_470 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_157 ( V_5 ) ;
if ( V_507 > ( V_478 - V_470 ) )
V_507 = V_478 - V_470 ;
V_470 += F_164 ( V_5 , V_507 ) ;
}
} while ( ( V_470 < V_478 ) && ( V_470 != V_508 ) );
if ( ( V_470 < V_478 ) && F_175 ( V_112 , V_470 ) ) {
F_16 ( V_2 ) ;
}
F_42 ( L_79 , V_470 ) ;
return V_470 ;
}
void F_161 ( struct V_1 * V_2 , struct V_6 * V_32 ,
unsigned int V_509 , unsigned int V_9 , unsigned int V_510 )
{
struct V_253 * V_254 ;
struct V_468 * V_469 ;
while ( V_9 -- ) {
V_254 = F_68 ( V_32 , V_509 ) ;
V_469 = V_254 -> V_469 ;
F_176 ( V_2 -> V_30 ,
L_80 , V_509 ,
( V_510 == 1 ) ? L_81 : L_82 ,
F_177 ( V_469 -> V_511 ) ,
F_177 ( V_469 -> V_512 ) ,
F_177 ( V_469 -> V_513 ) ,
F_177 ( V_469 -> V_514 ) ) ;
V_509 ++ ;
}
}
void F_178 ( struct V_1 * V_2 , struct V_6 * V_32 ,
unsigned int V_509 )
{
struct V_253 * V_254 ;
struct V_468 * V_469 ;
V_254 = F_68 ( V_32 , V_509 ) ;
V_469 = V_254 -> V_469 ;
F_176 ( V_2 -> V_30 ,
L_83 ,
V_509 , F_177 ( V_469 -> V_511 ) , F_177 ( V_469 -> V_512 ) ,
F_177 ( V_469 -> V_513 ) , F_177 ( V_469 -> V_514 ) ) ;
}
void F_129 ( struct V_42 * V_30 , struct V_330 * V_331 , bool V_515 )
{
struct V_516 * V_517 = (struct V_516 * ) V_331 -> V_70 ;
unsigned char * V_467 = V_331 -> V_70 ;
unsigned char V_518 [ 128 ] ;
unsigned int V_10 , V_255 ;
F_176 ( V_30 , L_84 ) ;
F_176 ( V_30 , L_85 ,
( V_515 ? L_86 : L_87 ) , V_331 -> V_344 ) ;
F_176 ( V_30 , L_88 , V_517 -> V_519 ) ;
F_176 ( V_30 , L_89 , V_517 -> V_520 ) ;
F_176 ( V_30 , L_90 , F_179 ( V_517 -> V_521 ) ) ;
for ( V_10 = 0 , V_255 = 0 ; V_10 < V_331 -> V_344 ; ) {
V_255 += snprintf ( V_518 + V_255 , sizeof( V_518 ) - V_255 , L_91 ,
V_467 [ V_10 ++ ] ) ;
if ( ( V_10 % 32 ) == 0 ) {
F_176 ( V_30 , L_92 , V_10 - 32 , V_518 ) ;
V_255 = 0 ;
} else if ( ( V_10 % 16 ) == 0 ) {
V_518 [ V_255 ++ ] = ' ' ;
V_518 [ V_255 ++ ] = ' ' ;
} else if ( ( V_10 % 4 ) == 0 ) {
V_518 [ V_255 ++ ] = ' ' ;
}
}
if ( V_10 % 32 )
F_176 ( V_30 , L_92 , V_10 - ( V_10 % 32 ) , V_518 ) ;
F_176 ( V_30 , L_84 ) ;
}
