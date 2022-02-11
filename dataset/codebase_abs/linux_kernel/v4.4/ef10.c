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
if ( V_18 == V_16 -> V_77 )
return 0 ;
V_16 -> V_77 = V_18 ;
F_124 ( V_2 ) ;
return - V_7 ;
}
static T_9 F_126 ( int V_330 , void * V_331 )
{
struct V_332 * V_333 = V_331 ;
struct V_1 * V_2 = V_333 -> V_2 ;
F_127 ( V_2 , V_334 , V_2 -> V_28 ,
L_25 , V_330 , F_128 () ) ;
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
L_26 V_344 L_27 ,
V_330 , F_128 () , F_133 ( V_3 ) ) ;
return V_338 ;
}
static void F_134 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_345 ) ;
F_13 ( V_346 != 0 ) ;
F_21 ( V_48 , V_347 , V_2 -> V_336 ) ;
( void ) F_9 ( V_2 , V_348 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
}
static int F_135 ( struct V_125 * V_126 )
{
return F_30 ( V_126 -> V_2 , & V_126 -> V_349 . V_62 ,
( V_126 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_71 ) ;
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
F_8 ( V_48 , F_140 ( V_357 * 8 /
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
F_141 ( V_48 , V_369 ,
V_370 , ! V_359 ,
V_371 , ! V_359 ) ;
F_21 ( V_48 , V_372 , 0 ) ;
F_21 ( V_48 , V_373 , V_16 -> V_80 ) ;
V_297 = V_126 -> V_349 . V_62 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_28 ,
V_126 -> V_140 , V_361 , ( T_7 ) V_297 ) ;
for ( V_68 = 0 ; V_68 < V_361 ; ++ V_68 ) {
F_142 ( V_48 , V_375 , V_68 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_140 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_376 , V_48 , V_363 ,
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
F_121 () ;
F_136 ( V_126 , V_349 ) ;
return;
V_135:
F_145 ( V_2 -> V_28 , L_29 ,
V_126 -> V_140 ) ;
}
static void F_146 ( struct V_125 * V_126 )
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
static void F_147 ( struct V_125 * V_126 )
{
F_47 ( V_126 -> V_2 , & V_126 -> V_349 . V_62 ) ;
}
static inline void F_148 ( struct V_125 * V_126 )
{
unsigned int V_352 ;
T_1 V_3 ;
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
F_149 ( V_3 , V_388 , V_352 ) ;
F_114 ( V_126 -> V_2 , & V_3 ,
V_389 , V_126 -> V_140 ) ;
}
static void F_150 ( struct V_125 * V_126 )
{
unsigned int V_390 = V_126 -> V_353 ;
struct V_391 * V_377 ;
unsigned int V_352 ;
V_351 * V_349 ;
V_126 -> V_392 = false ;
if ( F_151 ( V_126 -> V_353 == V_126 -> V_379 ) )
return;
do {
V_352 = V_126 -> V_353 & V_126 -> V_350 ;
V_377 = & V_126 -> V_377 [ V_352 ] ;
V_349 = F_143 ( V_126 , V_352 ) ;
++ V_126 -> V_353 ;
if ( V_377 -> V_204 & V_378 ) {
* V_349 = V_377 -> V_393 ;
} else {
F_13 ( V_394 != 1 ) ;
F_152 (
* V_349 ,
V_395 ,
V_377 -> V_204 & V_394 ,
V_396 , V_377 -> V_362 ,
V_397 , V_377 -> V_297 ) ;
}
} while ( V_126 -> V_353 != V_126 -> V_379 );
F_121 () ;
if ( F_153 ( V_126 , V_390 ) ) {
V_349 = F_143 ( V_126 ,
V_390 & V_126 -> V_350 ) ;
F_136 ( V_126 , V_349 ) ;
++ V_126 -> V_398 ;
} else {
F_148 ( V_126 ) ;
}
}
static int F_154 ( struct V_1 * V_2 , T_6 * V_333 ,
bool V_399 , unsigned * V_400 )
{
F_8 ( V_48 , V_401 ) ;
F_8 ( V_13 , V_402 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_6 V_403 = V_399 ?
V_404 :
V_405 ;
unsigned V_406 = V_399 ?
V_2 -> V_406 :
F_155 ( F_156 ( V_2 -> V_406 ) ,
V_407 ) ;
if ( ! V_399 && V_406 == 1 ) {
* V_333 = V_79 ;
if ( V_400 )
* V_400 = 1 ;
return 0 ;
}
F_21 ( V_48 , V_408 ,
V_16 -> V_80 ) ;
F_21 ( V_48 , V_409 , V_403 ) ;
F_21 ( V_48 , V_410 , V_406 ) ;
V_18 = F_9 ( V_2 , V_411 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_402 )
return - V_7 ;
* V_333 = F_10 ( V_13 , V_412 ) ;
if ( V_400 )
* V_400 = V_406 ;
return 0 ;
}
static void F_157 ( struct V_1 * V_2 , T_6 V_333 )
{
F_8 ( V_48 , V_413 ) ;
int V_18 ;
F_21 ( V_48 , V_414 ,
V_333 ) ;
V_18 = F_9 ( V_2 , V_415 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 != 0 ) ;
}
static int F_158 ( struct V_1 * V_2 , T_6 V_333 ,
const T_6 * V_196 )
{
F_8 ( V_416 , V_417 ) ;
F_8 ( V_418 , V_419 ) ;
int V_68 , V_18 ;
F_21 ( V_416 , V_420 ,
V_333 ) ;
F_13 ( F_159 ( V_2 -> V_196 ) !=
V_421 ) ;
for ( V_68 = 0 ; V_68 < F_159 ( V_2 -> V_196 ) ; ++ V_68 )
F_19 ( V_416 ,
V_422 ) [ V_68 ] =
( T_3 ) V_196 [ V_68 ] ;
V_18 = F_9 ( V_2 , V_423 , V_416 ,
sizeof( V_416 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_21 ( V_418 , V_424 ,
V_333 ) ;
F_13 ( F_159 ( V_2 -> V_425 ) !=
V_426 ) ;
for ( V_68 = 0 ; V_68 < F_159 ( V_2 -> V_425 ) ; ++ V_68 )
F_19 ( V_418 , V_427 ) [ V_68 ] =
V_2 -> V_425 [ V_68 ] ;
return F_9 ( V_2 , V_428 , V_418 ,
sizeof( V_418 ) , NULL , 0 , NULL ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_78 != V_79 )
F_157 ( V_2 , V_16 -> V_78 ) ;
V_16 -> V_78 = V_79 ;
}
static int F_160 ( struct V_1 * V_2 ,
unsigned * V_400 )
{
T_6 V_429 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_154 ( V_2 , & V_429 ,
false , V_400 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_78 = V_429 ;
V_16 -> V_430 = false ;
F_161 ( V_2 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 ,
const T_6 * V_196 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_429 ;
if ( V_16 -> V_78 == V_79 ||
! V_16 -> V_430 ) {
V_18 = F_154 ( V_2 , & V_429 ,
true , NULL ) ;
if ( V_18 == - V_319 )
return V_18 ;
else if ( V_18 != 0 )
goto V_75;
} else {
V_429 = V_16 -> V_78 ;
}
V_18 = F_158 ( V_2 , V_429 ,
V_196 ) ;
if ( V_18 != 0 )
goto V_76;
if ( V_16 -> V_78 != V_429 )
F_65 ( V_2 ) ;
V_16 -> V_78 = V_429 ;
V_16 -> V_430 = true ;
if ( V_196 != V_2 -> V_196 )
memcpy ( V_2 -> V_196 , V_196 ,
sizeof( V_2 -> V_196 ) ) ;
return 0 ;
V_76:
if ( V_429 != V_16 -> V_78 )
F_157 ( V_2 , V_429 ) ;
V_75:
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_30 , V_431 , V_18 ) ;
return V_18 ;
}
static int F_163 ( struct V_1 * V_2 , bool V_432 ,
const T_6 * V_196 )
{
int V_18 ;
if ( V_2 -> V_406 == 1 )
return 0 ;
V_18 = F_162 ( V_2 , V_196 ) ;
if ( V_18 == - V_147 && ! V_432 ) {
unsigned V_400 ;
bool V_433 = false ;
T_2 V_68 ;
for ( V_68 = 0 ; V_68 < F_159 ( V_2 -> V_196 ) && ! V_433 ;
V_68 ++ )
V_433 = V_196 [ V_68 ] !=
F_164 ( V_68 , V_2 -> V_406 ) ;
V_18 = F_160 ( V_2 , & V_400 ) ;
if ( V_18 == 0 ) {
if ( V_400 != V_2 -> V_406 )
F_165 ( V_2 , V_38 , V_2 -> V_28 ,
L_31
L_32
L_33
L_34 ,
V_2 -> V_406 , V_400 ) ;
else if ( V_433 )
F_165 ( V_2 , V_38 , V_2 -> V_28 ,
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
static int F_166 ( struct V_434 * V_435 )
{
return F_30 ( V_435 -> V_2 , & V_435 -> V_436 . V_62 ,
( V_435 -> V_350 + 1 ) *
sizeof( V_351 ) ,
V_71 ) ;
}
static void F_167 ( struct V_434 * V_435 )
{
F_8 ( V_48 ,
F_168 ( V_357 * 8 /
V_358 ) ) ;
struct V_123 * V_124 = F_169 ( V_435 ) ;
T_2 V_361 = V_435 -> V_436 . V_62 . V_362 / V_358 ;
struct V_1 * V_2 = V_435 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_363 ;
T_11 V_297 ;
int V_18 ;
int V_68 ;
F_13 ( V_437 != 0 ) ;
V_435 -> V_438 = 0 ;
V_435 -> V_439 = 0 ;
F_21 ( V_48 , V_440 , V_435 -> V_350 + 1 ) ;
F_21 ( V_48 , V_441 , V_124 -> V_124 ) ;
F_21 ( V_48 , V_442 , F_170 ( V_435 ) ) ;
F_21 ( V_48 , V_443 ,
F_170 ( V_435 ) ) ;
F_141 ( V_48 , V_444 ,
V_445 , 1 ,
V_446 , 1 ) ;
F_21 ( V_48 , V_447 , 0 ) ;
F_21 ( V_48 , V_448 , V_16 -> V_80 ) ;
V_297 = V_435 -> V_436 . V_62 . V_297 ;
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_39 ,
F_170 ( V_435 ) , V_361 , ( T_7 ) V_297 ) ;
for ( V_68 = 0 ; V_68 < V_361 ; ++ V_68 ) {
F_142 ( V_48 , V_449 , V_68 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_168 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_450 , V_48 , V_363 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_145 ( V_2 -> V_28 , L_40 ,
F_170 ( V_435 ) ) ;
}
static void F_171 ( struct V_434 * V_435 )
{
F_8 ( V_48 , V_451 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_435 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_452 ,
F_170 ( V_435 ) ) ;
V_18 = F_51 ( V_2 , V_453 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_109 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_453 , V_451 ,
V_13 , V_17 , V_18 ) ;
}
static void F_172 ( struct V_434 * V_435 )
{
F_47 ( V_435 -> V_2 , & V_435 -> V_436 . V_62 ) ;
}
static inline void
F_173 ( struct V_434 * V_435 , unsigned int V_128 )
{
struct V_454 * V_455 ;
V_351 * V_436 ;
V_436 = F_174 ( V_435 , V_128 ) ;
V_455 = V_454 ( V_435 , V_128 ) ;
F_175 ( * V_436 ,
V_456 , V_455 -> V_362 ,
V_457 , V_455 -> V_297 ) ;
}
static void F_176 ( struct V_434 * V_435 )
{
struct V_1 * V_2 = V_435 -> V_2 ;
unsigned int V_353 ;
T_1 V_3 ;
V_353 = V_435 -> V_458 & ~ 7 ;
if ( V_435 -> V_459 == V_353 )
return;
do
F_173 (
V_435 ,
V_435 -> V_459 & V_435 -> V_350 ) ;
while ( ++ V_435 -> V_459 != V_353 );
F_121 () ;
F_149 ( V_3 , V_460 ,
V_353 & V_435 -> V_350 ) ;
F_114 ( V_2 , & V_3 , V_461 ,
F_170 ( V_435 ) ) ;
}
static void F_177 ( struct V_434 * V_435 )
{
struct V_123 * V_124 = F_169 ( V_435 ) ;
F_8 ( V_48 , V_462 ) ;
V_351 V_463 ;
F_175 ( V_463 ,
V_464 , V_465 ,
V_466 , V_467 ) ;
F_21 ( V_48 , V_468 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_48 , V_469 ) , & V_463 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
F_178 ( V_124 -> V_2 , V_470 ,
V_48 , sizeof( V_48 ) , 0 ,
V_471 , 0 ) ;
}
static void
V_471 ( struct V_1 * V_2 , unsigned long V_472 ,
int V_18 , T_1 * V_13 ,
T_2 V_473 )
{
}
static int F_179 ( struct V_123 * V_124 )
{
return F_30 ( V_124 -> V_2 , & V_124 -> V_474 . V_62 ,
( V_124 -> V_475 + 1 ) *
sizeof( V_351 ) ,
V_71 ) ;
}
static void F_180 ( struct V_123 * V_124 )
{
F_8 ( V_48 , V_476 ) ;
F_50 ( V_13 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_48 , V_477 , V_124 -> V_124 ) ;
V_18 = F_51 ( V_2 , V_478 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_109 )
goto V_135;
return;
V_135:
F_52 ( V_2 , V_478 , V_476 ,
V_13 , V_17 , V_18 ) ;
}
static int F_181 ( struct V_123 * V_124 )
{
F_8 ( V_48 ,
F_182 ( V_479 * 8 /
V_358 ) ) ;
F_8 ( V_13 , V_480 ) ;
T_2 V_361 = V_124 -> V_474 . V_62 . V_362 / V_358 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_15 * V_16 ;
bool V_481 ;
T_2 V_363 , V_17 ;
unsigned int V_99 , V_482 ;
T_11 V_297 ;
int V_18 ;
int V_68 ;
V_16 = V_2 -> V_16 ;
V_481 =
! ! ( V_16 -> V_29 &
1 << V_483 ) ;
memset ( V_124 -> V_474 . V_62 . V_281 , 0xff , V_124 -> V_474 . V_62 . V_362 ) ;
F_21 ( V_48 , V_484 , V_124 -> V_475 + 1 ) ;
F_21 ( V_48 , V_485 , V_124 -> V_124 ) ;
F_21 ( V_48 , V_486 , V_124 -> V_124 ) ;
F_183 ( V_48 , V_487 ,
V_488 , 1 ,
V_489 , 1 ,
V_490 , 1 ,
V_491 , ! V_481 ) ;
F_21 ( V_48 , V_492 ,
V_493 ) ;
F_21 ( V_48 , V_494 , 0 ) ;
F_21 ( V_48 , V_495 , 0 ) ;
F_21 ( V_48 , V_496 ,
V_497 ) ;
F_21 ( V_48 , V_498 , 0 ) ;
V_297 = V_124 -> V_474 . V_62 . V_297 ;
for ( V_68 = 0 ; V_68 < V_361 ; ++ V_68 ) {
F_142 ( V_48 , V_499 , V_68 , V_297 ) ;
V_297 += V_358 ;
}
V_363 = F_182 ( V_361 ) ;
V_18 = F_9 ( V_2 , V_500 , V_48 , V_363 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_124 -> V_124 || V_18 )
return V_18 ;
V_18 = F_40 ( V_2 , & V_482 , & V_99 ) ;
if ( V_18 == - V_101 ) {
V_16 -> V_501 = false ;
V_18 = 0 ;
} else if ( V_18 ) {
goto V_135;
} else {
V_16 -> V_501 =
! ! ( V_99 & V_502 ) ;
if ( V_482 & V_502 &&
! V_16 -> V_501 ) {
unsigned int V_204 ;
V_18 = F_39 ( V_2 ,
V_503 ,
true , & V_204 ) ;
if ( ! V_18 ) {
if ( V_204 &
1 << V_504 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_41 ) ;
++ V_16 -> V_77 ;
}
V_16 -> V_501 = true ;
} else if ( V_18 == - V_98 ) {
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
F_47 ( V_124 -> V_2 , & V_124 -> V_474 . V_62 ) ;
}
static void F_185 ( struct V_434 * V_435 ,
unsigned int V_505 )
{
struct V_1 * V_2 = V_435 -> V_2 ;
F_62 ( V_2 , V_374 , V_2 -> V_28 ,
L_42 ,
F_170 ( V_435 ) , V_505 ) ;
F_186 ( V_2 , V_506 ) ;
}
static void
F_187 ( struct V_434 * V_435 ,
unsigned int V_507 , unsigned int V_508 )
{
unsigned int V_509 = ( V_507 - V_508 ) & V_435 -> V_350 ;
struct V_1 * V_2 = V_435 -> V_2 ;
F_62 ( V_2 , V_374 , V_2 -> V_28 ,
L_43 ,
V_509 , V_507 , V_508 ) ;
F_186 ( V_2 , V_506 ) ;
}
static void F_188 ( struct V_434 * V_435 )
{
unsigned int V_510 ;
F_41 ( V_435 -> V_2 , V_374 , V_435 -> V_2 -> V_28 ,
L_44 ,
V_435 -> V_438 ) ;
V_510 = V_435 -> V_511 & V_435 -> V_350 ;
F_189 ( V_435 , V_510 , V_435 -> V_438 ,
0 , V_512 ) ;
V_435 -> V_511 += V_435 -> V_438 ;
V_435 -> V_438 = 0 ;
V_435 -> V_439 = 0 ;
++ F_169 ( V_435 ) -> V_513 ;
}
static int F_190 ( struct V_123 * V_124 ,
const V_351 * V_463 )
{
unsigned int V_245 , V_514 , V_505 , V_515 ;
unsigned int V_516 , V_517 , V_68 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_434 * V_435 ;
bool V_518 ;
T_12 V_204 = 0 ;
if ( F_151 ( F_130 ( V_2 -> V_519 ) ) )
return 0 ;
V_245 = F_191 ( * V_463 , V_520 ) ;
V_514 = F_191 ( * V_463 , V_521 ) ;
V_505 = F_191 ( * V_463 , V_522 ) ;
V_515 = F_191 ( * V_463 , V_523 ) ;
V_518 = F_191 ( * V_463 , V_524 ) ;
if ( F_191 ( * V_463 , V_525 ) )
F_145 ( V_2 -> V_28 , L_45
V_526 L_27 ,
F_192 ( * V_463 ) ) ;
V_435 = F_193 ( V_124 ) ;
if ( F_151 ( V_505 != F_170 ( V_435 ) ) )
F_185 ( V_435 , V_505 ) ;
V_516 = ( ( V_514 - V_435 -> V_511 ) &
( ( 1 << V_527 ) - 1 ) ) ;
if ( V_516 != V_435 -> V_438 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_151 ( V_516 == V_435 -> V_438 ) ) {
if ( V_435 -> V_438 == 0 || V_245 != 0 )
F_145 ( V_2 -> V_28 ,
L_46
V_526 L_27 ,
V_435 -> V_438 ,
F_192 ( * V_463 ) ) ;
F_188 ( V_435 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_29 &
( 1 << V_483 ) ) ||
V_435 -> V_438 != 0 || V_518 ) {
F_187 (
V_435 , V_514 ,
( V_435 -> V_511 +
V_435 -> V_438 + 1 ) &
( ( 1 << V_527 ) - 1 ) ) ;
return 0 ;
}
V_435 -> V_438 = 1 ;
V_435 -> V_439 = 0 ;
V_517 = V_516 ;
++ V_124 -> V_528 ;
V_124 -> V_529 += V_517 ;
V_204 |= V_530 ;
} else {
++ V_435 -> V_438 ;
V_435 -> V_439 += V_245 ;
if ( V_518 )
return 0 ;
V_517 = 1 ;
}
if ( F_151 ( F_191 ( * V_463 , V_531 ) ) )
V_204 |= V_512 ;
if ( F_151 ( F_191 ( * V_463 , V_532 ) ) ) {
V_124 -> V_533 += V_517 ;
} else if ( F_151 ( F_191 ( * V_463 ,
V_534 ) ) ) {
V_124 -> V_535 += V_517 ;
} else if ( V_515 == V_536 ||
V_515 == V_537 ) {
V_204 |= V_538 ;
}
if ( V_515 == V_536 )
V_204 |= V_539 ;
V_124 -> V_540 += 2 * V_517 ;
for ( V_68 = 0 ; V_68 < V_517 ; V_68 ++ ) {
F_189 ( V_435 ,
V_435 -> V_511 & V_435 -> V_350 ,
V_435 -> V_438 , V_435 -> V_439 ,
V_204 ) ;
V_435 -> V_511 += V_435 -> V_438 ;
}
V_435 -> V_438 = 0 ;
V_435 -> V_439 = 0 ;
return V_517 ;
}
static int
F_194 ( struct V_123 * V_124 , V_351 * V_463 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_125 * V_126 ;
unsigned int V_541 ;
unsigned int V_542 ;
int V_543 = 0 ;
if ( F_151 ( F_130 ( V_2 -> V_519 ) ) )
return 0 ;
if ( F_151 ( F_191 ( * V_463 , V_544 ) ) )
return 0 ;
V_541 = F_191 ( * V_463 , V_545 ) ;
V_542 = F_191 ( * V_463 , V_546 ) ;
V_126 = F_195 ( V_124 ,
V_542 % V_184 ) ;
V_543 = ( ( V_541 + 1 - V_126 -> V_547 ) &
V_126 -> V_350 ) ;
F_196 ( V_126 , V_541 & V_126 -> V_350 ) ;
return V_543 ;
}
static void
F_197 ( struct V_123 * V_124 , V_351 * V_463 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
int V_548 ;
V_548 = F_191 ( * V_463 , V_549 ) ;
switch ( V_548 ) {
case V_550 :
case V_551 :
break;
case V_552 :
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_47
L_48 V_526 L_49 ,
V_124 -> V_124 , V_548 ,
F_192 ( * V_463 ) ) ;
}
}
static void F_198 ( struct V_123 * V_124 ,
V_351 * V_463 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_6 V_548 ;
V_548 = F_191 ( * V_463 , V_553 ) ;
switch ( V_548 ) {
case V_554 :
V_124 -> V_555 = F_128 () ;
break;
case V_467 :
F_199 ( & V_124 -> V_435 , true ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_50
L_48 V_526 L_49 ,
V_124 -> V_124 , ( unsigned ) V_548 ,
F_192 ( * V_463 ) ) ;
}
}
static int F_200 ( struct V_123 * V_124 , int V_556 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_463 , * V_557 ;
unsigned int V_558 ;
int V_559 ;
int V_543 = 0 ;
int V_560 = 0 ;
if ( V_556 <= 0 )
return V_560 ;
V_558 = V_124 -> V_561 ;
for (; ; ) {
V_557 = F_201 ( V_124 , V_558 ) ;
V_463 = * V_557 ;
if ( ! F_202 ( & V_463 ) )
break;
F_203 ( * V_557 ) ;
++ V_558 ;
V_559 = F_191 ( V_463 , V_464 ) ;
F_127 ( V_2 , V_27 , V_2 -> V_28 ,
L_51 V_526 L_27 ,
V_124 -> V_124 , F_192 ( V_463 ) ) ;
switch ( V_559 ) {
case V_562 :
F_204 ( V_124 , & V_463 ) ;
break;
case V_563 :
V_560 += F_190 ( V_124 , & V_463 ) ;
if ( V_560 >= V_556 ) {
V_560 = V_556 ;
goto V_304;
}
break;
case V_564 :
V_543 += F_194 ( V_124 , & V_463 ) ;
if ( V_543 > V_2 -> V_565 ) {
V_560 = V_556 ;
goto V_304;
} else if ( ++ V_560 == V_556 ) {
goto V_304;
}
break;
case V_566 :
F_197 ( V_124 , & V_463 ) ;
if ( ++ V_560 == V_556 )
goto V_304;
break;
case V_465 :
F_198 ( V_124 , & V_463 ) ;
break;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_52
L_48 V_526 L_49 ,
V_124 -> V_124 , V_559 ,
F_192 ( V_463 ) ) ;
}
}
V_304:
V_124 -> V_561 = V_558 ;
return V_560 ;
}
static void F_205 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
T_1 V_567 ;
if ( F_112 ( V_2 ) ) {
F_13 ( V_568 <
( 1 << V_569 ) ) ;
F_13 ( V_479 >
( 1 << 2 * V_569 ) ) ;
F_115 ( V_567 , V_570 ,
V_571 ,
V_572 ,
( V_124 -> V_561 &
V_124 -> V_475 ) >>
V_569 ) ;
F_114 ( V_2 , & V_567 , V_313 ,
V_124 -> V_124 ) ;
F_115 ( V_567 , V_570 ,
V_573 ,
V_572 ,
V_124 -> V_561 &
( ( 1 << V_569 ) - 1 ) ) ;
F_114 ( V_2 , & V_567 , V_313 ,
V_124 -> V_124 ) ;
} else {
F_149 ( V_567 , V_574 ,
V_124 -> V_561 &
V_124 -> V_475 ) ;
F_114 ( V_2 , & V_567 , V_575 , V_124 -> V_124 ) ;
}
}
static void F_206 ( struct V_123 * V_124 )
{
F_8 ( V_48 , V_462 ) ;
struct V_1 * V_2 = V_124 -> V_2 ;
V_351 V_463 ;
int V_18 ;
F_175 ( V_463 ,
V_464 , V_465 ,
V_466 , V_554 ) ;
F_21 ( V_48 , V_468 , V_124 -> V_124 ) ;
memcpy ( F_19 ( V_48 , V_469 ) , & V_463 . T_7 [ 0 ] ,
sizeof( V_351 ) ) ;
V_18 = F_9 ( V_2 , V_470 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_135;
return;
V_135:
F_22 ( true ) ;
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_30 , V_431 , V_18 ) ;
}
void F_207 ( struct V_1 * V_2 )
{
if ( F_208 ( & V_2 -> V_303 ) )
F_209 ( & V_2 -> V_576 ) ;
F_22 ( F_108 ( & V_2 -> V_303 ) < 0 ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
struct V_434 * V_435 ;
int V_577 ;
if ( V_16 -> V_194 ) {
F_211 ( & V_2 -> V_303 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_578 != V_579 ) {
F_58 (channel, efx) {
F_212 (rx_queue, channel)
F_171 ( V_435 ) ;
F_59 (tx_queue, channel)
F_146 ( V_126 ) ;
}
F_213 ( V_2 -> V_576 ,
F_108 ( & V_2 -> V_303 ) == 0 ,
F_214 ( V_580 ) ) ;
V_577 = F_108 ( & V_2 -> V_303 ) ;
if ( V_577 ) {
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_53 ,
V_577 ) ;
return - V_581 ;
}
}
return 0 ;
}
static void F_215 ( struct V_1 * V_2 )
{
F_211 ( & V_2 -> V_303 , 0 ) ;
}
static bool F_216 ( const struct V_582 * V_583 ,
const struct V_582 * V_584 )
{
if ( ( V_583 -> V_585 ^ V_584 -> V_585 ) |
( ( V_583 -> V_204 ^ V_584 -> V_204 ) &
( V_586 | V_587 ) ) )
return false ;
return memcmp ( & V_583 -> V_588 , & V_584 -> V_588 ,
sizeof( struct V_582 ) -
F_217 ( struct V_582 , V_588 ) ) == 0 ;
}
static unsigned int F_218 ( const struct V_582 * V_589 )
{
F_13 ( F_217 ( struct V_582 , V_588 ) & 3 ) ;
return F_219 ( ( const T_6 * ) & V_589 -> V_588 ,
( sizeof( struct V_582 ) -
F_217 ( struct V_582 , V_588 ) ) / 4 ,
0 ) ;
}
static bool F_220 ( const struct V_582 * V_589 )
{
if ( V_589 -> V_585 & V_590 &&
! F_221 ( V_589 -> V_591 ) )
return true ;
if ( ( V_589 -> V_585 &
( V_592 | V_593 ) ) ==
( V_592 | V_593 ) ) {
if ( V_589 -> V_594 == F_222 ( V_595 ) &&
! F_223 ( V_589 -> V_596 [ 0 ] ) )
return true ;
if ( V_589 -> V_594 == F_222 ( V_597 ) &&
( ( const T_3 * ) V_589 -> V_596 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_582 *
F_224 ( const struct V_598 * V_599 ,
unsigned int V_600 )
{
return (struct V_582 * ) ( V_599 -> V_601 [ V_600 ] . V_589 &
~ V_602 ) ;
}
static unsigned int
F_225 ( const struct V_598 * V_599 ,
unsigned int V_600 )
{
return V_599 -> V_601 [ V_600 ] . V_589 & V_602 ;
}
static void
F_226 ( struct V_598 * V_599 ,
unsigned int V_600 ,
const struct V_582 * V_589 ,
unsigned int V_204 )
{
V_599 -> V_601 [ V_600 ] . V_589 = ( unsigned long ) V_589 | V_204 ;
}
static void F_227 ( struct V_1 * V_2 ,
const struct V_582 * V_589 ,
T_1 * V_48 , T_7 V_603 ,
bool V_604 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
memset ( V_48 , 0 , V_605 ) ;
if ( V_604 ) {
F_21 ( V_48 , V_606 ,
V_607 ) ;
F_106 ( V_48 , V_608 , V_603 ) ;
} else {
T_6 V_609 = 0 ;
F_21 ( V_48 , V_606 ,
F_220 ( V_589 ) ?
V_610 :
V_611 ) ;
if ( V_589 -> V_585 & V_612 )
V_609 |=
F_221 ( V_589 -> V_591 ) ?
1 << V_613 :
1 << V_614 ;
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
F_228 ( V_615 , V_616 , V_617 ) ;
F_228 ( V_618 , V_596 , V_619 ) ;
F_228 ( V_620 , V_621 , V_622 ) ;
F_228 ( V_623 , V_624 , V_625 ) ;
F_228 ( V_626 , V_591 , V_627 ) ;
F_228 ( V_628 , V_629 , V_630 ) ;
F_228 ( V_631 , V_594 , V_631 ) ;
F_228 ( V_632 , V_633 , V_634 ) ;
F_228 ( V_635 , V_588 , V_636 ) ;
F_228 ( V_637 , V_638 , V_637 ) ;
#undef F_228
F_21 ( V_48 , V_639 ,
V_609 ) ;
}
F_21 ( V_48 , V_640 , V_16 -> V_80 ) ;
F_21 ( V_48 , V_641 ,
V_589 -> V_642 == V_643 ?
V_644 :
V_645 ) ;
F_21 ( V_48 , V_646 , 0 ) ;
F_21 ( V_48 , V_647 ,
V_648 ) ;
F_21 ( V_48 , V_649 ,
V_589 -> V_642 == V_643 ?
0 : V_589 -> V_642 ) ;
F_21 ( V_48 , V_650 ,
( V_589 -> V_204 & V_651 ) ?
V_652 :
V_653 ) ;
if ( V_589 -> V_204 & V_651 )
F_21 ( V_48 , V_654 ,
V_589 -> V_655 !=
V_656 ?
V_589 -> V_655 : V_16 -> V_78 ) ;
}
static int F_229 ( struct V_1 * V_2 ,
const struct V_582 * V_589 ,
T_7 * V_603 , bool V_604 )
{
F_8 ( V_48 , V_605 ) ;
F_8 ( V_13 , V_657 ) ;
int V_18 ;
F_227 ( V_2 , V_589 , V_48 , * V_603 , V_604 ) ;
V_18 = F_9 ( V_2 , V_658 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_603 = F_230 ( V_13 , V_659 ) ;
if ( V_18 == - V_660 )
V_18 = - V_169 ;
return V_18 ;
}
static int F_231 ( struct V_598 * V_599 ,
enum V_661 V_585 )
{
unsigned int V_662 ;
for ( V_662 = 0 ;
V_662 < V_599 -> V_663 ;
V_662 ++ )
if ( V_599 -> V_664 [ V_662 ] == V_585 )
return V_662 ;
return - V_665 ;
}
static T_16 F_232 ( struct V_1 * V_2 ,
struct V_582 * V_589 ,
bool V_666 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
F_90 ( V_668 , V_669 ) ;
struct V_582 * V_670 ;
unsigned int V_662 , V_671 ;
unsigned int V_672 ;
bool V_604 = false ;
int V_673 = - 1 ;
F_233 ( V_674 ) ;
bool V_675 ;
T_16 V_18 ;
if ( ( V_589 -> V_204 & ( V_586 | V_587 ) ) !=
V_586 )
return - V_215 ;
V_18 = F_231 ( V_599 , V_589 -> V_585 ) ;
if ( V_18 < 0 )
return V_18 ;
V_662 = V_18 ;
V_671 = F_218 ( V_589 ) ;
V_675 = F_234 ( V_589 ) ;
if ( V_675 )
F_235 ( V_668 , V_669 ) ;
for (; ; ) {
unsigned int V_676 = 1 ;
unsigned int V_68 ;
F_105 ( & V_2 -> V_677 ) ;
for (; ; ) {
V_68 = ( V_671 + V_676 ) & ( V_678 - 1 ) ;
V_670 = F_224 ( V_599 , V_68 ) ;
if ( ! V_670 ) {
if ( V_673 < 0 )
V_673 = V_68 ;
} else if ( F_216 ( V_589 , V_670 ) ) {
if ( V_599 -> V_601 [ V_68 ] . V_589 &
V_679 )
break;
if ( V_589 -> V_680 < V_670 -> V_680 &&
V_589 -> V_680 != V_681 ) {
V_18 = - V_98 ;
goto V_682;
}
if ( ! V_675 ) {
if ( V_589 -> V_680 ==
V_670 -> V_680 &&
! V_666 ) {
V_18 = - V_683 ;
goto V_682;
}
V_673 = V_68 ;
goto V_684;
} else if ( V_589 -> V_680 >
V_670 -> V_680 ||
( V_589 -> V_680 ==
V_670 -> V_680 &&
V_666 ) ) {
if ( V_673 < 0 )
V_673 = V_68 ;
else
F_236 ( V_676 , V_668 ) ;
}
}
if ( V_676 == V_669 ) {
if ( V_673 < 0 ) {
V_18 = - V_169 ;
goto V_682;
}
goto V_684;
}
++ V_676 ;
}
F_237 ( & V_599 -> V_685 , & V_674 , V_686 ) ;
F_103 ( & V_2 -> V_677 ) ;
F_238 () ;
}
V_684:
V_670 = F_224 ( V_599 , V_673 ) ;
if ( V_670 ) {
if ( V_589 -> V_680 == V_681 &&
V_670 -> V_680 >= V_681 ) {
if ( V_670 -> V_680 > V_681 )
V_670 -> V_204 |= V_687 ;
V_599 -> V_601 [ V_673 ] . V_589 &=
~ V_688 ;
V_18 = V_673 ;
goto V_682;
}
V_604 = true ;
V_672 = F_225 ( V_599 , V_673 ) ;
} else {
V_670 = F_239 ( sizeof( * V_589 ) , V_295 ) ;
if ( ! V_670 ) {
V_18 = - V_72 ;
goto V_682;
}
* V_670 = * V_589 ;
V_672 = 0 ;
}
F_226 ( V_599 , V_673 , V_670 ,
V_672 | V_679 ) ;
if ( V_675 ) {
unsigned int V_676 , V_68 ;
for ( V_676 = 0 ; V_676 < V_669 ; V_676 ++ ) {
V_68 = ( V_671 + V_676 ) & ( V_678 - 1 ) ;
if ( F_240 ( V_676 , V_668 ) )
V_599 -> V_601 [ V_68 ] . V_589 |=
V_679 ;
}
}
F_103 ( & V_2 -> V_677 ) ;
V_18 = F_229 ( V_2 , V_589 , & V_599 -> V_601 [ V_673 ] . V_603 ,
V_604 ) ;
F_105 ( & V_2 -> V_677 ) ;
if ( V_18 == 0 ) {
if ( V_604 ) {
if ( V_670 -> V_680 == V_681 )
V_670 -> V_204 |=
V_687 ;
V_670 -> V_680 = V_589 -> V_680 ;
V_670 -> V_204 &= V_687 ;
V_670 -> V_204 |= V_589 -> V_204 ;
V_670 -> V_655 = V_589 -> V_655 ;
V_670 -> V_642 = V_589 -> V_642 ;
}
} else if ( ! V_604 ) {
F_48 ( V_670 ) ;
V_670 = NULL ;
}
F_226 ( V_599 , V_673 , V_670 , V_672 ) ;
if ( V_675 ) {
F_8 ( V_48 , V_605 ) ;
unsigned int V_676 , V_68 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
for ( V_676 = 0 ; V_676 < V_669 ; V_676 ++ ) {
if ( ! F_240 ( V_676 , V_668 ) )
continue;
V_68 = ( V_671 + V_676 ) & ( V_678 - 1 ) ;
V_670 = F_224 ( V_599 , V_68 ) ;
V_672 = F_225 ( V_599 , V_68 ) ;
if ( V_18 == 0 ) {
F_103 ( & V_2 -> V_677 ) ;
F_21 ( V_48 , V_606 ,
V_689 ) ;
F_106 ( V_48 , V_608 ,
V_599 -> V_601 [ V_68 ] . V_603 ) ;
V_18 = F_9 ( V_2 , V_658 ,
V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_677 ) ;
}
if ( V_18 == 0 ) {
F_48 ( V_670 ) ;
V_670 = NULL ;
V_672 = 0 ;
} else {
V_672 &= ~ V_679 ;
}
F_226 ( V_599 , V_68 , V_670 ,
V_672 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_662 * V_678 + V_673 ;
F_241 ( & V_599 -> V_685 ) ;
V_682:
F_103 ( & V_2 -> V_677 ) ;
F_242 ( & V_599 -> V_685 , & V_674 ) ;
return V_18 ;
}
static void F_243 ( struct V_1 * V_2 )
{
}
static int F_244 ( struct V_1 * V_2 ,
unsigned int V_690 ,
T_6 V_691 , bool V_692 )
{
unsigned int V_600 = V_691 % V_678 ;
struct V_598 * V_599 = V_2 -> V_667 ;
F_8 ( V_48 ,
V_693 +
V_694 ) ;
struct V_582 * V_589 ;
F_233 ( V_674 ) ;
int V_18 ;
for (; ; ) {
F_105 ( & V_2 -> V_677 ) ;
if ( ! ( V_599 -> V_601 [ V_600 ] . V_589 &
V_679 ) )
break;
F_237 ( & V_599 -> V_685 , & V_674 , V_686 ) ;
F_103 ( & V_2 -> V_677 ) ;
F_238 () ;
}
V_589 = F_224 ( V_599 , V_600 ) ;
if ( ! V_589 ||
( ! V_692 &&
F_231 ( V_599 , V_589 -> V_585 ) !=
V_691 / V_678 ) ) {
V_18 = - V_102 ;
goto V_682;
}
if ( V_589 -> V_204 & V_687 &&
V_690 == ( 1U << V_681 ) ) {
V_589 -> V_204 &= ~ V_687 ;
V_599 -> V_601 [ V_600 ] . V_589 &= ~ V_688 ;
V_18 = 0 ;
goto V_682;
}
if ( ! ( V_690 & ( 1U << V_589 -> V_680 ) ) ) {
V_18 = - V_102 ;
goto V_682;
}
V_599 -> V_601 [ V_600 ] . V_589 |= V_679 ;
F_103 ( & V_2 -> V_677 ) ;
if ( V_589 -> V_204 & V_687 ) {
struct V_582 V_695 = * V_589 ;
V_695 . V_680 = V_681 ;
V_695 . V_204 = ( V_586 |
( F_245 ( V_2 ) ?
V_651 : 0 ) ) ;
V_695 . V_642 = 0 ;
V_695 . V_655 = V_656 ;
V_18 = F_229 ( V_2 , & V_695 ,
& V_599 -> V_601 [ V_600 ] . V_603 ,
true ) ;
F_105 ( & V_2 -> V_677 ) ;
if ( V_18 == 0 )
* V_589 = V_695 ;
} else {
F_21 ( V_48 , V_606 ,
F_220 ( V_589 ) ?
V_696 :
V_689 ) ;
F_106 ( V_48 , V_608 ,
V_599 -> V_601 [ V_600 ] . V_603 ) ;
V_18 = F_9 ( V_2 , V_658 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
F_105 ( & V_2 -> V_677 ) ;
if ( V_18 == 0 ) {
F_48 ( V_589 ) ;
F_226 ( V_599 , V_600 , NULL , 0 ) ;
}
}
V_599 -> V_601 [ V_600 ] . V_589 &= ~ V_679 ;
F_241 ( & V_599 -> V_685 ) ;
V_682:
F_103 ( & V_2 -> V_677 ) ;
F_242 ( & V_599 -> V_685 , & V_674 ) ;
return V_18 ;
}
static int F_246 ( struct V_1 * V_2 ,
enum V_697 V_680 ,
T_6 V_691 )
{
return F_244 ( V_2 , 1U << V_680 ,
V_691 , false ) ;
}
static T_6 F_247 ( struct V_1 * V_2 , T_6 V_691 )
{
return V_691 % V_678 ;
}
static int F_248 ( struct V_1 * V_2 ,
enum V_697 V_680 ,
T_6 V_691 )
{
return F_244 ( V_2 , 1U << V_680 ,
V_691 , true ) ;
}
static int F_249 ( struct V_1 * V_2 ,
enum V_697 V_680 ,
T_6 V_691 , struct V_582 * V_589 )
{
unsigned int V_600 = V_691 % V_678 ;
struct V_598 * V_599 = V_2 -> V_667 ;
const struct V_582 * V_670 ;
int V_18 ;
F_105 ( & V_2 -> V_677 ) ;
V_670 = F_224 ( V_599 , V_600 ) ;
if ( V_670 && V_670 -> V_680 == V_680 &&
F_231 ( V_599 , V_670 -> V_585 ) ==
V_691 / V_678 ) {
* V_589 = * V_670 ;
V_18 = 0 ;
} else {
V_18 = - V_102 ;
}
F_103 ( & V_2 -> V_677 ) ;
return V_18 ;
}
static int F_250 ( struct V_1 * V_2 ,
enum V_697 V_680 )
{
unsigned int V_690 ;
unsigned int V_68 ;
int V_18 ;
V_690 = ( ( ( 1U << ( V_680 + 1 ) ) - 1 ) &
~ ( 1U << V_681 ) ) ;
for ( V_68 = 0 ; V_68 < V_678 ; V_68 ++ ) {
V_18 = F_244 ( V_2 , V_690 ,
V_68 , true ) ;
if ( V_18 && V_18 != - V_102 )
return V_18 ;
}
return 0 ;
}
static T_6 F_251 ( struct V_1 * V_2 ,
enum V_697 V_680 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
unsigned int V_600 ;
T_16 V_698 = 0 ;
F_105 ( & V_2 -> V_677 ) ;
for ( V_600 = 0 ; V_600 < V_678 ; V_600 ++ ) {
if ( V_599 -> V_601 [ V_600 ] . V_589 &&
F_224 ( V_599 , V_600 ) -> V_680 ==
V_680 )
++ V_698 ;
}
F_103 ( & V_2 -> V_677 ) ;
return V_698 ;
}
static T_6 F_252 ( struct V_1 * V_2 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
return V_599 -> V_663 * V_678 ;
}
static T_16 F_253 ( struct V_1 * V_2 ,
enum V_697 V_680 ,
T_6 * V_62 , T_6 V_699 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_582 * V_589 ;
unsigned int V_600 ;
T_16 V_698 = 0 ;
F_105 ( & V_2 -> V_677 ) ;
for ( V_600 = 0 ; V_600 < V_678 ; V_600 ++ ) {
V_589 = F_224 ( V_599 , V_600 ) ;
if ( V_589 && V_589 -> V_680 == V_680 ) {
if ( V_698 == V_699 ) {
V_698 = - V_700 ;
break;
}
V_62 [ V_698 ++ ] = ( F_231 (
V_599 , V_589 -> V_585 ) *
V_678 +
V_600 ) ;
}
}
F_103 ( & V_2 -> V_677 ) ;
return V_698 ;
}
static T_16 F_254 ( struct V_1 * V_2 ,
struct V_582 * V_589 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
F_8 ( V_48 , V_605 ) ;
struct V_582 * V_670 ;
unsigned int V_671 , V_68 , V_676 = 1 ;
bool V_604 = false ;
int V_673 = - 1 ;
T_7 V_472 ;
T_16 V_18 ;
F_255 ( V_589 -> V_204 !=
( V_586 | V_701 ) ) ;
F_255 ( V_589 -> V_680 != V_702 ) ;
F_255 ( F_234 ( V_589 ) ) ;
V_671 = F_218 ( V_589 ) ;
F_105 ( & V_2 -> V_677 ) ;
for (; ; ) {
V_68 = ( V_671 + V_676 ) & ( V_678 - 1 ) ;
V_670 = F_224 ( V_599 , V_68 ) ;
if ( ! V_670 ) {
if ( V_673 < 0 )
V_673 = V_68 ;
} else if ( F_216 ( V_589 , V_670 ) ) {
if ( V_599 -> V_601 [ V_68 ] . V_589 & V_679 ) {
V_18 = - V_169 ;
goto V_703;
}
if ( V_589 -> V_680 < V_670 -> V_680 ) {
V_18 = - V_98 ;
goto V_703;
}
V_673 = V_68 ;
break;
}
if ( V_676 == V_669 ) {
if ( V_673 < 0 ) {
V_18 = - V_169 ;
goto V_703;
}
break;
}
++ V_676 ;
}
V_670 = F_224 ( V_599 , V_673 ) ;
if ( V_670 ) {
V_604 = true ;
} else {
V_670 = F_239 ( sizeof( * V_589 ) , V_295 ) ;
if ( ! V_670 ) {
V_18 = - V_72 ;
goto V_703;
}
* V_670 = * V_589 ;
}
F_226 ( V_599 , V_673 , V_670 ,
V_679 ) ;
F_103 ( & V_2 -> V_677 ) ;
V_472 = V_604 << 31 | V_673 << 16 | V_589 -> V_642 ;
F_227 ( V_2 , V_589 , V_48 ,
V_599 -> V_601 [ V_673 ] . V_603 , V_604 ) ;
F_178 ( V_2 , V_658 , V_48 , sizeof( V_48 ) ,
V_657 ,
V_704 , V_472 ) ;
return V_673 ;
V_703:
F_103 ( & V_2 -> V_677 ) ;
return V_18 ;
}
static void
V_704 ( struct V_1 * V_2 , unsigned long V_472 ,
int V_18 , T_1 * V_13 ,
T_2 V_473 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
unsigned int V_673 , V_642 ;
struct V_582 * V_589 ;
bool V_604 ;
V_604 = V_472 >> 31 ;
V_673 = ( V_472 >> 16 ) & ( V_678 - 1 ) ;
V_642 = V_472 & 0xffff ;
F_105 ( & V_2 -> V_677 ) ;
V_589 = F_224 ( V_599 , V_673 ) ;
if ( V_18 == 0 ) {
V_599 -> V_601 [ V_673 ] . V_603 =
F_230 ( V_13 , V_659 ) ;
if ( V_604 )
V_589 -> V_642 = V_642 ;
} else if ( ! V_604 ) {
F_48 ( V_589 ) ;
V_589 = NULL ;
}
F_226 ( V_599 , V_673 , V_589 , 0 ) ;
F_103 ( & V_2 -> V_677 ) ;
F_241 ( & V_599 -> V_685 ) ;
}
static bool F_256 ( struct V_1 * V_2 , T_6 V_705 ,
unsigned int V_600 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_582 * V_589 =
F_224 ( V_599 , V_600 ) ;
F_8 ( V_48 ,
V_693 +
V_694 ) ;
if ( ! V_589 ||
( V_599 -> V_601 [ V_600 ] . V_589 & V_679 ) ||
V_589 -> V_680 != V_702 ||
! F_257 ( V_2 -> V_28 , V_589 -> V_642 ,
V_705 , V_600 ) )
return false ;
F_21 ( V_48 , V_606 ,
V_696 ) ;
F_106 ( V_48 , V_608 ,
V_599 -> V_601 [ V_600 ] . V_603 ) ;
if ( F_178 ( V_2 , V_658 , V_48 , sizeof( V_48 ) , 0 ,
V_706 , V_600 ) )
return false ;
V_599 -> V_601 [ V_600 ] . V_589 |= V_679 ;
return true ;
}
static void
V_706 ( struct V_1 * V_2 ,
unsigned long V_600 ,
int V_18 , T_1 * V_13 ,
T_2 V_473 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_582 * V_589 =
F_224 ( V_599 , V_600 ) ;
F_105 ( & V_2 -> V_677 ) ;
if ( V_18 == 0 ) {
F_48 ( V_589 ) ;
F_226 ( V_599 , V_600 , NULL , 0 ) ;
}
V_599 -> V_601 [ V_600 ] . V_589 &= ~ V_679 ;
F_241 ( & V_599 -> V_685 ) ;
F_103 ( & V_2 -> V_677 ) ;
}
static int F_258 ( T_6 V_707 )
{
int V_585 = 0 ;
#define F_259 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_259 ( V_708 , V_709 ) ;
F_259 ( V_708 , V_710 ) ;
F_259 ( V_615 , V_617 ) ;
F_259 ( V_618 , V_619 ) ;
F_259 ( V_620 , V_622 ) ;
F_259 ( V_623 , V_625 ) ;
F_259 ( V_626 , V_627 ) ;
F_259 ( V_628 , V_630 ) ;
F_259 ( V_631 , V_631 ) ;
F_259 ( V_632 , V_634 ) ;
F_259 ( V_635 , V_636 ) ;
F_259 ( V_637 , V_637 ) ;
#undef F_259
if ( V_707 )
return - V_215 ;
return V_585 ;
}
static int F_260 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_711 ) ;
F_8 ( V_13 , V_712 ) ;
unsigned int V_713 , V_714 ;
struct V_598 * V_599 ;
T_2 V_17 ;
int V_18 ;
V_599 = F_29 ( sizeof( * V_599 ) , V_71 ) ;
if ( ! V_599 )
return - V_72 ;
F_21 ( V_48 , V_715 ,
V_716 ) ;
V_18 = F_9 ( V_2 , V_717 ,
V_48 , sizeof( V_48 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_135;
V_714 = F_261 (
V_17 , V_718 ) ;
V_599 -> V_663 = 0 ;
for ( V_713 = 0 ; V_713 < V_714 ; V_713 ++ ) {
T_6 V_707 =
F_262 (
V_13 ,
V_718 ,
V_713 ) ;
V_18 = F_258 ( V_707 ) ;
if ( V_18 < 0 ) {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_54 ,
V_431 , V_707 , V_713 ) ;
} else {
F_41 ( V_2 , V_38 , V_2 -> V_28 ,
L_55 ,
V_431 , V_707 , V_713 ,
V_18 , V_599 -> V_663 ) ;
V_599 -> V_664 [ V_599 -> V_663 ++ ] = V_18 ;
}
}
V_599 -> V_601 = F_263 ( V_678 * sizeof( * V_599 -> V_601 ) ) ;
if ( ! V_599 -> V_601 ) {
V_18 = - V_72 ;
goto V_135;
}
V_599 -> V_719 = V_720 ;
V_599 -> V_721 = V_720 ;
V_599 -> V_722 = V_720 ;
V_2 -> V_667 = V_599 ;
F_264 ( & V_599 -> V_685 ) ;
return 0 ;
V_135:
F_48 ( V_599 ) ;
return V_18 ;
}
static void F_265 ( struct V_1 * V_2 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_582 * V_589 ;
unsigned int V_600 ;
bool V_723 = false ;
int V_18 ;
F_22 ( ! F_266 ( & V_2 -> V_724 ) ) ;
if ( ! V_16 -> V_197 )
return;
if ( ! V_599 )
return;
F_105 ( & V_2 -> V_677 ) ;
for ( V_600 = 0 ; V_600 < V_678 ; V_600 ++ ) {
V_589 = F_224 ( V_599 , V_600 ) ;
if ( ! V_589 )
continue;
V_599 -> V_601 [ V_600 ] . V_589 |= V_679 ;
F_103 ( & V_2 -> V_677 ) ;
V_18 = F_229 ( V_2 , V_589 ,
& V_599 -> V_601 [ V_600 ] . V_603 ,
false ) ;
if ( V_18 )
V_723 = true ;
F_105 ( & V_2 -> V_677 ) ;
if ( V_18 ) {
F_48 ( V_589 ) ;
F_226 ( V_599 , V_600 , NULL , 0 ) ;
} else {
V_599 -> V_601 [ V_600 ] . V_589 &=
~ V_679 ;
}
}
F_103 ( & V_2 -> V_677 ) ;
if ( V_723 )
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_56 ) ;
else
V_16 -> V_197 = false ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
F_8 ( V_48 , V_605 ) ;
struct V_582 * V_589 ;
unsigned int V_600 ;
int V_18 ;
V_2 -> V_667 = NULL ;
if ( ! V_599 )
return;
for ( V_600 = 0 ; V_600 < V_678 ; V_600 ++ ) {
V_589 = F_224 ( V_599 , V_600 ) ;
if ( ! V_589 )
continue;
F_21 ( V_48 , V_606 ,
F_220 ( V_589 ) ?
V_696 :
V_689 ) ;
F_106 ( V_48 , V_608 ,
V_599 -> V_601 [ V_600 ] . V_603 ) ;
V_18 = F_9 ( V_2 , V_658 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_145 ( V_2 -> V_28 ,
L_57 ,
V_600 ,
V_599 -> V_601 [ V_600 ] . V_603 ) ;
F_48 ( V_589 ) ;
}
F_268 ( V_599 -> V_601 ) ;
F_48 ( V_599 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
unsigned int V_600 , V_68 ;
if ( ! V_599 )
return;
F_105 ( & V_2 -> V_677 ) ;
for ( V_68 = 0 ; V_68 < V_599 -> V_725 ; V_68 ++ )
F_270 ( V_599 -> V_726 [ V_68 ] . V_727 ) ;
for ( V_68 = 0 ; V_68 < V_599 -> V_728 ; V_68 ++ )
F_270 ( V_599 -> V_729 [ V_68 ] . V_727 ) ;
F_270 ( V_599 -> V_719 ) ;
F_270 ( V_599 -> V_721 ) ;
F_270 ( V_599 -> V_722 ) ;
F_103 ( & V_2 -> V_677 ) ;
}
static void F_271 ( struct V_1 * V_2 , bool * V_730 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_67 * V_28 = V_2 -> V_28 ;
struct V_731 * V_732 ;
int V_733 ;
unsigned int V_68 ;
V_599 -> V_719 = V_720 ;
V_733 = F_272 ( V_28 ) ;
if ( V_28 -> V_204 & V_734 )
* V_730 = true ;
V_599 -> V_725 = 1 + V_733 ;
F_18 ( V_599 -> V_726 [ 0 ] . V_281 , V_28 -> V_735 ) ;
V_68 = 1 ;
F_273 (uc, net_dev) {
if ( V_68 >= V_736 ) {
* V_730 = true ;
break;
}
F_18 ( V_599 -> V_726 [ V_68 ] . V_281 , V_732 -> V_281 ) ;
V_599 -> V_726 [ V_68 ] . V_727 = V_720 ;
V_68 ++ ;
}
}
static void F_274 ( struct V_1 * V_2 , bool * V_730 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_67 * V_28 = V_2 -> V_28 ;
struct V_731 * V_737 ;
unsigned int V_68 , V_733 ;
V_599 -> V_722 = V_720 ;
V_599 -> V_721 = V_720 ;
if ( V_28 -> V_204 & ( V_734 | V_738 ) )
* V_730 = true ;
V_733 = F_275 ( V_28 ) ;
V_68 = 0 ;
F_276 (mc, net_dev) {
if ( V_68 >= V_739 ) {
* V_730 = true ;
break;
}
F_18 ( V_599 -> V_729 [ V_68 ] . V_281 , V_737 -> V_281 ) ;
V_599 -> V_729 [ V_68 ] . V_727 = V_720 ;
V_68 ++ ;
}
V_599 -> V_728 = V_68 ;
}
static int F_277 ( struct V_1 * V_2 ,
bool V_256 , bool V_740 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_741 * V_742 ;
enum V_743 V_744 ;
struct V_582 V_589 ;
T_3 V_745 [ V_746 ] ;
unsigned int V_68 , V_747 ;
int V_733 ;
int V_18 ;
if ( V_256 ) {
V_742 = V_599 -> V_729 ;
V_733 = V_599 -> V_728 ;
} else {
V_742 = V_599 -> V_726 ;
V_733 = V_599 -> V_725 ;
}
V_744 = F_245 ( V_2 ) ? V_651 : 0 ;
for ( V_68 = 0 ; V_68 < V_733 ; V_68 ++ ) {
F_278 ( & V_589 , V_681 , V_744 , 0 ) ;
F_279 ( & V_589 , V_748 ,
V_742 [ V_68 ] . V_281 ) ;
V_18 = F_232 ( V_2 , & V_589 , true ) ;
if ( V_18 < 0 ) {
if ( V_740 ) {
F_62 ( V_2 , V_27 , V_2 -> V_28 ,
L_58 ,
V_18 ) ;
for ( V_747 = 0 ; V_747 < V_68 ; V_747 ++ ) {
if ( V_742 [ V_747 ] . V_727 == V_720 )
continue;
F_248 (
V_2 , V_681 ,
V_742 [ V_747 ] . V_727 ) ;
V_742 [ V_747 ] . V_727 = V_720 ;
}
return V_18 ;
} else {
V_18 = V_720 ;
}
}
V_742 [ V_68 ] . V_727 = F_247 ( V_2 , V_18 ) ;
}
if ( V_256 && V_740 ) {
F_278 ( & V_589 , V_681 , V_744 , 0 ) ;
F_280 ( V_745 ) ;
F_279 ( & V_589 , V_748 , V_745 ) ;
V_18 = F_232 ( V_2 , & V_589 , true ) ;
if ( V_18 < 0 ) {
F_165 ( V_2 , V_27 , V_2 -> V_28 ,
L_59 , V_18 ) ;
for ( V_747 = 0 ; V_747 < V_68 ; V_747 ++ ) {
if ( V_742 [ V_747 ] . V_727 == V_720 )
continue;
F_248 (
V_2 , V_681 ,
V_742 [ V_747 ] . V_727 ) ;
V_742 [ V_747 ] . V_727 = V_720 ;
}
return V_18 ;
} else {
V_599 -> V_721 = F_247 ( V_2 , V_18 ) ;
}
}
return 0 ;
}
static int F_281 ( struct V_1 * V_2 , bool V_256 ,
bool V_740 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_15 * V_16 = V_2 -> V_16 ;
enum V_743 V_744 ;
struct V_582 V_589 ;
T_3 V_745 [ V_746 ] ;
int V_18 ;
V_744 = F_245 ( V_2 ) ? V_651 : 0 ;
F_278 ( & V_589 , V_681 , V_744 , 0 ) ;
if ( V_256 )
F_282 ( & V_589 ) ;
else
F_283 ( & V_589 ) ;
V_18 = F_232 ( V_2 , & V_589 , true ) ;
if ( V_18 < 0 ) {
F_165 ( V_2 , V_27 , V_2 -> V_28 ,
L_60 ,
V_256 ? L_61 : L_62 , V_18 ) ;
} else if ( V_256 ) {
V_599 -> V_722 = F_247 ( V_2 , V_18 ) ;
if ( ! V_16 -> V_501 ) {
F_278 ( & V_589 , V_681 ,
V_744 , 0 ) ;
F_280 ( V_745 ) ;
F_279 ( & V_589 , V_748 ,
V_745 ) ;
V_18 = F_232 ( V_2 , & V_589 , true ) ;
if ( V_18 < 0 ) {
F_165 ( V_2 , V_27 , V_2 -> V_28 ,
L_59 ,
V_18 ) ;
if ( V_740 ) {
F_248 (
V_2 , V_681 ,
V_599 -> V_722 ) ;
V_599 -> V_722 = V_720 ;
return V_18 ;
}
} else {
V_599 -> V_721 = F_247 ( V_2 , V_18 ) ;
}
}
V_18 = 0 ;
} else {
V_599 -> V_719 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
bool V_749 = false ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_678 ; V_68 ++ ) {
if ( F_130 ( V_599 -> V_601 [ V_68 ] . V_589 ) &
V_688 ) {
if ( F_244 (
V_2 , 1U << V_681 ,
V_68 , true ) < 0 )
V_749 = true ;
}
}
F_22 ( V_749 ) ;
}
static int F_285 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_750 [ V_746 ] ;
int V_18 , V_751 ;
if ( F_286 ( V_16 -> V_752 ) )
return 0 ;
F_287 ( V_2 ) ;
F_288 ( V_2 -> V_28 ) ;
F_289 ( & V_2 -> V_724 ) ;
F_267 ( V_2 ) ;
F_290 ( & V_2 -> V_724 ) ;
V_18 = F_69 ( V_2 , V_16 -> V_80 ) ;
if ( V_18 )
goto V_753;
F_18 ( V_750 , V_16 -> V_752 ) ;
V_18 = F_71 ( V_2 , V_16 -> V_80 ,
V_16 -> V_752 ) ;
if ( V_18 )
goto V_754;
V_18 = F_70 ( V_2 , V_16 -> V_80 ,
V_2 -> V_28 -> V_735 ) ;
if ( ! V_18 ) {
F_18 ( V_16 -> V_752 , V_2 -> V_28 -> V_735 ) ;
} else {
V_751 = F_70 ( V_2 , V_16 -> V_80 , V_750 ) ;
if ( V_751 ) {
F_291 ( V_16 -> V_752 ) ;
goto V_755;
}
}
V_754:
V_751 = F_68 ( V_2 , V_16 -> V_80 ) ;
if ( V_751 )
goto V_755;
V_753:
F_289 ( & V_2 -> V_724 ) ;
V_751 = F_260 ( V_2 ) ;
F_290 ( & V_2 -> V_724 ) ;
if ( V_751 )
goto V_755;
V_751 = F_292 ( V_2 -> V_28 ) ;
if ( V_751 )
goto V_755;
F_293 ( V_2 -> V_28 ) ;
return V_18 ;
V_755:
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_63 ) ;
F_186 ( V_2 , V_203 ) ;
return V_18 ? V_18 : V_751 ;
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_598 * V_599 = V_2 -> V_667 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_67 * V_28 = V_2 -> V_28 ;
bool V_756 = false , V_757 = false ;
if ( ! F_295 ( V_2 ) )
return;
if ( ! V_599 )
return;
F_269 ( V_2 ) ;
F_296 ( V_28 ) ;
F_271 ( V_2 , & V_756 ) ;
F_274 ( V_2 , & V_757 ) ;
F_297 ( V_28 ) ;
if ( V_756 ) {
F_281 ( V_2 , false , false ) ;
F_277 ( V_2 , false , false ) ;
} else {
if ( F_277 ( V_2 , false , false ) )
F_281 ( V_2 , false , false ) ;
}
if ( V_16 -> V_501 && V_2 -> V_757 != V_757 )
F_284 ( V_2 ) ;
if ( V_757 ) {
if ( V_16 -> V_501 ) {
if ( F_281 ( V_2 , true , true ) ) {
F_284 ( V_2 ) ;
F_277 ( V_2 , true , false ) ;
}
} else {
F_281 ( V_2 , true , false ) ;
F_277 ( V_2 , true , false ) ;
}
} else {
if ( F_277 ( V_2 , true , true ) ) {
if ( V_16 -> V_501 )
F_284 ( V_2 ) ;
if ( F_281 ( V_2 , true , true ) )
F_277 ( V_2 , true , false ) ;
}
}
F_284 ( V_2 ) ;
V_2 -> V_757 = V_757 ;
}
static int F_298 ( struct V_1 * V_2 )
{
F_8 ( V_48 , V_758 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_759 = V_2 -> V_760 ;
int V_18 ;
F_287 ( V_2 ) ;
F_288 ( V_2 -> V_28 ) ;
F_289 ( & V_2 -> V_724 ) ;
F_267 ( V_2 ) ;
F_18 ( F_19 ( V_48 , V_761 ) ,
V_2 -> V_28 -> V_735 ) ;
F_21 ( V_48 , V_762 ,
V_16 -> V_80 ) ;
V_18 = F_51 ( V_2 , V_763 , V_48 ,
sizeof( V_48 ) , NULL , 0 , NULL ) ;
F_260 ( V_2 ) ;
F_290 ( & V_2 -> V_724 ) ;
if ( V_759 )
F_292 ( V_2 -> V_28 ) ;
F_293 ( V_2 -> V_28 ) ;
#ifdef F_44
if ( V_2 -> V_10 -> V_151 && V_2 -> V_10 -> V_103 ) {
struct V_10 * V_105 = V_2 -> V_10 -> V_103 ;
if ( V_18 == - V_98 ) {
struct V_1 * V_106 ;
V_106 = F_24 ( V_105 ) ;
V_18 = F_299 ( V_106 ,
V_16 -> V_22 ,
V_2 -> V_28 -> V_735 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_106 = F_24 ( V_105 ) ;
struct V_15 * V_16 = V_106 -> V_16 ;
unsigned int V_68 ;
for ( V_68 = 0 ; V_68 < V_106 -> V_199 ; ++ V_68 ) {
struct V_149 * V_150 = V_16 -> V_150 + V_68 ;
if ( V_150 -> V_2 == V_2 ) {
F_18 ( V_150 -> V_160 ,
V_2 -> V_28 -> V_735 ) ;
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
V_18 = F_285 ( V_2 ) ;
} else {
F_52 ( V_2 , V_763 ,
sizeof( V_48 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_300 ( struct V_1 * V_2 )
{
F_294 ( V_2 ) ;
return F_301 ( V_2 ) ;
}
static int F_302 ( struct V_1 * V_2 )
{
F_294 ( V_2 ) ;
return 0 ;
}
static int F_303 ( struct V_1 * V_2 , T_6 V_764 )
{
F_8 ( V_48 , V_765 ) ;
F_21 ( V_48 , V_766 , V_764 ) ;
return F_9 ( V_2 , V_767 , V_48 , sizeof( V_48 ) ,
NULL , 0 , NULL ) ;
}
static int F_304 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_768 ) ;
T_2 V_17 ;
T_6 V_769 ;
V_18 = F_9 ( V_2 , V_770 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_768 )
return - V_7 ;
V_769 = F_10 ( V_13 , V_771 ) ;
switch ( V_769 ) {
case V_772 :
F_41 ( V_2 , V_374 , V_2 -> V_28 , L_66 ) ;
return 0 ;
case V_773 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_67 ) ;
return - V_7 ;
case V_774 :
F_14 ( V_2 , V_374 , V_2 -> V_28 , L_68 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_374 , V_2 -> V_28 ,
L_69 , V_769 ) ;
return - V_7 ;
}
}
static int F_305 ( struct V_1 * V_2 , T_6 V_764 )
{
int V_18 ;
F_41 ( V_2 , V_27 , V_2 -> V_28 , L_70 , V_764 ) ;
V_18 = F_303 ( V_2 , V_764 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_304 ( V_2 ) ;
}
static int
F_306 ( struct V_1 * V_2 , struct V_775 * V_776 )
{
int V_18 , V_751 ;
F_307 ( V_2 , V_214 ) ;
V_18 = F_9 ( V_2 , V_777 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_304;
V_776 -> V_778 = F_305 ( V_2 , V_779 ) ? - 1 : 1 ;
V_776 -> V_780 = F_305 ( V_2 , V_781 ) ? - 1 : 1 ;
V_18 = F_35 ( V_2 , V_214 ) ;
V_304:
if ( V_18 == - V_98 )
V_18 = 0 ;
V_751 = F_308 ( V_2 , V_214 , V_18 == 0 ) ;
return V_18 ? V_18 : V_751 ;
}
static int F_309 ( struct V_1 * V_2 ,
struct V_782 * V_783 ,
unsigned int type )
{
F_8 ( V_48 , V_784 ) ;
F_8 ( V_13 , V_785 ) ;
const struct V_786 * V_787 ;
T_2 V_699 , V_788 , V_17 ;
bool V_789 ;
int V_18 ;
for ( V_787 = V_790 ; ; V_787 ++ ) {
if ( V_787 ==
V_790 + F_159 ( V_790 ) )
return - V_36 ;
if ( ( type & ~ V_787 -> V_791 ) == V_787 -> type )
break;
}
if ( V_787 -> V_792 != F_310 ( V_2 ) )
return - V_36 ;
V_18 = F_311 ( V_2 , type , & V_699 , & V_788 , & V_789 ) ;
if ( V_18 )
return V_18 ;
if ( V_789 )
return - V_36 ;
V_783 -> V_793 = type ;
F_21 ( V_48 , V_794 , type ) ;
V_18 = F_9 ( V_2 , V_795 , V_48 , sizeof( V_48 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_796 )
return - V_7 ;
if ( F_10 ( V_13 , V_797 ) &
( 1 << V_798 ) )
V_783 -> V_799 = F_10 ( V_13 ,
V_800 ) ;
V_783 -> V_801 . V_802 = L_71 ;
V_783 -> V_801 . V_803 = V_787 -> V_237 ;
V_783 -> V_801 . V_804 . type = V_805 ;
V_783 -> V_801 . V_804 . V_204 = V_806 ;
V_783 -> V_801 . V_804 . V_699 = V_699 ;
V_783 -> V_801 . V_804 . V_807 = V_788 ;
return 0 ;
}
static int F_312 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_808 ) ;
struct V_782 * V_809 ;
T_2 V_17 , V_810 , V_68 , V_811 ;
unsigned int type ;
int V_18 ;
F_313 () ;
F_13 ( V_812 != 0 ) ;
V_18 = F_9 ( V_2 , V_813 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_814 )
return - V_7 ;
V_810 = F_10 ( V_13 , V_815 ) ;
if ( V_810 >
F_261 ( V_17 , V_816 ) )
return - V_7 ;
V_809 = F_314 ( V_810 , sizeof( * V_809 ) , V_71 ) ;
if ( ! V_809 )
return - V_72 ;
V_811 = 0 ;
for ( V_68 = 0 ; V_68 < V_810 ; V_68 ++ ) {
type = F_262 ( V_13 , V_816 ,
V_68 ) ;
V_18 = F_309 ( V_2 , & V_809 [ V_811 ] , type ) ;
if ( V_18 == 0 )
V_811 ++ ;
else if ( V_18 != - V_36 )
goto V_135;
}
V_18 = F_315 ( V_2 , & V_809 [ 0 ] . V_801 , V_811 , sizeof( * V_809 ) ) ;
V_135:
if ( V_18 )
F_48 ( V_809 ) ;
return V_18 ;
}
static void F_316 ( struct V_1 * V_2 , T_6 V_817 )
{
F_32 ( V_2 , F_33 ( V_817 ) , V_328 ) ;
}
static void F_317 ( struct V_1 * V_2 ,
T_6 V_817 ) {}
static int F_318 ( struct V_123 * V_124 ,
bool V_818 )
{
F_8 ( V_48 , V_819 ) ;
int V_18 ;
if ( V_124 -> V_820 == V_821 ||
V_124 -> V_820 == V_822 ||
( V_818 && V_124 -> V_820 == V_823 ) )
return 0 ;
V_124 -> V_820 = V_821 ;
F_21 ( V_48 , V_824 , V_825 ) ;
F_21 ( V_48 , V_826 , 0 ) ;
F_21 ( V_48 , V_827 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_828 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_124 -> V_820 = V_818 ? V_829 :
V_823 ;
return V_18 ;
}
static int F_319 ( struct V_123 * V_124 ,
bool V_818 )
{
F_8 ( V_48 , V_830 ) ;
int V_18 ;
if ( V_124 -> V_820 == V_823 ||
( V_818 && V_124 -> V_820 == V_829 ) )
return 0 ;
if ( V_124 -> V_820 == V_829 ) {
V_124 -> V_820 = V_823 ;
return 0 ;
}
V_124 -> V_820 = V_818 ? V_829 :
V_823 ;
F_21 ( V_48 , V_824 , V_831 ) ;
F_21 ( V_48 , V_826 , 0 ) ;
F_21 ( V_48 , V_832 ,
V_833 ) ;
F_21 ( V_48 , V_834 ,
V_124 -> V_124 ) ;
V_18 = F_9 ( V_124 -> V_2 , V_828 ,
V_48 , sizeof( V_48 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_320 ( struct V_1 * V_2 , bool V_835 ,
bool V_818 )
{
int (* F_321)( struct V_123 * V_124 , bool V_818 );
struct V_123 * V_124 ;
F_321 = V_835 ?
F_318 :
F_319 ;
F_58 (channel, efx) {
int V_18 = F_321 ( V_124 , V_818 ) ;
if ( V_835 && V_18 != 0 ) {
F_320 ( V_2 , false , V_818 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_322 ( struct V_1 * V_2 ,
struct V_836 * V_837 )
{
return - V_319 ;
}
static int F_323 ( struct V_1 * V_2 ,
struct V_836 * V_837 )
{
int V_18 ;
switch ( V_837 -> V_838 ) {
case V_839 :
F_320 ( V_2 , false , false ) ;
return F_324 ( V_2 ,
V_837 -> V_840 != V_841 , 0 ) ;
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
case V_852 :
case V_853 :
case V_854 :
V_837 -> V_838 = V_842 ;
V_18 = F_324 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_320 ( V_2 , true , false ) ;
if ( V_18 )
F_324 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_42 ;
}
}
