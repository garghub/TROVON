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
F_46 ( V_40 ) ;
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
if ( V_40 -> V_101 . time == 0 )
goto V_105;
if ( F_56 ( V_40 -> V_106 , V_40 -> V_101 . V_91 ) )
return;
V_104 = F_57 ( V_40 -> V_90 , V_40 -> V_101 . time ) ;
F_54 ( V_40 , V_104 , 1 ) ;
V_105:
V_40 -> V_101 . V_91 = V_40 -> V_106 + V_40 -> V_30 ;
V_40 -> V_101 . time = V_40 -> V_90 ;
}
static inline void F_58 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_62 . V_107 &&
( F_26 ( V_4 ) -> V_108 -
F_26 ( V_4 ) -> V_91 >= F_8 ( V_2 ) -> V_15 . V_18 ) ) {
T_2 V_109 = F_59 ( V_40 ) - V_40 -> V_62 . V_107 ;
T_2 V_104 = V_109 * ( V_110 / V_111 ) ;
F_54 ( V_40 , V_104 , 0 ) ;
}
}
void F_60 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int time ;
int V_112 ;
time = F_57 ( V_40 -> V_90 , V_40 -> V_88 . time ) ;
if ( time < ( V_40 -> V_101 . V_102 >> 3 ) || V_40 -> V_101 . V_102 == 0 )
return;
V_112 = V_40 -> V_92 - V_40 -> V_88 . V_91 ;
if ( V_112 <= V_40 -> V_88 . V_89 )
goto V_105;
if ( V_82 &&
! ( V_2 -> V_85 & V_86 ) ) {
int V_113 , V_81 , V_114 ;
V_113 = ( V_112 << 1 ) + 16 * V_40 -> V_79 ;
if ( V_112 >=
V_40 -> V_88 . V_89 + ( V_40 -> V_88 . V_89 >> 2 ) ) {
if ( V_112 >=
V_40 -> V_88 . V_89 + ( V_40 -> V_88 . V_89 >> 1 ) )
V_113 <<= 1 ;
else
V_113 += ( V_113 >> 1 ) ;
}
V_81 = F_43 ( V_40 -> V_79 + V_65 ) ;
while ( F_38 ( V_81 ) < V_40 -> V_79 )
V_81 += 128 ;
V_114 = F_17 ( V_113 / V_40 -> V_79 * V_81 , V_75 [ 2 ] ) ;
if ( V_114 > V_2 -> V_83 ) {
V_2 -> V_83 = V_114 ;
V_40 -> V_77 = V_113 ;
}
}
V_40 -> V_88 . V_89 = V_112 ;
V_105:
V_40 -> V_88 . V_91 = V_40 -> V_92 ;
V_40 -> V_88 . time = V_40 -> V_90 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
T_2 V_115 ;
F_62 ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
F_55 ( V_40 ) ;
V_115 = V_95 ;
if ( ! V_13 -> V_15 . V_34 ) {
F_16 ( V_2 ) ;
V_13 -> V_15 . V_34 = V_35 ;
} else {
int V_103 = V_115 - V_13 -> V_15 . V_116 ;
if ( V_103 <= V_35 / 2 ) {
V_13 -> V_15 . V_34 = ( V_13 -> V_15 . V_34 >> 1 ) + V_35 / 2 ;
} else if ( V_103 < V_13 -> V_15 . V_34 ) {
V_13 -> V_15 . V_34 = ( V_13 -> V_15 . V_34 >> 1 ) + V_103 ;
if ( V_13 -> V_15 . V_34 > V_13 -> V_117 )
V_13 -> V_15 . V_34 = V_13 -> V_117 ;
} else if ( V_103 > V_13 -> V_117 ) {
F_16 ( V_2 ) ;
F_63 ( V_2 ) ;
}
}
V_13 -> V_15 . V_116 = V_115 ;
F_29 ( V_40 , V_4 ) ;
if ( V_4 -> V_5 >= 128 )
F_39 ( V_2 , V_4 ) ;
}
static void F_64 ( struct V_1 * V_2 , long V_118 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
long V_103 = V_118 ;
T_2 V_119 = V_40 -> V_120 ;
if ( V_119 != 0 ) {
V_103 -= ( V_119 >> 3 ) ;
V_119 += V_103 ;
if ( V_103 < 0 ) {
V_103 = - V_103 ;
V_103 -= ( V_40 -> V_121 >> 2 ) ;
if ( V_103 > 0 )
V_103 >>= 3 ;
} else {
V_103 -= ( V_40 -> V_121 >> 2 ) ;
}
V_40 -> V_121 += V_103 ;
if ( V_40 -> V_121 > V_40 -> V_122 ) {
V_40 -> V_122 = V_40 -> V_121 ;
if ( V_40 -> V_122 > V_40 -> V_123 )
V_40 -> V_123 = V_40 -> V_122 ;
}
if ( F_65 ( V_40 -> V_124 , V_40 -> V_125 ) ) {
if ( V_40 -> V_122 < V_40 -> V_123 )
V_40 -> V_123 -= ( V_40 -> V_123 - V_40 -> V_122 ) >> 2 ;
V_40 -> V_125 = V_40 -> V_126 ;
V_40 -> V_122 = F_66 ( V_2 ) ;
}
} else {
V_119 = V_103 << 3 ;
V_40 -> V_121 = V_103 << 1 ;
V_40 -> V_123 = F_48 ( V_40 -> V_121 , F_66 ( V_2 ) ) ;
V_40 -> V_122 = V_40 -> V_123 ;
V_40 -> V_125 = V_40 -> V_126 ;
}
V_40 -> V_120 = F_48 ( 1U , V_119 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
T_3 V_127 ;
V_127 = ( T_3 ) V_40 -> V_64 * ( ( V_110 / 100 ) << 3 ) ;
if ( V_40 -> V_68 < V_40 -> V_128 / 2 )
V_127 *= V_129 ;
else
V_127 *= V_130 ;
V_127 *= F_48 ( V_40 -> V_68 , V_40 -> V_131 ) ;
if ( F_68 ( V_40 -> V_120 ) )
F_69 ( V_127 , V_40 -> V_120 ) ;
F_70 ( V_2 -> V_132 ) = F_10 ( T_3 , V_127 ,
V_2 -> V_133 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
F_8 ( V_2 ) -> V_117 = F_72 ( V_40 ) ;
F_73 ( V_2 ) ;
}
T_4 F_74 ( const struct V_39 * V_40 , const struct V_36 * V_37 )
{
T_4 V_134 = ( V_37 ? F_21 ( V_37 , V_135 ) : 0 ) ;
if ( ! V_134 )
V_134 = V_67 ;
return F_10 ( T_4 , V_134 , V_40 -> V_136 ) ;
}
void F_75 ( struct V_39 * V_40 )
{
if ( F_76 ( V_40 ) )
V_40 -> V_137 = NULL ;
V_40 -> V_62 . V_138 &= ~ V_139 ;
}
static void F_77 ( struct V_39 * V_40 )
{
V_40 -> V_62 . V_138 |= V_140 ;
}
static void F_78 ( struct V_1 * V_2 , const int V_141 ,
const int V_142 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_143 ;
if ( F_79 ( V_141 < 0 ) )
return;
if ( V_141 > V_40 -> V_69 ) {
V_40 -> V_69 = F_17 ( V_144 , V_141 ) ;
#if V_145 > 1
F_80 ( L_3 ,
V_40 -> V_62 . V_138 , F_8 ( V_2 ) -> V_146 ,
V_40 -> V_69 ,
V_40 -> V_147 ,
V_40 -> V_148 ,
V_40 -> V_149 ? V_40 -> V_150 : 0 ) ;
#endif
F_75 ( V_40 ) ;
}
V_40 -> V_151 . V_152 = 1 ;
if ( V_142 )
V_143 = V_153 ;
else if ( F_81 ( V_40 ) )
V_143 = V_154 ;
else if ( F_76 ( V_40 ) )
V_143 = V_155 ;
else
V_143 = V_156 ;
F_82 ( F_4 ( V_2 ) , V_143 ) ;
}
static void F_83 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
if ( ! V_40 -> V_157 ||
F_56 ( F_26 ( V_4 ) -> V_91 ,
F_26 ( V_40 -> V_157 ) -> V_91 ) )
V_40 -> V_157 = V_4 ;
}
static void F_84 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
T_5 V_158 = F_26 ( V_4 ) -> V_158 ;
if ( ! ( V_158 & V_159 ) ||
( ( V_158 & V_159 ) && ( V_158 & V_160 ) ) )
V_40 -> V_161 += F_85 ( V_4 ) ;
}
static void F_86 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
if ( ! ( F_26 ( V_4 ) -> V_158 & ( V_159 | V_162 ) ) ) {
F_83 ( V_40 , V_4 ) ;
V_40 -> V_163 += F_85 ( V_4 ) ;
F_84 ( V_40 , V_4 ) ;
F_26 ( V_4 ) -> V_158 |= V_159 ;
}
}
void F_87 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
F_83 ( V_40 , V_4 ) ;
F_84 ( V_40 , V_4 ) ;
if ( ! ( F_26 ( V_4 ) -> V_158 & ( V_159 | V_162 ) ) ) {
V_40 -> V_163 += F_85 ( V_4 ) ;
F_26 ( V_4 ) -> V_158 |= V_159 ;
}
}
static bool F_88 ( struct V_39 * V_40 , bool V_164 ,
T_2 V_165 , T_2 V_108 )
{
if ( F_65 ( V_108 , V_40 -> V_126 ) || ! F_56 ( V_165 , V_108 ) )
return false ;
if ( ! F_56 ( V_165 , V_40 -> V_126 ) )
return false ;
if ( F_65 ( V_165 , V_40 -> V_124 ) )
return true ;
if ( ! V_164 || ! V_40 -> V_149 )
return false ;
if ( F_65 ( V_108 , V_40 -> V_124 ) )
return false ;
if ( ! F_56 ( V_165 , V_40 -> V_149 ) )
return true ;
if ( ! F_65 ( V_108 , V_40 -> V_149 ) )
return false ;
return ! F_56 ( V_165 , V_108 - V_40 -> V_166 ) ;
}
static bool F_89 ( struct V_1 * V_2 , const struct V_3 * V_167 ,
struct V_168 * V_169 , int V_170 ,
T_2 V_171 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_172 = F_90 ( & V_169 [ 0 ] . V_165 ) ;
T_2 V_173 = F_90 ( & V_169 [ 0 ] . V_108 ) ;
bool V_174 = false ;
if ( F_56 ( V_172 , F_26 ( V_167 ) -> V_175 ) ) {
V_174 = true ;
F_77 ( V_40 ) ;
F_82 ( F_4 ( V_2 ) , V_176 ) ;
} else if ( V_170 > 1 ) {
T_2 V_177 = F_90 ( & V_169 [ 1 ] . V_108 ) ;
T_2 V_178 = F_90 ( & V_169 [ 1 ] . V_165 ) ;
if ( ! F_65 ( V_173 , V_177 ) &&
! F_56 ( V_172 , V_178 ) ) {
V_174 = true ;
F_77 ( V_40 ) ;
F_82 ( F_4 ( V_2 ) ,
V_179 ) ;
}
}
if ( V_174 && V_40 -> V_149 && V_40 -> V_150 > 0 &&
! F_65 ( V_173 , V_171 ) &&
F_65 ( V_173 , V_40 -> V_149 ) )
V_40 -> V_150 -- ;
return V_174 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_165 , T_2 V_108 )
{
int V_180 ;
bool V_181 ;
unsigned int V_182 ;
unsigned int V_80 ;
V_181 = ! F_65 ( V_165 , F_26 ( V_4 ) -> V_91 ) &&
! F_56 ( V_108 , F_26 ( V_4 ) -> V_108 ) ;
if ( F_85 ( V_4 ) > 1 && ! V_181 &&
F_65 ( F_26 ( V_4 ) -> V_108 , V_165 ) ) {
V_80 = F_92 ( V_4 ) ;
V_181 = ! F_65 ( V_165 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! V_181 ) {
V_182 = V_165 - F_26 ( V_4 ) -> V_91 ;
if ( V_182 < V_80 )
V_182 = V_80 ;
} else {
V_182 = V_108 - F_26 ( V_4 ) -> V_91 ;
if ( V_182 < V_80 )
return - V_183 ;
}
if ( V_182 > V_80 ) {
unsigned int V_184 = ( V_182 / V_80 ) * V_80 ;
if ( ! V_181 && V_184 < V_182 )
V_184 += V_80 ;
V_182 = V_184 ;
}
if ( V_182 >= V_4 -> V_5 && ! V_181 )
return 0 ;
V_180 = F_93 ( V_2 , V_4 , V_182 , V_80 , V_185 ) ;
if ( V_180 < 0 )
return V_180 ;
}
return V_181 ;
}
static T_6 F_94 ( struct V_1 * V_2 ,
struct V_186 * V_187 , T_6 V_158 ,
T_2 V_165 , T_2 V_108 ,
int V_174 , int V_188 ,
T_3 V_189 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_190 = V_187 -> V_190 ;
if ( V_174 && ( V_158 & V_191 ) ) {
if ( V_40 -> V_149 && V_40 -> V_150 > 0 &&
F_65 ( V_108 , V_40 -> V_149 ) )
V_40 -> V_150 -- ;
if ( V_158 & V_162 )
V_187 -> V_152 = F_17 ( V_190 , V_187 -> V_152 ) ;
}
if ( ! F_65 ( V_108 , V_40 -> V_124 ) )
return V_158 ;
if ( ! ( V_158 & V_162 ) ) {
F_95 ( V_40 , V_158 , V_108 , V_189 ) ;
if ( V_158 & V_160 ) {
if ( V_158 & V_159 ) {
V_158 &= ~ ( V_159 | V_160 ) ;
V_40 -> V_163 -= V_188 ;
V_40 -> V_192 -= V_188 ;
}
} else {
if ( ! ( V_158 & V_191 ) ) {
if ( F_56 ( V_165 ,
F_96 ( V_40 ) ) )
V_187 -> V_152 = F_17 ( V_190 ,
V_187 -> V_152 ) ;
if ( ! F_65 ( V_108 , V_40 -> V_193 ) )
V_187 -> V_194 |= V_195 ;
if ( V_187 -> V_196 == 0 )
V_187 -> V_196 = V_189 ;
V_187 -> V_197 = V_189 ;
}
if ( V_158 & V_159 ) {
V_158 &= ~ V_159 ;
V_40 -> V_163 -= V_188 ;
}
}
V_158 |= V_162 ;
V_187 -> V_194 |= V_198 ;
V_40 -> V_148 += V_188 ;
V_40 -> V_199 += V_188 ;
V_190 += V_188 ;
if ( ! F_76 ( V_40 ) && V_40 -> V_137 &&
F_56 ( V_165 , F_26 ( V_40 -> V_137 ) -> V_91 ) )
V_40 -> V_200 += V_188 ;
if ( V_190 > V_40 -> V_147 )
V_40 -> V_147 = V_190 ;
}
if ( V_174 && ( V_158 & V_160 ) ) {
V_158 &= ~ V_160 ;
V_40 -> V_192 -= V_188 ;
}
return V_158 ;
}
static bool F_97 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_186 * V_187 ,
unsigned int V_188 , int V_201 , int V_80 ,
bool V_174 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_202 = F_98 ( V_2 , V_4 ) ;
T_2 V_165 = F_26 ( V_4 ) -> V_91 ;
T_2 V_108 = V_165 + V_201 ;
F_99 ( ! V_188 ) ;
F_94 ( V_2 , V_187 , F_26 ( V_4 ) -> V_158 ,
V_165 , V_108 , V_174 , V_188 ,
V_4 -> V_203 ) ;
F_100 ( V_2 , V_4 , V_187 -> V_127 ) ;
if ( V_4 == V_40 -> V_137 )
V_40 -> V_200 += V_188 ;
F_26 ( V_202 ) -> V_108 += V_201 ;
F_26 ( V_4 ) -> V_91 += V_201 ;
F_101 ( V_202 , V_188 ) ;
F_99 ( F_85 ( V_4 ) < V_188 ) ;
F_101 ( V_4 , - V_188 ) ;
if ( ! F_26 ( V_202 ) -> V_204 )
F_26 ( V_202 ) -> V_204 = V_80 ;
if ( F_85 ( V_4 ) <= 1 )
F_26 ( V_4 ) -> V_204 = 0 ;
F_26 ( V_202 ) -> V_158 |= ( F_26 ( V_4 ) -> V_158 & V_205 ) ;
if ( V_4 -> V_5 > 0 ) {
F_99 ( ! F_85 ( V_4 ) ) ;
F_82 ( F_4 ( V_2 ) , V_206 ) ;
return false ;
}
if ( V_4 == V_40 -> V_157 )
V_40 -> V_157 = V_202 ;
if ( V_4 == V_40 -> V_137 ) {
V_40 -> V_137 = V_202 ;
V_40 -> V_200 -= F_85 ( V_202 ) ;
}
F_26 ( V_202 ) -> V_207 |= F_26 ( V_4 ) -> V_207 ;
F_26 ( V_202 ) -> V_208 = F_26 ( V_4 ) -> V_208 ;
if ( F_26 ( V_4 ) -> V_207 & V_209 )
F_26 ( V_202 ) -> V_108 ++ ;
if ( V_4 == F_102 ( V_2 ) )
F_103 ( V_2 , V_4 ) ;
F_104 ( V_202 , V_4 ) ;
if ( F_11 ( F_26 ( V_202 ) -> V_210 . V_211 ) )
F_26 ( V_202 ) -> V_210 . V_211 = 0 ;
F_105 ( V_4 , V_2 ) ;
F_106 ( V_2 , V_4 ) ;
F_82 ( F_4 ( V_2 ) , V_212 ) ;
return true ;
}
static int F_107 ( const struct V_3 * V_4 )
{
return F_85 ( V_4 ) == 1 ? V_4 -> V_5 : F_92 ( V_4 ) ;
}
static int F_108 ( const struct V_3 * V_4 )
{
return ! F_109 ( V_4 ) && F_110 ( V_4 ) ;
}
static struct V_3 * F_111 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_186 * V_187 ,
T_2 V_165 , T_2 V_108 ,
bool V_174 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_202 ;
int V_80 ;
int V_188 = 0 ;
int V_5 ;
int V_181 ;
if ( ! F_112 ( V_2 ) )
goto V_213;
if ( ! V_174 &&
( F_26 ( V_4 ) -> V_158 & ( V_159 | V_160 ) ) == V_160 )
goto V_213;
if ( ! F_108 ( V_4 ) )
goto V_213;
if ( ! F_65 ( F_26 ( V_4 ) -> V_108 , V_40 -> V_124 ) )
goto V_213;
if ( F_11 ( V_4 == F_113 ( V_2 ) ) )
goto V_213;
V_202 = F_98 ( V_2 , V_4 ) ;
if ( ( F_26 ( V_202 ) -> V_158 & V_214 ) != V_162 )
goto V_213;
if ( ! F_114 ( V_202 ) )
goto V_213;
V_181 = ! F_65 ( V_165 , F_26 ( V_4 ) -> V_91 ) &&
! F_56 ( V_108 , F_26 ( V_4 ) -> V_108 ) ;
if ( V_181 ) {
V_5 = V_4 -> V_5 ;
V_188 = F_85 ( V_4 ) ;
V_80 = F_107 ( V_4 ) ;
if ( V_80 != F_107 ( V_202 ) )
goto V_213;
} else {
if ( ! F_65 ( F_26 ( V_4 ) -> V_108 , V_165 ) )
goto V_215;
if ( F_85 ( V_4 ) <= 1 )
goto V_215;
V_181 = ! F_65 ( V_165 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! V_181 ) {
goto V_213;
}
V_5 = V_108 - F_26 ( V_4 ) -> V_91 ;
F_99 ( V_5 < 0 ) ;
F_99 ( V_5 > V_4 -> V_5 ) ;
V_80 = F_92 ( V_4 ) ;
if ( V_80 != F_107 ( V_202 ) )
goto V_213;
if ( V_5 == V_80 ) {
V_188 = 1 ;
} else if ( V_5 < V_80 ) {
goto V_215;
} else {
V_188 = V_5 / V_80 ;
V_5 = V_188 * V_80 ;
}
}
if ( ! F_65 ( F_26 ( V_4 ) -> V_91 + V_5 , V_40 -> V_124 ) )
goto V_213;
if ( ! F_115 ( V_202 , V_4 , V_5 ) )
goto V_213;
if ( ! F_97 ( V_2 , V_4 , V_187 , V_188 , V_5 , V_80 , V_174 ) )
goto V_216;
if ( V_202 == F_116 ( V_2 ) )
goto V_216;
V_4 = F_117 ( V_2 , V_202 ) ;
if ( ! F_108 ( V_4 ) ||
( V_4 == F_118 ( V_2 ) ) ||
( ( F_26 ( V_4 ) -> V_158 & V_214 ) != V_162 ) ||
( V_80 != F_107 ( V_4 ) ) )
goto V_216;
V_5 = V_4 -> V_5 ;
if ( F_115 ( V_202 , V_4 , V_5 ) ) {
V_188 += F_85 ( V_4 ) ;
F_97 ( V_2 , V_4 , V_187 , F_85 ( V_4 ) , V_5 , V_80 , 0 ) ;
}
V_216:
V_187 -> V_190 += V_188 ;
return V_202 ;
V_215:
return V_4 ;
V_213:
F_82 ( F_4 ( V_2 ) , V_217 ) ;
return NULL ;
}
static struct V_3 * F_119 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_218 * V_219 ,
struct V_186 * V_187 ,
T_2 V_165 , T_2 V_108 ,
bool V_220 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_221 ;
F_120 (skb, sk) {
int V_181 = 0 ;
bool V_174 = V_220 ;
if ( V_4 == F_118 ( V_2 ) )
break;
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 , V_108 ) )
break;
if ( V_219 &&
F_56 ( F_26 ( V_4 ) -> V_91 , V_219 -> V_108 ) ) {
V_181 = F_91 ( V_2 , V_4 ,
V_219 -> V_165 ,
V_219 -> V_108 ) ;
if ( V_181 > 0 )
V_174 = true ;
}
if ( V_181 <= 0 ) {
V_221 = F_111 ( V_2 , V_4 , V_187 ,
V_165 , V_108 , V_174 ) ;
if ( V_221 ) {
if ( V_221 != V_4 ) {
V_4 = V_221 ;
continue;
}
V_181 = 0 ;
} else {
V_181 = F_91 ( V_2 , V_4 ,
V_165 ,
V_108 ) ;
}
}
if ( F_11 ( V_181 < 0 ) )
break;
if ( V_181 ) {
F_26 ( V_4 ) -> V_158 =
F_94 ( V_2 ,
V_187 ,
F_26 ( V_4 ) -> V_158 ,
F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_108 ,
V_174 ,
F_85 ( V_4 ) ,
V_4 -> V_203 ) ;
F_100 ( V_2 , V_4 , V_187 -> V_127 ) ;
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 ,
F_96 ( V_40 ) ) )
F_103 ( V_2 , V_4 ) ;
}
V_187 -> V_190 += F_85 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_121 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_186 * V_187 ,
T_2 V_222 )
{
F_120 (skb, sk) {
if ( V_4 == F_118 ( V_2 ) )
break;
if ( F_65 ( F_26 ( V_4 ) -> V_108 , V_222 ) )
break;
V_187 -> V_190 += F_85 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_122 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_218 * V_219 ,
struct V_186 * V_187 ,
T_2 V_222 )
{
if ( ! V_219 )
return V_4 ;
if ( F_56 ( V_219 -> V_165 , V_222 ) ) {
V_4 = F_121 ( V_4 , V_2 , V_187 , V_219 -> V_165 ) ;
V_4 = F_119 ( V_4 , V_2 , NULL , V_187 ,
V_219 -> V_165 , V_219 -> V_108 ,
1 ) ;
}
return V_4 ;
}
static int F_123 ( const struct V_39 * V_40 , const struct V_218 * V_223 )
{
return V_223 < V_40 -> V_224 + F_124 ( V_40 -> V_224 ) ;
}
static int
F_125 ( struct V_1 * V_2 , const struct V_3 * V_167 ,
T_2 V_171 , struct V_186 * V_187 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
const unsigned char * V_225 = ( F_12 ( V_167 ) +
F_26 ( V_167 ) -> V_158 ) ;
struct V_168 * V_226 = (struct V_168 * ) ( V_225 + 2 ) ;
struct V_218 V_169 [ V_227 ] ;
struct V_218 * V_223 ;
struct V_3 * V_4 ;
int V_170 = F_17 ( V_227 , ( V_225 [ 1 ] - V_228 ) >> 3 ) ;
int V_229 ;
bool V_230 = false ;
int V_231 , V_232 ;
int V_233 ;
V_187 -> V_194 = 0 ;
V_187 -> V_152 = V_40 -> V_131 ;
if ( ! V_40 -> V_148 ) {
if ( F_126 ( V_40 -> V_147 ) )
V_40 -> V_147 = 0 ;
F_127 ( V_2 ) ;
}
V_230 = F_89 ( V_2 , V_167 , V_226 ,
V_170 , V_171 ) ;
if ( V_230 ) {
V_187 -> V_194 |= V_234 ;
V_40 -> V_199 ++ ;
}
if ( F_56 ( F_26 ( V_167 ) -> V_175 , V_171 - V_40 -> V_166 ) )
return 0 ;
if ( ! V_40 -> V_131 )
goto V_216;
V_229 = 0 ;
V_233 = 0 ;
for ( V_231 = 0 ; V_231 < V_170 ; V_231 ++ ) {
bool V_174 = ! V_231 && V_230 ;
V_169 [ V_229 ] . V_165 = F_90 ( & V_226 [ V_231 ] . V_165 ) ;
V_169 [ V_229 ] . V_108 = F_90 ( & V_226 [ V_231 ] . V_108 ) ;
if ( ! F_88 ( V_40 , V_174 ,
V_169 [ V_229 ] . V_165 ,
V_169 [ V_229 ] . V_108 ) ) {
int V_143 ;
if ( V_174 ) {
if ( ! V_40 -> V_149 )
V_143 = V_235 ;
else
V_143 = V_236 ;
} else {
if ( ( F_26 ( V_167 ) -> V_175 != V_40 -> V_124 ) &&
! F_65 ( V_169 [ V_229 ] . V_108 , V_40 -> V_124 ) )
continue;
V_143 = V_237 ;
}
F_82 ( F_4 ( V_2 ) , V_143 ) ;
if ( V_231 == 0 )
V_233 = - 1 ;
continue;
}
if ( ! F_65 ( V_169 [ V_229 ] . V_108 , V_171 ) )
continue;
V_229 ++ ;
}
for ( V_231 = V_229 - 1 ; V_231 > 0 ; V_231 -- ) {
for ( V_232 = 0 ; V_232 < V_231 ; V_232 ++ ) {
if ( F_65 ( V_169 [ V_232 ] . V_165 , V_169 [ V_232 + 1 ] . V_165 ) ) {
F_128 ( V_169 [ V_232 ] , V_169 [ V_232 + 1 ] ) ;
if ( V_232 == V_233 )
V_233 = V_232 + 1 ;
}
}
}
V_4 = F_113 ( V_2 ) ;
V_187 -> V_190 = 0 ;
V_231 = 0 ;
if ( ! V_40 -> V_148 ) {
V_223 = V_40 -> V_224 + F_124 ( V_40 -> V_224 ) ;
} else {
V_223 = V_40 -> V_224 ;
while ( F_123 ( V_40 , V_223 ) && ! V_223 -> V_165 &&
! V_223 -> V_108 )
V_223 ++ ;
}
while ( V_231 < V_229 ) {
T_2 V_165 = V_169 [ V_231 ] . V_165 ;
T_2 V_108 = V_169 [ V_231 ] . V_108 ;
bool V_174 = ( V_230 && ( V_231 == V_233 ) ) ;
struct V_218 * V_219 = NULL ;
if ( V_230 && ( ( V_231 + 1 ) == V_233 ) )
V_219 = & V_169 [ V_231 + 1 ] ;
while ( F_123 ( V_40 , V_223 ) &&
! F_56 ( V_165 , V_223 -> V_108 ) )
V_223 ++ ;
if ( F_123 ( V_40 , V_223 ) && ! V_174 &&
F_65 ( V_108 , V_223 -> V_165 ) ) {
if ( F_56 ( V_165 , V_223 -> V_165 ) ) {
V_4 = F_121 ( V_4 , V_2 , V_187 ,
V_165 ) ;
V_4 = F_119 ( V_4 , V_2 , V_219 ,
V_187 ,
V_165 ,
V_223 -> V_165 ,
V_174 ) ;
}
if ( ! F_65 ( V_108 , V_223 -> V_108 ) )
goto V_238;
V_4 = F_122 ( V_4 , V_2 , V_219 ,
V_187 ,
V_223 -> V_108 ) ;
if ( F_96 ( V_40 ) == V_223 -> V_108 ) {
V_4 = F_102 ( V_2 ) ;
if ( ! V_4 )
break;
V_187 -> V_190 = V_40 -> V_147 ;
V_223 ++ ;
goto V_239;
}
V_4 = F_121 ( V_4 , V_2 , V_187 , V_223 -> V_108 ) ;
V_223 ++ ;
continue;
}
if ( ! F_56 ( V_165 , F_96 ( V_40 ) ) ) {
V_4 = F_102 ( V_2 ) ;
if ( ! V_4 )
break;
V_187 -> V_190 = V_40 -> V_147 ;
}
V_4 = F_121 ( V_4 , V_2 , V_187 , V_165 ) ;
V_239:
V_4 = F_119 ( V_4 , V_2 , V_219 , V_187 ,
V_165 , V_108 , V_174 ) ;
V_238:
V_231 ++ ;
}
for ( V_231 = 0 ; V_231 < F_124 ( V_40 -> V_224 ) - V_229 ; V_231 ++ ) {
V_40 -> V_224 [ V_231 ] . V_165 = 0 ;
V_40 -> V_224 [ V_231 ] . V_108 = 0 ;
}
for ( V_232 = 0 ; V_232 < V_229 ; V_232 ++ )
V_40 -> V_224 [ V_231 ++ ] = V_169 [ V_232 ] ;
if ( ( V_187 -> V_152 < V_40 -> V_147 ) &&
( ( F_8 ( V_2 ) -> V_146 != V_240 ) || V_40 -> V_149 ) )
F_78 ( V_2 , V_40 -> V_147 - V_187 -> V_152 , 0 ) ;
F_129 ( V_40 ) ;
V_216:
#if V_145 > 0
F_126 ( ( int ) V_40 -> V_148 < 0 ) ;
F_126 ( ( int ) V_40 -> V_163 < 0 ) ;
F_126 ( ( int ) V_40 -> V_192 < 0 ) ;
F_126 ( ( int ) F_130 ( V_40 ) < 0 ) ;
#endif
return V_187 -> V_194 ;
}
static bool F_131 ( struct V_39 * V_40 )
{
T_2 V_241 ;
V_241 = F_48 ( V_40 -> V_163 , 1U ) ;
V_241 = F_17 ( V_241 , V_40 -> V_131 ) ;
if ( ( V_40 -> V_148 + V_241 ) > V_40 -> V_131 ) {
V_40 -> V_148 = V_40 -> V_131 - V_241 ;
return true ;
}
return false ;
}
static void F_132 ( struct V_1 * V_2 , const int V_242 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_131 ( V_40 ) )
F_78 ( V_2 , V_40 -> V_131 + V_242 , 0 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_243 = V_40 -> V_148 ;
V_40 -> V_148 ++ ;
F_132 ( V_2 , 0 ) ;
if ( V_40 -> V_148 > V_243 )
V_40 -> V_199 ++ ;
F_129 ( V_40 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_244 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_244 > 0 ) {
V_40 -> V_199 += F_34 ( int , V_244 - V_40 -> V_148 , 1 ) ;
if ( V_244 - 1 >= V_40 -> V_148 )
V_40 -> V_148 = 0 ;
else
V_40 -> V_148 -= V_244 - 1 ;
}
F_132 ( V_2 , V_244 ) ;
F_129 ( V_40 ) ;
}
static inline void F_135 ( struct V_39 * V_40 )
{
V_40 -> V_148 = 0 ;
}
void F_136 ( struct V_39 * V_40 )
{
V_40 -> V_192 = 0 ;
V_40 -> V_163 = 0 ;
V_40 -> V_149 = 0 ;
V_40 -> V_150 = - 1 ;
V_40 -> V_147 = 0 ;
V_40 -> V_148 = 0 ;
}
static inline void F_137 ( struct V_39 * V_40 )
{
V_40 -> V_149 = V_40 -> V_124 ;
V_40 -> V_150 = V_40 -> V_192 ? : - 1 ;
}
void F_138 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_245 * V_245 = F_4 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_246 = V_13 -> V_146 < V_247 ;
bool V_248 ;
bool V_249 ;
if ( V_13 -> V_146 <= V_250 ||
! F_65 ( V_40 -> V_193 , V_40 -> V_124 ) ||
( V_13 -> V_146 == V_240 && ! V_13 -> V_251 ) ) {
V_40 -> V_252 = F_139 ( V_2 ) ;
V_40 -> V_128 = V_13 -> V_58 -> V_253 ( V_2 ) ;
F_28 ( V_2 , V_254 ) ;
F_137 ( V_40 ) ;
}
V_40 -> V_68 = 1 ;
V_40 -> V_255 = 0 ;
V_40 -> V_94 = V_95 ;
V_40 -> V_192 = 0 ;
V_40 -> V_163 = 0 ;
if ( F_81 ( V_40 ) )
F_135 ( V_40 ) ;
V_4 = F_113 ( V_2 ) ;
V_248 = V_4 && ( F_26 ( V_4 ) -> V_158 & V_162 ) ;
if ( V_248 ) {
F_82 ( F_4 ( V_2 ) , V_256 ) ;
V_40 -> V_148 = 0 ;
V_40 -> V_147 = 0 ;
}
F_140 ( V_40 ) ;
F_141 (skb, sk) {
if ( V_4 == F_118 ( V_2 ) )
break;
V_249 = ( ! ( F_26 ( V_4 ) -> V_158 & V_162 ) ||
V_248 ) ;
if ( V_249 )
F_84 ( V_40 , V_4 ) ;
F_26 ( V_4 ) -> V_158 &= ( ~ V_214 ) | V_162 ;
if ( V_249 ) {
F_26 ( V_4 ) -> V_158 &= ~ V_162 ;
F_26 ( V_4 ) -> V_158 |= V_159 ;
V_40 -> V_163 += F_85 ( V_4 ) ;
}
}
F_129 ( V_40 ) ;
if ( V_13 -> V_146 <= V_250 &&
V_40 -> V_148 >= V_245 -> V_257 . V_258 )
V_40 -> V_69 = F_10 (unsigned int, tp->reordering,
net->ipv4.sysctl_tcp_reordering) ;
F_142 ( V_2 , V_240 ) ;
V_40 -> V_193 = V_40 -> V_126 ;
F_22 ( V_40 ) ;
V_40 -> V_259 = V_260 &&
( V_246 || V_13 -> V_251 ) &&
! F_8 ( V_2 ) -> V_261 . V_262 ;
}
static bool F_143 ( struct V_1 * V_2 , int V_194 )
{
if ( V_194 & V_263 ) {
struct V_39 * V_40 = F_15 ( V_2 ) ;
unsigned long V_264 = F_48 ( F_144 ( V_40 -> V_120 >> 4 ) ,
F_145 ( 10 ) ) ;
F_146 ( V_2 , V_265 ,
V_264 , V_266 ) ;
return true ;
}
return false ;
}
static inline int F_147 ( const struct V_39 * V_40 )
{
return F_81 ( V_40 ) ? V_40 -> V_148 + 1 : V_40 -> V_147 ;
}
static inline int F_148 ( const struct V_39 * V_40 )
{
return F_76 ( V_40 ) ? V_40 -> V_147 : V_40 -> V_148 + 1 ;
}
static bool F_149 ( struct V_1 * V_2 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_163 )
return true ;
if ( F_148 ( V_40 ) > V_40 -> V_69 )
return true ;
return false ;
}
static void F_150 ( struct V_1 * V_2 , int V_267 , int V_268 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
int V_269 , V_270 , V_161 ;
unsigned int V_80 ;
const T_2 V_271 = F_151 ( V_40 ) ? V_40 -> V_126 : V_40 -> V_193 ;
F_126 ( V_267 > V_40 -> V_131 ) ;
if ( V_40 -> V_137 ) {
V_4 = V_40 -> V_137 ;
V_269 = V_40 -> V_200 ;
if ( V_268 && V_4 != F_113 ( V_2 ) )
return;
} else {
V_4 = F_113 ( V_2 ) ;
V_269 = 0 ;
}
F_120 (skb, sk) {
if ( V_4 == F_118 ( V_2 ) )
break;
V_40 -> V_137 = V_4 ;
V_40 -> V_200 = V_269 ;
if ( F_65 ( F_26 ( V_4 ) -> V_108 , V_271 ) )
break;
V_270 = V_269 ;
if ( F_76 ( V_40 ) || F_81 ( V_40 ) ||
( F_26 ( V_4 ) -> V_158 & V_162 ) )
V_269 += F_85 ( V_4 ) ;
if ( V_269 > V_267 ) {
if ( ( F_151 ( V_40 ) && ! F_76 ( V_40 ) ) ||
( F_26 ( V_4 ) -> V_158 & V_162 ) ||
( V_270 >= V_267 ) )
break;
V_80 = F_92 ( V_4 ) ;
V_161 = ( V_267 - V_270 ) * V_80 ;
if ( V_161 < V_4 -> V_5 &&
F_93 ( V_2 , V_4 , V_161 , V_80 , V_185 ) < 0 )
break;
V_269 = V_267 ;
}
F_86 ( V_40 , V_4 ) ;
if ( V_268 )
break;
}
F_129 ( V_40 ) ;
}
static void F_152 ( struct V_1 * V_2 , int V_272 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_81 ( V_40 ) ) {
F_150 ( V_2 , 1 , 1 ) ;
} else if ( F_76 ( V_40 ) ) {
int V_161 = V_40 -> V_147 - V_40 -> V_69 ;
if ( V_161 <= 0 )
V_161 = 1 ;
F_150 ( V_2 , V_161 , 0 ) ;
} else {
int V_273 = V_40 -> V_148 - V_40 -> V_69 ;
if ( V_273 >= 0 )
F_150 ( V_2 , V_273 , 0 ) ;
else if ( V_272 )
F_150 ( V_2 , 1 , 1 ) ;
}
}
static bool F_153 ( const struct V_39 * V_40 , T_2 V_274 )
{
return V_40 -> V_62 . V_275 && V_40 -> V_62 . V_107 &&
F_56 ( V_40 -> V_62 . V_107 , V_274 ) ;
}
static bool F_154 ( const struct V_39 * V_40 ,
const struct V_3 * V_4 )
{
return ( F_26 ( V_4 ) -> V_158 & V_191 ) &&
F_153 ( V_40 , F_155 ( V_4 ) ) ;
}
static inline bool F_156 ( const struct V_39 * V_40 )
{
return ! V_40 -> V_276 ||
F_153 ( V_40 , V_40 -> V_276 ) ;
}
static bool F_157 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_40 -> V_192 )
return true ;
V_4 = F_113 ( V_2 ) ;
if ( F_11 ( V_4 && F_26 ( V_4 ) -> V_158 & V_205 ) )
return true ;
return false ;
}
static void F_158 ( struct V_1 * V_2 , const char * V_277 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_278 * V_279 = F_159 ( V_2 ) ;
if ( V_2 -> V_280 == V_281 ) {
F_80 ( L_4 ,
V_277 ,
& V_279 -> V_282 , F_160 ( V_279 -> V_283 ) ,
V_40 -> V_68 , F_161 ( V_40 ) ,
V_40 -> V_128 , V_40 -> V_252 ,
V_40 -> V_131 ) ;
}
#if F_162 ( V_284 )
else if ( V_2 -> V_280 == V_285 ) {
F_80 ( L_5 ,
V_277 ,
& V_2 -> V_286 , F_160 ( V_279 -> V_283 ) ,
V_40 -> V_68 , F_161 ( V_40 ) ,
V_40 -> V_128 , V_40 -> V_252 ,
V_40 -> V_131 ) ;
}
#endif
}
static void F_163 ( struct V_1 * V_2 , bool V_287 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_287 ) {
struct V_3 * V_4 ;
F_141 (skb, sk) {
if ( V_4 == F_118 ( V_2 ) )
break;
F_26 ( V_4 ) -> V_158 &= ~ V_159 ;
}
V_40 -> V_163 = 0 ;
F_140 ( V_40 ) ;
}
if ( V_40 -> V_252 ) {
const struct V_12 * V_13 = F_8 ( V_2 ) ;
V_40 -> V_68 = V_13 -> V_58 -> V_288 ( V_2 ) ;
if ( V_40 -> V_252 > V_40 -> V_128 ) {
V_40 -> V_128 = V_40 -> V_252 ;
F_24 ( V_40 ) ;
}
}
V_40 -> V_94 = V_95 ;
V_40 -> V_149 = 0 ;
}
static inline bool F_164 ( const struct V_39 * V_40 )
{
return V_40 -> V_149 && ( ! V_40 -> V_150 || F_156 ( V_40 ) ) ;
}
static bool F_165 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_164 ( V_40 ) ) {
int V_143 ;
F_158 ( V_2 , F_8 ( V_2 ) -> V_146 == V_240 ? L_6 : L_7 ) ;
F_163 ( V_2 , false ) ;
if ( F_8 ( V_2 ) -> V_146 == V_240 )
V_143 = V_289 ;
else
V_143 = V_290 ;
F_82 ( F_4 ( V_2 ) , V_143 ) ;
}
if ( V_40 -> V_124 == V_40 -> V_193 && F_81 ( V_40 ) ) {
if ( ! F_157 ( V_2 ) )
V_40 -> V_276 = 0 ;
return true ;
}
F_142 ( V_2 , V_291 ) ;
return false ;
}
static bool F_166 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_149 && ! V_40 -> V_150 ) {
F_158 ( V_2 , L_8 ) ;
F_163 ( V_2 , false ) ;
F_82 ( F_4 ( V_2 ) , V_292 ) ;
return true ;
}
return false ;
}
static bool F_167 ( struct V_1 * V_2 , bool V_293 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_293 || F_164 ( V_40 ) ) {
F_163 ( V_2 , true ) ;
F_158 ( V_2 , L_9 ) ;
F_82 ( F_4 ( V_2 ) , V_289 ) ;
if ( V_293 )
F_82 ( F_4 ( V_2 ) ,
V_294 ) ;
F_8 ( V_2 ) -> V_251 = 0 ;
if ( V_293 || F_151 ( V_40 ) )
F_142 ( V_2 , V_291 ) ;
return true ;
}
return false ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
V_40 -> V_193 = V_40 -> V_126 ;
V_40 -> V_295 = 0 ;
V_40 -> V_255 = 0 ;
V_40 -> V_296 = V_40 -> V_68 ;
V_40 -> V_297 = 0 ;
V_40 -> V_298 = 0 ;
V_40 -> V_128 = F_8 ( V_2 ) -> V_58 -> V_253 ( V_2 ) ;
F_22 ( V_40 ) ;
}
void F_169 ( struct V_1 * V_2 , int V_299 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_300 = 0 ;
int V_109 = V_40 -> V_128 - F_130 ( V_40 ) ;
if ( V_299 <= 0 || F_79 ( ! V_40 -> V_296 ) )
return;
V_40 -> V_297 += V_299 ;
if ( V_109 < 0 ) {
T_3 V_301 = ( T_3 ) V_40 -> V_128 * V_40 -> V_297 +
V_40 -> V_296 - 1 ;
V_300 = F_170 ( V_301 , V_40 -> V_296 ) - V_40 -> V_298 ;
} else if ( ( V_194 & V_302 ) &&
! ( V_194 & V_303 ) ) {
V_300 = F_10 ( int , V_109 ,
F_34 ( int , V_40 -> V_297 - V_40 -> V_298 ,
V_299 ) + 1 ) ;
} else {
V_300 = F_17 ( V_109 , V_299 ) ;
}
V_300 = F_48 ( V_300 , ( V_40 -> V_298 ? 0 : 1 ) ) ;
V_40 -> V_68 = F_130 ( V_40 ) + V_300 ;
}
static inline void F_171 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_58 -> V_304 )
return;
if ( V_40 -> V_128 < V_305 &&
( F_8 ( V_2 ) -> V_146 == V_306 || V_40 -> V_149 ) ) {
V_40 -> V_68 = V_40 -> V_128 ;
V_40 -> V_94 = V_95 ;
}
F_28 ( V_2 , V_307 ) ;
}
void F_172 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
V_40 -> V_252 = 0 ;
if ( F_8 ( V_2 ) -> V_146 < V_306 ) {
V_40 -> V_149 = 0 ;
F_168 ( V_2 ) ;
F_142 ( V_2 , V_306 ) ;
}
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_187 = V_291 ;
if ( F_161 ( V_40 ) || F_157 ( V_2 ) )
V_187 = V_250 ;
if ( F_8 ( V_2 ) -> V_146 != V_187 ) {
F_142 ( V_2 , V_187 ) ;
V_40 -> V_193 = V_40 -> V_126 ;
}
}
static void F_174 ( struct V_1 * V_2 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_129 ( V_40 ) ;
if ( ! F_157 ( V_2 ) )
V_40 -> V_276 = 0 ;
if ( V_194 & V_308 )
F_172 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_146 != V_306 ) {
F_173 ( V_2 ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_261 . V_309 = V_13 -> V_261 . V_262 - 1 ;
V_13 -> V_261 . V_262 = 0 ;
F_82 ( F_4 ( V_2 ) , V_310 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_40 -> V_252 = F_139 ( V_2 ) ;
V_40 -> V_68 = V_40 -> V_68 *
F_177 ( V_2 , V_40 -> V_64 ) /
V_13 -> V_261 . V_262 ;
V_40 -> V_255 = 0 ;
V_40 -> V_94 = V_95 ;
V_40 -> V_128 = F_139 ( V_2 ) ;
V_13 -> V_261 . V_311 = V_13 -> V_261 . V_262 ;
V_13 -> V_261 . V_262 = 0 ;
F_178 ( V_2 , V_13 -> V_312 ) ;
F_82 ( F_4 ( V_2 ) , V_313 ) ;
}
void F_179 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_80 = F_180 ( V_2 ) ;
T_2 V_314 = V_40 -> V_163 ;
F_141 (skb, sk) {
if ( V_4 == F_118 ( V_2 ) )
break;
if ( F_107 ( V_4 ) > V_80 &&
! ( F_26 ( V_4 ) -> V_158 & V_162 ) ) {
if ( F_26 ( V_4 ) -> V_158 & V_160 ) {
F_26 ( V_4 ) -> V_158 &= ~ V_160 ;
V_40 -> V_192 -= F_85 ( V_4 ) ;
}
F_87 ( V_40 , V_4 ) ;
}
}
F_181 ( V_40 ) ;
if ( V_314 == V_40 -> V_163 )
return;
if ( F_81 ( V_40 ) )
F_131 ( V_40 ) ;
F_129 ( V_40 ) ;
if ( V_13 -> V_146 != V_240 ) {
V_40 -> V_193 = V_40 -> V_126 ;
V_40 -> V_128 = F_139 ( V_2 ) ;
V_40 -> V_252 = 0 ;
V_40 -> V_149 = 0 ;
F_142 ( V_2 , V_240 ) ;
}
F_182 ( V_2 ) ;
}
void F_183 ( struct V_1 * V_2 , bool V_315 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_143 ;
if ( F_81 ( V_40 ) )
V_143 = V_316 ;
else
V_143 = V_317 ;
F_82 ( F_4 ( V_2 ) , V_143 ) ;
V_40 -> V_252 = 0 ;
F_137 ( V_40 ) ;
if ( ! F_184 ( V_2 ) ) {
if ( ! V_315 )
V_40 -> V_252 = F_139 ( V_2 ) ;
F_168 ( V_2 ) ;
}
F_142 ( V_2 , V_247 ) ;
}
static void F_185 ( struct V_1 * V_2 , int V_194 , bool V_318 ,
int * V_319 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_320 = ! F_56 ( V_40 -> V_124 , V_40 -> V_193 ) ;
if ( ( V_194 & V_321 ) &&
F_167 ( V_2 , false ) )
return;
if ( ( V_194 & V_195 ) &&
F_167 ( V_2 , V_40 -> V_149 ) )
return;
if ( V_40 -> V_259 ) {
if ( F_65 ( V_40 -> V_126 , V_40 -> V_193 ) ) {
if ( V_194 & V_198 || V_318 )
V_40 -> V_259 = 0 ;
} else if ( V_194 & V_321 && ! V_320 ) {
V_40 -> V_193 = V_40 -> V_126 ;
if ( F_118 ( V_2 ) &&
F_65 ( F_186 ( V_40 ) , V_40 -> V_126 ) ) {
* V_319 = V_322 ;
return;
}
V_40 -> V_259 = 0 ;
}
}
if ( V_320 ) {
F_165 ( V_2 ) ;
return;
}
if ( F_81 ( V_40 ) ) {
if ( F_65 ( V_40 -> V_126 , V_40 -> V_193 ) && V_318 )
F_133 ( V_2 ) ;
else if ( V_194 & V_321 )
F_135 ( V_40 ) ;
}
* V_319 = V_323 ;
}
static bool F_187 ( struct V_1 * V_2 , const int V_244 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_149 && F_156 ( V_40 ) ) {
F_78 ( V_2 , F_147 ( V_40 ) + V_244 , 1 ) ;
if ( V_40 -> V_192 )
return true ;
if ( ! F_157 ( V_2 ) )
V_40 -> V_276 = 0 ;
F_158 ( V_2 , L_10 ) ;
F_163 ( V_2 , true ) ;
F_82 ( F_4 ( V_2 ) , V_324 ) ;
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
static void F_190 ( struct V_1 * V_2 , const int V_244 ,
bool V_318 , int * V_325 , int * V_319 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_272 = 0 , V_194 = * V_325 ;
bool V_329 = V_318 || ( ( V_194 & V_198 ) &&
( F_147 ( V_40 ) > V_40 -> V_69 ) ) ;
if ( F_126 ( ! V_40 -> V_131 && V_40 -> V_148 ) )
V_40 -> V_148 = 0 ;
if ( F_126 ( ! V_40 -> V_148 && V_40 -> V_147 ) )
V_40 -> V_147 = 0 ;
if ( V_194 & V_308 )
V_40 -> V_252 = 0 ;
if ( F_143 ( V_2 , V_194 ) )
return;
F_129 ( V_40 ) ;
if ( V_13 -> V_146 == V_291 ) {
F_126 ( V_40 -> V_192 != 0 ) ;
V_40 -> V_276 = 0 ;
} else if ( ! F_56 ( V_40 -> V_124 , V_40 -> V_193 ) ) {
switch ( V_13 -> V_146 ) {
case V_306 :
if ( V_40 -> V_124 != V_40 -> V_193 ) {
F_171 ( V_2 ) ;
F_142 ( V_2 , V_291 ) ;
}
break;
case V_247 :
if ( F_81 ( V_40 ) )
F_135 ( V_40 ) ;
if ( F_165 ( V_2 ) )
return;
F_171 ( V_2 ) ;
break;
}
}
switch ( V_13 -> V_146 ) {
case V_247 :
if ( ! ( V_194 & V_321 ) ) {
if ( F_81 ( V_40 ) && V_318 )
F_133 ( V_2 ) ;
} else {
if ( F_187 ( V_2 , V_244 ) )
return;
V_329 = F_81 ( V_40 ) ||
F_147 ( V_40 ) > V_40 -> V_69 ;
}
if ( F_166 ( V_2 ) ) {
F_173 ( V_2 ) ;
return;
}
F_188 ( V_2 , V_325 ) ;
break;
case V_240 :
F_185 ( V_2 , V_194 , V_318 , V_319 ) ;
F_188 ( V_2 , V_325 ) ;
if ( ! ( V_13 -> V_146 == V_291 ||
( * V_325 & V_303 ) ) )
return;
default:
if ( F_81 ( V_40 ) ) {
if ( V_194 & V_321 )
F_135 ( V_40 ) ;
if ( V_318 )
F_133 ( V_2 ) ;
}
if ( V_13 -> V_146 <= V_250 )
F_166 ( V_2 ) ;
F_188 ( V_2 , V_325 ) ;
if ( ! F_149 ( V_2 , V_194 ) ) {
F_174 ( V_2 , V_194 ) ;
return;
}
if ( V_13 -> V_146 < V_306 &&
V_13 -> V_261 . V_262 &&
V_40 -> V_124 == V_40 -> V_330 . V_331 ) {
F_175 ( V_2 ) ;
V_40 -> V_68 ++ ;
F_179 ( V_2 ) ;
return;
}
F_183 ( V_2 , ( V_194 & V_308 ) ) ;
V_272 = 1 ;
}
if ( V_329 )
F_152 ( V_2 , V_272 ) ;
* V_319 = V_323 ;
}
static void F_191 ( struct V_1 * V_2 , T_2 V_102 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_332 = V_333 * V_334 ;
F_192 ( & V_40 -> V_335 , V_332 , V_95 ,
V_102 ? : F_193 ( 1 ) ) ;
}
static bool F_194 ( struct V_1 * V_2 , const int V_194 ,
long V_336 , long V_337 ,
long V_338 , struct V_339 * V_340 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_336 < 0 )
V_336 = V_337 ;
if ( V_336 < 0 && V_40 -> V_62 . V_275 && V_40 -> V_62 . V_107 &&
V_194 & V_341 ) {
T_2 V_109 = F_59 ( V_40 ) - V_40 -> V_62 . V_107 ;
T_2 V_104 = V_109 * ( V_110 / V_111 ) ;
V_336 = V_338 = V_104 ;
}
V_340 -> V_102 = V_338 ;
if ( V_336 < 0 )
return false ;
F_191 ( V_2 , V_338 ) ;
F_64 ( V_2 , V_336 ) ;
F_71 ( V_2 ) ;
F_8 ( V_2 ) -> V_342 = 0 ;
return true ;
}
void F_195 ( struct V_1 * V_2 , struct V_343 * V_344 )
{
struct V_339 V_340 ;
long V_102 = - 1L ;
if ( V_344 && ! V_344 -> V_345 && F_196 ( V_344 ) -> V_346 )
V_102 = F_57 ( F_197 () , F_196 ( V_344 ) -> V_346 ) ;
F_194 ( V_2 , V_347 , V_102 , - 1L , V_102 , & V_340 ) ;
}
static void F_198 ( struct V_1 * V_2 , T_2 V_348 , T_2 V_244 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_58 -> V_349 ( V_2 , V_348 , V_244 ) ;
F_15 ( V_2 ) -> V_94 = V_95 ;
}
void F_199 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_350 )
return;
if ( ! V_40 -> V_131 ) {
F_200 ( V_2 , V_265 ) ;
} else {
T_2 V_351 = F_8 ( V_2 ) -> V_117 ;
if ( V_13 -> V_352 == V_353 ||
V_13 -> V_352 == V_354 ) {
T_7 V_104 = F_201 ( V_2 ) ;
V_351 = F_144 ( F_34 ( int , V_104 , 1 ) ) ;
}
F_146 ( V_2 , V_265 , V_351 ,
V_266 ) ;
}
}
static void F_202 ( struct V_1 * V_2 )
{
if ( ! F_203 ( V_2 ) )
F_199 ( V_2 ) ;
}
static T_2 F_204 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_355 ;
F_99 ( ! F_65 ( F_26 ( V_4 ) -> V_108 , V_40 -> V_124 ) ) ;
V_355 = F_85 ( V_4 ) ;
if ( F_205 ( V_2 , V_4 , V_40 -> V_124 - F_26 ( V_4 ) -> V_91 ) )
return 0 ;
V_355 -= F_85 ( V_4 ) ;
if ( V_355 ) {
F_99 ( F_85 ( V_4 ) == 0 ) ;
F_99 ( ! F_56 ( F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_108 ) ) ;
}
return V_355 ;
}
static void F_206 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_171 )
{
const struct V_66 * V_356 ;
if ( F_68 ( ! F_26 ( V_4 ) -> V_357 ) )
return;
V_356 = F_9 ( V_4 ) ;
if ( ! F_56 ( V_356 -> V_358 , V_171 ) &&
F_56 ( V_356 -> V_358 , F_15 ( V_2 ) -> V_124 ) )
F_207 ( V_4 , NULL , V_2 , V_359 ) ;
}
static int F_208 ( struct V_1 * V_2 , int V_360 ,
T_2 V_171 , int * V_244 ,
struct V_186 * V_361 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
T_3 V_362 , V_363 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_243 = V_40 -> V_148 ;
T_2 V_152 = V_40 -> V_131 ;
bool V_364 = true ;
long V_337 = - 1L ;
long V_336 = - 1L ;
long V_338 = - 1L ;
struct V_3 * V_4 ;
T_2 V_365 = 0 ;
T_2 V_366 = 0 ;
bool V_367 ;
int V_194 = 0 ;
V_362 = 0 ;
while ( ( V_4 = F_113 ( V_2 ) ) && V_4 != F_118 ( V_2 ) ) {
struct V_368 * V_369 = F_26 ( V_4 ) ;
T_6 V_158 = V_369 -> V_158 ;
T_2 V_370 ;
F_206 ( V_2 , V_4 , V_171 ) ;
if ( F_65 ( V_369 -> V_108 , V_40 -> V_124 ) ) {
if ( F_85 ( V_4 ) == 1 ||
! F_65 ( V_40 -> V_124 , V_369 -> V_91 ) )
break;
V_370 = F_204 ( V_2 , V_4 ) ;
if ( ! V_370 )
break;
V_364 = false ;
} else {
F_209 ( V_4 -> V_371 ) ;
V_370 = F_85 ( V_4 ) ;
}
if ( F_11 ( V_158 & V_191 ) ) {
if ( V_158 & V_160 )
V_40 -> V_192 -= V_370 ;
V_194 |= V_302 ;
} else if ( ! ( V_158 & V_162 ) ) {
V_363 = V_4 -> V_203 ;
F_79 ( V_363 == 0 ) ;
if ( ! V_362 )
V_362 = V_363 ;
V_366 = F_26 ( V_4 ) -> V_210 . V_372 ;
V_152 = F_17 ( V_365 , V_152 ) ;
if ( ! F_65 ( V_369 -> V_108 , V_40 -> V_193 ) )
V_194 |= V_195 ;
}
if ( V_158 & V_162 ) {
V_40 -> V_148 -= V_370 ;
} else if ( F_151 ( V_40 ) ) {
V_40 -> V_199 += V_370 ;
if ( ! F_154 ( V_40 , V_4 ) )
F_95 ( V_40 , V_158 , V_369 -> V_108 ,
V_4 -> V_203 ) ;
}
if ( V_158 & V_159 )
V_40 -> V_163 -= V_370 ;
V_40 -> V_131 -= V_370 ;
V_365 += V_370 ;
F_100 ( V_2 , V_4 , V_361 -> V_127 ) ;
if ( F_68 ( ! ( V_369 -> V_207 & V_373 ) ) ) {
V_194 |= V_374 ;
} else {
V_194 |= V_347 ;
V_40 -> V_276 = 0 ;
}
if ( ! V_364 )
break;
F_105 ( V_4 , V_2 ) ;
F_106 ( V_2 , V_4 ) ;
if ( F_11 ( V_4 == V_40 -> V_157 ) )
V_40 -> V_157 = NULL ;
if ( F_11 ( V_4 == V_40 -> V_137 ) )
V_40 -> V_137 = NULL ;
}
if ( ! V_4 )
F_210 ( V_2 , V_375 ) ;
if ( F_68 ( F_211 ( V_40 -> V_376 , V_171 , V_40 -> V_124 ) ) )
V_40 -> V_376 = V_40 -> V_124 ;
if ( V_4 && ( F_26 ( V_4 ) -> V_158 & V_162 ) )
V_194 |= V_263 ;
if ( F_68 ( V_362 ) && ! ( V_194 & V_302 ) ) {
V_336 = F_57 ( V_40 -> V_90 , V_362 ) ;
V_338 = F_57 ( V_40 -> V_90 , V_363 ) ;
}
if ( V_361 -> V_196 ) {
V_337 = F_57 ( V_40 -> V_90 , V_361 -> V_196 ) ;
V_338 = F_57 ( V_40 -> V_90 , V_361 -> V_197 ) ;
}
V_367 = F_194 ( V_2 , V_194 , V_336 , V_337 ,
V_338 , V_361 -> V_127 ) ;
if ( V_194 & V_341 ) {
V_194 |= V_377 ;
if ( F_11 ( V_13 -> V_261 . V_262 &&
! F_65 ( V_40 -> V_330 . V_378 , V_40 -> V_124 ) ) ) {
F_176 ( V_2 ) ;
}
if ( F_81 ( V_40 ) ) {
F_134 ( V_2 , V_365 ) ;
} else {
int V_109 ;
if ( V_152 < V_360 && V_152 <= V_40 -> V_147 )
F_78 ( V_2 , V_40 -> V_147 - V_152 , 0 ) ;
V_109 = F_76 ( V_40 ) ? V_365 :
V_243 - V_40 -> V_148 ;
V_40 -> V_200 -= F_17 ( V_40 -> V_200 , V_109 ) ;
}
V_40 -> V_147 -= F_17 ( V_365 , V_40 -> V_147 ) ;
} else if ( V_4 && V_367 && V_337 >= 0 &&
V_337 > F_57 ( V_40 -> V_90 , V_4 -> V_203 ) ) {
V_194 |= V_377 ;
}
if ( V_13 -> V_58 -> V_365 ) {
struct V_379 V_98 = { . V_365 = V_365 ,
. V_102 = V_361 -> V_127 -> V_102 ,
. V_372 = V_366 } ;
V_13 -> V_58 -> V_365 ( V_2 , & V_98 ) ;
}
#if V_145 > 0
F_126 ( ( int ) V_40 -> V_148 < 0 ) ;
F_126 ( ( int ) V_40 -> V_163 < 0 ) ;
F_126 ( ( int ) V_40 -> V_192 < 0 ) ;
if ( ! V_40 -> V_131 && F_151 ( V_40 ) ) {
V_13 = F_8 ( V_2 ) ;
if ( V_40 -> V_163 ) {
F_80 ( L_11 ,
V_40 -> V_163 , V_13 -> V_146 ) ;
V_40 -> V_163 = 0 ;
}
if ( V_40 -> V_148 ) {
F_80 ( L_12 ,
V_40 -> V_148 , V_13 -> V_146 ) ;
V_40 -> V_148 = 0 ;
}
if ( V_40 -> V_192 ) {
F_80 ( L_13 ,
V_40 -> V_192 , V_13 -> V_146 ) ;
V_40 -> V_192 = 0 ;
}
}
#endif
* V_244 = V_365 ;
return V_194 ;
}
static void F_212 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( ! F_65 ( F_26 ( F_118 ( V_2 ) ) -> V_108 , F_186 ( V_40 ) ) ) {
V_13 -> V_342 = 0 ;
F_200 ( V_2 , V_380 ) ;
} else {
unsigned long V_274 = F_213 ( V_2 , V_266 ) ;
F_146 ( V_2 , V_380 ,
V_274 , V_266 ) ;
}
}
static inline bool F_214 ( const struct V_1 * V_2 , const int V_194 )
{
return ! ( V_194 & V_381 ) || ( V_194 & V_382 ) ||
F_8 ( V_2 ) -> V_146 != V_291 ;
}
static inline bool F_215 ( const struct V_1 * V_2 , const int V_194 )
{
if ( F_15 ( V_2 ) -> V_69 > F_4 ( V_2 ) -> V_257 . V_258 )
return V_194 & V_383 ;
return V_194 & V_374 ;
}
static void F_216 ( struct V_1 * V_2 , T_2 V_348 , T_2 V_384 ,
int V_194 , const struct V_339 * V_340 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( V_13 -> V_58 -> V_304 ) {
V_13 -> V_58 -> V_304 ( V_2 , V_340 ) ;
return;
}
if ( F_184 ( V_2 ) ) {
F_169 ( V_2 , V_384 , V_194 ) ;
} else if ( F_215 ( V_2 , V_194 ) ) {
F_198 ( V_2 , V_348 , V_384 ) ;
}
F_67 ( V_2 ) ;
}
static inline bool F_217 ( const struct V_39 * V_40 ,
const T_2 V_348 , const T_2 V_175 ,
const T_2 V_385 )
{
return F_65 ( V_348 , V_40 -> V_124 ) ||
F_65 ( V_175 , V_40 -> V_386 ) ||
( V_175 == V_40 -> V_386 && V_385 > V_40 -> V_387 ) ;
}
static void F_218 ( struct V_39 * V_40 , T_2 V_348 )
{
T_2 V_109 = V_348 - V_40 -> V_124 ;
F_219 ( (struct V_1 * ) V_40 ) ;
V_40 -> V_388 += V_109 ;
V_40 -> V_124 = V_348 ;
}
static void F_220 ( struct V_39 * V_40 , T_2 V_91 )
{
T_2 V_109 = V_91 - V_40 -> V_106 ;
F_219 ( (struct V_1 * ) V_40 ) ;
V_40 -> V_389 += V_109 ;
V_40 -> V_106 = V_91 ;
}
static int F_221 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_2 V_348 ,
T_2 V_175 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_194 = 0 ;
T_2 V_385 = F_160 ( F_14 ( V_4 ) -> V_74 ) ;
if ( F_68 ( ! F_14 ( V_4 ) -> V_55 ) )
V_385 <<= V_40 -> V_62 . V_390 ;
if ( F_217 ( V_40 , V_348 , V_175 , V_385 ) ) {
V_194 |= V_391 ;
F_222 ( V_40 , V_175 ) ;
if ( V_40 -> V_387 != V_385 ) {
V_40 -> V_387 = V_385 ;
V_40 -> V_392 = 0 ;
F_223 ( V_2 ) ;
if ( F_118 ( V_2 ) )
F_224 ( V_2 ) ;
if ( V_385 > V_40 -> V_166 ) {
V_40 -> V_166 = V_385 ;
F_178 ( V_2 , F_8 ( V_2 ) -> V_312 ) ;
}
}
}
F_218 ( V_40 , V_348 ) ;
return V_194 ;
}
static bool F_225 ( struct V_245 * V_245 , int V_143 ,
T_2 * V_393 )
{
if ( * V_393 ) {
T_8 V_394 = ( T_8 ) ( V_95 - * V_393 ) ;
if ( 0 <= V_394 && V_394 < V_395 ) {
F_82 ( V_245 , V_143 ) ;
return true ;
}
}
* V_393 = V_95 ;
return false ;
}
bool F_226 ( struct V_245 * V_245 , const struct V_3 * V_4 ,
int V_143 , T_2 * V_393 )
{
if ( ( F_26 ( V_4 ) -> V_91 != F_26 ( V_4 ) -> V_108 ) &&
! F_14 ( V_4 ) -> V_55 )
return false ;
return F_225 ( V_245 , V_143 , V_393 ) ;
}
static void F_227 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_2 V_396 ;
static unsigned int V_397 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_398 , V_115 ;
if ( F_225 ( F_4 ( V_2 ) ,
V_399 ,
& V_40 -> V_393 ) )
return;
V_115 = V_400 / V_334 ;
if ( V_115 != V_396 ) {
T_2 V_401 = ( V_402 + 1 ) >> 1 ;
V_396 = V_115 ;
F_228 ( V_397 , V_401 +
F_229 ( V_402 ) ) ;
}
V_398 = F_230 ( V_397 ) ;
if ( V_398 > 0 ) {
F_228 ( V_397 , V_398 - 1 ) ;
F_82 ( F_4 ( V_2 ) , V_403 ) ;
F_231 ( V_2 ) ;
}
}
static void F_232 ( struct V_39 * V_40 )
{
V_40 -> V_62 . V_404 = V_40 -> V_62 . V_405 ;
V_40 -> V_62 . V_406 = F_233 () ;
}
static void F_234 ( struct V_39 * V_40 , T_2 V_91 )
{
if ( V_40 -> V_62 . V_275 && ! F_65 ( V_91 , V_40 -> V_407 ) ) {
if ( F_235 ( & V_40 -> V_62 , 0 ) )
F_232 ( V_40 ) ;
}
}
static void F_236 ( struct V_1 * V_2 , T_2 V_348 , int V_194 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_56 ( V_348 , V_40 -> V_295 ) )
return;
if ( V_194 & V_234 ) {
V_40 -> V_295 = 0 ;
} else if ( F_65 ( V_348 , V_40 -> V_295 ) ) {
F_168 ( V_2 ) ;
F_142 ( V_2 , V_306 ) ;
F_171 ( V_2 ) ;
F_173 ( V_2 ) ;
F_82 ( F_4 ( V_2 ) ,
V_408 ) ;
} else if ( ! ( V_194 & ( V_321 |
V_381 | V_198 ) ) ) {
V_40 -> V_295 = 0 ;
}
}
static inline void F_237 ( struct V_1 * V_2 , T_2 V_409 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( V_13 -> V_58 -> V_410 )
V_13 -> V_58 -> V_410 ( V_2 , V_409 ) ;
}
static void F_238 ( struct V_1 * V_2 , int V_319 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_319 == V_411 )
return;
if ( F_11 ( V_319 == 2 ) ) {
F_239 ( V_2 , F_180 ( V_2 ) ,
V_412 ) ;
if ( F_65 ( V_40 -> V_126 , V_40 -> V_193 ) )
return;
V_40 -> V_259 = 0 ;
}
F_182 ( V_2 ) ;
}
static int F_240 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_194 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_186 V_413 ;
struct V_339 V_340 = { . V_414 = 0 } ;
T_2 V_171 = V_40 -> V_124 ;
T_2 V_175 = F_26 ( V_4 ) -> V_91 ;
T_2 V_348 = F_26 ( V_4 ) -> V_175 ;
bool V_318 = false ;
T_2 V_360 ;
int V_415 = V_40 -> V_131 ;
T_2 V_199 = V_40 -> V_199 ;
T_2 V_161 = V_40 -> V_161 ;
int V_244 = 0 ;
int V_319 = V_411 ;
V_413 . V_196 = 0 ;
V_413 . V_127 = & V_340 ;
F_209 ( V_2 -> V_416 . V_371 ) ;
if ( F_56 ( V_348 , V_171 ) ) {
if ( F_56 ( V_348 , V_171 - V_40 -> V_166 ) ) {
if ( ! ( V_194 & V_417 ) )
F_227 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_418;
}
if ( F_65 ( V_348 , V_40 -> V_126 ) )
goto V_419;
if ( F_65 ( V_348 , V_171 ) ) {
V_194 |= V_321 ;
V_13 -> V_251 = 0 ;
}
V_360 = V_40 -> V_147 ;
V_340 . V_420 = F_130 ( V_40 ) ;
if ( V_194 & V_421 )
F_234 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! ( V_194 & V_422 ) && F_65 ( V_348 , V_171 ) ) {
F_222 ( V_40 , V_175 ) ;
F_218 ( V_40 , V_348 ) ;
V_194 |= V_391 ;
F_237 ( V_2 , V_423 ) ;
F_82 ( F_4 ( V_2 ) , V_424 ) ;
} else {
T_2 V_425 = V_426 ;
if ( V_175 != F_26 ( V_4 ) -> V_108 )
V_194 |= V_427 ;
else
F_82 ( F_4 ( V_2 ) , V_428 ) ;
V_194 |= F_221 ( V_2 , V_4 , V_348 , V_175 ) ;
if ( F_26 ( V_4 ) -> V_158 )
V_194 |= F_125 ( V_2 , V_4 , V_171 ,
& V_413 ) ;
if ( F_32 ( V_40 , F_14 ( V_4 ) ) ) {
V_194 |= V_308 ;
V_425 |= V_429 ;
}
if ( V_194 & V_391 )
V_425 |= V_423 ;
F_237 ( V_2 , V_425 ) ;
}
V_2 -> V_430 = 0 ;
V_13 -> V_431 = 0 ;
V_40 -> V_432 = V_95 ;
if ( ! V_415 )
goto V_433;
V_194 |= F_208 ( V_2 , V_360 , V_171 , & V_244 ,
& V_413 ) ;
if ( V_40 -> V_295 )
F_236 ( V_2 , V_348 , V_194 ) ;
if ( V_194 & V_377 )
F_202 ( V_2 ) ;
if ( F_214 ( V_2 , V_194 ) ) {
V_318 = ! ( V_194 & ( V_321 | V_381 ) ) ;
F_190 ( V_2 , V_244 , V_318 , & V_194 , & V_319 ) ;
}
if ( ( V_194 & V_383 ) || ! ( V_194 & V_381 ) )
F_241 ( V_2 ) ;
V_199 = V_40 -> V_199 - V_199 ;
V_161 = V_40 -> V_161 - V_161 ;
F_242 ( V_2 , V_199 , V_161 , V_413 . V_127 ) ;
F_216 ( V_2 , V_348 , V_199 , V_194 , V_413 . V_127 ) ;
F_238 ( V_2 , V_319 ) ;
return 1 ;
V_433:
if ( V_194 & V_234 )
F_190 ( V_2 , V_244 , V_318 , & V_194 , & V_319 ) ;
if ( F_118 ( V_2 ) )
F_212 ( V_2 ) ;
if ( V_40 -> V_295 )
F_236 ( V_2 , V_348 , V_194 ) ;
return 1 ;
V_419:
F_243 ( V_2 , L_14 , V_348 , V_40 -> V_124 , V_40 -> V_126 ) ;
return - 1 ;
V_418:
if ( F_26 ( V_4 ) -> V_158 ) {
V_194 |= F_125 ( V_2 , V_4 , V_171 ,
& V_413 ) ;
F_190 ( V_2 , V_244 , V_318 , & V_194 , & V_319 ) ;
F_238 ( V_2 , V_319 ) ;
}
F_243 ( V_2 , L_15 , V_348 , V_40 -> V_124 , V_40 -> V_126 ) ;
return 0 ;
}
static void F_244 ( int V_5 , const unsigned char * V_434 ,
bool V_55 , struct V_435 * V_436 ,
bool V_437 )
{
if ( ! V_436 || ! V_55 || V_5 < 0 || ( V_5 & 1 ) )
return;
if ( V_5 >= V_438 &&
V_5 <= V_439 )
memcpy ( V_436 -> V_440 , V_434 , V_5 ) ;
else if ( V_5 != 0 )
V_5 = - 1 ;
V_436 -> V_5 = V_5 ;
V_436 -> exp = V_437 ;
}
void F_245 ( const struct V_245 * V_245 ,
const struct V_3 * V_4 ,
struct V_441 * V_442 , int V_443 ,
struct V_435 * V_436 )
{
const unsigned char * V_225 ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
int V_444 = ( V_53 -> V_445 * 4 ) - sizeof( struct V_22 ) ;
V_225 = ( const unsigned char * ) ( V_53 + 1 ) ;
V_442 -> V_275 = 0 ;
while ( V_444 > 0 ) {
int V_446 = * V_225 ++ ;
int V_447 ;
switch ( V_446 ) {
case V_448 :
return;
case V_449 :
V_444 -- ;
continue;
default:
V_447 = * V_225 ++ ;
if ( V_447 < 2 )
return;
if ( V_447 > V_444 )
return;
switch ( V_446 ) {
case V_450 :
if ( V_447 == V_451 && V_53 -> V_55 && ! V_443 ) {
T_9 V_452 = F_246 ( V_225 ) ;
if ( V_452 ) {
if ( V_442 -> V_453 &&
V_442 -> V_453 < V_452 )
V_452 = V_442 -> V_453 ;
V_442 -> V_63 = V_452 ;
}
}
break;
case V_454 :
if ( V_447 == V_455 && V_53 -> V_55 &&
! V_443 && V_245 -> V_257 . V_456 ) {
T_5 V_390 = * ( T_5 * ) V_225 ;
V_442 -> V_457 = 1 ;
if ( V_390 > V_458 ) {
F_247 ( L_16 ,
V_459 ,
V_390 ,
V_458 ) ;
V_390 = V_458 ;
}
V_442 -> V_390 = V_390 ;
}
break;
case V_460 :
if ( ( V_447 == V_461 ) &&
( ( V_443 && V_442 -> V_462 ) ||
( ! V_443 && V_245 -> V_257 . V_463 ) ) ) {
V_442 -> V_275 = 1 ;
V_442 -> V_405 = F_90 ( V_225 ) ;
V_442 -> V_107 = F_90 ( V_225 + 4 ) ;
}
break;
case V_464 :
if ( V_447 == V_465 && V_53 -> V_55 &&
! V_443 && V_245 -> V_257 . V_466 ) {
V_442 -> V_138 = V_467 ;
F_248 ( V_442 ) ;
}
break;
case V_468 :
if ( ( V_447 >= ( V_228 + V_469 ) ) &&
! ( ( V_447 - V_228 ) % V_469 ) &&
V_442 -> V_138 ) {
F_26 ( V_4 ) -> V_158 = ( V_225 - 2 ) - ( unsigned char * ) V_53 ;
}
break;
#ifdef F_249
case V_470 :
break;
#endif
case V_471 :
F_244 (
V_447 - V_472 ,
V_225 , V_53 -> V_55 , V_436 , false ) ;
break;
case V_473 :
if ( V_447 >= V_474 &&
F_246 ( V_225 ) ==
V_475 )
F_244 ( V_447 -
V_474 ,
V_225 + 2 , V_53 -> V_55 , V_436 , true ) ;
break;
}
V_225 += V_447 - 2 ;
V_444 -= V_447 ;
}
}
}
static bool F_250 ( struct V_39 * V_40 , const struct V_22 * V_53 )
{
const T_10 * V_225 = ( const T_10 * ) ( V_53 + 1 ) ;
if ( * V_225 == F_251 ( ( V_449 << 24 ) | ( V_449 << 16 )
| ( V_460 << 8 ) | V_461 ) ) {
V_40 -> V_62 . V_275 = 1 ;
++ V_225 ;
V_40 -> V_62 . V_405 = F_252 ( * V_225 ) ;
++ V_225 ;
if ( * V_225 )
V_40 -> V_62 . V_107 = F_252 ( * V_225 ) - V_40 -> V_476 ;
else
V_40 -> V_62 . V_107 = 0 ;
return true ;
}
return false ;
}
static bool F_253 ( const struct V_245 * V_245 ,
const struct V_3 * V_4 ,
const struct V_22 * V_53 , struct V_39 * V_40 )
{
if ( V_53 -> V_445 == ( sizeof( * V_53 ) / 4 ) ) {
V_40 -> V_62 . V_275 = 0 ;
return false ;
} else if ( V_40 -> V_62 . V_462 &&
V_53 -> V_445 == ( ( sizeof( * V_53 ) + V_477 ) / 4 ) ) {
if ( F_250 ( V_40 , V_53 ) )
return true ;
}
F_245 ( V_245 , V_4 , & V_40 -> V_62 , 1 , NULL ) ;
if ( V_40 -> V_62 . V_275 && V_40 -> V_62 . V_107 )
V_40 -> V_62 . V_107 -= V_40 -> V_476 ;
return true ;
}
const T_6 * F_254 ( const struct V_22 * V_53 )
{
int V_444 = ( V_53 -> V_445 << 2 ) - sizeof( * V_53 ) ;
const T_6 * V_225 = ( const T_6 * ) ( V_53 + 1 ) ;
if ( V_444 < V_478 )
return NULL ;
while ( V_444 > 0 ) {
int V_446 = * V_225 ++ ;
int V_447 ;
switch ( V_446 ) {
case V_448 :
return NULL ;
case V_449 :
V_444 -- ;
continue;
default:
V_447 = * V_225 ++ ;
if ( V_447 < 2 || V_447 > V_444 )
return NULL ;
if ( V_446 == V_470 )
return V_447 == V_478 ? V_225 : NULL ;
}
V_225 += V_447 - 2 ;
V_444 -= V_447 ;
}
return NULL ;
}
static int F_255 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
T_2 V_91 = F_26 ( V_4 ) -> V_91 ;
T_2 V_348 = F_26 ( V_4 ) -> V_175 ;
return (
( V_53 -> V_348 && V_91 == F_26 ( V_4 ) -> V_108 && V_91 == V_40 -> V_106 ) &&
V_348 == V_40 -> V_124 &&
! F_217 ( V_40 , V_348 , V_91 , F_160 ( V_53 -> V_74 ) << V_40 -> V_62 . V_390 ) &&
( T_8 ) ( V_40 -> V_62 . V_404 - V_40 -> V_62 . V_405 ) <= ( F_8 ( V_2 ) -> V_117 * 1024 ) / V_334 ) ;
}
static inline bool F_256 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
return ! F_235 ( & V_40 -> V_62 , V_479 ) &&
! F_255 ( V_2 , V_4 ) ;
}
static inline bool F_257 ( const struct V_39 * V_40 , T_2 V_91 , T_2 V_108 )
{
return ! F_56 ( V_108 , V_40 -> V_407 ) &&
! F_65 ( V_91 , V_40 -> V_106 + F_258 ( V_40 ) ) ;
}
void F_259 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_480 ) {
case V_481 :
V_2 -> V_482 = V_483 ;
break;
case V_484 :
V_2 -> V_482 = V_485 ;
break;
case V_486 :
return;
default:
V_2 -> V_482 = V_487 ;
}
F_260 () ;
F_261 ( V_2 ) ;
if ( ! F_262 ( V_2 , V_488 ) )
V_2 -> V_489 ( V_2 ) ;
}
void F_263 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_62 ( V_2 ) ;
V_2 -> V_490 |= V_491 ;
F_264 ( V_2 , V_492 ) ;
switch ( V_2 -> V_480 ) {
case V_493 :
case V_494 :
F_265 ( V_2 , V_484 ) ;
F_8 ( V_2 ) -> V_15 . V_33 = 1 ;
break;
case V_484 :
case V_495 :
break;
case V_496 :
break;
case V_497 :
F_231 ( V_2 ) ;
F_265 ( V_2 , V_495 ) ;
break;
case V_498 :
F_231 ( V_2 ) ;
F_266 ( V_2 , V_499 , 0 ) ;
break;
default:
F_267 ( L_17 ,
V_459 , V_2 -> V_480 ) ;
break;
}
F_268 ( & V_40 -> V_500 ) ;
if ( F_151 ( V_40 ) )
F_248 ( & V_40 -> V_62 ) ;
F_63 ( V_2 ) ;
if ( ! F_262 ( V_2 , V_488 ) ) {
V_2 -> V_501 ( V_2 ) ;
if ( V_2 -> V_490 == V_502 ||
V_2 -> V_480 == V_486 )
F_269 ( V_2 , V_503 , V_504 ) ;
else
F_269 ( V_2 , V_503 , V_505 ) ;
}
}
static inline bool F_270 ( struct V_218 * V_169 , T_2 V_91 ,
T_2 V_108 )
{
if ( ! F_65 ( V_91 , V_169 -> V_108 ) && ! F_65 ( V_169 -> V_165 , V_108 ) ) {
if ( F_56 ( V_91 , V_169 -> V_165 ) )
V_169 -> V_165 = V_91 ;
if ( F_65 ( V_108 , V_169 -> V_108 ) )
V_169 -> V_108 = V_108 ;
return true ;
}
return false ;
}
static void F_271 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_108 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_151 ( V_40 ) && V_506 ) {
int V_143 ;
if ( F_56 ( V_91 , V_40 -> V_106 ) )
V_143 = V_507 ;
else
V_143 = V_508 ;
F_82 ( F_4 ( V_2 ) , V_143 ) ;
V_40 -> V_62 . V_509 = 1 ;
V_40 -> V_510 [ 0 ] . V_165 = V_91 ;
V_40 -> V_510 [ 0 ] . V_108 = V_108 ;
}
}
static void F_272 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_108 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( ! V_40 -> V_62 . V_509 )
F_271 ( V_2 , V_91 , V_108 ) ;
else
F_270 ( V_40 -> V_510 , V_91 , V_108 ) ;
}
static void F_273 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_26 ( V_4 ) -> V_108 != F_26 ( V_4 ) -> V_91 &&
F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_106 ) ) {
F_82 ( F_4 ( V_2 ) , V_511 ) ;
F_18 ( V_2 ) ;
if ( F_151 ( V_40 ) && V_506 ) {
T_2 V_108 = F_26 ( V_4 ) -> V_108 ;
if ( F_65 ( F_26 ( V_4 ) -> V_108 , V_40 -> V_106 ) )
V_108 = V_40 -> V_106 ;
F_271 ( V_2 , F_26 ( V_4 ) -> V_91 , V_108 ) ;
}
}
F_231 ( V_2 ) ;
}
static void F_274 ( struct V_39 * V_40 )
{
int V_512 ;
struct V_218 * V_169 = & V_40 -> V_513 [ 0 ] ;
struct V_218 * V_514 = V_169 + 1 ;
for ( V_512 = 1 ; V_512 < V_40 -> V_62 . V_170 ; ) {
if ( F_270 ( V_169 , V_514 -> V_165 , V_514 -> V_108 ) ) {
int V_231 ;
V_40 -> V_62 . V_170 -- ;
for ( V_231 = V_512 ; V_231 < V_40 -> V_62 . V_170 ; V_231 ++ )
V_169 [ V_231 ] = V_169 [ V_231 + 1 ] ;
continue;
}
V_512 ++ , V_514 ++ ;
}
}
static void F_275 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_108 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_218 * V_169 = & V_40 -> V_513 [ 0 ] ;
int V_515 = V_40 -> V_62 . V_170 ;
int V_512 ;
if ( ! V_515 )
goto V_516;
for ( V_512 = 0 ; V_512 < V_515 ; V_512 ++ , V_169 ++ ) {
if ( F_270 ( V_169 , V_91 , V_108 ) ) {
for (; V_512 > 0 ; V_512 -- , V_169 -- )
F_128 ( * V_169 , * ( V_169 - 1 ) ) ;
if ( V_515 > 1 )
F_274 ( V_40 ) ;
return;
}
}
if ( V_512 >= V_227 ) {
V_512 -- ;
V_40 -> V_62 . V_170 -- ;
V_169 -- ;
}
for (; V_512 > 0 ; V_512 -- , V_169 -- )
* V_169 = * ( V_169 - 1 ) ;
V_516:
V_169 -> V_165 = V_91 ;
V_169 -> V_108 = V_108 ;
V_40 -> V_62 . V_170 ++ ;
}
static void F_276 ( struct V_39 * V_40 )
{
struct V_218 * V_169 = & V_40 -> V_513 [ 0 ] ;
int V_170 = V_40 -> V_62 . V_170 ;
int V_512 ;
if ( F_277 ( & V_40 -> V_500 ) ) {
V_40 -> V_62 . V_170 = 0 ;
return;
}
for ( V_512 = 0 ; V_512 < V_170 ; ) {
if ( ! F_56 ( V_40 -> V_106 , V_169 -> V_165 ) ) {
int V_231 ;
F_126 ( F_56 ( V_40 -> V_106 , V_169 -> V_108 ) ) ;
for ( V_231 = V_512 + 1 ; V_231 < V_170 ; V_231 ++ )
V_40 -> V_513 [ V_231 - 1 ] = V_40 -> V_513 [ V_231 ] ;
V_170 -- ;
continue;
}
V_512 ++ ;
V_169 ++ ;
}
V_40 -> V_62 . V_170 = V_170 ;
}
static bool F_278 ( struct V_1 * V_2 ,
struct V_3 * V_517 ,
struct V_3 * V_518 ,
bool * V_519 )
{
int V_109 ;
* V_519 = false ;
if ( F_26 ( V_518 ) -> V_91 != F_26 ( V_517 ) -> V_108 )
return false ;
if ( ! F_279 ( V_517 , V_518 , V_519 , & V_109 ) )
return false ;
F_280 ( V_109 , & V_2 -> V_96 ) ;
F_281 ( V_2 , V_109 ) ;
F_82 ( F_4 ( V_2 ) , V_520 ) ;
F_26 ( V_517 ) -> V_108 = F_26 ( V_518 ) -> V_108 ;
F_26 ( V_517 ) -> V_175 = F_26 ( V_518 ) -> V_175 ;
F_26 ( V_517 ) -> V_207 |= F_26 ( V_518 ) -> V_207 ;
return true ;
}
static void F_282 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_283 ( V_2 , V_4 ) ;
F_284 ( V_4 ) ;
}
static void F_285 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_4 V_521 = V_40 -> V_106 ;
bool V_522 , V_519 , V_523 ;
struct V_3 * V_4 , * V_524 ;
struct V_525 * V_526 ;
V_526 = F_286 ( & V_40 -> V_500 ) ;
while ( V_526 ) {
V_4 = F_287 ( V_526 , struct V_3 , V_527 ) ;
if ( F_65 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_106 ) )
break;
if ( F_56 ( F_26 ( V_4 ) -> V_91 , V_521 ) ) {
T_4 V_509 = V_521 ;
if ( F_56 ( F_26 ( V_4 ) -> V_108 , V_521 ) )
V_521 = F_26 ( V_4 ) -> V_108 ;
F_272 ( V_2 , F_26 ( V_4 ) -> V_91 , V_509 ) ;
}
V_526 = F_288 ( V_526 ) ;
F_289 ( & V_4 -> V_527 , & V_40 -> V_500 ) ;
if ( F_11 ( ! F_65 ( F_26 ( V_4 ) -> V_108 , V_40 -> V_106 ) ) ) {
F_243 ( V_2 , L_18 ) ;
F_282 ( V_2 , V_4 ) ;
continue;
}
F_243 ( V_2 , L_19 ,
V_40 -> V_106 , F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_108 ) ;
V_524 = F_290 ( & V_2 -> V_528 ) ;
V_523 = V_524 && F_278 ( V_2 , V_524 , V_4 , & V_519 ) ;
F_220 ( V_40 , F_26 ( V_4 ) -> V_108 ) ;
V_522 = F_26 ( V_4 ) -> V_207 & V_209 ;
if ( ! V_523 )
F_291 ( & V_2 -> V_528 , V_4 ) ;
else
F_292 ( V_4 , V_519 ) ;
if ( F_11 ( V_522 ) ) {
F_263 ( V_2 ) ;
break;
}
}
}
static int F_293 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_529 )
{
if ( F_52 ( & V_2 -> V_96 ) > V_2 -> V_83 ||
! F_294 ( V_2 , V_4 , V_529 ) ) {
if ( F_295 ( V_2 ) < 0 )
return - 1 ;
while ( ! F_294 ( V_2 , V_4 , V_529 ) ) {
if ( ! F_296 ( V_2 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_297 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_525 * * V_526 , * V_530 , * V_531 ;
struct V_3 * V_532 ;
T_2 V_91 , V_108 ;
bool V_519 ;
F_29 ( V_40 , V_4 ) ;
if ( F_11 ( F_293 ( V_2 , V_4 , V_4 -> V_73 ) ) ) {
F_82 ( F_4 ( V_2 ) , V_533 ) ;
F_282 ( V_2 , V_4 ) ;
return;
}
V_40 -> V_392 = 0 ;
F_62 ( V_2 ) ;
F_82 ( F_4 ( V_2 ) , V_534 ) ;
V_91 = F_26 ( V_4 ) -> V_91 ;
V_108 = F_26 ( V_4 ) -> V_108 ;
F_243 ( V_2 , L_20 ,
V_40 -> V_106 , V_91 , V_108 ) ;
V_526 = & V_40 -> V_500 . V_525 ;
if ( F_277 ( & V_40 -> V_500 ) ) {
if ( F_151 ( V_40 ) ) {
V_40 -> V_62 . V_170 = 1 ;
V_40 -> V_513 [ 0 ] . V_165 = V_91 ;
V_40 -> V_513 [ 0 ] . V_108 = V_108 ;
}
F_298 ( & V_4 -> V_527 , NULL , V_526 ) ;
F_299 ( & V_4 -> V_527 , & V_40 -> V_500 ) ;
V_40 -> V_535 = V_4 ;
goto V_536;
}
if ( F_278 ( V_2 , V_40 -> V_535 , V_4 , & V_519 ) ) {
V_537:
F_39 ( V_2 , V_4 ) ;
F_292 ( V_4 , V_519 ) ;
V_4 = NULL ;
goto V_538;
}
if ( ! F_56 ( V_91 , F_26 ( V_40 -> V_535 ) -> V_108 ) ) {
V_531 = & V_40 -> V_535 -> V_527 ;
V_526 = & V_531 -> V_539 ;
goto V_540;
}
V_531 = NULL ;
while ( * V_526 ) {
V_531 = * V_526 ;
V_532 = F_287 ( V_531 , struct V_3 , V_527 ) ;
if ( F_56 ( V_91 , F_26 ( V_532 ) -> V_91 ) ) {
V_526 = & V_531 -> V_541 ;
continue;
}
if ( F_56 ( V_91 , F_26 ( V_532 ) -> V_108 ) ) {
if ( ! F_65 ( V_108 , F_26 ( V_532 ) -> V_108 ) ) {
F_82 ( F_4 ( V_2 ) ,
V_542 ) ;
F_284 ( V_4 ) ;
V_4 = NULL ;
F_271 ( V_2 , V_91 , V_108 ) ;
goto V_538;
}
if ( F_65 ( V_91 , F_26 ( V_532 ) -> V_91 ) ) {
F_271 ( V_2 , V_91 , F_26 ( V_532 ) -> V_108 ) ;
} else {
F_300 ( & V_532 -> V_527 , & V_4 -> V_527 ,
& V_40 -> V_500 ) ;
F_272 ( V_2 ,
F_26 ( V_532 ) -> V_91 ,
F_26 ( V_532 ) -> V_108 ) ;
F_82 ( F_4 ( V_2 ) ,
V_542 ) ;
F_284 ( V_532 ) ;
goto V_543;
}
} else if ( F_278 ( V_2 , V_532 , V_4 , & V_519 ) ) {
goto V_537;
}
V_526 = & V_531 -> V_539 ;
}
V_540:
F_298 ( & V_4 -> V_527 , V_531 , V_526 ) ;
F_299 ( & V_4 -> V_527 , & V_40 -> V_500 ) ;
V_543:
while ( ( V_530 = F_288 ( & V_4 -> V_527 ) ) != NULL ) {
V_532 = F_287 ( V_530 , struct V_3 , V_527 ) ;
if ( ! F_65 ( V_108 , F_26 ( V_532 ) -> V_91 ) )
break;
if ( F_56 ( V_108 , F_26 ( V_532 ) -> V_108 ) ) {
F_272 ( V_2 , F_26 ( V_532 ) -> V_91 ,
V_108 ) ;
break;
}
F_289 ( & V_532 -> V_527 , & V_40 -> V_500 ) ;
F_272 ( V_2 , F_26 ( V_532 ) -> V_91 ,
F_26 ( V_532 ) -> V_108 ) ;
F_82 ( F_4 ( V_2 ) , V_542 ) ;
F_282 ( V_2 , V_532 ) ;
}
if ( ! V_530 )
V_40 -> V_535 = V_4 ;
V_538:
if ( F_151 ( V_40 ) )
F_275 ( V_2 , V_91 , V_108 ) ;
V_536:
if ( V_4 ) {
F_39 ( V_2 , V_4 ) ;
F_301 ( V_4 ) ;
F_302 ( V_4 , V_2 ) ;
}
}
static int T_11 F_303 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_544 ,
bool * V_519 )
{
int V_523 ;
struct V_3 * V_524 = F_290 ( & V_2 -> V_528 ) ;
F_304 ( V_4 , V_544 ) ;
V_523 = ( V_524 &&
F_278 ( V_2 , V_524 , V_4 , V_519 ) ) ? 1 : 0 ;
F_220 ( F_15 ( V_2 ) , F_26 ( V_4 ) -> V_108 ) ;
if ( ! V_523 ) {
F_291 ( & V_2 -> V_528 , V_4 ) ;
F_302 ( V_4 , V_2 ) ;
}
return V_523 ;
}
int F_305 ( struct V_1 * V_2 , struct V_545 * V_277 , T_12 V_529 )
{
struct V_3 * V_4 ;
int V_180 = - V_546 ;
int V_547 = 0 ;
bool V_519 ;
if ( V_529 == 0 )
return 0 ;
if ( V_529 > V_548 ) {
int V_549 = F_10 ( T_12 , V_529 >> V_550 , V_551 ) ;
V_547 = V_549 << V_550 ;
V_529 = V_547 + ( V_529 & ~ V_552 ) ;
}
V_4 = F_306 ( V_529 - V_547 , V_547 ,
V_553 ,
& V_180 , V_2 -> V_554 ) ;
if ( ! V_4 )
goto V_180;
F_307 ( V_4 , V_529 - V_547 ) ;
V_4 -> V_547 = V_547 ;
V_4 -> V_5 = V_529 ;
if ( F_293 ( V_2 , V_4 , V_4 -> V_73 ) )
goto V_555;
V_180 = F_308 ( V_4 , 0 , & V_277 -> V_556 , V_529 ) ;
if ( V_180 )
goto V_555;
F_26 ( V_4 ) -> V_91 = F_15 ( V_2 ) -> V_106 ;
F_26 ( V_4 ) -> V_108 = F_26 ( V_4 ) -> V_91 + V_529 ;
F_26 ( V_4 ) -> V_175 = F_15 ( V_2 ) -> V_124 - 1 ;
if ( F_303 ( V_2 , V_4 , 0 , & V_519 ) ) {
F_79 ( V_519 ) ;
F_284 ( V_4 ) ;
}
return V_529 ;
V_555:
F_309 ( V_4 ) ;
V_180:
return V_180 ;
}
static void F_310 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_519 = false ;
int V_523 = - 1 ;
if ( F_26 ( V_4 ) -> V_91 == F_26 ( V_4 ) -> V_108 ) {
F_284 ( V_4 ) ;
return;
}
F_311 ( V_4 ) ;
F_304 ( V_4 , F_14 ( V_4 ) -> V_445 * 4 ) ;
F_23 ( V_40 , V_4 ) ;
V_40 -> V_62 . V_509 = 0 ;
if ( F_26 ( V_4 ) -> V_91 == V_40 -> V_106 ) {
if ( F_258 ( V_40 ) == 0 )
goto V_557;
if ( V_40 -> V_558 . V_559 == V_560 &&
V_40 -> V_92 == V_40 -> V_106 && V_40 -> V_558 . V_5 &&
F_312 ( V_2 ) && ! V_40 -> V_561 ) {
int V_562 = F_10 (unsigned int, skb->len,
tp->ucopy.len) ;
F_313 ( V_563 ) ;
if ( ! F_314 ( V_4 , 0 , V_40 -> V_558 . V_277 , V_562 ) ) {
V_40 -> V_558 . V_5 -= V_562 ;
V_40 -> V_92 += V_562 ;
V_523 = ( V_562 == V_4 -> V_5 ) ;
F_60 ( V_2 ) ;
}
}
if ( V_523 <= 0 ) {
V_564:
if ( V_523 < 0 ) {
if ( F_315 ( & V_2 -> V_528 ) == 0 )
F_316 ( V_2 , V_4 -> V_73 ) ;
else if ( F_293 ( V_2 , V_4 , V_4 -> V_73 ) )
goto V_565;
}
V_523 = F_303 ( V_2 , V_4 , 0 , & V_519 ) ;
}
F_220 ( V_40 , F_26 ( V_4 ) -> V_108 ) ;
if ( V_4 -> V_5 )
F_61 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_207 & V_209 )
F_263 ( V_2 ) ;
if ( ! F_277 ( & V_40 -> V_500 ) ) {
F_285 ( V_2 ) ;
if ( F_277 ( & V_40 -> V_500 ) )
F_8 ( V_2 ) -> V_15 . V_33 = 0 ;
}
if ( V_40 -> V_62 . V_170 )
F_276 ( V_40 ) ;
F_223 ( V_2 ) ;
if ( V_523 > 0 )
F_292 ( V_4 , V_519 ) ;
if ( ! F_262 ( V_2 , V_488 ) )
V_2 -> V_566 ( V_2 ) ;
return;
}
if ( ! F_65 ( F_26 ( V_4 ) -> V_108 , V_40 -> V_106 ) ) {
F_82 ( F_4 ( V_2 ) , V_511 ) ;
F_271 ( V_2 , F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_108 ) ;
V_557:
F_18 ( V_2 ) ;
F_62 ( V_2 ) ;
V_565:
F_282 ( V_2 , V_4 ) ;
return;
}
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_106 + F_258 ( V_40 ) ) )
goto V_557;
F_18 ( V_2 ) ;
if ( F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_106 ) ) {
F_243 ( V_2 , L_21 ,
V_40 -> V_106 , F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_108 ) ;
F_271 ( V_2 , F_26 ( V_4 ) -> V_91 , V_40 -> V_106 ) ;
if ( ! F_258 ( V_40 ) )
goto V_557;
goto V_564;
}
F_297 ( V_2 , V_4 ) ;
}
static struct V_3 * F_317 ( struct V_3 * V_4 , struct V_567 * V_568 )
{
if ( V_568 )
return ! F_318 ( V_568 , V_4 ) ? V_4 -> V_371 : NULL ;
return F_319 ( F_288 ( & V_4 -> V_527 ) , struct V_3 , V_527 ) ;
}
static struct V_3 * F_320 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_567 * V_568 ,
struct V_569 * V_570 )
{
struct V_3 * V_371 = F_317 ( V_4 , V_568 ) ;
if ( V_568 )
F_321 ( V_4 , V_568 ) ;
else
F_289 ( & V_4 -> V_527 , V_570 ) ;
F_284 ( V_4 ) ;
F_82 ( F_4 ( V_2 ) , V_571 ) ;
return V_371 ;
}
static void F_322 ( struct V_569 * V_570 , struct V_3 * V_4 )
{
struct V_525 * * V_526 = & V_570 -> V_525 ;
struct V_525 * V_531 = NULL ;
struct V_3 * V_532 ;
while ( * V_526 ) {
V_531 = * V_526 ;
V_532 = F_287 ( V_531 , struct V_3 , V_527 ) ;
if ( F_56 ( F_26 ( V_4 ) -> V_91 , F_26 ( V_532 ) -> V_91 ) )
V_526 = & V_531 -> V_541 ;
else
V_526 = & V_531 -> V_539 ;
}
F_298 ( & V_4 -> V_527 , V_531 , V_526 ) ;
F_299 ( & V_4 -> V_527 , V_570 ) ;
}
static void
F_323 ( struct V_1 * V_2 , struct V_567 * V_568 , struct V_569 * V_570 ,
struct V_3 * V_572 , struct V_3 * V_524 , T_2 V_573 , T_2 V_536 )
{
struct V_3 * V_4 = V_572 , * V_574 ;
struct V_567 V_221 ;
bool V_575 ;
V_576:
for ( V_575 = true ; V_4 != NULL && V_4 != V_524 ; V_4 = V_574 ) {
V_574 = F_317 ( V_4 , V_568 ) ;
if ( ! F_56 ( V_573 , F_26 ( V_4 ) -> V_108 ) ) {
V_4 = F_320 ( V_2 , V_4 , V_568 , V_570 ) ;
if ( ! V_4 )
break;
goto V_576;
}
if ( ! ( F_26 ( V_4 ) -> V_207 & ( V_373 | V_209 ) ) &&
( F_38 ( V_4 -> V_73 ) > V_4 -> V_5 ||
F_56 ( F_26 ( V_4 ) -> V_91 , V_573 ) ) ) {
V_575 = false ;
break;
}
if ( V_574 && V_574 != V_524 &&
F_26 ( V_4 ) -> V_108 != F_26 ( V_574 ) -> V_91 ) {
V_575 = false ;
break;
}
V_573 = F_26 ( V_4 ) -> V_108 ;
}
if ( V_575 ||
( F_26 ( V_4 ) -> V_207 & ( V_373 | V_209 ) ) )
return;
F_324 ( & V_221 ) ;
while ( F_56 ( V_573 , V_536 ) ) {
int V_577 = F_10 ( int , F_325 ( 0 , 0 ) , V_536 - V_573 ) ;
struct V_3 * V_578 ;
V_578 = F_326 ( V_577 , V_185 ) ;
if ( ! V_578 )
break;
memcpy ( V_578 -> V_579 , V_4 -> V_579 , sizeof( V_4 -> V_579 ) ) ;
F_26 ( V_578 ) -> V_91 = F_26 ( V_578 ) -> V_108 = V_573 ;
if ( V_568 )
F_327 ( V_568 , V_4 , V_578 ) ;
else
F_291 ( & V_221 , V_578 ) ;
F_302 ( V_578 , V_2 ) ;
while ( V_577 > 0 ) {
int V_580 = V_573 - F_26 ( V_4 ) -> V_91 ;
int V_529 = F_26 ( V_4 ) -> V_108 - V_573 ;
F_99 ( V_580 < 0 ) ;
if ( V_529 > 0 ) {
V_529 = F_17 ( V_577 , V_529 ) ;
if ( F_328 ( V_4 , V_580 , F_307 ( V_578 , V_529 ) , V_529 ) )
F_329 () ;
F_26 ( V_578 ) -> V_108 += V_529 ;
V_577 -= V_529 ;
V_573 += V_529 ;
}
if ( ! F_56 ( V_573 , F_26 ( V_4 ) -> V_108 ) ) {
V_4 = F_320 ( V_2 , V_4 , V_568 , V_570 ) ;
if ( ! V_4 ||
V_4 == V_524 ||
( F_26 ( V_4 ) -> V_207 & ( V_373 | V_209 ) ) )
goto V_536;
}
}
}
V_536:
F_330 (&tmp, skb, n)
F_322 ( V_570 , V_4 ) ;
}
static void F_331 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 , * V_572 ;
struct V_525 * V_526 ;
T_2 V_573 , V_536 ;
V_526 = F_286 ( & V_40 -> V_500 ) ;
V_4 = F_319 ( V_526 , struct V_3 , V_527 ) ;
V_581:
if ( ! V_4 ) {
V_526 = F_332 ( & V_40 -> V_500 ) ;
V_40 -> V_535 = F_287 ( V_526 , struct V_3 , V_527 ) ;
return;
}
V_573 = F_26 ( V_4 ) -> V_91 ;
V_536 = F_26 ( V_4 ) -> V_108 ;
for ( V_572 = V_4 ; ; ) {
V_4 = F_317 ( V_4 , NULL ) ;
if ( ! V_4 ||
F_65 ( F_26 ( V_4 ) -> V_91 , V_536 ) ||
F_56 ( F_26 ( V_4 ) -> V_108 , V_573 ) ) {
F_323 ( V_2 , NULL , & V_40 -> V_500 ,
V_572 , V_4 , V_573 , V_536 ) ;
goto V_581;
}
if ( F_11 ( F_56 ( F_26 ( V_4 ) -> V_91 , V_573 ) ) )
V_573 = F_26 ( V_4 ) -> V_91 ;
if ( F_65 ( F_26 ( V_4 ) -> V_108 , V_536 ) )
V_536 = F_26 ( V_4 ) -> V_108 ;
}
}
static bool F_296 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_525 * V_582 , * V_202 ;
if ( F_277 ( & V_40 -> V_500 ) )
return false ;
F_82 ( F_4 ( V_2 ) , V_583 ) ;
V_582 = & V_40 -> V_535 -> V_527 ;
do {
V_202 = F_333 ( V_582 ) ;
F_289 ( V_582 , & V_40 -> V_500 ) ;
F_282 ( V_2 , F_287 ( V_582 , struct V_3 , V_527 ) ) ;
F_63 ( V_2 ) ;
if ( F_52 ( & V_2 -> V_96 ) <= V_2 -> V_83 &&
! F_41 ( V_2 ) )
break;
V_582 = V_202 ;
} while ( V_582 );
V_40 -> V_535 = F_287 ( V_202 , struct V_3 , V_527 ) ;
if ( V_40 -> V_62 . V_138 )
F_248 ( & V_40 -> V_62 ) ;
return true ;
}
static int F_295 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_243 ( V_2 , L_22 , V_40 -> V_92 ) ;
F_82 ( F_4 ( V_2 ) , V_584 ) ;
if ( F_52 ( & V_2 -> V_96 ) >= V_2 -> V_83 )
F_49 ( V_2 ) ;
else if ( F_41 ( V_2 ) )
V_40 -> V_76 = F_17 ( V_40 -> V_76 , 4U * V_40 -> V_79 ) ;
F_331 ( V_2 ) ;
if ( ! F_334 ( & V_2 -> V_528 ) )
F_323 ( V_2 , & V_2 -> V_528 , NULL ,
F_335 ( & V_2 -> V_528 ) ,
NULL ,
V_40 -> V_92 , V_40 -> V_106 ) ;
F_63 ( V_2 ) ;
if ( F_52 ( & V_2 -> V_96 ) <= V_2 -> V_83 )
return 0 ;
F_296 ( V_2 ) ;
if ( F_52 ( & V_2 -> V_96 ) <= V_2 -> V_83 )
return 0 ;
F_82 ( F_4 ( V_2 ) , V_585 ) ;
V_40 -> V_392 = 0 ;
return - 1 ;
}
static bool F_336 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_2 -> V_85 & V_87 )
return false ;
if ( F_41 ( V_2 ) )
return false ;
if ( F_50 ( V_2 ) >= F_51 ( V_2 , 0 ) )
return false ;
if ( F_130 ( V_40 ) >= V_40 -> V_68 )
return false ;
return true ;
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_336 ( V_2 ) ) {
F_33 ( V_2 ) ;
V_40 -> V_94 = V_95 ;
}
V_2 -> V_586 ( V_2 ) ;
}
static void F_338 ( struct V_1 * V_2 )
{
if ( F_262 ( V_2 , V_587 ) ) {
F_339 ( V_2 , V_587 ) ;
F_340 () ;
if ( V_2 -> V_588 &&
F_341 ( V_589 , & V_2 -> V_588 -> V_409 ) ) {
F_337 ( V_2 ) ;
if ( ! F_341 ( V_589 , & V_2 -> V_588 -> V_409 ) )
F_210 ( V_2 , V_590 ) ;
}
}
}
static inline void F_342 ( struct V_1 * V_2 )
{
F_343 ( V_2 ) ;
F_338 ( V_2 ) ;
}
static void F_344 ( struct V_1 * V_2 , int V_591 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( ( ( V_40 -> V_106 - V_40 -> V_407 ) > F_8 ( V_2 ) -> V_15 . V_18 &&
F_345 ( V_2 ) >= V_40 -> V_30 ) ||
F_19 ( V_2 ) ||
( V_591 && ! F_277 ( & V_40 -> V_500 ) ) ) {
F_231 ( V_2 ) ;
} else {
F_346 ( V_2 ) ;
}
}
static inline void F_347 ( struct V_1 * V_2 )
{
if ( ! F_348 ( V_2 ) ) {
return;
}
F_344 ( V_2 , 1 ) ;
}
static void F_349 ( struct V_1 * V_2 , const struct V_22 * V_53 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_225 = F_160 ( V_53 -> V_592 ) ;
if ( V_225 && ! V_593 )
V_225 -- ;
V_225 += F_252 ( V_53 -> V_91 ) ;
if ( F_65 ( V_40 -> V_92 , V_225 ) )
return;
if ( F_56 ( V_225 , V_40 -> V_106 ) )
return;
if ( V_40 -> V_561 && ! F_65 ( V_225 , V_40 -> V_594 ) )
return;
F_350 ( V_2 ) ;
if ( V_40 -> V_594 == V_40 -> V_92 && V_40 -> V_561 &&
! F_262 ( V_2 , V_595 ) && V_40 -> V_92 != V_40 -> V_106 ) {
struct V_3 * V_4 = F_335 ( & V_2 -> V_528 ) ;
V_40 -> V_92 ++ ;
if ( V_4 && ! F_56 ( V_40 -> V_92 , F_26 ( V_4 ) -> V_108 ) ) {
F_321 ( V_4 , & V_2 -> V_528 ) ;
F_284 ( V_4 ) ;
}
}
V_40 -> V_561 = V_596 ;
V_40 -> V_594 = V_225 ;
V_40 -> V_392 = 0 ;
}
static void F_351 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_22 * V_53 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_53 -> V_597 )
F_349 ( V_2 , V_53 ) ;
if ( V_40 -> V_561 == V_596 ) {
T_2 V_225 = V_40 -> V_594 - F_252 ( V_53 -> V_91 ) + ( V_53 -> V_445 * 4 ) -
V_53 -> V_55 ;
if ( V_225 < V_4 -> V_5 ) {
T_6 V_221 ;
if ( F_328 ( V_4 , V_225 , & V_221 , 1 ) )
F_329 () ;
V_40 -> V_561 = V_598 | V_221 ;
if ( ! F_262 ( V_2 , V_488 ) )
V_2 -> V_566 ( V_2 ) ;
}
}
}
static int F_352 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_599 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_562 = V_4 -> V_5 - V_599 ;
int V_180 ;
if ( F_353 ( V_4 ) )
V_180 = F_314 ( V_4 , V_599 , V_40 -> V_558 . V_277 , V_562 ) ;
else
V_180 = F_354 ( V_4 , V_599 , V_40 -> V_558 . V_277 ) ;
if ( ! V_180 ) {
V_40 -> V_558 . V_5 -= V_562 ;
V_40 -> V_92 += V_562 ;
F_60 ( V_2 ) ;
}
return V_180 ;
}
static bool F_355 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
return F_11 ( F_26 ( V_4 ) -> V_91 == ( V_40 -> V_106 - 1 ) &&
( 1 << V_2 -> V_480 ) & ( V_600 | V_601 |
V_602 ) ) ;
}
static bool F_356 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 , int V_603 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_604 = false ;
if ( F_253 ( F_4 ( V_2 ) , V_4 , V_53 , V_40 ) &&
V_40 -> V_62 . V_275 &&
F_256 ( V_2 , V_4 ) ) {
if ( ! V_53 -> V_605 ) {
F_82 ( F_4 ( V_2 ) , V_606 ) ;
if ( ! F_226 ( F_4 ( V_2 ) , V_4 ,
V_607 ,
& V_40 -> V_393 ) )
F_273 ( V_2 , V_4 ) ;
goto V_608;
}
}
if ( ! F_257 ( V_40 , F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_108 ) ) {
if ( ! V_53 -> V_605 ) {
if ( V_53 -> V_55 )
goto V_609;
if ( ! F_226 ( F_4 ( V_2 ) , V_4 ,
V_610 ,
& V_40 -> V_393 ) )
F_273 ( V_2 , V_4 ) ;
} else if ( F_355 ( V_2 , V_4 ) ) {
F_259 ( V_2 ) ;
}
goto V_608;
}
if ( V_53 -> V_605 ) {
if ( F_26 ( V_4 ) -> V_91 == V_40 -> V_106 ||
F_355 ( V_2 , V_4 ) ) {
V_604 = true ;
} else if ( F_151 ( V_40 ) && V_40 -> V_62 . V_170 > 0 ) {
struct V_218 * V_169 = & V_40 -> V_513 [ 0 ] ;
int V_611 = V_169 [ 0 ] . V_108 ;
int V_512 ;
for ( V_512 = 1 ; V_512 < V_40 -> V_62 . V_170 ;
++ V_512 ) {
V_611 = F_65 ( V_169 [ V_512 ] . V_108 ,
V_611 ) ?
V_169 [ V_512 ] . V_108 : V_611 ;
}
if ( F_26 ( V_4 ) -> V_91 == V_611 )
V_604 = true ;
}
if ( V_604 )
F_259 ( V_2 ) ;
else {
if ( V_40 -> V_612 && ! V_40 -> V_613 &&
V_2 -> V_480 == V_494 )
F_357 ( V_2 ) ;
F_227 ( V_2 , V_4 ) ;
}
goto V_608;
}
if ( V_53 -> V_55 ) {
V_609:
if ( V_603 )
F_358 ( F_4 ( V_2 ) , V_614 ) ;
F_82 ( F_4 ( V_2 ) , V_615 ) ;
F_227 ( V_2 , V_4 ) ;
goto V_608;
}
return true ;
V_608:
F_282 ( V_2 , V_4 ) ;
return false ;
}
void F_359 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 , unsigned int V_5 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_46 ( V_40 ) ;
if ( F_11 ( ! V_2 -> V_616 ) )
F_8 ( V_2 ) -> V_617 -> V_618 ( V_2 , V_4 ) ;
V_40 -> V_62 . V_275 = 0 ;
if ( ( F_13 ( V_53 ) & V_619 ) == V_40 -> V_392 &&
F_26 ( V_4 ) -> V_91 == V_40 -> V_106 &&
! F_65 ( F_26 ( V_4 ) -> V_175 , V_40 -> V_126 ) ) {
int V_25 = V_40 -> V_25 ;
if ( V_25 == sizeof( struct V_22 ) + V_477 ) {
if ( ! F_250 ( V_40 , V_53 ) )
goto V_620;
if ( ( T_8 ) ( V_40 -> V_62 . V_405 - V_40 -> V_62 . V_404 ) < 0 )
goto V_620;
}
if ( V_5 <= V_25 ) {
if ( V_5 == V_25 ) {
if ( V_25 ==
( sizeof( struct V_22 ) + V_477 ) &&
V_40 -> V_106 == V_40 -> V_407 )
F_232 ( V_40 ) ;
F_240 ( V_2 , V_4 , 0 ) ;
F_284 ( V_4 ) ;
F_342 ( V_2 ) ;
return;
} else {
F_358 ( F_4 ( V_2 ) , V_614 ) ;
goto V_608;
}
} else {
int V_523 = 0 ;
bool V_519 = false ;
if ( V_40 -> V_558 . V_559 == V_560 &&
V_40 -> V_92 == V_40 -> V_106 &&
V_5 - V_25 <= V_40 -> V_558 . V_5 &&
F_312 ( V_2 ) ) {
F_313 ( V_563 ) ;
if ( ! F_352 ( V_2 , V_4 , V_25 ) ) {
if ( V_25 ==
( sizeof( struct V_22 ) +
V_477 ) &&
V_40 -> V_106 == V_40 -> V_407 )
F_232 ( V_40 ) ;
F_58 ( V_2 , V_4 ) ;
F_304 ( V_4 , V_25 ) ;
F_220 ( V_40 , F_26 ( V_4 ) -> V_108 ) ;
F_82 ( F_4 ( V_2 ) ,
V_621 ) ;
V_523 = 1 ;
}
}
if ( ! V_523 ) {
if ( F_360 ( V_4 ) )
goto V_622;
if ( ( int ) V_4 -> V_73 > V_2 -> V_623 )
goto V_624;
if ( V_25 ==
( sizeof( struct V_22 ) + V_477 ) &&
V_40 -> V_106 == V_40 -> V_407 )
F_232 ( V_40 ) ;
F_58 ( V_2 , V_4 ) ;
F_82 ( F_4 ( V_2 ) , V_625 ) ;
V_523 = F_303 ( V_2 , V_4 , V_25 ,
& V_519 ) ;
}
F_61 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_175 != V_40 -> V_124 ) {
F_240 ( V_2 , V_4 , V_427 ) ;
F_342 ( V_2 ) ;
if ( ! F_348 ( V_2 ) )
goto V_626;
}
F_344 ( V_2 , 0 ) ;
V_626:
if ( V_523 )
F_292 ( V_4 , V_519 ) ;
V_2 -> V_566 ( V_2 ) ;
return;
}
}
V_620:
if ( V_5 < ( V_53 -> V_445 << 2 ) || F_360 ( V_4 ) )
goto V_622;
if ( ! V_53 -> V_348 && ! V_53 -> V_605 && ! V_53 -> V_55 )
goto V_608;
if ( ! F_356 ( V_2 , V_4 , V_53 , 1 ) )
return;
V_624:
if ( F_240 ( V_2 , V_4 , V_422 | V_421 ) < 0 )
goto V_608;
F_58 ( V_2 , V_4 ) ;
F_351 ( V_2 , V_4 , V_53 ) ;
F_310 ( V_2 , V_4 ) ;
F_342 ( V_2 ) ;
F_347 ( V_2 ) ;
return;
V_622:
F_358 ( F_4 ( V_2 ) , V_627 ) ;
F_358 ( F_4 ( V_2 ) , V_614 ) ;
V_608:
F_282 ( V_2 , V_4 ) ;
}
void F_361 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
F_265 ( V_2 , V_494 ) ;
V_13 -> V_15 . V_116 = V_95 ;
if ( V_4 ) {
V_13 -> V_617 -> V_618 ( V_2 , V_4 ) ;
F_362 ( V_2 , V_4 ) ;
}
V_13 -> V_617 -> V_628 ( V_2 ) ;
F_363 ( V_2 ) ;
F_364 ( V_2 , V_629 ) ;
F_365 ( V_2 ) ;
V_40 -> V_630 = V_95 ;
F_45 ( V_2 ) ;
if ( F_262 ( V_2 , V_631 ) )
F_366 ( V_2 , F_367 ( V_40 ) ) ;
if ( ! V_40 -> V_62 . V_390 )
F_368 ( V_40 , V_40 -> V_387 ) ;
else
V_40 -> V_392 = 0 ;
}
static bool F_369 ( struct V_1 * V_2 , struct V_3 * V_632 ,
struct V_435 * V_434 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_20 = V_40 -> V_633 ? F_113 ( V_2 ) : NULL ;
T_9 V_80 = V_40 -> V_62 . V_63 , V_634 = 0 ;
bool V_635 = false ;
if ( V_80 == V_40 -> V_62 . V_453 ) {
struct V_441 V_636 ;
F_370 ( & V_636 ) ;
V_636 . V_453 = V_636 . V_63 = 0 ;
F_245 ( F_4 ( V_2 ) , V_632 , & V_636 , 0 , NULL ) ;
V_80 = V_636 . V_63 ;
}
if ( ! V_40 -> V_612 ) {
V_434 -> V_5 = - 1 ;
} else if ( V_40 -> V_637 ) {
V_635 = ( V_434 -> V_5 < 0 && V_20 ) ;
} else if ( V_434 -> V_5 < 0 && ! V_40 -> V_633 ) {
V_634 = V_40 -> V_638 ? 2 : 1 ;
}
F_371 ( V_2 , V_80 , V_434 , V_635 , V_634 ) ;
if ( V_20 ) {
F_120 (data, sk) {
if ( V_20 == F_118 ( V_2 ) ||
F_372 ( V_2 , V_20 , 1 ) )
break;
}
F_199 ( V_2 ) ;
F_82 ( F_4 ( V_2 ) ,
V_639 ) ;
return true ;
}
V_40 -> V_640 = V_40 -> V_633 ;
if ( V_40 -> V_640 )
F_82 ( F_4 ( V_2 ) ,
V_641 ) ;
F_373 ( V_2 , V_632 ) ;
return false ;
}
static int F_374 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_435 V_436 = { . V_5 = - 1 } ;
int V_642 = V_40 -> V_62 . V_63 ;
bool V_643 ;
F_245 ( F_4 ( V_2 ) , V_4 , & V_40 -> V_62 , 0 , & V_436 ) ;
if ( V_40 -> V_62 . V_275 && V_40 -> V_62 . V_107 )
V_40 -> V_62 . V_107 -= V_40 -> V_476 ;
if ( V_53 -> V_348 ) {
if ( ! F_65 ( F_26 ( V_4 ) -> V_175 , V_40 -> V_124 ) ||
F_65 ( F_26 ( V_4 ) -> V_175 , V_40 -> V_126 ) )
goto V_644;
if ( V_40 -> V_62 . V_275 && V_40 -> V_62 . V_107 &&
! F_211 ( V_40 -> V_62 . V_107 , V_40 -> V_276 ,
F_59 ( V_40 ) ) ) {
F_82 ( F_4 ( V_2 ) ,
V_645 ) ;
goto V_644;
}
if ( V_53 -> V_605 ) {
F_259 ( V_2 ) ;
goto V_608;
}
if ( ! V_53 -> V_55 )
goto V_646;
F_30 ( V_40 , V_53 ) ;
F_375 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
F_240 ( V_2 , V_4 , V_422 ) ;
V_40 -> V_106 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_407 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_387 = F_160 ( V_53 -> V_74 ) ;
if ( ! V_40 -> V_62 . V_457 ) {
V_40 -> V_62 . V_390 = V_40 -> V_62 . V_647 = 0 ;
V_40 -> V_77 = F_17 ( V_40 -> V_77 , 65535U ) ;
}
if ( V_40 -> V_62 . V_275 ) {
V_40 -> V_62 . V_462 = 1 ;
V_40 -> V_25 =
sizeof( struct V_22 ) + V_477 ;
V_40 -> V_79 -= V_477 ;
F_232 ( V_40 ) ;
} else {
V_40 -> V_25 = sizeof( struct V_22 ) ;
}
if ( F_151 ( V_40 ) && V_648 )
F_376 ( V_40 ) ;
F_377 ( V_2 ) ;
F_178 ( V_2 , V_13 -> V_312 ) ;
F_53 ( V_2 ) ;
V_40 -> V_92 = V_40 -> V_106 ;
F_340 () ;
F_361 ( V_2 , V_4 ) ;
V_643 = ( V_40 -> V_612 || V_40 -> V_633 ) &&
F_369 ( V_2 , V_4 , & V_436 ) ;
if ( ! F_262 ( V_2 , V_488 ) ) {
V_2 -> V_501 ( V_2 ) ;
F_269 ( V_2 , V_649 , V_650 ) ;
}
if ( V_643 )
return - 1 ;
if ( V_2 -> V_651 ||
V_13 -> V_652 . V_653 ||
V_13 -> V_15 . V_33 ) {
F_62 ( V_2 ) ;
F_18 ( V_2 ) ;
F_146 ( V_2 , V_654 ,
V_655 , V_266 ) ;
V_608:
F_282 ( V_2 , V_4 ) ;
return 0 ;
} else {
F_231 ( V_2 ) ;
}
return - 1 ;
}
if ( V_53 -> V_605 ) {
goto V_646;
}
if ( V_40 -> V_62 . V_406 && V_40 -> V_62 . V_275 &&
F_378 ( & V_40 -> V_62 , 0 ) )
goto V_646;
if ( V_53 -> V_55 ) {
F_265 ( V_2 , V_493 ) ;
if ( V_40 -> V_62 . V_275 ) {
V_40 -> V_62 . V_462 = 1 ;
F_232 ( V_40 ) ;
V_40 -> V_25 =
sizeof( struct V_22 ) + V_477 ;
} else {
V_40 -> V_25 = sizeof( struct V_22 ) ;
}
V_40 -> V_106 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_92 = V_40 -> V_106 ;
V_40 -> V_407 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_387 = F_160 ( V_53 -> V_74 ) ;
V_40 -> V_386 = F_26 ( V_4 ) -> V_91 ;
V_40 -> V_166 = V_40 -> V_387 ;
F_31 ( V_40 , V_53 ) ;
F_377 ( V_2 ) ;
F_178 ( V_2 , V_13 -> V_312 ) ;
F_53 ( V_2 ) ;
F_379 ( V_2 ) ;
#if 0
return -1;
#else
goto V_608;
#endif
}
V_646:
F_370 ( & V_40 -> V_62 ) ;
V_40 -> V_62 . V_63 = V_642 ;
goto V_608;
V_644:
F_370 ( & V_40 -> V_62 ) ;
V_40 -> V_62 . V_63 = V_642 ;
return 1 ;
}
int F_380 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
struct V_343 * V_344 ;
int V_656 = 0 ;
bool V_657 ;
switch ( V_2 -> V_480 ) {
case V_486 :
goto V_608;
case V_658 :
if ( V_53 -> V_348 )
return 1 ;
if ( V_53 -> V_605 )
goto V_608;
if ( V_53 -> V_55 ) {
if ( V_53 -> V_522 )
goto V_608;
F_381 () ;
V_657 = V_13 -> V_617 -> V_659 ( V_2 , V_4 ) >= 0 ;
F_382 () ;
if ( ! V_657 )
return 1 ;
F_383 ( V_4 ) ;
return 0 ;
}
goto V_608;
case V_481 :
V_40 -> V_62 . V_275 = 0 ;
F_46 ( V_40 ) ;
V_656 = F_374 ( V_2 , V_4 , V_53 ) ;
if ( V_656 >= 0 )
return V_656 ;
F_351 ( V_2 , V_4 , V_53 ) ;
F_284 ( V_4 ) ;
F_342 ( V_2 ) ;
return 0 ;
}
F_46 ( V_40 ) ;
V_40 -> V_62 . V_275 = 0 ;
V_344 = V_40 -> V_350 ;
if ( V_344 ) {
F_79 ( V_2 -> V_480 != V_493 &&
V_2 -> V_480 != V_497 ) ;
if ( ! F_384 ( V_2 , V_4 , V_344 , true ) )
goto V_608;
}
if ( ! V_53 -> V_348 && ! V_53 -> V_605 && ! V_53 -> V_55 )
goto V_608;
if ( ! F_356 ( V_2 , V_4 , V_53 , 0 ) )
return 0 ;
V_657 = F_240 ( V_2 , V_4 , V_422 |
V_421 |
V_417 ) > 0 ;
if ( ! V_657 ) {
if ( V_2 -> V_480 == V_493 )
return 1 ;
F_227 ( V_2 , V_4 ) ;
goto V_608;
}
switch ( V_2 -> V_480 ) {
case V_493 :
if ( ! V_40 -> V_120 )
F_195 ( V_2 , V_344 ) ;
if ( V_344 ) {
F_8 ( V_2 ) -> V_251 = 0 ;
F_385 ( V_2 , V_344 , false ) ;
} else {
V_13 -> V_617 -> V_628 ( V_2 ) ;
F_364 ( V_2 , V_660 ) ;
F_365 ( V_2 ) ;
F_377 ( V_2 ) ;
V_40 -> V_92 = V_40 -> V_106 ;
F_45 ( V_2 ) ;
}
F_340 () ;
F_265 ( V_2 , V_494 ) ;
V_2 -> V_501 ( V_2 ) ;
if ( V_2 -> V_588 )
F_269 ( V_2 , V_649 , V_650 ) ;
V_40 -> V_124 = F_26 ( V_4 ) -> V_175 ;
V_40 -> V_387 = F_160 ( V_53 -> V_74 ) << V_40 -> V_62 . V_390 ;
F_375 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
if ( V_40 -> V_62 . V_462 )
V_40 -> V_79 -= V_477 ;
if ( V_344 ) {
F_199 ( V_2 ) ;
} else
F_363 ( V_2 ) ;
if ( ! F_8 ( V_2 ) -> V_58 -> V_304 )
F_67 ( V_2 ) ;
V_40 -> V_630 = V_95 ;
F_53 ( V_2 ) ;
F_386 ( V_40 ) ;
break;
case V_497 : {
int V_661 ;
if ( V_344 ) {
F_385 ( V_2 , V_344 , false ) ;
F_199 ( V_2 ) ;
}
if ( V_40 -> V_124 != V_40 -> V_662 )
break;
F_265 ( V_2 , V_498 ) ;
V_2 -> V_490 |= V_663 ;
F_241 ( V_2 ) ;
if ( ! F_262 ( V_2 , V_488 ) ) {
V_2 -> V_501 ( V_2 ) ;
break;
}
if ( V_40 -> V_664 < 0 ) {
F_261 ( V_2 ) ;
F_82 ( F_4 ( V_2 ) , V_665 ) ;
return 1 ;
}
if ( F_26 ( V_4 ) -> V_108 != F_26 ( V_4 ) -> V_91 &&
F_65 ( F_26 ( V_4 ) -> V_108 - V_53 -> V_522 , V_40 -> V_106 ) ) {
if ( V_40 -> V_612 && V_53 -> V_522 )
F_357 ( V_2 ) ;
F_261 ( V_2 ) ;
F_82 ( F_4 ( V_2 ) , V_665 ) ;
return 1 ;
}
V_661 = F_387 ( V_2 ) ;
if ( V_661 > V_666 ) {
F_366 ( V_2 , V_661 - V_666 ) ;
} else if ( V_53 -> V_522 || F_312 ( V_2 ) ) {
F_366 ( V_2 , V_661 ) ;
} else {
F_266 ( V_2 , V_498 , V_661 ) ;
goto V_608;
}
break;
}
case V_495 :
if ( V_40 -> V_124 == V_40 -> V_662 ) {
F_266 ( V_2 , V_499 , 0 ) ;
goto V_608;
}
break;
case V_496 :
if ( V_40 -> V_124 == V_40 -> V_662 ) {
F_388 ( V_2 ) ;
F_261 ( V_2 ) ;
goto V_608;
}
break;
}
F_351 ( V_2 , V_4 , V_53 ) ;
switch ( V_2 -> V_480 ) {
case V_484 :
case V_495 :
case V_496 :
if ( ! F_56 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_106 ) )
break;
case V_497 :
case V_498 :
if ( V_2 -> V_490 & V_491 ) {
if ( F_26 ( V_4 ) -> V_108 != F_26 ( V_4 ) -> V_91 &&
F_65 ( F_26 ( V_4 ) -> V_108 - V_53 -> V_522 , V_40 -> V_106 ) ) {
F_82 ( F_4 ( V_2 ) , V_665 ) ;
F_259 ( V_2 ) ;
return 1 ;
}
}
case V_494 :
F_310 ( V_2 , V_4 ) ;
V_656 = 1 ;
break;
}
if ( V_2 -> V_480 != V_486 ) {
F_342 ( V_2 ) ;
F_347 ( V_2 ) ;
}
if ( ! V_656 ) {
V_608:
F_282 ( V_2 , V_4 ) ;
}
return 0 ;
}
static inline void F_389 ( struct V_343 * V_344 , T_13 V_667 , int V_668 )
{
struct V_669 * V_670 = F_390 ( V_344 ) ;
if ( V_668 == V_281 )
F_391 ( L_23 ,
& V_670 -> V_671 , V_667 ) ;
#if F_162 ( V_284 )
else if ( V_668 == V_285 )
F_391 ( L_24 ,
& V_670 -> V_672 , V_667 ) ;
#endif
}
static void F_392 ( struct V_343 * V_344 ,
const struct V_3 * V_4 ,
const struct V_1 * V_673 ,
const struct V_36 * V_37 )
{
const struct V_22 * V_53 = F_14 ( V_4 ) ;
const struct V_245 * V_245 = F_4 ( V_673 ) ;
bool V_674 = V_53 -> V_54 && V_53 -> V_44 ;
bool V_675 , V_676 ;
T_2 V_677 ;
if ( ! V_674 )
return;
V_675 = ! F_393 ( F_26 ( V_4 ) -> V_46 ) ;
V_677 = F_394 ( V_37 , V_678 ) ;
V_676 = V_245 -> V_257 . V_679 || V_677 ;
if ( ( ! V_675 && V_676 ) || F_27 ( V_673 ) ||
( V_677 & V_680 ) ||
F_395 ( (struct V_1 * ) V_344 ) )
F_390 ( V_344 ) -> V_676 = 1 ;
}
static void F_396 ( struct V_343 * V_344 ,
const struct V_441 * V_62 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_669 * V_670 = F_390 ( V_344 ) ;
V_344 -> V_681 = 0 ;
V_344 -> V_682 = 0 ;
F_196 ( V_344 ) -> V_683 = F_26 ( V_4 ) -> V_91 ;
F_196 ( V_344 ) -> V_106 = F_26 ( V_4 ) -> V_91 + 1 ;
F_196 ( V_344 ) -> V_346 = F_197 () ;
F_196 ( V_344 ) -> V_393 = 0 ;
V_344 -> V_80 = V_62 -> V_63 ;
V_344 -> V_404 = V_62 -> V_275 ? V_62 -> V_405 : 0 ;
V_670 -> V_462 = V_62 -> V_462 ;
V_670 -> V_138 = V_62 -> V_138 ;
V_670 -> V_390 = V_62 -> V_390 ;
V_670 -> V_457 = V_62 -> V_457 ;
V_670 -> V_244 = 0 ;
V_670 -> V_676 = 0 ;
V_670 -> V_684 = F_14 ( V_4 ) -> V_685 ;
V_670 -> V_686 = F_160 ( F_14 ( V_4 ) -> V_687 ) ;
V_670 -> V_688 = F_397 ( V_2 , V_4 ) ;
}
struct V_343 * F_398 ( const struct V_689 * V_690 ,
struct V_1 * V_691 ,
bool V_692 )
{
struct V_343 * V_344 = F_399 ( V_690 , V_691 ,
V_692 ) ;
if ( V_344 ) {
struct V_669 * V_670 = F_390 ( V_344 ) ;
F_400 ( V_670 , V_409 ) ;
V_670 -> V_636 = NULL ;
#if F_162 ( V_284 )
V_670 -> V_693 = NULL ;
#endif
F_401 ( & V_670 -> V_694 , 0 ) ;
V_670 -> V_695 = V_696 ;
F_402 ( & V_670 -> V_697 , F_4 ( V_691 ) ) ;
V_670 -> V_698 = V_691 -> V_280 ;
}
return V_344 ;
}
static bool F_403 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_699 )
{
struct V_700 * V_701 = & F_8 ( V_2 ) -> V_652 ;
const char * V_277 = L_25 ;
bool V_702 = false ;
struct V_245 * V_245 = F_4 ( V_2 ) ;
#ifdef F_404
if ( V_245 -> V_257 . V_703 ) {
V_277 = L_26 ;
V_702 = true ;
F_405 ( F_4 ( V_2 ) , V_704 ) ;
} else
#endif
F_405 ( F_4 ( V_2 ) , V_705 ) ;
if ( ! V_701 -> V_706 &&
V_245 -> V_257 . V_703 != 2 &&
F_406 ( & V_701 -> V_706 , 1 ) == 0 )
F_407 ( L_27 ,
V_699 , F_160 ( F_14 ( V_4 ) -> V_687 ) , V_277 ) ;
return V_702 ;
}
static void F_408 ( const struct V_1 * V_2 ,
struct V_343 * V_344 ,
const struct V_3 * V_4 )
{
if ( F_15 ( V_2 ) -> V_707 ) {
T_2 V_5 = F_409 ( V_4 ) + F_410 ( V_4 ) ;
T_2 * V_577 ;
V_577 = F_411 ( V_5 + sizeof( T_2 ) , V_185 ) ;
if ( V_577 ) {
V_577 [ 0 ] = V_5 ;
memcpy ( & V_577 [ 1 ] , F_412 ( V_4 ) , V_5 ) ;
V_344 -> V_708 = V_577 ;
}
}
}
int F_413 ( struct V_689 * V_709 ,
const struct V_710 * V_711 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_435 V_436 = { . V_5 = - 1 } ;
T_4 V_712 = F_26 ( V_4 ) -> V_713 ;
struct V_441 V_714 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_245 * V_245 = F_4 ( V_2 ) ;
struct V_1 * V_715 = NULL ;
struct V_36 * V_37 = NULL ;
struct V_343 * V_344 ;
bool V_702 = false ;
struct V_716 V_717 ;
if ( ( V_245 -> V_257 . V_703 == 2 ||
F_414 ( V_2 ) ) && ! V_712 ) {
V_702 = F_403 ( V_2 , V_4 , V_709 -> V_718 ) ;
if ( ! V_702 )
goto V_565;
}
if ( F_415 ( V_2 ) ) {
F_82 ( F_4 ( V_2 ) , V_719 ) ;
goto V_565;
}
V_344 = F_398 ( V_709 , V_2 , ! V_702 ) ;
if ( ! V_344 )
goto V_565;
F_196 ( V_344 ) -> V_720 = V_711 ;
F_196 ( V_344 ) -> V_721 = 0 ;
F_370 ( & V_714 ) ;
V_714 . V_63 = V_711 -> V_63 ;
V_714 . V_453 = V_40 -> V_62 . V_453 ;
F_245 ( F_4 ( V_2 ) , V_4 , & V_714 , 0 ,
V_702 ? NULL : & V_436 ) ;
if ( V_702 && ! V_714 . V_275 )
F_370 ( & V_714 ) ;
V_714 . V_462 = V_714 . V_275 ;
F_396 ( V_344 , & V_714 , V_4 , V_2 ) ;
F_390 ( V_344 ) -> V_722 = F_159 ( V_2 ) -> V_723 ;
F_390 ( V_344 ) -> V_724 = F_416 ( V_2 , V_4 ) ;
V_711 -> V_725 ( V_344 , V_2 , V_4 ) ;
if ( F_417 ( V_2 , V_4 , V_344 ) )
goto V_726;
if ( V_714 . V_462 )
F_196 ( V_344 ) -> V_721 = V_711 -> V_727 ( V_245 , V_4 ) ;
if ( ! V_702 && ! V_712 ) {
if ( ! V_245 -> V_257 . V_703 &&
( V_245 -> V_257 . V_728 - F_418 ( V_2 ) <
( V_245 -> V_257 . V_728 >> 2 ) ) &&
! F_419 ( V_344 , V_37 ) ) {
F_389 ( V_344 , F_160 ( F_14 ( V_4 ) -> V_685 ) ,
V_709 -> V_668 ) ;
goto V_729;
}
V_712 = V_711 -> V_730 ( V_4 ) ;
}
if ( ! V_37 ) {
V_37 = V_711 -> V_731 ( V_2 , & V_717 , V_344 ) ;
if ( ! V_37 )
goto V_726;
}
F_392 ( V_344 , V_4 , V_2 , V_37 ) ;
if ( V_702 ) {
V_712 = F_420 ( V_711 , V_2 , V_4 , & V_344 -> V_80 ) ;
V_344 -> V_682 = V_714 . V_462 ;
if ( ! V_714 . V_462 )
F_390 ( V_344 ) -> V_676 = 0 ;
}
F_196 ( V_344 ) -> V_732 = V_712 ;
F_196 ( V_344 ) -> V_733 = F_421 () ;
F_422 ( V_344 , V_2 , V_37 ) ;
if ( ! V_702 ) {
F_408 ( V_2 , V_344 , V_4 ) ;
V_715 = F_423 ( V_2 , V_4 , V_344 , & V_436 , V_37 ) ;
}
if ( V_715 ) {
V_711 -> V_734 ( V_715 , V_37 , & V_717 , V_344 ,
& V_436 , V_735 ) ;
F_424 ( V_2 , V_344 , V_715 ) ;
V_2 -> V_566 ( V_2 ) ;
F_425 ( V_715 ) ;
F_426 ( V_715 ) ;
} else {
F_196 ( V_344 ) -> V_736 = false ;
if ( ! V_702 )
F_427 ( V_2 , V_344 ,
F_428 ( (struct V_1 * ) V_344 ) ) ;
V_711 -> V_734 ( V_2 , V_37 , & V_717 , V_344 , & V_436 ,
! V_702 ? V_737 :
V_738 ) ;
if ( V_702 ) {
F_429 ( V_344 ) ;
return 0 ;
}
}
F_430 ( V_344 ) ;
return 0 ;
V_729:
F_431 ( V_37 ) ;
V_726:
F_429 ( V_344 ) ;
V_565:
F_432 ( V_2 ) ;
return 0 ;
}
