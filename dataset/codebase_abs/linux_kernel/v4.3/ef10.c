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
V_2 -> V_69 = F_28 (unsigned int,
EFX_MAX_CHANNELS,
efx_ef10_mem_map_size(efx) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
V_2 -> V_70 = V_2 -> V_69 ;
if ( F_22 ( V_2 -> V_69 == 0 ) )
return - V_7 ;
V_16 = F_29 ( sizeof( * V_16 ) , V_71 ) ;
if ( ! V_16 )
return - V_72 ;
V_2 -> V_16 = V_16 ;
F_13 ( V_73 % 4 ) ;
V_18 = F_30 ( V_2 , & V_16 -> V_74 ,
8 + V_73 , V_71 ) ;
if ( V_18 )
goto V_75;
V_68 = 0 ;
for (; ; ) {
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 )
break;
if ( ++ V_68 == 5 )
goto V_76;
F_31 ( 1 ) ;
}
V_16 -> V_77 = V_18 ;
V_16 -> V_78 = V_79 ;
V_16 -> V_80 = V_53 ;
F_32 ( V_2 , F_33 ( 1 ) , V_81 ) ;
V_18 = F_34 ( V_2 ) ;
if ( V_18 )
goto V_76;
V_18 = F_35 ( V_2 , V_82 ) ;
if ( V_18 )
goto V_83;
V_18 = F_36 ( V_2 , true , false , 0 ) ;
if ( V_18 )
goto V_83;
V_18 = F_37 ( & V_2 -> V_10 -> V_59 ,
& V_84 ) ;
if ( V_18 )
goto V_83;
V_18 = F_37 ( & V_2 -> V_10 -> V_59 , & V_85 ) ;
if ( V_18 )
goto V_86;
V_18 = F_7 ( V_2 ) ;
if ( V_18 )
goto V_87;
V_18 = F_12 ( V_2 ) ;
if ( V_18 < 0 )
goto V_87;
V_2 -> V_88 =
V_89 - V_90 ;
V_18 = F_38 ( V_2 ) ;
if ( V_18 < 0 )
goto V_87;
V_2 -> V_91 = V_18 ;
V_28 -> V_92 = V_18 ;
V_18 = V_2 -> type -> V_93 ( V_2 , V_2 -> V_28 -> V_94 ) ;
if ( V_18 )
goto V_87;
V_18 = F_16 ( V_2 ) ;
if ( V_18 < 0 )
goto V_87;
V_2 -> V_95 = 1536000 / V_18 ;
V_18 = F_39 ( V_2 , V_96 , true , NULL ) ;
if ( V_18 == 0 ) {
V_16 -> V_97 = true ;
} else if ( V_18 == - V_98 ) {
unsigned int V_99 ;
V_18 = F_40 ( V_2 , NULL , & V_99 ) ;
if ( V_18 )
goto V_83;
V_16 -> V_97 = V_99 &
V_100 ;
} else if ( V_18 != - V_101 && V_18 != - V_102 ) {
goto V_87;
}
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_5 ,
V_16 -> V_97 ? L_6 : L_7 ) ;
V_18 = F_42 ( V_2 ) ;
if ( V_18 && V_18 != - V_98 )
goto V_87;
F_43 ( V_2 , NULL ) ;
#ifdef F_44
if ( ( V_2 -> V_10 -> V_103 ) && ( ! V_2 -> V_10 -> V_104 ) ) {
struct V_10 * V_105 = V_2 -> V_10 -> V_103 ;
struct V_1 * V_106 = F_24 ( V_105 ) ;
V_106 -> type -> V_93 ( V_106 , V_16 -> V_107 ) ;
} else
#endif
F_18 ( V_16 -> V_107 , V_2 -> V_28 -> V_94 ) ;
return 0 ;
V_87:
F_45 ( & V_2 -> V_10 -> V_59 , & V_85 ) ;
V_86:
F_45 ( & V_2 -> V_10 -> V_59 , & V_84 ) ;
V_83:
F_46 ( V_2 ) ;
V_76:
F_47 ( V_2 , & V_16 -> V_74 ) ;
V_75:
F_48 ( V_16 ) ;
V_2 -> V_16 = NULL ;
return V_18 ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_50 ( V_13 ) ;
T_2 V_17 ;
int V_18 = F_51 ( V_2 , V_108 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 == - V_109 )
V_18 = 0 ;
if ( V_18 )
F_52 ( V_2 , V_108 , 0 , V_13 , V_17 ,
V_18 ) ;
return V_18 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_48 , V_110 ) ;
unsigned int V_68 ;
int V_18 ;
F_13 ( V_111 != 0 ) ;
for ( V_68 = 0 ; V_68 < V_16 -> V_112 ; V_68 ++ ) {
F_21 ( V_48 , V_113 ,
V_16 -> V_114 [ V_68 ] ) ;
V_18 = F_9 ( V_2 , V_115 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 ) ;
}
V_16 -> V_112 = 0 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_116 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_13 , V_117 ) ;
unsigned int V_68 ;
T_2 V_17 ;
int V_18 = 0 ;
F_13 ( V_118 != 0 ) ;
for ( V_68 = 0 ; V_68 < V_116 ; V_68 ++ ) {
V_18 = F_9 ( V_2 , V_119 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
break;
if ( V_17 < V_117 ) {
V_18 = - V_7 ;
break;
}
V_16 -> V_114 [ V_68 ] =
F_10 ( V_13 , V_120 ) ;
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_8 , V_68 ,
V_16 -> V_114 [ V_68 ] ) ;
}
V_16 -> V_112 = V_68 ;
if ( V_18 )
F_53 ( V_2 ) ;
return V_18 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_56 ( V_48 ,
F_57 ( V_121 ,
V_122 ) ) ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
unsigned int V_127 , V_128 ;
int V_18 ;
F_13 ( V_129 != 0 ) ;
F_13 ( V_130 != 0 ) ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
for ( V_128 = 0 ; V_128 < V_16 -> V_112 ; ++ V_128 ) {
F_21 ( V_48 , V_131 ,
V_16 -> V_114 [ V_128 ] ) ;
F_21 ( V_48 , V_132 ,
V_16 -> V_133 + V_128 ) ;
V_18 = F_9 ( V_2 , V_134 ,
V_48 , V_121 ,
NULL , 0 , NULL ) ;
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_9 ,
V_16 -> V_133 + V_128 , V_128 ,
V_18 ) ;
goto V_135;
}
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_10 ,
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
F_21 ( V_48 ,
V_131 ,
V_16 -> V_114 [ V_128 ] ) ;
F_21 ( V_48 ,
V_132 ,
V_126 -> V_140 ) ;
V_18 = F_9 ( V_2 , V_134 ,
V_48 , V_121 ,
NULL , 0 , NULL ) ;
}
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_9 ,
V_126 -> V_140 , V_128 , V_18 ) ;
V_126 -> V_141 = NULL ;
} else {
V_126 -> V_141 =
V_16 -> V_142 +
V_128 * V_143 + V_127 ;
V_126 -> V_144 = V_127 ;
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_11 ,
V_126 -> V_140 , V_128 ,
V_126 -> V_144 ,
V_126 -> V_141 ) ;
}
}
}
return 0 ;
V_135:
while ( V_128 -- ) {
F_21 ( V_48 , V_145 ,
V_16 -> V_133 + V_128 ) ;
F_9 ( V_2 , V_146 ,
V_48 , V_122 ,
NULL , 0 , NULL ) ;
}
return V_18 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_116 )
{
return V_116 == 0 ? 0 : - V_147 ;
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
struct V_10 * V_105 ;
struct V_1 * V_106 ;
struct V_149 * V_150 ;
if ( V_2 -> V_10 -> V_151 ) {
V_105 = V_2 -> V_10 -> V_103 ;
if ( V_105 ) {
V_106 = F_24 ( V_105 ) ;
V_148 = V_106 -> V_16 ;
V_150 = V_148 -> V_150 + V_16 -> V_22 ;
V_150 -> V_2 = NULL ;
} else
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_12 ) ;
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
F_45 ( & V_2 -> V_10 -> V_59 , & V_85 ) ;
F_45 ( & V_2 -> V_10 -> V_59 , & V_84 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 , & V_16 -> V_74 ) ;
F_48 ( V_16 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
return F_27 ( V_2 ) ;
}
int F_68 ( struct V_1 * V_2 , unsigned int V_107 )
{
F_8 ( V_48 , V_154 ) ;
F_21 ( V_48 , V_155 , V_107 ) ;
return F_9 ( V_2 , V_156 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
}
int F_69 ( struct V_1 * V_2 , unsigned int V_107 )
{
F_8 ( V_48 , V_157 ) ;
F_21 ( V_48 , V_158 , V_107 ) ;
return F_9 ( V_2 , V_159 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
}
int F_70 ( struct V_1 * V_2 ,
unsigned int V_107 , T_3 * V_160 )
{
F_8 ( V_48 , V_161 ) ;
F_21 ( V_48 , V_162 , V_107 ) ;
F_18 ( F_19 ( V_48 , V_163 ) , V_160 ) ;
return F_9 ( V_2 , V_164 , V_48 ,
sizeof( V_48 ) , NULL , 0 , NULL ) ;
}
int F_71 ( struct V_1 * V_2 ,
unsigned int V_107 , T_3 * V_160 )
{
F_8 ( V_48 , V_165 ) ;
F_21 ( V_48 , V_166 , V_107 ) ;
F_18 ( F_19 ( V_48 , V_167 ) , V_160 ) ;
return F_9 ( V_2 , V_168 , V_48 ,
sizeof( V_48 ) , NULL , 0 , NULL ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_10 * V_105 ;
V_105 = V_2 -> V_10 -> V_103 ;
if ( V_105 ) {
struct V_1 * V_106 = F_24 ( V_105 ) ;
struct V_15 * V_148 = V_106 -> V_16 ;
if ( ! V_148 -> V_150 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_13
L_14 ) ;
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
if ( V_2 -> V_10 -> V_103 ) {
struct V_1 * V_106 =
F_24 ( V_2 -> V_10 -> V_103 ) ;
struct V_15 * V_170 = V_106 -> V_16 ;
struct V_15 * V_16 = V_2 -> V_16 ;
V_170 -> V_150 [ V_16 -> V_22 ] . V_2 = V_2 ;
V_170 -> V_150 [ V_16 -> V_22 ] . V_10 =
V_2 -> V_10 ;
} else
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_12 ) ;
}
return 0 ;
V_135:
F_61 ( V_2 ) ;
return V_18 ;
}
static int F_73 ( struct V_1 * V_2 ,
unsigned int V_171 , unsigned int V_172 )
{
F_8 ( V_48 , V_173 ) ;
F_8 ( V_13 , V_174 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_175 , V_171 ) ;
F_21 ( V_48 , V_176 , V_172 ) ;
V_18 = F_9 ( V_2 , V_177 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_174 )
return - V_7 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_15 ,
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
unsigned int V_112 =
F_76 ( V_2 -> V_137 ,
V_139 / V_138 ) ;
V_18 = F_54 ( V_2 , V_112 ) ;
if ( V_18 )
F_14 ( V_2 , V_38 , V_2 -> V_28 ,
L_16 , V_18 ) ;
else
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_17 , V_112 ) ;
}
#else
V_16 -> V_112 = 0 ;
#endif
V_182 = F_77 ( ( V_186 - 1 ) * V_143 +
V_190 ) ;
if ( V_16 -> V_112 ) {
V_133 = V_182 / V_143 ;
V_183 = ( F_77 ( ( V_133 +
V_16 -> V_112 ) *
V_143 ) -
V_182 ) ;
V_172 = V_133 + V_16 -> V_112 ;
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
L_18
L_19 ) ;
V_2 -> V_69 = V_16 -> V_180 ;
V_2 -> V_70 =
V_16 -> V_180 / V_184 ;
F_49 ( V_2 ) ;
return - V_191 ;
}
if ( V_16 -> V_112 &&
V_16 -> V_180 <
V_133 + V_16 -> V_112 ) {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_20 ,
V_16 -> V_180 , V_16 -> V_112 ) ;
F_53 ( V_2 ) ;
}
V_187 = F_78 ( V_2 -> V_192 , V_182 ) ;
if ( ! V_187 ) {
F_14 ( V_2 , V_38 , V_2 -> V_28 ,
L_21 ,
V_182 ) ;
return - V_72 ;
}
F_66 ( V_2 -> V_187 ) ;
V_2 -> V_187 = V_187 ;
if ( V_183 ) {
V_16 -> V_152 = F_79 ( V_2 -> V_192 +
V_182 ,
V_183 ) ;
if ( ! V_16 -> V_152 ) {
F_14 ( V_2 , V_38 , V_2 -> V_28 ,
L_22 ,
V_183 ) ;
return - V_72 ;
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
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_23 ,
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
if ( V_16 -> V_153 && V_16 -> V_112 ) {
V_18 = F_54 ( V_2 , V_16 -> V_112 ) ;
if ( V_18 == 0 ) {
V_18 = F_55 ( V_2 ) ;
if ( V_18 )
F_53 ( V_2 ) ;
}
if ( V_18 )
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_24 , V_18 ) ;
V_16 -> V_153 = false ;
}
V_2 -> type -> V_195 ( V_2 , false , V_2 -> V_196 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
#ifdef F_44
unsigned int V_68 ;
#endif
V_16 -> V_194 = true ;
V_16 -> V_197 = true ;
V_16 -> V_153 = true ;
V_16 -> V_78 = V_79 ;
V_16 -> V_198 = true ;
V_16 -> V_80 = V_53 ;
#ifdef F_44
if ( V_16 -> V_150 )
for ( V_68 = 0 ; V_68 < V_2 -> V_199 ; V_68 ++ )
V_16 -> V_150 [ V_68 ] . V_80 = 0 ;
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
return V_82 ;
}
return - V_215 ;
}
static int F_85 ( struct V_1 * V_2 , enum V_200 V_200 )
{
int V_18 = F_35 ( V_2 , V_200 ) ;
if ( V_200 == V_214 && V_18 == - V_98 )
V_18 = 0 ;
if ( ( V_200 == V_82 ||
V_200 == V_216 ) && ! V_18 )
F_81 ( V_2 ) ;
return V_18 ;
}
static T_7 F_86 ( struct V_1 * V_2 )
{
T_7 V_217 = V_218 ;
T_6 V_219 = F_87 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_63 -> V_64 &
1 << V_65 ) )
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
F_8 ( V_48 , V_289 ) ;
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
F_106 ( V_48 , V_296 , V_293 . V_297 ) ;
F_107 ( V_48 , V_298 ,
V_299 , 1 ) ;
F_21 ( V_48 , V_300 , V_290 ) ;
F_21 ( V_48 , V_301 , V_53 ) ;
V_18 = F_51 ( V_2 , V_302 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_294 ) ;
if ( V_18 ) {
if ( V_18 != - V_102 || F_108 ( & V_2 -> V_303 ) )
F_52 ( V_2 , V_302 ,
sizeof( V_48 ) , NULL , 0 , V_18 ) ;
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
T_3 * V_327 = V_16 -> V_74 . V_281 ;
memcpy ( V_327 , V_323 , V_324 ) ;
memcpy ( V_327 + V_324 , V_325 , V_326 ) ;
F_121 () ;
F_32 ( V_2 , F_33 ( ( T_7 ) V_16 -> V_74 . V_297 >> 32 ) ,
V_328 ) ;
F_32 ( V_2 , F_33 ( ( T_6 ) V_16 -> V_74 . V_297 ) ,
V_81 ) ;
}
static bool F_122 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_1 V_323 = * ( const T_1 * ) V_16 -> V_74 . V_281 ;
F_95 () ;
return F_3 ( V_323 , V_329 ) ;
}
static void
F_123 ( struct V_1 * V_2 , T_1 * V_13 ,
T_2 V_127 , T_2 V_17 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_3 * V_327 = V_16 -> V_74 . V_281 ;
memcpy ( V_13 , V_327 + V_127 , V_17 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 ) {
return 0 ;
}
if ( V_18 == V_16 -> V_77 )
return 0 ;
V_16 -> V_77 = V_18 ;
F_81 ( V_2 ) ;
V_16 -> V_193 = true ;
V_16 -> V_235 [ V_287 ] = 0 ;
return - V_7 ;
}
static T_9 F_125 ( int V_330 , void * V_331 )
{
struct V_332 * V_333 = V_331 ;
struct V_1 * V_2 = V_333 -> V_2 ;
F_126 ( V_2 , V_334 , V_2 -> V_28 ,
L_25 , V_330 , F_127 () ) ;
if ( F_128 ( F_129 ( V_2 -> V_335 ) ) ) {
if ( V_333 -> V_128 == V_2 -> V_336 )
V_2 -> V_337 = F_127 () ;
F_130 ( V_2 -> V_124 [ V_333 -> V_128 ] ) ;
}
return V_338 ;
}
static T_9 F_131 ( int V_330 , void * V_331 )
{
struct V_1 * V_2 = V_331 ;
bool V_339 = F_129 ( V_2 -> V_335 ) ;
struct V_123 * V_124 ;
T_1 V_3 ;
T_6 V_340 ;
F_2 ( V_2 , & V_3 , V_341 ) ;
V_340 = F_3 ( V_3 , V_342 ) ;
if ( V_340 == 0 )
return V_343 ;
if ( F_128 ( V_339 ) ) {
if ( V_340 & ( 1U << V_2 -> V_336 ) )
V_2 -> V_337 = F_127 () ;
F_58 (channel, efx) {
if ( V_340 & 1 )
F_130 ( V_124 ) ;
V_340 >>= 1 ;
}
}
F_126 ( V_2 , V_334 , V_2 -> V_28 ,
L_26 V_344 L_27 ,
V_330 , F_127 () , F_132 ( V_3 ) ) ;
return V_338 ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_345 ) ;
F_13 ( V_346 != 0 ) ;
F_21 ( V_48 , V_347 , V_2 -> V_336 ) ;
( void ) F_9 ( V_2 , V_348 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
}
static int F_134 ( struct V_125 * V_126 )
{
return F_30 ( V_126 -> V_2 , & V_126 -> V_349 . V_62 ,
( V_126 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_71 ) ;
}
static inline void F_135 ( struct V_125 * V_126 ,
const V_351 * V_349 )
{
unsigned int V_352 ;
T_10 V_3 ;
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
F_136 ( V_3 , V_354 , V_352 ) ;
V_3 . V_355 [ 0 ] = * V_349 ;
F_137 ( V_126 -> V_2 , & V_3 ,
V_356 , V_126 -> V_140 ) ;
}
static void F_138 ( struct V_125 * V_126 )
{
F_8 ( V_48 , F_139 ( V_357 * 8 /
V_358 ) ) ;
bool V_359 = V_126 -> V_140 & V_360 ;
T_2 V_361 = V_126 -> V_349 . V_62 . V_362 / V_358 ;
struct V_123 * V_124 = V_126 -> V_124 ;
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_363 ;
T_11 V_297 ;
V_351 * V_349 ;
int V_18 ;
int V_68 ;
F_13 ( V_364 != 0 ) ;
F_21 ( V_48 , V_365 , V_126 -> V_350 + 1 ) ;
F_21 ( V_48 , V_366 , V_124 -> V_124 ) ;
F_21 ( V_48 , V_367 , V_126 -> V_140 ) ;
F_21 ( V_48 , V_368 , V_126 -> V_140 ) ;
F_140 ( V_48 , V_369 ,
V_370 , ! V_359 ,
V_371 , ! V_359 ) ;
F_21 ( V_48 , V_372 , 0 ) ;
F_21 ( V_48 , V_373 , V_16 -> V_80 ) ;
V_297 = V_126 -> V_349 . V_62 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_28 ,
V_126 -> V_140 , V_361 , ( T_7 ) V_297 ) ;
for ( V_68 = 0 ; V_68 < V_361 ; ++ V_68 ) {
F_141 ( V_48 , V_375 , V_68 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_139 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_376 , V_48 , V_363 ,
NULL , 0 , NULL ) ;
if ( V_18 )
goto V_135;
V_126 -> V_377 [ 0 ] . V_204 = V_378 ;
V_126 -> V_379 = 1 ;
V_349 = F_142 ( V_126 , 0 ) ;
F_143 ( * V_349 ,
V_380 , true ,
V_381 ,
V_382 ,
V_383 , V_359 ,
V_384 , V_359 ) ;
V_126 -> V_353 = 1 ;
F_121 () ;
F_135 ( V_126 , V_349 ) ;
return;
V_135:
F_144 ( V_2 -> V_28 , L_29 ,
V_126 -> V_140 ) ;
}
static void F_145 ( struct V_125 * V_126 )
{
F_8 ( V_48 , V_385 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_126 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_386 ,
V_126 -> V_140 ) ;
V_18 = F_51 ( V_2 , V_387 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_109 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_387 , V_385 ,
V_13 , V_17 , V_18 ) ;
}
static void F_146 ( struct V_125 * V_126 )
{
F_47 ( V_126 -> V_2 , & V_126 -> V_349 . V_62 ) ;
}
static inline void F_147 ( struct V_125 * V_126 )
{
unsigned int V_352 ;
T_1 V_3 ;
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
F_148 ( V_3 , V_388 , V_352 ) ;
F_114 ( V_126 -> V_2 , & V_3 ,
V_389 , V_126 -> V_140 ) ;
}
static void F_149 ( struct V_125 * V_126 )
{
unsigned int V_390 = V_126 -> V_353 ;
struct V_391 * V_377 ;
unsigned int V_352 ;
V_351 * V_349 ;
F_60 ( V_126 -> V_353 == V_126 -> V_379 ) ;
do {
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
V_377 = & V_126 -> V_377 [ V_352 ] ;
V_349 = F_142 ( V_126 , V_352 ) ;
++ V_126 -> V_353 ;
if ( V_377 -> V_204 & V_378 ) {
* V_349 = V_377 -> V_392 ;
} else {
F_13 ( V_393 != 1 ) ;
F_150 (
* V_349 ,
V_394 ,
V_377 -> V_204 & V_393 ,
V_395 , V_377 -> V_362 ,
V_396 , V_377 -> V_297 ) ;
}
} while ( V_126 -> V_353 != V_126 -> V_379 );
F_121 () ;
if ( F_151 ( V_126 , V_390 ) ) {
V_349 = F_142 ( V_126 ,
V_390 & V_126 -> V_350 ) ;
F_135 ( V_126 , V_349 ) ;
++ V_126 -> V_397 ;
} else {
F_147 ( V_126 ) ;
}
}
static int F_152 ( struct V_1 * V_2 , T_6 * V_333 ,
bool V_398 , unsigned * V_399 )
{
F_8 ( V_48 , V_400 ) ;
F_8 ( V_13 , V_401 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_6 V_402 = V_398 ?
V_403 :
V_404 ;
unsigned V_405 = V_398 ?
V_2 -> V_405 :
F_153 ( F_154 ( V_2 -> V_405 ) ,
V_406 ) ;
if ( ! V_398 && V_405 == 1 ) {
* V_333 = V_79 ;
if ( V_399 )
* V_399 = 1 ;
return 0 ;
}
F_21 ( V_48 , V_407 ,
V_16 -> V_80 ) ;
F_21 ( V_48 , V_408 , V_402 ) ;
F_21 ( V_48 , V_409 , V_405 ) ;
V_18 = F_9 ( V_2 , V_410 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_401 )
return - V_7 ;
* V_333 = F_10 ( V_13 , V_411 ) ;
if ( V_399 )
* V_399 = V_405 ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 , T_6 V_333 )
{
F_8 ( V_48 , V_412 ) ;
int V_18 ;
F_21 ( V_48 , V_413 ,
V_333 ) ;
V_18 = F_9 ( V_2 , V_414 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 != 0 ) ;
}
static int F_156 ( struct V_1 * V_2 , T_6 V_333 ,
const T_6 * V_196 )
{
F_8 ( V_415 , V_416 ) ;
F_8 ( V_417 , V_418 ) ;
int V_68 , V_18 ;
F_21 ( V_415 , V_419 ,
V_333 ) ;
F_13 ( F_157 ( V_2 -> V_196 ) !=
V_420 ) ;
for ( V_68 = 0 ; V_68 < F_157 ( V_2 -> V_196 ) ; ++ V_68 )
F_19 ( V_415 ,
V_421 ) [ V_68 ] =
( T_3 ) V_196 [ V_68 ] ;
V_18 = F_9 ( V_2 , V_422 , V_415 ,
sizeof( V_415 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_21 ( V_417 , V_423 ,
V_333 ) ;
F_13 ( F_157 ( V_2 -> V_424 ) !=
V_425 ) ;
for ( V_68 = 0 ; V_68 < F_157 ( V_2 -> V_424 ) ; ++ V_68 )
F_19 ( V_417 , V_426 ) [ V_68 ] =
V_2 -> V_424 [ V_68 ] ;
return F_9 ( V_2 , V_427 , V_417 ,
sizeof( V_417 ) , NULL , 0 , NULL ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_78 != V_79 )
F_155 ( V_2 , V_16 -> V_78 ) ;
V_16 -> V_78 = V_79 ;
}
static int F_158 ( struct V_1 * V_2 ,
unsigned * V_399 )
{
T_6 V_428 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_152 ( V_2 , & V_428 ,
false , V_399 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_78 = V_428 ;
V_16 -> V_429 = false ;
F_159 ( V_2 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 ,
const T_6 * V_196 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_428 ;
if ( V_16 -> V_78 == V_79 ||
! V_16 -> V_429 ) {
V_18 = F_152 ( V_2 , & V_428 ,
true , NULL ) ;
if ( V_18 == - V_319 )
return V_18 ;
else if ( V_18 != 0 )
goto V_75;
} else {
V_428 = V_16 -> V_78 ;
}
V_18 = F_156 ( V_2 , V_428 ,
V_196 ) ;
if ( V_18 != 0 )
goto V_76;
if ( V_16 -> V_78 != V_428 )
F_65 ( V_2 ) ;
V_16 -> V_78 = V_428 ;
V_16 -> V_429 = true ;
if ( V_196 != V_2 -> V_196 )
memcpy ( V_2 -> V_196 , V_196 ,
sizeof( V_2 -> V_196 ) ) ;
return 0 ;
V_76:
if ( V_428 != V_16 -> V_78 )
F_155 ( V_2 , V_428 ) ;
V_75:
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_30 , V_430 , V_18 ) ;
return V_18 ;
}
static int F_161 ( struct V_1 * V_2 , bool V_431 ,
const T_6 * V_196 )
{
int V_18 ;
if ( V_2 -> V_405 == 1 )
return 0 ;
V_18 = F_160 ( V_2 , V_196 ) ;
if ( V_18 == - V_147 && ! V_431 ) {
unsigned V_399 ;
bool V_432 = false ;
T_2 V_68 ;
for ( V_68 = 0 ; V_68 < F_157 ( V_2 -> V_196 ) && ! V_432 ;
V_68 ++ )
V_432 = V_196 [ V_68 ] !=
F_162 ( V_68 , V_2 -> V_405 ) ;
V_18 = F_158 ( V_2 , & V_399 ) ;
if ( V_18 == 0 ) {
if ( V_399 != V_2 -> V_405 )
F_163 ( V_2 , V_38 , V_2 -> V_28 ,
L_31
L_32
L_33
L_34 ,
V_2 -> V_405 , V_399 ) ;
else if ( V_432 )
F_163 ( V_2 , V_38 , V_2 -> V_28 ,
L_31
L_35
L_36
L_37 ) ;
else
F_62 ( V_2 , V_38 , V_2 -> V_28 ,
L_31
L_38 ) ;
}
}
return V_18 ;
}
static int F_164 ( struct V_433 * V_434 )
{
return F_30 ( V_434 -> V_2 , & V_434 -> V_435 . V_62 ,
( V_434 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_71 ) ;
}
static void F_165 ( struct V_433 * V_434 )
{
F_8 ( V_48 ,
F_166 ( V_357 * 8 /
V_358 ) ) ;
struct V_123 * V_124 = F_167 ( V_434 ) ;
T_2 V_361 = V_434 -> V_435 . V_62 . V_362 / V_358 ;
struct V_1 * V_2 = V_434 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_363 ;
T_11 V_297 ;
int V_18 ;
int V_68 ;
F_13 ( V_436 != 0 ) ;
V_434 -> V_437 = 0 ;
V_434 -> V_438 = 0 ;
F_21 ( V_48 , V_439 , V_434 -> V_350 + 1 ) ;
F_21 ( V_48 , V_440 , V_124 -> V_124 ) ;
F_21 ( V_48 , V_441 , F_168 ( V_434 ) ) ;
F_21 ( V_48 , V_442 ,
F_168 ( V_434 ) ) ;
F_140 ( V_48 , V_443 ,
V_444 , 1 ,
V_445 , 1 ) ;
F_21 ( V_48 , V_446 , 0 ) ;
F_21 ( V_48 , V_447 , V_16 -> V_80 ) ;
V_297 = V_434 -> V_435 . V_62 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_39 ,
F_168 ( V_434 ) , V_361 , ( T_7 ) V_297 ) ;
for ( V_68 = 0 ; V_68 < V_361 ; ++ V_68 ) {
F_141 ( V_48 , V_448 , V_68 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_166 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_449 , V_48 , V_363 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_144 ( V_2 -> V_28 , L_40 ,
F_168 ( V_434 ) ) ;
}
static void F_169 ( struct V_433 * V_434 )
{
F_8 ( V_48 , V_450 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_434 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_451 ,
F_168 ( V_434 ) ) ;
V_18 = F_51 ( V_2 , V_452 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_109 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_452 , V_450 ,
V_13 , V_17 , V_18 ) ;
}
static void F_170 ( struct V_433 * V_434 )
{
F_47 ( V_434 -> V_2 , & V_434 -> V_435 . V_62 ) ;
}
static inline void
F_171 ( struct V_433 * V_434 , unsigned int V_128 )
{
struct V_453 * V_454 ;
V_351 * V_435 ;
V_435 = F_172 ( V_434 , V_128 ) ;
V_454 = V_453 ( V_434 , V_128 ) ;
F_173 ( * V_435 ,
V_455 , V_454 -> V_362 ,
V_456 , V_454 -> V_297 ) ;
}
static void F_174 ( struct V_433 * V_434 )
{
struct V_1 * V_2 = V_434 -> V_2 ;
unsigned int V_353 ;
T_1 V_3 ;
V_353 = V_434 -> V_457 & ~ 7 ;
if ( V_434 -> V_458 == V_353 )
return;
do
F_171 (
V_434 ,
V_434 -> V_458 & V_434 -> V_350 ) ;
while ( ++ V_434 -> V_458 != V_353 );
F_121 () ;
F_148 ( V_3 , V_459 ,
V_353 & V_434 -> V_350 ) ;
F_114 ( V_2 , & V_3 , V_460 ,
F_168 ( V_434 ) ) ;
}
static void F_175 ( struct V_433 * V_434 )
{
struct V_123 * V_124 = F_167 ( V_434 ) ;
F_8 ( V_48 , V_461 ) ;
V_351 V_462 ;
F_173 ( V_462 ,
V_463 , V_464 ,
V_465 , V_466 ) ;
F_21 ( V_48 , V_467 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_48 , V_468 ) , & V_462 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
F_176 ( V_124 -> V_2 , V_469 ,
V_48 , sizeof( V_48 ) , 0 ,
V_470 , 0 ) ;
}
static void
V_470 ( struct V_1 * V_2 , unsigned long V_471 ,
int V_18 , T_1 * V_13 ,
T_2 V_472 )
{
}
static int F_177 ( struct V_123 * V_124 )
{
return F_30 ( V_124 -> V_2 , & V_124 -> V_473 . V_62 ,
( V_124 -> V_474 + 1 ) *
sizeof( V_351 ) ,
V_71 ) ;
}
static void F_178 ( struct V_123 * V_124 )
{
F_8 ( V_48 , V_475 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_476 , V_124 -> V_124 ) ;
V_18 = F_51 ( V_2 , V_477 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_109 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_477 , V_475 ,
V_13 , V_17 , V_18 ) ;
}
static int F_179 ( struct V_123 * V_124 )
{
F_8 ( V_48 ,
F_180 ( V_478 * 8 /
V_358 ) ) ;
F_8 ( V_13 , V_479 ) ;
T_2 V_361 = V_124 -> V_473 . V_62 . V_362 / V_358 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_15 * V_16 ;
bool V_480 ;
T_2 V_363 , V_17 ;
unsigned int V_99 , V_481 ;
T_11 V_297 ;
int V_18 ;
int V_68 ;
V_16 = V_2 -> V_16 ;
V_480 =
! ! ( V_16 -> V_29 &
1 << V_482 ) ;
memset ( V_124 -> V_473 . V_62 . V_281 , 0xff , V_124 -> V_473 . V_62 . V_362 ) ;
F_21 ( V_48 , V_483 , V_124 -> V_474 + 1 ) ;
F_21 ( V_48 , V_484 , V_124 -> V_124 ) ;
F_21 ( V_48 , V_485 , V_124 -> V_124 ) ;
F_181 ( V_48 , V_486 ,
V_487 , 1 ,
V_488 , 1 ,
V_489 , 1 ,
V_490 , ! V_480 ) ;
F_21 ( V_48 , V_491 ,
V_492 ) ;
F_21 ( V_48 , V_493 , 0 ) ;
F_21 ( V_48 , V_494 , 0 ) ;
F_21 ( V_48 , V_495 ,
V_496 ) ;
F_21 ( V_48 , V_497 , 0 ) ;
V_297 = V_124 -> V_473 . V_62 . V_297 ;
for ( V_68 = 0 ; V_68 < V_361 ; ++ V_68 ) {
F_141 ( V_48 , V_498 , V_68 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_180 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_499 , V_48 , V_363 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_124 -> V_124 || V_18 )
return V_18 ;
V_18 = F_40 ( V_2 , & V_481 , & V_99 ) ;
if ( V_18 == - V_101 ) {
V_16 -> V_500 = false ;
V_18 = 0 ;
} else if ( V_18 ) {
goto V_135;
} else {
V_16 -> V_500 =
! ! ( V_99 & V_501 ) ;
if ( V_481 & V_501 &&
! V_16 -> V_500 ) {
unsigned int V_204 ;
V_18 = F_39 ( V_2 ,
V_502 ,
true , & V_204 ) ;
if ( ! V_18 ) {
if ( V_204 &
1 << V_503 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_41 ) ;
++ V_16 -> V_77 ;
}
V_16 -> V_500 = true ;
} else if ( V_18 == - V_98 ) {
V_18 = 0 ;
}
}
}
if ( ! V_18 )
return 0 ;
V_135:
F_178 ( V_124 ) ;
return V_18 ;
}
static void F_182 ( struct V_123 * V_124 )
{
F_47 ( V_124 -> V_2 , & V_124 -> V_473 . V_62 ) ;
}
static void F_183 ( struct V_433 * V_434 ,
unsigned int V_504 )
{
struct V_1 * V_2 = V_434 -> V_2 ;
F_62 ( V_2 , V_374 , V_2 -> V_28 ,
L_42 ,
F_168 ( V_434 ) , V_504 ) ;
F_184 ( V_2 , V_505 ) ;
}
static void
F_185 ( struct V_433 * V_434 ,
unsigned int V_506 , unsigned int V_507 )
{
unsigned int V_508 = ( V_506 - V_507 ) & V_434 -> V_350 ;
struct V_1 * V_2 = V_434 -> V_2 ;
F_62 ( V_2 , V_374 , V_2 -> V_28 ,
L_43 ,
V_508 , V_506 , V_507 ) ;
F_184 ( V_2 , V_505 ) ;
}
static void F_186 ( struct V_433 * V_434 )
{
unsigned int V_509 ;
F_41 ( V_434 -> V_2 , V_374 , V_434 -> V_2 -> V_28 ,
L_44 ,
V_434 -> V_437 ) ;
V_509 = V_434 -> V_510 & V_434 -> V_350 ;
F_187 ( V_434 , V_509 , V_434 -> V_437 ,
0 , V_511 ) ;
V_434 -> V_510 += V_434 -> V_437 ;
V_434 -> V_437 = 0 ;
V_434 -> V_438 = 0 ;
++ F_167 ( V_434 ) -> V_512 ;
}
static int F_188 ( struct V_123 * V_124 ,
const V_351 * V_462 )
{
unsigned int V_245 , V_513 , V_504 , V_514 ;
unsigned int V_515 , V_516 , V_68 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_433 * V_434 ;
bool V_517 ;
T_12 V_204 = 0 ;
if ( F_189 ( F_129 ( V_2 -> V_518 ) ) )
return 0 ;
V_245 = F_190 ( * V_462 , V_519 ) ;
V_513 = F_190 ( * V_462 , V_520 ) ;
V_504 = F_190 ( * V_462 , V_521 ) ;
V_514 = F_190 ( * V_462 , V_522 ) ;
V_517 = F_190 ( * V_462 , V_523 ) ;
if ( F_190 ( * V_462 , V_524 ) )
F_144 ( V_2 -> V_28 , L_45
V_525 L_27 ,
F_191 ( * V_462 ) ) ;
V_434 = F_192 ( V_124 ) ;
if ( F_189 ( V_504 != F_168 ( V_434 ) ) )
F_183 ( V_434 , V_504 ) ;
V_515 = ( ( V_513 - V_434 -> V_510 ) &
( ( 1 << V_526 ) - 1 ) ) ;
if ( V_515 != V_434 -> V_437 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_189 ( V_515 == V_434 -> V_437 ) ) {
if ( V_434 -> V_437 == 0 || V_245 != 0 )
F_144 ( V_2 -> V_28 ,
L_46
V_525 L_27 ,
V_434 -> V_437 ,
F_191 ( * V_462 ) ) ;
F_186 ( V_434 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_29 &
( 1 << V_482 ) ) ||
V_434 -> V_437 != 0 || V_517 ) {
F_185 (
V_434 , V_513 ,
( V_434 -> V_510 +
V_434 -> V_437 + 1 ) &
( ( 1 << V_526 ) - 1 ) ) ;
return 0 ;
}
V_434 -> V_437 = 1 ;
V_434 -> V_438 = 0 ;
V_516 = V_515 ;
++ V_124 -> V_527 ;
V_124 -> V_528 += V_516 ;
V_204 |= V_529 ;
} else {
++ V_434 -> V_437 ;
V_434 -> V_438 += V_245 ;
if ( V_517 )
return 0 ;
V_516 = 1 ;
}
if ( F_189 ( F_190 ( * V_462 , V_530 ) ) )
V_204 |= V_511 ;
if ( F_189 ( F_190 ( * V_462 , V_531 ) ) ) {
V_124 -> V_532 += V_516 ;
} else if ( F_189 ( F_190 ( * V_462 ,
V_533 ) ) ) {
V_124 -> V_534 += V_516 ;
} else if ( V_514 == V_535 ||
V_514 == V_536 ) {
V_204 |= V_537 ;
}
if ( V_514 == V_535 )
V_204 |= V_538 ;
V_124 -> V_539 += 2 * V_516 ;
for ( V_68 = 0 ; V_68 < V_516 ; V_68 ++ ) {
F_187 ( V_434 ,
V_434 -> V_510 & V_434 -> V_350 ,
V_434 -> V_437 , V_434 -> V_438 ,
V_204 ) ;
V_434 -> V_510 += V_434 -> V_437 ;
}
V_434 -> V_437 = 0 ;
V_434 -> V_438 = 0 ;
return V_516 ;
}
static int
F_193 ( struct V_123 * V_124 , V_351 * V_462 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_125 * V_126 ;
unsigned int V_540 ;
unsigned int V_541 ;
int V_542 = 0 ;
if ( F_189 ( F_129 ( V_2 -> V_518 ) ) )
return 0 ;
if ( F_189 ( F_190 ( * V_462 , V_543 ) ) )
return 0 ;
V_540 = F_190 ( * V_462 , V_544 ) ;
V_541 = F_190 ( * V_462 , V_545 ) ;
V_126 = F_194 ( V_124 ,
V_541 % V_184 ) ;
V_542 = ( ( V_540 + 1 - V_126 -> V_546 ) &
V_126 -> V_350 ) ;
F_195 ( V_126 , V_540 & V_126 -> V_350 ) ;
return V_542 ;
}
static void
F_196 ( struct V_123 * V_124 , V_351 * V_462 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
int V_547 ;
V_547 = F_190 ( * V_462 , V_548 ) ;
switch ( V_547 ) {
case V_549 :
case V_550 :
break;
case V_551 :
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_47
L_48 V_525 L_49 ,
V_124 -> V_124 , V_547 ,
F_191 ( * V_462 ) ) ;
}
}
static void F_197 ( struct V_123 * V_124 ,
V_351 * V_462 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_6 V_547 ;
V_547 = F_190 ( * V_462 , V_552 ) ;
switch ( V_547 ) {
case V_553 :
V_124 -> V_554 = F_127 () ;
break;
case V_466 :
F_198 ( & V_124 -> V_434 , true ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_50
L_48 V_525 L_49 ,
V_124 -> V_124 , ( unsigned ) V_547 ,
F_191 ( * V_462 ) ) ;
}
}
static int F_199 ( struct V_123 * V_124 , int V_555 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_462 , * V_556 ;
unsigned int V_557 ;
int V_558 ;
int V_542 = 0 ;
int V_559 = 0 ;
if ( V_555 <= 0 )
return V_559 ;
V_557 = V_124 -> V_560 ;
for (; ; ) {
V_556 = F_200 ( V_124 , V_557 ) ;
V_462 = * V_556 ;
if ( ! F_201 ( & V_462 ) )
break;
F_202 ( * V_556 ) ;
++ V_557 ;
V_558 = F_190 ( V_462 , V_463 ) ;
F_126 ( V_2 , V_27 , V_2 -> V_28 ,
L_51 V_525 L_27 ,
V_124 -> V_124 , F_191 ( V_462 ) ) ;
switch ( V_558 ) {
case V_561 :
F_203 ( V_124 , & V_462 ) ;
break;
case V_562 :
V_559 += F_188 ( V_124 , & V_462 ) ;
if ( V_559 >= V_555 ) {
V_559 = V_555 ;
goto V_304;
}
break;
case V_563 :
V_542 += F_193 ( V_124 , & V_462 ) ;
if ( V_542 > V_2 -> V_564 ) {
V_559 = V_555 ;
goto V_304;
} else if ( ++ V_559 == V_555 ) {
goto V_304;
}
break;
case V_565 :
F_196 ( V_124 , & V_462 ) ;
if ( ++ V_559 == V_555 )
goto V_304;
break;
case V_464 :
F_197 ( V_124 , & V_462 ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_52
L_48 V_525 L_49 ,
V_124 -> V_124 , V_558 ,
F_191 ( V_462 ) ) ;
}
}
V_304:
V_124 -> V_560 = V_557 ;
return V_559 ;
}
static void F_204 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_1 V_566 ;
if ( F_112 ( V_2 ) ) {
F_13 ( V_567 <
( 1 << V_568 ) ) ;
F_13 ( V_478 >
( 1 << 2 * V_568 ) ) ;
F_115 ( V_566 , V_569 ,
V_570 ,
V_571 ,
( V_124 -> V_560 &
V_124 -> V_474 ) >>
V_568 ) ;
F_114 ( V_2 , & V_566 , V_313 ,
V_124 -> V_124 ) ;
F_115 ( V_566 , V_569 ,
V_572 ,
V_571 ,
V_124 -> V_560 &
( ( 1 << V_568 ) - 1 ) ) ;
F_114 ( V_2 , & V_566 , V_313 ,
V_124 -> V_124 ) ;
} else {
F_148 ( V_566 , V_573 ,
V_124 -> V_560 &
V_124 -> V_474 ) ;
F_114 ( V_2 , & V_566 , V_574 , V_124 -> V_124 ) ;
}
}
static void F_205 ( struct V_123 * V_124 )
{
F_8 ( V_48 , V_461 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_462 ;
int V_18 ;
F_173 ( V_462 ,
V_463 , V_464 ,
V_465 , V_553 ) ;
F_21 ( V_48 , V_467 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_48 , V_468 ) , & V_462 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
V_18 = F_9 ( V_2 , V_469 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_135;
return;
V_135:
F_22 ( true ) ;
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_30 , V_430 , V_18 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
if ( F_207 ( & V_2 -> V_303 ) )
F_208 ( & V_2 -> V_575 ) ;
F_22 ( F_108 ( & V_2 -> V_303 ) < 0 ) ;
}
static int F_209 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
struct V_433 * V_434 ;
int V_576 ;
if ( V_16 -> V_194 ) {
F_210 ( & V_2 -> V_303 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_577 != V_578 ) {
F_58 (channel, efx) {
F_211 (rx_queue, channel)
F_169 ( V_434 ) ;
F_59 (tx_queue, channel)
F_145 ( V_126 ) ;
}
F_212 ( V_2 -> V_575 ,
F_108 ( & V_2 -> V_303 ) == 0 ,
F_213 ( V_579 ) ) ;
V_576 = F_108 ( & V_2 -> V_303 ) ;
if ( V_576 ) {
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_53 ,
V_576 ) ;
return - V_580 ;
}
}
return 0 ;
}
static void F_214 ( struct V_1 * V_2 )
{
F_210 ( & V_2 -> V_303 , 0 ) ;
}
static bool F_215 ( const struct V_581 * V_582 ,
const struct V_581 * V_583 )
{
if ( ( V_582 -> V_584 ^ V_583 -> V_584 ) |
( ( V_582 -> V_204 ^ V_583 -> V_204 ) &
( V_585 | V_586 ) ) )
return false ;
return memcmp ( & V_582 -> V_587 , & V_583 -> V_587 ,
sizeof( struct V_581 ) -
F_216 ( struct V_581 , V_587 ) ) == 0 ;
}
static unsigned int F_217 ( const struct V_581 * V_588 )
{
F_13 ( F_216 ( struct V_581 , V_587 ) & 3 ) ;
return F_218 ( ( const T_6 * ) & V_588 -> V_587 ,
( sizeof( struct V_581 ) -
F_216 ( struct V_581 , V_587 ) ) / 4 ,
0 ) ;
}
static bool F_219 ( const struct V_581 * V_588 )
{
if ( V_588 -> V_584 & V_589 &&
! F_220 ( V_588 -> V_590 ) )
return true ;
if ( ( V_588 -> V_584 &
( V_591 | V_592 ) ) ==
( V_591 | V_592 ) ) {
if ( V_588 -> V_593 == F_221 ( V_594 ) &&
! F_222 ( V_588 -> V_595 [ 0 ] ) )
return true ;
if ( V_588 -> V_593 == F_221 ( V_596 ) &&
( ( const T_3 * ) V_588 -> V_595 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_581 *
F_223 ( const struct V_597 * V_598 ,
unsigned int V_599 )
{
return (struct V_581 * ) ( V_598 -> V_600 [ V_599 ] . V_588 &
~ V_601 ) ;
}
static unsigned int
F_224 ( const struct V_597 * V_598 ,
unsigned int V_599 )
{
return V_598 -> V_600 [ V_599 ] . V_588 & V_601 ;
}
static void
F_225 ( struct V_597 * V_598 ,
unsigned int V_599 ,
const struct V_581 * V_588 ,
unsigned int V_204 )
{
V_598 -> V_600 [ V_599 ] . V_588 = ( unsigned long ) V_588 | V_204 ;
}
static void F_226 ( struct V_1 * V_2 ,
const struct V_581 * V_588 ,
T_1 * V_48 , T_7 V_602 ,
bool V_603 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
memset ( V_48 , 0 , V_604 ) ;
if ( V_603 ) {
F_21 ( V_48 , V_605 ,
V_606 ) ;
F_106 ( V_48 , V_607 , V_602 ) ;
} else {
T_6 V_608 = 0 ;
F_21 ( V_48 , V_605 ,
F_219 ( V_588 ) ?
V_609 :
V_610 ) ;
if ( V_588 -> V_584 & V_611 )
V_608 |=
F_220 ( V_588 -> V_590 ) ?
1 << V_612 :
1 << V_613 ;
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
F_227 ( V_614 , V_615 , V_616 ) ;
F_227 ( V_617 , V_595 , V_618 ) ;
F_227 ( V_619 , V_620 , V_621 ) ;
F_227 ( V_622 , V_623 , V_624 ) ;
F_227 ( V_625 , V_590 , V_626 ) ;
F_227 ( V_627 , V_628 , V_629 ) ;
F_227 ( V_630 , V_593 , V_630 ) ;
F_227 ( V_631 , V_632 , V_633 ) ;
F_227 ( V_634 , V_587 , V_635 ) ;
F_227 ( V_636 , V_637 , V_636 ) ;
#undef F_227
F_21 ( V_48 , V_638 ,
V_608 ) ;
}
F_21 ( V_48 , V_639 , V_16 -> V_80 ) ;
F_21 ( V_48 , V_640 ,
V_588 -> V_641 == V_642 ?
V_643 :
V_644 ) ;
F_21 ( V_48 , V_645 , 0 ) ;
F_21 ( V_48 , V_646 ,
V_647 ) ;
F_21 ( V_48 , V_648 ,
V_588 -> V_641 == V_642 ?
0 : V_588 -> V_641 ) ;
F_21 ( V_48 , V_649 ,
( V_588 -> V_204 & V_650 ) ?
V_651 :
V_652 ) ;
if ( V_588 -> V_204 & V_650 )
F_21 ( V_48 , V_653 ,
V_588 -> V_654 !=
V_655 ?
V_588 -> V_654 : V_16 -> V_78 ) ;
}
static int F_228 ( struct V_1 * V_2 ,
const struct V_581 * V_588 ,
T_7 * V_602 , bool V_603 )
{
F_8 ( V_48 , V_604 ) ;
F_8 ( V_13 , V_656 ) ;
int V_18 ;
F_226 ( V_2 , V_588 , V_48 , * V_602 , V_603 ) ;
V_18 = F_9 ( V_2 , V_657 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_602 = F_229 ( V_13 , V_658 ) ;
if ( V_18 == - V_659 )
V_18 = - V_169 ;
return V_18 ;
}
static int F_230 ( struct V_597 * V_598 ,
enum V_660 V_584 )
{
unsigned int V_661 ;
for ( V_661 = 0 ;
V_661 < V_598 -> V_662 ;
V_661 ++ )
if ( V_598 -> V_663 [ V_661 ] == V_584 )
return V_661 ;
return - V_664 ;
}
static T_16 F_231 ( struct V_1 * V_2 ,
struct V_581 * V_588 ,
bool V_665 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
F_90 ( V_667 , V_668 ) ;
struct V_581 * V_669 ;
unsigned int V_661 , V_670 ;
unsigned int V_671 ;
bool V_603 = false ;
int V_672 = - 1 ;
F_232 ( V_673 ) ;
bool V_674 ;
T_16 V_18 ;
if ( ( V_588 -> V_204 & ( V_585 | V_586 ) ) !=
V_585 )
return - V_215 ;
V_18 = F_230 ( V_598 , V_588 -> V_584 ) ;
if ( V_18 < 0 )
return V_18 ;
V_661 = V_18 ;
V_670 = F_217 ( V_588 ) ;
V_674 = F_233 ( V_588 ) ;
if ( V_674 )
F_234 ( V_667 , V_668 ) ;
for (; ; ) {
unsigned int V_675 = 1 ;
unsigned int V_68 ;
F_105 ( & V_2 -> V_676 ) ;
for (; ; ) {
V_68 = ( V_670 + V_675 ) & ( V_677 - 1 ) ;
V_669 = F_223 ( V_598 , V_68 ) ;
if ( ! V_669 ) {
if ( V_672 < 0 )
V_672 = V_68 ;
} else if ( F_215 ( V_588 , V_669 ) ) {
if ( V_598 -> V_600 [ V_68 ] . V_588 &
V_678 )
break;
if ( V_588 -> V_679 < V_669 -> V_679 &&
V_588 -> V_679 != V_680 ) {
V_18 = - V_98 ;
goto V_681;
}
if ( ! V_674 ) {
if ( V_588 -> V_679 ==
V_669 -> V_679 &&
! V_665 ) {
V_18 = - V_682 ;
goto V_681;
}
V_672 = V_68 ;
goto V_683;
} else if ( V_588 -> V_679 >
V_669 -> V_679 ||
( V_588 -> V_679 ==
V_669 -> V_679 &&
V_665 ) ) {
if ( V_672 < 0 )
V_672 = V_68 ;
else
F_235 ( V_675 , V_667 ) ;
}
}
if ( V_675 == V_668 ) {
if ( V_672 < 0 ) {
V_18 = - V_169 ;
goto V_681;
}
goto V_683;
}
++ V_675 ;
}
F_236 ( & V_598 -> V_684 , & V_673 , V_685 ) ;
F_103 ( & V_2 -> V_676 ) ;
F_237 () ;
}
V_683:
V_669 = F_223 ( V_598 , V_672 ) ;
if ( V_669 ) {
if ( V_588 -> V_679 == V_680 &&
V_669 -> V_679 >= V_680 ) {
if ( V_669 -> V_679 > V_680 )
V_669 -> V_204 |= V_686 ;
V_598 -> V_600 [ V_672 ] . V_588 &=
~ V_687 ;
V_18 = V_672 ;
goto V_681;
}
V_603 = true ;
V_671 = F_224 ( V_598 , V_672 ) ;
} else {
V_669 = F_238 ( sizeof( * V_588 ) , V_295 ) ;
if ( ! V_669 ) {
V_18 = - V_72 ;
goto V_681;
}
* V_669 = * V_588 ;
V_671 = 0 ;
}
F_225 ( V_598 , V_672 , V_669 ,
V_671 | V_678 ) ;
if ( V_674 ) {
unsigned int V_675 , V_68 ;
for ( V_675 = 0 ; V_675 < V_668 ; V_675 ++ ) {
V_68 = ( V_670 + V_675 ) & ( V_677 - 1 ) ;
if ( F_239 ( V_675 , V_667 ) )
V_598 -> V_600 [ V_68 ] . V_588 |=
V_678 ;
}
}
F_103 ( & V_2 -> V_676 ) ;
V_18 = F_228 ( V_2 , V_588 , & V_598 -> V_600 [ V_672 ] . V_602 ,
V_603 ) ;
F_105 ( & V_2 -> V_676 ) ;
if ( V_18 == 0 ) {
if ( V_603 ) {
if ( V_669 -> V_679 == V_680 )
V_669 -> V_204 |=
V_686 ;
V_669 -> V_679 = V_588 -> V_679 ;
V_669 -> V_204 &= V_686 ;
V_669 -> V_204 |= V_588 -> V_204 ;
V_669 -> V_654 = V_588 -> V_654 ;
V_669 -> V_641 = V_588 -> V_641 ;
}
} else if ( ! V_603 ) {
F_48 ( V_669 ) ;
V_669 = NULL ;
}
F_225 ( V_598 , V_672 , V_669 , V_671 ) ;
if ( V_674 ) {
F_8 ( V_48 , V_604 ) ;
unsigned int V_675 , V_68 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
for ( V_675 = 0 ; V_675 < V_668 ; V_675 ++ ) {
if ( ! F_239 ( V_675 , V_667 ) )
continue;
V_68 = ( V_670 + V_675 ) & ( V_677 - 1 ) ;
V_669 = F_223 ( V_598 , V_68 ) ;
V_671 = F_224 ( V_598 , V_68 ) ;
if ( V_18 == 0 ) {
F_103 ( & V_2 -> V_676 ) ;
F_21 ( V_48 , V_605 ,
V_688 ) ;
F_106 ( V_48 , V_607 ,
V_598 -> V_600 [ V_68 ] . V_602 ) ;
V_18 = F_9 ( V_2 , V_657 ,
V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_676 ) ;
}
if ( V_18 == 0 ) {
F_48 ( V_669 ) ;
V_669 = NULL ;
V_671 = 0 ;
} else {
V_671 &= ~ V_678 ;
}
F_225 ( V_598 , V_68 , V_669 ,
V_671 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_661 * V_677 + V_672 ;
F_240 ( & V_598 -> V_684 ) ;
V_681:
F_103 ( & V_2 -> V_676 ) ;
F_241 ( & V_598 -> V_684 , & V_673 ) ;
return V_18 ;
}
static void F_242 ( struct V_1 * V_2 )
{
}
static int F_243 ( struct V_1 * V_2 ,
unsigned int V_689 ,
T_6 V_690 , bool V_691 )
{
unsigned int V_599 = V_690 % V_677 ;
struct V_597 * V_598 = V_2 -> V_666 ;
F_8 ( V_48 ,
V_692 +
V_693 ) ;
struct V_581 * V_588 ;
F_232 ( V_673 ) ;
int V_18 ;
for (; ; ) {
F_105 ( & V_2 -> V_676 ) ;
if ( ! ( V_598 -> V_600 [ V_599 ] . V_588 &
V_678 ) )
break;
F_236 ( & V_598 -> V_684 , & V_673 , V_685 ) ;
F_103 ( & V_2 -> V_676 ) ;
F_237 () ;
}
V_588 = F_223 ( V_598 , V_599 ) ;
if ( ! V_588 ||
( ! V_691 &&
F_230 ( V_598 , V_588 -> V_584 ) !=
V_690 / V_677 ) ) {
V_18 = - V_102 ;
goto V_681;
}
if ( V_588 -> V_204 & V_686 &&
V_689 == ( 1U << V_680 ) ) {
V_588 -> V_204 &= ~ V_686 ;
V_598 -> V_600 [ V_599 ] . V_588 &= ~ V_687 ;
V_18 = 0 ;
goto V_681;
}
if ( ! ( V_689 & ( 1U << V_588 -> V_679 ) ) ) {
V_18 = - V_102 ;
goto V_681;
}
V_598 -> V_600 [ V_599 ] . V_588 |= V_678 ;
F_103 ( & V_2 -> V_676 ) ;
if ( V_588 -> V_204 & V_686 ) {
struct V_581 V_694 = * V_588 ;
V_694 . V_679 = V_680 ;
V_694 . V_204 = ( V_585 |
V_650 ) ;
V_694 . V_641 = 0 ;
V_694 . V_654 = V_655 ;
V_18 = F_228 ( V_2 , & V_694 ,
& V_598 -> V_600 [ V_599 ] . V_602 ,
true ) ;
F_105 ( & V_2 -> V_676 ) ;
if ( V_18 == 0 )
* V_588 = V_694 ;
} else {
F_21 ( V_48 , V_605 ,
F_219 ( V_588 ) ?
V_695 :
V_688 ) ;
F_106 ( V_48 , V_607 ,
V_598 -> V_600 [ V_599 ] . V_602 ) ;
V_18 = F_9 ( V_2 , V_657 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_676 ) ;
if ( V_18 == 0 ) {
F_48 ( V_588 ) ;
F_225 ( V_598 , V_599 , NULL , 0 ) ;
}
}
V_598 -> V_600 [ V_599 ] . V_588 &= ~ V_678 ;
F_240 ( & V_598 -> V_684 ) ;
V_681:
F_103 ( & V_2 -> V_676 ) ;
F_241 ( & V_598 -> V_684 , & V_673 ) ;
return V_18 ;
}
static int F_244 ( struct V_1 * V_2 ,
enum V_696 V_679 ,
T_6 V_690 )
{
return F_243 ( V_2 , 1U << V_679 ,
V_690 , false ) ;
}
static T_6 F_245 ( struct V_1 * V_2 , T_6 V_690 )
{
return V_690 % V_677 ;
}
static int F_246 ( struct V_1 * V_2 ,
enum V_696 V_679 ,
T_6 V_690 )
{
return F_243 ( V_2 , 1U << V_679 ,
V_690 , true ) ;
}
static int F_247 ( struct V_1 * V_2 ,
enum V_696 V_679 ,
T_6 V_690 , struct V_581 * V_588 )
{
unsigned int V_599 = V_690 % V_677 ;
struct V_597 * V_598 = V_2 -> V_666 ;
const struct V_581 * V_669 ;
int V_18 ;
F_105 ( & V_2 -> V_676 ) ;
V_669 = F_223 ( V_598 , V_599 ) ;
if ( V_669 && V_669 -> V_679 == V_679 &&
F_230 ( V_598 , V_669 -> V_584 ) ==
V_690 / V_677 ) {
* V_588 = * V_669 ;
V_18 = 0 ;
} else {
V_18 = - V_102 ;
}
F_103 ( & V_2 -> V_676 ) ;
return V_18 ;
}
static int F_248 ( struct V_1 * V_2 ,
enum V_696 V_679 )
{
unsigned int V_689 ;
unsigned int V_68 ;
int V_18 ;
V_689 = ( ( ( 1U << ( V_679 + 1 ) ) - 1 ) &
~ ( 1U << V_680 ) ) ;
for ( V_68 = 0 ; V_68 < V_677 ; V_68 ++ ) {
V_18 = F_243 ( V_2 , V_689 ,
V_68 , true ) ;
if ( V_18 && V_18 != - V_102 )
return V_18 ;
}
return 0 ;
}
static T_6 F_249 ( struct V_1 * V_2 ,
enum V_696 V_679 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
unsigned int V_599 ;
T_16 V_697 = 0 ;
F_105 ( & V_2 -> V_676 ) ;
for ( V_599 = 0 ; V_599 < V_677 ; V_599 ++ ) {
if ( V_598 -> V_600 [ V_599 ] . V_588 &&
F_223 ( V_598 , V_599 ) -> V_679 ==
V_679 )
++ V_697 ;
}
F_103 ( & V_2 -> V_676 ) ;
return V_697 ;
}
static T_6 F_250 ( struct V_1 * V_2 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
return V_598 -> V_662 * V_677 ;
}
static T_16 F_251 ( struct V_1 * V_2 ,
enum V_696 V_679 ,
T_6 * V_62 , T_6 V_698 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_581 * V_588 ;
unsigned int V_599 ;
T_16 V_697 = 0 ;
F_105 ( & V_2 -> V_676 ) ;
for ( V_599 = 0 ; V_599 < V_677 ; V_599 ++ ) {
V_588 = F_223 ( V_598 , V_599 ) ;
if ( V_588 && V_588 -> V_679 == V_679 ) {
if ( V_697 == V_698 ) {
V_697 = - V_699 ;
break;
}
V_62 [ V_697 ++ ] = ( F_230 (
V_598 , V_588 -> V_584 ) *
V_677 +
V_599 ) ;
}
}
F_103 ( & V_2 -> V_676 ) ;
return V_697 ;
}
static T_16 F_252 ( struct V_1 * V_2 ,
struct V_581 * V_588 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
F_8 ( V_48 , V_604 ) ;
struct V_581 * V_669 ;
unsigned int V_670 , V_68 , V_675 = 1 ;
bool V_603 = false ;
int V_672 = - 1 ;
T_7 V_471 ;
T_16 V_18 ;
F_253 ( V_588 -> V_204 !=
( V_585 | V_700 ) ) ;
F_253 ( V_588 -> V_679 != V_701 ) ;
F_253 ( F_233 ( V_588 ) ) ;
V_670 = F_217 ( V_588 ) ;
F_105 ( & V_2 -> V_676 ) ;
for (; ; ) {
V_68 = ( V_670 + V_675 ) & ( V_677 - 1 ) ;
V_669 = F_223 ( V_598 , V_68 ) ;
if ( ! V_669 ) {
if ( V_672 < 0 )
V_672 = V_68 ;
} else if ( F_215 ( V_588 , V_669 ) ) {
if ( V_598 -> V_600 [ V_68 ] . V_588 & V_678 ) {
V_18 = - V_169 ;
goto V_702;
}
if ( V_588 -> V_679 < V_669 -> V_679 ) {
V_18 = - V_98 ;
goto V_702;
}
V_672 = V_68 ;
break;
}
if ( V_675 == V_668 ) {
if ( V_672 < 0 ) {
V_18 = - V_169 ;
goto V_702;
}
break;
}
++ V_675 ;
}
V_669 = F_223 ( V_598 , V_672 ) ;
if ( V_669 ) {
V_603 = true ;
} else {
V_669 = F_238 ( sizeof( * V_588 ) , V_295 ) ;
if ( ! V_669 ) {
V_18 = - V_72 ;
goto V_702;
}
* V_669 = * V_588 ;
}
F_225 ( V_598 , V_672 , V_669 ,
V_678 ) ;
F_103 ( & V_2 -> V_676 ) ;
V_471 = V_603 << 31 | V_672 << 16 | V_588 -> V_641 ;
F_226 ( V_2 , V_588 , V_48 ,
V_598 -> V_600 [ V_672 ] . V_602 , V_603 ) ;
F_176 ( V_2 , V_657 , V_48 , sizeof( V_48 ) ,
V_656 ,
V_703 , V_471 ) ;
return V_672 ;
V_702:
F_103 ( & V_2 -> V_676 ) ;
return V_18 ;
}
static void
V_703 ( struct V_1 * V_2 , unsigned long V_471 ,
int V_18 , T_1 * V_13 ,
T_2 V_472 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
unsigned int V_672 , V_641 ;
struct V_581 * V_588 ;
bool V_603 ;
V_603 = V_471 >> 31 ;
V_672 = ( V_471 >> 16 ) & ( V_677 - 1 ) ;
V_641 = V_471 & 0xffff ;
F_105 ( & V_2 -> V_676 ) ;
V_588 = F_223 ( V_598 , V_672 ) ;
if ( V_18 == 0 ) {
V_598 -> V_600 [ V_672 ] . V_602 =
F_229 ( V_13 , V_658 ) ;
if ( V_603 )
V_588 -> V_641 = V_641 ;
} else if ( ! V_603 ) {
F_48 ( V_588 ) ;
V_588 = NULL ;
}
F_225 ( V_598 , V_672 , V_588 , 0 ) ;
F_103 ( & V_2 -> V_676 ) ;
F_240 ( & V_598 -> V_684 ) ;
}
static bool F_254 ( struct V_1 * V_2 , T_6 V_704 ,
unsigned int V_599 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_581 * V_588 =
F_223 ( V_598 , V_599 ) ;
F_8 ( V_48 ,
V_692 +
V_693 ) ;
if ( ! V_588 ||
( V_598 -> V_600 [ V_599 ] . V_588 & V_678 ) ||
V_588 -> V_679 != V_701 ||
! F_255 ( V_2 -> V_28 , V_588 -> V_641 ,
V_704 , V_599 ) )
return false ;
F_21 ( V_48 , V_605 ,
V_695 ) ;
F_106 ( V_48 , V_607 ,
V_598 -> V_600 [ V_599 ] . V_602 ) ;
if ( F_176 ( V_2 , V_657 , V_48 , sizeof( V_48 ) , 0 ,
V_705 , V_599 ) )
return false ;
V_598 -> V_600 [ V_599 ] . V_588 |= V_678 ;
return true ;
}
static void
V_705 ( struct V_1 * V_2 ,
unsigned long V_599 ,
int V_18 , T_1 * V_13 ,
T_2 V_472 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_581 * V_588 =
F_223 ( V_598 , V_599 ) ;
F_105 ( & V_2 -> V_676 ) ;
if ( V_18 == 0 ) {
F_48 ( V_588 ) ;
F_225 ( V_598 , V_599 , NULL , 0 ) ;
}
V_598 -> V_600 [ V_599 ] . V_588 &= ~ V_678 ;
F_240 ( & V_598 -> V_684 ) ;
F_103 ( & V_2 -> V_676 ) ;
}
static int F_256 ( T_6 V_706 )
{
int V_584 = 0 ;
#define F_257 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_257 ( V_707 , V_708 ) ;
F_257 ( V_707 , V_709 ) ;
F_257 ( V_614 , V_616 ) ;
F_257 ( V_617 , V_618 ) ;
F_257 ( V_619 , V_621 ) ;
F_257 ( V_622 , V_624 ) ;
F_257 ( V_625 , V_626 ) ;
F_257 ( V_627 , V_629 ) ;
F_257 ( V_630 , V_630 ) ;
F_257 ( V_631 , V_633 ) ;
F_257 ( V_634 , V_635 ) ;
F_257 ( V_636 , V_636 ) ;
#undef F_257
if ( V_706 )
return - V_215 ;
return V_584 ;
}
static int F_258 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_710 ) ;
F_8 ( V_13 , V_711 ) ;
unsigned int V_712 , V_713 ;
struct V_597 * V_598 ;
T_2 V_17 ;
int V_18 ;
V_598 = F_29 ( sizeof( * V_598 ) , V_71 ) ;
if ( ! V_598 )
return - V_72 ;
F_21 ( V_48 , V_714 ,
V_715 ) ;
V_18 = F_9 ( V_2 , V_716 ,
V_48 , sizeof( V_48 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_135;
V_713 = F_259 (
V_17 , V_717 ) ;
V_598 -> V_662 = 0 ;
for ( V_712 = 0 ; V_712 < V_713 ; V_712 ++ ) {
T_6 V_706 =
F_260 (
V_13 ,
V_717 ,
V_712 ) ;
V_18 = F_256 ( V_706 ) ;
if ( V_18 < 0 ) {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_54 ,
V_430 , V_706 , V_712 ) ;
} else {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_55 ,
V_430 , V_706 , V_712 ,
V_18 , V_598 -> V_662 ) ;
V_598 -> V_663 [ V_598 -> V_662 ++ ] = V_18 ;
}
}
V_598 -> V_600 = F_261 ( V_677 * sizeof( * V_598 -> V_600 ) ) ;
if ( ! V_598 -> V_600 ) {
V_18 = - V_72 ;
goto V_135;
}
V_598 -> V_718 = V_719 ;
V_598 -> V_720 = V_719 ;
V_598 -> V_721 = V_719 ;
V_2 -> V_666 = V_598 ;
F_262 ( & V_598 -> V_684 ) ;
return 0 ;
V_135:
F_48 ( V_598 ) ;
return V_18 ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_581 * V_588 ;
unsigned int V_599 ;
bool V_722 = false ;
int V_18 ;
F_22 ( ! F_264 ( & V_2 -> V_723 ) ) ;
if ( ! V_16 -> V_197 )
return;
if ( ! V_598 )
return;
F_105 ( & V_2 -> V_676 ) ;
for ( V_599 = 0 ; V_599 < V_677 ; V_599 ++ ) {
V_588 = F_223 ( V_598 , V_599 ) ;
if ( ! V_588 )
continue;
V_598 -> V_600 [ V_599 ] . V_588 |= V_678 ;
F_103 ( & V_2 -> V_676 ) ;
V_18 = F_228 ( V_2 , V_588 ,
& V_598 -> V_600 [ V_599 ] . V_602 ,
false ) ;
if ( V_18 )
V_722 = true ;
F_105 ( & V_2 -> V_676 ) ;
if ( V_18 ) {
F_48 ( V_588 ) ;
F_225 ( V_598 , V_599 , NULL , 0 ) ;
} else {
V_598 -> V_600 [ V_599 ] . V_588 &=
~ V_678 ;
}
}
F_103 ( & V_2 -> V_676 ) ;
if ( V_722 )
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_56 ) ;
else
V_16 -> V_197 = false ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
F_8 ( V_48 , V_604 ) ;
struct V_581 * V_588 ;
unsigned int V_599 ;
int V_18 ;
V_2 -> V_666 = NULL ;
if ( ! V_598 )
return;
for ( V_599 = 0 ; V_599 < V_677 ; V_599 ++ ) {
V_588 = F_223 ( V_598 , V_599 ) ;
if ( ! V_588 )
continue;
F_21 ( V_48 , V_605 ,
F_219 ( V_588 ) ?
V_695 :
V_688 ) ;
F_106 ( V_48 , V_607 ,
V_598 -> V_600 [ V_599 ] . V_602 ) ;
V_18 = F_9 ( V_2 , V_657 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_144 ( V_2 -> V_28 ,
L_57 ,
V_599 ,
V_598 -> V_600 [ V_599 ] . V_602 ) ;
F_48 ( V_588 ) ;
}
F_266 ( V_598 -> V_600 ) ;
F_48 ( V_598 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
unsigned int V_599 , V_68 ;
if ( ! V_598 )
return;
F_105 ( & V_2 -> V_676 ) ;
for ( V_68 = 0 ; V_68 < V_598 -> V_724 ; V_68 ++ )
F_268 ( V_598 -> V_725 [ V_68 ] . V_726 ) ;
for ( V_68 = 0 ; V_68 < V_598 -> V_727 ; V_68 ++ )
F_268 ( V_598 -> V_728 [ V_68 ] . V_726 ) ;
F_268 ( V_598 -> V_718 ) ;
F_268 ( V_598 -> V_720 ) ;
F_268 ( V_598 -> V_721 ) ;
F_103 ( & V_2 -> V_676 ) ;
}
static void F_269 ( struct V_1 * V_2 , bool * V_729 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_67 * V_28 = V_2 -> V_28 ;
struct V_730 * V_731 ;
int V_732 ;
unsigned int V_68 ;
V_598 -> V_718 = V_719 ;
V_732 = F_270 ( V_28 ) ;
if ( V_28 -> V_204 & V_733 )
* V_729 = true ;
V_598 -> V_724 = 1 + V_732 ;
F_18 ( V_598 -> V_725 [ 0 ] . V_281 , V_28 -> V_734 ) ;
V_68 = 1 ;
F_271 (uc, net_dev) {
if ( V_68 >= V_735 ) {
* V_729 = true ;
break;
}
F_18 ( V_598 -> V_725 [ V_68 ] . V_281 , V_731 -> V_281 ) ;
V_598 -> V_725 [ V_68 ] . V_726 = V_719 ;
V_68 ++ ;
}
}
static void F_272 ( struct V_1 * V_2 , bool * V_729 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_67 * V_28 = V_2 -> V_28 ;
struct V_730 * V_736 ;
unsigned int V_68 , V_732 ;
V_598 -> V_721 = V_719 ;
V_598 -> V_720 = V_719 ;
if ( V_28 -> V_204 & ( V_733 | V_737 ) )
* V_729 = true ;
V_732 = F_273 ( V_28 ) ;
V_68 = 0 ;
F_274 (mc, net_dev) {
if ( V_68 >= V_738 ) {
* V_729 = true ;
break;
}
F_18 ( V_598 -> V_728 [ V_68 ] . V_281 , V_736 -> V_281 ) ;
V_598 -> V_728 [ V_68 ] . V_726 = V_719 ;
V_68 ++ ;
}
V_598 -> V_727 = V_68 ;
}
static int F_275 ( struct V_1 * V_2 ,
bool V_256 , bool V_739 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_740 * V_741 ;
struct V_581 V_588 ;
T_3 V_742 [ V_743 ] ;
unsigned int V_68 , V_744 ;
int V_732 ;
int V_18 ;
if ( V_256 ) {
V_741 = V_598 -> V_728 ;
V_732 = V_598 -> V_727 ;
} else {
V_741 = V_598 -> V_725 ;
V_732 = V_598 -> V_724 ;
}
for ( V_68 = 0 ; V_68 < V_732 ; V_68 ++ ) {
F_276 ( & V_588 , V_680 ,
V_650 ,
0 ) ;
F_277 ( & V_588 , V_745 ,
V_741 [ V_68 ] . V_281 ) ;
V_18 = F_231 ( V_2 , & V_588 , true ) ;
if ( V_18 < 0 ) {
if ( V_739 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_58 ,
V_18 ) ;
for ( V_744 = 0 ; V_744 < V_68 ; V_744 ++ ) {
if ( V_741 [ V_744 ] . V_726 == V_719 )
continue;
F_246 (
V_2 , V_680 ,
V_741 [ V_744 ] . V_726 ) ;
V_741 [ V_744 ] . V_726 = V_719 ;
}
return V_18 ;
} else {
V_18 = V_719 ;
}
}
V_741 [ V_68 ] . V_726 = F_245 ( V_2 , V_18 ) ;
}
if ( V_256 && V_739 ) {
F_276 ( & V_588 , V_680 ,
V_650 ,
0 ) ;
F_278 ( V_742 ) ;
F_277 ( & V_588 , V_745 , V_742 ) ;
V_18 = F_231 ( V_2 , & V_588 , true ) ;
if ( V_18 < 0 ) {
F_163 ( V_2 , V_27 , V_2 -> V_28 ,
L_59 , V_18 ) ;
for ( V_744 = 0 ; V_744 < V_68 ; V_744 ++ ) {
if ( V_741 [ V_744 ] . V_726 == V_719 )
continue;
F_246 (
V_2 , V_680 ,
V_741 [ V_744 ] . V_726 ) ;
V_741 [ V_744 ] . V_726 = V_719 ;
}
return V_18 ;
} else {
V_598 -> V_720 = F_245 ( V_2 , V_18 ) ;
}
}
return 0 ;
}
static int F_279 ( struct V_1 * V_2 , bool V_256 ,
bool V_739 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_581 V_588 ;
T_3 V_742 [ V_743 ] ;
int V_18 ;
F_276 ( & V_588 , V_680 ,
V_650 ,
0 ) ;
if ( V_256 )
F_280 ( & V_588 ) ;
else
F_281 ( & V_588 ) ;
V_18 = F_231 ( V_2 , & V_588 , true ) ;
if ( V_18 < 0 ) {
F_163 ( V_2 , V_27 , V_2 -> V_28 ,
L_60 ,
V_256 ? L_61 : L_62 , V_18 ) ;
} else if ( V_256 ) {
V_598 -> V_721 = F_245 ( V_2 , V_18 ) ;
if ( ! V_16 -> V_500 ) {
F_276 ( & V_588 , V_680 ,
V_650 ,
0 ) ;
F_278 ( V_742 ) ;
F_277 ( & V_588 , V_745 ,
V_742 ) ;
V_18 = F_231 ( V_2 , & V_588 , true ) ;
if ( V_18 < 0 ) {
F_163 ( V_2 , V_27 , V_2 -> V_28 ,
L_59 ,
V_18 ) ;
if ( V_739 ) {
F_246 (
V_2 , V_680 ,
V_598 -> V_721 ) ;
V_598 -> V_721 = V_719 ;
return V_18 ;
}
} else {
V_598 -> V_720 = F_245 ( V_2 , V_18 ) ;
}
}
V_18 = 0 ;
} else {
V_598 -> V_718 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
bool V_746 = false ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_677 ; V_68 ++ ) {
if ( F_129 ( V_598 -> V_600 [ V_68 ] . V_588 ) &
V_687 ) {
if ( F_243 (
V_2 , 1U << V_680 ,
V_68 , true ) < 0 )
V_746 = true ;
}
}
F_22 ( V_746 ) ;
}
static int F_283 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_747 [ V_743 ] ;
int V_18 , V_748 ;
if ( F_284 ( V_16 -> V_749 ) )
return 0 ;
F_285 ( V_2 ) ;
F_286 ( V_2 -> V_28 ) ;
F_287 ( & V_2 -> V_723 ) ;
F_265 ( V_2 ) ;
F_288 ( & V_2 -> V_723 ) ;
V_18 = F_69 ( V_2 , V_16 -> V_80 ) ;
if ( V_18 )
goto V_750;
F_18 ( V_747 , V_16 -> V_749 ) ;
V_18 = F_71 ( V_2 , V_16 -> V_80 ,
V_16 -> V_749 ) ;
if ( V_18 )
goto V_751;
V_18 = F_70 ( V_2 , V_16 -> V_80 ,
V_2 -> V_28 -> V_734 ) ;
if ( ! V_18 ) {
F_18 ( V_16 -> V_749 , V_2 -> V_28 -> V_734 ) ;
} else {
V_748 = F_70 ( V_2 , V_16 -> V_80 , V_747 ) ;
if ( V_748 ) {
F_289 ( V_16 -> V_749 ) ;
goto V_752;
}
}
V_751:
V_748 = F_68 ( V_2 , V_16 -> V_80 ) ;
if ( V_748 )
goto V_752;
V_750:
F_287 ( & V_2 -> V_723 ) ;
V_748 = F_258 ( V_2 ) ;
F_288 ( & V_2 -> V_723 ) ;
if ( V_748 )
goto V_752;
V_748 = F_290 ( V_2 -> V_28 ) ;
if ( V_748 )
goto V_752;
F_291 ( V_2 -> V_28 ) ;
return V_18 ;
V_752:
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_63 ) ;
F_184 ( V_2 , V_203 ) ;
return V_18 ? V_18 : V_748 ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_597 * V_598 = V_2 -> V_666 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_67 * V_28 = V_2 -> V_28 ;
bool V_753 = false , V_754 = false ;
if ( ! F_293 ( V_2 ) )
return;
if ( ! V_598 )
return;
F_267 ( V_2 ) ;
F_294 ( V_28 ) ;
F_269 ( V_2 , & V_753 ) ;
F_272 ( V_2 , & V_754 ) ;
F_295 ( V_28 ) ;
if ( V_753 ) {
F_279 ( V_2 , false , false ) ;
F_275 ( V_2 , false , false ) ;
} else {
if ( F_275 ( V_2 , false , false ) )
F_279 ( V_2 , false , false ) ;
}
if ( V_16 -> V_500 && V_2 -> V_754 != V_754 )
F_282 ( V_2 ) ;
if ( V_754 ) {
if ( V_16 -> V_500 ) {
if ( F_279 ( V_2 , true , true ) ) {
F_282 ( V_2 ) ;
F_275 ( V_2 , true , false ) ;
}
} else {
F_279 ( V_2 , true , false ) ;
F_275 ( V_2 , true , false ) ;
}
} else {
if ( F_275 ( V_2 , true , true ) ) {
if ( V_16 -> V_500 )
F_282 ( V_2 ) ;
if ( F_279 ( V_2 , true , true ) )
F_275 ( V_2 , true , false ) ;
}
}
F_282 ( V_2 ) ;
V_2 -> V_754 = V_754 ;
}
static int F_296 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_755 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_756 = V_2 -> V_757 ;
int V_18 ;
F_285 ( V_2 ) ;
F_286 ( V_2 -> V_28 ) ;
F_287 ( & V_2 -> V_723 ) ;
F_265 ( V_2 ) ;
F_18 ( F_19 ( V_48 , V_758 ) ,
V_2 -> V_28 -> V_734 ) ;
F_21 ( V_48 , V_759 ,
V_16 -> V_80 ) ;
V_18 = F_51 ( V_2 , V_760 , V_48 ,
sizeof( V_48 ) , NULL , 0 , NULL ) ;
F_258 ( V_2 ) ;
F_288 ( & V_2 -> V_723 ) ;
if ( V_756 )
F_290 ( V_2 -> V_28 ) ;
F_291 ( V_2 -> V_28 ) ;
#ifdef F_44
if ( V_2 -> V_10 -> V_151 && V_2 -> V_10 -> V_103 ) {
struct V_10 * V_105 = V_2 -> V_10 -> V_103 ;
if ( V_18 == - V_98 ) {
struct V_1 * V_106 ;
V_106 = F_24 ( V_105 ) ;
V_18 = F_297 ( V_106 ,
V_16 -> V_22 ,
V_2 -> V_28 -> V_734 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_106 = F_24 ( V_105 ) ;
struct V_15 * V_16 = V_106 -> V_16 ;
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_106 -> V_199 ; ++ V_68 ) {
struct V_149 * V_150 = V_16 -> V_150 + V_68 ;
if ( V_150 -> V_2 == V_2 ) {
F_18 ( V_150 -> V_160 ,
V_2 -> V_28 -> V_734 ) ;
return 0 ;
}
}
}
} else
#endif
if ( V_18 == - V_98 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_64
L_65 ) ;
} else if ( V_18 == - V_101 && ! F_6 ( V_2 ) ) {
V_18 = F_283 ( V_2 ) ;
} else {
F_52 ( V_2 , V_760 ,
sizeof( V_48 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_298 ( struct V_1 * V_2 )
{
F_292 ( V_2 ) ;
return F_299 ( V_2 ) ;
}
static int F_300 ( struct V_1 * V_2 )
{
F_292 ( V_2 ) ;
return 0 ;
}
static int F_301 ( struct V_1 * V_2 , T_6 V_761 )
{
F_8 ( V_48 , V_762 ) ;
F_21 ( V_48 , V_763 , V_761 ) ;
return F_9 ( V_2 , V_764 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
}
static int F_302 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_765 ) ;
T_2 V_17 ;
T_6 V_766 ;
V_18 = F_9 ( V_2 , V_767 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_765 )
return - V_7 ;
V_766 = F_10 ( V_13 , V_768 ) ;
switch ( V_766 ) {
case V_769 :
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_66 ) ;
return 0 ;
case V_770 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_67 ) ;
return - V_7 ;
case V_771 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_68 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_69 , V_766 ) ;
return - V_7 ;
}
}
static int F_303 ( struct V_1 * V_2 , T_6 V_761 )
{
int V_18 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_70 , V_761 ) ;
V_18 = F_301 ( V_2 , V_761 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_302 ( V_2 ) ;
}
static int
F_304 ( struct V_1 * V_2 , struct V_772 * V_773 )
{
int V_18 , V_748 ;
F_305 ( V_2 , V_214 ) ;
V_18 = F_9 ( V_2 , V_774 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_304;
V_773 -> V_775 = F_303 ( V_2 , V_776 ) ? - 1 : 1 ;
V_773 -> V_777 = F_303 ( V_2 , V_778 ) ? - 1 : 1 ;
V_18 = F_35 ( V_2 , V_214 ) ;
V_304:
if ( V_18 == - V_98 )
V_18 = 0 ;
V_748 = F_306 ( V_2 , V_214 , V_18 == 0 ) ;
return V_18 ? V_18 : V_748 ;
}
static int F_307 ( struct V_1 * V_2 ,
struct V_779 * V_780 ,
unsigned int type )
{
F_8 ( V_48 , V_781 ) ;
F_8 ( V_13 , V_782 ) ;
const struct V_783 * V_784 ;
T_2 V_698 , V_785 , V_17 ;
bool V_786 ;
int V_18 ;
for ( V_784 = V_787 ; ; V_784 ++ ) {
if ( V_784 ==
V_787 + F_157 ( V_787 ) )
return - V_36 ;
if ( ( type & ~ V_784 -> V_788 ) == V_784 -> type )
break;
}
if ( V_784 -> V_789 != F_308 ( V_2 ) )
return - V_36 ;
V_18 = F_309 ( V_2 , type , & V_698 , & V_785 , & V_786 ) ;
if ( V_18 )
return V_18 ;
if ( V_786 )
return - V_36 ;
V_780 -> V_790 = type ;
F_21 ( V_48 , V_791 , type ) ;
V_18 = F_9 ( V_2 , V_792 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_793 )
return - V_7 ;
if ( F_10 ( V_13 , V_794 ) &
( 1 << V_795 ) )
V_780 -> V_796 = F_10 ( V_13 ,
V_797 ) ;
V_780 -> V_798 . V_799 = L_71 ;
V_780 -> V_798 . V_800 = V_784 -> V_237 ;
V_780 -> V_798 . V_801 . type = V_802 ;
V_780 -> V_798 . V_801 . V_204 = V_803 ;
V_780 -> V_798 . V_801 . V_698 = V_698 ;
V_780 -> V_798 . V_801 . V_804 = V_785 ;
return 0 ;
}
static int F_310 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_805 ) ;
struct V_779 * V_806 ;
T_2 V_17 , V_807 , V_68 , V_808 ;
unsigned int type ;
int V_18 ;
F_311 () ;
F_13 ( V_809 != 0 ) ;
V_18 = F_9 ( V_2 , V_810 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_811 )
return - V_7 ;
V_807 = F_10 ( V_13 , V_812 ) ;
if ( V_807 >
F_259 ( V_17 , V_813 ) )
return - V_7 ;
V_806 = F_312 ( V_807 , sizeof( * V_806 ) , V_71 ) ;
if ( ! V_806 )
return - V_72 ;
V_808 = 0 ;
for ( V_68 = 0 ; V_68 < V_807 ; V_68 ++ ) {
type = F_260 ( V_13 , V_813 ,
V_68 ) ;
V_18 = F_307 ( V_2 , & V_806 [ V_808 ] , type ) ;
if ( V_18 == 0 )
V_808 ++ ;
else if ( V_18 != - V_36 )
goto V_135;
}
V_18 = F_313 ( V_2 , & V_806 [ 0 ] . V_798 , V_808 , sizeof( * V_806 ) ) ;
V_135:
if ( V_18 )
F_48 ( V_806 ) ;
return V_18 ;
}
static void F_314 ( struct V_1 * V_2 , T_6 V_814 )
{
F_32 ( V_2 , F_33 ( V_814 ) , V_328 ) ;
}
static void F_315 ( struct V_1 * V_2 ,
T_6 V_814 ) {}
static int F_316 ( struct V_123 * V_124 ,
bool V_815 )
{
F_8 ( V_48 , V_816 ) ;
int V_18 ;
if ( V_124 -> V_817 == V_818 ||
V_124 -> V_817 == V_819 ||
( V_815 && V_124 -> V_817 == V_820 ) )
return 0 ;
V_124 -> V_817 = V_818 ;
F_21 ( V_48 , V_821 , V_822 ) ;
F_21 ( V_48 , V_823 , 0 ) ;
F_21 ( V_48 , V_824 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_825 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_124 -> V_817 = V_815 ? V_826 :
V_820 ;
return V_18 ;
}
static int F_317 ( struct V_123 * V_124 ,
bool V_815 )
{
F_8 ( V_48 , V_827 ) ;
int V_18 ;
if ( V_124 -> V_817 == V_820 ||
( V_815 && V_124 -> V_817 == V_826 ) )
return 0 ;
if ( V_124 -> V_817 == V_826 ) {
V_124 -> V_817 = V_820 ;
return 0 ;
}
V_124 -> V_817 = V_815 ? V_826 :
V_820 ;
F_21 ( V_48 , V_821 , V_828 ) ;
F_21 ( V_48 , V_823 , 0 ) ;
F_21 ( V_48 , V_829 ,
V_830 ) ;
F_21 ( V_48 , V_831 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_825 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_318 ( struct V_1 * V_2 , bool V_832 ,
bool V_815 )
{
int (* F_319)( struct V_123 * V_124 , bool V_815 );
struct V_123 * V_124 ;
F_319 = V_832 ?
F_316 :
F_317 ;
F_58 (channel, efx) {
int V_18 = F_319 ( V_124 , V_815 ) ;
if ( V_832 && V_18 != 0 ) {
F_318 ( V_2 , false , V_815 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_320 ( struct V_1 * V_2 ,
struct V_833 * V_834 )
{
return - V_319 ;
}
static int F_321 ( struct V_1 * V_2 ,
struct V_833 * V_834 )
{
int V_18 ;
switch ( V_834 -> V_835 ) {
case V_836 :
F_318 ( V_2 , false , false ) ;
return F_322 ( V_2 ,
V_834 -> V_837 != V_838 , 0 ) ;
case V_839 :
case V_840 :
case V_841 :
case V_842 :
case V_843 :
case V_844 :
case V_845 :
case V_846 :
case V_847 :
case V_848 :
case V_849 :
case V_850 :
case V_851 :
V_834 -> V_835 = V_839 ;
V_18 = F_322 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_318 ( V_2 , true , false ) ;
if ( V_18 )
F_322 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_42 ;
}
}
