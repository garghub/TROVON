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
struct V_34 * V_14 = V_5 -> V_14 ;
int V_239 = F_74 ( V_33 ) ;
if ( V_232 -> V_233 & V_240 )
V_238 = 1 ;
else if ( V_232 -> V_241 )
V_238 = ! V_232 -> V_241 ( V_5 -> V_189 ) ;
else if ( ! F_75 ( V_239 ) )
V_238 = V_239 ;
else
V_238 = ( F_29 ( V_5 -> V_14 , V_242 ) & ( 1 << V_5 -> V_189 ) )
== 0 ? 1 : 0 ;
F_2 ( & V_14 -> V_15 ) ;
if ( V_238 ) {
F_24 ( V_210 , & V_5 -> V_18 ) ;
F_72 ( & V_33 -> V_47 , L_24 ) ;
} else {
F_76 ( V_210 , & V_5 -> V_18 ) ;
F_72 ( & V_33 -> V_47 , L_25 ) ;
}
F_4 ( & V_14 -> V_15 ) ;
return V_238 ;
}
static void F_77 ( struct V_4 * V_5 )
{
struct V_34 * V_14 = V_5 -> V_14 ;
V_43 V_183 ;
const V_43 V_243 = V_193 << V_5 -> V_189 ;
V_183 = F_29 ( V_14 , V_184 ) ;
if ( V_183 & V_243 ) {
F_15 ( V_14 , V_184 , V_183 & ~ V_243 ) ;
F_53 ( V_5 , V_185 |
V_60 , 0 ) ;
}
}
static void F_78 ( struct V_32 * V_33 , int V_244 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_34 * V_14 = V_5 -> V_14 ;
V_43 V_245 ;
V_245 = F_29 ( V_14 , V_165 ) ;
if ( V_244 ) {
F_77 ( V_5 ) ;
F_15 ( V_14 , V_165 ,
( V_245 | F_59 ( V_5 -> V_189 ) ) ) ;
} else {
F_15 ( V_14 , V_165 ,
( V_245 & ~ F_59 ( V_5 -> V_189 ) ) ) ;
}
}
static int F_79 ( struct V_32 * V_33 , V_43 V_16 )
{
struct V_4 * V_5 = F_17 ( V_33 ) ;
struct V_34 * V_14 = V_5 -> V_14 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
struct V_246 V_247 ;
int V_41 = - V_248 ;
if ( V_16 == V_249 ) {
if ( V_33 -> V_213 . V_215 == V_218 ) {
V_247 . V_250 = V_251 ;
V_247 . V_22 = sizeof( V_251 ) ;
} else if ( V_33 -> V_213 . V_215 == V_216 ) {
V_247 . V_250 = V_252 ;
V_247 . V_22 = sizeof( V_252 ) ;
} else {
return - V_138 ;
}
} else if ( V_16 == V_253 ) {
V_247 . V_250 = V_252 ;
V_247 . V_22 = sizeof( V_252 ) ;
} else {
F_13 ( V_14 -> V_84 ,
L_26 , V_16 ) ;
return - V_138 ;
}
if ( V_50 && V_50 -> V_254 )
V_41 = V_50 -> V_254 ( V_5 , V_16 , & V_247 ) ;
return V_41 ;
}
static void F_80 ( struct V_34 * V_14 , struct V_7 * V_8 )
__releases( &host->lock
static int F_81 ( struct V_34 * V_14 , struct V_9 * V_10 )
{
V_43 V_255 = V_14 -> V_181 ;
V_14 -> V_181 = 0 ;
if ( V_10 -> V_18 & V_61 ) {
if ( V_10 -> V_18 & V_63 ) {
V_10 -> V_19 [ 3 ] = F_29 ( V_14 , V_256 ) ;
V_10 -> V_19 [ 2 ] = F_29 ( V_14 , V_257 ) ;
V_10 -> V_19 [ 1 ] = F_29 ( V_14 , V_258 ) ;
V_10 -> V_19 [ 0 ] = F_29 ( V_14 , V_259 ) ;
} else {
V_10 -> V_19 [ 0 ] = F_29 ( V_14 , V_256 ) ;
V_10 -> V_19 [ 1 ] = 0 ;
V_10 -> V_19 [ 2 ] = 0 ;
V_10 -> V_19 [ 3 ] = 0 ;
}
}
if ( V_255 & V_260 )
V_10 -> error = - V_261 ;
else if ( ( V_10 -> V_18 & V_65 ) && ( V_255 & V_262 ) )
V_10 -> error = - V_263 ;
else if ( V_255 & V_264 )
V_10 -> error = - V_265 ;
else
V_10 -> error = 0 ;
if ( V_10 -> error ) {
if ( V_14 -> V_233 & V_266 )
F_82 ( 20 ) ;
}
return V_10 -> error ;
}
static int F_83 ( struct V_34 * V_14 , struct V_12 * V_13 )
{
V_43 V_255 = V_14 -> V_200 ;
if ( V_255 & V_267 ) {
if ( V_255 & V_268 ) {
V_13 -> error = - V_261 ;
} else if ( V_255 & V_269 ) {
V_13 -> error = - V_263 ;
} else if ( V_255 & V_270 ) {
if ( V_14 -> V_169 ==
V_171 ) {
V_13 -> V_20 = 0 ;
V_13 -> error = - V_261 ;
} else if ( V_14 -> V_169 ==
V_170 ) {
V_13 -> error = - V_265 ;
}
} else {
V_13 -> error = - V_265 ;
}
F_13 ( V_14 -> V_84 , L_27 , V_255 ) ;
F_84 ( V_14 ) ;
} else {
V_13 -> V_20 = V_13 -> V_21 * V_13 -> V_22 ;
V_13 -> error = 0 ;
}
return V_13 -> error ;
}
static void F_85 ( unsigned long V_271 )
{
struct V_34 * V_14 = (struct V_34 * ) V_271 ;
struct V_12 * V_13 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
enum V_272 V_44 ;
enum V_272 V_273 ;
unsigned int V_41 ;
F_86 ( & V_14 -> V_15 ) ;
V_44 = V_14 -> V_44 ;
V_13 = V_14 -> V_13 ;
V_8 = V_14 -> V_8 ;
do {
V_273 = V_44 ;
switch ( V_44 ) {
case V_206 :
break;
case V_207 :
if ( ! F_61 ( V_274 ,
& V_14 -> V_45 ) )
break;
V_10 = V_14 -> V_10 ;
V_14 -> V_10 = NULL ;
F_24 ( V_274 , & V_14 -> V_46 ) ;
V_41 = F_81 ( V_14 , V_10 ) ;
if ( V_10 == V_8 -> V_205 && ! V_41 ) {
V_273 = V_44 = V_207 ;
F_60 ( V_14 , V_14 -> V_199 ,
V_8 -> V_10 ) ;
goto V_275;
}
if ( V_10 -> V_13 && V_41 ) {
F_23 ( V_14 ) ;
F_22 ( V_14 , V_13 ) ;
V_44 = V_276 ;
break;
}
if ( ! V_10 -> V_13 || V_41 ) {
F_80 ( V_14 , V_8 ) ;
goto V_275;
}
V_273 = V_44 = V_277 ;
case V_277 :
if ( F_61 ( V_278 ,
& V_14 -> V_45 ) ) {
F_23 ( V_14 ) ;
F_22 ( V_14 , V_13 ) ;
V_44 = V_279 ;
break;
}
if ( ! F_61 ( V_92 ,
& V_14 -> V_45 ) )
break;
F_24 ( V_92 , & V_14 -> V_46 ) ;
V_273 = V_44 = V_280 ;
case V_280 :
if ( ! F_61 ( V_281 ,
& V_14 -> V_45 ) )
break;
V_14 -> V_13 = NULL ;
F_24 ( V_281 , & V_14 -> V_46 ) ;
V_41 = F_83 ( V_14 , V_13 ) ;
if ( ! V_41 ) {
if ( ! V_13 -> V_11 || V_8 -> V_205 ) {
if ( V_8 -> V_205 )
V_13 -> V_11 -> error = 0 ;
F_80 ( V_14 , V_8 ) ;
goto V_275;
}
if ( V_13 -> V_11 )
F_22 ( V_14 , V_13 ) ;
}
V_273 = V_44 = V_276 ;
case V_276 :
if ( ! F_61 ( V_274 ,
& V_14 -> V_45 ) )
break;
if ( V_8 -> V_10 -> error && V_8 -> V_13 )
F_84 ( V_14 ) ;
V_14 -> V_10 = NULL ;
V_14 -> V_13 = NULL ;
if ( V_8 -> V_11 )
F_81 ( V_14 , V_8 -> V_11 ) ;
else
V_14 -> V_181 = 0 ;
F_80 ( V_14 , V_8 ) ;
goto V_275;
case V_279 :
if ( ! F_61 ( V_92 ,
& V_14 -> V_45 ) )
break;
V_44 = V_280 ;
break;
}
} while ( V_44 != V_273 );
V_14 -> V_44 = V_44 ;
V_275:
F_87 ( & V_14 -> V_15 ) ;
}
static void F_88 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
memcpy ( ( void * ) & V_14 -> V_284 , V_282 , V_283 ) ;
V_14 -> V_177 = V_283 ;
}
static int F_89 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
V_283 = F_90 ( V_283 , ( 1 << V_14 -> V_144 ) - V_14 -> V_177 ) ;
memcpy ( ( void * ) & V_14 -> V_284 + V_14 -> V_177 , V_282 , V_283 ) ;
V_14 -> V_177 += V_283 ;
return V_283 ;
}
static int F_91 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
V_283 = F_90 ( V_283 , ( int ) V_14 -> V_177 ) ;
if ( V_283 ) {
memcpy ( V_282 , ( void * ) & V_14 -> V_284 + V_14 -> V_176 ,
V_283 ) ;
V_14 -> V_177 -= V_283 ;
V_14 -> V_176 += V_283 ;
}
return V_283 ;
}
static void F_92 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
memcpy ( V_282 , & V_14 -> V_284 , V_283 ) ;
V_14 -> V_176 = V_283 ;
V_14 -> V_177 = ( 1 << V_14 -> V_144 ) - V_283 ;
}
static void F_93 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
int V_285 = V_283 ;
if ( F_94 ( V_14 -> V_177 ) ) {
int V_286 = F_89 ( V_14 , V_282 , V_283 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
if ( V_14 -> V_177 == 2 ) {
F_95 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_14 -> V_288 ) ;
V_14 -> V_177 = 0 ;
}
}
#ifndef F_97
if ( F_94 ( ( unsigned long ) V_282 & 0x1 ) ) {
while ( V_283 >= 2 ) {
T_1 V_289 [ 64 ] ;
int V_286 = F_90 ( V_283 & - 2 , ( int ) sizeof( V_289 ) ) ;
int V_290 = V_286 >> 1 ;
int V_108 ;
memcpy ( V_289 , V_282 , V_286 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
for ( V_108 = 0 ; V_108 < V_290 ; ++ V_108 )
F_95 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_289 [ V_108 ] ) ;
}
} else
#endif
{
T_1 * V_197 = V_282 ;
for (; V_283 >= 2 ; V_283 -= 2 )
F_95 ( V_14 , F_96 ( V_14 -> V_287 ) , * V_197 ++ ) ;
V_282 = V_197 ;
}
if ( V_283 ) {
F_88 ( V_14 , V_282 , V_283 ) ;
if ( ( V_13 -> V_20 + V_285 ) ==
( V_13 -> V_22 * V_13 -> V_21 ) )
F_95 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_14 -> V_288 ) ;
}
}
static void F_98 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
#ifndef F_97
if ( F_94 ( ( unsigned long ) V_282 & 0x1 ) ) {
while ( V_283 >= 2 ) {
T_1 V_289 [ 64 ] ;
int V_286 = F_90 ( V_283 & - 2 , ( int ) sizeof( V_289 ) ) ;
int V_290 = V_286 >> 1 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_290 ; ++ V_108 )
V_289 [ V_108 ] = F_99 ( V_14 ,
F_96 ( V_14 -> V_287 ) ) ;
memcpy ( V_282 , V_289 , V_286 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
}
} else
#endif
{
T_1 * V_197 = V_282 ;
for (; V_283 >= 2 ; V_283 -= 2 )
* V_197 ++ = F_99 ( V_14 , F_96 ( V_14 -> V_287 ) ) ;
V_282 = V_197 ;
}
if ( V_283 ) {
V_14 -> V_288 = F_99 ( V_14 , F_96 ( V_14 -> V_287 ) ) ;
F_92 ( V_14 , V_282 , V_283 ) ;
}
}
static void F_100 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
int V_285 = V_283 ;
if ( F_94 ( V_14 -> V_177 ) ) {
int V_286 = F_89 ( V_14 , V_282 , V_283 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
if ( V_14 -> V_177 == 4 ) {
F_15 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_14 -> V_291 ) ;
V_14 -> V_177 = 0 ;
}
}
#ifndef F_97
if ( F_94 ( ( unsigned long ) V_282 & 0x3 ) ) {
while ( V_283 >= 4 ) {
V_43 V_289 [ 32 ] ;
int V_286 = F_90 ( V_283 & - 4 , ( int ) sizeof( V_289 ) ) ;
int V_290 = V_286 >> 2 ;
int V_108 ;
memcpy ( V_289 , V_282 , V_286 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
for ( V_108 = 0 ; V_108 < V_290 ; ++ V_108 )
F_15 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_289 [ V_108 ] ) ;
}
} else
#endif
{
V_43 * V_197 = V_282 ;
for (; V_283 >= 4 ; V_283 -= 4 )
F_15 ( V_14 , F_96 ( V_14 -> V_287 ) , * V_197 ++ ) ;
V_282 = V_197 ;
}
if ( V_283 ) {
F_88 ( V_14 , V_282 , V_283 ) ;
if ( ( V_13 -> V_20 + V_285 ) ==
( V_13 -> V_22 * V_13 -> V_21 ) )
F_15 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_14 -> V_291 ) ;
}
}
static void F_101 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
#ifndef F_97
if ( F_94 ( ( unsigned long ) V_282 & 0x3 ) ) {
while ( V_283 >= 4 ) {
V_43 V_289 [ 32 ] ;
int V_286 = F_90 ( V_283 & - 4 , ( int ) sizeof( V_289 ) ) ;
int V_290 = V_286 >> 2 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_290 ; ++ V_108 )
V_289 [ V_108 ] = F_29 ( V_14 ,
F_96 ( V_14 -> V_287 ) ) ;
memcpy ( V_282 , V_289 , V_286 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
}
} else
#endif
{
V_43 * V_197 = V_282 ;
for (; V_283 >= 4 ; V_283 -= 4 )
* V_197 ++ = F_29 ( V_14 , F_96 ( V_14 -> V_287 ) ) ;
V_282 = V_197 ;
}
if ( V_283 ) {
V_14 -> V_291 = F_29 ( V_14 , F_96 ( V_14 -> V_287 ) ) ;
F_92 ( V_14 , V_282 , V_283 ) ;
}
}
static void F_102 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
int V_285 = V_283 ;
if ( F_94 ( V_14 -> V_177 ) ) {
int V_286 = F_89 ( V_14 , V_282 , V_283 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
if ( V_14 -> V_177 == 8 ) {
F_103 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_14 -> V_284 ) ;
V_14 -> V_177 = 0 ;
}
}
#ifndef F_97
if ( F_94 ( ( unsigned long ) V_282 & 0x7 ) ) {
while ( V_283 >= 8 ) {
T_2 V_289 [ 16 ] ;
int V_286 = F_90 ( V_283 & - 8 , ( int ) sizeof( V_289 ) ) ;
int V_290 = V_286 >> 3 ;
int V_108 ;
memcpy ( V_289 , V_282 , V_286 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
for ( V_108 = 0 ; V_108 < V_290 ; ++ V_108 )
F_103 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_289 [ V_108 ] ) ;
}
} else
#endif
{
T_2 * V_197 = V_282 ;
for (; V_283 >= 8 ; V_283 -= 8 )
F_103 ( V_14 , F_96 ( V_14 -> V_287 ) , * V_197 ++ ) ;
V_282 = V_197 ;
}
if ( V_283 ) {
F_88 ( V_14 , V_282 , V_283 ) ;
if ( ( V_13 -> V_20 + V_285 ) ==
( V_13 -> V_22 * V_13 -> V_21 ) )
F_103 ( V_14 , F_96 ( V_14 -> V_287 ) ,
V_14 -> V_284 ) ;
}
}
static void F_104 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
#ifndef F_97
if ( F_94 ( ( unsigned long ) V_282 & 0x7 ) ) {
while ( V_283 >= 8 ) {
T_2 V_289 [ 16 ] ;
int V_286 = F_90 ( V_283 & - 8 , ( int ) sizeof( V_289 ) ) ;
int V_290 = V_286 >> 3 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_290 ; ++ V_108 )
V_289 [ V_108 ] = F_105 ( V_14 ,
F_96 ( V_14 -> V_287 ) ) ;
memcpy ( V_282 , V_289 , V_286 ) ;
V_282 += V_286 ;
V_283 -= V_286 ;
}
} else
#endif
{
T_2 * V_197 = V_282 ;
for (; V_283 >= 8 ; V_283 -= 8 )
* V_197 ++ = F_105 ( V_14 , F_96 ( V_14 -> V_287 ) ) ;
V_282 = V_197 ;
}
if ( V_283 ) {
V_14 -> V_284 = F_105 ( V_14 , F_96 ( V_14 -> V_287 ) ) ;
F_92 ( V_14 , V_282 , V_283 ) ;
}
}
static void F_106 ( struct V_34 * V_14 , void * V_282 , int V_283 )
{
int V_286 ;
V_286 = F_91 ( V_14 , V_282 , V_283 ) ;
if ( F_94 ( V_286 == V_283 ) )
return;
V_282 += V_286 ;
V_283 -= V_286 ;
V_14 -> V_292 ( V_14 , V_282 , V_283 ) ;
}
static void F_107 ( struct V_34 * V_14 , bool V_293 )
{
struct V_294 * V_175 = & V_14 -> V_175 ;
void * V_282 ;
unsigned int V_139 ;
struct V_12 * V_13 = V_14 -> V_13 ;
int V_295 = V_14 -> V_144 ;
V_43 V_255 ;
unsigned int V_286 ;
unsigned int V_296 , V_297 ;
do {
if ( ! F_108 ( V_175 ) )
goto V_153;
V_14 -> V_96 = V_175 -> V_298 . V_96 ;
V_282 = V_175 -> V_299 ;
V_296 = V_175 -> V_112 ;
V_139 = 0 ;
do {
V_297 = ( F_109 ( F_29 ( V_14 , V_300 ) )
<< V_295 ) + V_14 -> V_177 ;
V_286 = F_90 ( V_296 , V_297 ) ;
if ( ! V_286 )
break;
F_106 ( V_14 , ( void * ) ( V_282 + V_139 ) , V_286 ) ;
V_13 -> V_20 += V_286 ;
V_139 += V_286 ;
V_296 -= V_286 ;
} while ( V_296 );
V_175 -> V_301 = V_139 ;
V_255 = F_29 ( V_14 , V_302 ) ;
F_15 ( V_14 , V_178 , V_166 ) ;
} while ( ( V_255 & V_166 ) ||
( V_293 && F_109 ( F_29 ( V_14 , V_300 ) ) ) );
if ( ! V_296 ) {
if ( ! F_108 ( V_175 ) )
goto V_153;
V_175 -> V_301 = 0 ;
}
F_110 ( V_175 ) ;
return;
V_153:
F_110 ( V_175 ) ;
V_14 -> V_96 = NULL ;
F_111 () ;
F_24 ( V_92 , & V_14 -> V_45 ) ;
}
static void F_112 ( struct V_34 * V_14 )
{
struct V_294 * V_175 = & V_14 -> V_175 ;
void * V_282 ;
unsigned int V_139 ;
struct V_12 * V_13 = V_14 -> V_13 ;
int V_295 = V_14 -> V_144 ;
V_43 V_255 ;
unsigned int V_286 ;
unsigned int V_152 = V_14 -> V_152 ;
unsigned int V_296 , V_297 ;
do {
if ( ! F_108 ( V_175 ) )
goto V_153;
V_14 -> V_96 = V_175 -> V_298 . V_96 ;
V_282 = V_175 -> V_299 ;
V_296 = V_175 -> V_112 ;
V_139 = 0 ;
do {
V_297 = ( ( V_152 -
F_109 ( F_29 ( V_14 , V_300 ) ) )
<< V_295 ) - V_14 -> V_177 ;
V_286 = F_90 ( V_296 , V_297 ) ;
if ( ! V_286 )
break;
V_14 -> V_303 ( V_14 , ( void * ) ( V_282 + V_139 ) , V_286 ) ;
V_13 -> V_20 += V_286 ;
V_139 += V_286 ;
V_296 -= V_286 ;
} while ( V_296 );
V_175 -> V_301 = V_139 ;
V_255 = F_29 ( V_14 , V_302 ) ;
F_15 ( V_14 , V_178 , V_167 ) ;
} while ( V_255 & V_167 );
if ( ! V_296 ) {
if ( ! F_108 ( V_175 ) )
goto V_153;
V_175 -> V_301 = 0 ;
}
F_110 ( V_175 ) ;
return;
V_153:
F_110 ( V_175 ) ;
V_14 -> V_96 = NULL ;
F_111 () ;
F_24 ( V_92 , & V_14 -> V_45 ) ;
}
static void F_113 ( struct V_34 * V_14 , V_43 V_255 )
{
if ( ! V_14 -> V_181 )
V_14 -> V_181 = V_255 ;
F_111 () ;
F_24 ( V_274 , & V_14 -> V_45 ) ;
F_32 ( & V_14 -> V_107 ) ;
}
static T_3 F_114 ( int V_304 , void * V_305 )
{
struct V_34 * V_14 = V_305 ;
V_43 V_306 ;
int V_108 ;
V_306 = F_29 ( V_14 , V_302 ) ;
if ( V_14 -> V_233 & V_307 ) {
if ( ! V_306 &&
( ( F_29 ( V_14 , V_300 ) >> 17 ) & 0x1fff ) )
V_306 |= V_308 ;
}
if ( V_306 ) {
if ( V_306 & V_309 ) {
F_15 ( V_14 , V_178 , V_309 ) ;
V_14 -> V_181 = V_306 ;
F_111 () ;
F_24 ( V_274 , & V_14 -> V_45 ) ;
}
if ( V_306 & V_267 ) {
F_15 ( V_14 , V_178 , V_267 ) ;
V_14 -> V_200 = V_306 ;
F_111 () ;
F_24 ( V_278 , & V_14 -> V_45 ) ;
F_32 ( & V_14 -> V_107 ) ;
}
if ( V_306 & V_308 ) {
F_15 ( V_14 , V_178 , V_308 ) ;
if ( ! V_14 -> V_200 )
V_14 -> V_200 = V_306 ;
F_111 () ;
if ( V_14 -> V_169 == V_170 ) {
if ( V_14 -> V_96 != NULL )
F_107 ( V_14 , true ) ;
}
F_24 ( V_281 , & V_14 -> V_45 ) ;
F_32 ( & V_14 -> V_107 ) ;
}
if ( V_306 & V_166 ) {
F_15 ( V_14 , V_178 , V_166 ) ;
if ( V_14 -> V_169 == V_170 && V_14 -> V_96 )
F_107 ( V_14 , false ) ;
}
if ( V_306 & V_167 ) {
F_15 ( V_14 , V_178 , V_167 ) ;
if ( V_14 -> V_169 == V_171 && V_14 -> V_96 )
F_112 ( V_14 ) ;
}
if ( V_306 & V_310 ) {
F_15 ( V_14 , V_178 , V_310 ) ;
F_113 ( V_14 , V_306 ) ;
}
if ( V_306 & V_311 ) {
F_15 ( V_14 , V_178 , V_311 ) ;
F_115 ( V_14 -> V_312 , & V_14 -> V_313 ) ;
}
for ( V_108 = 0 ; V_108 < V_14 -> V_314 ; V_108 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_108 ] ;
if ( V_306 & F_59 ( V_108 ) ) {
F_15 ( V_14 , V_178 , F_59 ( V_108 ) ) ;
F_116 ( V_5 -> V_33 ) ;
}
}
}
#ifdef F_45
V_306 = F_29 ( V_14 , V_128 ) ;
if ( V_306 & ( V_133 | V_132 ) ) {
F_15 ( V_14 , V_128 , V_133 | V_132 ) ;
F_15 ( V_14 , V_128 , V_131 ) ;
V_14 -> V_90 -> V_315 ( V_14 ) ;
}
#endif
return V_316 ;
}
static void F_117 ( struct V_317 * V_318 )
{
struct V_34 * V_14 = F_118 ( V_318 , struct V_34 , V_313 ) ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_314 ; V_108 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_108 ] ;
struct V_32 * V_33 = V_5 -> V_33 ;
struct V_7 * V_8 ;
int V_238 ;
V_238 = F_73 ( V_33 ) ;
while ( V_238 != V_5 -> V_319 ) {
F_72 ( & V_5 -> V_33 -> V_47 , L_28 ,
V_238 ? L_29 : L_30 ) ;
F_2 ( & V_14 -> V_15 ) ;
V_5 -> V_319 = V_238 ;
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
case V_277 :
V_8 -> V_13 -> error = - V_211 ;
F_23 ( V_14 ) ;
break;
case V_280 :
case V_279 :
if ( V_8 -> V_13 -> error == - V_52 )
V_8 -> V_13 -> error = - V_211 ;
case V_276 :
if ( V_8 -> V_11 )
V_8 -> V_11 -> error = - V_211 ;
break;
}
F_80 ( V_14 , V_8 ) ;
} else {
F_119 ( & V_5 -> V_208 ) ;
V_8 -> V_10 -> error = - V_211 ;
if ( V_8 -> V_13 )
V_8 -> V_13 -> error = - V_211 ;
if ( V_8 -> V_11 )
V_8 -> V_11 -> error = - V_211 ;
F_87 ( & V_14 -> V_15 ) ;
F_67 ( V_5 -> V_33 , V_8 ) ;
F_86 ( & V_14 -> V_15 ) ;
}
}
if ( V_238 == 0 ) {
F_84 ( V_14 ) ;
#ifdef F_45
F_28 ( V_14 ) ;
#endif
}
F_4 ( & V_14 -> V_15 ) ;
V_238 = F_73 ( V_33 ) ;
}
F_120 ( V_5 -> V_33 ,
F_54 ( V_14 -> V_197 -> V_320 ) ) ;
}
}
static struct V_321 * F_121 ( struct V_322 * V_84 , T_4 V_5 )
{
struct V_321 * V_323 ;
const T_5 * V_299 ;
int V_286 ;
if ( ! V_84 || ! V_84 -> V_324 )
return NULL ;
F_122 (dev->of_node, np) {
V_299 = F_123 ( V_323 , L_31 , & V_286 ) ;
if ( ! V_299 || ( V_286 < sizeof( int ) ) )
continue;
if ( F_124 ( V_299 ) == V_5 )
return V_323 ;
}
return NULL ;
}
static int F_125 ( struct V_322 * V_84 , T_4 V_5 )
{
struct V_321 * V_323 = F_121 ( V_84 , V_5 ) ;
int V_233 = 0 ;
int V_151 ;
for ( V_151 = 0 ; V_151 < F_126 ( V_325 ) ; V_151 ++ )
if ( F_123 ( V_323 , V_325 [ V_151 ] . V_326 , NULL ) )
V_233 |= V_325 [ V_151 ] . V_189 ;
return V_233 ;
}
static V_43 F_127 ( struct V_322 * V_84 , T_4 V_5 )
{
struct V_321 * V_323 = F_121 ( V_84 , V_5 ) ;
V_43 V_327 = 1 ;
if ( ! V_323 )
return 1 ;
if ( F_128 ( V_323 , L_32 , & V_327 ) )
F_13 ( V_84 , L_33
L_34 ) ;
return V_327 ;
}
static int F_129 ( struct V_322 * V_84 , T_4 V_5 )
{
struct V_321 * V_323 = F_121 ( V_84 , V_5 ) ;
int V_328 ;
if ( ! V_323 )
return - V_138 ;
V_328 = F_130 ( V_323 , L_35 , 0 ) ;
if ( ! F_70 ( V_328 ) )
return - V_138 ;
if ( F_131 ( V_84 , V_328 , L_36 ) ) {
F_132 ( V_84 , L_37 , V_328 ) ;
return - V_138 ;
}
return V_328 ;
}
static void F_133 ( struct V_322 * V_84 , T_4 V_5 ,
struct V_32 * V_33 )
{
struct V_321 * V_323 = F_121 ( V_84 , V_5 ) ;
int V_328 ;
if ( ! V_323 )
return;
V_328 = F_130 ( V_323 , L_38 , 0 ) ;
if ( ! F_70 ( V_328 ) )
return;
if ( F_134 ( V_33 , V_328 , 0 ) )
F_132 ( V_84 , L_37 , V_328 ) ;
}
static int F_125 ( struct V_322 * V_84 , T_4 V_5 )
{
return 0 ;
}
static V_43 F_127 ( struct V_322 * V_84 , T_4 V_5 )
{
return 1 ;
}
static struct V_321 * F_121 ( struct V_322 * V_84 , T_4 V_5 )
{
return NULL ;
}
static int F_129 ( struct V_322 * V_84 , T_4 V_5 )
{
return - V_138 ;
}
static void F_133 ( struct V_322 * V_84 , T_4 V_5 ,
struct V_32 * V_33 )
{
return;
}
static int F_135 ( struct V_34 * V_14 , unsigned int V_189 )
{
struct V_32 * V_33 ;
struct V_4 * V_5 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_329 , V_330 ;
V_43 V_331 [ 2 ] ;
T_4 V_215 ;
V_33 = F_136 ( sizeof( struct V_4 ) , V_14 -> V_84 ) ;
if ( ! V_33 )
return - V_332 ;
V_5 = F_17 ( V_33 ) ;
V_5 -> V_189 = V_189 ;
V_5 -> V_33 = V_33 ;
V_5 -> V_14 = V_14 ;
V_14 -> V_5 [ V_189 ] = V_5 ;
V_5 -> V_233 = F_125 ( V_14 -> V_84 , V_5 -> V_189 ) ;
V_33 -> V_333 = & V_334 ;
if ( F_137 ( V_14 -> V_84 -> V_324 ,
L_39 , V_331 , 2 ) ) {
V_33 -> V_335 = V_336 ;
V_33 -> V_337 = V_338 ;
} else {
V_33 -> V_335 = V_331 [ 0 ] ;
V_33 -> V_337 = V_331 [ 1 ] ;
}
if ( V_14 -> V_197 -> V_339 )
V_33 -> V_227 = V_14 -> V_197 -> V_339 ( V_189 ) ;
else
V_33 -> V_227 = V_340 | V_341 ;
if ( V_14 -> V_197 -> V_226 )
V_14 -> V_197 -> V_226 ( V_189 , 0 ) ;
if ( V_14 -> V_197 -> V_342 )
V_33 -> V_342 = V_14 -> V_197 -> V_342 ;
if ( V_14 -> V_197 -> V_343 )
V_33 -> V_343 = V_14 -> V_197 -> V_343 ;
if ( V_14 -> V_84 -> V_324 ) {
V_329 = F_138 ( V_14 -> V_84 -> V_324 , L_40 ) ;
if ( V_329 < 0 )
V_329 = 0 ;
} else {
V_329 = F_139 ( V_14 -> V_84 ) -> V_189 ;
}
if ( V_50 && V_50 -> V_342 )
V_33 -> V_342 |= V_50 -> V_342 [ V_329 ] ;
if ( V_14 -> V_197 -> V_344 )
V_33 -> V_344 = V_14 -> V_197 -> V_344 ;
if ( V_14 -> V_197 -> V_345 )
V_215 = V_14 -> V_197 -> V_345 ( V_5 -> V_189 ) ;
else if ( V_14 -> V_84 -> V_324 )
V_215 = F_127 ( V_14 -> V_84 , V_5 -> V_189 ) ;
else
V_215 = 1 ;
switch ( V_215 ) {
case 8 :
V_33 -> V_342 |= V_346 ;
case 4 :
V_33 -> V_342 |= V_347 ;
}
if ( V_14 -> V_197 -> V_348 ) {
V_33 -> V_349 = V_14 -> V_197 -> V_348 -> V_349 ;
V_33 -> V_350 = V_14 -> V_197 -> V_348 -> V_350 ;
V_33 -> V_351 = V_14 -> V_197 -> V_348 -> V_351 ;
V_33 -> V_352 = V_14 -> V_197 -> V_348 -> V_352 ;
V_33 -> V_353 = V_14 -> V_197 -> V_348 -> V_353 ;
} else {
#ifdef F_45
V_33 -> V_349 = V_14 -> V_123 ;
V_33 -> V_350 = 65536 ;
V_33 -> V_351 = V_14 -> V_123 ;
V_33 -> V_353 = 0x1000 ;
V_33 -> V_352 = V_33 -> V_353 * V_33 -> V_351 ;
#else
V_33 -> V_349 = 64 ;
V_33 -> V_350 = 65536 ;
V_33 -> V_351 = 512 ;
V_33 -> V_352 = V_33 -> V_350 * V_33 -> V_351 ;
V_33 -> V_353 = V_33 -> V_352 ;
#endif
}
V_5 -> V_236 = F_129 ( V_14 -> V_84 , V_5 -> V_189 ) ;
F_133 ( V_14 -> V_84 , V_5 -> V_189 , V_33 ) ;
V_330 = F_140 ( V_33 ) ;
if ( V_330 )
goto V_354;
#if F_141 ( V_355 )
F_9 ( V_5 ) ;
#endif
V_5 -> V_319 = 0 ;
return 0 ;
V_354:
F_142 ( V_33 ) ;
return - V_138 ;
}
static void F_143 ( struct V_4 * V_5 , unsigned int V_189 )
{
if ( V_5 -> V_14 -> V_197 -> exit )
V_5 -> V_14 -> V_197 -> exit ( V_189 ) ;
F_144 ( V_5 -> V_33 ) ;
V_5 -> V_14 -> V_5 [ V_189 ] = NULL ;
F_142 ( V_5 -> V_33 ) ;
}
static void F_145 ( struct V_34 * V_14 )
{
V_14 -> V_111 = F_146 ( V_14 -> V_84 , V_124 ,
& V_14 -> V_126 , V_356 ) ;
if ( ! V_14 -> V_111 ) {
F_13 ( V_14 -> V_84 , L_41 ,
V_357 ) ;
goto V_358;
}
#ifdef F_45
V_14 -> V_90 = & V_359 ;
F_58 ( V_14 -> V_84 , L_42 ) ;
#endif
if ( ! V_14 -> V_90 )
goto V_358;
if ( V_14 -> V_90 -> V_360 && V_14 -> V_90 -> V_168 &&
V_14 -> V_90 -> V_11 && V_14 -> V_90 -> V_91 ) {
if ( V_14 -> V_90 -> V_360 ( V_14 ) ) {
F_13 ( V_14 -> V_84 , L_43
L_44 , V_357 ) ;
goto V_358;
}
} else {
F_13 ( V_14 -> V_84 , L_45 ) ;
goto V_358;
}
V_14 -> V_141 = 1 ;
return;
V_358:
F_58 ( V_14 -> V_84 , L_46 ) ;
V_14 -> V_141 = 0 ;
return;
}
static bool F_147 ( struct V_34 * V_14 , V_43 V_361 )
{
unsigned long V_179 = V_180 + F_54 ( 500 ) ;
V_43 V_362 ;
V_362 = F_29 ( V_14 , V_102 ) ;
V_362 |= V_361 ;
F_15 ( V_14 , V_102 , V_362 ) ;
do {
V_362 = F_29 ( V_14 , V_102 ) ;
if ( ! ( V_362 & V_361 ) )
return true ;
} while ( F_55 ( V_180 , V_179 ) );
F_13 ( V_14 -> V_84 ,
L_47 ,
V_362 & V_361 ) ;
return false ;
}
static inline bool F_84 ( struct V_34 * V_14 )
{
if ( V_14 -> V_96 ) {
F_110 ( & V_14 -> V_175 ) ;
V_14 -> V_96 = NULL ;
}
return F_147 ( V_14 , V_363 ) ;
}
static inline bool F_148 ( struct V_34 * V_14 )
{
return F_147 ( V_14 ,
V_363 |
V_364 |
V_104 ) ;
}
static struct V_231 * F_149 ( struct V_34 * V_14 )
{
struct V_231 * V_197 ;
struct V_322 * V_84 = V_14 -> V_84 ;
struct V_321 * V_323 = V_84 -> V_324 ;
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_151 , V_330 ;
V_43 V_365 ;
V_197 = F_150 ( V_84 , sizeof( * V_197 ) , V_356 ) ;
if ( ! V_197 ) {
F_13 ( V_84 , L_48 ) ;
return F_151 ( - V_332 ) ;
}
if ( F_128 ( V_84 -> V_324 , L_49 ,
& V_197 -> V_314 ) ) {
F_58 ( V_84 , L_50
L_51 ) ;
V_197 -> V_314 = 1 ;
}
for ( V_151 = 0 ; V_151 < F_126 ( V_366 ) ; V_151 ++ )
if ( F_123 ( V_323 , V_366 [ V_151 ] . V_326 , NULL ) )
V_197 -> V_233 |= V_366 [ V_151 ] . V_189 ;
if ( F_128 ( V_323 , L_52 , & V_197 -> V_152 ) )
F_58 ( V_84 , L_53
L_54 ) ;
F_128 ( V_323 , L_55 , & V_197 -> V_320 ) ;
if ( ! F_128 ( V_323 , L_56 , & V_365 ) )
V_197 -> V_187 = V_365 ;
if ( V_50 && V_50 -> V_367 ) {
V_330 = V_50 -> V_367 ( V_14 ) ;
if ( V_330 )
return F_151 ( V_330 ) ;
}
if ( F_152 ( V_323 , L_57 , NULL ) )
V_197 -> V_343 |= V_368 ;
if ( F_152 ( V_323 , L_58 , NULL ) )
V_197 -> V_343 |= V_369 ;
if ( F_152 ( V_323 , L_59 , NULL ) )
V_197 -> V_342 |= V_370 | V_371 ;
if ( F_152 ( V_323 , L_60 , NULL ) )
V_197 -> V_344 |= V_372 ;
if ( F_152 ( V_323 , L_61 , NULL ) )
V_197 -> V_344 |= V_373 ;
if ( F_123 ( V_323 , L_62 , NULL ) )
V_197 -> V_344 |= V_374 ;
return V_197 ;
}
static struct V_231 * F_149 ( struct V_34 * V_14 )
{
return F_151 ( - V_138 ) ;
}
int F_153 ( struct V_34 * V_14 )
{
const struct V_49 * V_50 = V_14 -> V_50 ;
int V_375 , V_108 , V_330 = 0 ;
V_43 V_376 ;
int V_377 = 0 ;
if ( ! V_14 -> V_197 ) {
V_14 -> V_197 = F_149 ( V_14 ) ;
if ( F_154 ( V_14 -> V_197 ) ) {
F_13 ( V_14 -> V_84 , L_63 ) ;
return - V_138 ;
}
}
if ( ! V_14 -> V_197 -> V_198 && V_14 -> V_197 -> V_314 > 1 ) {
F_13 ( V_14 -> V_84 ,
L_64 ) ;
return - V_162 ;
}
V_14 -> V_378 = F_155 ( V_14 -> V_84 , L_65 ) ;
if ( F_154 ( V_14 -> V_378 ) ) {
F_72 ( V_14 -> V_84 , L_66 ) ;
} else {
V_330 = F_156 ( V_14 -> V_378 ) ;
if ( V_330 ) {
F_13 ( V_14 -> V_84 , L_67 ) ;
return V_330 ;
}
}
V_14 -> V_379 = F_155 ( V_14 -> V_84 , L_68 ) ;
if ( F_154 ( V_14 -> V_379 ) ) {
F_72 ( V_14 -> V_84 , L_69 ) ;
V_14 -> V_187 = V_14 -> V_197 -> V_187 ;
} else {
V_330 = F_156 ( V_14 -> V_379 ) ;
if ( V_330 ) {
F_13 ( V_14 -> V_84 , L_70 ) ;
goto V_380;
}
if ( V_14 -> V_197 -> V_187 ) {
V_330 = F_157 ( V_14 -> V_379 , V_14 -> V_197 -> V_187 ) ;
if ( V_330 )
F_132 ( V_14 -> V_84 ,
L_71 ,
V_14 -> V_197 -> V_187 ) ;
}
V_14 -> V_187 = F_158 ( V_14 -> V_379 ) ;
}
if ( V_50 && V_50 -> V_360 ) {
V_330 = V_50 -> V_360 ( V_14 ) ;
if ( V_330 ) {
F_13 ( V_14 -> V_84 ,
L_72 ) ;
goto V_381;
}
}
if ( V_50 && V_50 -> V_382 ) {
V_330 = V_50 -> V_382 ( V_14 ) ;
if ( V_330 ) {
F_13 ( V_14 -> V_84 ,
L_73 ) ;
goto V_381;
}
}
V_14 -> V_383 = F_159 ( V_14 -> V_84 , L_74 ) ;
if ( F_154 ( V_14 -> V_383 ) ) {
V_330 = F_160 ( V_14 -> V_383 ) ;
if ( V_330 == - V_384 )
goto V_381;
F_58 ( V_14 -> V_84 , L_75 , V_330 ) ;
V_14 -> V_383 = NULL ;
} else {
V_330 = F_161 ( V_14 -> V_383 ) ;
if ( V_330 ) {
if ( V_330 != - V_384 )
F_13 ( V_14 -> V_84 ,
L_76 , V_330 ) ;
goto V_381;
}
}
if ( ! V_14 -> V_187 ) {
F_13 ( V_14 -> V_84 ,
L_77 ) ;
V_330 = - V_162 ;
goto V_385;
}
V_14 -> V_233 = V_14 -> V_197 -> V_233 ;
F_162 ( & V_14 -> V_15 ) ;
F_163 ( & V_14 -> V_209 ) ;
V_108 = ( F_29 ( V_14 , V_386 ) >> 7 ) & 0x7 ;
if ( ! V_108 ) {
V_14 -> V_303 = F_93 ;
V_14 -> V_292 = F_98 ;
V_375 = 16 ;
V_14 -> V_144 = 1 ;
} else if ( V_108 == 2 ) {
V_14 -> V_303 = F_102 ;
V_14 -> V_292 = F_104 ;
V_375 = 64 ;
V_14 -> V_144 = 3 ;
} else {
F_164 ( ( V_108 != 1 ) ,
L_78
L_79 ) ;
V_14 -> V_303 = F_100 ;
V_14 -> V_292 = F_101 ;
V_375 = 32 ;
V_14 -> V_144 = 2 ;
}
if ( ! F_148 ( V_14 ) )
return - V_162 ;
V_14 -> V_90 = V_14 -> V_197 -> V_90 ;
F_145 ( V_14 ) ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , 0 ) ;
F_15 ( V_14 , V_48 , 0xFFFFFFFF ) ;
if ( ! V_14 -> V_197 -> V_152 ) {
V_376 = F_29 ( V_14 , V_154 ) ;
V_376 = 1 + ( ( V_376 >> 16 ) & 0xfff ) ;
} else {
V_376 = V_14 -> V_197 -> V_152 ;
}
V_14 -> V_152 = V_376 ;
V_14 -> V_146 =
F_46 ( 0x2 , V_376 / 2 - 1 , V_376 / 2 ) ;
F_15 ( V_14 , V_154 , V_14 -> V_146 ) ;
F_15 ( V_14 , V_184 , 0 ) ;
F_15 ( V_14 , V_190 , 0 ) ;
V_14 -> V_387 = F_165 ( F_29 ( V_14 , V_388 ) ) ;
F_58 ( V_14 -> V_84 , L_80 , V_14 -> V_387 ) ;
if ( V_14 -> V_387 < V_389 )
V_14 -> V_287 = V_390 ;
else
V_14 -> V_287 = V_391 ;
F_166 ( & V_14 -> V_107 , F_85 , ( unsigned long ) V_14 ) ;
V_14 -> V_312 = F_167 ( L_81 ,
V_392 | V_393 , 1 ) ;
if ( ! V_14 -> V_312 ) {
V_330 = - V_332 ;
goto V_394;
}
F_168 ( & V_14 -> V_313 , F_117 ) ;
V_330 = F_169 ( V_14 -> V_84 , V_14 -> V_304 , F_114 ,
V_14 -> V_395 , L_82 , V_14 ) ;
if ( V_330 )
goto V_396;
if ( V_14 -> V_197 -> V_314 )
V_14 -> V_314 = V_14 -> V_197 -> V_314 ;
else
V_14 -> V_314 = ( ( F_29 ( V_14 , V_386 ) >> 1 ) & 0x1F ) + 1 ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , V_310 | V_308 |
V_167 | V_166 |
V_397 | V_311 ) ;
F_15 ( V_14 , V_102 , V_398 ) ;
F_58 ( V_14 -> V_84 , L_83
L_84
L_85 ,
V_14 -> V_304 , V_375 , V_376 ) ;
for ( V_108 = 0 ; V_108 < V_14 -> V_314 ; V_108 ++ ) {
V_330 = F_135 ( V_14 , V_108 ) ;
if ( V_330 )
F_72 ( V_14 -> V_84 , L_86 , V_108 ) ;
else
V_377 ++ ;
}
if ( V_377 ) {
F_58 ( V_14 -> V_84 , L_87 , V_377 ) ;
} else {
F_72 ( V_14 -> V_84 , L_88
L_89 , V_14 -> V_314 ) ;
goto V_396;
}
if ( V_14 -> V_233 & V_307 )
F_58 ( V_14 -> V_84 , L_90 ) ;
return 0 ;
V_396:
F_170 ( V_14 -> V_312 ) ;
V_394:
if ( V_14 -> V_141 && V_14 -> V_90 -> exit )
V_14 -> V_90 -> exit ( V_14 ) ;
V_385:
if ( V_14 -> V_383 )
F_171 ( V_14 -> V_383 ) ;
V_381:
if ( ! F_154 ( V_14 -> V_379 ) )
F_172 ( V_14 -> V_379 ) ;
V_380:
if ( ! F_154 ( V_14 -> V_378 ) )
F_172 ( V_14 -> V_378 ) ;
return V_330 ;
}
void F_173 ( struct V_34 * V_14 )
{
int V_108 ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , 0 ) ;
for ( V_108 = 0 ; V_108 < V_14 -> V_314 ; V_108 ++ ) {
F_72 ( V_14 -> V_84 , L_91 , V_108 ) ;
if ( V_14 -> V_5 [ V_108 ] )
F_143 ( V_14 -> V_5 [ V_108 ] , V_108 ) ;
}
F_15 ( V_14 , V_184 , 0 ) ;
F_15 ( V_14 , V_190 , 0 ) ;
F_170 ( V_14 -> V_312 ) ;
if ( V_14 -> V_141 && V_14 -> V_90 -> exit )
V_14 -> V_90 -> exit ( V_14 ) ;
if ( V_14 -> V_383 )
F_171 ( V_14 -> V_383 ) ;
if ( ! F_154 ( V_14 -> V_379 ) )
F_172 ( V_14 -> V_379 ) ;
if ( ! F_154 ( V_14 -> V_378 ) )
F_172 ( V_14 -> V_378 ) ;
}
int F_174 ( struct V_34 * V_14 )
{
if ( V_14 -> V_383 )
F_171 ( V_14 -> V_383 ) ;
return 0 ;
}
int F_175 ( struct V_34 * V_14 )
{
int V_108 , V_330 ;
if ( V_14 -> V_383 ) {
V_330 = F_161 ( V_14 -> V_383 ) ;
if ( V_330 ) {
F_13 ( V_14 -> V_84 ,
L_92 , V_330 ) ;
return V_330 ;
}
}
if ( ! F_148 ( V_14 ) ) {
V_330 = - V_162 ;
return V_330 ;
}
if ( V_14 -> V_141 && V_14 -> V_90 -> V_360 )
V_14 -> V_90 -> V_360 ( V_14 ) ;
F_15 ( V_14 , V_154 , V_14 -> V_146 ) ;
V_14 -> V_163 = 0 ;
F_15 ( V_14 , V_48 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_178 , 0xFFFFFFFF ) ;
F_15 ( V_14 , V_165 , V_310 | V_308 |
V_167 | V_166 |
V_397 | V_311 ) ;
F_15 ( V_14 , V_102 , V_398 ) ;
for ( V_108 = 0 ; V_108 < V_14 -> V_314 ; V_108 ++ ) {
struct V_4 * V_5 = V_14 -> V_5 [ V_108 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_33 -> V_399 & V_368 ) {
F_68 ( V_5 -> V_33 , & V_5 -> V_33 -> V_213 ) ;
F_56 ( V_5 , true ) ;
}
}
return 0 ;
}
static int T_6 F_176 ( void )
{
F_177 ( L_93 ) ;
return 0 ;
}
static void T_7 F_178 ( void )
{
}
