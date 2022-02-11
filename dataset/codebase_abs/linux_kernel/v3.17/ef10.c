static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , & V_3 , V_4 ) ;
return F_3 ( V_3 , V_5 ) == 0xb007 ?
F_3 ( V_3 , V_6 ) : - V_7 ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
return F_5 ( & V_2 -> V_8 -> V_9 [ V_10 ] ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_12 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 V_15 ;
int V_16 ;
F_8 ( V_17 != 0 ) ;
V_16 = F_9 ( V_2 , V_18 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < sizeof( V_11 ) ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_1 ) ;
return - V_7 ;
}
V_14 -> V_21 =
F_11 ( V_11 , V_22 ) ;
if ( ! ( V_14 -> V_21 &
( 1 << V_23 ) ) ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_2 ) ;
return - V_24 ;
}
if ( ! ( V_14 -> V_21 &
( 1 << V_25 ) ) ) {
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_3 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_27 ) ;
int V_16 ;
V_16 = F_9 ( V_2 , V_28 , NULL , 0 ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_16 )
return V_16 ;
V_16 = F_11 ( V_11 , V_29 ) ;
return V_16 > 0 ? V_16 : - V_30 ;
}
static int F_13 ( struct V_1 * V_2 , T_3 * V_31 )
{
F_7 ( V_11 , V_32 ) ;
T_2 V_15 ;
int V_16 ;
F_8 ( V_33 != 0 ) ;
V_16 = F_9 ( V_2 , V_34 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_32 )
return - V_7 ;
F_14 ( V_31 ,
F_15 ( V_11 , V_35 ) ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_36 , V_16 ;
V_2 -> V_37 =
F_17 (unsigned int,
EFX_MAX_CHANNELS,
resource_size(&efx->pci_dev->resource[EFX_MEM_BAR]) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
F_18 ( V_2 -> V_37 == 0 ) ;
V_14 = F_19 ( sizeof( * V_14 ) , V_38 ) ;
if ( ! V_14 )
return - V_39 ;
V_2 -> V_14 = V_14 ;
V_16 = F_20 ( V_2 , & V_14 -> V_40 ,
8 + V_41 , V_38 ) ;
if ( V_16 )
goto V_42;
V_36 = 0 ;
for (; ; ) {
V_16 = F_1 ( V_2 ) ;
if ( V_16 >= 0 )
break;
if ( ++ V_36 == 5 )
goto V_43;
F_21 ( 1 ) ;
}
V_14 -> V_44 = V_16 ;
V_14 -> V_45 = V_46 ;
F_22 ( V_2 , F_23 ( 1 ) , V_47 ) ;
V_16 = F_24 ( V_2 ) ;
if ( V_16 )
goto V_43;
V_16 = F_25 ( V_2 , V_48 ) ;
if ( V_16 )
goto V_49;
V_16 = F_26 ( V_2 , true , false , 0 ) ;
if ( V_16 )
goto V_49;
V_16 = F_6 ( V_2 ) ;
if ( V_16 < 0 )
goto V_49;
V_2 -> V_50 =
V_51 - V_52 ;
V_16 = F_27 ( V_2 ) ;
if ( V_16 < 0 )
goto V_49;
V_2 -> V_53 = V_16 ;
V_16 = F_13 ( V_2 , V_2 -> V_20 -> V_54 ) ;
if ( V_16 )
goto V_49;
V_16 = F_12 ( V_2 ) ;
if ( V_16 < 0 )
goto V_49;
V_2 -> V_55 = 1536000 / V_16 ;
V_16 = F_28 ( V_2 , V_56 , true ) ;
if ( V_16 == 0 )
V_14 -> V_57 = true ;
else if ( V_16 != - V_58 && V_16 != - V_59 )
goto V_49;
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_4 ,
V_14 -> V_57 ? L_5 : L_6 ) ;
V_16 = F_30 ( V_2 ) ;
if ( V_16 )
goto V_49;
F_31 ( V_2 , NULL ) ;
return 0 ;
V_49:
F_32 ( V_2 ) ;
V_43:
F_33 ( V_2 , & V_14 -> V_40 ) ;
V_42:
F_34 ( V_14 ) ;
V_2 -> V_14 = NULL ;
return V_16 ;
}
static int F_35 ( struct V_1 * V_2 )
{
F_36 ( V_11 , 0 ) ;
T_2 V_15 ;
int V_16 = F_37 ( V_2 , V_60 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 == - V_61 )
V_16 = 0 ;
if ( V_16 )
F_38 ( V_2 , V_60 , 0 , V_11 , V_15 ,
V_16 ) ;
return V_16 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_62 , V_63 ) ;
unsigned int V_36 ;
int V_16 ;
F_8 ( V_64 != 0 ) ;
for ( V_36 = 0 ; V_36 < V_14 -> V_65 ; V_36 ++ ) {
F_40 ( V_62 , V_66 ,
V_14 -> V_67 [ V_36 ] ) ;
V_16 = F_9 ( V_2 , V_68 , V_62 , sizeof( V_62 ) ,
NULL , 0 , NULL ) ;
F_41 ( V_16 ) ;
}
V_14 -> V_65 = 0 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_69 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_11 , V_70 ) ;
unsigned int V_36 ;
T_2 V_15 ;
int V_16 = 0 ;
F_8 ( V_71 != 0 ) ;
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
V_16 = F_9 ( V_2 , V_72 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
break;
if ( V_15 < V_70 ) {
V_16 = - V_7 ;
break;
}
V_14 -> V_67 [ V_36 ] =
F_11 ( V_11 , V_73 ) ;
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_7 , V_36 ,
V_14 -> V_67 [ V_36 ] ) ;
}
V_14 -> V_65 = V_36 ;
if ( V_16 )
F_39 ( V_2 ) ;
return V_16 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_62 ,
F_44 ( V_74 ,
V_75 ) ) ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
unsigned int V_80 , V_81 ;
int V_16 ;
F_8 ( V_82 != 0 ) ;
F_8 ( V_83 != 0 ) ;
for ( V_81 = 0 ; V_81 < V_14 -> V_65 ; ++ V_81 ) {
F_40 ( V_62 , V_84 ,
V_14 -> V_67 [ V_81 ] ) ;
F_40 ( V_62 , V_85 ,
V_14 -> V_86 + V_81 ) ;
V_16 = F_9 ( V_2 , V_87 ,
V_62 , V_74 ,
NULL , 0 , NULL ) ;
if ( V_16 ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_8 ,
V_14 -> V_86 + V_81 , V_81 ,
V_16 ) ;
goto V_88;
}
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_9 ,
V_14 -> V_86 + V_81 , V_81 ) ;
}
F_45 (channel, efx) {
F_46 (tx_queue, channel) {
V_80 = ( ( V_2 -> V_89 + V_2 -> V_90 -
V_79 -> V_77 -> V_77 - 1 ) *
V_91 ) ;
V_81 = V_80 / V_92 ;
V_80 = V_80 % V_92 ;
if ( V_79 -> V_93 == V_14 -> V_86 ) {
F_18 ( V_81 != 0 ) ;
V_16 = 0 ;
} else {
F_40 ( V_62 ,
V_84 ,
V_14 -> V_67 [ V_81 ] ) ;
F_40 ( V_62 ,
V_85 ,
V_79 -> V_93 ) ;
V_16 = F_9 ( V_2 , V_87 ,
V_62 , V_74 ,
NULL , 0 , NULL ) ;
}
if ( V_16 ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_8 ,
V_79 -> V_93 , V_81 , V_16 ) ;
V_79 -> V_94 = NULL ;
} else {
V_79 -> V_94 =
V_14 -> V_95 +
V_81 * V_96 + V_80 ;
V_79 -> V_97 = V_80 ;
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_10 ,
V_79 -> V_93 , V_81 ,
V_79 -> V_97 ,
V_79 -> V_94 ) ;
}
}
}
return 0 ;
V_88:
while ( V_81 -- ) {
F_40 ( V_62 , V_98 ,
V_14 -> V_86 + V_81 ) ;
F_9 ( V_2 , V_99 ,
V_62 , V_75 ,
NULL , 0 , NULL ) ;
}
return V_16 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_69 )
{
return V_69 == 0 ? 0 : - V_100 ;
}
static int F_43 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( V_14 -> V_101 )
F_51 ( V_14 -> V_101 ) ;
V_16 = F_35 ( V_2 ) ;
F_41 ( V_16 != 0 ) ;
if ( ! V_14 -> V_102 )
F_39 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_2 , & V_14 -> V_40 ) ;
F_34 ( V_14 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
unsigned int V_103 , unsigned int V_104 )
{
F_7 ( V_62 , V_105 ) ;
F_7 ( V_11 , V_106 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 V_15 ;
int V_16 ;
F_40 ( V_62 , V_107 , V_103 ) ;
F_40 ( V_62 , V_108 , V_104 ) ;
V_16 = F_9 ( V_2 , V_109 , V_62 , sizeof( V_62 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_106 )
return - V_7 ;
F_29 ( V_2 , V_19 , V_2 -> V_20 , L_11 ,
F_11 ( V_11 , V_110 ) ) ;
V_14 -> V_111 = F_11 ( V_11 , V_110 ) ;
V_14 -> V_112 = F_11 ( V_11 , V_113 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned int V_114 , V_115 ;
unsigned int V_103 , V_86 , V_104 ;
void T_4 * V_116 ;
int V_16 ;
V_103 = F_44 ( V_2 -> V_117 , V_2 -> V_90 * V_118 ) ;
#ifdef F_54
if ( V_91 != 0 &&
V_92 / V_91 * V_119 >=
V_2 -> V_90 ) {
unsigned int V_65 =
F_55 ( V_2 -> V_90 ,
V_92 / V_91 ) ;
V_16 = F_42 ( V_2 , V_65 ) ;
if ( V_16 )
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_12 , V_16 ) ;
else
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_13 , V_65 ) ;
}
#else
V_14 -> V_65 = 0 ;
#endif
V_114 = F_56 ( ( V_103 - 1 ) * V_96 +
V_120 ) ;
if ( V_14 -> V_65 ) {
V_86 = V_114 / V_96 ;
V_115 = ( F_56 ( ( V_86 +
V_14 -> V_65 ) *
V_96 ) -
V_114 ) ;
V_104 = V_86 + V_14 -> V_65 ;
} else {
V_86 = 0 ;
V_115 = 0 ;
V_104 = V_103 ;
}
V_16 = F_35 ( V_2 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_52 ( V_2 , V_103 , V_104 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_14 -> V_65 &&
V_14 -> V_112 <
V_86 + V_14 -> V_65 ) {
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_14 ,
V_14 -> V_112 , V_14 -> V_65 ) ;
F_39 ( V_2 ) ;
}
V_116 = F_57 ( V_2 -> V_121 , V_114 ) ;
if ( ! V_116 ) {
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_15 ,
V_114 ) ;
return - V_39 ;
}
F_51 ( V_2 -> V_116 ) ;
V_2 -> V_116 = V_116 ;
if ( V_115 ) {
V_14 -> V_101 = F_58 ( V_2 -> V_121 +
V_114 ,
V_115 ) ;
if ( ! V_14 -> V_101 ) {
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_16 ,
V_115 ) ;
return - V_39 ;
}
V_14 -> V_86 = V_86 ;
V_14 -> V_95 =
V_14 -> V_101 +
( V_86 * V_96 + V_120 -
V_114 ) ;
V_16 = F_43 ( V_2 ) ;
if ( V_16 )
F_39 ( V_2 ) ;
}
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_17 ,
& V_2 -> V_121 , V_2 -> V_116 , V_114 ,
V_14 -> V_101 , V_115 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
if ( V_14 -> V_122 ) {
V_16 = F_6 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_122 = false ;
}
if ( V_14 -> V_123 ) {
V_16 = F_52 ( V_2 , V_14 -> V_112 ,
V_14 -> V_112 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_123 = false ;
}
if ( V_14 -> V_102 && V_14 -> V_65 ) {
V_16 = F_42 ( V_2 , V_14 -> V_65 ) ;
if ( V_16 == 0 ) {
V_16 = F_43 ( V_2 ) ;
if ( V_16 )
F_39 ( V_2 ) ;
}
if ( V_16 )
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_18 , V_16 ) ;
V_14 -> V_102 = false ;
}
F_60 ( V_2 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_123 = true ;
V_14 -> V_124 = true ;
V_14 -> V_102 = true ;
V_14 -> V_45 = V_46 ;
}
static int F_62 ( T_5 * V_125 )
{
enum {
V_126 = ( ( V_127 | V_128 ) <<
V_129 ) ,
V_130 = ( ( V_131 | V_132 |
V_133 | V_127 |
V_128 | V_134 ) <<
V_129 )
};
if ( ( * V_125 & V_130 ) == V_130 ) {
* V_125 &= ~ V_130 ;
return V_135 ;
}
if ( ( * V_125 & V_126 ) == V_126 ) {
* V_125 &= ~ V_126 ;
return V_48 ;
}
return - V_136 ;
}
static int F_63 ( struct V_1 * V_2 , enum V_137 V_137 )
{
int V_16 = F_25 ( V_2 , V_137 ) ;
if ( ( V_137 == V_48 ||
V_137 == V_138 ) && ! V_16 )
F_61 ( V_2 ) ;
return V_16 ;
}
static T_6 F_64 ( struct V_1 * V_2 )
{
T_6 V_139 = V_140 ;
T_5 V_141 = F_65 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_141 & ( 1 << V_142 ) )
V_139 |= V_143 ;
else
V_139 |= V_144 ;
if ( V_14 -> V_21 &
( 1 << V_145 ) )
V_139 |= V_146 ;
return V_139 ;
}
static void F_66 ( struct V_1 * V_2 , unsigned long * V_147 )
{
T_6 V_139 = F_64 ( V_2 ) ;
#if V_148 == 64
V_147 [ 0 ] = V_139 ;
#else
V_147 [ 0 ] = V_139 & 0xffffffff ;
V_147 [ 1 ] = V_139 >> 32 ;
#endif
}
static T_2 F_67 ( struct V_1 * V_2 , T_3 * V_149 )
{
F_68 ( V_147 , V_150 ) ;
F_66 ( V_2 , V_147 ) ;
return F_69 ( V_151 , V_150 ,
V_147 , V_149 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_68 ( V_147 , V_150 ) ;
T_7 V_152 , V_153 ;
T_6 * V_154 = V_14 -> V_154 ;
T_7 * V_155 ;
F_66 ( V_2 , V_147 ) ;
V_155 = V_2 -> V_156 . V_157 ;
V_14 = V_2 -> V_14 ;
V_153 = V_155 [ V_158 ] ;
if ( V_153 == V_159 )
return 0 ;
F_71 () ;
F_72 ( V_151 , V_150 , V_147 ,
V_154 , V_2 -> V_156 . V_157 , false ) ;
F_71 () ;
V_152 = V_155 [ V_160 ] ;
if ( V_153 != V_152 )
return - V_161 ;
F_73 ( V_2 , & V_154 [ V_162 ] ) ;
V_154 [ V_163 ] =
V_154 [ V_164 ] -
V_154 [ V_165 ] ;
F_74 ( & V_154 [ V_166 ] ,
V_154 [ V_165 ] ) ;
F_75 ( V_2 , V_154 ) ;
return 0 ;
}
static T_2 F_76 ( struct V_1 * V_2 , T_6 * V_167 ,
struct V_168 * V_169 )
{
F_68 ( V_147 , V_150 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 * V_154 = V_14 -> V_154 ;
T_2 V_170 = 0 , V_81 ;
int V_171 ;
F_66 ( V_2 , V_147 ) ;
for ( V_171 = 0 ; V_171 < 100 ; ++ V_171 ) {
if ( F_70 ( V_2 ) == 0 )
break;
F_77 ( 100 ) ;
}
if ( V_167 ) {
F_78 (index, mask, EF10_STAT_COUNT) {
if ( V_151 [ V_81 ] . V_172 ) {
* V_167 ++ = V_154 [ V_81 ] ;
++ V_170 ;
}
}
}
if ( V_169 ) {
V_169 -> V_173 = V_154 [ V_174 ] ;
V_169 -> V_175 = V_154 [ V_176 ] ;
V_169 -> V_177 = V_154 [ V_164 ] ;
V_169 -> V_178 = V_154 [ V_179 ] ;
V_169 -> V_180 = V_154 [ V_162 ] +
V_154 [ V_181 ] +
V_154 [ V_182 ] ;
V_169 -> V_183 = V_154 [ V_184 ] ;
V_169 -> V_185 =
V_154 [ V_186 ] +
V_154 [ V_187 ] ;
V_169 -> V_188 = V_154 [ V_189 ] ;
V_169 -> V_190 = V_154 [ V_191 ] ;
V_169 -> V_192 = V_154 [ V_193 ] ;
V_169 -> V_194 = ( V_169 -> V_185 +
V_169 -> V_188 +
V_169 -> V_190 ) ;
}
return V_170 ;
}
static void F_79 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
unsigned int V_195 , V_196 ;
T_1 V_197 ;
if ( V_77 -> V_198 ) {
V_195 = 3 ;
V_196 = V_77 -> V_198 - 1 ;
} else {
V_195 = 0 ;
V_196 = 0 ;
}
if ( F_80 ( V_2 ) ) {
F_81 ( V_197 , V_199 ,
V_200 ,
V_201 , V_195 ,
V_202 , V_196 ) ;
F_82 ( V_2 , & V_197 , V_203 ,
V_77 -> V_77 ) ;
} else {
F_83 ( V_197 , V_204 , V_195 ,
V_205 , V_196 ) ;
F_82 ( V_2 , & V_197 , V_206 ,
V_77 -> V_77 ) ;
}
}
static void F_84 ( struct V_1 * V_2 , struct V_207 * V_208 )
{
V_208 -> V_209 = 0 ;
V_208 -> V_210 = 0 ;
memset ( & V_208 -> V_211 , 0 , sizeof( V_208 -> V_211 ) ) ;
}
static int F_85 ( struct V_1 * V_2 , T_5 type )
{
if ( type != 0 )
return - V_136 ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 ,
const T_1 * V_212 , T_2 V_213 ,
const T_1 * V_214 , T_2 V_215 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_3 * V_216 = V_14 -> V_40 . V_157 ;
memcpy ( V_216 , V_212 , V_213 ) ;
memcpy ( V_216 + V_213 , V_214 , V_215 ) ;
F_87 () ;
F_22 ( V_2 , F_23 ( ( T_6 ) V_14 -> V_40 . V_217 >> 32 ) ,
V_218 ) ;
F_22 ( V_2 , F_23 ( ( T_5 ) V_14 -> V_40 . V_217 ) ,
V_47 ) ;
}
static bool F_88 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_1 V_212 = * ( const T_1 * ) V_14 -> V_40 . V_157 ;
F_71 () ;
return F_3 ( V_212 , V_219 ) ;
}
static void
F_89 ( struct V_1 * V_2 , T_1 * V_11 ,
T_2 V_80 , T_2 V_15 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_3 * V_216 = V_14 -> V_40 . V_157 ;
memcpy ( V_11 , V_216 + V_80 , V_15 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 < 0 ) {
return 0 ;
}
if ( V_16 == V_14 -> V_44 )
return 0 ;
V_14 -> V_44 = V_16 ;
F_61 ( V_2 ) ;
V_14 -> V_122 = true ;
V_14 -> V_154 [ V_166 ] = 0 ;
return - V_7 ;
}
static T_8 F_91 ( int V_220 , void * V_221 )
{
struct V_222 * V_223 = V_221 ;
struct V_1 * V_2 = V_223 -> V_2 ;
F_92 ( V_2 , V_224 , V_2 -> V_20 ,
L_19 , V_220 , F_93 () ) ;
if ( F_94 ( F_95 ( V_2 -> V_225 ) ) ) {
if ( V_223 -> V_81 == V_2 -> V_226 )
V_2 -> V_227 = F_93 () ;
F_96 ( V_2 -> V_77 [ V_223 -> V_81 ] ) ;
}
return V_228 ;
}
static T_8 F_97 ( int V_220 , void * V_221 )
{
struct V_1 * V_2 = V_221 ;
bool V_229 = F_95 ( V_2 -> V_225 ) ;
struct V_76 * V_77 ;
T_1 V_3 ;
T_5 V_230 ;
F_2 ( V_2 , & V_3 , V_231 ) ;
V_230 = F_3 ( V_3 , V_232 ) ;
if ( V_230 == 0 )
return V_233 ;
if ( F_94 ( V_229 ) ) {
if ( V_230 & ( 1U << V_2 -> V_226 ) )
V_2 -> V_227 = F_93 () ;
F_45 (channel, efx) {
if ( V_230 & 1 )
F_96 ( V_77 ) ;
V_230 >>= 1 ;
}
}
F_92 ( V_2 , V_224 , V_2 -> V_20 ,
L_20 V_234 L_21 ,
V_220 , F_93 () , F_98 ( V_3 ) ) ;
return V_228 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_7 ( V_62 , V_235 ) ;
F_8 ( V_236 != 0 ) ;
F_40 ( V_62 , V_237 , V_2 -> V_226 ) ;
( void ) F_9 ( V_2 , V_238 ,
V_62 , sizeof( V_62 ) , NULL , 0 , NULL ) ;
}
static int F_100 ( struct V_78 * V_79 )
{
return F_20 ( V_79 -> V_2 , & V_79 -> V_239 . V_240 ,
( V_79 -> V_241 + 1 ) *
sizeof( V_242 ) ,
V_38 ) ;
}
static inline void F_101 ( struct V_78 * V_79 ,
const V_242 * V_239 )
{
unsigned int V_243 ;
T_9 V_3 ;
V_243 = V_79 -> V_244 & V_79 -> V_241 ;
F_102 ( V_3 , V_245 , V_243 ) ;
V_3 . V_246 [ 0 ] = * V_239 ;
F_103 ( V_79 -> V_2 , & V_3 ,
V_247 , V_79 -> V_93 ) ;
}
static void F_104 ( struct V_78 * V_79 )
{
F_7 ( V_62 , F_105 ( V_248 * 8 /
V_249 ) ) ;
F_7 ( V_11 , V_250 ) ;
bool V_251 = V_79 -> V_93 & V_252 ;
T_2 V_253 = V_79 -> V_239 . V_240 . V_254 / V_249 ;
struct V_76 * V_77 = V_79 -> V_77 ;
struct V_1 * V_2 = V_79 -> V_2 ;
T_2 V_255 , V_15 ;
T_10 V_217 ;
V_242 * V_239 ;
int V_16 ;
int V_36 ;
F_40 ( V_62 , V_256 , V_79 -> V_241 + 1 ) ;
F_40 ( V_62 , V_257 , V_77 -> V_77 ) ;
F_40 ( V_62 , V_258 , V_79 -> V_93 ) ;
F_40 ( V_62 , V_259 , V_79 -> V_93 ) ;
F_106 ( V_62 , V_260 ,
V_261 , ! V_251 ,
V_262 , ! V_251 ) ;
F_40 ( V_62 , V_263 , 0 ) ;
F_40 ( V_62 , V_264 , V_265 ) ;
V_217 = V_79 -> V_239 . V_240 . V_217 ;
F_29 ( V_2 , V_266 , V_2 -> V_20 , L_22 ,
V_79 -> V_93 , V_253 , ( T_6 ) V_217 ) ;
for ( V_36 = 0 ; V_36 < V_253 ; ++ V_36 ) {
F_107 ( V_62 , V_267 , V_36 , V_217 ) ;
V_217 += V_249 ;
}
V_255 = F_105 ( V_253 ) ;
V_16 = F_9 ( V_2 , V_268 , V_62 , V_255 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_88;
V_79 -> V_269 [ 0 ] . V_125 = V_270 ;
V_79 -> V_271 = 1 ;
V_239 = F_108 ( V_79 , 0 ) ;
F_109 ( * V_239 ,
V_272 , true ,
V_273 ,
V_274 ,
V_275 , V_251 ,
V_276 , V_251 ) ;
V_79 -> V_244 = 1 ;
F_87 () ;
F_101 ( V_79 , V_239 ) ;
return;
V_88:
F_110 ( V_2 -> V_20 , L_23 ,
V_79 -> V_93 ) ;
}
static void F_111 ( struct V_78 * V_79 )
{
F_7 ( V_62 , V_277 ) ;
F_7 ( V_11 , V_278 ) ;
struct V_1 * V_2 = V_79 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_40 ( V_62 , V_279 ,
V_79 -> V_93 ) ;
V_16 = F_37 ( V_2 , V_280 , V_62 , sizeof( V_62 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_61 )
goto V_88;
return;
V_88:
F_38 ( V_2 , V_280 , V_277 ,
V_11 , V_15 , V_16 ) ;
}
static void F_112 ( struct V_78 * V_79 )
{
F_33 ( V_79 -> V_2 , & V_79 -> V_239 . V_240 ) ;
}
static inline void F_113 ( struct V_78 * V_79 )
{
unsigned int V_243 ;
T_1 V_3 ;
V_243 = V_79 -> V_244 & V_79 -> V_241 ;
F_114 ( V_3 , V_281 , V_243 ) ;
F_82 ( V_79 -> V_2 , & V_3 ,
V_282 , V_79 -> V_93 ) ;
}
static void F_115 ( struct V_78 * V_79 )
{
unsigned int V_283 = V_79 -> V_244 ;
struct V_284 * V_269 ;
unsigned int V_243 ;
V_242 * V_239 ;
F_18 ( V_79 -> V_244 == V_79 -> V_271 ) ;
do {
V_243 = V_79 -> V_244 & V_79 -> V_241 ;
V_269 = & V_79 -> V_269 [ V_243 ] ;
V_239 = F_108 ( V_79 , V_243 ) ;
++ V_79 -> V_244 ;
if ( V_269 -> V_125 & V_270 ) {
* V_239 = V_269 -> V_285 ;
} else {
F_8 ( V_286 != 1 ) ;
F_116 (
* V_239 ,
V_287 ,
V_269 -> V_125 & V_286 ,
V_288 , V_269 -> V_254 ,
V_289 , V_269 -> V_217 ) ;
}
} while ( V_79 -> V_244 != V_79 -> V_271 );
F_87 () ;
if ( F_117 ( V_79 , V_283 ) ) {
V_239 = F_108 ( V_79 ,
V_283 & V_79 -> V_241 ) ;
F_101 ( V_79 , V_239 ) ;
++ V_79 -> V_290 ;
} else {
F_113 ( V_79 ) ;
}
}
static int F_118 ( struct V_1 * V_2 , T_5 * V_223 )
{
F_7 ( V_62 , V_291 ) ;
F_7 ( V_11 , V_292 ) ;
T_2 V_15 ;
int V_16 ;
F_40 ( V_62 , V_293 ,
V_265 ) ;
F_40 ( V_62 , V_294 ,
V_295 ) ;
F_40 ( V_62 , V_296 ,
V_297 ) ;
V_16 = F_9 ( V_2 , V_298 , V_62 , sizeof( V_62 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_292 )
return - V_7 ;
* V_223 = F_11 ( V_11 , V_299 ) ;
return 0 ;
}
static void F_119 ( struct V_1 * V_2 , T_5 V_223 )
{
F_7 ( V_62 , V_300 ) ;
int V_16 ;
F_40 ( V_62 , V_301 ,
V_223 ) ;
V_16 = F_9 ( V_2 , V_302 , V_62 , sizeof( V_62 ) ,
NULL , 0 , NULL ) ;
F_41 ( V_16 != 0 ) ;
}
static int F_120 ( struct V_1 * V_2 , T_5 V_223 )
{
F_7 ( V_303 , V_304 ) ;
F_7 ( V_305 , V_306 ) ;
int V_36 , V_16 ;
F_40 ( V_303 , V_307 ,
V_223 ) ;
F_8 ( F_121 ( V_2 -> V_308 ) !=
V_309 ) ;
for ( V_36 = 0 ; V_36 < F_121 ( V_2 -> V_308 ) ; ++ V_36 )
F_15 ( V_303 ,
V_310 ) [ V_36 ] =
( T_3 ) V_2 -> V_308 [ V_36 ] ;
V_16 = F_9 ( V_2 , V_311 , V_303 ,
sizeof( V_303 ) , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
return V_16 ;
F_40 ( V_305 , V_312 ,
V_223 ) ;
F_8 ( F_121 ( V_2 -> V_313 ) !=
V_314 ) ;
for ( V_36 = 0 ; V_36 < F_121 ( V_2 -> V_313 ) ; ++ V_36 )
F_15 ( V_305 , V_315 ) [ V_36 ] =
V_2 -> V_313 [ V_36 ] ;
return F_9 ( V_2 , V_316 , V_305 ,
sizeof( V_305 ) , NULL , 0 , NULL ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_45 != V_46 )
F_119 ( V_2 , V_14 -> V_45 ) ;
V_14 -> V_45 = V_46 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_29 ( V_2 , V_19 , V_2 -> V_20 , L_24 ) ;
if ( V_14 -> V_45 == V_46 ) {
V_16 = F_118 ( V_2 , & V_14 -> V_45 ) ;
if ( V_16 != 0 )
goto V_88;
}
V_16 = F_120 ( V_2 , V_14 -> V_45 ) ;
if ( V_16 != 0 )
goto V_88;
return;
V_88:
F_10 ( V_2 , V_266 , V_2 -> V_20 , L_25 , V_317 , V_16 ) ;
}
static int F_122 ( struct V_318 * V_319 )
{
return F_20 ( V_319 -> V_2 , & V_319 -> V_320 . V_240 ,
( V_319 -> V_241 + 1 ) *
sizeof( V_242 ) ,
V_38 ) ;
}
static void F_123 ( struct V_318 * V_319 )
{
F_7 ( V_62 ,
F_124 ( V_248 * 8 /
V_249 ) ) ;
F_7 ( V_11 , V_321 ) ;
struct V_76 * V_77 = F_125 ( V_319 ) ;
T_2 V_253 = V_319 -> V_320 . V_240 . V_254 / V_249 ;
struct V_1 * V_2 = V_319 -> V_2 ;
T_2 V_255 , V_15 ;
T_10 V_217 ;
int V_16 ;
int V_36 ;
V_319 -> V_322 = 0 ;
V_319 -> V_323 = 0 ;
F_40 ( V_62 , V_324 , V_319 -> V_241 + 1 ) ;
F_40 ( V_62 , V_325 , V_77 -> V_77 ) ;
F_40 ( V_62 , V_326 , F_126 ( V_319 ) ) ;
F_40 ( V_62 , V_327 ,
F_126 ( V_319 ) ) ;
F_106 ( V_62 , V_328 ,
V_329 , 1 ,
V_330 , 1 ) ;
F_40 ( V_62 , V_331 , 0 ) ;
F_40 ( V_62 , V_332 , V_265 ) ;
V_217 = V_319 -> V_320 . V_240 . V_217 ;
F_29 ( V_2 , V_266 , V_2 -> V_20 , L_26 ,
F_126 ( V_319 ) , V_253 , ( T_6 ) V_217 ) ;
for ( V_36 = 0 ; V_36 < V_253 ; ++ V_36 ) {
F_107 ( V_62 , V_333 , V_36 , V_217 ) ;
V_217 += V_249 ;
}
V_255 = F_124 ( V_253 ) ;
V_16 = F_9 ( V_2 , V_334 , V_62 , V_255 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
F_110 ( V_2 -> V_20 , L_27 ,
F_126 ( V_319 ) ) ;
}
static void F_127 ( struct V_318 * V_319 )
{
F_7 ( V_62 , V_335 ) ;
F_7 ( V_11 , V_336 ) ;
struct V_1 * V_2 = V_319 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_40 ( V_62 , V_337 ,
F_126 ( V_319 ) ) ;
V_16 = F_37 ( V_2 , V_338 , V_62 , sizeof( V_62 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_61 )
goto V_88;
return;
V_88:
F_38 ( V_2 , V_338 , V_335 ,
V_11 , V_15 , V_16 ) ;
}
static void F_128 ( struct V_318 * V_319 )
{
F_33 ( V_319 -> V_2 , & V_319 -> V_320 . V_240 ) ;
}
static inline void
F_129 ( struct V_318 * V_319 , unsigned int V_81 )
{
struct V_339 * V_340 ;
V_242 * V_320 ;
V_320 = F_130 ( V_319 , V_81 ) ;
V_340 = V_339 ( V_319 , V_81 ) ;
F_131 ( * V_320 ,
V_341 , V_340 -> V_254 ,
V_342 , V_340 -> V_217 ) ;
}
static void F_132 ( struct V_318 * V_319 )
{
struct V_1 * V_2 = V_319 -> V_2 ;
unsigned int V_244 ;
T_1 V_3 ;
V_244 = V_319 -> V_343 & ~ 7 ;
if ( V_319 -> V_344 == V_244 )
return;
do
F_129 (
V_319 ,
V_319 -> V_344 & V_319 -> V_241 ) ;
while ( ++ V_319 -> V_344 != V_244 );
F_87 () ;
F_114 ( V_3 , V_345 ,
V_244 & V_319 -> V_241 ) ;
F_82 ( V_2 , & V_3 , V_346 ,
F_126 ( V_319 ) ) ;
}
static void F_133 ( struct V_318 * V_319 )
{
struct V_76 * V_77 = F_125 ( V_319 ) ;
F_7 ( V_62 , V_347 ) ;
V_242 V_348 ;
F_131 ( V_348 ,
V_349 , V_350 ,
V_351 , V_352 ) ;
F_40 ( V_62 , V_353 , V_77 -> V_77 ) ;
memcpy ( F_15 ( V_62 , V_354 ) , & V_348 . T_6 [ 0 ] ,
sizeof( V_242 ) ) ;
F_134 ( V_77 -> V_2 , V_355 ,
V_62 , sizeof( V_62 ) , 0 ,
V_356 , 0 ) ;
}
static void
V_356 ( struct V_1 * V_2 , unsigned long V_357 ,
int V_16 , T_1 * V_11 ,
T_2 V_358 )
{
}
static int F_135 ( struct V_76 * V_77 )
{
return F_20 ( V_77 -> V_2 , & V_77 -> V_359 . V_240 ,
( V_77 -> V_360 + 1 ) *
sizeof( V_242 ) ,
V_38 ) ;
}
static int F_136 ( struct V_76 * V_77 )
{
F_7 ( V_62 ,
F_137 ( V_361 * 8 /
V_249 ) ) ;
F_7 ( V_11 , V_362 ) ;
T_2 V_253 = V_77 -> V_359 . V_240 . V_254 / V_249 ;
struct V_1 * V_2 = V_77 -> V_2 ;
struct V_13 * V_14 ;
bool V_363 ;
T_2 V_255 , V_15 ;
T_10 V_217 ;
int V_16 ;
int V_36 ;
V_14 = V_2 -> V_14 ;
V_363 =
! ! ( V_14 -> V_21 &
1 << V_364 ) ;
memset ( V_77 -> V_359 . V_240 . V_157 , 0xff , V_77 -> V_359 . V_240 . V_254 ) ;
F_40 ( V_62 , V_365 , V_77 -> V_360 + 1 ) ;
F_40 ( V_62 , V_366 , V_77 -> V_77 ) ;
F_40 ( V_62 , V_367 , V_77 -> V_77 ) ;
F_138 ( V_62 , V_368 ,
V_369 , 1 ,
V_370 , 1 ,
V_371 , 1 ,
V_372 , ! V_363 ) ;
F_40 ( V_62 , V_373 ,
V_374 ) ;
F_40 ( V_62 , V_375 , 0 ) ;
F_40 ( V_62 , V_376 , 0 ) ;
F_40 ( V_62 , V_377 ,
V_378 ) ;
F_40 ( V_62 , V_379 , 0 ) ;
V_217 = V_77 -> V_359 . V_240 . V_217 ;
for ( V_36 = 0 ; V_36 < V_253 ; ++ V_36 ) {
F_107 ( V_62 , V_380 , V_36 , V_217 ) ;
V_217 += V_249 ;
}
V_255 = F_137 ( V_253 ) ;
V_16 = F_9 ( V_2 , V_381 , V_62 , V_255 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
return V_16 ;
}
static void F_139 ( struct V_76 * V_77 )
{
F_7 ( V_62 , V_382 ) ;
F_7 ( V_11 , V_383 ) ;
struct V_1 * V_2 = V_77 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_40 ( V_62 , V_384 , V_77 -> V_77 ) ;
V_16 = F_37 ( V_2 , V_385 , V_62 , sizeof( V_62 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_61 )
goto V_88;
return;
V_88:
F_38 ( V_2 , V_385 , V_382 ,
V_11 , V_15 , V_16 ) ;
}
static void F_140 ( struct V_76 * V_77 )
{
F_33 ( V_77 -> V_2 , & V_77 -> V_359 . V_240 ) ;
}
static void F_141 ( struct V_318 * V_319 ,
unsigned int V_386 )
{
struct V_1 * V_2 = V_319 -> V_2 ;
F_142 ( V_2 , V_266 , V_2 -> V_20 ,
L_28 ,
F_126 ( V_319 ) , V_386 ) ;
F_143 ( V_2 , V_387 ) ;
}
static void
F_144 ( struct V_318 * V_319 ,
unsigned int V_388 , unsigned int V_389 )
{
unsigned int V_390 = ( V_388 - V_389 ) & V_319 -> V_241 ;
struct V_1 * V_2 = V_319 -> V_2 ;
F_142 ( V_2 , V_266 , V_2 -> V_20 ,
L_29 ,
V_390 , V_388 , V_389 ) ;
F_143 ( V_2 , V_387 ) ;
}
static void F_145 ( struct V_318 * V_319 )
{
unsigned int V_391 ;
F_29 ( V_319 -> V_2 , V_266 , V_319 -> V_2 -> V_20 ,
L_30 ,
V_319 -> V_322 ) ;
V_391 = V_319 -> V_392 & V_319 -> V_241 ;
F_146 ( V_319 , V_391 , V_319 -> V_322 ,
0 , V_393 ) ;
V_319 -> V_392 += V_319 -> V_322 ;
V_319 -> V_322 = 0 ;
V_319 -> V_323 = 0 ;
++ F_125 ( V_319 ) -> V_394 ;
}
static int F_147 ( struct V_76 * V_77 ,
const V_242 * V_348 )
{
unsigned int V_177 , V_395 , V_386 , V_396 ;
unsigned int V_397 , V_398 , V_36 ;
struct V_1 * V_2 = V_77 -> V_2 ;
struct V_318 * V_319 ;
bool V_399 ;
T_11 V_125 = 0 ;
if ( F_148 ( F_95 ( V_2 -> V_400 ) ) )
return 0 ;
V_177 = F_149 ( * V_348 , V_401 ) ;
V_395 = F_149 ( * V_348 , V_402 ) ;
V_386 = F_149 ( * V_348 , V_403 ) ;
V_396 = F_149 ( * V_348 , V_404 ) ;
V_399 = F_149 ( * V_348 , V_405 ) ;
if ( F_149 ( * V_348 , V_406 ) )
F_110 ( V_2 -> V_20 , L_31
V_407 L_21 ,
F_150 ( * V_348 ) ) ;
V_319 = F_151 ( V_77 ) ;
if ( F_148 ( V_386 != F_126 ( V_319 ) ) )
F_141 ( V_319 , V_386 ) ;
V_397 = ( ( V_395 - V_319 -> V_392 ) &
( ( 1 << V_408 ) - 1 ) ) ;
if ( V_397 != V_319 -> V_322 + 1 ) {
struct V_13 * V_14 = V_2 -> V_14 ;
if ( F_148 ( V_397 == V_319 -> V_322 ) ) {
if ( V_319 -> V_322 == 0 || V_177 != 0 )
F_110 ( V_2 -> V_20 ,
L_32
V_407 L_21 ,
V_319 -> V_322 ,
F_150 ( * V_348 ) ) ;
F_145 ( V_319 ) ;
return 0 ;
}
if ( ! ( V_14 -> V_21 &
( 1 << V_364 ) ) ||
V_319 -> V_322 != 0 || V_399 ) {
F_144 (
V_319 , V_395 ,
( V_319 -> V_392 +
V_319 -> V_322 + 1 ) &
( ( 1 << V_408 ) - 1 ) ) ;
return 0 ;
}
V_319 -> V_322 = 1 ;
V_319 -> V_323 = 0 ;
V_398 = V_397 ;
++ V_77 -> V_409 ;
V_77 -> V_410 += V_398 ;
V_125 |= V_411 ;
} else {
++ V_319 -> V_322 ;
V_319 -> V_323 += V_177 ;
if ( V_399 )
return 0 ;
V_398 = 1 ;
}
if ( F_148 ( F_149 ( * V_348 , V_412 ) ) )
V_125 |= V_393 ;
if ( F_148 ( F_149 ( * V_348 , V_413 ) ) ) {
V_77 -> V_414 += V_398 ;
} else if ( F_148 ( F_149 ( * V_348 ,
V_415 ) ) ) {
V_77 -> V_416 += V_398 ;
} else if ( V_396 == V_417 ||
V_396 == V_418 ) {
V_125 |= V_419 ;
}
if ( V_396 == V_417 )
V_125 |= V_420 ;
V_77 -> V_421 += 2 * V_398 ;
for ( V_36 = 0 ; V_36 < V_398 ; V_36 ++ ) {
F_146 ( V_319 ,
V_319 -> V_392 & V_319 -> V_241 ,
V_319 -> V_322 , V_319 -> V_323 ,
V_125 ) ;
V_319 -> V_392 += V_319 -> V_322 ;
}
V_319 -> V_322 = 0 ;
V_319 -> V_323 = 0 ;
return V_398 ;
}
static int
F_152 ( struct V_76 * V_77 , V_242 * V_348 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
struct V_78 * V_79 ;
unsigned int V_422 ;
unsigned int V_423 ;
int V_424 = 0 ;
if ( F_148 ( F_95 ( V_2 -> V_400 ) ) )
return 0 ;
if ( F_148 ( F_149 ( * V_348 , V_425 ) ) )
return 0 ;
V_422 = F_149 ( * V_348 , V_426 ) ;
V_423 = F_149 ( * V_348 , V_427 ) ;
V_79 = F_153 ( V_77 ,
V_423 % V_118 ) ;
V_424 = ( ( V_422 + 1 - V_79 -> V_428 ) &
V_79 -> V_241 ) ;
F_154 ( V_79 , V_422 & V_79 -> V_241 ) ;
return V_424 ;
}
static void
F_155 ( struct V_76 * V_77 , V_242 * V_348 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
int V_429 ;
V_429 = F_149 ( * V_348 , V_430 ) ;
switch ( V_429 ) {
case V_431 :
case V_432 :
break;
case V_433 :
break;
default:
F_10 ( V_2 , V_266 , V_2 -> V_20 ,
L_33
L_34 V_407 L_35 ,
V_77 -> V_77 , V_429 ,
F_150 ( * V_348 ) ) ;
}
}
static void F_156 ( struct V_76 * V_77 ,
V_242 * V_348 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
T_5 V_429 ;
V_429 = F_149 ( * V_348 , V_434 ) ;
switch ( V_429 ) {
case V_435 :
V_77 -> V_436 = F_93 () ;
break;
case V_352 :
F_157 ( & V_77 -> V_319 , true ) ;
break;
default:
F_10 ( V_2 , V_266 , V_2 -> V_20 ,
L_36
L_34 V_407 L_35 ,
V_77 -> V_77 , ( unsigned ) V_429 ,
F_150 ( * V_348 ) ) ;
}
}
static int F_158 ( struct V_76 * V_77 , int V_437 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
V_242 V_348 , * V_438 ;
unsigned int V_439 ;
int V_440 ;
int V_424 = 0 ;
int V_441 = 0 ;
if ( V_437 <= 0 )
return V_441 ;
V_439 = V_77 -> V_442 ;
for (; ; ) {
V_438 = F_159 ( V_77 , V_439 ) ;
V_348 = * V_438 ;
if ( ! F_160 ( & V_348 ) )
break;
F_161 ( * V_438 ) ;
++ V_439 ;
V_440 = F_149 ( V_348 , V_349 ) ;
F_92 ( V_2 , V_19 , V_2 -> V_20 ,
L_37 V_407 L_21 ,
V_77 -> V_77 , F_150 ( V_348 ) ) ;
switch ( V_440 ) {
case V_443 :
F_162 ( V_77 , & V_348 ) ;
break;
case V_444 :
V_441 += F_147 ( V_77 , & V_348 ) ;
if ( V_441 >= V_437 ) {
V_441 = V_437 ;
goto V_445;
}
break;
case V_446 :
V_424 += F_152 ( V_77 , & V_348 ) ;
if ( V_424 > V_2 -> V_447 ) {
V_441 = V_437 ;
goto V_445;
} else if ( ++ V_441 == V_437 ) {
goto V_445;
}
break;
case V_448 :
F_155 ( V_77 , & V_348 ) ;
if ( ++ V_441 == V_437 )
goto V_445;
break;
case V_350 :
F_156 ( V_77 , & V_348 ) ;
break;
default:
F_10 ( V_2 , V_266 , V_2 -> V_20 ,
L_38
L_34 V_407 L_35 ,
V_77 -> V_77 , V_440 ,
F_150 ( V_348 ) ) ;
}
}
V_445:
V_77 -> V_442 = V_439 ;
return V_441 ;
}
static void F_163 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_2 ;
T_1 V_449 ;
if ( F_80 ( V_2 ) ) {
F_8 ( V_450 <
( 1 << V_451 ) ) ;
F_8 ( V_361 >
( 1 << 2 * V_451 ) ) ;
F_83 ( V_449 , V_452 ,
V_453 ,
V_454 ,
( V_77 -> V_442 &
V_77 -> V_360 ) >>
V_451 ) ;
F_82 ( V_2 , & V_449 , V_203 ,
V_77 -> V_77 ) ;
F_83 ( V_449 , V_452 ,
V_455 ,
V_454 ,
V_77 -> V_442 &
( ( 1 << V_451 ) - 1 ) ) ;
F_82 ( V_2 , & V_449 , V_203 ,
V_77 -> V_77 ) ;
} else {
F_114 ( V_449 , V_456 ,
V_77 -> V_442 &
V_77 -> V_360 ) ;
F_82 ( V_2 , & V_449 , V_457 , V_77 -> V_77 ) ;
}
}
static void F_164 ( struct V_76 * V_77 )
{
F_7 ( V_62 , V_347 ) ;
struct V_1 * V_2 = V_77 -> V_2 ;
V_242 V_348 ;
int V_16 ;
F_131 ( V_348 ,
V_349 , V_350 ,
V_351 , V_435 ) ;
F_40 ( V_62 , V_353 , V_77 -> V_77 ) ;
memcpy ( F_15 ( V_62 , V_354 ) , & V_348 . T_6 [ 0 ] ,
sizeof( V_242 ) ) ;
V_16 = F_9 ( V_2 , V_355 , V_62 , sizeof( V_62 ) ,
NULL , 0 , NULL ) ;
if ( V_16 != 0 )
goto V_88;
return;
V_88:
F_41 ( true ) ;
F_10 ( V_2 , V_266 , V_2 -> V_20 , L_25 , V_317 , V_16 ) ;
}
void F_165 ( struct V_1 * V_2 )
{
if ( F_166 ( & V_2 -> V_458 ) )
F_167 ( & V_2 -> V_459 ) ;
F_41 ( F_168 ( & V_2 -> V_458 ) < 0 ) ;
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_318 * V_319 ;
int V_460 ;
if ( V_14 -> V_123 ) {
F_170 ( & V_2 -> V_458 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_461 != V_462 ) {
F_45 (channel, efx) {
F_171 (rx_queue, channel)
F_127 ( V_319 ) ;
F_46 (tx_queue, channel)
F_111 ( V_79 ) ;
}
F_172 ( V_2 -> V_459 ,
F_168 ( & V_2 -> V_458 ) == 0 ,
F_173 ( V_463 ) ) ;
V_460 = F_168 ( & V_2 -> V_458 ) ;
if ( V_460 ) {
F_10 ( V_2 , V_266 , V_2 -> V_20 , L_39 ,
V_460 ) ;
return - V_464 ;
}
}
return 0 ;
}
static void F_174 ( struct V_1 * V_2 )
{
F_170 ( & V_2 -> V_458 , 0 ) ;
}
static bool F_175 ( const struct V_465 * V_466 ,
const struct V_465 * V_467 )
{
if ( ( V_466 -> V_468 ^ V_467 -> V_468 ) |
( ( V_466 -> V_125 ^ V_467 -> V_125 ) &
( V_469 | V_470 ) ) )
return false ;
return memcmp ( & V_466 -> V_471 , & V_467 -> V_471 ,
sizeof( struct V_465 ) -
F_176 ( struct V_465 , V_471 ) ) == 0 ;
}
static unsigned int F_177 ( const struct V_465 * V_472 )
{
F_8 ( F_176 ( struct V_465 , V_471 ) & 3 ) ;
return F_178 ( ( const T_5 * ) & V_472 -> V_471 ,
( sizeof( struct V_465 ) -
F_176 ( struct V_465 , V_471 ) ) / 4 ,
0 ) ;
}
static bool F_179 ( const struct V_465 * V_472 )
{
if ( V_472 -> V_468 & V_473 &&
! F_180 ( V_472 -> V_474 ) )
return true ;
if ( ( V_472 -> V_468 &
( V_475 | V_476 ) ) ==
( V_475 | V_476 ) ) {
if ( V_472 -> V_477 == F_181 ( V_478 ) &&
! F_182 ( V_472 -> V_479 [ 0 ] ) )
return true ;
if ( V_472 -> V_477 == F_181 ( V_480 ) &&
( ( const T_3 * ) V_472 -> V_479 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_465 *
F_183 ( const struct V_481 * V_482 ,
unsigned int V_483 )
{
return (struct V_465 * ) ( V_482 -> V_484 [ V_483 ] . V_472 &
~ V_485 ) ;
}
static unsigned int
F_184 ( const struct V_481 * V_482 ,
unsigned int V_483 )
{
return V_482 -> V_484 [ V_483 ] . V_472 & V_485 ;
}
static void
F_185 ( struct V_481 * V_482 ,
unsigned int V_483 ,
const struct V_465 * V_472 ,
unsigned int V_125 )
{
V_482 -> V_484 [ V_483 ] . V_472 = ( unsigned long ) V_472 | V_125 ;
}
static void F_186 ( struct V_1 * V_2 ,
const struct V_465 * V_472 ,
T_1 * V_62 , T_6 V_486 ,
bool V_487 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
memset ( V_62 , 0 , V_488 ) ;
if ( V_487 ) {
F_40 ( V_62 , V_489 ,
V_490 ) ;
F_187 ( V_62 , V_491 , V_486 ) ;
} else {
T_5 V_492 = 0 ;
F_40 ( V_62 , V_489 ,
F_179 ( V_472 ) ?
V_493 :
V_494 ) ;
if ( V_472 -> V_468 & V_495 )
V_492 |=
F_180 ( V_472 -> V_474 ) ?
1 << V_496 :
1 << V_497 ;
#define F_188 ( T_12 , T_13 , T_14 ) \
if (spec->match_flags & EFX_FILTER_MATCH_ ## gen_flag) { \
match_fields |= \
1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN; \
BUILD_BUG_ON( \
MC_CMD_FILTER_OP_IN_ ## mcdi_field ## _LEN < \
sizeof(spec->gen_field)); \
memcpy(MCDI_PTR(inbuf, FILTER_OP_IN_ ## mcdi_field), \
&spec->gen_field, sizeof(spec->gen_field)); \
}
F_188 ( V_498 , V_499 , V_500 ) ;
F_188 ( V_501 , V_479 , V_502 ) ;
F_188 ( V_503 , V_504 , V_505 ) ;
F_188 ( V_506 , V_507 , V_508 ) ;
F_188 ( V_509 , V_474 , V_510 ) ;
F_188 ( V_511 , V_512 , V_513 ) ;
F_188 ( V_514 , V_477 , V_514 ) ;
F_188 ( V_515 , V_516 , V_517 ) ;
F_188 ( V_518 , V_471 , V_519 ) ;
F_188 ( V_520 , V_521 , V_520 ) ;
#undef F_188
F_40 ( V_62 , V_522 ,
V_492 ) ;
}
F_40 ( V_62 , V_523 , V_265 ) ;
F_40 ( V_62 , V_524 ,
V_472 -> V_525 == V_526 ?
V_527 :
V_528 ) ;
F_40 ( V_62 , V_529 ,
V_530 ) ;
F_40 ( V_62 , V_531 ,
V_472 -> V_525 == V_526 ?
0 : V_472 -> V_525 ) ;
F_40 ( V_62 , V_532 ,
( V_472 -> V_125 & V_533 ) ?
V_534 :
V_535 ) ;
if ( V_472 -> V_125 & V_533 )
F_40 ( V_62 , V_536 ,
V_472 -> V_537 !=
V_538 ?
V_472 -> V_537 : V_14 -> V_45 ) ;
}
static int F_189 ( struct V_1 * V_2 ,
const struct V_465 * V_472 ,
T_6 * V_486 , bool V_487 )
{
F_7 ( V_62 , V_488 ) ;
F_7 ( V_11 , V_539 ) ;
int V_16 ;
F_186 ( V_2 , V_472 , V_62 , * V_486 , V_487 ) ;
V_16 = F_9 ( V_2 , V_540 , V_62 , sizeof( V_62 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_16 == 0 )
* V_486 = F_190 ( V_11 , V_541 ) ;
if ( V_16 == - V_542 )
V_16 = - V_543 ;
return V_16 ;
}
static int F_191 ( struct V_481 * V_482 ,
enum V_544 V_468 )
{
unsigned int V_545 ;
for ( V_545 = 0 ;
V_545 < V_482 -> V_546 ;
V_545 ++ )
if ( V_482 -> V_547 [ V_545 ] == V_468 )
return V_545 ;
return - V_548 ;
}
static T_15 F_192 ( struct V_1 * V_2 ,
struct V_465 * V_472 ,
bool V_549 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
F_68 ( V_551 , V_552 ) ;
struct V_465 * V_553 ;
unsigned int V_545 , V_554 ;
unsigned int V_555 ;
bool V_487 = false ;
int V_556 = - 1 ;
F_193 ( V_557 ) ;
bool V_558 ;
T_15 V_16 ;
if ( ( V_472 -> V_125 & ( V_469 | V_470 ) ) !=
V_469 )
return - V_136 ;
V_16 = F_191 ( V_482 , V_472 -> V_468 ) ;
if ( V_16 < 0 )
return V_16 ;
V_545 = V_16 ;
V_554 = F_177 ( V_472 ) ;
V_558 = F_194 ( V_472 ) ;
if ( V_558 )
F_195 ( V_551 , V_552 ) ;
for (; ; ) {
unsigned int V_559 = 1 ;
unsigned int V_36 ;
F_196 ( & V_2 -> V_560 ) ;
for (; ; ) {
V_36 = ( V_554 + V_559 ) & ( V_561 - 1 ) ;
V_553 = F_183 ( V_482 , V_36 ) ;
if ( ! V_553 ) {
if ( V_556 < 0 )
V_556 = V_36 ;
} else if ( F_175 ( V_472 , V_553 ) ) {
if ( V_482 -> V_484 [ V_36 ] . V_472 &
V_562 )
break;
if ( V_472 -> V_563 < V_553 -> V_563 &&
V_472 -> V_563 != V_564 ) {
V_16 = - V_565 ;
goto V_566;
}
if ( ! V_558 ) {
if ( V_472 -> V_563 ==
V_553 -> V_563 &&
! V_549 ) {
V_16 = - V_567 ;
goto V_566;
}
V_556 = V_36 ;
goto V_568;
} else if ( V_472 -> V_563 >
V_553 -> V_563 ||
( V_472 -> V_563 ==
V_553 -> V_563 &&
V_549 ) ) {
if ( V_556 < 0 )
V_556 = V_36 ;
else
F_197 ( V_559 , V_551 ) ;
}
}
if ( V_559 == V_552 ) {
if ( V_556 < 0 ) {
V_16 = - V_543 ;
goto V_566;
}
goto V_568;
}
++ V_559 ;
}
F_198 ( & V_482 -> V_569 , & V_557 , V_570 ) ;
F_199 ( & V_2 -> V_560 ) ;
F_200 () ;
}
V_568:
V_553 = F_183 ( V_482 , V_556 ) ;
if ( V_553 ) {
if ( V_472 -> V_563 == V_564 &&
V_553 -> V_563 >= V_564 ) {
if ( V_553 -> V_563 > V_564 )
V_553 -> V_125 |= V_571 ;
V_482 -> V_484 [ V_556 ] . V_472 &=
~ V_572 ;
V_16 = V_556 ;
goto V_566;
}
V_487 = true ;
V_555 = F_184 ( V_482 , V_556 ) ;
} else {
V_553 = F_201 ( sizeof( * V_472 ) , V_573 ) ;
if ( ! V_553 ) {
V_16 = - V_39 ;
goto V_566;
}
* V_553 = * V_472 ;
V_555 = 0 ;
}
F_185 ( V_482 , V_556 , V_553 ,
V_555 | V_562 ) ;
if ( V_558 ) {
unsigned int V_559 , V_36 ;
for ( V_559 = 0 ; V_559 < V_552 ; V_559 ++ ) {
V_36 = ( V_554 + V_559 ) & ( V_561 - 1 ) ;
if ( F_202 ( V_559 , V_551 ) )
V_482 -> V_484 [ V_36 ] . V_472 |=
V_562 ;
}
}
F_199 ( & V_2 -> V_560 ) ;
V_16 = F_189 ( V_2 , V_472 , & V_482 -> V_484 [ V_556 ] . V_486 ,
V_487 ) ;
F_196 ( & V_2 -> V_560 ) ;
if ( V_16 == 0 ) {
if ( V_487 ) {
if ( V_553 -> V_563 == V_564 )
V_553 -> V_125 |=
V_571 ;
V_553 -> V_563 = V_472 -> V_563 ;
V_553 -> V_125 &= V_571 ;
V_553 -> V_125 |= V_472 -> V_125 ;
V_553 -> V_537 = V_472 -> V_537 ;
V_553 -> V_525 = V_472 -> V_525 ;
}
} else if ( ! V_487 ) {
F_34 ( V_553 ) ;
V_553 = NULL ;
}
F_185 ( V_482 , V_556 , V_553 , V_555 ) ;
if ( V_558 ) {
F_7 ( V_62 , V_488 ) ;
unsigned int V_559 , V_36 ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
for ( V_559 = 0 ; V_559 < V_552 ; V_559 ++ ) {
if ( ! F_202 ( V_559 , V_551 ) )
continue;
V_36 = ( V_554 + V_559 ) & ( V_561 - 1 ) ;
V_553 = F_183 ( V_482 , V_36 ) ;
V_555 = F_184 ( V_482 , V_36 ) ;
if ( V_16 == 0 ) {
F_199 ( & V_2 -> V_560 ) ;
F_40 ( V_62 , V_489 ,
V_574 ) ;
F_187 ( V_62 , V_491 ,
V_482 -> V_484 [ V_36 ] . V_486 ) ;
V_16 = F_9 ( V_2 , V_540 ,
V_62 , sizeof( V_62 ) ,
NULL , 0 , NULL ) ;
F_196 ( & V_2 -> V_560 ) ;
}
if ( V_16 == 0 ) {
F_34 ( V_553 ) ;
V_553 = NULL ;
V_555 = 0 ;
} else {
V_555 &= ~ V_562 ;
}
F_185 ( V_482 , V_36 , V_553 ,
V_555 ) ;
}
}
if ( V_16 == 0 )
V_16 = V_545 * V_561 + V_556 ;
F_203 ( & V_482 -> V_569 ) ;
V_566:
F_199 ( & V_2 -> V_560 ) ;
F_204 ( & V_482 -> V_569 , & V_557 ) ;
return V_16 ;
}
static void F_205 ( struct V_1 * V_2 )
{
}
static int F_206 ( struct V_1 * V_2 ,
unsigned int V_575 ,
T_5 V_576 , bool V_577 )
{
unsigned int V_483 = V_576 % V_561 ;
struct V_481 * V_482 = V_2 -> V_550 ;
F_7 ( V_62 ,
V_578 +
V_579 ) ;
struct V_465 * V_472 ;
F_193 ( V_557 ) ;
int V_16 ;
for (; ; ) {
F_196 ( & V_2 -> V_560 ) ;
if ( ! ( V_482 -> V_484 [ V_483 ] . V_472 &
V_562 ) )
break;
F_198 ( & V_482 -> V_569 , & V_557 , V_570 ) ;
F_199 ( & V_2 -> V_560 ) ;
F_200 () ;
}
V_472 = F_183 ( V_482 , V_483 ) ;
if ( ! V_472 ||
( ! V_577 &&
F_191 ( V_482 , V_472 -> V_468 ) !=
V_576 / V_561 ) ) {
V_16 = - V_59 ;
goto V_566;
}
if ( V_472 -> V_125 & V_571 &&
V_575 == ( 1U << V_564 ) ) {
V_472 -> V_125 &= ~ V_571 ;
V_482 -> V_484 [ V_483 ] . V_472 &= ~ V_572 ;
V_16 = 0 ;
goto V_566;
}
if ( ! ( V_575 & ( 1U << V_472 -> V_563 ) ) ) {
V_16 = - V_59 ;
goto V_566;
}
V_482 -> V_484 [ V_483 ] . V_472 |= V_562 ;
F_199 ( & V_2 -> V_560 ) ;
if ( V_472 -> V_125 & V_571 ) {
struct V_465 V_580 = * V_472 ;
V_580 . V_563 = V_564 ;
V_580 . V_125 = ( V_469 |
V_533 ) ;
V_580 . V_525 = 0 ;
V_580 . V_537 = V_538 ;
V_16 = F_189 ( V_2 , & V_580 ,
& V_482 -> V_484 [ V_483 ] . V_486 ,
true ) ;
F_196 ( & V_2 -> V_560 ) ;
if ( V_16 == 0 )
* V_472 = V_580 ;
} else {
F_40 ( V_62 , V_489 ,
F_179 ( V_472 ) ?
V_581 :
V_574 ) ;
F_187 ( V_62 , V_491 ,
V_482 -> V_484 [ V_483 ] . V_486 ) ;
V_16 = F_9 ( V_2 , V_540 ,
V_62 , sizeof( V_62 ) , NULL , 0 , NULL ) ;
F_196 ( & V_2 -> V_560 ) ;
if ( V_16 == 0 ) {
F_34 ( V_472 ) ;
F_185 ( V_482 , V_483 , NULL , 0 ) ;
}
}
V_482 -> V_484 [ V_483 ] . V_472 &= ~ V_562 ;
F_203 ( & V_482 -> V_569 ) ;
V_566:
F_199 ( & V_2 -> V_560 ) ;
F_204 ( & V_482 -> V_569 , & V_557 ) ;
return V_16 ;
}
static int F_207 ( struct V_1 * V_2 ,
enum V_582 V_563 ,
T_5 V_576 )
{
return F_206 ( V_2 , 1U << V_563 ,
V_576 , false ) ;
}
static int F_208 ( struct V_1 * V_2 ,
enum V_582 V_563 ,
T_5 V_576 , struct V_465 * V_472 )
{
unsigned int V_483 = V_576 % V_561 ;
struct V_481 * V_482 = V_2 -> V_550 ;
const struct V_465 * V_553 ;
int V_16 ;
F_196 ( & V_2 -> V_560 ) ;
V_553 = F_183 ( V_482 , V_483 ) ;
if ( V_553 && V_553 -> V_563 == V_563 &&
F_191 ( V_482 , V_553 -> V_468 ) ==
V_576 / V_561 ) {
* V_472 = * V_553 ;
V_16 = 0 ;
} else {
V_16 = - V_59 ;
}
F_199 ( & V_2 -> V_560 ) ;
return V_16 ;
}
static int F_209 ( struct V_1 * V_2 ,
enum V_582 V_563 )
{
unsigned int V_575 ;
unsigned int V_36 ;
int V_16 ;
V_575 = ( ( ( 1U << ( V_563 + 1 ) ) - 1 ) &
~ ( 1U << V_564 ) ) ;
for ( V_36 = 0 ; V_36 < V_561 ; V_36 ++ ) {
V_16 = F_206 ( V_2 , V_575 ,
V_36 , true ) ;
if ( V_16 && V_16 != - V_59 )
return V_16 ;
}
return 0 ;
}
static T_5 F_210 ( struct V_1 * V_2 ,
enum V_582 V_563 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
unsigned int V_483 ;
T_15 V_583 = 0 ;
F_196 ( & V_2 -> V_560 ) ;
for ( V_483 = 0 ; V_483 < V_561 ; V_483 ++ ) {
if ( V_482 -> V_484 [ V_483 ] . V_472 &&
F_183 ( V_482 , V_483 ) -> V_563 ==
V_563 )
++ V_583 ;
}
F_199 ( & V_2 -> V_560 ) ;
return V_583 ;
}
static T_5 F_211 ( struct V_1 * V_2 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
return V_482 -> V_546 * V_561 ;
}
static T_15 F_212 ( struct V_1 * V_2 ,
enum V_582 V_563 ,
T_5 * V_240 , T_5 V_584 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
struct V_465 * V_472 ;
unsigned int V_483 ;
T_15 V_583 = 0 ;
F_196 ( & V_2 -> V_560 ) ;
for ( V_483 = 0 ; V_483 < V_561 ; V_483 ++ ) {
V_472 = F_183 ( V_482 , V_483 ) ;
if ( V_472 && V_472 -> V_563 == V_563 ) {
if ( V_583 == V_584 ) {
V_583 = - V_585 ;
break;
}
V_240 [ V_583 ++ ] = ( F_191 (
V_482 , V_472 -> V_468 ) *
V_561 +
V_483 ) ;
}
}
F_199 ( & V_2 -> V_560 ) ;
return V_583 ;
}
static T_15 F_213 ( struct V_1 * V_2 ,
struct V_465 * V_472 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
F_7 ( V_62 , V_488 ) ;
struct V_465 * V_553 ;
unsigned int V_554 , V_36 , V_559 = 1 ;
bool V_487 = false ;
int V_556 = - 1 ;
T_6 V_357 ;
T_15 V_16 ;
F_214 ( V_472 -> V_125 !=
( V_469 | V_586 ) ) ;
F_214 ( V_472 -> V_563 != V_587 ) ;
F_214 ( F_194 ( V_472 ) ) ;
V_554 = F_177 ( V_472 ) ;
F_196 ( & V_2 -> V_560 ) ;
for (; ; ) {
V_36 = ( V_554 + V_559 ) & ( V_561 - 1 ) ;
V_553 = F_183 ( V_482 , V_36 ) ;
if ( ! V_553 ) {
if ( V_556 < 0 )
V_556 = V_36 ;
} else if ( F_175 ( V_472 , V_553 ) ) {
if ( V_482 -> V_484 [ V_36 ] . V_472 & V_562 ) {
V_16 = - V_543 ;
goto V_588;
}
if ( V_472 -> V_563 < V_553 -> V_563 ) {
V_16 = - V_565 ;
goto V_588;
}
V_556 = V_36 ;
break;
}
if ( V_559 == V_552 ) {
if ( V_556 < 0 ) {
V_16 = - V_543 ;
goto V_588;
}
break;
}
++ V_559 ;
}
V_553 = F_183 ( V_482 , V_556 ) ;
if ( V_553 ) {
V_487 = true ;
} else {
V_553 = F_201 ( sizeof( * V_472 ) , V_573 ) ;
if ( ! V_553 ) {
V_16 = - V_39 ;
goto V_588;
}
* V_553 = * V_472 ;
}
F_185 ( V_482 , V_556 , V_553 ,
V_562 ) ;
F_199 ( & V_2 -> V_560 ) ;
V_357 = V_487 << 31 | V_556 << 16 | V_472 -> V_525 ;
F_186 ( V_2 , V_472 , V_62 ,
V_482 -> V_484 [ V_556 ] . V_486 , V_487 ) ;
F_134 ( V_2 , V_540 , V_62 , sizeof( V_62 ) ,
V_539 ,
V_589 , V_357 ) ;
return V_556 ;
V_588:
F_199 ( & V_2 -> V_560 ) ;
return V_16 ;
}
static void
V_589 ( struct V_1 * V_2 , unsigned long V_357 ,
int V_16 , T_1 * V_11 ,
T_2 V_358 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
unsigned int V_556 , V_525 ;
struct V_465 * V_472 ;
bool V_487 ;
V_487 = V_357 >> 31 ;
V_556 = ( V_357 >> 16 ) & ( V_561 - 1 ) ;
V_525 = V_357 & 0xffff ;
F_196 ( & V_2 -> V_560 ) ;
V_472 = F_183 ( V_482 , V_556 ) ;
if ( V_16 == 0 ) {
V_482 -> V_484 [ V_556 ] . V_486 =
F_190 ( V_11 , V_541 ) ;
if ( V_487 )
V_472 -> V_525 = V_525 ;
} else if ( ! V_487 ) {
F_34 ( V_472 ) ;
V_472 = NULL ;
}
F_185 ( V_482 , V_556 , V_472 , 0 ) ;
F_199 ( & V_2 -> V_560 ) ;
F_203 ( & V_482 -> V_569 ) ;
}
static bool F_215 ( struct V_1 * V_2 , T_5 V_590 ,
unsigned int V_483 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
struct V_465 * V_472 =
F_183 ( V_482 , V_483 ) ;
F_7 ( V_62 ,
V_578 +
V_579 ) ;
if ( ! V_472 ||
( V_482 -> V_484 [ V_483 ] . V_472 & V_562 ) ||
V_472 -> V_563 != V_587 ||
! F_216 ( V_2 -> V_20 , V_472 -> V_525 ,
V_590 , V_483 ) )
return false ;
F_40 ( V_62 , V_489 ,
V_581 ) ;
F_187 ( V_62 , V_491 ,
V_482 -> V_484 [ V_483 ] . V_486 ) ;
if ( F_134 ( V_2 , V_540 , V_62 , sizeof( V_62 ) , 0 ,
V_591 , V_483 ) )
return false ;
V_482 -> V_484 [ V_483 ] . V_472 |= V_562 ;
return true ;
}
static void
V_591 ( struct V_1 * V_2 ,
unsigned long V_483 ,
int V_16 , T_1 * V_11 ,
T_2 V_358 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
struct V_465 * V_472 =
F_183 ( V_482 , V_483 ) ;
F_196 ( & V_2 -> V_560 ) ;
if ( V_16 == 0 ) {
F_34 ( V_472 ) ;
F_185 ( V_482 , V_483 , NULL , 0 ) ;
}
V_482 -> V_484 [ V_483 ] . V_472 &= ~ V_562 ;
F_203 ( & V_482 -> V_569 ) ;
F_199 ( & V_2 -> V_560 ) ;
}
static int F_217 ( T_5 V_592 )
{
int V_468 = 0 ;
#define F_218 ( T_12 , T_14 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_218 ( V_593 , V_594 ) ;
F_218 ( V_593 , V_595 ) ;
F_218 ( V_498 , V_500 ) ;
F_218 ( V_501 , V_502 ) ;
F_218 ( V_503 , V_505 ) ;
F_218 ( V_506 , V_508 ) ;
F_218 ( V_509 , V_510 ) ;
F_218 ( V_511 , V_513 ) ;
F_218 ( V_514 , V_514 ) ;
F_218 ( V_515 , V_517 ) ;
F_218 ( V_518 , V_519 ) ;
F_218 ( V_520 , V_520 ) ;
#undef F_218
if ( V_592 )
return - V_136 ;
return V_468 ;
}
static int F_219 ( struct V_1 * V_2 )
{
F_7 ( V_62 , V_596 ) ;
F_7 ( V_11 , V_597 ) ;
unsigned int V_598 , V_599 ;
struct V_481 * V_482 ;
T_2 V_15 ;
int V_16 ;
V_482 = F_19 ( sizeof( * V_482 ) , V_38 ) ;
if ( ! V_482 )
return - V_39 ;
F_40 ( V_62 , V_600 ,
V_601 ) ;
V_16 = F_9 ( V_2 , V_602 ,
V_62 , sizeof( V_62 ) , V_11 , sizeof( V_11 ) ,
& V_15 ) ;
if ( V_16 )
goto V_88;
V_599 = F_220 (
V_15 , V_603 ) ;
V_482 -> V_546 = 0 ;
for ( V_598 = 0 ; V_598 < V_599 ; V_598 ++ ) {
T_5 V_592 =
F_221 (
V_11 ,
V_603 ,
V_598 ) ;
V_16 = F_217 ( V_592 ) ;
if ( V_16 < 0 ) {
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_40 ,
V_317 , V_592 , V_598 ) ;
} else {
F_29 ( V_2 , V_26 , V_2 -> V_20 ,
L_41 ,
V_317 , V_592 , V_598 ,
V_16 , V_482 -> V_546 ) ;
V_482 -> V_547 [ V_482 -> V_546 ++ ] = V_16 ;
}
}
V_482 -> V_484 = F_222 ( V_561 * sizeof( * V_482 -> V_484 ) ) ;
if ( ! V_482 -> V_484 ) {
V_16 = - V_39 ;
goto V_88;
}
V_2 -> V_550 = V_482 ;
F_223 ( & V_482 -> V_569 ) ;
return 0 ;
V_88:
F_34 ( V_482 ) ;
return V_16 ;
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_465 * V_472 ;
unsigned int V_483 ;
bool V_604 = false ;
int V_16 ;
if ( ! V_14 -> V_124 )
return;
F_196 ( & V_2 -> V_560 ) ;
for ( V_483 = 0 ; V_483 < V_561 ; V_483 ++ ) {
V_472 = F_183 ( V_482 , V_483 ) ;
if ( ! V_472 )
continue;
V_482 -> V_484 [ V_483 ] . V_472 |= V_562 ;
F_199 ( & V_2 -> V_560 ) ;
V_16 = F_189 ( V_2 , V_472 ,
& V_482 -> V_484 [ V_483 ] . V_486 ,
false ) ;
if ( V_16 )
V_604 = true ;
F_196 ( & V_2 -> V_560 ) ;
if ( V_16 ) {
F_34 ( V_472 ) ;
F_185 ( V_482 , V_483 , NULL , 0 ) ;
} else {
V_482 -> V_484 [ V_483 ] . V_472 &=
~ V_562 ;
}
}
F_199 ( & V_2 -> V_560 ) ;
if ( V_604 )
F_10 ( V_2 , V_266 , V_2 -> V_20 ,
L_42 ) ;
else
V_14 -> V_124 = false ;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
F_7 ( V_62 , V_488 ) ;
struct V_465 * V_472 ;
unsigned int V_483 ;
int V_16 ;
for ( V_483 = 0 ; V_483 < V_561 ; V_483 ++ ) {
V_472 = F_183 ( V_482 , V_483 ) ;
if ( ! V_472 )
continue;
F_40 ( V_62 , V_489 ,
F_179 ( V_472 ) ?
V_581 :
V_574 ) ;
F_187 ( V_62 , V_491 ,
V_482 -> V_484 [ V_483 ] . V_486 ) ;
V_16 = F_9 ( V_2 , V_540 , V_62 , sizeof( V_62 ) ,
NULL , 0 , NULL ) ;
if ( V_16 )
F_110 ( V_2 -> V_20 ,
L_43 ,
V_483 ,
V_482 -> V_484 [ V_483 ] . V_486 ) ;
F_34 ( V_472 ) ;
}
F_226 ( V_482 -> V_484 ) ;
F_34 ( V_482 ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_481 * V_482 = V_2 -> V_550 ;
struct V_605 * V_20 = V_2 -> V_20 ;
struct V_465 V_472 ;
bool V_606 = false ;
struct V_607 * V_608 ;
struct V_607 * V_609 ;
unsigned int V_483 ;
int V_36 , V_69 , V_16 ;
if ( ! F_228 ( V_2 ) )
return;
F_196 ( & V_2 -> V_560 ) ;
V_69 = V_482 -> V_610 < 0 ? 1 : V_482 -> V_610 ;
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
V_483 = V_482 -> V_611 [ V_36 ] . V_612 % V_561 ;
V_482 -> V_484 [ V_483 ] . V_472 |= V_572 ;
}
V_69 = V_482 -> V_613 < 0 ? 1 : V_482 -> V_613 ;
for ( V_36 = 0 ; V_36 < V_69 ; V_36 ++ ) {
V_483 = V_482 -> V_614 [ V_36 ] . V_612 % V_561 ;
V_482 -> V_484 [ V_483 ] . V_472 |= V_572 ;
}
F_199 ( & V_2 -> V_560 ) ;
F_229 ( V_20 ) ;
if ( V_20 -> V_125 & V_615 ||
F_230 ( V_20 ) >= V_616 ) {
V_482 -> V_610 = - 1 ;
} else {
V_482 -> V_610 = 1 + F_230 ( V_20 ) ;
F_14 ( V_482 -> V_611 [ 0 ] . V_157 , V_20 -> V_617 ) ;
V_36 = 1 ;
F_231 (uc, net_dev) {
F_14 ( V_482 -> V_611 [ V_36 ] . V_157 , V_608 -> V_157 ) ;
V_36 ++ ;
}
}
if ( V_20 -> V_125 & ( V_615 | V_618 ) ||
F_232 ( V_20 ) >= V_619 ) {
V_482 -> V_613 = - 1 ;
} else {
V_482 -> V_613 = 1 + F_232 ( V_20 ) ;
F_233 ( V_482 -> V_614 [ 0 ] . V_157 ) ;
V_36 = 1 ;
F_234 (mc, net_dev) {
F_14 ( V_482 -> V_614 [ V_36 ] . V_157 , V_609 -> V_157 ) ;
V_36 ++ ;
}
}
F_235 ( V_20 ) ;
if ( V_482 -> V_610 >= 0 ) {
for ( V_36 = 0 ; V_36 < V_482 -> V_610 ; V_36 ++ ) {
F_236 ( & V_472 , V_564 ,
V_533 ,
0 ) ;
F_237 ( & V_472 , V_620 ,
V_482 -> V_611 [ V_36 ] . V_157 ) ;
V_16 = F_192 ( V_2 , & V_472 , true ) ;
if ( V_16 < 0 ) {
while ( V_36 -- )
F_207 (
V_2 , V_564 ,
V_482 -> V_611 [ V_36 ] . V_612 ) ;
V_482 -> V_610 = - 1 ;
break;
}
V_482 -> V_611 [ V_36 ] . V_612 = V_16 ;
}
}
if ( V_482 -> V_610 < 0 ) {
F_236 ( & V_472 , V_564 ,
V_533 ,
0 ) ;
F_238 ( & V_472 ) ;
V_16 = F_192 ( V_2 , & V_472 , true ) ;
if ( V_16 < 0 ) {
F_41 ( 1 ) ;
V_482 -> V_610 = 0 ;
} else {
V_482 -> V_611 [ 0 ] . V_612 = V_16 ;
}
}
if ( V_482 -> V_613 >= 0 ) {
for ( V_36 = 0 ; V_36 < V_482 -> V_613 ; V_36 ++ ) {
F_236 ( & V_472 , V_564 ,
V_533 ,
0 ) ;
F_237 ( & V_472 , V_620 ,
V_482 -> V_614 [ V_36 ] . V_157 ) ;
V_16 = F_192 ( V_2 , & V_472 , true ) ;
if ( V_16 < 0 ) {
while ( V_36 -- )
F_207 (
V_2 , V_564 ,
V_482 -> V_614 [ V_36 ] . V_612 ) ;
V_482 -> V_613 = - 1 ;
break;
}
V_482 -> V_614 [ V_36 ] . V_612 = V_16 ;
}
}
if ( V_482 -> V_613 < 0 ) {
F_236 ( & V_472 , V_564 ,
V_533 ,
0 ) ;
F_239 ( & V_472 ) ;
V_16 = F_192 ( V_2 , & V_472 , true ) ;
if ( V_16 < 0 ) {
F_41 ( 1 ) ;
V_482 -> V_613 = 0 ;
} else {
V_482 -> V_614 [ 0 ] . V_612 = V_16 ;
}
}
for ( V_36 = 0 ; V_36 < V_561 ; V_36 ++ ) {
if ( F_95 ( V_482 -> V_484 [ V_36 ] . V_472 ) &
V_572 ) {
if ( F_206 (
V_2 , 1U << V_564 ,
V_36 , true ) < 0 )
V_606 = true ;
}
}
F_41 ( V_606 ) ;
}
static int F_240 ( struct V_1 * V_2 )
{
F_227 ( V_2 ) ;
return F_241 ( V_2 ) ;
}
static int F_242 ( struct V_1 * V_2 , T_5 V_621 )
{
F_7 ( V_62 , V_622 ) ;
F_40 ( V_62 , V_623 , V_621 ) ;
return F_9 ( V_2 , V_624 , V_62 , sizeof( V_62 ) ,
NULL , 0 , NULL ) ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_16 ;
F_7 ( V_11 , V_625 ) ;
T_2 V_15 ;
T_5 V_626 ;
V_16 = F_9 ( V_2 , V_627 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_625 )
return - V_7 ;
V_626 = F_11 ( V_11 , V_628 ) ;
switch ( V_626 ) {
case V_629 :
F_29 ( V_2 , V_266 , V_2 -> V_20 , L_44 ) ;
return 0 ;
case V_630 :
F_10 ( V_2 , V_266 , V_2 -> V_20 , L_45 ) ;
return - V_7 ;
case V_631 :
F_10 ( V_2 , V_266 , V_2 -> V_20 , L_46 ) ;
return - V_7 ;
default:
F_10 ( V_2 , V_266 , V_2 -> V_20 ,
L_47 , V_626 ) ;
return - V_7 ;
}
}
static int F_244 ( struct V_1 * V_2 , T_5 V_621 )
{
int V_16 ;
F_29 ( V_2 , V_19 , V_2 -> V_20 , L_48 , V_621 ) ;
V_16 = F_242 ( V_2 , V_621 ) ;
if ( V_16 != 0 )
return V_16 ;
return F_243 ( V_2 ) ;
}
static int
F_245 ( struct V_1 * V_2 , struct V_632 * V_633 )
{
int V_16 , V_634 ;
F_246 ( V_2 , V_135 ) ;
V_16 = F_9 ( V_2 , V_635 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
goto V_445;
V_633 -> V_636 = F_244 ( V_2 , V_637 ) ? - 1 : 1 ;
V_633 -> V_638 = F_244 ( V_2 , V_639 ) ? - 1 : 1 ;
V_16 = F_25 ( V_2 , V_135 ) ;
V_445:
V_634 = F_247 ( V_2 , V_135 , V_16 == 0 ) ;
return V_16 ? V_16 : V_634 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_640 * V_641 ,
unsigned int type )
{
F_7 ( V_62 , V_642 ) ;
F_7 ( V_11 , V_643 ) ;
const struct V_644 * V_645 ;
T_2 V_584 , V_646 , V_15 ;
bool V_647 ;
int V_16 ;
for ( V_645 = V_648 ; ; V_645 ++ ) {
if ( V_645 ==
V_648 + F_121 ( V_648 ) )
return - V_24 ;
if ( ( type & ~ V_645 -> V_649 ) == V_645 -> type )
break;
}
if ( V_645 -> V_650 != F_249 ( V_2 ) )
return - V_24 ;
V_16 = F_250 ( V_2 , type , & V_584 , & V_646 , & V_647 ) ;
if ( V_16 )
return V_16 ;
if ( V_647 )
return - V_24 ;
V_641 -> V_651 = type ;
F_40 ( V_62 , V_652 , type ) ;
V_16 = F_9 ( V_2 , V_653 , V_62 , sizeof( V_62 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_654 )
return - V_7 ;
if ( F_11 ( V_11 , V_655 ) &
( 1 << V_656 ) )
V_641 -> V_657 = F_11 ( V_11 ,
V_658 ) ;
V_641 -> V_659 . V_660 = L_49 ;
V_641 -> V_659 . V_661 = V_645 -> V_172 ;
V_641 -> V_659 . V_662 . type = V_663 ;
V_641 -> V_659 . V_662 . V_125 = V_664 ;
V_641 -> V_659 . V_662 . V_584 = V_584 ;
V_641 -> V_659 . V_662 . V_665 = V_646 ;
return 0 ;
}
static int F_251 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_666 ) ;
struct V_640 * V_667 ;
T_2 V_15 , V_668 , V_36 , V_669 ;
unsigned int type ;
int V_16 ;
F_252 () ;
F_8 ( V_670 != 0 ) ;
V_16 = F_9 ( V_2 , V_671 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_672 )
return - V_7 ;
V_668 = F_11 ( V_11 , V_673 ) ;
if ( V_668 >
F_220 ( V_15 , V_674 ) )
return - V_7 ;
V_667 = F_253 ( V_668 , sizeof( * V_667 ) , V_38 ) ;
if ( ! V_667 )
return - V_39 ;
V_669 = 0 ;
for ( V_36 = 0 ; V_36 < V_668 ; V_36 ++ ) {
type = F_221 ( V_11 , V_674 ,
V_36 ) ;
V_16 = F_248 ( V_2 , & V_667 [ V_669 ] , type ) ;
if ( V_16 == 0 )
V_669 ++ ;
else if ( V_16 != - V_24 )
goto V_88;
}
V_16 = F_254 ( V_2 , & V_667 [ 0 ] . V_659 , V_669 , sizeof( * V_667 ) ) ;
V_88:
if ( V_16 )
F_34 ( V_667 ) ;
return V_16 ;
}
static void F_255 ( struct V_1 * V_2 , T_5 V_675 )
{
F_22 ( V_2 , F_23 ( V_675 ) , V_218 ) ;
}
static int F_256 ( struct V_76 * V_77 ,
bool V_676 )
{
F_7 ( V_62 , V_677 ) ;
int V_16 ;
if ( V_77 -> V_678 == V_679 ||
V_77 -> V_678 == V_680 ||
( V_676 && V_77 -> V_678 == V_681 ) )
return 0 ;
V_77 -> V_678 = V_679 ;
F_40 ( V_62 , V_682 , V_683 ) ;
F_40 ( V_62 , V_684 , 0 ) ;
F_40 ( V_62 , V_685 ,
V_77 -> V_77 ) ;
V_16 = F_9 ( V_77 -> V_2 , V_686 ,
V_62 , sizeof( V_62 ) , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
V_77 -> V_678 = V_676 ? V_687 :
V_681 ;
return V_16 ;
}
static int F_257 ( struct V_76 * V_77 ,
bool V_676 )
{
F_7 ( V_62 , V_688 ) ;
int V_16 ;
if ( V_77 -> V_678 == V_681 ||
( V_676 && V_77 -> V_678 == V_687 ) )
return 0 ;
if ( V_77 -> V_678 == V_687 ) {
V_77 -> V_678 = V_681 ;
return 0 ;
}
V_77 -> V_678 = V_676 ? V_687 :
V_681 ;
F_40 ( V_62 , V_682 , V_689 ) ;
F_40 ( V_62 , V_684 , 0 ) ;
F_40 ( V_62 , V_690 ,
V_691 ) ;
F_40 ( V_62 , V_692 ,
V_77 -> V_77 ) ;
V_16 = F_9 ( V_77 -> V_2 , V_686 ,
V_62 , sizeof( V_62 ) , NULL , 0 , NULL ) ;
return V_16 ;
}
static int F_258 ( struct V_1 * V_2 , bool V_693 ,
bool V_676 )
{
int (* F_259)( struct V_76 * V_77 , bool V_676 );
struct V_76 * V_77 ;
F_259 = V_693 ?
F_256 :
F_257 ;
F_45 (channel, efx) {
int V_16 = F_259 ( V_77 , V_676 ) ;
if ( V_693 && V_16 != 0 ) {
F_258 ( V_2 , false , V_676 ) ;
return V_16 ;
}
}
return 0 ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_694 * V_695 )
{
int V_16 ;
switch ( V_695 -> V_696 ) {
case V_697 :
F_258 ( V_2 , false , false ) ;
return F_261 ( V_2 ,
V_695 -> V_698 != V_699 , 0 ) ;
case V_700 :
case V_701 :
case V_702 :
case V_703 :
case V_704 :
case V_705 :
case V_706 :
case V_707 :
case V_708 :
case V_709 :
case V_710 :
case V_711 :
case V_712 :
V_695 -> V_696 = V_700 ;
V_16 = F_261 ( V_2 , true , 0 ) ;
if ( ! V_16 )
V_16 = F_258 ( V_2 , true , false ) ;
if ( V_16 )
F_261 ( V_2 , false , 0 ) ;
return V_16 ;
default:
return - V_30 ;
}
}
