static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const unsigned int V_7 = V_6 -> V_8 . V_9 ;
unsigned int V_10 ;
V_6 -> V_8 . V_9 = 0 ;
V_10 = F_3 ( V_4 ) -> V_11 ? : V_4 -> V_10 ;
if ( V_10 >= V_6 -> V_8 . V_12 ) {
V_6 -> V_8 . V_12 = V_10 ;
} else {
V_10 += V_4 -> V_13 - F_4 ( V_4 ) ;
if ( V_10 >= V_14 + sizeof( struct V_15 ) ||
( V_10 >= V_16 + sizeof( struct V_15 ) &&
! ( F_5 ( F_6 ( V_4 ) ) & V_17 ) ) ) {
V_10 -= F_7 ( V_2 ) -> V_18 ;
V_6 -> V_8 . V_9 = V_10 ;
if ( V_10 == V_7 ) {
V_6 -> V_8 . V_12 = V_10 ;
return;
}
}
if ( V_6 -> V_8 . V_19 & V_20 )
V_6 -> V_8 . V_19 |= V_21 ;
V_6 -> V_8 . V_19 |= V_20 ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_22 = F_7 ( V_2 ) -> V_23 / ( 2 * V_6 -> V_8 . V_12 ) ;
if ( V_22 == 0 )
V_22 = 2 ;
if ( V_22 > V_6 -> V_8 . V_24 )
V_6 -> V_8 . V_24 = F_9 ( V_22 , V_25 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
V_6 -> V_8 . V_26 = 0 ;
V_6 -> V_8 . V_27 = V_28 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_29 * V_30 = F_12 ( V_2 ) ;
return ( V_30 && F_13 ( V_30 , V_31 ) ) ||
( V_6 -> V_8 . V_24 && ! V_6 -> V_8 . V_26 ) ;
}
static void F_14 ( struct V_32 * V_33 )
{
if ( V_33 -> V_34 & V_35 )
V_33 -> V_34 |= V_36 ;
}
static void F_15 ( struct V_32 * V_33 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) -> V_37 )
V_33 -> V_34 &= ~ V_38 ;
}
static void F_16 ( struct V_32 * V_33 )
{
V_33 -> V_34 &= ~ V_38 ;
}
static void F_17 ( struct V_32 * V_33 , const struct V_3 * V_4 )
{
switch ( F_18 ( V_4 ) -> V_39 & V_40 ) {
case V_41 :
if ( V_33 -> V_34 & V_42 )
F_10 ( (struct V_1 * ) V_33 ) ;
break;
case V_43 :
if ( F_19 ( (struct V_1 * ) V_33 ) )
F_20 ( (struct V_1 * ) V_33 , V_44 ) ;
if ( ! ( V_33 -> V_34 & V_38 ) ) {
F_10 ( (struct V_1 * ) V_33 ) ;
V_33 -> V_34 |= V_38 ;
}
V_33 -> V_34 |= V_42 ;
break;
default:
if ( F_19 ( (struct V_1 * ) V_33 ) )
F_20 ( (struct V_1 * ) V_33 , V_45 ) ;
V_33 -> V_34 |= V_42 ;
break;
}
}
static void F_21 ( struct V_32 * V_33 , const struct V_3 * V_4 )
{
if ( V_33 -> V_34 & V_35 )
F_17 ( V_33 , V_4 ) ;
}
static void F_22 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
if ( ( V_33 -> V_34 & V_35 ) && ( ! V_46 -> V_47 || V_46 -> V_37 ) )
V_33 -> V_34 &= ~ V_35 ;
}
static void F_23 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
if ( ( V_33 -> V_34 & V_35 ) && ( ! V_46 -> V_47 || ! V_46 -> V_37 ) )
V_33 -> V_34 &= ~ V_35 ;
}
static bool F_24 ( const struct V_32 * V_33 , const struct V_15 * V_46 )
{
if ( V_46 -> V_47 && ! V_46 -> V_48 && ( V_33 -> V_34 & V_35 ) )
return true ;
return false ;
}
static void F_25 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_49 , V_50 ;
T_1 V_51 ;
V_50 = F_26 ( T_1 , V_33 -> V_52 . V_53 , V_33 -> V_54 ) +
V_55 +
F_27 ( sizeof( struct V_56 ) ) ;
V_50 = F_28 ( V_50 ) +
F_27 ( sizeof( struct V_3 ) ) ;
V_51 = F_26 ( T_1 , V_57 , V_33 -> V_58 ) ;
V_51 = F_26 ( T_1 , V_51 , V_33 -> V_59 + 1 ) ;
V_49 = 2 * V_51 * V_50 ;
if ( V_2 -> V_60 < V_49 )
V_2 -> V_60 = F_9 ( V_49 , V_61 [ 2 ] ) ;
}
static int F_29 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_62 = F_30 ( V_4 -> V_62 ) >> 1 ;
int V_63 = F_30 ( V_64 [ 2 ] ) >> 1 ;
while ( V_33 -> V_65 <= V_63 ) {
if ( V_62 <= V_4 -> V_10 )
return 2 * F_2 ( V_2 ) -> V_8 . V_12 ;
V_62 >>= 1 ;
V_63 >>= 1 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_65 < V_33 -> V_66 &&
( int ) V_33 -> V_65 < F_32 ( V_2 ) &&
! F_33 ( V_2 ) ) {
int V_67 ;
if ( F_30 ( V_4 -> V_62 ) <= V_4 -> V_10 )
V_67 = 2 * V_33 -> V_68 ;
else
V_67 = F_29 ( V_2 , V_4 ) ;
if ( V_67 ) {
V_67 = F_26 ( int , V_67 , 2 * V_4 -> V_10 ) ;
V_33 -> V_65 = F_9 ( V_33 -> V_65 + V_67 ,
V_33 -> V_66 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_69 = F_7 ( V_2 ) -> V_68 ;
int V_70 ;
V_70 = 2 * F_35 ( V_69 + V_55 ) *
F_36 ( V_69 ) ;
if ( V_71 )
V_70 <<= 2 ;
if ( V_2 -> V_72 < V_70 )
V_2 -> V_72 = F_9 ( V_70 , V_64 [ 2 ] ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_73 ;
if ( ! ( V_2 -> V_74 & V_75 ) )
F_34 ( V_2 ) ;
if ( ! ( V_2 -> V_74 & V_76 ) )
F_25 ( V_2 ) ;
V_33 -> V_77 . V_78 = V_33 -> V_23 ;
V_33 -> V_77 . time = V_79 ;
V_33 -> V_77 . V_80 = V_33 -> V_81 ;
V_73 = F_38 ( V_2 ) ;
if ( V_33 -> V_66 >= V_73 ) {
V_33 -> V_66 = V_73 ;
if ( V_82 && V_73 > 4 * V_33 -> V_68 )
V_33 -> V_66 = F_39 ( V_73 -
( V_73 >> V_82 ) ,
4 * V_33 -> V_68 ) ;
}
if ( V_82 &&
V_33 -> V_66 > 2 * V_33 -> V_68 &&
V_33 -> V_66 + V_33 -> V_68 > V_73 )
V_33 -> V_66 = F_39 ( 2 * V_33 -> V_68 , V_73 - V_33 -> V_68 ) ;
V_33 -> V_65 = F_9 ( V_33 -> V_65 , V_33 -> V_66 ) ;
V_33 -> V_83 = V_79 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_72 < V_64 [ 2 ] &&
! ( V_2 -> V_74 & V_75 ) &&
! F_33 ( V_2 ) &&
F_41 ( V_2 ) < F_42 ( V_2 , 0 ) ) {
V_2 -> V_72 = F_9 ( F_43 ( & V_2 -> V_84 ) ,
V_64 [ 2 ] ) ;
}
if ( F_43 ( & V_2 -> V_84 ) > V_2 -> V_72 )
V_33 -> V_65 = F_9 ( V_33 -> V_66 , 2U * V_33 -> V_68 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned int V_85 = F_45 (unsigned int, tp->advmss, tp->mss_cache) ;
V_85 = F_9 ( V_85 , V_33 -> V_23 / 2 ) ;
V_85 = F_9 ( V_85 , V_14 ) ;
V_85 = F_39 ( V_85 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_85 ;
}
static void F_46 ( struct V_32 * V_33 , T_1 V_86 , int V_87 )
{
T_1 V_88 = V_33 -> V_89 . V_90 ;
long V_91 = V_86 ;
if ( V_91 == 0 )
V_91 = 1 ;
if ( V_88 != 0 ) {
if ( ! V_87 ) {
V_91 -= ( V_88 >> 3 ) ;
V_88 += V_91 ;
} else {
V_91 <<= 3 ;
if ( V_91 < V_88 )
V_88 = V_91 ;
}
} else {
V_88 = V_91 << 3 ;
}
if ( V_33 -> V_89 . V_90 != V_88 )
V_33 -> V_89 . V_90 = V_88 ;
}
static inline void F_47 ( struct V_32 * V_33 )
{
if ( V_33 -> V_89 . time == 0 )
goto V_92;
if ( F_48 ( V_33 -> V_93 , V_33 -> V_89 . V_80 ) )
return;
F_46 ( V_33 , V_79 - V_33 -> V_89 . time , 1 ) ;
V_92:
V_33 -> V_89 . V_80 = V_33 -> V_93 + V_33 -> V_23 ;
V_33 -> V_89 . time = V_79 ;
}
static inline void F_49 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_52 . V_94 &&
( F_18 ( V_4 ) -> V_95 -
F_18 ( V_4 ) -> V_80 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_46 ( V_33 , V_79 - V_33 -> V_52 . V_94 , 0 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int time ;
int V_96 ;
time = V_79 - V_33 -> V_77 . time ;
if ( time < ( V_33 -> V_89 . V_90 >> 3 ) || V_33 -> V_89 . V_90 == 0 )
return;
V_96 = V_33 -> V_81 - V_33 -> V_77 . V_80 ;
if ( V_96 <= V_33 -> V_77 . V_78 )
goto V_92;
if ( V_71 &&
! ( V_2 -> V_74 & V_75 ) ) {
int V_97 , V_70 , V_98 ;
V_97 = ( V_96 << 1 ) + 16 * V_33 -> V_68 ;
if ( V_96 >=
V_33 -> V_77 . V_78 + ( V_33 -> V_77 . V_78 >> 2 ) ) {
if ( V_96 >=
V_33 -> V_77 . V_78 + ( V_33 -> V_77 . V_78 >> 1 ) )
V_97 <<= 1 ;
else
V_97 += ( V_97 >> 1 ) ;
}
V_70 = F_35 ( V_33 -> V_68 + V_55 ) ;
while ( F_30 ( V_70 ) < V_33 -> V_68 )
V_70 += 128 ;
V_98 = F_9 ( V_97 / V_33 -> V_68 * V_70 , V_64 [ 2 ] ) ;
if ( V_98 > V_2 -> V_72 ) {
V_2 -> V_72 = V_98 ;
V_33 -> V_66 = V_97 ;
}
}
V_33 -> V_77 . V_78 = V_96 ;
V_92:
V_33 -> V_77 . V_80 = V_33 -> V_81 ;
V_33 -> V_77 . time = V_79 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_99 ;
F_52 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_47 ( V_33 ) ;
V_99 = V_79 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_91 = V_99 - V_6 -> V_8 . V_100 ;
if ( V_91 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_91 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_91 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_101 )
V_6 -> V_8 . V_27 = V_6 -> V_101 ;
} else if ( V_91 > V_6 -> V_101 ) {
F_8 ( V_2 ) ;
F_53 ( V_2 ) ;
}
}
V_6 -> V_8 . V_100 = V_99 ;
F_21 ( V_33 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_31 ( V_2 , V_4 ) ;
}
static void F_54 ( struct V_1 * V_2 , long V_102 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
long V_91 = V_102 ;
T_1 V_103 = V_33 -> V_104 ;
if ( V_103 != 0 ) {
V_91 -= ( V_103 >> 3 ) ;
V_103 += V_91 ;
if ( V_91 < 0 ) {
V_91 = - V_91 ;
V_91 -= ( V_33 -> V_105 >> 2 ) ;
if ( V_91 > 0 )
V_91 >>= 3 ;
} else {
V_91 -= ( V_33 -> V_105 >> 2 ) ;
}
V_33 -> V_105 += V_91 ;
if ( V_33 -> V_105 > V_33 -> V_106 ) {
V_33 -> V_106 = V_33 -> V_105 ;
if ( V_33 -> V_106 > V_33 -> V_107 )
V_33 -> V_107 = V_33 -> V_106 ;
}
if ( F_55 ( V_33 -> V_108 , V_33 -> V_109 ) ) {
if ( V_33 -> V_106 < V_33 -> V_107 )
V_33 -> V_107 -= ( V_33 -> V_107 - V_33 -> V_106 ) >> 2 ;
V_33 -> V_109 = V_33 -> V_110 ;
V_33 -> V_106 = F_56 ( V_2 ) ;
}
} else {
V_103 = V_91 << 3 ;
V_33 -> V_105 = V_91 << 1 ;
V_33 -> V_107 = F_39 ( V_33 -> V_105 , F_56 ( V_2 ) ) ;
V_33 -> V_106 = V_33 -> V_107 ;
V_33 -> V_109 = V_33 -> V_110 ;
}
V_33 -> V_104 = F_39 ( 1U , V_103 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
T_2 V_111 ;
V_111 = ( T_2 ) V_33 -> V_54 * ( ( V_112 / 100 ) << 3 ) ;
if ( V_33 -> V_58 < V_33 -> V_113 / 2 )
V_111 *= V_114 ;
else
V_111 *= V_115 ;
V_111 *= F_39 ( V_33 -> V_58 , V_33 -> V_116 ) ;
if ( F_58 ( V_33 -> V_104 ) )
F_59 ( V_111 , V_33 -> V_104 ) ;
F_60 ( V_2 -> V_117 ) = F_45 ( T_2 , V_111 ,
V_2 -> V_118 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_101 = F_62 ( V_33 ) ;
F_63 ( V_2 ) ;
}
T_3 F_64 ( const struct V_32 * V_33 , const struct V_29 * V_30 )
{
T_3 V_119 = ( V_30 ? F_13 ( V_30 , V_120 ) : 0 ) ;
if ( ! V_119 )
V_119 = V_57 ;
return F_45 ( T_3 , V_119 , V_33 -> V_121 ) ;
}
void F_65 ( struct V_32 * V_33 )
{
if ( F_66 ( V_33 ) )
V_33 -> V_122 = NULL ;
V_33 -> V_52 . V_123 &= ~ V_124 ;
}
static void F_67 ( struct V_32 * V_33 )
{
V_33 -> V_52 . V_123 |= V_125 ;
}
static void F_68 ( struct V_1 * V_2 , const int V_126 ,
const int V_127 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_126 > V_33 -> V_59 ) {
int V_128 ;
V_33 -> V_59 = F_9 ( V_129 , V_126 ) ;
if ( V_127 )
V_128 = V_130 ;
else if ( F_69 ( V_33 ) )
V_128 = V_131 ;
else if ( F_66 ( V_33 ) )
V_128 = V_132 ;
else
V_128 = V_133 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
#if V_134 > 1
F_72 ( L_1 ,
V_33 -> V_52 . V_123 , F_2 ( V_2 ) -> V_135 ,
V_33 -> V_59 ,
V_33 -> V_136 ,
V_33 -> V_137 ,
V_33 -> V_138 ? V_33 -> V_139 : 0 ) ;
#endif
F_65 ( V_33 ) ;
}
if ( V_126 > 0 )
F_73 ( V_33 ) ;
}
static void F_74 ( struct V_32 * V_33 , struct V_3 * V_4 )
{
if ( ! V_33 -> V_140 ||
F_48 ( F_18 ( V_4 ) -> V_80 ,
F_18 ( V_33 -> V_140 ) -> V_80 ) )
V_33 -> V_140 = V_4 ;
if ( ! V_33 -> V_141 ||
F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_142 ) )
V_33 -> V_142 = F_18 ( V_4 ) -> V_95 ;
}
static void F_75 ( struct V_32 * V_33 , struct V_3 * V_4 )
{
if ( ! ( F_18 ( V_4 ) -> V_143 & ( V_144 | V_145 ) ) ) {
F_74 ( V_33 , V_4 ) ;
V_33 -> V_141 += F_76 ( V_4 ) ;
F_18 ( V_4 ) -> V_143 |= V_144 ;
}
}
static void F_77 ( struct V_32 * V_33 ,
struct V_3 * V_4 )
{
F_74 ( V_33 , V_4 ) ;
if ( ! ( F_18 ( V_4 ) -> V_143 & ( V_144 | V_145 ) ) ) {
V_33 -> V_141 += F_76 ( V_4 ) ;
F_18 ( V_4 ) -> V_143 |= V_144 ;
}
}
static bool F_78 ( struct V_32 * V_33 , bool V_146 ,
T_1 V_147 , T_1 V_95 )
{
if ( F_55 ( V_95 , V_33 -> V_110 ) || ! F_48 ( V_147 , V_95 ) )
return false ;
if ( ! F_48 ( V_147 , V_33 -> V_110 ) )
return false ;
if ( F_55 ( V_147 , V_33 -> V_108 ) )
return true ;
if ( ! V_146 || ! V_33 -> V_138 )
return false ;
if ( F_55 ( V_95 , V_33 -> V_108 ) )
return false ;
if ( ! F_48 ( V_147 , V_33 -> V_138 ) )
return true ;
if ( ! F_55 ( V_95 , V_33 -> V_138 ) )
return false ;
return ! F_48 ( V_147 , V_95 - V_33 -> V_148 ) ;
}
static void F_79 ( struct V_1 * V_2 , int * V_149 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_150 = 0 ;
T_1 V_151 = V_33 -> V_110 ;
T_1 V_152 = F_80 ( V_33 ) ;
if ( ! F_66 ( V_33 ) || ! V_33 -> V_153 ||
! F_55 ( V_152 , V_33 -> V_154 ) ||
V_6 -> V_135 != V_155 )
return;
F_81 (skb, sk) {
T_1 V_156 = F_18 ( V_4 ) -> V_156 ;
if ( V_4 == F_82 ( V_2 ) )
break;
if ( V_150 == V_33 -> V_153 )
break;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) )
continue;
if ( ! ( F_18 ( V_4 ) -> V_143 & V_157 ) )
continue;
if ( F_55 ( V_152 , V_156 ) ) {
F_18 ( V_4 ) -> V_143 &= ~ V_157 ;
V_33 -> V_153 -= F_76 ( V_4 ) ;
* V_149 |= V_158 ;
F_77 ( V_33 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_159 ) ;
} else {
if ( F_48 ( V_156 , V_151 ) )
V_151 = V_156 ;
V_150 += F_76 ( V_4 ) ;
}
}
if ( V_33 -> V_153 )
V_33 -> V_154 = V_151 ;
}
static bool F_83 ( struct V_1 * V_2 , const struct V_3 * V_160 ,
struct V_161 * V_162 , int V_163 ,
T_1 V_164 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_165 = F_84 ( & V_162 [ 0 ] . V_147 ) ;
T_1 V_166 = F_84 ( & V_162 [ 0 ] . V_95 ) ;
bool V_167 = false ;
if ( F_48 ( V_165 , F_18 ( V_160 ) -> V_156 ) ) {
V_167 = true ;
F_67 ( V_33 ) ;
F_70 ( F_71 ( V_2 ) , V_168 ) ;
} else if ( V_163 > 1 ) {
T_1 V_169 = F_84 ( & V_162 [ 1 ] . V_95 ) ;
T_1 V_170 = F_84 ( & V_162 [ 1 ] . V_147 ) ;
if ( ! F_55 ( V_166 , V_169 ) &&
! F_48 ( V_165 , V_170 ) ) {
V_167 = true ;
F_67 ( V_33 ) ;
F_70 ( F_71 ( V_2 ) ,
V_171 ) ;
}
}
if ( V_167 && V_33 -> V_138 && V_33 -> V_139 > 0 &&
! F_55 ( V_166 , V_164 ) &&
F_55 ( V_166 , V_33 -> V_138 ) )
V_33 -> V_139 -- ;
return V_167 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_147 , T_1 V_95 )
{
int V_172 ;
bool V_173 ;
unsigned int V_174 ;
unsigned int V_69 ;
V_173 = ! F_55 ( V_147 , F_18 ( V_4 ) -> V_80 ) &&
! F_48 ( V_95 , F_18 ( V_4 ) -> V_95 ) ;
if ( F_76 ( V_4 ) > 1 && ! V_173 &&
F_55 ( F_18 ( V_4 ) -> V_95 , V_147 ) ) {
V_69 = F_86 ( V_4 ) ;
V_173 = ! F_55 ( V_147 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! V_173 ) {
V_174 = V_147 - F_18 ( V_4 ) -> V_80 ;
if ( V_174 < V_69 )
V_174 = V_69 ;
} else {
V_174 = V_95 - F_18 ( V_4 ) -> V_80 ;
if ( V_174 < V_69 )
return - V_175 ;
}
if ( V_174 > V_69 ) {
unsigned int V_176 = ( V_174 / V_69 ) * V_69 ;
if ( ! V_173 && V_176 < V_174 ) {
V_176 += V_69 ;
if ( V_176 >= V_4 -> V_10 )
return 0 ;
}
V_174 = V_176 ;
}
V_172 = F_87 ( V_2 , V_4 , V_174 , V_69 , V_177 ) ;
if ( V_172 < 0 )
return V_172 ;
}
return V_173 ;
}
static T_4 F_88 ( struct V_1 * V_2 ,
struct V_178 * V_179 , T_4 V_143 ,
T_1 V_147 , T_1 V_95 ,
int V_167 , int V_180 ,
const struct V_181 * V_182 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_183 = V_179 -> V_183 ;
if ( V_167 && ( V_143 & V_184 ) ) {
if ( V_33 -> V_138 && V_33 -> V_139 > 0 &&
F_55 ( V_95 , V_33 -> V_138 ) )
V_33 -> V_139 -- ;
if ( V_143 & V_145 )
V_179 -> V_185 = F_9 ( V_183 , V_179 -> V_185 ) ;
}
if ( ! F_55 ( V_95 , V_33 -> V_108 ) )
return V_143 ;
if ( ! ( V_143 & V_145 ) ) {
if ( V_143 & V_157 ) {
if ( V_143 & V_144 ) {
V_143 &= ~ ( V_144 | V_157 ) ;
V_33 -> V_141 -= V_180 ;
V_33 -> V_153 -= V_180 ;
}
} else {
if ( ! ( V_143 & V_184 ) ) {
if ( F_48 ( V_147 ,
F_80 ( V_33 ) ) )
V_179 -> V_185 = F_9 ( V_183 ,
V_179 -> V_185 ) ;
if ( ! F_55 ( V_95 , V_33 -> V_186 ) )
V_179 -> V_149 |= V_187 ;
if ( V_179 -> V_188 . V_189 == 0 )
V_179 -> V_188 = * V_182 ;
V_179 -> V_190 = * V_182 ;
}
if ( V_143 & V_144 ) {
V_143 &= ~ V_144 ;
V_33 -> V_141 -= V_180 ;
}
}
V_143 |= V_145 ;
V_179 -> V_149 |= V_191 ;
V_33 -> V_137 += V_180 ;
V_183 += V_180 ;
if ( ! F_66 ( V_33 ) && V_33 -> V_122 &&
F_48 ( V_147 , F_18 ( V_33 -> V_122 ) -> V_80 ) )
V_33 -> V_192 += V_180 ;
if ( V_183 > V_33 -> V_136 )
V_33 -> V_136 = V_183 ;
}
if ( V_167 && ( V_143 & V_157 ) ) {
V_143 &= ~ V_157 ;
V_33 -> V_153 -= V_180 ;
}
return V_143 ;
}
static bool F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_178 * V_179 ,
unsigned int V_180 , int V_193 , int V_69 ,
bool V_167 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_194 = F_90 ( V_2 , V_4 ) ;
T_1 V_147 = F_18 ( V_4 ) -> V_80 ;
T_1 V_95 = V_147 + V_193 ;
F_91 ( ! V_180 ) ;
F_88 ( V_2 , V_179 , F_18 ( V_4 ) -> V_143 ,
V_147 , V_95 , V_167 , V_180 ,
& V_4 -> V_181 ) ;
if ( V_4 == V_33 -> V_122 )
V_33 -> V_192 += V_180 ;
F_18 ( V_194 ) -> V_95 += V_193 ;
F_18 ( V_4 ) -> V_80 += V_193 ;
F_92 ( V_194 , V_180 ) ;
F_91 ( F_76 ( V_4 ) < V_180 ) ;
F_92 ( V_4 , - V_180 ) ;
if ( ! F_18 ( V_194 ) -> V_195 )
F_18 ( V_194 ) -> V_195 = V_69 ;
if ( F_76 ( V_4 ) <= 1 )
F_18 ( V_4 ) -> V_195 = 0 ;
F_18 ( V_194 ) -> V_143 |= ( F_18 ( V_4 ) -> V_143 & V_196 ) ;
if ( V_4 -> V_10 > 0 ) {
F_91 ( ! F_76 ( V_4 ) ) ;
F_70 ( F_71 ( V_2 ) , V_197 ) ;
return false ;
}
if ( V_4 == V_33 -> V_140 )
V_33 -> V_140 = V_194 ;
if ( V_4 == V_33 -> V_122 ) {
V_33 -> V_122 = V_194 ;
V_33 -> V_192 -= F_76 ( V_194 ) ;
}
F_18 ( V_194 ) -> V_198 |= F_18 ( V_4 ) -> V_198 ;
if ( F_18 ( V_4 ) -> V_198 & V_199 )
F_18 ( V_194 ) -> V_95 ++ ;
if ( V_4 == F_93 ( V_2 ) )
F_94 ( V_2 , V_4 ) ;
F_95 ( V_4 , V_2 ) ;
F_96 ( V_2 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_200 ) ;
return true ;
}
static int F_97 ( const struct V_3 * V_4 )
{
return F_76 ( V_4 ) == 1 ? V_4 -> V_10 : F_86 ( V_4 ) ;
}
static int F_98 ( const struct V_3 * V_4 )
{
return ! F_99 ( V_4 ) && F_100 ( V_4 ) ;
}
static struct V_3 * F_101 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_178 * V_179 ,
T_1 V_147 , T_1 V_95 ,
bool V_167 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_194 ;
int V_69 ;
int V_180 = 0 ;
int V_10 ;
int V_173 ;
if ( ! F_102 ( V_2 ) )
goto V_201;
if ( ! V_167 &&
( F_18 ( V_4 ) -> V_143 & ( V_144 | V_157 ) ) == V_157 )
goto V_201;
if ( ! F_98 ( V_4 ) )
goto V_201;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) )
goto V_201;
if ( F_103 ( V_4 == F_104 ( V_2 ) ) )
goto V_201;
V_194 = F_90 ( V_2 , V_4 ) ;
if ( ( F_18 ( V_194 ) -> V_143 & V_202 ) != V_145 )
goto V_201;
V_173 = ! F_55 ( V_147 , F_18 ( V_4 ) -> V_80 ) &&
! F_48 ( V_95 , F_18 ( V_4 ) -> V_95 ) ;
if ( V_173 ) {
V_10 = V_4 -> V_10 ;
V_180 = F_76 ( V_4 ) ;
V_69 = F_97 ( V_4 ) ;
if ( V_69 != F_97 ( V_194 ) )
goto V_201;
} else {
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_147 ) )
goto V_203;
if ( F_76 ( V_4 ) <= 1 )
goto V_203;
V_173 = ! F_55 ( V_147 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! V_173 ) {
goto V_201;
}
V_10 = V_95 - F_18 ( V_4 ) -> V_80 ;
F_91 ( V_10 < 0 ) ;
F_91 ( V_10 > V_4 -> V_10 ) ;
V_69 = F_86 ( V_4 ) ;
if ( V_69 != F_97 ( V_194 ) )
goto V_201;
if ( V_10 == V_69 ) {
V_180 = 1 ;
} else if ( V_10 < V_69 ) {
goto V_203;
} else {
V_180 = V_10 / V_69 ;
V_10 = V_180 * V_69 ;
}
}
if ( ! F_55 ( F_18 ( V_4 ) -> V_80 + V_10 , V_33 -> V_108 ) )
goto V_201;
if ( ! F_105 ( V_194 , V_4 , V_10 ) )
goto V_201;
if ( ! F_89 ( V_2 , V_4 , V_179 , V_180 , V_10 , V_69 , V_167 ) )
goto V_204;
if ( V_194 == F_106 ( V_2 ) )
goto V_204;
V_4 = F_107 ( V_2 , V_194 ) ;
if ( ! F_98 ( V_4 ) ||
( V_4 == F_82 ( V_2 ) ) ||
( ( F_18 ( V_4 ) -> V_143 & V_202 ) != V_145 ) ||
( V_69 != F_97 ( V_4 ) ) )
goto V_204;
V_10 = V_4 -> V_10 ;
if ( F_105 ( V_194 , V_4 , V_10 ) ) {
V_180 += F_76 ( V_4 ) ;
F_89 ( V_2 , V_4 , V_179 , F_76 ( V_4 ) , V_10 , V_69 , 0 ) ;
}
V_204:
V_179 -> V_183 += V_180 ;
return V_194 ;
V_203:
return V_4 ;
V_201:
F_70 ( F_71 ( V_2 ) , V_205 ) ;
return NULL ;
}
static struct V_3 * F_108 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_206 * V_207 ,
struct V_178 * V_179 ,
T_1 V_147 , T_1 V_95 ,
bool V_208 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_209 ;
F_109 (skb, sk) {
int V_173 = 0 ;
bool V_167 = V_208 ;
if ( V_4 == F_82 ( V_2 ) )
break;
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_95 ) )
break;
if ( V_207 &&
F_48 ( F_18 ( V_4 ) -> V_80 , V_207 -> V_95 ) ) {
V_173 = F_85 ( V_2 , V_4 ,
V_207 -> V_147 ,
V_207 -> V_95 ) ;
if ( V_173 > 0 )
V_167 = true ;
}
if ( V_173 <= 0 ) {
V_209 = F_101 ( V_2 , V_4 , V_179 ,
V_147 , V_95 , V_167 ) ;
if ( V_209 ) {
if ( V_209 != V_4 ) {
V_4 = V_209 ;
continue;
}
V_173 = 0 ;
} else {
V_173 = F_85 ( V_2 , V_4 ,
V_147 ,
V_95 ) ;
}
}
if ( F_103 ( V_173 < 0 ) )
break;
if ( V_173 ) {
F_18 ( V_4 ) -> V_143 =
F_88 ( V_2 ,
V_179 ,
F_18 ( V_4 ) -> V_143 ,
F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ,
V_167 ,
F_76 ( V_4 ) ,
& V_4 -> V_181 ) ;
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 ,
F_80 ( V_33 ) ) )
F_94 ( V_2 , V_4 ) ;
}
V_179 -> V_183 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_110 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_178 * V_179 ,
T_1 V_210 )
{
F_109 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_210 ) )
break;
V_179 -> V_183 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_111 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_206 * V_207 ,
struct V_178 * V_179 ,
T_1 V_210 )
{
if ( ! V_207 )
return V_4 ;
if ( F_48 ( V_207 -> V_147 , V_210 ) ) {
V_4 = F_110 ( V_4 , V_2 , V_179 , V_207 -> V_147 ) ;
V_4 = F_108 ( V_4 , V_2 , NULL , V_179 ,
V_207 -> V_147 , V_207 -> V_95 ,
1 ) ;
}
return V_4 ;
}
static int F_112 ( const struct V_32 * V_33 , const struct V_206 * V_211 )
{
return V_211 < V_33 -> V_212 + F_113 ( V_33 -> V_212 ) ;
}
static int
F_114 ( struct V_1 * V_2 , const struct V_3 * V_160 ,
T_1 V_164 , struct V_178 * V_179 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
const unsigned char * V_213 = ( F_4 ( V_160 ) +
F_18 ( V_160 ) -> V_143 ) ;
struct V_161 * V_214 = (struct V_161 * ) ( V_213 + 2 ) ;
struct V_206 V_162 [ V_215 ] ;
struct V_206 * V_211 ;
struct V_3 * V_4 ;
int V_163 = F_9 ( V_215 , ( V_213 [ 1 ] - V_216 ) >> 3 ) ;
int V_217 ;
bool V_218 = false ;
int V_219 , V_220 ;
int V_221 ;
V_179 -> V_149 = 0 ;
V_179 -> V_185 = V_33 -> V_116 ;
if ( ! V_33 -> V_137 ) {
if ( F_115 ( V_33 -> V_136 ) )
V_33 -> V_136 = 0 ;
F_116 ( V_2 ) ;
}
V_218 = F_83 ( V_2 , V_160 , V_214 ,
V_163 , V_164 ) ;
if ( V_218 )
V_179 -> V_149 |= V_222 ;
if ( F_48 ( F_18 ( V_160 ) -> V_156 , V_164 - V_33 -> V_148 ) )
return 0 ;
if ( ! V_33 -> V_116 )
goto V_204;
V_217 = 0 ;
V_221 = 0 ;
for ( V_219 = 0 ; V_219 < V_163 ; V_219 ++ ) {
bool V_167 = ! V_219 && V_218 ;
V_162 [ V_217 ] . V_147 = F_84 ( & V_214 [ V_219 ] . V_147 ) ;
V_162 [ V_217 ] . V_95 = F_84 ( & V_214 [ V_219 ] . V_95 ) ;
if ( ! F_78 ( V_33 , V_167 ,
V_162 [ V_217 ] . V_147 ,
V_162 [ V_217 ] . V_95 ) ) {
int V_128 ;
if ( V_167 ) {
if ( ! V_33 -> V_138 )
V_128 = V_223 ;
else
V_128 = V_224 ;
} else {
if ( ( F_18 ( V_160 ) -> V_156 != V_33 -> V_108 ) &&
! F_55 ( V_162 [ V_217 ] . V_95 , V_33 -> V_108 ) )
continue;
V_128 = V_225 ;
}
F_70 ( F_71 ( V_2 ) , V_128 ) ;
if ( V_219 == 0 )
V_221 = - 1 ;
continue;
}
if ( ! F_55 ( V_162 [ V_217 ] . V_95 , V_164 ) )
continue;
V_217 ++ ;
}
for ( V_219 = V_217 - 1 ; V_219 > 0 ; V_219 -- ) {
for ( V_220 = 0 ; V_220 < V_219 ; V_220 ++ ) {
if ( F_55 ( V_162 [ V_220 ] . V_147 , V_162 [ V_220 + 1 ] . V_147 ) ) {
F_117 ( V_162 [ V_220 ] , V_162 [ V_220 + 1 ] ) ;
if ( V_220 == V_221 )
V_221 = V_220 + 1 ;
}
}
}
V_4 = F_104 ( V_2 ) ;
V_179 -> V_183 = 0 ;
V_219 = 0 ;
if ( ! V_33 -> V_137 ) {
V_211 = V_33 -> V_212 + F_113 ( V_33 -> V_212 ) ;
} else {
V_211 = V_33 -> V_212 ;
while ( F_112 ( V_33 , V_211 ) && ! V_211 -> V_147 &&
! V_211 -> V_95 )
V_211 ++ ;
}
while ( V_219 < V_217 ) {
T_1 V_147 = V_162 [ V_219 ] . V_147 ;
T_1 V_95 = V_162 [ V_219 ] . V_95 ;
bool V_167 = ( V_218 && ( V_219 == V_221 ) ) ;
struct V_206 * V_207 = NULL ;
if ( V_218 && ( ( V_219 + 1 ) == V_221 ) )
V_207 = & V_162 [ V_219 + 1 ] ;
while ( F_112 ( V_33 , V_211 ) &&
! F_48 ( V_147 , V_211 -> V_95 ) )
V_211 ++ ;
if ( F_112 ( V_33 , V_211 ) && ! V_167 &&
F_55 ( V_95 , V_211 -> V_147 ) ) {
if ( F_48 ( V_147 , V_211 -> V_147 ) ) {
V_4 = F_110 ( V_4 , V_2 , V_179 ,
V_147 ) ;
V_4 = F_108 ( V_4 , V_2 , V_207 ,
V_179 ,
V_147 ,
V_211 -> V_147 ,
V_167 ) ;
}
if ( ! F_55 ( V_95 , V_211 -> V_95 ) )
goto V_226;
V_4 = F_111 ( V_4 , V_2 , V_207 ,
V_179 ,
V_211 -> V_95 ) ;
if ( F_80 ( V_33 ) == V_211 -> V_95 ) {
V_4 = F_93 ( V_2 ) ;
if ( ! V_4 )
break;
V_179 -> V_183 = V_33 -> V_136 ;
V_211 ++ ;
goto V_227;
}
V_4 = F_110 ( V_4 , V_2 , V_179 , V_211 -> V_95 ) ;
V_211 ++ ;
continue;
}
if ( ! F_48 ( V_147 , F_80 ( V_33 ) ) ) {
V_4 = F_93 ( V_2 ) ;
if ( ! V_4 )
break;
V_179 -> V_183 = V_33 -> V_136 ;
}
V_4 = F_110 ( V_4 , V_2 , V_179 , V_147 ) ;
V_227:
V_4 = F_108 ( V_4 , V_2 , V_207 , V_179 ,
V_147 , V_95 , V_167 ) ;
V_226:
V_219 ++ ;
}
for ( V_219 = 0 ; V_219 < F_113 ( V_33 -> V_212 ) - V_217 ; V_219 ++ ) {
V_33 -> V_212 [ V_219 ] . V_147 = 0 ;
V_33 -> V_212 [ V_219 ] . V_95 = 0 ;
}
for ( V_220 = 0 ; V_220 < V_217 ; V_220 ++ )
V_33 -> V_212 [ V_219 ++ ] = V_162 [ V_220 ] ;
if ( ( V_179 -> V_185 < V_33 -> V_136 ) &&
( ( F_2 ( V_2 ) -> V_135 != V_228 ) || V_33 -> V_138 ) )
F_68 ( V_2 , V_33 -> V_136 - V_179 -> V_185 , 0 ) ;
F_79 ( V_2 , & V_179 -> V_149 ) ;
F_118 ( V_33 ) ;
V_204:
#if V_134 > 0
F_115 ( ( int ) V_33 -> V_137 < 0 ) ;
F_115 ( ( int ) V_33 -> V_141 < 0 ) ;
F_115 ( ( int ) V_33 -> V_153 < 0 ) ;
F_115 ( ( int ) F_119 ( V_33 ) < 0 ) ;
#endif
return V_179 -> V_149 ;
}
static bool F_120 ( struct V_32 * V_33 )
{
T_1 V_229 ;
V_229 = F_39 ( V_33 -> V_141 , 1U ) ;
V_229 = F_9 ( V_229 , V_33 -> V_116 ) ;
if ( ( V_33 -> V_137 + V_229 ) > V_33 -> V_116 ) {
V_33 -> V_137 = V_33 -> V_116 - V_229 ;
return true ;
}
return false ;
}
static void F_121 ( struct V_1 * V_2 , const int V_230 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_120 ( V_33 ) )
F_68 ( V_2 , V_33 -> V_116 + V_230 , 0 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_137 ++ ;
F_121 ( V_2 , 0 ) ;
F_118 ( V_33 ) ;
}
static void F_123 ( struct V_1 * V_2 , int V_231 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_231 > 0 ) {
if ( V_231 - 1 >= V_33 -> V_137 )
V_33 -> V_137 = 0 ;
else
V_33 -> V_137 -= V_231 - 1 ;
}
F_121 ( V_2 , V_231 ) ;
F_118 ( V_33 ) ;
}
static inline void F_124 ( struct V_32 * V_33 )
{
V_33 -> V_137 = 0 ;
}
void F_125 ( struct V_32 * V_33 )
{
V_33 -> V_153 = 0 ;
V_33 -> V_141 = 0 ;
V_33 -> V_138 = 0 ;
V_33 -> V_139 = - 1 ;
V_33 -> V_136 = 0 ;
V_33 -> V_137 = 0 ;
}
static inline void F_126 ( struct V_32 * V_33 )
{
V_33 -> V_138 = V_33 -> V_108 ;
V_33 -> V_139 = V_33 -> V_153 ? : - 1 ;
}
void F_127 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_232 = V_6 -> V_135 < V_155 ;
bool V_233 ;
if ( V_6 -> V_135 <= V_234 ||
! F_55 ( V_33 -> V_186 , V_33 -> V_108 ) ||
( V_6 -> V_135 == V_228 && ! V_6 -> V_235 ) ) {
V_33 -> V_236 = F_128 ( V_2 ) ;
V_33 -> V_113 = V_6 -> V_237 -> V_238 ( V_2 ) ;
F_20 ( V_2 , V_239 ) ;
F_126 ( V_33 ) ;
}
V_33 -> V_58 = 1 ;
V_33 -> V_240 = 0 ;
V_33 -> V_83 = V_79 ;
V_33 -> V_153 = 0 ;
V_33 -> V_141 = 0 ;
if ( F_69 ( V_33 ) )
F_124 ( V_33 ) ;
V_4 = F_104 ( V_2 ) ;
V_233 = V_4 && ( F_18 ( V_4 ) -> V_143 & V_145 ) ;
if ( V_233 ) {
F_70 ( F_71 ( V_2 ) , V_241 ) ;
V_33 -> V_137 = 0 ;
V_33 -> V_136 = 0 ;
}
F_129 ( V_33 ) ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
F_18 ( V_4 ) -> V_143 &= ( ~ V_202 ) | V_145 ;
if ( ! ( F_18 ( V_4 ) -> V_143 & V_145 ) || V_233 ) {
F_18 ( V_4 ) -> V_143 &= ~ V_145 ;
F_18 ( V_4 ) -> V_143 |= V_144 ;
V_33 -> V_141 += F_76 ( V_4 ) ;
V_33 -> V_142 = F_18 ( V_4 ) -> V_95 ;
}
}
F_118 ( V_33 ) ;
if ( V_6 -> V_135 <= V_234 &&
V_33 -> V_137 >= V_242 )
V_33 -> V_59 = F_45 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_130 ( V_2 , V_228 ) ;
V_33 -> V_186 = V_33 -> V_110 ;
F_14 ( V_33 ) ;
V_33 -> V_243 = V_244 &&
( V_232 || V_6 -> V_235 ) &&
! F_2 ( V_2 ) -> V_245 . V_246 ;
}
static bool F_131 ( struct V_1 * V_2 , int V_149 )
{
if ( V_149 & V_247 ) {
struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned long V_248 = F_39 ( F_132 ( V_33 -> V_104 >> 4 ) ,
F_133 ( 10 ) ) ;
F_134 ( V_2 , V_249 ,
V_248 , V_250 ) ;
return true ;
}
return false ;
}
static inline int F_135 ( const struct V_32 * V_33 )
{
return F_69 ( V_33 ) ? V_33 -> V_137 + 1 : V_33 -> V_136 ;
}
static inline int F_136 ( const struct V_32 * V_33 )
{
return F_66 ( V_33 ) ? V_33 -> V_136 : V_33 -> V_137 + 1 ;
}
static bool F_137 ( struct V_1 * V_2 , int V_149 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
unsigned long V_248 ;
if ( V_251 < 2 || V_251 > 3 ||
( V_149 & V_252 ) || ! V_33 -> V_104 )
return false ;
V_248 = F_39 ( F_132 ( V_33 -> V_104 >> 5 ) ,
F_133 ( 2 ) ) ;
if ( ! F_138 ( F_2 ( V_2 ) -> V_253 , ( V_254 + V_248 ) ) )
return false ;
F_134 ( V_2 , V_255 , V_248 ,
V_250 ) ;
return true ;
}
static bool F_139 ( struct V_1 * V_2 , int V_149 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_3 V_116 ;
if ( V_33 -> V_141 )
return true ;
if ( F_136 ( V_33 ) > V_33 -> V_59 )
return true ;
V_116 = V_33 -> V_116 ;
if ( V_116 <= V_33 -> V_59 &&
V_33 -> V_137 >= F_26 ( T_3 , V_116 / 2 , V_242 ) &&
! F_140 ( V_2 ) ) {
return true ;
}
if ( ( V_33 -> V_256 || V_257 ) &&
F_141 ( V_33 ) && F_136 ( V_33 ) > 1 &&
F_142 ( V_33 ) && ! F_82 ( V_2 ) )
return true ;
if ( V_33 -> V_258 && ! V_33 -> V_153 && V_33 -> V_137 &&
( V_33 -> V_116 >= ( V_33 -> V_137 + 1 ) && V_33 -> V_116 < 4 ) &&
! F_140 ( V_2 ) )
return ! F_137 ( V_2 , V_149 ) ;
return false ;
}
static void F_143 ( struct V_1 * V_2 , int V_259 , int V_260 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_150 , V_261 ;
int V_172 ;
unsigned int V_69 ;
const T_1 V_262 = F_142 ( V_33 ) ? V_33 -> V_110 : V_33 -> V_186 ;
F_115 ( V_259 > V_33 -> V_116 ) ;
if ( V_33 -> V_122 ) {
V_4 = V_33 -> V_122 ;
V_150 = V_33 -> V_192 ;
if ( V_260 && V_4 != F_104 ( V_2 ) )
return;
} else {
V_4 = F_104 ( V_2 ) ;
V_150 = 0 ;
}
F_109 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
V_33 -> V_122 = V_4 ;
V_33 -> V_192 = V_150 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_262 ) )
break;
V_261 = V_150 ;
if ( F_66 ( V_33 ) || F_69 ( V_33 ) ||
( F_18 ( V_4 ) -> V_143 & V_145 ) )
V_150 += F_76 ( V_4 ) ;
if ( V_150 > V_259 ) {
if ( ( F_142 ( V_33 ) && ! F_66 ( V_33 ) ) ||
( F_18 ( V_4 ) -> V_143 & V_145 ) ||
( V_261 >= V_259 ) )
break;
V_69 = F_86 ( V_4 ) ;
V_172 = F_87 ( V_2 , V_4 , ( V_259 - V_261 ) * V_69 ,
V_69 , V_177 ) ;
if ( V_172 < 0 )
break;
V_150 = V_259 ;
}
F_75 ( V_33 , V_4 ) ;
if ( V_260 )
break;
}
F_118 ( V_33 ) ;
}
static void F_144 ( struct V_1 * V_2 , int V_263 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_69 ( V_33 ) ) {
F_143 ( V_2 , 1 , 1 ) ;
} else if ( F_66 ( V_33 ) ) {
int V_264 = V_33 -> V_136 - V_33 -> V_59 ;
if ( V_264 <= 0 )
V_264 = 1 ;
F_143 ( V_2 , V_264 , 0 ) ;
} else {
int V_265 = V_33 -> V_137 - V_33 -> V_59 ;
if ( V_265 >= 0 )
F_143 ( V_2 , V_265 , 0 ) ;
else if ( V_263 )
F_143 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_145 ( struct V_32 * V_33 )
{
V_33 -> V_58 = F_9 ( V_33 -> V_58 ,
F_119 ( V_33 ) + F_146 ( V_33 ) ) ;
V_33 -> V_83 = V_79 ;
}
static inline bool F_147 ( const struct V_32 * V_33 )
{
return ! V_33 -> V_266 ||
( V_33 -> V_52 . V_267 && V_33 -> V_52 . V_94 &&
F_48 ( V_33 -> V_52 . V_94 , V_33 -> V_266 ) ) ;
}
static bool F_148 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_33 -> V_153 )
return true ;
V_4 = F_104 ( V_2 ) ;
if ( F_103 ( V_4 && F_18 ( V_4 ) -> V_143 & V_196 ) )
return true ;
return false ;
}
static void F_149 ( struct V_1 * V_2 , const char * V_268 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_269 * V_270 = F_150 ( V_2 ) ;
if ( V_2 -> V_271 == V_272 ) {
F_72 ( L_2 ,
V_268 ,
& V_270 -> V_273 , F_151 ( V_270 -> V_274 ) ,
V_33 -> V_58 , F_152 ( V_33 ) ,
V_33 -> V_113 , V_33 -> V_236 ,
V_33 -> V_116 ) ;
}
#if F_153 ( V_275 )
else if ( V_2 -> V_271 == V_276 ) {
struct V_277 * V_278 = F_154 ( V_2 ) ;
F_72 ( L_3 ,
V_268 ,
& V_278 -> V_279 , F_151 ( V_270 -> V_274 ) ,
V_33 -> V_58 , F_152 ( V_33 ) ,
V_33 -> V_113 , V_33 -> V_236 ,
V_33 -> V_116 ) ;
}
#endif
}
static void F_155 ( struct V_1 * V_2 , bool V_280 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_280 ) {
struct V_3 * V_4 ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
F_18 ( V_4 ) -> V_143 &= ~ V_144 ;
}
V_33 -> V_141 = 0 ;
F_129 ( V_33 ) ;
}
if ( V_33 -> V_236 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_237 -> V_281 )
V_33 -> V_58 = V_6 -> V_237 -> V_281 ( V_2 ) ;
else
V_33 -> V_58 = F_39 ( V_33 -> V_58 , V_33 -> V_113 << 1 ) ;
if ( V_33 -> V_236 > V_33 -> V_113 ) {
V_33 -> V_113 = V_33 -> V_236 ;
F_16 ( V_33 ) ;
}
} else {
V_33 -> V_58 = F_39 ( V_33 -> V_58 , V_33 -> V_113 ) ;
}
V_33 -> V_83 = V_79 ;
V_33 -> V_138 = 0 ;
}
static inline bool F_156 ( const struct V_32 * V_33 )
{
return V_33 -> V_138 && ( ! V_33 -> V_139 || F_147 ( V_33 ) ) ;
}
static bool F_157 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_156 ( V_33 ) ) {
int V_128 ;
F_149 ( V_2 , F_2 ( V_2 ) -> V_135 == V_228 ? L_4 : L_5 ) ;
F_155 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_135 == V_228 )
V_128 = V_282 ;
else
V_128 = V_283 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
}
if ( V_33 -> V_108 == V_33 -> V_186 && F_69 ( V_33 ) ) {
F_145 ( V_33 ) ;
if ( ! F_148 ( V_2 ) )
V_33 -> V_266 = 0 ;
return true ;
}
F_130 ( V_2 , V_284 ) ;
return false ;
}
static bool F_158 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && ! V_33 -> V_139 ) {
F_149 ( V_2 , L_6 ) ;
F_155 ( V_2 , false ) ;
F_70 ( F_71 ( V_2 ) , V_285 ) ;
return true ;
}
return false ;
}
static bool F_159 ( struct V_1 * V_2 , bool V_286 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_286 || F_156 ( V_33 ) ) {
F_155 ( V_2 , true ) ;
F_149 ( V_2 , L_7 ) ;
F_70 ( F_71 ( V_2 ) , V_282 ) ;
if ( V_286 )
F_70 ( F_71 ( V_2 ) ,
V_287 ) ;
F_2 ( V_2 ) -> V_235 = 0 ;
if ( V_286 || F_142 ( V_33 ) )
F_130 ( V_2 , V_284 ) ;
return true ;
}
return false ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_186 = V_33 -> V_110 ;
V_33 -> V_288 = 0 ;
V_33 -> V_240 = 0 ;
V_33 -> V_289 = V_33 -> V_58 ;
V_33 -> V_290 = 0 ;
V_33 -> V_291 = 0 ;
V_33 -> V_113 = F_2 ( V_2 ) -> V_237 -> V_238 ( V_2 ) ;
F_14 ( V_33 ) ;
}
static void F_161 ( struct V_1 * V_2 , const int V_292 ,
int V_263 , int V_149 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_293 = 0 ;
int V_294 = V_33 -> V_113 - F_119 ( V_33 ) ;
int V_295 = V_292 -
( V_33 -> V_116 - V_33 -> V_137 ) ;
V_33 -> V_290 += V_295 ;
if ( V_294 < 0 ) {
T_2 V_296 = ( T_2 ) V_33 -> V_113 * V_33 -> V_290 +
V_33 -> V_289 - 1 ;
V_293 = F_162 ( V_296 , V_33 -> V_289 ) - V_33 -> V_291 ;
} else if ( ( V_149 & V_297 ) &&
! ( V_149 & V_158 ) ) {
V_293 = F_45 ( int , V_294 ,
F_26 ( int , V_33 -> V_290 - V_33 -> V_291 ,
V_295 ) + 1 ) ;
} else {
V_293 = F_9 ( V_294 , V_295 ) ;
}
V_293 = F_39 ( V_293 , ( V_263 ? 1 : 0 ) ) ;
V_33 -> V_58 = F_119 ( V_33 ) + V_293 ;
}
static inline void F_163 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 == V_298 ||
( V_33 -> V_138 && V_33 -> V_113 < V_299 ) ) {
V_33 -> V_58 = V_33 -> V_113 ;
V_33 -> V_83 = V_79 ;
}
F_20 ( V_2 , V_300 ) ;
}
void F_164 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
V_33 -> V_236 = 0 ;
if ( F_2 ( V_2 ) -> V_135 < V_298 ) {
V_33 -> V_138 = 0 ;
F_160 ( V_2 ) ;
F_130 ( V_2 , V_298 ) ;
}
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_179 = V_284 ;
if ( F_152 ( V_33 ) || F_148 ( V_2 ) )
V_179 = V_234 ;
if ( F_2 ( V_2 ) -> V_135 != V_179 ) {
F_130 ( V_2 , V_179 ) ;
V_33 -> V_186 = V_33 -> V_110 ;
}
}
static void F_166 ( struct V_1 * V_2 , int V_149 , const int V_292 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_118 ( V_33 ) ;
if ( ! F_148 ( V_2 ) )
V_33 -> V_266 = 0 ;
if ( V_149 & V_252 )
F_164 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_135 != V_298 ) {
F_165 ( V_2 ) ;
} else {
F_161 ( V_2 , V_292 , 0 , V_149 ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_245 . V_301 = V_6 -> V_245 . V_246 - 1 ;
V_6 -> V_245 . V_246 = 0 ;
F_70 ( F_71 ( V_2 ) , V_302 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_33 -> V_236 = F_128 ( V_2 ) ;
V_33 -> V_58 = V_33 -> V_58 *
F_169 ( V_2 , V_33 -> V_54 ) /
V_6 -> V_245 . V_246 ;
V_33 -> V_240 = 0 ;
V_33 -> V_83 = V_79 ;
V_33 -> V_113 = F_128 ( V_2 ) ;
V_6 -> V_245 . V_303 = V_6 -> V_245 . V_246 ;
V_6 -> V_245 . V_246 = 0 ;
F_170 ( V_2 , V_6 -> V_304 ) ;
F_70 ( F_71 ( V_2 ) , V_305 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_69 = F_172 ( V_2 ) ;
T_1 V_306 = V_33 -> V_141 ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_97 ( V_4 ) > V_69 &&
! ( F_18 ( V_4 ) -> V_143 & V_145 ) ) {
if ( F_18 ( V_4 ) -> V_143 & V_157 ) {
F_18 ( V_4 ) -> V_143 &= ~ V_157 ;
V_33 -> V_153 -= F_76 ( V_4 ) ;
}
F_77 ( V_33 , V_4 ) ;
}
}
F_173 ( V_33 ) ;
if ( V_306 == V_33 -> V_141 )
return;
if ( F_69 ( V_33 ) )
F_120 ( V_33 ) ;
F_118 ( V_33 ) ;
if ( V_6 -> V_135 != V_228 ) {
V_33 -> V_186 = V_33 -> V_110 ;
V_33 -> V_113 = F_128 ( V_2 ) ;
V_33 -> V_236 = 0 ;
V_33 -> V_138 = 0 ;
F_130 ( V_2 , V_228 ) ;
}
F_174 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 , bool V_307 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_128 ;
if ( F_69 ( V_33 ) )
V_128 = V_308 ;
else
V_128 = V_309 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_236 = 0 ;
F_126 ( V_33 ) ;
if ( ! F_176 ( V_2 ) ) {
if ( ! V_307 )
V_33 -> V_236 = F_128 ( V_2 ) ;
F_160 ( V_2 ) ;
}
F_130 ( V_2 , V_155 ) ;
}
static void F_177 ( struct V_1 * V_2 , int V_149 , bool V_310 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_311 = ! F_48 ( V_33 -> V_108 , V_33 -> V_186 ) ;
if ( ( V_149 & V_312 ) &&
F_159 ( V_2 , false ) )
return;
if ( V_33 -> V_243 ) {
if ( ( V_149 & V_187 ) &&
F_159 ( V_2 , true ) )
return;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_186 ) ) {
if ( V_149 & V_191 || V_310 )
V_33 -> V_243 = 0 ;
} else if ( V_149 & V_312 && ! V_311 ) {
V_33 -> V_186 = V_33 -> V_110 ;
F_178 ( V_2 , F_172 ( V_2 ) ,
V_313 ) ;
if ( F_55 ( V_33 -> V_110 , V_33 -> V_186 ) )
return;
V_33 -> V_243 = 0 ;
}
}
if ( V_311 ) {
F_157 ( V_2 ) ;
return;
}
if ( F_69 ( V_33 ) ) {
if ( F_55 ( V_33 -> V_110 , V_33 -> V_186 ) && V_310 )
F_122 ( V_2 ) ;
else if ( V_149 & V_312 )
F_124 ( V_33 ) ;
}
F_174 ( V_2 ) ;
}
static bool F_179 ( struct V_1 * V_2 , const int V_231 ,
const int V_292 , int V_149 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_138 && F_147 ( V_33 ) ) {
F_68 ( V_2 , F_135 ( V_33 ) + V_231 , 1 ) ;
if ( V_33 -> V_153 ) {
F_161 ( V_2 , V_292 , 0 , V_149 ) ;
return true ;
}
if ( ! F_148 ( V_2 ) )
V_33 -> V_266 = 0 ;
F_149 ( V_2 , L_8 ) ;
F_155 ( V_2 , true ) ;
F_70 ( F_71 ( V_2 ) , V_314 ) ;
F_165 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_180 ( struct V_1 * V_2 , const int V_231 ,
const int V_292 ,
bool V_310 , int V_149 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_315 = V_310 || ( ( V_149 & V_191 ) &&
( F_135 ( V_33 ) > V_33 -> V_59 ) ) ;
int V_263 = 0 ;
if ( F_115 ( ! V_33 -> V_116 && V_33 -> V_137 ) )
V_33 -> V_137 = 0 ;
if ( F_115 ( ! V_33 -> V_137 && V_33 -> V_136 ) )
V_33 -> V_136 = 0 ;
if ( V_149 & V_252 )
V_33 -> V_236 = 0 ;
if ( F_131 ( V_2 , V_149 ) )
return;
F_118 ( V_33 ) ;
if ( V_6 -> V_135 == V_284 ) {
F_115 ( V_33 -> V_153 != 0 ) ;
V_33 -> V_266 = 0 ;
} else if ( ! F_48 ( V_33 -> V_108 , V_33 -> V_186 ) ) {
switch ( V_6 -> V_135 ) {
case V_298 :
if ( V_33 -> V_108 != V_33 -> V_186 ) {
F_163 ( V_2 ) ;
F_130 ( V_2 , V_284 ) ;
}
break;
case V_155 :
if ( F_69 ( V_33 ) )
F_124 ( V_33 ) ;
if ( F_157 ( V_2 ) )
return;
F_163 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_135 ) {
case V_155 :
if ( ! ( V_149 & V_312 ) ) {
if ( F_69 ( V_33 ) && V_310 )
F_122 ( V_2 ) ;
} else {
if ( F_179 ( V_2 , V_231 , V_292 , V_149 ) )
return;
V_315 = F_69 ( V_33 ) ||
F_135 ( V_33 ) > V_33 -> V_59 ;
}
if ( F_158 ( V_2 ) ) {
F_165 ( V_2 ) ;
return;
}
break;
case V_228 :
F_177 ( V_2 , V_149 , V_310 ) ;
if ( V_6 -> V_135 != V_284 &&
! ( V_149 & V_158 ) )
return;
default:
if ( F_69 ( V_33 ) ) {
if ( V_149 & V_312 )
F_124 ( V_33 ) ;
if ( V_310 )
F_122 ( V_2 ) ;
}
if ( V_6 -> V_135 <= V_234 )
F_158 ( V_2 ) ;
if ( ! F_139 ( V_2 , V_149 ) ) {
F_166 ( V_2 , V_149 , V_292 ) ;
return;
}
if ( V_6 -> V_135 < V_298 &&
V_6 -> V_245 . V_246 &&
V_33 -> V_108 == V_33 -> V_316 . V_317 ) {
F_167 ( V_2 ) ;
V_33 -> V_58 ++ ;
F_171 ( V_2 ) ;
return;
}
F_175 ( V_2 , ( V_149 & V_252 ) ) ;
V_263 = 1 ;
}
if ( V_315 )
F_144 ( V_2 , V_263 ) ;
F_161 ( V_2 , V_292 , V_263 , V_149 ) ;
F_174 ( V_2 ) ;
}
static inline bool F_181 ( struct V_1 * V_2 , const int V_149 ,
long V_318 , long V_319 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_149 & V_297 )
V_318 = - 1L ;
if ( V_318 < 0 )
V_318 = V_319 ;
if ( V_318 < 0 && V_33 -> V_52 . V_267 && V_33 -> V_52 . V_94 &&
V_149 & V_320 )
V_318 = F_182 ( V_79 - V_33 -> V_52 . V_94 ) ;
if ( V_318 < 0 )
return false ;
F_54 ( V_2 , V_318 ) ;
F_61 ( V_2 ) ;
F_2 ( V_2 ) -> V_321 = 0 ;
return true ;
}
static void F_183 ( struct V_1 * V_2 , const T_1 V_322 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
long V_318 = - 1L ;
if ( V_322 && ! V_33 -> V_323 )
V_318 = F_182 ( V_79 - V_322 ) ;
if ( ! V_33 -> V_104 )
F_181 ( V_2 , V_324 , V_318 , - 1L ) ;
}
static void F_184 ( struct V_1 * V_2 , T_1 V_325 , T_1 V_231 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_237 -> V_326 ( V_2 , V_325 , V_231 ) ;
F_7 ( V_2 ) -> V_83 = V_79 ;
}
void F_185 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_33 -> V_327 )
return;
if ( ! V_33 -> V_116 ) {
F_186 ( V_2 , V_249 ) ;
} else {
T_1 V_328 = F_2 ( V_2 ) -> V_101 ;
if ( V_6 -> V_329 == V_255 ||
V_6 -> V_329 == V_330 ) {
struct V_3 * V_4 = F_104 ( V_2 ) ;
const T_1 V_331 =
F_187 ( V_4 ) + V_328 ;
T_5 V_294 = ( T_5 ) ( V_331 - V_79 ) ;
if ( V_294 > 0 )
V_328 = V_294 ;
}
F_134 ( V_2 , V_249 , V_328 ,
V_250 ) ;
}
}
void F_188 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_185 ( V_2 ) ;
if ( ! V_33 -> V_258 )
return;
F_175 ( V_2 , false ) ;
F_144 ( V_2 , 1 ) ;
F_174 ( V_2 ) ;
}
static T_1 F_189 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_332 ;
F_91 ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_108 ) ) ;
V_332 = F_76 ( V_4 ) ;
if ( F_190 ( V_2 , V_4 , V_33 -> V_108 - F_18 ( V_4 ) -> V_80 ) )
return 0 ;
V_332 -= F_76 ( V_4 ) ;
if ( V_332 ) {
F_91 ( F_76 ( V_4 ) == 0 ) ;
F_91 ( ! F_48 ( F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) ;
}
return V_332 ;
}
static void F_191 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_164 )
{
const struct V_56 * V_333 ;
if ( F_58 ( ! ( V_2 -> V_334 & V_335 ) ) )
return;
V_333 = F_3 ( V_4 ) ;
if ( ( V_333 -> V_336 & V_337 ) &&
F_192 ( V_333 -> V_338 , V_164 , F_7 ( V_2 ) -> V_108 - 1 ) )
F_193 ( V_4 , NULL , V_2 , V_339 ) ;
}
static int F_194 ( struct V_1 * V_2 , int V_340 ,
T_1 V_164 ,
struct V_178 * V_341 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_181 V_342 , V_343 , V_99 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_344 = V_33 -> V_137 ;
T_1 V_185 = V_33 -> V_116 ;
bool V_345 = true ;
long V_319 = - 1L ;
long V_318 = - 1L ;
long V_346 = - 1L ;
struct V_3 * V_4 ;
T_1 V_347 = 0 ;
bool V_348 ;
int V_149 = 0 ;
V_342 . V_189 = 0 ;
while ( ( V_4 = F_104 ( V_2 ) ) && V_4 != F_82 ( V_2 ) ) {
struct V_349 * V_350 = F_18 ( V_4 ) ;
T_4 V_143 = V_350 -> V_143 ;
T_1 V_351 ;
F_191 ( V_2 , V_4 , V_164 ) ;
if ( F_55 ( V_350 -> V_95 , V_33 -> V_108 ) ) {
if ( F_76 ( V_4 ) == 1 ||
! F_55 ( V_33 -> V_108 , V_350 -> V_80 ) )
break;
V_351 = F_189 ( V_2 , V_4 ) ;
if ( ! V_351 )
break;
V_345 = false ;
} else {
F_195 ( V_4 -> V_352 ) ;
V_351 = F_76 ( V_4 ) ;
}
if ( F_103 ( V_143 & V_184 ) ) {
if ( V_143 & V_157 )
V_33 -> V_153 -= V_351 ;
V_149 |= V_297 ;
} else if ( ! ( V_143 & V_145 ) ) {
V_343 = V_4 -> V_181 ;
F_196 ( V_343 . V_189 == 0 ) ;
if ( ! V_342 . V_189 )
V_342 = V_343 ;
V_185 = F_9 ( V_347 , V_185 ) ;
if ( ! F_55 ( V_350 -> V_95 , V_33 -> V_186 ) )
V_149 |= V_187 ;
}
if ( V_143 & V_145 )
V_33 -> V_137 -= V_351 ;
if ( V_143 & V_144 )
V_33 -> V_141 -= V_351 ;
V_33 -> V_116 -= V_351 ;
V_347 += V_351 ;
if ( F_58 ( ! ( V_350 -> V_198 & V_353 ) ) ) {
V_149 |= V_354 ;
} else {
V_149 |= V_324 ;
V_33 -> V_266 = 0 ;
}
if ( ! V_345 )
break;
F_95 ( V_4 , V_2 ) ;
F_96 ( V_2 , V_4 ) ;
if ( F_103 ( V_4 == V_33 -> V_140 ) )
V_33 -> V_140 = NULL ;
if ( F_103 ( V_4 == V_33 -> V_122 ) )
V_33 -> V_122 = NULL ;
}
if ( F_58 ( F_192 ( V_33 -> V_355 , V_164 , V_33 -> V_108 ) ) )
V_33 -> V_355 = V_33 -> V_108 ;
if ( V_4 && ( F_18 ( V_4 ) -> V_143 & V_145 ) )
V_149 |= V_247 ;
F_197 ( & V_99 ) ;
if ( F_58 ( V_342 . V_189 ) ) {
V_318 = F_198 ( & V_99 , & V_342 ) ;
V_346 = F_198 ( & V_99 , & V_343 ) ;
}
if ( V_341 -> V_188 . V_189 ) {
V_319 = F_198 ( & V_99 , & V_341 -> V_188 ) ;
V_346 = F_198 ( & V_99 , & V_341 -> V_190 ) ;
}
V_348 = F_181 ( V_2 , V_149 , V_318 , V_319 ) ;
if ( V_149 & V_320 ) {
F_185 ( V_2 ) ;
if ( F_103 ( V_6 -> V_245 . V_246 &&
! F_55 ( V_33 -> V_316 . V_356 , V_33 -> V_108 ) ) ) {
F_168 ( V_2 ) ;
}
if ( F_69 ( V_33 ) ) {
F_123 ( V_2 , V_347 ) ;
} else {
int V_294 ;
if ( V_185 < V_340 )
F_68 ( V_2 , V_33 -> V_136 - V_185 , 0 ) ;
V_294 = F_66 ( V_33 ) ? V_347 :
V_344 - V_33 -> V_137 ;
V_33 -> V_192 -= F_9 ( V_33 -> V_192 , V_294 ) ;
}
V_33 -> V_136 -= F_9 ( V_347 , V_33 -> V_136 ) ;
} else if ( V_4 && V_348 && V_319 >= 0 &&
V_319 > F_198 ( & V_99 , & V_4 -> V_181 ) ) {
F_185 ( V_2 ) ;
}
if ( V_6 -> V_237 -> V_347 )
V_6 -> V_237 -> V_347 ( V_2 , V_347 , V_346 ) ;
#if V_134 > 0
F_115 ( ( int ) V_33 -> V_137 < 0 ) ;
F_115 ( ( int ) V_33 -> V_141 < 0 ) ;
F_115 ( ( int ) V_33 -> V_153 < 0 ) ;
if ( ! V_33 -> V_116 && F_142 ( V_33 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_33 -> V_141 ) {
F_72 ( L_9 ,
V_33 -> V_141 , V_6 -> V_135 ) ;
V_33 -> V_141 = 0 ;
}
if ( V_33 -> V_137 ) {
F_72 ( L_10 ,
V_33 -> V_137 , V_6 -> V_135 ) ;
V_33 -> V_137 = 0 ;
}
if ( V_33 -> V_153 ) {
F_72 ( L_11 ,
V_33 -> V_153 , V_6 -> V_135 ) ;
V_33 -> V_153 = 0 ;
}
}
#endif
return V_149 ;
}
static void F_199 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_55 ( F_18 ( F_82 ( V_2 ) ) -> V_95 , F_200 ( V_33 ) ) ) {
V_6 -> V_321 = 0 ;
F_186 ( V_2 , V_357 ) ;
} else {
unsigned long V_358 = F_201 ( V_2 , V_250 ) ;
F_134 ( V_2 , V_357 ,
V_358 , V_250 ) ;
}
}
static inline bool F_202 ( const struct V_1 * V_2 , const int V_149 )
{
return ! ( V_149 & V_359 ) || ( V_149 & V_360 ) ||
F_2 ( V_2 ) -> V_135 != V_284 ;
}
static inline bool F_203 ( const struct V_1 * V_2 , const int V_149 )
{
if ( F_176 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_59 > V_242 )
return V_149 & V_361 ;
return V_149 & V_354 ;
}
static inline bool F_204 ( const struct V_32 * V_33 ,
const T_1 V_325 , const T_1 V_156 ,
const T_1 V_362 )
{
return F_55 ( V_325 , V_33 -> V_108 ) ||
F_55 ( V_156 , V_33 -> V_363 ) ||
( V_156 == V_33 -> V_363 && V_362 > V_33 -> V_364 ) ;
}
static void F_205 ( struct V_32 * V_33 , T_1 V_325 )
{
T_1 V_294 = V_325 - V_33 -> V_108 ;
F_206 ( & V_33 -> V_365 ) ;
V_33 -> V_366 += V_294 ;
F_207 ( & V_33 -> V_365 ) ;
V_33 -> V_108 = V_325 ;
}
static void F_208 ( struct V_32 * V_33 , T_1 V_80 )
{
T_1 V_294 = V_80 - V_33 -> V_93 ;
F_206 ( & V_33 -> V_365 ) ;
V_33 -> V_367 += V_294 ;
F_207 ( & V_33 -> V_365 ) ;
V_33 -> V_93 = V_80 ;
}
static int F_209 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_325 ,
T_1 V_156 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_149 = 0 ;
T_1 V_362 = F_151 ( F_6 ( V_4 ) -> V_63 ) ;
if ( F_58 ( ! F_6 ( V_4 ) -> V_48 ) )
V_362 <<= V_33 -> V_52 . V_368 ;
if ( F_204 ( V_33 , V_325 , V_156 , V_362 ) ) {
V_149 |= V_369 ;
F_210 ( V_33 , V_156 ) ;
if ( V_33 -> V_364 != V_362 ) {
V_33 -> V_364 = V_362 ;
V_33 -> V_370 = 0 ;
F_211 ( V_2 ) ;
if ( F_82 ( V_2 ) )
F_212 ( V_2 ) ;
if ( V_362 > V_33 -> V_148 ) {
V_33 -> V_148 = V_362 ;
F_170 ( V_2 , F_2 ( V_2 ) -> V_304 ) ;
}
}
}
F_205 ( V_33 , V_325 ) ;
return V_149 ;
}
bool F_213 ( struct V_371 * V_371 , const struct V_3 * V_4 ,
int V_128 , T_1 * V_372 )
{
if ( ( F_18 ( V_4 ) -> V_80 != F_18 ( V_4 ) -> V_95 ) &&
! F_6 ( V_4 ) -> V_48 )
goto V_373;
if ( * V_372 ) {
T_5 V_374 = ( T_5 ) ( V_79 - * V_372 ) ;
if ( 0 <= V_374 && V_374 < V_375 ) {
F_70 ( V_371 , V_128 ) ;
return true ;
}
}
* V_372 = V_79 ;
V_373:
return false ;
}
static void F_214 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_1 V_376 ;
static unsigned int V_377 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_99 ;
if ( F_213 ( F_71 ( V_2 ) , V_4 ,
V_378 ,
& V_33 -> V_372 ) )
return;
V_99 = V_254 / V_379 ;
if ( V_99 != V_376 ) {
V_376 = V_99 ;
V_377 = 0 ;
}
if ( ++ V_377 <= V_380 ) {
F_70 ( F_71 ( V_2 ) , V_381 ) ;
F_215 ( V_2 ) ;
}
}
static void F_216 ( struct V_32 * V_33 )
{
V_33 -> V_52 . V_382 = V_33 -> V_52 . V_383 ;
V_33 -> V_52 . V_384 = F_217 () ;
}
static void F_218 ( struct V_32 * V_33 , T_1 V_80 )
{
if ( V_33 -> V_52 . V_267 && ! F_55 ( V_80 , V_33 -> V_385 ) ) {
if ( F_219 ( & V_33 -> V_52 , 0 ) )
F_216 ( V_33 ) ;
}
}
static void F_220 ( struct V_1 * V_2 , T_1 V_325 , int V_149 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_48 ( V_325 , V_33 -> V_288 ) )
return;
if ( V_149 & V_222 ) {
V_33 -> V_288 = 0 ;
} else if ( F_55 ( V_325 , V_33 -> V_288 ) ) {
F_160 ( V_2 ) ;
F_130 ( V_2 , V_298 ) ;
F_163 ( V_2 ) ;
F_165 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) ,
V_386 ) ;
} else if ( ! ( V_149 & ( V_312 |
V_359 | V_191 ) ) ) {
V_33 -> V_288 = 0 ;
}
}
static inline void F_221 ( struct V_1 * V_2 , T_1 V_387 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_237 -> V_388 )
V_6 -> V_237 -> V_388 ( V_2 , V_387 ) ;
}
static int F_222 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_149 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_178 V_389 ;
T_1 V_164 = V_33 -> V_108 ;
T_1 V_156 = F_18 ( V_4 ) -> V_80 ;
T_1 V_325 = F_18 ( V_4 ) -> V_156 ;
bool V_310 = false ;
T_1 V_340 ;
int V_390 = V_33 -> V_116 ;
const int V_292 = V_33 -> V_116 - V_33 -> V_137 ;
int V_231 = 0 ;
V_389 . V_188 . V_189 = 0 ;
F_195 ( V_2 -> V_391 . V_352 ) ;
if ( F_48 ( V_325 , V_164 ) ) {
if ( F_48 ( V_325 , V_164 - V_33 -> V_148 ) ) {
F_214 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_392;
}
if ( F_55 ( V_325 , V_33 -> V_110 ) )
goto V_393;
if ( V_6 -> V_329 == V_255 ||
V_6 -> V_329 == V_330 )
F_185 ( V_2 ) ;
if ( F_55 ( V_325 , V_164 ) ) {
V_149 |= V_312 ;
V_6 -> V_235 = 0 ;
}
V_340 = V_33 -> V_136 ;
if ( V_149 & V_394 )
F_218 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
if ( ! ( V_149 & V_395 ) && F_55 ( V_325 , V_164 ) ) {
F_210 ( V_33 , V_156 ) ;
F_205 ( V_33 , V_325 ) ;
V_149 |= V_369 ;
F_221 ( V_2 , V_396 ) ;
F_70 ( F_71 ( V_2 ) , V_397 ) ;
} else {
T_1 V_398 = V_399 ;
if ( V_156 != F_18 ( V_4 ) -> V_95 )
V_149 |= V_400 ;
else
F_70 ( F_71 ( V_2 ) , V_401 ) ;
V_149 |= F_209 ( V_2 , V_4 , V_325 , V_156 ) ;
if ( F_18 ( V_4 ) -> V_143 )
V_149 |= F_114 ( V_2 , V_4 , V_164 ,
& V_389 ) ;
if ( F_24 ( V_33 , F_6 ( V_4 ) ) ) {
V_149 |= V_252 ;
V_398 |= V_402 ;
}
if ( V_149 & V_369 )
V_398 |= V_396 ;
F_221 ( V_2 , V_398 ) ;
}
V_2 -> V_403 = 0 ;
V_6 -> V_404 = 0 ;
V_33 -> V_405 = V_79 ;
if ( ! V_390 )
goto V_406;
V_231 = V_33 -> V_116 ;
V_149 |= F_194 ( V_2 , V_340 , V_164 ,
& V_389 ) ;
V_231 -= V_33 -> V_116 ;
if ( F_202 ( V_2 , V_149 ) ) {
V_310 = ! ( V_149 & ( V_312 | V_359 ) ) ;
F_180 ( V_2 , V_231 , V_292 ,
V_310 , V_149 ) ;
}
if ( V_33 -> V_288 )
F_220 ( V_2 , V_325 , V_149 ) ;
if ( F_203 ( V_2 , V_149 ) )
F_184 ( V_2 , V_325 , V_231 ) ;
if ( ( V_149 & V_361 ) || ! ( V_149 & V_359 ) ) {
struct V_29 * V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_223 ( V_30 ) ;
}
if ( V_6 -> V_329 == V_249 )
F_224 ( V_2 ) ;
F_57 ( V_2 ) ;
return 1 ;
V_406:
if ( V_149 & V_222 )
F_180 ( V_2 , V_231 , V_292 ,
V_310 , V_149 ) ;
if ( F_82 ( V_2 ) )
F_199 ( V_2 ) ;
if ( V_33 -> V_288 )
F_220 ( V_2 , V_325 , V_149 ) ;
return 1 ;
V_393:
F_225 ( V_2 , L_12 , V_325 , V_33 -> V_108 , V_33 -> V_110 ) ;
return - 1 ;
V_392:
if ( F_18 ( V_4 ) -> V_143 ) {
V_149 |= F_114 ( V_2 , V_4 , V_164 ,
& V_389 ) ;
F_180 ( V_2 , V_231 , V_292 ,
V_310 , V_149 ) ;
}
F_225 ( V_2 , L_13 , V_325 , V_33 -> V_108 , V_33 -> V_110 ) ;
return 0 ;
}
static void F_226 ( int V_10 , const unsigned char * V_407 ,
bool V_48 , struct V_408 * V_409 ,
bool V_410 )
{
if ( ! V_409 || ! V_48 || V_10 < 0 || ( V_10 & 1 ) )
return;
if ( V_10 >= V_411 &&
V_10 <= V_412 )
memcpy ( V_409 -> V_413 , V_407 , V_10 ) ;
else if ( V_10 != 0 )
V_10 = - 1 ;
V_409 -> V_10 = V_10 ;
V_409 -> exp = V_410 ;
}
void F_227 ( const struct V_3 * V_4 ,
struct V_414 * V_415 , int V_416 ,
struct V_408 * V_409 )
{
const unsigned char * V_213 ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
int V_417 = ( V_46 -> V_418 * 4 ) - sizeof( struct V_15 ) ;
V_213 = ( const unsigned char * ) ( V_46 + 1 ) ;
V_415 -> V_267 = 0 ;
while ( V_417 > 0 ) {
int V_419 = * V_213 ++ ;
int V_420 ;
switch ( V_419 ) {
case V_421 :
return;
case V_422 :
V_417 -- ;
continue;
default:
V_420 = * V_213 ++ ;
if ( V_420 < 2 )
return;
if ( V_420 > V_417 )
return;
switch ( V_419 ) {
case V_423 :
if ( V_420 == V_424 && V_46 -> V_48 && ! V_416 ) {
T_6 V_425 = F_228 ( V_213 ) ;
if ( V_425 ) {
if ( V_415 -> V_426 &&
V_415 -> V_426 < V_425 )
V_425 = V_415 -> V_426 ;
V_415 -> V_53 = V_425 ;
}
}
break;
case V_427 :
if ( V_420 == V_428 && V_46 -> V_48 &&
! V_416 && V_429 ) {
T_7 V_368 = * ( T_7 * ) V_213 ;
V_415 -> V_430 = 1 ;
if ( V_368 > 14 ) {
F_229 ( L_14 ,
V_431 ,
V_368 ) ;
V_368 = 14 ;
}
V_415 -> V_368 = V_368 ;
}
break;
case V_432 :
if ( ( V_420 == V_433 ) &&
( ( V_416 && V_415 -> V_434 ) ||
( ! V_416 && V_435 ) ) ) {
V_415 -> V_267 = 1 ;
V_415 -> V_383 = F_84 ( V_213 ) ;
V_415 -> V_94 = F_84 ( V_213 + 4 ) ;
}
break;
case V_436 :
if ( V_420 == V_437 && V_46 -> V_48 &&
! V_416 && V_438 ) {
V_415 -> V_123 = V_439 ;
F_230 ( V_415 ) ;
}
break;
case V_440 :
if ( ( V_420 >= ( V_216 + V_441 ) ) &&
! ( ( V_420 - V_216 ) % V_441 ) &&
V_415 -> V_123 ) {
F_18 ( V_4 ) -> V_143 = ( V_213 - 2 ) - ( unsigned char * ) V_46 ;
}
break;
#ifdef F_231
case V_442 :
break;
#endif
case V_443 :
F_226 (
V_420 - V_444 ,
V_213 , V_46 -> V_48 , V_409 , false ) ;
break;
case V_445 :
if ( V_420 >= V_446 &&
F_228 ( V_213 ) ==
V_447 )
F_226 ( V_420 -
V_446 ,
V_213 + 2 , V_46 -> V_48 , V_409 , true ) ;
break;
}
V_213 += V_420 - 2 ;
V_417 -= V_420 ;
}
}
}
static bool F_232 ( struct V_32 * V_33 , const struct V_15 * V_46 )
{
const T_8 * V_213 = ( const T_8 * ) ( V_46 + 1 ) ;
if ( * V_213 == F_233 ( ( V_422 << 24 ) | ( V_422 << 16 )
| ( V_432 << 8 ) | V_433 ) ) {
V_33 -> V_52 . V_267 = 1 ;
++ V_213 ;
V_33 -> V_52 . V_383 = F_234 ( * V_213 ) ;
++ V_213 ;
if ( * V_213 )
V_33 -> V_52 . V_94 = F_234 ( * V_213 ) - V_33 -> V_448 ;
else
V_33 -> V_52 . V_94 = 0 ;
return true ;
}
return false ;
}
static bool F_235 ( const struct V_3 * V_4 ,
const struct V_15 * V_46 , struct V_32 * V_33 )
{
if ( V_46 -> V_418 == ( sizeof( * V_46 ) / 4 ) ) {
V_33 -> V_52 . V_267 = 0 ;
return false ;
} else if ( V_33 -> V_52 . V_434 &&
V_46 -> V_418 == ( ( sizeof( * V_46 ) + V_449 ) / 4 ) ) {
if ( F_232 ( V_33 , V_46 ) )
return true ;
}
F_227 ( V_4 , & V_33 -> V_52 , 1 , NULL ) ;
if ( V_33 -> V_52 . V_267 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_448 ;
return true ;
}
const T_4 * F_236 ( const struct V_15 * V_46 )
{
int V_417 = ( V_46 -> V_418 << 2 ) - sizeof( * V_46 ) ;
const T_4 * V_213 = ( const T_4 * ) ( V_46 + 1 ) ;
if ( V_417 < V_450 )
return NULL ;
while ( V_417 > 0 ) {
int V_419 = * V_213 ++ ;
int V_420 ;
switch ( V_419 ) {
case V_421 :
return NULL ;
case V_422 :
V_417 -- ;
continue;
default:
V_420 = * V_213 ++ ;
if ( V_420 < 2 || V_420 > V_417 )
return NULL ;
if ( V_419 == V_442 )
return V_420 == V_450 ? V_213 : NULL ;
}
V_213 += V_420 - 2 ;
V_417 -= V_420 ;
}
return NULL ;
}
static int F_237 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
const struct V_15 * V_46 = F_6 ( V_4 ) ;
T_1 V_80 = F_18 ( V_4 ) -> V_80 ;
T_1 V_325 = F_18 ( V_4 ) -> V_156 ;
return (
( V_46 -> V_325 && V_80 == F_18 ( V_4 ) -> V_95 && V_80 == V_33 -> V_93 ) &&
V_325 == V_33 -> V_108 &&
! F_204 ( V_33 , V_325 , V_80 , F_151 ( V_46 -> V_63 ) << V_33 -> V_52 . V_368 ) &&
( T_5 ) ( V_33 -> V_52 . V_382 - V_33 -> V_52 . V_383 ) <= ( F_2 ( V_2 ) -> V_101 * 1024 ) / V_379 ) ;
}
static inline bool F_238 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
return ! F_219 ( & V_33 -> V_52 , V_451 ) &&
! F_237 ( V_2 , V_4 ) ;
}
static inline bool F_239 ( const struct V_32 * V_33 , T_1 V_80 , T_1 V_95 )
{
return ! F_48 ( V_95 , V_33 -> V_385 ) &&
! F_55 ( V_80 , V_33 -> V_93 + F_240 ( V_33 ) ) ;
}
void F_241 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_452 ) {
case V_453 :
V_2 -> V_454 = V_455 ;
break;
case V_456 :
V_2 -> V_454 = V_457 ;
break;
case V_458 :
return;
default:
V_2 -> V_454 = V_459 ;
}
F_242 () ;
if ( ! F_243 ( V_2 , V_460 ) )
V_2 -> V_461 ( V_2 ) ;
F_244 ( V_2 ) ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_52 ( V_2 ) ;
V_2 -> V_462 |= V_463 ;
F_246 ( V_2 , V_464 ) ;
switch ( V_2 -> V_452 ) {
case V_465 :
case V_466 :
F_247 ( V_2 , V_456 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_456 :
case V_467 :
break;
case V_468 :
break;
case V_469 :
F_215 ( V_2 ) ;
F_247 ( V_2 , V_467 ) ;
break;
case V_470 :
F_215 ( V_2 ) ;
F_248 ( V_2 , V_471 , 0 ) ;
break;
default:
F_249 ( L_15 ,
V_431 , V_2 -> V_452 ) ;
break;
}
F_250 ( & V_33 -> V_472 ) ;
if ( F_142 ( V_33 ) )
F_230 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
if ( ! F_243 ( V_2 , V_460 ) ) {
V_2 -> V_473 ( V_2 ) ;
if ( V_2 -> V_462 == V_474 ||
V_2 -> V_452 == V_458 )
F_251 ( V_2 , V_475 , V_476 ) ;
else
F_251 ( V_2 , V_475 , V_477 ) ;
}
}
static inline bool F_252 ( struct V_206 * V_162 , T_1 V_80 ,
T_1 V_95 )
{
if ( ! F_55 ( V_80 , V_162 -> V_95 ) && ! F_55 ( V_162 -> V_147 , V_95 ) ) {
if ( F_48 ( V_80 , V_162 -> V_147 ) )
V_162 -> V_147 = V_80 ;
if ( F_55 ( V_95 , V_162 -> V_95 ) )
V_162 -> V_95 = V_95 ;
return true ;
}
return false ;
}
static void F_253 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_142 ( V_33 ) && V_478 ) {
int V_128 ;
if ( F_48 ( V_80 , V_33 -> V_93 ) )
V_128 = V_479 ;
else
V_128 = V_480 ;
F_70 ( F_71 ( V_2 ) , V_128 ) ;
V_33 -> V_52 . V_481 = 1 ;
V_33 -> V_482 [ 0 ] . V_147 = V_80 ;
V_33 -> V_482 [ 0 ] . V_95 = V_95 ;
}
}
static void F_254 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ! V_33 -> V_52 . V_481 )
F_253 ( V_2 , V_80 , V_95 ) ;
else
F_252 ( V_33 -> V_482 , V_80 , V_95 ) ;
}
static void F_255 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_483 ) ;
F_10 ( V_2 ) ;
if ( F_142 ( V_33 ) && V_478 ) {
T_1 V_95 = F_18 ( V_4 ) -> V_95 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) )
V_95 = V_33 -> V_93 ;
F_253 ( V_2 , F_18 ( V_4 ) -> V_80 , V_95 ) ;
}
}
F_215 ( V_2 ) ;
}
static void F_256 ( struct V_32 * V_33 )
{
int V_484 ;
struct V_206 * V_162 = & V_33 -> V_485 [ 0 ] ;
struct V_206 * V_486 = V_162 + 1 ;
for ( V_484 = 1 ; V_484 < V_33 -> V_52 . V_163 ; ) {
if ( F_252 ( V_162 , V_486 -> V_147 , V_486 -> V_95 ) ) {
int V_219 ;
V_33 -> V_52 . V_163 -- ;
for ( V_219 = V_484 ; V_219 < V_33 -> V_52 . V_163 ; V_219 ++ )
V_162 [ V_219 ] = V_162 [ V_219 + 1 ] ;
continue;
}
V_484 ++ , V_486 ++ ;
}
}
static void F_257 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_95 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_206 * V_162 = & V_33 -> V_485 [ 0 ] ;
int V_487 = V_33 -> V_52 . V_163 ;
int V_484 ;
if ( ! V_487 )
goto V_488;
for ( V_484 = 0 ; V_484 < V_487 ; V_484 ++ , V_162 ++ ) {
if ( F_252 ( V_162 , V_80 , V_95 ) ) {
for (; V_484 > 0 ; V_484 -- , V_162 -- )
F_117 ( * V_162 , * ( V_162 - 1 ) ) ;
if ( V_487 > 1 )
F_256 ( V_33 ) ;
return;
}
}
if ( V_484 >= V_215 ) {
V_484 -- ;
V_33 -> V_52 . V_163 -- ;
V_162 -- ;
}
for (; V_484 > 0 ; V_484 -- , V_162 -- )
* V_162 = * ( V_162 - 1 ) ;
V_488:
V_162 -> V_147 = V_80 ;
V_162 -> V_95 = V_95 ;
V_33 -> V_52 . V_163 ++ ;
}
static void F_258 ( struct V_32 * V_33 )
{
struct V_206 * V_162 = & V_33 -> V_485 [ 0 ] ;
int V_163 = V_33 -> V_52 . V_163 ;
int V_484 ;
if ( F_259 ( & V_33 -> V_472 ) ) {
V_33 -> V_52 . V_163 = 0 ;
return;
}
for ( V_484 = 0 ; V_484 < V_163 ; ) {
if ( ! F_48 ( V_33 -> V_93 , V_162 -> V_147 ) ) {
int V_219 ;
F_115 ( F_48 ( V_33 -> V_93 , V_162 -> V_95 ) ) ;
for ( V_219 = V_484 + 1 ; V_219 < V_163 ; V_219 ++ )
V_33 -> V_485 [ V_219 - 1 ] = V_33 -> V_485 [ V_219 ] ;
V_163 -- ;
continue;
}
V_484 ++ ;
V_162 ++ ;
}
V_33 -> V_52 . V_163 = V_163 ;
}
static bool F_260 ( struct V_1 * V_2 ,
struct V_3 * V_489 ,
struct V_3 * V_490 ,
bool * V_491 )
{
int V_294 ;
* V_491 = false ;
if ( F_18 ( V_490 ) -> V_80 != F_18 ( V_489 ) -> V_95 )
return false ;
if ( ! F_261 ( V_489 , V_490 , V_491 , & V_294 ) )
return false ;
F_262 ( V_294 , & V_2 -> V_84 ) ;
F_263 ( V_2 , V_294 ) ;
F_70 ( F_71 ( V_2 ) , V_492 ) ;
F_18 ( V_489 ) -> V_95 = F_18 ( V_490 ) -> V_95 ;
F_18 ( V_489 ) -> V_156 = F_18 ( V_490 ) -> V_156 ;
F_18 ( V_489 ) -> V_198 |= F_18 ( V_490 ) -> V_198 ;
return true ;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_3 V_493 = V_33 -> V_93 ;
struct V_3 * V_4 , * V_494 ;
bool V_491 , V_495 ;
while ( ( V_4 = F_265 ( & V_33 -> V_472 ) ) != NULL ) {
if ( F_55 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_493 ) ) {
T_3 V_481 = V_493 ;
if ( F_48 ( F_18 ( V_4 ) -> V_95 , V_493 ) )
V_493 = F_18 ( V_4 ) -> V_95 ;
F_254 ( V_2 , F_18 ( V_4 ) -> V_80 , V_481 ) ;
}
F_266 ( V_4 , & V_33 -> V_472 ) ;
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_225 ( V_2 , L_16 ) ;
F_267 ( V_4 ) ;
continue;
}
F_225 ( V_2 , L_17 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
V_494 = F_268 ( & V_2 -> V_496 ) ;
V_495 = V_494 && F_260 ( V_2 , V_494 , V_4 , & V_491 ) ;
F_208 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_495 )
F_269 ( & V_2 -> V_496 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_198 & V_199 )
F_245 ( V_2 ) ;
if ( V_495 )
F_270 ( V_4 , V_491 ) ;
}
}
static int F_271 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_497 )
{
if ( F_43 ( & V_2 -> V_84 ) > V_2 -> V_72 ||
! F_272 ( V_2 , V_4 , V_497 ) ) {
if ( F_273 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_272 ( V_2 , V_4 , V_497 ) ) {
if ( ! F_274 ( V_2 ) )
return - 1 ;
if ( ! F_272 ( V_2 , V_4 , V_497 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_275 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_498 ;
T_1 V_80 , V_95 ;
F_21 ( V_33 , V_4 ) ;
if ( F_103 ( F_271 ( V_2 , V_4 , V_4 -> V_62 ) ) ) {
F_70 ( F_71 ( V_2 ) , V_499 ) ;
F_267 ( V_4 ) ;
return;
}
V_33 -> V_370 = 0 ;
F_52 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_500 ) ;
F_225 ( V_2 , L_18 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_498 = F_268 ( & V_33 -> V_472 ) ;
if ( ! V_498 ) {
if ( F_142 ( V_33 ) ) {
V_33 -> V_52 . V_163 = 1 ;
V_33 -> V_485 [ 0 ] . V_147 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_485 [ 0 ] . V_95 =
F_18 ( V_4 ) -> V_95 ;
}
F_276 ( & V_33 -> V_472 , V_4 ) ;
goto V_501;
}
V_80 = F_18 ( V_4 ) -> V_80 ;
V_95 = F_18 ( V_4 ) -> V_95 ;
if ( V_80 == F_18 ( V_498 ) -> V_95 ) {
bool V_491 ;
if ( ! F_260 ( V_2 , V_498 , V_4 , & V_491 ) ) {
F_277 ( & V_33 -> V_472 , V_498 , V_4 ) ;
} else {
F_31 ( V_2 , V_4 ) ;
F_270 ( V_4 , V_491 ) ;
V_4 = NULL ;
}
if ( ! V_33 -> V_52 . V_163 ||
V_33 -> V_485 [ 0 ] . V_95 != V_80 )
goto V_502;
V_33 -> V_485 [ 0 ] . V_95 = V_95 ;
goto V_501;
}
while ( 1 ) {
if ( ! F_55 ( F_18 ( V_498 ) -> V_80 , V_80 ) )
break;
if ( F_278 ( & V_33 -> V_472 , V_498 ) ) {
V_498 = NULL ;
break;
}
V_498 = F_279 ( & V_33 -> V_472 , V_498 ) ;
}
if ( V_498 && F_48 ( V_80 , F_18 ( V_498 ) -> V_95 ) ) {
if ( ! F_55 ( V_95 , F_18 ( V_498 ) -> V_95 ) ) {
F_70 ( F_71 ( V_2 ) , V_503 ) ;
F_267 ( V_4 ) ;
V_4 = NULL ;
F_253 ( V_2 , V_80 , V_95 ) ;
goto V_502;
}
if ( F_55 ( V_80 , F_18 ( V_498 ) -> V_80 ) ) {
F_253 ( V_2 , V_80 ,
F_18 ( V_498 ) -> V_95 ) ;
} else {
if ( F_278 ( & V_33 -> V_472 ,
V_498 ) )
V_498 = NULL ;
else
V_498 = F_279 (
& V_33 -> V_472 ,
V_498 ) ;
}
}
if ( ! V_498 )
F_276 ( & V_33 -> V_472 , V_4 ) ;
else
F_277 ( & V_33 -> V_472 , V_498 , V_4 ) ;
while ( ! F_280 ( & V_33 -> V_472 , V_4 ) ) {
V_498 = F_281 ( & V_33 -> V_472 , V_4 ) ;
if ( ! F_55 ( V_95 , F_18 ( V_498 ) -> V_80 ) )
break;
if ( F_48 ( V_95 , F_18 ( V_498 ) -> V_95 ) ) {
F_254 ( V_2 , F_18 ( V_498 ) -> V_80 ,
V_95 ) ;
break;
}
F_266 ( V_498 , & V_33 -> V_472 ) ;
F_254 ( V_2 , F_18 ( V_498 ) -> V_80 ,
F_18 ( V_498 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) , V_503 ) ;
F_267 ( V_498 ) ;
}
V_502:
if ( F_142 ( V_33 ) )
F_257 ( V_2 , V_80 , V_95 ) ;
V_501:
if ( V_4 ) {
F_31 ( V_2 , V_4 ) ;
F_282 ( V_4 , V_2 ) ;
}
}
static int T_9 F_283 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_504 ,
bool * V_491 )
{
int V_495 ;
struct V_3 * V_494 = F_268 ( & V_2 -> V_496 ) ;
F_284 ( V_4 , V_504 ) ;
V_495 = ( V_494 &&
F_260 ( V_2 , V_494 , V_4 , V_491 ) ) ? 1 : 0 ;
F_208 ( F_7 ( V_2 ) , F_18 ( V_4 ) -> V_95 ) ;
if ( ! V_495 ) {
F_269 ( & V_2 -> V_496 , V_4 ) ;
F_282 ( V_4 , V_2 ) ;
}
return V_495 ;
}
int F_285 ( struct V_1 * V_2 , struct V_505 * V_268 , T_10 V_497 )
{
struct V_3 * V_4 ;
bool V_491 ;
if ( V_497 == 0 )
return 0 ;
V_4 = F_286 ( V_497 , V_2 -> V_506 ) ;
if ( ! V_4 )
goto V_172;
if ( F_271 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_507;
if ( F_287 ( F_288 ( V_4 , V_497 ) , V_268 , V_497 ) )
goto V_507;
F_18 ( V_4 ) -> V_80 = F_7 ( V_2 ) -> V_93 ;
F_18 ( V_4 ) -> V_95 = F_18 ( V_4 ) -> V_80 + V_497 ;
F_18 ( V_4 ) -> V_156 = F_7 ( V_2 ) -> V_108 - 1 ;
if ( F_283 ( V_2 , V_4 , 0 , & V_491 ) ) {
F_196 ( V_491 ) ;
F_267 ( V_4 ) ;
}
return V_497 ;
V_507:
F_289 ( V_4 ) ;
V_172:
return - V_508 ;
}
static void F_290 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_495 = - 1 ;
bool V_491 = false ;
if ( F_18 ( V_4 ) -> V_80 == F_18 ( V_4 ) -> V_95 )
goto V_509;
F_291 ( V_4 ) ;
F_284 ( V_4 , F_6 ( V_4 ) -> V_418 * 4 ) ;
F_15 ( V_33 , V_4 ) ;
V_33 -> V_52 . V_481 = 0 ;
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 ) {
if ( F_240 ( V_33 ) == 0 )
goto V_510;
if ( V_33 -> V_511 . V_512 == V_513 &&
V_33 -> V_81 == V_33 -> V_93 && V_33 -> V_511 . V_10 &&
F_292 ( V_2 ) && ! V_33 -> V_514 ) {
int V_515 = F_45 (unsigned int, skb->len,
tp->ucopy.len) ;
F_293 ( V_516 ) ;
F_294 () ;
if ( ! F_295 ( V_4 , 0 , V_33 -> V_511 . V_268 , V_515 ) ) {
V_33 -> V_511 . V_10 -= V_515 ;
V_33 -> V_81 += V_515 ;
V_495 = ( V_515 == V_4 -> V_10 ) ;
F_50 ( V_2 ) ;
}
F_296 () ;
}
if ( V_495 <= 0 ) {
V_517:
if ( V_495 < 0 ) {
if ( F_297 ( & V_2 -> V_496 ) == 0 )
F_298 ( V_2 , V_4 -> V_62 ) ;
else if ( F_271 ( V_2 , V_4 , V_4 -> V_62 ) )
goto V_509;
}
V_495 = F_283 ( V_2 , V_4 , 0 , & V_491 ) ;
}
F_208 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
if ( V_4 -> V_10 )
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_198 & V_199 )
F_245 ( V_2 ) ;
if ( ! F_259 ( & V_33 -> V_472 ) ) {
F_264 ( V_2 ) ;
if ( F_259 ( & V_33 -> V_472 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_33 -> V_52 . V_163 )
F_258 ( V_33 ) ;
F_211 ( V_2 ) ;
if ( V_495 > 0 )
F_270 ( V_4 , V_491 ) ;
if ( ! F_243 ( V_2 , V_460 ) )
V_2 -> V_518 ( V_2 ) ;
return;
}
if ( ! F_55 ( F_18 ( V_4 ) -> V_95 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_483 ) ;
F_253 ( V_2 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ;
V_510:
F_10 ( V_2 ) ;
F_52 ( V_2 ) ;
V_509:
F_267 ( V_4 ) ;
return;
}
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 + F_240 ( V_33 ) ) )
goto V_510;
F_10 ( V_2 ) ;
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ) {
F_225 ( V_2 , L_19 ,
V_33 -> V_93 , F_18 ( V_4 ) -> V_80 ,
F_18 ( V_4 ) -> V_95 ) ;
F_253 ( V_2 , F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) ;
if ( ! F_240 ( V_33 ) )
goto V_510;
goto V_517;
}
F_275 ( V_2 , V_4 ) ;
}
static struct V_3 * F_299 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_519 * V_520 )
{
struct V_3 * V_352 = NULL ;
if ( ! F_280 ( V_520 , V_4 ) )
V_352 = F_281 ( V_520 , V_4 ) ;
F_266 ( V_4 , V_520 ) ;
F_267 ( V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_521 ) ;
return V_352 ;
}
static void
F_300 ( struct V_1 * V_2 , struct V_519 * V_520 ,
struct V_3 * V_522 , struct V_3 * V_494 ,
T_1 V_523 , T_1 V_501 )
{
struct V_3 * V_4 , * V_524 ;
bool V_525 ;
V_4 = V_522 ;
V_526:
V_525 = true ;
F_301 (list, skb, n) {
if ( V_4 == V_494 )
break;
if ( ! F_48 ( V_523 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_299 ( V_2 , V_4 , V_520 ) ;
if ( ! V_4 )
break;
goto V_526;
}
if ( ! ( F_18 ( V_4 ) -> V_198 & ( V_353 | V_199 ) ) &&
( F_30 ( V_4 -> V_62 ) > V_4 -> V_10 ||
F_48 ( F_18 ( V_4 ) -> V_80 , V_523 ) ) ) {
V_525 = false ;
break;
}
if ( ! F_280 ( V_520 , V_4 ) ) {
struct V_3 * V_352 = F_281 ( V_520 , V_4 ) ;
if ( V_352 != V_494 &&
F_18 ( V_4 ) -> V_95 != F_18 ( V_352 ) -> V_80 ) {
V_525 = false ;
break;
}
}
V_523 = F_18 ( V_4 ) -> V_95 ;
}
if ( V_525 ||
( F_18 ( V_4 ) -> V_198 & ( V_353 | V_199 ) ) )
return;
while ( F_48 ( V_523 , V_501 ) ) {
int V_527 = F_45 ( int , F_302 ( 0 , 0 ) , V_501 - V_523 ) ;
struct V_3 * V_528 ;
V_528 = F_286 ( V_527 , V_177 ) ;
if ( ! V_528 )
return;
memcpy ( V_528 -> V_529 , V_4 -> V_529 , sizeof( V_4 -> V_529 ) ) ;
F_18 ( V_528 ) -> V_80 = F_18 ( V_528 ) -> V_95 = V_523 ;
F_303 ( V_520 , V_4 , V_528 ) ;
F_282 ( V_528 , V_2 ) ;
while ( V_527 > 0 ) {
int V_530 = V_523 - F_18 ( V_4 ) -> V_80 ;
int V_497 = F_18 ( V_4 ) -> V_95 - V_523 ;
F_91 ( V_530 < 0 ) ;
if ( V_497 > 0 ) {
V_497 = F_9 ( V_527 , V_497 ) ;
if ( F_304 ( V_4 , V_530 , F_288 ( V_528 , V_497 ) , V_497 ) )
F_305 () ;
F_18 ( V_528 ) -> V_95 += V_497 ;
V_527 -= V_497 ;
V_523 += V_497 ;
}
if ( ! F_48 ( V_523 , F_18 ( V_4 ) -> V_95 ) ) {
V_4 = F_299 ( V_2 , V_4 , V_520 ) ;
if ( ! V_4 ||
V_4 == V_494 ||
( F_18 ( V_4 ) -> V_198 & ( V_353 | V_199 ) ) )
return;
}
}
}
}
static void F_306 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_265 ( & V_33 -> V_472 ) ;
struct V_3 * V_522 ;
T_1 V_523 , V_501 ;
if ( ! V_4 )
return;
V_523 = F_18 ( V_4 ) -> V_80 ;
V_501 = F_18 ( V_4 ) -> V_95 ;
V_522 = V_4 ;
for (; ; ) {
struct V_3 * V_352 = NULL ;
if ( ! F_280 ( & V_33 -> V_472 , V_4 ) )
V_352 = F_281 ( & V_33 -> V_472 , V_4 ) ;
V_4 = V_352 ;
if ( ! V_4 ||
F_55 ( F_18 ( V_4 ) -> V_80 , V_501 ) ||
F_48 ( F_18 ( V_4 ) -> V_95 , V_523 ) ) {
F_300 ( V_2 , & V_33 -> V_472 ,
V_522 , V_4 , V_523 , V_501 ) ;
V_522 = V_4 ;
if ( ! V_4 )
break;
V_523 = F_18 ( V_4 ) -> V_80 ;
V_501 = F_18 ( V_4 ) -> V_95 ;
} else {
if ( F_48 ( F_18 ( V_4 ) -> V_80 , V_523 ) )
V_523 = F_18 ( V_4 ) -> V_80 ;
if ( F_55 ( F_18 ( V_4 ) -> V_95 , V_501 ) )
V_501 = F_18 ( V_4 ) -> V_95 ;
}
}
}
static bool F_274 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
bool V_531 = false ;
if ( ! F_259 ( & V_33 -> V_472 ) ) {
F_70 ( F_71 ( V_2 ) , V_532 ) ;
F_250 ( & V_33 -> V_472 ) ;
if ( V_33 -> V_52 . V_123 )
F_230 ( & V_33 -> V_52 ) ;
F_53 ( V_2 ) ;
V_531 = true ;
}
return V_531 ;
}
static int F_273 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
F_225 ( V_2 , L_20 , V_33 -> V_81 ) ;
F_70 ( F_71 ( V_2 ) , V_533 ) ;
if ( F_43 ( & V_2 -> V_84 ) >= V_2 -> V_72 )
F_40 ( V_2 ) ;
else if ( F_33 ( V_2 ) )
V_33 -> V_65 = F_9 ( V_33 -> V_65 , 4U * V_33 -> V_68 ) ;
F_306 ( V_2 ) ;
if ( ! F_259 ( & V_2 -> V_496 ) )
F_300 ( V_2 , & V_2 -> V_496 ,
F_265 ( & V_2 -> V_496 ) ,
NULL ,
V_33 -> V_81 , V_33 -> V_93 ) ;
F_53 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_274 ( V_2 ) ;
if ( F_43 ( & V_2 -> V_84 ) <= V_2 -> V_72 )
return 0 ;
F_70 ( F_71 ( V_2 ) , V_534 ) ;
V_33 -> V_370 = 0 ;
return - 1 ;
}
static bool F_307 ( const struct V_1 * V_2 )
{
const struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_2 -> V_74 & V_76 )
return false ;
if ( F_33 ( V_2 ) )
return false ;
if ( F_41 ( V_2 ) >= F_42 ( V_2 , 0 ) )
return false ;
if ( F_119 ( V_33 ) >= V_33 -> V_58 )
return false ;
return true ;
}
static void F_308 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_307 ( V_2 ) ) {
F_25 ( V_2 ) ;
V_33 -> V_83 = V_79 ;
}
V_2 -> V_535 ( V_2 ) ;
}
static void F_309 ( struct V_1 * V_2 )
{
if ( F_243 ( V_2 , V_536 ) ) {
F_310 ( V_2 , V_536 ) ;
F_311 () ;
if ( V_2 -> V_537 &&
F_312 ( V_538 , & V_2 -> V_537 -> V_387 ) )
F_308 ( V_2 ) ;
}
}
static inline void F_313 ( struct V_1 * V_2 )
{
F_314 ( V_2 ) ;
F_309 ( V_2 ) ;
}
static void F_315 ( struct V_1 * V_2 , int V_539 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( ( ( V_33 -> V_93 - V_33 -> V_385 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_316 ( V_2 ) >= V_33 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_539 && F_265 ( & V_33 -> V_472 ) ) ) {
F_215 ( V_2 ) ;
} else {
F_317 ( V_2 ) ;
}
}
static inline void F_318 ( struct V_1 * V_2 )
{
if ( ! F_319 ( V_2 ) ) {
return;
}
F_315 ( V_2 , 1 ) ;
}
static void F_320 ( struct V_1 * V_2 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
T_1 V_213 = F_151 ( V_46 -> V_540 ) ;
if ( V_213 && ! V_541 )
V_213 -- ;
V_213 += F_234 ( V_46 -> V_80 ) ;
if ( F_55 ( V_33 -> V_81 , V_213 ) )
return;
if ( F_48 ( V_213 , V_33 -> V_93 ) )
return;
if ( V_33 -> V_514 && ! F_55 ( V_213 , V_33 -> V_542 ) )
return;
F_321 ( V_2 ) ;
if ( V_33 -> V_542 == V_33 -> V_81 && V_33 -> V_514 &&
! F_243 ( V_2 , V_543 ) && V_33 -> V_81 != V_33 -> V_93 ) {
struct V_3 * V_4 = F_265 ( & V_2 -> V_496 ) ;
V_33 -> V_81 ++ ;
if ( V_4 && ! F_48 ( V_33 -> V_81 , F_18 ( V_4 ) -> V_95 ) ) {
F_266 ( V_4 , & V_2 -> V_496 ) ;
F_267 ( V_4 ) ;
}
}
V_33 -> V_514 = V_544 ;
V_33 -> V_542 = V_213 ;
V_33 -> V_370 = 0 ;
}
static void F_322 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_46 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( V_46 -> V_545 )
F_320 ( V_2 , V_46 ) ;
if ( V_33 -> V_514 == V_544 ) {
T_1 V_213 = V_33 -> V_542 - F_234 ( V_46 -> V_80 ) + ( V_46 -> V_418 * 4 ) -
V_46 -> V_48 ;
if ( V_213 < V_4 -> V_10 ) {
T_4 V_209 ;
if ( F_304 ( V_4 , V_213 , & V_209 , 1 ) )
F_305 () ;
V_33 -> V_514 = V_546 | V_209 ;
if ( ! F_243 ( V_2 , V_460 ) )
V_2 -> V_518 ( V_2 ) ;
}
}
}
static int F_323 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_547 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
int V_515 = V_4 -> V_10 - V_547 ;
int V_172 ;
F_294 () ;
if ( F_324 ( V_4 ) )
V_172 = F_295 ( V_4 , V_547 , V_33 -> V_511 . V_268 , V_515 ) ;
else
V_172 = F_325 ( V_4 , V_547 , V_33 -> V_511 . V_268 ) ;
if ( ! V_172 ) {
V_33 -> V_511 . V_10 -= V_515 ;
V_33 -> V_81 += V_515 ;
F_50 ( V_2 ) ;
}
F_296 () ;
return V_172 ;
}
static T_11 F_326 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_548 ;
if ( F_292 ( V_2 ) ) {
F_294 () ;
V_548 = F_327 ( V_4 ) ;
F_296 () ;
} else {
V_548 = F_327 ( V_4 ) ;
}
return V_548 ;
}
static inline bool F_328 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_324 ( V_4 ) &&
F_326 ( V_2 , V_4 ) ;
}
static bool F_329 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , int V_549 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_235 ( V_4 , V_46 , V_33 ) && V_33 -> V_52 . V_267 &&
F_238 ( V_2 , V_4 ) ) {
if ( ! V_46 -> V_550 ) {
F_70 ( F_71 ( V_2 ) , V_551 ) ;
if ( ! F_213 ( F_71 ( V_2 ) , V_4 ,
V_552 ,
& V_33 -> V_372 ) )
F_255 ( V_2 , V_4 ) ;
goto V_553;
}
}
if ( ! F_239 ( V_33 , F_18 ( V_4 ) -> V_80 , F_18 ( V_4 ) -> V_95 ) ) {
if ( ! V_46 -> V_550 ) {
if ( V_46 -> V_48 )
goto V_554;
if ( ! F_213 ( F_71 ( V_2 ) , V_4 ,
V_555 ,
& V_33 -> V_372 ) )
F_255 ( V_2 , V_4 ) ;
}
goto V_553;
}
if ( V_46 -> V_550 ) {
if ( F_18 ( V_4 ) -> V_80 == V_33 -> V_93 )
F_241 ( V_2 ) ;
else
F_214 ( V_2 , V_4 ) ;
goto V_553;
}
if ( V_46 -> V_48 ) {
V_554:
if ( V_549 )
F_330 ( F_71 ( V_2 ) , V_556 ) ;
F_70 ( F_71 ( V_2 ) , V_557 ) ;
F_214 ( V_2 , V_4 ) ;
goto V_553;
}
return true ;
V_553:
F_267 ( V_4 ) ;
return false ;
}
void F_331 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , unsigned int V_10 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
if ( F_103 ( ! V_2 -> V_558 ) )
F_2 ( V_2 ) -> V_559 -> V_560 ( V_2 , V_4 ) ;
V_33 -> V_52 . V_267 = 0 ;
if ( ( F_5 ( V_46 ) & V_561 ) == V_33 -> V_370 &&
F_18 ( V_4 ) -> V_80 == V_33 -> V_93 &&
! F_55 ( F_18 ( V_4 ) -> V_156 , V_33 -> V_110 ) ) {
int V_18 = V_33 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_449 ) {
if ( ! F_232 ( V_33 , V_46 ) )
goto V_562;
if ( ( T_5 ) ( V_33 -> V_52 . V_383 - V_33 -> V_52 . V_382 ) < 0 )
goto V_562;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_449 ) &&
V_33 -> V_93 == V_33 -> V_385 )
F_216 ( V_33 ) ;
F_222 ( V_2 , V_4 , 0 ) ;
F_267 ( V_4 ) ;
F_313 ( V_2 ) ;
return;
} else {
F_330 ( F_71 ( V_2 ) , V_556 ) ;
goto V_553;
}
} else {
int V_495 = 0 ;
bool V_491 = false ;
if ( V_33 -> V_511 . V_512 == V_513 &&
V_33 -> V_81 == V_33 -> V_93 &&
V_10 - V_18 <= V_33 -> V_511 . V_10 &&
F_292 ( V_2 ) ) {
F_293 ( V_516 ) ;
if ( ! F_323 ( V_2 , V_4 , V_18 ) ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_449 ) &&
V_33 -> V_93 == V_33 -> V_385 )
F_216 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_284 ( V_4 , V_18 ) ;
F_208 ( V_33 , F_18 ( V_4 ) -> V_95 ) ;
F_70 ( F_71 ( V_2 ) , V_563 ) ;
V_495 = 1 ;
}
}
if ( ! V_495 ) {
if ( F_328 ( V_2 , V_4 ) )
goto V_564;
if ( ( int ) V_4 -> V_62 > V_2 -> V_565 )
goto V_566;
if ( V_18 ==
( sizeof( struct V_15 ) + V_449 ) &&
V_33 -> V_93 == V_33 -> V_385 )
F_216 ( V_33 ) ;
F_49 ( V_2 , V_4 ) ;
F_70 ( F_71 ( V_2 ) , V_567 ) ;
V_495 = F_283 ( V_2 , V_4 , V_18 ,
& V_491 ) ;
}
F_51 ( V_2 , V_4 ) ;
if ( F_18 ( V_4 ) -> V_156 != V_33 -> V_108 ) {
F_222 ( V_2 , V_4 , V_400 ) ;
F_313 ( V_2 ) ;
if ( ! F_319 ( V_2 ) )
goto V_568;
}
F_315 ( V_2 , 0 ) ;
V_568:
if ( V_495 )
F_270 ( V_4 , V_491 ) ;
V_2 -> V_518 ( V_2 ) ;
return;
}
}
V_562:
if ( V_10 < ( V_46 -> V_418 << 2 ) || F_328 ( V_2 , V_4 ) )
goto V_564;
if ( ! V_46 -> V_325 && ! V_46 -> V_550 && ! V_46 -> V_48 )
goto V_553;
if ( ! F_329 ( V_2 , V_4 , V_46 , 1 ) )
return;
V_566:
if ( F_222 ( V_2 , V_4 , V_395 | V_394 ) < 0 )
goto V_553;
F_49 ( V_2 , V_4 ) ;
F_322 ( V_2 , V_4 , V_46 ) ;
F_290 ( V_2 , V_4 ) ;
F_313 ( V_2 ) ;
F_318 ( V_2 ) ;
return;
V_564:
F_330 ( F_71 ( V_2 ) , V_569 ) ;
F_330 ( F_71 ( V_2 ) , V_556 ) ;
V_553:
F_267 ( V_4 ) ;
}
void F_332 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_247 ( V_2 , V_466 ) ;
if ( V_4 ) {
V_6 -> V_559 -> V_560 ( V_2 , V_4 ) ;
F_333 ( V_2 , V_4 ) ;
}
V_6 -> V_559 -> V_570 ( V_2 ) ;
F_334 ( V_2 ) ;
F_335 ( V_2 ) ;
V_33 -> V_571 = V_79 ;
F_37 ( V_2 ) ;
if ( F_243 ( V_2 , V_572 ) )
F_336 ( V_2 , F_337 ( V_33 ) ) ;
if ( ! V_33 -> V_52 . V_368 )
F_338 ( V_33 , V_33 -> V_364 ) ;
else
V_33 -> V_370 = 0 ;
if ( ! F_243 ( V_2 , V_460 ) ) {
V_2 -> V_473 ( V_2 ) ;
F_251 ( V_2 , V_573 , V_574 ) ;
}
}
static bool F_339 ( struct V_1 * V_2 , struct V_3 * V_575 ,
struct V_408 * V_407 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_33 -> V_576 ? F_104 ( V_2 ) : NULL ;
T_6 V_69 = V_33 -> V_52 . V_53 , V_577 = 0 ;
bool V_578 = false ;
if ( V_69 == V_33 -> V_52 . V_426 ) {
struct V_414 V_579 ;
F_340 ( & V_579 ) ;
V_579 . V_426 = V_579 . V_53 = 0 ;
F_227 ( V_575 , & V_579 , 0 , NULL ) ;
V_69 = V_579 . V_53 ;
}
if ( ! V_33 -> V_580 ) {
V_407 -> V_10 = - 1 ;
} else if ( V_33 -> V_323 ) {
V_578 = ( V_407 -> V_10 < 0 && V_13 ) ;
} else if ( V_407 -> V_10 < 0 && ! V_33 -> V_576 ) {
V_577 = V_33 -> V_581 ? 2 : 1 ;
}
F_341 ( V_2 , V_69 , V_407 , V_578 , V_577 ) ;
if ( V_13 ) {
F_109 (data, sk) {
if ( V_13 == F_82 ( V_2 ) ||
F_342 ( V_2 , V_13 ) )
break;
}
F_185 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_582 ) ;
return true ;
}
V_33 -> V_583 = V_33 -> V_576 ;
if ( V_33 -> V_583 )
F_70 ( F_71 ( V_2 ) , V_584 ) ;
return false ;
}
static int F_343 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_408 V_409 = { . V_10 = - 1 } ;
int V_585 = V_33 -> V_52 . V_53 ;
F_227 ( V_4 , & V_33 -> V_52 , 0 , & V_409 ) ;
if ( V_33 -> V_52 . V_267 && V_33 -> V_52 . V_94 )
V_33 -> V_52 . V_94 -= V_33 -> V_448 ;
if ( V_46 -> V_325 ) {
if ( ! F_55 ( F_18 ( V_4 ) -> V_156 , V_33 -> V_108 ) ||
F_55 ( F_18 ( V_4 ) -> V_156 , V_33 -> V_110 ) )
goto V_586;
if ( V_33 -> V_52 . V_267 && V_33 -> V_52 . V_94 &&
! F_192 ( V_33 -> V_52 . V_94 , V_33 -> V_266 ,
V_79 ) ) {
F_70 ( F_71 ( V_2 ) , V_587 ) ;
goto V_586;
}
if ( V_46 -> V_550 ) {
F_241 ( V_2 ) ;
goto V_553;
}
if ( ! V_46 -> V_48 )
goto V_588;
F_22 ( V_33 , V_46 ) ;
F_344 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
F_222 ( V_2 , V_4 , V_395 ) ;
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_385 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_364 = F_151 ( V_46 -> V_63 ) ;
if ( ! V_33 -> V_52 . V_430 ) {
V_33 -> V_52 . V_368 = V_33 -> V_52 . V_589 = 0 ;
V_33 -> V_66 = F_9 ( V_33 -> V_66 , 65535U ) ;
}
if ( V_33 -> V_52 . V_267 ) {
V_33 -> V_52 . V_434 = 1 ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_449 ;
V_33 -> V_68 -= V_449 ;
F_216 ( V_33 ) ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_142 ( V_33 ) && V_590 )
F_345 ( V_33 ) ;
F_346 ( V_2 ) ;
F_170 ( V_2 , V_6 -> V_304 ) ;
F_44 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_347 () ;
F_332 ( V_2 , V_4 ) ;
if ( ( V_33 -> V_580 || V_33 -> V_576 ) &&
F_339 ( V_2 , V_4 , & V_409 ) )
return - 1 ;
if ( V_2 -> V_591 ||
V_6 -> V_592 . V_593 ||
V_6 -> V_8 . V_26 ) {
F_52 ( V_2 ) ;
V_6 -> V_8 . V_100 = V_79 ;
F_10 ( V_2 ) ;
F_134 ( V_2 , V_594 ,
V_595 , V_250 ) ;
V_553:
F_267 ( V_4 ) ;
return 0 ;
} else {
F_215 ( V_2 ) ;
}
return - 1 ;
}
if ( V_46 -> V_550 ) {
goto V_588;
}
if ( V_33 -> V_52 . V_384 && V_33 -> V_52 . V_267 &&
F_348 ( & V_33 -> V_52 , 0 ) )
goto V_588;
if ( V_46 -> V_48 ) {
F_247 ( V_2 , V_465 ) ;
if ( V_33 -> V_52 . V_267 ) {
V_33 -> V_52 . V_434 = 1 ;
F_216 ( V_33 ) ;
V_33 -> V_18 =
sizeof( struct V_15 ) + V_449 ;
} else {
V_33 -> V_18 = sizeof( struct V_15 ) ;
}
V_33 -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_385 = F_18 ( V_4 ) -> V_80 + 1 ;
V_33 -> V_364 = F_151 ( V_46 -> V_63 ) ;
V_33 -> V_363 = F_18 ( V_4 ) -> V_80 ;
V_33 -> V_148 = V_33 -> V_364 ;
F_23 ( V_33 , V_46 ) ;
F_346 ( V_2 ) ;
F_170 ( V_2 , V_6 -> V_304 ) ;
F_44 ( V_2 ) ;
F_349 ( V_2 ) ;
#if 0
return -1;
#else
goto V_553;
#endif
}
V_588:
F_340 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_585 ;
goto V_553;
V_586:
F_340 ( & V_33 -> V_52 ) ;
V_33 -> V_52 . V_53 = V_585 ;
return 1 ;
}
int F_350 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_46 , unsigned int V_10 )
{
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_596 * V_597 ;
int V_598 = 0 ;
bool V_599 ;
T_1 V_322 ;
V_33 -> V_52 . V_267 = 0 ;
switch ( V_2 -> V_452 ) {
case V_458 :
goto V_553;
case V_600 :
if ( V_46 -> V_325 )
return 1 ;
if ( V_46 -> V_550 )
goto V_553;
if ( V_46 -> V_48 ) {
if ( V_46 -> V_601 )
goto V_553;
if ( V_6 -> V_559 -> V_602 ( V_2 , V_4 ) < 0 )
return 1 ;
F_289 ( V_4 ) ;
return 0 ;
}
goto V_553;
case V_453 :
V_598 = F_343 ( V_2 , V_4 , V_46 , V_10 ) ;
if ( V_598 >= 0 )
return V_598 ;
F_322 ( V_2 , V_4 , V_46 ) ;
F_267 ( V_4 ) ;
F_313 ( V_2 ) ;
return 0 ;
}
V_597 = V_33 -> V_327 ;
if ( V_597 ) {
F_196 ( V_2 -> V_452 != V_465 &&
V_2 -> V_452 != V_469 ) ;
if ( ! F_351 ( V_2 , V_4 , V_597 , true ) )
goto V_553;
}
if ( ! V_46 -> V_325 && ! V_46 -> V_550 && ! V_46 -> V_48 )
goto V_553;
if ( ! F_329 ( V_2 , V_4 , V_46 , 0 ) )
return 0 ;
V_599 = F_222 ( V_2 , V_4 , V_395 |
V_394 ) > 0 ;
switch ( V_2 -> V_452 ) {
case V_465 :
if ( ! V_599 )
return 1 ;
if ( V_597 ) {
V_322 = F_352 ( V_597 ) -> V_603 ;
V_33 -> V_323 = V_597 -> V_604 ;
F_353 ( V_2 , V_597 , false ) ;
} else {
V_322 = V_33 -> V_571 ;
V_6 -> V_559 -> V_570 ( V_2 ) ;
F_335 ( V_2 ) ;
F_346 ( V_2 ) ;
V_33 -> V_81 = V_33 -> V_93 ;
F_37 ( V_2 ) ;
}
F_347 () ;
F_247 ( V_2 , V_466 ) ;
V_2 -> V_473 ( V_2 ) ;
if ( V_2 -> V_537 )
F_251 ( V_2 , V_573 , V_574 ) ;
V_33 -> V_108 = F_18 ( V_4 ) -> V_156 ;
V_33 -> V_364 = F_151 ( V_46 -> V_63 ) << V_33 -> V_52 . V_368 ;
F_344 ( V_33 , F_18 ( V_4 ) -> V_80 ) ;
F_183 ( V_2 , V_322 ) ;
if ( V_33 -> V_52 . V_434 )
V_33 -> V_68 -= V_449 ;
if ( V_597 ) {
F_185 ( V_2 ) ;
} else
F_334 ( V_2 ) ;
F_57 ( V_2 ) ;
V_33 -> V_571 = V_79 ;
F_44 ( V_2 ) ;
F_354 ( V_33 ) ;
break;
case V_469 : {
struct V_29 * V_30 ;
int V_605 ;
if ( V_597 ) {
if ( ! V_599 )
return 1 ;
F_353 ( V_2 , V_597 , false ) ;
F_185 ( V_2 ) ;
}
if ( V_33 -> V_108 != V_33 -> V_606 )
break;
F_247 ( V_2 , V_470 ) ;
V_2 -> V_462 |= V_607 ;
V_30 = F_12 ( V_2 ) ;
if ( V_30 )
F_223 ( V_30 ) ;
if ( ! F_243 ( V_2 , V_460 ) ) {
V_2 -> V_473 ( V_2 ) ;
break;
}
if ( V_33 -> V_608 < 0 ||
( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_601 , V_33 -> V_93 ) ) ) {
F_244 ( V_2 ) ;
F_70 ( F_71 ( V_2 ) , V_609 ) ;
return 1 ;
}
V_605 = F_355 ( V_2 ) ;
if ( V_605 > V_610 ) {
F_336 ( V_2 , V_605 - V_610 ) ;
} else if ( V_46 -> V_601 || F_292 ( V_2 ) ) {
F_336 ( V_2 , V_605 ) ;
} else {
F_248 ( V_2 , V_470 , V_605 ) ;
goto V_553;
}
break;
}
case V_467 :
if ( V_33 -> V_108 == V_33 -> V_606 ) {
F_248 ( V_2 , V_471 , 0 ) ;
goto V_553;
}
break;
case V_468 :
if ( V_33 -> V_108 == V_33 -> V_606 ) {
F_356 ( V_2 ) ;
F_244 ( V_2 ) ;
goto V_553;
}
break;
}
F_322 ( V_2 , V_4 , V_46 ) ;
switch ( V_2 -> V_452 ) {
case V_456 :
case V_467 :
case V_468 :
if ( ! F_48 ( F_18 ( V_4 ) -> V_80 , V_33 -> V_93 ) )
break;
case V_469 :
case V_470 :
if ( V_2 -> V_462 & V_463 ) {
if ( F_18 ( V_4 ) -> V_95 != F_18 ( V_4 ) -> V_80 &&
F_55 ( F_18 ( V_4 ) -> V_95 - V_46 -> V_601 , V_33 -> V_93 ) ) {
F_70 ( F_71 ( V_2 ) , V_609 ) ;
F_241 ( V_2 ) ;
return 1 ;
}
}
case V_466 :
F_290 ( V_2 , V_4 ) ;
V_598 = 1 ;
break;
}
if ( V_2 -> V_452 != V_458 ) {
F_313 ( V_2 ) ;
F_318 ( V_2 ) ;
}
if ( ! V_598 ) {
V_553:
F_267 ( V_4 ) ;
}
return 0 ;
}
static inline void F_357 ( struct V_596 * V_597 , T_12 V_611 , int V_612 )
{
struct V_613 * V_614 = F_358 ( V_597 ) ;
if ( V_612 == V_272 )
F_359 ( L_21 ,
& V_614 -> V_615 , V_611 ) ;
#if F_153 ( V_275 )
else if ( V_612 == V_276 )
F_359 ( L_22 ,
& V_614 -> V_616 , V_611 ) ;
#endif
}
static void F_360 ( struct V_596 * V_597 ,
const struct V_3 * V_4 ,
const struct V_1 * V_617 ,
const struct V_29 * V_30 )
{
const struct V_15 * V_46 = F_6 ( V_4 ) ;
const struct V_371 * V_371 = F_71 ( V_617 ) ;
bool V_618 = V_46 -> V_47 && V_46 -> V_37 ;
bool V_619 , V_620 ;
T_1 V_621 ;
if ( ! V_618 )
return;
V_619 = ! F_361 ( F_18 ( V_4 ) -> V_39 ) ;
V_621 = F_362 ( V_30 , V_622 ) ;
V_620 = V_371 -> V_623 . V_624 || V_621 ;
if ( ( ! V_619 && V_620 ) || F_19 ( V_617 ) ||
( V_621 & V_625 ) )
F_358 ( V_597 ) -> V_620 = 1 ;
}
static void F_363 ( struct V_596 * V_597 ,
const struct V_414 * V_52 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_613 * V_614 = F_358 ( V_597 ) ;
V_597 -> V_23 = 0 ;
V_597 -> V_626 = 0 ;
F_352 ( V_597 ) -> V_627 = F_18 ( V_4 ) -> V_80 ;
F_352 ( V_597 ) -> V_93 = F_18 ( V_4 ) -> V_80 + 1 ;
F_352 ( V_597 ) -> V_603 = V_79 ;
F_352 ( V_597 ) -> V_372 = 0 ;
V_597 -> V_69 = V_52 -> V_53 ;
V_597 -> V_382 = V_52 -> V_267 ? V_52 -> V_383 : 0 ;
V_614 -> V_434 = V_52 -> V_434 ;
V_614 -> V_123 = V_52 -> V_123 ;
V_614 -> V_368 = V_52 -> V_368 ;
V_614 -> V_430 = V_52 -> V_430 ;
V_614 -> V_231 = 0 ;
V_614 -> V_620 = 0 ;
V_614 -> V_628 = F_6 ( V_4 ) -> V_629 ;
V_614 -> V_630 = F_151 ( F_6 ( V_4 ) -> V_631 ) ;
V_614 -> V_632 = F_364 ( V_2 , V_4 ) ;
}
struct V_596 * F_365 ( const struct V_633 * V_634 ,
struct V_1 * V_635 )
{
struct V_596 * V_597 = F_366 ( V_634 , V_635 ) ;
if ( V_597 ) {
struct V_613 * V_614 = F_358 ( V_597 ) ;
F_367 ( V_614 , V_387 ) ;
V_614 -> V_579 = NULL ;
F_368 ( & V_614 -> V_636 , 0 ) ;
V_614 -> V_637 = V_638 ;
F_369 ( & V_614 -> V_639 , F_71 ( V_635 ) ) ;
V_614 -> V_640 = V_635 -> V_271 ;
}
return V_597 ;
}
static bool F_370 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_641 )
{
const char * V_268 = L_23 ;
bool V_642 = false ;
struct V_643 * V_644 ;
#ifdef F_371
if ( V_645 ) {
V_268 = L_24 ;
V_642 = true ;
F_70 ( F_71 ( V_2 ) , V_646 ) ;
} else
#endif
F_70 ( F_71 ( V_2 ) , V_647 ) ;
V_644 = F_2 ( V_2 ) -> V_592 . V_648 ;
if ( ! V_644 -> V_649 && V_645 != 2 ) {
V_644 -> V_649 = 1 ;
F_372 ( L_25 ,
V_641 , F_151 ( F_6 ( V_4 ) -> V_631 ) , V_268 ) ;
}
return V_642 ;
}
static void F_373 ( const struct V_1 * V_2 ,
struct V_596 * V_597 ,
const struct V_3 * V_4 )
{
if ( F_7 ( V_2 ) -> V_650 ) {
T_1 V_10 = F_374 ( V_4 ) + F_375 ( V_4 ) ;
T_1 * V_527 ;
V_527 = F_376 ( V_10 + sizeof( T_1 ) , V_177 ) ;
if ( V_527 ) {
V_527 [ 0 ] = V_10 ;
memcpy ( & V_527 [ 1 ] , F_377 ( V_4 ) , V_10 ) ;
V_597 -> V_651 = V_527 ;
}
}
}
int F_378 ( struct V_633 * V_652 ,
const struct V_653 * V_654 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_414 V_655 ;
struct V_596 * V_597 ;
struct V_32 * V_33 = F_7 ( V_2 ) ;
struct V_29 * V_30 = NULL ;
T_3 V_656 = F_18 ( V_4 ) -> V_657 ;
bool V_642 = false , V_658 ;
struct V_659 V_660 ;
struct V_408 V_409 = { . V_10 = - 1 } ;
int V_172 ;
if ( ( V_645 == 2 ||
F_379 ( V_2 ) ) && ! V_656 ) {
V_642 = F_370 ( V_2 , V_4 , V_652 -> V_661 ) ;
if ( ! V_642 )
goto V_509;
}
if ( F_380 ( V_2 ) && F_381 ( V_2 ) > 1 ) {
F_70 ( F_71 ( V_2 ) , V_662 ) ;
goto V_509;
}
V_597 = F_365 ( V_652 , V_2 ) ;
if ( ! V_597 )
goto V_509;
F_352 ( V_597 ) -> V_663 = V_654 ;
F_340 ( & V_655 ) ;
V_655 . V_53 = V_654 -> V_53 ;
V_655 . V_426 = V_33 -> V_52 . V_426 ;
F_227 ( V_4 , & V_655 , 0 , V_642 ? NULL : & V_409 ) ;
if ( V_642 && ! V_655 . V_267 )
F_340 ( & V_655 ) ;
V_655 . V_434 = V_655 . V_267 ;
F_363 ( V_597 , & V_655 , V_4 , V_2 ) ;
F_358 ( V_597 ) -> V_664 = V_2 -> V_665 ;
V_654 -> V_666 ( V_597 , V_2 , V_4 ) ;
if ( F_382 ( V_2 , V_4 , V_597 ) )
goto V_667;
if ( ! V_642 && ! V_656 ) {
if ( V_668 . V_669 ) {
bool V_670 ;
V_30 = V_654 -> V_671 ( V_2 , & V_660 , V_597 , & V_670 ) ;
if ( V_30 && V_670 &&
! F_383 ( V_597 , V_30 , true ,
V_655 . V_267 ) ) {
F_70 ( F_71 ( V_2 ) , V_672 ) ;
goto V_673;
}
}
else if ( ! V_645 &&
( V_674 - F_384 ( V_2 ) <
( V_674 >> 2 ) ) &&
! F_383 ( V_597 , V_30 , false ,
V_655 . V_267 ) ) {
F_357 ( V_597 , F_151 ( F_6 ( V_4 ) -> V_629 ) ,
V_652 -> V_612 ) ;
goto V_673;
}
V_656 = V_654 -> V_675 ( V_4 ) ;
}
if ( ! V_30 ) {
V_30 = V_654 -> V_671 ( V_2 , & V_660 , V_597 , NULL ) ;
if ( ! V_30 )
goto V_667;
}
F_360 ( V_597 , V_4 , V_2 , V_30 ) ;
if ( V_642 ) {
V_656 = F_385 ( V_654 , V_2 , V_4 , & V_597 -> V_69 ) ;
V_597 -> V_626 = V_655 . V_434 ;
if ( ! V_655 . V_434 )
F_358 ( V_597 ) -> V_620 = 0 ;
}
F_352 ( V_597 ) -> V_676 = V_656 ;
F_386 ( V_597 , V_2 , V_30 ) ;
V_658 = ! V_642 &&
F_387 ( V_2 , V_4 , V_597 , & V_409 , V_30 ) ;
V_172 = V_654 -> V_677 ( V_2 , V_30 , & V_660 , V_597 ,
F_388 ( V_4 ) , & V_409 ) ;
if ( ! V_658 ) {
if ( V_172 || V_642 )
goto V_667;
F_352 ( V_597 ) -> V_678 = false ;
V_654 -> V_679 ( V_2 , V_597 , V_680 ) ;
}
F_373 ( V_2 , V_597 , V_4 ) ;
return 0 ;
V_673:
F_389 ( V_30 ) ;
V_667:
F_390 ( V_597 ) ;
V_509:
F_70 ( F_71 ( V_2 ) , V_681 ) ;
return 0 ;
}
