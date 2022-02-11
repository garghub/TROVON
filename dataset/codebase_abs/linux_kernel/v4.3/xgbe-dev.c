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
unsigned int V_72 , V_73 ;
unsigned int V_74 , V_75 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_76 , 1 ) ;
V_72 = V_77 ;
V_73 = F_40 (unsigned int, pdata->tx_q_count, max_q_count) ;
V_74 = V_78 ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
V_75 = F_41 ( V_2 , V_74 ) ;
F_34 ( V_75 , V_78 , V_79 , 1 ) ;
F_34 ( V_75 , V_78 , V_81 , 0xffff ) ;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_80 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_82 , V_83 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_82 , V_83 , 1 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
if ( V_2 -> V_86 || ( V_85 && V_85 -> V_87 ) )
F_42 ( V_2 ) ;
else
F_39 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
if ( V_2 -> V_88 || ( V_85 && V_85 -> V_87 ) )
F_44 ( V_2 ) ;
else
F_43 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_22 ( V_2 , V_82 , V_89 ,
( V_85 && V_85 -> V_87 ) ? 1 : 0 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_90 , V_91 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
V_90 = F_49 ( V_9 , V_92 ) ;
F_50 ( V_9 , V_92 , V_90 ) ;
V_91 = 0 ;
F_34 ( V_91 , V_93 , V_94 , 1 ) ;
F_34 ( V_91 , V_93 , V_95 , 1 ) ;
F_34 ( V_91 , V_93 , V_96 , 1 ) ;
if ( V_9 -> V_17 ) {
if ( ! V_2 -> V_97 )
F_34 ( V_91 , V_93 , V_98 , 1 ) ;
}
if ( V_9 -> V_20 ) {
F_34 ( V_91 , V_93 , V_99 , 1 ) ;
if ( ! V_2 -> V_97 )
F_34 ( V_91 , V_93 , V_100 , 1 ) ;
}
F_50 ( V_9 , V_93 , V_91 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_101 ;
unsigned int V_73 , V_10 ;
V_73 = F_52 ( V_2 -> V_63 . V_102 , V_2 -> V_63 . V_103 ) ;
for ( V_10 = 0 ; V_10 < V_73 ; V_10 ++ ) {
V_101 = F_53 ( V_2 , V_10 , V_104 ) ;
F_54 ( V_2 , V_10 , V_104 , V_101 ) ;
F_54 ( V_2 , V_10 , V_105 , 0 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_106 = 0 ;
F_34 ( V_106 , V_107 , V_108 , 1 ) ;
F_26 ( V_2 , V_107 , V_106 ) ;
F_22 ( V_2 , V_109 , V_110 , 0xffffffff ) ;
F_22 ( V_2 , V_111 , V_110 , 0xffffffff ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , V_112 , V_113 ) == 0x3 )
return 0 ;
F_22 ( V_2 , V_112 , V_113 , 0x3 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , V_112 , V_113 ) == 0x2 )
return 0 ;
F_22 ( V_2 , V_112 , V_113 , 0x2 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 , V_112 , V_113 ) == 0 )
return 0 ;
F_22 ( V_2 , V_112 , V_113 , 0 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
unsigned int V_114 )
{
unsigned int V_24 = V_114 ? 1 : 0 ;
if ( F_25 ( V_2 , V_115 , V_116 ) == V_24 )
return 0 ;
F_60 ( V_2 , V_117 , V_2 -> V_69 , L_6 ,
V_114 ? L_7 : L_8 ) ;
F_22 ( V_2 , V_115 , V_116 , V_24 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
unsigned int V_114 )
{
unsigned int V_24 = V_114 ? 1 : 0 ;
if ( F_25 ( V_2 , V_115 , V_118 ) == V_24 )
return 0 ;
F_60 ( V_2 , V_117 , V_2 -> V_69 , L_9 ,
V_114 ? L_7 : L_8 ) ;
F_22 ( V_2 , V_115 , V_118 , V_24 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_119 * V_120 , unsigned int * V_121 )
{
unsigned int V_122 , V_123 ;
T_1 * V_124 ;
V_123 = 0 ;
V_122 = 0 ;
if ( V_120 ) {
V_124 = ( T_1 * ) & V_123 ;
V_124 [ 0 ] = V_120 -> V_125 [ 0 ] ;
V_124 [ 1 ] = V_120 -> V_125 [ 1 ] ;
V_124 [ 2 ] = V_120 -> V_125 [ 2 ] ;
V_124 [ 3 ] = V_120 -> V_125 [ 3 ] ;
V_124 = ( T_1 * ) & V_122 ;
V_124 [ 0 ] = V_120 -> V_125 [ 4 ] ;
V_124 [ 1 ] = V_120 -> V_125 [ 5 ] ;
F_60 ( V_2 , V_117 , V_2 -> V_69 ,
L_10 ,
V_120 -> V_125 , * V_121 ) ;
F_34 ( V_122 , V_126 , V_127 , 1 ) ;
}
F_26 ( V_2 , * V_121 , V_122 ) ;
* V_121 += V_128 ;
F_26 ( V_2 , * V_121 , V_123 ) ;
* V_121 += V_128 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_129 * V_69 = V_2 -> V_69 ;
struct V_119 * V_120 ;
unsigned int V_121 ;
unsigned int V_130 ;
V_121 = V_126 ;
V_130 = V_2 -> V_63 . V_131 ;
if ( F_64 ( V_69 ) > V_130 ) {
F_59 ( V_2 , 1 ) ;
} else {
F_65 (ha, netdev) {
F_62 ( V_2 , V_120 , & V_121 ) ;
V_130 -- ;
}
if ( F_66 ( V_69 ) > V_130 ) {
F_61 ( V_2 , 1 ) ;
} else {
F_67 (ha, netdev) {
F_62 ( V_2 , V_120 , & V_121 ) ;
V_130 -- ;
}
}
}
while ( V_130 -- )
F_62 ( V_2 , NULL , & V_121 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_129 * V_69 = V_2 -> V_69 ;
struct V_119 * V_120 ;
unsigned int V_132 ;
unsigned int V_133 , V_134 ;
V_56 V_135 [ V_136 ] ;
V_56 V_137 ;
unsigned int V_10 ;
V_133 = 26 - ( V_2 -> V_63 . V_138 >> 7 ) ;
V_134 = V_2 -> V_63 . V_138 / 32 ;
memset ( V_135 , 0 , sizeof( V_135 ) ) ;
F_65 (ha, netdev) {
V_137 = F_69 ( ~ F_70 ( ~ 0 , V_120 -> V_125 , V_139 ) ) ;
V_137 >>= V_133 ;
V_135 [ V_137 >> 5 ] |= ( 1 << ( V_137 & 0x1f ) ) ;
}
F_67 (ha, netdev) {
V_137 = F_69 ( ~ F_70 ( ~ 0 , V_120 -> V_125 , V_139 ) ) ;
V_137 >>= V_133 ;
V_135 [ V_137 >> 5 ] |= ( 1 << ( V_137 & 0x1f ) ) ;
}
V_132 = V_140 ;
for ( V_10 = 0 ; V_10 < V_134 ; V_10 ++ ) {
F_26 ( V_2 , V_132 , V_135 [ V_10 ] ) ;
V_132 += V_141 ;
}
}
static int F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 . V_138 )
F_68 ( V_2 ) ;
else
F_63 ( V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , T_1 * V_125 )
{
unsigned int V_122 , V_123 ;
V_122 = ( V_125 [ 5 ] << 8 ) | ( V_125 [ 4 ] << 0 ) ;
V_123 = ( V_125 [ 3 ] << 24 ) | ( V_125 [ 2 ] << 16 ) |
( V_125 [ 1 ] << 8 ) | ( V_125 [ 0 ] << 0 ) ;
F_26 ( V_2 , V_142 , V_122 ) ;
F_26 ( V_2 , V_143 , V_123 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_129 * V_69 = V_2 -> V_69 ;
unsigned int V_144 , V_145 ;
V_144 = ( ( V_69 -> V_146 & V_147 ) != 0 ) ;
V_145 = ( ( V_69 -> V_146 & V_148 ) != 0 ) ;
F_59 ( V_2 , V_144 ) ;
F_61 ( V_2 , V_145 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , int V_149 ,
int V_150 )
{
unsigned int V_151 ;
int V_152 ;
if ( V_150 & V_153 )
V_151 = V_150 & ~ V_153 ;
else
V_151 = ( V_2 -> V_154 << 16 ) | ( V_150 & 0xffff ) ;
F_24 ( & V_2 -> V_155 ) ;
F_75 ( V_2 , V_156 << 2 , V_151 >> 8 ) ;
V_152 = F_76 ( V_2 , ( V_151 & 0xff ) << 2 ) ;
F_28 ( & V_2 -> V_155 ) ;
return V_152 ;
}
static void F_77 ( struct V_1 * V_2 , int V_149 ,
int V_150 , int V_152 )
{
unsigned int V_151 ;
if ( V_150 & V_153 )
V_151 = V_150 & ~ V_153 ;
else
V_151 = ( V_2 -> V_154 << 16 ) | ( V_150 & 0xffff ) ;
F_24 ( & V_2 -> V_155 ) ;
F_75 ( V_2 , V_156 << 2 , V_151 >> 8 ) ;
F_75 ( V_2 , ( V_151 & 0xff ) << 2 , V_152 ) ;
F_28 ( & V_2 -> V_155 ) ;
}
static int F_78 ( struct V_157 * V_158 )
{
return ! F_79 ( V_158 -> V_159 , V_160 , V_161 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_162 , 0 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_162 , 1 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_163 , V_164 , 1 ) ;
F_22 ( V_2 , V_163 , V_165 , 1 ) ;
F_22 ( V_2 , V_163 , V_166 , 0 ) ;
F_22 ( V_2 , V_163 , V_167 , 0 ) ;
F_22 ( V_2 , V_163 , V_168 , 0x3 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_163 , V_168 , 0 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_115 , V_169 , 1 ) ;
F_22 ( V_2 , V_163 , V_170 , 1 ) ;
F_22 ( V_2 , V_163 , V_171 , 0 ) ;
F_22 ( V_2 , V_163 , V_172 , 1 ) ;
F_22 ( V_2 , V_163 , V_173 , 1 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_115 , V_169 , 0 ) ;
return 0 ;
}
static V_56 F_86 ( T_2 V_174 )
{
V_56 V_175 = V_176 ;
V_56 V_137 = ~ 0 ;
V_56 V_177 = 0 ;
unsigned char * V_178 = ( unsigned char * ) & V_174 ;
unsigned char V_179 = 0 ;
int V_10 , V_180 ;
V_180 = F_87 ( V_181 ) ;
for ( V_10 = 0 ; V_10 < V_180 ; V_10 ++ ) {
if ( ( V_10 % 8 ) == 0 )
V_179 = V_178 [ V_10 / 8 ] ;
V_177 = ( ( V_137 & 1 ) ^ V_179 ) & 1 ;
V_137 >>= 1 ;
V_179 >>= 1 ;
if ( V_177 )
V_137 ^= V_175 ;
}
return V_137 ;
}
static int F_88 ( struct V_1 * V_2 )
{
V_56 V_137 ;
T_3 V_182 ;
T_2 V_174 ;
T_3 V_183 = 0 ;
F_89 (vid, pdata->active_vlans, VLAN_N_VID) {
V_174 = F_90 ( V_182 ) ;
V_137 = F_69 ( ~ F_86 ( V_174 ) ) >> 28 ;
V_183 |= ( 1 << V_137 ) ;
}
F_22 ( V_2 , V_184 , V_185 , V_183 ) ;
return 0 ;
}
static void F_91 ( struct V_186 * V_187 )
{
struct V_157 * V_158 = V_187 -> V_158 ;
V_158 -> V_188 = 0 ;
V_158 -> V_189 = 0 ;
V_158 -> V_190 = 0 ;
V_158 -> V_159 = 0 ;
F_92 () ;
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_191 * V_192 = V_9 -> V_17 ;
struct V_186 * V_187 ;
int V_10 ;
int V_193 = V_192 -> V_194 ;
F_2 ( L_11 ) ;
for ( V_10 = 0 ; V_10 < V_192 -> V_195 ; V_10 ++ ) {
V_187 = F_94 ( V_192 , V_10 ) ;
F_91 ( V_187 ) ;
}
F_50 ( V_9 , V_196 , V_192 -> V_195 - 1 ) ;
V_187 = F_94 ( V_192 , V_193 ) ;
F_50 ( V_9 , V_197 ,
F_95 ( V_187 -> V_198 ) ) ;
F_50 ( V_9 , V_199 ,
F_96 ( V_187 -> V_198 ) ) ;
F_2 ( L_12 ) ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_186 * V_187 , unsigned int V_43 )
{
struct V_157 * V_158 = V_187 -> V_158 ;
unsigned int V_200 = V_2 -> V_200 ;
unsigned int V_201 = V_2 -> V_201 ;
unsigned int V_202 ;
T_4 V_203 , V_204 ;
if ( ! V_200 && ! V_201 ) {
V_202 = 1 ;
} else {
if ( V_201 && ! ( ( V_43 + 1 ) % V_201 ) )
V_202 = 1 ;
else
V_202 = 0 ;
}
V_203 = V_187 -> V_205 . V_206 . V_207 + V_187 -> V_205 . V_206 . V_208 ;
V_204 = V_187 -> V_205 . V_209 . V_207 + V_187 -> V_205 . V_209 . V_208 ;
V_158 -> V_188 = F_98 ( F_96 ( V_203 ) ) ;
V_158 -> V_189 = F_98 ( F_95 ( V_203 ) ) ;
V_158 -> V_190 = F_98 ( F_96 ( V_204 ) ) ;
V_158 -> V_159 = F_98 ( F_95 ( V_204 ) ) ;
F_99 ( V_158 -> V_159 , V_210 , V_211 , V_202 ) ;
F_92 () ;
F_99 ( V_158 -> V_159 , V_210 , V_161 , 1 ) ;
F_92 () ;
}
static void F_100 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_191 * V_192 = V_9 -> V_20 ;
struct V_186 * V_187 ;
unsigned int V_193 = V_192 -> V_194 ;
unsigned int V_10 ;
F_2 ( L_13 ) ;
for ( V_10 = 0 ; V_10 < V_192 -> V_195 ; V_10 ++ ) {
V_187 = F_94 ( V_192 , V_10 ) ;
F_97 ( V_2 , V_187 , V_10 ) ;
}
F_50 ( V_9 , V_212 , V_192 -> V_195 - 1 ) ;
V_187 = F_94 ( V_192 , V_193 ) ;
F_50 ( V_9 , V_213 ,
F_95 ( V_187 -> V_198 ) ) ;
F_50 ( V_9 , V_214 ,
F_96 ( V_187 -> V_198 ) ) ;
V_187 = F_94 ( V_192 , V_193 + V_192 -> V_195 - 1 ) ;
F_50 ( V_9 , V_215 ,
F_96 ( V_187 -> V_198 ) ) ;
F_2 ( L_14 ) ;
}
static void F_101 ( struct V_1 * V_2 ,
unsigned int V_216 )
{
F_26 ( V_2 , V_217 , V_216 ) ;
F_22 ( V_2 , V_218 , V_219 , 1 ) ;
while ( F_25 ( V_2 , V_218 , V_219 ) )
F_102 ( 5 ) ;
}
static void F_103 ( struct V_1 * V_2 , unsigned int V_220 ,
unsigned int V_221 )
{
F_26 ( V_2 , V_222 , V_220 ) ;
F_26 ( V_2 , V_223 , V_221 ) ;
F_22 ( V_2 , V_218 , V_224 , 1 ) ;
while ( F_25 ( V_2 , V_218 , V_224 ) )
F_102 ( 5 ) ;
}
static T_5 F_104 ( struct V_1 * V_2 )
{
T_5 V_221 ;
V_221 = F_41 ( V_2 , V_225 ) ;
V_221 *= V_226 ;
V_221 += F_41 ( V_2 , V_227 ) ;
return V_221 ;
}
static T_5 F_105 ( struct V_1 * V_2 )
{
unsigned int V_228 ;
T_5 V_221 ;
V_228 = F_41 ( V_2 , V_229 ) ;
if ( F_106 ( V_228 , V_229 , V_230 ) )
return 0 ;
V_221 = F_41 ( V_2 , V_231 ) ;
V_221 *= V_226 ;
V_221 += V_228 ;
return V_221 ;
}
static void F_107 ( struct V_232 * V_233 ,
struct V_157 * V_158 )
{
T_5 V_221 ;
if ( F_79 ( V_158 -> V_159 , V_234 , V_235 ) &&
! F_79 ( V_158 -> V_159 , V_234 , V_236 ) ) {
V_221 = F_108 ( V_158 -> V_189 ) ;
V_221 <<= 32 ;
V_221 |= F_108 ( V_158 -> V_188 ) ;
if ( V_221 != 0xffffffffffffffffULL ) {
V_233 -> V_237 = V_221 ;
F_34 ( V_233 -> V_238 , V_239 ,
V_240 , 1 ) ;
}
}
}
static int F_109 ( struct V_1 * V_2 ,
unsigned int V_241 )
{
F_34 ( V_241 , V_218 , V_242 , 1 ) ;
F_34 ( V_241 , V_218 , V_243 , 1 ) ;
F_34 ( V_241 , V_218 , V_244 , 1 ) ;
F_26 ( V_2 , V_218 , V_241 ) ;
if ( ! F_106 ( V_241 , V_218 , V_245 ) )
return 0 ;
F_22 ( V_2 , V_246 , V_247 , V_248 ) ;
F_22 ( V_2 , V_246 , V_249 , V_250 ) ;
F_101 ( V_2 , V_2 -> V_251 ) ;
F_103 ( V_2 , 0 , 0 ) ;
F_110 ( & V_2 -> V_252 , & V_2 -> V_253 ,
F_111 ( F_112 () ) ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_254 * V_255 = V_2 -> V_255 ;
unsigned int V_256 , V_257 , V_258 ;
unsigned int V_10 ;
if ( ! V_255 )
return;
F_22 ( V_2 , V_259 , V_260 , V_261 ) ;
V_256 = V_2 -> V_69 -> V_262 * V_2 -> V_63 . V_263 ;
V_257 = V_256 / 100 ;
if ( ! V_257 )
V_257 = 1 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_263 ; V_10 ++ ) {
switch ( V_255 -> V_264 [ V_10 ] ) {
case V_265 :
F_60 ( V_2 , V_117 , V_2 -> V_69 ,
L_15 , V_10 ) ;
F_13 ( V_2 , V_10 , V_266 , V_235 ,
V_267 ) ;
break;
case V_268 :
V_258 = V_256 * V_255 -> V_269 [ V_10 ] / 100 ;
V_258 = F_114 ( V_258 , V_257 , V_256 ) ;
F_60 ( V_2 , V_117 , V_2 -> V_69 ,
L_16 , V_10 , V_258 ) ;
F_13 ( V_2 , V_10 , V_266 , V_235 ,
V_270 ) ;
F_13 ( V_2 , V_10 , V_271 , V_272 ,
V_258 ) ;
break;
}
}
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
struct V_254 * V_255 = V_2 -> V_255 ;
unsigned int V_273 , V_74 , V_75 ;
unsigned int V_274 , V_275 ;
if ( ! V_85 || ! V_255 )
return;
for ( V_274 = 0 ; V_274 < V_2 -> V_63 . V_263 ; V_274 ++ ) {
V_273 = 0 ;
for ( V_275 = 0 ; V_275 < V_276 ; V_275 ++ ) {
if ( ( V_85 -> V_87 & ( 1 << V_275 ) ) &&
( V_255 -> V_277 [ V_275 ] == V_274 ) )
V_273 |= ( 1 << V_275 ) ;
}
V_273 &= 0xff ;
F_60 ( V_2 , V_117 , V_2 -> V_69 , L_17 ,
V_274 , V_273 ) ;
V_74 = V_278 + ( V_279 * ( V_274 / V_280 ) ) ;
V_75 = F_41 ( V_2 , V_74 ) ;
V_75 &= ~ ( 0xff << ( ( V_274 % V_280 ) << 3 ) ) ;
V_75 |= ( V_273 << ( ( V_274 % V_280 ) << 3 ) ) ;
F_26 ( V_2 , V_74 , V_75 ) ;
}
F_47 ( V_2 ) ;
}
static void F_116 ( struct V_8 * V_9 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_186 * V_187 ;
F_117 () ;
V_187 = F_94 ( V_192 , V_192 -> V_194 ) ;
F_50 ( V_9 , V_281 ,
F_96 ( V_187 -> V_198 ) ) ;
if ( V_2 -> V_282 && ! V_9 -> V_283 ) {
V_9 -> V_283 = 1 ;
F_118 ( & V_9 -> V_284 ,
V_285 + F_119 ( V_2 -> V_282 ) ) ;
}
V_192 -> V_286 . V_287 = 0 ;
}
static void F_120 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_191 * V_192 = V_9 -> V_17 ;
struct V_186 * V_187 ;
struct V_157 * V_158 ;
struct V_232 * V_233 = & V_192 -> V_288 ;
unsigned int V_289 , V_290 , V_291 ;
unsigned int V_292 , V_293 ;
unsigned int V_294 ;
int V_193 = V_192 -> V_194 ;
int V_295 = V_192 -> V_194 ;
int V_10 ;
F_2 ( L_18 ) ;
V_289 = F_106 ( V_233 -> V_238 , V_296 ,
V_297 ) ;
V_290 = F_106 ( V_233 -> V_238 , V_296 ,
V_298 ) ;
V_291 = F_106 ( V_233 -> V_238 , V_296 ,
V_299 ) ;
if ( V_290 && ( V_233 -> V_300 != V_192 -> V_286 . V_301 ) )
V_292 = 1 ;
else
V_292 = 0 ;
if ( V_291 && ( V_233 -> V_302 != V_192 -> V_286 . V_303 ) )
V_293 = 1 ;
else
V_293 = 0 ;
V_192 -> V_304 += V_233 -> V_305 ;
if ( ! V_2 -> V_306 )
V_294 = 0 ;
else if ( V_233 -> V_305 > V_2 -> V_306 )
V_294 = 1 ;
else if ( ( V_192 -> V_304 % V_2 -> V_306 ) <
V_233 -> V_305 )
V_294 = 1 ;
else
V_294 = 0 ;
V_187 = F_94 ( V_192 , V_295 ) ;
V_158 = V_187 -> V_158 ;
if ( V_292 || V_293 ) {
if ( V_292 ) {
F_60 ( V_2 , V_307 , V_2 -> V_69 ,
L_19 ,
V_233 -> V_300 ) ;
F_99 ( V_158 -> V_190 , V_308 ,
V_309 , V_233 -> V_300 ) ;
F_99 ( V_158 -> V_159 , V_310 ,
V_311 , 1 ) ;
F_99 ( V_158 -> V_159 , V_310 ,
V_312 , 1 ) ;
V_192 -> V_286 . V_301 = V_233 -> V_300 ;
}
if ( V_293 ) {
F_60 ( V_2 , V_307 , V_2 -> V_69 ,
L_20 ,
V_233 -> V_302 ) ;
F_99 ( V_158 -> V_159 , V_310 ,
V_311 , 1 ) ;
F_99 ( V_158 -> V_159 , V_310 ,
V_313 , V_233 -> V_302 ) ;
F_99 ( V_158 -> V_159 , V_310 ,
V_314 , 1 ) ;
V_192 -> V_286 . V_303 = V_233 -> V_302 ;
}
V_295 ++ ;
V_187 = F_94 ( V_192 , V_295 ) ;
V_158 = V_187 -> V_158 ;
}
V_158 -> V_188 = F_98 ( F_96 ( V_187 -> V_315 ) ) ;
V_158 -> V_189 = F_98 ( F_95 ( V_187 -> V_315 ) ) ;
F_99 ( V_158 -> V_190 , V_316 , V_317 ,
V_187 -> V_318 ) ;
if ( V_291 )
F_99 ( V_158 -> V_190 , V_316 , V_319 ,
V_320 ) ;
if ( F_106 ( V_233 -> V_238 , V_296 , V_321 ) )
F_99 ( V_158 -> V_190 , V_316 , V_322 , 1 ) ;
F_99 ( V_158 -> V_159 , V_160 , V_323 , 1 ) ;
F_99 ( V_158 -> V_159 , V_160 , V_311 , 0 ) ;
if ( V_295 != V_193 )
F_99 ( V_158 -> V_159 , V_160 , V_161 , 1 ) ;
if ( V_290 ) {
F_99 ( V_158 -> V_159 , V_160 , V_38 , 1 ) ;
F_99 ( V_158 -> V_159 , V_160 , V_324 ,
V_233 -> V_325 ) ;
F_99 ( V_158 -> V_159 , V_160 , V_326 ,
V_233 -> V_327 / 4 ) ;
V_2 -> V_328 . V_329 ++ ;
} else {
F_99 ( V_158 -> V_159 , V_160 , V_330 , 0 ) ;
if ( V_289 )
F_99 ( V_158 -> V_159 , V_160 ,
V_331 , 0x3 ) ;
F_99 ( V_158 -> V_159 , V_160 , V_332 ,
V_233 -> V_333 ) ;
}
for ( V_10 = V_295 - V_193 + 1 ; V_10 < V_233 -> V_195 ; V_10 ++ ) {
V_295 ++ ;
V_187 = F_94 ( V_192 , V_295 ) ;
V_158 = V_187 -> V_158 ;
V_158 -> V_188 = F_98 ( F_96 ( V_187 -> V_315 ) ) ;
V_158 -> V_189 = F_98 ( F_95 ( V_187 -> V_315 ) ) ;
F_99 ( V_158 -> V_190 , V_316 , V_317 ,
V_187 -> V_318 ) ;
F_99 ( V_158 -> V_159 , V_160 , V_161 , 1 ) ;
F_99 ( V_158 -> V_159 , V_160 , V_311 , 0 ) ;
if ( V_289 )
F_99 ( V_158 -> V_159 , V_160 ,
V_331 , 0x3 ) ;
}
F_99 ( V_158 -> V_159 , V_160 , V_334 , 1 ) ;
if ( V_294 )
F_99 ( V_158 -> V_190 , V_316 , V_335 , 1 ) ;
V_187 -> V_286 . V_336 = V_233 -> V_305 ;
V_187 -> V_286 . V_337 = V_233 -> V_338 ;
F_92 () ;
V_187 = F_94 ( V_192 , V_193 ) ;
V_158 = V_187 -> V_158 ;
F_99 ( V_158 -> V_159 , V_160 , V_161 , 1 ) ;
if ( F_121 ( V_2 ) )
F_122 ( V_2 , V_192 , V_193 ,
V_233 -> V_195 , 1 ) ;
F_123 () ;
V_192 -> V_194 = V_295 + 1 ;
if ( ! V_233 -> V_339 -> V_287 ||
F_124 ( F_125 ( V_2 -> V_69 ,
V_9 -> V_340 ) ) )
F_116 ( V_9 , V_192 ) ;
else
V_192 -> V_286 . V_287 = 1 ;
F_2 ( L_21 ,
V_9 -> V_341 , V_193 & ( V_192 -> V_195 - 1 ) ,
( V_192 -> V_194 - 1 ) & ( V_192 -> V_195 - 1 ) ) ;
F_2 ( L_22 ) ;
}
static int F_126 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_191 * V_192 = V_9 -> V_20 ;
struct V_186 * V_187 ;
struct V_157 * V_158 ;
struct V_232 * V_233 = & V_192 -> V_288 ;
struct V_129 * V_69 = V_2 -> V_69 ;
unsigned int V_342 , V_343 , V_344 ;
F_2 ( L_23 , V_192 -> V_194 ) ;
V_187 = F_94 ( V_192 , V_192 -> V_194 ) ;
V_158 = V_187 -> V_158 ;
if ( F_79 ( V_158 -> V_159 , V_210 , V_161 ) )
return 1 ;
F_127 () ;
if ( F_128 ( V_2 ) )
F_129 ( V_2 , V_192 , V_192 -> V_194 ) ;
if ( F_79 ( V_158 -> V_159 , V_210 , V_311 ) ) {
F_107 ( V_233 , V_158 ) ;
F_34 ( V_233 -> V_238 , V_239 ,
V_345 , 1 ) ;
F_34 ( V_233 -> V_238 , V_239 ,
V_346 , 0 ) ;
return 0 ;
}
F_34 ( V_233 -> V_238 , V_239 , V_345 , 0 ) ;
if ( F_79 ( V_158 -> V_159 , V_210 , V_347 ) )
F_34 ( V_233 -> V_238 , V_239 ,
V_346 , 1 ) ;
if ( F_79 ( V_158 -> V_159 , V_210 , V_323 ) ) {
V_187 -> V_205 . V_348 = F_79 ( V_158 -> V_190 ,
V_349 , V_350 ) ;
if ( V_187 -> V_205 . V_348 )
V_2 -> V_328 . V_351 ++ ;
}
if ( F_79 ( V_158 -> V_159 , V_210 , V_352 ) ) {
F_34 ( V_233 -> V_238 , V_239 ,
V_353 , 1 ) ;
V_233 -> V_354 = F_108 ( V_158 -> V_189 ) ;
V_344 = F_79 ( V_158 -> V_159 , V_210 , V_355 ) ;
switch ( V_344 ) {
case V_356 :
case V_357 :
case V_358 :
case V_359 :
V_233 -> V_360 = V_361 ;
break;
default:
V_233 -> V_360 = V_362 ;
}
}
V_187 -> V_205 . V_363 = F_79 ( V_158 -> V_159 , V_210 , V_364 ) ;
if ( ! F_79 ( V_158 -> V_159 , V_210 , V_334 ) ) {
F_34 ( V_233 -> V_238 , V_239 ,
V_365 , 1 ) ;
return 0 ;
}
F_34 ( V_233 -> V_238 , V_239 ,
V_365 , 0 ) ;
if ( V_69 -> V_70 & V_366 )
F_34 ( V_233 -> V_238 , V_239 ,
V_367 , 1 ) ;
V_342 = F_79 ( V_158 -> V_159 , V_210 , V_368 ) ;
V_343 = F_79 ( V_158 -> V_159 , V_210 , V_369 ) ;
F_60 ( V_2 , V_370 , V_69 , L_24 , V_342 , V_343 ) ;
if ( ! V_342 || ! V_343 ) {
if ( ( V_343 == 0x09 ) &&
( V_69 -> V_70 & V_371 ) ) {
F_34 ( V_233 -> V_238 , V_239 ,
V_299 , 1 ) ;
V_233 -> V_302 = F_79 ( V_158 -> V_188 ,
V_372 ,
V_373 ) ;
F_60 ( V_2 , V_370 , V_69 , L_25 ,
V_233 -> V_302 ) ;
}
} else {
if ( ( V_343 == 0x05 ) || ( V_343 == 0x06 ) )
F_34 ( V_233 -> V_238 , V_239 ,
V_367 , 0 ) ;
else
F_34 ( V_233 -> V_374 , V_375 ,
V_376 , 1 ) ;
}
F_2 ( L_26 , V_9 -> V_341 ,
V_192 -> V_194 & ( V_192 -> V_195 - 1 ) , V_192 -> V_194 ) ;
return 0 ;
}
static int F_130 ( struct V_157 * V_158 )
{
return F_79 ( V_158 -> V_159 , V_160 , V_311 ) ;
}
static int F_131 ( struct V_157 * V_158 )
{
return F_79 ( V_158 -> V_159 , V_160 , V_334 ) ;
}
static int F_132 ( struct V_8 * V_9 ,
enum V_377 V_378 )
{
unsigned int V_91 ;
V_91 = F_49 ( V_9 , V_93 ) ;
switch ( V_378 ) {
case V_379 :
F_34 ( V_91 , V_93 , V_98 , 1 ) ;
break;
case V_380 :
F_34 ( V_91 , V_93 , V_381 , 1 ) ;
break;
case V_382 :
F_34 ( V_91 , V_93 , V_383 , 1 ) ;
break;
case V_384 :
F_34 ( V_91 , V_93 , V_100 , 1 ) ;
break;
case V_385 :
F_34 ( V_91 , V_93 , V_99 , 1 ) ;
break;
case V_386 :
F_34 ( V_91 , V_93 , V_387 , 1 ) ;
break;
case V_388 :
F_34 ( V_91 , V_93 , V_98 , 1 ) ;
F_34 ( V_91 , V_93 , V_100 , 1 ) ;
break;
case V_389 :
F_34 ( V_91 , V_93 , V_96 , 1 ) ;
break;
case V_390 :
V_91 |= V_9 -> V_391 ;
break;
default:
return - 1 ;
}
F_50 ( V_9 , V_93 , V_91 ) ;
return 0 ;
}
static int F_133 ( struct V_8 * V_9 ,
enum V_377 V_378 )
{
unsigned int V_91 ;
V_91 = F_49 ( V_9 , V_93 ) ;
switch ( V_378 ) {
case V_379 :
F_34 ( V_91 , V_93 , V_98 , 0 ) ;
break;
case V_380 :
F_34 ( V_91 , V_93 , V_381 , 0 ) ;
break;
case V_382 :
F_34 ( V_91 , V_93 , V_383 , 0 ) ;
break;
case V_384 :
F_34 ( V_91 , V_93 , V_100 , 0 ) ;
break;
case V_385 :
F_34 ( V_91 , V_93 , V_99 , 0 ) ;
break;
case V_386 :
F_34 ( V_91 , V_93 , V_387 , 0 ) ;
break;
case V_388 :
F_34 ( V_91 , V_93 , V_98 , 0 ) ;
F_34 ( V_91 , V_93 , V_100 , 0 ) ;
break;
case V_389 :
F_34 ( V_91 , V_93 , V_96 , 0 ) ;
break;
case V_390 :
V_9 -> V_391 = V_91 & V_392 ;
V_91 &= ~ V_392 ;
break;
default:
return - 1 ;
}
F_50 ( V_9 , V_93 , V_91 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
unsigned int V_393 = 2000 ;
F_2 ( L_27 ) ;
F_22 ( V_2 , V_394 , V_395 , 1 ) ;
F_27 ( 10 , 15 ) ;
while ( V_393 -- && F_25 ( V_2 , V_394 , V_395 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_393 )
return - V_48 ;
F_2 ( L_28 ) ;
return 0 ;
}
static int F_135 ( struct V_1 * V_2 )
{
unsigned int V_10 , V_393 ;
if ( F_106 ( V_2 -> V_63 . V_396 , V_397 , V_398 ) < 0x21 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_399 , 1 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ ) {
V_393 = 2000 ;
while ( V_393 -- && F_136 ( V_2 , V_10 ,
V_29 , V_399 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_393 )
return - V_48 ;
}
return 0 ;
}
static void F_137 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_400 , V_401 , 1 ) ;
F_22 ( V_2 , V_400 , UNDEF , 1 ) ;
F_22 ( V_2 , V_400 , V_402 , 1 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
unsigned int V_403 , V_404 ;
V_403 = 0 ;
F_34 ( V_403 , V_405 , V_406 , V_2 -> V_403 ) ;
F_34 ( V_403 , V_405 , V_407 , V_2 -> V_408 ) ;
F_34 ( V_403 , V_405 , V_409 , V_2 -> V_403 ) ;
F_34 ( V_403 , V_405 , V_410 , V_2 -> V_408 ) ;
F_34 ( V_403 , V_405 , V_411 , V_2 -> V_403 ) ;
F_34 ( V_403 , V_405 , V_412 , V_2 -> V_408 ) ;
F_26 ( V_2 , V_405 , V_403 ) ;
V_404 = 0 ;
F_34 ( V_404 , V_413 , V_414 , V_2 -> V_404 ) ;
F_34 ( V_404 , V_413 , V_415 , V_2 -> V_408 ) ;
F_34 ( V_404 , V_413 , V_416 , V_2 -> V_404 ) ;
F_34 ( V_404 , V_413 , V_417 , V_2 -> V_408 ) ;
F_34 ( V_404 , V_413 , V_418 , V_2 -> V_404 ) ;
F_34 ( V_404 , V_413 , V_419 , V_2 -> V_408 ) ;
F_34 ( V_404 , V_413 , V_420 , V_2 -> V_404 ) ;
F_34 ( V_404 , V_413 , V_421 , V_2 -> V_408 ) ;
F_26 ( V_2 , V_413 , V_404 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
F_22 ( V_2 , V_259 , V_260 , V_422 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_263 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_266 , V_235 ,
V_270 ) ;
F_13 ( V_2 , V_10 , V_271 , V_272 , 1 ) ;
}
F_22 ( V_2 , V_259 , V_423 , V_424 ) ;
}
static unsigned int F_140 ( unsigned int V_425 ,
unsigned int V_426 )
{
unsigned int V_427 = 0 ;
enum V_428 V_429 = V_430 ;
switch ( V_425 ) {
case 0 :
V_427 = F_141 ( 128 ) ;
break;
case 1 :
V_427 = F_141 ( 256 ) ;
break;
case 2 :
V_427 = F_141 ( 512 ) ;
break;
case 3 :
V_427 = F_142 ( 1 ) ;
break;
case 4 :
V_427 = F_142 ( 2 ) ;
break;
case 5 :
V_427 = F_142 ( 4 ) ;
break;
case 6 :
V_427 = F_142 ( 8 ) ;
break;
case 7 :
V_427 = F_142 ( 16 ) ;
break;
case 8 :
V_427 = F_142 ( 32 ) ;
break;
case 9 :
V_427 = F_142 ( 64 ) ;
break;
case 10 :
V_427 = F_142 ( 128 ) ;
break;
case 11 :
V_427 = F_142 ( 256 ) ;
break;
}
V_427 = F_40 (unsigned int, XGBE_FIFO_MAX, q_fifo_size) ;
V_427 = V_427 / V_426 ;
if ( V_427 >= F_142 ( 256 ) )
V_429 = V_431 ;
else if ( V_427 >= F_142 ( 128 ) )
V_429 = V_432 ;
else if ( V_427 >= F_142 ( 64 ) )
V_429 = V_433 ;
else if ( V_427 >= F_142 ( 32 ) )
V_429 = V_434 ;
else if ( V_427 >= F_142 ( 16 ) )
V_429 = V_435 ;
else if ( V_427 >= F_142 ( 8 ) )
V_429 = V_436 ;
else if ( V_427 >= F_142 ( 4 ) )
V_429 = V_437 ;
else if ( V_427 >= F_142 ( 2 ) )
V_429 = V_438 ;
else if ( V_427 >= F_142 ( 1 ) )
V_429 = V_439 ;
else if ( V_427 >= F_141 ( 512 ) )
V_429 = V_440 ;
else if ( V_427 >= F_141 ( 256 ) )
V_429 = V_430 ;
return V_429 ;
}
static void F_143 ( struct V_1 * V_2 )
{
enum V_428 V_425 ;
unsigned int V_10 ;
V_425 = F_140 ( V_2 -> V_63 . V_441 ,
V_2 -> V_28 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_442 , V_425 ) ;
F_144 ( V_2 , V_117 , V_2 -> V_69 ,
L_29 ,
V_2 -> V_28 , ( ( V_425 + 1 ) * 256 ) ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
enum V_428 V_425 ;
unsigned int V_10 ;
V_425 = F_140 ( V_2 -> V_63 . V_443 ,
V_2 -> V_25 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_444 , V_425 ) ;
F_144 ( V_2 , V_117 , V_2 -> V_69 ,
L_30 ,
V_2 -> V_25 , ( ( V_425 + 1 ) * 256 ) ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
unsigned int V_445 , V_446 , V_447 ;
unsigned int V_448 ;
unsigned int V_449 , V_450 , V_275 ;
unsigned int V_273 ;
unsigned int V_10 , V_451 , V_74 , V_75 ;
V_445 = V_2 -> V_28 / V_2 -> V_63 . V_263 ;
V_446 = V_2 -> V_28 % V_2 -> V_63 . V_263 ;
for ( V_10 = 0 , V_447 = 0 ; V_10 < V_2 -> V_63 . V_263 ; V_10 ++ ) {
for ( V_451 = 0 ; V_451 < V_445 ; V_451 ++ ) {
F_60 ( V_2 , V_117 , V_2 -> V_69 ,
L_31 , V_447 , V_10 ) ;
F_13 ( V_2 , V_447 , V_29 ,
V_452 , V_10 ) ;
V_2 -> V_453 [ V_447 ++ ] = V_10 ;
}
if ( V_10 < V_446 ) {
F_60 ( V_2 , V_117 , V_2 -> V_69 ,
L_31 , V_447 , V_10 ) ;
F_13 ( V_2 , V_447 , V_29 ,
V_452 , V_10 ) ;
V_2 -> V_453 [ V_447 ++ ] = V_10 ;
}
}
V_448 = F_40 (unsigned int, IEEE_8021QAZ_MAX_TCS,
pdata->rx_q_count) ;
V_449 = V_276 / V_448 ;
V_450 = V_276 % V_448 ;
V_74 = V_454 ;
V_75 = 0 ;
for ( V_10 = 0 , V_275 = 0 ; V_10 < V_448 ; ) {
V_273 = 0 ;
for ( V_451 = 0 ; V_451 < V_449 ; V_451 ++ ) {
F_60 ( V_2 , V_117 , V_2 -> V_69 ,
L_32 , V_275 , V_10 ) ;
V_273 |= ( 1 << V_275 ) ;
V_2 -> V_455 [ V_275 ++ ] = V_10 ;
}
if ( V_10 < V_450 ) {
F_60 ( V_2 , V_117 , V_2 -> V_69 ,
L_32 , V_275 , V_10 ) ;
V_273 |= ( 1 << V_275 ) ;
V_2 -> V_455 [ V_275 ++ ] = V_10 ;
}
V_75 |= ( V_273 << ( ( V_10 ++ % V_456 ) << 3 ) ) ;
if ( ( V_10 % V_456 ) && ( V_10 != V_448 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_457 ;
V_75 = 0 ;
}
V_74 = V_458 ;
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; ) {
V_75 |= ( 0x80 << ( ( V_10 ++ % V_459 ) << 3 ) ) ;
if ( ( V_10 % V_459 ) && ( V_10 != V_2 -> V_25 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_460 ;
V_75 = 0 ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_461 , V_462 , 2 ) ;
F_13 ( V_2 , V_10 , V_461 , V_463 , 4 ) ;
}
}
static void F_148 ( struct V_1 * V_2 )
{
F_72 ( V_2 , V_2 -> V_69 -> V_464 ) ;
if ( V_2 -> V_63 . V_138 ) {
F_22 ( V_2 , V_115 , V_465 , 1 ) ;
F_22 ( V_2 , V_115 , V_466 , 1 ) ;
F_22 ( V_2 , V_115 , V_467 , 1 ) ;
}
}
static void F_149 ( struct V_1 * V_2 )
{
unsigned int V_24 ;
V_24 = ( V_2 -> V_69 -> V_262 > V_468 ) ? 1 : 0 ;
F_22 ( V_2 , V_40 , V_469 , V_24 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_470 ) {
case V_471 :
F_58 ( V_2 ) ;
break;
case V_472 :
F_57 ( V_2 ) ;
break;
case V_473 :
F_56 ( V_2 ) ;
break;
}
}
static void F_151 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 -> V_70 & V_366 )
F_81 ( V_2 ) ;
else
F_80 ( V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_474 , V_475 , 0 ) ;
F_22 ( V_2 , V_474 , V_476 , 1 ) ;
F_88 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_477 )
F_84 ( V_2 ) ;
else
F_85 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_371 )
F_82 ( V_2 ) ;
else
F_83 ( V_2 ) ;
}
static T_5 F_153 ( struct V_1 * V_2 , unsigned int V_478 )
{
bool V_479 ;
T_5 V_24 ;
switch ( V_478 ) {
case V_480 :
case V_481 :
case V_482 :
case V_483 :
V_479 = true ;
break;
default:
V_479 = false ;
} ;
V_24 = F_41 ( V_2 , V_478 ) ;
if ( V_479 )
V_24 |= ( ( T_5 ) F_41 ( V_2 , V_478 + 4 ) << 32 ) ;
return V_24 ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_484 * V_485 = & V_2 -> V_486 ;
unsigned int V_487 = F_41 ( V_2 , V_488 ) ;
if ( F_106 ( V_487 , V_488 , V_489 ) )
V_485 -> V_490 +=
F_153 ( V_2 , V_480 ) ;
if ( F_106 ( V_487 , V_488 , V_491 ) )
V_485 -> V_492 +=
F_153 ( V_2 , V_493 ) ;
if ( F_106 ( V_487 , V_488 , V_494 ) )
V_485 -> V_495 +=
F_153 ( V_2 , V_496 ) ;
if ( F_106 ( V_487 , V_488 , V_497 ) )
V_485 -> V_498 +=
F_153 ( V_2 , V_499 ) ;
if ( F_106 ( V_487 , V_488 , V_500 ) )
V_485 -> V_501 +=
F_153 ( V_2 , V_502 ) ;
if ( F_106 ( V_487 , V_488 , V_503 ) )
V_485 -> V_504 +=
F_153 ( V_2 , V_505 ) ;
if ( F_106 ( V_487 , V_488 , V_506 ) )
V_485 -> V_507 +=
F_153 ( V_2 , V_508 ) ;
if ( F_106 ( V_487 , V_488 , V_509 ) )
V_485 -> V_510 +=
F_153 ( V_2 , V_511 ) ;
if ( F_106 ( V_487 , V_488 , V_512 ) )
V_485 -> V_513 +=
F_153 ( V_2 , V_514 ) ;
if ( F_106 ( V_487 , V_488 , V_515 ) )
V_485 -> V_516 +=
F_153 ( V_2 , V_517 ) ;
if ( F_106 ( V_487 , V_488 , V_518 ) )
V_485 -> V_519 +=
F_153 ( V_2 , V_520 ) ;
if ( F_106 ( V_487 , V_488 , V_521 ) )
V_485 -> V_522 +=
F_153 ( V_2 , V_523 ) ;
if ( F_106 ( V_487 , V_488 , V_524 ) )
V_485 -> V_495 +=
F_153 ( V_2 , V_525 ) ;
if ( F_106 ( V_487 , V_488 , V_526 ) )
V_485 -> V_527 +=
F_153 ( V_2 , V_528 ) ;
if ( F_106 ( V_487 , V_488 , V_529 ) )
V_485 -> V_530 +=
F_153 ( V_2 , V_481 ) ;
if ( F_106 ( V_487 , V_488 , V_531 ) )
V_485 -> V_532 +=
F_153 ( V_2 , V_533 ) ;
if ( F_106 ( V_487 , V_488 , V_534 ) )
V_485 -> V_535 +=
F_153 ( V_2 , V_536 ) ;
if ( F_106 ( V_487 , V_488 , V_537 ) )
V_485 -> V_538 +=
F_153 ( V_2 , V_539 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_484 * V_485 = & V_2 -> V_486 ;
unsigned int V_487 = F_41 ( V_2 , V_540 ) ;
if ( F_106 ( V_487 , V_540 , V_541 ) )
V_485 -> V_542 +=
F_153 ( V_2 , V_543 ) ;
if ( F_106 ( V_487 , V_540 , V_544 ) )
V_485 -> V_545 +=
F_153 ( V_2 , V_482 ) ;
if ( F_106 ( V_487 , V_540 , V_546 ) )
V_485 -> V_547 +=
F_153 ( V_2 , V_483 ) ;
if ( F_106 ( V_487 , V_540 , V_548 ) )
V_485 -> V_549 +=
F_153 ( V_2 , V_550 ) ;
if ( F_106 ( V_487 , V_540 , V_551 ) )
V_485 -> V_552 +=
F_153 ( V_2 , V_553 ) ;
if ( F_106 ( V_487 , V_540 , V_554 ) )
V_485 -> V_555 +=
F_153 ( V_2 , V_556 ) ;
if ( F_106 ( V_487 , V_540 , V_557 ) )
V_485 -> V_558 +=
F_153 ( V_2 , V_559 ) ;
if ( F_106 ( V_487 , V_540 , V_560 ) )
V_485 -> V_561 +=
F_153 ( V_2 , V_562 ) ;
if ( F_106 ( V_487 , V_540 , V_563 ) )
V_485 -> V_564 +=
F_153 ( V_2 , V_565 ) ;
if ( F_106 ( V_487 , V_540 , V_566 ) )
V_485 -> V_567 +=
F_153 ( V_2 , V_568 ) ;
if ( F_106 ( V_487 , V_540 , V_569 ) )
V_485 -> V_570 +=
F_153 ( V_2 , V_571 ) ;
if ( F_106 ( V_487 , V_540 , V_572 ) )
V_485 -> V_573 +=
F_153 ( V_2 , V_574 ) ;
if ( F_106 ( V_487 , V_540 , V_575 ) )
V_485 -> V_576 +=
F_153 ( V_2 , V_577 ) ;
if ( F_106 ( V_487 , V_540 , V_578 ) )
V_485 -> V_579 +=
F_153 ( V_2 , V_580 ) ;
if ( F_106 ( V_487 , V_540 , V_581 ) )
V_485 -> V_582 +=
F_153 ( V_2 , V_583 ) ;
if ( F_106 ( V_487 , V_540 , V_584 ) )
V_485 -> V_585 +=
F_153 ( V_2 , V_586 ) ;
if ( F_106 ( V_487 , V_540 , V_587 ) )
V_485 -> V_588 +=
F_153 ( V_2 , V_589 ) ;
if ( F_106 ( V_487 , V_540 , V_590 ) )
V_485 -> V_591 +=
F_153 ( V_2 , V_592 ) ;
if ( F_106 ( V_487 , V_540 , V_593 ) )
V_485 -> V_594 +=
F_153 ( V_2 , V_595 ) ;
if ( F_106 ( V_487 , V_540 , V_596 ) )
V_485 -> V_597 +=
F_153 ( V_2 , V_598 ) ;
if ( F_106 ( V_487 , V_540 , V_599 ) )
V_485 -> V_600 +=
F_153 ( V_2 , V_601 ) ;
if ( F_106 ( V_487 , V_540 , V_602 ) )
V_485 -> V_603 +=
F_153 ( V_2 , V_604 ) ;
if ( F_106 ( V_487 , V_540 , V_605 ) )
V_485 -> V_606 +=
F_153 ( V_2 , V_607 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_484 * V_485 = & V_2 -> V_486 ;
F_22 ( V_2 , V_608 , V_609 , 1 ) ;
V_485 -> V_490 +=
F_153 ( V_2 , V_480 ) ;
V_485 -> V_492 +=
F_153 ( V_2 , V_493 ) ;
V_485 -> V_495 +=
F_153 ( V_2 , V_496 ) ;
V_485 -> V_498 +=
F_153 ( V_2 , V_499 ) ;
V_485 -> V_501 +=
F_153 ( V_2 , V_502 ) ;
V_485 -> V_504 +=
F_153 ( V_2 , V_505 ) ;
V_485 -> V_507 +=
F_153 ( V_2 , V_508 ) ;
V_485 -> V_510 +=
F_153 ( V_2 , V_511 ) ;
V_485 -> V_513 +=
F_153 ( V_2 , V_514 ) ;
V_485 -> V_516 +=
F_153 ( V_2 , V_517 ) ;
V_485 -> V_519 +=
F_153 ( V_2 , V_520 ) ;
V_485 -> V_522 +=
F_153 ( V_2 , V_523 ) ;
V_485 -> V_495 +=
F_153 ( V_2 , V_525 ) ;
V_485 -> V_527 +=
F_153 ( V_2 , V_528 ) ;
V_485 -> V_530 +=
F_153 ( V_2 , V_481 ) ;
V_485 -> V_532 +=
F_153 ( V_2 , V_533 ) ;
V_485 -> V_535 +=
F_153 ( V_2 , V_536 ) ;
V_485 -> V_538 +=
F_153 ( V_2 , V_539 ) ;
V_485 -> V_542 +=
F_153 ( V_2 , V_543 ) ;
V_485 -> V_545 +=
F_153 ( V_2 , V_482 ) ;
V_485 -> V_547 +=
F_153 ( V_2 , V_483 ) ;
V_485 -> V_549 +=
F_153 ( V_2 , V_550 ) ;
V_485 -> V_552 +=
F_153 ( V_2 , V_553 ) ;
V_485 -> V_555 +=
F_153 ( V_2 , V_556 ) ;
V_485 -> V_558 +=
F_153 ( V_2 , V_559 ) ;
V_485 -> V_561 +=
F_153 ( V_2 , V_562 ) ;
V_485 -> V_564 +=
F_153 ( V_2 , V_565 ) ;
V_485 -> V_567 +=
F_153 ( V_2 , V_568 ) ;
V_485 -> V_570 +=
F_153 ( V_2 , V_571 ) ;
V_485 -> V_573 +=
F_153 ( V_2 , V_574 ) ;
V_485 -> V_576 +=
F_153 ( V_2 , V_577 ) ;
V_485 -> V_579 +=
F_153 ( V_2 , V_580 ) ;
V_485 -> V_582 +=
F_153 ( V_2 , V_583 ) ;
V_485 -> V_585 +=
F_153 ( V_2 , V_586 ) ;
V_485 -> V_588 +=
F_153 ( V_2 , V_589 ) ;
V_485 -> V_591 +=
F_153 ( V_2 , V_592 ) ;
V_485 -> V_594 +=
F_153 ( V_2 , V_595 ) ;
V_485 -> V_597 +=
F_153 ( V_2 , V_598 ) ;
V_485 -> V_600 +=
F_153 ( V_2 , V_601 ) ;
V_485 -> V_603 +=
F_153 ( V_2 , V_604 ) ;
V_485 -> V_606 +=
F_153 ( V_2 , V_607 ) ;
F_22 ( V_2 , V_608 , V_609 , 0 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_608 , V_610 , 1 ) ;
F_22 ( V_2 , V_608 , V_611 , 1 ) ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned int V_612 , V_613 , V_614 ;
unsigned int V_615 ;
unsigned long V_616 ;
if ( V_9 -> V_340 < V_617 ) {
V_612 = V_618 ;
V_613 = ( V_9 -> V_340 * V_619 ) +
V_620 ;
} else {
V_614 = V_9 -> V_340 - V_617 ;
V_612 = V_621 + ( ( V_614 / V_622 ) * V_623 ) ;
V_613 = ( ( V_614 % V_622 ) * V_619 ) +
V_624 ;
}
V_616 = V_285 + ( V_625 * V_626 ) ;
while ( F_159 ( V_285 , V_616 ) ) {
V_615 = F_41 ( V_2 , V_612 ) ;
V_615 = F_160 ( V_615 , V_613 , V_627 ) ;
if ( ( V_615 == V_628 ) ||
( V_615 == V_629 ) )
break;
F_27 ( 500 , 1000 ) ;
}
if ( ! F_159 ( V_285 , V_616 ) )
F_161 ( V_2 -> V_69 ,
L_33 ,
V_9 -> V_340 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_630 , 1 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_631 ,
V_632 ) ;
F_22 ( V_2 , V_112 , V_633 , 1 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_158 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_112 , V_633 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_631 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_630 , 0 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_75 , V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_634 , 1 ) ;
}
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
V_75 |= ( 0x02 << ( V_10 << 1 ) ) ;
F_26 ( V_2 , V_635 , V_75 ) ;
F_22 ( V_2 , V_40 , V_636 , 1 ) ;
F_22 ( V_2 , V_40 , V_637 , 1 ) ;
F_22 ( V_2 , V_40 , V_638 , 1 ) ;
F_22 ( V_2 , V_40 , V_639 , 1 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
F_22 ( V_2 , V_40 , V_636 , 0 ) ;
F_22 ( V_2 , V_40 , V_637 , 0 ) ;
F_22 ( V_2 , V_40 , V_638 , 0 ) ;
F_22 ( V_2 , V_40 , V_639 , 0 ) ;
F_26 ( V_2 , V_635 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_634 , 0 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_630 , 1 ) ;
}
F_22 ( V_2 , V_112 , V_633 , 1 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_158 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_112 , V_633 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_630 , 0 ) ;
}
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_634 , 1 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_634 , 0 ) ;
}
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_640 * V_641 = & V_2 -> V_641 ;
int V_5 ;
F_2 ( L_34 ) ;
V_5 = F_135 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_137 ( V_2 ) ;
F_138 ( V_2 ) ;
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
V_641 -> V_642 ( V_2 ) ;
V_641 -> V_643 ( V_2 ) ;
F_48 ( V_2 ) ;
F_139 ( V_2 ) ;
F_146 ( V_2 ) ;
F_14 ( V_2 , V_2 -> V_644 ) ;
F_12 ( V_2 , V_2 -> V_645 ) ;
F_16 ( V_2 , V_2 -> V_646 ) ;
F_15 ( V_2 , V_2 -> V_647 ) ;
F_143 ( V_2 ) ;
F_145 ( V_2 ) ;
F_147 ( V_2 ) ;
F_113 ( V_2 ) ;
F_115 ( V_2 ) ;
F_51 ( V_2 ) ;
F_148 ( V_2 ) ;
F_73 ( V_2 ) ;
F_149 ( V_2 ) ;
F_47 ( V_2 ) ;
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
F_157 ( V_2 ) ;
F_55 ( V_2 ) ;
F_2 ( L_35 ) ;
return 0 ;
}
void F_171 ( struct V_648 * V_649 )
{
F_2 ( L_36 ) ;
V_649 -> V_650 = F_78 ;
V_649 -> V_651 = F_72 ;
V_649 -> V_652 = F_73 ;
V_649 -> V_653 = F_81 ;
V_649 -> V_654 = F_80 ;
V_649 -> V_655 = F_82 ;
V_649 -> V_656 = F_83 ;
V_649 -> V_657 = F_84 ;
V_649 -> V_658 = F_85 ;
V_649 -> V_659 = F_88 ;
V_649 -> V_660 = F_74 ;
V_649 -> V_661 = F_77 ;
V_649 -> V_662 = F_56 ;
V_649 -> V_663 = F_57 ;
V_649 -> V_664 = F_58 ;
V_649 -> V_665 = F_162 ;
V_649 -> V_666 = F_163 ;
V_649 -> V_667 = F_164 ;
V_649 -> V_668 = F_165 ;
V_649 -> V_669 = F_166 ;
V_649 -> V_670 = F_167 ;
V_649 -> V_671 = F_168 ;
V_649 -> V_672 = F_169 ;
V_649 -> V_673 = F_120 ;
V_649 -> V_674 = F_126 ;
V_649 -> V_675 = F_132 ;
V_649 -> V_676 = F_133 ;
V_649 -> V_677 = F_170 ;
V_649 -> exit = F_134 ;
V_649 -> V_678 = F_93 ;
V_649 -> V_679 = F_100 ;
V_649 -> V_680 = F_91 ;
V_649 -> V_681 = F_97 ;
V_649 -> V_682 = F_131 ;
V_649 -> V_683 = F_130 ;
V_649 -> V_684 = F_116 ;
V_649 -> V_685 = F_45 ;
V_649 -> V_686 = F_46 ;
V_649 -> V_687 = F_17 ;
V_649 -> V_688 = F_18 ;
V_649 -> V_689 = F_1 ;
V_649 -> V_690 = F_3 ;
V_649 -> V_691 = F_15 ;
V_649 -> V_692 = F_16 ;
V_649 -> V_693 = F_12 ;
V_649 -> V_694 = F_14 ;
V_649 -> V_695 = F_11 ;
V_649 -> V_696 = F_10 ;
V_649 -> V_697 = F_9 ;
V_649 -> V_698 = F_8 ;
V_649 -> V_699 = F_6 ;
V_649 -> V_700 = F_4 ;
V_649 -> V_701 = F_154 ;
V_649 -> V_702 = F_155 ;
V_649 -> V_703 = F_156 ;
V_649 -> V_704 = F_109 ;
V_649 -> V_705 = F_101 ;
V_649 -> V_706 = F_103 ;
V_649 -> V_707 = F_104 ;
V_649 -> V_708 = F_105 ;
V_649 -> V_709 = F_113 ;
V_649 -> V_710 = F_115 ;
V_649 -> V_711 = F_35 ;
V_649 -> V_712 = F_36 ;
V_649 -> V_713 = F_32 ;
V_649 -> V_714 = F_33 ;
F_2 ( L_37 ) ;
}
