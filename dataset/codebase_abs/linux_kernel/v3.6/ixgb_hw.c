static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = V_4 |
V_5 |
V_6 |
V_7 |
V_8 |
V_9 |
V_10 |
V_11 ;
#ifdef F_2
F_3 ( V_2 , V_12 , V_3 ) ;
#else
F_4 ( V_2 , V_12 , V_3 ) ;
#endif
F_5 ( V_13 ) ;
V_3 = F_6 ( V_2 , V_12 ) ;
#ifdef F_7
ASSERT ( ! ( V_3 & V_4 ) ) ;
#endif
if ( V_2 -> V_14 == V_15 ) {
V_3 =
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ;
F_4 ( V_2 , V_21 , V_3 ) ;
F_8 ( V_2 ) ;
}
if ( V_2 -> V_22 == V_23 )
F_9 ( V_2 ) ;
return V_3 ;
}
bool
F_10 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_24 ;
F_11 () ;
if ( V_2 -> V_25 ) {
F_12 ( L_1 ) ;
return false ;
}
V_2 -> V_25 = true ;
F_12 ( L_2 ) ;
F_4 ( V_2 , V_26 , 0xFFFFFFFF ) ;
F_4 ( V_2 , V_27 , F_6 ( V_2 , V_27 ) & ~ V_28 ) ;
F_4 ( V_2 , V_29 , F_6 ( V_2 , V_29 ) & ~ V_30 ) ;
F_13 ( V_2 ) ;
F_5 ( V_31 ) ;
F_12 ( L_3 ) ;
V_3 = F_1 ( V_2 ) ;
F_12 ( L_2 ) ;
F_4 ( V_2 , V_26 , 0xffffffff ) ;
V_24 = F_6 ( V_2 , V_32 ) ;
return V_3 & V_4 ;
}
static T_2
F_14 ( struct V_1 * V_2 )
{
T_1 V_33 ;
T_3 V_34 [ 5 ] ;
T_2 V_35 ;
F_11 () ;
for ( V_33 = 0 ; V_33 < 5 ; V_33 ++ ) {
V_34 [ V_33 ] = F_15 ( V_2 ,
V_36
+ V_33 , V_37 ,
V_38 ) ;
}
if ( V_34 [ 0 ] == 'I' &&
V_34 [ 1 ] == 'N' &&
V_34 [ 2 ] == 'T' &&
V_34 [ 3 ] == 'E' && V_34 [ 4 ] == 'L' ) {
V_35 = V_39 ;
} else {
V_35 = V_40 ;
}
return V_35 ;
}
static T_4
F_16 ( struct V_1 * V_2 )
{
T_4 V_22 ;
T_2 V_35 ;
F_11 () ;
switch ( V_2 -> V_41 ) {
case V_42 :
F_12 ( L_4 ) ;
V_22 = V_23 ;
break;
case V_43 :
V_35 = F_14 ( V_2 ) ;
if ( V_35 == V_39 ) {
F_12 ( L_5 ) ;
V_22 = V_44 ;
} else {
F_12 ( L_6 ) ;
V_22 = V_45 ;
}
break;
case V_46 :
F_12 ( L_7 ) ;
V_22 = V_47 ;
break;
case V_48 :
F_12 ( L_8 ) ;
V_35 = F_14 ( V_2 ) ;
if ( V_35 == V_39 ) {
F_12 ( L_5 ) ;
V_22 = V_44 ;
} else {
F_12 ( L_6 ) ;
V_22 = V_45 ;
}
break;
default:
F_12 ( L_9 ) ;
V_22 = V_49 ;
break;
}
if ( V_2 -> V_14 == V_15 )
V_22 = V_50 ;
return V_22 ;
}
bool
F_17 ( struct V_1 * V_2 )
{
T_1 V_33 ;
T_1 V_3 ;
bool V_51 ;
F_11 () ;
F_12 ( L_3 ) ;
V_3 = F_1 ( V_2 ) ;
F_12 ( L_10 ) ;
#ifdef F_2
F_3 ( V_2 , V_21 , V_52 ) ;
#else
F_4 ( V_2 , V_21 , V_52 ) ;
#endif
F_5 ( V_53 ) ;
if ( ! F_18 ( V_2 ) )
return false ;
V_2 -> V_41 = F_19 ( V_2 ) ;
V_2 -> V_22 = F_16 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( ! F_21 ( V_2 -> V_54 ) ) {
F_12 ( L_11 ) ;
return ( false ) ;
}
V_2 -> V_25 = false ;
F_22 ( V_2 ) ;
F_12 ( L_12 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ )
F_23 ( V_2 , V_56 , V_33 , 0 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
V_51 = F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
return V_51 ;
}
static void
F_20 ( struct V_1 * V_2 )
{
T_1 V_33 ;
F_11 () ;
if ( ! F_21 ( V_2 -> V_54 ) ) {
F_28 ( V_2 , V_2 -> V_54 ) ;
F_12 ( L_13 ,
V_2 -> V_54 ) ;
} else {
F_12 ( L_14 ) ;
F_12 ( L_15 , V_2 -> V_54 ) ;
F_29 ( V_2 , V_2 -> V_54 , 0 ) ;
}
F_12 ( L_16 ) ;
for ( V_33 = 1 ; V_33 < V_57 ; V_33 ++ ) {
F_23 ( V_2 , V_58 , ( ( V_33 << 1 ) + 1 ) , 0 ) ;
F_23 ( V_2 , V_58 , ( V_33 << 1 ) , 0 ) ;
}
}
void
F_30 ( struct V_1 * V_2 ,
T_5 * V_59 ,
T_1 V_60 ,
T_1 V_61 )
{
T_1 V_62 ;
T_1 V_33 ;
T_1 V_63 = 1 ;
T_5 * V_64 ;
F_11 () ;
V_2 -> V_65 = V_60 ;
F_12 ( L_16 ) ;
for ( V_33 = V_63 ; V_33 < V_57 ; V_33 ++ ) {
F_23 ( V_2 , V_58 , ( V_33 << 1 ) , 0 ) ;
F_23 ( V_2 , V_58 , ( ( V_33 << 1 ) + 1 ) , 0 ) ;
}
F_12 ( L_17 ) ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ )
F_23 ( V_2 , V_56 , V_33 , 0 ) ;
V_64 = V_59 ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
F_12 ( L_18 ) ;
F_12 ( L_19 , V_33 , V_64 ) ;
if ( V_63 < V_57 ) {
F_29 ( V_2 , V_64 , V_63 ) ;
F_12 ( L_20 , V_33 ) ;
V_63 ++ ;
} else {
V_62 = F_31 ( V_2 , V_64 ) ;
F_12 ( L_21 , V_62 ) ;
F_32 ( V_2 , V_62 ) ;
}
V_64 += V_66 + V_61 ;
}
F_12 ( L_22 ) ;
}
static T_1
F_31 ( struct V_1 * V_2 ,
T_5 * V_67 )
{
T_1 V_62 = 0 ;
F_11 () ;
switch ( V_2 -> V_68 ) {
case 0 :
V_62 =
( ( V_67 [ 4 ] >> 4 ) | ( ( ( T_3 ) V_67 [ 5 ] ) << 4 ) ) ;
break;
case 1 :
V_62 =
( ( V_67 [ 4 ] >> 3 ) | ( ( ( T_3 ) V_67 [ 5 ] ) << 5 ) ) ;
break;
case 2 :
V_62 =
( ( V_67 [ 4 ] >> 2 ) | ( ( ( T_3 ) V_67 [ 5 ] ) << 6 ) ) ;
break;
case 3 :
V_62 = ( ( V_67 [ 4 ] ) | ( ( ( T_3 ) V_67 [ 5 ] ) << 8 ) ) ;
break;
default:
F_12 ( L_23 ) ;
ASSERT ( 0 ) ;
break;
}
V_62 &= 0xFFF ;
return V_62 ;
}
static void
F_32 ( struct V_1 * V_2 ,
T_1 V_62 )
{
T_1 V_69 , V_70 ;
T_1 V_71 ;
V_70 = ( V_62 >> 5 ) & 0x7F ;
V_69 = V_62 & 0x1F ;
V_71 = F_33 ( V_2 , V_56 , V_70 ) ;
V_71 |= ( 1 << V_69 ) ;
F_23 ( V_2 , V_56 , V_70 , V_71 ) ;
}
void
F_29 ( struct V_1 * V_2 ,
T_5 * V_72 ,
T_1 V_73 )
{
T_1 V_74 , V_75 ;
F_11 () ;
V_74 = ( ( T_1 ) V_72 [ 0 ] |
( ( T_1 ) V_72 [ 1 ] << 8 ) |
( ( T_1 ) V_72 [ 2 ] << 16 ) |
( ( T_1 ) V_72 [ 3 ] << 24 ) ) ;
V_75 = ( ( T_1 ) V_72 [ 4 ] |
( ( T_1 ) V_72 [ 5 ] << 8 ) |
V_76 ) ;
F_23 ( V_2 , V_58 , ( V_73 << 1 ) , V_74 ) ;
F_23 ( V_2 , V_58 , ( ( V_73 << 1 ) + 1 ) , V_75 ) ;
}
void
F_34 ( struct V_1 * V_2 ,
T_1 V_77 ,
T_1 V_78 )
{
F_23 ( V_2 , V_79 , V_77 , V_78 ) ;
}
static void
F_24 ( struct V_1 * V_2 )
{
T_1 V_77 ;
for ( V_77 = 0 ; V_77 < V_80 ; V_77 ++ )
F_23 ( V_2 , V_79 , V_77 , 0 ) ;
}
static bool
F_26 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_81 = 0 ;
bool V_51 = true ;
F_11 () ;
V_3 = F_6 ( V_2 , V_12 ) ;
V_3 &= ~ ( V_82 | V_83 ) ;
switch ( V_2 -> V_84 . type ) {
case V_85 :
V_3 |= ( V_86 ) ;
break;
case V_87 :
V_3 |= ( V_82 ) ;
break;
case V_88 :
V_3 |= ( V_83 ) ;
V_81 = V_2 -> V_84 . V_89 ;
break;
case V_90 :
V_3 |= ( V_82 | V_83 ) ;
V_81 = V_2 -> V_84 . V_89 ;
break;
default:
F_12 ( L_24 ) ;
ASSERT ( 0 ) ;
break;
}
F_4 ( V_2 , V_12 , V_3 ) ;
if ( V_81 != 0 )
F_4 ( V_2 , V_91 , V_81 ) ;
if ( ! ( V_2 -> V_84 . type & V_88 ) ) {
F_4 ( V_2 , V_92 , 0 ) ;
F_4 ( V_2 , V_93 , 0 ) ;
} else {
if ( V_2 -> V_84 . V_94 ) {
F_4 ( V_2 , V_92 ,
( V_2 -> V_84 . V_95 | V_96 ) ) ;
} else {
F_4 ( V_2 , V_92 , V_2 -> V_84 . V_95 ) ;
}
F_4 ( V_2 , V_93 , V_2 -> V_84 . V_97 ) ;
}
return V_51 ;
}
static T_3
F_15 ( struct V_1 * V_2 ,
T_1 V_98 ,
T_1 V_99 ,
T_1 V_100 )
{
T_1 V_33 ;
T_1 V_101 ;
T_1 V_102 = 0 ;
ASSERT ( V_98 <= V_103 ) ;
ASSERT ( V_99 <= V_104 ) ;
ASSERT ( V_100 <= V_105 ) ;
V_102 = ( ( V_98 << V_106 ) |
( V_100 << V_107 ) |
( V_99 << V_108 ) |
( V_109 | V_110 ) ) ;
F_4 ( V_2 , V_111 , V_102 ) ;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ )
{
F_35 ( 10 ) ;
V_102 = F_6 ( V_2 , V_111 ) ;
if ( ( V_102 & V_110 ) == 0 )
break;
}
ASSERT ( ( V_102 & V_110 ) == 0 ) ;
V_102 = ( ( V_98 << V_106 ) |
( V_100 << V_107 ) |
( V_99 << V_108 ) |
( V_112 | V_110 ) ) ;
F_4 ( V_2 , V_111 , V_102 ) ;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ )
{
F_35 ( 10 ) ;
V_102 = F_6 ( V_2 , V_111 ) ;
if ( ( V_102 & V_110 ) == 0 )
break;
}
ASSERT ( ( V_102 & V_110 ) == 0 ) ;
V_101 = F_6 ( V_2 , V_113 ) ;
V_101 >>= V_114 ;
return ( ( T_3 ) V_101 ) ;
}
static void
F_36 ( struct V_1 * V_2 ,
T_1 V_98 ,
T_1 V_99 ,
T_1 V_100 ,
T_3 V_101 )
{
T_1 V_33 ;
T_1 V_102 = 0 ;
ASSERT ( V_98 <= V_103 ) ;
ASSERT ( V_99 <= V_104 ) ;
ASSERT ( V_100 <= V_105 ) ;
F_4 ( V_2 , V_113 , ( T_1 ) V_101 ) ;
V_102 = ( ( V_98 << V_106 ) |
( V_100 << V_107 ) |
( V_99 << V_108 ) |
( V_109 | V_110 ) ) ;
F_4 ( V_2 , V_111 , V_102 ) ;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ )
{
F_35 ( 10 ) ;
V_102 = F_6 ( V_2 , V_111 ) ;
if ( ( V_102 & V_110 ) == 0 )
break;
}
ASSERT ( ( V_102 & V_110 ) == 0 ) ;
V_102 = ( ( V_98 << V_106 ) |
( V_100 << V_107 ) |
( V_99 << V_108 ) |
( V_115 | V_110 ) ) ;
F_4 ( V_2 , V_111 , V_102 ) ;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ )
{
F_35 ( 10 ) ;
V_102 = F_6 ( V_2 , V_111 ) ;
if ( ( V_102 & V_110 ) == 0 )
break;
}
ASSERT ( ( V_102 & V_110 ) == 0 ) ;
}
void
F_27 ( struct V_1 * V_2 )
{
T_1 V_116 ;
T_1 V_117 ;
F_11 () ;
V_117 = F_6 ( V_2 , V_118 ) ;
V_116 = F_6 ( V_2 , V_119 ) ;
if ( ( V_117 & V_120 ) &&
( V_116 & V_121 ) ) {
V_2 -> V_122 = true ;
} else if ( ! ( V_117 & V_120 ) &&
( V_116 & V_121 ) ) {
F_12 ( L_25 ) ;
V_2 -> V_122 = F_37 ( V_2 ) ;
} else {
V_2 -> V_122 = F_37 ( V_2 ) ;
}
}
bool F_38 ( struct V_1 * V_2 )
{
T_1 V_123 , V_124 ;
bool V_125 = false ;
if ( V_2 -> V_22 == V_23 ) {
V_123 = F_6 ( V_2 , V_126 ) ;
V_124 = F_6 ( V_2 , V_127 ) ;
if ( ( V_2 -> V_128 + 250 < V_123 )
|| ( V_2 -> V_129 + 250 < V_124 ) ) {
F_12 ( L_26 ) ;
V_125 = true ;
}
V_2 -> V_128 = V_123 ;
V_2 -> V_129 = V_124 ;
}
return V_125 ;
}
static void
F_25 ( struct V_1 * V_2 )
{
volatile T_1 V_130 ;
F_11 () ;
if ( V_2 -> V_25 ) {
F_12 ( L_27 ) ;
return;
}
V_130 = F_6 ( V_2 , V_131 ) ;
V_130 = F_6 ( V_2 , V_132 ) ;
V_130 = F_6 ( V_2 , V_133 ) ;
V_130 = F_6 ( V_2 , V_134 ) ;
V_130 = F_6 ( V_2 , V_135 ) ;
V_130 = F_6 ( V_2 , V_136 ) ;
V_130 = F_6 ( V_2 , V_137 ) ;
V_130 = F_6 ( V_2 , V_138 ) ;
V_130 = F_6 ( V_2 , V_139 ) ;
V_130 = F_6 ( V_2 , V_140 ) ;
V_130 = F_6 ( V_2 , V_141 ) ;
V_130 = F_6 ( V_2 , V_142 ) ;
V_130 = F_6 ( V_2 , V_143 ) ;
V_130 = F_6 ( V_2 , V_144 ) ;
V_130 = F_6 ( V_2 , V_145 ) ;
V_130 = F_6 ( V_2 , V_146 ) ;
V_130 = F_6 ( V_2 , V_147 ) ;
V_130 = F_6 ( V_2 , V_148 ) ;
V_130 = F_6 ( V_2 , V_149 ) ;
V_130 = F_6 ( V_2 , V_150 ) ;
V_130 = F_6 ( V_2 , V_151 ) ;
V_130 = F_6 ( V_2 , V_152 ) ;
V_130 = F_6 ( V_2 , V_153 ) ;
V_130 = F_6 ( V_2 , V_154 ) ;
V_130 = F_6 ( V_2 , V_155 ) ;
V_130 = F_6 ( V_2 , V_156 ) ;
V_130 = F_6 ( V_2 , V_157 ) ;
V_130 = F_6 ( V_2 , V_158 ) ;
V_130 = F_6 ( V_2 , V_159 ) ;
V_130 = F_6 ( V_2 , V_160 ) ;
V_130 = F_6 ( V_2 , V_161 ) ;
V_130 = F_6 ( V_2 , V_162 ) ;
V_130 = F_6 ( V_2 , V_163 ) ;
V_130 = F_6 ( V_2 , V_164 ) ;
V_130 = F_6 ( V_2 , V_165 ) ;
V_130 = F_6 ( V_2 , V_166 ) ;
V_130 = F_6 ( V_2 , V_167 ) ;
V_130 = F_6 ( V_2 , V_168 ) ;
V_130 = F_6 ( V_2 , V_169 ) ;
V_130 = F_6 ( V_2 , V_170 ) ;
V_130 = F_6 ( V_2 , V_171 ) ;
V_130 = F_6 ( V_2 , V_172 ) ;
V_130 = F_6 ( V_2 , V_173 ) ;
V_130 = F_6 ( V_2 , V_174 ) ;
V_130 = F_6 ( V_2 , V_175 ) ;
V_130 = F_6 ( V_2 , V_176 ) ;
V_130 = F_6 ( V_2 , V_177 ) ;
V_130 = F_6 ( V_2 , V_178 ) ;
V_130 = F_6 ( V_2 , V_179 ) ;
V_130 = F_6 ( V_2 , V_127 ) ;
V_130 = F_6 ( V_2 , V_126 ) ;
V_130 = F_6 ( V_2 , V_180 ) ;
V_130 = F_6 ( V_2 , V_181 ) ;
V_130 = F_6 ( V_2 , V_182 ) ;
V_130 = F_6 ( V_2 , V_183 ) ;
V_130 = F_6 ( V_2 , V_184 ) ;
V_130 = F_6 ( V_2 , V_185 ) ;
V_130 = F_6 ( V_2 , V_186 ) ;
V_130 = F_6 ( V_2 , V_187 ) ;
V_130 = F_6 ( V_2 , V_188 ) ;
}
void
F_39 ( struct V_1 * V_2 )
{
T_1 V_189 = F_6 ( V_2 , V_12 ) ;
V_189 &= ~ V_11 ;
F_4 ( V_2 , V_12 , V_189 ) ;
}
void
F_40 ( struct V_1 * V_2 )
{
T_1 V_189 = F_6 ( V_2 , V_12 ) ;
V_189 |= V_11 ;
F_4 ( V_2 , V_12 , V_189 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
T_1 V_116 ;
V_116 = F_6 ( V_2 , V_119 ) ;
V_2 -> V_190 . type = ( V_116 & V_191 ) ?
V_192 : V_193 ;
if ( V_2 -> V_190 . type == V_193 ) {
V_2 -> V_190 . V_194 = ( V_116 & V_195 ) ?
V_196 : V_197 ;
} else {
switch ( V_116 & V_198 ) {
case V_199 :
V_2 -> V_190 . V_194 = V_196 ;
break;
case V_200 :
V_2 -> V_190 . V_194 = V_201 ;
break;
case V_202 :
V_2 -> V_190 . V_194 = V_203 ;
break;
default:
V_2 -> V_190 . V_194 = V_204 ;
break;
}
}
V_2 -> V_190 . V_205 = ( V_116 & V_206 ) ?
V_207 : V_208 ;
}
static bool
F_21 ( T_5 * V_209 )
{
bool V_210 = true ;
F_11 () ;
if ( F_41 ( V_209 ) ) {
F_12 ( L_28 ) ;
V_210 = false ;
}
else if ( F_42 ( V_209 ) ) {
F_12 ( L_29 ) ;
V_210 = false ;
}
else if ( F_43 ( V_209 ) ) {
F_12 ( L_30 ) ;
V_210 = false ;
}
return V_210 ;
}
static bool
F_37 ( struct V_1 * V_2 )
{
bool V_211 = false ;
T_5 V_212 = V_213 ;
T_5 V_214 = V_213 ;
do {
F_4 ( V_2 , V_12 ,
F_6 ( V_2 , V_12 ) | V_215 ) ;
do {
F_35 ( V_216 ) ;
V_211 =
( ( F_6 ( V_2 , V_119 ) & V_121 )
&& ( F_6 ( V_2 , V_118 ) &
V_120 ) ) ? true : false ;
} while ( ! V_211 && -- V_212 );
} while ( ! V_211 && -- V_214 );
return V_211 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 == V_23 ) {
T_3 V_217 ;
F_36 ( V_2 ,
V_218 ,
V_37 ,
V_38 ,
V_219 ) ;
V_217 = F_15 ( V_2 ,
V_218 ,
V_37 ,
V_38 ) ;
}
}
static void
F_8 ( struct V_1 * V_2 )
{
T_1 V_220 = F_6 ( V_2 , V_12 ) ;
V_220 &= ~ V_10 ;
V_220 |= V_9 ;
F_4 ( V_2 , V_12 , V_220 ) ;
F_13 ( V_2 ) ;
F_5 ( V_221 ) ;
F_36 ( V_2 ,
V_222 ,
V_223 ,
V_224 ,
V_225 ) ;
F_15 ( V_2 ,
V_222 ,
V_223 ,
V_224 ) ;
F_15 ( V_2 ,
V_222 ,
V_223 ,
V_224 ) ;
F_36 ( V_2 ,
V_226 ,
V_223 ,
V_224 ,
V_227 ) ;
F_15 ( V_2 ,
V_226 ,
V_223 ,
V_224 ) ;
F_15 ( V_2 ,
V_226 ,
V_223 ,
V_224 ) ;
F_5 ( V_221 ) ;
}
