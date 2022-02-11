static inline void F_1 ( struct V_1 * V_1 ,
unsigned char * V_2 ,
unsigned char V_3 )
{
unsigned long V_4 ;
V_4 = ( ( void V_5 * ) V_2 ) - V_1 -> V_6 -> V_7 . V_8 ;
V_1 -> V_6 -> V_9 -> V_10 -> V_11 ( V_1 -> V_6 , V_12 , V_4 ,
V_3 ) ;
}
static inline void F_2 ( struct V_1 * V_1 ,
unsigned char * V_2 ,
unsigned char V_3 )
{
F_1 ( V_1 , V_2 , V_3 ) ;
}
static inline unsigned char F_3 ( struct V_1 * V_1 ,
unsigned char * V_13 )
{
unsigned long V_4 ;
unsigned char V_3 ;
V_4 = ( ( void V_5 * ) V_13 ) - V_1 -> V_6 -> V_7 . V_8 ;
V_1 -> V_6 -> V_9 -> V_10 -> V_14 ( V_1 -> V_6 , V_12 , V_4 ,
& V_3 ) ;
return V_3 ;
}
static struct V_1 * F_4 ( struct V_15 * V_16 )
{
struct V_1 * V_17 ;
F_5 (p, &ipoctal_list, list) {
if ( V_16 -> V_18 -> V_19 == V_17 -> V_20 -> V_19 )
return V_17 ;
}
return NULL ;
}
static int F_6 ( struct V_21 * V_22 , struct V_15 * V_16 )
{
struct V_1 * V_1 ;
int V_23 = V_16 -> V_24 ;
V_1 = F_4 ( V_16 ) ;
if ( V_1 == NULL ) {
F_7 ( L_1 , V_16 -> V_18 -> V_19 ) ;
return - V_25 ;
}
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_30 ) ;
V_16 -> V_31 = V_1 ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_32 * V_32 )
{
int V_23 = V_16 -> V_24 ;
int V_33 ;
struct V_1 * V_1 ;
V_1 = F_4 ( V_16 ) ;
if ( V_1 == NULL ) {
F_7 ( L_1 , V_16 -> V_18 -> V_19 ) ;
return - V_25 ;
}
if ( F_9 ( & V_1 -> V_34 [ V_23 ] ) )
return - V_35 ;
V_33 = F_10 ( & V_1 -> V_21 [ V_23 ] , V_16 , V_32 ) ;
if ( V_33 )
return V_33 ;
F_11 ( & V_1 -> V_34 [ V_23 ] ) ;
return 0 ;
}
static void F_12 ( struct V_36 * V_37 )
{
V_37 -> V_38 = 0 ;
V_37 -> V_39 = 0 ;
V_37 -> V_40 = 0 ;
V_37 -> V_41 = 0 ;
V_37 -> V_42 = 0 ;
V_37 -> V_43 = 0 ;
}
static void F_13 ( struct V_15 * V_16 )
{
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_31 ;
if ( V_1 == NULL )
return;
F_12 ( & V_1 -> V_44 [ V_23 ] ) ;
V_1 -> V_45 [ V_23 ] = 0 ;
V_1 -> V_46 [ V_23 ] = 0 ;
V_1 -> V_47 [ V_23 ] = 0 ;
}
static void F_14 ( struct V_15 * V_16 , struct V_32 * V_48 )
{
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_31 ;
F_15 ( & V_1 -> V_21 [ V_23 ] , V_16 , V_48 ) ;
if ( F_16 ( & V_1 -> V_34 [ V_23 ] ) )
F_13 ( V_16 ) ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = V_16 -> V_31 ;
int V_23 = V_16 -> V_24 ;
V_50 -> V_51 = 0 ;
V_50 -> V_52 = 0 ;
V_50 -> V_53 = 0 ;
V_50 -> V_54 = 0 ;
V_50 -> V_39 = V_1 -> V_44 [ V_23 ] . V_39 ;
V_50 -> V_38 = V_1 -> V_44 [ V_23 ] . V_38 ;
V_50 -> V_55 = V_1 -> V_44 [ V_23 ] . V_41 ;
V_50 -> V_56 = V_1 -> V_44 [ V_23 ] . V_43 ;
V_50 -> V_57 = V_1 -> V_44 [ V_23 ] . V_40 ;
return 0 ;
}
static int F_18 ( void * V_58 )
{
unsigned int V_23 ;
unsigned int V_59 ;
unsigned char V_60 ;
unsigned char V_61 ;
unsigned char V_62 , V_63 ;
unsigned char V_3 ;
unsigned char V_64 ;
struct V_15 * V_16 ;
struct V_1 * V_1 = (struct V_1 * ) V_58 ;
for ( V_23 = 0 ; V_23 < V_65 ; V_23 ++ ) {
if ( ! F_9 ( & V_1 -> V_34 [ V_23 ] ) )
continue;
V_16 = F_19 ( & V_1 -> V_21 [ V_23 ] ) ;
if ( ! V_16 )
continue;
V_59 = V_23 / 2 ;
V_60 = F_3 ( V_1 ,
& V_1 -> V_66 [ V_59 ] . V_27 . V_67 . V_60 ) ;
V_61 = F_3 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_67 . V_61 ) ;
if ( ( V_23 % 2 ) == 1 ) {
V_62 = V_60 & V_68 ;
V_63 = V_60 & V_69 ;
} else {
V_62 = V_60 & V_70 ;
V_63 = V_60 & V_71 ;
}
if ( ( V_1 -> V_72 == V_73 ) &&
( V_61 & V_74 ) &&
( V_1 -> V_47 [ V_23 ] == 0 ) ) {
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_75 ) ;
F_2 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_76 ) ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_30 ) ;
V_1 -> V_77 = 1 ;
F_20 ( & V_1 -> V_78 [ V_23 ] ) ;
}
if ( V_63 && ( V_61 & V_79 ) ) {
V_3 = F_3 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_67 . V_80 ) ;
V_64 = V_81 ;
if ( V_61 & V_82 ) {
F_2 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_83 ) ;
if ( V_61 & V_84 ) {
V_1 -> V_85 [ V_23 ] |= V_86 ;
V_1 -> V_44 [ V_23 ] . V_42 ++ ;
F_21 ( V_16 , 0 , V_87 ) ;
}
if ( V_61 & V_88 ) {
V_1 -> V_85 [ V_23 ] |= V_89 ;
V_1 -> V_44 [ V_23 ] . V_43 ++ ;
V_64 = V_90 ;
}
if ( V_61 & V_91 ) {
V_1 -> V_85 [ V_23 ] |= V_92 ;
V_1 -> V_44 [ V_23 ] . V_41 ++ ;
V_64 = V_93 ;
}
if ( V_61 & V_94 ) {
V_1 -> V_85 [ V_23 ] |= V_95 ;
V_1 -> V_44 [ V_23 ] . V_40 ++ ;
V_64 = V_96 ;
}
}
F_21 ( V_16 , V_3 , V_64 ) ;
}
if ( V_62 && ( V_61 & V_97 ) ) {
unsigned int * V_46 =
& V_1 -> V_46 [ V_23 ] ;
if ( V_1 -> V_47 [ V_23 ] <= 0 ) {
V_1 -> V_47 [ V_23 ] = 0 ;
continue;
}
F_22 ( & V_1 -> V_98 [ V_23 ] ) ;
V_3 = V_1 -> V_99 [ V_23 ] [ * V_46 ] ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_100 ,
V_3 ) ;
V_1 -> V_44 [ V_23 ] . V_38 ++ ;
V_1 -> V_101 [ V_23 ] ++ ;
( * V_46 ) ++ ;
* V_46 = * V_46 % V_102 ;
V_1 -> V_47 [ V_23 ] -- ;
F_23 ( & V_1 -> V_98 [ V_23 ] ) ;
if ( ( V_1 -> V_47 [ V_23 ] == 0 ) &&
( F_24 ( & V_1 -> V_78 [ V_23 ] ) ) ) {
if ( V_1 -> V_72 != V_73 ) {
V_1 -> V_77 = 1 ;
F_20 ( & V_1 -> V_78 [ V_23 ] ) ;
}
}
}
F_25 ( V_16 ) ;
F_26 ( V_16 ) ;
}
return V_103 ;
}
static int F_27 ( struct V_104 * V_6 , unsigned char * V_105 )
{
unsigned char V_106 ;
unsigned char V_72 ;
V_6 -> V_9 -> V_10 -> V_14 ( V_6 , V_107 ,
V_108 , & V_106 ) ;
if ( V_106 != V_109 )
return - V_25 ;
V_6 -> V_9 -> V_10 -> V_14 ( V_6 , V_107 ,
V_110 , ( unsigned char * ) & V_72 ) ;
switch ( V_72 ) {
case V_111 :
case V_112 :
case V_73 :
* V_105 = V_72 ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , unsigned int V_113 ,
unsigned int V_114 , unsigned int V_115 )
{
int V_33 = 0 ;
int V_116 ;
struct V_117 * V_16 ;
char V_118 [ 20 ] ;
unsigned char V_72 ;
V_33 = V_1 -> V_6 -> V_9 -> V_10 -> V_119 ( V_1 -> V_6 , 0 ,
V_107 ) ;
if ( V_33 ) {
F_7 ( L_2 , V_113 , V_114 ) ;
return V_33 ;
}
V_33 = F_27 ( V_1 -> V_6 , & V_72 ) ;
if ( V_33 ) {
V_1 -> V_6 -> V_9 -> V_10 -> V_120 ( V_1 -> V_6 ,
V_107 ) ;
goto V_121;
}
V_1 -> V_72 = V_72 ;
V_33 = V_1 -> V_6 -> V_9 -> V_10 -> V_119 ( V_1 -> V_6 , 0 ,
V_12 ) ;
if ( V_33 ) {
F_7 ( L_3 , V_113 , V_114 ) ;
goto V_121;
}
V_33 = V_1 -> V_6 -> V_9 -> V_10 -> V_119 ( V_1 -> V_6 ,
0x8000 , V_122 ) ;
if ( V_33 ) {
F_7 ( L_4 , V_113 , V_114 ) ;
goto V_123;
}
V_1 -> V_26 =
(struct V_124 * ) V_1 -> V_6 -> V_7 . V_8 ;
V_1 -> V_66 =
(struct V_125 * ) V_1 -> V_6 -> V_7 . V_8 ;
for ( V_116 = 0 ; V_116 < V_65 ; V_116 ++ ) {
F_1 ( V_1 , & V_1 -> V_26 [ V_116 ] . V_27 . V_28 . V_29 ,
V_126 | V_75 ) ;
}
for ( V_116 = 0 ; V_116 < V_127 ; V_116 ++ ) {
F_1 ( V_1 ,
& V_1 -> V_66 [ V_116 ] . V_27 . V_28 . V_128 ,
V_129 ) ;
F_1 ( V_1 ,
& V_1 -> V_66 [ V_116 ] . V_27 . V_28 . V_130 ,
V_131 | V_132 |
V_133 ) ;
F_1 ( V_1 ,
& V_1 -> V_66 [ V_116 ] . V_27 . V_28 . V_134 ,
V_135 | V_136 |
V_137 | V_138 |
V_139 | V_140 ) ;
}
V_1 -> V_6 -> V_9 -> V_10 -> V_141 ( V_1 -> V_6 , V_115 ,
F_18 , V_1 ) ;
V_1 -> V_6 -> V_9 -> V_10 -> V_11 ( V_1 -> V_6 , V_107 , 0 , V_115 ) ;
V_16 = F_29 ( V_65 ) ;
if ( ! V_16 ) {
V_33 = - V_142 ;
goto V_143;
}
V_16 -> V_144 = V_145 ;
V_16 -> V_146 = L_5 ;
sprintf ( V_118 , L_6 , V_113 , V_114 ) ;
V_16 -> V_118 = V_118 ;
V_16 -> V_19 = 0 ;
V_16 -> V_147 = 0 ;
V_16 -> type = V_148 ;
V_16 -> V_149 = V_150 ;
V_16 -> V_151 = V_152 | V_153 ;
V_16 -> V_154 = V_155 ;
V_16 -> V_154 . V_156 = V_157 | V_158 | V_159 | V_160 | V_161 ;
V_16 -> V_154 . V_162 = 9600 ;
V_16 -> V_154 . V_163 = 9600 ;
F_30 ( V_16 , & V_164 ) ;
V_33 = F_31 ( V_16 ) ;
if ( V_33 ) {
F_7 ( L_7 ) ;
F_32 ( V_16 ) ;
goto V_143;
}
V_1 -> V_20 = V_16 ;
for ( V_116 = 0 ; V_116 < V_65 ; V_116 ++ ) {
F_33 ( & V_1 -> V_21 [ V_116 ] ) ;
F_34 ( & V_1 -> V_21 [ V_116 ] ) ;
V_1 -> V_21 [ V_116 ] . V_10 = & V_165 ;
F_12 ( & V_1 -> V_44 [ V_116 ] ) ;
V_1 -> V_47 [ V_116 ] = 0 ;
F_35 ( & V_1 -> V_78 [ V_116 ] ) ;
V_1 -> V_85 [ V_116 ] = V_166 ;
F_36 ( & V_1 -> V_98 [ V_116 ] ) ;
V_1 -> V_45 [ V_116 ] = 0 ;
V_1 -> V_46 [ V_116 ] = 0 ;
V_1 -> V_47 [ V_116 ] = 0 ;
F_37 ( V_16 , V_116 , NULL ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_116 ] . V_27 . V_28 . V_29 ,
V_30 ) ;
}
return 0 ;
V_143:
V_1 -> V_6 -> V_9 -> V_10 -> V_120 ( V_1 -> V_6 , V_107 ) ;
V_123:
V_1 -> V_6 -> V_9 -> V_10 -> V_120 ( V_1 -> V_6 , V_12 ) ;
V_121:
V_1 -> V_6 -> V_9 -> V_10 -> V_120 ( V_1 -> V_6 , V_122 ) ;
return V_33 ;
}
static inline int F_38 ( struct V_1 * V_1 ,
unsigned int V_23 ,
const unsigned char * V_167 ,
int V_168 )
{
unsigned long V_151 ;
int V_116 ;
unsigned int * V_45 = & V_1 -> V_45 [ V_23 ] ;
for ( V_116 = 0 ; V_116 < V_168 ; V_116 ++ ) {
if ( V_116 <= ( V_102 - V_1 -> V_47 [ V_23 ] ) ) {
F_39 ( & V_1 -> V_98 [ V_23 ] , V_151 ) ;
V_1 -> V_21 [ V_23 ] . V_169 [ * V_45 ] = V_167 [ V_116 ] ;
* V_45 = ( * V_45 + 1 ) % V_102 ;
V_1 -> V_47 [ V_23 ] ++ ;
F_40 ( & V_1 -> V_98 [ V_23 ] , V_151 ) ;
} else {
break;
}
}
return V_116 ;
}
static int F_41 ( struct V_1 * V_1 , unsigned int V_23 ,
const unsigned char * V_167 , int V_168 )
{
V_1 -> V_47 [ V_23 ] = 0 ;
V_1 -> V_101 [ V_23 ] = 0 ;
F_38 ( V_1 , V_23 , V_167 , V_168 ) ;
V_1 -> V_85 [ V_23 ] = V_166 ;
if ( V_1 -> V_72 == V_73 ) {
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_126 ) ;
F_2 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_170 ) ;
}
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_171 ) ;
F_42 ( V_1 -> V_78 [ V_23 ] , V_1 -> V_77 ) ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_75 ) ;
V_1 -> V_77 = 0 ;
return V_1 -> V_101 [ V_23 ] ;
}
static int F_43 ( struct V_15 * V_16 ,
const unsigned char * V_167 , int V_168 )
{
unsigned int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_31 ;
return F_41 ( V_1 , V_23 , V_167 , V_168 ) ;
}
static int F_44 ( struct V_15 * V_16 )
{
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_31 ;
return V_102 - V_1 -> V_47 [ V_23 ] ;
}
static int F_45 ( struct V_15 * V_16 )
{
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_31 ;
return V_1 -> V_47 [ V_23 ] ;
}
static void F_46 ( struct V_15 * V_16 ,
struct V_172 * V_173 )
{
unsigned int V_174 ;
unsigned char V_175 = 0 ;
unsigned char V_176 = 0 ;
unsigned char V_177 = 0 ;
unsigned int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_31 ;
T_1 V_178 ;
V_174 = V_16 -> V_179 -> V_156 ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_126 | V_75 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_180 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_181 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_83 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_182 ) ;
switch ( V_174 & V_183 ) {
case V_184 :
V_175 |= V_185 ;
break;
case V_186 :
V_175 |= V_187 ;
break;
case V_158 :
default:
V_175 |= V_188 ;
V_16 -> V_179 -> V_156 = ( V_174 & ~ V_183 ) | V_158 ;
break;
}
if ( V_174 & V_189 )
if ( V_174 & V_190 )
V_175 |= V_191 | V_192 ;
else
V_175 |= V_191 | V_193 ;
else
V_175 |= V_194 ;
V_16 -> V_179 -> V_156 &= ~ V_195 ;
if ( V_174 & V_196 )
V_176 |= V_197 ;
else
V_176 |= V_198 ;
switch ( V_1 -> V_72 ) {
case V_111 :
if ( V_174 & V_199 ) {
V_175 |= V_200 ;
V_176 |= V_201 | V_202 ;
V_1 -> V_203 [ V_23 ] . V_204 = 1 ;
} else {
V_175 |= V_205 ;
V_176 |= V_201 | V_206 ;
V_1 -> V_203 [ V_23 ] . V_204 = 0 ;
}
break;
case V_112 :
V_175 |= V_205 ;
V_176 |= V_201 | V_206 ;
V_1 -> V_203 [ V_23 ] . V_204 = 0 ;
break;
case V_73 :
V_175 |= V_205 ;
V_176 |= V_207 | V_206 ;
V_1 -> V_203 [ V_23 ] . V_204 = 0 ;
break;
default:
return;
break;
}
V_178 = F_47 ( V_16 ) ;
F_48 ( V_16 -> V_179 , V_178 , V_178 ) ;
switch ( V_16 -> V_179 -> V_163 ) {
case 75 :
V_177 |= V_208 | V_209 ;
break;
case 110 :
V_177 |= V_210 | V_211 ;
break;
case 150 :
V_177 |= V_212 | V_213 ;
break;
case 300 :
V_177 |= V_214 | V_215 ;
break;
case 600 :
V_177 |= V_216 | V_217 ;
break;
case 1200 :
V_177 |= V_218 | V_219 ;
break;
case 1800 :
V_177 |= V_220 | V_221 ;
break;
case 2000 :
V_177 |= V_222 | V_223 ;
break;
case 2400 :
V_177 |= V_224 | V_225 ;
break;
case 4800 :
V_177 |= V_226 | V_227 ;
break;
case 9600 :
V_177 |= V_228 | V_229 ;
break;
case 19200 :
V_177 |= V_230 | V_231 ;
break;
case 38400 :
default:
V_177 |= V_232 | V_233 ;
F_48 ( V_16 -> V_179 , 38400 , 38400 ) ;
break;
}
V_175 |= V_234 ;
V_175 |= V_235 ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_236 , V_175 ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_236 , V_176 ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_177 , V_177 ) ;
V_1 -> V_203 [ V_23 ] . V_178 = F_47 ( V_16 ) ;
V_1 -> V_203 [ V_23 ] . V_237 = V_174 & V_183 ;
V_1 -> V_203 [ V_23 ] . V_56 = V_174 & V_189 ;
V_1 -> V_203 [ V_23 ] . V_238 = V_174 & V_196 ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_30 ) ;
}
static void F_49 ( struct V_15 * V_16 )
{
unsigned long V_151 ;
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_31 ;
if ( V_1 == NULL )
return;
F_39 ( & V_1 -> V_98 [ V_23 ] , V_151 ) ;
V_1 -> V_47 [ V_23 ] = 0 ;
V_1 -> V_45 [ V_23 ] = 0 ;
V_1 -> V_46 [ V_23 ] = 0 ;
F_40 ( & V_1 -> V_98 [ V_23 ] , V_151 ) ;
F_50 ( & V_1 -> V_21 [ V_23 ] ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_126 | V_75 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_180 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_181 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_83 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_182 ) ;
F_51 ( V_239 , & V_1 -> V_21 [ V_23 ] . V_151 ) ;
F_20 ( & V_1 -> V_21 [ V_23 ] . V_240 ) ;
}
static int F_52 ( struct V_104 * V_6 )
{
int V_33 ;
unsigned char V_72 ;
if ( ( ! V_6 -> V_9 -> V_10 ) || ( ! V_6 -> V_9 -> V_10 -> V_119 ) ||
( ! V_6 -> V_9 -> V_10 -> V_120 ) )
return 0 ;
V_33 = V_6 -> V_9 -> V_10 -> V_119 ( V_6 , 0 , V_107 ) ;
if ( V_33 )
return 0 ;
V_33 = F_27 ( V_6 , & V_72 ) ;
V_6 -> V_9 -> V_10 -> V_120 ( V_6 , V_107 ) ;
if ( ! V_33 )
return 1 ;
return 0 ;
}
static int F_53 ( struct V_104 * V_6 )
{
int V_33 ;
struct V_1 * V_1 ;
V_1 = F_54 ( sizeof( struct V_1 ) , V_241 ) ;
if ( V_1 == NULL )
return - V_142 ;
V_1 -> V_6 = V_6 ;
V_33 = F_28 ( V_1 , V_6 -> V_113 , V_6 -> V_114 , V_6 -> V_242 ) ;
if ( V_33 )
goto V_243;
F_55 ( & V_1 -> V_244 , & V_245 ) ;
return 0 ;
V_243:
F_56 ( V_1 ) ;
return V_33 ;
}
static void F_57 ( struct V_1 * V_1 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_65 ; V_116 ++ ) {
F_58 ( V_1 -> V_20 , V_116 ) ;
F_59 ( & V_1 -> V_21 [ V_116 ] ) ;
}
F_60 ( V_1 -> V_20 ) ;
F_32 ( V_1 -> V_20 ) ;
if ( V_1 -> V_6 -> V_9 -> V_10 -> V_246 != NULL )
V_1 -> V_6 -> V_9 -> V_10 -> V_246 ( V_1 -> V_6 ) ;
F_61 ( & V_1 -> V_244 ) ;
F_56 ( V_1 ) ;
}
static void F_62 ( struct V_104 * V_247 )
{
struct V_1 * V_1 , * V_248 ;
F_63 (ipoctal, next, &ipoctal_list, list) {
if ( V_1 -> V_6 == V_247 )
F_57 ( V_1 ) ;
}
}
static int T_2 F_64 ( void )
{
V_18 . V_10 = & V_249 ;
return F_65 ( & V_18 , V_145 , V_250 ) ;
}
static void T_3 F_66 ( void )
{
struct V_1 * V_17 , * V_248 ;
F_63 (p, next, &ipoctal_list, list)
F_57 ( V_17 ) ;
F_67 ( & V_18 ) ;
}
