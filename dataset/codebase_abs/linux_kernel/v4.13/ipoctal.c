static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
return F_2 ( V_3 , struct V_1 , V_5 [ V_4 ] ) ;
}
static void F_3 ( struct V_2 * V_5 )
{
F_4 ( V_6 | V_7 , & V_5 -> V_8 -> V_9 . V_10 ) ;
V_5 -> V_11 = 0 ;
F_4 ( V_12 , & V_5 -> V_8 -> V_9 . V_10 ) ;
F_4 ( V_13 , & V_5 -> V_8 -> V_9 . V_10 ) ;
F_4 ( V_14 , & V_5 -> V_8 -> V_9 . V_10 ) ;
F_4 ( V_15 , & V_5 -> V_8 -> V_9 . V_10 ) ;
}
static int F_5 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_2 * V_5 ;
V_5 = F_6 ( V_19 -> V_20 ) ;
F_4 ( V_21 , & V_5 -> V_8 -> V_9 . V_10 ) ;
V_5 -> V_11 = 1 ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 , struct V_22 * V_22 )
{
struct V_2 * V_5 = F_6 ( V_19 -> V_20 ) ;
struct V_1 * V_1 = F_1 ( V_5 , V_19 -> V_4 ) ;
int V_23 ;
V_19 -> V_24 = V_5 ;
if ( ! F_8 ( V_1 -> V_20 ) )
return - V_25 ;
V_23 = F_9 ( & V_5 -> V_16 , V_19 , V_22 ) ;
if ( V_23 )
F_10 ( V_1 -> V_20 ) ;
return V_23 ;
}
static void F_11 ( struct V_26 * V_27 )
{
V_27 -> V_28 = 0 ;
V_27 -> V_29 = 0 ;
V_27 -> V_30 = 0 ;
V_27 -> V_31 = 0 ;
V_27 -> V_32 = 0 ;
V_27 -> V_33 = 0 ;
}
static void F_12 ( struct V_2 * V_5 )
{
F_11 ( & V_5 -> V_27 ) ;
V_5 -> V_34 = 0 ;
V_5 -> V_35 = 0 ;
V_5 -> V_36 = 0 ;
}
static void F_13 ( struct V_18 * V_19 , struct V_22 * V_37 )
{
struct V_2 * V_5 = V_19 -> V_24 ;
F_14 ( & V_5 -> V_16 , V_19 , V_37 ) ;
F_12 ( V_5 ) ;
}
static int F_15 ( struct V_18 * V_19 ,
struct V_38 * V_39 )
{
struct V_2 * V_5 = V_19 -> V_24 ;
V_39 -> V_40 = 0 ;
V_39 -> V_41 = 0 ;
V_39 -> V_42 = 0 ;
V_39 -> V_43 = 0 ;
V_39 -> V_29 = V_5 -> V_27 . V_29 ;
V_39 -> V_28 = V_5 -> V_27 . V_28 ;
V_39 -> V_44 = V_5 -> V_27 . V_31 ;
V_39 -> V_45 = V_5 -> V_27 . V_33 ;
V_39 -> V_46 = V_5 -> V_27 . V_30 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_5 , T_1 V_47 )
{
struct V_16 * V_17 = & V_5 -> V_16 ;
unsigned char V_48 ;
unsigned char V_49 ;
T_1 V_50 ;
do {
V_48 = F_17 ( & V_5 -> V_8 -> V_51 . V_52 ) ;
V_49 = V_53 ;
if ( V_47 & V_54 ) {
F_4 ( V_14 , & V_5 -> V_8 -> V_9 . V_10 ) ;
if ( V_47 & V_55 ) {
V_5 -> V_27 . V_32 ++ ;
F_18 ( V_17 , 0 , V_56 ) ;
}
if ( V_47 & V_57 ) {
V_5 -> V_27 . V_33 ++ ;
V_49 = V_58 ;
}
if ( V_47 & V_59 ) {
V_5 -> V_27 . V_31 ++ ;
V_49 = V_60 ;
}
if ( V_47 & V_61 ) {
V_5 -> V_27 . V_30 ++ ;
V_49 = V_62 ;
}
}
F_18 ( V_17 , V_48 , V_49 ) ;
V_50 = F_17 ( & V_5 -> V_63 -> V_51 . V_50 ) ;
V_47 = F_17 ( & V_5 -> V_8 -> V_51 . V_47 ) ;
} while ( V_50 & V_5 -> V_64 );
F_19 ( V_17 ) ;
}
static void F_20 ( struct V_2 * V_5 )
{
unsigned char V_48 ;
unsigned int * V_35 = & V_5 -> V_35 ;
if ( V_5 -> V_36 == 0 )
return;
F_21 ( & V_5 -> V_65 ) ;
V_48 = V_5 -> V_16 . V_66 [ * V_35 ] ;
F_4 ( V_48 , & V_5 -> V_8 -> V_9 . V_67 ) ;
V_5 -> V_27 . V_28 ++ ;
( * V_35 ) ++ ;
* V_35 = * V_35 % V_68 ;
V_5 -> V_36 -- ;
F_22 ( & V_5 -> V_65 ) ;
}
static void F_23 ( struct V_2 * V_5 )
{
T_1 V_50 , V_47 ;
V_50 = F_17 ( & V_5 -> V_63 -> V_51 . V_50 ) ;
V_47 = F_17 ( & V_5 -> V_8 -> V_51 . V_47 ) ;
if ( V_50 & ( V_69 | V_70 ) )
F_4 ( V_71 , & V_5 -> V_8 -> V_9 . V_10 ) ;
if ( ( V_47 & V_72 ) && ( V_5 -> V_36 == 0 ) ) {
F_4 ( V_7 , & V_5 -> V_8 -> V_9 . V_10 ) ;
if ( V_5 -> V_73 == V_74 ) {
F_4 ( V_75 , & V_5 -> V_8 -> V_9 . V_10 ) ;
F_4 ( V_21 , & V_5 -> V_8 -> V_9 . V_10 ) ;
V_5 -> V_11 = 1 ;
}
}
if ( ( V_50 & V_5 -> V_64 ) && ( V_47 & V_76 ) )
F_16 ( V_5 , V_47 ) ;
if ( ( V_50 & V_5 -> V_77 ) && ( V_47 & V_78 ) )
F_20 ( V_5 ) ;
}
static T_2 F_24 ( void * V_79 )
{
unsigned int V_80 ;
struct V_1 * V_1 = (struct V_1 * ) V_79 ;
F_25 ( V_1 -> V_81 + V_82 ) ;
F_25 ( V_1 -> V_81 + V_83 ) ;
for ( V_80 = 0 ; V_80 < V_84 ; V_80 ++ )
F_23 ( & V_1 -> V_5 [ V_80 ] ) ;
return V_85 ;
}
static int F_26 ( struct V_1 * V_1 , unsigned int V_86 ,
unsigned int V_87 )
{
int V_88 ;
int V_80 ;
struct V_89 * V_19 ;
char V_90 [ 20 ] ;
struct V_2 * V_5 ;
struct V_91 * V_92 ;
void T_3 * V_93 ;
union V_94 T_3 * V_95 ;
union V_96 T_3 * V_63 ;
V_1 -> V_73 = V_1 -> V_20 -> V_97 ;
V_92 = & V_1 -> V_20 -> V_92 [ V_98 ] ;
V_93 = F_27 ( & V_1 -> V_20 -> V_20 ,
V_92 -> V_99 , V_92 -> V_100 ) ;
if ( ! V_93 ) {
F_28 ( & V_1 -> V_20 -> V_20 ,
L_1 ,
V_86 , V_87 ) ;
return - V_101 ;
}
V_95 =
(union V_94 T_3 * ) V_93 ;
V_63 =
(union V_96 T_3 * ) V_93 ;
V_92 = & V_1 -> V_20 -> V_92 [ V_102 ] ;
V_1 -> V_81 =
F_27 ( & V_1 -> V_20 -> V_20 ,
V_92 -> V_99 , V_92 -> V_100 ) ;
if ( ! V_1 -> V_81 ) {
F_28 ( & V_1 -> V_20 -> V_20 ,
L_2 ,
V_86 , V_87 ) ;
return - V_101 ;
}
V_92 = & V_1 -> V_20 -> V_92 [ V_103 ] ;
V_1 -> V_104 =
F_27 ( & V_1 -> V_20 -> V_20 ,
V_92 -> V_99 , 0x8000 ) ;
if ( ! V_1 -> V_104 ) {
F_28 ( & V_1 -> V_20 -> V_20 ,
L_3 ,
V_86 , V_87 ) ;
return - V_101 ;
}
for ( V_80 = 0 ; V_80 < V_84 ; V_80 ++ ) {
struct V_2 * V_5 = & V_1 -> V_5 [ V_80 ] ;
V_5 -> V_8 = V_95 + V_80 ;
V_5 -> V_63 = V_63 + ( V_80 >> 1 ) ;
V_5 -> V_73 = V_1 -> V_73 ;
if ( V_80 & 1 ) {
V_5 -> V_77 = V_105 ;
V_5 -> V_64 = V_106 ;
} else {
V_5 -> V_77 = V_107 ;
V_5 -> V_64 = V_108 ;
}
F_3 ( V_5 ) ;
F_4 ( V_109 | V_110 | V_111 ,
& V_5 -> V_8 -> V_9 . V_112 ) ;
F_4 ( 0 , & V_5 -> V_8 -> V_9 . V_112 ) ;
F_4 ( V_113 | V_114 , & V_5 -> V_8 -> V_9 . V_115 ) ;
}
for ( V_80 = 0 ; V_80 < V_116 ; V_80 ++ ) {
F_4 ( V_117 , & V_63 [ V_80 ] . V_9 . V_118 ) ;
F_4 ( V_119 | V_120 | V_121 ,
& V_63 [ V_80 ] . V_9 . V_122 ) ;
F_4 ( V_123 | V_124 | V_69 |
V_125 | V_126 | V_70 ,
& V_63 [ V_80 ] . V_9 . V_127 ) ;
}
F_4 ( 1 , V_1 -> V_104 + 1 ) ;
V_19 = F_29 ( V_84 ) ;
if ( ! V_19 )
return - V_128 ;
V_19 -> V_129 = V_130 ;
V_19 -> V_131 = V_132 ;
sprintf ( V_90 , V_132 L_4 , V_86 , V_87 ) ;
V_19 -> V_90 = V_90 ;
V_19 -> V_133 = 0 ;
V_19 -> V_134 = 0 ;
V_19 -> type = V_135 ;
V_19 -> V_136 = V_137 ;
V_19 -> V_138 = V_139 | V_140 ;
V_19 -> V_141 = V_142 ;
V_19 -> V_141 . V_143 = V_144 | V_145 | V_146 | V_147 | V_148 ;
V_19 -> V_141 . V_149 = 9600 ;
V_19 -> V_141 . V_150 = 9600 ;
F_30 ( V_19 , & V_151 ) ;
V_88 = F_31 ( V_19 ) ;
if ( V_88 ) {
F_28 ( & V_1 -> V_20 -> V_20 , L_5 ) ;
F_32 ( V_19 ) ;
return V_88 ;
}
V_1 -> V_152 = V_19 ;
for ( V_80 = 0 ; V_80 < V_84 ; V_80 ++ ) {
struct V_153 * V_154 ;
V_5 = & V_1 -> V_5 [ V_80 ] ;
F_33 ( & V_5 -> V_16 ) ;
F_34 ( & V_5 -> V_16 ) ;
V_5 -> V_16 . V_155 = & V_156 ;
F_11 ( & V_5 -> V_27 ) ;
V_5 -> V_36 = 0 ;
F_35 ( & V_5 -> V_65 ) ;
V_5 -> V_34 = 0 ;
V_5 -> V_35 = 0 ;
V_154 = F_36 ( & V_5 -> V_16 , V_19 , V_80 , NULL ) ;
if ( F_37 ( V_154 ) ) {
F_28 ( & V_1 -> V_20 -> V_20 , L_6 ) ;
F_38 ( & V_5 -> V_16 ) ;
continue;
}
F_39 ( V_154 , V_5 ) ;
}
V_1 -> V_20 -> V_157 -> V_155 -> V_158 ( V_1 -> V_20 ,
F_24 , V_1 ) ;
return 0 ;
}
static inline int F_40 ( struct V_2 * V_5 ,
const unsigned char * V_159 ,
int V_160 )
{
unsigned long V_138 ;
int V_80 ;
unsigned int * V_34 = & V_5 -> V_34 ;
for ( V_80 = 0 ; V_80 < V_160 ; V_80 ++ ) {
if ( V_80 <= ( V_68 - V_5 -> V_36 ) ) {
F_41 ( & V_5 -> V_65 , V_138 ) ;
V_5 -> V_16 . V_66 [ * V_34 ] = V_159 [ V_80 ] ;
* V_34 = ( * V_34 + 1 ) % V_68 ;
V_5 -> V_36 ++ ;
F_42 ( & V_5 -> V_65 , V_138 ) ;
} else {
break;
}
}
return V_80 ;
}
static int F_43 ( struct V_18 * V_19 ,
const unsigned char * V_159 , int V_160 )
{
struct V_2 * V_5 = V_19 -> V_24 ;
unsigned int V_161 ;
V_161 = F_40 ( V_5 , V_159 , V_160 ) ;
if ( V_5 -> V_73 == V_74 ) {
F_4 ( V_6 , & V_5 -> V_8 -> V_9 . V_10 ) ;
V_5 -> V_11 = 0 ;
F_4 ( V_162 , & V_5 -> V_8 -> V_9 . V_10 ) ;
}
F_4 ( V_163 , & V_5 -> V_8 -> V_9 . V_10 ) ;
return V_161 ;
}
static int F_44 ( struct V_18 * V_19 )
{
struct V_2 * V_5 = V_19 -> V_24 ;
return V_68 - V_5 -> V_36 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_2 * V_5 = V_19 -> V_24 ;
return V_5 -> V_36 ;
}
static void F_46 ( struct V_18 * V_19 ,
struct V_164 * V_165 )
{
unsigned int V_166 ;
unsigned char V_167 = 0 ;
unsigned char V_168 = 0 ;
unsigned char V_115 = 0 ;
struct V_2 * V_5 = V_19 -> V_24 ;
T_4 V_169 ;
V_166 = V_19 -> V_170 . V_143 ;
F_3 ( V_5 ) ;
switch ( V_166 & V_171 ) {
case V_172 :
V_167 |= V_173 ;
break;
case V_174 :
V_167 |= V_175 ;
break;
case V_145 :
default:
V_167 |= V_109 ;
V_19 -> V_170 . V_143 = ( V_166 & ~ V_171 ) | V_145 ;
break;
}
if ( V_166 & V_176 )
if ( V_166 & V_177 )
V_167 |= V_178 | V_179 ;
else
V_167 |= V_178 | V_180 ;
else
V_167 |= V_181 ;
V_19 -> V_170 . V_143 &= ~ V_182 ;
if ( V_166 & V_183 )
V_168 |= V_184 ;
else
V_168 |= V_185 ;
switch ( V_5 -> V_73 ) {
case V_186 :
if ( V_166 & V_187 ) {
V_167 |= V_188 ;
V_168 |= V_189 | V_190 ;
} else {
V_167 |= V_191 ;
V_168 |= V_189 | V_192 ;
}
break;
case V_193 :
V_167 |= V_191 ;
V_168 |= V_189 | V_192 ;
break;
case V_74 :
V_167 |= V_191 ;
V_168 |= V_194 | V_192 ;
break;
default:
return;
break;
}
V_169 = F_47 ( V_19 ) ;
F_48 ( & V_19 -> V_170 , V_169 , V_169 ) ;
switch ( V_169 ) {
case 75 :
V_115 |= V_195 | V_196 ;
break;
case 110 :
V_115 |= V_197 | V_198 ;
break;
case 150 :
V_115 |= V_199 | V_200 ;
break;
case 300 :
V_115 |= V_201 | V_202 ;
break;
case 600 :
V_115 |= V_203 | V_204 ;
break;
case 1200 :
V_115 |= V_205 | V_206 ;
break;
case 1800 :
V_115 |= V_207 | V_208 ;
break;
case 2000 :
V_115 |= V_209 | V_210 ;
break;
case 2400 :
V_115 |= V_211 | V_212 ;
break;
case 4800 :
V_115 |= V_213 | V_214 ;
break;
case 9600 :
V_115 |= V_113 | V_114 ;
break;
case 19200 :
V_115 |= V_215 | V_216 ;
break;
case 38400 :
default:
V_115 |= V_217 | V_218 ;
F_48 ( & V_19 -> V_170 , 38400 , 38400 ) ;
break;
}
V_167 |= V_110 ;
V_167 |= V_111 ;
F_4 ( V_167 , & V_5 -> V_8 -> V_9 . V_112 ) ;
F_4 ( V_168 , & V_5 -> V_8 -> V_9 . V_112 ) ;
F_4 ( V_115 , & V_5 -> V_8 -> V_9 . V_115 ) ;
if ( V_5 -> V_11 )
F_4 ( V_21 , & V_5 -> V_8 -> V_9 . V_10 ) ;
}
static void F_49 ( struct V_18 * V_19 )
{
unsigned long V_138 ;
struct V_2 * V_5 = V_19 -> V_24 ;
if ( V_5 == NULL )
return;
F_41 ( & V_5 -> V_65 , V_138 ) ;
V_5 -> V_36 = 0 ;
V_5 -> V_34 = 0 ;
V_5 -> V_35 = 0 ;
F_42 ( & V_5 -> V_65 , V_138 ) ;
F_50 ( & V_5 -> V_16 ) ;
F_3 ( V_5 ) ;
F_51 ( & V_5 -> V_16 , 0 ) ;
F_52 ( & V_5 -> V_16 . V_219 ) ;
}
static void F_53 ( struct V_18 * V_19 )
{
struct V_2 * V_5 = V_19 -> V_24 ;
if ( V_5 == NULL )
return;
F_3 ( V_5 ) ;
F_51 ( & V_5 -> V_16 , 0 ) ;
}
static void F_54 ( struct V_18 * V_19 )
{
struct V_2 * V_5 = V_19 -> V_24 ;
struct V_1 * V_1 = F_1 ( V_5 , V_19 -> V_4 ) ;
F_10 ( V_1 -> V_20 ) ;
}
static int F_55 ( struct V_220 * V_20 )
{
int V_88 ;
struct V_1 * V_1 ;
V_1 = F_56 ( sizeof( struct V_1 ) , V_221 ) ;
if ( V_1 == NULL )
return - V_128 ;
V_1 -> V_20 = V_20 ;
V_88 = F_26 ( V_1 , V_20 -> V_157 -> V_86 , V_20 -> V_87 ) ;
if ( V_88 )
goto V_222;
F_39 ( & V_20 -> V_20 , V_1 ) ;
return 0 ;
V_222:
F_57 ( V_1 ) ;
return V_88 ;
}
static void F_58 ( struct V_1 * V_1 )
{
int V_80 ;
V_1 -> V_20 -> V_157 -> V_155 -> V_223 ( V_1 -> V_20 ) ;
for ( V_80 = 0 ; V_80 < V_84 ; V_80 ++ ) {
struct V_2 * V_5 = & V_1 -> V_5 [ V_80 ] ;
F_59 ( V_1 -> V_152 , V_80 ) ;
F_60 ( & V_5 -> V_16 ) ;
F_38 ( & V_5 -> V_16 ) ;
}
F_61 ( V_1 -> V_152 ) ;
F_32 ( V_1 -> V_152 ) ;
F_57 ( V_1 ) ;
}
static void F_62 ( struct V_220 * V_224 )
{
F_58 ( F_6 ( & V_224 -> V_20 ) ) ;
}
static int T_5 F_63 ( void )
{
return F_64 ( & V_225 , V_130 , V_132 ) ;
}
static void T_6 F_65 ( void )
{
F_66 ( & V_225 ) ;
}
