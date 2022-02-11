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
if ( V_17 < V_27 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_1 ) ;
return - V_7 ;
}
V_16 -> V_30 =
F_10 ( V_13 , V_31 ) ;
if ( V_17 >= V_24 )
V_16 -> V_32 = F_10 ( V_13 ,
V_33 ) ;
else
V_16 -> V_32 = 0 ;
V_16 -> V_34 =
F_15 ( V_13 , V_35 ) ;
V_16 -> V_36 =
F_15 ( V_13 , V_37 ) ;
if ( ! ( V_16 -> V_30 &
( 1 << V_38 ) ) ) {
F_14 ( V_2 , V_39 , V_2 -> V_29 ,
L_2 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_41 ) ;
int V_18 ;
V_18 = F_9 ( V_2 , V_42 , NULL , 0 ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 )
return V_18 ;
V_18 = F_10 ( V_13 , V_43 ) ;
return V_18 > 0 ? V_18 : - V_44 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_45 ;
unsigned int V_46 ;
int V_18 ;
V_16 -> V_47 = false ;
V_16 -> V_48 = false ;
V_18 = F_18 ( V_2 , & V_45 , & V_46 ) ;
if ( V_18 == - V_49 ) {
V_18 = 0 ;
} else if ( V_18 == 0 ) {
if ( V_46 & V_50 )
V_16 -> V_48 = true ;
if ( V_46 & V_51 ) {
V_16 -> V_47 = true ;
} else if ( V_45 & V_51 ) {
V_18 = F_19 ( V_2 ,
V_52 ,
true , NULL ) ;
if ( V_18 == 0 )
V_16 -> V_47 = true ;
V_18 = 0 ;
}
}
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_3 ,
V_16 -> V_47 ? L_4 : L_5 ) ;
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_6 ,
V_16 -> V_48 ? L_4 : L_5 ) ;
return V_18 ;
}
static void F_21 ( struct V_1 * V_2 ,
const T_1 * V_53 )
{
unsigned int V_54 ;
if ( F_22 ( V_2 ) ) {
V_2 -> V_55 = F_10 ( V_53 ,
V_56 ) ;
V_2 -> V_57 = F_10 ( V_53 ,
V_58 ) ;
} else if ( F_23 ( V_2 ) ) {
V_2 -> V_55 = F_10 ( V_53 ,
V_59 ) ;
V_54 = F_10 ( V_53 ,
V_60 ) ;
V_2 -> V_57 = V_54 * V_2 -> V_55 ;
} else {
V_2 -> V_55 = F_10 ( V_53 ,
V_61 ) ;
V_54 = F_10 ( V_53 ,
V_62 ) ;
V_2 -> V_57 = V_54 * V_2 -> V_55 ;
}
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_7 ,
V_2 -> V_55 , V_2 -> V_57 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_63 ) ;
int V_18 ;
V_18 = F_17 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_25 ( V_2 , V_64 , NULL , 0 ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 ) {
F_21 ( V_2 , V_13 ) ;
} else if ( V_18 == - V_49 || V_18 == - V_65 ) {
unsigned int V_66 ;
V_18 = F_16 ( V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_66 = 1536000 / V_18 ;
V_2 -> V_55 = V_66 ;
V_2 -> V_57 = V_2 -> type -> V_67 * V_66 ;
V_18 = 0 ;
} else {
F_26 ( V_2 , V_64 ,
V_63 ,
NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_27 ( struct V_1 * V_2 , T_3 * V_68 )
{
F_8 ( V_13 , V_69 ) ;
T_2 V_17 ;
int V_18 ;
F_13 ( V_70 != 0 ) ;
V_18 = F_9 ( V_2 , V_71 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_69 )
return - V_7 ;
F_28 ( V_68 ,
F_29 ( V_13 , V_72 ) ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , T_3 * V_68 )
{
F_8 ( V_73 , V_74 ) ;
F_8 ( V_13 , V_75 ) ;
T_2 V_17 ;
int V_76 , V_18 ;
F_31 ( V_73 , V_77 ,
V_78 ) ;
V_18 = F_9 ( V_2 , V_79 , V_73 ,
sizeof( V_73 ) , V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_80 )
return - V_7 ;
V_76 = F_10 ( V_13 ,
V_81 ) ;
F_32 ( V_76 != 1 ) ;
F_28 ( V_68 ,
F_29 ( V_13 , V_82 ) ) ;
return 0 ;
}
static T_4 F_33 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 )
{
struct V_1 * V_2 = F_34 ( F_35 ( V_84 ) ) ;
return sprintf ( V_87 , L_8 ,
( ( V_2 -> V_88 -> V_89 ) &
( 1 << V_90 ) )
? 1 : 0 ) ;
}
static T_4 F_36 ( struct V_83 * V_84 ,
struct V_85 * V_86 ,
char * V_87 )
{
struct V_1 * V_2 = F_34 ( F_35 ( V_84 ) ) ;
return sprintf ( V_87 , L_8 ,
( ( V_2 -> V_88 -> V_89 ) &
( 1 << V_91 ) )
? 1 : 0 ) ;
}
static struct V_92 * F_37 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_92 * V_94 ;
F_32 ( ! F_38 ( & V_16 -> V_95 ) ) ;
F_39 (vlan, &nic_data->vlan_list, list) {
if ( V_94 -> V_93 == V_93 )
return V_94 ;
}
return NULL ;
}
static int F_40 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_92 * V_94 ;
int V_18 ;
F_41 ( & V_16 -> V_95 ) ;
V_94 = F_37 ( V_2 , V_93 ) ;
if ( V_94 ) {
if ( V_93 == 0 )
goto V_96;
F_42 ( V_2 , V_28 , V_2 -> V_29 ,
L_9 , V_93 ) ;
V_18 = - V_97 ;
goto V_98;
}
V_18 = - V_99 ;
V_94 = F_43 ( sizeof( * V_94 ) , V_100 ) ;
if ( ! V_94 )
goto V_101;
V_94 -> V_93 = V_93 ;
F_44 ( & V_94 -> V_102 , & V_16 -> V_103 ) ;
if ( V_2 -> V_104 ) {
F_41 ( & V_2 -> V_105 ) ;
F_45 ( & V_2 -> V_106 ) ;
V_18 = F_46 ( V_2 , V_94 -> V_93 ) ;
F_47 ( & V_2 -> V_106 ) ;
F_48 ( & V_2 -> V_105 ) ;
if ( V_18 )
goto V_107;
}
V_96:
F_48 ( & V_16 -> V_95 ) ;
return 0 ;
V_107:
F_49 ( & V_94 -> V_102 ) ;
F_50 ( V_94 ) ;
V_101:
V_98:
F_48 ( & V_16 -> V_95 ) ;
return V_18 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_92 * V_94 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_32 ( ! F_38 ( & V_16 -> V_95 ) ) ;
if ( V_2 -> V_104 ) {
F_45 ( & V_2 -> V_106 ) ;
F_52 ( V_2 , V_94 -> V_93 ) ;
F_47 ( & V_2 -> V_106 ) ;
}
F_49 ( & V_94 -> V_102 ) ;
F_50 ( V_94 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_92 * V_94 ;
int V_18 = 0 ;
if ( V_93 == 0 )
return 0 ;
F_41 ( & V_16 -> V_95 ) ;
V_94 = F_37 ( V_2 , V_93 ) ;
if ( ! V_94 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_10 , V_93 ) ;
V_18 = - V_108 ;
} else {
F_51 ( V_2 , V_94 ) ;
}
F_48 ( & V_16 -> V_95 ) ;
return V_18 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_92 * V_94 , * V_109 ;
F_41 ( & V_16 -> V_95 ) ;
F_55 (vlan, next_vlan, &nic_data->vlan_list, list)
F_51 ( V_2 , V_94 ) ;
F_48 ( & V_16 -> V_95 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_110 * V_29 = V_2 -> V_29 ;
int V_111 , V_18 ;
V_2 -> V_112 = F_57 (unsigned int,
EFX_MAX_CHANNELS,
efx_ef10_mem_map_size(efx) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
V_2 -> V_113 = V_2 -> V_112 ;
if ( F_32 ( V_2 -> V_112 == 0 ) )
return - V_7 ;
V_16 = F_43 ( sizeof( * V_16 ) , V_100 ) ;
if ( ! V_16 )
return - V_99 ;
V_2 -> V_16 = V_16 ;
F_13 ( V_114 % 4 ) ;
V_18 = F_58 ( V_2 , & V_16 -> V_115 ,
8 + V_114 , V_100 ) ;
if ( V_18 )
goto V_116;
V_111 = 0 ;
for (; ; ) {
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 )
break;
if ( ++ V_111 == 5 )
goto V_117;
F_59 ( 1 ) ;
}
V_16 -> V_118 = V_18 ;
V_16 -> V_119 = V_120 ;
V_16 -> V_121 = V_78 ;
F_60 ( V_2 , F_61 ( 1 ) , V_122 ) ;
V_18 = F_62 ( V_2 ) ;
if ( V_18 )
goto V_117;
V_18 = F_63 ( V_2 , V_123 ) ;
if ( V_18 )
goto V_124;
V_18 = F_64 ( V_2 , true , false , 0 ) ;
if ( V_18 )
goto V_124;
V_18 = F_65 ( & V_2 -> V_10 -> V_84 ,
& V_125 ) ;
if ( V_18 )
goto V_124;
V_18 = F_65 ( & V_2 -> V_10 -> V_84 , & V_126 ) ;
if ( V_18 )
goto V_127;
V_18 = F_7 ( V_2 ) ;
if ( V_18 )
goto V_128;
V_18 = F_12 ( V_2 ) ;
if ( V_18 < 0 )
goto V_128;
V_2 -> V_129 =
V_130 - V_131 ;
V_18 = F_66 ( V_2 ) ;
if ( V_18 < 0 )
goto V_128;
V_2 -> V_132 = V_18 ;
V_29 -> V_133 = V_18 ;
V_18 = V_2 -> type -> V_134 ( V_2 , V_2 -> V_29 -> V_135 ) ;
if ( V_18 )
goto V_128;
V_18 = F_24 ( V_2 ) ;
if ( V_18 < 0 )
goto V_128;
V_18 = F_67 ( V_2 ) ;
if ( V_18 && V_18 != - V_65 )
goto V_128;
F_68 ( V_2 , NULL ) ;
#ifdef F_69
if ( ( V_2 -> V_10 -> V_136 ) && ( ! V_2 -> V_10 -> V_137 ) ) {
struct V_10 * V_138 = V_2 -> V_10 -> V_136 ;
struct V_1 * V_139 = F_34 ( V_138 ) ;
V_139 -> type -> V_134 ( V_139 , V_16 -> V_140 ) ;
} else
#endif
F_28 ( V_16 -> V_140 , V_2 -> V_29 -> V_135 ) ;
F_70 ( & V_16 -> V_103 ) ;
F_71 ( & V_16 -> V_95 ) ;
V_18 = F_40 ( V_2 , V_141 ) ;
if ( V_18 )
goto V_142;
V_18 = F_40 ( V_2 , 0 ) ;
if ( V_18 )
goto V_143;
return 0 ;
V_143:
F_54 ( V_2 ) ;
V_142:
F_72 ( & V_16 -> V_95 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
V_128:
F_75 ( & V_2 -> V_10 -> V_84 , & V_126 ) ;
V_127:
F_75 ( & V_2 -> V_10 -> V_84 , & V_125 ) ;
V_124:
F_76 ( V_2 ) ;
V_117:
F_77 ( V_2 , & V_16 -> V_115 ) ;
V_116:
F_50 ( V_16 ) ;
V_2 -> V_16 = NULL ;
return V_18 ;
}
static int F_78 ( struct V_1 * V_2 )
{
F_79 ( V_13 ) ;
T_2 V_17 ;
int V_18 = F_25 ( V_2 , V_144 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 == - V_97 )
V_18 = 0 ;
if ( V_18 )
F_26 ( V_2 , V_144 , 0 , V_13 , V_17 ,
V_18 ) ;
return V_18 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_73 , V_145 ) ;
unsigned int V_111 ;
int V_18 ;
F_13 ( V_146 != 0 ) ;
for ( V_111 = 0 ; V_111 < V_16 -> V_147 ; V_111 ++ ) {
F_31 ( V_73 , V_148 ,
V_16 -> V_149 [ V_111 ] ) ;
V_18 = F_9 ( V_2 , V_150 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
F_32 ( V_18 ) ;
}
V_16 -> V_147 = 0 ;
}
static int F_81 ( struct V_1 * V_2 , unsigned int V_151 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_13 , V_152 ) ;
unsigned int V_111 ;
T_2 V_17 ;
int V_18 = 0 ;
F_13 ( V_153 != 0 ) ;
for ( V_111 = 0 ; V_111 < V_151 ; V_111 ++ ) {
V_18 = F_25 ( V_2 , V_154 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 ) {
if ( ! ( F_6 ( V_2 ) && V_18 == - V_155 ) )
F_26 ( V_2 , V_154 ,
0 , V_13 , V_17 , V_18 ) ;
break;
}
if ( V_17 < V_152 ) {
V_18 = - V_7 ;
break;
}
V_16 -> V_149 [ V_111 ] =
F_10 ( V_13 , V_156 ) ;
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_11 , V_111 ,
V_16 -> V_149 [ V_111 ] ) ;
}
V_16 -> V_147 = V_111 ;
if ( V_18 )
F_80 ( V_2 ) ;
return V_18 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_83 ( V_73 ,
F_84 ( V_157 ,
V_158 ) ) ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
unsigned int V_163 , V_164 ;
int V_18 ;
F_13 ( V_165 != 0 ) ;
F_13 ( V_166 != 0 ) ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
for ( V_164 = 0 ; V_164 < V_16 -> V_147 ; ++ V_164 ) {
F_31 ( V_73 , V_167 ,
V_16 -> V_149 [ V_164 ] ) ;
F_31 ( V_73 , V_168 ,
V_16 -> V_169 + V_164 ) ;
V_18 = F_9 ( V_2 , V_170 ,
V_73 , V_157 ,
NULL , 0 , NULL ) ;
if ( V_18 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_12 ,
V_16 -> V_169 + V_164 , V_164 ,
V_18 ) ;
goto V_171;
}
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_13 ,
V_16 -> V_169 + V_164 , V_164 ) ;
}
F_85 (channel, efx) {
F_86 (tx_queue, channel) {
V_163 = ( ( V_2 -> V_172 + V_2 -> V_173 -
V_162 -> V_160 -> V_160 - 1 ) *
V_174 ) ;
V_164 = V_163 / V_175 ;
V_163 = V_163 % V_175 ;
if ( V_162 -> V_176 == V_16 -> V_169 ) {
F_87 ( V_164 != 0 ) ;
V_18 = 0 ;
} else {
F_31 ( V_73 ,
V_167 ,
V_16 -> V_149 [ V_164 ] ) ;
F_31 ( V_73 ,
V_168 ,
V_162 -> V_176 ) ;
V_18 = F_9 ( V_2 , V_170 ,
V_73 , V_157 ,
NULL , 0 , NULL ) ;
}
if ( V_18 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_12 ,
V_162 -> V_176 , V_164 , V_18 ) ;
V_162 -> V_177 = NULL ;
} else {
V_162 -> V_177 =
V_16 -> V_178 +
V_164 * V_179 + V_163 ;
V_162 -> V_180 = V_163 ;
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_14 ,
V_162 -> V_176 , V_164 ,
V_162 -> V_180 ,
V_162 -> V_177 ) ;
}
}
}
return 0 ;
V_171:
while ( V_164 -- ) {
F_31 ( V_73 , V_181 ,
V_16 -> V_169 + V_164 ) ;
F_9 ( V_2 , V_182 ,
V_73 , V_158 ,
NULL , 0 , NULL ) ;
}
return V_18 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_159 * V_160 ;
struct V_161 * V_162 ;
F_85 (channel, efx)
F_86 (tx_queue, channel)
V_162 -> V_177 = NULL ;
}
static int F_81 ( struct V_1 * V_2 , unsigned int V_151 )
{
return V_151 == 0 ? 0 : - V_183 ;
}
static int F_82 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
}
static void F_88 ( struct V_1 * V_2 )
{
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
#ifdef F_69
struct V_15 * V_184 ;
struct V_10 * V_138 ;
struct V_1 * V_139 ;
struct V_185 * V_186 ;
if ( V_2 -> V_10 -> V_187 ) {
V_138 = V_2 -> V_10 -> V_136 ;
if ( V_138 ) {
V_139 = F_34 ( V_138 ) ;
V_184 = V_139 -> V_16 ;
V_186 = V_184 -> V_186 + V_16 -> V_22 ;
V_186 -> V_2 = NULL ;
} else
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_15 ) ;
}
#endif
F_54 ( V_2 ) ;
F_72 ( & V_16 -> V_95 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
F_91 ( V_2 ) ;
if ( V_16 -> V_188 )
F_92 ( V_16 -> V_188 ) ;
V_18 = F_78 ( V_2 ) ;
F_32 ( V_18 != 0 ) ;
if ( ! V_16 -> V_189 )
F_80 ( V_2 ) ;
F_75 ( & V_2 -> V_10 -> V_84 , & V_126 ) ;
F_75 ( & V_2 -> V_10 -> V_84 , & V_125 ) ;
F_76 ( V_2 ) ;
F_77 ( V_2 , & V_16 -> V_115 ) ;
F_50 ( V_16 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
return F_56 ( V_2 ) ;
}
int F_94 ( struct V_1 * V_2 , unsigned int V_140 ,
T_6 * V_190 , T_6 * V_191 ,
unsigned int * V_192 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_73 , V_193 ) ;
F_8 ( V_13 , V_194 ) ;
T_2 V_17 ;
int V_18 ;
if ( V_16 -> V_30 &
( 1 << V_195 ) ) {
F_31 ( V_73 , V_196 ,
V_140 ) ;
V_18 = F_9 ( V_2 , V_197 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < sizeof( V_13 ) ) {
V_18 = - V_7 ;
return V_18 ;
}
}
if ( V_190 )
* V_190 = F_10 ( V_13 , V_198 ) ;
if ( V_191 )
* V_191 =
F_10 ( V_13 , V_199 ) ;
if ( V_192 )
* V_192 =
F_10 ( V_13 ,
V_200 ) ;
return 0 ;
}
int F_95 ( struct V_1 * V_2 , unsigned int V_140 )
{
F_8 ( V_73 , V_201 ) ;
F_31 ( V_73 , V_202 , V_140 ) ;
return F_9 ( V_2 , V_203 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
}
int F_96 ( struct V_1 * V_2 , unsigned int V_140 )
{
F_8 ( V_73 , V_204 ) ;
F_31 ( V_73 , V_205 , V_140 ) ;
return F_9 ( V_2 , V_206 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
}
int F_97 ( struct V_1 * V_2 ,
unsigned int V_140 , T_3 * V_207 )
{
F_8 ( V_73 , V_208 ) ;
F_31 ( V_73 , V_209 , V_140 ) ;
F_28 ( F_29 ( V_73 , V_210 ) , V_207 ) ;
return F_9 ( V_2 , V_211 , V_73 ,
sizeof( V_73 ) , NULL , 0 , NULL ) ;
}
int F_98 ( struct V_1 * V_2 ,
unsigned int V_140 , T_3 * V_207 )
{
F_8 ( V_73 , V_212 ) ;
F_31 ( V_73 , V_213 , V_140 ) ;
F_28 ( F_29 ( V_73 , V_214 ) , V_207 ) ;
return F_9 ( V_2 , V_215 , V_73 ,
sizeof( V_73 ) , NULL , 0 , NULL ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_10 * V_138 ;
V_138 = V_2 -> V_10 -> V_136 ;
if ( V_138 ) {
struct V_1 * V_139 = F_34 ( V_138 ) ;
struct V_15 * V_184 = V_139 -> V_16 ;
if ( ! V_184 -> V_186 ) {
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_16
L_17 ) ;
return - V_216 ;
}
}
V_18 = F_56 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
goto V_171;
if ( V_2 -> V_10 -> V_187 ) {
if ( V_2 -> V_10 -> V_136 ) {
struct V_1 * V_139 =
F_34 ( V_2 -> V_10 -> V_136 ) ;
struct V_15 * V_217 = V_139 -> V_16 ;
struct V_15 * V_16 = V_2 -> V_16 ;
V_217 -> V_186 [ V_16 -> V_22 ] . V_2 = V_2 ;
V_217 -> V_186 [ V_16 -> V_22 ] . V_10 =
V_2 -> V_10 ;
} else
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_15 ) ;
}
return 0 ;
V_171:
F_89 ( V_2 ) ;
return V_18 ;
}
static int F_100 ( struct V_1 * V_2 ,
unsigned int V_218 , unsigned int V_219 )
{
F_8 ( V_73 , V_220 ) ;
F_8 ( V_13 , V_221 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
F_31 ( V_73 , V_222 , V_218 ) ;
F_31 ( V_73 , V_223 , V_219 ) ;
V_18 = F_9 ( V_2 , V_224 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_221 )
return - V_7 ;
F_20 ( V_2 , V_28 , V_2 -> V_29 , L_18 ,
F_10 ( V_13 , V_225 ) ) ;
V_16 -> V_226 = F_10 ( V_13 , V_225 ) ;
V_16 -> V_227 = F_10 ( V_13 , V_228 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_229 , V_230 ;
unsigned int V_218 = F_84 ( V_231 ,
V_232 ? 2 : 1 ) ;
unsigned int V_233 , V_169 , V_219 ;
void T_7 * V_234 ;
int V_18 ;
V_233 = F_84 ( V_2 -> V_235 , V_2 -> V_173 * V_231 ) ;
#ifdef F_102
if ( V_174 != 0 &&
V_175 / V_174 * V_236 >=
V_2 -> V_173 ) {
unsigned int V_147 =
F_103 ( V_2 -> V_173 ,
V_175 / V_174 ) ;
V_18 = F_81 ( V_2 , V_147 ) ;
if ( V_18 )
F_14 ( V_2 , V_39 , V_2 -> V_29 ,
L_19 , V_18 ) ;
else
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_20 , V_147 ) ;
}
#else
V_16 -> V_147 = 0 ;
#endif
V_229 = F_104 ( ( V_233 - 1 ) * V_179 +
V_237 ) ;
if ( V_16 -> V_147 ) {
V_169 = V_229 / V_179 ;
V_230 = ( F_104 ( ( V_169 +
V_16 -> V_147 ) *
V_179 ) -
V_229 ) ;
V_219 = V_169 + V_16 -> V_147 ;
} else {
V_169 = 0 ;
V_230 = 0 ;
V_219 = V_233 ;
}
V_18 = F_78 ( V_2 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_100 ( V_2 , V_218 , V_219 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_16 -> V_227 < V_233 ) {
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_21
L_22 ) ;
V_2 -> V_112 = V_16 -> V_227 ;
V_2 -> V_113 =
V_16 -> V_227 / V_231 ;
F_78 ( V_2 ) ;
return - V_238 ;
}
if ( V_16 -> V_147 &&
V_16 -> V_227 <
V_169 + V_16 -> V_147 ) {
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_23 ,
V_16 -> V_227 , V_16 -> V_147 ) ;
F_80 ( V_2 ) ;
}
V_234 = F_105 ( V_2 -> V_239 , V_229 ) ;
if ( ! V_234 ) {
F_14 ( V_2 , V_39 , V_2 -> V_29 ,
L_24 ,
V_229 ) ;
return - V_99 ;
}
F_92 ( V_2 -> V_234 ) ;
V_2 -> V_234 = V_234 ;
if ( V_230 ) {
V_16 -> V_188 = F_106 ( V_2 -> V_239 +
V_229 ,
V_230 ) ;
if ( ! V_16 -> V_188 ) {
F_14 ( V_2 , V_39 , V_2 -> V_29 ,
L_25 ,
V_230 ) ;
return - V_99 ;
}
V_16 -> V_169 = V_169 ;
V_16 -> V_178 =
V_16 -> V_188 +
( V_169 * V_179 + V_237 -
V_229 ) ;
V_18 = F_82 ( V_2 ) ;
if ( V_18 )
F_80 ( V_2 ) ;
}
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_26 ,
& V_2 -> V_239 , V_2 -> V_234 , V_229 ,
V_16 -> V_188 , V_230 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
if ( V_16 -> V_240 ) {
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_240 = false ;
}
if ( V_16 -> V_241 ) {
V_18 = F_100 ( V_2 , V_16 -> V_227 ,
V_16 -> V_227 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_241 = false ;
}
if ( V_16 -> V_189 && V_16 -> V_147 ) {
V_18 = F_81 ( V_2 , V_16 -> V_147 ) ;
if ( V_18 == 0 ) {
V_18 = F_82 ( V_2 ) ;
if ( V_18 )
F_80 ( V_2 ) ;
}
if ( V_18 )
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_27 , V_18 ) ;
V_16 -> V_189 = false ;
}
V_18 = V_2 -> type -> V_242 ( V_2 , false , V_2 -> V_243 ) ;
V_2 -> V_244 = ( V_18 == 0 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
#ifdef F_69
unsigned int V_111 ;
#endif
V_16 -> V_241 = true ;
V_16 -> V_245 = true ;
V_16 -> V_189 = true ;
F_88 ( V_2 ) ;
V_16 -> V_119 = V_120 ;
V_16 -> V_246 = true ;
V_16 -> V_121 = V_78 ;
#ifdef F_69
if ( V_16 -> V_186 )
for ( V_111 = 0 ; V_111 < V_2 -> V_247 ; V_111 ++ )
V_16 -> V_186 [ V_111 ] . V_121 = 0 ;
#endif
}
static enum V_248 F_109 ( enum V_248 V_249 )
{
if ( V_249 == V_250 )
return V_251 ;
return F_110 ( V_249 ) ;
}
static int F_111 ( T_6 * V_252 )
{
enum {
V_253 = ( ( V_254 | V_255 ) <<
V_256 ) ,
V_257 = ( ( V_258 | V_259 |
V_260 | V_254 |
V_255 | V_261 ) <<
V_256 )
};
if ( ( * V_252 & V_257 ) == V_257 ) {
* V_252 &= ~ V_257 ;
return V_262 ;
}
if ( ( * V_252 & V_253 ) == V_253 ) {
* V_252 &= ~ V_253 ;
return V_123 ;
}
return - V_263 ;
}
static int F_112 ( struct V_1 * V_2 , enum V_248 V_248 )
{
int V_18 = F_63 ( V_2 , V_248 ) ;
if ( V_248 == V_262 && V_18 == - V_65 )
V_18 = 0 ;
if ( ( V_248 == V_123 ||
V_248 == V_264 ) && ! V_18 )
F_108 ( V_2 ) ;
return V_18 ;
}
static T_8 F_113 ( struct V_1 * V_2 )
{
T_8 V_265 = V_266 ;
T_6 V_267 = F_114 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_88 -> V_89 &
1 << V_90 ) )
return 0 ;
if ( V_267 & ( 1 << V_268 ) ) {
V_265 |= V_269 ;
if ( V_16 -> V_32 &
( 1 << V_270 ) )
V_265 |= V_271 ;
} else {
V_265 |= V_271 ;
}
if ( V_16 -> V_30 &
( 1 << V_272 ) )
V_265 |= V_273 ;
return V_265 ;
}
static void F_115 ( struct V_1 * V_2 , unsigned long * V_274 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_8 V_265 [ 2 ] ;
V_265 [ 0 ] = F_113 ( V_2 ) ;
if ( V_16 -> V_30 &
( 1 << V_275 ) ) {
V_265 [ 0 ] |= ~ ( ( 1ULL << V_276 ) - 1 ) ;
V_265 [ 1 ] = ( 1ULL << ( V_277 - 63 ) ) - 1 ;
} else {
V_265 [ 1 ] = 0 ;
}
#if V_278 == 64
F_13 ( F_116 ( V_277 ) != 2 ) ;
V_274 [ 0 ] = V_265 [ 0 ] ;
V_274 [ 1 ] = V_265 [ 1 ] ;
#else
F_13 ( F_116 ( V_277 ) != 3 ) ;
V_274 [ 0 ] = V_265 [ 0 ] & 0xffffffff ;
V_274 [ 1 ] = V_265 [ 0 ] >> 32 ;
V_274 [ 2 ] = V_265 [ 1 ] & 0xffffffff ;
#endif
}
static T_2 F_117 ( struct V_1 * V_2 , T_3 * V_279 )
{
F_118 ( V_274 , V_277 ) ;
F_115 ( V_2 , V_274 ) ;
return F_119 ( V_280 , V_277 ,
V_274 , V_279 ) ;
}
static T_2 F_120 ( struct V_1 * V_2 , T_8 * V_281 ,
struct V_282 * V_283 )
{
F_118 ( V_274 , V_277 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_8 * V_284 = V_16 -> V_284 ;
T_2 V_285 = 0 , V_164 ;
F_115 ( V_2 , V_274 ) ;
if ( V_281 ) {
F_121 (index, mask, EF10_STAT_COUNT) {
if ( V_280 [ V_164 ] . V_286 ) {
* V_281 ++ = V_284 [ V_164 ] ;
++ V_285 ;
}
}
}
if ( ! V_283 )
return V_285 ;
if ( V_16 -> V_30 &
1 << V_275 ) {
V_283 -> V_287 = V_284 [ V_276 ] +
V_284 [ V_288 ] +
V_284 [ V_289 ] ;
V_283 -> V_290 = V_284 [ V_291 ] +
V_284 [ V_292 ] +
V_284 [ V_293 ] ;
V_283 -> V_294 = V_284 [ V_295 ] +
V_284 [ V_296 ] +
V_284 [ V_297 ] ;
V_283 -> V_298 = V_284 [ V_299 ] +
V_284 [ V_300 ] +
V_284 [ V_301 ] ;
V_283 -> V_302 = V_284 [ V_303 ] +
V_284 [ V_304 ] ;
V_283 -> V_305 = V_284 [ V_288 ] ;
V_283 -> V_306 = V_284 [ V_307 ] ;
V_283 -> V_308 = V_284 [ V_309 ] ;
V_283 -> V_310 = V_283 -> V_306 ;
V_283 -> V_311 = V_284 [ V_312 ] ;
} else {
V_283 -> V_287 = V_284 [ V_313 ] ;
V_283 -> V_290 = V_284 [ V_314 ] ;
V_283 -> V_294 = V_284 [ V_315 ] ;
V_283 -> V_298 = V_284 [ V_316 ] ;
V_283 -> V_302 = V_284 [ V_317 ] +
V_284 [ V_303 ] +
V_284 [ V_304 ] ;
V_283 -> V_305 = V_284 [ V_318 ] ;
V_283 -> V_319 =
V_284 [ V_320 ] +
V_284 [ V_321 ] ;
V_283 -> V_306 = V_284 [ V_322 ] ;
V_283 -> V_323 =
V_284 [ V_324 ] ;
V_283 -> V_308 = V_284 [ V_325 ] ;
V_283 -> V_310 = ( V_283 -> V_319 +
V_283 -> V_306 +
V_283 -> V_323 ) ;
}
return V_285 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_118 ( V_274 , V_277 ) ;
T_9 V_326 , V_327 ;
T_8 * V_284 = V_16 -> V_284 ;
T_9 * V_328 ;
F_115 ( V_2 , V_274 ) ;
V_328 = V_2 -> V_329 . V_330 ;
V_327 = V_328 [ V_331 ] ;
if ( V_327 == V_332 )
return 0 ;
F_123 () ;
F_124 ( V_280 , V_277 , V_274 ,
V_284 , V_2 -> V_329 . V_330 , false ) ;
F_123 () ;
V_326 = V_328 [ V_333 ] ;
if ( V_327 != V_326 )
return - V_238 ;
F_125 ( V_2 ,
& V_284 [ V_317 ] ) ;
V_284 [ V_334 ] =
V_284 [ V_315 ] -
V_284 [ V_335 ] ;
F_126 ( & V_284 [ V_336 ] ,
V_284 [ V_335 ] ) ;
F_127 ( V_2 , V_284 ) ;
return 0 ;
}
static T_2 F_128 ( struct V_1 * V_2 , T_8 * V_281 ,
struct V_282 * V_283 )
{
int V_337 ;
for ( V_337 = 0 ; V_337 < 100 ; ++ V_337 ) {
if ( F_122 ( V_2 ) == 0 )
break;
F_129 ( 100 ) ;
}
return F_120 ( V_2 , V_281 , V_283 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_338 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
F_118 ( V_274 , V_277 ) ;
T_9 V_326 , V_327 ;
T_8 * V_284 = V_16 -> V_284 ;
T_6 V_339 = V_340 * sizeof( T_8 ) ;
struct V_341 V_342 ;
T_9 * V_328 ;
int V_18 ;
F_131 ( & V_2 -> V_343 ) ;
if ( F_132 () ) {
F_133 ( & V_2 -> V_343 ) ;
F_127 ( V_2 , V_284 ) ;
return 0 ;
}
F_115 ( V_2 , V_274 ) ;
V_18 = F_58 ( V_2 , & V_342 , V_339 , V_344 ) ;
if ( V_18 ) {
F_133 ( & V_2 -> V_343 ) ;
return V_18 ;
}
V_328 = V_342 . V_330 ;
V_328 [ V_331 ] = V_332 ;
F_134 ( V_73 , V_345 , V_342 . V_346 ) ;
F_135 ( V_73 , V_347 ,
V_348 , 1 ) ;
F_31 ( V_73 , V_349 , V_339 ) ;
F_31 ( V_73 , V_350 , V_78 ) ;
V_18 = F_25 ( V_2 , V_351 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
F_133 ( & V_2 -> V_343 ) ;
if ( V_18 ) {
if ( V_18 != - V_108 || F_136 ( & V_2 -> V_352 ) )
F_26 ( V_2 , V_351 ,
sizeof( V_73 ) , NULL , 0 , V_18 ) ;
goto V_353;
}
V_327 = V_328 [ V_331 ] ;
if ( V_327 == V_332 ) {
F_137 ( 1 ) ;
goto V_353;
}
F_123 () ;
F_124 ( V_280 , V_277 , V_274 ,
V_284 , V_342 . V_330 , false ) ;
F_123 () ;
V_326 = V_328 [ V_333 ] ;
if ( V_327 != V_326 ) {
V_18 = - V_238 ;
goto V_353;
}
F_127 ( V_2 , V_284 ) ;
V_353:
F_77 ( V_2 , & V_342 ) ;
return V_18 ;
}
static T_2 F_138 ( struct V_1 * V_2 , T_8 * V_281 ,
struct V_282 * V_283 )
{
if ( F_130 ( V_2 ) )
return 0 ;
return F_120 ( V_2 , V_281 , V_283 ) ;
}
static void F_139 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
unsigned int V_354 , V_355 ;
T_1 V_356 ;
if ( V_160 -> V_357 ) {
V_354 = 3 ;
V_355 = V_160 -> V_357 ;
} else {
V_354 = 0 ;
V_355 = 0 ;
}
if ( F_22 ( V_2 ) ) {
F_8 ( V_73 , V_358 ) ;
unsigned int V_359 = V_355 * 1000 ;
F_31 ( V_73 , V_360 ,
V_160 -> V_160 ) ;
F_31 ( V_73 , V_361 , V_359 ) ;
F_31 ( V_73 , V_362 , V_359 ) ;
F_31 ( V_73 , V_363 , V_354 ) ;
F_140 ( V_2 , V_364 ,
V_73 , sizeof( V_73 ) , 0 , NULL , 0 ) ;
} else if ( F_23 ( V_2 ) ) {
unsigned int V_365 = F_141 ( V_2 , V_355 ) ;
F_142 ( V_356 , V_366 ,
V_367 ,
V_368 , V_354 ,
V_369 , V_365 ) ;
F_143 ( V_2 , & V_356 , V_370 ,
V_160 -> V_160 ) ;
} else {
unsigned int V_365 = F_141 ( V_2 , V_355 ) ;
F_144 ( V_356 , V_371 , V_354 ,
V_372 , V_365 ) ;
F_143 ( V_2 , & V_356 , V_373 ,
V_160 -> V_160 ) ;
}
}
static void F_145 ( struct V_1 * V_2 ,
struct V_374 * V_375 ) {}
static int F_146 ( struct V_1 * V_2 , T_6 type )
{
return - V_376 ;
}
static void F_147 ( struct V_1 * V_2 , struct V_374 * V_375 )
{
V_375 -> V_377 = 0 ;
V_375 -> V_378 = 0 ;
memset ( & V_375 -> V_379 , 0 , sizeof( V_375 -> V_379 ) ) ;
}
static int F_148 ( struct V_1 * V_2 , T_6 type )
{
if ( type != 0 )
return - V_263 ;
return 0 ;
}
static void F_149 ( struct V_1 * V_2 ,
const T_1 * V_380 , T_2 V_381 ,
const T_1 * V_382 , T_2 V_383 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 * V_384 = V_16 -> V_115 . V_330 ;
memcpy ( V_384 , V_380 , V_381 ) ;
memcpy ( V_384 + V_381 , V_382 , V_383 ) ;
F_150 () ;
F_60 ( V_2 , F_61 ( ( T_8 ) V_16 -> V_115 . V_346 >> 32 ) ,
V_385 ) ;
F_60 ( V_2 , F_61 ( ( T_6 ) V_16 -> V_115 . V_346 ) ,
V_122 ) ;
}
static bool F_151 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_1 V_380 = * ( const T_1 * ) V_16 -> V_115 . V_330 ;
F_123 () ;
return F_3 ( V_380 , V_386 ) ;
}
static void
F_152 ( struct V_1 * V_2 , T_1 * V_13 ,
T_2 V_163 , T_2 V_17 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_3 * V_384 = V_16 -> V_115 . V_330 ;
memcpy ( V_13 , V_384 + V_163 , V_17 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_108 ( V_2 ) ;
V_16 -> V_240 = true ;
V_16 -> V_284 [ V_336 ] = 0 ;
}
static int F_154 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 ) {
return 0 ;
}
if ( V_18 == V_16 -> V_118 )
return 0 ;
V_16 -> V_118 = V_18 ;
F_153 ( V_2 ) ;
return - V_7 ;
}
static T_10 F_155 ( int V_387 , void * V_388 )
{
struct V_389 * V_390 = V_388 ;
struct V_1 * V_2 = V_390 -> V_2 ;
F_156 ( V_2 , V_391 , V_2 -> V_29 ,
L_28 , V_387 , F_157 () ) ;
if ( F_158 ( F_159 ( V_2 -> V_392 ) ) ) {
if ( V_390 -> V_164 == V_2 -> V_393 )
V_2 -> V_394 = F_157 () ;
F_160 ( V_2 -> V_160 [ V_390 -> V_164 ] ) ;
}
return V_395 ;
}
static T_10 F_161 ( int V_387 , void * V_388 )
{
struct V_1 * V_2 = V_388 ;
bool V_396 = F_159 ( V_2 -> V_392 ) ;
struct V_159 * V_160 ;
T_1 V_3 ;
T_6 V_397 ;
F_2 ( V_2 , & V_3 , V_398 ) ;
V_397 = F_3 ( V_3 , V_399 ) ;
if ( V_397 == 0 )
return V_400 ;
if ( F_158 ( V_396 ) ) {
if ( V_397 & ( 1U << V_2 -> V_393 ) )
V_2 -> V_394 = F_157 () ;
F_85 (channel, efx) {
if ( V_397 & 1 )
F_160 ( V_160 ) ;
V_397 >>= 1 ;
}
}
F_156 ( V_2 , V_391 , V_2 -> V_29 ,
L_29 V_401 L_30 ,
V_387 , F_157 () , F_162 ( V_3 ) ) ;
return V_395 ;
}
static int F_163 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_402 ) ;
if ( F_19 ( V_2 , V_403 , true ,
NULL ) == 0 )
return - V_404 ;
F_13 ( V_405 != 0 ) ;
F_31 ( V_73 , V_406 , V_2 -> V_393 ) ;
return F_9 ( V_2 , V_407 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
}
static int F_164 ( struct V_161 * V_162 )
{
return F_58 ( V_162 -> V_2 , & V_162 -> V_408 . V_87 ,
( V_162 -> V_409 + 1 ) *
sizeof( V_410 ) ,
V_100 ) ;
}
static inline void F_165 ( struct V_161 * V_162 ,
const V_410 * V_408 )
{
unsigned int V_411 ;
T_11 V_3 ;
V_411 = V_162 -> V_412 & V_162 -> V_409 ;
F_166 ( V_3 , V_413 , V_411 ) ;
V_3 . V_414 [ 0 ] = * V_408 ;
F_167 ( V_162 -> V_2 , & V_3 ,
V_415 , V_162 -> V_176 ) ;
}
static int F_168 ( struct V_161 * V_162 ,
struct V_416 * V_417 ,
bool * V_418 )
{
struct V_419 * V_420 ;
struct V_421 * V_422 ;
struct V_423 * V_424 ;
T_5 V_425 ;
T_6 V_426 ;
T_6 V_427 ;
F_169 ( V_162 -> V_428 != 2 ) ;
V_427 = F_170 ( V_417 ) -> V_429 ;
if ( F_171 ( V_427 < 4 ) ) {
F_172 ( 1 , L_31 , V_427 ) ;
return - V_263 ;
}
V_424 = F_173 ( V_417 ) ;
if ( V_424 -> V_430 == 4 ) {
V_424 -> V_431 = 0 ;
V_424 -> V_432 = 0 ;
V_425 = V_424 -> V_433 ;
} else {
struct V_434 * V_435 = F_174 ( V_417 ) ;
V_435 -> V_436 = 0 ;
V_425 = 0 ;
}
V_422 = F_175 ( V_417 ) ;
V_426 = F_176 ( V_422 -> V_437 ) ;
V_420 = F_177 ( V_162 ) ;
V_420 -> V_252 = V_438 ;
V_420 -> V_439 = 0 ;
V_420 -> V_440 = 0 ;
F_178 ( V_420 -> V_441 ,
V_442 , 1 ,
V_443 , V_444 ,
V_445 ,
V_446 ,
V_447 , V_425 ,
V_448 , V_426
) ;
++ V_162 -> V_449 ;
V_420 = F_177 ( V_162 ) ;
V_420 -> V_252 = V_438 ;
V_420 -> V_439 = 0 ;
V_420 -> V_440 = 0 ;
F_179 ( V_420 -> V_441 ,
V_442 , 1 ,
V_443 , V_444 ,
V_445 ,
V_450 ,
V_451 , V_427
) ;
++ V_162 -> V_449 ;
return 0 ;
}
static T_6 F_180 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_6 V_452 = 0 ;
if ( V_16 -> V_30 &
( 1 << V_453 ) )
V_452 |= F_181 ( 1 ) ;
if ( V_16 -> V_32 &
( 1 << V_454 ) )
V_452 |= F_181 ( 2 ) ;
return V_452 ;
}
static void F_182 ( struct V_161 * V_162 )
{
F_8 ( V_73 , F_183 ( V_455 * 8 /
V_456 ) ) ;
bool V_457 = V_162 -> V_176 & V_458 ;
T_2 V_459 = V_162 -> V_408 . V_87 . V_439 / V_456 ;
struct V_159 * V_160 = V_162 -> V_160 ;
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_460 = false ;
T_2 V_461 ;
T_12 V_346 ;
V_410 * V_408 ;
int V_18 ;
int V_111 ;
F_13 ( V_462 != 0 ) ;
if ( V_457 && ( V_16 -> V_32 &
( 1 << V_454 ) ) ) {
V_460 = true ;
F_20 ( V_2 , V_463 , V_2 -> V_29 , L_32 ,
V_160 -> V_160 ) ;
}
F_31 ( V_73 , V_464 , V_162 -> V_409 + 1 ) ;
F_31 ( V_73 , V_465 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_466 , V_162 -> V_176 ) ;
F_31 ( V_73 , V_467 , V_162 -> V_176 ) ;
F_31 ( V_73 , V_468 , 0 ) ;
F_31 ( V_73 , V_469 , V_16 -> V_121 ) ;
V_346 = V_162 -> V_408 . V_87 . V_346 ;
F_20 ( V_2 , V_463 , V_2 -> V_29 , L_33 ,
V_162 -> V_176 , V_459 , ( T_8 ) V_346 ) ;
for ( V_111 = 0 ; V_111 < V_459 ; ++ V_111 ) {
F_184 ( V_73 , V_470 , V_111 , V_346 ) ;
V_346 += V_456 ;
}
V_461 = F_183 ( V_459 ) ;
do {
F_185 ( V_73 , V_471 ,
V_472 , V_460 ,
V_473 , ! V_457 ,
V_474 , ! V_457 ) ;
V_18 = F_25 ( V_2 , V_475 , V_73 , V_461 ,
NULL , 0 , NULL ) ;
if ( V_18 == - V_155 && V_460 ) {
V_460 = false ;
F_42 ( V_2 , V_39 , V_2 -> V_29 ,
L_34 ) ;
} else if ( V_18 ) {
F_26 ( V_2 , V_475 ,
V_476 ,
NULL , 0 , V_18 ) ;
goto V_171;
}
} while ( V_18 );
V_162 -> V_420 [ 0 ] . V_252 = V_438 ;
V_162 -> V_449 = 1 ;
V_408 = F_186 ( V_162 , 0 ) ;
F_179 ( * V_408 ,
V_442 , true ,
V_443 ,
V_477 ,
V_478 , V_457 ,
V_479 , V_457 ) ;
V_162 -> V_412 = 1 ;
if ( V_460 ) {
V_162 -> V_480 = F_168 ;
V_162 -> V_428 = 2 ;
} else if ( V_16 -> V_30 &
( 1 << V_453 ) ) {
V_162 -> V_428 = 1 ;
}
F_150 () ;
F_165 ( V_162 , V_408 ) ;
return;
V_171:
F_187 ( V_2 -> V_29 , L_35 ,
V_162 -> V_176 ) ;
}
static void F_188 ( struct V_161 * V_162 )
{
F_8 ( V_73 , V_481 ) ;
F_79 ( V_13 ) ;
struct V_1 * V_2 = V_162 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_31 ( V_73 , V_482 ,
V_162 -> V_176 ) ;
V_18 = F_25 ( V_2 , V_483 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_97 )
goto V_171;
return;
V_171:
F_26 ( V_2 , V_483 , V_481 ,
V_13 , V_17 , V_18 ) ;
}
static void F_189 ( struct V_161 * V_162 )
{
F_77 ( V_162 -> V_2 , & V_162 -> V_408 . V_87 ) ;
}
static inline void F_190 ( struct V_161 * V_162 )
{
unsigned int V_411 ;
T_1 V_3 ;
V_411 = V_162 -> V_412 & V_162 -> V_409 ;
F_191 ( V_3 , V_484 , V_411 ) ;
F_143 ( V_162 -> V_2 , & V_3 ,
V_485 , V_162 -> V_176 ) ;
}
static unsigned int F_192 ( struct V_161 * V_162 ,
T_12 V_346 , unsigned int V_439 )
{
if ( V_439 > V_486 ) {
T_12 V_487 = V_346 + V_486 ;
F_13 ( V_486 < V_488 ) ;
V_439 = ( V_487 & ( ~ ( V_488 - 1 ) ) ) - V_346 ;
}
return V_439 ;
}
static void F_193 ( struct V_161 * V_162 )
{
unsigned int V_489 = V_162 -> V_412 ;
struct V_419 * V_420 ;
unsigned int V_411 ;
V_410 * V_408 ;
V_162 -> V_490 = false ;
if ( F_171 ( V_162 -> V_412 == V_162 -> V_449 ) )
return;
do {
V_411 = V_162 -> V_412 & V_162 -> V_409 ;
V_420 = & V_162 -> V_420 [ V_411 ] ;
V_408 = F_186 ( V_162 , V_411 ) ;
++ V_162 -> V_412 ;
if ( V_420 -> V_252 & V_438 ) {
* V_408 = V_420 -> V_441 ;
} else {
F_13 ( V_491 != 1 ) ;
F_194 (
* V_408 ,
V_492 ,
V_420 -> V_252 & V_491 ,
V_493 , V_420 -> V_439 ,
V_494 , V_420 -> V_346 ) ;
}
} while ( V_162 -> V_412 != V_162 -> V_449 );
F_150 () ;
if ( F_195 ( V_162 , V_489 ) ) {
V_408 = F_186 ( V_162 ,
V_489 & V_162 -> V_409 ) ;
F_165 ( V_162 , V_408 ) ;
++ V_162 -> V_495 ;
} else {
F_190 ( V_162 ) ;
}
}
static int F_196 ( struct V_1 * V_2 , T_6 V_390 , T_6 * V_252 )
{
F_8 ( V_73 , V_496 ) ;
F_8 ( V_13 , V_496 ) ;
T_2 V_17 ;
int V_18 ;
F_13 ( V_497 != V_498 ) ;
F_31 ( V_73 , V_499 , V_390 ) ;
F_31 ( V_73 , V_500 ,
V_501 ) ;
V_18 = F_9 ( V_2 , V_502 , V_73 ,
sizeof( V_73 ) , V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 == 0 ) {
if ( V_17 < V_496 )
V_18 = - V_7 ;
else
* V_252 = F_10 ( V_13 , V_500 ) ;
}
return V_18 ;
}
static void F_197 ( struct V_1 * V_2 , T_6 V_390 )
{
F_8 ( V_73 , V_503 ) ;
T_6 V_252 ;
F_13 ( V_504 != 0 ) ;
if ( F_196 ( V_2 , V_390 , & V_252 ) != 0 )
return;
F_31 ( V_73 , V_505 , V_390 ) ;
V_252 |= V_506 << V_507 ;
V_252 |= V_506 << V_508 ;
F_31 ( V_73 , V_509 , V_252 ) ;
if ( ! F_9 ( V_2 , V_510 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) )
V_2 -> V_511 = true ;
}
static int F_198 ( struct V_1 * V_2 , T_6 * V_390 ,
bool V_512 , unsigned * V_513 )
{
F_8 ( V_73 , V_514 ) ;
F_8 ( V_13 , V_515 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_6 V_516 = V_512 ?
V_517 :
V_518 ;
unsigned V_519 = V_512 ?
V_2 -> V_519 :
F_199 ( F_200 ( V_2 -> V_519 ) ,
V_520 ) ;
if ( ! V_512 && V_519 == 1 ) {
* V_390 = V_120 ;
if ( V_513 )
* V_513 = 1 ;
return 0 ;
}
if ( V_16 -> V_30 &
1 << V_521 )
return - V_376 ;
F_31 ( V_73 , V_522 ,
V_16 -> V_121 ) ;
F_31 ( V_73 , V_523 , V_516 ) ;
F_31 ( V_73 , V_524 , V_519 ) ;
V_18 = F_9 ( V_2 , V_525 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_515 )
return - V_7 ;
* V_390 = F_10 ( V_13 , V_526 ) ;
if ( V_513 )
* V_513 = V_519 ;
if ( V_16 -> V_30 &
1 << V_527 )
F_197 ( V_2 , * V_390 ) ;
return 0 ;
}
static void F_201 ( struct V_1 * V_2 , T_6 V_390 )
{
F_8 ( V_73 , V_528 ) ;
int V_18 ;
F_31 ( V_73 , V_529 ,
V_390 ) ;
V_18 = F_9 ( V_2 , V_530 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
F_32 ( V_18 != 0 ) ;
}
static int F_202 ( struct V_1 * V_2 , T_6 V_390 ,
const T_6 * V_243 )
{
F_8 ( V_531 , V_532 ) ;
F_8 ( V_533 , V_534 ) ;
int V_111 , V_18 ;
F_31 ( V_531 , V_535 ,
V_390 ) ;
F_13 ( F_203 ( V_2 -> V_243 ) !=
V_536 ) ;
for ( V_111 = 0 ; V_111 < F_203 ( V_2 -> V_243 ) ; ++ V_111 )
F_29 ( V_531 ,
V_537 ) [ V_111 ] =
( T_3 ) V_243 [ V_111 ] ;
V_18 = F_9 ( V_2 , V_538 , V_531 ,
sizeof( V_531 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_31 ( V_533 , V_539 ,
V_390 ) ;
F_13 ( F_203 ( V_2 -> V_540 ) !=
V_541 ) ;
for ( V_111 = 0 ; V_111 < F_203 ( V_2 -> V_540 ) ; ++ V_111 )
F_29 ( V_533 , V_542 ) [ V_111 ] =
V_2 -> V_540 [ V_111 ] ;
return F_9 ( V_2 , V_543 , V_533 ,
sizeof( V_533 ) , NULL , 0 , NULL ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_119 != V_120 )
F_201 ( V_2 , V_16 -> V_119 ) ;
V_16 -> V_119 = V_120 ;
}
static int F_204 ( struct V_1 * V_2 ,
unsigned * V_513 )
{
T_6 V_544 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_198 ( V_2 , & V_544 ,
false , V_513 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_119 = V_544 ;
V_16 -> V_545 = false ;
F_205 ( V_2 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_2 ,
const T_6 * V_243 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_544 ;
if ( V_16 -> V_119 == V_120 ||
! V_16 -> V_545 ) {
V_18 = F_198 ( V_2 , & V_544 ,
true , NULL ) ;
if ( V_18 == - V_376 )
return V_18 ;
else if ( V_18 != 0 )
goto V_116;
} else {
V_544 = V_16 -> V_119 ;
}
V_18 = F_202 ( V_2 , V_544 ,
V_243 ) ;
if ( V_18 != 0 )
goto V_117;
if ( V_16 -> V_119 != V_544 )
F_91 ( V_2 ) ;
V_16 -> V_119 = V_544 ;
V_16 -> V_545 = true ;
if ( V_243 != V_2 -> V_243 )
memcpy ( V_2 -> V_243 , V_243 ,
sizeof( V_2 -> V_243 ) ) ;
return 0 ;
V_117:
if ( V_544 != V_16 -> V_119 )
F_201 ( V_2 , V_544 ) ;
V_116:
F_14 ( V_2 , V_463 , V_2 -> V_29 , L_36 , V_546 , V_18 ) ;
return V_18 ;
}
static int F_207 ( struct V_1 * V_2 , bool V_547 ,
const T_6 * V_243 )
{
int V_18 ;
if ( V_2 -> V_519 == 1 )
return 0 ;
V_18 = F_206 ( V_2 , V_243 ) ;
if ( V_18 == - V_183 && ! V_547 ) {
unsigned V_513 ;
bool V_548 = false ;
T_2 V_111 ;
for ( V_111 = 0 ; V_111 < F_203 ( V_2 -> V_243 ) && ! V_548 ;
V_111 ++ )
V_548 = V_243 [ V_111 ] !=
F_208 ( V_111 , V_2 -> V_519 ) ;
V_18 = F_204 ( V_2 , & V_513 ) ;
if ( V_18 == 0 ) {
if ( V_513 != V_2 -> V_519 )
F_42 ( V_2 , V_39 , V_2 -> V_29 ,
L_37
L_38
L_39
L_40 ,
V_2 -> V_519 , V_513 ) ;
else if ( V_548 )
F_42 ( V_2 , V_39 , V_2 -> V_29 ,
L_37
L_41
L_42
L_43 ) ;
else
F_90 ( V_2 , V_39 , V_2 -> V_29 ,
L_37
L_44 ) ;
}
}
return V_18 ;
}
static int F_209 ( struct V_549 * V_550 )
{
return F_58 ( V_550 -> V_2 , & V_550 -> V_551 . V_87 ,
( V_550 -> V_409 + 1 ) *
sizeof( V_410 ) ,
V_100 ) ;
}
static void F_210 ( struct V_549 * V_550 )
{
F_8 ( V_73 ,
F_211 ( V_455 * 8 /
V_456 ) ) ;
struct V_159 * V_160 = F_212 ( V_550 ) ;
T_2 V_459 = V_550 -> V_551 . V_87 . V_439 / V_456 ;
struct V_1 * V_2 = V_550 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_461 ;
T_12 V_346 ;
int V_18 ;
int V_111 ;
F_13 ( V_552 != 0 ) ;
V_550 -> V_553 = 0 ;
V_550 -> V_554 = 0 ;
F_31 ( V_73 , V_555 , V_550 -> V_409 + 1 ) ;
F_31 ( V_73 , V_556 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_557 , F_213 ( V_550 ) ) ;
F_31 ( V_73 , V_558 ,
F_213 ( V_550 ) ) ;
F_214 ( V_73 , V_559 ,
V_560 , 1 ,
V_561 , 1 ) ;
F_31 ( V_73 , V_562 , 0 ) ;
F_31 ( V_73 , V_563 , V_16 -> V_121 ) ;
V_346 = V_550 -> V_551 . V_87 . V_346 ;
F_20 ( V_2 , V_463 , V_2 -> V_29 , L_45 ,
F_213 ( V_550 ) , V_459 , ( T_8 ) V_346 ) ;
for ( V_111 = 0 ; V_111 < V_459 ; ++ V_111 ) {
F_184 ( V_73 , V_564 , V_111 , V_346 ) ;
V_346 += V_456 ;
}
V_461 = F_211 ( V_459 ) ;
V_18 = F_9 ( V_2 , V_565 , V_73 , V_461 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_187 ( V_2 -> V_29 , L_46 ,
F_213 ( V_550 ) ) ;
}
static void F_215 ( struct V_549 * V_550 )
{
F_8 ( V_73 , V_566 ) ;
F_79 ( V_13 ) ;
struct V_1 * V_2 = V_550 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_31 ( V_73 , V_567 ,
F_213 ( V_550 ) ) ;
V_18 = F_25 ( V_2 , V_568 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_97 )
goto V_171;
return;
V_171:
F_26 ( V_2 , V_568 , V_566 ,
V_13 , V_17 , V_18 ) ;
}
static void F_216 ( struct V_549 * V_550 )
{
F_77 ( V_550 -> V_2 , & V_550 -> V_551 . V_87 ) ;
}
static inline void
F_217 ( struct V_549 * V_550 , unsigned int V_164 )
{
struct V_569 * V_570 ;
V_410 * V_551 ;
V_551 = F_218 ( V_550 , V_164 ) ;
V_570 = V_569 ( V_550 , V_164 ) ;
F_219 ( * V_551 ,
V_571 , V_570 -> V_439 ,
V_572 , V_570 -> V_346 ) ;
}
static void F_220 ( struct V_549 * V_550 )
{
struct V_1 * V_2 = V_550 -> V_2 ;
unsigned int V_412 ;
T_1 V_3 ;
V_412 = V_550 -> V_573 & ~ 7 ;
if ( V_550 -> V_574 == V_412 )
return;
do
F_217 (
V_550 ,
V_550 -> V_574 & V_550 -> V_409 ) ;
while ( ++ V_550 -> V_574 != V_412 );
F_150 () ;
F_191 ( V_3 , V_575 ,
V_412 & V_550 -> V_409 ) ;
F_143 ( V_2 , & V_3 , V_576 ,
F_213 ( V_550 ) ) ;
}
static void F_221 ( struct V_549 * V_550 )
{
struct V_159 * V_160 = F_212 ( V_550 ) ;
F_8 ( V_73 , V_577 ) ;
V_410 V_578 ;
F_219 ( V_578 ,
V_579 , V_580 ,
V_581 , V_582 ) ;
F_31 ( V_73 , V_583 , V_160 -> V_160 ) ;
memcpy ( F_29 ( V_73 , V_584 ) , & V_578 . T_8 [ 0 ] ,
sizeof( V_410 ) ) ;
F_140 ( V_160 -> V_2 , V_585 ,
V_73 , sizeof( V_73 ) , 0 ,
V_586 , 0 ) ;
}
static void
V_586 ( struct V_1 * V_2 , unsigned long V_587 ,
int V_18 , T_1 * V_13 ,
T_2 V_588 )
{
}
static int F_222 ( struct V_159 * V_160 )
{
return F_58 ( V_160 -> V_2 , & V_160 -> V_589 . V_87 ,
( V_160 -> V_590 + 1 ) *
sizeof( V_410 ) ,
V_100 ) ;
}
static void F_223 ( struct V_159 * V_160 )
{
F_8 ( V_73 , V_591 ) ;
F_79 ( V_13 ) ;
struct V_1 * V_2 = V_160 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_31 ( V_73 , V_592 , V_160 -> V_160 ) ;
V_18 = F_25 ( V_2 , V_593 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_97 )
goto V_171;
return;
V_171:
F_26 ( V_2 , V_593 , V_591 ,
V_13 , V_17 , V_18 ) ;
}
static int F_224 ( struct V_159 * V_160 )
{
F_8 ( V_73 ,
F_225 ( V_594 * 8 /
V_456 ) ) ;
F_8 ( V_13 , V_595 ) ;
T_2 V_459 = V_160 -> V_589 . V_87 . V_439 / V_456 ;
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_15 * V_16 ;
T_2 V_461 , V_17 ;
unsigned int V_46 , V_45 ;
T_12 V_346 ;
int V_18 ;
int V_111 ;
V_16 = V_2 -> V_16 ;
memset ( V_160 -> V_589 . V_87 . V_330 , 0xff , V_160 -> V_589 . V_87 . V_439 ) ;
F_31 ( V_73 , V_596 , V_160 -> V_590 + 1 ) ;
F_31 ( V_73 , V_597 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_598 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_599 ,
V_600 ) ;
F_31 ( V_73 , V_601 , 0 ) ;
F_31 ( V_73 , V_602 , 0 ) ;
F_31 ( V_73 , V_603 ,
V_604 ) ;
F_31 ( V_73 , V_605 , 0 ) ;
if ( V_16 -> V_32 &
1 << V_606 ) {
F_214 ( V_73 , V_607 ,
V_608 , 1 ,
V_609 ,
V_610 ) ;
} else {
bool V_611 = ! ( V_16 -> V_30 &
1 << V_612 ) ;
F_226 ( V_73 , V_613 ,
V_614 , 1 ,
V_615 , 1 ,
V_616 , 1 ,
V_617 , V_611 ) ;
}
V_346 = V_160 -> V_589 . V_87 . V_346 ;
for ( V_111 = 0 ; V_111 < V_459 ; ++ V_111 ) {
F_184 ( V_73 , V_618 , V_111 , V_346 ) ;
V_346 += V_456 ;
}
V_461 = F_227 ( V_459 ) ;
V_18 = F_9 ( V_2 , V_619 , V_73 , V_461 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_17 >= V_595 )
F_20 ( V_2 , V_28 , V_2 -> V_29 ,
L_47 ,
V_160 -> V_160 ,
F_10 ( V_13 , V_620 ) ) ;
if ( V_160 -> V_160 || V_18 )
return V_18 ;
V_18 = F_18 ( V_2 , & V_45 , & V_46 ) ;
if ( V_18 == - V_49 ) {
V_16 -> V_621 = false ;
V_18 = 0 ;
} else if ( V_18 ) {
goto V_171;
} else {
V_16 -> V_621 =
! ! ( V_46 & V_622 ) ;
if ( V_45 & V_622 &&
! V_16 -> V_621 ) {
unsigned int V_252 ;
V_18 = F_19 ( V_2 ,
V_623 ,
true , & V_252 ) ;
if ( ! V_18 ) {
if ( V_252 &
1 << V_624 ) {
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_48 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 ) {
V_16 -> V_118 = V_18 ;
V_18 = 0 ;
}
}
V_16 -> V_621 = true ;
} else if ( V_18 == - V_65 ) {
V_18 = 0 ;
}
}
}
if ( ! V_18 )
return 0 ;
V_171:
F_223 ( V_160 ) ;
return V_18 ;
}
static void F_228 ( struct V_159 * V_160 )
{
F_77 ( V_160 -> V_2 , & V_160 -> V_589 . V_87 ) ;
}
static void F_229 ( struct V_549 * V_550 ,
unsigned int V_625 )
{
struct V_1 * V_2 = V_550 -> V_2 ;
F_90 ( V_2 , V_463 , V_2 -> V_29 ,
L_49 ,
F_213 ( V_550 ) , V_625 ) ;
F_230 ( V_2 , V_626 ) ;
}
static void
F_231 ( struct V_549 * V_550 ,
unsigned int V_627 , unsigned int V_628 )
{
unsigned int V_629 = ( V_627 - V_628 ) & V_550 -> V_409 ;
struct V_1 * V_2 = V_550 -> V_2 ;
F_90 ( V_2 , V_463 , V_2 -> V_29 ,
L_50 ,
V_629 , V_627 , V_628 ) ;
F_230 ( V_2 , V_626 ) ;
}
static void F_232 ( struct V_549 * V_550 )
{
unsigned int V_630 ;
F_20 ( V_550 -> V_2 , V_463 , V_550 -> V_2 -> V_29 ,
L_51 ,
V_550 -> V_553 ) ;
V_630 = V_550 -> V_631 & V_550 -> V_409 ;
F_233 ( V_550 , V_630 , V_550 -> V_553 ,
0 , V_632 ) ;
V_550 -> V_631 += V_550 -> V_553 ;
V_550 -> V_553 = 0 ;
V_550 -> V_554 = 0 ;
++ F_212 ( V_550 ) -> V_633 ;
}
static int F_234 ( struct V_159 * V_160 ,
const V_410 * V_578 )
{
unsigned int V_294 , V_634 , V_625 , V_635 ;
unsigned int V_636 , V_637 , V_111 ;
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_549 * V_550 ;
bool V_638 ;
T_5 V_252 = 0 ;
if ( F_171 ( F_159 ( V_2 -> V_639 ) ) )
return 0 ;
V_294 = F_235 ( * V_578 , V_640 ) ;
V_634 = F_235 ( * V_578 , V_641 ) ;
V_625 = F_235 ( * V_578 , V_642 ) ;
V_635 = F_235 ( * V_578 , V_643 ) ;
V_638 = F_235 ( * V_578 , V_644 ) ;
if ( F_235 ( * V_578 , V_645 ) )
F_187 ( V_2 -> V_29 , L_52
V_646 L_30 ,
F_236 ( * V_578 ) ) ;
V_550 = F_237 ( V_160 ) ;
if ( F_171 ( V_625 != F_213 ( V_550 ) ) )
F_229 ( V_550 , V_625 ) ;
V_636 = ( ( V_634 - V_550 -> V_631 ) &
( ( 1 << V_647 ) - 1 ) ) ;
if ( V_636 != V_550 -> V_553 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_171 ( V_636 == V_550 -> V_553 ) ) {
if ( V_550 -> V_553 == 0 || V_294 != 0 )
F_187 ( V_2 -> V_29 ,
L_53
V_646 L_30 ,
V_550 -> V_553 ,
F_236 ( * V_578 ) ) ;
F_232 ( V_550 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_30 &
( 1 << V_612 ) ) ||
V_550 -> V_553 != 0 || V_638 ) {
F_231 (
V_550 , V_634 ,
( V_550 -> V_631 +
V_550 -> V_553 + 1 ) &
( ( 1 << V_647 ) - 1 ) ) ;
return 0 ;
}
V_550 -> V_553 = 1 ;
V_550 -> V_554 = 0 ;
V_637 = V_636 ;
++ V_160 -> V_648 ;
V_160 -> V_649 += V_637 ;
V_252 |= V_650 ;
} else {
++ V_550 -> V_553 ;
V_550 -> V_554 += V_294 ;
if ( V_638 )
return 0 ;
V_637 = 1 ;
}
if ( F_171 ( F_235 ( * V_578 , V_651 ) ) )
V_252 |= V_632 ;
if ( F_171 ( F_235 ( * V_578 , V_652 ) ) ) {
V_160 -> V_653 += V_637 ;
} else if ( F_171 ( F_235 ( * V_578 ,
V_654 ) ) ) {
V_160 -> V_655 += V_637 ;
} else if ( V_635 == V_656 ||
V_635 == V_657 ) {
V_252 |= V_658 ;
}
if ( V_635 == V_656 )
V_252 |= V_659 ;
V_160 -> V_660 += 2 * V_637 ;
for ( V_111 = 0 ; V_111 < V_637 ; V_111 ++ ) {
F_233 ( V_550 ,
V_550 -> V_631 & V_550 -> V_409 ,
V_550 -> V_553 , V_550 -> V_554 ,
V_252 ) ;
V_550 -> V_631 += V_550 -> V_553 ;
}
V_550 -> V_553 = 0 ;
V_550 -> V_554 = 0 ;
return V_637 ;
}
static int
F_238 ( struct V_159 * V_160 , V_410 * V_578 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_161 * V_162 ;
unsigned int V_661 ;
unsigned int V_662 ;
int V_663 = 0 ;
if ( F_171 ( F_159 ( V_2 -> V_639 ) ) )
return 0 ;
if ( F_171 ( F_235 ( * V_578 , V_664 ) ) )
return 0 ;
V_661 = F_235 ( * V_578 , V_665 ) ;
V_662 = F_235 ( * V_578 , V_666 ) ;
V_162 = F_239 ( V_160 ,
V_662 % V_231 ) ;
V_663 = ( ( V_661 + 1 - V_162 -> V_667 ) &
V_162 -> V_409 ) ;
F_240 ( V_162 , V_661 & V_162 -> V_409 ) ;
return V_663 ;
}
static void
F_241 ( struct V_159 * V_160 , V_410 * V_578 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
int V_668 ;
V_668 = F_235 ( * V_578 , V_669 ) ;
switch ( V_668 ) {
case V_670 :
case V_671 :
break;
case V_672 :
break;
default:
F_14 ( V_2 , V_463 , V_2 -> V_29 ,
L_54
L_55 V_646 L_56 ,
V_160 -> V_160 , V_668 ,
F_236 ( * V_578 ) ) ;
}
}
static void F_242 ( struct V_159 * V_160 ,
V_410 * V_578 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
T_6 V_668 ;
V_668 = F_235 ( * V_578 , V_673 ) ;
switch ( V_668 ) {
case V_674 :
V_160 -> V_675 = F_157 () ;
break;
case V_582 :
F_243 ( & V_160 -> V_550 , true ) ;
break;
default:
F_14 ( V_2 , V_463 , V_2 -> V_29 ,
L_57
L_55 V_646 L_56 ,
V_160 -> V_160 , ( unsigned ) V_668 ,
F_236 ( * V_578 ) ) ;
}
}
static int F_244 ( struct V_159 * V_160 , int V_676 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
V_410 V_578 , * V_677 ;
unsigned int V_678 ;
int V_679 ;
int V_663 = 0 ;
int V_680 = 0 ;
if ( V_676 <= 0 )
return V_680 ;
V_678 = V_160 -> V_681 ;
for (; ; ) {
V_677 = F_245 ( V_160 , V_678 ) ;
V_578 = * V_677 ;
if ( ! F_246 ( & V_578 ) )
break;
F_247 ( * V_677 ) ;
++ V_678 ;
V_679 = F_235 ( V_578 , V_579 ) ;
F_156 ( V_2 , V_28 , V_2 -> V_29 ,
L_58 V_646 L_30 ,
V_160 -> V_160 , F_236 ( V_578 ) ) ;
switch ( V_679 ) {
case V_682 :
F_248 ( V_160 , & V_578 ) ;
break;
case V_683 :
V_680 += F_234 ( V_160 , & V_578 ) ;
if ( V_680 >= V_676 ) {
V_680 = V_676 ;
goto V_353;
}
break;
case V_684 :
V_663 += F_238 ( V_160 , & V_578 ) ;
if ( V_663 > V_2 -> V_685 ) {
V_680 = V_676 ;
goto V_353;
} else if ( ++ V_680 == V_676 ) {
goto V_353;
}
break;
case V_686 :
F_241 ( V_160 , & V_578 ) ;
if ( ++ V_680 == V_676 )
goto V_353;
break;
case V_580 :
F_242 ( V_160 , & V_578 ) ;
break;
default:
F_14 ( V_2 , V_463 , V_2 -> V_29 ,
L_59
L_55 V_646 L_56 ,
V_160 -> V_160 , V_679 ,
F_236 ( V_578 ) ) ;
}
}
V_353:
V_160 -> V_681 = V_678 ;
return V_680 ;
}
static void F_249 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
T_1 V_687 ;
if ( F_23 ( V_2 ) ) {
F_13 ( V_688 <
( 1 << V_689 ) ) ;
F_13 ( V_594 >
( 1 << 2 * V_689 ) ) ;
F_144 ( V_687 , V_690 ,
V_691 ,
V_692 ,
( V_160 -> V_681 &
V_160 -> V_590 ) >>
V_689 ) ;
F_143 ( V_2 , & V_687 , V_370 ,
V_160 -> V_160 ) ;
F_144 ( V_687 , V_690 ,
V_693 ,
V_692 ,
V_160 -> V_681 &
( ( 1 << V_689 ) - 1 ) ) ;
F_143 ( V_2 , & V_687 , V_370 ,
V_160 -> V_160 ) ;
} else {
F_191 ( V_687 , V_694 ,
V_160 -> V_681 &
V_160 -> V_590 ) ;
F_143 ( V_2 , & V_687 , V_695 , V_160 -> V_160 ) ;
}
}
static void F_250 ( struct V_159 * V_160 )
{
F_8 ( V_73 , V_577 ) ;
struct V_1 * V_2 = V_160 -> V_2 ;
V_410 V_578 ;
int V_18 ;
F_219 ( V_578 ,
V_579 , V_580 ,
V_581 , V_674 ) ;
F_31 ( V_73 , V_583 , V_160 -> V_160 ) ;
memcpy ( F_29 ( V_73 , V_584 ) , & V_578 . T_8 [ 0 ] ,
sizeof( V_410 ) ) ;
V_18 = F_9 ( V_2 , V_585 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_171;
return;
V_171:
F_32 ( true ) ;
F_14 ( V_2 , V_463 , V_2 -> V_29 , L_36 , V_546 , V_18 ) ;
}
void F_251 ( struct V_1 * V_2 )
{
if ( F_252 ( & V_2 -> V_352 ) )
F_253 ( & V_2 -> V_696 ) ;
F_32 ( F_136 ( & V_2 -> V_352 ) < 0 ) ;
}
static int F_254 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
struct V_549 * V_550 ;
int V_697 ;
if ( V_16 -> V_241 ) {
F_255 ( & V_2 -> V_352 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_698 != V_699 ) {
F_85 (channel, efx) {
F_256 (rx_queue, channel)
F_215 ( V_550 ) ;
F_86 (tx_queue, channel)
F_188 ( V_162 ) ;
}
F_257 ( V_2 -> V_696 ,
F_136 ( & V_2 -> V_352 ) == 0 ,
F_258 ( V_700 ) ) ;
V_697 = F_136 ( & V_2 -> V_352 ) ;
if ( V_697 ) {
F_14 ( V_2 , V_463 , V_2 -> V_29 , L_60 ,
V_697 ) ;
return - V_701 ;
}
}
return 0 ;
}
static void F_259 ( struct V_1 * V_2 )
{
F_255 ( & V_2 -> V_352 , 0 ) ;
}
static bool F_260 ( const struct V_702 * V_703 ,
const struct V_702 * V_704 )
{
if ( ( V_703 -> V_705 ^ V_704 -> V_705 ) |
( ( V_703 -> V_252 ^ V_704 -> V_252 ) &
( V_706 | V_707 ) ) )
return false ;
return memcmp ( & V_703 -> V_708 , & V_704 -> V_708 ,
sizeof( struct V_702 ) -
F_261 ( struct V_702 , V_708 ) ) == 0 ;
}
static unsigned int F_262 ( const struct V_702 * V_709 )
{
F_13 ( F_261 ( struct V_702 , V_708 ) & 3 ) ;
return F_263 ( ( const T_6 * ) & V_709 -> V_708 ,
( sizeof( struct V_702 ) -
F_261 ( struct V_702 , V_708 ) ) / 4 ,
0 ) ;
}
static bool F_264 ( const struct V_702 * V_709 )
{
if ( V_709 -> V_705 & V_710 &&
! F_265 ( V_709 -> V_711 ) )
return true ;
if ( ( V_709 -> V_705 &
( V_712 | V_713 ) ) ==
( V_712 | V_713 ) ) {
if ( V_709 -> V_714 == F_266 ( V_715 ) &&
! F_267 ( V_709 -> V_716 [ 0 ] ) )
return true ;
if ( V_709 -> V_714 == F_266 ( V_717 ) &&
( ( const T_3 * ) V_709 -> V_716 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_702 *
F_268 ( const struct V_718 * V_719 ,
unsigned int V_720 )
{
return (struct V_702 * ) ( V_719 -> V_721 [ V_720 ] . V_709 &
~ V_722 ) ;
}
static unsigned int
F_269 ( const struct V_718 * V_719 ,
unsigned int V_720 )
{
return V_719 -> V_721 [ V_720 ] . V_709 & V_722 ;
}
static void
F_270 ( struct V_718 * V_719 ,
unsigned int V_720 ,
const struct V_702 * V_709 ,
unsigned int V_252 )
{
V_719 -> V_721 [ V_720 ] . V_709 = ( unsigned long ) V_709 | V_252 ;
}
static void F_271 ( struct V_1 * V_2 ,
const struct V_702 * V_709 ,
T_1 * V_73 , T_8 V_723 ,
bool V_724 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_6 V_252 = V_709 -> V_252 ;
memset ( V_73 , 0 , V_725 ) ;
if ( V_252 & V_726 &&
V_709 -> V_727 == V_728 &&
V_16 -> V_119 == V_120 )
V_252 &= ~ V_726 ;
if ( V_724 ) {
F_31 ( V_73 , V_729 ,
V_730 ) ;
F_134 ( V_73 , V_731 , V_723 ) ;
} else {
T_6 V_732 = 0 ;
F_31 ( V_73 , V_729 ,
F_264 ( V_709 ) ?
V_733 :
V_734 ) ;
if ( V_709 -> V_705 & V_735 )
V_732 |=
F_265 ( V_709 -> V_711 ) ?
1 << V_736 :
1 << V_737 ;
#define F_272 ( T_13 , T_14 , T_15 ) \
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
F_272 ( V_738 , V_739 , V_740 ) ;
F_272 ( V_741 , V_716 , V_742 ) ;
F_272 ( V_743 , V_744 , V_745 ) ;
F_272 ( V_746 , V_747 , V_748 ) ;
F_272 ( V_749 , V_711 , V_750 ) ;
F_272 ( V_751 , V_752 , V_753 ) ;
F_272 ( V_754 , V_714 , V_754 ) ;
F_272 ( V_755 , V_756 , V_757 ) ;
F_272 ( V_758 , V_708 , V_759 ) ;
F_272 ( V_760 , V_761 , V_760 ) ;
#undef F_272
F_31 ( V_73 , V_762 ,
V_732 ) ;
}
F_31 ( V_73 , V_763 , V_16 -> V_121 ) ;
F_31 ( V_73 , V_764 ,
V_709 -> V_765 == V_766 ?
V_767 :
V_768 ) ;
F_31 ( V_73 , V_769 , 0 ) ;
F_31 ( V_73 , V_770 ,
V_771 ) ;
F_31 ( V_73 , V_772 ,
V_709 -> V_765 == V_766 ?
0 : V_709 -> V_765 ) ;
F_31 ( V_73 , V_773 ,
( V_252 & V_726 ) ?
V_774 :
V_775 ) ;
if ( V_252 & V_726 )
F_31 ( V_73 , V_776 ,
V_709 -> V_727 !=
V_728 ?
V_709 -> V_727 : V_16 -> V_119 ) ;
}
static int F_273 ( struct V_1 * V_2 ,
const struct V_702 * V_709 ,
T_8 * V_723 , bool V_724 )
{
F_8 ( V_73 , V_725 ) ;
F_8 ( V_13 , V_777 ) ;
int V_18 ;
F_271 ( V_2 , V_709 , V_73 , * V_723 , V_724 ) ;
V_18 = F_9 ( V_2 , V_778 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_723 = F_274 ( V_13 , V_779 ) ;
if ( V_18 == - V_155 )
V_18 = - V_216 ;
return V_18 ;
}
static T_6 F_275 ( const struct V_702 * V_709 )
{
unsigned int V_705 = V_709 -> V_705 ;
T_6 V_780 = 0 ;
if ( V_705 & V_735 ) {
V_705 &= ~ V_735 ;
V_780 |=
F_265 ( V_709 -> V_711 ) ?
( 1 << V_736 ) :
( 1 << V_737 ) ;
}
#define F_276 ( T_13 , T_15 ) { \
unsigned int old_match_flags = match_flags; \
match_flags &= ~EFX_FILTER_MATCH_ ## gen_flag; \
if (match_flags != old_match_flags) \
mcdi_flags |= \
(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
}
F_276 ( V_738 , V_740 ) ;
F_276 ( V_741 , V_742 ) ;
F_276 ( V_743 , V_745 ) ;
F_276 ( V_746 , V_748 ) ;
F_276 ( V_749 , V_750 ) ;
F_276 ( V_751 , V_753 ) ;
F_276 ( V_754 , V_754 ) ;
F_276 ( V_755 , V_757 ) ;
F_276 ( V_758 , V_759 ) ;
F_276 ( V_760 , V_760 ) ;
#undef F_276
F_137 ( V_705 ) ;
return V_780 ;
}
static int F_277 ( struct V_718 * V_719 ,
const struct V_702 * V_709 )
{
T_6 V_780 = F_275 ( V_709 ) ;
unsigned int V_781 ;
for ( V_781 = 0 ;
V_781 < V_719 -> V_782 ;
V_781 ++ )
if ( V_719 -> V_783 [ V_781 ] == V_780 )
return V_781 ;
return - V_784 ;
}
static T_16 F_278 ( struct V_1 * V_2 ,
struct V_702 * V_709 ,
bool V_785 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
F_118 ( V_786 , V_787 ) ;
struct V_702 * V_788 ;
unsigned int V_781 , V_789 ;
unsigned int V_790 ;
bool V_724 = false ;
int V_791 = - 1 ;
F_279 ( V_792 ) ;
bool V_793 ;
T_16 V_18 ;
if ( ( V_709 -> V_252 & ( V_706 | V_707 ) ) !=
V_706 )
return - V_263 ;
V_18 = F_277 ( V_719 , V_709 ) ;
if ( V_18 < 0 )
return V_18 ;
V_781 = V_18 ;
V_789 = F_262 ( V_709 ) ;
V_793 = F_280 ( V_709 ) ;
if ( V_793 )
F_281 ( V_786 , V_787 ) ;
for (; ; ) {
unsigned int V_794 = 1 ;
unsigned int V_111 ;
F_133 ( & V_2 -> V_795 ) ;
for (; ; ) {
V_111 = ( V_789 + V_794 ) & ( V_796 - 1 ) ;
V_788 = F_268 ( V_719 , V_111 ) ;
if ( ! V_788 ) {
if ( V_791 < 0 )
V_791 = V_111 ;
} else if ( F_260 ( V_709 , V_788 ) ) {
if ( V_719 -> V_721 [ V_111 ] . V_709 &
V_797 )
break;
if ( V_709 -> V_798 < V_788 -> V_798 &&
V_709 -> V_798 != V_799 ) {
V_18 = - V_65 ;
goto V_800;
}
if ( ! V_793 ) {
if ( V_709 -> V_798 ==
V_788 -> V_798 &&
! V_785 ) {
V_18 = - V_801 ;
goto V_800;
}
V_791 = V_111 ;
goto V_802;
} else if ( V_709 -> V_798 >
V_788 -> V_798 ||
( V_709 -> V_798 ==
V_788 -> V_798 &&
V_785 ) ) {
if ( V_791 < 0 )
V_791 = V_111 ;
else
F_282 ( V_794 , V_786 ) ;
}
}
if ( V_794 == V_787 ) {
if ( V_791 < 0 ) {
V_18 = - V_216 ;
goto V_800;
}
goto V_802;
}
++ V_794 ;
}
F_283 ( & V_719 -> V_803 , & V_792 , V_804 ) ;
F_131 ( & V_2 -> V_795 ) ;
F_284 () ;
}
V_802:
V_788 = F_268 ( V_719 , V_791 ) ;
if ( V_788 ) {
if ( V_709 -> V_798 == V_799 &&
V_788 -> V_798 >= V_799 ) {
if ( V_788 -> V_798 > V_799 )
V_788 -> V_252 |= V_805 ;
V_719 -> V_721 [ V_791 ] . V_709 &=
~ V_806 ;
V_18 = V_791 ;
goto V_800;
}
V_724 = true ;
V_790 = F_269 ( V_719 , V_791 ) ;
} else {
V_788 = F_285 ( sizeof( * V_709 ) , V_344 ) ;
if ( ! V_788 ) {
V_18 = - V_99 ;
goto V_800;
}
* V_788 = * V_709 ;
V_790 = 0 ;
}
F_270 ( V_719 , V_791 , V_788 ,
V_790 | V_797 ) ;
if ( V_793 ) {
unsigned int V_794 , V_111 ;
for ( V_794 = 0 ; V_794 < V_787 ; V_794 ++ ) {
V_111 = ( V_789 + V_794 ) & ( V_796 - 1 ) ;
if ( F_286 ( V_794 , V_786 ) )
V_719 -> V_721 [ V_111 ] . V_709 |=
V_797 ;
}
}
F_131 ( & V_2 -> V_795 ) ;
V_18 = F_273 ( V_2 , V_709 , & V_719 -> V_721 [ V_791 ] . V_723 ,
V_724 ) ;
F_133 ( & V_2 -> V_795 ) ;
if ( V_18 == 0 ) {
if ( V_724 ) {
if ( V_788 -> V_798 == V_799 )
V_788 -> V_252 |=
V_805 ;
V_788 -> V_798 = V_709 -> V_798 ;
V_788 -> V_252 &= V_805 ;
V_788 -> V_252 |= V_709 -> V_252 ;
V_788 -> V_727 = V_709 -> V_727 ;
V_788 -> V_765 = V_709 -> V_765 ;
}
} else if ( ! V_724 ) {
F_50 ( V_788 ) ;
V_788 = NULL ;
}
F_270 ( V_719 , V_791 , V_788 , V_790 ) ;
if ( V_793 ) {
F_8 ( V_73 , V_725 ) ;
unsigned int V_794 , V_111 ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
for ( V_794 = 0 ; V_794 < V_787 ; V_794 ++ ) {
if ( ! F_286 ( V_794 , V_786 ) )
continue;
V_111 = ( V_789 + V_794 ) & ( V_796 - 1 ) ;
V_788 = F_268 ( V_719 , V_111 ) ;
V_790 = F_269 ( V_719 , V_111 ) ;
if ( V_18 == 0 ) {
F_131 ( & V_2 -> V_795 ) ;
F_31 ( V_73 , V_729 ,
V_807 ) ;
F_134 ( V_73 , V_731 ,
V_719 -> V_721 [ V_111 ] . V_723 ) ;
V_18 = F_9 ( V_2 , V_778 ,
V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
F_133 ( & V_2 -> V_795 ) ;
}
if ( V_18 == 0 ) {
F_50 ( V_788 ) ;
V_788 = NULL ;
V_790 = 0 ;
} else {
V_790 &= ~ V_797 ;
}
F_270 ( V_719 , V_111 , V_788 ,
V_790 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_781 * V_796 + V_791 ;
F_287 ( & V_719 -> V_803 ) ;
V_800:
F_131 ( & V_2 -> V_795 ) ;
F_288 ( & V_719 -> V_803 , & V_792 ) ;
return V_18 ;
}
static void F_289 ( struct V_1 * V_2 )
{
}
static int F_290 ( struct V_1 * V_2 ,
unsigned int V_808 ,
T_6 V_809 , bool V_810 )
{
unsigned int V_720 = V_809 % V_796 ;
struct V_718 * V_719 = V_2 -> V_104 ;
F_8 ( V_73 ,
V_811 +
V_812 ) ;
struct V_702 * V_709 ;
F_279 ( V_792 ) ;
int V_18 ;
for (; ; ) {
F_133 ( & V_2 -> V_795 ) ;
if ( ! ( V_719 -> V_721 [ V_720 ] . V_709 &
V_797 ) )
break;
F_283 ( & V_719 -> V_803 , & V_792 , V_804 ) ;
F_131 ( & V_2 -> V_795 ) ;
F_284 () ;
}
V_709 = F_268 ( V_719 , V_720 ) ;
if ( ! V_709 ||
( ! V_810 &&
F_277 ( V_719 , V_709 ) !=
V_809 / V_796 ) ) {
V_18 = - V_108 ;
goto V_800;
}
if ( V_709 -> V_252 & V_805 &&
V_808 == ( 1U << V_799 ) ) {
V_709 -> V_252 &= ~ V_805 ;
V_719 -> V_721 [ V_720 ] . V_709 &= ~ V_806 ;
V_18 = 0 ;
goto V_800;
}
if ( ! ( V_808 & ( 1U << V_709 -> V_798 ) ) ) {
V_18 = - V_108 ;
goto V_800;
}
V_719 -> V_721 [ V_720 ] . V_709 |= V_797 ;
F_131 ( & V_2 -> V_795 ) ;
if ( V_709 -> V_252 & V_805 ) {
struct V_702 V_813 = * V_709 ;
V_813 . V_798 = V_799 ;
V_813 . V_252 = ( V_706 |
( F_291 ( V_2 ) ?
V_726 : 0 ) ) ;
V_813 . V_765 = 0 ;
V_813 . V_727 = V_728 ;
V_18 = F_273 ( V_2 , & V_813 ,
& V_719 -> V_721 [ V_720 ] . V_723 ,
true ) ;
F_133 ( & V_2 -> V_795 ) ;
if ( V_18 == 0 )
* V_709 = V_813 ;
} else {
F_31 ( V_73 , V_729 ,
F_264 ( V_709 ) ?
V_814 :
V_807 ) ;
F_134 ( V_73 , V_731 ,
V_719 -> V_721 [ V_720 ] . V_723 ) ;
V_18 = F_9 ( V_2 , V_778 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
F_133 ( & V_2 -> V_795 ) ;
if ( V_18 == 0 ) {
F_50 ( V_709 ) ;
F_270 ( V_719 , V_720 , NULL , 0 ) ;
}
}
V_719 -> V_721 [ V_720 ] . V_709 &= ~ V_797 ;
F_287 ( & V_719 -> V_803 ) ;
V_800:
F_131 ( & V_2 -> V_795 ) ;
F_288 ( & V_719 -> V_803 , & V_792 ) ;
return V_18 ;
}
static int F_292 ( struct V_1 * V_2 ,
enum V_815 V_798 ,
T_6 V_809 )
{
return F_290 ( V_2 , 1U << V_798 ,
V_809 , false ) ;
}
static T_6 F_293 ( struct V_1 * V_2 , T_6 V_809 )
{
return V_809 % V_796 ;
}
static void F_294 ( struct V_1 * V_2 ,
enum V_815 V_798 ,
T_6 V_809 )
{
if ( V_809 == V_816 )
return;
F_290 ( V_2 , 1U << V_798 , V_809 , true ) ;
}
static int F_295 ( struct V_1 * V_2 ,
enum V_815 V_798 ,
T_6 V_809 , struct V_702 * V_709 )
{
unsigned int V_720 = V_809 % V_796 ;
struct V_718 * V_719 = V_2 -> V_104 ;
const struct V_702 * V_788 ;
int V_18 ;
F_133 ( & V_2 -> V_795 ) ;
V_788 = F_268 ( V_719 , V_720 ) ;
if ( V_788 && V_788 -> V_798 == V_798 &&
F_277 ( V_719 , V_788 ) ==
V_809 / V_796 ) {
* V_709 = * V_788 ;
V_18 = 0 ;
} else {
V_18 = - V_108 ;
}
F_131 ( & V_2 -> V_795 ) ;
return V_18 ;
}
static int F_296 ( struct V_1 * V_2 ,
enum V_815 V_798 )
{
unsigned int V_808 ;
unsigned int V_111 ;
int V_18 ;
V_808 = ( ( ( 1U << ( V_798 + 1 ) ) - 1 ) &
~ ( 1U << V_799 ) ) ;
for ( V_111 = 0 ; V_111 < V_796 ; V_111 ++ ) {
V_18 = F_290 ( V_2 , V_808 ,
V_111 , true ) ;
if ( V_18 && V_18 != - V_108 )
return V_18 ;
}
return 0 ;
}
static T_6 F_297 ( struct V_1 * V_2 ,
enum V_815 V_798 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
unsigned int V_720 ;
T_16 V_817 = 0 ;
F_133 ( & V_2 -> V_795 ) ;
for ( V_720 = 0 ; V_720 < V_796 ; V_720 ++ ) {
if ( V_719 -> V_721 [ V_720 ] . V_709 &&
F_268 ( V_719 , V_720 ) -> V_798 ==
V_798 )
++ V_817 ;
}
F_131 ( & V_2 -> V_795 ) ;
return V_817 ;
}
static T_6 F_298 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
return V_719 -> V_782 * V_796 ;
}
static T_16 F_299 ( struct V_1 * V_2 ,
enum V_815 V_798 ,
T_6 * V_87 , T_6 V_818 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_702 * V_709 ;
unsigned int V_720 ;
T_16 V_817 = 0 ;
F_133 ( & V_2 -> V_795 ) ;
for ( V_720 = 0 ; V_720 < V_796 ; V_720 ++ ) {
V_709 = F_268 ( V_719 , V_720 ) ;
if ( V_709 && V_709 -> V_798 == V_798 ) {
if ( V_817 == V_818 ) {
V_817 = - V_819 ;
break;
}
V_87 [ V_817 ++ ] = ( F_277 ( V_719 , V_709 ) *
V_796 +
V_720 ) ;
}
}
F_131 ( & V_2 -> V_795 ) ;
return V_817 ;
}
static T_16 F_300 ( struct V_1 * V_2 ,
struct V_702 * V_709 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
F_8 ( V_73 , V_725 ) ;
struct V_702 * V_788 ;
unsigned int V_789 , V_111 , V_794 = 1 ;
bool V_724 = false ;
int V_791 = - 1 ;
T_8 V_587 ;
T_16 V_18 ;
F_301 ( V_709 -> V_252 !=
( V_706 | V_820 ) ) ;
F_301 ( V_709 -> V_798 != V_821 ) ;
F_301 ( F_280 ( V_709 ) ) ;
V_789 = F_262 ( V_709 ) ;
F_133 ( & V_2 -> V_795 ) ;
for (; ; ) {
V_111 = ( V_789 + V_794 ) & ( V_796 - 1 ) ;
V_788 = F_268 ( V_719 , V_111 ) ;
if ( ! V_788 ) {
if ( V_791 < 0 )
V_791 = V_111 ;
} else if ( F_260 ( V_709 , V_788 ) ) {
if ( V_719 -> V_721 [ V_111 ] . V_709 & V_797 ) {
V_18 = - V_216 ;
goto V_822;
}
if ( V_709 -> V_798 < V_788 -> V_798 ) {
V_18 = - V_65 ;
goto V_822;
}
V_791 = V_111 ;
break;
}
if ( V_794 == V_787 ) {
if ( V_791 < 0 ) {
V_18 = - V_216 ;
goto V_822;
}
break;
}
++ V_794 ;
}
V_788 = F_268 ( V_719 , V_791 ) ;
if ( V_788 ) {
V_724 = true ;
} else {
V_788 = F_285 ( sizeof( * V_709 ) , V_344 ) ;
if ( ! V_788 ) {
V_18 = - V_99 ;
goto V_822;
}
* V_788 = * V_709 ;
}
F_270 ( V_719 , V_791 , V_788 ,
V_797 ) ;
F_131 ( & V_2 -> V_795 ) ;
V_587 = V_724 << 31 | V_791 << 16 | V_709 -> V_765 ;
F_271 ( V_2 , V_709 , V_73 ,
V_719 -> V_721 [ V_791 ] . V_723 , V_724 ) ;
F_140 ( V_2 , V_778 , V_73 , sizeof( V_73 ) ,
V_777 ,
V_823 , V_587 ) ;
return V_791 ;
V_822:
F_131 ( & V_2 -> V_795 ) ;
return V_18 ;
}
static void
V_823 ( struct V_1 * V_2 , unsigned long V_587 ,
int V_18 , T_1 * V_13 ,
T_2 V_588 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
unsigned int V_791 , V_765 ;
struct V_702 * V_709 ;
bool V_724 ;
V_724 = V_587 >> 31 ;
V_791 = ( V_587 >> 16 ) & ( V_796 - 1 ) ;
V_765 = V_587 & 0xffff ;
F_133 ( & V_2 -> V_795 ) ;
V_709 = F_268 ( V_719 , V_791 ) ;
if ( V_18 == 0 ) {
V_719 -> V_721 [ V_791 ] . V_723 =
F_274 ( V_13 , V_779 ) ;
if ( V_724 )
V_709 -> V_765 = V_765 ;
} else if ( ! V_724 ) {
F_50 ( V_709 ) ;
V_709 = NULL ;
}
F_270 ( V_719 , V_791 , V_709 , 0 ) ;
F_131 ( & V_2 -> V_795 ) ;
F_287 ( & V_719 -> V_803 ) ;
}
static bool F_302 ( struct V_1 * V_2 , T_6 V_824 ,
unsigned int V_720 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_702 * V_709 =
F_268 ( V_719 , V_720 ) ;
F_8 ( V_73 ,
V_811 +
V_812 ) ;
if ( ! V_709 ||
( V_719 -> V_721 [ V_720 ] . V_709 & V_797 ) ||
V_709 -> V_798 != V_821 ||
! F_303 ( V_2 -> V_29 , V_709 -> V_765 ,
V_824 , V_720 ) )
return false ;
F_31 ( V_73 , V_729 ,
V_814 ) ;
F_134 ( V_73 , V_731 ,
V_719 -> V_721 [ V_720 ] . V_723 ) ;
if ( F_140 ( V_2 , V_778 , V_73 , sizeof( V_73 ) , 0 ,
V_825 , V_720 ) )
return false ;
V_719 -> V_721 [ V_720 ] . V_709 |= V_797 ;
return true ;
}
static void
V_825 ( struct V_1 * V_2 ,
unsigned long V_720 ,
int V_18 , T_1 * V_13 ,
T_2 V_588 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_702 * V_709 =
F_268 ( V_719 , V_720 ) ;
F_133 ( & V_2 -> V_795 ) ;
if ( V_18 == 0 ) {
F_50 ( V_709 ) ;
F_270 ( V_719 , V_720 , NULL , 0 ) ;
}
V_719 -> V_721 [ V_720 ] . V_709 &= ~ V_797 ;
F_287 ( & V_719 -> V_803 ) ;
F_131 ( & V_2 -> V_795 ) ;
}
static int F_304 ( T_6 V_780 )
{
int V_705 = 0 ;
#define F_305 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_305 ( V_826 , V_827 ) ;
F_305 ( V_826 , V_828 ) ;
F_305 ( V_738 , V_740 ) ;
F_305 ( V_741 , V_742 ) ;
F_305 ( V_743 , V_745 ) ;
F_305 ( V_746 , V_748 ) ;
F_305 ( V_749 , V_750 ) ;
F_305 ( V_751 , V_753 ) ;
F_305 ( V_754 , V_754 ) ;
F_305 ( V_755 , V_757 ) ;
F_305 ( V_758 , V_759 ) ;
F_305 ( V_760 , V_760 ) ;
#undef F_305
if ( V_780 )
return - V_263 ;
return V_705 ;
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_829 * V_94 , * V_109 ;
if ( ! F_307 ( & V_2 -> V_106 ) )
return;
if ( ! V_719 )
return;
F_55 (vlan, next_vlan, &table->vlan_list, list)
F_308 ( V_2 , V_94 ) ;
}
static bool F_309 ( struct V_718 * V_719 ,
enum V_830 V_705 )
{
unsigned int V_781 ;
int V_831 ;
for ( V_781 = 0 ;
V_781 < V_719 -> V_782 ;
V_781 ++ ) {
V_831 = F_304 (
V_719 -> V_783 [ V_781 ] ) ;
if ( V_831 == V_705 )
return true ;
}
return false ;
}
static int F_310 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_832 ) ;
F_8 ( V_13 , V_833 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_110 * V_29 = V_2 -> V_29 ;
unsigned int V_834 , V_835 ;
struct V_718 * V_719 ;
struct V_92 * V_94 ;
T_2 V_17 ;
int V_18 ;
if ( ! F_307 ( & V_2 -> V_106 ) )
return - V_263 ;
if ( V_2 -> V_104 )
return 0 ;
V_719 = F_43 ( sizeof( * V_719 ) , V_100 ) ;
if ( ! V_719 )
return - V_99 ;
F_31 ( V_73 , V_836 ,
V_837 ) ;
V_18 = F_9 ( V_2 , V_838 ,
V_73 , sizeof( V_73 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_171;
V_835 = F_311 (
V_17 , V_839 ) ;
V_719 -> V_782 = 0 ;
for ( V_834 = 0 ; V_834 < V_835 ; V_834 ++ ) {
T_6 V_780 =
F_312 (
V_13 ,
V_839 ,
V_834 ) ;
V_18 = F_304 ( V_780 ) ;
if ( V_18 < 0 ) {
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_61 ,
V_546 , V_780 , V_834 ) ;
} else {
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_62 ,
V_546 , V_780 , V_834 ,
V_18 , V_719 -> V_782 ) ;
V_719 -> V_783 [ V_719 -> V_782 ] = V_780 ;
V_719 -> V_782 ++ ;
}
}
if ( ( F_313 ( V_2 ) & V_840 ) &&
! ( F_309 ( V_719 ,
( V_841 | V_710 ) ) &&
F_309 ( V_719 ,
( V_841 | V_735 ) ) ) ) {
F_90 ( V_2 , V_39 , V_29 ,
L_63 ) ;
V_29 -> V_842 &= ~ V_840 ;
V_2 -> V_843 &= ~ V_840 ;
V_29 -> V_844 &= ~ V_840 ;
}
V_719 -> V_721 = F_314 ( V_796 * sizeof( * V_719 -> V_721 ) ) ;
if ( ! V_719 -> V_721 ) {
V_18 = - V_99 ;
goto V_171;
}
V_719 -> V_845 = false ;
V_719 -> V_846 =
! ! ( V_2 -> V_29 -> V_842 & V_840 ) ;
F_70 ( & V_719 -> V_103 ) ;
V_2 -> V_104 = V_719 ;
F_315 ( & V_719 -> V_803 ) ;
F_39 (vlan, &nic_data->vlan_list, list) {
V_18 = F_46 ( V_2 , V_94 -> V_93 ) ;
if ( V_18 )
goto V_847;
}
return 0 ;
V_847:
F_306 ( V_2 ) ;
V_2 -> V_104 = NULL ;
V_171:
F_50 ( V_719 ) ;
return V_18 ;
}
static void F_316 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_702 * V_709 ;
unsigned int V_720 ;
bool V_848 = false ;
int V_18 ;
F_32 ( ! F_317 ( & V_2 -> V_106 ) ) ;
if ( ! V_16 -> V_245 )
return;
if ( ! V_719 )
return;
F_133 ( & V_2 -> V_795 ) ;
for ( V_720 = 0 ; V_720 < V_796 ; V_720 ++ ) {
V_709 = F_268 ( V_719 , V_720 ) ;
if ( ! V_709 )
continue;
V_719 -> V_721 [ V_720 ] . V_709 |= V_797 ;
F_131 ( & V_2 -> V_795 ) ;
V_18 = F_273 ( V_2 , V_709 ,
& V_719 -> V_721 [ V_720 ] . V_723 ,
false ) ;
if ( V_18 )
V_848 = true ;
F_133 ( & V_2 -> V_795 ) ;
if ( V_18 ) {
F_50 ( V_709 ) ;
F_270 ( V_719 , V_720 , NULL , 0 ) ;
} else {
V_719 -> V_721 [ V_720 ] . V_709 &=
~ V_797 ;
}
}
F_131 ( & V_2 -> V_795 ) ;
if ( V_848 )
F_14 ( V_2 , V_463 , V_2 -> V_29 ,
L_64 ) ;
else
V_16 -> V_245 = false ;
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
F_8 ( V_73 , V_725 ) ;
struct V_702 * V_709 ;
unsigned int V_720 ;
int V_18 ;
F_306 ( V_2 ) ;
V_2 -> V_104 = NULL ;
if ( ! F_307 ( & V_2 -> V_106 ) )
return;
if ( ! V_719 )
return;
for ( V_720 = 0 ; V_720 < V_796 ; V_720 ++ ) {
V_709 = F_268 ( V_719 , V_720 ) ;
if ( ! V_709 )
continue;
F_31 ( V_73 , V_729 ,
F_264 ( V_709 ) ?
V_814 :
V_807 ) ;
F_134 ( V_73 , V_731 ,
V_719 -> V_721 [ V_720 ] . V_723 ) ;
V_18 = F_25 ( V_2 , V_778 , V_73 ,
sizeof( V_73 ) , NULL , 0 , NULL ) ;
if ( V_18 )
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_65 ,
V_546 , V_720 ) ;
F_50 ( V_709 ) ;
}
F_319 ( V_719 -> V_721 ) ;
F_50 ( V_719 ) ;
}
static void F_320 ( struct V_1 * V_2 , T_17 * V_433 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
unsigned int V_720 ;
if ( * V_433 != V_816 ) {
V_720 = F_293 ( V_2 , * V_433 ) ;
if ( ! V_719 -> V_721 [ V_720 ] . V_709 )
F_20 ( V_2 , V_28 , V_2 -> V_29 ,
L_66 , * V_433 ,
V_720 ) ;
V_719 -> V_721 [ V_720 ] . V_709 |= V_806 ;
* V_433 = V_816 ;
}
}
static void F_321 ( struct V_1 * V_2 ,
struct V_829 * V_94 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_719 -> V_849 ; V_111 ++ )
F_320 ( V_2 , & V_94 -> V_850 [ V_111 ] ) ;
for ( V_111 = 0 ; V_111 < V_719 -> V_851 ; V_111 ++ )
F_320 ( V_2 , & V_94 -> V_852 [ V_111 ] ) ;
F_320 ( V_2 , & V_94 -> V_853 ) ;
F_320 ( V_2 , & V_94 -> V_854 ) ;
F_320 ( V_2 , & V_94 -> V_855 ) ;
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_829 * V_94 ;
F_133 ( & V_2 -> V_795 ) ;
F_39 (vlan, &table->vlan_list, list)
F_321 ( V_2 , V_94 ) ;
F_131 ( & V_2 -> V_795 ) ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_110 * V_29 = V_2 -> V_29 ;
struct V_856 * V_850 ;
int V_857 ;
unsigned int V_111 ;
V_857 = F_324 ( V_29 ) ;
V_719 -> V_858 = ! ! ( V_29 -> V_252 & V_859 ) ;
V_719 -> V_849 = 1 + V_857 ;
F_28 ( V_719 -> V_860 [ 0 ] . V_330 , V_29 -> V_861 ) ;
V_111 = 1 ;
F_325 (uc, net_dev) {
if ( V_111 >= V_862 ) {
V_719 -> V_858 = true ;
break;
}
F_28 ( V_719 -> V_860 [ V_111 ] . V_330 , V_850 -> V_330 ) ;
V_111 ++ ;
}
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_110 * V_29 = V_2 -> V_29 ;
struct V_856 * V_852 ;
unsigned int V_111 , V_857 ;
V_719 -> V_863 = ! ! ( V_29 -> V_252 & ( V_859 | V_864 ) ) ;
V_857 = F_327 ( V_29 ) ;
V_111 = 0 ;
F_328 (mc, net_dev) {
if ( V_111 >= V_865 ) {
V_719 -> V_863 = true ;
break;
}
F_28 ( V_719 -> V_866 [ V_111 ] . V_330 , V_852 -> V_330 ) ;
V_111 ++ ;
}
V_719 -> V_851 = V_111 ;
}
static int F_329 ( struct V_1 * V_2 ,
struct V_829 * V_94 ,
bool V_305 , bool V_867 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_868 * V_869 ;
enum V_870 V_871 ;
struct V_702 V_709 ;
T_3 V_872 [ V_873 ] ;
unsigned int V_111 , V_874 ;
int V_857 ;
T_5 * V_875 ;
int V_18 ;
if ( V_305 ) {
V_869 = V_719 -> V_866 ;
V_857 = V_719 -> V_851 ;
V_875 = V_94 -> V_852 ;
} else {
V_869 = V_719 -> V_860 ;
V_857 = V_719 -> V_849 ;
V_875 = V_94 -> V_850 ;
}
V_871 = F_291 ( V_2 ) ? V_726 : 0 ;
for ( V_111 = 0 ; V_111 < V_857 ; V_111 ++ ) {
F_330 ( & V_709 , V_799 , V_871 , 0 ) ;
F_331 ( & V_709 , V_94 -> V_93 , V_869 [ V_111 ] . V_330 ) ;
V_18 = F_278 ( V_2 , & V_709 , true ) ;
if ( V_18 < 0 ) {
if ( V_867 ) {
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_67 ,
V_18 ) ;
for ( V_874 = 0 ; V_874 < V_111 ; V_874 ++ ) {
F_294 (
V_2 , V_799 ,
V_875 [ V_874 ] ) ;
V_875 [ V_874 ] = V_816 ;
}
return V_18 ;
} else {
V_18 = V_816 ;
}
}
V_875 [ V_111 ] = F_293 ( V_2 , V_18 ) ;
}
if ( V_305 && V_867 ) {
F_330 ( & V_709 , V_799 , V_871 , 0 ) ;
F_332 ( V_872 ) ;
F_331 ( & V_709 , V_94 -> V_93 , V_872 ) ;
V_18 = F_278 ( V_2 , & V_709 , true ) ;
if ( V_18 < 0 ) {
F_42 ( V_2 , V_28 , V_2 -> V_29 ,
L_68 , V_18 ) ;
for ( V_874 = 0 ; V_874 < V_111 ; V_874 ++ ) {
F_294 (
V_2 , V_799 ,
V_875 [ V_874 ] ) ;
V_875 [ V_874 ] = V_816 ;
}
return V_18 ;
} else {
F_301 ( V_94 -> V_854 !=
V_816 ) ;
V_94 -> V_854 = F_293 ( V_2 , V_18 ) ;
}
}
return 0 ;
}
static int F_333 ( struct V_1 * V_2 ,
struct V_829 * V_94 ,
bool V_305 , bool V_867 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
enum V_870 V_871 ;
struct V_702 V_709 ;
T_3 V_872 [ V_873 ] ;
int V_18 ;
V_871 = F_291 ( V_2 ) ? V_726 : 0 ;
F_330 ( & V_709 , V_799 , V_871 , 0 ) ;
if ( V_305 )
F_334 ( & V_709 ) ;
else
F_335 ( & V_709 ) ;
if ( V_94 -> V_93 != V_141 )
F_331 ( & V_709 , V_94 -> V_93 , NULL ) ;
V_18 = F_278 ( V_2 , & V_709 , true ) ;
if ( V_18 < 0 ) {
F_336 ( V_2 , V_28 , V_18 == - V_65 ? V_876 : V_877 ,
V_2 -> V_29 ,
L_69 ,
V_305 ? L_70 : L_71 , V_18 ) ;
} else if ( V_305 ) {
F_301 ( V_94 -> V_855 != V_816 ) ;
V_94 -> V_855 = F_293 ( V_2 , V_18 ) ;
if ( ! V_16 -> V_621 ) {
F_330 ( & V_709 , V_799 ,
V_871 , 0 ) ;
F_332 ( V_872 ) ;
F_331 ( & V_709 , V_94 -> V_93 , V_872 ) ;
V_18 = F_278 ( V_2 , & V_709 , true ) ;
if ( V_18 < 0 ) {
F_42 ( V_2 , V_28 , V_2 -> V_29 ,
L_68 ,
V_18 ) ;
if ( V_867 ) {
F_294 (
V_2 , V_799 ,
V_94 -> V_855 ) ;
V_94 -> V_855 = V_816 ;
return V_18 ;
}
} else {
F_301 ( V_94 -> V_854 !=
V_816 ) ;
V_94 -> V_854 = F_293 ( V_2 , V_18 ) ;
}
}
V_18 = 0 ;
} else {
F_301 ( V_94 -> V_853 != V_816 ) ;
V_94 -> V_853 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
int V_878 = 0 ;
int V_879 = 0 ;
int V_18 ;
int V_111 ;
for ( V_111 = 0 ; V_111 < V_796 ; V_111 ++ ) {
if ( F_159 ( V_719 -> V_721 [ V_111 ] . V_709 ) &
V_806 ) {
V_18 = F_290 ( V_2 ,
1U << V_799 , V_111 , true ) ;
if ( V_18 == - V_108 )
V_879 ++ ;
else if ( V_18 )
V_878 ++ ;
}
}
if ( V_878 )
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_72 ,
V_546 , V_878 ) ;
if ( V_879 )
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_73 ,
V_546 , V_879 ) ;
}
static int F_338 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_880 [ V_873 ] ;
int V_18 , V_881 ;
if ( F_339 ( V_16 -> V_882 ) )
return 0 ;
F_340 ( V_2 ) ;
F_341 ( V_2 -> V_29 ) ;
F_45 ( & V_2 -> V_106 ) ;
F_318 ( V_2 ) ;
F_47 ( & V_2 -> V_106 ) ;
V_18 = F_96 ( V_2 , V_16 -> V_121 ) ;
if ( V_18 )
goto V_883;
F_28 ( V_880 , V_16 -> V_882 ) ;
V_18 = F_98 ( V_2 , V_16 -> V_121 ,
V_16 -> V_882 ) ;
if ( V_18 )
goto V_884;
V_18 = F_97 ( V_2 , V_16 -> V_121 ,
V_2 -> V_29 -> V_861 ) ;
if ( ! V_18 ) {
F_28 ( V_16 -> V_882 , V_2 -> V_29 -> V_861 ) ;
} else {
V_881 = F_97 ( V_2 , V_16 -> V_121 , V_880 ) ;
if ( V_881 ) {
F_342 ( V_16 -> V_882 ) ;
goto V_885;
}
}
V_884:
V_881 = F_95 ( V_2 , V_16 -> V_121 ) ;
if ( V_881 )
goto V_885;
V_883:
F_45 ( & V_2 -> V_106 ) ;
V_881 = F_310 ( V_2 ) ;
F_47 ( & V_2 -> V_106 ) ;
if ( V_881 )
goto V_885;
V_881 = F_343 ( V_2 -> V_29 ) ;
if ( V_881 )
goto V_885;
F_344 ( V_2 -> V_29 ) ;
return V_18 ;
V_885:
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_74 ) ;
F_230 ( V_2 , V_251 ) ;
return V_18 ? V_18 : V_881 ;
}
static void F_345 ( struct V_1 * V_2 ,
struct V_829 * V_94 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ( V_94 -> V_93 == V_141 ) == V_719 -> V_846 )
return;
if ( V_719 -> V_858 ) {
F_333 ( V_2 , V_94 , false , false ) ;
F_329 ( V_2 , V_94 , false , false ) ;
} else {
if ( F_329 ( V_2 , V_94 , false , false ) )
F_333 ( V_2 , V_94 , false , false ) ;
}
if ( V_16 -> V_621 &&
V_719 -> V_845 != V_719 -> V_863 )
F_337 ( V_2 ) ;
if ( V_719 -> V_863 ) {
if ( V_16 -> V_621 ) {
if ( F_333 ( V_2 , V_94 , true , true ) ) {
F_337 ( V_2 ) ;
F_329 ( V_2 , V_94 ,
true , false ) ;
}
} else {
F_333 ( V_2 , V_94 , true , false ) ;
F_329 ( V_2 , V_94 , true , false ) ;
}
} else {
if ( F_329 ( V_2 , V_94 , true , true ) ) {
if ( V_16 -> V_621 )
F_337 ( V_2 ) ;
if ( F_333 ( V_2 , V_94 , true , true ) )
F_329 ( V_2 , V_94 ,
true , false ) ;
}
}
}
static void F_346 ( struct V_1 * V_2 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_110 * V_29 = V_2 -> V_29 ;
struct V_829 * V_94 ;
bool V_846 ;
if ( ! F_347 ( V_2 ) )
return;
if ( ! V_719 )
return;
F_322 ( V_2 ) ;
F_348 ( V_29 ) ;
F_323 ( V_2 ) ;
F_326 ( V_2 ) ;
F_349 ( V_29 ) ;
V_846 = ! ! ( V_29 -> V_842 & V_840 ) ;
if ( V_719 -> V_846 != V_846 ) {
V_719 -> V_846 = V_846 ;
F_337 ( V_2 ) ;
}
F_39 (vlan, &table->vlan_list, list)
F_345 ( V_2 , V_94 ) ;
F_337 ( V_2 ) ;
V_719 -> V_845 = V_719 -> V_863 ;
}
static struct V_829 * F_350 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_829 * V_94 ;
F_32 ( ! F_317 ( & V_2 -> V_106 ) ) ;
F_39 (vlan, &table->vlan_list, list) {
if ( V_94 -> V_93 == V_93 )
return V_94 ;
}
return NULL ;
}
static int F_46 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_718 * V_719 = V_2 -> V_104 ;
struct V_829 * V_94 ;
unsigned int V_111 ;
if ( ! F_307 ( & V_2 -> V_106 ) )
return - V_263 ;
V_94 = F_350 ( V_2 , V_93 ) ;
if ( F_32 ( V_94 ) ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_9 , V_93 ) ;
return - V_97 ;
}
V_94 = F_43 ( sizeof( * V_94 ) , V_100 ) ;
if ( ! V_94 )
return - V_99 ;
V_94 -> V_93 = V_93 ;
for ( V_111 = 0 ; V_111 < F_203 ( V_94 -> V_850 ) ; V_111 ++ )
V_94 -> V_850 [ V_111 ] = V_816 ;
for ( V_111 = 0 ; V_111 < F_203 ( V_94 -> V_852 ) ; V_111 ++ )
V_94 -> V_852 [ V_111 ] = V_816 ;
V_94 -> V_853 = V_816 ;
V_94 -> V_854 = V_816 ;
V_94 -> V_855 = V_816 ;
F_44 ( & V_94 -> V_102 , & V_719 -> V_103 ) ;
if ( F_347 ( V_2 ) )
F_345 ( V_2 , V_94 ) ;
return 0 ;
}
static void F_308 ( struct V_1 * V_2 ,
struct V_829 * V_94 )
{
unsigned int V_111 ;
if ( ! F_307 ( & V_2 -> V_106 ) )
return;
F_49 ( & V_94 -> V_102 ) ;
for ( V_111 = 0 ; V_111 < F_203 ( V_94 -> V_850 ) ; V_111 ++ )
F_294 ( V_2 , V_799 ,
V_94 -> V_850 [ V_111 ] ) ;
for ( V_111 = 0 ; V_111 < F_203 ( V_94 -> V_852 ) ; V_111 ++ )
F_294 ( V_2 , V_799 ,
V_94 -> V_852 [ V_111 ] ) ;
F_294 ( V_2 , V_799 , V_94 -> V_853 ) ;
F_294 ( V_2 , V_799 , V_94 -> V_854 ) ;
F_294 ( V_2 , V_799 , V_94 -> V_855 ) ;
F_50 ( V_94 ) ;
}
static void F_52 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_829 * V_94 ;
if ( ! F_307 ( & V_2 -> V_106 ) )
return;
V_94 = F_350 ( V_2 , V_93 ) ;
if ( ! V_94 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_75 , V_93 ) ;
return;
}
F_308 ( V_2 , V_94 ) ;
}
static int F_351 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_886 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_887 = V_2 -> V_888 ;
int V_18 ;
F_340 ( V_2 ) ;
F_341 ( V_2 -> V_29 ) ;
F_41 ( & V_2 -> V_105 ) ;
F_45 ( & V_2 -> V_106 ) ;
F_318 ( V_2 ) ;
F_28 ( F_29 ( V_73 , V_889 ) ,
V_2 -> V_29 -> V_861 ) ;
F_31 ( V_73 , V_890 ,
V_16 -> V_121 ) ;
V_18 = F_25 ( V_2 , V_891 , V_73 ,
sizeof( V_73 ) , NULL , 0 , NULL ) ;
F_310 ( V_2 ) ;
F_47 ( & V_2 -> V_106 ) ;
F_48 ( & V_2 -> V_105 ) ;
if ( V_887 )
F_343 ( V_2 -> V_29 ) ;
F_344 ( V_2 -> V_29 ) ;
#ifdef F_69
if ( V_2 -> V_10 -> V_187 && V_2 -> V_10 -> V_136 ) {
struct V_10 * V_138 = V_2 -> V_10 -> V_136 ;
if ( V_18 == - V_65 ) {
struct V_1 * V_139 ;
V_139 = F_34 ( V_138 ) ;
V_18 = F_352 ( V_139 ,
V_16 -> V_22 ,
V_2 -> V_29 -> V_861 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_139 = F_34 ( V_138 ) ;
struct V_15 * V_16 = V_139 -> V_16 ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_139 -> V_247 ; ++ V_111 ) {
struct V_185 * V_186 = V_16 -> V_186 + V_111 ;
if ( V_186 -> V_2 == V_2 ) {
F_28 ( V_186 -> V_207 ,
V_2 -> V_29 -> V_861 ) ;
return 0 ;
}
}
}
} else
#endif
if ( V_18 == - V_65 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_76
L_77 ) ;
} else if ( V_18 == - V_49 && ! F_6 ( V_2 ) ) {
V_18 = F_338 ( V_2 ) ;
} else {
F_26 ( V_2 , V_891 ,
sizeof( V_73 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_353 ( struct V_1 * V_2 )
{
F_346 ( V_2 ) ;
return F_354 ( V_2 ) ;
}
static int F_355 ( struct V_1 * V_2 )
{
F_346 ( V_2 ) ;
return 0 ;
}
static int F_356 ( struct V_1 * V_2 , T_6 V_892 )
{
F_8 ( V_73 , V_893 ) ;
F_31 ( V_73 , V_894 , V_892 ) ;
return F_9 ( V_2 , V_895 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
}
static int F_357 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_896 ) ;
T_2 V_17 ;
T_6 V_897 ;
V_18 = F_9 ( V_2 , V_898 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_896 )
return - V_7 ;
V_897 = F_10 ( V_13 , V_899 ) ;
switch ( V_897 ) {
case V_900 :
F_20 ( V_2 , V_463 , V_2 -> V_29 , L_78 ) ;
return 0 ;
case V_901 :
F_14 ( V_2 , V_463 , V_2 -> V_29 , L_79 ) ;
return - V_7 ;
case V_902 :
F_14 ( V_2 , V_463 , V_2 -> V_29 , L_80 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_463 , V_2 -> V_29 ,
L_81 , V_897 ) ;
return - V_7 ;
}
}
static int F_358 ( struct V_1 * V_2 , T_6 V_892 )
{
int V_18 ;
F_20 ( V_2 , V_28 , V_2 -> V_29 , L_82 , V_892 ) ;
V_18 = F_356 ( V_2 , V_892 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_357 ( V_2 ) ;
}
static int
F_359 ( struct V_1 * V_2 , struct V_903 * V_904 )
{
int V_18 , V_881 ;
F_360 ( V_2 , V_262 ) ;
V_18 = F_9 ( V_2 , V_905 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_353;
V_904 -> V_906 = F_358 ( V_2 , V_907 ) ? - 1 : 1 ;
V_904 -> V_908 = F_358 ( V_2 , V_909 ) ? - 1 : 1 ;
V_18 = F_63 ( V_2 , V_262 ) ;
V_353:
if ( V_18 == - V_65 )
V_18 = 0 ;
V_881 = F_361 ( V_2 , V_262 , V_18 == 0 ) ;
return V_18 ? V_18 : V_881 ;
}
static int F_362 ( struct V_1 * V_2 ,
struct V_910 * V_911 ,
unsigned int type )
{
F_8 ( V_73 , V_912 ) ;
F_8 ( V_13 , V_913 ) ;
const struct V_914 * V_915 ;
T_2 V_818 , V_916 , V_17 ;
bool V_917 ;
int V_18 ;
for ( V_915 = V_918 ; ; V_915 ++ ) {
if ( V_915 ==
V_918 + F_203 ( V_918 ) )
return - V_40 ;
if ( ( type & ~ V_915 -> V_919 ) == V_915 -> type )
break;
}
if ( V_915 -> V_920 != F_363 ( V_2 ) )
return - V_40 ;
V_18 = F_364 ( V_2 , type , & V_818 , & V_916 , & V_917 ) ;
if ( V_18 )
return V_18 ;
if ( V_917 )
return - V_40 ;
V_911 -> V_921 = type ;
F_31 ( V_73 , V_922 , type ) ;
V_18 = F_9 ( V_2 , V_923 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_924 )
return - V_7 ;
if ( F_10 ( V_13 , V_925 ) &
( 1 << V_926 ) )
V_911 -> V_927 = F_10 ( V_13 ,
V_928 ) ;
V_911 -> V_929 . V_930 = L_83 ;
V_911 -> V_929 . V_931 = V_915 -> V_286 ;
V_911 -> V_929 . V_932 . type = V_933 ;
V_911 -> V_929 . V_932 . V_252 = V_934 ;
V_911 -> V_929 . V_932 . V_818 = V_818 ;
V_911 -> V_929 . V_932 . V_935 = V_916 ;
return 0 ;
}
static int F_365 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_936 ) ;
struct V_910 * V_937 ;
T_2 V_17 , V_938 , V_111 , V_939 ;
unsigned int type ;
int V_18 ;
F_366 () ;
F_13 ( V_940 != 0 ) ;
V_18 = F_9 ( V_2 , V_941 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_942 )
return - V_7 ;
V_938 = F_10 ( V_13 , V_943 ) ;
if ( V_938 >
F_311 ( V_17 , V_944 ) )
return - V_7 ;
V_937 = F_367 ( V_938 , sizeof( * V_937 ) , V_100 ) ;
if ( ! V_937 )
return - V_99 ;
V_939 = 0 ;
for ( V_111 = 0 ; V_111 < V_938 ; V_111 ++ ) {
type = F_312 ( V_13 , V_944 ,
V_111 ) ;
V_18 = F_362 ( V_2 , & V_937 [ V_939 ] , type ) ;
if ( V_18 == 0 )
V_939 ++ ;
else if ( V_18 != - V_40 )
goto V_171;
}
V_18 = F_368 ( V_2 , & V_937 [ 0 ] . V_929 , V_939 , sizeof( * V_937 ) ) ;
V_171:
if ( V_18 )
F_50 ( V_937 ) ;
return V_18 ;
}
static void F_369 ( struct V_1 * V_2 , T_6 V_945 )
{
F_60 ( V_2 , F_61 ( V_945 ) , V_385 ) ;
}
static void F_370 ( struct V_1 * V_2 ,
T_6 V_945 ) {}
static int F_371 ( struct V_159 * V_160 ,
bool V_946 )
{
F_8 ( V_73 , V_947 ) ;
int V_18 ;
if ( V_160 -> V_948 == V_949 ||
V_160 -> V_948 == V_950 ||
( V_946 && V_160 -> V_948 == V_951 ) )
return 0 ;
V_160 -> V_948 = V_949 ;
F_31 ( V_73 , V_952 , V_953 ) ;
F_31 ( V_73 , V_954 , 0 ) ;
F_31 ( V_73 , V_955 ,
V_160 -> V_160 ) ;
V_18 = F_9 ( V_160 -> V_2 , V_956 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_160 -> V_948 = V_946 ? V_957 :
V_951 ;
return V_18 ;
}
static int F_372 ( struct V_159 * V_160 ,
bool V_946 )
{
F_8 ( V_73 , V_958 ) ;
int V_18 ;
if ( V_160 -> V_948 == V_951 ||
( V_946 && V_160 -> V_948 == V_957 ) )
return 0 ;
if ( V_160 -> V_948 == V_957 ) {
V_160 -> V_948 = V_951 ;
return 0 ;
}
V_160 -> V_948 = V_946 ? V_957 :
V_951 ;
F_31 ( V_73 , V_952 , V_959 ) ;
F_31 ( V_73 , V_954 , 0 ) ;
F_31 ( V_73 , V_960 ,
V_961 ) ;
F_31 ( V_73 , V_962 ,
V_160 -> V_160 ) ;
V_18 = F_9 ( V_160 -> V_2 , V_956 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_373 ( struct V_1 * V_2 , bool V_963 ,
bool V_946 )
{
int (* F_374)( struct V_159 * V_160 , bool V_946 );
struct V_159 * V_160 ;
F_374 = V_963 ?
F_371 :
F_372 ;
F_85 (channel, efx) {
int V_18 = F_374 ( V_160 , V_946 ) ;
if ( V_963 && V_18 != 0 ) {
F_373 ( V_2 , false , V_946 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_375 ( struct V_1 * V_2 ,
struct V_964 * V_965 )
{
return - V_376 ;
}
static int F_376 ( struct V_1 * V_2 ,
struct V_964 * V_965 )
{
int V_18 ;
switch ( V_965 -> V_966 ) {
case V_967 :
F_373 ( V_2 , false , false ) ;
return F_377 ( V_2 ,
V_965 -> V_968 != V_969 , 0 ) ;
case V_970 :
case V_971 :
case V_972 :
case V_973 :
case V_974 :
case V_975 :
case V_976 :
case V_977 :
case V_978 :
case V_979 :
case V_980 :
case V_981 :
case V_982 :
V_965 -> V_966 = V_970 ;
V_18 = F_377 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_373 ( V_2 , true , false ) ;
if ( V_18 )
F_377 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_44 ;
}
}
static int F_378 ( struct V_1 * V_2 , T_18 V_983 , T_5 V_93 )
{
if ( V_983 != F_266 ( V_984 ) )
return - V_263 ;
return F_40 ( V_2 , V_93 ) ;
}
static int F_379 ( struct V_1 * V_2 , T_18 V_983 , T_5 V_93 )
{
if ( V_983 != F_266 ( V_984 ) )
return - V_263 ;
return F_53 ( V_2 , V_93 ) ;
}
