static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 (
enum V_6 V_7 ,
T_1 V_8 )
{
int V_9 ;
for ( V_9 = 1 ; V_9 < F_4 ( V_10 ) ; V_9 ++ )
if ( ( V_10 [ V_9 ] . V_7 == V_7 ) &&
( V_10 [ V_9 ] . V_8 == V_8 ) ) {
return & V_10 [ V_9 ] ;
}
return & V_10 [ 0 ] ;
}
static void F_5 ( struct V_11 * V_12 ,
unsigned long V_13 , int V_14 )
{
struct V_5 * V_15 = V_12 -> V_16 ;
if ( V_15 -> V_17 . V_18 == 1 ) {
F_6 ( V_13 , V_12 -> V_19 +
V_20 + 4 * V_14 ) ;
} else {
F_6 ( V_13 , V_12 -> V_19 +
V_21 - 0x14 * V_14 ) ;
if ( V_15 -> V_8 == V_22 ) {
T_1 V_23 = V_12 -> V_24 -> V_25 *
V_12 -> V_24 -> V_26 ;
F_6 ( V_13 + V_23 , V_12 -> V_19 +
V_27 - 0x14 * V_14 ) ;
F_6 ( V_13 + ( ( 5 * V_23 ) / 4 ) , V_12 -> V_19 +
V_28 - 0x14 * V_14 ) ;
}
}
}
static void F_7 ( struct V_11 * V_12 )
{
F_8 ( V_12 -> V_29 ) ;
F_8 ( V_12 -> V_30 ) ;
F_6 ( 0 , V_12 -> V_31 + V_32 ) ;
F_6 ( 0 , V_12 -> V_19 + V_33 ) ;
}
static int F_9 ( struct V_34 * V_24 )
{
struct V_35 * V_36 = F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
int V_39 ;
T_1 V_40 ;
if ( V_12 -> V_24 )
return - V_41 ;
V_39 = F_11 ( V_12 -> V_29 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_11 ( V_12 -> V_30 ) ;
if ( V_39 < 0 )
goto V_42;
V_40 = V_43 | V_44 | V_45 |
F_12 ( 0 ) ;
V_12 -> V_40 = V_40 ;
F_6 ( V_12 -> V_40 , V_12 -> V_31 + V_32 ) ;
V_12 -> V_24 = V_24 ;
V_12 -> V_46 = 0 ;
F_13 ( V_24 -> V_37 , L_1 ,
V_24 -> V_47 ) ;
return 0 ;
V_42:
F_8 ( V_12 -> V_29 ) ;
return V_39 ;
}
static void F_14 ( struct V_34 * V_24 )
{
struct V_35 * V_36 = F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
F_15 ( V_24 != V_12 -> V_24 ) ;
F_13 ( V_24 -> V_37 , L_2 ,
V_24 -> V_47 ) ;
F_7 ( V_12 ) ;
V_12 -> V_24 = NULL ;
}
static int F_16 ( struct V_48 * V_49 ,
const struct V_50 * V_51 ,
unsigned int * V_52 , unsigned int * V_53 ,
unsigned int V_54 [] , void * V_55 [] )
{
struct V_34 * V_24 = F_17 ( V_49 ) ;
struct V_35 * V_36 = F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
F_18 ( V_24 -> V_37 , L_3 , * V_52 , V_54 [ 0 ] ) ;
if ( V_51 != NULL )
return - V_56 ;
V_55 [ 0 ] = V_12 -> V_57 ;
V_54 [ 0 ] = V_24 -> V_58 ;
if ( 0 == * V_52 )
* V_52 = 32 ;
if ( ! * V_53 &&
V_54 [ 0 ] * * V_52 > V_59 * 1024 * 1024 )
* V_52 = ( V_59 * 1024 * 1024 ) / V_54 [ 0 ] ;
* V_53 = 1 ;
return 0 ;
}
static int F_19 ( struct V_60 * V_61 )
{
struct V_34 * V_24 = F_17 ( V_61 -> V_48 ) ;
int V_39 = 0 ;
F_18 ( V_24 -> V_37 , L_4 , V_62 ,
V_61 , F_20 ( V_61 , 0 ) , F_21 ( V_61 , 0 ) ) ;
#ifdef F_22
memset ( ( void * ) F_20 ( V_61 , 0 ) ,
0xaa , F_21 ( V_61 , 0 ) ) ;
#endif
F_23 ( V_61 , 0 , V_24 -> V_58 ) ;
if ( F_20 ( V_61 , 0 ) &&
F_21 ( V_61 , 0 ) > F_24 ( V_61 , 0 ) ) {
V_39 = - V_63 ;
goto V_64;
}
return 0 ;
V_64:
return V_39 ;
}
static void F_25 ( struct V_60 * V_61 )
{
struct V_34 * V_24 = F_17 ( V_61 -> V_48 ) ;
struct V_35 * V_36 =
F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
struct V_1 * V_65 = F_2 ( V_61 , struct V_1 , V_61 ) ;
unsigned long V_66 ;
F_18 ( V_24 -> V_37 , L_4 , V_62 ,
V_61 , F_20 ( V_61 , 0 ) , F_21 ( V_61 , 0 ) ) ;
F_26 ( & V_12 -> V_67 , V_66 ) ;
F_27 ( & V_65 -> V_4 . V_68 , & V_12 -> V_69 ) ;
F_28 ( & V_12 -> V_67 , V_66 ) ;
}
static void F_29 ( struct V_34 * V_24 ,
int V_70 )
{
struct V_35 * V_36 =
F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
struct V_5 * V_15 = V_12 -> V_16 ;
F_6 ( ( V_12 -> V_71 << 16 ) | V_12 -> V_72 ,
V_12 -> V_19 + V_73 ) ;
F_6 ( V_15 -> V_17 . V_74 ,
V_12 -> V_19 + V_75 ) ;
if ( V_15 -> V_17 . V_18 == 1 ) {
F_6 ( ( V_24 -> V_26 << 16 ) | V_24 -> V_25 ,
V_12 -> V_19 + V_76 ) ;
F_6 ( V_70 ,
V_12 -> V_19 + V_77 ) ;
F_6 ( V_15 -> V_17 . V_78 ,
V_12 -> V_19 + V_79 ) ;
} else {
F_6 ( ( V_24 -> V_26 << 16 ) | V_24 -> V_25 ,
V_12 -> V_19 + V_80 ) ;
}
F_6 ( V_15 -> V_17 . V_81 , V_12 -> V_19 + V_82 ) ;
}
static void F_30 ( struct V_11 * V_12 )
{
int V_83 ;
for ( V_83 = V_84 ; V_83 <= V_85 ; V_83 ++ ) {
unsigned char * V_86 = V_12 -> V_87 [ V_83 ] . V_86 ;
int V_88 = V_12 -> V_87 [ V_83 ] . V_88 ;
unsigned int V_89 [ 2 ] = { 0 , 0 } ;
unsigned int V_90 = 0 ;
int V_9 ;
if ( V_88 == 0 )
continue;
for ( V_9 = V_91 - 1 ; V_9 >= 0 ; V_9 -- ) {
int V_92 ;
V_92 = V_9 > 9 ? 1 : 0 ;
V_89 [ V_92 ] = ( V_89 [ V_92 ] << V_93 ) |
( V_86 [ V_9 ] & ( V_94 - 1 ) ) ;
if ( V_9 == 5 || V_9 == 15 )
V_89 [ V_92 ] <<= 1 ;
V_90 = ( V_90 << 1 ) | ( V_86 [ V_9 ] >> V_93 ) ;
}
V_90 |= F_31 ( V_88 ) ;
if ( V_12 -> V_87 [ V_83 ] . V_95 == V_96 )
V_90 |= V_97 ;
if ( V_12 -> V_16 -> V_17 . V_18 == 1 ) {
if ( V_83 == V_84 ) {
F_6 ( V_89 [ 0 ] , V_12 -> V_19 +
V_98 ) ;
F_6 ( V_89 [ 1 ] , V_12 -> V_19 +
V_99 ) ;
F_6 ( V_90 , V_12 -> V_19 +
V_100 ) ;
} else {
F_6 ( V_89 [ 0 ] , V_12 -> V_19 +
V_101 ) ;
F_6 ( V_89 [ 1 ] , V_12 -> V_19 +
V_102 ) ;
F_6 ( V_90 , V_12 -> V_19 +
V_103 ) ;
}
} else {
if ( V_83 == V_84 ) {
F_6 ( V_89 [ 0 ] , V_12 -> V_19 +
V_104 ) ;
F_6 ( V_89 [ 1 ] , V_12 -> V_19 +
V_105 ) ;
F_6 ( V_90 , V_12 -> V_19 +
V_106 ) ;
} else {
F_6 ( V_89 [ 0 ] , V_12 -> V_19 +
V_107 ) ;
F_6 ( V_89 [ 1 ] , V_12 -> V_19 +
V_108 ) ;
F_6 ( V_90 , V_12 -> V_19 +
V_109 ) ;
}
}
}
}
static int F_32 ( struct V_48 * V_110 , unsigned int V_52 )
{
struct V_34 * V_24 = F_17 ( V_110 ) ;
struct V_35 * V_36 =
F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
struct V_5 * V_15 = V_12 -> V_16 ;
struct V_60 * V_61 ;
struct V_1 * V_65 ;
unsigned long V_13 ;
int V_70 ;
unsigned long V_66 ;
if ( V_52 < 2 )
return - V_63 ;
F_26 ( & V_12 -> V_67 , V_66 ) ;
V_65 = F_33 ( & V_12 -> V_69 , struct V_1 ,
V_4 . V_68 ) ;
V_65 -> V_4 . V_14 = 0 ;
V_61 = & V_65 -> V_61 ;
V_13 = F_34 ( V_61 , 0 ) ;
F_5 ( V_12 , V_13 , V_65 -> V_4 . V_14 ) ;
F_35 ( V_12 -> V_69 . V_111 , & V_12 -> V_112 ) ;
V_65 = F_33 ( & V_12 -> V_69 , struct V_1 ,
V_4 . V_68 ) ;
V_65 -> V_4 . V_14 = 1 ;
V_61 = & V_65 -> V_61 ;
V_13 = F_34 ( V_61 , 0 ) ;
F_5 ( V_12 , V_13 , V_65 -> V_4 . V_14 ) ;
F_35 ( V_12 -> V_69 . V_111 , & V_12 -> V_112 ) ;
V_70 = F_36 ( V_24 -> V_26 ,
V_24 -> V_113 -> V_114 ) ;
if ( V_70 < 0 ) {
F_28 ( & V_12 -> V_67 , V_66 ) ;
return V_70 ;
}
V_12 -> V_115 = V_24 -> V_25 * V_70 ;
V_12 -> V_116 = F_37 ( V_36 -> V_117 . V_118 ,
V_12 -> V_115 ,
& V_12 -> V_119 , V_120 ) ;
if ( ! V_12 -> V_116 ) {
F_28 ( & V_12 -> V_67 , V_66 ) ;
return - V_121 ;
}
V_12 -> V_122 [ 0 ] . V_123 = true ;
F_27 ( & V_12 -> V_122 [ 0 ] . V_68 ,
& V_12 -> V_123 ) ;
V_12 -> V_122 [ 1 ] . V_123 = true ;
F_27 ( & V_12 -> V_122 [ 1 ] . V_68 ,
& V_12 -> V_123 ) ;
F_30 ( V_12 ) ;
F_29 ( V_24 , V_70 ) ;
if ( V_15 -> V_17 . V_18 == 1 ) {
F_6 ( V_124 |
V_125 |
V_15 -> V_17 . V_7 |
V_15 -> V_17 . V_8 |
V_126 |
V_127 |
F_38 ( 0 ) |
F_39 ( 0 ) ,
V_12 -> V_19 + V_33 ) ;
} else {
F_6 ( V_128 |
V_125 |
V_15 -> V_17 . V_7 |
V_15 -> V_17 . V_8 |
V_129 |
F_40 ( 0 ) |
F_39 ( 0 ) ,
V_12 -> V_19 + V_33 ) ;
}
F_28 ( & V_12 -> V_67 , V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_48 * V_110 )
{
struct V_34 * V_24 = F_17 ( V_110 ) ;
struct V_35 * V_36 =
F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
struct V_5 * V_15 = V_12 -> V_16 ;
unsigned long V_66 ;
void * V_130 ;
T_1 V_131 ;
F_26 ( & V_12 -> V_67 , V_66 ) ;
V_131 = F_42 ( V_12 -> V_19 + V_33 ) ;
if ( V_15 -> V_17 . V_18 == 1 ) {
F_6 ( V_131 & ~ V_124 ,
V_12 -> V_19 + V_33 ) ;
} else {
F_6 ( V_131 & ~ V_128 ,
V_12 -> V_19 + V_33 ) ;
}
F_43 ( & V_12 -> V_69 ) ;
F_43 ( & V_12 -> V_112 ) ;
F_43 ( & V_12 -> V_123 ) ;
V_130 = V_12 -> V_116 ;
V_12 -> V_116 = NULL ;
F_28 ( & V_12 -> V_67 , V_66 ) ;
F_44 ( V_36 -> V_117 . V_118 ,
V_12 -> V_115 , V_130 , V_12 -> V_119 ) ;
return 0 ;
}
static int F_45 ( struct V_48 * V_110 ,
struct V_34 * V_24 )
{
V_110 -> type = V_132 ;
V_110 -> V_133 = V_134 | V_135 ;
V_110 -> V_136 = V_24 ;
V_110 -> V_137 = & V_138 ;
V_110 -> V_139 = & V_140 ;
V_110 -> V_141 = sizeof( struct V_1 ) ;
V_110 -> V_142 = V_143 ;
return F_46 ( V_110 ) ;
}
static int F_47 ( struct V_11 * V_12 )
{
T_1 V_131 ;
int V_52 = 0 ;
V_131 = F_42 ( V_12 -> V_19 + V_33 ) ;
F_6 ( V_144 , V_12 -> V_19 + V_33 ) ;
while ( V_52 ++ < 100 ) {
if ( ! ( F_42 ( V_12 -> V_19 + V_33 ) & V_144 ) )
return 0 ;
F_48 () ;
F_49 ( 1 ) ;
}
return - V_145 ;
}
static int F_50 ( struct V_34 * V_24 )
{
struct V_146 * V_147 = F_51 ( V_24 ) ;
struct V_35 * V_36 = F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
struct V_148 V_17 = { . type = V_149 ,} ;
unsigned long V_150 ;
int V_39 ;
int V_70 ;
T_1 V_40 = V_12 -> V_40 ;
V_39 = F_52 ( V_147 , V_151 , V_152 , & V_17 ) ;
if ( ! V_39 ) {
V_150 = F_53 ( & V_17 , V_153 ) ;
if ( ! V_150 ) {
F_54 ( V_24 -> V_37 ,
L_5 ,
V_17 . V_66 , V_153 ) ;
return - V_63 ;
}
} else if ( V_39 != - V_154 ) {
return V_39 ;
} else {
V_150 = V_153 ;
}
if ( ( V_150 & V_155 ) &&
( V_150 & V_156 ) ) {
if ( V_12 -> V_157 & V_158 )
V_150 &= ~ V_156 ;
else
V_150 &= ~ V_155 ;
}
if ( ( V_150 & V_159 ) &&
( V_150 & V_160 ) ) {
if ( V_12 -> V_157 & V_161 )
V_150 &= ~ V_160 ;
else
V_150 &= ~ V_159 ;
}
V_17 . V_66 = V_150 ;
V_39 = F_52 ( V_147 , V_151 , V_162 , & V_17 ) ;
if ( V_39 < 0 && V_39 != - V_154 ) {
F_18 ( V_24 -> V_37 , L_6 ,
V_150 , V_39 ) ;
return V_39 ;
}
V_40 = ( V_40 & ~ V_163 ) | V_12 -> V_16 -> V_17 . V_40 ;
if ( V_150 & V_159 )
V_40 |= V_164 ;
if ( V_150 & V_165 )
V_40 |= V_166 ;
if ( V_150 & V_155 )
V_40 |= V_167 ;
if ( V_12 -> V_157 & V_168 )
V_40 |= V_169 ;
if ( V_12 -> V_157 & V_170 )
V_40 |= V_171 ;
if ( V_12 -> V_157 & V_172 )
V_40 |= V_173 ;
if ( V_12 -> V_157 & V_174 )
V_40 |= V_175 ;
if ( V_12 -> V_157 & V_176 )
V_40 |= V_177 ;
V_12 -> V_40 = V_40 ;
V_70 = F_36 ( V_24 -> V_26 ,
V_24 -> V_113 -> V_114 ) ;
if ( V_70 < 0 )
return V_70 ;
V_39 = F_47 ( V_12 ) ;
if ( V_39 )
return V_39 ;
F_6 ( V_12 -> V_40 , V_12 -> V_31 + V_32 ) ;
return 0 ;
}
static int F_55 ( struct V_34 * V_24 ,
const struct V_178 * V_179 )
{
struct V_178 V_180 = * V_179 ;
struct V_181 * V_182 = & V_180 . V_183 ;
struct V_146 * V_147 = F_51 ( V_24 ) ;
struct V_184 V_185 ;
int V_39 ;
F_56 ( & V_182 -> V_186 , & V_182 -> V_187 , 0 , 2 , 4096 ) ;
F_56 ( & V_182 -> V_188 , & V_182 -> V_189 , 0 , 2 , 4096 ) ;
V_39 = F_52 ( V_147 , V_151 , V_190 , V_179 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_52 ( V_147 , V_151 , V_191 , & V_185 ) ;
if ( V_39 < 0 )
return V_39 ;
F_18 ( V_24 -> V_37 , L_7 ,
V_185 . V_187 , V_185 . V_189 ) ;
V_24 -> V_26 = V_185 . V_187 ;
V_24 -> V_25 = V_185 . V_189 ;
return V_39 ;
}
static int F_57 ( struct V_34 * V_24 ,
unsigned int V_192 ,
struct V_193 * V_194 )
{
struct V_146 * V_147 = F_51 ( V_24 ) ;
const struct V_195 * V_51 ;
struct V_196 * V_118 = V_24 -> V_37 ;
enum V_6 V_197 ;
int V_39 , V_198 = 0 ;
V_39 = F_52 ( V_147 , V_151 , V_199 , V_192 , & V_197 ) ;
if ( V_39 < 0 )
return 0 ;
V_51 = F_58 ( V_197 ) ;
if ( ! V_51 ) {
F_59 ( V_118 , L_8 , V_192 , V_197 ) ;
return 0 ;
}
if ( V_197 == V_200 ||
V_197 == V_201 ) {
V_198 ++ ;
if ( V_194 ) {
V_194 -> V_114 =
F_58 ( V_202 ) ;
V_194 -> V_197 = V_197 ;
F_18 ( V_118 , L_9 ,
V_194 -> V_114 -> V_203 , V_197 ) ;
V_194 ++ ;
}
}
if ( V_197 == V_201 ) {
V_198 ++ ;
if ( V_194 ) {
V_194 -> V_114 =
F_58 ( V_200 ) ;
V_194 -> V_197 = V_197 ;
F_18 ( V_118 , L_9 ,
V_194 -> V_114 -> V_203 , V_197 ) ;
V_194 ++ ;
}
}
V_198 ++ ;
if ( V_194 ) {
V_194 -> V_114 = V_51 ;
V_194 -> V_197 = V_197 ;
V_194 ++ ;
}
return V_198 ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_184 * V_204 ,
struct V_205 * V_206 , bool V_207 )
{
int V_208 , V_209 ;
unsigned long V_210 ;
int V_9 , V_83 ;
for ( V_83 = V_84 ; V_83 <= V_85 ; V_83 ++ ) {
struct V_211 V_212 ;
unsigned char * V_86 = V_212 . V_86 ;
int V_88 = 0 ;
int V_213 , V_64 ;
if ( V_83 == V_84 ) {
V_213 = V_204 -> V_187 ;
V_64 = V_206 -> V_187 ;
} else {
V_213 = V_204 -> V_189 ;
V_64 = V_206 -> V_189 ;
}
if ( V_213 < V_64 )
return - V_63 ;
else if ( V_213 == V_64 )
continue;
V_210 = F_61 ( V_213 , V_64 ) ;
V_208 = V_213 / V_210 ;
V_209 = V_64 / V_210 ;
if ( V_208 > V_91 )
return - V_63 ;
if ( ( V_208 >= 2 * V_209 ) && ( V_209 == 1 ) &&
( V_208 < 9 ) && ( ! ( V_208 & 0x01 ) ) ) {
int V_214 = 0 ;
int V_92 ;
V_212 . V_95 = V_215 ;
V_88 = V_208 ;
for ( V_9 = 0 ; V_9 < ( V_88 / 2 ) ; V_9 ++ )
V_86 [ V_9 ] = 8 ;
do {
for ( V_9 = 0 ; V_9 < ( V_88 / 2 ) ; V_9 ++ ) {
V_86 [ V_9 ] = V_86 [ V_9 ] >> 1 ;
V_214 = 0 ;
for ( V_92 = 0 ; V_92 < ( V_88 / 2 ) ; V_92 ++ )
V_214 += V_86 [ V_92 ] ;
if ( V_214 == 4 )
break;
}
} while ( V_214 != 4 );
for ( V_9 = ( V_88 / 2 ) ; V_9 < V_88 ; V_9 ++ )
V_86 [ V_9 ] = V_86 [ V_88 - V_9 - 1 ] ;
V_86 [ V_88 - 1 ] |= V_94 ;
} else {
int V_216 ;
int V_89 , V_217 ;
int V_218 = 2 * V_209 ;
int V_219 = V_208 ;
int V_220 = 2 * V_208 ;
int V_221 = V_208 - V_209 ;
int V_222 = V_221 ;
V_212 . V_95 = V_96 ;
V_216 = V_209 + V_218 ;
do {
V_89 = V_216 - V_219 ;
V_219 += V_220 ;
V_222 += V_220 ;
for ( V_217 = 0 ; V_216 < V_219 ; V_217 ++ ) {
V_216 += V_218 ;
V_222 -= V_218 ;
}
if ( V_88 > V_91 )
return - V_63 ;
V_89 = ( ( V_89 << V_93 ) +
( V_218 >> 1 ) ) / V_218 ;
if ( V_89 >= ( V_94 - 1 ) )
V_89 -- ;
V_89 |= V_94 ;
V_86 [ V_88 ] = ( unsigned char ) V_89 ;
V_88 ++ ;
for ( V_9 = 1 ; V_9 < V_217 ; V_9 ++ ) {
if ( V_88 >= V_91 )
return - V_63 ;
V_86 [ V_88 ] = 0 ;
V_88 ++ ;
}
} while ( V_222 != V_221 );
}
V_212 . V_88 = V_88 ;
if ( V_83 == V_84 )
V_204 -> V_187 = V_206 -> V_187 ;
else
V_204 -> V_189 = V_206 -> V_189 ;
if ( V_207 )
memcpy ( & V_12 -> V_87 [ V_83 ] , & V_212 , sizeof( V_212 ) ) ;
}
return 0 ;
}
static int F_62 ( struct V_34 * V_24 ,
struct V_50 * V_223 )
{
struct V_35 * V_36 = F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
struct V_146 * V_147 = F_51 ( V_24 ) ;
const struct V_193 * V_194 ;
struct V_205 * V_224 = & V_223 -> V_51 . V_224 ;
struct V_184 V_185 ;
int V_39 ;
F_18 ( V_24 -> V_37 , L_10 ,
V_62 , V_224 -> V_187 , V_224 -> V_189 ) ;
V_194 = F_63 ( V_24 , V_224 -> V_225 ) ;
if ( ! V_194 ) {
F_54 ( V_24 -> V_37 , L_11 ,
V_224 -> V_225 ) ;
return - V_63 ;
}
V_185 . V_187 = V_224 -> V_187 ;
V_185 . V_189 = V_224 -> V_189 ;
V_185 . V_226 = V_224 -> V_226 ;
V_185 . V_227 = V_224 -> V_227 ;
V_185 . V_197 = V_194 -> V_197 ;
V_39 = F_52 ( V_147 , V_151 , V_228 , & V_185 ) ;
if ( V_39 < 0 && V_39 != - V_154 )
return V_39 ;
V_12 -> V_71 = V_185 . V_187 ;
V_12 -> V_72 = V_185 . V_189 ;
F_18 ( V_24 -> V_37 , L_12 ,
V_62 , V_12 -> V_71 , V_12 -> V_72 ) ;
V_12 -> V_16 = F_3 ( V_194 -> V_197 ,
V_194 -> V_114 -> V_229 ) ;
memset ( V_12 -> V_87 , 0 , sizeof( V_12 -> V_87 ) ) ;
if ( ( V_185 . V_187 != V_224 -> V_187 || V_185 . V_189 != V_224 -> V_189 ) &&
V_12 -> V_16 -> V_17 . V_7 == V_230 ) {
if ( F_60 ( V_12 , & V_185 , V_224 , true ) < 0 )
F_18 ( V_24 -> V_37 , L_13 , V_62 ) ;
}
if ( V_185 . V_197 != V_194 -> V_197 )
return - V_63 ;
V_224 -> V_187 = V_185 . V_187 ;
V_224 -> V_189 = V_185 . V_189 ;
V_224 -> V_226 = V_185 . V_226 ;
V_224 -> V_227 = V_185 . V_227 ;
V_24 -> V_113 = V_194 ;
F_18 ( V_24 -> V_37 , L_14 ,
V_62 , V_224 -> V_187 , V_224 -> V_189 ) ;
return 0 ;
}
static int F_64 ( struct V_34 * V_24 ,
struct V_50 * V_223 )
{
struct V_146 * V_147 = F_51 ( V_24 ) ;
const struct V_193 * V_194 ;
struct V_205 * V_224 = & V_223 -> V_51 . V_224 ;
struct V_184 V_185 ;
T_2 V_231 = V_224 -> V_225 ;
struct V_35 * V_36 = F_10 ( V_24 -> V_37 ) ;
struct V_11 * V_12 = V_36 -> V_38 ;
struct V_5 * V_16 ;
int V_39 ;
F_18 ( V_24 -> V_37 , L_10 ,
V_62 , V_224 -> V_187 , V_224 -> V_189 ) ;
V_194 = F_63 ( V_24 , V_231 ) ;
if ( V_231 && ! V_194 ) {
F_54 ( V_24 -> V_37 , L_11 , V_231 ) ;
return - V_63 ;
}
V_224 -> V_187 &= ~ 0x7 ;
V_185 . V_187 = V_224 -> V_187 ;
V_185 . V_189 = V_224 -> V_189 ;
V_185 . V_226 = V_224 -> V_226 ;
V_185 . V_227 = V_224 -> V_227 ;
V_185 . V_197 = V_194 -> V_197 ;
V_39 = F_52 ( V_147 , V_151 , V_232 , & V_185 ) ;
if ( V_39 < 0 )
return V_39 ;
F_18 ( V_24 -> V_37 , L_12 ,
V_62 , V_12 -> V_71 , V_12 -> V_72 ) ;
V_16 = F_3 ( V_194 -> V_197 ,
V_194 -> V_114 -> V_229 ) ;
if ( ( V_185 . V_187 != V_224 -> V_187 || V_185 . V_189 != V_224 -> V_189 ) &&
V_16 -> V_17 . V_7 == V_230 ) {
if ( F_60 ( V_12 , & V_185 , V_224 , false ) < 0 )
F_18 ( V_24 -> V_37 , L_13 , V_62 ) ;
}
if ( V_185 . V_226 == V_233 )
V_185 . V_226 = V_234 ;
if ( V_185 . V_226 != V_234 && ! F_65 ( V_185 . V_226 ) ) {
F_59 ( V_24 -> V_37 , L_15 ,
V_185 . V_226 ) ;
return - V_63 ;
}
V_224 -> V_187 = V_185 . V_187 ;
V_224 -> V_189 = V_185 . V_189 ;
V_224 -> V_226 = V_185 . V_226 ;
V_224 -> V_227 = V_185 . V_227 ;
F_18 ( V_24 -> V_37 , L_14 ,
V_62 , V_224 -> V_187 , V_224 -> V_189 ) ;
return 0 ;
}
static int F_66 ( struct V_35 * V_36 ,
struct V_235 * V_236 )
{
F_67 ( V_236 -> V_237 , V_238 , sizeof( V_236 -> V_237 ) ) ;
V_236 -> V_239 = V_240 | V_241 ;
return 0 ;
}
static unsigned int F_68 ( struct V_242 * V_242 , T_3 * V_243 )
{
struct V_34 * V_24 = V_242 -> V_244 ;
return F_69 ( & V_24 -> V_245 , V_242 , V_243 ) ;
}
static void F_70 ( struct V_11 * V_12 ,
int V_14 , bool V_246 )
{
#ifdef F_22
struct V_5 * V_15 = V_12 -> V_16 ;
#endif
struct V_2 * V_247 ;
struct V_1 * V_65 ;
struct V_60 * V_61 ;
unsigned long V_13 ;
V_247 = F_33 ( & V_12 -> V_112 , struct V_2 ,
V_68 ) ;
F_15 ( V_247 -> V_14 != V_14 ) ;
if ( V_247 -> V_123 ) {
F_35 ( V_12 -> V_112 . V_111 , & V_12 -> V_123 ) ;
} else {
V_65 = F_1 ( V_247 ) ;
V_61 = & V_65 -> V_61 ;
#ifdef F_22
V_13 = F_34 ( V_61 , 0 ) ;
if ( V_15 -> V_17 . V_18 == 1 ) {
if ( F_42 ( V_12 -> V_19 + V_20 +
4 * V_14 ) != V_13 ) {
F_59 ( V_12 -> V_118 , L_16 , V_13 ,
F_42 ( V_12 -> V_19 +
V_20 + 4 * V_14 ) ) ;
}
} else {
if ( F_42 ( V_12 -> V_19 + V_21 -
0x14 * V_14 ) != V_13 ) {
F_59 ( V_12 -> V_118 , L_16 , V_13 ,
F_42 ( V_12 -> V_19 +
V_21 - 0x14 * V_14 ) ) ;
}
}
#endif
F_18 ( V_12 -> V_118 , L_4 , V_62 , V_61 ,
F_20 ( V_61 , 0 ) ,
F_21 ( V_61 , 0 ) ) ;
F_71 ( & V_65 -> V_4 . V_68 ) ;
F_72 ( & V_61 -> V_248 . V_249 ) ;
V_61 -> V_248 . V_250 = V_12 -> V_46 ;
if ( V_246 )
F_73 ( V_61 , V_251 ) ;
else
F_73 ( V_61 , V_252 ) ;
}
V_12 -> V_46 ++ ;
if ( F_74 ( & V_12 -> V_69 ) ) {
if ( F_74 ( & V_12 -> V_123 ) ) {
F_54 ( V_12 -> V_118 , L_17 ,
V_62 ) ;
return;
}
V_247 = F_33 ( & V_12 -> V_123 ,
struct V_2 , V_68 ) ;
V_247 -> V_14 = V_14 ;
F_35 ( V_12 -> V_123 . V_111 , & V_12 -> V_112 ) ;
F_5 ( V_12 , V_12 -> V_119 , V_14 ) ;
return;
}
V_65 = F_33 ( & V_12 -> V_69 , struct V_1 ,
V_4 . V_68 ) ;
V_65 -> V_4 . V_14 = V_14 ;
F_35 ( V_12 -> V_69 . V_111 , & V_12 -> V_112 ) ;
V_61 = & V_65 -> V_61 ;
V_13 = F_34 ( V_61 , 0 ) ;
F_5 ( V_12 , V_13 , V_14 ) ;
}
static T_4 F_75 ( int V_253 , void * V_254 )
{
struct V_11 * V_12 = V_254 ;
unsigned int V_255 = F_42 ( V_12 -> V_19 + V_256 ) ;
struct V_2 * V_247 ;
F_76 ( & V_12 -> V_67 ) ;
if ( F_74 ( & V_12 -> V_112 ) ) {
F_54 ( V_12 -> V_118 , L_18 ,
V_62 ) ;
if ( ! V_255 ) {
F_77 ( & V_12 -> V_67 ) ;
return V_257 ;
}
}
if ( V_255 & ( 1 << 7 ) ) {
T_1 V_131 = F_42 ( V_12 -> V_19 + V_33 ) ;
F_6 ( V_131 & ~ ( V_124 | V_128 ) ,
V_12 -> V_19 + V_33 ) ;
F_6 ( V_131 , V_12 -> V_19 + V_33 ) ;
V_247 = F_33 ( & V_12 -> V_112 ,
struct V_2 , V_68 ) ;
F_70 ( V_12 ,
V_247 -> V_14 , true ) ;
V_255 &= ~ ( 1 << 7 ) ;
} else if ( ( ( V_255 & ( 3 << 5 ) ) == ( 3 << 5 ) ) ||
( ( V_255 & ( 3 << 3 ) ) == ( 3 << 3 ) ) ) {
V_247 = F_33 ( & V_12 -> V_112 ,
struct V_2 , V_68 ) ;
F_70 ( V_12 , V_247 -> V_14 , false ) ;
V_255 &= ~ ( 1 << ( 6 - V_247 -> V_14 ) ) ;
} else if ( ( V_255 & ( 1 << 6 ) ) || ( V_255 & ( 1 << 4 ) ) ) {
F_70 ( V_12 , 0 , false ) ;
} else if ( ( V_255 & ( 1 << 5 ) ) || ( V_255 & ( 1 << 3 ) ) ) {
F_70 ( V_12 , 1 , false ) ;
}
F_77 ( & V_12 -> V_67 ) ;
F_6 ( V_255 , V_12 -> V_19 + V_256 ) ;
return V_258 ;
}
static int F_78 ( struct V_259 * V_260 )
{
struct V_11 * V_12 = F_79 ( V_260 ) ;
struct V_261 * V_262 ;
int V_253 ;
int V_246 = 0 ;
V_262 = F_80 ( V_260 , V_263 , 1 ) ;
V_253 = F_81 ( V_260 , 1 ) ;
if ( ! V_262 || ! V_253 ) {
F_59 ( V_12 -> V_118 , L_19 ) ;
V_246 = - V_264 ;
goto V_64;
}
V_12 -> V_19 = F_82 ( V_12 -> V_118 , V_262 ) ;
if ( F_83 ( V_12 -> V_19 ) ) {
V_246 = F_84 ( V_12 -> V_19 ) ;
goto V_64;
}
V_246 = F_85 ( V_12 -> V_118 , V_253 , F_75 , 0 ,
V_265 , V_12 ) ;
if ( V_246 ) {
F_59 ( V_12 -> V_118 , L_20 ) ;
goto V_64;
}
V_12 -> V_266 = F_86 ( V_12 -> V_118 , L_21 ) ;
if ( F_83 ( V_12 -> V_266 ) ) {
V_246 = F_84 ( V_12 -> V_266 ) ;
goto V_64;
}
F_11 ( V_12 -> V_266 ) ;
V_12 -> V_267 = F_86 ( V_12 -> V_118 , L_22 ) ;
if ( F_83 ( V_12 -> V_267 ) ) {
V_246 = F_84 ( V_12 -> V_267 ) ;
goto V_268;
}
F_11 ( V_12 -> V_267 ) ;
V_246 = F_47 ( V_12 ) ;
if ( V_246 )
goto V_269;
return V_246 ;
V_269:
F_8 ( V_12 -> V_267 ) ;
V_268:
F_8 ( V_12 -> V_266 ) ;
V_64:
return V_246 ;
}
static int F_87 ( struct V_259 * V_260 )
{
struct V_11 * V_12 ;
struct V_261 * V_270 ;
int V_271 ;
int V_246 = 0 ;
F_18 ( & V_260 -> V_118 , L_23 ) ;
V_270 = F_80 ( V_260 , V_263 , 0 ) ;
V_271 = F_81 ( V_260 , 0 ) ;
if ( V_270 == NULL || V_271 < 0 ) {
F_59 ( & V_260 -> V_118 , L_24 ) ;
V_246 = - V_264 ;
goto exit;
}
V_12 = F_88 ( & V_260 -> V_118 , sizeof( * V_12 ) , V_272 ) ;
if ( ! V_12 ) {
F_59 ( & V_260 -> V_118 , L_25 ) ;
V_246 = - V_121 ;
goto exit;
}
V_12 -> V_29 = F_86 ( & V_260 -> V_118 , L_26 ) ;
if ( F_83 ( V_12 -> V_29 ) ) {
F_59 ( & V_260 -> V_118 , L_27 ) ;
V_246 = F_84 ( V_12 -> V_29 ) ;
goto exit;
}
V_12 -> V_30 = F_86 ( & V_260 -> V_118 , L_28 ) ;
if ( F_83 ( V_12 -> V_30 ) ) {
F_59 ( & V_260 -> V_118 , L_29 ) ;
V_246 = F_84 ( V_12 -> V_30 ) ;
goto exit;
}
V_12 -> V_273 = V_260 -> V_118 . V_274 ;
if ( V_12 -> V_273 ) {
long V_275 ;
V_12 -> V_157 = V_12 -> V_273 -> V_66 ;
V_275 = F_89 ( V_12 -> V_30 ,
V_12 -> V_273 -> V_276 * 2 ) ;
if ( V_275 <= 0 ) {
V_246 = - V_264 ;
goto exit;
}
V_246 = F_90 ( V_12 -> V_30 , V_275 ) ;
if ( V_246 < 0 )
goto exit;
}
F_43 ( & V_12 -> V_69 ) ;
F_43 ( & V_12 -> V_112 ) ;
F_43 ( & V_12 -> V_123 ) ;
F_91 ( & V_12 -> V_67 ) ;
V_12 -> V_31 = F_82 ( & V_260 -> V_118 , V_270 ) ;
if ( F_83 ( V_12 -> V_31 ) ) {
V_246 = F_84 ( V_12 -> V_31 ) ;
goto exit;
}
V_12 -> V_118 = & V_260 -> V_118 ;
F_92 ( V_260 , V_12 ) ;
V_246 = F_78 ( V_260 ) ;
if ( V_246 )
goto exit;
F_92 ( V_260 , NULL ) ;
V_12 -> V_277 . V_278 = V_265 ,
V_12 -> V_277 . V_137 = & V_279 ,
V_12 -> V_277 . V_38 = V_12 ;
V_12 -> V_277 . V_117 . V_118 = & V_260 -> V_118 ;
V_12 -> V_277 . V_280 = V_260 -> V_281 ;
V_12 -> V_57 = F_93 ( & V_260 -> V_118 ) ;
if ( F_83 ( V_12 -> V_57 ) ) {
V_246 = F_84 ( V_12 -> V_57 ) ;
goto V_282;
}
V_246 = F_94 ( & V_12 -> V_277 ) ;
if ( V_246 )
goto V_283;
F_13 ( & V_260 -> V_118 , L_30 ,
F_95 ( V_12 -> V_30 ) ) ;
return 0 ;
V_283:
F_96 ( V_12 -> V_57 ) ;
V_282:
F_8 ( V_12 -> V_266 ) ;
F_8 ( V_12 -> V_267 ) ;
exit:
return V_246 ;
}
static int F_97 ( struct V_259 * V_260 )
{
struct V_35 * V_277 = F_10 ( & V_260 -> V_118 ) ;
struct V_11 * V_12 = F_2 ( V_277 ,
struct V_11 , V_277 ) ;
F_98 ( & V_12 -> V_277 ) ;
F_96 ( V_12 -> V_57 ) ;
F_8 ( V_12 -> V_266 ) ;
F_8 ( V_12 -> V_267 ) ;
F_13 ( & V_260 -> V_118 , L_31 ) ;
return 0 ;
}
