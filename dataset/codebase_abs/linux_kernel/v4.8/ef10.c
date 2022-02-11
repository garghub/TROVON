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
static struct V_66 * F_27 ( struct V_1 * V_2 , T_5 V_67 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_66 * V_68 ;
F_22 ( ! F_28 ( & V_16 -> V_69 ) ) ;
F_29 (vlan, &nic_data->vlan_list, list) {
if ( V_68 -> V_67 == V_67 )
return V_68 ;
}
return NULL ;
}
static int F_30 ( struct V_1 * V_2 , T_5 V_67 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_66 * V_68 ;
int V_18 ;
F_31 ( & V_16 -> V_69 ) ;
V_68 = F_27 ( V_2 , V_67 ) ;
if ( V_68 ) {
if ( V_67 == 0 )
goto V_70;
F_32 ( V_2 , V_27 , V_2 -> V_28 ,
L_4 , V_67 ) ;
V_18 = - V_71 ;
goto V_72;
}
V_18 = - V_73 ;
V_68 = F_33 ( sizeof( * V_68 ) , V_74 ) ;
if ( ! V_68 )
goto V_75;
V_68 -> V_67 = V_67 ;
F_34 ( & V_68 -> V_76 , & V_16 -> V_77 ) ;
if ( V_2 -> V_78 ) {
F_31 ( & V_2 -> V_79 ) ;
F_35 ( & V_2 -> V_80 ) ;
V_18 = F_36 ( V_2 , V_68 -> V_67 ) ;
F_37 ( & V_2 -> V_80 ) ;
F_38 ( & V_2 -> V_79 ) ;
if ( V_18 )
goto V_81;
}
V_70:
F_38 ( & V_16 -> V_69 ) ;
return 0 ;
V_81:
F_39 ( & V_68 -> V_76 ) ;
F_40 ( V_68 ) ;
V_75:
V_72:
F_38 ( & V_16 -> V_69 ) ;
return V_18 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_66 * V_68 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_22 ( ! F_28 ( & V_16 -> V_69 ) ) ;
if ( V_2 -> V_78 ) {
F_35 ( & V_2 -> V_80 ) ;
F_42 ( V_2 , V_68 -> V_67 ) ;
F_37 ( & V_2 -> V_80 ) ;
}
F_39 ( & V_68 -> V_76 ) ;
F_40 ( V_68 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_5 V_67 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_66 * V_68 ;
int V_18 = 0 ;
if ( V_67 == 0 )
return 0 ;
F_31 ( & V_16 -> V_69 ) ;
V_68 = F_27 ( V_2 , V_67 ) ;
if ( ! V_68 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_5 , V_67 ) ;
V_18 = - V_82 ;
} else {
F_41 ( V_2 , V_68 ) ;
}
F_38 ( & V_16 -> V_69 ) ;
return V_18 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_66 * V_68 , * V_83 ;
F_31 ( & V_16 -> V_69 ) ;
F_45 (vlan, next_vlan, &nic_data->vlan_list, list)
F_41 ( V_2 , V_68 ) ;
F_38 ( & V_16 -> V_69 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_84 * V_28 = V_2 -> V_28 ;
int V_85 , V_18 ;
V_2 -> V_86 = F_47 (unsigned int,
EFX_MAX_CHANNELS,
efx_ef10_mem_map_size(efx) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES)) ;
V_2 -> V_87 = V_2 -> V_86 ;
if ( F_22 ( V_2 -> V_86 == 0 ) )
return - V_7 ;
V_16 = F_33 ( sizeof( * V_16 ) , V_74 ) ;
if ( ! V_16 )
return - V_73 ;
V_2 -> V_16 = V_16 ;
F_13 ( V_88 % 4 ) ;
V_18 = F_48 ( V_2 , & V_16 -> V_89 ,
8 + V_88 , V_74 ) ;
if ( V_18 )
goto V_90;
V_85 = 0 ;
for (; ; ) {
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 )
break;
if ( ++ V_85 == 5 )
goto V_91;
F_49 ( 1 ) ;
}
V_16 -> V_92 = V_18 ;
V_16 -> V_93 = V_94 ;
V_16 -> V_95 = V_52 ;
F_50 ( V_2 , F_51 ( 1 ) , V_96 ) ;
V_18 = F_52 ( V_2 ) ;
if ( V_18 )
goto V_91;
V_18 = F_53 ( V_2 , V_97 ) ;
if ( V_18 )
goto V_98;
V_18 = F_54 ( V_2 , true , false , 0 ) ;
if ( V_18 )
goto V_98;
V_18 = F_55 ( & V_2 -> V_10 -> V_58 ,
& V_99 ) ;
if ( V_18 )
goto V_98;
V_18 = F_55 ( & V_2 -> V_10 -> V_58 , & V_100 ) ;
if ( V_18 )
goto V_101;
V_18 = F_7 ( V_2 ) ;
if ( V_18 )
goto V_102;
V_18 = F_12 ( V_2 ) ;
if ( V_18 < 0 )
goto V_102;
V_2 -> V_103 =
V_104 - V_105 ;
V_18 = F_56 ( V_2 ) ;
if ( V_18 < 0 )
goto V_102;
V_2 -> V_106 = V_18 ;
V_28 -> V_107 = V_18 ;
V_18 = V_2 -> type -> V_108 ( V_2 , V_2 -> V_28 -> V_109 ) ;
if ( V_18 )
goto V_102;
V_18 = F_16 ( V_2 ) ;
if ( V_18 < 0 )
goto V_102;
V_2 -> V_110 = 1536000 / V_18 ;
V_18 = F_57 ( V_2 , V_111 , true , NULL ) ;
if ( V_18 == 0 ) {
V_16 -> V_112 = true ;
} else if ( V_18 == - V_113 ) {
unsigned int V_114 ;
V_18 = F_58 ( V_2 , NULL , & V_114 ) ;
if ( V_18 )
goto V_98;
V_16 -> V_112 = V_114 &
V_115 ;
} else if ( V_18 != - V_116 && V_18 != - V_82 ) {
goto V_102;
}
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_6 ,
V_16 -> V_112 ? L_7 : L_8 ) ;
V_18 = F_60 ( V_2 ) ;
if ( V_18 && V_18 != - V_113 )
goto V_102;
F_61 ( V_2 , NULL ) ;
#ifdef F_62
if ( ( V_2 -> V_10 -> V_117 ) && ( ! V_2 -> V_10 -> V_118 ) ) {
struct V_10 * V_119 = V_2 -> V_10 -> V_117 ;
struct V_1 * V_120 = F_24 ( V_119 ) ;
V_120 -> type -> V_108 ( V_120 , V_16 -> V_121 ) ;
} else
#endif
F_18 ( V_16 -> V_121 , V_2 -> V_28 -> V_109 ) ;
F_63 ( & V_16 -> V_77 ) ;
F_64 ( & V_16 -> V_69 ) ;
V_18 = F_30 ( V_2 , V_122 ) ;
if ( V_18 )
goto V_123;
V_18 = F_30 ( V_2 , 0 ) ;
if ( V_18 )
goto V_124;
return 0 ;
V_124:
F_44 ( V_2 ) ;
V_123:
F_65 ( & V_16 -> V_69 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
V_102:
F_68 ( & V_2 -> V_10 -> V_58 , & V_100 ) ;
V_101:
F_68 ( & V_2 -> V_10 -> V_58 , & V_99 ) ;
V_98:
F_69 ( V_2 ) ;
V_91:
F_70 ( V_2 , & V_16 -> V_89 ) ;
V_90:
F_40 ( V_16 ) ;
V_2 -> V_16 = NULL ;
return V_18 ;
}
static int F_71 ( struct V_1 * V_2 )
{
F_72 ( V_13 ) ;
T_2 V_17 ;
int V_18 = F_73 ( V_2 , V_125 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 == - V_71 )
V_18 = 0 ;
if ( V_18 )
F_74 ( V_2 , V_125 , 0 , V_13 , V_17 ,
V_18 ) ;
return V_18 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_47 , V_126 ) ;
unsigned int V_85 ;
int V_18 ;
F_13 ( V_127 != 0 ) ;
for ( V_85 = 0 ; V_85 < V_16 -> V_128 ; V_85 ++ ) {
F_21 ( V_47 , V_129 ,
V_16 -> V_130 [ V_85 ] ) ;
V_18 = F_9 ( V_2 , V_131 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 ) ;
}
V_16 -> V_128 = 0 ;
}
static int F_76 ( struct V_1 * V_2 , unsigned int V_132 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_13 , V_133 ) ;
unsigned int V_85 ;
T_2 V_17 ;
int V_18 = 0 ;
F_13 ( V_134 != 0 ) ;
for ( V_85 = 0 ; V_85 < V_132 ; V_85 ++ ) {
V_18 = F_73 ( V_2 , V_135 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 ) {
if ( ! ( F_6 ( V_2 ) && V_18 == - V_136 ) )
F_74 ( V_2 , V_135 ,
0 , V_13 , V_17 , V_18 ) ;
break;
}
if ( V_17 < V_133 ) {
V_18 = - V_7 ;
break;
}
V_16 -> V_130 [ V_85 ] =
F_10 ( V_13 , V_137 ) ;
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_9 , V_85 ,
V_16 -> V_130 [ V_85 ] ) ;
}
V_16 -> V_128 = V_85 ;
if ( V_18 )
F_75 ( V_2 ) ;
return V_18 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_78 ( V_47 ,
F_79 ( V_138 ,
V_139 ) ) ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
unsigned int V_144 , V_145 ;
int V_18 ;
F_13 ( V_146 != 0 ) ;
F_13 ( V_147 != 0 ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
for ( V_145 = 0 ; V_145 < V_16 -> V_128 ; ++ V_145 ) {
F_21 ( V_47 , V_148 ,
V_16 -> V_130 [ V_145 ] ) ;
F_21 ( V_47 , V_149 ,
V_16 -> V_150 + V_145 ) ;
V_18 = F_9 ( V_2 , V_151 ,
V_47 , V_138 ,
NULL , 0 , NULL ) ;
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_10 ,
V_16 -> V_150 + V_145 , V_145 ,
V_18 ) ;
goto V_152;
}
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_11 ,
V_16 -> V_150 + V_145 , V_145 ) ;
}
F_80 (channel, efx) {
F_81 (tx_queue, channel) {
V_144 = ( ( V_2 -> V_153 + V_2 -> V_154 -
V_143 -> V_141 -> V_141 - 1 ) *
V_155 ) ;
V_145 = V_144 / V_156 ;
V_144 = V_144 % V_156 ;
if ( V_143 -> V_157 == V_16 -> V_150 ) {
F_82 ( V_145 != 0 ) ;
V_18 = 0 ;
} else {
F_21 ( V_47 ,
V_148 ,
V_16 -> V_130 [ V_145 ] ) ;
F_21 ( V_47 ,
V_149 ,
V_143 -> V_157 ) ;
V_18 = F_9 ( V_2 , V_151 ,
V_47 , V_138 ,
NULL , 0 , NULL ) ;
}
if ( V_18 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_10 ,
V_143 -> V_157 , V_145 , V_18 ) ;
V_143 -> V_158 = NULL ;
} else {
V_143 -> V_158 =
V_16 -> V_159 +
V_145 * V_160 + V_144 ;
V_143 -> V_161 = V_144 ;
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_12 ,
V_143 -> V_157 , V_145 ,
V_143 -> V_161 ,
V_143 -> V_158 ) ;
}
}
}
return 0 ;
V_152:
while ( V_145 -- ) {
F_21 ( V_47 , V_162 ,
V_16 -> V_150 + V_145 ) ;
F_9 ( V_2 , V_163 ,
V_47 , V_139 ,
NULL , 0 , NULL ) ;
}
return V_18 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_140 * V_141 ;
struct V_142 * V_143 ;
F_80 (channel, efx)
F_81 (tx_queue, channel)
V_143 -> V_158 = NULL ;
}
static int F_76 ( struct V_1 * V_2 , unsigned int V_132 )
{
return V_132 == 0 ? 0 : - V_164 ;
}
static int F_77 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
}
static void F_83 ( struct V_1 * V_2 )
{
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
#ifdef F_62
struct V_15 * V_165 ;
struct V_10 * V_119 ;
struct V_1 * V_120 ;
struct V_166 * V_167 ;
if ( V_2 -> V_10 -> V_168 ) {
V_119 = V_2 -> V_10 -> V_117 ;
if ( V_119 ) {
V_120 = F_24 ( V_119 ) ;
V_165 = V_120 -> V_16 ;
V_167 = V_165 -> V_167 + V_16 -> V_22 ;
V_167 -> V_2 = NULL ;
} else
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_13 ) ;
}
#endif
F_44 ( V_2 ) ;
F_65 ( & V_16 -> V_69 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_86 ( V_2 ) ;
if ( V_16 -> V_169 )
F_87 ( V_16 -> V_169 ) ;
V_18 = F_71 ( V_2 ) ;
F_22 ( V_18 != 0 ) ;
if ( ! V_16 -> V_170 )
F_75 ( V_2 ) ;
F_68 ( & V_2 -> V_10 -> V_58 , & V_100 ) ;
F_68 ( & V_2 -> V_10 -> V_58 , & V_99 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 , & V_16 -> V_89 ) ;
F_40 ( V_16 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
return F_46 ( V_2 ) ;
}
int F_89 ( struct V_1 * V_2 , unsigned int V_121 ,
T_6 * V_171 , T_6 * V_172 ,
unsigned int * V_173 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_8 ( V_47 , V_174 ) ;
F_8 ( V_13 , V_175 ) ;
T_2 V_17 ;
int V_18 ;
if ( V_16 -> V_29 &
( 1 << V_176 ) ) {
F_21 ( V_47 , V_177 ,
V_121 ) ;
V_18 = F_9 ( V_2 , V_178 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < sizeof( V_13 ) ) {
V_18 = - V_7 ;
return V_18 ;
}
}
if ( V_171 )
* V_171 = F_10 ( V_13 , V_179 ) ;
if ( V_172 )
* V_172 =
F_10 ( V_13 , V_180 ) ;
if ( V_173 )
* V_173 =
F_10 ( V_13 ,
V_181 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 , unsigned int V_121 )
{
F_8 ( V_47 , V_182 ) ;
F_21 ( V_47 , V_183 , V_121 ) ;
return F_9 ( V_2 , V_184 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
int F_91 ( struct V_1 * V_2 , unsigned int V_121 )
{
F_8 ( V_47 , V_185 ) ;
F_21 ( V_47 , V_186 , V_121 ) ;
return F_9 ( V_2 , V_187 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
int F_92 ( struct V_1 * V_2 ,
unsigned int V_121 , T_3 * V_188 )
{
F_8 ( V_47 , V_189 ) ;
F_21 ( V_47 , V_190 , V_121 ) ;
F_18 ( F_19 ( V_47 , V_191 ) , V_188 ) ;
return F_9 ( V_2 , V_192 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
int F_93 ( struct V_1 * V_2 ,
unsigned int V_121 , T_3 * V_188 )
{
F_8 ( V_47 , V_193 ) ;
F_21 ( V_47 , V_194 , V_121 ) ;
F_18 ( F_19 ( V_47 , V_195 ) , V_188 ) ;
return F_9 ( V_2 , V_196 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_10 * V_119 ;
V_119 = V_2 -> V_10 -> V_117 ;
if ( V_119 ) {
struct V_1 * V_120 = F_24 ( V_119 ) ;
struct V_15 * V_165 = V_120 -> V_16 ;
if ( ! V_165 -> V_167 ) {
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_14
L_15 ) ;
return - V_197 ;
}
}
V_18 = F_46 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
goto V_152;
if ( V_2 -> V_10 -> V_168 ) {
if ( V_2 -> V_10 -> V_117 ) {
struct V_1 * V_120 =
F_24 ( V_2 -> V_10 -> V_117 ) ;
struct V_15 * V_198 = V_120 -> V_16 ;
struct V_15 * V_16 = V_2 -> V_16 ;
V_198 -> V_167 [ V_16 -> V_22 ] . V_2 = V_2 ;
V_198 -> V_167 [ V_16 -> V_22 ] . V_10 =
V_2 -> V_10 ;
} else
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_13 ) ;
}
return 0 ;
V_152:
F_84 ( V_2 ) ;
return V_18 ;
}
static int F_95 ( struct V_1 * V_2 ,
unsigned int V_199 , unsigned int V_200 )
{
F_8 ( V_47 , V_201 ) ;
F_8 ( V_13 , V_202 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_203 , V_199 ) ;
F_21 ( V_47 , V_204 , V_200 ) ;
V_18 = F_9 ( V_2 , V_205 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_202 )
return - V_7 ;
F_59 ( V_2 , V_27 , V_2 -> V_28 , L_16 ,
F_10 ( V_13 , V_206 ) ) ;
V_16 -> V_207 = F_10 ( V_13 , V_206 ) ;
V_16 -> V_208 = F_10 ( V_13 , V_209 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_210 , V_211 ;
unsigned int V_199 = F_79 ( V_212 ,
V_213 ? 2 : 1 ) ;
unsigned int V_214 , V_150 , V_200 ;
void T_7 * V_215 ;
int V_18 ;
V_214 = F_79 ( V_2 -> V_216 , V_2 -> V_154 * V_212 ) ;
#ifdef F_97
if ( V_155 != 0 &&
V_156 / V_155 * V_217 >=
V_2 -> V_154 ) {
unsigned int V_128 =
F_98 ( V_2 -> V_154 ,
V_156 / V_155 ) ;
V_18 = F_76 ( V_2 , V_128 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_17 , V_18 ) ;
else
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_18 , V_128 ) ;
}
#else
V_16 -> V_128 = 0 ;
#endif
V_210 = F_99 ( ( V_214 - 1 ) * V_160 +
V_218 ) ;
if ( V_16 -> V_128 ) {
V_150 = V_210 / V_160 ;
V_211 = ( F_99 ( ( V_150 +
V_16 -> V_128 ) *
V_160 ) -
V_210 ) ;
V_200 = V_150 + V_16 -> V_128 ;
} else {
V_150 = 0 ;
V_211 = 0 ;
V_200 = V_214 ;
}
V_18 = F_71 ( V_2 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_95 ( V_2 , V_199 , V_200 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_16 -> V_208 < V_214 ) {
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_19
L_20 ) ;
V_2 -> V_86 = V_16 -> V_208 ;
V_2 -> V_87 =
V_16 -> V_208 / V_212 ;
F_71 ( V_2 ) ;
return - V_219 ;
}
if ( V_16 -> V_128 &&
V_16 -> V_208 <
V_150 + V_16 -> V_128 ) {
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_21 ,
V_16 -> V_208 , V_16 -> V_128 ) ;
F_75 ( V_2 ) ;
}
V_215 = F_100 ( V_2 -> V_220 , V_210 ) ;
if ( ! V_215 ) {
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_22 ,
V_210 ) ;
return - V_73 ;
}
F_87 ( V_2 -> V_215 ) ;
V_2 -> V_215 = V_215 ;
if ( V_211 ) {
V_16 -> V_169 = F_101 ( V_2 -> V_220 +
V_210 ,
V_211 ) ;
if ( ! V_16 -> V_169 ) {
F_14 ( V_2 , V_36 , V_2 -> V_28 ,
L_23 ,
V_211 ) ;
return - V_73 ;
}
V_16 -> V_150 = V_150 ;
V_16 -> V_159 =
V_16 -> V_169 +
( V_150 * V_160 + V_218 -
V_210 ) ;
V_18 = F_77 ( V_2 ) ;
if ( V_18 )
F_75 ( V_2 ) ;
}
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_24 ,
& V_2 -> V_220 , V_2 -> V_215 , V_210 ,
V_16 -> V_169 , V_211 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
if ( V_16 -> V_221 ) {
V_18 = F_12 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_221 = false ;
}
if ( V_16 -> V_222 ) {
V_18 = F_95 ( V_2 , V_16 -> V_208 ,
V_16 -> V_208 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_222 = false ;
}
if ( V_16 -> V_170 && V_16 -> V_128 ) {
V_18 = F_76 ( V_2 , V_16 -> V_128 ) ;
if ( V_18 == 0 ) {
V_18 = F_77 ( V_2 ) ;
if ( V_18 )
F_75 ( V_2 ) ;
}
if ( V_18 )
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_25 , V_18 ) ;
V_16 -> V_170 = false ;
}
V_2 -> type -> V_223 ( V_2 , false , V_2 -> V_224 ) ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
#ifdef F_62
unsigned int V_85 ;
#endif
V_16 -> V_222 = true ;
V_16 -> V_225 = true ;
V_16 -> V_170 = true ;
F_83 ( V_2 ) ;
V_16 -> V_93 = V_94 ;
V_16 -> V_226 = true ;
V_16 -> V_95 = V_52 ;
#ifdef F_62
if ( V_16 -> V_167 )
for ( V_85 = 0 ; V_85 < V_2 -> V_227 ; V_85 ++ )
V_16 -> V_167 [ V_85 ] . V_95 = 0 ;
#endif
}
static enum V_228 F_104 ( enum V_228 V_229 )
{
if ( V_229 == V_230 )
return V_231 ;
return F_105 ( V_229 ) ;
}
static int F_106 ( T_6 * V_232 )
{
enum {
V_233 = ( ( V_234 | V_235 ) <<
V_236 ) ,
V_237 = ( ( V_238 | V_239 |
V_240 | V_234 |
V_235 | V_241 ) <<
V_236 )
};
if ( ( * V_232 & V_237 ) == V_237 ) {
* V_232 &= ~ V_237 ;
return V_242 ;
}
if ( ( * V_232 & V_233 ) == V_233 ) {
* V_232 &= ~ V_233 ;
return V_97 ;
}
return - V_243 ;
}
static int F_107 ( struct V_1 * V_2 , enum V_228 V_228 )
{
int V_18 = F_53 ( V_2 , V_228 ) ;
if ( V_228 == V_242 && V_18 == - V_113 )
V_18 = 0 ;
if ( ( V_228 == V_97 ||
V_228 == V_244 ) && ! V_18 )
F_103 ( V_2 ) ;
return V_18 ;
}
static T_8 F_108 ( struct V_1 * V_2 )
{
T_8 V_245 = V_246 ;
T_6 V_247 = F_109 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ! ( V_2 -> V_62 -> V_63 &
1 << V_64 ) )
return 0 ;
if ( V_247 & ( 1 << V_248 ) )
V_245 |= V_249 ;
else
V_245 |= V_250 ;
if ( V_16 -> V_29 &
( 1 << V_251 ) )
V_245 |= V_252 ;
return V_245 ;
}
static void F_110 ( struct V_1 * V_2 , unsigned long * V_253 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_8 V_245 [ 2 ] ;
V_245 [ 0 ] = F_108 ( V_2 ) ;
if ( V_16 -> V_29 &
( 1 << V_254 ) ) {
V_245 [ 0 ] |= ~ ( ( 1ULL << V_255 ) - 1 ) ;
V_245 [ 1 ] = ( 1ULL << ( V_256 - 63 ) ) - 1 ;
} else {
V_245 [ 1 ] = 0 ;
}
#if V_257 == 64
F_13 ( F_111 ( V_256 ) != 2 ) ;
V_253 [ 0 ] = V_245 [ 0 ] ;
V_253 [ 1 ] = V_245 [ 1 ] ;
#else
F_13 ( F_111 ( V_256 ) != 3 ) ;
V_253 [ 0 ] = V_245 [ 0 ] & 0xffffffff ;
V_253 [ 1 ] = V_245 [ 0 ] >> 32 ;
V_253 [ 2 ] = V_245 [ 1 ] & 0xffffffff ;
#endif
}
static T_2 F_112 ( struct V_1 * V_2 , T_3 * V_258 )
{
F_113 ( V_253 , V_256 ) ;
F_110 ( V_2 , V_253 ) ;
return F_114 ( V_259 , V_256 ,
V_253 , V_258 ) ;
}
static T_2 F_115 ( struct V_1 * V_2 , T_8 * V_260 ,
struct V_261 * V_262 )
{
F_113 ( V_253 , V_256 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_8 * V_263 = V_16 -> V_263 ;
T_2 V_264 = 0 , V_145 ;
F_110 ( V_2 , V_253 ) ;
if ( V_260 ) {
F_116 (index, mask, EF10_STAT_COUNT) {
if ( V_259 [ V_145 ] . V_265 ) {
* V_260 ++ = V_263 [ V_145 ] ;
++ V_264 ;
}
}
}
if ( ! V_262 )
return V_264 ;
if ( V_16 -> V_29 &
1 << V_254 ) {
V_262 -> V_266 = V_263 [ V_255 ] +
V_263 [ V_267 ] +
V_263 [ V_268 ] ;
V_262 -> V_269 = V_263 [ V_270 ] +
V_263 [ V_271 ] +
V_263 [ V_272 ] ;
V_262 -> V_273 = V_263 [ V_274 ] +
V_263 [ V_275 ] +
V_263 [ V_276 ] ;
V_262 -> V_277 = V_263 [ V_278 ] +
V_263 [ V_279 ] +
V_263 [ V_280 ] ;
V_262 -> V_281 = V_263 [ V_282 ] +
V_263 [ V_283 ] ;
V_262 -> V_284 = V_263 [ V_267 ] ;
V_262 -> V_285 = V_263 [ V_286 ] ;
V_262 -> V_287 = V_263 [ V_288 ] ;
V_262 -> V_289 = V_262 -> V_285 ;
V_262 -> V_290 = V_263 [ V_291 ] ;
} else {
V_262 -> V_266 = V_263 [ V_292 ] ;
V_262 -> V_269 = V_263 [ V_293 ] ;
V_262 -> V_273 = V_263 [ V_294 ] ;
V_262 -> V_277 = V_263 [ V_295 ] ;
V_262 -> V_281 = V_263 [ V_296 ] +
V_263 [ V_282 ] +
V_263 [ V_283 ] ;
V_262 -> V_284 = V_263 [ V_297 ] ;
V_262 -> V_298 =
V_263 [ V_299 ] +
V_263 [ V_300 ] ;
V_262 -> V_285 = V_263 [ V_301 ] ;
V_262 -> V_302 =
V_263 [ V_303 ] ;
V_262 -> V_287 = V_263 [ V_304 ] ;
V_262 -> V_289 = ( V_262 -> V_298 +
V_262 -> V_285 +
V_262 -> V_302 ) ;
}
return V_264 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_113 ( V_253 , V_256 ) ;
T_9 V_305 , V_306 ;
T_8 * V_263 = V_16 -> V_263 ;
T_9 * V_307 ;
F_110 ( V_2 , V_253 ) ;
V_307 = V_2 -> V_308 . V_309 ;
V_16 = V_2 -> V_16 ;
V_306 = V_307 [ V_310 ] ;
if ( V_306 == V_311 )
return 0 ;
F_118 () ;
F_119 ( V_259 , V_256 , V_253 ,
V_263 , V_2 -> V_308 . V_309 , false ) ;
F_118 () ;
V_305 = V_307 [ V_312 ] ;
if ( V_306 != V_305 )
return - V_219 ;
F_120 ( V_2 ,
& V_263 [ V_296 ] ) ;
V_263 [ V_313 ] =
V_263 [ V_294 ] -
V_263 [ V_314 ] ;
F_121 ( & V_263 [ V_315 ] ,
V_263 [ V_314 ] ) ;
F_122 ( V_2 , V_263 ) ;
return 0 ;
}
static T_2 F_123 ( struct V_1 * V_2 , T_8 * V_260 ,
struct V_261 * V_262 )
{
int V_316 ;
for ( V_316 = 0 ; V_316 < 100 ; ++ V_316 ) {
if ( F_117 ( V_2 ) == 0 )
break;
F_124 ( 100 ) ;
}
return F_115 ( V_2 , V_260 , V_262 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_317 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
F_113 ( V_253 , V_256 ) ;
T_9 V_305 , V_306 ;
T_8 * V_263 = V_16 -> V_263 ;
T_6 V_318 = V_319 * sizeof( T_8 ) ;
struct V_320 V_321 ;
T_9 * V_307 ;
int V_18 ;
F_126 ( & V_2 -> V_322 ) ;
if ( F_127 () ) {
F_128 ( & V_2 -> V_322 ) ;
F_122 ( V_2 , V_263 ) ;
return 0 ;
}
F_110 ( V_2 , V_253 ) ;
V_18 = F_48 ( V_2 , & V_321 , V_318 , V_323 ) ;
if ( V_18 ) {
F_128 ( & V_2 -> V_322 ) ;
return V_18 ;
}
V_307 = V_321 . V_309 ;
V_307 [ V_310 ] = V_311 ;
F_129 ( V_47 , V_324 , V_321 . V_325 ) ;
F_130 ( V_47 , V_326 ,
V_327 , 1 ) ;
F_21 ( V_47 , V_328 , V_318 ) ;
F_21 ( V_47 , V_329 , V_52 ) ;
V_18 = F_73 ( V_2 , V_330 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_128 ( & V_2 -> V_322 ) ;
if ( V_18 ) {
if ( V_18 != - V_82 || F_131 ( & V_2 -> V_331 ) )
F_74 ( V_2 , V_330 ,
sizeof( V_47 ) , NULL , 0 , V_18 ) ;
goto V_332;
}
V_306 = V_307 [ V_310 ] ;
if ( V_306 == V_311 ) {
F_132 ( 1 ) ;
goto V_332;
}
F_118 () ;
F_119 ( V_259 , V_256 , V_253 ,
V_263 , V_321 . V_309 , false ) ;
F_118 () ;
V_305 = V_307 [ V_312 ] ;
if ( V_306 != V_305 ) {
V_18 = - V_219 ;
goto V_332;
}
F_122 ( V_2 , V_263 ) ;
V_332:
F_70 ( V_2 , & V_321 ) ;
return V_18 ;
}
static T_2 F_133 ( struct V_1 * V_2 , T_8 * V_260 ,
struct V_261 * V_262 )
{
if ( F_125 ( V_2 ) )
return 0 ;
return F_115 ( V_2 , V_260 , V_262 ) ;
}
static void F_134 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = V_141 -> V_2 ;
unsigned int V_333 , V_334 ;
T_1 V_335 ;
if ( V_141 -> V_336 ) {
V_333 = 3 ;
V_334 = V_141 -> V_336 - 1 ;
} else {
V_333 = 0 ;
V_334 = 0 ;
}
if ( F_135 ( V_2 ) ) {
F_136 ( V_335 , V_337 ,
V_338 ,
V_339 , V_333 ,
V_340 , V_334 ) ;
F_137 ( V_2 , & V_335 , V_341 ,
V_141 -> V_141 ) ;
} else {
F_138 ( V_335 , V_342 , V_333 ,
V_343 , V_334 ) ;
F_137 ( V_2 , & V_335 , V_344 ,
V_141 -> V_141 ) ;
}
}
static void F_139 ( struct V_1 * V_2 ,
struct V_345 * V_346 ) {}
static int F_140 ( struct V_1 * V_2 , T_6 type )
{
return - V_347 ;
}
static void F_141 ( struct V_1 * V_2 , struct V_345 * V_346 )
{
V_346 -> V_348 = 0 ;
V_346 -> V_349 = 0 ;
memset ( & V_346 -> V_350 , 0 , sizeof( V_346 -> V_350 ) ) ;
}
static int F_142 ( struct V_1 * V_2 , T_6 type )
{
if ( type != 0 )
return - V_243 ;
return 0 ;
}
static void F_143 ( struct V_1 * V_2 ,
const T_1 * V_351 , T_2 V_352 ,
const T_1 * V_353 , T_2 V_354 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 * V_355 = V_16 -> V_89 . V_309 ;
memcpy ( V_355 , V_351 , V_352 ) ;
memcpy ( V_355 + V_352 , V_353 , V_354 ) ;
F_144 () ;
F_50 ( V_2 , F_51 ( ( T_8 ) V_16 -> V_89 . V_325 >> 32 ) ,
V_356 ) ;
F_50 ( V_2 , F_51 ( ( T_6 ) V_16 -> V_89 . V_325 ) ,
V_96 ) ;
}
static bool F_145 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_1 V_351 = * ( const T_1 * ) V_16 -> V_89 . V_309 ;
F_118 () ;
return F_3 ( V_351 , V_357 ) ;
}
static void
F_146 ( struct V_1 * V_2 , T_1 * V_13 ,
T_2 V_144 , T_2 V_17 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
const T_3 * V_355 = V_16 -> V_89 . V_309 ;
memcpy ( V_13 , V_355 + V_144 , V_17 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
F_103 ( V_2 ) ;
V_16 -> V_221 = true ;
V_16 -> V_263 [ V_315 ] = 0 ;
}
static int F_148 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 ) {
return 0 ;
}
if ( V_18 == V_16 -> V_92 )
return 0 ;
V_16 -> V_92 = V_18 ;
F_147 ( V_2 ) ;
return - V_7 ;
}
static T_10 F_149 ( int V_358 , void * V_359 )
{
struct V_360 * V_361 = V_359 ;
struct V_1 * V_2 = V_361 -> V_2 ;
F_150 ( V_2 , V_362 , V_2 -> V_28 ,
L_26 , V_358 , F_151 () ) ;
if ( F_152 ( F_153 ( V_2 -> V_363 ) ) ) {
if ( V_361 -> V_145 == V_2 -> V_364 )
V_2 -> V_365 = F_151 () ;
F_154 ( V_2 -> V_141 [ V_361 -> V_145 ] ) ;
}
return V_366 ;
}
static T_10 F_155 ( int V_358 , void * V_359 )
{
struct V_1 * V_2 = V_359 ;
bool V_367 = F_153 ( V_2 -> V_363 ) ;
struct V_140 * V_141 ;
T_1 V_3 ;
T_6 V_368 ;
F_2 ( V_2 , & V_3 , V_369 ) ;
V_368 = F_3 ( V_3 , V_370 ) ;
if ( V_368 == 0 )
return V_371 ;
if ( F_152 ( V_367 ) ) {
if ( V_368 & ( 1U << V_2 -> V_364 ) )
V_2 -> V_365 = F_151 () ;
F_80 (channel, efx) {
if ( V_368 & 1 )
F_154 ( V_141 ) ;
V_368 >>= 1 ;
}
}
F_150 ( V_2 , V_362 , V_2 -> V_28 ,
L_27 V_372 L_28 ,
V_358 , F_151 () , F_156 ( V_3 ) ) ;
return V_366 ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_373 ) ;
F_13 ( V_374 != 0 ) ;
F_21 ( V_47 , V_375 , V_2 -> V_364 ) ;
( void ) F_9 ( V_2 , V_376 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
}
static int F_158 ( struct V_142 * V_143 )
{
return F_48 ( V_143 -> V_2 , & V_143 -> V_377 . V_61 ,
( V_143 -> V_378 + 1 ) *
sizeof( V_379 ) ,
V_74 ) ;
}
static inline void F_159 ( struct V_142 * V_143 ,
const V_379 * V_377 )
{
unsigned int V_380 ;
T_11 V_3 ;
V_380 = V_143 -> V_381 & V_143 -> V_378 ;
F_160 ( V_3 , V_382 , V_380 ) ;
V_3 . V_383 [ 0 ] = * V_377 ;
F_161 ( V_143 -> V_2 , & V_3 ,
V_384 , V_143 -> V_157 ) ;
}
static void F_162 ( struct V_142 * V_143 )
{
F_8 ( V_47 , F_163 ( V_385 * 8 /
V_386 ) ) ;
bool V_387 = V_143 -> V_157 & V_388 ;
T_2 V_389 = V_143 -> V_377 . V_61 . V_390 / V_386 ;
struct V_140 * V_141 = V_143 -> V_141 ;
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_391 ;
T_12 V_325 ;
V_379 * V_377 ;
int V_18 ;
int V_85 ;
F_13 ( V_392 != 0 ) ;
F_21 ( V_47 , V_393 , V_143 -> V_378 + 1 ) ;
F_21 ( V_47 , V_394 , V_141 -> V_141 ) ;
F_21 ( V_47 , V_395 , V_143 -> V_157 ) ;
F_21 ( V_47 , V_396 , V_143 -> V_157 ) ;
F_164 ( V_47 , V_397 ,
V_398 , ! V_387 ,
V_399 , ! V_387 ) ;
F_21 ( V_47 , V_400 , 0 ) ;
F_21 ( V_47 , V_401 , V_16 -> V_95 ) ;
V_325 = V_143 -> V_377 . V_61 . V_325 ;
F_59 ( V_2 , V_402 , V_2 -> V_28 , L_29 ,
V_143 -> V_157 , V_389 , ( T_8 ) V_325 ) ;
for ( V_85 = 0 ; V_85 < V_389 ; ++ V_85 ) {
F_165 ( V_47 , V_403 , V_85 , V_325 ) ;
V_325 += V_386 ;
}
V_391 = F_163 ( V_389 ) ;
V_18 = F_9 ( V_2 , V_404 , V_47 , V_391 ,
NULL , 0 , NULL ) ;
if ( V_18 )
goto V_152;
V_143 -> V_405 [ 0 ] . V_232 = V_406 ;
V_143 -> V_407 = 1 ;
V_377 = F_166 ( V_143 , 0 ) ;
F_167 ( * V_377 ,
V_408 , true ,
V_409 ,
V_410 ,
V_411 , V_387 ,
V_412 , V_387 ) ;
V_143 -> V_381 = 1 ;
if ( V_16 -> V_29 &
( 1 << V_413 ) ) {
V_143 -> V_414 = 1 ;
}
F_144 () ;
F_159 ( V_143 , V_377 ) ;
return;
V_152:
F_168 ( V_2 -> V_28 , L_30 ,
V_143 -> V_157 ) ;
}
static void F_169 ( struct V_142 * V_143 )
{
F_8 ( V_47 , V_415 ) ;
F_72 ( V_13 ) ;
struct V_1 * V_2 = V_143 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_416 ,
V_143 -> V_157 ) ;
V_18 = F_73 ( V_2 , V_417 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_71 )
goto V_152;
return;
V_152:
F_74 ( V_2 , V_417 , V_415 ,
V_13 , V_17 , V_18 ) ;
}
static void F_170 ( struct V_142 * V_143 )
{
F_70 ( V_143 -> V_2 , & V_143 -> V_377 . V_61 ) ;
}
static inline void F_171 ( struct V_142 * V_143 )
{
unsigned int V_380 ;
T_1 V_3 ;
V_380 = V_143 -> V_381 & V_143 -> V_378 ;
F_172 ( V_3 , V_418 , V_380 ) ;
F_137 ( V_143 -> V_2 , & V_3 ,
V_419 , V_143 -> V_157 ) ;
}
static void F_173 ( struct V_142 * V_143 )
{
unsigned int V_420 = V_143 -> V_381 ;
struct V_421 * V_405 ;
unsigned int V_380 ;
V_379 * V_377 ;
V_143 -> V_422 = false ;
if ( F_174 ( V_143 -> V_381 == V_143 -> V_407 ) )
return;
do {
V_380 = V_143 -> V_381 & V_143 -> V_378 ;
V_405 = & V_143 -> V_405 [ V_380 ] ;
V_377 = F_166 ( V_143 , V_380 ) ;
++ V_143 -> V_381 ;
if ( V_405 -> V_232 & V_406 ) {
* V_377 = V_405 -> V_423 ;
} else {
F_13 ( V_424 != 1 ) ;
F_175 (
* V_377 ,
V_425 ,
V_405 -> V_232 & V_424 ,
V_426 , V_405 -> V_390 ,
V_427 , V_405 -> V_325 ) ;
}
} while ( V_143 -> V_381 != V_143 -> V_407 );
F_144 () ;
if ( F_176 ( V_143 , V_420 ) ) {
V_377 = F_166 ( V_143 ,
V_420 & V_143 -> V_378 ) ;
F_159 ( V_143 , V_377 ) ;
++ V_143 -> V_428 ;
} else {
F_171 ( V_143 ) ;
}
}
static int F_177 ( struct V_1 * V_2 , T_6 * V_361 ,
bool V_429 , unsigned * V_430 )
{
F_8 ( V_47 , V_431 ) ;
F_8 ( V_13 , V_432 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_6 V_433 = V_429 ?
V_434 :
V_435 ;
unsigned V_436 = V_429 ?
V_2 -> V_436 :
F_178 ( F_179 ( V_2 -> V_436 ) ,
V_437 ) ;
if ( ! V_429 && V_436 == 1 ) {
* V_361 = V_94 ;
if ( V_430 )
* V_430 = 1 ;
return 0 ;
}
if ( V_16 -> V_29 &
1 << V_438 )
return - V_347 ;
F_21 ( V_47 , V_439 ,
V_16 -> V_95 ) ;
F_21 ( V_47 , V_440 , V_433 ) ;
F_21 ( V_47 , V_441 , V_436 ) ;
V_18 = F_9 ( V_2 , V_442 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_432 )
return - V_7 ;
* V_361 = F_10 ( V_13 , V_443 ) ;
if ( V_430 )
* V_430 = V_436 ;
return 0 ;
}
static void F_180 ( struct V_1 * V_2 , T_6 V_361 )
{
F_8 ( V_47 , V_444 ) ;
int V_18 ;
F_21 ( V_47 , V_445 ,
V_361 ) ;
V_18 = F_9 ( V_2 , V_446 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_22 ( V_18 != 0 ) ;
}
static int F_181 ( struct V_1 * V_2 , T_6 V_361 ,
const T_6 * V_224 )
{
F_8 ( V_447 , V_448 ) ;
F_8 ( V_449 , V_450 ) ;
int V_85 , V_18 ;
F_21 ( V_447 , V_451 ,
V_361 ) ;
F_13 ( F_182 ( V_2 -> V_224 ) !=
V_452 ) ;
for ( V_85 = 0 ; V_85 < F_182 ( V_2 -> V_224 ) ; ++ V_85 )
F_19 ( V_447 ,
V_453 ) [ V_85 ] =
( T_3 ) V_224 [ V_85 ] ;
V_18 = F_9 ( V_2 , V_454 , V_447 ,
sizeof( V_447 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
F_21 ( V_449 , V_455 ,
V_361 ) ;
F_13 ( F_182 ( V_2 -> V_456 ) !=
V_457 ) ;
for ( V_85 = 0 ; V_85 < F_182 ( V_2 -> V_456 ) ; ++ V_85 )
F_19 ( V_449 , V_458 ) [ V_85 ] =
V_2 -> V_456 [ V_85 ] ;
return F_9 ( V_2 , V_459 , V_449 ,
sizeof( V_449 ) , NULL , 0 , NULL ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_93 != V_94 )
F_180 ( V_2 , V_16 -> V_93 ) ;
V_16 -> V_93 = V_94 ;
}
static int F_183 ( struct V_1 * V_2 ,
unsigned * V_430 )
{
T_6 V_460 ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 = F_177 ( V_2 , & V_460 ,
false , V_430 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 -> V_93 = V_460 ;
V_16 -> V_461 = false ;
F_184 ( V_2 ) ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 ,
const T_6 * V_224 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_18 ;
T_6 V_460 ;
if ( V_16 -> V_93 == V_94 ||
! V_16 -> V_461 ) {
V_18 = F_177 ( V_2 , & V_460 ,
true , NULL ) ;
if ( V_18 == - V_347 )
return V_18 ;
else if ( V_18 != 0 )
goto V_90;
} else {
V_460 = V_16 -> V_93 ;
}
V_18 = F_181 ( V_2 , V_460 ,
V_224 ) ;
if ( V_18 != 0 )
goto V_91;
if ( V_16 -> V_93 != V_460 )
F_86 ( V_2 ) ;
V_16 -> V_93 = V_460 ;
V_16 -> V_461 = true ;
if ( V_224 != V_2 -> V_224 )
memcpy ( V_2 -> V_224 , V_224 ,
sizeof( V_2 -> V_224 ) ) ;
return 0 ;
V_91:
if ( V_460 != V_16 -> V_93 )
F_180 ( V_2 , V_460 ) ;
V_90:
F_14 ( V_2 , V_402 , V_2 -> V_28 , L_31 , V_462 , V_18 ) ;
return V_18 ;
}
static int F_186 ( struct V_1 * V_2 , bool V_463 ,
const T_6 * V_224 )
{
int V_18 ;
if ( V_2 -> V_436 == 1 )
return 0 ;
V_18 = F_185 ( V_2 , V_224 ) ;
if ( V_18 == - V_164 && ! V_463 ) {
unsigned V_430 ;
bool V_464 = false ;
T_2 V_85 ;
for ( V_85 = 0 ; V_85 < F_182 ( V_2 -> V_224 ) && ! V_464 ;
V_85 ++ )
V_464 = V_224 [ V_85 ] !=
F_187 ( V_85 , V_2 -> V_436 ) ;
V_18 = F_183 ( V_2 , & V_430 ) ;
if ( V_18 == 0 ) {
if ( V_430 != V_2 -> V_436 )
F_32 ( V_2 , V_36 , V_2 -> V_28 ,
L_32
L_33
L_34
L_35 ,
V_2 -> V_436 , V_430 ) ;
else if ( V_464 )
F_32 ( V_2 , V_36 , V_2 -> V_28 ,
L_32
L_36
L_37
L_38 ) ;
else
F_85 ( V_2 , V_36 , V_2 -> V_28 ,
L_32
L_39 ) ;
}
}
return V_18 ;
}
static int F_188 ( struct V_465 * V_466 )
{
return F_48 ( V_466 -> V_2 , & V_466 -> V_467 . V_61 ,
( V_466 -> V_378 + 1 ) *
sizeof( V_379 ) ,
V_74 ) ;
}
static void F_189 ( struct V_465 * V_466 )
{
F_8 ( V_47 ,
F_190 ( V_385 * 8 /
V_386 ) ) ;
struct V_140 * V_141 = F_191 ( V_466 ) ;
T_2 V_389 = V_466 -> V_467 . V_61 . V_390 / V_386 ;
struct V_1 * V_2 = V_466 -> V_2 ;
struct V_15 * V_16 = V_2 -> V_16 ;
T_2 V_391 ;
T_12 V_325 ;
int V_18 ;
int V_85 ;
F_13 ( V_468 != 0 ) ;
V_466 -> V_469 = 0 ;
V_466 -> V_470 = 0 ;
F_21 ( V_47 , V_471 , V_466 -> V_378 + 1 ) ;
F_21 ( V_47 , V_472 , V_141 -> V_141 ) ;
F_21 ( V_47 , V_473 , F_192 ( V_466 ) ) ;
F_21 ( V_47 , V_474 ,
F_192 ( V_466 ) ) ;
F_164 ( V_47 , V_475 ,
V_476 , 1 ,
V_477 , 1 ) ;
F_21 ( V_47 , V_478 , 0 ) ;
F_21 ( V_47 , V_479 , V_16 -> V_95 ) ;
V_325 = V_466 -> V_467 . V_61 . V_325 ;
F_59 ( V_2 , V_402 , V_2 -> V_28 , L_40 ,
F_192 ( V_466 ) , V_389 , ( T_8 ) V_325 ) ;
for ( V_85 = 0 ; V_85 < V_389 ; ++ V_85 ) {
F_165 ( V_47 , V_480 , V_85 , V_325 ) ;
V_325 += V_386 ;
}
V_391 = F_190 ( V_389 ) ;
V_18 = F_9 ( V_2 , V_481 , V_47 , V_391 ,
NULL , 0 , NULL ) ;
if ( V_18 )
F_168 ( V_2 -> V_28 , L_41 ,
F_192 ( V_466 ) ) ;
}
static void F_193 ( struct V_465 * V_466 )
{
F_8 ( V_47 , V_482 ) ;
F_72 ( V_13 ) ;
struct V_1 * V_2 = V_466 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_483 ,
F_192 ( V_466 ) ) ;
V_18 = F_73 ( V_2 , V_484 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_71 )
goto V_152;
return;
V_152:
F_74 ( V_2 , V_484 , V_482 ,
V_13 , V_17 , V_18 ) ;
}
static void F_194 ( struct V_465 * V_466 )
{
F_70 ( V_466 -> V_2 , & V_466 -> V_467 . V_61 ) ;
}
static inline void
F_195 ( struct V_465 * V_466 , unsigned int V_145 )
{
struct V_485 * V_486 ;
V_379 * V_467 ;
V_467 = F_196 ( V_466 , V_145 ) ;
V_486 = V_485 ( V_466 , V_145 ) ;
F_197 ( * V_467 ,
V_487 , V_486 -> V_390 ,
V_488 , V_486 -> V_325 ) ;
}
static void F_198 ( struct V_465 * V_466 )
{
struct V_1 * V_2 = V_466 -> V_2 ;
unsigned int V_381 ;
T_1 V_3 ;
V_381 = V_466 -> V_489 & ~ 7 ;
if ( V_466 -> V_490 == V_381 )
return;
do
F_195 (
V_466 ,
V_466 -> V_490 & V_466 -> V_378 ) ;
while ( ++ V_466 -> V_490 != V_381 );
F_144 () ;
F_172 ( V_3 , V_491 ,
V_381 & V_466 -> V_378 ) ;
F_137 ( V_2 , & V_3 , V_492 ,
F_192 ( V_466 ) ) ;
}
static void F_199 ( struct V_465 * V_466 )
{
struct V_140 * V_141 = F_191 ( V_466 ) ;
F_8 ( V_47 , V_493 ) ;
V_379 V_494 ;
F_197 ( V_494 ,
V_495 , V_496 ,
V_497 , V_498 ) ;
F_21 ( V_47 , V_499 , V_141 -> V_141 ) ;
memcpy ( F_19 ( V_47 , V_500 ) , & V_494 . T_8 [ 0 ] ,
sizeof( V_379 ) ) ;
F_200 ( V_141 -> V_2 , V_501 ,
V_47 , sizeof( V_47 ) , 0 ,
V_502 , 0 ) ;
}
static void
V_502 ( struct V_1 * V_2 , unsigned long V_503 ,
int V_18 , T_1 * V_13 ,
T_2 V_504 )
{
}
static int F_201 ( struct V_140 * V_141 )
{
return F_48 ( V_141 -> V_2 , & V_141 -> V_505 . V_61 ,
( V_141 -> V_506 + 1 ) *
sizeof( V_379 ) ,
V_74 ) ;
}
static void F_202 ( struct V_140 * V_141 )
{
F_8 ( V_47 , V_507 ) ;
F_72 ( V_13 ) ;
struct V_1 * V_2 = V_141 -> V_2 ;
T_2 V_17 ;
int V_18 ;
F_21 ( V_47 , V_508 , V_141 -> V_141 ) ;
V_18 = F_73 ( V_2 , V_509 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 && V_18 != - V_71 )
goto V_152;
return;
V_152:
F_74 ( V_2 , V_509 , V_507 ,
V_13 , V_17 , V_18 ) ;
}
static int F_203 ( struct V_140 * V_141 )
{
F_8 ( V_47 ,
F_204 ( V_510 * 8 /
V_386 ) ) ;
F_8 ( V_13 , V_511 ) ;
T_2 V_389 = V_141 -> V_505 . V_61 . V_390 / V_386 ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_15 * V_16 ;
bool V_512 ;
T_2 V_391 , V_17 ;
unsigned int V_114 , V_513 ;
T_12 V_325 ;
int V_18 ;
int V_85 ;
V_16 = V_2 -> V_16 ;
V_512 =
! ! ( V_16 -> V_29 &
1 << V_514 ) ;
memset ( V_141 -> V_505 . V_61 . V_309 , 0xff , V_141 -> V_505 . V_61 . V_390 ) ;
F_21 ( V_47 , V_515 , V_141 -> V_506 + 1 ) ;
F_21 ( V_47 , V_516 , V_141 -> V_141 ) ;
F_21 ( V_47 , V_517 , V_141 -> V_141 ) ;
F_205 ( V_47 , V_518 ,
V_519 , 1 ,
V_520 , 1 ,
V_521 , 1 ,
V_522 , ! V_512 ) ;
F_21 ( V_47 , V_523 ,
V_524 ) ;
F_21 ( V_47 , V_525 , 0 ) ;
F_21 ( V_47 , V_526 , 0 ) ;
F_21 ( V_47 , V_527 ,
V_528 ) ;
F_21 ( V_47 , V_529 , 0 ) ;
V_325 = V_141 -> V_505 . V_61 . V_325 ;
for ( V_85 = 0 ; V_85 < V_389 ; ++ V_85 ) {
F_165 ( V_47 , V_530 , V_85 , V_325 ) ;
V_325 += V_386 ;
}
V_391 = F_204 ( V_389 ) ;
V_18 = F_9 ( V_2 , V_531 , V_47 , V_391 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_141 -> V_141 || V_18 )
return V_18 ;
V_18 = F_58 ( V_2 , & V_513 , & V_114 ) ;
if ( V_18 == - V_116 ) {
V_16 -> V_532 = false ;
V_18 = 0 ;
} else if ( V_18 ) {
goto V_152;
} else {
V_16 -> V_532 =
! ! ( V_114 & V_533 ) ;
if ( V_513 & V_533 &&
! V_16 -> V_532 ) {
unsigned int V_232 ;
V_18 = F_57 ( V_2 ,
V_534 ,
true , & V_232 ) ;
if ( ! V_18 ) {
if ( V_232 &
1 << V_535 ) {
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_42 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 >= 0 ) {
V_16 -> V_92 = V_18 ;
V_18 = 0 ;
}
}
V_16 -> V_532 = true ;
} else if ( V_18 == - V_113 ) {
V_18 = 0 ;
}
}
}
if ( ! V_18 )
return 0 ;
V_152:
F_202 ( V_141 ) ;
return V_18 ;
}
static void F_206 ( struct V_140 * V_141 )
{
F_70 ( V_141 -> V_2 , & V_141 -> V_505 . V_61 ) ;
}
static void F_207 ( struct V_465 * V_466 ,
unsigned int V_536 )
{
struct V_1 * V_2 = V_466 -> V_2 ;
F_85 ( V_2 , V_402 , V_2 -> V_28 ,
L_43 ,
F_192 ( V_466 ) , V_536 ) ;
F_208 ( V_2 , V_537 ) ;
}
static void
F_209 ( struct V_465 * V_466 ,
unsigned int V_538 , unsigned int V_539 )
{
unsigned int V_540 = ( V_538 - V_539 ) & V_466 -> V_378 ;
struct V_1 * V_2 = V_466 -> V_2 ;
F_85 ( V_2 , V_402 , V_2 -> V_28 ,
L_44 ,
V_540 , V_538 , V_539 ) ;
F_208 ( V_2 , V_537 ) ;
}
static void F_210 ( struct V_465 * V_466 )
{
unsigned int V_541 ;
F_59 ( V_466 -> V_2 , V_402 , V_466 -> V_2 -> V_28 ,
L_45 ,
V_466 -> V_469 ) ;
V_541 = V_466 -> V_542 & V_466 -> V_378 ;
F_211 ( V_466 , V_541 , V_466 -> V_469 ,
0 , V_543 ) ;
V_466 -> V_542 += V_466 -> V_469 ;
V_466 -> V_469 = 0 ;
V_466 -> V_470 = 0 ;
++ F_191 ( V_466 ) -> V_544 ;
}
static int F_212 ( struct V_140 * V_141 ,
const V_379 * V_494 )
{
unsigned int V_273 , V_545 , V_536 , V_546 ;
unsigned int V_547 , V_548 , V_85 ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_465 * V_466 ;
bool V_549 ;
T_5 V_232 = 0 ;
if ( F_174 ( F_153 ( V_2 -> V_550 ) ) )
return 0 ;
V_273 = F_213 ( * V_494 , V_551 ) ;
V_545 = F_213 ( * V_494 , V_552 ) ;
V_536 = F_213 ( * V_494 , V_553 ) ;
V_546 = F_213 ( * V_494 , V_554 ) ;
V_549 = F_213 ( * V_494 , V_555 ) ;
if ( F_213 ( * V_494 , V_556 ) )
F_168 ( V_2 -> V_28 , L_46
V_557 L_28 ,
F_214 ( * V_494 ) ) ;
V_466 = F_215 ( V_141 ) ;
if ( F_174 ( V_536 != F_192 ( V_466 ) ) )
F_207 ( V_466 , V_536 ) ;
V_547 = ( ( V_545 - V_466 -> V_542 ) &
( ( 1 << V_558 ) - 1 ) ) ;
if ( V_547 != V_466 -> V_469 + 1 ) {
struct V_15 * V_16 = V_2 -> V_16 ;
if ( F_174 ( V_547 == V_466 -> V_469 ) ) {
if ( V_466 -> V_469 == 0 || V_273 != 0 )
F_168 ( V_2 -> V_28 ,
L_47
V_557 L_28 ,
V_466 -> V_469 ,
F_214 ( * V_494 ) ) ;
F_210 ( V_466 ) ;
return 0 ;
}
if ( ! ( V_16 -> V_29 &
( 1 << V_514 ) ) ||
V_466 -> V_469 != 0 || V_549 ) {
F_209 (
V_466 , V_545 ,
( V_466 -> V_542 +
V_466 -> V_469 + 1 ) &
( ( 1 << V_558 ) - 1 ) ) ;
return 0 ;
}
V_466 -> V_469 = 1 ;
V_466 -> V_470 = 0 ;
V_548 = V_547 ;
++ V_141 -> V_559 ;
V_141 -> V_560 += V_548 ;
V_232 |= V_561 ;
} else {
++ V_466 -> V_469 ;
V_466 -> V_470 += V_273 ;
if ( V_549 )
return 0 ;
V_548 = 1 ;
}
if ( F_174 ( F_213 ( * V_494 , V_562 ) ) )
V_232 |= V_543 ;
if ( F_174 ( F_213 ( * V_494 , V_563 ) ) ) {
V_141 -> V_564 += V_548 ;
} else if ( F_174 ( F_213 ( * V_494 ,
V_565 ) ) ) {
V_141 -> V_566 += V_548 ;
} else if ( V_546 == V_567 ||
V_546 == V_568 ) {
V_232 |= V_569 ;
}
if ( V_546 == V_567 )
V_232 |= V_570 ;
V_141 -> V_571 += 2 * V_548 ;
for ( V_85 = 0 ; V_85 < V_548 ; V_85 ++ ) {
F_211 ( V_466 ,
V_466 -> V_542 & V_466 -> V_378 ,
V_466 -> V_469 , V_466 -> V_470 ,
V_232 ) ;
V_466 -> V_542 += V_466 -> V_469 ;
}
V_466 -> V_469 = 0 ;
V_466 -> V_470 = 0 ;
return V_548 ;
}
static int
F_216 ( struct V_140 * V_141 , V_379 * V_494 )
{
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_142 * V_143 ;
unsigned int V_572 ;
unsigned int V_573 ;
int V_574 = 0 ;
if ( F_174 ( F_153 ( V_2 -> V_550 ) ) )
return 0 ;
if ( F_174 ( F_213 ( * V_494 , V_575 ) ) )
return 0 ;
V_572 = F_213 ( * V_494 , V_576 ) ;
V_573 = F_213 ( * V_494 , V_577 ) ;
V_143 = F_217 ( V_141 ,
V_573 % V_212 ) ;
V_574 = ( ( V_572 + 1 - V_143 -> V_578 ) &
V_143 -> V_378 ) ;
F_218 ( V_143 , V_572 & V_143 -> V_378 ) ;
return V_574 ;
}
static void
F_219 ( struct V_140 * V_141 , V_379 * V_494 )
{
struct V_1 * V_2 = V_141 -> V_2 ;
int V_579 ;
V_579 = F_213 ( * V_494 , V_580 ) ;
switch ( V_579 ) {
case V_581 :
case V_582 :
break;
case V_583 :
break;
default:
F_14 ( V_2 , V_402 , V_2 -> V_28 ,
L_48
L_49 V_557 L_50 ,
V_141 -> V_141 , V_579 ,
F_214 ( * V_494 ) ) ;
}
}
static void F_220 ( struct V_140 * V_141 ,
V_379 * V_494 )
{
struct V_1 * V_2 = V_141 -> V_2 ;
T_6 V_579 ;
V_579 = F_213 ( * V_494 , V_584 ) ;
switch ( V_579 ) {
case V_585 :
V_141 -> V_586 = F_151 () ;
break;
case V_498 :
F_221 ( & V_141 -> V_466 , true ) ;
break;
default:
F_14 ( V_2 , V_402 , V_2 -> V_28 ,
L_51
L_49 V_557 L_50 ,
V_141 -> V_141 , ( unsigned ) V_579 ,
F_214 ( * V_494 ) ) ;
}
}
static int F_222 ( struct V_140 * V_141 , int V_587 )
{
struct V_1 * V_2 = V_141 -> V_2 ;
V_379 V_494 , * V_588 ;
unsigned int V_589 ;
int V_590 ;
int V_574 = 0 ;
int V_591 = 0 ;
if ( V_587 <= 0 )
return V_591 ;
V_589 = V_141 -> V_592 ;
for (; ; ) {
V_588 = F_223 ( V_141 , V_589 ) ;
V_494 = * V_588 ;
if ( ! F_224 ( & V_494 ) )
break;
F_225 ( * V_588 ) ;
++ V_589 ;
V_590 = F_213 ( V_494 , V_495 ) ;
F_150 ( V_2 , V_27 , V_2 -> V_28 ,
L_52 V_557 L_28 ,
V_141 -> V_141 , F_214 ( V_494 ) ) ;
switch ( V_590 ) {
case V_593 :
F_226 ( V_141 , & V_494 ) ;
break;
case V_594 :
V_591 += F_212 ( V_141 , & V_494 ) ;
if ( V_591 >= V_587 ) {
V_591 = V_587 ;
goto V_332;
}
break;
case V_595 :
V_574 += F_216 ( V_141 , & V_494 ) ;
if ( V_574 > V_2 -> V_596 ) {
V_591 = V_587 ;
goto V_332;
} else if ( ++ V_591 == V_587 ) {
goto V_332;
}
break;
case V_597 :
F_219 ( V_141 , & V_494 ) ;
if ( ++ V_591 == V_587 )
goto V_332;
break;
case V_496 :
F_220 ( V_141 , & V_494 ) ;
break;
default:
F_14 ( V_2 , V_402 , V_2 -> V_28 ,
L_53
L_49 V_557 L_50 ,
V_141 -> V_141 , V_590 ,
F_214 ( V_494 ) ) ;
}
}
V_332:
V_141 -> V_592 = V_589 ;
return V_591 ;
}
static void F_227 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = V_141 -> V_2 ;
T_1 V_598 ;
if ( F_135 ( V_2 ) ) {
F_13 ( V_599 <
( 1 << V_600 ) ) ;
F_13 ( V_510 >
( 1 << 2 * V_600 ) ) ;
F_138 ( V_598 , V_601 ,
V_602 ,
V_603 ,
( V_141 -> V_592 &
V_141 -> V_506 ) >>
V_600 ) ;
F_137 ( V_2 , & V_598 , V_341 ,
V_141 -> V_141 ) ;
F_138 ( V_598 , V_601 ,
V_604 ,
V_603 ,
V_141 -> V_592 &
( ( 1 << V_600 ) - 1 ) ) ;
F_137 ( V_2 , & V_598 , V_341 ,
V_141 -> V_141 ) ;
} else {
F_172 ( V_598 , V_605 ,
V_141 -> V_592 &
V_141 -> V_506 ) ;
F_137 ( V_2 , & V_598 , V_606 , V_141 -> V_141 ) ;
}
}
static void F_228 ( struct V_140 * V_141 )
{
F_8 ( V_47 , V_493 ) ;
struct V_1 * V_2 = V_141 -> V_2 ;
V_379 V_494 ;
int V_18 ;
F_197 ( V_494 ,
V_495 , V_496 ,
V_497 , V_585 ) ;
F_21 ( V_47 , V_499 , V_141 -> V_141 ) ;
memcpy ( F_19 ( V_47 , V_500 ) , & V_494 . T_8 [ 0 ] ,
sizeof( V_379 ) ) ;
V_18 = F_9 ( V_2 , V_501 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_152;
return;
V_152:
F_22 ( true ) ;
F_14 ( V_2 , V_402 , V_2 -> V_28 , L_31 , V_462 , V_18 ) ;
}
void F_229 ( struct V_1 * V_2 )
{
if ( F_230 ( & V_2 -> V_331 ) )
F_231 ( & V_2 -> V_607 ) ;
F_22 ( F_131 ( & V_2 -> V_331 ) < 0 ) ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_465 * V_466 ;
int V_608 ;
if ( V_16 -> V_222 ) {
F_233 ( & V_2 -> V_331 , 0 ) ;
return 0 ;
}
if ( V_2 -> V_609 != V_610 ) {
F_80 (channel, efx) {
F_234 (rx_queue, channel)
F_193 ( V_466 ) ;
F_81 (tx_queue, channel)
F_169 ( V_143 ) ;
}
F_235 ( V_2 -> V_607 ,
F_131 ( & V_2 -> V_331 ) == 0 ,
F_236 ( V_611 ) ) ;
V_608 = F_131 ( & V_2 -> V_331 ) ;
if ( V_608 ) {
F_14 ( V_2 , V_402 , V_2 -> V_28 , L_54 ,
V_608 ) ;
return - V_612 ;
}
}
return 0 ;
}
static void F_237 ( struct V_1 * V_2 )
{
F_233 ( & V_2 -> V_331 , 0 ) ;
}
static bool F_238 ( const struct V_613 * V_614 ,
const struct V_613 * V_615 )
{
if ( ( V_614 -> V_616 ^ V_615 -> V_616 ) |
( ( V_614 -> V_232 ^ V_615 -> V_232 ) &
( V_617 | V_618 ) ) )
return false ;
return memcmp ( & V_614 -> V_619 , & V_615 -> V_619 ,
sizeof( struct V_613 ) -
F_239 ( struct V_613 , V_619 ) ) == 0 ;
}
static unsigned int F_240 ( const struct V_613 * V_620 )
{
F_13 ( F_239 ( struct V_613 , V_619 ) & 3 ) ;
return F_241 ( ( const T_6 * ) & V_620 -> V_619 ,
( sizeof( struct V_613 ) -
F_239 ( struct V_613 , V_619 ) ) / 4 ,
0 ) ;
}
static bool F_242 ( const struct V_613 * V_620 )
{
if ( V_620 -> V_616 & V_621 &&
! F_243 ( V_620 -> V_622 ) )
return true ;
if ( ( V_620 -> V_616 &
( V_623 | V_624 ) ) ==
( V_623 | V_624 ) ) {
if ( V_620 -> V_625 == F_244 ( V_626 ) &&
! F_245 ( V_620 -> V_627 [ 0 ] ) )
return true ;
if ( V_620 -> V_625 == F_244 ( V_628 ) &&
( ( const T_3 * ) V_620 -> V_627 ) [ 0 ] != 0xff )
return true ;
}
return false ;
}
static struct V_613 *
F_246 ( const struct V_629 * V_630 ,
unsigned int V_631 )
{
return (struct V_613 * ) ( V_630 -> V_632 [ V_631 ] . V_620 &
~ V_633 ) ;
}
static unsigned int
F_247 ( const struct V_629 * V_630 ,
unsigned int V_631 )
{
return V_630 -> V_632 [ V_631 ] . V_620 & V_633 ;
}
static void
F_248 ( struct V_629 * V_630 ,
unsigned int V_631 ,
const struct V_613 * V_620 ,
unsigned int V_232 )
{
V_630 -> V_632 [ V_631 ] . V_620 = ( unsigned long ) V_620 | V_232 ;
}
static void F_249 ( struct V_1 * V_2 ,
const struct V_613 * V_620 ,
T_1 * V_47 , T_8 V_634 ,
bool V_635 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_6 V_232 = V_620 -> V_232 ;
memset ( V_47 , 0 , V_636 ) ;
if ( V_232 & V_637 &&
V_620 -> V_638 == V_639 &&
V_16 -> V_93 == V_94 )
V_232 &= ~ V_637 ;
if ( V_635 ) {
F_21 ( V_47 , V_640 ,
V_641 ) ;
F_129 ( V_47 , V_642 , V_634 ) ;
} else {
T_6 V_643 = 0 ;
F_21 ( V_47 , V_640 ,
F_242 ( V_620 ) ?
V_644 :
V_645 ) ;
if ( V_620 -> V_616 & V_646 )
V_643 |=
F_243 ( V_620 -> V_622 ) ?
1 << V_647 :
1 << V_648 ;
#define F_250 ( T_13 , T_14 , T_15 ) \
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
F_250 ( V_649 , V_650 , V_651 ) ;
F_250 ( V_652 , V_627 , V_653 ) ;
F_250 ( V_654 , V_655 , V_656 ) ;
F_250 ( V_657 , V_658 , V_659 ) ;
F_250 ( V_660 , V_622 , V_661 ) ;
F_250 ( V_662 , V_663 , V_664 ) ;
F_250 ( V_665 , V_625 , V_665 ) ;
F_250 ( V_666 , V_667 , V_668 ) ;
F_250 ( V_669 , V_619 , V_670 ) ;
F_250 ( V_671 , V_672 , V_671 ) ;
#undef F_250
F_21 ( V_47 , V_673 ,
V_643 ) ;
}
F_21 ( V_47 , V_674 , V_16 -> V_95 ) ;
F_21 ( V_47 , V_675 ,
V_620 -> V_676 == V_677 ?
V_678 :
V_679 ) ;
F_21 ( V_47 , V_680 , 0 ) ;
F_21 ( V_47 , V_681 ,
V_682 ) ;
F_21 ( V_47 , V_683 ,
V_620 -> V_676 == V_677 ?
0 : V_620 -> V_676 ) ;
F_21 ( V_47 , V_684 ,
( V_232 & V_637 ) ?
V_685 :
V_686 ) ;
if ( V_232 & V_637 )
F_21 ( V_47 , V_687 ,
V_620 -> V_638 !=
V_639 ?
V_620 -> V_638 : V_16 -> V_93 ) ;
}
static int F_251 ( struct V_1 * V_2 ,
const struct V_613 * V_620 ,
T_8 * V_634 , bool V_635 )
{
F_8 ( V_47 , V_636 ) ;
F_8 ( V_13 , V_688 ) ;
int V_18 ;
F_249 ( V_2 , V_620 , V_47 , * V_634 , V_635 ) ;
V_18 = F_9 ( V_2 , V_689 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , NULL ) ;
if ( V_18 == 0 )
* V_634 = F_252 ( V_13 , V_690 ) ;
if ( V_18 == - V_136 )
V_18 = - V_197 ;
return V_18 ;
}
static T_6 F_253 ( const struct V_613 * V_620 )
{
unsigned int V_616 = V_620 -> V_616 ;
T_6 V_691 = 0 ;
if ( V_616 & V_646 ) {
V_616 &= ~ V_646 ;
V_691 |=
F_243 ( V_620 -> V_622 ) ?
( 1 << V_647 ) :
( 1 << V_648 ) ;
}
#define F_254 ( T_13 , T_15 ) { \
unsigned int old_match_flags = match_flags; \
match_flags &= ~EFX_FILTER_MATCH_ ## gen_flag; \
if (match_flags != old_match_flags) \
mcdi_flags |= \
(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
}
F_254 ( V_649 , V_651 ) ;
F_254 ( V_652 , V_653 ) ;
F_254 ( V_654 , V_656 ) ;
F_254 ( V_657 , V_659 ) ;
F_254 ( V_660 , V_661 ) ;
F_254 ( V_662 , V_664 ) ;
F_254 ( V_665 , V_665 ) ;
F_254 ( V_666 , V_668 ) ;
F_254 ( V_669 , V_670 ) ;
F_254 ( V_671 , V_671 ) ;
#undef F_254
F_132 ( V_616 ) ;
return V_691 ;
}
static int F_255 ( struct V_629 * V_630 ,
const struct V_613 * V_620 )
{
T_6 V_691 = F_253 ( V_620 ) ;
unsigned int V_692 ;
for ( V_692 = 0 ;
V_692 < V_630 -> V_693 ;
V_692 ++ )
if ( V_630 -> V_694 [ V_692 ] == V_691 )
return V_692 ;
return - V_695 ;
}
static T_16 F_256 ( struct V_1 * V_2 ,
struct V_613 * V_620 ,
bool V_696 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
F_113 ( V_697 , V_698 ) ;
struct V_613 * V_699 ;
unsigned int V_692 , V_700 ;
unsigned int V_701 ;
bool V_635 = false ;
int V_702 = - 1 ;
F_257 ( V_703 ) ;
bool V_704 ;
T_16 V_18 ;
if ( ( V_620 -> V_232 & ( V_617 | V_618 ) ) !=
V_617 )
return - V_243 ;
V_18 = F_255 ( V_630 , V_620 ) ;
if ( V_18 < 0 )
return V_18 ;
V_692 = V_18 ;
V_700 = F_240 ( V_620 ) ;
V_704 = F_258 ( V_620 ) ;
if ( V_704 )
F_259 ( V_697 , V_698 ) ;
for (; ; ) {
unsigned int V_705 = 1 ;
unsigned int V_85 ;
F_128 ( & V_2 -> V_706 ) ;
for (; ; ) {
V_85 = ( V_700 + V_705 ) & ( V_707 - 1 ) ;
V_699 = F_246 ( V_630 , V_85 ) ;
if ( ! V_699 ) {
if ( V_702 < 0 )
V_702 = V_85 ;
} else if ( F_238 ( V_620 , V_699 ) ) {
if ( V_630 -> V_632 [ V_85 ] . V_620 &
V_708 )
break;
if ( V_620 -> V_709 < V_699 -> V_709 &&
V_620 -> V_709 != V_710 ) {
V_18 = - V_113 ;
goto V_711;
}
if ( ! V_704 ) {
if ( V_620 -> V_709 ==
V_699 -> V_709 &&
! V_696 ) {
V_18 = - V_712 ;
goto V_711;
}
V_702 = V_85 ;
goto V_713;
} else if ( V_620 -> V_709 >
V_699 -> V_709 ||
( V_620 -> V_709 ==
V_699 -> V_709 &&
V_696 ) ) {
if ( V_702 < 0 )
V_702 = V_85 ;
else
F_260 ( V_705 , V_697 ) ;
}
}
if ( V_705 == V_698 ) {
if ( V_702 < 0 ) {
V_18 = - V_197 ;
goto V_711;
}
goto V_713;
}
++ V_705 ;
}
F_261 ( & V_630 -> V_714 , & V_703 , V_715 ) ;
F_126 ( & V_2 -> V_706 ) ;
F_262 () ;
}
V_713:
V_699 = F_246 ( V_630 , V_702 ) ;
if ( V_699 ) {
if ( V_620 -> V_709 == V_710 &&
V_699 -> V_709 >= V_710 ) {
if ( V_699 -> V_709 > V_710 )
V_699 -> V_232 |= V_716 ;
V_630 -> V_632 [ V_702 ] . V_620 &=
~ V_717 ;
V_18 = V_702 ;
goto V_711;
}
V_635 = true ;
V_701 = F_247 ( V_630 , V_702 ) ;
} else {
V_699 = F_263 ( sizeof( * V_620 ) , V_323 ) ;
if ( ! V_699 ) {
V_18 = - V_73 ;
goto V_711;
}
* V_699 = * V_620 ;
V_701 = 0 ;
}
F_248 ( V_630 , V_702 , V_699 ,
V_701 | V_708 ) ;
if ( V_704 ) {
unsigned int V_705 , V_85 ;
for ( V_705 = 0 ; V_705 < V_698 ; V_705 ++ ) {
V_85 = ( V_700 + V_705 ) & ( V_707 - 1 ) ;
if ( F_264 ( V_705 , V_697 ) )
V_630 -> V_632 [ V_85 ] . V_620 |=
V_708 ;
}
}
F_126 ( & V_2 -> V_706 ) ;
V_18 = F_251 ( V_2 , V_620 , & V_630 -> V_632 [ V_702 ] . V_634 ,
V_635 ) ;
F_128 ( & V_2 -> V_706 ) ;
if ( V_18 == 0 ) {
if ( V_635 ) {
if ( V_699 -> V_709 == V_710 )
V_699 -> V_232 |=
V_716 ;
V_699 -> V_709 = V_620 -> V_709 ;
V_699 -> V_232 &= V_716 ;
V_699 -> V_232 |= V_620 -> V_232 ;
V_699 -> V_638 = V_620 -> V_638 ;
V_699 -> V_676 = V_620 -> V_676 ;
}
} else if ( ! V_635 ) {
F_40 ( V_699 ) ;
V_699 = NULL ;
}
F_248 ( V_630 , V_702 , V_699 , V_701 ) ;
if ( V_704 ) {
F_8 ( V_47 , V_636 ) ;
unsigned int V_705 , V_85 ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
for ( V_705 = 0 ; V_705 < V_698 ; V_705 ++ ) {
if ( ! F_264 ( V_705 , V_697 ) )
continue;
V_85 = ( V_700 + V_705 ) & ( V_707 - 1 ) ;
V_699 = F_246 ( V_630 , V_85 ) ;
V_701 = F_247 ( V_630 , V_85 ) ;
if ( V_18 == 0 ) {
F_126 ( & V_2 -> V_706 ) ;
F_21 ( V_47 , V_640 ,
V_718 ) ;
F_129 ( V_47 , V_642 ,
V_630 -> V_632 [ V_85 ] . V_634 ) ;
V_18 = F_9 ( V_2 , V_689 ,
V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
F_128 ( & V_2 -> V_706 ) ;
}
if ( V_18 == 0 ) {
F_40 ( V_699 ) ;
V_699 = NULL ;
V_701 = 0 ;
} else {
V_701 &= ~ V_708 ;
}
F_248 ( V_630 , V_85 , V_699 ,
V_701 ) ;
}
}
if ( V_18 == 0 )
V_18 = V_692 * V_707 + V_702 ;
F_265 ( & V_630 -> V_714 ) ;
V_711:
F_126 ( & V_2 -> V_706 ) ;
F_266 ( & V_630 -> V_714 , & V_703 ) ;
return V_18 ;
}
static void F_267 ( struct V_1 * V_2 )
{
}
static int F_268 ( struct V_1 * V_2 ,
unsigned int V_719 ,
T_6 V_720 , bool V_721 )
{
unsigned int V_631 = V_720 % V_707 ;
struct V_629 * V_630 = V_2 -> V_78 ;
F_8 ( V_47 ,
V_722 +
V_723 ) ;
struct V_613 * V_620 ;
F_257 ( V_703 ) ;
int V_18 ;
for (; ; ) {
F_128 ( & V_2 -> V_706 ) ;
if ( ! ( V_630 -> V_632 [ V_631 ] . V_620 &
V_708 ) )
break;
F_261 ( & V_630 -> V_714 , & V_703 , V_715 ) ;
F_126 ( & V_2 -> V_706 ) ;
F_262 () ;
}
V_620 = F_246 ( V_630 , V_631 ) ;
if ( ! V_620 ||
( ! V_721 &&
F_255 ( V_630 , V_620 ) !=
V_720 / V_707 ) ) {
V_18 = - V_82 ;
goto V_711;
}
if ( V_620 -> V_232 & V_716 &&
V_719 == ( 1U << V_710 ) ) {
V_620 -> V_232 &= ~ V_716 ;
V_630 -> V_632 [ V_631 ] . V_620 &= ~ V_717 ;
V_18 = 0 ;
goto V_711;
}
if ( ! ( V_719 & ( 1U << V_620 -> V_709 ) ) ) {
V_18 = - V_82 ;
goto V_711;
}
V_630 -> V_632 [ V_631 ] . V_620 |= V_708 ;
F_126 ( & V_2 -> V_706 ) ;
if ( V_620 -> V_232 & V_716 ) {
struct V_613 V_724 = * V_620 ;
V_724 . V_709 = V_710 ;
V_724 . V_232 = ( V_617 |
( F_269 ( V_2 ) ?
V_637 : 0 ) ) ;
V_724 . V_676 = 0 ;
V_724 . V_638 = V_639 ;
V_18 = F_251 ( V_2 , & V_724 ,
& V_630 -> V_632 [ V_631 ] . V_634 ,
true ) ;
F_128 ( & V_2 -> V_706 ) ;
if ( V_18 == 0 )
* V_620 = V_724 ;
} else {
F_21 ( V_47 , V_640 ,
F_242 ( V_620 ) ?
V_725 :
V_718 ) ;
F_129 ( V_47 , V_642 ,
V_630 -> V_632 [ V_631 ] . V_634 ) ;
V_18 = F_9 ( V_2 , V_689 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
F_128 ( & V_2 -> V_706 ) ;
if ( V_18 == 0 ) {
F_40 ( V_620 ) ;
F_248 ( V_630 , V_631 , NULL , 0 ) ;
}
}
V_630 -> V_632 [ V_631 ] . V_620 &= ~ V_708 ;
F_265 ( & V_630 -> V_714 ) ;
V_711:
F_126 ( & V_2 -> V_706 ) ;
F_266 ( & V_630 -> V_714 , & V_703 ) ;
return V_18 ;
}
static int F_270 ( struct V_1 * V_2 ,
enum V_726 V_709 ,
T_6 V_720 )
{
return F_268 ( V_2 , 1U << V_709 ,
V_720 , false ) ;
}
static T_6 F_271 ( struct V_1 * V_2 , T_6 V_720 )
{
return V_720 % V_707 ;
}
static void F_272 ( struct V_1 * V_2 ,
enum V_726 V_709 ,
T_6 V_720 )
{
if ( V_720 == V_727 )
return;
F_268 ( V_2 , 1U << V_709 , V_720 , true ) ;
}
static int F_273 ( struct V_1 * V_2 ,
enum V_726 V_709 ,
T_6 V_720 , struct V_613 * V_620 )
{
unsigned int V_631 = V_720 % V_707 ;
struct V_629 * V_630 = V_2 -> V_78 ;
const struct V_613 * V_699 ;
int V_18 ;
F_128 ( & V_2 -> V_706 ) ;
V_699 = F_246 ( V_630 , V_631 ) ;
if ( V_699 && V_699 -> V_709 == V_709 &&
F_255 ( V_630 , V_699 ) ==
V_720 / V_707 ) {
* V_620 = * V_699 ;
V_18 = 0 ;
} else {
V_18 = - V_82 ;
}
F_126 ( & V_2 -> V_706 ) ;
return V_18 ;
}
static int F_274 ( struct V_1 * V_2 ,
enum V_726 V_709 )
{
unsigned int V_719 ;
unsigned int V_85 ;
int V_18 ;
V_719 = ( ( ( 1U << ( V_709 + 1 ) ) - 1 ) &
~ ( 1U << V_710 ) ) ;
for ( V_85 = 0 ; V_85 < V_707 ; V_85 ++ ) {
V_18 = F_268 ( V_2 , V_719 ,
V_85 , true ) ;
if ( V_18 && V_18 != - V_82 )
return V_18 ;
}
return 0 ;
}
static T_6 F_275 ( struct V_1 * V_2 ,
enum V_726 V_709 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
unsigned int V_631 ;
T_16 V_728 = 0 ;
F_128 ( & V_2 -> V_706 ) ;
for ( V_631 = 0 ; V_631 < V_707 ; V_631 ++ ) {
if ( V_630 -> V_632 [ V_631 ] . V_620 &&
F_246 ( V_630 , V_631 ) -> V_709 ==
V_709 )
++ V_728 ;
}
F_126 ( & V_2 -> V_706 ) ;
return V_728 ;
}
static T_6 F_276 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
return V_630 -> V_693 * V_707 ;
}
static T_16 F_277 ( struct V_1 * V_2 ,
enum V_726 V_709 ,
T_6 * V_61 , T_6 V_729 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_613 * V_620 ;
unsigned int V_631 ;
T_16 V_728 = 0 ;
F_128 ( & V_2 -> V_706 ) ;
for ( V_631 = 0 ; V_631 < V_707 ; V_631 ++ ) {
V_620 = F_246 ( V_630 , V_631 ) ;
if ( V_620 && V_620 -> V_709 == V_709 ) {
if ( V_728 == V_729 ) {
V_728 = - V_730 ;
break;
}
V_61 [ V_728 ++ ] = ( F_255 ( V_630 , V_620 ) *
V_707 +
V_631 ) ;
}
}
F_126 ( & V_2 -> V_706 ) ;
return V_728 ;
}
static T_16 F_278 ( struct V_1 * V_2 ,
struct V_613 * V_620 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
F_8 ( V_47 , V_636 ) ;
struct V_613 * V_699 ;
unsigned int V_700 , V_85 , V_705 = 1 ;
bool V_635 = false ;
int V_702 = - 1 ;
T_8 V_503 ;
T_16 V_18 ;
F_279 ( V_620 -> V_232 !=
( V_617 | V_731 ) ) ;
F_279 ( V_620 -> V_709 != V_732 ) ;
F_279 ( F_258 ( V_620 ) ) ;
V_700 = F_240 ( V_620 ) ;
F_128 ( & V_2 -> V_706 ) ;
for (; ; ) {
V_85 = ( V_700 + V_705 ) & ( V_707 - 1 ) ;
V_699 = F_246 ( V_630 , V_85 ) ;
if ( ! V_699 ) {
if ( V_702 < 0 )
V_702 = V_85 ;
} else if ( F_238 ( V_620 , V_699 ) ) {
if ( V_630 -> V_632 [ V_85 ] . V_620 & V_708 ) {
V_18 = - V_197 ;
goto V_733;
}
if ( V_620 -> V_709 < V_699 -> V_709 ) {
V_18 = - V_113 ;
goto V_733;
}
V_702 = V_85 ;
break;
}
if ( V_705 == V_698 ) {
if ( V_702 < 0 ) {
V_18 = - V_197 ;
goto V_733;
}
break;
}
++ V_705 ;
}
V_699 = F_246 ( V_630 , V_702 ) ;
if ( V_699 ) {
V_635 = true ;
} else {
V_699 = F_263 ( sizeof( * V_620 ) , V_323 ) ;
if ( ! V_699 ) {
V_18 = - V_73 ;
goto V_733;
}
* V_699 = * V_620 ;
}
F_248 ( V_630 , V_702 , V_699 ,
V_708 ) ;
F_126 ( & V_2 -> V_706 ) ;
V_503 = V_635 << 31 | V_702 << 16 | V_620 -> V_676 ;
F_249 ( V_2 , V_620 , V_47 ,
V_630 -> V_632 [ V_702 ] . V_634 , V_635 ) ;
F_200 ( V_2 , V_689 , V_47 , sizeof( V_47 ) ,
V_688 ,
V_734 , V_503 ) ;
return V_702 ;
V_733:
F_126 ( & V_2 -> V_706 ) ;
return V_18 ;
}
static void
V_734 ( struct V_1 * V_2 , unsigned long V_503 ,
int V_18 , T_1 * V_13 ,
T_2 V_504 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
unsigned int V_702 , V_676 ;
struct V_613 * V_620 ;
bool V_635 ;
V_635 = V_503 >> 31 ;
V_702 = ( V_503 >> 16 ) & ( V_707 - 1 ) ;
V_676 = V_503 & 0xffff ;
F_128 ( & V_2 -> V_706 ) ;
V_620 = F_246 ( V_630 , V_702 ) ;
if ( V_18 == 0 ) {
V_630 -> V_632 [ V_702 ] . V_634 =
F_252 ( V_13 , V_690 ) ;
if ( V_635 )
V_620 -> V_676 = V_676 ;
} else if ( ! V_635 ) {
F_40 ( V_620 ) ;
V_620 = NULL ;
}
F_248 ( V_630 , V_702 , V_620 , 0 ) ;
F_126 ( & V_2 -> V_706 ) ;
F_265 ( & V_630 -> V_714 ) ;
}
static bool F_280 ( struct V_1 * V_2 , T_6 V_735 ,
unsigned int V_631 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_613 * V_620 =
F_246 ( V_630 , V_631 ) ;
F_8 ( V_47 ,
V_722 +
V_723 ) ;
if ( ! V_620 ||
( V_630 -> V_632 [ V_631 ] . V_620 & V_708 ) ||
V_620 -> V_709 != V_732 ||
! F_281 ( V_2 -> V_28 , V_620 -> V_676 ,
V_735 , V_631 ) )
return false ;
F_21 ( V_47 , V_640 ,
V_725 ) ;
F_129 ( V_47 , V_642 ,
V_630 -> V_632 [ V_631 ] . V_634 ) ;
if ( F_200 ( V_2 , V_689 , V_47 , sizeof( V_47 ) , 0 ,
V_736 , V_631 ) )
return false ;
V_630 -> V_632 [ V_631 ] . V_620 |= V_708 ;
return true ;
}
static void
V_736 ( struct V_1 * V_2 ,
unsigned long V_631 ,
int V_18 , T_1 * V_13 ,
T_2 V_504 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_613 * V_620 =
F_246 ( V_630 , V_631 ) ;
F_128 ( & V_2 -> V_706 ) ;
if ( V_18 == 0 ) {
F_40 ( V_620 ) ;
F_248 ( V_630 , V_631 , NULL , 0 ) ;
}
V_630 -> V_632 [ V_631 ] . V_620 &= ~ V_708 ;
F_265 ( & V_630 -> V_714 ) ;
F_126 ( & V_2 -> V_706 ) ;
}
static int F_282 ( T_6 V_691 )
{
int V_616 = 0 ;
#define F_283 ( T_13 , T_15 ) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
F_283 ( V_737 , V_738 ) ;
F_283 ( V_737 , V_739 ) ;
F_283 ( V_649 , V_651 ) ;
F_283 ( V_652 , V_653 ) ;
F_283 ( V_654 , V_656 ) ;
F_283 ( V_657 , V_659 ) ;
F_283 ( V_660 , V_661 ) ;
F_283 ( V_662 , V_664 ) ;
F_283 ( V_665 , V_665 ) ;
F_283 ( V_666 , V_668 ) ;
F_283 ( V_669 , V_670 ) ;
F_283 ( V_671 , V_671 ) ;
#undef F_283
if ( V_691 )
return - V_243 ;
return V_616 ;
}
static void F_284 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_740 * V_68 , * V_83 ;
if ( ! F_285 ( & V_2 -> V_80 ) )
return;
if ( ! V_630 )
return;
F_45 (vlan, next_vlan, &table->vlan_list, list)
F_286 ( V_2 , V_68 ) ;
}
static bool F_287 ( struct V_629 * V_630 ,
enum V_741 V_616 )
{
unsigned int V_692 ;
int V_742 ;
for ( V_692 = 0 ;
V_692 < V_630 -> V_693 ;
V_692 ++ ) {
V_742 = F_282 (
V_630 -> V_694 [ V_692 ] ) ;
if ( V_742 == V_616 )
return true ;
}
return false ;
}
static int F_288 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_743 ) ;
F_8 ( V_13 , V_744 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_84 * V_28 = V_2 -> V_28 ;
unsigned int V_745 , V_746 ;
struct V_629 * V_630 ;
struct V_66 * V_68 ;
T_2 V_17 ;
int V_18 ;
if ( ! F_285 ( & V_2 -> V_80 ) )
return - V_243 ;
if ( V_2 -> V_78 )
return 0 ;
V_630 = F_33 ( sizeof( * V_630 ) , V_74 ) ;
if ( ! V_630 )
return - V_73 ;
F_21 ( V_47 , V_747 ,
V_748 ) ;
V_18 = F_9 ( V_2 , V_749 ,
V_47 , sizeof( V_47 ) , V_13 , sizeof( V_13 ) ,
& V_17 ) ;
if ( V_18 )
goto V_152;
V_746 = F_289 (
V_17 , V_750 ) ;
V_630 -> V_693 = 0 ;
for ( V_745 = 0 ; V_745 < V_746 ; V_745 ++ ) {
T_6 V_691 =
F_290 (
V_13 ,
V_750 ,
V_745 ) ;
V_18 = F_282 ( V_691 ) ;
if ( V_18 < 0 ) {
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_55 ,
V_462 , V_691 , V_745 ) ;
} else {
F_59 ( V_2 , V_36 , V_2 -> V_28 ,
L_56 ,
V_462 , V_691 , V_745 ,
V_18 , V_630 -> V_693 ) ;
V_630 -> V_694 [ V_630 -> V_693 ] = V_691 ;
V_630 -> V_693 ++ ;
}
}
if ( ( F_291 ( V_2 ) & V_751 ) &&
! ( F_287 ( V_630 ,
( V_752 | V_621 ) ) &&
F_287 ( V_630 ,
( V_752 | V_646 ) ) ) ) {
F_85 ( V_2 , V_36 , V_28 ,
L_57 ) ;
V_28 -> V_753 &= ~ V_751 ;
V_2 -> V_754 &= ~ V_751 ;
V_28 -> V_755 &= ~ V_751 ;
}
V_630 -> V_632 = F_292 ( V_707 * sizeof( * V_630 -> V_632 ) ) ;
if ( ! V_630 -> V_632 ) {
V_18 = - V_73 ;
goto V_152;
}
V_630 -> V_756 = false ;
V_630 -> V_757 =
! ! ( V_2 -> V_28 -> V_753 & V_751 ) ;
F_63 ( & V_630 -> V_77 ) ;
V_2 -> V_78 = V_630 ;
F_293 ( & V_630 -> V_714 ) ;
F_29 (vlan, &nic_data->vlan_list, list) {
V_18 = F_36 ( V_2 , V_68 -> V_67 ) ;
if ( V_18 )
goto V_758;
}
return 0 ;
V_758:
F_284 ( V_2 ) ;
V_2 -> V_78 = NULL ;
V_152:
F_40 ( V_630 ) ;
return V_18 ;
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_613 * V_620 ;
unsigned int V_631 ;
bool V_759 = false ;
int V_18 ;
F_22 ( ! F_295 ( & V_2 -> V_80 ) ) ;
if ( ! V_16 -> V_225 )
return;
if ( ! V_630 )
return;
F_128 ( & V_2 -> V_706 ) ;
for ( V_631 = 0 ; V_631 < V_707 ; V_631 ++ ) {
V_620 = F_246 ( V_630 , V_631 ) ;
if ( ! V_620 )
continue;
V_630 -> V_632 [ V_631 ] . V_620 |= V_708 ;
F_126 ( & V_2 -> V_706 ) ;
V_18 = F_251 ( V_2 , V_620 ,
& V_630 -> V_632 [ V_631 ] . V_634 ,
false ) ;
if ( V_18 )
V_759 = true ;
F_128 ( & V_2 -> V_706 ) ;
if ( V_18 ) {
F_40 ( V_620 ) ;
F_248 ( V_630 , V_631 , NULL , 0 ) ;
} else {
V_630 -> V_632 [ V_631 ] . V_620 &=
~ V_708 ;
}
}
F_126 ( & V_2 -> V_706 ) ;
if ( V_759 )
F_14 ( V_2 , V_402 , V_2 -> V_28 ,
L_58 ) ;
else
V_16 -> V_225 = false ;
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
F_8 ( V_47 , V_636 ) ;
struct V_613 * V_620 ;
unsigned int V_631 ;
int V_18 ;
F_284 ( V_2 ) ;
V_2 -> V_78 = NULL ;
if ( ! F_285 ( & V_2 -> V_80 ) )
return;
if ( ! V_630 )
return;
for ( V_631 = 0 ; V_631 < V_707 ; V_631 ++ ) {
V_620 = F_246 ( V_630 , V_631 ) ;
if ( ! V_620 )
continue;
F_21 ( V_47 , V_640 ,
F_242 ( V_620 ) ?
V_725 :
V_718 ) ;
F_129 ( V_47 , V_642 ,
V_630 -> V_632 [ V_631 ] . V_634 ) ;
V_18 = F_73 ( V_2 , V_689 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
if ( V_18 )
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_59 ,
V_462 , V_631 ) ;
F_40 ( V_620 ) ;
}
F_297 ( V_630 -> V_632 ) ;
F_40 ( V_630 ) ;
}
static void F_298 ( struct V_1 * V_2 , T_17 * V_760 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
unsigned int V_631 ;
if ( * V_760 != V_727 ) {
V_631 = F_271 ( V_2 , * V_760 ) ;
if ( ! V_630 -> V_632 [ V_631 ] . V_620 )
F_59 ( V_2 , V_27 , V_2 -> V_28 ,
L_60 , * V_760 ,
V_631 ) ;
V_630 -> V_632 [ V_631 ] . V_620 |= V_717 ;
* V_760 = V_727 ;
}
}
static void F_299 ( struct V_1 * V_2 ,
struct V_740 * V_68 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
unsigned int V_85 ;
for ( V_85 = 0 ; V_85 < V_630 -> V_761 ; V_85 ++ )
F_298 ( V_2 , & V_68 -> V_762 [ V_85 ] ) ;
for ( V_85 = 0 ; V_85 < V_630 -> V_763 ; V_85 ++ )
F_298 ( V_2 , & V_68 -> V_764 [ V_85 ] ) ;
F_298 ( V_2 , & V_68 -> V_765 ) ;
F_298 ( V_2 , & V_68 -> V_766 ) ;
F_298 ( V_2 , & V_68 -> V_767 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_740 * V_68 ;
F_128 ( & V_2 -> V_706 ) ;
F_29 (vlan, &table->vlan_list, list)
F_299 ( V_2 , V_68 ) ;
F_126 ( & V_2 -> V_706 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_84 * V_28 = V_2 -> V_28 ;
struct V_768 * V_762 ;
int V_769 ;
unsigned int V_85 ;
V_769 = F_302 ( V_28 ) ;
V_630 -> V_770 = ! ! ( V_28 -> V_232 & V_771 ) ;
V_630 -> V_761 = 1 + V_769 ;
F_18 ( V_630 -> V_772 [ 0 ] . V_309 , V_28 -> V_773 ) ;
V_85 = 1 ;
F_303 (uc, net_dev) {
if ( V_85 >= V_774 ) {
V_630 -> V_770 = true ;
break;
}
F_18 ( V_630 -> V_772 [ V_85 ] . V_309 , V_762 -> V_309 ) ;
V_85 ++ ;
}
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_84 * V_28 = V_2 -> V_28 ;
struct V_768 * V_764 ;
unsigned int V_85 , V_769 ;
V_630 -> V_775 = ! ! ( V_28 -> V_232 & ( V_771 | V_776 ) ) ;
V_769 = F_305 ( V_28 ) ;
V_85 = 0 ;
F_306 (mc, net_dev) {
if ( V_85 >= V_777 ) {
V_630 -> V_775 = true ;
break;
}
F_18 ( V_630 -> V_778 [ V_85 ] . V_309 , V_764 -> V_309 ) ;
V_85 ++ ;
}
V_630 -> V_763 = V_85 ;
}
static int F_307 ( struct V_1 * V_2 ,
struct V_740 * V_68 ,
bool V_284 , bool V_779 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_780 * V_781 ;
enum V_782 V_783 ;
struct V_613 V_620 ;
T_3 V_784 [ V_785 ] ;
unsigned int V_85 , V_786 ;
int V_769 ;
T_5 * V_787 ;
int V_18 ;
if ( V_284 ) {
V_781 = V_630 -> V_778 ;
V_769 = V_630 -> V_763 ;
V_787 = V_68 -> V_764 ;
} else {
V_781 = V_630 -> V_772 ;
V_769 = V_630 -> V_761 ;
V_787 = V_68 -> V_762 ;
}
V_783 = F_269 ( V_2 ) ? V_637 : 0 ;
for ( V_85 = 0 ; V_85 < V_769 ; V_85 ++ ) {
F_308 ( & V_620 , V_710 , V_783 , 0 ) ;
F_309 ( & V_620 , V_68 -> V_67 , V_781 [ V_85 ] . V_309 ) ;
V_18 = F_256 ( V_2 , & V_620 , true ) ;
if ( V_18 < 0 ) {
if ( V_779 ) {
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_61 ,
V_18 ) ;
for ( V_786 = 0 ; V_786 < V_85 ; V_786 ++ ) {
F_272 (
V_2 , V_710 ,
V_787 [ V_786 ] ) ;
V_787 [ V_786 ] = V_727 ;
}
return V_18 ;
} else {
V_18 = V_727 ;
}
}
V_787 [ V_85 ] = F_271 ( V_2 , V_18 ) ;
}
if ( V_284 && V_779 ) {
F_308 ( & V_620 , V_710 , V_783 , 0 ) ;
F_310 ( V_784 ) ;
F_309 ( & V_620 , V_68 -> V_67 , V_784 ) ;
V_18 = F_256 ( V_2 , & V_620 , true ) ;
if ( V_18 < 0 ) {
F_32 ( V_2 , V_27 , V_2 -> V_28 ,
L_62 , V_18 ) ;
for ( V_786 = 0 ; V_786 < V_85 ; V_786 ++ ) {
F_272 (
V_2 , V_710 ,
V_787 [ V_786 ] ) ;
V_787 [ V_786 ] = V_727 ;
}
return V_18 ;
} else {
F_279 ( V_68 -> V_766 !=
V_727 ) ;
V_68 -> V_766 = F_271 ( V_2 , V_18 ) ;
}
}
return 0 ;
}
static int F_311 ( struct V_1 * V_2 ,
struct V_740 * V_68 ,
bool V_284 , bool V_779 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
enum V_782 V_783 ;
struct V_613 V_620 ;
T_3 V_784 [ V_785 ] ;
int V_18 ;
V_783 = F_269 ( V_2 ) ? V_637 : 0 ;
F_308 ( & V_620 , V_710 , V_783 , 0 ) ;
if ( V_284 )
F_312 ( & V_620 ) ;
else
F_313 ( & V_620 ) ;
if ( V_68 -> V_67 != V_122 )
F_309 ( & V_620 , V_68 -> V_67 , NULL ) ;
V_18 = F_256 ( V_2 , & V_620 , true ) ;
if ( V_18 < 0 ) {
F_314 ( V_2 , V_27 , V_18 == - V_113 ? V_788 : V_789 ,
V_2 -> V_28 ,
L_63 ,
V_284 ? L_64 : L_65 , V_18 ) ;
} else if ( V_284 ) {
F_279 ( V_68 -> V_767 != V_727 ) ;
V_68 -> V_767 = F_271 ( V_2 , V_18 ) ;
if ( ! V_16 -> V_532 ) {
F_308 ( & V_620 , V_710 ,
V_783 , 0 ) ;
F_310 ( V_784 ) ;
F_309 ( & V_620 , V_68 -> V_67 , V_784 ) ;
V_18 = F_256 ( V_2 , & V_620 , true ) ;
if ( V_18 < 0 ) {
F_32 ( V_2 , V_27 , V_2 -> V_28 ,
L_62 ,
V_18 ) ;
if ( V_779 ) {
F_272 (
V_2 , V_710 ,
V_68 -> V_767 ) ;
V_68 -> V_767 = V_727 ;
return V_18 ;
}
} else {
F_279 ( V_68 -> V_766 !=
V_727 ) ;
V_68 -> V_766 = F_271 ( V_2 , V_18 ) ;
}
}
V_18 = 0 ;
} else {
F_279 ( V_68 -> V_765 != V_727 ) ;
V_68 -> V_765 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static void F_315 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
int V_790 = 0 ;
int V_791 = 0 ;
int V_18 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_707 ; V_85 ++ ) {
if ( F_153 ( V_630 -> V_632 [ V_85 ] . V_620 ) &
V_717 ) {
V_18 = F_268 ( V_2 ,
1U << V_710 , V_85 , true ) ;
if ( V_18 == - V_82 )
V_791 ++ ;
else if ( V_18 )
V_790 ++ ;
}
}
if ( V_790 )
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_66 ,
V_462 , V_790 ) ;
if ( V_791 )
F_85 ( V_2 , V_27 , V_2 -> V_28 ,
L_67 ,
V_462 , V_791 ) ;
}
static int F_316 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
T_3 V_792 [ V_785 ] ;
int V_18 , V_793 ;
if ( F_317 ( V_16 -> V_794 ) )
return 0 ;
F_318 ( V_2 ) ;
F_319 ( V_2 -> V_28 ) ;
F_35 ( & V_2 -> V_80 ) ;
F_296 ( V_2 ) ;
F_37 ( & V_2 -> V_80 ) ;
V_18 = F_91 ( V_2 , V_16 -> V_95 ) ;
if ( V_18 )
goto V_795;
F_18 ( V_792 , V_16 -> V_794 ) ;
V_18 = F_93 ( V_2 , V_16 -> V_95 ,
V_16 -> V_794 ) ;
if ( V_18 )
goto V_796;
V_18 = F_92 ( V_2 , V_16 -> V_95 ,
V_2 -> V_28 -> V_773 ) ;
if ( ! V_18 ) {
F_18 ( V_16 -> V_794 , V_2 -> V_28 -> V_773 ) ;
} else {
V_793 = F_92 ( V_2 , V_16 -> V_95 , V_792 ) ;
if ( V_793 ) {
F_320 ( V_16 -> V_794 ) ;
goto V_797;
}
}
V_796:
V_793 = F_90 ( V_2 , V_16 -> V_95 ) ;
if ( V_793 )
goto V_797;
V_795:
F_35 ( & V_2 -> V_80 ) ;
V_793 = F_288 ( V_2 ) ;
F_37 ( & V_2 -> V_80 ) ;
if ( V_793 )
goto V_797;
V_793 = F_321 ( V_2 -> V_28 ) ;
if ( V_793 )
goto V_797;
F_322 ( V_2 -> V_28 ) ;
return V_18 ;
V_797:
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_68 ) ;
F_208 ( V_2 , V_231 ) ;
return V_18 ? V_18 : V_793 ;
}
static void F_323 ( struct V_1 * V_2 ,
struct V_740 * V_68 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ( V_68 -> V_67 == V_122 ) == V_630 -> V_757 )
return;
if ( V_630 -> V_770 ) {
F_311 ( V_2 , V_68 , false , false ) ;
F_307 ( V_2 , V_68 , false , false ) ;
} else {
if ( F_307 ( V_2 , V_68 , false , false ) )
F_311 ( V_2 , V_68 , false , false ) ;
}
if ( V_16 -> V_532 &&
V_630 -> V_756 != V_630 -> V_775 )
F_315 ( V_2 ) ;
if ( V_630 -> V_775 ) {
if ( V_16 -> V_532 ) {
if ( F_311 ( V_2 , V_68 , true , true ) ) {
F_315 ( V_2 ) ;
F_307 ( V_2 , V_68 ,
true , false ) ;
}
} else {
F_311 ( V_2 , V_68 , true , false ) ;
F_307 ( V_2 , V_68 , true , false ) ;
}
} else {
if ( F_307 ( V_2 , V_68 , true , true ) ) {
if ( V_16 -> V_532 )
F_315 ( V_2 ) ;
if ( F_311 ( V_2 , V_68 , true , true ) )
F_307 ( V_2 , V_68 ,
true , false ) ;
}
}
}
static void F_324 ( struct V_1 * V_2 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_84 * V_28 = V_2 -> V_28 ;
struct V_740 * V_68 ;
bool V_757 ;
if ( ! F_325 ( V_2 ) )
return;
if ( ! V_630 )
return;
F_300 ( V_2 ) ;
F_326 ( V_28 ) ;
F_301 ( V_2 ) ;
F_304 ( V_2 ) ;
F_327 ( V_28 ) ;
V_757 = ! ! ( V_28 -> V_753 & V_751 ) ;
if ( V_630 -> V_757 != V_757 ) {
V_630 -> V_757 = V_757 ;
F_315 ( V_2 ) ;
}
F_29 (vlan, &table->vlan_list, list)
F_323 ( V_2 , V_68 ) ;
F_315 ( V_2 ) ;
V_630 -> V_756 = V_630 -> V_775 ;
}
static struct V_740 * F_328 ( struct V_1 * V_2 , T_5 V_67 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_740 * V_68 ;
F_22 ( ! F_295 ( & V_2 -> V_80 ) ) ;
F_29 (vlan, &table->vlan_list, list) {
if ( V_68 -> V_67 == V_67 )
return V_68 ;
}
return NULL ;
}
static int F_36 ( struct V_1 * V_2 , T_5 V_67 )
{
struct V_629 * V_630 = V_2 -> V_78 ;
struct V_740 * V_68 ;
unsigned int V_85 ;
if ( ! F_285 ( & V_2 -> V_80 ) )
return - V_243 ;
V_68 = F_328 ( V_2 , V_67 ) ;
if ( F_22 ( V_68 ) ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_4 , V_67 ) ;
return - V_71 ;
}
V_68 = F_33 ( sizeof( * V_68 ) , V_74 ) ;
if ( ! V_68 )
return - V_73 ;
V_68 -> V_67 = V_67 ;
for ( V_85 = 0 ; V_85 < F_182 ( V_68 -> V_762 ) ; V_85 ++ )
V_68 -> V_762 [ V_85 ] = V_727 ;
for ( V_85 = 0 ; V_85 < F_182 ( V_68 -> V_764 ) ; V_85 ++ )
V_68 -> V_764 [ V_85 ] = V_727 ;
V_68 -> V_765 = V_727 ;
V_68 -> V_766 = V_727 ;
V_68 -> V_767 = V_727 ;
F_34 ( & V_68 -> V_76 , & V_630 -> V_77 ) ;
if ( F_325 ( V_2 ) )
F_323 ( V_2 , V_68 ) ;
return 0 ;
}
static void F_286 ( struct V_1 * V_2 ,
struct V_740 * V_68 )
{
unsigned int V_85 ;
if ( ! F_285 ( & V_2 -> V_80 ) )
return;
F_39 ( & V_68 -> V_76 ) ;
for ( V_85 = 0 ; V_85 < F_182 ( V_68 -> V_762 ) ; V_85 ++ )
F_272 ( V_2 , V_710 ,
V_68 -> V_762 [ V_85 ] ) ;
for ( V_85 = 0 ; V_85 < F_182 ( V_68 -> V_764 ) ; V_85 ++ )
F_272 ( V_2 , V_710 ,
V_68 -> V_764 [ V_85 ] ) ;
F_272 ( V_2 , V_710 , V_68 -> V_765 ) ;
F_272 ( V_2 , V_710 , V_68 -> V_766 ) ;
F_272 ( V_2 , V_710 , V_68 -> V_767 ) ;
F_40 ( V_68 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_5 V_67 )
{
struct V_740 * V_68 ;
if ( ! F_285 ( & V_2 -> V_80 ) )
return;
V_68 = F_328 ( V_2 , V_67 ) ;
if ( ! V_68 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_69 , V_67 ) ;
return;
}
F_286 ( V_2 , V_68 ) ;
}
static int F_329 ( struct V_1 * V_2 )
{
F_8 ( V_47 , V_798 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
bool V_799 = V_2 -> V_800 ;
int V_18 ;
F_318 ( V_2 ) ;
F_319 ( V_2 -> V_28 ) ;
F_31 ( & V_2 -> V_79 ) ;
F_35 ( & V_2 -> V_80 ) ;
F_296 ( V_2 ) ;
F_18 ( F_19 ( V_47 , V_801 ) ,
V_2 -> V_28 -> V_773 ) ;
F_21 ( V_47 , V_802 ,
V_16 -> V_95 ) ;
V_18 = F_73 ( V_2 , V_803 , V_47 ,
sizeof( V_47 ) , NULL , 0 , NULL ) ;
F_288 ( V_2 ) ;
F_37 ( & V_2 -> V_80 ) ;
F_38 ( & V_2 -> V_79 ) ;
if ( V_799 )
F_321 ( V_2 -> V_28 ) ;
F_322 ( V_2 -> V_28 ) ;
#ifdef F_62
if ( V_2 -> V_10 -> V_168 && V_2 -> V_10 -> V_117 ) {
struct V_10 * V_119 = V_2 -> V_10 -> V_117 ;
if ( V_18 == - V_113 ) {
struct V_1 * V_120 ;
V_120 = F_24 ( V_119 ) ;
V_18 = F_330 ( V_120 ,
V_16 -> V_22 ,
V_2 -> V_28 -> V_773 ) ;
} else if ( ! V_18 ) {
struct V_1 * V_120 = F_24 ( V_119 ) ;
struct V_15 * V_16 = V_120 -> V_16 ;
unsigned int V_85 ;
for ( V_85 = 0 ; V_85 < V_120 -> V_227 ; ++ V_85 ) {
struct V_166 * V_167 = V_16 -> V_167 + V_85 ;
if ( V_167 -> V_2 == V_2 ) {
F_18 ( V_167 -> V_188 ,
V_2 -> V_28 -> V_773 ) ;
return 0 ;
}
}
}
} else
#endif
if ( V_18 == - V_113 ) {
F_14 ( V_2 , V_27 , V_2 -> V_28 ,
L_70
L_71 ) ;
} else if ( V_18 == - V_116 && ! F_6 ( V_2 ) ) {
V_18 = F_316 ( V_2 ) ;
} else {
F_74 ( V_2 , V_803 ,
sizeof( V_47 ) , NULL , 0 , V_18 ) ;
}
return V_18 ;
}
static int F_331 ( struct V_1 * V_2 )
{
F_324 ( V_2 ) ;
return F_332 ( V_2 ) ;
}
static int F_333 ( struct V_1 * V_2 )
{
F_324 ( V_2 ) ;
return 0 ;
}
static int F_334 ( struct V_1 * V_2 , T_6 V_804 )
{
F_8 ( V_47 , V_805 ) ;
F_21 ( V_47 , V_806 , V_804 ) ;
return F_9 ( V_2 , V_807 , V_47 , sizeof( V_47 ) ,
NULL , 0 , NULL ) ;
}
static int F_335 ( struct V_1 * V_2 )
{
int V_18 ;
F_8 ( V_13 , V_808 ) ;
T_2 V_17 ;
T_6 V_809 ;
V_18 = F_9 ( V_2 , V_810 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( V_17 < V_808 )
return - V_7 ;
V_809 = F_10 ( V_13 , V_811 ) ;
switch ( V_809 ) {
case V_812 :
F_59 ( V_2 , V_402 , V_2 -> V_28 , L_72 ) ;
return 0 ;
case V_813 :
F_14 ( V_2 , V_402 , V_2 -> V_28 , L_73 ) ;
return - V_7 ;
case V_814 :
F_14 ( V_2 , V_402 , V_2 -> V_28 , L_74 ) ;
return - V_7 ;
default:
F_14 ( V_2 , V_402 , V_2 -> V_28 ,
L_75 , V_809 ) ;
return - V_7 ;
}
}
static int F_336 ( struct V_1 * V_2 , T_6 V_804 )
{
int V_18 ;
F_59 ( V_2 , V_27 , V_2 -> V_28 , L_76 , V_804 ) ;
V_18 = F_334 ( V_2 , V_804 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_335 ( V_2 ) ;
}
static int
F_337 ( struct V_1 * V_2 , struct V_815 * V_816 )
{
int V_18 , V_793 ;
F_338 ( V_2 , V_242 ) ;
V_18 = F_9 ( V_2 , V_817 ,
NULL , 0 , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
goto V_332;
V_816 -> V_818 = F_336 ( V_2 , V_819 ) ? - 1 : 1 ;
V_816 -> V_820 = F_336 ( V_2 , V_821 ) ? - 1 : 1 ;
V_18 = F_53 ( V_2 , V_242 ) ;
V_332:
if ( V_18 == - V_113 )
V_18 = 0 ;
V_793 = F_339 ( V_2 , V_242 , V_18 == 0 ) ;
return V_18 ? V_18 : V_793 ;
}
static int F_340 ( struct V_1 * V_2 ,
struct V_822 * V_823 ,
unsigned int type )
{
F_8 ( V_47 , V_824 ) ;
F_8 ( V_13 , V_825 ) ;
const struct V_826 * V_827 ;
T_2 V_729 , V_828 , V_17 ;
bool V_829 ;
int V_18 ;
for ( V_827 = V_830 ; ; V_827 ++ ) {
if ( V_827 ==
V_830 + F_182 ( V_830 ) )
return - V_37 ;
if ( ( type & ~ V_827 -> V_831 ) == V_827 -> type )
break;
}
if ( V_827 -> V_832 != F_341 ( V_2 ) )
return - V_37 ;
V_18 = F_342 ( V_2 , type , & V_729 , & V_828 , & V_829 ) ;
if ( V_18 )
return V_18 ;
if ( V_829 )
return - V_37 ;
V_823 -> V_833 = type ;
F_21 ( V_47 , V_834 , type ) ;
V_18 = F_9 ( V_2 , V_835 , V_47 , sizeof( V_47 ) ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_836 )
return - V_7 ;
if ( F_10 ( V_13 , V_837 ) &
( 1 << V_838 ) )
V_823 -> V_839 = F_10 ( V_13 ,
V_840 ) ;
V_823 -> V_841 . V_842 = L_77 ;
V_823 -> V_841 . V_843 = V_827 -> V_265 ;
V_823 -> V_841 . V_844 . type = V_845 ;
V_823 -> V_841 . V_844 . V_232 = V_846 ;
V_823 -> V_841 . V_844 . V_729 = V_729 ;
V_823 -> V_841 . V_844 . V_847 = V_828 ;
return 0 ;
}
static int F_343 ( struct V_1 * V_2 )
{
F_8 ( V_13 , V_848 ) ;
struct V_822 * V_849 ;
T_2 V_17 , V_850 , V_85 , V_851 ;
unsigned int type ;
int V_18 ;
F_344 () ;
F_13 ( V_852 != 0 ) ;
V_18 = F_9 ( V_2 , V_853 , NULL , 0 ,
V_13 , sizeof( V_13 ) , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < V_854 )
return - V_7 ;
V_850 = F_10 ( V_13 , V_855 ) ;
if ( V_850 >
F_289 ( V_17 , V_856 ) )
return - V_7 ;
V_849 = F_345 ( V_850 , sizeof( * V_849 ) , V_74 ) ;
if ( ! V_849 )
return - V_73 ;
V_851 = 0 ;
for ( V_85 = 0 ; V_85 < V_850 ; V_85 ++ ) {
type = F_290 ( V_13 , V_856 ,
V_85 ) ;
V_18 = F_340 ( V_2 , & V_849 [ V_851 ] , type ) ;
if ( V_18 == 0 )
V_851 ++ ;
else if ( V_18 != - V_37 )
goto V_152;
}
V_18 = F_346 ( V_2 , & V_849 [ 0 ] . V_841 , V_851 , sizeof( * V_849 ) ) ;
V_152:
if ( V_18 )
F_40 ( V_849 ) ;
return V_18 ;
}
static void F_347 ( struct V_1 * V_2 , T_6 V_857 )
{
F_50 ( V_2 , F_51 ( V_857 ) , V_356 ) ;
}
static void F_348 ( struct V_1 * V_2 ,
T_6 V_857 ) {}
static int F_349 ( struct V_140 * V_141 ,
bool V_858 )
{
F_8 ( V_47 , V_859 ) ;
int V_18 ;
if ( V_141 -> V_860 == V_861 ||
V_141 -> V_860 == V_862 ||
( V_858 && V_141 -> V_860 == V_863 ) )
return 0 ;
V_141 -> V_860 = V_861 ;
F_21 ( V_47 , V_864 , V_865 ) ;
F_21 ( V_47 , V_866 , 0 ) ;
F_21 ( V_47 , V_867 ,
V_141 -> V_141 ) ;
V_18 = F_9 ( V_141 -> V_2 , V_868 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
if ( V_18 != 0 )
V_141 -> V_860 = V_858 ? V_869 :
V_863 ;
return V_18 ;
}
static int F_350 ( struct V_140 * V_141 ,
bool V_858 )
{
F_8 ( V_47 , V_870 ) ;
int V_18 ;
if ( V_141 -> V_860 == V_863 ||
( V_858 && V_141 -> V_860 == V_869 ) )
return 0 ;
if ( V_141 -> V_860 == V_869 ) {
V_141 -> V_860 = V_863 ;
return 0 ;
}
V_141 -> V_860 = V_858 ? V_869 :
V_863 ;
F_21 ( V_47 , V_864 , V_871 ) ;
F_21 ( V_47 , V_866 , 0 ) ;
F_21 ( V_47 , V_872 ,
V_873 ) ;
F_21 ( V_47 , V_874 ,
V_141 -> V_141 ) ;
V_18 = F_9 ( V_141 -> V_2 , V_868 ,
V_47 , sizeof( V_47 ) , NULL , 0 , NULL ) ;
return V_18 ;
}
static int F_351 ( struct V_1 * V_2 , bool V_875 ,
bool V_858 )
{
int (* F_352)( struct V_140 * V_141 , bool V_858 );
struct V_140 * V_141 ;
F_352 = V_875 ?
F_349 :
F_350 ;
F_80 (channel, efx) {
int V_18 = F_352 ( V_141 , V_858 ) ;
if ( V_875 && V_18 != 0 ) {
F_351 ( V_2 , false , V_858 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_353 ( struct V_1 * V_2 ,
struct V_876 * V_877 )
{
return - V_347 ;
}
static int F_354 ( struct V_1 * V_2 ,
struct V_876 * V_877 )
{
int V_18 ;
switch ( V_877 -> V_878 ) {
case V_879 :
F_351 ( V_2 , false , false ) ;
return F_355 ( V_2 ,
V_877 -> V_880 != V_881 , 0 ) ;
case V_882 :
case V_883 :
case V_884 :
case V_885 :
case V_886 :
case V_887 :
case V_888 :
case V_889 :
case V_890 :
case V_891 :
case V_892 :
case V_893 :
case V_894 :
V_877 -> V_878 = V_882 ;
V_18 = F_355 ( V_2 , true , 0 ) ;
if ( ! V_18 )
V_18 = F_351 ( V_2 , true , false ) ;
if ( V_18 )
F_355 ( V_2 , false , 0 ) ;
return V_18 ;
default:
return - V_41 ;
}
}
static int F_356 ( struct V_1 * V_2 , T_18 V_895 , T_5 V_67 )
{
if ( V_895 != F_244 ( V_896 ) )
return - V_243 ;
return F_30 ( V_2 , V_67 ) ;
}
static int F_357 ( struct V_1 * V_2 , T_18 V_895 , T_5 V_67 )
{
if ( V_895 != F_244 ( V_896 ) )
return - V_243 ;
return F_43 ( V_2 , V_67 ) ;
}
