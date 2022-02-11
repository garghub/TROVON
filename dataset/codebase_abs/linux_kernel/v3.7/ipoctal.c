static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 -> V_7 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
return 0 ;
}
static int F_4 ( struct V_3 * V_4 , struct V_12 * V_12 )
{
int V_13 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 -> V_7 ) ;
if ( F_5 ( & V_6 -> V_14 ) )
return - V_15 ;
V_4 -> V_16 = V_6 ;
V_13 = F_6 ( & V_6 -> V_1 , V_4 , V_12 ) ;
if ( V_13 )
return V_13 ;
F_7 ( & V_6 -> V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_17 * V_18 )
{
V_18 -> V_19 = 0 ;
V_18 -> V_20 = 0 ;
V_18 -> V_21 = 0 ;
V_18 -> V_22 = 0 ;
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_18 ) ;
V_6 -> V_25 = 0 ;
V_6 -> V_26 = 0 ;
V_6 -> V_27 = 0 ;
}
static void F_10 ( struct V_3 * V_4 , struct V_12 * V_28 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
F_11 ( & V_6 -> V_1 , V_4 , V_28 ) ;
if ( F_12 ( & V_6 -> V_14 ) )
F_9 ( V_6 ) ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
V_30 -> V_31 = 0 ;
V_30 -> V_32 = 0 ;
V_30 -> V_33 = 0 ;
V_30 -> V_34 = 0 ;
V_30 -> V_20 = V_6 -> V_18 . V_20 ;
V_30 -> V_19 = V_6 -> V_18 . V_19 ;
V_30 -> V_35 = V_6 -> V_18 . V_22 ;
V_30 -> V_36 = V_6 -> V_18 . V_24 ;
V_30 -> V_37 = V_6 -> V_18 . V_21 ;
return 0 ;
}
static void F_14 ( struct V_5 * V_6 ,
struct V_3 * V_4 , T_1 V_38 )
{
unsigned char V_39 ;
unsigned char V_40 = V_41 ;
T_1 V_42 ;
do {
V_39 = F_15 ( & V_6 -> V_9 -> V_43 . V_44 ) ;
if ( V_38 & V_45 ) {
F_3 ( V_46 , & V_6 -> V_9 -> V_10 . V_11 ) ;
if ( V_38 & V_47 ) {
V_6 -> V_18 . V_23 ++ ;
F_16 ( V_4 , 0 , V_48 ) ;
}
if ( V_38 & V_49 ) {
V_6 -> V_18 . V_24 ++ ;
V_40 = V_50 ;
}
if ( V_38 & V_51 ) {
V_6 -> V_18 . V_22 ++ ;
V_40 = V_52 ;
}
if ( V_38 & V_53 ) {
F_3 ( V_54 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_18 . V_21 ++ ;
V_40 = V_55 ;
}
}
F_16 ( V_4 , V_39 , V_40 ) ;
V_42 = F_15 ( & V_6 -> V_56 -> V_43 . V_42 ) ;
V_38 = F_15 ( & V_6 -> V_9 -> V_43 . V_38 ) ;
} while ( V_42 & V_6 -> V_57 );
F_17 ( V_4 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
unsigned char V_39 ;
unsigned int * V_26 = & V_6 -> V_26 ;
if ( V_6 -> V_27 <= 0 ) {
V_6 -> V_27 = 0 ;
return;
}
V_39 = V_6 -> V_1 . V_58 [ * V_26 ] ;
F_3 ( V_39 , & V_6 -> V_9 -> V_10 . V_59 ) ;
V_6 -> V_18 . V_19 ++ ;
( * V_26 ) ++ ;
* V_26 = * V_26 % V_60 ;
V_6 -> V_27 -- ;
if ( ( V_6 -> V_27 == 0 ) &&
( F_19 ( & V_6 -> V_61 ) ) ) {
if ( V_6 -> V_62 != V_63 ) {
* V_6 -> V_64 = 1 ;
F_20 ( & V_6 -> V_61 ) ;
}
}
}
static void F_21 ( struct V_5 * V_6 )
{
T_1 V_42 , V_38 ;
struct V_3 * V_4 ;
if ( ! F_5 ( & V_6 -> V_14 ) )
return;
V_4 = F_22 ( & V_6 -> V_1 ) ;
if ( ! V_4 )
return;
V_42 = F_15 ( & V_6 -> V_56 -> V_43 . V_42 ) ;
V_38 = F_15 ( & V_6 -> V_9 -> V_43 . V_38 ) ;
if ( ( V_6 -> V_62 == V_63 ) &&
( V_38 & V_65 ) && ( V_6 -> V_27 == 0 ) ) {
F_3 ( V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_67 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
* V_6 -> V_64 = 1 ;
F_20 ( & V_6 -> V_61 ) ;
}
if ( ( V_42 & V_6 -> V_57 ) && ( V_38 & V_68 ) )
F_14 ( V_6 , V_4 , V_38 ) ;
if ( ( V_42 & V_6 -> V_69 ) && ( V_38 & V_70 ) )
F_18 ( V_6 ) ;
F_17 ( V_4 ) ;
F_23 ( V_4 ) ;
}
static T_2 F_24 ( void * V_71 )
{
unsigned int V_72 ;
struct V_73 * V_73 = (struct V_73 * ) V_71 ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ )
F_21 ( & V_73 -> V_6 [ V_72 ] ) ;
F_25 ( V_73 -> V_7 -> V_75 . V_76 + V_77 ) ;
F_25 ( V_73 -> V_7 -> V_75 . V_76 + V_78 ) ;
return V_79 ;
}
static int F_26 ( struct V_80 * V_7 , unsigned char * V_81 )
{
unsigned char V_82 ;
unsigned char V_62 ;
V_82 = F_15 ( V_7 -> V_83 . V_76 + V_84 ) ;
if ( V_82 != V_85 )
return - V_86 ;
V_62 = F_15 ( V_7 -> V_83 . V_76 + V_87 ) ;
switch ( V_62 ) {
case V_88 :
case V_89 :
case V_63 :
* V_81 = V_62 ;
break;
default:
return - V_86 ;
}
return 0 ;
}
static int F_27 ( struct V_73 * V_73 , unsigned int V_90 ,
unsigned int V_91 )
{
int V_13 = 0 ;
int V_72 ;
struct V_92 * V_4 ;
char V_93 [ 20 ] ;
unsigned char V_62 ;
struct V_5 * V_6 ;
union V_94 T_3 * V_95 ;
union V_96 T_3 * V_56 ;
V_13 = V_73 -> V_7 -> V_97 -> V_98 -> V_99 ( V_73 -> V_7 , 0 ,
V_100 ) ;
if ( V_13 ) {
F_28 ( & V_73 -> V_7 -> V_7 ,
L_1 ,
V_90 , V_91 ) ;
return V_13 ;
}
V_13 = F_26 ( V_73 -> V_7 , & V_62 ) ;
if ( V_13 ) {
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 ,
V_100 ) ;
goto V_102;
}
V_73 -> V_62 = V_62 ;
V_13 = V_73 -> V_7 -> V_97 -> V_98 -> V_99 ( V_73 -> V_7 , 0 ,
V_103 ) ;
if ( V_13 ) {
F_28 ( & V_73 -> V_7 -> V_7 ,
L_2 ,
V_90 , V_91 ) ;
goto V_102;
}
V_13 = V_73 -> V_7 -> V_97 -> V_98 -> V_99 ( V_73 -> V_7 , 0 ,
V_104 ) ;
if ( V_13 ) {
F_28 ( & V_73 -> V_7 -> V_7 ,
L_3 ,
V_90 , V_91 ) ;
goto V_105;
}
V_13 = V_73 -> V_7 -> V_97 -> V_98 -> V_99 ( V_73 -> V_7 ,
0x8000 , V_106 ) ;
if ( V_13 ) {
F_28 ( & V_73 -> V_7 -> V_7 ,
L_4 ,
V_90 , V_91 ) ;
goto V_107;
}
V_95 =
(union V_94 T_3 * ) V_73 -> V_7 -> V_108 . V_76 ;
V_56 =
(union V_96 T_3 * ) V_73 -> V_7 -> V_108 . V_76 ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
struct V_5 * V_6 = & V_73 -> V_6 [ V_72 ] ;
V_6 -> V_9 = V_95 + V_72 ;
V_6 -> V_56 = V_56 + ( V_72 >> 1 ) ;
V_6 -> V_64 = & V_73 -> V_109 ;
V_6 -> V_62 = V_73 -> V_62 ;
if ( V_72 & 1 ) {
V_6 -> V_69 = V_110 ;
V_6 -> V_57 = V_111 ;
} else {
V_6 -> V_69 = V_112 ;
V_6 -> V_57 = V_113 ;
}
F_3 ( V_114 | V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_115 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_116 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_117 | V_118 | V_119 ,
& V_6 -> V_9 -> V_10 . V_120 ) ;
F_3 ( 0 , & V_6 -> V_9 -> V_10 . V_120 ) ;
F_3 ( V_121 | V_122 , & V_6 -> V_9 -> V_10 . V_123 ) ;
}
for ( V_72 = 0 ; V_72 < V_124 ; V_72 ++ ) {
F_3 ( V_125 , & V_56 [ V_72 ] . V_10 . V_126 ) ;
F_3 ( V_127 | V_128 | V_129 ,
& V_56 [ V_72 ] . V_10 . V_130 ) ;
F_3 ( V_131 | V_132 | V_133 |
V_134 | V_135 | V_136 ,
& V_56 [ V_72 ] . V_10 . V_137 ) ;
}
V_73 -> V_7 -> V_97 -> V_98 -> V_138 ( V_73 -> V_7 ,
F_24 , V_73 ) ;
F_3 ( 1 , V_73 -> V_7 -> V_139 . V_76 + 1 ) ;
V_4 = F_29 ( V_74 ) ;
if ( ! V_4 ) {
V_13 = - V_140 ;
goto V_141;
}
V_4 -> V_142 = V_143 ;
V_4 -> V_144 = V_145 ;
sprintf ( V_93 , V_145 L_5 , V_90 , V_91 ) ;
V_4 -> V_93 = V_93 ;
V_4 -> V_146 = 0 ;
V_4 -> V_147 = 0 ;
V_4 -> type = V_148 ;
V_4 -> V_149 = V_150 ;
V_4 -> V_151 = V_152 | V_153 ;
V_4 -> V_154 = V_155 ;
V_4 -> V_154 . V_156 = V_157 | V_158 | V_159 | V_160 | V_161 ;
V_4 -> V_154 . V_162 = 9600 ;
V_4 -> V_154 . V_163 = 9600 ;
F_30 ( V_4 , & V_164 ) ;
V_13 = F_31 ( V_4 ) ;
if ( V_13 ) {
F_28 ( & V_73 -> V_7 -> V_7 , L_6 ) ;
F_32 ( V_4 ) ;
goto V_141;
}
V_73 -> V_165 = V_4 ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
struct V_166 * V_167 ;
V_6 = & V_73 -> V_6 [ V_72 ] ;
F_33 ( & V_6 -> V_1 ) ;
F_34 ( & V_6 -> V_1 ) ;
V_6 -> V_1 . V_98 = & V_168 ;
F_8 ( & V_6 -> V_18 ) ;
V_6 -> V_27 = 0 ;
F_35 ( & V_6 -> V_61 ) ;
F_36 ( & V_6 -> V_169 ) ;
V_6 -> V_25 = 0 ;
V_6 -> V_26 = 0 ;
V_167 = F_37 ( & V_6 -> V_1 , V_4 , V_72 , NULL ) ;
if ( F_38 ( V_167 ) ) {
F_28 ( & V_73 -> V_7 -> V_7 , L_7 ) ;
continue;
}
F_39 ( V_167 , V_6 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
return 0 ;
V_141:
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_100 ) ;
V_107:
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_104 ) ;
V_105:
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_103 ) ;
V_102:
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_106 ) ;
return V_13 ;
}
static inline int F_40 ( struct V_5 * V_6 ,
const unsigned char * V_170 ,
int V_171 )
{
unsigned long V_151 ;
int V_72 ;
unsigned int * V_25 = & V_6 -> V_25 ;
for ( V_72 = 0 ; V_72 < V_171 ; V_72 ++ ) {
if ( V_72 <= ( V_60 - V_6 -> V_27 ) ) {
F_41 ( & V_6 -> V_169 , V_151 ) ;
V_6 -> V_1 . V_58 [ * V_25 ] = V_170 [ V_72 ] ;
* V_25 = ( * V_25 + 1 ) % V_60 ;
V_6 -> V_27 ++ ;
F_42 ( & V_6 -> V_169 , V_151 ) ;
} else {
break;
}
}
return V_72 ;
}
static int F_43 ( struct V_3 * V_4 ,
const unsigned char * V_170 , int V_171 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
unsigned int V_172 ;
V_172 = F_40 ( V_6 , V_170 , V_171 ) ;
if ( V_6 -> V_62 == V_63 ) {
F_3 ( V_114 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_173 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
F_3 ( V_174 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_44 ( V_6 -> V_61 , * V_6 -> V_64 ) ;
F_3 ( V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
* V_6 -> V_64 = 0 ;
return V_172 ;
}
static int F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
return V_60 - V_6 -> V_27 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
return V_6 -> V_27 ;
}
static void F_47 ( struct V_3 * V_4 ,
struct V_175 * V_176 )
{
unsigned int V_177 ;
unsigned char V_178 = 0 ;
unsigned char V_179 = 0 ;
unsigned char V_123 = 0 ;
struct V_5 * V_6 = V_4 -> V_16 ;
T_4 V_180 ;
V_177 = V_4 -> V_181 . V_156 ;
F_3 ( V_114 | V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_115 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_116 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_46 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_182 , & V_6 -> V_9 -> V_10 . V_11 ) ;
switch ( V_177 & V_183 ) {
case V_184 :
V_178 |= V_185 ;
break;
case V_186 :
V_178 |= V_187 ;
break;
case V_158 :
default:
V_178 |= V_117 ;
V_4 -> V_181 . V_156 = ( V_177 & ~ V_183 ) | V_158 ;
break;
}
if ( V_177 & V_188 )
if ( V_177 & V_189 )
V_178 |= V_190 | V_191 ;
else
V_178 |= V_190 | V_192 ;
else
V_178 |= V_193 ;
V_4 -> V_181 . V_156 &= ~ V_194 ;
if ( V_177 & V_195 )
V_179 |= V_196 ;
else
V_179 |= V_197 ;
switch ( V_6 -> V_62 ) {
case V_88 :
if ( V_177 & V_198 ) {
V_178 |= V_199 ;
V_179 |= V_200 | V_201 ;
} else {
V_178 |= V_202 ;
V_179 |= V_200 | V_203 ;
}
break;
case V_89 :
V_178 |= V_202 ;
V_179 |= V_200 | V_203 ;
break;
case V_63 :
V_178 |= V_202 ;
V_179 |= V_204 | V_203 ;
break;
default:
return;
break;
}
V_180 = F_48 ( V_4 ) ;
F_49 ( & V_4 -> V_181 , V_180 , V_180 ) ;
switch ( V_180 ) {
case 75 :
V_123 |= V_205 | V_206 ;
break;
case 110 :
V_123 |= V_207 | V_208 ;
break;
case 150 :
V_123 |= V_209 | V_210 ;
break;
case 300 :
V_123 |= V_211 | V_212 ;
break;
case 600 :
V_123 |= V_213 | V_214 ;
break;
case 1200 :
V_123 |= V_215 | V_216 ;
break;
case 1800 :
V_123 |= V_217 | V_218 ;
break;
case 2000 :
V_123 |= V_219 | V_220 ;
break;
case 2400 :
V_123 |= V_221 | V_222 ;
break;
case 4800 :
V_123 |= V_223 | V_224 ;
break;
case 9600 :
V_123 |= V_121 | V_122 ;
break;
case 19200 :
V_123 |= V_225 | V_226 ;
break;
case 38400 :
default:
V_123 |= V_227 | V_228 ;
F_49 ( & V_4 -> V_181 , 38400 , 38400 ) ;
break;
}
V_178 |= V_118 ;
V_178 |= V_119 ;
F_3 ( V_178 , & V_6 -> V_9 -> V_10 . V_120 ) ;
F_3 ( V_179 , & V_6 -> V_9 -> V_10 . V_120 ) ;
F_3 ( V_123 , & V_6 -> V_9 -> V_10 . V_123 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
static void F_50 ( struct V_3 * V_4 )
{
unsigned long V_151 ;
struct V_5 * V_6 = V_4 -> V_16 ;
if ( V_6 == NULL )
return;
F_41 ( & V_6 -> V_169 , V_151 ) ;
V_6 -> V_27 = 0 ;
V_6 -> V_25 = 0 ;
V_6 -> V_26 = 0 ;
F_42 ( & V_6 -> V_169 , V_151 ) ;
F_51 ( & V_6 -> V_1 ) ;
F_3 ( V_114 | V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_115 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_116 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_46 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_182 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_52 ( V_229 , & V_6 -> V_1 . V_151 ) ;
F_20 ( & V_6 -> V_1 . V_230 ) ;
}
static int F_53 ( struct V_80 * V_7 )
{
int V_13 ;
struct V_73 * V_73 ;
V_73 = F_54 ( sizeof( struct V_73 ) , V_231 ) ;
if ( V_73 == NULL )
return - V_140 ;
V_73 -> V_7 = V_7 ;
V_13 = F_27 ( V_73 , V_7 -> V_90 , V_7 -> V_91 ) ;
if ( V_13 )
goto V_232;
F_39 ( & V_7 -> V_7 , V_73 ) ;
return 0 ;
V_232:
F_55 ( V_73 ) ;
return V_13 ;
}
static void F_56 ( struct V_73 * V_73 )
{
int V_72 ;
V_73 -> V_7 -> V_97 -> V_98 -> V_233 ( V_73 -> V_7 ) ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
struct V_5 * V_6 = & V_73 -> V_6 [ V_72 ] ;
F_57 ( V_73 -> V_165 , V_72 ) ;
F_58 ( & V_6 -> V_1 ) ;
}
F_59 ( V_73 -> V_165 ) ;
F_32 ( V_73 -> V_165 ) ;
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_106 ) ;
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_104 ) ;
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_103 ) ;
V_73 -> V_7 -> V_97 -> V_98 -> V_101 ( V_73 -> V_7 , V_100 ) ;
F_55 ( V_73 ) ;
}
static void F_60 ( struct V_80 * V_234 )
{
F_56 ( F_2 ( & V_234 -> V_7 ) ) ;
}
static int T_5 F_61 ( void )
{
return F_62 ( & V_235 , V_143 , V_145 ) ;
}
static void T_6 F_63 ( void )
{
F_64 ( & V_235 ) ;
}
