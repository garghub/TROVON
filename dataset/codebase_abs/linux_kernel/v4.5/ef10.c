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
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_11 ) ;
}
#endif
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_16 -> V_152 )
F_66 ( V_16 -> V_152 ) ;
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
static int F_67 ( struct V_1 * V_2 )
{
return F_27 ( V_2 ) ;
}
int F_68 ( struct V_1 * V_2 , unsigned int V_106 )
{
F_8 ( V_47 , V_154 ) ;
F_21 ( V_47 , V_155 , V_106 ) ;
return F_9 ( V_2 , V_156 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
int F_69 ( struct V_1 * V_2 , unsigned int V_106 )
{
F_8 ( V_47 , V_157 ) ;
F_21 ( V_47 , V_158 , V_106 ) ;
return F_9 ( V_2 , V_159 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
int F_70 ( struct V_1 * V_2 ,
unsigned int V_106 , T_3 * V_160 )
{
F_8 ( V_47 , V_161 ) ;
F_21 ( V_47 , V_162 , V_106 ) ;
F_18 ( F_19 ( V_47 , V_163 ) , V_160 ) ;
return F_9 ( V_2 , V_164 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
int F_71 ( struct V_1 * V_2 ,
unsigned int V_106 , T_3 * V_160 )
{
F_8 ( V_47 , V_165 ) ;
F_21 ( V_47 , V_166 , V_106 ) ;
F_18 ( F_19 ( V_47 , V_167 ) , V_160 ) ;
return F_9 ( V_2 , V_168 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_10 * V_104 ;
V_104 = V_2 -> V_10 -> V_102 ;
if ( V_104 ) {
struct V_1 * V_105 = F_24 ( V_104 ) ;
struct V_15 * V_148 = V_105 -> V_16 ;
if ( ! V_148 -> V_150 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
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
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_11 ) ;
}
return 0 ;
V_135:
F_61 ( V_2 ) ;
return V_18 ;
}
static int F_73 ( struct V_1 * V_2 ,
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
static int F_74 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_182 , V_183 ;
unsigned int V_171 = F_57 ( V_184 ,
V_185 ? 2 : 1 ) ;
unsigned int V_186 , V_133 , V_172 ;
void T_5 * V_187 ;
int V_18 ;
V_186 = F_57 ( V_2 -> V_188 , V_2 -> V_137 * V_184 ) ;
#ifdef F_75
if ( V_138 != 0 &&
V_139 / V_138 * V_189 >=
V_2 -> V_137 ) {
unsigned int V_111 =
F_76 ( V_2 -> V_137 ,
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
V_182 = F_77 ( ( V_186 - 1 ) * V_143 +
V_190 ) ;
if ( V_16 -> V_111 ) {
V_133 = V_182 / V_143 ;
V_183 = ( F_77 ( ( V_133 +
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
V_18 = F_73 ( V_2 , V_171 , V_172 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_16 -> V_180 < V_186 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
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
V_187 = F_78 ( V_2 -> V_192 , V_182 ) ;
if ( ! V_187 ) {
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_20 ,
V_182 ) ;
return - V_71 ;
}
F_66 ( V_2 -> V_187 ) ;
V_2 -> V_187 = V_187 ;
if ( V_183 ) {
V_16 -> V_152 = F_79 ( V_2 -> V_192 +
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
static int F_80 ( struct V_1 * V_2 )
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
V_18 = F_73 ( V_2 , V_16 -> V_180 ,
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
static void F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
#ifdef F_44
unsigned int V_67 ;
#endif
V_16 -> V_194 = true ;
V_16 -> V_197 = true ;
V_16 -> V_153 = true ;
V_16 -> V_77 = V_78 ;
V_16 -> V_198 = true ;
V_16 -> V_79 = V_52 ;
#ifdef F_44
if ( V_16 -> V_150 )
for ( V_67 = 0 ; V_67 < V_2 -> V_199 ; V_67 ++ )
V_16 -> V_150 [ V_67 ] . V_79 = 0 ;
#endif
}
static enum V_200 F_82 ( enum V_200 V_201 )
{
if ( V_201 == V_202 )
return V_203 ;
return F_83 ( V_201 ) ;
}
static int F_84 ( T_6 * V_204 )
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
static int F_85 ( struct V_1 * V_2 , enum V_200 V_200 )
{
int V_18 = F_35 ( V_2 , V_200 ) ;
if ( V_200 == V_214 && V_18 == - V_97 )
V_18 = 0 ;
if ( ( V_200 == V_81 ||
V_200 == V_216 ) && ! V_18 )
F_81 ( V_2 ) ;
return V_18 ;
}
static T_7 F_86 ( struct V_1 * V_2 )
{
T_7 V_217 = V_218 ;
T_6 V_219 = F_87 ( V_2 ) ;
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
static void F_88 ( struct V_1 * V_2 , unsigned long * V_225 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_7 V_217 [ 2 ] ;
V_217 [ 0 ] = F_86 ( V_2 ) ;
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
static T_2 F_89 ( struct V_1 * V_2 , T_3 * V_230 )
{
F_90 ( V_225 , V_228 ) ;
F_88 ( V_2 , V_225 ) ;
return F_91 ( V_231 , V_228 ,
V_225 , V_230 ) ;
}
static T_2 F_92 ( struct V_1 * V_2 , T_7 * V_232 ,
struct V_233 * V_234 )
{
F_90 ( V_225 , V_228 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_7 * V_235 = V_16 -> V_235 ;
T_2 V_236 = 0 , V_128 ;
F_88 ( V_2 , V_225 ) ;
if ( V_232 ) {
F_93 (index, mask, EF10_STAT_COUNT) {
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
static int F_94 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_90 ( V_225 , V_228 ) ;
T_8 V_277 , V_278 ;
T_7 * V_235 = V_16 -> V_235 ;
T_8 * V_279 ;
F_88 ( V_2 , V_225 ) ;
V_279 = V_2 -> V_280 . V_281 ;
V_16 = V_2 -> V_16 ;
V_278 = V_279 [ V_282 ] ;
if ( V_278 == V_283 )
return 0 ;
F_95 () ;
F_96 ( V_231 , V_228 , V_225 ,
V_235 , V_2 -> V_280 . V_281 , false ) ;
F_95 () ;
V_277 = V_279 [ V_284 ] ;
if ( V_278 != V_277 )
return - V_191 ;
F_97 ( V_2 ,
& V_235 [ V_268 ] ) ;
V_235 [ V_285 ] =
V_235 [ V_266 ] -
V_235 [ V_286 ] ;
F_98 ( & V_235 [ V_287 ] ,
V_235 [ V_286 ] ) ;
F_99 ( V_2 , V_235 ) ;
return 0 ;
}
static T_2 F_100 ( struct V_1 * V_2 , T_7 * V_232 ,
struct V_233 * V_234 )
{
int V_288 ;
for ( V_288 = 0 ; V_288 < 100 ; ++ V_288 ) {
if ( F_94 ( V_2 ) == 0 )
break;
F_101 ( 100 ) ;
}
return F_92 ( V_2 , V_232 , V_234 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_289 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
F_90 ( V_225 , V_228 ) ;
T_8 V_277 , V_278 ;
T_7 * V_235 = V_16 -> V_235 ;
T_6 V_290 = V_291 * sizeof( T_7 ) ;
struct V_292 V_293 ;
T_8 * V_279 ;
int V_18 ;
F_103 ( & V_2 -> V_294 ) ;
if ( F_104 () ) {
F_105 ( & V_2 -> V_294 ) ;
F_99 ( V_2 , V_235 ) ;
return 0 ;
}
F_88 ( V_2 , V_225 ) ;
V_18 = F_30 ( V_2 , & V_293 , V_290 , V_295 ) ;
if ( V_18 ) {
F_105 ( & V_2 -> V_294 ) ;
return V_18 ;
}
V_279 = V_293 . V_281 ;
V_279 [ V_282 ] = V_283 ;
F_106 ( V_47 , V_296 , V_293 . V_297 ) ;
F_107 ( V_47 , V_298 ,
V_299 , 1 ) ;
F_21 ( V_47 , V_300 , V_290 ) ;
F_21 ( V_47 , V_301 , V_52 ) ;
V_18 = F_51 ( V_2 , V_302 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_294 ) ;
if ( V_18 ) {
if ( V_18 != - V_101 || F_108 ( & V_2 -> V_303 ) )
F_52 ( V_2 , V_302 ,
sizeof( V_47 ) , NULL , 0 , V_18 ) ;
goto V_304;
}
V_278 = V_279 [ V_282 ] ;
if ( V_278 == V_283 ) {
F_109 ( 1 ) ;
goto V_304;
}
F_95 () ;
F_96 ( V_231 , V_228 , V_225 ,
V_235 , V_293 . V_281 , false ) ;
F_95 () ;
V_277 = V_279 [ V_284 ] ;
if ( V_278 != V_277 ) {
V_18 = - V_191 ;
goto V_304;
}
F_99 ( V_2 , V_235 ) ;
V_304:
F_47 ( V_2 , & V_293 ) ;
return V_18 ;
}
static T_2 F_110 ( struct V_1 * V_2 , T_7 * V_232 ,
struct V_233 * V_234 )
{
if ( F_102 ( V_2 ) )
return 0 ;
return F_92 ( V_2 , V_232 , V_234 ) ;
}
static void F_111 ( struct V_123 * V_124 )
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
if ( F_112 ( V_2 ) ) {
F_113 ( V_307 , V_309 ,
V_310 ,
V_311 , V_305 ,
V_312 , V_306 ) ;
F_114 ( V_2 , & V_307 , V_313 ,
V_124 -> V_124 ) ;
} else {
F_115 ( V_307 , V_314 , V_305 ,
V_315 , V_306 ) ;
F_114 ( V_2 , & V_307 , V_316 ,
V_124 -> V_124 ) ;
}
}
static void F_116 ( struct V_1 * V_2 ,
struct V_317 * V_318 ) {}
static int F_117 ( struct V_1 * V_2 , T_6 type )
{
return - V_319 ;
}
static void F_118 ( struct V_1 * V_2 , struct V_317 * V_318 )
{
V_318 -> V_320 = 0 ;
V_318 -> V_321 = 0 ;
memset ( & V_318 -> V_322 , 0 , sizeof( V_318 -> V_322 ) ) ;
}
static int F_119 ( struct V_1 * V_2 , T_6 type )
{
if ( type != 0 )
return - V_215 ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 ,
const T_1 * V_323 , T_2 V_324 ,
const T_1 * V_325 , T_2 V_326 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 * V_327 = V_16 -> V_73 . V_281 ;
memcpy ( V_327 , V_323 , V_324 ) ;
memcpy ( V_327 + V_324 , V_325 , V_326 ) ;
F_121 () ;
F_32 ( V_2 , F_33 ( ( T_7 ) V_16 -> V_73 . V_297 >> 32 ) ,
V_328 ) ;
F_32 ( V_2 , F_33 ( ( T_6 ) V_16 -> V_73 . V_297 ) ,
V_80 ) ;
}
static bool F_122 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_1 V_323 = * ( const T_1 * ) V_16 -> V_73 . V_281 ;
F_95 () ;
return F_3 ( V_323 , V_329 ) ;
}
static void
F_123 ( struct V_1 * V_2 , T_1 * V_13 ,
T_2 V_127 , T_2 V_17 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_3 * V_327 = V_16 -> V_73 . V_281 ;
memcpy ( V_13 , V_327 + V_127 , V_17 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_81 ( V_2 ) ;
V_16 -> V_193 = true ;
V_16 -> V_235 [ V_287 ] = 0 ;
}
static int F_125 ( struct V_1 * V_2 )
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
F_124 ( V_2 ) ;
return - V_7 ;
}
static T_9 F_126 ( int V_330 , void * V_331 )
{
struct V_332 * V_333 = V_331 ;
struct V_1 * V_2 = V_333 -> V_2 ;
F_127 ( V_2 , V_334 , V_2 -> V_28 ,
L_24 , V_330 , F_128 () ) ;
if ( F_129 ( F_130 ( V_2 -> V_335 ) ) ) {
if ( V_333 -> V_128 == V_2 -> V_336 )
V_2 -> V_337 = F_128 () ;
F_131 ( V_2 -> V_124 [ V_333 -> V_128 ] ) ;
}
return V_338 ;
}
static T_9 F_132 ( int V_330 , void * V_331 )
{
struct V_1 * V_2 = V_331 ;
bool V_339 = F_130 ( V_2 -> V_335 ) ;
struct V_123 * V_124 ;
T_1 V_3 ;
T_6 V_340 ;
F_2 ( V_2 , & V_3 , V_341 ) ;
V_340 = F_3 ( V_3 , V_342 ) ;
if ( V_340 == 0 )
return V_343 ;
if ( F_129 ( V_339 ) ) {
if ( V_340 & ( 1U << V_2 -> V_336 ) )
V_2 -> V_337 = F_128 () ;
F_58 (channel, efx) {
if ( V_340 & 1 )
F_131 ( V_124 ) ;
V_340 >>= 1 ;
}
}
F_127 ( V_2 , V_334 , V_2 -> V_28 ,
L_25 V_344 L_26 ,
V_330 , F_128 () , F_133 ( V_3 ) ) ;
return V_338 ;
}
static void F_134 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_345 ) ;
F_13 ( V_346 != 0 ) ;
F_21 ( V_47 , V_347 , V_2 -> V_336 ) ;
( void ) F_9 ( V_2 , V_348 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
static int F_135 ( struct V_125 * V_126 )
{
return F_30 ( V_126 -> V_2 , & V_126 -> V_349 . V_61 ,
( V_126 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_70 ) ;
}
static inline void F_136 ( struct V_125 * V_126 ,
const V_351 * V_349 )
{
unsigned int V_352 ;
T_10 V_3 ;
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
F_137 ( V_3 , V_354 , V_352 ) ;
V_3 . V_355 [ 0 ] = * V_349 ;
F_138 ( V_126 -> V_2 , & V_3 ,
V_356 , V_126 -> V_140 ) ;
}
static void F_139 ( struct V_125 * V_126 )
{
F_8 ( V_47 , F_140 ( V_357 * 8 /
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
F_141 ( V_47 , V_369 ,
V_370 , ! V_359 ,
V_371 , ! V_359 ) ;
F_21 ( V_47 , V_372 , 0 ) ;
F_21 ( V_47 , V_373 , V_16 -> V_79 ) ;
V_297 = V_126 -> V_349 . V_61 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_27 ,
V_126 -> V_140 , V_361 , ( T_7 ) V_297 ) ;
for ( V_67 = 0 ; V_67 < V_361 ; ++ V_67 ) {
F_142 ( V_47 , V_375 , V_67 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_140 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_376 , V_47 , V_363 ,
NULL , 0 , NULL ) ;
if ( V_18 )
goto V_135;
V_126 -> V_377 [ 0 ] . V_204 = V_378 ;
V_126 -> V_379 = 1 ;
V_349 = F_143 ( V_126 , 0 ) ;
F_144 ( * V_349 ,
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
F_121 () ;
F_136 ( V_126 , V_349 ) ;
return;
V_135:
F_145 ( V_2 -> V_28 , L_28 ,
V_126 -> V_140 ) ;
}
static void F_146 ( struct V_125 * V_126 )
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
static void F_147 ( struct V_125 * V_126 )
{
F_47 ( V_126 -> V_2 , & V_126 -> V_349 . V_61 ) ;
}
static inline void F_148 ( struct V_125 * V_126 )
{
unsigned int V_352 ;
T_1 V_3 ;
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
F_149 ( V_3 , V_390 , V_352 ) ;
F_114 ( V_126 -> V_2 , & V_3 ,
V_391 , V_126 -> V_140 ) ;
}
static void F_150 ( struct V_125 * V_126 )
{
unsigned int V_392 = V_126 -> V_353 ;
struct V_393 * V_377 ;
unsigned int V_352 ;
V_351 * V_349 ;
V_126 -> V_394 = false ;
if ( F_151 ( V_126 -> V_353 == V_126 -> V_379 ) )
return;
do {
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
V_377 = & V_126 -> V_377 [ V_352 ] ;
V_349 = F_143 ( V_126 , V_352 ) ;
++ V_126 -> V_353 ;
if ( V_377 -> V_204 & V_378 ) {
* V_349 = V_377 -> V_395 ;
} else {
F_13 ( V_396 != 1 ) ;
F_152 (
* V_349 ,
V_397 ,
V_377 -> V_204 & V_396 ,
V_398 , V_377 -> V_362 ,
V_399 , V_377 -> V_297 ) ;
}
} while ( V_126 -> V_353 != V_126 -> V_379 );
F_121 () ;
if ( F_153 ( V_126 , V_392 ) ) {
V_349 = F_143 ( V_126 ,
V_392 & V_126 -> V_350 ) ;
F_136 ( V_126 , V_349 ) ;
++ V_126 -> V_400 ;
} else {
F_148 ( V_126 ) ;
}
}
static int F_154 ( struct V_1 * V_2 , T_6 * V_333 ,
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
F_155 ( F_156 ( V_2 -> V_408 ) ,
V_409 ) ;
if ( ! V_401 && V_408 == 1 ) {
* V_333 = V_78 ;
if ( V_402 )
* V_402 = 1 ;
return 0 ;
}
F_21 ( V_47 , V_410 ,
V_16 -> V_79 ) ;
F_21 ( V_47 , V_411 , V_405 ) ;
F_21 ( V_47 , V_412 , V_408 ) ;
V_18 = F_9 ( V_2 , V_413 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_404 )
return - V_7 ;
* V_333 = F_10 ( V_13 , V_414 ) ;
if ( V_402 )
* V_402 = V_408 ;
return 0 ;
}
static void F_157 ( struct V_1 * V_2 , T_6 V_333 )
{
F_8 ( V_47 , V_415 ) ;
int V_18 ;
F_21 ( V_47 , V_416 ,
V_333 ) ;
V_18 = F_9 ( V_2 , V_417 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 != 0 ) ;
}
static int F_158 ( struct V_1 * V_2 , T_6 V_333 ,
const T_6 * V_196 )
{
F_8 ( V_418 , V_419 ) ;
F_8 ( V_420 , V_421 ) ;
int V_67 , V_18 ;
F_21 ( V_418 , V_422 ,
V_333 ) ;
F_13 ( F_159 ( V_2 -> V_196 ) !=
V_423 ) ;
for ( V_67 = 0 ; V_67 < F_159 ( V_2 -> V_196 ) ; ++ V_67 )
F_19 ( V_418 ,
V_424 ) [ V_67 ] =
( T_3 ) V_196 [ V_67 ] ;
V_18 = F_9 ( V_2 , V_425 , V_418 ,
sizeof( V_418 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_21 ( V_420 , V_426 ,
V_333 ) ;
F_13 ( F_159 ( V_2 -> V_427 ) !=
V_428 ) ;
for ( V_67 = 0 ; V_67 < F_159 ( V_2 -> V_427 ) ; ++ V_67 )
F_19 ( V_420 , V_429 ) [ V_67 ] =
V_2 -> V_427 [ V_67 ] ;
return F_9 ( V_2 , V_430 , V_420 ,
sizeof( V_420 ) , NULL , 0 , NULL ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_77 != V_78 )
F_157 ( V_2 , V_16 -> V_77 ) ;
V_16 -> V_77 = V_78 ;
}
static int F_160 ( struct V_1 * V_2 ,
unsigned * V_402 )
{
T_6 V_431 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_154 ( V_2 , & V_431 ,
false , V_402 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_77 = V_431 ;
V_16 -> V_432 = false ;
F_161 ( V_2 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 ,
const T_6 * V_196 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_431 ;
if ( V_16 -> V_77 == V_78 ||
! V_16 -> V_432 ) {
V_18 = F_154 ( V_2 , & V_431 ,
true , NULL ) ;
if ( V_18 == - V_319 )
return V_18 ;
else if ( V_18 != 0 )
goto V_74;
} else {
V_431 = V_16 -> V_77 ;
}
V_18 = F_158 ( V_2 , V_431 ,
V_196 ) ;
if ( V_18 != 0 )
goto V_75;
if ( V_16 -> V_77 != V_431 )
F_65 ( V_2 ) ;
V_16 -> V_77 = V_431 ;
V_16 -> V_432 = true ;
if ( V_196 != V_2 -> V_196 )
memcpy ( V_2 -> V_196 , V_196 ,
sizeof( V_2 -> V_196 ) ) ;
return 0 ;
V_75:
if ( V_431 != V_16 -> V_77 )
F_157 ( V_2 , V_431 ) ;
V_74:
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_29 , V_433 , V_18 ) ;
return V_18 ;
}
static int F_163 ( struct V_1 * V_2 , bool V_434 ,
const T_6 * V_196 )
{
int V_18 ;
if ( V_2 -> V_408 == 1 )
return 0 ;
V_18 = F_162 ( V_2 , V_196 ) ;
if ( V_18 == - V_147 && ! V_434 ) {
unsigned V_402 ;
bool V_435 = false ;
T_2 V_67 ;
for ( V_67 = 0 ; V_67 < F_159 ( V_2 -> V_196 ) && ! V_435 ;
V_67 ++ )
V_435 = V_196 [ V_67 ] !=
F_164 ( V_67 , V_2 -> V_408 ) ;
V_18 = F_160 ( V_2 , & V_402 ) ;
if ( V_18 == 0 ) {
if ( V_402 != V_2 -> V_408 )
F_165 ( V_2 , V_36 , V_2 -> V_28 ,
L_30
L_31
L_32
L_33 ,
V_2 -> V_408 , V_402 ) ;
else if ( V_435 )
F_165 ( V_2 , V_36 , V_2 -> V_28 ,
L_30
L_34
L_35
L_36 ) ;
else
F_62 ( V_2 , V_36 , V_2 -> V_28 ,
L_30
L_37 ) ;
}
}
return V_18 ;
}
static int F_166 ( struct V_436 * V_437 )
{
return F_30 ( V_437 -> V_2 , & V_437 -> V_438 . V_61 ,
( V_437 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_70 ) ;
}
static void F_167 ( struct V_436 * V_437 )
{
F_8 ( V_47 ,
F_168 ( V_357 * 8 /
V_358 ) ) ;
struct V_123 * V_124 = F_169 ( V_437 ) ;
T_2 V_361 = V_437 -> V_438 . V_61 . V_362 / V_358 ;
struct V_1 * V_2 = V_437 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_363 ;
T_11 V_297 ;
int V_18 ;
int V_67 ;
F_13 ( V_439 != 0 ) ;
V_437 -> V_440 = 0 ;
V_437 -> V_441 = 0 ;
F_21 ( V_47 , V_442 , V_437 -> V_350 + 1 ) ;
F_21 ( V_47 , V_443 , V_124 -> V_124 ) ;
F_21 ( V_47 , V_444 , F_170 ( V_437 ) ) ;
F_21 ( V_47 , V_445 ,
F_170 ( V_437 ) ) ;
F_141 ( V_47 , V_446 ,
V_447 , 1 ,
V_448 , 1 ) ;
F_21 ( V_47 , V_449 , 0 ) ;
F_21 ( V_47 , V_450 , V_16 -> V_79 ) ;
V_297 = V_437 -> V_438 . V_61 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_38 ,
F_170 ( V_437 ) , V_361 , ( T_7 ) V_297 ) ;
for ( V_67 = 0 ; V_67 < V_361 ; ++ V_67 ) {
F_142 ( V_47 , V_451 , V_67 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_168 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_452 , V_47 , V_363 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_145 ( V_2 -> V_28 , L_39 ,
F_170 ( V_437 ) ) ;
}
static void F_171 ( struct V_436 * V_437 )
{
F_8 ( V_47 , V_453 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_437 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_454 ,
F_170 ( V_437 ) ) ;
V_18 = F_51 ( V_2 , V_455 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_455 , V_453 ,
V_13 , V_17 , V_18 ) ;
}
static void F_172 ( struct V_436 * V_437 )
{
F_47 ( V_437 -> V_2 , & V_437 -> V_438 . V_61 ) ;
}
static inline void
F_173 ( struct V_436 * V_437 , unsigned int V_128 )
{
struct V_456 * V_457 ;
V_351 * V_438 ;
V_438 = F_174 ( V_437 , V_128 ) ;
V_457 = V_456 ( V_437 , V_128 ) ;
F_175 ( * V_438 ,
V_458 , V_457 -> V_362 ,
V_459 , V_457 -> V_297 ) ;
}
static void F_176 ( struct V_436 * V_437 )
{
struct V_1 * V_2 = V_437 -> V_2 ;
unsigned int V_353 ;
T_1 V_3 ;
V_353 = V_437 -> V_460 & ~ 7 ;
if ( V_437 -> V_461 == V_353 )
return;
do
F_173 (
V_437 ,
V_437 -> V_461 & V_437 -> V_350 ) ;
while ( ++ V_437 -> V_461 != V_353 );
F_121 () ;
F_149 ( V_3 , V_462 ,
V_353 & V_437 -> V_350 ) ;
F_114 ( V_2 , & V_3 , V_463 ,
F_170 ( V_437 ) ) ;
}
static void F_177 ( struct V_436 * V_437 )
{
struct V_123 * V_124 = F_169 ( V_437 ) ;
F_8 ( V_47 , V_464 ) ;
V_351 V_465 ;
F_175 ( V_465 ,
V_466 , V_467 ,
V_468 , V_469 ) ;
F_21 ( V_47 , V_470 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_47 , V_471 ) , & V_465 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
F_178 ( V_124 -> V_2 , V_472 ,
V_47 , sizeof( V_47 ) , 0 ,
V_473 , 0 ) ;
}
static void
V_473 ( struct V_1 * V_2 , unsigned long V_474 ,
int V_18 , T_1 * V_13 ,
T_2 V_475 )
{
}
static int F_179 ( struct V_123 * V_124 )
{
return F_30 ( V_124 -> V_2 , & V_124 -> V_476 . V_61 ,
( V_124 -> V_477 + 1 ) *
sizeof( V_351 ) ,
V_70 ) ;
}
static void F_180 ( struct V_123 * V_124 )
{
F_8 ( V_47 , V_478 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_479 , V_124 -> V_124 ) ;
V_18 = F_51 ( V_2 , V_480 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_480 , V_478 ,
V_13 , V_17 , V_18 ) ;
}
static int F_181 ( struct V_123 * V_124 )
{
F_8 ( V_47 ,
F_182 ( V_481 * 8 /
V_358 ) ) ;
F_8 ( V_13 , V_482 ) ;
T_2 V_361 = V_124 -> V_476 . V_61 . V_362 / V_358 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_15 * V_16 ;
bool V_483 ;
T_2 V_363 , V_17 ;
unsigned int V_98 , V_484 ;
T_11 V_297 ;
int V_18 ;
int V_67 ;
V_16 = V_2 -> V_16 ;
V_483 =
! ! ( V_16 -> V_29 &
1 << V_485 ) ;
memset ( V_124 -> V_476 . V_61 . V_281 , 0xff , V_124 -> V_476 . V_61 . V_362 ) ;
F_21 ( V_47 , V_486 , V_124 -> V_477 + 1 ) ;
F_21 ( V_47 , V_487 , V_124 -> V_124 ) ;
F_21 ( V_47 , V_488 , V_124 -> V_124 ) ;
F_183 ( V_47 , V_489 ,
V_490 , 1 ,
V_491 , 1 ,
V_492 , 1 ,
V_493 , ! V_483 ) ;
F_21 ( V_47 , V_494 ,
V_495 ) ;
F_21 ( V_47 , V_496 , 0 ) ;
F_21 ( V_47 , V_497 , 0 ) ;
F_21 ( V_47 , V_498 ,
V_499 ) ;
F_21 ( V_47 , V_500 , 0 ) ;
V_297 = V_124 -> V_476 . V_61 . V_297 ;
for ( V_67 = 0 ; V_67 < V_361 ; ++ V_67 ) {
F_142 ( V_47 , V_501 , V_67 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_182 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_502 , V_47 , V_363 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_124 -> V_124 || V_18 )
return V_18 ;
V_18 = F_40 ( V_2 , & V_484 , & V_98 ) ;
if ( V_18 == - V_100 ) {
V_16 -> V_503 = false ;
V_18 = 0 ;
} else if ( V_18 ) {
goto V_135;
} else {
V_16 -> V_503 =
! ! ( V_98 & V_504 ) ;
if ( V_484 & V_504 &&
! V_16 -> V_503 ) {
unsigned int V_204 ;
V_18 = F_39 ( V_2 ,
V_505 ,
true , & V_204 ) ;
if ( ! V_18 ) {
if ( V_204 &
1 << V_506 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_40 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 ) {
V_16 -> V_76 = V_18 ;
V_18 = 0 ;
}
}
V_16 -> V_503 = true ;
} else if ( V_18 == - V_97 ) {
V_18 = 0 ;
}
}
}
if ( ! V_18 )
return 0 ;
V_135:
F_180 ( V_124 ) ;
return V_18 ;
}
static void F_184 ( struct V_123 * V_124 )
{
F_47 ( V_124 -> V_2 , & V_124 -> V_476 . V_61 ) ;
}
static void F_185 ( struct V_436 * V_437 ,
unsigned int V_507 )
{
struct V_1 * V_2 = V_437 -> V_2 ;
F_62 ( V_2 , V_374 , V_2 -> V_28 ,
L_41 ,
F_170 ( V_437 ) , V_507 ) ;
F_186 ( V_2 , V_508 ) ;
}
static void
F_187 ( struct V_436 * V_437 ,
unsigned int V_509 , unsigned int V_510 )
{
unsigned int V_511 = ( V_509 - V_510 ) & V_437 -> V_350 ;
struct V_1 * V_2 = V_437 -> V_2 ;
F_62 ( V_2 , V_374 , V_2 -> V_28 ,
L_42 ,
V_511 , V_509 , V_510 ) ;
F_186 ( V_2 , V_508 ) ;
}
static void F_188 ( struct V_436 * V_437 )
{
unsigned int V_512 ;
F_41 ( V_437 -> V_2 , V_374 , V_437 -> V_2 -> V_28 ,
L_43 ,
V_437 -> V_440 ) ;
V_512 = V_437 -> V_513 & V_437 -> V_350 ;
F_189 ( V_437 , V_512 , V_437 -> V_440 ,
0 , V_514 ) ;
V_437 -> V_513 += V_437 -> V_440 ;
V_437 -> V_440 = 0 ;
V_437 -> V_441 = 0 ;
++ F_169 ( V_437 ) -> V_515 ;
}
static int F_190 ( struct V_123 * V_124 ,
const V_351 * V_465 )
{
unsigned int V_245 , V_516 , V_507 , V_517 ;
unsigned int V_518 , V_519 , V_67 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_436 * V_437 ;
bool V_520 ;
T_12 V_204 = 0 ;
if ( F_151 ( F_130 ( V_2 -> V_521 ) ) )
return 0 ;
V_245 = F_191 ( * V_465 , V_522 ) ;
V_516 = F_191 ( * V_465 , V_523 ) ;
V_507 = F_191 ( * V_465 , V_524 ) ;
V_517 = F_191 ( * V_465 , V_525 ) ;
V_520 = F_191 ( * V_465 , V_526 ) ;
if ( F_191 ( * V_465 , V_527 ) )
F_145 ( V_2 -> V_28 , L_44
V_528 L_26 ,
F_192 ( * V_465 ) ) ;
V_437 = F_193 ( V_124 ) ;
if ( F_151 ( V_507 != F_170 ( V_437 ) ) )
F_185 ( V_437 , V_507 ) ;
V_518 = ( ( V_516 - V_437 -> V_513 ) &
( ( 1 << V_529 ) - 1 ) ) ;
if ( V_518 != V_437 -> V_440 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_151 ( V_518 == V_437 -> V_440 ) ) {
if ( V_437 -> V_440 == 0 || V_245 != 0 )
F_145 ( V_2 -> V_28 ,
L_45
V_528 L_26 ,
V_437 -> V_440 ,
F_192 ( * V_465 ) ) ;
F_188 ( V_437 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_29 &
( 1 << V_485 ) ) ||
V_437 -> V_440 != 0 || V_520 ) {
F_187 (
V_437 , V_516 ,
( V_437 -> V_513 +
V_437 -> V_440 + 1 ) &
( ( 1 << V_529 ) - 1 ) ) ;
return 0 ;
}
V_437 -> V_440 = 1 ;
V_437 -> V_441 = 0 ;
V_519 = V_518 ;
++ V_124 -> V_530 ;
V_124 -> V_531 += V_519 ;
V_204 |= V_532 ;
} else {
++ V_437 -> V_440 ;
V_437 -> V_441 += V_245 ;
if ( V_520 )
return 0 ;
V_519 = 1 ;
}
if ( F_151 ( F_191 ( * V_465 , V_533 ) ) )
V_204 |= V_514 ;
if ( F_151 ( F_191 ( * V_465 , V_534 ) ) ) {
V_124 -> V_535 += V_519 ;
} else if ( F_151 ( F_191 ( * V_465 ,
V_536 ) ) ) {
V_124 -> V_537 += V_519 ;
} else if ( V_517 == V_538 ||
V_517 == V_539 ) {
V_204 |= V_540 ;
}
if ( V_517 == V_538 )
V_204 |= V_541 ;
V_124 -> V_542 += 2 * V_519 ;
for ( V_67 = 0 ; V_67 < V_519 ; V_67 ++ ) {
F_189 ( V_437 ,
V_437 -> V_513 & V_437 -> V_350 ,
V_437 -> V_440 , V_437 -> V_441 ,
V_204 ) ;
V_437 -> V_513 += V_437 -> V_440 ;
}
V_437 -> V_440 = 0 ;
V_437 -> V_441 = 0 ;
return V_519 ;
}
static int
F_194 ( struct V_123 * V_124 , V_351 * V_465 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_125 * V_126 ;
unsigned int V_543 ;
unsigned int V_544 ;
int V_545 = 0 ;
if ( F_151 ( F_130 ( V_2 -> V_521 ) ) )
return 0 ;
if ( F_151 ( F_191 ( * V_465 , V_546 ) ) )
return 0 ;
V_543 = F_191 ( * V_465 , V_547 ) ;
V_544 = F_191 ( * V_465 , V_548 ) ;
V_126 = F_195 ( V_124 ,
V_544 % V_184 ) ;
V_545 = ( ( V_543 + 1 - V_126 -> V_549 ) &
V_126 -> V_350 ) ;
F_196 ( V_126 , V_543 & V_126 -> V_350 ) ;
return V_545 ;
}
static void
F_197 ( struct V_123 * V_124 , V_351 * V_465 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
int V_550 ;
V_550 = F_191 ( * V_465 , V_551 ) ;
switch ( V_550 ) {
case V_552 :
case V_553 :
break;
case V_554 :
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_46
L_47 V_528 L_48 ,
V_124 -> V_124 , V_550 ,
F_192 ( * V_465 ) ) ;
}
}
static void F_198 ( struct V_123 * V_124 ,
V_351 * V_465 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_6 V_550 ;
V_550 = F_191 ( * V_465 , V_555 ) ;
switch ( V_550 ) {
case V_556 :
V_124 -> V_557 = F_128 () ;
break;
case V_469 :
F_199 ( & V_124 -> V_437 , true ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_49
L_47 V_528 L_48 ,
V_124 -> V_124 , ( unsigned ) V_550 ,
F_192 ( * V_465 ) ) ;
}
}
static int F_200 ( struct V_123 * V_124 , int V_558 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_465 , * V_559 ;
unsigned int V_560 ;
int V_561 ;
int V_545 = 0 ;
int V_562 = 0 ;
if ( V_558 <= 0 )
return V_562 ;
V_560 = V_124 -> V_563 ;
for (; ; ) {
V_559 = F_201 ( V_124 , V_560 ) ;
V_465 = * V_559 ;
if ( ! F_202 ( & V_465 ) )
break;
F_203 ( * V_559 ) ;
++ V_560 ;
V_561 = F_191 ( V_465 , V_466 ) ;
F_127 ( V_2 , V_27 , V_2 -> V_28 ,
L_50 V_528 L_26 ,
V_124 -> V_124 , F_192 ( V_465 ) ) ;
switch ( V_561 ) {
case V_564 :
F_204 ( V_124 , & V_465 ) ;
break;
case V_565 :
V_562 += F_190 ( V_124 , & V_465 ) ;
if ( V_562 >= V_558 ) {
V_562 = V_558 ;
goto V_304;
}
break;
case V_566 :
V_545 += F_194 ( V_124 , & V_465 ) ;
if ( V_545 > V_2 -> V_567 ) {
V_562 = V_558 ;
goto V_304;
} else if ( ++ V_562 == V_558 ) {
goto V_304;
}
break;
case V_568 :
F_197 ( V_124 , & V_465 ) ;
if ( ++ V_562 == V_558 )
goto V_304;
break;
case V_467 :
F_198 ( V_124 , & V_465 ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_51
L_47 V_528 L_48 ,
V_124 -> V_124 , V_561 ,
F_192 ( V_465 ) ) ;
}
}
V_304:
V_124 -> V_563 = V_560 ;
return V_562 ;
}
static void F_205 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_1 V_569 ;
if ( F_112 ( V_2 ) ) {
F_13 ( V_570 <
( 1 << V_571 ) ) ;
F_13 ( V_481 >
( 1 << 2 * V_571 ) ) ;
F_115 ( V_569 , V_572 ,
V_573 ,
V_574 ,
( V_124 -> V_563 &
V_124 -> V_477 ) >>
V_571 ) ;
F_114 ( V_2 , & V_569 , V_313 ,
V_124 -> V_124 ) ;
F_115 ( V_569 , V_572 ,
V_575 ,
V_574 ,
V_124 -> V_563 &
( ( 1 << V_571 ) - 1 ) ) ;
F_114 ( V_2 , & V_569 , V_313 ,
V_124 -> V_124 ) ;
} else {
F_149 ( V_569 , V_576 ,
V_124 -> V_563 &
V_124 -> V_477 ) ;
F_114 ( V_2 , & V_569 , V_577 , V_124 -> V_124 ) ;
}
}
static void F_206 ( struct V_123 * V_124 )
{
F_8 ( V_47 , V_464 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_465 ;
int V_18 ;
F_175 ( V_465 ,
V_466 , V_467 ,
V_468 , V_556 ) ;
F_21 ( V_47 , V_470 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_47 , V_471 ) , & V_465 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
V_18 = F_9 ( V_2 , V_472 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_135;
return;
V_135:
F_22 ( true ) ;
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_29 , V_433 , V_18 ) ;
}
void F_207 ( struct V_1 * V_2 )
{
if ( F_208 ( & V_2 -> V_303 ) )
F_209 ( & V_2 -> V_578 ) ;
F_22 ( F_108 ( & V_2 -> V_303 ) < 0 ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
struct V_436 * V_437 ;
int V_579 ;
if ( V_16 -> V_194 ) {
F_211 ( & V_2 -> V_303 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_580 != V_581 ) {
F_58 (channel, efx) {
F_212 (rx_queue, channel)
F_171 ( V_437 ) ;
F_59 (tx_queue, channel)
F_146 ( V_126 ) ;
}
F_213 ( V_2 -> V_578 ,
F_108 ( & V_2 -> V_303 ) == 0 ,
F_214 ( V_582 ) ) ;
V_579 = F_108 ( & V_2 -> V_303 ) ;
if ( V_579 ) {
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_52 ,
V_579 ) ;
return - V_583 ;
}
}
return 0 ;
}
static void F_215 ( struct V_1 * V_2 )
{
F_211 ( & V_2 -> V_303 , 0 ) ;
}
static bool F_216 ( const struct V_584 * V_585 ,
const struct V_584 * V_586 )
{
if ( ( V_585 -> V_587 ^ V_586 -> V_587 ) |
( ( V_585 -> V_204 ^ V_586 -> V_204 ) &
( V_588 | V_589 ) ) )
return false ;
return memcmp ( & V_585 -> V_590 , & V_586 -> V_590 ,
sizeof( struct V_584 ) -
F_217 ( struct V_584 , V_590 ) ) == 0 ;
}
static unsigned int F_218 ( const struct V_584 * V_591 )
{
F_13 ( F_217 ( struct V_584 , V_590 ) & 3 ) ;
return F_219 ( ( const T_6 * ) & V_591 -> V_590 ,
( sizeof( struct V_584 ) -
F_217 ( struct V_584 , V_590 ) ) / 4 ,
0 ) ;
}
static bool F_220 ( const struct V_584 * V_591 )
{
if ( V_591 -> V_587 & V_592 &&
! F_221 ( V_591 -> V_593 ) )
return true ;
if ( ( V_591 -> V_587 &
( V_594 | V_595 ) ) ==
( V_594 | V_595 ) ) {
if ( V_591 -> V_596 == F_222 ( V_597 ) &&
! F_223 ( V_591 -> V_598 [ 0 ] ) )
return true ;
if ( V_591 -> V_596 == F_222 ( V_599 ) &&
( ( const T_3 * ) V_591 -> V_598 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_584 *
F_224 ( const struct V_600 * V_601 ,
unsigned int V_602 )
{
return (struct V_584 * ) ( V_601 -> V_603 [ V_602 ] . V_591 &
~ V_604 ) ;
}
static unsigned int
F_225 ( const struct V_600 * V_601 ,
unsigned int V_602 )
{
return V_601 -> V_603 [ V_602 ] . V_591 & V_604 ;
}
static void
F_226 ( struct V_600 * V_601 ,
unsigned int V_602 ,
const struct V_584 * V_591 ,
unsigned int V_204 )
{
V_601 -> V_603 [ V_602 ] . V_591 = ( unsigned long ) V_591 | V_204 ;
}
static void F_227 ( struct V_1 * V_2 ,
const struct V_584 * V_591 ,
T_1 * V_47 , T_7 V_605 ,
bool V_606 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
memset ( V_47 , 0 , V_607 ) ;
if ( V_606 ) {
F_21 ( V_47 , V_608 ,
V_609 ) ;
F_106 ( V_47 , V_610 , V_605 ) ;
} else {
T_6 V_611 = 0 ;
F_21 ( V_47 , V_608 ,
F_220 ( V_591 ) ?
V_612 :
V_613 ) ;
if ( V_591 -> V_587 & V_614 )
V_611 |=
F_221 ( V_591 -> V_593 ) ?
1 << V_615 :
1 << V_616 ;
#define F_228 ( T_13 , T_14 , T_15 ) \
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
F_228 ( V_617 , V_618 , V_619 ) ;
F_228 ( V_620 , V_598 , V_621 ) ;
F_228 ( V_622 , V_623 , V_624 ) ;
F_228 ( V_625 , V_626 , V_627 ) ;
F_228 ( V_628 , V_593 , V_629 ) ;
F_228 ( V_630 , V_631 , V_632 ) ;
F_228 ( V_633 , V_596 , V_633 ) ;
F_228 ( V_634 , V_635 , V_636 ) ;
F_228 ( V_637 , V_590 , V_638 ) ;
F_228 ( V_639 , V_640 , V_639 ) ;
#undef F_228
F_21 ( V_47 , V_641 ,
V_611 ) ;
}
F_21 ( V_47 , V_642 , V_16 -> V_79 ) ;
F_21 ( V_47 , V_643 ,
V_591 -> V_644 == V_645 ?
V_646 :
V_647 ) ;
F_21 ( V_47 , V_648 , 0 ) ;
F_21 ( V_47 , V_649 ,
V_650 ) ;
F_21 ( V_47 , V_651 ,
V_591 -> V_644 == V_645 ?
0 : V_591 -> V_644 ) ;
F_21 ( V_47 , V_652 ,
( V_591 -> V_204 & V_653 ) ?
V_654 :
V_655 ) ;
if ( V_591 -> V_204 & V_653 )
F_21 ( V_47 , V_656 ,
V_591 -> V_657 !=
V_658 ?
V_591 -> V_657 : V_16 -> V_77 ) ;
}
static int F_229 ( struct V_1 * V_2 ,
const struct V_584 * V_591 ,
T_7 * V_605 , bool V_606 )
{
F_8 ( V_47 , V_607 ) ;
F_8 ( V_13 , V_659 ) ;
int V_18 ;
F_227 ( V_2 , V_591 , V_47 , * V_605 , V_606 ) ;
V_18 = F_9 ( V_2 , V_660 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_605 = F_230 ( V_13 , V_661 ) ;
if ( V_18 == - V_119 )
V_18 = - V_169 ;
return V_18 ;
}
static int F_231 ( struct V_600 * V_601 ,
enum V_662 V_587 )
{
unsigned int V_663 ;
for ( V_663 = 0 ;
V_663 < V_601 -> V_664 ;
V_663 ++ )
if ( V_601 -> V_665 [ V_663 ] == V_587 )
return V_663 ;
return - V_666 ;
}
static T_16 F_232 ( struct V_1 * V_2 ,
struct V_584 * V_591 ,
bool V_667 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
F_90 ( V_669 , V_670 ) ;
struct V_584 * V_671 ;
unsigned int V_663 , V_672 ;
unsigned int V_673 ;
bool V_606 = false ;
int V_674 = - 1 ;
F_233 ( V_675 ) ;
bool V_676 ;
T_16 V_18 ;
if ( ( V_591 -> V_204 & ( V_588 | V_589 ) ) !=
V_588 )
return - V_215 ;
V_18 = F_231 ( V_601 , V_591 -> V_587 ) ;
if ( V_18 < 0 )
return V_18 ;
V_663 = V_18 ;
V_672 = F_218 ( V_591 ) ;
V_676 = F_234 ( V_591 ) ;
if ( V_676 )
F_235 ( V_669 , V_670 ) ;
for (; ; ) {
unsigned int V_677 = 1 ;
unsigned int V_67 ;
F_105 ( & V_2 -> V_678 ) ;
for (; ; ) {
V_67 = ( V_672 + V_677 ) & ( V_679 - 1 ) ;
V_671 = F_224 ( V_601 , V_67 ) ;
if ( ! V_671 ) {
if ( V_674 < 0 )
V_674 = V_67 ;
} else if ( F_216 ( V_591 , V_671 ) ) {
if ( V_601 -> V_603 [ V_67 ] . V_591 &
V_680 )
break;
if ( V_591 -> V_681 < V_671 -> V_681 &&
V_591 -> V_681 != V_682 ) {
V_18 = - V_97 ;
goto V_683;
}
if ( ! V_676 ) {
if ( V_591 -> V_681 ==
V_671 -> V_681 &&
! V_667 ) {
V_18 = - V_684 ;
goto V_683;
}
V_674 = V_67 ;
goto V_685;
} else if ( V_591 -> V_681 >
V_671 -> V_681 ||
( V_591 -> V_681 ==
V_671 -> V_681 &&
V_667 ) ) {
if ( V_674 < 0 )
V_674 = V_67 ;
else
F_236 ( V_677 , V_669 ) ;
}
}
if ( V_677 == V_670 ) {
if ( V_674 < 0 ) {
V_18 = - V_169 ;
goto V_683;
}
goto V_685;
}
++ V_677 ;
}
F_237 ( & V_601 -> V_686 , & V_675 , V_687 ) ;
F_103 ( & V_2 -> V_678 ) ;
F_238 () ;
}
V_685:
V_671 = F_224 ( V_601 , V_674 ) ;
if ( V_671 ) {
if ( V_591 -> V_681 == V_682 &&
V_671 -> V_681 >= V_682 ) {
if ( V_671 -> V_681 > V_682 )
V_671 -> V_204 |= V_688 ;
V_601 -> V_603 [ V_674 ] . V_591 &=
~ V_689 ;
V_18 = V_674 ;
goto V_683;
}
V_606 = true ;
V_673 = F_225 ( V_601 , V_674 ) ;
} else {
V_671 = F_239 ( sizeof( * V_591 ) , V_295 ) ;
if ( ! V_671 ) {
V_18 = - V_71 ;
goto V_683;
}
* V_671 = * V_591 ;
V_673 = 0 ;
}
F_226 ( V_601 , V_674 , V_671 ,
V_673 | V_680 ) ;
if ( V_676 ) {
unsigned int V_677 , V_67 ;
for ( V_677 = 0 ; V_677 < V_670 ; V_677 ++ ) {
V_67 = ( V_672 + V_677 ) & ( V_679 - 1 ) ;
if ( F_240 ( V_677 , V_669 ) )
V_601 -> V_603 [ V_67 ] . V_591 |=
V_680 ;
}
}
F_103 ( & V_2 -> V_678 ) ;
V_18 = F_229 ( V_2 , V_591 , & V_601 -> V_603 [ V_674 ] . V_605 ,
V_606 ) ;
F_105 ( & V_2 -> V_678 ) ;
if ( V_18 == 0 ) {
if ( V_606 ) {
if ( V_671 -> V_681 == V_682 )
V_671 -> V_204 |=
V_688 ;
V_671 -> V_681 = V_591 -> V_681 ;
V_671 -> V_204 &= V_688 ;
V_671 -> V_204 |= V_591 -> V_204 ;
V_671 -> V_657 = V_591 -> V_657 ;
V_671 -> V_644 = V_591 -> V_644 ;
}
} else if ( ! V_606 ) {
F_48 ( V_671 ) ;
V_671 = NULL ;
}
F_226 ( V_601 , V_674 , V_671 , V_673 ) ;
if ( V_676 ) {
F_8 ( V_47 , V_607 ) ;
unsigned int V_677 , V_67 ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
for ( V_677 = 0 ; V_677 < V_670 ; V_677 ++ ) {
if ( ! F_240 ( V_677 , V_669 ) )
continue;
V_67 = ( V_672 + V_677 ) & ( V_679 - 1 ) ;
V_671 = F_224 ( V_601 , V_67 ) ;
V_673 = F_225 ( V_601 , V_67 ) ;
if ( V_18 == 0 ) {
F_103 ( & V_2 -> V_678 ) ;
F_21 ( V_47 , V_608 ,
V_690 ) ;
F_106 ( V_47 , V_610 ,
V_601 -> V_603 [ V_67 ] . V_605 ) ;
V_18 = F_9 ( V_2 , V_660 ,
V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_678 ) ;
}
if ( V_18 == 0 ) {
F_48 ( V_671 ) ;
V_671 = NULL ;
V_673 = 0 ;
} else {
V_673 &= ~ V_680 ;
}
F_226 ( V_601 , V_67 , V_671 ,
V_673 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_663 * V_679 + V_674 ;
F_241 ( & V_601 -> V_686 ) ;
V_683:
F_103 ( & V_2 -> V_678 ) ;
F_242 ( & V_601 -> V_686 , & V_675 ) ;
return V_18 ;
}
static void F_243 ( struct V_1 * V_2 )
{
}
static int F_244 ( struct V_1 * V_2 ,
unsigned int V_691 ,
T_6 V_692 , bool V_693 )
{
unsigned int V_602 = V_692 % V_679 ;
struct V_600 * V_601 = V_2 -> V_668 ;
F_8 ( V_47 ,
V_694 +
V_695 ) ;
struct V_584 * V_591 ;
F_233 ( V_675 ) ;
int V_18 ;
for (; ; ) {
F_105 ( & V_2 -> V_678 ) ;
if ( ! ( V_601 -> V_603 [ V_602 ] . V_591 &
V_680 ) )
break;
F_237 ( & V_601 -> V_686 , & V_675 , V_687 ) ;
F_103 ( & V_2 -> V_678 ) ;
F_238 () ;
}
V_591 = F_224 ( V_601 , V_602 ) ;
if ( ! V_591 ||
( ! V_693 &&
F_231 ( V_601 , V_591 -> V_587 ) !=
V_692 / V_679 ) ) {
V_18 = - V_101 ;
goto V_683;
}
if ( V_591 -> V_204 & V_688 &&
V_691 == ( 1U << V_682 ) ) {
V_591 -> V_204 &= ~ V_688 ;
V_601 -> V_603 [ V_602 ] . V_591 &= ~ V_689 ;
V_18 = 0 ;
goto V_683;
}
if ( ! ( V_691 & ( 1U << V_591 -> V_681 ) ) ) {
V_18 = - V_101 ;
goto V_683;
}
V_601 -> V_603 [ V_602 ] . V_591 |= V_680 ;
F_103 ( & V_2 -> V_678 ) ;
if ( V_591 -> V_204 & V_688 ) {
struct V_584 V_696 = * V_591 ;
V_696 . V_681 = V_682 ;
V_696 . V_204 = ( V_588 |
( F_245 ( V_2 ) ?
V_653 : 0 ) ) ;
V_696 . V_644 = 0 ;
V_696 . V_657 = V_658 ;
V_18 = F_229 ( V_2 , & V_696 ,
& V_601 -> V_603 [ V_602 ] . V_605 ,
true ) ;
F_105 ( & V_2 -> V_678 ) ;
if ( V_18 == 0 )
* V_591 = V_696 ;
} else {
F_21 ( V_47 , V_608 ,
F_220 ( V_591 ) ?
V_697 :
V_690 ) ;
F_106 ( V_47 , V_610 ,
V_601 -> V_603 [ V_602 ] . V_605 ) ;
V_18 = F_9 ( V_2 , V_660 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_678 ) ;
if ( V_18 == 0 ) {
F_48 ( V_591 ) ;
F_226 ( V_601 , V_602 , NULL , 0 ) ;
}
}
V_601 -> V_603 [ V_602 ] . V_591 &= ~ V_680 ;
F_241 ( & V_601 -> V_686 ) ;
V_683:
F_103 ( & V_2 -> V_678 ) ;
F_242 ( & V_601 -> V_686 , & V_675 ) ;
return V_18 ;
}
static int F_246 ( struct V_1 * V_2 ,
enum V_698 V_681 ,
T_6 V_692 )
{
return F_244 ( V_2 , 1U << V_681 ,
V_692 , false ) ;
}
static T_6 F_247 ( struct V_1 * V_2 , T_6 V_692 )
{
return V_692 % V_679 ;
}
static int F_248 ( struct V_1 * V_2 ,
enum V_698 V_681 ,
T_6 V_692 )
{
return F_244 ( V_2 , 1U << V_681 ,
V_692 , true ) ;
}
static int F_249 ( struct V_1 * V_2 ,
enum V_698 V_681 ,
T_6 V_692 , struct V_584 * V_591 )
{
unsigned int V_602 = V_692 % V_679 ;
struct V_600 * V_601 = V_2 -> V_668 ;
const struct V_584 * V_671 ;
int V_18 ;
F_105 ( & V_2 -> V_678 ) ;
V_671 = F_224 ( V_601 , V_602 ) ;
if ( V_671 && V_671 -> V_681 == V_681 &&
F_231 ( V_601 , V_671 -> V_587 ) ==
V_692 / V_679 ) {
* V_591 = * V_671 ;
V_18 = 0 ;
} else {
V_18 = - V_101 ;
}
F_103 ( & V_2 -> V_678 ) ;
return V_18 ;
}
static int F_250 ( struct V_1 * V_2 ,
enum V_698 V_681 )
{
unsigned int V_691 ;
unsigned int V_67 ;
int V_18 ;
V_691 = ( ( ( 1U << ( V_681 + 1 ) ) - 1 ) &
~ ( 1U << V_682 ) ) ;
for ( V_67 = 0 ; V_67 < V_679 ; V_67 ++ ) {
V_18 = F_244 ( V_2 , V_691 ,
V_67 , true ) ;
if ( V_18 && V_18 != - V_101 )
return V_18 ;
}
return 0 ;
}
static T_6 F_251 ( struct V_1 * V_2 ,
enum V_698 V_681 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
unsigned int V_602 ;
T_16 V_699 = 0 ;
F_105 ( & V_2 -> V_678 ) ;
for ( V_602 = 0 ; V_602 < V_679 ; V_602 ++ ) {
if ( V_601 -> V_603 [ V_602 ] . V_591 &&
F_224 ( V_601 , V_602 ) -> V_681 ==
V_681 )
++ V_699 ;
}
F_103 ( & V_2 -> V_678 ) ;
return V_699 ;
}
static T_6 F_252 ( struct V_1 * V_2 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
return V_601 -> V_664 * V_679 ;
}
static T_16 F_253 ( struct V_1 * V_2 ,
enum V_698 V_681 ,
T_6 * V_61 , T_6 V_700 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_584 * V_591 ;
unsigned int V_602 ;
T_16 V_699 = 0 ;
F_105 ( & V_2 -> V_678 ) ;
for ( V_602 = 0 ; V_602 < V_679 ; V_602 ++ ) {
V_591 = F_224 ( V_601 , V_602 ) ;
if ( V_591 && V_591 -> V_681 == V_681 ) {
if ( V_699 == V_700 ) {
V_699 = - V_701 ;
break;
}
V_61 [ V_699 ++ ] = ( F_231 (
V_601 , V_591 -> V_587 ) *
V_679 +
V_602 ) ;
}
}
F_103 ( & V_2 -> V_678 ) ;
return V_699 ;
}
static T_16 F_254 ( struct V_1 * V_2 ,
struct V_584 * V_591 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
F_8 ( V_47 , V_607 ) ;
struct V_584 * V_671 ;
unsigned int V_672 , V_67 , V_677 = 1 ;
bool V_606 = false ;
int V_674 = - 1 ;
T_7 V_474 ;
T_16 V_18 ;
F_255 ( V_591 -> V_204 !=
( V_588 | V_702 ) ) ;
F_255 ( V_591 -> V_681 != V_703 ) ;
F_255 ( F_234 ( V_591 ) ) ;
V_672 = F_218 ( V_591 ) ;
F_105 ( & V_2 -> V_678 ) ;
for (; ; ) {
V_67 = ( V_672 + V_677 ) & ( V_679 - 1 ) ;
V_671 = F_224 ( V_601 , V_67 ) ;
if ( ! V_671 ) {
if ( V_674 < 0 )
V_674 = V_67 ;
} else if ( F_216 ( V_591 , V_671 ) ) {
if ( V_601 -> V_603 [ V_67 ] . V_591 & V_680 ) {
V_18 = - V_169 ;
goto V_704;
}
if ( V_591 -> V_681 < V_671 -> V_681 ) {
V_18 = - V_97 ;
goto V_704;
}
V_674 = V_67 ;
break;
}
if ( V_677 == V_670 ) {
if ( V_674 < 0 ) {
V_18 = - V_169 ;
goto V_704;
}
break;
}
++ V_677 ;
}
V_671 = F_224 ( V_601 , V_674 ) ;
if ( V_671 ) {
V_606 = true ;
} else {
V_671 = F_239 ( sizeof( * V_591 ) , V_295 ) ;
if ( ! V_671 ) {
V_18 = - V_71 ;
goto V_704;
}
* V_671 = * V_591 ;
}
F_226 ( V_601 , V_674 , V_671 ,
V_680 ) ;
F_103 ( & V_2 -> V_678 ) ;
V_474 = V_606 << 31 | V_674 << 16 | V_591 -> V_644 ;
F_227 ( V_2 , V_591 , V_47 ,
V_601 -> V_603 [ V_674 ] . V_605 , V_606 ) ;
F_178 ( V_2 , V_660 , V_47 , sizeof( V_47 ) ,
V_659 ,
V_705 , V_474 ) ;
return V_674 ;
V_704:
F_103 ( & V_2 -> V_678 ) ;
return V_18 ;
}
static void
V_705 ( struct V_1 * V_2 , unsigned long V_474 ,
int V_18 , T_1 * V_13 ,
T_2 V_475 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
unsigned int V_674 , V_644 ;
struct V_584 * V_591 ;
bool V_606 ;
V_606 = V_474 >> 31 ;
V_674 = ( V_474 >> 16 ) & ( V_679 - 1 ) ;
V_644 = V_474 & 0xffff ;
F_105 ( & V_2 -> V_678 ) ;
V_591 = F_224 ( V_601 , V_674 ) ;
if ( V_18 == 0 ) {
V_601 -> V_603 [ V_674 ] . V_605 =
F_230 ( V_13 , V_661 ) ;
if ( V_606 )
V_591 -> V_644 = V_644 ;
} else if ( ! V_606 ) {
F_48 ( V_591 ) ;
V_591 = NULL ;
}
F_226 ( V_601 , V_674 , V_591 , 0 ) ;
F_103 ( & V_2 -> V_678 ) ;
F_241 ( & V_601 -> V_686 ) ;
}
static bool F_256 ( struct V_1 * V_2 , T_6 V_706 ,
unsigned int V_602 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_584 * V_591 =
F_224 ( V_601 , V_602 ) ;
F_8 ( V_47 ,
V_694 +
V_695 ) ;
if ( ! V_591 ||
( V_601 -> V_603 [ V_602 ] . V_591 & V_680 ) ||
V_591 -> V_681 != V_703 ||
! F_257 ( V_2 -> V_28 , V_591 -> V_644 ,
V_706 , V_602 ) )
return false ;
F_21 ( V_47 , V_608 ,
V_697 ) ;
F_106 ( V_47 , V_610 ,
V_601 -> V_603 [ V_602 ] . V_605 ) ;
if ( F_178 ( V_2 , V_660 , V_47 , sizeof( V_47 ) , 0 ,
V_707 , V_602 ) )
return false ;
V_601 -> V_603 [ V_602 ] . V_591 |= V_680 ;
return true ;
}
static void
V_707 ( struct V_1 * V_2 ,
unsigned long V_602 ,
int V_18 , T_1 * V_13 ,
T_2 V_475 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_584 * V_591 =
F_224 ( V_601 , V_602 ) ;
F_105 ( & V_2 -> V_678 ) ;
if ( V_18 == 0 ) {
F_48 ( V_591 ) ;
F_226 ( V_601 , V_602 , NULL , 0 ) ;
}
V_601 -> V_603 [ V_602 ] . V_591 &= ~ V_680 ;
F_241 ( & V_601 -> V_686 ) ;
F_103 ( & V_2 -> V_678 ) ;
}
static int F_258 ( T_6 V_708 )
{
int V_587 = 0 ;
#define F_259 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_259 ( V_709 , V_710 ) ;
F_259 ( V_709 , V_711 ) ;
F_259 ( V_617 , V_619 ) ;
F_259 ( V_620 , V_621 ) ;
F_259 ( V_622 , V_624 ) ;
F_259 ( V_625 , V_627 ) ;
F_259 ( V_628 , V_629 ) ;
F_259 ( V_630 , V_632 ) ;
F_259 ( V_633 , V_633 ) ;
F_259 ( V_634 , V_636 ) ;
F_259 ( V_637 , V_638 ) ;
F_259 ( V_639 , V_639 ) ;
#undef F_259
if ( V_708 )
return - V_215 ;
return V_587 ;
}
static int F_260 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_712 ) ;
F_8 ( V_13 , V_713 ) ;
unsigned int V_714 , V_715 ;
struct V_600 * V_601 ;
T_2 V_17 ;
int V_18 ;
V_601 = F_29 ( sizeof( * V_601 ) , V_70 ) ;
if ( ! V_601 )
return - V_71 ;
F_21 ( V_47 , V_716 ,
V_717 ) ;
V_18 = F_9 ( V_2 , V_718 ,
V_47 , sizeof( V_47 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_135;
V_715 = F_261 (
V_17 , V_719 ) ;
V_601 -> V_664 = 0 ;
for ( V_714 = 0 ; V_714 < V_715 ; V_714 ++ ) {
T_6 V_708 =
F_262 (
V_13 ,
V_719 ,
V_714 ) ;
V_18 = F_258 ( V_708 ) ;
if ( V_18 < 0 ) {
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_53 ,
V_433 , V_708 , V_714 ) ;
} else {
F_41 ( V_2 , V_36 , V_2 -> V_28 ,
L_54 ,
V_433 , V_708 , V_714 ,
V_18 , V_601 -> V_664 ) ;
V_601 -> V_665 [ V_601 -> V_664 ++ ] = V_18 ;
}
}
V_601 -> V_603 = F_263 ( V_679 * sizeof( * V_601 -> V_603 ) ) ;
if ( ! V_601 -> V_603 ) {
V_18 = - V_71 ;
goto V_135;
}
V_601 -> V_720 = V_721 ;
V_601 -> V_722 = V_721 ;
V_601 -> V_723 = V_721 ;
V_2 -> V_668 = V_601 ;
F_264 ( & V_601 -> V_686 ) ;
return 0 ;
V_135:
F_48 ( V_601 ) ;
return V_18 ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_584 * V_591 ;
unsigned int V_602 ;
bool V_724 = false ;
int V_18 ;
F_22 ( ! F_266 ( & V_2 -> V_725 ) ) ;
if ( ! V_16 -> V_197 )
return;
if ( ! V_601 )
return;
F_105 ( & V_2 -> V_678 ) ;
for ( V_602 = 0 ; V_602 < V_679 ; V_602 ++ ) {
V_591 = F_224 ( V_601 , V_602 ) ;
if ( ! V_591 )
continue;
V_601 -> V_603 [ V_602 ] . V_591 |= V_680 ;
F_103 ( & V_2 -> V_678 ) ;
V_18 = F_229 ( V_2 , V_591 ,
& V_601 -> V_603 [ V_602 ] . V_605 ,
false ) ;
if ( V_18 )
V_724 = true ;
F_105 ( & V_2 -> V_678 ) ;
if ( V_18 ) {
F_48 ( V_591 ) ;
F_226 ( V_601 , V_602 , NULL , 0 ) ;
} else {
V_601 -> V_603 [ V_602 ] . V_591 &=
~ V_680 ;
}
}
F_103 ( & V_2 -> V_678 ) ;
if ( V_724 )
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_55 ) ;
else
V_16 -> V_197 = false ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
F_8 ( V_47 , V_607 ) ;
struct V_584 * V_591 ;
unsigned int V_602 ;
int V_18 ;
V_2 -> V_668 = NULL ;
if ( ! V_601 )
return;
for ( V_602 = 0 ; V_602 < V_679 ; V_602 ++ ) {
V_591 = F_224 ( V_601 , V_602 ) ;
if ( ! V_591 )
continue;
F_21 ( V_47 , V_608 ,
F_220 ( V_591 ) ?
V_697 :
V_690 ) ;
F_106 ( V_47 , V_610 ,
V_601 -> V_603 [ V_602 ] . V_605 ) ;
V_18 = F_51 ( V_2 , V_660 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
if ( V_18 )
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_56 ,
V_433 , V_602 ) ;
F_48 ( V_591 ) ;
}
F_268 ( V_601 -> V_603 ) ;
F_48 ( V_601 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
unsigned int V_602 , V_67 ;
if ( ! V_601 )
return;
F_105 ( & V_2 -> V_678 ) ;
for ( V_67 = 0 ; V_67 < V_601 -> V_726 ; V_67 ++ )
F_270 ( V_601 -> V_727 [ V_67 ] . V_728 ) ;
for ( V_67 = 0 ; V_67 < V_601 -> V_729 ; V_67 ++ )
F_270 ( V_601 -> V_730 [ V_67 ] . V_728 ) ;
F_270 ( V_601 -> V_720 ) ;
F_270 ( V_601 -> V_722 ) ;
F_270 ( V_601 -> V_723 ) ;
F_103 ( & V_2 -> V_678 ) ;
}
static void F_271 ( struct V_1 * V_2 , bool * V_731 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_66 * V_28 = V_2 -> V_28 ;
struct V_732 * V_733 ;
int V_734 ;
unsigned int V_67 ;
V_601 -> V_720 = V_721 ;
V_734 = F_272 ( V_28 ) ;
if ( V_28 -> V_204 & V_735 )
* V_731 = true ;
V_601 -> V_726 = 1 + V_734 ;
F_18 ( V_601 -> V_727 [ 0 ] . V_281 , V_28 -> V_736 ) ;
V_67 = 1 ;
F_273 (uc, net_dev) {
if ( V_67 >= V_737 ) {
* V_731 = true ;
break;
}
F_18 ( V_601 -> V_727 [ V_67 ] . V_281 , V_733 -> V_281 ) ;
V_601 -> V_727 [ V_67 ] . V_728 = V_721 ;
V_67 ++ ;
}
}
static void F_274 ( struct V_1 * V_2 , bool * V_731 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_66 * V_28 = V_2 -> V_28 ;
struct V_732 * V_738 ;
unsigned int V_67 , V_734 ;
V_601 -> V_723 = V_721 ;
V_601 -> V_722 = V_721 ;
if ( V_28 -> V_204 & ( V_735 | V_739 ) )
* V_731 = true ;
V_734 = F_275 ( V_28 ) ;
V_67 = 0 ;
F_276 (mc, net_dev) {
if ( V_67 >= V_740 ) {
* V_731 = true ;
break;
}
F_18 ( V_601 -> V_730 [ V_67 ] . V_281 , V_738 -> V_281 ) ;
V_601 -> V_730 [ V_67 ] . V_728 = V_721 ;
V_67 ++ ;
}
V_601 -> V_729 = V_67 ;
}
static int F_277 ( struct V_1 * V_2 ,
bool V_256 , bool V_741 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_742 * V_743 ;
enum V_744 V_745 ;
struct V_584 V_591 ;
T_3 V_746 [ V_747 ] ;
unsigned int V_67 , V_748 ;
int V_734 ;
int V_18 ;
if ( V_256 ) {
V_743 = V_601 -> V_730 ;
V_734 = V_601 -> V_729 ;
} else {
V_743 = V_601 -> V_727 ;
V_734 = V_601 -> V_726 ;
}
V_745 = F_245 ( V_2 ) ? V_653 : 0 ;
for ( V_67 = 0 ; V_67 < V_734 ; V_67 ++ ) {
F_278 ( & V_591 , V_682 , V_745 , 0 ) ;
F_279 ( & V_591 , V_749 ,
V_743 [ V_67 ] . V_281 ) ;
V_18 = F_232 ( V_2 , & V_591 , true ) ;
if ( V_18 < 0 ) {
if ( V_741 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_57 ,
V_18 ) ;
for ( V_748 = 0 ; V_748 < V_67 ; V_748 ++ ) {
if ( V_743 [ V_748 ] . V_728 == V_721 )
continue;
F_248 (
V_2 , V_682 ,
V_743 [ V_748 ] . V_728 ) ;
V_743 [ V_748 ] . V_728 = V_721 ;
}
return V_18 ;
} else {
V_18 = V_721 ;
}
}
V_743 [ V_67 ] . V_728 = F_247 ( V_2 , V_18 ) ;
}
if ( V_256 && V_741 ) {
F_278 ( & V_591 , V_682 , V_745 , 0 ) ;
F_280 ( V_746 ) ;
F_279 ( & V_591 , V_749 , V_746 ) ;
V_18 = F_232 ( V_2 , & V_591 , true ) ;
if ( V_18 < 0 ) {
F_165 ( V_2 , V_27 , V_2 -> V_28 ,
L_58 , V_18 ) ;
for ( V_748 = 0 ; V_748 < V_67 ; V_748 ++ ) {
if ( V_743 [ V_748 ] . V_728 == V_721 )
continue;
F_248 (
V_2 , V_682 ,
V_743 [ V_748 ] . V_728 ) ;
V_743 [ V_748 ] . V_728 = V_721 ;
}
return V_18 ;
} else {
V_601 -> V_722 = F_247 ( V_2 , V_18 ) ;
}
}
return 0 ;
}
static int F_281 ( struct V_1 * V_2 , bool V_256 ,
bool V_741 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_15 * V_16 = V_2 -> V_16 ;
enum V_744 V_745 ;
struct V_584 V_591 ;
T_3 V_746 [ V_747 ] ;
int V_18 ;
V_745 = F_245 ( V_2 ) ? V_653 : 0 ;
F_278 ( & V_591 , V_682 , V_745 , 0 ) ;
if ( V_256 )
F_282 ( & V_591 ) ;
else
F_283 ( & V_591 ) ;
V_18 = F_232 ( V_2 , & V_591 , true ) ;
if ( V_18 < 0 ) {
F_284 ( V_2 , V_27 , V_18 == - V_97 ? V_750 : V_751 ,
V_2 -> V_28 ,
L_59 ,
V_256 ? L_60 : L_61 , V_18 ) ;
} else if ( V_256 ) {
V_601 -> V_723 = F_247 ( V_2 , V_18 ) ;
if ( ! V_16 -> V_503 ) {
F_278 ( & V_591 , V_682 ,
V_745 , 0 ) ;
F_280 ( V_746 ) ;
F_279 ( & V_591 , V_749 ,
V_746 ) ;
V_18 = F_232 ( V_2 , & V_591 , true ) ;
if ( V_18 < 0 ) {
F_165 ( V_2 , V_27 , V_2 -> V_28 ,
L_58 ,
V_18 ) ;
if ( V_741 ) {
F_248 (
V_2 , V_682 ,
V_601 -> V_723 ) ;
V_601 -> V_723 = V_721 ;
return V_18 ;
}
} else {
V_601 -> V_722 = F_247 ( V_2 , V_18 ) ;
}
}
V_18 = 0 ;
} else {
V_601 -> V_720 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_285 ( struct V_1 * V_2 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
int V_752 = 0 ;
int V_753 = 0 ;
int V_18 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_679 ; V_67 ++ ) {
if ( F_130 ( V_601 -> V_603 [ V_67 ] . V_591 ) &
V_689 ) {
V_18 = F_244 ( V_2 ,
1U << V_682 , V_67 , true ) ;
if ( V_18 == - V_101 )
V_753 ++ ;
else if ( V_18 )
V_752 ++ ;
}
}
if ( V_752 )
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_62 ,
V_433 , V_752 ) ;
if ( V_753 )
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_63 ,
V_433 , V_753 ) ;
}
static int F_286 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_754 [ V_747 ] ;
int V_18 , V_755 ;
if ( F_287 ( V_16 -> V_756 ) )
return 0 ;
F_288 ( V_2 ) ;
F_289 ( V_2 -> V_28 ) ;
F_290 ( & V_2 -> V_725 ) ;
F_267 ( V_2 ) ;
F_291 ( & V_2 -> V_725 ) ;
V_18 = F_69 ( V_2 , V_16 -> V_79 ) ;
if ( V_18 )
goto V_757;
F_18 ( V_754 , V_16 -> V_756 ) ;
V_18 = F_71 ( V_2 , V_16 -> V_79 ,
V_16 -> V_756 ) ;
if ( V_18 )
goto V_758;
V_18 = F_70 ( V_2 , V_16 -> V_79 ,
V_2 -> V_28 -> V_736 ) ;
if ( ! V_18 ) {
F_18 ( V_16 -> V_756 , V_2 -> V_28 -> V_736 ) ;
} else {
V_755 = F_70 ( V_2 , V_16 -> V_79 , V_754 ) ;
if ( V_755 ) {
F_292 ( V_16 -> V_756 ) ;
goto V_759;
}
}
V_758:
V_755 = F_68 ( V_2 , V_16 -> V_79 ) ;
if ( V_755 )
goto V_759;
V_757:
F_290 ( & V_2 -> V_725 ) ;
V_755 = F_260 ( V_2 ) ;
F_291 ( & V_2 -> V_725 ) ;
if ( V_755 )
goto V_759;
V_755 = F_293 ( V_2 -> V_28 ) ;
if ( V_755 )
goto V_759;
F_294 ( V_2 -> V_28 ) ;
return V_18 ;
V_759:
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_64 ) ;
F_186 ( V_2 , V_203 ) ;
return V_18 ? V_18 : V_755 ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_600 * V_601 = V_2 -> V_668 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_66 * V_28 = V_2 -> V_28 ;
bool V_760 = false , V_761 = false ;
if ( ! F_296 ( V_2 ) )
return;
if ( ! V_601 )
return;
F_269 ( V_2 ) ;
F_297 ( V_28 ) ;
F_271 ( V_2 , & V_760 ) ;
F_274 ( V_2 , & V_761 ) ;
F_298 ( V_28 ) ;
if ( V_760 ) {
F_281 ( V_2 , false , false ) ;
F_277 ( V_2 , false , false ) ;
} else {
if ( F_277 ( V_2 , false , false ) )
F_281 ( V_2 , false , false ) ;
}
if ( V_16 -> V_503 && V_2 -> V_761 != V_761 )
F_285 ( V_2 ) ;
if ( V_761 ) {
if ( V_16 -> V_503 ) {
if ( F_281 ( V_2 , true , true ) ) {
F_285 ( V_2 ) ;
F_277 ( V_2 , true , false ) ;
}
} else {
F_281 ( V_2 , true , false ) ;
F_277 ( V_2 , true , false ) ;
}
} else {
if ( F_277 ( V_2 , true , true ) ) {
if ( V_16 -> V_503 )
F_285 ( V_2 ) ;
if ( F_281 ( V_2 , true , true ) )
F_277 ( V_2 , true , false ) ;
}
}
F_285 ( V_2 ) ;
V_2 -> V_761 = V_761 ;
}
static int F_299 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_762 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_763 = V_2 -> V_764 ;
int V_18 ;
F_288 ( V_2 ) ;
F_289 ( V_2 -> V_28 ) ;
F_290 ( & V_2 -> V_725 ) ;
F_267 ( V_2 ) ;
F_18 ( F_19 ( V_47 , V_765 ) ,
V_2 -> V_28 -> V_736 ) ;
F_21 ( V_47 , V_766 ,
V_16 -> V_79 ) ;
V_18 = F_51 ( V_2 , V_767 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
F_260 ( V_2 ) ;
F_291 ( & V_2 -> V_725 ) ;
if ( V_763 )
F_293 ( V_2 -> V_28 ) ;
F_294 ( V_2 -> V_28 ) ;
#ifdef F_44
if ( V_2 -> V_10 -> V_151 && V_2 -> V_10 -> V_102 ) {
struct V_10 * V_104 = V_2 -> V_10 -> V_102 ;
if ( V_18 == - V_97 ) {
struct V_1 * V_105 ;
V_105 = F_24 ( V_104 ) ;
V_18 = F_300 ( V_105 ,
V_16 -> V_22 ,
V_2 -> V_28 -> V_736 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_105 = F_24 ( V_104 ) ;
struct V_15 * V_16 = V_105 -> V_16 ;
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_105 -> V_199 ; ++ V_67 ) {
struct V_149 * V_150 = V_16 -> V_150 + V_67 ;
if ( V_150 -> V_2 == V_2 ) {
F_18 ( V_150 -> V_160 ,
V_2 -> V_28 -> V_736 ) ;
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
V_18 = F_286 ( V_2 ) ;
} else {
F_52 ( V_2 , V_767 ,
sizeof( V_47 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_301 ( struct V_1 * V_2 )
{
F_295 ( V_2 ) ;
return F_302 ( V_2 ) ;
}
static int F_303 ( struct V_1 * V_2 )
{
F_295 ( V_2 ) ;
return 0 ;
}
static int F_304 ( struct V_1 * V_2 , T_6 V_768 )
{
F_8 ( V_47 , V_769 ) ;
F_21 ( V_47 , V_770 , V_768 ) ;
return F_9 ( V_2 , V_771 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
static int F_305 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_772 ) ;
T_2 V_17 ;
T_6 V_773 ;
V_18 = F_9 ( V_2 , V_774 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_772 )
return - V_7 ;
V_773 = F_10 ( V_13 , V_775 ) ;
switch ( V_773 ) {
case V_776 :
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_67 ) ;
return 0 ;
case V_777 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_68 ) ;
return - V_7 ;
case V_778 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_69 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_70 , V_773 ) ;
return - V_7 ;
}
}
static int F_306 ( struct V_1 * V_2 , T_6 V_768 )
{
int V_18 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_71 , V_768 ) ;
V_18 = F_304 ( V_2 , V_768 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_305 ( V_2 ) ;
}
static int
F_307 ( struct V_1 * V_2 , struct V_779 * V_780 )
{
int V_18 , V_755 ;
F_308 ( V_2 , V_214 ) ;
V_18 = F_9 ( V_2 , V_781 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_304;
V_780 -> V_782 = F_306 ( V_2 , V_783 ) ? - 1 : 1 ;
V_780 -> V_784 = F_306 ( V_2 , V_785 ) ? - 1 : 1 ;
V_18 = F_35 ( V_2 , V_214 ) ;
V_304:
if ( V_18 == - V_97 )
V_18 = 0 ;
V_755 = F_309 ( V_2 , V_214 , V_18 == 0 ) ;
return V_18 ? V_18 : V_755 ;
}
static int F_310 ( struct V_1 * V_2 ,
struct V_786 * V_787 ,
unsigned int type )
{
F_8 ( V_47 , V_788 ) ;
F_8 ( V_13 , V_789 ) ;
const struct V_790 * V_791 ;
T_2 V_700 , V_792 , V_17 ;
bool V_793 ;
int V_18 ;
for ( V_791 = V_794 ; ; V_791 ++ ) {
if ( V_791 ==
V_794 + F_159 ( V_794 ) )
return - V_37 ;
if ( ( type & ~ V_791 -> V_795 ) == V_791 -> type )
break;
}
if ( V_791 -> V_796 != F_311 ( V_2 ) )
return - V_37 ;
V_18 = F_312 ( V_2 , type , & V_700 , & V_792 , & V_793 ) ;
if ( V_18 )
return V_18 ;
if ( V_793 )
return - V_37 ;
V_787 -> V_797 = type ;
F_21 ( V_47 , V_798 , type ) ;
V_18 = F_9 ( V_2 , V_799 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_800 )
return - V_7 ;
if ( F_10 ( V_13 , V_801 ) &
( 1 << V_802 ) )
V_787 -> V_803 = F_10 ( V_13 ,
V_804 ) ;
V_787 -> V_805 . V_806 = L_72 ;
V_787 -> V_805 . V_807 = V_791 -> V_237 ;
V_787 -> V_805 . V_808 . type = V_809 ;
V_787 -> V_805 . V_808 . V_204 = V_810 ;
V_787 -> V_805 . V_808 . V_700 = V_700 ;
V_787 -> V_805 . V_808 . V_811 = V_792 ;
return 0 ;
}
static int F_313 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_812 ) ;
struct V_786 * V_813 ;
T_2 V_17 , V_814 , V_67 , V_815 ;
unsigned int type ;
int V_18 ;
F_314 () ;
F_13 ( V_816 != 0 ) ;
V_18 = F_9 ( V_2 , V_817 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_818 )
return - V_7 ;
V_814 = F_10 ( V_13 , V_819 ) ;
if ( V_814 >
F_261 ( V_17 , V_820 ) )
return - V_7 ;
V_813 = F_315 ( V_814 , sizeof( * V_813 ) , V_70 ) ;
if ( ! V_813 )
return - V_71 ;
V_815 = 0 ;
for ( V_67 = 0 ; V_67 < V_814 ; V_67 ++ ) {
type = F_262 ( V_13 , V_820 ,
V_67 ) ;
V_18 = F_310 ( V_2 , & V_813 [ V_815 ] , type ) ;
if ( V_18 == 0 )
V_815 ++ ;
else if ( V_18 != - V_37 )
goto V_135;
}
V_18 = F_316 ( V_2 , & V_813 [ 0 ] . V_805 , V_815 , sizeof( * V_813 ) ) ;
V_135:
if ( V_18 )
F_48 ( V_813 ) ;
return V_18 ;
}
static void F_317 ( struct V_1 * V_2 , T_6 V_821 )
{
F_32 ( V_2 , F_33 ( V_821 ) , V_328 ) ;
}
static void F_318 ( struct V_1 * V_2 ,
T_6 V_821 ) {}
static int F_319 ( struct V_123 * V_124 ,
bool V_822 )
{
F_8 ( V_47 , V_823 ) ;
int V_18 ;
if ( V_124 -> V_824 == V_825 ||
V_124 -> V_824 == V_826 ||
( V_822 && V_124 -> V_824 == V_827 ) )
return 0 ;
V_124 -> V_824 = V_825 ;
F_21 ( V_47 , V_828 , V_829 ) ;
F_21 ( V_47 , V_830 , 0 ) ;
F_21 ( V_47 , V_831 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_832 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_124 -> V_824 = V_822 ? V_833 :
V_827 ;
return V_18 ;
}
static int F_320 ( struct V_123 * V_124 ,
bool V_822 )
{
F_8 ( V_47 , V_834 ) ;
int V_18 ;
if ( V_124 -> V_824 == V_827 ||
( V_822 && V_124 -> V_824 == V_833 ) )
return 0 ;
if ( V_124 -> V_824 == V_833 ) {
V_124 -> V_824 = V_827 ;
return 0 ;
}
V_124 -> V_824 = V_822 ? V_833 :
V_827 ;
F_21 ( V_47 , V_828 , V_835 ) ;
F_21 ( V_47 , V_830 , 0 ) ;
F_21 ( V_47 , V_836 ,
V_837 ) ;
F_21 ( V_47 , V_838 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_832 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_321 ( struct V_1 * V_2 , bool V_839 ,
bool V_822 )
{
int (* F_322)( struct V_123 * V_124 , bool V_822 );
struct V_123 * V_124 ;
F_322 = V_839 ?
F_319 :
F_320 ;
F_58 (channel, efx) {
int V_18 = F_322 ( V_124 , V_822 ) ;
if ( V_839 && V_18 != 0 ) {
F_321 ( V_2 , false , V_822 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_323 ( struct V_1 * V_2 ,
struct V_840 * V_841 )
{
return - V_319 ;
}
static int F_324 ( struct V_1 * V_2 ,
struct V_840 * V_841 )
{
int V_18 ;
switch ( V_841 -> V_842 ) {
case V_843 :
F_321 ( V_2 , false , false ) ;
return F_325 ( V_2 ,
V_841 -> V_844 != V_845 , 0 ) ;
case V_846 :
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
V_841 -> V_842 = V_846 ;
V_18 = F_325 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_321 ( V_2 , true , false ) ;
if ( V_18 )
F_325 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_41 ;
}
}
