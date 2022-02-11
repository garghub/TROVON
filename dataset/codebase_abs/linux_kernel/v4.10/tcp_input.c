static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static bool T_1 V_5 ;
if ( ! T_1 ) {
struct V_6 * V_7 ;
T_1 = true ;
F_2 () ;
V_7 = F_3 ( F_4 ( V_2 ) , V_4 -> V_8 ) ;
F_5 ( L_1 ,
V_7 ? V_7 -> V_9 : L_2 ) ;
F_6 () ;
}
}
static void F_7 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
const unsigned int V_12 = V_11 -> V_13 . V_14 ;
unsigned int V_15 ;
V_11 -> V_13 . V_14 = 0 ;
V_15 = F_9 ( V_4 ) -> V_16 ? : V_4 -> V_15 ;
if ( V_15 >= V_11 -> V_13 . V_17 ) {
V_11 -> V_13 . V_17 = F_10 (unsigned int, len,
tcp_sk(sk)->advmss) ;
if ( F_11 ( V_11 -> V_13 . V_17 != V_15 ) )
F_1 ( V_2 , V_4 ) ;
} else {
V_15 += V_4 -> V_18 - F_12 ( V_4 ) ;
if ( V_15 >= V_19 + sizeof( struct V_20 ) ||
( V_15 >= V_21 + sizeof( struct V_20 ) &&
! ( F_13 ( F_14 ( V_4 ) ) & V_22 ) ) ) {
V_15 -= F_15 ( V_2 ) -> V_23 ;
V_11 -> V_13 . V_14 = V_15 ;
if ( V_15 == V_12 ) {
V_11 -> V_13 . V_17 = V_15 ;
return;
}
}
if ( V_11 -> V_13 . V_24 & V_25 )
V_11 -> V_13 . V_24 |= V_26 ;
V_11 -> V_13 . V_24 |= V_25 ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
unsigned int V_27 = F_15 ( V_2 ) -> V_28 / ( 2 * V_11 -> V_13 . V_17 ) ;
if ( V_27 == 0 )
V_27 = 2 ;
if ( V_27 > V_11 -> V_13 . V_29 )
V_11 -> V_13 . V_29 = F_17 ( V_27 , V_30 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
F_16 ( V_2 ) ;
V_11 -> V_13 . V_31 = 0 ;
V_11 -> V_13 . V_32 = V_33 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
const struct V_34 * V_35 = F_20 ( V_2 ) ;
return ( V_35 && F_21 ( V_35 , V_36 ) ) ||
( V_11 -> V_13 . V_29 && ! V_11 -> V_13 . V_31 ) ;
}
static void F_22 ( struct V_37 * V_38 )
{
if ( V_38 -> V_39 & V_40 )
V_38 -> V_39 |= V_41 ;
}
static void F_23 ( struct V_37 * V_38 , const struct V_3 * V_4 )
{
if ( F_14 ( V_4 ) -> V_42 )
V_38 -> V_39 &= ~ V_43 ;
}
static void F_24 ( struct V_37 * V_38 )
{
V_38 -> V_39 &= ~ V_43 ;
}
static void F_25 ( struct V_37 * V_38 , const struct V_3 * V_4 )
{
switch ( F_26 ( V_4 ) -> V_44 & V_45 ) {
case V_46 :
if ( V_38 -> V_39 & V_47 )
F_18 ( (struct V_1 * ) V_38 ) ;
break;
case V_48 :
if ( F_27 ( (struct V_1 * ) V_38 ) )
F_28 ( (struct V_1 * ) V_38 , V_49 ) ;
if ( ! ( V_38 -> V_39 & V_43 ) ) {
F_18 ( (struct V_1 * ) V_38 ) ;
V_38 -> V_39 |= V_43 ;
}
V_38 -> V_39 |= V_47 ;
break;
default:
if ( F_27 ( (struct V_1 * ) V_38 ) )
F_28 ( (struct V_1 * ) V_38 , V_50 ) ;
V_38 -> V_39 |= V_47 ;
break;
}
}
static void F_29 ( struct V_37 * V_38 , const struct V_3 * V_4 )
{
if ( V_38 -> V_39 & V_40 )
F_25 ( V_38 , V_4 ) ;
}
static void F_30 ( struct V_37 * V_38 , const struct V_20 * V_51 )
{
if ( ( V_38 -> V_39 & V_40 ) && ( ! V_51 -> V_52 || V_51 -> V_42 ) )
V_38 -> V_39 &= ~ V_40 ;
}
static void F_31 ( struct V_37 * V_38 , const struct V_20 * V_51 )
{
if ( ( V_38 -> V_39 & V_40 ) && ( ! V_51 -> V_52 || ! V_51 -> V_42 ) )
V_38 -> V_39 &= ~ V_40 ;
}
static bool F_32 ( const struct V_37 * V_38 , const struct V_20 * V_51 )
{
if ( V_51 -> V_52 && ! V_51 -> V_53 && ( V_38 -> V_39 & V_40 ) )
return true ;
return false ;
}
static void F_33 ( struct V_1 * V_2 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
const struct V_54 * V_55 = F_8 ( V_2 ) -> V_56 ;
int V_57 , V_58 ;
T_2 V_59 ;
V_58 = F_34 ( T_2 , V_38 -> V_60 . V_61 , V_38 -> V_62 ) +
V_63 +
F_35 ( sizeof( struct V_64 ) ) ;
V_58 = F_36 ( V_58 ) +
F_35 ( sizeof( struct V_3 ) ) ;
V_59 = F_34 ( T_2 , V_65 , V_38 -> V_66 ) ;
V_59 = F_34 ( T_2 , V_59 , V_38 -> V_67 + 1 ) ;
V_57 = V_55 -> V_68 ? V_55 -> V_68 ( V_2 ) : 2 ;
V_57 *= V_59 * V_58 ;
if ( V_2 -> V_69 < V_57 )
V_2 -> V_69 = F_17 ( V_57 , V_70 [ 2 ] ) ;
}
static int F_37 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_71 = F_38 ( V_4 -> V_71 ) >> 1 ;
int V_72 = F_38 ( V_73 [ 2 ] ) >> 1 ;
while ( V_38 -> V_74 <= V_72 ) {
if ( V_71 <= V_4 -> V_15 )
return 2 * F_8 ( V_2 ) -> V_13 . V_17 ;
V_71 >>= 1 ;
V_72 >>= 1 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_38 -> V_74 < V_38 -> V_75 &&
( int ) V_38 -> V_74 < F_40 ( V_2 ) &&
! F_41 ( V_2 ) ) {
int V_76 ;
if ( F_38 ( V_4 -> V_71 ) <= V_4 -> V_15 )
V_76 = 2 * V_38 -> V_77 ;
else
V_76 = F_37 ( V_2 , V_4 ) ;
if ( V_76 ) {
V_76 = F_34 ( int , V_76 , 2 * V_4 -> V_15 ) ;
V_38 -> V_74 = F_17 ( V_38 -> V_74 + V_76 ,
V_38 -> V_75 ) ;
F_8 ( V_2 ) -> V_13 . V_29 |= 1 ;
}
}
}
static void F_42 ( struct V_1 * V_2 )
{
T_2 V_78 = F_15 ( V_2 ) -> V_77 ;
int V_79 ;
V_79 = 2 * F_43 ( V_78 + V_63 ) *
F_44 ( V_78 ) ;
if ( V_80 )
V_79 <<= 2 ;
if ( V_2 -> V_81 < V_79 )
V_2 -> V_81 = F_17 ( V_79 , V_73 [ 2 ] ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_82 ;
if ( ! ( V_2 -> V_83 & V_84 ) )
F_42 ( V_2 ) ;
if ( ! ( V_2 -> V_83 & V_85 ) )
F_33 ( V_2 ) ;
V_38 -> V_86 . V_87 = V_38 -> V_28 ;
V_38 -> V_86 . time = V_88 ;
V_38 -> V_86 . V_89 = V_38 -> V_90 ;
V_82 = F_46 ( V_2 ) ;
if ( V_38 -> V_75 >= V_82 ) {
V_38 -> V_75 = V_82 ;
if ( V_91 && V_82 > 4 * V_38 -> V_77 )
V_38 -> V_75 = F_47 ( V_82 -
( V_82 >> V_91 ) ,
4 * V_38 -> V_77 ) ;
}
if ( V_91 &&
V_38 -> V_75 > 2 * V_38 -> V_77 &&
V_38 -> V_75 + V_38 -> V_77 > V_82 )
V_38 -> V_75 = F_47 ( 2 * V_38 -> V_77 , V_82 - V_38 -> V_77 ) ;
V_38 -> V_74 = F_17 ( V_38 -> V_74 , V_38 -> V_75 ) ;
V_38 -> V_92 = V_88 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
V_11 -> V_13 . V_29 = 0 ;
if ( V_2 -> V_81 < V_73 [ 2 ] &&
! ( V_2 -> V_83 & V_84 ) &&
! F_41 ( V_2 ) &&
F_49 ( V_2 ) < F_50 ( V_2 , 0 ) ) {
V_2 -> V_81 = F_17 ( F_51 ( & V_2 -> V_93 ) ,
V_73 [ 2 ] ) ;
}
if ( F_51 ( & V_2 -> V_93 ) > V_2 -> V_81 )
V_38 -> V_74 = F_17 ( V_38 -> V_75 , 2U * V_38 -> V_77 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
unsigned int V_94 = F_10 (unsigned int, tp->advmss, tp->mss_cache) ;
V_94 = F_17 ( V_94 , V_38 -> V_28 / 2 ) ;
V_94 = F_17 ( V_94 , V_19 ) ;
V_94 = F_47 ( V_94 , V_21 ) ;
F_8 ( V_2 ) -> V_13 . V_17 = V_94 ;
}
static void F_53 ( struct V_37 * V_38 , T_2 V_95 , int V_96 )
{
T_2 V_97 = V_38 -> V_98 . V_99 ;
long V_100 = V_95 ;
if ( V_100 == 0 )
V_100 = 1 ;
if ( V_97 != 0 ) {
if ( ! V_96 ) {
V_100 -= ( V_97 >> 3 ) ;
V_97 += V_100 ;
} else {
V_100 <<= 3 ;
if ( V_100 < V_97 )
V_97 = V_100 ;
}
} else {
V_97 = V_100 << 3 ;
}
if ( V_38 -> V_98 . V_99 != V_97 )
V_38 -> V_98 . V_99 = V_97 ;
}
static inline void F_54 ( struct V_37 * V_38 )
{
if ( V_38 -> V_98 . time == 0 )
goto V_101;
if ( F_55 ( V_38 -> V_102 , V_38 -> V_98 . V_89 ) )
return;
F_53 ( V_38 , V_88 - V_38 -> V_98 . time , 1 ) ;
V_101:
V_38 -> V_98 . V_89 = V_38 -> V_102 + V_38 -> V_28 ;
V_38 -> V_98 . time = V_88 ;
}
static inline void F_56 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_38 -> V_60 . V_103 &&
( F_26 ( V_4 ) -> V_104 -
F_26 ( V_4 ) -> V_89 >= F_8 ( V_2 ) -> V_13 . V_17 ) )
F_53 ( V_38 , V_88 - V_38 -> V_60 . V_103 , 0 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int time ;
int V_105 ;
time = V_88 - V_38 -> V_86 . time ;
if ( time < ( V_38 -> V_98 . V_99 >> 3 ) || V_38 -> V_98 . V_99 == 0 )
return;
V_105 = V_38 -> V_90 - V_38 -> V_86 . V_89 ;
if ( V_105 <= V_38 -> V_86 . V_87 )
goto V_101;
if ( V_80 &&
! ( V_2 -> V_83 & V_84 ) ) {
int V_106 , V_79 , V_107 ;
V_106 = ( V_105 << 1 ) + 16 * V_38 -> V_77 ;
if ( V_105 >=
V_38 -> V_86 . V_87 + ( V_38 -> V_86 . V_87 >> 2 ) ) {
if ( V_105 >=
V_38 -> V_86 . V_87 + ( V_38 -> V_86 . V_87 >> 1 ) )
V_106 <<= 1 ;
else
V_106 += ( V_106 >> 1 ) ;
}
V_79 = F_43 ( V_38 -> V_77 + V_63 ) ;
while ( F_38 ( V_79 ) < V_38 -> V_77 )
V_79 += 128 ;
V_107 = F_17 ( V_106 / V_38 -> V_77 * V_79 , V_73 [ 2 ] ) ;
if ( V_107 > V_2 -> V_81 ) {
V_2 -> V_81 = V_107 ;
V_38 -> V_75 = V_106 ;
}
}
V_38 -> V_86 . V_87 = V_105 ;
V_101:
V_38 -> V_86 . V_89 = V_38 -> V_90 ;
V_38 -> V_86 . time = V_88 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
T_2 V_108 ;
F_59 ( V_2 ) ;
F_7 ( V_2 , V_4 ) ;
F_54 ( V_38 ) ;
V_108 = V_88 ;
if ( ! V_11 -> V_13 . V_32 ) {
F_16 ( V_2 ) ;
V_11 -> V_13 . V_32 = V_33 ;
} else {
int V_100 = V_108 - V_11 -> V_13 . V_109 ;
if ( V_100 <= V_33 / 2 ) {
V_11 -> V_13 . V_32 = ( V_11 -> V_13 . V_32 >> 1 ) + V_33 / 2 ;
} else if ( V_100 < V_11 -> V_13 . V_32 ) {
V_11 -> V_13 . V_32 = ( V_11 -> V_13 . V_32 >> 1 ) + V_100 ;
if ( V_11 -> V_13 . V_32 > V_11 -> V_110 )
V_11 -> V_13 . V_32 = V_11 -> V_110 ;
} else if ( V_100 > V_11 -> V_110 ) {
F_16 ( V_2 ) ;
F_60 ( V_2 ) ;
}
}
V_11 -> V_13 . V_109 = V_108 ;
F_29 ( V_38 , V_4 ) ;
if ( V_4 -> V_15 >= 128 )
F_39 ( V_2 , V_4 ) ;
}
static void F_61 ( struct V_1 * V_2 , long V_111 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
long V_100 = V_111 ;
T_2 V_112 = V_38 -> V_113 ;
if ( V_112 != 0 ) {
V_100 -= ( V_112 >> 3 ) ;
V_112 += V_100 ;
if ( V_100 < 0 ) {
V_100 = - V_100 ;
V_100 -= ( V_38 -> V_114 >> 2 ) ;
if ( V_100 > 0 )
V_100 >>= 3 ;
} else {
V_100 -= ( V_38 -> V_114 >> 2 ) ;
}
V_38 -> V_114 += V_100 ;
if ( V_38 -> V_114 > V_38 -> V_115 ) {
V_38 -> V_115 = V_38 -> V_114 ;
if ( V_38 -> V_115 > V_38 -> V_116 )
V_38 -> V_116 = V_38 -> V_115 ;
}
if ( F_62 ( V_38 -> V_117 , V_38 -> V_118 ) ) {
if ( V_38 -> V_115 < V_38 -> V_116 )
V_38 -> V_116 -= ( V_38 -> V_116 - V_38 -> V_115 ) >> 2 ;
V_38 -> V_118 = V_38 -> V_119 ;
V_38 -> V_115 = F_63 ( V_2 ) ;
}
} else {
V_112 = V_100 << 3 ;
V_38 -> V_114 = V_100 << 1 ;
V_38 -> V_116 = F_47 ( V_38 -> V_114 , F_63 ( V_2 ) ) ;
V_38 -> V_115 = V_38 -> V_116 ;
V_38 -> V_118 = V_38 -> V_119 ;
}
V_38 -> V_113 = F_47 ( 1U , V_112 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
T_3 V_120 ;
V_120 = ( T_3 ) V_38 -> V_62 * ( ( V_121 / 100 ) << 3 ) ;
if ( V_38 -> V_66 < V_38 -> V_122 / 2 )
V_120 *= V_123 ;
else
V_120 *= V_124 ;
V_120 *= F_47 ( V_38 -> V_66 , V_38 -> V_125 ) ;
if ( F_65 ( V_38 -> V_113 ) )
F_66 ( V_120 , V_38 -> V_113 ) ;
F_67 ( V_2 -> V_126 ) = F_10 ( T_3 , V_120 ,
V_2 -> V_127 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
F_8 ( V_2 ) -> V_110 = F_69 ( V_38 ) ;
F_70 ( V_2 ) ;
}
T_4 F_71 ( const struct V_37 * V_38 , const struct V_34 * V_35 )
{
T_4 V_128 = ( V_35 ? F_21 ( V_35 , V_129 ) : 0 ) ;
if ( ! V_128 )
V_128 = V_65 ;
return F_10 ( T_4 , V_128 , V_38 -> V_130 ) ;
}
void F_72 ( struct V_37 * V_38 )
{
if ( F_73 ( V_38 ) )
V_38 -> V_131 = NULL ;
V_38 -> V_60 . V_132 &= ~ V_133 ;
}
static void F_74 ( struct V_37 * V_38 )
{
V_38 -> V_60 . V_132 |= V_134 ;
}
static void F_75 ( struct V_1 * V_2 , const int V_135 ,
const int V_136 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_135 > V_38 -> V_67 ) {
int V_137 ;
V_38 -> V_67 = F_17 ( V_138 , V_135 ) ;
if ( V_136 )
V_137 = V_139 ;
else if ( F_76 ( V_38 ) )
V_137 = V_140 ;
else if ( F_73 ( V_38 ) )
V_137 = V_141 ;
else
V_137 = V_142 ;
F_77 ( F_4 ( V_2 ) , V_137 ) ;
#if V_143 > 1
F_78 ( L_3 ,
V_38 -> V_60 . V_132 , F_8 ( V_2 ) -> V_144 ,
V_38 -> V_67 ,
V_38 -> V_145 ,
V_38 -> V_146 ,
V_38 -> V_147 ? V_38 -> V_148 : 0 ) ;
#endif
F_72 ( V_38 ) ;
}
if ( V_135 > 0 )
F_79 ( V_38 ) ;
V_38 -> V_149 . V_150 = 1 ;
}
static void F_80 ( struct V_37 * V_38 , struct V_3 * V_4 )
{
if ( ! V_38 -> V_151 ||
F_55 ( F_26 ( V_4 ) -> V_89 ,
F_26 ( V_38 -> V_151 ) -> V_89 ) )
V_38 -> V_151 = V_4 ;
if ( ! V_38 -> V_152 ||
F_62 ( F_26 ( V_4 ) -> V_104 , V_38 -> V_153 ) )
V_38 -> V_153 = F_26 ( V_4 ) -> V_104 ;
}
static void F_81 ( struct V_37 * V_38 , struct V_3 * V_4 )
{
T_5 V_154 = F_26 ( V_4 ) -> V_154 ;
if ( ! ( V_154 & V_155 ) ||
( ( V_154 & V_155 ) && ( V_154 & V_156 ) ) )
V_38 -> V_157 += F_82 ( V_4 ) ;
}
static void F_83 ( struct V_37 * V_38 , struct V_3 * V_4 )
{
if ( ! ( F_26 ( V_4 ) -> V_154 & ( V_155 | V_158 ) ) ) {
F_80 ( V_38 , V_4 ) ;
V_38 -> V_152 += F_82 ( V_4 ) ;
F_81 ( V_38 , V_4 ) ;
F_26 ( V_4 ) -> V_154 |= V_155 ;
}
}
void F_84 ( struct V_37 * V_38 , struct V_3 * V_4 )
{
F_80 ( V_38 , V_4 ) ;
F_81 ( V_38 , V_4 ) ;
if ( ! ( F_26 ( V_4 ) -> V_154 & ( V_155 | V_158 ) ) ) {
V_38 -> V_152 += F_82 ( V_4 ) ;
F_26 ( V_4 ) -> V_154 |= V_155 ;
}
}
static bool F_85 ( struct V_37 * V_38 , bool V_159 ,
T_2 V_160 , T_2 V_104 )
{
if ( F_62 ( V_104 , V_38 -> V_119 ) || ! F_55 ( V_160 , V_104 ) )
return false ;
if ( ! F_55 ( V_160 , V_38 -> V_119 ) )
return false ;
if ( F_62 ( V_160 , V_38 -> V_117 ) )
return true ;
if ( ! V_159 || ! V_38 -> V_147 )
return false ;
if ( F_62 ( V_104 , V_38 -> V_117 ) )
return false ;
if ( ! F_55 ( V_160 , V_38 -> V_147 ) )
return true ;
if ( ! F_62 ( V_104 , V_38 -> V_147 ) )
return false ;
return ! F_55 ( V_160 , V_104 - V_38 -> V_161 ) ;
}
static bool F_86 ( struct V_1 * V_2 , const struct V_3 * V_162 ,
struct V_163 * V_164 , int V_165 ,
T_2 V_166 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_2 V_167 = F_87 ( & V_164 [ 0 ] . V_160 ) ;
T_2 V_168 = F_87 ( & V_164 [ 0 ] . V_104 ) ;
bool V_169 = false ;
if ( F_55 ( V_167 , F_26 ( V_162 ) -> V_170 ) ) {
V_169 = true ;
F_74 ( V_38 ) ;
F_77 ( F_4 ( V_2 ) , V_171 ) ;
} else if ( V_165 > 1 ) {
T_2 V_172 = F_87 ( & V_164 [ 1 ] . V_104 ) ;
T_2 V_173 = F_87 ( & V_164 [ 1 ] . V_160 ) ;
if ( ! F_62 ( V_168 , V_172 ) &&
! F_55 ( V_167 , V_173 ) ) {
V_169 = true ;
F_74 ( V_38 ) ;
F_77 ( F_4 ( V_2 ) ,
V_174 ) ;
}
}
if ( V_169 && V_38 -> V_147 && V_38 -> V_148 > 0 &&
! F_62 ( V_168 , V_166 ) &&
F_62 ( V_168 , V_38 -> V_147 ) )
V_38 -> V_148 -- ;
return V_169 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_160 , T_2 V_104 )
{
int V_175 ;
bool V_176 ;
unsigned int V_177 ;
unsigned int V_78 ;
V_176 = ! F_62 ( V_160 , F_26 ( V_4 ) -> V_89 ) &&
! F_55 ( V_104 , F_26 ( V_4 ) -> V_104 ) ;
if ( F_82 ( V_4 ) > 1 && ! V_176 &&
F_62 ( F_26 ( V_4 ) -> V_104 , V_160 ) ) {
V_78 = F_89 ( V_4 ) ;
V_176 = ! F_62 ( V_160 , F_26 ( V_4 ) -> V_89 ) ;
if ( ! V_176 ) {
V_177 = V_160 - F_26 ( V_4 ) -> V_89 ;
if ( V_177 < V_78 )
V_177 = V_78 ;
} else {
V_177 = V_104 - F_26 ( V_4 ) -> V_89 ;
if ( V_177 < V_78 )
return - V_178 ;
}
if ( V_177 > V_78 ) {
unsigned int V_179 = ( V_177 / V_78 ) * V_78 ;
if ( ! V_176 && V_179 < V_177 ) {
V_179 += V_78 ;
if ( V_179 >= V_4 -> V_15 )
return 0 ;
}
V_177 = V_179 ;
}
V_175 = F_90 ( V_2 , V_4 , V_177 , V_78 , V_180 ) ;
if ( V_175 < 0 )
return V_175 ;
}
return V_176 ;
}
static T_6 F_91 ( struct V_1 * V_2 ,
struct V_181 * V_182 , T_6 V_154 ,
T_2 V_160 , T_2 V_104 ,
int V_169 , int V_183 ,
const struct V_184 * V_185 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_186 = V_182 -> V_186 ;
if ( V_169 && ( V_154 & V_187 ) ) {
if ( V_38 -> V_147 && V_38 -> V_148 > 0 &&
F_62 ( V_104 , V_38 -> V_147 ) )
V_38 -> V_148 -- ;
if ( V_154 & V_158 )
V_182 -> V_150 = F_17 ( V_186 , V_182 -> V_150 ) ;
}
if ( ! F_62 ( V_104 , V_38 -> V_117 ) )
return V_154 ;
if ( ! ( V_154 & V_158 ) ) {
F_92 ( V_38 , V_185 , V_154 ) ;
if ( V_154 & V_156 ) {
if ( V_154 & V_155 ) {
V_154 &= ~ ( V_155 | V_156 ) ;
V_38 -> V_152 -= V_183 ;
V_38 -> V_188 -= V_183 ;
}
} else {
if ( ! ( V_154 & V_187 ) ) {
if ( F_55 ( V_160 ,
F_93 ( V_38 ) ) )
V_182 -> V_150 = F_17 ( V_186 ,
V_182 -> V_150 ) ;
if ( ! F_62 ( V_104 , V_38 -> V_189 ) )
V_182 -> V_190 |= V_191 ;
if ( V_182 -> V_192 . V_193 == 0 )
V_182 -> V_192 = * V_185 ;
V_182 -> V_194 = * V_185 ;
}
if ( V_154 & V_155 ) {
V_154 &= ~ V_155 ;
V_38 -> V_152 -= V_183 ;
}
}
V_154 |= V_158 ;
V_182 -> V_190 |= V_195 ;
V_38 -> V_146 += V_183 ;
V_38 -> V_196 += V_183 ;
V_186 += V_183 ;
if ( ! F_73 ( V_38 ) && V_38 -> V_131 &&
F_55 ( V_160 , F_26 ( V_38 -> V_131 ) -> V_89 ) )
V_38 -> V_197 += V_183 ;
if ( V_186 > V_38 -> V_145 )
V_38 -> V_145 = V_186 ;
}
if ( V_169 && ( V_154 & V_156 ) ) {
V_154 &= ~ V_156 ;
V_38 -> V_188 -= V_183 ;
}
return V_154 ;
}
static bool F_94 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_181 * V_182 ,
unsigned int V_183 , int V_198 , int V_78 ,
bool V_169 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_199 = F_95 ( V_2 , V_4 ) ;
T_2 V_160 = F_26 ( V_4 ) -> V_89 ;
T_2 V_104 = V_160 + V_198 ;
F_96 ( ! V_183 ) ;
F_91 ( V_2 , V_182 , F_26 ( V_4 ) -> V_154 ,
V_160 , V_104 , V_169 , V_183 ,
& V_4 -> V_184 ) ;
F_97 ( V_2 , V_4 , V_182 -> V_120 ) ;
if ( V_4 == V_38 -> V_131 )
V_38 -> V_197 += V_183 ;
F_26 ( V_199 ) -> V_104 += V_198 ;
F_26 ( V_4 ) -> V_89 += V_198 ;
F_98 ( V_199 , V_183 ) ;
F_96 ( F_82 ( V_4 ) < V_183 ) ;
F_98 ( V_4 , - V_183 ) ;
if ( ! F_26 ( V_199 ) -> V_200 )
F_26 ( V_199 ) -> V_200 = V_78 ;
if ( F_82 ( V_4 ) <= 1 )
F_26 ( V_4 ) -> V_200 = 0 ;
F_26 ( V_199 ) -> V_154 |= ( F_26 ( V_4 ) -> V_154 & V_201 ) ;
if ( V_4 -> V_15 > 0 ) {
F_96 ( ! F_82 ( V_4 ) ) ;
F_77 ( F_4 ( V_2 ) , V_202 ) ;
return false ;
}
if ( V_4 == V_38 -> V_151 )
V_38 -> V_151 = V_199 ;
if ( V_4 == V_38 -> V_131 ) {
V_38 -> V_131 = V_199 ;
V_38 -> V_197 -= F_82 ( V_199 ) ;
}
F_26 ( V_199 ) -> V_203 |= F_26 ( V_4 ) -> V_203 ;
F_26 ( V_199 ) -> V_204 = F_26 ( V_4 ) -> V_204 ;
if ( F_26 ( V_4 ) -> V_203 & V_205 )
F_26 ( V_199 ) -> V_104 ++ ;
if ( V_4 == F_99 ( V_2 ) )
F_100 ( V_2 , V_4 ) ;
F_101 ( V_199 , V_4 ) ;
if ( F_11 ( F_26 ( V_199 ) -> V_206 . V_207 . V_193 ) )
F_26 ( V_199 ) -> V_206 . V_207 . V_193 = 0 ;
F_102 ( V_4 , V_2 ) ;
F_103 ( V_2 , V_4 ) ;
F_77 ( F_4 ( V_2 ) , V_208 ) ;
return true ;
}
static int F_104 ( const struct V_3 * V_4 )
{
return F_82 ( V_4 ) == 1 ? V_4 -> V_15 : F_89 ( V_4 ) ;
}
static int F_105 ( const struct V_3 * V_4 )
{
return ! F_106 ( V_4 ) && F_107 ( V_4 ) ;
}
static struct V_3 * F_108 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_181 * V_182 ,
T_2 V_160 , T_2 V_104 ,
bool V_169 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_199 ;
int V_78 ;
int V_183 = 0 ;
int V_15 ;
int V_176 ;
if ( ! F_109 ( V_2 ) )
goto V_209;
if ( ! V_169 &&
( F_26 ( V_4 ) -> V_154 & ( V_155 | V_156 ) ) == V_156 )
goto V_209;
if ( ! F_105 ( V_4 ) )
goto V_209;
if ( ! F_62 ( F_26 ( V_4 ) -> V_104 , V_38 -> V_117 ) )
goto V_209;
if ( F_11 ( V_4 == F_110 ( V_2 ) ) )
goto V_209;
V_199 = F_95 ( V_2 , V_4 ) ;
if ( ( F_26 ( V_199 ) -> V_154 & V_210 ) != V_158 )
goto V_209;
if ( ! F_111 ( V_199 ) )
goto V_209;
V_176 = ! F_62 ( V_160 , F_26 ( V_4 ) -> V_89 ) &&
! F_55 ( V_104 , F_26 ( V_4 ) -> V_104 ) ;
if ( V_176 ) {
V_15 = V_4 -> V_15 ;
V_183 = F_82 ( V_4 ) ;
V_78 = F_104 ( V_4 ) ;
if ( V_78 != F_104 ( V_199 ) )
goto V_209;
} else {
if ( ! F_62 ( F_26 ( V_4 ) -> V_104 , V_160 ) )
goto V_211;
if ( F_82 ( V_4 ) <= 1 )
goto V_211;
V_176 = ! F_62 ( V_160 , F_26 ( V_4 ) -> V_89 ) ;
if ( ! V_176 ) {
goto V_209;
}
V_15 = V_104 - F_26 ( V_4 ) -> V_89 ;
F_96 ( V_15 < 0 ) ;
F_96 ( V_15 > V_4 -> V_15 ) ;
V_78 = F_89 ( V_4 ) ;
if ( V_78 != F_104 ( V_199 ) )
goto V_209;
if ( V_15 == V_78 ) {
V_183 = 1 ;
} else if ( V_15 < V_78 ) {
goto V_211;
} else {
V_183 = V_15 / V_78 ;
V_15 = V_183 * V_78 ;
}
}
if ( ! F_62 ( F_26 ( V_4 ) -> V_89 + V_15 , V_38 -> V_117 ) )
goto V_209;
if ( ! F_112 ( V_199 , V_4 , V_15 ) )
goto V_209;
if ( ! F_94 ( V_2 , V_4 , V_182 , V_183 , V_15 , V_78 , V_169 ) )
goto V_212;
if ( V_199 == F_113 ( V_2 ) )
goto V_212;
V_4 = F_114 ( V_2 , V_199 ) ;
if ( ! F_105 ( V_4 ) ||
( V_4 == F_115 ( V_2 ) ) ||
( ( F_26 ( V_4 ) -> V_154 & V_210 ) != V_158 ) ||
( V_78 != F_104 ( V_4 ) ) )
goto V_212;
V_15 = V_4 -> V_15 ;
if ( F_112 ( V_199 , V_4 , V_15 ) ) {
V_183 += F_82 ( V_4 ) ;
F_94 ( V_2 , V_4 , V_182 , F_82 ( V_4 ) , V_15 , V_78 , 0 ) ;
}
V_212:
V_182 -> V_186 += V_183 ;
return V_199 ;
V_211:
return V_4 ;
V_209:
F_77 ( F_4 ( V_2 ) , V_213 ) ;
return NULL ;
}
static struct V_3 * F_116 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_214 * V_215 ,
struct V_181 * V_182 ,
T_2 V_160 , T_2 V_104 ,
bool V_216 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_217 ;
F_117 (skb, sk) {
int V_176 = 0 ;
bool V_169 = V_216 ;
if ( V_4 == F_115 ( V_2 ) )
break;
if ( ! F_55 ( F_26 ( V_4 ) -> V_89 , V_104 ) )
break;
if ( V_215 &&
F_55 ( F_26 ( V_4 ) -> V_89 , V_215 -> V_104 ) ) {
V_176 = F_88 ( V_2 , V_4 ,
V_215 -> V_160 ,
V_215 -> V_104 ) ;
if ( V_176 > 0 )
V_169 = true ;
}
if ( V_176 <= 0 ) {
V_217 = F_108 ( V_2 , V_4 , V_182 ,
V_160 , V_104 , V_169 ) ;
if ( V_217 ) {
if ( V_217 != V_4 ) {
V_4 = V_217 ;
continue;
}
V_176 = 0 ;
} else {
V_176 = F_88 ( V_2 , V_4 ,
V_160 ,
V_104 ) ;
}
}
if ( F_11 ( V_176 < 0 ) )
break;
if ( V_176 ) {
F_26 ( V_4 ) -> V_154 =
F_91 ( V_2 ,
V_182 ,
F_26 ( V_4 ) -> V_154 ,
F_26 ( V_4 ) -> V_89 ,
F_26 ( V_4 ) -> V_104 ,
V_169 ,
F_82 ( V_4 ) ,
& V_4 -> V_184 ) ;
F_97 ( V_2 , V_4 , V_182 -> V_120 ) ;
if ( ! F_55 ( F_26 ( V_4 ) -> V_89 ,
F_93 ( V_38 ) ) )
F_100 ( V_2 , V_4 ) ;
}
V_182 -> V_186 += F_82 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_118 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_181 * V_182 ,
T_2 V_218 )
{
F_117 (skb, sk) {
if ( V_4 == F_115 ( V_2 ) )
break;
if ( F_62 ( F_26 ( V_4 ) -> V_104 , V_218 ) )
break;
V_182 -> V_186 += F_82 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_119 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_214 * V_215 ,
struct V_181 * V_182 ,
T_2 V_218 )
{
if ( ! V_215 )
return V_4 ;
if ( F_55 ( V_215 -> V_160 , V_218 ) ) {
V_4 = F_118 ( V_4 , V_2 , V_182 , V_215 -> V_160 ) ;
V_4 = F_116 ( V_4 , V_2 , NULL , V_182 ,
V_215 -> V_160 , V_215 -> V_104 ,
1 ) ;
}
return V_4 ;
}
static int F_120 ( const struct V_37 * V_38 , const struct V_214 * V_219 )
{
return V_219 < V_38 -> V_220 + F_121 ( V_38 -> V_220 ) ;
}
static int
F_122 ( struct V_1 * V_2 , const struct V_3 * V_162 ,
T_2 V_166 , struct V_181 * V_182 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
const unsigned char * V_221 = ( F_12 ( V_162 ) +
F_26 ( V_162 ) -> V_154 ) ;
struct V_163 * V_222 = (struct V_163 * ) ( V_221 + 2 ) ;
struct V_214 V_164 [ V_223 ] ;
struct V_214 * V_219 ;
struct V_3 * V_4 ;
int V_165 = F_17 ( V_223 , ( V_221 [ 1 ] - V_224 ) >> 3 ) ;
int V_225 ;
bool V_226 = false ;
int V_227 , V_228 ;
int V_229 ;
V_182 -> V_190 = 0 ;
V_182 -> V_150 = V_38 -> V_125 ;
if ( ! V_38 -> V_146 ) {
if ( F_123 ( V_38 -> V_145 ) )
V_38 -> V_145 = 0 ;
F_124 ( V_2 ) ;
}
V_226 = F_86 ( V_2 , V_162 , V_222 ,
V_165 , V_166 ) ;
if ( V_226 ) {
V_182 -> V_190 |= V_230 ;
V_38 -> V_196 ++ ;
}
if ( F_55 ( F_26 ( V_162 ) -> V_170 , V_166 - V_38 -> V_161 ) )
return 0 ;
if ( ! V_38 -> V_125 )
goto V_212;
V_225 = 0 ;
V_229 = 0 ;
for ( V_227 = 0 ; V_227 < V_165 ; V_227 ++ ) {
bool V_169 = ! V_227 && V_226 ;
V_164 [ V_225 ] . V_160 = F_87 ( & V_222 [ V_227 ] . V_160 ) ;
V_164 [ V_225 ] . V_104 = F_87 ( & V_222 [ V_227 ] . V_104 ) ;
if ( ! F_85 ( V_38 , V_169 ,
V_164 [ V_225 ] . V_160 ,
V_164 [ V_225 ] . V_104 ) ) {
int V_137 ;
if ( V_169 ) {
if ( ! V_38 -> V_147 )
V_137 = V_231 ;
else
V_137 = V_232 ;
} else {
if ( ( F_26 ( V_162 ) -> V_170 != V_38 -> V_117 ) &&
! F_62 ( V_164 [ V_225 ] . V_104 , V_38 -> V_117 ) )
continue;
V_137 = V_233 ;
}
F_77 ( F_4 ( V_2 ) , V_137 ) ;
if ( V_227 == 0 )
V_229 = - 1 ;
continue;
}
if ( ! F_62 ( V_164 [ V_225 ] . V_104 , V_166 ) )
continue;
V_225 ++ ;
}
for ( V_227 = V_225 - 1 ; V_227 > 0 ; V_227 -- ) {
for ( V_228 = 0 ; V_228 < V_227 ; V_228 ++ ) {
if ( F_62 ( V_164 [ V_228 ] . V_160 , V_164 [ V_228 + 1 ] . V_160 ) ) {
F_125 ( V_164 [ V_228 ] , V_164 [ V_228 + 1 ] ) ;
if ( V_228 == V_229 )
V_229 = V_228 + 1 ;
}
}
}
V_4 = F_110 ( V_2 ) ;
V_182 -> V_186 = 0 ;
V_227 = 0 ;
if ( ! V_38 -> V_146 ) {
V_219 = V_38 -> V_220 + F_121 ( V_38 -> V_220 ) ;
} else {
V_219 = V_38 -> V_220 ;
while ( F_120 ( V_38 , V_219 ) && ! V_219 -> V_160 &&
! V_219 -> V_104 )
V_219 ++ ;
}
while ( V_227 < V_225 ) {
T_2 V_160 = V_164 [ V_227 ] . V_160 ;
T_2 V_104 = V_164 [ V_227 ] . V_104 ;
bool V_169 = ( V_226 && ( V_227 == V_229 ) ) ;
struct V_214 * V_215 = NULL ;
if ( V_226 && ( ( V_227 + 1 ) == V_229 ) )
V_215 = & V_164 [ V_227 + 1 ] ;
while ( F_120 ( V_38 , V_219 ) &&
! F_55 ( V_160 , V_219 -> V_104 ) )
V_219 ++ ;
if ( F_120 ( V_38 , V_219 ) && ! V_169 &&
F_62 ( V_104 , V_219 -> V_160 ) ) {
if ( F_55 ( V_160 , V_219 -> V_160 ) ) {
V_4 = F_118 ( V_4 , V_2 , V_182 ,
V_160 ) ;
V_4 = F_116 ( V_4 , V_2 , V_215 ,
V_182 ,
V_160 ,
V_219 -> V_160 ,
V_169 ) ;
}
if ( ! F_62 ( V_104 , V_219 -> V_104 ) )
goto V_234;
V_4 = F_119 ( V_4 , V_2 , V_215 ,
V_182 ,
V_219 -> V_104 ) ;
if ( F_93 ( V_38 ) == V_219 -> V_104 ) {
V_4 = F_99 ( V_2 ) ;
if ( ! V_4 )
break;
V_182 -> V_186 = V_38 -> V_145 ;
V_219 ++ ;
goto V_235;
}
V_4 = F_118 ( V_4 , V_2 , V_182 , V_219 -> V_104 ) ;
V_219 ++ ;
continue;
}
if ( ! F_55 ( V_160 , F_93 ( V_38 ) ) ) {
V_4 = F_99 ( V_2 ) ;
if ( ! V_4 )
break;
V_182 -> V_186 = V_38 -> V_145 ;
}
V_4 = F_118 ( V_4 , V_2 , V_182 , V_160 ) ;
V_235:
V_4 = F_116 ( V_4 , V_2 , V_215 , V_182 ,
V_160 , V_104 , V_169 ) ;
V_234:
V_227 ++ ;
}
for ( V_227 = 0 ; V_227 < F_121 ( V_38 -> V_220 ) - V_225 ; V_227 ++ ) {
V_38 -> V_220 [ V_227 ] . V_160 = 0 ;
V_38 -> V_220 [ V_227 ] . V_104 = 0 ;
}
for ( V_228 = 0 ; V_228 < V_225 ; V_228 ++ )
V_38 -> V_220 [ V_227 ++ ] = V_164 [ V_228 ] ;
if ( ( V_182 -> V_150 < V_38 -> V_145 ) &&
( ( F_8 ( V_2 ) -> V_144 != V_236 ) || V_38 -> V_147 ) )
F_75 ( V_2 , V_38 -> V_145 - V_182 -> V_150 , 0 ) ;
F_126 ( V_38 ) ;
V_212:
#if V_143 > 0
F_123 ( ( int ) V_38 -> V_146 < 0 ) ;
F_123 ( ( int ) V_38 -> V_152 < 0 ) ;
F_123 ( ( int ) V_38 -> V_188 < 0 ) ;
F_123 ( ( int ) F_127 ( V_38 ) < 0 ) ;
#endif
return V_182 -> V_190 ;
}
static bool F_128 ( struct V_37 * V_38 )
{
T_2 V_237 ;
V_237 = F_47 ( V_38 -> V_152 , 1U ) ;
V_237 = F_17 ( V_237 , V_38 -> V_125 ) ;
if ( ( V_38 -> V_146 + V_237 ) > V_38 -> V_125 ) {
V_38 -> V_146 = V_38 -> V_125 - V_237 ;
return true ;
}
return false ;
}
static void F_129 ( struct V_1 * V_2 , const int V_238 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_128 ( V_38 ) )
F_75 ( V_2 , V_38 -> V_125 + V_238 , 0 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_2 V_239 = V_38 -> V_146 ;
V_38 -> V_146 ++ ;
F_129 ( V_2 , 0 ) ;
if ( V_38 -> V_146 > V_239 )
V_38 -> V_196 ++ ;
F_126 ( V_38 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_240 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_240 > 0 ) {
V_38 -> V_196 += F_34 ( int , V_240 - V_38 -> V_146 , 1 ) ;
if ( V_240 - 1 >= V_38 -> V_146 )
V_38 -> V_146 = 0 ;
else
V_38 -> V_146 -= V_240 - 1 ;
}
F_129 ( V_2 , V_240 ) ;
F_126 ( V_38 ) ;
}
static inline void F_132 ( struct V_37 * V_38 )
{
V_38 -> V_146 = 0 ;
}
void F_133 ( struct V_37 * V_38 )
{
V_38 -> V_188 = 0 ;
V_38 -> V_152 = 0 ;
V_38 -> V_147 = 0 ;
V_38 -> V_148 = - 1 ;
V_38 -> V_145 = 0 ;
V_38 -> V_146 = 0 ;
}
static inline void F_134 ( struct V_37 * V_38 )
{
V_38 -> V_147 = V_38 -> V_117 ;
V_38 -> V_148 = V_38 -> V_188 ? : - 1 ;
}
void F_135 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_241 * V_241 = F_4 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_242 = V_11 -> V_144 < V_243 ;
bool V_244 ;
bool V_245 ;
if ( V_11 -> V_144 <= V_246 ||
! F_62 ( V_38 -> V_189 , V_38 -> V_117 ) ||
( V_11 -> V_144 == V_236 && ! V_11 -> V_247 ) ) {
V_38 -> V_248 = F_136 ( V_2 ) ;
V_38 -> V_122 = V_11 -> V_56 -> V_249 ( V_2 ) ;
F_28 ( V_2 , V_250 ) ;
F_134 ( V_38 ) ;
}
V_38 -> V_66 = 1 ;
V_38 -> V_251 = 0 ;
V_38 -> V_92 = V_88 ;
V_38 -> V_188 = 0 ;
V_38 -> V_152 = 0 ;
if ( F_76 ( V_38 ) )
F_132 ( V_38 ) ;
V_4 = F_110 ( V_2 ) ;
V_244 = V_4 && ( F_26 ( V_4 ) -> V_154 & V_158 ) ;
if ( V_244 ) {
F_77 ( F_4 ( V_2 ) , V_252 ) ;
V_38 -> V_146 = 0 ;
V_38 -> V_145 = 0 ;
}
F_137 ( V_38 ) ;
F_138 (skb, sk) {
if ( V_4 == F_115 ( V_2 ) )
break;
V_245 = ( ! ( F_26 ( V_4 ) -> V_154 & V_158 ) ||
V_244 ) ;
if ( V_245 )
F_81 ( V_38 , V_4 ) ;
F_26 ( V_4 ) -> V_154 &= ( ~ V_210 ) | V_158 ;
if ( V_245 ) {
F_26 ( V_4 ) -> V_154 &= ~ V_158 ;
F_26 ( V_4 ) -> V_154 |= V_155 ;
V_38 -> V_152 += F_82 ( V_4 ) ;
V_38 -> V_153 = F_26 ( V_4 ) -> V_104 ;
}
}
F_126 ( V_38 ) ;
if ( V_11 -> V_144 <= V_246 &&
V_38 -> V_146 >= V_241 -> V_253 . V_254 )
V_38 -> V_67 = F_10 (unsigned int, tp->reordering,
net->ipv4.sysctl_tcp_reordering) ;
F_139 ( V_2 , V_236 ) ;
V_38 -> V_189 = V_38 -> V_119 ;
F_22 ( V_38 ) ;
V_38 -> V_255 = V_256 &&
( V_242 || V_11 -> V_247 ) &&
! F_8 ( V_2 ) -> V_257 . V_258 ;
}
static bool F_140 ( struct V_1 * V_2 , int V_190 )
{
if ( V_190 & V_259 ) {
struct V_37 * V_38 = F_15 ( V_2 ) ;
unsigned long V_260 = F_47 ( F_141 ( V_38 -> V_113 >> 4 ) ,
F_142 ( 10 ) ) ;
F_143 ( V_2 , V_261 ,
V_260 , V_262 ) ;
return true ;
}
return false ;
}
static inline int F_144 ( const struct V_37 * V_38 )
{
return F_76 ( V_38 ) ? V_38 -> V_146 + 1 : V_38 -> V_145 ;
}
static inline int F_145 ( const struct V_37 * V_38 )
{
return F_73 ( V_38 ) ? V_38 -> V_145 : V_38 -> V_146 + 1 ;
}
static bool F_146 ( struct V_1 * V_2 , int V_190 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
unsigned long V_260 ;
if ( V_263 < 2 || V_263 > 3 ||
( V_190 & V_264 ) || ! V_38 -> V_113 )
return false ;
V_260 = F_47 ( F_141 ( V_38 -> V_113 >> 5 ) ,
F_142 ( 2 ) ) ;
if ( ! F_147 ( F_8 ( V_2 ) -> V_265 , ( V_266 + V_260 ) ) )
return false ;
F_143 ( V_2 , V_267 , V_260 ,
V_262 ) ;
return true ;
}
static bool F_148 ( struct V_1 * V_2 , int V_190 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_4 V_125 ;
int V_268 = F_4 ( V_2 ) -> V_253 . V_254 ;
if ( V_38 -> V_152 )
return true ;
if ( F_145 ( V_38 ) > V_38 -> V_67 )
return true ;
V_125 = V_38 -> V_125 ;
if ( V_125 <= V_38 -> V_67 &&
V_38 -> V_146 >= F_34 ( T_4 , V_125 / 2 , V_268 ) &&
! F_149 ( V_2 ) ) {
return true ;
}
if ( ( V_38 -> V_269 || V_270 ) &&
F_150 ( V_38 ) && F_145 ( V_38 ) > 1 &&
F_151 ( V_38 ) && ! F_115 ( V_2 ) )
return true ;
if ( V_38 -> V_271 && ! V_38 -> V_188 && V_38 -> V_146 &&
( V_38 -> V_125 >= ( V_38 -> V_146 + 1 ) && V_38 -> V_125 < 4 ) &&
! F_149 ( V_2 ) )
return ! F_146 ( V_2 , V_190 ) ;
return false ;
}
static void F_152 ( struct V_1 * V_2 , int V_272 , int V_273 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
int V_274 , V_275 , V_157 ;
unsigned int V_78 ;
const T_2 V_276 = F_151 ( V_38 ) ? V_38 -> V_119 : V_38 -> V_189 ;
F_123 ( V_272 > V_38 -> V_125 ) ;
if ( V_38 -> V_131 ) {
V_4 = V_38 -> V_131 ;
V_274 = V_38 -> V_197 ;
if ( V_273 && V_4 != F_110 ( V_2 ) )
return;
} else {
V_4 = F_110 ( V_2 ) ;
V_274 = 0 ;
}
F_117 (skb, sk) {
if ( V_4 == F_115 ( V_2 ) )
break;
V_38 -> V_131 = V_4 ;
V_38 -> V_197 = V_274 ;
if ( F_62 ( F_26 ( V_4 ) -> V_104 , V_276 ) )
break;
V_275 = V_274 ;
if ( F_73 ( V_38 ) || F_76 ( V_38 ) ||
( F_26 ( V_4 ) -> V_154 & V_158 ) )
V_274 += F_82 ( V_4 ) ;
if ( V_274 > V_272 ) {
if ( ( F_151 ( V_38 ) && ! F_73 ( V_38 ) ) ||
( F_26 ( V_4 ) -> V_154 & V_158 ) ||
( V_275 >= V_272 ) )
break;
V_78 = F_89 ( V_4 ) ;
V_157 = ( V_272 - V_275 ) * V_78 ;
if ( V_157 < V_4 -> V_15 &&
F_90 ( V_2 , V_4 , V_157 , V_78 , V_180 ) < 0 )
break;
V_274 = V_272 ;
}
F_83 ( V_38 , V_4 ) ;
if ( V_273 )
break;
}
F_126 ( V_38 ) ;
}
static void F_153 ( struct V_1 * V_2 , int V_277 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_76 ( V_38 ) ) {
F_152 ( V_2 , 1 , 1 ) ;
} else if ( F_73 ( V_38 ) ) {
int V_157 = V_38 -> V_145 - V_38 -> V_67 ;
if ( V_157 <= 0 )
V_157 = 1 ;
F_152 ( V_2 , V_157 , 0 ) ;
} else {
int V_278 = V_38 -> V_146 - V_38 -> V_67 ;
if ( V_278 >= 0 )
F_152 ( V_2 , V_278 , 0 ) ;
else if ( V_277 )
F_152 ( V_2 , 1 , 1 ) ;
}
}
static bool F_154 ( const struct V_37 * V_38 , T_2 V_279 )
{
return V_38 -> V_60 . V_280 && V_38 -> V_60 . V_103 &&
F_55 ( V_38 -> V_60 . V_103 , V_279 ) ;
}
static bool F_155 ( const struct V_37 * V_38 ,
const struct V_3 * V_4 )
{
return ( F_26 ( V_4 ) -> V_154 & V_187 ) &&
F_154 ( V_38 , F_156 ( V_4 ) ) ;
}
static inline bool F_157 ( const struct V_37 * V_38 )
{
return ! V_38 -> V_281 ||
F_154 ( V_38 , V_38 -> V_281 ) ;
}
static bool F_158 ( const struct V_1 * V_2 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_38 -> V_188 )
return true ;
V_4 = F_110 ( V_2 ) ;
if ( F_11 ( V_4 && F_26 ( V_4 ) -> V_154 & V_201 ) )
return true ;
return false ;
}
static void F_159 ( struct V_1 * V_2 , const char * V_282 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_283 * V_284 = F_160 ( V_2 ) ;
if ( V_2 -> V_285 == V_286 ) {
F_78 ( L_4 ,
V_282 ,
& V_284 -> V_287 , F_161 ( V_284 -> V_288 ) ,
V_38 -> V_66 , F_162 ( V_38 ) ,
V_38 -> V_122 , V_38 -> V_248 ,
V_38 -> V_125 ) ;
}
#if F_163 ( V_289 )
else if ( V_2 -> V_285 == V_290 ) {
F_78 ( L_5 ,
V_282 ,
& V_2 -> V_291 , F_161 ( V_284 -> V_288 ) ,
V_38 -> V_66 , F_162 ( V_38 ) ,
V_38 -> V_122 , V_38 -> V_248 ,
V_38 -> V_125 ) ;
}
#endif
}
static void F_164 ( struct V_1 * V_2 , bool V_292 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_292 ) {
struct V_3 * V_4 ;
F_138 (skb, sk) {
if ( V_4 == F_115 ( V_2 ) )
break;
F_26 ( V_4 ) -> V_154 &= ~ V_155 ;
}
V_38 -> V_152 = 0 ;
F_137 ( V_38 ) ;
}
if ( V_38 -> V_248 ) {
const struct V_10 * V_11 = F_8 ( V_2 ) ;
V_38 -> V_66 = V_11 -> V_56 -> V_293 ( V_2 ) ;
if ( V_38 -> V_248 > V_38 -> V_122 ) {
V_38 -> V_122 = V_38 -> V_248 ;
F_24 ( V_38 ) ;
}
}
V_38 -> V_92 = V_88 ;
V_38 -> V_147 = 0 ;
}
static inline bool F_165 ( const struct V_37 * V_38 )
{
return V_38 -> V_147 && ( ! V_38 -> V_148 || F_157 ( V_38 ) ) ;
}
static bool F_166 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_165 ( V_38 ) ) {
int V_137 ;
F_159 ( V_2 , F_8 ( V_2 ) -> V_144 == V_236 ? L_6 : L_7 ) ;
F_164 ( V_2 , false ) ;
if ( F_8 ( V_2 ) -> V_144 == V_236 )
V_137 = V_294 ;
else
V_137 = V_295 ;
F_77 ( F_4 ( V_2 ) , V_137 ) ;
}
if ( V_38 -> V_117 == V_38 -> V_189 && F_76 ( V_38 ) ) {
if ( ! F_158 ( V_2 ) )
V_38 -> V_281 = 0 ;
return true ;
}
F_139 ( V_2 , V_296 ) ;
return false ;
}
static bool F_167 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_38 -> V_147 && ! V_38 -> V_148 ) {
F_159 ( V_2 , L_8 ) ;
F_164 ( V_2 , false ) ;
F_77 ( F_4 ( V_2 ) , V_297 ) ;
return true ;
}
return false ;
}
static bool F_168 ( struct V_1 * V_2 , bool V_298 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_298 || F_165 ( V_38 ) ) {
F_164 ( V_2 , true ) ;
F_159 ( V_2 , L_9 ) ;
F_77 ( F_4 ( V_2 ) , V_294 ) ;
if ( V_298 )
F_77 ( F_4 ( V_2 ) ,
V_299 ) ;
F_8 ( V_2 ) -> V_247 = 0 ;
if ( V_298 || F_151 ( V_38 ) )
F_139 ( V_2 , V_296 ) ;
return true ;
}
return false ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
V_38 -> V_189 = V_38 -> V_119 ;
V_38 -> V_300 = 0 ;
V_38 -> V_251 = 0 ;
V_38 -> V_301 = V_38 -> V_66 ;
V_38 -> V_302 = 0 ;
V_38 -> V_303 = 0 ;
V_38 -> V_122 = F_8 ( V_2 ) -> V_56 -> V_249 ( V_2 ) ;
F_22 ( V_38 ) ;
}
static void F_170 ( struct V_1 * V_2 , int V_304 ,
int V_190 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_305 = 0 ;
int V_306 = V_38 -> V_122 - F_127 ( V_38 ) ;
if ( V_304 <= 0 || F_171 ( ! V_38 -> V_301 ) )
return;
V_38 -> V_302 += V_304 ;
if ( V_306 < 0 ) {
T_3 V_307 = ( T_3 ) V_38 -> V_122 * V_38 -> V_302 +
V_38 -> V_301 - 1 ;
V_305 = F_172 ( V_307 , V_38 -> V_301 ) - V_38 -> V_303 ;
} else if ( ( V_190 & V_308 ) &&
! ( V_190 & V_309 ) ) {
V_305 = F_10 ( int , V_306 ,
F_34 ( int , V_38 -> V_302 - V_38 -> V_303 ,
V_304 ) + 1 ) ;
} else {
V_305 = F_17 ( V_306 , V_304 ) ;
}
V_305 = F_47 ( V_305 , ( V_38 -> V_303 ? 0 : 1 ) ) ;
V_38 -> V_66 = F_127 ( V_38 ) + V_305 ;
}
static inline void F_173 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_56 -> V_310 )
return;
if ( F_8 ( V_2 ) -> V_144 == V_311 ||
( V_38 -> V_147 && V_38 -> V_122 < V_312 ) ) {
V_38 -> V_66 = V_38 -> V_122 ;
V_38 -> V_92 = V_88 ;
}
F_28 ( V_2 , V_313 ) ;
}
void F_174 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
V_38 -> V_248 = 0 ;
if ( F_8 ( V_2 ) -> V_144 < V_311 ) {
V_38 -> V_147 = 0 ;
F_169 ( V_2 ) ;
F_139 ( V_2 , V_311 ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_182 = V_296 ;
if ( F_162 ( V_38 ) || F_158 ( V_2 ) )
V_182 = V_246 ;
if ( F_8 ( V_2 ) -> V_144 != V_182 ) {
F_139 ( V_2 , V_182 ) ;
V_38 -> V_189 = V_38 -> V_119 ;
}
}
static void F_176 ( struct V_1 * V_2 , int V_190 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
F_126 ( V_38 ) ;
if ( ! F_158 ( V_2 ) )
V_38 -> V_281 = 0 ;
if ( V_190 & V_264 )
F_174 ( V_2 ) ;
if ( F_8 ( V_2 ) -> V_144 != V_311 ) {
F_175 ( V_2 ) ;
}
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
V_11 -> V_257 . V_314 = V_11 -> V_257 . V_258 - 1 ;
V_11 -> V_257 . V_258 = 0 ;
F_77 ( F_4 ( V_2 ) , V_315 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
V_38 -> V_248 = F_136 ( V_2 ) ;
V_38 -> V_66 = V_38 -> V_66 *
F_179 ( V_2 , V_38 -> V_62 ) /
V_11 -> V_257 . V_258 ;
V_38 -> V_251 = 0 ;
V_38 -> V_92 = V_88 ;
V_38 -> V_122 = F_136 ( V_2 ) ;
V_11 -> V_257 . V_316 = V_11 -> V_257 . V_258 ;
V_11 -> V_257 . V_258 = 0 ;
F_180 ( V_2 , V_11 -> V_317 ) ;
F_77 ( F_4 ( V_2 ) , V_318 ) ;
}
void F_181 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_78 = F_182 ( V_2 ) ;
T_2 V_319 = V_38 -> V_152 ;
F_138 (skb, sk) {
if ( V_4 == F_115 ( V_2 ) )
break;
if ( F_104 ( V_4 ) > V_78 &&
! ( F_26 ( V_4 ) -> V_154 & V_158 ) ) {
if ( F_26 ( V_4 ) -> V_154 & V_156 ) {
F_26 ( V_4 ) -> V_154 &= ~ V_156 ;
V_38 -> V_188 -= F_82 ( V_4 ) ;
}
F_84 ( V_38 , V_4 ) ;
}
}
F_183 ( V_38 ) ;
if ( V_319 == V_38 -> V_152 )
return;
if ( F_76 ( V_38 ) )
F_128 ( V_38 ) ;
F_126 ( V_38 ) ;
if ( V_11 -> V_144 != V_236 ) {
V_38 -> V_189 = V_38 -> V_119 ;
V_38 -> V_122 = F_136 ( V_2 ) ;
V_38 -> V_248 = 0 ;
V_38 -> V_147 = 0 ;
F_139 ( V_2 , V_236 ) ;
}
F_184 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 , bool V_320 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_137 ;
if ( F_76 ( V_38 ) )
V_137 = V_321 ;
else
V_137 = V_322 ;
F_77 ( F_4 ( V_2 ) , V_137 ) ;
V_38 -> V_248 = 0 ;
F_134 ( V_38 ) ;
if ( ! F_186 ( V_2 ) ) {
if ( ! V_320 )
V_38 -> V_248 = F_136 ( V_2 ) ;
F_169 ( V_2 ) ;
}
F_139 ( V_2 , V_243 ) ;
}
static void F_187 ( struct V_1 * V_2 , int V_190 , bool V_323 ,
int * V_324 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
bool V_325 = ! F_55 ( V_38 -> V_117 , V_38 -> V_189 ) ;
if ( ( V_190 & V_326 ) &&
F_168 ( V_2 , false ) )
return;
if ( V_38 -> V_255 ) {
if ( ( V_190 & V_191 ) &&
F_168 ( V_2 , true ) )
return;
if ( F_62 ( V_38 -> V_119 , V_38 -> V_189 ) ) {
if ( V_190 & V_195 || V_323 )
V_38 -> V_255 = 0 ;
} else if ( V_190 & V_326 && ! V_325 ) {
V_38 -> V_189 = V_38 -> V_119 ;
if ( F_115 ( V_2 ) &&
F_62 ( F_188 ( V_38 ) , V_38 -> V_119 ) ) {
* V_324 = V_327 ;
return;
}
V_38 -> V_255 = 0 ;
}
}
if ( V_325 ) {
F_166 ( V_2 ) ;
return;
}
if ( F_76 ( V_38 ) ) {
if ( F_62 ( V_38 -> V_119 , V_38 -> V_189 ) && V_323 )
F_130 ( V_2 ) ;
else if ( V_190 & V_326 )
F_132 ( V_38 ) ;
}
* V_324 = V_328 ;
}
static bool F_189 ( struct V_1 * V_2 , const int V_240 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_38 -> V_147 && F_157 ( V_38 ) ) {
F_75 ( V_2 , F_144 ( V_38 ) + V_240 , 1 ) ;
if ( V_38 -> V_188 )
return true ;
if ( ! F_158 ( V_2 ) )
V_38 -> V_281 = 0 ;
F_159 ( V_2 , L_10 ) ;
F_164 ( V_2 , true ) ;
F_77 ( F_4 ( V_2 ) , V_329 ) ;
F_175 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_190 ( struct V_1 * V_2 , const int V_240 ,
bool V_323 , int * V_330 , int * V_324 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_277 = 0 , V_190 = * V_330 ;
bool V_331 = V_323 || ( ( V_190 & V_195 ) &&
( F_144 ( V_38 ) > V_38 -> V_67 ) ) ;
if ( F_123 ( ! V_38 -> V_125 && V_38 -> V_146 ) )
V_38 -> V_146 = 0 ;
if ( F_123 ( ! V_38 -> V_146 && V_38 -> V_145 ) )
V_38 -> V_145 = 0 ;
if ( V_190 & V_264 )
V_38 -> V_248 = 0 ;
if ( F_140 ( V_2 , V_190 ) )
return;
F_126 ( V_38 ) ;
if ( V_11 -> V_144 == V_296 ) {
F_123 ( V_38 -> V_188 != 0 ) ;
V_38 -> V_281 = 0 ;
} else if ( ! F_55 ( V_38 -> V_117 , V_38 -> V_189 ) ) {
switch ( V_11 -> V_144 ) {
case V_311 :
if ( V_38 -> V_117 != V_38 -> V_189 ) {
F_173 ( V_2 ) ;
F_139 ( V_2 , V_296 ) ;
}
break;
case V_243 :
if ( F_76 ( V_38 ) )
F_132 ( V_38 ) ;
if ( F_166 ( V_2 ) )
return;
F_173 ( V_2 ) ;
break;
}
}
if ( V_332 & V_333 &&
F_191 ( V_2 ) ) {
V_190 |= V_309 ;
* V_330 |= V_309 ;
}
switch ( V_11 -> V_144 ) {
case V_243 :
if ( ! ( V_190 & V_326 ) ) {
if ( F_76 ( V_38 ) && V_323 )
F_130 ( V_2 ) ;
} else {
if ( F_189 ( V_2 , V_240 ) )
return;
V_331 = F_76 ( V_38 ) ||
F_144 ( V_38 ) > V_38 -> V_67 ;
}
if ( F_167 ( V_2 ) ) {
F_175 ( V_2 ) ;
return;
}
break;
case V_236 :
F_187 ( V_2 , V_190 , V_323 , V_324 ) ;
if ( V_11 -> V_144 != V_296 &&
! ( V_190 & V_309 ) )
return;
default:
if ( F_76 ( V_38 ) ) {
if ( V_190 & V_326 )
F_132 ( V_38 ) ;
if ( V_323 )
F_130 ( V_2 ) ;
}
if ( V_11 -> V_144 <= V_246 )
F_167 ( V_2 ) ;
if ( ! F_148 ( V_2 , V_190 ) ) {
F_176 ( V_2 , V_190 ) ;
return;
}
if ( V_11 -> V_144 < V_311 &&
V_11 -> V_257 . V_258 &&
V_38 -> V_117 == V_38 -> V_334 . V_335 ) {
F_177 ( V_2 ) ;
V_38 -> V_66 ++ ;
F_181 ( V_2 ) ;
return;
}
F_185 ( V_2 , ( V_190 & V_264 ) ) ;
V_277 = 1 ;
}
if ( V_331 )
F_153 ( V_2 , V_277 ) ;
* V_324 = V_328 ;
}
static void F_192 ( struct V_1 * V_2 , T_2 V_336 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_2 V_337 = V_338 * V_339 ;
F_193 ( & V_38 -> V_340 , V_337 , V_88 ,
V_336 ? : F_194 ( 1 ) ) ;
}
static inline bool F_195 ( struct V_1 * V_2 , const int V_190 ,
long V_341 , long V_342 ,
long V_343 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_341 < 0 )
V_341 = V_342 ;
if ( V_341 < 0 && V_38 -> V_60 . V_280 && V_38 -> V_60 . V_103 &&
V_190 & V_344 )
V_341 = V_343 = F_194 ( V_88 -
V_38 -> V_60 . V_103 ) ;
if ( V_341 < 0 )
return false ;
F_192 ( V_2 , V_343 ) ;
F_61 ( V_2 , V_341 ) ;
F_68 ( V_2 ) ;
F_8 ( V_2 ) -> V_345 = 0 ;
return true ;
}
void F_196 ( struct V_1 * V_2 , struct V_346 * V_347 )
{
long V_336 = - 1L ;
if ( V_347 && ! V_347 -> V_348 && F_197 ( V_347 ) -> V_349 . V_193 ) {
struct V_184 V_108 ;
F_198 ( & V_108 ) ;
V_336 = F_199 ( & V_108 , & F_197 ( V_347 ) -> V_349 ) ;
}
F_195 ( V_2 , V_350 , V_336 , - 1L , V_336 ) ;
}
static void F_200 ( struct V_1 * V_2 , T_2 V_351 , T_2 V_240 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
V_11 -> V_56 -> V_352 ( V_2 , V_351 , V_240 ) ;
F_15 ( V_2 ) -> V_92 = V_88 ;
}
void F_201 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_38 -> V_353 )
return;
if ( ! V_38 -> V_125 ) {
F_202 ( V_2 , V_261 ) ;
} else {
T_2 V_354 = F_8 ( V_2 ) -> V_110 ;
if ( V_11 -> V_355 == V_267 ||
V_11 -> V_355 == V_356 ) {
struct V_3 * V_4 = F_110 ( V_2 ) ;
const T_2 V_357 =
F_156 ( V_4 ) + V_354 ;
T_7 V_306 = ( T_7 ) ( V_357 - V_88 ) ;
if ( V_306 > 0 )
V_354 = V_306 ;
}
F_143 ( V_2 , V_261 , V_354 ,
V_262 ) ;
}
}
void F_203 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
F_201 ( V_2 ) ;
if ( ! V_38 -> V_271 )
return;
F_185 ( V_2 , false ) ;
F_153 ( V_2 , 1 ) ;
F_184 ( V_2 ) ;
}
static T_2 F_204 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_2 V_358 ;
F_96 ( ! F_62 ( F_26 ( V_4 ) -> V_104 , V_38 -> V_117 ) ) ;
V_358 = F_82 ( V_4 ) ;
if ( F_205 ( V_2 , V_4 , V_38 -> V_117 - F_26 ( V_4 ) -> V_89 ) )
return 0 ;
V_358 -= F_82 ( V_4 ) ;
if ( V_358 ) {
F_96 ( F_82 ( V_4 ) == 0 ) ;
F_96 ( ! F_55 ( F_26 ( V_4 ) -> V_89 , F_26 ( V_4 ) -> V_104 ) ) ;
}
return V_358 ;
}
static void F_206 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_166 )
{
const struct V_64 * V_359 ;
if ( F_65 ( ! F_26 ( V_4 ) -> V_360 ) )
return;
V_359 = F_9 ( V_4 ) ;
if ( ! F_55 ( V_359 -> V_361 , V_166 ) &&
F_55 ( V_359 -> V_361 , F_15 ( V_2 ) -> V_117 ) )
F_207 ( V_4 , NULL , V_2 , V_362 ) ;
}
static int F_208 ( struct V_1 * V_2 , int V_363 ,
T_2 V_166 , int * V_240 ,
struct V_181 * V_364 ,
struct V_184 * V_108 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_184 V_365 , V_366 ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_2 V_239 = V_38 -> V_146 ;
T_2 V_150 = V_38 -> V_125 ;
bool V_367 = true ;
long V_342 = - 1L ;
long V_341 = - 1L ;
long V_343 = - 1L ;
struct V_3 * V_4 ;
T_2 V_368 = 0 ;
T_2 V_369 = 0 ;
bool V_370 ;
int V_190 = 0 ;
V_365 . V_193 = 0 ;
while ( ( V_4 = F_110 ( V_2 ) ) && V_4 != F_115 ( V_2 ) ) {
struct V_371 * V_372 = F_26 ( V_4 ) ;
T_6 V_154 = V_372 -> V_154 ;
T_2 V_373 ;
F_206 ( V_2 , V_4 , V_166 ) ;
if ( F_62 ( V_372 -> V_104 , V_38 -> V_117 ) ) {
if ( F_82 ( V_4 ) == 1 ||
! F_62 ( V_38 -> V_117 , V_372 -> V_89 ) )
break;
V_373 = F_204 ( V_2 , V_4 ) ;
if ( ! V_373 )
break;
V_367 = false ;
} else {
F_209 ( V_4 -> V_374 ) ;
V_373 = F_82 ( V_4 ) ;
}
if ( F_11 ( V_154 & V_187 ) ) {
if ( V_154 & V_156 )
V_38 -> V_188 -= V_373 ;
V_190 |= V_308 ;
} else if ( ! ( V_154 & V_158 ) ) {
V_366 = V_4 -> V_184 ;
F_171 ( V_366 . V_193 == 0 ) ;
if ( ! V_365 . V_193 )
V_365 = V_366 ;
V_369 = F_26 ( V_4 ) -> V_206 . V_375 ;
V_150 = F_17 ( V_368 , V_150 ) ;
if ( ! F_62 ( V_372 -> V_104 , V_38 -> V_189 ) )
V_190 |= V_191 ;
}
if ( V_154 & V_158 ) {
V_38 -> V_146 -= V_373 ;
} else if ( F_151 ( V_38 ) ) {
V_38 -> V_196 += V_373 ;
if ( ! F_155 ( V_38 , V_4 ) )
F_92 ( V_38 , & V_4 -> V_184 , V_154 ) ;
}
if ( V_154 & V_155 )
V_38 -> V_152 -= V_373 ;
V_38 -> V_125 -= V_373 ;
V_368 += V_373 ;
F_97 ( V_2 , V_4 , V_364 -> V_120 ) ;
if ( F_65 ( ! ( V_372 -> V_203 & V_376 ) ) ) {
V_190 |= V_377 ;
} else {
V_190 |= V_350 ;
V_38 -> V_281 = 0 ;
}
if ( ! V_367 )
break;
F_102 ( V_4 , V_2 ) ;
F_103 ( V_2 , V_4 ) ;
if ( F_11 ( V_4 == V_38 -> V_151 ) )
V_38 -> V_151 = NULL ;
if ( F_11 ( V_4 == V_38 -> V_131 ) )
V_38 -> V_131 = NULL ;
}
if ( ! V_4 )
F_210 ( V_2 , V_378 ) ;
if ( F_65 ( F_211 ( V_38 -> V_379 , V_166 , V_38 -> V_117 ) ) )
V_38 -> V_379 = V_38 -> V_117 ;
if ( V_4 && ( F_26 ( V_4 ) -> V_154 & V_158 ) )
V_190 |= V_259 ;
if ( F_65 ( V_365 . V_193 ) && ! ( V_190 & V_308 ) ) {
V_341 = F_199 ( V_108 , & V_365 ) ;
V_343 = F_199 ( V_108 , & V_366 ) ;
}
if ( V_364 -> V_192 . V_193 ) {
V_342 = F_199 ( V_108 , & V_364 -> V_192 ) ;
V_343 = F_199 ( V_108 , & V_364 -> V_194 ) ;
}
V_364 -> V_120 -> V_336 = V_343 ;
V_370 = F_195 ( V_2 , V_190 , V_341 , V_342 ,
V_343 ) ;
if ( V_190 & V_344 ) {
F_201 ( V_2 ) ;
if ( F_11 ( V_11 -> V_257 . V_258 &&
! F_62 ( V_38 -> V_334 . V_380 , V_38 -> V_117 ) ) ) {
F_178 ( V_2 ) ;
}
if ( F_76 ( V_38 ) ) {
F_131 ( V_2 , V_368 ) ;
} else {
int V_306 ;
if ( V_150 < V_363 )
F_75 ( V_2 , V_38 -> V_145 - V_150 , 0 ) ;
V_306 = F_73 ( V_38 ) ? V_368 :
V_239 - V_38 -> V_146 ;
V_38 -> V_197 -= F_17 ( V_38 -> V_197 , V_306 ) ;
}
V_38 -> V_145 -= F_17 ( V_368 , V_38 -> V_145 ) ;
} else if ( V_4 && V_370 && V_342 >= 0 &&
V_342 > F_199 ( V_108 , & V_4 -> V_184 ) ) {
F_201 ( V_2 ) ;
}
if ( V_11 -> V_56 -> V_368 ) {
struct V_381 V_95 = { . V_368 = V_368 ,
. V_336 = V_343 ,
. V_375 = V_369 } ;
V_11 -> V_56 -> V_368 ( V_2 , & V_95 ) ;
}
#if V_143 > 0
F_123 ( ( int ) V_38 -> V_146 < 0 ) ;
F_123 ( ( int ) V_38 -> V_152 < 0 ) ;
F_123 ( ( int ) V_38 -> V_188 < 0 ) ;
if ( ! V_38 -> V_125 && F_151 ( V_38 ) ) {
V_11 = F_8 ( V_2 ) ;
if ( V_38 -> V_152 ) {
F_78 ( L_11 ,
V_38 -> V_152 , V_11 -> V_144 ) ;
V_38 -> V_152 = 0 ;
}
if ( V_38 -> V_146 ) {
F_78 ( L_12 ,
V_38 -> V_146 , V_11 -> V_144 ) ;
V_38 -> V_146 = 0 ;
}
if ( V_38 -> V_188 ) {
F_78 ( L_13 ,
V_38 -> V_188 , V_11 -> V_144 ) ;
V_38 -> V_188 = 0 ;
}
}
#endif
* V_240 = V_368 ;
return V_190 ;
}
static void F_212 ( struct V_1 * V_2 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
if ( ! F_62 ( F_26 ( F_115 ( V_2 ) ) -> V_104 , F_188 ( V_38 ) ) ) {
V_11 -> V_345 = 0 ;
F_202 ( V_2 , V_382 ) ;
} else {
unsigned long V_279 = F_213 ( V_2 , V_262 ) ;
F_143 ( V_2 , V_382 ,
V_279 , V_262 ) ;
}
}
static inline bool F_214 ( const struct V_1 * V_2 , const int V_190 )
{
return ! ( V_190 & V_383 ) || ( V_190 & V_384 ) ||
F_8 ( V_2 ) -> V_144 != V_296 ;
}
static inline bool F_215 ( const struct V_1 * V_2 , const int V_190 )
{
if ( F_15 ( V_2 ) -> V_67 > F_4 ( V_2 ) -> V_253 . V_254 )
return V_190 & V_385 ;
return V_190 & V_377 ;
}
static void F_216 ( struct V_1 * V_2 , T_2 V_351 , T_2 V_386 ,
int V_190 , const struct V_387 * V_388 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
if ( V_11 -> V_56 -> V_310 ) {
V_11 -> V_56 -> V_310 ( V_2 , V_388 ) ;
return;
}
if ( F_186 ( V_2 ) ) {
F_170 ( V_2 , V_386 , V_190 ) ;
} else if ( F_215 ( V_2 , V_190 ) ) {
F_200 ( V_2 , V_351 , V_386 ) ;
}
F_64 ( V_2 ) ;
}
static inline bool F_217 ( const struct V_37 * V_38 ,
const T_2 V_351 , const T_2 V_170 ,
const T_2 V_389 )
{
return F_62 ( V_351 , V_38 -> V_117 ) ||
F_62 ( V_170 , V_38 -> V_390 ) ||
( V_170 == V_38 -> V_390 && V_389 > V_38 -> V_391 ) ;
}
static void F_218 ( struct V_37 * V_38 , T_2 V_351 )
{
T_2 V_306 = V_351 - V_38 -> V_117 ;
F_219 ( (struct V_1 * ) V_38 ) ;
V_38 -> V_392 += V_306 ;
V_38 -> V_117 = V_351 ;
}
static void F_220 ( struct V_37 * V_38 , T_2 V_89 )
{
T_2 V_306 = V_89 - V_38 -> V_102 ;
F_219 ( (struct V_1 * ) V_38 ) ;
V_38 -> V_393 += V_306 ;
V_38 -> V_102 = V_89 ;
}
static int F_221 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_2 V_351 ,
T_2 V_170 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_190 = 0 ;
T_2 V_389 = F_161 ( F_14 ( V_4 ) -> V_72 ) ;
if ( F_65 ( ! F_14 ( V_4 ) -> V_53 ) )
V_389 <<= V_38 -> V_60 . V_394 ;
if ( F_217 ( V_38 , V_351 , V_170 , V_389 ) ) {
V_190 |= V_395 ;
F_222 ( V_38 , V_170 ) ;
if ( V_38 -> V_391 != V_389 ) {
V_38 -> V_391 = V_389 ;
V_38 -> V_396 = 0 ;
F_223 ( V_2 ) ;
if ( F_115 ( V_2 ) )
F_224 ( V_2 ) ;
if ( V_389 > V_38 -> V_161 ) {
V_38 -> V_161 = V_389 ;
F_180 ( V_2 , F_8 ( V_2 ) -> V_317 ) ;
}
}
}
F_218 ( V_38 , V_351 ) ;
return V_190 ;
}
static bool F_225 ( struct V_241 * V_241 , int V_137 ,
T_2 * V_397 )
{
if ( * V_397 ) {
T_7 V_398 = ( T_7 ) ( V_88 - * V_397 ) ;
if ( 0 <= V_398 && V_398 < V_399 ) {
F_77 ( V_241 , V_137 ) ;
return true ;
}
}
* V_397 = V_88 ;
return false ;
}
bool F_226 ( struct V_241 * V_241 , const struct V_3 * V_4 ,
int V_137 , T_2 * V_397 )
{
if ( ( F_26 ( V_4 ) -> V_89 != F_26 ( V_4 ) -> V_104 ) &&
! F_14 ( V_4 ) -> V_53 )
return false ;
return F_225 ( V_241 , V_137 , V_397 ) ;
}
static void F_227 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_2 V_400 ;
static unsigned int V_401 ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_2 V_402 , V_108 ;
if ( F_225 ( F_4 ( V_2 ) ,
V_403 ,
& V_38 -> V_397 ) )
return;
V_108 = V_266 / V_339 ;
if ( V_108 != V_400 ) {
T_2 V_404 = ( V_405 + 1 ) >> 1 ;
V_400 = V_108 ;
F_228 ( V_401 , V_404 +
F_229 ( V_405 ) ) ;
}
V_402 = F_230 ( V_401 ) ;
if ( V_402 > 0 ) {
F_228 ( V_401 , V_402 - 1 ) ;
F_77 ( F_4 ( V_2 ) , V_406 ) ;
F_231 ( V_2 ) ;
}
}
static void F_232 ( struct V_37 * V_38 )
{
V_38 -> V_60 . V_407 = V_38 -> V_60 . V_408 ;
V_38 -> V_60 . V_409 = F_233 () ;
}
static void F_234 ( struct V_37 * V_38 , T_2 V_89 )
{
if ( V_38 -> V_60 . V_280 && ! F_62 ( V_89 , V_38 -> V_410 ) ) {
if ( F_235 ( & V_38 -> V_60 , 0 ) )
F_232 ( V_38 ) ;
}
}
static void F_236 ( struct V_1 * V_2 , T_2 V_351 , int V_190 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_55 ( V_351 , V_38 -> V_300 ) )
return;
if ( V_190 & V_230 ) {
V_38 -> V_300 = 0 ;
} else if ( F_62 ( V_351 , V_38 -> V_300 ) ) {
F_169 ( V_2 ) ;
F_139 ( V_2 , V_311 ) ;
F_173 ( V_2 ) ;
F_175 ( V_2 ) ;
F_77 ( F_4 ( V_2 ) ,
V_411 ) ;
} else if ( ! ( V_190 & ( V_326 |
V_383 | V_195 ) ) ) {
V_38 -> V_300 = 0 ;
}
}
static inline void F_237 ( struct V_1 * V_2 , T_2 V_412 )
{
const struct V_10 * V_11 = F_8 ( V_2 ) ;
if ( V_11 -> V_56 -> V_413 )
V_11 -> V_56 -> V_413 ( V_2 , V_412 ) ;
}
static void F_238 ( struct V_1 * V_2 , int V_324 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_324 == V_414 )
return;
if ( F_11 ( V_324 == 2 ) ) {
F_239 ( V_2 , F_182 ( V_2 ) ,
V_415 ) ;
if ( F_62 ( V_38 -> V_119 , V_38 -> V_189 ) )
return;
V_38 -> V_255 = 0 ;
}
F_184 ( V_2 ) ;
}
static int F_240 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_190 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_181 V_416 ;
struct V_387 V_388 = { . V_417 = 0 } ;
T_2 V_166 = V_38 -> V_117 ;
T_2 V_170 = F_26 ( V_4 ) -> V_89 ;
T_2 V_351 = F_26 ( V_4 ) -> V_170 ;
bool V_323 = false ;
T_2 V_363 ;
int V_418 = V_38 -> V_125 ;
T_2 V_196 = V_38 -> V_196 ;
T_2 V_157 = V_38 -> V_157 ;
int V_240 = 0 ;
int V_324 = V_414 ;
struct V_184 V_108 ;
V_416 . V_192 . V_193 = 0 ;
V_416 . V_120 = & V_388 ;
F_209 ( V_2 -> V_419 . V_374 ) ;
if ( F_55 ( V_351 , V_166 ) ) {
if ( F_55 ( V_351 , V_166 - V_38 -> V_161 ) ) {
F_227 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_420;
}
if ( F_62 ( V_351 , V_38 -> V_119 ) )
goto V_421;
F_198 ( & V_108 ) ;
if ( V_11 -> V_355 == V_267 ||
V_11 -> V_355 == V_356 )
F_201 ( V_2 ) ;
if ( F_62 ( V_351 , V_166 ) ) {
V_190 |= V_326 ;
V_11 -> V_247 = 0 ;
}
V_363 = V_38 -> V_145 ;
V_388 . V_422 = F_127 ( V_38 ) ;
if ( V_190 & V_423 )
F_234 ( V_38 , F_26 ( V_4 ) -> V_89 ) ;
if ( ! ( V_190 & V_424 ) && F_62 ( V_351 , V_166 ) ) {
F_222 ( V_38 , V_170 ) ;
F_218 ( V_38 , V_351 ) ;
V_190 |= V_395 ;
F_237 ( V_2 , V_425 ) ;
F_77 ( F_4 ( V_2 ) , V_426 ) ;
} else {
T_2 V_427 = V_428 ;
if ( V_170 != F_26 ( V_4 ) -> V_104 )
V_190 |= V_429 ;
else
F_77 ( F_4 ( V_2 ) , V_430 ) ;
V_190 |= F_221 ( V_2 , V_4 , V_351 , V_170 ) ;
if ( F_26 ( V_4 ) -> V_154 )
V_190 |= F_122 ( V_2 , V_4 , V_166 ,
& V_416 ) ;
if ( F_32 ( V_38 , F_14 ( V_4 ) ) ) {
V_190 |= V_264 ;
V_427 |= V_431 ;
}
if ( V_190 & V_395 )
V_427 |= V_425 ;
F_237 ( V_2 , V_427 ) ;
}
V_2 -> V_432 = 0 ;
V_11 -> V_433 = 0 ;
V_38 -> V_434 = V_88 ;
if ( ! V_418 )
goto V_435;
V_190 |= F_208 ( V_2 , V_363 , V_166 , & V_240 ,
& V_416 , & V_108 ) ;
if ( F_214 ( V_2 , V_190 ) ) {
V_323 = ! ( V_190 & ( V_326 | V_383 ) ) ;
F_190 ( V_2 , V_240 , V_323 , & V_190 , & V_324 ) ;
}
if ( V_38 -> V_300 )
F_236 ( V_2 , V_351 , V_190 ) ;
if ( ( V_190 & V_385 ) || ! ( V_190 & V_383 ) ) {
struct V_34 * V_35 = F_20 ( V_2 ) ;
if ( V_35 )
F_241 ( V_35 ) ;
}
if ( V_11 -> V_355 == V_261 )
F_242 ( V_2 ) ;
V_196 = V_38 -> V_196 - V_196 ;
V_157 = V_38 -> V_157 - V_157 ;
F_243 ( V_2 , V_196 , V_157 , & V_108 , & V_388 ) ;
F_216 ( V_2 , V_351 , V_196 , V_190 , & V_388 ) ;
F_238 ( V_2 , V_324 ) ;
return 1 ;
V_435:
if ( V_190 & V_230 )
F_190 ( V_2 , V_240 , V_323 , & V_190 , & V_324 ) ;
if ( F_115 ( V_2 ) )
F_212 ( V_2 ) ;
if ( V_38 -> V_300 )
F_236 ( V_2 , V_351 , V_190 ) ;
return 1 ;
V_421:
F_244 ( V_2 , L_14 , V_351 , V_38 -> V_117 , V_38 -> V_119 ) ;
return - 1 ;
V_420:
if ( F_26 ( V_4 ) -> V_154 ) {
V_190 |= F_122 ( V_2 , V_4 , V_166 ,
& V_416 ) ;
F_190 ( V_2 , V_240 , V_323 , & V_190 , & V_324 ) ;
F_238 ( V_2 , V_324 ) ;
}
F_244 ( V_2 , L_15 , V_351 , V_38 -> V_117 , V_38 -> V_119 ) ;
return 0 ;
}
static void F_245 ( int V_15 , const unsigned char * V_436 ,
bool V_53 , struct V_437 * V_438 ,
bool V_439 )
{
if ( ! V_438 || ! V_53 || V_15 < 0 || ( V_15 & 1 ) )
return;
if ( V_15 >= V_440 &&
V_15 <= V_441 )
memcpy ( V_438 -> V_442 , V_436 , V_15 ) ;
else if ( V_15 != 0 )
V_15 = - 1 ;
V_438 -> V_15 = V_15 ;
V_438 -> exp = V_439 ;
}
void F_246 ( const struct V_3 * V_4 ,
struct V_443 * V_444 , int V_445 ,
struct V_437 * V_438 )
{
const unsigned char * V_221 ;
const struct V_20 * V_51 = F_14 ( V_4 ) ;
int V_446 = ( V_51 -> V_447 * 4 ) - sizeof( struct V_20 ) ;
V_221 = ( const unsigned char * ) ( V_51 + 1 ) ;
V_444 -> V_280 = 0 ;
while ( V_446 > 0 ) {
int V_448 = * V_221 ++ ;
int V_449 ;
switch ( V_448 ) {
case V_450 :
return;
case V_451 :
V_446 -- ;
continue;
default:
V_449 = * V_221 ++ ;
if ( V_449 < 2 )
return;
if ( V_449 > V_446 )
return;
switch ( V_448 ) {
case V_452 :
if ( V_449 == V_453 && V_51 -> V_53 && ! V_445 ) {
T_8 V_454 = F_247 ( V_221 ) ;
if ( V_454 ) {
if ( V_444 -> V_455 &&
V_444 -> V_455 < V_454 )
V_454 = V_444 -> V_455 ;
V_444 -> V_61 = V_454 ;
}
}
break;
case V_456 :
if ( V_449 == V_457 && V_51 -> V_53 &&
! V_445 && V_458 ) {
T_5 V_394 = * ( T_5 * ) V_221 ;
V_444 -> V_459 = 1 ;
if ( V_394 > 14 ) {
F_248 ( L_16 ,
V_460 ,
V_394 ) ;
V_394 = 14 ;
}
V_444 -> V_394 = V_394 ;
}
break;
case V_461 :
if ( ( V_449 == V_462 ) &&
( ( V_445 && V_444 -> V_463 ) ||
( ! V_445 && V_464 ) ) ) {
V_444 -> V_280 = 1 ;
V_444 -> V_408 = F_87 ( V_221 ) ;
V_444 -> V_103 = F_87 ( V_221 + 4 ) ;
}
break;
case V_465 :
if ( V_449 == V_466 && V_51 -> V_53 &&
! V_445 && V_467 ) {
V_444 -> V_132 = V_468 ;
F_249 ( V_444 ) ;
}
break;
case V_469 :
if ( ( V_449 >= ( V_224 + V_470 ) ) &&
! ( ( V_449 - V_224 ) % V_470 ) &&
V_444 -> V_132 ) {
F_26 ( V_4 ) -> V_154 = ( V_221 - 2 ) - ( unsigned char * ) V_51 ;
}
break;
#ifdef F_250
case V_471 :
break;
#endif
case V_472 :
F_245 (
V_449 - V_473 ,
V_221 , V_51 -> V_53 , V_438 , false ) ;
break;
case V_474 :
if ( V_449 >= V_475 &&
F_247 ( V_221 ) ==
V_476 )
F_245 ( V_449 -
V_475 ,
V_221 + 2 , V_51 -> V_53 , V_438 , true ) ;
break;
}
V_221 += V_449 - 2 ;
V_446 -= V_449 ;
}
}
}
static bool F_251 ( struct V_37 * V_38 , const struct V_20 * V_51 )
{
const T_9 * V_221 = ( const T_9 * ) ( V_51 + 1 ) ;
if ( * V_221 == F_252 ( ( V_451 << 24 ) | ( V_451 << 16 )
| ( V_461 << 8 ) | V_462 ) ) {
V_38 -> V_60 . V_280 = 1 ;
++ V_221 ;
V_38 -> V_60 . V_408 = F_253 ( * V_221 ) ;
++ V_221 ;
if ( * V_221 )
V_38 -> V_60 . V_103 = F_253 ( * V_221 ) - V_38 -> V_477 ;
else
V_38 -> V_60 . V_103 = 0 ;
return true ;
}
return false ;
}
static bool F_254 ( const struct V_3 * V_4 ,
const struct V_20 * V_51 , struct V_37 * V_38 )
{
if ( V_51 -> V_447 == ( sizeof( * V_51 ) / 4 ) ) {
V_38 -> V_60 . V_280 = 0 ;
return false ;
} else if ( V_38 -> V_60 . V_463 &&
V_51 -> V_447 == ( ( sizeof( * V_51 ) + V_478 ) / 4 ) ) {
if ( F_251 ( V_38 , V_51 ) )
return true ;
}
F_246 ( V_4 , & V_38 -> V_60 , 1 , NULL ) ;
if ( V_38 -> V_60 . V_280 && V_38 -> V_60 . V_103 )
V_38 -> V_60 . V_103 -= V_38 -> V_477 ;
return true ;
}
const T_6 * F_255 ( const struct V_20 * V_51 )
{
int V_446 = ( V_51 -> V_447 << 2 ) - sizeof( * V_51 ) ;
const T_6 * V_221 = ( const T_6 * ) ( V_51 + 1 ) ;
if ( V_446 < V_479 )
return NULL ;
while ( V_446 > 0 ) {
int V_448 = * V_221 ++ ;
int V_449 ;
switch ( V_448 ) {
case V_450 :
return NULL ;
case V_451 :
V_446 -- ;
continue;
default:
V_449 = * V_221 ++ ;
if ( V_449 < 2 || V_449 > V_446 )
return NULL ;
if ( V_448 == V_471 )
return V_449 == V_479 ? V_221 : NULL ;
}
V_221 += V_449 - 2 ;
V_446 -= V_449 ;
}
return NULL ;
}
static int F_256 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
const struct V_20 * V_51 = F_14 ( V_4 ) ;
T_2 V_89 = F_26 ( V_4 ) -> V_89 ;
T_2 V_351 = F_26 ( V_4 ) -> V_170 ;
return (
( V_51 -> V_351 && V_89 == F_26 ( V_4 ) -> V_104 && V_89 == V_38 -> V_102 ) &&
V_351 == V_38 -> V_117 &&
! F_217 ( V_38 , V_351 , V_89 , F_161 ( V_51 -> V_72 ) << V_38 -> V_60 . V_394 ) &&
( T_7 ) ( V_38 -> V_60 . V_407 - V_38 -> V_60 . V_408 ) <= ( F_8 ( V_2 ) -> V_110 * 1024 ) / V_339 ) ;
}
static inline bool F_257 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
return ! F_235 ( & V_38 -> V_60 , V_480 ) &&
! F_256 ( V_2 , V_4 ) ;
}
static inline bool F_258 ( const struct V_37 * V_38 , T_2 V_89 , T_2 V_104 )
{
return ! F_55 ( V_104 , V_38 -> V_410 ) &&
! F_62 ( V_89 , V_38 -> V_102 + F_259 ( V_38 ) ) ;
}
void F_260 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_481 ) {
case V_482 :
V_2 -> V_483 = V_484 ;
break;
case V_485 :
V_2 -> V_483 = V_486 ;
break;
case V_487 :
return;
default:
V_2 -> V_483 = V_488 ;
}
F_261 () ;
if ( ! F_262 ( V_2 , V_489 ) )
V_2 -> V_490 ( V_2 ) ;
F_263 ( V_2 ) ;
}
void F_264 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
F_59 ( V_2 ) ;
V_2 -> V_491 |= V_492 ;
F_265 ( V_2 , V_493 ) ;
switch ( V_2 -> V_481 ) {
case V_494 :
case V_495 :
F_266 ( V_2 , V_485 ) ;
F_8 ( V_2 ) -> V_13 . V_31 = 1 ;
break;
case V_485 :
case V_496 :
break;
case V_497 :
break;
case V_498 :
F_231 ( V_2 ) ;
F_266 ( V_2 , V_496 ) ;
break;
case V_499 :
F_231 ( V_2 ) ;
F_267 ( V_2 , V_500 , 0 ) ;
break;
default:
F_268 ( L_17 ,
V_460 , V_2 -> V_481 ) ;
break;
}
F_269 ( & V_38 -> V_501 ) ;
if ( F_151 ( V_38 ) )
F_249 ( & V_38 -> V_60 ) ;
F_60 ( V_2 ) ;
if ( ! F_262 ( V_2 , V_489 ) ) {
V_2 -> V_502 ( V_2 ) ;
if ( V_2 -> V_491 == V_503 ||
V_2 -> V_481 == V_487 )
F_270 ( V_2 , V_504 , V_505 ) ;
else
F_270 ( V_2 , V_504 , V_506 ) ;
}
}
static inline bool F_271 ( struct V_214 * V_164 , T_2 V_89 ,
T_2 V_104 )
{
if ( ! F_62 ( V_89 , V_164 -> V_104 ) && ! F_62 ( V_164 -> V_160 , V_104 ) ) {
if ( F_55 ( V_89 , V_164 -> V_160 ) )
V_164 -> V_160 = V_89 ;
if ( F_62 ( V_104 , V_164 -> V_104 ) )
V_164 -> V_104 = V_104 ;
return true ;
}
return false ;
}
static void F_272 ( struct V_1 * V_2 , T_2 V_89 , T_2 V_104 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_151 ( V_38 ) && V_507 ) {
int V_137 ;
if ( F_55 ( V_89 , V_38 -> V_102 ) )
V_137 = V_508 ;
else
V_137 = V_509 ;
F_77 ( F_4 ( V_2 ) , V_137 ) ;
V_38 -> V_60 . V_510 = 1 ;
V_38 -> V_511 [ 0 ] . V_160 = V_89 ;
V_38 -> V_511 [ 0 ] . V_104 = V_104 ;
}
}
static void F_273 ( struct V_1 * V_2 , T_2 V_89 , T_2 V_104 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( ! V_38 -> V_60 . V_510 )
F_272 ( V_2 , V_89 , V_104 ) ;
else
F_271 ( V_38 -> V_511 , V_89 , V_104 ) ;
}
static void F_274 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_26 ( V_4 ) -> V_104 != F_26 ( V_4 ) -> V_89 &&
F_55 ( F_26 ( V_4 ) -> V_89 , V_38 -> V_102 ) ) {
F_77 ( F_4 ( V_2 ) , V_512 ) ;
F_18 ( V_2 ) ;
if ( F_151 ( V_38 ) && V_507 ) {
T_2 V_104 = F_26 ( V_4 ) -> V_104 ;
if ( F_62 ( F_26 ( V_4 ) -> V_104 , V_38 -> V_102 ) )
V_104 = V_38 -> V_102 ;
F_272 ( V_2 , F_26 ( V_4 ) -> V_89 , V_104 ) ;
}
}
F_231 ( V_2 ) ;
}
static void F_275 ( struct V_37 * V_38 )
{
int V_513 ;
struct V_214 * V_164 = & V_38 -> V_514 [ 0 ] ;
struct V_214 * V_515 = V_164 + 1 ;
for ( V_513 = 1 ; V_513 < V_38 -> V_60 . V_165 ; ) {
if ( F_271 ( V_164 , V_515 -> V_160 , V_515 -> V_104 ) ) {
int V_227 ;
V_38 -> V_60 . V_165 -- ;
for ( V_227 = V_513 ; V_227 < V_38 -> V_60 . V_165 ; V_227 ++ )
V_164 [ V_227 ] = V_164 [ V_227 + 1 ] ;
continue;
}
V_513 ++ , V_515 ++ ;
}
}
static void F_276 ( struct V_1 * V_2 , T_2 V_89 , T_2 V_104 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_214 * V_164 = & V_38 -> V_514 [ 0 ] ;
int V_516 = V_38 -> V_60 . V_165 ;
int V_513 ;
if ( ! V_516 )
goto V_517;
for ( V_513 = 0 ; V_513 < V_516 ; V_513 ++ , V_164 ++ ) {
if ( F_271 ( V_164 , V_89 , V_104 ) ) {
for (; V_513 > 0 ; V_513 -- , V_164 -- )
F_125 ( * V_164 , * ( V_164 - 1 ) ) ;
if ( V_516 > 1 )
F_275 ( V_38 ) ;
return;
}
}
if ( V_513 >= V_223 ) {
V_513 -- ;
V_38 -> V_60 . V_165 -- ;
V_164 -- ;
}
for (; V_513 > 0 ; V_513 -- , V_164 -- )
* V_164 = * ( V_164 - 1 ) ;
V_517:
V_164 -> V_160 = V_89 ;
V_164 -> V_104 = V_104 ;
V_38 -> V_60 . V_165 ++ ;
}
static void F_277 ( struct V_37 * V_38 )
{
struct V_214 * V_164 = & V_38 -> V_514 [ 0 ] ;
int V_165 = V_38 -> V_60 . V_165 ;
int V_513 ;
if ( F_278 ( & V_38 -> V_501 ) ) {
V_38 -> V_60 . V_165 = 0 ;
return;
}
for ( V_513 = 0 ; V_513 < V_165 ; ) {
if ( ! F_55 ( V_38 -> V_102 , V_164 -> V_160 ) ) {
int V_227 ;
F_123 ( F_55 ( V_38 -> V_102 , V_164 -> V_104 ) ) ;
for ( V_227 = V_513 + 1 ; V_227 < V_165 ; V_227 ++ )
V_38 -> V_514 [ V_227 - 1 ] = V_38 -> V_514 [ V_227 ] ;
V_165 -- ;
continue;
}
V_513 ++ ;
V_164 ++ ;
}
V_38 -> V_60 . V_165 = V_165 ;
}
static bool F_279 ( struct V_1 * V_2 ,
struct V_3 * V_518 ,
struct V_3 * V_519 ,
bool * V_520 )
{
int V_306 ;
* V_520 = false ;
if ( F_26 ( V_519 ) -> V_89 != F_26 ( V_518 ) -> V_104 )
return false ;
if ( ! F_280 ( V_518 , V_519 , V_520 , & V_306 ) )
return false ;
F_281 ( V_306 , & V_2 -> V_93 ) ;
F_282 ( V_2 , V_306 ) ;
F_77 ( F_4 ( V_2 ) , V_521 ) ;
F_26 ( V_518 ) -> V_104 = F_26 ( V_519 ) -> V_104 ;
F_26 ( V_518 ) -> V_170 = F_26 ( V_519 ) -> V_170 ;
F_26 ( V_518 ) -> V_203 |= F_26 ( V_519 ) -> V_203 ;
return true ;
}
static void F_283 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_284 ( V_2 , V_4 ) ;
F_285 ( V_4 ) ;
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_4 V_522 = V_38 -> V_102 ;
bool V_523 , V_520 , V_524 ;
struct V_3 * V_4 , * V_525 ;
struct V_526 * V_527 ;
V_527 = F_287 ( & V_38 -> V_501 ) ;
while ( V_527 ) {
V_4 = F_288 ( V_527 , struct V_3 , V_528 ) ;
if ( F_62 ( F_26 ( V_4 ) -> V_89 , V_38 -> V_102 ) )
break;
if ( F_55 ( F_26 ( V_4 ) -> V_89 , V_522 ) ) {
T_4 V_510 = V_522 ;
if ( F_55 ( F_26 ( V_4 ) -> V_104 , V_522 ) )
V_522 = F_26 ( V_4 ) -> V_104 ;
F_273 ( V_2 , F_26 ( V_4 ) -> V_89 , V_510 ) ;
}
V_527 = F_289 ( V_527 ) ;
F_290 ( & V_4 -> V_528 , & V_38 -> V_501 ) ;
if ( F_11 ( ! F_62 ( F_26 ( V_4 ) -> V_104 , V_38 -> V_102 ) ) ) {
F_244 ( V_2 , L_18 ) ;
F_283 ( V_2 , V_4 ) ;
continue;
}
F_244 ( V_2 , L_19 ,
V_38 -> V_102 , F_26 ( V_4 ) -> V_89 ,
F_26 ( V_4 ) -> V_104 ) ;
V_525 = F_291 ( & V_2 -> V_529 ) ;
V_524 = V_525 && F_279 ( V_2 , V_525 , V_4 , & V_520 ) ;
F_220 ( V_38 , F_26 ( V_4 ) -> V_104 ) ;
V_523 = F_26 ( V_4 ) -> V_203 & V_205 ;
if ( ! V_524 )
F_292 ( & V_2 -> V_529 , V_4 ) ;
else
F_293 ( V_4 , V_520 ) ;
if ( F_11 ( V_523 ) ) {
F_264 ( V_2 ) ;
break;
}
}
}
static int F_294 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_530 )
{
if ( F_51 ( & V_2 -> V_93 ) > V_2 -> V_81 ||
! F_295 ( V_2 , V_4 , V_530 ) ) {
if ( F_296 ( V_2 ) < 0 )
return - 1 ;
while ( ! F_295 ( V_2 , V_4 , V_530 ) ) {
if ( ! F_297 ( V_2 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_298 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_526 * * V_527 , * V_531 , * V_532 ;
struct V_3 * V_533 ;
T_2 V_89 , V_104 ;
bool V_520 ;
F_29 ( V_38 , V_4 ) ;
if ( F_11 ( F_294 ( V_2 , V_4 , V_4 -> V_71 ) ) ) {
F_77 ( F_4 ( V_2 ) , V_534 ) ;
F_283 ( V_2 , V_4 ) ;
return;
}
V_38 -> V_396 = 0 ;
F_59 ( V_2 ) ;
F_77 ( F_4 ( V_2 ) , V_535 ) ;
V_89 = F_26 ( V_4 ) -> V_89 ;
V_104 = F_26 ( V_4 ) -> V_104 ;
F_244 ( V_2 , L_20 ,
V_38 -> V_102 , V_89 , V_104 ) ;
V_527 = & V_38 -> V_501 . V_526 ;
if ( F_278 ( & V_38 -> V_501 ) ) {
if ( F_151 ( V_38 ) ) {
V_38 -> V_60 . V_165 = 1 ;
V_38 -> V_514 [ 0 ] . V_160 = V_89 ;
V_38 -> V_514 [ 0 ] . V_104 = V_104 ;
}
F_299 ( & V_4 -> V_528 , NULL , V_527 ) ;
F_300 ( & V_4 -> V_528 , & V_38 -> V_501 ) ;
V_38 -> V_536 = V_4 ;
goto V_537;
}
if ( F_279 ( V_2 , V_38 -> V_536 , V_4 , & V_520 ) ) {
V_538:
F_39 ( V_2 , V_4 ) ;
F_293 ( V_4 , V_520 ) ;
V_4 = NULL ;
goto V_539;
}
if ( ! F_55 ( V_89 , F_26 ( V_38 -> V_536 ) -> V_104 ) ) {
V_532 = & V_38 -> V_536 -> V_528 ;
V_527 = & V_532 -> V_540 ;
goto V_541;
}
V_532 = NULL ;
while ( * V_527 ) {
V_532 = * V_527 ;
V_533 = F_288 ( V_532 , struct V_3 , V_528 ) ;
if ( F_55 ( V_89 , F_26 ( V_533 ) -> V_89 ) ) {
V_527 = & V_532 -> V_542 ;
continue;
}
if ( F_55 ( V_89 , F_26 ( V_533 ) -> V_104 ) ) {
if ( ! F_62 ( V_104 , F_26 ( V_533 ) -> V_104 ) ) {
F_77 ( F_4 ( V_2 ) ,
V_543 ) ;
F_285 ( V_4 ) ;
V_4 = NULL ;
F_272 ( V_2 , V_89 , V_104 ) ;
goto V_539;
}
if ( F_62 ( V_89 , F_26 ( V_533 ) -> V_89 ) ) {
F_272 ( V_2 , V_89 , F_26 ( V_533 ) -> V_104 ) ;
} else {
F_301 ( & V_533 -> V_528 , & V_4 -> V_528 ,
& V_38 -> V_501 ) ;
F_273 ( V_2 ,
F_26 ( V_533 ) -> V_89 ,
F_26 ( V_533 ) -> V_104 ) ;
F_77 ( F_4 ( V_2 ) ,
V_543 ) ;
F_285 ( V_533 ) ;
goto V_544;
}
} else if ( F_279 ( V_2 , V_533 , V_4 , & V_520 ) ) {
goto V_538;
}
V_527 = & V_532 -> V_540 ;
}
V_541:
F_299 ( & V_4 -> V_528 , V_532 , V_527 ) ;
F_300 ( & V_4 -> V_528 , & V_38 -> V_501 ) ;
V_544:
while ( ( V_531 = F_289 ( & V_4 -> V_528 ) ) != NULL ) {
V_533 = F_288 ( V_531 , struct V_3 , V_528 ) ;
if ( ! F_62 ( V_104 , F_26 ( V_533 ) -> V_89 ) )
break;
if ( F_55 ( V_104 , F_26 ( V_533 ) -> V_104 ) ) {
F_273 ( V_2 , F_26 ( V_533 ) -> V_89 ,
V_104 ) ;
break;
}
F_290 ( & V_533 -> V_528 , & V_38 -> V_501 ) ;
F_273 ( V_2 , F_26 ( V_533 ) -> V_89 ,
F_26 ( V_533 ) -> V_104 ) ;
F_77 ( F_4 ( V_2 ) , V_543 ) ;
F_283 ( V_2 , V_533 ) ;
}
if ( ! V_531 )
V_38 -> V_536 = V_4 ;
V_539:
if ( F_151 ( V_38 ) )
F_276 ( V_2 , V_89 , V_104 ) ;
V_537:
if ( V_4 ) {
F_39 ( V_2 , V_4 ) ;
F_302 ( V_4 , V_2 ) ;
}
}
static int T_10 F_303 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_545 ,
bool * V_520 )
{
int V_524 ;
struct V_3 * V_525 = F_291 ( & V_2 -> V_529 ) ;
F_304 ( V_4 , V_545 ) ;
V_524 = ( V_525 &&
F_279 ( V_2 , V_525 , V_4 , V_520 ) ) ? 1 : 0 ;
F_220 ( F_15 ( V_2 ) , F_26 ( V_4 ) -> V_104 ) ;
if ( ! V_524 ) {
F_292 ( & V_2 -> V_529 , V_4 ) ;
F_302 ( V_4 , V_2 ) ;
}
return V_524 ;
}
int F_305 ( struct V_1 * V_2 , struct V_546 * V_282 , T_11 V_530 )
{
struct V_3 * V_4 ;
int V_175 = - V_547 ;
int V_548 = 0 ;
bool V_520 ;
if ( V_530 == 0 )
return 0 ;
if ( V_530 > V_549 ) {
int V_550 = F_10 ( T_11 , V_530 >> V_551 , V_552 ) ;
V_548 = V_550 << V_551 ;
V_530 = V_548 + ( V_530 & ~ V_553 ) ;
}
V_4 = F_306 ( V_530 - V_548 , V_548 ,
V_554 ,
& V_175 , V_2 -> V_555 ) ;
if ( ! V_4 )
goto V_175;
F_307 ( V_4 , V_530 - V_548 ) ;
V_4 -> V_548 = V_548 ;
V_4 -> V_15 = V_530 ;
if ( F_294 ( V_2 , V_4 , V_4 -> V_71 ) )
goto V_556;
V_175 = F_308 ( V_4 , 0 , & V_282 -> V_557 , V_530 ) ;
if ( V_175 )
goto V_556;
F_26 ( V_4 ) -> V_89 = F_15 ( V_2 ) -> V_102 ;
F_26 ( V_4 ) -> V_104 = F_26 ( V_4 ) -> V_89 + V_530 ;
F_26 ( V_4 ) -> V_170 = F_15 ( V_2 ) -> V_117 - 1 ;
if ( F_303 ( V_2 , V_4 , 0 , & V_520 ) ) {
F_171 ( V_520 ) ;
F_285 ( V_4 ) ;
}
return V_530 ;
V_556:
F_309 ( V_4 ) ;
V_175:
return V_175 ;
}
static void F_310 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
bool V_520 = false ;
int V_524 = - 1 ;
if ( F_26 ( V_4 ) -> V_89 == F_26 ( V_4 ) -> V_104 ) {
F_285 ( V_4 ) ;
return;
}
F_311 ( V_4 ) ;
F_304 ( V_4 , F_14 ( V_4 ) -> V_447 * 4 ) ;
F_23 ( V_38 , V_4 ) ;
V_38 -> V_60 . V_510 = 0 ;
if ( F_26 ( V_4 ) -> V_89 == V_38 -> V_102 ) {
if ( F_259 ( V_38 ) == 0 )
goto V_558;
if ( V_38 -> V_559 . V_560 == V_561 &&
V_38 -> V_90 == V_38 -> V_102 && V_38 -> V_559 . V_15 &&
F_312 ( V_2 ) && ! V_38 -> V_562 ) {
int V_563 = F_10 (unsigned int, skb->len,
tp->ucopy.len) ;
F_313 ( V_564 ) ;
if ( ! F_314 ( V_4 , 0 , V_38 -> V_559 . V_282 , V_563 ) ) {
V_38 -> V_559 . V_15 -= V_563 ;
V_38 -> V_90 += V_563 ;
V_524 = ( V_563 == V_4 -> V_15 ) ;
F_57 ( V_2 ) ;
}
}
if ( V_524 <= 0 ) {
V_565:
if ( V_524 < 0 ) {
if ( F_315 ( & V_2 -> V_529 ) == 0 )
F_316 ( V_2 , V_4 -> V_71 ) ;
else if ( F_294 ( V_2 , V_4 , V_4 -> V_71 ) )
goto V_566;
}
V_524 = F_303 ( V_2 , V_4 , 0 , & V_520 ) ;
}
F_220 ( V_38 , F_26 ( V_4 ) -> V_104 ) ;
if ( V_4 -> V_15 )
F_58 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_203 & V_205 )
F_264 ( V_2 ) ;
if ( ! F_278 ( & V_38 -> V_501 ) ) {
F_286 ( V_2 ) ;
if ( F_278 ( & V_38 -> V_501 ) )
F_8 ( V_2 ) -> V_13 . V_31 = 0 ;
}
if ( V_38 -> V_60 . V_165 )
F_277 ( V_38 ) ;
F_223 ( V_2 ) ;
if ( V_524 > 0 )
F_293 ( V_4 , V_520 ) ;
if ( ! F_262 ( V_2 , V_489 ) )
V_2 -> V_567 ( V_2 ) ;
return;
}
if ( ! F_62 ( F_26 ( V_4 ) -> V_104 , V_38 -> V_102 ) ) {
F_77 ( F_4 ( V_2 ) , V_512 ) ;
F_272 ( V_2 , F_26 ( V_4 ) -> V_89 , F_26 ( V_4 ) -> V_104 ) ;
V_558:
F_18 ( V_2 ) ;
F_59 ( V_2 ) ;
V_566:
F_283 ( V_2 , V_4 ) ;
return;
}
if ( ! F_55 ( F_26 ( V_4 ) -> V_89 , V_38 -> V_102 + F_259 ( V_38 ) ) )
goto V_558;
F_18 ( V_2 ) ;
if ( F_55 ( F_26 ( V_4 ) -> V_89 , V_38 -> V_102 ) ) {
F_244 ( V_2 , L_21 ,
V_38 -> V_102 , F_26 ( V_4 ) -> V_89 ,
F_26 ( V_4 ) -> V_104 ) ;
F_272 ( V_2 , F_26 ( V_4 ) -> V_89 , V_38 -> V_102 ) ;
if ( ! F_259 ( V_38 ) )
goto V_558;
goto V_565;
}
F_298 ( V_2 , V_4 ) ;
}
static struct V_3 * F_317 ( struct V_3 * V_4 , struct V_568 * V_569 )
{
if ( V_569 )
return ! F_318 ( V_569 , V_4 ) ? V_4 -> V_374 : NULL ;
return F_319 ( F_289 ( & V_4 -> V_528 ) , struct V_3 , V_528 ) ;
}
static struct V_3 * F_320 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_568 * V_569 ,
struct V_570 * V_571 )
{
struct V_3 * V_374 = F_317 ( V_4 , V_569 ) ;
if ( V_569 )
F_321 ( V_4 , V_569 ) ;
else
F_290 ( & V_4 -> V_528 , V_571 ) ;
F_285 ( V_4 ) ;
F_77 ( F_4 ( V_2 ) , V_572 ) ;
return V_374 ;
}
static void F_322 ( struct V_570 * V_571 , struct V_3 * V_4 )
{
struct V_526 * * V_527 = & V_571 -> V_526 ;
struct V_526 * V_532 = NULL ;
struct V_3 * V_533 ;
while ( * V_527 ) {
V_532 = * V_527 ;
V_533 = F_288 ( V_532 , struct V_3 , V_528 ) ;
if ( F_55 ( F_26 ( V_4 ) -> V_89 , F_26 ( V_533 ) -> V_89 ) )
V_527 = & V_532 -> V_542 ;
else
V_527 = & V_532 -> V_540 ;
}
F_299 ( & V_4 -> V_528 , V_532 , V_527 ) ;
F_300 ( & V_4 -> V_528 , V_571 ) ;
}
static void
F_323 ( struct V_1 * V_2 , struct V_568 * V_569 , struct V_570 * V_571 ,
struct V_3 * V_573 , struct V_3 * V_525 , T_2 V_574 , T_2 V_537 )
{
struct V_3 * V_4 = V_573 , * V_575 ;
struct V_568 V_217 ;
bool V_576 ;
V_577:
for ( V_576 = true ; V_4 != NULL && V_4 != V_525 ; V_4 = V_575 ) {
V_575 = F_317 ( V_4 , V_569 ) ;
if ( ! F_55 ( V_574 , F_26 ( V_4 ) -> V_104 ) ) {
V_4 = F_320 ( V_2 , V_4 , V_569 , V_571 ) ;
if ( ! V_4 )
break;
goto V_577;
}
if ( ! ( F_26 ( V_4 ) -> V_203 & ( V_376 | V_205 ) ) &&
( F_38 ( V_4 -> V_71 ) > V_4 -> V_15 ||
F_55 ( F_26 ( V_4 ) -> V_89 , V_574 ) ) ) {
V_576 = false ;
break;
}
if ( V_575 && V_575 != V_525 &&
F_26 ( V_4 ) -> V_104 != F_26 ( V_575 ) -> V_89 ) {
V_576 = false ;
break;
}
V_574 = F_26 ( V_4 ) -> V_104 ;
}
if ( V_576 ||
( F_26 ( V_4 ) -> V_203 & ( V_376 | V_205 ) ) )
return;
F_324 ( & V_217 ) ;
while ( F_55 ( V_574 , V_537 ) ) {
int V_578 = F_10 ( int , F_325 ( 0 , 0 ) , V_537 - V_574 ) ;
struct V_3 * V_579 ;
V_579 = F_326 ( V_578 , V_180 ) ;
if ( ! V_579 )
break;
memcpy ( V_579 -> V_580 , V_4 -> V_580 , sizeof( V_4 -> V_580 ) ) ;
F_26 ( V_579 ) -> V_89 = F_26 ( V_579 ) -> V_104 = V_574 ;
if ( V_569 )
F_327 ( V_569 , V_4 , V_579 ) ;
else
F_292 ( & V_217 , V_579 ) ;
F_302 ( V_579 , V_2 ) ;
while ( V_578 > 0 ) {
int V_581 = V_574 - F_26 ( V_4 ) -> V_89 ;
int V_530 = F_26 ( V_4 ) -> V_104 - V_574 ;
F_96 ( V_581 < 0 ) ;
if ( V_530 > 0 ) {
V_530 = F_17 ( V_578 , V_530 ) ;
if ( F_328 ( V_4 , V_581 , F_307 ( V_579 , V_530 ) , V_530 ) )
F_329 () ;
F_26 ( V_579 ) -> V_104 += V_530 ;
V_578 -= V_530 ;
V_574 += V_530 ;
}
if ( ! F_55 ( V_574 , F_26 ( V_4 ) -> V_104 ) ) {
V_4 = F_320 ( V_2 , V_4 , V_569 , V_571 ) ;
if ( ! V_4 ||
V_4 == V_525 ||
( F_26 ( V_4 ) -> V_203 & ( V_376 | V_205 ) ) )
goto V_537;
}
}
}
V_537:
F_330 (&tmp, skb, n)
F_322 ( V_571 , V_4 ) ;
}
static void F_331 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_4 , * V_573 ;
struct V_526 * V_527 ;
T_2 V_574 , V_537 ;
V_527 = F_287 ( & V_38 -> V_501 ) ;
V_4 = F_319 ( V_527 , struct V_3 , V_528 ) ;
V_582:
if ( ! V_4 ) {
V_527 = F_332 ( & V_38 -> V_501 ) ;
V_38 -> V_536 = F_288 ( V_527 , struct V_3 , V_528 ) ;
return;
}
V_574 = F_26 ( V_4 ) -> V_89 ;
V_537 = F_26 ( V_4 ) -> V_104 ;
for ( V_573 = V_4 ; ; ) {
V_4 = F_317 ( V_4 , NULL ) ;
if ( ! V_4 ||
F_62 ( F_26 ( V_4 ) -> V_89 , V_537 ) ||
F_55 ( F_26 ( V_4 ) -> V_104 , V_574 ) ) {
F_323 ( V_2 , NULL , & V_38 -> V_501 ,
V_573 , V_4 , V_574 , V_537 ) ;
goto V_582;
}
if ( F_11 ( F_55 ( F_26 ( V_4 ) -> V_89 , V_574 ) ) )
V_574 = F_26 ( V_4 ) -> V_89 ;
if ( F_62 ( F_26 ( V_4 ) -> V_104 , V_537 ) )
V_537 = F_26 ( V_4 ) -> V_104 ;
}
}
static bool F_297 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_526 * V_583 , * V_199 ;
if ( F_278 ( & V_38 -> V_501 ) )
return false ;
F_77 ( F_4 ( V_2 ) , V_584 ) ;
V_583 = & V_38 -> V_536 -> V_528 ;
do {
V_199 = F_333 ( V_583 ) ;
F_290 ( V_583 , & V_38 -> V_501 ) ;
F_283 ( V_2 , F_288 ( V_583 , struct V_3 , V_528 ) ) ;
F_60 ( V_2 ) ;
if ( F_51 ( & V_2 -> V_93 ) <= V_2 -> V_81 &&
! F_41 ( V_2 ) )
break;
V_583 = V_199 ;
} while ( V_583 );
V_38 -> V_536 = F_288 ( V_199 , struct V_3 , V_528 ) ;
if ( V_38 -> V_60 . V_132 )
F_249 ( & V_38 -> V_60 ) ;
return true ;
}
static int F_296 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
F_244 ( V_2 , L_22 , V_38 -> V_90 ) ;
F_77 ( F_4 ( V_2 ) , V_585 ) ;
if ( F_51 ( & V_2 -> V_93 ) >= V_2 -> V_81 )
F_48 ( V_2 ) ;
else if ( F_41 ( V_2 ) )
V_38 -> V_74 = F_17 ( V_38 -> V_74 , 4U * V_38 -> V_77 ) ;
F_331 ( V_2 ) ;
if ( ! F_334 ( & V_2 -> V_529 ) )
F_323 ( V_2 , & V_2 -> V_529 , NULL ,
F_335 ( & V_2 -> V_529 ) ,
NULL ,
V_38 -> V_90 , V_38 -> V_102 ) ;
F_60 ( V_2 ) ;
if ( F_51 ( & V_2 -> V_93 ) <= V_2 -> V_81 )
return 0 ;
F_297 ( V_2 ) ;
if ( F_51 ( & V_2 -> V_93 ) <= V_2 -> V_81 )
return 0 ;
F_77 ( F_4 ( V_2 ) , V_586 ) ;
V_38 -> V_396 = 0 ;
return - 1 ;
}
static bool F_336 ( const struct V_1 * V_2 )
{
const struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_2 -> V_83 & V_85 )
return false ;
if ( F_41 ( V_2 ) )
return false ;
if ( F_49 ( V_2 ) >= F_50 ( V_2 , 0 ) )
return false ;
if ( F_127 ( V_38 ) >= V_38 -> V_66 )
return false ;
return true ;
}
static void F_337 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_336 ( V_2 ) ) {
F_33 ( V_2 ) ;
V_38 -> V_92 = V_88 ;
}
V_2 -> V_587 ( V_2 ) ;
}
static void F_338 ( struct V_1 * V_2 )
{
if ( F_262 ( V_2 , V_588 ) ) {
F_339 ( V_2 , V_588 ) ;
F_340 () ;
if ( V_2 -> V_589 &&
F_341 ( V_590 , & V_2 -> V_589 -> V_412 ) ) {
F_337 ( V_2 ) ;
if ( ! F_341 ( V_590 , & V_2 -> V_589 -> V_412 ) )
F_210 ( V_2 , V_591 ) ;
}
}
}
static inline void F_342 ( struct V_1 * V_2 )
{
F_343 ( V_2 ) ;
F_338 ( V_2 ) ;
}
static void F_344 ( struct V_1 * V_2 , int V_592 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( ( ( V_38 -> V_102 - V_38 -> V_410 ) > F_8 ( V_2 ) -> V_13 . V_17 &&
F_345 ( V_2 ) >= V_38 -> V_28 ) ||
F_19 ( V_2 ) ||
( V_592 && ! F_278 ( & V_38 -> V_501 ) ) ) {
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
static void F_349 ( struct V_1 * V_2 , const struct V_20 * V_51 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
T_2 V_221 = F_161 ( V_51 -> V_593 ) ;
if ( V_221 && ! V_594 )
V_221 -- ;
V_221 += F_253 ( V_51 -> V_89 ) ;
if ( F_62 ( V_38 -> V_90 , V_221 ) )
return;
if ( F_55 ( V_221 , V_38 -> V_102 ) )
return;
if ( V_38 -> V_562 && ! F_62 ( V_221 , V_38 -> V_595 ) )
return;
F_350 ( V_2 ) ;
if ( V_38 -> V_595 == V_38 -> V_90 && V_38 -> V_562 &&
! F_262 ( V_2 , V_596 ) && V_38 -> V_90 != V_38 -> V_102 ) {
struct V_3 * V_4 = F_335 ( & V_2 -> V_529 ) ;
V_38 -> V_90 ++ ;
if ( V_4 && ! F_55 ( V_38 -> V_90 , F_26 ( V_4 ) -> V_104 ) ) {
F_321 ( V_4 , & V_2 -> V_529 ) ;
F_285 ( V_4 ) ;
}
}
V_38 -> V_562 = V_597 ;
V_38 -> V_595 = V_221 ;
V_38 -> V_396 = 0 ;
}
static void F_351 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_20 * V_51 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( V_51 -> V_598 )
F_349 ( V_2 , V_51 ) ;
if ( V_38 -> V_562 == V_597 ) {
T_2 V_221 = V_38 -> V_595 - F_253 ( V_51 -> V_89 ) + ( V_51 -> V_447 * 4 ) -
V_51 -> V_53 ;
if ( V_221 < V_4 -> V_15 ) {
T_6 V_217 ;
if ( F_328 ( V_4 , V_221 , & V_217 , 1 ) )
F_329 () ;
V_38 -> V_562 = V_599 | V_217 ;
if ( ! F_262 ( V_2 , V_489 ) )
V_2 -> V_567 ( V_2 ) ;
}
}
}
static int F_352 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_600 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
int V_563 = V_4 -> V_15 - V_600 ;
int V_175 ;
if ( F_353 ( V_4 ) )
V_175 = F_314 ( V_4 , V_600 , V_38 -> V_559 . V_282 , V_563 ) ;
else
V_175 = F_354 ( V_4 , V_600 , V_38 -> V_559 . V_282 ) ;
if ( ! V_175 ) {
V_38 -> V_559 . V_15 -= V_563 ;
V_38 -> V_90 += V_563 ;
F_57 ( V_2 ) ;
}
return V_175 ;
}
static bool F_355 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_20 * V_51 , int V_601 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
bool V_602 = false ;
if ( F_254 ( V_4 , V_51 , V_38 ) && V_38 -> V_60 . V_280 &&
F_257 ( V_2 , V_4 ) ) {
if ( ! V_51 -> V_603 ) {
F_77 ( F_4 ( V_2 ) , V_604 ) ;
if ( ! F_226 ( F_4 ( V_2 ) , V_4 ,
V_605 ,
& V_38 -> V_397 ) )
F_274 ( V_2 , V_4 ) ;
goto V_606;
}
}
if ( ! F_258 ( V_38 , F_26 ( V_4 ) -> V_89 , F_26 ( V_4 ) -> V_104 ) ) {
if ( ! V_51 -> V_603 ) {
if ( V_51 -> V_53 )
goto V_607;
if ( ! F_226 ( F_4 ( V_2 ) , V_4 ,
V_608 ,
& V_38 -> V_397 ) )
F_274 ( V_2 , V_4 ) ;
}
goto V_606;
}
if ( V_51 -> V_603 ) {
if ( F_26 ( V_4 ) -> V_89 == V_38 -> V_102 ) {
V_602 = true ;
} else if ( F_151 ( V_38 ) && V_38 -> V_60 . V_165 > 0 ) {
struct V_214 * V_164 = & V_38 -> V_514 [ 0 ] ;
int V_609 = V_164 [ 0 ] . V_104 ;
int V_513 ;
for ( V_513 = 1 ; V_513 < V_38 -> V_60 . V_165 ;
++ V_513 ) {
V_609 = F_62 ( V_164 [ V_513 ] . V_104 ,
V_609 ) ?
V_164 [ V_513 ] . V_104 : V_609 ;
}
if ( F_26 ( V_4 ) -> V_89 == V_609 )
V_602 = true ;
}
if ( V_602 )
F_260 ( V_2 ) ;
else
F_227 ( V_2 , V_4 ) ;
goto V_606;
}
if ( V_51 -> V_53 ) {
V_607:
if ( V_601 )
F_356 ( F_4 ( V_2 ) , V_610 ) ;
F_77 ( F_4 ( V_2 ) , V_611 ) ;
F_227 ( V_2 , V_4 ) ;
goto V_606;
}
return true ;
V_606:
F_283 ( V_2 , V_4 ) ;
return false ;
}
void F_357 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_20 * V_51 , unsigned int V_15 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
if ( F_11 ( ! V_2 -> V_612 ) )
F_8 ( V_2 ) -> V_613 -> V_614 ( V_2 , V_4 ) ;
V_38 -> V_60 . V_280 = 0 ;
if ( ( F_13 ( V_51 ) & V_615 ) == V_38 -> V_396 &&
F_26 ( V_4 ) -> V_89 == V_38 -> V_102 &&
! F_62 ( F_26 ( V_4 ) -> V_170 , V_38 -> V_119 ) ) {
int V_23 = V_38 -> V_23 ;
if ( V_23 == sizeof( struct V_20 ) + V_478 ) {
if ( ! F_251 ( V_38 , V_51 ) )
goto V_616;
if ( ( T_7 ) ( V_38 -> V_60 . V_408 - V_38 -> V_60 . V_407 ) < 0 )
goto V_616;
}
if ( V_15 <= V_23 ) {
if ( V_15 == V_23 ) {
if ( V_23 ==
( sizeof( struct V_20 ) + V_478 ) &&
V_38 -> V_102 == V_38 -> V_410 )
F_232 ( V_38 ) ;
F_240 ( V_2 , V_4 , 0 ) ;
F_285 ( V_4 ) ;
F_342 ( V_2 ) ;
return;
} else {
F_356 ( F_4 ( V_2 ) , V_610 ) ;
goto V_606;
}
} else {
int V_524 = 0 ;
bool V_520 = false ;
if ( V_38 -> V_559 . V_560 == V_561 &&
V_38 -> V_90 == V_38 -> V_102 &&
V_15 - V_23 <= V_38 -> V_559 . V_15 &&
F_312 ( V_2 ) ) {
F_313 ( V_564 ) ;
if ( ! F_352 ( V_2 , V_4 , V_23 ) ) {
if ( V_23 ==
( sizeof( struct V_20 ) +
V_478 ) &&
V_38 -> V_102 == V_38 -> V_410 )
F_232 ( V_38 ) ;
F_56 ( V_2 , V_4 ) ;
F_304 ( V_4 , V_23 ) ;
F_220 ( V_38 , F_26 ( V_4 ) -> V_104 ) ;
F_77 ( F_4 ( V_2 ) ,
V_617 ) ;
V_524 = 1 ;
}
}
if ( ! V_524 ) {
if ( F_358 ( V_4 ) )
goto V_618;
if ( ( int ) V_4 -> V_71 > V_2 -> V_619 )
goto V_620;
if ( V_23 ==
( sizeof( struct V_20 ) + V_478 ) &&
V_38 -> V_102 == V_38 -> V_410 )
F_232 ( V_38 ) ;
F_56 ( V_2 , V_4 ) ;
F_77 ( F_4 ( V_2 ) , V_621 ) ;
V_524 = F_303 ( V_2 , V_4 , V_23 ,
& V_520 ) ;
}
F_58 ( V_2 , V_4 ) ;
if ( F_26 ( V_4 ) -> V_170 != V_38 -> V_117 ) {
F_240 ( V_2 , V_4 , V_429 ) ;
F_342 ( V_2 ) ;
if ( ! F_348 ( V_2 ) )
goto V_622;
}
F_344 ( V_2 , 0 ) ;
V_622:
if ( V_524 )
F_293 ( V_4 , V_520 ) ;
V_2 -> V_567 ( V_2 ) ;
return;
}
}
V_616:
if ( V_15 < ( V_51 -> V_447 << 2 ) || F_358 ( V_4 ) )
goto V_618;
if ( ! V_51 -> V_351 && ! V_51 -> V_603 && ! V_51 -> V_53 )
goto V_606;
if ( ! F_355 ( V_2 , V_4 , V_51 , 1 ) )
return;
V_620:
if ( F_240 ( V_2 , V_4 , V_424 | V_423 ) < 0 )
goto V_606;
F_56 ( V_2 , V_4 ) ;
F_351 ( V_2 , V_4 , V_51 ) ;
F_310 ( V_2 , V_4 ) ;
F_342 ( V_2 ) ;
F_347 ( V_2 ) ;
return;
V_618:
F_356 ( F_4 ( V_2 ) , V_623 ) ;
F_356 ( F_4 ( V_2 ) , V_610 ) ;
V_606:
F_283 ( V_2 , V_4 ) ;
}
void F_359 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
F_266 ( V_2 , V_495 ) ;
if ( V_4 ) {
V_11 -> V_613 -> V_614 ( V_2 , V_4 ) ;
F_360 ( V_2 , V_4 ) ;
}
V_11 -> V_613 -> V_624 ( V_2 ) ;
F_361 ( V_2 ) ;
F_362 ( V_2 ) ;
V_38 -> V_625 = V_88 ;
F_45 ( V_2 ) ;
if ( F_262 ( V_2 , V_626 ) )
F_363 ( V_2 , F_364 ( V_38 ) ) ;
if ( ! V_38 -> V_60 . V_394 )
F_365 ( V_38 , V_38 -> V_391 ) ;
else
V_38 -> V_396 = 0 ;
if ( ! F_262 ( V_2 , V_489 ) ) {
V_2 -> V_502 ( V_2 ) ;
F_270 ( V_2 , V_627 , V_628 ) ;
}
}
static bool F_366 ( struct V_1 * V_2 , struct V_3 * V_629 ,
struct V_437 * V_436 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_3 * V_18 = V_38 -> V_630 ? F_110 ( V_2 ) : NULL ;
T_8 V_78 = V_38 -> V_60 . V_61 , V_631 = 0 ;
bool V_632 = false ;
if ( V_78 == V_38 -> V_60 . V_455 ) {
struct V_443 V_633 ;
F_367 ( & V_633 ) ;
V_633 . V_455 = V_633 . V_61 = 0 ;
F_246 ( V_629 , & V_633 , 0 , NULL ) ;
V_78 = V_633 . V_61 ;
}
if ( ! V_38 -> V_634 ) {
V_436 -> V_15 = - 1 ;
} else if ( V_38 -> V_635 ) {
V_632 = ( V_436 -> V_15 < 0 && V_18 ) ;
} else if ( V_436 -> V_15 < 0 && ! V_38 -> V_630 ) {
V_631 = V_38 -> V_636 ? 2 : 1 ;
}
F_368 ( V_2 , V_78 , V_436 , V_632 , V_631 ) ;
if ( V_18 ) {
F_117 (data, sk) {
if ( V_18 == F_115 ( V_2 ) ||
F_369 ( V_2 , V_18 , 1 ) )
break;
}
F_201 ( V_2 ) ;
F_77 ( F_4 ( V_2 ) ,
V_637 ) ;
return true ;
}
V_38 -> V_638 = V_38 -> V_630 ;
if ( V_38 -> V_638 )
F_77 ( F_4 ( V_2 ) ,
V_639 ) ;
F_370 ( V_2 , V_629 ) ;
return false ;
}
static int F_371 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_20 * V_51 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_437 V_438 = { . V_15 = - 1 } ;
int V_640 = V_38 -> V_60 . V_61 ;
F_246 ( V_4 , & V_38 -> V_60 , 0 , & V_438 ) ;
if ( V_38 -> V_60 . V_280 && V_38 -> V_60 . V_103 )
V_38 -> V_60 . V_103 -= V_38 -> V_477 ;
if ( V_51 -> V_351 ) {
if ( ! F_62 ( F_26 ( V_4 ) -> V_170 , V_38 -> V_117 ) ||
F_62 ( F_26 ( V_4 ) -> V_170 , V_38 -> V_119 ) )
goto V_641;
if ( V_38 -> V_60 . V_280 && V_38 -> V_60 . V_103 &&
! F_211 ( V_38 -> V_60 . V_103 , V_38 -> V_281 ,
V_88 ) ) {
F_77 ( F_4 ( V_2 ) ,
V_642 ) ;
goto V_641;
}
if ( V_51 -> V_603 ) {
F_260 ( V_2 ) ;
goto V_606;
}
if ( ! V_51 -> V_53 )
goto V_643;
F_30 ( V_38 , V_51 ) ;
F_372 ( V_38 , F_26 ( V_4 ) -> V_89 ) ;
F_240 ( V_2 , V_4 , V_424 ) ;
V_38 -> V_102 = F_26 ( V_4 ) -> V_89 + 1 ;
V_38 -> V_410 = F_26 ( V_4 ) -> V_89 + 1 ;
V_38 -> V_391 = F_161 ( V_51 -> V_72 ) ;
if ( ! V_38 -> V_60 . V_459 ) {
V_38 -> V_60 . V_394 = V_38 -> V_60 . V_644 = 0 ;
V_38 -> V_75 = F_17 ( V_38 -> V_75 , 65535U ) ;
}
if ( V_38 -> V_60 . V_280 ) {
V_38 -> V_60 . V_463 = 1 ;
V_38 -> V_23 =
sizeof( struct V_20 ) + V_478 ;
V_38 -> V_77 -= V_478 ;
F_232 ( V_38 ) ;
} else {
V_38 -> V_23 = sizeof( struct V_20 ) ;
}
if ( F_151 ( V_38 ) && V_645 )
F_373 ( V_38 ) ;
F_374 ( V_2 ) ;
F_180 ( V_2 , V_11 -> V_317 ) ;
F_52 ( V_2 ) ;
V_38 -> V_90 = V_38 -> V_102 ;
F_340 () ;
F_359 ( V_2 , V_4 ) ;
if ( ( V_38 -> V_634 || V_38 -> V_630 ) &&
F_366 ( V_2 , V_4 , & V_438 ) )
return - 1 ;
if ( V_2 -> V_646 ||
V_11 -> V_647 . V_648 ||
V_11 -> V_13 . V_31 ) {
F_59 ( V_2 ) ;
V_11 -> V_13 . V_109 = V_88 ;
F_18 ( V_2 ) ;
F_143 ( V_2 , V_649 ,
V_650 , V_262 ) ;
V_606:
F_283 ( V_2 , V_4 ) ;
return 0 ;
} else {
F_231 ( V_2 ) ;
}
return - 1 ;
}
if ( V_51 -> V_603 ) {
goto V_643;
}
if ( V_38 -> V_60 . V_409 && V_38 -> V_60 . V_280 &&
F_375 ( & V_38 -> V_60 , 0 ) )
goto V_643;
if ( V_51 -> V_53 ) {
F_266 ( V_2 , V_494 ) ;
if ( V_38 -> V_60 . V_280 ) {
V_38 -> V_60 . V_463 = 1 ;
F_232 ( V_38 ) ;
V_38 -> V_23 =
sizeof( struct V_20 ) + V_478 ;
} else {
V_38 -> V_23 = sizeof( struct V_20 ) ;
}
V_38 -> V_102 = F_26 ( V_4 ) -> V_89 + 1 ;
V_38 -> V_90 = V_38 -> V_102 ;
V_38 -> V_410 = F_26 ( V_4 ) -> V_89 + 1 ;
V_38 -> V_391 = F_161 ( V_51 -> V_72 ) ;
V_38 -> V_390 = F_26 ( V_4 ) -> V_89 ;
V_38 -> V_161 = V_38 -> V_391 ;
F_31 ( V_38 , V_51 ) ;
F_374 ( V_2 ) ;
F_180 ( V_2 , V_11 -> V_317 ) ;
F_52 ( V_2 ) ;
F_376 ( V_2 ) ;
#if 0
return -1;
#else
goto V_606;
#endif
}
V_643:
F_367 ( & V_38 -> V_60 ) ;
V_38 -> V_60 . V_61 = V_640 ;
goto V_606;
V_641:
F_367 ( & V_38 -> V_60 ) ;
V_38 -> V_60 . V_61 = V_640 ;
return 1 ;
}
int F_377 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
const struct V_20 * V_51 = F_14 ( V_4 ) ;
struct V_346 * V_347 ;
int V_651 = 0 ;
bool V_652 ;
switch ( V_2 -> V_481 ) {
case V_487 :
goto V_606;
case V_653 :
if ( V_51 -> V_351 )
return 1 ;
if ( V_51 -> V_603 )
goto V_606;
if ( V_51 -> V_53 ) {
if ( V_51 -> V_523 )
goto V_606;
if ( V_11 -> V_613 -> V_654 ( V_2 , V_4 ) < 0 )
return 1 ;
F_378 ( V_4 ) ;
return 0 ;
}
goto V_606;
case V_482 :
V_38 -> V_60 . V_280 = 0 ;
V_651 = F_371 ( V_2 , V_4 , V_51 ) ;
if ( V_651 >= 0 )
return V_651 ;
F_351 ( V_2 , V_4 , V_51 ) ;
F_285 ( V_4 ) ;
F_342 ( V_2 ) ;
return 0 ;
}
V_38 -> V_60 . V_280 = 0 ;
V_347 = V_38 -> V_353 ;
if ( V_347 ) {
F_171 ( V_2 -> V_481 != V_494 &&
V_2 -> V_481 != V_498 ) ;
if ( ! F_379 ( V_2 , V_4 , V_347 , true ) )
goto V_606;
}
if ( ! V_51 -> V_351 && ! V_51 -> V_603 && ! V_51 -> V_53 )
goto V_606;
if ( ! F_355 ( V_2 , V_4 , V_51 , 0 ) )
return 0 ;
V_652 = F_240 ( V_2 , V_4 , V_424 |
V_423 ) > 0 ;
switch ( V_2 -> V_481 ) {
case V_494 :
if ( ! V_652 )
return 1 ;
if ( ! V_38 -> V_113 )
F_196 ( V_2 , V_347 ) ;
if ( V_347 ) {
F_8 ( V_2 ) -> V_247 = 0 ;
F_380 ( V_2 , V_347 , false ) ;
} else {
V_11 -> V_613 -> V_624 ( V_2 ) ;
F_362 ( V_2 ) ;
F_374 ( V_2 ) ;
V_38 -> V_90 = V_38 -> V_102 ;
F_45 ( V_2 ) ;
}
F_340 () ;
F_266 ( V_2 , V_495 ) ;
V_2 -> V_502 ( V_2 ) ;
if ( V_2 -> V_589 )
F_270 ( V_2 , V_627 , V_628 ) ;
V_38 -> V_117 = F_26 ( V_4 ) -> V_170 ;
V_38 -> V_391 = F_161 ( V_51 -> V_72 ) << V_38 -> V_60 . V_394 ;
F_372 ( V_38 , F_26 ( V_4 ) -> V_89 ) ;
if ( V_38 -> V_60 . V_463 )
V_38 -> V_77 -= V_478 ;
if ( V_347 ) {
F_201 ( V_2 ) ;
} else
F_361 ( V_2 ) ;
if ( ! F_8 ( V_2 ) -> V_56 -> V_310 )
F_64 ( V_2 ) ;
V_38 -> V_625 = V_88 ;
F_52 ( V_2 ) ;
F_381 ( V_38 ) ;
break;
case V_498 : {
struct V_34 * V_35 ;
int V_655 ;
if ( V_347 ) {
if ( ! V_652 )
return 1 ;
F_380 ( V_2 , V_347 , false ) ;
F_201 ( V_2 ) ;
}
if ( V_38 -> V_117 != V_38 -> V_656 )
break;
F_266 ( V_2 , V_499 ) ;
V_2 -> V_491 |= V_657 ;
V_35 = F_20 ( V_2 ) ;
if ( V_35 )
F_241 ( V_35 ) ;
if ( ! F_262 ( V_2 , V_489 ) ) {
V_2 -> V_502 ( V_2 ) ;
break;
}
if ( V_38 -> V_658 < 0 ||
( F_26 ( V_4 ) -> V_104 != F_26 ( V_4 ) -> V_89 &&
F_62 ( F_26 ( V_4 ) -> V_104 - V_51 -> V_523 , V_38 -> V_102 ) ) ) {
F_263 ( V_2 ) ;
F_77 ( F_4 ( V_2 ) , V_659 ) ;
return 1 ;
}
V_655 = F_382 ( V_2 ) ;
if ( V_655 > V_660 ) {
F_363 ( V_2 , V_655 - V_660 ) ;
} else if ( V_51 -> V_523 || F_312 ( V_2 ) ) {
F_363 ( V_2 , V_655 ) ;
} else {
F_267 ( V_2 , V_499 , V_655 ) ;
goto V_606;
}
break;
}
case V_496 :
if ( V_38 -> V_117 == V_38 -> V_656 ) {
F_267 ( V_2 , V_500 , 0 ) ;
goto V_606;
}
break;
case V_497 :
if ( V_38 -> V_117 == V_38 -> V_656 ) {
F_383 ( V_2 ) ;
F_263 ( V_2 ) ;
goto V_606;
}
break;
}
F_351 ( V_2 , V_4 , V_51 ) ;
switch ( V_2 -> V_481 ) {
case V_485 :
case V_496 :
case V_497 :
if ( ! F_55 ( F_26 ( V_4 ) -> V_89 , V_38 -> V_102 ) )
break;
case V_498 :
case V_499 :
if ( V_2 -> V_491 & V_492 ) {
if ( F_26 ( V_4 ) -> V_104 != F_26 ( V_4 ) -> V_89 &&
F_62 ( F_26 ( V_4 ) -> V_104 - V_51 -> V_523 , V_38 -> V_102 ) ) {
F_77 ( F_4 ( V_2 ) , V_659 ) ;
F_260 ( V_2 ) ;
return 1 ;
}
}
case V_495 :
F_310 ( V_2 , V_4 ) ;
V_651 = 1 ;
break;
}
if ( V_2 -> V_481 != V_487 ) {
F_342 ( V_2 ) ;
F_347 ( V_2 ) ;
}
if ( ! V_651 ) {
V_606:
F_283 ( V_2 , V_4 ) ;
}
return 0 ;
}
static inline void F_384 ( struct V_346 * V_347 , T_12 V_661 , int V_662 )
{
struct V_663 * V_664 = F_385 ( V_347 ) ;
if ( V_662 == V_286 )
F_386 ( L_23 ,
& V_664 -> V_665 , V_661 ) ;
#if F_163 ( V_289 )
else if ( V_662 == V_290 )
F_386 ( L_24 ,
& V_664 -> V_666 , V_661 ) ;
#endif
}
static void F_387 ( struct V_346 * V_347 ,
const struct V_3 * V_4 ,
const struct V_1 * V_667 ,
const struct V_34 * V_35 )
{
const struct V_20 * V_51 = F_14 ( V_4 ) ;
const struct V_241 * V_241 = F_4 ( V_667 ) ;
bool V_668 = V_51 -> V_52 && V_51 -> V_42 ;
bool V_669 , V_670 ;
T_2 V_671 ;
if ( ! V_668 )
return;
V_669 = ! F_388 ( F_26 ( V_4 ) -> V_44 ) ;
V_671 = F_389 ( V_35 , V_672 ) ;
V_670 = V_241 -> V_253 . V_673 || V_671 ;
if ( ( ! V_669 && V_670 ) || F_27 ( V_667 ) ||
( V_671 & V_674 ) )
F_385 ( V_347 ) -> V_670 = 1 ;
}
static void F_390 ( struct V_346 * V_347 ,
const struct V_443 * V_60 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_663 * V_664 = F_385 ( V_347 ) ;
V_347 -> V_675 = 0 ;
V_347 -> V_676 = 0 ;
F_197 ( V_347 ) -> V_677 = F_26 ( V_4 ) -> V_89 ;
F_197 ( V_347 ) -> V_102 = F_26 ( V_4 ) -> V_89 + 1 ;
F_198 ( & F_197 ( V_347 ) -> V_349 ) ;
F_197 ( V_347 ) -> V_397 = 0 ;
V_347 -> V_78 = V_60 -> V_61 ;
V_347 -> V_407 = V_60 -> V_280 ? V_60 -> V_408 : 0 ;
V_664 -> V_463 = V_60 -> V_463 ;
V_664 -> V_132 = V_60 -> V_132 ;
V_664 -> V_394 = V_60 -> V_394 ;
V_664 -> V_459 = V_60 -> V_459 ;
V_664 -> V_240 = 0 ;
V_664 -> V_670 = 0 ;
V_664 -> V_678 = F_14 ( V_4 ) -> V_679 ;
V_664 -> V_680 = F_161 ( F_14 ( V_4 ) -> V_681 ) ;
V_664 -> V_682 = F_391 ( V_2 , V_4 ) ;
}
struct V_346 * F_392 ( const struct V_683 * V_684 ,
struct V_1 * V_685 ,
bool V_686 )
{
struct V_346 * V_347 = F_393 ( V_684 , V_685 ,
V_686 ) ;
if ( V_347 ) {
struct V_663 * V_664 = F_385 ( V_347 ) ;
F_394 ( V_664 , V_412 ) ;
V_664 -> V_633 = NULL ;
#if F_163 ( V_289 )
V_664 -> V_687 = NULL ;
#endif
F_395 ( & V_664 -> V_688 , 0 ) ;
V_664 -> V_689 = V_690 ;
F_396 ( & V_664 -> V_691 , F_4 ( V_685 ) ) ;
V_664 -> V_692 = V_685 -> V_285 ;
}
return V_347 ;
}
static bool F_397 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_693 )
{
struct V_694 * V_695 = & F_8 ( V_2 ) -> V_647 ;
const char * V_282 = L_25 ;
bool V_696 = false ;
struct V_241 * V_241 = F_4 ( V_2 ) ;
#ifdef F_398
if ( V_241 -> V_253 . V_697 ) {
V_282 = L_26 ;
V_696 = true ;
F_399 ( F_4 ( V_2 ) , V_698 ) ;
} else
#endif
F_399 ( F_4 ( V_2 ) , V_699 ) ;
if ( ! V_695 -> V_700 &&
V_241 -> V_253 . V_697 != 2 &&
F_400 ( & V_695 -> V_700 , 1 ) == 0 )
F_401 ( L_27 ,
V_693 , F_161 ( F_14 ( V_4 ) -> V_681 ) , V_282 ) ;
return V_696 ;
}
static void F_402 ( const struct V_1 * V_2 ,
struct V_346 * V_347 ,
const struct V_3 * V_4 )
{
if ( F_15 ( V_2 ) -> V_701 ) {
T_2 V_15 = F_403 ( V_4 ) + F_404 ( V_4 ) ;
T_2 * V_578 ;
V_578 = F_405 ( V_15 + sizeof( T_2 ) , V_180 ) ;
if ( V_578 ) {
V_578 [ 0 ] = V_15 ;
memcpy ( & V_578 [ 1 ] , F_406 ( V_4 ) , V_15 ) ;
V_347 -> V_702 = V_578 ;
}
}
}
int F_407 ( struct V_683 * V_703 ,
const struct V_704 * V_705 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_437 V_438 = { . V_15 = - 1 } ;
T_4 V_706 = F_26 ( V_4 ) -> V_707 ;
struct V_443 V_708 ;
struct V_37 * V_38 = F_15 ( V_2 ) ;
struct V_241 * V_241 = F_4 ( V_2 ) ;
struct V_1 * V_709 = NULL ;
struct V_34 * V_35 = NULL ;
struct V_346 * V_347 ;
bool V_696 = false ;
struct V_710 V_711 ;
if ( ( V_241 -> V_253 . V_697 == 2 ||
F_408 ( V_2 ) ) && ! V_706 ) {
V_696 = F_397 ( V_2 , V_4 , V_703 -> V_712 ) ;
if ( ! V_696 )
goto V_566;
}
if ( F_409 ( V_2 ) ) {
F_77 ( F_4 ( V_2 ) , V_713 ) ;
goto V_566;
}
V_347 = F_392 ( V_703 , V_2 , ! V_696 ) ;
if ( ! V_347 )
goto V_566;
F_197 ( V_347 ) -> V_714 = V_705 ;
F_197 ( V_347 ) -> V_715 = 0 ;
F_367 ( & V_708 ) ;
V_708 . V_61 = V_705 -> V_61 ;
V_708 . V_455 = V_38 -> V_60 . V_455 ;
F_246 ( V_4 , & V_708 , 0 , V_696 ? NULL : & V_438 ) ;
if ( V_696 && ! V_708 . V_280 )
F_367 ( & V_708 ) ;
V_708 . V_463 = V_708 . V_280 ;
F_390 ( V_347 , & V_708 , V_4 , V_2 ) ;
F_385 ( V_347 ) -> V_716 = F_160 ( V_2 ) -> V_717 ;
F_385 ( V_347 ) -> V_718 = F_410 ( V_2 , V_4 ) ;
V_705 -> V_719 ( V_347 , V_2 , V_4 ) ;
if ( F_411 ( V_2 , V_4 , V_347 ) )
goto V_720;
if ( V_706 && V_708 . V_463 )
V_705 -> V_721 ( V_4 , & F_197 ( V_347 ) -> V_715 ) ;
if ( ! V_696 && ! V_706 ) {
if ( V_722 . V_723 ) {
bool V_724 ;
V_35 = V_705 -> V_725 ( V_2 , & V_711 , V_347 , & V_724 ) ;
if ( V_35 && V_724 &&
! F_412 ( V_347 , V_35 , true ,
V_708 . V_280 ) ) {
F_77 ( F_4 ( V_2 ) , V_726 ) ;
goto V_727;
}
}
else if ( ! V_241 -> V_253 . V_697 &&
( V_728 - F_413 ( V_2 ) <
( V_728 >> 2 ) ) &&
! F_412 ( V_347 , V_35 , false ,
V_708 . V_280 ) ) {
F_384 ( V_347 , F_161 ( F_14 ( V_4 ) -> V_679 ) ,
V_703 -> V_662 ) ;
goto V_727;
}
V_706 = V_705 -> V_721 ( V_4 , & F_197 ( V_347 ) -> V_715 ) ;
}
if ( ! V_35 ) {
V_35 = V_705 -> V_725 ( V_2 , & V_711 , V_347 , NULL ) ;
if ( ! V_35 )
goto V_720;
}
F_387 ( V_347 , V_4 , V_2 , V_35 ) ;
if ( V_696 ) {
V_706 = F_414 ( V_705 , V_2 , V_4 , & V_347 -> V_78 ) ;
F_197 ( V_347 ) -> V_715 = 0 ;
V_347 -> V_676 = V_708 . V_463 ;
if ( ! V_708 . V_463 )
F_385 ( V_347 ) -> V_670 = 0 ;
}
F_197 ( V_347 ) -> V_729 = V_706 ;
F_197 ( V_347 ) -> V_730 = F_415 () ;
F_416 ( V_347 , V_2 , V_35 ) ;
if ( ! V_696 ) {
F_402 ( V_2 , V_347 , V_4 ) ;
V_709 = F_417 ( V_2 , V_4 , V_347 , & V_438 , V_35 ) ;
}
if ( V_709 ) {
V_705 -> V_731 ( V_709 , V_35 , & V_711 , V_347 ,
& V_438 , V_732 ) ;
F_418 ( V_2 , V_347 , V_709 ) ;
V_2 -> V_567 ( V_2 ) ;
F_419 ( V_709 ) ;
F_420 ( V_709 ) ;
} else {
F_197 ( V_347 ) -> V_733 = false ;
if ( ! V_696 )
F_421 ( V_2 , V_347 , V_734 ) ;
V_705 -> V_731 ( V_2 , V_35 , & V_711 , V_347 , & V_438 ,
! V_696 ? V_735 :
V_736 ) ;
if ( V_696 ) {
F_422 ( V_347 ) ;
return 0 ;
}
}
F_423 ( V_347 ) ;
return 0 ;
V_727:
F_424 ( V_35 ) ;
V_720:
F_422 ( V_347 ) ;
V_566:
F_425 ( V_2 ) ;
return 0 ;
}
