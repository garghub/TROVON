static inline void F_1 ( T_1 T_2 * V_1 , unsigned int V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_1 F_3 ( T_1 T_2 * V_1 , unsigned int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void F_5 ( T_1 * V_4 , T_1 V_5 , T_1 V_3 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_4 , V_5 ) ;
F_1 ( V_4 , V_5 , ( V_7 & ~ V_6 ) | ( V_3 & V_6 ) ) ;
}
static int F_6 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 V_12 ;
int V_13 = 0 , V_14 = 0 , V_15 ;
unsigned long V_16 , V_17 ;
V_16 = F_7 ( V_10 ) ;
V_12 . V_18 = ( V_19 ) V_16 & 0xffffffffe0ULL ;
V_12 . V_20 = 0 ;
V_12 . V_21 = 0 ;
V_12 . V_22 = 0 ;
V_15 = V_9 -> V_23 -> V_24 ;
do {
V_17 = F_8 () ;
V_13 = F_9 ( 1 , 0 , V_15 , & V_12 ) ;
F_10 ( V_17 ) ;
if ( V_13 == 0 )
return 0 ;
} while ( ++ V_14 < 10000 );
F_11 ( V_9 -> V_25 , L_1 ) ;
return V_13 ;
}
static inline unsigned char * F_12 ( void )
{
struct V_26 * V_27 ;
int V_28 = sizeof( struct V_26 * ) ;
unsigned char * V_29 ;
V_27 = F_13 ( V_30 , V_31 ) ;
if ( ! V_27 )
return NULL ;
V_29 = V_27 -> V_32 ;
F_14 ( V_27 , V_33 ) ;
F_15 ( V_27 , V_33 ) ;
memcpy ( V_29 , & V_27 , V_28 ) ;
return V_27 -> V_32 ;
}
static void F_16 ( int V_34 , int V_35 , int V_36 , int V_37 ,
struct V_11 * V_12 , void * V_38 )
{
struct V_26 * V_27 ;
void * V_29 = NULL ;
struct V_39 * V_25 ;
struct V_8 * V_9 ;
T_1 V_40 , V_41 ;
unsigned char * V_10 ;
struct V_42 * V_43 = V_38 ;
V_41 = ( V_12 -> V_18 >> 40 ) & 0x3fff ;
if ( V_41 == 0 ) {
V_10 = F_17 ( V_12 -> V_18 & 0xffffffffffULL ) ;
V_10 = V_10 - V_33 ;
V_27 = (struct V_26 * ) ( * ( unsigned long * ) V_10 ) ;
F_18 ( (struct V_26 * ) V_10 ) ;
} else {
V_10 = ( unsigned char * )
F_17 ( V_12 -> V_18 & 0xffffffffe0ULL ) ;
V_41 = V_41 - V_44 - V_45 ;
V_40 = ( ( int ) V_12 -> V_18 ) & 0x0f ;
V_10 = V_10 - V_33 ;
V_27 = (struct V_26 * ) ( * ( unsigned long * ) V_10 ) ;
V_27 -> V_46 = V_43 -> V_47 [ V_40 ] ;
if ( ! V_27 -> V_46 )
return;
V_25 = V_27 -> V_46 ;
V_9 = F_19 ( V_25 ) ;
F_20 ( V_27 , V_44 ) ;
F_14 ( V_27 , V_41 ) ;
V_27 -> V_48 = F_21 ( V_27 , V_27 -> V_46 ) ;
F_22 ( V_27 ) ;
V_29 = F_12 () ;
if ( V_29 )
F_6 ( V_9 , V_29 ) ;
}
}
static struct V_49 * F_23 ( struct V_8 * V_9 )
{
return F_24 ( V_9 -> V_50 , V_9 -> V_51 ) ;
}
static int F_25 ( struct V_39 * V_25 ,
struct V_52 * V_53 )
{
struct V_8 * V_9 = F_19 ( V_25 ) ;
struct V_49 * V_54 = F_23 ( V_9 ) ;
if ( ! V_54 )
return - V_55 ;
return F_26 ( V_54 , V_53 ) ;
}
static int F_27 ( struct V_39 * V_25 ,
const struct V_52 * V_53 )
{
struct V_8 * V_9 = F_19 ( V_25 ) ;
struct V_49 * V_54 = F_23 ( V_9 ) ;
if ( ! V_54 )
return - V_55 ;
return F_28 ( V_54 , V_53 ) ;
}
static int F_29 ( struct V_39 * V_25 )
{
void * V_29 ;
struct V_8 * V_9 = F_19 ( V_25 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 / 4 ; V_56 ++ ) {
V_29 = F_12 () ;
if ( ! V_29 ) {
F_11 ( V_25 , L_2 ) ;
return - V_58 ;
}
F_6 ( V_9 , V_29 ) ;
}
F_30 ( V_25 , L_3 ) ;
return 0 ;
}
static int F_31 ( struct V_39 * V_25 )
{
T_1 V_59 ;
struct V_8 * V_9 = F_19 ( V_25 ) ;
struct V_49 * V_54 = F_23 ( V_9 ) ;
F_32 ( V_54 ) ;
V_59 = F_33 ( V_54 ) ;
if ( V_59 ) {
F_34 ( L_4 ) ;
return V_59 ;
}
F_35 ( V_9 ) ;
F_36 ( V_25 ) ;
return 0 ;
}
static int F_37 ( struct V_39 * V_25 )
{
struct V_8 * V_9 = F_19 ( V_25 ) ;
struct V_49 * V_54 = F_23 ( V_9 ) ;
F_38 ( V_54 ) ;
F_39 ( V_25 ) ;
return 0 ;
}
static void F_40 ( struct V_11 * V_12 , unsigned long V_10 ,
struct V_26 * V_27 )
{
unsigned long V_60 = F_41 ( V_27 ) ;
int V_61 = F_42 () ;
int V_62 = V_61 * 8 + V_63 ;
V_12 -> V_18 = ( ( ( V_19 ) 1 << 63 ) |
( ( V_19 ) 127 << 54 ) |
( V_19 ) V_27 -> V_64 << 40 |
( ( V_19 ) V_10 ) ) ;
V_12 -> V_20 = ( ( ( V_19 ) 1 << 63 ) |
( ( V_19 ) V_62 << 54 ) |
( V_19 ) 0 << 40 |
( ( V_19 ) V_60 & 0xffffffff ) ) ;
V_12 -> V_21 = 0 ;
V_12 -> V_22 = 0 ;
}
static T_3 F_43 ( struct V_26 * V_27 ,
struct V_39 * V_25 )
{
struct V_11 V_12 ;
struct V_8 * V_9 = F_19 ( V_25 ) ;
int V_13 ;
T_1 V_65 ;
F_40 ( & V_12 , F_41 ( V_27 -> V_32 ) , V_27 ) ;
V_65 = F_8 () ;
V_13 = F_9 ( 2 , 0 , V_9 -> V_66 , & V_12 ) ;
F_10 ( V_65 ) ;
if ( V_13 )
F_18 ( V_27 ) ;
return V_67 ;
}
static T_4 F_44 ( struct V_39 * V_25 , struct V_26 * V_27 ,
void * V_68 ,
T_5 V_69 )
{
return ( T_4 ) F_45 () ;
}
static void F_46 ( struct V_39 * V_25 )
{
struct V_8 * V_9 = F_19 ( V_25 ) ;
F_1 ( V_9 -> V_4 , V_70 ,
( ( V_25 -> V_71 [ 5 ] << 24 ) | ( V_25 -> V_71 [ 4 ] << 16 ) |
( V_25 -> V_71 [ 3 ] << 8 ) | ( V_25 -> V_71 [ 2 ] ) ) ) ;
F_1 ( V_9 -> V_4 , V_70 + 1 ,
( ( V_25 -> V_71 [ 1 ] << 24 ) | ( V_25 -> V_71 [ 0 ] << 16 ) ) ) ;
F_1 ( V_9 -> V_4 , V_72 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_72 + 1 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_73 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_73 + 1 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_74 ,
( 1 << V_75 ) |
( 1 << V_76 ) |
( 1 << V_77 ) ) ;
if ( V_9 -> V_23 -> V_78 == V_79 ||
V_9 -> V_23 -> V_78 == V_80 )
F_5 ( V_9 -> V_4 , V_81 , V_82 , 0x7f ) ;
}
static int F_47 ( struct V_39 * V_25 , void * V_32 )
{
int V_59 ;
V_59 = F_48 ( V_25 , V_32 ) ;
if ( V_59 )
return V_59 ;
F_46 ( V_25 ) ;
return 0 ;
}
static void F_49 ( struct V_39 * V_25 )
{
struct V_8 * V_9 = F_19 ( V_25 ) ;
T_1 V_83 ;
V_83 = F_3 ( V_9 -> V_4 , V_74 ) ;
if ( V_25 -> V_65 & V_84 ) {
V_83 |= ( 1 << V_75 ) |
( 1 << V_85 ) |
( 1 << V_76 ) |
( 1 << V_86 ) ;
} else {
V_83 &= ~ ( ( 1 << V_85 ) |
( 1 << V_86 ) ) ;
}
F_1 ( V_9 -> V_4 , V_74 , V_83 ) ;
}
static void F_50 ( struct V_39 * V_25 , struct V_87 * V_88 )
{
struct V_8 * V_9 = F_19 ( V_25 ) ;
V_88 -> V_89 = F_3 ( V_9 -> V_4 , V_90 ) ;
V_88 -> V_91 = F_3 ( V_9 -> V_4 , V_92 ) ;
V_88 -> V_93 = F_3 ( V_9 -> V_4 , V_94 ) ;
V_88 -> V_95 = F_3 ( V_9 -> V_4 , V_96 ) ;
V_88 -> V_97 = F_3 ( V_9 -> V_4 , V_98 ) ;
V_88 -> V_99 = F_3 ( V_9 -> V_4 ,
V_100 ) ;
V_88 -> V_101 = F_3 ( V_9 -> V_4 ,
V_102 ) ;
V_88 -> V_103 = F_3 ( V_9 -> V_4 ,
V_104 ) ;
V_88 -> V_105 = F_3 ( V_9 -> V_4 ,
V_106 ) ;
V_88 -> V_107 = F_3 ( V_9 -> V_4 ,
V_108 ) ;
V_88 -> V_109 = F_3 ( V_9 -> V_4 ,
V_100 ) ;
V_88 -> V_110 = F_3 ( V_9 -> V_4 ,
V_111 ) ;
V_88 -> V_112 = F_3 ( V_9 -> V_4 ,
V_113 ) ;
V_88 -> V_114 = F_3 ( V_9 -> V_4 ,
V_100 ) ;
V_88 -> V_115 = F_3 ( V_9 -> V_4 ,
V_116 ) ;
V_88 -> V_117 = ( V_88 -> V_109 + V_88 -> V_110 +
V_88 -> V_112 + V_88 -> V_114 +
V_88 -> V_115 ) ;
V_88 -> V_118 = F_3 ( V_9 -> V_4 ,
V_119 ) ;
V_88 -> V_120 = F_3 ( V_9 -> V_4 ,
V_102 ) ;
V_88 -> V_121 = F_3 ( V_9 -> V_4 ,
V_102 ) ;
}
static void * F_51 ( struct V_8 * V_9 , int V_122 ,
int V_123 , int V_124 , int V_36 )
{
void * V_125 ;
T_1 * V_1 ;
unsigned long V_126 ;
T_1 V_127 ;
V_1 = V_9 -> V_4 ;
V_127 = V_36 ;
V_125 = F_52 ( V_127 + V_128 , V_31 ) ;
if ( ! V_125 ) {
F_34 ( L_5 ) ;
return V_129 ;
}
V_125 = F_53 ( V_125 , V_128 ) ;
V_126 = F_41 ( V_125 ) ;
F_54 ( & V_9 -> V_25 -> V_46 , L_6 ,
V_36 , V_126 ) ;
F_1 ( V_1 , V_122 , ( V_126 >> 5 ) & 0xffffffff ) ;
F_1 ( V_1 , V_123 , ( ( V_19 ) V_126 >> 37 ) & 0x07 ) ;
F_1 ( V_1 , V_124 , V_127 ) ;
return V_125 ;
}
static void F_55 ( struct V_8 * V_9 )
{
V_9 -> V_130 = F_51 ( V_9 ,
V_131 ,
V_132 ,
V_133 ,
V_57 *
sizeof( V_19 ) ) ;
V_9 -> V_134 = F_51 ( V_9 ,
V_135 ,
V_136 ,
V_137 ,
V_138 *
sizeof( V_19 ) ) ;
V_9 -> V_139 = F_51 ( V_9 ,
V_140 ,
V_141 ,
V_142 ,
V_143 *
sizeof( V_19 ) ) ;
V_9 -> V_144 = F_51 ( V_9 ,
V_145 ,
V_146 ,
V_147 ,
V_148 *
sizeof( V_19 ) ) ;
V_9 -> V_149 = F_51 ( V_9 ,
V_150 ,
V_151 ,
V_152 ,
V_153 *
sizeof( V_19 ) ) ;
V_9 -> V_154 = F_51 ( V_9 ,
V_155 ,
V_156 ,
V_157 ,
V_158 *
sizeof( V_19 ) ) ;
}
static void F_56 ( struct V_8 * V_9 )
{
int V_56 = 0 ;
V_19 V_159 = 0 ;
for ( V_56 = 0 ; V_56 < F_57 ( V_9 -> V_23 -> V_160 ) ; V_56 ++ )
V_159 |= ( 0xff << ( V_56 * 8 ) ) ;
F_1 ( V_9 -> V_4 , V_161 , ( V_159 & 0xffffffff ) ) ;
F_1 ( V_9 -> V_4 , V_161 + 1 ,
( ( V_159 >> 32 ) & 0xffffffff ) ) ;
F_1 ( V_9 -> V_4 , V_162 , ( V_159 & 0xffffffff ) ) ;
F_1 ( V_9 -> V_4 , V_162 + 1 ,
( ( V_159 >> 32 ) & 0xffffffff ) ) ;
F_1 ( V_9 -> V_4 , V_163 , ( V_159 & 0xffffffff ) ) ;
F_1 ( V_9 -> V_4 , V_163 + 1 ,
( ( V_159 >> 32 ) & 0xffffffff ) ) ;
F_1 ( V_9 -> V_4 , V_164 , ( V_159 & 0xffffffff ) ) ;
F_1 ( V_9 -> V_4 , V_164 + 1 ,
( ( V_159 >> 32 ) & 0xffffffff ) ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_165 * V_166 = V_9 -> V_23 -> V_167 ;
int V_168 = V_166 -> V_168 ;
int V_169 = V_166 -> V_169 ;
int * V_170 = V_9 -> V_23 -> V_170 ;
int V_56 , V_171 , V_59 ;
for ( V_56 = V_168 ; V_56 <= V_169 ; V_56 ++ ) {
F_1 ( V_9 -> V_4 ,
V_172 + V_56 - V_168 ,
V_170 [ V_56 ] ) ;
}
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
for ( V_171 = 0 ; V_171 < 8 ; V_171 ++ )
F_1 ( V_9 -> V_4 ,
( V_173 + ( V_56 * 8 ) ) + V_171 ,
V_166 -> V_174 [ ( V_56 * 8 ) + V_171 ] ) ;
}
F_1 ( V_9 -> V_4 , V_175 , 3 ) ;
F_1 ( V_9 -> V_4 , V_176 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_177 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_178 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_179 , 0xffffffff ) ;
F_1 ( V_9 -> V_4 , V_180 , 0 ) ;
V_59 = F_29 ( V_9 -> V_25 ) ;
if ( V_59 )
return V_59 ;
F_59 ( V_168 , V_169 , F_16 ,
V_9 -> V_43 ) ;
return 0 ;
}
static void F_60 ( struct V_8 * V_9 )
{
T_1 V_160 ;
T_1 V_3 ;
int V_181 [ 32 ] ;
int V_182 , V_183 , V_184 , V_185 , V_56 , V_171 , V_186 ;
int V_187 ;
V_187 = 0 ;
V_160 = V_9 -> V_23 -> V_160 ;
F_61 ( L_7 ,
( V_187 ) ? L_8 : L_9 ) ;
V_171 = 0 ;
for ( V_56 = 0 ; V_56 < 32 ; V_56 ++ ) {
if ( ( 1 << V_56 ) & V_160 ) {
V_181 [ V_171 ] = ( ( V_56 / 4 ) * 8 ) + ( V_56 % 4 ) ;
V_171 ++ ;
}
}
V_186 = 0 ;
V_184 = 3 ;
V_185 = 0 ;
for ( V_56 = 0 ; V_56 < 64 ; V_56 ++ ) {
V_184 = ( V_184 + 1 ) & 3 ;
V_185 = ( V_184 + 1 ) & 3 ;
V_182 = V_181 [ V_186 ] ;
V_186 = ( V_186 + 1 ) % V_171 ;
V_183 = V_181 [ V_186 ] ;
V_186 = ( V_186 + 1 ) % V_171 ;
V_3 = ( ( V_184 << 23 ) | ( V_182 << 17 ) | ( V_187 << 16 ) |
( V_185 << 7 ) | ( V_183 << 1 ) | ( V_187 << 0 ) ) ;
F_54 ( & V_9 -> V_25 -> V_46 , L_10 ,
V_56 , V_182 , V_183 , V_184 , V_185 ) ;
F_1 ( V_9 -> V_4 , V_188 + V_56 , V_3 ) ;
V_184 = V_185 ;
}
}
static void F_62 ( struct V_8 * V_9 )
{
T_1 V_3 ;
F_1 ( V_9 -> V_4 , V_189 , 0x01 ) ;
F_1 ( V_9 -> V_4 , V_190 ,
( ( 0x7f << 8 ) | ( 1 << 1 ) ) ) ;
F_1 ( V_9 -> V_4 , V_191 ,
( 9 << 20 ) | ( 1 << 19 ) | ( 1 << 18 ) | ( 0x01 << 16 ) |
( 0x0800 << 0 ) ) ;
F_1 ( V_9 -> V_4 , V_191 + 1 ,
( 9 << 25 ) | ( 1 << 21 ) | ( 12 << 14 ) | ( 4 << 10 ) |
( 16 << 4 ) | 4 ) ;
F_1 ( V_9 -> V_4 , V_192 , 6 ) ;
F_1 ( V_9 -> V_4 , V_192 + 2 , 17 ) ;
V_3 = ( ( 0 << 21 ) | ( 2 << 17 ) | ( 2 << 11 ) | ( 2 << 7 ) ) ;
F_1 ( V_9 -> V_4 , V_192 + 1 , V_3 ) ;
F_1 ( V_9 -> V_4 , V_192 + 3 , V_3 ) ;
F_60 ( V_9 ) ;
}
static int F_63 ( T_1 * V_4 , int V_51 , int V_193 , T_4 V_3 )
{
unsigned long V_194 , V_195 , V_196 ;
int V_197 ;
V_194 = F_64 ( 100 ) ;
V_195 = V_198 + V_194 ;
V_197 = 0 ;
F_1 ( V_4 , V_199 , ( V_51 << 8 ) | V_193 ) ;
F_1 ( V_4 , V_200 , ( T_1 ) V_3 ) ;
while ( ! V_197 ) {
V_196 = V_198 ;
if ( F_3 ( V_4 , V_201 ) == 0 )
break;
V_197 = F_65 ( V_196 , V_195 ) ;
}
if ( V_197 ) {
F_61 ( L_11 ) ;
return - V_202 ;
}
return 0 ;
}
static int F_66 ( T_1 * V_4 , int V_51 , int V_193 )
{
unsigned long V_194 , V_195 , V_196 ;
int V_197 ;
V_194 = F_64 ( 100 ) ;
V_195 = V_198 + V_194 ;
V_197 = 0 ;
F_1 ( V_4 , V_199 ,
( V_51 << 8 ) | ( V_193 << 0 ) ) ;
F_1 ( V_4 , V_203 ,
( 1 << V_204 ) ) ;
while ( ! V_197 ) {
V_196 = V_198 ;
if ( F_3 ( V_4 , V_201 ) == 0 )
break;
V_197 = F_65 ( V_196 , V_195 ) ;
}
if ( V_197 ) {
F_61 ( L_12 ) ;
return - V_202 ;
}
F_1 ( V_4 , V_203 , 0 ) ;
return F_3 ( V_4 , V_205 ) ;
}
static int F_67 ( struct V_50 * V_206 , int V_51 , int V_193 , T_4 V_3 )
{
struct V_8 * V_9 = V_206 -> V_9 ;
int V_13 ;
V_13 = F_63 ( V_9 -> V_207 , V_51 , V_193 , V_3 ) ;
F_54 ( & V_9 -> V_25 -> V_46 , L_13 ,
V_51 , V_193 , V_3 , V_13 ) ;
return V_13 ;
}
static int F_68 ( struct V_50 * V_206 , int V_51 , int V_193 )
{
struct V_8 * V_9 = V_206 -> V_9 ;
int V_13 ;
V_13 = F_66 ( V_9 -> V_207 , V_51 , V_193 ) ;
F_54 ( & V_9 -> V_25 -> V_46 , L_14 ,
V_51 , V_193 , V_13 ) ;
return V_13 ;
}
static void F_69 ( struct V_8 * V_9 )
{
int V_208 ;
F_63 ( V_9 -> V_209 , 26 , 0 , 0x6DB0 ) ;
F_63 ( V_9 -> V_209 , 26 , 1 , 0xFFFF ) ;
F_63 ( V_9 -> V_209 , 26 , 2 , 0xB6D0 ) ;
F_63 ( V_9 -> V_209 , 26 , 3 , 0x00FF ) ;
F_63 ( V_9 -> V_209 , 26 , 4 , 0x0000 ) ;
F_63 ( V_9 -> V_209 , 26 , 5 , 0x0000 ) ;
F_63 ( V_9 -> V_209 , 26 , 6 , 0x0005 ) ;
F_63 ( V_9 -> V_209 , 26 , 7 , 0x0001 ) ;
F_63 ( V_9 -> V_209 , 26 , 8 , 0x0000 ) ;
F_63 ( V_9 -> V_209 , 26 , 9 , 0x0000 ) ;
F_63 ( V_9 -> V_209 , 26 , 10 , 0x0000 ) ;
F_1 ( V_9 -> V_210 , 0x20 , 0x7e6802 ) ;
F_1 ( V_9 -> V_210 , 0x10 , 0x7104 ) ;
F_1 ( V_9 -> V_210 , 0x22 , 0x7e6802 ) ;
F_1 ( V_9 -> V_210 , 0x21 , 0x7104 ) ;
V_208 = V_9 -> V_51 % 4 + 27 ;
F_63 ( V_9 -> V_211 , V_208 , 0 , 0x1000 ) ;
F_63 ( V_9 -> V_211 , V_208 , 0 , 0x0200 ) ;
}
void F_35 ( struct V_8 * V_9 )
{
struct V_49 * V_54 = F_23 ( V_9 ) ;
int V_212 ;
if ( V_54 -> V_213 == V_80 )
F_69 ( V_9 ) ;
if ( V_54 -> V_212 != V_9 -> V_214 ) {
V_212 = V_54 -> V_212 ;
if ( V_212 == V_215 ) {
F_1 ( V_9 -> V_4 , V_216 , 0x7217 ) ;
V_9 -> V_214 = V_212 ;
} else if ( V_212 == V_217 || V_212 == V_218 ) {
F_1 ( V_9 -> V_4 , V_216 , 0x7117 ) ;
V_9 -> V_214 = V_212 ;
}
if ( V_54 -> V_213 == V_80 ) {
if ( V_212 == V_218 )
F_1 ( V_9 -> V_4 ,
V_219 ,
V_220 ) ;
if ( V_212 == V_217 )
F_1 ( V_9 -> V_4 ,
V_219 ,
V_221 ) ;
if ( V_212 == V_215 )
F_1 ( V_9 -> V_4 ,
V_219 ,
V_222 ) ;
}
if ( V_212 == V_218 )
F_1 ( V_9 -> V_4 , V_223 , 0x2 ) ;
if ( V_212 == V_217 )
F_1 ( V_9 -> V_4 , V_223 , 0x1 ) ;
if ( V_212 == V_215 )
F_1 ( V_9 -> V_4 , V_223 , 0x0 ) ;
}
F_61 ( L_15 , V_9 -> V_224 , V_9 -> V_214 ) ;
}
static void F_70 ( struct V_39 * V_25 )
{
struct V_8 * V_9 = F_19 ( V_25 ) ;
struct V_49 * V_54 = F_23 ( V_9 ) ;
T_1 V_225 ;
V_225 = F_3 ( V_9 -> V_4 , V_226 ) ;
if ( V_54 -> V_227 ) {
if ( V_54 -> V_212 != V_9 -> V_214 ) {
F_35 ( V_9 ) ;
F_61 ( L_16 , V_9 -> V_224 ) ;
}
} else {
F_35 ( V_9 ) ;
F_61 ( L_17 , V_9 -> V_224 ) ;
}
}
static int F_71 ( struct V_8 * V_9 )
{
struct V_49 * V_54 = F_23 ( V_9 ) ;
if ( ! V_54 ) {
F_34 ( L_18 , V_9 -> V_51 ) ;
return - V_55 ;
}
V_54 = F_72 ( V_9 -> V_25 , F_73 ( V_54 ) ,
F_70 , V_9 -> V_23 -> V_78 ) ;
if ( F_74 ( V_54 ) ) {
F_34 ( L_19 ) ;
return F_75 ( V_54 ) ;
}
V_54 -> V_228 &= ( V_229
| V_230
| V_231
| V_232
| V_233
| V_234
| V_235 ) ;
V_54 -> V_236 = V_54 -> V_228 ;
F_76 ( V_54 ) ;
return 0 ;
}
static int F_77 ( struct V_8 * V_9 ,
struct V_237 * V_238 )
{
int V_59 ;
V_9 -> V_50 = F_78 () ;
if ( ! V_9 -> V_50 ) {
F_34 ( L_20 ) ;
return - V_58 ;
}
V_9 -> V_50 -> V_9 = V_9 ;
V_9 -> V_50 -> V_239 = L_21 ;
snprintf ( V_9 -> V_50 -> V_240 , V_241 , L_22 ,
V_9 -> V_50 -> V_239 , V_9 -> V_224 ) ;
V_9 -> V_50 -> V_242 = F_68 ;
V_9 -> V_50 -> V_243 = F_67 ;
V_9 -> V_50 -> V_244 = & V_238 -> V_46 ;
V_9 -> V_50 -> V_245 = ~ ( 1 << V_9 -> V_51 ) ;
F_1 ( V_9 -> V_4 , V_246 , 0x7 ) ;
V_59 = F_79 ( V_9 -> V_50 ) ;
if ( V_59 ) {
F_80 ( V_9 -> V_50 ) ;
F_34 ( L_23 ) ;
return V_59 ;
}
F_61 ( L_24 , V_9 -> V_50 -> V_240 ) ;
V_59 = F_71 ( V_9 ) ;
if ( V_59 ) {
F_80 ( V_9 -> V_50 ) ;
return V_59 ;
}
return 0 ;
}
static void F_81 ( struct V_8 * V_9 )
{
T_1 V_247 = ( F_82 () & 0xf000 ) ;
if ( ( V_247 == 0x8000 || V_247 == 0x4000 || V_247 == 0xc000 ) &&
V_9 -> V_23 -> V_78 == V_79 )
F_5 ( V_9 -> V_4 , V_248 ,
( 1 << V_249 ) ,
( 1 << V_249 ) ) ;
F_5 ( V_9 -> V_4 , V_250 ,
( ( 1 << V_251 ) |
( 1 << V_252 ) |
( 1 << V_253 ) |
( 1 << V_254 ) ) ,
( ( 1 << V_251 ) |
( 1 << V_252 ) |
( 1 << V_253 ) |
( 1 << V_254 ) ) ) ;
F_5 ( V_9 -> V_4 , V_255 ,
( ( 1 << V_256 ) |
( 512 << V_257 ) ) , 0x3fff ) ;
F_5 ( V_9 -> V_4 , V_248 ,
1 << V_258 ,
1 << V_258 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
F_5 ( V_9 -> V_4 , V_250 ,
( ( 1 << V_251 ) |
( 1 << V_252 ) |
( 1 << V_253 ) |
( 1 << V_254 ) ) , 0x0 ) ;
F_5 ( V_9 -> V_4 , V_255 ,
( ( 1 << V_256 ) |
( 512 << V_257 ) ) , 0 ) ;
F_5 ( V_9 -> V_4 , V_248 ,
1 << V_258 , 0 ) ;
}
static int F_84 ( struct V_8 * V_9 ,
struct V_237 * V_238 )
{
int V_13 ;
F_61 ( L_25 , V_9 -> V_224 ) ;
F_83 ( V_9 ) ;
F_1 ( V_9 -> V_4 , V_259 ,
( 1 << V_260 ) |
( V_44 << V_261 ) |
( 1600 << V_262 ) ) ;
V_13 = F_77 ( V_9 , V_238 ) ;
if ( V_13 )
return V_13 ;
F_81 ( V_9 ) ;
F_1 ( V_9 -> V_4 , V_216 , 0x7217 ) ;
F_1 ( V_9 -> V_4 , V_223 , 0x02 ) ;
F_1 ( V_9 -> V_4 , V_263 , ( 1 << V_264 ) |
( 1 << V_265 ) | ( 1 << V_266 ) |
( 1 << V_267 ) | ( 1 << V_268 ) |
( 1 << V_269 ) | ( 1 << V_270 ) ) ;
F_5 ( V_9 -> V_4 , V_271 , 0 , 1 << V_272 ) ;
F_5 ( V_9 -> V_4 , V_271 , 1 << 2 , 1 << 2 ) ;
return 0 ;
}
static int F_85 ( struct V_237 * V_238 )
{
struct V_8 * V_9 = NULL ;
struct V_39 * V_25 ;
struct V_273 * V_274 ;
struct V_42 * V_43 ;
int V_59 , V_40 ;
F_61 ( L_26 , V_238 -> V_240 ) ;
V_43 = (struct V_42 * )
F_86 ( & V_238 -> V_46 , sizeof( * V_43 ) , V_275 ) ;
if ( ! V_43 )
return - V_58 ;
for ( V_40 = 0 ; V_40 < V_238 -> V_276 / 2 ; V_40 ++ ) {
V_25 = F_87 ( sizeof( struct V_8 ) , 32 ) ;
if ( ! V_25 ) {
F_88 ( & V_238 -> V_46 ,
L_27 ) ;
return - V_58 ;
}
V_9 = F_19 ( V_25 ) ;
V_9 -> V_238 = V_238 ;
V_9 -> V_25 = V_25 ;
V_9 -> V_224 = ( V_238 -> V_240 * 4 ) + V_40 ;
V_9 -> V_23 = (struct V_277 * ) V_238 -> V_46 . V_278 ;
V_274 = F_89 ( V_238 , V_279 , V_40 ) ;
V_9 -> V_4 = F_90 ( & V_238 -> V_46 , V_274 ) ;
if ( F_74 ( V_9 -> V_4 ) ) {
V_59 = F_75 ( V_9 -> V_4 ) ;
goto V_280;
}
V_9 -> V_43 = V_43 ;
V_43 -> V_47 [ V_40 ] = V_25 ;
V_274 = F_89 ( V_238 , V_281 , V_40 ) ;
if ( ! V_274 ) {
F_88 ( & V_238 -> V_46 , L_28 ,
V_9 -> V_224 ) ;
V_59 = - V_55 ;
goto V_280;
}
V_25 -> V_282 = V_274 -> V_283 ;
V_9 -> V_51 = V_9 -> V_23 -> V_51 [ V_40 ] ;
V_9 -> V_66 = V_9 -> V_23 -> V_66 [ V_40 ] ;
V_9 -> V_207 = V_9 -> V_23 -> V_207 ;
V_9 -> V_209 = V_9 -> V_23 -> V_209 ;
V_9 -> V_211 = V_9 -> V_23 -> V_211 ;
V_9 -> V_210 = V_9 -> V_23 -> V_210 ;
V_25 -> V_284 = & V_285 ;
V_25 -> V_286 = V_287 ;
F_91 ( V_25 ) ;
F_46 ( V_25 ) ;
F_49 ( V_25 ) ;
V_9 -> V_288 += V_289 ;
V_25 -> V_290 = & V_291 ;
F_92 ( V_25 , & V_238 -> V_46 ) ;
F_55 ( V_9 ) ;
F_56 ( V_9 ) ;
F_62 ( V_9 ) ;
if ( strcmp ( V_274 -> V_239 , L_29 ) == 0 ) {
V_59 = F_84 ( V_9 , V_238 ) ;
if ( V_59 ) {
F_88 ( & V_238 -> V_46 , L_30 ,
V_9 -> V_224 ) ;
goto V_280;
}
}
if ( V_9 -> V_224 == 0 || V_9 -> V_224 == 4 ) {
V_59 = F_58 ( V_9 ) ;
if ( V_59 )
goto V_292;
}
V_59 = F_93 ( V_25 ) ;
if ( V_59 ) {
F_88 ( & V_238 -> V_46 ,
L_31 ,
V_9 -> V_224 ) ;
goto V_292;
}
F_94 ( V_238 , V_9 ) ;
}
return 0 ;
V_292:
F_80 ( V_9 -> V_50 ) ;
V_280:
F_95 ( V_25 ) ;
return V_59 ;
}
static int F_96 ( struct V_237 * V_238 )
{
struct V_8 * V_9 = F_97 ( V_238 ) ;
F_98 ( V_9 -> V_25 ) ;
F_99 ( V_9 -> V_50 ) ;
F_80 ( V_9 -> V_50 ) ;
F_95 ( V_9 -> V_25 ) ;
return 0 ;
}
