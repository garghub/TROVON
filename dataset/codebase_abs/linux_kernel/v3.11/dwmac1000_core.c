static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_1 + V_3 ) ;
F_3 ( 0x207 , V_1 + V_5 ) ;
#ifdef F_4
F_3 ( 0x0 , V_1 + V_6 ) ;
#endif
}
static int F_5 ( void T_1 * V_1 )
{
T_2 V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_7 ;
F_3 ( V_2 , V_1 + V_3 ) ;
V_2 = F_2 ( V_1 + V_3 ) ;
return ! ! ( V_2 & V_7 ) ;
}
static void F_6 ( void T_1 * V_1 )
{
int V_8 ;
F_7 ( L_1 , V_1 ) ;
for ( V_8 = 0 ; V_8 < 55 ; V_8 ++ ) {
int V_9 = V_8 * 4 ;
F_7 ( L_2 , V_8 ,
V_9 , F_2 ( V_1 + V_9 ) ) ;
}
}
static void F_8 ( void T_1 * V_1 , unsigned char * V_10 ,
unsigned int V_11 )
{
F_9 ( V_1 , V_10 , F_10 ( V_11 ) ,
F_11 ( V_11 ) ) ;
}
static void F_12 ( void T_1 * V_1 , unsigned char * V_10 ,
unsigned int V_11 )
{
F_13 ( V_1 , V_10 , F_10 ( V_11 ) ,
F_11 ( V_11 ) ) ;
}
static void F_14 ( struct V_12 * V_13 , int V_14 )
{
void T_1 * V_1 = ( void T_1 * ) V_13 -> V_15 ;
unsigned int V_2 = 0 ;
unsigned int V_16 ;
F_15 ( L_3 , V_17 ,
F_16 ( V_13 ) , F_17 ( V_13 ) ) ;
if ( V_13 -> V_18 & V_19 )
V_2 = V_20 ;
else if ( ( F_16 ( V_13 ) > V_21 )
|| ( V_13 -> V_18 & V_22 ) ) {
V_2 = V_23 ;
F_3 ( 0xffffffff , V_1 + V_24 ) ;
F_3 ( 0xffffffff , V_1 + V_25 ) ;
} else if ( ! F_18 ( V_13 ) ) {
T_2 V_26 [ 2 ] ;
struct V_27 * V_28 ;
V_2 = V_29 ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
F_19 (ha, dev) {
int V_30 = F_20 ( ~ F_21 ( ~ 0 , V_28 -> V_10 , 6 ) ) >> 26 ;
V_26 [ V_30 >> 5 ] |= 1 << ( V_30 & 31 ) ;
}
F_3 ( V_26 [ 0 ] , V_1 + V_25 ) ;
F_3 ( V_26 [ 1 ] , V_1 + V_24 ) ;
}
if ( V_14 > V_31 )
V_16 = V_32 ;
else
V_16 = V_32 / 2 ;
if ( F_17 ( V_13 ) > V_16 )
V_2 |= V_20 ;
else {
int V_33 = 1 ;
struct V_27 * V_28 ;
F_22 (ha, dev) {
F_8 ( V_1 , V_28 -> V_10 , V_33 ) ;
V_33 ++ ;
}
}
#ifdef F_23
V_2 |= V_34 ;
#endif
F_3 ( V_2 , V_1 + V_35 ) ;
F_15 ( L_4 ,
F_2 ( V_1 + V_35 ) ,
F_2 ( V_1 + V_24 ) , F_2 ( V_1 + V_25 ) ) ;
}
static void F_24 ( void T_1 * V_1 , unsigned int V_36 ,
unsigned int V_37 , unsigned int V_38 )
{
unsigned int V_39 = 0 ;
F_15 ( L_5 ) ;
if ( V_37 & V_40 ) {
F_15 ( L_6 ) ;
V_39 |= V_41 ;
}
if ( V_37 & V_42 ) {
F_15 ( L_7 ) ;
V_39 |= V_43 ;
}
if ( V_36 ) {
F_15 ( L_8 , V_38 ) ;
V_39 |= ( V_38 << V_44 ) ;
}
F_3 ( V_39 , V_1 + V_45 ) ;
}
static void F_25 ( void T_1 * V_1 , unsigned long V_46 )
{
unsigned int V_47 = 0 ;
if ( V_46 & V_48 ) {
F_15 ( L_9 ) ;
V_47 |= V_49 | V_50 ;
}
if ( V_46 & V_51 ) {
F_15 ( L_10 ) ;
V_47 |= V_52 ;
}
F_3 ( V_47 , V_1 + V_53 ) ;
}
static int F_26 ( void T_1 * V_1 ,
struct V_54 * V_55 )
{
T_2 V_56 = F_2 ( V_1 + V_57 ) ;
int V_58 = 0 ;
if ( ( V_56 & V_59 ) )
V_55 -> V_60 ++ ;
if ( F_27 ( V_56 & V_61 ) )
V_55 -> V_62 ++ ;
if ( F_27 ( V_56 & V_63 ) )
V_55 -> V_64 ++ ;
if ( F_27 ( V_56 & V_65 ) ) {
F_2 ( V_1 + V_53 ) ;
V_55 -> V_66 ++ ;
}
if ( V_56 & V_67 ) {
V_58 = F_2 ( V_1 + V_68 ) ;
if ( V_58 & V_69 )
V_55 -> V_70 ++ ;
if ( V_58 & V_71 )
V_55 -> V_72 ++ ;
if ( V_58 & V_73 )
V_55 -> V_74 ++ ;
if ( V_58 & V_75 )
V_55 -> V_76 ++ ;
}
if ( ( V_56 & V_77 ) || ( V_56 & V_78 ) ) {
F_2 ( V_1 + V_79 ) ;
V_55 -> V_80 ++ ;
}
if ( V_56 & V_81 ) {
T_2 V_82 = F_2 ( V_1 + V_83 ) ;
V_55 -> V_84 ++ ;
if ( V_82 & V_85 ) {
int V_86 = ( V_82 & V_87 ) >>
V_88 ;
V_55 -> V_89 = ( V_82 & V_90 ) ;
if ( V_86 == V_91 )
V_55 -> V_92 = V_93 ;
else if ( V_86 == V_94 )
V_55 -> V_92 = V_95 ;
else
V_55 -> V_92 = V_96 ;
V_55 -> V_97 = 1 ;
F_15 ( L_11 , V_17 ,
( int ) V_55 -> V_92 ,
V_55 -> V_89 ? L_12 : L_13 ) ;
} else {
V_55 -> V_97 = 0 ;
F_15 ( L_14 , V_17 ) ;
}
}
return V_58 ;
}
static void F_28 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_68 ) ;
V_2 |= V_98 | V_99 ;
F_3 ( V_2 , V_1 + V_68 ) ;
}
static void F_29 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_68 ) ;
V_2 &= ~ ( V_98 | V_99 ) ;
F_3 ( V_2 , V_1 + V_68 ) ;
}
static void F_30 ( void T_1 * V_1 , int V_100 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_68 ) ;
if ( V_100 )
V_2 |= V_101 ;
else
V_2 &= ~ V_101 ;
F_3 ( V_2 , V_1 + V_68 ) ;
}
static void F_31 ( void T_1 * V_1 , int V_102 , int V_103 )
{
int V_2 = ( ( V_103 & 0xffff ) ) | ( ( V_102 & 0x7ff ) << 16 ) ;
F_3 ( V_2 , V_1 + V_104 ) ;
}
static void F_32 ( void T_1 * V_1 , bool V_105 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_106 ) ;
V_2 = V_107 | V_108 ;
if ( V_105 )
V_2 |= V_109 ;
F_3 ( V_2 , V_1 + V_106 ) ;
}
static void F_33 ( void T_1 * V_1 , struct V_110 * V_111 )
{
T_2 V_2 = F_2 ( V_1 + V_112 ) ;
if ( V_2 & V_113 )
V_111 -> V_36 = V_114 ;
if ( V_2 & V_115 )
V_111 -> V_36 |= V_116 ;
V_111 -> V_117 = ( V_2 & V_118 ) >> V_119 ;
V_2 = F_2 ( V_1 + V_120 ) ;
if ( V_2 & V_113 )
V_111 -> V_121 = V_114 ;
if ( V_2 & V_115 )
V_111 -> V_121 = V_116 ;
V_111 -> V_122 = ( V_2 & V_118 ) >> V_119 ;
}
struct V_123 * F_34 ( void T_1 * V_1 )
{
struct V_123 * V_124 ;
T_2 V_125 = F_2 ( V_1 + V_126 ) ;
V_124 = F_35 ( sizeof( const struct V_123 ) , V_127 ) ;
if ( ! V_124 )
return NULL ;
V_124 -> V_124 = & V_128 ;
V_124 -> V_129 = & V_130 ;
V_124 -> V_100 . V_131 = V_132 ;
V_124 -> V_100 . V_36 = V_133 ;
V_124 -> V_100 . V_134 = V_135 ;
V_124 -> V_136 . V_10 = V_137 ;
V_124 -> V_136 . V_138 = V_139 ;
V_124 -> V_140 = V_125 ;
return V_124 ;
}
