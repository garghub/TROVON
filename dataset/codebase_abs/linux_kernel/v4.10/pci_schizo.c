static void * F_1 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned int V_4 ,
int V_5 )
{
if ( ! V_2 )
return NULL ;
V_3 -= V_2 -> V_6 ;
return ( void * )
( F_2 ( V_2 ) |
F_3 ( V_3 , V_4 , V_5 ) ) ;
}
static void F_4 ( struct V_1 * V_2 ,
enum V_7 type )
{
struct V_8 * V_8 = & V_2 -> V_9 ;
unsigned long V_10 = V_2 -> V_11 ;
unsigned long V_12 , V_13 , V_14 ;
T_1 V_15 ;
int V_16 ;
V_12 = V_10 + V_17 ;
V_13 = V_10 + V_18 ;
V_14 = V_10 + V_19 ;
F_5 ( & V_20 ) ;
V_15 = F_6 ( V_8 -> V_21 ) ;
F_7 ( ( V_15 | V_22 ) ,
V_8 -> V_21 ) ;
for ( V_16 = 0 ; V_16 < 128 ; V_16 ++ ) {
unsigned long V_23 ;
V_23 = F_6 ( V_12 + ( V_16 * 8UL ) ) ;
F_7 ( 0UL , V_12 + ( V_16 * 8UL ) ) ;
V_24 [ V_16 ] = V_23 ;
}
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
V_25 [ V_16 ] = F_6 ( V_13 + ( V_16 * 8UL ) ) ;
V_26 [ V_16 ] = F_6 ( V_14 + ( V_16 * 8UL ) ) ;
F_7 ( 0UL , V_13 + ( V_16 * 8UL ) ) ;
F_7 ( 0UL , V_14 + ( V_16 * 8UL ) ) ;
}
F_7 ( V_15 , V_8 -> V_21 ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
int V_27 , V_28 , V_29 , V_30 ;
V_28 = 0 ;
V_29 = V_16 * 8 ;
V_30 = V_29 + 8 ;
for ( V_27 = V_29 ; V_27 < V_30 ; V_27 ++ ) {
unsigned long V_31 = V_24 [ V_27 ] ;
if ( V_31 != 0 ) {
V_28 ++ ;
F_8 ( L_1 ,
V_2 -> V_32 ,
V_27 ,
( V_31 & V_33 ) ? 1 : 0 ,
( V_31 & V_34 ) ? 1 : 0 ) ;
}
}
if ( V_28 != 0 ) {
unsigned long V_35 = V_25 [ V_16 ] ;
unsigned long V_36 = V_26 [ V_16 ] ;
F_8 ( L_2 ,
V_2 -> V_32 ,
V_16 ,
( ( V_35 & V_37 ) >> 19UL ) ,
( V_35 & V_38 ) ,
( ( V_35 & V_39 ) ? 1 : 0 ) ,
( ( V_35 & V_40 ) ? 1 : 0 ) ) ;
F_8 ( L_3
L_4 ,
V_2 -> V_32 ,
V_16 ,
( ( V_36 & V_41 ) >> 23UL ) ,
( ( V_36 & V_42 ) >> 13UL ) ,
( ( V_36 & V_43 ) >> 6UL ) ,
( ( V_36 & V_44 ) >> 0UL ) ,
( ( V_36 & V_45 ) ? 1 : 0 ) ,
( ( V_36 & V_46 ) ? 1 : 0 ) ) ;
}
}
F_9 ( & V_20 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
enum V_7 type )
{
struct V_47 * V_47 = V_2 -> V_47 ;
unsigned long V_48 [ 16 ] ;
unsigned long V_49 [ 16 ] ;
unsigned long V_50 ;
T_1 V_15 ;
int V_16 ;
F_11 ( & V_47 -> V_51 , V_50 ) ;
V_15 = F_6 ( V_47 -> V_52 ) ;
if ( V_15 & V_53 ) {
unsigned long V_54 ;
char * V_55 ;
V_15 &= ~ V_53 ;
F_7 ( V_15 , V_47 -> V_52 ) ;
switch( ( V_15 & V_56 ) >> 25UL ) {
case 0 :
V_55 = L_5 ;
break;
case 1 :
V_55 = L_6 ;
break;
case 2 :
V_55 = L_7 ;
break;
case 3 :
default:
V_55 = L_8 ;
break;
}
F_8 ( L_9 ,
V_2 -> V_32 , V_55 ) ;
F_7 ( V_15 | V_57 ,
V_47 -> V_52 ) ;
V_54 = V_2 -> V_11 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
V_48 [ V_16 ] =
F_6 ( V_54 + V_58 + ( V_16 * 8UL ) ) ;
V_49 [ V_16 ] =
F_6 ( V_54 + V_59 + ( V_16 * 8UL ) ) ;
F_7 ( 0 , V_54 + V_58 + ( V_16 * 8UL ) ) ;
F_7 ( 0 , V_54 + V_59 + ( V_16 * 8UL ) ) ;
}
F_7 ( V_15 , V_47 -> V_52 ) ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
unsigned long V_60 , V_61 ;
V_60 = V_48 [ V_16 ] ;
if ( ! ( V_60 & V_62 ) )
continue;
V_61 = V_49 [ V_16 ] ;
switch( ( V_60 & V_63 ) >> 23UL ) {
case 0 :
V_55 = L_5 ;
break;
case 1 :
V_55 = L_6 ;
break;
case 2 :
V_55 = L_7 ;
break;
case 3 :
default:
V_55 = L_8 ;
break;
}
F_8 ( L_10
L_11 ,
V_2 -> V_32 , V_16 , V_55 ,
( int ) ( ( V_60 & V_64 ) >> 25UL ) ,
( ( V_60 & V_65 ) ? 1 : 0 ) ,
( ( V_60 & V_66 ) ? 1 : 0 ) ,
( ( V_60 & V_67 ) ? 64 : 8 ) ,
( V_60 & V_68 ) << V_69 ) ;
F_8 ( L_12 ,
V_2 -> V_32 , V_16 ,
( ( V_61 & V_70 ) ? 1 : 0 ) ,
( ( V_61 & V_71 ) ? 1 : 0 ) ,
( V_61 & V_72 ) << V_69 ) ;
}
}
if ( V_2 -> V_9 . V_73 )
F_4 ( V_2 , type ) ;
F_12 ( & V_47 -> V_51 , V_50 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
enum V_7 type )
{
F_10 ( V_2 , type ) ;
if ( V_2 -> V_74 )
F_10 ( V_2 -> V_74 , type ) ;
}
static T_2 F_14 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
unsigned long V_77 = V_2 -> V_78 + V_79 ;
unsigned long V_80 = V_2 -> V_78 + V_81 ;
unsigned long V_82 , V_83 , V_84 ;
int V_85 , V_86 ;
V_83 = F_6 ( V_80 ) ;
V_86 = 1000 ;
do {
V_82 = F_6 ( V_77 ) ;
} while ( ( V_82 & V_87 ) != 0 && -- V_86 );
V_84 = V_82 &
( V_88 | V_89 | V_90 |
V_91 | V_92 ) ;
if ( ! V_84 )
return V_93 ;
F_7 ( V_84 , V_77 ) ;
F_8 ( L_13 ,
V_2 -> V_32 ,
( ( ( V_84 & V_88 ) ?
L_14 :
( ( V_84 & V_89 ) ?
L_15 :
( ( V_84 & V_90 ) ?
L_16 : L_17 ) ) ) ) ) ;
F_8 ( L_18 ,
V_2 -> V_32 ,
( V_82 & V_94 ) >> 32UL ,
( V_82 & V_95 ) >> 30UL ,
( V_82 & V_96 ) >> 24UL ) ;
F_8 ( L_19 ,
V_2 -> V_32 ,
( V_82 & V_97 ) ? 1 : 0 ,
( V_82 & V_98 ) ? 1 : 0 ,
( V_82 & V_99 ) >> 13UL ,
( V_82 & V_100 ) >> 16UL ,
( V_82 & V_101 ) >> 0UL ) ;
F_8 ( L_20 , V_2 -> V_32 , V_83 ) ;
F_8 ( L_21 , V_2 -> V_32 ) ;
V_85 = 0 ;
if ( V_82 & V_91 ) {
V_85 ++ ;
F_8 ( L_22 ) ;
}
if ( V_82 & V_92 ) {
V_85 ++ ;
F_8 ( L_23 ) ;
}
if ( ! V_85 )
F_8 ( L_24 ) ;
F_8 ( L_25 ) ;
F_13 ( V_2 , V_102 ) ;
return V_103 ;
}
static T_2 F_15 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
unsigned long V_77 = V_2 -> V_78 + V_104 ;
unsigned long V_80 = V_2 -> V_78 + V_105 ;
unsigned long V_82 , V_83 , V_84 ;
int V_85 , V_86 ;
V_83 = F_6 ( V_80 ) ;
V_86 = 1000 ;
do {
V_82 = F_6 ( V_77 ) ;
} while ( ( V_82 & V_87 ) != 0 && -- V_86 );
V_84 = V_82 &
( V_106 | V_107 | V_108 |
V_109 | V_110 ) ;
if ( ! V_84 )
return V_93 ;
F_7 ( V_84 , V_77 ) ;
F_8 ( L_26 ,
V_2 -> V_32 ,
( ( ( V_84 & V_106 ) ?
L_14 :
( ( V_84 & V_107 ) ?
L_15 :
( ( V_84 & V_108 ) ?
L_16 : L_17 ) ) ) ) ) ;
F_8 ( L_18 ,
V_2 -> V_32 ,
( V_82 & V_94 ) >> 32UL ,
( V_82 & V_95 ) >> 30UL ,
( V_82 & V_96 ) >> 24UL ) ;
F_8 ( L_19 ,
V_2 -> V_32 ,
( V_82 & V_97 ) ? 1 : 0 ,
( V_82 & V_98 ) ? 1 : 0 ,
( V_82 & V_99 ) >> 13UL ,
( V_82 & V_100 ) >> 16UL ,
( V_82 & V_101 ) >> 0UL ) ;
F_8 ( L_27 , V_2 -> V_32 , V_83 ) ;
F_8 ( L_28 , V_2 -> V_32 ) ;
V_85 = 0 ;
if ( V_82 & V_109 ) {
V_85 ++ ;
F_8 ( L_22 ) ;
}
if ( V_82 & V_110 ) {
V_85 ++ ;
F_8 ( L_23 ) ;
}
if ( ! V_85 )
F_8 ( L_24 ) ;
F_8 ( L_25 ) ;
return V_103 ;
}
static T_2 F_16 ( struct V_1 * V_2 )
{
unsigned long V_111 , V_112 , V_113 ;
T_2 V_114 = V_93 ;
T_3 V_115 ;
V_111 = V_2 -> V_11 + V_116 ;
V_112 = F_6 ( V_111 ) ;
V_113 =
V_112 & ( V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 ) ;
if ( V_113 ) {
F_7 ( V_112 , V_111 ) ;
if ( V_113 & V_117 )
F_8 ( L_29 ,
V_2 -> V_32 ) ;
if ( V_113 & V_118 )
F_8 ( L_30 ,
V_2 -> V_32 ) ;
if ( V_113 & V_119 )
F_8 ( L_31 ,
V_2 -> V_32 ) ;
if ( V_113 & V_120 )
F_8 ( L_32 ,
V_2 -> V_32 ) ;
if ( V_113 & V_121 )
F_8 ( L_33 ,
V_2 -> V_32 ) ;
if ( V_113 & V_122 )
F_8 ( L_34 ,
V_2 -> V_32 ) ;
V_114 = V_103 ;
}
V_2 -> V_123 -> V_124 ( V_2 -> V_125 , 0 , V_126 , 2 , & V_115 ) ;
if ( V_115 & ( V_127 |
V_128 |
V_129 |
V_130 |
V_131 ) ) {
F_8 ( L_35 ,
V_2 -> V_32 , V_115 ) ;
V_2 -> V_123 -> V_132 ( V_2 -> V_125 , 0 , V_126 , 2 , 0xffff ) ;
V_114 = V_103 ;
}
return V_114 ;
}
static T_2 F_17 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
unsigned long V_77 , V_80 , V_54 ;
unsigned long V_82 , V_83 , V_84 ;
int V_85 ;
V_54 = V_2 -> V_11 ;
V_77 = V_54 + V_133 ;
V_80 = V_54 + V_134 ;
V_83 = F_6 ( V_80 ) ;
V_82 = F_6 ( V_77 ) ;
V_84 = V_82 &
( V_135 | V_136 |
V_137 | V_138 |
V_139 | V_140 |
V_141 | V_142 |
V_143 | V_144 |
V_145 | V_146 ) ;
if ( ! V_84 )
return F_16 ( V_2 ) ;
F_7 ( V_84 , V_77 ) ;
F_8 ( L_36 ,
V_2 -> V_32 ,
( ( ( V_84 & V_135 ) ?
L_37 :
( ( V_84 & V_136 ) ?
L_38 :
( ( V_84 & V_137 ) ?
L_39 :
( ( V_84 & V_138 ) ?
L_40 :
( ( V_84 & V_139 ) ?
L_41 :
( ( V_84 & V_140 ) ?
L_42 : L_17 ) ) ) ) ) ) ) ) ;
F_8 ( L_43 ,
V_2 -> V_32 ,
( V_82 & V_147 ) >> 32UL ,
( V_82 & V_148 ) ? 1 : 0 ,
( ( V_82 & V_149 ) ?
L_44 :
( ( V_82 & V_150 ) ?
L_45 :
( ( V_82 & V_151 ) ?
L_46 : L_17 ) ) ) ) ;
F_8 ( L_47 ,
V_2 -> V_32 , V_83 ) ;
F_8 ( L_48 ,
V_2 -> V_32 ) ;
V_85 = 0 ;
if ( V_82 & V_141 ) {
V_85 ++ ;
F_8 ( L_49 ) ;
}
if ( V_82 & V_142 ) {
V_85 ++ ;
F_8 ( L_50 ) ;
}
if ( V_82 & V_143 ) {
V_85 ++ ;
F_8 ( L_51 ) ;
}
if ( V_82 & V_144 ) {
V_85 ++ ;
F_8 ( L_52 ) ;
}
if ( V_82 & V_145 ) {
V_85 ++ ;
F_8 ( L_53 ) ;
}
if ( V_82 & V_146 ) {
V_85 ++ ;
F_8 ( L_54 ) ;
}
if ( ! V_85 )
F_8 ( L_24 ) ;
F_8 ( L_25 ) ;
if ( V_84 & ( V_136 | V_142 ) ) {
F_13 ( V_2 , V_152 ) ;
F_18 ( V_2 , V_2 -> V_125 ) ;
}
if ( V_84 & ( V_135 | V_141 ) )
F_19 ( V_2 , V_2 -> V_125 ) ;
if ( V_84 & ( V_138 | V_144 ) )
F_20 ( V_2 , V_2 -> V_125 ) ;
return V_103 ;
}
static T_2 F_21 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
T_1 V_153 ;
V_153 = F_6 ( V_2 -> V_78 + V_154 ) ;
F_7 ( V_153 & ~ ( V_155 ) ,
V_2 -> V_78 + V_154 ) ;
if ( ! ( V_153 & V_156 ) ) {
F_8 ( L_55 ,
V_2 -> V_32 , V_153 ) ;
return V_103 ;
}
F_8 ( L_56 ,
V_2 -> V_32 ) ;
F_13 ( V_2 , V_157 ) ;
return V_103 ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_158 )
{
V_158 &= V_159 ;
if ( V_2 -> V_160 & ( 1UL << V_158 ) )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_161 * V_162 = F_24 ( V_2 -> V_162 -> V_163 . V_164 ) ;
T_1 V_165 , V_166 , V_167 ;
int V_168 ;
if ( F_22 ( V_2 , V_169 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 1 ] , F_14 , 0 ,
L_57 , V_2 ) ;
if ( V_168 )
F_8 ( V_172 L_58
L_59 , V_2 -> V_32 , V_168 ) ;
}
if ( F_22 ( V_2 , V_173 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 2 ] , F_15 , 0 ,
L_60 , V_2 ) ;
if ( V_168 )
F_8 ( V_172 L_61
L_59 , V_2 -> V_32 , V_168 ) ;
}
V_168 = 0 ;
if ( F_22 ( V_2 , V_174 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 0 ] , F_17 , 0 ,
L_62 , V_2 ) ;
} else if ( F_22 ( V_2 , V_175 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 0 ] , F_17 , 0 ,
L_62 , V_2 ) ;
}
if ( V_168 )
F_8 ( V_172 L_63
L_59 , V_2 -> V_32 , V_168 ) ;
if ( F_22 ( V_2 , V_176 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 3 ] , F_21 , 0 ,
L_64 , V_2 ) ;
if ( V_168 )
F_8 ( V_172 L_65
L_59 , V_2 -> V_32 , V_168 ) ;
}
F_7 ( ( V_177 |
V_178 |
V_179 ) , V_2 -> V_78 + V_180 ) ;
V_166 = ( V_117 |
V_118 |
V_119 |
V_122 |
V_181 ) ;
V_167 = V_120 ;
V_165 = F_6 ( V_2 -> V_11 + V_116 ) ;
V_165 |= V_166 ;
V_165 &= ~ V_167 ;
F_7 ( V_165 , V_2 -> V_11 + V_116 ) ;
V_166 = ( V_135 | V_136 |
V_137 | V_138 |
V_139 |
V_141 | V_142 |
V_143 | V_144 |
V_145 ) ;
F_7 ( V_166 , V_2 -> V_11 + V_133 ) ;
V_166 = ( V_182 | V_183 |
V_184 | V_185 |
V_186 | V_187 |
V_188 | V_189 |
V_190 | V_191 |
V_192 | V_193 |
V_194 | V_195 |
V_196 | V_156 |
V_197 | V_198 ) ;
F_7 ( ( V_199 | V_166 ) ,
V_2 -> V_78 + V_200 ) ;
F_7 ( ( V_201 | ( V_156 ) ) ,
V_2 -> V_78 + V_202 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_161 * V_162 = F_24 ( V_2 -> V_162 -> V_163 . V_164 ) ;
T_1 V_165 , V_166 , V_167 ;
int V_168 ;
if ( F_22 ( V_2 , V_169 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 1 ] , F_14 , 0 ,
L_66 , V_2 ) ;
if ( V_168 )
F_8 ( V_172 L_58
L_59 , V_2 -> V_32 , V_168 ) ;
}
if ( F_22 ( V_2 , V_173 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 2 ] , F_15 , 0 ,
L_67 , V_2 ) ;
if ( V_168 )
F_8 ( V_172 L_61
L_59 , V_2 -> V_32 , V_168 ) ;
}
V_168 = 0 ;
if ( F_22 ( V_2 , V_174 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 0 ] , F_17 , 0 ,
L_68 , V_2 ) ;
} else if ( F_22 ( V_2 , V_175 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 0 ] , F_17 , 0 ,
L_68 , V_2 ) ;
}
if ( V_168 )
F_8 ( V_172 L_63
L_59 , V_2 -> V_32 , V_168 ) ;
if ( F_22 ( V_2 , V_176 ) ) {
V_168 = F_25 ( V_162 -> V_170 . V_171 [ 3 ] , F_21 , 0 ,
L_69 , V_2 ) ;
if ( V_168 )
F_8 ( V_172 L_65
L_59 , V_2 -> V_32 , V_168 ) ;
}
F_7 ( ( V_177 |
V_178 |
V_179 ) , V_2 -> V_78 + V_180 ) ;
V_166 = ( V_117 |
V_203 |
V_118 |
V_119 |
V_121 |
V_122 |
V_181 ) ;
V_167 = ( V_120 |
V_204 ) ;
V_165 = F_6 ( V_2 -> V_11 + V_116 ) ;
V_165 |= V_166 ;
V_165 &= ~ V_167 ;
F_7 ( V_165 , V_2 -> V_11 + V_116 ) ;
F_7 ( ( V_135 | V_136 |
V_137 | V_138 |
V_139 | V_140 |
V_141 | V_142 |
V_143 | V_144 |
V_145 | V_146 ) ,
V_2 -> V_11 + V_133 ) ;
V_166 = ( V_182 | V_205 |
V_206 | V_207 |
V_208 |
V_209 | V_210 |
V_211 | V_212 |
V_213 |
V_214 | V_215 |
V_216 | V_196 |
V_197 | V_198 |
V_217 ) ;
#if 1
V_166 &= ~ ( V_209 | V_210 |
V_211 | V_212 ) ;
#endif
F_7 ( ( V_199 | V_166 ) ,
V_2 -> V_78 + V_200 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_4 * V_218 ;
V_218 = F_1 ( V_2 , V_2 -> V_6 ,
0 , V_219 ) ;
F_28 ( V_218 , 64 / sizeof( T_3 ) ) ;
V_218 = F_1 ( V_2 , V_2 -> V_6 ,
0 , V_220 ) ;
F_28 ( V_218 , 64 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_221 * V_222 )
{
F_27 ( V_2 ) ;
V_2 -> V_223 =
( F_30 ( V_2 -> V_162 -> V_163 . V_164 , L_70 , NULL )
!= NULL ) ;
V_2 -> V_125 = F_31 ( V_2 , V_222 ) ;
if ( V_2 -> V_224 == V_225 )
F_23 ( V_2 ) ;
else
F_26 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned long V_54 = V_2 -> V_11 ;
T_1 V_15 ;
if ( V_2 -> V_224 == V_225 ) {
return;
}
V_2 -> V_9 . V_21 = V_54 + V_226 ;
V_2 -> V_9 . V_227 = V_54 + V_228 ;
V_2 -> V_9 . V_229 = V_54 + V_230 ;
V_2 -> V_9 . V_231 = V_54 + V_232 ;
V_2 -> V_9 . V_233 = V_54 + V_234 ;
V_2 -> V_9 . V_235 = ( volatile unsigned long * )
( ( ( ( unsigned long ) & V_2 -> V_9 . V_236 [ 0 ] )
+ 63UL )
& ~ 63UL ) ;
V_2 -> V_9 . V_237 = ( unsigned long )
F_33 ( V_2 -> V_9 . V_235 ) ;
V_15 = F_6 ( V_2 -> V_9 . V_21 ) ;
V_15 &= ~ ( V_238 |
V_239 |
V_22 ) ;
V_15 |= V_240 ;
F_7 ( V_15 , V_2 -> V_9 . V_21 ) ;
V_2 -> V_9 . V_73 = 1 ;
}
static int F_34 ( struct V_1 * V_2 )
{
static const T_3 V_241 [] = { 0xc0000000 , 0x40000000 } ;
unsigned long V_16 , V_242 , V_243 ;
struct V_47 * V_47 = V_2 -> V_47 ;
int V_244 , V_168 ;
const T_3 * V_245 ;
T_3 V_246 ;
T_1 V_15 ;
V_245 = F_35 ( V_2 -> V_162 -> V_163 . V_164 , L_71 , NULL ) ;
if ( ! V_245 )
V_245 = V_241 ;
V_246 = V_245 [ 0 ] ;
switch ( V_245 [ 1 ] ) {
case 0x20000000 :
V_246 |= 0x1fffffff ;
V_244 = 64 ;
break;
case 0x40000000 :
V_246 |= 0x3fffffff ;
V_244 = 128 ;
break;
case 0x80000000 :
V_246 |= 0x7fffffff ;
V_244 = 128 ;
break;
default:
F_8 (KERN_ERR PFX L_72 ) ;
return - V_247 ;
}
V_47 -> V_52 = V_2 -> V_11 + V_248 ;
V_47 -> V_249 = V_2 -> V_11 + V_250 ;
V_47 -> V_251 = V_2 -> V_11 + V_252 ;
V_47 -> V_253 = V_47 -> V_251 + ( 0xa580UL - 0x0210UL ) ;
V_47 -> V_254 = V_2 -> V_11 + V_255 ;
V_47 -> V_256 = V_2 -> V_78 + 0x10000UL ;
V_15 = F_6 ( V_47 -> V_52 ) ;
V_15 |= V_57 ;
F_7 ( V_15 , V_47 -> V_52 ) ;
V_242 = V_58 , V_243 = V_59 ;
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
F_7 ( 0 , V_2 -> V_11 + V_242 + ( V_16 * 8UL ) ) ;
F_7 ( 0 , V_2 -> V_11 + V_243 + ( V_16 * 8UL ) ) ;
}
V_168 = F_36 ( V_47 , V_244 * 8 * 1024 , V_245 [ 0 ] , V_246 ,
V_2 -> V_257 ) ;
if ( V_168 ) {
F_8 (KERN_ERR PFX L_73 , err) ;
return V_168 ;
}
F_7 ( F_33 ( V_47 -> V_258 ) , V_47 -> V_249 ) ;
V_15 = F_6 ( V_47 -> V_52 ) ;
V_15 &= ~ ( V_259 | V_260 ) ;
switch ( V_244 ) {
case 64 :
V_15 |= V_261 ;
break;
case 128 :
V_15 |= V_262 ;
break;
}
V_15 |= V_263 ;
F_7 ( V_15 , V_47 -> V_52 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_1 V_165 ;
F_7 ( 5 , V_2 -> V_11 + V_264 ) ;
V_165 = F_6 ( V_2 -> V_11 + V_116 ) ;
V_165 |= 0xff ;
if ( V_2 -> V_224 == V_225 &&
V_2 -> V_265 >= 0x2 )
V_165 |= 0x3UL << V_266 ;
if ( ! F_30 ( V_2 -> V_162 -> V_163 . V_164 , L_74 , NULL ) )
V_165 |= V_267 ;
else
V_165 &= ~ V_267 ;
if ( V_2 -> V_224 == V_225 &&
V_2 -> V_265 <= 0x1 )
V_165 |= V_268 ;
else
V_165 &= ~ V_268 ;
if ( V_2 -> V_224 == V_225 )
V_165 |= ( V_269 |
V_270 |
V_271 ) ;
F_7 ( V_165 , V_2 -> V_11 + V_116 ) ;
V_165 = F_6 ( V_2 -> V_11 + V_272 ) ;
V_165 &= ~ ( V_273 |
V_274 |
V_275 ) ;
F_7 ( V_165 , V_2 -> V_11 + V_272 ) ;
if ( V_2 -> V_224 == V_225 ) {
V_165 = ( V_276 |
( 1 << V_277 ) |
V_278 |
V_279 |
V_280 ) ;
F_7 ( V_165 , V_2 -> V_11 + V_281 ) ;
}
}
static int F_38 ( struct V_1 * V_2 ,
struct V_161 * V_162 , T_3 V_282 ,
int V_224 )
{
const struct V_283 * V_284 ;
struct V_285 * V_286 = V_162 -> V_163 . V_164 ;
const char * V_287 ;
int V_168 ;
switch ( V_224 ) {
case V_225 :
V_287 = L_75 ;
break;
case V_288 :
V_287 = L_76 ;
break;
case V_289 :
default:
V_287 = L_77 ;
break;
}
V_284 = F_35 ( V_286 , L_78 , NULL ) ;
V_2 -> V_290 = V_291 ;
V_291 = V_2 ;
V_2 -> V_257 = - 1 ;
V_2 -> V_123 = & V_292 ;
V_2 -> V_293 = 8 ;
V_2 -> V_294 = V_295 ++ ;
V_2 -> V_282 = V_282 ;
V_2 -> V_162 = V_162 ;
V_2 -> V_224 = V_224 ;
V_2 -> V_265 = F_39 ( V_286 , L_79 , 0 ) ;
V_2 -> V_296 = F_39 ( V_286 , L_80 , 0 ) ;
V_2 -> V_11 = V_284 [ 0 ] . V_297 ;
V_2 -> V_78 = V_284 [ 1 ] . V_297 - 0x10000UL ;
if ( V_224 == V_225 )
V_2 -> V_298 = V_284 [ 3 ] . V_297 + 0x1a18UL ;
V_2 -> V_32 = V_286 -> V_299 ;
F_8 ( L_81 ,
V_2 -> V_32 , V_287 ,
V_2 -> V_265 , V_2 -> V_296 ) ;
F_37 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
V_168 = F_34 ( V_2 ) ;
if ( V_168 )
return V_168 ;
F_32 ( V_2 ) ;
F_29 ( V_2 , & V_162 -> V_163 ) ;
return 0 ;
}
static inline int F_42 ( T_3 V_300 , T_3 V_301 , int V_224 )
{
if ( V_224 == V_225 ) {
if ( V_300 == ( V_301 ^ 1 ) )
return 1 ;
return 0 ;
}
return ( V_300 == V_301 ) ;
}
static struct V_1 * F_43 ( T_3 V_282 , int V_224 )
{
struct V_1 * V_2 ;
for ( V_2 = V_291 ; V_2 ; V_2 = V_2 -> V_290 ) {
if ( F_42 ( V_2 -> V_282 , V_282 , V_224 ) )
return V_2 ;
}
return NULL ;
}
static int F_44 ( struct V_161 * V_162 , unsigned long V_224 )
{
struct V_285 * V_286 = V_162 -> V_163 . V_164 ;
struct V_1 * V_2 ;
struct V_47 * V_47 ;
T_3 V_282 ;
int V_168 ;
V_282 = F_39 ( V_286 , L_82 , 0xff ) ;
V_168 = - V_302 ;
V_2 = F_45 ( sizeof( * V_2 ) , V_303 ) ;
if ( ! V_2 ) {
F_8 (KERN_ERR PFX L_83 ) ;
goto V_304;
}
V_2 -> V_74 = F_43 ( V_282 , V_224 ) ;
V_47 = F_45 ( sizeof( struct V_47 ) , V_303 ) ;
if ( ! V_47 ) {
F_8 (KERN_ERR PFX L_84 ) ;
goto V_305;
}
V_2 -> V_47 = V_47 ;
if ( F_38 ( V_2 , V_162 , V_282 , V_224 ) )
goto V_306;
if ( V_2 -> V_74 )
V_2 -> V_74 -> V_74 = V_2 ;
F_46 ( & V_162 -> V_163 , V_2 ) ;
return 0 ;
V_306:
F_47 ( V_2 -> V_47 ) ;
V_305:
F_47 ( V_2 ) ;
V_304:
return V_168 ;
}
static int F_48 ( struct V_161 * V_162 )
{
const struct V_307 * V_308 ;
V_308 = F_49 ( V_309 , & V_162 -> V_163 ) ;
if ( ! V_308 )
return - V_247 ;
return F_44 ( V_162 , ( unsigned long ) V_308 -> V_61 ) ;
}
static int T_5 F_50 ( void )
{
return F_51 ( & V_310 ) ;
}
