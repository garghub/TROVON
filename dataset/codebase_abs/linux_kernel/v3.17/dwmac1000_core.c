static void F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
V_6 |= V_8 ;
if ( V_3 > 1500 )
V_6 |= V_9 ;
if ( V_3 > 2000 )
V_6 |= V_10 ;
F_3 ( V_6 , V_4 + V_7 ) ;
F_3 ( 0x207 , V_4 + V_11 ) ;
#ifdef F_4
F_3 ( 0x0 , V_4 + V_12 ) ;
#endif
}
static int F_5 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_7 ) ;
if ( V_2 -> V_13 )
V_6 |= V_14 ;
else
V_6 &= ~ V_14 ;
F_3 ( V_6 , V_4 + V_7 ) ;
V_6 = F_2 ( V_4 + V_7 ) ;
return ! ! ( V_6 & V_14 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_15 ;
F_7 ( L_1 , V_4 ) ;
for ( V_15 = 0 ; V_15 < 55 ; V_15 ++ ) {
int V_16 = V_15 * 4 ;
F_7 ( L_2 , V_15 ,
V_16 , F_2 ( V_4 + V_16 ) ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char * V_17 ,
unsigned int V_18 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_9 ( V_4 , V_17 , F_10 ( V_18 ) ,
F_11 ( V_18 ) ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned char * V_17 ,
unsigned int V_18 )
{
void T_1 * V_4 = V_2 -> V_5 ;
F_13 ( V_4 , V_17 , F_10 ( V_18 ) ,
F_11 ( V_18 ) ) ;
}
static void F_14 ( void T_1 * V_4 , T_2 * V_19 ,
int V_20 )
{
int V_21 , V_22 ;
switch ( V_20 ) {
case 6 :
F_3 ( V_19 [ 0 ] , V_4 + V_23 ) ;
F_3 ( V_19 [ 1 ] , V_4 + V_24 ) ;
return;
break;
case 7 :
V_21 = 4 ;
break;
case 8 :
V_21 = 8 ;
break;
default:
F_15 ( L_3 ) ;
return;
break;
}
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ )
F_3 ( V_19 [ V_22 ] ,
V_4 + V_25 + V_22 * 4 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
void T_1 * V_4 = ( void T_1 * ) V_27 -> V_28 ;
unsigned int V_6 = 0 ;
unsigned int V_29 = V_2 -> V_30 ;
T_2 V_31 [ 2 ] ;
int V_20 = V_2 -> V_32 ;
F_15 ( L_4 , V_33 ,
F_17 ( V_27 ) , F_18 ( V_27 ) ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
if ( V_27 -> V_34 & V_35 ) {
V_6 = V_36 ;
} else if ( V_27 -> V_34 & V_37 ) {
V_6 = V_38 ;
} else if ( ! F_19 ( V_27 ) ) {
struct V_39 * V_40 ;
V_6 = V_41 ;
F_20 (ha, dev) {
int V_42 = F_21 ( ~ F_22 ( ~ 0 , V_40 -> V_17 ,
V_43 ) ) >>
( 32 - V_20 ) ;
V_31 [ V_42 >> 5 ] |= 1 << ( V_42 & 31 ) ;
}
}
F_14 ( V_4 , V_31 , V_20 ) ;
if ( F_18 ( V_27 ) > V_29 )
V_6 |= V_36 ;
else {
int V_44 = 1 ;
struct V_39 * V_40 ;
F_23 (ha, dev) {
F_13 ( V_4 , V_40 -> V_17 ,
F_10 ( V_44 ) ,
F_11 ( V_44 ) ) ;
V_44 ++ ;
}
}
#ifdef F_24
V_6 |= V_45 ;
#endif
F_3 ( V_6 , V_4 + V_46 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned int V_47 ,
unsigned int V_48 , unsigned int V_49 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_50 = 0 ;
F_15 ( L_5 ) ;
if ( V_48 & V_51 ) {
F_15 ( L_6 ) ;
V_50 |= V_52 ;
}
if ( V_48 & V_53 ) {
F_15 ( L_7 ) ;
V_50 |= V_54 ;
}
if ( V_47 ) {
F_15 ( L_8 , V_49 ) ;
V_50 |= ( V_49 << V_55 ) ;
}
F_3 ( V_50 , V_4 + V_56 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned long V_57 )
{
void T_1 * V_4 = V_2 -> V_5 ;
unsigned int V_58 = 0 ;
if ( V_57 & V_59 ) {
F_15 ( L_9 ) ;
V_58 |= V_60 | V_61 ;
}
if ( V_57 & V_62 ) {
F_15 ( L_10 ) ;
V_58 |= V_63 ;
}
F_3 ( V_58 , V_4 + V_64 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_67 = F_2 ( V_4 + V_68 ) ;
int V_69 = 0 ;
if ( ( V_67 & V_70 ) )
V_66 -> V_71 ++ ;
if ( F_28 ( V_67 & V_72 ) )
V_66 -> V_73 ++ ;
if ( F_28 ( V_67 & V_74 ) )
V_66 -> V_75 ++ ;
if ( F_28 ( V_67 & V_76 ) ) {
F_2 ( V_4 + V_64 ) ;
V_66 -> V_77 ++ ;
}
if ( V_67 & V_78 ) {
V_69 = F_2 ( V_4 + V_79 ) ;
if ( V_69 & V_80 )
V_66 -> V_81 ++ ;
if ( V_69 & V_82 )
V_66 -> V_83 ++ ;
if ( V_69 & V_84 )
V_66 -> V_85 ++ ;
if ( V_69 & V_86 )
V_66 -> V_87 ++ ;
}
if ( ( V_67 & V_88 ) || ( V_67 & V_89 ) ) {
F_2 ( V_4 + V_90 ) ;
V_66 -> V_91 ++ ;
}
if ( V_67 & V_92 ) {
T_2 V_93 = F_2 ( V_4 + V_94 ) ;
V_66 -> V_95 ++ ;
if ( V_93 & V_96 ) {
int V_97 = ( V_93 & V_98 ) >>
V_99 ;
V_66 -> V_100 = ( V_93 & V_101 ) ;
if ( V_97 == V_102 )
V_66 -> V_103 = V_104 ;
else if ( V_97 == V_105 )
V_66 -> V_103 = V_106 ;
else
V_66 -> V_103 = V_107 ;
V_66 -> V_108 = 1 ;
F_15 ( L_11 , V_33 ,
( int ) V_66 -> V_103 ,
V_66 -> V_100 ? L_12 : L_13 ) ;
} else {
V_66 -> V_108 = 0 ;
F_15 ( L_14 , V_33 ) ;
}
}
return V_69 ;
}
static void F_29 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_79 ) ;
V_6 |= V_109 | V_110 ;
F_3 ( V_6 , V_4 + V_79 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_79 ) ;
V_6 &= ~ ( V_109 | V_110 ) ;
F_3 ( V_6 , V_4 + V_79 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_111 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_4 + V_79 ) ;
if ( V_111 )
V_6 |= V_112 ;
else
V_6 &= ~ V_112 ;
F_3 ( V_6 , V_4 + V_79 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_113 , int V_114 )
{
void T_1 * V_4 = V_2 -> V_5 ;
int V_6 = ( ( V_114 & 0xffff ) ) | ( ( V_113 & 0x7ff ) << 16 ) ;
F_3 ( V_6 , V_4 + V_115 ) ;
}
static void F_33 ( struct V_1 * V_2 , bool V_116 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = V_117 | V_118 ;
if ( V_116 )
V_6 |= V_119 ;
F_3 ( V_6 , V_4 + V_120 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
void T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 = F_2 ( V_4 + V_123 ) ;
if ( V_6 & V_124 )
V_122 -> V_47 = V_125 ;
if ( V_6 & V_126 )
V_122 -> V_47 |= V_127 ;
V_122 -> V_128 = ( V_6 & V_129 ) >> V_130 ;
V_6 = F_2 ( V_4 + V_131 ) ;
if ( V_6 & V_124 )
V_122 -> V_132 = V_125 ;
if ( V_6 & V_126 )
V_122 -> V_132 = V_127 ;
V_122 -> V_133 = ( V_6 & V_129 ) >> V_130 ;
}
struct V_1 * F_35 ( void T_1 * V_4 , int V_134 ,
int V_135 )
{
struct V_1 * V_136 ;
T_2 V_137 = F_2 ( V_4 + V_138 ) ;
V_136 = F_36 ( sizeof( const struct V_1 ) , V_139 ) ;
if ( ! V_136 )
return NULL ;
V_136 -> V_5 = V_4 ;
V_136 -> V_140 = V_134 ;
V_136 -> V_30 = V_135 ;
V_136 -> V_32 = 0 ;
if ( V_136 -> V_140 )
V_136 -> V_32 = F_37 ( V_136 -> V_140 ) ;
V_136 -> V_136 = & V_141 ;
V_136 -> V_142 = & V_143 ;
V_136 -> V_111 . V_144 = V_145 ;
V_136 -> V_111 . V_47 = V_146 ;
V_136 -> V_111 . V_147 = V_148 ;
V_136 -> V_149 . V_17 = V_150 ;
V_136 -> V_149 . V_151 = V_152 ;
V_136 -> V_153 = V_137 ;
return V_136 ;
}
