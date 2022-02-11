static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long V_4 ;
unsigned int V_5 ;
F_2 ( L_1 ) ;
V_4 = V_2 -> V_6 ;
V_5 = ( V_3 * ( V_4 / 1000000 ) ) / 256 ;
F_2 ( L_2 ) ;
return V_5 ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
unsigned long V_4 ;
unsigned int V_5 ;
F_2 ( L_3 ) ;
V_4 = V_2 -> V_6 ;
V_5 = ( V_7 * 256 ) / ( V_4 / 1000000 ) ;
F_2 ( L_4 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ )
F_5 ( V_9 , V_12 , V_13 ,
V_2 -> V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 -> V_9 , V_15 , V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_16 ,
V_2 -> V_18 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_7 ( V_2 -> V_9 , V_19 , V_16 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_16 ,
V_2 -> V_21 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_22 ,
V_2 -> V_23 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_24 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_27 , V_24 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_24 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_30 , V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_24 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_31 , V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_24 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_32 , V_24 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_33 , V_34 ,
V_2 -> V_35 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_36 ,
V_2 -> V_37 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_38 , 1 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_12 , V_39 , 1 ) ;
}
F_22 ( V_2 , V_40 , V_41 , V_42 ) ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int type ,
unsigned int V_43 , unsigned int V_24 )
{
unsigned int V_44 ;
int V_5 = 0 ;
F_24 ( & V_2 -> V_45 ) ;
if ( F_25 ( V_2 , V_46 , V_47 ) ) {
V_5 = - V_48 ;
goto V_49;
}
F_26 ( V_2 , V_50 , V_24 ) ;
F_22 ( V_2 , V_46 , V_51 , V_43 ) ;
F_22 ( V_2 , V_46 , V_52 , type ) ;
F_22 ( V_2 , V_46 , V_53 , 0 ) ;
F_22 ( V_2 , V_46 , V_47 , 1 ) ;
V_44 = 1000 ;
while ( V_44 -- ) {
if ( ! F_25 ( V_2 , V_46 , V_47 ) )
goto V_49;
F_27 ( 1000 , 1500 ) ;
}
V_5 = - V_48 ;
V_49:
F_28 ( & V_2 -> V_45 ) ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned int V_54 = sizeof( V_2 -> V_55 ) / sizeof( V_56 ) ;
unsigned int * V_57 = ( unsigned int * ) & V_2 -> V_55 ;
int V_5 ;
while ( V_54 -- ) {
V_5 = F_23 ( V_2 , V_58 ,
V_54 , * V_57 ++ ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
int V_5 ;
for ( V_10 = 0 ; V_10 < F_31 ( V_2 -> V_59 ) ; V_10 ++ ) {
V_5 = F_23 ( V_2 ,
V_60 , V_10 ,
V_2 -> V_59 [ V_10 ] ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , const T_1 * V_57 )
{
memcpy ( V_2 -> V_55 , V_57 , sizeof( V_2 -> V_55 ) ) ;
return F_29 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
const V_56 * V_61 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_31 ( V_2 -> V_59 ) ; V_10 ++ )
F_34 ( V_2 -> V_59 [ V_10 ] , V_50 , V_62 , V_61 [ V_10 ] ) ;
return F_30 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! V_2 -> V_63 . V_64 )
return - V_65 ;
V_5 = F_29 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_30 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_26 ( V_2 , V_66 , V_2 -> V_67 ) ;
F_22 ( V_2 , V_66 , V_68 , 1 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_63 . V_64 )
return - V_65 ;
F_22 ( V_2 , V_66 , V_68 , 0 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! V_2 -> V_63 . V_64 )
return;
if ( V_2 -> V_69 -> V_70 & V_71 )
V_5 = F_35 ( V_2 ) ;
else
V_5 = F_36 ( V_2 ) ;
if ( V_5 )
F_38 ( V_2 -> V_69 ,
L_5 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
unsigned int V_72 , V_73 ;
unsigned int V_74 , V_75 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_76 , 0 ) ;
V_72 = V_77 ;
V_73 = F_40 (unsigned int, pdata->tx_q_count, max_q_count) ;
V_74 = V_78 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
V_75 = F_41 ( V_2 , V_74 ) ;
F_34 ( V_75 , V_78 , V_79 , 0 ) ;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_80 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_82 ;
struct V_83 * V_84 = V_2 -> V_84 ;
unsigned int V_72 , V_73 ;
unsigned int V_74 , V_75 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
unsigned int V_85 = 0 ;
if ( V_82 && V_84 ) {
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
unsigned int V_88 ;
if ( V_2 -> V_89 [ V_86 ] != V_10 )
continue;
V_88 = V_84 -> V_90 [ V_86 ] ;
if ( V_82 -> V_91 & ( 1 << V_88 ) ) {
V_85 = 1 ;
break;
}
}
} else {
V_85 = 1 ;
}
F_13 ( V_2 , V_10 , V_26 , V_76 , V_85 ) ;
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_6 ,
V_85 ? L_7 : L_8 , V_10 ) ;
}
V_72 = V_77 ;
V_73 = F_40 (unsigned int, pdata->tx_q_count, max_q_count) ;
V_74 = V_78 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
V_75 = F_41 ( V_2 , V_74 ) ;
F_34 ( V_75 , V_78 , V_79 , 1 ) ;
F_34 ( V_75 , V_78 , V_93 , 0xffff ) ;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_80 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_94 , V_95 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_94 , V_95 , 1 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_82 ;
if ( V_2 -> V_96 || ( V_82 && V_82 -> V_91 ) )
F_42 ( V_2 ) ;
else
F_39 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_82 ;
if ( V_2 -> V_97 || ( V_82 && V_82 -> V_91 ) )
F_45 ( V_2 ) ;
else
F_44 ( V_2 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_82 ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_22 ( V_2 , V_94 , V_98 ,
( V_82 && V_82 -> V_91 ) ? 1 : 0 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_99 , V_100 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
V_99 = F_50 ( V_9 , V_101 ) ;
F_51 ( V_9 , V_101 , V_99 ) ;
V_100 = 0 ;
F_34 ( V_100 , V_102 , V_103 , 1 ) ;
F_34 ( V_100 , V_102 , V_104 , 1 ) ;
F_34 ( V_100 , V_102 , V_105 , 1 ) ;
if ( V_9 -> V_17 ) {
if ( ! V_2 -> V_106 )
F_34 ( V_100 , V_102 , V_107 , 1 ) ;
}
if ( V_9 -> V_20 ) {
F_34 ( V_100 , V_102 , V_108 , 1 ) ;
if ( ! V_2 -> V_106 )
F_34 ( V_100 , V_102 , V_109 , 1 ) ;
}
F_51 ( V_9 , V_102 , V_100 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned int V_110 ;
unsigned int V_73 , V_10 ;
V_73 = F_53 ( V_2 -> V_63 . V_111 , V_2 -> V_63 . V_112 ) ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
V_110 = F_54 ( V_2 , V_10 , V_113 ) ;
F_55 ( V_2 , V_10 , V_113 , V_110 ) ;
F_55 ( V_2 , V_10 , V_114 , 0 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned int V_115 = 0 ;
F_34 ( V_115 , V_116 , V_117 , 1 ) ;
F_26 ( V_2 , V_116 , V_115 ) ;
F_22 ( V_2 , V_118 , V_119 , 0xffffffff ) ;
F_22 ( V_2 , V_120 , V_119 , 0xffffffff ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , V_121 , V_122 ) == 0x3 )
return 0 ;
F_22 ( V_2 , V_121 , V_122 , 0x3 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , V_121 , V_122 ) == 0x2 )
return 0 ;
F_22 ( V_2 , V_121 , V_122 , 0x2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , V_121 , V_122 ) == 0 )
return 0 ;
F_22 ( V_2 , V_121 , V_122 , 0 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_123 , V_124 , 1 ) ;
F_22 ( V_2 , V_123 , V_125 , 1 ) ;
F_22 ( V_2 , V_123 , V_126 , 0 ) ;
F_22 ( V_2 , V_123 , V_127 , 0 ) ;
F_22 ( V_2 , V_123 , V_128 , 0x3 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_123 , V_128 , 0 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_129 , V_130 , 1 ) ;
F_22 ( V_2 , V_123 , V_131 , 1 ) ;
F_22 ( V_2 , V_123 , V_132 , 0 ) ;
F_22 ( V_2 , V_123 , V_133 , 1 ) ;
F_22 ( V_2 , V_123 , V_134 , 1 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_129 , V_130 , 0 ) ;
return 0 ;
}
static V_56 F_64 ( T_2 V_135 )
{
V_56 V_136 = 0xedb88320 ;
V_56 V_137 = ~ 0 ;
V_56 V_138 = 0 ;
unsigned char * V_139 = ( unsigned char * ) & V_135 ;
unsigned char V_140 = 0 ;
int V_10 , V_141 ;
V_141 = F_65 ( V_142 ) ;
for ( V_10 = 0 ; V_10 < V_141 ; V_10 ++ ) {
if ( ( V_10 % 8 ) == 0 )
V_140 = V_139 [ V_10 / 8 ] ;
V_138 = ( ( V_137 & 1 ) ^ V_140 ) & 1 ;
V_137 >>= 1 ;
V_140 >>= 1 ;
if ( V_138 )
V_137 ^= V_136 ;
}
return V_137 ;
}
static int F_66 ( struct V_1 * V_2 )
{
V_56 V_137 ;
T_3 V_143 ;
T_2 V_135 ;
T_3 V_144 = 0 ;
F_67 (vid, pdata->active_vlans, VLAN_N_VID) {
V_135 = F_68 ( V_143 ) ;
V_137 = F_69 ( ~ F_64 ( V_135 ) ) >> 28 ;
V_144 |= ( 1 << V_137 ) ;
}
F_22 ( V_2 , V_145 , V_146 , V_144 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
unsigned int V_147 )
{
unsigned int V_24 = V_147 ? 1 : 0 ;
if ( F_25 ( V_2 , V_129 , V_148 ) == V_24 )
return 0 ;
F_43 ( V_2 , V_92 , V_2 -> V_69 , L_9 ,
V_147 ? L_10 : L_11 ) ;
F_22 ( V_2 , V_129 , V_148 , V_24 ) ;
if ( V_147 ) {
F_63 ( V_2 ) ;
} else {
if ( V_2 -> V_69 -> V_70 & V_149 )
F_62 ( V_2 ) ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned int V_147 )
{
unsigned int V_24 = V_147 ? 1 : 0 ;
if ( F_25 ( V_2 , V_129 , V_150 ) == V_24 )
return 0 ;
F_43 ( V_2 , V_92 , V_2 -> V_69 , L_12 ,
V_147 ? L_10 : L_11 ) ;
F_22 ( V_2 , V_129 , V_150 , V_24 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_151 * V_152 , unsigned int * V_153 )
{
unsigned int V_154 , V_155 ;
T_1 * V_156 ;
V_155 = 0 ;
V_154 = 0 ;
if ( V_152 ) {
V_156 = ( T_1 * ) & V_155 ;
V_156 [ 0 ] = V_152 -> V_157 [ 0 ] ;
V_156 [ 1 ] = V_152 -> V_157 [ 1 ] ;
V_156 [ 2 ] = V_152 -> V_157 [ 2 ] ;
V_156 [ 3 ] = V_152 -> V_157 [ 3 ] ;
V_156 = ( T_1 * ) & V_154 ;
V_156 [ 0 ] = V_152 -> V_157 [ 4 ] ;
V_156 [ 1 ] = V_152 -> V_157 [ 5 ] ;
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_13 ,
V_152 -> V_157 , * V_153 ) ;
F_34 ( V_154 , V_158 , V_159 , 1 ) ;
}
F_26 ( V_2 , * V_153 , V_154 ) ;
* V_153 += V_160 ;
F_26 ( V_2 , * V_153 , V_155 ) ;
* V_153 += V_160 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_161 * V_69 = V_2 -> V_69 ;
struct V_151 * V_152 ;
unsigned int V_153 ;
unsigned int V_162 ;
V_153 = V_158 ;
V_162 = V_2 -> V_63 . V_163 ;
if ( F_74 ( V_69 ) > V_162 ) {
F_70 ( V_2 , 1 ) ;
} else {
F_75 (ha, netdev) {
F_72 ( V_2 , V_152 , & V_153 ) ;
V_162 -- ;
}
if ( F_76 ( V_69 ) > V_162 ) {
F_71 ( V_2 , 1 ) ;
} else {
F_77 (ha, netdev) {
F_72 ( V_2 , V_152 , & V_153 ) ;
V_162 -- ;
}
}
}
while ( V_162 -- )
F_72 ( V_2 , NULL , & V_153 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_161 * V_69 = V_2 -> V_69 ;
struct V_151 * V_152 ;
unsigned int V_164 ;
unsigned int V_165 , V_166 ;
V_56 V_167 [ V_168 ] ;
V_56 V_137 ;
unsigned int V_10 ;
V_165 = 26 - ( V_2 -> V_63 . V_169 >> 7 ) ;
V_166 = V_2 -> V_63 . V_169 / 32 ;
memset ( V_167 , 0 , sizeof( V_167 ) ) ;
F_75 (ha, netdev) {
V_137 = F_69 ( ~ F_79 ( ~ 0 , V_152 -> V_157 , V_170 ) ) ;
V_137 >>= V_165 ;
V_167 [ V_137 >> 5 ] |= ( 1 << ( V_137 & 0x1f ) ) ;
}
F_77 (ha, netdev) {
V_137 = F_69 ( ~ F_79 ( ~ 0 , V_152 -> V_157 , V_170 ) ) ;
V_137 >>= V_165 ;
V_167 [ V_137 >> 5 ] |= ( 1 << ( V_137 & 0x1f ) ) ;
}
V_164 = V_171 ;
for ( V_10 = 0 ; V_10 < V_166 ; V_10 ++ ) {
F_26 ( V_2 , V_164 , V_167 [ V_10 ] ) ;
V_164 += V_172 ;
}
}
static int F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 . V_169 )
F_78 ( V_2 ) ;
else
F_73 ( V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 * V_157 )
{
unsigned int V_154 , V_155 ;
V_154 = ( V_157 [ 5 ] << 8 ) | ( V_157 [ 4 ] << 0 ) ;
V_155 = ( V_157 [ 3 ] << 24 ) | ( V_157 [ 2 ] << 16 ) |
( V_157 [ 1 ] << 8 ) | ( V_157 [ 0 ] << 0 ) ;
F_26 ( V_2 , V_173 , V_154 ) ;
F_26 ( V_2 , V_174 , V_155 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_161 * V_69 = V_2 -> V_69 ;
unsigned int V_175 , V_176 ;
V_175 = ( ( V_69 -> V_177 & V_178 ) != 0 ) ;
V_176 = ( ( V_69 -> V_177 & V_179 ) != 0 ) ;
F_70 ( V_2 , V_175 ) ;
F_71 ( V_2 , V_176 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , int V_180 ,
int V_181 )
{
unsigned long V_177 ;
unsigned int V_182 ;
int V_183 ;
if ( V_181 & V_184 )
V_182 = V_181 & ~ V_184 ;
else
V_182 = ( V_2 -> V_185 << 16 ) | ( V_181 & 0xffff ) ;
F_84 ( & V_2 -> V_186 , V_177 ) ;
F_85 ( V_2 , V_187 << 2 , V_182 >> 8 ) ;
V_183 = F_86 ( V_2 , ( V_182 & 0xff ) << 2 ) ;
F_87 ( & V_2 -> V_186 , V_177 ) ;
return V_183 ;
}
static void F_88 ( struct V_1 * V_2 , int V_180 ,
int V_181 , int V_183 )
{
unsigned int V_182 ;
unsigned long V_177 ;
if ( V_181 & V_184 )
V_182 = V_181 & ~ V_184 ;
else
V_182 = ( V_2 -> V_185 << 16 ) | ( V_181 & 0xffff ) ;
F_84 ( & V_2 -> V_186 , V_177 ) ;
F_85 ( V_2 , V_187 << 2 , V_182 >> 8 ) ;
F_85 ( V_2 , ( V_182 & 0xff ) << 2 , V_183 ) ;
F_87 ( & V_2 -> V_186 , V_177 ) ;
}
static int F_89 ( struct V_188 * V_189 )
{
return ! F_90 ( V_189 -> V_190 , V_191 , V_192 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_193 , 0 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_193 , 1 ) ;
return 0 ;
}
static void F_93 ( struct V_194 * V_195 )
{
struct V_188 * V_189 = V_195 -> V_189 ;
V_189 -> V_196 = 0 ;
V_189 -> V_197 = 0 ;
V_189 -> V_198 = 0 ;
V_189 -> V_190 = 0 ;
F_94 () ;
}
static void F_95 ( struct V_8 * V_9 )
{
struct V_199 * V_200 = V_9 -> V_17 ;
struct V_194 * V_195 ;
int V_10 ;
int V_201 = V_200 -> V_202 ;
F_2 ( L_14 ) ;
for ( V_10 = 0 ; V_10 < V_200 -> V_203 ; V_10 ++ ) {
V_195 = F_96 ( V_200 , V_10 ) ;
F_93 ( V_195 ) ;
}
F_51 ( V_9 , V_204 , V_200 -> V_203 - 1 ) ;
V_195 = F_96 ( V_200 , V_201 ) ;
F_51 ( V_9 , V_205 ,
F_97 ( V_195 -> V_206 ) ) ;
F_51 ( V_9 , V_207 ,
F_98 ( V_195 -> V_206 ) ) ;
F_2 ( L_15 ) ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_194 * V_195 , unsigned int V_43 )
{
struct V_188 * V_189 = V_195 -> V_189 ;
unsigned int V_208 = V_2 -> V_208 ;
unsigned int V_209 = V_2 -> V_209 ;
unsigned int V_210 ;
T_4 V_211 , V_212 ;
if ( ! V_208 && ! V_209 ) {
V_210 = 1 ;
} else {
if ( V_209 && ! ( ( V_43 + 1 ) % V_209 ) )
V_210 = 1 ;
else
V_210 = 0 ;
}
V_211 = V_195 -> V_213 . V_214 . V_215 + V_195 -> V_213 . V_214 . V_216 ;
V_212 = V_195 -> V_213 . V_217 . V_215 + V_195 -> V_213 . V_217 . V_216 ;
V_189 -> V_196 = F_100 ( F_98 ( V_211 ) ) ;
V_189 -> V_197 = F_100 ( F_97 ( V_211 ) ) ;
V_189 -> V_198 = F_100 ( F_98 ( V_212 ) ) ;
V_189 -> V_190 = F_100 ( F_97 ( V_212 ) ) ;
F_101 ( V_189 -> V_190 , V_218 , V_219 , V_210 ) ;
F_94 () ;
F_101 ( V_189 -> V_190 , V_218 , V_192 , 1 ) ;
F_94 () ;
}
static void F_102 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_199 * V_200 = V_9 -> V_20 ;
struct V_194 * V_195 ;
unsigned int V_201 = V_200 -> V_202 ;
unsigned int V_10 ;
F_2 ( L_16 ) ;
for ( V_10 = 0 ; V_10 < V_200 -> V_203 ; V_10 ++ ) {
V_195 = F_96 ( V_200 , V_10 ) ;
F_99 ( V_2 , V_195 , V_10 ) ;
}
F_51 ( V_9 , V_220 , V_200 -> V_203 - 1 ) ;
V_195 = F_96 ( V_200 , V_201 ) ;
F_51 ( V_9 , V_221 ,
F_97 ( V_195 -> V_206 ) ) ;
F_51 ( V_9 , V_222 ,
F_98 ( V_195 -> V_206 ) ) ;
V_195 = F_96 ( V_200 , V_201 + V_200 -> V_203 - 1 ) ;
F_51 ( V_9 , V_223 ,
F_98 ( V_195 -> V_206 ) ) ;
F_2 ( L_17 ) ;
}
static void F_103 ( struct V_1 * V_2 ,
unsigned int V_224 )
{
F_26 ( V_2 , V_225 , V_224 ) ;
F_22 ( V_2 , V_226 , V_227 , 1 ) ;
while ( F_25 ( V_2 , V_226 , V_227 ) )
F_104 ( 5 ) ;
}
static void F_105 ( struct V_1 * V_2 , unsigned int V_228 ,
unsigned int V_229 )
{
F_26 ( V_2 , V_230 , V_228 ) ;
F_26 ( V_2 , V_231 , V_229 ) ;
F_22 ( V_2 , V_226 , V_232 , 1 ) ;
while ( F_25 ( V_2 , V_226 , V_232 ) )
F_104 ( 5 ) ;
}
static T_5 F_106 ( struct V_1 * V_2 )
{
T_5 V_229 ;
V_229 = F_41 ( V_2 , V_233 ) ;
V_229 *= V_234 ;
V_229 += F_41 ( V_2 , V_235 ) ;
return V_229 ;
}
static T_5 F_107 ( struct V_1 * V_2 )
{
unsigned int V_236 ;
T_5 V_229 ;
V_236 = F_41 ( V_2 , V_237 ) ;
if ( F_108 ( V_236 , V_237 , V_238 ) )
return 0 ;
V_229 = F_41 ( V_2 , V_239 ) ;
V_229 *= V_234 ;
V_229 += V_236 ;
return V_229 ;
}
static void F_109 ( struct V_240 * V_241 ,
struct V_188 * V_189 )
{
T_5 V_229 ;
if ( F_90 ( V_189 -> V_190 , V_242 , V_243 ) &&
! F_90 ( V_189 -> V_190 , V_242 , V_244 ) ) {
V_229 = F_110 ( V_189 -> V_197 ) ;
V_229 <<= 32 ;
V_229 |= F_110 ( V_189 -> V_196 ) ;
if ( V_229 != 0xffffffffffffffffULL ) {
V_241 -> V_245 = V_229 ;
F_34 ( V_241 -> V_246 , V_247 ,
V_248 , 1 ) ;
}
}
}
static int F_111 ( struct V_1 * V_2 ,
unsigned int V_249 )
{
F_34 ( V_249 , V_226 , V_250 , 1 ) ;
F_34 ( V_249 , V_226 , V_251 , 1 ) ;
F_34 ( V_249 , V_226 , V_252 , 1 ) ;
F_26 ( V_2 , V_226 , V_249 ) ;
if ( ! F_108 ( V_249 , V_226 , V_253 ) )
return 0 ;
F_22 ( V_2 , V_254 , V_255 , V_256 ) ;
F_22 ( V_2 , V_254 , V_257 , V_258 ) ;
F_103 ( V_2 , V_2 -> V_259 ) ;
F_105 ( V_2 , 0 , 0 ) ;
F_112 ( & V_2 -> V_260 , & V_2 -> V_261 ,
F_113 ( F_114 () ) ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 )
{
unsigned int V_262 , V_263 , V_86 ;
T_1 V_10 ;
F_116 ( V_2 -> V_69 ) ;
if ( ! V_2 -> V_264 )
return;
F_117 ( V_2 -> V_69 , V_2 -> V_264 ) ;
for ( V_10 = 0 , V_263 = 0 , V_262 = 0 ; V_10 < V_2 -> V_264 ; V_10 ++ ) {
while ( ( V_263 < V_2 -> V_28 ) &&
( V_2 -> V_265 [ V_263 ] == V_10 ) )
V_263 ++ ;
F_43 ( V_2 , V_92 , V_2 -> V_69 , L_18 ,
V_10 , V_262 , V_263 - 1 ) ;
F_118 ( V_2 -> V_69 , V_10 , V_263 - V_262 , V_262 ) ;
V_262 = V_263 ;
}
if ( ! V_2 -> V_84 )
return;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
F_119 ( V_2 -> V_69 , V_86 ,
V_2 -> V_84 -> V_90 [ V_86 ] ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
unsigned int V_266 , V_267 , V_268 ;
unsigned int V_269 , V_74 , V_75 ;
unsigned int V_10 , V_86 ;
if ( ! V_84 )
return;
F_22 ( V_2 , V_270 , V_271 , V_272 ) ;
V_266 = V_2 -> V_69 -> V_273 * V_2 -> V_63 . V_274 ;
V_267 = V_266 / 100 ;
if ( ! V_267 )
V_267 = 1 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_274 ; V_10 ++ ) {
V_269 = 0 ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
if ( V_84 -> V_90 [ V_86 ] == V_10 )
V_269 |= ( 1 << V_86 ) ;
}
V_269 &= 0xff ;
F_43 ( V_2 , V_92 , V_2 -> V_69 , L_19 ,
V_10 , V_269 ) ;
V_74 = V_275 + ( V_276 * ( V_10 / V_277 ) ) ;
V_75 = F_41 ( V_2 , V_74 ) ;
V_75 &= ~ ( 0xff << ( ( V_10 % V_277 ) << 3 ) ) ;
V_75 |= ( V_269 << ( ( V_10 % V_277 ) << 3 ) ) ;
F_26 ( V_2 , V_74 , V_75 ) ;
switch ( V_84 -> V_278 [ V_10 ] ) {
case V_279 :
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_20 , V_10 ) ;
F_13 ( V_2 , V_10 , V_280 , V_243 ,
V_281 ) ;
break;
case V_282 :
V_268 = V_266 * V_84 -> V_283 [ V_10 ] / 100 ;
V_268 = F_121 ( V_268 , V_267 , V_266 ) ;
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_21 , V_10 , V_268 ) ;
F_13 ( V_2 , V_10 , V_280 , V_243 ,
V_284 ) ;
F_13 ( V_2 , V_10 , V_285 , V_286 ,
V_268 ) ;
break;
}
}
F_115 ( V_2 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_48 ( V_2 ) ;
}
static void F_123 ( struct V_8 * V_9 ,
struct V_199 * V_200 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_194 * V_195 ;
F_124 () ;
V_195 = F_96 ( V_200 , V_200 -> V_202 ) ;
F_51 ( V_9 , V_287 ,
F_98 ( V_195 -> V_206 ) ) ;
if ( V_2 -> V_288 && ! V_9 -> V_289 ) {
V_9 -> V_289 = 1 ;
F_125 ( & V_9 -> V_290 ,
V_291 + F_126 ( V_2 -> V_288 ) ) ;
}
V_200 -> V_292 . V_293 = 0 ;
}
static void F_127 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_199 * V_200 = V_9 -> V_17 ;
struct V_194 * V_195 ;
struct V_188 * V_189 ;
struct V_240 * V_241 = & V_200 -> V_294 ;
unsigned int V_295 , V_296 , V_297 ;
unsigned int V_298 , V_299 ;
unsigned int V_300 ;
int V_201 = V_200 -> V_202 ;
int V_301 = V_200 -> V_202 ;
int V_10 ;
F_2 ( L_22 ) ;
V_295 = F_108 ( V_241 -> V_246 , V_302 ,
V_303 ) ;
V_296 = F_108 ( V_241 -> V_246 , V_302 ,
V_304 ) ;
V_297 = F_108 ( V_241 -> V_246 , V_302 ,
V_305 ) ;
if ( V_296 && ( V_241 -> V_306 != V_200 -> V_292 . V_307 ) )
V_298 = 1 ;
else
V_298 = 0 ;
if ( V_297 && ( V_241 -> V_308 != V_200 -> V_292 . V_309 ) )
V_299 = 1 ;
else
V_299 = 0 ;
V_200 -> V_310 += V_241 -> V_311 ;
if ( ! V_2 -> V_312 )
V_300 = 0 ;
else if ( V_241 -> V_311 > V_2 -> V_312 )
V_300 = 1 ;
else if ( ( V_200 -> V_310 % V_2 -> V_312 ) <
V_241 -> V_311 )
V_300 = 1 ;
else
V_300 = 0 ;
V_195 = F_96 ( V_200 , V_301 ) ;
V_189 = V_195 -> V_189 ;
if ( V_298 || V_299 ) {
if ( V_298 ) {
F_43 ( V_2 , V_313 , V_2 -> V_69 ,
L_23 ,
V_241 -> V_306 ) ;
F_101 ( V_189 -> V_198 , V_314 ,
V_315 , V_241 -> V_306 ) ;
F_101 ( V_189 -> V_190 , V_316 ,
V_317 , 1 ) ;
F_101 ( V_189 -> V_190 , V_316 ,
V_318 , 1 ) ;
V_200 -> V_292 . V_307 = V_241 -> V_306 ;
}
if ( V_299 ) {
F_43 ( V_2 , V_313 , V_2 -> V_69 ,
L_24 ,
V_241 -> V_308 ) ;
F_101 ( V_189 -> V_190 , V_316 ,
V_317 , 1 ) ;
F_101 ( V_189 -> V_190 , V_316 ,
V_319 , V_241 -> V_308 ) ;
F_101 ( V_189 -> V_190 , V_316 ,
V_320 , 1 ) ;
V_200 -> V_292 . V_309 = V_241 -> V_308 ;
}
V_301 ++ ;
V_195 = F_96 ( V_200 , V_301 ) ;
V_189 = V_195 -> V_189 ;
}
V_189 -> V_196 = F_100 ( F_98 ( V_195 -> V_321 ) ) ;
V_189 -> V_197 = F_100 ( F_97 ( V_195 -> V_321 ) ) ;
F_101 ( V_189 -> V_198 , V_322 , V_323 ,
V_195 -> V_324 ) ;
if ( V_297 )
F_101 ( V_189 -> V_198 , V_322 , V_325 ,
V_326 ) ;
if ( F_108 ( V_241 -> V_246 , V_302 , V_327 ) )
F_101 ( V_189 -> V_198 , V_322 , V_328 , 1 ) ;
F_101 ( V_189 -> V_190 , V_191 , V_329 , 1 ) ;
F_101 ( V_189 -> V_190 , V_191 , V_317 , 0 ) ;
if ( V_301 != V_201 )
F_101 ( V_189 -> V_190 , V_191 , V_192 , 1 ) ;
if ( V_296 ) {
F_101 ( V_189 -> V_190 , V_191 , V_38 , 1 ) ;
F_101 ( V_189 -> V_190 , V_191 , V_330 ,
V_241 -> V_331 ) ;
F_101 ( V_189 -> V_190 , V_191 , V_332 ,
V_241 -> V_333 / 4 ) ;
V_2 -> V_334 . V_335 ++ ;
} else {
F_101 ( V_189 -> V_190 , V_191 , V_336 , 0 ) ;
if ( V_295 )
F_101 ( V_189 -> V_190 , V_191 ,
V_337 , 0x3 ) ;
F_101 ( V_189 -> V_190 , V_191 , V_338 ,
V_241 -> V_339 ) ;
}
for ( V_10 = V_301 - V_201 + 1 ; V_10 < V_241 -> V_203 ; V_10 ++ ) {
V_301 ++ ;
V_195 = F_96 ( V_200 , V_301 ) ;
V_189 = V_195 -> V_189 ;
V_189 -> V_196 = F_100 ( F_98 ( V_195 -> V_321 ) ) ;
V_189 -> V_197 = F_100 ( F_97 ( V_195 -> V_321 ) ) ;
F_101 ( V_189 -> V_198 , V_322 , V_323 ,
V_195 -> V_324 ) ;
F_101 ( V_189 -> V_190 , V_191 , V_192 , 1 ) ;
F_101 ( V_189 -> V_190 , V_191 , V_317 , 0 ) ;
if ( V_295 )
F_101 ( V_189 -> V_190 , V_191 ,
V_337 , 0x3 ) ;
}
F_101 ( V_189 -> V_190 , V_191 , V_340 , 1 ) ;
if ( V_300 )
F_101 ( V_189 -> V_198 , V_322 , V_341 , 1 ) ;
V_195 -> V_292 . V_342 = V_241 -> V_311 ;
V_195 -> V_292 . V_343 = V_241 -> V_344 ;
F_94 () ;
V_195 = F_96 ( V_200 , V_201 ) ;
V_189 = V_195 -> V_189 ;
F_101 ( V_189 -> V_190 , V_191 , V_192 , 1 ) ;
if ( F_128 ( V_2 ) )
F_129 ( V_2 , V_200 , V_201 ,
V_241 -> V_203 , 1 ) ;
F_130 () ;
V_200 -> V_202 = V_301 + 1 ;
if ( ! V_241 -> V_345 -> V_293 ||
F_131 ( F_132 ( V_2 -> V_69 ,
V_9 -> V_346 ) ) )
F_123 ( V_9 , V_200 ) ;
else
V_200 -> V_292 . V_293 = 1 ;
F_2 ( L_25 ,
V_9 -> V_347 , V_201 & ( V_200 -> V_203 - 1 ) ,
( V_200 -> V_202 - 1 ) & ( V_200 -> V_203 - 1 ) ) ;
F_2 ( L_26 ) ;
}
static int F_133 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_199 * V_200 = V_9 -> V_20 ;
struct V_194 * V_195 ;
struct V_188 * V_189 ;
struct V_240 * V_241 = & V_200 -> V_294 ;
struct V_161 * V_69 = V_2 -> V_69 ;
unsigned int V_348 , V_349 , V_350 ;
F_2 ( L_27 , V_200 -> V_202 ) ;
V_195 = F_96 ( V_200 , V_200 -> V_202 ) ;
V_189 = V_195 -> V_189 ;
if ( F_90 ( V_189 -> V_190 , V_218 , V_192 ) )
return 1 ;
F_134 () ;
if ( F_135 ( V_2 ) )
F_136 ( V_2 , V_200 , V_200 -> V_202 ) ;
if ( F_90 ( V_189 -> V_190 , V_218 , V_317 ) ) {
F_109 ( V_241 , V_189 ) ;
F_34 ( V_241 -> V_246 , V_247 ,
V_351 , 1 ) ;
F_34 ( V_241 -> V_246 , V_247 ,
V_352 , 0 ) ;
return 0 ;
}
F_34 ( V_241 -> V_246 , V_247 , V_351 , 0 ) ;
if ( F_90 ( V_189 -> V_190 , V_218 , V_353 ) )
F_34 ( V_241 -> V_246 , V_247 ,
V_352 , 1 ) ;
if ( F_90 ( V_189 -> V_190 , V_218 , V_329 ) ) {
V_195 -> V_213 . V_354 = F_90 ( V_189 -> V_198 ,
V_355 , V_356 ) ;
if ( V_195 -> V_213 . V_354 )
V_2 -> V_334 . V_357 ++ ;
}
if ( F_90 ( V_189 -> V_190 , V_218 , V_358 ) ) {
F_34 ( V_241 -> V_246 , V_247 ,
V_359 , 1 ) ;
V_241 -> V_360 = F_110 ( V_189 -> V_197 ) ;
V_350 = F_90 ( V_189 -> V_190 , V_218 , V_361 ) ;
switch ( V_350 ) {
case V_362 :
case V_363 :
case V_364 :
case V_365 :
V_241 -> V_366 = V_367 ;
break;
default:
V_241 -> V_366 = V_368 ;
}
}
V_195 -> V_213 . V_369 = F_90 ( V_189 -> V_190 , V_218 , V_370 ) ;
if ( ! F_90 ( V_189 -> V_190 , V_218 , V_340 ) ) {
F_34 ( V_241 -> V_246 , V_247 ,
V_371 , 1 ) ;
return 0 ;
}
F_34 ( V_241 -> V_246 , V_247 ,
V_371 , 0 ) ;
if ( V_69 -> V_70 & V_372 )
F_34 ( V_241 -> V_246 , V_247 ,
V_373 , 1 ) ;
V_348 = F_90 ( V_189 -> V_190 , V_218 , V_374 ) ;
V_349 = F_90 ( V_189 -> V_190 , V_218 , V_375 ) ;
F_43 ( V_2 , V_376 , V_69 , L_28 , V_348 , V_349 ) ;
if ( ! V_348 || ! V_349 ) {
if ( ( V_349 == 0x09 ) &&
( V_69 -> V_70 & V_377 ) ) {
F_34 ( V_241 -> V_246 , V_247 ,
V_305 , 1 ) ;
V_241 -> V_308 = F_90 ( V_189 -> V_196 ,
V_378 ,
V_379 ) ;
F_43 ( V_2 , V_376 , V_69 , L_29 ,
V_241 -> V_308 ) ;
}
} else {
if ( ( V_349 == 0x05 ) || ( V_349 == 0x06 ) )
F_34 ( V_241 -> V_246 , V_247 ,
V_373 , 0 ) ;
else
F_34 ( V_241 -> V_380 , V_381 ,
V_382 , 1 ) ;
}
F_2 ( L_30 , V_9 -> V_347 ,
V_200 -> V_202 & ( V_200 -> V_203 - 1 ) , V_200 -> V_202 ) ;
return 0 ;
}
static int F_137 ( struct V_188 * V_189 )
{
return F_90 ( V_189 -> V_190 , V_191 , V_317 ) ;
}
static int F_138 ( struct V_188 * V_189 )
{
return F_90 ( V_189 -> V_190 , V_191 , V_340 ) ;
}
static int F_139 ( struct V_8 * V_9 ,
enum V_383 V_384 )
{
unsigned int V_100 ;
V_100 = F_50 ( V_9 , V_102 ) ;
switch ( V_384 ) {
case V_385 :
F_34 ( V_100 , V_102 , V_107 , 1 ) ;
break;
case V_386 :
F_34 ( V_100 , V_102 , V_387 , 1 ) ;
break;
case V_388 :
F_34 ( V_100 , V_102 , V_389 , 1 ) ;
break;
case V_390 :
F_34 ( V_100 , V_102 , V_109 , 1 ) ;
break;
case V_391 :
F_34 ( V_100 , V_102 , V_108 , 1 ) ;
break;
case V_392 :
F_34 ( V_100 , V_102 , V_393 , 1 ) ;
break;
case V_394 :
F_34 ( V_100 , V_102 , V_107 , 1 ) ;
F_34 ( V_100 , V_102 , V_109 , 1 ) ;
break;
case V_395 :
F_34 ( V_100 , V_102 , V_105 , 1 ) ;
break;
case V_396 :
V_100 |= V_9 -> V_397 ;
break;
default:
return - 1 ;
}
F_51 ( V_9 , V_102 , V_100 ) ;
return 0 ;
}
static int F_140 ( struct V_8 * V_9 ,
enum V_383 V_384 )
{
unsigned int V_100 ;
V_100 = F_50 ( V_9 , V_102 ) ;
switch ( V_384 ) {
case V_385 :
F_34 ( V_100 , V_102 , V_107 , 0 ) ;
break;
case V_386 :
F_34 ( V_100 , V_102 , V_387 , 0 ) ;
break;
case V_388 :
F_34 ( V_100 , V_102 , V_389 , 0 ) ;
break;
case V_390 :
F_34 ( V_100 , V_102 , V_109 , 0 ) ;
break;
case V_391 :
F_34 ( V_100 , V_102 , V_108 , 0 ) ;
break;
case V_392 :
F_34 ( V_100 , V_102 , V_393 , 0 ) ;
break;
case V_394 :
F_34 ( V_100 , V_102 , V_107 , 0 ) ;
F_34 ( V_100 , V_102 , V_109 , 0 ) ;
break;
case V_395 :
F_34 ( V_100 , V_102 , V_105 , 0 ) ;
break;
case V_396 :
V_9 -> V_397 = V_100 & V_398 ;
V_100 &= ~ V_398 ;
break;
default:
return - 1 ;
}
F_51 ( V_9 , V_102 , V_100 ) ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
unsigned int V_399 = 2000 ;
F_2 ( L_31 ) ;
F_22 ( V_2 , V_400 , V_401 , 1 ) ;
F_27 ( 10 , 15 ) ;
while ( -- V_399 && F_25 ( V_2 , V_400 , V_401 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_399 )
return - V_48 ;
F_2 ( L_32 ) ;
return 0 ;
}
static int F_142 ( struct V_1 * V_2 )
{
unsigned int V_10 , V_399 ;
if ( F_108 ( V_2 -> V_63 . V_402 , V_403 , V_404 ) < 0x21 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_405 , 1 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ ) {
V_399 = 2000 ;
while ( -- V_399 && F_143 ( V_2 , V_10 ,
V_29 , V_405 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_399 )
return - V_48 ;
}
return 0 ;
}
static void F_144 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_406 , V_407 , 1 ) ;
F_22 ( V_2 , V_406 , UNDEF , 1 ) ;
F_22 ( V_2 , V_406 , V_408 , 1 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
unsigned int V_409 , V_410 ;
V_409 = 0 ;
F_34 ( V_409 , V_411 , V_412 , V_2 -> V_409 ) ;
F_34 ( V_409 , V_411 , V_413 , V_2 -> V_414 ) ;
F_34 ( V_409 , V_411 , V_415 , V_2 -> V_409 ) ;
F_34 ( V_409 , V_411 , V_416 , V_2 -> V_414 ) ;
F_34 ( V_409 , V_411 , V_417 , V_2 -> V_409 ) ;
F_34 ( V_409 , V_411 , V_418 , V_2 -> V_414 ) ;
F_26 ( V_2 , V_411 , V_409 ) ;
V_410 = 0 ;
F_34 ( V_410 , V_419 , V_420 , V_2 -> V_410 ) ;
F_34 ( V_410 , V_419 , V_421 , V_2 -> V_414 ) ;
F_34 ( V_410 , V_419 , V_422 , V_2 -> V_410 ) ;
F_34 ( V_410 , V_419 , V_423 , V_2 -> V_414 ) ;
F_34 ( V_410 , V_419 , V_424 , V_2 -> V_410 ) ;
F_34 ( V_410 , V_419 , V_425 , V_2 -> V_414 ) ;
F_34 ( V_410 , V_419 , V_426 , V_2 -> V_410 ) ;
F_34 ( V_410 , V_419 , V_427 , V_2 -> V_414 ) ;
F_26 ( V_2 , V_419 , V_410 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
F_22 ( V_2 , V_270 , V_271 , V_428 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_274 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_280 , V_243 ,
V_284 ) ;
F_13 ( V_2 , V_10 , V_285 , V_286 , 1 ) ;
}
F_22 ( V_2 , V_270 , V_429 , V_430 ) ;
}
static unsigned int F_147 ( unsigned int V_431 ,
unsigned int V_432 )
{
unsigned int V_433 ;
unsigned int V_434 ;
V_433 = 1 << ( V_431 + 7 ) ;
V_433 = F_40 (unsigned int, XGBE_FIFO_MAX, q_fifo_size) ;
V_433 = V_433 / V_432 ;
V_434 = V_433 / 256 ;
if ( V_434 )
V_434 -- ;
return V_434 ;
}
static void F_148 ( struct V_1 * V_2 )
{
unsigned int V_431 ;
unsigned int V_10 ;
V_431 = F_147 ( V_2 -> V_63 . V_435 ,
V_2 -> V_28 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_436 , V_431 ) ;
F_149 ( V_2 , V_92 , V_2 -> V_69 ,
L_33 ,
V_2 -> V_28 , ( ( V_431 + 1 ) * 256 ) ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
unsigned int V_431 ;
unsigned int V_10 ;
V_431 = F_147 ( V_2 -> V_63 . V_437 ,
V_2 -> V_25 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_438 , V_431 ) ;
F_149 ( V_2 , V_92 , V_2 -> V_69 ,
L_34 ,
V_2 -> V_25 , ( ( V_431 + 1 ) * 256 ) ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
unsigned int V_439 , V_440 , V_263 ;
unsigned int V_441 ;
unsigned int V_442 , V_443 , V_86 ;
unsigned int V_269 ;
unsigned int V_10 , V_444 , V_74 , V_75 ;
V_439 = V_2 -> V_28 / V_2 -> V_63 . V_274 ;
V_440 = V_2 -> V_28 % V_2 -> V_63 . V_274 ;
for ( V_10 = 0 , V_263 = 0 ; V_10 < V_2 -> V_63 . V_274 ; V_10 ++ ) {
for ( V_444 = 0 ; V_444 < V_439 ; V_444 ++ ) {
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_35 , V_263 , V_10 ) ;
F_13 ( V_2 , V_263 , V_29 ,
V_445 , V_10 ) ;
V_2 -> V_265 [ V_263 ++ ] = V_10 ;
}
if ( V_10 < V_440 ) {
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_35 , V_263 , V_10 ) ;
F_13 ( V_2 , V_263 , V_29 ,
V_445 , V_10 ) ;
V_2 -> V_265 [ V_263 ++ ] = V_10 ;
}
}
V_441 = F_40 (unsigned int, IEEE_8021QAZ_MAX_TCS,
pdata->rx_q_count) ;
V_442 = V_87 / V_441 ;
V_443 = V_87 % V_441 ;
V_74 = V_446 ;
V_75 = 0 ;
for ( V_10 = 0 , V_86 = 0 ; V_10 < V_441 ; ) {
V_269 = 0 ;
for ( V_444 = 0 ; V_444 < V_442 ; V_444 ++ ) {
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_36 , V_86 , V_10 ) ;
V_269 |= ( 1 << V_86 ) ;
V_2 -> V_89 [ V_86 ++ ] = V_10 ;
}
if ( V_10 < V_443 ) {
F_43 ( V_2 , V_92 , V_2 -> V_69 ,
L_36 , V_86 , V_10 ) ;
V_269 |= ( 1 << V_86 ) ;
V_2 -> V_89 [ V_86 ++ ] = V_10 ;
}
V_75 |= ( V_269 << ( ( V_10 ++ % V_447 ) << 3 ) ) ;
if ( ( V_10 % V_447 ) && ( V_10 != V_441 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_448 ;
V_75 = 0 ;
}
V_74 = V_449 ;
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; ) {
V_75 |= ( 0x80 << ( ( V_10 ++ % V_450 ) << 3 ) ) ;
if ( ( V_10 % V_450 ) && ( V_10 != V_2 -> V_25 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_451 ;
V_75 = 0 ;
}
}
static void F_152 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_452 , V_453 , 2 ) ;
F_13 ( V_2 , V_10 , V_452 , V_454 , 4 ) ;
}
}
static void F_153 ( struct V_1 * V_2 )
{
F_81 ( V_2 , V_2 -> V_69 -> V_455 ) ;
if ( V_2 -> V_63 . V_169 ) {
F_22 ( V_2 , V_129 , V_456 , 1 ) ;
F_22 ( V_2 , V_129 , V_457 , 1 ) ;
F_22 ( V_2 , V_129 , V_458 , 1 ) ;
}
}
static void F_154 ( struct V_1 * V_2 )
{
unsigned int V_24 ;
V_24 = ( V_2 -> V_69 -> V_273 > V_459 ) ? 1 : 0 ;
F_22 ( V_2 , V_40 , V_460 , V_24 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_461 ) {
case V_462 :
F_59 ( V_2 ) ;
break;
case V_463 :
F_58 ( V_2 ) ;
break;
case V_464 :
F_57 ( V_2 ) ;
break;
}
}
static void F_156 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 -> V_70 & V_372 )
F_92 ( V_2 ) ;
else
F_91 ( V_2 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_465 , V_466 , 0 ) ;
F_22 ( V_2 , V_465 , V_467 , 1 ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_149 )
F_62 ( V_2 ) ;
else
F_63 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_377 )
F_60 ( V_2 ) ;
else
F_61 ( V_2 ) ;
}
static T_5 F_158 ( struct V_1 * V_2 , unsigned int V_468 )
{
bool V_469 ;
T_5 V_24 ;
switch ( V_468 ) {
case V_470 :
case V_471 :
case V_472 :
case V_473 :
V_469 = true ;
break;
default:
V_469 = false ;
}
V_24 = F_41 ( V_2 , V_468 ) ;
if ( V_469 )
V_24 |= ( ( T_5 ) F_41 ( V_2 , V_468 + 4 ) << 32 ) ;
return V_24 ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_474 * V_475 = & V_2 -> V_476 ;
unsigned int V_477 = F_41 ( V_2 , V_478 ) ;
if ( F_108 ( V_477 , V_478 , V_479 ) )
V_475 -> V_480 +=
F_158 ( V_2 , V_470 ) ;
if ( F_108 ( V_477 , V_478 , V_481 ) )
V_475 -> V_482 +=
F_158 ( V_2 , V_483 ) ;
if ( F_108 ( V_477 , V_478 , V_484 ) )
V_475 -> V_485 +=
F_158 ( V_2 , V_486 ) ;
if ( F_108 ( V_477 , V_478 , V_487 ) )
V_475 -> V_488 +=
F_158 ( V_2 , V_489 ) ;
if ( F_108 ( V_477 , V_478 , V_490 ) )
V_475 -> V_491 +=
F_158 ( V_2 , V_492 ) ;
if ( F_108 ( V_477 , V_478 , V_493 ) )
V_475 -> V_494 +=
F_158 ( V_2 , V_495 ) ;
if ( F_108 ( V_477 , V_478 , V_496 ) )
V_475 -> V_497 +=
F_158 ( V_2 , V_498 ) ;
if ( F_108 ( V_477 , V_478 , V_499 ) )
V_475 -> V_500 +=
F_158 ( V_2 , V_501 ) ;
if ( F_108 ( V_477 , V_478 , V_502 ) )
V_475 -> V_503 +=
F_158 ( V_2 , V_504 ) ;
if ( F_108 ( V_477 , V_478 , V_505 ) )
V_475 -> V_506 +=
F_158 ( V_2 , V_507 ) ;
if ( F_108 ( V_477 , V_478 , V_508 ) )
V_475 -> V_509 +=
F_158 ( V_2 , V_510 ) ;
if ( F_108 ( V_477 , V_478 , V_511 ) )
V_475 -> V_512 +=
F_158 ( V_2 , V_513 ) ;
if ( F_108 ( V_477 , V_478 , V_514 ) )
V_475 -> V_485 +=
F_158 ( V_2 , V_515 ) ;
if ( F_108 ( V_477 , V_478 , V_516 ) )
V_475 -> V_517 +=
F_158 ( V_2 , V_518 ) ;
if ( F_108 ( V_477 , V_478 , V_519 ) )
V_475 -> V_520 +=
F_158 ( V_2 , V_471 ) ;
if ( F_108 ( V_477 , V_478 , V_521 ) )
V_475 -> V_522 +=
F_158 ( V_2 , V_523 ) ;
if ( F_108 ( V_477 , V_478 , V_524 ) )
V_475 -> V_525 +=
F_158 ( V_2 , V_526 ) ;
if ( F_108 ( V_477 , V_478 , V_527 ) )
V_475 -> V_528 +=
F_158 ( V_2 , V_529 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_474 * V_475 = & V_2 -> V_476 ;
unsigned int V_477 = F_41 ( V_2 , V_530 ) ;
if ( F_108 ( V_477 , V_530 , V_531 ) )
V_475 -> V_532 +=
F_158 ( V_2 , V_533 ) ;
if ( F_108 ( V_477 , V_530 , V_534 ) )
V_475 -> V_535 +=
F_158 ( V_2 , V_472 ) ;
if ( F_108 ( V_477 , V_530 , V_536 ) )
V_475 -> V_537 +=
F_158 ( V_2 , V_473 ) ;
if ( F_108 ( V_477 , V_530 , V_538 ) )
V_475 -> V_539 +=
F_158 ( V_2 , V_540 ) ;
if ( F_108 ( V_477 , V_530 , V_541 ) )
V_475 -> V_542 +=
F_158 ( V_2 , V_543 ) ;
if ( F_108 ( V_477 , V_530 , V_544 ) )
V_475 -> V_545 +=
F_158 ( V_2 , V_546 ) ;
if ( F_108 ( V_477 , V_530 , V_547 ) )
V_475 -> V_548 +=
F_158 ( V_2 , V_549 ) ;
if ( F_108 ( V_477 , V_530 , V_550 ) )
V_475 -> V_551 +=
F_158 ( V_2 , V_552 ) ;
if ( F_108 ( V_477 , V_530 , V_553 ) )
V_475 -> V_554 +=
F_158 ( V_2 , V_555 ) ;
if ( F_108 ( V_477 , V_530 , V_556 ) )
V_475 -> V_557 +=
F_158 ( V_2 , V_558 ) ;
if ( F_108 ( V_477 , V_530 , V_559 ) )
V_475 -> V_560 +=
F_158 ( V_2 , V_561 ) ;
if ( F_108 ( V_477 , V_530 , V_562 ) )
V_475 -> V_563 +=
F_158 ( V_2 , V_564 ) ;
if ( F_108 ( V_477 , V_530 , V_565 ) )
V_475 -> V_566 +=
F_158 ( V_2 , V_567 ) ;
if ( F_108 ( V_477 , V_530 , V_568 ) )
V_475 -> V_569 +=
F_158 ( V_2 , V_570 ) ;
if ( F_108 ( V_477 , V_530 , V_571 ) )
V_475 -> V_572 +=
F_158 ( V_2 , V_573 ) ;
if ( F_108 ( V_477 , V_530 , V_574 ) )
V_475 -> V_575 +=
F_158 ( V_2 , V_576 ) ;
if ( F_108 ( V_477 , V_530 , V_577 ) )
V_475 -> V_578 +=
F_158 ( V_2 , V_579 ) ;
if ( F_108 ( V_477 , V_530 , V_580 ) )
V_475 -> V_581 +=
F_158 ( V_2 , V_582 ) ;
if ( F_108 ( V_477 , V_530 , V_583 ) )
V_475 -> V_584 +=
F_158 ( V_2 , V_585 ) ;
if ( F_108 ( V_477 , V_530 , V_586 ) )
V_475 -> V_587 +=
F_158 ( V_2 , V_588 ) ;
if ( F_108 ( V_477 , V_530 , V_589 ) )
V_475 -> V_590 +=
F_158 ( V_2 , V_591 ) ;
if ( F_108 ( V_477 , V_530 , V_592 ) )
V_475 -> V_593 +=
F_158 ( V_2 , V_594 ) ;
if ( F_108 ( V_477 , V_530 , V_595 ) )
V_475 -> V_596 +=
F_158 ( V_2 , V_597 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_474 * V_475 = & V_2 -> V_476 ;
F_22 ( V_2 , V_598 , V_599 , 1 ) ;
V_475 -> V_480 +=
F_158 ( V_2 , V_470 ) ;
V_475 -> V_482 +=
F_158 ( V_2 , V_483 ) ;
V_475 -> V_485 +=
F_158 ( V_2 , V_486 ) ;
V_475 -> V_488 +=
F_158 ( V_2 , V_489 ) ;
V_475 -> V_491 +=
F_158 ( V_2 , V_492 ) ;
V_475 -> V_494 +=
F_158 ( V_2 , V_495 ) ;
V_475 -> V_497 +=
F_158 ( V_2 , V_498 ) ;
V_475 -> V_500 +=
F_158 ( V_2 , V_501 ) ;
V_475 -> V_503 +=
F_158 ( V_2 , V_504 ) ;
V_475 -> V_506 +=
F_158 ( V_2 , V_507 ) ;
V_475 -> V_509 +=
F_158 ( V_2 , V_510 ) ;
V_475 -> V_512 +=
F_158 ( V_2 , V_513 ) ;
V_475 -> V_485 +=
F_158 ( V_2 , V_515 ) ;
V_475 -> V_517 +=
F_158 ( V_2 , V_518 ) ;
V_475 -> V_520 +=
F_158 ( V_2 , V_471 ) ;
V_475 -> V_522 +=
F_158 ( V_2 , V_523 ) ;
V_475 -> V_525 +=
F_158 ( V_2 , V_526 ) ;
V_475 -> V_528 +=
F_158 ( V_2 , V_529 ) ;
V_475 -> V_532 +=
F_158 ( V_2 , V_533 ) ;
V_475 -> V_535 +=
F_158 ( V_2 , V_472 ) ;
V_475 -> V_537 +=
F_158 ( V_2 , V_473 ) ;
V_475 -> V_539 +=
F_158 ( V_2 , V_540 ) ;
V_475 -> V_542 +=
F_158 ( V_2 , V_543 ) ;
V_475 -> V_545 +=
F_158 ( V_2 , V_546 ) ;
V_475 -> V_548 +=
F_158 ( V_2 , V_549 ) ;
V_475 -> V_551 +=
F_158 ( V_2 , V_552 ) ;
V_475 -> V_554 +=
F_158 ( V_2 , V_555 ) ;
V_475 -> V_557 +=
F_158 ( V_2 , V_558 ) ;
V_475 -> V_560 +=
F_158 ( V_2 , V_561 ) ;
V_475 -> V_563 +=
F_158 ( V_2 , V_564 ) ;
V_475 -> V_566 +=
F_158 ( V_2 , V_567 ) ;
V_475 -> V_569 +=
F_158 ( V_2 , V_570 ) ;
V_475 -> V_572 +=
F_158 ( V_2 , V_573 ) ;
V_475 -> V_575 +=
F_158 ( V_2 , V_576 ) ;
V_475 -> V_578 +=
F_158 ( V_2 , V_579 ) ;
V_475 -> V_581 +=
F_158 ( V_2 , V_582 ) ;
V_475 -> V_584 +=
F_158 ( V_2 , V_585 ) ;
V_475 -> V_587 +=
F_158 ( V_2 , V_588 ) ;
V_475 -> V_590 +=
F_158 ( V_2 , V_591 ) ;
V_475 -> V_593 +=
F_158 ( V_2 , V_594 ) ;
V_475 -> V_596 +=
F_158 ( V_2 , V_597 ) ;
F_22 ( V_2 , V_598 , V_599 , 0 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_598 , V_600 , 1 ) ;
F_22 ( V_2 , V_598 , V_601 , 1 ) ;
}
static void F_163 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned int V_602 , V_603 , V_604 ;
unsigned int V_605 ;
unsigned long V_606 ;
if ( V_9 -> V_346 < V_607 ) {
V_602 = V_608 ;
V_603 = ( V_9 -> V_346 * V_609 ) +
V_610 ;
} else {
V_604 = V_9 -> V_346 - V_607 ;
V_602 = V_611 + ( ( V_604 / V_612 ) * V_613 ) ;
V_603 = ( ( V_604 % V_612 ) * V_609 ) +
V_614 ;
}
V_606 = V_291 + ( V_615 * V_616 ) ;
while ( F_164 ( V_291 , V_606 ) ) {
V_605 = F_41 ( V_2 , V_602 ) ;
V_605 = F_165 ( V_605 , V_603 , V_617 ) ;
if ( ( V_605 == V_618 ) ||
( V_605 == V_619 ) )
break;
F_27 ( 500 , 1000 ) ;
}
if ( ! F_164 ( V_291 , V_606 ) )
F_166 ( V_2 -> V_69 ,
L_37 ,
V_9 -> V_346 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_620 , 1 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_621 ,
V_622 ) ;
F_22 ( V_2 , V_121 , V_623 , 1 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_163 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_121 , V_623 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_621 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_620 , 0 ) ;
}
}
static void F_169 ( struct V_1 * V_2 ,
unsigned int V_263 )
{
unsigned int V_376 ;
unsigned long V_624 ;
V_624 = V_291 + ( V_615 * V_616 ) ;
while ( F_164 ( V_291 , V_624 ) ) {
V_376 = F_54 ( V_2 , V_263 , V_625 ) ;
if ( ( F_108 ( V_376 , V_625 , V_626 ) == 0 ) &&
( F_108 ( V_376 , V_625 , V_627 ) == 0 ) )
break;
F_27 ( 500 , 1000 ) ;
}
if ( ! F_164 ( V_291 , V_624 ) )
F_166 ( V_2 -> V_69 ,
L_38 ,
V_263 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_75 , V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_628 , 1 ) ;
}
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
V_75 |= ( 0x02 << ( V_10 << 1 ) ) ;
F_26 ( V_2 , V_629 , V_75 ) ;
F_22 ( V_2 , V_40 , V_630 , 1 ) ;
F_22 ( V_2 , V_40 , V_631 , 1 ) ;
F_22 ( V_2 , V_40 , V_632 , 1 ) ;
F_22 ( V_2 , V_40 , V_633 , 1 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
F_22 ( V_2 , V_40 , V_630 , 0 ) ;
F_22 ( V_2 , V_40 , V_631 , 0 ) ;
F_22 ( V_2 , V_40 , V_632 , 0 ) ;
F_22 ( V_2 , V_40 , V_633 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_169 ( V_2 , V_10 ) ;
F_26 ( V_2 , V_629 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_628 , 0 ) ;
}
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_620 , 1 ) ;
}
F_22 ( V_2 , V_121 , V_623 , 1 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_163 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_121 , V_623 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_620 , 0 ) ;
}
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_628 , 1 ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_628 , 0 ) ;
}
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_634 * V_635 = & V_2 -> V_635 ;
int V_5 ;
F_2 ( L_39 ) ;
V_5 = F_142 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
F_11 ( V_2 ) ;
F_4 ( V_2 ) ;
F_8 ( V_2 ) ;
F_10 ( V_2 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_37 ( V_2 ) ;
V_635 -> V_636 ( V_2 ) ;
V_635 -> V_637 ( V_2 ) ;
F_49 ( V_2 ) ;
F_146 ( V_2 ) ;
F_151 ( V_2 ) ;
F_14 ( V_2 , V_2 -> V_638 ) ;
F_12 ( V_2 , V_2 -> V_639 ) ;
F_16 ( V_2 , V_2 -> V_640 ) ;
F_15 ( V_2 , V_2 -> V_641 ) ;
F_148 ( V_2 ) ;
F_150 ( V_2 ) ;
F_152 ( V_2 ) ;
F_120 ( V_2 ) ;
F_122 ( V_2 ) ;
F_52 ( V_2 ) ;
F_153 ( V_2 ) ;
F_82 ( V_2 ) ;
F_154 ( V_2 ) ;
F_48 ( V_2 ) ;
F_155 ( V_2 ) ;
F_156 ( V_2 ) ;
F_157 ( V_2 ) ;
F_162 ( V_2 ) ;
F_56 ( V_2 ) ;
F_2 ( L_40 ) ;
return 0 ;
}
void F_177 ( struct V_642 * V_643 )
{
F_2 ( L_41 ) ;
V_643 -> V_644 = F_89 ;
V_643 -> V_645 = F_81 ;
V_643 -> V_646 = F_82 ;
V_643 -> V_647 = F_92 ;
V_643 -> V_648 = F_91 ;
V_643 -> V_649 = F_60 ;
V_643 -> V_650 = F_61 ;
V_643 -> V_651 = F_62 ;
V_643 -> V_652 = F_63 ;
V_643 -> V_653 = F_66 ;
V_643 -> V_654 = F_83 ;
V_643 -> V_655 = F_88 ;
V_643 -> V_656 = F_57 ;
V_643 -> V_657 = F_58 ;
V_643 -> V_658 = F_59 ;
V_643 -> V_659 = F_167 ;
V_643 -> V_660 = F_168 ;
V_643 -> V_661 = F_170 ;
V_643 -> V_662 = F_171 ;
V_643 -> V_663 = F_172 ;
V_643 -> V_664 = F_173 ;
V_643 -> V_665 = F_174 ;
V_643 -> V_666 = F_175 ;
V_643 -> V_667 = F_127 ;
V_643 -> V_668 = F_133 ;
V_643 -> V_669 = F_139 ;
V_643 -> V_670 = F_140 ;
V_643 -> V_671 = F_176 ;
V_643 -> exit = F_141 ;
V_643 -> V_672 = F_95 ;
V_643 -> V_673 = F_102 ;
V_643 -> V_674 = F_93 ;
V_643 -> V_675 = F_99 ;
V_643 -> V_676 = F_138 ;
V_643 -> V_677 = F_137 ;
V_643 -> V_678 = F_123 ;
V_643 -> V_679 = F_46 ;
V_643 -> V_680 = F_47 ;
V_643 -> V_681 = F_17 ;
V_643 -> V_682 = F_18 ;
V_643 -> V_683 = F_1 ;
V_643 -> V_684 = F_3 ;
V_643 -> V_685 = F_15 ;
V_643 -> V_686 = F_16 ;
V_643 -> V_687 = F_12 ;
V_643 -> V_688 = F_14 ;
V_643 -> V_689 = F_11 ;
V_643 -> V_690 = F_10 ;
V_643 -> V_691 = F_9 ;
V_643 -> V_692 = F_8 ;
V_643 -> V_693 = F_6 ;
V_643 -> V_694 = F_4 ;
V_643 -> V_695 = F_159 ;
V_643 -> V_696 = F_160 ;
V_643 -> V_697 = F_161 ;
V_643 -> V_698 = F_111 ;
V_643 -> V_699 = F_103 ;
V_643 -> V_700 = F_105 ;
V_643 -> V_701 = F_106 ;
V_643 -> V_702 = F_107 ;
V_643 -> V_703 = F_115 ;
V_643 -> V_704 = F_120 ;
V_643 -> V_705 = F_122 ;
V_643 -> V_706 = F_35 ;
V_643 -> V_707 = F_36 ;
V_643 -> V_708 = F_32 ;
V_643 -> V_709 = F_33 ;
F_2 ( L_42 ) ;
}
