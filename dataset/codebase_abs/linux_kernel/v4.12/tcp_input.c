static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_5 )
{
static bool T_1 V_6 ;
if ( ! T_1 ) {
struct V_7 * V_8 ;
T_1 = true ;
F_2 () ;
V_8 = F_3 ( F_4 ( V_2 ) , V_4 -> V_9 ) ;
if ( ! V_8 || V_5 >= V_8 -> V_10 )
F_5 ( L_1 ,
V_8 ? V_8 -> V_11 : L_2 ) ;
F_6 () ;
}
}
static void F_7 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
const unsigned int V_14 = V_13 -> V_15 . V_16 ;
unsigned int V_5 ;
V_13 -> V_15 . V_16 = 0 ;
V_5 = F_9 ( V_4 ) -> V_17 ? : V_4 -> V_5 ;
if ( V_5 >= V_13 -> V_15 . V_18 ) {
V_13 -> V_15 . V_18 = F_10 (unsigned int, len,
tcp_sk(sk)->advmss) ;
if ( F_11 ( V_5 > V_13 -> V_15 . V_18 +
V_19 ) )
F_1 ( V_2 , V_4 , V_5 ) ;
} else {
V_5 += V_4 -> V_20 - F_12 ( V_4 ) ;
if ( V_5 >= V_21 + sizeof( struct V_22 ) ||
( V_5 >= V_23 + sizeof( struct V_22 ) &&
! ( F_13 ( F_14 ( V_4 ) ) & V_24 ) ) ) {
V_5 -= F_15 ( V_2 ) -> V_25 ;
V_13 -> V_15 . V_16 = V_5 ;
if ( V_5 == V_14 ) {
V_13 -> V_15 . V_18 = V_5 ;
return;
}
}
if ( V_13 -> V_15 . V_26 & V_27 )
V_13 -> V_15 . V_26 |= V_28 ;
V_13 -> V_15 . V_26 |= V_27 ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
unsigned int V_29 = F_15 ( V_2 ) -> V_30 / ( 2 * V_13 -> V_15 . V_18 ) ;
if ( V_29 == 0 )
V_29 = 2 ;
if ( V_29 > V_13 -> V_15 . V_31 )
V_13 -> V_15 . V_31 = F_17 ( V_29 , V_32 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
F_16 ( V_2 ) ;
V_13 -> V_15 . V_33 = 0 ;
V_13 -> V_15 . V_34 = V_35 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
const struct V_36 * V_37 = F_20 ( V_2 ) ;
return ( V_37 && F_21 ( V_37 , V_38 ) ) ||
( V_13 -> V_15 . V_31 && ! V_13 -> V_15 . V_33 ) ;
}
static void F_22 ( struct V_39 * V_40 )
{
if ( V_40 -> V_41 & V_42 )
V_40 -> V_41 |= V_43 ;
}
static void F_23 ( struct V_39 * V_40 , const struct V_3 * V_4 )
{
if ( F_14 ( V_4 ) -> V_44 )
V_40 -> V_41 &= ~ V_45 ;
}
static void F_24 ( struct V_39 * V_40 )
{
V_40 -> V_41 &= ~ V_45 ;
}
static void F_25 ( struct V_39 * V_40 , const struct V_3 * V_4 )
{
switch ( F_26 ( V_4 ) -> V_46 & V_47 ) {
case V_48 :
if ( V_40 -> V_41 & V_49 )
F_18 ( (struct V_1 * ) V_40 ) ;
break;
case V_50 :
if ( F_27 ( (struct V_1 * ) V_40 ) )
F_28 ( (struct V_1 * ) V_40 , V_51 ) ;
if ( ! ( V_40 -> V_41 & V_45 ) ) {
F_18 ( (struct V_1 * ) V_40 ) ;
V_40 -> V_41 |= V_45 ;
}
V_40 -> V_41 |= V_49 ;
break;
default:
if ( F_27 ( (struct V_1 * ) V_40 ) )
F_28 ( (struct V_1 * ) V_40 , V_52 ) ;
V_40 -> V_41 |= V_49 ;
break;
}
}
static void F_29 ( struct V_39 * V_40 , const struct V_3 * V_4 )
{
if ( V_40 -> V_41 & V_42 )
F_25 ( V_40 , V_4 ) ;
}
static void F_30 ( struct V_39 * V_40 , const struct V_22 * V_53 )
{
if ( ( V_40 -> V_41 & V_42 ) && ( ! V_53 -> V_54 || V_53 -> V_44 ) )
V_40 -> V_41 &= ~ V_42 ;
}
static void F_31 ( struct V_39 * V_40 , const struct V_22 * V_53 )
{
if ( ( V_40 -> V_41 & V_42 ) && ( ! V_53 -> V_54 || ! V_53 -> V_44 ) )
V_40 -> V_41 &= ~ V_42 ;
}
static bool F_32 ( const struct V_39 * V_40 , const struct V_22 * V_53 )
{
if ( V_53 -> V_54 && ! V_53 -> V_55 && ( V_40 -> V_41 & V_42 ) )
return true ;
return false ;
}
static void F_33 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
const struct V_56 * V_57 = F_8 ( V_2 ) -> V_58 ;
int V_59 , V_60 ;
T_2 V_61 ;
V_60 = F_34 ( T_2 , V_40 -> V_62 . V_63 , V_40 -> V_64 ) +
V_65 +
F_35 ( sizeof( struct V_66 ) ) ;
V_60 = F_36 ( V_60 ) +
F_35 ( sizeof( struct V_3 ) ) ;
V_61 = F_34 ( T_2 , V_67 , V_40 -> V_68 ) ;
V_61 = F_34 ( T_2 , V_61 , V_40 -> V_69 + 1 ) ;
V_59 = V_57 -> V_70 ? V_57 -> V_70 ( V_2 ) : 2 ;
V_59 *= V_61 * V_60 ;
if ( V_2 -> V_71 < V_59 )
V_2 -> V_71 = F_17 ( V_59 , V_72 [ 2 ] ) ;
}
static int F_37 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_73 = F_38 ( V_4 -> V_73 ) >> 1 ;
int V_74 = F_38 ( V_75 [ 2 ] ) >> 1 ;
while ( V_40 -> V_76 <= V_74 ) {
if ( V_73 <= V_4 -> V_5 )
return 2 * F_8 ( V_2 ) -> V_15 . V_18 ;
V_73 >>= 1 ;
V_74 >>= 1 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_76 < V_40 -> V_77 &&
( int ) V_40 -> V_76 < F_40 ( V_2 ) &&
! F_41 ( V_2 ) ) {
int V_78 ;
if ( F_38 ( V_4 -> V_73 ) <= V_4 -> V_5 )
V_78 = 2 * V_40 -> V_79 ;
else
V_78 = F_37 ( V_2 , V_4 ) ;
if ( V_78 ) {
V_78 = F_34 ( int , V_78 , 2 * V_4 -> V_5 ) ;
V_40 -> V_76 = F_17 ( V_40 -> V_76 + V_78 ,
V_40 -> V_77 ) ;
F_8 ( V_2 ) -> V_15 . V_31 |= 1 ;
}
}
}
static void F_42 ( struct V_1 * V_2 )
{
T_2 V_80 = F_15 ( V_2 ) -> V_79 ;
int V_81 ;
V_81 = 2 * F_43 ( V_80 + V_65 ) *
F_44 ( V_80 ) ;
if ( V_82 )
V_81 <<= 2 ;
if ( V_2 -> V_83 < V_81 )
V_2 -> V_83 = F_17 ( V_81 , V_75 [ 2 ] ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_84 ;
if ( ! ( V_2 -> V_85 & V_86 ) )
F_42 ( V_2 ) ;
if ( ! ( V_2 -> V_85 & V_87 ) )
F_33 ( V_2 ) ;
V_40 -> V_88 . V_89 = V_40 -> V_30 ;
F_46 ( & V_40 -> V_90 ) ;
V_40 -> V_88 . time = V_40 -> V_90 ;
V_40 -> V_88 . V_91 = V_40 -> V_92 ;
V_84 = F_47 ( V_2 ) ;
if ( V_40 -> V_77 >= V_84 ) {
V_40 -> V_77 = V_84 ;
if ( V_93 && V_84 > 4 * V_40 -> V_79 )
V_40 -> V_77 = F_48 ( V_84 -
( V_84 >> V_93 ) ,
4 * V_40 -> V_79 ) ;
}
if ( V_93 &&
V_40 -> V_77 > 2 * V_40 -> V_79 &&
V_40 -> V_77 + V_40 -> V_79 > V_84 )
V_40 -> V_77 = F_48 ( 2 * V_40 -> V_79 , V_84 - V_40 -> V_79 ) ;
V_40 -> V_76 = F_17 ( V_40 -> V_76 , V_40 -> V_77 ) ;
V_40 -> V_94 = V_95 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_15 . V_31 = 0 ;
if ( V_2 -> V_83 < V_75 [ 2 ] &&
! ( V_2 -> V_85 & V_86 ) &&
! F_41 ( V_2 ) &&
F_50 ( V_2 ) < F_51 ( V_2 , 0 ) ) {
V_2 -> V_83 = F_17 ( F_52 ( & V_2 -> V_96 ) ,
V_75 [ 2 ] ) ;
}
if ( F_52 ( & V_2 -> V_96 ) > V_2 -> V_83 )
V_40 -> V_76 = F_17 ( V_40 -> V_77 , 2U * V_40 -> V_79 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
unsigned int V_97 = F_10 (unsigned int, tp->advmss, tp->mss_cache) ;
V_97 = F_17 ( V_97 , V_40 -> V_30 / 2 ) ;
V_97 = F_17 ( V_97 , V_21 ) ;
V_97 = F_48 ( V_97 , V_23 ) ;
F_8 ( V_2 ) -> V_15 . V_18 = V_97 ;
}
static void F_54 ( struct V_39 * V_40 , T_2 V_98 , int V_99 )
{
T_2 V_100 = V_40 -> V_101 . V_102 ;
long V_103 = V_98 ;
if ( V_103 == 0 )
V_103 = 1 ;
if ( V_100 != 0 ) {
if ( ! V_99 ) {
V_103 -= ( V_100 >> 3 ) ;
V_100 += V_103 ;
} else {
V_103 <<= 3 ;
if ( V_103 < V_100 )
V_100 = V_103 ;
}
} else {
V_100 = V_103 << 3 ;
}
V_40 -> V_101 . V_102 = V_100 ;
}
static inline void F_55 ( struct V_39 * V_40 )
{
T_2 V_104 ;
if ( V_40 -> V_101 . time . V_105 == 0 )
goto V_106;
if ( F_56 ( V_40 -> V_107 , V_40 -> V_101 . V_91 ) )
return;
V_104 = F_57 ( & V_40 -> V_90 , & V_40 -> V_101 . time ) ;
F_54 ( V_40 , V_104 , 1 ) ;
V_106:
V_40 -> V_101 . V_91 = V_40 -> V_107 + V_40 -> V_30 ;
V_40 -> V_101 . time = V_40 -> V_90 ;
}
static inline void F_58 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_62 . V_108 &&
( F_26 ( V_4 ) -> V_109 -
F_26 ( V_4 ) -> V_91 >= F_8 ( V_2 ) -> V_15 . V_18 ) )
F_54 ( V_40 ,
F_59 ( V_95 -
V_40 -> V_62 . V_108 ) ,
0 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int time ;
int V_110 ;
time = F_57 ( & V_40 -> V_90 , & V_40 -> V_88 . time ) ;
if ( time < ( V_40 -> V_101 . V_102 >> 3 ) || V_40 -> V_101 . V_102 == 0 )
return;
V_110 = V_40 -> V_92 - V_40 -> V_88 . V_91 ;
if ( V_110 <= V_40 -> V_88 . V_89 )
goto V_106;
if ( V_82 &&
! ( V_2 -> V_85 & V_86 ) ) {
int V_111 , V_81 , V_112 ;
V_111 = ( V_110 << 1 ) + 16 * V_40 -> V_79 ;
if ( V_110 >=
V_40 -> V_88 . V_89 + ( V_40 -> V_88 . V_89 >> 2 ) ) {
if ( V_110 >=
V_40 -> V_88 . V_89 + ( V_40 -> V_88 . V_89 >> 1 ) )
V_111 <<= 1 ;
else
V_111 += ( V_111 >> 1 ) ;
}
V_81 = F_43 ( V_40 -> V_79 + V_65 ) ;
while ( F_38 ( V_81 ) < V_40 -> V_79 )
V_81 += 128 ;
V_112 = F_17 ( V_111 / V_40 -> V_79 * V_81 , V_75 [ 2 ] ) ;
if ( V_112 > V_2 -> V_83 ) {
V_2 -> V_83 = V_112 ;
V_40 -> V_77 = V_111 ;
}
}
V_40 -> V_88 . V_89 = V_110 ;
V_106:
V_40 -> V_88 . V_91 = V_40 -> V_92 ;
V_40 -> V_88 . time = V_40 -> V_90 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
T_2 V_113 ;
F_62 ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
F_55 ( V_40 ) ;
V_113 = V_95 ;
if ( ! V_13 -> V_15 . V_34 ) {
F_16 ( V_2 ) ;
V_13 -> V_15 . V_34 = V_35 ;
} else {
int V_103 = V_113 - V_13 -> V_15 . V_114 ;
if ( V_103 <= V_35 / 2 ) {
V_13 -> V_15 . V_34 = ( V_13 -> V_15 . V_34 >> 1 ) + V_35 / 2 ;
} else if ( V_103 < V_13 -> V_15 . V_34 ) {
V_13 -> V_15 . V_34 = ( V_13 -> V_15 . V_34 >> 1 ) + V_103 ;
if ( V_13 -> V_15 . V_34 > V_13 -> V_115 )
V_13 -> V_15 . V_34 = V_13 -> V_115 ;
} else if ( V_103 > V_13 -> V_115 ) {
F_16 ( V_2 ) ;
F_63 ( V_2 ) ;
}
}
V_13 -> V_15 . V_114 = V_113 ;
F_29 ( V_40 , V_4 ) ;
if ( V_4 -> V_5 >= 128 )
F_39 ( V_2 , V_4 ) ;
}
static void F_64 ( struct V_1 * V_2 , long V_116 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
long V_103 = V_116 ;
T_2 V_117 = V_40 -> V_118 ;
if ( V_117 != 0 ) {
V_103 -= ( V_117 >> 3 ) ;
V_117 += V_103 ;
if ( V_103 < 0 ) {
V_103 = - V_103 ;
V_103 -= ( V_40 -> V_119 >> 2 ) ;
if ( V_103 > 0 )
V_103 >>= 3 ;
} else {
V_103 -= ( V_40 -> V_119 >> 2 ) ;
}
V_40 -> V_119 += V_103 ;
if ( V_40 -> V_119 > V_40 -> V_120 ) {
V_40 -> V_120 = V_40 -> V_119 ;
if ( V_40 -> V_120 > V_40 -> V_121 )
V_40 -> V_121 = V_40 -> V_120 ;
}
if ( F_65 ( V_40 -> V_122 , V_40 -> V_123 ) ) {
if ( V_40 -> V_120 < V_40 -> V_121 )
V_40 -> V_121 -= ( V_40 -> V_121 - V_40 -> V_120 ) >> 2 ;
V_40 -> V_123 = V_40 -> V_124 ;
V_40 -> V_120 = F_66 ( V_2 ) ;
}
} else {
V_117 = V_103 << 3 ;
V_40 -> V_119 = V_103 << 1 ;
V_40 -> V_121 = F_48 ( V_40 -> V_119 , F_66 ( V_2 ) ) ;
V_40 -> V_120 = V_40 -> V_121 ;
V_40 -> V_123 = V_40 -> V_124 ;
}
V_40 -> V_118 = F_48 ( 1U , V_117 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
T_3 V_125 ;
V_125 = ( T_3 ) V_40 -> V_64 * ( ( V_126 / 100 ) << 3 ) ;
if ( V_40 -> V_68 < V_40 -> V_127 / 2 )
V_125 *= V_128 ;
else
V_125 *= V_129 ;
V_125 *= F_48 ( V_40 -> V_68 , V_40 -> V_130 ) ;
if ( F_68 ( V_40 -> V_118 ) )
F_69 ( V_125 , V_40 -> V_118 ) ;
F_70 ( V_2 -> V_131 ) = F_10 ( T_3 , V_125 ,
V_2 -> V_132 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
F_8 ( V_2 ) -> V_115 = F_72 ( V_40 ) ;
F_73 ( V_2 ) ;
}
T_4 F_74 ( const struct V_39 * V_40 , const struct V_36 * V_37 )
{
T_4 V_133 = ( V_37 ? F_21 ( V_37 , V_134 ) : 0 ) ;
if ( ! V_133 )
V_133 = V_67 ;
return F_10 ( T_4 , V_133 , V_40 -> V_135 ) ;
}
void F_75 ( struct V_39 * V_40 )
{
if ( F_76 ( V_40 ) )
V_40 -> V_136 = NULL ;
V_40 -> V_62 . V_137 &= ~ V_138 ;
}
static void F_77 ( struct V_39 * V_40 )
{
V_40 -> V_62 . V_137 |= V_139 ;
}
static void F_78 ( struct V_1 * V_2 , const int V_140 ,
const int V_141 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_142 ;
if ( V_140 > V_40 -> V_69 ) {
V_40 -> V_69 = F_17 ( V_143 , V_140 ) ;
#if V_144 > 1
F_79 ( L_3 ,
V_40 -> V_62 . V_137 , F_8 ( V_2 ) -> V_145 ,
V_40 -> V_69 ,
V_40 -> V_146 ,
V_40 -> V_147 ,
V_40 -> V_148 ? V_40 -> V_149 : 0 ) ;
#endif
F_75 ( V_40 ) ;
}
V_40 -> V_150 . V_151 = 1 ;
if ( V_141 )
V_142 = V_152 ;
else if ( F_80 ( V_40 ) )
V_142 = V_153 ;
else if ( F_76 ( V_40 ) )
V_142 = V_154 ;
else
V_142 = V_155 ;
F_81 ( F_4 ( V_2 ) , V_142 ) ;
}
static void F_82 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
if ( ! V_40 -> V_156 ||
F_56 ( F_26 ( V_4 ) -> V_91 ,
F_26 ( V_40 -> V_156 ) -> V_91 ) )
V_40 -> V_156 = V_4 ;
}
static void F_83 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
T_5 V_157 = F_26 ( V_4 ) -> V_157 ;
if ( ! ( V_157 & V_158 ) ||
( ( V_157 & V_158 ) && ( V_157 & V_159 ) ) )
V_40 -> V_160 += F_84 ( V_4 ) ;
}
static void F_85 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
if ( ! ( F_26 ( V_4 ) -> V_157 & ( V_158 | V_161 ) ) ) {
F_82 ( V_40 , V_4 ) ;
V_40 -> V_162 += F_84 ( V_4 ) ;
F_83 ( V_40 , V_4 ) ;
F_26 ( V_4 ) -> V_157 |= V_158 ;
}
}
void F_86 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
F_82 ( V_40 , V_4 ) ;
F_83 ( V_40 , V_4 ) ;
if ( ! ( F_26 ( V_4 ) -> V_157 & ( V_158 | V_161 ) ) ) {
V_40 -> V_162 += F_84 ( V_4 ) ;
F_26 ( V_4 ) -> V_157 |= V_158 ;
}
}
static bool F_87 ( struct V_39 * V_40 , bool V_163 ,
T_2 V_164 , T_2 V_109 )
{
if ( F_65 ( V_109 , V_40 -> V_124 ) || ! F_56 ( V_164 , V_109 ) )
return false ;
if ( ! F_56 ( V_164 , V_40 -> V_124 ) )
return false ;
if ( F_65 ( V_164 , V_40 -> V_122 ) )
return true ;
if ( ! V_163 || ! V_40 -> V_148 )
return false ;
if ( F_65 ( V_109 , V_40 -> V_122 ) )
return false ;
if ( ! F_56 ( V_164 , V_40 -> V_148 ) )
return true ;
if ( ! F_65 ( V_109 , V_40 -> V_148 ) )
return false ;
return ! F_56 ( V_164 , V_109 - V_40 -> V_165 ) ;
}
static bool F_88 ( struct V_1 * V_2 , const struct V_3 * V_166 ,
struct V_167 * V_168 , int V_169 ,
T_2 V_170 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_171 = F_89 ( & V_168 [ 0 ] . V_164 ) ;
T_2 V_172 = F_89 ( & V_168 [ 0 ] . V_109 ) ;
bool V_173 = false ;
if ( F_56 ( V_171 , F_26 ( V_166 ) -> V_174 ) ) {
V_173 = true ;
F_77 ( V_40 ) ;
F_81 ( F_4 ( V_2 ) , V_175 ) ;
} else if ( V_169 > 1 ) {
T_2 V_176 = F_89 ( & V_168 [ 1 ] . V_109 ) ;
T_2 V_177 = F_89 ( & V_168 [ 1 ] . V_164 ) ;
if ( ! F_65 ( V_172 , V_176 ) &&
! F_56 ( V_171 , V_177 ) ) {
V_173 = true ;
F_77 ( V_40 ) ;
F_81 ( F_4 ( V_2 ) ,
V_178 ) ;
}
}
if ( V_173 && V_40 -> V_148 && V_40 -> V_149 > 0 &&
! F_65 ( V_172 , V_170 ) &&
F_65 ( V_172 , V_40 -> V_148 ) )
V_40 -> V_149 -- ;
return V_173 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_164 , T_2 V_109 )
{
int V_179 ;
bool V_180 ;
unsigned int V_181 ;
unsigned int V_80 ;
V_180 = ! F_65 ( V_164 , F_26 ( V_4 ) -> V_91 ) &&
! F_56 ( V_109 , F_26 ( V_4 ) -> V_109 ) ;
if ( F_84 ( V_4 ) > 1 && ! V_180 &&
F_65 ( F_26 ( V_4 ) -> V_109 , V_164 ) ) {
V_80 = F_91 ( V_4 ) ;
V_180 = ! F_65 ( V_164 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! V_180 ) {
V_181 = V_164 - F_26 ( V_4 ) -> V_91 ;
if ( V_181 < V_80 )
V_181 = V_80 ;
} else {
V_181 = V_109 - F_26 ( V_4 ) -> V_91 ;
if ( V_181 < V_80 )
return - V_182 ;
}
if ( V_181 > V_80 ) {
unsigned int V_183 = ( V_181 / V_80 ) * V_80 ;
if ( ! V_180 && V_183 < V_181 )
V_183 += V_80 ;
V_181 = V_183 ;
}
if ( V_181 >= V_4 -> V_5 && ! V_180 )
return 0 ;
V_179 = F_92 ( V_2 , V_4 , V_181 , V_80 , V_184 ) ;
if ( V_179 < 0 )
return V_179 ;
}
return V_180 ;
}
static T_6 F_93 ( struct V_1 * V_2 ,
struct V_185 * V_186 , T_6 V_157 ,
T_2 V_164 , T_2 V_109 ,
int V_173 , int V_187 ,
const struct V_188 * V_189 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_190 = V_186 -> V_190 ;
if ( V_173 && ( V_157 & V_191 ) ) {
if ( V_40 -> V_148 && V_40 -> V_149 > 0 &&
F_65 ( V_109 , V_40 -> V_148 ) )
V_40 -> V_149 -- ;
if ( V_157 & V_161 )
V_186 -> V_151 = F_17 ( V_190 , V_186 -> V_151 ) ;
}
if ( ! F_65 ( V_109 , V_40 -> V_122 ) )
return V_157 ;
if ( ! ( V_157 & V_161 ) ) {
F_94 ( V_40 , V_157 , V_109 , V_189 ) ;
if ( V_157 & V_159 ) {
if ( V_157 & V_158 ) {
V_157 &= ~ ( V_158 | V_159 ) ;
V_40 -> V_162 -= V_187 ;
V_40 -> V_192 -= V_187 ;
}
} else {
if ( ! ( V_157 & V_191 ) ) {
if ( F_56 ( V_164 ,
F_95 ( V_40 ) ) )
V_186 -> V_151 = F_17 ( V_190 ,
V_186 -> V_151 ) ;
if ( ! F_65 ( V_109 , V_40 -> V_193 ) )
V_186 -> V_194 |= V_195 ;
if ( V_186 -> V_196 . V_105 == 0 )
V_186 -> V_196 = * V_189 ;
V_186 -> V_197 = * V_189 ;
}
if ( V_157 & V_158 ) {
V_157 &= ~ V_158 ;
V_40 -> V_162 -= V_187 ;
}
}
V_157 |= V_161 ;
V_186 -> V_194 |= V_198 ;
V_40 -> V_147 += V_187 ;
V_40 -> V_199 += V_187 ;
V_190 += V_187 ;
if ( ! F_76 ( V_40 ) && V_40 -> V_136 &&
F_56 ( V_164 , F_26 ( V_40 -> V_136 ) -> V_91 ) )
V_40 -> V_200 += V_187 ;
if ( V_190 > V_40 -> V_146 )
V_40 -> V_146 = V_190 ;
}
if ( V_173 && ( V_157 & V_159 ) ) {
V_157 &= ~ V_159 ;
V_40 -> V_192 -= V_187 ;
}
return V_157 ;
}
static bool F_96 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_185 * V_186 ,
unsigned int V_187 , int V_201 , int V_80 ,
bool V_173 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_202 = F_97 ( V_2 , V_4 ) ;
T_2 V_164 = F_26 ( V_4 ) -> V_91 ;
T_2 V_109 = V_164 + V_201 ;
F_98 ( ! V_187 ) ;
F_93 ( V_2 , V_186 , F_26 ( V_4 ) -> V_157 ,
V_164 , V_109 , V_173 , V_187 ,
& V_4 -> V_188 ) ;
F_99 ( V_2 , V_4 , V_186 -> V_125 ) ;
if ( V_4 == V_40 -> V_136 )
V_40 -> V_200 += V_187 ;
F_26 ( V_202 ) -> V_109 += V_201 ;
F_26 ( V_4 ) -> V_91 += V_201 ;
F_100 ( V_202 , V_187 ) ;
F_98 ( F_84 ( V_4 ) < V_187 ) ;
F_100 ( V_4 , - V_187 ) ;
if ( ! F_26 ( V_202 ) -> V_203 )
F_26 ( V_202 ) -> V_203 = V_80 ;
if ( F_84 ( V_4 ) <= 1 )
F_26 ( V_4 ) -> V_203 = 0 ;
F_26 ( V_202 ) -> V_157 |= ( F_26 ( V_4 ) -> V_157 & V_204 ) ;
if ( V_4 -> V_5 > 0 ) {
F_98 ( ! F_84 ( V_4 ) ) ;
F_81 ( F_4 ( V_2 ) , V_205 ) ;
return false ;
}
if ( V_4 == V_40 -> V_156 )
V_40 -> V_156 = V_202 ;
if ( V_4 == V_40 -> V_136 ) {
V_40 -> V_136 = V_202 ;
V_40 -> V_200 -= F_84 ( V_202 ) ;
}
F_26 ( V_202 ) -> V_206 |= F_26 ( V_4 ) -> V_206 ;
F_26 ( V_202 ) -> V_207 = F_26 ( V_4 ) -> V_207 ;
if ( F_26 ( V_4 ) -> V_206 & V_208 )
F_26 ( V_202 ) -> V_109 ++ ;
if ( V_4 == F_101 ( V_2 ) )
F_102 ( V_2 , V_4 ) ;
F_103 ( V_202 , V_4 ) ;
if ( F_11 ( F_26 ( V_202 ) -> V_209 . V_210 . V_105 ) )
F_26 ( V_202 ) -> V_209 . V_210 . V_105 = 0 ;
F_104 ( V_4 , V_2 ) ;
F_105 ( V_2 , V_4 ) ;
F_81 ( F_4 ( V_2 ) , V_211 ) ;
return true ;
}
static int F_106 ( const struct V_3 * V_4 )
{
return F_84 ( V_4 ) == 1 ? V_4 -> V_5 : F_91 ( V_4 ) ;
}
static int F_107 ( const struct V_3 * V_4 )
{
return ! F_108 ( V_4 ) && F_109 ( V_4 ) ;
}
static struct V_3 * F_110 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_185 * V_186 ,
T_2 V_164 , T_2 V_109 ,
bool V_173 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_202 ;
int V_80 ;
int V_187 = 0 ;
int V_5 ;
int V_180 ;
if ( ! F_111 ( V_2 ) )
goto V_212;
if ( ! V_173 &&
( F_26 ( V_4 ) -> V_157 & ( V_158 | V_159 ) ) == V_159 )
goto V_212;
if ( ! F_107 ( V_4 ) )
goto V_212;
if ( ! F_65 ( F_26 ( V_4 ) -> V_109 , V_40 -> V_122 ) )
goto V_212;
if ( F_11 ( V_4 == F_112 ( V_2 ) ) )
goto V_212;
V_202 = F_97 ( V_2 , V_4 ) ;
if ( ( F_26 ( V_202 ) -> V_157 & V_213 ) != V_161 )
goto V_212;
if ( ! F_113 ( V_202 ) )
goto V_212;
V_180 = ! F_65 ( V_164 , F_26 ( V_4 ) -> V_91 ) &&
! F_56 ( V_109 , F_26 ( V_4 ) -> V_109 ) ;
if ( V_180 ) {
V_5 = V_4 -> V_5 ;
V_187 = F_84 ( V_4 ) ;
V_80 = F_106 ( V_4 ) ;
if ( V_80 != F_106 ( V_202 ) )
goto V_212;
} else {
if ( ! F_65 ( F_26 ( V_4 ) -> V_109 , V_164 ) )
goto V_214;
if ( F_84 ( V_4 ) <= 1 )
goto V_214;
V_180 = ! F_65 ( V_164 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! V_180 ) {
goto V_212;
}
V_5 = V_109 - F_26 ( V_4 ) -> V_91 ;
F_98 ( V_5 < 0 ) ;
F_98 ( V_5 > V_4 -> V_5 ) ;
V_80 = F_91 ( V_4 ) ;
if ( V_80 != F_106 ( V_202 ) )
goto V_212;
if ( V_5 == V_80 ) {
V_187 = 1 ;
} else if ( V_5 < V_80 ) {
goto V_214;
} else {
V_187 = V_5 / V_80 ;
V_5 = V_187 * V_80 ;
}
}
if ( ! F_65 ( F_26 ( V_4 ) -> V_91 + V_5 , V_40 -> V_122 ) )
goto V_212;
if ( ! F_114 ( V_202 , V_4 , V_5 ) )
goto V_212;
if ( ! F_96 ( V_2 , V_4 , V_186 , V_187 , V_5 , V_80 , V_173 ) )
goto V_215;
if ( V_202 == F_115 ( V_2 ) )
goto V_215;
V_4 = F_116 ( V_2 , V_202 ) ;
if ( ! F_107 ( V_4 ) ||
( V_4 == F_117 ( V_2 ) ) ||
( ( F_26 ( V_4 ) -> V_157 & V_213 ) != V_161 ) ||
( V_80 != F_106 ( V_4 ) ) )
goto V_215;
V_5 = V_4 -> V_5 ;
if ( F_114 ( V_202 , V_4 , V_5 ) ) {
V_187 += F_84 ( V_4 ) ;
F_96 ( V_2 , V_4 , V_186 , F_84 ( V_4 ) , V_5 , V_80 , 0 ) ;
}
V_215:
V_186 -> V_190 += V_187 ;
return V_202 ;
V_214:
return V_4 ;
V_212:
F_81 ( F_4 ( V_2 ) , V_216 ) ;
return NULL ;
}
static struct V_3 * F_118 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_217 * V_218 ,
struct V_185 * V_186 ,
T_2 V_164 , T_2 V_109 ,
bool V_219 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_220 ;
F_119 (skb, sk) {
int V_180 = 0 ;
bool V_173 = V_219 ;
if ( V_4 == F_117 ( V_2 ) )
break;
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 , V_109 ) )
break;
if ( V_218 &&
F_56 ( F_26 ( V_4 ) -> V_91 , V_218 -> V_109 ) ) {
V_180 = F_90 ( V_2 , V_4 ,
V_218 -> V_164 ,
V_218 -> V_109 ) ;
if ( V_180 > 0 )
V_173 = true ;
}
if ( V_180 <= 0 ) {
V_220 = F_110 ( V_2 , V_4 , V_186 ,
V_164 , V_109 , V_173 ) ;
if ( V_220 ) {
if ( V_220 != V_4 ) {
V_4 = V_220 ;
continue;
}
V_180 = 0 ;
} else {
V_180 = F_90 ( V_2 , V_4 ,
V_164 ,
V_109 ) ;
}
}
if ( F_11 ( V_180 < 0 ) )
break;
if ( V_180 ) {
F_26 ( V_4 ) -> V_157 =
F_93 ( V_2 ,
V_186 ,
F_26 ( V_4 ) -> V_157 ,
F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_109 ,
V_173 ,
F_84 ( V_4 ) ,
& V_4 -> V_188 ) ;
F_99 ( V_2 , V_4 , V_186 -> V_125 ) ;
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 ,
F_95 ( V_40 ) ) )
F_102 ( V_2 , V_4 ) ;
}
V_186 -> V_190 += F_84 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_120 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_185 * V_186 ,
T_2 V_221 )
{
F_119 (skb, sk) {
if ( V_4 == F_117 ( V_2 ) )
break;
if ( F_65 ( F_26 ( V_4 ) -> V_109 , V_221 ) )
break;
V_186 -> V_190 += F_84 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_121 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_217 * V_218 ,
struct V_185 * V_186 ,
T_2 V_221 )
{
if ( ! V_218 )
return V_4 ;
if ( F_56 ( V_218 -> V_164 , V_221 ) ) {
V_4 = F_120 ( V_4 , V_2 , V_186 , V_218 -> V_164 ) ;
V_4 = F_118 ( V_4 , V_2 , NULL , V_186 ,
V_218 -> V_164 , V_218 -> V_109 ,
1 ) ;
}
return V_4 ;
}
static int F_122 ( const struct V_39 * V_40 , const struct V_217 * V_222 )
{
return V_222 < V_40 -> V_223 + F_123 ( V_40 -> V_223 ) ;
}
static int
F_124 ( struct V_1 * V_2 , const struct V_3 * V_166 ,
T_2 V_170 , struct V_185 * V_186 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
const unsigned char * V_224 = ( F_12 ( V_166 ) +
F_26 ( V_166 ) -> V_157 ) ;
struct V_167 * V_225 = (struct V_167 * ) ( V_224 + 2 ) ;
struct V_217 V_168 [ V_226 ] ;
struct V_217 * V_222 ;
struct V_3 * V_4 ;
int V_169 = F_17 ( V_226 , ( V_224 [ 1 ] - V_227 ) >> 3 ) ;
int V_228 ;
bool V_229 = false ;
int V_230 , V_231 ;
int V_232 ;
V_186 -> V_194 = 0 ;
V_186 -> V_151 = V_40 -> V_130 ;
if ( ! V_40 -> V_147 ) {
if ( F_125 ( V_40 -> V_146 ) )
V_40 -> V_146 = 0 ;
F_126 ( V_2 ) ;
}
V_229 = F_88 ( V_2 , V_166 , V_225 ,
V_169 , V_170 ) ;
if ( V_229 ) {
V_186 -> V_194 |= V_233 ;
V_40 -> V_199 ++ ;
}
if ( F_56 ( F_26 ( V_166 ) -> V_174 , V_170 - V_40 -> V_165 ) )
return 0 ;
if ( ! V_40 -> V_130 )
goto V_215;
V_228 = 0 ;
V_232 = 0 ;
for ( V_230 = 0 ; V_230 < V_169 ; V_230 ++ ) {
bool V_173 = ! V_230 && V_229 ;
V_168 [ V_228 ] . V_164 = F_89 ( & V_225 [ V_230 ] . V_164 ) ;
V_168 [ V_228 ] . V_109 = F_89 ( & V_225 [ V_230 ] . V_109 ) ;
if ( ! F_87 ( V_40 , V_173 ,
V_168 [ V_228 ] . V_164 ,
V_168 [ V_228 ] . V_109 ) ) {
int V_142 ;
if ( V_173 ) {
if ( ! V_40 -> V_148 )
V_142 = V_234 ;
else
V_142 = V_235 ;
} else {
if ( ( F_26 ( V_166 ) -> V_174 != V_40 -> V_122 ) &&
! F_65 ( V_168 [ V_228 ] . V_109 , V_40 -> V_122 ) )
continue;
V_142 = V_236 ;
}
F_81 ( F_4 ( V_2 ) , V_142 ) ;
if ( V_230 == 0 )
V_232 = - 1 ;
continue;
}
if ( ! F_65 ( V_168 [ V_228 ] . V_109 , V_170 ) )
continue;
V_228 ++ ;
}
for ( V_230 = V_228 - 1 ; V_230 > 0 ; V_230 -- ) {
for ( V_231 = 0 ; V_231 < V_230 ; V_231 ++ ) {
if ( F_65 ( V_168 [ V_231 ] . V_164 , V_168 [ V_231 + 1 ] . V_164 ) ) {
F_127 ( V_168 [ V_231 ] , V_168 [ V_231 + 1 ] ) ;
if ( V_231 == V_232 )
V_232 = V_231 + 1 ;
}
}
}
V_4 = F_112 ( V_2 ) ;
V_186 -> V_190 = 0 ;
V_230 = 0 ;
if ( ! V_40 -> V_147 ) {
V_222 = V_40 -> V_223 + F_123 ( V_40 -> V_223 ) ;
} else {
V_222 = V_40 -> V_223 ;
while ( F_122 ( V_40 , V_222 ) && ! V_222 -> V_164 &&
! V_222 -> V_109 )
V_222 ++ ;
}
while ( V_230 < V_228 ) {
T_2 V_164 = V_168 [ V_230 ] . V_164 ;
T_2 V_109 = V_168 [ V_230 ] . V_109 ;
bool V_173 = ( V_229 && ( V_230 == V_232 ) ) ;
struct V_217 * V_218 = NULL ;
if ( V_229 && ( ( V_230 + 1 ) == V_232 ) )
V_218 = & V_168 [ V_230 + 1 ] ;
while ( F_122 ( V_40 , V_222 ) &&
! F_56 ( V_164 , V_222 -> V_109 ) )
V_222 ++ ;
if ( F_122 ( V_40 , V_222 ) && ! V_173 &&
F_65 ( V_109 , V_222 -> V_164 ) ) {
if ( F_56 ( V_164 , V_222 -> V_164 ) ) {
V_4 = F_120 ( V_4 , V_2 , V_186 ,
V_164 ) ;
V_4 = F_118 ( V_4 , V_2 , V_218 ,
V_186 ,
V_164 ,
V_222 -> V_164 ,
V_173 ) ;
}
if ( ! F_65 ( V_109 , V_222 -> V_109 ) )
goto V_237;
V_4 = F_121 ( V_4 , V_2 , V_218 ,
V_186 ,
V_222 -> V_109 ) ;
if ( F_95 ( V_40 ) == V_222 -> V_109 ) {
V_4 = F_101 ( V_2 ) ;
if ( ! V_4 )
break;
V_186 -> V_190 = V_40 -> V_146 ;
V_222 ++ ;
goto V_238;
}
V_4 = F_120 ( V_4 , V_2 , V_186 , V_222 -> V_109 ) ;
V_222 ++ ;
continue;
}
if ( ! F_56 ( V_164 , F_95 ( V_40 ) ) ) {
V_4 = F_101 ( V_2 ) ;
if ( ! V_4 )
break;
V_186 -> V_190 = V_40 -> V_146 ;
}
V_4 = F_120 ( V_4 , V_2 , V_186 , V_164 ) ;
V_238:
V_4 = F_118 ( V_4 , V_2 , V_218 , V_186 ,
V_164 , V_109 , V_173 ) ;
V_237:
V_230 ++ ;
}
for ( V_230 = 0 ; V_230 < F_123 ( V_40 -> V_223 ) - V_228 ; V_230 ++ ) {
V_40 -> V_223 [ V_230 ] . V_164 = 0 ;
V_40 -> V_223 [ V_230 ] . V_109 = 0 ;
}
for ( V_231 = 0 ; V_231 < V_228 ; V_231 ++ )
V_40 -> V_223 [ V_230 ++ ] = V_168 [ V_231 ] ;
if ( ( V_186 -> V_151 < V_40 -> V_146 ) &&
( ( F_8 ( V_2 ) -> V_145 != V_239 ) || V_40 -> V_148 ) )
F_78 ( V_2 , V_40 -> V_146 - V_186 -> V_151 , 0 ) ;
F_128 ( V_40 ) ;
V_215:
#if V_144 > 0
F_125 ( ( int ) V_40 -> V_147 < 0 ) ;
F_125 ( ( int ) V_40 -> V_162 < 0 ) ;
F_125 ( ( int ) V_40 -> V_192 < 0 ) ;
F_125 ( ( int ) F_129 ( V_40 ) < 0 ) ;
#endif
return V_186 -> V_194 ;
}
static bool F_130 ( struct V_39 * V_40 )
{
T_2 V_240 ;
V_240 = F_48 ( V_40 -> V_162 , 1U ) ;
V_240 = F_17 ( V_240 , V_40 -> V_130 ) ;
if ( ( V_40 -> V_147 + V_240 ) > V_40 -> V_130 ) {
V_40 -> V_147 = V_40 -> V_130 - V_240 ;
return true ;
}
return false ;
}
static void F_131 ( struct V_1 * V_2 , const int V_241 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_130 ( V_40 ) )
F_78 ( V_2 , V_40 -> V_130 + V_241 , 0 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_242 = V_40 -> V_147 ;
V_40 -> V_147 ++ ;
F_131 ( V_2 , 0 ) ;
if ( V_40 -> V_147 > V_242 )
V_40 -> V_199 ++ ;
F_128 ( V_40 ) ;
}
static void F_133 ( struct V_1 * V_2 , int V_243 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_243 > 0 ) {
V_40 -> V_199 += F_34 ( int , V_243 - V_40 -> V_147 , 1 ) ;
if ( V_243 - 1 >= V_40 -> V_147 )
V_40 -> V_147 = 0 ;
else
V_40 -> V_147 -= V_243 - 1 ;
}
F_131 ( V_2 , V_243 ) ;
F_128 ( V_40 ) ;
}
static inline void F_134 ( struct V_39 * V_40 )
{
V_40 -> V_147 = 0 ;
}
void F_135 ( struct V_39 * V_40 )
{
V_40 -> V_192 = 0 ;
V_40 -> V_162 = 0 ;
V_40 -> V_148 = 0 ;
V_40 -> V_149 = - 1 ;
V_40 -> V_146 = 0 ;
V_40 -> V_147 = 0 ;
}
static inline void F_136 ( struct V_39 * V_40 )
{
V_40 -> V_148 = V_40 -> V_122 ;
V_40 -> V_149 = V_40 -> V_192 ? : - 1 ;
}
void F_137 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_244 * V_244 = F_4 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_245 = V_13 -> V_145 < V_246 ;
bool V_247 ;
bool V_248 ;
if ( V_13 -> V_145 <= V_249 ||
! F_65 ( V_40 -> V_193 , V_40 -> V_122 ) ||
( V_13 -> V_145 == V_239 && ! V_13 -> V_250 ) ) {
V_40 -> V_251 = F_138 ( V_2 ) ;
V_40 -> V_127 = V_13 -> V_58 -> V_252 ( V_2 ) ;
F_28 ( V_2 , V_253 ) ;
F_136 ( V_40 ) ;
}
V_40 -> V_68 = 1 ;
V_40 -> V_254 = 0 ;
V_40 -> V_94 = V_95 ;
V_40 -> V_192 = 0 ;
V_40 -> V_162 = 0 ;
if ( F_80 ( V_40 ) )
F_134 ( V_40 ) ;
V_4 = F_112 ( V_2 ) ;
V_247 = V_4 && ( F_26 ( V_4 ) -> V_157 & V_161 ) ;
if ( V_247 ) {
F_81 ( F_4 ( V_2 ) , V_255 ) ;
V_40 -> V_147 = 0 ;
V_40 -> V_146 = 0 ;
}
F_139 ( V_40 ) ;
F_140 (skb, sk) {
if ( V_4 == F_117 ( V_2 ) )
break;
V_248 = ( ! ( F_26 ( V_4 ) -> V_157 & V_161 ) ||
V_247 ) ;
if ( V_248 )
F_83 ( V_40 , V_4 ) ;
F_26 ( V_4 ) -> V_157 &= ( ~ V_213 ) | V_161 ;
if ( V_248 ) {
F_26 ( V_4 ) -> V_157 &= ~ V_161 ;
F_26 ( V_4 ) -> V_157 |= V_158 ;
V_40 -> V_162 += F_84 ( V_4 ) ;
}
}
F_128 ( V_40 ) ;
if ( V_13 -> V_145 <= V_249 &&
V_40 -> V_147 >= V_244 -> V_256 . V_257 )
V_40 -> V_69 = F_10 (unsigned int, tp->reordering,
net->ipv4.sysctl_tcp_reordering) ;
F_141 ( V_2 , V_239 ) ;
V_40 -> V_193 = V_40 -> V_124 ;
F_22 ( V_40 ) ;
V_40 -> V_258 = V_259 &&
( V_245 || V_13 -> V_250 ) &&
! F_8 ( V_2 ) -> V_260 . V_261 ;
}
static bool F_142 ( struct V_1 * V_2 , int V_194 )
{
if ( V_194 & V_262 ) {
struct V_39 * V_40 = F_15 ( V_2 ) ;
unsigned long V_263 = F_48 ( F_143 ( V_40 -> V_118 >> 4 ) ,
F_144 ( 10 ) ) ;
F_145 ( V_2 , V_264 ,
V_263 , V_265 ) ;
return true ;
}
return false ;
}
static inline int F_146 ( const struct V_39 * V_40 )
{
return F_80 ( V_40 ) ? V_40 -> V_147 + 1 : V_40 -> V_146 ;
}
static inline int F_147 ( const struct V_39 * V_40 )
{
return F_76 ( V_40 ) ? V_40 -> V_146 : V_40 -> V_147 + 1 ;
}
static bool F_148 ( struct V_1 * V_2 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_162 )
return true ;
if ( F_147 ( V_40 ) > V_40 -> V_69 )
return true ;
return false ;
}
static void F_149 ( struct V_1 * V_2 , int V_266 , int V_267 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
int V_268 , V_269 , V_160 ;
unsigned int V_80 ;
const T_2 V_270 = F_150 ( V_40 ) ? V_40 -> V_124 : V_40 -> V_193 ;
F_125 ( V_266 > V_40 -> V_130 ) ;
if ( V_40 -> V_136 ) {
V_4 = V_40 -> V_136 ;
V_268 = V_40 -> V_200 ;
if ( V_267 && V_4 != F_112 ( V_2 ) )
return;
} else {
V_4 = F_112 ( V_2 ) ;
V_268 = 0 ;
}
F_119 (skb, sk) {
if ( V_4 == F_117 ( V_2 ) )
break;
V_40 -> V_136 = V_4 ;
V_40 -> V_200 = V_268 ;
if ( F_65 ( F_26 ( V_4 ) -> V_109 , V_270 ) )
break;
V_269 = V_268 ;
if ( F_76 ( V_40 ) || F_80 ( V_40 ) ||
( F_26 ( V_4 ) -> V_157 & V_161 ) )
V_268 += F_84 ( V_4 ) ;
if ( V_268 > V_266 ) {
if ( ( F_150 ( V_40 ) && ! F_76 ( V_40 ) ) ||
( F_26 ( V_4 ) -> V_157 & V_161 ) ||
( V_269 >= V_266 ) )
break;
V_80 = F_91 ( V_4 ) ;
V_160 = ( V_266 - V_269 ) * V_80 ;
if ( V_160 < V_4 -> V_5 &&
F_92 ( V_2 , V_4 , V_160 , V_80 , V_184 ) < 0 )
break;
V_268 = V_266 ;
}
F_85 ( V_40 , V_4 ) ;
if ( V_267 )
break;
}
F_128 ( V_40 ) ;
}
static void F_151 ( struct V_1 * V_2 , int V_271 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_80 ( V_40 ) ) {
F_149 ( V_2 , 1 , 1 ) ;
} else if ( F_76 ( V_40 ) ) {
int V_160 = V_40 -> V_146 - V_40 -> V_69 ;
if ( V_160 <= 0 )
V_160 = 1 ;
F_149 ( V_2 , V_160 , 0 ) ;
} else {
int V_272 = V_40 -> V_147 - V_40 -> V_69 ;
if ( V_272 >= 0 )
F_149 ( V_2 , V_272 , 0 ) ;
else if ( V_271 )
F_149 ( V_2 , 1 , 1 ) ;
}
}
static bool F_152 ( const struct V_39 * V_40 , T_2 V_273 )
{
return V_40 -> V_62 . V_274 && V_40 -> V_62 . V_108 &&
F_56 ( V_40 -> V_62 . V_108 , V_273 ) ;
}
static bool F_153 ( const struct V_39 * V_40 ,
const struct V_3 * V_4 )
{
return ( F_26 ( V_4 ) -> V_157 & V_191 ) &&
F_152 ( V_40 , F_154 ( V_4 ) ) ;
}
static inline bool F_155 ( const struct V_39 * V_40 )
{
return ! V_40 -> V_275 ||
F_152 ( V_40 , V_40 -> V_275 ) ;
}
static bool F_156 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_40 -> V_192 )
return true ;
V_4 = F_112 ( V_2 ) ;
if ( F_11 ( V_4 && F_26 ( V_4 ) -> V_157 & V_204 ) )
return true ;
return false ;
}
static void F_157 ( struct V_1 * V_2 , const char * V_276 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_277 * V_278 = F_158 ( V_2 ) ;
if ( V_2 -> V_279 == V_280 ) {
F_79 ( L_4 ,
V_276 ,
& V_278 -> V_281 , F_159 ( V_278 -> V_282 ) ,
V_40 -> V_68 , F_160 ( V_40 ) ,
V_40 -> V_127 , V_40 -> V_251 ,
V_40 -> V_130 ) ;
}
#if F_161 ( V_283 )
else if ( V_2 -> V_279 == V_284 ) {
F_79 ( L_5 ,
V_276 ,
& V_2 -> V_285 , F_159 ( V_278 -> V_282 ) ,
V_40 -> V_68 , F_160 ( V_40 ) ,
V_40 -> V_127 , V_40 -> V_251 ,
V_40 -> V_130 ) ;
}
#endif
}
static void F_162 ( struct V_1 * V_2 , bool V_286 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_286 ) {
struct V_3 * V_4 ;
F_140 (skb, sk) {
if ( V_4 == F_117 ( V_2 ) )
break;
F_26 ( V_4 ) -> V_157 &= ~ V_158 ;
}
V_40 -> V_162 = 0 ;
F_139 ( V_40 ) ;
}
if ( V_40 -> V_251 ) {
const struct V_12 * V_13 = F_8 ( V_2 ) ;
V_40 -> V_68 = V_13 -> V_58 -> V_287 ( V_2 ) ;
if ( V_40 -> V_251 > V_40 -> V_127 ) {
V_40 -> V_127 = V_40 -> V_251 ;
F_24 ( V_40 ) ;
}
}
V_40 -> V_94 = V_95 ;
V_40 -> V_148 = 0 ;
}
static inline bool F_163 ( const struct V_39 * V_40 )
{
return V_40 -> V_148 && ( ! V_40 -> V_149 || F_155 ( V_40 ) ) ;
}
static bool F_164 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_163 ( V_40 ) ) {
int V_142 ;
F_157 ( V_2 , F_8 ( V_2 ) -> V_145 == V_239 ? L_6 : L_7 ) ;
F_162 ( V_2 , false ) ;
if ( F_8 ( V_2 ) -> V_145 == V_239 )
V_142 = V_288 ;
else
V_142 = V_289 ;
F_81 ( F_4 ( V_2 ) , V_142 ) ;
}
if ( V_40 -> V_122 == V_40 -> V_193 && F_80 ( V_40 ) ) {
if ( ! F_156 ( V_2 ) )
V_40 -> V_275 = 0 ;
return true ;
}
F_141 ( V_2 , V_290 ) ;
return false ;
}
static bool F_165 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_148 && ! V_40 -> V_149 ) {
F_157 ( V_2 , L_8 ) ;
F_162 ( V_2 , false ) ;
F_81 ( F_4 ( V_2 ) , V_291 ) ;
return true ;
}
return false ;
}
static bool F_166 ( struct V_1 * V_2 , bool V_292 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_292 || F_163 ( V_40 ) ) {
F_162 ( V_2 , true ) ;
F_157 ( V_2 , L_9 ) ;
F_81 ( F_4 ( V_2 ) , V_288 ) ;
if ( V_292 )
F_81 ( F_4 ( V_2 ) ,
V_293 ) ;
F_8 ( V_2 ) -> V_250 = 0 ;
if ( V_292 || F_150 ( V_40 ) )
F_141 ( V_2 , V_290 ) ;
return true ;
}
return false ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
V_40 -> V_193 = V_40 -> V_124 ;
V_40 -> V_294 = 0 ;
V_40 -> V_254 = 0 ;
V_40 -> V_295 = V_40 -> V_68 ;
V_40 -> V_296 = 0 ;
V_40 -> V_297 = 0 ;
V_40 -> V_127 = F_8 ( V_2 ) -> V_58 -> V_252 ( V_2 ) ;
F_22 ( V_40 ) ;
}
void F_168 ( struct V_1 * V_2 , int V_298 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_299 = 0 ;
int V_300 = V_40 -> V_127 - F_129 ( V_40 ) ;
if ( V_298 <= 0 || F_169 ( ! V_40 -> V_295 ) )
return;
V_40 -> V_296 += V_298 ;
if ( V_300 < 0 ) {
T_3 V_301 = ( T_3 ) V_40 -> V_127 * V_40 -> V_296 +
V_40 -> V_295 - 1 ;
V_299 = F_170 ( V_301 , V_40 -> V_295 ) - V_40 -> V_297 ;
} else if ( ( V_194 & V_302 ) &&
! ( V_194 & V_303 ) ) {
V_299 = F_10 ( int , V_300 ,
F_34 ( int , V_40 -> V_296 - V_40 -> V_297 ,
V_298 ) + 1 ) ;
} else {
V_299 = F_17 ( V_300 , V_298 ) ;
}
V_299 = F_48 ( V_299 , ( V_40 -> V_297 ? 0 : 1 ) ) ;
V_40 -> V_68 = F_129 ( V_40 ) + V_299 ;
}
static inline void F_171 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_58 -> V_304 )
return;
if ( F_8 ( V_2 ) -> V_145 == V_305 ||
( V_40 -> V_148 && V_40 -> V_127 < V_306 ) ) {
V_40 -> V_68 = V_40 -> V_127 ;
V_40 -> V_94 = V_95 ;
}
F_28 ( V_2 , V_307 ) ;
}
void F_172 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
V_40 -> V_251 = 0 ;
if ( F_8 ( V_2 ) -> V_145 < V_305 ) {
V_40 -> V_148 = 0 ;
F_167 ( V_2 ) ;
F_141 ( V_2 , V_305 ) ;
}
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_186 = V_290 ;
if ( F_160 ( V_40 ) || F_156 ( V_2 ) )
V_186 = V_249 ;
if ( F_8 ( V_2 ) -> V_145 != V_186 ) {
F_141 ( V_2 , V_186 ) ;
V_40 -> V_193 = V_40 -> V_124 ;
}
}
static void F_174 ( struct V_1 * V_2 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_128 ( V_40 ) ;
if ( ! F_156 ( V_2 ) )
V_40 -> V_275 = 0 ;
if ( V_194 & V_308 )
F_172 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_145 != V_305 ) {
F_173 ( V_2 ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_260 . V_309 = V_13 -> V_260 . V_261 - 1 ;
V_13 -> V_260 . V_261 = 0 ;
F_81 ( F_4 ( V_2 ) , V_310 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_40 -> V_251 = F_138 ( V_2 ) ;
V_40 -> V_68 = V_40 -> V_68 *
F_177 ( V_2 , V_40 -> V_64 ) /
V_13 -> V_260 . V_261 ;
V_40 -> V_254 = 0 ;
V_40 -> V_94 = V_95 ;
V_40 -> V_127 = F_138 ( V_2 ) ;
V_13 -> V_260 . V_311 = V_13 -> V_260 . V_261 ;
V_13 -> V_260 . V_261 = 0 ;
F_178 ( V_2 , V_13 -> V_312 ) ;
F_81 ( F_4 ( V_2 ) , V_313 ) ;
}
void F_179 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_80 = F_180 ( V_2 ) ;
T_2 V_314 = V_40 -> V_162 ;
F_140 (skb, sk) {
if ( V_4 == F_117 ( V_2 ) )
break;
if ( F_106 ( V_4 ) > V_80 &&
! ( F_26 ( V_4 ) -> V_157 & V_161 ) ) {
if ( F_26 ( V_4 ) -> V_157 & V_159 ) {
F_26 ( V_4 ) -> V_157 &= ~ V_159 ;
V_40 -> V_192 -= F_84 ( V_4 ) ;
}
F_86 ( V_40 , V_4 ) ;
}
}
F_181 ( V_40 ) ;
if ( V_314 == V_40 -> V_162 )
return;
if ( F_80 ( V_40 ) )
F_130 ( V_40 ) ;
F_128 ( V_40 ) ;
if ( V_13 -> V_145 != V_239 ) {
V_40 -> V_193 = V_40 -> V_124 ;
V_40 -> V_127 = F_138 ( V_2 ) ;
V_40 -> V_251 = 0 ;
V_40 -> V_148 = 0 ;
F_141 ( V_2 , V_239 ) ;
}
F_182 ( V_2 ) ;
}
void F_183 ( struct V_1 * V_2 , bool V_315 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_142 ;
if ( F_80 ( V_40 ) )
V_142 = V_316 ;
else
V_142 = V_317 ;
F_81 ( F_4 ( V_2 ) , V_142 ) ;
V_40 -> V_251 = 0 ;
F_136 ( V_40 ) ;
if ( ! F_184 ( V_2 ) ) {
if ( ! V_315 )
V_40 -> V_251 = F_138 ( V_2 ) ;
F_167 ( V_2 ) ;
}
F_141 ( V_2 , V_246 ) ;
}
static void F_185 ( struct V_1 * V_2 , int V_194 , bool V_318 ,
int * V_319 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_320 = ! F_56 ( V_40 -> V_122 , V_40 -> V_193 ) ;
if ( ( V_194 & V_321 ) &&
F_166 ( V_2 , false ) )
return;
if ( ( V_194 & V_195 ) &&
F_166 ( V_2 , V_40 -> V_148 ) )
return;
if ( V_40 -> V_258 ) {
if ( F_65 ( V_40 -> V_124 , V_40 -> V_193 ) ) {
if ( V_194 & V_198 || V_318 )
V_40 -> V_258 = 0 ;
} else if ( V_194 & V_321 && ! V_320 ) {
V_40 -> V_193 = V_40 -> V_124 ;
if ( F_117 ( V_2 ) &&
F_65 ( F_186 ( V_40 ) , V_40 -> V_124 ) ) {
* V_319 = V_322 ;
return;
}
V_40 -> V_258 = 0 ;
}
}
if ( V_320 ) {
F_164 ( V_2 ) ;
return;
}
if ( F_80 ( V_40 ) ) {
if ( F_65 ( V_40 -> V_124 , V_40 -> V_193 ) && V_318 )
F_132 ( V_2 ) ;
else if ( V_194 & V_321 )
F_134 ( V_40 ) ;
}
* V_319 = V_323 ;
}
static bool F_187 ( struct V_1 * V_2 , const int V_243 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_148 && F_155 ( V_40 ) ) {
F_78 ( V_2 , F_146 ( V_40 ) + V_243 , 1 ) ;
if ( V_40 -> V_192 )
return true ;
if ( ! F_156 ( V_2 ) )
V_40 -> V_275 = 0 ;
F_157 ( V_2 , L_10 ) ;
F_162 ( V_2 , true ) ;
F_81 ( F_4 ( V_2 ) , V_324 ) ;
F_173 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_188 ( struct V_1 * V_2 , int * V_325 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_326 & V_327 ) {
T_2 V_328 = V_40 -> V_192 ;
F_189 ( V_2 ) ;
if ( V_328 > V_40 -> V_192 )
* V_325 |= V_303 ;
}
}
static void F_190 ( struct V_1 * V_2 , const int V_243 ,
bool V_318 , int * V_325 , int * V_319 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_271 = 0 , V_194 = * V_325 ;
bool V_329 = V_318 || ( ( V_194 & V_198 ) &&
( F_146 ( V_40 ) > V_40 -> V_69 ) ) ;
if ( F_125 ( ! V_40 -> V_130 && V_40 -> V_147 ) )
V_40 -> V_147 = 0 ;
if ( F_125 ( ! V_40 -> V_147 && V_40 -> V_146 ) )
V_40 -> V_146 = 0 ;
if ( V_194 & V_308 )
V_40 -> V_251 = 0 ;
if ( F_142 ( V_2 , V_194 ) )
return;
F_128 ( V_40 ) ;
if ( V_13 -> V_145 == V_290 ) {
F_125 ( V_40 -> V_192 != 0 ) ;
V_40 -> V_275 = 0 ;
} else if ( ! F_56 ( V_40 -> V_122 , V_40 -> V_193 ) ) {
switch ( V_13 -> V_145 ) {
case V_305 :
if ( V_40 -> V_122 != V_40 -> V_193 ) {
F_171 ( V_2 ) ;
F_141 ( V_2 , V_290 ) ;
}
break;
case V_246 :
if ( F_80 ( V_40 ) )
F_134 ( V_40 ) ;
if ( F_164 ( V_2 ) )
return;
F_171 ( V_2 ) ;
break;
}
}
switch ( V_13 -> V_145 ) {
case V_246 :
if ( ! ( V_194 & V_321 ) ) {
if ( F_80 ( V_40 ) && V_318 )
F_132 ( V_2 ) ;
} else {
if ( F_187 ( V_2 , V_243 ) )
return;
V_329 = F_80 ( V_40 ) ||
F_146 ( V_40 ) > V_40 -> V_69 ;
}
if ( F_165 ( V_2 ) ) {
F_173 ( V_2 ) ;
return;
}
F_188 ( V_2 , V_325 ) ;
break;
case V_239 :
F_185 ( V_2 , V_194 , V_318 , V_319 ) ;
F_188 ( V_2 , V_325 ) ;
if ( ! ( V_13 -> V_145 == V_290 ||
( * V_325 & V_303 ) ) )
return;
default:
if ( F_80 ( V_40 ) ) {
if ( V_194 & V_321 )
F_134 ( V_40 ) ;
if ( V_318 )
F_132 ( V_2 ) ;
}
if ( V_13 -> V_145 <= V_249 )
F_165 ( V_2 ) ;
F_188 ( V_2 , V_325 ) ;
if ( ! F_148 ( V_2 , V_194 ) ) {
F_174 ( V_2 , V_194 ) ;
return;
}
if ( V_13 -> V_145 < V_305 &&
V_13 -> V_260 . V_261 &&
V_40 -> V_122 == V_40 -> V_330 . V_331 ) {
F_175 ( V_2 ) ;
V_40 -> V_68 ++ ;
F_179 ( V_2 ) ;
return;
}
F_183 ( V_2 , ( V_194 & V_308 ) ) ;
V_271 = 1 ;
}
if ( V_329 )
F_151 ( V_2 , V_271 ) ;
* V_319 = V_323 ;
}
static void F_191 ( struct V_1 * V_2 , T_2 V_102 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_332 = V_333 * V_334 ;
F_192 ( & V_40 -> V_335 , V_332 , V_95 ,
V_102 ? : F_59 ( 1 ) ) ;
}
static inline bool F_193 ( struct V_1 * V_2 , const int V_194 ,
long V_336 , long V_337 ,
long V_338 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_336 < 0 )
V_336 = V_337 ;
if ( V_336 < 0 && V_40 -> V_62 . V_274 && V_40 -> V_62 . V_108 &&
V_194 & V_339 )
V_336 = V_338 = F_59 ( V_95 -
V_40 -> V_62 . V_108 ) ;
if ( V_336 < 0 )
return false ;
F_191 ( V_2 , V_338 ) ;
F_64 ( V_2 , V_336 ) ;
F_71 ( V_2 ) ;
F_8 ( V_2 ) -> V_340 = 0 ;
return true ;
}
void F_194 ( struct V_1 * V_2 , struct V_341 * V_342 )
{
long V_102 = - 1L ;
if ( V_342 && ! V_342 -> V_343 && F_195 ( V_342 ) -> V_344 . V_105 ) {
struct V_188 V_113 ;
F_46 ( & V_113 ) ;
V_102 = F_57 ( & V_113 , & F_195 ( V_342 ) -> V_344 ) ;
}
F_193 ( V_2 , V_345 , V_102 , - 1L , V_102 ) ;
}
static void F_196 ( struct V_1 * V_2 , T_2 V_346 , T_2 V_243 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_58 -> V_347 ( V_2 , V_346 , V_243 ) ;
F_15 ( V_2 ) -> V_94 = V_95 ;
}
void F_197 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_348 )
return;
if ( ! V_40 -> V_130 ) {
F_198 ( V_2 , V_264 ) ;
} else {
T_2 V_349 = F_8 ( V_2 ) -> V_115 ;
if ( V_13 -> V_350 == V_351 ||
V_13 -> V_350 == V_352 ) {
struct V_3 * V_4 = F_112 ( V_2 ) ;
const T_2 V_353 =
F_154 ( V_4 ) + V_349 ;
T_7 V_300 = ( T_7 ) ( V_353 - V_95 ) ;
if ( V_300 > 0 )
V_349 = V_300 ;
}
F_145 ( V_2 , V_264 , V_349 ,
V_265 ) ;
}
}
static T_2 F_199 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_354 ;
F_98 ( ! F_65 ( F_26 ( V_4 ) -> V_109 , V_40 -> V_122 ) ) ;
V_354 = F_84 ( V_4 ) ;
if ( F_200 ( V_2 , V_4 , V_40 -> V_122 - F_26 ( V_4 ) -> V_91 ) )
return 0 ;
V_354 -= F_84 ( V_4 ) ;
if ( V_354 ) {
F_98 ( F_84 ( V_4 ) == 0 ) ;
F_98 ( ! F_56 ( F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_109 ) ) ;
}
return V_354 ;
}
static void F_201 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_170 )
{
const struct V_66 * V_355 ;
if ( F_68 ( ! F_26 ( V_4 ) -> V_356 ) )
return;
V_355 = F_9 ( V_4 ) ;
if ( ! F_56 ( V_355 -> V_357 , V_170 ) &&
F_56 ( V_355 -> V_357 , F_15 ( V_2 ) -> V_122 ) )
F_202 ( V_4 , NULL , V_2 , V_358 ) ;
}
static int F_203 ( struct V_1 * V_2 , int V_359 ,
T_2 V_170 , int * V_243 ,
struct V_185 * V_360 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_188 V_361 , V_362 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_188 * V_113 = & V_40 -> V_90 ;
T_2 V_242 = V_40 -> V_147 ;
T_2 V_151 = V_40 -> V_130 ;
bool V_363 = true ;
long V_337 = - 1L ;
long V_336 = - 1L ;
long V_338 = - 1L ;
struct V_3 * V_4 ;
T_2 V_364 = 0 ;
T_2 V_365 = 0 ;
bool V_366 ;
int V_194 = 0 ;
V_361 . V_105 = 0 ;
while ( ( V_4 = F_112 ( V_2 ) ) && V_4 != F_117 ( V_2 ) ) {
struct V_367 * V_368 = F_26 ( V_4 ) ;
T_6 V_157 = V_368 -> V_157 ;
T_2 V_369 ;
F_201 ( V_2 , V_4 , V_170 ) ;
if ( F_65 ( V_368 -> V_109 , V_40 -> V_122 ) ) {
if ( F_84 ( V_4 ) == 1 ||
! F_65 ( V_40 -> V_122 , V_368 -> V_91 ) )
break;
V_369 = F_199 ( V_2 , V_4 ) ;
if ( ! V_369 )
break;
V_363 = false ;
} else {
F_204 ( V_4 -> V_370 ) ;
V_369 = F_84 ( V_4 ) ;
}
if ( F_11 ( V_157 & V_191 ) ) {
if ( V_157 & V_159 )
V_40 -> V_192 -= V_369 ;
V_194 |= V_302 ;
} else if ( ! ( V_157 & V_161 ) ) {
V_362 = V_4 -> V_188 ;
F_169 ( V_362 . V_105 == 0 ) ;
if ( ! V_361 . V_105 )
V_361 = V_362 ;
V_365 = F_26 ( V_4 ) -> V_209 . V_371 ;
V_151 = F_17 ( V_364 , V_151 ) ;
if ( ! F_65 ( V_368 -> V_109 , V_40 -> V_193 ) )
V_194 |= V_195 ;
}
if ( V_157 & V_161 ) {
V_40 -> V_147 -= V_369 ;
} else if ( F_150 ( V_40 ) ) {
V_40 -> V_199 += V_369 ;
if ( ! F_153 ( V_40 , V_4 ) )
F_94 ( V_40 , V_157 , V_368 -> V_109 ,
& V_4 -> V_188 ) ;
}
if ( V_157 & V_158 )
V_40 -> V_162 -= V_369 ;
V_40 -> V_130 -= V_369 ;
V_364 += V_369 ;
F_99 ( V_2 , V_4 , V_360 -> V_125 ) ;
if ( F_68 ( ! ( V_368 -> V_206 & V_372 ) ) ) {
V_194 |= V_373 ;
} else {
V_194 |= V_345 ;
V_40 -> V_275 = 0 ;
}
if ( ! V_363 )
break;
F_104 ( V_4 , V_2 ) ;
F_105 ( V_2 , V_4 ) ;
if ( F_11 ( V_4 == V_40 -> V_156 ) )
V_40 -> V_156 = NULL ;
if ( F_11 ( V_4 == V_40 -> V_136 ) )
V_40 -> V_136 = NULL ;
}
if ( ! V_4 )
F_205 ( V_2 , V_374 ) ;
if ( F_68 ( F_206 ( V_40 -> V_375 , V_170 , V_40 -> V_122 ) ) )
V_40 -> V_375 = V_40 -> V_122 ;
if ( V_4 && ( F_26 ( V_4 ) -> V_157 & V_161 ) )
V_194 |= V_262 ;
if ( F_68 ( V_361 . V_105 ) && ! ( V_194 & V_302 ) ) {
V_336 = F_57 ( V_113 , & V_361 ) ;
V_338 = F_57 ( V_113 , & V_362 ) ;
}
if ( V_360 -> V_196 . V_105 ) {
V_337 = F_57 ( V_113 , & V_360 -> V_196 ) ;
V_338 = F_57 ( V_113 , & V_360 -> V_197 ) ;
}
V_360 -> V_125 -> V_102 = V_338 ;
V_366 = F_193 ( V_2 , V_194 , V_336 , V_337 ,
V_338 ) ;
if ( V_194 & V_339 ) {
F_197 ( V_2 ) ;
if ( F_11 ( V_13 -> V_260 . V_261 &&
! F_65 ( V_40 -> V_330 . V_376 , V_40 -> V_122 ) ) ) {
F_176 ( V_2 ) ;
}
if ( F_80 ( V_40 ) ) {
F_133 ( V_2 , V_364 ) ;
} else {
int V_300 ;
if ( V_151 < V_359 && V_151 <= V_40 -> V_146 )
F_78 ( V_2 , V_40 -> V_146 - V_151 , 0 ) ;
V_300 = F_76 ( V_40 ) ? V_364 :
V_242 - V_40 -> V_147 ;
V_40 -> V_200 -= F_17 ( V_40 -> V_200 , V_300 ) ;
}
V_40 -> V_146 -= F_17 ( V_364 , V_40 -> V_146 ) ;
} else if ( V_4 && V_366 && V_337 >= 0 &&
V_337 > F_57 ( V_113 , & V_4 -> V_188 ) ) {
F_197 ( V_2 ) ;
}
if ( V_13 -> V_58 -> V_364 ) {
struct V_377 V_98 = { . V_364 = V_364 ,
. V_102 = V_338 ,
. V_371 = V_365 } ;
V_13 -> V_58 -> V_364 ( V_2 , & V_98 ) ;
}
#if V_144 > 0
F_125 ( ( int ) V_40 -> V_147 < 0 ) ;
F_125 ( ( int ) V_40 -> V_162 < 0 ) ;
F_125 ( ( int ) V_40 -> V_192 < 0 ) ;
if ( ! V_40 -> V_130 && F_150 ( V_40 ) ) {
V_13 = F_8 ( V_2 ) ;
if ( V_40 -> V_162 ) {
F_79 ( L_11 ,
V_40 -> V_162 , V_13 -> V_145 ) ;
V_40 -> V_162 = 0 ;
}
if ( V_40 -> V_147 ) {
F_79 ( L_12 ,
V_40 -> V_147 , V_13 -> V_145 ) ;
V_40 -> V_147 = 0 ;
}
if ( V_40 -> V_192 ) {
F_79 ( L_13 ,
V_40 -> V_192 , V_13 -> V_145 ) ;
V_40 -> V_192 = 0 ;
}
}
#endif
* V_243 = V_364 ;
return V_194 ;
}
static void F_207 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( ! F_65 ( F_26 ( F_117 ( V_2 ) ) -> V_109 , F_186 ( V_40 ) ) ) {
V_13 -> V_340 = 0 ;
F_198 ( V_2 , V_378 ) ;
} else {
unsigned long V_273 = F_208 ( V_2 , V_265 ) ;
F_145 ( V_2 , V_378 ,
V_273 , V_265 ) ;
}
}
static inline bool F_209 ( const struct V_1 * V_2 , const int V_194 )
{
return ! ( V_194 & V_379 ) || ( V_194 & V_380 ) ||
F_8 ( V_2 ) -> V_145 != V_290 ;
}
static inline bool F_210 ( const struct V_1 * V_2 , const int V_194 )
{
if ( F_15 ( V_2 ) -> V_69 > F_4 ( V_2 ) -> V_256 . V_257 )
return V_194 & V_381 ;
return V_194 & V_373 ;
}
static void F_211 ( struct V_1 * V_2 , T_2 V_346 , T_2 V_382 ,
int V_194 , const struct V_383 * V_384 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( V_13 -> V_58 -> V_304 ) {
V_13 -> V_58 -> V_304 ( V_2 , V_384 ) ;
return;
}
if ( F_184 ( V_2 ) ) {
F_168 ( V_2 , V_382 , V_194 ) ;
} else if ( F_210 ( V_2 , V_194 ) ) {
F_196 ( V_2 , V_346 , V_382 ) ;
}
F_67 ( V_2 ) ;
}
static inline bool F_212 ( const struct V_39 * V_40 ,
const T_2 V_346 , const T_2 V_174 ,
const T_2 V_385 )
{
return F_65 ( V_346 , V_40 -> V_122 ) ||
F_65 ( V_174 , V_40 -> V_386 ) ||
( V_174 == V_40 -> V_386 && V_385 > V_40 -> V_387 ) ;
}
static void F_213 ( struct V_39 * V_40 , T_2 V_346 )
{
T_2 V_300 = V_346 - V_40 -> V_122 ;
F_214 ( (struct V_1 * ) V_40 ) ;
V_40 -> V_388 += V_300 ;
V_40 -> V_122 = V_346 ;
}
static void F_215 ( struct V_39 * V_40 , T_2 V_91 )
{
T_2 V_300 = V_91 - V_40 -> V_107 ;
F_214 ( (struct V_1 * ) V_40 ) ;
V_40 -> V_389 += V_300 ;
V_40 -> V_107 = V_91 ;
}
static int F_216 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_2 V_346 ,
T_2 V_174 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_194 = 0 ;
T_2 V_385 = F_159 ( F_14 ( V_4 ) -> V_74 ) ;
if ( F_68 ( ! F_14 ( V_4 ) -> V_55 ) )
V_385 <<= V_40 -> V_62 . V_390 ;
if ( F_212 ( V_40 , V_346 , V_174 , V_385 ) ) {
V_194 |= V_391 ;
F_217 ( V_40 , V_174 ) ;
if ( V_40 -> V_387 != V_385 ) {
V_40 -> V_387 = V_385 ;
V_40 -> V_392 = 0 ;
F_218 ( V_2 ) ;
if ( F_117 ( V_2 ) )
F_219 ( V_2 ) ;
if ( V_385 > V_40 -> V_165 ) {
V_40 -> V_165 = V_385 ;
F_178 ( V_2 , F_8 ( V_2 ) -> V_312 ) ;
}
}
}
F_213 ( V_40 , V_346 ) ;
return V_194 ;
}
static bool F_220 ( struct V_244 * V_244 , int V_142 ,
T_2 * V_393 )
{
if ( * V_393 ) {
T_7 V_394 = ( T_7 ) ( V_95 - * V_393 ) ;
if ( 0 <= V_394 && V_394 < V_395 ) {
F_81 ( V_244 , V_142 ) ;
return true ;
}
}
* V_393 = V_95 ;
return false ;
}
bool F_221 ( struct V_244 * V_244 , const struct V_3 * V_4 ,
int V_142 , T_2 * V_393 )
{
if ( ( F_26 ( V_4 ) -> V_91 != F_26 ( V_4 ) -> V_109 ) &&
! F_14 ( V_4 ) -> V_55 )
return false ;
return F_220 ( V_244 , V_142 , V_393 ) ;
}
static void F_222 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_2 V_396 ;
static unsigned int V_397 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_398 , V_113 ;
if ( F_220 ( F_4 ( V_2 ) ,
V_399 ,
& V_40 -> V_393 ) )
return;
V_113 = V_400 / V_334 ;
if ( V_113 != V_396 ) {
T_2 V_401 = ( V_402 + 1 ) >> 1 ;
V_396 = V_113 ;
F_223 ( V_397 , V_401 +
F_224 ( V_402 ) ) ;
}
V_398 = F_225 ( V_397 ) ;
if ( V_398 > 0 ) {
F_223 ( V_397 , V_398 - 1 ) ;
F_81 ( F_4 ( V_2 ) , V_403 ) ;
F_226 ( V_2 ) ;
}
}
static void F_227 ( struct V_39 * V_40 )
{
V_40 -> V_62 . V_404 = V_40 -> V_62 . V_405 ;
V_40 -> V_62 . V_406 = F_228 () ;
}
static void F_229 ( struct V_39 * V_40 , T_2 V_91 )
{
if ( V_40 -> V_62 . V_274 && ! F_65 ( V_91 , V_40 -> V_407 ) ) {
if ( F_230 ( & V_40 -> V_62 , 0 ) )
F_227 ( V_40 ) ;
}
}
static void F_231 ( struct V_1 * V_2 , T_2 V_346 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_56 ( V_346 , V_40 -> V_294 ) )
return;
if ( V_194 & V_233 ) {
V_40 -> V_294 = 0 ;
} else if ( F_65 ( V_346 , V_40 -> V_294 ) ) {
F_167 ( V_2 ) ;
F_141 ( V_2 , V_305 ) ;
F_171 ( V_2 ) ;
F_173 ( V_2 ) ;
F_81 ( F_4 ( V_2 ) ,
V_408 ) ;
} else if ( ! ( V_194 & ( V_321 |
V_379 | V_198 ) ) ) {
V_40 -> V_294 = 0 ;
}
}
static inline void F_232 ( struct V_1 * V_2 , T_2 V_409 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( V_13 -> V_58 -> V_410 )
V_13 -> V_58 -> V_410 ( V_2 , V_409 ) ;
}
static void F_233 ( struct V_1 * V_2 , int V_319 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_319 == V_411 )
return;
if ( F_11 ( V_319 == 2 ) ) {
F_234 ( V_2 , F_180 ( V_2 ) ,
V_412 ) ;
if ( F_65 ( V_40 -> V_124 , V_40 -> V_193 ) )
return;
V_40 -> V_258 = 0 ;
}
F_182 ( V_2 ) ;
}
static int F_235 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_194 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_185 V_413 ;
struct V_383 V_384 = { . V_414 = 0 } ;
T_2 V_170 = V_40 -> V_122 ;
T_2 V_174 = F_26 ( V_4 ) -> V_91 ;
T_2 V_346 = F_26 ( V_4 ) -> V_174 ;
bool V_318 = false ;
T_2 V_359 ;
int V_415 = V_40 -> V_130 ;
T_2 V_199 = V_40 -> V_199 ;
T_2 V_160 = V_40 -> V_160 ;
int V_243 = 0 ;
int V_319 = V_411 ;
V_413 . V_196 . V_105 = 0 ;
V_413 . V_125 = & V_384 ;
F_204 ( V_2 -> V_416 . V_370 ) ;
if ( F_56 ( V_346 , V_170 ) ) {
if ( F_56 ( V_346 , V_170 - V_40 -> V_165 ) ) {
F_222 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_417;
}
if ( F_65 ( V_346 , V_40 -> V_124 ) )
goto V_418;
if ( V_13 -> V_350 == V_352 )
F_197 ( V_2 ) ;
if ( F_65 ( V_346 , V_170 ) ) {
V_194 |= V_321 ;
V_13 -> V_250 = 0 ;
}
V_359 = V_40 -> V_146 ;
V_384 . V_419 = F_129 ( V_40 ) ;
if ( V_194 & V_420 )
F_229 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! ( V_194 & V_421 ) && F_65 ( V_346 , V_170 ) ) {
F_217 ( V_40 , V_174 ) ;
F_213 ( V_40 , V_346 ) ;
V_194 |= V_391 ;
F_232 ( V_2 , V_422 ) ;
F_81 ( F_4 ( V_2 ) , V_423 ) ;
} else {
T_2 V_424 = V_425 ;
if ( V_174 != F_26 ( V_4 ) -> V_109 )
V_194 |= V_426 ;
else
F_81 ( F_4 ( V_2 ) , V_427 ) ;
V_194 |= F_216 ( V_2 , V_4 , V_346 , V_174 ) ;
if ( F_26 ( V_4 ) -> V_157 )
V_194 |= F_124 ( V_2 , V_4 , V_170 ,
& V_413 ) ;
if ( F_32 ( V_40 , F_14 ( V_4 ) ) ) {
V_194 |= V_308 ;
V_424 |= V_428 ;
}
if ( V_194 & V_391 )
V_424 |= V_422 ;
F_232 ( V_2 , V_424 ) ;
}
V_2 -> V_429 = 0 ;
V_13 -> V_430 = 0 ;
V_40 -> V_431 = V_95 ;
if ( ! V_415 )
goto V_432;
V_194 |= F_203 ( V_2 , V_359 , V_170 , & V_243 ,
& V_413 ) ;
if ( F_209 ( V_2 , V_194 ) ) {
V_318 = ! ( V_194 & ( V_321 | V_379 ) ) ;
F_190 ( V_2 , V_243 , V_318 , & V_194 , & V_319 ) ;
}
if ( V_40 -> V_294 )
F_231 ( V_2 , V_346 , V_194 ) ;
if ( ( V_194 & V_381 ) || ! ( V_194 & V_379 ) )
F_236 ( V_2 ) ;
if ( V_13 -> V_350 == V_264 )
F_237 ( V_2 ) ;
V_199 = V_40 -> V_199 - V_199 ;
V_160 = V_40 -> V_160 - V_160 ;
F_238 ( V_2 , V_199 , V_160 , V_413 . V_125 ) ;
F_211 ( V_2 , V_346 , V_199 , V_194 , V_413 . V_125 ) ;
F_233 ( V_2 , V_319 ) ;
return 1 ;
V_432:
if ( V_194 & V_233 )
F_190 ( V_2 , V_243 , V_318 , & V_194 , & V_319 ) ;
if ( F_117 ( V_2 ) )
F_207 ( V_2 ) ;
if ( V_40 -> V_294 )
F_231 ( V_2 , V_346 , V_194 ) ;
return 1 ;
V_418:
F_239 ( V_2 , L_14 , V_346 , V_40 -> V_122 , V_40 -> V_124 ) ;
return - 1 ;
V_417:
if ( F_26 ( V_4 ) -> V_157 ) {
V_194 |= F_124 ( V_2 , V_4 , V_170 ,
& V_413 ) ;
F_190 ( V_2 , V_243 , V_318 , & V_194 , & V_319 ) ;
F_233 ( V_2 , V_319 ) ;
}
F_239 ( V_2 , L_15 , V_346 , V_40 -> V_122 , V_40 -> V_124 ) ;
return 0 ;
}
static void F_240 ( int V_5 , const unsigned char * V_433 ,
bool V_55 , struct V_434 * V_435 ,
bool V_436 )
{
if ( ! V_435 || ! V_55 || V_5 < 0 || ( V_5 & 1 ) )
return;
if ( V_5 >= V_437 &&
V_5 <= V_438 )
memcpy ( V_435 -> V_439 , V_433 , V_5 ) ;
else if ( V_5 != 0 )
V_5 = - 1 ;
V_435 -> V_5 = V_5 ;
V_435 -> exp = V_436 ;
}
void F_241 ( const struct V_3 * V_4 ,
struct V_440 * V_441 , int V_442 ,
struct V_434 * V_435 )
{
const unsigned char * V_224 ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
int V_443 = ( V_53 -> V_444 * 4 ) - sizeof( struct V_22 ) ;
V_224 = ( const unsigned char * ) ( V_53 + 1 ) ;
V_441 -> V_274 = 0 ;
while ( V_443 > 0 ) {
int V_445 = * V_224 ++ ;
int V_446 ;
switch ( V_445 ) {
case V_447 :
return;
case V_448 :
V_443 -- ;
continue;
default:
V_446 = * V_224 ++ ;
if ( V_446 < 2 )
return;
if ( V_446 > V_443 )
return;
switch ( V_445 ) {
case V_449 :
if ( V_446 == V_450 && V_53 -> V_55 && ! V_442 ) {
T_8 V_451 = F_242 ( V_224 ) ;
if ( V_451 ) {
if ( V_441 -> V_452 &&
V_441 -> V_452 < V_451 )
V_451 = V_441 -> V_452 ;
V_441 -> V_63 = V_451 ;
}
}
break;
case V_453 :
if ( V_446 == V_454 && V_53 -> V_55 &&
! V_442 && V_455 ) {
T_5 V_390 = * ( T_5 * ) V_224 ;
V_441 -> V_456 = 1 ;
if ( V_390 > V_457 ) {
F_243 ( L_16 ,
V_458 ,
V_390 ,
V_457 ) ;
V_390 = V_457 ;
}
V_441 -> V_390 = V_390 ;
}
break;
case V_459 :
if ( ( V_446 == V_460 ) &&
( ( V_442 && V_441 -> V_461 ) ||
( ! V_442 && V_462 ) ) ) {
V_441 -> V_274 = 1 ;
V_441 -> V_405 = F_89 ( V_224 ) ;
V_441 -> V_108 = F_89 ( V_224 + 4 ) ;
}
break;
case V_463 :
if ( V_446 == V_464 && V_53 -> V_55 &&
! V_442 && V_465 ) {
V_441 -> V_137 = V_466 ;
F_244 ( V_441 ) ;
}
break;
case V_467 :
if ( ( V_446 >= ( V_227 + V_468 ) ) &&
! ( ( V_446 - V_227 ) % V_468 ) &&
V_441 -> V_137 ) {
F_26 ( V_4 ) -> V_157 = ( V_224 - 2 ) - ( unsigned char * ) V_53 ;
}
break;
#ifdef F_245
case V_469 :
break;
#endif
case V_470 :
F_240 (
V_446 - V_471 ,
V_224 , V_53 -> V_55 , V_435 , false ) ;
break;
case V_472 :
if ( V_446 >= V_473 &&
F_242 ( V_224 ) ==
V_474 )
F_240 ( V_446 -
V_473 ,
V_224 + 2 , V_53 -> V_55 , V_435 , true ) ;
break;
}
V_224 += V_446 - 2 ;
V_443 -= V_446 ;
}
}
}
static bool F_246 ( struct V_39 * V_40 , const struct V_22 * V_53 )
{
const T_9 * V_224 = ( const T_9 * ) ( V_53 + 1 ) ;
if ( * V_224 == F_247 ( ( V_448 << 24 ) | ( V_448 << 16 )
| ( V_459 << 8 ) | V_460 ) ) {
V_40 -> V_62 . V_274 = 1 ;
++ V_224 ;
V_40 -> V_62 . V_405 = F_248 ( * V_224 ) ;
++ V_224 ;
if ( * V_224 )
V_40 -> V_62 . V_108 = F_248 ( * V_224 ) - V_40 -> V_475 ;
else
V_40 -> V_62 . V_108 = 0 ;
return true ;
}
return false ;
}
static bool F_249 ( const struct V_3 * V_4 ,
const struct V_22 * V_53 , struct V_39 * V_40 )
{
if ( V_53 -> V_444 == ( sizeof( * V_53 ) / 4 ) ) {
V_40 -> V_62 . V_274 = 0 ;
return false ;
} else if ( V_40 -> V_62 . V_461 &&
V_53 -> V_444 == ( ( sizeof( * V_53 ) + V_476 ) / 4 ) ) {
if ( F_246 ( V_40 , V_53 ) )
return true ;
}
F_241 ( V_4 , & V_40 -> V_62 , 1 , NULL ) ;
if ( V_40 -> V_62 . V_274 && V_40 -> V_62 . V_108 )
V_40 -> V_62 . V_108 -= V_40 -> V_475 ;
return true ;
}
const T_6 * F_250 ( const struct V_22 * V_53 )
{
int V_443 = ( V_53 -> V_444 << 2 ) - sizeof( * V_53 ) ;
const T_6 * V_224 = ( const T_6 * ) ( V_53 + 1 ) ;
if ( V_443 < V_477 )
return NULL ;
while ( V_443 > 0 ) {
int V_445 = * V_224 ++ ;
int V_446 ;
switch ( V_445 ) {
case V_447 :
return NULL ;
case V_448 :
V_443 -- ;
continue;
default:
V_446 = * V_224 ++ ;
if ( V_446 < 2 || V_446 > V_443 )
return NULL ;
if ( V_445 == V_469 )
return V_446 == V_477 ? V_224 : NULL ;
}
V_224 += V_446 - 2 ;
V_443 -= V_446 ;
}
return NULL ;
}
static int F_251 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
T_2 V_91 = F_26 ( V_4 ) -> V_91 ;
T_2 V_346 = F_26 ( V_4 ) -> V_174 ;
return (
( V_53 -> V_346 && V_91 == F_26 ( V_4 ) -> V_109 && V_91 == V_40 -> V_107 ) &&
V_346 == V_40 -> V_122 &&
! F_212 ( V_40 , V_346 , V_91 , F_159 ( V_53 -> V_74 ) << V_40 -> V_62 . V_390 ) &&
( T_7 ) ( V_40 -> V_62 . V_404 - V_40 -> V_62 . V_405 ) <= ( F_8 ( V_2 ) -> V_115 * 1024 ) / V_334 ) ;
}
static inline bool F_252 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
return ! F_230 ( & V_40 -> V_62 , V_478 ) &&
! F_251 ( V_2 , V_4 ) ;
}
static inline bool F_253 ( const struct V_39 * V_40 , T_2 V_91 , T_2 V_109 )
{
return ! F_56 ( V_109 , V_40 -> V_407 ) &&
! F_65 ( V_91 , V_40 -> V_107 + F_254 ( V_40 ) ) ;
}
void F_255 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_479 ) {
case V_480 :
V_2 -> V_481 = V_482 ;
break;
case V_483 :
V_2 -> V_481 = V_484 ;
break;
case V_485 :
return;
default:
V_2 -> V_481 = V_486 ;
}
F_256 () ;
F_257 ( V_2 ) ;
if ( ! F_258 ( V_2 , V_487 ) )
V_2 -> V_488 ( V_2 ) ;
}
void F_259 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_62 ( V_2 ) ;
V_2 -> V_489 |= V_490 ;
F_260 ( V_2 , V_491 ) ;
switch ( V_2 -> V_479 ) {
case V_492 :
case V_493 :
F_261 ( V_2 , V_483 ) ;
F_8 ( V_2 ) -> V_15 . V_33 = 1 ;
break;
case V_483 :
case V_494 :
break;
case V_495 :
break;
case V_496 :
F_226 ( V_2 ) ;
F_261 ( V_2 , V_494 ) ;
break;
case V_497 :
F_226 ( V_2 ) ;
F_262 ( V_2 , V_498 , 0 ) ;
break;
default:
F_263 ( L_17 ,
V_458 , V_2 -> V_479 ) ;
break;
}
F_264 ( & V_40 -> V_499 ) ;
if ( F_150 ( V_40 ) )
F_244 ( & V_40 -> V_62 ) ;
F_63 ( V_2 ) ;
if ( ! F_258 ( V_2 , V_487 ) ) {
V_2 -> V_500 ( V_2 ) ;
if ( V_2 -> V_489 == V_501 ||
V_2 -> V_479 == V_485 )
F_265 ( V_2 , V_502 , V_503 ) ;
else
F_265 ( V_2 , V_502 , V_504 ) ;
}
}
static inline bool F_266 ( struct V_217 * V_168 , T_2 V_91 ,
T_2 V_109 )
{
if ( ! F_65 ( V_91 , V_168 -> V_109 ) && ! F_65 ( V_168 -> V_164 , V_109 ) ) {
if ( F_56 ( V_91 , V_168 -> V_164 ) )
V_168 -> V_164 = V_91 ;
if ( F_65 ( V_109 , V_168 -> V_109 ) )
V_168 -> V_109 = V_109 ;
return true ;
}
return false ;
}
static void F_267 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_109 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_150 ( V_40 ) && V_505 ) {
int V_142 ;
if ( F_56 ( V_91 , V_40 -> V_107 ) )
V_142 = V_506 ;
else
V_142 = V_507 ;
F_81 ( F_4 ( V_2 ) , V_142 ) ;
V_40 -> V_62 . V_508 = 1 ;
V_40 -> V_509 [ 0 ] . V_164 = V_91 ;
V_40 -> V_509 [ 0 ] . V_109 = V_109 ;
}
}
static void F_268 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_109 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( ! V_40 -> V_62 . V_508 )
F_267 ( V_2 , V_91 , V_109 ) ;
else
F_266 ( V_40 -> V_509 , V_91 , V_109 ) ;
}
static void F_269 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_26 ( V_4 ) -> V_109 != F_26 ( V_4 ) -> V_91 &&
F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_107 ) ) {
F_81 ( F_4 ( V_2 ) , V_510 ) ;
F_18 ( V_2 ) ;
if ( F_150 ( V_40 ) && V_505 ) {
T_2 V_109 = F_26 ( V_4 ) -> V_109 ;
if ( F_65 ( F_26 ( V_4 ) -> V_109 , V_40 -> V_107 ) )
V_109 = V_40 -> V_107 ;
F_267 ( V_2 , F_26 ( V_4 ) -> V_91 , V_109 ) ;
}
}
F_226 ( V_2 ) ;
}
static void F_270 ( struct V_39 * V_40 )
{
int V_511 ;
struct V_217 * V_168 = & V_40 -> V_512 [ 0 ] ;
struct V_217 * V_513 = V_168 + 1 ;
for ( V_511 = 1 ; V_511 < V_40 -> V_62 . V_169 ; ) {
if ( F_266 ( V_168 , V_513 -> V_164 , V_513 -> V_109 ) ) {
int V_230 ;
V_40 -> V_62 . V_169 -- ;
for ( V_230 = V_511 ; V_230 < V_40 -> V_62 . V_169 ; V_230 ++ )
V_168 [ V_230 ] = V_168 [ V_230 + 1 ] ;
continue;
}
V_511 ++ , V_513 ++ ;
}
}
static void F_271 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_109 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_217 * V_168 = & V_40 -> V_512 [ 0 ] ;
int V_514 = V_40 -> V_62 . V_169 ;
int V_511 ;
if ( ! V_514 )
goto V_515;
for ( V_511 = 0 ; V_511 < V_514 ; V_511 ++ , V_168 ++ ) {
if ( F_266 ( V_168 , V_91 , V_109 ) ) {
for (; V_511 > 0 ; V_511 -- , V_168 -- )
F_127 ( * V_168 , * ( V_168 - 1 ) ) ;
if ( V_514 > 1 )
F_270 ( V_40 ) ;
return;
}
}
if ( V_511 >= V_226 ) {
V_511 -- ;
V_40 -> V_62 . V_169 -- ;
V_168 -- ;
}
for (; V_511 > 0 ; V_511 -- , V_168 -- )
* V_168 = * ( V_168 - 1 ) ;
V_515:
V_168 -> V_164 = V_91 ;
V_168 -> V_109 = V_109 ;
V_40 -> V_62 . V_169 ++ ;
}
static void F_272 ( struct V_39 * V_40 )
{
struct V_217 * V_168 = & V_40 -> V_512 [ 0 ] ;
int V_169 = V_40 -> V_62 . V_169 ;
int V_511 ;
if ( F_273 ( & V_40 -> V_499 ) ) {
V_40 -> V_62 . V_169 = 0 ;
return;
}
for ( V_511 = 0 ; V_511 < V_169 ; ) {
if ( ! F_56 ( V_40 -> V_107 , V_168 -> V_164 ) ) {
int V_230 ;
F_125 ( F_56 ( V_40 -> V_107 , V_168 -> V_109 ) ) ;
for ( V_230 = V_511 + 1 ; V_230 < V_169 ; V_230 ++ )
V_40 -> V_512 [ V_230 - 1 ] = V_40 -> V_512 [ V_230 ] ;
V_169 -- ;
continue;
}
V_511 ++ ;
V_168 ++ ;
}
V_40 -> V_62 . V_169 = V_169 ;
}
static bool F_274 ( struct V_1 * V_2 ,
struct V_3 * V_516 ,
struct V_3 * V_517 ,
bool * V_518 )
{
int V_300 ;
* V_518 = false ;
if ( F_26 ( V_517 ) -> V_91 != F_26 ( V_516 ) -> V_109 )
return false ;
if ( ! F_275 ( V_516 , V_517 , V_518 , & V_300 ) )
return false ;
F_276 ( V_300 , & V_2 -> V_96 ) ;
F_277 ( V_2 , V_300 ) ;
F_81 ( F_4 ( V_2 ) , V_519 ) ;
F_26 ( V_516 ) -> V_109 = F_26 ( V_517 ) -> V_109 ;
F_26 ( V_516 ) -> V_174 = F_26 ( V_517 ) -> V_174 ;
F_26 ( V_516 ) -> V_206 |= F_26 ( V_517 ) -> V_206 ;
return true ;
}
static void F_278 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_279 ( V_2 , V_4 ) ;
F_280 ( V_4 ) ;
}
static void F_281 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_4 V_520 = V_40 -> V_107 ;
bool V_521 , V_518 , V_522 ;
struct V_3 * V_4 , * V_523 ;
struct V_524 * V_525 ;
V_525 = F_282 ( & V_40 -> V_499 ) ;
while ( V_525 ) {
V_4 = F_283 ( V_525 , struct V_3 , V_526 ) ;
if ( F_65 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_107 ) )
break;
if ( F_56 ( F_26 ( V_4 ) -> V_91 , V_520 ) ) {
T_4 V_508 = V_520 ;
if ( F_56 ( F_26 ( V_4 ) -> V_109 , V_520 ) )
V_520 = F_26 ( V_4 ) -> V_109 ;
F_268 ( V_2 , F_26 ( V_4 ) -> V_91 , V_508 ) ;
}
V_525 = F_284 ( V_525 ) ;
F_285 ( & V_4 -> V_526 , & V_40 -> V_499 ) ;
if ( F_11 ( ! F_65 ( F_26 ( V_4 ) -> V_109 , V_40 -> V_107 ) ) ) {
F_239 ( V_2 , L_18 ) ;
F_278 ( V_2 , V_4 ) ;
continue;
}
F_239 ( V_2 , L_19 ,
V_40 -> V_107 , F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_109 ) ;
V_523 = F_286 ( & V_2 -> V_527 ) ;
V_522 = V_523 && F_274 ( V_2 , V_523 , V_4 , & V_518 ) ;
F_215 ( V_40 , F_26 ( V_4 ) -> V_109 ) ;
V_521 = F_26 ( V_4 ) -> V_206 & V_208 ;
if ( ! V_522 )
F_287 ( & V_2 -> V_527 , V_4 ) ;
else
F_288 ( V_4 , V_518 ) ;
if ( F_11 ( V_521 ) ) {
F_259 ( V_2 ) ;
break;
}
}
}
static int F_289 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_528 )
{
if ( F_52 ( & V_2 -> V_96 ) > V_2 -> V_83 ||
! F_290 ( V_2 , V_4 , V_528 ) ) {
if ( F_291 ( V_2 ) < 0 )
return - 1 ;
while ( ! F_290 ( V_2 , V_4 , V_528 ) ) {
if ( ! F_292 ( V_2 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_293 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_524 * * V_525 , * V_529 , * V_530 ;
struct V_3 * V_531 ;
T_2 V_91 , V_109 ;
bool V_518 ;
F_29 ( V_40 , V_4 ) ;
if ( F_11 ( F_289 ( V_2 , V_4 , V_4 -> V_73 ) ) ) {
F_81 ( F_4 ( V_2 ) , V_532 ) ;
F_278 ( V_2 , V_4 ) ;
return;
}
V_40 -> V_392 = 0 ;
F_62 ( V_2 ) ;
F_81 ( F_4 ( V_2 ) , V_533 ) ;
V_91 = F_26 ( V_4 ) -> V_91 ;
V_109 = F_26 ( V_4 ) -> V_109 ;
F_239 ( V_2 , L_20 ,
V_40 -> V_107 , V_91 , V_109 ) ;
V_525 = & V_40 -> V_499 . V_524 ;
if ( F_273 ( & V_40 -> V_499 ) ) {
if ( F_150 ( V_40 ) ) {
V_40 -> V_62 . V_169 = 1 ;
V_40 -> V_512 [ 0 ] . V_164 = V_91 ;
V_40 -> V_512 [ 0 ] . V_109 = V_109 ;
}
F_294 ( & V_4 -> V_526 , NULL , V_525 ) ;
F_295 ( & V_4 -> V_526 , & V_40 -> V_499 ) ;
V_40 -> V_534 = V_4 ;
goto V_535;
}
if ( F_274 ( V_2 , V_40 -> V_534 , V_4 , & V_518 ) ) {
V_536:
F_39 ( V_2 , V_4 ) ;
F_288 ( V_4 , V_518 ) ;
V_4 = NULL ;
goto V_537;
}
if ( ! F_56 ( V_91 , F_26 ( V_40 -> V_534 ) -> V_109 ) ) {
V_530 = & V_40 -> V_534 -> V_526 ;
V_525 = & V_530 -> V_538 ;
goto V_539;
}
V_530 = NULL ;
while ( * V_525 ) {
V_530 = * V_525 ;
V_531 = F_283 ( V_530 , struct V_3 , V_526 ) ;
if ( F_56 ( V_91 , F_26 ( V_531 ) -> V_91 ) ) {
V_525 = & V_530 -> V_540 ;
continue;
}
if ( F_56 ( V_91 , F_26 ( V_531 ) -> V_109 ) ) {
if ( ! F_65 ( V_109 , F_26 ( V_531 ) -> V_109 ) ) {
F_81 ( F_4 ( V_2 ) ,
V_541 ) ;
F_280 ( V_4 ) ;
V_4 = NULL ;
F_267 ( V_2 , V_91 , V_109 ) ;
goto V_537;
}
if ( F_65 ( V_91 , F_26 ( V_531 ) -> V_91 ) ) {
F_267 ( V_2 , V_91 , F_26 ( V_531 ) -> V_109 ) ;
} else {
F_296 ( & V_531 -> V_526 , & V_4 -> V_526 ,
& V_40 -> V_499 ) ;
F_268 ( V_2 ,
F_26 ( V_531 ) -> V_91 ,
F_26 ( V_531 ) -> V_109 ) ;
F_81 ( F_4 ( V_2 ) ,
V_541 ) ;
F_280 ( V_531 ) ;
goto V_542;
}
} else if ( F_274 ( V_2 , V_531 , V_4 , & V_518 ) ) {
goto V_536;
}
V_525 = & V_530 -> V_538 ;
}
V_539:
F_294 ( & V_4 -> V_526 , V_530 , V_525 ) ;
F_295 ( & V_4 -> V_526 , & V_40 -> V_499 ) ;
V_542:
while ( ( V_529 = F_284 ( & V_4 -> V_526 ) ) != NULL ) {
V_531 = F_283 ( V_529 , struct V_3 , V_526 ) ;
if ( ! F_65 ( V_109 , F_26 ( V_531 ) -> V_91 ) )
break;
if ( F_56 ( V_109 , F_26 ( V_531 ) -> V_109 ) ) {
F_268 ( V_2 , F_26 ( V_531 ) -> V_91 ,
V_109 ) ;
break;
}
F_285 ( & V_531 -> V_526 , & V_40 -> V_499 ) ;
F_268 ( V_2 , F_26 ( V_531 ) -> V_91 ,
F_26 ( V_531 ) -> V_109 ) ;
F_81 ( F_4 ( V_2 ) , V_541 ) ;
F_278 ( V_2 , V_531 ) ;
}
if ( ! V_529 )
V_40 -> V_534 = V_4 ;
V_537:
if ( F_150 ( V_40 ) )
F_271 ( V_2 , V_91 , V_109 ) ;
V_535:
if ( V_4 ) {
F_39 ( V_2 , V_4 ) ;
F_297 ( V_4 ) ;
F_298 ( V_4 , V_2 ) ;
}
}
static int T_10 F_299 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_543 ,
bool * V_518 )
{
int V_522 ;
struct V_3 * V_523 = F_286 ( & V_2 -> V_527 ) ;
F_300 ( V_4 , V_543 ) ;
V_522 = ( V_523 &&
F_274 ( V_2 , V_523 , V_4 , V_518 ) ) ? 1 : 0 ;
F_215 ( F_15 ( V_2 ) , F_26 ( V_4 ) -> V_109 ) ;
if ( ! V_522 ) {
F_287 ( & V_2 -> V_527 , V_4 ) ;
F_298 ( V_4 , V_2 ) ;
}
return V_522 ;
}
int F_301 ( struct V_1 * V_2 , struct V_544 * V_276 , T_11 V_528 )
{
struct V_3 * V_4 ;
int V_179 = - V_545 ;
int V_546 = 0 ;
bool V_518 ;
if ( V_528 == 0 )
return 0 ;
if ( V_528 > V_547 ) {
int V_548 = F_10 ( T_11 , V_528 >> V_549 , V_550 ) ;
V_546 = V_548 << V_549 ;
V_528 = V_546 + ( V_528 & ~ V_551 ) ;
}
V_4 = F_302 ( V_528 - V_546 , V_546 ,
V_552 ,
& V_179 , V_2 -> V_553 ) ;
if ( ! V_4 )
goto V_179;
F_303 ( V_4 , V_528 - V_546 ) ;
V_4 -> V_546 = V_546 ;
V_4 -> V_5 = V_528 ;
if ( F_289 ( V_2 , V_4 , V_4 -> V_73 ) )
goto V_554;
V_179 = F_304 ( V_4 , 0 , & V_276 -> V_555 , V_528 ) ;
if ( V_179 )
goto V_554;
F_26 ( V_4 ) -> V_91 = F_15 ( V_2 ) -> V_107 ;
F_26 ( V_4 ) -> V_109 = F_26 ( V_4 ) -> V_91 + V_528 ;
F_26 ( V_4 ) -> V_174 = F_15 ( V_2 ) -> V_122 - 1 ;
if ( F_299 ( V_2 , V_4 , 0 , & V_518 ) ) {
F_169 ( V_518 ) ;
F_280 ( V_4 ) ;
}
return V_528 ;
V_554:
F_305 ( V_4 ) ;
V_179:
return V_179 ;
}
static void F_306 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_518 = false ;
int V_522 = - 1 ;
if ( F_26 ( V_4 ) -> V_91 == F_26 ( V_4 ) -> V_109 ) {
F_280 ( V_4 ) ;
return;
}
F_307 ( V_4 ) ;
F_300 ( V_4 , F_14 ( V_4 ) -> V_444 * 4 ) ;
F_23 ( V_40 , V_4 ) ;
V_40 -> V_62 . V_508 = 0 ;
if ( F_26 ( V_4 ) -> V_91 == V_40 -> V_107 ) {
if ( F_254 ( V_40 ) == 0 )
goto V_556;
if ( V_40 -> V_557 . V_558 == V_559 &&
V_40 -> V_92 == V_40 -> V_107 && V_40 -> V_557 . V_5 &&
F_308 ( V_2 ) && ! V_40 -> V_560 ) {
int V_561 = F_10 (unsigned int, skb->len,
tp->ucopy.len) ;
F_309 ( V_562 ) ;
if ( ! F_310 ( V_4 , 0 , V_40 -> V_557 . V_276 , V_561 ) ) {
V_40 -> V_557 . V_5 -= V_561 ;
V_40 -> V_92 += V_561 ;
V_522 = ( V_561 == V_4 -> V_5 ) ;
F_60 ( V_2 ) ;
}
}
if ( V_522 <= 0 ) {
V_563:
if ( V_522 < 0 ) {
if ( F_311 ( & V_2 -> V_527 ) == 0 )
F_312 ( V_2 , V_4 -> V_73 ) ;
else if ( F_289 ( V_2 , V_4 , V_4 -> V_73 ) )
goto V_564;
}
V_522 = F_299 ( V_2 , V_4 , 0 , & V_518 ) ;
}
F_215 ( V_40 , F_26 ( V_4 ) -> V_109 ) ;
if ( V_4 -> V_5 )
F_61 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_206 & V_208 )
F_259 ( V_2 ) ;
if ( ! F_273 ( & V_40 -> V_499 ) ) {
F_281 ( V_2 ) ;
if ( F_273 ( & V_40 -> V_499 ) )
F_8 ( V_2 ) -> V_15 . V_33 = 0 ;
}
if ( V_40 -> V_62 . V_169 )
F_272 ( V_40 ) ;
F_218 ( V_2 ) ;
if ( V_522 > 0 )
F_288 ( V_4 , V_518 ) ;
if ( ! F_258 ( V_2 , V_487 ) )
V_2 -> V_565 ( V_2 ) ;
return;
}
if ( ! F_65 ( F_26 ( V_4 ) -> V_109 , V_40 -> V_107 ) ) {
F_81 ( F_4 ( V_2 ) , V_510 ) ;
F_267 ( V_2 , F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_109 ) ;
V_556:
F_18 ( V_2 ) ;
F_62 ( V_2 ) ;
V_564:
F_278 ( V_2 , V_4 ) ;
return;
}
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_107 + F_254 ( V_40 ) ) )
goto V_556;
F_18 ( V_2 ) ;
if ( F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_107 ) ) {
F_239 ( V_2 , L_21 ,
V_40 -> V_107 , F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_109 ) ;
F_267 ( V_2 , F_26 ( V_4 ) -> V_91 , V_40 -> V_107 ) ;
if ( ! F_254 ( V_40 ) )
goto V_556;
goto V_563;
}
F_293 ( V_2 , V_4 ) ;
}
static struct V_3 * F_313 ( struct V_3 * V_4 , struct V_566 * V_567 )
{
if ( V_567 )
return ! F_314 ( V_567 , V_4 ) ? V_4 -> V_370 : NULL ;
return F_315 ( F_284 ( & V_4 -> V_526 ) , struct V_3 , V_526 ) ;
}
static struct V_3 * F_316 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_566 * V_567 ,
struct V_568 * V_569 )
{
struct V_3 * V_370 = F_313 ( V_4 , V_567 ) ;
if ( V_567 )
F_317 ( V_4 , V_567 ) ;
else
F_285 ( & V_4 -> V_526 , V_569 ) ;
F_280 ( V_4 ) ;
F_81 ( F_4 ( V_2 ) , V_570 ) ;
return V_370 ;
}
static void F_318 ( struct V_568 * V_569 , struct V_3 * V_4 )
{
struct V_524 * * V_525 = & V_569 -> V_524 ;
struct V_524 * V_530 = NULL ;
struct V_3 * V_531 ;
while ( * V_525 ) {
V_530 = * V_525 ;
V_531 = F_283 ( V_530 , struct V_3 , V_526 ) ;
if ( F_56 ( F_26 ( V_4 ) -> V_91 , F_26 ( V_531 ) -> V_91 ) )
V_525 = & V_530 -> V_540 ;
else
V_525 = & V_530 -> V_538 ;
}
F_294 ( & V_4 -> V_526 , V_530 , V_525 ) ;
F_295 ( & V_4 -> V_526 , V_569 ) ;
}
static void
F_319 ( struct V_1 * V_2 , struct V_566 * V_567 , struct V_568 * V_569 ,
struct V_3 * V_571 , struct V_3 * V_523 , T_2 V_572 , T_2 V_535 )
{
struct V_3 * V_4 = V_571 , * V_573 ;
struct V_566 V_220 ;
bool V_574 ;
V_575:
for ( V_574 = true ; V_4 != NULL && V_4 != V_523 ; V_4 = V_573 ) {
V_573 = F_313 ( V_4 , V_567 ) ;
if ( ! F_56 ( V_572 , F_26 ( V_4 ) -> V_109 ) ) {
V_4 = F_316 ( V_2 , V_4 , V_567 , V_569 ) ;
if ( ! V_4 )
break;
goto V_575;
}
if ( ! ( F_26 ( V_4 ) -> V_206 & ( V_372 | V_208 ) ) &&
( F_38 ( V_4 -> V_73 ) > V_4 -> V_5 ||
F_56 ( F_26 ( V_4 ) -> V_91 , V_572 ) ) ) {
V_574 = false ;
break;
}
if ( V_573 && V_573 != V_523 &&
F_26 ( V_4 ) -> V_109 != F_26 ( V_573 ) -> V_91 ) {
V_574 = false ;
break;
}
V_572 = F_26 ( V_4 ) -> V_109 ;
}
if ( V_574 ||
( F_26 ( V_4 ) -> V_206 & ( V_372 | V_208 ) ) )
return;
F_320 ( & V_220 ) ;
while ( F_56 ( V_572 , V_535 ) ) {
int V_576 = F_10 ( int , F_321 ( 0 , 0 ) , V_535 - V_572 ) ;
struct V_3 * V_577 ;
V_577 = F_322 ( V_576 , V_184 ) ;
if ( ! V_577 )
break;
memcpy ( V_577 -> V_578 , V_4 -> V_578 , sizeof( V_4 -> V_578 ) ) ;
F_26 ( V_577 ) -> V_91 = F_26 ( V_577 ) -> V_109 = V_572 ;
if ( V_567 )
F_323 ( V_567 , V_4 , V_577 ) ;
else
F_287 ( & V_220 , V_577 ) ;
F_298 ( V_577 , V_2 ) ;
while ( V_576 > 0 ) {
int V_579 = V_572 - F_26 ( V_4 ) -> V_91 ;
int V_528 = F_26 ( V_4 ) -> V_109 - V_572 ;
F_98 ( V_579 < 0 ) ;
if ( V_528 > 0 ) {
V_528 = F_17 ( V_576 , V_528 ) ;
if ( F_324 ( V_4 , V_579 , F_303 ( V_577 , V_528 ) , V_528 ) )
F_325 () ;
F_26 ( V_577 ) -> V_109 += V_528 ;
V_576 -= V_528 ;
V_572 += V_528 ;
}
if ( ! F_56 ( V_572 , F_26 ( V_4 ) -> V_109 ) ) {
V_4 = F_316 ( V_2 , V_4 , V_567 , V_569 ) ;
if ( ! V_4 ||
V_4 == V_523 ||
( F_26 ( V_4 ) -> V_206 & ( V_372 | V_208 ) ) )
goto V_535;
}
}
}
V_535:
F_326 (&tmp, skb, n)
F_318 ( V_569 , V_4 ) ;
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 , * V_571 ;
struct V_524 * V_525 ;
T_2 V_572 , V_535 ;
V_525 = F_282 ( & V_40 -> V_499 ) ;
V_4 = F_315 ( V_525 , struct V_3 , V_526 ) ;
V_580:
if ( ! V_4 ) {
V_525 = F_328 ( & V_40 -> V_499 ) ;
V_40 -> V_534 = F_283 ( V_525 , struct V_3 , V_526 ) ;
return;
}
V_572 = F_26 ( V_4 ) -> V_91 ;
V_535 = F_26 ( V_4 ) -> V_109 ;
for ( V_571 = V_4 ; ; ) {
V_4 = F_313 ( V_4 , NULL ) ;
if ( ! V_4 ||
F_65 ( F_26 ( V_4 ) -> V_91 , V_535 ) ||
F_56 ( F_26 ( V_4 ) -> V_109 , V_572 ) ) {
F_319 ( V_2 , NULL , & V_40 -> V_499 ,
V_571 , V_4 , V_572 , V_535 ) ;
goto V_580;
}
if ( F_11 ( F_56 ( F_26 ( V_4 ) -> V_91 , V_572 ) ) )
V_572 = F_26 ( V_4 ) -> V_91 ;
if ( F_65 ( F_26 ( V_4 ) -> V_109 , V_535 ) )
V_535 = F_26 ( V_4 ) -> V_109 ;
}
}
static bool F_292 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_524 * V_581 , * V_202 ;
if ( F_273 ( & V_40 -> V_499 ) )
return false ;
F_81 ( F_4 ( V_2 ) , V_582 ) ;
V_581 = & V_40 -> V_534 -> V_526 ;
do {
V_202 = F_329 ( V_581 ) ;
F_285 ( V_581 , & V_40 -> V_499 ) ;
F_278 ( V_2 , F_283 ( V_581 , struct V_3 , V_526 ) ) ;
F_63 ( V_2 ) ;
if ( F_52 ( & V_2 -> V_96 ) <= V_2 -> V_83 &&
! F_41 ( V_2 ) )
break;
V_581 = V_202 ;
} while ( V_581 );
V_40 -> V_534 = F_283 ( V_202 , struct V_3 , V_526 ) ;
if ( V_40 -> V_62 . V_137 )
F_244 ( & V_40 -> V_62 ) ;
return true ;
}
static int F_291 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_239 ( V_2 , L_22 , V_40 -> V_92 ) ;
F_81 ( F_4 ( V_2 ) , V_583 ) ;
if ( F_52 ( & V_2 -> V_96 ) >= V_2 -> V_83 )
F_49 ( V_2 ) ;
else if ( F_41 ( V_2 ) )
V_40 -> V_76 = F_17 ( V_40 -> V_76 , 4U * V_40 -> V_79 ) ;
F_327 ( V_2 ) ;
if ( ! F_330 ( & V_2 -> V_527 ) )
F_319 ( V_2 , & V_2 -> V_527 , NULL ,
F_331 ( & V_2 -> V_527 ) ,
NULL ,
V_40 -> V_92 , V_40 -> V_107 ) ;
F_63 ( V_2 ) ;
if ( F_52 ( & V_2 -> V_96 ) <= V_2 -> V_83 )
return 0 ;
F_292 ( V_2 ) ;
if ( F_52 ( & V_2 -> V_96 ) <= V_2 -> V_83 )
return 0 ;
F_81 ( F_4 ( V_2 ) , V_584 ) ;
V_40 -> V_392 = 0 ;
return - 1 ;
}
static bool F_332 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_2 -> V_85 & V_87 )
return false ;
if ( F_41 ( V_2 ) )
return false ;
if ( F_50 ( V_2 ) >= F_51 ( V_2 , 0 ) )
return false ;
if ( F_129 ( V_40 ) >= V_40 -> V_68 )
return false ;
return true ;
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_332 ( V_2 ) ) {
F_33 ( V_2 ) ;
V_40 -> V_94 = V_95 ;
}
V_2 -> V_585 ( V_2 ) ;
}
static void F_334 ( struct V_1 * V_2 )
{
if ( F_258 ( V_2 , V_586 ) ) {
F_335 ( V_2 , V_586 ) ;
F_336 () ;
if ( V_2 -> V_587 &&
F_337 ( V_588 , & V_2 -> V_587 -> V_409 ) ) {
F_333 ( V_2 ) ;
if ( ! F_337 ( V_588 , & V_2 -> V_587 -> V_409 ) )
F_205 ( V_2 , V_589 ) ;
}
}
}
static inline void F_338 ( struct V_1 * V_2 )
{
F_339 ( V_2 ) ;
F_334 ( V_2 ) ;
}
static void F_340 ( struct V_1 * V_2 , int V_590 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( ( ( V_40 -> V_107 - V_40 -> V_407 ) > F_8 ( V_2 ) -> V_15 . V_18 &&
F_341 ( V_2 ) >= V_40 -> V_30 ) ||
F_19 ( V_2 ) ||
( V_590 && ! F_273 ( & V_40 -> V_499 ) ) ) {
F_226 ( V_2 ) ;
} else {
F_342 ( V_2 ) ;
}
}
static inline void F_343 ( struct V_1 * V_2 )
{
if ( ! F_344 ( V_2 ) ) {
return;
}
F_340 ( V_2 , 1 ) ;
}
static void F_345 ( struct V_1 * V_2 , const struct V_22 * V_53 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_224 = F_159 ( V_53 -> V_591 ) ;
if ( V_224 && ! V_592 )
V_224 -- ;
V_224 += F_248 ( V_53 -> V_91 ) ;
if ( F_65 ( V_40 -> V_92 , V_224 ) )
return;
if ( F_56 ( V_224 , V_40 -> V_107 ) )
return;
if ( V_40 -> V_560 && ! F_65 ( V_224 , V_40 -> V_593 ) )
return;
F_346 ( V_2 ) ;
if ( V_40 -> V_593 == V_40 -> V_92 && V_40 -> V_560 &&
! F_258 ( V_2 , V_594 ) && V_40 -> V_92 != V_40 -> V_107 ) {
struct V_3 * V_4 = F_331 ( & V_2 -> V_527 ) ;
V_40 -> V_92 ++ ;
if ( V_4 && ! F_56 ( V_40 -> V_92 , F_26 ( V_4 ) -> V_109 ) ) {
F_317 ( V_4 , & V_2 -> V_527 ) ;
F_280 ( V_4 ) ;
}
}
V_40 -> V_560 = V_595 ;
V_40 -> V_593 = V_224 ;
V_40 -> V_392 = 0 ;
}
static void F_347 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_22 * V_53 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_53 -> V_596 )
F_345 ( V_2 , V_53 ) ;
if ( V_40 -> V_560 == V_595 ) {
T_2 V_224 = V_40 -> V_593 - F_248 ( V_53 -> V_91 ) + ( V_53 -> V_444 * 4 ) -
V_53 -> V_55 ;
if ( V_224 < V_4 -> V_5 ) {
T_6 V_220 ;
if ( F_324 ( V_4 , V_224 , & V_220 , 1 ) )
F_325 () ;
V_40 -> V_560 = V_597 | V_220 ;
if ( ! F_258 ( V_2 , V_487 ) )
V_2 -> V_565 ( V_2 ) ;
}
}
}
static int F_348 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_598 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_561 = V_4 -> V_5 - V_598 ;
int V_179 ;
if ( F_349 ( V_4 ) )
V_179 = F_310 ( V_4 , V_598 , V_40 -> V_557 . V_276 , V_561 ) ;
else
V_179 = F_350 ( V_4 , V_598 , V_40 -> V_557 . V_276 ) ;
if ( ! V_179 ) {
V_40 -> V_557 . V_5 -= V_561 ;
V_40 -> V_92 += V_561 ;
F_60 ( V_2 ) ;
}
return V_179 ;
}
static bool F_351 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
return F_11 ( F_26 ( V_4 ) -> V_91 == ( V_40 -> V_107 - 1 ) &&
( 1 << V_2 -> V_479 ) & ( V_599 | V_600 |
V_601 ) ) ;
}
static bool F_352 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 , int V_602 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_603 = false ;
if ( F_249 ( V_4 , V_53 , V_40 ) && V_40 -> V_62 . V_274 &&
F_252 ( V_2 , V_4 ) ) {
if ( ! V_53 -> V_604 ) {
F_81 ( F_4 ( V_2 ) , V_605 ) ;
if ( ! F_221 ( F_4 ( V_2 ) , V_4 ,
V_606 ,
& V_40 -> V_393 ) )
F_269 ( V_2 , V_4 ) ;
goto V_607;
}
}
if ( ! F_253 ( V_40 , F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_109 ) ) {
if ( ! V_53 -> V_604 ) {
if ( V_53 -> V_55 )
goto V_608;
if ( ! F_221 ( F_4 ( V_2 ) , V_4 ,
V_609 ,
& V_40 -> V_393 ) )
F_269 ( V_2 , V_4 ) ;
} else if ( F_351 ( V_2 , V_4 ) ) {
F_255 ( V_2 ) ;
}
goto V_607;
}
if ( V_53 -> V_604 ) {
if ( F_26 ( V_4 ) -> V_91 == V_40 -> V_107 ||
F_351 ( V_2 , V_4 ) ) {
V_603 = true ;
} else if ( F_150 ( V_40 ) && V_40 -> V_62 . V_169 > 0 ) {
struct V_217 * V_168 = & V_40 -> V_512 [ 0 ] ;
int V_610 = V_168 [ 0 ] . V_109 ;
int V_511 ;
for ( V_511 = 1 ; V_511 < V_40 -> V_62 . V_169 ;
++ V_511 ) {
V_610 = F_65 ( V_168 [ V_511 ] . V_109 ,
V_610 ) ?
V_168 [ V_511 ] . V_109 : V_610 ;
}
if ( F_26 ( V_4 ) -> V_91 == V_610 )
V_603 = true ;
}
if ( V_603 )
F_255 ( V_2 ) ;
else {
if ( V_40 -> V_611 && ! V_40 -> V_612 &&
V_2 -> V_479 == V_493 )
F_353 ( V_2 ) ;
F_222 ( V_2 , V_4 ) ;
}
goto V_607;
}
if ( V_53 -> V_55 ) {
V_608:
if ( V_602 )
F_354 ( F_4 ( V_2 ) , V_613 ) ;
F_81 ( F_4 ( V_2 ) , V_614 ) ;
F_222 ( V_2 , V_4 ) ;
goto V_607;
}
return true ;
V_607:
F_278 ( V_2 , V_4 ) ;
return false ;
}
void F_355 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 , unsigned int V_5 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_46 ( & V_40 -> V_90 ) ;
if ( F_11 ( ! V_2 -> V_615 ) )
F_8 ( V_2 ) -> V_616 -> V_617 ( V_2 , V_4 ) ;
V_40 -> V_62 . V_274 = 0 ;
if ( ( F_13 ( V_53 ) & V_618 ) == V_40 -> V_392 &&
F_26 ( V_4 ) -> V_91 == V_40 -> V_107 &&
! F_65 ( F_26 ( V_4 ) -> V_174 , V_40 -> V_124 ) ) {
int V_25 = V_40 -> V_25 ;
if ( V_25 == sizeof( struct V_22 ) + V_476 ) {
if ( ! F_246 ( V_40 , V_53 ) )
goto V_619;
if ( ( T_7 ) ( V_40 -> V_62 . V_405 - V_40 -> V_62 . V_404 ) < 0 )
goto V_619;
}
if ( V_5 <= V_25 ) {
if ( V_5 == V_25 ) {
if ( V_25 ==
( sizeof( struct V_22 ) + V_476 ) &&
V_40 -> V_107 == V_40 -> V_407 )
F_227 ( V_40 ) ;
F_235 ( V_2 , V_4 , 0 ) ;
F_280 ( V_4 ) ;
F_338 ( V_2 ) ;
return;
} else {
F_354 ( F_4 ( V_2 ) , V_613 ) ;
goto V_607;
}
} else {
int V_522 = 0 ;
bool V_518 = false ;
if ( V_40 -> V_557 . V_558 == V_559 &&
V_40 -> V_92 == V_40 -> V_107 &&
V_5 - V_25 <= V_40 -> V_557 . V_5 &&
F_308 ( V_2 ) ) {
F_309 ( V_562 ) ;
if ( ! F_348 ( V_2 , V_4 , V_25 ) ) {
if ( V_25 ==
( sizeof( struct V_22 ) +
V_476 ) &&
V_40 -> V_107 == V_40 -> V_407 )
F_227 ( V_40 ) ;
F_58 ( V_2 , V_4 ) ;
F_300 ( V_4 , V_25 ) ;
F_215 ( V_40 , F_26 ( V_4 ) -> V_109 ) ;
F_81 ( F_4 ( V_2 ) ,
V_620 ) ;
V_522 = 1 ;
}
}
if ( ! V_522 ) {
if ( F_356 ( V_4 ) )
goto V_621;
if ( ( int ) V_4 -> V_73 > V_2 -> V_622 )
goto V_623;
if ( V_25 ==
( sizeof( struct V_22 ) + V_476 ) &&
V_40 -> V_107 == V_40 -> V_407 )
F_227 ( V_40 ) ;
F_58 ( V_2 , V_4 ) ;
F_81 ( F_4 ( V_2 ) , V_624 ) ;
V_522 = F_299 ( V_2 , V_4 , V_25 ,
& V_518 ) ;
}
F_61 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_174 != V_40 -> V_122 ) {
F_235 ( V_2 , V_4 , V_426 ) ;
F_338 ( V_2 ) ;
if ( ! F_344 ( V_2 ) )
goto V_625;
}
F_340 ( V_2 , 0 ) ;
V_625:
if ( V_522 )
F_288 ( V_4 , V_518 ) ;
V_2 -> V_565 ( V_2 ) ;
return;
}
}
V_619:
if ( V_5 < ( V_53 -> V_444 << 2 ) || F_356 ( V_4 ) )
goto V_621;
if ( ! V_53 -> V_346 && ! V_53 -> V_604 && ! V_53 -> V_55 )
goto V_607;
if ( ! F_352 ( V_2 , V_4 , V_53 , 1 ) )
return;
V_623:
if ( F_235 ( V_2 , V_4 , V_421 | V_420 ) < 0 )
goto V_607;
F_58 ( V_2 , V_4 ) ;
F_347 ( V_2 , V_4 , V_53 ) ;
F_306 ( V_2 , V_4 ) ;
F_338 ( V_2 ) ;
F_343 ( V_2 ) ;
return;
V_621:
F_354 ( F_4 ( V_2 ) , V_626 ) ;
F_354 ( F_4 ( V_2 ) , V_613 ) ;
V_607:
F_278 ( V_2 , V_4 ) ;
}
void F_357 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
F_261 ( V_2 , V_493 ) ;
V_13 -> V_15 . V_114 = V_95 ;
if ( V_4 ) {
V_13 -> V_616 -> V_617 ( V_2 , V_4 ) ;
F_358 ( V_2 , V_4 ) ;
}
V_13 -> V_616 -> V_627 ( V_2 ) ;
F_359 ( V_2 ) ;
F_360 ( V_2 ) ;
V_40 -> V_628 = V_95 ;
F_45 ( V_2 ) ;
if ( F_258 ( V_2 , V_629 ) )
F_361 ( V_2 , F_362 ( V_40 ) ) ;
if ( ! V_40 -> V_62 . V_390 )
F_363 ( V_40 , V_40 -> V_387 ) ;
else
V_40 -> V_392 = 0 ;
}
static bool F_364 ( struct V_1 * V_2 , struct V_3 * V_630 ,
struct V_434 * V_433 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_20 = V_40 -> V_631 ? F_112 ( V_2 ) : NULL ;
T_8 V_80 = V_40 -> V_62 . V_63 , V_632 = 0 ;
bool V_633 = false ;
if ( V_80 == V_40 -> V_62 . V_452 ) {
struct V_440 V_634 ;
F_365 ( & V_634 ) ;
V_634 . V_452 = V_634 . V_63 = 0 ;
F_241 ( V_630 , & V_634 , 0 , NULL ) ;
V_80 = V_634 . V_63 ;
}
if ( ! V_40 -> V_611 ) {
V_433 -> V_5 = - 1 ;
} else if ( V_40 -> V_635 ) {
V_633 = ( V_433 -> V_5 < 0 && V_20 ) ;
} else if ( V_433 -> V_5 < 0 && ! V_40 -> V_631 ) {
V_632 = V_40 -> V_636 ? 2 : 1 ;
}
F_366 ( V_2 , V_80 , V_433 , V_633 , V_632 ) ;
if ( V_20 ) {
F_119 (data, sk) {
if ( V_20 == F_117 ( V_2 ) ||
F_367 ( V_2 , V_20 , 1 ) )
break;
}
F_197 ( V_2 ) ;
F_81 ( F_4 ( V_2 ) ,
V_637 ) ;
return true ;
}
V_40 -> V_638 = V_40 -> V_631 ;
if ( V_40 -> V_638 )
F_81 ( F_4 ( V_2 ) ,
V_639 ) ;
F_368 ( V_2 , V_630 ) ;
return false ;
}
static int F_369 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_434 V_435 = { . V_5 = - 1 } ;
int V_640 = V_40 -> V_62 . V_63 ;
bool V_641 ;
F_241 ( V_4 , & V_40 -> V_62 , 0 , & V_435 ) ;
if ( V_40 -> V_62 . V_274 && V_40 -> V_62 . V_108 )
V_40 -> V_62 . V_108 -= V_40 -> V_475 ;
if ( V_53 -> V_346 ) {
if ( ! F_65 ( F_26 ( V_4 ) -> V_174 , V_40 -> V_122 ) ||
F_65 ( F_26 ( V_4 ) -> V_174 , V_40 -> V_124 ) )
goto V_642;
if ( V_40 -> V_62 . V_274 && V_40 -> V_62 . V_108 &&
! F_206 ( V_40 -> V_62 . V_108 , V_40 -> V_275 ,
V_95 ) ) {
F_81 ( F_4 ( V_2 ) ,
V_643 ) ;
goto V_642;
}
if ( V_53 -> V_604 ) {
F_255 ( V_2 ) ;
goto V_607;
}
if ( ! V_53 -> V_55 )
goto V_644;
F_30 ( V_40 , V_53 ) ;
F_370 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
F_235 ( V_2 , V_4 , V_421 ) ;
V_40 -> V_107 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_407 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_387 = F_159 ( V_53 -> V_74 ) ;
if ( ! V_40 -> V_62 . V_456 ) {
V_40 -> V_62 . V_390 = V_40 -> V_62 . V_645 = 0 ;
V_40 -> V_77 = F_17 ( V_40 -> V_77 , 65535U ) ;
}
if ( V_40 -> V_62 . V_274 ) {
V_40 -> V_62 . V_461 = 1 ;
V_40 -> V_25 =
sizeof( struct V_22 ) + V_476 ;
V_40 -> V_79 -= V_476 ;
F_227 ( V_40 ) ;
} else {
V_40 -> V_25 = sizeof( struct V_22 ) ;
}
if ( F_150 ( V_40 ) && V_646 )
F_371 ( V_40 ) ;
F_372 ( V_2 ) ;
F_178 ( V_2 , V_13 -> V_312 ) ;
F_53 ( V_2 ) ;
V_40 -> V_92 = V_40 -> V_107 ;
F_336 () ;
F_357 ( V_2 , V_4 ) ;
V_641 = ( V_40 -> V_611 || V_40 -> V_631 ) &&
F_364 ( V_2 , V_4 , & V_435 ) ;
if ( ! F_258 ( V_2 , V_487 ) ) {
V_2 -> V_500 ( V_2 ) ;
F_265 ( V_2 , V_647 , V_648 ) ;
}
if ( V_641 )
return - 1 ;
if ( V_2 -> V_649 ||
V_13 -> V_650 . V_651 ||
V_13 -> V_15 . V_33 ) {
F_62 ( V_2 ) ;
F_18 ( V_2 ) ;
F_145 ( V_2 , V_652 ,
V_653 , V_265 ) ;
V_607:
F_278 ( V_2 , V_4 ) ;
return 0 ;
} else {
F_226 ( V_2 ) ;
}
return - 1 ;
}
if ( V_53 -> V_604 ) {
goto V_644;
}
if ( V_40 -> V_62 . V_406 && V_40 -> V_62 . V_274 &&
F_373 ( & V_40 -> V_62 , 0 ) )
goto V_644;
if ( V_53 -> V_55 ) {
F_261 ( V_2 , V_492 ) ;
if ( V_40 -> V_62 . V_274 ) {
V_40 -> V_62 . V_461 = 1 ;
F_227 ( V_40 ) ;
V_40 -> V_25 =
sizeof( struct V_22 ) + V_476 ;
} else {
V_40 -> V_25 = sizeof( struct V_22 ) ;
}
V_40 -> V_107 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_92 = V_40 -> V_107 ;
V_40 -> V_407 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_387 = F_159 ( V_53 -> V_74 ) ;
V_40 -> V_386 = F_26 ( V_4 ) -> V_91 ;
V_40 -> V_165 = V_40 -> V_387 ;
F_31 ( V_40 , V_53 ) ;
F_372 ( V_2 ) ;
F_178 ( V_2 , V_13 -> V_312 ) ;
F_53 ( V_2 ) ;
F_374 ( V_2 ) ;
#if 0
return -1;
#else
goto V_607;
#endif
}
V_644:
F_365 ( & V_40 -> V_62 ) ;
V_40 -> V_62 . V_63 = V_640 ;
goto V_607;
V_642:
F_365 ( & V_40 -> V_62 ) ;
V_40 -> V_62 . V_63 = V_640 ;
return 1 ;
}
int F_375 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
struct V_341 * V_342 ;
int V_654 = 0 ;
bool V_655 ;
switch ( V_2 -> V_479 ) {
case V_485 :
goto V_607;
case V_656 :
if ( V_53 -> V_346 )
return 1 ;
if ( V_53 -> V_604 )
goto V_607;
if ( V_53 -> V_55 ) {
if ( V_53 -> V_521 )
goto V_607;
F_376 () ;
V_655 = V_13 -> V_616 -> V_657 ( V_2 , V_4 ) >= 0 ;
F_377 () ;
if ( ! V_655 )
return 1 ;
F_378 ( V_4 ) ;
return 0 ;
}
goto V_607;
case V_480 :
V_40 -> V_62 . V_274 = 0 ;
F_46 ( & V_40 -> V_90 ) ;
V_654 = F_369 ( V_2 , V_4 , V_53 ) ;
if ( V_654 >= 0 )
return V_654 ;
F_347 ( V_2 , V_4 , V_53 ) ;
F_280 ( V_4 ) ;
F_338 ( V_2 ) ;
return 0 ;
}
F_46 ( & V_40 -> V_90 ) ;
V_40 -> V_62 . V_274 = 0 ;
V_342 = V_40 -> V_348 ;
if ( V_342 ) {
F_169 ( V_2 -> V_479 != V_492 &&
V_2 -> V_479 != V_496 ) ;
if ( ! F_379 ( V_2 , V_4 , V_342 , true ) )
goto V_607;
}
if ( ! V_53 -> V_346 && ! V_53 -> V_604 && ! V_53 -> V_55 )
goto V_607;
if ( ! F_352 ( V_2 , V_4 , V_53 , 0 ) )
return 0 ;
V_655 = F_235 ( V_2 , V_4 , V_421 |
V_420 ) > 0 ;
switch ( V_2 -> V_479 ) {
case V_492 :
if ( ! V_655 )
return 1 ;
if ( ! V_40 -> V_118 )
F_194 ( V_2 , V_342 ) ;
if ( V_342 ) {
F_8 ( V_2 ) -> V_250 = 0 ;
F_380 ( V_2 , V_342 , false ) ;
} else {
V_13 -> V_616 -> V_627 ( V_2 ) ;
F_360 ( V_2 ) ;
F_372 ( V_2 ) ;
V_40 -> V_92 = V_40 -> V_107 ;
F_45 ( V_2 ) ;
}
F_336 () ;
F_261 ( V_2 , V_493 ) ;
V_2 -> V_500 ( V_2 ) ;
if ( V_2 -> V_587 )
F_265 ( V_2 , V_647 , V_648 ) ;
V_40 -> V_122 = F_26 ( V_4 ) -> V_174 ;
V_40 -> V_387 = F_159 ( V_53 -> V_74 ) << V_40 -> V_62 . V_390 ;
F_370 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
if ( V_40 -> V_62 . V_461 )
V_40 -> V_79 -= V_476 ;
if ( V_342 ) {
F_197 ( V_2 ) ;
} else
F_359 ( V_2 ) ;
if ( ! F_8 ( V_2 ) -> V_58 -> V_304 )
F_67 ( V_2 ) ;
V_40 -> V_628 = V_95 ;
F_53 ( V_2 ) ;
F_381 ( V_40 ) ;
break;
case V_496 : {
int V_658 ;
if ( V_342 ) {
if ( ! V_655 )
return 1 ;
F_380 ( V_2 , V_342 , false ) ;
F_197 ( V_2 ) ;
}
if ( V_40 -> V_122 != V_40 -> V_659 )
break;
F_261 ( V_2 , V_497 ) ;
V_2 -> V_489 |= V_660 ;
F_236 ( V_2 ) ;
if ( ! F_258 ( V_2 , V_487 ) ) {
V_2 -> V_500 ( V_2 ) ;
break;
}
if ( V_40 -> V_661 < 0 ) {
F_257 ( V_2 ) ;
F_81 ( F_4 ( V_2 ) , V_662 ) ;
return 1 ;
}
if ( F_26 ( V_4 ) -> V_109 != F_26 ( V_4 ) -> V_91 &&
F_65 ( F_26 ( V_4 ) -> V_109 - V_53 -> V_521 , V_40 -> V_107 ) ) {
if ( V_40 -> V_611 && V_53 -> V_521 )
F_353 ( V_2 ) ;
F_257 ( V_2 ) ;
F_81 ( F_4 ( V_2 ) , V_662 ) ;
return 1 ;
}
V_658 = F_382 ( V_2 ) ;
if ( V_658 > V_663 ) {
F_361 ( V_2 , V_658 - V_663 ) ;
} else if ( V_53 -> V_521 || F_308 ( V_2 ) ) {
F_361 ( V_2 , V_658 ) ;
} else {
F_262 ( V_2 , V_497 , V_658 ) ;
goto V_607;
}
break;
}
case V_494 :
if ( V_40 -> V_122 == V_40 -> V_659 ) {
F_262 ( V_2 , V_498 , 0 ) ;
goto V_607;
}
break;
case V_495 :
if ( V_40 -> V_122 == V_40 -> V_659 ) {
F_383 ( V_2 ) ;
F_257 ( V_2 ) ;
goto V_607;
}
break;
}
F_347 ( V_2 , V_4 , V_53 ) ;
switch ( V_2 -> V_479 ) {
case V_483 :
case V_494 :
case V_495 :
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_107 ) )
break;
case V_496 :
case V_497 :
if ( V_2 -> V_489 & V_490 ) {
if ( F_26 ( V_4 ) -> V_109 != F_26 ( V_4 ) -> V_91 &&
F_65 ( F_26 ( V_4 ) -> V_109 - V_53 -> V_521 , V_40 -> V_107 ) ) {
F_81 ( F_4 ( V_2 ) , V_662 ) ;
F_255 ( V_2 ) ;
return 1 ;
}
}
case V_493 :
F_306 ( V_2 , V_4 ) ;
V_654 = 1 ;
break;
}
if ( V_2 -> V_479 != V_485 ) {
F_338 ( V_2 ) ;
F_343 ( V_2 ) ;
}
if ( ! V_654 ) {
V_607:
F_278 ( V_2 , V_4 ) ;
}
return 0 ;
}
static inline void F_384 ( struct V_341 * V_342 , T_12 V_664 , int V_665 )
{
struct V_666 * V_667 = F_385 ( V_342 ) ;
if ( V_665 == V_280 )
F_386 ( L_23 ,
& V_667 -> V_668 , V_664 ) ;
#if F_161 ( V_283 )
else if ( V_665 == V_284 )
F_386 ( L_24 ,
& V_667 -> V_669 , V_664 ) ;
#endif
}
static void F_387 ( struct V_341 * V_342 ,
const struct V_3 * V_4 ,
const struct V_1 * V_670 ,
const struct V_36 * V_37 )
{
const struct V_22 * V_53 = F_14 ( V_4 ) ;
const struct V_244 * V_244 = F_4 ( V_670 ) ;
bool V_671 = V_53 -> V_54 && V_53 -> V_44 ;
bool V_672 , V_673 ;
T_2 V_674 ;
if ( ! V_671 )
return;
V_672 = ! F_388 ( F_26 ( V_4 ) -> V_46 ) ;
V_674 = F_389 ( V_37 , V_675 ) ;
V_673 = V_244 -> V_256 . V_676 || V_674 ;
if ( ( ! V_672 && V_673 ) || F_27 ( V_670 ) ||
( V_674 & V_677 ) )
F_385 ( V_342 ) -> V_673 = 1 ;
}
static void F_390 ( struct V_341 * V_342 ,
const struct V_440 * V_62 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_666 * V_667 = F_385 ( V_342 ) ;
V_342 -> V_678 = 0 ;
V_342 -> V_679 = 0 ;
F_195 ( V_342 ) -> V_680 = F_26 ( V_4 ) -> V_91 ;
F_195 ( V_342 ) -> V_107 = F_26 ( V_4 ) -> V_91 + 1 ;
F_46 ( & F_195 ( V_342 ) -> V_344 ) ;
F_195 ( V_342 ) -> V_393 = 0 ;
V_342 -> V_80 = V_62 -> V_63 ;
V_342 -> V_404 = V_62 -> V_274 ? V_62 -> V_405 : 0 ;
V_667 -> V_461 = V_62 -> V_461 ;
V_667 -> V_137 = V_62 -> V_137 ;
V_667 -> V_390 = V_62 -> V_390 ;
V_667 -> V_456 = V_62 -> V_456 ;
V_667 -> V_243 = 0 ;
V_667 -> V_673 = 0 ;
V_667 -> V_681 = F_14 ( V_4 ) -> V_682 ;
V_667 -> V_683 = F_159 ( F_14 ( V_4 ) -> V_684 ) ;
V_667 -> V_685 = F_391 ( V_2 , V_4 ) ;
}
struct V_341 * F_392 ( const struct V_686 * V_687 ,
struct V_1 * V_688 ,
bool V_689 )
{
struct V_341 * V_342 = F_393 ( V_687 , V_688 ,
V_689 ) ;
if ( V_342 ) {
struct V_666 * V_667 = F_385 ( V_342 ) ;
F_394 ( V_667 , V_409 ) ;
V_667 -> V_634 = NULL ;
#if F_161 ( V_283 )
V_667 -> V_690 = NULL ;
#endif
F_395 ( & V_667 -> V_691 , 0 ) ;
V_667 -> V_692 = V_693 ;
F_396 ( & V_667 -> V_694 , F_4 ( V_688 ) ) ;
V_667 -> V_695 = V_688 -> V_279 ;
}
return V_342 ;
}
static bool F_397 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_696 )
{
struct V_697 * V_698 = & F_8 ( V_2 ) -> V_650 ;
const char * V_276 = L_25 ;
bool V_699 = false ;
struct V_244 * V_244 = F_4 ( V_2 ) ;
#ifdef F_398
if ( V_244 -> V_256 . V_700 ) {
V_276 = L_26 ;
V_699 = true ;
F_399 ( F_4 ( V_2 ) , V_701 ) ;
} else
#endif
F_399 ( F_4 ( V_2 ) , V_702 ) ;
if ( ! V_698 -> V_703 &&
V_244 -> V_256 . V_700 != 2 &&
F_400 ( & V_698 -> V_703 , 1 ) == 0 )
F_401 ( L_27 ,
V_696 , F_159 ( F_14 ( V_4 ) -> V_684 ) , V_276 ) ;
return V_699 ;
}
static void F_402 ( const struct V_1 * V_2 ,
struct V_341 * V_342 ,
const struct V_3 * V_4 )
{
if ( F_15 ( V_2 ) -> V_704 ) {
T_2 V_5 = F_403 ( V_4 ) + F_404 ( V_4 ) ;
T_2 * V_576 ;
V_576 = F_405 ( V_5 + sizeof( T_2 ) , V_184 ) ;
if ( V_576 ) {
V_576 [ 0 ] = V_5 ;
memcpy ( & V_576 [ 1 ] , F_406 ( V_4 ) , V_5 ) ;
V_342 -> V_705 = V_576 ;
}
}
}
int F_407 ( struct V_686 * V_706 ,
const struct V_707 * V_708 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_434 V_435 = { . V_5 = - 1 } ;
T_4 V_709 = F_26 ( V_4 ) -> V_710 ;
struct V_440 V_711 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_244 * V_244 = F_4 ( V_2 ) ;
struct V_1 * V_712 = NULL ;
struct V_36 * V_37 = NULL ;
struct V_341 * V_342 ;
bool V_699 = false ;
struct V_713 V_714 ;
if ( ( V_244 -> V_256 . V_700 == 2 ||
F_408 ( V_2 ) ) && ! V_709 ) {
V_699 = F_397 ( V_2 , V_4 , V_706 -> V_715 ) ;
if ( ! V_699 )
goto V_564;
}
if ( F_409 ( V_2 ) ) {
F_81 ( F_4 ( V_2 ) , V_716 ) ;
goto V_564;
}
V_342 = F_392 ( V_706 , V_2 , ! V_699 ) ;
if ( ! V_342 )
goto V_564;
F_195 ( V_342 ) -> V_717 = V_708 ;
F_195 ( V_342 ) -> V_718 = 0 ;
F_365 ( & V_711 ) ;
V_711 . V_63 = V_708 -> V_63 ;
V_711 . V_452 = V_40 -> V_62 . V_452 ;
F_241 ( V_4 , & V_711 , 0 , V_699 ? NULL : & V_435 ) ;
if ( V_699 && ! V_711 . V_274 )
F_365 ( & V_711 ) ;
V_711 . V_461 = V_711 . V_274 ;
F_390 ( V_342 , & V_711 , V_4 , V_2 ) ;
F_385 ( V_342 ) -> V_719 = F_158 ( V_2 ) -> V_720 ;
F_385 ( V_342 ) -> V_721 = F_410 ( V_2 , V_4 ) ;
V_708 -> V_722 ( V_342 , V_2 , V_4 ) ;
if ( F_411 ( V_2 , V_4 , V_342 ) )
goto V_723;
if ( V_711 . V_461 )
F_195 ( V_342 ) -> V_718 = V_708 -> V_724 ( V_4 ) ;
if ( ! V_699 && ! V_709 ) {
if ( ! V_244 -> V_256 . V_700 &&
( V_244 -> V_256 . V_725 - F_412 ( V_2 ) <
( V_244 -> V_256 . V_725 >> 2 ) ) &&
! F_413 ( V_342 , V_37 ) ) {
F_384 ( V_342 , F_159 ( F_14 ( V_4 ) -> V_682 ) ,
V_706 -> V_665 ) ;
goto V_726;
}
V_709 = V_708 -> V_727 ( V_4 ) ;
}
if ( ! V_37 ) {
V_37 = V_708 -> V_728 ( V_2 , & V_714 , V_342 ) ;
if ( ! V_37 )
goto V_723;
}
F_387 ( V_342 , V_4 , V_2 , V_37 ) ;
if ( V_699 ) {
V_709 = F_414 ( V_708 , V_2 , V_4 , & V_342 -> V_80 ) ;
V_342 -> V_679 = V_711 . V_461 ;
if ( ! V_711 . V_461 )
F_385 ( V_342 ) -> V_673 = 0 ;
}
F_195 ( V_342 ) -> V_729 = V_709 ;
F_195 ( V_342 ) -> V_730 = F_415 () ;
F_416 ( V_342 , V_2 , V_37 ) ;
if ( ! V_699 ) {
F_402 ( V_2 , V_342 , V_4 ) ;
V_712 = F_417 ( V_2 , V_4 , V_342 , & V_435 , V_37 ) ;
}
if ( V_712 ) {
V_708 -> V_731 ( V_712 , V_37 , & V_714 , V_342 ,
& V_435 , V_732 ) ;
F_418 ( V_2 , V_342 , V_712 ) ;
V_2 -> V_565 ( V_2 ) ;
F_419 ( V_712 ) ;
F_420 ( V_712 ) ;
} else {
F_195 ( V_342 ) -> V_733 = false ;
if ( ! V_699 )
F_421 ( V_2 , V_342 , V_734 ) ;
V_708 -> V_731 ( V_2 , V_37 , & V_714 , V_342 , & V_435 ,
! V_699 ? V_735 :
V_736 ) ;
if ( V_699 ) {
F_422 ( V_342 ) ;
return 0 ;
}
}
F_423 ( V_342 ) ;
return 0 ;
V_726:
F_424 ( V_37 ) ;
V_723:
F_422 ( V_342 ) ;
V_564:
F_425 ( V_2 ) ;
return 0 ;
}
