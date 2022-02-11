static void F_1 ( void T_1 * V_1 , int V_2 )
{
T_2 V_3 = F_2 ( V_1 + V_4 ) ;
V_3 |= V_5 ;
if ( V_2 > 1500 )
V_3 |= V_6 ;
if ( V_2 > 2000 )
V_3 |= V_7 ;
F_3 ( V_3 , V_1 + V_4 ) ;
F_3 ( 0x207 , V_1 + V_8 ) ;
#ifdef F_4
F_3 ( 0x0 , V_1 + V_9 ) ;
#endif
}
static int F_5 ( void T_1 * V_1 )
{
T_2 V_3 = F_2 ( V_1 + V_4 ) ;
V_3 |= V_10 ;
F_3 ( V_3 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
return ! ! ( V_3 & V_10 ) ;
}
static void F_6 ( void T_1 * V_1 )
{
int V_11 ;
F_7 ( L_1 , V_1 ) ;
for ( V_11 = 0 ; V_11 < 55 ; V_11 ++ ) {
int V_12 = V_11 * 4 ;
F_7 ( L_2 , V_11 ,
V_12 , F_2 ( V_1 + V_12 ) ) ;
}
}
static void F_8 ( void T_1 * V_1 , unsigned char * V_13 ,
unsigned int V_14 )
{
F_9 ( V_1 , V_13 , F_10 ( V_14 ) ,
F_11 ( V_14 ) ) ;
}
static void F_12 ( void T_1 * V_1 , unsigned char * V_13 ,
unsigned int V_14 )
{
F_13 ( V_1 , V_13 , F_10 ( V_14 ) ,
F_11 ( V_14 ) ) ;
}
static void F_14 ( struct V_15 * V_16 , int V_17 )
{
void T_1 * V_1 = ( void T_1 * ) V_16 -> V_18 ;
unsigned int V_3 = 0 ;
unsigned int V_19 ;
F_15 ( L_3 , V_20 ,
F_16 ( V_16 ) , F_17 ( V_16 ) ) ;
if ( V_16 -> V_21 & V_22 )
V_3 = V_23 ;
else if ( ( F_16 ( V_16 ) > V_24 )
|| ( V_16 -> V_21 & V_25 ) ) {
V_3 = V_26 ;
F_3 ( 0xffffffff , V_1 + V_27 ) ;
F_3 ( 0xffffffff , V_1 + V_28 ) ;
} else if ( ! F_18 ( V_16 ) ) {
T_2 V_29 [ 2 ] ;
struct V_30 * V_31 ;
V_3 = V_32 ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
F_19 (ha, dev) {
int V_33 = F_20 ( ~ F_21 ( ~ 0 , V_31 -> V_13 , 6 ) ) >> 26 ;
V_29 [ V_33 >> 5 ] |= 1 << ( V_33 & 31 ) ;
}
F_3 ( V_29 [ 0 ] , V_1 + V_28 ) ;
F_3 ( V_29 [ 1 ] , V_1 + V_27 ) ;
}
if ( V_17 > V_34 )
V_19 = V_35 ;
else
V_19 = V_35 / 2 ;
if ( F_17 ( V_16 ) > V_19 )
V_3 |= V_23 ;
else {
int V_36 = 1 ;
struct V_30 * V_31 ;
F_22 (ha, dev) {
F_8 ( V_1 , V_31 -> V_13 , V_36 ) ;
V_36 ++ ;
}
}
#ifdef F_23
V_3 |= V_37 ;
#endif
F_3 ( V_3 , V_1 + V_38 ) ;
F_15 ( L_4 ,
F_2 ( V_1 + V_38 ) ,
F_2 ( V_1 + V_27 ) , F_2 ( V_1 + V_28 ) ) ;
}
static void F_24 ( void T_1 * V_1 , unsigned int V_39 ,
unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_42 = 0 ;
F_15 ( L_5 ) ;
if ( V_40 & V_43 ) {
F_15 ( L_6 ) ;
V_42 |= V_44 ;
}
if ( V_40 & V_45 ) {
F_15 ( L_7 ) ;
V_42 |= V_46 ;
}
if ( V_39 ) {
F_15 ( L_8 , V_41 ) ;
V_42 |= ( V_41 << V_47 ) ;
}
F_3 ( V_42 , V_1 + V_48 ) ;
}
static void F_25 ( void T_1 * V_1 , unsigned long V_49 )
{
unsigned int V_50 = 0 ;
if ( V_49 & V_51 ) {
F_15 ( L_9 ) ;
V_50 |= V_52 | V_53 ;
}
if ( V_49 & V_54 ) {
F_15 ( L_10 ) ;
V_50 |= V_55 ;
}
F_3 ( V_50 , V_1 + V_56 ) ;
}
static int F_26 ( void T_1 * V_1 ,
struct V_57 * V_58 )
{
T_2 V_59 = F_2 ( V_1 + V_60 ) ;
int V_61 = 0 ;
if ( ( V_59 & V_62 ) )
V_58 -> V_63 ++ ;
if ( F_27 ( V_59 & V_64 ) )
V_58 -> V_65 ++ ;
if ( F_27 ( V_59 & V_66 ) )
V_58 -> V_67 ++ ;
if ( F_27 ( V_59 & V_68 ) ) {
F_2 ( V_1 + V_56 ) ;
V_58 -> V_69 ++ ;
}
if ( V_59 & V_70 ) {
V_61 = F_2 ( V_1 + V_71 ) ;
if ( V_61 & V_72 )
V_58 -> V_73 ++ ;
if ( V_61 & V_74 )
V_58 -> V_75 ++ ;
if ( V_61 & V_76 )
V_58 -> V_77 ++ ;
if ( V_61 & V_78 )
V_58 -> V_79 ++ ;
}
if ( ( V_59 & V_80 ) || ( V_59 & V_81 ) ) {
F_2 ( V_1 + V_82 ) ;
V_58 -> V_83 ++ ;
}
if ( V_59 & V_84 ) {
T_2 V_85 = F_2 ( V_1 + V_86 ) ;
V_58 -> V_87 ++ ;
if ( V_85 & V_88 ) {
int V_89 = ( V_85 & V_90 ) >>
V_91 ;
V_58 -> V_92 = ( V_85 & V_93 ) ;
if ( V_89 == V_94 )
V_58 -> V_95 = V_96 ;
else if ( V_89 == V_97 )
V_58 -> V_95 = V_98 ;
else
V_58 -> V_95 = V_99 ;
V_58 -> V_100 = 1 ;
F_15 ( L_11 , V_20 ,
( int ) V_58 -> V_95 ,
V_58 -> V_92 ? L_12 : L_13 ) ;
} else {
V_58 -> V_100 = 0 ;
F_15 ( L_14 , V_20 ) ;
}
}
return V_61 ;
}
static void F_28 ( void T_1 * V_1 )
{
T_2 V_3 ;
V_3 = F_2 ( V_1 + V_71 ) ;
V_3 |= V_101 | V_102 ;
F_3 ( V_3 , V_1 + V_71 ) ;
}
static void F_29 ( void T_1 * V_1 )
{
T_2 V_3 ;
V_3 = F_2 ( V_1 + V_71 ) ;
V_3 &= ~ ( V_101 | V_102 ) ;
F_3 ( V_3 , V_1 + V_71 ) ;
}
static void F_30 ( void T_1 * V_1 , int V_103 )
{
T_2 V_3 ;
V_3 = F_2 ( V_1 + V_71 ) ;
if ( V_103 )
V_3 |= V_104 ;
else
V_3 &= ~ V_104 ;
F_3 ( V_3 , V_1 + V_71 ) ;
}
static void F_31 ( void T_1 * V_1 , int V_105 , int V_106 )
{
int V_3 = ( ( V_106 & 0xffff ) ) | ( ( V_105 & 0x7ff ) << 16 ) ;
F_3 ( V_3 , V_1 + V_107 ) ;
}
static void F_32 ( void T_1 * V_1 , bool V_108 )
{
T_2 V_3 = V_109 | V_110 ;
if ( V_108 )
V_3 |= V_111 ;
F_3 ( V_3 , V_1 + V_112 ) ;
}
static void F_33 ( void T_1 * V_1 , struct V_113 * V_114 )
{
T_2 V_3 = F_2 ( V_1 + V_115 ) ;
if ( V_3 & V_116 )
V_114 -> V_39 = V_117 ;
if ( V_3 & V_118 )
V_114 -> V_39 |= V_119 ;
V_114 -> V_120 = ( V_3 & V_121 ) >> V_122 ;
V_3 = F_2 ( V_1 + V_123 ) ;
if ( V_3 & V_116 )
V_114 -> V_124 = V_117 ;
if ( V_3 & V_118 )
V_114 -> V_124 = V_119 ;
V_114 -> V_125 = ( V_3 & V_121 ) >> V_122 ;
}
struct V_126 * F_34 ( void T_1 * V_1 )
{
struct V_126 * V_127 ;
T_2 V_128 = F_2 ( V_1 + V_129 ) ;
V_127 = F_35 ( sizeof( const struct V_126 ) , V_130 ) ;
if ( ! V_127 )
return NULL ;
V_127 -> V_127 = & V_131 ;
V_127 -> V_132 = & V_133 ;
V_127 -> V_103 . V_134 = V_135 ;
V_127 -> V_103 . V_39 = V_136 ;
V_127 -> V_103 . V_137 = V_138 ;
V_127 -> V_139 . V_13 = V_140 ;
V_127 -> V_139 . V_141 = V_142 ;
V_127 -> V_143 = V_128 ;
return V_127 ;
}
