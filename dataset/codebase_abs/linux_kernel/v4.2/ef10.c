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
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_2 ) ;
return - V_36 ;
}
if ( ! ( V_16 -> V_29 &
( 1 << V_37 ) ) ) {
F_14 ( V_2 , V_38 , V_2 -> V_28 ,
L_3 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_39 ) ;
int V_18 ;
V_18 = F_9 ( V_2 , V_40 , NULL , 0 ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 )
return V_18 ;
V_18 = F_10 ( V_13 , V_41 ) ;
return V_18 > 0 ? V_18 : - V_42 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_43 )
{
F_8 ( V_13 , V_44 ) ;
T_2 V_17 ;
int V_18 ;
F_13 ( V_45 != 0 ) ;
V_18 = F_9 ( V_2 , V_46 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_44 )
return - V_7 ;
F_18 ( V_43 ,
F_19 ( V_13 , V_47 ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 * V_43 )
{
F_8 ( V_48 , V_49 ) ;
F_8 ( V_13 , V_50 ) ;
T_2 V_17 ;
int V_51 , V_18 ;
F_21 ( V_48 , V_52 ,
V_53 ) ;
V_18 = F_9 ( V_2 , V_54 , V_48 ,
sizeof( V_48 ) , V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_55 )
return - V_7 ;
V_51 = F_10 ( V_13 ,
V_56 ) ;
F_22 ( V_51 != 1 ) ;
F_18 ( V_43 ,
F_19 ( V_13 , V_57 ) ) ;
return 0 ;
}
static T_4 F_23 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_24 ( F_25 ( V_59 ) ) ;
return sprintf ( V_62 , L_4 ,
( ( V_2 -> V_63 -> V_64 ) &
( 1 << V_65 ) )
? 1 : 0 ) ;
}
static T_4 F_26 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_24 ( F_25 ( V_59 ) ) ;
return sprintf ( V_62 , L_4 ,
( ( V_2 -> V_63 -> V_64 ) &
( 1 << V_66 ) )
? 1 : 0 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_67 * V_28 = V_2 -> V_28 ;
int V_68 , V_18 ;
V_2 -> V_69 =
F_28 (unsigned int,
EFX_MAX_CHANNELS,
efx_ef10_mem_map_size(efx) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
if ( F_22 ( V_2 -> V_69 == 0 ) )
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
V_68 = 0 ;
for (; ; ) {
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 )
break;
if ( ++ V_68 == 5 )
goto V_75;
F_31 ( 1 ) ;
}
V_16 -> V_76 = V_18 ;
V_16 -> V_77 = V_78 ;
V_16 -> V_79 = V_53 ;
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
V_18 = F_37 ( & V_2 -> V_10 -> V_59 ,
& V_83 ) ;
if ( V_18 )
goto V_82;
V_18 = F_37 ( & V_2 -> V_10 -> V_59 , & V_84 ) ;
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
V_18 = F_39 ( V_2 , V_95 , true ) ;
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
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_5 ,
V_16 -> V_96 ? L_6 : L_7 ) ;
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
F_45 ( & V_2 -> V_10 -> V_59 , & V_84 ) ;
V_85:
F_45 ( & V_2 -> V_10 -> V_59 , & V_83 ) ;
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
F_8 ( V_48 , V_109 ) ;
unsigned int V_68 ;
int V_18 ;
F_13 ( V_110 != 0 ) ;
for ( V_68 = 0 ; V_68 < V_16 -> V_111 ; V_68 ++ ) {
F_21 ( V_48 , V_112 ,
V_16 -> V_113 [ V_68 ] ) ;
V_18 = F_9 ( V_2 , V_114 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 ) ;
}
V_16 -> V_111 = 0 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_115 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_13 , V_116 ) ;
unsigned int V_68 ;
T_2 V_17 ;
int V_18 = 0 ;
F_13 ( V_117 != 0 ) ;
for ( V_68 = 0 ; V_68 < V_115 ; V_68 ++ ) {
V_18 = F_9 ( V_2 , V_118 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
break;
if ( V_17 < V_116 ) {
V_18 = - V_7 ;
break;
}
V_16 -> V_113 [ V_68 ] =
F_10 ( V_13 , V_119 ) ;
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_8 , V_68 ,
V_16 -> V_113 [ V_68 ] ) ;
}
V_16 -> V_111 = V_68 ;
if ( V_18 )
F_53 ( V_2 ) ;
return V_18 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_56 ( V_48 ,
F_57 ( V_120 ,
V_121 ) ) ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
unsigned int V_126 , V_127 ;
int V_18 ;
F_13 ( V_128 != 0 ) ;
F_13 ( V_129 != 0 ) ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
for ( V_127 = 0 ; V_127 < V_16 -> V_111 ; ++ V_127 ) {
F_21 ( V_48 , V_130 ,
V_16 -> V_113 [ V_127 ] ) ;
F_21 ( V_48 , V_131 ,
V_16 -> V_132 + V_127 ) ;
V_18 = F_9 ( V_2 , V_133 ,
V_48 , V_120 ,
NULL , 0 , NULL ) ;
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_9 ,
V_16 -> V_132 + V_127 , V_127 ,
V_18 ) ;
goto V_134;
}
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_10 ,
V_16 -> V_132 + V_127 , V_127 ) ;
}
F_58 (channel, efx) {
F_59 (tx_queue, channel) {
V_126 = ( ( V_2 -> V_135 + V_2 -> V_136 -
V_125 -> V_123 -> V_123 - 1 ) *
V_137 ) ;
V_127 = V_126 / V_138 ;
V_126 = V_126 % V_138 ;
if ( V_125 -> V_139 == V_16 -> V_132 ) {
F_60 ( V_127 != 0 ) ;
V_18 = 0 ;
} else {
F_21 ( V_48 ,
V_130 ,
V_16 -> V_113 [ V_127 ] ) ;
F_21 ( V_48 ,
V_131 ,
V_125 -> V_139 ) ;
V_18 = F_9 ( V_2 , V_133 ,
V_48 , V_120 ,
NULL , 0 , NULL ) ;
}
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_9 ,
V_125 -> V_139 , V_127 , V_18 ) ;
V_125 -> V_140 = NULL ;
} else {
V_125 -> V_140 =
V_16 -> V_141 +
V_127 * V_142 + V_126 ;
V_125 -> V_143 = V_126 ;
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_11 ,
V_125 -> V_139 , V_127 ,
V_125 -> V_143 ,
V_125 -> V_140 ) ;
}
}
}
return 0 ;
V_134:
while ( V_127 -- ) {
F_21 ( V_48 , V_144 ,
V_16 -> V_132 + V_127 ) ;
F_9 ( V_2 , V_145 ,
V_48 , V_121 ,
NULL , 0 , NULL ) ;
}
return V_18 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_115 )
{
return V_115 == 0 ? 0 : - V_146 ;
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
struct V_15 * V_147 ;
struct V_10 * V_104 ;
struct V_1 * V_105 ;
struct V_148 * V_149 ;
if ( V_2 -> V_10 -> V_150 ) {
V_104 = V_2 -> V_10 -> V_102 ;
if ( V_104 ) {
V_105 = F_24 ( V_104 ) ;
V_147 = V_105 -> V_16 ;
V_149 = V_147 -> V_149 + V_16 -> V_22 ;
V_149 -> V_2 = NULL ;
} else
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_12 ) ;
}
#endif
F_63 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
if ( V_16 -> V_151 )
F_66 ( V_16 -> V_151 ) ;
V_18 = F_49 ( V_2 ) ;
F_22 ( V_18 != 0 ) ;
if ( ! V_16 -> V_152 )
F_53 ( V_2 ) ;
F_45 ( & V_2 -> V_10 -> V_59 , & V_84 ) ;
F_45 ( & V_2 -> V_10 -> V_59 , & V_83 ) ;
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
F_8 ( V_48 , V_153 ) ;
F_21 ( V_48 , V_154 , V_106 ) ;
return F_9 ( V_2 , V_155 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
}
int F_69 ( struct V_1 * V_2 , unsigned int V_106 )
{
F_8 ( V_48 , V_156 ) ;
F_21 ( V_48 , V_157 , V_106 ) ;
return F_9 ( V_2 , V_158 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
}
int F_70 ( struct V_1 * V_2 ,
unsigned int V_106 , T_3 * V_159 )
{
F_8 ( V_48 , V_160 ) ;
F_21 ( V_48 , V_161 , V_106 ) ;
F_18 ( F_19 ( V_48 , V_162 ) , V_159 ) ;
return F_9 ( V_2 , V_163 , V_48 ,
sizeof( V_48 ) , NULL , 0 , NULL ) ;
}
int F_71 ( struct V_1 * V_2 ,
unsigned int V_106 , T_3 * V_159 )
{
F_8 ( V_48 , V_164 ) ;
F_21 ( V_48 , V_165 , V_106 ) ;
F_18 ( F_19 ( V_48 , V_166 ) , V_159 ) ;
return F_9 ( V_2 , V_167 , V_48 ,
sizeof( V_48 ) , NULL , 0 , NULL ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_10 * V_104 ;
V_104 = V_2 -> V_10 -> V_102 ;
if ( V_104 ) {
struct V_1 * V_105 = F_24 ( V_104 ) ;
struct V_15 * V_147 = V_105 -> V_16 ;
if ( ! V_147 -> V_149 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_13
L_14 ) ;
return - V_168 ;
}
}
V_18 = F_27 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
goto V_134;
if ( V_2 -> V_10 -> V_150 ) {
if ( V_2 -> V_10 -> V_102 ) {
struct V_1 * V_105 =
F_24 ( V_2 -> V_10 -> V_102 ) ;
struct V_15 * V_169 = V_105 -> V_16 ;
struct V_15 * V_16 = V_2 -> V_16 ;
V_169 -> V_149 [ V_16 -> V_22 ] . V_2 = V_2 ;
V_169 -> V_149 [ V_16 -> V_22 ] . V_10 =
V_2 -> V_10 ;
} else
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_12 ) ;
}
return 0 ;
V_134:
F_61 ( V_2 ) ;
return V_18 ;
}
static int F_73 ( struct V_1 * V_2 ,
unsigned int V_170 , unsigned int V_171 )
{
F_8 ( V_48 , V_172 ) ;
F_8 ( V_13 , V_173 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_174 , V_170 ) ;
F_21 ( V_48 , V_175 , V_171 ) ;
V_18 = F_9 ( V_2 , V_176 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_173 )
return - V_7 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_15 ,
F_10 ( V_13 , V_177 ) ) ;
V_16 -> V_178 = F_10 ( V_13 , V_177 ) ;
V_16 -> V_179 = F_10 ( V_13 , V_180 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_181 , V_182 ;
unsigned int V_170 , V_132 , V_171 ;
void T_5 * V_183 ;
int V_18 ;
V_170 = F_57 ( V_2 -> V_184 , V_2 -> V_136 * V_185 ) ;
#ifdef F_75
if ( V_137 != 0 &&
V_138 / V_137 * V_186 >=
V_2 -> V_136 ) {
unsigned int V_111 =
F_76 ( V_2 -> V_136 ,
V_138 / V_137 ) ;
V_18 = F_54 ( V_2 , V_111 ) ;
if ( V_18 )
F_14 ( V_2 , V_38 , V_2 -> V_28 ,
L_16 , V_18 ) ;
else
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_17 , V_111 ) ;
}
#else
V_16 -> V_111 = 0 ;
#endif
V_181 = F_77 ( ( V_170 - 1 ) * V_142 +
V_187 ) ;
if ( V_16 -> V_111 ) {
V_132 = V_181 / V_142 ;
V_182 = ( F_77 ( ( V_132 +
V_16 -> V_111 ) *
V_142 ) -
V_181 ) ;
V_171 = V_132 + V_16 -> V_111 ;
} else {
V_132 = 0 ;
V_182 = 0 ;
V_171 = V_170 ;
}
V_18 = F_49 ( V_2 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_73 ( V_2 , V_170 , V_171 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_16 -> V_111 &&
V_16 -> V_179 <
V_132 + V_16 -> V_111 ) {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_18 ,
V_16 -> V_179 , V_16 -> V_111 ) ;
F_53 ( V_2 ) ;
}
V_183 = F_78 ( V_2 -> V_188 , V_181 ) ;
if ( ! V_183 ) {
F_14 ( V_2 , V_38 , V_2 -> V_28 ,
L_19 ,
V_181 ) ;
return - V_71 ;
}
F_66 ( V_2 -> V_183 ) ;
V_2 -> V_183 = V_183 ;
if ( V_182 ) {
V_16 -> V_151 = F_79 ( V_2 -> V_188 +
V_181 ,
V_182 ) ;
if ( ! V_16 -> V_151 ) {
F_14 ( V_2 , V_38 , V_2 -> V_28 ,
L_20 ,
V_182 ) ;
return - V_71 ;
}
V_16 -> V_132 = V_132 ;
V_16 -> V_141 =
V_16 -> V_151 +
( V_132 * V_142 + V_187 -
V_181 ) ;
V_18 = F_55 ( V_2 ) ;
if ( V_18 )
F_53 ( V_2 ) ;
}
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_21 ,
& V_2 -> V_188 , V_2 -> V_183 , V_181 ,
V_16 -> V_151 , V_182 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
if ( V_16 -> V_189 ) {
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_189 = false ;
}
if ( V_16 -> V_190 ) {
V_18 = F_73 ( V_2 , V_16 -> V_179 ,
V_16 -> V_179 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_190 = false ;
}
if ( V_16 -> V_152 && V_16 -> V_111 ) {
V_18 = F_54 ( V_2 , V_16 -> V_111 ) ;
if ( V_18 == 0 ) {
V_18 = F_55 ( V_2 ) ;
if ( V_18 )
F_53 ( V_2 ) ;
}
if ( V_18 )
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_22 , V_18 ) ;
V_16 -> V_152 = false ;
}
V_2 -> type -> V_191 ( V_2 , false , V_2 -> V_192 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
V_16 -> V_190 = true ;
V_16 -> V_193 = true ;
V_16 -> V_152 = true ;
V_16 -> V_77 = V_78 ;
}
static enum V_194 F_82 ( enum V_194 V_195 )
{
if ( V_195 == V_196 )
return V_197 ;
return F_83 ( V_195 ) ;
}
static int F_84 ( T_6 * V_198 )
{
enum {
V_199 = ( ( V_200 | V_201 ) <<
V_202 ) ,
V_203 = ( ( V_204 | V_205 |
V_206 | V_200 |
V_201 | V_207 ) <<
V_202 )
};
if ( ( * V_198 & V_203 ) == V_203 ) {
* V_198 &= ~ V_203 ;
return V_208 ;
}
if ( ( * V_198 & V_199 ) == V_199 ) {
* V_198 &= ~ V_199 ;
return V_81 ;
}
return - V_209 ;
}
static int F_85 ( struct V_1 * V_2 , enum V_194 V_194 )
{
int V_18 = F_35 ( V_2 , V_194 ) ;
if ( ( V_194 == V_81 ||
V_194 == V_210 ) && ! V_18 )
F_81 ( V_2 ) ;
return V_18 ;
}
static T_7 F_86 ( struct V_1 * V_2 )
{
T_7 V_211 = V_212 ;
T_6 V_213 = F_87 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_63 -> V_64 &
1 << V_65 ) )
return 0 ;
if ( V_213 & ( 1 << V_214 ) )
V_211 |= V_215 ;
else
V_211 |= V_216 ;
if ( V_16 -> V_29 &
( 1 << V_217 ) )
V_211 |= V_218 ;
return V_211 ;
}
static void F_88 ( struct V_1 * V_2 , unsigned long * V_219 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_7 V_211 [ 2 ] ;
V_211 [ 0 ] = F_86 ( V_2 ) ;
if ( V_16 -> V_29 &
( 1 << V_220 ) ) {
V_211 [ 0 ] |= ~ ( ( 1ULL << V_221 ) - 1 ) ;
V_211 [ 1 ] = ( 1ULL << ( V_222 - 63 ) ) - 1 ;
} else {
V_211 [ 1 ] = 0 ;
}
#if V_223 == 64
V_219 [ 0 ] = V_211 [ 0 ] ;
V_219 [ 1 ] = V_211 [ 1 ] ;
#else
V_219 [ 0 ] = V_211 [ 0 ] & 0xffffffff ;
V_219 [ 1 ] = V_211 [ 0 ] >> 32 ;
V_219 [ 2 ] = V_211 [ 1 ] & 0xffffffff ;
V_219 [ 3 ] = V_211 [ 1 ] >> 32 ;
#endif
}
static T_2 F_89 ( struct V_1 * V_2 , T_3 * V_224 )
{
F_90 ( V_219 , V_222 ) ;
F_88 ( V_2 , V_219 ) ;
return F_91 ( V_225 , V_222 ,
V_219 , V_224 ) ;
}
static T_2 F_92 ( struct V_1 * V_2 , T_7 * V_226 ,
struct V_227 * V_228 )
{
F_90 ( V_219 , V_222 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_7 * V_229 = V_16 -> V_229 ;
T_2 V_230 = 0 , V_127 ;
F_88 ( V_2 , V_219 ) ;
if ( V_226 ) {
F_93 (index, mask, EF10_STAT_COUNT) {
if ( V_225 [ V_127 ] . V_231 ) {
* V_226 ++ = V_229 [ V_127 ] ;
++ V_230 ;
}
}
}
if ( ! V_228 )
return V_230 ;
if ( V_16 -> V_29 &
1 << V_220 ) {
V_228 -> V_232 = V_229 [ V_221 ] +
V_229 [ V_233 ] +
V_229 [ V_234 ] ;
V_228 -> V_235 = V_229 [ V_236 ] +
V_229 [ V_237 ] +
V_229 [ V_238 ] ;
V_228 -> V_239 = V_229 [ V_240 ] +
V_229 [ V_241 ] +
V_229 [ V_242 ] ;
V_228 -> V_243 = V_229 [ V_244 ] +
V_229 [ V_245 ] +
V_229 [ V_246 ] ;
V_228 -> V_247 = V_229 [ V_248 ] +
V_229 [ V_249 ] ;
V_228 -> V_250 = V_229 [ V_233 ] ;
V_228 -> V_251 = V_229 [ V_252 ] ;
V_228 -> V_253 = V_229 [ V_254 ] ;
V_228 -> V_255 = V_228 -> V_251 ;
V_228 -> V_256 = V_229 [ V_257 ] ;
} else {
V_228 -> V_232 = V_229 [ V_258 ] ;
V_228 -> V_235 = V_229 [ V_259 ] ;
V_228 -> V_239 = V_229 [ V_260 ] ;
V_228 -> V_243 = V_229 [ V_261 ] ;
V_228 -> V_247 = V_229 [ V_262 ] +
V_229 [ V_248 ] +
V_229 [ V_249 ] ;
V_228 -> V_250 = V_229 [ V_263 ] ;
V_228 -> V_264 =
V_229 [ V_265 ] +
V_229 [ V_266 ] ;
V_228 -> V_251 = V_229 [ V_267 ] ;
V_228 -> V_268 =
V_229 [ V_269 ] ;
V_228 -> V_253 = V_229 [ V_270 ] ;
V_228 -> V_255 = ( V_228 -> V_264 +
V_228 -> V_251 +
V_228 -> V_268 ) ;
}
return V_230 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_90 ( V_219 , V_222 ) ;
T_8 V_271 , V_272 ;
T_7 * V_229 = V_16 -> V_229 ;
T_8 * V_273 ;
F_88 ( V_2 , V_219 ) ;
V_273 = V_2 -> V_274 . V_275 ;
V_16 = V_2 -> V_16 ;
V_272 = V_273 [ V_276 ] ;
if ( V_272 == V_277 )
return 0 ;
F_95 () ;
F_96 ( V_225 , V_222 , V_219 ,
V_229 , V_2 -> V_274 . V_275 , false ) ;
F_95 () ;
V_271 = V_273 [ V_278 ] ;
if ( V_272 != V_271 )
return - V_279 ;
F_97 ( V_2 ,
& V_229 [ V_262 ] ) ;
V_229 [ V_280 ] =
V_229 [ V_260 ] -
V_229 [ V_281 ] ;
F_98 ( & V_229 [ V_282 ] ,
V_229 [ V_281 ] ) ;
F_99 ( V_2 , V_229 ) ;
return 0 ;
}
static T_2 F_100 ( struct V_1 * V_2 , T_7 * V_226 ,
struct V_227 * V_228 )
{
int V_283 ;
for ( V_283 = 0 ; V_283 < 100 ; ++ V_283 ) {
if ( F_94 ( V_2 ) == 0 )
break;
F_101 ( 100 ) ;
}
return F_92 ( V_2 , V_226 , V_228 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_284 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
F_90 ( V_219 , V_222 ) ;
T_8 V_271 , V_272 ;
T_7 * V_229 = V_16 -> V_229 ;
T_6 V_285 = V_286 * sizeof( T_7 ) ;
struct V_287 V_288 ;
T_8 * V_273 ;
int V_18 ;
F_103 ( & V_2 -> V_289 ) ;
if ( F_104 () ) {
F_105 ( & V_2 -> V_289 ) ;
F_99 ( V_2 , V_229 ) ;
return 0 ;
}
F_88 ( V_2 , V_219 ) ;
V_18 = F_30 ( V_2 , & V_288 , V_285 , V_290 ) ;
if ( V_18 ) {
F_105 ( & V_2 -> V_289 ) ;
return V_18 ;
}
V_273 = V_288 . V_275 ;
V_273 [ V_276 ] = V_277 ;
F_106 ( V_48 , V_291 , V_288 . V_292 ) ;
F_107 ( V_48 , V_293 ,
V_294 , 1 ) ;
F_21 ( V_48 , V_295 , V_285 ) ;
F_21 ( V_48 , V_296 , V_53 ) ;
V_18 = F_51 ( V_2 , V_297 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_289 ) ;
if ( V_18 ) {
if ( V_18 != - V_101 || F_108 ( & V_2 -> V_298 ) )
F_52 ( V_2 , V_297 ,
sizeof( V_48 ) , NULL , 0 , V_18 ) ;
goto V_299;
}
V_272 = V_273 [ V_276 ] ;
if ( V_272 == V_277 ) {
F_109 ( 1 ) ;
goto V_299;
}
F_95 () ;
F_96 ( V_225 , V_222 , V_219 ,
V_229 , V_288 . V_275 , false ) ;
F_95 () ;
V_271 = V_273 [ V_278 ] ;
if ( V_272 != V_271 ) {
V_18 = - V_279 ;
goto V_299;
}
F_99 ( V_2 , V_229 ) ;
V_299:
F_47 ( V_2 , & V_288 ) ;
return V_18 ;
}
static T_2 F_110 ( struct V_1 * V_2 , T_7 * V_226 ,
struct V_227 * V_228 )
{
if ( F_102 ( V_2 ) )
return 0 ;
return F_92 ( V_2 , V_226 , V_228 ) ;
}
static void F_111 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = V_123 -> V_2 ;
unsigned int V_300 , V_301 ;
T_1 V_302 ;
if ( V_123 -> V_303 ) {
V_300 = 3 ;
V_301 = V_123 -> V_303 - 1 ;
} else {
V_300 = 0 ;
V_301 = 0 ;
}
if ( F_112 ( V_2 ) ) {
F_113 ( V_302 , V_304 ,
V_305 ,
V_306 , V_300 ,
V_307 , V_301 ) ;
F_114 ( V_2 , & V_302 , V_308 ,
V_123 -> V_123 ) ;
} else {
F_115 ( V_302 , V_309 , V_300 ,
V_310 , V_301 ) ;
F_114 ( V_2 , & V_302 , V_311 ,
V_123 -> V_123 ) ;
}
}
static void F_116 ( struct V_1 * V_2 ,
struct V_312 * V_313 ) {}
static int F_117 ( struct V_1 * V_2 , T_6 type )
{
return - V_314 ;
}
static void F_118 ( struct V_1 * V_2 , struct V_312 * V_313 )
{
V_313 -> V_315 = 0 ;
V_313 -> V_316 = 0 ;
memset ( & V_313 -> V_317 , 0 , sizeof( V_313 -> V_317 ) ) ;
}
static int F_119 ( struct V_1 * V_2 , T_6 type )
{
if ( type != 0 )
return - V_209 ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 ,
const T_1 * V_318 , T_2 V_319 ,
const T_1 * V_320 , T_2 V_321 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 * V_322 = V_16 -> V_73 . V_275 ;
memcpy ( V_322 , V_318 , V_319 ) ;
memcpy ( V_322 + V_319 , V_320 , V_321 ) ;
F_121 () ;
F_32 ( V_2 , F_33 ( ( T_7 ) V_16 -> V_73 . V_292 >> 32 ) ,
V_323 ) ;
F_32 ( V_2 , F_33 ( ( T_6 ) V_16 -> V_73 . V_292 ) ,
V_80 ) ;
}
static bool F_122 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_1 V_318 = * ( const T_1 * ) V_16 -> V_73 . V_275 ;
F_95 () ;
return F_3 ( V_318 , V_324 ) ;
}
static void
F_123 ( struct V_1 * V_2 , T_1 * V_13 ,
T_2 V_126 , T_2 V_17 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_3 * V_322 = V_16 -> V_73 . V_275 ;
memcpy ( V_13 , V_322 + V_126 , V_17 ) ;
}
static int F_124 ( struct V_1 * V_2 )
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
F_81 ( V_2 ) ;
V_16 -> V_325 = true ;
V_16 -> V_79 = V_53 ;
V_16 -> V_189 = true ;
V_16 -> V_229 [ V_282 ] = 0 ;
return - V_7 ;
}
static T_9 F_125 ( int V_326 , void * V_327 )
{
struct V_328 * V_329 = V_327 ;
struct V_1 * V_2 = V_329 -> V_2 ;
F_126 ( V_2 , V_330 , V_2 -> V_28 ,
L_23 , V_326 , F_127 () ) ;
if ( F_128 ( F_129 ( V_2 -> V_331 ) ) ) {
if ( V_329 -> V_127 == V_2 -> V_332 )
V_2 -> V_333 = F_127 () ;
F_130 ( V_2 -> V_123 [ V_329 -> V_127 ] ) ;
}
return V_334 ;
}
static T_9 F_131 ( int V_326 , void * V_327 )
{
struct V_1 * V_2 = V_327 ;
bool V_335 = F_129 ( V_2 -> V_331 ) ;
struct V_122 * V_123 ;
T_1 V_3 ;
T_6 V_336 ;
F_2 ( V_2 , & V_3 , V_337 ) ;
V_336 = F_3 ( V_3 , V_338 ) ;
if ( V_336 == 0 )
return V_339 ;
if ( F_128 ( V_335 ) ) {
if ( V_336 & ( 1U << V_2 -> V_332 ) )
V_2 -> V_333 = F_127 () ;
F_58 (channel, efx) {
if ( V_336 & 1 )
F_130 ( V_123 ) ;
V_336 >>= 1 ;
}
}
F_126 ( V_2 , V_330 , V_2 -> V_28 ,
L_24 V_340 L_25 ,
V_326 , F_127 () , F_132 ( V_3 ) ) ;
return V_334 ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_341 ) ;
F_13 ( V_342 != 0 ) ;
F_21 ( V_48 , V_343 , V_2 -> V_332 ) ;
( void ) F_9 ( V_2 , V_344 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
}
static int F_134 ( struct V_124 * V_125 )
{
return F_30 ( V_125 -> V_2 , & V_125 -> V_345 . V_62 ,
( V_125 -> V_346 + 1 ) *
sizeof( V_347 ) ,
V_70 ) ;
}
static inline void F_135 ( struct V_124 * V_125 ,
const V_347 * V_345 )
{
unsigned int V_348 ;
T_10 V_3 ;
V_348 = V_125 -> V_349 & V_125 -> V_346 ;
F_136 ( V_3 , V_350 , V_348 ) ;
V_3 . V_351 [ 0 ] = * V_345 ;
F_137 ( V_125 -> V_2 , & V_3 ,
V_352 , V_125 -> V_139 ) ;
}
static void F_138 ( struct V_124 * V_125 )
{
F_8 ( V_48 , F_139 ( V_353 * 8 /
V_354 ) ) ;
bool V_355 = V_125 -> V_139 & V_356 ;
T_2 V_357 = V_125 -> V_345 . V_62 . V_358 / V_354 ;
struct V_122 * V_123 = V_125 -> V_123 ;
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_359 ;
T_11 V_292 ;
V_347 * V_345 ;
int V_18 ;
int V_68 ;
F_13 ( V_360 != 0 ) ;
F_21 ( V_48 , V_361 , V_125 -> V_346 + 1 ) ;
F_21 ( V_48 , V_362 , V_123 -> V_123 ) ;
F_21 ( V_48 , V_363 , V_125 -> V_139 ) ;
F_21 ( V_48 , V_364 , V_125 -> V_139 ) ;
F_140 ( V_48 , V_365 ,
V_366 , ! V_355 ,
V_367 , ! V_355 ) ;
F_21 ( V_48 , V_368 , 0 ) ;
F_21 ( V_48 , V_369 , V_16 -> V_79 ) ;
V_292 = V_125 -> V_345 . V_62 . V_292 ;
F_41 ( V_2 , V_370 , V_2 -> V_28 , L_26 ,
V_125 -> V_139 , V_357 , ( T_7 ) V_292 ) ;
for ( V_68 = 0 ; V_68 < V_357 ; ++ V_68 ) {
F_141 ( V_48 , V_371 , V_68 , V_292 ) ;
V_292 += V_354 ;
}
V_359 = F_139 ( V_357 ) ;
V_18 = F_9 ( V_2 , V_372 , V_48 , V_359 ,
NULL , 0 , NULL ) ;
if ( V_18 )
goto V_134;
V_125 -> V_373 [ 0 ] . V_198 = V_374 ;
V_125 -> V_375 = 1 ;
V_345 = F_142 ( V_125 , 0 ) ;
F_143 ( * V_345 ,
V_376 , true ,
V_377 ,
V_378 ,
V_379 , V_355 ,
V_380 , V_355 ) ;
V_125 -> V_349 = 1 ;
F_121 () ;
F_135 ( V_125 , V_345 ) ;
return;
V_134:
F_144 ( V_2 -> V_28 , L_27 ,
V_125 -> V_139 ) ;
}
static void F_145 ( struct V_124 * V_125 )
{
F_8 ( V_48 , V_381 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_125 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_382 ,
V_125 -> V_139 ) ;
V_18 = F_51 ( V_2 , V_383 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_134;
return;
V_134:
F_52 ( V_2 , V_383 , V_381 ,
V_13 , V_17 , V_18 ) ;
}
static void F_146 ( struct V_124 * V_125 )
{
F_47 ( V_125 -> V_2 , & V_125 -> V_345 . V_62 ) ;
}
static inline void F_147 ( struct V_124 * V_125 )
{
unsigned int V_348 ;
T_1 V_3 ;
V_348 = V_125 -> V_349 & V_125 -> V_346 ;
F_148 ( V_3 , V_384 , V_348 ) ;
F_114 ( V_125 -> V_2 , & V_3 ,
V_385 , V_125 -> V_139 ) ;
}
static void F_149 ( struct V_124 * V_125 )
{
unsigned int V_386 = V_125 -> V_349 ;
struct V_387 * V_373 ;
unsigned int V_348 ;
V_347 * V_345 ;
F_60 ( V_125 -> V_349 == V_125 -> V_375 ) ;
do {
V_348 = V_125 -> V_349 & V_125 -> V_346 ;
V_373 = & V_125 -> V_373 [ V_348 ] ;
V_345 = F_142 ( V_125 , V_348 ) ;
++ V_125 -> V_349 ;
if ( V_373 -> V_198 & V_374 ) {
* V_345 = V_373 -> V_388 ;
} else {
F_13 ( V_389 != 1 ) ;
F_150 (
* V_345 ,
V_390 ,
V_373 -> V_198 & V_389 ,
V_391 , V_373 -> V_358 ,
V_392 , V_373 -> V_292 ) ;
}
} while ( V_125 -> V_349 != V_125 -> V_375 );
F_121 () ;
if ( F_151 ( V_125 , V_386 ) ) {
V_345 = F_142 ( V_125 ,
V_386 & V_125 -> V_346 ) ;
F_135 ( V_125 , V_345 ) ;
++ V_125 -> V_393 ;
} else {
F_147 ( V_125 ) ;
}
}
static int F_152 ( struct V_1 * V_2 , T_6 * V_329 ,
bool V_394 , unsigned * V_395 )
{
F_8 ( V_48 , V_396 ) ;
F_8 ( V_13 , V_397 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_6 V_398 = V_394 ?
V_399 :
V_400 ;
unsigned V_401 = V_394 ?
V_2 -> V_401 :
F_153 ( F_154 ( V_2 -> V_401 ) ,
V_402 ) ;
if ( ! V_394 && V_401 == 1 ) {
* V_329 = V_78 ;
if ( V_395 )
* V_395 = 1 ;
return 0 ;
}
F_21 ( V_48 , V_403 ,
V_16 -> V_79 ) ;
F_21 ( V_48 , V_404 , V_398 ) ;
F_21 ( V_48 , V_405 , V_401 ) ;
V_18 = F_9 ( V_2 , V_406 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_397 )
return - V_7 ;
* V_329 = F_10 ( V_13 , V_407 ) ;
if ( V_395 )
* V_395 = V_401 ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 , T_6 V_329 )
{
F_8 ( V_48 , V_408 ) ;
int V_18 ;
F_21 ( V_48 , V_409 ,
V_329 ) ;
V_18 = F_9 ( V_2 , V_410 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 != 0 ) ;
}
static int F_156 ( struct V_1 * V_2 , T_6 V_329 ,
const T_6 * V_192 )
{
F_8 ( V_411 , V_412 ) ;
F_8 ( V_413 , V_414 ) ;
int V_68 , V_18 ;
F_21 ( V_411 , V_415 ,
V_329 ) ;
F_13 ( F_157 ( V_2 -> V_192 ) !=
V_416 ) ;
for ( V_68 = 0 ; V_68 < F_157 ( V_2 -> V_192 ) ; ++ V_68 )
F_19 ( V_411 ,
V_417 ) [ V_68 ] =
( T_3 ) V_192 [ V_68 ] ;
V_18 = F_9 ( V_2 , V_418 , V_411 ,
sizeof( V_411 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_21 ( V_413 , V_419 ,
V_329 ) ;
F_13 ( F_157 ( V_2 -> V_420 ) !=
V_421 ) ;
for ( V_68 = 0 ; V_68 < F_157 ( V_2 -> V_420 ) ; ++ V_68 )
F_19 ( V_413 , V_422 ) [ V_68 ] =
V_2 -> V_420 [ V_68 ] ;
return F_9 ( V_2 , V_423 , V_413 ,
sizeof( V_413 ) , NULL , 0 , NULL ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_77 != V_78 )
F_155 ( V_2 , V_16 -> V_77 ) ;
V_16 -> V_77 = V_78 ;
}
static int F_158 ( struct V_1 * V_2 ,
unsigned * V_395 )
{
T_6 V_424 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_152 ( V_2 , & V_424 ,
false , V_395 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_77 = V_424 ;
V_16 -> V_425 = false ;
F_159 ( V_2 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 ,
const T_6 * V_192 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_424 ;
if ( V_16 -> V_77 == V_78 ||
! V_16 -> V_425 ) {
V_18 = F_152 ( V_2 , & V_424 ,
true , NULL ) ;
if ( V_18 == - V_314 )
return V_18 ;
else if ( V_18 != 0 )
goto V_74;
} else {
V_424 = V_16 -> V_77 ;
}
V_18 = F_156 ( V_2 , V_424 ,
V_192 ) ;
if ( V_18 != 0 )
goto V_75;
if ( V_16 -> V_77 != V_424 )
F_65 ( V_2 ) ;
V_16 -> V_77 = V_424 ;
V_16 -> V_425 = true ;
if ( V_192 != V_2 -> V_192 )
memcpy ( V_2 -> V_192 , V_192 ,
sizeof( V_2 -> V_192 ) ) ;
return 0 ;
V_75:
if ( V_424 != V_16 -> V_77 )
F_155 ( V_2 , V_424 ) ;
V_74:
F_14 ( V_2 , V_370 , V_2 -> V_28 , L_28 , V_426 , V_18 ) ;
return V_18 ;
}
static int F_161 ( struct V_1 * V_2 , bool V_427 ,
const T_6 * V_192 )
{
int V_18 ;
if ( V_2 -> V_401 == 1 )
return 0 ;
V_18 = F_160 ( V_2 , V_192 ) ;
if ( V_18 == - V_146 && ! V_427 ) {
unsigned V_395 ;
bool V_428 = false ;
T_2 V_68 ;
for ( V_68 = 0 ; V_68 < F_157 ( V_2 -> V_192 ) && ! V_428 ;
V_68 ++ )
V_428 = V_192 [ V_68 ] !=
F_162 ( V_68 , V_2 -> V_401 ) ;
V_18 = F_158 ( V_2 , & V_395 ) ;
if ( V_18 == 0 ) {
if ( V_395 != V_2 -> V_401 )
F_163 ( V_2 , V_38 , V_2 -> V_28 ,
L_29
L_30
L_31
L_32 ,
V_2 -> V_401 , V_395 ) ;
else if ( V_428 )
F_163 ( V_2 , V_38 , V_2 -> V_28 ,
L_29
L_33
L_34
L_35 ) ;
else
F_62 ( V_2 , V_38 , V_2 -> V_28 ,
L_29
L_36 ) ;
}
}
return V_18 ;
}
static int F_164 ( struct V_429 * V_430 )
{
return F_30 ( V_430 -> V_2 , & V_430 -> V_431 . V_62 ,
( V_430 -> V_346 + 1 ) *
sizeof( V_347 ) ,
V_70 ) ;
}
static void F_165 ( struct V_429 * V_430 )
{
F_8 ( V_48 ,
F_166 ( V_353 * 8 /
V_354 ) ) ;
struct V_122 * V_123 = F_167 ( V_430 ) ;
T_2 V_357 = V_430 -> V_431 . V_62 . V_358 / V_354 ;
struct V_1 * V_2 = V_430 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_359 ;
T_11 V_292 ;
int V_18 ;
int V_68 ;
F_13 ( V_432 != 0 ) ;
V_430 -> V_433 = 0 ;
V_430 -> V_434 = 0 ;
F_21 ( V_48 , V_435 , V_430 -> V_346 + 1 ) ;
F_21 ( V_48 , V_436 , V_123 -> V_123 ) ;
F_21 ( V_48 , V_437 , F_168 ( V_430 ) ) ;
F_21 ( V_48 , V_438 ,
F_168 ( V_430 ) ) ;
F_140 ( V_48 , V_439 ,
V_440 , 1 ,
V_441 , 1 ) ;
F_21 ( V_48 , V_442 , 0 ) ;
F_21 ( V_48 , V_443 , V_16 -> V_79 ) ;
V_292 = V_430 -> V_431 . V_62 . V_292 ;
F_41 ( V_2 , V_370 , V_2 -> V_28 , L_37 ,
F_168 ( V_430 ) , V_357 , ( T_7 ) V_292 ) ;
for ( V_68 = 0 ; V_68 < V_357 ; ++ V_68 ) {
F_141 ( V_48 , V_444 , V_68 , V_292 ) ;
V_292 += V_354 ;
}
V_359 = F_166 ( V_357 ) ;
V_18 = F_9 ( V_2 , V_445 , V_48 , V_359 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_144 ( V_2 -> V_28 , L_38 ,
F_168 ( V_430 ) ) ;
}
static void F_169 ( struct V_429 * V_430 )
{
F_8 ( V_48 , V_446 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_430 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_447 ,
F_168 ( V_430 ) ) ;
V_18 = F_51 ( V_2 , V_448 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_134;
return;
V_134:
F_52 ( V_2 , V_448 , V_446 ,
V_13 , V_17 , V_18 ) ;
}
static void F_170 ( struct V_429 * V_430 )
{
F_47 ( V_430 -> V_2 , & V_430 -> V_431 . V_62 ) ;
}
static inline void
F_171 ( struct V_429 * V_430 , unsigned int V_127 )
{
struct V_449 * V_450 ;
V_347 * V_431 ;
V_431 = F_172 ( V_430 , V_127 ) ;
V_450 = V_449 ( V_430 , V_127 ) ;
F_173 ( * V_431 ,
V_451 , V_450 -> V_358 ,
V_452 , V_450 -> V_292 ) ;
}
static void F_174 ( struct V_429 * V_430 )
{
struct V_1 * V_2 = V_430 -> V_2 ;
unsigned int V_349 ;
T_1 V_3 ;
V_349 = V_430 -> V_453 & ~ 7 ;
if ( V_430 -> V_454 == V_349 )
return;
do
F_171 (
V_430 ,
V_430 -> V_454 & V_430 -> V_346 ) ;
while ( ++ V_430 -> V_454 != V_349 );
F_121 () ;
F_148 ( V_3 , V_455 ,
V_349 & V_430 -> V_346 ) ;
F_114 ( V_2 , & V_3 , V_456 ,
F_168 ( V_430 ) ) ;
}
static void F_175 ( struct V_429 * V_430 )
{
struct V_122 * V_123 = F_167 ( V_430 ) ;
F_8 ( V_48 , V_457 ) ;
V_347 V_458 ;
F_173 ( V_458 ,
V_459 , V_460 ,
V_461 , V_462 ) ;
F_21 ( V_48 , V_463 , V_123 -> V_123 ) ;
memcpy ( F_19 ( V_48 , V_464 ) , & V_458 . T_7 [ 0 ] ,
sizeof( V_347 ) ) ;
F_176 ( V_123 -> V_2 , V_465 ,
V_48 , sizeof( V_48 ) , 0 ,
V_466 , 0 ) ;
}
static void
V_466 ( struct V_1 * V_2 , unsigned long V_467 ,
int V_18 , T_1 * V_13 ,
T_2 V_468 )
{
}
static int F_177 ( struct V_122 * V_123 )
{
return F_30 ( V_123 -> V_2 , & V_123 -> V_469 . V_62 ,
( V_123 -> V_470 + 1 ) *
sizeof( V_347 ) ,
V_70 ) ;
}
static int F_178 ( struct V_122 * V_123 )
{
F_8 ( V_48 ,
F_179 ( V_471 * 8 /
V_354 ) ) ;
F_8 ( V_13 , V_472 ) ;
T_2 V_357 = V_123 -> V_469 . V_62 . V_358 / V_354 ;
struct V_1 * V_2 = V_123 -> V_2 ;
struct V_15 * V_16 ;
bool V_473 ;
T_2 V_359 , V_17 ;
T_11 V_292 ;
int V_18 ;
int V_68 ;
V_16 = V_2 -> V_16 ;
V_473 =
! ! ( V_16 -> V_29 &
1 << V_474 ) ;
memset ( V_123 -> V_469 . V_62 . V_275 , 0xff , V_123 -> V_469 . V_62 . V_358 ) ;
F_21 ( V_48 , V_475 , V_123 -> V_470 + 1 ) ;
F_21 ( V_48 , V_476 , V_123 -> V_123 ) ;
F_21 ( V_48 , V_477 , V_123 -> V_123 ) ;
F_180 ( V_48 , V_478 ,
V_479 , 1 ,
V_480 , 1 ,
V_481 , 1 ,
V_482 , ! V_473 ) ;
F_21 ( V_48 , V_483 ,
V_484 ) ;
F_21 ( V_48 , V_485 , 0 ) ;
F_21 ( V_48 , V_486 , 0 ) ;
F_21 ( V_48 , V_487 ,
V_488 ) ;
F_21 ( V_48 , V_489 , 0 ) ;
V_292 = V_123 -> V_469 . V_62 . V_292 ;
for ( V_68 = 0 ; V_68 < V_357 ; ++ V_68 ) {
F_141 ( V_48 , V_490 , V_68 , V_292 ) ;
V_292 += V_354 ;
}
V_359 = F_179 ( V_357 ) ;
V_18 = F_9 ( V_2 , V_491 , V_48 , V_359 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
return V_18 ;
}
static void F_181 ( struct V_122 * V_123 )
{
F_8 ( V_48 , V_492 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_123 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_493 , V_123 -> V_123 ) ;
V_18 = F_51 ( V_2 , V_494 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_108 )
goto V_134;
return;
V_134:
F_52 ( V_2 , V_494 , V_492 ,
V_13 , V_17 , V_18 ) ;
}
static void F_182 ( struct V_122 * V_123 )
{
F_47 ( V_123 -> V_2 , & V_123 -> V_469 . V_62 ) ;
}
static void F_183 ( struct V_429 * V_430 ,
unsigned int V_495 )
{
struct V_1 * V_2 = V_430 -> V_2 ;
F_62 ( V_2 , V_370 , V_2 -> V_28 ,
L_39 ,
F_168 ( V_430 ) , V_495 ) ;
F_184 ( V_2 , V_496 ) ;
}
static void
F_185 ( struct V_429 * V_430 ,
unsigned int V_497 , unsigned int V_498 )
{
unsigned int V_499 = ( V_497 - V_498 ) & V_430 -> V_346 ;
struct V_1 * V_2 = V_430 -> V_2 ;
F_62 ( V_2 , V_370 , V_2 -> V_28 ,
L_40 ,
V_499 , V_497 , V_498 ) ;
F_184 ( V_2 , V_496 ) ;
}
static void F_186 ( struct V_429 * V_430 )
{
unsigned int V_500 ;
F_41 ( V_430 -> V_2 , V_370 , V_430 -> V_2 -> V_28 ,
L_41 ,
V_430 -> V_433 ) ;
V_500 = V_430 -> V_501 & V_430 -> V_346 ;
F_187 ( V_430 , V_500 , V_430 -> V_433 ,
0 , V_502 ) ;
V_430 -> V_501 += V_430 -> V_433 ;
V_430 -> V_433 = 0 ;
V_430 -> V_434 = 0 ;
++ F_167 ( V_430 ) -> V_503 ;
}
static int F_188 ( struct V_122 * V_123 ,
const V_347 * V_458 )
{
unsigned int V_239 , V_504 , V_495 , V_505 ;
unsigned int V_506 , V_507 , V_68 ;
struct V_1 * V_2 = V_123 -> V_2 ;
struct V_429 * V_430 ;
bool V_508 ;
T_12 V_198 = 0 ;
if ( F_189 ( F_129 ( V_2 -> V_509 ) ) )
return 0 ;
V_239 = F_190 ( * V_458 , V_510 ) ;
V_504 = F_190 ( * V_458 , V_511 ) ;
V_495 = F_190 ( * V_458 , V_512 ) ;
V_505 = F_190 ( * V_458 , V_513 ) ;
V_508 = F_190 ( * V_458 , V_514 ) ;
if ( F_190 ( * V_458 , V_515 ) )
F_144 ( V_2 -> V_28 , L_42
V_516 L_25 ,
F_191 ( * V_458 ) ) ;
V_430 = F_192 ( V_123 ) ;
if ( F_189 ( V_495 != F_168 ( V_430 ) ) )
F_183 ( V_430 , V_495 ) ;
V_506 = ( ( V_504 - V_430 -> V_501 ) &
( ( 1 << V_517 ) - 1 ) ) ;
if ( V_506 != V_430 -> V_433 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_189 ( V_506 == V_430 -> V_433 ) ) {
if ( V_430 -> V_433 == 0 || V_239 != 0 )
F_144 ( V_2 -> V_28 ,
L_43
V_516 L_25 ,
V_430 -> V_433 ,
F_191 ( * V_458 ) ) ;
F_186 ( V_430 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_29 &
( 1 << V_474 ) ) ||
V_430 -> V_433 != 0 || V_508 ) {
F_185 (
V_430 , V_504 ,
( V_430 -> V_501 +
V_430 -> V_433 + 1 ) &
( ( 1 << V_517 ) - 1 ) ) ;
return 0 ;
}
V_430 -> V_433 = 1 ;
V_430 -> V_434 = 0 ;
V_507 = V_506 ;
++ V_123 -> V_518 ;
V_123 -> V_519 += V_507 ;
V_198 |= V_520 ;
} else {
++ V_430 -> V_433 ;
V_430 -> V_434 += V_239 ;
if ( V_508 )
return 0 ;
V_507 = 1 ;
}
if ( F_189 ( F_190 ( * V_458 , V_521 ) ) )
V_198 |= V_502 ;
if ( F_189 ( F_190 ( * V_458 , V_522 ) ) ) {
V_123 -> V_523 += V_507 ;
} else if ( F_189 ( F_190 ( * V_458 ,
V_524 ) ) ) {
V_123 -> V_525 += V_507 ;
} else if ( V_505 == V_526 ||
V_505 == V_527 ) {
V_198 |= V_528 ;
}
if ( V_505 == V_526 )
V_198 |= V_529 ;
V_123 -> V_530 += 2 * V_507 ;
for ( V_68 = 0 ; V_68 < V_507 ; V_68 ++ ) {
F_187 ( V_430 ,
V_430 -> V_501 & V_430 -> V_346 ,
V_430 -> V_433 , V_430 -> V_434 ,
V_198 ) ;
V_430 -> V_501 += V_430 -> V_433 ;
}
V_430 -> V_433 = 0 ;
V_430 -> V_434 = 0 ;
return V_507 ;
}
static int
F_193 ( struct V_122 * V_123 , V_347 * V_458 )
{
struct V_1 * V_2 = V_123 -> V_2 ;
struct V_124 * V_125 ;
unsigned int V_531 ;
unsigned int V_532 ;
int V_533 = 0 ;
if ( F_189 ( F_129 ( V_2 -> V_509 ) ) )
return 0 ;
if ( F_189 ( F_190 ( * V_458 , V_534 ) ) )
return 0 ;
V_531 = F_190 ( * V_458 , V_535 ) ;
V_532 = F_190 ( * V_458 , V_536 ) ;
V_125 = F_194 ( V_123 ,
V_532 % V_185 ) ;
V_533 = ( ( V_531 + 1 - V_125 -> V_537 ) &
V_125 -> V_346 ) ;
F_195 ( V_125 , V_531 & V_125 -> V_346 ) ;
return V_533 ;
}
static void
F_196 ( struct V_122 * V_123 , V_347 * V_458 )
{
struct V_1 * V_2 = V_123 -> V_2 ;
int V_538 ;
V_538 = F_190 ( * V_458 , V_539 ) ;
switch ( V_538 ) {
case V_540 :
case V_541 :
break;
case V_542 :
break;
default:
F_14 ( V_2 , V_370 , V_2 -> V_28 ,
L_44
L_45 V_516 L_46 ,
V_123 -> V_123 , V_538 ,
F_191 ( * V_458 ) ) ;
}
}
static void F_197 ( struct V_122 * V_123 ,
V_347 * V_458 )
{
struct V_1 * V_2 = V_123 -> V_2 ;
T_6 V_538 ;
V_538 = F_190 ( * V_458 , V_543 ) ;
switch ( V_538 ) {
case V_544 :
V_123 -> V_545 = F_127 () ;
break;
case V_462 :
F_198 ( & V_123 -> V_430 , true ) ;
break;
default:
F_14 ( V_2 , V_370 , V_2 -> V_28 ,
L_47
L_45 V_516 L_46 ,
V_123 -> V_123 , ( unsigned ) V_538 ,
F_191 ( * V_458 ) ) ;
}
}
static int F_199 ( struct V_122 * V_123 , int V_546 )
{
struct V_1 * V_2 = V_123 -> V_2 ;
V_347 V_458 , * V_547 ;
unsigned int V_548 ;
int V_549 ;
int V_533 = 0 ;
int V_550 = 0 ;
if ( V_546 <= 0 )
return V_550 ;
V_548 = V_123 -> V_551 ;
for (; ; ) {
V_547 = F_200 ( V_123 , V_548 ) ;
V_458 = * V_547 ;
if ( ! F_201 ( & V_458 ) )
break;
F_202 ( * V_547 ) ;
++ V_548 ;
V_549 = F_190 ( V_458 , V_459 ) ;
F_126 ( V_2 , V_27 , V_2 -> V_28 ,
L_48 V_516 L_25 ,
V_123 -> V_123 , F_191 ( V_458 ) ) ;
switch ( V_549 ) {
case V_552 :
F_203 ( V_123 , & V_458 ) ;
break;
case V_553 :
V_550 += F_188 ( V_123 , & V_458 ) ;
if ( V_550 >= V_546 ) {
V_550 = V_546 ;
goto V_299;
}
break;
case V_554 :
V_533 += F_193 ( V_123 , & V_458 ) ;
if ( V_533 > V_2 -> V_555 ) {
V_550 = V_546 ;
goto V_299;
} else if ( ++ V_550 == V_546 ) {
goto V_299;
}
break;
case V_556 :
F_196 ( V_123 , & V_458 ) ;
if ( ++ V_550 == V_546 )
goto V_299;
break;
case V_460 :
F_197 ( V_123 , & V_458 ) ;
break;
default:
F_14 ( V_2 , V_370 , V_2 -> V_28 ,
L_49
L_45 V_516 L_46 ,
V_123 -> V_123 , V_549 ,
F_191 ( V_458 ) ) ;
}
}
V_299:
V_123 -> V_551 = V_548 ;
return V_550 ;
}
static void F_204 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = V_123 -> V_2 ;
T_1 V_557 ;
if ( F_112 ( V_2 ) ) {
F_13 ( V_558 <
( 1 << V_559 ) ) ;
F_13 ( V_471 >
( 1 << 2 * V_559 ) ) ;
F_115 ( V_557 , V_560 ,
V_561 ,
V_562 ,
( V_123 -> V_551 &
V_123 -> V_470 ) >>
V_559 ) ;
F_114 ( V_2 , & V_557 , V_308 ,
V_123 -> V_123 ) ;
F_115 ( V_557 , V_560 ,
V_563 ,
V_562 ,
V_123 -> V_551 &
( ( 1 << V_559 ) - 1 ) ) ;
F_114 ( V_2 , & V_557 , V_308 ,
V_123 -> V_123 ) ;
} else {
F_148 ( V_557 , V_564 ,
V_123 -> V_551 &
V_123 -> V_470 ) ;
F_114 ( V_2 , & V_557 , V_565 , V_123 -> V_123 ) ;
}
}
static void F_205 ( struct V_122 * V_123 )
{
F_8 ( V_48 , V_457 ) ;
struct V_1 * V_2 = V_123 -> V_2 ;
V_347 V_458 ;
int V_18 ;
F_173 ( V_458 ,
V_459 , V_460 ,
V_461 , V_544 ) ;
F_21 ( V_48 , V_463 , V_123 -> V_123 ) ;
memcpy ( F_19 ( V_48 , V_464 ) , & V_458 . T_7 [ 0 ] ,
sizeof( V_347 ) ) ;
V_18 = F_9 ( V_2 , V_465 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_134;
return;
V_134:
F_22 ( true ) ;
F_14 ( V_2 , V_370 , V_2 -> V_28 , L_28 , V_426 , V_18 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
if ( F_207 ( & V_2 -> V_298 ) )
F_208 ( & V_2 -> V_566 ) ;
F_22 ( F_108 ( & V_2 -> V_298 ) < 0 ) ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
struct V_429 * V_430 ;
int V_567 ;
if ( V_16 -> V_190 ) {
F_210 ( & V_2 -> V_298 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_568 != V_569 ) {
F_58 (channel, efx) {
F_211 (rx_queue, channel)
F_169 ( V_430 ) ;
F_59 (tx_queue, channel)
F_145 ( V_125 ) ;
}
F_212 ( V_2 -> V_566 ,
F_108 ( & V_2 -> V_298 ) == 0 ,
F_213 ( V_570 ) ) ;
V_567 = F_108 ( & V_2 -> V_298 ) ;
if ( V_567 ) {
F_14 ( V_2 , V_370 , V_2 -> V_28 , L_50 ,
V_567 ) ;
return - V_571 ;
}
}
return 0 ;
}
static void F_214 ( struct V_1 * V_2 )
{
F_210 ( & V_2 -> V_298 , 0 ) ;
}
static bool F_215 ( const struct V_572 * V_573 ,
const struct V_572 * V_574 )
{
if ( ( V_573 -> V_575 ^ V_574 -> V_575 ) |
( ( V_573 -> V_198 ^ V_574 -> V_198 ) &
( V_576 | V_577 ) ) )
return false ;
return memcmp ( & V_573 -> V_578 , & V_574 -> V_578 ,
sizeof( struct V_572 ) -
F_216 ( struct V_572 , V_578 ) ) == 0 ;
}
static unsigned int F_217 ( const struct V_572 * V_579 )
{
F_13 ( F_216 ( struct V_572 , V_578 ) & 3 ) ;
return F_218 ( ( const T_6 * ) & V_579 -> V_578 ,
( sizeof( struct V_572 ) -
F_216 ( struct V_572 , V_578 ) ) / 4 ,
0 ) ;
}
static bool F_219 ( const struct V_572 * V_579 )
{
if ( V_579 -> V_575 & V_580 &&
! F_220 ( V_579 -> V_581 ) )
return true ;
if ( ( V_579 -> V_575 &
( V_582 | V_583 ) ) ==
( V_582 | V_583 ) ) {
if ( V_579 -> V_584 == F_221 ( V_585 ) &&
! F_222 ( V_579 -> V_586 [ 0 ] ) )
return true ;
if ( V_579 -> V_584 == F_221 ( V_587 ) &&
( ( const T_3 * ) V_579 -> V_586 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_572 *
F_223 ( const struct V_588 * V_589 ,
unsigned int V_590 )
{
return (struct V_572 * ) ( V_589 -> V_591 [ V_590 ] . V_579 &
~ V_592 ) ;
}
static unsigned int
F_224 ( const struct V_588 * V_589 ,
unsigned int V_590 )
{
return V_589 -> V_591 [ V_590 ] . V_579 & V_592 ;
}
static void
F_225 ( struct V_588 * V_589 ,
unsigned int V_590 ,
const struct V_572 * V_579 ,
unsigned int V_198 )
{
V_589 -> V_591 [ V_590 ] . V_579 = ( unsigned long ) V_579 | V_198 ;
}
static void F_226 ( struct V_1 * V_2 ,
const struct V_572 * V_579 ,
T_1 * V_48 , T_7 V_593 ,
bool V_594 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
memset ( V_48 , 0 , V_595 ) ;
if ( V_594 ) {
F_21 ( V_48 , V_596 ,
V_597 ) ;
F_106 ( V_48 , V_598 , V_593 ) ;
} else {
T_6 V_599 = 0 ;
F_21 ( V_48 , V_596 ,
F_219 ( V_579 ) ?
V_600 :
V_601 ) ;
if ( V_579 -> V_575 & V_602 )
V_599 |=
F_220 ( V_579 -> V_581 ) ?
1 << V_603 :
1 << V_604 ;
#define F_227 ( T_13 , T_14 , T_15 ) \
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
F_227 ( V_605 , V_606 , V_607 ) ;
F_227 ( V_608 , V_586 , V_609 ) ;
F_227 ( V_610 , V_611 , V_612 ) ;
F_227 ( V_613 , V_614 , V_615 ) ;
F_227 ( V_616 , V_581 , V_617 ) ;
F_227 ( V_618 , V_619 , V_620 ) ;
F_227 ( V_621 , V_584 , V_621 ) ;
F_227 ( V_622 , V_623 , V_624 ) ;
F_227 ( V_625 , V_578 , V_626 ) ;
F_227 ( V_627 , V_628 , V_627 ) ;
#undef F_227
F_21 ( V_48 , V_629 ,
V_599 ) ;
}
F_21 ( V_48 , V_630 , V_16 -> V_79 ) ;
F_21 ( V_48 , V_631 ,
V_579 -> V_632 == V_633 ?
V_634 :
V_635 ) ;
F_21 ( V_48 , V_636 , 0 ) ;
F_21 ( V_48 , V_637 ,
V_638 ) ;
F_21 ( V_48 , V_639 ,
V_579 -> V_632 == V_633 ?
0 : V_579 -> V_632 ) ;
F_21 ( V_48 , V_640 ,
( V_579 -> V_198 & V_641 ) ?
V_642 :
V_643 ) ;
if ( V_579 -> V_198 & V_641 )
F_21 ( V_48 , V_644 ,
V_579 -> V_645 !=
V_646 ?
V_579 -> V_645 : V_16 -> V_77 ) ;
}
static int F_228 ( struct V_1 * V_2 ,
const struct V_572 * V_579 ,
T_7 * V_593 , bool V_594 )
{
F_8 ( V_48 , V_595 ) ;
F_8 ( V_13 , V_647 ) ;
int V_18 ;
F_226 ( V_2 , V_579 , V_48 , * V_593 , V_594 ) ;
V_18 = F_9 ( V_2 , V_648 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_593 = F_229 ( V_13 , V_649 ) ;
if ( V_18 == - V_650 )
V_18 = - V_168 ;
return V_18 ;
}
static int F_230 ( struct V_588 * V_589 ,
enum V_651 V_575 )
{
unsigned int V_652 ;
for ( V_652 = 0 ;
V_652 < V_589 -> V_653 ;
V_652 ++ )
if ( V_589 -> V_654 [ V_652 ] == V_575 )
return V_652 ;
return - V_655 ;
}
static T_16 F_231 ( struct V_1 * V_2 ,
struct V_572 * V_579 ,
bool V_656 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
F_90 ( V_658 , V_659 ) ;
struct V_572 * V_660 ;
unsigned int V_652 , V_661 ;
unsigned int V_662 ;
bool V_594 = false ;
int V_663 = - 1 ;
F_232 ( V_664 ) ;
bool V_665 ;
T_16 V_18 ;
if ( ( V_579 -> V_198 & ( V_576 | V_577 ) ) !=
V_576 )
return - V_209 ;
V_18 = F_230 ( V_589 , V_579 -> V_575 ) ;
if ( V_18 < 0 )
return V_18 ;
V_652 = V_18 ;
V_661 = F_217 ( V_579 ) ;
V_665 = F_233 ( V_579 ) ;
if ( V_665 )
F_234 ( V_658 , V_659 ) ;
for (; ; ) {
unsigned int V_666 = 1 ;
unsigned int V_68 ;
F_105 ( & V_2 -> V_667 ) ;
for (; ; ) {
V_68 = ( V_661 + V_666 ) & ( V_668 - 1 ) ;
V_660 = F_223 ( V_589 , V_68 ) ;
if ( ! V_660 ) {
if ( V_663 < 0 )
V_663 = V_68 ;
} else if ( F_215 ( V_579 , V_660 ) ) {
if ( V_589 -> V_591 [ V_68 ] . V_579 &
V_669 )
break;
if ( V_579 -> V_670 < V_660 -> V_670 &&
V_579 -> V_670 != V_671 ) {
V_18 = - V_97 ;
goto V_672;
}
if ( ! V_665 ) {
if ( V_579 -> V_670 ==
V_660 -> V_670 &&
! V_656 ) {
V_18 = - V_673 ;
goto V_672;
}
V_663 = V_68 ;
goto V_674;
} else if ( V_579 -> V_670 >
V_660 -> V_670 ||
( V_579 -> V_670 ==
V_660 -> V_670 &&
V_656 ) ) {
if ( V_663 < 0 )
V_663 = V_68 ;
else
F_235 ( V_666 , V_658 ) ;
}
}
if ( V_666 == V_659 ) {
if ( V_663 < 0 ) {
V_18 = - V_168 ;
goto V_672;
}
goto V_674;
}
++ V_666 ;
}
F_236 ( & V_589 -> V_675 , & V_664 , V_676 ) ;
F_103 ( & V_2 -> V_667 ) ;
F_237 () ;
}
V_674:
V_660 = F_223 ( V_589 , V_663 ) ;
if ( V_660 ) {
if ( V_579 -> V_670 == V_671 &&
V_660 -> V_670 >= V_671 ) {
if ( V_660 -> V_670 > V_671 )
V_660 -> V_198 |= V_677 ;
V_589 -> V_591 [ V_663 ] . V_579 &=
~ V_678 ;
V_18 = V_663 ;
goto V_672;
}
V_594 = true ;
V_662 = F_224 ( V_589 , V_663 ) ;
} else {
V_660 = F_238 ( sizeof( * V_579 ) , V_290 ) ;
if ( ! V_660 ) {
V_18 = - V_71 ;
goto V_672;
}
* V_660 = * V_579 ;
V_662 = 0 ;
}
F_225 ( V_589 , V_663 , V_660 ,
V_662 | V_669 ) ;
if ( V_665 ) {
unsigned int V_666 , V_68 ;
for ( V_666 = 0 ; V_666 < V_659 ; V_666 ++ ) {
V_68 = ( V_661 + V_666 ) & ( V_668 - 1 ) ;
if ( F_239 ( V_666 , V_658 ) )
V_589 -> V_591 [ V_68 ] . V_579 |=
V_669 ;
}
}
F_103 ( & V_2 -> V_667 ) ;
V_18 = F_228 ( V_2 , V_579 , & V_589 -> V_591 [ V_663 ] . V_593 ,
V_594 ) ;
F_105 ( & V_2 -> V_667 ) ;
if ( V_18 == 0 ) {
if ( V_594 ) {
if ( V_660 -> V_670 == V_671 )
V_660 -> V_198 |=
V_677 ;
V_660 -> V_670 = V_579 -> V_670 ;
V_660 -> V_198 &= V_677 ;
V_660 -> V_198 |= V_579 -> V_198 ;
V_660 -> V_645 = V_579 -> V_645 ;
V_660 -> V_632 = V_579 -> V_632 ;
}
} else if ( ! V_594 ) {
F_48 ( V_660 ) ;
V_660 = NULL ;
}
F_225 ( V_589 , V_663 , V_660 , V_662 ) ;
if ( V_665 ) {
F_8 ( V_48 , V_595 ) ;
unsigned int V_666 , V_68 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
for ( V_666 = 0 ; V_666 < V_659 ; V_666 ++ ) {
if ( ! F_239 ( V_666 , V_658 ) )
continue;
V_68 = ( V_661 + V_666 ) & ( V_668 - 1 ) ;
V_660 = F_223 ( V_589 , V_68 ) ;
V_662 = F_224 ( V_589 , V_68 ) ;
if ( V_18 == 0 ) {
F_103 ( & V_2 -> V_667 ) ;
F_21 ( V_48 , V_596 ,
V_679 ) ;
F_106 ( V_48 , V_598 ,
V_589 -> V_591 [ V_68 ] . V_593 ) ;
V_18 = F_9 ( V_2 , V_648 ,
V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_667 ) ;
}
if ( V_18 == 0 ) {
F_48 ( V_660 ) ;
V_660 = NULL ;
V_662 = 0 ;
} else {
V_662 &= ~ V_669 ;
}
F_225 ( V_589 , V_68 , V_660 ,
V_662 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_652 * V_668 + V_663 ;
F_240 ( & V_589 -> V_675 ) ;
V_672:
F_103 ( & V_2 -> V_667 ) ;
F_241 ( & V_589 -> V_675 , & V_664 ) ;
return V_18 ;
}
static void F_242 ( struct V_1 * V_2 )
{
}
static int F_243 ( struct V_1 * V_2 ,
unsigned int V_680 ,
T_6 V_681 , bool V_682 )
{
unsigned int V_590 = V_681 % V_668 ;
struct V_588 * V_589 = V_2 -> V_657 ;
F_8 ( V_48 ,
V_683 +
V_684 ) ;
struct V_572 * V_579 ;
F_232 ( V_664 ) ;
int V_18 ;
for (; ; ) {
F_105 ( & V_2 -> V_667 ) ;
if ( ! ( V_589 -> V_591 [ V_590 ] . V_579 &
V_669 ) )
break;
F_236 ( & V_589 -> V_675 , & V_664 , V_676 ) ;
F_103 ( & V_2 -> V_667 ) ;
F_237 () ;
}
V_579 = F_223 ( V_589 , V_590 ) ;
if ( ! V_579 ||
( ! V_682 &&
F_230 ( V_589 , V_579 -> V_575 ) !=
V_681 / V_668 ) ) {
V_18 = - V_101 ;
goto V_672;
}
if ( V_579 -> V_198 & V_677 &&
V_680 == ( 1U << V_671 ) ) {
V_579 -> V_198 &= ~ V_677 ;
V_589 -> V_591 [ V_590 ] . V_579 &= ~ V_678 ;
V_18 = 0 ;
goto V_672;
}
if ( ! ( V_680 & ( 1U << V_579 -> V_670 ) ) ) {
V_18 = - V_101 ;
goto V_672;
}
V_589 -> V_591 [ V_590 ] . V_579 |= V_669 ;
F_103 ( & V_2 -> V_667 ) ;
if ( V_579 -> V_198 & V_677 ) {
struct V_572 V_685 = * V_579 ;
V_685 . V_670 = V_671 ;
V_685 . V_198 = ( V_576 |
V_641 ) ;
V_685 . V_632 = 0 ;
V_685 . V_645 = V_646 ;
V_18 = F_228 ( V_2 , & V_685 ,
& V_589 -> V_591 [ V_590 ] . V_593 ,
true ) ;
F_105 ( & V_2 -> V_667 ) ;
if ( V_18 == 0 )
* V_579 = V_685 ;
} else {
F_21 ( V_48 , V_596 ,
F_219 ( V_579 ) ?
V_686 :
V_679 ) ;
F_106 ( V_48 , V_598 ,
V_589 -> V_591 [ V_590 ] . V_593 ) ;
V_18 = F_9 ( V_2 , V_648 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_667 ) ;
if ( V_18 == 0 ) {
F_48 ( V_579 ) ;
F_225 ( V_589 , V_590 , NULL , 0 ) ;
}
}
V_589 -> V_591 [ V_590 ] . V_579 &= ~ V_669 ;
F_240 ( & V_589 -> V_675 ) ;
V_672:
F_103 ( & V_2 -> V_667 ) ;
F_241 ( & V_589 -> V_675 , & V_664 ) ;
return V_18 ;
}
static int F_244 ( struct V_1 * V_2 ,
enum V_687 V_670 ,
T_6 V_681 )
{
return F_243 ( V_2 , 1U << V_670 ,
V_681 , false ) ;
}
static int F_245 ( struct V_1 * V_2 ,
enum V_687 V_670 ,
T_6 V_681 , struct V_572 * V_579 )
{
unsigned int V_590 = V_681 % V_668 ;
struct V_588 * V_589 = V_2 -> V_657 ;
const struct V_572 * V_660 ;
int V_18 ;
F_105 ( & V_2 -> V_667 ) ;
V_660 = F_223 ( V_589 , V_590 ) ;
if ( V_660 && V_660 -> V_670 == V_670 &&
F_230 ( V_589 , V_660 -> V_575 ) ==
V_681 / V_668 ) {
* V_579 = * V_660 ;
V_18 = 0 ;
} else {
V_18 = - V_101 ;
}
F_103 ( & V_2 -> V_667 ) ;
return V_18 ;
}
static int F_246 ( struct V_1 * V_2 ,
enum V_687 V_670 )
{
unsigned int V_680 ;
unsigned int V_68 ;
int V_18 ;
V_680 = ( ( ( 1U << ( V_670 + 1 ) ) - 1 ) &
~ ( 1U << V_671 ) ) ;
for ( V_68 = 0 ; V_68 < V_668 ; V_68 ++ ) {
V_18 = F_243 ( V_2 , V_680 ,
V_68 , true ) ;
if ( V_18 && V_18 != - V_101 )
return V_18 ;
}
return 0 ;
}
static T_6 F_247 ( struct V_1 * V_2 ,
enum V_687 V_670 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
unsigned int V_590 ;
T_16 V_688 = 0 ;
F_105 ( & V_2 -> V_667 ) ;
for ( V_590 = 0 ; V_590 < V_668 ; V_590 ++ ) {
if ( V_589 -> V_591 [ V_590 ] . V_579 &&
F_223 ( V_589 , V_590 ) -> V_670 ==
V_670 )
++ V_688 ;
}
F_103 ( & V_2 -> V_667 ) ;
return V_688 ;
}
static T_6 F_248 ( struct V_1 * V_2 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
return V_589 -> V_653 * V_668 ;
}
static T_16 F_249 ( struct V_1 * V_2 ,
enum V_687 V_670 ,
T_6 * V_62 , T_6 V_689 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
struct V_572 * V_579 ;
unsigned int V_590 ;
T_16 V_688 = 0 ;
F_105 ( & V_2 -> V_667 ) ;
for ( V_590 = 0 ; V_590 < V_668 ; V_590 ++ ) {
V_579 = F_223 ( V_589 , V_590 ) ;
if ( V_579 && V_579 -> V_670 == V_670 ) {
if ( V_688 == V_689 ) {
V_688 = - V_690 ;
break;
}
V_62 [ V_688 ++ ] = ( F_230 (
V_589 , V_579 -> V_575 ) *
V_668 +
V_590 ) ;
}
}
F_103 ( & V_2 -> V_667 ) ;
return V_688 ;
}
static T_16 F_250 ( struct V_1 * V_2 ,
struct V_572 * V_579 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
F_8 ( V_48 , V_595 ) ;
struct V_572 * V_660 ;
unsigned int V_661 , V_68 , V_666 = 1 ;
bool V_594 = false ;
int V_663 = - 1 ;
T_7 V_467 ;
T_16 V_18 ;
F_251 ( V_579 -> V_198 !=
( V_576 | V_691 ) ) ;
F_251 ( V_579 -> V_670 != V_692 ) ;
F_251 ( F_233 ( V_579 ) ) ;
V_661 = F_217 ( V_579 ) ;
F_105 ( & V_2 -> V_667 ) ;
for (; ; ) {
V_68 = ( V_661 + V_666 ) & ( V_668 - 1 ) ;
V_660 = F_223 ( V_589 , V_68 ) ;
if ( ! V_660 ) {
if ( V_663 < 0 )
V_663 = V_68 ;
} else if ( F_215 ( V_579 , V_660 ) ) {
if ( V_589 -> V_591 [ V_68 ] . V_579 & V_669 ) {
V_18 = - V_168 ;
goto V_693;
}
if ( V_579 -> V_670 < V_660 -> V_670 ) {
V_18 = - V_97 ;
goto V_693;
}
V_663 = V_68 ;
break;
}
if ( V_666 == V_659 ) {
if ( V_663 < 0 ) {
V_18 = - V_168 ;
goto V_693;
}
break;
}
++ V_666 ;
}
V_660 = F_223 ( V_589 , V_663 ) ;
if ( V_660 ) {
V_594 = true ;
} else {
V_660 = F_238 ( sizeof( * V_579 ) , V_290 ) ;
if ( ! V_660 ) {
V_18 = - V_71 ;
goto V_693;
}
* V_660 = * V_579 ;
}
F_225 ( V_589 , V_663 , V_660 ,
V_669 ) ;
F_103 ( & V_2 -> V_667 ) ;
V_467 = V_594 << 31 | V_663 << 16 | V_579 -> V_632 ;
F_226 ( V_2 , V_579 , V_48 ,
V_589 -> V_591 [ V_663 ] . V_593 , V_594 ) ;
F_176 ( V_2 , V_648 , V_48 , sizeof( V_48 ) ,
V_647 ,
V_694 , V_467 ) ;
return V_663 ;
V_693:
F_103 ( & V_2 -> V_667 ) ;
return V_18 ;
}
static void
V_694 ( struct V_1 * V_2 , unsigned long V_467 ,
int V_18 , T_1 * V_13 ,
T_2 V_468 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
unsigned int V_663 , V_632 ;
struct V_572 * V_579 ;
bool V_594 ;
V_594 = V_467 >> 31 ;
V_663 = ( V_467 >> 16 ) & ( V_668 - 1 ) ;
V_632 = V_467 & 0xffff ;
F_105 ( & V_2 -> V_667 ) ;
V_579 = F_223 ( V_589 , V_663 ) ;
if ( V_18 == 0 ) {
V_589 -> V_591 [ V_663 ] . V_593 =
F_229 ( V_13 , V_649 ) ;
if ( V_594 )
V_579 -> V_632 = V_632 ;
} else if ( ! V_594 ) {
F_48 ( V_579 ) ;
V_579 = NULL ;
}
F_225 ( V_589 , V_663 , V_579 , 0 ) ;
F_103 ( & V_2 -> V_667 ) ;
F_240 ( & V_589 -> V_675 ) ;
}
static bool F_252 ( struct V_1 * V_2 , T_6 V_695 ,
unsigned int V_590 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
struct V_572 * V_579 =
F_223 ( V_589 , V_590 ) ;
F_8 ( V_48 ,
V_683 +
V_684 ) ;
if ( ! V_579 ||
( V_589 -> V_591 [ V_590 ] . V_579 & V_669 ) ||
V_579 -> V_670 != V_692 ||
! F_253 ( V_2 -> V_28 , V_579 -> V_632 ,
V_695 , V_590 ) )
return false ;
F_21 ( V_48 , V_596 ,
V_686 ) ;
F_106 ( V_48 , V_598 ,
V_589 -> V_591 [ V_590 ] . V_593 ) ;
if ( F_176 ( V_2 , V_648 , V_48 , sizeof( V_48 ) , 0 ,
V_696 , V_590 ) )
return false ;
V_589 -> V_591 [ V_590 ] . V_579 |= V_669 ;
return true ;
}
static void
V_696 ( struct V_1 * V_2 ,
unsigned long V_590 ,
int V_18 , T_1 * V_13 ,
T_2 V_468 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
struct V_572 * V_579 =
F_223 ( V_589 , V_590 ) ;
F_105 ( & V_2 -> V_667 ) ;
if ( V_18 == 0 ) {
F_48 ( V_579 ) ;
F_225 ( V_589 , V_590 , NULL , 0 ) ;
}
V_589 -> V_591 [ V_590 ] . V_579 &= ~ V_669 ;
F_240 ( & V_589 -> V_675 ) ;
F_103 ( & V_2 -> V_667 ) ;
}
static int F_254 ( T_6 V_697 )
{
int V_575 = 0 ;
#define F_255 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_255 ( V_698 , V_699 ) ;
F_255 ( V_698 , V_700 ) ;
F_255 ( V_605 , V_607 ) ;
F_255 ( V_608 , V_609 ) ;
F_255 ( V_610 , V_612 ) ;
F_255 ( V_613 , V_615 ) ;
F_255 ( V_616 , V_617 ) ;
F_255 ( V_618 , V_620 ) ;
F_255 ( V_621 , V_621 ) ;
F_255 ( V_622 , V_624 ) ;
F_255 ( V_625 , V_626 ) ;
F_255 ( V_627 , V_627 ) ;
#undef F_255
if ( V_697 )
return - V_209 ;
return V_575 ;
}
static int F_256 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_701 ) ;
F_8 ( V_13 , V_702 ) ;
unsigned int V_703 , V_704 ;
struct V_588 * V_589 ;
T_2 V_17 ;
int V_18 ;
V_589 = F_29 ( sizeof( * V_589 ) , V_70 ) ;
if ( ! V_589 )
return - V_71 ;
F_21 ( V_48 , V_705 ,
V_706 ) ;
V_18 = F_9 ( V_2 , V_707 ,
V_48 , sizeof( V_48 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_134;
V_704 = F_257 (
V_17 , V_708 ) ;
V_589 -> V_653 = 0 ;
for ( V_703 = 0 ; V_703 < V_704 ; V_703 ++ ) {
T_6 V_697 =
F_258 (
V_13 ,
V_708 ,
V_703 ) ;
V_18 = F_254 ( V_697 ) ;
if ( V_18 < 0 ) {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_51 ,
V_426 , V_697 , V_703 ) ;
} else {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_52 ,
V_426 , V_697 , V_703 ,
V_18 , V_589 -> V_653 ) ;
V_589 -> V_654 [ V_589 -> V_653 ++ ] = V_18 ;
}
}
V_589 -> V_591 = F_259 ( V_668 * sizeof( * V_589 -> V_591 ) ) ;
if ( ! V_589 -> V_591 ) {
V_18 = - V_71 ;
goto V_134;
}
V_2 -> V_657 = V_589 ;
F_260 ( & V_589 -> V_675 ) ;
return 0 ;
V_134:
F_48 ( V_589 ) ;
return V_18 ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_572 * V_579 ;
unsigned int V_590 ;
bool V_709 = false ;
int V_18 ;
F_22 ( ! F_262 ( & V_2 -> V_710 ) ) ;
if ( ! V_16 -> V_193 )
return;
if ( ! V_589 )
return;
F_105 ( & V_2 -> V_667 ) ;
for ( V_590 = 0 ; V_590 < V_668 ; V_590 ++ ) {
V_579 = F_223 ( V_589 , V_590 ) ;
if ( ! V_579 )
continue;
V_589 -> V_591 [ V_590 ] . V_579 |= V_669 ;
F_103 ( & V_2 -> V_667 ) ;
V_18 = F_228 ( V_2 , V_579 ,
& V_589 -> V_591 [ V_590 ] . V_593 ,
false ) ;
if ( V_18 )
V_709 = true ;
F_105 ( & V_2 -> V_667 ) ;
if ( V_18 ) {
F_48 ( V_579 ) ;
F_225 ( V_589 , V_590 , NULL , 0 ) ;
} else {
V_589 -> V_591 [ V_590 ] . V_579 &=
~ V_669 ;
}
}
F_103 ( & V_2 -> V_667 ) ;
if ( V_709 )
F_14 ( V_2 , V_370 , V_2 -> V_28 ,
L_53 ) ;
else
V_16 -> V_193 = false ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
F_8 ( V_48 , V_595 ) ;
struct V_572 * V_579 ;
unsigned int V_590 ;
int V_18 ;
V_2 -> V_657 = NULL ;
if ( ! V_589 )
return;
for ( V_590 = 0 ; V_590 < V_668 ; V_590 ++ ) {
V_579 = F_223 ( V_589 , V_590 ) ;
if ( ! V_579 )
continue;
F_21 ( V_48 , V_596 ,
F_219 ( V_579 ) ?
V_686 :
V_679 ) ;
F_106 ( V_48 , V_598 ,
V_589 -> V_591 [ V_590 ] . V_593 ) ;
V_18 = F_9 ( V_2 , V_648 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_144 ( V_2 -> V_28 ,
L_54 ,
V_590 ,
V_589 -> V_591 [ V_590 ] . V_593 ) ;
F_48 ( V_579 ) ;
}
F_264 ( V_589 -> V_591 ) ;
F_48 ( V_589 ) ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_588 * V_589 = V_2 -> V_657 ;
struct V_67 * V_28 = V_2 -> V_28 ;
struct V_572 V_579 ;
bool V_711 = false ;
struct V_712 * V_713 ;
struct V_712 * V_714 ;
unsigned int V_590 ;
int V_68 , V_115 , V_18 ;
if ( ! F_266 ( V_2 ) )
return;
if ( ! V_589 )
return;
F_105 ( & V_2 -> V_667 ) ;
V_115 = V_589 -> V_715 < 0 ? 1 : V_589 -> V_715 ;
for ( V_68 = 0 ; V_68 < V_115 ; V_68 ++ ) {
V_590 = V_589 -> V_716 [ V_68 ] . V_717 % V_668 ;
V_589 -> V_591 [ V_590 ] . V_579 |= V_678 ;
}
V_115 = V_589 -> V_718 < 0 ? 1 : V_589 -> V_718 ;
for ( V_68 = 0 ; V_68 < V_115 ; V_68 ++ ) {
V_590 = V_589 -> V_719 [ V_68 ] . V_717 % V_668 ;
V_589 -> V_591 [ V_590 ] . V_579 |= V_678 ;
}
F_103 ( & V_2 -> V_667 ) ;
F_267 ( V_28 ) ;
if ( V_28 -> V_198 & V_720 ||
F_268 ( V_28 ) >= V_721 ) {
V_589 -> V_715 = - 1 ;
} else {
V_589 -> V_715 = 1 + F_268 ( V_28 ) ;
F_18 ( V_589 -> V_716 [ 0 ] . V_275 , V_28 -> V_722 ) ;
V_68 = 1 ;
F_269 (uc, net_dev) {
F_18 ( V_589 -> V_716 [ V_68 ] . V_275 , V_713 -> V_275 ) ;
V_68 ++ ;
}
}
if ( V_28 -> V_198 & ( V_720 | V_723 ) ||
F_270 ( V_28 ) >= V_724 ) {
V_589 -> V_718 = - 1 ;
} else {
V_589 -> V_718 = 1 + F_270 ( V_28 ) ;
F_271 ( V_589 -> V_719 [ 0 ] . V_275 ) ;
V_68 = 1 ;
F_272 (mc, net_dev) {
F_18 ( V_589 -> V_719 [ V_68 ] . V_275 , V_714 -> V_275 ) ;
V_68 ++ ;
}
}
F_273 ( V_28 ) ;
if ( V_589 -> V_715 >= 0 ) {
for ( V_68 = 0 ; V_68 < V_589 -> V_715 ; V_68 ++ ) {
F_274 ( & V_579 , V_671 ,
V_641 ,
0 ) ;
F_275 ( & V_579 , V_725 ,
V_589 -> V_716 [ V_68 ] . V_275 ) ;
V_18 = F_231 ( V_2 , & V_579 , true ) ;
if ( V_18 < 0 ) {
while ( V_68 -- )
F_244 (
V_2 , V_671 ,
V_589 -> V_716 [ V_68 ] . V_717 ) ;
V_589 -> V_715 = - 1 ;
break;
}
V_589 -> V_716 [ V_68 ] . V_717 = V_18 ;
}
}
if ( V_589 -> V_715 < 0 ) {
F_274 ( & V_579 , V_671 ,
V_641 ,
0 ) ;
F_276 ( & V_579 ) ;
V_18 = F_231 ( V_2 , & V_579 , true ) ;
if ( V_18 < 0 ) {
F_22 ( 1 ) ;
V_589 -> V_715 = 0 ;
} else {
V_589 -> V_716 [ 0 ] . V_717 = V_18 ;
}
}
if ( V_589 -> V_718 >= 0 ) {
for ( V_68 = 0 ; V_68 < V_589 -> V_718 ; V_68 ++ ) {
F_274 ( & V_579 , V_671 ,
V_641 ,
0 ) ;
F_275 ( & V_579 , V_725 ,
V_589 -> V_719 [ V_68 ] . V_275 ) ;
V_18 = F_231 ( V_2 , & V_579 , true ) ;
if ( V_18 < 0 ) {
while ( V_68 -- )
F_244 (
V_2 , V_671 ,
V_589 -> V_719 [ V_68 ] . V_717 ) ;
V_589 -> V_718 = - 1 ;
break;
}
V_589 -> V_719 [ V_68 ] . V_717 = V_18 ;
}
}
if ( V_589 -> V_718 < 0 ) {
F_274 ( & V_579 , V_671 ,
V_641 ,
0 ) ;
F_277 ( & V_579 ) ;
V_18 = F_231 ( V_2 , & V_579 , true ) ;
if ( V_18 < 0 ) {
F_22 ( 1 ) ;
V_589 -> V_718 = 0 ;
} else {
V_589 -> V_719 [ 0 ] . V_717 = V_18 ;
}
}
for ( V_68 = 0 ; V_68 < V_668 ; V_68 ++ ) {
if ( F_129 ( V_589 -> V_591 [ V_68 ] . V_579 ) &
V_678 ) {
if ( F_243 (
V_2 , 1U << V_671 ,
V_68 , true ) < 0 )
V_711 = true ;
}
}
F_22 ( V_711 ) ;
}
static int F_278 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_726 [ V_727 ] ;
int V_18 , V_728 ;
if ( F_279 ( V_16 -> V_729 ) )
return 0 ;
F_280 ( V_2 ) ;
F_281 ( V_2 -> V_28 ) ;
F_282 ( & V_2 -> V_710 ) ;
F_263 ( V_2 ) ;
F_283 ( & V_2 -> V_710 ) ;
V_18 = F_69 ( V_2 , V_16 -> V_79 ) ;
if ( V_18 )
goto V_730;
F_18 ( V_726 , V_16 -> V_729 ) ;
V_18 = F_71 ( V_2 , V_16 -> V_79 ,
V_16 -> V_729 ) ;
if ( V_18 )
goto V_731;
V_18 = F_70 ( V_2 , V_16 -> V_79 ,
V_2 -> V_28 -> V_722 ) ;
if ( ! V_18 ) {
F_18 ( V_16 -> V_729 , V_2 -> V_28 -> V_722 ) ;
} else {
V_728 = F_70 ( V_2 , V_16 -> V_79 , V_726 ) ;
if ( V_728 ) {
F_284 ( V_16 -> V_729 ) ;
goto V_732;
}
}
V_731:
V_728 = F_68 ( V_2 , V_16 -> V_79 ) ;
if ( V_728 )
goto V_732;
V_730:
F_282 ( & V_2 -> V_710 ) ;
V_728 = F_256 ( V_2 ) ;
F_283 ( & V_2 -> V_710 ) ;
if ( V_728 )
goto V_732;
V_728 = F_285 ( V_2 -> V_28 ) ;
if ( V_728 )
goto V_732;
F_286 ( V_2 -> V_28 ) ;
return V_18 ;
V_732:
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_55 ) ;
F_184 ( V_2 , V_197 ) ;
return V_18 ? V_18 : V_728 ;
}
static int F_287 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_733 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_734 = V_2 -> V_735 ;
int V_18 ;
F_280 ( V_2 ) ;
F_281 ( V_2 -> V_28 ) ;
F_282 ( & V_2 -> V_710 ) ;
F_263 ( V_2 ) ;
F_18 ( F_19 ( V_48 , V_736 ) ,
V_2 -> V_28 -> V_722 ) ;
F_21 ( V_48 , V_737 ,
V_16 -> V_79 ) ;
V_18 = F_51 ( V_2 , V_738 , V_48 ,
sizeof( V_48 ) , NULL , 0 , NULL ) ;
F_256 ( V_2 ) ;
F_283 ( & V_2 -> V_710 ) ;
if ( V_734 )
F_285 ( V_2 -> V_28 ) ;
F_286 ( V_2 -> V_28 ) ;
#ifdef F_44
if ( V_2 -> V_10 -> V_150 && V_2 -> V_10 -> V_102 ) {
struct V_10 * V_104 = V_2 -> V_10 -> V_102 ;
if ( V_18 == - V_97 ) {
struct V_1 * V_105 ;
V_105 = F_24 ( V_104 ) ;
V_18 = F_288 ( V_105 ,
V_16 -> V_22 ,
V_2 -> V_28 -> V_722 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_105 = F_24 ( V_104 ) ;
struct V_15 * V_16 = V_105 -> V_16 ;
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_105 -> V_739 ; ++ V_68 ) {
struct V_148 * V_149 = V_16 -> V_149 + V_68 ;
if ( V_149 -> V_2 == V_2 ) {
F_18 ( V_149 -> V_159 ,
V_2 -> V_28 -> V_722 ) ;
return 0 ;
}
}
}
} else
#endif
if ( V_18 == - V_97 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_56
L_57 ) ;
} else if ( V_18 == - V_100 && ! F_6 ( V_2 ) ) {
V_18 = F_278 ( V_2 ) ;
} else {
F_52 ( V_2 , V_738 ,
sizeof( V_48 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_289 ( struct V_1 * V_2 )
{
F_265 ( V_2 ) ;
return F_290 ( V_2 ) ;
}
static int F_291 ( struct V_1 * V_2 )
{
F_265 ( V_2 ) ;
return 0 ;
}
static int F_292 ( struct V_1 * V_2 , T_6 V_740 )
{
F_8 ( V_48 , V_741 ) ;
F_21 ( V_48 , V_742 , V_740 ) ;
return F_9 ( V_2 , V_743 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
}
static int F_293 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_744 ) ;
T_2 V_17 ;
T_6 V_745 ;
V_18 = F_9 ( V_2 , V_746 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_744 )
return - V_7 ;
V_745 = F_10 ( V_13 , V_747 ) ;
switch ( V_745 ) {
case V_748 :
F_41 ( V_2 , V_370 , V_2 -> V_28 , L_58 ) ;
return 0 ;
case V_749 :
F_14 ( V_2 , V_370 , V_2 -> V_28 , L_59 ) ;
return - V_7 ;
case V_750 :
F_14 ( V_2 , V_370 , V_2 -> V_28 , L_60 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_370 , V_2 -> V_28 ,
L_61 , V_745 ) ;
return - V_7 ;
}
}
static int F_294 ( struct V_1 * V_2 , T_6 V_740 )
{
int V_18 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_62 , V_740 ) ;
V_18 = F_292 ( V_2 , V_740 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_293 ( V_2 ) ;
}
static int
F_295 ( struct V_1 * V_2 , struct V_751 * V_752 )
{
int V_18 , V_728 ;
F_296 ( V_2 , V_208 ) ;
V_18 = F_9 ( V_2 , V_753 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_299;
V_752 -> V_754 = F_294 ( V_2 , V_755 ) ? - 1 : 1 ;
V_752 -> V_756 = F_294 ( V_2 , V_757 ) ? - 1 : 1 ;
V_18 = F_35 ( V_2 , V_208 ) ;
V_299:
V_728 = F_297 ( V_2 , V_208 , V_18 == 0 ) ;
return V_18 ? V_18 : V_728 ;
}
static int F_298 ( struct V_1 * V_2 ,
struct V_758 * V_759 ,
unsigned int type )
{
F_8 ( V_48 , V_760 ) ;
F_8 ( V_13 , V_761 ) ;
const struct V_762 * V_763 ;
T_2 V_689 , V_764 , V_17 ;
bool V_765 ;
int V_18 ;
for ( V_763 = V_766 ; ; V_763 ++ ) {
if ( V_763 ==
V_766 + F_157 ( V_766 ) )
return - V_36 ;
if ( ( type & ~ V_763 -> V_767 ) == V_763 -> type )
break;
}
if ( V_763 -> V_768 != F_299 ( V_2 ) )
return - V_36 ;
V_18 = F_300 ( V_2 , type , & V_689 , & V_764 , & V_765 ) ;
if ( V_18 )
return V_18 ;
if ( V_765 )
return - V_36 ;
V_759 -> V_769 = type ;
F_21 ( V_48 , V_770 , type ) ;
V_18 = F_9 ( V_2 , V_771 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_772 )
return - V_7 ;
if ( F_10 ( V_13 , V_773 ) &
( 1 << V_774 ) )
V_759 -> V_775 = F_10 ( V_13 ,
V_776 ) ;
V_759 -> V_777 . V_778 = L_63 ;
V_759 -> V_777 . V_779 = V_763 -> V_231 ;
V_759 -> V_777 . V_780 . type = V_781 ;
V_759 -> V_777 . V_780 . V_198 = V_782 ;
V_759 -> V_777 . V_780 . V_689 = V_689 ;
V_759 -> V_777 . V_780 . V_783 = V_764 ;
return 0 ;
}
static int F_301 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_784 ) ;
struct V_758 * V_785 ;
T_2 V_17 , V_786 , V_68 , V_787 ;
unsigned int type ;
int V_18 ;
F_302 () ;
F_13 ( V_788 != 0 ) ;
V_18 = F_9 ( V_2 , V_789 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_790 )
return - V_7 ;
V_786 = F_10 ( V_13 , V_791 ) ;
if ( V_786 >
F_257 ( V_17 , V_792 ) )
return - V_7 ;
V_785 = F_303 ( V_786 , sizeof( * V_785 ) , V_70 ) ;
if ( ! V_785 )
return - V_71 ;
V_787 = 0 ;
for ( V_68 = 0 ; V_68 < V_786 ; V_68 ++ ) {
type = F_258 ( V_13 , V_792 ,
V_68 ) ;
V_18 = F_298 ( V_2 , & V_785 [ V_787 ] , type ) ;
if ( V_18 == 0 )
V_787 ++ ;
else if ( V_18 != - V_36 )
goto V_134;
}
V_18 = F_304 ( V_2 , & V_785 [ 0 ] . V_777 , V_787 , sizeof( * V_785 ) ) ;
V_134:
if ( V_18 )
F_48 ( V_785 ) ;
return V_18 ;
}
static void F_305 ( struct V_1 * V_2 , T_6 V_793 )
{
F_32 ( V_2 , F_33 ( V_793 ) , V_323 ) ;
}
static void F_306 ( struct V_1 * V_2 ,
T_6 V_793 ) {}
static int F_307 ( struct V_122 * V_123 ,
bool V_794 )
{
F_8 ( V_48 , V_795 ) ;
int V_18 ;
if ( V_123 -> V_796 == V_797 ||
V_123 -> V_796 == V_798 ||
( V_794 && V_123 -> V_796 == V_799 ) )
return 0 ;
V_123 -> V_796 = V_797 ;
F_21 ( V_48 , V_800 , V_801 ) ;
F_21 ( V_48 , V_802 , 0 ) ;
F_21 ( V_48 , V_803 ,
V_123 -> V_123 ) ;
V_18 = F_9 ( V_123 -> V_2 , V_804 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_123 -> V_796 = V_794 ? V_805 :
V_799 ;
return V_18 ;
}
static int F_308 ( struct V_122 * V_123 ,
bool V_794 )
{
F_8 ( V_48 , V_806 ) ;
int V_18 ;
if ( V_123 -> V_796 == V_799 ||
( V_794 && V_123 -> V_796 == V_805 ) )
return 0 ;
if ( V_123 -> V_796 == V_805 ) {
V_123 -> V_796 = V_799 ;
return 0 ;
}
V_123 -> V_796 = V_794 ? V_805 :
V_799 ;
F_21 ( V_48 , V_800 , V_807 ) ;
F_21 ( V_48 , V_802 , 0 ) ;
F_21 ( V_48 , V_808 ,
V_809 ) ;
F_21 ( V_48 , V_810 ,
V_123 -> V_123 ) ;
V_18 = F_9 ( V_123 -> V_2 , V_804 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_309 ( struct V_1 * V_2 , bool V_811 ,
bool V_794 )
{
int (* F_310)( struct V_122 * V_123 , bool V_794 );
struct V_122 * V_123 ;
F_310 = V_811 ?
F_307 :
F_308 ;
F_58 (channel, efx) {
int V_18 = F_310 ( V_123 , V_794 ) ;
if ( V_811 && V_18 != 0 ) {
F_309 ( V_2 , false , V_794 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_311 ( struct V_1 * V_2 ,
struct V_812 * V_813 )
{
return - V_314 ;
}
static int F_312 ( struct V_1 * V_2 ,
struct V_812 * V_813 )
{
int V_18 ;
switch ( V_813 -> V_814 ) {
case V_815 :
F_309 ( V_2 , false , false ) ;
return F_313 ( V_2 ,
V_813 -> V_816 != V_817 , 0 ) ;
case V_818 :
case V_819 :
case V_820 :
case V_821 :
case V_822 :
case V_823 :
case V_824 :
case V_825 :
case V_826 :
case V_827 :
case V_828 :
case V_829 :
case V_830 :
V_813 -> V_814 = V_818 ;
V_18 = F_313 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_309 ( V_2 , true , false ) ;
if ( V_18 )
F_313 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_42 ;
}
}
