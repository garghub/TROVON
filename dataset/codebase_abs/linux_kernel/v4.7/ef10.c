static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , & V_3 , V_4 ) ;
return F_3 ( V_3 , V_5 ) == 0xb007 ?
F_3 ( V_3 , V_6 ) : - V_7 ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = V_2 -> type -> V_9 ;
return F_5 ( & V_2 -> V_10 -> V_11 [ V_8 ] ) ;
}
static bool F_6 ( struct V_1 * V_2 )
{
return V_2 -> type -> V_12 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_14 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
V_18 = F_9 ( V_2 , V_19 , NULL , 0 , V_13 ,
sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < sizeof( V_13 ) )
return - V_7 ;
V_16 -> V_20 = F_10 ( V_13 , V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_14 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
V_18 = F_9 ( V_2 , V_19 , NULL , 0 , V_13 ,
sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < sizeof( V_13 ) )
return - V_7 ;
V_16 -> V_22 = F_10 ( V_13 , V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_24 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
F_13 ( V_25 != 0 ) ;
V_18 = F_9 ( V_2 , V_26 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < sizeof( V_13 ) ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_1 ) ;
return - V_7 ;
}
V_16 -> V_29 =
F_10 ( V_13 , V_30 ) ;
V_16 -> V_31 =
F_15 ( V_13 , V_32 ) ;
V_16 -> V_33 =
F_15 ( V_13 , V_34 ) ;
if ( ! ( V_16 -> V_29 &
( 1 << V_35 ) ) ) {
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_2 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_38 ) ;
int V_18 ;
V_18 = F_9 ( V_2 , V_39 , NULL , 0 ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 )
return V_18 ;
V_18 = F_10 ( V_13 , V_40 ) ;
return V_18 > 0 ? V_18 : - V_41 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_42 )
{
F_8 ( V_13 , V_43 ) ;
T_2 V_17 ;
int V_18 ;
F_13 ( V_44 != 0 ) ;
V_18 = F_9 ( V_2 , V_45 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_43 )
return - V_7 ;
F_18 ( V_42 ,
F_19 ( V_13 , V_46 ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 * V_42 )
{
F_8 ( V_47 , V_48 ) ;
F_8 ( V_13 , V_49 ) ;
T_2 V_17 ;
int V_50 , V_18 ;
F_21 ( V_47 , V_51 ,
V_52 ) ;
V_18 = F_9 ( V_2 , V_53 , V_47 ,
sizeof( V_47 ) , V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_54 )
return - V_7 ;
V_50 = F_10 ( V_13 ,
V_55 ) ;
F_22 ( V_50 != 1 ) ;
F_18 ( V_42 ,
F_19 ( V_13 , V_56 ) ) ;
return 0 ;
}
static T_4 F_23 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
char * V_61 )
{
struct V_1 * V_2 = F_24 ( F_25 ( V_58 ) ) ;
return sprintf ( V_61 , L_3 ,
( ( V_2 -> V_62 -> V_63 ) &
( 1 << V_64 ) )
? 1 : 0 ) ;
}
static T_4 F_26 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
char * V_61 )
{
struct V_1 * V_2 = F_24 ( F_25 ( V_58 ) ) ;
return sprintf ( V_61 , L_3 ,
( ( V_2 -> V_62 -> V_63 ) &
( 1 << V_65 ) )
? 1 : 0 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_66 * V_28 = V_2 -> V_28 ;
int V_67 , V_18 ;
V_2 -> V_68 = F_28 (unsigned int,
EFX_MAX_CHANNELS,
efx_ef10_mem_map_size(efx) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
V_2 -> V_69 = V_2 -> V_68 ;
if ( F_22 ( V_2 -> V_68 == 0 ) )
return - V_7 ;
V_16 = F_29 ( sizeof( * V_16 ) , V_70 ) ;
if ( ! V_16 )
return - V_71 ;
V_2 -> V_16 = V_16 ;
F_13 ( V_72 % 4 ) ;
V_18 = F_30 ( V_2 , & V_16 -> V_73 ,
8 + V_72 , V_70 ) ;
if ( V_18 )
goto V_74;
V_67 = 0 ;
for (; ; ) {
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 )
break;
if ( ++ V_67 == 5 )
goto V_75;
F_31 ( 1 ) ;
}
V_16 -> V_76 = V_18 ;
V_16 -> V_77 = V_78 ;
V_16 -> V_79 = V_52 ;
F_32 ( V_2 , F_33 ( 1 ) , V_80 ) ;
V_18 = F_34 ( V_2 ) ;
if ( V_18 )
goto V_75;
V_18 = F_35 ( V_2 , V_81 ) ;
if ( V_18 )
goto V_82;
V_18 = F_36 ( V_2 , true , false , 0 ) ;
if ( V_18 )
goto V_82;
V_18 = F_37 ( & V_2 -> V_10 -> V_58 ,
& V_83 ) ;
if ( V_18 )
goto V_82;
V_18 = F_37 ( & V_2 -> V_10 -> V_58 , & V_84 ) ;
if ( V_18 )
goto V_85;
V_18 = F_7 ( V_2 ) ;
if ( V_18 )
goto V_86;
V_18 = F_12 ( V_2 ) ;
if ( V_18 < 0 )
goto V_86;
V_2 -> V_87 =
V_88 - V_89 ;
V_18 = F_38 ( V_2 ) ;
if ( V_18 < 0 )
goto V_86;
V_2 -> V_90 = V_18 ;
V_28 -> V_91 = V_18 ;
V_18 = V_2 -> type -> V_92 ( V_2 , V_2 -> V_28 -> V_93 ) ;
if ( V_18 )
goto V_86;
V_18 = F_16 ( V_2 ) ;
if ( V_18 < 0 )
goto V_86;
V_2 -> V_94 = 1536000 / V_18 ;
V_18 = F_39 ( V_2 , V_95 , true , NULL ) ;
if ( V_18 == 0 ) {
V_16 -> V_96 = true ;
} else if ( V_18 == - V_97 ) {
unsigned int V_98 ;
V_18 = F_40 ( V_2 , NULL , & V_98 ) ;
if ( V_18 )
goto V_82;
V_16 -> V_96 = V_98 &
V_99 ;
} else if ( V_18 != - V_100 && V_18 != - V_101 ) {
goto V_86;
}
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_4 ,
V_16 -> V_96 ? L_5 : L_6 ) ;
V_18 = F_42 ( V_2 ) ;
if ( V_18 && V_18 != - V_97 )
goto V_86;
F_43 ( V_2 , NULL ) ;
#ifdef F_44
if ( ( V_2 -> V_10 -> V_102 ) && ( ! V_2 -> V_10 -> V_103 ) ) {
struct V_10 * V_104 = V_2 -> V_10 -> V_102 ;
struct V_1 * V_105 = F_24 ( V_104 ) ;
V_105 -> type -> V_92 ( V_105 , V_16 -> V_106 ) ;
} else
#endif
F_18 ( V_16 -> V_106 , V_2 -> V_28 -> V_93 ) ;
return 0 ;
V_86:
F_45 ( & V_2 -> V_10 -> V_58 , & V_84 ) ;
V_85:
F_45 ( & V_2 -> V_10 -> V_58 , & V_83 ) ;
V_82:
F_46 ( V_2 ) ;
V_75:
F_47 ( V_2 , & V_16 -> V_73 ) ;
V_74:
F_48 ( V_16 ) ;
V_2 -> V_16 = NULL ;
return V_18 ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_50 ( V_13 ) ;
T_2 V_17 ;
int V_18 = F_51 ( V_2 , V_107 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 == - V_108 )
V_18 = 0 ;
if ( V_18 )
F_52 ( V_2 , V_107 , 0 , V_13 , V_17 ,
V_18 ) ;
return V_18 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_47 , V_109 ) ;
unsigned int V_67 ;
int V_18 ;
F_13 ( V_110 != 0 ) ;
for ( V_67 = 0 ; V_67 < V_16 -> V_111 ; V_67 ++ ) {
F_21 ( V_47 , V_112 ,
V_16 -> V_113 [ V_67 ] ) ;
V_18 = F_9 ( V_2 , V_114 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 ) ;
}
V_16 -> V_111 = 0 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_115 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_13 , V_116 ) ;
unsigned int V_67 ;
T_2 V_17 ;
int V_18 = 0 ;
F_13 ( V_117 != 0 ) ;
for ( V_67 = 0 ; V_67 < V_115 ; V_67 ++ ) {
V_18 = F_51 ( V_2 , V_118 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 ) {
if ( ! ( F_6 ( V_2 ) && V_18 == - V_119 ) )
F_52 ( V_2 , V_118 ,
0 , V_13 , V_17 , V_18 ) ;
break;
}
if ( V_17 < V_116 ) {
V_18 = - V_7 ;
break;
}
V_16 -> V_113 [ V_67 ] =
F_10 ( V_13 , V_120 ) ;
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_7 , V_67 ,
V_16 -> V_113 [ V_67 ] ) ;
}
V_16 -> V_111 = V_67 ;
if ( V_18 )
F_53 ( V_2 ) ;
return V_18 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_56 ( V_47 ,
F_57 ( V_121 ,
V_122 ) ) ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
unsigned int V_127 , V_128 ;
int V_18 ;
F_13 ( V_129 != 0 ) ;
F_13 ( V_130 != 0 ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
for ( V_128 = 0 ; V_128 < V_16 -> V_111 ; ++ V_128 ) {
F_21 ( V_47 , V_131 ,
V_16 -> V_113 [ V_128 ] ) ;
F_21 ( V_47 , V_132 ,
V_16 -> V_133 + V_128 ) ;
V_18 = F_9 ( V_2 , V_134 ,
V_47 , V_121 ,
NULL , 0 , NULL ) ;
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_8 ,
V_16 -> V_133 + V_128 , V_128 ,
V_18 ) ;
goto V_135;
}
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_9 ,
V_16 -> V_133 + V_128 , V_128 ) ;
}
F_58 (channel, efx) {
F_59 (tx_queue, channel) {
V_127 = ( ( V_2 -> V_136 + V_2 -> V_137 -
V_126 -> V_124 -> V_124 - 1 ) *
V_138 ) ;
V_128 = V_127 / V_139 ;
V_127 = V_127 % V_139 ;
if ( V_126 -> V_140 == V_16 -> V_133 ) {
F_60 ( V_128 != 0 ) ;
V_18 = 0 ;
} else {
F_21 ( V_47 ,
V_131 ,
V_16 -> V_113 [ V_128 ] ) ;
F_21 ( V_47 ,
V_132 ,
V_126 -> V_140 ) ;
V_18 = F_9 ( V_2 , V_134 ,
V_47 , V_121 ,
NULL , 0 , NULL ) ;
}
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_8 ,
V_126 -> V_140 , V_128 , V_18 ) ;
V_126 -> V_141 = NULL ;
} else {
V_126 -> V_141 =
V_16 -> V_142 +
V_128 * V_143 + V_127 ;
V_126 -> V_144 = V_127 ;
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_10 ,
V_126 -> V_140 , V_128 ,
V_126 -> V_144 ,
V_126 -> V_141 ) ;
}
}
}
return 0 ;
V_135:
while ( V_128 -- ) {
F_21 ( V_47 , V_145 ,
V_16 -> V_133 + V_128 ) ;
F_9 ( V_2 , V_146 ,
V_47 , V_122 ,
NULL , 0 , NULL ) ;
}
return V_18 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_123 * V_124 ;
struct V_125 * V_126 ;
F_58 (channel, efx)
F_59 (tx_queue, channel)
V_126 -> V_141 = NULL ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_115 )
{
return V_115 == 0 ? 0 : - V_147 ;
}
static int F_55 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
}
static void F_61 ( struct V_1 * V_2 )
{
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
#ifdef F_44
struct V_15 * V_148 ;
struct V_10 * V_104 ;
struct V_1 * V_105 ;
struct V_149 * V_150 ;
if ( V_2 -> V_10 -> V_151 ) {
V_104 = V_2 -> V_10 -> V_102 ;
if ( V_104 ) {
V_105 = F_24 ( V_104 ) ;
V_148 = V_105 -> V_16 ;
V_150 = V_148 -> V_150 + V_16 -> V_22 ;
V_150 -> V_2 = NULL ;
} else
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_11 ) ;
}
#endif
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( V_16 -> V_152 )
F_67 ( V_16 -> V_152 ) ;
V_18 = F_49 ( V_2 ) ;
F_22 ( V_18 != 0 ) ;
if ( ! V_16 -> V_153 )
F_53 ( V_2 ) ;
F_45 ( & V_2 -> V_10 -> V_58 , & V_84 ) ;
F_45 ( & V_2 -> V_10 -> V_58 , & V_83 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 , & V_16 -> V_73 ) ;
F_48 ( V_16 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
return F_27 ( V_2 ) ;
}
int F_69 ( struct V_1 * V_2 , unsigned int V_106 )
{
F_8 ( V_47 , V_154 ) ;
F_21 ( V_47 , V_155 , V_106 ) ;
return F_9 ( V_2 , V_156 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
int F_70 ( struct V_1 * V_2 , unsigned int V_106 )
{
F_8 ( V_47 , V_157 ) ;
F_21 ( V_47 , V_158 , V_106 ) ;
return F_9 ( V_2 , V_159 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
int F_71 ( struct V_1 * V_2 ,
unsigned int V_106 , T_3 * V_160 )
{
F_8 ( V_47 , V_161 ) ;
F_21 ( V_47 , V_162 , V_106 ) ;
F_18 ( F_19 ( V_47 , V_163 ) , V_160 ) ;
return F_9 ( V_2 , V_164 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
int F_72 ( struct V_1 * V_2 ,
unsigned int V_106 , T_3 * V_160 )
{
F_8 ( V_47 , V_165 ) ;
F_21 ( V_47 , V_166 , V_106 ) ;
F_18 ( F_19 ( V_47 , V_167 ) , V_160 ) ;
return F_9 ( V_2 , V_168 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_10 * V_104 ;
V_104 = V_2 -> V_10 -> V_102 ;
if ( V_104 ) {
struct V_1 * V_105 = F_24 ( V_104 ) ;
struct V_15 * V_148 = V_105 -> V_16 ;
if ( ! V_148 -> V_150 ) {
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_12
L_13 ) ;
return - V_169 ;
}
}
V_18 = F_27 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
goto V_135;
if ( V_2 -> V_10 -> V_151 ) {
if ( V_2 -> V_10 -> V_102 ) {
struct V_1 * V_105 =
F_24 ( V_2 -> V_10 -> V_102 ) ;
struct V_15 * V_170 = V_105 -> V_16 ;
struct V_15 * V_16 = V_2 -> V_16 ;
V_170 -> V_150 [ V_16 -> V_22 ] . V_2 = V_2 ;
V_170 -> V_150 [ V_16 -> V_22 ] . V_10 =
V_2 -> V_10 ;
} else
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_11 ) ;
}
return 0 ;
V_135:
F_62 ( V_2 ) ;
return V_18 ;
}
static int F_74 ( struct V_1 * V_2 ,
unsigned int V_171 , unsigned int V_172 )
{
F_8 ( V_47 , V_173 ) ;
F_8 ( V_13 , V_174 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_175 , V_171 ) ;
F_21 ( V_47 , V_176 , V_172 ) ;
V_18 = F_9 ( V_2 , V_177 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_174 )
return - V_7 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_14 ,
F_10 ( V_13 , V_178 ) ) ;
V_16 -> V_179 = F_10 ( V_13 , V_178 ) ;
V_16 -> V_180 = F_10 ( V_13 , V_181 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_182 , V_183 ;
unsigned int V_171 = F_57 ( V_184 ,
V_185 ? 2 : 1 ) ;
unsigned int V_186 , V_133 , V_172 ;
void T_5 * V_187 ;
int V_18 ;
V_186 = F_57 ( V_2 -> V_188 , V_2 -> V_137 * V_184 ) ;
#ifdef F_76
if ( V_138 != 0 &&
V_139 / V_138 * V_189 >=
V_2 -> V_137 ) {
unsigned int V_111 =
F_77 ( V_2 -> V_137 ,
V_139 / V_138 ) ;
V_18 = F_54 ( V_2 , V_111 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_15 , V_18 ) ;
else
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_16 , V_111 ) ;
}
#else
V_16 -> V_111 = 0 ;
#endif
V_182 = F_78 ( ( V_186 - 1 ) * V_143 +
V_190 ) ;
if ( V_16 -> V_111 ) {
V_133 = V_182 / V_143 ;
V_183 = ( F_78 ( ( V_133 +
V_16 -> V_111 ) *
V_143 ) -
V_182 ) ;
V_172 = V_133 + V_16 -> V_111 ;
} else {
V_133 = 0 ;
V_183 = 0 ;
V_172 = V_186 ;
}
V_18 = F_49 ( V_2 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_74 ( V_2 , V_171 , V_172 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_16 -> V_180 < V_186 ) {
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_17
L_18 ) ;
V_2 -> V_68 = V_16 -> V_180 ;
V_2 -> V_69 =
V_16 -> V_180 / V_184 ;
F_49 ( V_2 ) ;
return - V_191 ;
}
if ( V_16 -> V_111 &&
V_16 -> V_180 <
V_133 + V_16 -> V_111 ) {
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_19 ,
V_16 -> V_180 , V_16 -> V_111 ) ;
F_53 ( V_2 ) ;
}
V_187 = F_79 ( V_2 -> V_192 , V_182 ) ;
if ( ! V_187 ) {
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_20 ,
V_182 ) ;
return - V_71 ;
}
F_67 ( V_2 -> V_187 ) ;
V_2 -> V_187 = V_187 ;
if ( V_183 ) {
V_16 -> V_152 = F_80 ( V_2 -> V_192 +
V_182 ,
V_183 ) ;
if ( ! V_16 -> V_152 ) {
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_21 ,
V_183 ) ;
return - V_71 ;
}
V_16 -> V_133 = V_133 ;
V_16 -> V_142 =
V_16 -> V_152 +
( V_133 * V_143 + V_190 -
V_182 ) ;
V_18 = F_55 ( V_2 ) ;
if ( V_18 )
F_53 ( V_2 ) ;
}
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_22 ,
& V_2 -> V_192 , V_2 -> V_187 , V_182 ,
V_16 -> V_152 , V_183 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
if ( V_16 -> V_193 ) {
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_193 = false ;
}
if ( V_16 -> V_194 ) {
V_18 = F_74 ( V_2 , V_16 -> V_180 ,
V_16 -> V_180 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_194 = false ;
}
if ( V_16 -> V_153 && V_16 -> V_111 ) {
V_18 = F_54 ( V_2 , V_16 -> V_111 ) ;
if ( V_18 == 0 ) {
V_18 = F_55 ( V_2 ) ;
if ( V_18 )
F_53 ( V_2 ) ;
}
if ( V_18 )
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_23 , V_18 ) ;
V_16 -> V_153 = false ;
}
V_2 -> type -> V_195 ( V_2 , false , V_2 -> V_196 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
#ifdef F_44
unsigned int V_67 ;
#endif
V_16 -> V_194 = true ;
V_16 -> V_197 = true ;
V_16 -> V_153 = true ;
F_61 ( V_2 ) ;
V_16 -> V_77 = V_78 ;
V_16 -> V_198 = true ;
V_16 -> V_79 = V_52 ;
#ifdef F_44
if ( V_16 -> V_150 )
for ( V_67 = 0 ; V_67 < V_2 -> V_199 ; V_67 ++ )
V_16 -> V_150 [ V_67 ] . V_79 = 0 ;
#endif
}
static enum V_200 F_83 ( enum V_200 V_201 )
{
if ( V_201 == V_202 )
return V_203 ;
return F_84 ( V_201 ) ;
}
static int F_85 ( T_6 * V_204 )
{
enum {
V_205 = ( ( V_206 | V_207 ) <<
V_208 ) ,
V_209 = ( ( V_210 | V_211 |
V_212 | V_206 |
V_207 | V_213 ) <<
V_208 )
};
if ( ( * V_204 & V_209 ) == V_209 ) {
* V_204 &= ~ V_209 ;
return V_214 ;
}
if ( ( * V_204 & V_205 ) == V_205 ) {
* V_204 &= ~ V_205 ;
return V_81 ;
}
return - V_215 ;
}
static int F_86 ( struct V_1 * V_2 , enum V_200 V_200 )
{
int V_18 = F_35 ( V_2 , V_200 ) ;
if ( V_200 == V_214 && V_18 == - V_97 )
V_18 = 0 ;
if ( ( V_200 == V_81 ||
V_200 == V_216 ) && ! V_18 )
F_82 ( V_2 ) ;
return V_18 ;
}
static T_7 F_87 ( struct V_1 * V_2 )
{
T_7 V_217 = V_218 ;
T_6 V_219 = F_88 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_62 -> V_63 &
1 << V_64 ) )
return 0 ;
if ( V_219 & ( 1 << V_220 ) )
V_217 |= V_221 ;
else
V_217 |= V_222 ;
if ( V_16 -> V_29 &
( 1 << V_223 ) )
V_217 |= V_224 ;
return V_217 ;
}
static void F_89 ( struct V_1 * V_2 , unsigned long * V_225 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_7 V_217 [ 2 ] ;
V_217 [ 0 ] = F_87 ( V_2 ) ;
if ( V_16 -> V_29 &
( 1 << V_226 ) ) {
V_217 [ 0 ] |= ~ ( ( 1ULL << V_227 ) - 1 ) ;
V_217 [ 1 ] = ( 1ULL << ( V_228 - 63 ) ) - 1 ;
} else {
V_217 [ 1 ] = 0 ;
}
#if V_229 == 64
V_225 [ 0 ] = V_217 [ 0 ] ;
V_225 [ 1 ] = V_217 [ 1 ] ;
#else
V_225 [ 0 ] = V_217 [ 0 ] & 0xffffffff ;
V_225 [ 1 ] = V_217 [ 0 ] >> 32 ;
V_225 [ 2 ] = V_217 [ 1 ] & 0xffffffff ;
V_225 [ 3 ] = V_217 [ 1 ] >> 32 ;
#endif
}
static T_2 F_90 ( struct V_1 * V_2 , T_3 * V_230 )
{
F_91 ( V_225 , V_228 ) ;
F_89 ( V_2 , V_225 ) ;
return F_92 ( V_231 , V_228 ,
V_225 , V_230 ) ;
}
static T_2 F_93 ( struct V_1 * V_2 , T_7 * V_232 ,
struct V_233 * V_234 )
{
F_91 ( V_225 , V_228 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_7 * V_235 = V_16 -> V_235 ;
T_2 V_236 = 0 , V_128 ;
F_89 ( V_2 , V_225 ) ;
if ( V_232 ) {
F_94 (index, mask, EF10_STAT_COUNT) {
if ( V_231 [ V_128 ] . V_237 ) {
* V_232 ++ = V_235 [ V_128 ] ;
++ V_236 ;
}
}
}
if ( ! V_234 )
return V_236 ;
if ( V_16 -> V_29 &
1 << V_226 ) {
V_234 -> V_238 = V_235 [ V_227 ] +
V_235 [ V_239 ] +
V_235 [ V_240 ] ;
V_234 -> V_241 = V_235 [ V_242 ] +
V_235 [ V_243 ] +
V_235 [ V_244 ] ;
V_234 -> V_245 = V_235 [ V_246 ] +
V_235 [ V_247 ] +
V_235 [ V_248 ] ;
V_234 -> V_249 = V_235 [ V_250 ] +
V_235 [ V_251 ] +
V_235 [ V_252 ] ;
V_234 -> V_253 = V_235 [ V_254 ] +
V_235 [ V_255 ] ;
V_234 -> V_256 = V_235 [ V_239 ] ;
V_234 -> V_257 = V_235 [ V_258 ] ;
V_234 -> V_259 = V_235 [ V_260 ] ;
V_234 -> V_261 = V_234 -> V_257 ;
V_234 -> V_262 = V_235 [ V_263 ] ;
} else {
V_234 -> V_238 = V_235 [ V_264 ] ;
V_234 -> V_241 = V_235 [ V_265 ] ;
V_234 -> V_245 = V_235 [ V_266 ] ;
V_234 -> V_249 = V_235 [ V_267 ] ;
V_234 -> V_253 = V_235 [ V_268 ] +
V_235 [ V_254 ] +
V_235 [ V_255 ] ;
V_234 -> V_256 = V_235 [ V_269 ] ;
V_234 -> V_270 =
V_235 [ V_271 ] +
V_235 [ V_272 ] ;
V_234 -> V_257 = V_235 [ V_273 ] ;
V_234 -> V_274 =
V_235 [ V_275 ] ;
V_234 -> V_259 = V_235 [ V_276 ] ;
V_234 -> V_261 = ( V_234 -> V_270 +
V_234 -> V_257 +
V_234 -> V_274 ) ;
}
return V_236 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_91 ( V_225 , V_228 ) ;
T_8 V_277 , V_278 ;
T_7 * V_235 = V_16 -> V_235 ;
T_8 * V_279 ;
F_89 ( V_2 , V_225 ) ;
V_279 = V_2 -> V_280 . V_281 ;
V_16 = V_2 -> V_16 ;
V_278 = V_279 [ V_282 ] ;
if ( V_278 == V_283 )
return 0 ;
F_96 () ;
F_97 ( V_231 , V_228 , V_225 ,
V_235 , V_2 -> V_280 . V_281 , false ) ;
F_96 () ;
V_277 = V_279 [ V_284 ] ;
if ( V_278 != V_277 )
return - V_191 ;
F_98 ( V_2 ,
& V_235 [ V_268 ] ) ;
V_235 [ V_285 ] =
V_235 [ V_266 ] -
V_235 [ V_286 ] ;
F_99 ( & V_235 [ V_287 ] ,
V_235 [ V_286 ] ) ;
F_100 ( V_2 , V_235 ) ;
return 0 ;
}
static T_2 F_101 ( struct V_1 * V_2 , T_7 * V_232 ,
struct V_233 * V_234 )
{
int V_288 ;
for ( V_288 = 0 ; V_288 < 100 ; ++ V_288 ) {
if ( F_95 ( V_2 ) == 0 )
break;
F_102 ( 100 ) ;
}
return F_93 ( V_2 , V_232 , V_234 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_289 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
F_91 ( V_225 , V_228 ) ;
T_8 V_277 , V_278 ;
T_7 * V_235 = V_16 -> V_235 ;
T_6 V_290 = V_291 * sizeof( T_7 ) ;
struct V_292 V_293 ;
T_8 * V_279 ;
int V_18 ;
F_104 ( & V_2 -> V_294 ) ;
if ( F_105 () ) {
F_106 ( & V_2 -> V_294 ) ;
F_100 ( V_2 , V_235 ) ;
return 0 ;
}
F_89 ( V_2 , V_225 ) ;
V_18 = F_30 ( V_2 , & V_293 , V_290 , V_295 ) ;
if ( V_18 ) {
F_106 ( & V_2 -> V_294 ) ;
return V_18 ;
}
V_279 = V_293 . V_281 ;
V_279 [ V_282 ] = V_283 ;
F_107 ( V_47 , V_296 , V_293 . V_297 ) ;
F_108 ( V_47 , V_298 ,
V_299 , 1 ) ;
F_21 ( V_47 , V_300 , V_290 ) ;
F_21 ( V_47 , V_301 , V_52 ) ;
V_18 = F_51 ( V_2 , V_302 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_106 ( & V_2 -> V_294 ) ;
if ( V_18 ) {
if ( V_18 != - V_101 || F_109 ( & V_2 -> V_303 ) )
F_52 ( V_2 , V_302 ,
sizeof( V_47 ) , NULL , 0 , V_18 ) ;
goto V_304;
}
V_278 = V_279 [ V_282 ] ;
if ( V_278 == V_283 ) {
F_110 ( 1 ) ;
goto V_304;
}
F_96 () ;
F_97 ( V_231 , V_228 , V_225 ,
V_235 , V_293 . V_281 , false ) ;
F_96 () ;
V_277 = V_279 [ V_284 ] ;
if ( V_278 != V_277 ) {
V_18 = - V_191 ;
goto V_304;
}
F_100 ( V_2 , V_235 ) ;
V_304:
F_47 ( V_2 , & V_293 ) ;
return V_18 ;
}
static T_2 F_111 ( struct V_1 * V_2 , T_7 * V_232 ,
struct V_233 * V_234 )
{
if ( F_103 ( V_2 ) )
return 0 ;
return F_93 ( V_2 , V_232 , V_234 ) ;
}
static void F_112 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
unsigned int V_305 , V_306 ;
T_1 V_307 ;
if ( V_124 -> V_308 ) {
V_305 = 3 ;
V_306 = V_124 -> V_308 - 1 ;
} else {
V_305 = 0 ;
V_306 = 0 ;
}
if ( F_113 ( V_2 ) ) {
F_114 ( V_307 , V_309 ,
V_310 ,
V_311 , V_305 ,
V_312 , V_306 ) ;
F_115 ( V_2 , & V_307 , V_313 ,
V_124 -> V_124 ) ;
} else {
F_116 ( V_307 , V_314 , V_305 ,
V_315 , V_306 ) ;
F_115 ( V_2 , & V_307 , V_316 ,
V_124 -> V_124 ) ;
}
}
static void F_117 ( struct V_1 * V_2 ,
struct V_317 * V_318 ) {}
static int F_118 ( struct V_1 * V_2 , T_6 type )
{
return - V_319 ;
}
static void F_119 ( struct V_1 * V_2 , struct V_317 * V_318 )
{
V_318 -> V_320 = 0 ;
V_318 -> V_321 = 0 ;
memset ( & V_318 -> V_322 , 0 , sizeof( V_318 -> V_322 ) ) ;
}
static int F_120 ( struct V_1 * V_2 , T_6 type )
{
if ( type != 0 )
return - V_215 ;
return 0 ;
}
static void F_121 ( struct V_1 * V_2 ,
const T_1 * V_323 , T_2 V_324 ,
const T_1 * V_325 , T_2 V_326 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 * V_327 = V_16 -> V_73 . V_281 ;
memcpy ( V_327 , V_323 , V_324 ) ;
memcpy ( V_327 + V_324 , V_325 , V_326 ) ;
F_122 () ;
F_32 ( V_2 , F_33 ( ( T_7 ) V_16 -> V_73 . V_297 >> 32 ) ,
V_328 ) ;
F_32 ( V_2 , F_33 ( ( T_6 ) V_16 -> V_73 . V_297 ) ,
V_80 ) ;
}
static bool F_123 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_1 V_323 = * ( const T_1 * ) V_16 -> V_73 . V_281 ;
F_96 () ;
return F_3 ( V_323 , V_329 ) ;
}
static void
F_124 ( struct V_1 * V_2 , T_1 * V_13 ,
T_2 V_127 , T_2 V_17 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_3 * V_327 = V_16 -> V_73 . V_281 ;
memcpy ( V_13 , V_327 + V_127 , V_17 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_82 ( V_2 ) ;
V_16 -> V_193 = true ;
V_16 -> V_235 [ V_287 ] = 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 ) {
return 0 ;
}
if ( V_18 == V_16 -> V_76 )
return 0 ;
V_16 -> V_76 = V_18 ;
F_125 ( V_2 ) ;
return - V_7 ;
}
static T_9 F_127 ( int V_330 , void * V_331 )
{
struct V_332 * V_333 = V_331 ;
struct V_1 * V_2 = V_333 -> V_2 ;
F_128 ( V_2 , V_334 , V_2 -> V_28 ,
L_24 , V_330 , F_129 () ) ;
if ( F_130 ( F_131 ( V_2 -> V_335 ) ) ) {
if ( V_333 -> V_128 == V_2 -> V_336 )
V_2 -> V_337 = F_129 () ;
F_132 ( V_2 -> V_124 [ V_333 -> V_128 ] ) ;
}
return V_338 ;
}
static T_9 F_133 ( int V_330 , void * V_331 )
{
struct V_1 * V_2 = V_331 ;
bool V_339 = F_131 ( V_2 -> V_335 ) ;
struct V_123 * V_124 ;
T_1 V_3 ;
T_6 V_340 ;
F_2 ( V_2 , & V_3 , V_341 ) ;
V_340 = F_3 ( V_3 , V_342 ) ;
if ( V_340 == 0 )
return V_343 ;
if ( F_130 ( V_339 ) ) {
if ( V_340 & ( 1U << V_2 -> V_336 ) )
V_2 -> V_337 = F_129 () ;
F_58 (channel, efx) {
if ( V_340 & 1 )
F_132 ( V_124 ) ;
V_340 >>= 1 ;
}
}
F_128 ( V_2 , V_334 , V_2 -> V_28 ,
L_25 V_344 L_26 ,
V_330 , F_129 () , F_134 ( V_3 ) ) ;
return V_338 ;
}
static void F_135 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_345 ) ;
F_13 ( V_346 != 0 ) ;
F_21 ( V_47 , V_347 , V_2 -> V_336 ) ;
( void ) F_9 ( V_2 , V_348 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
static int F_136 ( struct V_125 * V_126 )
{
return F_30 ( V_126 -> V_2 , & V_126 -> V_349 . V_61 ,
( V_126 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_70 ) ;
}
static inline void F_137 ( struct V_125 * V_126 ,
const V_351 * V_349 )
{
unsigned int V_352 ;
T_10 V_3 ;
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
F_138 ( V_3 , V_354 , V_352 ) ;
V_3 . V_355 [ 0 ] = * V_349 ;
F_139 ( V_126 -> V_2 , & V_3 ,
V_356 , V_126 -> V_140 ) ;
}
static void F_140 ( struct V_125 * V_126 )
{
F_8 ( V_47 , F_141 ( V_357 * 8 /
V_358 ) ) ;
bool V_359 = V_126 -> V_140 & V_360 ;
T_2 V_361 = V_126 -> V_349 . V_61 . V_362 / V_358 ;
struct V_123 * V_124 = V_126 -> V_124 ;
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_363 ;
T_11 V_297 ;
V_351 * V_349 ;
int V_18 ;
int V_67 ;
F_13 ( V_364 != 0 ) ;
F_21 ( V_47 , V_365 , V_126 -> V_350 + 1 ) ;
F_21 ( V_47 , V_366 , V_124 -> V_124 ) ;
F_21 ( V_47 , V_367 , V_126 -> V_140 ) ;
F_21 ( V_47 , V_368 , V_126 -> V_140 ) ;
F_142 ( V_47 , V_369 ,
V_370 , ! V_359 ,
V_371 , ! V_359 ) ;
F_21 ( V_47 , V_372 , 0 ) ;
F_21 ( V_47 , V_373 , V_16 -> V_79 ) ;
V_297 = V_126 -> V_349 . V_61 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_27 ,
V_126 -> V_140 , V_361 , ( T_7 ) V_297 ) ;
for ( V_67 = 0 ; V_67 < V_361 ; ++ V_67 ) {
F_143 ( V_47 , V_375 , V_67 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_141 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_376 , V_47 , V_363 ,
NULL , 0 , NULL ) ;
if ( V_18 )
goto V_135;
V_126 -> V_377 [ 0 ] . V_204 = V_378 ;
V_126 -> V_379 = 1 ;
V_349 = F_144 ( V_126 , 0 ) ;
F_145 ( * V_349 ,
V_380 , true ,
V_381 ,
V_382 ,
V_383 , V_359 ,
V_384 , V_359 ) ;
V_126 -> V_353 = 1 ;
if ( V_16 -> V_29 &
( 1 << V_385 ) ) {
V_126 -> V_386 = 1 ;
}
F_122 () ;
F_137 ( V_126 , V_349 ) ;
return;
V_135:
F_146 ( V_2 -> V_28 , L_28 ,
V_126 -> V_140 ) ;
}
static void F_147 ( struct V_125 * V_126 )
{
F_8 ( V_47 , V_387 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_126 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_388 ,
V_126 -> V_140 ) ;
V_18 = F_51 ( V_2 , V_389 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_389 , V_387 ,
V_13 , V_17 , V_18 ) ;
}
static void F_148 ( struct V_125 * V_126 )
{
F_47 ( V_126 -> V_2 , & V_126 -> V_349 . V_61 ) ;
}
static inline void F_149 ( struct V_125 * V_126 )
{
unsigned int V_352 ;
T_1 V_3 ;
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
F_150 ( V_3 , V_390 , V_352 ) ;
F_115 ( V_126 -> V_2 , & V_3 ,
V_391 , V_126 -> V_140 ) ;
}
static void F_151 ( struct V_125 * V_126 )
{
unsigned int V_392 = V_126 -> V_353 ;
struct V_393 * V_377 ;
unsigned int V_352 ;
V_351 * V_349 ;
V_126 -> V_394 = false ;
if ( F_152 ( V_126 -> V_353 == V_126 -> V_379 ) )
return;
do {
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
V_377 = & V_126 -> V_377 [ V_352 ] ;
V_349 = F_144 ( V_126 , V_352 ) ;
++ V_126 -> V_353 ;
if ( V_377 -> V_204 & V_378 ) {
* V_349 = V_377 -> V_395 ;
} else {
F_13 ( V_396 != 1 ) ;
F_153 (
* V_349 ,
V_397 ,
V_377 -> V_204 & V_396 ,
V_398 , V_377 -> V_362 ,
V_399 , V_377 -> V_297 ) ;
}
} while ( V_126 -> V_353 != V_126 -> V_379 );
F_122 () ;
if ( F_154 ( V_126 , V_392 ) ) {
V_349 = F_144 ( V_126 ,
V_392 & V_126 -> V_350 ) ;
F_137 ( V_126 , V_349 ) ;
++ V_126 -> V_400 ;
} else {
F_149 ( V_126 ) ;
}
}
static int F_155 ( struct V_1 * V_2 , T_6 * V_333 ,
bool V_401 , unsigned * V_402 )
{
F_8 ( V_47 , V_403 ) ;
F_8 ( V_13 , V_404 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_6 V_405 = V_401 ?
V_406 :
V_407 ;
unsigned V_408 = V_401 ?
V_2 -> V_408 :
F_156 ( F_157 ( V_2 -> V_408 ) ,
V_409 ) ;
if ( ! V_401 && V_408 == 1 ) {
* V_333 = V_78 ;
if ( V_402 )
* V_402 = 1 ;
return 0 ;
}
if ( V_16 -> V_29 &
1 << V_410 )
return - V_319 ;
F_21 ( V_47 , V_411 ,
V_16 -> V_79 ) ;
F_21 ( V_47 , V_412 , V_405 ) ;
F_21 ( V_47 , V_413 , V_408 ) ;
V_18 = F_9 ( V_2 , V_414 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_404 )
return - V_7 ;
* V_333 = F_10 ( V_13 , V_415 ) ;
if ( V_402 )
* V_402 = V_408 ;
return 0 ;
}
static void F_158 ( struct V_1 * V_2 , T_6 V_333 )
{
F_8 ( V_47 , V_416 ) ;
int V_18 ;
F_21 ( V_47 , V_417 ,
V_333 ) ;
V_18 = F_9 ( V_2 , V_418 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 != 0 ) ;
}
static int F_159 ( struct V_1 * V_2 , T_6 V_333 ,
const T_6 * V_196 )
{
F_8 ( V_419 , V_420 ) ;
F_8 ( V_421 , V_422 ) ;
int V_67 , V_18 ;
F_21 ( V_419 , V_423 ,
V_333 ) ;
F_13 ( F_160 ( V_2 -> V_196 ) !=
V_424 ) ;
for ( V_67 = 0 ; V_67 < F_160 ( V_2 -> V_196 ) ; ++ V_67 )
F_19 ( V_419 ,
V_425 ) [ V_67 ] =
( T_3 ) V_196 [ V_67 ] ;
V_18 = F_9 ( V_2 , V_426 , V_419 ,
sizeof( V_419 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_21 ( V_421 , V_427 ,
V_333 ) ;
F_13 ( F_160 ( V_2 -> V_428 ) !=
V_429 ) ;
for ( V_67 = 0 ; V_67 < F_160 ( V_2 -> V_428 ) ; ++ V_67 )
F_19 ( V_421 , V_430 ) [ V_67 ] =
V_2 -> V_428 [ V_67 ] ;
return F_9 ( V_2 , V_431 , V_421 ,
sizeof( V_421 ) , NULL , 0 , NULL ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_77 != V_78 )
F_158 ( V_2 , V_16 -> V_77 ) ;
V_16 -> V_77 = V_78 ;
}
static int F_161 ( struct V_1 * V_2 ,
unsigned * V_402 )
{
T_6 V_432 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_155 ( V_2 , & V_432 ,
false , V_402 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_77 = V_432 ;
V_16 -> V_433 = false ;
F_162 ( V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 ,
const T_6 * V_196 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_432 ;
if ( V_16 -> V_77 == V_78 ||
! V_16 -> V_433 ) {
V_18 = F_155 ( V_2 , & V_432 ,
true , NULL ) ;
if ( V_18 == - V_319 )
return V_18 ;
else if ( V_18 != 0 )
goto V_74;
} else {
V_432 = V_16 -> V_77 ;
}
V_18 = F_159 ( V_2 , V_432 ,
V_196 ) ;
if ( V_18 != 0 )
goto V_75;
if ( V_16 -> V_77 != V_432 )
F_66 ( V_2 ) ;
V_16 -> V_77 = V_432 ;
V_16 -> V_433 = true ;
if ( V_196 != V_2 -> V_196 )
memcpy ( V_2 -> V_196 , V_196 ,
sizeof( V_2 -> V_196 ) ) ;
return 0 ;
V_75:
if ( V_432 != V_16 -> V_77 )
F_158 ( V_2 , V_432 ) ;
V_74:
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_29 , V_434 , V_18 ) ;
return V_18 ;
}
static int F_164 ( struct V_1 * V_2 , bool V_435 ,
const T_6 * V_196 )
{
int V_18 ;
if ( V_2 -> V_408 == 1 )
return 0 ;
V_18 = F_163 ( V_2 , V_196 ) ;
if ( V_18 == - V_147 && ! V_435 ) {
unsigned V_402 ;
bool V_436 = false ;
T_2 V_67 ;
for ( V_67 = 0 ; V_67 < F_160 ( V_2 -> V_196 ) && ! V_436 ;
V_67 ++ )
V_436 = V_196 [ V_67 ] !=
F_165 ( V_67 , V_2 -> V_408 ) ;
V_18 = F_161 ( V_2 , & V_402 ) ;
if ( V_18 == 0 ) {
if ( V_402 != V_2 -> V_408 )
F_166 ( V_2 , V_36 , V_2 -> V_28 ,
L_30
L_31
L_32
L_33 ,
V_2 -> V_408 , V_402 ) ;
else if ( V_436 )
F_166 ( V_2 , V_36 , V_2 -> V_28 ,
L_30
L_34
L_35
L_36 ) ;
else
F_63 ( V_2 , V_36 , V_2 -> V_28 ,
L_30
L_37 ) ;
}
}
return V_18 ;
}
static int F_167 ( struct V_437 * V_438 )
{
return F_30 ( V_438 -> V_2 , & V_438 -> V_439 . V_61 ,
( V_438 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_70 ) ;
}
static void F_168 ( struct V_437 * V_438 )
{
F_8 ( V_47 ,
F_169 ( V_357 * 8 /
V_358 ) ) ;
struct V_123 * V_124 = F_170 ( V_438 ) ;
T_2 V_361 = V_438 -> V_439 . V_61 . V_362 / V_358 ;
struct V_1 * V_2 = V_438 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_363 ;
T_11 V_297 ;
int V_18 ;
int V_67 ;
F_13 ( V_440 != 0 ) ;
V_438 -> V_441 = 0 ;
V_438 -> V_442 = 0 ;
F_21 ( V_47 , V_443 , V_438 -> V_350 + 1 ) ;
F_21 ( V_47 , V_444 , V_124 -> V_124 ) ;
F_21 ( V_47 , V_445 , F_171 ( V_438 ) ) ;
F_21 ( V_47 , V_446 ,
F_171 ( V_438 ) ) ;
F_142 ( V_47 , V_447 ,
V_448 , 1 ,
V_449 , 1 ) ;
F_21 ( V_47 , V_450 , 0 ) ;
F_21 ( V_47 , V_451 , V_16 -> V_79 ) ;
V_297 = V_438 -> V_439 . V_61 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_38 ,
F_171 ( V_438 ) , V_361 , ( T_7 ) V_297 ) ;
for ( V_67 = 0 ; V_67 < V_361 ; ++ V_67 ) {
F_143 ( V_47 , V_452 , V_67 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_169 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_453 , V_47 , V_363 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_146 ( V_2 -> V_28 , L_39 ,
F_171 ( V_438 ) ) ;
}
static void F_172 ( struct V_437 * V_438 )
{
F_8 ( V_47 , V_454 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_438 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_455 ,
F_171 ( V_438 ) ) ;
V_18 = F_51 ( V_2 , V_456 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_456 , V_454 ,
V_13 , V_17 , V_18 ) ;
}
static void F_173 ( struct V_437 * V_438 )
{
F_47 ( V_438 -> V_2 , & V_438 -> V_439 . V_61 ) ;
}
static inline void
F_174 ( struct V_437 * V_438 , unsigned int V_128 )
{
struct V_457 * V_458 ;
V_351 * V_439 ;
V_439 = F_175 ( V_438 , V_128 ) ;
V_458 = V_457 ( V_438 , V_128 ) ;
F_176 ( * V_439 ,
V_459 , V_458 -> V_362 ,
V_460 , V_458 -> V_297 ) ;
}
static void F_177 ( struct V_437 * V_438 )
{
struct V_1 * V_2 = V_438 -> V_2 ;
unsigned int V_353 ;
T_1 V_3 ;
V_353 = V_438 -> V_461 & ~ 7 ;
if ( V_438 -> V_462 == V_353 )
return;
do
F_174 (
V_438 ,
V_438 -> V_462 & V_438 -> V_350 ) ;
while ( ++ V_438 -> V_462 != V_353 );
F_122 () ;
F_150 ( V_3 , V_463 ,
V_353 & V_438 -> V_350 ) ;
F_115 ( V_2 , & V_3 , V_464 ,
F_171 ( V_438 ) ) ;
}
static void F_178 ( struct V_437 * V_438 )
{
struct V_123 * V_124 = F_170 ( V_438 ) ;
F_8 ( V_47 , V_465 ) ;
V_351 V_466 ;
F_176 ( V_466 ,
V_467 , V_468 ,
V_469 , V_470 ) ;
F_21 ( V_47 , V_471 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_47 , V_472 ) , & V_466 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
F_179 ( V_124 -> V_2 , V_473 ,
V_47 , sizeof( V_47 ) , 0 ,
V_474 , 0 ) ;
}
static void
V_474 ( struct V_1 * V_2 , unsigned long V_475 ,
int V_18 , T_1 * V_13 ,
T_2 V_476 )
{
}
static int F_180 ( struct V_123 * V_124 )
{
return F_30 ( V_124 -> V_2 , & V_124 -> V_477 . V_61 ,
( V_124 -> V_478 + 1 ) *
sizeof( V_351 ) ,
V_70 ) ;
}
static void F_181 ( struct V_123 * V_124 )
{
F_8 ( V_47 , V_479 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_480 , V_124 -> V_124 ) ;
V_18 = F_51 ( V_2 , V_481 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_481 , V_479 ,
V_13 , V_17 , V_18 ) ;
}
static int F_182 ( struct V_123 * V_124 )
{
F_8 ( V_47 ,
F_183 ( V_482 * 8 /
V_358 ) ) ;
F_8 ( V_13 , V_483 ) ;
T_2 V_361 = V_124 -> V_477 . V_61 . V_362 / V_358 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_15 * V_16 ;
bool V_484 ;
T_2 V_363 , V_17 ;
unsigned int V_98 , V_485 ;
T_11 V_297 ;
int V_18 ;
int V_67 ;
V_16 = V_2 -> V_16 ;
V_484 =
! ! ( V_16 -> V_29 &
1 << V_486 ) ;
memset ( V_124 -> V_477 . V_61 . V_281 , 0xff , V_124 -> V_477 . V_61 . V_362 ) ;
F_21 ( V_47 , V_487 , V_124 -> V_478 + 1 ) ;
F_21 ( V_47 , V_488 , V_124 -> V_124 ) ;
F_21 ( V_47 , V_489 , V_124 -> V_124 ) ;
F_184 ( V_47 , V_490 ,
V_491 , 1 ,
V_492 , 1 ,
V_493 , 1 ,
V_494 , ! V_484 ) ;
F_21 ( V_47 , V_495 ,
V_496 ) ;
F_21 ( V_47 , V_497 , 0 ) ;
F_21 ( V_47 , V_498 , 0 ) ;
F_21 ( V_47 , V_499 ,
V_500 ) ;
F_21 ( V_47 , V_501 , 0 ) ;
V_297 = V_124 -> V_477 . V_61 . V_297 ;
for ( V_67 = 0 ; V_67 < V_361 ; ++ V_67 ) {
F_143 ( V_47 , V_502 , V_67 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_183 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_503 , V_47 , V_363 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_124 -> V_124 || V_18 )
return V_18 ;
V_18 = F_40 ( V_2 , & V_485 , & V_98 ) ;
if ( V_18 == - V_100 ) {
V_16 -> V_504 = false ;
V_18 = 0 ;
} else if ( V_18 ) {
goto V_135;
} else {
V_16 -> V_504 =
! ! ( V_98 & V_505 ) ;
if ( V_485 & V_505 &&
! V_16 -> V_504 ) {
unsigned int V_204 ;
V_18 = F_39 ( V_2 ,
V_506 ,
true , & V_204 ) ;
if ( ! V_18 ) {
if ( V_204 &
1 << V_507 ) {
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_40 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 ) {
V_16 -> V_76 = V_18 ;
V_18 = 0 ;
}
}
V_16 -> V_504 = true ;
} else if ( V_18 == - V_97 ) {
V_18 = 0 ;
}
}
}
if ( ! V_18 )
return 0 ;
V_135:
F_181 ( V_124 ) ;
return V_18 ;
}
static void F_185 ( struct V_123 * V_124 )
{
F_47 ( V_124 -> V_2 , & V_124 -> V_477 . V_61 ) ;
}
static void F_186 ( struct V_437 * V_438 ,
unsigned int V_508 )
{
struct V_1 * V_2 = V_438 -> V_2 ;
F_63 ( V_2 , V_374 , V_2 -> V_28 ,
L_41 ,
F_171 ( V_438 ) , V_508 ) ;
F_187 ( V_2 , V_509 ) ;
}
static void
F_188 ( struct V_437 * V_438 ,
unsigned int V_510 , unsigned int V_511 )
{
unsigned int V_512 = ( V_510 - V_511 ) & V_438 -> V_350 ;
struct V_1 * V_2 = V_438 -> V_2 ;
F_63 ( V_2 , V_374 , V_2 -> V_28 ,
L_42 ,
V_512 , V_510 , V_511 ) ;
F_187 ( V_2 , V_509 ) ;
}
static void F_189 ( struct V_437 * V_438 )
{
unsigned int V_513 ;
F_41 ( V_438 -> V_2 , V_374 , V_438 -> V_2 -> V_28 ,
L_43 ,
V_438 -> V_441 ) ;
V_513 = V_438 -> V_514 & V_438 -> V_350 ;
F_190 ( V_438 , V_513 , V_438 -> V_441 ,
0 , V_515 ) ;
V_438 -> V_514 += V_438 -> V_441 ;
V_438 -> V_441 = 0 ;
V_438 -> V_442 = 0 ;
++ F_170 ( V_438 ) -> V_516 ;
}
static int F_191 ( struct V_123 * V_124 ,
const V_351 * V_466 )
{
unsigned int V_245 , V_517 , V_508 , V_518 ;
unsigned int V_519 , V_520 , V_67 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_437 * V_438 ;
bool V_521 ;
T_12 V_204 = 0 ;
if ( F_152 ( F_131 ( V_2 -> V_522 ) ) )
return 0 ;
V_245 = F_192 ( * V_466 , V_523 ) ;
V_517 = F_192 ( * V_466 , V_524 ) ;
V_508 = F_192 ( * V_466 , V_525 ) ;
V_518 = F_192 ( * V_466 , V_526 ) ;
V_521 = F_192 ( * V_466 , V_527 ) ;
if ( F_192 ( * V_466 , V_528 ) )
F_146 ( V_2 -> V_28 , L_44
V_529 L_26 ,
F_193 ( * V_466 ) ) ;
V_438 = F_194 ( V_124 ) ;
if ( F_152 ( V_508 != F_171 ( V_438 ) ) )
F_186 ( V_438 , V_508 ) ;
V_519 = ( ( V_517 - V_438 -> V_514 ) &
( ( 1 << V_530 ) - 1 ) ) ;
if ( V_519 != V_438 -> V_441 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_152 ( V_519 == V_438 -> V_441 ) ) {
if ( V_438 -> V_441 == 0 || V_245 != 0 )
F_146 ( V_2 -> V_28 ,
L_45
V_529 L_26 ,
V_438 -> V_441 ,
F_193 ( * V_466 ) ) ;
F_189 ( V_438 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_29 &
( 1 << V_486 ) ) ||
V_438 -> V_441 != 0 || V_521 ) {
F_188 (
V_438 , V_517 ,
( V_438 -> V_514 +
V_438 -> V_441 + 1 ) &
( ( 1 << V_530 ) - 1 ) ) ;
return 0 ;
}
V_438 -> V_441 = 1 ;
V_438 -> V_442 = 0 ;
V_520 = V_519 ;
++ V_124 -> V_531 ;
V_124 -> V_532 += V_520 ;
V_204 |= V_533 ;
} else {
++ V_438 -> V_441 ;
V_438 -> V_442 += V_245 ;
if ( V_521 )
return 0 ;
V_520 = 1 ;
}
if ( F_152 ( F_192 ( * V_466 , V_534 ) ) )
V_204 |= V_515 ;
if ( F_152 ( F_192 ( * V_466 , V_535 ) ) ) {
V_124 -> V_536 += V_520 ;
} else if ( F_152 ( F_192 ( * V_466 ,
V_537 ) ) ) {
V_124 -> V_538 += V_520 ;
} else if ( V_518 == V_539 ||
V_518 == V_540 ) {
V_204 |= V_541 ;
}
if ( V_518 == V_539 )
V_204 |= V_542 ;
V_124 -> V_543 += 2 * V_520 ;
for ( V_67 = 0 ; V_67 < V_520 ; V_67 ++ ) {
F_190 ( V_438 ,
V_438 -> V_514 & V_438 -> V_350 ,
V_438 -> V_441 , V_438 -> V_442 ,
V_204 ) ;
V_438 -> V_514 += V_438 -> V_441 ;
}
V_438 -> V_441 = 0 ;
V_438 -> V_442 = 0 ;
return V_520 ;
}
static int
F_195 ( struct V_123 * V_124 , V_351 * V_466 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_125 * V_126 ;
unsigned int V_544 ;
unsigned int V_545 ;
int V_546 = 0 ;
if ( F_152 ( F_131 ( V_2 -> V_522 ) ) )
return 0 ;
if ( F_152 ( F_192 ( * V_466 , V_547 ) ) )
return 0 ;
V_544 = F_192 ( * V_466 , V_548 ) ;
V_545 = F_192 ( * V_466 , V_549 ) ;
V_126 = F_196 ( V_124 ,
V_545 % V_184 ) ;
V_546 = ( ( V_544 + 1 - V_126 -> V_550 ) &
V_126 -> V_350 ) ;
F_197 ( V_126 , V_544 & V_126 -> V_350 ) ;
return V_546 ;
}
static void
F_198 ( struct V_123 * V_124 , V_351 * V_466 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
int V_551 ;
V_551 = F_192 ( * V_466 , V_552 ) ;
switch ( V_551 ) {
case V_553 :
case V_554 :
break;
case V_555 :
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_46
L_47 V_529 L_48 ,
V_124 -> V_124 , V_551 ,
F_193 ( * V_466 ) ) ;
}
}
static void F_199 ( struct V_123 * V_124 ,
V_351 * V_466 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_6 V_551 ;
V_551 = F_192 ( * V_466 , V_556 ) ;
switch ( V_551 ) {
case V_557 :
V_124 -> V_558 = F_129 () ;
break;
case V_470 :
F_200 ( & V_124 -> V_438 , true ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_49
L_47 V_529 L_48 ,
V_124 -> V_124 , ( unsigned ) V_551 ,
F_193 ( * V_466 ) ) ;
}
}
static int F_201 ( struct V_123 * V_124 , int V_559 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_466 , * V_560 ;
unsigned int V_561 ;
int V_562 ;
int V_546 = 0 ;
int V_563 = 0 ;
if ( V_559 <= 0 )
return V_563 ;
V_561 = V_124 -> V_564 ;
for (; ; ) {
V_560 = F_202 ( V_124 , V_561 ) ;
V_466 = * V_560 ;
if ( ! F_203 ( & V_466 ) )
break;
F_204 ( * V_560 ) ;
++ V_561 ;
V_562 = F_192 ( V_466 , V_467 ) ;
F_128 ( V_2 , V_27 , V_2 -> V_28 ,
L_50 V_529 L_26 ,
V_124 -> V_124 , F_193 ( V_466 ) ) ;
switch ( V_562 ) {
case V_565 :
F_205 ( V_124 , & V_466 ) ;
break;
case V_566 :
V_563 += F_191 ( V_124 , & V_466 ) ;
if ( V_563 >= V_559 ) {
V_563 = V_559 ;
goto V_304;
}
break;
case V_567 :
V_546 += F_195 ( V_124 , & V_466 ) ;
if ( V_546 > V_2 -> V_568 ) {
V_563 = V_559 ;
goto V_304;
} else if ( ++ V_563 == V_559 ) {
goto V_304;
}
break;
case V_569 :
F_198 ( V_124 , & V_466 ) ;
if ( ++ V_563 == V_559 )
goto V_304;
break;
case V_468 :
F_199 ( V_124 , & V_466 ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_51
L_47 V_529 L_48 ,
V_124 -> V_124 , V_562 ,
F_193 ( V_466 ) ) ;
}
}
V_304:
V_124 -> V_564 = V_561 ;
return V_563 ;
}
static void F_206 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_1 V_570 ;
if ( F_113 ( V_2 ) ) {
F_13 ( V_571 <
( 1 << V_572 ) ) ;
F_13 ( V_482 >
( 1 << 2 * V_572 ) ) ;
F_116 ( V_570 , V_573 ,
V_574 ,
V_575 ,
( V_124 -> V_564 &
V_124 -> V_478 ) >>
V_572 ) ;
F_115 ( V_2 , & V_570 , V_313 ,
V_124 -> V_124 ) ;
F_116 ( V_570 , V_573 ,
V_576 ,
V_575 ,
V_124 -> V_564 &
( ( 1 << V_572 ) - 1 ) ) ;
F_115 ( V_2 , & V_570 , V_313 ,
V_124 -> V_124 ) ;
} else {
F_150 ( V_570 , V_577 ,
V_124 -> V_564 &
V_124 -> V_478 ) ;
F_115 ( V_2 , & V_570 , V_578 , V_124 -> V_124 ) ;
}
}
static void F_207 ( struct V_123 * V_124 )
{
F_8 ( V_47 , V_465 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_466 ;
int V_18 ;
F_176 ( V_466 ,
V_467 , V_468 ,
V_469 , V_557 ) ;
F_21 ( V_47 , V_471 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_47 , V_472 ) , & V_466 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
V_18 = F_9 ( V_2 , V_473 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_135;
return;
V_135:
F_22 ( true ) ;
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_29 , V_434 , V_18 ) ;
}
void F_208 ( struct V_1 * V_2 )
{
if ( F_209 ( & V_2 -> V_303 ) )
F_210 ( & V_2 -> V_579 ) ;
F_22 ( F_109 ( & V_2 -> V_303 ) < 0 ) ;
}
static int F_211 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
struct V_437 * V_438 ;
int V_580 ;
if ( V_16 -> V_194 ) {
F_212 ( & V_2 -> V_303 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_581 != V_582 ) {
F_58 (channel, efx) {
F_213 (rx_queue, channel)
F_172 ( V_438 ) ;
F_59 (tx_queue, channel)
F_147 ( V_126 ) ;
}
F_214 ( V_2 -> V_579 ,
F_109 ( & V_2 -> V_303 ) == 0 ,
F_215 ( V_583 ) ) ;
V_580 = F_109 ( & V_2 -> V_303 ) ;
if ( V_580 ) {
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_52 ,
V_580 ) ;
return - V_584 ;
}
}
return 0 ;
}
static void F_216 ( struct V_1 * V_2 )
{
F_212 ( & V_2 -> V_303 , 0 ) ;
}
static bool F_217 ( const struct V_585 * V_586 ,
const struct V_585 * V_587 )
{
if ( ( V_586 -> V_588 ^ V_587 -> V_588 ) |
( ( V_586 -> V_204 ^ V_587 -> V_204 ) &
( V_589 | V_590 ) ) )
return false ;
return memcmp ( & V_586 -> V_591 , & V_587 -> V_591 ,
sizeof( struct V_585 ) -
F_218 ( struct V_585 , V_591 ) ) == 0 ;
}
static unsigned int F_219 ( const struct V_585 * V_592 )
{
F_13 ( F_218 ( struct V_585 , V_591 ) & 3 ) ;
return F_220 ( ( const T_6 * ) & V_592 -> V_591 ,
( sizeof( struct V_585 ) -
F_218 ( struct V_585 , V_591 ) ) / 4 ,
0 ) ;
}
static bool F_221 ( const struct V_585 * V_592 )
{
if ( V_592 -> V_588 & V_593 &&
! F_222 ( V_592 -> V_594 ) )
return true ;
if ( ( V_592 -> V_588 &
( V_595 | V_596 ) ) ==
( V_595 | V_596 ) ) {
if ( V_592 -> V_597 == F_223 ( V_598 ) &&
! F_224 ( V_592 -> V_599 [ 0 ] ) )
return true ;
if ( V_592 -> V_597 == F_223 ( V_600 ) &&
( ( const T_3 * ) V_592 -> V_599 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_585 *
F_225 ( const struct V_601 * V_602 ,
unsigned int V_603 )
{
return (struct V_585 * ) ( V_602 -> V_604 [ V_603 ] . V_592 &
~ V_605 ) ;
}
static unsigned int
F_226 ( const struct V_601 * V_602 ,
unsigned int V_603 )
{
return V_602 -> V_604 [ V_603 ] . V_592 & V_605 ;
}
static void
F_227 ( struct V_601 * V_602 ,
unsigned int V_603 ,
const struct V_585 * V_592 ,
unsigned int V_204 )
{
V_602 -> V_604 [ V_603 ] . V_592 = ( unsigned long ) V_592 | V_204 ;
}
static void F_228 ( struct V_1 * V_2 ,
const struct V_585 * V_592 ,
T_1 * V_47 , T_7 V_606 ,
bool V_607 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_6 V_204 = V_592 -> V_204 ;
memset ( V_47 , 0 , V_608 ) ;
if ( V_204 & V_609 &&
V_592 -> V_610 == V_611 &&
V_16 -> V_77 == V_78 )
V_204 &= ~ V_609 ;
if ( V_607 ) {
F_21 ( V_47 , V_612 ,
V_613 ) ;
F_107 ( V_47 , V_614 , V_606 ) ;
} else {
T_6 V_615 = 0 ;
F_21 ( V_47 , V_612 ,
F_221 ( V_592 ) ?
V_616 :
V_617 ) ;
if ( V_592 -> V_588 & V_618 )
V_615 |=
F_222 ( V_592 -> V_594 ) ?
1 << V_619 :
1 << V_620 ;
#define F_229 ( T_13 , T_14 , T_15 ) \
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
F_229 ( V_621 , V_622 , V_623 ) ;
F_229 ( V_624 , V_599 , V_625 ) ;
F_229 ( V_626 , V_627 , V_628 ) ;
F_229 ( V_629 , V_630 , V_631 ) ;
F_229 ( V_632 , V_594 , V_633 ) ;
F_229 ( V_634 , V_635 , V_636 ) ;
F_229 ( V_637 , V_597 , V_637 ) ;
F_229 ( V_638 , V_639 , V_640 ) ;
F_229 ( V_641 , V_591 , V_642 ) ;
F_229 ( V_643 , V_644 , V_643 ) ;
#undef F_229
F_21 ( V_47 , V_645 ,
V_615 ) ;
}
F_21 ( V_47 , V_646 , V_16 -> V_79 ) ;
F_21 ( V_47 , V_647 ,
V_592 -> V_648 == V_649 ?
V_650 :
V_651 ) ;
F_21 ( V_47 , V_652 , 0 ) ;
F_21 ( V_47 , V_653 ,
V_654 ) ;
F_21 ( V_47 , V_655 ,
V_592 -> V_648 == V_649 ?
0 : V_592 -> V_648 ) ;
F_21 ( V_47 , V_656 ,
( V_204 & V_609 ) ?
V_657 :
V_658 ) ;
if ( V_204 & V_609 )
F_21 ( V_47 , V_659 ,
V_592 -> V_610 !=
V_611 ?
V_592 -> V_610 : V_16 -> V_77 ) ;
}
static int F_230 ( struct V_1 * V_2 ,
const struct V_585 * V_592 ,
T_7 * V_606 , bool V_607 )
{
F_8 ( V_47 , V_608 ) ;
F_8 ( V_13 , V_660 ) ;
int V_18 ;
F_228 ( V_2 , V_592 , V_47 , * V_606 , V_607 ) ;
V_18 = F_9 ( V_2 , V_661 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_606 = F_231 ( V_13 , V_662 ) ;
if ( V_18 == - V_119 )
V_18 = - V_169 ;
return V_18 ;
}
static int F_232 ( struct V_601 * V_602 ,
enum V_663 V_588 )
{
unsigned int V_664 ;
for ( V_664 = 0 ;
V_664 < V_602 -> V_665 ;
V_664 ++ )
if ( V_602 -> V_666 [ V_664 ] == V_588 )
return V_664 ;
return - V_667 ;
}
static T_16 F_233 ( struct V_1 * V_2 ,
struct V_585 * V_592 ,
bool V_668 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
F_91 ( V_670 , V_671 ) ;
struct V_585 * V_672 ;
unsigned int V_664 , V_673 ;
unsigned int V_674 ;
bool V_607 = false ;
int V_675 = - 1 ;
F_234 ( V_676 ) ;
bool V_677 ;
T_16 V_18 ;
if ( ( V_592 -> V_204 & ( V_589 | V_590 ) ) !=
V_589 )
return - V_215 ;
V_18 = F_232 ( V_602 , V_592 -> V_588 ) ;
if ( V_18 < 0 )
return V_18 ;
V_664 = V_18 ;
V_673 = F_219 ( V_592 ) ;
V_677 = F_235 ( V_592 ) ;
if ( V_677 )
F_236 ( V_670 , V_671 ) ;
for (; ; ) {
unsigned int V_678 = 1 ;
unsigned int V_67 ;
F_106 ( & V_2 -> V_679 ) ;
for (; ; ) {
V_67 = ( V_673 + V_678 ) & ( V_680 - 1 ) ;
V_672 = F_225 ( V_602 , V_67 ) ;
if ( ! V_672 ) {
if ( V_675 < 0 )
V_675 = V_67 ;
} else if ( F_217 ( V_592 , V_672 ) ) {
if ( V_602 -> V_604 [ V_67 ] . V_592 &
V_681 )
break;
if ( V_592 -> V_682 < V_672 -> V_682 &&
V_592 -> V_682 != V_683 ) {
V_18 = - V_97 ;
goto V_684;
}
if ( ! V_677 ) {
if ( V_592 -> V_682 ==
V_672 -> V_682 &&
! V_668 ) {
V_18 = - V_685 ;
goto V_684;
}
V_675 = V_67 ;
goto V_686;
} else if ( V_592 -> V_682 >
V_672 -> V_682 ||
( V_592 -> V_682 ==
V_672 -> V_682 &&
V_668 ) ) {
if ( V_675 < 0 )
V_675 = V_67 ;
else
F_237 ( V_678 , V_670 ) ;
}
}
if ( V_678 == V_671 ) {
if ( V_675 < 0 ) {
V_18 = - V_169 ;
goto V_684;
}
goto V_686;
}
++ V_678 ;
}
F_238 ( & V_602 -> V_687 , & V_676 , V_688 ) ;
F_104 ( & V_2 -> V_679 ) ;
F_239 () ;
}
V_686:
V_672 = F_225 ( V_602 , V_675 ) ;
if ( V_672 ) {
if ( V_592 -> V_682 == V_683 &&
V_672 -> V_682 >= V_683 ) {
if ( V_672 -> V_682 > V_683 )
V_672 -> V_204 |= V_689 ;
V_602 -> V_604 [ V_675 ] . V_592 &=
~ V_690 ;
V_18 = V_675 ;
goto V_684;
}
V_607 = true ;
V_674 = F_226 ( V_602 , V_675 ) ;
} else {
V_672 = F_240 ( sizeof( * V_592 ) , V_295 ) ;
if ( ! V_672 ) {
V_18 = - V_71 ;
goto V_684;
}
* V_672 = * V_592 ;
V_674 = 0 ;
}
F_227 ( V_602 , V_675 , V_672 ,
V_674 | V_681 ) ;
if ( V_677 ) {
unsigned int V_678 , V_67 ;
for ( V_678 = 0 ; V_678 < V_671 ; V_678 ++ ) {
V_67 = ( V_673 + V_678 ) & ( V_680 - 1 ) ;
if ( F_241 ( V_678 , V_670 ) )
V_602 -> V_604 [ V_67 ] . V_592 |=
V_681 ;
}
}
F_104 ( & V_2 -> V_679 ) ;
V_18 = F_230 ( V_2 , V_592 , & V_602 -> V_604 [ V_675 ] . V_606 ,
V_607 ) ;
F_106 ( & V_2 -> V_679 ) ;
if ( V_18 == 0 ) {
if ( V_607 ) {
if ( V_672 -> V_682 == V_683 )
V_672 -> V_204 |=
V_689 ;
V_672 -> V_682 = V_592 -> V_682 ;
V_672 -> V_204 &= V_689 ;
V_672 -> V_204 |= V_592 -> V_204 ;
V_672 -> V_610 = V_592 -> V_610 ;
V_672 -> V_648 = V_592 -> V_648 ;
}
} else if ( ! V_607 ) {
F_48 ( V_672 ) ;
V_672 = NULL ;
}
F_227 ( V_602 , V_675 , V_672 , V_674 ) ;
if ( V_677 ) {
F_8 ( V_47 , V_608 ) ;
unsigned int V_678 , V_67 ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
for ( V_678 = 0 ; V_678 < V_671 ; V_678 ++ ) {
if ( ! F_241 ( V_678 , V_670 ) )
continue;
V_67 = ( V_673 + V_678 ) & ( V_680 - 1 ) ;
V_672 = F_225 ( V_602 , V_67 ) ;
V_674 = F_226 ( V_602 , V_67 ) ;
if ( V_18 == 0 ) {
F_104 ( & V_2 -> V_679 ) ;
F_21 ( V_47 , V_612 ,
V_691 ) ;
F_107 ( V_47 , V_614 ,
V_602 -> V_604 [ V_67 ] . V_606 ) ;
V_18 = F_9 ( V_2 , V_661 ,
V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_106 ( & V_2 -> V_679 ) ;
}
if ( V_18 == 0 ) {
F_48 ( V_672 ) ;
V_672 = NULL ;
V_674 = 0 ;
} else {
V_674 &= ~ V_681 ;
}
F_227 ( V_602 , V_67 , V_672 ,
V_674 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_664 * V_680 + V_675 ;
F_242 ( & V_602 -> V_687 ) ;
V_684:
F_104 ( & V_2 -> V_679 ) ;
F_243 ( & V_602 -> V_687 , & V_676 ) ;
return V_18 ;
}
static void F_244 ( struct V_1 * V_2 )
{
}
static int F_245 ( struct V_1 * V_2 ,
unsigned int V_692 ,
T_6 V_693 , bool V_694 )
{
unsigned int V_603 = V_693 % V_680 ;
struct V_601 * V_602 = V_2 -> V_669 ;
F_8 ( V_47 ,
V_695 +
V_696 ) ;
struct V_585 * V_592 ;
F_234 ( V_676 ) ;
int V_18 ;
for (; ; ) {
F_106 ( & V_2 -> V_679 ) ;
if ( ! ( V_602 -> V_604 [ V_603 ] . V_592 &
V_681 ) )
break;
F_238 ( & V_602 -> V_687 , & V_676 , V_688 ) ;
F_104 ( & V_2 -> V_679 ) ;
F_239 () ;
}
V_592 = F_225 ( V_602 , V_603 ) ;
if ( ! V_592 ||
( ! V_694 &&
F_232 ( V_602 , V_592 -> V_588 ) !=
V_693 / V_680 ) ) {
V_18 = - V_101 ;
goto V_684;
}
if ( V_592 -> V_204 & V_689 &&
V_692 == ( 1U << V_683 ) ) {
V_592 -> V_204 &= ~ V_689 ;
V_602 -> V_604 [ V_603 ] . V_592 &= ~ V_690 ;
V_18 = 0 ;
goto V_684;
}
if ( ! ( V_692 & ( 1U << V_592 -> V_682 ) ) ) {
V_18 = - V_101 ;
goto V_684;
}
V_602 -> V_604 [ V_603 ] . V_592 |= V_681 ;
F_104 ( & V_2 -> V_679 ) ;
if ( V_592 -> V_204 & V_689 ) {
struct V_585 V_697 = * V_592 ;
V_697 . V_682 = V_683 ;
V_697 . V_204 = ( V_589 |
( F_246 ( V_2 ) ?
V_609 : 0 ) ) ;
V_697 . V_648 = 0 ;
V_697 . V_610 = V_611 ;
V_18 = F_230 ( V_2 , & V_697 ,
& V_602 -> V_604 [ V_603 ] . V_606 ,
true ) ;
F_106 ( & V_2 -> V_679 ) ;
if ( V_18 == 0 )
* V_592 = V_697 ;
} else {
F_21 ( V_47 , V_612 ,
F_221 ( V_592 ) ?
V_698 :
V_691 ) ;
F_107 ( V_47 , V_614 ,
V_602 -> V_604 [ V_603 ] . V_606 ) ;
V_18 = F_9 ( V_2 , V_661 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
F_106 ( & V_2 -> V_679 ) ;
if ( V_18 == 0 ) {
F_48 ( V_592 ) ;
F_227 ( V_602 , V_603 , NULL , 0 ) ;
}
}
V_602 -> V_604 [ V_603 ] . V_592 &= ~ V_681 ;
F_242 ( & V_602 -> V_687 ) ;
V_684:
F_104 ( & V_2 -> V_679 ) ;
F_243 ( & V_602 -> V_687 , & V_676 ) ;
return V_18 ;
}
static int F_247 ( struct V_1 * V_2 ,
enum V_699 V_682 ,
T_6 V_693 )
{
return F_245 ( V_2 , 1U << V_682 ,
V_693 , false ) ;
}
static T_6 F_248 ( struct V_1 * V_2 , T_6 V_693 )
{
return V_693 % V_680 ;
}
static int F_249 ( struct V_1 * V_2 ,
enum V_699 V_682 ,
T_6 V_693 )
{
return F_245 ( V_2 , 1U << V_682 ,
V_693 , true ) ;
}
static int F_250 ( struct V_1 * V_2 ,
enum V_699 V_682 ,
T_6 V_693 , struct V_585 * V_592 )
{
unsigned int V_603 = V_693 % V_680 ;
struct V_601 * V_602 = V_2 -> V_669 ;
const struct V_585 * V_672 ;
int V_18 ;
F_106 ( & V_2 -> V_679 ) ;
V_672 = F_225 ( V_602 , V_603 ) ;
if ( V_672 && V_672 -> V_682 == V_682 &&
F_232 ( V_602 , V_672 -> V_588 ) ==
V_693 / V_680 ) {
* V_592 = * V_672 ;
V_18 = 0 ;
} else {
V_18 = - V_101 ;
}
F_104 ( & V_2 -> V_679 ) ;
return V_18 ;
}
static int F_251 ( struct V_1 * V_2 ,
enum V_699 V_682 )
{
unsigned int V_692 ;
unsigned int V_67 ;
int V_18 ;
V_692 = ( ( ( 1U << ( V_682 + 1 ) ) - 1 ) &
~ ( 1U << V_683 ) ) ;
for ( V_67 = 0 ; V_67 < V_680 ; V_67 ++ ) {
V_18 = F_245 ( V_2 , V_692 ,
V_67 , true ) ;
if ( V_18 && V_18 != - V_101 )
return V_18 ;
}
return 0 ;
}
static T_6 F_252 ( struct V_1 * V_2 ,
enum V_699 V_682 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
unsigned int V_603 ;
T_16 V_700 = 0 ;
F_106 ( & V_2 -> V_679 ) ;
for ( V_603 = 0 ; V_603 < V_680 ; V_603 ++ ) {
if ( V_602 -> V_604 [ V_603 ] . V_592 &&
F_225 ( V_602 , V_603 ) -> V_682 ==
V_682 )
++ V_700 ;
}
F_104 ( & V_2 -> V_679 ) ;
return V_700 ;
}
static T_6 F_253 ( struct V_1 * V_2 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
return V_602 -> V_665 * V_680 ;
}
static T_16 F_254 ( struct V_1 * V_2 ,
enum V_699 V_682 ,
T_6 * V_61 , T_6 V_701 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_585 * V_592 ;
unsigned int V_603 ;
T_16 V_700 = 0 ;
F_106 ( & V_2 -> V_679 ) ;
for ( V_603 = 0 ; V_603 < V_680 ; V_603 ++ ) {
V_592 = F_225 ( V_602 , V_603 ) ;
if ( V_592 && V_592 -> V_682 == V_682 ) {
if ( V_700 == V_701 ) {
V_700 = - V_702 ;
break;
}
V_61 [ V_700 ++ ] = ( F_232 (
V_602 , V_592 -> V_588 ) *
V_680 +
V_603 ) ;
}
}
F_104 ( & V_2 -> V_679 ) ;
return V_700 ;
}
static T_16 F_255 ( struct V_1 * V_2 ,
struct V_585 * V_592 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
F_8 ( V_47 , V_608 ) ;
struct V_585 * V_672 ;
unsigned int V_673 , V_67 , V_678 = 1 ;
bool V_607 = false ;
int V_675 = - 1 ;
T_7 V_475 ;
T_16 V_18 ;
F_256 ( V_592 -> V_204 !=
( V_589 | V_703 ) ) ;
F_256 ( V_592 -> V_682 != V_704 ) ;
F_256 ( F_235 ( V_592 ) ) ;
V_673 = F_219 ( V_592 ) ;
F_106 ( & V_2 -> V_679 ) ;
for (; ; ) {
V_67 = ( V_673 + V_678 ) & ( V_680 - 1 ) ;
V_672 = F_225 ( V_602 , V_67 ) ;
if ( ! V_672 ) {
if ( V_675 < 0 )
V_675 = V_67 ;
} else if ( F_217 ( V_592 , V_672 ) ) {
if ( V_602 -> V_604 [ V_67 ] . V_592 & V_681 ) {
V_18 = - V_169 ;
goto V_705;
}
if ( V_592 -> V_682 < V_672 -> V_682 ) {
V_18 = - V_97 ;
goto V_705;
}
V_675 = V_67 ;
break;
}
if ( V_678 == V_671 ) {
if ( V_675 < 0 ) {
V_18 = - V_169 ;
goto V_705;
}
break;
}
++ V_678 ;
}
V_672 = F_225 ( V_602 , V_675 ) ;
if ( V_672 ) {
V_607 = true ;
} else {
V_672 = F_240 ( sizeof( * V_592 ) , V_295 ) ;
if ( ! V_672 ) {
V_18 = - V_71 ;
goto V_705;
}
* V_672 = * V_592 ;
}
F_227 ( V_602 , V_675 , V_672 ,
V_681 ) ;
F_104 ( & V_2 -> V_679 ) ;
V_475 = V_607 << 31 | V_675 << 16 | V_592 -> V_648 ;
F_228 ( V_2 , V_592 , V_47 ,
V_602 -> V_604 [ V_675 ] . V_606 , V_607 ) ;
F_179 ( V_2 , V_661 , V_47 , sizeof( V_47 ) ,
V_660 ,
V_706 , V_475 ) ;
return V_675 ;
V_705:
F_104 ( & V_2 -> V_679 ) ;
return V_18 ;
}
static void
V_706 ( struct V_1 * V_2 , unsigned long V_475 ,
int V_18 , T_1 * V_13 ,
T_2 V_476 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
unsigned int V_675 , V_648 ;
struct V_585 * V_592 ;
bool V_607 ;
V_607 = V_475 >> 31 ;
V_675 = ( V_475 >> 16 ) & ( V_680 - 1 ) ;
V_648 = V_475 & 0xffff ;
F_106 ( & V_2 -> V_679 ) ;
V_592 = F_225 ( V_602 , V_675 ) ;
if ( V_18 == 0 ) {
V_602 -> V_604 [ V_675 ] . V_606 =
F_231 ( V_13 , V_662 ) ;
if ( V_607 )
V_592 -> V_648 = V_648 ;
} else if ( ! V_607 ) {
F_48 ( V_592 ) ;
V_592 = NULL ;
}
F_227 ( V_602 , V_675 , V_592 , 0 ) ;
F_104 ( & V_2 -> V_679 ) ;
F_242 ( & V_602 -> V_687 ) ;
}
static bool F_257 ( struct V_1 * V_2 , T_6 V_707 ,
unsigned int V_603 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_585 * V_592 =
F_225 ( V_602 , V_603 ) ;
F_8 ( V_47 ,
V_695 +
V_696 ) ;
if ( ! V_592 ||
( V_602 -> V_604 [ V_603 ] . V_592 & V_681 ) ||
V_592 -> V_682 != V_704 ||
! F_258 ( V_2 -> V_28 , V_592 -> V_648 ,
V_707 , V_603 ) )
return false ;
F_21 ( V_47 , V_612 ,
V_698 ) ;
F_107 ( V_47 , V_614 ,
V_602 -> V_604 [ V_603 ] . V_606 ) ;
if ( F_179 ( V_2 , V_661 , V_47 , sizeof( V_47 ) , 0 ,
V_708 , V_603 ) )
return false ;
V_602 -> V_604 [ V_603 ] . V_592 |= V_681 ;
return true ;
}
static void
V_708 ( struct V_1 * V_2 ,
unsigned long V_603 ,
int V_18 , T_1 * V_13 ,
T_2 V_476 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_585 * V_592 =
F_225 ( V_602 , V_603 ) ;
F_106 ( & V_2 -> V_679 ) ;
if ( V_18 == 0 ) {
F_48 ( V_592 ) ;
F_227 ( V_602 , V_603 , NULL , 0 ) ;
}
V_602 -> V_604 [ V_603 ] . V_592 &= ~ V_681 ;
F_242 ( & V_602 -> V_687 ) ;
F_104 ( & V_2 -> V_679 ) ;
}
static int F_259 ( T_6 V_709 )
{
int V_588 = 0 ;
#define F_260 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_260 ( V_710 , V_711 ) ;
F_260 ( V_710 , V_712 ) ;
F_260 ( V_621 , V_623 ) ;
F_260 ( V_624 , V_625 ) ;
F_260 ( V_626 , V_628 ) ;
F_260 ( V_629 , V_631 ) ;
F_260 ( V_632 , V_633 ) ;
F_260 ( V_634 , V_636 ) ;
F_260 ( V_637 , V_637 ) ;
F_260 ( V_638 , V_640 ) ;
F_260 ( V_641 , V_642 ) ;
F_260 ( V_643 , V_643 ) ;
#undef F_260
if ( V_709 )
return - V_215 ;
return V_588 ;
}
static int F_261 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_713 ) ;
F_8 ( V_13 , V_714 ) ;
unsigned int V_715 , V_716 ;
struct V_601 * V_602 ;
T_2 V_17 ;
int V_18 ;
V_602 = F_29 ( sizeof( * V_602 ) , V_70 ) ;
if ( ! V_602 )
return - V_71 ;
F_21 ( V_47 , V_717 ,
V_718 ) ;
V_18 = F_9 ( V_2 , V_719 ,
V_47 , sizeof( V_47 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_135;
V_716 = F_262 (
V_17 , V_720 ) ;
V_602 -> V_665 = 0 ;
for ( V_715 = 0 ; V_715 < V_716 ; V_715 ++ ) {
T_6 V_709 =
F_263 (
V_13 ,
V_720 ,
V_715 ) ;
V_18 = F_259 ( V_709 ) ;
if ( V_18 < 0 ) {
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_53 ,
V_434 , V_709 , V_715 ) ;
} else {
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_54 ,
V_434 , V_709 , V_715 ,
V_18 , V_602 -> V_665 ) ;
V_602 -> V_666 [ V_602 -> V_665 ++ ] = V_18 ;
}
}
V_602 -> V_604 = F_264 ( V_680 * sizeof( * V_602 -> V_604 ) ) ;
if ( ! V_602 -> V_604 ) {
V_18 = - V_71 ;
goto V_135;
}
V_602 -> V_721 = V_722 ;
V_602 -> V_723 = V_722 ;
V_602 -> V_724 = V_722 ;
V_2 -> V_669 = V_602 ;
F_265 ( & V_602 -> V_687 ) ;
return 0 ;
V_135:
F_48 ( V_602 ) ;
return V_18 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_585 * V_592 ;
unsigned int V_603 ;
bool V_725 = false ;
int V_18 ;
F_22 ( ! F_267 ( & V_2 -> V_726 ) ) ;
if ( ! V_16 -> V_197 )
return;
if ( ! V_602 )
return;
F_106 ( & V_2 -> V_679 ) ;
for ( V_603 = 0 ; V_603 < V_680 ; V_603 ++ ) {
V_592 = F_225 ( V_602 , V_603 ) ;
if ( ! V_592 )
continue;
V_602 -> V_604 [ V_603 ] . V_592 |= V_681 ;
F_104 ( & V_2 -> V_679 ) ;
V_18 = F_230 ( V_2 , V_592 ,
& V_602 -> V_604 [ V_603 ] . V_606 ,
false ) ;
if ( V_18 )
V_725 = true ;
F_106 ( & V_2 -> V_679 ) ;
if ( V_18 ) {
F_48 ( V_592 ) ;
F_227 ( V_602 , V_603 , NULL , 0 ) ;
} else {
V_602 -> V_604 [ V_603 ] . V_592 &=
~ V_681 ;
}
}
F_104 ( & V_2 -> V_679 ) ;
if ( V_725 )
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_55 ) ;
else
V_16 -> V_197 = false ;
}
static void F_268 ( struct V_1 * V_2 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
F_8 ( V_47 , V_608 ) ;
struct V_585 * V_592 ;
unsigned int V_603 ;
int V_18 ;
V_2 -> V_669 = NULL ;
if ( ! V_602 )
return;
for ( V_603 = 0 ; V_603 < V_680 ; V_603 ++ ) {
V_592 = F_225 ( V_602 , V_603 ) ;
if ( ! V_592 )
continue;
F_21 ( V_47 , V_612 ,
F_221 ( V_592 ) ?
V_698 :
V_691 ) ;
F_107 ( V_47 , V_614 ,
V_602 -> V_604 [ V_603 ] . V_606 ) ;
V_18 = F_51 ( V_2 , V_661 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
if ( V_18 )
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_56 ,
V_434 , V_603 ) ;
F_48 ( V_592 ) ;
}
F_269 ( V_602 -> V_604 ) ;
F_48 ( V_602 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
unsigned int V_603 , V_67 ;
if ( ! V_602 )
return;
F_106 ( & V_2 -> V_679 ) ;
for ( V_67 = 0 ; V_67 < V_602 -> V_727 ; V_67 ++ )
F_271 ( V_602 -> V_728 [ V_67 ] . V_729 ) ;
for ( V_67 = 0 ; V_67 < V_602 -> V_730 ; V_67 ++ )
F_271 ( V_602 -> V_731 [ V_67 ] . V_729 ) ;
F_271 ( V_602 -> V_721 ) ;
F_271 ( V_602 -> V_723 ) ;
F_271 ( V_602 -> V_724 ) ;
F_104 ( & V_2 -> V_679 ) ;
}
static void F_272 ( struct V_1 * V_2 , bool * V_732 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_66 * V_28 = V_2 -> V_28 ;
struct V_733 * V_734 ;
int V_735 ;
unsigned int V_67 ;
V_602 -> V_721 = V_722 ;
V_735 = F_273 ( V_28 ) ;
if ( V_28 -> V_204 & V_736 )
* V_732 = true ;
V_602 -> V_727 = 1 + V_735 ;
F_18 ( V_602 -> V_728 [ 0 ] . V_281 , V_28 -> V_737 ) ;
V_67 = 1 ;
F_274 (uc, net_dev) {
if ( V_67 >= V_738 ) {
* V_732 = true ;
break;
}
F_18 ( V_602 -> V_728 [ V_67 ] . V_281 , V_734 -> V_281 ) ;
V_602 -> V_728 [ V_67 ] . V_729 = V_722 ;
V_67 ++ ;
}
}
static void F_275 ( struct V_1 * V_2 , bool * V_732 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_66 * V_28 = V_2 -> V_28 ;
struct V_733 * V_739 ;
unsigned int V_67 , V_735 ;
V_602 -> V_724 = V_722 ;
V_602 -> V_723 = V_722 ;
if ( V_28 -> V_204 & ( V_736 | V_740 ) )
* V_732 = true ;
V_735 = F_276 ( V_28 ) ;
V_67 = 0 ;
F_277 (mc, net_dev) {
if ( V_67 >= V_741 ) {
* V_732 = true ;
break;
}
F_18 ( V_602 -> V_731 [ V_67 ] . V_281 , V_739 -> V_281 ) ;
V_602 -> V_731 [ V_67 ] . V_729 = V_722 ;
V_67 ++ ;
}
V_602 -> V_730 = V_67 ;
}
static int F_278 ( struct V_1 * V_2 ,
bool V_256 , bool V_742 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_743 * V_744 ;
enum V_745 V_746 ;
struct V_585 V_592 ;
T_3 V_747 [ V_748 ] ;
unsigned int V_67 , V_749 ;
int V_735 ;
int V_18 ;
if ( V_256 ) {
V_744 = V_602 -> V_731 ;
V_735 = V_602 -> V_730 ;
} else {
V_744 = V_602 -> V_728 ;
V_735 = V_602 -> V_727 ;
}
V_746 = F_246 ( V_2 ) ? V_609 : 0 ;
for ( V_67 = 0 ; V_67 < V_735 ; V_67 ++ ) {
F_279 ( & V_592 , V_683 , V_746 , 0 ) ;
F_280 ( & V_592 , V_750 ,
V_744 [ V_67 ] . V_281 ) ;
V_18 = F_233 ( V_2 , & V_592 , true ) ;
if ( V_18 < 0 ) {
if ( V_742 ) {
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_57 ,
V_18 ) ;
for ( V_749 = 0 ; V_749 < V_67 ; V_749 ++ ) {
if ( V_744 [ V_749 ] . V_729 == V_722 )
continue;
F_249 (
V_2 , V_683 ,
V_744 [ V_749 ] . V_729 ) ;
V_744 [ V_749 ] . V_729 = V_722 ;
}
return V_18 ;
} else {
V_18 = V_722 ;
}
}
V_744 [ V_67 ] . V_729 = F_248 ( V_2 , V_18 ) ;
}
if ( V_256 && V_742 ) {
F_279 ( & V_592 , V_683 , V_746 , 0 ) ;
F_281 ( V_747 ) ;
F_280 ( & V_592 , V_750 , V_747 ) ;
V_18 = F_233 ( V_2 , & V_592 , true ) ;
if ( V_18 < 0 ) {
F_166 ( V_2 , V_27 , V_2 -> V_28 ,
L_58 , V_18 ) ;
for ( V_749 = 0 ; V_749 < V_67 ; V_749 ++ ) {
if ( V_744 [ V_749 ] . V_729 == V_722 )
continue;
F_249 (
V_2 , V_683 ,
V_744 [ V_749 ] . V_729 ) ;
V_744 [ V_749 ] . V_729 = V_722 ;
}
return V_18 ;
} else {
V_602 -> V_723 = F_248 ( V_2 , V_18 ) ;
}
}
return 0 ;
}
static int F_282 ( struct V_1 * V_2 , bool V_256 ,
bool V_742 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_15 * V_16 = V_2 -> V_16 ;
enum V_745 V_746 ;
struct V_585 V_592 ;
T_3 V_747 [ V_748 ] ;
int V_18 ;
V_746 = F_246 ( V_2 ) ? V_609 : 0 ;
F_279 ( & V_592 , V_683 , V_746 , 0 ) ;
if ( V_256 )
F_283 ( & V_592 ) ;
else
F_284 ( & V_592 ) ;
V_18 = F_233 ( V_2 , & V_592 , true ) ;
if ( V_18 < 0 ) {
F_285 ( V_2 , V_27 , V_18 == - V_97 ? V_751 : V_752 ,
V_2 -> V_28 ,
L_59 ,
V_256 ? L_60 : L_61 , V_18 ) ;
} else if ( V_256 ) {
V_602 -> V_724 = F_248 ( V_2 , V_18 ) ;
if ( ! V_16 -> V_504 ) {
F_279 ( & V_592 , V_683 ,
V_746 , 0 ) ;
F_281 ( V_747 ) ;
F_280 ( & V_592 , V_750 ,
V_747 ) ;
V_18 = F_233 ( V_2 , & V_592 , true ) ;
if ( V_18 < 0 ) {
F_166 ( V_2 , V_27 , V_2 -> V_28 ,
L_58 ,
V_18 ) ;
if ( V_742 ) {
F_249 (
V_2 , V_683 ,
V_602 -> V_724 ) ;
V_602 -> V_724 = V_722 ;
return V_18 ;
}
} else {
V_602 -> V_723 = F_248 ( V_2 , V_18 ) ;
}
}
V_18 = 0 ;
} else {
V_602 -> V_721 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
int V_753 = 0 ;
int V_754 = 0 ;
int V_18 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_680 ; V_67 ++ ) {
if ( F_131 ( V_602 -> V_604 [ V_67 ] . V_592 ) &
V_690 ) {
V_18 = F_245 ( V_2 ,
1U << V_683 , V_67 , true ) ;
if ( V_18 == - V_101 )
V_754 ++ ;
else if ( V_18 )
V_753 ++ ;
}
}
if ( V_753 )
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_62 ,
V_434 , V_753 ) ;
if ( V_754 )
F_63 ( V_2 , V_27 , V_2 -> V_28 ,
L_63 ,
V_434 , V_754 ) ;
}
static int F_287 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_755 [ V_748 ] ;
int V_18 , V_756 ;
if ( F_288 ( V_16 -> V_757 ) )
return 0 ;
F_289 ( V_2 ) ;
F_290 ( V_2 -> V_28 ) ;
F_291 ( & V_2 -> V_726 ) ;
F_268 ( V_2 ) ;
F_292 ( & V_2 -> V_726 ) ;
V_18 = F_70 ( V_2 , V_16 -> V_79 ) ;
if ( V_18 )
goto V_758;
F_18 ( V_755 , V_16 -> V_757 ) ;
V_18 = F_72 ( V_2 , V_16 -> V_79 ,
V_16 -> V_757 ) ;
if ( V_18 )
goto V_759;
V_18 = F_71 ( V_2 , V_16 -> V_79 ,
V_2 -> V_28 -> V_737 ) ;
if ( ! V_18 ) {
F_18 ( V_16 -> V_757 , V_2 -> V_28 -> V_737 ) ;
} else {
V_756 = F_71 ( V_2 , V_16 -> V_79 , V_755 ) ;
if ( V_756 ) {
F_293 ( V_16 -> V_757 ) ;
goto V_760;
}
}
V_759:
V_756 = F_69 ( V_2 , V_16 -> V_79 ) ;
if ( V_756 )
goto V_760;
V_758:
F_291 ( & V_2 -> V_726 ) ;
V_756 = F_261 ( V_2 ) ;
F_292 ( & V_2 -> V_726 ) ;
if ( V_756 )
goto V_760;
V_756 = F_294 ( V_2 -> V_28 ) ;
if ( V_756 )
goto V_760;
F_295 ( V_2 -> V_28 ) ;
return V_18 ;
V_760:
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_64 ) ;
F_187 ( V_2 , V_203 ) ;
return V_18 ? V_18 : V_756 ;
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_601 * V_602 = V_2 -> V_669 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_66 * V_28 = V_2 -> V_28 ;
bool V_761 = false , V_762 = false ;
if ( ! F_297 ( V_2 ) )
return;
if ( ! V_602 )
return;
F_270 ( V_2 ) ;
F_298 ( V_28 ) ;
F_272 ( V_2 , & V_761 ) ;
F_275 ( V_2 , & V_762 ) ;
F_299 ( V_28 ) ;
if ( V_761 ) {
F_282 ( V_2 , false , false ) ;
F_278 ( V_2 , false , false ) ;
} else {
if ( F_278 ( V_2 , false , false ) )
F_282 ( V_2 , false , false ) ;
}
if ( V_16 -> V_504 && V_2 -> V_762 != V_762 )
F_286 ( V_2 ) ;
if ( V_762 ) {
if ( V_16 -> V_504 ) {
if ( F_282 ( V_2 , true , true ) ) {
F_286 ( V_2 ) ;
F_278 ( V_2 , true , false ) ;
}
} else {
F_282 ( V_2 , true , false ) ;
F_278 ( V_2 , true , false ) ;
}
} else {
if ( F_278 ( V_2 , true , true ) ) {
if ( V_16 -> V_504 )
F_286 ( V_2 ) ;
if ( F_282 ( V_2 , true , true ) )
F_278 ( V_2 , true , false ) ;
}
}
F_286 ( V_2 ) ;
V_2 -> V_762 = V_762 ;
}
static int F_300 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_763 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_764 = V_2 -> V_765 ;
int V_18 ;
F_289 ( V_2 ) ;
F_290 ( V_2 -> V_28 ) ;
F_291 ( & V_2 -> V_726 ) ;
F_268 ( V_2 ) ;
F_18 ( F_19 ( V_47 , V_766 ) ,
V_2 -> V_28 -> V_737 ) ;
F_21 ( V_47 , V_767 ,
V_16 -> V_79 ) ;
V_18 = F_51 ( V_2 , V_768 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
F_261 ( V_2 ) ;
F_292 ( & V_2 -> V_726 ) ;
if ( V_764 )
F_294 ( V_2 -> V_28 ) ;
F_295 ( V_2 -> V_28 ) ;
#ifdef F_44
if ( V_2 -> V_10 -> V_151 && V_2 -> V_10 -> V_102 ) {
struct V_10 * V_104 = V_2 -> V_10 -> V_102 ;
if ( V_18 == - V_97 ) {
struct V_1 * V_105 ;
V_105 = F_24 ( V_104 ) ;
V_18 = F_301 ( V_105 ,
V_16 -> V_22 ,
V_2 -> V_28 -> V_737 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_105 = F_24 ( V_104 ) ;
struct V_15 * V_16 = V_105 -> V_16 ;
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_105 -> V_199 ; ++ V_67 ) {
struct V_149 * V_150 = V_16 -> V_150 + V_67 ;
if ( V_150 -> V_2 == V_2 ) {
F_18 ( V_150 -> V_160 ,
V_2 -> V_28 -> V_737 ) ;
return 0 ;
}
}
}
} else
#endif
if ( V_18 == - V_97 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_65
L_66 ) ;
} else if ( V_18 == - V_100 && ! F_6 ( V_2 ) ) {
V_18 = F_287 ( V_2 ) ;
} else {
F_52 ( V_2 , V_768 ,
sizeof( V_47 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_302 ( struct V_1 * V_2 )
{
F_296 ( V_2 ) ;
return F_303 ( V_2 ) ;
}
static int F_304 ( struct V_1 * V_2 )
{
F_296 ( V_2 ) ;
return 0 ;
}
static int F_305 ( struct V_1 * V_2 , T_6 V_769 )
{
F_8 ( V_47 , V_770 ) ;
F_21 ( V_47 , V_771 , V_769 ) ;
return F_9 ( V_2 , V_772 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
static int F_306 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_773 ) ;
T_2 V_17 ;
T_6 V_774 ;
V_18 = F_9 ( V_2 , V_775 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_773 )
return - V_7 ;
V_774 = F_10 ( V_13 , V_776 ) ;
switch ( V_774 ) {
case V_777 :
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_67 ) ;
return 0 ;
case V_778 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_68 ) ;
return - V_7 ;
case V_779 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_69 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_70 , V_774 ) ;
return - V_7 ;
}
}
static int F_307 ( struct V_1 * V_2 , T_6 V_769 )
{
int V_18 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_71 , V_769 ) ;
V_18 = F_305 ( V_2 , V_769 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_306 ( V_2 ) ;
}
static int
F_308 ( struct V_1 * V_2 , struct V_780 * V_781 )
{
int V_18 , V_756 ;
F_309 ( V_2 , V_214 ) ;
V_18 = F_9 ( V_2 , V_782 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_304;
V_781 -> V_783 = F_307 ( V_2 , V_784 ) ? - 1 : 1 ;
V_781 -> V_785 = F_307 ( V_2 , V_786 ) ? - 1 : 1 ;
V_18 = F_35 ( V_2 , V_214 ) ;
V_304:
if ( V_18 == - V_97 )
V_18 = 0 ;
V_756 = F_310 ( V_2 , V_214 , V_18 == 0 ) ;
return V_18 ? V_18 : V_756 ;
}
static int F_311 ( struct V_1 * V_2 ,
struct V_787 * V_788 ,
unsigned int type )
{
F_8 ( V_47 , V_789 ) ;
F_8 ( V_13 , V_790 ) ;
const struct V_791 * V_792 ;
T_2 V_701 , V_793 , V_17 ;
bool V_794 ;
int V_18 ;
for ( V_792 = V_795 ; ; V_792 ++ ) {
if ( V_792 ==
V_795 + F_160 ( V_795 ) )
return - V_37 ;
if ( ( type & ~ V_792 -> V_796 ) == V_792 -> type )
break;
}
if ( V_792 -> V_797 != F_312 ( V_2 ) )
return - V_37 ;
V_18 = F_313 ( V_2 , type , & V_701 , & V_793 , & V_794 ) ;
if ( V_18 )
return V_18 ;
if ( V_794 )
return - V_37 ;
V_788 -> V_798 = type ;
F_21 ( V_47 , V_799 , type ) ;
V_18 = F_9 ( V_2 , V_800 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_801 )
return - V_7 ;
if ( F_10 ( V_13 , V_802 ) &
( 1 << V_803 ) )
V_788 -> V_804 = F_10 ( V_13 ,
V_805 ) ;
V_788 -> V_806 . V_807 = L_72 ;
V_788 -> V_806 . V_808 = V_792 -> V_237 ;
V_788 -> V_806 . V_809 . type = V_810 ;
V_788 -> V_806 . V_809 . V_204 = V_811 ;
V_788 -> V_806 . V_809 . V_701 = V_701 ;
V_788 -> V_806 . V_809 . V_812 = V_793 ;
return 0 ;
}
static int F_314 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_813 ) ;
struct V_787 * V_814 ;
T_2 V_17 , V_815 , V_67 , V_816 ;
unsigned int type ;
int V_18 ;
F_315 () ;
F_13 ( V_817 != 0 ) ;
V_18 = F_9 ( V_2 , V_818 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_819 )
return - V_7 ;
V_815 = F_10 ( V_13 , V_820 ) ;
if ( V_815 >
F_262 ( V_17 , V_821 ) )
return - V_7 ;
V_814 = F_316 ( V_815 , sizeof( * V_814 ) , V_70 ) ;
if ( ! V_814 )
return - V_71 ;
V_816 = 0 ;
for ( V_67 = 0 ; V_67 < V_815 ; V_67 ++ ) {
type = F_263 ( V_13 , V_821 ,
V_67 ) ;
V_18 = F_311 ( V_2 , & V_814 [ V_816 ] , type ) ;
if ( V_18 == 0 )
V_816 ++ ;
else if ( V_18 != - V_37 )
goto V_135;
}
V_18 = F_317 ( V_2 , & V_814 [ 0 ] . V_806 , V_816 , sizeof( * V_814 ) ) ;
V_135:
if ( V_18 )
F_48 ( V_814 ) ;
return V_18 ;
}
static void F_318 ( struct V_1 * V_2 , T_6 V_822 )
{
F_32 ( V_2 , F_33 ( V_822 ) , V_328 ) ;
}
static void F_319 ( struct V_1 * V_2 ,
T_6 V_822 ) {}
static int F_320 ( struct V_123 * V_124 ,
bool V_823 )
{
F_8 ( V_47 , V_824 ) ;
int V_18 ;
if ( V_124 -> V_825 == V_826 ||
V_124 -> V_825 == V_827 ||
( V_823 && V_124 -> V_825 == V_828 ) )
return 0 ;
V_124 -> V_825 = V_826 ;
F_21 ( V_47 , V_829 , V_830 ) ;
F_21 ( V_47 , V_831 , 0 ) ;
F_21 ( V_47 , V_832 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_833 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_124 -> V_825 = V_823 ? V_834 :
V_828 ;
return V_18 ;
}
static int F_321 ( struct V_123 * V_124 ,
bool V_823 )
{
F_8 ( V_47 , V_835 ) ;
int V_18 ;
if ( V_124 -> V_825 == V_828 ||
( V_823 && V_124 -> V_825 == V_834 ) )
return 0 ;
if ( V_124 -> V_825 == V_834 ) {
V_124 -> V_825 = V_828 ;
return 0 ;
}
V_124 -> V_825 = V_823 ? V_834 :
V_828 ;
F_21 ( V_47 , V_829 , V_836 ) ;
F_21 ( V_47 , V_831 , 0 ) ;
F_21 ( V_47 , V_837 ,
V_838 ) ;
F_21 ( V_47 , V_839 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_833 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_322 ( struct V_1 * V_2 , bool V_840 ,
bool V_823 )
{
int (* F_323)( struct V_123 * V_124 , bool V_823 );
struct V_123 * V_124 ;
F_323 = V_840 ?
F_320 :
F_321 ;
F_58 (channel, efx) {
int V_18 = F_323 ( V_124 , V_823 ) ;
if ( V_840 && V_18 != 0 ) {
F_322 ( V_2 , false , V_823 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_324 ( struct V_1 * V_2 ,
struct V_841 * V_842 )
{
return - V_319 ;
}
static int F_325 ( struct V_1 * V_2 ,
struct V_841 * V_842 )
{
int V_18 ;
switch ( V_842 -> V_843 ) {
case V_844 :
F_322 ( V_2 , false , false ) ;
return F_326 ( V_2 ,
V_842 -> V_845 != V_846 , 0 ) ;
case V_847 :
case V_848 :
case V_849 :
case V_850 :
case V_851 :
case V_852 :
case V_853 :
case V_854 :
case V_855 :
case V_856 :
case V_857 :
case V_858 :
case V_859 :
V_842 -> V_843 = V_847 ;
V_18 = F_326 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_322 ( V_2 , true , false ) ;
if ( V_18 )
F_326 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_41 ;
}
}
