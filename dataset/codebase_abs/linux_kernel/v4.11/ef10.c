static T_1 F_1 ( T_1 V_1 )
{
F_2 ( V_1 == V_2 ) ;
return V_1 & ( V_3 - 1 ) ;
}
static unsigned int F_3 ( T_1 V_1 )
{
return V_1 / ( V_3 * 2 ) ;
}
static T_1 F_4 ( unsigned int V_4 , T_2 V_5 )
{
return V_4 * V_3 * 2 + V_5 ;
}
static int F_5 ( struct V_6 * V_7 )
{
T_3 V_8 ;
F_6 ( V_7 , & V_8 , V_9 ) ;
return F_7 ( V_8 , V_10 ) == 0xb007 ?
F_7 ( V_8 , V_11 ) : - V_12 ;
}
static unsigned int F_8 ( struct V_6 * V_7 )
{
int V_13 ;
V_13 = V_7 -> type -> V_14 ;
return F_9 ( & V_7 -> V_15 -> V_16 [ V_13 ] ) ;
}
static bool F_10 ( struct V_6 * V_7 )
{
return V_7 -> type -> V_17 ;
}
static int F_11 ( struct V_6 * V_7 )
{
F_12 ( V_18 , V_19 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_4 V_22 ;
int V_23 ;
V_23 = F_13 ( V_7 , V_24 , NULL , 0 , V_18 ,
sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < sizeof( V_18 ) )
return - V_12 ;
V_21 -> V_25 = F_14 ( V_18 , V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
F_12 ( V_18 , V_19 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_4 V_22 ;
int V_23 ;
V_23 = F_13 ( V_7 , V_24 , NULL , 0 , V_18 ,
sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < sizeof( V_18 ) )
return - V_12 ;
V_21 -> V_27 = F_14 ( V_18 , V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
F_12 ( V_18 , V_29 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_4 V_22 ;
int V_23 ;
F_17 ( V_30 != 0 ) ;
V_23 = F_13 ( V_7 , V_31 , NULL , 0 ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < V_32 ) {
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_1 ) ;
return - V_12 ;
}
V_21 -> V_35 =
F_14 ( V_18 , V_36 ) ;
if ( V_22 >= V_29 ) {
V_21 -> V_37 = F_14 ( V_18 ,
V_38 ) ;
V_21 -> V_39 = F_19 ( V_18 ,
V_40 ) ;
} else {
V_21 -> V_37 = 0 ;
V_21 -> V_39 = V_41 ;
}
V_21 -> V_42 =
F_19 ( V_18 , V_43 ) ;
V_21 -> V_44 =
F_19 ( V_18 , V_45 ) ;
if ( ! ( V_21 -> V_35 &
( 1 << V_46 ) ) ) {
F_18 ( V_7 , V_47 , V_7 -> V_34 ,
L_2 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
F_12 ( V_18 , V_49 ) ;
int V_23 ;
V_23 = F_13 ( V_7 , V_50 , NULL , 0 ,
V_18 , sizeof( V_18 ) , NULL ) ;
if ( V_23 )
return V_23 ;
V_23 = F_14 ( V_18 , V_51 ) ;
return V_23 > 0 ? V_23 : - V_52 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
unsigned int V_53 ;
unsigned int V_54 ;
int V_23 ;
V_21 -> V_55 = false ;
V_21 -> V_56 = false ;
V_23 = F_22 ( V_7 , & V_53 , & V_54 ) ;
if ( V_23 == - V_57 ) {
V_23 = 0 ;
} else if ( V_23 == 0 ) {
if ( V_54 & V_58 )
V_21 -> V_56 = true ;
if ( V_54 & V_59 ) {
V_21 -> V_55 = true ;
} else if ( V_53 & V_59 ) {
V_23 = F_23 ( V_7 ,
V_60 ,
true , NULL ) ;
if ( V_23 == 0 )
V_21 -> V_55 = true ;
V_23 = 0 ;
}
}
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_3 ,
V_21 -> V_55 ? L_4 : L_5 ) ;
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_6 ,
V_21 -> V_56 ? L_4 : L_5 ) ;
return V_23 ;
}
static void F_25 ( struct V_6 * V_7 ,
const T_3 * V_61 )
{
unsigned int V_62 ;
if ( F_26 ( V_7 ) ) {
V_7 -> V_63 = F_14 ( V_61 ,
V_64 ) ;
V_7 -> V_65 = F_14 ( V_61 ,
V_66 ) ;
} else if ( F_27 ( V_7 ) ) {
V_7 -> V_63 = F_14 ( V_61 ,
V_67 ) ;
V_62 = F_14 ( V_61 ,
V_68 ) ;
V_7 -> V_65 = V_62 * V_7 -> V_63 ;
} else {
V_7 -> V_63 = F_14 ( V_61 ,
V_69 ) ;
V_62 = F_14 ( V_61 ,
V_70 ) ;
V_7 -> V_65 = V_62 * V_7 -> V_63 ;
}
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_7 ,
V_7 -> V_63 , V_7 -> V_65 ) ;
}
static int F_28 ( struct V_6 * V_7 )
{
F_12 ( V_18 , V_71 ) ;
int V_23 ;
V_23 = F_21 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_29 ( V_7 , V_72 , NULL , 0 ,
V_18 , sizeof( V_18 ) , NULL ) ;
if ( V_23 == 0 ) {
F_25 ( V_7 , V_18 ) ;
} else if ( V_23 == - V_57 || V_23 == - V_73 ) {
unsigned int V_74 ;
V_23 = F_20 ( V_7 ) ;
if ( V_23 < 0 )
return V_23 ;
V_74 = 1536000 / V_23 ;
V_7 -> V_63 = V_74 ;
V_7 -> V_65 = V_7 -> type -> V_75 * V_74 ;
V_23 = 0 ;
} else {
F_30 ( V_7 , V_72 ,
V_71 ,
NULL , 0 , V_23 ) ;
}
return V_23 ;
}
static int F_31 ( struct V_6 * V_7 , T_5 * V_76 )
{
F_12 ( V_18 , V_77 ) ;
T_4 V_22 ;
int V_23 ;
F_17 ( V_78 != 0 ) ;
V_23 = F_13 ( V_7 , V_79 , NULL , 0 ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < V_77 )
return - V_12 ;
F_32 ( V_76 ,
F_33 ( V_18 , V_80 ) ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 , T_5 * V_76 )
{
F_12 ( V_81 , V_82 ) ;
F_12 ( V_18 , V_83 ) ;
T_4 V_22 ;
int V_84 , V_23 ;
F_35 ( V_81 , V_85 ,
V_86 ) ;
V_23 = F_13 ( V_7 , V_87 , V_81 ,
sizeof( V_81 ) , V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < V_88 )
return - V_12 ;
V_84 = F_14 ( V_18 ,
V_89 ) ;
F_36 ( V_84 != 1 ) ;
F_32 ( V_76 ,
F_33 ( V_18 , V_90 ) ) ;
return 0 ;
}
static T_6 F_37 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_6 * V_7 = F_38 ( F_39 ( V_92 ) ) ;
return sprintf ( V_95 , L_8 ,
( ( V_7 -> V_96 -> V_97 ) &
( 1 << V_98 ) )
? 1 : 0 ) ;
}
static T_6 F_40 ( struct V_91 * V_92 ,
struct V_93 * V_94 ,
char * V_95 )
{
struct V_6 * V_7 = F_38 ( F_39 ( V_92 ) ) ;
return sprintf ( V_95 , L_8 ,
( ( V_7 -> V_96 -> V_97 ) &
( 1 << V_99 ) )
? 1 : 0 ) ;
}
static struct V_100 * F_41 ( struct V_6 * V_7 , T_2 V_101 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_100 * V_102 ;
F_36 ( ! F_42 ( & V_21 -> V_103 ) ) ;
F_43 (vlan, &nic_data->vlan_list, list) {
if ( V_102 -> V_101 == V_101 )
return V_102 ;
}
return NULL ;
}
static int F_44 ( struct V_6 * V_7 , T_2 V_101 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_100 * V_102 ;
int V_23 ;
F_45 ( & V_21 -> V_103 ) ;
V_102 = F_41 ( V_7 , V_101 ) ;
if ( V_102 ) {
if ( V_101 == 0 )
goto V_104;
F_46 ( V_7 , V_33 , V_7 -> V_34 ,
L_9 , V_101 ) ;
V_23 = - V_105 ;
goto V_106;
}
V_23 = - V_107 ;
V_102 = F_47 ( sizeof( * V_102 ) , V_108 ) ;
if ( ! V_102 )
goto V_109;
V_102 -> V_101 = V_101 ;
F_48 ( & V_102 -> V_110 , & V_21 -> V_111 ) ;
if ( V_7 -> V_112 ) {
F_45 ( & V_7 -> V_113 ) ;
F_49 ( & V_7 -> V_114 ) ;
V_23 = F_50 ( V_7 , V_102 -> V_101 ) ;
F_51 ( & V_7 -> V_114 ) ;
F_52 ( & V_7 -> V_113 ) ;
if ( V_23 )
goto V_115;
}
V_104:
F_52 ( & V_21 -> V_103 ) ;
return 0 ;
V_115:
F_53 ( & V_102 -> V_110 ) ;
F_54 ( V_102 ) ;
V_109:
V_106:
F_52 ( & V_21 -> V_103 ) ;
return V_23 ;
}
static void F_55 ( struct V_6 * V_7 ,
struct V_100 * V_102 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_36 ( ! F_42 ( & V_21 -> V_103 ) ) ;
if ( V_7 -> V_112 ) {
F_49 ( & V_7 -> V_114 ) ;
F_56 ( V_7 , V_102 -> V_101 ) ;
F_51 ( & V_7 -> V_114 ) ;
}
F_53 ( & V_102 -> V_110 ) ;
F_54 ( V_102 ) ;
}
static int F_57 ( struct V_6 * V_7 , T_2 V_101 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_100 * V_102 ;
int V_23 = 0 ;
if ( V_101 == 0 )
return 0 ;
F_45 ( & V_21 -> V_103 ) ;
V_102 = F_41 ( V_7 , V_101 ) ;
if ( ! V_102 ) {
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_10 , V_101 ) ;
V_23 = - V_116 ;
} else {
F_55 ( V_7 , V_102 ) ;
}
F_52 ( & V_21 -> V_103 ) ;
return V_23 ;
}
static void F_58 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_100 * V_102 , * V_117 ;
F_45 ( & V_21 -> V_103 ) ;
F_59 (vlan, next_vlan, &nic_data->vlan_list, list)
F_55 ( V_7 , V_102 ) ;
F_52 ( & V_21 -> V_103 ) ;
}
static int F_60 ( struct V_6 * V_7 )
{
struct V_20 * V_21 ;
int V_118 , V_23 ;
V_7 -> V_119 = F_61 (unsigned int,
EFX_MAX_CHANNELS,
efx_ef10_mem_map_size(efx) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
V_7 -> V_120 = V_7 -> V_119 ;
if ( F_36 ( V_7 -> V_119 == 0 ) )
return - V_12 ;
V_21 = F_47 ( sizeof( * V_21 ) , V_108 ) ;
if ( ! V_21 )
return - V_107 ;
V_7 -> V_21 = V_21 ;
F_17 ( V_121 % 4 ) ;
V_23 = F_62 ( V_7 , & V_21 -> V_122 ,
8 + V_121 , V_108 ) ;
if ( V_23 )
goto V_123;
V_118 = 0 ;
for (; ; ) {
V_23 = F_5 ( V_7 ) ;
if ( V_23 >= 0 )
break;
if ( ++ V_118 == 5 )
goto V_124;
F_63 ( 1 ) ;
}
V_21 -> V_125 = V_23 ;
V_21 -> V_126 = V_127 ;
V_21 -> V_128 = V_86 ;
F_64 ( V_7 , F_65 ( 1 ) , V_129 ) ;
V_23 = F_66 ( V_7 ) ;
if ( V_23 )
goto V_124;
F_67 ( & V_21 -> V_130 ) ;
V_23 = F_68 ( V_7 , V_131 ) ;
if ( V_23 )
goto V_132;
V_23 = F_69 ( V_7 , true , false , 0 ) ;
if ( V_23 )
goto V_132;
V_23 = F_70 ( & V_7 -> V_15 -> V_92 ,
& V_133 ) ;
if ( V_23 )
goto V_132;
V_23 = F_70 ( & V_7 -> V_15 -> V_92 , & V_134 ) ;
if ( V_23 )
goto V_135;
V_23 = F_11 ( V_7 ) ;
if ( V_23 )
goto V_136;
V_23 = F_16 ( V_7 ) ;
if ( V_23 < 0 )
goto V_136;
V_7 -> V_137 =
V_138 - V_139 ;
V_23 = F_71 ( V_7 ) ;
if ( V_23 < 0 )
goto V_136;
V_7 -> V_140 = V_23 ;
V_23 = V_7 -> type -> V_141 ( V_7 , V_7 -> V_34 -> V_142 ) ;
if ( V_23 )
goto V_136;
V_23 = F_28 ( V_7 ) ;
if ( V_23 < 0 )
goto V_136;
V_23 = F_72 ( V_7 ) ;
if ( V_23 && V_23 != - V_73 )
goto V_136;
F_73 ( V_7 , NULL ) ;
#ifdef F_74
if ( ( V_7 -> V_15 -> V_143 ) && ( ! V_7 -> V_15 -> V_144 ) ) {
struct V_15 * V_145 = V_7 -> V_15 -> V_143 ;
struct V_6 * V_146 = F_38 ( V_145 ) ;
V_146 -> type -> V_141 ( V_146 , V_21 -> V_147 ) ;
} else
#endif
F_32 ( V_21 -> V_147 , V_7 -> V_34 -> V_142 ) ;
F_75 ( & V_21 -> V_111 ) ;
F_67 ( & V_21 -> V_103 ) ;
V_23 = F_44 ( V_7 , V_148 ) ;
if ( V_23 )
goto V_149;
V_23 = F_44 ( V_7 , 0 ) ;
if ( V_23 )
goto V_150;
return 0 ;
V_150:
F_58 ( V_7 ) ;
V_149:
F_76 ( & V_21 -> V_103 ) ;
F_77 ( V_7 ) ;
F_78 ( V_7 ) ;
V_136:
F_79 ( & V_7 -> V_15 -> V_92 , & V_134 ) ;
V_135:
F_79 ( & V_7 -> V_15 -> V_92 , & V_133 ) ;
V_132:
F_80 ( V_7 ) ;
F_45 ( & V_21 -> V_130 ) ;
memset ( V_21 -> V_151 , 0 , sizeof( V_21 -> V_151 ) ) ;
( void ) F_81 ( V_7 , true ) ;
F_52 ( & V_21 -> V_130 ) ;
F_76 ( & V_21 -> V_130 ) ;
F_82 ( V_7 ) ;
V_124:
F_83 ( V_7 , & V_21 -> V_122 ) ;
V_123:
F_54 ( V_21 ) ;
V_7 -> V_21 = NULL ;
return V_23 ;
}
static int F_84 ( struct V_6 * V_7 )
{
F_85 ( V_18 ) ;
T_4 V_22 ;
int V_23 = F_29 ( V_7 , V_152 , NULL , 0 ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 == - V_105 )
V_23 = 0 ;
if ( V_23 )
F_30 ( V_7 , V_152 , 0 , V_18 , V_22 ,
V_23 ) ;
return V_23 ;
}
static void F_86 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_12 ( V_81 , V_153 ) ;
unsigned int V_118 ;
int V_23 ;
F_17 ( V_154 != 0 ) ;
for ( V_118 = 0 ; V_118 < V_21 -> V_155 ; V_118 ++ ) {
F_35 ( V_81 , V_156 ,
V_21 -> V_157 [ V_118 ] ) ;
V_23 = F_13 ( V_7 , V_158 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
F_36 ( V_23 ) ;
}
V_21 -> V_155 = 0 ;
}
static int F_87 ( struct V_6 * V_7 , unsigned int V_159 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_12 ( V_18 , V_160 ) ;
unsigned int V_118 ;
T_4 V_22 ;
int V_23 = 0 ;
F_17 ( V_161 != 0 ) ;
for ( V_118 = 0 ; V_118 < V_159 ; V_118 ++ ) {
V_23 = F_29 ( V_7 , V_162 , NULL , 0 ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 ) {
if ( ! ( F_10 ( V_7 ) && V_23 == - V_163 ) )
F_30 ( V_7 , V_162 ,
0 , V_18 , V_22 , V_23 ) ;
break;
}
if ( V_22 < V_160 ) {
V_23 = - V_12 ;
break;
}
V_21 -> V_157 [ V_118 ] =
F_14 ( V_18 , V_164 ) ;
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_11 , V_118 ,
V_21 -> V_157 [ V_118 ] ) ;
}
V_21 -> V_155 = V_118 ;
if ( V_23 )
F_86 ( V_7 ) ;
return V_23 ;
}
static int F_88 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_12 ( V_81 , V_165 ) ;
struct V_166 * V_167 ;
struct V_168 * V_169 ;
unsigned int V_170 , V_171 ;
int V_23 ;
F_17 ( V_172 != 0 ) ;
F_17 ( V_173 != 0 ) ;
for ( V_171 = 0 ; V_171 < V_21 -> V_155 ; ++ V_171 ) {
F_35 ( V_81 , V_174 ,
V_21 -> V_157 [ V_171 ] ) ;
F_35 ( V_81 , V_175 ,
V_21 -> V_176 + V_171 ) ;
V_23 = F_13 ( V_7 , V_177 ,
V_81 , V_165 ,
NULL , 0 , NULL ) ;
if ( V_23 ) {
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_12 ,
V_21 -> V_176 + V_171 , V_171 ,
V_23 ) ;
goto V_178;
}
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_13 ,
V_21 -> V_176 + V_171 , V_171 ) ;
}
F_89 (channel, efx) {
F_90 (tx_queue, channel) {
V_170 = ( ( V_7 -> V_179 + V_7 -> V_180 -
V_169 -> V_167 -> V_167 - 1 ) *
V_181 ) ;
V_171 = V_170 / V_21 -> V_39 ;
V_170 = V_170 % V_21 -> V_39 ;
if ( V_169 -> V_182 == V_21 -> V_176 ) {
F_91 ( V_171 != 0 ) ;
V_23 = 0 ;
} else {
F_35 ( V_81 ,
V_174 ,
V_21 -> V_157 [ V_171 ] ) ;
F_35 ( V_81 ,
V_175 ,
V_169 -> V_182 ) ;
V_23 = F_13 ( V_7 , V_177 ,
V_81 , V_165 ,
NULL , 0 , NULL ) ;
}
if ( V_23 ) {
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_12 ,
V_169 -> V_182 , V_171 , V_23 ) ;
V_169 -> V_183 = NULL ;
} else {
V_169 -> V_183 =
V_21 -> V_184 +
V_171 * V_185 + V_170 ;
V_169 -> V_186 = V_170 ;
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_14 ,
V_169 -> V_182 , V_171 ,
V_169 -> V_186 ,
V_169 -> V_183 ) ;
}
}
}
return 0 ;
V_178:
F_17 ( V_165 < V_187 ) ;
while ( V_171 -- ) {
F_35 ( V_81 , V_188 ,
V_21 -> V_176 + V_171 ) ;
F_13 ( V_7 , V_189 ,
V_81 , V_187 ,
NULL , 0 , NULL ) ;
}
return V_23 ;
}
static void F_92 ( struct V_6 * V_7 )
{
struct V_166 * V_167 ;
struct V_168 * V_169 ;
F_89 (channel, efx)
F_90 (tx_queue, channel)
V_169 -> V_183 = NULL ;
}
static int F_87 ( struct V_6 * V_7 , unsigned int V_159 )
{
return V_159 == 0 ? 0 : - V_190 ;
}
static int F_88 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_86 ( struct V_6 * V_7 )
{
}
static void F_92 ( struct V_6 * V_7 )
{
}
static void F_93 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
int V_23 ;
#ifdef F_74
struct V_20 * V_191 ;
struct V_15 * V_145 ;
struct V_6 * V_146 ;
struct V_192 * V_193 ;
if ( V_7 -> V_15 -> V_194 ) {
V_145 = V_7 -> V_15 -> V_143 ;
if ( V_145 ) {
V_146 = F_38 ( V_145 ) ;
V_191 = V_146 -> V_21 ;
V_193 = V_191 -> V_193 + V_21 -> V_27 ;
V_193 -> V_7 = NULL ;
} else
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_15 ) ;
}
#endif
F_58 ( V_7 ) ;
F_76 ( & V_21 -> V_103 ) ;
F_77 ( V_7 ) ;
F_78 ( V_7 ) ;
F_95 ( V_7 ) ;
if ( V_21 -> V_195 )
F_96 ( V_21 -> V_195 ) ;
V_23 = F_84 ( V_7 ) ;
F_36 ( V_23 != 0 ) ;
if ( ! V_21 -> V_196 )
F_86 ( V_7 ) ;
F_79 ( & V_7 -> V_15 -> V_92 , & V_134 ) ;
F_79 ( & V_7 -> V_15 -> V_92 , & V_133 ) ;
F_80 ( V_7 ) ;
memset ( V_21 -> V_151 , 0 , sizeof( V_21 -> V_151 ) ) ;
F_45 ( & V_21 -> V_130 ) ;
( void ) F_81 ( V_7 , true ) ;
F_52 ( & V_21 -> V_130 ) ;
F_76 ( & V_21 -> V_130 ) ;
F_82 ( V_7 ) ;
F_83 ( V_7 , & V_21 -> V_122 ) ;
F_54 ( V_21 ) ;
}
static int F_97 ( struct V_6 * V_7 )
{
return F_60 ( V_7 ) ;
}
int F_98 ( struct V_6 * V_7 , unsigned int V_147 ,
T_1 * V_197 , T_1 * V_198 ,
unsigned int * V_199 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_12 ( V_81 , V_200 ) ;
F_12 ( V_18 , V_201 ) ;
T_4 V_22 ;
int V_23 ;
if ( V_21 -> V_35 &
( 1 << V_202 ) ) {
F_35 ( V_81 , V_203 ,
V_147 ) ;
V_23 = F_13 ( V_7 , V_204 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < sizeof( V_18 ) ) {
V_23 = - V_12 ;
return V_23 ;
}
}
if ( V_197 )
* V_197 = F_14 ( V_18 , V_205 ) ;
if ( V_198 )
* V_198 =
F_14 ( V_18 , V_206 ) ;
if ( V_199 )
* V_199 =
F_14 ( V_18 ,
V_207 ) ;
return 0 ;
}
int F_99 ( struct V_6 * V_7 , unsigned int V_147 )
{
F_12 ( V_81 , V_208 ) ;
F_35 ( V_81 , V_209 , V_147 ) ;
return F_13 ( V_7 , V_210 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
}
int F_100 ( struct V_6 * V_7 , unsigned int V_147 )
{
F_12 ( V_81 , V_211 ) ;
F_35 ( V_81 , V_212 , V_147 ) ;
return F_13 ( V_7 , V_213 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
}
int F_101 ( struct V_6 * V_7 ,
unsigned int V_147 , T_5 * V_214 )
{
F_12 ( V_81 , V_215 ) ;
F_35 ( V_81 , V_216 , V_147 ) ;
F_32 ( F_33 ( V_81 , V_217 ) , V_214 ) ;
return F_13 ( V_7 , V_218 , V_81 ,
sizeof( V_81 ) , NULL , 0 , NULL ) ;
}
int F_102 ( struct V_6 * V_7 ,
unsigned int V_147 , T_5 * V_214 )
{
F_12 ( V_81 , V_219 ) ;
F_35 ( V_81 , V_220 , V_147 ) ;
F_32 ( F_33 ( V_81 , V_221 ) , V_214 ) ;
return F_13 ( V_7 , V_222 , V_81 ,
sizeof( V_81 ) , NULL , 0 , NULL ) ;
}
static int F_103 ( struct V_6 * V_7 )
{
int V_23 ;
struct V_15 * V_145 ;
V_145 = V_7 -> V_15 -> V_143 ;
if ( V_145 ) {
struct V_6 * V_146 = F_38 ( V_145 ) ;
struct V_20 * V_191 = V_146 -> V_21 ;
if ( ! V_191 -> V_193 ) {
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_16
L_17 ) ;
return - V_223 ;
}
}
V_23 = F_60 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_15 ( V_7 ) ;
if ( V_23 )
goto V_178;
if ( V_7 -> V_15 -> V_194 ) {
if ( V_7 -> V_15 -> V_143 ) {
struct V_6 * V_146 =
F_38 ( V_7 -> V_15 -> V_143 ) ;
struct V_20 * V_224 = V_146 -> V_21 ;
struct V_20 * V_21 = V_7 -> V_21 ;
V_224 -> V_193 [ V_21 -> V_27 ] . V_7 = V_7 ;
V_224 -> V_193 [ V_21 -> V_27 ] . V_15 =
V_7 -> V_15 ;
} else
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_15 ) ;
}
return 0 ;
V_178:
F_93 ( V_7 ) ;
return V_23 ;
}
static int F_104 ( struct V_6 * V_7 ,
unsigned int V_225 , unsigned int V_226 )
{
F_12 ( V_81 , V_227 ) ;
F_12 ( V_18 , V_228 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_4 V_22 ;
int V_23 ;
F_35 ( V_81 , V_229 , V_225 ) ;
F_35 ( V_81 , V_230 , V_226 ) ;
V_23 = F_13 ( V_7 , V_231 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( V_22 < V_228 )
return - V_12 ;
F_24 ( V_7 , V_33 , V_7 -> V_34 , L_18 ,
F_14 ( V_18 , V_232 ) ) ;
V_21 -> V_233 = F_14 ( V_18 , V_232 ) ;
V_21 -> V_234 = F_14 ( V_18 , V_235 ) ;
return 0 ;
}
static int F_105 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
unsigned int V_236 , V_237 ;
unsigned int V_225 = F_106 ( V_238 ,
V_239 ? 2 : 1 ) ;
unsigned int V_240 , V_176 , V_226 ;
void T_7 * V_241 ;
int V_23 ;
V_240 = F_106 ( V_7 -> V_242 , V_7 -> V_180 * V_238 ) ;
#ifdef F_107
if ( V_181 != 0 &&
V_21 -> V_39 / V_181 * V_243 >=
V_7 -> V_180 ) {
unsigned int V_155 =
F_108 ( V_7 -> V_180 ,
V_21 -> V_39 / V_181 ) ;
V_23 = F_87 ( V_7 , V_155 ) ;
if ( V_23 == - V_163 )
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_19 ) ;
else if ( V_23 == - V_73 )
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_20 ) ;
else if ( V_23 )
F_18 ( V_7 , V_47 , V_7 -> V_34 ,
L_21 , V_23 ) ;
else
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_22 , V_155 ) ;
}
#else
V_21 -> V_155 = 0 ;
#endif
V_236 = F_109 ( ( V_240 - 1 ) * V_185 +
V_244 ) ;
if ( V_21 -> V_155 ) {
V_176 = V_236 / V_185 ;
V_237 = ( F_109 ( ( V_176 +
V_21 -> V_155 ) *
V_185 ) -
V_236 ) ;
V_226 = V_176 + V_21 -> V_155 ;
} else {
V_176 = 0 ;
V_237 = 0 ;
V_226 = V_240 ;
}
V_23 = F_84 ( V_7 ) ;
if ( V_23 != 0 )
return V_23 ;
V_23 = F_104 ( V_7 , V_225 , V_226 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( V_21 -> V_234 < V_240 ) {
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_23
L_24 ) ;
V_7 -> V_119 = V_21 -> V_234 ;
V_7 -> V_120 =
V_21 -> V_234 / V_238 ;
F_84 ( V_7 ) ;
return - V_245 ;
}
if ( V_21 -> V_155 &&
V_21 -> V_234 <
V_176 + V_21 -> V_155 ) {
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_25 ,
V_21 -> V_234 , V_21 -> V_155 ) ;
F_86 ( V_7 ) ;
}
V_241 = F_110 ( V_7 -> V_246 , V_236 ) ;
if ( ! V_241 ) {
F_18 ( V_7 , V_47 , V_7 -> V_34 ,
L_26 ,
V_236 ) ;
return - V_107 ;
}
F_96 ( V_7 -> V_241 ) ;
V_7 -> V_241 = V_241 ;
if ( V_237 ) {
V_21 -> V_195 = F_111 ( V_7 -> V_246 +
V_236 ,
V_237 ) ;
if ( ! V_21 -> V_195 ) {
F_18 ( V_7 , V_47 , V_7 -> V_34 ,
L_27 ,
V_237 ) ;
return - V_107 ;
}
V_21 -> V_176 = V_176 ;
V_21 -> V_184 =
V_21 -> V_195 +
( V_176 * V_185 + V_244 -
V_236 ) ;
V_23 = F_88 ( V_7 ) ;
if ( V_23 )
F_86 ( V_7 ) ;
}
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_28 ,
& V_7 -> V_246 , V_7 -> V_241 , V_236 ,
V_21 -> V_195 , V_237 ) ;
return 0 ;
}
static int F_112 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
int V_23 ;
if ( V_21 -> V_247 ) {
V_23 = F_16 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_21 -> V_247 = false ;
}
if ( V_21 -> V_248 ) {
V_23 = F_104 ( V_7 , V_21 -> V_234 ,
V_21 -> V_234 ) ;
if ( V_23 )
return V_23 ;
V_21 -> V_248 = false ;
}
if ( V_21 -> V_196 && V_21 -> V_155 ) {
V_23 = F_87 ( V_7 , V_21 -> V_155 ) ;
if ( V_23 == 0 ) {
V_23 = F_88 ( V_7 ) ;
if ( V_23 )
F_86 ( V_7 ) ;
}
if ( V_23 == - V_73 )
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_29 ) ;
else if ( V_23 )
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_30 , V_23 ) ;
V_21 -> V_196 = false ;
}
V_23 = V_7 -> type -> V_249 ( V_7 , false , V_7 -> V_250 , NULL ) ;
V_7 -> V_251 = ( V_23 == 0 ) ;
return 0 ;
}
static void F_113 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
#ifdef F_74
unsigned int V_118 ;
#endif
V_21 -> V_248 = true ;
V_21 -> V_252 = true ;
V_21 -> V_196 = true ;
F_92 ( V_7 ) ;
V_21 -> V_126 = V_127 ;
V_21 -> V_253 = true ;
V_21 -> V_128 = V_86 ;
#ifdef F_74
if ( V_21 -> V_193 )
for ( V_118 = 0 ; V_118 < V_7 -> V_254 ; V_118 ++ )
V_21 -> V_193 [ V_118 ] . V_128 = 0 ;
#endif
}
static enum V_255 F_114 ( enum V_255 V_256 )
{
if ( V_256 == V_257 )
return V_258 ;
return F_115 ( V_256 ) ;
}
static int F_116 ( T_1 * V_259 )
{
enum {
V_260 = ( ( V_261 | V_262 ) <<
V_263 ) ,
V_264 = ( ( V_265 | V_266 |
V_267 | V_261 |
V_262 | V_268 ) <<
V_263 )
};
if ( ( * V_259 & V_264 ) == V_264 ) {
* V_259 &= ~ V_264 ;
return V_269 ;
}
if ( ( * V_259 & V_260 ) == V_260 ) {
* V_259 &= ~ V_260 ;
return V_131 ;
}
return - V_270 ;
}
static int F_117 ( struct V_6 * V_7 , enum V_255 V_255 )
{
int V_23 = F_68 ( V_7 , V_255 ) ;
if ( V_255 == V_269 && V_23 == - V_73 )
V_23 = 0 ;
if ( ( V_255 == V_131 ||
V_255 == V_271 ) && ! V_23 )
F_113 ( V_7 ) ;
return V_23 ;
}
static T_8 F_118 ( struct V_6 * V_7 )
{
T_8 V_272 = V_273 ;
T_1 V_274 = F_119 ( V_7 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
if ( ! ( V_7 -> V_96 -> V_97 &
1 << V_98 ) )
return 0 ;
if ( V_274 & ( 1 << V_275 ) ) {
V_272 |= V_276 ;
if ( V_21 -> V_37 &
( 1 << V_277 ) )
V_272 |= V_278 ;
} else {
V_272 |= V_278 ;
}
if ( V_21 -> V_35 &
( 1 << V_279 ) )
V_272 |= V_280 ;
return V_272 ;
}
static void F_120 ( struct V_6 * V_7 , unsigned long * V_281 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
T_8 V_272 [ 2 ] ;
V_272 [ 0 ] = F_118 ( V_7 ) ;
if ( V_21 -> V_35 &
( 1 << V_282 ) ) {
V_272 [ 0 ] |= ~ ( ( 1ULL << V_283 ) - 1 ) ;
V_272 [ 1 ] = ( 1ULL << ( V_284 - 63 ) ) - 1 ;
} else {
V_272 [ 1 ] = 0 ;
}
#if V_285 == 64
F_17 ( F_121 ( V_284 ) != 2 ) ;
V_281 [ 0 ] = V_272 [ 0 ] ;
V_281 [ 1 ] = V_272 [ 1 ] ;
#else
F_17 ( F_121 ( V_284 ) != 3 ) ;
V_281 [ 0 ] = V_272 [ 0 ] & 0xffffffff ;
V_281 [ 1 ] = V_272 [ 0 ] >> 32 ;
V_281 [ 2 ] = V_272 [ 1 ] & 0xffffffff ;
#endif
}
static T_4 F_122 ( struct V_6 * V_7 , T_5 * V_286 )
{
F_123 ( V_281 , V_284 ) ;
F_120 ( V_7 , V_281 ) ;
return F_124 ( V_287 , V_284 ,
V_281 , V_286 ) ;
}
static T_4 F_125 ( struct V_6 * V_7 , T_8 * V_288 ,
struct V_289 * V_290 )
{
F_123 ( V_281 , V_284 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_8 * V_291 = V_21 -> V_291 ;
T_4 V_292 = 0 , V_171 ;
F_120 ( V_7 , V_281 ) ;
if ( V_288 ) {
F_126 (index, mask, EF10_STAT_COUNT) {
if ( V_287 [ V_171 ] . V_293 ) {
* V_288 ++ = V_291 [ V_171 ] ;
++ V_292 ;
}
}
}
if ( ! V_290 )
return V_292 ;
if ( V_21 -> V_35 &
1 << V_282 ) {
V_290 -> V_294 = V_291 [ V_283 ] +
V_291 [ V_295 ] +
V_291 [ V_296 ] ;
V_290 -> V_297 = V_291 [ V_298 ] +
V_291 [ V_299 ] +
V_291 [ V_300 ] ;
V_290 -> V_301 = V_291 [ V_302 ] +
V_291 [ V_303 ] +
V_291 [ V_304 ] ;
V_290 -> V_305 = V_291 [ V_306 ] +
V_291 [ V_307 ] +
V_291 [ V_308 ] ;
V_290 -> V_309 = V_291 [ V_310 ] +
V_291 [ V_311 ] ;
V_290 -> V_312 = V_291 [ V_295 ] ;
V_290 -> V_313 = V_291 [ V_314 ] ;
V_290 -> V_315 = V_291 [ V_316 ] ;
V_290 -> V_317 = V_290 -> V_313 ;
V_290 -> V_318 = V_291 [ V_319 ] ;
} else {
V_290 -> V_294 = V_291 [ V_320 ] ;
V_290 -> V_297 = V_291 [ V_321 ] ;
V_290 -> V_301 = V_291 [ V_322 ] ;
V_290 -> V_305 = V_291 [ V_323 ] ;
V_290 -> V_309 = V_291 [ V_324 ] +
V_291 [ V_310 ] +
V_291 [ V_311 ] ;
V_290 -> V_312 = V_291 [ V_325 ] ;
V_290 -> V_326 =
V_291 [ V_327 ] +
V_291 [ V_328 ] ;
V_290 -> V_313 = V_291 [ V_329 ] ;
V_290 -> V_330 =
V_291 [ V_331 ] ;
V_290 -> V_315 = V_291 [ V_332 ] ;
V_290 -> V_317 = ( V_290 -> V_326 +
V_290 -> V_313 +
V_290 -> V_330 ) ;
}
return V_292 ;
}
static int F_127 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_123 ( V_281 , V_284 ) ;
T_9 V_333 , V_334 ;
T_8 * V_291 = V_21 -> V_291 ;
T_9 * V_335 ;
F_120 ( V_7 , V_281 ) ;
V_335 = V_7 -> V_336 . V_337 ;
V_334 = V_335 [ V_338 ] ;
if ( V_334 == V_339 )
return 0 ;
F_128 () ;
F_129 ( V_287 , V_284 , V_281 ,
V_291 , V_7 -> V_336 . V_337 , false ) ;
F_128 () ;
V_333 = V_335 [ V_340 ] ;
if ( V_334 != V_333 )
return - V_245 ;
F_130 ( V_7 ,
& V_291 [ V_324 ] ) ;
V_291 [ V_341 ] =
V_291 [ V_322 ] -
V_291 [ V_342 ] ;
F_131 ( & V_291 [ V_343 ] ,
V_291 [ V_342 ] ) ;
F_132 ( V_7 , V_291 ) ;
return 0 ;
}
static T_4 F_133 ( struct V_6 * V_7 , T_8 * V_288 ,
struct V_289 * V_290 )
{
int V_344 ;
for ( V_344 = 0 ; V_344 < 100 ; ++ V_344 ) {
if ( F_127 ( V_7 ) == 0 )
break;
F_134 ( 100 ) ;
}
return F_125 ( V_7 , V_288 , V_290 ) ;
}
static int F_135 ( struct V_6 * V_7 )
{
F_12 ( V_81 , V_345 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
F_123 ( V_281 , V_284 ) ;
T_9 V_333 , V_334 ;
T_8 * V_291 = V_21 -> V_291 ;
T_1 V_346 = V_347 * sizeof( T_8 ) ;
struct V_348 V_349 ;
T_9 * V_335 ;
int V_23 ;
F_136 ( & V_7 -> V_350 ) ;
if ( F_137 () ) {
F_138 ( & V_7 -> V_350 ) ;
F_132 ( V_7 , V_291 ) ;
return 0 ;
}
F_120 ( V_7 , V_281 ) ;
V_23 = F_62 ( V_7 , & V_349 , V_346 , V_351 ) ;
if ( V_23 ) {
F_138 ( & V_7 -> V_350 ) ;
return V_23 ;
}
V_335 = V_349 . V_337 ;
V_335 [ V_338 ] = V_339 ;
F_139 ( V_81 , V_352 , V_349 . V_353 ) ;
F_140 ( V_81 , V_354 ,
V_355 , 1 ) ;
F_35 ( V_81 , V_356 , V_346 ) ;
F_35 ( V_81 , V_357 , V_86 ) ;
V_23 = F_29 ( V_7 , V_358 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
F_138 ( & V_7 -> V_350 ) ;
if ( V_23 ) {
if ( V_23 != - V_116 || F_141 ( & V_7 -> V_359 ) )
F_30 ( V_7 , V_358 ,
sizeof( V_81 ) , NULL , 0 , V_23 ) ;
goto V_360;
}
V_334 = V_335 [ V_338 ] ;
if ( V_334 == V_339 ) {
F_2 ( 1 ) ;
goto V_360;
}
F_128 () ;
F_129 ( V_287 , V_284 , V_281 ,
V_291 , V_349 . V_337 , false ) ;
F_128 () ;
V_333 = V_335 [ V_340 ] ;
if ( V_334 != V_333 ) {
V_23 = - V_245 ;
goto V_360;
}
F_132 ( V_7 , V_291 ) ;
V_360:
F_83 ( V_7 , & V_349 ) ;
return V_23 ;
}
static T_4 F_142 ( struct V_6 * V_7 , T_8 * V_288 ,
struct V_289 * V_290 )
{
if ( F_135 ( V_7 ) )
return 0 ;
return F_125 ( V_7 , V_288 , V_290 ) ;
}
static void F_143 ( struct V_166 * V_167 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
unsigned int V_361 , V_362 ;
T_3 V_363 ;
if ( V_167 -> V_364 ) {
V_361 = 3 ;
V_362 = V_167 -> V_364 ;
} else {
V_361 = 0 ;
V_362 = 0 ;
}
if ( F_26 ( V_7 ) ) {
F_12 ( V_81 , V_365 ) ;
unsigned int V_366 = V_362 * 1000 ;
F_35 ( V_81 , V_367 ,
V_167 -> V_167 ) ;
F_35 ( V_81 , V_368 , V_366 ) ;
F_35 ( V_81 , V_369 , V_366 ) ;
F_35 ( V_81 , V_370 , V_361 ) ;
F_144 ( V_7 , V_371 ,
V_81 , sizeof( V_81 ) , 0 , NULL , 0 ) ;
} else if ( F_27 ( V_7 ) ) {
unsigned int V_372 = F_145 ( V_7 , V_362 ) ;
F_146 ( V_363 , V_373 ,
V_374 ,
V_375 , V_361 ,
V_376 , V_372 ) ;
F_147 ( V_7 , & V_363 , V_377 ,
V_167 -> V_167 ) ;
} else {
unsigned int V_372 = F_145 ( V_7 , V_362 ) ;
F_148 ( V_363 , V_378 , V_361 ,
V_379 , V_372 ) ;
F_147 ( V_7 , & V_363 , V_380 ,
V_167 -> V_167 ) ;
}
}
static void F_149 ( struct V_6 * V_7 ,
struct V_381 * V_382 ) {}
static int F_150 ( struct V_6 * V_7 , T_1 type )
{
return - V_383 ;
}
static void F_151 ( struct V_6 * V_7 , struct V_381 * V_382 )
{
V_382 -> V_384 = 0 ;
V_382 -> V_385 = 0 ;
memset ( & V_382 -> V_386 , 0 , sizeof( V_382 -> V_386 ) ) ;
}
static int F_152 ( struct V_6 * V_7 , T_1 type )
{
if ( type != 0 )
return - V_270 ;
return 0 ;
}
static void F_153 ( struct V_6 * V_7 ,
const T_3 * V_387 , T_4 V_388 ,
const T_3 * V_389 , T_4 V_390 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
T_5 * V_391 = V_21 -> V_122 . V_337 ;
memcpy ( V_391 , V_387 , V_388 ) ;
memcpy ( V_391 + V_388 , V_389 , V_390 ) ;
F_154 () ;
F_64 ( V_7 , F_65 ( ( T_8 ) V_21 -> V_122 . V_353 >> 32 ) ,
V_392 ) ;
F_64 ( V_7 , F_65 ( ( T_1 ) V_21 -> V_122 . V_353 ) ,
V_129 ) ;
}
static bool F_155 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
const T_3 V_387 = * ( const T_3 * ) V_21 -> V_122 . V_337 ;
F_128 () ;
return F_7 ( V_387 , V_393 ) ;
}
static void
F_156 ( struct V_6 * V_7 , T_3 * V_18 ,
T_4 V_170 , T_4 V_22 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
const T_5 * V_391 = V_21 -> V_122 . V_337 ;
memcpy ( V_18 , V_391 + V_170 , V_22 ) ;
}
static void F_157 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_113 ( V_7 ) ;
V_21 -> V_247 = true ;
V_21 -> V_291 [ V_343 ] = 0 ;
}
static int F_158 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
int V_23 ;
V_23 = F_5 ( V_7 ) ;
if ( V_23 < 0 ) {
return 0 ;
}
if ( V_23 == V_21 -> V_125 )
return 0 ;
V_21 -> V_125 = V_23 ;
F_157 ( V_7 ) ;
return - V_12 ;
}
static T_10 F_159 ( int V_394 , void * V_395 )
{
struct V_396 * V_397 = V_395 ;
struct V_6 * V_7 = V_397 -> V_7 ;
F_160 ( V_7 , V_398 , V_7 -> V_34 ,
L_31 , V_394 , F_161 () ) ;
if ( F_162 ( F_163 ( V_7 -> V_399 ) ) ) {
if ( V_397 -> V_171 == V_7 -> V_400 )
V_7 -> V_401 = F_161 () ;
F_164 ( V_7 -> V_167 [ V_397 -> V_171 ] ) ;
}
return V_402 ;
}
static T_10 F_165 ( int V_394 , void * V_395 )
{
struct V_6 * V_7 = V_395 ;
bool V_403 = F_163 ( V_7 -> V_399 ) ;
struct V_166 * V_167 ;
T_3 V_8 ;
T_1 V_404 ;
F_6 ( V_7 , & V_8 , V_405 ) ;
V_404 = F_7 ( V_8 , V_406 ) ;
if ( V_404 == 0 )
return V_407 ;
if ( F_162 ( V_403 ) ) {
if ( V_404 & ( 1U << V_7 -> V_400 ) )
V_7 -> V_401 = F_161 () ;
F_89 (channel, efx) {
if ( V_404 & 1 )
F_164 ( V_167 ) ;
V_404 >>= 1 ;
}
}
F_160 ( V_7 , V_398 , V_7 -> V_34 ,
L_32 V_408 L_33 ,
V_394 , F_161 () , F_166 ( V_8 ) ) ;
return V_402 ;
}
static int F_167 ( struct V_6 * V_7 )
{
F_12 ( V_81 , V_409 ) ;
if ( F_23 ( V_7 , V_410 , true ,
NULL ) == 0 )
return - V_411 ;
F_17 ( V_412 != 0 ) ;
F_35 ( V_81 , V_413 , V_7 -> V_400 ) ;
return F_13 ( V_7 , V_414 ,
V_81 , sizeof( V_81 ) , NULL , 0 , NULL ) ;
}
static int F_168 ( struct V_168 * V_169 )
{
return F_62 ( V_169 -> V_7 , & V_169 -> V_415 . V_95 ,
( V_169 -> V_416 + 1 ) *
sizeof( V_417 ) ,
V_108 ) ;
}
static inline void F_169 ( struct V_168 * V_169 ,
const V_417 * V_415 )
{
unsigned int V_418 ;
T_11 V_8 ;
V_418 = V_169 -> V_419 & V_169 -> V_416 ;
F_170 ( V_8 , V_420 , V_418 ) ;
V_8 . V_421 [ 0 ] = * V_415 ;
F_171 ( V_169 -> V_7 , & V_8 ,
V_422 , V_169 -> V_182 ) ;
}
static int F_172 ( struct V_168 * V_169 ,
struct V_423 * V_424 ,
bool * V_425 )
{
struct V_426 * V_427 ;
struct V_428 * V_429 ;
struct V_430 * V_431 ;
T_2 V_432 ;
T_1 V_433 ;
T_1 V_434 ;
F_173 ( V_169 -> V_435 != 2 ) ;
V_434 = F_174 ( V_424 ) -> V_436 ;
if ( F_175 ( V_434 < 4 ) ) {
F_176 ( 1 , L_34 , V_434 ) ;
return - V_270 ;
}
V_431 = F_177 ( V_424 ) ;
if ( V_431 -> V_437 == 4 ) {
V_431 -> V_438 = 0 ;
V_431 -> V_439 = 0 ;
V_432 = F_178 ( V_431 -> V_440 ) ;
} else {
struct V_441 * V_442 = F_179 ( V_424 ) ;
V_442 -> V_443 = 0 ;
V_432 = 0 ;
}
V_429 = F_180 ( V_424 ) ;
V_433 = F_181 ( V_429 -> V_444 ) ;
V_427 = F_182 ( V_169 ) ;
V_427 -> V_259 = V_445 ;
V_427 -> V_446 = 0 ;
V_427 -> V_447 = 0 ;
F_183 ( V_427 -> V_448 ,
V_449 , 1 ,
V_450 , V_451 ,
V_452 ,
V_453 ,
V_454 , V_432 ,
V_455 , V_433
) ;
++ V_169 -> V_456 ;
V_427 = F_182 ( V_169 ) ;
V_427 -> V_259 = V_445 ;
V_427 -> V_446 = 0 ;
V_427 -> V_447 = 0 ;
F_184 ( V_427 -> V_448 ,
V_449 , 1 ,
V_450 , V_451 ,
V_452 ,
V_457 ,
V_458 , V_434
) ;
++ V_169 -> V_456 ;
return 0 ;
}
static T_1 F_185 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
T_1 V_459 = 0 ;
if ( V_21 -> V_35 &
( 1 << V_460 ) )
V_459 |= F_186 ( 1 ) ;
if ( V_21 -> V_37 &
( 1 << V_461 ) )
V_459 |= F_186 ( 2 ) ;
return V_459 ;
}
static void F_187 ( struct V_168 * V_169 )
{
F_12 ( V_81 , F_188 ( V_462 * 8 /
V_463 ) ) ;
bool V_464 = V_169 -> V_182 & V_465 ;
T_4 V_466 = V_169 -> V_415 . V_95 . V_446 / V_463 ;
struct V_166 * V_167 = V_169 -> V_167 ;
struct V_6 * V_7 = V_169 -> V_7 ;
struct V_20 * V_21 = V_7 -> V_21 ;
bool V_467 = false ;
T_4 V_468 ;
T_12 V_353 ;
V_417 * V_415 ;
int V_23 ;
int V_118 ;
F_17 ( V_469 != 0 ) ;
if ( V_464 && ( V_21 -> V_37 &
( 1 << V_461 ) ) ) {
V_467 = true ;
F_24 ( V_7 , V_470 , V_7 -> V_34 , L_35 ,
V_167 -> V_167 ) ;
}
F_35 ( V_81 , V_471 , V_169 -> V_416 + 1 ) ;
F_35 ( V_81 , V_472 , V_167 -> V_167 ) ;
F_35 ( V_81 , V_473 , V_169 -> V_182 ) ;
F_35 ( V_81 , V_474 , V_169 -> V_182 ) ;
F_35 ( V_81 , V_475 , 0 ) ;
F_35 ( V_81 , V_476 , V_21 -> V_128 ) ;
V_353 = V_169 -> V_415 . V_95 . V_353 ;
F_24 ( V_7 , V_470 , V_7 -> V_34 , L_36 ,
V_169 -> V_182 , V_466 , ( T_8 ) V_353 ) ;
for ( V_118 = 0 ; V_118 < V_466 ; ++ V_118 ) {
F_189 ( V_81 , V_477 , V_118 , V_353 ) ;
V_353 += V_463 ;
}
V_468 = F_188 ( V_466 ) ;
do {
F_190 ( V_81 , V_478 ,
V_479 , V_467 ,
V_480 , ! V_464 ,
V_481 , ! V_464 ) ;
V_23 = F_29 ( V_7 , V_482 , V_81 , V_468 ,
NULL , 0 , NULL ) ;
if ( V_23 == - V_163 && V_467 ) {
V_467 = false ;
F_46 ( V_7 , V_47 , V_7 -> V_34 ,
L_37 ) ;
} else if ( V_23 ) {
F_30 ( V_7 , V_482 ,
V_483 ,
NULL , 0 , V_23 ) ;
goto V_178;
}
} while ( V_23 );
V_169 -> V_427 [ 0 ] . V_259 = V_445 ;
V_169 -> V_456 = 1 ;
V_415 = F_191 ( V_169 , 0 ) ;
F_184 ( * V_415 ,
V_449 , true ,
V_450 ,
V_484 ,
V_485 , V_464 ,
V_486 , V_464 ) ;
V_169 -> V_419 = 1 ;
if ( V_467 ) {
V_169 -> V_487 = F_172 ;
V_169 -> V_435 = 2 ;
} else if ( V_21 -> V_35 &
( 1 << V_460 ) ) {
V_169 -> V_435 = 1 ;
}
F_154 () ;
F_169 ( V_169 , V_415 ) ;
return;
V_178:
F_192 ( V_7 -> V_34 , L_38 ,
V_169 -> V_182 ) ;
}
static void F_193 ( struct V_168 * V_169 )
{
F_12 ( V_81 , V_488 ) ;
F_85 ( V_18 ) ;
struct V_6 * V_7 = V_169 -> V_7 ;
T_4 V_22 ;
int V_23 ;
F_35 ( V_81 , V_489 ,
V_169 -> V_182 ) ;
V_23 = F_29 ( V_7 , V_490 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 && V_23 != - V_105 )
goto V_178;
return;
V_178:
F_30 ( V_7 , V_490 , V_488 ,
V_18 , V_22 , V_23 ) ;
}
static void F_194 ( struct V_168 * V_169 )
{
F_83 ( V_169 -> V_7 , & V_169 -> V_415 . V_95 ) ;
}
static inline void F_195 ( struct V_168 * V_169 )
{
unsigned int V_418 ;
T_3 V_8 ;
V_418 = V_169 -> V_419 & V_169 -> V_416 ;
F_196 ( V_8 , V_491 , V_418 ) ;
F_147 ( V_169 -> V_7 , & V_8 ,
V_492 , V_169 -> V_182 ) ;
}
static unsigned int F_197 ( struct V_168 * V_169 ,
T_12 V_353 , unsigned int V_446 )
{
if ( V_446 > V_493 ) {
T_12 V_494 = V_353 + V_493 ;
F_17 ( V_493 < V_495 ) ;
V_446 = ( V_494 & ( ~ ( V_495 - 1 ) ) ) - V_353 ;
}
return V_446 ;
}
static void F_198 ( struct V_168 * V_169 )
{
unsigned int V_496 = V_169 -> V_419 ;
struct V_426 * V_427 ;
unsigned int V_418 ;
V_417 * V_415 ;
V_169 -> V_497 = false ;
if ( F_175 ( V_169 -> V_419 == V_169 -> V_456 ) )
return;
do {
V_418 = V_169 -> V_419 & V_169 -> V_416 ;
V_427 = & V_169 -> V_427 [ V_418 ] ;
V_415 = F_191 ( V_169 , V_418 ) ;
++ V_169 -> V_419 ;
if ( V_427 -> V_259 & V_445 ) {
* V_415 = V_427 -> V_448 ;
if ( F_199 ( * V_415 , V_450 ) == 1 )
V_169 -> V_498 = V_169 -> V_419 ;
} else {
V_169 -> V_498 = V_169 -> V_419 ;
F_17 ( V_499 != 1 ) ;
F_200 (
* V_415 ,
V_500 ,
V_427 -> V_259 & V_499 ,
V_501 , V_427 -> V_446 ,
V_502 , V_427 -> V_353 ) ;
}
} while ( V_169 -> V_419 != V_169 -> V_456 );
F_154 () ;
if ( F_201 ( V_169 , V_496 ) ) {
V_415 = F_191 ( V_169 ,
V_496 & V_169 -> V_416 ) ;
F_169 ( V_169 , V_415 ) ;
++ V_169 -> V_503 ;
} else {
F_195 ( V_169 ) ;
}
}
static int F_202 ( struct V_6 * V_7 , T_1 V_397 , T_1 * V_259 )
{
F_12 ( V_81 , V_504 ) ;
F_12 ( V_18 , V_504 ) ;
T_4 V_22 ;
int V_23 ;
F_17 ( V_505 != V_506 ) ;
F_35 ( V_81 , V_507 , V_397 ) ;
F_35 ( V_81 , V_508 ,
V_509 ) ;
V_23 = F_13 ( V_7 , V_510 , V_81 ,
sizeof( V_81 ) , V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 == 0 ) {
if ( V_22 < V_504 )
V_23 = - V_12 ;
else
* V_259 = F_14 ( V_18 , V_508 ) ;
}
return V_23 ;
}
static void F_203 ( struct V_6 * V_7 , T_1 V_397 )
{
F_12 ( V_81 , V_511 ) ;
T_1 V_259 ;
F_17 ( V_512 != 0 ) ;
if ( F_202 ( V_7 , V_397 , & V_259 ) != 0 )
return;
F_35 ( V_81 , V_513 , V_397 ) ;
V_259 |= V_514 << V_515 ;
V_259 |= V_514 << V_516 ;
F_35 ( V_81 , V_517 , V_259 ) ;
if ( ! F_13 ( V_7 , V_518 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) )
V_7 -> V_519 = true ;
}
static int F_204 ( struct V_6 * V_7 , T_1 * V_397 ,
bool V_520 , unsigned * V_521 )
{
F_12 ( V_81 , V_522 ) ;
F_12 ( V_18 , V_523 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_4 V_22 ;
int V_23 ;
T_1 V_524 = V_520 ?
V_525 :
V_526 ;
unsigned V_527 = V_520 ?
V_7 -> V_527 :
F_205 ( F_206 ( V_7 -> V_527 ) ,
V_528 ) ;
if ( ! V_520 && V_527 == 1 ) {
* V_397 = V_127 ;
if ( V_521 )
* V_521 = 1 ;
return 0 ;
}
if ( V_21 -> V_35 &
1 << V_529 )
return - V_383 ;
F_35 ( V_81 , V_530 ,
V_21 -> V_128 ) ;
F_35 ( V_81 , V_531 , V_524 ) ;
F_35 ( V_81 , V_532 , V_527 ) ;
V_23 = F_13 ( V_7 , V_533 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( V_22 < V_523 )
return - V_12 ;
* V_397 = F_14 ( V_18 , V_534 ) ;
if ( V_521 )
* V_521 = V_527 ;
if ( V_21 -> V_35 &
1 << V_535 )
F_203 ( V_7 , * V_397 ) ;
return 0 ;
}
static void F_207 ( struct V_6 * V_7 , T_1 V_397 )
{
F_12 ( V_81 , V_536 ) ;
int V_23 ;
F_35 ( V_81 , V_537 ,
V_397 ) ;
V_23 = F_13 ( V_7 , V_538 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
F_36 ( V_23 != 0 ) ;
}
static int F_208 ( struct V_6 * V_7 , T_1 V_397 ,
const T_1 * V_250 , const T_5 * V_539 )
{
F_12 ( V_540 , V_541 ) ;
F_12 ( V_542 , V_543 ) ;
int V_118 , V_23 ;
F_35 ( V_540 , V_544 ,
V_397 ) ;
F_17 ( F_209 ( V_7 -> V_250 ) !=
V_545 ) ;
for ( V_118 = 0 ; V_118 < F_209 ( V_7 -> V_250 ) ; ++ V_118 )
F_33 ( V_540 ,
V_546 ) [ V_118 ] =
( T_5 ) V_250 [ V_118 ] ;
V_23 = F_13 ( V_7 , V_547 , V_540 ,
sizeof( V_540 ) , NULL , 0 , NULL ) ;
if ( V_23 != 0 )
return V_23 ;
F_35 ( V_542 , V_548 ,
V_397 ) ;
F_17 ( F_209 ( V_7 -> V_549 ) !=
V_550 ) ;
for ( V_118 = 0 ; V_118 < F_209 ( V_7 -> V_549 ) ; ++ V_118 )
F_33 ( V_542 , V_551 ) [ V_118 ] = V_539 [ V_118 ] ;
return F_13 ( V_7 , V_552 , V_542 ,
sizeof( V_542 ) , NULL , 0 , NULL ) ;
}
static void F_95 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
if ( V_21 -> V_126 != V_127 )
F_207 ( V_7 , V_21 -> V_126 ) ;
V_21 -> V_126 = V_127 ;
}
static int F_210 ( struct V_6 * V_7 ,
unsigned * V_521 )
{
T_1 V_553 ;
struct V_20 * V_21 = V_7 -> V_21 ;
int V_23 = F_204 ( V_7 , & V_553 ,
false , V_521 ) ;
if ( V_23 != 0 )
return V_23 ;
V_21 -> V_126 = V_553 ;
V_21 -> V_554 = false ;
F_211 ( V_7 ) ;
return 0 ;
}
static int F_212 ( struct V_6 * V_7 ,
const T_1 * V_250 ,
const T_5 * V_539 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
int V_23 ;
T_1 V_553 ;
if ( V_21 -> V_126 == V_127 ||
! V_21 -> V_554 ) {
V_23 = F_204 ( V_7 , & V_553 ,
true , NULL ) ;
if ( V_23 == - V_383 )
return V_23 ;
else if ( V_23 != 0 )
goto V_123;
} else {
V_553 = V_21 -> V_126 ;
}
V_23 = F_208 ( V_7 , V_553 ,
V_250 , V_539 ) ;
if ( V_23 != 0 )
goto V_124;
if ( V_21 -> V_126 != V_553 )
F_95 ( V_7 ) ;
V_21 -> V_126 = V_553 ;
V_21 -> V_554 = true ;
if ( V_250 != V_7 -> V_250 )
memcpy ( V_7 -> V_250 , V_250 ,
sizeof( V_7 -> V_250 ) ) ;
if ( V_539 != V_7 -> V_549 )
memcpy ( V_7 -> V_549 , V_539 , V_7 -> type -> V_555 ) ;
return 0 ;
V_124:
if ( V_553 != V_21 -> V_126 )
F_207 ( V_7 , V_553 ) ;
V_123:
F_18 ( V_7 , V_470 , V_7 -> V_34 , L_39 , V_556 , V_23 ) ;
return V_23 ;
}
static int F_213 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_12 ( V_81 , V_557 ) ;
F_12 ( V_540 , V_558 ) ;
F_12 ( V_542 , V_559 ) ;
T_4 V_22 ;
int V_23 , V_118 ;
F_17 ( V_557 !=
V_560 ) ;
if ( V_21 -> V_126 == V_127 )
return - V_116 ;
F_35 ( V_81 , V_561 ,
V_21 -> V_126 ) ;
F_17 ( F_209 ( V_7 -> V_250 ) !=
V_562 ) ;
V_23 = F_13 ( V_7 , V_563 , V_81 , sizeof( V_81 ) ,
V_540 , sizeof( V_540 ) , & V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( F_36 ( V_22 != V_558 ) )
return - V_12 ;
for ( V_118 = 0 ; V_118 < F_209 ( V_7 -> V_250 ) ; V_118 ++ )
V_7 -> V_250 [ V_118 ] = F_33 ( V_540 ,
V_564 ) [ V_118 ] ;
F_35 ( V_81 , V_565 ,
V_21 -> V_126 ) ;
F_17 ( F_209 ( V_7 -> V_549 ) !=
V_550 ) ;
V_23 = F_13 ( V_7 , V_566 , V_81 , sizeof( V_81 ) ,
V_542 , sizeof( V_542 ) , & V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( F_36 ( V_22 != V_559 ) )
return - V_12 ;
for ( V_118 = 0 ; V_118 < F_209 ( V_7 -> V_549 ) ; ++ V_118 )
V_7 -> V_549 [ V_118 ] = F_33 (
V_542 , V_567 ) [ V_118 ] ;
return 0 ;
}
static int F_214 ( struct V_6 * V_7 , bool V_568 ,
const T_1 * V_250 ,
const T_5 * V_539 )
{
int V_23 ;
if ( V_7 -> V_527 == 1 )
return 0 ;
if ( ! V_539 )
V_539 = V_7 -> V_549 ;
V_23 = F_212 ( V_7 , V_250 , V_539 ) ;
if ( V_23 == - V_190 && ! V_568 ) {
unsigned V_521 ;
bool V_569 = false ;
T_4 V_118 ;
for ( V_118 = 0 ; V_118 < F_209 ( V_7 -> V_250 ) && ! V_569 ;
V_118 ++ )
V_569 = V_250 [ V_118 ] !=
F_215 ( V_118 , V_7 -> V_527 ) ;
V_23 = F_210 ( V_7 , & V_521 ) ;
if ( V_23 == 0 ) {
if ( V_521 != V_7 -> V_527 )
F_46 ( V_7 , V_47 , V_7 -> V_34 ,
L_40
L_41
L_42
L_43 ,
V_7 -> V_527 , V_521 ) ;
else if ( V_569 )
F_46 ( V_7 , V_47 , V_7 -> V_34 ,
L_40
L_44
L_45
L_46 ) ;
else
F_94 ( V_7 , V_47 , V_7 -> V_34 ,
L_40
L_47 ) ;
}
}
return V_23 ;
}
static int F_216 ( struct V_570 * V_571 )
{
return F_62 ( V_571 -> V_7 , & V_571 -> V_572 . V_95 ,
( V_571 -> V_416 + 1 ) *
sizeof( V_417 ) ,
V_108 ) ;
}
static void F_217 ( struct V_570 * V_571 )
{
F_12 ( V_81 ,
F_218 ( V_462 * 8 /
V_463 ) ) ;
struct V_166 * V_167 = F_219 ( V_571 ) ;
T_4 V_466 = V_571 -> V_572 . V_95 . V_446 / V_463 ;
struct V_6 * V_7 = V_571 -> V_7 ;
struct V_20 * V_21 = V_7 -> V_21 ;
T_4 V_468 ;
T_12 V_353 ;
int V_23 ;
int V_118 ;
F_17 ( V_573 != 0 ) ;
V_571 -> V_574 = 0 ;
V_571 -> V_575 = 0 ;
F_35 ( V_81 , V_576 , V_571 -> V_416 + 1 ) ;
F_35 ( V_81 , V_577 , V_167 -> V_167 ) ;
F_35 ( V_81 , V_578 , F_220 ( V_571 ) ) ;
F_35 ( V_81 , V_579 ,
F_220 ( V_571 ) ) ;
F_221 ( V_81 , V_580 ,
V_581 , 1 ,
V_582 , 1 ) ;
F_35 ( V_81 , V_583 , 0 ) ;
F_35 ( V_81 , V_584 , V_21 -> V_128 ) ;
V_353 = V_571 -> V_572 . V_95 . V_353 ;
F_24 ( V_7 , V_470 , V_7 -> V_34 , L_48 ,
F_220 ( V_571 ) , V_466 , ( T_8 ) V_353 ) ;
for ( V_118 = 0 ; V_118 < V_466 ; ++ V_118 ) {
F_189 ( V_81 , V_585 , V_118 , V_353 ) ;
V_353 += V_463 ;
}
V_468 = F_218 ( V_466 ) ;
V_23 = F_13 ( V_7 , V_586 , V_81 , V_468 ,
NULL , 0 , NULL ) ;
if ( V_23 )
F_192 ( V_7 -> V_34 , L_49 ,
F_220 ( V_571 ) ) ;
}
static void F_222 ( struct V_570 * V_571 )
{
F_12 ( V_81 , V_587 ) ;
F_85 ( V_18 ) ;
struct V_6 * V_7 = V_571 -> V_7 ;
T_4 V_22 ;
int V_23 ;
F_35 ( V_81 , V_588 ,
F_220 ( V_571 ) ) ;
V_23 = F_29 ( V_7 , V_589 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 && V_23 != - V_105 )
goto V_178;
return;
V_178:
F_30 ( V_7 , V_589 , V_587 ,
V_18 , V_22 , V_23 ) ;
}
static void F_223 ( struct V_570 * V_571 )
{
F_83 ( V_571 -> V_7 , & V_571 -> V_572 . V_95 ) ;
}
static inline void
F_224 ( struct V_570 * V_571 , unsigned int V_171 )
{
struct V_590 * V_591 ;
V_417 * V_572 ;
V_572 = F_225 ( V_571 , V_171 ) ;
V_591 = V_590 ( V_571 , V_171 ) ;
F_226 ( * V_572 ,
V_592 , V_591 -> V_446 ,
V_593 , V_591 -> V_353 ) ;
}
static void F_227 ( struct V_570 * V_571 )
{
struct V_6 * V_7 = V_571 -> V_7 ;
unsigned int V_419 ;
T_3 V_8 ;
V_419 = V_571 -> V_594 & ~ 7 ;
if ( V_571 -> V_595 == V_419 )
return;
do
F_224 (
V_571 ,
V_571 -> V_595 & V_571 -> V_416 ) ;
while ( ++ V_571 -> V_595 != V_419 );
F_154 () ;
F_196 ( V_8 , V_596 ,
V_419 & V_571 -> V_416 ) ;
F_147 ( V_7 , & V_8 , V_597 ,
F_220 ( V_571 ) ) ;
}
static void F_228 ( struct V_570 * V_571 )
{
struct V_166 * V_167 = F_219 ( V_571 ) ;
F_12 ( V_81 , V_598 ) ;
V_417 V_599 ;
F_226 ( V_599 ,
V_600 , V_601 ,
V_602 , V_603 ) ;
F_35 ( V_81 , V_604 , V_167 -> V_167 ) ;
memcpy ( F_33 ( V_81 , V_605 ) , & V_599 . T_8 [ 0 ] ,
sizeof( V_417 ) ) ;
F_144 ( V_167 -> V_7 , V_606 ,
V_81 , sizeof( V_81 ) , 0 ,
V_607 , 0 ) ;
}
static void
V_607 ( struct V_6 * V_7 , unsigned long V_608 ,
int V_23 , T_3 * V_18 ,
T_4 V_609 )
{
}
static int F_229 ( struct V_166 * V_167 )
{
return F_62 ( V_167 -> V_7 , & V_167 -> V_610 . V_95 ,
( V_167 -> V_611 + 1 ) *
sizeof( V_417 ) ,
V_108 ) ;
}
static void F_230 ( struct V_166 * V_167 )
{
F_12 ( V_81 , V_612 ) ;
F_85 ( V_18 ) ;
struct V_6 * V_7 = V_167 -> V_7 ;
T_4 V_22 ;
int V_23 ;
F_35 ( V_81 , V_613 , V_167 -> V_167 ) ;
V_23 = F_29 ( V_7 , V_614 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 && V_23 != - V_105 )
goto V_178;
return;
V_178:
F_30 ( V_7 , V_614 , V_612 ,
V_18 , V_22 , V_23 ) ;
}
static int F_231 ( struct V_166 * V_167 )
{
F_12 ( V_81 ,
F_232 ( V_615 * 8 /
V_463 ) ) ;
F_12 ( V_18 , V_616 ) ;
T_4 V_466 = V_167 -> V_610 . V_95 . V_446 / V_463 ;
struct V_6 * V_7 = V_167 -> V_7 ;
struct V_20 * V_21 ;
T_4 V_468 , V_22 ;
unsigned int V_54 , V_53 ;
T_12 V_353 ;
int V_23 ;
int V_118 ;
V_21 = V_7 -> V_21 ;
memset ( V_167 -> V_610 . V_95 . V_337 , 0xff , V_167 -> V_610 . V_95 . V_446 ) ;
F_35 ( V_81 , V_617 , V_167 -> V_611 + 1 ) ;
F_35 ( V_81 , V_618 , V_167 -> V_167 ) ;
F_35 ( V_81 , V_619 , V_167 -> V_167 ) ;
F_35 ( V_81 , V_620 ,
V_621 ) ;
F_35 ( V_81 , V_622 , 0 ) ;
F_35 ( V_81 , V_623 , 0 ) ;
F_35 ( V_81 , V_624 ,
V_625 ) ;
F_35 ( V_81 , V_626 , 0 ) ;
if ( V_21 -> V_37 &
1 << V_627 ) {
F_221 ( V_81 , V_628 ,
V_629 , 1 ,
V_630 ,
V_631 ) ;
} else {
bool V_632 = ! ( V_21 -> V_35 &
1 << V_633 ) ;
F_233 ( V_81 , V_634 ,
V_635 , 1 ,
V_636 , 1 ,
V_637 , 1 ,
V_638 , V_632 ) ;
}
V_353 = V_167 -> V_610 . V_95 . V_353 ;
for ( V_118 = 0 ; V_118 < V_466 ; ++ V_118 ) {
F_189 ( V_81 , V_639 , V_118 , V_353 ) ;
V_353 += V_463 ;
}
V_468 = F_234 ( V_466 ) ;
V_23 = F_13 ( V_7 , V_640 , V_81 , V_468 ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_22 >= V_616 )
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_50 ,
V_167 -> V_167 ,
F_14 ( V_18 , V_641 ) ) ;
if ( V_167 -> V_167 || V_23 )
return V_23 ;
V_23 = F_22 ( V_7 , & V_53 , & V_54 ) ;
if ( V_23 == - V_57 ) {
V_21 -> V_642 = false ;
V_23 = 0 ;
} else if ( V_23 ) {
goto V_178;
} else {
V_21 -> V_642 =
! ! ( V_54 & V_643 ) ;
if ( V_53 & V_643 &&
! V_21 -> V_642 ) {
unsigned int V_259 ;
V_23 = F_23 ( V_7 ,
V_644 ,
true , & V_259 ) ;
if ( ! V_23 ) {
if ( V_259 &
1 << V_645 ) {
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_51 ) ;
V_23 = F_5 ( V_7 ) ;
if ( V_23 >= 0 ) {
V_21 -> V_125 = V_23 ;
V_23 = 0 ;
}
}
V_21 -> V_642 = true ;
} else if ( V_23 == - V_73 ) {
V_23 = 0 ;
}
}
}
if ( ! V_23 )
return 0 ;
V_178:
F_230 ( V_167 ) ;
return V_23 ;
}
static void F_235 ( struct V_166 * V_167 )
{
F_83 ( V_167 -> V_7 , & V_167 -> V_610 . V_95 ) ;
}
static void F_236 ( struct V_570 * V_571 ,
unsigned int V_646 )
{
struct V_6 * V_7 = V_571 -> V_7 ;
F_94 ( V_7 , V_470 , V_7 -> V_34 ,
L_52 ,
F_220 ( V_571 ) , V_646 ) ;
F_237 ( V_7 , V_647 ) ;
}
static void
F_238 ( struct V_570 * V_571 ,
unsigned int V_648 , unsigned int V_649 )
{
unsigned int V_650 = ( V_648 - V_649 ) & V_571 -> V_416 ;
struct V_6 * V_7 = V_571 -> V_7 ;
F_94 ( V_7 , V_470 , V_7 -> V_34 ,
L_53 ,
V_650 , V_648 , V_649 ) ;
F_237 ( V_7 , V_647 ) ;
}
static void F_239 ( struct V_570 * V_571 )
{
unsigned int V_651 ;
F_24 ( V_571 -> V_7 , V_470 , V_571 -> V_7 -> V_34 ,
L_54 ,
V_571 -> V_574 ) ;
V_651 = V_571 -> V_652 & V_571 -> V_416 ;
F_240 ( V_571 , V_651 , V_571 -> V_574 ,
0 , V_653 ) ;
V_571 -> V_652 += V_571 -> V_574 ;
V_571 -> V_574 = 0 ;
V_571 -> V_575 = 0 ;
++ F_219 ( V_571 ) -> V_654 ;
}
static T_2 F_241 ( struct V_166 * V_167 ,
unsigned int V_655 ,
unsigned int V_656 ,
unsigned int V_657 ,
unsigned int V_658 ,
const V_417 * V_599 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
if ( F_199 ( * V_599 , V_659 ) ) {
if ( ! V_7 -> V_660 )
V_167 -> V_661 += V_655 ;
return V_653 ;
}
if ( F_199 ( * V_599 , V_662 ) ) {
if ( F_175 ( V_656 != V_663 &&
V_657 != V_664 &&
V_657 != V_665 &&
V_657 != V_666 &&
V_657 != V_667 ) )
F_192 ( V_7 -> V_34 ,
L_55
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
if ( ! V_7 -> V_660 )
* ( V_656 ?
& V_167 -> V_669 :
& V_167 -> V_670 ) += V_655 ;
return 0 ;
}
if ( F_199 ( * V_599 , V_671 ) ) {
if ( F_175 ( V_656 != V_663 &&
( ( V_657 != V_664 &&
V_657 != V_666 ) ||
( V_658 != V_672 &&
V_658 != V_673 ) ) ) )
F_192 ( V_7 -> V_34 ,
L_56
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
if ( ! V_7 -> V_660 )
* ( V_656 ?
& V_167 -> V_674 :
& V_167 -> V_675 ) += V_655 ;
return 0 ;
}
if ( F_199 ( * V_599 , V_676 ) ) {
if ( F_175 ( ! V_656 ) )
F_192 ( V_7 -> V_34 ,
L_57
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
else if ( F_175 ( V_657 != V_664 &&
V_657 != V_665 &&
V_657 != V_666 &&
V_657 != V_667 ) )
F_192 ( V_7 -> V_34 ,
L_58
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
if ( ! V_7 -> V_660 )
V_167 -> V_677 += V_655 ;
return 0 ;
}
if ( F_199 ( * V_599 , V_678 ) ) {
if ( F_175 ( ! V_656 ) )
F_192 ( V_7 -> V_34 ,
L_59
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
else if ( F_175 ( ( V_657 != V_664 &&
V_657 != V_666 ) ||
( V_658 != V_672 &&
V_658 != V_673 ) ) )
F_192 ( V_7 -> V_34 ,
L_60
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
if ( ! V_7 -> V_660 )
V_167 -> V_679 += V_655 ;
return 0 ;
}
F_36 ( 1 ) ;
return 0 ;
}
static int F_243 ( struct V_166 * V_167 ,
const V_417 * V_599 )
{
unsigned int V_301 , V_680 , V_646 ;
unsigned int V_657 , V_658 , V_656 ;
unsigned int V_681 , V_655 , V_118 ;
struct V_6 * V_7 = V_167 -> V_7 ;
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_570 * V_571 ;
V_417 V_682 ;
bool V_683 ;
T_2 V_259 = 0 ;
if ( F_175 ( F_163 ( V_7 -> V_684 ) ) )
return 0 ;
V_301 = F_199 ( * V_599 , V_685 ) ;
V_680 = F_199 ( * V_599 , V_686 ) ;
V_646 = F_199 ( * V_599 , V_687 ) ;
V_657 = F_199 ( * V_599 , V_688 ) ;
V_658 = F_199 ( * V_599 , V_689 ) ;
V_683 = F_199 ( * V_599 , V_690 ) ;
V_656 =
V_21 -> V_35 &
( 1 << V_691 ) ?
F_199 ( * V_599 , V_692 ) :
V_693 ;
if ( F_199 ( * V_599 , V_694 ) )
F_192 ( V_7 -> V_34 , L_61
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
V_571 = F_244 ( V_167 ) ;
if ( F_175 ( V_646 != F_220 ( V_571 ) ) )
F_236 ( V_571 , V_646 ) ;
V_681 = ( ( V_680 - V_571 -> V_652 ) &
( ( 1 << V_695 ) - 1 ) ) ;
if ( V_681 != V_571 -> V_574 + 1 ) {
struct V_20 * V_21 = V_7 -> V_21 ;
if ( F_175 ( V_681 == V_571 -> V_574 ) ) {
if ( V_571 -> V_574 == 0 || V_301 != 0 )
F_192 ( V_7 -> V_34 ,
L_62
V_668 L_33 ,
V_571 -> V_574 ,
F_242 ( * V_599 ) ) ;
F_239 ( V_571 ) ;
return 0 ;
}
if ( ! ( V_21 -> V_35 &
( 1 << V_633 ) ) ||
V_571 -> V_574 != 0 || V_683 ) {
F_238 (
V_571 , V_680 ,
( V_571 -> V_652 +
V_571 -> V_574 + 1 ) &
( ( 1 << V_695 ) - 1 ) ) ;
return 0 ;
}
V_571 -> V_574 = 1 ;
V_571 -> V_575 = 0 ;
V_655 = V_681 ;
++ V_167 -> V_696 ;
V_167 -> V_697 += V_655 ;
V_259 |= V_698 ;
} else {
++ V_571 -> V_574 ;
V_571 -> V_575 += V_301 ;
if ( V_683 )
return 0 ;
V_655 = 1 ;
}
F_183 ( V_682 , V_659 , 1 ,
V_662 , 1 ,
V_671 , 1 ,
V_676 , 1 ,
V_678 , 1 ) ;
F_245 ( V_682 , * V_599 , V_682 ) ;
if ( F_175 ( ! F_246 ( V_682 ) ) ) {
V_259 |= F_241 ( V_167 , V_655 ,
V_656 ,
V_657 , V_658 ,
V_599 ) ;
} else {
bool V_699 = V_658 == V_672 ||
V_658 == V_673 ;
switch ( V_656 ) {
case V_663 :
V_259 |= V_700 ;
if ( V_699 )
V_259 |= V_701 ;
break;
case V_702 :
case V_693 :
if ( V_699 )
V_259 |= V_700 ;
break;
default:
F_192 ( V_7 -> V_34 ,
L_63
V_668 L_33 ,
F_242 ( * V_599 ) ) ;
}
}
if ( V_658 == V_672 )
V_259 |= V_703 ;
V_167 -> V_704 += 2 * V_655 ;
for ( V_118 = 0 ; V_118 < V_655 ; V_118 ++ ) {
F_240 ( V_571 ,
V_571 -> V_652 & V_571 -> V_416 ,
V_571 -> V_574 , V_571 -> V_575 ,
V_259 ) ;
V_571 -> V_652 += V_571 -> V_574 ;
}
V_571 -> V_574 = 0 ;
V_571 -> V_575 = 0 ;
return V_655 ;
}
static int
F_247 ( struct V_166 * V_167 , V_417 * V_599 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
struct V_168 * V_169 ;
unsigned int V_705 ;
unsigned int V_706 ;
int V_707 = 0 ;
if ( F_175 ( F_163 ( V_7 -> V_684 ) ) )
return 0 ;
if ( F_175 ( F_199 ( * V_599 , V_708 ) ) )
return 0 ;
V_705 = F_199 ( * V_599 , V_709 ) ;
V_706 = F_199 ( * V_599 , V_710 ) ;
V_169 = F_248 ( V_167 ,
V_706 % V_238 ) ;
V_707 = ( ( V_705 + 1 - V_169 -> V_711 ) &
V_169 -> V_416 ) ;
F_249 ( V_169 , V_705 & V_169 -> V_416 ) ;
return V_707 ;
}
static void
F_250 ( struct V_166 * V_167 , V_417 * V_599 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
int V_712 ;
V_712 = F_199 ( * V_599 , V_713 ) ;
switch ( V_712 ) {
case V_714 :
case V_715 :
break;
case V_716 :
break;
default:
F_18 ( V_7 , V_470 , V_7 -> V_34 ,
L_64
L_65 V_668 L_66 ,
V_167 -> V_167 , V_712 ,
F_242 ( * V_599 ) ) ;
}
}
static void F_251 ( struct V_166 * V_167 ,
V_417 * V_599 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
T_1 V_712 ;
V_712 = F_199 ( * V_599 , V_717 ) ;
switch ( V_712 ) {
case V_718 :
V_167 -> V_719 = F_161 () ;
break;
case V_603 :
F_252 ( & V_167 -> V_571 , true ) ;
break;
default:
F_18 ( V_7 , V_470 , V_7 -> V_34 ,
L_67
L_65 V_668 L_66 ,
V_167 -> V_167 , ( unsigned ) V_712 ,
F_242 ( * V_599 ) ) ;
}
}
static int F_253 ( struct V_166 * V_167 , int V_720 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
V_417 V_599 , * V_721 ;
unsigned int V_722 ;
int V_723 ;
int V_707 = 0 ;
int V_724 = 0 ;
if ( V_720 <= 0 )
return V_724 ;
V_722 = V_167 -> V_725 ;
for (; ; ) {
V_721 = F_254 ( V_167 , V_722 ) ;
V_599 = * V_721 ;
if ( ! F_255 ( & V_599 ) )
break;
F_256 ( * V_721 ) ;
++ V_722 ;
V_723 = F_199 ( V_599 , V_600 ) ;
F_160 ( V_7 , V_33 , V_7 -> V_34 ,
L_68 V_668 L_33 ,
V_167 -> V_167 , F_242 ( V_599 ) ) ;
switch ( V_723 ) {
case V_726 :
F_257 ( V_167 , & V_599 ) ;
break;
case V_727 :
V_724 += F_243 ( V_167 , & V_599 ) ;
if ( V_724 >= V_720 ) {
V_724 = V_720 ;
goto V_360;
}
break;
case V_728 :
V_707 += F_247 ( V_167 , & V_599 ) ;
if ( V_707 > V_7 -> V_729 ) {
V_724 = V_720 ;
goto V_360;
} else if ( ++ V_724 == V_720 ) {
goto V_360;
}
break;
case V_730 :
F_250 ( V_167 , & V_599 ) ;
if ( ++ V_724 == V_720 )
goto V_360;
break;
case V_601 :
F_251 ( V_167 , & V_599 ) ;
break;
default:
F_18 ( V_7 , V_470 , V_7 -> V_34 ,
L_69
L_65 V_668 L_66 ,
V_167 -> V_167 , V_723 ,
F_242 ( V_599 ) ) ;
}
}
V_360:
V_167 -> V_725 = V_722 ;
return V_724 ;
}
static void F_258 ( struct V_166 * V_167 )
{
struct V_6 * V_7 = V_167 -> V_7 ;
T_3 V_731 ;
if ( F_27 ( V_7 ) ) {
F_17 ( V_732 <
( 1 << V_733 ) ) ;
F_17 ( V_615 >
( 1 << 2 * V_733 ) ) ;
F_148 ( V_731 , V_734 ,
V_735 ,
V_736 ,
( V_167 -> V_725 &
V_167 -> V_611 ) >>
V_733 ) ;
F_147 ( V_7 , & V_731 , V_377 ,
V_167 -> V_167 ) ;
F_148 ( V_731 , V_734 ,
V_737 ,
V_736 ,
V_167 -> V_725 &
( ( 1 << V_733 ) - 1 ) ) ;
F_147 ( V_7 , & V_731 , V_377 ,
V_167 -> V_167 ) ;
} else {
F_196 ( V_731 , V_738 ,
V_167 -> V_725 &
V_167 -> V_611 ) ;
F_147 ( V_7 , & V_731 , V_739 , V_167 -> V_167 ) ;
}
}
static void F_259 ( struct V_166 * V_167 )
{
F_12 ( V_81 , V_598 ) ;
struct V_6 * V_7 = V_167 -> V_7 ;
V_417 V_599 ;
int V_23 ;
F_226 ( V_599 ,
V_600 , V_601 ,
V_602 , V_718 ) ;
F_35 ( V_81 , V_604 , V_167 -> V_167 ) ;
memcpy ( F_33 ( V_81 , V_605 ) , & V_599 . T_8 [ 0 ] ,
sizeof( V_417 ) ) ;
V_23 = F_13 ( V_7 , V_606 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
if ( V_23 != 0 )
goto V_178;
return;
V_178:
F_36 ( true ) ;
F_18 ( V_7 , V_470 , V_7 -> V_34 , L_39 , V_556 , V_23 ) ;
}
void F_260 ( struct V_6 * V_7 )
{
if ( F_261 ( & V_7 -> V_359 ) )
F_262 ( & V_7 -> V_740 ) ;
F_36 ( F_141 ( & V_7 -> V_359 ) < 0 ) ;
}
static int F_263 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_166 * V_167 ;
struct V_168 * V_169 ;
struct V_570 * V_571 ;
int V_741 ;
if ( V_21 -> V_248 ) {
F_264 ( & V_7 -> V_359 , 0 ) ;
return 0 ;
}
if ( V_7 -> V_742 != V_743 ) {
F_89 (channel, efx) {
F_265 (rx_queue, channel)
F_222 ( V_571 ) ;
F_90 (tx_queue, channel)
F_193 ( V_169 ) ;
}
F_266 ( V_7 -> V_740 ,
F_141 ( & V_7 -> V_359 ) == 0 ,
F_267 ( V_744 ) ) ;
V_741 = F_141 ( & V_7 -> V_359 ) ;
if ( V_741 ) {
F_18 ( V_7 , V_470 , V_7 -> V_34 , L_70 ,
V_741 ) ;
return - V_745 ;
}
}
return 0 ;
}
static void F_268 ( struct V_6 * V_7 )
{
F_264 ( & V_7 -> V_359 , 0 ) ;
}
static bool F_269 ( const struct V_746 * V_747 ,
const struct V_746 * V_748 )
{
if ( ( V_747 -> V_749 ^ V_748 -> V_749 ) |
( ( V_747 -> V_259 ^ V_748 -> V_259 ) &
( V_750 | V_751 ) ) )
return false ;
return memcmp ( & V_747 -> V_752 , & V_748 -> V_752 ,
sizeof( struct V_746 ) -
F_270 ( struct V_746 , V_752 ) ) == 0 ;
}
static unsigned int F_271 ( const struct V_746 * V_753 )
{
F_17 ( F_270 ( struct V_746 , V_752 ) & 3 ) ;
return F_272 ( ( const T_1 * ) & V_753 -> V_752 ,
( sizeof( struct V_746 ) -
F_270 ( struct V_746 , V_752 ) ) / 4 ,
0 ) ;
}
static bool F_273 ( const struct V_746 * V_753 )
{
if ( V_753 -> V_749 & V_754 &&
! F_274 ( V_753 -> V_755 ) )
return true ;
if ( ( V_753 -> V_749 &
( V_756 | V_757 ) ) ==
( V_756 | V_757 ) ) {
if ( V_753 -> V_758 == F_275 ( V_759 ) &&
! F_276 ( V_753 -> V_760 [ 0 ] ) )
return true ;
if ( V_753 -> V_758 == F_275 ( V_761 ) &&
( ( const T_5 * ) V_753 -> V_760 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_746 *
F_277 ( const struct V_762 * V_763 ,
unsigned int V_764 )
{
return (struct V_746 * ) ( V_763 -> V_765 [ V_764 ] . V_753 &
~ V_766 ) ;
}
static unsigned int
F_278 ( const struct V_762 * V_763 ,
unsigned int V_764 )
{
return V_763 -> V_765 [ V_764 ] . V_753 & V_766 ;
}
static void
F_279 ( struct V_762 * V_763 ,
unsigned int V_764 ,
const struct V_746 * V_753 ,
unsigned int V_259 )
{
V_763 -> V_765 [ V_764 ] . V_753 = ( unsigned long ) V_753 | V_259 ;
}
static void
F_280 ( struct V_6 * V_7 ,
const struct V_746 * V_753 ,
T_3 * V_81 )
{
enum V_767 V_768 = F_281 ( V_753 ) ;
T_1 V_769 = 0 , V_770 , V_771 ;
F_35 ( V_81 , V_772 ,
F_273 ( V_753 ) ?
V_773 :
V_774 ) ;
#define F_282 ( T_13 , T_14 ) \
do { \
match_fields |= \
1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN; \
BUILD_BUG_ON( \
MC_CMD_FILTER_OP_IN_ ## mcdi_field ## _LEN < \
sizeof(value)); \
memcpy(MCDI_PTR(inbuf, FILTER_OP_IN_ ## mcdi_field), \
&value, sizeof(value)); \
} while (0)
#define F_283 ( T_15 , T_16 , T_14 ) \
if (spec->match_flags & EFX_FILTER_MATCH_ ## gen_flag) { \
COPY_VALUE(spec->gen_field, mcdi_field); \
}
if ( V_768 ) {
T_17 V_758 =
F_275 ( V_768 & V_775 ?
V_761 : V_759 ) ;
T_5 V_776 = V_777 ;
T_5 V_778 ;
switch ( V_768 & V_779 ) {
case V_780 :
V_776 = V_781 ;
case V_782 :
F_282 ( V_758 , V_783 ) ;
V_778 = V_784 ;
F_282 ( V_778 , V_785 ) ;
F_140 ( V_81 ,
V_786 ,
V_787 ,
V_776 ) ;
break;
case V_788 :
F_282 ( V_758 , V_783 ) ;
V_778 = V_789 ;
F_282 ( V_778 , V_785 ) ;
break;
default:
F_36 ( 1 ) ;
}
V_770 = V_790 ;
V_771 = V_791 ;
} else {
V_770 = V_792 ;
V_771 = V_793 ;
}
if ( V_753 -> V_749 & V_794 )
V_769 |=
F_274 ( V_753 -> V_755 ) ?
1 << V_771 :
1 << V_770 ;
F_283 ( V_795 , V_796 , V_797 ) ;
F_283 ( V_798 , V_760 , V_799 ) ;
F_283 ( V_800 , V_801 , V_802 ) ;
F_283 ( V_803 , V_804 , V_805 ) ;
F_283 ( V_806 , V_755 , V_807 ) ;
F_283 ( V_808 , V_809 , V_810 ) ;
F_283 ( V_783 , V_758 , V_783 ) ;
F_283 ( V_811 , V_812 , V_813 ) ;
F_283 ( V_814 , V_752 , V_815 ) ;
F_283 ( V_785 , V_816 , V_785 ) ;
#undef F_283
#undef F_282
F_35 ( V_81 , V_817 ,
V_769 ) ;
}
static void F_284 ( struct V_6 * V_7 ,
const struct V_746 * V_753 ,
T_3 * V_81 , T_8 V_818 ,
bool V_819 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
T_1 V_259 = V_753 -> V_259 ;
memset ( V_81 , 0 , V_820 ) ;
if ( V_259 & V_821 &&
V_753 -> V_822 == V_823 &&
V_21 -> V_126 == V_127 )
V_259 &= ~ V_821 ;
if ( V_819 ) {
F_35 ( V_81 , V_772 ,
V_824 ) ;
F_139 ( V_81 , V_825 , V_818 ) ;
} else {
F_280 ( V_7 , V_753 , V_81 ) ;
}
F_35 ( V_81 , V_826 , V_21 -> V_128 ) ;
F_35 ( V_81 , V_827 ,
V_753 -> V_828 == V_829 ?
V_830 :
V_831 ) ;
F_35 ( V_81 , V_832 , 0 ) ;
F_35 ( V_81 , V_833 ,
V_834 ) ;
F_35 ( V_81 , V_835 ,
V_753 -> V_828 == V_829 ?
0 : V_753 -> V_828 ) ;
F_35 ( V_81 , V_836 ,
( V_259 & V_821 ) ?
V_837 :
V_838 ) ;
if ( V_259 & V_821 )
F_35 ( V_81 , V_839 ,
V_753 -> V_822 !=
V_823 ?
V_753 -> V_822 : V_21 -> V_126 ) ;
}
static int F_285 ( struct V_6 * V_7 ,
const struct V_746 * V_753 ,
T_8 * V_818 , bool V_819 )
{
F_12 ( V_81 , V_820 ) ;
F_12 ( V_18 , V_840 ) ;
int V_23 ;
F_284 ( V_7 , V_753 , V_81 , * V_818 , V_819 ) ;
V_23 = F_13 ( V_7 , V_841 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , NULL ) ;
if ( V_23 == 0 )
* V_818 = F_286 ( V_18 , V_842 ) ;
if ( V_23 == - V_163 )
V_23 = - V_223 ;
return V_23 ;
}
static T_1 F_287 ( const struct V_746 * V_753 )
{
enum V_767 V_768 = F_281 ( V_753 ) ;
unsigned int V_749 = V_753 -> V_749 ;
unsigned int V_770 , V_771 ;
T_1 V_843 = 0 ;
#define F_288 ( T_15 , T_14 , T_18 ) { \
unsigned int old_match_flags = match_flags; \
match_flags &= ~EFX_FILTER_MATCH_ ## gen_flag; \
if (match_flags != old_match_flags) \
mcdi_flags |= \
(1 << ((encap) ? \
MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_ ## \
mcdi_field ## _LBN : \
MC_CMD_FILTER_OP_EXT_IN_MATCH_ ##\
mcdi_field ## _LBN)); \
}
F_288 ( V_795 , V_797 , V_768 ) ;
F_288 ( V_798 , V_799 , V_768 ) ;
F_288 ( V_800 , V_802 , V_768 ) ;
F_288 ( V_803 , V_805 , V_768 ) ;
F_288 ( V_806 , V_807 , V_768 ) ;
F_288 ( V_808 , V_810 , V_768 ) ;
F_288 ( V_783 , V_783 , V_768 ) ;
F_288 ( V_785 , V_785 , V_768 ) ;
F_288 ( V_811 , V_813 , false ) ;
F_288 ( V_814 , V_815 , false ) ;
#undef F_288
if ( V_768 ) {
V_749 &= ~ V_844 ;
V_843 |=
( 1 << V_845 ) ;
V_843 |= ( 1 << V_846 ) ;
V_770 = V_790 ;
V_771 = V_791 ;
} else {
V_770 = V_792 ;
V_771 = V_793 ;
}
if ( V_749 & V_794 ) {
V_749 &= ~ V_794 ;
V_843 |=
F_274 ( V_753 -> V_755 ) ?
1 << V_771 :
1 << V_770 ;
}
F_2 ( V_749 ) ;
return V_843 ;
}
static int F_289 ( struct V_762 * V_763 ,
const struct V_746 * V_753 )
{
T_1 V_843 = F_287 ( V_753 ) ;
unsigned int V_847 ;
for ( V_847 = 0 ;
V_847 < V_763 -> V_848 ;
V_847 ++ )
if ( V_763 -> V_849 [ V_847 ] == V_843 )
return V_847 ;
return - V_850 ;
}
static T_19 F_290 ( struct V_6 * V_7 ,
struct V_746 * V_753 ,
bool V_851 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
F_123 ( V_852 , V_853 ) ;
struct V_746 * V_854 ;
unsigned int V_847 , V_855 ;
unsigned int V_856 ;
bool V_819 = false ;
int V_857 = - 1 ;
F_291 ( V_858 ) ;
bool V_859 ;
T_19 V_23 ;
if ( ( V_753 -> V_259 & ( V_750 | V_751 ) ) !=
V_750 )
return - V_270 ;
V_23 = F_289 ( V_763 , V_753 ) ;
if ( V_23 < 0 )
return V_23 ;
V_847 = V_23 ;
V_855 = F_271 ( V_753 ) ;
V_859 = F_292 ( V_753 ) ;
if ( V_859 )
F_293 ( V_852 , V_853 ) ;
for (; ; ) {
unsigned int V_860 = 1 ;
unsigned int V_118 ;
F_138 ( & V_7 -> V_861 ) ;
for (; ; ) {
V_118 = ( V_855 + V_860 ) & ( V_3 - 1 ) ;
V_854 = F_277 ( V_763 , V_118 ) ;
if ( ! V_854 ) {
if ( V_857 < 0 )
V_857 = V_118 ;
} else if ( F_269 ( V_753 , V_854 ) ) {
if ( V_763 -> V_765 [ V_118 ] . V_753 &
V_862 )
break;
if ( V_753 -> V_863 < V_854 -> V_863 &&
V_753 -> V_863 != V_864 ) {
V_23 = - V_73 ;
goto V_865;
}
if ( ! V_859 ) {
if ( V_753 -> V_863 ==
V_854 -> V_863 &&
! V_851 ) {
V_23 = - V_866 ;
goto V_865;
}
V_857 = V_118 ;
goto V_867;
} else if ( V_753 -> V_863 >
V_854 -> V_863 ||
( V_753 -> V_863 ==
V_854 -> V_863 &&
V_851 ) ) {
if ( V_857 < 0 )
V_857 = V_118 ;
else
F_294 ( V_860 , V_852 ) ;
}
}
if ( V_860 == V_853 ) {
if ( V_857 < 0 ) {
V_23 = - V_223 ;
goto V_865;
}
goto V_867;
}
++ V_860 ;
}
F_295 ( & V_763 -> V_868 , & V_858 , V_869 ) ;
F_136 ( & V_7 -> V_861 ) ;
F_296 () ;
}
V_867:
V_854 = F_277 ( V_763 , V_857 ) ;
if ( V_854 ) {
if ( V_753 -> V_863 == V_864 &&
V_854 -> V_863 >= V_864 ) {
if ( V_854 -> V_863 > V_864 )
V_854 -> V_259 |= V_870 ;
V_763 -> V_765 [ V_857 ] . V_753 &=
~ V_871 ;
V_23 = V_857 ;
goto V_865;
}
V_819 = true ;
V_856 = F_278 ( V_763 , V_857 ) ;
} else {
V_854 = F_297 ( sizeof( * V_753 ) , V_351 ) ;
if ( ! V_854 ) {
V_23 = - V_107 ;
goto V_865;
}
* V_854 = * V_753 ;
V_856 = 0 ;
}
F_279 ( V_763 , V_857 , V_854 ,
V_856 | V_862 ) ;
if ( V_859 ) {
unsigned int V_860 , V_118 ;
for ( V_860 = 0 ; V_860 < V_853 ; V_860 ++ ) {
V_118 = ( V_855 + V_860 ) & ( V_3 - 1 ) ;
if ( F_298 ( V_860 , V_852 ) )
V_763 -> V_765 [ V_118 ] . V_753 |=
V_862 ;
}
}
F_136 ( & V_7 -> V_861 ) ;
V_23 = F_285 ( V_7 , V_753 , & V_763 -> V_765 [ V_857 ] . V_818 ,
V_819 ) ;
F_138 ( & V_7 -> V_861 ) ;
if ( V_23 == 0 ) {
if ( V_819 ) {
if ( V_854 -> V_863 == V_864 )
V_854 -> V_259 |=
V_870 ;
V_854 -> V_863 = V_753 -> V_863 ;
V_854 -> V_259 &= V_870 ;
V_854 -> V_259 |= V_753 -> V_259 ;
V_854 -> V_822 = V_753 -> V_822 ;
V_854 -> V_828 = V_753 -> V_828 ;
}
} else if ( ! V_819 ) {
F_54 ( V_854 ) ;
V_854 = NULL ;
}
F_279 ( V_763 , V_857 , V_854 , V_856 ) ;
if ( V_859 ) {
F_12 ( V_81 , V_872 ) ;
unsigned int V_860 , V_118 ;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
for ( V_860 = 0 ; V_860 < V_853 ; V_860 ++ ) {
if ( ! F_298 ( V_860 , V_852 ) )
continue;
V_118 = ( V_855 + V_860 ) & ( V_3 - 1 ) ;
V_854 = F_277 ( V_763 , V_118 ) ;
V_856 = F_278 ( V_763 , V_118 ) ;
if ( V_23 == 0 ) {
F_136 ( & V_7 -> V_861 ) ;
F_35 ( V_81 , V_772 ,
V_873 ) ;
F_139 ( V_81 , V_825 ,
V_763 -> V_765 [ V_118 ] . V_818 ) ;
V_23 = F_13 ( V_7 , V_841 ,
V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
F_138 ( & V_7 -> V_861 ) ;
}
if ( V_23 == 0 ) {
F_54 ( V_854 ) ;
V_854 = NULL ;
V_856 = 0 ;
} else {
V_856 &= ~ V_862 ;
}
F_279 ( V_763 , V_118 , V_854 ,
V_856 ) ;
}
}
if ( V_23 == 0 )
V_23 = F_4 ( V_847 , V_857 ) ;
F_299 ( & V_763 -> V_868 ) ;
V_865:
F_136 ( & V_7 -> V_861 ) ;
F_300 ( & V_763 -> V_868 , & V_858 ) ;
return V_23 ;
}
static void F_301 ( struct V_6 * V_7 )
{
}
static int F_302 ( struct V_6 * V_7 ,
unsigned int V_874 ,
T_1 V_1 , bool V_875 )
{
unsigned int V_764 = F_1 ( V_1 ) ;
struct V_762 * V_763 = V_7 -> V_112 ;
F_12 ( V_81 ,
V_876 +
V_877 ) ;
struct V_746 * V_753 ;
F_291 ( V_858 ) ;
int V_23 ;
for (; ; ) {
F_138 ( & V_7 -> V_861 ) ;
if ( ! ( V_763 -> V_765 [ V_764 ] . V_753 &
V_862 ) )
break;
F_295 ( & V_763 -> V_868 , & V_858 , V_869 ) ;
F_136 ( & V_7 -> V_861 ) ;
F_296 () ;
}
V_753 = F_277 ( V_763 , V_764 ) ;
if ( ! V_753 ||
( ! V_875 &&
F_289 ( V_763 , V_753 ) !=
F_3 ( V_1 ) ) ) {
V_23 = - V_116 ;
goto V_865;
}
if ( V_753 -> V_259 & V_870 &&
V_874 == ( 1U << V_864 ) ) {
V_753 -> V_259 &= ~ V_870 ;
V_763 -> V_765 [ V_764 ] . V_753 &= ~ V_871 ;
V_23 = 0 ;
goto V_865;
}
if ( ! ( V_874 & ( 1U << V_753 -> V_863 ) ) ) {
V_23 = - V_116 ;
goto V_865;
}
V_763 -> V_765 [ V_764 ] . V_753 |= V_862 ;
F_136 ( & V_7 -> V_861 ) ;
if ( V_753 -> V_259 & V_870 ) {
struct V_746 V_878 = * V_753 ;
V_878 . V_863 = V_864 ;
V_878 . V_259 = ( V_750 |
( F_303 ( V_7 ) ?
V_821 : 0 ) ) ;
V_878 . V_828 = 0 ;
V_878 . V_822 = V_823 ;
V_23 = F_285 ( V_7 , & V_878 ,
& V_763 -> V_765 [ V_764 ] . V_818 ,
true ) ;
F_138 ( & V_7 -> V_861 ) ;
if ( V_23 == 0 )
* V_753 = V_878 ;
} else {
F_35 ( V_81 , V_772 ,
F_273 ( V_753 ) ?
V_879 :
V_873 ) ;
F_139 ( V_81 , V_825 ,
V_763 -> V_765 [ V_764 ] . V_818 ) ;
V_23 = F_29 ( V_7 , V_841 ,
V_81 , sizeof( V_81 ) , NULL , 0 , NULL ) ;
F_138 ( & V_7 -> V_861 ) ;
if ( ( V_23 == 0 ) || ( V_23 == - V_116 ) ) {
F_54 ( V_753 ) ;
F_279 ( V_763 , V_764 , NULL , 0 ) ;
} else {
F_30 ( V_7 , V_841 ,
V_872 ,
NULL , 0 , V_23 ) ;
}
}
V_763 -> V_765 [ V_764 ] . V_753 &= ~ V_862 ;
F_299 ( & V_763 -> V_868 ) ;
V_865:
F_136 ( & V_7 -> V_861 ) ;
F_300 ( & V_763 -> V_868 , & V_858 ) ;
return V_23 ;
}
static int F_304 ( struct V_6 * V_7 ,
enum V_880 V_863 ,
T_1 V_1 )
{
return F_302 ( V_7 , 1U << V_863 ,
V_1 , false ) ;
}
static void F_305 ( struct V_6 * V_7 ,
enum V_880 V_863 ,
T_1 V_1 )
{
if ( V_1 == V_2 )
return;
F_302 ( V_7 , 1U << V_863 , V_1 , true ) ;
}
static int F_306 ( struct V_6 * V_7 ,
enum V_880 V_863 ,
T_1 V_1 , struct V_746 * V_753 )
{
unsigned int V_764 = F_1 ( V_1 ) ;
struct V_762 * V_763 = V_7 -> V_112 ;
const struct V_746 * V_854 ;
int V_23 ;
F_138 ( & V_7 -> V_861 ) ;
V_854 = F_277 ( V_763 , V_764 ) ;
if ( V_854 && V_854 -> V_863 == V_863 &&
F_289 ( V_763 , V_854 ) ==
F_3 ( V_1 ) ) {
* V_753 = * V_854 ;
V_23 = 0 ;
} else {
V_23 = - V_116 ;
}
F_136 ( & V_7 -> V_861 ) ;
return V_23 ;
}
static int F_307 ( struct V_6 * V_7 ,
enum V_880 V_863 )
{
unsigned int V_874 ;
unsigned int V_118 ;
int V_23 ;
V_874 = ( ( ( 1U << ( V_863 + 1 ) ) - 1 ) &
~ ( 1U << V_864 ) ) ;
for ( V_118 = 0 ; V_118 < V_3 ; V_118 ++ ) {
V_23 = F_302 ( V_7 , V_874 ,
V_118 , true ) ;
if ( V_23 && V_23 != - V_116 )
return V_23 ;
}
return 0 ;
}
static T_1 F_308 ( struct V_6 * V_7 ,
enum V_880 V_863 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
unsigned int V_764 ;
T_19 V_881 = 0 ;
F_138 ( & V_7 -> V_861 ) ;
for ( V_764 = 0 ; V_764 < V_3 ; V_764 ++ ) {
if ( V_763 -> V_765 [ V_764 ] . V_753 &&
F_277 ( V_763 , V_764 ) -> V_863 ==
V_863 )
++ V_881 ;
}
F_136 ( & V_7 -> V_861 ) ;
return V_881 ;
}
static T_1 F_309 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
return V_763 -> V_848 * V_3 * 2 ;
}
static T_19 F_310 ( struct V_6 * V_7 ,
enum V_880 V_863 ,
T_1 * V_95 , T_1 V_882 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_746 * V_753 ;
unsigned int V_764 ;
T_19 V_881 = 0 ;
F_138 ( & V_7 -> V_861 ) ;
for ( V_764 = 0 ; V_764 < V_3 ; V_764 ++ ) {
V_753 = F_277 ( V_763 , V_764 ) ;
if ( V_753 && V_753 -> V_863 == V_863 ) {
if ( V_881 == V_882 ) {
V_881 = - V_883 ;
break;
}
V_95 [ V_881 ++ ] =
F_4 (
F_289 ( V_763 , V_753 ) ,
V_764 ) ;
}
}
F_136 ( & V_7 -> V_861 ) ;
return V_881 ;
}
static T_19 F_311 ( struct V_6 * V_7 ,
struct V_746 * V_753 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
F_12 ( V_81 , V_872 ) ;
struct V_746 * V_854 ;
unsigned int V_855 , V_118 , V_860 = 1 ;
bool V_819 = false ;
int V_857 = - 1 ;
T_8 V_608 ;
T_19 V_23 ;
F_312 ( V_753 -> V_259 !=
( V_750 | V_884 ) ) ;
F_312 ( V_753 -> V_863 != V_885 ) ;
F_312 ( F_292 ( V_753 ) ) ;
V_855 = F_271 ( V_753 ) ;
F_138 ( & V_7 -> V_861 ) ;
for (; ; ) {
V_118 = ( V_855 + V_860 ) & ( V_3 - 1 ) ;
V_854 = F_277 ( V_763 , V_118 ) ;
if ( ! V_854 ) {
if ( V_857 < 0 )
V_857 = V_118 ;
} else if ( F_269 ( V_753 , V_854 ) ) {
if ( V_763 -> V_765 [ V_118 ] . V_753 & V_862 ) {
V_23 = - V_223 ;
goto V_886;
}
if ( V_753 -> V_863 < V_854 -> V_863 ) {
V_23 = - V_73 ;
goto V_886;
}
V_857 = V_118 ;
break;
}
if ( V_860 == V_853 ) {
if ( V_857 < 0 ) {
V_23 = - V_223 ;
goto V_886;
}
break;
}
++ V_860 ;
}
V_854 = F_277 ( V_763 , V_857 ) ;
if ( V_854 ) {
V_819 = true ;
} else {
V_854 = F_297 ( sizeof( * V_753 ) , V_351 ) ;
if ( ! V_854 ) {
V_23 = - V_107 ;
goto V_886;
}
* V_854 = * V_753 ;
}
F_279 ( V_763 , V_857 , V_854 ,
V_862 ) ;
F_136 ( & V_7 -> V_861 ) ;
V_608 = V_819 << 31 | V_857 << 16 | V_753 -> V_828 ;
F_284 ( V_7 , V_753 , V_81 ,
V_763 -> V_765 [ V_857 ] . V_818 , V_819 ) ;
F_144 ( V_7 , V_841 , V_81 , sizeof( V_81 ) ,
V_887 ,
V_888 , V_608 ) ;
return V_857 ;
V_886:
F_136 ( & V_7 -> V_861 ) ;
return V_23 ;
}
static void
V_888 ( struct V_6 * V_7 , unsigned long V_608 ,
int V_23 , T_3 * V_18 ,
T_4 V_609 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
unsigned int V_857 , V_828 ;
struct V_746 * V_753 ;
bool V_819 ;
V_819 = V_608 >> 31 ;
V_857 = ( V_608 >> 16 ) & ( V_3 - 1 ) ;
V_828 = V_608 & 0xffff ;
F_138 ( & V_7 -> V_861 ) ;
V_753 = F_277 ( V_763 , V_857 ) ;
if ( V_23 == 0 ) {
V_763 -> V_765 [ V_857 ] . V_818 =
F_286 ( V_18 , V_842 ) ;
if ( V_819 )
V_753 -> V_828 = V_828 ;
} else if ( ! V_819 ) {
F_54 ( V_753 ) ;
V_753 = NULL ;
}
F_279 ( V_763 , V_857 , V_753 , 0 ) ;
F_136 ( & V_7 -> V_861 ) ;
F_299 ( & V_763 -> V_868 ) ;
}
static bool F_313 ( struct V_6 * V_7 , T_1 V_889 ,
unsigned int V_764 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_746 * V_753 =
F_277 ( V_763 , V_764 ) ;
F_12 ( V_81 ,
V_876 +
V_877 ) ;
if ( ! V_753 ||
( V_763 -> V_765 [ V_764 ] . V_753 & V_862 ) ||
V_753 -> V_863 != V_885 ||
! F_314 ( V_7 -> V_34 , V_753 -> V_828 ,
V_889 , V_764 ) )
return false ;
F_35 ( V_81 , V_772 ,
V_879 ) ;
F_139 ( V_81 , V_825 ,
V_763 -> V_765 [ V_764 ] . V_818 ) ;
if ( F_144 ( V_7 , V_841 , V_81 , sizeof( V_81 ) , 0 ,
V_890 , V_764 ) )
return false ;
V_763 -> V_765 [ V_764 ] . V_753 |= V_862 ;
return true ;
}
static void
V_890 ( struct V_6 * V_7 ,
unsigned long V_764 ,
int V_23 , T_3 * V_18 ,
T_4 V_609 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_746 * V_753 =
F_277 ( V_763 , V_764 ) ;
F_138 ( & V_7 -> V_861 ) ;
if ( V_23 == 0 ) {
F_54 ( V_753 ) ;
F_279 ( V_763 , V_764 , NULL , 0 ) ;
}
V_763 -> V_765 [ V_764 ] . V_753 &= ~ V_862 ;
F_299 ( & V_763 -> V_868 ) ;
F_136 ( & V_7 -> V_861 ) ;
}
static int F_315 ( bool T_18 , T_1 V_843 )
{
int V_749 = 0 ;
#define F_316 ( T_15 , T_14 ) do { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_EXT_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
} while (0)
if ( T_18 ) {
V_749 |= V_844 ;
V_843 &=
~ ( 1 << V_846 ) ;
V_843 &=
~ ( 1 << V_845 ) ;
F_316 ( V_811 , V_813 ) ;
F_316 ( V_814 , V_815 ) ;
F_316 ( V_891 , V_892 ) ;
F_316 ( V_891 , V_893 ) ;
F_316 ( V_795 , V_894 ) ;
F_316 ( V_798 , V_895 ) ;
F_316 ( V_800 , V_896 ) ;
F_316 ( V_803 , V_897 ) ;
F_316 ( V_806 , V_898 ) ;
F_316 ( V_808 , V_899 ) ;
F_316 ( V_783 , V_900 ) ;
F_316 ( V_785 , V_901 ) ;
} else {
F_316 ( V_891 , V_902 ) ;
F_316 ( V_891 , V_903 ) ;
F_316 ( V_795 , V_797 ) ;
F_316 ( V_798 , V_799 ) ;
F_316 ( V_800 , V_802 ) ;
F_316 ( V_803 , V_805 ) ;
F_316 ( V_806 , V_807 ) ;
F_316 ( V_808 , V_810 ) ;
F_316 ( V_783 , V_783 ) ;
F_316 ( V_811 , V_813 ) ;
F_316 ( V_814 , V_815 ) ;
F_316 ( V_785 , V_785 ) ;
}
#undef F_316
if ( V_843 )
return - V_270 ;
return V_749 ;
}
static void F_317 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_904 * V_102 , * V_117 ;
if ( ! F_318 ( & V_7 -> V_114 ) )
return;
if ( ! V_763 )
return;
F_59 (vlan, next_vlan, &table->vlan_list, list)
F_319 ( V_7 , V_102 ) ;
}
static bool F_320 ( struct V_762 * V_763 ,
bool T_18 ,
enum V_905 V_749 )
{
unsigned int V_847 ;
int V_906 ;
for ( V_847 = 0 ;
V_847 < V_763 -> V_848 ;
V_847 ++ ) {
V_906 = F_315 ( T_18 ,
V_763 -> V_849 [ V_847 ] ) ;
if ( V_906 == V_749 )
return true ;
}
return false ;
}
static int
F_321 ( struct V_6 * V_7 ,
struct V_762 * V_763 ,
bool T_18 )
{
F_12 ( V_81 , V_907 ) ;
F_12 ( V_18 , V_908 ) ;
unsigned int V_909 , V_910 ;
T_4 V_22 ;
int V_23 ;
F_35 ( V_81 , V_911 ,
T_18 ?
V_912 :
V_913 ) ;
V_23 = F_13 ( V_7 , V_914 ,
V_81 , sizeof( V_81 ) , V_18 , sizeof( V_18 ) ,
& V_22 ) ;
if ( V_23 )
return V_23 ;
V_910 = F_322 (
V_22 , V_915 ) ;
for ( V_909 = 0 ; V_909 < V_910 ; V_909 ++ ) {
T_1 V_843 =
F_323 (
V_18 ,
V_915 ,
V_909 ) ;
V_23 = F_315 ( T_18 , V_843 ) ;
if ( V_23 < 0 ) {
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_71 ,
V_556 , V_843 , V_909 ) ;
} else {
F_24 ( V_7 , V_47 , V_7 -> V_34 ,
L_72 ,
V_556 , V_843 , V_909 ,
V_23 , V_763 -> V_848 ) ;
V_763 -> V_849 [ V_763 -> V_848 ] = V_843 ;
V_763 -> V_848 ++ ;
}
}
return 0 ;
}
static int F_324 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_916 * V_34 = V_7 -> V_34 ;
struct V_762 * V_763 ;
struct V_100 * V_102 ;
int V_23 ;
if ( ! F_318 ( & V_7 -> V_114 ) )
return - V_270 ;
if ( V_7 -> V_112 )
return 0 ;
V_763 = F_47 ( sizeof( * V_763 ) , V_108 ) ;
if ( ! V_763 )
return - V_107 ;
V_763 -> V_848 = 0 ;
V_23 = F_321 ( V_7 , V_763 , false ) ;
if ( V_23 )
goto V_178;
if ( V_21 -> V_35 &
( 1 << V_691 ) )
V_23 = F_321 ( V_7 , V_763 , true ) ;
if ( V_23 )
goto V_178;
if ( ( F_325 ( V_7 ) & V_917 ) &&
! ( F_320 ( V_763 , false ,
( V_918 | V_754 ) ) &&
F_320 ( V_763 , false ,
( V_918 | V_794 ) ) ) ) {
F_94 ( V_7 , V_47 , V_34 ,
L_73 ) ;
V_34 -> V_919 &= ~ V_917 ;
V_7 -> V_920 &= ~ V_917 ;
V_34 -> V_921 &= ~ V_917 ;
}
V_763 -> V_765 = F_326 ( V_3 * sizeof( * V_763 -> V_765 ) ) ;
if ( ! V_763 -> V_765 ) {
V_23 = - V_107 ;
goto V_178;
}
V_763 -> V_922 = false ;
V_763 -> V_923 =
! ! ( V_7 -> V_34 -> V_919 & V_917 ) ;
F_75 ( & V_763 -> V_111 ) ;
V_7 -> V_112 = V_763 ;
F_327 ( & V_763 -> V_868 ) ;
F_43 (vlan, &nic_data->vlan_list, list) {
V_23 = F_50 ( V_7 , V_102 -> V_101 ) ;
if ( V_23 )
goto V_924;
}
return 0 ;
V_924:
F_317 ( V_7 ) ;
V_7 -> V_112 = NULL ;
V_178:
F_54 ( V_763 ) ;
return V_23 ;
}
static void F_328 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_20 * V_21 = V_7 -> V_21 ;
unsigned int V_925 = 0 , V_926 = 0 ;
struct V_904 * V_102 ;
struct V_746 * V_753 ;
unsigned int V_764 ;
T_1 V_843 ;
int V_847 ;
int V_23 , V_118 ;
F_36 ( ! F_329 ( & V_7 -> V_114 ) ) ;
if ( ! V_21 -> V_252 )
return;
if ( ! V_763 )
return;
F_138 ( & V_7 -> V_861 ) ;
for ( V_764 = 0 ; V_764 < V_3 ; V_764 ++ ) {
V_753 = F_277 ( V_763 , V_764 ) ;
if ( ! V_753 )
continue;
V_843 = F_287 ( V_753 ) ;
V_847 = 0 ;
while ( V_847 < V_763 -> V_848 &&
V_763 -> V_849 [ V_847 ] != V_843 )
++ V_847 ;
if ( V_847 >= V_763 -> V_848 ) {
V_925 ++ ;
goto V_927;
}
if ( V_753 -> V_822 != V_823 &&
V_753 -> V_822 != V_21 -> V_126 )
F_46 ( V_7 , V_33 , V_7 -> V_34 ,
L_74 ) ;
V_763 -> V_765 [ V_764 ] . V_753 |= V_862 ;
F_136 ( & V_7 -> V_861 ) ;
V_23 = F_285 ( V_7 , V_753 ,
& V_763 -> V_765 [ V_764 ] . V_818 ,
false ) ;
if ( V_23 )
V_926 ++ ;
F_138 ( & V_7 -> V_861 ) ;
if ( V_23 ) {
V_927:
F_43 (vlan, &table->vlan_list, list)
for ( V_118 = 0 ; V_118 < V_928 ; ++ V_118 )
if ( V_102 -> V_929 [ V_118 ] == V_764 )
V_102 -> V_929 [ V_118 ] =
V_2 ;
F_54 ( V_753 ) ;
F_279 ( V_763 , V_764 , NULL , 0 ) ;
} else {
V_763 -> V_765 [ V_764 ] . V_753 &=
~ V_862 ;
}
}
F_136 ( & V_7 -> V_861 ) ;
if ( V_925 )
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_75 ,
V_925 ) ;
if ( V_926 )
F_18 ( V_7 , V_470 , V_7 -> V_34 ,
L_76 , V_926 ) ;
else
V_21 -> V_252 = false ;
}
static void F_330 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
F_12 ( V_81 , V_872 ) ;
struct V_746 * V_753 ;
unsigned int V_764 ;
int V_23 ;
F_317 ( V_7 ) ;
V_7 -> V_112 = NULL ;
if ( ! F_318 ( & V_7 -> V_114 ) )
return;
if ( ! V_763 )
return;
for ( V_764 = 0 ; V_764 < V_3 ; V_764 ++ ) {
V_753 = F_277 ( V_763 , V_764 ) ;
if ( ! V_753 )
continue;
F_35 ( V_81 , V_772 ,
F_273 ( V_753 ) ?
V_879 :
V_873 ) ;
F_139 ( V_81 , V_825 ,
V_763 -> V_765 [ V_764 ] . V_818 ) ;
V_23 = F_29 ( V_7 , V_841 , V_81 ,
sizeof( V_81 ) , NULL , 0 , NULL ) ;
if ( V_23 )
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_77 ,
V_556 , V_764 ) ;
F_54 ( V_753 ) ;
}
F_331 ( V_763 -> V_765 ) ;
F_54 ( V_763 ) ;
}
static void F_332 ( struct V_6 * V_7 , T_20 * V_440 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
unsigned int V_764 ;
if ( * V_440 != V_2 ) {
V_764 = F_1 ( * V_440 ) ;
if ( ! V_763 -> V_765 [ V_764 ] . V_753 )
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_78 , * V_440 ,
V_764 ) ;
V_763 -> V_765 [ V_764 ] . V_753 |= V_871 ;
* V_440 = V_2 ;
}
}
static void F_333 ( struct V_6 * V_7 ,
struct V_904 * V_102 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < V_763 -> V_930 ; V_118 ++ )
F_332 ( V_7 , & V_102 -> V_931 [ V_118 ] ) ;
for ( V_118 = 0 ; V_118 < V_763 -> V_932 ; V_118 ++ )
F_332 ( V_7 , & V_102 -> V_933 [ V_118 ] ) ;
for ( V_118 = 0 ; V_118 < V_928 ; V_118 ++ )
F_332 ( V_7 , & V_102 -> V_929 [ V_118 ] ) ;
}
static void F_334 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_904 * V_102 ;
F_138 ( & V_7 -> V_861 ) ;
F_43 (vlan, &table->vlan_list, list)
F_333 ( V_7 , V_102 ) ;
F_136 ( & V_7 -> V_861 ) ;
}
static void F_335 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_916 * V_34 = V_7 -> V_34 ;
struct V_934 * V_931 ;
int V_935 ;
unsigned int V_118 ;
V_935 = F_336 ( V_34 ) ;
V_763 -> V_936 = ! ! ( V_34 -> V_259 & V_937 ) ;
V_763 -> V_930 = 1 + V_935 ;
F_32 ( V_763 -> V_938 [ 0 ] . V_337 , V_34 -> V_939 ) ;
V_118 = 1 ;
F_337 (uc, net_dev) {
if ( V_118 >= V_940 ) {
V_763 -> V_936 = true ;
break;
}
F_32 ( V_763 -> V_938 [ V_118 ] . V_337 , V_931 -> V_337 ) ;
V_118 ++ ;
}
}
static void F_338 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_916 * V_34 = V_7 -> V_34 ;
struct V_934 * V_933 ;
unsigned int V_118 , V_935 ;
V_763 -> V_941 = ! ! ( V_34 -> V_259 & ( V_937 | V_942 ) ) ;
V_935 = F_339 ( V_34 ) ;
V_118 = 0 ;
F_340 (mc, net_dev) {
if ( V_118 >= V_943 ) {
V_763 -> V_941 = true ;
break;
}
F_32 ( V_763 -> V_944 [ V_118 ] . V_337 , V_933 -> V_337 ) ;
V_118 ++ ;
}
V_763 -> V_932 = V_118 ;
}
static int F_341 ( struct V_6 * V_7 ,
struct V_904 * V_102 ,
bool V_312 , bool V_945 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_946 * V_947 ;
enum V_948 V_949 ;
struct V_746 V_753 ;
T_5 V_950 [ V_951 ] ;
unsigned int V_118 , V_952 ;
int V_935 ;
T_2 * V_953 ;
int V_23 ;
if ( V_312 ) {
V_947 = V_763 -> V_944 ;
V_935 = V_763 -> V_932 ;
V_953 = V_102 -> V_933 ;
} else {
V_947 = V_763 -> V_938 ;
V_935 = V_763 -> V_930 ;
V_953 = V_102 -> V_931 ;
}
V_949 = F_303 ( V_7 ) ? V_821 : 0 ;
for ( V_118 = 0 ; V_118 < V_935 ; V_118 ++ ) {
F_342 ( & V_753 , V_864 , V_949 , 0 ) ;
F_343 ( & V_753 , V_102 -> V_101 , V_947 [ V_118 ] . V_337 ) ;
V_23 = F_290 ( V_7 , & V_753 , true ) ;
if ( V_23 < 0 ) {
if ( V_945 ) {
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_79 ,
V_23 ) ;
for ( V_952 = 0 ; V_952 < V_118 ; V_952 ++ ) {
F_305 (
V_7 , V_864 ,
V_953 [ V_952 ] ) ;
V_953 [ V_952 ] = V_2 ;
}
return V_23 ;
} else {
V_23 = V_2 ;
}
}
V_953 [ V_118 ] = F_1 ( V_23 ) ;
}
if ( V_312 && V_945 ) {
F_312 ( V_102 -> V_929 [ V_954 ] !=
V_2 ) ;
F_342 ( & V_753 , V_864 , V_949 , 0 ) ;
F_344 ( V_950 ) ;
F_343 ( & V_753 , V_102 -> V_101 , V_950 ) ;
V_23 = F_290 ( V_7 , & V_753 , true ) ;
if ( V_23 < 0 ) {
F_46 ( V_7 , V_33 , V_7 -> V_34 ,
L_80 , V_23 ) ;
for ( V_952 = 0 ; V_952 < V_118 ; V_952 ++ ) {
F_305 (
V_7 , V_864 ,
V_953 [ V_952 ] ) ;
V_953 [ V_952 ] = V_2 ;
}
return V_23 ;
} else {
V_102 -> V_929 [ V_954 ] =
F_1 ( V_23 ) ;
}
}
return 0 ;
}
static int F_345 ( struct V_6 * V_7 ,
struct V_904 * V_102 ,
enum V_767 V_768 ,
bool V_312 , bool V_945 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
enum V_948 V_949 ;
struct V_746 V_753 ;
T_5 V_950 [ V_951 ] ;
int V_23 ;
T_2 * V_440 ;
V_949 = F_303 ( V_7 ) ? V_821 : 0 ;
F_342 ( & V_753 , V_864 , V_949 , 0 ) ;
if ( V_312 )
F_346 ( & V_753 ) ;
else
F_347 ( & V_753 ) ;
if ( V_768 ) {
if ( V_21 -> V_35 &
( 1 << V_691 ) )
F_348 ( & V_753 , V_768 ) ;
else
return 0 ;
}
if ( V_102 -> V_101 != V_148 )
F_343 ( & V_753 , V_102 -> V_101 , NULL ) ;
V_23 = F_290 ( V_7 , & V_753 , true ) ;
if ( V_23 < 0 ) {
const char * V_955 = V_312 ? L_81 : L_82 ;
const char * V_956 = L_83 ;
const char * V_957 = L_83 ;
if ( ( V_768 & V_779 ) ==
V_780 )
V_956 = L_84 ;
else if ( ( V_768 & V_779 ) ==
V_788 )
V_956 = L_85 ;
else if ( ( V_768 & V_779 ) ==
V_782 )
V_956 = L_86 ;
if ( V_768 & V_775 )
V_957 = L_87 ;
else if ( V_768 )
V_957 = L_88 ;
F_349 ( V_7 , V_33 , V_7 -> V_34 ,
V_23 == - V_73 && ( V_768 || ! V_312 ) , V_958 ,
L_89 ,
V_956 , V_957 , V_955 , V_23 ) ;
} else if ( V_312 ) {
static enum V_959 V_960 [] = {
[ V_961 ] = V_962 ,
[ V_780 ] = V_963 ,
[ V_788 ] = V_964 ,
[ V_782 ] = V_965 ,
[ V_780 | V_775 ] =
V_966 ,
[ V_788 | V_775 ] =
V_967 ,
[ V_782 | V_775 ] =
V_968 ,
} ;
F_17 ( V_954 != 0 ) ;
if ( V_768 >= F_209 ( V_960 ) || V_960 [ V_768 ] == 0 ) {
F_36 ( 1 ) ;
return - V_270 ;
}
V_440 = & V_102 -> V_929 [ V_960 [ V_768 ] ] ;
F_312 ( * V_440 != V_2 ) ;
* V_440 = F_1 ( V_23 ) ;
if ( ! V_21 -> V_642 && ! V_768 ) {
F_342 ( & V_753 , V_864 ,
V_949 , 0 ) ;
F_344 ( V_950 ) ;
F_343 ( & V_753 , V_102 -> V_101 , V_950 ) ;
V_23 = F_290 ( V_7 , & V_753 , true ) ;
if ( V_23 < 0 ) {
F_46 ( V_7 , V_33 , V_7 -> V_34 ,
L_80 ,
V_23 ) ;
if ( V_945 ) {
F_305 (
V_7 , V_864 ,
* V_440 ) ;
* V_440 = V_2 ;
return V_23 ;
}
} else {
F_312 (
V_102 -> V_929 [ V_954 ] !=
V_2 ) ;
V_102 -> V_929 [ V_954 ] =
F_1 ( V_23 ) ;
}
}
V_23 = 0 ;
} else {
static enum V_959 V_960 [] = {
[ V_961 ] = V_969 ,
[ V_780 ] = V_970 ,
[ V_788 ] = V_971 ,
[ V_782 ] = V_972 ,
[ V_780 | V_775 ] =
V_973 ,
[ V_788 | V_775 ] =
V_974 ,
[ V_782 | V_775 ] =
V_975 ,
} ;
F_17 ( V_954 != 0 ) ;
if ( V_768 >= F_209 ( V_960 ) || V_960 [ V_768 ] == 0 ) {
F_36 ( 1 ) ;
return - V_270 ;
}
V_440 = & V_102 -> V_929 [ V_960 [ V_768 ] ] ;
F_312 ( * V_440 != V_2 ) ;
* V_440 = V_23 ;
V_23 = 0 ;
}
return V_23 ;
}
static void F_350 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
int V_976 = 0 ;
int V_977 = 0 ;
int V_23 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_3 ; V_118 ++ ) {
if ( F_163 ( V_763 -> V_765 [ V_118 ] . V_753 ) &
V_871 ) {
V_23 = F_302 ( V_7 ,
1U << V_864 , V_118 , true ) ;
if ( V_23 == - V_116 )
V_977 ++ ;
else if ( V_23 )
V_976 ++ ;
}
}
if ( V_976 )
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_90 ,
V_556 , V_976 ) ;
if ( V_977 )
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_91 ,
V_556 , V_977 ) ;
}
static int F_351 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
T_5 V_978 [ V_951 ] ;
int V_23 , V_979 ;
if ( F_352 ( V_21 -> V_980 ) )
return 0 ;
F_353 ( V_7 ) ;
F_354 ( V_7 -> V_34 ) ;
F_49 ( & V_7 -> V_114 ) ;
F_330 ( V_7 ) ;
F_51 ( & V_7 -> V_114 ) ;
V_23 = F_100 ( V_7 , V_21 -> V_128 ) ;
if ( V_23 )
goto V_981;
F_32 ( V_978 , V_21 -> V_980 ) ;
V_23 = F_102 ( V_7 , V_21 -> V_128 ,
V_21 -> V_980 ) ;
if ( V_23 )
goto V_982;
V_23 = F_101 ( V_7 , V_21 -> V_128 ,
V_7 -> V_34 -> V_939 ) ;
if ( ! V_23 ) {
F_32 ( V_21 -> V_980 , V_7 -> V_34 -> V_939 ) ;
} else {
V_979 = F_101 ( V_7 , V_21 -> V_128 , V_978 ) ;
if ( V_979 ) {
F_355 ( V_21 -> V_980 ) ;
goto V_983;
}
}
V_982:
V_979 = F_99 ( V_7 , V_21 -> V_128 ) ;
if ( V_979 )
goto V_983;
V_981:
F_49 ( & V_7 -> V_114 ) ;
V_979 = F_324 ( V_7 ) ;
F_51 ( & V_7 -> V_114 ) ;
if ( V_979 )
goto V_983;
V_979 = F_356 ( V_7 -> V_34 ) ;
if ( V_979 )
goto V_983;
F_357 ( V_7 ) ;
return V_23 ;
V_983:
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_92 ) ;
F_237 ( V_7 , V_258 ) ;
return V_23 ? V_23 : V_979 ;
}
static void F_358 ( struct V_6 * V_7 ,
struct V_904 * V_102 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_20 * V_21 = V_7 -> V_21 ;
if ( ( V_102 -> V_101 == V_148 ) == V_763 -> V_923 )
return;
if ( V_763 -> V_936 ) {
F_345 ( V_7 , V_102 , V_961 ,
false , false ) ;
F_341 ( V_7 , V_102 , false , false ) ;
} else {
if ( F_341 ( V_7 , V_102 , false , false ) )
F_345 ( V_7 , V_102 ,
V_961 ,
false , false ) ;
}
F_345 ( V_7 , V_102 , V_780 ,
false , false ) ;
F_345 ( V_7 , V_102 , V_780 |
V_775 ,
false , false ) ;
F_345 ( V_7 , V_102 , V_788 ,
false , false ) ;
F_345 ( V_7 , V_102 , V_788 |
V_775 ,
false , false ) ;
F_345 ( V_7 , V_102 , V_782 ,
false , false ) ;
F_345 ( V_7 , V_102 , V_782 |
V_775 ,
false , false ) ;
if ( V_21 -> V_642 &&
V_763 -> V_922 != V_763 -> V_941 )
F_350 ( V_7 ) ;
if ( V_763 -> V_941 ) {
if ( V_21 -> V_642 ) {
if ( F_345 ( V_7 , V_102 ,
V_961 ,
true , true ) ) {
F_350 ( V_7 ) ;
F_341 ( V_7 , V_102 ,
true , false ) ;
}
} else {
F_345 ( V_7 , V_102 ,
V_961 ,
true , false ) ;
F_341 ( V_7 , V_102 , true , false ) ;
}
} else {
if ( F_341 ( V_7 , V_102 , true , true ) ) {
if ( V_21 -> V_642 )
F_350 ( V_7 ) ;
if ( F_345 ( V_7 , V_102 ,
V_961 ,
true , true ) )
F_341 ( V_7 , V_102 ,
true , false ) ;
}
}
F_345 ( V_7 , V_102 , V_780 ,
true , false ) ;
F_345 ( V_7 , V_102 , V_780 |
V_775 ,
true , false ) ;
F_345 ( V_7 , V_102 , V_788 ,
true , false ) ;
F_345 ( V_7 , V_102 , V_788 |
V_775 ,
true , false ) ;
F_345 ( V_7 , V_102 , V_782 ,
true , false ) ;
F_345 ( V_7 , V_102 , V_782 |
V_775 ,
true , false ) ;
}
static void F_359 ( struct V_6 * V_7 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_916 * V_34 = V_7 -> V_34 ;
struct V_904 * V_102 ;
bool V_923 ;
if ( ! F_360 ( V_7 ) )
return;
if ( ! V_763 )
return;
F_334 ( V_7 ) ;
F_361 ( V_34 ) ;
F_335 ( V_7 ) ;
F_338 ( V_7 ) ;
F_362 ( V_34 ) ;
V_923 = ! ! ( V_34 -> V_919 & V_917 ) ;
if ( V_763 -> V_923 != V_923 ) {
V_763 -> V_923 = V_923 ;
F_350 ( V_7 ) ;
}
F_43 (vlan, &table->vlan_list, list)
F_358 ( V_7 , V_102 ) ;
F_350 ( V_7 ) ;
V_763 -> V_922 = V_763 -> V_941 ;
}
static struct V_904 * F_363 ( struct V_6 * V_7 , T_2 V_101 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_904 * V_102 ;
F_36 ( ! F_329 ( & V_7 -> V_114 ) ) ;
F_43 (vlan, &table->vlan_list, list) {
if ( V_102 -> V_101 == V_101 )
return V_102 ;
}
return NULL ;
}
static int F_50 ( struct V_6 * V_7 , T_2 V_101 )
{
struct V_762 * V_763 = V_7 -> V_112 ;
struct V_904 * V_102 ;
unsigned int V_118 ;
if ( ! F_318 ( & V_7 -> V_114 ) )
return - V_270 ;
V_102 = F_363 ( V_7 , V_101 ) ;
if ( F_36 ( V_102 ) ) {
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_9 , V_101 ) ;
return - V_105 ;
}
V_102 = F_47 ( sizeof( * V_102 ) , V_108 ) ;
if ( ! V_102 )
return - V_107 ;
V_102 -> V_101 = V_101 ;
for ( V_118 = 0 ; V_118 < F_209 ( V_102 -> V_931 ) ; V_118 ++ )
V_102 -> V_931 [ V_118 ] = V_2 ;
for ( V_118 = 0 ; V_118 < F_209 ( V_102 -> V_933 ) ; V_118 ++ )
V_102 -> V_933 [ V_118 ] = V_2 ;
for ( V_118 = 0 ; V_118 < V_928 ; V_118 ++ )
V_102 -> V_929 [ V_118 ] = V_2 ;
F_48 ( & V_102 -> V_110 , & V_763 -> V_111 ) ;
if ( F_360 ( V_7 ) )
F_358 ( V_7 , V_102 ) ;
return 0 ;
}
static void F_319 ( struct V_6 * V_7 ,
struct V_904 * V_102 )
{
unsigned int V_118 ;
if ( ! F_318 ( & V_7 -> V_114 ) )
return;
F_53 ( & V_102 -> V_110 ) ;
for ( V_118 = 0 ; V_118 < F_209 ( V_102 -> V_931 ) ; V_118 ++ )
F_305 ( V_7 , V_864 ,
V_102 -> V_931 [ V_118 ] ) ;
for ( V_118 = 0 ; V_118 < F_209 ( V_102 -> V_933 ) ; V_118 ++ )
F_305 ( V_7 , V_864 ,
V_102 -> V_933 [ V_118 ] ) ;
for ( V_118 = 0 ; V_118 < V_928 ; V_118 ++ )
if ( V_102 -> V_929 [ V_118 ] != V_2 )
F_305 ( V_7 , V_864 ,
V_102 -> V_929 [ V_118 ] ) ;
F_54 ( V_102 ) ;
}
static void F_56 ( struct V_6 * V_7 , T_2 V_101 )
{
struct V_904 * V_102 ;
if ( ! F_318 ( & V_7 -> V_114 ) )
return;
V_102 = F_363 ( V_7 , V_101 ) ;
if ( ! V_102 ) {
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_93 , V_101 ) ;
return;
}
F_319 ( V_7 , V_102 ) ;
}
static int F_364 ( struct V_6 * V_7 )
{
F_12 ( V_81 , V_984 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
bool V_985 = V_7 -> V_986 ;
int V_23 ;
F_353 ( V_7 ) ;
F_354 ( V_7 -> V_34 ) ;
F_45 ( & V_7 -> V_113 ) ;
F_49 ( & V_7 -> V_114 ) ;
F_330 ( V_7 ) ;
F_32 ( F_33 ( V_81 , V_987 ) ,
V_7 -> V_34 -> V_939 ) ;
F_35 ( V_81 , V_988 ,
V_21 -> V_128 ) ;
V_23 = F_29 ( V_7 , V_989 , V_81 ,
sizeof( V_81 ) , NULL , 0 , NULL ) ;
F_324 ( V_7 ) ;
F_51 ( & V_7 -> V_114 ) ;
F_52 ( & V_7 -> V_113 ) ;
if ( V_985 )
F_356 ( V_7 -> V_34 ) ;
F_357 ( V_7 ) ;
#ifdef F_74
if ( V_7 -> V_15 -> V_194 && V_7 -> V_15 -> V_143 ) {
struct V_15 * V_145 = V_7 -> V_15 -> V_143 ;
if ( V_23 == - V_73 ) {
struct V_6 * V_146 ;
V_146 = F_38 ( V_145 ) ;
V_23 = F_365 ( V_146 ,
V_21 -> V_27 ,
V_7 -> V_34 -> V_939 ) ;
} else if ( ! V_23 ) {
struct V_6 * V_146 = F_38 ( V_145 ) ;
struct V_20 * V_21 = V_146 -> V_21 ;
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < V_146 -> V_254 ; ++ V_118 ) {
struct V_192 * V_193 = V_21 -> V_193 + V_118 ;
if ( V_193 -> V_7 == V_7 ) {
F_32 ( V_193 -> V_214 ,
V_7 -> V_34 -> V_939 ) ;
return 0 ;
}
}
}
} else
#endif
if ( V_23 == - V_73 ) {
F_18 ( V_7 , V_33 , V_7 -> V_34 ,
L_94
L_95 ) ;
} else if ( V_23 == - V_57 && ! F_10 ( V_7 ) ) {
V_23 = F_351 ( V_7 ) ;
} else {
F_30 ( V_7 , V_989 ,
sizeof( V_81 ) , NULL , 0 , V_23 ) ;
}
return V_23 ;
}
static int F_366 ( struct V_6 * V_7 )
{
F_359 ( V_7 ) ;
return F_367 ( V_7 ) ;
}
static int F_368 ( struct V_6 * V_7 )
{
F_359 ( V_7 ) ;
return 0 ;
}
static int F_369 ( struct V_6 * V_7 , T_1 V_990 )
{
F_12 ( V_81 , V_991 ) ;
F_35 ( V_81 , V_992 , V_990 ) ;
return F_13 ( V_7 , V_993 , V_81 , sizeof( V_81 ) ,
NULL , 0 , NULL ) ;
}
static int F_370 ( struct V_6 * V_7 )
{
int V_23 ;
F_12 ( V_18 , V_994 ) ;
T_4 V_22 ;
T_1 V_995 ;
V_23 = F_13 ( V_7 , V_996 , NULL , 0 ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( V_22 < V_994 )
return - V_12 ;
V_995 = F_14 ( V_18 , V_997 ) ;
switch ( V_995 ) {
case V_998 :
F_24 ( V_7 , V_470 , V_7 -> V_34 , L_96 ) ;
return 0 ;
case V_999 :
F_18 ( V_7 , V_470 , V_7 -> V_34 , L_97 ) ;
return - V_12 ;
case V_1000 :
F_18 ( V_7 , V_470 , V_7 -> V_34 , L_98 ) ;
return - V_12 ;
default:
F_18 ( V_7 , V_470 , V_7 -> V_34 ,
L_99 , V_995 ) ;
return - V_12 ;
}
}
static int F_371 ( struct V_6 * V_7 , T_1 V_990 )
{
int V_23 ;
F_24 ( V_7 , V_33 , V_7 -> V_34 , L_100 , V_990 ) ;
V_23 = F_369 ( V_7 , V_990 ) ;
if ( V_23 != 0 )
return V_23 ;
return F_370 ( V_7 ) ;
}
static int
F_372 ( struct V_6 * V_7 , struct V_1001 * V_1002 )
{
int V_23 , V_979 ;
F_373 ( V_7 , V_269 ) ;
V_23 = F_13 ( V_7 , V_1003 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_23 != 0 )
goto V_360;
V_1002 -> V_1004 = F_371 ( V_7 , V_1005 ) ? - 1 : 1 ;
V_1002 -> V_1006 = F_371 ( V_7 , V_1007 ) ? - 1 : 1 ;
V_23 = F_68 ( V_7 , V_269 ) ;
V_360:
if ( V_23 == - V_73 )
V_23 = 0 ;
V_979 = F_374 ( V_7 , V_269 , V_23 == 0 ) ;
return V_23 ? V_23 : V_979 ;
}
static int F_375 ( struct V_6 * V_7 ,
struct V_1008 * V_1009 ,
unsigned int type )
{
F_12 ( V_81 , V_1010 ) ;
F_12 ( V_18 , V_1011 ) ;
const struct V_1012 * V_1013 ;
T_4 V_882 , V_1014 , V_22 ;
bool V_1015 ;
int V_23 ;
for ( V_1013 = V_1016 ; ; V_1013 ++ ) {
if ( V_1013 ==
V_1016 + F_209 ( V_1016 ) )
return - V_48 ;
if ( ( type & ~ V_1013 -> V_1017 ) == V_1013 -> type )
break;
}
if ( V_1013 -> V_1018 != F_376 ( V_7 ) )
return - V_48 ;
V_23 = F_377 ( V_7 , type , & V_882 , & V_1014 , & V_1015 ) ;
if ( V_23 )
return V_23 ;
if ( V_1015 )
return - V_48 ;
V_1009 -> V_1019 = type ;
F_35 ( V_81 , V_1020 , type ) ;
V_23 = F_13 ( V_7 , V_1021 , V_81 , sizeof( V_81 ) ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < V_1022 )
return - V_12 ;
if ( F_14 ( V_18 , V_1023 ) &
( 1 << V_1024 ) )
V_1009 -> V_1025 = F_14 ( V_18 ,
V_1026 ) ;
V_1009 -> V_1027 . V_1028 = L_101 ;
V_1009 -> V_1027 . V_1029 = V_1013 -> V_293 ;
V_1009 -> V_1027 . V_1030 . type = V_1031 ;
V_1009 -> V_1027 . V_1030 . V_259 = V_1032 ;
V_1009 -> V_1027 . V_1030 . V_882 = V_882 ;
V_1009 -> V_1027 . V_1030 . V_1033 = V_1014 ;
return 0 ;
}
static int F_378 ( struct V_6 * V_7 )
{
F_12 ( V_18 , V_1034 ) ;
struct V_1008 * V_1035 ;
T_4 V_22 , V_1036 , V_118 , V_1037 ;
unsigned int type ;
int V_23 ;
F_379 () ;
F_17 ( V_1038 != 0 ) ;
V_23 = F_13 ( V_7 , V_1039 , NULL , 0 ,
V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 < V_1040 )
return - V_12 ;
V_1036 = F_14 ( V_18 , V_1041 ) ;
if ( V_1036 >
F_322 ( V_22 , V_1042 ) )
return - V_12 ;
V_1035 = F_380 ( V_1036 , sizeof( * V_1035 ) , V_108 ) ;
if ( ! V_1035 )
return - V_107 ;
V_1037 = 0 ;
for ( V_118 = 0 ; V_118 < V_1036 ; V_118 ++ ) {
type = F_323 ( V_18 , V_1042 ,
V_118 ) ;
V_23 = F_375 ( V_7 , & V_1035 [ V_1037 ] , type ) ;
if ( V_23 == 0 )
V_1037 ++ ;
else if ( V_23 != - V_48 )
goto V_178;
}
V_23 = F_381 ( V_7 , & V_1035 [ 0 ] . V_1027 , V_1037 , sizeof( * V_1035 ) ) ;
V_178:
if ( V_23 )
F_54 ( V_1035 ) ;
return V_23 ;
}
static void F_382 ( struct V_6 * V_7 , T_1 V_1043 )
{
F_64 ( V_7 , F_65 ( V_1043 ) , V_392 ) ;
}
static void F_383 ( struct V_6 * V_7 ,
T_1 V_1043 ) {}
static int F_384 ( struct V_166 * V_167 ,
bool V_1044 )
{
F_12 ( V_81 , V_1045 ) ;
int V_23 ;
if ( V_167 -> V_1046 == V_1047 ||
V_167 -> V_1046 == V_1048 ||
( V_1044 && V_167 -> V_1046 == V_1049 ) )
return 0 ;
V_167 -> V_1046 = V_1047 ;
F_35 ( V_81 , V_1050 , V_1051 ) ;
F_35 ( V_81 , V_1052 , 0 ) ;
F_35 ( V_81 , V_1053 ,
V_167 -> V_167 ) ;
V_23 = F_13 ( V_167 -> V_7 , V_1054 ,
V_81 , sizeof( V_81 ) , NULL , 0 , NULL ) ;
if ( V_23 != 0 )
V_167 -> V_1046 = V_1044 ? V_1055 :
V_1049 ;
return V_23 ;
}
static int F_385 ( struct V_166 * V_167 ,
bool V_1044 )
{
F_12 ( V_81 , V_1056 ) ;
int V_23 ;
if ( V_167 -> V_1046 == V_1049 ||
( V_1044 && V_167 -> V_1046 == V_1055 ) )
return 0 ;
if ( V_167 -> V_1046 == V_1055 ) {
V_167 -> V_1046 = V_1049 ;
return 0 ;
}
V_167 -> V_1046 = V_1044 ? V_1055 :
V_1049 ;
F_35 ( V_81 , V_1050 , V_1057 ) ;
F_35 ( V_81 , V_1052 , 0 ) ;
F_35 ( V_81 , V_1058 ,
V_1059 ) ;
F_35 ( V_81 , V_1060 ,
V_167 -> V_167 ) ;
V_23 = F_13 ( V_167 -> V_7 , V_1054 ,
V_81 , sizeof( V_81 ) , NULL , 0 , NULL ) ;
return V_23 ;
}
static int F_386 ( struct V_6 * V_7 , bool V_1061 ,
bool V_1044 )
{
int (* F_387)( struct V_166 * V_167 , bool V_1044 );
struct V_166 * V_167 ;
F_387 = V_1061 ?
F_384 :
F_385 ;
F_89 (channel, efx) {
int V_23 = F_387 ( V_167 , V_1044 ) ;
if ( V_1061 && V_23 != 0 ) {
F_386 ( V_7 , false , V_1044 ) ;
return V_23 ;
}
}
return 0 ;
}
static int F_388 ( struct V_6 * V_7 ,
struct V_1062 * V_1063 )
{
return - V_383 ;
}
static int F_389 ( struct V_6 * V_7 ,
struct V_1062 * V_1063 )
{
int V_23 ;
switch ( V_1063 -> V_1064 ) {
case V_1065 :
F_386 ( V_7 , false , false ) ;
return F_390 ( V_7 ,
V_1063 -> V_1066 != V_1067 , 0 ) ;
case V_1068 :
case V_1069 :
case V_1070 :
case V_1071 :
case V_1072 :
case V_1073 :
case V_1074 :
case V_1075 :
case V_1076 :
case V_1077 :
case V_1078 :
case V_1079 :
case V_1080 :
V_1063 -> V_1064 = V_1068 ;
V_23 = F_390 ( V_7 , true , 0 ) ;
if ( ! V_23 )
V_23 = F_386 ( V_7 , true , false ) ;
if ( V_23 )
F_390 ( V_7 , false , 0 ) ;
return V_23 ;
default:
return - V_52 ;
}
}
static int F_391 ( struct V_6 * V_7 ,
struct V_1081 * V_1082 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
if ( ! F_392 ( V_21 -> V_147 ) )
return - V_383 ;
V_1082 -> V_1083 = V_951 ;
memcpy ( V_1082 -> V_440 , V_21 -> V_147 , V_1082 -> V_1083 ) ;
return 0 ;
}
static int F_393 ( struct V_6 * V_7 , T_17 V_1084 , T_2 V_101 )
{
if ( V_1084 != F_275 ( V_1085 ) )
return - V_270 ;
return F_44 ( V_7 , V_101 ) ;
}
static int F_394 ( struct V_6 * V_7 , T_17 V_1084 , T_2 V_101 )
{
if ( V_1084 != F_275 ( V_1085 ) )
return - V_270 ;
return F_57 ( V_7 , V_101 ) ;
}
static int F_81 ( struct V_6 * V_7 , bool V_1086 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
F_12 ( V_81 , V_1087 ) ;
F_12 ( V_18 , V_1088 ) ;
bool V_1089 = false ;
T_4 V_1090 = 0 ;
T_4 V_468 , V_22 ;
T_4 V_118 ;
int V_23 ;
T_3 V_1091 ;
F_36 ( ! F_42 ( & V_21 -> V_130 ) ) ;
V_21 -> V_1092 = false ;
if ( ! ( V_21 -> V_35 &
( 1 << V_691 ) ) ) {
F_357 ( V_7 ) ;
return 0 ;
}
F_17 ( F_209 ( V_21 -> V_151 ) >
V_1093 ) ;
for ( V_118 = 0 ; V_118 < F_209 ( V_21 -> V_151 ) ; ++ V_118 ) {
if ( V_21 -> V_151 [ V_118 ] . V_881 &&
V_21 -> V_151 [ V_118 ] . V_1018 ) {
T_3 V_765 ;
F_148 ( V_765 ,
V_1094 ,
F_178 ( V_21 -> V_151 [ V_118 ] . V_1018 ) ,
V_1095 ,
V_21 -> V_151 [ V_118 ] . type ) ;
* F_395 ( V_81 ,
V_1096 ,
V_1090 ++ ) = V_765 ;
}
}
F_17 ( ( V_1097 -
V_1098 ) * 8 !=
V_1099 ) ;
F_17 ( V_1100 * 8 !=
V_1101 ) ;
F_148 ( V_1091 ,
V_1102 ,
! ! V_1086 ,
V_10 , V_1090 ) ;
* F_396 ( V_81 , V_1103 ) =
V_1091 ;
V_468 = F_397 ( V_1090 ) ;
V_23 = F_29 ( V_7 , V_1104 ,
V_81 , V_468 , V_18 , sizeof( V_18 ) , & V_22 ) ;
if ( V_23 == - V_12 ) {
V_21 -> V_1092 = true ;
return 0 ;
}
if ( V_23 ) {
if ( V_23 != - V_73 )
F_46 ( V_7 , V_33 , V_7 -> V_34 ,
L_102 , V_23 ) ;
} else if ( F_14 ( V_18 , V_1105 ) &
( 1 << V_1106 ) ) {
F_94 ( V_7 , V_33 , V_7 -> V_34 ,
L_103 ) ;
V_1089 = true ;
if ( V_1086 )
F_398 ( 100 ) ;
}
if ( ! V_1089 && ! V_1086 ) {
F_357 ( V_7 ) ;
}
return V_23 ;
}
static int F_399 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
int V_23 = 0 ;
F_45 ( & V_21 -> V_130 ) ;
if ( V_21 -> V_1092 ) {
F_353 ( V_7 ) ;
V_23 = F_81 ( V_7 , false ) ;
}
F_52 ( & V_21 -> V_130 ) ;
return V_23 ;
}
static struct V_1107 * F_400 ( struct V_6 * V_7 ,
T_17 V_1018 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
T_4 V_118 ;
for ( V_118 = 0 ; V_118 < F_209 ( V_21 -> V_151 ) ; ++ V_118 ) {
if ( ! V_21 -> V_151 [ V_118 ] . V_881 )
continue;
if ( V_21 -> V_151 [ V_118 ] . V_1018 == V_1018 )
return & V_21 -> V_151 [ V_118 ] ;
}
return NULL ;
}
static int F_401 ( struct V_6 * V_7 ,
struct V_1107 V_1108 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_1107 * V_1109 ;
char V_1110 [ 8 ] ;
T_4 V_118 ;
int V_23 ;
if ( ! ( V_21 -> V_35 &
( 1 << V_691 ) ) )
return 0 ;
F_402 ( V_1108 . type , V_1110 , sizeof( V_1110 ) ) ;
F_24 ( V_7 , V_33 , V_7 -> V_34 , L_104 ,
V_1110 , F_178 ( V_1108 . V_1018 ) ) ;
F_45 ( & V_21 -> V_130 ) ;
F_353 ( V_7 ) ;
V_1109 = F_400 ( V_7 , V_1108 . V_1018 ) ;
if ( V_1109 != NULL ) {
if ( V_1109 -> type == V_1108 . type ) {
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_105 ) ;
V_1109 -> V_881 ++ ;
V_23 = 0 ;
goto V_1111;
}
F_402 ( V_1109 -> type ,
V_1110 , sizeof( V_1110 ) ) ;
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_106 ,
F_178 ( V_1108 . V_1018 ) , V_1110 ) ;
V_23 = - V_866 ;
goto V_1111;
}
for ( V_118 = 0 ; V_118 < F_209 ( V_21 -> V_151 ) ; ++ V_118 )
if ( ! V_21 -> V_151 [ V_118 ] . V_881 ) {
V_21 -> V_151 [ V_118 ] = V_1108 ;
V_21 -> V_151 [ V_118 ] . V_881 = 1 ;
V_23 = F_81 ( V_7 , false ) ;
goto V_1111;
}
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_107 ,
V_1110 , F_178 ( V_1108 . V_1018 ) ) ;
V_23 = - V_107 ;
V_1111:
F_52 ( & V_21 -> V_130 ) ;
return V_23 ;
}
static bool F_403 ( struct V_6 * V_7 , T_17 V_1018 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
if ( ! ( V_21 -> V_35 &
( 1 << V_691 ) ) )
return false ;
if ( V_21 -> V_1092 )
return false ;
return F_400 ( V_7 , V_1018 ) != NULL ;
}
static int F_404 ( struct V_6 * V_7 ,
struct V_1107 V_1108 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_1107 * V_1109 ;
char V_1110 [ 8 ] ;
int V_23 ;
if ( ! ( V_21 -> V_35 &
( 1 << V_691 ) ) )
return 0 ;
F_402 ( V_1108 . type , V_1110 , sizeof( V_1110 ) ) ;
F_24 ( V_7 , V_33 , V_7 -> V_34 , L_108 ,
V_1110 , F_178 ( V_1108 . V_1018 ) ) ;
F_45 ( & V_21 -> V_130 ) ;
F_353 ( V_7 ) ;
V_1109 = F_400 ( V_7 , V_1108 . V_1018 ) ;
if ( V_1109 != NULL ) {
if ( V_1109 -> type == V_1108 . type ) {
if ( -- V_1109 -> V_881 ) {
F_24 ( V_7 , V_33 , V_7 -> V_34 ,
L_109 ,
F_178 ( V_1108 . V_1018 ) ) ;
V_23 = 0 ;
goto V_865;
}
V_23 = F_81 ( V_7 , false ) ;
goto V_865;
}
F_402 ( V_1109 -> type ,
V_1110 , sizeof( V_1110 ) ) ;
F_46 ( V_7 , V_33 , V_7 -> V_34 ,
L_110 ,
F_178 ( V_1108 . V_1018 ) , V_1110 ) ;
}
V_23 = - V_116 ;
V_865:
F_52 ( & V_21 -> V_130 ) ;
return V_23 ;
}
