static int T_1
F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 , V_6 ;
F_2 ( V_7
L_1 ) ;
if ( F_3 ( V_8 , V_9 ) ) {
F_2 ( V_10 L_2 ) ;
return - V_11 ;
}
V_2 = F_4 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 )
return - V_12 ;
V_4 = F_5 ( V_2 ) ;
V_2 -> V_13 |= V_14 ;
V_2 -> V_15 = ( unsigned int ) V_16 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = & V_22 ;
V_2 -> V_23 = & V_24 ;
F_6 ( & V_4 -> V_25 ) ;
F_6 ( & V_4 -> V_26 ) ;
F_6 ( & V_4 -> V_27 ) ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
V_29 [ V_5 ] . V_30 = F_7 ( V_31 + 2 * V_32 ) ;
if ( ! V_29 [ V_5 ] . V_30 )
return - V_12 ;
V_29 [ V_5 ] . V_33 . V_34 = 0 ;
V_29 [ V_5 ] . V_33 . V_35 = V_31 ;
V_29 [ V_5 ] . V_33 . V_36 = F_8 ( & V_29 [ V_5 + 1 ] ) ;
V_29 [ V_5 ] . V_33 . V_37 = F_9 ( F_8 ( V_29 [ V_5 ] . V_30 -> V_38 ) ) ;
V_29 [ V_5 ] . V_33 . V_39 = 0 ;
V_29 [ V_5 ] . V_33 . V_40 = 0 ;
F_10 ( & V_29 [ V_5 ] . V_33 ) ;
}
V_29 [ V_28 - 1 ] . V_33 . V_34 = V_41 ;
V_29 [ V_28 - 1 ] . V_33 . V_36 = F_8 ( & V_29 [ 0 ] ) ;
V_42 = 0 ;
for ( V_5 = 0 ; V_5 < V_43 ; V_5 ++ ) {
V_44 [ V_5 ] . V_33 . V_34 = 0 ;
V_44 [ V_5 ] . V_33 . V_35 = 0 ;
V_44 [ V_5 ] . V_33 . V_36 = F_8 ( & V_44 [ V_5 + 1 ] . V_33 ) ;
V_44 [ V_5 ] . V_33 . V_37 = 0 ;
V_44 [ V_5 ] . V_33 . V_39 = 0 ;
V_44 [ V_5 ] . V_33 . V_40 = 0 ;
V_44 [ V_5 ] . V_30 = 0 ;
}
V_44 [ V_43 - 1 ] . V_33 . V_34 = V_41 ;
V_44 [ V_43 - 1 ] . V_33 . V_36 = F_8 ( & V_44 [ 0 ] . V_33 ) ;
V_45 = & V_29 [ 0 ] ;
V_46 = & V_29 [ V_28 - 1 ] ;
V_47 = & V_44 [ 0 ] ;
V_48 = & V_44 [ 0 ] ;
V_49 = & V_44 [ V_43 - 1 ] ;
V_6 = F_11 ( V_2 ) ;
if ( V_6 ) {
F_12 ( V_2 ) ;
return V_6 ;
}
F_13 ( V_2 , & V_50 ) ;
V_51 = 10 ;
V_52 = 0 ;
V_53 . V_54 = V_55 + V_56 ;
V_53 . V_38 = ( unsigned long ) V_2 ;
V_53 . V_57 = V_58 ;
V_59 . V_57 = V_60 ;
V_59 . V_38 = ( unsigned long ) V_2 ;
V_61 = 0 ;
V_62 = V_63 ;
V_64 . V_54 = V_55 + V_65 ;
V_64 . V_38 = ( unsigned long ) V_2 ;
V_64 . V_57 = V_66 ;
V_4 -> V_67 . V_68 = 0x1f ;
V_4 -> V_67 . V_69 = 0x1f ;
V_4 -> V_67 . V_2 = V_2 ;
V_4 -> V_67 . V_70 = V_71 ;
V_4 -> V_67 . V_72 = V_73 ;
* V_74 = 0x00000000 ;
* V_75 = 0x00000000 ;
V_76 = V_55 ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , void * V_77 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
struct V_78 * V_79 = V_77 ;
F_14 ( & V_4 -> V_25 ) ;
memcpy ( V_2 -> V_80 , V_79 -> V_81 , V_2 -> V_82 ) ;
* V_16 = V_2 -> V_80 [ 0 ] | ( V_2 -> V_80 [ 1 ] << 8 ) |
( V_2 -> V_80 [ 2 ] << 16 ) | ( V_2 -> V_80 [ 3 ] << 24 ) ;
* V_83 = V_2 -> V_80 [ 4 ] | ( V_2 -> V_80 [ 5 ] << 8 ) ;
* V_84 = 0 ;
F_2 ( V_7 L_3 , V_2 -> V_85 , V_2 -> V_80 ) ;
F_15 ( & V_4 -> V_25 ) ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 )
{
unsigned long V_86 ;
* V_87 = F_17 ( V_87 , V_88 , V_89 ) ;
* V_90 =
F_17 ( V_90 , V_91 , V_92 ) |
F_17 ( V_90 , V_93 , V_92 ) |
F_17 ( V_90 , V_94 , V_92 ) ;
* V_95 =
F_17 ( V_95 , V_96 , V_92 ) |
F_17 ( V_95 , V_97 , V_92 ) |
F_17 ( V_95 , V_98 , V_92 ) |
F_17 ( V_95 , V_99 , V_92 ) ;
F_18 ( V_100 ) ;
F_18 ( V_20 ) ;
F_19 ( V_100 ) ;
F_19 ( V_20 ) ;
if ( F_20 ( V_18 , V_101 , 0 , V_9 ,
( void * ) V_2 ) ) {
goto V_102;
}
if ( F_20 ( V_103 , V_101 , 0 ,
V_9 , ( void * ) V_2 ) ) {
goto V_104;
}
if ( F_20 ( V_105 , V_106 , 0 ,
V_9 , ( void * ) V_2 ) ) {
goto V_107;
}
if ( F_21 ( V_100 ,
V_9 ,
V_108 ,
V_109 ) ) {
goto V_110;
}
if ( F_21 ( V_20 ,
V_9 ,
V_108 ,
V_109 ) ) {
goto V_111;
}
* V_16 = V_2 -> V_80 [ 0 ] | ( V_2 -> V_80 [ 1 ] << 8 ) |
( V_2 -> V_80 [ 2 ] << 16 ) | ( V_2 -> V_80 [ 3 ] << 24 ) ;
* V_83 = V_2 -> V_80 [ 4 ] | ( V_2 -> V_80 [ 5 ] << 8 ) ;
* V_84 = 0 ;
#if 0
*R_NETWORK_GA_0 = 0xffffffff;
*R_NETWORK_GA_1 = 0xffffffff;
*R_NETWORK_REC_CONFIG = 0xd;
#else
F_22 ( V_112 , V_113 , V_114 , V_115 ) ;
F_22 ( V_112 , V_113 , V_116 , V_117 ) ;
F_22 ( V_112 , V_113 , V_118 , V_89 ) ;
F_23 ( V_112 , V_113 , V_119 , V_61 ) ;
* V_113 = V_112 ;
#endif
* V_120 =
F_17 ( V_120 , V_121 , V_122 ) |
F_17 ( V_120 , V_89 , V_123 ) ;
F_22 ( V_124 , V_125 , V_126 , V_92 ) ;
F_22 ( V_124 , V_125 , V_127 , V_128 ) ;
F_22 ( V_124 , V_125 , V_129 , V_130 ) ;
F_22 ( V_124 , V_125 , V_131 , V_89 ) ;
F_22 ( V_124 , V_125 , V_132 , V_89 ) ;
F_22 ( V_124 , V_125 , V_133 , V_89 ) ;
F_22 ( V_124 , V_125 , V_134 , V_89 ) ;
* V_125 = V_124 ;
F_24 ( V_86 ) ;
* V_135 =
F_17 ( V_135 , V_97 , V_136 ) |
F_17 ( V_135 , V_99 , V_136 ) ;
* V_137 =
F_17 ( V_137 , V_91 , V_136 ) |
F_17 ( V_137 , V_93 , V_136 ) |
F_17 ( V_137 , V_94 , V_136 ) ;
* V_138 = F_17 (R_DMA_CH0_CLR_INTR, clr_eop, do) ;
* V_139 = F_17 (R_DMA_CH1_CLR_INTR, clr_eop, do) ;
( void ) * V_140 ;
( void ) * V_141 ;
* V_142 = F_8 ( V_45 ) ;
* V_143 = F_17 ( V_143 , V_144 , V_145 ) ;
* V_146 = 0 ;
* V_147 = F_8 ( V_49 ) ;
F_25 ( V_2 ) ;
F_26 ( V_86 ) ;
if ( F_27 ( V_2 ) )
goto V_148;
F_28 ( & V_53 ) ;
F_28 ( & V_64 ) ;
F_29 ( V_2 ) ;
return 0 ;
V_148:
F_30 ( V_20 , V_9 ) ;
V_111:
F_30 ( V_100 , V_9 ) ;
V_110:
F_31 ( V_105 , ( void * ) V_2 ) ;
V_107:
F_31 ( V_103 , ( void * ) V_2 ) ;
V_104:
F_31 ( V_18 , ( void * ) V_2 ) ;
V_102:
return - V_149 ;
}
static void
F_32 ( struct V_1 * V_2 )
{
V_51 = 100 ;
}
static void
F_33 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 , V_151 ) ;
if ( ( V_38 & V_152 ) ||
( V_38 & V_153 ) )
V_51 = 100 ;
else
V_51 = 10 ;
}
static void
F_34 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 ,
V_154 ) ;
V_51 = ( V_38 & V_155 ? 100 : 10 ) ;
}
static void
F_35 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 ,
V_156 ) ;
V_51 = ( V_38 & V_157 ? 100 : 10 ) ;
}
static void
F_36 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 ,
V_158 ) ;
V_51 = ( V_38 & V_159 ? 100 : 10 ) ;
}
static void
V_58 ( unsigned long V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
static int V_161 = 0 ;
unsigned long V_38 ;
int V_162 = V_51 ;
F_14 ( & V_4 -> V_27 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 , V_163 ) ;
if ( ! ( V_38 & V_164 ) ) {
V_51 = 0 ;
} else {
V_165 -> V_166 ( V_2 ) ;
}
F_14 ( & V_4 -> V_26 ) ;
if ( ( V_162 != V_51 ) || ! V_161 ) {
V_161 = 1 ;
F_37 ( V_167 ) ;
if ( V_51 )
F_29 ( V_2 ) ;
else
F_38 ( V_2 ) ;
}
F_15 ( & V_4 -> V_26 ) ;
V_53 . V_54 = V_55 + V_56 ;
F_28 ( & V_53 ) ;
F_15 ( & V_4 -> V_27 ) ;
}
static void
F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
unsigned short V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 ,
V_151 ) ;
V_38 &= ~ ( V_153 | V_152 |
V_168 | V_169 ) ;
switch ( V_52 ) {
case 10 :
if ( V_62 == V_170 )
V_38 |= V_169 ;
else if ( V_62 == V_171 )
V_38 |= V_168 ;
else
V_38 |= V_168 | V_169 ;
break;
case 100 :
if ( V_62 == V_170 )
V_38 |= V_152 ;
else if ( V_62 == V_171 )
V_38 |= V_153 ;
else
V_38 |= V_153 | V_152 ;
break;
case 0 :
if ( V_62 == V_170 )
V_38 |= V_152 | V_169 ;
else if ( V_62 == V_171 )
V_38 |= V_153 | V_168 ;
else
V_38 |= V_168 | V_169 |
V_153 | V_152 ;
break;
default:
V_38 |= V_168 | V_169 |
V_153 | V_152 ;
break;
}
V_73 ( V_2 , V_4 -> V_67 . V_150 , V_151 , V_38 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 , V_172 ) ;
if ( V_173 ) {
V_38 |= V_174 | V_175 ;
} else {
V_38 &= ~ ( V_174 | V_175 ) ;
if ( V_52 == 10 )
V_38 &= ~ V_176 ;
else
V_38 |= V_176 ;
if ( V_62 != V_170 )
V_38 &= ~ V_177 ;
else
V_38 |= V_177 ;
}
V_73 ( V_2 , V_4 -> V_67 . V_150 , V_172 , V_38 ) ;
}
static void
F_40 ( struct V_1 * V_2 , unsigned long V_178 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_14 ( & V_4 -> V_27 ) ;
if ( V_178 != V_52 ) {
V_52 = V_178 ;
F_39 ( V_2 ) ;
}
F_15 ( & V_4 -> V_27 ) ;
}
static void
V_66 ( unsigned long V_160 )
{
struct V_1 * V_2 = (struct V_1 * ) V_160 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
int V_179 ;
F_14 ( & V_4 -> V_27 ) ;
V_179 = V_61 ;
V_165 -> V_180 ( V_2 ) ;
if ( V_179 != V_61 ) {
F_23 ( V_112 , V_113 , V_119 , V_61 ) ;
* V_113 = V_112 ;
}
V_64 . V_54 = V_55 + V_65 ;
F_28 ( & V_64 ) ;
V_4 -> V_67 . V_61 = V_61 ;
F_15 ( & V_4 -> V_27 ) ;
}
static void
F_41 ( struct V_1 * V_2 )
{
V_61 = 1 ;
}
static void
F_42 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 , V_151 ) ;
if ( ( V_38 & V_169 ) ||
( V_38 & V_152 ) )
V_61 = 1 ;
else
V_61 = 0 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 ,
V_154 ) ;
V_61 = ( V_38 & V_181 ) ? 1 : 0 ;
}
static void
F_44 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 ,
V_156 ) ;
V_61 = ( V_38 & V_182 ) ? 1 : 0 ;
}
static void
F_45 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 ,
V_158 ) ;
V_61 = ( V_38 & V_183 ) ? 1 : 0 ;
}
static void
F_46 ( struct V_1 * V_2 , enum V_119 V_184 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_14 ( & V_4 -> V_27 ) ;
if ( V_184 != V_62 ) {
V_62 = V_184 ;
F_39 ( V_2 ) ;
}
F_15 ( & V_4 -> V_27 ) ;
}
static int
F_27 ( struct V_1 * V_2 )
{
int V_185 = 0 ;
#if ! F_47 ( V_186 )
unsigned int V_187 ;
unsigned int V_188 ;
unsigned int V_189 ;
struct V_190 * V_191 = NULL ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_14 ( & V_4 -> V_27 ) ;
for ( V_4 -> V_67 . V_150 = 0 ; V_4 -> V_67 . V_150 <= 31 ;
V_4 -> V_67 . V_150 ++ ) {
if ( V_71 ( V_2 ,
V_4 -> V_67 . V_150 , V_163 ) != 0xffff )
break;
}
if ( V_4 -> V_67 . V_150 == 32 ) {
V_185 = - V_192 ;
goto V_193;
}
V_187 = V_71 ( V_2 , V_4 -> V_67 . V_150 , V_194 ) ;
V_188 = V_71 ( V_2 , V_4 -> V_67 . V_150 , V_195 ) ;
V_189 = ( V_187 << 6 ) | ( V_188 >> 10 ) ;
for ( V_191 = & V_196 [ 0 ] ; V_191 -> V_189 ; V_191 ++ ) {
if ( V_191 -> V_189 == V_189 )
break;
}
V_165 = V_191 ;
V_193:
F_15 ( & V_4 -> V_27 ) ;
#endif
return V_185 ;
}
static int
V_71 ( struct V_1 * V_2 , int V_150 , int V_197 )
{
unsigned short V_144 ;
int V_38 ;
int V_198 ;
V_144 = ( V_199 << 14 ) | ( V_200 << 12 ) | ( V_150 << 7 ) |
( V_197 << 2 ) ;
F_48 ( V_144 , 0 ) ;
V_38 = 0 ;
for ( V_198 = 15 ; V_198 >= 0 ; V_198 -- ) {
V_38 |= ( F_49 () << V_198 ) ;
}
return V_38 ;
}
static void
V_73 ( struct V_1 * V_2 , int V_150 , int V_197 , int V_201 )
{
int V_198 ;
unsigned short V_144 ;
V_144 = ( V_199 << 14 ) | ( V_202 << 12 ) | ( V_150 << 7 ) |
( V_197 << 2 ) ;
F_48 ( V_144 , 1 ) ;
for ( V_198 = 15 ; V_198 >= 0 ; V_198 -- ) {
F_50 ( F_51 ( V_198 , V_201 ) ) ;
}
}
static void
F_48 ( unsigned short V_144 , int V_203 )
{
int V_198 ;
unsigned char V_38 = 0x2 ;
for ( V_198 = 31 ; V_198 >= 0 ; V_198 -- )
F_50 ( F_51 ( V_198 , V_204 ) ) ;
for ( V_198 = 15 ; V_198 >= 2 ; V_198 -- )
F_50 ( F_51 ( V_198 , V_144 ) ) ;
for ( V_198 = 1 ; V_198 >= 0 ; V_198 -- )
if ( V_203 )
F_50 ( F_51 ( V_198 , V_38 ) ) ;
else
F_49 () ;
}
static void
F_50 ( unsigned char V_205 )
{
* V_87 =
F_17 ( V_87 , V_88 , V_89 ) |
F_52 ( V_87 , V_206 , V_205 ) ;
F_53 ( 1 ) ;
* V_87 =
F_17 ( V_87 , V_88 , V_89 ) |
F_54 ( V_87 , V_207 ) |
F_52 ( V_87 , V_206 , V_205 ) ;
F_53 ( 1 ) ;
}
static unsigned char
F_49 ( void )
{
unsigned char V_205 ;
* V_87 = 0 ;
V_205 = F_55 ( V_208 , V_206 , * V_208 ) ;
F_53 ( 1 ) ;
* V_87 = F_54 ( V_87 , V_207 ) ;
F_53 ( 1 ) ;
return V_205 ;
}
static void
F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
unsigned short V_144 ;
unsigned short V_38 ;
int V_198 ;
V_38 = V_71 ( V_2 , V_4 -> V_67 . V_150 , V_172 ) ;
V_144 = ( V_199 << 14 ) | ( V_202 << 12 ) | ( V_4 -> V_67 . V_150 << 7 ) | ( V_172 << 2 ) ;
F_48 ( V_144 , 1 ) ;
V_38 |= 0x8000 ;
for ( V_198 = 15 ; V_198 >= 0 ; V_198 -- ) {
F_50 ( F_51 ( V_198 , V_38 ) ) ;
}
}
static void
F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
unsigned long V_86 ;
F_58 ( & V_4 -> V_25 , V_86 ) ;
F_2 ( V_209 L_4 , V_2 -> V_85 ,
F_59 ( V_2 ) ? L_5 : L_6 ) ;
V_2 -> V_210 . V_211 ++ ;
F_18 ( V_100 ) ;
F_19 ( V_100 ) ;
F_56 ( V_2 ) ;
while ( V_47 != V_48 ) {
F_60 ( V_47 -> V_30 ) ;
V_47 -> V_30 = 0 ;
V_47 = F_61 ( V_47 -> V_33 . V_36 ) ;
}
* V_146 = 0 ;
* V_147 = F_8 ( V_49 ) ;
F_62 ( V_2 ) ;
F_63 ( & V_4 -> V_25 , V_86 ) ;
}
static int
F_64 ( struct V_212 * V_30 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
unsigned char * V_37 = V_30 -> V_38 ;
unsigned long V_86 ;
#ifdef F_65
F_2 ( L_7 , V_213 ) ;
#endif
F_58 ( & V_4 -> V_25 , V_86 ) ;
V_48 -> V_30 = V_30 ;
V_2 -> V_214 = V_55 ;
F_66 ( V_4 , V_37 , V_30 -> V_215 ) ;
V_48 = F_61 ( V_48 -> V_33 . V_36 ) ;
if ( V_48 == V_47 ) {
F_67 ( V_2 ) ;
}
F_63 ( & V_4 -> V_25 , V_86 ) ;
return V_216 ;
}
static T_2
V_101 ( int V_17 , void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
unsigned long V_218 ;
V_218 = * V_219 ;
if ( V_218 & F_17 ( V_219 , V_99 , V_220 ) ) {
* V_139 = F_17 (R_DMA_CH1_CLR_INTR, clr_eop, do) ;
while ( ( * V_142 != F_8 ( V_45 ) ) &&
( V_45 != V_46 ) ) {
F_68 ( V_2 ) ;
V_2 -> V_210 . V_221 ++ ;
* V_143 = F_17 ( V_143 , V_144 , V_222 ) ;
* V_139 =
F_17 (R_DMA_CH1_CLR_INTR, clr_eop, do) |
F_17 (R_DMA_CH1_CLR_INTR, clr_descr, do) ;
}
}
while ( F_8 ( V_47 ) != * V_146 &&
( F_69 ( V_2 ) || V_47 != V_48 ) ) {
V_2 -> V_210 . V_223 += V_47 -> V_30 -> V_215 ;
V_2 -> V_210 . V_224 ++ ;
F_70 ( V_47 -> V_30 ) ;
V_47 -> V_30 = 0 ;
V_47 = F_61 ( V_47 -> V_33 . V_36 ) ;
F_62 ( V_2 ) ;
}
if ( V_218 & F_17 ( V_219 , V_97 , V_220 ) ) {
* V_138 = F_17 (R_DMA_CH0_CLR_INTR, clr_eop, do) ;
}
return V_225 ;
}
static T_2
V_106 ( int V_17 , void * V_217 )
{
struct V_1 * V_2 = (struct V_1 * ) V_217 ;
unsigned long V_218 = * V_226 ;
if ( V_218 & F_17 ( V_226 , V_93 , V_220 ) ) {
F_22 ( V_124 , V_125 , V_126 , V_92 ) ;
* V_125 = V_124 ;
F_22 ( V_124 , V_125 , V_126 , V_227 ) ;
V_2 -> V_210 . V_211 ++ ;
F_71 ( F_2 ( L_8 ) ) ;
}
if ( V_218 & F_17 ( V_226 , V_91 , V_220 ) ) {
F_72 ( & V_2 -> V_210 ) ;
F_71 ( F_2 ( L_9 ) ) ;
}
if ( V_218 & F_17 ( V_226 , V_94 , V_220 ) ) {
F_22 ( V_124 , V_125 , V_126 , V_92 ) ;
* V_125 = V_124 ;
F_22 ( V_124 , V_125 , V_126 , V_227 ) ;
V_2 -> V_210 . V_211 ++ ;
F_71 ( F_2 ( L_10 ) ) ;
}
return V_225 ;
}
static void
F_68 ( struct V_1 * V_2 )
{
struct V_212 * V_30 ;
int V_213 = 0 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
unsigned char * V_228 ;
#ifdef F_65
int V_5 ;
#endif
T_3 * V_229 ;
F_14 ( & V_4 -> V_26 ) ;
if ( ! V_230 && F_73 ( V_55 , V_76 ) ) {
F_37 ( V_231 ) ;
V_76 = V_55 + V_232 ;
V_230 = 1 ;
F_74 ( & V_59 , V_55 + V_233 / 10 ) ;
}
F_15 ( & V_4 -> V_26 ) ;
V_213 = V_45 -> V_33 . V_40 - 4 ;
V_2 -> V_210 . V_234 += V_213 ;
#ifdef F_65
F_2 ( L_11 , V_213 ) ;
V_228 = ( unsigned char * ) F_61 ( V_45 -> V_33 . V_37 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_2 ( L_12 , V_5 * 8 ,
V_228 [ 0 ] , V_228 [ 1 ] , V_228 [ 2 ] , V_228 [ 3 ] ,
V_228 [ 4 ] , V_228 [ 5 ] , V_228 [ 6 ] , V_228 [ 7 ] ) ;
V_228 += 8 ;
}
#endif
if ( V_213 < V_235 ) {
V_30 = F_7 ( V_213 - V_236 ) ;
if ( ! V_30 ) {
V_2 -> V_210 . V_237 ++ ;
F_2 ( V_238 L_13 , V_2 -> V_85 ) ;
goto V_239;
}
F_75 ( V_30 , V_213 - V_236 ) ;
V_228 = F_76 ( V_30 , V_236 ) ;
#ifdef F_65
F_2 ( L_14 ,
V_30 -> V_240 , V_30 -> V_38 , F_77 ( V_30 ) ,
F_78 ( V_30 ) ) ;
F_2 ( L_15 , V_228 ) ;
#endif
memcpy ( V_228 , F_61 ( V_45 -> V_33 . V_37 ) , V_213 ) ;
}
else {
int V_241 ;
struct V_212 * V_242 = F_7 ( V_31 + 2 * V_32 ) ;
if ( ! V_242 ) {
V_2 -> V_210 . V_237 ++ ;
F_2 ( V_238 L_13 , V_2 -> V_85 ) ;
goto V_239;
}
V_30 = V_45 -> V_30 ;
V_241 = ( int ) F_61 ( V_45 -> V_33 . V_37 ) - ( int ) V_30 -> V_38 ;
F_75 ( V_30 , V_213 + V_241 ) ;
F_79 ( V_30 , V_241 ) ;
V_45 -> V_30 = V_242 ;
V_45 -> V_33 . V_37 = F_9 ( F_8 ( V_45 -> V_30 -> V_38 ) ) ;
}
V_30 -> V_243 = F_80 ( V_30 , V_2 ) ;
F_81 ( V_30 ) ;
V_239:
V_45 -> V_33 . V_39 = 0 ;
V_229 = V_45 ;
V_45 = F_61 ( V_45 -> V_33 . V_36 ) ;
V_42 ++ ;
if ( V_42 == V_244 ) {
F_82 () ;
V_229 -> V_33 . V_34 |= V_41 ;
V_46 -> V_33 . V_34 &= ~ V_41 ;
V_46 = V_229 ;
V_42 = 0 ;
}
}
static int
F_83 ( struct V_1 * V_2 )
{
F_2 ( V_7 L_16 , V_2 -> V_85 ) ;
F_67 ( V_2 ) ;
* V_90 =
F_17 ( V_90 , V_91 , V_92 ) |
F_17 ( V_90 , V_93 , V_92 ) |
F_17 ( V_90 , V_94 , V_92 ) ;
* V_95 =
F_17 ( V_95 , V_96 , V_92 ) |
F_17 ( V_95 , V_97 , V_92 ) |
F_17 ( V_95 , V_98 , V_92 ) |
F_17 ( V_95 , V_99 , V_92 ) ;
F_18 ( V_100 ) ;
F_18 ( V_20 ) ;
F_31 ( V_18 , ( void * ) V_2 ) ;
F_31 ( V_103 , ( void * ) V_2 ) ;
F_31 ( V_105 , ( void * ) V_2 ) ;
F_30 ( V_100 , V_9 ) ;
F_30 ( V_20 , V_9 ) ;
F_72 ( & V_2 -> V_210 ) ;
F_84 ( & V_2 -> V_210 ) ;
F_85 ( & V_53 ) ;
F_85 ( & V_64 ) ;
return 0 ;
}
static int
F_86 ( struct V_1 * V_2 , struct V_245 * V_246 , int V_144 )
{
struct V_247 * V_38 = F_87 ( V_246 ) ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
int V_248 = 0 ;
int V_249 ;
F_14 ( & V_4 -> V_25 ) ;
switch ( V_144 ) {
case V_250 :
F_40 ( V_2 , 10 ) ;
break;
case V_251 :
F_40 ( V_2 , 100 ) ;
break;
case V_252 :
F_40 ( V_2 , 0 ) ;
break;
case V_253 :
F_46 ( V_2 , V_171 ) ;
break;
case V_254 :
F_46 ( V_2 , V_170 ) ;
break;
case V_255 :
F_46 ( V_2 , V_63 ) ;
break;
case V_256 :
V_249 = V_173 ;
V_173 = * ( int * ) V_38 ;
if ( V_173 != V_249 )
F_39 ( V_2 ) ;
break;
default:
V_248 = F_88 ( & V_4 -> V_67 , F_87 ( V_246 ) ,
V_144 , NULL ) ;
break;
}
F_15 ( & V_4 -> V_25 ) ;
return V_248 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_257 * V_144 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
int V_6 ;
F_90 ( & V_4 -> V_25 ) ;
V_6 = F_91 ( & V_4 -> V_67 , V_144 ) ;
F_92 ( & V_4 -> V_25 ) ;
V_144 -> V_258 &= ~ ( V_259
| V_260 ) ;
return V_6 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_257 * V_261 )
{
if ( V_261 -> V_63 == V_262 ) {
F_46 ( V_2 , V_63 ) ;
F_40 ( V_2 , 0 ) ;
} else {
F_46 ( V_2 , V_261 -> V_119 == V_263 ? V_171 : V_170 ) ;
F_40 ( V_2 , V_261 -> V_178 == V_264 ? 10 : 100 ) ;
}
return 0 ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_265 * V_266 )
{
F_95 ( V_266 -> V_267 , L_17 , sizeof( V_266 -> V_267 ) ) ;
F_95 ( V_266 -> V_268 , L_18 , sizeof( V_266 -> V_268 ) ) ;
F_95 ( V_266 -> V_269 , L_19 , sizeof( V_266 -> V_269 ) ) ;
F_95 ( V_266 -> V_270 , L_19 , sizeof( V_266 -> V_270 ) ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
if ( V_62 == V_63 && V_52 == 0 )
F_39 ( V_2 ) ;
return 0 ;
}
static int
F_97 ( struct V_1 * V_2 , struct V_271 * V_272 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_14 ( & V_4 -> V_25 ) ;
switch( V_272 -> V_273 ) {
case V_274 :
F_40 ( V_2 , 0 ) ;
F_46 ( V_2 , V_63 ) ;
break;
case V_275 :
F_40 ( V_2 , 10 ) ;
F_46 ( V_2 , V_63 ) ;
break;
case V_276 :
case V_277 :
F_40 ( V_2 , 100 ) ;
F_46 ( V_2 , V_63 ) ;
break;
case V_278 :
case V_279 :
case V_280 :
F_15 ( & V_4 -> V_25 ) ;
return - V_281 ;
break;
default:
F_2 ( V_282 L_20 , V_2 -> V_85 ) ;
F_15 ( & V_4 -> V_25 ) ;
return - V_283 ;
}
F_15 ( & V_4 -> V_25 ) ;
return 0 ;
}
static void
F_72 ( struct V_284 * V_285 )
{
unsigned long V_286 = * V_140 ;
V_285 -> V_287 += F_55 ( V_140 , V_288 , V_286 ) ;
V_285 -> V_289 += F_55 ( V_140 , V_290 , V_286 ) ;
V_285 -> V_291 += F_55 ( V_140 , V_292 , V_286 ) ;
V_285 -> V_293 += F_55 ( V_140 , V_294 , V_286 ) ;
}
static void
F_84 ( struct V_284 * V_285 )
{
unsigned long V_286 = * V_141 ;
V_285 -> V_295 +=
F_55 ( V_141 , V_296 , V_286 ) +
F_55 ( V_141 , V_297 , V_286 ) ;
}
static struct V_284 *
F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_298 = F_5 ( V_2 ) ;
unsigned long V_86 ;
F_58 ( & V_298 -> V_25 , V_86 ) ;
F_72 ( & V_2 -> V_210 ) ;
F_84 ( & V_2 -> V_210 ) ;
F_63 ( & V_298 -> V_25 , V_86 ) ;
return & V_2 -> V_210 ;
}
static void
F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_298 = F_5 ( V_2 ) ;
int V_299 = F_100 ( V_2 ) ;
unsigned long int V_300 ;
unsigned long int V_301 ;
F_14 ( & V_298 -> V_25 ) ;
if ( V_2 -> V_86 & V_302 ) {
V_300 = 0xfffffffful ;
V_301 = 0xfffffffful ;
F_22 ( V_112 , V_113 , V_303 , V_117 ) ;
* V_113 = V_112 ;
} else if ( V_2 -> V_86 & V_304 ) {
V_300 = 0xfffffffful ;
V_301 = 0xfffffffful ;
F_22 ( V_112 , V_113 , V_303 , V_305 ) ;
* V_113 = V_112 ;
} else if ( V_299 == 0 ) {
V_300 = 0x00000000ul ;
V_301 = 0x00000000ul ;
F_22 ( V_112 , V_113 , V_303 , V_305 ) ;
* V_113 = V_112 ;
} else {
char V_306 ;
struct V_307 * V_308 ;
char * V_309 ;
V_300 = 0x00000000ul ;
V_301 = 0x00000000ul ;
F_101 (ha, dev) {
V_306 = 0 ;
V_309 = V_308 -> V_79 ;
V_306 ^= ( * V_309 ) & 0x3f ;
V_306 ^= ( ( * V_309 ) >> 6 ) & 0x03 ;
++ V_309 ;
V_306 ^= ( ( * V_309 ) << 2 ) & 0x03c ;
V_306 ^= ( ( * V_309 ) >> 4 ) & 0xf ;
++ V_309 ;
V_306 ^= ( ( * V_309 ) << 4 ) & 0x30 ;
V_306 ^= ( ( * V_309 ) >> 2 ) & 0x3f ;
++ V_309 ;
V_306 ^= ( * V_309 ) & 0x3f ;
V_306 ^= ( ( * V_309 ) >> 6 ) & 0x03 ;
++ V_309 ;
V_306 ^= ( ( * V_309 ) << 2 ) & 0x03c ;
V_306 ^= ( ( * V_309 ) >> 4 ) & 0xf ;
++ V_309 ;
V_306 ^= ( ( * V_309 ) << 4 ) & 0x30 ;
V_306 ^= ( ( * V_309 ) >> 2 ) & 0x3f ;
V_306 &= 0x3f ;
if ( V_306 >= 32 ) {
V_301 |= ( 1 << ( V_306 - 32 ) ) ;
} else {
V_300 |= ( 1 << V_306 ) ;
}
}
F_22 ( V_112 , V_113 , V_303 , V_305 ) ;
* V_113 = V_112 ;
}
* V_74 = V_300 ;
* V_75 = V_301 ;
F_15 ( & V_298 -> V_25 ) ;
}
void
F_66 ( struct V_3 * V_4 , char * V_37 , int V_213 )
{
F_71 ( F_2 ( L_21 , V_37 , V_213 ) ) ;
F_14 ( & V_4 -> V_26 ) ;
if ( ! V_230 && F_73 ( V_55 , V_76 ) ) {
F_37 ( V_231 ) ;
V_76 = V_55 + V_232 ;
V_230 = 1 ;
F_74 ( & V_59 , V_55 + V_233 / 10 ) ;
}
F_15 ( & V_4 -> V_26 ) ;
V_48 -> V_33 . V_35 = V_213 ;
V_48 -> V_33 . V_34 = V_310 | V_41 | V_311 ;
V_48 -> V_33 . V_37 = F_8 ( V_37 ) ;
V_49 -> V_33 . V_34 &= ~ V_41 ;
V_49 = V_48 ;
* V_312 = F_17 ( V_312 , V_144 , V_222 ) ;
}
static void
V_60 ( unsigned long V_313 )
{
struct V_1 * V_2 = (struct V_1 * ) V_313 ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_14 ( & V_4 -> V_26 ) ;
if ( V_230 && F_73 ( V_55 , V_76 ) ) {
F_37 ( V_167 ) ;
V_76 = V_55 + V_314 ;
V_230 = 0 ;
}
F_15 ( & V_4 -> V_26 ) ;
}
static void
F_37 ( int V_220 )
{
#if F_47 ( V_315 )
int V_316 = ( V_220 == V_167 ) ;
#elif F_47 ( V_317 )
int V_316 = ( V_220 == V_231 ) ;
#else
#error "Define either CONFIG_ETRAX_NETWORK_LED_ON_WHEN_LINK or CONFIG_ETRAX_NETWORK_LED_ON_WHEN_ACTIVITY"
#endif
if ( ! V_51 ) {
F_102 ( V_318 ) ;
} else if ( V_316 ) {
if ( V_51 == 10 ) {
F_102 ( V_319 ) ;
} else {
F_102 ( V_320 ) ;
}
} else {
F_102 ( V_318 ) ;
}
}
static void
F_103 ( struct V_1 * V_321 )
{
V_101 ( V_103 , V_321 ) ;
}
static int
F_104 ( void )
{
return F_1 () ;
}
static int T_1
F_105 ( char * V_322 )
{
struct V_78 V_323 = { 0 } ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_324 ; V_5 ++ ) {
unsigned int V_325 ;
if ( sscanf ( V_322 + 3 * V_5 , L_22 , & V_325 ) != 1 ) {
F_2 ( V_209 L_23 ) ;
return 0 ;
}
V_323 . V_81 [ V_5 ] = ( char ) V_325 ;
}
V_50 = V_323 ;
return 1 ;
}
