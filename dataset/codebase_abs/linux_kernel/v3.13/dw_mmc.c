static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_9 * V_11 ;
struct V_12 * V_13 ;
F_2 ( & V_5 -> V_14 -> V_15 ) ;
V_8 = V_5 -> V_8 ;
if ( V_8 ) {
V_10 = V_8 -> V_10 ;
V_13 = V_8 -> V_13 ;
V_11 = V_8 -> V_11 ;
if ( V_10 )
F_3 ( V_2 ,
L_1 ,
V_10 -> V_16 , V_10 -> V_17 , V_10 -> V_18 ,
V_10 -> V_19 [ 0 ] , V_10 -> V_19 [ 1 ] , V_10 -> V_19 [ 2 ] ,
V_10 -> V_19 [ 2 ] , V_10 -> error ) ;
if ( V_13 )
F_3 ( V_2 , L_2 ,
V_13 -> V_20 , V_13 -> V_21 ,
V_13 -> V_22 , V_13 -> V_18 , V_13 -> error ) ;
if ( V_11 )
F_3 ( V_2 ,
L_1 ,
V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 ,
V_11 -> V_19 [ 0 ] , V_11 -> V_19 [ 1 ] , V_11 -> V_19 [ 2 ] ,
V_11 -> V_19 [ 2 ] , V_11 -> error ) ;
}
F_4 ( & V_5 -> V_14 -> V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_6 ( V_24 , F_1 , V_23 -> V_25 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_3 )
{
F_3 ( V_2 , L_3 , V_26 ) ;
F_3 ( V_2 , L_4 , V_27 ) ;
F_3 ( V_2 , L_5 , V_28 ) ;
F_3 ( V_2 , L_6 , V_29 ) ;
F_3 ( V_2 , L_7 , V_30 ) ;
F_3 ( V_2 , L_8 , V_31 ) ;
return 0 ;
}
static int F_8 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_6 ( V_24 , F_7 , V_23 -> V_25 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_32 * V_33 = V_5 -> V_33 ;
struct V_34 * V_14 = V_5 -> V_14 ;
struct V_35 * V_36 ;
struct V_35 * V_37 ;
V_36 = V_33 -> V_38 ;
if ( ! V_36 )
return;
V_37 = F_10 ( L_9 , V_39 , V_36 , V_14 ,
& V_40 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_10 ( L_10 , V_39 , V_36 , V_5 ,
& V_42 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_11 ( L_11 , V_39 , V_36 , ( V_43 * ) & V_14 -> V_44 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_12 ( L_12 , V_39 , V_36 ,
( V_43 * ) & V_14 -> V_45 ) ;
if ( ! V_37 )
goto V_41;
V_37 = F_12 ( L_13 , V_39 , V_36 ,
( V_43 * ) & V_14 -> V_46 ) ;
if ( ! V_37 )
goto V_41;
return;
V_41:
F_13 ( & V_33 -> V_47 , L_14 ) ;
}
static void F_14 ( struct V_34 * V_14 )
{
F_15 ( V_14 , V_48 , 0xffffffff ) ;
}
static V_43 F_16 ( struct V_32 * V_33 , struct V_9 * V_10 )
{
struct V_12 * V_13 ;
struct V_4 * V_5 = F_17 ( V_33 ) ;
const struct V_49 * V_50 = V_5 -> V_14 -> V_50 ;
V_43 V_51 ;
V_10 -> error = - V_52 ;
V_51 = V_10 -> V_16 ;
if ( V_10 -> V_16 == V_53 ||
V_10 -> V_16 == V_54 ||
V_10 -> V_16 == V_55 ||
( V_10 -> V_16 == V_56 &&
( ( V_10 -> V_17 >> 9 ) & 0x1FFFF ) == V_57 ) )
V_51 |= V_58 ;
else
if ( V_10 -> V_16 != V_59 && V_10 -> V_13 )
V_51 |= V_60 ;
if ( V_10 -> V_18 & V_61 ) {
V_51 |= V_62 ;
if ( V_10 -> V_18 & V_63 )
V_51 |= V_64 ;
}
if ( V_10 -> V_18 & V_65 )
V_51 |= V_66 ;
V_13 = V_10 -> V_13 ;
if ( V_13 ) {
V_51 |= V_67 ;
if ( V_13 -> V_18 & V_68 )
V_51 |= V_69 ;
if ( V_13 -> V_18 & V_70 )
V_51 |= V_71 ;
}
if ( V_50 && V_50 -> V_72 )
V_50 -> V_72 ( V_5 -> V_14 , & V_51 ) ;
return V_51 ;
}
static V_43 F_18 ( struct V_34 * V_14 , struct V_9 * V_10 )
{
struct V_9 * V_11 ;
V_43 V_51 ;
if ( ! V_10 -> V_13 )
return 0 ;
V_11 = & V_14 -> V_73 ;
V_51 = V_10 -> V_16 ;
memset ( V_11 , 0 , sizeof( struct V_9 ) ) ;
if ( V_51 == V_74 ||
V_51 == V_75 ||
V_51 == V_76 ||
V_51 == V_77 ) {
V_11 -> V_16 = V_53 ;
V_11 -> V_17 = 0 ;
V_11 -> V_18 = V_78 | V_79 ;
} else if ( V_51 == V_80 ) {
V_11 -> V_16 = V_56 ;
V_11 -> V_17 |= ( 1 << 31 ) | ( 0 << 28 ) | ( V_57 << 9 ) |
( ( V_10 -> V_17 >> 28 ) & 0x7 ) ;
V_11 -> V_18 = V_81 | V_82 | V_79 ;
} else {
return 0 ;
}
V_51 = V_11 -> V_16 | V_58 |
V_66 | V_62 ;
return V_51 ;
}
static void F_19 ( struct V_34 * V_14 ,
struct V_9 * V_10 , V_43 V_83 )
{
V_14 -> V_10 = V_10 ;
F_20 ( V_14 -> V_84 ,
L_15 ,
V_10 -> V_17 , V_83 ) ;
F_15 ( V_14 , V_85 , V_10 -> V_17 ) ;
F_21 () ;
F_15 ( V_14 , V_86 , V_83 | V_87 ) ;
}
static inline void F_22 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
struct V_9 * V_11 = V_13 -> V_11 ? V_13 -> V_11 : & V_14 -> V_73 ;
F_19 ( V_14 , V_11 , V_14 -> V_88 ) ;
}
static void F_23 ( struct V_34 * V_14 )
{
if ( V_14 -> V_89 ) {
V_14 -> V_90 -> V_11 ( V_14 ) ;
V_14 -> V_90 -> V_91 ( V_14 ) ;
}
F_24 ( V_92 , & V_14 -> V_45 ) ;
}
static int F_25 ( struct V_12 * V_13 )
{
if ( V_13 -> V_18 & V_70 )
return V_93 ;
else
return V_94 ;
}
static void F_26 ( struct V_34 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 )
if ( ! V_13 -> V_95 )
F_27 ( V_14 -> V_84 ,
V_13 -> V_96 ,
V_13 -> V_97 ,
F_25 ( V_13 ) ) ;
}
static void F_28 ( struct V_34 * V_14 )
{
V_43 V_98 = F_29 ( V_14 , V_99 ) ;
V_98 |= V_100 ;
F_15 ( V_14 , V_99 , V_98 ) ;
}
static void F_30 ( struct V_34 * V_14 )
{
V_43 V_101 ;
V_101 = F_29 ( V_14 , V_102 ) ;
V_101 &= ~ V_103 ;
V_101 |= V_104 ;
F_15 ( V_14 , V_102 , V_101 ) ;
V_101 = F_29 ( V_14 , V_99 ) ;
V_101 &= ~ ( V_105 | V_106 ) ;
V_101 |= V_100 ;
F_15 ( V_14 , V_99 , V_101 ) ;
}
static void F_31 ( struct V_34 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
F_20 ( V_14 -> V_84 , L_16 ) ;
V_14 -> V_90 -> V_91 ( V_14 ) ;
if ( V_13 ) {
F_24 ( V_92 , & V_14 -> V_45 ) ;
F_32 ( & V_14 -> V_107 ) ;
}
}
static void F_33 ( struct V_34 * V_14 , struct V_12 * V_13 ,
unsigned int V_97 )
{
int V_108 ;
struct V_109 * V_110 = V_14 -> V_111 ;
for ( V_108 = 0 ; V_108 < V_97 ; V_108 ++ , V_110 ++ ) {
unsigned int V_112 = F_34 ( & V_13 -> V_96 [ V_108 ] ) ;
V_43 V_113 = F_35 ( & V_13 -> V_96 [ V_108 ] ) ;
V_110 -> V_114 = V_115 | V_116 | V_117 ;
F_36 ( V_110 , V_112 ) ;
V_110 -> V_118 = V_113 ;
}
V_110 = V_14 -> V_111 ;
V_110 -> V_114 |= V_119 ;
V_110 = V_14 -> V_111 + ( V_108 - 1 ) * sizeof( struct V_109 ) ;
V_110 -> V_114 &= ~ ( V_117 | V_116 ) ;
V_110 -> V_114 |= V_120 ;
F_21 () ;
}
static void F_37 ( struct V_34 * V_14 , unsigned int V_97 )
{
V_43 V_101 ;
F_33 ( V_14 , V_14 -> V_13 , V_97 ) ;
V_101 = F_29 ( V_14 , V_102 ) ;
V_101 |= V_103 ;
F_15 ( V_14 , V_102 , V_101 ) ;
F_21 () ;
V_101 = F_29 ( V_14 , V_99 ) ;
V_101 |= V_105 | V_106 ;
F_15 ( V_14 , V_99 , V_101 ) ;
F_15 ( V_14 , V_121 , 1 ) ;
}
static int F_38 ( struct V_34 * V_14 )
{
struct V_109 * V_122 ;
int V_108 ;
V_14 -> V_123 = V_124 / sizeof( struct V_109 ) ;
for ( V_108 = 0 , V_122 = V_14 -> V_111 ; V_108 < V_14 -> V_123 - 1 ; V_108 ++ , V_122 ++ )
V_122 -> V_125 = V_14 -> V_126 + ( sizeof( struct V_109 ) * ( V_108 + 1 ) ) ;
V_122 -> V_125 = V_14 -> V_126 ;
V_122 -> V_114 = V_127 ;
F_28 ( V_14 ) ;
F_15 ( V_14 , V_128 , V_129 ) ;
F_15 ( V_14 , V_130 , V_131 | V_132 |
V_133 ) ;
F_15 ( V_14 , V_134 , V_14 -> V_126 ) ;
return 0 ;
}
static int F_39 ( struct V_34 * V_14 ,
struct V_12 * V_13 ,
bool V_135 )
{
struct V_136 * V_96 ;
unsigned int V_108 , V_97 ;
if ( ! V_135 && V_13 -> V_95 )
return V_13 -> V_95 ;
if ( V_13 -> V_21 * V_13 -> V_22 < V_137 )
return - V_138 ;
if ( V_13 -> V_22 & 3 )
return - V_138 ;
F_40 (data->sg, sg, data->sg_len, i) {
if ( V_96 -> V_139 & 3 || V_96 -> V_112 & 3 )
return - V_138 ;
}
V_97 = F_41 ( V_14 -> V_84 ,
V_13 -> V_96 ,
V_13 -> V_97 ,
F_25 ( V_13 ) ) ;
if ( V_97 == 0 )
return - V_138 ;
if ( V_135 )
V_13 -> V_95 = V_97 ;
return V_97 ;
}
static void F_42 ( struct V_32 * V_33 ,
struct V_7 * V_8 ,
bool V_140 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_12 * V_13 = V_8 -> V_13 ;
if ( ! V_5 -> V_14 -> V_141 || ! V_13 )
return;
if ( V_13 -> V_95 ) {
V_13 -> V_95 = 0 ;
return;
}
if ( F_39 ( V_5 -> V_14 , V_8 -> V_13 , 1 ) < 0 )
V_13 -> V_95 = 0 ;
}
static void F_43 ( struct V_32 * V_33 ,
struct V_7 * V_8 ,
int V_41 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_12 * V_13 = V_8 -> V_13 ;
if ( ! V_5 -> V_14 -> V_141 || ! V_13 )
return;
if ( V_13 -> V_95 )
F_27 ( V_5 -> V_14 -> V_84 ,
V_13 -> V_96 ,
V_13 -> V_97 ,
F_25 ( V_13 ) ) ;
V_13 -> V_95 = 0 ;
}
static void F_44 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
#ifdef F_45
unsigned int V_22 = V_13 -> V_22 ;
const V_43 V_142 [] = { 1 , 4 , 8 , 16 , 32 , 64 , 128 , 256 } ;
V_43 V_143 = 1 << V_14 -> V_144 ;
V_43 V_145 = V_22 / V_143 , V_146 ;
V_43 V_147 = 0 , V_148 = 1 , V_149 , V_150 ;
int V_151 = ( sizeof( V_142 ) / sizeof( V_142 [ 0 ] ) ) - 1 ;
V_149 = ( V_14 -> V_152 ) / 2 ;
V_150 = V_14 -> V_152 - V_149 ;
if ( V_22 % V_143 ) {
V_147 = 0 ;
V_148 = 1 ;
goto V_153;
}
do {
if ( ! ( ( V_145 % V_142 [ V_151 ] ) ||
( V_150 % V_142 [ V_151 ] ) ) ) {
V_147 = V_151 ;
V_148 = V_142 [ V_151 ] - 1 ;
break;
}
} while ( -- V_151 > 0 );
V_153:
V_146 = F_46 ( V_147 , V_148 , V_149 ) ;
F_15 ( V_14 , V_154 , V_146 ) ;
#endif
}
static void F_47 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
unsigned int V_22 = V_13 -> V_22 ;
V_43 V_145 , V_152 ;
T_1 V_155 ;
F_48 ( ! ( V_13 -> V_18 & V_156 ) ) ;
if ( V_14 -> V_157 != V_158 &&
V_14 -> V_157 != V_159 )
goto V_160;
V_145 = V_22 / ( 1 << V_14 -> V_144 ) ;
V_152 = V_14 -> V_152 ;
if ( V_145 > V_152 )
goto V_160;
V_155 = V_22 ;
F_15 ( V_14 , V_161 , F_49 ( V_155 , 1 ) ) ;
return;
V_160:
F_15 ( V_14 , V_161 , F_49 ( 0 , 0 ) ) ;
}
static int F_50 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
int V_97 ;
V_43 V_101 ;
V_14 -> V_89 = 0 ;
if ( ! V_14 -> V_141 )
return - V_162 ;
V_97 = F_39 ( V_14 , V_13 , 0 ) ;
if ( V_97 < 0 ) {
V_14 -> V_90 -> V_11 ( V_14 ) ;
return V_97 ;
}
V_14 -> V_89 = 1 ;
F_20 ( V_14 -> V_84 ,
L_17 ,
( unsigned long ) V_14 -> V_111 , ( unsigned long ) V_14 -> V_126 ,
V_97 ) ;
if ( V_14 -> V_163 != V_13 -> V_22 )
F_44 ( V_14 , V_13 ) ;
V_101 = F_29 ( V_14 , V_102 ) ;
V_101 |= V_164 ;
F_15 ( V_14 , V_102 , V_101 ) ;
V_101 = F_29 ( V_14 , V_165 ) ;
V_101 &= ~ ( V_166 | V_167 ) ;
F_15 ( V_14 , V_165 , V_101 ) ;
V_14 -> V_90 -> V_168 ( V_14 , V_97 ) ;
return 0 ;
}
static void F_51 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
V_43 V_101 ;
V_13 -> error = - V_52 ;
F_48 ( V_14 -> V_13 ) ;
V_14 -> V_96 = NULL ;
V_14 -> V_13 = V_13 ;
if ( V_13 -> V_18 & V_156 ) {
V_14 -> V_169 = V_170 ;
F_47 ( V_14 , V_13 ) ;
} else {
V_14 -> V_169 = V_171 ;
}
if ( F_50 ( V_14 , V_13 ) ) {
int V_18 = V_172 ;
if ( V_14 -> V_13 -> V_18 & V_156 )
V_18 |= V_173 ;
else
V_18 |= V_174 ;
F_52 ( & V_14 -> V_175 , V_13 -> V_96 , V_13 -> V_97 , V_18 ) ;
V_14 -> V_96 = V_13 -> V_96 ;
V_14 -> V_176 = 0 ;
V_14 -> V_177 = 0 ;
F_15 ( V_14 , V_178 , V_167 | V_166 ) ;
V_101 = F_29 ( V_14 , V_165 ) ;
V_101 |= V_167 | V_166 ;
F_15 ( V_14 , V_165 , V_101 ) ;
V_101 = F_29 ( V_14 , V_102 ) ;
V_101 &= ~ V_164 ;
F_15 ( V_14 , V_102 , V_101 ) ;
F_15 ( V_14 , V_154 , V_14 -> V_146 ) ;
V_14 -> V_163 = 0 ;
} else {
V_14 -> V_163 = V_13 -> V_22 ;
}
}
static void F_53 ( struct V_4 * V_5 , V_43 V_10 , V_43 V_17 )
{
struct V_34 * V_14 = V_5 -> V_14 ;
unsigned long V_179 = V_180 + F_54 ( 500 ) ;
unsigned int V_181 = 0 ;
F_15 ( V_14 , V_85 , V_17 ) ;
F_21 () ;
F_15 ( V_14 , V_86 , V_87 | V_10 ) ;
while ( F_55 ( V_180 , V_179 ) ) {
V_181 = F_29 ( V_14 , V_86 ) ;
if ( ! ( V_181 & V_87 ) )
return;
}
F_13 ( & V_5 -> V_33 -> V_47 ,
L_18 ,
V_10 , V_17 , V_181 ) ;
}
static void F_56 ( struct V_4 * V_5 , bool V_182 )
{
struct V_34 * V_14 = V_5 -> V_14 ;
unsigned int clock = V_5 -> clock ;
V_43 div ;
V_43 V_183 ;
if ( ! clock ) {
F_15 ( V_14 , V_184 , 0 ) ;
F_53 ( V_5 ,
V_185 | V_60 , 0 ) ;
} else if ( clock != V_14 -> V_186 || V_182 ) {
div = V_14 -> V_187 / clock ;
if ( V_14 -> V_187 % clock && V_14 -> V_187 > clock )
div += 1 ;
div = ( V_14 -> V_187 != clock ) ? F_57 ( div , 2 ) : 0 ;
if ( ( clock << div ) != V_5 -> V_188 || V_182 )
F_58 ( & V_5 -> V_33 -> V_47 ,
L_19 ,
V_5 -> V_189 , V_14 -> V_187 , clock ,
div ? ( ( V_14 -> V_187 / div ) >> 1 ) :
V_14 -> V_187 , div ) ;
F_15 ( V_14 , V_184 , 0 ) ;
F_15 ( V_14 , V_190 , 0 ) ;
F_53 ( V_5 ,
V_185 | V_60 , 0 ) ;
F_15 ( V_14 , V_191 , div ) ;
F_53 ( V_5 ,
V_185 | V_60 , 0 ) ;
V_183 = V_192 << V_5 -> V_189 ;
if ( ! ( F_29 ( V_14 , V_165 ) & F_59 ( V_5 -> V_189 ) ) )
V_183 |= V_193 << V_5 -> V_189 ;
F_15 ( V_14 , V_184 , V_183 ) ;
F_53 ( V_5 ,
V_185 | V_60 , 0 ) ;
V_5 -> V_188 = clock << div ;
}
V_14 -> V_186 = clock ;
F_15 ( V_14 , V_194 , ( V_5 -> V_195 << V_5 -> V_189 ) ) ;
}
static void F_60 ( struct V_34 * V_14 ,
struct V_4 * V_5 ,
struct V_9 * V_10 )
{
struct V_7 * V_8 ;
struct V_12 * V_13 ;
V_43 V_196 ;
V_8 = V_5 -> V_8 ;
if ( V_14 -> V_197 -> V_198 )
V_14 -> V_197 -> V_198 ( V_5 -> V_189 ) ;
V_14 -> V_199 = V_5 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_45 = 0 ;
V_14 -> V_46 = 0 ;
V_14 -> V_181 = 0 ;
V_14 -> V_200 = 0 ;
V_14 -> V_169 = 0 ;
V_13 = V_10 -> V_13 ;
if ( V_13 ) {
F_14 ( V_14 ) ;
F_15 ( V_14 , V_201 , V_13 -> V_22 * V_13 -> V_21 ) ;
F_15 ( V_14 , V_202 , V_13 -> V_22 ) ;
}
V_196 = F_16 ( V_5 -> V_33 , V_10 ) ;
if ( F_61 ( V_203 , & V_5 -> V_18 ) )
V_196 |= V_204 ;
if ( V_13 ) {
F_51 ( V_14 , V_13 ) ;
F_21 () ;
}
F_19 ( V_14 , V_10 , V_196 ) ;
if ( V_8 -> V_11 )
V_14 -> V_88 = F_16 ( V_5 -> V_33 , V_8 -> V_11 ) ;
else
V_14 -> V_88 = F_18 ( V_14 , V_10 ) ;
}
static void F_62 ( struct V_34 * V_14 ,
struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 ;
V_10 = V_8 -> V_205 ? V_8 -> V_205 : V_8 -> V_10 ;
F_60 ( V_14 , V_5 , V_10 ) ;
}
static void F_63 ( struct V_34 * V_14 , struct V_4 * V_5 ,
struct V_7 * V_8 )
{
F_20 ( & V_5 -> V_33 -> V_47 , L_20 ,
V_14 -> V_44 ) ;
V_5 -> V_8 = V_8 ;
if ( V_14 -> V_44 == V_206 ) {
V_14 -> V_44 = V_207 ;
F_62 ( V_14 , V_5 ) ;
} else {
F_64 ( & V_5 -> V_208 , & V_14 -> V_209 ) ;
}
}
static void F_65 ( struct V_32 * V_33 , struct V_7 * V_8 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_34 * V_14 = V_5 -> V_14 ;
F_48 ( V_5 -> V_8 ) ;
F_2 ( & V_14 -> V_15 ) ;
if ( ! F_66 ( V_210 , & V_5 -> V_18 ) ) {
F_4 ( & V_14 -> V_15 ) ;
V_8 -> V_10 -> error = - V_211 ;
F_67 ( V_33 , V_8 ) ;
return;
}
F_63 ( V_14 , V_5 , V_8 ) ;
F_4 ( & V_14 -> V_15 ) ;
}
static void F_68 ( struct V_32 * V_33 , struct V_212 * V_213 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
const struct V_49 * V_50 = V_5 -> V_14 -> V_50 ;
V_43 V_214 ;
switch ( V_213 -> V_215 ) {
case V_216 :
V_5 -> V_195 = V_217 ;
break;
case V_218 :
V_5 -> V_195 = V_219 ;
break;
default:
V_5 -> V_195 = V_220 ;
}
V_214 = F_29 ( V_5 -> V_14 , V_221 ) ;
if ( V_213 -> V_157 == V_222 )
V_214 |= ( ( 0x1 << V_5 -> V_189 ) << 16 ) ;
else
V_214 &= ~ ( ( 0x1 << V_5 -> V_189 ) << 16 ) ;
F_15 ( V_5 -> V_14 , V_221 , V_214 ) ;
V_5 -> V_14 -> V_157 = V_213 -> V_157 ;
V_5 -> clock = V_213 -> clock ;
if ( V_50 && V_50 -> V_223 )
V_50 -> V_223 ( V_5 -> V_14 , V_213 ) ;
F_56 ( V_5 , false ) ;
switch ( V_213 -> V_224 ) {
case V_225 :
F_24 ( V_203 , & V_5 -> V_18 ) ;
if ( V_5 -> V_14 -> V_197 -> V_226 )
V_5 -> V_14 -> V_197 -> V_226 ( V_5 -> V_189 , V_33 -> V_227 ) ;
V_214 = F_29 ( V_5 -> V_14 , V_228 ) ;
V_214 |= ( 1 << V_5 -> V_189 ) ;
F_15 ( V_5 -> V_14 , V_228 , V_214 ) ;
break;
case V_229 :
if ( V_5 -> V_14 -> V_197 -> V_226 )
V_5 -> V_14 -> V_197 -> V_226 ( V_5 -> V_189 , 0 ) ;
V_214 = F_29 ( V_5 -> V_14 , V_228 ) ;
V_214 &= ~ ( 1 << V_5 -> V_189 ) ;
F_15 ( V_5 -> V_14 , V_228 , V_214 ) ;
break;
default:
break;
}
}
static int F_69 ( struct V_32 * V_33 )
{
int V_230 ;
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_231 * V_232 = V_5 -> V_14 -> V_197 ;
if ( V_5 -> V_233 & V_234 )
V_230 = 0 ;
else if ( V_232 -> V_235 )
V_230 = V_232 -> V_235 ( V_5 -> V_189 ) ;
else if ( F_70 ( V_5 -> V_236 ) )
V_230 = F_71 ( V_5 -> V_236 ) ;
else
V_230 =
F_29 ( V_5 -> V_14 , V_237 ) & ( 1 << V_5 -> V_189 ) ? 1 : 0 ;
F_72 ( & V_33 -> V_47 , L_21 ,
V_230 ? L_22 : L_23 ) ;
return V_230 ;
}
static int F_73 ( struct V_32 * V_33 )
{
int V_238 ;
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_231 * V_232 = V_5 -> V_14 -> V_197 ;
if ( V_232 -> V_233 & V_239 )
V_238 = 1 ;
else if ( V_232 -> V_240 )
V_238 = ! V_232 -> V_240 ( V_5 -> V_189 ) ;
else
V_238 = ( F_29 ( V_5 -> V_14 , V_241 ) & ( 1 << V_5 -> V_189 ) )
== 0 ? 1 : 0 ;
if ( V_238 )
F_72 ( & V_33 -> V_47 , L_24 ) ;
else
F_72 ( & V_33 -> V_47 , L_25 ) ;
return V_238 ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_34 * V_14 = V_5 -> V_14 ;
V_43 V_183 ;
const V_43 V_242 = V_193 << V_5 -> V_189 ;
V_183 = F_29 ( V_14 , V_184 ) ;
if ( V_183 & V_242 ) {
F_15 ( V_14 , V_184 , V_183 & ~ V_242 ) ;
F_53 ( V_5 , V_185 |
V_60 , 0 ) ;
}
}
static void F_75 ( struct V_32 * V_33 , int V_243 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_34 * V_14 = V_5 -> V_14 ;
V_43 V_244 ;
V_244 = F_29 ( V_14 , V_165 ) ;
if ( V_243 ) {
F_74 ( V_5 ) ;
F_15 ( V_14 , V_165 ,
( V_244 | F_59 ( V_5 -> V_189 ) ) ) ;
} else {
F_15 ( V_14 , V_165 ,
( V_244 & ~ F_59 ( V_5 -> V_189 ) ) ) ;
}
}
static int F_76 ( struct V_32 * V_33 , V_43 V_16 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_34 * V_14 = V_5 -> V_14 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
struct V_245 V_246 ;
int V_41 = - V_247 ;
if ( V_16 == V_248 ) {
if ( V_33 -> V_213 . V_215 == V_218 ) {
V_246 . V_249 = V_250 ;
V_246 . V_22 = sizeof( V_250 ) ;
} else if ( V_33 -> V_213 . V_215 == V_216 ) {
V_246 . V_249 = V_251 ;
V_246 . V_22 = sizeof( V_251 ) ;
} else {
return - V_138 ;
}
} else if ( V_16 == V_252 ) {
V_246 . V_249 = V_251 ;
V_246 . V_22 = sizeof( V_251 ) ;
} else {
F_13 ( V_14 -> V_84 ,
L_26 , V_16 ) ;
return - V_138 ;
}
if ( V_50 && V_50 -> V_253 )
V_41 = V_50 -> V_253 ( V_5 , V_16 , & V_246 ) ;
return V_41 ;
}
static void F_77 ( struct V_34 * V_14 , struct V_7 * V_8 )
__releases( &host->lock
static int F_78 ( struct V_34 * V_14 , struct V_9 * V_10 )
{
V_43 V_254 = V_14 -> V_181 ;
V_14 -> V_181 = 0 ;
if ( V_10 -> V_18 & V_61 ) {
if ( V_10 -> V_18 & V_63 ) {
V_10 -> V_19 [ 3 ] = F_29 ( V_14 , V_255 ) ;
V_10 -> V_19 [ 2 ] = F_29 ( V_14 , V_256 ) ;
V_10 -> V_19 [ 1 ] = F_29 ( V_14 , V_257 ) ;
V_10 -> V_19 [ 0 ] = F_29 ( V_14 , V_258 ) ;
} else {
V_10 -> V_19 [ 0 ] = F_29 ( V_14 , V_255 ) ;
V_10 -> V_19 [ 1 ] = 0 ;
V_10 -> V_19 [ 2 ] = 0 ;
V_10 -> V_19 [ 3 ] = 0 ;
}
}
if ( V_254 & V_259 )
V_10 -> error = - V_260 ;
else if ( ( V_10 -> V_18 & V_65 ) && ( V_254 & V_261 ) )
V_10 -> error = - V_262 ;
else if ( V_254 & V_263 )
V_10 -> error = - V_264 ;
else
V_10 -> error = 0 ;
if ( V_10 -> error ) {
if ( V_14 -> V_233 & V_265 )
F_79 ( 20 ) ;
}
return V_10 -> error ;
}
static int F_80 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
V_43 V_254 = V_14 -> V_200 ;
if ( V_254 & V_266 ) {
if ( V_254 & V_267 ) {
V_13 -> error = - V_260 ;
} else if ( V_254 & V_268 ) {
V_13 -> error = - V_262 ;
} else if ( V_254 & V_269 ) {
if ( V_14 -> V_169 ==
V_171 ) {
V_13 -> V_20 = 0 ;
V_13 -> error = - V_260 ;
} else if ( V_14 -> V_169 ==
V_170 ) {
V_13 -> error = - V_264 ;
}
} else {
V_13 -> error = - V_264 ;
}
F_13 ( V_14 -> V_84 , L_27 , V_254 ) ;
F_81 ( V_14 ) ;
} else {
V_13 -> V_20 = V_13 -> V_21 * V_13 -> V_22 ;
V_13 -> error = 0 ;
}
return V_13 -> error ;
}
static void F_82 ( unsigned long V_270 )
{
struct V_34 * V_14 = (struct V_34 * ) V_270 ;
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
enum V_271 V_44 ;
enum V_271 V_272 ;
unsigned int V_41 ;
F_83 ( & V_14 -> V_15 ) ;
V_44 = V_14 -> V_44 ;
V_13 = V_14 -> V_13 ;
V_8 = V_14 -> V_8 ;
do {
V_272 = V_44 ;
switch ( V_44 ) {
case V_206 :
break;
case V_207 :
if ( ! F_61 ( V_273 ,
& V_14 -> V_45 ) )
break;
V_10 = V_14 -> V_10 ;
V_14 -> V_10 = NULL ;
F_24 ( V_273 , & V_14 -> V_46 ) ;
V_41 = F_78 ( V_14 , V_10 ) ;
if ( V_10 == V_8 -> V_205 && ! V_41 ) {
V_272 = V_44 = V_207 ;
F_60 ( V_14 , V_14 -> V_199 ,
V_8 -> V_10 ) ;
goto V_274;
}
if ( V_10 -> V_13 && V_41 ) {
F_23 ( V_14 ) ;
F_22 ( V_14 , V_13 ) ;
V_44 = V_275 ;
break;
}
if ( ! V_10 -> V_13 || V_41 ) {
F_77 ( V_14 , V_8 ) ;
goto V_274;
}
V_272 = V_44 = V_276 ;
case V_276 :
if ( F_61 ( V_277 ,
& V_14 -> V_45 ) ) {
F_23 ( V_14 ) ;
F_22 ( V_14 , V_13 ) ;
V_44 = V_278 ;
break;
}
if ( ! F_61 ( V_92 ,
& V_14 -> V_45 ) )
break;
F_24 ( V_92 , & V_14 -> V_46 ) ;
V_272 = V_44 = V_279 ;
case V_279 :
if ( ! F_61 ( V_280 ,
& V_14 -> V_45 ) )
break;
V_14 -> V_13 = NULL ;
F_24 ( V_280 , & V_14 -> V_46 ) ;
V_41 = F_80 ( V_14 , V_13 ) ;
if ( ! V_41 ) {
if ( ! V_13 -> V_11 || V_8 -> V_205 ) {
if ( V_8 -> V_205 )
V_13 -> V_11 -> error = 0 ;
F_77 ( V_14 , V_8 ) ;
goto V_274;
}
if ( V_13 -> V_11 )
F_22 ( V_14 , V_13 ) ;
}
V_272 = V_44 = V_275 ;
case V_275 :
if ( ! F_61 ( V_273 ,
& V_14 -> V_45 ) )
break;
if ( V_8 -> V_10 -> error && V_8 -> V_13 )
F_81 ( V_14 ) ;
V_14 -> V_10 = NULL ;
V_14 -> V_13 = NULL ;
if ( V_8 -> V_11 )
F_78 ( V_14 , V_8 -> V_11 ) ;
else
V_14 -> V_181 = 0 ;
F_77 ( V_14 , V_8 ) ;
goto V_274;
case V_278 :
if ( ! F_61 ( V_92 ,
& V_14 -> V_45 ) )
break;
V_44 = V_279 ;
break;
}
} while ( V_44 != V_272 );
V_14 -> V_44 = V_44 ;
V_274:
F_84 ( & V_14 -> V_15 ) ;
}
static void F_85 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
memcpy ( ( void * ) & V_14 -> V_283 , V_281 , V_282 ) ;
V_14 -> V_177 = V_282 ;
}
static int F_86 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
V_282 = F_87 ( V_282 , ( 1 << V_14 -> V_144 ) - V_14 -> V_177 ) ;
memcpy ( ( void * ) & V_14 -> V_283 + V_14 -> V_177 , V_281 , V_282 ) ;
V_14 -> V_177 += V_282 ;
return V_282 ;
}
static int F_88 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
V_282 = F_87 ( V_282 , ( int ) V_14 -> V_177 ) ;
if ( V_282 ) {
memcpy ( V_281 , ( void * ) & V_14 -> V_283 + V_14 -> V_176 ,
V_282 ) ;
V_14 -> V_177 -= V_282 ;
V_14 -> V_176 += V_282 ;
}
return V_282 ;
}
static void F_89 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
memcpy ( V_281 , & V_14 -> V_283 , V_282 ) ;
V_14 -> V_176 = V_282 ;
V_14 -> V_177 = ( 1 << V_14 -> V_144 ) - V_282 ;
}
static void F_90 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
int V_284 = V_282 ;
if ( F_91 ( V_14 -> V_177 ) ) {
int V_285 = F_86 ( V_14 , V_281 , V_282 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
if ( V_14 -> V_177 == 2 ) {
F_92 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_14 -> V_287 ) ;
V_14 -> V_177 = 0 ;
}
}
#ifndef F_94
if ( F_91 ( ( unsigned long ) V_281 & 0x1 ) ) {
while ( V_282 >= 2 ) {
T_1 V_288 [ 64 ] ;
int V_285 = F_87 ( V_282 & - 2 , ( int ) sizeof( V_288 ) ) ;
int V_289 = V_285 >> 1 ;
int V_108 ;
memcpy ( V_288 , V_281 , V_285 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
for ( V_108 = 0 ; V_108 < V_289 ; ++ V_108 )
F_92 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_288 [ V_108 ] ) ;
}
} else
#endif
{
T_1 * V_197 = V_281 ;
for (; V_282 >= 2 ; V_282 -= 2 )
F_92 ( V_14 , F_93 ( V_14 -> V_286 ) , * V_197 ++ ) ;
V_281 = V_197 ;
}
if ( V_282 ) {
F_85 ( V_14 , V_281 , V_282 ) ;
if ( ( V_13 -> V_20 + V_284 ) ==
( V_13 -> V_22 * V_13 -> V_21 ) )
F_92 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_14 -> V_287 ) ;
}
}
static void F_95 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
#ifndef F_94
if ( F_91 ( ( unsigned long ) V_281 & 0x1 ) ) {
while ( V_282 >= 2 ) {
T_1 V_288 [ 64 ] ;
int V_285 = F_87 ( V_282 & - 2 , ( int ) sizeof( V_288 ) ) ;
int V_289 = V_285 >> 1 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_289 ; ++ V_108 )
V_288 [ V_108 ] = F_96 ( V_14 ,
F_93 ( V_14 -> V_286 ) ) ;
memcpy ( V_281 , V_288 , V_285 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
}
} else
#endif
{
T_1 * V_197 = V_281 ;
for (; V_282 >= 2 ; V_282 -= 2 )
* V_197 ++ = F_96 ( V_14 , F_93 ( V_14 -> V_286 ) ) ;
V_281 = V_197 ;
}
if ( V_282 ) {
V_14 -> V_287 = F_96 ( V_14 , F_93 ( V_14 -> V_286 ) ) ;
F_89 ( V_14 , V_281 , V_282 ) ;
}
}
static void F_97 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
int V_284 = V_282 ;
if ( F_91 ( V_14 -> V_177 ) ) {
int V_285 = F_86 ( V_14 , V_281 , V_282 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
if ( V_14 -> V_177 == 4 ) {
F_15 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_14 -> V_290 ) ;
V_14 -> V_177 = 0 ;
}
}
#ifndef F_94
if ( F_91 ( ( unsigned long ) V_281 & 0x3 ) ) {
while ( V_282 >= 4 ) {
V_43 V_288 [ 32 ] ;
int V_285 = F_87 ( V_282 & - 4 , ( int ) sizeof( V_288 ) ) ;
int V_289 = V_285 >> 2 ;
int V_108 ;
memcpy ( V_288 , V_281 , V_285 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
for ( V_108 = 0 ; V_108 < V_289 ; ++ V_108 )
F_15 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_288 [ V_108 ] ) ;
}
} else
#endif
{
V_43 * V_197 = V_281 ;
for (; V_282 >= 4 ; V_282 -= 4 )
F_15 ( V_14 , F_93 ( V_14 -> V_286 ) , * V_197 ++ ) ;
V_281 = V_197 ;
}
if ( V_282 ) {
F_85 ( V_14 , V_281 , V_282 ) ;
if ( ( V_13 -> V_20 + V_284 ) ==
( V_13 -> V_22 * V_13 -> V_21 ) )
F_15 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_14 -> V_290 ) ;
}
}
static void F_98 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
#ifndef F_94
if ( F_91 ( ( unsigned long ) V_281 & 0x3 ) ) {
while ( V_282 >= 4 ) {
V_43 V_288 [ 32 ] ;
int V_285 = F_87 ( V_282 & - 4 , ( int ) sizeof( V_288 ) ) ;
int V_289 = V_285 >> 2 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_289 ; ++ V_108 )
V_288 [ V_108 ] = F_29 ( V_14 ,
F_93 ( V_14 -> V_286 ) ) ;
memcpy ( V_281 , V_288 , V_285 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
}
} else
#endif
{
V_43 * V_197 = V_281 ;
for (; V_282 >= 4 ; V_282 -= 4 )
* V_197 ++ = F_29 ( V_14 , F_93 ( V_14 -> V_286 ) ) ;
V_281 = V_197 ;
}
if ( V_282 ) {
V_14 -> V_290 = F_29 ( V_14 , F_93 ( V_14 -> V_286 ) ) ;
F_89 ( V_14 , V_281 , V_282 ) ;
}
}
static void F_99 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
int V_284 = V_282 ;
if ( F_91 ( V_14 -> V_177 ) ) {
int V_285 = F_86 ( V_14 , V_281 , V_282 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
if ( V_14 -> V_177 == 8 ) {
F_100 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_14 -> V_283 ) ;
V_14 -> V_177 = 0 ;
}
}
#ifndef F_94
if ( F_91 ( ( unsigned long ) V_281 & 0x7 ) ) {
while ( V_282 >= 8 ) {
T_2 V_288 [ 16 ] ;
int V_285 = F_87 ( V_282 & - 8 , ( int ) sizeof( V_288 ) ) ;
int V_289 = V_285 >> 3 ;
int V_108 ;
memcpy ( V_288 , V_281 , V_285 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
for ( V_108 = 0 ; V_108 < V_289 ; ++ V_108 )
F_100 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_288 [ V_108 ] ) ;
}
} else
#endif
{
T_2 * V_197 = V_281 ;
for (; V_282 >= 8 ; V_282 -= 8 )
F_100 ( V_14 , F_93 ( V_14 -> V_286 ) , * V_197 ++ ) ;
V_281 = V_197 ;
}
if ( V_282 ) {
F_85 ( V_14 , V_281 , V_282 ) ;
if ( ( V_13 -> V_20 + V_284 ) ==
( V_13 -> V_22 * V_13 -> V_21 ) )
F_100 ( V_14 , F_93 ( V_14 -> V_286 ) ,
V_14 -> V_283 ) ;
}
}
static void F_101 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
#ifndef F_94
if ( F_91 ( ( unsigned long ) V_281 & 0x7 ) ) {
while ( V_282 >= 8 ) {
T_2 V_288 [ 16 ] ;
int V_285 = F_87 ( V_282 & - 8 , ( int ) sizeof( V_288 ) ) ;
int V_289 = V_285 >> 3 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_289 ; ++ V_108 )
V_288 [ V_108 ] = F_102 ( V_14 ,
F_93 ( V_14 -> V_286 ) ) ;
memcpy ( V_281 , V_288 , V_285 ) ;
V_281 += V_285 ;
V_282 -= V_285 ;
}
} else
#endif
{
T_2 * V_197 = V_281 ;
for (; V_282 >= 8 ; V_282 -= 8 )
* V_197 ++ = F_102 ( V_14 , F_93 ( V_14 -> V_286 ) ) ;
V_281 = V_197 ;
}
if ( V_282 ) {
V_14 -> V_283 = F_102 ( V_14 , F_93 ( V_14 -> V_286 ) ) ;
F_89 ( V_14 , V_281 , V_282 ) ;
}
}
static void F_103 ( struct V_34 * V_14 , void * V_281 , int V_282 )
{
int V_285 ;
V_285 = F_88 ( V_14 , V_281 , V_282 ) ;
if ( F_91 ( V_285 == V_282 ) )
return;
V_281 += V_285 ;
V_282 -= V_285 ;
V_14 -> V_291 ( V_14 , V_281 , V_282 ) ;
}
static void F_104 ( struct V_34 * V_14 , bool V_292 )
{
struct V_293 * V_175 = & V_14 -> V_175 ;
void * V_281 ;
unsigned int V_139 ;
struct V_12 * V_13 = V_14 -> V_13 ;
int V_294 = V_14 -> V_144 ;
V_43 V_254 ;
unsigned int V_285 ;
unsigned int V_295 , V_296 ;
do {
if ( ! F_105 ( V_175 ) )
goto V_153;
V_14 -> V_96 = V_175 -> V_297 . V_96 ;
V_281 = V_175 -> V_298 ;
V_295 = V_175 -> V_112 ;
V_139 = 0 ;
do {
V_296 = ( F_106 ( F_29 ( V_14 , V_299 ) )
<< V_294 ) + V_14 -> V_177 ;
V_285 = F_87 ( V_295 , V_296 ) ;
if ( ! V_285 )
break;
F_103 ( V_14 , ( void * ) ( V_281 + V_139 ) , V_285 ) ;
V_13 -> V_20 += V_285 ;
V_139 += V_285 ;
V_295 -= V_285 ;
} while ( V_295 );
V_175 -> V_300 = V_139 ;
V_254 = F_29 ( V_14 , V_301 ) ;
F_15 ( V_14 , V_178 , V_166 ) ;
} while ( ( V_254 & V_166 ) ||
( V_292 && F_106 ( F_29 ( V_14 , V_299 ) ) ) );
if ( ! V_295 ) {
if ( ! F_105 ( V_175 ) )
goto V_153;
V_175 -> V_300 = 0 ;
}
F_107 ( V_175 ) ;
return;
V_153:
F_107 ( V_175 ) ;
V_14 -> V_96 = NULL ;
F_108 () ;
F_24 ( V_92 , & V_14 -> V_45 ) ;
}
static void F_109 ( struct V_34 * V_14 )
{
struct V_293 * V_175 = & V_14 -> V_175 ;
void * V_281 ;
unsigned int V_139 ;
struct V_12 * V_13 = V_14 -> V_13 ;
int V_294 = V_14 -> V_144 ;
V_43 V_254 ;
unsigned int V_285 ;
unsigned int V_152 = V_14 -> V_152 ;
unsigned int V_295 , V_296 ;
do {
if ( ! F_105 ( V_175 ) )
goto V_153;
V_14 -> V_96 = V_175 -> V_297 . V_96 ;
V_281 = V_175 -> V_298 ;
V_295 = V_175 -> V_112 ;
V_139 = 0 ;
do {
V_296 = ( ( V_152 -
F_106 ( F_29 ( V_14 , V_299 ) ) )
<< V_294 ) - V_14 -> V_177 ;
V_285 = F_87 ( V_295 , V_296 ) ;
if ( ! V_285 )
break;
V_14 -> V_302 ( V_14 , ( void * ) ( V_281 + V_139 ) , V_285 ) ;
V_13 -> V_20 += V_285 ;
V_139 += V_285 ;
V_295 -= V_285 ;
} while ( V_295 );
V_175 -> V_300 = V_139 ;
V_254 = F_29 ( V_14 , V_301 ) ;
F_15 ( V_14 , V_178 , V_167 ) ;
} while ( V_254 & V_167 );
if ( ! V_295 ) {
if ( ! F_105 ( V_175 ) )
goto V_153;
V_175 -> V_300 = 0 ;
}
F_107 ( V_175 ) ;
return;
V_153:
F_107 ( V_175 ) ;
V_14 -> V_96 = NULL ;
F_108 () ;
F_24 ( V_92 , & V_14 -> V_45 ) ;
}
static void F_110 ( struct V_34 * V_14 , V_43 V_254 )
{
if ( ! V_14 -> V_181 )
V_14 -> V_181 = V_254 ;
F_108 () ;
F_24 ( V_273 , & V_14 -> V_45 ) ;
F_32 ( & V_14 -> V_107 ) ;
}
static T_3 F_111 ( int V_303 , void * V_304 )
{
struct V_34 * V_14 = V_304 ;
V_43 V_305 ;
int V_108 ;
V_305 = F_29 ( V_14 , V_301 ) ;
if ( V_14 -> V_233 & V_306 ) {
if ( ! V_305 &&
( ( F_29 ( V_14 , V_299 ) >> 17 ) & 0x1fff ) )
V_305 |= V_307 ;
}
if ( V_305 ) {
if ( V_305 & V_308 ) {
F_15 ( V_14 , V_178 , V_308 ) ;
V_14 -> V_181 = V_305 ;
F_108 () ;
F_24 ( V_273 , & V_14 -> V_45 ) ;
}
if ( V_305 & V_266 ) {
F_15 ( V_14 , V_178 , V_266 ) ;
V_14 -> V_200 = V_305 ;
F_108 () ;
F_24 ( V_277 , & V_14 -> V_45 ) ;
F_32 ( & V_14 -> V_107 ) ;
}
if ( V_305 & V_307 ) {
F_15 ( V_14 , V_178 , V_307 ) ;
if ( ! V_14 -> V_200 )
V_14 -> V_200 = V_305 ;
F_108 () ;
if ( V_14 -> V_169 == V_170 ) {
if ( V_14 -> V_96 != NULL )
F_104 ( V_14 , true ) ;
}
F_24 ( V_280 , & V_14 -> V_45 ) ;
F_32 ( & V_14 -> V_107 ) ;
}
if ( V_305 & V_166 ) {
F_15 ( V_14 , V_178 , V_166 ) ;
if ( V_14 -> V_169 == V_170 && V_14 -> V_96 )
F_104 ( V_14 , false ) ;
}
if ( V_305 & V_167 ) {
F_15 ( V_14 , V_178 , V_167 ) ;
if ( V_14 -> V_169 == V_171 && V_14 -> V_96 )
F_109 ( V_14 ) ;
}
if ( V_305 & V_309 ) {
F_15 ( V_14 , V_178 , V_309 ) ;
F_110 ( V_14 , V_305 ) ;
}
if ( V_305 & V_310 ) {
F_15 ( V_14 , V_178 , V_310 ) ;
F_112 ( V_14 -> V_311 , & V_14 -> V_312 ) ;
}
for ( V_108 = 0 ; V_108 < V_14 -> V_313 ; V_108 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_108 ] ;
if ( V_305 & F_59 ( V_108 ) ) {
F_15 ( V_14 , V_178 , F_59 ( V_108 ) ) ;
F_113 ( V_5 -> V_33 ) ;
}
}
}
#ifdef F_45
V_305 = F_29 ( V_14 , V_128 ) ;
if ( V_305 & ( V_133 | V_132 ) ) {
F_15 ( V_14 , V_128 , V_133 | V_132 ) ;
F_15 ( V_14 , V_128 , V_131 ) ;
V_14 -> V_90 -> V_314 ( V_14 ) ;
}
#endif
return V_315 ;
}
static void F_114 ( struct V_316 * V_317 )
{
struct V_34 * V_14 = F_115 ( V_317 , struct V_34 , V_312 ) ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_313 ; V_108 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_108 ] ;
struct V_32 * V_33 = V_5 -> V_33 ;
struct V_7 * V_8 ;
int V_238 ;
V_238 = F_73 ( V_33 ) ;
while ( V_238 != V_5 -> V_318 ) {
F_72 ( & V_5 -> V_33 -> V_47 , L_28 ,
V_238 ? L_29 : L_30 ) ;
F_2 ( & V_14 -> V_15 ) ;
V_5 -> V_318 = V_238 ;
if ( V_238 != 0 )
F_24 ( V_210 , & V_5 -> V_18 ) ;
V_8 = V_5 -> V_8 ;
if ( V_8 ) {
if ( V_8 == V_14 -> V_8 ) {
V_14 -> V_13 = NULL ;
V_14 -> V_10 = NULL ;
switch ( V_14 -> V_44 ) {
case V_206 :
break;
case V_207 :
V_8 -> V_10 -> error = - V_211 ;
if ( ! V_8 -> V_13 )
break;
case V_276 :
V_8 -> V_13 -> error = - V_211 ;
F_23 ( V_14 ) ;
break;
case V_279 :
case V_278 :
if ( V_8 -> V_13 -> error == - V_52 )
V_8 -> V_13 -> error = - V_211 ;
case V_275 :
if ( V_8 -> V_11 )
V_8 -> V_11 -> error = - V_211 ;
break;
}
F_77 ( V_14 , V_8 ) ;
} else {
F_116 ( & V_5 -> V_208 ) ;
V_8 -> V_10 -> error = - V_211 ;
if ( V_8 -> V_13 )
V_8 -> V_13 -> error = - V_211 ;
if ( V_8 -> V_11 )
V_8 -> V_11 -> error = - V_211 ;
F_84 ( & V_14 -> V_15 ) ;
F_67 ( V_5 -> V_33 , V_8 ) ;
F_83 ( & V_14 -> V_15 ) ;
}
}
if ( V_238 == 0 ) {
F_117 ( V_210 , & V_5 -> V_18 ) ;
F_81 ( V_14 ) ;
#ifdef F_45
F_28 ( V_14 ) ;
#endif
}
F_4 ( & V_14 -> V_15 ) ;
V_238 = F_73 ( V_33 ) ;
}
F_118 ( V_5 -> V_33 ,
F_54 ( V_14 -> V_197 -> V_319 ) ) ;
}
}
static struct V_320 * F_119 ( struct V_321 * V_84 , T_4 V_5 )
{
struct V_320 * V_322 ;
const T_5 * V_298 ;
int V_285 ;
if ( ! V_84 || ! V_84 -> V_323 )
return NULL ;
F_120 (dev->of_node, np) {
V_298 = F_121 ( V_322 , L_31 , & V_285 ) ;
if ( ! V_298 || ( V_285 < sizeof( int ) ) )
continue;
if ( F_122 ( V_298 ) == V_5 )
return V_322 ;
}
return NULL ;
}
static int F_123 ( struct V_321 * V_84 , T_4 V_5 )
{
struct V_320 * V_322 = F_119 ( V_84 , V_5 ) ;
int V_233 = 0 ;
int V_151 ;
for ( V_151 = 0 ; V_151 < F_124 ( V_324 ) ; V_151 ++ )
if ( F_121 ( V_322 , V_324 [ V_151 ] . V_325 , NULL ) )
V_233 |= V_324 [ V_151 ] . V_189 ;
return V_233 ;
}
static V_43 F_125 ( struct V_321 * V_84 , T_4 V_5 )
{
struct V_320 * V_322 = F_119 ( V_84 , V_5 ) ;
V_43 V_326 = 1 ;
if ( ! V_322 )
return 1 ;
if ( F_126 ( V_322 , L_32 , & V_326 ) )
F_13 ( V_84 , L_33
L_34 ) ;
return V_326 ;
}
static int F_127 ( struct V_321 * V_84 , T_4 V_5 )
{
struct V_320 * V_322 = F_119 ( V_84 , V_5 ) ;
int V_327 ;
if ( ! V_322 )
return - V_138 ;
V_327 = F_128 ( V_322 , L_35 , 0 ) ;
if ( ! F_70 ( V_327 ) )
return - V_138 ;
if ( F_129 ( V_84 , V_327 , L_36 ) ) {
F_130 ( V_84 , L_37 , V_327 ) ;
return - V_138 ;
}
return V_327 ;
}
static int F_123 ( struct V_321 * V_84 , T_4 V_5 )
{
return 0 ;
}
static V_43 F_125 ( struct V_321 * V_84 , T_4 V_5 )
{
return 1 ;
}
static struct V_320 * F_119 ( struct V_321 * V_84 , T_4 V_5 )
{
return NULL ;
}
static int F_127 ( struct V_321 * V_84 , T_4 V_5 )
{
return - V_138 ;
}
static int F_131 ( struct V_34 * V_14 , unsigned int V_189 )
{
struct V_32 * V_33 ;
struct V_4 * V_5 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_328 , V_329 ;
V_43 V_330 [ 2 ] ;
T_4 V_215 ;
V_33 = F_132 ( sizeof( struct V_4 ) , V_14 -> V_84 ) ;
if ( ! V_33 )
return - V_331 ;
V_5 = F_17 ( V_33 ) ;
V_5 -> V_189 = V_189 ;
V_5 -> V_33 = V_33 ;
V_5 -> V_14 = V_14 ;
V_14 -> V_5 [ V_189 ] = V_5 ;
V_5 -> V_233 = F_123 ( V_14 -> V_84 , V_5 -> V_189 ) ;
V_33 -> V_332 = & V_333 ;
if ( F_133 ( V_14 -> V_84 -> V_323 ,
L_38 , V_330 , 2 ) ) {
V_33 -> V_334 = V_335 ;
V_33 -> V_336 = V_337 ;
} else {
V_33 -> V_334 = V_330 [ 0 ] ;
V_33 -> V_336 = V_330 [ 1 ] ;
}
if ( V_14 -> V_197 -> V_338 )
V_33 -> V_227 = V_14 -> V_197 -> V_338 ( V_189 ) ;
else
V_33 -> V_227 = V_339 | V_340 ;
if ( V_14 -> V_197 -> V_226 )
V_14 -> V_197 -> V_226 ( V_189 , 0 ) ;
if ( V_14 -> V_197 -> V_341 )
V_33 -> V_341 = V_14 -> V_197 -> V_341 ;
if ( V_14 -> V_197 -> V_342 )
V_33 -> V_342 = V_14 -> V_197 -> V_342 ;
if ( V_14 -> V_84 -> V_323 ) {
V_328 = F_134 ( V_14 -> V_84 -> V_323 , L_39 ) ;
if ( V_328 < 0 )
V_328 = 0 ;
} else {
V_328 = F_135 ( V_14 -> V_84 ) -> V_189 ;
}
if ( V_50 && V_50 -> V_341 )
V_33 -> V_341 |= V_50 -> V_341 [ V_328 ] ;
if ( V_14 -> V_197 -> V_343 )
V_33 -> V_343 = V_14 -> V_197 -> V_343 ;
if ( V_14 -> V_197 -> V_344 )
V_215 = V_14 -> V_197 -> V_344 ( V_5 -> V_189 ) ;
else if ( V_14 -> V_84 -> V_323 )
V_215 = F_125 ( V_14 -> V_84 , V_5 -> V_189 ) ;
else
V_215 = 1 ;
switch ( V_215 ) {
case 8 :
V_33 -> V_341 |= V_345 ;
case 4 :
V_33 -> V_341 |= V_346 ;
}
if ( V_14 -> V_197 -> V_347 ) {
V_33 -> V_348 = V_14 -> V_197 -> V_347 -> V_348 ;
V_33 -> V_349 = V_14 -> V_197 -> V_347 -> V_349 ;
V_33 -> V_350 = V_14 -> V_197 -> V_347 -> V_350 ;
V_33 -> V_351 = V_14 -> V_197 -> V_347 -> V_351 ;
V_33 -> V_352 = V_14 -> V_197 -> V_347 -> V_352 ;
} else {
#ifdef F_45
V_33 -> V_348 = V_14 -> V_123 ;
V_33 -> V_349 = 65536 ;
V_33 -> V_350 = V_14 -> V_123 ;
V_33 -> V_352 = 0x1000 ;
V_33 -> V_351 = V_33 -> V_352 * V_33 -> V_350 ;
#else
V_33 -> V_348 = 64 ;
V_33 -> V_349 = 65536 ;
V_33 -> V_350 = 512 ;
V_33 -> V_351 = V_33 -> V_349 * V_33 -> V_350 ;
V_33 -> V_352 = V_33 -> V_351 ;
#endif
}
if ( F_73 ( V_33 ) )
F_24 ( V_210 , & V_5 -> V_18 ) ;
else
F_117 ( V_210 , & V_5 -> V_18 ) ;
V_5 -> V_236 = F_127 ( V_14 -> V_84 , V_5 -> V_189 ) ;
V_329 = F_136 ( V_33 ) ;
if ( V_329 )
goto V_353;
#if F_137 ( V_354 )
F_9 ( V_5 ) ;
#endif
V_5 -> V_318 = 0 ;
return 0 ;
V_353:
F_138 ( V_33 ) ;
return - V_138 ;
}
static void F_139 ( struct V_4 * V_5 , unsigned int V_189 )
{
if ( V_5 -> V_14 -> V_197 -> exit )
V_5 -> V_14 -> V_197 -> exit ( V_189 ) ;
F_140 ( V_5 -> V_33 ) ;
V_5 -> V_14 -> V_5 [ V_189 ] = NULL ;
F_138 ( V_5 -> V_33 ) ;
}
static void F_141 ( struct V_34 * V_14 )
{
V_14 -> V_111 = F_142 ( V_14 -> V_84 , V_124 ,
& V_14 -> V_126 , V_355 ) ;
if ( ! V_14 -> V_111 ) {
F_13 ( V_14 -> V_84 , L_40 ,
V_356 ) ;
goto V_357;
}
#ifdef F_45
V_14 -> V_90 = & V_358 ;
F_58 ( V_14 -> V_84 , L_41 ) ;
#endif
if ( ! V_14 -> V_90 )
goto V_357;
if ( V_14 -> V_90 -> V_359 && V_14 -> V_90 -> V_168 &&
V_14 -> V_90 -> V_11 && V_14 -> V_90 -> V_91 ) {
if ( V_14 -> V_90 -> V_359 ( V_14 ) ) {
F_13 ( V_14 -> V_84 , L_42
L_43 , V_356 ) ;
goto V_357;
}
} else {
F_13 ( V_14 -> V_84 , L_44 ) ;
goto V_357;
}
V_14 -> V_141 = 1 ;
return;
V_357:
F_58 ( V_14 -> V_84 , L_45 ) ;
V_14 -> V_141 = 0 ;
return;
}
static bool F_143 ( struct V_34 * V_14 , V_43 V_360 )
{
unsigned long V_179 = V_180 + F_54 ( 500 ) ;
V_43 V_361 ;
V_361 = F_29 ( V_14 , V_102 ) ;
V_361 |= V_360 ;
F_15 ( V_14 , V_102 , V_361 ) ;
do {
V_361 = F_29 ( V_14 , V_102 ) ;
if ( ! ( V_361 & V_360 ) )
return true ;
} while ( F_55 ( V_180 , V_179 ) );
F_13 ( V_14 -> V_84 ,
L_46 ,
V_361 & V_360 ) ;
return false ;
}
static inline bool F_81 ( struct V_34 * V_14 )
{
if ( V_14 -> V_96 ) {
F_107 ( & V_14 -> V_175 ) ;
V_14 -> V_96 = NULL ;
}
return F_143 ( V_14 , V_362 ) ;
}
static inline bool F_144 ( struct V_34 * V_14 )
{
return F_143 ( V_14 ,
V_362 |
V_363 |
V_104 ) ;
}
static struct V_231 * F_145 ( struct V_34 * V_14 )
{
struct V_231 * V_197 ;
struct V_321 * V_84 = V_14 -> V_84 ;
struct V_320 * V_322 = V_84 -> V_323 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_151 , V_329 ;
V_43 V_364 ;
V_197 = F_146 ( V_84 , sizeof( * V_197 ) , V_355 ) ;
if ( ! V_197 ) {
F_13 ( V_84 , L_47 ) ;
return F_147 ( - V_331 ) ;
}
if ( F_126 ( V_84 -> V_323 , L_48 ,
& V_197 -> V_313 ) ) {
F_58 ( V_84 , L_49
L_50 ) ;
V_197 -> V_313 = 1 ;
}
for ( V_151 = 0 ; V_151 < F_124 ( V_365 ) ; V_151 ++ )
if ( F_121 ( V_322 , V_365 [ V_151 ] . V_325 , NULL ) )
V_197 -> V_233 |= V_365 [ V_151 ] . V_189 ;
if ( F_126 ( V_322 , L_51 , & V_197 -> V_152 ) )
F_58 ( V_84 , L_52
L_53 ) ;
F_126 ( V_322 , L_54 , & V_197 -> V_319 ) ;
if ( ! F_126 ( V_322 , L_55 , & V_364 ) )
V_197 -> V_187 = V_364 ;
if ( V_50 && V_50 -> V_366 ) {
V_329 = V_50 -> V_366 ( V_14 ) ;
if ( V_329 )
return F_147 ( V_329 ) ;
}
if ( F_148 ( V_322 , L_56 , NULL ) )
V_197 -> V_342 |= V_367 ;
if ( F_148 ( V_322 , L_57 , NULL ) )
V_197 -> V_342 |= V_368 ;
if ( F_148 ( V_322 , L_58 , NULL ) )
V_197 -> V_341 |= V_369 | V_370 ;
if ( F_148 ( V_322 , L_59 , NULL ) )
V_197 -> V_343 |= V_371 ;
if ( F_148 ( V_322 , L_60 , NULL ) )
V_197 -> V_343 |= V_372 ;
return V_197 ;
}
static struct V_231 * F_145 ( struct V_34 * V_14 )
{
return F_147 ( - V_138 ) ;
}
int F_149 ( struct V_34 * V_14 )
{
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_373 , V_108 , V_329 = 0 ;
V_43 V_374 ;
int V_375 = 0 ;
if ( ! V_14 -> V_197 ) {
V_14 -> V_197 = F_145 ( V_14 ) ;
if ( F_150 ( V_14 -> V_197 ) ) {
F_13 ( V_14 -> V_84 , L_61 ) ;
return - V_138 ;
}
}
if ( ! V_14 -> V_197 -> V_198 && V_14 -> V_197 -> V_313 > 1 ) {
F_13 ( V_14 -> V_84 ,
L_62 ) ;
return - V_162 ;
}
V_14 -> V_376 = F_151 ( V_14 -> V_84 , L_63 ) ;
if ( F_150 ( V_14 -> V_376 ) ) {
F_72 ( V_14 -> V_84 , L_64 ) ;
} else {
V_329 = F_152 ( V_14 -> V_376 ) ;
if ( V_329 ) {
F_13 ( V_14 -> V_84 , L_65 ) ;
return V_329 ;
}
}
V_14 -> V_377 = F_151 ( V_14 -> V_84 , L_66 ) ;
if ( F_150 ( V_14 -> V_377 ) ) {
F_72 ( V_14 -> V_84 , L_67 ) ;
V_14 -> V_187 = V_14 -> V_197 -> V_187 ;
} else {
V_329 = F_152 ( V_14 -> V_377 ) ;
if ( V_329 ) {
F_13 ( V_14 -> V_84 , L_68 ) ;
goto V_378;
}
if ( V_14 -> V_197 -> V_187 ) {
V_329 = F_153 ( V_14 -> V_377 , V_14 -> V_197 -> V_187 ) ;
if ( V_329 )
F_130 ( V_14 -> V_84 ,
L_69 ,
V_14 -> V_197 -> V_187 ) ;
}
V_14 -> V_187 = F_154 ( V_14 -> V_377 ) ;
}
if ( V_50 && V_50 -> V_359 ) {
V_329 = V_50 -> V_359 ( V_14 ) ;
if ( V_329 ) {
F_13 ( V_14 -> V_84 ,
L_70 ) ;
goto V_379;
}
}
if ( V_50 && V_50 -> V_380 ) {
V_329 = V_50 -> V_380 ( V_14 ) ;
if ( V_329 ) {
F_13 ( V_14 -> V_84 ,
L_71 ) ;
goto V_379;
}
}
V_14 -> V_381 = F_155 ( V_14 -> V_84 , L_72 ) ;
if ( F_150 ( V_14 -> V_381 ) ) {
V_329 = F_156 ( V_14 -> V_381 ) ;
if ( V_329 == - V_382 )
goto V_379;
F_58 ( V_14 -> V_84 , L_73 , V_329 ) ;
V_14 -> V_381 = NULL ;
} else {
V_329 = F_157 ( V_14 -> V_381 ) ;
if ( V_329 ) {
if ( V_329 != - V_382 )
F_13 ( V_14 -> V_84 ,
L_74 , V_329 ) ;
goto V_379;
}
}
if ( ! V_14 -> V_187 ) {
F_13 ( V_14 -> V_84 ,
L_75 ) ;
V_329 = - V_162 ;
goto V_383;
}
V_14 -> V_233 = V_14 -> V_197 -> V_233 ;
F_158 ( & V_14 -> V_15 ) ;
F_159 ( & V_14 -> V_209 ) ;
V_108 = ( F_29 ( V_14 , V_384 ) >> 7 ) & 0x7 ;
if ( ! V_108 ) {
V_14 -> V_302 = F_90 ;
V_14 -> V_291 = F_95 ;
V_373 = 16 ;
V_14 -> V_144 = 1 ;
} else if ( V_108 == 2 ) {
V_14 -> V_302 = F_99 ;
V_14 -> V_291 = F_101 ;
V_373 = 64 ;
V_14 -> V_144 = 3 ;
} else {
F_160 ( ( V_108 != 1 ) ,
L_76
L_77 ) ;
V_14 -> V_302 = F_97 ;
V_14 -> V_291 = F_98 ;
V_373 = 32 ;
V_14 -> V_144 = 2 ;
}
if ( ! F_144 ( V_14 ) )
return - V_162 ;
V_14 -> V_90 = V_14 -> V_197 -> V_90 ;
F_141 ( V_14 ) ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , 0 ) ;
F_15 ( V_14 , V_48 , 0xFFFFFFFF ) ;
if ( ! V_14 -> V_197 -> V_152 ) {
V_374 = F_29 ( V_14 , V_154 ) ;
V_374 = 1 + ( ( V_374 >> 16 ) & 0xfff ) ;
} else {
V_374 = V_14 -> V_197 -> V_152 ;
}
V_14 -> V_152 = V_374 ;
V_14 -> V_146 =
F_46 ( 0x2 , V_374 / 2 - 1 , V_374 / 2 ) ;
F_15 ( V_14 , V_154 , V_14 -> V_146 ) ;
F_15 ( V_14 , V_184 , 0 ) ;
F_15 ( V_14 , V_190 , 0 ) ;
V_14 -> V_385 = F_161 ( F_29 ( V_14 , V_386 ) ) ;
F_58 ( V_14 -> V_84 , L_78 , V_14 -> V_385 ) ;
if ( V_14 -> V_385 < V_387 )
V_14 -> V_286 = V_388 ;
else
V_14 -> V_286 = V_389 ;
F_162 ( & V_14 -> V_107 , F_82 , ( unsigned long ) V_14 ) ;
V_14 -> V_311 = F_163 ( L_79 ,
V_390 | V_391 , 1 ) ;
if ( ! V_14 -> V_311 ) {
V_329 = - V_331 ;
goto V_392;
}
F_164 ( & V_14 -> V_312 , F_114 ) ;
V_329 = F_165 ( V_14 -> V_84 , V_14 -> V_303 , F_111 ,
V_14 -> V_393 , L_80 , V_14 ) ;
if ( V_329 )
goto V_394;
if ( V_14 -> V_197 -> V_313 )
V_14 -> V_313 = V_14 -> V_197 -> V_313 ;
else
V_14 -> V_313 = ( ( F_29 ( V_14 , V_384 ) >> 1 ) & 0x1F ) + 1 ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , V_309 | V_307 |
V_167 | V_166 |
V_395 | V_310 ) ;
F_15 ( V_14 , V_102 , V_396 ) ;
F_58 ( V_14 -> V_84 , L_81
L_82
L_83 ,
V_14 -> V_303 , V_373 , V_374 ) ;
for ( V_108 = 0 ; V_108 < V_14 -> V_313 ; V_108 ++ ) {
V_329 = F_131 ( V_14 , V_108 ) ;
if ( V_329 )
F_72 ( V_14 -> V_84 , L_84 , V_108 ) ;
else
V_375 ++ ;
}
if ( V_375 ) {
F_58 ( V_14 -> V_84 , L_85 , V_375 ) ;
} else {
F_72 ( V_14 -> V_84 , L_86
L_87 , V_14 -> V_313 ) ;
goto V_394;
}
if ( V_14 -> V_233 & V_306 )
F_58 ( V_14 -> V_84 , L_88 ) ;
return 0 ;
V_394:
F_166 ( V_14 -> V_311 ) ;
V_392:
if ( V_14 -> V_141 && V_14 -> V_90 -> exit )
V_14 -> V_90 -> exit ( V_14 ) ;
V_383:
if ( V_14 -> V_381 )
F_167 ( V_14 -> V_381 ) ;
V_379:
if ( ! F_150 ( V_14 -> V_377 ) )
F_168 ( V_14 -> V_377 ) ;
V_378:
if ( ! F_150 ( V_14 -> V_376 ) )
F_168 ( V_14 -> V_376 ) ;
return V_329 ;
}
void F_169 ( struct V_34 * V_14 )
{
int V_108 ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , 0 ) ;
for ( V_108 = 0 ; V_108 < V_14 -> V_313 ; V_108 ++ ) {
F_72 ( V_14 -> V_84 , L_89 , V_108 ) ;
if ( V_14 -> V_5 [ V_108 ] )
F_139 ( V_14 -> V_5 [ V_108 ] , V_108 ) ;
}
F_15 ( V_14 , V_184 , 0 ) ;
F_15 ( V_14 , V_190 , 0 ) ;
F_166 ( V_14 -> V_311 ) ;
if ( V_14 -> V_141 && V_14 -> V_90 -> exit )
V_14 -> V_90 -> exit ( V_14 ) ;
if ( V_14 -> V_381 )
F_167 ( V_14 -> V_381 ) ;
if ( ! F_150 ( V_14 -> V_377 ) )
F_168 ( V_14 -> V_377 ) ;
if ( ! F_150 ( V_14 -> V_376 ) )
F_168 ( V_14 -> V_376 ) ;
}
int F_170 ( struct V_34 * V_14 )
{
if ( V_14 -> V_381 )
F_167 ( V_14 -> V_381 ) ;
return 0 ;
}
int F_171 ( struct V_34 * V_14 )
{
int V_108 , V_329 ;
if ( V_14 -> V_381 ) {
V_329 = F_157 ( V_14 -> V_381 ) ;
if ( V_329 ) {
F_13 ( V_14 -> V_84 ,
L_90 , V_329 ) ;
return V_329 ;
}
}
if ( ! F_144 ( V_14 ) ) {
V_329 = - V_162 ;
return V_329 ;
}
if ( V_14 -> V_141 && V_14 -> V_90 -> V_359 )
V_14 -> V_90 -> V_359 ( V_14 ) ;
F_15 ( V_14 , V_154 , V_14 -> V_146 ) ;
V_14 -> V_163 = 0 ;
F_15 ( V_14 , V_48 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , V_309 | V_307 |
V_167 | V_166 |
V_395 | V_310 ) ;
F_15 ( V_14 , V_102 , V_396 ) ;
for ( V_108 = 0 ; V_108 < V_14 -> V_313 ; V_108 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_108 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_33 -> V_397 & V_367 ) {
F_68 ( V_5 -> V_33 , & V_5 -> V_33 -> V_213 ) ;
F_56 ( V_5 , true ) ;
}
}
return 0 ;
}
static int T_6 F_172 ( void )
{
F_173 ( L_91 ) ;
return 0 ;
}
static void T_7 F_174 ( void )
{
}
