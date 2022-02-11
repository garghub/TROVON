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
V_2 -> type -> V_242 ( V_2 , false , V_2 -> V_243 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
#ifdef F_69
unsigned int V_111 ;
#endif
V_16 -> V_241 = true ;
V_16 -> V_244 = true ;
V_16 -> V_189 = true ;
F_88 ( V_2 ) ;
V_16 -> V_119 = V_120 ;
V_16 -> V_245 = true ;
V_16 -> V_121 = V_78 ;
#ifdef F_69
if ( V_16 -> V_186 )
for ( V_111 = 0 ; V_111 < V_2 -> V_246 ; V_111 ++ )
V_16 -> V_186 [ V_111 ] . V_121 = 0 ;
#endif
}
static enum V_247 F_109 ( enum V_247 V_248 )
{
if ( V_248 == V_249 )
return V_250 ;
return F_110 ( V_248 ) ;
}
static int F_111 ( T_6 * V_251 )
{
enum {
V_252 = ( ( V_253 | V_254 ) <<
V_255 ) ,
V_256 = ( ( V_257 | V_258 |
V_259 | V_253 |
V_254 | V_260 ) <<
V_255 )
};
if ( ( * V_251 & V_256 ) == V_256 ) {
* V_251 &= ~ V_256 ;
return V_261 ;
}
if ( ( * V_251 & V_252 ) == V_252 ) {
* V_251 &= ~ V_252 ;
return V_123 ;
}
return - V_262 ;
}
static int F_112 ( struct V_1 * V_2 , enum V_247 V_247 )
{
int V_18 = F_63 ( V_2 , V_247 ) ;
if ( V_247 == V_261 && V_18 == - V_65 )
V_18 = 0 ;
if ( ( V_247 == V_123 ||
V_247 == V_263 ) && ! V_18 )
F_108 ( V_2 ) ;
return V_18 ;
}
static T_8 F_113 ( struct V_1 * V_2 )
{
T_8 V_264 = V_265 ;
T_6 V_266 = F_114 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_88 -> V_89 &
1 << V_90 ) )
return 0 ;
if ( V_266 & ( 1 << V_267 ) ) {
V_264 |= V_268 ;
if ( V_16 -> V_32 &
( 1 << V_269 ) )
V_264 |= V_270 ;
} else {
V_264 |= V_270 ;
}
if ( V_16 -> V_30 &
( 1 << V_271 ) )
V_264 |= V_272 ;
return V_264 ;
}
static void F_115 ( struct V_1 * V_2 , unsigned long * V_273 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_8 V_264 [ 2 ] ;
V_264 [ 0 ] = F_113 ( V_2 ) ;
if ( V_16 -> V_30 &
( 1 << V_274 ) ) {
V_264 [ 0 ] |= ~ ( ( 1ULL << V_275 ) - 1 ) ;
V_264 [ 1 ] = ( 1ULL << ( V_276 - 63 ) ) - 1 ;
} else {
V_264 [ 1 ] = 0 ;
}
#if V_277 == 64
F_13 ( F_116 ( V_276 ) != 2 ) ;
V_273 [ 0 ] = V_264 [ 0 ] ;
V_273 [ 1 ] = V_264 [ 1 ] ;
#else
F_13 ( F_116 ( V_276 ) != 3 ) ;
V_273 [ 0 ] = V_264 [ 0 ] & 0xffffffff ;
V_273 [ 1 ] = V_264 [ 0 ] >> 32 ;
V_273 [ 2 ] = V_264 [ 1 ] & 0xffffffff ;
#endif
}
static T_2 F_117 ( struct V_1 * V_2 , T_3 * V_278 )
{
F_118 ( V_273 , V_276 ) ;
F_115 ( V_2 , V_273 ) ;
return F_119 ( V_279 , V_276 ,
V_273 , V_278 ) ;
}
static T_2 F_120 ( struct V_1 * V_2 , T_8 * V_280 ,
struct V_281 * V_282 )
{
F_118 ( V_273 , V_276 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_8 * V_283 = V_16 -> V_283 ;
T_2 V_284 = 0 , V_164 ;
F_115 ( V_2 , V_273 ) ;
if ( V_280 ) {
F_121 (index, mask, EF10_STAT_COUNT) {
if ( V_279 [ V_164 ] . V_285 ) {
* V_280 ++ = V_283 [ V_164 ] ;
++ V_284 ;
}
}
}
if ( ! V_282 )
return V_284 ;
if ( V_16 -> V_30 &
1 << V_274 ) {
V_282 -> V_286 = V_283 [ V_275 ] +
V_283 [ V_287 ] +
V_283 [ V_288 ] ;
V_282 -> V_289 = V_283 [ V_290 ] +
V_283 [ V_291 ] +
V_283 [ V_292 ] ;
V_282 -> V_293 = V_283 [ V_294 ] +
V_283 [ V_295 ] +
V_283 [ V_296 ] ;
V_282 -> V_297 = V_283 [ V_298 ] +
V_283 [ V_299 ] +
V_283 [ V_300 ] ;
V_282 -> V_301 = V_283 [ V_302 ] +
V_283 [ V_303 ] ;
V_282 -> V_304 = V_283 [ V_287 ] ;
V_282 -> V_305 = V_283 [ V_306 ] ;
V_282 -> V_307 = V_283 [ V_308 ] ;
V_282 -> V_309 = V_282 -> V_305 ;
V_282 -> V_310 = V_283 [ V_311 ] ;
} else {
V_282 -> V_286 = V_283 [ V_312 ] ;
V_282 -> V_289 = V_283 [ V_313 ] ;
V_282 -> V_293 = V_283 [ V_314 ] ;
V_282 -> V_297 = V_283 [ V_315 ] ;
V_282 -> V_301 = V_283 [ V_316 ] +
V_283 [ V_302 ] +
V_283 [ V_303 ] ;
V_282 -> V_304 = V_283 [ V_317 ] ;
V_282 -> V_318 =
V_283 [ V_319 ] +
V_283 [ V_320 ] ;
V_282 -> V_305 = V_283 [ V_321 ] ;
V_282 -> V_322 =
V_283 [ V_323 ] ;
V_282 -> V_307 = V_283 [ V_324 ] ;
V_282 -> V_309 = ( V_282 -> V_318 +
V_282 -> V_305 +
V_282 -> V_322 ) ;
}
return V_284 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_118 ( V_273 , V_276 ) ;
T_9 V_325 , V_326 ;
T_8 * V_283 = V_16 -> V_283 ;
T_9 * V_327 ;
F_115 ( V_2 , V_273 ) ;
V_327 = V_2 -> V_328 . V_329 ;
V_326 = V_327 [ V_330 ] ;
if ( V_326 == V_331 )
return 0 ;
F_123 () ;
F_124 ( V_279 , V_276 , V_273 ,
V_283 , V_2 -> V_328 . V_329 , false ) ;
F_123 () ;
V_325 = V_327 [ V_332 ] ;
if ( V_326 != V_325 )
return - V_238 ;
F_125 ( V_2 ,
& V_283 [ V_316 ] ) ;
V_283 [ V_333 ] =
V_283 [ V_314 ] -
V_283 [ V_334 ] ;
F_126 ( & V_283 [ V_335 ] ,
V_283 [ V_334 ] ) ;
F_127 ( V_2 , V_283 ) ;
return 0 ;
}
static T_2 F_128 ( struct V_1 * V_2 , T_8 * V_280 ,
struct V_281 * V_282 )
{
int V_336 ;
for ( V_336 = 0 ; V_336 < 100 ; ++ V_336 ) {
if ( F_122 ( V_2 ) == 0 )
break;
F_129 ( 100 ) ;
}
return F_120 ( V_2 , V_280 , V_282 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_337 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
F_118 ( V_273 , V_276 ) ;
T_9 V_325 , V_326 ;
T_8 * V_283 = V_16 -> V_283 ;
T_6 V_338 = V_339 * sizeof( T_8 ) ;
struct V_340 V_341 ;
T_9 * V_327 ;
int V_18 ;
F_131 ( & V_2 -> V_342 ) ;
if ( F_132 () ) {
F_133 ( & V_2 -> V_342 ) ;
F_127 ( V_2 , V_283 ) ;
return 0 ;
}
F_115 ( V_2 , V_273 ) ;
V_18 = F_58 ( V_2 , & V_341 , V_338 , V_343 ) ;
if ( V_18 ) {
F_133 ( & V_2 -> V_342 ) ;
return V_18 ;
}
V_327 = V_341 . V_329 ;
V_327 [ V_330 ] = V_331 ;
F_134 ( V_73 , V_344 , V_341 . V_345 ) ;
F_135 ( V_73 , V_346 ,
V_347 , 1 ) ;
F_31 ( V_73 , V_348 , V_338 ) ;
F_31 ( V_73 , V_349 , V_78 ) ;
V_18 = F_25 ( V_2 , V_350 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
F_133 ( & V_2 -> V_342 ) ;
if ( V_18 ) {
if ( V_18 != - V_108 || F_136 ( & V_2 -> V_351 ) )
F_26 ( V_2 , V_350 ,
sizeof( V_73 ) , NULL , 0 , V_18 ) ;
goto V_352;
}
V_326 = V_327 [ V_330 ] ;
if ( V_326 == V_331 ) {
F_137 ( 1 ) ;
goto V_352;
}
F_123 () ;
F_124 ( V_279 , V_276 , V_273 ,
V_283 , V_341 . V_329 , false ) ;
F_123 () ;
V_325 = V_327 [ V_332 ] ;
if ( V_326 != V_325 ) {
V_18 = - V_238 ;
goto V_352;
}
F_127 ( V_2 , V_283 ) ;
V_352:
F_77 ( V_2 , & V_341 ) ;
return V_18 ;
}
static T_2 F_138 ( struct V_1 * V_2 , T_8 * V_280 ,
struct V_281 * V_282 )
{
if ( F_130 ( V_2 ) )
return 0 ;
return F_120 ( V_2 , V_280 , V_282 ) ;
}
static void F_139 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
unsigned int V_353 , V_354 ;
T_1 V_355 ;
if ( V_160 -> V_356 ) {
V_353 = 3 ;
V_354 = V_160 -> V_356 ;
} else {
V_353 = 0 ;
V_354 = 0 ;
}
if ( F_22 ( V_2 ) ) {
F_8 ( V_73 , V_357 ) ;
unsigned int V_358 = V_354 * 1000 ;
F_31 ( V_73 , V_359 ,
V_160 -> V_160 ) ;
F_31 ( V_73 , V_360 , V_358 ) ;
F_31 ( V_73 , V_361 , V_358 ) ;
F_31 ( V_73 , V_362 , V_353 ) ;
F_140 ( V_2 , V_363 ,
V_73 , sizeof( V_73 ) , 0 , NULL , 0 ) ;
} else if ( F_23 ( V_2 ) ) {
unsigned int V_364 = F_141 ( V_2 , V_354 ) ;
F_142 ( V_355 , V_365 ,
V_366 ,
V_367 , V_353 ,
V_368 , V_364 ) ;
F_143 ( V_2 , & V_355 , V_369 ,
V_160 -> V_160 ) ;
} else {
unsigned int V_364 = F_141 ( V_2 , V_354 ) ;
F_144 ( V_355 , V_370 , V_353 ,
V_371 , V_364 ) ;
F_143 ( V_2 , & V_355 , V_372 ,
V_160 -> V_160 ) ;
}
}
static void F_145 ( struct V_1 * V_2 ,
struct V_373 * V_374 ) {}
static int F_146 ( struct V_1 * V_2 , T_6 type )
{
return - V_375 ;
}
static void F_147 ( struct V_1 * V_2 , struct V_373 * V_374 )
{
V_374 -> V_376 = 0 ;
V_374 -> V_377 = 0 ;
memset ( & V_374 -> V_378 , 0 , sizeof( V_374 -> V_378 ) ) ;
}
static int F_148 ( struct V_1 * V_2 , T_6 type )
{
if ( type != 0 )
return - V_262 ;
return 0 ;
}
static void F_149 ( struct V_1 * V_2 ,
const T_1 * V_379 , T_2 V_380 ,
const T_1 * V_381 , T_2 V_382 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 * V_383 = V_16 -> V_115 . V_329 ;
memcpy ( V_383 , V_379 , V_380 ) ;
memcpy ( V_383 + V_380 , V_381 , V_382 ) ;
F_150 () ;
F_60 ( V_2 , F_61 ( ( T_8 ) V_16 -> V_115 . V_345 >> 32 ) ,
V_384 ) ;
F_60 ( V_2 , F_61 ( ( T_6 ) V_16 -> V_115 . V_345 ) ,
V_122 ) ;
}
static bool F_151 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_1 V_379 = * ( const T_1 * ) V_16 -> V_115 . V_329 ;
F_123 () ;
return F_3 ( V_379 , V_385 ) ;
}
static void
F_152 ( struct V_1 * V_2 , T_1 * V_13 ,
T_2 V_163 , T_2 V_17 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_3 * V_383 = V_16 -> V_115 . V_329 ;
memcpy ( V_13 , V_383 + V_163 , V_17 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_108 ( V_2 ) ;
V_16 -> V_240 = true ;
V_16 -> V_283 [ V_335 ] = 0 ;
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
static T_10 F_155 ( int V_386 , void * V_387 )
{
struct V_388 * V_389 = V_387 ;
struct V_1 * V_2 = V_389 -> V_2 ;
F_156 ( V_2 , V_390 , V_2 -> V_29 ,
L_28 , V_386 , F_157 () ) ;
if ( F_158 ( F_159 ( V_2 -> V_391 ) ) ) {
if ( V_389 -> V_164 == V_2 -> V_392 )
V_2 -> V_393 = F_157 () ;
F_160 ( V_2 -> V_160 [ V_389 -> V_164 ] ) ;
}
return V_394 ;
}
static T_10 F_161 ( int V_386 , void * V_387 )
{
struct V_1 * V_2 = V_387 ;
bool V_395 = F_159 ( V_2 -> V_391 ) ;
struct V_159 * V_160 ;
T_1 V_3 ;
T_6 V_396 ;
F_2 ( V_2 , & V_3 , V_397 ) ;
V_396 = F_3 ( V_3 , V_398 ) ;
if ( V_396 == 0 )
return V_399 ;
if ( F_158 ( V_395 ) ) {
if ( V_396 & ( 1U << V_2 -> V_392 ) )
V_2 -> V_393 = F_157 () ;
F_85 (channel, efx) {
if ( V_396 & 1 )
F_160 ( V_160 ) ;
V_396 >>= 1 ;
}
}
F_156 ( V_2 , V_390 , V_2 -> V_29 ,
L_29 V_400 L_30 ,
V_386 , F_157 () , F_162 ( V_3 ) ) ;
return V_394 ;
}
static int F_163 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_401 ) ;
if ( F_19 ( V_2 , V_402 , true ,
NULL ) == 0 )
return - V_403 ;
F_13 ( V_404 != 0 ) ;
F_31 ( V_73 , V_405 , V_2 -> V_392 ) ;
return F_9 ( V_2 , V_406 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
}
static int F_164 ( struct V_161 * V_162 )
{
return F_58 ( V_162 -> V_2 , & V_162 -> V_407 . V_87 ,
( V_162 -> V_408 + 1 ) *
sizeof( V_409 ) ,
V_100 ) ;
}
static inline void F_165 ( struct V_161 * V_162 ,
const V_409 * V_407 )
{
unsigned int V_410 ;
T_11 V_3 ;
V_410 = V_162 -> V_411 & V_162 -> V_408 ;
F_166 ( V_3 , V_412 , V_410 ) ;
V_3 . V_413 [ 0 ] = * V_407 ;
F_167 ( V_162 -> V_2 , & V_3 ,
V_414 , V_162 -> V_176 ) ;
}
static void F_168 ( struct V_161 * V_162 )
{
F_8 ( V_73 , F_169 ( V_415 * 8 /
V_416 ) ) ;
bool V_417 = V_162 -> V_176 & V_418 ;
T_2 V_419 = V_162 -> V_407 . V_87 . V_420 / V_416 ;
struct V_159 * V_160 = V_162 -> V_160 ;
struct V_1 * V_2 = V_162 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_421 ;
T_12 V_345 ;
V_409 * V_407 ;
int V_18 ;
int V_111 ;
F_13 ( V_422 != 0 ) ;
F_31 ( V_73 , V_423 , V_162 -> V_408 + 1 ) ;
F_31 ( V_73 , V_424 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_425 , V_162 -> V_176 ) ;
F_31 ( V_73 , V_426 , V_162 -> V_176 ) ;
F_170 ( V_73 , V_427 ,
V_428 , ! V_417 ,
V_429 , ! V_417 ) ;
F_31 ( V_73 , V_430 , 0 ) ;
F_31 ( V_73 , V_431 , V_16 -> V_121 ) ;
V_345 = V_162 -> V_407 . V_87 . V_345 ;
F_20 ( V_2 , V_432 , V_2 -> V_29 , L_31 ,
V_162 -> V_176 , V_419 , ( T_8 ) V_345 ) ;
for ( V_111 = 0 ; V_111 < V_419 ; ++ V_111 ) {
F_171 ( V_73 , V_433 , V_111 , V_345 ) ;
V_345 += V_416 ;
}
V_421 = F_169 ( V_419 ) ;
V_18 = F_9 ( V_2 , V_434 , V_73 , V_421 ,
NULL , 0 , NULL ) ;
if ( V_18 )
goto V_171;
V_162 -> V_435 [ 0 ] . V_251 = V_436 ;
V_162 -> V_437 = 1 ;
V_407 = F_172 ( V_162 , 0 ) ;
F_173 ( * V_407 ,
V_438 , true ,
V_439 ,
V_440 ,
V_441 , V_417 ,
V_442 , V_417 ) ;
V_162 -> V_411 = 1 ;
if ( V_16 -> V_30 &
( 1 << V_443 ) ) {
V_162 -> V_444 = 1 ;
}
F_150 () ;
F_165 ( V_162 , V_407 ) ;
return;
V_171:
F_174 ( V_2 -> V_29 , L_32 ,
V_162 -> V_176 ) ;
}
static void F_175 ( struct V_161 * V_162 )
{
F_8 ( V_73 , V_445 ) ;
F_79 ( V_13 ) ;
struct V_1 * V_2 = V_162 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_31 ( V_73 , V_446 ,
V_162 -> V_176 ) ;
V_18 = F_25 ( V_2 , V_447 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_97 )
goto V_171;
return;
V_171:
F_26 ( V_2 , V_447 , V_445 ,
V_13 , V_17 , V_18 ) ;
}
static void F_176 ( struct V_161 * V_162 )
{
F_77 ( V_162 -> V_2 , & V_162 -> V_407 . V_87 ) ;
}
static inline void F_177 ( struct V_161 * V_162 )
{
unsigned int V_410 ;
T_1 V_3 ;
V_410 = V_162 -> V_411 & V_162 -> V_408 ;
F_178 ( V_3 , V_448 , V_410 ) ;
F_143 ( V_162 -> V_2 , & V_3 ,
V_449 , V_162 -> V_176 ) ;
}
static void F_179 ( struct V_161 * V_162 )
{
unsigned int V_450 = V_162 -> V_411 ;
struct V_451 * V_435 ;
unsigned int V_410 ;
V_409 * V_407 ;
V_162 -> V_452 = false ;
if ( F_180 ( V_162 -> V_411 == V_162 -> V_437 ) )
return;
do {
V_410 = V_162 -> V_411 & V_162 -> V_408 ;
V_435 = & V_162 -> V_435 [ V_410 ] ;
V_407 = F_172 ( V_162 , V_410 ) ;
++ V_162 -> V_411 ;
if ( V_435 -> V_251 & V_436 ) {
* V_407 = V_435 -> V_453 ;
} else {
F_13 ( V_454 != 1 ) ;
F_181 (
* V_407 ,
V_455 ,
V_435 -> V_251 & V_454 ,
V_456 , V_435 -> V_420 ,
V_457 , V_435 -> V_345 ) ;
}
} while ( V_162 -> V_411 != V_162 -> V_437 );
F_150 () ;
if ( F_182 ( V_162 , V_450 ) ) {
V_407 = F_172 ( V_162 ,
V_450 & V_162 -> V_408 ) ;
F_165 ( V_162 , V_407 ) ;
++ V_162 -> V_458 ;
} else {
F_177 ( V_162 ) ;
}
}
static int F_183 ( struct V_1 * V_2 , T_6 * V_389 ,
bool V_459 , unsigned * V_460 )
{
F_8 ( V_73 , V_461 ) ;
F_8 ( V_13 , V_462 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_6 V_463 = V_459 ?
V_464 :
V_465 ;
unsigned V_466 = V_459 ?
V_2 -> V_466 :
F_184 ( F_185 ( V_2 -> V_466 ) ,
V_467 ) ;
if ( ! V_459 && V_466 == 1 ) {
* V_389 = V_120 ;
if ( V_460 )
* V_460 = 1 ;
return 0 ;
}
if ( V_16 -> V_30 &
1 << V_468 )
return - V_375 ;
F_31 ( V_73 , V_469 ,
V_16 -> V_121 ) ;
F_31 ( V_73 , V_470 , V_463 ) ;
F_31 ( V_73 , V_471 , V_466 ) ;
V_18 = F_9 ( V_2 , V_472 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_462 )
return - V_7 ;
* V_389 = F_10 ( V_13 , V_473 ) ;
if ( V_460 )
* V_460 = V_466 ;
return 0 ;
}
static void F_186 ( struct V_1 * V_2 , T_6 V_389 )
{
F_8 ( V_73 , V_474 ) ;
int V_18 ;
F_31 ( V_73 , V_475 ,
V_389 ) ;
V_18 = F_9 ( V_2 , V_476 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
F_32 ( V_18 != 0 ) ;
}
static int F_187 ( struct V_1 * V_2 , T_6 V_389 ,
const T_6 * V_243 )
{
F_8 ( V_477 , V_478 ) ;
F_8 ( V_479 , V_480 ) ;
int V_111 , V_18 ;
F_31 ( V_477 , V_481 ,
V_389 ) ;
F_13 ( F_188 ( V_2 -> V_243 ) !=
V_482 ) ;
for ( V_111 = 0 ; V_111 < F_188 ( V_2 -> V_243 ) ; ++ V_111 )
F_29 ( V_477 ,
V_483 ) [ V_111 ] =
( T_3 ) V_243 [ V_111 ] ;
V_18 = F_9 ( V_2 , V_484 , V_477 ,
sizeof( V_477 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_31 ( V_479 , V_485 ,
V_389 ) ;
F_13 ( F_188 ( V_2 -> V_486 ) !=
V_487 ) ;
for ( V_111 = 0 ; V_111 < F_188 ( V_2 -> V_486 ) ; ++ V_111 )
F_29 ( V_479 , V_488 ) [ V_111 ] =
V_2 -> V_486 [ V_111 ] ;
return F_9 ( V_2 , V_489 , V_479 ,
sizeof( V_479 ) , NULL , 0 , NULL ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_119 != V_120 )
F_186 ( V_2 , V_16 -> V_119 ) ;
V_16 -> V_119 = V_120 ;
}
static int F_189 ( struct V_1 * V_2 ,
unsigned * V_460 )
{
T_6 V_490 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_183 ( V_2 , & V_490 ,
false , V_460 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_119 = V_490 ;
V_16 -> V_491 = false ;
F_190 ( V_2 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 ,
const T_6 * V_243 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_490 ;
if ( V_16 -> V_119 == V_120 ||
! V_16 -> V_491 ) {
V_18 = F_183 ( V_2 , & V_490 ,
true , NULL ) ;
if ( V_18 == - V_375 )
return V_18 ;
else if ( V_18 != 0 )
goto V_116;
} else {
V_490 = V_16 -> V_119 ;
}
V_18 = F_187 ( V_2 , V_490 ,
V_243 ) ;
if ( V_18 != 0 )
goto V_117;
if ( V_16 -> V_119 != V_490 )
F_91 ( V_2 ) ;
V_16 -> V_119 = V_490 ;
V_16 -> V_491 = true ;
if ( V_243 != V_2 -> V_243 )
memcpy ( V_2 -> V_243 , V_243 ,
sizeof( V_2 -> V_243 ) ) ;
return 0 ;
V_117:
if ( V_490 != V_16 -> V_119 )
F_186 ( V_2 , V_490 ) ;
V_116:
F_14 ( V_2 , V_432 , V_2 -> V_29 , L_33 , V_492 , V_18 ) ;
return V_18 ;
}
static int F_192 ( struct V_1 * V_2 , bool V_493 ,
const T_6 * V_243 )
{
int V_18 ;
if ( V_2 -> V_466 == 1 )
return 0 ;
V_18 = F_191 ( V_2 , V_243 ) ;
if ( V_18 == - V_183 && ! V_493 ) {
unsigned V_460 ;
bool V_494 = false ;
T_2 V_111 ;
for ( V_111 = 0 ; V_111 < F_188 ( V_2 -> V_243 ) && ! V_494 ;
V_111 ++ )
V_494 = V_243 [ V_111 ] !=
F_193 ( V_111 , V_2 -> V_466 ) ;
V_18 = F_189 ( V_2 , & V_460 ) ;
if ( V_18 == 0 ) {
if ( V_460 != V_2 -> V_466 )
F_42 ( V_2 , V_39 , V_2 -> V_29 ,
L_34
L_35
L_36
L_37 ,
V_2 -> V_466 , V_460 ) ;
else if ( V_494 )
F_42 ( V_2 , V_39 , V_2 -> V_29 ,
L_34
L_38
L_39
L_40 ) ;
else
F_90 ( V_2 , V_39 , V_2 -> V_29 ,
L_34
L_41 ) ;
}
}
return V_18 ;
}
static int F_194 ( struct V_495 * V_496 )
{
return F_58 ( V_496 -> V_2 , & V_496 -> V_497 . V_87 ,
( V_496 -> V_408 + 1 ) *
sizeof( V_409 ) ,
V_100 ) ;
}
static void F_195 ( struct V_495 * V_496 )
{
F_8 ( V_73 ,
F_196 ( V_415 * 8 /
V_416 ) ) ;
struct V_159 * V_160 = F_197 ( V_496 ) ;
T_2 V_419 = V_496 -> V_497 . V_87 . V_420 / V_416 ;
struct V_1 * V_2 = V_496 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_421 ;
T_12 V_345 ;
int V_18 ;
int V_111 ;
F_13 ( V_498 != 0 ) ;
V_496 -> V_499 = 0 ;
V_496 -> V_500 = 0 ;
F_31 ( V_73 , V_501 , V_496 -> V_408 + 1 ) ;
F_31 ( V_73 , V_502 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_503 , F_198 ( V_496 ) ) ;
F_31 ( V_73 , V_504 ,
F_198 ( V_496 ) ) ;
F_170 ( V_73 , V_505 ,
V_506 , 1 ,
V_507 , 1 ) ;
F_31 ( V_73 , V_508 , 0 ) ;
F_31 ( V_73 , V_509 , V_16 -> V_121 ) ;
V_345 = V_496 -> V_497 . V_87 . V_345 ;
F_20 ( V_2 , V_432 , V_2 -> V_29 , L_42 ,
F_198 ( V_496 ) , V_419 , ( T_8 ) V_345 ) ;
for ( V_111 = 0 ; V_111 < V_419 ; ++ V_111 ) {
F_171 ( V_73 , V_510 , V_111 , V_345 ) ;
V_345 += V_416 ;
}
V_421 = F_196 ( V_419 ) ;
V_18 = F_9 ( V_2 , V_511 , V_73 , V_421 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_174 ( V_2 -> V_29 , L_43 ,
F_198 ( V_496 ) ) ;
}
static void F_199 ( struct V_495 * V_496 )
{
F_8 ( V_73 , V_512 ) ;
F_79 ( V_13 ) ;
struct V_1 * V_2 = V_496 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_31 ( V_73 , V_513 ,
F_198 ( V_496 ) ) ;
V_18 = F_25 ( V_2 , V_514 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_97 )
goto V_171;
return;
V_171:
F_26 ( V_2 , V_514 , V_512 ,
V_13 , V_17 , V_18 ) ;
}
static void F_200 ( struct V_495 * V_496 )
{
F_77 ( V_496 -> V_2 , & V_496 -> V_497 . V_87 ) ;
}
static inline void
F_201 ( struct V_495 * V_496 , unsigned int V_164 )
{
struct V_515 * V_516 ;
V_409 * V_497 ;
V_497 = F_202 ( V_496 , V_164 ) ;
V_516 = V_515 ( V_496 , V_164 ) ;
F_203 ( * V_497 ,
V_517 , V_516 -> V_420 ,
V_518 , V_516 -> V_345 ) ;
}
static void F_204 ( struct V_495 * V_496 )
{
struct V_1 * V_2 = V_496 -> V_2 ;
unsigned int V_411 ;
T_1 V_3 ;
V_411 = V_496 -> V_519 & ~ 7 ;
if ( V_496 -> V_520 == V_411 )
return;
do
F_201 (
V_496 ,
V_496 -> V_520 & V_496 -> V_408 ) ;
while ( ++ V_496 -> V_520 != V_411 );
F_150 () ;
F_178 ( V_3 , V_521 ,
V_411 & V_496 -> V_408 ) ;
F_143 ( V_2 , & V_3 , V_522 ,
F_198 ( V_496 ) ) ;
}
static void F_205 ( struct V_495 * V_496 )
{
struct V_159 * V_160 = F_197 ( V_496 ) ;
F_8 ( V_73 , V_523 ) ;
V_409 V_524 ;
F_203 ( V_524 ,
V_525 , V_526 ,
V_527 , V_528 ) ;
F_31 ( V_73 , V_529 , V_160 -> V_160 ) ;
memcpy ( F_29 ( V_73 , V_530 ) , & V_524 . T_8 [ 0 ] ,
sizeof( V_409 ) ) ;
F_140 ( V_160 -> V_2 , V_531 ,
V_73 , sizeof( V_73 ) , 0 ,
V_532 , 0 ) ;
}
static void
V_532 ( struct V_1 * V_2 , unsigned long V_533 ,
int V_18 , T_1 * V_13 ,
T_2 V_534 )
{
}
static int F_206 ( struct V_159 * V_160 )
{
return F_58 ( V_160 -> V_2 , & V_160 -> V_535 . V_87 ,
( V_160 -> V_536 + 1 ) *
sizeof( V_409 ) ,
V_100 ) ;
}
static void F_207 ( struct V_159 * V_160 )
{
F_8 ( V_73 , V_537 ) ;
F_79 ( V_13 ) ;
struct V_1 * V_2 = V_160 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_31 ( V_73 , V_538 , V_160 -> V_160 ) ;
V_18 = F_25 ( V_2 , V_539 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_97 )
goto V_171;
return;
V_171:
F_26 ( V_2 , V_539 , V_537 ,
V_13 , V_17 , V_18 ) ;
}
static int F_208 ( struct V_159 * V_160 )
{
F_8 ( V_73 ,
F_209 ( V_540 * 8 /
V_416 ) ) ;
F_8 ( V_13 , V_541 ) ;
T_2 V_419 = V_160 -> V_535 . V_87 . V_420 / V_416 ;
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_15 * V_16 ;
T_2 V_421 , V_17 ;
unsigned int V_46 , V_45 ;
T_12 V_345 ;
int V_18 ;
int V_111 ;
V_16 = V_2 -> V_16 ;
memset ( V_160 -> V_535 . V_87 . V_329 , 0xff , V_160 -> V_535 . V_87 . V_420 ) ;
F_31 ( V_73 , V_542 , V_160 -> V_536 + 1 ) ;
F_31 ( V_73 , V_543 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_544 , V_160 -> V_160 ) ;
F_31 ( V_73 , V_545 ,
V_546 ) ;
F_31 ( V_73 , V_547 , 0 ) ;
F_31 ( V_73 , V_548 , 0 ) ;
F_31 ( V_73 , V_549 ,
V_550 ) ;
F_31 ( V_73 , V_551 , 0 ) ;
if ( V_16 -> V_32 &
1 << V_552 ) {
F_170 ( V_73 , V_553 ,
V_554 , 1 ,
V_555 ,
V_556 ) ;
} else {
bool V_557 = ! ( V_16 -> V_30 &
1 << V_558 ) ;
F_210 ( V_73 , V_559 ,
V_560 , 1 ,
V_561 , 1 ,
V_562 , 1 ,
V_563 , V_557 ) ;
}
V_345 = V_160 -> V_535 . V_87 . V_345 ;
for ( V_111 = 0 ; V_111 < V_419 ; ++ V_111 ) {
F_171 ( V_73 , V_564 , V_111 , V_345 ) ;
V_345 += V_416 ;
}
V_421 = F_211 ( V_419 ) ;
V_18 = F_9 ( V_2 , V_565 , V_73 , V_421 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_17 >= V_541 )
F_20 ( V_2 , V_28 , V_2 -> V_29 ,
L_44 ,
V_160 -> V_160 ,
F_10 ( V_13 , V_566 ) ) ;
if ( V_160 -> V_160 || V_18 )
return V_18 ;
V_18 = F_18 ( V_2 , & V_45 , & V_46 ) ;
if ( V_18 == - V_49 ) {
V_16 -> V_567 = false ;
V_18 = 0 ;
} else if ( V_18 ) {
goto V_171;
} else {
V_16 -> V_567 =
! ! ( V_46 & V_568 ) ;
if ( V_45 & V_568 &&
! V_16 -> V_567 ) {
unsigned int V_251 ;
V_18 = F_19 ( V_2 ,
V_569 ,
true , & V_251 ) ;
if ( ! V_18 ) {
if ( V_251 &
1 << V_570 ) {
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_45 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 ) {
V_16 -> V_118 = V_18 ;
V_18 = 0 ;
}
}
V_16 -> V_567 = true ;
} else if ( V_18 == - V_65 ) {
V_18 = 0 ;
}
}
}
if ( ! V_18 )
return 0 ;
V_171:
F_207 ( V_160 ) ;
return V_18 ;
}
static void F_212 ( struct V_159 * V_160 )
{
F_77 ( V_160 -> V_2 , & V_160 -> V_535 . V_87 ) ;
}
static void F_213 ( struct V_495 * V_496 ,
unsigned int V_571 )
{
struct V_1 * V_2 = V_496 -> V_2 ;
F_90 ( V_2 , V_432 , V_2 -> V_29 ,
L_46 ,
F_198 ( V_496 ) , V_571 ) ;
F_214 ( V_2 , V_572 ) ;
}
static void
F_215 ( struct V_495 * V_496 ,
unsigned int V_573 , unsigned int V_574 )
{
unsigned int V_575 = ( V_573 - V_574 ) & V_496 -> V_408 ;
struct V_1 * V_2 = V_496 -> V_2 ;
F_90 ( V_2 , V_432 , V_2 -> V_29 ,
L_47 ,
V_575 , V_573 , V_574 ) ;
F_214 ( V_2 , V_572 ) ;
}
static void F_216 ( struct V_495 * V_496 )
{
unsigned int V_576 ;
F_20 ( V_496 -> V_2 , V_432 , V_496 -> V_2 -> V_29 ,
L_48 ,
V_496 -> V_499 ) ;
V_576 = V_496 -> V_577 & V_496 -> V_408 ;
F_217 ( V_496 , V_576 , V_496 -> V_499 ,
0 , V_578 ) ;
V_496 -> V_577 += V_496 -> V_499 ;
V_496 -> V_499 = 0 ;
V_496 -> V_500 = 0 ;
++ F_197 ( V_496 ) -> V_579 ;
}
static int F_218 ( struct V_159 * V_160 ,
const V_409 * V_524 )
{
unsigned int V_293 , V_580 , V_571 , V_581 ;
unsigned int V_582 , V_583 , V_111 ;
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_495 * V_496 ;
bool V_584 ;
T_5 V_251 = 0 ;
if ( F_180 ( F_159 ( V_2 -> V_585 ) ) )
return 0 ;
V_293 = F_219 ( * V_524 , V_586 ) ;
V_580 = F_219 ( * V_524 , V_587 ) ;
V_571 = F_219 ( * V_524 , V_588 ) ;
V_581 = F_219 ( * V_524 , V_589 ) ;
V_584 = F_219 ( * V_524 , V_590 ) ;
if ( F_219 ( * V_524 , V_591 ) )
F_174 ( V_2 -> V_29 , L_49
V_592 L_30 ,
F_220 ( * V_524 ) ) ;
V_496 = F_221 ( V_160 ) ;
if ( F_180 ( V_571 != F_198 ( V_496 ) ) )
F_213 ( V_496 , V_571 ) ;
V_582 = ( ( V_580 - V_496 -> V_577 ) &
( ( 1 << V_593 ) - 1 ) ) ;
if ( V_582 != V_496 -> V_499 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_180 ( V_582 == V_496 -> V_499 ) ) {
if ( V_496 -> V_499 == 0 || V_293 != 0 )
F_174 ( V_2 -> V_29 ,
L_50
V_592 L_30 ,
V_496 -> V_499 ,
F_220 ( * V_524 ) ) ;
F_216 ( V_496 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_30 &
( 1 << V_558 ) ) ||
V_496 -> V_499 != 0 || V_584 ) {
F_215 (
V_496 , V_580 ,
( V_496 -> V_577 +
V_496 -> V_499 + 1 ) &
( ( 1 << V_593 ) - 1 ) ) ;
return 0 ;
}
V_496 -> V_499 = 1 ;
V_496 -> V_500 = 0 ;
V_583 = V_582 ;
++ V_160 -> V_594 ;
V_160 -> V_595 += V_583 ;
V_251 |= V_596 ;
} else {
++ V_496 -> V_499 ;
V_496 -> V_500 += V_293 ;
if ( V_584 )
return 0 ;
V_583 = 1 ;
}
if ( F_180 ( F_219 ( * V_524 , V_597 ) ) )
V_251 |= V_578 ;
if ( F_180 ( F_219 ( * V_524 , V_598 ) ) ) {
V_160 -> V_599 += V_583 ;
} else if ( F_180 ( F_219 ( * V_524 ,
V_600 ) ) ) {
V_160 -> V_601 += V_583 ;
} else if ( V_581 == V_602 ||
V_581 == V_603 ) {
V_251 |= V_604 ;
}
if ( V_581 == V_602 )
V_251 |= V_605 ;
V_160 -> V_606 += 2 * V_583 ;
for ( V_111 = 0 ; V_111 < V_583 ; V_111 ++ ) {
F_217 ( V_496 ,
V_496 -> V_577 & V_496 -> V_408 ,
V_496 -> V_499 , V_496 -> V_500 ,
V_251 ) ;
V_496 -> V_577 += V_496 -> V_499 ;
}
V_496 -> V_499 = 0 ;
V_496 -> V_500 = 0 ;
return V_583 ;
}
static int
F_222 ( struct V_159 * V_160 , V_409 * V_524 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
struct V_161 * V_162 ;
unsigned int V_607 ;
unsigned int V_608 ;
int V_609 = 0 ;
if ( F_180 ( F_159 ( V_2 -> V_585 ) ) )
return 0 ;
if ( F_180 ( F_219 ( * V_524 , V_610 ) ) )
return 0 ;
V_607 = F_219 ( * V_524 , V_611 ) ;
V_608 = F_219 ( * V_524 , V_612 ) ;
V_162 = F_223 ( V_160 ,
V_608 % V_231 ) ;
V_609 = ( ( V_607 + 1 - V_162 -> V_613 ) &
V_162 -> V_408 ) ;
F_224 ( V_162 , V_607 & V_162 -> V_408 ) ;
return V_609 ;
}
static void
F_225 ( struct V_159 * V_160 , V_409 * V_524 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
int V_614 ;
V_614 = F_219 ( * V_524 , V_615 ) ;
switch ( V_614 ) {
case V_616 :
case V_617 :
break;
case V_618 :
break;
default:
F_14 ( V_2 , V_432 , V_2 -> V_29 ,
L_51
L_52 V_592 L_53 ,
V_160 -> V_160 , V_614 ,
F_220 ( * V_524 ) ) ;
}
}
static void F_226 ( struct V_159 * V_160 ,
V_409 * V_524 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
T_6 V_614 ;
V_614 = F_219 ( * V_524 , V_619 ) ;
switch ( V_614 ) {
case V_620 :
V_160 -> V_621 = F_157 () ;
break;
case V_528 :
F_227 ( & V_160 -> V_496 , true ) ;
break;
default:
F_14 ( V_2 , V_432 , V_2 -> V_29 ,
L_54
L_52 V_592 L_53 ,
V_160 -> V_160 , ( unsigned ) V_614 ,
F_220 ( * V_524 ) ) ;
}
}
static int F_228 ( struct V_159 * V_160 , int V_622 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
V_409 V_524 , * V_623 ;
unsigned int V_624 ;
int V_625 ;
int V_609 = 0 ;
int V_626 = 0 ;
if ( V_622 <= 0 )
return V_626 ;
V_624 = V_160 -> V_627 ;
for (; ; ) {
V_623 = F_229 ( V_160 , V_624 ) ;
V_524 = * V_623 ;
if ( ! F_230 ( & V_524 ) )
break;
F_231 ( * V_623 ) ;
++ V_624 ;
V_625 = F_219 ( V_524 , V_525 ) ;
F_156 ( V_2 , V_28 , V_2 -> V_29 ,
L_55 V_592 L_30 ,
V_160 -> V_160 , F_220 ( V_524 ) ) ;
switch ( V_625 ) {
case V_628 :
F_232 ( V_160 , & V_524 ) ;
break;
case V_629 :
V_626 += F_218 ( V_160 , & V_524 ) ;
if ( V_626 >= V_622 ) {
V_626 = V_622 ;
goto V_352;
}
break;
case V_630 :
V_609 += F_222 ( V_160 , & V_524 ) ;
if ( V_609 > V_2 -> V_631 ) {
V_626 = V_622 ;
goto V_352;
} else if ( ++ V_626 == V_622 ) {
goto V_352;
}
break;
case V_632 :
F_225 ( V_160 , & V_524 ) ;
if ( ++ V_626 == V_622 )
goto V_352;
break;
case V_526 :
F_226 ( V_160 , & V_524 ) ;
break;
default:
F_14 ( V_2 , V_432 , V_2 -> V_29 ,
L_56
L_52 V_592 L_53 ,
V_160 -> V_160 , V_625 ,
F_220 ( V_524 ) ) ;
}
}
V_352:
V_160 -> V_627 = V_624 ;
return V_626 ;
}
static void F_233 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = V_160 -> V_2 ;
T_1 V_633 ;
if ( F_23 ( V_2 ) ) {
F_13 ( V_634 <
( 1 << V_635 ) ) ;
F_13 ( V_540 >
( 1 << 2 * V_635 ) ) ;
F_144 ( V_633 , V_636 ,
V_637 ,
V_638 ,
( V_160 -> V_627 &
V_160 -> V_536 ) >>
V_635 ) ;
F_143 ( V_2 , & V_633 , V_369 ,
V_160 -> V_160 ) ;
F_144 ( V_633 , V_636 ,
V_639 ,
V_638 ,
V_160 -> V_627 &
( ( 1 << V_635 ) - 1 ) ) ;
F_143 ( V_2 , & V_633 , V_369 ,
V_160 -> V_160 ) ;
} else {
F_178 ( V_633 , V_640 ,
V_160 -> V_627 &
V_160 -> V_536 ) ;
F_143 ( V_2 , & V_633 , V_641 , V_160 -> V_160 ) ;
}
}
static void F_234 ( struct V_159 * V_160 )
{
F_8 ( V_73 , V_523 ) ;
struct V_1 * V_2 = V_160 -> V_2 ;
V_409 V_524 ;
int V_18 ;
F_203 ( V_524 ,
V_525 , V_526 ,
V_527 , V_620 ) ;
F_31 ( V_73 , V_529 , V_160 -> V_160 ) ;
memcpy ( F_29 ( V_73 , V_530 ) , & V_524 . T_8 [ 0 ] ,
sizeof( V_409 ) ) ;
V_18 = F_9 ( V_2 , V_531 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_171;
return;
V_171:
F_32 ( true ) ;
F_14 ( V_2 , V_432 , V_2 -> V_29 , L_33 , V_492 , V_18 ) ;
}
void F_235 ( struct V_1 * V_2 )
{
if ( F_236 ( & V_2 -> V_351 ) )
F_237 ( & V_2 -> V_642 ) ;
F_32 ( F_136 ( & V_2 -> V_351 ) < 0 ) ;
}
static int F_238 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
struct V_495 * V_496 ;
int V_643 ;
if ( V_16 -> V_241 ) {
F_239 ( & V_2 -> V_351 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_644 != V_645 ) {
F_85 (channel, efx) {
F_240 (rx_queue, channel)
F_199 ( V_496 ) ;
F_86 (tx_queue, channel)
F_175 ( V_162 ) ;
}
F_241 ( V_2 -> V_642 ,
F_136 ( & V_2 -> V_351 ) == 0 ,
F_242 ( V_646 ) ) ;
V_643 = F_136 ( & V_2 -> V_351 ) ;
if ( V_643 ) {
F_14 ( V_2 , V_432 , V_2 -> V_29 , L_57 ,
V_643 ) ;
return - V_647 ;
}
}
return 0 ;
}
static void F_243 ( struct V_1 * V_2 )
{
F_239 ( & V_2 -> V_351 , 0 ) ;
}
static bool F_244 ( const struct V_648 * V_649 ,
const struct V_648 * V_650 )
{
if ( ( V_649 -> V_651 ^ V_650 -> V_651 ) |
( ( V_649 -> V_251 ^ V_650 -> V_251 ) &
( V_652 | V_653 ) ) )
return false ;
return memcmp ( & V_649 -> V_654 , & V_650 -> V_654 ,
sizeof( struct V_648 ) -
F_245 ( struct V_648 , V_654 ) ) == 0 ;
}
static unsigned int F_246 ( const struct V_648 * V_655 )
{
F_13 ( F_245 ( struct V_648 , V_654 ) & 3 ) ;
return F_247 ( ( const T_6 * ) & V_655 -> V_654 ,
( sizeof( struct V_648 ) -
F_245 ( struct V_648 , V_654 ) ) / 4 ,
0 ) ;
}
static bool F_248 ( const struct V_648 * V_655 )
{
if ( V_655 -> V_651 & V_656 &&
! F_249 ( V_655 -> V_657 ) )
return true ;
if ( ( V_655 -> V_651 &
( V_658 | V_659 ) ) ==
( V_658 | V_659 ) ) {
if ( V_655 -> V_660 == F_250 ( V_661 ) &&
! F_251 ( V_655 -> V_662 [ 0 ] ) )
return true ;
if ( V_655 -> V_660 == F_250 ( V_663 ) &&
( ( const T_3 * ) V_655 -> V_662 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_648 *
F_252 ( const struct V_664 * V_665 ,
unsigned int V_666 )
{
return (struct V_648 * ) ( V_665 -> V_667 [ V_666 ] . V_655 &
~ V_668 ) ;
}
static unsigned int
F_253 ( const struct V_664 * V_665 ,
unsigned int V_666 )
{
return V_665 -> V_667 [ V_666 ] . V_655 & V_668 ;
}
static void
F_254 ( struct V_664 * V_665 ,
unsigned int V_666 ,
const struct V_648 * V_655 ,
unsigned int V_251 )
{
V_665 -> V_667 [ V_666 ] . V_655 = ( unsigned long ) V_655 | V_251 ;
}
static void F_255 ( struct V_1 * V_2 ,
const struct V_648 * V_655 ,
T_1 * V_73 , T_8 V_669 ,
bool V_670 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_6 V_251 = V_655 -> V_251 ;
memset ( V_73 , 0 , V_671 ) ;
if ( V_251 & V_672 &&
V_655 -> V_673 == V_674 &&
V_16 -> V_119 == V_120 )
V_251 &= ~ V_672 ;
if ( V_670 ) {
F_31 ( V_73 , V_675 ,
V_676 ) ;
F_134 ( V_73 , V_677 , V_669 ) ;
} else {
T_6 V_678 = 0 ;
F_31 ( V_73 , V_675 ,
F_248 ( V_655 ) ?
V_679 :
V_680 ) ;
if ( V_655 -> V_651 & V_681 )
V_678 |=
F_249 ( V_655 -> V_657 ) ?
1 << V_682 :
1 << V_683 ;
#define F_256 ( T_13 , T_14 , T_15 ) \
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
F_256 ( V_684 , V_685 , V_686 ) ;
F_256 ( V_687 , V_662 , V_688 ) ;
F_256 ( V_689 , V_690 , V_691 ) ;
F_256 ( V_692 , V_693 , V_694 ) ;
F_256 ( V_695 , V_657 , V_696 ) ;
F_256 ( V_697 , V_698 , V_699 ) ;
F_256 ( V_700 , V_660 , V_700 ) ;
F_256 ( V_701 , V_702 , V_703 ) ;
F_256 ( V_704 , V_654 , V_705 ) ;
F_256 ( V_706 , V_707 , V_706 ) ;
#undef F_256
F_31 ( V_73 , V_708 ,
V_678 ) ;
}
F_31 ( V_73 , V_709 , V_16 -> V_121 ) ;
F_31 ( V_73 , V_710 ,
V_655 -> V_711 == V_712 ?
V_713 :
V_714 ) ;
F_31 ( V_73 , V_715 , 0 ) ;
F_31 ( V_73 , V_716 ,
V_717 ) ;
F_31 ( V_73 , V_718 ,
V_655 -> V_711 == V_712 ?
0 : V_655 -> V_711 ) ;
F_31 ( V_73 , V_719 ,
( V_251 & V_672 ) ?
V_720 :
V_721 ) ;
if ( V_251 & V_672 )
F_31 ( V_73 , V_722 ,
V_655 -> V_673 !=
V_674 ?
V_655 -> V_673 : V_16 -> V_119 ) ;
}
static int F_257 ( struct V_1 * V_2 ,
const struct V_648 * V_655 ,
T_8 * V_669 , bool V_670 )
{
F_8 ( V_73 , V_671 ) ;
F_8 ( V_13 , V_723 ) ;
int V_18 ;
F_255 ( V_2 , V_655 , V_73 , * V_669 , V_670 ) ;
V_18 = F_9 ( V_2 , V_724 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_669 = F_258 ( V_13 , V_725 ) ;
if ( V_18 == - V_155 )
V_18 = - V_216 ;
return V_18 ;
}
static T_6 F_259 ( const struct V_648 * V_655 )
{
unsigned int V_651 = V_655 -> V_651 ;
T_6 V_726 = 0 ;
if ( V_651 & V_681 ) {
V_651 &= ~ V_681 ;
V_726 |=
F_249 ( V_655 -> V_657 ) ?
( 1 << V_682 ) :
( 1 << V_683 ) ;
}
#define F_260 ( T_13 , T_15 ) { \
unsigned int old_match_flags = match_flags; \
match_flags &= ~EFX_FILTER_MATCH_ ## gen_flag; \
if (match_flags != old_match_flags) \
mcdi_flags |= \
(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
}
F_260 ( V_684 , V_686 ) ;
F_260 ( V_687 , V_688 ) ;
F_260 ( V_689 , V_691 ) ;
F_260 ( V_692 , V_694 ) ;
F_260 ( V_695 , V_696 ) ;
F_260 ( V_697 , V_699 ) ;
F_260 ( V_700 , V_700 ) ;
F_260 ( V_701 , V_703 ) ;
F_260 ( V_704 , V_705 ) ;
F_260 ( V_706 , V_706 ) ;
#undef F_260
F_137 ( V_651 ) ;
return V_726 ;
}
static int F_261 ( struct V_664 * V_665 ,
const struct V_648 * V_655 )
{
T_6 V_726 = F_259 ( V_655 ) ;
unsigned int V_727 ;
for ( V_727 = 0 ;
V_727 < V_665 -> V_728 ;
V_727 ++ )
if ( V_665 -> V_729 [ V_727 ] == V_726 )
return V_727 ;
return - V_730 ;
}
static T_16 F_262 ( struct V_1 * V_2 ,
struct V_648 * V_655 ,
bool V_731 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
F_118 ( V_732 , V_733 ) ;
struct V_648 * V_734 ;
unsigned int V_727 , V_735 ;
unsigned int V_736 ;
bool V_670 = false ;
int V_737 = - 1 ;
F_263 ( V_738 ) ;
bool V_739 ;
T_16 V_18 ;
if ( ( V_655 -> V_251 & ( V_652 | V_653 ) ) !=
V_652 )
return - V_262 ;
V_18 = F_261 ( V_665 , V_655 ) ;
if ( V_18 < 0 )
return V_18 ;
V_727 = V_18 ;
V_735 = F_246 ( V_655 ) ;
V_739 = F_264 ( V_655 ) ;
if ( V_739 )
F_265 ( V_732 , V_733 ) ;
for (; ; ) {
unsigned int V_740 = 1 ;
unsigned int V_111 ;
F_133 ( & V_2 -> V_741 ) ;
for (; ; ) {
V_111 = ( V_735 + V_740 ) & ( V_742 - 1 ) ;
V_734 = F_252 ( V_665 , V_111 ) ;
if ( ! V_734 ) {
if ( V_737 < 0 )
V_737 = V_111 ;
} else if ( F_244 ( V_655 , V_734 ) ) {
if ( V_665 -> V_667 [ V_111 ] . V_655 &
V_743 )
break;
if ( V_655 -> V_744 < V_734 -> V_744 &&
V_655 -> V_744 != V_745 ) {
V_18 = - V_65 ;
goto V_746;
}
if ( ! V_739 ) {
if ( V_655 -> V_744 ==
V_734 -> V_744 &&
! V_731 ) {
V_18 = - V_747 ;
goto V_746;
}
V_737 = V_111 ;
goto V_748;
} else if ( V_655 -> V_744 >
V_734 -> V_744 ||
( V_655 -> V_744 ==
V_734 -> V_744 &&
V_731 ) ) {
if ( V_737 < 0 )
V_737 = V_111 ;
else
F_266 ( V_740 , V_732 ) ;
}
}
if ( V_740 == V_733 ) {
if ( V_737 < 0 ) {
V_18 = - V_216 ;
goto V_746;
}
goto V_748;
}
++ V_740 ;
}
F_267 ( & V_665 -> V_749 , & V_738 , V_750 ) ;
F_131 ( & V_2 -> V_741 ) ;
F_268 () ;
}
V_748:
V_734 = F_252 ( V_665 , V_737 ) ;
if ( V_734 ) {
if ( V_655 -> V_744 == V_745 &&
V_734 -> V_744 >= V_745 ) {
if ( V_734 -> V_744 > V_745 )
V_734 -> V_251 |= V_751 ;
V_665 -> V_667 [ V_737 ] . V_655 &=
~ V_752 ;
V_18 = V_737 ;
goto V_746;
}
V_670 = true ;
V_736 = F_253 ( V_665 , V_737 ) ;
} else {
V_734 = F_269 ( sizeof( * V_655 ) , V_343 ) ;
if ( ! V_734 ) {
V_18 = - V_99 ;
goto V_746;
}
* V_734 = * V_655 ;
V_736 = 0 ;
}
F_254 ( V_665 , V_737 , V_734 ,
V_736 | V_743 ) ;
if ( V_739 ) {
unsigned int V_740 , V_111 ;
for ( V_740 = 0 ; V_740 < V_733 ; V_740 ++ ) {
V_111 = ( V_735 + V_740 ) & ( V_742 - 1 ) ;
if ( F_270 ( V_740 , V_732 ) )
V_665 -> V_667 [ V_111 ] . V_655 |=
V_743 ;
}
}
F_131 ( & V_2 -> V_741 ) ;
V_18 = F_257 ( V_2 , V_655 , & V_665 -> V_667 [ V_737 ] . V_669 ,
V_670 ) ;
F_133 ( & V_2 -> V_741 ) ;
if ( V_18 == 0 ) {
if ( V_670 ) {
if ( V_734 -> V_744 == V_745 )
V_734 -> V_251 |=
V_751 ;
V_734 -> V_744 = V_655 -> V_744 ;
V_734 -> V_251 &= V_751 ;
V_734 -> V_251 |= V_655 -> V_251 ;
V_734 -> V_673 = V_655 -> V_673 ;
V_734 -> V_711 = V_655 -> V_711 ;
}
} else if ( ! V_670 ) {
F_50 ( V_734 ) ;
V_734 = NULL ;
}
F_254 ( V_665 , V_737 , V_734 , V_736 ) ;
if ( V_739 ) {
F_8 ( V_73 , V_671 ) ;
unsigned int V_740 , V_111 ;
memset ( V_73 , 0 , sizeof( V_73 ) ) ;
for ( V_740 = 0 ; V_740 < V_733 ; V_740 ++ ) {
if ( ! F_270 ( V_740 , V_732 ) )
continue;
V_111 = ( V_735 + V_740 ) & ( V_742 - 1 ) ;
V_734 = F_252 ( V_665 , V_111 ) ;
V_736 = F_253 ( V_665 , V_111 ) ;
if ( V_18 == 0 ) {
F_131 ( & V_2 -> V_741 ) ;
F_31 ( V_73 , V_675 ,
V_753 ) ;
F_134 ( V_73 , V_677 ,
V_665 -> V_667 [ V_111 ] . V_669 ) ;
V_18 = F_9 ( V_2 , V_724 ,
V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
F_133 ( & V_2 -> V_741 ) ;
}
if ( V_18 == 0 ) {
F_50 ( V_734 ) ;
V_734 = NULL ;
V_736 = 0 ;
} else {
V_736 &= ~ V_743 ;
}
F_254 ( V_665 , V_111 , V_734 ,
V_736 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_727 * V_742 + V_737 ;
F_271 ( & V_665 -> V_749 ) ;
V_746:
F_131 ( & V_2 -> V_741 ) ;
F_272 ( & V_665 -> V_749 , & V_738 ) ;
return V_18 ;
}
static void F_273 ( struct V_1 * V_2 )
{
}
static int F_274 ( struct V_1 * V_2 ,
unsigned int V_754 ,
T_6 V_755 , bool V_756 )
{
unsigned int V_666 = V_755 % V_742 ;
struct V_664 * V_665 = V_2 -> V_104 ;
F_8 ( V_73 ,
V_757 +
V_758 ) ;
struct V_648 * V_655 ;
F_263 ( V_738 ) ;
int V_18 ;
for (; ; ) {
F_133 ( & V_2 -> V_741 ) ;
if ( ! ( V_665 -> V_667 [ V_666 ] . V_655 &
V_743 ) )
break;
F_267 ( & V_665 -> V_749 , & V_738 , V_750 ) ;
F_131 ( & V_2 -> V_741 ) ;
F_268 () ;
}
V_655 = F_252 ( V_665 , V_666 ) ;
if ( ! V_655 ||
( ! V_756 &&
F_261 ( V_665 , V_655 ) !=
V_755 / V_742 ) ) {
V_18 = - V_108 ;
goto V_746;
}
if ( V_655 -> V_251 & V_751 &&
V_754 == ( 1U << V_745 ) ) {
V_655 -> V_251 &= ~ V_751 ;
V_665 -> V_667 [ V_666 ] . V_655 &= ~ V_752 ;
V_18 = 0 ;
goto V_746;
}
if ( ! ( V_754 & ( 1U << V_655 -> V_744 ) ) ) {
V_18 = - V_108 ;
goto V_746;
}
V_665 -> V_667 [ V_666 ] . V_655 |= V_743 ;
F_131 ( & V_2 -> V_741 ) ;
if ( V_655 -> V_251 & V_751 ) {
struct V_648 V_759 = * V_655 ;
V_759 . V_744 = V_745 ;
V_759 . V_251 = ( V_652 |
( F_275 ( V_2 ) ?
V_672 : 0 ) ) ;
V_759 . V_711 = 0 ;
V_759 . V_673 = V_674 ;
V_18 = F_257 ( V_2 , & V_759 ,
& V_665 -> V_667 [ V_666 ] . V_669 ,
true ) ;
F_133 ( & V_2 -> V_741 ) ;
if ( V_18 == 0 )
* V_655 = V_759 ;
} else {
F_31 ( V_73 , V_675 ,
F_248 ( V_655 ) ?
V_760 :
V_753 ) ;
F_134 ( V_73 , V_677 ,
V_665 -> V_667 [ V_666 ] . V_669 ) ;
V_18 = F_9 ( V_2 , V_724 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
F_133 ( & V_2 -> V_741 ) ;
if ( V_18 == 0 ) {
F_50 ( V_655 ) ;
F_254 ( V_665 , V_666 , NULL , 0 ) ;
}
}
V_665 -> V_667 [ V_666 ] . V_655 &= ~ V_743 ;
F_271 ( & V_665 -> V_749 ) ;
V_746:
F_131 ( & V_2 -> V_741 ) ;
F_272 ( & V_665 -> V_749 , & V_738 ) ;
return V_18 ;
}
static int F_276 ( struct V_1 * V_2 ,
enum V_761 V_744 ,
T_6 V_755 )
{
return F_274 ( V_2 , 1U << V_744 ,
V_755 , false ) ;
}
static T_6 F_277 ( struct V_1 * V_2 , T_6 V_755 )
{
return V_755 % V_742 ;
}
static void F_278 ( struct V_1 * V_2 ,
enum V_761 V_744 ,
T_6 V_755 )
{
if ( V_755 == V_762 )
return;
F_274 ( V_2 , 1U << V_744 , V_755 , true ) ;
}
static int F_279 ( struct V_1 * V_2 ,
enum V_761 V_744 ,
T_6 V_755 , struct V_648 * V_655 )
{
unsigned int V_666 = V_755 % V_742 ;
struct V_664 * V_665 = V_2 -> V_104 ;
const struct V_648 * V_734 ;
int V_18 ;
F_133 ( & V_2 -> V_741 ) ;
V_734 = F_252 ( V_665 , V_666 ) ;
if ( V_734 && V_734 -> V_744 == V_744 &&
F_261 ( V_665 , V_734 ) ==
V_755 / V_742 ) {
* V_655 = * V_734 ;
V_18 = 0 ;
} else {
V_18 = - V_108 ;
}
F_131 ( & V_2 -> V_741 ) ;
return V_18 ;
}
static int F_280 ( struct V_1 * V_2 ,
enum V_761 V_744 )
{
unsigned int V_754 ;
unsigned int V_111 ;
int V_18 ;
V_754 = ( ( ( 1U << ( V_744 + 1 ) ) - 1 ) &
~ ( 1U << V_745 ) ) ;
for ( V_111 = 0 ; V_111 < V_742 ; V_111 ++ ) {
V_18 = F_274 ( V_2 , V_754 ,
V_111 , true ) ;
if ( V_18 && V_18 != - V_108 )
return V_18 ;
}
return 0 ;
}
static T_6 F_281 ( struct V_1 * V_2 ,
enum V_761 V_744 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
unsigned int V_666 ;
T_16 V_763 = 0 ;
F_133 ( & V_2 -> V_741 ) ;
for ( V_666 = 0 ; V_666 < V_742 ; V_666 ++ ) {
if ( V_665 -> V_667 [ V_666 ] . V_655 &&
F_252 ( V_665 , V_666 ) -> V_744 ==
V_744 )
++ V_763 ;
}
F_131 ( & V_2 -> V_741 ) ;
return V_763 ;
}
static T_6 F_282 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
return V_665 -> V_728 * V_742 ;
}
static T_16 F_283 ( struct V_1 * V_2 ,
enum V_761 V_744 ,
T_6 * V_87 , T_6 V_764 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_648 * V_655 ;
unsigned int V_666 ;
T_16 V_763 = 0 ;
F_133 ( & V_2 -> V_741 ) ;
for ( V_666 = 0 ; V_666 < V_742 ; V_666 ++ ) {
V_655 = F_252 ( V_665 , V_666 ) ;
if ( V_655 && V_655 -> V_744 == V_744 ) {
if ( V_763 == V_764 ) {
V_763 = - V_765 ;
break;
}
V_87 [ V_763 ++ ] = ( F_261 ( V_665 , V_655 ) *
V_742 +
V_666 ) ;
}
}
F_131 ( & V_2 -> V_741 ) ;
return V_763 ;
}
static T_16 F_284 ( struct V_1 * V_2 ,
struct V_648 * V_655 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
F_8 ( V_73 , V_671 ) ;
struct V_648 * V_734 ;
unsigned int V_735 , V_111 , V_740 = 1 ;
bool V_670 = false ;
int V_737 = - 1 ;
T_8 V_533 ;
T_16 V_18 ;
F_285 ( V_655 -> V_251 !=
( V_652 | V_766 ) ) ;
F_285 ( V_655 -> V_744 != V_767 ) ;
F_285 ( F_264 ( V_655 ) ) ;
V_735 = F_246 ( V_655 ) ;
F_133 ( & V_2 -> V_741 ) ;
for (; ; ) {
V_111 = ( V_735 + V_740 ) & ( V_742 - 1 ) ;
V_734 = F_252 ( V_665 , V_111 ) ;
if ( ! V_734 ) {
if ( V_737 < 0 )
V_737 = V_111 ;
} else if ( F_244 ( V_655 , V_734 ) ) {
if ( V_665 -> V_667 [ V_111 ] . V_655 & V_743 ) {
V_18 = - V_216 ;
goto V_768;
}
if ( V_655 -> V_744 < V_734 -> V_744 ) {
V_18 = - V_65 ;
goto V_768;
}
V_737 = V_111 ;
break;
}
if ( V_740 == V_733 ) {
if ( V_737 < 0 ) {
V_18 = - V_216 ;
goto V_768;
}
break;
}
++ V_740 ;
}
V_734 = F_252 ( V_665 , V_737 ) ;
if ( V_734 ) {
V_670 = true ;
} else {
V_734 = F_269 ( sizeof( * V_655 ) , V_343 ) ;
if ( ! V_734 ) {
V_18 = - V_99 ;
goto V_768;
}
* V_734 = * V_655 ;
}
F_254 ( V_665 , V_737 , V_734 ,
V_743 ) ;
F_131 ( & V_2 -> V_741 ) ;
V_533 = V_670 << 31 | V_737 << 16 | V_655 -> V_711 ;
F_255 ( V_2 , V_655 , V_73 ,
V_665 -> V_667 [ V_737 ] . V_669 , V_670 ) ;
F_140 ( V_2 , V_724 , V_73 , sizeof( V_73 ) ,
V_723 ,
V_769 , V_533 ) ;
return V_737 ;
V_768:
F_131 ( & V_2 -> V_741 ) ;
return V_18 ;
}
static void
V_769 ( struct V_1 * V_2 , unsigned long V_533 ,
int V_18 , T_1 * V_13 ,
T_2 V_534 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
unsigned int V_737 , V_711 ;
struct V_648 * V_655 ;
bool V_670 ;
V_670 = V_533 >> 31 ;
V_737 = ( V_533 >> 16 ) & ( V_742 - 1 ) ;
V_711 = V_533 & 0xffff ;
F_133 ( & V_2 -> V_741 ) ;
V_655 = F_252 ( V_665 , V_737 ) ;
if ( V_18 == 0 ) {
V_665 -> V_667 [ V_737 ] . V_669 =
F_258 ( V_13 , V_725 ) ;
if ( V_670 )
V_655 -> V_711 = V_711 ;
} else if ( ! V_670 ) {
F_50 ( V_655 ) ;
V_655 = NULL ;
}
F_254 ( V_665 , V_737 , V_655 , 0 ) ;
F_131 ( & V_2 -> V_741 ) ;
F_271 ( & V_665 -> V_749 ) ;
}
static bool F_286 ( struct V_1 * V_2 , T_6 V_770 ,
unsigned int V_666 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_648 * V_655 =
F_252 ( V_665 , V_666 ) ;
F_8 ( V_73 ,
V_757 +
V_758 ) ;
if ( ! V_655 ||
( V_665 -> V_667 [ V_666 ] . V_655 & V_743 ) ||
V_655 -> V_744 != V_767 ||
! F_287 ( V_2 -> V_29 , V_655 -> V_711 ,
V_770 , V_666 ) )
return false ;
F_31 ( V_73 , V_675 ,
V_760 ) ;
F_134 ( V_73 , V_677 ,
V_665 -> V_667 [ V_666 ] . V_669 ) ;
if ( F_140 ( V_2 , V_724 , V_73 , sizeof( V_73 ) , 0 ,
V_771 , V_666 ) )
return false ;
V_665 -> V_667 [ V_666 ] . V_655 |= V_743 ;
return true ;
}
static void
V_771 ( struct V_1 * V_2 ,
unsigned long V_666 ,
int V_18 , T_1 * V_13 ,
T_2 V_534 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_648 * V_655 =
F_252 ( V_665 , V_666 ) ;
F_133 ( & V_2 -> V_741 ) ;
if ( V_18 == 0 ) {
F_50 ( V_655 ) ;
F_254 ( V_665 , V_666 , NULL , 0 ) ;
}
V_665 -> V_667 [ V_666 ] . V_655 &= ~ V_743 ;
F_271 ( & V_665 -> V_749 ) ;
F_131 ( & V_2 -> V_741 ) ;
}
static int F_288 ( T_6 V_726 )
{
int V_651 = 0 ;
#define F_289 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_289 ( V_772 , V_773 ) ;
F_289 ( V_772 , V_774 ) ;
F_289 ( V_684 , V_686 ) ;
F_289 ( V_687 , V_688 ) ;
F_289 ( V_689 , V_691 ) ;
F_289 ( V_692 , V_694 ) ;
F_289 ( V_695 , V_696 ) ;
F_289 ( V_697 , V_699 ) ;
F_289 ( V_700 , V_700 ) ;
F_289 ( V_701 , V_703 ) ;
F_289 ( V_704 , V_705 ) ;
F_289 ( V_706 , V_706 ) ;
#undef F_289
if ( V_726 )
return - V_262 ;
return V_651 ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_775 * V_94 , * V_109 ;
if ( ! F_291 ( & V_2 -> V_106 ) )
return;
if ( ! V_665 )
return;
F_55 (vlan, next_vlan, &table->vlan_list, list)
F_292 ( V_2 , V_94 ) ;
}
static bool F_293 ( struct V_664 * V_665 ,
enum V_776 V_651 )
{
unsigned int V_727 ;
int V_777 ;
for ( V_727 = 0 ;
V_727 < V_665 -> V_728 ;
V_727 ++ ) {
V_777 = F_288 (
V_665 -> V_729 [ V_727 ] ) ;
if ( V_777 == V_651 )
return true ;
}
return false ;
}
static int F_294 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_778 ) ;
F_8 ( V_13 , V_779 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_110 * V_29 = V_2 -> V_29 ;
unsigned int V_780 , V_781 ;
struct V_664 * V_665 ;
struct V_92 * V_94 ;
T_2 V_17 ;
int V_18 ;
if ( ! F_291 ( & V_2 -> V_106 ) )
return - V_262 ;
if ( V_2 -> V_104 )
return 0 ;
V_665 = F_43 ( sizeof( * V_665 ) , V_100 ) ;
if ( ! V_665 )
return - V_99 ;
F_31 ( V_73 , V_782 ,
V_783 ) ;
V_18 = F_9 ( V_2 , V_784 ,
V_73 , sizeof( V_73 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_171;
V_781 = F_295 (
V_17 , V_785 ) ;
V_665 -> V_728 = 0 ;
for ( V_780 = 0 ; V_780 < V_781 ; V_780 ++ ) {
T_6 V_726 =
F_296 (
V_13 ,
V_785 ,
V_780 ) ;
V_18 = F_288 ( V_726 ) ;
if ( V_18 < 0 ) {
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_58 ,
V_492 , V_726 , V_780 ) ;
} else {
F_20 ( V_2 , V_39 , V_2 -> V_29 ,
L_59 ,
V_492 , V_726 , V_780 ,
V_18 , V_665 -> V_728 ) ;
V_665 -> V_729 [ V_665 -> V_728 ] = V_726 ;
V_665 -> V_728 ++ ;
}
}
if ( ( F_297 ( V_2 ) & V_786 ) &&
! ( F_293 ( V_665 ,
( V_787 | V_656 ) ) &&
F_293 ( V_665 ,
( V_787 | V_681 ) ) ) ) {
F_90 ( V_2 , V_39 , V_29 ,
L_60 ) ;
V_29 -> V_788 &= ~ V_786 ;
V_2 -> V_789 &= ~ V_786 ;
V_29 -> V_790 &= ~ V_786 ;
}
V_665 -> V_667 = F_298 ( V_742 * sizeof( * V_665 -> V_667 ) ) ;
if ( ! V_665 -> V_667 ) {
V_18 = - V_99 ;
goto V_171;
}
V_665 -> V_791 = false ;
V_665 -> V_792 =
! ! ( V_2 -> V_29 -> V_788 & V_786 ) ;
F_70 ( & V_665 -> V_103 ) ;
V_2 -> V_104 = V_665 ;
F_299 ( & V_665 -> V_749 ) ;
F_39 (vlan, &nic_data->vlan_list, list) {
V_18 = F_46 ( V_2 , V_94 -> V_93 ) ;
if ( V_18 )
goto V_793;
}
return 0 ;
V_793:
F_290 ( V_2 ) ;
V_2 -> V_104 = NULL ;
V_171:
F_50 ( V_665 ) ;
return V_18 ;
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_648 * V_655 ;
unsigned int V_666 ;
bool V_794 = false ;
int V_18 ;
F_32 ( ! F_301 ( & V_2 -> V_106 ) ) ;
if ( ! V_16 -> V_244 )
return;
if ( ! V_665 )
return;
F_133 ( & V_2 -> V_741 ) ;
for ( V_666 = 0 ; V_666 < V_742 ; V_666 ++ ) {
V_655 = F_252 ( V_665 , V_666 ) ;
if ( ! V_655 )
continue;
V_665 -> V_667 [ V_666 ] . V_655 |= V_743 ;
F_131 ( & V_2 -> V_741 ) ;
V_18 = F_257 ( V_2 , V_655 ,
& V_665 -> V_667 [ V_666 ] . V_669 ,
false ) ;
if ( V_18 )
V_794 = true ;
F_133 ( & V_2 -> V_741 ) ;
if ( V_18 ) {
F_50 ( V_655 ) ;
F_254 ( V_665 , V_666 , NULL , 0 ) ;
} else {
V_665 -> V_667 [ V_666 ] . V_655 &=
~ V_743 ;
}
}
F_131 ( & V_2 -> V_741 ) ;
if ( V_794 )
F_14 ( V_2 , V_432 , V_2 -> V_29 ,
L_61 ) ;
else
V_16 -> V_244 = false ;
}
static void F_302 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
F_8 ( V_73 , V_671 ) ;
struct V_648 * V_655 ;
unsigned int V_666 ;
int V_18 ;
F_290 ( V_2 ) ;
V_2 -> V_104 = NULL ;
if ( ! F_291 ( & V_2 -> V_106 ) )
return;
if ( ! V_665 )
return;
for ( V_666 = 0 ; V_666 < V_742 ; V_666 ++ ) {
V_655 = F_252 ( V_665 , V_666 ) ;
if ( ! V_655 )
continue;
F_31 ( V_73 , V_675 ,
F_248 ( V_655 ) ?
V_760 :
V_753 ) ;
F_134 ( V_73 , V_677 ,
V_665 -> V_667 [ V_666 ] . V_669 ) ;
V_18 = F_25 ( V_2 , V_724 , V_73 ,
sizeof( V_73 ) , NULL , 0 , NULL ) ;
if ( V_18 )
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_62 ,
V_492 , V_666 ) ;
F_50 ( V_655 ) ;
}
F_303 ( V_665 -> V_667 ) ;
F_50 ( V_665 ) ;
}
static void F_304 ( struct V_1 * V_2 , T_17 * V_795 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
unsigned int V_666 ;
if ( * V_795 != V_762 ) {
V_666 = F_277 ( V_2 , * V_795 ) ;
if ( ! V_665 -> V_667 [ V_666 ] . V_655 )
F_20 ( V_2 , V_28 , V_2 -> V_29 ,
L_63 , * V_795 ,
V_666 ) ;
V_665 -> V_667 [ V_666 ] . V_655 |= V_752 ;
* V_795 = V_762 ;
}
}
static void F_305 ( struct V_1 * V_2 ,
struct V_775 * V_94 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_665 -> V_796 ; V_111 ++ )
F_304 ( V_2 , & V_94 -> V_797 [ V_111 ] ) ;
for ( V_111 = 0 ; V_111 < V_665 -> V_798 ; V_111 ++ )
F_304 ( V_2 , & V_94 -> V_799 [ V_111 ] ) ;
F_304 ( V_2 , & V_94 -> V_800 ) ;
F_304 ( V_2 , & V_94 -> V_801 ) ;
F_304 ( V_2 , & V_94 -> V_802 ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_775 * V_94 ;
F_133 ( & V_2 -> V_741 ) ;
F_39 (vlan, &table->vlan_list, list)
F_305 ( V_2 , V_94 ) ;
F_131 ( & V_2 -> V_741 ) ;
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_110 * V_29 = V_2 -> V_29 ;
struct V_803 * V_797 ;
int V_804 ;
unsigned int V_111 ;
V_804 = F_308 ( V_29 ) ;
V_665 -> V_805 = ! ! ( V_29 -> V_251 & V_806 ) ;
V_665 -> V_796 = 1 + V_804 ;
F_28 ( V_665 -> V_807 [ 0 ] . V_329 , V_29 -> V_808 ) ;
V_111 = 1 ;
F_309 (uc, net_dev) {
if ( V_111 >= V_809 ) {
V_665 -> V_805 = true ;
break;
}
F_28 ( V_665 -> V_807 [ V_111 ] . V_329 , V_797 -> V_329 ) ;
V_111 ++ ;
}
}
static void F_310 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_110 * V_29 = V_2 -> V_29 ;
struct V_803 * V_799 ;
unsigned int V_111 , V_804 ;
V_665 -> V_810 = ! ! ( V_29 -> V_251 & ( V_806 | V_811 ) ) ;
V_804 = F_311 ( V_29 ) ;
V_111 = 0 ;
F_312 (mc, net_dev) {
if ( V_111 >= V_812 ) {
V_665 -> V_810 = true ;
break;
}
F_28 ( V_665 -> V_813 [ V_111 ] . V_329 , V_799 -> V_329 ) ;
V_111 ++ ;
}
V_665 -> V_798 = V_111 ;
}
static int F_313 ( struct V_1 * V_2 ,
struct V_775 * V_94 ,
bool V_304 , bool V_814 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_815 * V_816 ;
enum V_817 V_818 ;
struct V_648 V_655 ;
T_3 V_819 [ V_820 ] ;
unsigned int V_111 , V_821 ;
int V_804 ;
T_5 * V_822 ;
int V_18 ;
if ( V_304 ) {
V_816 = V_665 -> V_813 ;
V_804 = V_665 -> V_798 ;
V_822 = V_94 -> V_799 ;
} else {
V_816 = V_665 -> V_807 ;
V_804 = V_665 -> V_796 ;
V_822 = V_94 -> V_797 ;
}
V_818 = F_275 ( V_2 ) ? V_672 : 0 ;
for ( V_111 = 0 ; V_111 < V_804 ; V_111 ++ ) {
F_314 ( & V_655 , V_745 , V_818 , 0 ) ;
F_315 ( & V_655 , V_94 -> V_93 , V_816 [ V_111 ] . V_329 ) ;
V_18 = F_262 ( V_2 , & V_655 , true ) ;
if ( V_18 < 0 ) {
if ( V_814 ) {
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_64 ,
V_18 ) ;
for ( V_821 = 0 ; V_821 < V_111 ; V_821 ++ ) {
F_278 (
V_2 , V_745 ,
V_822 [ V_821 ] ) ;
V_822 [ V_821 ] = V_762 ;
}
return V_18 ;
} else {
V_18 = V_762 ;
}
}
V_822 [ V_111 ] = F_277 ( V_2 , V_18 ) ;
}
if ( V_304 && V_814 ) {
F_314 ( & V_655 , V_745 , V_818 , 0 ) ;
F_316 ( V_819 ) ;
F_315 ( & V_655 , V_94 -> V_93 , V_819 ) ;
V_18 = F_262 ( V_2 , & V_655 , true ) ;
if ( V_18 < 0 ) {
F_42 ( V_2 , V_28 , V_2 -> V_29 ,
L_65 , V_18 ) ;
for ( V_821 = 0 ; V_821 < V_111 ; V_821 ++ ) {
F_278 (
V_2 , V_745 ,
V_822 [ V_821 ] ) ;
V_822 [ V_821 ] = V_762 ;
}
return V_18 ;
} else {
F_285 ( V_94 -> V_801 !=
V_762 ) ;
V_94 -> V_801 = F_277 ( V_2 , V_18 ) ;
}
}
return 0 ;
}
static int F_317 ( struct V_1 * V_2 ,
struct V_775 * V_94 ,
bool V_304 , bool V_814 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
enum V_817 V_818 ;
struct V_648 V_655 ;
T_3 V_819 [ V_820 ] ;
int V_18 ;
V_818 = F_275 ( V_2 ) ? V_672 : 0 ;
F_314 ( & V_655 , V_745 , V_818 , 0 ) ;
if ( V_304 )
F_318 ( & V_655 ) ;
else
F_319 ( & V_655 ) ;
if ( V_94 -> V_93 != V_141 )
F_315 ( & V_655 , V_94 -> V_93 , NULL ) ;
V_18 = F_262 ( V_2 , & V_655 , true ) ;
if ( V_18 < 0 ) {
F_320 ( V_2 , V_28 , V_18 == - V_65 ? V_823 : V_824 ,
V_2 -> V_29 ,
L_66 ,
V_304 ? L_67 : L_68 , V_18 ) ;
} else if ( V_304 ) {
F_285 ( V_94 -> V_802 != V_762 ) ;
V_94 -> V_802 = F_277 ( V_2 , V_18 ) ;
if ( ! V_16 -> V_567 ) {
F_314 ( & V_655 , V_745 ,
V_818 , 0 ) ;
F_316 ( V_819 ) ;
F_315 ( & V_655 , V_94 -> V_93 , V_819 ) ;
V_18 = F_262 ( V_2 , & V_655 , true ) ;
if ( V_18 < 0 ) {
F_42 ( V_2 , V_28 , V_2 -> V_29 ,
L_65 ,
V_18 ) ;
if ( V_814 ) {
F_278 (
V_2 , V_745 ,
V_94 -> V_802 ) ;
V_94 -> V_802 = V_762 ;
return V_18 ;
}
} else {
F_285 ( V_94 -> V_801 !=
V_762 ) ;
V_94 -> V_801 = F_277 ( V_2 , V_18 ) ;
}
}
V_18 = 0 ;
} else {
F_285 ( V_94 -> V_800 != V_762 ) ;
V_94 -> V_800 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_321 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
int V_825 = 0 ;
int V_826 = 0 ;
int V_18 ;
int V_111 ;
for ( V_111 = 0 ; V_111 < V_742 ; V_111 ++ ) {
if ( F_159 ( V_665 -> V_667 [ V_111 ] . V_655 ) &
V_752 ) {
V_18 = F_274 ( V_2 ,
1U << V_745 , V_111 , true ) ;
if ( V_18 == - V_108 )
V_826 ++ ;
else if ( V_18 )
V_825 ++ ;
}
}
if ( V_825 )
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_69 ,
V_492 , V_825 ) ;
if ( V_826 )
F_90 ( V_2 , V_28 , V_2 -> V_29 ,
L_70 ,
V_492 , V_826 ) ;
}
static int F_322 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_827 [ V_820 ] ;
int V_18 , V_828 ;
if ( F_323 ( V_16 -> V_829 ) )
return 0 ;
F_324 ( V_2 ) ;
F_325 ( V_2 -> V_29 ) ;
F_45 ( & V_2 -> V_106 ) ;
F_302 ( V_2 ) ;
F_47 ( & V_2 -> V_106 ) ;
V_18 = F_96 ( V_2 , V_16 -> V_121 ) ;
if ( V_18 )
goto V_830;
F_28 ( V_827 , V_16 -> V_829 ) ;
V_18 = F_98 ( V_2 , V_16 -> V_121 ,
V_16 -> V_829 ) ;
if ( V_18 )
goto V_831;
V_18 = F_97 ( V_2 , V_16 -> V_121 ,
V_2 -> V_29 -> V_808 ) ;
if ( ! V_18 ) {
F_28 ( V_16 -> V_829 , V_2 -> V_29 -> V_808 ) ;
} else {
V_828 = F_97 ( V_2 , V_16 -> V_121 , V_827 ) ;
if ( V_828 ) {
F_326 ( V_16 -> V_829 ) ;
goto V_832;
}
}
V_831:
V_828 = F_95 ( V_2 , V_16 -> V_121 ) ;
if ( V_828 )
goto V_832;
V_830:
F_45 ( & V_2 -> V_106 ) ;
V_828 = F_294 ( V_2 ) ;
F_47 ( & V_2 -> V_106 ) ;
if ( V_828 )
goto V_832;
V_828 = F_327 ( V_2 -> V_29 ) ;
if ( V_828 )
goto V_832;
F_328 ( V_2 -> V_29 ) ;
return V_18 ;
V_832:
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_71 ) ;
F_214 ( V_2 , V_250 ) ;
return V_18 ? V_18 : V_828 ;
}
static void F_329 ( struct V_1 * V_2 ,
struct V_775 * V_94 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ( V_94 -> V_93 == V_141 ) == V_665 -> V_792 )
return;
if ( V_665 -> V_805 ) {
F_317 ( V_2 , V_94 , false , false ) ;
F_313 ( V_2 , V_94 , false , false ) ;
} else {
if ( F_313 ( V_2 , V_94 , false , false ) )
F_317 ( V_2 , V_94 , false , false ) ;
}
if ( V_16 -> V_567 &&
V_665 -> V_791 != V_665 -> V_810 )
F_321 ( V_2 ) ;
if ( V_665 -> V_810 ) {
if ( V_16 -> V_567 ) {
if ( F_317 ( V_2 , V_94 , true , true ) ) {
F_321 ( V_2 ) ;
F_313 ( V_2 , V_94 ,
true , false ) ;
}
} else {
F_317 ( V_2 , V_94 , true , false ) ;
F_313 ( V_2 , V_94 , true , false ) ;
}
} else {
if ( F_313 ( V_2 , V_94 , true , true ) ) {
if ( V_16 -> V_567 )
F_321 ( V_2 ) ;
if ( F_317 ( V_2 , V_94 , true , true ) )
F_313 ( V_2 , V_94 ,
true , false ) ;
}
}
}
static void F_330 ( struct V_1 * V_2 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_110 * V_29 = V_2 -> V_29 ;
struct V_775 * V_94 ;
bool V_792 ;
if ( ! F_331 ( V_2 ) )
return;
if ( ! V_665 )
return;
F_306 ( V_2 ) ;
F_332 ( V_29 ) ;
F_307 ( V_2 ) ;
F_310 ( V_2 ) ;
F_333 ( V_29 ) ;
V_792 = ! ! ( V_29 -> V_788 & V_786 ) ;
if ( V_665 -> V_792 != V_792 ) {
V_665 -> V_792 = V_792 ;
F_321 ( V_2 ) ;
}
F_39 (vlan, &table->vlan_list, list)
F_329 ( V_2 , V_94 ) ;
F_321 ( V_2 ) ;
V_665 -> V_791 = V_665 -> V_810 ;
}
static struct V_775 * F_334 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_775 * V_94 ;
F_32 ( ! F_301 ( & V_2 -> V_106 ) ) ;
F_39 (vlan, &table->vlan_list, list) {
if ( V_94 -> V_93 == V_93 )
return V_94 ;
}
return NULL ;
}
static int F_46 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_664 * V_665 = V_2 -> V_104 ;
struct V_775 * V_94 ;
unsigned int V_111 ;
if ( ! F_291 ( & V_2 -> V_106 ) )
return - V_262 ;
V_94 = F_334 ( V_2 , V_93 ) ;
if ( F_32 ( V_94 ) ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_9 , V_93 ) ;
return - V_97 ;
}
V_94 = F_43 ( sizeof( * V_94 ) , V_100 ) ;
if ( ! V_94 )
return - V_99 ;
V_94 -> V_93 = V_93 ;
for ( V_111 = 0 ; V_111 < F_188 ( V_94 -> V_797 ) ; V_111 ++ )
V_94 -> V_797 [ V_111 ] = V_762 ;
for ( V_111 = 0 ; V_111 < F_188 ( V_94 -> V_799 ) ; V_111 ++ )
V_94 -> V_799 [ V_111 ] = V_762 ;
V_94 -> V_800 = V_762 ;
V_94 -> V_801 = V_762 ;
V_94 -> V_802 = V_762 ;
F_44 ( & V_94 -> V_102 , & V_665 -> V_103 ) ;
if ( F_331 ( V_2 ) )
F_329 ( V_2 , V_94 ) ;
return 0 ;
}
static void F_292 ( struct V_1 * V_2 ,
struct V_775 * V_94 )
{
unsigned int V_111 ;
if ( ! F_291 ( & V_2 -> V_106 ) )
return;
F_49 ( & V_94 -> V_102 ) ;
for ( V_111 = 0 ; V_111 < F_188 ( V_94 -> V_797 ) ; V_111 ++ )
F_278 ( V_2 , V_745 ,
V_94 -> V_797 [ V_111 ] ) ;
for ( V_111 = 0 ; V_111 < F_188 ( V_94 -> V_799 ) ; V_111 ++ )
F_278 ( V_2 , V_745 ,
V_94 -> V_799 [ V_111 ] ) ;
F_278 ( V_2 , V_745 , V_94 -> V_800 ) ;
F_278 ( V_2 , V_745 , V_94 -> V_801 ) ;
F_278 ( V_2 , V_745 , V_94 -> V_802 ) ;
F_50 ( V_94 ) ;
}
static void F_52 ( struct V_1 * V_2 , T_5 V_93 )
{
struct V_775 * V_94 ;
if ( ! F_291 ( & V_2 -> V_106 ) )
return;
V_94 = F_334 ( V_2 , V_93 ) ;
if ( ! V_94 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_72 , V_93 ) ;
return;
}
F_292 ( V_2 , V_94 ) ;
}
static int F_335 ( struct V_1 * V_2 )
{
F_8 ( V_73 , V_833 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_834 = V_2 -> V_835 ;
int V_18 ;
F_324 ( V_2 ) ;
F_325 ( V_2 -> V_29 ) ;
F_41 ( & V_2 -> V_105 ) ;
F_45 ( & V_2 -> V_106 ) ;
F_302 ( V_2 ) ;
F_28 ( F_29 ( V_73 , V_836 ) ,
V_2 -> V_29 -> V_808 ) ;
F_31 ( V_73 , V_837 ,
V_16 -> V_121 ) ;
V_18 = F_25 ( V_2 , V_838 , V_73 ,
sizeof( V_73 ) , NULL , 0 , NULL ) ;
F_294 ( V_2 ) ;
F_47 ( & V_2 -> V_106 ) ;
F_48 ( & V_2 -> V_105 ) ;
if ( V_834 )
F_327 ( V_2 -> V_29 ) ;
F_328 ( V_2 -> V_29 ) ;
#ifdef F_69
if ( V_2 -> V_10 -> V_187 && V_2 -> V_10 -> V_136 ) {
struct V_10 * V_138 = V_2 -> V_10 -> V_136 ;
if ( V_18 == - V_65 ) {
struct V_1 * V_139 ;
V_139 = F_34 ( V_138 ) ;
V_18 = F_336 ( V_139 ,
V_16 -> V_22 ,
V_2 -> V_29 -> V_808 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_139 = F_34 ( V_138 ) ;
struct V_15 * V_16 = V_139 -> V_16 ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_139 -> V_246 ; ++ V_111 ) {
struct V_185 * V_186 = V_16 -> V_186 + V_111 ;
if ( V_186 -> V_2 == V_2 ) {
F_28 ( V_186 -> V_207 ,
V_2 -> V_29 -> V_808 ) ;
return 0 ;
}
}
}
} else
#endif
if ( V_18 == - V_65 ) {
F_14 ( V_2 , V_28 , V_2 -> V_29 ,
L_73
L_74 ) ;
} else if ( V_18 == - V_49 && ! F_6 ( V_2 ) ) {
V_18 = F_322 ( V_2 ) ;
} else {
F_26 ( V_2 , V_838 ,
sizeof( V_73 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_337 ( struct V_1 * V_2 )
{
F_330 ( V_2 ) ;
return F_338 ( V_2 ) ;
}
static int F_339 ( struct V_1 * V_2 )
{
F_330 ( V_2 ) ;
return 0 ;
}
static int F_340 ( struct V_1 * V_2 , T_6 V_839 )
{
F_8 ( V_73 , V_840 ) ;
F_31 ( V_73 , V_841 , V_839 ) ;
return F_9 ( V_2 , V_842 , V_73 , sizeof( V_73 ) ,
NULL , 0 , NULL ) ;
}
static int F_341 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_843 ) ;
T_2 V_17 ;
T_6 V_844 ;
V_18 = F_9 ( V_2 , V_845 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_843 )
return - V_7 ;
V_844 = F_10 ( V_13 , V_846 ) ;
switch ( V_844 ) {
case V_847 :
F_20 ( V_2 , V_432 , V_2 -> V_29 , L_75 ) ;
return 0 ;
case V_848 :
F_14 ( V_2 , V_432 , V_2 -> V_29 , L_76 ) ;
return - V_7 ;
case V_849 :
F_14 ( V_2 , V_432 , V_2 -> V_29 , L_77 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_432 , V_2 -> V_29 ,
L_78 , V_844 ) ;
return - V_7 ;
}
}
static int F_342 ( struct V_1 * V_2 , T_6 V_839 )
{
int V_18 ;
F_20 ( V_2 , V_28 , V_2 -> V_29 , L_79 , V_839 ) ;
V_18 = F_340 ( V_2 , V_839 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_341 ( V_2 ) ;
}
static int
F_343 ( struct V_1 * V_2 , struct V_850 * V_851 )
{
int V_18 , V_828 ;
F_344 ( V_2 , V_261 ) ;
V_18 = F_9 ( V_2 , V_852 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_352;
V_851 -> V_853 = F_342 ( V_2 , V_854 ) ? - 1 : 1 ;
V_851 -> V_855 = F_342 ( V_2 , V_856 ) ? - 1 : 1 ;
V_18 = F_63 ( V_2 , V_261 ) ;
V_352:
if ( V_18 == - V_65 )
V_18 = 0 ;
V_828 = F_345 ( V_2 , V_261 , V_18 == 0 ) ;
return V_18 ? V_18 : V_828 ;
}
static int F_346 ( struct V_1 * V_2 ,
struct V_857 * V_858 ,
unsigned int type )
{
F_8 ( V_73 , V_859 ) ;
F_8 ( V_13 , V_860 ) ;
const struct V_861 * V_862 ;
T_2 V_764 , V_863 , V_17 ;
bool V_864 ;
int V_18 ;
for ( V_862 = V_865 ; ; V_862 ++ ) {
if ( V_862 ==
V_865 + F_188 ( V_865 ) )
return - V_40 ;
if ( ( type & ~ V_862 -> V_866 ) == V_862 -> type )
break;
}
if ( V_862 -> V_867 != F_347 ( V_2 ) )
return - V_40 ;
V_18 = F_348 ( V_2 , type , & V_764 , & V_863 , & V_864 ) ;
if ( V_18 )
return V_18 ;
if ( V_864 )
return - V_40 ;
V_858 -> V_868 = type ;
F_31 ( V_73 , V_869 , type ) ;
V_18 = F_9 ( V_2 , V_870 , V_73 , sizeof( V_73 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_871 )
return - V_7 ;
if ( F_10 ( V_13 , V_872 ) &
( 1 << V_873 ) )
V_858 -> V_874 = F_10 ( V_13 ,
V_875 ) ;
V_858 -> V_876 . V_877 = L_80 ;
V_858 -> V_876 . V_878 = V_862 -> V_285 ;
V_858 -> V_876 . V_879 . type = V_880 ;
V_858 -> V_876 . V_879 . V_251 = V_881 ;
V_858 -> V_876 . V_879 . V_764 = V_764 ;
V_858 -> V_876 . V_879 . V_882 = V_863 ;
return 0 ;
}
static int F_349 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_883 ) ;
struct V_857 * V_884 ;
T_2 V_17 , V_885 , V_111 , V_886 ;
unsigned int type ;
int V_18 ;
F_350 () ;
F_13 ( V_887 != 0 ) ;
V_18 = F_9 ( V_2 , V_888 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_889 )
return - V_7 ;
V_885 = F_10 ( V_13 , V_890 ) ;
if ( V_885 >
F_295 ( V_17 , V_891 ) )
return - V_7 ;
V_884 = F_351 ( V_885 , sizeof( * V_884 ) , V_100 ) ;
if ( ! V_884 )
return - V_99 ;
V_886 = 0 ;
for ( V_111 = 0 ; V_111 < V_885 ; V_111 ++ ) {
type = F_296 ( V_13 , V_891 ,
V_111 ) ;
V_18 = F_346 ( V_2 , & V_884 [ V_886 ] , type ) ;
if ( V_18 == 0 )
V_886 ++ ;
else if ( V_18 != - V_40 )
goto V_171;
}
V_18 = F_352 ( V_2 , & V_884 [ 0 ] . V_876 , V_886 , sizeof( * V_884 ) ) ;
V_171:
if ( V_18 )
F_50 ( V_884 ) ;
return V_18 ;
}
static void F_353 ( struct V_1 * V_2 , T_6 V_892 )
{
F_60 ( V_2 , F_61 ( V_892 ) , V_384 ) ;
}
static void F_354 ( struct V_1 * V_2 ,
T_6 V_892 ) {}
static int F_355 ( struct V_159 * V_160 ,
bool V_893 )
{
F_8 ( V_73 , V_894 ) ;
int V_18 ;
if ( V_160 -> V_895 == V_896 ||
V_160 -> V_895 == V_897 ||
( V_893 && V_160 -> V_895 == V_898 ) )
return 0 ;
V_160 -> V_895 = V_896 ;
F_31 ( V_73 , V_899 , V_900 ) ;
F_31 ( V_73 , V_901 , 0 ) ;
F_31 ( V_73 , V_902 ,
V_160 -> V_160 ) ;
V_18 = F_9 ( V_160 -> V_2 , V_903 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_160 -> V_895 = V_893 ? V_904 :
V_898 ;
return V_18 ;
}
static int F_356 ( struct V_159 * V_160 ,
bool V_893 )
{
F_8 ( V_73 , V_905 ) ;
int V_18 ;
if ( V_160 -> V_895 == V_898 ||
( V_893 && V_160 -> V_895 == V_904 ) )
return 0 ;
if ( V_160 -> V_895 == V_904 ) {
V_160 -> V_895 = V_898 ;
return 0 ;
}
V_160 -> V_895 = V_893 ? V_904 :
V_898 ;
F_31 ( V_73 , V_899 , V_906 ) ;
F_31 ( V_73 , V_901 , 0 ) ;
F_31 ( V_73 , V_907 ,
V_908 ) ;
F_31 ( V_73 , V_909 ,
V_160 -> V_160 ) ;
V_18 = F_9 ( V_160 -> V_2 , V_903 ,
V_73 , sizeof( V_73 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_357 ( struct V_1 * V_2 , bool V_910 ,
bool V_893 )
{
int (* F_358)( struct V_159 * V_160 , bool V_893 );
struct V_159 * V_160 ;
F_358 = V_910 ?
F_355 :
F_356 ;
F_85 (channel, efx) {
int V_18 = F_358 ( V_160 , V_893 ) ;
if ( V_910 && V_18 != 0 ) {
F_357 ( V_2 , false , V_893 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_359 ( struct V_1 * V_2 ,
struct V_911 * V_912 )
{
return - V_375 ;
}
static int F_360 ( struct V_1 * V_2 ,
struct V_911 * V_912 )
{
int V_18 ;
switch ( V_912 -> V_913 ) {
case V_914 :
F_357 ( V_2 , false , false ) ;
return F_361 ( V_2 ,
V_912 -> V_915 != V_916 , 0 ) ;
case V_917 :
case V_918 :
case V_919 :
case V_920 :
case V_921 :
case V_922 :
case V_923 :
case V_924 :
case V_925 :
case V_926 :
case V_927 :
case V_928 :
case V_929 :
V_912 -> V_913 = V_917 ;
V_18 = F_361 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_357 ( V_2 , true , false ) ;
if ( V_18 )
F_361 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_44 ;
}
}
static int F_362 ( struct V_1 * V_2 , T_18 V_930 , T_5 V_93 )
{
if ( V_930 != F_250 ( V_931 ) )
return - V_262 ;
return F_40 ( V_2 , V_93 ) ;
}
static int F_363 ( struct V_1 * V_2 , T_18 V_930 , T_5 V_93 )
{
if ( V_930 != F_250 ( V_931 ) )
return - V_262 ;
return F_53 ( V_2 , V_93 ) ;
}
