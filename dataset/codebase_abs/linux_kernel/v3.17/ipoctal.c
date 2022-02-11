static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 -> V_7 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_12 = 1 ;
return 0 ;
}
static int F_4 ( struct V_3 * V_4 , struct V_13 * V_13 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 -> V_7 ) ;
V_4 -> V_14 = V_6 ;
return F_5 ( & V_6 -> V_1 , V_4 , V_13 ) ;
}
static void F_6 ( struct V_15 * V_16 )
{
V_16 -> V_17 = 0 ;
V_16 -> V_18 = 0 ;
V_16 -> V_19 = 0 ;
V_16 -> V_20 = 0 ;
V_16 -> V_21 = 0 ;
V_16 -> V_22 = 0 ;
}
static void F_7 ( struct V_5 * V_6 )
{
F_6 ( & V_6 -> V_16 ) ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_6 -> V_25 = 0 ;
}
static void F_8 ( struct V_3 * V_4 , struct V_13 * V_26 )
{
struct V_5 * V_6 = V_4 -> V_14 ;
F_9 ( & V_6 -> V_1 , V_4 , V_26 ) ;
F_7 ( V_6 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = V_4 -> V_14 ;
V_28 -> V_29 = 0 ;
V_28 -> V_30 = 0 ;
V_28 -> V_31 = 0 ;
V_28 -> V_32 = 0 ;
V_28 -> V_18 = V_6 -> V_16 . V_18 ;
V_28 -> V_17 = V_6 -> V_16 . V_17 ;
V_28 -> V_33 = V_6 -> V_16 . V_20 ;
V_28 -> V_34 = V_6 -> V_16 . V_22 ;
V_28 -> V_35 = V_6 -> V_16 . V_19 ;
return 0 ;
}
static void F_11 ( struct V_5 * V_6 , T_1 V_36 )
{
struct V_1 * V_2 = & V_6 -> V_1 ;
unsigned char V_37 ;
unsigned char V_38 ;
T_1 V_39 ;
do {
V_37 = F_12 ( & V_6 -> V_9 -> V_40 . V_41 ) ;
V_38 = V_42 ;
if ( V_36 & V_43 ) {
F_3 ( V_44 , & V_6 -> V_9 -> V_10 . V_11 ) ;
if ( V_36 & V_45 ) {
V_6 -> V_16 . V_21 ++ ;
F_13 ( V_2 , 0 , V_46 ) ;
}
if ( V_36 & V_47 ) {
V_6 -> V_16 . V_22 ++ ;
V_38 = V_48 ;
}
if ( V_36 & V_49 ) {
V_6 -> V_16 . V_20 ++ ;
V_38 = V_50 ;
}
if ( V_36 & V_51 ) {
F_3 ( V_52 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_16 . V_19 ++ ;
V_38 = V_53 ;
}
}
F_13 ( V_2 , V_37 , V_38 ) ;
V_39 = F_12 ( & V_6 -> V_54 -> V_40 . V_39 ) ;
V_36 = F_12 ( & V_6 -> V_9 -> V_40 . V_36 ) ;
} while ( V_39 & V_6 -> V_55 );
F_14 ( V_2 ) ;
}
static void F_15 ( struct V_5 * V_6 )
{
unsigned char V_37 ;
unsigned int * V_24 = & V_6 -> V_24 ;
if ( V_6 -> V_25 == 0 )
return;
F_16 ( & V_6 -> V_56 ) ;
V_37 = V_6 -> V_1 . V_57 [ * V_24 ] ;
F_3 ( V_37 , & V_6 -> V_9 -> V_10 . V_58 ) ;
V_6 -> V_16 . V_17 ++ ;
( * V_24 ) ++ ;
* V_24 = * V_24 % V_59 ;
V_6 -> V_25 -- ;
F_17 ( & V_6 -> V_56 ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
T_1 V_39 , V_36 ;
V_39 = F_12 ( & V_6 -> V_54 -> V_40 . V_39 ) ;
V_36 = F_12 ( & V_6 -> V_9 -> V_40 . V_36 ) ;
if ( ( V_36 & V_60 ) && ( V_6 -> V_25 == 0 ) ) {
F_3 ( V_61 , & V_6 -> V_9 -> V_10 . V_11 ) ;
if ( V_6 -> V_62 == V_63 ) {
F_3 ( V_64 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_12 = 1 ;
}
}
if ( ( V_39 & V_6 -> V_55 ) && ( V_36 & V_65 ) )
F_11 ( V_6 , V_36 ) ;
if ( ( V_39 & V_6 -> V_66 ) && ( V_36 & V_67 ) )
F_15 ( V_6 ) ;
}
static T_2 F_19 ( void * V_68 )
{
unsigned int V_69 ;
struct V_70 * V_70 = (struct V_70 * ) V_68 ;
F_20 ( V_70 -> V_71 + V_72 ) ;
F_20 ( V_70 -> V_71 + V_73 ) ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ )
F_18 ( & V_70 -> V_6 [ V_69 ] ) ;
return V_75 ;
}
static int F_21 ( struct V_70 * V_70 , unsigned int V_76 ,
unsigned int V_77 )
{
int V_78 ;
int V_69 ;
struct V_79 * V_4 ;
char V_80 [ 20 ] ;
struct V_5 * V_6 ;
struct V_81 * V_82 ;
void T_3 * V_83 ;
union V_84 T_3 * V_85 ;
union V_86 T_3 * V_54 ;
V_70 -> V_62 = V_70 -> V_7 -> V_87 ;
V_82 = & V_70 -> V_7 -> V_82 [ V_88 ] ;
V_83 = F_22 ( & V_70 -> V_7 -> V_7 ,
V_82 -> V_89 , V_82 -> V_90 ) ;
if ( ! V_83 ) {
F_23 ( & V_70 -> V_7 -> V_7 ,
L_1 ,
V_76 , V_77 ) ;
return - V_91 ;
}
V_85 =
(union V_84 T_3 * ) V_83 ;
V_54 =
(union V_86 T_3 * ) V_83 ;
V_82 = & V_70 -> V_7 -> V_82 [ V_92 ] ;
V_70 -> V_71 =
F_22 ( & V_70 -> V_7 -> V_7 ,
V_82 -> V_89 , V_82 -> V_90 ) ;
if ( ! V_70 -> V_71 ) {
F_23 ( & V_70 -> V_7 -> V_7 ,
L_2 ,
V_76 , V_77 ) ;
return - V_91 ;
}
V_82 = & V_70 -> V_7 -> V_82 [ V_93 ] ;
V_70 -> V_94 =
F_22 ( & V_70 -> V_7 -> V_7 ,
V_82 -> V_89 , 0x8000 ) ;
if ( ! V_70 -> V_94 ) {
F_23 ( & V_70 -> V_7 -> V_7 ,
L_3 ,
V_76 , V_77 ) ;
return - V_91 ;
}
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_5 * V_6 = & V_70 -> V_6 [ V_69 ] ;
V_6 -> V_9 = V_85 + V_69 ;
V_6 -> V_54 = V_54 + ( V_69 >> 1 ) ;
V_6 -> V_62 = V_70 -> V_62 ;
if ( V_69 & 1 ) {
V_6 -> V_66 = V_95 ;
V_6 -> V_55 = V_96 ;
} else {
V_6 -> V_66 = V_97 ;
V_6 -> V_55 = V_98 ;
}
F_3 ( V_99 | V_61 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_12 = 0 ;
F_3 ( V_100 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_101 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_102 | V_103 | V_104 ,
& V_6 -> V_9 -> V_10 . V_105 ) ;
F_3 ( 0 , & V_6 -> V_9 -> V_10 . V_105 ) ;
F_3 ( V_106 | V_107 , & V_6 -> V_9 -> V_10 . V_108 ) ;
}
for ( V_69 = 0 ; V_69 < V_109 ; V_69 ++ ) {
F_3 ( V_110 , & V_54 [ V_69 ] . V_10 . V_111 ) ;
F_3 ( V_112 | V_113 | V_114 ,
& V_54 [ V_69 ] . V_10 . V_115 ) ;
F_3 ( V_116 | V_117 | V_118 |
V_119 | V_120 | V_121 ,
& V_54 [ V_69 ] . V_10 . V_122 ) ;
}
F_3 ( 1 , V_70 -> V_94 + 1 ) ;
V_4 = F_24 ( V_74 ) ;
if ( ! V_4 )
return - V_123 ;
V_4 -> V_124 = V_125 ;
V_4 -> V_126 = V_127 ;
sprintf ( V_80 , V_127 L_4 , V_76 , V_77 ) ;
V_4 -> V_80 = V_80 ;
V_4 -> V_128 = 0 ;
V_4 -> V_129 = 0 ;
V_4 -> type = V_130 ;
V_4 -> V_131 = V_132 ;
V_4 -> V_133 = V_134 | V_135 ;
V_4 -> V_136 = V_137 ;
V_4 -> V_136 . V_138 = V_139 | V_140 | V_141 | V_142 | V_143 ;
V_4 -> V_136 . V_144 = 9600 ;
V_4 -> V_136 . V_145 = 9600 ;
F_25 ( V_4 , & V_146 ) ;
V_78 = F_26 ( V_4 ) ;
if ( V_78 ) {
F_23 ( & V_70 -> V_7 -> V_7 , L_5 ) ;
F_27 ( V_4 ) ;
return V_78 ;
}
V_70 -> V_147 = V_4 ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_148 * V_149 ;
V_6 = & V_70 -> V_6 [ V_69 ] ;
F_28 ( & V_6 -> V_1 ) ;
F_29 ( & V_6 -> V_1 ) ;
V_6 -> V_1 . V_150 = & V_151 ;
F_6 ( & V_6 -> V_16 ) ;
V_6 -> V_25 = 0 ;
F_30 ( & V_6 -> V_56 ) ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_149 = F_31 ( & V_6 -> V_1 , V_4 , V_69 , NULL ) ;
if ( F_32 ( V_149 ) ) {
F_23 ( & V_70 -> V_7 -> V_7 , L_6 ) ;
F_33 ( & V_6 -> V_1 ) ;
continue;
}
F_34 ( V_149 , V_6 ) ;
}
V_70 -> V_7 -> V_152 -> V_150 -> V_153 ( V_70 -> V_7 ,
F_19 , V_70 ) ;
return 0 ;
}
static inline int F_35 ( struct V_5 * V_6 ,
const unsigned char * V_154 ,
int V_155 )
{
unsigned long V_133 ;
int V_69 ;
unsigned int * V_23 = & V_6 -> V_23 ;
for ( V_69 = 0 ; V_69 < V_155 ; V_69 ++ ) {
if ( V_69 <= ( V_59 - V_6 -> V_25 ) ) {
F_36 ( & V_6 -> V_56 , V_133 ) ;
V_6 -> V_1 . V_57 [ * V_23 ] = V_154 [ V_69 ] ;
* V_23 = ( * V_23 + 1 ) % V_59 ;
V_6 -> V_25 ++ ;
F_37 ( & V_6 -> V_56 , V_133 ) ;
} else {
break;
}
}
return V_69 ;
}
static int F_38 ( struct V_3 * V_4 ,
const unsigned char * V_154 , int V_155 )
{
struct V_5 * V_6 = V_4 -> V_14 ;
unsigned int V_156 ;
V_156 = F_35 ( V_6 , V_154 , V_155 ) ;
if ( V_6 -> V_62 == V_63 ) {
F_3 ( V_99 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_12 = 0 ;
F_3 ( V_157 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
F_3 ( V_158 , & V_6 -> V_9 -> V_10 . V_11 ) ;
return V_156 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_14 ;
return V_59 - V_6 -> V_25 ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_14 ;
return V_6 -> V_25 ;
}
static void F_41 ( struct V_3 * V_4 ,
struct V_159 * V_160 )
{
unsigned int V_161 ;
unsigned char V_162 = 0 ;
unsigned char V_163 = 0 ;
unsigned char V_108 = 0 ;
struct V_5 * V_6 = V_4 -> V_14 ;
T_4 V_164 ;
V_161 = V_4 -> V_165 . V_138 ;
F_3 ( V_99 | V_61 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_100 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_101 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_44 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_166 , & V_6 -> V_9 -> V_10 . V_11 ) ;
switch ( V_161 & V_167 ) {
case V_168 :
V_162 |= V_169 ;
break;
case V_170 :
V_162 |= V_171 ;
break;
case V_140 :
default:
V_162 |= V_102 ;
V_4 -> V_165 . V_138 = ( V_161 & ~ V_167 ) | V_140 ;
break;
}
if ( V_161 & V_172 )
if ( V_161 & V_173 )
V_162 |= V_174 | V_175 ;
else
V_162 |= V_174 | V_176 ;
else
V_162 |= V_177 ;
V_4 -> V_165 . V_138 &= ~ V_178 ;
if ( V_161 & V_179 )
V_163 |= V_180 ;
else
V_163 |= V_181 ;
switch ( V_6 -> V_62 ) {
case V_182 :
if ( V_161 & V_183 ) {
V_162 |= V_184 ;
V_163 |= V_185 | V_186 ;
} else {
V_162 |= V_187 ;
V_163 |= V_185 | V_188 ;
}
break;
case V_189 :
V_162 |= V_187 ;
V_163 |= V_185 | V_188 ;
break;
case V_63 :
V_162 |= V_187 ;
V_163 |= V_190 | V_188 ;
break;
default:
return;
break;
}
V_164 = F_42 ( V_4 ) ;
F_43 ( & V_4 -> V_165 , V_164 , V_164 ) ;
switch ( V_164 ) {
case 75 :
V_108 |= V_191 | V_192 ;
break;
case 110 :
V_108 |= V_193 | V_194 ;
break;
case 150 :
V_108 |= V_195 | V_196 ;
break;
case 300 :
V_108 |= V_197 | V_198 ;
break;
case 600 :
V_108 |= V_199 | V_200 ;
break;
case 1200 :
V_108 |= V_201 | V_202 ;
break;
case 1800 :
V_108 |= V_203 | V_204 ;
break;
case 2000 :
V_108 |= V_205 | V_206 ;
break;
case 2400 :
V_108 |= V_207 | V_208 ;
break;
case 4800 :
V_108 |= V_209 | V_210 ;
break;
case 9600 :
V_108 |= V_106 | V_107 ;
break;
case 19200 :
V_108 |= V_211 | V_212 ;
break;
case 38400 :
default:
V_108 |= V_213 | V_214 ;
F_43 ( & V_4 -> V_165 , 38400 , 38400 ) ;
break;
}
V_162 |= V_103 ;
V_162 |= V_104 ;
F_3 ( V_162 , & V_6 -> V_9 -> V_10 . V_105 ) ;
F_3 ( V_163 , & V_6 -> V_9 -> V_10 . V_105 ) ;
F_3 ( V_108 , & V_6 -> V_9 -> V_10 . V_108 ) ;
if ( V_6 -> V_12 )
F_3 ( V_8 , & V_6 -> V_9 -> V_10 . V_11 ) ;
}
static void F_44 ( struct V_3 * V_4 )
{
unsigned long V_133 ;
struct V_5 * V_6 = V_4 -> V_14 ;
if ( V_6 == NULL )
return;
F_36 ( & V_6 -> V_56 , V_133 ) ;
V_6 -> V_25 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
F_37 ( & V_6 -> V_56 , V_133 ) ;
F_45 ( & V_6 -> V_1 ) ;
F_3 ( V_99 | V_61 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_12 = 0 ;
F_3 ( V_100 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_101 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_44 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_166 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_46 ( V_215 , & V_6 -> V_1 . V_133 ) ;
F_47 ( & V_6 -> V_1 . V_216 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_14 ;
if ( V_6 == NULL )
return;
F_3 ( V_99 | V_61 , & V_6 -> V_9 -> V_10 . V_11 ) ;
V_6 -> V_12 = 0 ;
F_3 ( V_100 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_101 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_44 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_3 ( V_166 , & V_6 -> V_9 -> V_10 . V_11 ) ;
F_46 ( V_215 , & V_6 -> V_1 . V_133 ) ;
}
static int F_49 ( struct V_217 * V_7 )
{
int V_78 ;
struct V_70 * V_70 ;
V_70 = F_50 ( sizeof( struct V_70 ) , V_218 ) ;
if ( V_70 == NULL )
return - V_123 ;
V_70 -> V_7 = V_7 ;
V_78 = F_21 ( V_70 , V_7 -> V_152 -> V_76 , V_7 -> V_77 ) ;
if ( V_78 )
goto V_219;
F_34 ( & V_7 -> V_7 , V_70 ) ;
return 0 ;
V_219:
F_51 ( V_70 ) ;
return V_78 ;
}
static void F_52 ( struct V_70 * V_70 )
{
int V_69 ;
V_70 -> V_7 -> V_152 -> V_150 -> V_220 ( V_70 -> V_7 ) ;
for ( V_69 = 0 ; V_69 < V_74 ; V_69 ++ ) {
struct V_5 * V_6 = & V_70 -> V_6 [ V_69 ] ;
F_53 ( V_70 -> V_147 , V_69 ) ;
F_54 ( & V_6 -> V_1 ) ;
F_33 ( & V_6 -> V_1 ) ;
}
F_55 ( V_70 -> V_147 ) ;
F_27 ( V_70 -> V_147 ) ;
F_51 ( V_70 ) ;
}
static void F_56 ( struct V_217 * V_221 )
{
F_52 ( F_2 ( & V_221 -> V_7 ) ) ;
}
static int T_5 F_57 ( void )
{
return F_58 ( & V_222 , V_125 , V_127 ) ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_222 ) ;
}
