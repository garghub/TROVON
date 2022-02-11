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
F_2 ( L_6 , V_114 ? L_7 : L_8 ) ;
F_22 ( V_2 , V_115 , V_116 , V_24 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
unsigned int V_114 )
{
unsigned int V_24 = V_114 ? 1 : 0 ;
if ( F_25 ( V_2 , V_115 , V_117 ) == V_24 )
return 0 ;
F_2 ( L_9 , V_114 ? L_7 : L_8 ) ;
F_22 ( V_2 , V_115 , V_117 , V_24 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_118 * V_119 , unsigned int * V_120 )
{
unsigned int V_121 , V_122 ;
T_1 * V_123 ;
V_122 = 0 ;
V_121 = 0 ;
if ( V_119 ) {
V_123 = ( T_1 * ) & V_122 ;
V_123 [ 0 ] = V_119 -> V_124 [ 0 ] ;
V_123 [ 1 ] = V_119 -> V_124 [ 1 ] ;
V_123 [ 2 ] = V_119 -> V_124 [ 2 ] ;
V_123 [ 3 ] = V_119 -> V_124 [ 3 ] ;
V_123 = ( T_1 * ) & V_121 ;
V_123 [ 0 ] = V_119 -> V_124 [ 4 ] ;
V_123 [ 1 ] = V_119 -> V_124 [ 5 ] ;
F_2 ( L_10 , V_119 -> V_124 ,
* V_120 ) ;
F_34 ( V_121 , V_125 , V_126 , 1 ) ;
}
F_26 ( V_2 , * V_120 , V_121 ) ;
* V_120 += V_127 ;
F_26 ( V_2 , * V_120 , V_122 ) ;
* V_120 += V_127 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_128 * V_69 = V_2 -> V_69 ;
struct V_118 * V_119 ;
unsigned int V_120 ;
unsigned int V_129 ;
V_120 = V_125 ;
V_129 = V_2 -> V_63 . V_130 ;
if ( F_63 ( V_69 ) > V_129 ) {
F_59 ( V_2 , 1 ) ;
} else {
F_64 (ha, netdev) {
F_61 ( V_2 , V_119 , & V_120 ) ;
V_129 -- ;
}
if ( F_65 ( V_69 ) > V_129 ) {
F_60 ( V_2 , 1 ) ;
} else {
F_66 (ha, netdev) {
F_61 ( V_2 , V_119 , & V_120 ) ;
V_129 -- ;
}
}
}
while ( V_129 -- )
F_61 ( V_2 , NULL , & V_120 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_128 * V_69 = V_2 -> V_69 ;
struct V_118 * V_119 ;
unsigned int V_131 ;
unsigned int V_132 , V_133 ;
V_56 V_134 [ V_135 ] ;
V_56 V_136 ;
unsigned int V_10 ;
V_132 = 26 - ( V_2 -> V_63 . V_137 >> 7 ) ;
V_133 = V_2 -> V_63 . V_137 / 32 ;
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
F_64 (ha, netdev) {
V_136 = F_68 ( ~ F_69 ( ~ 0 , V_119 -> V_124 , V_138 ) ) ;
V_136 >>= V_132 ;
V_134 [ V_136 >> 5 ] |= ( 1 << ( V_136 & 0x1f ) ) ;
}
F_66 (ha, netdev) {
V_136 = F_68 ( ~ F_69 ( ~ 0 , V_119 -> V_124 , V_138 ) ) ;
V_136 >>= V_132 ;
V_134 [ V_136 >> 5 ] |= ( 1 << ( V_136 & 0x1f ) ) ;
}
V_131 = V_139 ;
for ( V_10 = 0 ; V_10 < V_133 ; V_10 ++ ) {
F_26 ( V_2 , V_131 , V_134 [ V_10 ] ) ;
V_131 += V_140 ;
}
}
static int F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 . V_137 )
F_67 ( V_2 ) ;
else
F_62 ( V_2 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , T_1 * V_124 )
{
unsigned int V_121 , V_122 ;
V_121 = ( V_124 [ 5 ] << 8 ) | ( V_124 [ 4 ] << 0 ) ;
V_122 = ( V_124 [ 3 ] << 24 ) | ( V_124 [ 2 ] << 16 ) |
( V_124 [ 1 ] << 8 ) | ( V_124 [ 0 ] << 0 ) ;
F_26 ( V_2 , V_141 , V_121 ) ;
F_26 ( V_2 , V_142 , V_122 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , int V_143 ,
int V_144 )
{
unsigned int V_145 ;
int V_146 ;
if ( V_144 & V_147 )
V_145 = V_144 & ~ V_147 ;
else
V_145 = ( V_2 -> V_148 << 16 ) | ( V_144 & 0xffff ) ;
F_24 ( & V_2 -> V_149 ) ;
F_73 ( V_2 , V_150 << 2 , V_145 >> 8 ) ;
V_146 = F_74 ( V_2 , ( V_145 & 0xff ) << 2 ) ;
F_28 ( & V_2 -> V_149 ) ;
return V_146 ;
}
static void F_75 ( struct V_1 * V_2 , int V_143 ,
int V_144 , int V_146 )
{
unsigned int V_145 ;
if ( V_144 & V_147 )
V_145 = V_144 & ~ V_147 ;
else
V_145 = ( V_2 -> V_148 << 16 ) | ( V_144 & 0xffff ) ;
if ( ( ( V_145 >> 16 ) == V_151 ) &&
( ( V_145 & 0xffff ) == V_152 ) ) {
struct V_153 * V_154 = V_2 -> V_154 ;
if ( V_146 & V_155 ) {
if ( V_154 -> V_156 & V_157 )
F_56 ( V_2 ) ;
else
F_57 ( V_2 ) ;
} else {
F_58 ( V_2 ) ;
}
}
F_24 ( & V_2 -> V_149 ) ;
F_73 ( V_2 , V_150 << 2 , V_145 >> 8 ) ;
F_73 ( V_2 , ( V_145 & 0xff ) << 2 , V_146 ) ;
F_28 ( & V_2 -> V_149 ) ;
}
static int F_76 ( struct V_158 * V_159 )
{
return ! F_77 ( V_159 -> V_160 , V_161 , V_162 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_163 , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_163 , 1 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_164 , V_165 , 1 ) ;
F_22 ( V_2 , V_164 , V_166 , 1 ) ;
F_22 ( V_2 , V_164 , V_167 , 0 ) ;
F_22 ( V_2 , V_164 , V_168 , 0 ) ;
F_22 ( V_2 , V_164 , V_169 , 0x3 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_164 , V_169 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_115 , V_170 , 1 ) ;
F_22 ( V_2 , V_164 , V_171 , 1 ) ;
F_22 ( V_2 , V_164 , V_172 , 0 ) ;
F_22 ( V_2 , V_164 , V_173 , 1 ) ;
F_22 ( V_2 , V_164 , V_174 , 1 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_115 , V_170 , 0 ) ;
return 0 ;
}
static V_56 F_84 ( T_2 V_175 )
{
V_56 V_176 = V_177 ;
V_56 V_136 = ~ 0 ;
V_56 V_178 = 0 ;
unsigned char * V_179 = ( unsigned char * ) & V_175 ;
unsigned char V_180 = 0 ;
int V_10 , V_181 ;
V_181 = F_85 ( V_182 ) ;
for ( V_10 = 0 ; V_10 < V_181 ; V_10 ++ ) {
if ( ( V_10 % 8 ) == 0 )
V_180 = V_179 [ V_10 / 8 ] ;
V_178 = ( ( V_136 & 1 ) ^ V_180 ) & 1 ;
V_136 >>= 1 ;
V_180 >>= 1 ;
if ( V_178 )
V_136 ^= V_176 ;
}
return V_136 ;
}
static int F_86 ( struct V_1 * V_2 )
{
V_56 V_136 ;
T_3 V_183 ;
T_2 V_175 ;
T_3 V_184 = 0 ;
F_87 (vid, pdata->active_vlans, VLAN_N_VID) {
V_175 = F_88 ( V_183 ) ;
V_136 = F_68 ( ~ F_84 ( V_175 ) ) >> 28 ;
V_184 |= ( 1 << V_136 ) ;
}
F_22 ( V_2 , V_185 , V_186 , V_184 ) ;
return 0 ;
}
static void F_89 ( struct V_187 * V_188 )
{
struct V_158 * V_159 = V_188 -> V_159 ;
V_159 -> V_189 = 0 ;
V_159 -> V_190 = 0 ;
V_159 -> V_191 = 0 ;
V_159 -> V_160 = 0 ;
F_90 () ;
}
static void F_91 ( struct V_8 * V_9 )
{
struct V_192 * V_193 = V_9 -> V_17 ;
struct V_187 * V_188 ;
int V_10 ;
int V_194 = V_193 -> V_195 ;
F_2 ( L_11 ) ;
for ( V_10 = 0 ; V_10 < V_193 -> V_196 ; V_10 ++ ) {
V_188 = F_92 ( V_193 , V_10 ) ;
F_89 ( V_188 ) ;
}
F_50 ( V_9 , V_197 , V_193 -> V_196 - 1 ) ;
V_188 = F_92 ( V_193 , V_194 ) ;
F_50 ( V_9 , V_198 ,
F_93 ( V_188 -> V_199 ) ) ;
F_50 ( V_9 , V_200 ,
F_94 ( V_188 -> V_199 ) ) ;
F_2 ( L_12 ) ;
}
static void F_95 ( struct V_187 * V_188 )
{
struct V_158 * V_159 = V_188 -> V_159 ;
V_159 -> V_189 = F_96 ( F_94 ( V_188 -> V_201 . V_202 . V_203 ) ) ;
V_159 -> V_190 = F_96 ( F_93 ( V_188 -> V_201 . V_202 . V_203 ) ) ;
V_159 -> V_191 = F_96 ( F_94 ( V_188 -> V_201 . V_204 . V_203 ) ) ;
V_159 -> V_160 = F_96 ( F_93 ( V_188 -> V_201 . V_204 . V_203 ) ) ;
F_97 ( V_159 -> V_160 , V_205 , V_206 ,
V_188 -> V_207 ? 1 : 0 ) ;
F_90 () ;
F_97 ( V_159 -> V_160 , V_205 , V_162 , 1 ) ;
F_90 () ;
}
static void F_98 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_192 * V_193 = V_9 -> V_20 ;
struct V_187 * V_188 ;
unsigned int V_194 = V_193 -> V_195 ;
unsigned int V_208 , V_209 ;
unsigned int V_10 ;
F_2 ( L_13 ) ;
V_208 = ( V_2 -> V_35 || V_2 -> V_209 ) ? 1 : 0 ;
V_209 = V_2 -> V_209 ;
for ( V_10 = 0 ; V_10 < V_193 -> V_196 ; V_10 ++ ) {
V_188 = F_92 ( V_193 , V_10 ) ;
if ( V_208 && ( ! V_209 || ( ( V_10 + 1 ) % V_209 ) ) )
V_188 -> V_207 = 0 ;
else
V_188 -> V_207 = 1 ;
F_95 ( V_188 ) ;
}
F_50 ( V_9 , V_210 , V_193 -> V_196 - 1 ) ;
V_188 = F_92 ( V_193 , V_194 ) ;
F_50 ( V_9 , V_211 ,
F_93 ( V_188 -> V_199 ) ) ;
F_50 ( V_9 , V_212 ,
F_94 ( V_188 -> V_199 ) ) ;
V_188 = F_92 ( V_193 , V_194 + V_193 -> V_196 - 1 ) ;
F_50 ( V_9 , V_213 ,
F_94 ( V_188 -> V_199 ) ) ;
F_2 ( L_14 ) ;
}
static void F_99 ( struct V_1 * V_2 ,
unsigned int V_214 )
{
F_26 ( V_2 , V_215 , V_214 ) ;
F_22 ( V_2 , V_216 , V_217 , 1 ) ;
while ( F_25 ( V_2 , V_216 , V_217 ) )
F_100 ( 5 ) ;
}
static void F_101 ( struct V_1 * V_2 , unsigned int V_218 ,
unsigned int V_219 )
{
F_26 ( V_2 , V_220 , V_218 ) ;
F_26 ( V_2 , V_221 , V_219 ) ;
F_22 ( V_2 , V_216 , V_222 , 1 ) ;
while ( F_25 ( V_2 , V_216 , V_222 ) )
F_100 ( 5 ) ;
}
static T_4 F_102 ( struct V_1 * V_2 )
{
T_4 V_219 ;
V_219 = F_41 ( V_2 , V_223 ) ;
V_219 *= V_224 ;
V_219 += F_41 ( V_2 , V_225 ) ;
return V_219 ;
}
static T_4 F_103 ( struct V_1 * V_2 )
{
unsigned int V_226 ;
T_4 V_219 ;
V_226 = F_41 ( V_2 , V_227 ) ;
if ( F_104 ( V_226 , V_227 , V_228 ) )
return 0 ;
V_219 = F_41 ( V_2 , V_229 ) ;
V_219 *= V_224 ;
V_219 += V_226 ;
return V_219 ;
}
static void F_105 ( struct V_230 * V_231 ,
struct V_158 * V_159 )
{
T_4 V_219 ;
if ( F_77 ( V_159 -> V_160 , V_232 , V_233 ) &&
! F_77 ( V_159 -> V_160 , V_232 , V_234 ) ) {
V_219 = F_106 ( V_159 -> V_190 ) ;
V_219 <<= 32 ;
V_219 |= F_106 ( V_159 -> V_189 ) ;
if ( V_219 != 0xffffffffffffffffULL ) {
V_231 -> V_235 = V_219 ;
F_34 ( V_231 -> V_236 , V_237 ,
V_238 , 1 ) ;
}
}
}
static int F_107 ( struct V_1 * V_2 ,
unsigned int V_239 )
{
F_34 ( V_239 , V_216 , V_240 , 1 ) ;
F_34 ( V_239 , V_216 , V_241 , 1 ) ;
F_34 ( V_239 , V_216 , V_242 , 1 ) ;
F_26 ( V_2 , V_216 , V_239 ) ;
if ( ! F_104 ( V_239 , V_216 , V_243 ) )
return 0 ;
F_22 ( V_2 , V_244 , V_245 , V_246 ) ;
F_22 ( V_2 , V_244 , V_247 , V_248 ) ;
F_99 ( V_2 , V_2 -> V_249 ) ;
F_101 ( V_2 , 0 , 0 ) ;
F_108 ( & V_2 -> V_250 , & V_2 -> V_251 ,
F_109 ( F_110 () ) ) ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_252 * V_253 = V_2 -> V_253 ;
unsigned int V_254 , V_255 , V_256 ;
unsigned int V_10 ;
if ( ! V_253 )
return;
F_22 ( V_2 , V_257 , V_258 , V_259 ) ;
V_254 = V_2 -> V_69 -> V_260 * V_2 -> V_63 . V_261 ;
V_255 = V_254 / 100 ;
if ( ! V_255 )
V_255 = 1 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_261 ; V_10 ++ ) {
switch ( V_253 -> V_262 [ V_10 ] ) {
case V_263 :
F_2 ( L_15 , V_10 ) ;
F_13 ( V_2 , V_10 , V_264 , V_233 ,
V_265 ) ;
break;
case V_266 :
V_256 = V_254 * V_253 -> V_267 [ V_10 ] / 100 ;
V_256 = F_112 ( V_256 , V_255 , V_254 ) ;
F_2 ( L_16 , V_10 , V_256 ) ;
F_13 ( V_2 , V_10 , V_264 , V_233 ,
V_268 ) ;
F_13 ( V_2 , V_10 , V_269 , V_270 ,
V_256 ) ;
break;
}
}
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
struct V_252 * V_253 = V_2 -> V_253 ;
unsigned int V_271 , V_74 , V_75 ;
unsigned int V_272 , V_273 ;
if ( ! V_85 || ! V_253 )
return;
for ( V_272 = 0 ; V_272 < V_2 -> V_63 . V_261 ; V_272 ++ ) {
V_271 = 0 ;
for ( V_273 = 0 ; V_273 < V_274 ; V_273 ++ ) {
if ( ( V_85 -> V_87 & ( 1 << V_273 ) ) &&
( V_253 -> V_275 [ V_273 ] == V_272 ) )
V_271 |= ( 1 << V_273 ) ;
}
V_271 &= 0xff ;
F_2 ( L_17 , V_272 , V_271 ) ;
V_74 = V_276 + ( V_277 * ( V_272 / V_278 ) ) ;
V_75 = F_41 ( V_2 , V_74 ) ;
V_75 &= ~ ( 0xff << ( ( V_272 % V_278 ) << 3 ) ) ;
V_75 |= ( V_271 << ( ( V_272 % V_278 ) << 3 ) ) ;
F_26 ( V_2 , V_74 , V_75 ) ;
}
F_47 ( V_2 ) ;
}
static void F_114 ( struct V_8 * V_9 ,
struct V_192 * V_193 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_187 * V_188 ;
V_188 = F_92 ( V_193 , V_193 -> V_195 ) ;
F_50 ( V_9 , V_279 ,
F_94 ( V_188 -> V_199 ) ) ;
if ( V_2 -> V_280 && ! V_9 -> V_281 ) {
V_9 -> V_281 = 1 ;
F_115 ( & V_9 -> V_282 ,
F_116 ( 0 , V_2 -> V_280 * V_283 ) ,
V_284 ) ;
}
V_193 -> V_285 . V_286 = 0 ;
}
static void F_117 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_192 * V_193 = V_9 -> V_17 ;
struct V_187 * V_188 ;
struct V_158 * V_159 ;
struct V_230 * V_231 = & V_193 -> V_287 ;
unsigned int V_288 , V_289 , V_290 ;
unsigned int V_291 , V_292 ;
unsigned int V_293 ;
int V_194 = V_193 -> V_195 ;
int V_294 = V_193 -> V_195 ;
int V_10 ;
F_2 ( L_18 ) ;
V_288 = F_104 ( V_231 -> V_236 , V_295 ,
V_296 ) ;
V_289 = F_104 ( V_231 -> V_236 , V_295 ,
V_297 ) ;
V_290 = F_104 ( V_231 -> V_236 , V_295 ,
V_298 ) ;
if ( V_289 && ( V_231 -> V_299 != V_193 -> V_285 . V_300 ) )
V_291 = 1 ;
else
V_291 = 0 ;
if ( V_290 && ( V_231 -> V_301 != V_193 -> V_285 . V_302 ) )
V_292 = 1 ;
else
V_292 = 0 ;
V_193 -> V_303 += V_231 -> V_304 ;
if ( ! V_2 -> V_305 )
V_293 = 0 ;
else if ( V_231 -> V_304 > V_2 -> V_305 )
V_293 = 1 ;
else if ( ( V_193 -> V_303 % V_2 -> V_305 ) <
V_231 -> V_304 )
V_293 = 1 ;
else
V_293 = 0 ;
V_188 = F_92 ( V_193 , V_294 ) ;
V_159 = V_188 -> V_159 ;
if ( V_291 || V_292 ) {
if ( V_291 ) {
F_2 ( L_19 ,
V_231 -> V_299 ) ;
F_97 ( V_159 -> V_191 , V_306 ,
V_307 , V_231 -> V_299 ) ;
F_97 ( V_159 -> V_160 , V_308 ,
V_309 , 1 ) ;
F_97 ( V_159 -> V_160 , V_308 ,
V_310 , 1 ) ;
V_193 -> V_285 . V_300 = V_231 -> V_299 ;
}
if ( V_292 ) {
F_2 ( L_20 ,
V_231 -> V_301 ) ;
F_97 ( V_159 -> V_160 , V_308 ,
V_309 , 1 ) ;
F_97 ( V_159 -> V_160 , V_308 ,
V_311 , V_231 -> V_301 ) ;
F_97 ( V_159 -> V_160 , V_308 ,
V_312 , 1 ) ;
V_193 -> V_285 . V_302 = V_231 -> V_301 ;
}
V_294 ++ ;
V_188 = F_92 ( V_193 , V_294 ) ;
V_159 = V_188 -> V_159 ;
}
V_159 -> V_189 = F_96 ( F_94 ( V_188 -> V_313 ) ) ;
V_159 -> V_190 = F_96 ( F_93 ( V_188 -> V_313 ) ) ;
F_97 ( V_159 -> V_191 , V_314 , V_315 ,
V_188 -> V_316 ) ;
if ( V_290 )
F_97 ( V_159 -> V_191 , V_314 , V_317 ,
V_318 ) ;
if ( F_104 ( V_231 -> V_236 , V_295 , V_319 ) )
F_97 ( V_159 -> V_191 , V_314 , V_320 , 1 ) ;
F_97 ( V_159 -> V_160 , V_161 , V_321 , 1 ) ;
F_97 ( V_159 -> V_160 , V_161 , V_309 , 0 ) ;
if ( V_294 != V_194 )
F_97 ( V_159 -> V_160 , V_161 , V_162 , 1 ) ;
if ( V_289 ) {
F_97 ( V_159 -> V_160 , V_161 , V_38 , 1 ) ;
F_97 ( V_159 -> V_160 , V_161 , V_322 ,
V_231 -> V_323 ) ;
F_97 ( V_159 -> V_160 , V_161 , V_324 ,
V_231 -> V_325 / 4 ) ;
} else {
F_97 ( V_159 -> V_160 , V_161 , V_326 , 0 ) ;
if ( V_288 )
F_97 ( V_159 -> V_160 , V_161 ,
V_327 , 0x3 ) ;
F_97 ( V_159 -> V_160 , V_161 , V_328 ,
V_231 -> V_329 ) ;
}
for ( V_10 = V_294 - V_194 + 1 ; V_10 < V_231 -> V_196 ; V_10 ++ ) {
V_294 ++ ;
V_188 = F_92 ( V_193 , V_294 ) ;
V_159 = V_188 -> V_159 ;
V_159 -> V_189 = F_96 ( F_94 ( V_188 -> V_313 ) ) ;
V_159 -> V_190 = F_96 ( F_93 ( V_188 -> V_313 ) ) ;
F_97 ( V_159 -> V_191 , V_314 , V_315 ,
V_188 -> V_316 ) ;
F_97 ( V_159 -> V_160 , V_161 , V_162 , 1 ) ;
F_97 ( V_159 -> V_160 , V_161 , V_309 , 0 ) ;
if ( V_288 )
F_97 ( V_159 -> V_160 , V_161 ,
V_327 , 0x3 ) ;
}
F_97 ( V_159 -> V_160 , V_161 , V_330 , 1 ) ;
if ( V_293 )
F_97 ( V_159 -> V_191 , V_314 , V_331 , 1 ) ;
V_188 -> V_285 . V_332 = V_231 -> V_304 ;
V_188 -> V_285 . V_333 = V_231 -> V_334 ;
F_90 () ;
V_188 = F_92 ( V_193 , V_194 ) ;
V_159 = V_188 -> V_159 ;
F_97 ( V_159 -> V_160 , V_161 , V_162 , 1 ) ;
#ifdef F_118
F_119 ( V_193 , V_194 , V_231 -> V_196 , 1 ) ;
#endif
F_90 () ;
V_193 -> V_195 = V_294 + 1 ;
if ( ! V_231 -> V_335 -> V_286 ||
F_120 ( F_121 ( V_2 -> V_69 ,
V_9 -> V_336 ) ) )
F_114 ( V_9 , V_193 ) ;
else
V_193 -> V_285 . V_286 = 1 ;
F_2 ( L_21 ,
V_9 -> V_337 , V_194 & ( V_193 -> V_196 - 1 ) ,
( V_193 -> V_195 - 1 ) & ( V_193 -> V_196 - 1 ) ) ;
F_2 ( L_22 ) ;
}
static int F_122 ( struct V_8 * V_9 )
{
struct V_192 * V_193 = V_9 -> V_20 ;
struct V_187 * V_188 ;
struct V_158 * V_159 ;
struct V_230 * V_231 = & V_193 -> V_287 ;
struct V_128 * V_69 = V_9 -> V_2 -> V_69 ;
unsigned int V_338 , V_339 , V_340 ;
F_2 ( L_23 , V_193 -> V_195 ) ;
V_188 = F_92 ( V_193 , V_193 -> V_195 ) ;
V_159 = V_188 -> V_159 ;
if ( F_77 ( V_159 -> V_160 , V_205 , V_162 ) )
return 1 ;
F_123 () ;
#ifdef F_124
F_125 ( V_193 , V_159 , V_193 -> V_195 ) ;
#endif
if ( F_77 ( V_159 -> V_160 , V_205 , V_309 ) ) {
F_105 ( V_231 , V_159 ) ;
F_34 ( V_231 -> V_236 , V_237 ,
V_341 , 1 ) ;
F_34 ( V_231 -> V_236 , V_237 ,
V_342 , 0 ) ;
return 0 ;
}
F_34 ( V_231 -> V_236 , V_237 , V_341 , 0 ) ;
if ( F_77 ( V_159 -> V_160 , V_205 , V_343 ) )
F_34 ( V_231 -> V_236 , V_237 ,
V_342 , 1 ) ;
if ( F_77 ( V_159 -> V_160 , V_205 , V_321 ) )
V_188 -> V_201 . V_344 = F_77 ( V_159 -> V_191 ,
V_345 , V_346 ) ;
if ( F_77 ( V_159 -> V_160 , V_205 , V_347 ) ) {
F_34 ( V_231 -> V_236 , V_237 ,
V_348 , 1 ) ;
V_231 -> V_349 = F_106 ( V_159 -> V_190 ) ;
V_340 = F_77 ( V_159 -> V_160 , V_205 , V_350 ) ;
switch ( V_340 ) {
case V_351 :
case V_352 :
case V_353 :
case V_354 :
V_231 -> V_355 = V_356 ;
break;
default:
V_231 -> V_355 = V_357 ;
}
}
V_188 -> V_201 . V_358 = F_77 ( V_159 -> V_160 , V_205 , V_359 ) ;
if ( ! F_77 ( V_159 -> V_160 , V_205 , V_330 ) ) {
F_34 ( V_231 -> V_236 , V_237 ,
V_360 , 1 ) ;
return 0 ;
}
F_34 ( V_231 -> V_236 , V_237 ,
V_360 , 0 ) ;
if ( V_9 -> V_2 -> V_69 -> V_70 & V_361 )
F_34 ( V_231 -> V_236 , V_237 ,
V_362 , 1 ) ;
V_338 = F_77 ( V_159 -> V_160 , V_205 , V_363 ) ;
V_339 = F_77 ( V_159 -> V_160 , V_205 , V_364 ) ;
F_2 ( L_24 , V_338 , V_339 ) ;
if ( ! V_338 || ! V_339 ) {
if ( ( V_339 == 0x09 ) &&
( V_69 -> V_70 & V_365 ) ) {
F_34 ( V_231 -> V_236 , V_237 ,
V_298 , 1 ) ;
V_231 -> V_301 = F_77 ( V_159 -> V_189 ,
V_366 ,
V_367 ) ;
F_2 ( L_25 , V_231 -> V_301 ) ;
}
} else {
if ( ( V_339 == 0x05 ) || ( V_339 == 0x06 ) )
F_34 ( V_231 -> V_236 , V_237 ,
V_362 , 0 ) ;
else
F_34 ( V_231 -> V_368 , V_369 ,
V_370 , 1 ) ;
}
F_2 ( L_26 , V_9 -> V_337 ,
V_193 -> V_195 & ( V_193 -> V_196 - 1 ) , V_193 -> V_195 ) ;
return 0 ;
}
static int F_126 ( struct V_158 * V_159 )
{
return F_77 ( V_159 -> V_160 , V_161 , V_309 ) ;
}
static int F_127 ( struct V_158 * V_159 )
{
return F_77 ( V_159 -> V_160 , V_161 , V_330 ) ;
}
static int F_128 ( struct V_8 * V_9 ,
enum V_371 V_372 )
{
unsigned int V_91 ;
V_91 = F_49 ( V_9 , V_93 ) ;
switch ( V_372 ) {
case V_373 :
F_34 ( V_91 , V_93 , V_98 , 1 ) ;
break;
case V_374 :
F_34 ( V_91 , V_93 , V_375 , 1 ) ;
break;
case V_376 :
F_34 ( V_91 , V_93 , V_377 , 1 ) ;
break;
case V_378 :
F_34 ( V_91 , V_93 , V_100 , 1 ) ;
break;
case V_379 :
F_34 ( V_91 , V_93 , V_99 , 1 ) ;
break;
case V_380 :
F_34 ( V_91 , V_93 , V_381 , 1 ) ;
break;
case V_382 :
F_34 ( V_91 , V_93 , V_98 , 1 ) ;
F_34 ( V_91 , V_93 , V_100 , 1 ) ;
break;
case V_383 :
F_34 ( V_91 , V_93 , V_96 , 1 ) ;
break;
case V_384 :
V_91 |= V_9 -> V_385 ;
break;
default:
return - 1 ;
}
F_50 ( V_9 , V_93 , V_91 ) ;
return 0 ;
}
static int F_129 ( struct V_8 * V_9 ,
enum V_371 V_372 )
{
unsigned int V_91 ;
V_91 = F_49 ( V_9 , V_93 ) ;
switch ( V_372 ) {
case V_373 :
F_34 ( V_91 , V_93 , V_98 , 0 ) ;
break;
case V_374 :
F_34 ( V_91 , V_93 , V_375 , 0 ) ;
break;
case V_376 :
F_34 ( V_91 , V_93 , V_377 , 0 ) ;
break;
case V_378 :
F_34 ( V_91 , V_93 , V_100 , 0 ) ;
break;
case V_379 :
F_34 ( V_91 , V_93 , V_99 , 0 ) ;
break;
case V_380 :
F_34 ( V_91 , V_93 , V_381 , 0 ) ;
break;
case V_382 :
F_34 ( V_91 , V_93 , V_98 , 0 ) ;
F_34 ( V_91 , V_93 , V_100 , 0 ) ;
break;
case V_383 :
F_34 ( V_91 , V_93 , V_96 , 0 ) ;
break;
case V_384 :
V_9 -> V_385 = V_91 & V_386 ;
V_91 &= ~ V_386 ;
break;
default:
return - 1 ;
}
F_50 ( V_9 , V_93 , V_91 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
unsigned int V_387 = 2000 ;
F_2 ( L_27 ) ;
F_22 ( V_2 , V_388 , V_389 , 1 ) ;
F_27 ( 10 , 15 ) ;
while ( V_387 -- && F_25 ( V_2 , V_388 , V_389 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_387 )
return - V_48 ;
F_2 ( L_28 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 )
{
unsigned int V_10 , V_387 ;
if ( F_104 ( V_2 -> V_63 . V_390 , V_391 , V_392 ) < 0x21 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_393 , 1 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ ) {
V_387 = 2000 ;
while ( V_387 -- && F_132 ( V_2 , V_10 ,
V_29 , V_393 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_387 )
return - V_48 ;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_394 , V_395 , 1 ) ;
F_22 ( V_2 , V_394 , UNDEF , 1 ) ;
F_22 ( V_2 , V_394 , V_396 , 1 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
unsigned int V_397 , V_398 ;
V_397 = 0 ;
F_34 ( V_397 , V_399 , V_400 , V_2 -> V_397 ) ;
F_34 ( V_397 , V_399 , V_401 , V_2 -> V_402 ) ;
F_34 ( V_397 , V_399 , V_403 , V_2 -> V_397 ) ;
F_34 ( V_397 , V_399 , V_404 , V_2 -> V_402 ) ;
F_34 ( V_397 , V_399 , V_405 , V_2 -> V_397 ) ;
F_34 ( V_397 , V_399 , V_406 , V_2 -> V_402 ) ;
F_26 ( V_2 , V_399 , V_397 ) ;
V_398 = 0 ;
F_34 ( V_398 , V_407 , V_408 , V_2 -> V_398 ) ;
F_34 ( V_398 , V_407 , V_409 , V_2 -> V_402 ) ;
F_34 ( V_398 , V_407 , V_410 , V_2 -> V_398 ) ;
F_34 ( V_398 , V_407 , V_411 , V_2 -> V_402 ) ;
F_34 ( V_398 , V_407 , V_412 , V_2 -> V_398 ) ;
F_34 ( V_398 , V_407 , V_413 , V_2 -> V_402 ) ;
F_34 ( V_398 , V_407 , V_414 , V_2 -> V_398 ) ;
F_34 ( V_398 , V_407 , V_415 , V_2 -> V_402 ) ;
F_26 ( V_2 , V_407 , V_398 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
F_22 ( V_2 , V_257 , V_258 , V_416 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_261 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_264 , V_233 ,
V_268 ) ;
F_13 ( V_2 , V_10 , V_269 , V_270 , 1 ) ;
}
F_22 ( V_2 , V_257 , V_417 , V_418 ) ;
}
static unsigned int F_136 ( unsigned int V_419 ,
unsigned int V_420 )
{
unsigned int V_421 = 0 ;
enum V_422 V_423 = V_424 ;
switch ( V_419 ) {
case 0 :
V_421 = F_137 ( 128 ) ;
break;
case 1 :
V_421 = F_137 ( 256 ) ;
break;
case 2 :
V_421 = F_137 ( 512 ) ;
break;
case 3 :
V_421 = F_138 ( 1 ) ;
break;
case 4 :
V_421 = F_138 ( 2 ) ;
break;
case 5 :
V_421 = F_138 ( 4 ) ;
break;
case 6 :
V_421 = F_138 ( 8 ) ;
break;
case 7 :
V_421 = F_138 ( 16 ) ;
break;
case 8 :
V_421 = F_138 ( 32 ) ;
break;
case 9 :
V_421 = F_138 ( 64 ) ;
break;
case 10 :
V_421 = F_138 ( 128 ) ;
break;
case 11 :
V_421 = F_138 ( 256 ) ;
break;
}
V_421 = F_40 (unsigned int, XGBE_FIFO_MAX, q_fifo_size) ;
V_421 = V_421 / V_420 ;
if ( V_421 >= F_138 ( 256 ) )
V_423 = V_425 ;
else if ( V_421 >= F_138 ( 128 ) )
V_423 = V_426 ;
else if ( V_421 >= F_138 ( 64 ) )
V_423 = V_427 ;
else if ( V_421 >= F_138 ( 32 ) )
V_423 = V_428 ;
else if ( V_421 >= F_138 ( 16 ) )
V_423 = V_429 ;
else if ( V_421 >= F_138 ( 8 ) )
V_423 = V_430 ;
else if ( V_421 >= F_138 ( 4 ) )
V_423 = V_431 ;
else if ( V_421 >= F_138 ( 2 ) )
V_423 = V_432 ;
else if ( V_421 >= F_138 ( 1 ) )
V_423 = V_433 ;
else if ( V_421 >= F_137 ( 512 ) )
V_423 = V_434 ;
else if ( V_421 >= F_137 ( 256 ) )
V_423 = V_424 ;
return V_423 ;
}
static void F_139 ( struct V_1 * V_2 )
{
enum V_422 V_419 ;
unsigned int V_10 ;
V_419 = F_136 ( V_2 -> V_63 . V_435 ,
V_2 -> V_28 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_436 , V_419 ) ;
F_140 ( V_2 -> V_69 , L_29 ,
V_2 -> V_28 , ( ( V_419 + 1 ) * 256 ) ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
enum V_422 V_419 ;
unsigned int V_10 ;
V_419 = F_136 ( V_2 -> V_63 . V_437 ,
V_2 -> V_25 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_438 , V_419 ) ;
F_140 ( V_2 -> V_69 , L_30 ,
V_2 -> V_25 , ( ( V_419 + 1 ) * 256 ) ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
unsigned int V_439 , V_440 , V_441 ;
unsigned int V_442 ;
unsigned int V_443 , V_444 , V_273 ;
unsigned int V_271 ;
unsigned int V_10 , V_445 , V_74 , V_75 ;
V_439 = V_2 -> V_28 / V_2 -> V_63 . V_261 ;
V_440 = V_2 -> V_28 % V_2 -> V_63 . V_261 ;
for ( V_10 = 0 , V_441 = 0 ; V_10 < V_2 -> V_63 . V_261 ; V_10 ++ ) {
for ( V_445 = 0 ; V_445 < V_439 ; V_445 ++ ) {
F_2 ( L_31 , V_441 , V_10 ) ;
F_13 ( V_2 , V_441 , V_29 ,
V_446 , V_10 ) ;
V_2 -> V_447 [ V_441 ++ ] = V_10 ;
}
if ( V_10 < V_440 ) {
F_2 ( L_31 , V_441 , V_10 ) ;
F_13 ( V_2 , V_441 , V_29 ,
V_446 , V_10 ) ;
V_2 -> V_447 [ V_441 ++ ] = V_10 ;
}
}
V_442 = F_40 (unsigned int, IEEE_8021QAZ_MAX_TCS,
pdata->rx_q_count) ;
V_443 = V_274 / V_442 ;
V_444 = V_274 % V_442 ;
V_74 = V_448 ;
V_75 = 0 ;
for ( V_10 = 0 , V_273 = 0 ; V_10 < V_442 ; ) {
V_271 = 0 ;
for ( V_445 = 0 ; V_445 < V_443 ; V_445 ++ ) {
F_2 ( L_32 , V_273 , V_10 ) ;
V_271 |= ( 1 << V_273 ) ;
V_2 -> V_449 [ V_273 ++ ] = V_10 ;
}
if ( V_10 < V_444 ) {
F_2 ( L_32 , V_273 , V_10 ) ;
V_271 |= ( 1 << V_273 ) ;
V_2 -> V_449 [ V_273 ++ ] = V_10 ;
}
V_75 |= ( V_271 << ( ( V_10 ++ % V_450 ) << 3 ) ) ;
if ( ( V_10 % V_450 ) && ( V_10 != V_442 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_451 ;
V_75 = 0 ;
}
V_74 = V_452 ;
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; ) {
V_75 |= ( 0x80 << ( ( V_10 ++ % V_453 ) << 3 ) ) ;
if ( ( V_10 % V_453 ) && ( V_10 != V_2 -> V_25 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_454 ;
V_75 = 0 ;
}
}
static void F_143 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_455 , V_456 , 2 ) ;
F_13 ( V_2 , V_10 , V_455 , V_457 , 4 ) ;
}
}
static void F_144 ( struct V_1 * V_2 )
{
F_71 ( V_2 , V_2 -> V_69 -> V_458 ) ;
if ( V_2 -> V_63 . V_137 ) {
F_22 ( V_2 , V_115 , V_459 , 1 ) ;
F_22 ( V_2 , V_115 , V_460 , 1 ) ;
F_22 ( V_2 , V_115 , V_461 , 1 ) ;
}
}
static void F_145 ( struct V_1 * V_2 )
{
unsigned int V_24 ;
V_24 = ( V_2 -> V_69 -> V_260 > V_462 ) ? 1 : 0 ;
F_22 ( V_2 , V_40 , V_463 , V_24 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_464 ) {
case V_465 :
F_58 ( V_2 ) ;
break;
case V_466 :
F_57 ( V_2 ) ;
break;
case V_467 :
F_56 ( V_2 ) ;
break;
}
}
static void F_147 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 -> V_70 & V_361 )
F_79 ( V_2 ) ;
else
F_78 ( V_2 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_468 , V_469 , 0 ) ;
F_22 ( V_2 , V_468 , V_470 , 1 ) ;
F_86 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_471 )
F_82 ( V_2 ) ;
else
F_83 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_365 )
F_80 ( V_2 ) ;
else
F_81 ( V_2 ) ;
}
static T_4 F_149 ( struct V_1 * V_2 , unsigned int V_472 )
{
bool V_473 ;
T_4 V_24 ;
switch ( V_472 ) {
case V_474 :
case V_475 :
case V_476 :
case V_477 :
V_473 = true ;
break;
default:
V_473 = false ;
} ;
V_24 = F_41 ( V_2 , V_472 ) ;
if ( V_473 )
V_24 |= ( ( T_4 ) F_41 ( V_2 , V_472 + 4 ) << 32 ) ;
return V_24 ;
}
static void F_150 ( struct V_1 * V_2 )
{
struct V_478 * V_479 = & V_2 -> V_480 ;
unsigned int V_481 = F_41 ( V_2 , V_482 ) ;
if ( F_104 ( V_481 , V_482 , V_483 ) )
V_479 -> V_484 +=
F_149 ( V_2 , V_474 ) ;
if ( F_104 ( V_481 , V_482 , V_485 ) )
V_479 -> V_486 +=
F_149 ( V_2 , V_487 ) ;
if ( F_104 ( V_481 , V_482 , V_488 ) )
V_479 -> V_489 +=
F_149 ( V_2 , V_490 ) ;
if ( F_104 ( V_481 , V_482 , V_491 ) )
V_479 -> V_492 +=
F_149 ( V_2 , V_493 ) ;
if ( F_104 ( V_481 , V_482 , V_494 ) )
V_479 -> V_495 +=
F_149 ( V_2 , V_496 ) ;
if ( F_104 ( V_481 , V_482 , V_497 ) )
V_479 -> V_498 +=
F_149 ( V_2 , V_499 ) ;
if ( F_104 ( V_481 , V_482 , V_500 ) )
V_479 -> V_501 +=
F_149 ( V_2 , V_502 ) ;
if ( F_104 ( V_481 , V_482 , V_503 ) )
V_479 -> V_504 +=
F_149 ( V_2 , V_505 ) ;
if ( F_104 ( V_481 , V_482 , V_506 ) )
V_479 -> V_507 +=
F_149 ( V_2 , V_508 ) ;
if ( F_104 ( V_481 , V_482 , V_509 ) )
V_479 -> V_510 +=
F_149 ( V_2 , V_511 ) ;
if ( F_104 ( V_481 , V_482 , V_512 ) )
V_479 -> V_513 +=
F_149 ( V_2 , V_514 ) ;
if ( F_104 ( V_481 , V_482 , V_515 ) )
V_479 -> V_516 +=
F_149 ( V_2 , V_517 ) ;
if ( F_104 ( V_481 , V_482 , V_518 ) )
V_479 -> V_489 +=
F_149 ( V_2 , V_519 ) ;
if ( F_104 ( V_481 , V_482 , V_520 ) )
V_479 -> V_521 +=
F_149 ( V_2 , V_522 ) ;
if ( F_104 ( V_481 , V_482 , V_523 ) )
V_479 -> V_524 +=
F_149 ( V_2 , V_475 ) ;
if ( F_104 ( V_481 , V_482 , V_525 ) )
V_479 -> V_526 +=
F_149 ( V_2 , V_527 ) ;
if ( F_104 ( V_481 , V_482 , V_528 ) )
V_479 -> V_529 +=
F_149 ( V_2 , V_530 ) ;
if ( F_104 ( V_481 , V_482 , V_531 ) )
V_479 -> V_532 +=
F_149 ( V_2 , V_533 ) ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_478 * V_479 = & V_2 -> V_480 ;
unsigned int V_481 = F_41 ( V_2 , V_534 ) ;
if ( F_104 ( V_481 , V_534 , V_535 ) )
V_479 -> V_536 +=
F_149 ( V_2 , V_537 ) ;
if ( F_104 ( V_481 , V_534 , V_538 ) )
V_479 -> V_539 +=
F_149 ( V_2 , V_476 ) ;
if ( F_104 ( V_481 , V_534 , V_540 ) )
V_479 -> V_541 +=
F_149 ( V_2 , V_477 ) ;
if ( F_104 ( V_481 , V_534 , V_542 ) )
V_479 -> V_543 +=
F_149 ( V_2 , V_544 ) ;
if ( F_104 ( V_481 , V_534 , V_545 ) )
V_479 -> V_546 +=
F_149 ( V_2 , V_547 ) ;
if ( F_104 ( V_481 , V_534 , V_548 ) )
V_479 -> V_549 +=
F_149 ( V_2 , V_550 ) ;
if ( F_104 ( V_481 , V_534 , V_551 ) )
V_479 -> V_552 +=
F_149 ( V_2 , V_553 ) ;
if ( F_104 ( V_481 , V_534 , V_554 ) )
V_479 -> V_555 +=
F_149 ( V_2 , V_556 ) ;
if ( F_104 ( V_481 , V_534 , V_557 ) )
V_479 -> V_558 +=
F_149 ( V_2 , V_559 ) ;
if ( F_104 ( V_481 , V_534 , V_560 ) )
V_479 -> V_561 +=
F_149 ( V_2 , V_562 ) ;
if ( F_104 ( V_481 , V_534 , V_563 ) )
V_479 -> V_564 +=
F_149 ( V_2 , V_565 ) ;
if ( F_104 ( V_481 , V_534 , V_566 ) )
V_479 -> V_567 +=
F_149 ( V_2 , V_568 ) ;
if ( F_104 ( V_481 , V_534 , V_569 ) )
V_479 -> V_570 +=
F_149 ( V_2 , V_571 ) ;
if ( F_104 ( V_481 , V_534 , V_572 ) )
V_479 -> V_573 +=
F_149 ( V_2 , V_574 ) ;
if ( F_104 ( V_481 , V_534 , V_575 ) )
V_479 -> V_576 +=
F_149 ( V_2 , V_577 ) ;
if ( F_104 ( V_481 , V_534 , V_578 ) )
V_479 -> V_579 +=
F_149 ( V_2 , V_580 ) ;
if ( F_104 ( V_481 , V_534 , V_581 ) )
V_479 -> V_582 +=
F_149 ( V_2 , V_583 ) ;
if ( F_104 ( V_481 , V_534 , V_584 ) )
V_479 -> V_585 +=
F_149 ( V_2 , V_586 ) ;
if ( F_104 ( V_481 , V_534 , V_587 ) )
V_479 -> V_588 +=
F_149 ( V_2 , V_589 ) ;
if ( F_104 ( V_481 , V_534 , V_590 ) )
V_479 -> V_591 +=
F_149 ( V_2 , V_592 ) ;
if ( F_104 ( V_481 , V_534 , V_593 ) )
V_479 -> V_594 +=
F_149 ( V_2 , V_595 ) ;
if ( F_104 ( V_481 , V_534 , V_596 ) )
V_479 -> V_597 +=
F_149 ( V_2 , V_598 ) ;
if ( F_104 ( V_481 , V_534 , V_599 ) )
V_479 -> V_600 +=
F_149 ( V_2 , V_601 ) ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_478 * V_479 = & V_2 -> V_480 ;
F_22 ( V_2 , V_602 , V_603 , 1 ) ;
V_479 -> V_484 +=
F_149 ( V_2 , V_474 ) ;
V_479 -> V_486 +=
F_149 ( V_2 , V_487 ) ;
V_479 -> V_489 +=
F_149 ( V_2 , V_490 ) ;
V_479 -> V_492 +=
F_149 ( V_2 , V_493 ) ;
V_479 -> V_495 +=
F_149 ( V_2 , V_496 ) ;
V_479 -> V_498 +=
F_149 ( V_2 , V_499 ) ;
V_479 -> V_501 +=
F_149 ( V_2 , V_502 ) ;
V_479 -> V_504 +=
F_149 ( V_2 , V_505 ) ;
V_479 -> V_507 +=
F_149 ( V_2 , V_508 ) ;
V_479 -> V_510 +=
F_149 ( V_2 , V_511 ) ;
V_479 -> V_513 +=
F_149 ( V_2 , V_514 ) ;
V_479 -> V_516 +=
F_149 ( V_2 , V_517 ) ;
V_479 -> V_489 +=
F_149 ( V_2 , V_519 ) ;
V_479 -> V_521 +=
F_149 ( V_2 , V_522 ) ;
V_479 -> V_524 +=
F_149 ( V_2 , V_475 ) ;
V_479 -> V_526 +=
F_149 ( V_2 , V_527 ) ;
V_479 -> V_529 +=
F_149 ( V_2 , V_530 ) ;
V_479 -> V_532 +=
F_149 ( V_2 , V_533 ) ;
V_479 -> V_536 +=
F_149 ( V_2 , V_537 ) ;
V_479 -> V_539 +=
F_149 ( V_2 , V_476 ) ;
V_479 -> V_541 +=
F_149 ( V_2 , V_477 ) ;
V_479 -> V_543 +=
F_149 ( V_2 , V_544 ) ;
V_479 -> V_546 +=
F_149 ( V_2 , V_547 ) ;
V_479 -> V_549 +=
F_149 ( V_2 , V_550 ) ;
V_479 -> V_552 +=
F_149 ( V_2 , V_553 ) ;
V_479 -> V_555 +=
F_149 ( V_2 , V_556 ) ;
V_479 -> V_558 +=
F_149 ( V_2 , V_559 ) ;
V_479 -> V_561 +=
F_149 ( V_2 , V_562 ) ;
V_479 -> V_564 +=
F_149 ( V_2 , V_565 ) ;
V_479 -> V_567 +=
F_149 ( V_2 , V_568 ) ;
V_479 -> V_570 +=
F_149 ( V_2 , V_571 ) ;
V_479 -> V_573 +=
F_149 ( V_2 , V_574 ) ;
V_479 -> V_576 +=
F_149 ( V_2 , V_577 ) ;
V_479 -> V_579 +=
F_149 ( V_2 , V_580 ) ;
V_479 -> V_582 +=
F_149 ( V_2 , V_583 ) ;
V_479 -> V_585 +=
F_149 ( V_2 , V_586 ) ;
V_479 -> V_588 +=
F_149 ( V_2 , V_589 ) ;
V_479 -> V_591 +=
F_149 ( V_2 , V_592 ) ;
V_479 -> V_594 +=
F_149 ( V_2 , V_595 ) ;
V_479 -> V_597 +=
F_149 ( V_2 , V_598 ) ;
V_479 -> V_600 +=
F_149 ( V_2 , V_601 ) ;
F_22 ( V_2 , V_602 , V_603 , 0 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_602 , V_604 , 1 ) ;
F_22 ( V_2 , V_602 , V_605 , 1 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned int V_606 , V_607 , V_608 ;
unsigned int V_609 ;
unsigned long V_610 ;
if ( V_9 -> V_336 < V_611 ) {
V_606 = V_612 ;
V_607 = ( V_9 -> V_336 * V_613 ) +
V_614 ;
} else {
V_608 = V_9 -> V_336 - V_611 ;
V_606 = V_615 + ( ( V_608 / V_616 ) * V_617 ) ;
V_607 = ( ( V_608 % V_616 ) * V_613 ) +
V_618 ;
}
V_610 = V_619 + ( V_620 * V_621 ) ;
while ( F_155 ( V_619 , V_610 ) ) {
V_609 = F_41 ( V_2 , V_606 ) ;
V_609 = F_156 ( V_609 , V_607 , V_622 ) ;
if ( ( V_609 == V_623 ) ||
( V_609 == V_624 ) )
break;
F_27 ( 500 , 1000 ) ;
}
if ( ! F_155 ( V_619 , V_610 ) )
F_157 ( V_2 -> V_69 ,
L_33 ,
V_9 -> V_336 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_625 , 1 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_626 ,
V_627 ) ;
F_22 ( V_2 , V_112 , V_628 , 1 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_154 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_112 , V_628 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_626 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_625 , 0 ) ;
}
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_75 , V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_629 , 1 ) ;
}
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
V_75 |= ( 0x02 << ( V_10 << 1 ) ) ;
F_26 ( V_2 , V_630 , V_75 ) ;
F_22 ( V_2 , V_40 , V_631 , 1 ) ;
F_22 ( V_2 , V_40 , V_632 , 1 ) ;
F_22 ( V_2 , V_40 , V_633 , 1 ) ;
F_22 ( V_2 , V_40 , V_634 , 1 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
F_22 ( V_2 , V_40 , V_631 , 0 ) ;
F_22 ( V_2 , V_40 , V_632 , 0 ) ;
F_22 ( V_2 , V_40 , V_633 , 0 ) ;
F_22 ( V_2 , V_40 , V_634 , 0 ) ;
F_26 ( V_2 , V_630 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_629 , 0 ) ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_625 , 1 ) ;
}
F_22 ( V_2 , V_112 , V_628 , 1 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_154 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_112 , V_628 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_625 , 0 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_629 , 1 ) ;
}
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_629 , 0 ) ;
}
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_635 * V_636 = & V_2 -> V_636 ;
int V_5 ;
F_2 ( L_34 ) ;
V_5 = F_131 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
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
V_636 -> V_637 ( V_2 ) ;
V_636 -> V_638 ( V_2 ) ;
F_48 ( V_2 ) ;
F_135 ( V_2 ) ;
F_142 ( V_2 ) ;
F_14 ( V_2 , V_2 -> V_639 ) ;
F_12 ( V_2 , V_2 -> V_640 ) ;
F_16 ( V_2 , V_2 -> V_641 ) ;
F_15 ( V_2 , V_2 -> V_642 ) ;
F_139 ( V_2 ) ;
F_141 ( V_2 ) ;
F_143 ( V_2 ) ;
F_111 ( V_2 ) ;
F_113 ( V_2 ) ;
F_51 ( V_2 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
F_47 ( V_2 ) ;
F_146 ( V_2 ) ;
F_147 ( V_2 ) ;
F_148 ( V_2 ) ;
F_153 ( V_2 ) ;
F_55 ( V_2 ) ;
F_2 ( L_35 ) ;
return 0 ;
}
void F_167 ( struct V_643 * V_644 )
{
F_2 ( L_36 ) ;
V_644 -> V_645 = F_76 ;
V_644 -> V_646 = F_59 ;
V_644 -> V_647 = F_60 ;
V_644 -> V_648 = F_70 ;
V_644 -> V_649 = F_71 ;
V_644 -> V_650 = F_79 ;
V_644 -> V_651 = F_78 ;
V_644 -> V_652 = F_80 ;
V_644 -> V_653 = F_81 ;
V_644 -> V_654 = F_82 ;
V_644 -> V_655 = F_83 ;
V_644 -> V_656 = F_86 ;
V_644 -> V_657 = F_72 ;
V_644 -> V_658 = F_75 ;
V_644 -> V_659 = F_56 ;
V_644 -> V_660 = F_57 ;
V_644 -> V_661 = F_58 ;
V_644 -> V_662 = F_158 ;
V_644 -> V_663 = F_159 ;
V_644 -> V_664 = F_160 ;
V_644 -> V_665 = F_161 ;
V_644 -> V_666 = F_162 ;
V_644 -> V_667 = F_163 ;
V_644 -> V_668 = F_164 ;
V_644 -> V_669 = F_165 ;
V_644 -> V_670 = F_117 ;
V_644 -> V_671 = F_122 ;
V_644 -> V_672 = F_128 ;
V_644 -> V_673 = F_129 ;
V_644 -> V_674 = F_166 ;
V_644 -> exit = F_130 ;
V_644 -> V_675 = F_91 ;
V_644 -> V_676 = F_98 ;
V_644 -> V_677 = F_89 ;
V_644 -> V_678 = F_95 ;
V_644 -> V_679 = F_127 ;
V_644 -> V_680 = F_126 ;
V_644 -> V_681 = F_114 ;
V_644 -> V_682 = F_45 ;
V_644 -> V_683 = F_46 ;
V_644 -> V_684 = F_17 ;
V_644 -> V_685 = F_18 ;
V_644 -> V_686 = F_1 ;
V_644 -> V_687 = F_3 ;
V_644 -> V_688 = F_15 ;
V_644 -> V_689 = F_16 ;
V_644 -> V_690 = F_12 ;
V_644 -> V_691 = F_14 ;
V_644 -> V_692 = F_11 ;
V_644 -> V_693 = F_10 ;
V_644 -> V_694 = F_9 ;
V_644 -> V_695 = F_8 ;
V_644 -> V_696 = F_6 ;
V_644 -> V_697 = F_4 ;
V_644 -> V_698 = F_150 ;
V_644 -> V_699 = F_151 ;
V_644 -> V_700 = F_152 ;
V_644 -> V_701 = F_107 ;
V_644 -> V_702 = F_99 ;
V_644 -> V_703 = F_101 ;
V_644 -> V_704 = F_102 ;
V_644 -> V_705 = F_103 ;
V_644 -> V_706 = F_111 ;
V_644 -> V_707 = F_113 ;
V_644 -> V_708 = F_35 ;
V_644 -> V_709 = F_36 ;
V_644 -> V_710 = F_32 ;
V_644 -> V_711 = F_33 ;
F_2 ( L_37 ) ;
}
