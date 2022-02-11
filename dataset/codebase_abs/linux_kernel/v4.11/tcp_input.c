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
V_40 -> V_88 . time = V_90 ;
V_40 -> V_88 . V_91 = V_40 -> V_92 ;
V_84 = F_46 ( V_2 ) ;
if ( V_40 -> V_77 >= V_84 ) {
V_40 -> V_77 = V_84 ;
if ( V_93 && V_84 > 4 * V_40 -> V_79 )
V_40 -> V_77 = F_47 ( V_84 -
( V_84 >> V_93 ) ,
4 * V_40 -> V_79 ) ;
}
if ( V_93 &&
V_40 -> V_77 > 2 * V_40 -> V_79 &&
V_40 -> V_77 + V_40 -> V_79 > V_84 )
V_40 -> V_77 = F_47 ( 2 * V_40 -> V_79 , V_84 - V_40 -> V_79 ) ;
V_40 -> V_76 = F_17 ( V_40 -> V_76 , V_40 -> V_77 ) ;
V_40 -> V_94 = V_90 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_15 . V_31 = 0 ;
if ( V_2 -> V_83 < V_75 [ 2 ] &&
! ( V_2 -> V_85 & V_86 ) &&
! F_41 ( V_2 ) &&
F_49 ( V_2 ) < F_50 ( V_2 , 0 ) ) {
V_2 -> V_83 = F_17 ( F_51 ( & V_2 -> V_95 ) ,
V_75 [ 2 ] ) ;
}
if ( F_51 ( & V_2 -> V_95 ) > V_2 -> V_83 )
V_40 -> V_76 = F_17 ( V_40 -> V_77 , 2U * V_40 -> V_79 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
unsigned int V_96 = F_10 (unsigned int, tp->advmss, tp->mss_cache) ;
V_96 = F_17 ( V_96 , V_40 -> V_30 / 2 ) ;
V_96 = F_17 ( V_96 , V_21 ) ;
V_96 = F_47 ( V_96 , V_23 ) ;
F_8 ( V_2 ) -> V_15 . V_18 = V_96 ;
}
static void F_53 ( struct V_39 * V_40 , T_2 V_97 , int V_98 )
{
T_2 V_99 = V_40 -> V_100 . V_101 ;
long V_102 = V_97 ;
if ( V_102 == 0 )
V_102 = 1 ;
if ( V_99 != 0 ) {
if ( ! V_98 ) {
V_102 -= ( V_99 >> 3 ) ;
V_99 += V_102 ;
} else {
V_102 <<= 3 ;
if ( V_102 < V_99 )
V_99 = V_102 ;
}
} else {
V_99 = V_102 << 3 ;
}
if ( V_40 -> V_100 . V_101 != V_99 )
V_40 -> V_100 . V_101 = V_99 ;
}
static inline void F_54 ( struct V_39 * V_40 )
{
if ( V_40 -> V_100 . time == 0 )
goto V_103;
if ( F_55 ( V_40 -> V_104 , V_40 -> V_100 . V_91 ) )
return;
F_53 ( V_40 , V_90 - V_40 -> V_100 . time , 1 ) ;
V_103:
V_40 -> V_100 . V_91 = V_40 -> V_104 + V_40 -> V_30 ;
V_40 -> V_100 . time = V_90 ;
}
static inline void F_56 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_62 . V_105 &&
( F_26 ( V_4 ) -> V_106 -
F_26 ( V_4 ) -> V_91 >= F_8 ( V_2 ) -> V_15 . V_18 ) )
F_53 ( V_40 , V_90 - V_40 -> V_62 . V_105 , 0 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int time ;
int V_107 ;
time = V_90 - V_40 -> V_88 . time ;
if ( time < ( V_40 -> V_100 . V_101 >> 3 ) || V_40 -> V_100 . V_101 == 0 )
return;
V_107 = V_40 -> V_92 - V_40 -> V_88 . V_91 ;
if ( V_107 <= V_40 -> V_88 . V_89 )
goto V_103;
if ( V_82 &&
! ( V_2 -> V_85 & V_86 ) ) {
int V_108 , V_81 , V_109 ;
V_108 = ( V_107 << 1 ) + 16 * V_40 -> V_79 ;
if ( V_107 >=
V_40 -> V_88 . V_89 + ( V_40 -> V_88 . V_89 >> 2 ) ) {
if ( V_107 >=
V_40 -> V_88 . V_89 + ( V_40 -> V_88 . V_89 >> 1 ) )
V_108 <<= 1 ;
else
V_108 += ( V_108 >> 1 ) ;
}
V_81 = F_43 ( V_40 -> V_79 + V_65 ) ;
while ( F_38 ( V_81 ) < V_40 -> V_79 )
V_81 += 128 ;
V_109 = F_17 ( V_108 / V_40 -> V_79 * V_81 , V_75 [ 2 ] ) ;
if ( V_109 > V_2 -> V_83 ) {
V_2 -> V_83 = V_109 ;
V_40 -> V_77 = V_108 ;
}
}
V_40 -> V_88 . V_89 = V_107 ;
V_103:
V_40 -> V_88 . V_91 = V_40 -> V_92 ;
V_40 -> V_88 . time = V_90 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
T_2 V_110 ;
F_59 ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
F_54 ( V_40 ) ;
V_110 = V_90 ;
if ( ! V_13 -> V_15 . V_34 ) {
F_16 ( V_2 ) ;
V_13 -> V_15 . V_34 = V_35 ;
} else {
int V_102 = V_110 - V_13 -> V_15 . V_111 ;
if ( V_102 <= V_35 / 2 ) {
V_13 -> V_15 . V_34 = ( V_13 -> V_15 . V_34 >> 1 ) + V_35 / 2 ;
} else if ( V_102 < V_13 -> V_15 . V_34 ) {
V_13 -> V_15 . V_34 = ( V_13 -> V_15 . V_34 >> 1 ) + V_102 ;
if ( V_13 -> V_15 . V_34 > V_13 -> V_112 )
V_13 -> V_15 . V_34 = V_13 -> V_112 ;
} else if ( V_102 > V_13 -> V_112 ) {
F_16 ( V_2 ) ;
F_60 ( V_2 ) ;
}
}
V_13 -> V_15 . V_111 = V_110 ;
F_29 ( V_40 , V_4 ) ;
if ( V_4 -> V_5 >= 128 )
F_39 ( V_2 , V_4 ) ;
}
static void F_61 ( struct V_1 * V_2 , long V_113 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
long V_102 = V_113 ;
T_2 V_114 = V_40 -> V_115 ;
if ( V_114 != 0 ) {
V_102 -= ( V_114 >> 3 ) ;
V_114 += V_102 ;
if ( V_102 < 0 ) {
V_102 = - V_102 ;
V_102 -= ( V_40 -> V_116 >> 2 ) ;
if ( V_102 > 0 )
V_102 >>= 3 ;
} else {
V_102 -= ( V_40 -> V_116 >> 2 ) ;
}
V_40 -> V_116 += V_102 ;
if ( V_40 -> V_116 > V_40 -> V_117 ) {
V_40 -> V_117 = V_40 -> V_116 ;
if ( V_40 -> V_117 > V_40 -> V_118 )
V_40 -> V_118 = V_40 -> V_117 ;
}
if ( F_62 ( V_40 -> V_119 , V_40 -> V_120 ) ) {
if ( V_40 -> V_117 < V_40 -> V_118 )
V_40 -> V_118 -= ( V_40 -> V_118 - V_40 -> V_117 ) >> 2 ;
V_40 -> V_120 = V_40 -> V_121 ;
V_40 -> V_117 = F_63 ( V_2 ) ;
}
} else {
V_114 = V_102 << 3 ;
V_40 -> V_116 = V_102 << 1 ;
V_40 -> V_118 = F_47 ( V_40 -> V_116 , F_63 ( V_2 ) ) ;
V_40 -> V_117 = V_40 -> V_118 ;
V_40 -> V_120 = V_40 -> V_121 ;
}
V_40 -> V_115 = F_47 ( 1U , V_114 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
T_3 V_122 ;
V_122 = ( T_3 ) V_40 -> V_64 * ( ( V_123 / 100 ) << 3 ) ;
if ( V_40 -> V_68 < V_40 -> V_124 / 2 )
V_122 *= V_125 ;
else
V_122 *= V_126 ;
V_122 *= F_47 ( V_40 -> V_68 , V_40 -> V_127 ) ;
if ( F_65 ( V_40 -> V_115 ) )
F_66 ( V_122 , V_40 -> V_115 ) ;
F_67 ( V_2 -> V_128 ) = F_10 ( T_3 , V_122 ,
V_2 -> V_129 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
F_8 ( V_2 ) -> V_112 = F_69 ( V_40 ) ;
F_70 ( V_2 ) ;
}
T_4 F_71 ( const struct V_39 * V_40 , const struct V_36 * V_37 )
{
T_4 V_130 = ( V_37 ? F_21 ( V_37 , V_131 ) : 0 ) ;
if ( ! V_130 )
V_130 = V_67 ;
return F_10 ( T_4 , V_130 , V_40 -> V_132 ) ;
}
void F_72 ( struct V_39 * V_40 )
{
if ( F_73 ( V_40 ) )
V_40 -> V_133 = NULL ;
V_40 -> V_62 . V_134 &= ~ V_135 ;
}
static void F_74 ( struct V_39 * V_40 )
{
V_40 -> V_62 . V_134 |= V_136 ;
}
static void F_75 ( struct V_1 * V_2 , const int V_137 ,
const int V_138 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_139 ;
if ( V_137 > V_40 -> V_69 ) {
V_40 -> V_69 = F_17 ( V_140 , V_137 ) ;
#if V_141 > 1
F_76 ( L_3 ,
V_40 -> V_62 . V_134 , F_8 ( V_2 ) -> V_142 ,
V_40 -> V_69 ,
V_40 -> V_143 ,
V_40 -> V_144 ,
V_40 -> V_145 ? V_40 -> V_146 : 0 ) ;
#endif
F_72 ( V_40 ) ;
}
V_40 -> V_147 . V_148 = 1 ;
if ( V_138 )
V_139 = V_149 ;
else if ( F_77 ( V_40 ) )
V_139 = V_150 ;
else if ( F_73 ( V_40 ) )
V_139 = V_151 ;
else
V_139 = V_152 ;
F_78 ( F_4 ( V_2 ) , V_139 ) ;
}
static void F_79 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
if ( ! V_40 -> V_153 ||
F_55 ( F_26 ( V_4 ) -> V_91 ,
F_26 ( V_40 -> V_153 ) -> V_91 ) )
V_40 -> V_153 = V_4 ;
}
static void F_80 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
T_5 V_154 = F_26 ( V_4 ) -> V_154 ;
if ( ! ( V_154 & V_155 ) ||
( ( V_154 & V_155 ) && ( V_154 & V_156 ) ) )
V_40 -> V_157 += F_81 ( V_4 ) ;
}
static void F_82 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
if ( ! ( F_26 ( V_4 ) -> V_154 & ( V_155 | V_158 ) ) ) {
F_79 ( V_40 , V_4 ) ;
V_40 -> V_159 += F_81 ( V_4 ) ;
F_80 ( V_40 , V_4 ) ;
F_26 ( V_4 ) -> V_154 |= V_155 ;
}
}
void F_83 ( struct V_39 * V_40 , struct V_3 * V_4 )
{
F_79 ( V_40 , V_4 ) ;
F_80 ( V_40 , V_4 ) ;
if ( ! ( F_26 ( V_4 ) -> V_154 & ( V_155 | V_158 ) ) ) {
V_40 -> V_159 += F_81 ( V_4 ) ;
F_26 ( V_4 ) -> V_154 |= V_155 ;
}
}
static bool F_84 ( struct V_39 * V_40 , bool V_160 ,
T_2 V_161 , T_2 V_106 )
{
if ( F_62 ( V_106 , V_40 -> V_121 ) || ! F_55 ( V_161 , V_106 ) )
return false ;
if ( ! F_55 ( V_161 , V_40 -> V_121 ) )
return false ;
if ( F_62 ( V_161 , V_40 -> V_119 ) )
return true ;
if ( ! V_160 || ! V_40 -> V_145 )
return false ;
if ( F_62 ( V_106 , V_40 -> V_119 ) )
return false ;
if ( ! F_55 ( V_161 , V_40 -> V_145 ) )
return true ;
if ( ! F_62 ( V_106 , V_40 -> V_145 ) )
return false ;
return ! F_55 ( V_161 , V_106 - V_40 -> V_162 ) ;
}
static bool F_85 ( struct V_1 * V_2 , const struct V_3 * V_163 ,
struct V_164 * V_165 , int V_166 ,
T_2 V_167 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_168 = F_86 ( & V_165 [ 0 ] . V_161 ) ;
T_2 V_169 = F_86 ( & V_165 [ 0 ] . V_106 ) ;
bool V_170 = false ;
if ( F_55 ( V_168 , F_26 ( V_163 ) -> V_171 ) ) {
V_170 = true ;
F_74 ( V_40 ) ;
F_78 ( F_4 ( V_2 ) , V_172 ) ;
} else if ( V_166 > 1 ) {
T_2 V_173 = F_86 ( & V_165 [ 1 ] . V_106 ) ;
T_2 V_174 = F_86 ( & V_165 [ 1 ] . V_161 ) ;
if ( ! F_62 ( V_169 , V_173 ) &&
! F_55 ( V_168 , V_174 ) ) {
V_170 = true ;
F_74 ( V_40 ) ;
F_78 ( F_4 ( V_2 ) ,
V_175 ) ;
}
}
if ( V_170 && V_40 -> V_145 && V_40 -> V_146 > 0 &&
! F_62 ( V_169 , V_167 ) &&
F_62 ( V_169 , V_40 -> V_145 ) )
V_40 -> V_146 -- ;
return V_170 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_161 , T_2 V_106 )
{
int V_176 ;
bool V_177 ;
unsigned int V_178 ;
unsigned int V_80 ;
V_177 = ! F_62 ( V_161 , F_26 ( V_4 ) -> V_91 ) &&
! F_55 ( V_106 , F_26 ( V_4 ) -> V_106 ) ;
if ( F_81 ( V_4 ) > 1 && ! V_177 &&
F_62 ( F_26 ( V_4 ) -> V_106 , V_161 ) ) {
V_80 = F_88 ( V_4 ) ;
V_177 = ! F_62 ( V_161 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! V_177 ) {
V_178 = V_161 - F_26 ( V_4 ) -> V_91 ;
if ( V_178 < V_80 )
V_178 = V_80 ;
} else {
V_178 = V_106 - F_26 ( V_4 ) -> V_91 ;
if ( V_178 < V_80 )
return - V_179 ;
}
if ( V_178 > V_80 ) {
unsigned int V_180 = ( V_178 / V_80 ) * V_80 ;
if ( ! V_177 && V_180 < V_178 ) {
V_180 += V_80 ;
if ( V_180 >= V_4 -> V_5 )
return 0 ;
}
V_178 = V_180 ;
}
V_176 = F_89 ( V_2 , V_4 , V_178 , V_80 , V_181 ) ;
if ( V_176 < 0 )
return V_176 ;
}
return V_177 ;
}
static T_6 F_90 ( struct V_1 * V_2 ,
struct V_182 * V_183 , T_6 V_154 ,
T_2 V_161 , T_2 V_106 ,
int V_170 , int V_184 ,
const struct V_185 * V_186 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_187 = V_183 -> V_187 ;
if ( V_170 && ( V_154 & V_188 ) ) {
if ( V_40 -> V_145 && V_40 -> V_146 > 0 &&
F_62 ( V_106 , V_40 -> V_145 ) )
V_40 -> V_146 -- ;
if ( V_154 & V_158 )
V_183 -> V_148 = F_17 ( V_187 , V_183 -> V_148 ) ;
}
if ( ! F_62 ( V_106 , V_40 -> V_119 ) )
return V_154 ;
if ( ! ( V_154 & V_158 ) ) {
F_91 ( V_40 , V_154 , V_106 ,
V_186 , & V_183 -> V_189 ) ;
if ( V_154 & V_156 ) {
if ( V_154 & V_155 ) {
V_154 &= ~ ( V_155 | V_156 ) ;
V_40 -> V_159 -= V_184 ;
V_40 -> V_190 -= V_184 ;
}
} else {
if ( ! ( V_154 & V_188 ) ) {
if ( F_55 ( V_161 ,
F_92 ( V_40 ) ) )
V_183 -> V_148 = F_17 ( V_187 ,
V_183 -> V_148 ) ;
if ( ! F_62 ( V_106 , V_40 -> V_191 ) )
V_183 -> V_192 |= V_193 ;
if ( V_183 -> V_194 . V_195 == 0 )
V_183 -> V_194 = * V_186 ;
V_183 -> V_196 = * V_186 ;
}
if ( V_154 & V_155 ) {
V_154 &= ~ V_155 ;
V_40 -> V_159 -= V_184 ;
}
}
V_154 |= V_158 ;
V_183 -> V_192 |= V_197 ;
V_40 -> V_144 += V_184 ;
V_40 -> V_198 += V_184 ;
V_187 += V_184 ;
if ( ! F_73 ( V_40 ) && V_40 -> V_133 &&
F_55 ( V_161 , F_26 ( V_40 -> V_133 ) -> V_91 ) )
V_40 -> V_199 += V_184 ;
if ( V_187 > V_40 -> V_143 )
V_40 -> V_143 = V_187 ;
}
if ( V_170 && ( V_154 & V_156 ) ) {
V_154 &= ~ V_156 ;
V_40 -> V_190 -= V_184 ;
}
return V_154 ;
}
static bool F_93 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_182 * V_183 ,
unsigned int V_184 , int V_200 , int V_80 ,
bool V_170 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_201 = F_94 ( V_2 , V_4 ) ;
T_2 V_161 = F_26 ( V_4 ) -> V_91 ;
T_2 V_106 = V_161 + V_200 ;
F_95 ( ! V_184 ) ;
F_90 ( V_2 , V_183 , F_26 ( V_4 ) -> V_154 ,
V_161 , V_106 , V_170 , V_184 ,
& V_4 -> V_185 ) ;
F_96 ( V_2 , V_4 , V_183 -> V_122 ) ;
if ( V_4 == V_40 -> V_133 )
V_40 -> V_199 += V_184 ;
F_26 ( V_201 ) -> V_106 += V_200 ;
F_26 ( V_4 ) -> V_91 += V_200 ;
F_97 ( V_201 , V_184 ) ;
F_95 ( F_81 ( V_4 ) < V_184 ) ;
F_97 ( V_4 , - V_184 ) ;
if ( ! F_26 ( V_201 ) -> V_202 )
F_26 ( V_201 ) -> V_202 = V_80 ;
if ( F_81 ( V_4 ) <= 1 )
F_26 ( V_4 ) -> V_202 = 0 ;
F_26 ( V_201 ) -> V_154 |= ( F_26 ( V_4 ) -> V_154 & V_203 ) ;
if ( V_4 -> V_5 > 0 ) {
F_95 ( ! F_81 ( V_4 ) ) ;
F_78 ( F_4 ( V_2 ) , V_204 ) ;
return false ;
}
if ( V_4 == V_40 -> V_153 )
V_40 -> V_153 = V_201 ;
if ( V_4 == V_40 -> V_133 ) {
V_40 -> V_133 = V_201 ;
V_40 -> V_199 -= F_81 ( V_201 ) ;
}
F_26 ( V_201 ) -> V_205 |= F_26 ( V_4 ) -> V_205 ;
F_26 ( V_201 ) -> V_206 = F_26 ( V_4 ) -> V_206 ;
if ( F_26 ( V_4 ) -> V_205 & V_207 )
F_26 ( V_201 ) -> V_106 ++ ;
if ( V_4 == F_98 ( V_2 ) )
F_99 ( V_2 , V_4 ) ;
F_100 ( V_201 , V_4 ) ;
if ( F_11 ( F_26 ( V_201 ) -> V_208 . V_209 . V_195 ) )
F_26 ( V_201 ) -> V_208 . V_209 . V_195 = 0 ;
F_101 ( V_4 , V_2 ) ;
F_102 ( V_2 , V_4 ) ;
F_78 ( F_4 ( V_2 ) , V_210 ) ;
return true ;
}
static int F_103 ( const struct V_3 * V_4 )
{
return F_81 ( V_4 ) == 1 ? V_4 -> V_5 : F_88 ( V_4 ) ;
}
static int F_104 ( const struct V_3 * V_4 )
{
return ! F_105 ( V_4 ) && F_106 ( V_4 ) ;
}
static struct V_3 * F_107 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_182 * V_183 ,
T_2 V_161 , T_2 V_106 ,
bool V_170 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_201 ;
int V_80 ;
int V_184 = 0 ;
int V_5 ;
int V_177 ;
if ( ! F_108 ( V_2 ) )
goto V_211;
if ( ! V_170 &&
( F_26 ( V_4 ) -> V_154 & ( V_155 | V_156 ) ) == V_156 )
goto V_211;
if ( ! F_104 ( V_4 ) )
goto V_211;
if ( ! F_62 ( F_26 ( V_4 ) -> V_106 , V_40 -> V_119 ) )
goto V_211;
if ( F_11 ( V_4 == F_109 ( V_2 ) ) )
goto V_211;
V_201 = F_94 ( V_2 , V_4 ) ;
if ( ( F_26 ( V_201 ) -> V_154 & V_212 ) != V_158 )
goto V_211;
if ( ! F_110 ( V_201 ) )
goto V_211;
V_177 = ! F_62 ( V_161 , F_26 ( V_4 ) -> V_91 ) &&
! F_55 ( V_106 , F_26 ( V_4 ) -> V_106 ) ;
if ( V_177 ) {
V_5 = V_4 -> V_5 ;
V_184 = F_81 ( V_4 ) ;
V_80 = F_103 ( V_4 ) ;
if ( V_80 != F_103 ( V_201 ) )
goto V_211;
} else {
if ( ! F_62 ( F_26 ( V_4 ) -> V_106 , V_161 ) )
goto V_213;
if ( F_81 ( V_4 ) <= 1 )
goto V_213;
V_177 = ! F_62 ( V_161 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! V_177 ) {
goto V_211;
}
V_5 = V_106 - F_26 ( V_4 ) -> V_91 ;
F_95 ( V_5 < 0 ) ;
F_95 ( V_5 > V_4 -> V_5 ) ;
V_80 = F_88 ( V_4 ) ;
if ( V_80 != F_103 ( V_201 ) )
goto V_211;
if ( V_5 == V_80 ) {
V_184 = 1 ;
} else if ( V_5 < V_80 ) {
goto V_213;
} else {
V_184 = V_5 / V_80 ;
V_5 = V_184 * V_80 ;
}
}
if ( ! F_62 ( F_26 ( V_4 ) -> V_91 + V_5 , V_40 -> V_119 ) )
goto V_211;
if ( ! F_111 ( V_201 , V_4 , V_5 ) )
goto V_211;
if ( ! F_93 ( V_2 , V_4 , V_183 , V_184 , V_5 , V_80 , V_170 ) )
goto V_214;
if ( V_201 == F_112 ( V_2 ) )
goto V_214;
V_4 = F_113 ( V_2 , V_201 ) ;
if ( ! F_104 ( V_4 ) ||
( V_4 == F_114 ( V_2 ) ) ||
( ( F_26 ( V_4 ) -> V_154 & V_212 ) != V_158 ) ||
( V_80 != F_103 ( V_4 ) ) )
goto V_214;
V_5 = V_4 -> V_5 ;
if ( F_111 ( V_201 , V_4 , V_5 ) ) {
V_184 += F_81 ( V_4 ) ;
F_93 ( V_2 , V_4 , V_183 , F_81 ( V_4 ) , V_5 , V_80 , 0 ) ;
}
V_214:
V_183 -> V_187 += V_184 ;
return V_201 ;
V_213:
return V_4 ;
V_211:
F_78 ( F_4 ( V_2 ) , V_215 ) ;
return NULL ;
}
static struct V_3 * F_115 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_216 * V_217 ,
struct V_182 * V_183 ,
T_2 V_161 , T_2 V_106 ,
bool V_218 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_219 ;
F_116 (skb, sk) {
int V_177 = 0 ;
bool V_170 = V_218 ;
if ( V_4 == F_114 ( V_2 ) )
break;
if ( ! F_55 ( F_26 ( V_4 ) -> V_91 , V_106 ) )
break;
if ( V_217 &&
F_55 ( F_26 ( V_4 ) -> V_91 , V_217 -> V_106 ) ) {
V_177 = F_87 ( V_2 , V_4 ,
V_217 -> V_161 ,
V_217 -> V_106 ) ;
if ( V_177 > 0 )
V_170 = true ;
}
if ( V_177 <= 0 ) {
V_219 = F_107 ( V_2 , V_4 , V_183 ,
V_161 , V_106 , V_170 ) ;
if ( V_219 ) {
if ( V_219 != V_4 ) {
V_4 = V_219 ;
continue;
}
V_177 = 0 ;
} else {
V_177 = F_87 ( V_2 , V_4 ,
V_161 ,
V_106 ) ;
}
}
if ( F_11 ( V_177 < 0 ) )
break;
if ( V_177 ) {
F_26 ( V_4 ) -> V_154 =
F_90 ( V_2 ,
V_183 ,
F_26 ( V_4 ) -> V_154 ,
F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_106 ,
V_170 ,
F_81 ( V_4 ) ,
& V_4 -> V_185 ) ;
F_96 ( V_2 , V_4 , V_183 -> V_122 ) ;
if ( ! F_55 ( F_26 ( V_4 ) -> V_91 ,
F_92 ( V_40 ) ) )
F_99 ( V_2 , V_4 ) ;
}
V_183 -> V_187 += F_81 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_117 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_182 * V_183 ,
T_2 V_220 )
{
F_116 (skb, sk) {
if ( V_4 == F_114 ( V_2 ) )
break;
if ( F_62 ( F_26 ( V_4 ) -> V_106 , V_220 ) )
break;
V_183 -> V_187 += F_81 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_118 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_216 * V_217 ,
struct V_182 * V_183 ,
T_2 V_220 )
{
if ( ! V_217 )
return V_4 ;
if ( F_55 ( V_217 -> V_161 , V_220 ) ) {
V_4 = F_117 ( V_4 , V_2 , V_183 , V_217 -> V_161 ) ;
V_4 = F_115 ( V_4 , V_2 , NULL , V_183 ,
V_217 -> V_161 , V_217 -> V_106 ,
1 ) ;
}
return V_4 ;
}
static int F_119 ( const struct V_39 * V_40 , const struct V_216 * V_221 )
{
return V_221 < V_40 -> V_222 + F_120 ( V_40 -> V_222 ) ;
}
static int
F_121 ( struct V_1 * V_2 , const struct V_3 * V_163 ,
T_2 V_167 , struct V_182 * V_183 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
const unsigned char * V_223 = ( F_12 ( V_163 ) +
F_26 ( V_163 ) -> V_154 ) ;
struct V_164 * V_224 = (struct V_164 * ) ( V_223 + 2 ) ;
struct V_216 V_165 [ V_225 ] ;
struct V_216 * V_221 ;
struct V_3 * V_4 ;
int V_166 = F_17 ( V_225 , ( V_223 [ 1 ] - V_226 ) >> 3 ) ;
int V_227 ;
bool V_228 = false ;
int V_229 , V_230 ;
int V_231 ;
V_183 -> V_192 = 0 ;
V_183 -> V_148 = V_40 -> V_127 ;
if ( ! V_40 -> V_144 ) {
if ( F_122 ( V_40 -> V_143 ) )
V_40 -> V_143 = 0 ;
F_123 ( V_2 ) ;
}
V_228 = F_85 ( V_2 , V_163 , V_224 ,
V_166 , V_167 ) ;
if ( V_228 ) {
V_183 -> V_192 |= V_232 ;
V_40 -> V_198 ++ ;
}
if ( F_55 ( F_26 ( V_163 ) -> V_171 , V_167 - V_40 -> V_162 ) )
return 0 ;
if ( ! V_40 -> V_127 )
goto V_214;
V_227 = 0 ;
V_231 = 0 ;
for ( V_229 = 0 ; V_229 < V_166 ; V_229 ++ ) {
bool V_170 = ! V_229 && V_228 ;
V_165 [ V_227 ] . V_161 = F_86 ( & V_224 [ V_229 ] . V_161 ) ;
V_165 [ V_227 ] . V_106 = F_86 ( & V_224 [ V_229 ] . V_106 ) ;
if ( ! F_84 ( V_40 , V_170 ,
V_165 [ V_227 ] . V_161 ,
V_165 [ V_227 ] . V_106 ) ) {
int V_139 ;
if ( V_170 ) {
if ( ! V_40 -> V_145 )
V_139 = V_233 ;
else
V_139 = V_234 ;
} else {
if ( ( F_26 ( V_163 ) -> V_171 != V_40 -> V_119 ) &&
! F_62 ( V_165 [ V_227 ] . V_106 , V_40 -> V_119 ) )
continue;
V_139 = V_235 ;
}
F_78 ( F_4 ( V_2 ) , V_139 ) ;
if ( V_229 == 0 )
V_231 = - 1 ;
continue;
}
if ( ! F_62 ( V_165 [ V_227 ] . V_106 , V_167 ) )
continue;
V_227 ++ ;
}
for ( V_229 = V_227 - 1 ; V_229 > 0 ; V_229 -- ) {
for ( V_230 = 0 ; V_230 < V_229 ; V_230 ++ ) {
if ( F_62 ( V_165 [ V_230 ] . V_161 , V_165 [ V_230 + 1 ] . V_161 ) ) {
F_124 ( V_165 [ V_230 ] , V_165 [ V_230 + 1 ] ) ;
if ( V_230 == V_231 )
V_231 = V_230 + 1 ;
}
}
}
V_4 = F_109 ( V_2 ) ;
V_183 -> V_187 = 0 ;
V_229 = 0 ;
if ( ! V_40 -> V_144 ) {
V_221 = V_40 -> V_222 + F_120 ( V_40 -> V_222 ) ;
} else {
V_221 = V_40 -> V_222 ;
while ( F_119 ( V_40 , V_221 ) && ! V_221 -> V_161 &&
! V_221 -> V_106 )
V_221 ++ ;
}
while ( V_229 < V_227 ) {
T_2 V_161 = V_165 [ V_229 ] . V_161 ;
T_2 V_106 = V_165 [ V_229 ] . V_106 ;
bool V_170 = ( V_228 && ( V_229 == V_231 ) ) ;
struct V_216 * V_217 = NULL ;
if ( V_228 && ( ( V_229 + 1 ) == V_231 ) )
V_217 = & V_165 [ V_229 + 1 ] ;
while ( F_119 ( V_40 , V_221 ) &&
! F_55 ( V_161 , V_221 -> V_106 ) )
V_221 ++ ;
if ( F_119 ( V_40 , V_221 ) && ! V_170 &&
F_62 ( V_106 , V_221 -> V_161 ) ) {
if ( F_55 ( V_161 , V_221 -> V_161 ) ) {
V_4 = F_117 ( V_4 , V_2 , V_183 ,
V_161 ) ;
V_4 = F_115 ( V_4 , V_2 , V_217 ,
V_183 ,
V_161 ,
V_221 -> V_161 ,
V_170 ) ;
}
if ( ! F_62 ( V_106 , V_221 -> V_106 ) )
goto V_236;
V_4 = F_118 ( V_4 , V_2 , V_217 ,
V_183 ,
V_221 -> V_106 ) ;
if ( F_92 ( V_40 ) == V_221 -> V_106 ) {
V_4 = F_98 ( V_2 ) ;
if ( ! V_4 )
break;
V_183 -> V_187 = V_40 -> V_143 ;
V_221 ++ ;
goto V_237;
}
V_4 = F_117 ( V_4 , V_2 , V_183 , V_221 -> V_106 ) ;
V_221 ++ ;
continue;
}
if ( ! F_55 ( V_161 , F_92 ( V_40 ) ) ) {
V_4 = F_98 ( V_2 ) ;
if ( ! V_4 )
break;
V_183 -> V_187 = V_40 -> V_143 ;
}
V_4 = F_117 ( V_4 , V_2 , V_183 , V_161 ) ;
V_237:
V_4 = F_115 ( V_4 , V_2 , V_217 , V_183 ,
V_161 , V_106 , V_170 ) ;
V_236:
V_229 ++ ;
}
for ( V_229 = 0 ; V_229 < F_120 ( V_40 -> V_222 ) - V_227 ; V_229 ++ ) {
V_40 -> V_222 [ V_229 ] . V_161 = 0 ;
V_40 -> V_222 [ V_229 ] . V_106 = 0 ;
}
for ( V_230 = 0 ; V_230 < V_227 ; V_230 ++ )
V_40 -> V_222 [ V_229 ++ ] = V_165 [ V_230 ] ;
if ( ( V_183 -> V_148 < V_40 -> V_143 ) &&
( ( F_8 ( V_2 ) -> V_142 != V_238 ) || V_40 -> V_145 ) )
F_75 ( V_2 , V_40 -> V_143 - V_183 -> V_148 , 0 ) ;
F_125 ( V_40 ) ;
V_214:
#if V_141 > 0
F_122 ( ( int ) V_40 -> V_144 < 0 ) ;
F_122 ( ( int ) V_40 -> V_159 < 0 ) ;
F_122 ( ( int ) V_40 -> V_190 < 0 ) ;
F_122 ( ( int ) F_126 ( V_40 ) < 0 ) ;
#endif
return V_183 -> V_192 ;
}
static bool F_127 ( struct V_39 * V_40 )
{
T_2 V_239 ;
V_239 = F_47 ( V_40 -> V_159 , 1U ) ;
V_239 = F_17 ( V_239 , V_40 -> V_127 ) ;
if ( ( V_40 -> V_144 + V_239 ) > V_40 -> V_127 ) {
V_40 -> V_144 = V_40 -> V_127 - V_239 ;
return true ;
}
return false ;
}
static void F_128 ( struct V_1 * V_2 , const int V_240 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_127 ( V_40 ) )
F_75 ( V_2 , V_40 -> V_127 + V_240 , 0 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_241 = V_40 -> V_144 ;
V_40 -> V_144 ++ ;
F_128 ( V_2 , 0 ) ;
if ( V_40 -> V_144 > V_241 )
V_40 -> V_198 ++ ;
F_125 ( V_40 ) ;
}
static void F_130 ( struct V_1 * V_2 , int V_242 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_242 > 0 ) {
V_40 -> V_198 += F_34 ( int , V_242 - V_40 -> V_144 , 1 ) ;
if ( V_242 - 1 >= V_40 -> V_144 )
V_40 -> V_144 = 0 ;
else
V_40 -> V_144 -= V_242 - 1 ;
}
F_128 ( V_2 , V_242 ) ;
F_125 ( V_40 ) ;
}
static inline void F_131 ( struct V_39 * V_40 )
{
V_40 -> V_144 = 0 ;
}
void F_132 ( struct V_39 * V_40 )
{
V_40 -> V_190 = 0 ;
V_40 -> V_159 = 0 ;
V_40 -> V_145 = 0 ;
V_40 -> V_146 = - 1 ;
V_40 -> V_143 = 0 ;
V_40 -> V_144 = 0 ;
}
static inline void F_133 ( struct V_39 * V_40 )
{
V_40 -> V_145 = V_40 -> V_119 ;
V_40 -> V_146 = V_40 -> V_190 ? : - 1 ;
}
void F_134 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_243 * V_243 = F_4 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_244 = V_13 -> V_142 < V_245 ;
bool V_246 ;
bool V_247 ;
if ( V_13 -> V_142 <= V_248 ||
! F_62 ( V_40 -> V_191 , V_40 -> V_119 ) ||
( V_13 -> V_142 == V_238 && ! V_13 -> V_249 ) ) {
V_40 -> V_250 = F_135 ( V_2 ) ;
V_40 -> V_124 = V_13 -> V_58 -> V_251 ( V_2 ) ;
F_28 ( V_2 , V_252 ) ;
F_133 ( V_40 ) ;
}
V_40 -> V_68 = 1 ;
V_40 -> V_253 = 0 ;
V_40 -> V_94 = V_90 ;
V_40 -> V_190 = 0 ;
V_40 -> V_159 = 0 ;
if ( F_77 ( V_40 ) )
F_131 ( V_40 ) ;
V_4 = F_109 ( V_2 ) ;
V_246 = V_4 && ( F_26 ( V_4 ) -> V_154 & V_158 ) ;
if ( V_246 ) {
F_78 ( F_4 ( V_2 ) , V_254 ) ;
V_40 -> V_144 = 0 ;
V_40 -> V_143 = 0 ;
}
F_136 ( V_40 ) ;
F_137 (skb, sk) {
if ( V_4 == F_114 ( V_2 ) )
break;
V_247 = ( ! ( F_26 ( V_4 ) -> V_154 & V_158 ) ||
V_246 ) ;
if ( V_247 )
F_80 ( V_40 , V_4 ) ;
F_26 ( V_4 ) -> V_154 &= ( ~ V_212 ) | V_158 ;
if ( V_247 ) {
F_26 ( V_4 ) -> V_154 &= ~ V_158 ;
F_26 ( V_4 ) -> V_154 |= V_155 ;
V_40 -> V_159 += F_81 ( V_4 ) ;
}
}
F_125 ( V_40 ) ;
if ( V_13 -> V_142 <= V_248 &&
V_40 -> V_144 >= V_243 -> V_255 . V_256 )
V_40 -> V_69 = F_10 (unsigned int, tp->reordering,
net->ipv4.sysctl_tcp_reordering) ;
F_138 ( V_2 , V_238 ) ;
V_40 -> V_191 = V_40 -> V_121 ;
F_22 ( V_40 ) ;
V_40 -> V_257 = V_258 &&
( V_244 || V_13 -> V_249 ) &&
! F_8 ( V_2 ) -> V_259 . V_260 ;
}
static bool F_139 ( struct V_1 * V_2 , int V_192 )
{
if ( V_192 & V_261 ) {
struct V_39 * V_40 = F_15 ( V_2 ) ;
unsigned long V_262 = F_47 ( F_140 ( V_40 -> V_115 >> 4 ) ,
F_141 ( 10 ) ) ;
F_142 ( V_2 , V_263 ,
V_262 , V_264 ) ;
return true ;
}
return false ;
}
static inline int F_143 ( const struct V_39 * V_40 )
{
return F_77 ( V_40 ) ? V_40 -> V_144 + 1 : V_40 -> V_143 ;
}
static inline int F_144 ( const struct V_39 * V_40 )
{
return F_73 ( V_40 ) ? V_40 -> V_143 : V_40 -> V_144 + 1 ;
}
static bool F_145 ( struct V_1 * V_2 , int V_192 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_159 )
return true ;
if ( F_144 ( V_40 ) > V_40 -> V_69 )
return true ;
return false ;
}
static void F_146 ( struct V_1 * V_2 , int V_265 , int V_266 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
int V_267 , V_268 , V_157 ;
unsigned int V_80 ;
const T_2 V_269 = F_147 ( V_40 ) ? V_40 -> V_121 : V_40 -> V_191 ;
F_122 ( V_265 > V_40 -> V_127 ) ;
if ( V_40 -> V_133 ) {
V_4 = V_40 -> V_133 ;
V_267 = V_40 -> V_199 ;
if ( V_266 && V_4 != F_109 ( V_2 ) )
return;
} else {
V_4 = F_109 ( V_2 ) ;
V_267 = 0 ;
}
F_116 (skb, sk) {
if ( V_4 == F_114 ( V_2 ) )
break;
V_40 -> V_133 = V_4 ;
V_40 -> V_199 = V_267 ;
if ( F_62 ( F_26 ( V_4 ) -> V_106 , V_269 ) )
break;
V_268 = V_267 ;
if ( F_73 ( V_40 ) || F_77 ( V_40 ) ||
( F_26 ( V_4 ) -> V_154 & V_158 ) )
V_267 += F_81 ( V_4 ) ;
if ( V_267 > V_265 ) {
if ( ( F_147 ( V_40 ) && ! F_73 ( V_40 ) ) ||
( F_26 ( V_4 ) -> V_154 & V_158 ) ||
( V_268 >= V_265 ) )
break;
V_80 = F_88 ( V_4 ) ;
V_157 = ( V_265 - V_268 ) * V_80 ;
if ( V_157 < V_4 -> V_5 &&
F_89 ( V_2 , V_4 , V_157 , V_80 , V_181 ) < 0 )
break;
V_267 = V_265 ;
}
F_82 ( V_40 , V_4 ) ;
if ( V_266 )
break;
}
F_125 ( V_40 ) ;
}
static void F_148 ( struct V_1 * V_2 , int V_270 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_77 ( V_40 ) ) {
F_146 ( V_2 , 1 , 1 ) ;
} else if ( F_73 ( V_40 ) ) {
int V_157 = V_40 -> V_143 - V_40 -> V_69 ;
if ( V_157 <= 0 )
V_157 = 1 ;
F_146 ( V_2 , V_157 , 0 ) ;
} else {
int V_271 = V_40 -> V_144 - V_40 -> V_69 ;
if ( V_271 >= 0 )
F_146 ( V_2 , V_271 , 0 ) ;
else if ( V_270 )
F_146 ( V_2 , 1 , 1 ) ;
}
}
static bool F_149 ( const struct V_39 * V_40 , T_2 V_272 )
{
return V_40 -> V_62 . V_273 && V_40 -> V_62 . V_105 &&
F_55 ( V_40 -> V_62 . V_105 , V_272 ) ;
}
static bool F_150 ( const struct V_39 * V_40 ,
const struct V_3 * V_4 )
{
return ( F_26 ( V_4 ) -> V_154 & V_188 ) &&
F_149 ( V_40 , F_151 ( V_4 ) ) ;
}
static inline bool F_152 ( const struct V_39 * V_40 )
{
return ! V_40 -> V_274 ||
F_149 ( V_40 , V_40 -> V_274 ) ;
}
static bool F_153 ( const struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_40 -> V_190 )
return true ;
V_4 = F_109 ( V_2 ) ;
if ( F_11 ( V_4 && F_26 ( V_4 ) -> V_154 & V_203 ) )
return true ;
return false ;
}
static void F_154 ( struct V_1 * V_2 , const char * V_275 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_276 * V_277 = F_155 ( V_2 ) ;
if ( V_2 -> V_278 == V_279 ) {
F_76 ( L_4 ,
V_275 ,
& V_277 -> V_280 , F_156 ( V_277 -> V_281 ) ,
V_40 -> V_68 , F_157 ( V_40 ) ,
V_40 -> V_124 , V_40 -> V_250 ,
V_40 -> V_127 ) ;
}
#if F_158 ( V_282 )
else if ( V_2 -> V_278 == V_283 ) {
F_76 ( L_5 ,
V_275 ,
& V_2 -> V_284 , F_156 ( V_277 -> V_281 ) ,
V_40 -> V_68 , F_157 ( V_40 ) ,
V_40 -> V_124 , V_40 -> V_250 ,
V_40 -> V_127 ) ;
}
#endif
}
static void F_159 ( struct V_1 * V_2 , bool V_285 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_285 ) {
struct V_3 * V_4 ;
F_137 (skb, sk) {
if ( V_4 == F_114 ( V_2 ) )
break;
F_26 ( V_4 ) -> V_154 &= ~ V_155 ;
}
V_40 -> V_159 = 0 ;
F_136 ( V_40 ) ;
}
if ( V_40 -> V_250 ) {
const struct V_12 * V_13 = F_8 ( V_2 ) ;
V_40 -> V_68 = V_13 -> V_58 -> V_286 ( V_2 ) ;
if ( V_40 -> V_250 > V_40 -> V_124 ) {
V_40 -> V_124 = V_40 -> V_250 ;
F_24 ( V_40 ) ;
}
}
V_40 -> V_94 = V_90 ;
V_40 -> V_145 = 0 ;
}
static inline bool F_160 ( const struct V_39 * V_40 )
{
return V_40 -> V_145 && ( ! V_40 -> V_146 || F_152 ( V_40 ) ) ;
}
static bool F_161 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_160 ( V_40 ) ) {
int V_139 ;
F_154 ( V_2 , F_8 ( V_2 ) -> V_142 == V_238 ? L_6 : L_7 ) ;
F_159 ( V_2 , false ) ;
if ( F_8 ( V_2 ) -> V_142 == V_238 )
V_139 = V_287 ;
else
V_139 = V_288 ;
F_78 ( F_4 ( V_2 ) , V_139 ) ;
}
if ( V_40 -> V_119 == V_40 -> V_191 && F_77 ( V_40 ) ) {
if ( ! F_153 ( V_2 ) )
V_40 -> V_274 = 0 ;
return true ;
}
F_138 ( V_2 , V_289 ) ;
return false ;
}
static bool F_162 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_145 && ! V_40 -> V_146 ) {
F_154 ( V_2 , L_8 ) ;
F_159 ( V_2 , false ) ;
F_78 ( F_4 ( V_2 ) , V_290 ) ;
return true ;
}
return false ;
}
static bool F_163 ( struct V_1 * V_2 , bool V_291 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_291 || F_160 ( V_40 ) ) {
F_159 ( V_2 , true ) ;
F_154 ( V_2 , L_9 ) ;
F_78 ( F_4 ( V_2 ) , V_287 ) ;
if ( V_291 )
F_78 ( F_4 ( V_2 ) ,
V_292 ) ;
F_8 ( V_2 ) -> V_249 = 0 ;
if ( V_291 || F_147 ( V_40 ) )
F_138 ( V_2 , V_289 ) ;
return true ;
}
return false ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
V_40 -> V_191 = V_40 -> V_121 ;
V_40 -> V_293 = 0 ;
V_40 -> V_253 = 0 ;
V_40 -> V_294 = V_40 -> V_68 ;
V_40 -> V_295 = 0 ;
V_40 -> V_296 = 0 ;
V_40 -> V_124 = F_8 ( V_2 ) -> V_58 -> V_251 ( V_2 ) ;
F_22 ( V_40 ) ;
}
void F_165 ( struct V_1 * V_2 , int V_297 , int V_192 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_298 = 0 ;
int V_299 = V_40 -> V_124 - F_126 ( V_40 ) ;
if ( V_297 <= 0 || F_166 ( ! V_40 -> V_294 ) )
return;
V_40 -> V_295 += V_297 ;
if ( V_299 < 0 ) {
T_3 V_300 = ( T_3 ) V_40 -> V_124 * V_40 -> V_295 +
V_40 -> V_294 - 1 ;
V_298 = F_167 ( V_300 , V_40 -> V_294 ) - V_40 -> V_296 ;
} else if ( ( V_192 & V_301 ) &&
! ( V_192 & V_302 ) ) {
V_298 = F_10 ( int , V_299 ,
F_34 ( int , V_40 -> V_295 - V_40 -> V_296 ,
V_297 ) + 1 ) ;
} else {
V_298 = F_17 ( V_299 , V_297 ) ;
}
V_298 = F_47 ( V_298 , ( V_40 -> V_296 ? 0 : 1 ) ) ;
V_40 -> V_68 = F_126 ( V_40 ) + V_298 ;
}
static inline void F_168 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_58 -> V_303 )
return;
if ( F_8 ( V_2 ) -> V_142 == V_304 ||
( V_40 -> V_145 && V_40 -> V_124 < V_305 ) ) {
V_40 -> V_68 = V_40 -> V_124 ;
V_40 -> V_94 = V_90 ;
}
F_28 ( V_2 , V_306 ) ;
}
void F_169 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
V_40 -> V_250 = 0 ;
if ( F_8 ( V_2 ) -> V_142 < V_304 ) {
V_40 -> V_145 = 0 ;
F_164 ( V_2 ) ;
F_138 ( V_2 , V_304 ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_183 = V_289 ;
if ( F_157 ( V_40 ) || F_153 ( V_2 ) )
V_183 = V_248 ;
if ( F_8 ( V_2 ) -> V_142 != V_183 ) {
F_138 ( V_2 , V_183 ) ;
V_40 -> V_191 = V_40 -> V_121 ;
}
}
static void F_171 ( struct V_1 * V_2 , int V_192 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_125 ( V_40 ) ;
if ( ! F_153 ( V_2 ) )
V_40 -> V_274 = 0 ;
if ( V_192 & V_307 )
F_169 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_142 != V_304 ) {
F_170 ( V_2 ) ;
}
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_259 . V_308 = V_13 -> V_259 . V_260 - 1 ;
V_13 -> V_259 . V_260 = 0 ;
F_78 ( F_4 ( V_2 ) , V_309 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
V_40 -> V_250 = F_135 ( V_2 ) ;
V_40 -> V_68 = V_40 -> V_68 *
F_174 ( V_2 , V_40 -> V_64 ) /
V_13 -> V_259 . V_260 ;
V_40 -> V_253 = 0 ;
V_40 -> V_94 = V_90 ;
V_40 -> V_124 = F_135 ( V_2 ) ;
V_13 -> V_259 . V_310 = V_13 -> V_259 . V_260 ;
V_13 -> V_259 . V_260 = 0 ;
F_175 ( V_2 , V_13 -> V_311 ) ;
F_78 ( F_4 ( V_2 ) , V_312 ) ;
}
void F_176 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_80 = F_177 ( V_2 ) ;
T_2 V_313 = V_40 -> V_159 ;
F_137 (skb, sk) {
if ( V_4 == F_114 ( V_2 ) )
break;
if ( F_103 ( V_4 ) > V_80 &&
! ( F_26 ( V_4 ) -> V_154 & V_158 ) ) {
if ( F_26 ( V_4 ) -> V_154 & V_156 ) {
F_26 ( V_4 ) -> V_154 &= ~ V_156 ;
V_40 -> V_190 -= F_81 ( V_4 ) ;
}
F_83 ( V_40 , V_4 ) ;
}
}
F_178 ( V_40 ) ;
if ( V_313 == V_40 -> V_159 )
return;
if ( F_77 ( V_40 ) )
F_127 ( V_40 ) ;
F_125 ( V_40 ) ;
if ( V_13 -> V_142 != V_238 ) {
V_40 -> V_191 = V_40 -> V_121 ;
V_40 -> V_124 = F_135 ( V_2 ) ;
V_40 -> V_250 = 0 ;
V_40 -> V_145 = 0 ;
F_138 ( V_2 , V_238 ) ;
}
F_179 ( V_2 ) ;
}
void F_180 ( struct V_1 * V_2 , bool V_314 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_139 ;
if ( F_77 ( V_40 ) )
V_139 = V_315 ;
else
V_139 = V_316 ;
F_78 ( F_4 ( V_2 ) , V_139 ) ;
V_40 -> V_250 = 0 ;
F_133 ( V_40 ) ;
if ( ! F_181 ( V_2 ) ) {
if ( ! V_314 )
V_40 -> V_250 = F_135 ( V_2 ) ;
F_164 ( V_2 ) ;
}
F_138 ( V_2 , V_245 ) ;
}
static void F_182 ( struct V_1 * V_2 , int V_192 , bool V_317 ,
int * V_318 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_319 = ! F_55 ( V_40 -> V_119 , V_40 -> V_191 ) ;
if ( ( V_192 & V_320 ) &&
F_163 ( V_2 , false ) )
return;
if ( ( V_192 & V_193 ) &&
F_163 ( V_2 , V_40 -> V_145 ) )
return;
if ( V_40 -> V_257 ) {
if ( F_62 ( V_40 -> V_121 , V_40 -> V_191 ) ) {
if ( V_192 & V_197 || V_317 )
V_40 -> V_257 = 0 ;
} else if ( V_192 & V_320 && ! V_319 ) {
V_40 -> V_191 = V_40 -> V_121 ;
if ( F_114 ( V_2 ) &&
F_62 ( F_183 ( V_40 ) , V_40 -> V_121 ) ) {
* V_318 = V_321 ;
return;
}
V_40 -> V_257 = 0 ;
}
}
if ( V_319 ) {
F_161 ( V_2 ) ;
return;
}
if ( F_77 ( V_40 ) ) {
if ( F_62 ( V_40 -> V_121 , V_40 -> V_191 ) && V_317 )
F_129 ( V_2 ) ;
else if ( V_192 & V_320 )
F_131 ( V_40 ) ;
}
* V_318 = V_322 ;
}
static bool F_184 ( struct V_1 * V_2 , const int V_242 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_145 && F_152 ( V_40 ) ) {
F_75 ( V_2 , F_143 ( V_40 ) + V_242 , 1 ) ;
if ( V_40 -> V_190 )
return true ;
if ( ! F_153 ( V_2 ) )
V_40 -> V_274 = 0 ;
F_154 ( V_2 , L_10 ) ;
F_159 ( V_2 , true ) ;
F_78 ( F_4 ( V_2 ) , V_323 ) ;
F_170 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_185 ( struct V_1 * V_2 , int * V_324 ,
const struct V_185 * V_189 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_325 & V_326 ) {
T_2 V_327 = V_40 -> V_190 ;
F_186 ( V_2 , V_189 ) ;
if ( V_327 > V_40 -> V_190 )
* V_324 |= V_302 ;
}
}
static void F_187 ( struct V_1 * V_2 , const int V_242 ,
bool V_317 , int * V_324 , int * V_318 ,
const struct V_185 * V_189 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_270 = 0 , V_192 = * V_324 ;
bool V_328 = V_317 || ( ( V_192 & V_197 ) &&
( F_143 ( V_40 ) > V_40 -> V_69 ) ) ;
if ( F_122 ( ! V_40 -> V_127 && V_40 -> V_144 ) )
V_40 -> V_144 = 0 ;
if ( F_122 ( ! V_40 -> V_144 && V_40 -> V_143 ) )
V_40 -> V_143 = 0 ;
if ( V_192 & V_307 )
V_40 -> V_250 = 0 ;
if ( F_139 ( V_2 , V_192 ) )
return;
F_125 ( V_40 ) ;
if ( V_13 -> V_142 == V_289 ) {
F_122 ( V_40 -> V_190 != 0 ) ;
V_40 -> V_274 = 0 ;
} else if ( ! F_55 ( V_40 -> V_119 , V_40 -> V_191 ) ) {
switch ( V_13 -> V_142 ) {
case V_304 :
if ( V_40 -> V_119 != V_40 -> V_191 ) {
F_168 ( V_2 ) ;
F_138 ( V_2 , V_289 ) ;
}
break;
case V_245 :
if ( F_77 ( V_40 ) )
F_131 ( V_40 ) ;
if ( F_161 ( V_2 ) )
return;
F_168 ( V_2 ) ;
break;
}
}
switch ( V_13 -> V_142 ) {
case V_245 :
if ( ! ( V_192 & V_320 ) ) {
if ( F_77 ( V_40 ) && V_317 )
F_129 ( V_2 ) ;
} else {
if ( F_184 ( V_2 , V_242 ) )
return;
V_328 = F_77 ( V_40 ) ||
F_143 ( V_40 ) > V_40 -> V_69 ;
}
if ( F_162 ( V_2 ) ) {
F_170 ( V_2 ) ;
return;
}
F_185 ( V_2 , V_324 , V_189 ) ;
break;
case V_238 :
F_182 ( V_2 , V_192 , V_317 , V_318 ) ;
F_185 ( V_2 , V_324 , V_189 ) ;
if ( ! ( V_13 -> V_142 == V_289 ||
( * V_324 & V_302 ) ) )
return;
default:
if ( F_77 ( V_40 ) ) {
if ( V_192 & V_320 )
F_131 ( V_40 ) ;
if ( V_317 )
F_129 ( V_2 ) ;
}
if ( V_13 -> V_142 <= V_248 )
F_162 ( V_2 ) ;
F_185 ( V_2 , V_324 , V_189 ) ;
if ( ! F_145 ( V_2 , V_192 ) ) {
F_171 ( V_2 , V_192 ) ;
return;
}
if ( V_13 -> V_142 < V_304 &&
V_13 -> V_259 . V_260 &&
V_40 -> V_119 == V_40 -> V_329 . V_330 ) {
F_172 ( V_2 ) ;
V_40 -> V_68 ++ ;
F_176 ( V_2 ) ;
return;
}
F_180 ( V_2 , ( V_192 & V_307 ) ) ;
V_270 = 1 ;
}
if ( V_328 )
F_148 ( V_2 , V_270 ) ;
* V_318 = V_322 ;
}
static void F_188 ( struct V_1 * V_2 , T_2 V_331 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_332 = V_333 * V_334 ;
F_189 ( & V_40 -> V_335 , V_332 , V_90 ,
V_331 ? : F_190 ( 1 ) ) ;
}
static inline bool F_191 ( struct V_1 * V_2 , const int V_192 ,
long V_336 , long V_337 ,
long V_338 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_336 < 0 )
V_336 = V_337 ;
if ( V_336 < 0 && V_40 -> V_62 . V_273 && V_40 -> V_62 . V_105 &&
V_192 & V_339 )
V_336 = V_338 = F_190 ( V_90 -
V_40 -> V_62 . V_105 ) ;
if ( V_336 < 0 )
return false ;
F_188 ( V_2 , V_338 ) ;
F_61 ( V_2 , V_336 ) ;
F_68 ( V_2 ) ;
F_8 ( V_2 ) -> V_340 = 0 ;
return true ;
}
void F_192 ( struct V_1 * V_2 , struct V_341 * V_342 )
{
long V_331 = - 1L ;
if ( V_342 && ! V_342 -> V_343 && F_193 ( V_342 ) -> V_344 . V_195 ) {
struct V_185 V_110 ;
F_194 ( & V_110 ) ;
V_331 = F_195 ( & V_110 , & F_193 ( V_342 ) -> V_344 ) ;
}
F_191 ( V_2 , V_345 , V_331 , - 1L , V_331 ) ;
}
static void F_196 ( struct V_1 * V_2 , T_2 V_346 , T_2 V_242 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
V_13 -> V_58 -> V_347 ( V_2 , V_346 , V_242 ) ;
F_15 ( V_2 ) -> V_94 = V_90 ;
}
void F_197 ( struct V_1 * V_2 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_40 -> V_348 )
return;
if ( ! V_40 -> V_127 ) {
F_198 ( V_2 , V_263 ) ;
} else {
T_2 V_349 = F_8 ( V_2 ) -> V_112 ;
if ( V_13 -> V_350 == V_351 ||
V_13 -> V_350 == V_352 ) {
struct V_3 * V_4 = F_109 ( V_2 ) ;
const T_2 V_353 =
F_151 ( V_4 ) + V_349 ;
T_7 V_299 = ( T_7 ) ( V_353 - V_90 ) ;
if ( V_299 > 0 )
V_349 = V_299 ;
}
F_142 ( V_2 , V_263 , V_349 ,
V_264 ) ;
}
}
static T_2 F_199 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_354 ;
F_95 ( ! F_62 ( F_26 ( V_4 ) -> V_106 , V_40 -> V_119 ) ) ;
V_354 = F_81 ( V_4 ) ;
if ( F_200 ( V_2 , V_4 , V_40 -> V_119 - F_26 ( V_4 ) -> V_91 ) )
return 0 ;
V_354 -= F_81 ( V_4 ) ;
if ( V_354 ) {
F_95 ( F_81 ( V_4 ) == 0 ) ;
F_95 ( ! F_55 ( F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_106 ) ) ;
}
return V_354 ;
}
static void F_201 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_167 )
{
const struct V_66 * V_355 ;
if ( F_65 ( ! F_26 ( V_4 ) -> V_356 ) )
return;
V_355 = F_9 ( V_4 ) ;
if ( ! F_55 ( V_355 -> V_357 , V_167 ) &&
F_55 ( V_355 -> V_357 , F_15 ( V_2 ) -> V_119 ) )
F_202 ( V_4 , NULL , V_2 , V_358 ) ;
}
static int F_203 ( struct V_1 * V_2 , int V_359 ,
T_2 V_167 , int * V_242 ,
struct V_182 * V_360 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_185 V_361 , V_362 ;
struct V_185 * V_110 = & V_360 -> V_189 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_241 = V_40 -> V_144 ;
T_2 V_148 = V_40 -> V_127 ;
bool V_363 = true ;
long V_337 = - 1L ;
long V_336 = - 1L ;
long V_338 = - 1L ;
struct V_3 * V_4 ;
T_2 V_364 = 0 ;
T_2 V_365 = 0 ;
bool V_366 ;
int V_192 = 0 ;
V_361 . V_195 = 0 ;
while ( ( V_4 = F_109 ( V_2 ) ) && V_4 != F_114 ( V_2 ) ) {
struct V_367 * V_368 = F_26 ( V_4 ) ;
T_6 V_154 = V_368 -> V_154 ;
T_2 V_369 ;
F_201 ( V_2 , V_4 , V_167 ) ;
if ( F_62 ( V_368 -> V_106 , V_40 -> V_119 ) ) {
if ( F_81 ( V_4 ) == 1 ||
! F_62 ( V_40 -> V_119 , V_368 -> V_91 ) )
break;
V_369 = F_199 ( V_2 , V_4 ) ;
if ( ! V_369 )
break;
V_363 = false ;
} else {
F_204 ( V_4 -> V_370 ) ;
V_369 = F_81 ( V_4 ) ;
}
if ( F_11 ( V_154 & V_188 ) ) {
if ( V_154 & V_156 )
V_40 -> V_190 -= V_369 ;
V_192 |= V_301 ;
} else if ( ! ( V_154 & V_158 ) ) {
V_362 = V_4 -> V_185 ;
F_166 ( V_362 . V_195 == 0 ) ;
if ( ! V_361 . V_195 )
V_361 = V_362 ;
V_365 = F_26 ( V_4 ) -> V_208 . V_371 ;
V_148 = F_17 ( V_364 , V_148 ) ;
if ( ! F_62 ( V_368 -> V_106 , V_40 -> V_191 ) )
V_192 |= V_193 ;
}
if ( V_154 & V_158 ) {
V_40 -> V_144 -= V_369 ;
} else if ( F_147 ( V_40 ) ) {
V_40 -> V_198 += V_369 ;
if ( ! F_150 ( V_40 , V_4 ) )
F_91 ( V_40 , V_154 , V_368 -> V_106 ,
& V_4 -> V_185 ,
& V_360 -> V_189 ) ;
}
if ( V_154 & V_155 )
V_40 -> V_159 -= V_369 ;
V_40 -> V_127 -= V_369 ;
V_364 += V_369 ;
F_96 ( V_2 , V_4 , V_360 -> V_122 ) ;
if ( F_65 ( ! ( V_368 -> V_205 & V_372 ) ) ) {
V_192 |= V_373 ;
} else {
V_192 |= V_345 ;
V_40 -> V_274 = 0 ;
}
if ( ! V_363 )
break;
F_101 ( V_4 , V_2 ) ;
F_102 ( V_2 , V_4 ) ;
if ( F_11 ( V_4 == V_40 -> V_153 ) )
V_40 -> V_153 = NULL ;
if ( F_11 ( V_4 == V_40 -> V_133 ) )
V_40 -> V_133 = NULL ;
}
if ( ! V_4 )
F_205 ( V_2 , V_374 ) ;
if ( F_65 ( F_206 ( V_40 -> V_375 , V_167 , V_40 -> V_119 ) ) )
V_40 -> V_375 = V_40 -> V_119 ;
if ( V_4 && ( F_26 ( V_4 ) -> V_154 & V_158 ) )
V_192 |= V_261 ;
if ( F_65 ( V_361 . V_195 ) && ! ( V_192 & V_301 ) ) {
V_336 = F_195 ( V_110 , & V_361 ) ;
V_338 = F_195 ( V_110 , & V_362 ) ;
}
if ( V_360 -> V_194 . V_195 ) {
V_337 = F_195 ( V_110 , & V_360 -> V_194 ) ;
V_338 = F_195 ( V_110 , & V_360 -> V_196 ) ;
}
V_360 -> V_122 -> V_331 = V_338 ;
V_366 = F_191 ( V_2 , V_192 , V_336 , V_337 ,
V_338 ) ;
if ( V_192 & V_339 ) {
F_197 ( V_2 ) ;
if ( F_11 ( V_13 -> V_259 . V_260 &&
! F_62 ( V_40 -> V_329 . V_376 , V_40 -> V_119 ) ) ) {
F_173 ( V_2 ) ;
}
if ( F_77 ( V_40 ) ) {
F_130 ( V_2 , V_364 ) ;
} else {
int V_299 ;
if ( V_148 < V_359 )
F_75 ( V_2 , V_40 -> V_143 - V_148 , 0 ) ;
V_299 = F_73 ( V_40 ) ? V_364 :
V_241 - V_40 -> V_144 ;
V_40 -> V_199 -= F_17 ( V_40 -> V_199 , V_299 ) ;
}
V_40 -> V_143 -= F_17 ( V_364 , V_40 -> V_143 ) ;
} else if ( V_4 && V_366 && V_337 >= 0 &&
V_337 > F_195 ( V_110 , & V_4 -> V_185 ) ) {
F_197 ( V_2 ) ;
}
if ( V_13 -> V_58 -> V_364 ) {
struct V_377 V_97 = { . V_364 = V_364 ,
. V_331 = V_338 ,
. V_371 = V_365 } ;
V_13 -> V_58 -> V_364 ( V_2 , & V_97 ) ;
}
#if V_141 > 0
F_122 ( ( int ) V_40 -> V_144 < 0 ) ;
F_122 ( ( int ) V_40 -> V_159 < 0 ) ;
F_122 ( ( int ) V_40 -> V_190 < 0 ) ;
if ( ! V_40 -> V_127 && F_147 ( V_40 ) ) {
V_13 = F_8 ( V_2 ) ;
if ( V_40 -> V_159 ) {
F_76 ( L_11 ,
V_40 -> V_159 , V_13 -> V_142 ) ;
V_40 -> V_159 = 0 ;
}
if ( V_40 -> V_144 ) {
F_76 ( L_12 ,
V_40 -> V_144 , V_13 -> V_142 ) ;
V_40 -> V_144 = 0 ;
}
if ( V_40 -> V_190 ) {
F_76 ( L_13 ,
V_40 -> V_190 , V_13 -> V_142 ) ;
V_40 -> V_190 = 0 ;
}
}
#endif
* V_242 = V_364 ;
return V_192 ;
}
static void F_207 ( struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( ! F_62 ( F_26 ( F_114 ( V_2 ) ) -> V_106 , F_183 ( V_40 ) ) ) {
V_13 -> V_340 = 0 ;
F_198 ( V_2 , V_378 ) ;
} else {
unsigned long V_272 = F_208 ( V_2 , V_264 ) ;
F_142 ( V_2 , V_378 ,
V_272 , V_264 ) ;
}
}
static inline bool F_209 ( const struct V_1 * V_2 , const int V_192 )
{
return ! ( V_192 & V_379 ) || ( V_192 & V_380 ) ||
F_8 ( V_2 ) -> V_142 != V_289 ;
}
static inline bool F_210 ( const struct V_1 * V_2 , const int V_192 )
{
if ( F_15 ( V_2 ) -> V_69 > F_4 ( V_2 ) -> V_255 . V_256 )
return V_192 & V_381 ;
return V_192 & V_373 ;
}
static void F_211 ( struct V_1 * V_2 , T_2 V_346 , T_2 V_382 ,
int V_192 , const struct V_383 * V_384 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( V_13 -> V_58 -> V_303 ) {
V_13 -> V_58 -> V_303 ( V_2 , V_384 ) ;
return;
}
if ( F_181 ( V_2 ) ) {
F_165 ( V_2 , V_382 , V_192 ) ;
} else if ( F_210 ( V_2 , V_192 ) ) {
F_196 ( V_2 , V_346 , V_382 ) ;
}
F_64 ( V_2 ) ;
}
static inline bool F_212 ( const struct V_39 * V_40 ,
const T_2 V_346 , const T_2 V_171 ,
const T_2 V_385 )
{
return F_62 ( V_346 , V_40 -> V_119 ) ||
F_62 ( V_171 , V_40 -> V_386 ) ||
( V_171 == V_40 -> V_386 && V_385 > V_40 -> V_387 ) ;
}
static void F_213 ( struct V_39 * V_40 , T_2 V_346 )
{
T_2 V_299 = V_346 - V_40 -> V_119 ;
F_214 ( (struct V_1 * ) V_40 ) ;
V_40 -> V_388 += V_299 ;
V_40 -> V_119 = V_346 ;
}
static void F_215 ( struct V_39 * V_40 , T_2 V_91 )
{
T_2 V_299 = V_91 - V_40 -> V_104 ;
F_214 ( (struct V_1 * ) V_40 ) ;
V_40 -> V_389 += V_299 ;
V_40 -> V_104 = V_91 ;
}
static int F_216 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_2 V_346 ,
T_2 V_171 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_192 = 0 ;
T_2 V_385 = F_156 ( F_14 ( V_4 ) -> V_74 ) ;
if ( F_65 ( ! F_14 ( V_4 ) -> V_55 ) )
V_385 <<= V_40 -> V_62 . V_390 ;
if ( F_212 ( V_40 , V_346 , V_171 , V_385 ) ) {
V_192 |= V_391 ;
F_217 ( V_40 , V_171 ) ;
if ( V_40 -> V_387 != V_385 ) {
V_40 -> V_387 = V_385 ;
V_40 -> V_392 = 0 ;
F_218 ( V_2 ) ;
if ( F_114 ( V_2 ) )
F_219 ( V_2 ) ;
if ( V_385 > V_40 -> V_162 ) {
V_40 -> V_162 = V_385 ;
F_175 ( V_2 , F_8 ( V_2 ) -> V_311 ) ;
}
}
}
F_213 ( V_40 , V_346 ) ;
return V_192 ;
}
static bool F_220 ( struct V_243 * V_243 , int V_139 ,
T_2 * V_393 )
{
if ( * V_393 ) {
T_7 V_394 = ( T_7 ) ( V_90 - * V_393 ) ;
if ( 0 <= V_394 && V_394 < V_395 ) {
F_78 ( V_243 , V_139 ) ;
return true ;
}
}
* V_393 = V_90 ;
return false ;
}
bool F_221 ( struct V_243 * V_243 , const struct V_3 * V_4 ,
int V_139 , T_2 * V_393 )
{
if ( ( F_26 ( V_4 ) -> V_91 != F_26 ( V_4 ) -> V_106 ) &&
! F_14 ( V_4 ) -> V_55 )
return false ;
return F_220 ( V_243 , V_139 , V_393 ) ;
}
static void F_222 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_2 V_396 ;
static unsigned int V_397 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
T_2 V_398 , V_110 ;
if ( F_220 ( F_4 ( V_2 ) ,
V_399 ,
& V_40 -> V_393 ) )
return;
V_110 = V_400 / V_334 ;
if ( V_110 != V_396 ) {
T_2 V_401 = ( V_402 + 1 ) >> 1 ;
V_396 = V_110 ;
F_223 ( V_397 , V_401 +
F_224 ( V_402 ) ) ;
}
V_398 = F_225 ( V_397 ) ;
if ( V_398 > 0 ) {
F_223 ( V_397 , V_398 - 1 ) ;
F_78 ( F_4 ( V_2 ) , V_403 ) ;
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
if ( V_40 -> V_62 . V_273 && ! F_62 ( V_91 , V_40 -> V_407 ) ) {
if ( F_230 ( & V_40 -> V_62 , 0 ) )
F_227 ( V_40 ) ;
}
}
static void F_231 ( struct V_1 * V_2 , T_2 V_346 , int V_192 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_55 ( V_346 , V_40 -> V_293 ) )
return;
if ( V_192 & V_232 ) {
V_40 -> V_293 = 0 ;
} else if ( F_62 ( V_346 , V_40 -> V_293 ) ) {
F_164 ( V_2 ) ;
F_138 ( V_2 , V_304 ) ;
F_168 ( V_2 ) ;
F_170 ( V_2 ) ;
F_78 ( F_4 ( V_2 ) ,
V_408 ) ;
} else if ( ! ( V_192 & ( V_320 |
V_379 | V_197 ) ) ) {
V_40 -> V_293 = 0 ;
}
}
static inline void F_232 ( struct V_1 * V_2 , T_2 V_409 )
{
const struct V_12 * V_13 = F_8 ( V_2 ) ;
if ( V_13 -> V_58 -> V_410 )
V_13 -> V_58 -> V_410 ( V_2 , V_409 ) ;
}
static void F_233 ( struct V_1 * V_2 , int V_318 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_318 == V_411 )
return;
if ( F_11 ( V_318 == 2 ) ) {
F_234 ( V_2 , F_177 ( V_2 ) ,
V_412 ) ;
if ( F_62 ( V_40 -> V_121 , V_40 -> V_191 ) )
return;
V_40 -> V_257 = 0 ;
}
F_179 ( V_2 ) ;
}
static int F_235 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_192 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_182 V_413 ;
struct V_383 V_384 = { . V_414 = 0 } ;
T_2 V_167 = V_40 -> V_119 ;
T_2 V_171 = F_26 ( V_4 ) -> V_91 ;
T_2 V_346 = F_26 ( V_4 ) -> V_171 ;
bool V_317 = false ;
T_2 V_359 ;
int V_415 = V_40 -> V_127 ;
T_2 V_198 = V_40 -> V_198 ;
T_2 V_157 = V_40 -> V_157 ;
int V_242 = 0 ;
int V_318 = V_411 ;
V_413 . V_194 . V_195 = 0 ;
V_413 . V_122 = & V_384 ;
F_204 ( V_2 -> V_416 . V_370 ) ;
if ( F_55 ( V_346 , V_167 ) ) {
if ( F_55 ( V_346 , V_167 - V_40 -> V_162 ) ) {
F_222 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_417;
}
if ( F_62 ( V_346 , V_40 -> V_121 ) )
goto V_418;
F_194 ( & V_413 . V_189 ) ;
if ( V_13 -> V_350 == V_352 )
F_197 ( V_2 ) ;
if ( F_62 ( V_346 , V_167 ) ) {
V_192 |= V_320 ;
V_13 -> V_249 = 0 ;
}
V_359 = V_40 -> V_143 ;
V_384 . V_419 = F_126 ( V_40 ) ;
if ( V_192 & V_420 )
F_229 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
if ( ! ( V_192 & V_421 ) && F_62 ( V_346 , V_167 ) ) {
F_217 ( V_40 , V_171 ) ;
F_213 ( V_40 , V_346 ) ;
V_192 |= V_391 ;
F_232 ( V_2 , V_422 ) ;
F_78 ( F_4 ( V_2 ) , V_423 ) ;
} else {
T_2 V_424 = V_425 ;
if ( V_171 != F_26 ( V_4 ) -> V_106 )
V_192 |= V_426 ;
else
F_78 ( F_4 ( V_2 ) , V_427 ) ;
V_192 |= F_216 ( V_2 , V_4 , V_346 , V_171 ) ;
if ( F_26 ( V_4 ) -> V_154 )
V_192 |= F_121 ( V_2 , V_4 , V_167 ,
& V_413 ) ;
if ( F_32 ( V_40 , F_14 ( V_4 ) ) ) {
V_192 |= V_307 ;
V_424 |= V_428 ;
}
if ( V_192 & V_391 )
V_424 |= V_422 ;
F_232 ( V_2 , V_424 ) ;
}
V_2 -> V_429 = 0 ;
V_13 -> V_430 = 0 ;
V_40 -> V_431 = V_90 ;
if ( ! V_415 )
goto V_432;
V_192 |= F_203 ( V_2 , V_359 , V_167 , & V_242 ,
& V_413 ) ;
if ( F_209 ( V_2 , V_192 ) ) {
V_317 = ! ( V_192 & ( V_320 | V_379 ) ) ;
F_187 ( V_2 , V_242 , V_317 , & V_192 , & V_318 ,
& V_413 . V_189 ) ;
}
if ( V_40 -> V_293 )
F_231 ( V_2 , V_346 , V_192 ) ;
if ( ( V_192 & V_381 ) || ! ( V_192 & V_379 ) )
F_236 ( V_2 ) ;
if ( V_13 -> V_350 == V_263 )
F_237 ( V_2 ) ;
V_198 = V_40 -> V_198 - V_198 ;
V_157 = V_40 -> V_157 - V_157 ;
F_238 ( V_2 , V_198 , V_157 , & V_413 . V_189 ,
V_413 . V_122 ) ;
F_211 ( V_2 , V_346 , V_198 , V_192 , V_413 . V_122 ) ;
F_233 ( V_2 , V_318 ) ;
return 1 ;
V_432:
if ( V_192 & V_232 )
F_187 ( V_2 , V_242 , V_317 , & V_192 , & V_318 ,
& V_413 . V_189 ) ;
if ( F_114 ( V_2 ) )
F_207 ( V_2 ) ;
if ( V_40 -> V_293 )
F_231 ( V_2 , V_346 , V_192 ) ;
return 1 ;
V_418:
F_239 ( V_2 , L_14 , V_346 , V_40 -> V_119 , V_40 -> V_121 ) ;
return - 1 ;
V_417:
if ( F_26 ( V_4 ) -> V_154 ) {
F_194 ( & V_413 . V_189 ) ;
V_192 |= F_121 ( V_2 , V_4 , V_167 ,
& V_413 ) ;
F_187 ( V_2 , V_242 , V_317 , & V_192 , & V_318 ,
& V_413 . V_189 ) ;
F_233 ( V_2 , V_318 ) ;
}
F_239 ( V_2 , L_15 , V_346 , V_40 -> V_119 , V_40 -> V_121 ) ;
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
const unsigned char * V_223 ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
int V_443 = ( V_53 -> V_444 * 4 ) - sizeof( struct V_22 ) ;
V_223 = ( const unsigned char * ) ( V_53 + 1 ) ;
V_441 -> V_273 = 0 ;
while ( V_443 > 0 ) {
int V_445 = * V_223 ++ ;
int V_446 ;
switch ( V_445 ) {
case V_447 :
return;
case V_448 :
V_443 -- ;
continue;
default:
V_446 = * V_223 ++ ;
if ( V_446 < 2 )
return;
if ( V_446 > V_443 )
return;
switch ( V_445 ) {
case V_449 :
if ( V_446 == V_450 && V_53 -> V_55 && ! V_442 ) {
T_8 V_451 = F_242 ( V_223 ) ;
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
T_5 V_390 = * ( T_5 * ) V_223 ;
V_441 -> V_456 = 1 ;
if ( V_390 > 14 ) {
F_243 ( L_16 ,
V_457 ,
V_390 ) ;
V_390 = 14 ;
}
V_441 -> V_390 = V_390 ;
}
break;
case V_458 :
if ( ( V_446 == V_459 ) &&
( ( V_442 && V_441 -> V_460 ) ||
( ! V_442 && V_461 ) ) ) {
V_441 -> V_273 = 1 ;
V_441 -> V_405 = F_86 ( V_223 ) ;
V_441 -> V_105 = F_86 ( V_223 + 4 ) ;
}
break;
case V_462 :
if ( V_446 == V_463 && V_53 -> V_55 &&
! V_442 && V_464 ) {
V_441 -> V_134 = V_465 ;
F_244 ( V_441 ) ;
}
break;
case V_466 :
if ( ( V_446 >= ( V_226 + V_467 ) ) &&
! ( ( V_446 - V_226 ) % V_467 ) &&
V_441 -> V_134 ) {
F_26 ( V_4 ) -> V_154 = ( V_223 - 2 ) - ( unsigned char * ) V_53 ;
}
break;
#ifdef F_245
case V_468 :
break;
#endif
case V_469 :
F_240 (
V_446 - V_470 ,
V_223 , V_53 -> V_55 , V_435 , false ) ;
break;
case V_471 :
if ( V_446 >= V_472 &&
F_242 ( V_223 ) ==
V_473 )
F_240 ( V_446 -
V_472 ,
V_223 + 2 , V_53 -> V_55 , V_435 , true ) ;
break;
}
V_223 += V_446 - 2 ;
V_443 -= V_446 ;
}
}
}
static bool F_246 ( struct V_39 * V_40 , const struct V_22 * V_53 )
{
const T_9 * V_223 = ( const T_9 * ) ( V_53 + 1 ) ;
if ( * V_223 == F_247 ( ( V_448 << 24 ) | ( V_448 << 16 )
| ( V_458 << 8 ) | V_459 ) ) {
V_40 -> V_62 . V_273 = 1 ;
++ V_223 ;
V_40 -> V_62 . V_405 = F_248 ( * V_223 ) ;
++ V_223 ;
if ( * V_223 )
V_40 -> V_62 . V_105 = F_248 ( * V_223 ) - V_40 -> V_474 ;
else
V_40 -> V_62 . V_105 = 0 ;
return true ;
}
return false ;
}
static bool F_249 ( const struct V_3 * V_4 ,
const struct V_22 * V_53 , struct V_39 * V_40 )
{
if ( V_53 -> V_444 == ( sizeof( * V_53 ) / 4 ) ) {
V_40 -> V_62 . V_273 = 0 ;
return false ;
} else if ( V_40 -> V_62 . V_460 &&
V_53 -> V_444 == ( ( sizeof( * V_53 ) + V_475 ) / 4 ) ) {
if ( F_246 ( V_40 , V_53 ) )
return true ;
}
F_241 ( V_4 , & V_40 -> V_62 , 1 , NULL ) ;
if ( V_40 -> V_62 . V_273 && V_40 -> V_62 . V_105 )
V_40 -> V_62 . V_105 -= V_40 -> V_474 ;
return true ;
}
const T_6 * F_250 ( const struct V_22 * V_53 )
{
int V_443 = ( V_53 -> V_444 << 2 ) - sizeof( * V_53 ) ;
const T_6 * V_223 = ( const T_6 * ) ( V_53 + 1 ) ;
if ( V_443 < V_476 )
return NULL ;
while ( V_443 > 0 ) {
int V_445 = * V_223 ++ ;
int V_446 ;
switch ( V_445 ) {
case V_447 :
return NULL ;
case V_448 :
V_443 -- ;
continue;
default:
V_446 = * V_223 ++ ;
if ( V_446 < 2 || V_446 > V_443 )
return NULL ;
if ( V_445 == V_468 )
return V_446 == V_476 ? V_223 : NULL ;
}
V_223 += V_446 - 2 ;
V_443 -= V_446 ;
}
return NULL ;
}
static int F_251 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
T_2 V_91 = F_26 ( V_4 ) -> V_91 ;
T_2 V_346 = F_26 ( V_4 ) -> V_171 ;
return (
( V_53 -> V_346 && V_91 == F_26 ( V_4 ) -> V_106 && V_91 == V_40 -> V_104 ) &&
V_346 == V_40 -> V_119 &&
! F_212 ( V_40 , V_346 , V_91 , F_156 ( V_53 -> V_74 ) << V_40 -> V_62 . V_390 ) &&
( T_7 ) ( V_40 -> V_62 . V_404 - V_40 -> V_62 . V_405 ) <= ( F_8 ( V_2 ) -> V_112 * 1024 ) / V_334 ) ;
}
static inline bool F_252 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_39 * V_40 = F_15 ( V_2 ) ;
return ! F_230 ( & V_40 -> V_62 , V_477 ) &&
! F_251 ( V_2 , V_4 ) ;
}
static inline bool F_253 ( const struct V_39 * V_40 , T_2 V_91 , T_2 V_106 )
{
return ! F_55 ( V_106 , V_40 -> V_407 ) &&
! F_62 ( V_91 , V_40 -> V_104 + F_254 ( V_40 ) ) ;
}
void F_255 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_478 ) {
case V_479 :
V_2 -> V_480 = V_481 ;
break;
case V_482 :
V_2 -> V_480 = V_483 ;
break;
case V_484 :
return;
default:
V_2 -> V_480 = V_485 ;
}
F_256 () ;
if ( ! F_257 ( V_2 , V_486 ) )
V_2 -> V_487 ( V_2 ) ;
F_258 ( V_2 ) ;
}
void F_259 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_59 ( V_2 ) ;
V_2 -> V_488 |= V_489 ;
F_260 ( V_2 , V_490 ) ;
switch ( V_2 -> V_478 ) {
case V_491 :
case V_492 :
F_261 ( V_2 , V_482 ) ;
F_8 ( V_2 ) -> V_15 . V_33 = 1 ;
break;
case V_482 :
case V_493 :
break;
case V_494 :
break;
case V_495 :
F_226 ( V_2 ) ;
F_261 ( V_2 , V_493 ) ;
break;
case V_496 :
F_226 ( V_2 ) ;
F_262 ( V_2 , V_497 , 0 ) ;
break;
default:
F_263 ( L_17 ,
V_457 , V_2 -> V_478 ) ;
break;
}
F_264 ( & V_40 -> V_498 ) ;
if ( F_147 ( V_40 ) )
F_244 ( & V_40 -> V_62 ) ;
F_60 ( V_2 ) ;
if ( ! F_257 ( V_2 , V_486 ) ) {
V_2 -> V_499 ( V_2 ) ;
if ( V_2 -> V_488 == V_500 ||
V_2 -> V_478 == V_484 )
F_265 ( V_2 , V_501 , V_502 ) ;
else
F_265 ( V_2 , V_501 , V_503 ) ;
}
}
static inline bool F_266 ( struct V_216 * V_165 , T_2 V_91 ,
T_2 V_106 )
{
if ( ! F_62 ( V_91 , V_165 -> V_106 ) && ! F_62 ( V_165 -> V_161 , V_106 ) ) {
if ( F_55 ( V_91 , V_165 -> V_161 ) )
V_165 -> V_161 = V_91 ;
if ( F_62 ( V_106 , V_165 -> V_106 ) )
V_165 -> V_106 = V_106 ;
return true ;
}
return false ;
}
static void F_267 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_106 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_147 ( V_40 ) && V_504 ) {
int V_139 ;
if ( F_55 ( V_91 , V_40 -> V_104 ) )
V_139 = V_505 ;
else
V_139 = V_506 ;
F_78 ( F_4 ( V_2 ) , V_139 ) ;
V_40 -> V_62 . V_507 = 1 ;
V_40 -> V_508 [ 0 ] . V_161 = V_91 ;
V_40 -> V_508 [ 0 ] . V_106 = V_106 ;
}
}
static void F_268 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_106 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( ! V_40 -> V_62 . V_507 )
F_267 ( V_2 , V_91 , V_106 ) ;
else
F_266 ( V_40 -> V_508 , V_91 , V_106 ) ;
}
static void F_269 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_26 ( V_4 ) -> V_106 != F_26 ( V_4 ) -> V_91 &&
F_55 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_104 ) ) {
F_78 ( F_4 ( V_2 ) , V_509 ) ;
F_18 ( V_2 ) ;
if ( F_147 ( V_40 ) && V_504 ) {
T_2 V_106 = F_26 ( V_4 ) -> V_106 ;
if ( F_62 ( F_26 ( V_4 ) -> V_106 , V_40 -> V_104 ) )
V_106 = V_40 -> V_104 ;
F_267 ( V_2 , F_26 ( V_4 ) -> V_91 , V_106 ) ;
}
}
F_226 ( V_2 ) ;
}
static void F_270 ( struct V_39 * V_40 )
{
int V_510 ;
struct V_216 * V_165 = & V_40 -> V_511 [ 0 ] ;
struct V_216 * V_512 = V_165 + 1 ;
for ( V_510 = 1 ; V_510 < V_40 -> V_62 . V_166 ; ) {
if ( F_266 ( V_165 , V_512 -> V_161 , V_512 -> V_106 ) ) {
int V_229 ;
V_40 -> V_62 . V_166 -- ;
for ( V_229 = V_510 ; V_229 < V_40 -> V_62 . V_166 ; V_229 ++ )
V_165 [ V_229 ] = V_165 [ V_229 + 1 ] ;
continue;
}
V_510 ++ , V_512 ++ ;
}
}
static void F_271 ( struct V_1 * V_2 , T_2 V_91 , T_2 V_106 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_216 * V_165 = & V_40 -> V_511 [ 0 ] ;
int V_513 = V_40 -> V_62 . V_166 ;
int V_510 ;
if ( ! V_513 )
goto V_514;
for ( V_510 = 0 ; V_510 < V_513 ; V_510 ++ , V_165 ++ ) {
if ( F_266 ( V_165 , V_91 , V_106 ) ) {
for (; V_510 > 0 ; V_510 -- , V_165 -- )
F_124 ( * V_165 , * ( V_165 - 1 ) ) ;
if ( V_513 > 1 )
F_270 ( V_40 ) ;
return;
}
}
if ( V_510 >= V_225 ) {
V_510 -- ;
V_40 -> V_62 . V_166 -- ;
V_165 -- ;
}
for (; V_510 > 0 ; V_510 -- , V_165 -- )
* V_165 = * ( V_165 - 1 ) ;
V_514:
V_165 -> V_161 = V_91 ;
V_165 -> V_106 = V_106 ;
V_40 -> V_62 . V_166 ++ ;
}
static void F_272 ( struct V_39 * V_40 )
{
struct V_216 * V_165 = & V_40 -> V_511 [ 0 ] ;
int V_166 = V_40 -> V_62 . V_166 ;
int V_510 ;
if ( F_273 ( & V_40 -> V_498 ) ) {
V_40 -> V_62 . V_166 = 0 ;
return;
}
for ( V_510 = 0 ; V_510 < V_166 ; ) {
if ( ! F_55 ( V_40 -> V_104 , V_165 -> V_161 ) ) {
int V_229 ;
F_122 ( F_55 ( V_40 -> V_104 , V_165 -> V_106 ) ) ;
for ( V_229 = V_510 + 1 ; V_229 < V_166 ; V_229 ++ )
V_40 -> V_511 [ V_229 - 1 ] = V_40 -> V_511 [ V_229 ] ;
V_166 -- ;
continue;
}
V_510 ++ ;
V_165 ++ ;
}
V_40 -> V_62 . V_166 = V_166 ;
}
static bool F_274 ( struct V_1 * V_2 ,
struct V_3 * V_515 ,
struct V_3 * V_516 ,
bool * V_517 )
{
int V_299 ;
* V_517 = false ;
if ( F_26 ( V_516 ) -> V_91 != F_26 ( V_515 ) -> V_106 )
return false ;
if ( ! F_275 ( V_515 , V_516 , V_517 , & V_299 ) )
return false ;
F_276 ( V_299 , & V_2 -> V_95 ) ;
F_277 ( V_2 , V_299 ) ;
F_78 ( F_4 ( V_2 ) , V_518 ) ;
F_26 ( V_515 ) -> V_106 = F_26 ( V_516 ) -> V_106 ;
F_26 ( V_515 ) -> V_171 = F_26 ( V_516 ) -> V_171 ;
F_26 ( V_515 ) -> V_205 |= F_26 ( V_516 ) -> V_205 ;
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
T_4 V_519 = V_40 -> V_104 ;
bool V_520 , V_517 , V_521 ;
struct V_3 * V_4 , * V_522 ;
struct V_523 * V_524 ;
V_524 = F_282 ( & V_40 -> V_498 ) ;
while ( V_524 ) {
V_4 = F_283 ( V_524 , struct V_3 , V_525 ) ;
if ( F_62 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_104 ) )
break;
if ( F_55 ( F_26 ( V_4 ) -> V_91 , V_519 ) ) {
T_4 V_507 = V_519 ;
if ( F_55 ( F_26 ( V_4 ) -> V_106 , V_519 ) )
V_519 = F_26 ( V_4 ) -> V_106 ;
F_268 ( V_2 , F_26 ( V_4 ) -> V_91 , V_507 ) ;
}
V_524 = F_284 ( V_524 ) ;
F_285 ( & V_4 -> V_525 , & V_40 -> V_498 ) ;
if ( F_11 ( ! F_62 ( F_26 ( V_4 ) -> V_106 , V_40 -> V_104 ) ) ) {
F_239 ( V_2 , L_18 ) ;
F_278 ( V_2 , V_4 ) ;
continue;
}
F_239 ( V_2 , L_19 ,
V_40 -> V_104 , F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_106 ) ;
V_522 = F_286 ( & V_2 -> V_526 ) ;
V_521 = V_522 && F_274 ( V_2 , V_522 , V_4 , & V_517 ) ;
F_215 ( V_40 , F_26 ( V_4 ) -> V_106 ) ;
V_520 = F_26 ( V_4 ) -> V_205 & V_207 ;
if ( ! V_521 )
F_287 ( & V_2 -> V_526 , V_4 ) ;
else
F_288 ( V_4 , V_517 ) ;
if ( F_11 ( V_520 ) ) {
F_259 ( V_2 ) ;
break;
}
}
}
static int F_289 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_527 )
{
if ( F_51 ( & V_2 -> V_95 ) > V_2 -> V_83 ||
! F_290 ( V_2 , V_4 , V_527 ) ) {
if ( F_291 ( V_2 ) < 0 )
return - 1 ;
while ( ! F_290 ( V_2 , V_4 , V_527 ) ) {
if ( ! F_292 ( V_2 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_293 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_523 * * V_524 , * V_528 , * V_529 ;
struct V_3 * V_530 ;
T_2 V_91 , V_106 ;
bool V_517 ;
F_29 ( V_40 , V_4 ) ;
if ( F_11 ( F_289 ( V_2 , V_4 , V_4 -> V_73 ) ) ) {
F_78 ( F_4 ( V_2 ) , V_531 ) ;
F_278 ( V_2 , V_4 ) ;
return;
}
V_40 -> V_392 = 0 ;
F_59 ( V_2 ) ;
F_78 ( F_4 ( V_2 ) , V_532 ) ;
V_91 = F_26 ( V_4 ) -> V_91 ;
V_106 = F_26 ( V_4 ) -> V_106 ;
F_239 ( V_2 , L_20 ,
V_40 -> V_104 , V_91 , V_106 ) ;
V_524 = & V_40 -> V_498 . V_523 ;
if ( F_273 ( & V_40 -> V_498 ) ) {
if ( F_147 ( V_40 ) ) {
V_40 -> V_62 . V_166 = 1 ;
V_40 -> V_511 [ 0 ] . V_161 = V_91 ;
V_40 -> V_511 [ 0 ] . V_106 = V_106 ;
}
F_294 ( & V_4 -> V_525 , NULL , V_524 ) ;
F_295 ( & V_4 -> V_525 , & V_40 -> V_498 ) ;
V_40 -> V_533 = V_4 ;
goto V_534;
}
if ( F_274 ( V_2 , V_40 -> V_533 , V_4 , & V_517 ) ) {
V_535:
F_39 ( V_2 , V_4 ) ;
F_288 ( V_4 , V_517 ) ;
V_4 = NULL ;
goto V_536;
}
if ( ! F_55 ( V_91 , F_26 ( V_40 -> V_533 ) -> V_106 ) ) {
V_529 = & V_40 -> V_533 -> V_525 ;
V_524 = & V_529 -> V_537 ;
goto V_538;
}
V_529 = NULL ;
while ( * V_524 ) {
V_529 = * V_524 ;
V_530 = F_283 ( V_529 , struct V_3 , V_525 ) ;
if ( F_55 ( V_91 , F_26 ( V_530 ) -> V_91 ) ) {
V_524 = & V_529 -> V_539 ;
continue;
}
if ( F_55 ( V_91 , F_26 ( V_530 ) -> V_106 ) ) {
if ( ! F_62 ( V_106 , F_26 ( V_530 ) -> V_106 ) ) {
F_78 ( F_4 ( V_2 ) ,
V_540 ) ;
F_280 ( V_4 ) ;
V_4 = NULL ;
F_267 ( V_2 , V_91 , V_106 ) ;
goto V_536;
}
if ( F_62 ( V_91 , F_26 ( V_530 ) -> V_91 ) ) {
F_267 ( V_2 , V_91 , F_26 ( V_530 ) -> V_106 ) ;
} else {
F_296 ( & V_530 -> V_525 , & V_4 -> V_525 ,
& V_40 -> V_498 ) ;
F_268 ( V_2 ,
F_26 ( V_530 ) -> V_91 ,
F_26 ( V_530 ) -> V_106 ) ;
F_78 ( F_4 ( V_2 ) ,
V_540 ) ;
F_280 ( V_530 ) ;
goto V_541;
}
} else if ( F_274 ( V_2 , V_530 , V_4 , & V_517 ) ) {
goto V_535;
}
V_524 = & V_529 -> V_537 ;
}
V_538:
F_294 ( & V_4 -> V_525 , V_529 , V_524 ) ;
F_295 ( & V_4 -> V_525 , & V_40 -> V_498 ) ;
V_541:
while ( ( V_528 = F_284 ( & V_4 -> V_525 ) ) != NULL ) {
V_530 = F_283 ( V_528 , struct V_3 , V_525 ) ;
if ( ! F_62 ( V_106 , F_26 ( V_530 ) -> V_91 ) )
break;
if ( F_55 ( V_106 , F_26 ( V_530 ) -> V_106 ) ) {
F_268 ( V_2 , F_26 ( V_530 ) -> V_91 ,
V_106 ) ;
break;
}
F_285 ( & V_530 -> V_525 , & V_40 -> V_498 ) ;
F_268 ( V_2 , F_26 ( V_530 ) -> V_91 ,
F_26 ( V_530 ) -> V_106 ) ;
F_78 ( F_4 ( V_2 ) , V_540 ) ;
F_278 ( V_2 , V_530 ) ;
}
if ( ! V_528 )
V_40 -> V_533 = V_4 ;
V_536:
if ( F_147 ( V_40 ) )
F_271 ( V_2 , V_91 , V_106 ) ;
V_534:
if ( V_4 ) {
F_39 ( V_2 , V_4 ) ;
F_297 ( V_4 ) ;
F_298 ( V_4 , V_2 ) ;
}
}
static int T_10 F_299 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_542 ,
bool * V_517 )
{
int V_521 ;
struct V_3 * V_522 = F_286 ( & V_2 -> V_526 ) ;
F_300 ( V_4 , V_542 ) ;
V_521 = ( V_522 &&
F_274 ( V_2 , V_522 , V_4 , V_517 ) ) ? 1 : 0 ;
F_215 ( F_15 ( V_2 ) , F_26 ( V_4 ) -> V_106 ) ;
if ( ! V_521 ) {
F_287 ( & V_2 -> V_526 , V_4 ) ;
F_298 ( V_4 , V_2 ) ;
}
return V_521 ;
}
int F_301 ( struct V_1 * V_2 , struct V_543 * V_275 , T_11 V_527 )
{
struct V_3 * V_4 ;
int V_176 = - V_544 ;
int V_545 = 0 ;
bool V_517 ;
if ( V_527 == 0 )
return 0 ;
if ( V_527 > V_546 ) {
int V_547 = F_10 ( T_11 , V_527 >> V_548 , V_549 ) ;
V_545 = V_547 << V_548 ;
V_527 = V_545 + ( V_527 & ~ V_550 ) ;
}
V_4 = F_302 ( V_527 - V_545 , V_545 ,
V_551 ,
& V_176 , V_2 -> V_552 ) ;
if ( ! V_4 )
goto V_176;
F_303 ( V_4 , V_527 - V_545 ) ;
V_4 -> V_545 = V_545 ;
V_4 -> V_5 = V_527 ;
if ( F_289 ( V_2 , V_4 , V_4 -> V_73 ) )
goto V_553;
V_176 = F_304 ( V_4 , 0 , & V_275 -> V_554 , V_527 ) ;
if ( V_176 )
goto V_553;
F_26 ( V_4 ) -> V_91 = F_15 ( V_2 ) -> V_104 ;
F_26 ( V_4 ) -> V_106 = F_26 ( V_4 ) -> V_91 + V_527 ;
F_26 ( V_4 ) -> V_171 = F_15 ( V_2 ) -> V_119 - 1 ;
if ( F_299 ( V_2 , V_4 , 0 , & V_517 ) ) {
F_166 ( V_517 ) ;
F_280 ( V_4 ) ;
}
return V_527 ;
V_553:
F_305 ( V_4 ) ;
V_176:
return V_176 ;
}
static void F_306 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_517 = false ;
int V_521 = - 1 ;
if ( F_26 ( V_4 ) -> V_91 == F_26 ( V_4 ) -> V_106 ) {
F_280 ( V_4 ) ;
return;
}
F_307 ( V_4 ) ;
F_300 ( V_4 , F_14 ( V_4 ) -> V_444 * 4 ) ;
F_23 ( V_40 , V_4 ) ;
V_40 -> V_62 . V_507 = 0 ;
if ( F_26 ( V_4 ) -> V_91 == V_40 -> V_104 ) {
if ( F_254 ( V_40 ) == 0 )
goto V_555;
if ( V_40 -> V_556 . V_557 == V_558 &&
V_40 -> V_92 == V_40 -> V_104 && V_40 -> V_556 . V_5 &&
F_308 ( V_2 ) && ! V_40 -> V_559 ) {
int V_560 = F_10 (unsigned int, skb->len,
tp->ucopy.len) ;
F_309 ( V_561 ) ;
if ( ! F_310 ( V_4 , 0 , V_40 -> V_556 . V_275 , V_560 ) ) {
V_40 -> V_556 . V_5 -= V_560 ;
V_40 -> V_92 += V_560 ;
V_521 = ( V_560 == V_4 -> V_5 ) ;
F_57 ( V_2 ) ;
}
}
if ( V_521 <= 0 ) {
V_562:
if ( V_521 < 0 ) {
if ( F_311 ( & V_2 -> V_526 ) == 0 )
F_312 ( V_2 , V_4 -> V_73 ) ;
else if ( F_289 ( V_2 , V_4 , V_4 -> V_73 ) )
goto V_563;
}
V_521 = F_299 ( V_2 , V_4 , 0 , & V_517 ) ;
}
F_215 ( V_40 , F_26 ( V_4 ) -> V_106 ) ;
if ( V_4 -> V_5 )
F_58 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_205 & V_207 )
F_259 ( V_2 ) ;
if ( ! F_273 ( & V_40 -> V_498 ) ) {
F_281 ( V_2 ) ;
if ( F_273 ( & V_40 -> V_498 ) )
F_8 ( V_2 ) -> V_15 . V_33 = 0 ;
}
if ( V_40 -> V_62 . V_166 )
F_272 ( V_40 ) ;
F_218 ( V_2 ) ;
if ( V_521 > 0 )
F_288 ( V_4 , V_517 ) ;
if ( ! F_257 ( V_2 , V_486 ) )
V_2 -> V_564 ( V_2 ) ;
return;
}
if ( ! F_62 ( F_26 ( V_4 ) -> V_106 , V_40 -> V_104 ) ) {
F_78 ( F_4 ( V_2 ) , V_509 ) ;
F_267 ( V_2 , F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_106 ) ;
V_555:
F_18 ( V_2 ) ;
F_59 ( V_2 ) ;
V_563:
F_278 ( V_2 , V_4 ) ;
return;
}
if ( ! F_55 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_104 + F_254 ( V_40 ) ) )
goto V_555;
F_18 ( V_2 ) ;
if ( F_55 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_104 ) ) {
F_239 ( V_2 , L_21 ,
V_40 -> V_104 , F_26 ( V_4 ) -> V_91 ,
F_26 ( V_4 ) -> V_106 ) ;
F_267 ( V_2 , F_26 ( V_4 ) -> V_91 , V_40 -> V_104 ) ;
if ( ! F_254 ( V_40 ) )
goto V_555;
goto V_562;
}
F_293 ( V_2 , V_4 ) ;
}
static struct V_3 * F_313 ( struct V_3 * V_4 , struct V_565 * V_566 )
{
if ( V_566 )
return ! F_314 ( V_566 , V_4 ) ? V_4 -> V_370 : NULL ;
return F_315 ( F_284 ( & V_4 -> V_525 ) , struct V_3 , V_525 ) ;
}
static struct V_3 * F_316 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_565 * V_566 ,
struct V_567 * V_568 )
{
struct V_3 * V_370 = F_313 ( V_4 , V_566 ) ;
if ( V_566 )
F_317 ( V_4 , V_566 ) ;
else
F_285 ( & V_4 -> V_525 , V_568 ) ;
F_280 ( V_4 ) ;
F_78 ( F_4 ( V_2 ) , V_569 ) ;
return V_370 ;
}
static void F_318 ( struct V_567 * V_568 , struct V_3 * V_4 )
{
struct V_523 * * V_524 = & V_568 -> V_523 ;
struct V_523 * V_529 = NULL ;
struct V_3 * V_530 ;
while ( * V_524 ) {
V_529 = * V_524 ;
V_530 = F_283 ( V_529 , struct V_3 , V_525 ) ;
if ( F_55 ( F_26 ( V_4 ) -> V_91 , F_26 ( V_530 ) -> V_91 ) )
V_524 = & V_529 -> V_539 ;
else
V_524 = & V_529 -> V_537 ;
}
F_294 ( & V_4 -> V_525 , V_529 , V_524 ) ;
F_295 ( & V_4 -> V_525 , V_568 ) ;
}
static void
F_319 ( struct V_1 * V_2 , struct V_565 * V_566 , struct V_567 * V_568 ,
struct V_3 * V_570 , struct V_3 * V_522 , T_2 V_571 , T_2 V_534 )
{
struct V_3 * V_4 = V_570 , * V_572 ;
struct V_565 V_219 ;
bool V_573 ;
V_574:
for ( V_573 = true ; V_4 != NULL && V_4 != V_522 ; V_4 = V_572 ) {
V_572 = F_313 ( V_4 , V_566 ) ;
if ( ! F_55 ( V_571 , F_26 ( V_4 ) -> V_106 ) ) {
V_4 = F_316 ( V_2 , V_4 , V_566 , V_568 ) ;
if ( ! V_4 )
break;
goto V_574;
}
if ( ! ( F_26 ( V_4 ) -> V_205 & ( V_372 | V_207 ) ) &&
( F_38 ( V_4 -> V_73 ) > V_4 -> V_5 ||
F_55 ( F_26 ( V_4 ) -> V_91 , V_571 ) ) ) {
V_573 = false ;
break;
}
if ( V_572 && V_572 != V_522 &&
F_26 ( V_4 ) -> V_106 != F_26 ( V_572 ) -> V_91 ) {
V_573 = false ;
break;
}
V_571 = F_26 ( V_4 ) -> V_106 ;
}
if ( V_573 ||
( F_26 ( V_4 ) -> V_205 & ( V_372 | V_207 ) ) )
return;
F_320 ( & V_219 ) ;
while ( F_55 ( V_571 , V_534 ) ) {
int V_575 = F_10 ( int , F_321 ( 0 , 0 ) , V_534 - V_571 ) ;
struct V_3 * V_576 ;
V_576 = F_322 ( V_575 , V_181 ) ;
if ( ! V_576 )
break;
memcpy ( V_576 -> V_577 , V_4 -> V_577 , sizeof( V_4 -> V_577 ) ) ;
F_26 ( V_576 ) -> V_91 = F_26 ( V_576 ) -> V_106 = V_571 ;
if ( V_566 )
F_323 ( V_566 , V_4 , V_576 ) ;
else
F_287 ( & V_219 , V_576 ) ;
F_298 ( V_576 , V_2 ) ;
while ( V_575 > 0 ) {
int V_578 = V_571 - F_26 ( V_4 ) -> V_91 ;
int V_527 = F_26 ( V_4 ) -> V_106 - V_571 ;
F_95 ( V_578 < 0 ) ;
if ( V_527 > 0 ) {
V_527 = F_17 ( V_575 , V_527 ) ;
if ( F_324 ( V_4 , V_578 , F_303 ( V_576 , V_527 ) , V_527 ) )
F_325 () ;
F_26 ( V_576 ) -> V_106 += V_527 ;
V_575 -= V_527 ;
V_571 += V_527 ;
}
if ( ! F_55 ( V_571 , F_26 ( V_4 ) -> V_106 ) ) {
V_4 = F_316 ( V_2 , V_4 , V_566 , V_568 ) ;
if ( ! V_4 ||
V_4 == V_522 ||
( F_26 ( V_4 ) -> V_205 & ( V_372 | V_207 ) ) )
goto V_534;
}
}
}
V_534:
F_326 (&tmp, skb, n)
F_318 ( V_568 , V_4 ) ;
}
static void F_327 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_4 , * V_570 ;
struct V_523 * V_524 ;
T_2 V_571 , V_534 ;
V_524 = F_282 ( & V_40 -> V_498 ) ;
V_4 = F_315 ( V_524 , struct V_3 , V_525 ) ;
V_579:
if ( ! V_4 ) {
V_524 = F_328 ( & V_40 -> V_498 ) ;
V_40 -> V_533 = F_283 ( V_524 , struct V_3 , V_525 ) ;
return;
}
V_571 = F_26 ( V_4 ) -> V_91 ;
V_534 = F_26 ( V_4 ) -> V_106 ;
for ( V_570 = V_4 ; ; ) {
V_4 = F_313 ( V_4 , NULL ) ;
if ( ! V_4 ||
F_62 ( F_26 ( V_4 ) -> V_91 , V_534 ) ||
F_55 ( F_26 ( V_4 ) -> V_106 , V_571 ) ) {
F_319 ( V_2 , NULL , & V_40 -> V_498 ,
V_570 , V_4 , V_571 , V_534 ) ;
goto V_579;
}
if ( F_11 ( F_55 ( F_26 ( V_4 ) -> V_91 , V_571 ) ) )
V_571 = F_26 ( V_4 ) -> V_91 ;
if ( F_62 ( F_26 ( V_4 ) -> V_106 , V_534 ) )
V_534 = F_26 ( V_4 ) -> V_106 ;
}
}
static bool F_292 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_523 * V_580 , * V_201 ;
if ( F_273 ( & V_40 -> V_498 ) )
return false ;
F_78 ( F_4 ( V_2 ) , V_581 ) ;
V_580 = & V_40 -> V_533 -> V_525 ;
do {
V_201 = F_329 ( V_580 ) ;
F_285 ( V_580 , & V_40 -> V_498 ) ;
F_278 ( V_2 , F_283 ( V_580 , struct V_3 , V_525 ) ) ;
F_60 ( V_2 ) ;
if ( F_51 ( & V_2 -> V_95 ) <= V_2 -> V_83 &&
! F_41 ( V_2 ) )
break;
V_580 = V_201 ;
} while ( V_580 );
V_40 -> V_533 = F_283 ( V_201 , struct V_3 , V_525 ) ;
if ( V_40 -> V_62 . V_134 )
F_244 ( & V_40 -> V_62 ) ;
return true ;
}
static int F_291 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
F_239 ( V_2 , L_22 , V_40 -> V_92 ) ;
F_78 ( F_4 ( V_2 ) , V_582 ) ;
if ( F_51 ( & V_2 -> V_95 ) >= V_2 -> V_83 )
F_48 ( V_2 ) ;
else if ( F_41 ( V_2 ) )
V_40 -> V_76 = F_17 ( V_40 -> V_76 , 4U * V_40 -> V_79 ) ;
F_327 ( V_2 ) ;
if ( ! F_330 ( & V_2 -> V_526 ) )
F_319 ( V_2 , & V_2 -> V_526 , NULL ,
F_331 ( & V_2 -> V_526 ) ,
NULL ,
V_40 -> V_92 , V_40 -> V_104 ) ;
F_60 ( V_2 ) ;
if ( F_51 ( & V_2 -> V_95 ) <= V_2 -> V_83 )
return 0 ;
F_292 ( V_2 ) ;
if ( F_51 ( & V_2 -> V_95 ) <= V_2 -> V_83 )
return 0 ;
F_78 ( F_4 ( V_2 ) , V_583 ) ;
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
if ( F_49 ( V_2 ) >= F_50 ( V_2 , 0 ) )
return false ;
if ( F_126 ( V_40 ) >= V_40 -> V_68 )
return false ;
return true ;
}
static void F_333 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_332 ( V_2 ) ) {
F_33 ( V_2 ) ;
V_40 -> V_94 = V_90 ;
}
V_2 -> V_584 ( V_2 ) ;
}
static void F_334 ( struct V_1 * V_2 )
{
if ( F_257 ( V_2 , V_585 ) ) {
F_335 ( V_2 , V_585 ) ;
F_336 () ;
if ( V_2 -> V_586 &&
F_337 ( V_587 , & V_2 -> V_586 -> V_409 ) ) {
F_333 ( V_2 ) ;
if ( ! F_337 ( V_587 , & V_2 -> V_586 -> V_409 ) )
F_205 ( V_2 , V_588 ) ;
}
}
}
static inline void F_338 ( struct V_1 * V_2 )
{
F_339 ( V_2 ) ;
F_334 ( V_2 ) ;
}
static void F_340 ( struct V_1 * V_2 , int V_589 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( ( ( V_40 -> V_104 - V_40 -> V_407 ) > F_8 ( V_2 ) -> V_15 . V_18 &&
F_341 ( V_2 ) >= V_40 -> V_30 ) ||
F_19 ( V_2 ) ||
( V_589 && ! F_273 ( & V_40 -> V_498 ) ) ) {
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
T_2 V_223 = F_156 ( V_53 -> V_590 ) ;
if ( V_223 && ! V_591 )
V_223 -- ;
V_223 += F_248 ( V_53 -> V_91 ) ;
if ( F_62 ( V_40 -> V_92 , V_223 ) )
return;
if ( F_55 ( V_223 , V_40 -> V_104 ) )
return;
if ( V_40 -> V_559 && ! F_62 ( V_223 , V_40 -> V_592 ) )
return;
F_346 ( V_2 ) ;
if ( V_40 -> V_592 == V_40 -> V_92 && V_40 -> V_559 &&
! F_257 ( V_2 , V_593 ) && V_40 -> V_92 != V_40 -> V_104 ) {
struct V_3 * V_4 = F_331 ( & V_2 -> V_526 ) ;
V_40 -> V_92 ++ ;
if ( V_4 && ! F_55 ( V_40 -> V_92 , F_26 ( V_4 ) -> V_106 ) ) {
F_317 ( V_4 , & V_2 -> V_526 ) ;
F_280 ( V_4 ) ;
}
}
V_40 -> V_559 = V_594 ;
V_40 -> V_592 = V_223 ;
V_40 -> V_392 = 0 ;
}
static void F_347 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_22 * V_53 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( V_53 -> V_595 )
F_345 ( V_2 , V_53 ) ;
if ( V_40 -> V_559 == V_594 ) {
T_2 V_223 = V_40 -> V_592 - F_248 ( V_53 -> V_91 ) + ( V_53 -> V_444 * 4 ) -
V_53 -> V_55 ;
if ( V_223 < V_4 -> V_5 ) {
T_6 V_219 ;
if ( F_324 ( V_4 , V_223 , & V_219 , 1 ) )
F_325 () ;
V_40 -> V_559 = V_596 | V_219 ;
if ( ! F_257 ( V_2 , V_486 ) )
V_2 -> V_564 ( V_2 ) ;
}
}
}
static int F_348 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_597 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
int V_560 = V_4 -> V_5 - V_597 ;
int V_176 ;
if ( F_349 ( V_4 ) )
V_176 = F_310 ( V_4 , V_597 , V_40 -> V_556 . V_275 , V_560 ) ;
else
V_176 = F_350 ( V_4 , V_597 , V_40 -> V_556 . V_275 ) ;
if ( ! V_176 ) {
V_40 -> V_556 . V_5 -= V_560 ;
V_40 -> V_92 += V_560 ;
F_57 ( V_2 ) ;
}
return V_176 ;
}
static bool F_351 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
return F_11 ( F_26 ( V_4 ) -> V_91 == ( V_40 -> V_104 - 1 ) &&
( 1 << V_2 -> V_478 ) & ( V_598 | V_599 |
V_600 ) ) ;
}
static bool F_352 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 , int V_601 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
bool V_602 = false ;
if ( F_249 ( V_4 , V_53 , V_40 ) && V_40 -> V_62 . V_273 &&
F_252 ( V_2 , V_4 ) ) {
if ( ! V_53 -> V_603 ) {
F_78 ( F_4 ( V_2 ) , V_604 ) ;
if ( ! F_221 ( F_4 ( V_2 ) , V_4 ,
V_605 ,
& V_40 -> V_393 ) )
F_269 ( V_2 , V_4 ) ;
goto V_606;
}
}
if ( ! F_253 ( V_40 , F_26 ( V_4 ) -> V_91 , F_26 ( V_4 ) -> V_106 ) ) {
if ( ! V_53 -> V_603 ) {
if ( V_53 -> V_55 )
goto V_607;
if ( ! F_221 ( F_4 ( V_2 ) , V_4 ,
V_608 ,
& V_40 -> V_393 ) )
F_269 ( V_2 , V_4 ) ;
} else if ( F_351 ( V_2 , V_4 ) ) {
F_255 ( V_2 ) ;
}
goto V_606;
}
if ( V_53 -> V_603 ) {
if ( F_26 ( V_4 ) -> V_91 == V_40 -> V_104 ||
F_351 ( V_2 , V_4 ) ) {
V_602 = true ;
} else if ( F_147 ( V_40 ) && V_40 -> V_62 . V_166 > 0 ) {
struct V_216 * V_165 = & V_40 -> V_511 [ 0 ] ;
int V_609 = V_165 [ 0 ] . V_106 ;
int V_510 ;
for ( V_510 = 1 ; V_510 < V_40 -> V_62 . V_166 ;
++ V_510 ) {
V_609 = F_62 ( V_165 [ V_510 ] . V_106 ,
V_609 ) ?
V_165 [ V_510 ] . V_106 : V_609 ;
}
if ( F_26 ( V_4 ) -> V_91 == V_609 )
V_602 = true ;
}
if ( V_602 )
F_255 ( V_2 ) ;
else
F_222 ( V_2 , V_4 ) ;
goto V_606;
}
if ( V_53 -> V_55 ) {
V_607:
if ( V_601 )
F_353 ( F_4 ( V_2 ) , V_610 ) ;
F_78 ( F_4 ( V_2 ) , V_611 ) ;
F_222 ( V_2 , V_4 ) ;
goto V_606;
}
return true ;
V_606:
F_278 ( V_2 , V_4 ) ;
return false ;
}
void F_354 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 , unsigned int V_5 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
if ( F_11 ( ! V_2 -> V_612 ) )
F_8 ( V_2 ) -> V_613 -> V_614 ( V_2 , V_4 ) ;
V_40 -> V_62 . V_273 = 0 ;
if ( ( F_13 ( V_53 ) & V_615 ) == V_40 -> V_392 &&
F_26 ( V_4 ) -> V_91 == V_40 -> V_104 &&
! F_62 ( F_26 ( V_4 ) -> V_171 , V_40 -> V_121 ) ) {
int V_25 = V_40 -> V_25 ;
if ( V_25 == sizeof( struct V_22 ) + V_475 ) {
if ( ! F_246 ( V_40 , V_53 ) )
goto V_616;
if ( ( T_7 ) ( V_40 -> V_62 . V_405 - V_40 -> V_62 . V_404 ) < 0 )
goto V_616;
}
if ( V_5 <= V_25 ) {
if ( V_5 == V_25 ) {
if ( V_25 ==
( sizeof( struct V_22 ) + V_475 ) &&
V_40 -> V_104 == V_40 -> V_407 )
F_227 ( V_40 ) ;
F_235 ( V_2 , V_4 , 0 ) ;
F_280 ( V_4 ) ;
F_338 ( V_2 ) ;
return;
} else {
F_353 ( F_4 ( V_2 ) , V_610 ) ;
goto V_606;
}
} else {
int V_521 = 0 ;
bool V_517 = false ;
if ( V_40 -> V_556 . V_557 == V_558 &&
V_40 -> V_92 == V_40 -> V_104 &&
V_5 - V_25 <= V_40 -> V_556 . V_5 &&
F_308 ( V_2 ) ) {
F_309 ( V_561 ) ;
if ( ! F_348 ( V_2 , V_4 , V_25 ) ) {
if ( V_25 ==
( sizeof( struct V_22 ) +
V_475 ) &&
V_40 -> V_104 == V_40 -> V_407 )
F_227 ( V_40 ) ;
F_56 ( V_2 , V_4 ) ;
F_300 ( V_4 , V_25 ) ;
F_215 ( V_40 , F_26 ( V_4 ) -> V_106 ) ;
F_78 ( F_4 ( V_2 ) ,
V_617 ) ;
V_521 = 1 ;
}
}
if ( ! V_521 ) {
if ( F_355 ( V_4 ) )
goto V_618;
if ( ( int ) V_4 -> V_73 > V_2 -> V_619 )
goto V_620;
if ( V_25 ==
( sizeof( struct V_22 ) + V_475 ) &&
V_40 -> V_104 == V_40 -> V_407 )
F_227 ( V_40 ) ;
F_56 ( V_2 , V_4 ) ;
F_78 ( F_4 ( V_2 ) , V_621 ) ;
V_521 = F_299 ( V_2 , V_4 , V_25 ,
& V_517 ) ;
}
F_58 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_171 != V_40 -> V_119 ) {
F_235 ( V_2 , V_4 , V_426 ) ;
F_338 ( V_2 ) ;
if ( ! F_344 ( V_2 ) )
goto V_622;
}
F_340 ( V_2 , 0 ) ;
V_622:
if ( V_521 )
F_288 ( V_4 , V_517 ) ;
V_2 -> V_564 ( V_2 ) ;
return;
}
}
V_616:
if ( V_5 < ( V_53 -> V_444 << 2 ) || F_355 ( V_4 ) )
goto V_618;
if ( ! V_53 -> V_346 && ! V_53 -> V_603 && ! V_53 -> V_55 )
goto V_606;
if ( ! F_352 ( V_2 , V_4 , V_53 , 1 ) )
return;
V_620:
if ( F_235 ( V_2 , V_4 , V_421 | V_420 ) < 0 )
goto V_606;
F_56 ( V_2 , V_4 ) ;
F_347 ( V_2 , V_4 , V_53 ) ;
F_306 ( V_2 , V_4 ) ;
F_338 ( V_2 ) ;
F_343 ( V_2 ) ;
return;
V_618:
F_353 ( F_4 ( V_2 ) , V_623 ) ;
F_353 ( F_4 ( V_2 ) , V_610 ) ;
V_606:
F_278 ( V_2 , V_4 ) ;
}
void F_356 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
F_261 ( V_2 , V_492 ) ;
V_13 -> V_15 . V_111 = V_90 ;
if ( V_4 ) {
V_13 -> V_613 -> V_614 ( V_2 , V_4 ) ;
F_357 ( V_2 , V_4 ) ;
}
V_13 -> V_613 -> V_624 ( V_2 ) ;
F_358 ( V_2 ) ;
F_359 ( V_2 ) ;
V_40 -> V_625 = V_90 ;
F_45 ( V_2 ) ;
if ( F_257 ( V_2 , V_626 ) )
F_360 ( V_2 , F_361 ( V_40 ) ) ;
if ( ! V_40 -> V_62 . V_390 )
F_362 ( V_40 , V_40 -> V_387 ) ;
else
V_40 -> V_392 = 0 ;
if ( ! F_257 ( V_2 , V_486 ) ) {
V_2 -> V_499 ( V_2 ) ;
F_265 ( V_2 , V_627 , V_628 ) ;
}
}
static bool F_363 ( struct V_1 * V_2 , struct V_3 * V_629 ,
struct V_434 * V_433 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_3 * V_20 = V_40 -> V_630 ? F_109 ( V_2 ) : NULL ;
T_8 V_80 = V_40 -> V_62 . V_63 , V_631 = 0 ;
bool V_632 = false ;
if ( V_80 == V_40 -> V_62 . V_452 ) {
struct V_440 V_633 ;
F_364 ( & V_633 ) ;
V_633 . V_452 = V_633 . V_63 = 0 ;
F_241 ( V_629 , & V_633 , 0 , NULL ) ;
V_80 = V_633 . V_63 ;
}
if ( ! V_40 -> V_634 ) {
V_433 -> V_5 = - 1 ;
} else if ( V_40 -> V_635 ) {
V_632 = ( V_433 -> V_5 < 0 && V_20 ) ;
} else if ( V_433 -> V_5 < 0 && ! V_40 -> V_630 ) {
V_631 = V_40 -> V_636 ? 2 : 1 ;
}
F_365 ( V_2 , V_80 , V_433 , V_632 , V_631 ) ;
if ( V_20 ) {
F_116 (data, sk) {
if ( V_20 == F_114 ( V_2 ) ||
F_366 ( V_2 , V_20 , 1 ) )
break;
}
F_197 ( V_2 ) ;
F_78 ( F_4 ( V_2 ) ,
V_637 ) ;
return true ;
}
V_40 -> V_638 = V_40 -> V_630 ;
if ( V_40 -> V_638 )
F_78 ( F_4 ( V_2 ) ,
V_639 ) ;
F_367 ( V_2 , V_629 ) ;
return false ;
}
static int F_368 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_22 * V_53 )
{
struct V_12 * V_13 = F_8 ( V_2 ) ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_434 V_435 = { . V_5 = - 1 } ;
int V_640 = V_40 -> V_62 . V_63 ;
F_241 ( V_4 , & V_40 -> V_62 , 0 , & V_435 ) ;
if ( V_40 -> V_62 . V_273 && V_40 -> V_62 . V_105 )
V_40 -> V_62 . V_105 -= V_40 -> V_474 ;
if ( V_53 -> V_346 ) {
if ( ! F_62 ( F_26 ( V_4 ) -> V_171 , V_40 -> V_119 ) ||
F_62 ( F_26 ( V_4 ) -> V_171 , V_40 -> V_121 ) )
goto V_641;
if ( V_40 -> V_62 . V_273 && V_40 -> V_62 . V_105 &&
! F_206 ( V_40 -> V_62 . V_105 , V_40 -> V_274 ,
V_90 ) ) {
F_78 ( F_4 ( V_2 ) ,
V_642 ) ;
goto V_641;
}
if ( V_53 -> V_603 ) {
F_255 ( V_2 ) ;
goto V_606;
}
if ( ! V_53 -> V_55 )
goto V_643;
F_30 ( V_40 , V_53 ) ;
F_369 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
F_235 ( V_2 , V_4 , V_421 ) ;
V_40 -> V_104 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_407 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_387 = F_156 ( V_53 -> V_74 ) ;
if ( ! V_40 -> V_62 . V_456 ) {
V_40 -> V_62 . V_390 = V_40 -> V_62 . V_644 = 0 ;
V_40 -> V_77 = F_17 ( V_40 -> V_77 , 65535U ) ;
}
if ( V_40 -> V_62 . V_273 ) {
V_40 -> V_62 . V_460 = 1 ;
V_40 -> V_25 =
sizeof( struct V_22 ) + V_475 ;
V_40 -> V_79 -= V_475 ;
F_227 ( V_40 ) ;
} else {
V_40 -> V_25 = sizeof( struct V_22 ) ;
}
if ( F_147 ( V_40 ) && V_645 )
F_370 ( V_40 ) ;
F_371 ( V_2 ) ;
F_175 ( V_2 , V_13 -> V_311 ) ;
F_52 ( V_2 ) ;
V_40 -> V_92 = V_40 -> V_104 ;
F_336 () ;
F_356 ( V_2 , V_4 ) ;
if ( ( V_40 -> V_634 || V_40 -> V_630 ) &&
F_363 ( V_2 , V_4 , & V_435 ) )
return - 1 ;
if ( V_2 -> V_646 ||
V_13 -> V_647 . V_648 ||
V_13 -> V_15 . V_33 ) {
F_59 ( V_2 ) ;
F_18 ( V_2 ) ;
F_142 ( V_2 , V_649 ,
V_650 , V_264 ) ;
V_606:
F_278 ( V_2 , V_4 ) ;
return 0 ;
} else {
F_226 ( V_2 ) ;
}
return - 1 ;
}
if ( V_53 -> V_603 ) {
goto V_643;
}
if ( V_40 -> V_62 . V_406 && V_40 -> V_62 . V_273 &&
F_372 ( & V_40 -> V_62 , 0 ) )
goto V_643;
if ( V_53 -> V_55 ) {
F_261 ( V_2 , V_491 ) ;
if ( V_40 -> V_62 . V_273 ) {
V_40 -> V_62 . V_460 = 1 ;
F_227 ( V_40 ) ;
V_40 -> V_25 =
sizeof( struct V_22 ) + V_475 ;
} else {
V_40 -> V_25 = sizeof( struct V_22 ) ;
}
V_40 -> V_104 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_92 = V_40 -> V_104 ;
V_40 -> V_407 = F_26 ( V_4 ) -> V_91 + 1 ;
V_40 -> V_387 = F_156 ( V_53 -> V_74 ) ;
V_40 -> V_386 = F_26 ( V_4 ) -> V_91 ;
V_40 -> V_162 = V_40 -> V_387 ;
F_31 ( V_40 , V_53 ) ;
F_371 ( V_2 ) ;
F_175 ( V_2 , V_13 -> V_311 ) ;
F_52 ( V_2 ) ;
F_373 ( V_2 ) ;
#if 0
return -1;
#else
goto V_606;
#endif
}
V_643:
F_364 ( & V_40 -> V_62 ) ;
V_40 -> V_62 . V_63 = V_640 ;
goto V_606;
V_641:
F_364 ( & V_40 -> V_62 ) ;
V_40 -> V_62 . V_63 = V_640 ;
return 1 ;
}
int F_374 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_2 ) ;
const struct V_22 * V_53 = F_14 ( V_4 ) ;
struct V_341 * V_342 ;
int V_651 = 0 ;
bool V_652 ;
switch ( V_2 -> V_478 ) {
case V_484 :
goto V_606;
case V_653 :
if ( V_53 -> V_346 )
return 1 ;
if ( V_53 -> V_603 )
goto V_606;
if ( V_53 -> V_55 ) {
if ( V_53 -> V_520 )
goto V_606;
F_375 () ;
V_652 = V_13 -> V_613 -> V_654 ( V_2 , V_4 ) >= 0 ;
F_376 () ;
if ( ! V_652 )
return 1 ;
F_377 ( V_4 ) ;
return 0 ;
}
goto V_606;
case V_479 :
V_40 -> V_62 . V_273 = 0 ;
V_651 = F_368 ( V_2 , V_4 , V_53 ) ;
if ( V_651 >= 0 )
return V_651 ;
F_347 ( V_2 , V_4 , V_53 ) ;
F_280 ( V_4 ) ;
F_338 ( V_2 ) ;
return 0 ;
}
V_40 -> V_62 . V_273 = 0 ;
V_342 = V_40 -> V_348 ;
if ( V_342 ) {
F_166 ( V_2 -> V_478 != V_491 &&
V_2 -> V_478 != V_495 ) ;
if ( ! F_378 ( V_2 , V_4 , V_342 , true ) )
goto V_606;
}
if ( ! V_53 -> V_346 && ! V_53 -> V_603 && ! V_53 -> V_55 )
goto V_606;
if ( ! F_352 ( V_2 , V_4 , V_53 , 0 ) )
return 0 ;
V_652 = F_235 ( V_2 , V_4 , V_421 |
V_420 ) > 0 ;
switch ( V_2 -> V_478 ) {
case V_491 :
if ( ! V_652 )
return 1 ;
if ( ! V_40 -> V_115 )
F_192 ( V_2 , V_342 ) ;
if ( V_342 ) {
F_8 ( V_2 ) -> V_249 = 0 ;
F_379 ( V_2 , V_342 , false ) ;
} else {
V_13 -> V_613 -> V_624 ( V_2 ) ;
F_359 ( V_2 ) ;
F_371 ( V_2 ) ;
V_40 -> V_92 = V_40 -> V_104 ;
F_45 ( V_2 ) ;
}
F_336 () ;
F_261 ( V_2 , V_492 ) ;
V_2 -> V_499 ( V_2 ) ;
if ( V_2 -> V_586 )
F_265 ( V_2 , V_627 , V_628 ) ;
V_40 -> V_119 = F_26 ( V_4 ) -> V_171 ;
V_40 -> V_387 = F_156 ( V_53 -> V_74 ) << V_40 -> V_62 . V_390 ;
F_369 ( V_40 , F_26 ( V_4 ) -> V_91 ) ;
if ( V_40 -> V_62 . V_460 )
V_40 -> V_79 -= V_475 ;
if ( V_342 ) {
F_197 ( V_2 ) ;
} else
F_358 ( V_2 ) ;
if ( ! F_8 ( V_2 ) -> V_58 -> V_303 )
F_64 ( V_2 ) ;
V_40 -> V_625 = V_90 ;
F_52 ( V_2 ) ;
F_380 ( V_40 ) ;
break;
case V_495 : {
int V_655 ;
if ( V_342 ) {
if ( ! V_652 )
return 1 ;
F_379 ( V_2 , V_342 , false ) ;
F_197 ( V_2 ) ;
}
if ( V_40 -> V_119 != V_40 -> V_656 )
break;
F_261 ( V_2 , V_496 ) ;
V_2 -> V_488 |= V_657 ;
F_236 ( V_2 ) ;
if ( ! F_257 ( V_2 , V_486 ) ) {
V_2 -> V_499 ( V_2 ) ;
break;
}
if ( V_40 -> V_658 < 0 ||
( F_26 ( V_4 ) -> V_106 != F_26 ( V_4 ) -> V_91 &&
F_62 ( F_26 ( V_4 ) -> V_106 - V_53 -> V_520 , V_40 -> V_104 ) ) ) {
F_258 ( V_2 ) ;
F_78 ( F_4 ( V_2 ) , V_659 ) ;
return 1 ;
}
V_655 = F_381 ( V_2 ) ;
if ( V_655 > V_660 ) {
F_360 ( V_2 , V_655 - V_660 ) ;
} else if ( V_53 -> V_520 || F_308 ( V_2 ) ) {
F_360 ( V_2 , V_655 ) ;
} else {
F_262 ( V_2 , V_496 , V_655 ) ;
goto V_606;
}
break;
}
case V_493 :
if ( V_40 -> V_119 == V_40 -> V_656 ) {
F_262 ( V_2 , V_497 , 0 ) ;
goto V_606;
}
break;
case V_494 :
if ( V_40 -> V_119 == V_40 -> V_656 ) {
F_382 ( V_2 ) ;
F_258 ( V_2 ) ;
goto V_606;
}
break;
}
F_347 ( V_2 , V_4 , V_53 ) ;
switch ( V_2 -> V_478 ) {
case V_482 :
case V_493 :
case V_494 :
if ( ! F_55 ( F_26 ( V_4 ) -> V_91 , V_40 -> V_104 ) )
break;
case V_495 :
case V_496 :
if ( V_2 -> V_488 & V_489 ) {
if ( F_26 ( V_4 ) -> V_106 != F_26 ( V_4 ) -> V_91 &&
F_62 ( F_26 ( V_4 ) -> V_106 - V_53 -> V_520 , V_40 -> V_104 ) ) {
F_78 ( F_4 ( V_2 ) , V_659 ) ;
F_255 ( V_2 ) ;
return 1 ;
}
}
case V_492 :
F_306 ( V_2 , V_4 ) ;
V_651 = 1 ;
break;
}
if ( V_2 -> V_478 != V_484 ) {
F_338 ( V_2 ) ;
F_343 ( V_2 ) ;
}
if ( ! V_651 ) {
V_606:
F_278 ( V_2 , V_4 ) ;
}
return 0 ;
}
static inline void F_383 ( struct V_341 * V_342 , T_12 V_661 , int V_662 )
{
struct V_663 * V_664 = F_384 ( V_342 ) ;
if ( V_662 == V_279 )
F_385 ( L_23 ,
& V_664 -> V_665 , V_661 ) ;
#if F_158 ( V_282 )
else if ( V_662 == V_283 )
F_385 ( L_24 ,
& V_664 -> V_666 , V_661 ) ;
#endif
}
static void F_386 ( struct V_341 * V_342 ,
const struct V_3 * V_4 ,
const struct V_1 * V_667 ,
const struct V_36 * V_37 )
{
const struct V_22 * V_53 = F_14 ( V_4 ) ;
const struct V_243 * V_243 = F_4 ( V_667 ) ;
bool V_668 = V_53 -> V_54 && V_53 -> V_44 ;
bool V_669 , V_670 ;
T_2 V_671 ;
if ( ! V_668 )
return;
V_669 = ! F_387 ( F_26 ( V_4 ) -> V_46 ) ;
V_671 = F_388 ( V_37 , V_672 ) ;
V_670 = V_243 -> V_255 . V_673 || V_671 ;
if ( ( ! V_669 && V_670 ) || F_27 ( V_667 ) ||
( V_671 & V_674 ) )
F_384 ( V_342 ) -> V_670 = 1 ;
}
static void F_389 ( struct V_341 * V_342 ,
const struct V_440 * V_62 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_663 * V_664 = F_384 ( V_342 ) ;
V_342 -> V_675 = 0 ;
V_342 -> V_676 = 0 ;
F_193 ( V_342 ) -> V_677 = F_26 ( V_4 ) -> V_91 ;
F_193 ( V_342 ) -> V_104 = F_26 ( V_4 ) -> V_91 + 1 ;
F_194 ( & F_193 ( V_342 ) -> V_344 ) ;
F_193 ( V_342 ) -> V_393 = 0 ;
V_342 -> V_80 = V_62 -> V_63 ;
V_342 -> V_404 = V_62 -> V_273 ? V_62 -> V_405 : 0 ;
V_664 -> V_460 = V_62 -> V_460 ;
V_664 -> V_134 = V_62 -> V_134 ;
V_664 -> V_390 = V_62 -> V_390 ;
V_664 -> V_456 = V_62 -> V_456 ;
V_664 -> V_242 = 0 ;
V_664 -> V_670 = 0 ;
V_664 -> V_678 = F_14 ( V_4 ) -> V_679 ;
V_664 -> V_680 = F_156 ( F_14 ( V_4 ) -> V_681 ) ;
V_664 -> V_682 = F_390 ( V_2 , V_4 ) ;
}
struct V_341 * F_391 ( const struct V_683 * V_684 ,
struct V_1 * V_685 ,
bool V_686 )
{
struct V_341 * V_342 = F_392 ( V_684 , V_685 ,
V_686 ) ;
if ( V_342 ) {
struct V_663 * V_664 = F_384 ( V_342 ) ;
F_393 ( V_664 , V_409 ) ;
V_664 -> V_633 = NULL ;
#if F_158 ( V_282 )
V_664 -> V_687 = NULL ;
#endif
F_394 ( & V_664 -> V_688 , 0 ) ;
V_664 -> V_689 = V_690 ;
F_395 ( & V_664 -> V_691 , F_4 ( V_685 ) ) ;
V_664 -> V_692 = V_685 -> V_278 ;
}
return V_342 ;
}
static bool F_396 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_693 )
{
struct V_694 * V_695 = & F_8 ( V_2 ) -> V_647 ;
const char * V_275 = L_25 ;
bool V_696 = false ;
struct V_243 * V_243 = F_4 ( V_2 ) ;
#ifdef F_397
if ( V_243 -> V_255 . V_697 ) {
V_275 = L_26 ;
V_696 = true ;
F_398 ( F_4 ( V_2 ) , V_698 ) ;
} else
#endif
F_398 ( F_4 ( V_2 ) , V_699 ) ;
if ( ! V_695 -> V_700 &&
V_243 -> V_255 . V_697 != 2 &&
F_399 ( & V_695 -> V_700 , 1 ) == 0 )
F_400 ( L_27 ,
V_693 , F_156 ( F_14 ( V_4 ) -> V_681 ) , V_275 ) ;
return V_696 ;
}
static void F_401 ( const struct V_1 * V_2 ,
struct V_341 * V_342 ,
const struct V_3 * V_4 )
{
if ( F_15 ( V_2 ) -> V_701 ) {
T_2 V_5 = F_402 ( V_4 ) + F_403 ( V_4 ) ;
T_2 * V_575 ;
V_575 = F_404 ( V_5 + sizeof( T_2 ) , V_181 ) ;
if ( V_575 ) {
V_575 [ 0 ] = V_5 ;
memcpy ( & V_575 [ 1 ] , F_405 ( V_4 ) , V_5 ) ;
V_342 -> V_702 = V_575 ;
}
}
}
int F_406 ( struct V_683 * V_703 ,
const struct V_704 * V_705 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_434 V_435 = { . V_5 = - 1 } ;
T_4 V_706 = F_26 ( V_4 ) -> V_707 ;
struct V_440 V_708 ;
struct V_39 * V_40 = F_15 ( V_2 ) ;
struct V_243 * V_243 = F_4 ( V_2 ) ;
struct V_1 * V_709 = NULL ;
struct V_36 * V_37 = NULL ;
struct V_341 * V_342 ;
bool V_696 = false ;
struct V_710 V_711 ;
if ( ( V_243 -> V_255 . V_697 == 2 ||
F_407 ( V_2 ) ) && ! V_706 ) {
V_696 = F_396 ( V_2 , V_4 , V_703 -> V_712 ) ;
if ( ! V_696 )
goto V_563;
}
if ( F_408 ( V_2 ) ) {
F_78 ( F_4 ( V_2 ) , V_713 ) ;
goto V_563;
}
V_342 = F_391 ( V_703 , V_2 , ! V_696 ) ;
if ( ! V_342 )
goto V_563;
F_193 ( V_342 ) -> V_714 = V_705 ;
F_193 ( V_342 ) -> V_715 = 0 ;
F_364 ( & V_708 ) ;
V_708 . V_63 = V_705 -> V_63 ;
V_708 . V_452 = V_40 -> V_62 . V_452 ;
F_241 ( V_4 , & V_708 , 0 , V_696 ? NULL : & V_435 ) ;
if ( V_696 && ! V_708 . V_273 )
F_364 ( & V_708 ) ;
V_708 . V_460 = V_708 . V_273 ;
F_389 ( V_342 , & V_708 , V_4 , V_2 ) ;
F_384 ( V_342 ) -> V_716 = F_155 ( V_2 ) -> V_717 ;
F_384 ( V_342 ) -> V_718 = F_409 ( V_2 , V_4 ) ;
V_705 -> V_719 ( V_342 , V_2 , V_4 ) ;
if ( F_410 ( V_2 , V_4 , V_342 ) )
goto V_720;
if ( V_706 && V_708 . V_460 )
V_705 -> V_721 ( V_4 , & F_193 ( V_342 ) -> V_715 ) ;
if ( ! V_696 && ! V_706 ) {
if ( V_243 -> V_255 . V_722 . V_723 ) {
bool V_724 ;
V_37 = V_705 -> V_725 ( V_2 , & V_711 , V_342 , & V_724 ) ;
if ( V_37 && V_724 &&
! F_411 ( V_342 , V_37 , true ,
V_708 . V_273 ) ) {
F_78 ( F_4 ( V_2 ) , V_726 ) ;
goto V_727;
}
}
else if ( ! V_243 -> V_255 . V_697 &&
( V_243 -> V_255 . V_728 - F_412 ( V_2 ) <
( V_243 -> V_255 . V_728 >> 2 ) ) &&
! F_411 ( V_342 , V_37 , false ,
V_708 . V_273 ) ) {
F_383 ( V_342 , F_156 ( F_14 ( V_4 ) -> V_679 ) ,
V_703 -> V_662 ) ;
goto V_727;
}
V_706 = V_705 -> V_721 ( V_4 , & F_193 ( V_342 ) -> V_715 ) ;
}
if ( ! V_37 ) {
V_37 = V_705 -> V_725 ( V_2 , & V_711 , V_342 , NULL ) ;
if ( ! V_37 )
goto V_720;
}
F_386 ( V_342 , V_4 , V_2 , V_37 ) ;
if ( V_696 ) {
V_706 = F_413 ( V_705 , V_2 , V_4 , & V_342 -> V_80 ) ;
F_193 ( V_342 ) -> V_715 = 0 ;
V_342 -> V_676 = V_708 . V_460 ;
if ( ! V_708 . V_460 )
F_384 ( V_342 ) -> V_670 = 0 ;
}
F_193 ( V_342 ) -> V_729 = V_706 ;
F_193 ( V_342 ) -> V_730 = F_414 () ;
F_415 ( V_342 , V_2 , V_37 ) ;
if ( ! V_696 ) {
F_401 ( V_2 , V_342 , V_4 ) ;
V_709 = F_416 ( V_2 , V_4 , V_342 , & V_435 , V_37 ) ;
}
if ( V_709 ) {
V_705 -> V_731 ( V_709 , V_37 , & V_711 , V_342 ,
& V_435 , V_732 ) ;
F_417 ( V_2 , V_342 , V_709 ) ;
V_2 -> V_564 ( V_2 ) ;
F_418 ( V_709 ) ;
F_419 ( V_709 ) ;
} else {
F_193 ( V_342 ) -> V_733 = false ;
if ( ! V_696 )
F_420 ( V_2 , V_342 , V_734 ) ;
V_705 -> V_731 ( V_2 , V_37 , & V_711 , V_342 , & V_435 ,
! V_696 ? V_735 :
V_736 ) ;
if ( V_696 ) {
F_421 ( V_342 ) ;
return 0 ;
}
}
F_422 ( V_342 ) ;
return 0 ;
V_727:
F_423 ( V_37 ) ;
V_720:
F_421 ( V_342 ) ;
V_563:
F_424 ( V_2 ) ;
return 0 ;
}
