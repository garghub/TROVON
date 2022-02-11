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
F_15 ( V_17 L_3 ,
V_18 , F_16 ( V_13 ) , F_17 ( V_13 ) ) ;
if ( V_13 -> V_19 & V_20 )
V_2 = V_21 ;
else if ( ( F_16 ( V_13 ) > V_22 )
|| ( V_13 -> V_19 & V_23 ) ) {
V_2 = V_24 ;
F_3 ( 0xffffffff , V_1 + V_25 ) ;
F_3 ( 0xffffffff , V_1 + V_26 ) ;
} else if ( ! F_18 ( V_13 ) ) {
T_2 V_27 [ 2 ] ;
struct V_28 * V_29 ;
V_2 = V_30 ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
F_19 (ha, dev) {
int V_31 = F_20 ( ~ F_21 ( ~ 0 , V_29 -> V_10 , 6 ) ) >> 26 ;
V_27 [ V_31 >> 5 ] |= 1 << ( V_31 & 31 ) ;
}
F_3 ( V_27 [ 0 ] , V_1 + V_26 ) ;
F_3 ( V_27 [ 1 ] , V_1 + V_25 ) ;
}
if ( V_14 > V_32 )
V_16 = V_33 ;
else
V_16 = V_33 / 2 ;
if ( F_17 ( V_13 ) > V_16 )
V_2 |= V_21 ;
else {
int V_34 = 1 ;
struct V_28 * V_29 ;
F_22 (ha, dev) {
F_8 ( V_1 , V_29 -> V_10 , V_34 ) ;
V_34 ++ ;
}
}
#ifdef F_23
V_2 |= V_35 ;
#endif
F_3 ( V_2 , V_1 + V_36 ) ;
F_15 ( V_17 L_4 ,
F_2 ( V_1 + V_36 ) ,
F_2 ( V_1 + V_25 ) , F_2 ( V_1 + V_26 ) ) ;
}
static void F_24 ( void T_1 * V_1 , unsigned int V_37 ,
unsigned int V_38 , unsigned int V_39 )
{
unsigned int V_40 = 0 ;
F_15 ( V_41 L_5 ) ;
if ( V_38 & V_42 ) {
F_15 ( V_41 L_6 ) ;
V_40 |= V_43 ;
}
if ( V_38 & V_44 ) {
F_15 ( V_41 L_7 ) ;
V_40 |= V_45 ;
}
if ( V_37 ) {
F_15 ( V_41 L_8 , V_39 ) ;
V_40 |= ( V_39 << V_46 ) ;
}
F_3 ( V_40 , V_1 + V_47 ) ;
}
static void F_25 ( void T_1 * V_1 , unsigned long V_48 )
{
unsigned int V_49 = 0 ;
if ( V_48 & V_50 ) {
F_15 ( V_41 L_9 ) ;
V_49 |= V_51 | V_52 ;
}
if ( V_48 & V_53 ) {
F_15 ( V_41 L_10 ) ;
V_49 |= V_54 ;
}
F_3 ( V_49 , V_1 + V_55 ) ;
}
static int F_26 ( void T_1 * V_1 ,
struct V_56 * V_57 )
{
T_2 V_58 = F_2 ( V_1 + V_59 ) ;
int V_60 = 0 ;
if ( ( V_58 & V_61 ) ) {
F_15 ( V_17 L_11 ,
F_2 ( V_1 + V_62 ) ) ;
V_57 -> V_63 ++ ;
}
if ( F_27 ( V_58 & V_64 ) ) {
F_15 ( V_17 L_12 ,
F_2 ( V_1 + V_65 ) ) ;
V_57 -> V_66 ++ ;
}
if ( F_27 ( V_58 & V_67 ) ) {
F_15 ( V_17 L_13 ,
F_2 ( V_1 + V_68 ) ) ;
V_57 -> V_69 ++ ;
}
if ( F_27 ( V_58 & V_70 ) ) {
F_15 ( V_17 L_14 ) ;
F_2 ( V_1 + V_55 ) ;
V_57 -> V_71 ++ ;
}
if ( V_58 & V_72 ) {
V_60 = F_2 ( V_1 + V_73 ) ;
if ( V_60 & V_74 ) {
F_15 ( V_17 L_15 ) ;
V_57 -> V_75 ++ ;
}
if ( V_60 & V_76 ) {
F_15 ( V_17 L_16 ) ;
V_57 -> V_77 ++ ;
}
if ( V_60 & V_78 ) {
F_15 ( V_17 L_17 ) ;
V_57 -> V_79 ++ ;
}
if ( V_60 & V_80 ) {
F_15 ( V_17 L_18 ) ;
V_57 -> V_81 ++ ;
}
}
if ( ( V_58 & V_82 ) || ( V_58 & V_83 ) ) {
F_15 ( V_17 L_19 ) ;
F_2 ( V_1 + V_84 ) ;
V_57 -> V_85 ++ ;
}
if ( V_58 & V_86 ) {
T_2 V_87 = F_2 ( V_1 + V_88 ) ;
F_15 ( V_17 L_20 ) ;
V_57 -> V_89 ++ ;
if ( V_87 & V_90 ) {
int V_91 = ( V_87 & V_92 ) >>
V_93 ;
V_57 -> V_94 = ( V_87 & V_95 ) ;
if ( V_91 == V_96 )
V_57 -> V_97 = V_98 ;
else if ( V_91 == V_99 )
V_57 -> V_97 = V_100 ;
else
V_57 -> V_97 = V_101 ;
V_57 -> V_102 = 1 ;
F_28 ( L_21 , ( int ) V_57 -> V_97 ,
V_57 -> V_94 ? L_22 : L_23 ) ;
} else {
V_57 -> V_102 = 0 ;
F_28 ( L_24 ) ;
}
}
return V_60 ;
}
static void F_29 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_73 ) ;
V_2 |= V_103 | V_104 ;
F_3 ( V_2 , V_1 + V_73 ) ;
}
static void F_30 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_73 ) ;
V_2 &= ~ ( V_103 | V_104 ) ;
F_3 ( V_2 , V_1 + V_73 ) ;
}
static void F_31 ( void T_1 * V_1 , int V_105 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_73 ) ;
if ( V_105 )
V_2 |= V_106 ;
else
V_2 &= ~ V_106 ;
F_3 ( V_2 , V_1 + V_73 ) ;
}
static void F_32 ( void T_1 * V_1 , int V_107 , int V_108 )
{
int V_2 = ( ( V_108 & 0xffff ) ) | ( ( V_107 & 0x7ff ) << 16 ) ;
F_3 ( V_2 , V_1 + V_109 ) ;
}
static void F_33 ( void T_1 * V_1 , bool V_110 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_111 ) ;
V_2 = V_112 | V_113 ;
if ( V_110 )
V_2 |= V_114 ;
F_3 ( V_2 , V_1 + V_111 ) ;
}
static void F_34 ( void T_1 * V_1 , struct V_115 * V_116 )
{
T_2 V_2 = F_2 ( V_1 + V_117 ) ;
if ( V_2 & V_118 )
V_116 -> V_37 = V_119 ;
if ( V_2 & V_120 )
V_116 -> V_37 |= V_121 ;
V_116 -> V_122 = ( V_2 & V_123 ) >> V_124 ;
V_2 = F_2 ( V_1 + V_125 ) ;
if ( V_2 & V_118 )
V_116 -> V_126 = V_119 ;
if ( V_2 & V_120 )
V_116 -> V_126 = V_121 ;
V_116 -> V_127 = ( V_2 & V_123 ) >> V_124 ;
}
struct V_128 * F_35 ( void T_1 * V_1 )
{
struct V_128 * V_129 ;
T_2 V_130 = F_2 ( V_1 + V_131 ) ;
V_129 = F_36 ( sizeof( const struct V_128 ) , V_132 ) ;
if ( ! V_129 )
return NULL ;
V_129 -> V_129 = & V_133 ;
V_129 -> V_134 = & V_135 ;
V_129 -> V_105 . V_136 = V_137 ;
V_129 -> V_105 . V_37 = V_138 ;
V_129 -> V_105 . V_139 = V_140 ;
V_129 -> V_141 . V_10 = V_142 ;
V_129 -> V_141 . V_143 = V_144 ;
V_129 -> V_145 = V_130 ;
return V_129 ;
}
