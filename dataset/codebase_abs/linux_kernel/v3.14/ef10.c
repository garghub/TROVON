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
memcpy ( V_31 ,
F_14 ( V_11 , V_35 ) , V_36 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_37 , V_16 ;
V_2 -> V_38 =
F_16 (unsigned int,
EFX_MAX_CHANNELS,
resource_size(&efx->pci_dev->resource[EFX_MEM_BAR]) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
F_17 ( V_2 -> V_38 == 0 ) ;
V_14 = F_18 ( sizeof( * V_14 ) , V_39 ) ;
if ( ! V_14 )
return - V_40 ;
V_2 -> V_14 = V_14 ;
V_16 = F_19 ( V_2 , & V_14 -> V_41 ,
8 + V_42 , V_39 ) ;
if ( V_16 )
goto V_43;
V_37 = 0 ;
for (; ; ) {
V_16 = F_1 ( V_2 ) ;
if ( V_16 >= 0 )
break;
if ( ++ V_37 == 5 )
goto V_44;
F_20 ( 1 ) ;
}
V_14 -> V_45 = V_16 ;
V_14 -> V_46 = V_47 ;
F_21 ( V_2 , F_22 ( 1 ) , V_48 ) ;
V_16 = F_23 ( V_2 ) ;
if ( V_16 )
goto V_44;
V_16 = F_24 ( V_2 , V_49 ) ;
if ( V_16 )
goto V_50;
V_16 = F_25 ( V_2 , true , false , 0 ) ;
if ( V_16 )
goto V_50;
V_16 = F_6 ( V_2 ) ;
if ( V_16 < 0 )
goto V_50;
V_2 -> V_51 =
V_52 - V_53 ;
V_16 = F_26 ( V_2 ) ;
if ( V_16 < 0 )
goto V_50;
V_2 -> V_54 = V_16 ;
V_16 = F_13 ( V_2 , V_2 -> V_20 -> V_55 ) ;
if ( V_16 )
goto V_50;
V_16 = F_12 ( V_2 ) ;
if ( V_16 < 0 )
goto V_50;
V_2 -> V_56 = 1536000 / V_16 ;
V_16 = F_27 ( V_2 , V_57 , true ) ;
if ( V_16 == 0 )
V_14 -> V_58 = true ;
else if ( V_16 != - V_59 && V_16 != - V_60 )
goto V_50;
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_4 ,
V_14 -> V_58 ? L_5 : L_6 ) ;
V_16 = F_29 ( V_2 ) ;
if ( V_16 )
goto V_50;
F_30 ( V_2 , NULL ) ;
return 0 ;
V_50:
F_31 ( V_2 ) ;
V_44:
F_32 ( V_2 , & V_14 -> V_41 ) ;
V_43:
F_33 ( V_14 ) ;
V_2 -> V_14 = NULL ;
return V_16 ;
}
static int F_34 ( struct V_1 * V_2 )
{
F_35 ( V_11 , 0 ) ;
T_2 V_15 ;
int V_16 = F_36 ( V_2 , V_61 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 == - V_62 )
V_16 = 0 ;
if ( V_16 )
F_37 ( V_2 , V_61 , 0 , V_11 , V_15 ,
V_16 ) ;
return V_16 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_63 , V_64 ) ;
unsigned int V_37 ;
int V_16 ;
F_8 ( V_65 != 0 ) ;
for ( V_37 = 0 ; V_37 < V_14 -> V_66 ; V_37 ++ ) {
F_39 ( V_63 , V_67 ,
V_14 -> V_68 [ V_37 ] ) ;
V_16 = F_9 ( V_2 , V_69 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
F_40 ( V_16 ) ;
}
V_14 -> V_66 = 0 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_70 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_11 , V_71 ) ;
unsigned int V_37 ;
T_2 V_15 ;
int V_16 = 0 ;
F_8 ( V_72 != 0 ) ;
for ( V_37 = 0 ; V_37 < V_70 ; V_37 ++ ) {
V_16 = F_9 ( V_2 , V_73 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
break;
if ( V_15 < V_71 ) {
V_16 = - V_7 ;
break;
}
V_14 -> V_68 [ V_37 ] =
F_11 ( V_11 , V_74 ) ;
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_7 , V_37 ,
V_14 -> V_68 [ V_37 ] ) ;
}
V_14 -> V_66 = V_37 ;
if ( V_16 )
F_38 ( V_2 ) ;
return V_16 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_63 ,
F_43 ( V_75 ,
V_76 ) ) ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
unsigned int V_81 , V_82 ;
int V_16 ;
F_8 ( V_83 != 0 ) ;
F_8 ( V_84 != 0 ) ;
for ( V_82 = 0 ; V_82 < V_14 -> V_66 ; ++ V_82 ) {
F_39 ( V_63 , V_85 ,
V_14 -> V_68 [ V_82 ] ) ;
F_39 ( V_63 , V_86 ,
V_14 -> V_87 + V_82 ) ;
V_16 = F_9 ( V_2 , V_88 ,
V_63 , V_75 ,
NULL , 0 , NULL ) ;
if ( V_16 ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_8 ,
V_14 -> V_87 + V_82 , V_82 ,
V_16 ) ;
goto V_89;
}
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_9 ,
V_14 -> V_87 + V_82 , V_82 ) ;
}
F_44 (channel, efx) {
F_45 (tx_queue, channel) {
V_81 = ( ( V_2 -> V_90 + V_2 -> V_91 -
V_80 -> V_78 -> V_78 - 1 ) *
V_92 ) ;
V_82 = V_81 / V_93 ;
V_81 = V_81 % V_93 ;
if ( V_80 -> V_94 == V_14 -> V_87 ) {
F_17 ( V_82 != 0 ) ;
V_16 = 0 ;
} else {
F_39 ( V_63 ,
V_85 ,
V_14 -> V_68 [ V_82 ] ) ;
F_39 ( V_63 ,
V_86 ,
V_80 -> V_94 ) ;
V_16 = F_9 ( V_2 , V_88 ,
V_63 , V_75 ,
NULL , 0 , NULL ) ;
}
if ( V_16 ) {
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_8 ,
V_80 -> V_94 , V_82 , V_16 ) ;
V_80 -> V_95 = NULL ;
} else {
V_80 -> V_95 =
V_14 -> V_96 +
V_82 * V_97 + V_81 ;
V_80 -> V_98 = V_81 ;
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_10 ,
V_80 -> V_94 , V_82 ,
V_80 -> V_98 ,
V_80 -> V_95 ) ;
}
}
}
return 0 ;
V_89:
while ( V_82 -- ) {
F_39 ( V_63 , V_99 ,
V_14 -> V_87 + V_82 ) ;
F_9 ( V_2 , V_100 ,
V_63 , V_76 ,
NULL , 0 , NULL ) ;
}
return V_16 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned int V_70 )
{
return V_70 == 0 ? 0 : - V_101 ;
}
static int F_42 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
if ( V_14 -> V_102 )
F_50 ( V_14 -> V_102 ) ;
V_16 = F_34 ( V_2 ) ;
F_40 ( V_16 != 0 ) ;
if ( ! V_14 -> V_103 )
F_38 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 , & V_14 -> V_41 ) ;
F_33 ( V_14 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned int V_104 , unsigned int V_105 )
{
F_7 ( V_63 , V_106 ) ;
F_7 ( V_11 , V_107 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_63 , V_108 , V_104 ) ;
F_39 ( V_63 , V_109 , V_105 ) ;
V_16 = F_9 ( V_2 , V_110 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_107 )
return - V_7 ;
F_28 ( V_2 , V_19 , V_2 -> V_20 , L_11 ,
F_11 ( V_11 , V_111 ) ) ;
V_14 -> V_112 = F_11 ( V_11 , V_111 ) ;
V_14 -> V_113 = F_11 ( V_11 , V_114 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned int V_115 , V_116 ;
unsigned int V_104 , V_87 , V_105 ;
void T_4 * V_117 ;
int V_16 ;
V_104 = F_43 ( V_2 -> V_118 , V_2 -> V_91 * V_119 ) ;
#ifdef F_53
if ( V_92 != 0 &&
V_93 / V_92 * V_120 >=
V_2 -> V_91 ) {
unsigned int V_66 =
F_54 ( V_2 -> V_91 ,
V_93 / V_92 ) ;
V_16 = F_41 ( V_2 , V_66 ) ;
if ( V_16 )
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_12 , V_16 ) ;
else
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_13 , V_66 ) ;
}
#else
V_14 -> V_66 = 0 ;
#endif
V_115 = F_55 ( ( V_104 - 1 ) * V_97 +
V_121 ) ;
if ( V_14 -> V_66 ) {
V_87 = V_115 / V_97 ;
V_116 = ( F_55 ( ( V_87 +
V_14 -> V_66 ) *
V_97 ) -
V_115 ) ;
V_105 = V_87 + V_14 -> V_66 ;
} else {
V_87 = 0 ;
V_116 = 0 ;
V_105 = V_104 ;
}
V_16 = F_34 ( V_2 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_51 ( V_2 , V_104 , V_105 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_14 -> V_66 &&
V_14 -> V_113 <
V_87 + V_14 -> V_66 ) {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_14 ,
V_14 -> V_113 , V_14 -> V_66 ) ;
F_38 ( V_2 ) ;
}
V_117 = F_56 ( V_2 -> V_122 , V_115 ) ;
if ( ! V_117 ) {
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_15 ,
V_115 ) ;
return - V_40 ;
}
F_50 ( V_2 -> V_117 ) ;
V_2 -> V_117 = V_117 ;
if ( V_116 ) {
V_14 -> V_102 = F_57 ( V_2 -> V_122 +
V_115 ,
V_116 ) ;
if ( ! V_14 -> V_102 ) {
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_16 ,
V_116 ) ;
return - V_40 ;
}
V_14 -> V_87 = V_87 ;
V_14 -> V_96 =
V_14 -> V_102 +
( V_87 * V_97 + V_121 -
V_115 ) ;
V_16 = F_42 ( V_2 ) ;
if ( V_16 )
F_38 ( V_2 ) ;
}
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_17 ,
& V_2 -> V_122 , V_2 -> V_117 , V_115 ,
V_14 -> V_102 , V_116 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
if ( V_14 -> V_123 ) {
V_16 = F_6 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_123 = false ;
}
if ( V_14 -> V_124 ) {
V_16 = F_51 ( V_2 , V_14 -> V_113 ,
V_14 -> V_113 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_124 = false ;
}
if ( V_14 -> V_103 && V_14 -> V_66 ) {
V_16 = F_41 ( V_2 , V_14 -> V_66 ) ;
if ( V_16 == 0 ) {
V_16 = F_42 ( V_2 ) ;
if ( V_16 )
F_38 ( V_2 ) ;
}
if ( V_16 )
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_18 , V_16 ) ;
V_14 -> V_103 = false ;
}
F_59 ( V_2 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_124 = true ;
V_14 -> V_125 = true ;
V_14 -> V_103 = true ;
V_14 -> V_46 = V_47 ;
}
static int F_61 ( T_5 * V_126 )
{
enum {
V_127 = ( ( V_128 | V_129 ) <<
V_130 ) ,
V_131 = ( ( V_132 | V_133 |
V_134 | V_128 |
V_129 | V_135 ) <<
V_130 )
};
if ( ( * V_126 & V_131 ) == V_131 ) {
* V_126 &= ~ V_131 ;
return V_136 ;
}
if ( ( * V_126 & V_127 ) == V_127 ) {
* V_126 &= ~ V_127 ;
return V_49 ;
}
return - V_137 ;
}
static int F_62 ( struct V_1 * V_2 , enum V_138 V_138 )
{
int V_16 = F_24 ( V_2 , V_138 ) ;
if ( V_138 == V_49 && ! V_16 )
F_60 ( V_2 ) ;
return V_16 ;
}
static T_6 F_63 ( struct V_1 * V_2 )
{
T_6 V_139 = V_140 ;
T_5 V_141 = F_64 ( V_2 ) ;
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
static void F_65 ( struct V_1 * V_2 , unsigned long * V_147 )
{
T_6 V_139 = F_63 ( V_2 ) ;
#if V_148 == 64
V_147 [ 0 ] = V_139 ;
#else
V_147 [ 0 ] = V_139 & 0xffffffff ;
V_147 [ 1 ] = V_139 >> 32 ;
#endif
}
static T_2 F_66 ( struct V_1 * V_2 , T_3 * V_149 )
{
F_67 ( V_147 , V_150 ) ;
F_65 ( V_2 , V_147 ) ;
return F_68 ( V_151 , V_150 ,
V_147 , V_149 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_67 ( V_147 , V_150 ) ;
T_7 V_152 , V_153 ;
T_6 * V_154 = V_14 -> V_154 ;
T_7 * V_155 ;
F_65 ( V_2 , V_147 ) ;
V_155 = V_2 -> V_156 . V_157 ;
V_14 = V_2 -> V_14 ;
V_153 = V_155 [ V_158 ] ;
if ( V_153 == V_159 )
return 0 ;
F_70 () ;
F_71 ( V_151 , V_150 , V_147 ,
V_154 , V_2 -> V_156 . V_157 , false ) ;
F_70 () ;
V_152 = V_155 [ V_160 ] ;
if ( V_153 != V_152 )
return - V_161 ;
F_72 ( V_2 , & V_154 [ V_162 ] ) ;
V_154 [ V_163 ] =
V_154 [ V_164 ] -
V_154 [ V_165 ] ;
F_73 ( & V_154 [ V_166 ] ,
V_154 [ V_165 ] ) ;
return 0 ;
}
static T_2 F_74 ( struct V_1 * V_2 , T_6 * V_167 ,
struct V_168 * V_169 )
{
F_67 ( V_147 , V_150 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 * V_154 = V_14 -> V_154 ;
T_2 V_170 = 0 , V_82 ;
int V_171 ;
F_65 ( V_2 , V_147 ) ;
for ( V_171 = 0 ; V_171 < 100 ; ++ V_171 ) {
if ( F_69 ( V_2 ) == 0 )
break;
F_75 ( 100 ) ;
}
if ( V_167 ) {
F_76 (index, mask, EF10_STAT_COUNT) {
if ( V_151 [ V_82 ] . V_172 ) {
* V_167 ++ = V_154 [ V_82 ] ;
++ V_170 ;
}
}
}
if ( V_169 ) {
V_169 -> V_173 = V_154 [ V_174 ] ;
V_169 -> V_175 = V_154 [ V_176 ] ;
V_169 -> V_177 = V_154 [ V_164 ] ;
V_169 -> V_178 = V_154 [ V_179 ] ;
V_169 -> V_180 = V_154 [ V_162 ] ;
V_169 -> V_181 = V_154 [ V_182 ] ;
V_169 -> V_183 =
V_154 [ V_184 ] +
V_154 [ V_185 ] ;
V_169 -> V_186 = V_154 [ V_187 ] ;
V_169 -> V_188 = V_154 [ V_189 ] ;
V_169 -> V_190 = V_154 [ V_191 ] ;
V_169 -> V_192 = ( V_169 -> V_183 +
V_169 -> V_186 +
V_169 -> V_188 ) ;
}
return V_170 ;
}
static void F_77 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
unsigned int V_193 , V_194 ;
T_1 V_195 ;
if ( V_78 -> V_196 ) {
V_193 = 3 ;
V_194 = V_78 -> V_196 - 1 ;
} else {
V_193 = 0 ;
V_194 = 0 ;
}
if ( F_78 ( V_2 ) ) {
F_79 ( V_195 , V_197 ,
V_198 ,
V_199 , V_193 ,
V_200 , V_194 ) ;
F_80 ( V_2 , & V_195 , V_201 ,
V_78 -> V_78 ) ;
} else {
F_81 ( V_195 , V_202 , V_193 ,
V_203 , V_194 ) ;
F_80 ( V_2 , & V_195 , V_204 ,
V_78 -> V_78 ) ;
}
}
static void F_82 ( struct V_1 * V_2 , struct V_205 * V_206 )
{
V_206 -> V_207 = 0 ;
V_206 -> V_208 = 0 ;
memset ( & V_206 -> V_209 , 0 , sizeof( V_206 -> V_209 ) ) ;
}
static int F_83 ( struct V_1 * V_2 , T_5 type )
{
if ( type != 0 )
return - V_137 ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 ,
const T_1 * V_210 , T_2 V_211 ,
const T_1 * V_212 , T_2 V_213 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_3 * V_214 = V_14 -> V_41 . V_157 ;
memcpy ( V_214 , V_210 , V_211 ) ;
memcpy ( V_214 + V_211 , V_212 , V_213 ) ;
F_85 () ;
F_21 ( V_2 , F_22 ( ( T_6 ) V_14 -> V_41 . V_215 >> 32 ) ,
V_216 ) ;
F_21 ( V_2 , F_22 ( ( T_5 ) V_14 -> V_41 . V_215 ) ,
V_48 ) ;
}
static bool F_86 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_1 V_210 = * ( const T_1 * ) V_14 -> V_41 . V_157 ;
F_70 () ;
return F_3 ( V_210 , V_217 ) ;
}
static void
F_87 ( struct V_1 * V_2 , T_1 * V_11 ,
T_2 V_81 , T_2 V_15 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_3 * V_214 = V_14 -> V_41 . V_157 ;
memcpy ( V_11 , V_214 + V_81 , V_15 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
V_16 = F_1 ( V_2 ) ;
if ( V_16 < 0 ) {
return 0 ;
}
if ( V_16 == V_14 -> V_45 )
return 0 ;
V_14 -> V_45 = V_16 ;
F_60 ( V_2 ) ;
V_14 -> V_123 = true ;
V_14 -> V_154 [ V_166 ] = 0 ;
return - V_7 ;
}
static T_8 F_89 ( int V_218 , void * V_219 )
{
struct V_220 * V_221 = V_219 ;
struct V_1 * V_2 = V_221 -> V_2 ;
F_90 ( V_2 , V_222 , V_2 -> V_20 ,
L_19 , V_218 , F_91 () ) ;
if ( F_92 ( F_93 ( V_2 -> V_223 ) ) ) {
if ( V_221 -> V_82 == V_2 -> V_224 )
V_2 -> V_225 = F_91 () ;
F_94 ( V_2 -> V_78 [ V_221 -> V_82 ] ) ;
}
return V_226 ;
}
static T_8 F_95 ( int V_218 , void * V_219 )
{
struct V_1 * V_2 = V_219 ;
bool V_227 = F_93 ( V_2 -> V_223 ) ;
struct V_77 * V_78 ;
T_1 V_3 ;
T_5 V_228 ;
F_2 ( V_2 , & V_3 , V_229 ) ;
V_228 = F_3 ( V_3 , V_230 ) ;
if ( V_228 == 0 )
return V_231 ;
if ( F_92 ( V_227 ) ) {
if ( V_228 & ( 1U << V_2 -> V_224 ) )
V_2 -> V_225 = F_91 () ;
F_44 (channel, efx) {
if ( V_228 & 1 )
F_94 ( V_78 ) ;
V_228 >>= 1 ;
}
}
F_90 ( V_2 , V_222 , V_2 -> V_20 ,
L_20 V_232 L_21 ,
V_218 , F_91 () , F_96 ( V_3 ) ) ;
return V_226 ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_7 ( V_63 , V_233 ) ;
F_8 ( V_234 != 0 ) ;
F_39 ( V_63 , V_235 , V_2 -> V_224 ) ;
( void ) F_9 ( V_2 , V_236 ,
V_63 , sizeof( V_63 ) , NULL , 0 , NULL ) ;
}
static int F_98 ( struct V_79 * V_80 )
{
return F_19 ( V_80 -> V_2 , & V_80 -> V_237 . V_238 ,
( V_80 -> V_239 + 1 ) *
sizeof( V_240 ) ,
V_39 ) ;
}
static inline void F_99 ( struct V_79 * V_80 ,
const V_240 * V_237 )
{
unsigned int V_241 ;
T_9 V_3 ;
V_241 = V_80 -> V_242 & V_80 -> V_239 ;
F_100 ( V_3 , V_243 , V_241 ) ;
V_3 . V_244 [ 0 ] = * V_237 ;
F_101 ( V_80 -> V_2 , & V_3 ,
V_245 , V_80 -> V_94 ) ;
}
static void F_102 ( struct V_79 * V_80 )
{
F_7 ( V_63 , F_103 ( V_246 * 8 /
V_247 ) ) ;
F_7 ( V_11 , V_248 ) ;
bool V_249 = V_80 -> V_94 & V_250 ;
T_2 V_251 = V_80 -> V_237 . V_238 . V_252 / V_247 ;
struct V_77 * V_78 = V_80 -> V_78 ;
struct V_1 * V_2 = V_80 -> V_2 ;
T_2 V_253 , V_15 ;
T_10 V_215 ;
V_240 * V_237 ;
int V_16 ;
int V_37 ;
F_39 ( V_63 , V_254 , V_80 -> V_239 + 1 ) ;
F_39 ( V_63 , V_255 , V_78 -> V_78 ) ;
F_39 ( V_63 , V_256 , V_80 -> V_94 ) ;
F_39 ( V_63 , V_257 , V_80 -> V_94 ) ;
F_104 ( V_63 , V_258 ,
V_259 , ! V_249 ,
V_260 , ! V_249 ) ;
F_39 ( V_63 , V_261 , 0 ) ;
F_39 ( V_63 , V_262 , V_263 ) ;
V_215 = V_80 -> V_237 . V_238 . V_215 ;
F_28 ( V_2 , V_264 , V_2 -> V_20 , L_22 ,
V_80 -> V_94 , V_251 , ( T_6 ) V_215 ) ;
for ( V_37 = 0 ; V_37 < V_251 ; ++ V_37 ) {
F_105 ( V_63 , V_265 , V_37 , V_215 ) ;
V_215 += V_247 ;
}
V_253 = F_103 ( V_251 ) ;
V_16 = F_9 ( V_2 , V_266 , V_63 , V_253 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_89;
V_80 -> V_267 [ 0 ] . V_126 = V_268 ;
V_80 -> V_269 = 1 ;
V_237 = F_106 ( V_80 , 0 ) ;
F_107 ( * V_237 ,
V_270 , true ,
V_271 ,
V_272 ,
V_273 , V_249 ,
V_274 , V_249 ) ;
V_80 -> V_242 = 1 ;
F_85 () ;
F_99 ( V_80 , V_237 ) ;
return;
V_89:
F_108 ( V_2 -> V_20 , L_23 ,
V_80 -> V_94 ) ;
}
static void F_109 ( struct V_79 * V_80 )
{
F_7 ( V_63 , V_275 ) ;
F_7 ( V_11 , V_276 ) ;
struct V_1 * V_2 = V_80 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_63 , V_277 ,
V_80 -> V_94 ) ;
V_16 = F_36 ( V_2 , V_278 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_89;
return;
V_89:
F_37 ( V_2 , V_278 , V_275 ,
V_11 , V_15 , V_16 ) ;
}
static void F_110 ( struct V_79 * V_80 )
{
F_32 ( V_80 -> V_2 , & V_80 -> V_237 . V_238 ) ;
}
static inline void F_111 ( struct V_79 * V_80 )
{
unsigned int V_241 ;
T_1 V_3 ;
V_241 = V_80 -> V_242 & V_80 -> V_239 ;
F_112 ( V_3 , V_279 , V_241 ) ;
F_80 ( V_80 -> V_2 , & V_3 ,
V_280 , V_80 -> V_94 ) ;
}
static void F_113 ( struct V_79 * V_80 )
{
unsigned int V_281 = V_80 -> V_242 ;
struct V_282 * V_267 ;
unsigned int V_241 ;
V_240 * V_237 ;
F_17 ( V_80 -> V_242 == V_80 -> V_269 ) ;
do {
V_241 = V_80 -> V_242 & V_80 -> V_239 ;
V_267 = & V_80 -> V_267 [ V_241 ] ;
V_237 = F_106 ( V_80 , V_241 ) ;
++ V_80 -> V_242 ;
if ( V_267 -> V_126 & V_268 ) {
* V_237 = V_267 -> V_283 ;
} else {
F_8 ( V_284 != 1 ) ;
F_114 (
* V_237 ,
V_285 ,
V_267 -> V_126 & V_284 ,
V_286 , V_267 -> V_252 ,
V_287 , V_267 -> V_215 ) ;
}
} while ( V_80 -> V_242 != V_80 -> V_269 );
F_85 () ;
if ( F_115 ( V_80 , V_281 ) ) {
V_237 = F_106 ( V_80 ,
V_281 & V_80 -> V_239 ) ;
F_99 ( V_80 , V_237 ) ;
++ V_80 -> V_288 ;
} else {
F_111 ( V_80 ) ;
}
}
static int F_116 ( struct V_1 * V_2 , T_5 * V_221 )
{
F_7 ( V_63 , V_289 ) ;
F_7 ( V_11 , V_290 ) ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_63 , V_291 ,
V_263 ) ;
F_39 ( V_63 , V_292 ,
V_293 ) ;
F_39 ( V_63 , V_294 ,
V_295 ) ;
V_16 = F_9 ( V_2 , V_296 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_290 )
return - V_7 ;
* V_221 = F_11 ( V_11 , V_297 ) ;
return 0 ;
}
static void F_117 ( struct V_1 * V_2 , T_5 V_221 )
{
F_7 ( V_63 , V_298 ) ;
int V_16 ;
F_39 ( V_63 , V_299 ,
V_221 ) ;
V_16 = F_9 ( V_2 , V_300 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
F_40 ( V_16 != 0 ) ;
}
static int F_118 ( struct V_1 * V_2 , T_5 V_221 )
{
F_7 ( V_301 , V_302 ) ;
F_7 ( V_303 , V_304 ) ;
int V_37 , V_16 ;
F_39 ( V_301 , V_305 ,
V_221 ) ;
F_8 ( F_119 ( V_2 -> V_306 ) !=
V_307 ) ;
for ( V_37 = 0 ; V_37 < F_119 ( V_2 -> V_306 ) ; ++ V_37 )
F_14 ( V_301 ,
V_308 ) [ V_37 ] =
( T_3 ) V_2 -> V_306 [ V_37 ] ;
V_16 = F_9 ( V_2 , V_309 , V_301 ,
sizeof( V_301 ) , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
return V_16 ;
F_39 ( V_303 , V_310 ,
V_221 ) ;
F_8 ( F_119 ( V_2 -> V_311 ) !=
V_312 ) ;
for ( V_37 = 0 ; V_37 < F_119 ( V_2 -> V_311 ) ; ++ V_37 )
F_14 ( V_303 , V_313 ) [ V_37 ] =
V_2 -> V_311 [ V_37 ] ;
return F_9 ( V_2 , V_314 , V_303 ,
sizeof( V_303 ) , NULL , 0 , NULL ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_46 != V_47 )
F_117 ( V_2 , V_14 -> V_46 ) ;
V_14 -> V_46 = V_47 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_28 ( V_2 , V_19 , V_2 -> V_20 , L_24 ) ;
if ( V_14 -> V_46 == V_47 ) {
V_16 = F_116 ( V_2 , & V_14 -> V_46 ) ;
if ( V_16 != 0 )
goto V_89;
}
V_16 = F_118 ( V_2 , V_14 -> V_46 ) ;
if ( V_16 != 0 )
goto V_89;
return;
V_89:
F_10 ( V_2 , V_264 , V_2 -> V_20 , L_25 , V_315 , V_16 ) ;
}
static int F_120 ( struct V_316 * V_317 )
{
return F_19 ( V_317 -> V_2 , & V_317 -> V_318 . V_238 ,
( V_317 -> V_239 + 1 ) *
sizeof( V_240 ) ,
V_39 ) ;
}
static void F_121 ( struct V_316 * V_317 )
{
F_7 ( V_63 ,
F_122 ( V_246 * 8 /
V_247 ) ) ;
F_7 ( V_11 , V_319 ) ;
struct V_77 * V_78 = F_123 ( V_317 ) ;
T_2 V_251 = V_317 -> V_318 . V_238 . V_252 / V_247 ;
struct V_1 * V_2 = V_317 -> V_2 ;
T_2 V_253 , V_15 ;
T_10 V_215 ;
int V_16 ;
int V_37 ;
V_317 -> V_320 = 0 ;
V_317 -> V_321 = 0 ;
F_39 ( V_63 , V_322 , V_317 -> V_239 + 1 ) ;
F_39 ( V_63 , V_323 , V_78 -> V_78 ) ;
F_39 ( V_63 , V_324 , F_124 ( V_317 ) ) ;
F_39 ( V_63 , V_325 ,
F_124 ( V_317 ) ) ;
F_104 ( V_63 , V_326 ,
V_327 , 1 ,
V_328 , 1 ) ;
F_39 ( V_63 , V_329 , 0 ) ;
F_39 ( V_63 , V_330 , V_263 ) ;
V_215 = V_317 -> V_318 . V_238 . V_215 ;
F_28 ( V_2 , V_264 , V_2 -> V_20 , L_26 ,
F_124 ( V_317 ) , V_251 , ( T_6 ) V_215 ) ;
for ( V_37 = 0 ; V_37 < V_251 ; ++ V_37 ) {
F_105 ( V_63 , V_331 , V_37 , V_215 ) ;
V_215 += V_247 ;
}
V_253 = F_122 ( V_251 ) ;
V_16 = F_9 ( V_2 , V_332 , V_63 , V_253 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
F_108 ( V_2 -> V_20 , L_27 ,
F_124 ( V_317 ) ) ;
}
static void F_125 ( struct V_316 * V_317 )
{
F_7 ( V_63 , V_333 ) ;
F_7 ( V_11 , V_334 ) ;
struct V_1 * V_2 = V_317 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_63 , V_335 ,
F_124 ( V_317 ) ) ;
V_16 = F_36 ( V_2 , V_336 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_89;
return;
V_89:
F_37 ( V_2 , V_336 , V_333 ,
V_11 , V_15 , V_16 ) ;
}
static void F_126 ( struct V_316 * V_317 )
{
F_32 ( V_317 -> V_2 , & V_317 -> V_318 . V_238 ) ;
}
static inline void
F_127 ( struct V_316 * V_317 , unsigned int V_82 )
{
struct V_337 * V_338 ;
V_240 * V_318 ;
V_318 = F_128 ( V_317 , V_82 ) ;
V_338 = V_337 ( V_317 , V_82 ) ;
F_129 ( * V_318 ,
V_339 , V_338 -> V_252 ,
V_340 , V_338 -> V_215 ) ;
}
static void F_130 ( struct V_316 * V_317 )
{
struct V_1 * V_2 = V_317 -> V_2 ;
unsigned int V_242 ;
T_1 V_3 ;
V_242 = V_317 -> V_341 & ~ 7 ;
if ( V_317 -> V_342 == V_242 )
return;
do
F_127 (
V_317 ,
V_317 -> V_342 & V_317 -> V_239 ) ;
while ( ++ V_317 -> V_342 != V_242 );
F_85 () ;
F_112 ( V_3 , V_343 ,
V_242 & V_317 -> V_239 ) ;
F_80 ( V_2 , & V_3 , V_344 ,
F_124 ( V_317 ) ) ;
}
static void F_131 ( struct V_316 * V_317 )
{
struct V_77 * V_78 = F_123 ( V_317 ) ;
F_7 ( V_63 , V_345 ) ;
V_240 V_346 ;
F_129 ( V_346 ,
V_347 , V_348 ,
V_349 , V_350 ) ;
F_39 ( V_63 , V_351 , V_78 -> V_78 ) ;
memcpy ( F_14 ( V_63 , V_352 ) , & V_346 . T_6 [ 0 ] ,
sizeof( V_240 ) ) ;
F_132 ( V_78 -> V_2 , V_353 ,
V_63 , sizeof( V_63 ) , 0 ,
V_354 , 0 ) ;
}
static void
V_354 ( struct V_1 * V_2 , unsigned long V_355 ,
int V_16 , T_1 * V_11 ,
T_2 V_356 )
{
}
static int F_133 ( struct V_77 * V_78 )
{
return F_19 ( V_78 -> V_2 , & V_78 -> V_357 . V_238 ,
( V_78 -> V_358 + 1 ) *
sizeof( V_240 ) ,
V_39 ) ;
}
static int F_134 ( struct V_77 * V_78 )
{
F_7 ( V_63 ,
F_135 ( V_359 * 8 /
V_247 ) ) ;
F_7 ( V_11 , V_360 ) ;
T_2 V_251 = V_78 -> V_357 . V_238 . V_252 / V_247 ;
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_13 * V_14 ;
bool V_361 ;
T_2 V_253 , V_15 ;
T_10 V_215 ;
int V_16 ;
int V_37 ;
V_14 = V_2 -> V_14 ;
V_361 =
! ! ( V_14 -> V_21 &
1 << V_362 ) ;
memset ( V_78 -> V_357 . V_238 . V_157 , 0xff , V_78 -> V_357 . V_238 . V_252 ) ;
F_39 ( V_63 , V_363 , V_78 -> V_358 + 1 ) ;
F_39 ( V_63 , V_364 , V_78 -> V_78 ) ;
F_39 ( V_63 , V_365 , V_78 -> V_78 ) ;
F_136 ( V_63 , V_366 ,
V_367 , 1 ,
V_368 , 1 ,
V_369 , 1 ,
V_370 , ! V_361 ) ;
F_39 ( V_63 , V_371 ,
V_372 ) ;
F_39 ( V_63 , V_373 , 0 ) ;
F_39 ( V_63 , V_374 , 0 ) ;
F_39 ( V_63 , V_375 ,
V_376 ) ;
F_39 ( V_63 , V_377 , 0 ) ;
V_215 = V_78 -> V_357 . V_238 . V_215 ;
for ( V_37 = 0 ; V_37 < V_251 ; ++ V_37 ) {
F_105 ( V_63 , V_378 , V_37 , V_215 ) ;
V_215 += V_247 ;
}
V_253 = F_135 ( V_251 ) ;
V_16 = F_9 ( V_2 , V_379 , V_63 , V_253 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
return V_16 ;
}
static void F_137 ( struct V_77 * V_78 )
{
F_7 ( V_63 , V_380 ) ;
F_7 ( V_11 , V_381 ) ;
struct V_1 * V_2 = V_78 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_39 ( V_63 , V_382 , V_78 -> V_78 ) ;
V_16 = F_36 ( V_2 , V_383 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_89;
return;
V_89:
F_37 ( V_2 , V_383 , V_380 ,
V_11 , V_15 , V_16 ) ;
}
static void F_138 ( struct V_77 * V_78 )
{
F_32 ( V_78 -> V_2 , & V_78 -> V_357 . V_238 ) ;
}
static void F_139 ( struct V_316 * V_317 ,
unsigned int V_384 )
{
struct V_1 * V_2 = V_317 -> V_2 ;
F_140 ( V_2 , V_264 , V_2 -> V_20 ,
L_28 ,
F_124 ( V_317 ) , V_384 ) ;
F_141 ( V_2 , V_385 ) ;
}
static void
F_142 ( struct V_316 * V_317 ,
unsigned int V_386 , unsigned int V_387 )
{
unsigned int V_388 = ( V_386 - V_387 ) & V_317 -> V_239 ;
struct V_1 * V_2 = V_317 -> V_2 ;
F_140 ( V_2 , V_264 , V_2 -> V_20 ,
L_29 ,
V_388 , V_386 , V_387 ) ;
F_141 ( V_2 , V_385 ) ;
}
static void F_143 ( struct V_316 * V_317 )
{
unsigned int V_389 ;
F_28 ( V_317 -> V_2 , V_264 , V_317 -> V_2 -> V_20 ,
L_30 ,
V_317 -> V_320 ) ;
V_389 = V_317 -> V_390 & V_317 -> V_239 ;
F_144 ( V_317 , V_389 , V_317 -> V_320 ,
0 , V_391 ) ;
V_317 -> V_390 += V_317 -> V_320 ;
V_317 -> V_320 = 0 ;
V_317 -> V_321 = 0 ;
++ F_123 ( V_317 ) -> V_392 ;
}
static int F_145 ( struct V_77 * V_78 ,
const V_240 * V_346 )
{
unsigned int V_177 , V_393 , V_384 , V_394 ;
unsigned int V_395 , V_396 , V_37 ;
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_316 * V_317 ;
bool V_397 ;
T_11 V_126 = 0 ;
if ( F_146 ( F_93 ( V_2 -> V_398 ) ) )
return 0 ;
V_177 = F_147 ( * V_346 , V_399 ) ;
V_393 = F_147 ( * V_346 , V_400 ) ;
V_384 = F_147 ( * V_346 , V_401 ) ;
V_394 = F_147 ( * V_346 , V_402 ) ;
V_397 = F_147 ( * V_346 , V_403 ) ;
if ( F_147 ( * V_346 , V_404 ) )
F_108 ( V_2 -> V_20 , L_31
V_405 L_21 ,
F_148 ( * V_346 ) ) ;
V_317 = F_149 ( V_78 ) ;
if ( F_146 ( V_384 != F_124 ( V_317 ) ) )
F_139 ( V_317 , V_384 ) ;
V_395 = ( ( V_393 - V_317 -> V_390 ) &
( ( 1 << V_406 ) - 1 ) ) ;
if ( V_395 != V_317 -> V_320 + 1 ) {
struct V_13 * V_14 = V_2 -> V_14 ;
if ( F_146 ( V_395 == V_317 -> V_320 ) ) {
if ( V_317 -> V_320 == 0 || V_177 != 0 )
F_108 ( V_2 -> V_20 ,
L_32
V_405 L_21 ,
V_317 -> V_320 ,
F_148 ( * V_346 ) ) ;
F_143 ( V_317 ) ;
return 0 ;
}
if ( ! ( V_14 -> V_21 &
( 1 << V_362 ) ) ||
V_317 -> V_320 != 0 || V_397 ) {
F_142 (
V_317 , V_393 ,
( V_317 -> V_390 +
V_317 -> V_320 + 1 ) &
( ( 1 << V_406 ) - 1 ) ) ;
return 0 ;
}
V_317 -> V_320 = 1 ;
V_317 -> V_321 = 0 ;
V_396 = V_395 ;
++ V_78 -> V_407 ;
V_78 -> V_408 += V_396 ;
V_126 |= V_409 ;
} else {
++ V_317 -> V_320 ;
V_317 -> V_321 += V_177 ;
if ( V_397 )
return 0 ;
V_396 = 1 ;
}
if ( F_146 ( F_147 ( * V_346 , V_410 ) ) )
V_126 |= V_391 ;
if ( F_146 ( F_147 ( * V_346 , V_411 ) ) ) {
V_78 -> V_412 += V_396 ;
} else if ( F_146 ( F_147 ( * V_346 ,
V_413 ) ) ) {
V_78 -> V_414 += V_396 ;
} else if ( V_394 == V_415 ||
V_394 == V_416 ) {
V_126 |= V_417 ;
}
if ( V_394 == V_415 )
V_126 |= V_418 ;
V_78 -> V_419 += 2 * V_396 ;
for ( V_37 = 0 ; V_37 < V_396 ; V_37 ++ ) {
F_144 ( V_317 ,
V_317 -> V_390 & V_317 -> V_239 ,
V_317 -> V_320 , V_317 -> V_321 ,
V_126 ) ;
V_317 -> V_390 += V_317 -> V_320 ;
}
V_317 -> V_320 = 0 ;
V_317 -> V_321 = 0 ;
return V_396 ;
}
static int
F_150 ( struct V_77 * V_78 , V_240 * V_346 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_79 * V_80 ;
unsigned int V_420 ;
unsigned int V_421 ;
int V_422 = 0 ;
if ( F_146 ( F_93 ( V_2 -> V_398 ) ) )
return 0 ;
if ( F_146 ( F_147 ( * V_346 , V_423 ) ) )
return 0 ;
V_420 = F_147 ( * V_346 , V_424 ) ;
V_421 = F_147 ( * V_346 , V_425 ) ;
V_80 = F_151 ( V_78 ,
V_421 % V_119 ) ;
V_422 = ( ( V_420 + 1 - V_80 -> V_426 ) &
V_80 -> V_239 ) ;
F_152 ( V_80 , V_420 & V_80 -> V_239 ) ;
return V_422 ;
}
static void
F_153 ( struct V_77 * V_78 , V_240 * V_346 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
int V_427 ;
V_427 = F_147 ( * V_346 , V_428 ) ;
switch ( V_427 ) {
case V_429 :
case V_430 :
break;
case V_431 :
break;
default:
F_10 ( V_2 , V_264 , V_2 -> V_20 ,
L_33
L_34 V_405 L_35 ,
V_78 -> V_78 , V_427 ,
F_148 ( * V_346 ) ) ;
}
}
static void F_154 ( struct V_77 * V_78 ,
V_240 * V_346 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
T_5 V_427 ;
V_427 = F_147 ( * V_346 , V_432 ) ;
switch ( V_427 ) {
case V_433 :
V_78 -> V_434 = F_91 () ;
break;
case V_350 :
F_155 ( & V_78 -> V_317 , true ) ;
break;
default:
F_10 ( V_2 , V_264 , V_2 -> V_20 ,
L_36
L_34 V_405 L_35 ,
V_78 -> V_78 , ( unsigned ) V_427 ,
F_148 ( * V_346 ) ) ;
}
}
static int F_156 ( struct V_77 * V_78 , int V_435 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
V_240 V_346 , * V_436 ;
unsigned int V_437 ;
int V_438 ;
int V_422 = 0 ;
int V_439 = 0 ;
V_437 = V_78 -> V_440 ;
for (; ; ) {
V_436 = F_157 ( V_78 , V_437 ) ;
V_346 = * V_436 ;
if ( ! F_158 ( & V_346 ) )
break;
F_159 ( * V_436 ) ;
++ V_437 ;
V_438 = F_147 ( V_346 , V_347 ) ;
F_90 ( V_2 , V_19 , V_2 -> V_20 ,
L_37 V_405 L_21 ,
V_78 -> V_78 , F_148 ( V_346 ) ) ;
switch ( V_438 ) {
case V_441 :
F_160 ( V_78 , & V_346 ) ;
break;
case V_442 :
V_439 += F_145 ( V_78 , & V_346 ) ;
if ( V_439 >= V_435 ) {
V_439 = V_435 ;
goto V_443;
}
break;
case V_444 :
V_422 += F_150 ( V_78 , & V_346 ) ;
if ( V_422 > V_2 -> V_445 ) {
V_439 = V_435 ;
goto V_443;
} else if ( ++ V_439 == V_435 ) {
goto V_443;
}
break;
case V_446 :
F_153 ( V_78 , & V_346 ) ;
if ( ++ V_439 == V_435 )
goto V_443;
break;
case V_348 :
F_154 ( V_78 , & V_346 ) ;
break;
default:
F_10 ( V_2 , V_264 , V_2 -> V_20 ,
L_38
L_34 V_405 L_35 ,
V_78 -> V_78 , V_438 ,
F_148 ( V_346 ) ) ;
}
}
V_443:
V_78 -> V_440 = V_437 ;
return V_439 ;
}
static void F_161 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
T_1 V_447 ;
if ( F_78 ( V_2 ) ) {
F_8 ( V_448 <
( 1 << V_449 ) ) ;
F_8 ( V_359 >
( 1 << 2 * V_449 ) ) ;
F_81 ( V_447 , V_450 ,
V_451 ,
V_452 ,
( V_78 -> V_440 &
V_78 -> V_358 ) >>
V_449 ) ;
F_80 ( V_2 , & V_447 , V_201 ,
V_78 -> V_78 ) ;
F_81 ( V_447 , V_450 ,
V_453 ,
V_452 ,
V_78 -> V_440 &
( ( 1 << V_449 ) - 1 ) ) ;
F_80 ( V_2 , & V_447 , V_201 ,
V_78 -> V_78 ) ;
} else {
F_112 ( V_447 , V_454 ,
V_78 -> V_440 &
V_78 -> V_358 ) ;
F_80 ( V_2 , & V_447 , V_455 , V_78 -> V_78 ) ;
}
}
static void F_162 ( struct V_77 * V_78 )
{
F_7 ( V_63 , V_345 ) ;
struct V_1 * V_2 = V_78 -> V_2 ;
V_240 V_346 ;
int V_16 ;
F_129 ( V_346 ,
V_347 , V_348 ,
V_349 , V_433 ) ;
F_39 ( V_63 , V_351 , V_78 -> V_78 ) ;
memcpy ( F_14 ( V_63 , V_352 ) , & V_346 . T_6 [ 0 ] ,
sizeof( V_240 ) ) ;
V_16 = F_9 ( V_2 , V_353 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
if ( V_16 != 0 )
goto V_89;
return;
V_89:
F_40 ( true ) ;
F_10 ( V_2 , V_264 , V_2 -> V_20 , L_25 , V_315 , V_16 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
if ( F_164 ( & V_2 -> V_456 ) )
F_165 ( & V_2 -> V_457 ) ;
F_40 ( F_166 ( & V_2 -> V_456 ) < 0 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_316 * V_317 ;
int V_458 ;
if ( V_14 -> V_124 ) {
F_168 ( & V_2 -> V_456 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_459 != V_460 ) {
F_44 (channel, efx) {
F_169 (rx_queue, channel)
F_125 ( V_317 ) ;
F_45 (tx_queue, channel)
F_109 ( V_80 ) ;
}
F_170 ( V_2 -> V_457 ,
F_166 ( & V_2 -> V_456 ) == 0 ,
F_171 ( V_461 ) ) ;
V_458 = F_166 ( & V_2 -> V_456 ) ;
if ( V_458 ) {
F_10 ( V_2 , V_264 , V_2 -> V_20 , L_39 ,
V_458 ) ;
return - V_462 ;
}
}
return 0 ;
}
static bool F_172 ( const struct V_463 * V_464 ,
const struct V_463 * V_465 )
{
if ( ( V_464 -> V_466 ^ V_465 -> V_466 ) |
( ( V_464 -> V_126 ^ V_465 -> V_126 ) &
( V_467 | V_468 ) ) )
return false ;
return memcmp ( & V_464 -> V_469 , & V_465 -> V_469 ,
sizeof( struct V_463 ) -
F_173 ( struct V_463 , V_469 ) ) == 0 ;
}
static unsigned int F_174 ( const struct V_463 * V_470 )
{
F_8 ( F_173 ( struct V_463 , V_469 ) & 3 ) ;
return F_175 ( ( const T_5 * ) & V_470 -> V_469 ,
( sizeof( struct V_463 ) -
F_173 ( struct V_463 , V_469 ) ) / 4 ,
0 ) ;
}
static bool F_176 ( const struct V_463 * V_470 )
{
if ( V_470 -> V_466 & V_471 &&
! F_177 ( V_470 -> V_472 ) )
return true ;
if ( ( V_470 -> V_466 &
( V_473 | V_474 ) ) ==
( V_473 | V_474 ) ) {
if ( V_470 -> V_475 == F_178 ( V_476 ) &&
! F_179 ( V_470 -> V_477 [ 0 ] ) )
return true ;
if ( V_470 -> V_475 == F_178 ( V_478 ) &&
( ( const T_3 * ) V_470 -> V_477 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_463 *
F_180 ( const struct V_479 * V_480 ,
unsigned int V_481 )
{
return (struct V_463 * ) ( V_480 -> V_482 [ V_481 ] . V_470 &
~ V_483 ) ;
}
static unsigned int
F_181 ( const struct V_479 * V_480 ,
unsigned int V_481 )
{
return V_480 -> V_482 [ V_481 ] . V_470 & V_483 ;
}
static void
F_182 ( struct V_479 * V_480 ,
unsigned int V_481 ,
const struct V_463 * V_470 ,
unsigned int V_126 )
{
V_480 -> V_482 [ V_481 ] . V_470 = ( unsigned long ) V_470 | V_126 ;
}
static void F_183 ( struct V_1 * V_2 ,
const struct V_463 * V_470 ,
T_1 * V_63 , T_6 V_484 ,
bool V_485 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
memset ( V_63 , 0 , V_486 ) ;
if ( V_485 ) {
F_39 ( V_63 , V_487 ,
V_488 ) ;
F_184 ( V_63 , V_489 , V_484 ) ;
} else {
T_5 V_490 = 0 ;
F_39 ( V_63 , V_487 ,
F_176 ( V_470 ) ?
V_491 :
V_492 ) ;
if ( V_470 -> V_466 & V_493 )
V_490 |=
F_177 ( V_470 -> V_472 ) ?
1 << V_494 :
1 << V_495 ;
#define F_185 ( T_12 , T_13 , T_14 ) \
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
F_185 ( V_496 , V_497 , V_498 ) ;
F_185 ( V_499 , V_477 , V_500 ) ;
F_185 ( V_501 , V_502 , V_503 ) ;
F_185 ( V_504 , V_505 , V_506 ) ;
F_185 ( V_507 , V_472 , V_508 ) ;
F_185 ( V_509 , V_510 , V_511 ) ;
F_185 ( V_512 , V_475 , V_512 ) ;
F_185 ( V_513 , V_514 , V_515 ) ;
F_185 ( V_516 , V_469 , V_517 ) ;
F_185 ( V_518 , V_519 , V_518 ) ;
#undef F_185
F_39 ( V_63 , V_520 ,
V_490 ) ;
}
F_39 ( V_63 , V_521 , V_263 ) ;
F_39 ( V_63 , V_522 ,
V_470 -> V_523 == V_524 ?
V_525 :
V_526 ) ;
F_39 ( V_63 , V_527 ,
V_528 ) ;
F_39 ( V_63 , V_529 ,
V_470 -> V_523 == V_524 ?
0 : V_470 -> V_523 ) ;
F_39 ( V_63 , V_530 ,
( V_470 -> V_126 & V_531 ) ?
V_532 :
V_533 ) ;
if ( V_470 -> V_126 & V_531 )
F_39 ( V_63 , V_534 ,
V_470 -> V_535 !=
V_536 ?
V_470 -> V_535 : V_14 -> V_46 ) ;
}
static int F_186 ( struct V_1 * V_2 ,
const struct V_463 * V_470 ,
T_6 * V_484 , bool V_485 )
{
F_7 ( V_63 , V_486 ) ;
F_7 ( V_11 , V_537 ) ;
int V_16 ;
F_183 ( V_2 , V_470 , V_63 , * V_484 , V_485 ) ;
V_16 = F_9 ( V_2 , V_538 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_16 == 0 )
* V_484 = F_187 ( V_11 , V_539 ) ;
if ( V_16 == - V_540 )
V_16 = - V_541 ;
return V_16 ;
}
static int F_188 ( struct V_479 * V_480 ,
enum V_542 V_466 )
{
unsigned int V_543 ;
for ( V_543 = 0 ;
V_543 < V_480 -> V_544 ;
V_543 ++ )
if ( V_480 -> V_545 [ V_543 ] == V_466 )
return V_543 ;
return - V_546 ;
}
static T_15 F_189 ( struct V_1 * V_2 ,
struct V_463 * V_470 ,
bool V_547 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
F_67 ( V_549 , V_550 ) ;
struct V_463 * V_551 ;
unsigned int V_543 , V_552 ;
unsigned int V_553 ;
bool V_485 = false ;
int V_554 = - 1 ;
F_190 ( V_555 ) ;
bool V_556 ;
T_15 V_16 ;
if ( ( V_470 -> V_126 & ( V_467 | V_468 ) ) !=
V_467 )
return - V_137 ;
V_16 = F_188 ( V_480 , V_470 -> V_466 ) ;
if ( V_16 < 0 )
return V_16 ;
V_543 = V_16 ;
V_552 = F_174 ( V_470 ) ;
V_556 = F_191 ( V_470 ) ;
if ( V_556 )
F_192 ( V_549 , V_550 ) ;
for (; ; ) {
unsigned int V_557 = 1 ;
unsigned int V_37 ;
F_193 ( & V_2 -> V_558 ) ;
for (; ; ) {
V_37 = ( V_552 + V_557 ) & ( V_559 - 1 ) ;
V_551 = F_180 ( V_480 , V_37 ) ;
if ( ! V_551 ) {
if ( V_554 < 0 )
V_554 = V_37 ;
} else if ( F_172 ( V_470 , V_551 ) ) {
if ( V_480 -> V_482 [ V_37 ] . V_470 &
V_560 )
break;
if ( V_470 -> V_561 < V_551 -> V_561 &&
V_470 -> V_561 != V_562 ) {
V_16 = - V_563 ;
goto V_564;
}
if ( ! V_556 ) {
if ( V_470 -> V_561 ==
V_551 -> V_561 &&
! V_547 ) {
V_16 = - V_565 ;
goto V_564;
}
V_554 = V_37 ;
goto V_566;
} else if ( V_470 -> V_561 >
V_551 -> V_561 ||
( V_470 -> V_561 ==
V_551 -> V_561 &&
V_547 ) ) {
if ( V_554 < 0 )
V_554 = V_37 ;
else
F_194 ( V_557 , V_549 ) ;
}
}
if ( V_557 == V_550 ) {
if ( V_554 < 0 ) {
V_16 = - V_541 ;
goto V_564;
}
goto V_566;
}
++ V_557 ;
}
F_195 ( & V_480 -> V_567 , & V_555 , V_568 ) ;
F_196 ( & V_2 -> V_558 ) ;
F_197 () ;
}
V_566:
V_551 = F_180 ( V_480 , V_554 ) ;
if ( V_551 ) {
if ( V_470 -> V_561 == V_562 &&
V_551 -> V_561 >= V_562 ) {
if ( V_551 -> V_561 > V_562 )
V_551 -> V_126 |= V_569 ;
V_480 -> V_482 [ V_554 ] . V_470 &=
~ V_570 ;
V_16 = V_554 ;
goto V_564;
}
V_485 = true ;
V_553 = F_181 ( V_480 , V_554 ) ;
} else {
V_551 = F_198 ( sizeof( * V_470 ) , V_571 ) ;
if ( ! V_551 ) {
V_16 = - V_40 ;
goto V_564;
}
* V_551 = * V_470 ;
V_553 = 0 ;
}
F_182 ( V_480 , V_554 , V_551 ,
V_553 | V_560 ) ;
if ( V_556 ) {
unsigned int V_557 , V_37 ;
for ( V_557 = 0 ; V_557 < V_550 ; V_557 ++ ) {
V_37 = ( V_552 + V_557 ) & ( V_559 - 1 ) ;
if ( F_199 ( V_557 , V_549 ) )
V_480 -> V_482 [ V_37 ] . V_470 |=
V_560 ;
}
}
F_196 ( & V_2 -> V_558 ) ;
V_16 = F_186 ( V_2 , V_470 , & V_480 -> V_482 [ V_554 ] . V_484 ,
V_485 ) ;
F_193 ( & V_2 -> V_558 ) ;
if ( V_16 == 0 ) {
if ( V_485 ) {
if ( V_551 -> V_561 == V_562 )
V_551 -> V_126 |=
V_569 ;
V_551 -> V_561 = V_470 -> V_561 ;
V_551 -> V_126 &= V_569 ;
V_551 -> V_126 |= V_470 -> V_126 ;
V_551 -> V_535 = V_470 -> V_535 ;
V_551 -> V_523 = V_470 -> V_523 ;
}
} else if ( ! V_485 ) {
F_33 ( V_551 ) ;
V_551 = NULL ;
}
F_182 ( V_480 , V_554 , V_551 , V_553 ) ;
if ( V_556 ) {
F_7 ( V_63 , V_486 ) ;
unsigned int V_557 , V_37 ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
for ( V_557 = 0 ; V_557 < V_550 ; V_557 ++ ) {
if ( ! F_199 ( V_557 , V_549 ) )
continue;
V_37 = ( V_552 + V_557 ) & ( V_559 - 1 ) ;
V_551 = F_180 ( V_480 , V_37 ) ;
V_553 = F_181 ( V_480 , V_37 ) ;
if ( V_16 == 0 ) {
F_196 ( & V_2 -> V_558 ) ;
F_39 ( V_63 , V_487 ,
V_572 ) ;
F_184 ( V_63 , V_489 ,
V_480 -> V_482 [ V_37 ] . V_484 ) ;
V_16 = F_9 ( V_2 , V_538 ,
V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
F_193 ( & V_2 -> V_558 ) ;
}
if ( V_16 == 0 ) {
F_33 ( V_551 ) ;
V_551 = NULL ;
V_553 = 0 ;
} else {
V_553 &= ~ V_560 ;
}
F_182 ( V_480 , V_37 , V_551 ,
V_553 ) ;
}
}
if ( V_16 == 0 )
V_16 = V_543 * V_559 + V_554 ;
F_200 ( & V_480 -> V_567 ) ;
V_564:
F_196 ( & V_2 -> V_558 ) ;
F_201 ( & V_480 -> V_567 , & V_555 ) ;
return V_16 ;
}
static void F_202 ( struct V_1 * V_2 )
{
}
static int F_203 ( struct V_1 * V_2 ,
unsigned int V_573 ,
T_5 V_574 , bool V_575 )
{
unsigned int V_481 = V_574 % V_559 ;
struct V_479 * V_480 = V_2 -> V_548 ;
F_7 ( V_63 ,
V_576 +
V_577 ) ;
struct V_463 * V_470 ;
F_190 ( V_555 ) ;
int V_16 ;
for (; ; ) {
F_193 ( & V_2 -> V_558 ) ;
if ( ! ( V_480 -> V_482 [ V_481 ] . V_470 &
V_560 ) )
break;
F_195 ( & V_480 -> V_567 , & V_555 , V_568 ) ;
F_196 ( & V_2 -> V_558 ) ;
F_197 () ;
}
V_470 = F_180 ( V_480 , V_481 ) ;
if ( ! V_470 ||
( ! V_575 &&
F_188 ( V_480 , V_470 -> V_466 ) !=
V_574 / V_559 ) ) {
V_16 = - V_60 ;
goto V_564;
}
if ( V_470 -> V_126 & V_569 &&
V_573 == ( 1U << V_562 ) ) {
V_470 -> V_126 &= ~ V_569 ;
V_480 -> V_482 [ V_481 ] . V_470 &= ~ V_570 ;
V_16 = 0 ;
goto V_564;
}
if ( ! ( V_573 & ( 1U << V_470 -> V_561 ) ) ) {
V_16 = - V_60 ;
goto V_564;
}
V_480 -> V_482 [ V_481 ] . V_470 |= V_560 ;
F_196 ( & V_2 -> V_558 ) ;
if ( V_470 -> V_126 & V_569 ) {
struct V_463 V_578 = * V_470 ;
V_578 . V_561 = V_562 ;
V_578 . V_126 = ( V_467 |
V_531 ) ;
V_578 . V_523 = 0 ;
V_578 . V_535 = V_536 ;
V_16 = F_186 ( V_2 , & V_578 ,
& V_480 -> V_482 [ V_481 ] . V_484 ,
true ) ;
F_193 ( & V_2 -> V_558 ) ;
if ( V_16 == 0 )
* V_470 = V_578 ;
} else {
F_39 ( V_63 , V_487 ,
F_176 ( V_470 ) ?
V_579 :
V_572 ) ;
F_184 ( V_63 , V_489 ,
V_480 -> V_482 [ V_481 ] . V_484 ) ;
V_16 = F_9 ( V_2 , V_538 ,
V_63 , sizeof( V_63 ) , NULL , 0 , NULL ) ;
F_193 ( & V_2 -> V_558 ) ;
if ( V_16 == 0 ) {
F_33 ( V_470 ) ;
F_182 ( V_480 , V_481 , NULL , 0 ) ;
}
}
V_480 -> V_482 [ V_481 ] . V_470 &= ~ V_560 ;
F_200 ( & V_480 -> V_567 ) ;
V_564:
F_196 ( & V_2 -> V_558 ) ;
F_201 ( & V_480 -> V_567 , & V_555 ) ;
return V_16 ;
}
static int F_204 ( struct V_1 * V_2 ,
enum V_580 V_561 ,
T_5 V_574 )
{
return F_203 ( V_2 , 1U << V_561 ,
V_574 , false ) ;
}
static int F_205 ( struct V_1 * V_2 ,
enum V_580 V_561 ,
T_5 V_574 , struct V_463 * V_470 )
{
unsigned int V_481 = V_574 % V_559 ;
struct V_479 * V_480 = V_2 -> V_548 ;
const struct V_463 * V_551 ;
int V_16 ;
F_193 ( & V_2 -> V_558 ) ;
V_551 = F_180 ( V_480 , V_481 ) ;
if ( V_551 && V_551 -> V_561 == V_561 &&
F_188 ( V_480 , V_551 -> V_466 ) ==
V_574 / V_559 ) {
* V_470 = * V_551 ;
V_16 = 0 ;
} else {
V_16 = - V_60 ;
}
F_196 ( & V_2 -> V_558 ) ;
return V_16 ;
}
static int F_206 ( struct V_1 * V_2 ,
enum V_580 V_561 )
{
unsigned int V_573 ;
unsigned int V_37 ;
int V_16 ;
V_573 = ( ( ( 1U << ( V_561 + 1 ) ) - 1 ) &
~ ( 1U << V_562 ) ) ;
for ( V_37 = 0 ; V_37 < V_559 ; V_37 ++ ) {
V_16 = F_203 ( V_2 , V_573 ,
V_37 , true ) ;
if ( V_16 && V_16 != - V_60 )
return V_16 ;
}
return 0 ;
}
static T_5 F_207 ( struct V_1 * V_2 ,
enum V_580 V_561 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
unsigned int V_481 ;
T_15 V_581 = 0 ;
F_193 ( & V_2 -> V_558 ) ;
for ( V_481 = 0 ; V_481 < V_559 ; V_481 ++ ) {
if ( V_480 -> V_482 [ V_481 ] . V_470 &&
F_180 ( V_480 , V_481 ) -> V_561 ==
V_561 )
++ V_581 ;
}
F_196 ( & V_2 -> V_558 ) ;
return V_581 ;
}
static T_5 F_208 ( struct V_1 * V_2 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
return V_480 -> V_544 * V_559 ;
}
static T_15 F_209 ( struct V_1 * V_2 ,
enum V_580 V_561 ,
T_5 * V_238 , T_5 V_582 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
struct V_463 * V_470 ;
unsigned int V_481 ;
T_15 V_581 = 0 ;
F_193 ( & V_2 -> V_558 ) ;
for ( V_481 = 0 ; V_481 < V_559 ; V_481 ++ ) {
V_470 = F_180 ( V_480 , V_481 ) ;
if ( V_470 && V_470 -> V_561 == V_561 ) {
if ( V_581 == V_582 ) {
V_581 = - V_583 ;
break;
}
V_238 [ V_581 ++ ] = ( F_188 (
V_480 , V_470 -> V_466 ) *
V_559 +
V_481 ) ;
}
}
F_196 ( & V_2 -> V_558 ) ;
return V_581 ;
}
static T_15 F_210 ( struct V_1 * V_2 ,
struct V_463 * V_470 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
F_7 ( V_63 , V_486 ) ;
struct V_463 * V_551 ;
unsigned int V_552 , V_37 , V_557 = 1 ;
bool V_485 = false ;
int V_554 = - 1 ;
T_6 V_355 ;
T_15 V_16 ;
F_211 ( V_470 -> V_126 !=
( V_467 | V_584 ) ) ;
F_211 ( V_470 -> V_561 != V_585 ) ;
F_211 ( F_191 ( V_470 ) ) ;
V_552 = F_174 ( V_470 ) ;
F_193 ( & V_2 -> V_558 ) ;
for (; ; ) {
V_37 = ( V_552 + V_557 ) & ( V_559 - 1 ) ;
V_551 = F_180 ( V_480 , V_37 ) ;
if ( ! V_551 ) {
if ( V_554 < 0 )
V_554 = V_37 ;
} else if ( F_172 ( V_470 , V_551 ) ) {
if ( V_480 -> V_482 [ V_37 ] . V_470 & V_560 ) {
V_16 = - V_541 ;
goto V_586;
}
if ( V_470 -> V_561 < V_551 -> V_561 ) {
V_16 = - V_563 ;
goto V_586;
}
V_554 = V_37 ;
break;
}
if ( V_557 == V_550 ) {
if ( V_554 < 0 ) {
V_16 = - V_541 ;
goto V_586;
}
break;
}
++ V_557 ;
}
V_551 = F_180 ( V_480 , V_554 ) ;
if ( V_551 ) {
V_485 = true ;
} else {
V_551 = F_198 ( sizeof( * V_470 ) , V_571 ) ;
if ( ! V_551 ) {
V_16 = - V_40 ;
goto V_586;
}
* V_551 = * V_470 ;
}
F_182 ( V_480 , V_554 , V_551 ,
V_560 ) ;
F_196 ( & V_2 -> V_558 ) ;
V_355 = V_485 << 31 | V_554 << 16 | V_470 -> V_523 ;
F_183 ( V_2 , V_470 , V_63 ,
V_480 -> V_482 [ V_554 ] . V_484 , V_485 ) ;
F_132 ( V_2 , V_538 , V_63 , sizeof( V_63 ) ,
V_537 ,
V_587 , V_355 ) ;
return V_554 ;
V_586:
F_196 ( & V_2 -> V_558 ) ;
return V_16 ;
}
static void
V_587 ( struct V_1 * V_2 , unsigned long V_355 ,
int V_16 , T_1 * V_11 ,
T_2 V_356 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
unsigned int V_554 , V_523 ;
struct V_463 * V_470 ;
bool V_485 ;
V_485 = V_355 >> 31 ;
V_554 = ( V_355 >> 16 ) & ( V_559 - 1 ) ;
V_523 = V_355 & 0xffff ;
F_193 ( & V_2 -> V_558 ) ;
V_470 = F_180 ( V_480 , V_554 ) ;
if ( V_16 == 0 ) {
V_480 -> V_482 [ V_554 ] . V_484 =
F_187 ( V_11 , V_539 ) ;
if ( V_485 )
V_470 -> V_523 = V_523 ;
} else if ( ! V_485 ) {
F_33 ( V_470 ) ;
V_470 = NULL ;
}
F_182 ( V_480 , V_554 , V_470 , 0 ) ;
F_196 ( & V_2 -> V_558 ) ;
F_200 ( & V_480 -> V_567 ) ;
}
static bool F_212 ( struct V_1 * V_2 , T_5 V_588 ,
unsigned int V_481 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
struct V_463 * V_470 =
F_180 ( V_480 , V_481 ) ;
F_7 ( V_63 ,
V_576 +
V_577 ) ;
if ( ! V_470 ||
( V_480 -> V_482 [ V_481 ] . V_470 & V_560 ) ||
V_470 -> V_561 != V_585 ||
! F_213 ( V_2 -> V_20 , V_470 -> V_523 ,
V_588 , V_481 ) )
return false ;
F_39 ( V_63 , V_487 ,
V_579 ) ;
F_184 ( V_63 , V_489 ,
V_480 -> V_482 [ V_481 ] . V_484 ) ;
if ( F_132 ( V_2 , V_538 , V_63 , sizeof( V_63 ) , 0 ,
V_589 , V_481 ) )
return false ;
V_480 -> V_482 [ V_481 ] . V_470 |= V_560 ;
return true ;
}
static void
V_589 ( struct V_1 * V_2 ,
unsigned long V_481 ,
int V_16 , T_1 * V_11 ,
T_2 V_356 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
struct V_463 * V_470 =
F_180 ( V_480 , V_481 ) ;
F_193 ( & V_2 -> V_558 ) ;
if ( V_16 == 0 ) {
F_33 ( V_470 ) ;
F_182 ( V_480 , V_481 , NULL , 0 ) ;
}
V_480 -> V_482 [ V_481 ] . V_470 &= ~ V_560 ;
F_200 ( & V_480 -> V_567 ) ;
F_196 ( & V_2 -> V_558 ) ;
}
static int F_214 ( T_5 V_590 )
{
int V_466 = 0 ;
#define F_215 ( T_12 , T_14 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_215 ( V_591 , V_592 ) ;
F_215 ( V_591 , V_593 ) ;
F_215 ( V_496 , V_498 ) ;
F_215 ( V_499 , V_500 ) ;
F_215 ( V_501 , V_503 ) ;
F_215 ( V_504 , V_506 ) ;
F_215 ( V_507 , V_508 ) ;
F_215 ( V_509 , V_511 ) ;
F_215 ( V_512 , V_512 ) ;
F_215 ( V_513 , V_515 ) ;
F_215 ( V_516 , V_517 ) ;
F_215 ( V_518 , V_518 ) ;
#undef F_215
if ( V_590 )
return - V_137 ;
return V_466 ;
}
static int F_216 ( struct V_1 * V_2 )
{
F_7 ( V_63 , V_594 ) ;
F_7 ( V_11 , V_595 ) ;
unsigned int V_596 , V_597 ;
struct V_479 * V_480 ;
T_2 V_15 ;
int V_16 ;
V_480 = F_18 ( sizeof( * V_480 ) , V_39 ) ;
if ( ! V_480 )
return - V_40 ;
F_39 ( V_63 , V_598 ,
V_599 ) ;
V_16 = F_9 ( V_2 , V_600 ,
V_63 , sizeof( V_63 ) , V_11 , sizeof( V_11 ) ,
& V_15 ) ;
if ( V_16 )
goto V_89;
V_597 = F_217 (
V_15 , V_601 ) ;
V_480 -> V_544 = 0 ;
for ( V_596 = 0 ; V_596 < V_597 ; V_596 ++ ) {
T_5 V_590 =
F_218 (
V_11 ,
V_601 ,
V_596 ) ;
V_16 = F_214 ( V_590 ) ;
if ( V_16 < 0 ) {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_40 ,
V_315 , V_590 , V_596 ) ;
} else {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_41 ,
V_315 , V_590 , V_596 ,
V_16 , V_480 -> V_544 ) ;
V_480 -> V_545 [ V_480 -> V_544 ++ ] = V_16 ;
}
}
V_480 -> V_482 = F_219 ( V_559 * sizeof( * V_480 -> V_482 ) ) ;
if ( ! V_480 -> V_482 ) {
V_16 = - V_40 ;
goto V_89;
}
V_2 -> V_548 = V_480 ;
F_220 ( & V_480 -> V_567 ) ;
return 0 ;
V_89:
F_33 ( V_480 ) ;
return V_16 ;
}
static void F_221 ( struct V_1 * V_2 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_463 * V_470 ;
unsigned int V_481 ;
bool V_602 = false ;
int V_16 ;
if ( ! V_14 -> V_125 )
return;
F_193 ( & V_2 -> V_558 ) ;
for ( V_481 = 0 ; V_481 < V_559 ; V_481 ++ ) {
V_470 = F_180 ( V_480 , V_481 ) ;
if ( ! V_470 )
continue;
V_480 -> V_482 [ V_481 ] . V_470 |= V_560 ;
F_196 ( & V_2 -> V_558 ) ;
V_16 = F_186 ( V_2 , V_470 ,
& V_480 -> V_482 [ V_481 ] . V_484 ,
false ) ;
if ( V_16 )
V_602 = true ;
F_193 ( & V_2 -> V_558 ) ;
if ( V_16 ) {
F_33 ( V_470 ) ;
F_182 ( V_480 , V_481 , NULL , 0 ) ;
} else {
V_480 -> V_482 [ V_481 ] . V_470 &=
~ V_560 ;
}
}
F_196 ( & V_2 -> V_558 ) ;
if ( V_602 )
F_10 ( V_2 , V_264 , V_2 -> V_20 ,
L_42 ) ;
else
V_14 -> V_125 = false ;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
F_7 ( V_63 , V_486 ) ;
struct V_463 * V_470 ;
unsigned int V_481 ;
int V_16 ;
for ( V_481 = 0 ; V_481 < V_559 ; V_481 ++ ) {
V_470 = F_180 ( V_480 , V_481 ) ;
if ( ! V_470 )
continue;
F_39 ( V_63 , V_487 ,
F_176 ( V_470 ) ?
V_579 :
V_572 ) ;
F_184 ( V_63 , V_489 ,
V_480 -> V_482 [ V_481 ] . V_484 ) ;
V_16 = F_9 ( V_2 , V_538 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
if ( V_16 )
F_108 ( V_2 -> V_20 ,
L_43 ,
V_481 ,
V_480 -> V_482 [ V_481 ] . V_484 ) ;
F_33 ( V_470 ) ;
}
F_223 ( V_480 -> V_482 ) ;
F_33 ( V_480 ) ;
}
static void F_224 ( struct V_1 * V_2 )
{
struct V_479 * V_480 = V_2 -> V_548 ;
struct V_603 * V_20 = V_2 -> V_20 ;
struct V_463 V_470 ;
bool V_604 = false ;
struct V_605 * V_606 ;
struct V_605 * V_607 ;
unsigned int V_481 ;
int V_37 , V_70 , V_16 ;
if ( ! F_225 ( V_2 ) )
return;
F_193 ( & V_2 -> V_558 ) ;
V_70 = V_480 -> V_608 < 0 ? 1 : V_480 -> V_608 ;
for ( V_37 = 0 ; V_37 < V_70 ; V_37 ++ ) {
V_481 = V_480 -> V_609 [ V_37 ] . V_610 % V_559 ;
V_480 -> V_482 [ V_481 ] . V_470 |= V_570 ;
}
V_70 = V_480 -> V_611 < 0 ? 1 : V_480 -> V_611 ;
for ( V_37 = 0 ; V_37 < V_70 ; V_37 ++ ) {
V_481 = V_480 -> V_612 [ V_37 ] . V_610 % V_559 ;
V_480 -> V_482 [ V_481 ] . V_470 |= V_570 ;
}
F_196 ( & V_2 -> V_558 ) ;
F_226 ( V_20 ) ;
if ( V_20 -> V_126 & V_613 ||
F_227 ( V_20 ) >= V_614 ) {
V_480 -> V_608 = - 1 ;
} else {
V_480 -> V_608 = 1 + F_227 ( V_20 ) ;
memcpy ( V_480 -> V_609 [ 0 ] . V_157 , V_20 -> V_615 ,
V_36 ) ;
V_37 = 1 ;
F_228 (uc, net_dev) {
memcpy ( V_480 -> V_609 [ V_37 ] . V_157 ,
V_606 -> V_157 , V_36 ) ;
V_37 ++ ;
}
}
if ( V_20 -> V_126 & ( V_613 | V_616 ) ||
F_229 ( V_20 ) >= V_617 ) {
V_480 -> V_611 = - 1 ;
} else {
V_480 -> V_611 = 1 + F_229 ( V_20 ) ;
F_230 ( V_480 -> V_612 [ 0 ] . V_157 ) ;
V_37 = 1 ;
F_231 (mc, net_dev) {
memcpy ( V_480 -> V_612 [ V_37 ] . V_157 ,
V_607 -> V_157 , V_36 ) ;
V_37 ++ ;
}
}
F_232 ( V_20 ) ;
if ( V_480 -> V_608 >= 0 ) {
for ( V_37 = 0 ; V_37 < V_480 -> V_608 ; V_37 ++ ) {
F_233 ( & V_470 , V_562 ,
V_531 ,
0 ) ;
F_234 ( & V_470 , V_618 ,
V_480 -> V_609 [ V_37 ] . V_157 ) ;
V_16 = F_189 ( V_2 , & V_470 , true ) ;
if ( V_16 < 0 ) {
while ( V_37 -- )
F_204 (
V_2 , V_562 ,
V_480 -> V_609 [ V_37 ] . V_610 ) ;
V_480 -> V_608 = - 1 ;
break;
}
V_480 -> V_609 [ V_37 ] . V_610 = V_16 ;
}
}
if ( V_480 -> V_608 < 0 ) {
F_233 ( & V_470 , V_562 ,
V_531 ,
0 ) ;
F_235 ( & V_470 ) ;
V_16 = F_189 ( V_2 , & V_470 , true ) ;
if ( V_16 < 0 ) {
F_40 ( 1 ) ;
V_480 -> V_608 = 0 ;
} else {
V_480 -> V_609 [ 0 ] . V_610 = V_16 ;
}
}
if ( V_480 -> V_611 >= 0 ) {
for ( V_37 = 0 ; V_37 < V_480 -> V_611 ; V_37 ++ ) {
F_233 ( & V_470 , V_562 ,
V_531 ,
0 ) ;
F_234 ( & V_470 , V_618 ,
V_480 -> V_612 [ V_37 ] . V_157 ) ;
V_16 = F_189 ( V_2 , & V_470 , true ) ;
if ( V_16 < 0 ) {
while ( V_37 -- )
F_204 (
V_2 , V_562 ,
V_480 -> V_612 [ V_37 ] . V_610 ) ;
V_480 -> V_611 = - 1 ;
break;
}
V_480 -> V_612 [ V_37 ] . V_610 = V_16 ;
}
}
if ( V_480 -> V_611 < 0 ) {
F_233 ( & V_470 , V_562 ,
V_531 ,
0 ) ;
F_236 ( & V_470 ) ;
V_16 = F_189 ( V_2 , & V_470 , true ) ;
if ( V_16 < 0 ) {
F_40 ( 1 ) ;
V_480 -> V_611 = 0 ;
} else {
V_480 -> V_612 [ 0 ] . V_610 = V_16 ;
}
}
for ( V_37 = 0 ; V_37 < V_559 ; V_37 ++ ) {
if ( F_93 ( V_480 -> V_482 [ V_37 ] . V_470 ) &
V_570 ) {
if ( F_203 (
V_2 , 1U << V_562 ,
V_37 , true ) < 0 )
V_604 = true ;
}
}
F_40 ( V_604 ) ;
}
static int F_237 ( struct V_1 * V_2 )
{
F_224 ( V_2 ) ;
return F_238 ( V_2 ) ;
}
static int F_239 ( struct V_1 * V_2 , T_5 V_619 )
{
F_7 ( V_63 , V_620 ) ;
F_39 ( V_63 , V_621 , V_619 ) ;
return F_9 ( V_2 , V_622 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
}
static int F_240 ( struct V_1 * V_2 )
{
int V_16 ;
F_7 ( V_11 , V_623 ) ;
T_2 V_15 ;
T_5 V_624 ;
V_16 = F_9 ( V_2 , V_625 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_623 )
return - V_7 ;
V_624 = F_11 ( V_11 , V_626 ) ;
switch ( V_624 ) {
case V_627 :
F_28 ( V_2 , V_264 , V_2 -> V_20 , L_44 ) ;
return 0 ;
case V_628 :
F_10 ( V_2 , V_264 , V_2 -> V_20 , L_45 ) ;
return - V_7 ;
case V_629 :
F_10 ( V_2 , V_264 , V_2 -> V_20 , L_46 ) ;
return - V_7 ;
default:
F_10 ( V_2 , V_264 , V_2 -> V_20 ,
L_47 , V_624 ) ;
return - V_7 ;
}
}
static int F_241 ( struct V_1 * V_2 , T_5 V_619 )
{
int V_16 ;
F_28 ( V_2 , V_19 , V_2 -> V_20 , L_48 , V_619 ) ;
V_16 = F_239 ( V_2 , V_619 ) ;
if ( V_16 != 0 )
return V_16 ;
return F_240 ( V_2 ) ;
}
static int
F_242 ( struct V_1 * V_2 , struct V_630 * V_631 )
{
int V_16 , V_632 ;
F_243 ( V_2 , V_136 ) ;
V_16 = F_9 ( V_2 , V_633 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
goto V_443;
V_631 -> V_634 = F_241 ( V_2 , V_635 ) ? - 1 : 1 ;
V_631 -> V_636 = F_241 ( V_2 , V_637 ) ? - 1 : 1 ;
V_16 = F_24 ( V_2 , V_136 ) ;
V_443:
V_632 = F_244 ( V_2 , V_136 , V_16 == 0 ) ;
return V_16 ? V_16 : V_632 ;
}
static int F_245 ( struct V_1 * V_2 ,
struct V_638 * V_639 ,
unsigned int type )
{
F_7 ( V_63 , V_640 ) ;
F_7 ( V_11 , V_641 ) ;
const struct V_642 * V_643 ;
T_2 V_582 , V_644 , V_15 ;
bool V_645 ;
int V_16 ;
for ( V_643 = V_646 ; ; V_643 ++ ) {
if ( V_643 ==
V_646 + F_119 ( V_646 ) )
return - V_24 ;
if ( ( type & ~ V_643 -> V_647 ) == V_643 -> type )
break;
}
if ( V_643 -> V_648 != F_246 ( V_2 ) )
return - V_24 ;
V_16 = F_247 ( V_2 , type , & V_582 , & V_644 , & V_645 ) ;
if ( V_16 )
return V_16 ;
if ( V_645 )
return - V_24 ;
V_639 -> V_649 = type ;
F_39 ( V_63 , V_650 , type ) ;
V_16 = F_9 ( V_2 , V_651 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_652 )
return - V_7 ;
if ( F_11 ( V_11 , V_653 ) &
( 1 << V_654 ) )
V_639 -> V_655 = F_11 ( V_11 ,
V_656 ) ;
V_639 -> V_657 . V_658 = L_49 ;
V_639 -> V_657 . V_659 = V_643 -> V_172 ;
V_639 -> V_657 . V_660 . type = V_661 ;
V_639 -> V_657 . V_660 . V_126 = V_662 ;
V_639 -> V_657 . V_660 . V_582 = V_582 ;
V_639 -> V_657 . V_660 . V_663 = V_644 ;
return 0 ;
}
static int F_248 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_664 ) ;
struct V_638 * V_665 ;
T_2 V_15 , V_666 , V_37 , V_667 ;
unsigned int type ;
int V_16 ;
F_249 () ;
F_8 ( V_668 != 0 ) ;
V_16 = F_9 ( V_2 , V_669 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_670 )
return - V_7 ;
V_666 = F_11 ( V_11 , V_671 ) ;
if ( V_666 >
F_217 ( V_15 , V_672 ) )
return - V_7 ;
V_665 = F_250 ( V_666 , sizeof( * V_665 ) , V_39 ) ;
if ( ! V_665 )
return - V_40 ;
V_667 = 0 ;
for ( V_37 = 0 ; V_37 < V_666 ; V_37 ++ ) {
type = F_218 ( V_11 , V_672 ,
V_37 ) ;
V_16 = F_245 ( V_2 , & V_665 [ V_667 ] , type ) ;
if ( V_16 == 0 )
V_667 ++ ;
else if ( V_16 != - V_24 )
goto V_89;
}
V_16 = F_251 ( V_2 , & V_665 [ 0 ] . V_657 , V_667 , sizeof( * V_665 ) ) ;
V_89:
if ( V_16 )
F_33 ( V_665 ) ;
return V_16 ;
}
static void F_252 ( struct V_1 * V_2 , T_5 V_673 )
{
F_21 ( V_2 , F_22 ( V_673 ) , V_216 ) ;
}
static int F_253 ( struct V_77 * V_78 ,
bool V_674 )
{
F_7 ( V_63 , V_675 ) ;
int V_16 ;
if ( V_78 -> V_676 == V_677 ||
V_78 -> V_676 == V_678 ||
( V_674 && V_78 -> V_676 == V_679 ) )
return 0 ;
V_78 -> V_676 = V_677 ;
F_39 ( V_63 , V_680 , V_681 ) ;
F_39 ( V_63 , V_682 , 0 ) ;
F_39 ( V_63 , V_683 ,
V_78 -> V_78 ) ;
V_16 = F_9 ( V_78 -> V_2 , V_684 ,
V_63 , sizeof( V_63 ) , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
V_78 -> V_676 = V_674 ? V_685 :
V_679 ;
return V_16 ;
}
static int F_254 ( struct V_77 * V_78 ,
bool V_674 )
{
F_7 ( V_63 , V_686 ) ;
int V_16 ;
if ( V_78 -> V_676 == V_679 ||
( V_674 && V_78 -> V_676 == V_685 ) )
return 0 ;
if ( V_78 -> V_676 == V_685 ) {
V_78 -> V_676 = V_679 ;
return 0 ;
}
V_78 -> V_676 = V_674 ? V_685 :
V_679 ;
F_39 ( V_63 , V_680 , V_687 ) ;
F_39 ( V_63 , V_682 , 0 ) ;
F_39 ( V_63 , V_688 ,
V_689 ) ;
F_39 ( V_63 , V_690 ,
V_78 -> V_78 ) ;
V_16 = F_9 ( V_78 -> V_2 , V_684 ,
V_63 , sizeof( V_63 ) , NULL , 0 , NULL ) ;
return V_16 ;
}
static int F_255 ( struct V_1 * V_2 , bool V_691 ,
bool V_674 )
{
int (* F_256)( struct V_77 * V_78 , bool V_674 );
struct V_77 * V_78 ;
F_256 = V_691 ?
F_253 :
F_254 ;
F_44 (channel, efx) {
int V_16 = F_256 ( V_78 , V_674 ) ;
if ( V_691 && V_16 != 0 ) {
F_255 ( V_2 , false , V_674 ) ;
return V_16 ;
}
}
return 0 ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_692 * V_693 )
{
int V_16 ;
switch ( V_693 -> V_694 ) {
case V_695 :
F_255 ( V_2 , false , false ) ;
return F_258 ( V_2 ,
V_693 -> V_696 != V_697 , 0 ) ;
case V_698 :
case V_699 :
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
V_693 -> V_694 = V_698 ;
V_16 = F_258 ( V_2 , true , 0 ) ;
if ( ! V_16 )
V_16 = F_255 ( V_2 , true , false ) ;
if ( V_16 )
F_258 ( V_2 , false , 0 ) ;
return V_16 ;
default:
return - V_30 ;
}
}
