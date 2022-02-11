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
F_7 ( V_16 -> V_6 , L_1 ,
V_16 -> V_18 -> V_19 ) ;
return - V_25 ;
}
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_30 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_31 * V_31 )
{
int V_23 = V_16 -> V_24 ;
int V_32 ;
struct V_1 * V_1 ;
V_1 = F_4 ( V_16 ) ;
if ( V_1 == NULL ) {
F_7 ( V_16 -> V_6 , L_1 ,
V_16 -> V_18 -> V_19 ) ;
return - V_25 ;
}
if ( F_9 ( & V_1 -> V_33 [ V_23 ] ) )
return - V_34 ;
V_16 -> V_35 = V_1 ;
V_32 = F_10 ( & V_1 -> V_21 [ V_23 ] , V_16 , V_31 ) ;
if ( V_32 )
return V_32 ;
F_11 ( & V_1 -> V_33 [ V_23 ] ) ;
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
struct V_1 * V_1 = V_16 -> V_35 ;
if ( V_1 == NULL )
return;
F_12 ( & V_1 -> V_44 [ V_23 ] ) ;
V_1 -> V_45 [ V_23 ] = 0 ;
V_1 -> V_46 [ V_23 ] = 0 ;
V_1 -> V_47 [ V_23 ] = 0 ;
}
static void F_14 ( struct V_15 * V_16 , struct V_31 * V_48 )
{
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_35 ;
F_15 ( & V_1 -> V_21 [ V_23 ] , V_16 , V_48 ) ;
if ( F_16 ( & V_1 -> V_33 [ V_23 ] ) )
F_13 ( V_16 ) ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = V_16 -> V_35 ;
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
if ( ! F_9 ( & V_1 -> V_33 [ V_23 ] ) )
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
V_1 -> V_44 [ V_23 ] . V_42 ++ ;
F_21 ( V_16 , 0 , V_85 ) ;
}
if ( V_61 & V_86 ) {
V_1 -> V_44 [ V_23 ] . V_43 ++ ;
V_64 = V_87 ;
}
if ( V_61 & V_88 ) {
V_1 -> V_44 [ V_23 ] . V_41 ++ ;
V_64 = V_89 ;
}
if ( V_61 & V_90 ) {
V_1 -> V_44 [ V_23 ] . V_40 ++ ;
V_64 = V_91 ;
}
}
F_21 ( V_16 , V_3 , V_64 ) ;
}
if ( V_62 && ( V_61 & V_92 ) ) {
unsigned int * V_46 =
& V_1 -> V_46 [ V_23 ] ;
if ( V_1 -> V_47 [ V_23 ] <= 0 ) {
V_1 -> V_47 [ V_23 ] = 0 ;
continue;
}
V_3 = V_1 -> V_21 [ V_23 ] . V_93 [ * V_46 ] ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_94 ,
V_3 ) ;
V_1 -> V_44 [ V_23 ] . V_38 ++ ;
V_1 -> V_95 [ V_23 ] ++ ;
( * V_46 ) ++ ;
* V_46 = * V_46 % V_96 ;
V_1 -> V_47 [ V_23 ] -- ;
if ( ( V_1 -> V_47 [ V_23 ] == 0 ) &&
( F_22 ( & V_1 -> V_78 [ V_23 ] ) ) ) {
if ( V_1 -> V_72 != V_73 ) {
V_1 -> V_77 = 1 ;
F_20 ( & V_1 -> V_78 [ V_23 ] ) ;
}
}
}
F_23 ( V_16 ) ;
F_24 ( V_16 ) ;
}
return V_97 ;
}
static int F_25 ( struct V_98 * V_6 , unsigned char * V_99 )
{
unsigned char V_100 ;
unsigned char V_72 ;
V_6 -> V_9 -> V_10 -> V_14 ( V_6 , V_101 ,
V_102 , & V_100 ) ;
if ( V_100 != V_103 )
return - V_25 ;
V_6 -> V_9 -> V_10 -> V_14 ( V_6 , V_101 ,
V_104 , ( unsigned char * ) & V_72 ) ;
switch ( V_72 ) {
case V_105 :
case V_106 :
case V_73 :
* V_99 = V_72 ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , unsigned int V_107 ,
unsigned int V_108 , unsigned int V_109 )
{
int V_32 = 0 ;
int V_110 ;
struct V_111 * V_16 ;
char V_112 [ 20 ] ;
unsigned char V_72 ;
V_32 = V_1 -> V_6 -> V_9 -> V_10 -> V_113 ( V_1 -> V_6 , 0 ,
V_101 ) ;
if ( V_32 ) {
F_7 ( & V_1 -> V_6 -> V_6 ,
L_2 ,
V_107 , V_108 ) ;
return V_32 ;
}
V_32 = F_25 ( V_1 -> V_6 , & V_72 ) ;
if ( V_32 ) {
V_1 -> V_6 -> V_9 -> V_10 -> V_114 ( V_1 -> V_6 ,
V_101 ) ;
goto V_115;
}
V_1 -> V_72 = V_72 ;
V_32 = V_1 -> V_6 -> V_9 -> V_10 -> V_113 ( V_1 -> V_6 , 0 ,
V_12 ) ;
if ( V_32 ) {
F_7 ( & V_1 -> V_6 -> V_6 ,
L_3 ,
V_107 , V_108 ) ;
goto V_115;
}
V_32 = V_1 -> V_6 -> V_9 -> V_10 -> V_113 ( V_1 -> V_6 ,
0x8000 , V_116 ) ;
if ( V_32 ) {
F_7 ( & V_1 -> V_6 -> V_6 ,
L_4 ,
V_107 , V_108 ) ;
goto V_117;
}
V_1 -> V_26 =
(struct V_118 * ) V_1 -> V_6 -> V_7 . V_8 ;
V_1 -> V_66 =
(struct V_119 * ) V_1 -> V_6 -> V_7 . V_8 ;
for ( V_110 = 0 ; V_110 < V_65 ; V_110 ++ ) {
F_1 ( V_1 , & V_1 -> V_26 [ V_110 ] . V_27 . V_28 . V_29 ,
V_120 | V_75 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_110 ] . V_27 . V_28 . V_29 ,
V_121 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_110 ] . V_27 . V_28 . V_29 ,
V_122 ) ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_110 ] . V_27 . V_28 . V_123 ,
V_124 | V_125 |
V_126 ) ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_110 ] . V_27 . V_28 . V_123 ,
0 ) ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_110 ] . V_27 . V_28 . V_127 ,
V_128 | V_129 ) ;
}
for ( V_110 = 0 ; V_110 < V_130 ; V_110 ++ ) {
F_1 ( V_1 ,
& V_1 -> V_66 [ V_110 ] . V_27 . V_28 . V_131 ,
V_132 ) ;
F_1 ( V_1 ,
& V_1 -> V_66 [ V_110 ] . V_27 . V_28 . V_133 ,
V_134 | V_135 |
V_136 ) ;
F_1 ( V_1 ,
& V_1 -> V_66 [ V_110 ] . V_27 . V_28 . V_137 ,
V_138 | V_139 |
V_140 | V_141 |
V_142 | V_143 ) ;
}
V_1 -> V_6 -> V_9 -> V_10 -> V_144 ( V_1 -> V_6 , V_109 ,
F_18 , V_1 ) ;
V_1 -> V_6 -> V_9 -> V_10 -> V_11 ( V_1 -> V_6 , V_116 , 0 ,
V_109 ) ;
V_16 = F_27 ( V_65 ) ;
if ( ! V_16 ) {
V_32 = - V_145 ;
goto V_146;
}
V_16 -> V_147 = V_148 ;
V_16 -> V_149 = L_5 ;
sprintf ( V_112 , L_6 , V_107 , V_108 ) ;
V_16 -> V_112 = V_112 ;
V_16 -> V_19 = 0 ;
V_16 -> V_150 = 0 ;
V_16 -> type = V_151 ;
V_16 -> V_152 = V_153 ;
V_16 -> V_154 = V_155 | V_156 ;
V_16 -> V_157 = V_158 ;
V_16 -> V_157 . V_159 = V_160 | V_161 | V_162 | V_163 | V_164 ;
V_16 -> V_157 . V_165 = 9600 ;
V_16 -> V_157 . V_166 = 9600 ;
F_28 ( V_16 , & V_167 ) ;
V_32 = F_29 ( V_16 ) ;
if ( V_32 ) {
F_7 ( & V_1 -> V_6 -> V_6 , L_7 ) ;
F_30 ( V_16 ) ;
goto V_146;
}
V_1 -> V_20 = V_16 ;
for ( V_110 = 0 ; V_110 < V_65 ; V_110 ++ ) {
F_31 ( & V_1 -> V_21 [ V_110 ] ) ;
F_32 ( & V_1 -> V_21 [ V_110 ] ) ;
V_1 -> V_21 [ V_110 ] . V_10 = & V_168 ;
F_12 ( & V_1 -> V_44 [ V_110 ] ) ;
V_1 -> V_47 [ V_110 ] = 0 ;
F_33 ( & V_1 -> V_78 [ V_110 ] ) ;
F_34 ( & V_1 -> V_169 [ V_110 ] ) ;
V_1 -> V_45 [ V_110 ] = 0 ;
V_1 -> V_46 [ V_110 ] = 0 ;
V_1 -> V_47 [ V_110 ] = 0 ;
F_35 ( V_16 , V_110 , NULL ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_110 ] . V_27 . V_28 . V_29 ,
V_30 ) ;
}
return 0 ;
V_146:
V_1 -> V_6 -> V_9 -> V_10 -> V_114 ( V_1 -> V_6 , V_101 ) ;
V_117:
V_1 -> V_6 -> V_9 -> V_10 -> V_114 ( V_1 -> V_6 , V_12 ) ;
V_115:
V_1 -> V_6 -> V_9 -> V_10 -> V_114 ( V_1 -> V_6 , V_116 ) ;
return V_32 ;
}
static inline int F_36 ( struct V_1 * V_1 ,
unsigned int V_23 ,
const unsigned char * V_170 ,
int V_171 )
{
unsigned long V_154 ;
int V_110 ;
unsigned int * V_45 = & V_1 -> V_45 [ V_23 ] ;
for ( V_110 = 0 ; V_110 < V_171 ; V_110 ++ ) {
if ( V_110 <= ( V_96 - V_1 -> V_47 [ V_23 ] ) ) {
F_37 ( & V_1 -> V_169 [ V_23 ] , V_154 ) ;
V_1 -> V_21 [ V_23 ] . V_93 [ * V_45 ] = V_170 [ V_110 ] ;
* V_45 = ( * V_45 + 1 ) % V_96 ;
V_1 -> V_47 [ V_23 ] ++ ;
F_38 ( & V_1 -> V_169 [ V_23 ] , V_154 ) ;
} else {
break;
}
}
return V_110 ;
}
static int F_39 ( struct V_1 * V_1 , unsigned int V_23 ,
const unsigned char * V_170 , int V_171 )
{
V_1 -> V_47 [ V_23 ] = 0 ;
V_1 -> V_95 [ V_23 ] = 0 ;
F_36 ( V_1 , V_23 , V_170 , V_171 ) ;
if ( V_1 -> V_72 == V_73 ) {
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_120 ) ;
F_2 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_172 ) ;
}
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_173 ) ;
F_40 ( V_1 -> V_78 [ V_23 ] , V_1 -> V_77 ) ;
F_1 ( V_1 ,
& V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_75 ) ;
V_1 -> V_77 = 0 ;
return V_1 -> V_95 [ V_23 ] ;
}
static int F_41 ( struct V_15 * V_16 ,
const unsigned char * V_170 , int V_171 )
{
unsigned int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_35 ;
return F_39 ( V_1 , V_23 , V_170 , V_171 ) ;
}
static int F_42 ( struct V_15 * V_16 )
{
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_35 ;
return V_96 - V_1 -> V_47 [ V_23 ] ;
}
static int F_43 ( struct V_15 * V_16 )
{
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_35 ;
return V_1 -> V_47 [ V_23 ] ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_174 * V_175 )
{
unsigned int V_176 ;
unsigned char V_177 = 0 ;
unsigned char V_178 = 0 ;
unsigned char V_127 = 0 ;
unsigned int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_35 ;
T_1 V_179 ;
V_176 = V_16 -> V_180 -> V_159 ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_120 | V_75 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_121 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_122 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_83 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_181 ) ;
switch ( V_176 & V_182 ) {
case V_183 :
V_177 |= V_184 ;
break;
case V_185 :
V_177 |= V_186 ;
break;
case V_161 :
default:
V_177 |= V_124 ;
V_16 -> V_180 -> V_159 = ( V_176 & ~ V_182 ) | V_161 ;
break;
}
if ( V_176 & V_187 )
if ( V_176 & V_188 )
V_177 |= V_189 | V_190 ;
else
V_177 |= V_189 | V_191 ;
else
V_177 |= V_192 ;
V_16 -> V_180 -> V_159 &= ~ V_193 ;
if ( V_176 & V_194 )
V_178 |= V_195 ;
else
V_178 |= V_196 ;
switch ( V_1 -> V_72 ) {
case V_105 :
if ( V_176 & V_197 ) {
V_177 |= V_198 ;
V_178 |= V_199 | V_200 ;
} else {
V_177 |= V_201 ;
V_178 |= V_199 | V_202 ;
}
break;
case V_106 :
V_177 |= V_201 ;
V_178 |= V_199 | V_202 ;
break;
case V_73 :
V_177 |= V_201 ;
V_178 |= V_203 | V_202 ;
break;
default:
return;
break;
}
V_179 = F_45 ( V_16 ) ;
F_46 ( V_16 -> V_180 , V_179 , V_179 ) ;
switch ( V_16 -> V_180 -> V_166 ) {
case 75 :
V_127 |= V_204 | V_205 ;
break;
case 110 :
V_127 |= V_206 | V_207 ;
break;
case 150 :
V_127 |= V_208 | V_209 ;
break;
case 300 :
V_127 |= V_210 | V_211 ;
break;
case 600 :
V_127 |= V_212 | V_213 ;
break;
case 1200 :
V_127 |= V_214 | V_215 ;
break;
case 1800 :
V_127 |= V_216 | V_217 ;
break;
case 2000 :
V_127 |= V_218 | V_219 ;
break;
case 2400 :
V_127 |= V_220 | V_221 ;
break;
case 4800 :
V_127 |= V_222 | V_223 ;
break;
case 9600 :
V_127 |= V_128 | V_129 ;
break;
case 19200 :
V_127 |= V_224 | V_225 ;
break;
case 38400 :
default:
V_127 |= V_226 | V_227 ;
F_46 ( V_16 -> V_180 , 38400 , 38400 ) ;
break;
}
V_177 |= V_125 ;
V_177 |= V_126 ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_123 , V_177 ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_123 , V_178 ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_127 , V_127 ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_30 ) ;
}
static void F_47 ( struct V_15 * V_16 )
{
unsigned long V_154 ;
int V_23 = V_16 -> V_24 ;
struct V_1 * V_1 = V_16 -> V_35 ;
if ( V_1 == NULL )
return;
F_37 ( & V_1 -> V_169 [ V_23 ] , V_154 ) ;
V_1 -> V_47 [ V_23 ] = 0 ;
V_1 -> V_45 [ V_23 ] = 0 ;
V_1 -> V_46 [ V_23 ] = 0 ;
F_38 ( & V_1 -> V_169 [ V_23 ] , V_154 ) ;
F_48 ( & V_1 -> V_21 [ V_23 ] ) ;
F_1 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_120 | V_75 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_121 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_122 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_83 ) ;
F_2 ( V_1 , & V_1 -> V_26 [ V_23 ] . V_27 . V_28 . V_29 ,
V_181 ) ;
F_49 ( V_228 , & V_1 -> V_21 [ V_23 ] . V_154 ) ;
F_20 ( & V_1 -> V_21 [ V_23 ] . V_229 ) ;
}
static int F_50 ( struct V_98 * V_6 )
{
int V_32 ;
unsigned char V_72 ;
if ( ( ! V_6 -> V_9 -> V_10 ) || ( ! V_6 -> V_9 -> V_10 -> V_113 ) ||
( ! V_6 -> V_9 -> V_10 -> V_114 ) )
return 0 ;
V_32 = V_6 -> V_9 -> V_10 -> V_113 ( V_6 , 0 , V_101 ) ;
if ( V_32 )
return 0 ;
V_32 = F_25 ( V_6 , & V_72 ) ;
V_6 -> V_9 -> V_10 -> V_114 ( V_6 , V_101 ) ;
if ( ! V_32 )
return 1 ;
return 0 ;
}
static int F_51 ( struct V_98 * V_6 )
{
int V_32 ;
struct V_1 * V_1 ;
V_1 = F_52 ( sizeof( struct V_1 ) , V_230 ) ;
if ( V_1 == NULL )
return - V_145 ;
V_1 -> V_6 = V_6 ;
V_32 = F_26 ( V_1 , V_6 -> V_107 , V_6 -> V_108 , V_6 -> V_231 ) ;
if ( V_32 )
goto V_232;
F_53 ( & V_1 -> V_233 , & V_234 ) ;
return 0 ;
V_232:
F_54 ( V_1 ) ;
return V_32 ;
}
static void F_55 ( struct V_1 * V_1 )
{
int V_110 ;
for ( V_110 = 0 ; V_110 < V_65 ; V_110 ++ ) {
F_56 ( V_1 -> V_20 , V_110 ) ;
F_57 ( & V_1 -> V_21 [ V_110 ] ) ;
}
F_58 ( V_1 -> V_20 ) ;
F_30 ( V_1 -> V_20 ) ;
F_59 ( & V_1 -> V_233 ) ;
F_54 ( V_1 ) ;
}
static void F_60 ( struct V_98 * V_235 )
{
struct V_1 * V_1 , * V_236 ;
F_61 (ipoctal, next, &ipoctal_list, list) {
if ( V_1 -> V_6 == V_235 )
F_55 ( V_1 ) ;
}
}
static int T_2 F_62 ( void )
{
V_18 . V_10 = & V_237 ;
return F_63 ( & V_18 , V_148 , V_238 ) ;
}
static void T_3 F_64 ( void )
{
struct V_1 * V_17 , * V_236 ;
F_61 (p, next, &ipoctal_list, list)
V_17 -> V_6 -> V_9 -> V_10 -> V_239 ( V_17 -> V_6 ) ;
F_65 ( & V_18 ) ;
}
