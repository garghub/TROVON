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
return 0 ;
V_50:
F_30 ( V_2 ) ;
V_44:
F_31 ( V_2 , & V_14 -> V_41 ) ;
V_43:
F_32 ( V_14 ) ;
V_2 -> V_14 = NULL ;
return V_16 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_16 = F_9 ( V_2 , V_61 , NULL , 0 , NULL , 0 , NULL ) ;
if ( V_16 == - V_62 )
V_16 = 0 ;
return V_16 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_63 , V_64 ) ;
unsigned int V_37 ;
int V_16 ;
F_8 ( V_65 != 0 ) ;
for ( V_37 = 0 ; V_37 < V_14 -> V_66 ; V_37 ++ ) {
F_35 ( V_63 , V_67 ,
V_14 -> V_68 [ V_37 ] ) ;
V_16 = F_9 ( V_2 , V_69 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
F_36 ( V_16 ) ;
}
V_14 -> V_66 = 0 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_70 )
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
F_34 ( V_2 ) ;
return V_16 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_7 ( V_63 ,
F_39 ( V_75 ,
V_76 ) ) ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
unsigned int V_81 , V_82 ;
int V_16 ;
F_8 ( V_83 != 0 ) ;
F_8 ( V_84 != 0 ) ;
for ( V_82 = 0 ; V_82 < V_14 -> V_66 ; ++ V_82 ) {
F_35 ( V_63 , V_85 ,
V_14 -> V_68 [ V_82 ] ) ;
F_35 ( V_63 , V_86 ,
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
F_40 (channel, efx) {
F_41 (tx_queue, channel) {
V_81 = ( ( V_2 -> V_90 + V_2 -> V_91 -
V_80 -> V_78 -> V_78 - 1 ) *
V_92 ) ;
V_82 = V_81 / V_93 ;
V_81 = V_81 % V_93 ;
if ( V_80 -> V_94 == V_14 -> V_87 ) {
F_17 ( V_82 != 0 ) ;
V_16 = 0 ;
} else {
F_35 ( V_63 ,
V_85 ,
V_14 -> V_68 [ V_82 ] ) ;
F_35 ( V_63 ,
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
F_35 ( V_63 , V_99 ,
V_14 -> V_87 + V_82 ) ;
F_9 ( V_2 , V_100 ,
V_63 , V_76 ,
NULL , 0 , NULL ) ;
}
return V_16 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_70 )
{
return V_70 == 0 ? 0 : - V_101 ;
}
static int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( V_14 -> V_102 )
F_45 ( V_14 -> V_102 ) ;
V_16 = F_33 ( V_2 ) ;
F_36 ( V_16 != 0 ) ;
if ( ! V_14 -> V_103 )
F_34 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 , & V_14 -> V_41 ) ;
F_32 ( V_14 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
unsigned int V_104 , unsigned int V_105 )
{
F_7 ( V_63 , V_106 ) ;
F_7 ( V_11 , V_107 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 V_15 ;
int V_16 ;
F_35 ( V_63 , V_108 , V_104 ) ;
F_35 ( V_63 , V_109 , V_105 ) ;
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
static int F_47 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned int V_115 , V_116 ;
unsigned int V_104 , V_87 , V_105 ;
void T_4 * V_117 ;
int V_16 ;
V_104 = F_39 ( V_2 -> V_118 , V_2 -> V_91 * V_119 ) ;
#ifdef F_48
if ( V_92 != 0 &&
V_93 / V_92 * V_120 >=
V_2 -> V_91 ) {
unsigned int V_66 =
F_49 ( V_2 -> V_91 ,
V_93 / V_92 ) ;
V_16 = F_37 ( V_2 , V_66 ) ;
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
V_115 = F_50 ( ( V_104 - 1 ) * V_97 +
V_121 ) ;
if ( V_14 -> V_66 ) {
V_87 = V_115 / V_97 ;
V_116 = ( F_50 ( ( V_87 +
V_14 -> V_66 ) *
V_97 ) -
V_115 ) ;
V_105 = V_87 + V_14 -> V_66 ;
} else {
V_87 = 0 ;
V_116 = 0 ;
V_105 = V_104 ;
}
V_16 = F_33 ( V_2 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_46 ( V_2 , V_104 , V_105 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_14 -> V_66 &&
V_14 -> V_113 <
V_87 + V_14 -> V_66 ) {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_14 ,
V_14 -> V_113 , V_14 -> V_66 ) ;
F_34 ( V_2 ) ;
}
V_117 = F_51 ( V_2 -> V_122 , V_115 ) ;
if ( ! V_117 ) {
F_10 ( V_2 , V_26 , V_2 -> V_20 ,
L_15 ,
V_115 ) ;
return - V_40 ;
}
F_45 ( V_2 -> V_117 ) ;
V_2 -> V_117 = V_117 ;
if ( V_116 ) {
V_14 -> V_102 = F_52 ( V_2 -> V_122 +
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
V_16 = F_38 ( V_2 ) ;
if ( V_16 )
F_34 ( V_2 ) ;
}
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_17 ,
& V_2 -> V_122 , V_2 -> V_117 , V_115 ,
V_14 -> V_102 , V_116 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
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
V_16 = F_46 ( V_2 , V_14 -> V_113 ,
V_14 -> V_113 ) ;
if ( V_16 )
return V_16 ;
V_14 -> V_124 = false ;
}
if ( V_14 -> V_103 && V_14 -> V_66 ) {
V_16 = F_37 ( V_2 , V_14 -> V_66 ) ;
if ( V_16 == 0 ) {
V_16 = F_38 ( V_2 ) ;
if ( V_16 )
F_34 ( V_2 ) ;
}
if ( V_16 )
F_10 ( V_2 , V_19 , V_2 -> V_20 ,
L_18 , V_16 ) ;
V_14 -> V_103 = false ;
}
F_54 ( V_2 ) ;
return 0 ;
}
static int F_55 ( T_5 * V_125 )
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
return V_49 ;
}
return - V_136 ;
}
static T_6 F_56 ( struct V_1 * V_2 )
{
T_6 V_137 = V_138 ;
T_5 V_139 = F_57 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_139 & ( 1 << V_140 ) )
V_137 |= V_141 ;
else
V_137 |= V_142 ;
if ( V_14 -> V_21 &
( 1 << V_143 ) )
V_137 |= V_144 ;
return V_137 ;
}
static void F_58 ( struct V_1 * V_2 , unsigned long * V_145 )
{
T_6 V_137 = F_56 ( V_2 ) ;
#if V_146 == 64
V_145 [ 0 ] = V_137 ;
#else
V_145 [ 0 ] = V_137 & 0xffffffff ;
V_145 [ 1 ] = V_137 >> 32 ;
#endif
}
static T_2 F_59 ( struct V_1 * V_2 , T_3 * V_147 )
{
F_60 ( V_145 , V_148 ) ;
F_58 ( V_2 , V_145 ) ;
return F_61 ( V_149 , V_148 ,
V_145 , V_147 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_60 ( V_145 , V_148 ) ;
T_7 V_150 , V_151 ;
T_6 * V_152 = V_14 -> V_152 ;
T_7 * V_153 ;
F_58 ( V_2 , V_145 ) ;
V_153 = V_2 -> V_154 . V_155 ;
V_14 = V_2 -> V_14 ;
V_151 = V_153 [ V_156 ] ;
if ( V_151 == V_157 )
return 0 ;
F_63 () ;
F_64 ( V_149 , V_148 , V_145 ,
V_152 , V_2 -> V_154 . V_155 , false ) ;
F_63 () ;
V_150 = V_153 [ V_158 ] ;
if ( V_151 != V_150 )
return - V_159 ;
V_152 [ V_160 ] =
V_152 [ V_161 ] -
V_152 [ V_162 ] ;
F_65 ( & V_152 [ V_163 ] ,
V_152 [ V_162 ] ) ;
return 0 ;
}
static T_2 F_66 ( struct V_1 * V_2 , T_6 * V_164 ,
struct V_165 * V_166 )
{
F_60 ( V_145 , V_148 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 * V_152 = V_14 -> V_152 ;
T_2 V_167 = 0 , V_82 ;
int V_168 ;
F_58 ( V_2 , V_145 ) ;
for ( V_168 = 0 ; V_168 < 100 ; ++ V_168 ) {
if ( F_62 ( V_2 ) == 0 )
break;
F_67 ( 100 ) ;
}
if ( V_164 ) {
F_68 (index, mask, EF10_STAT_COUNT) {
if ( V_149 [ V_82 ] . V_169 ) {
* V_164 ++ = V_152 [ V_82 ] ;
++ V_167 ;
}
}
}
if ( V_166 ) {
V_166 -> V_170 = V_152 [ V_171 ] ;
V_166 -> V_172 = V_152 [ V_173 ] ;
V_166 -> V_174 = V_152 [ V_161 ] ;
V_166 -> V_175 = V_152 [ V_176 ] ;
V_166 -> V_177 = V_152 [ V_178 ] ;
V_166 -> V_179 = V_152 [ V_180 ] ;
V_166 -> V_181 =
V_152 [ V_182 ] +
V_152 [ V_183 ] ;
V_166 -> V_184 = V_152 [ V_185 ] ;
V_166 -> V_186 = V_152 [ V_187 ] ;
V_166 -> V_188 = V_152 [ V_189 ] ;
V_166 -> V_190 = ( V_166 -> V_181 +
V_166 -> V_184 +
V_166 -> V_186 ) ;
}
return V_167 ;
}
static void F_69 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
unsigned int V_191 , V_192 ;
T_1 V_193 ;
if ( V_78 -> V_194 ) {
V_191 = 3 ;
V_192 = V_78 -> V_194 - 1 ;
} else {
V_191 = 0 ;
V_192 = 0 ;
}
if ( F_70 ( V_2 ) ) {
F_71 ( V_193 , V_195 ,
V_196 ,
V_197 , V_191 ,
V_198 , V_192 ) ;
F_72 ( V_2 , & V_193 , V_199 ,
V_78 -> V_78 ) ;
} else {
F_73 ( V_193 , V_200 , V_191 ,
V_201 , V_192 ) ;
F_72 ( V_2 , & V_193 , V_202 ,
V_78 -> V_78 ) ;
}
}
static void F_74 ( struct V_1 * V_2 , struct V_203 * V_204 )
{
V_204 -> V_205 = 0 ;
V_204 -> V_206 = 0 ;
memset ( & V_204 -> V_207 , 0 , sizeof( V_204 -> V_207 ) ) ;
}
static int F_75 ( struct V_1 * V_2 , T_5 type )
{
if ( type != 0 )
return - V_136 ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 ,
const T_1 * V_208 , T_2 V_209 ,
const T_1 * V_210 , T_2 V_211 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_3 * V_212 = V_14 -> V_41 . V_155 ;
memcpy ( V_212 , V_208 , V_209 ) ;
memcpy ( V_212 + V_209 , V_210 , V_211 ) ;
F_77 () ;
F_21 ( V_2 , F_22 ( ( T_6 ) V_14 -> V_41 . V_213 >> 32 ) ,
V_214 ) ;
F_21 ( V_2 , F_22 ( ( T_5 ) V_14 -> V_41 . V_213 ) ,
V_48 ) ;
}
static bool F_78 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_1 V_208 = * ( const T_1 * ) V_14 -> V_41 . V_155 ;
F_63 () ;
return F_3 ( V_208 , V_215 ) ;
}
static void
F_79 ( struct V_1 * V_2 , T_1 * V_11 ,
T_2 V_81 , T_2 V_15 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const T_3 * V_212 = V_14 -> V_41 . V_155 ;
memcpy ( V_11 , V_212 + V_81 , V_15 ) ;
}
static int F_80 ( struct V_1 * V_2 )
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
V_14 -> V_124 = true ;
V_14 -> V_216 = true ;
V_14 -> V_103 = true ;
V_14 -> V_46 = V_47 ;
V_14 -> V_123 = true ;
V_14 -> V_152 [ V_163 ] = 0 ;
return - V_7 ;
}
static T_8 F_81 ( int V_217 , void * V_218 )
{
struct V_219 * V_220 = V_218 ;
struct V_1 * V_2 = V_220 -> V_2 ;
F_82 ( V_2 , V_221 , V_2 -> V_20 ,
L_19 , V_217 , F_83 () ) ;
if ( F_84 ( F_85 ( V_2 -> V_222 ) ) ) {
if ( V_220 -> V_82 == V_2 -> V_223 )
V_2 -> V_224 = F_83 () ;
F_86 ( V_2 -> V_78 [ V_220 -> V_82 ] ) ;
}
return V_225 ;
}
static T_8 F_87 ( int V_217 , void * V_218 )
{
struct V_1 * V_2 = V_218 ;
bool V_226 = F_85 ( V_2 -> V_222 ) ;
struct V_77 * V_78 ;
T_1 V_3 ;
T_5 V_227 ;
F_2 ( V_2 , & V_3 , V_228 ) ;
V_227 = F_3 ( V_3 , V_229 ) ;
if ( V_227 == 0 )
return V_230 ;
if ( F_84 ( V_226 ) ) {
if ( V_227 & ( 1U << V_2 -> V_223 ) )
V_2 -> V_224 = F_83 () ;
F_40 (channel, efx) {
if ( V_227 & 1 )
F_86 ( V_78 ) ;
V_227 >>= 1 ;
}
}
F_82 ( V_2 , V_221 , V_2 -> V_20 ,
L_20 V_231 L_21 ,
V_217 , F_83 () , F_88 ( V_3 ) ) ;
return V_225 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_7 ( V_63 , V_232 ) ;
F_8 ( V_233 != 0 ) ;
F_35 ( V_63 , V_234 , V_2 -> V_223 ) ;
( void ) F_9 ( V_2 , V_235 ,
V_63 , sizeof( V_63 ) , NULL , 0 , NULL ) ;
}
static int F_90 ( struct V_79 * V_80 )
{
return F_19 ( V_80 -> V_2 , & V_80 -> V_236 . V_237 ,
( V_80 -> V_238 + 1 ) *
sizeof( V_239 ) ,
V_39 ) ;
}
static inline void F_91 ( struct V_79 * V_80 ,
const V_239 * V_236 )
{
unsigned int V_240 ;
T_9 V_3 ;
V_240 = V_80 -> V_241 & V_80 -> V_238 ;
F_92 ( V_3 , V_242 , V_240 ) ;
V_3 . V_243 [ 0 ] = * V_236 ;
F_93 ( V_80 -> V_2 , & V_3 ,
V_244 , V_80 -> V_94 ) ;
}
static void F_94 ( struct V_79 * V_80 )
{
F_7 ( V_63 , F_95 ( V_245 * 8 /
V_246 ) ) ;
F_7 ( V_11 , V_247 ) ;
bool V_248 = V_80 -> V_94 & V_249 ;
T_2 V_250 = V_80 -> V_236 . V_237 . V_251 / V_246 ;
struct V_77 * V_78 = V_80 -> V_78 ;
struct V_1 * V_2 = V_80 -> V_2 ;
T_2 V_252 , V_15 ;
T_10 V_213 ;
V_239 * V_236 ;
int V_16 ;
int V_37 ;
F_35 ( V_63 , V_253 , V_80 -> V_238 + 1 ) ;
F_35 ( V_63 , V_254 , V_78 -> V_78 ) ;
F_35 ( V_63 , V_255 , V_80 -> V_94 ) ;
F_35 ( V_63 , V_256 , V_80 -> V_94 ) ;
F_96 ( V_63 , V_257 ,
V_258 , ! V_248 ,
V_259 , ! V_248 ) ;
F_35 ( V_63 , V_260 , 0 ) ;
F_35 ( V_63 , V_261 , V_262 ) ;
V_213 = V_80 -> V_236 . V_237 . V_213 ;
F_28 ( V_2 , V_263 , V_2 -> V_20 , L_22 ,
V_80 -> V_94 , V_250 , ( T_6 ) V_213 ) ;
for ( V_37 = 0 ; V_37 < V_250 ; ++ V_37 ) {
F_97 ( V_63 , V_264 , V_37 , V_213 ) ;
V_213 += V_246 ;
}
V_252 = F_95 ( V_250 ) ;
V_16 = F_9 ( V_2 , V_265 , V_63 , V_252 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_89;
V_80 -> V_266 [ 0 ] . V_125 = V_267 ;
V_80 -> V_268 = 1 ;
V_236 = F_98 ( V_80 , 0 ) ;
F_99 ( * V_236 ,
V_269 , true ,
V_270 ,
V_271 ,
V_272 , V_248 ,
V_273 , V_248 ) ;
V_80 -> V_241 = 1 ;
F_77 () ;
F_91 ( V_80 , V_236 ) ;
return;
V_89:
F_36 ( true ) ;
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
}
static void F_100 ( struct V_79 * V_80 )
{
F_7 ( V_63 , V_275 ) ;
F_7 ( V_11 , V_276 ) ;
struct V_1 * V_2 = V_80 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_35 ( V_63 , V_277 ,
V_80 -> V_94 ) ;
V_16 = F_9 ( V_2 , V_278 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_89;
return;
V_89:
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
}
static void F_101 ( struct V_79 * V_80 )
{
F_31 ( V_80 -> V_2 , & V_80 -> V_236 . V_237 ) ;
}
static inline void F_102 ( struct V_79 * V_80 )
{
unsigned int V_240 ;
T_1 V_3 ;
V_240 = V_80 -> V_241 & V_80 -> V_238 ;
F_103 ( V_3 , V_279 , V_240 ) ;
F_72 ( V_80 -> V_2 , & V_3 ,
V_280 , V_80 -> V_94 ) ;
}
static void F_104 ( struct V_79 * V_80 )
{
unsigned int V_281 = V_80 -> V_241 ;
struct V_282 * V_266 ;
unsigned int V_240 ;
V_239 * V_236 ;
F_17 ( V_80 -> V_241 == V_80 -> V_268 ) ;
do {
V_240 = V_80 -> V_241 & V_80 -> V_238 ;
V_266 = & V_80 -> V_266 [ V_240 ] ;
V_236 = F_98 ( V_80 , V_240 ) ;
++ V_80 -> V_241 ;
if ( V_266 -> V_125 & V_267 ) {
* V_236 = V_266 -> V_283 ;
} else {
F_8 ( V_284 != 1 ) ;
F_105 (
* V_236 ,
V_285 ,
V_266 -> V_125 & V_284 ,
V_286 , V_266 -> V_251 ,
V_287 , V_266 -> V_213 ) ;
}
} while ( V_80 -> V_241 != V_80 -> V_268 );
F_77 () ;
if ( F_106 ( V_80 , V_281 ) ) {
V_236 = F_98 ( V_80 ,
V_281 & V_80 -> V_238 ) ;
F_91 ( V_80 , V_236 ) ;
++ V_80 -> V_288 ;
} else {
F_102 ( V_80 ) ;
}
}
static int F_107 ( struct V_1 * V_2 , T_5 * V_220 )
{
F_7 ( V_63 , V_289 ) ;
F_7 ( V_11 , V_290 ) ;
T_2 V_15 ;
int V_16 ;
F_35 ( V_63 , V_291 ,
V_262 ) ;
F_35 ( V_63 , V_292 ,
V_293 ) ;
F_35 ( V_63 , V_294 ,
V_295 ) ;
V_16 = F_9 ( V_2 , V_296 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( V_15 < V_290 )
return - V_7 ;
* V_220 = F_11 ( V_11 , V_297 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 , T_5 V_220 )
{
F_7 ( V_63 , V_298 ) ;
int V_16 ;
F_35 ( V_63 , V_299 ,
V_220 ) ;
V_16 = F_9 ( V_2 , V_300 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
F_36 ( V_16 != 0 ) ;
}
static int F_109 ( struct V_1 * V_2 , T_5 V_220 )
{
F_7 ( V_301 , V_302 ) ;
F_7 ( V_303 , V_304 ) ;
int V_37 , V_16 ;
F_35 ( V_301 , V_305 ,
V_220 ) ;
F_8 ( F_110 ( V_2 -> V_306 ) !=
V_307 ) ;
for ( V_37 = 0 ; V_37 < F_110 ( V_2 -> V_306 ) ; ++ V_37 )
F_14 ( V_301 ,
V_308 ) [ V_37 ] =
( T_3 ) V_2 -> V_306 [ V_37 ] ;
V_16 = F_9 ( V_2 , V_309 , V_301 ,
sizeof( V_301 ) , NULL , 0 , NULL ) ;
if ( V_16 != 0 )
return V_16 ;
F_35 ( V_303 , V_310 ,
V_220 ) ;
F_8 ( F_110 ( V_2 -> V_311 ) !=
V_312 ) ;
for ( V_37 = 0 ; V_37 < F_110 ( V_2 -> V_311 ) ; ++ V_37 )
F_14 ( V_303 , V_313 ) [ V_37 ] =
V_2 -> V_311 [ V_37 ] ;
return F_9 ( V_2 , V_314 , V_303 ,
sizeof( V_303 ) , NULL , 0 , NULL ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_46 != V_47 )
F_108 ( V_2 , V_14 -> V_46 ) ;
V_14 -> V_46 = V_47 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_16 ;
F_28 ( V_2 , V_19 , V_2 -> V_20 , L_24 ) ;
if ( V_14 -> V_46 == V_47 ) {
V_16 = F_107 ( V_2 , & V_14 -> V_46 ) ;
if ( V_16 != 0 )
goto V_89;
}
V_16 = F_109 ( V_2 , V_14 -> V_46 ) ;
if ( V_16 != 0 )
goto V_89;
return;
V_89:
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
}
static int F_111 ( struct V_315 * V_316 )
{
return F_19 ( V_316 -> V_2 , & V_316 -> V_317 . V_237 ,
( V_316 -> V_238 + 1 ) *
sizeof( V_239 ) ,
V_39 ) ;
}
static void F_112 ( struct V_315 * V_316 )
{
F_7 ( V_63 ,
F_113 ( V_245 * 8 /
V_246 ) ) ;
F_7 ( V_11 , V_318 ) ;
struct V_77 * V_78 = F_114 ( V_316 ) ;
T_2 V_250 = V_316 -> V_317 . V_237 . V_251 / V_246 ;
struct V_1 * V_2 = V_316 -> V_2 ;
T_2 V_252 , V_15 ;
T_10 V_213 ;
int V_16 ;
int V_37 ;
V_316 -> V_319 = 0 ;
V_316 -> V_320 = 0 ;
F_35 ( V_63 , V_321 , V_316 -> V_238 + 1 ) ;
F_35 ( V_63 , V_322 , V_78 -> V_78 ) ;
F_35 ( V_63 , V_323 , F_115 ( V_316 ) ) ;
F_35 ( V_63 , V_324 ,
F_115 ( V_316 ) ) ;
F_116 ( V_63 , V_325 ,
V_326 , 1 ) ;
F_35 ( V_63 , V_327 , 0 ) ;
F_35 ( V_63 , V_328 , V_262 ) ;
V_213 = V_316 -> V_317 . V_237 . V_213 ;
F_28 ( V_2 , V_263 , V_2 -> V_20 , L_25 ,
F_115 ( V_316 ) , V_250 , ( T_6 ) V_213 ) ;
for ( V_37 = 0 ; V_37 < V_250 ; ++ V_37 ) {
F_97 ( V_63 , V_329 , V_37 , V_213 ) ;
V_213 += V_246 ;
}
V_252 = F_113 ( V_250 ) ;
V_16 = F_9 ( V_2 , V_330 , V_63 , V_252 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_89;
return;
V_89:
F_36 ( true ) ;
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
}
static void F_117 ( struct V_315 * V_316 )
{
F_7 ( V_63 , V_331 ) ;
F_7 ( V_11 , V_332 ) ;
struct V_1 * V_2 = V_316 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_35 ( V_63 , V_333 ,
F_115 ( V_316 ) ) ;
V_16 = F_9 ( V_2 , V_334 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_89;
return;
V_89:
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
}
static void F_118 ( struct V_315 * V_316 )
{
F_31 ( V_316 -> V_2 , & V_316 -> V_317 . V_237 ) ;
}
static inline void
F_119 ( struct V_315 * V_316 , unsigned int V_82 )
{
struct V_335 * V_336 ;
V_239 * V_317 ;
V_317 = F_120 ( V_316 , V_82 ) ;
V_336 = V_335 ( V_316 , V_82 ) ;
F_121 ( * V_317 ,
V_337 , V_336 -> V_251 ,
V_338 , V_336 -> V_213 ) ;
}
static void F_122 ( struct V_315 * V_316 )
{
struct V_1 * V_2 = V_316 -> V_2 ;
unsigned int V_241 ;
T_1 V_3 ;
V_241 = V_316 -> V_339 & ~ 7 ;
if ( V_316 -> V_340 == V_241 )
return;
do
F_119 (
V_316 ,
V_316 -> V_340 & V_316 -> V_238 ) ;
while ( ++ V_316 -> V_340 != V_241 );
F_77 () ;
F_103 ( V_3 , V_341 ,
V_241 & V_316 -> V_238 ) ;
F_72 ( V_2 , & V_3 , V_342 ,
F_115 ( V_316 ) ) ;
}
static void F_123 ( struct V_315 * V_316 )
{
struct V_77 * V_78 = F_114 ( V_316 ) ;
F_7 ( V_63 , V_343 ) ;
V_239 V_344 ;
F_121 ( V_344 ,
V_345 , V_346 ,
V_347 , V_348 ) ;
F_35 ( V_63 , V_349 , V_78 -> V_78 ) ;
memcpy ( F_14 ( V_63 , V_350 ) , & V_344 . T_6 [ 0 ] ,
sizeof( V_239 ) ) ;
F_124 ( V_78 -> V_2 , V_351 ,
V_63 , sizeof( V_63 ) , 0 ,
V_352 , 0 ) ;
}
static void
V_352 ( struct V_1 * V_2 , unsigned long V_353 ,
int V_16 , T_1 * V_11 ,
T_2 V_354 )
{
}
static int F_125 ( struct V_77 * V_78 )
{
return F_19 ( V_78 -> V_2 , & V_78 -> V_355 . V_237 ,
( V_78 -> V_356 + 1 ) *
sizeof( V_239 ) ,
V_39 ) ;
}
static int F_126 ( struct V_77 * V_78 )
{
F_7 ( V_63 ,
F_127 ( V_357 * 8 /
V_246 ) ) ;
F_7 ( V_11 , V_358 ) ;
T_2 V_250 = V_78 -> V_355 . V_237 . V_251 / V_246 ;
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_13 * V_14 ;
bool V_359 ;
T_2 V_252 , V_15 ;
T_10 V_213 ;
int V_16 ;
int V_37 ;
V_14 = V_2 -> V_14 ;
V_359 =
! ! ( V_14 -> V_21 &
1 << V_360 ) ;
memset ( V_78 -> V_355 . V_237 . V_155 , 0xff , V_78 -> V_355 . V_237 . V_251 ) ;
F_35 ( V_63 , V_361 , V_78 -> V_356 + 1 ) ;
F_35 ( V_63 , V_362 , V_78 -> V_78 ) ;
F_35 ( V_63 , V_363 , V_78 -> V_78 ) ;
F_128 ( V_63 , V_364 ,
V_365 , 1 ,
V_366 , 1 ,
V_367 , 1 ,
V_368 , ! V_359 ) ;
F_35 ( V_63 , V_369 ,
V_370 ) ;
F_35 ( V_63 , V_371 , 0 ) ;
F_35 ( V_63 , V_372 , 0 ) ;
F_35 ( V_63 , V_373 ,
V_374 ) ;
F_35 ( V_63 , V_375 , 0 ) ;
V_213 = V_78 -> V_355 . V_237 . V_213 ;
for ( V_37 = 0 ; V_37 < V_250 ; ++ V_37 ) {
F_97 ( V_63 , V_376 , V_37 , V_213 ) ;
V_213 += V_246 ;
}
V_252 = F_127 ( V_250 ) ;
V_16 = F_9 ( V_2 , V_377 , V_63 , V_252 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
goto V_89;
return 0 ;
V_89:
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
return V_16 ;
}
static void F_129 ( struct V_77 * V_78 )
{
F_7 ( V_63 , V_378 ) ;
F_7 ( V_11 , V_379 ) ;
struct V_1 * V_2 = V_78 -> V_2 ;
T_2 V_15 ;
int V_16 ;
F_35 ( V_63 , V_380 , V_78 -> V_78 ) ;
V_16 = F_9 ( V_2 , V_381 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 && V_16 != - V_62 )
goto V_89;
return;
V_89:
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
}
static void F_130 ( struct V_77 * V_78 )
{
F_31 ( V_78 -> V_2 , & V_78 -> V_355 . V_237 ) ;
}
static void F_131 ( struct V_315 * V_316 ,
unsigned int V_382 )
{
struct V_1 * V_2 = V_316 -> V_2 ;
F_132 ( V_2 , V_263 , V_2 -> V_20 ,
L_26 ,
F_115 ( V_316 ) , V_382 ) ;
F_133 ( V_2 , V_383 ) ;
}
static void
F_134 ( struct V_315 * V_316 ,
unsigned int V_384 , unsigned int V_385 )
{
unsigned int V_386 = ( V_384 - V_385 ) & V_316 -> V_238 ;
struct V_1 * V_2 = V_316 -> V_2 ;
F_132 ( V_2 , V_263 , V_2 -> V_20 ,
L_27 ,
V_386 , V_384 , V_385 ) ;
F_133 ( V_2 , V_383 ) ;
}
static void F_135 ( struct V_315 * V_316 )
{
unsigned int V_387 ;
F_36 ( V_316 -> V_319 == 0 ) ;
F_28 ( V_316 -> V_2 , V_263 , V_316 -> V_2 -> V_20 ,
L_28 ,
V_316 -> V_319 ) ;
V_387 = V_316 -> V_388 & V_316 -> V_238 ;
F_136 ( V_316 , V_387 , V_316 -> V_319 ,
0 , V_389 ) ;
V_316 -> V_388 += V_316 -> V_319 ;
V_316 -> V_319 = 0 ;
V_316 -> V_320 = 0 ;
++ F_114 ( V_316 ) -> V_390 ;
}
static int F_137 ( struct V_77 * V_78 ,
const V_239 * V_344 )
{
unsigned int V_174 , V_391 , V_382 , V_392 ;
unsigned int V_393 , V_394 , V_37 ;
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_315 * V_316 ;
bool V_395 ;
T_11 V_125 = 0 ;
if ( F_138 ( F_85 ( V_2 -> V_396 ) ) )
return 0 ;
V_174 = F_139 ( * V_344 , V_397 ) ;
V_391 = F_139 ( * V_344 , V_398 ) ;
V_382 = F_139 ( * V_344 , V_399 ) ;
V_392 = F_139 ( * V_344 , V_400 ) ;
V_395 = F_139 ( * V_344 , V_401 ) ;
F_36 ( F_139 ( * V_344 , V_402 ) ) ;
V_316 = F_140 ( V_78 ) ;
if ( F_138 ( V_382 != F_115 ( V_316 ) ) )
F_131 ( V_316 , V_382 ) ;
V_393 = ( ( V_391 - V_316 -> V_388 ) &
( ( 1 << V_403 ) - 1 ) ) ;
if ( V_393 != V_316 -> V_319 + 1 ) {
if ( F_138 ( V_393 == V_316 -> V_319 ) ) {
F_36 ( V_174 != 0 ) ;
F_135 ( V_316 ) ;
return 0 ;
}
if ( F_138 ( V_316 -> V_319 != 0 ) ) {
F_134 (
V_316 , V_391 ,
( V_316 -> V_388 +
V_316 -> V_319 + 1 ) &
( ( 1 << V_403 ) - 1 ) ) ;
return 0 ;
}
V_316 -> V_319 = 1 ;
V_316 -> V_320 = 0 ;
V_394 = V_393 ;
++ V_78 -> V_404 ;
V_78 -> V_405 += V_394 ;
V_125 |= V_406 ;
} else {
++ V_316 -> V_319 ;
V_316 -> V_320 += V_174 ;
if ( V_395 )
return 0 ;
V_394 = 1 ;
}
if ( F_138 ( F_139 ( * V_344 , V_407 ) ) )
V_125 |= V_389 ;
if ( F_138 ( F_139 ( * V_344 , V_408 ) ) ) {
V_78 -> V_409 += V_394 ;
} else if ( F_138 ( F_139 ( * V_344 ,
V_410 ) ) ) {
V_78 -> V_411 += V_394 ;
} else if ( V_392 == V_412 ||
V_392 == V_413 ) {
V_125 |= V_414 ;
}
if ( V_392 == V_412 )
V_125 |= V_415 ;
V_78 -> V_416 += 2 * V_394 ;
for ( V_37 = 0 ; V_37 < V_394 ; V_37 ++ ) {
F_136 ( V_316 ,
V_316 -> V_388 & V_316 -> V_238 ,
V_316 -> V_319 , V_316 -> V_320 ,
V_125 ) ;
V_316 -> V_388 += V_316 -> V_319 ;
}
V_316 -> V_319 = 0 ;
V_316 -> V_320 = 0 ;
return V_394 ;
}
static int
F_141 ( struct V_77 * V_78 , V_239 * V_344 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
struct V_79 * V_80 ;
unsigned int V_417 ;
unsigned int V_418 ;
int V_419 = 0 ;
if ( F_138 ( F_85 ( V_2 -> V_396 ) ) )
return 0 ;
if ( F_138 ( F_139 ( * V_344 , V_420 ) ) )
return 0 ;
V_417 = F_139 ( * V_344 , V_421 ) ;
V_418 = F_139 ( * V_344 , V_422 ) ;
V_80 = F_142 ( V_78 ,
V_418 % V_119 ) ;
V_419 = ( ( V_417 + 1 - V_80 -> V_423 ) &
V_80 -> V_238 ) ;
F_143 ( V_80 , V_417 & V_80 -> V_238 ) ;
return V_419 ;
}
static void
F_144 ( struct V_77 * V_78 , V_239 * V_344 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
int V_424 ;
V_424 = F_139 ( * V_344 , V_425 ) ;
switch ( V_424 ) {
case V_426 :
case V_427 :
break;
case V_428 :
break;
default:
F_10 ( V_2 , V_263 , V_2 -> V_20 ,
L_29
L_30 V_429 L_31 ,
V_78 -> V_78 , V_424 ,
F_145 ( * V_344 ) ) ;
}
}
static void F_146 ( struct V_77 * V_78 ,
V_239 * V_344 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
T_5 V_424 ;
V_424 = F_139 ( * V_344 , V_430 ) ;
switch ( V_424 ) {
case V_431 :
V_78 -> V_432 = F_83 () ;
break;
case V_348 :
F_147 ( & V_78 -> V_316 ) ;
break;
default:
F_10 ( V_2 , V_263 , V_2 -> V_20 ,
L_32
L_30 V_429 L_31 ,
V_78 -> V_78 , ( unsigned ) V_424 ,
F_145 ( * V_344 ) ) ;
}
}
static int F_148 ( struct V_77 * V_78 , int V_433 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
V_239 V_344 , * V_434 ;
unsigned int V_435 ;
int V_436 ;
int V_419 = 0 ;
int V_437 = 0 ;
V_435 = V_78 -> V_438 ;
for (; ; ) {
V_434 = F_149 ( V_78 , V_435 ) ;
V_344 = * V_434 ;
if ( ! F_150 ( & V_344 ) )
break;
F_151 ( * V_434 ) ;
++ V_435 ;
V_436 = F_139 ( V_344 , V_345 ) ;
F_82 ( V_2 , V_19 , V_2 -> V_20 ,
L_33 V_429 L_21 ,
V_78 -> V_78 , F_145 ( V_344 ) ) ;
switch ( V_436 ) {
case V_439 :
F_152 ( V_78 , & V_344 ) ;
break;
case V_440 :
V_437 += F_137 ( V_78 , & V_344 ) ;
if ( V_437 >= V_433 ) {
V_437 = V_433 ;
goto V_441;
}
break;
case V_442 :
V_419 += F_141 ( V_78 , & V_344 ) ;
if ( V_419 > V_2 -> V_443 ) {
V_437 = V_433 ;
goto V_441;
} else if ( ++ V_437 == V_433 ) {
goto V_441;
}
break;
case V_444 :
F_144 ( V_78 , & V_344 ) ;
if ( ++ V_437 == V_433 )
goto V_441;
break;
case V_346 :
F_146 ( V_78 , & V_344 ) ;
break;
default:
F_10 ( V_2 , V_263 , V_2 -> V_20 ,
L_34
L_30 V_429 L_31 ,
V_78 -> V_78 , V_436 ,
F_145 ( V_344 ) ) ;
}
}
V_441:
V_78 -> V_438 = V_435 ;
return V_437 ;
}
static void F_153 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = V_78 -> V_2 ;
T_1 V_445 ;
if ( F_70 ( V_2 ) ) {
F_8 ( V_446 <
( 1 << V_447 ) ) ;
F_8 ( V_357 >
( 1 << 2 * V_447 ) ) ;
F_73 ( V_445 , V_448 ,
V_449 ,
V_450 ,
( V_78 -> V_438 &
V_78 -> V_356 ) >>
V_447 ) ;
F_72 ( V_2 , & V_445 , V_199 ,
V_78 -> V_78 ) ;
F_73 ( V_445 , V_448 ,
V_451 ,
V_450 ,
V_78 -> V_438 &
( ( 1 << V_447 ) - 1 ) ) ;
F_72 ( V_2 , & V_445 , V_199 ,
V_78 -> V_78 ) ;
} else {
F_103 ( V_445 , V_452 ,
V_78 -> V_438 &
V_78 -> V_356 ) ;
F_72 ( V_2 , & V_445 , V_453 , V_78 -> V_78 ) ;
}
}
static void F_154 ( struct V_77 * V_78 )
{
F_7 ( V_63 , V_343 ) ;
struct V_1 * V_2 = V_78 -> V_2 ;
V_239 V_344 ;
int V_16 ;
F_121 ( V_344 ,
V_345 , V_346 ,
V_347 , V_431 ) ;
F_35 ( V_63 , V_349 , V_78 -> V_78 ) ;
memcpy ( F_14 ( V_63 , V_350 ) , & V_344 . T_6 [ 0 ] ,
sizeof( V_239 ) ) ;
V_16 = F_9 ( V_2 , V_351 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
if ( V_16 != 0 )
goto V_89;
return;
V_89:
F_36 ( true ) ;
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_23 , V_274 , V_16 ) ;
}
void F_155 ( struct V_1 * V_2 )
{
if ( F_156 ( & V_2 -> V_454 ) )
F_157 ( & V_2 -> V_455 ) ;
F_36 ( F_158 ( & V_2 -> V_454 ) < 0 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_315 * V_316 ;
int V_456 ;
if ( V_14 -> V_124 ) {
F_160 ( & V_2 -> V_454 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_457 != V_458 ) {
F_40 (channel, efx) {
F_161 (rx_queue, channel)
F_117 ( V_316 ) ;
F_41 (tx_queue, channel)
F_100 ( V_80 ) ;
}
F_162 ( V_2 -> V_455 ,
F_158 ( & V_2 -> V_454 ) == 0 ,
F_163 ( V_459 ) ) ;
V_456 = F_158 ( & V_2 -> V_454 ) ;
if ( V_456 ) {
F_10 ( V_2 , V_263 , V_2 -> V_20 , L_35 ,
V_456 ) ;
return - V_460 ;
}
}
return 0 ;
}
static bool F_164 ( const struct V_461 * V_462 ,
const struct V_461 * V_463 )
{
if ( ( V_462 -> V_464 ^ V_463 -> V_464 ) |
( ( V_462 -> V_125 ^ V_463 -> V_125 ) &
( V_465 | V_466 ) ) )
return false ;
return memcmp ( & V_462 -> V_467 , & V_463 -> V_467 ,
sizeof( struct V_461 ) -
F_165 ( struct V_461 , V_467 ) ) == 0 ;
}
static unsigned int F_166 ( const struct V_461 * V_468 )
{
F_8 ( F_165 ( struct V_461 , V_467 ) & 3 ) ;
return F_167 ( ( const T_5 * ) & V_468 -> V_467 ,
( sizeof( struct V_461 ) -
F_165 ( struct V_461 , V_467 ) ) / 4 ,
0 ) ;
}
static bool F_168 ( const struct V_461 * V_468 )
{
if ( V_468 -> V_464 & V_469 &&
! F_169 ( V_468 -> V_470 ) )
return true ;
if ( ( V_468 -> V_464 &
( V_471 | V_472 ) ) ==
( V_471 | V_472 ) ) {
if ( V_468 -> V_473 == F_170 ( V_474 ) &&
! F_171 ( V_468 -> V_475 [ 0 ] ) )
return true ;
if ( V_468 -> V_473 == F_170 ( V_476 ) &&
( ( const T_3 * ) V_468 -> V_475 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_461 *
F_172 ( const struct V_477 * V_478 ,
unsigned int V_479 )
{
return (struct V_461 * ) ( V_478 -> V_480 [ V_479 ] . V_468 &
~ V_481 ) ;
}
static unsigned int
F_173 ( const struct V_477 * V_478 ,
unsigned int V_479 )
{
return V_478 -> V_480 [ V_479 ] . V_468 & V_481 ;
}
static void
F_174 ( struct V_477 * V_478 ,
unsigned int V_479 ,
const struct V_461 * V_468 ,
unsigned int V_125 )
{
V_478 -> V_480 [ V_479 ] . V_468 = ( unsigned long ) V_468 | V_125 ;
}
static void F_175 ( struct V_1 * V_2 ,
const struct V_461 * V_468 ,
T_1 * V_63 , T_6 V_482 ,
bool V_483 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
memset ( V_63 , 0 , V_484 ) ;
if ( V_483 ) {
F_35 ( V_63 , V_485 ,
V_486 ) ;
F_176 ( V_63 , V_487 , V_482 ) ;
} else {
T_5 V_488 = 0 ;
F_35 ( V_63 , V_485 ,
F_168 ( V_468 ) ?
V_489 :
V_490 ) ;
if ( V_468 -> V_464 & V_491 )
V_488 |=
F_169 ( V_468 -> V_470 ) ?
1 << V_492 :
1 << V_493 ;
#define F_177 ( T_12 , T_13 , T_14 ) \
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
F_177 ( V_494 , V_495 , V_496 ) ;
F_177 ( V_497 , V_475 , V_498 ) ;
F_177 ( V_499 , V_500 , V_501 ) ;
F_177 ( V_502 , V_503 , V_504 ) ;
F_177 ( V_505 , V_470 , V_506 ) ;
F_177 ( V_507 , V_508 , V_509 ) ;
F_177 ( V_510 , V_473 , V_510 ) ;
F_177 ( V_511 , V_512 , V_513 ) ;
F_177 ( V_514 , V_467 , V_515 ) ;
F_177 ( V_516 , V_517 , V_516 ) ;
#undef F_177
F_35 ( V_63 , V_518 ,
V_488 ) ;
}
F_35 ( V_63 , V_519 , V_262 ) ;
F_35 ( V_63 , V_520 ,
V_468 -> V_521 == V_522 ?
V_523 :
V_524 ) ;
F_35 ( V_63 , V_525 ,
V_526 ) ;
F_35 ( V_63 , V_527 , V_468 -> V_521 ) ;
F_35 ( V_63 , V_528 ,
( V_468 -> V_125 & V_529 ) ?
V_530 :
V_531 ) ;
if ( V_468 -> V_125 & V_529 )
F_35 ( V_63 , V_532 ,
V_468 -> V_533 !=
V_534 ?
V_468 -> V_533 : V_14 -> V_46 ) ;
}
static int F_178 ( struct V_1 * V_2 ,
const struct V_461 * V_468 ,
T_6 * V_482 , bool V_483 )
{
F_7 ( V_63 , V_484 ) ;
F_7 ( V_11 , V_535 ) ;
int V_16 ;
F_175 ( V_2 , V_468 , V_63 , * V_482 , V_483 ) ;
V_16 = F_9 ( V_2 , V_536 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , NULL ) ;
if ( V_16 == 0 )
* V_482 = F_179 ( V_11 , V_537 ) ;
return V_16 ;
}
static int F_180 ( struct V_477 * V_478 ,
enum V_538 V_464 )
{
unsigned int V_539 ;
for ( V_539 = 0 ;
V_539 < V_478 -> V_540 ;
V_539 ++ )
if ( V_478 -> V_541 [ V_539 ] == V_464 )
return V_539 ;
return - V_542 ;
}
static T_15 F_181 ( struct V_1 * V_2 ,
struct V_461 * V_468 ,
bool V_543 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
F_60 ( V_545 , V_546 ) ;
struct V_461 * V_547 ;
unsigned int V_539 , V_548 ;
unsigned int V_549 ;
bool V_483 = false ;
int V_550 = - 1 ;
F_182 ( V_551 ) ;
bool V_552 ;
T_15 V_16 ;
if ( ( V_468 -> V_125 & ( V_465 | V_466 ) ) !=
V_465 )
return - V_136 ;
V_16 = F_180 ( V_478 , V_468 -> V_464 ) ;
if ( V_16 < 0 )
return V_16 ;
V_539 = V_16 ;
V_548 = F_166 ( V_468 ) ;
V_552 = F_183 ( V_468 ) ;
if ( V_552 )
F_184 ( V_545 , V_546 ) ;
for (; ; ) {
unsigned int V_553 = 1 ;
unsigned int V_37 ;
F_185 ( & V_2 -> V_554 ) ;
for (; ; ) {
V_37 = ( V_548 + V_553 ) & ( V_555 - 1 ) ;
V_547 = F_172 ( V_478 , V_37 ) ;
if ( ! V_547 ) {
if ( V_550 < 0 )
V_550 = V_37 ;
} else if ( F_164 ( V_468 , V_547 ) ) {
if ( V_478 -> V_480 [ V_37 ] . V_468 &
V_556 )
break;
if ( V_468 -> V_557 < V_547 -> V_557 &&
! ( V_547 -> V_557 ==
V_558 &&
V_547 -> V_125 &
V_559 ) ) {
V_16 = - V_560 ;
goto V_561;
}
if ( ! V_552 ) {
if ( V_468 -> V_557 ==
V_547 -> V_557 &&
! V_543 ) {
V_16 = - V_562 ;
goto V_561;
}
V_550 = V_37 ;
goto V_563;
} else if ( V_468 -> V_557 >
V_547 -> V_557 ||
( V_468 -> V_557 ==
V_547 -> V_557 &&
V_543 ) ) {
if ( V_550 < 0 )
V_550 = V_37 ;
else
F_186 ( V_553 , V_545 ) ;
}
}
if ( V_553 == V_546 ) {
if ( V_550 < 0 ) {
V_16 = - V_564 ;
goto V_561;
}
goto V_563;
}
++ V_553 ;
}
F_187 ( & V_478 -> V_565 , & V_551 , V_566 ) ;
F_188 ( & V_2 -> V_554 ) ;
F_189 () ;
}
V_563:
V_547 = F_172 ( V_478 , V_550 ) ;
if ( V_547 ) {
if ( V_468 -> V_125 & V_559 ) {
V_547 -> V_125 |= V_559 ;
V_478 -> V_480 [ V_550 ] . V_468 &=
~ V_567 ;
V_16 = V_550 ;
goto V_561;
}
V_483 = true ;
V_549 = F_173 ( V_478 , V_550 ) ;
} else {
V_547 = F_190 ( sizeof( * V_468 ) , V_568 ) ;
if ( ! V_547 ) {
V_16 = - V_40 ;
goto V_561;
}
* V_547 = * V_468 ;
V_549 = 0 ;
}
F_174 ( V_478 , V_550 , V_547 ,
V_549 | V_556 ) ;
if ( V_552 ) {
unsigned int V_553 , V_37 ;
for ( V_553 = 0 ; V_553 < V_546 ; V_553 ++ ) {
V_37 = ( V_548 + V_553 ) & ( V_555 - 1 ) ;
if ( F_191 ( V_553 , V_545 ) )
V_478 -> V_480 [ V_37 ] . V_468 |=
V_556 ;
}
}
F_188 ( & V_2 -> V_554 ) ;
V_16 = F_178 ( V_2 , V_468 , & V_478 -> V_480 [ V_550 ] . V_482 ,
V_483 ) ;
F_185 ( & V_2 -> V_554 ) ;
if ( V_16 == 0 ) {
if ( V_483 ) {
V_547 -> V_557 = V_468 -> V_557 ;
V_547 -> V_125 &= V_559 ;
V_547 -> V_125 |= V_468 -> V_125 ;
V_547 -> V_533 = V_468 -> V_533 ;
V_547 -> V_521 = V_468 -> V_521 ;
}
} else if ( ! V_483 ) {
F_32 ( V_547 ) ;
V_547 = NULL ;
}
F_174 ( V_478 , V_550 , V_547 , V_549 ) ;
if ( V_552 ) {
F_7 ( V_63 , V_484 ) ;
unsigned int V_553 , V_37 ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
for ( V_553 = 0 ; V_553 < V_546 ; V_553 ++ ) {
if ( ! F_191 ( V_553 , V_545 ) )
continue;
V_37 = ( V_548 + V_553 ) & ( V_555 - 1 ) ;
V_547 = F_172 ( V_478 , V_37 ) ;
V_549 = F_173 ( V_478 , V_37 ) ;
if ( V_16 == 0 ) {
F_188 ( & V_2 -> V_554 ) ;
F_35 ( V_63 , V_485 ,
V_569 ) ;
F_176 ( V_63 , V_487 ,
V_478 -> V_480 [ V_37 ] . V_482 ) ;
V_16 = F_9 ( V_2 , V_536 ,
V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
F_185 ( & V_2 -> V_554 ) ;
}
if ( V_16 == 0 ) {
F_32 ( V_547 ) ;
V_547 = NULL ;
V_549 = 0 ;
} else {
V_549 &= ~ V_556 ;
}
F_174 ( V_478 , V_37 , V_547 ,
V_549 ) ;
}
}
if ( V_16 == 0 )
V_16 = V_539 * V_555 + V_550 ;
F_192 ( & V_478 -> V_565 ) ;
V_561:
F_188 ( & V_2 -> V_554 ) ;
F_193 ( & V_478 -> V_565 , & V_551 ) ;
return V_16 ;
}
static void F_194 ( struct V_1 * V_2 )
{
}
static int F_195 ( struct V_1 * V_2 ,
enum V_570 V_557 ,
T_5 V_571 , bool V_572 )
{
unsigned int V_479 = V_571 % V_555 ;
struct V_477 * V_478 = V_2 -> V_544 ;
F_7 ( V_63 ,
V_573 +
V_574 ) ;
struct V_461 * V_468 ;
F_182 ( V_551 ) ;
int V_16 ;
for (; ; ) {
F_185 ( & V_2 -> V_554 ) ;
if ( ! ( V_478 -> V_480 [ V_479 ] . V_468 &
V_556 ) )
break;
F_187 ( & V_478 -> V_565 , & V_551 , V_566 ) ;
F_188 ( & V_2 -> V_554 ) ;
F_189 () ;
}
V_468 = F_172 ( V_478 , V_479 ) ;
if ( ! V_468 || V_468 -> V_557 > V_557 ||
( ! V_572 &&
F_180 ( V_478 , V_468 -> V_464 ) !=
V_571 / V_555 ) ) {
V_16 = - V_60 ;
goto V_561;
}
V_478 -> V_480 [ V_479 ] . V_468 |= V_556 ;
F_188 ( & V_2 -> V_554 ) ;
if ( V_468 -> V_125 & V_559 && ! V_572 ) {
struct V_461 V_575 = * V_468 ;
V_575 . V_557 = V_558 ;
V_575 . V_125 = ( V_465 |
V_529 |
V_559 ) ;
V_575 . V_521 = 0 ;
V_575 . V_533 = V_534 ;
V_16 = F_178 ( V_2 , & V_575 ,
& V_478 -> V_480 [ V_479 ] . V_482 ,
true ) ;
F_185 ( & V_2 -> V_554 ) ;
if ( V_16 == 0 )
* V_468 = V_575 ;
} else {
F_35 ( V_63 , V_485 ,
F_168 ( V_468 ) ?
V_576 :
V_569 ) ;
F_176 ( V_63 , V_487 ,
V_478 -> V_480 [ V_479 ] . V_482 ) ;
V_16 = F_9 ( V_2 , V_536 ,
V_63 , sizeof( V_63 ) , NULL , 0 , NULL ) ;
F_185 ( & V_2 -> V_554 ) ;
if ( V_16 == 0 ) {
F_32 ( V_468 ) ;
F_174 ( V_478 , V_479 , NULL , 0 ) ;
}
}
V_478 -> V_480 [ V_479 ] . V_468 &= ~ V_556 ;
F_192 ( & V_478 -> V_565 ) ;
V_561:
F_188 ( & V_2 -> V_554 ) ;
F_193 ( & V_478 -> V_565 , & V_551 ) ;
return V_16 ;
}
static int F_196 ( struct V_1 * V_2 ,
enum V_570 V_557 ,
T_5 V_571 )
{
return F_195 ( V_2 , V_557 , V_571 , false ) ;
}
static int F_197 ( struct V_1 * V_2 ,
enum V_570 V_557 ,
T_5 V_571 , struct V_461 * V_468 )
{
unsigned int V_479 = V_571 % V_555 ;
struct V_477 * V_478 = V_2 -> V_544 ;
const struct V_461 * V_547 ;
int V_16 ;
F_185 ( & V_2 -> V_554 ) ;
V_547 = F_172 ( V_478 , V_479 ) ;
if ( V_547 && V_547 -> V_557 == V_557 &&
F_180 ( V_478 , V_547 -> V_464 ) ==
V_571 / V_555 ) {
* V_468 = * V_547 ;
V_16 = 0 ;
} else {
V_16 = - V_60 ;
}
F_188 ( & V_2 -> V_554 ) ;
return V_16 ;
}
static void F_198 ( struct V_1 * V_2 ,
enum V_570 V_557 )
{
}
static T_5 F_199 ( struct V_1 * V_2 ,
enum V_570 V_557 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
unsigned int V_479 ;
T_15 V_577 = 0 ;
F_185 ( & V_2 -> V_554 ) ;
for ( V_479 = 0 ; V_479 < V_555 ; V_479 ++ ) {
if ( V_478 -> V_480 [ V_479 ] . V_468 &&
F_172 ( V_478 , V_479 ) -> V_557 ==
V_557 )
++ V_577 ;
}
F_188 ( & V_2 -> V_554 ) ;
return V_577 ;
}
static T_5 F_200 ( struct V_1 * V_2 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
return V_478 -> V_540 * V_555 ;
}
static T_15 F_201 ( struct V_1 * V_2 ,
enum V_570 V_557 ,
T_5 * V_237 , T_5 V_578 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
struct V_461 * V_468 ;
unsigned int V_479 ;
T_15 V_577 = 0 ;
F_185 ( & V_2 -> V_554 ) ;
for ( V_479 = 0 ; V_479 < V_555 ; V_479 ++ ) {
V_468 = F_172 ( V_478 , V_479 ) ;
if ( V_468 && V_468 -> V_557 == V_557 ) {
if ( V_577 == V_578 ) {
V_577 = - V_579 ;
break;
}
V_237 [ V_577 ++ ] = ( F_180 (
V_478 , V_468 -> V_464 ) *
V_555 +
V_479 ) ;
}
}
F_188 ( & V_2 -> V_554 ) ;
return V_577 ;
}
static T_15 F_202 ( struct V_1 * V_2 ,
struct V_461 * V_468 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
F_7 ( V_63 , V_484 ) ;
struct V_461 * V_547 ;
unsigned int V_548 , V_37 , V_553 = 1 ;
bool V_483 = false ;
int V_550 = - 1 ;
T_6 V_353 ;
T_15 V_16 ;
F_203 ( V_468 -> V_125 !=
( V_465 | V_580 ) ) ;
F_203 ( V_468 -> V_557 != V_581 ) ;
F_203 ( F_183 ( V_468 ) ) ;
V_548 = F_166 ( V_468 ) ;
F_185 ( & V_2 -> V_554 ) ;
for (; ; ) {
V_37 = ( V_548 + V_553 ) & ( V_555 - 1 ) ;
V_547 = F_172 ( V_478 , V_37 ) ;
if ( ! V_547 ) {
if ( V_550 < 0 )
V_550 = V_37 ;
} else if ( F_164 ( V_468 , V_547 ) ) {
if ( V_478 -> V_480 [ V_37 ] . V_468 & V_556 ) {
V_16 = - V_564 ;
goto V_582;
}
F_203 ( V_547 -> V_125 &
V_559 ) ;
if ( V_468 -> V_557 < V_547 -> V_557 ) {
V_16 = - V_560 ;
goto V_582;
}
V_550 = V_37 ;
break;
}
if ( V_553 == V_546 ) {
if ( V_550 < 0 ) {
V_16 = - V_564 ;
goto V_582;
}
break;
}
++ V_553 ;
}
V_547 = F_172 ( V_478 , V_550 ) ;
if ( V_547 ) {
V_483 = true ;
} else {
V_547 = F_190 ( sizeof( * V_468 ) , V_568 ) ;
if ( ! V_547 ) {
V_16 = - V_40 ;
goto V_582;
}
* V_547 = * V_468 ;
}
F_174 ( V_478 , V_550 , V_547 ,
V_556 ) ;
F_188 ( & V_2 -> V_554 ) ;
V_353 = V_483 << 31 | V_550 << 16 | V_468 -> V_521 ;
F_175 ( V_2 , V_468 , V_63 ,
V_478 -> V_480 [ V_550 ] . V_482 , V_483 ) ;
F_124 ( V_2 , V_536 , V_63 , sizeof( V_63 ) ,
V_535 ,
V_583 , V_353 ) ;
return V_550 ;
V_582:
F_188 ( & V_2 -> V_554 ) ;
return V_16 ;
}
static void
V_583 ( struct V_1 * V_2 , unsigned long V_353 ,
int V_16 , T_1 * V_11 ,
T_2 V_354 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
unsigned int V_550 , V_521 ;
struct V_461 * V_468 ;
bool V_483 ;
V_483 = V_353 >> 31 ;
V_550 = ( V_353 >> 16 ) & ( V_555 - 1 ) ;
V_521 = V_353 & 0xffff ;
F_185 ( & V_2 -> V_554 ) ;
V_468 = F_172 ( V_478 , V_550 ) ;
if ( V_16 == 0 ) {
V_478 -> V_480 [ V_550 ] . V_482 =
F_179 ( V_11 , V_537 ) ;
if ( V_483 )
V_468 -> V_521 = V_521 ;
} else if ( ! V_483 ) {
F_32 ( V_468 ) ;
V_468 = NULL ;
}
F_174 ( V_478 , V_550 , V_468 , 0 ) ;
F_188 ( & V_2 -> V_554 ) ;
F_192 ( & V_478 -> V_565 ) ;
}
static bool F_204 ( struct V_1 * V_2 , T_5 V_584 ,
unsigned int V_479 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
struct V_461 * V_468 =
F_172 ( V_478 , V_479 ) ;
F_7 ( V_63 ,
V_573 +
V_574 ) ;
if ( ! V_468 ||
( V_478 -> V_480 [ V_479 ] . V_468 & V_556 ) ||
V_468 -> V_557 != V_581 ||
! F_205 ( V_2 -> V_20 , V_468 -> V_521 ,
V_584 , V_479 ) )
return false ;
F_35 ( V_63 , V_485 ,
V_576 ) ;
F_176 ( V_63 , V_487 ,
V_478 -> V_480 [ V_479 ] . V_482 ) ;
if ( F_124 ( V_2 , V_536 , V_63 , sizeof( V_63 ) , 0 ,
V_585 , V_479 ) )
return false ;
V_478 -> V_480 [ V_479 ] . V_468 |= V_556 ;
return true ;
}
static void
V_585 ( struct V_1 * V_2 ,
unsigned long V_479 ,
int V_16 , T_1 * V_11 ,
T_2 V_354 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
struct V_461 * V_468 =
F_172 ( V_478 , V_479 ) ;
F_185 ( & V_2 -> V_554 ) ;
if ( V_16 == 0 ) {
F_32 ( V_468 ) ;
F_174 ( V_478 , V_479 , NULL , 0 ) ;
}
V_478 -> V_480 [ V_479 ] . V_468 &= ~ V_556 ;
F_192 ( & V_478 -> V_565 ) ;
F_188 ( & V_2 -> V_554 ) ;
}
static int F_206 ( T_5 V_586 )
{
int V_464 = 0 ;
#define F_207 ( T_12 , T_14 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_207 ( V_587 , V_588 ) ;
F_207 ( V_587 , V_589 ) ;
F_207 ( V_494 , V_496 ) ;
F_207 ( V_497 , V_498 ) ;
F_207 ( V_499 , V_501 ) ;
F_207 ( V_502 , V_504 ) ;
F_207 ( V_505 , V_506 ) ;
F_207 ( V_507 , V_509 ) ;
F_207 ( V_510 , V_510 ) ;
F_207 ( V_511 , V_513 ) ;
F_207 ( V_514 , V_515 ) ;
F_207 ( V_516 , V_516 ) ;
#undef F_207
if ( V_586 )
return - V_136 ;
return V_464 ;
}
static int F_208 ( struct V_1 * V_2 )
{
F_7 ( V_63 , V_590 ) ;
F_7 ( V_11 , V_591 ) ;
unsigned int V_592 , V_593 ;
struct V_477 * V_478 ;
T_2 V_15 ;
int V_16 ;
V_478 = F_18 ( sizeof( * V_478 ) , V_39 ) ;
if ( ! V_478 )
return - V_40 ;
F_35 ( V_63 , V_594 ,
V_595 ) ;
V_16 = F_9 ( V_2 , V_596 ,
V_63 , sizeof( V_63 ) , V_11 , sizeof( V_11 ) ,
& V_15 ) ;
if ( V_16 )
goto V_89;
V_593 = F_209 (
V_15 , V_597 ) ;
V_478 -> V_540 = 0 ;
for ( V_592 = 0 ; V_592 < V_593 ; V_592 ++ ) {
T_5 V_586 =
F_210 (
V_11 ,
V_597 ,
V_592 ) ;
V_16 = F_206 ( V_586 ) ;
if ( V_16 < 0 ) {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_36 ,
V_274 , V_586 , V_592 ) ;
} else {
F_28 ( V_2 , V_26 , V_2 -> V_20 ,
L_37 ,
V_274 , V_586 , V_592 ,
V_16 , V_478 -> V_540 ) ;
V_478 -> V_541 [ V_478 -> V_540 ++ ] = V_16 ;
}
}
V_478 -> V_480 = F_211 ( V_555 * sizeof( * V_478 -> V_480 ) ) ;
if ( ! V_478 -> V_480 ) {
V_16 = - V_40 ;
goto V_89;
}
V_2 -> V_544 = V_478 ;
F_212 ( & V_478 -> V_565 ) ;
return 0 ;
V_89:
F_32 ( V_478 ) ;
return V_16 ;
}
static void F_213 ( struct V_1 * V_2 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_461 * V_468 ;
unsigned int V_479 ;
bool V_598 = false ;
int V_16 ;
if ( ! V_14 -> V_216 )
return;
F_185 ( & V_2 -> V_554 ) ;
for ( V_479 = 0 ; V_479 < V_555 ; V_479 ++ ) {
V_468 = F_172 ( V_478 , V_479 ) ;
if ( ! V_468 )
continue;
V_478 -> V_480 [ V_479 ] . V_468 |= V_556 ;
F_188 ( & V_2 -> V_554 ) ;
V_16 = F_178 ( V_2 , V_468 ,
& V_478 -> V_480 [ V_479 ] . V_482 ,
false ) ;
if ( V_16 )
V_598 = true ;
F_185 ( & V_2 -> V_554 ) ;
if ( V_16 ) {
F_32 ( V_468 ) ;
F_174 ( V_478 , V_479 , NULL , 0 ) ;
} else {
V_478 -> V_480 [ V_479 ] . V_468 &=
~ V_556 ;
}
}
F_188 ( & V_2 -> V_554 ) ;
if ( V_598 )
F_10 ( V_2 , V_263 , V_2 -> V_20 ,
L_38 ) ;
else
V_14 -> V_216 = false ;
}
static void F_214 ( struct V_1 * V_2 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
F_7 ( V_63 , V_484 ) ;
struct V_461 * V_468 ;
unsigned int V_479 ;
int V_16 ;
for ( V_479 = 0 ; V_479 < V_555 ; V_479 ++ ) {
V_468 = F_172 ( V_478 , V_479 ) ;
if ( ! V_468 )
continue;
F_35 ( V_63 , V_485 ,
F_168 ( V_468 ) ?
V_576 :
V_569 ) ;
F_176 ( V_63 , V_487 ,
V_478 -> V_480 [ V_479 ] . V_482 ) ;
V_16 = F_9 ( V_2 , V_536 , V_63 , sizeof( V_63 ) ,
NULL , 0 , NULL ) ;
F_36 ( V_16 != 0 ) ;
F_32 ( V_468 ) ;
}
F_215 ( V_478 -> V_480 ) ;
F_32 ( V_478 ) ;
}
static void F_216 ( struct V_1 * V_2 )
{
struct V_477 * V_478 = V_2 -> V_544 ;
struct V_599 * V_20 = V_2 -> V_20 ;
struct V_461 V_468 ;
bool V_600 = false ;
struct V_601 * V_602 ;
struct V_601 * V_603 ;
unsigned int V_479 ;
int V_37 , V_70 , V_16 ;
if ( ! F_217 ( V_2 ) )
return;
F_185 ( & V_2 -> V_554 ) ;
V_70 = V_478 -> V_604 < 0 ? 1 : V_478 -> V_604 ;
for ( V_37 = 0 ; V_37 < V_70 ; V_37 ++ ) {
V_479 = V_478 -> V_605 [ V_37 ] . V_606 % V_555 ;
V_478 -> V_480 [ V_479 ] . V_468 |= V_567 ;
}
V_70 = V_478 -> V_607 < 0 ? 1 : V_478 -> V_607 ;
for ( V_37 = 0 ; V_37 < V_70 ; V_37 ++ ) {
V_479 = V_478 -> V_608 [ V_37 ] . V_606 % V_555 ;
V_478 -> V_480 [ V_479 ] . V_468 |= V_567 ;
}
F_188 ( & V_2 -> V_554 ) ;
F_218 ( V_20 ) ;
if ( V_20 -> V_125 & V_609 ||
F_219 ( V_20 ) >= V_610 ) {
V_478 -> V_604 = - 1 ;
} else {
V_478 -> V_604 = 1 + F_219 ( V_20 ) ;
memcpy ( V_478 -> V_605 [ 0 ] . V_155 , V_20 -> V_611 ,
V_36 ) ;
V_37 = 1 ;
F_220 (uc, net_dev) {
memcpy ( V_478 -> V_605 [ V_37 ] . V_155 ,
V_602 -> V_155 , V_36 ) ;
V_37 ++ ;
}
}
if ( V_20 -> V_125 & ( V_609 | V_612 ) ||
F_221 ( V_20 ) >= V_613 ) {
V_478 -> V_607 = - 1 ;
} else {
V_478 -> V_607 = 1 + F_221 ( V_20 ) ;
F_222 ( V_478 -> V_608 [ 0 ] . V_155 ) ;
V_37 = 1 ;
F_223 (mc, net_dev) {
memcpy ( V_478 -> V_608 [ V_37 ] . V_155 ,
V_603 -> V_155 , V_36 ) ;
V_37 ++ ;
}
}
F_224 ( V_20 ) ;
if ( V_478 -> V_604 >= 0 ) {
for ( V_37 = 0 ; V_37 < V_478 -> V_604 ; V_37 ++ ) {
F_225 ( & V_468 , V_558 ,
V_529 |
V_559 ,
0 ) ;
F_226 ( & V_468 , V_614 ,
V_478 -> V_605 [ V_37 ] . V_155 ) ;
V_16 = F_181 ( V_2 , & V_468 , true ) ;
if ( V_16 < 0 ) {
while ( V_37 -- )
F_196 (
V_2 , V_558 ,
V_478 -> V_605 [ V_37 ] . V_606 ) ;
V_478 -> V_604 = - 1 ;
break;
}
V_478 -> V_605 [ V_37 ] . V_606 = V_16 ;
}
}
if ( V_478 -> V_604 < 0 ) {
F_225 ( & V_468 , V_558 ,
V_529 |
V_559 ,
0 ) ;
F_227 ( & V_468 ) ;
V_16 = F_181 ( V_2 , & V_468 , true ) ;
if ( V_16 < 0 ) {
F_36 ( 1 ) ;
V_478 -> V_604 = 0 ;
} else {
V_478 -> V_605 [ 0 ] . V_606 = V_16 ;
}
}
if ( V_478 -> V_607 >= 0 ) {
for ( V_37 = 0 ; V_37 < V_478 -> V_607 ; V_37 ++ ) {
F_225 ( & V_468 , V_558 ,
V_529 |
V_559 ,
0 ) ;
F_226 ( & V_468 , V_614 ,
V_478 -> V_608 [ V_37 ] . V_155 ) ;
V_16 = F_181 ( V_2 , & V_468 , true ) ;
if ( V_16 < 0 ) {
while ( V_37 -- )
F_196 (
V_2 , V_558 ,
V_478 -> V_608 [ V_37 ] . V_606 ) ;
V_478 -> V_607 = - 1 ;
break;
}
V_478 -> V_608 [ V_37 ] . V_606 = V_16 ;
}
}
if ( V_478 -> V_607 < 0 ) {
F_225 ( & V_468 , V_558 ,
V_529 |
V_559 ,
0 ) ;
F_228 ( & V_468 ) ;
V_16 = F_181 ( V_2 , & V_468 , true ) ;
if ( V_16 < 0 ) {
F_36 ( 1 ) ;
V_478 -> V_607 = 0 ;
} else {
V_478 -> V_608 [ 0 ] . V_606 = V_16 ;
}
}
for ( V_37 = 0 ; V_37 < V_555 ; V_37 ++ ) {
if ( F_85 ( V_478 -> V_480 [ V_37 ] . V_468 ) &
V_567 ) {
if ( F_195 ( V_2 ,
V_558 ,
V_37 , true ) < 0 )
V_600 = true ;
}
}
F_36 ( V_600 ) ;
}
static int F_229 ( struct V_1 * V_2 )
{
F_216 ( V_2 ) ;
return F_230 ( V_2 ) ;
}
static int F_231 ( struct V_1 * V_2 ,
struct V_615 * V_616 ,
unsigned int type )
{
F_7 ( V_63 , V_617 ) ;
F_7 ( V_11 , V_618 ) ;
const struct V_619 * V_620 ;
T_2 V_578 , V_621 , V_15 ;
bool V_622 ;
int V_16 ;
for ( V_620 = V_623 ; ; V_620 ++ ) {
if ( V_620 ==
V_623 + F_110 ( V_623 ) )
return - V_24 ;
if ( ( type & ~ V_620 -> V_624 ) == V_620 -> type )
break;
}
if ( V_620 -> V_625 != F_232 ( V_2 ) )
return - V_24 ;
V_16 = F_233 ( V_2 , type , & V_578 , & V_621 , & V_622 ) ;
if ( V_16 )
return V_16 ;
if ( V_622 )
return - V_24 ;
V_616 -> V_626 = type ;
F_35 ( V_63 , V_627 , type ) ;
V_16 = F_9 ( V_2 , V_628 , V_63 , sizeof( V_63 ) ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_629 )
return - V_7 ;
if ( F_11 ( V_11 , V_630 ) &
( 1 << V_631 ) )
V_616 -> V_632 = F_11 ( V_11 ,
V_633 ) ;
V_616 -> V_634 . V_635 = L_39 ;
V_616 -> V_634 . V_636 = V_620 -> V_169 ;
V_616 -> V_634 . V_637 . type = V_638 ;
V_616 -> V_634 . V_637 . V_125 = V_639 ;
V_616 -> V_634 . V_637 . V_578 = V_578 ;
V_616 -> V_634 . V_637 . V_640 = V_621 ;
return 0 ;
}
static int F_234 ( struct V_1 * V_2 )
{
F_7 ( V_11 , V_641 ) ;
struct V_615 * V_642 ;
T_2 V_15 , V_643 , V_37 , V_644 ;
unsigned int type ;
int V_16 ;
F_235 () ;
F_8 ( V_645 != 0 ) ;
V_16 = F_9 ( V_2 , V_646 , NULL , 0 ,
V_11 , sizeof( V_11 ) , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 < V_647 )
return - V_7 ;
V_643 = F_11 ( V_11 , V_648 ) ;
if ( V_643 >
F_209 ( V_15 , V_649 ) )
return - V_7 ;
V_642 = F_236 ( V_643 , sizeof( * V_642 ) , V_39 ) ;
if ( ! V_642 )
return - V_40 ;
V_644 = 0 ;
for ( V_37 = 0 ; V_37 < V_643 ; V_37 ++ ) {
type = F_210 ( V_11 , V_649 ,
V_37 ) ;
V_16 = F_231 ( V_2 , & V_642 [ V_644 ] , type ) ;
if ( V_16 == 0 )
V_644 ++ ;
else if ( V_16 != - V_24 )
goto V_89;
}
V_16 = F_237 ( V_2 , & V_642 [ 0 ] . V_634 , V_644 , sizeof( * V_642 ) ) ;
V_89:
if ( V_16 )
F_32 ( V_642 ) ;
return V_16 ;
}
static void F_238 ( struct V_1 * V_2 , T_5 V_650 )
{
F_21 ( V_2 , F_22 ( V_650 ) , V_214 ) ;
}
