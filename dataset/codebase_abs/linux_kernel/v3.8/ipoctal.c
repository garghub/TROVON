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
F_25 ( V_73 -> V_75 + V_76 ) ;
F_25 ( V_73 -> V_75 + V_77 ) ;
return V_78 ;
}
static int F_26 ( struct V_73 * V_73 , unsigned int V_79 ,
unsigned int V_80 )
{
int V_13 ;
int V_72 ;
struct V_81 * V_4 ;
char V_82 [ 20 ] ;
struct V_5 * V_6 ;
struct V_83 * V_84 ;
void T_3 * V_85 ;
union V_86 T_3 * V_87 ;
union V_88 T_3 * V_56 ;
V_73 -> V_62 = V_73 -> V_7 -> V_89 ;
V_84 = & V_73 -> V_7 -> V_84 [ V_90 ] ;
V_85 = F_27 ( & V_73 -> V_7 -> V_7 ,
V_84 -> V_91 , V_84 -> V_92 ) ;
if ( ! V_85 ) {
F_28 ( & V_73 -> V_7 -> V_7 ,
L_1 ,
V_79 , V_80 ) ;
return - V_93 ;
}
V_87 =
(union V_86 T_3 * ) V_85 ;
V_56 =
(union V_88 T_3 * ) V_85 ;
V_84 = & V_73 -> V_7 -> V_84 [ V_94 ] ;
V_73 -> V_75 =
F_27 ( & V_73 -> V_7 -> V_7 ,
V_84 -> V_91 , V_84 -> V_92 ) ;
if ( ! V_73 -> V_75 ) {
F_28 ( & V_73 -> V_7 -> V_7 ,
L_2 ,
V_79 , V_80 ) ;
return - V_93 ;
}
V_84 = & V_73 -> V_7 -> V_84 [ V_95 ] ;
V_73 -> V_96 =
F_27 ( & V_73 -> V_7 -> V_7 ,
V_84 -> V_91 , 0x8000 ) ;
if ( ! V_85 ) {
F_28 ( & V_73 -> V_7 -> V_7 ,
L_3 ,
V_79 , V_80 ) ;
return - V_93 ;
}
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
struct V_5 * V_6 = & V_73 -> V_6 [ V_72 ] ;
V_6 -> V_9 = V_87 + V_72 ;
V_6 -> V_56 = V_56 + ( V_72 >> 1 ) ;
V_6 -> V_64 = & V_73 -> V_97 ;
V_6 -> V_62 = V_73 -> V_62 ;
if ( V_72 & 1 ) {
V_6 -> V_69 = V_98 ;
V_6 -> V_57 = V_99 ;
} else {
V_6 -> V_69 = V_100 ;
V_6 -> V_57 = V_101 ;
}
F_3 ( V_102 | V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_103 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_104 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_105 | V_106 | V_107 ,
& V_6 -> V_9 -> V_10 . V_108 ) ;
F_3 ( 0 , & V_6 -> V_9 -> V_10 . V_108 ) ;
F_3 ( V_109 | V_110 , & V_6 -> V_9 -> V_10 . V_111 ) ;
}
for ( V_72 = 0 ; V_72 < V_112 ; V_72 ++ ) {
F_3 ( V_113 , & V_56 [ V_72 ] . V_10 . V_114 ) ;
F_3 ( V_115 | V_116 | V_117 ,
& V_56 [ V_72 ] . V_10 . V_118 ) ;
F_3 ( V_119 | V_120 | V_121 |
V_122 | V_123 | V_124 ,
& V_56 [ V_72 ] . V_10 . V_125 ) ;
}
V_73 -> V_7 -> V_126 -> V_127 -> V_128 ( V_73 -> V_7 ,
F_24 , V_73 ) ;
F_3 ( 1 , V_73 -> V_96 + 1 ) ;
V_4 = F_29 ( V_74 ) ;
if ( ! V_4 )
return - V_129 ;
V_4 -> V_130 = V_131 ;
V_4 -> V_132 = V_133 ;
sprintf ( V_82 , V_133 L_4 , V_79 , V_80 ) ;
V_4 -> V_82 = V_82 ;
V_4 -> V_134 = 0 ;
V_4 -> V_135 = 0 ;
V_4 -> type = V_136 ;
V_4 -> V_137 = V_138 ;
V_4 -> V_139 = V_140 | V_141 ;
V_4 -> V_142 = V_143 ;
V_4 -> V_142 . V_144 = V_145 | V_146 | V_147 | V_148 | V_149 ;
V_4 -> V_142 . V_150 = 9600 ;
V_4 -> V_142 . V_151 = 9600 ;
F_30 ( V_4 , & V_152 ) ;
V_13 = F_31 ( V_4 ) ;
if ( V_13 ) {
F_28 ( & V_73 -> V_7 -> V_7 , L_5 ) ;
F_32 ( V_4 ) ;
return V_13 ;
}
V_73 -> V_153 = V_4 ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
struct V_154 * V_155 ;
V_6 = & V_73 -> V_6 [ V_72 ] ;
F_33 ( & V_6 -> V_1 ) ;
F_34 ( & V_6 -> V_1 ) ;
V_6 -> V_1 . V_127 = & V_156 ;
F_8 ( & V_6 -> V_18 ) ;
V_6 -> V_27 = 0 ;
F_35 ( & V_6 -> V_61 ) ;
F_36 ( & V_6 -> V_157 ) ;
V_6 -> V_25 = 0 ;
V_6 -> V_26 = 0 ;
V_155 = F_37 ( & V_6 -> V_1 , V_4 , V_72 , NULL ) ;
if ( F_38 ( V_155 ) ) {
F_28 ( & V_73 -> V_7 -> V_7 , L_6 ) ;
F_39 ( & V_6 -> V_1 ) ;
continue;
}
F_40 ( V_155 , V_6 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
return 0 ;
}
static inline int F_41 ( struct V_5 * V_6 ,
const unsigned char * V_158 ,
int V_159 )
{
unsigned long V_139 ;
int V_72 ;
unsigned int * V_25 = & V_6 -> V_25 ;
for ( V_72 = 0 ; V_72 < V_159 ; V_72 ++ ) {
if ( V_72 <= ( V_60 - V_6 -> V_27 ) ) {
F_42 ( & V_6 -> V_157 , V_139 ) ;
V_6 -> V_1 . V_58 [ * V_25 ] = V_158 [ V_72 ] ;
* V_25 = ( * V_25 + 1 ) % V_60 ;
V_6 -> V_27 ++ ;
F_43 ( & V_6 -> V_157 , V_139 ) ;
} else {
break;
}
}
return V_72 ;
}
static int F_44 ( struct V_3 * V_4 ,
const unsigned char * V_158 , int V_159 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
unsigned int V_160 ;
V_160 = F_41 ( V_6 , V_158 , V_159 ) ;
if ( V_6 -> V_62 == V_63 ) {
F_3 ( V_102 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_161 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
F_3 ( V_162 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_45 ( V_6 -> V_61 , * V_6 -> V_64 ) ;
F_3 ( V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
* V_6 -> V_64 = 0 ;
return V_160 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
return V_60 - V_6 -> V_27 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_16 ;
return V_6 -> V_27 ;
}
static void F_48 ( struct V_3 * V_4 ,
struct V_163 * V_164 )
{
unsigned int V_165 ;
unsigned char V_166 = 0 ;
unsigned char V_167 = 0 ;
unsigned char V_111 = 0 ;
struct V_5 * V_6 = V_4 -> V_16 ;
T_4 V_168 ;
V_165 = V_4 -> V_169 . V_144 ;
F_3 ( V_102 | V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_103 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_104 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_46 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_170 , & V_6 -> V_9 -> V_10 . V_11 ) ;
switch ( V_165 & V_171 ) {
case V_172 :
V_166 |= V_173 ;
break;
case V_174 :
V_166 |= V_175 ;
break;
case V_146 :
default:
V_166 |= V_105 ;
V_4 -> V_169 . V_144 = ( V_165 & ~ V_171 ) | V_146 ;
break;
}
if ( V_165 & V_176 )
if ( V_165 & V_177 )
V_166 |= V_178 | V_179 ;
else
V_166 |= V_178 | V_180 ;
else
V_166 |= V_181 ;
V_4 -> V_169 . V_144 &= ~ V_182 ;
if ( V_165 & V_183 )
V_167 |= V_184 ;
else
V_167 |= V_185 ;
switch ( V_6 -> V_62 ) {
case V_186 :
if ( V_165 & V_187 ) {
V_166 |= V_188 ;
V_167 |= V_189 | V_190 ;
} else {
V_166 |= V_191 ;
V_167 |= V_189 | V_192 ;
}
break;
case V_193 :
V_166 |= V_191 ;
V_167 |= V_189 | V_192 ;
break;
case V_63 :
V_166 |= V_191 ;
V_167 |= V_194 | V_192 ;
break;
default:
return;
break;
}
V_168 = F_49 ( V_4 ) ;
F_50 ( & V_4 -> V_169 , V_168 , V_168 ) ;
switch ( V_168 ) {
case 75 :
V_111 |= V_195 | V_196 ;
break;
case 110 :
V_111 |= V_197 | V_198 ;
break;
case 150 :
V_111 |= V_199 | V_200 ;
break;
case 300 :
V_111 |= V_201 | V_202 ;
break;
case 600 :
V_111 |= V_203 | V_204 ;
break;
case 1200 :
V_111 |= V_205 | V_206 ;
break;
case 1800 :
V_111 |= V_207 | V_208 ;
break;
case 2000 :
V_111 |= V_209 | V_210 ;
break;
case 2400 :
V_111 |= V_211 | V_212 ;
break;
case 4800 :
V_111 |= V_213 | V_214 ;
break;
case 9600 :
V_111 |= V_109 | V_110 ;
break;
case 19200 :
V_111 |= V_215 | V_216 ;
break;
case 38400 :
default:
V_111 |= V_217 | V_218 ;
F_50 ( & V_4 -> V_169 , 38400 , 38400 ) ;
break;
}
V_166 |= V_106 ;
V_166 |= V_107 ;
F_3 ( V_166 , & V_6 -> V_9 -> V_10 . V_108 ) ;
F_3 ( V_167 , & V_6 -> V_9 -> V_10 . V_108 ) ;
F_3 ( V_111 , & V_6 -> V_9 -> V_10 . V_111 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
static void F_51 ( struct V_3 * V_4 )
{
unsigned long V_139 ;
struct V_5 * V_6 = V_4 -> V_16 ;
if ( V_6 == NULL )
return;
F_42 ( & V_6 -> V_157 , V_139 ) ;
V_6 -> V_27 = 0 ;
V_6 -> V_25 = 0 ;
V_6 -> V_26 = 0 ;
F_43 ( & V_6 -> V_157 , V_139 ) ;
F_52 ( & V_6 -> V_1 ) ;
F_3 ( V_102 | V_66 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_103 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_104 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_46 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_170 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_53 ( V_219 , & V_6 -> V_1 . V_139 ) ;
F_20 ( & V_6 -> V_1 . V_220 ) ;
}
static int F_54 ( struct V_221 * V_7 )
{
int V_13 ;
struct V_73 * V_73 ;
V_73 = F_55 ( sizeof( struct V_73 ) , V_222 ) ;
if ( V_73 == NULL )
return - V_129 ;
V_73 -> V_7 = V_7 ;
V_13 = F_26 ( V_73 , V_7 -> V_126 -> V_79 , V_7 -> V_80 ) ;
if ( V_13 )
goto V_223;
F_40 ( & V_7 -> V_7 , V_73 ) ;
return 0 ;
V_223:
F_56 ( V_73 ) ;
return V_13 ;
}
static void F_57 ( struct V_73 * V_73 )
{
int V_72 ;
V_73 -> V_7 -> V_126 -> V_127 -> V_224 ( V_73 -> V_7 ) ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
struct V_5 * V_6 = & V_73 -> V_6 [ V_72 ] ;
F_58 ( V_73 -> V_153 , V_72 ) ;
F_59 ( & V_6 -> V_1 ) ;
F_39 ( & V_6 -> V_1 ) ;
}
F_60 ( V_73 -> V_153 ) ;
F_32 ( V_73 -> V_153 ) ;
F_56 ( V_73 ) ;
}
static void F_61 ( struct V_221 * V_225 )
{
F_57 ( F_2 ( & V_225 -> V_7 ) ) ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_226 , V_131 , V_133 ) ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_226 ) ;
}
