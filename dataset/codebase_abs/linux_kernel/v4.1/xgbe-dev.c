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
static int F_72 ( struct V_1 * V_2 )
{
struct V_128 * V_69 = V_2 -> V_69 ;
unsigned int V_143 , V_144 ;
V_143 = ( ( V_69 -> V_145 & V_146 ) != 0 ) ;
V_144 = ( ( V_69 -> V_145 & V_147 ) != 0 ) ;
F_59 ( V_2 , V_143 ) ;
F_60 ( V_2 , V_144 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , int V_148 ,
int V_149 )
{
unsigned int V_150 ;
int V_151 ;
if ( V_149 & V_152 )
V_150 = V_149 & ~ V_152 ;
else
V_150 = ( V_2 -> V_153 << 16 ) | ( V_149 & 0xffff ) ;
F_24 ( & V_2 -> V_154 ) ;
F_74 ( V_2 , V_155 << 2 , V_150 >> 8 ) ;
V_151 = F_75 ( V_2 , ( V_150 & 0xff ) << 2 ) ;
F_28 ( & V_2 -> V_154 ) ;
return V_151 ;
}
static void F_76 ( struct V_1 * V_2 , int V_148 ,
int V_149 , int V_151 )
{
unsigned int V_150 ;
if ( V_149 & V_152 )
V_150 = V_149 & ~ V_152 ;
else
V_150 = ( V_2 -> V_153 << 16 ) | ( V_149 & 0xffff ) ;
if ( ( ( V_150 >> 16 ) == V_156 ) &&
( ( V_150 & 0xffff ) == V_157 ) ) {
struct V_158 * V_159 = V_2 -> V_159 ;
if ( V_151 & V_160 ) {
if ( V_159 -> V_161 & V_162 )
F_56 ( V_2 ) ;
else
F_57 ( V_2 ) ;
} else {
F_58 ( V_2 ) ;
}
}
F_24 ( & V_2 -> V_154 ) ;
F_74 ( V_2 , V_155 << 2 , V_150 >> 8 ) ;
F_74 ( V_2 , ( V_150 & 0xff ) << 2 , V_151 ) ;
F_28 ( & V_2 -> V_154 ) ;
}
static int F_77 ( struct V_163 * V_164 )
{
return ! F_78 ( V_164 -> V_165 , V_166 , V_167 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_168 , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_40 , V_168 , 1 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_169 , V_170 , 1 ) ;
F_22 ( V_2 , V_169 , V_171 , 1 ) ;
F_22 ( V_2 , V_169 , V_172 , 0 ) ;
F_22 ( V_2 , V_169 , V_173 , 0 ) ;
F_22 ( V_2 , V_169 , V_174 , 0x3 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_169 , V_174 , 0 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_115 , V_175 , 1 ) ;
F_22 ( V_2 , V_169 , V_176 , 1 ) ;
F_22 ( V_2 , V_169 , V_177 , 0 ) ;
F_22 ( V_2 , V_169 , V_178 , 1 ) ;
F_22 ( V_2 , V_169 , V_179 , 1 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_115 , V_175 , 0 ) ;
return 0 ;
}
static V_56 F_85 ( T_2 V_180 )
{
V_56 V_181 = V_182 ;
V_56 V_136 = ~ 0 ;
V_56 V_183 = 0 ;
unsigned char * V_184 = ( unsigned char * ) & V_180 ;
unsigned char V_185 = 0 ;
int V_10 , V_186 ;
V_186 = F_86 ( V_187 ) ;
for ( V_10 = 0 ; V_10 < V_186 ; V_10 ++ ) {
if ( ( V_10 % 8 ) == 0 )
V_185 = V_184 [ V_10 / 8 ] ;
V_183 = ( ( V_136 & 1 ) ^ V_185 ) & 1 ;
V_136 >>= 1 ;
V_185 >>= 1 ;
if ( V_183 )
V_136 ^= V_181 ;
}
return V_136 ;
}
static int F_87 ( struct V_1 * V_2 )
{
V_56 V_136 ;
T_3 V_188 ;
T_2 V_180 ;
T_3 V_189 = 0 ;
F_88 (vid, pdata->active_vlans, VLAN_N_VID) {
V_180 = F_89 ( V_188 ) ;
V_136 = F_68 ( ~ F_85 ( V_180 ) ) >> 28 ;
V_189 |= ( 1 << V_136 ) ;
}
F_22 ( V_2 , V_190 , V_191 , V_189 ) ;
return 0 ;
}
static void F_90 ( struct V_192 * V_193 )
{
struct V_163 * V_164 = V_193 -> V_164 ;
V_164 -> V_194 = 0 ;
V_164 -> V_195 = 0 ;
V_164 -> V_196 = 0 ;
V_164 -> V_165 = 0 ;
F_91 () ;
}
static void F_92 ( struct V_8 * V_9 )
{
struct V_197 * V_198 = V_9 -> V_17 ;
struct V_192 * V_193 ;
int V_10 ;
int V_199 = V_198 -> V_200 ;
F_2 ( L_11 ) ;
for ( V_10 = 0 ; V_10 < V_198 -> V_201 ; V_10 ++ ) {
V_193 = F_93 ( V_198 , V_10 ) ;
F_90 ( V_193 ) ;
}
F_50 ( V_9 , V_202 , V_198 -> V_201 - 1 ) ;
V_193 = F_93 ( V_198 , V_199 ) ;
F_50 ( V_9 , V_203 ,
F_94 ( V_193 -> V_204 ) ) ;
F_50 ( V_9 , V_205 ,
F_95 ( V_193 -> V_204 ) ) ;
F_2 ( L_12 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_192 * V_193 , unsigned int V_43 )
{
struct V_163 * V_164 = V_193 -> V_164 ;
unsigned int V_206 = V_2 -> V_206 ;
unsigned int V_207 = V_2 -> V_207 ;
unsigned int V_208 ;
if ( ! V_206 && ! V_207 ) {
V_208 = 1 ;
} else {
if ( V_207 && ! ( ( V_43 + 1 ) % V_207 ) )
V_208 = 1 ;
else
V_208 = 0 ;
}
V_164 -> V_194 = F_97 ( F_95 ( V_193 -> V_209 . V_210 . V_211 ) ) ;
V_164 -> V_195 = F_97 ( F_94 ( V_193 -> V_209 . V_210 . V_211 ) ) ;
V_164 -> V_196 = F_97 ( F_95 ( V_193 -> V_209 . V_212 . V_211 ) ) ;
V_164 -> V_165 = F_97 ( F_94 ( V_193 -> V_209 . V_212 . V_211 ) ) ;
F_98 ( V_164 -> V_165 , V_213 , V_214 , V_208 ) ;
F_91 () ;
F_98 ( V_164 -> V_165 , V_213 , V_167 , 1 ) ;
F_91 () ;
}
static void F_99 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_197 * V_198 = V_9 -> V_20 ;
struct V_192 * V_193 ;
unsigned int V_199 = V_198 -> V_200 ;
unsigned int V_10 ;
F_2 ( L_13 ) ;
for ( V_10 = 0 ; V_10 < V_198 -> V_201 ; V_10 ++ ) {
V_193 = F_93 ( V_198 , V_10 ) ;
F_96 ( V_2 , V_193 , V_10 ) ;
}
F_50 ( V_9 , V_215 , V_198 -> V_201 - 1 ) ;
V_193 = F_93 ( V_198 , V_199 ) ;
F_50 ( V_9 , V_216 ,
F_94 ( V_193 -> V_204 ) ) ;
F_50 ( V_9 , V_217 ,
F_95 ( V_193 -> V_204 ) ) ;
V_193 = F_93 ( V_198 , V_199 + V_198 -> V_201 - 1 ) ;
F_50 ( V_9 , V_218 ,
F_95 ( V_193 -> V_204 ) ) ;
F_2 ( L_14 ) ;
}
static void F_100 ( struct V_1 * V_2 ,
unsigned int V_219 )
{
F_26 ( V_2 , V_220 , V_219 ) ;
F_22 ( V_2 , V_221 , V_222 , 1 ) ;
while ( F_25 ( V_2 , V_221 , V_222 ) )
F_101 ( 5 ) ;
}
static void F_102 ( struct V_1 * V_2 , unsigned int V_223 ,
unsigned int V_224 )
{
F_26 ( V_2 , V_225 , V_223 ) ;
F_26 ( V_2 , V_226 , V_224 ) ;
F_22 ( V_2 , V_221 , V_227 , 1 ) ;
while ( F_25 ( V_2 , V_221 , V_227 ) )
F_101 ( 5 ) ;
}
static T_4 F_103 ( struct V_1 * V_2 )
{
T_4 V_224 ;
V_224 = F_41 ( V_2 , V_228 ) ;
V_224 *= V_229 ;
V_224 += F_41 ( V_2 , V_230 ) ;
return V_224 ;
}
static T_4 F_104 ( struct V_1 * V_2 )
{
unsigned int V_231 ;
T_4 V_224 ;
V_231 = F_41 ( V_2 , V_232 ) ;
if ( F_105 ( V_231 , V_232 , V_233 ) )
return 0 ;
V_224 = F_41 ( V_2 , V_234 ) ;
V_224 *= V_229 ;
V_224 += V_231 ;
return V_224 ;
}
static void F_106 ( struct V_235 * V_236 ,
struct V_163 * V_164 )
{
T_4 V_224 ;
if ( F_78 ( V_164 -> V_165 , V_237 , V_238 ) &&
! F_78 ( V_164 -> V_165 , V_237 , V_239 ) ) {
V_224 = F_107 ( V_164 -> V_195 ) ;
V_224 <<= 32 ;
V_224 |= F_107 ( V_164 -> V_194 ) ;
if ( V_224 != 0xffffffffffffffffULL ) {
V_236 -> V_240 = V_224 ;
F_34 ( V_236 -> V_241 , V_242 ,
V_243 , 1 ) ;
}
}
}
static int F_108 ( struct V_1 * V_2 ,
unsigned int V_244 )
{
F_34 ( V_244 , V_221 , V_245 , 1 ) ;
F_34 ( V_244 , V_221 , V_246 , 1 ) ;
F_34 ( V_244 , V_221 , V_247 , 1 ) ;
F_26 ( V_2 , V_221 , V_244 ) ;
if ( ! F_105 ( V_244 , V_221 , V_248 ) )
return 0 ;
F_22 ( V_2 , V_249 , V_250 , V_251 ) ;
F_22 ( V_2 , V_249 , V_252 , V_253 ) ;
F_100 ( V_2 , V_2 -> V_254 ) ;
F_102 ( V_2 , 0 , 0 ) ;
F_109 ( & V_2 -> V_255 , & V_2 -> V_256 ,
F_110 ( F_111 () ) ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_257 * V_258 = V_2 -> V_258 ;
unsigned int V_259 , V_260 , V_261 ;
unsigned int V_10 ;
if ( ! V_258 )
return;
F_22 ( V_2 , V_262 , V_263 , V_264 ) ;
V_259 = V_2 -> V_69 -> V_265 * V_2 -> V_63 . V_266 ;
V_260 = V_259 / 100 ;
if ( ! V_260 )
V_260 = 1 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_266 ; V_10 ++ ) {
switch ( V_258 -> V_267 [ V_10 ] ) {
case V_268 :
F_2 ( L_15 , V_10 ) ;
F_13 ( V_2 , V_10 , V_269 , V_238 ,
V_270 ) ;
break;
case V_271 :
V_261 = V_259 * V_258 -> V_272 [ V_10 ] / 100 ;
V_261 = F_113 ( V_261 , V_260 , V_259 ) ;
F_2 ( L_16 , V_10 , V_261 ) ;
F_13 ( V_2 , V_10 , V_269 , V_238 ,
V_273 ) ;
F_13 ( V_2 , V_10 , V_274 , V_275 ,
V_261 ) ;
break;
}
}
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
struct V_257 * V_258 = V_2 -> V_258 ;
unsigned int V_276 , V_74 , V_75 ;
unsigned int V_277 , V_278 ;
if ( ! V_85 || ! V_258 )
return;
for ( V_277 = 0 ; V_277 < V_2 -> V_63 . V_266 ; V_277 ++ ) {
V_276 = 0 ;
for ( V_278 = 0 ; V_278 < V_279 ; V_278 ++ ) {
if ( ( V_85 -> V_87 & ( 1 << V_278 ) ) &&
( V_258 -> V_280 [ V_278 ] == V_277 ) )
V_276 |= ( 1 << V_278 ) ;
}
V_276 &= 0xff ;
F_2 ( L_17 , V_277 , V_276 ) ;
V_74 = V_281 + ( V_282 * ( V_277 / V_283 ) ) ;
V_75 = F_41 ( V_2 , V_74 ) ;
V_75 &= ~ ( 0xff << ( ( V_277 % V_283 ) << 3 ) ) ;
V_75 |= ( V_276 << ( ( V_277 % V_283 ) << 3 ) ) ;
F_26 ( V_2 , V_74 , V_75 ) ;
}
F_47 ( V_2 ) ;
}
static void F_115 ( struct V_8 * V_9 ,
struct V_197 * V_198 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_192 * V_193 ;
F_116 () ;
V_193 = F_93 ( V_198 , V_198 -> V_200 ) ;
F_50 ( V_9 , V_284 ,
F_95 ( V_193 -> V_204 ) ) ;
if ( V_2 -> V_285 && ! V_9 -> V_286 ) {
V_9 -> V_286 = 1 ;
F_117 ( & V_9 -> V_287 ,
V_288 + F_118 ( V_2 -> V_285 ) ) ;
}
V_198 -> V_289 . V_290 = 0 ;
}
static void F_119 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_197 * V_198 = V_9 -> V_17 ;
struct V_192 * V_193 ;
struct V_163 * V_164 ;
struct V_235 * V_236 = & V_198 -> V_291 ;
unsigned int V_292 , V_293 , V_294 ;
unsigned int V_295 , V_296 ;
unsigned int V_297 ;
int V_199 = V_198 -> V_200 ;
int V_298 = V_198 -> V_200 ;
int V_10 ;
F_2 ( L_18 ) ;
V_292 = F_105 ( V_236 -> V_241 , V_299 ,
V_300 ) ;
V_293 = F_105 ( V_236 -> V_241 , V_299 ,
V_301 ) ;
V_294 = F_105 ( V_236 -> V_241 , V_299 ,
V_302 ) ;
if ( V_293 && ( V_236 -> V_303 != V_198 -> V_289 . V_304 ) )
V_295 = 1 ;
else
V_295 = 0 ;
if ( V_294 && ( V_236 -> V_305 != V_198 -> V_289 . V_306 ) )
V_296 = 1 ;
else
V_296 = 0 ;
V_198 -> V_307 += V_236 -> V_308 ;
if ( ! V_2 -> V_309 )
V_297 = 0 ;
else if ( V_236 -> V_308 > V_2 -> V_309 )
V_297 = 1 ;
else if ( ( V_198 -> V_307 % V_2 -> V_309 ) <
V_236 -> V_308 )
V_297 = 1 ;
else
V_297 = 0 ;
V_193 = F_93 ( V_198 , V_298 ) ;
V_164 = V_193 -> V_164 ;
if ( V_295 || V_296 ) {
if ( V_295 ) {
F_2 ( L_19 ,
V_236 -> V_303 ) ;
F_98 ( V_164 -> V_196 , V_310 ,
V_311 , V_236 -> V_303 ) ;
F_98 ( V_164 -> V_165 , V_312 ,
V_313 , 1 ) ;
F_98 ( V_164 -> V_165 , V_312 ,
V_314 , 1 ) ;
V_198 -> V_289 . V_304 = V_236 -> V_303 ;
}
if ( V_296 ) {
F_2 ( L_20 ,
V_236 -> V_305 ) ;
F_98 ( V_164 -> V_165 , V_312 ,
V_313 , 1 ) ;
F_98 ( V_164 -> V_165 , V_312 ,
V_315 , V_236 -> V_305 ) ;
F_98 ( V_164 -> V_165 , V_312 ,
V_316 , 1 ) ;
V_198 -> V_289 . V_306 = V_236 -> V_305 ;
}
V_298 ++ ;
V_193 = F_93 ( V_198 , V_298 ) ;
V_164 = V_193 -> V_164 ;
}
V_164 -> V_194 = F_97 ( F_95 ( V_193 -> V_317 ) ) ;
V_164 -> V_195 = F_97 ( F_94 ( V_193 -> V_317 ) ) ;
F_98 ( V_164 -> V_196 , V_318 , V_319 ,
V_193 -> V_320 ) ;
if ( V_294 )
F_98 ( V_164 -> V_196 , V_318 , V_321 ,
V_322 ) ;
if ( F_105 ( V_236 -> V_241 , V_299 , V_323 ) )
F_98 ( V_164 -> V_196 , V_318 , V_324 , 1 ) ;
F_98 ( V_164 -> V_165 , V_166 , V_325 , 1 ) ;
F_98 ( V_164 -> V_165 , V_166 , V_313 , 0 ) ;
if ( V_298 != V_199 )
F_98 ( V_164 -> V_165 , V_166 , V_167 , 1 ) ;
if ( V_293 ) {
F_98 ( V_164 -> V_165 , V_166 , V_38 , 1 ) ;
F_98 ( V_164 -> V_165 , V_166 , V_326 ,
V_236 -> V_327 ) ;
F_98 ( V_164 -> V_165 , V_166 , V_328 ,
V_236 -> V_329 / 4 ) ;
} else {
F_98 ( V_164 -> V_165 , V_166 , V_330 , 0 ) ;
if ( V_292 )
F_98 ( V_164 -> V_165 , V_166 ,
V_331 , 0x3 ) ;
F_98 ( V_164 -> V_165 , V_166 , V_332 ,
V_236 -> V_333 ) ;
}
for ( V_10 = V_298 - V_199 + 1 ; V_10 < V_236 -> V_201 ; V_10 ++ ) {
V_298 ++ ;
V_193 = F_93 ( V_198 , V_298 ) ;
V_164 = V_193 -> V_164 ;
V_164 -> V_194 = F_97 ( F_95 ( V_193 -> V_317 ) ) ;
V_164 -> V_195 = F_97 ( F_94 ( V_193 -> V_317 ) ) ;
F_98 ( V_164 -> V_196 , V_318 , V_319 ,
V_193 -> V_320 ) ;
F_98 ( V_164 -> V_165 , V_166 , V_167 , 1 ) ;
F_98 ( V_164 -> V_165 , V_166 , V_313 , 0 ) ;
if ( V_292 )
F_98 ( V_164 -> V_165 , V_166 ,
V_331 , 0x3 ) ;
}
F_98 ( V_164 -> V_165 , V_166 , V_334 , 1 ) ;
if ( V_297 )
F_98 ( V_164 -> V_196 , V_318 , V_335 , 1 ) ;
V_193 -> V_289 . V_336 = V_236 -> V_308 ;
V_193 -> V_289 . V_337 = V_236 -> V_338 ;
F_91 () ;
V_193 = F_93 ( V_198 , V_199 ) ;
V_164 = V_193 -> V_164 ;
F_98 ( V_164 -> V_165 , V_166 , V_167 , 1 ) ;
#ifdef F_120
F_121 ( V_198 , V_199 , V_236 -> V_201 , 1 ) ;
#endif
F_91 () ;
V_198 -> V_200 = V_298 + 1 ;
if ( ! V_236 -> V_339 -> V_290 ||
F_122 ( F_123 ( V_2 -> V_69 ,
V_9 -> V_340 ) ) )
F_115 ( V_9 , V_198 ) ;
else
V_198 -> V_289 . V_290 = 1 ;
F_2 ( L_21 ,
V_9 -> V_341 , V_199 & ( V_198 -> V_201 - 1 ) ,
( V_198 -> V_200 - 1 ) & ( V_198 -> V_201 - 1 ) ) ;
F_2 ( L_22 ) ;
}
static int F_124 ( struct V_8 * V_9 )
{
struct V_197 * V_198 = V_9 -> V_20 ;
struct V_192 * V_193 ;
struct V_163 * V_164 ;
struct V_235 * V_236 = & V_198 -> V_291 ;
struct V_128 * V_69 = V_9 -> V_2 -> V_69 ;
unsigned int V_342 , V_343 , V_344 ;
F_2 ( L_23 , V_198 -> V_200 ) ;
V_193 = F_93 ( V_198 , V_198 -> V_200 ) ;
V_164 = V_193 -> V_164 ;
if ( F_78 ( V_164 -> V_165 , V_213 , V_167 ) )
return 1 ;
F_125 () ;
#ifdef F_126
F_127 ( V_198 , V_164 , V_198 -> V_200 ) ;
#endif
if ( F_78 ( V_164 -> V_165 , V_213 , V_313 ) ) {
F_106 ( V_236 , V_164 ) ;
F_34 ( V_236 -> V_241 , V_242 ,
V_345 , 1 ) ;
F_34 ( V_236 -> V_241 , V_242 ,
V_346 , 0 ) ;
return 0 ;
}
F_34 ( V_236 -> V_241 , V_242 , V_345 , 0 ) ;
if ( F_78 ( V_164 -> V_165 , V_213 , V_347 ) )
F_34 ( V_236 -> V_241 , V_242 ,
V_346 , 1 ) ;
if ( F_78 ( V_164 -> V_165 , V_213 , V_325 ) )
V_193 -> V_209 . V_348 = F_78 ( V_164 -> V_196 ,
V_349 , V_350 ) ;
if ( F_78 ( V_164 -> V_165 , V_213 , V_351 ) ) {
F_34 ( V_236 -> V_241 , V_242 ,
V_352 , 1 ) ;
V_236 -> V_353 = F_107 ( V_164 -> V_195 ) ;
V_344 = F_78 ( V_164 -> V_165 , V_213 , V_354 ) ;
switch ( V_344 ) {
case V_355 :
case V_356 :
case V_357 :
case V_358 :
V_236 -> V_359 = V_360 ;
break;
default:
V_236 -> V_359 = V_361 ;
}
}
V_193 -> V_209 . V_362 = F_78 ( V_164 -> V_165 , V_213 , V_363 ) ;
if ( ! F_78 ( V_164 -> V_165 , V_213 , V_334 ) ) {
F_34 ( V_236 -> V_241 , V_242 ,
V_364 , 1 ) ;
return 0 ;
}
F_34 ( V_236 -> V_241 , V_242 ,
V_364 , 0 ) ;
if ( V_9 -> V_2 -> V_69 -> V_70 & V_365 )
F_34 ( V_236 -> V_241 , V_242 ,
V_366 , 1 ) ;
V_342 = F_78 ( V_164 -> V_165 , V_213 , V_367 ) ;
V_343 = F_78 ( V_164 -> V_165 , V_213 , V_368 ) ;
F_2 ( L_24 , V_342 , V_343 ) ;
if ( ! V_342 || ! V_343 ) {
if ( ( V_343 == 0x09 ) &&
( V_69 -> V_70 & V_369 ) ) {
F_34 ( V_236 -> V_241 , V_242 ,
V_302 , 1 ) ;
V_236 -> V_305 = F_78 ( V_164 -> V_194 ,
V_370 ,
V_371 ) ;
F_2 ( L_25 , V_236 -> V_305 ) ;
}
} else {
if ( ( V_343 == 0x05 ) || ( V_343 == 0x06 ) )
F_34 ( V_236 -> V_241 , V_242 ,
V_366 , 0 ) ;
else
F_34 ( V_236 -> V_372 , V_373 ,
V_374 , 1 ) ;
}
F_2 ( L_26 , V_9 -> V_341 ,
V_198 -> V_200 & ( V_198 -> V_201 - 1 ) , V_198 -> V_200 ) ;
return 0 ;
}
static int F_128 ( struct V_163 * V_164 )
{
return F_78 ( V_164 -> V_165 , V_166 , V_313 ) ;
}
static int F_129 ( struct V_163 * V_164 )
{
return F_78 ( V_164 -> V_165 , V_166 , V_334 ) ;
}
static int F_130 ( struct V_8 * V_9 ,
enum V_375 V_376 )
{
unsigned int V_91 ;
V_91 = F_49 ( V_9 , V_93 ) ;
switch ( V_376 ) {
case V_377 :
F_34 ( V_91 , V_93 , V_98 , 1 ) ;
break;
case V_378 :
F_34 ( V_91 , V_93 , V_379 , 1 ) ;
break;
case V_380 :
F_34 ( V_91 , V_93 , V_381 , 1 ) ;
break;
case V_382 :
F_34 ( V_91 , V_93 , V_100 , 1 ) ;
break;
case V_383 :
F_34 ( V_91 , V_93 , V_99 , 1 ) ;
break;
case V_384 :
F_34 ( V_91 , V_93 , V_385 , 1 ) ;
break;
case V_386 :
F_34 ( V_91 , V_93 , V_98 , 1 ) ;
F_34 ( V_91 , V_93 , V_100 , 1 ) ;
break;
case V_387 :
F_34 ( V_91 , V_93 , V_96 , 1 ) ;
break;
case V_388 :
V_91 |= V_9 -> V_389 ;
break;
default:
return - 1 ;
}
F_50 ( V_9 , V_93 , V_91 ) ;
return 0 ;
}
static int F_131 ( struct V_8 * V_9 ,
enum V_375 V_376 )
{
unsigned int V_91 ;
V_91 = F_49 ( V_9 , V_93 ) ;
switch ( V_376 ) {
case V_377 :
F_34 ( V_91 , V_93 , V_98 , 0 ) ;
break;
case V_378 :
F_34 ( V_91 , V_93 , V_379 , 0 ) ;
break;
case V_380 :
F_34 ( V_91 , V_93 , V_381 , 0 ) ;
break;
case V_382 :
F_34 ( V_91 , V_93 , V_100 , 0 ) ;
break;
case V_383 :
F_34 ( V_91 , V_93 , V_99 , 0 ) ;
break;
case V_384 :
F_34 ( V_91 , V_93 , V_385 , 0 ) ;
break;
case V_386 :
F_34 ( V_91 , V_93 , V_98 , 0 ) ;
F_34 ( V_91 , V_93 , V_100 , 0 ) ;
break;
case V_387 :
F_34 ( V_91 , V_93 , V_96 , 0 ) ;
break;
case V_388 :
V_9 -> V_389 = V_91 & V_390 ;
V_91 &= ~ V_390 ;
break;
default:
return - 1 ;
}
F_50 ( V_9 , V_93 , V_91 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
unsigned int V_391 = 2000 ;
F_2 ( L_27 ) ;
F_22 ( V_2 , V_392 , V_393 , 1 ) ;
F_27 ( 10 , 15 ) ;
while ( V_391 -- && F_25 ( V_2 , V_392 , V_393 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_391 )
return - V_48 ;
F_2 ( L_28 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 )
{
unsigned int V_10 , V_391 ;
if ( F_105 ( V_2 -> V_63 . V_394 , V_395 , V_396 ) < 0x21 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_397 , 1 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ ) {
V_391 = 2000 ;
while ( V_391 -- && F_134 ( V_2 , V_10 ,
V_29 , V_397 ) )
F_27 ( 500 , 600 ) ;
if ( ! V_391 )
return - V_48 ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_398 , V_399 , 1 ) ;
F_22 ( V_2 , V_398 , UNDEF , 1 ) ;
F_22 ( V_2 , V_398 , V_400 , 1 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
unsigned int V_401 , V_402 ;
V_401 = 0 ;
F_34 ( V_401 , V_403 , V_404 , V_2 -> V_401 ) ;
F_34 ( V_401 , V_403 , V_405 , V_2 -> V_406 ) ;
F_34 ( V_401 , V_403 , V_407 , V_2 -> V_401 ) ;
F_34 ( V_401 , V_403 , V_408 , V_2 -> V_406 ) ;
F_34 ( V_401 , V_403 , V_409 , V_2 -> V_401 ) ;
F_34 ( V_401 , V_403 , V_410 , V_2 -> V_406 ) ;
F_26 ( V_2 , V_403 , V_401 ) ;
V_402 = 0 ;
F_34 ( V_402 , V_411 , V_412 , V_2 -> V_402 ) ;
F_34 ( V_402 , V_411 , V_413 , V_2 -> V_406 ) ;
F_34 ( V_402 , V_411 , V_414 , V_2 -> V_402 ) ;
F_34 ( V_402 , V_411 , V_415 , V_2 -> V_406 ) ;
F_34 ( V_402 , V_411 , V_416 , V_2 -> V_402 ) ;
F_34 ( V_402 , V_411 , V_417 , V_2 -> V_406 ) ;
F_34 ( V_402 , V_411 , V_418 , V_2 -> V_402 ) ;
F_34 ( V_402 , V_411 , V_419 , V_2 -> V_406 ) ;
F_26 ( V_2 , V_411 , V_402 ) ;
}
static void F_137 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
F_22 ( V_2 , V_262 , V_263 , V_420 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_63 . V_266 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_269 , V_238 ,
V_273 ) ;
F_13 ( V_2 , V_10 , V_274 , V_275 , 1 ) ;
}
F_22 ( V_2 , V_262 , V_421 , V_422 ) ;
}
static unsigned int F_138 ( unsigned int V_423 ,
unsigned int V_424 )
{
unsigned int V_425 = 0 ;
enum V_426 V_427 = V_428 ;
switch ( V_423 ) {
case 0 :
V_425 = F_139 ( 128 ) ;
break;
case 1 :
V_425 = F_139 ( 256 ) ;
break;
case 2 :
V_425 = F_139 ( 512 ) ;
break;
case 3 :
V_425 = F_140 ( 1 ) ;
break;
case 4 :
V_425 = F_140 ( 2 ) ;
break;
case 5 :
V_425 = F_140 ( 4 ) ;
break;
case 6 :
V_425 = F_140 ( 8 ) ;
break;
case 7 :
V_425 = F_140 ( 16 ) ;
break;
case 8 :
V_425 = F_140 ( 32 ) ;
break;
case 9 :
V_425 = F_140 ( 64 ) ;
break;
case 10 :
V_425 = F_140 ( 128 ) ;
break;
case 11 :
V_425 = F_140 ( 256 ) ;
break;
}
V_425 = F_40 (unsigned int, XGBE_FIFO_MAX, q_fifo_size) ;
V_425 = V_425 / V_424 ;
if ( V_425 >= F_140 ( 256 ) )
V_427 = V_429 ;
else if ( V_425 >= F_140 ( 128 ) )
V_427 = V_430 ;
else if ( V_425 >= F_140 ( 64 ) )
V_427 = V_431 ;
else if ( V_425 >= F_140 ( 32 ) )
V_427 = V_432 ;
else if ( V_425 >= F_140 ( 16 ) )
V_427 = V_433 ;
else if ( V_425 >= F_140 ( 8 ) )
V_427 = V_434 ;
else if ( V_425 >= F_140 ( 4 ) )
V_427 = V_435 ;
else if ( V_425 >= F_140 ( 2 ) )
V_427 = V_436 ;
else if ( V_425 >= F_140 ( 1 ) )
V_427 = V_437 ;
else if ( V_425 >= F_139 ( 512 ) )
V_427 = V_438 ;
else if ( V_425 >= F_139 ( 256 ) )
V_427 = V_428 ;
return V_427 ;
}
static void F_141 ( struct V_1 * V_2 )
{
enum V_426 V_423 ;
unsigned int V_10 ;
V_423 = F_138 ( V_2 -> V_63 . V_439 ,
V_2 -> V_28 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_440 , V_423 ) ;
F_142 ( V_2 -> V_69 ,
L_29 ,
V_2 -> V_28 , ( ( V_423 + 1 ) * 256 ) ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
enum V_426 V_423 ;
unsigned int V_10 ;
V_423 = F_138 ( V_2 -> V_63 . V_441 ,
V_2 -> V_25 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_26 , V_442 , V_423 ) ;
F_142 ( V_2 -> V_69 ,
L_30 ,
V_2 -> V_25 , ( ( V_423 + 1 ) * 256 ) ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
unsigned int V_443 , V_444 , V_445 ;
unsigned int V_446 ;
unsigned int V_447 , V_448 , V_278 ;
unsigned int V_276 ;
unsigned int V_10 , V_449 , V_74 , V_75 ;
V_443 = V_2 -> V_28 / V_2 -> V_63 . V_266 ;
V_444 = V_2 -> V_28 % V_2 -> V_63 . V_266 ;
for ( V_10 = 0 , V_445 = 0 ; V_10 < V_2 -> V_63 . V_266 ; V_10 ++ ) {
for ( V_449 = 0 ; V_449 < V_443 ; V_449 ++ ) {
F_2 ( L_31 , V_445 , V_10 ) ;
F_13 ( V_2 , V_445 , V_29 ,
V_450 , V_10 ) ;
V_2 -> V_451 [ V_445 ++ ] = V_10 ;
}
if ( V_10 < V_444 ) {
F_2 ( L_31 , V_445 , V_10 ) ;
F_13 ( V_2 , V_445 , V_29 ,
V_450 , V_10 ) ;
V_2 -> V_451 [ V_445 ++ ] = V_10 ;
}
}
V_446 = F_40 (unsigned int, IEEE_8021QAZ_MAX_TCS,
pdata->rx_q_count) ;
V_447 = V_279 / V_446 ;
V_448 = V_279 % V_446 ;
V_74 = V_452 ;
V_75 = 0 ;
for ( V_10 = 0 , V_278 = 0 ; V_10 < V_446 ; ) {
V_276 = 0 ;
for ( V_449 = 0 ; V_449 < V_447 ; V_449 ++ ) {
F_2 ( L_32 , V_278 , V_10 ) ;
V_276 |= ( 1 << V_278 ) ;
V_2 -> V_453 [ V_278 ++ ] = V_10 ;
}
if ( V_10 < V_448 ) {
F_2 ( L_32 , V_278 , V_10 ) ;
V_276 |= ( 1 << V_278 ) ;
V_2 -> V_453 [ V_278 ++ ] = V_10 ;
}
V_75 |= ( V_276 << ( ( V_10 ++ % V_454 ) << 3 ) ) ;
if ( ( V_10 % V_454 ) && ( V_10 != V_446 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_455 ;
V_75 = 0 ;
}
V_74 = V_456 ;
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; ) {
V_75 |= ( 0x80 << ( ( V_10 ++ % V_457 ) << 3 ) ) ;
if ( ( V_10 % V_457 ) && ( V_10 != V_2 -> V_25 ) )
continue;
F_26 ( V_2 , V_74 , V_75 ) ;
V_74 += V_458 ;
V_75 = 0 ;
}
}
static void F_145 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ ) {
F_13 ( V_2 , V_10 , V_459 , V_460 , 2 ) ;
F_13 ( V_2 , V_10 , V_459 , V_461 , 4 ) ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
F_71 ( V_2 , V_2 -> V_69 -> V_462 ) ;
if ( V_2 -> V_63 . V_137 ) {
F_22 ( V_2 , V_115 , V_463 , 1 ) ;
F_22 ( V_2 , V_115 , V_464 , 1 ) ;
F_22 ( V_2 , V_115 , V_465 , 1 ) ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
unsigned int V_24 ;
V_24 = ( V_2 -> V_69 -> V_265 > V_466 ) ? 1 : 0 ;
F_22 ( V_2 , V_40 , V_467 , V_24 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_468 ) {
case V_469 :
F_58 ( V_2 ) ;
break;
case V_470 :
F_57 ( V_2 ) ;
break;
case V_471 :
F_56 ( V_2 ) ;
break;
}
}
static void F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 -> V_70 & V_365 )
F_80 ( V_2 ) ;
else
F_79 ( V_2 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_472 , V_473 , 0 ) ;
F_22 ( V_2 , V_472 , V_474 , 1 ) ;
F_87 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_475 )
F_83 ( V_2 ) ;
else
F_84 ( V_2 ) ;
if ( V_2 -> V_69 -> V_70 & V_369 )
F_81 ( V_2 ) ;
else
F_82 ( V_2 ) ;
}
static T_4 F_151 ( struct V_1 * V_2 , unsigned int V_476 )
{
bool V_477 ;
T_4 V_24 ;
switch ( V_476 ) {
case V_478 :
case V_479 :
case V_480 :
case V_481 :
V_477 = true ;
break;
default:
V_477 = false ;
} ;
V_24 = F_41 ( V_2 , V_476 ) ;
if ( V_477 )
V_24 |= ( ( T_4 ) F_41 ( V_2 , V_476 + 4 ) << 32 ) ;
return V_24 ;
}
static void F_152 ( struct V_1 * V_2 )
{
struct V_482 * V_483 = & V_2 -> V_484 ;
unsigned int V_485 = F_41 ( V_2 , V_486 ) ;
if ( F_105 ( V_485 , V_486 , V_487 ) )
V_483 -> V_488 +=
F_151 ( V_2 , V_478 ) ;
if ( F_105 ( V_485 , V_486 , V_489 ) )
V_483 -> V_490 +=
F_151 ( V_2 , V_491 ) ;
if ( F_105 ( V_485 , V_486 , V_492 ) )
V_483 -> V_493 +=
F_151 ( V_2 , V_494 ) ;
if ( F_105 ( V_485 , V_486 , V_495 ) )
V_483 -> V_496 +=
F_151 ( V_2 , V_497 ) ;
if ( F_105 ( V_485 , V_486 , V_498 ) )
V_483 -> V_499 +=
F_151 ( V_2 , V_500 ) ;
if ( F_105 ( V_485 , V_486 , V_501 ) )
V_483 -> V_502 +=
F_151 ( V_2 , V_503 ) ;
if ( F_105 ( V_485 , V_486 , V_504 ) )
V_483 -> V_505 +=
F_151 ( V_2 , V_506 ) ;
if ( F_105 ( V_485 , V_486 , V_507 ) )
V_483 -> V_508 +=
F_151 ( V_2 , V_509 ) ;
if ( F_105 ( V_485 , V_486 , V_510 ) )
V_483 -> V_511 +=
F_151 ( V_2 , V_512 ) ;
if ( F_105 ( V_485 , V_486 , V_513 ) )
V_483 -> V_514 +=
F_151 ( V_2 , V_515 ) ;
if ( F_105 ( V_485 , V_486 , V_516 ) )
V_483 -> V_517 +=
F_151 ( V_2 , V_518 ) ;
if ( F_105 ( V_485 , V_486 , V_519 ) )
V_483 -> V_520 +=
F_151 ( V_2 , V_521 ) ;
if ( F_105 ( V_485 , V_486 , V_522 ) )
V_483 -> V_493 +=
F_151 ( V_2 , V_523 ) ;
if ( F_105 ( V_485 , V_486 , V_524 ) )
V_483 -> V_525 +=
F_151 ( V_2 , V_526 ) ;
if ( F_105 ( V_485 , V_486 , V_527 ) )
V_483 -> V_528 +=
F_151 ( V_2 , V_479 ) ;
if ( F_105 ( V_485 , V_486 , V_529 ) )
V_483 -> V_530 +=
F_151 ( V_2 , V_531 ) ;
if ( F_105 ( V_485 , V_486 , V_532 ) )
V_483 -> V_533 +=
F_151 ( V_2 , V_534 ) ;
if ( F_105 ( V_485 , V_486 , V_535 ) )
V_483 -> V_536 +=
F_151 ( V_2 , V_537 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_482 * V_483 = & V_2 -> V_484 ;
unsigned int V_485 = F_41 ( V_2 , V_538 ) ;
if ( F_105 ( V_485 , V_538 , V_539 ) )
V_483 -> V_540 +=
F_151 ( V_2 , V_541 ) ;
if ( F_105 ( V_485 , V_538 , V_542 ) )
V_483 -> V_543 +=
F_151 ( V_2 , V_480 ) ;
if ( F_105 ( V_485 , V_538 , V_544 ) )
V_483 -> V_545 +=
F_151 ( V_2 , V_481 ) ;
if ( F_105 ( V_485 , V_538 , V_546 ) )
V_483 -> V_547 +=
F_151 ( V_2 , V_548 ) ;
if ( F_105 ( V_485 , V_538 , V_549 ) )
V_483 -> V_550 +=
F_151 ( V_2 , V_551 ) ;
if ( F_105 ( V_485 , V_538 , V_552 ) )
V_483 -> V_553 +=
F_151 ( V_2 , V_554 ) ;
if ( F_105 ( V_485 , V_538 , V_555 ) )
V_483 -> V_556 +=
F_151 ( V_2 , V_557 ) ;
if ( F_105 ( V_485 , V_538 , V_558 ) )
V_483 -> V_559 +=
F_151 ( V_2 , V_560 ) ;
if ( F_105 ( V_485 , V_538 , V_561 ) )
V_483 -> V_562 +=
F_151 ( V_2 , V_563 ) ;
if ( F_105 ( V_485 , V_538 , V_564 ) )
V_483 -> V_565 +=
F_151 ( V_2 , V_566 ) ;
if ( F_105 ( V_485 , V_538 , V_567 ) )
V_483 -> V_568 +=
F_151 ( V_2 , V_569 ) ;
if ( F_105 ( V_485 , V_538 , V_570 ) )
V_483 -> V_571 +=
F_151 ( V_2 , V_572 ) ;
if ( F_105 ( V_485 , V_538 , V_573 ) )
V_483 -> V_574 +=
F_151 ( V_2 , V_575 ) ;
if ( F_105 ( V_485 , V_538 , V_576 ) )
V_483 -> V_577 +=
F_151 ( V_2 , V_578 ) ;
if ( F_105 ( V_485 , V_538 , V_579 ) )
V_483 -> V_580 +=
F_151 ( V_2 , V_581 ) ;
if ( F_105 ( V_485 , V_538 , V_582 ) )
V_483 -> V_583 +=
F_151 ( V_2 , V_584 ) ;
if ( F_105 ( V_485 , V_538 , V_585 ) )
V_483 -> V_586 +=
F_151 ( V_2 , V_587 ) ;
if ( F_105 ( V_485 , V_538 , V_588 ) )
V_483 -> V_589 +=
F_151 ( V_2 , V_590 ) ;
if ( F_105 ( V_485 , V_538 , V_591 ) )
V_483 -> V_592 +=
F_151 ( V_2 , V_593 ) ;
if ( F_105 ( V_485 , V_538 , V_594 ) )
V_483 -> V_595 +=
F_151 ( V_2 , V_596 ) ;
if ( F_105 ( V_485 , V_538 , V_597 ) )
V_483 -> V_598 +=
F_151 ( V_2 , V_599 ) ;
if ( F_105 ( V_485 , V_538 , V_600 ) )
V_483 -> V_601 +=
F_151 ( V_2 , V_602 ) ;
if ( F_105 ( V_485 , V_538 , V_603 ) )
V_483 -> V_604 +=
F_151 ( V_2 , V_605 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_482 * V_483 = & V_2 -> V_484 ;
F_22 ( V_2 , V_606 , V_607 , 1 ) ;
V_483 -> V_488 +=
F_151 ( V_2 , V_478 ) ;
V_483 -> V_490 +=
F_151 ( V_2 , V_491 ) ;
V_483 -> V_493 +=
F_151 ( V_2 , V_494 ) ;
V_483 -> V_496 +=
F_151 ( V_2 , V_497 ) ;
V_483 -> V_499 +=
F_151 ( V_2 , V_500 ) ;
V_483 -> V_502 +=
F_151 ( V_2 , V_503 ) ;
V_483 -> V_505 +=
F_151 ( V_2 , V_506 ) ;
V_483 -> V_508 +=
F_151 ( V_2 , V_509 ) ;
V_483 -> V_511 +=
F_151 ( V_2 , V_512 ) ;
V_483 -> V_514 +=
F_151 ( V_2 , V_515 ) ;
V_483 -> V_517 +=
F_151 ( V_2 , V_518 ) ;
V_483 -> V_520 +=
F_151 ( V_2 , V_521 ) ;
V_483 -> V_493 +=
F_151 ( V_2 , V_523 ) ;
V_483 -> V_525 +=
F_151 ( V_2 , V_526 ) ;
V_483 -> V_528 +=
F_151 ( V_2 , V_479 ) ;
V_483 -> V_530 +=
F_151 ( V_2 , V_531 ) ;
V_483 -> V_533 +=
F_151 ( V_2 , V_534 ) ;
V_483 -> V_536 +=
F_151 ( V_2 , V_537 ) ;
V_483 -> V_540 +=
F_151 ( V_2 , V_541 ) ;
V_483 -> V_543 +=
F_151 ( V_2 , V_480 ) ;
V_483 -> V_545 +=
F_151 ( V_2 , V_481 ) ;
V_483 -> V_547 +=
F_151 ( V_2 , V_548 ) ;
V_483 -> V_550 +=
F_151 ( V_2 , V_551 ) ;
V_483 -> V_553 +=
F_151 ( V_2 , V_554 ) ;
V_483 -> V_556 +=
F_151 ( V_2 , V_557 ) ;
V_483 -> V_559 +=
F_151 ( V_2 , V_560 ) ;
V_483 -> V_562 +=
F_151 ( V_2 , V_563 ) ;
V_483 -> V_565 +=
F_151 ( V_2 , V_566 ) ;
V_483 -> V_568 +=
F_151 ( V_2 , V_569 ) ;
V_483 -> V_571 +=
F_151 ( V_2 , V_572 ) ;
V_483 -> V_574 +=
F_151 ( V_2 , V_575 ) ;
V_483 -> V_577 +=
F_151 ( V_2 , V_578 ) ;
V_483 -> V_580 +=
F_151 ( V_2 , V_581 ) ;
V_483 -> V_583 +=
F_151 ( V_2 , V_584 ) ;
V_483 -> V_586 +=
F_151 ( V_2 , V_587 ) ;
V_483 -> V_589 +=
F_151 ( V_2 , V_590 ) ;
V_483 -> V_592 +=
F_151 ( V_2 , V_593 ) ;
V_483 -> V_595 +=
F_151 ( V_2 , V_596 ) ;
V_483 -> V_598 +=
F_151 ( V_2 , V_599 ) ;
V_483 -> V_601 +=
F_151 ( V_2 , V_602 ) ;
V_483 -> V_604 +=
F_151 ( V_2 , V_605 ) ;
F_22 ( V_2 , V_606 , V_607 , 0 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_606 , V_608 , 1 ) ;
F_22 ( V_2 , V_606 , V_609 , 1 ) ;
}
static void F_156 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
unsigned int V_610 , V_611 , V_612 ;
unsigned int V_613 ;
unsigned long V_614 ;
if ( V_9 -> V_340 < V_615 ) {
V_610 = V_616 ;
V_611 = ( V_9 -> V_340 * V_617 ) +
V_618 ;
} else {
V_612 = V_9 -> V_340 - V_615 ;
V_610 = V_619 + ( ( V_612 / V_620 ) * V_621 ) ;
V_611 = ( ( V_612 % V_620 ) * V_617 ) +
V_622 ;
}
V_614 = V_288 + ( V_623 * V_624 ) ;
while ( F_157 ( V_288 , V_614 ) ) {
V_613 = F_41 ( V_2 , V_610 ) ;
V_613 = F_158 ( V_613 , V_611 , V_625 ) ;
if ( ( V_613 == V_626 ) ||
( V_613 == V_627 ) )
break;
F_27 ( 500 , 1000 ) ;
}
if ( ! F_157 ( V_288 , V_614 ) )
F_159 ( V_2 -> V_69 ,
L_33 ,
V_9 -> V_340 ) ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_628 , 1 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_629 ,
V_630 ) ;
F_22 ( V_2 , V_112 , V_631 , 1 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_156 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_112 , V_631 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_28 ; V_10 ++ )
F_13 ( V_2 , V_10 , V_29 , V_629 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_628 , 0 ) ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_75 , V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_632 , 1 ) ;
}
V_75 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_25 ; V_10 ++ )
V_75 |= ( 0x02 << ( V_10 << 1 ) ) ;
F_26 ( V_2 , V_633 , V_75 ) ;
F_22 ( V_2 , V_40 , V_634 , 1 ) ;
F_22 ( V_2 , V_40 , V_635 , 1 ) ;
F_22 ( V_2 , V_40 , V_636 , 1 ) ;
F_22 ( V_2 , V_40 , V_637 , 1 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
F_22 ( V_2 , V_40 , V_634 , 0 ) ;
F_22 ( V_2 , V_40 , V_635 , 0 ) ;
F_22 ( V_2 , V_40 , V_636 , 0 ) ;
F_22 ( V_2 , V_40 , V_637 , 0 ) ;
F_26 ( V_2 , V_633 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_632 , 0 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_628 , 1 ) ;
}
F_22 ( V_2 , V_112 , V_631 , 1 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_156 ( V_2 , V_9 ) ;
}
F_22 ( V_2 , V_112 , V_631 , 0 ) ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_17 )
break;
F_5 ( V_9 , V_15 , V_628 , 0 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_632 , 1 ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_10 ;
V_9 = V_2 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_11 ; V_10 ++ , V_9 ++ ) {
if ( ! V_9 -> V_20 )
break;
F_5 ( V_9 , V_19 , V_632 , 0 ) ;
}
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_638 * V_639 = & V_2 -> V_639 ;
int V_5 ;
F_2 ( L_34 ) ;
V_5 = F_133 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_135 ( V_2 ) ;
F_136 ( V_2 ) ;
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
V_639 -> V_640 ( V_2 ) ;
V_639 -> V_641 ( V_2 ) ;
F_48 ( V_2 ) ;
F_137 ( V_2 ) ;
F_144 ( V_2 ) ;
F_14 ( V_2 , V_2 -> V_642 ) ;
F_12 ( V_2 , V_2 -> V_643 ) ;
F_16 ( V_2 , V_2 -> V_644 ) ;
F_15 ( V_2 , V_2 -> V_645 ) ;
F_141 ( V_2 ) ;
F_143 ( V_2 ) ;
F_145 ( V_2 ) ;
F_112 ( V_2 ) ;
F_114 ( V_2 ) ;
F_51 ( V_2 ) ;
F_146 ( V_2 ) ;
F_72 ( V_2 ) ;
F_147 ( V_2 ) ;
F_47 ( V_2 ) ;
F_148 ( V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
F_155 ( V_2 ) ;
F_55 ( V_2 ) ;
F_2 ( L_35 ) ;
return 0 ;
}
void F_169 ( struct V_646 * V_647 )
{
F_2 ( L_36 ) ;
V_647 -> V_648 = F_77 ;
V_647 -> V_649 = F_71 ;
V_647 -> V_650 = F_72 ;
V_647 -> V_651 = F_80 ;
V_647 -> V_652 = F_79 ;
V_647 -> V_653 = F_81 ;
V_647 -> V_654 = F_82 ;
V_647 -> V_655 = F_83 ;
V_647 -> V_656 = F_84 ;
V_647 -> V_657 = F_87 ;
V_647 -> V_658 = F_73 ;
V_647 -> V_659 = F_76 ;
V_647 -> V_660 = F_56 ;
V_647 -> V_661 = F_57 ;
V_647 -> V_662 = F_58 ;
V_647 -> V_663 = F_160 ;
V_647 -> V_664 = F_161 ;
V_647 -> V_665 = F_162 ;
V_647 -> V_666 = F_163 ;
V_647 -> V_667 = F_164 ;
V_647 -> V_668 = F_165 ;
V_647 -> V_669 = F_166 ;
V_647 -> V_670 = F_167 ;
V_647 -> V_671 = F_119 ;
V_647 -> V_672 = F_124 ;
V_647 -> V_673 = F_130 ;
V_647 -> V_674 = F_131 ;
V_647 -> V_675 = F_168 ;
V_647 -> exit = F_132 ;
V_647 -> V_676 = F_92 ;
V_647 -> V_677 = F_99 ;
V_647 -> V_678 = F_90 ;
V_647 -> V_679 = F_96 ;
V_647 -> V_680 = F_129 ;
V_647 -> V_681 = F_128 ;
V_647 -> V_682 = F_115 ;
V_647 -> V_683 = F_45 ;
V_647 -> V_684 = F_46 ;
V_647 -> V_685 = F_17 ;
V_647 -> V_686 = F_18 ;
V_647 -> V_687 = F_1 ;
V_647 -> V_688 = F_3 ;
V_647 -> V_689 = F_15 ;
V_647 -> V_690 = F_16 ;
V_647 -> V_691 = F_12 ;
V_647 -> V_692 = F_14 ;
V_647 -> V_693 = F_11 ;
V_647 -> V_694 = F_10 ;
V_647 -> V_695 = F_9 ;
V_647 -> V_696 = F_8 ;
V_647 -> V_697 = F_6 ;
V_647 -> V_698 = F_4 ;
V_647 -> V_699 = F_152 ;
V_647 -> V_700 = F_153 ;
V_647 -> V_701 = F_154 ;
V_647 -> V_702 = F_108 ;
V_647 -> V_703 = F_100 ;
V_647 -> V_704 = F_102 ;
V_647 -> V_705 = F_103 ;
V_647 -> V_706 = F_104 ;
V_647 -> V_707 = F_112 ;
V_647 -> V_708 = F_114 ;
V_647 -> V_709 = F_35 ;
V_647 -> V_710 = F_36 ;
V_647 -> V_711 = F_32 ;
V_647 -> V_712 = F_33 ;
F_2 ( L_37 ) ;
}
