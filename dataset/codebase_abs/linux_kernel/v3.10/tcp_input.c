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
static inline bool F_11 ( const struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_8 . V_24 && ! V_6 -> V_8 . V_26 ;
}
static inline void F_12 ( struct V_29 * V_30 )
{
if ( V_30 -> V_31 & V_32 )
V_30 -> V_31 |= V_33 ;
}
static inline void F_13 ( struct V_29 * V_30 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) -> V_34 )
V_30 -> V_31 &= ~ V_35 ;
}
static inline void F_14 ( struct V_29 * V_30 )
{
V_30 -> V_31 &= ~ V_35 ;
}
static inline void F_15 ( struct V_29 * V_30 , const struct V_3 * V_4 )
{
if ( ! ( V_30 -> V_31 & V_32 ) )
return;
switch ( F_16 ( V_4 ) -> V_36 & V_37 ) {
case V_38 :
if ( V_30 -> V_31 & V_39 )
F_10 ( (struct V_1 * ) V_30 ) ;
break;
case V_40 :
if ( ! ( V_30 -> V_31 & V_35 ) ) {
F_10 ( (struct V_1 * ) V_30 ) ;
V_30 -> V_31 |= V_35 ;
}
default:
V_30 -> V_31 |= V_39 ;
}
}
static inline void F_17 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
if ( ( V_30 -> V_31 & V_32 ) && ( ! V_41 -> V_42 || V_41 -> V_34 ) )
V_30 -> V_31 &= ~ V_32 ;
}
static inline void F_18 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
if ( ( V_30 -> V_31 & V_32 ) && ( ! V_41 -> V_42 || ! V_41 -> V_34 ) )
V_30 -> V_31 &= ~ V_32 ;
}
static bool F_19 ( const struct V_29 * V_30 , const struct V_15 * V_41 )
{
if ( V_41 -> V_42 && ! V_41 -> V_43 && ( V_30 -> V_31 & V_32 ) )
return true ;
return false ;
}
static void F_20 ( struct V_1 * V_2 )
{
int V_44 = F_21 ( F_7 ( V_2 ) -> V_45 . V_46 + V_47 ) ;
V_44 *= V_48 ;
if ( V_2 -> V_49 < V_44 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
}
static int F_22 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_51 = F_23 ( V_4 -> V_51 ) >> 1 ;
int V_52 = F_23 ( V_53 [ 2 ] ) >> 1 ;
while ( V_30 -> V_54 <= V_52 ) {
if ( V_51 <= V_4 -> V_10 )
return 2 * F_2 ( V_2 ) -> V_8 . V_12 ;
V_51 >>= 1 ;
V_52 >>= 1 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_54 < V_30 -> V_55 &&
( int ) V_30 -> V_54 < F_25 ( V_2 ) &&
! F_26 ( V_2 ) ) {
int V_56 ;
if ( F_23 ( V_4 -> V_51 ) <= V_4 -> V_10 )
V_56 = 2 * V_30 -> V_57 ;
else
V_56 = F_22 ( V_2 , V_4 ) ;
if ( V_56 ) {
V_56 = F_27 ( int , V_56 , 2 * V_4 -> V_10 ) ;
V_30 -> V_54 = F_9 ( V_30 -> V_54 + V_56 ,
V_30 -> V_55 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_58 = F_7 ( V_2 ) -> V_57 ;
T_1 V_59 = V_60 ;
int V_61 ;
if ( V_58 > 1460 )
V_59 = F_27 ( T_1 , ( 1460 * V_60 ) / V_58 , 2 ) ;
V_61 = F_21 ( V_58 + V_47 ) ;
while ( F_23 ( V_61 ) < V_58 )
V_61 += 128 ;
V_61 *= V_59 ;
if ( V_2 -> V_62 < V_61 )
V_2 -> V_62 = F_9 ( V_61 , V_53 [ 2 ] ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_63 ;
if ( ! ( V_2 -> V_64 & V_65 ) )
F_28 ( V_2 ) ;
if ( ! ( V_2 -> V_64 & V_66 ) )
F_20 ( V_2 ) ;
V_30 -> V_67 . V_68 = V_30 -> V_23 ;
V_63 = F_30 ( V_2 ) ;
if ( V_30 -> V_55 >= V_63 ) {
V_30 -> V_55 = V_63 ;
if ( V_69 && V_63 > 4 * V_30 -> V_57 )
V_30 -> V_55 = F_31 ( V_63 -
( V_63 >> V_69 ) ,
4 * V_30 -> V_57 ) ;
}
if ( V_69 &&
V_30 -> V_55 > 2 * V_30 -> V_57 &&
V_30 -> V_55 + V_30 -> V_57 > V_63 )
V_30 -> V_55 = F_31 ( 2 * V_30 -> V_57 , V_63 - V_30 -> V_57 ) ;
V_30 -> V_54 = F_9 ( V_30 -> V_54 , V_30 -> V_55 ) ;
V_30 -> V_70 = V_71 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_62 < V_53 [ 2 ] &&
! ( V_2 -> V_64 & V_65 ) &&
! F_26 ( V_2 ) &&
F_33 ( V_2 ) < F_34 ( V_2 , 0 ) ) {
V_2 -> V_62 = F_9 ( F_35 ( & V_2 -> V_72 ) ,
V_53 [ 2 ] ) ;
}
if ( F_35 ( & V_2 -> V_72 ) > V_2 -> V_62 )
V_30 -> V_54 = F_9 ( V_30 -> V_55 , 2U * V_30 -> V_57 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned int V_73 = F_37 (unsigned int, tp->advmss, tp->mss_cache) ;
V_73 = F_9 ( V_73 , V_30 -> V_23 / 2 ) ;
V_73 = F_9 ( V_73 , V_14 ) ;
V_73 = F_31 ( V_73 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_73 ;
}
static void F_38 ( struct V_29 * V_30 , T_1 V_74 , int V_75 )
{
T_1 V_76 = V_30 -> V_77 . V_78 ;
long V_79 = V_74 ;
if ( V_79 == 0 )
V_79 = 1 ;
if ( V_76 != 0 ) {
if ( ! V_75 ) {
V_79 -= ( V_76 >> 3 ) ;
V_76 += V_79 ;
} else {
V_79 <<= 3 ;
if ( V_79 < V_76 )
V_76 = V_79 ;
}
} else {
V_76 = V_79 << 3 ;
}
if ( V_30 -> V_77 . V_78 != V_76 )
V_30 -> V_77 . V_78 = V_76 ;
}
static inline void F_39 ( struct V_29 * V_30 )
{
if ( V_30 -> V_77 . time == 0 )
goto V_80;
if ( F_40 ( V_30 -> V_81 , V_30 -> V_77 . V_82 ) )
return;
F_38 ( V_30 , V_71 - V_30 -> V_77 . time , 1 ) ;
V_80:
V_30 -> V_77 . V_82 = V_30 -> V_81 + V_30 -> V_23 ;
V_30 -> V_77 . time = V_71 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_83 &&
( F_16 ( V_4 ) -> V_84 -
F_16 ( V_4 ) -> V_82 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_38 ( V_30 , V_71 - V_30 -> V_45 . V_83 , 0 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int time ;
int V_68 ;
if ( V_30 -> V_67 . time == 0 )
goto V_80;
time = V_71 - V_30 -> V_67 . time ;
if ( time < ( V_30 -> V_77 . V_78 >> 3 ) || V_30 -> V_77 . V_78 == 0 )
return;
V_68 = 2 * ( V_30 -> V_85 - V_30 -> V_67 . V_82 ) ;
V_68 = F_31 ( V_30 -> V_67 . V_68 , V_68 ) ;
if ( V_30 -> V_67 . V_68 != V_68 ) {
int V_61 ;
V_30 -> V_67 . V_68 = V_68 ;
if ( V_86 &&
! ( V_2 -> V_64 & V_65 ) ) {
int V_87 = V_68 ;
V_68 /= V_30 -> V_57 ;
if ( ! V_68 )
V_68 = 1 ;
V_61 = F_21 ( V_30 -> V_57 + V_47 ) ;
while ( F_23 ( V_61 ) < V_30 -> V_57 )
V_61 += 128 ;
V_68 *= V_61 ;
V_68 = F_9 ( V_68 , V_53 [ 2 ] ) ;
if ( V_68 > V_2 -> V_62 ) {
V_2 -> V_62 = V_68 ;
V_30 -> V_55 = V_87 ;
}
}
}
V_80:
V_30 -> V_67 . V_82 = V_30 -> V_85 ;
V_30 -> V_67 . time = V_71 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_88 ;
F_44 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_39 ( V_30 ) ;
V_88 = V_71 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_79 = V_88 - V_6 -> V_8 . V_89 ;
if ( V_79 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_79 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_79 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_90 )
V_6 -> V_8 . V_27 = V_6 -> V_90 ;
} else if ( V_79 > V_6 -> V_90 ) {
F_8 ( V_2 ) ;
F_45 ( V_2 ) ;
}
}
V_6 -> V_8 . V_89 = V_88 ;
F_15 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_24 ( V_2 , V_4 ) ;
}
static void F_46 ( struct V_1 * V_2 , const T_2 V_91 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_79 = V_91 ;
if ( V_79 == 0 )
V_79 = 1 ;
if ( V_30 -> V_92 != 0 ) {
V_79 -= ( V_30 -> V_92 >> 3 ) ;
V_30 -> V_92 += V_79 ;
if ( V_79 < 0 ) {
V_79 = - V_79 ;
V_79 -= ( V_30 -> V_93 >> 2 ) ;
if ( V_79 > 0 )
V_79 >>= 3 ;
} else {
V_79 -= ( V_30 -> V_93 >> 2 ) ;
}
V_30 -> V_93 += V_79 ;
if ( V_30 -> V_93 > V_30 -> V_94 ) {
V_30 -> V_94 = V_30 -> V_93 ;
if ( V_30 -> V_94 > V_30 -> V_95 )
V_30 -> V_95 = V_30 -> V_94 ;
}
if ( F_47 ( V_30 -> V_96 , V_30 -> V_97 ) ) {
if ( V_30 -> V_94 < V_30 -> V_95 )
V_30 -> V_95 -= ( V_30 -> V_95 - V_30 -> V_94 ) >> 2 ;
V_30 -> V_97 = V_30 -> V_98 ;
V_30 -> V_94 = F_48 ( V_2 ) ;
}
} else {
V_30 -> V_92 = V_79 << 3 ;
V_30 -> V_93 = V_79 << 1 ;
V_30 -> V_94 = V_30 -> V_95 = F_31 ( V_30 -> V_93 , F_48 ( V_2 ) ) ;
V_30 -> V_97 = V_30 -> V_98 ;
}
}
void F_49 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_90 = F_50 ( V_30 ) ;
F_51 ( V_2 ) ;
}
T_2 F_52 ( const struct V_29 * V_30 , const struct V_99 * V_100 )
{
T_2 V_101 = ( V_100 ? F_53 ( V_100 , V_102 ) : 0 ) ;
if ( ! V_101 )
V_101 = V_48 ;
return F_37 ( T_2 , V_101 , V_30 -> V_103 ) ;
}
void F_54 ( struct V_29 * V_30 )
{
if ( F_55 ( V_30 ) )
V_30 -> V_104 = NULL ;
V_30 -> V_45 . V_105 &= ~ V_106 ;
}
static void F_56 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_105 |= V_107 ;
}
static void F_57 ( struct V_1 * V_2 , const int V_108 ,
const int V_109 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_108 > V_30 -> V_110 ) {
int V_111 ;
V_30 -> V_110 = F_9 ( V_112 , V_108 ) ;
if ( V_109 )
V_111 = V_113 ;
else if ( F_58 ( V_30 ) )
V_111 = V_114 ;
else if ( F_55 ( V_30 ) )
V_111 = V_115 ;
else
V_111 = V_116 ;
F_59 ( F_60 ( V_2 ) , V_111 ) ;
#if V_117 > 1
F_61 ( L_1 ,
V_30 -> V_45 . V_105 , F_2 ( V_2 ) -> V_118 ,
V_30 -> V_110 ,
V_30 -> V_119 ,
V_30 -> V_120 ,
V_30 -> V_121 ? V_30 -> V_122 : 0 ) ;
#endif
F_54 ( V_30 ) ;
}
if ( V_108 > 0 )
F_62 ( V_30 ) ;
}
static void F_63 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_123 == NULL ) ||
F_40 ( F_16 ( V_4 ) -> V_82 ,
F_16 ( V_30 -> V_123 ) -> V_82 ) )
V_30 -> V_123 = V_4 ;
if ( ! V_30 -> V_124 ||
F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_125 ) )
V_30 -> V_125 = F_16 ( V_4 ) -> V_84 ;
}
static void F_64 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_126 & ( V_127 | V_128 ) ) ) {
F_63 ( V_30 , V_4 ) ;
V_30 -> V_124 += F_65 ( V_4 ) ;
F_16 ( V_4 ) -> V_126 |= V_127 ;
}
}
static void F_66 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_63 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_126 & ( V_127 | V_128 ) ) ) {
V_30 -> V_124 += F_65 ( V_4 ) ;
F_16 ( V_4 ) -> V_126 |= V_127 ;
}
}
static bool F_67 ( struct V_29 * V_30 , bool V_129 ,
T_1 V_130 , T_1 V_84 )
{
if ( F_47 ( V_84 , V_30 -> V_98 ) || ! F_40 ( V_130 , V_84 ) )
return false ;
if ( ! F_40 ( V_130 , V_30 -> V_98 ) )
return false ;
if ( F_47 ( V_130 , V_30 -> V_96 ) )
return true ;
if ( ! V_129 || ! V_30 -> V_121 )
return false ;
if ( F_47 ( V_84 , V_30 -> V_96 ) )
return false ;
if ( ! F_40 ( V_130 , V_30 -> V_121 ) )
return true ;
if ( ! F_47 ( V_84 , V_30 -> V_121 ) )
return false ;
return ! F_40 ( V_130 , V_84 - V_30 -> V_131 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_132 = 0 ;
T_1 V_133 = V_30 -> V_98 ;
T_1 V_134 = F_69 ( V_30 ) ;
if ( ! F_55 ( V_30 ) || ! V_30 -> V_135 ||
! F_47 ( V_134 , V_30 -> V_136 ) ||
V_6 -> V_118 != V_137 )
return;
F_70 (skb, sk) {
T_1 V_138 = F_16 ( V_4 ) -> V_138 ;
if ( V_4 == F_71 ( V_2 ) )
break;
if ( V_132 == V_30 -> V_135 )
break;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_126 & V_139 ) )
continue;
if ( F_47 ( V_134 , V_138 ) ) {
F_16 ( V_4 ) -> V_126 &= ~ V_139 ;
V_30 -> V_135 -= F_65 ( V_4 ) ;
F_66 ( V_30 , V_4 ) ;
F_59 ( F_60 ( V_2 ) , V_140 ) ;
} else {
if ( F_40 ( V_138 , V_133 ) )
V_133 = V_138 ;
V_132 += F_65 ( V_4 ) ;
}
}
if ( V_30 -> V_135 )
V_30 -> V_136 = V_133 ;
}
static bool F_72 ( struct V_1 * V_2 , const struct V_3 * V_141 ,
struct V_142 * V_143 , int V_144 ,
T_1 V_145 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_146 = F_73 ( & V_143 [ 0 ] . V_130 ) ;
T_1 V_147 = F_73 ( & V_143 [ 0 ] . V_84 ) ;
bool V_148 = false ;
if ( F_40 ( V_146 , F_16 ( V_141 ) -> V_138 ) ) {
V_148 = true ;
F_56 ( V_30 ) ;
F_59 ( F_60 ( V_2 ) , V_149 ) ;
} else if ( V_144 > 1 ) {
T_1 V_150 = F_73 ( & V_143 [ 1 ] . V_84 ) ;
T_1 V_151 = F_73 ( & V_143 [ 1 ] . V_130 ) ;
if ( ! F_47 ( V_147 , V_150 ) &&
! F_40 ( V_146 , V_151 ) ) {
V_148 = true ;
F_56 ( V_30 ) ;
F_59 ( F_60 ( V_2 ) ,
V_152 ) ;
}
}
if ( V_148 && V_30 -> V_121 && V_30 -> V_122 &&
! F_47 ( V_147 , V_145 ) &&
F_47 ( V_147 , V_30 -> V_121 ) )
V_30 -> V_122 -- ;
return V_148 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_130 , T_1 V_84 )
{
int V_153 ;
bool V_154 ;
unsigned int V_155 ;
unsigned int V_58 ;
V_154 = ! F_47 ( V_130 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( F_65 ( V_4 ) > 1 && ! V_154 &&
F_47 ( F_16 ( V_4 ) -> V_84 , V_130 ) ) {
V_58 = F_75 ( V_4 ) ;
V_154 = ! F_47 ( V_130 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_154 ) {
V_155 = V_130 - F_16 ( V_4 ) -> V_82 ;
if ( V_155 < V_58 )
V_155 = V_58 ;
} else {
V_155 = V_84 - F_16 ( V_4 ) -> V_82 ;
if ( V_155 < V_58 )
return - V_156 ;
}
if ( V_155 > V_58 ) {
unsigned int V_157 = ( V_155 / V_58 ) * V_58 ;
if ( ! V_154 && V_157 < V_155 ) {
V_157 += V_58 ;
if ( V_157 > V_4 -> V_10 )
return 0 ;
}
V_155 = V_157 ;
}
V_153 = F_76 ( V_2 , V_4 , V_155 , V_58 ) ;
if ( V_153 < 0 )
return V_153 ;
}
return V_154 ;
}
static T_3 F_77 ( struct V_1 * V_2 ,
struct V_158 * V_159 , T_3 V_126 ,
T_1 V_130 , T_1 V_84 ,
bool V_148 , int V_160 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_161 = V_159 -> V_161 ;
if ( V_148 && ( V_126 & V_162 ) ) {
if ( V_30 -> V_121 && V_30 -> V_122 &&
F_47 ( V_84 , V_30 -> V_121 ) )
V_30 -> V_122 -- ;
if ( V_126 & V_128 )
V_159 -> V_163 = F_9 ( V_161 , V_159 -> V_163 ) ;
}
if ( ! F_47 ( V_84 , V_30 -> V_96 ) )
return V_126 ;
if ( ! ( V_126 & V_128 ) ) {
if ( V_126 & V_139 ) {
if ( V_126 & V_127 ) {
V_126 &= ~ ( V_127 | V_139 ) ;
V_30 -> V_124 -= V_160 ;
V_30 -> V_135 -= V_160 ;
}
} else {
if ( ! ( V_126 & V_162 ) ) {
if ( F_40 ( V_130 ,
F_69 ( V_30 ) ) )
V_159 -> V_163 = F_9 ( V_161 ,
V_159 -> V_163 ) ;
if ( ! F_47 ( V_84 , V_30 -> V_164 ) )
V_159 -> V_165 |= V_166 ;
}
if ( V_126 & V_127 ) {
V_126 &= ~ V_127 ;
V_30 -> V_124 -= V_160 ;
}
}
V_126 |= V_128 ;
V_159 -> V_165 |= V_167 ;
V_30 -> V_120 += V_160 ;
V_161 += V_160 ;
if ( ! F_55 ( V_30 ) && ( V_30 -> V_104 != NULL ) &&
F_40 ( V_130 , F_16 ( V_30 -> V_104 ) -> V_82 ) )
V_30 -> V_168 += V_160 ;
if ( V_161 > V_30 -> V_119 )
V_30 -> V_119 = V_161 ;
}
if ( V_148 && ( V_126 & V_139 ) ) {
V_126 &= ~ V_139 ;
V_30 -> V_135 -= V_160 ;
}
return V_126 ;
}
static bool F_78 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_158 * V_159 ,
unsigned int V_160 , int V_169 , int V_58 ,
bool V_148 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_170 = F_79 ( V_2 , V_4 ) ;
T_1 V_130 = F_16 ( V_4 ) -> V_82 ;
T_1 V_84 = V_130 + V_169 ;
F_80 ( ! V_160 ) ;
F_77 ( V_2 , V_159 , F_16 ( V_4 ) -> V_126 ,
V_130 , V_84 , V_148 , V_160 ) ;
if ( V_4 == V_30 -> V_104 )
V_30 -> V_168 += V_160 ;
F_16 ( V_170 ) -> V_84 += V_169 ;
F_16 ( V_4 ) -> V_82 += V_169 ;
F_3 ( V_170 ) -> V_171 += V_160 ;
F_80 ( F_3 ( V_4 ) -> V_171 < V_160 ) ;
F_3 ( V_4 ) -> V_171 -= V_160 ;
if ( ! F_3 ( V_170 ) -> V_11 ) {
F_3 ( V_170 ) -> V_11 = V_58 ;
F_3 ( V_170 ) -> V_172 = V_2 -> V_173 ;
}
if ( F_3 ( V_4 ) -> V_171 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_172 = 0 ;
}
F_16 ( V_170 ) -> V_126 |= ( F_16 ( V_4 ) -> V_126 & V_174 ) ;
if ( V_4 -> V_10 > 0 ) {
F_80 ( ! F_65 ( V_4 ) ) ;
F_59 ( F_60 ( V_2 ) , V_175 ) ;
return false ;
}
if ( V_4 == V_30 -> V_123 )
V_30 -> V_123 = V_170 ;
if ( V_4 == V_30 -> V_176 )
V_30 -> V_176 = V_170 ;
if ( V_4 == V_30 -> V_104 ) {
V_30 -> V_104 = V_170 ;
V_30 -> V_168 -= F_65 ( V_170 ) ;
}
F_16 ( V_4 ) -> V_177 |= F_16 ( V_170 ) -> V_177 ;
if ( V_4 == F_81 ( V_2 ) )
F_82 ( V_2 , V_4 ) ;
F_83 ( V_4 , V_2 ) ;
F_84 ( V_2 , V_4 ) ;
F_59 ( F_60 ( V_2 ) , V_178 ) ;
return true ;
}
static int F_85 ( const struct V_3 * V_4 )
{
return F_65 ( V_4 ) == 1 ? V_4 -> V_10 : F_75 ( V_4 ) ;
}
static int F_86 ( const struct V_3 * V_4 )
{
return ! F_87 ( V_4 ) && F_88 ( V_4 ) ;
}
static struct V_3 * F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_158 * V_159 ,
T_1 V_130 , T_1 V_84 ,
bool V_148 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_170 ;
int V_58 ;
int V_160 = 0 ;
int V_10 ;
int V_154 ;
if ( ! F_90 ( V_2 ) )
goto V_179;
if ( ! V_148 &&
( F_16 ( V_4 ) -> V_126 & ( V_127 | V_139 ) ) == V_139 )
goto V_179;
if ( ! F_86 ( V_4 ) )
goto V_179;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
goto V_179;
if ( F_91 ( V_4 == F_92 ( V_2 ) ) )
goto V_179;
V_170 = F_79 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_170 ) -> V_126 & V_180 ) != V_128 )
goto V_179;
V_154 = ! F_47 ( V_130 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( V_154 ) {
V_10 = V_4 -> V_10 ;
V_160 = F_65 ( V_4 ) ;
V_58 = F_85 ( V_4 ) ;
if ( V_58 != F_85 ( V_170 ) )
goto V_179;
} else {
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_130 ) )
goto V_181;
if ( F_65 ( V_4 ) <= 1 )
goto V_181;
V_154 = ! F_47 ( V_130 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_154 ) {
goto V_179;
}
V_10 = V_84 - F_16 ( V_4 ) -> V_82 ;
F_80 ( V_10 < 0 ) ;
F_80 ( V_10 > V_4 -> V_10 ) ;
V_58 = F_75 ( V_4 ) ;
if ( V_58 != F_85 ( V_170 ) )
goto V_179;
if ( V_10 == V_58 ) {
V_160 = 1 ;
} else if ( V_10 < V_58 ) {
goto V_181;
} else {
V_160 = V_10 / V_58 ;
V_10 = V_160 * V_58 ;
}
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_82 + V_10 , V_30 -> V_96 ) )
goto V_179;
if ( ! F_93 ( V_170 , V_4 , V_10 ) )
goto V_179;
if ( ! F_78 ( V_2 , V_4 , V_159 , V_160 , V_10 , V_58 , V_148 ) )
goto V_182;
if ( V_170 == F_94 ( V_2 ) )
goto V_182;
V_4 = F_95 ( V_2 , V_170 ) ;
if ( ! F_86 ( V_4 ) ||
( V_4 == F_71 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_126 & V_180 ) != V_128 ) ||
( V_58 != F_85 ( V_4 ) ) )
goto V_182;
V_10 = V_4 -> V_10 ;
if ( F_93 ( V_170 , V_4 , V_10 ) ) {
V_160 += F_65 ( V_4 ) ;
F_78 ( V_2 , V_4 , V_159 , F_65 ( V_4 ) , V_10 , V_58 , 0 ) ;
}
V_182:
V_159 -> V_161 += V_160 ;
return V_170 ;
V_181:
return V_4 ;
V_179:
F_59 ( F_60 ( V_2 ) , V_183 ) ;
return NULL ;
}
static struct V_3 * F_96 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_184 * V_185 ,
struct V_158 * V_159 ,
T_1 V_130 , T_1 V_84 ,
bool V_186 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_187 ;
F_97 (skb, sk) {
int V_154 = 0 ;
bool V_148 = V_186 ;
if ( V_4 == F_71 ( V_2 ) )
break;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_84 ) )
break;
if ( ( V_185 != NULL ) &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_185 -> V_84 ) ) {
V_154 = F_74 ( V_2 , V_4 ,
V_185 -> V_130 ,
V_185 -> V_84 ) ;
if ( V_154 > 0 )
V_148 = true ;
}
if ( V_154 <= 0 ) {
V_187 = F_89 ( V_2 , V_4 , V_159 ,
V_130 , V_84 , V_148 ) ;
if ( V_187 != NULL ) {
if ( V_187 != V_4 ) {
V_4 = V_187 ;
continue;
}
V_154 = 0 ;
} else {
V_154 = F_74 ( V_2 , V_4 ,
V_130 ,
V_84 ) ;
}
}
if ( F_91 ( V_154 < 0 ) )
break;
if ( V_154 ) {
F_16 ( V_4 ) -> V_126 =
F_77 ( V_2 ,
V_159 ,
F_16 ( V_4 ) -> V_126 ,
F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ,
V_148 ,
F_65 ( V_4 ) ) ;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 ,
F_69 ( V_30 ) ) )
F_82 ( V_2 , V_4 ) ;
}
V_159 -> V_161 += F_65 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_98 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_158 * V_159 ,
T_1 V_188 )
{
F_97 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_188 ) )
break;
V_159 -> V_161 += F_65 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_99 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_184 * V_185 ,
struct V_158 * V_159 ,
T_1 V_188 )
{
if ( V_185 == NULL )
return V_4 ;
if ( F_40 ( V_185 -> V_130 , V_188 ) ) {
V_4 = F_98 ( V_4 , V_2 , V_159 , V_185 -> V_130 ) ;
V_4 = F_96 ( V_4 , V_2 , NULL , V_159 ,
V_185 -> V_130 , V_185 -> V_84 ,
1 ) ;
}
return V_4 ;
}
static int F_100 ( const struct V_29 * V_30 , const struct V_184 * V_189 )
{
return V_189 < V_30 -> V_190 + F_101 ( V_30 -> V_190 ) ;
}
static int
F_102 ( struct V_1 * V_2 , const struct V_3 * V_141 ,
T_1 V_145 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_191 = ( F_4 ( V_141 ) +
F_16 ( V_141 ) -> V_126 ) ;
struct V_142 * V_192 = (struct V_142 * ) ( V_191 + 2 ) ;
struct V_184 V_143 [ V_193 ] ;
struct V_184 * V_189 ;
struct V_158 V_159 ;
struct V_3 * V_4 ;
int V_144 = F_9 ( V_193 , ( V_191 [ 1 ] - V_194 ) >> 3 ) ;
int V_195 ;
bool V_196 = false ;
int V_197 , V_198 ;
int V_199 ;
V_159 . V_165 = 0 ;
V_159 . V_163 = V_30 -> V_200 ;
if ( ! V_30 -> V_120 ) {
if ( F_103 ( V_30 -> V_119 ) )
V_30 -> V_119 = 0 ;
F_104 ( V_2 ) ;
}
V_196 = F_72 ( V_2 , V_141 , V_192 ,
V_144 , V_145 ) ;
if ( V_196 )
V_159 . V_165 |= V_201 ;
if ( F_40 ( F_16 ( V_141 ) -> V_138 , V_145 - V_30 -> V_131 ) )
return 0 ;
if ( ! V_30 -> V_200 )
goto V_182;
V_195 = 0 ;
V_199 = 0 ;
for ( V_197 = 0 ; V_197 < V_144 ; V_197 ++ ) {
bool V_148 = ! V_197 && V_196 ;
V_143 [ V_195 ] . V_130 = F_73 ( & V_192 [ V_197 ] . V_130 ) ;
V_143 [ V_195 ] . V_84 = F_73 ( & V_192 [ V_197 ] . V_84 ) ;
if ( ! F_67 ( V_30 , V_148 ,
V_143 [ V_195 ] . V_130 ,
V_143 [ V_195 ] . V_84 ) ) {
int V_111 ;
if ( V_148 ) {
if ( ! V_30 -> V_121 )
V_111 = V_202 ;
else
V_111 = V_203 ;
} else {
if ( ( F_16 ( V_141 ) -> V_138 != V_30 -> V_96 ) &&
! F_47 ( V_143 [ V_195 ] . V_84 , V_30 -> V_96 ) )
continue;
V_111 = V_204 ;
}
F_59 ( F_60 ( V_2 ) , V_111 ) ;
if ( V_197 == 0 )
V_199 = - 1 ;
continue;
}
if ( ! F_47 ( V_143 [ V_195 ] . V_84 , V_145 ) )
continue;
V_195 ++ ;
}
for ( V_197 = V_195 - 1 ; V_197 > 0 ; V_197 -- ) {
for ( V_198 = 0 ; V_198 < V_197 ; V_198 ++ ) {
if ( F_47 ( V_143 [ V_198 ] . V_130 , V_143 [ V_198 + 1 ] . V_130 ) ) {
F_105 ( V_143 [ V_198 ] , V_143 [ V_198 + 1 ] ) ;
if ( V_198 == V_199 )
V_199 = V_198 + 1 ;
}
}
}
V_4 = F_92 ( V_2 ) ;
V_159 . V_161 = 0 ;
V_197 = 0 ;
if ( ! V_30 -> V_120 ) {
V_189 = V_30 -> V_190 + F_101 ( V_30 -> V_190 ) ;
} else {
V_189 = V_30 -> V_190 ;
while ( F_100 ( V_30 , V_189 ) && ! V_189 -> V_130 &&
! V_189 -> V_84 )
V_189 ++ ;
}
while ( V_197 < V_195 ) {
T_1 V_130 = V_143 [ V_197 ] . V_130 ;
T_1 V_84 = V_143 [ V_197 ] . V_84 ;
bool V_148 = ( V_196 && ( V_197 == V_199 ) ) ;
struct V_184 * V_185 = NULL ;
if ( V_196 && ( ( V_197 + 1 ) == V_199 ) )
V_185 = & V_143 [ V_197 + 1 ] ;
while ( F_100 ( V_30 , V_189 ) &&
! F_40 ( V_130 , V_189 -> V_84 ) )
V_189 ++ ;
if ( F_100 ( V_30 , V_189 ) && ! V_148 &&
F_47 ( V_84 , V_189 -> V_130 ) ) {
if ( F_40 ( V_130 , V_189 -> V_130 ) ) {
V_4 = F_98 ( V_4 , V_2 , & V_159 ,
V_130 ) ;
V_4 = F_96 ( V_4 , V_2 , V_185 ,
& V_159 ,
V_130 ,
V_189 -> V_130 ,
V_148 ) ;
}
if ( ! F_47 ( V_84 , V_189 -> V_84 ) )
goto V_205;
V_4 = F_99 ( V_4 , V_2 , V_185 ,
& V_159 ,
V_189 -> V_84 ) ;
if ( F_69 ( V_30 ) == V_189 -> V_84 ) {
V_4 = F_81 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_159 . V_161 = V_30 -> V_119 ;
V_189 ++ ;
goto V_206;
}
V_4 = F_98 ( V_4 , V_2 , & V_159 , V_189 -> V_84 ) ;
V_189 ++ ;
continue;
}
if ( ! F_40 ( V_130 , F_69 ( V_30 ) ) ) {
V_4 = F_81 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_159 . V_161 = V_30 -> V_119 ;
}
V_4 = F_98 ( V_4 , V_2 , & V_159 , V_130 ) ;
V_206:
V_4 = F_96 ( V_4 , V_2 , V_185 , & V_159 ,
V_130 , V_84 , V_148 ) ;
V_205:
V_197 ++ ;
}
for ( V_197 = 0 ; V_197 < F_101 ( V_30 -> V_190 ) - V_195 ; V_197 ++ ) {
V_30 -> V_190 [ V_197 ] . V_130 = 0 ;
V_30 -> V_190 [ V_197 ] . V_84 = 0 ;
}
for ( V_198 = 0 ; V_198 < V_195 ; V_198 ++ )
V_30 -> V_190 [ V_197 ++ ] = V_143 [ V_198 ] ;
F_68 ( V_2 ) ;
F_106 ( V_30 ) ;
if ( ( V_159 . V_163 < V_30 -> V_119 ) &&
( ( F_2 ( V_2 ) -> V_118 != V_207 ) || V_30 -> V_121 ) )
F_57 ( V_2 , V_30 -> V_119 - V_159 . V_163 , 0 ) ;
V_182:
#if V_117 > 0
F_103 ( ( int ) V_30 -> V_120 < 0 ) ;
F_103 ( ( int ) V_30 -> V_124 < 0 ) ;
F_103 ( ( int ) V_30 -> V_135 < 0 ) ;
F_103 ( ( int ) F_107 ( V_30 ) < 0 ) ;
#endif
return V_159 . V_165 ;
}
static bool F_108 ( struct V_29 * V_30 )
{
T_1 V_208 ;
V_208 = F_31 ( V_30 -> V_124 , 1U ) ;
V_208 = F_9 ( V_208 , V_30 -> V_200 ) ;
if ( ( V_30 -> V_120 + V_208 ) > V_30 -> V_200 ) {
V_30 -> V_120 = V_30 -> V_200 - V_208 ;
return true ;
}
return false ;
}
static void F_109 ( struct V_1 * V_2 , const int V_209 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_108 ( V_30 ) )
F_57 ( V_2 , V_30 -> V_200 + V_209 , 0 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_120 ++ ;
F_109 ( V_2 , 0 ) ;
F_106 ( V_30 ) ;
}
static void F_111 ( struct V_1 * V_2 , int V_210 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_210 > 0 ) {
if ( V_210 - 1 >= V_30 -> V_120 )
V_30 -> V_120 = 0 ;
else
V_30 -> V_120 -= V_210 - 1 ;
}
F_109 ( V_2 , V_210 ) ;
F_106 ( V_30 ) ;
}
static inline void F_112 ( struct V_29 * V_30 )
{
V_30 -> V_120 = 0 ;
}
static void F_113 ( struct V_29 * V_30 )
{
V_30 -> V_135 = 0 ;
V_30 -> V_124 = 0 ;
V_30 -> V_121 = 0 ;
V_30 -> V_122 = 0 ;
}
void F_114 ( struct V_29 * V_30 )
{
F_113 ( V_30 ) ;
V_30 -> V_119 = 0 ;
V_30 -> V_120 = 0 ;
}
void F_115 ( struct V_1 * V_2 , int V_211 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_212 = false ;
if ( V_6 -> V_118 <= V_213 ||
! F_47 ( V_30 -> V_164 , V_30 -> V_96 ) ||
( V_6 -> V_118 == V_207 && ! V_6 -> V_214 ) ) {
V_212 = true ;
V_30 -> V_215 = F_116 ( V_2 ) ;
V_30 -> V_216 = V_6 -> V_217 -> V_218 ( V_2 ) ;
F_117 ( V_2 , V_219 ) ;
}
V_30 -> V_220 = 1 ;
V_30 -> V_221 = 0 ;
V_30 -> V_70 = V_71 ;
F_113 ( V_30 ) ;
if ( F_58 ( V_30 ) )
F_112 ( V_30 ) ;
V_30 -> V_121 = V_30 -> V_96 ;
if ( V_211 ) {
V_30 -> V_120 = 0 ;
V_30 -> V_119 = 0 ;
}
F_118 ( V_30 ) ;
F_70 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_126 & V_162 )
V_30 -> V_121 = 0 ;
F_16 ( V_4 ) -> V_126 &= ( ~ V_180 ) | V_128 ;
if ( ! ( F_16 ( V_4 ) -> V_126 & V_128 ) || V_211 ) {
F_16 ( V_4 ) -> V_126 &= ~ V_128 ;
F_16 ( V_4 ) -> V_126 |= V_127 ;
V_30 -> V_124 += F_65 ( V_4 ) ;
V_30 -> V_125 = F_16 ( V_4 ) -> V_84 ;
}
}
F_106 ( V_30 ) ;
V_30 -> V_110 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_119 ( V_2 , V_207 ) ;
V_30 -> V_164 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
V_30 -> V_222 = V_223 &&
( V_212 || V_6 -> V_214 ) &&
! F_2 ( V_2 ) -> V_224 . V_225 ;
}
static bool F_120 ( struct V_1 * V_2 , int V_165 )
{
if ( V_165 & V_226 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_59 ( F_60 ( V_2 ) , V_227 ) ;
F_115 ( V_2 , 1 ) ;
V_6 -> V_214 ++ ;
F_121 ( V_2 , F_92 ( V_2 ) ) ;
F_122 ( V_2 , V_228 ,
V_6 -> V_90 , V_229 ) ;
return true ;
}
return false ;
}
static inline int F_123 ( const struct V_29 * V_30 )
{
return F_58 ( V_30 ) ? V_30 -> V_120 + 1 : V_30 -> V_119 ;
}
static inline int F_124 ( const struct V_29 * V_30 )
{
return F_55 ( V_30 ) ? V_30 -> V_119 : V_30 -> V_120 + 1 ;
}
static bool F_125 ( struct V_1 * V_2 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_230 ;
if ( V_231 < 2 || V_231 > 3 ||
( V_165 & V_232 ) || ! V_30 -> V_92 )
return false ;
V_230 = F_27 (unsigned long, (tp->srtt >> 5), msecs_to_jiffies(2)) ;
if ( ! F_126 ( F_2 ( V_2 ) -> V_233 , ( V_234 + V_230 ) ) )
return false ;
F_122 ( V_2 , V_235 , V_230 ,
V_229 ) ;
return true ;
}
static inline int F_127 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_71 - F_16 ( V_4 ) -> V_236 > F_2 ( V_2 ) -> V_90 ;
}
static inline int F_128 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_200 &&
F_127 ( V_2 , F_92 ( V_2 ) ) ;
}
static bool F_129 ( struct V_1 * V_2 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_200 ;
if ( V_30 -> V_124 )
return true ;
if ( F_124 ( V_30 ) > V_30 -> V_110 )
return true ;
if ( F_55 ( V_30 ) && F_128 ( V_2 ) )
return true ;
V_200 = V_30 -> V_200 ;
if ( V_200 <= V_30 -> V_110 &&
V_30 -> V_120 >= F_27 ( T_2 , V_200 / 2 , V_237 ) &&
! F_130 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_238 || V_239 ) &&
F_131 ( V_30 ) && F_124 ( V_30 ) > 1 &&
F_132 ( V_30 ) && ! F_71 ( V_2 ) )
return true ;
if ( V_30 -> V_240 && ! V_30 -> V_135 && V_30 -> V_120 &&
( V_30 -> V_200 >= ( V_30 -> V_120 + 1 ) && V_30 -> V_200 < 4 ) &&
! F_130 ( V_2 ) )
return ! F_125 ( V_2 , V_165 ) ;
return false ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_55 ( V_30 ) || ! F_128 ( V_2 ) )
return;
V_4 = V_30 -> V_176 ;
if ( V_30 -> V_176 == NULL )
V_4 = F_92 ( V_2 ) ;
F_97 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
if ( ! F_127 ( V_2 , V_4 ) )
break;
F_64 ( V_30 , V_4 ) ;
}
V_30 -> V_176 = V_4 ;
F_106 ( V_30 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_241 , int V_242 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_132 , V_243 ;
int V_153 ;
unsigned int V_58 ;
const T_1 V_244 = F_132 ( V_30 ) ? V_30 -> V_98 : V_30 -> V_164 ;
F_103 ( V_241 > V_30 -> V_200 ) ;
if ( V_30 -> V_104 ) {
V_4 = V_30 -> V_104 ;
V_132 = V_30 -> V_168 ;
if ( V_242 && V_4 != F_92 ( V_2 ) )
return;
} else {
V_4 = F_92 ( V_2 ) ;
V_132 = 0 ;
}
F_97 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
V_30 -> V_104 = V_4 ;
V_30 -> V_168 = V_132 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_244 ) )
break;
V_243 = V_132 ;
if ( F_55 ( V_30 ) || F_58 ( V_30 ) ||
( F_16 ( V_4 ) -> V_126 & V_128 ) )
V_132 += F_65 ( V_4 ) ;
if ( V_132 > V_241 ) {
if ( ( F_132 ( V_30 ) && ! F_55 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_126 & V_128 ) ||
( V_243 >= V_241 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_153 = F_76 ( V_2 , V_4 , ( V_241 - V_243 ) * V_58 , V_58 ) ;
if ( V_153 < 0 )
break;
V_132 = V_241 ;
}
F_64 ( V_30 , V_4 ) ;
if ( V_242 )
break;
}
F_106 ( V_30 ) ;
}
static void F_135 ( struct V_1 * V_2 , int V_245 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_58 ( V_30 ) ) {
F_134 ( V_2 , 1 , 1 ) ;
} else if ( F_55 ( V_30 ) ) {
int V_246 = V_30 -> V_119 - V_30 -> V_110 ;
if ( V_246 <= 0 )
V_246 = 1 ;
F_134 ( V_2 , V_246 , 0 ) ;
} else {
int V_247 = V_30 -> V_120 - V_30 -> V_110 ;
if ( V_247 >= 0 )
F_134 ( V_2 , V_247 , 0 ) ;
else if ( V_245 )
F_134 ( V_2 , 1 , 1 ) ;
}
F_133 ( V_2 ) ;
}
static inline void F_136 ( struct V_29 * V_30 )
{
V_30 -> V_220 = F_9 ( V_30 -> V_220 ,
F_107 ( V_30 ) + F_137 ( V_30 ) ) ;
V_30 -> V_70 = V_71 ;
}
static inline bool F_138 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_248 ||
( V_30 -> V_45 . V_249 && V_30 -> V_45 . V_83 &&
F_40 ( V_30 -> V_45 . V_83 , V_30 -> V_248 ) ) ;
}
static void F_139 ( struct V_1 * V_2 , const char * V_250 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_251 * V_252 = F_140 ( V_2 ) ;
if ( V_2 -> V_253 == V_254 ) {
F_61 ( L_2 ,
V_250 ,
& V_252 -> V_255 , F_141 ( V_252 -> V_256 ) ,
V_30 -> V_220 , F_142 ( V_30 ) ,
V_30 -> V_216 , V_30 -> V_215 ,
V_30 -> V_200 ) ;
}
#if F_143 ( V_257 )
else if ( V_2 -> V_253 == V_258 ) {
struct V_259 * V_260 = F_144 ( V_2 ) ;
F_61 ( L_3 ,
V_250 ,
& V_260 -> V_261 , F_141 ( V_252 -> V_256 ) ,
V_30 -> V_220 , F_142 ( V_30 ) ,
V_30 -> V_216 , V_30 -> V_215 ,
V_30 -> V_200 ) ;
}
#endif
}
static void F_145 ( struct V_1 * V_2 , const bool V_262 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_215 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_217 -> V_263 )
V_30 -> V_220 = V_6 -> V_217 -> V_263 ( V_2 ) ;
else
V_30 -> V_220 = F_31 ( V_30 -> V_220 , V_30 -> V_216 << 1 ) ;
if ( V_262 && V_30 -> V_215 > V_30 -> V_216 ) {
V_30 -> V_216 = V_30 -> V_215 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_220 = F_31 ( V_30 -> V_220 , V_30 -> V_216 ) ;
}
V_30 -> V_70 = V_71 ;
}
static inline bool F_146 ( const struct V_29 * V_30 )
{
return V_30 -> V_121 && ( ! V_30 -> V_122 || F_138 ( V_30 ) ) ;
}
static bool F_147 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_146 ( V_30 ) ) {
int V_111 ;
F_139 ( V_2 , F_2 ( V_2 ) -> V_118 == V_207 ? L_4 : L_5 ) ;
F_145 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_118 == V_207 )
V_111 = V_264 ;
else
V_111 = V_265 ;
F_59 ( F_60 ( V_2 ) , V_111 ) ;
V_30 -> V_121 = 0 ;
}
if ( V_30 -> V_96 == V_30 -> V_164 && F_58 ( V_30 ) ) {
F_136 ( V_30 ) ;
return true ;
}
F_119 ( V_2 , V_266 ) ;
return false ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_121 && ! V_30 -> V_122 ) {
F_139 ( V_2 , L_6 ) ;
F_145 ( V_2 , true ) ;
V_30 -> V_121 = 0 ;
F_59 ( F_60 ( V_2 ) , V_267 ) ;
}
}
static bool F_149 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_135 )
return true ;
V_4 = F_92 ( V_2 ) ;
if ( F_91 ( V_4 && F_16 ( V_4 ) -> V_126 & V_174 ) )
return true ;
return false ;
}
static int F_150 ( struct V_1 * V_2 , int V_210 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_268 = F_58 ( V_30 ) || ( F_123 ( V_30 ) > V_30 -> V_110 ) ;
if ( F_146 ( V_30 ) ) {
if ( ! F_149 ( V_2 ) )
V_30 -> V_248 = 0 ;
F_57 ( V_2 , F_123 ( V_30 ) + V_210 , 1 ) ;
F_139 ( V_2 , L_7 ) ;
F_145 ( V_2 , false ) ;
F_59 ( F_60 ( V_2 ) , V_269 ) ;
V_268 = 0 ;
}
return V_268 ;
}
static bool F_151 ( struct V_1 * V_2 , bool V_270 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_270 || F_146 ( V_30 ) ) {
struct V_3 * V_4 ;
F_70 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_126 &= ~ V_127 ;
}
F_118 ( V_30 ) ;
F_139 ( V_2 , L_8 ) ;
V_30 -> V_124 = 0 ;
F_145 ( V_2 , true ) ;
F_59 ( F_60 ( V_2 ) , V_264 ) ;
if ( V_270 )
F_59 ( F_60 ( V_2 ) ,
V_271 ) ;
F_2 ( V_2 ) -> V_214 = 0 ;
V_30 -> V_121 = 0 ;
if ( V_270 || F_132 ( V_30 ) )
F_119 ( V_2 , V_266 ) ;
return true ;
}
return false ;
}
static void F_152 ( struct V_1 * V_2 , const bool V_272 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_164 = V_30 -> V_98 ;
V_30 -> V_273 = 0 ;
V_30 -> V_221 = 0 ;
V_30 -> V_274 = V_30 -> V_220 ;
V_30 -> V_275 = 0 ;
V_30 -> V_276 = 0 ;
if ( V_272 )
V_30 -> V_216 = F_2 ( V_2 ) -> V_217 -> V_218 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_153 ( struct V_1 * V_2 , int V_277 ,
int V_245 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_278 = 0 ;
int V_279 = V_30 -> V_216 - F_107 ( V_30 ) ;
V_30 -> V_275 += V_277 ;
if ( F_107 ( V_30 ) > V_30 -> V_216 ) {
T_4 V_280 = ( T_4 ) V_30 -> V_216 * V_30 -> V_275 +
V_30 -> V_274 - 1 ;
V_278 = F_154 ( V_280 , V_30 -> V_274 ) - V_30 -> V_276 ;
} else {
V_278 = F_37 ( int , V_279 ,
F_27 ( int , V_30 -> V_275 - V_30 -> V_276 ,
V_277 ) + 1 ) ;
}
V_278 = F_31 ( V_278 , ( V_245 ? 1 : 0 ) ) ;
V_30 -> V_220 = F_107 ( V_30 ) + V_278 ;
}
static inline void F_155 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_118 == V_281 ||
( V_30 -> V_121 && V_30 -> V_216 < V_282 ) ) {
V_30 -> V_220 = V_30 -> V_216 ;
V_30 -> V_70 = V_71 ;
}
F_117 ( V_2 , V_283 ) ;
}
void F_156 ( struct V_1 * V_2 , const int V_272 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_215 = 0 ;
if ( F_2 ( V_2 ) -> V_118 < V_281 ) {
V_30 -> V_121 = 0 ;
F_152 ( V_2 , V_272 ) ;
F_119 ( V_2 , V_281 ) ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_159 = V_266 ;
if ( F_142 ( V_30 ) || F_149 ( V_2 ) )
V_159 = V_213 ;
if ( F_2 ( V_2 ) -> V_118 != V_159 ) {
F_119 ( V_2 , V_159 ) ;
V_30 -> V_164 = V_30 -> V_98 ;
}
}
static void F_158 ( struct V_1 * V_2 , int V_165 , int V_277 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_106 ( V_30 ) ;
if ( ! F_149 ( V_2 ) )
V_30 -> V_248 = 0 ;
if ( V_165 & V_232 )
F_156 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_118 != V_281 ) {
F_157 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_118 != V_266 )
F_136 ( V_30 ) ;
} else {
F_153 ( V_2 , V_277 , 0 ) ;
}
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_224 . V_284 = V_6 -> V_224 . V_225 - 1 ;
V_6 -> V_224 . V_225 = 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_215 = F_116 ( V_2 ) ;
V_30 -> V_220 = V_30 -> V_220 *
F_161 ( V_2 , V_30 -> V_285 ) /
V_6 -> V_224 . V_225 ;
V_30 -> V_221 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_216 = F_116 ( V_2 ) ;
V_6 -> V_224 . V_286 = V_6 -> V_224 . V_225 ;
V_6 -> V_224 . V_225 = 0 ;
F_162 ( V_2 , V_6 -> V_287 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_164 ( V_2 ) ;
T_1 V_288 = V_30 -> V_124 ;
F_70 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
if ( F_85 ( V_4 ) > V_58 &&
! ( F_16 ( V_4 ) -> V_126 & V_128 ) ) {
if ( F_16 ( V_4 ) -> V_126 & V_139 ) {
F_16 ( V_4 ) -> V_126 &= ~ V_139 ;
V_30 -> V_135 -= F_65 ( V_4 ) ;
}
F_66 ( V_30 , V_4 ) ;
}
}
F_165 ( V_30 ) ;
if ( V_288 == V_30 -> V_124 )
return;
if ( F_58 ( V_30 ) )
F_108 ( V_30 ) ;
F_106 ( V_30 ) ;
if ( V_6 -> V_118 != V_207 ) {
V_30 -> V_164 = V_30 -> V_98 ;
V_30 -> V_216 = F_116 ( V_2 ) ;
V_30 -> V_215 = 0 ;
V_30 -> V_121 = 0 ;
F_119 ( V_2 , V_207 ) ;
}
F_166 ( V_2 ) ;
}
static void F_167 ( struct V_1 * V_2 , bool V_289 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_111 ;
if ( F_58 ( V_30 ) )
V_111 = V_290 ;
else
V_111 = V_291 ;
F_59 ( F_60 ( V_2 ) , V_111 ) ;
V_30 -> V_215 = 0 ;
V_30 -> V_121 = V_30 -> V_96 ;
V_30 -> V_122 = V_30 -> V_135 ;
if ( F_2 ( V_2 ) -> V_118 < V_281 ) {
if ( ! V_289 )
V_30 -> V_215 = F_116 ( V_2 ) ;
F_152 ( V_2 , true ) ;
}
F_119 ( V_2 , V_137 ) ;
}
static void F_168 ( struct V_1 * V_2 , int V_165 , bool V_292 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_293 = ! F_40 ( V_30 -> V_96 , V_30 -> V_164 ) ;
if ( V_30 -> V_222 ) {
if ( V_165 & V_166 ) {
F_151 ( V_2 , true ) ;
return;
}
if ( F_47 ( V_30 -> V_98 , V_30 -> V_164 ) &&
( V_165 & V_167 || V_292 ) ) {
V_30 -> V_222 = 0 ;
} else if ( V_165 & V_294 && ! V_293 ) {
V_30 -> V_164 = V_30 -> V_98 ;
F_169 ( V_2 , F_164 ( V_2 ) ,
V_295 ) ;
if ( F_47 ( V_30 -> V_98 , V_30 -> V_164 ) )
return;
V_30 -> V_222 = 0 ;
}
}
if ( V_293 ) {
V_6 -> V_214 = 0 ;
F_147 ( V_2 ) ;
return;
}
if ( V_165 & V_296 )
V_6 -> V_214 = 0 ;
if ( F_58 ( V_30 ) ) {
if ( F_47 ( V_30 -> V_98 , V_30 -> V_164 ) && V_292 )
F_110 ( V_2 ) ;
else if ( V_165 & V_294 )
F_112 ( V_30 ) ;
}
if ( F_151 ( V_2 , false ) )
return;
F_166 ( V_2 ) ;
}
static void F_170 ( struct V_1 * V_2 , int V_297 ,
int V_298 , int V_299 ,
bool V_292 , int V_165 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_300 = V_292 || ( ( V_165 & V_167 ) &&
( F_123 ( V_30 ) > V_30 -> V_110 ) ) ;
int V_277 = 0 ;
int V_245 = 0 ;
if ( F_103 ( ! V_30 -> V_200 && V_30 -> V_120 ) )
V_30 -> V_120 = 0 ;
if ( F_103 ( ! V_30 -> V_120 && V_30 -> V_119 ) )
V_30 -> V_119 = 0 ;
if ( V_165 & V_232 )
V_30 -> V_215 = 0 ;
if ( F_120 ( V_2 , V_165 ) )
return;
F_106 ( V_30 ) ;
if ( V_6 -> V_118 == V_266 ) {
F_103 ( V_30 -> V_135 != 0 ) ;
V_30 -> V_248 = 0 ;
} else if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_164 ) ) {
switch ( V_6 -> V_118 ) {
case V_281 :
if ( V_30 -> V_96 != V_30 -> V_164 ) {
F_155 ( V_2 ) ;
F_119 ( V_2 , V_266 ) ;
}
break;
case V_137 :
if ( F_58 ( V_30 ) )
F_112 ( V_30 ) ;
if ( F_147 ( V_2 ) )
return;
F_155 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_118 ) {
case V_137 :
if ( ! ( V_165 & V_294 ) ) {
if ( F_58 ( V_30 ) && V_292 )
F_110 ( V_2 ) ;
} else
V_300 = F_150 ( V_2 , V_297 ) ;
V_277 = V_299 - V_30 -> V_200 +
V_30 -> V_120 - V_298 ;
break;
case V_207 :
F_168 ( V_2 , V_165 , V_292 ) ;
if ( V_6 -> V_118 != V_266 )
return;
default:
if ( F_58 ( V_30 ) ) {
if ( V_165 & V_294 )
F_112 ( V_30 ) ;
if ( V_292 )
F_110 ( V_2 ) ;
}
V_277 = V_299 - V_30 -> V_200 +
V_30 -> V_120 - V_298 ;
if ( V_6 -> V_118 <= V_213 )
F_148 ( V_2 ) ;
if ( ! F_129 ( V_2 , V_165 ) ) {
F_158 ( V_2 , V_165 , V_277 ) ;
return;
}
if ( V_6 -> V_118 < V_281 &&
V_6 -> V_224 . V_225 &&
V_30 -> V_96 == V_30 -> V_301 . V_302 ) {
F_159 ( V_2 ) ;
V_30 -> V_220 ++ ;
F_163 ( V_2 ) ;
return;
}
F_167 ( V_2 , ( V_165 & V_232 ) ) ;
V_245 = 1 ;
}
if ( V_300 || ( F_55 ( V_30 ) && F_128 ( V_2 ) ) )
F_135 ( V_2 , V_245 ) ;
F_153 ( V_2 , V_277 , V_245 ) ;
F_166 ( V_2 ) ;
}
void F_171 ( struct V_1 * V_2 , T_1 V_303 )
{
F_46 ( V_2 , V_303 ) ;
F_49 ( V_2 ) ;
F_2 ( V_2 ) -> V_304 = 0 ;
}
static void F_172 ( struct V_1 * V_2 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_171 ( V_2 , V_71 - V_30 -> V_45 . V_83 ) ;
}
static void F_173 ( struct V_1 * V_2 , T_1 V_303 , int V_165 )
{
if ( V_165 & V_305 )
return;
F_171 ( V_2 , V_303 ) ;
}
static inline void F_174 ( struct V_1 * V_2 , const int V_165 ,
const T_5 V_303 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_249 && V_30 -> V_45 . V_83 )
F_172 ( V_2 , V_165 ) ;
else if ( V_303 >= 0 )
F_173 ( V_2 , V_303 , V_165 ) ;
}
static void F_175 ( struct V_1 * V_2 , T_1 V_306 , T_1 V_307 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_217 -> V_308 ( V_2 , V_306 , V_307 ) ;
F_7 ( V_2 ) -> V_70 = V_71 ;
}
void F_176 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_309 )
return;
if ( ! V_30 -> V_200 ) {
F_177 ( V_2 , V_228 ) ;
} else {
T_1 V_310 = F_2 ( V_2 ) -> V_90 ;
if ( V_6 -> V_311 == V_235 ||
V_6 -> V_311 == V_312 ) {
struct V_3 * V_4 = F_92 ( V_2 ) ;
const T_1 V_313 = F_16 ( V_4 ) -> V_236 + V_310 ;
T_5 V_279 = ( T_5 ) ( V_313 - V_71 ) ;
if ( V_279 > 0 )
V_310 = V_279 ;
}
F_122 ( V_2 , V_228 , V_310 ,
V_229 ) ;
}
}
void F_178 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_176 ( V_2 ) ;
if ( ! V_30 -> V_240 )
return;
F_167 ( V_2 , false ) ;
F_135 ( V_2 , 1 ) ;
F_166 ( V_2 ) ;
}
static T_1 F_179 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_314 ;
F_80 ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) ) ;
V_314 = F_65 ( V_4 ) ;
if ( F_180 ( V_2 , V_4 , V_30 -> V_96 - F_16 ( V_4 ) -> V_82 ) )
return 0 ;
V_314 -= F_65 ( V_4 ) ;
if ( V_314 ) {
F_80 ( F_65 ( V_4 ) == 0 ) ;
F_80 ( ! F_40 ( F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) ;
}
return V_314 ;
}
static int F_181 ( struct V_1 * V_2 , int V_315 ,
T_1 V_145 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_88 = V_71 ;
int V_316 = true ;
int V_165 = 0 ;
T_1 V_297 = 0 ;
T_1 V_163 = V_30 -> V_200 ;
T_1 V_298 = V_30 -> V_120 ;
T_5 V_303 = - 1 ;
T_5 V_317 = - 1 ;
T_6 V_318 = F_182 () ;
while ( ( V_4 = F_92 ( V_2 ) ) && V_4 != F_71 ( V_2 ) ) {
struct V_319 * V_320 = F_16 ( V_4 ) ;
T_1 V_321 ;
T_3 V_126 = V_320 -> V_126 ;
if ( F_47 ( V_320 -> V_84 , V_30 -> V_96 ) ) {
if ( F_65 ( V_4 ) == 1 ||
! F_47 ( V_30 -> V_96 , V_320 -> V_82 ) )
break;
V_321 = F_179 ( V_2 , V_4 ) ;
if ( ! V_321 )
break;
V_316 = false ;
} else {
V_321 = F_65 ( V_4 ) ;
}
if ( V_126 & V_162 ) {
if ( V_126 & V_139 )
V_30 -> V_135 -= V_321 ;
V_165 |= V_305 ;
V_317 = - 1 ;
V_303 = - 1 ;
} else {
V_317 = V_88 - V_320 -> V_236 ;
V_318 = V_4 -> V_322 ;
if ( V_303 < 0 ) {
V_303 = V_317 ;
}
if ( ! ( V_126 & V_128 ) )
V_163 = F_9 ( V_297 , V_163 ) ;
if ( ! F_47 ( V_320 -> V_84 , V_30 -> V_164 ) )
V_165 |= V_166 ;
}
if ( V_126 & V_128 )
V_30 -> V_120 -= V_321 ;
if ( V_126 & V_127 )
V_30 -> V_124 -= V_321 ;
V_30 -> V_200 -= V_321 ;
V_297 += V_321 ;
if ( ! ( V_320 -> V_177 & V_323 ) ) {
V_165 |= V_296 ;
} else {
V_165 |= V_324 ;
V_30 -> V_248 = 0 ;
}
if ( ! V_316 )
break;
F_83 ( V_4 , V_2 ) ;
F_84 ( V_2 , V_4 ) ;
V_30 -> V_176 = NULL ;
if ( V_4 == V_30 -> V_123 )
V_30 -> V_123 = NULL ;
if ( V_4 == V_30 -> V_104 )
V_30 -> V_104 = NULL ;
}
if ( F_183 ( F_184 ( V_30 -> V_325 , V_145 , V_30 -> V_96 ) ) )
V_30 -> V_325 = V_30 -> V_96 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_126 & V_128 ) )
V_165 |= V_226 ;
if ( V_165 & V_326 ) {
const struct V_327 * V_328
= F_2 ( V_2 ) -> V_217 ;
if ( F_91 ( V_6 -> V_224 . V_225 &&
! F_47 ( V_30 -> V_301 . V_329 , V_30 -> V_96 ) ) ) {
F_160 ( V_2 ) ;
}
F_174 ( V_2 , V_165 , V_303 ) ;
F_176 ( V_2 ) ;
if ( F_58 ( V_30 ) ) {
F_111 ( V_2 , V_297 ) ;
} else {
int V_279 ;
if ( V_163 < V_315 )
F_57 ( V_2 , V_30 -> V_119 - V_163 , 0 ) ;
V_279 = F_55 ( V_30 ) ? V_297 :
V_298 - V_30 -> V_120 ;
V_30 -> V_168 -= F_9 ( V_30 -> V_168 , V_279 ) ;
}
V_30 -> V_119 -= F_9 ( V_297 , V_30 -> V_119 ) ;
if ( V_328 -> V_297 ) {
T_5 V_330 = - 1 ;
if ( ! ( V_165 & V_305 ) ) {
if ( V_328 -> V_331 & V_332 &&
! F_185 ( V_318 ,
F_182 () ) )
V_330 = F_186 ( F_187 () ,
V_318 ) ;
else if ( V_317 >= 0 )
V_330 = F_188 ( V_317 ) ;
}
V_328 -> V_297 ( V_2 , V_297 , V_330 ) ;
}
}
#if V_117 > 0
F_103 ( ( int ) V_30 -> V_120 < 0 ) ;
F_103 ( ( int ) V_30 -> V_124 < 0 ) ;
F_103 ( ( int ) V_30 -> V_135 < 0 ) ;
if ( ! V_30 -> V_200 && F_132 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_124 ) {
F_61 ( L_9 ,
V_30 -> V_124 , V_6 -> V_118 ) ;
V_30 -> V_124 = 0 ;
}
if ( V_30 -> V_120 ) {
F_61 ( L_10 ,
V_30 -> V_120 , V_6 -> V_118 ) ;
V_30 -> V_120 = 0 ;
}
if ( V_30 -> V_135 ) {
F_61 ( L_11 ,
V_30 -> V_135 , V_6 -> V_118 ) ;
V_30 -> V_135 = 0 ;
}
}
#endif
return V_165 ;
}
static void F_189 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_47 ( F_16 ( F_71 ( V_2 ) ) -> V_84 , F_190 ( V_30 ) ) ) {
V_6 -> V_304 = 0 ;
F_177 ( V_2 , V_333 ) ;
} else {
F_122 ( V_2 , V_333 ,
F_9 ( V_6 -> V_90 << V_6 -> V_304 , V_229 ) ,
V_229 ) ;
}
}
static inline bool F_191 ( const struct V_1 * V_2 , const int V_165 )
{
return ! ( V_165 & V_334 ) || ( V_165 & V_335 ) ||
F_2 ( V_2 ) -> V_118 != V_266 ;
}
static inline bool F_192 ( const struct V_1 * V_2 , const int V_165 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_165 & V_232 ) || V_30 -> V_220 < V_30 -> V_216 ) &&
! F_193 ( V_2 ) ;
}
static inline bool F_194 ( const struct V_29 * V_30 ,
const T_1 V_306 , const T_1 V_138 ,
const T_1 V_336 )
{
return F_47 ( V_306 , V_30 -> V_96 ) ||
F_47 ( V_138 , V_30 -> V_337 ) ||
( V_138 == V_30 -> V_337 && V_336 > V_30 -> V_338 ) ;
}
static int F_195 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_306 ,
T_1 V_138 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_165 = 0 ;
T_1 V_336 = F_141 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_183 ( ! F_6 ( V_4 ) -> V_43 ) )
V_336 <<= V_30 -> V_45 . V_339 ;
if ( F_194 ( V_30 , V_306 , V_138 , V_336 ) ) {
V_165 |= V_340 ;
F_196 ( V_30 , V_138 ) ;
if ( V_30 -> V_338 != V_336 ) {
V_30 -> V_338 = V_336 ;
V_30 -> V_341 = 0 ;
F_197 ( V_2 ) ;
if ( V_336 > V_30 -> V_131 ) {
V_30 -> V_131 = V_336 ;
F_162 ( V_2 , F_2 ( V_2 ) -> V_287 ) ;
}
}
}
V_30 -> V_96 = V_306 ;
return V_165 ;
}
static void F_198 ( struct V_1 * V_2 )
{
static T_1 V_342 ;
static unsigned int V_343 ;
T_1 V_88 = V_234 / V_344 ;
if ( V_88 != V_342 ) {
V_342 = V_88 ;
V_343 = 0 ;
}
if ( ++ V_343 <= V_345 ) {
F_59 ( F_60 ( V_2 ) , V_346 ) ;
F_199 ( V_2 ) ;
}
}
static void F_200 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_347 = V_30 -> V_45 . V_348 ;
V_30 -> V_45 . V_349 = F_201 () ;
}
static void F_202 ( struct V_29 * V_30 , T_1 V_82 )
{
if ( V_30 -> V_45 . V_249 && ! F_47 ( V_82 , V_30 -> V_350 ) ) {
if ( F_203 ( & V_30 -> V_45 , 0 ) )
F_200 ( V_30 ) ;
}
}
static void F_204 ( struct V_1 * V_2 , T_1 V_306 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_351 = ( V_306 == V_30 -> V_273 ) &&
! ( V_165 & ( V_294 |
V_334 | V_167 ) ) ;
if ( V_351 ) {
V_30 -> V_273 = 0 ;
return;
}
if ( F_47 ( V_306 , V_30 -> V_273 ) ) {
V_30 -> V_273 = 0 ;
if ( ! ( V_165 & V_201 ) ) {
F_152 ( V_2 , true ) ;
F_119 ( V_2 , V_281 ) ;
F_155 ( V_2 ) ;
F_119 ( V_2 , V_266 ) ;
F_59 ( F_60 ( V_2 ) ,
V_352 ) ;
}
}
}
static int F_205 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_165 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_145 = V_30 -> V_96 ;
T_1 V_138 = F_16 ( V_4 ) -> V_82 ;
T_1 V_306 = F_16 ( V_4 ) -> V_138 ;
bool V_292 = false ;
T_1 V_353 ;
T_1 V_315 ;
int V_299 = V_30 -> V_200 ;
int V_298 = V_30 -> V_120 ;
int V_297 = 0 ;
int V_354 = 0 ;
if ( F_40 ( V_306 , V_145 ) ) {
if ( F_40 ( V_306 , V_145 - V_30 -> V_131 ) ) {
F_198 ( V_2 ) ;
return - 1 ;
}
goto V_355;
}
if ( F_47 ( V_306 , V_30 -> V_98 ) )
goto V_356;
if ( V_6 -> V_311 == V_235 ||
V_6 -> V_311 == V_312 )
F_176 ( V_2 ) ;
if ( F_47 ( V_306 , V_145 ) )
V_165 |= V_294 ;
V_315 = V_30 -> V_119 ;
V_353 = F_107 ( V_30 ) ;
if ( V_165 & V_357 )
F_202 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! ( V_165 & V_358 ) && F_47 ( V_306 , V_145 ) ) {
F_196 ( V_30 , V_138 ) ;
V_30 -> V_96 = V_306 ;
V_165 |= V_340 ;
F_117 ( V_2 , V_359 ) ;
F_59 ( F_60 ( V_2 ) , V_360 ) ;
} else {
if ( V_138 != F_16 ( V_4 ) -> V_84 )
V_165 |= V_361 ;
else
F_59 ( F_60 ( V_2 ) , V_362 ) ;
V_165 |= F_195 ( V_2 , V_4 , V_306 , V_138 ) ;
if ( F_16 ( V_4 ) -> V_126 )
V_165 |= F_102 ( V_2 , V_4 , V_145 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_165 |= V_232 ;
F_117 ( V_2 , V_363 ) ;
}
V_2 -> V_364 = 0 ;
V_6 -> V_365 = 0 ;
V_30 -> V_366 = V_71 ;
if ( ! V_299 )
goto V_367;
V_354 = V_30 -> V_200 ;
V_165 |= F_181 ( V_2 , V_315 , V_145 ) ;
V_297 = V_354 - V_30 -> V_200 ;
if ( F_191 ( V_2 , V_165 ) ) {
if ( ( V_165 & V_296 ) && F_192 ( V_2 , V_165 ) )
F_175 ( V_2 , V_306 , V_353 ) ;
V_292 = ! ( V_165 & ( V_294 | V_334 ) ) ;
F_170 ( V_2 , V_297 , V_298 ,
V_299 , V_292 , V_165 ) ;
} else {
if ( V_165 & V_296 )
F_175 ( V_2 , V_306 , V_353 ) ;
}
if ( V_30 -> V_273 )
F_204 ( V_2 , V_306 , V_165 ) ;
if ( ( V_165 & V_368 ) || ! ( V_165 & V_334 ) ) {
struct V_99 * V_100 = F_206 ( V_2 ) ;
if ( V_100 )
F_207 ( V_100 ) ;
}
if ( V_6 -> V_311 == V_228 )
F_208 ( V_2 ) ;
return 1 ;
V_367:
if ( V_165 & V_201 )
F_170 ( V_2 , V_297 , V_298 ,
V_299 , V_292 , V_165 ) ;
if ( F_71 ( V_2 ) )
F_189 ( V_2 ) ;
if ( V_30 -> V_273 )
F_204 ( V_2 , V_306 , V_165 ) ;
return 1 ;
V_356:
F_209 ( V_2 , L_12 , V_306 , V_30 -> V_96 , V_30 -> V_98 ) ;
return - 1 ;
V_355:
if ( F_16 ( V_4 ) -> V_126 ) {
V_165 |= F_102 ( V_2 , V_4 , V_145 ) ;
F_170 ( V_2 , V_297 , V_298 ,
V_299 , V_292 , V_165 ) ;
}
F_209 ( V_2 , L_13 , V_306 , V_30 -> V_96 , V_30 -> V_98 ) ;
return 0 ;
}
void F_210 ( const struct V_3 * V_4 ,
struct V_369 * V_370 , int V_371 ,
struct V_372 * V_373 )
{
const unsigned char * V_191 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_374 = ( V_41 -> V_375 * 4 ) - sizeof( struct V_15 ) ;
V_191 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_370 -> V_249 = 0 ;
while ( V_374 > 0 ) {
int V_376 = * V_191 ++ ;
int V_377 ;
switch ( V_376 ) {
case V_378 :
return;
case V_379 :
V_374 -- ;
continue;
default:
V_377 = * V_191 ++ ;
if ( V_377 < 2 )
return;
if ( V_377 > V_374 )
return;
switch ( V_376 ) {
case V_380 :
if ( V_377 == V_381 && V_41 -> V_43 && ! V_371 ) {
T_7 V_382 = F_211 ( V_191 ) ;
if ( V_382 ) {
if ( V_370 -> V_383 &&
V_370 -> V_383 < V_382 )
V_382 = V_370 -> V_383 ;
V_370 -> V_46 = V_382 ;
}
}
break;
case V_384 :
if ( V_377 == V_385 && V_41 -> V_43 &&
! V_371 && V_386 ) {
T_8 V_339 = * ( T_8 * ) V_191 ;
V_370 -> V_387 = 1 ;
if ( V_339 > 14 ) {
F_212 ( L_14 ,
V_388 ,
V_339 ) ;
V_339 = 14 ;
}
V_370 -> V_339 = V_339 ;
}
break;
case V_389 :
if ( ( V_377 == V_390 ) &&
( ( V_371 && V_370 -> V_391 ) ||
( ! V_371 && V_392 ) ) ) {
V_370 -> V_249 = 1 ;
V_370 -> V_348 = F_73 ( V_191 ) ;
V_370 -> V_83 = F_73 ( V_191 + 4 ) ;
}
break;
case V_393 :
if ( V_377 == V_394 && V_41 -> V_43 &&
! V_371 && V_395 ) {
V_370 -> V_105 = V_396 ;
F_213 ( V_370 ) ;
}
break;
case V_397 :
if ( ( V_377 >= ( V_194 + V_398 ) ) &&
! ( ( V_377 - V_194 ) % V_398 ) &&
V_370 -> V_105 ) {
F_16 ( V_4 ) -> V_126 = ( V_191 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_214
case V_399 :
break;
#endif
case V_400 :
if ( V_377 < V_401 ||
F_211 ( V_191 ) != V_402 ||
V_373 == NULL || ! V_41 -> V_43 || ( V_377 & 1 ) )
break;
V_373 -> V_10 = V_377 - V_401 ;
if ( V_373 -> V_10 >= V_403 &&
V_373 -> V_10 <= V_404 )
memcpy ( V_373 -> V_405 , V_191 + 2 , V_373 -> V_10 ) ;
else if ( V_373 -> V_10 != 0 )
V_373 -> V_10 = - 1 ;
break;
}
V_191 += V_377 - 2 ;
V_374 -= V_377 ;
}
}
}
static bool F_215 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_191 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_191 == F_216 ( ( V_379 << 24 ) | ( V_379 << 16 )
| ( V_389 << 8 ) | V_390 ) ) {
V_30 -> V_45 . V_249 = 1 ;
++ V_191 ;
V_30 -> V_45 . V_348 = F_217 ( * V_191 ) ;
++ V_191 ;
V_30 -> V_45 . V_83 = F_217 ( * V_191 ) - V_30 -> V_406 ;
return true ;
}
return false ;
}
static bool F_218 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 , struct V_29 * V_30 )
{
if ( V_41 -> V_375 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_249 = 0 ;
return false ;
} else if ( V_30 -> V_45 . V_391 &&
V_41 -> V_375 == ( ( sizeof( * V_41 ) + V_407 ) / 4 ) ) {
if ( F_215 ( V_30 , V_41 ) )
return true ;
}
F_210 ( V_4 , & V_30 -> V_45 , 1 , NULL ) ;
if ( V_30 -> V_45 . V_249 )
V_30 -> V_45 . V_83 -= V_30 -> V_406 ;
return true ;
}
const T_3 * F_219 ( const struct V_15 * V_41 )
{
int V_374 = ( V_41 -> V_375 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_191 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_374 < V_408 )
return NULL ;
while ( V_374 > 0 ) {
int V_376 = * V_191 ++ ;
int V_377 ;
switch( V_376 ) {
case V_378 :
return NULL ;
case V_379 :
V_374 -- ;
continue;
default:
V_377 = * V_191 ++ ;
if ( V_377 < 2 || V_377 > V_374 )
return NULL ;
if ( V_376 == V_399 )
return V_377 == V_408 ? V_191 : NULL ;
}
V_191 += V_377 - 2 ;
V_374 -= V_377 ;
}
return NULL ;
}
static int F_220 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
T_1 V_306 = F_16 ( V_4 ) -> V_138 ;
return (
( V_41 -> V_306 && V_82 == F_16 ( V_4 ) -> V_84 && V_82 == V_30 -> V_81 ) &&
V_306 == V_30 -> V_96 &&
! F_194 ( V_30 , V_306 , V_82 , F_141 ( V_41 -> V_52 ) << V_30 -> V_45 . V_339 ) &&
( T_5 ) ( V_30 -> V_45 . V_347 - V_30 -> V_45 . V_348 ) <= ( F_2 ( V_2 ) -> V_90 * 1024 ) / V_344 ) ;
}
static inline bool F_221 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_203 ( & V_30 -> V_45 , V_409 ) &&
! F_220 ( V_2 , V_4 ) ;
}
static inline bool F_222 ( const struct V_29 * V_30 , T_1 V_82 , T_1 V_84 )
{
return ! F_40 ( V_84 , V_30 -> V_350 ) &&
! F_47 ( V_82 , V_30 -> V_81 + F_223 ( V_30 ) ) ;
}
void F_224 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_410 ) {
case V_411 :
V_2 -> V_412 = V_413 ;
break;
case V_414 :
V_2 -> V_412 = V_415 ;
break;
case V_416 :
return;
default:
V_2 -> V_412 = V_417 ;
}
F_225 () ;
if ( ! F_226 ( V_2 , V_418 ) )
V_2 -> V_419 ( V_2 ) ;
F_227 ( V_2 ) ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_420 |= V_421 ;
F_229 ( V_2 , V_422 ) ;
switch ( V_2 -> V_410 ) {
case V_423 :
case V_424 :
F_230 ( V_2 , V_414 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_414 :
case V_425 :
break;
case V_426 :
break;
case V_427 :
F_199 ( V_2 ) ;
F_230 ( V_2 , V_425 ) ;
break;
case V_428 :
F_199 ( V_2 ) ;
F_231 ( V_2 , V_429 , 0 ) ;
break;
default:
F_232 ( L_15 ,
V_388 , V_2 -> V_410 ) ;
break;
}
F_233 ( & V_30 -> V_430 ) ;
if ( F_132 ( V_30 ) )
F_213 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
if ( ! F_226 ( V_2 , V_418 ) ) {
V_2 -> V_431 ( V_2 ) ;
if ( V_2 -> V_420 == V_432 ||
V_2 -> V_410 == V_416 )
F_234 ( V_2 , V_433 , V_434 ) ;
else
F_234 ( V_2 , V_433 , V_435 ) ;
}
}
static inline bool F_235 ( struct V_184 * V_143 , T_1 V_82 ,
T_1 V_84 )
{
if ( ! F_47 ( V_82 , V_143 -> V_84 ) && ! F_47 ( V_143 -> V_130 , V_84 ) ) {
if ( F_40 ( V_82 , V_143 -> V_130 ) )
V_143 -> V_130 = V_82 ;
if ( F_47 ( V_84 , V_143 -> V_84 ) )
V_143 -> V_84 = V_84 ;
return true ;
}
return false ;
}
static void F_236 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_132 ( V_30 ) && V_436 ) {
int V_111 ;
if ( F_40 ( V_82 , V_30 -> V_81 ) )
V_111 = V_437 ;
else
V_111 = V_438 ;
F_59 ( F_60 ( V_2 ) , V_111 ) ;
V_30 -> V_45 . V_439 = 1 ;
V_30 -> V_440 [ 0 ] . V_130 = V_82 ;
V_30 -> V_440 [ 0 ] . V_84 = V_84 ;
}
}
static void F_237 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_439 )
F_236 ( V_2 , V_82 , V_84 ) ;
else
F_235 ( V_30 -> V_440 , V_82 , V_84 ) ;
}
static void F_238 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_59 ( F_60 ( V_2 ) , V_441 ) ;
F_10 ( V_2 ) ;
if ( F_132 ( V_30 ) && V_436 ) {
T_1 V_84 = F_16 ( V_4 ) -> V_84 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) )
V_84 = V_30 -> V_81 ;
F_236 ( V_2 , F_16 ( V_4 ) -> V_82 , V_84 ) ;
}
}
F_199 ( V_2 ) ;
}
static void F_239 ( struct V_29 * V_30 )
{
int V_442 ;
struct V_184 * V_143 = & V_30 -> V_443 [ 0 ] ;
struct V_184 * V_444 = V_143 + 1 ;
for ( V_442 = 1 ; V_442 < V_30 -> V_45 . V_144 ; ) {
if ( F_235 ( V_143 , V_444 -> V_130 , V_444 -> V_84 ) ) {
int V_197 ;
V_30 -> V_45 . V_144 -- ;
for ( V_197 = V_442 ; V_197 < V_30 -> V_45 . V_144 ; V_197 ++ )
V_143 [ V_197 ] = V_143 [ V_197 + 1 ] ;
continue;
}
V_442 ++ , V_444 ++ ;
}
}
static void F_240 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_184 * V_143 = & V_30 -> V_443 [ 0 ] ;
int V_445 = V_30 -> V_45 . V_144 ;
int V_442 ;
if ( ! V_445 )
goto V_446;
for ( V_442 = 0 ; V_442 < V_445 ; V_442 ++ , V_143 ++ ) {
if ( F_235 ( V_143 , V_82 , V_84 ) ) {
for (; V_442 > 0 ; V_442 -- , V_143 -- )
F_105 ( * V_143 , * ( V_143 - 1 ) ) ;
if ( V_445 > 1 )
F_239 ( V_30 ) ;
return;
}
}
if ( V_442 >= V_193 ) {
V_442 -- ;
V_30 -> V_45 . V_144 -- ;
V_143 -- ;
}
for (; V_442 > 0 ; V_442 -- , V_143 -- )
* V_143 = * ( V_143 - 1 ) ;
V_446:
V_143 -> V_130 = V_82 ;
V_143 -> V_84 = V_84 ;
V_30 -> V_45 . V_144 ++ ;
}
static void F_241 ( struct V_29 * V_30 )
{
struct V_184 * V_143 = & V_30 -> V_443 [ 0 ] ;
int V_144 = V_30 -> V_45 . V_144 ;
int V_442 ;
if ( F_242 ( & V_30 -> V_430 ) ) {
V_30 -> V_45 . V_144 = 0 ;
return;
}
for ( V_442 = 0 ; V_442 < V_144 ; ) {
if ( ! F_40 ( V_30 -> V_81 , V_143 -> V_130 ) ) {
int V_197 ;
F_103 ( F_40 ( V_30 -> V_81 , V_143 -> V_84 ) ) ;
for ( V_197 = V_442 + 1 ; V_197 < V_144 ; V_197 ++ )
V_30 -> V_443 [ V_197 - 1 ] = V_30 -> V_443 [ V_197 ] ;
V_144 -- ;
continue;
}
V_442 ++ ;
V_143 ++ ;
}
V_30 -> V_45 . V_144 = V_144 ;
}
static void F_243 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_447 = V_30 -> V_81 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_244 ( & V_30 -> V_430 ) ) != NULL ) {
if ( F_47 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_447 ) ) {
T_2 V_439 = V_447 ;
if ( F_40 ( F_16 ( V_4 ) -> V_84 , V_447 ) )
V_447 = F_16 ( V_4 ) -> V_84 ;
F_237 ( V_2 , F_16 ( V_4 ) -> V_82 , V_439 ) ;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_209 ( V_2 , L_16 ) ;
F_245 ( V_4 , & V_30 -> V_430 ) ;
F_246 ( V_4 ) ;
continue;
}
F_209 ( V_2 , L_17 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_245 ( V_4 , & V_30 -> V_430 ) ;
F_247 ( & V_2 -> V_448 , V_4 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( F_6 ( V_4 ) -> V_449 )
F_228 ( V_2 ) ;
}
}
static int F_248 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_450 )
{
if ( F_35 ( & V_2 -> V_72 ) > V_2 -> V_62 ||
! F_249 ( V_2 , V_4 , V_450 ) ) {
if ( F_250 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_249 ( V_2 , V_4 , V_450 ) ) {
if ( ! F_251 ( V_2 ) )
return - 1 ;
if ( ! F_249 ( V_2 , V_4 , V_450 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_252 ( struct V_1 * V_2 ,
struct V_3 * V_451 ,
struct V_3 * V_452 ,
bool * V_453 )
{
int V_279 ;
* V_453 = false ;
if ( F_6 ( V_452 ) -> V_449 )
return false ;
if ( F_16 ( V_452 ) -> V_82 != F_16 ( V_451 ) -> V_84 )
return false ;
if ( ! F_253 ( V_451 , V_452 , V_453 , & V_279 ) )
return false ;
F_254 ( V_279 , & V_2 -> V_72 ) ;
F_255 ( V_2 , V_279 ) ;
F_59 ( F_60 ( V_2 ) , V_454 ) ;
F_16 ( V_451 ) -> V_84 = F_16 ( V_452 ) -> V_84 ;
F_16 ( V_451 ) -> V_138 = F_16 ( V_452 ) -> V_138 ;
return true ;
}
static void F_256 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_455 ;
T_1 V_82 , V_84 ;
F_15 ( V_30 , V_4 ) ;
if ( F_91 ( F_248 ( V_2 , V_4 , V_4 -> V_51 ) ) ) {
F_59 ( F_60 ( V_2 ) , V_456 ) ;
F_246 ( V_4 ) ;
return;
}
V_30 -> V_341 = 0 ;
F_44 ( V_2 ) ;
F_59 ( F_60 ( V_2 ) , V_457 ) ;
F_209 ( V_2 , L_18 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_455 = F_257 ( & V_30 -> V_430 ) ;
if ( ! V_455 ) {
if ( F_132 ( V_30 ) ) {
V_30 -> V_45 . V_144 = 1 ;
V_30 -> V_443 [ 0 ] . V_130 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_443 [ 0 ] . V_84 =
F_16 ( V_4 ) -> V_84 ;
}
F_258 ( & V_30 -> V_430 , V_4 ) ;
goto V_458;
}
V_82 = F_16 ( V_4 ) -> V_82 ;
V_84 = F_16 ( V_4 ) -> V_84 ;
if ( V_82 == F_16 ( V_455 ) -> V_84 ) {
bool V_453 ;
if ( ! F_252 ( V_2 , V_455 , V_4 , & V_453 ) ) {
F_259 ( & V_30 -> V_430 , V_455 , V_4 ) ;
} else {
F_260 ( V_4 , V_453 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_45 . V_144 ||
V_30 -> V_443 [ 0 ] . V_84 != V_82 )
goto V_459;
V_30 -> V_443 [ 0 ] . V_84 = V_84 ;
goto V_458;
}
while ( 1 ) {
if ( ! F_47 ( F_16 ( V_455 ) -> V_82 , V_82 ) )
break;
if ( F_261 ( & V_30 -> V_430 , V_455 ) ) {
V_455 = NULL ;
break;
}
V_455 = F_262 ( & V_30 -> V_430 , V_455 ) ;
}
if ( V_455 && F_40 ( V_82 , F_16 ( V_455 ) -> V_84 ) ) {
if ( ! F_47 ( V_84 , F_16 ( V_455 ) -> V_84 ) ) {
F_59 ( F_60 ( V_2 ) , V_460 ) ;
F_246 ( V_4 ) ;
V_4 = NULL ;
F_236 ( V_2 , V_82 , V_84 ) ;
goto V_459;
}
if ( F_47 ( V_82 , F_16 ( V_455 ) -> V_82 ) ) {
F_236 ( V_2 , V_82 ,
F_16 ( V_455 ) -> V_84 ) ;
} else {
if ( F_261 ( & V_30 -> V_430 ,
V_455 ) )
V_455 = NULL ;
else
V_455 = F_262 (
& V_30 -> V_430 ,
V_455 ) ;
}
}
if ( ! V_455 )
F_258 ( & V_30 -> V_430 , V_4 ) ;
else
F_259 ( & V_30 -> V_430 , V_455 , V_4 ) ;
while ( ! F_263 ( & V_30 -> V_430 , V_4 ) ) {
V_455 = F_264 ( & V_30 -> V_430 , V_4 ) ;
if ( ! F_47 ( V_84 , F_16 ( V_455 ) -> V_82 ) )
break;
if ( F_40 ( V_84 , F_16 ( V_455 ) -> V_84 ) ) {
F_237 ( V_2 , F_16 ( V_455 ) -> V_82 ,
V_84 ) ;
break;
}
F_245 ( V_455 , & V_30 -> V_430 ) ;
F_237 ( V_2 , F_16 ( V_455 ) -> V_82 ,
F_16 ( V_455 ) -> V_84 ) ;
F_59 ( F_60 ( V_2 ) , V_460 ) ;
F_246 ( V_455 ) ;
}
V_459:
if ( F_132 ( V_30 ) )
F_240 ( V_2 , V_82 , V_84 ) ;
V_458:
if ( V_4 )
F_265 ( V_4 , V_2 ) ;
}
static int T_10 F_266 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_461 ,
bool * V_453 )
{
int V_462 ;
struct V_3 * V_463 = F_257 ( & V_2 -> V_448 ) ;
F_267 ( V_4 , V_461 ) ;
V_462 = ( V_463 &&
F_252 ( V_2 , V_463 , V_4 , V_453 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( ! V_462 ) {
F_247 ( & V_2 -> V_448 , V_4 ) ;
F_265 ( V_4 , V_2 ) ;
}
return V_462 ;
}
int F_268 ( struct V_1 * V_2 , struct V_464 * V_250 , T_11 V_450 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_453 ;
if ( V_450 == 0 )
return 0 ;
V_4 = F_269 ( V_450 + sizeof( * V_41 ) , V_2 -> V_465 ) ;
if ( ! V_4 )
goto V_153;
if ( F_248 ( V_2 , V_4 , V_450 + sizeof( * V_41 ) ) )
goto V_466;
V_41 = (struct V_15 * ) F_270 ( V_4 , sizeof( * V_41 ) ) ;
F_271 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_272 ( F_270 ( V_4 , V_450 ) , V_250 -> V_467 , V_450 ) )
goto V_466;
F_16 ( V_4 ) -> V_82 = F_7 ( V_2 ) -> V_81 ;
F_16 ( V_4 ) -> V_84 = F_16 ( V_4 ) -> V_82 + V_450 ;
F_16 ( V_4 ) -> V_138 = F_7 ( V_2 ) -> V_96 - 1 ;
if ( F_266 ( V_2 , V_4 , sizeof( * V_41 ) , & V_453 ) ) {
F_273 ( V_453 ) ;
F_246 ( V_4 ) ;
}
return V_450 ;
V_466:
F_274 ( V_4 ) ;
V_153:
return - V_468 ;
}
static void F_275 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_462 = - 1 ;
bool V_453 = false ;
if ( F_16 ( V_4 ) -> V_82 == F_16 ( V_4 ) -> V_84 )
goto V_469;
F_276 ( V_4 ) ;
F_267 ( V_4 , V_41 -> V_375 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_439 = 0 ;
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 ) {
if ( F_223 ( V_30 ) == 0 )
goto V_470;
if ( V_30 -> V_471 . V_472 == V_473 &&
V_30 -> V_85 == V_30 -> V_81 && V_30 -> V_471 . V_10 &&
F_277 ( V_2 ) && ! V_30 -> V_474 ) {
int V_475 = F_37 (unsigned int, skb->len,
tp->ucopy.len) ;
F_278 ( V_476 ) ;
F_279 () ;
if ( ! F_280 ( V_4 , 0 , V_30 -> V_471 . V_477 , V_475 ) ) {
V_30 -> V_471 . V_10 -= V_475 ;
V_30 -> V_85 += V_475 ;
V_462 = ( V_475 == V_4 -> V_10 ) ;
F_42 ( V_2 ) ;
}
F_281 () ;
}
if ( V_462 <= 0 ) {
V_478:
if ( V_462 < 0 &&
F_248 ( V_2 , V_4 , V_4 -> V_51 ) )
goto V_469;
V_462 = F_266 ( V_2 , V_4 , 0 , & V_453 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( V_4 -> V_10 )
F_43 ( V_2 , V_4 ) ;
if ( V_41 -> V_449 )
F_228 ( V_2 ) ;
if ( ! F_242 ( & V_30 -> V_430 ) ) {
F_243 ( V_2 ) ;
if ( F_242 ( & V_30 -> V_430 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_144 )
F_241 ( V_30 ) ;
F_197 ( V_2 ) ;
if ( V_462 > 0 )
F_260 ( V_4 , V_453 ) ;
if ( ! F_226 ( V_2 , V_418 ) )
V_2 -> V_479 ( V_2 , 0 ) ;
return;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_59 ( F_60 ( V_2 ) , V_441 ) ;
F_236 ( V_2 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_470:
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
V_469:
F_246 ( V_4 ) ;
return;
}
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 + F_223 ( V_30 ) ) )
goto V_470;
F_10 ( V_2 ) ;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_209 ( V_2 , L_19 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_236 ( V_2 , F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ;
if ( ! F_223 ( V_30 ) )
goto V_470;
goto V_478;
}
F_256 ( V_2 , V_4 ) ;
}
static struct V_3 * F_282 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_480 * V_481 )
{
struct V_3 * V_482 = NULL ;
if ( ! F_263 ( V_481 , V_4 ) )
V_482 = F_264 ( V_481 , V_4 ) ;
F_245 ( V_4 , V_481 ) ;
F_246 ( V_4 ) ;
F_59 ( F_60 ( V_2 ) , V_483 ) ;
return V_482 ;
}
static void
F_283 ( struct V_1 * V_2 , struct V_480 * V_481 ,
struct V_3 * V_484 , struct V_3 * V_463 ,
T_1 V_485 , T_1 V_458 )
{
struct V_3 * V_4 , * V_486 ;
bool V_487 ;
V_4 = V_484 ;
V_488:
V_487 = true ;
F_284 (list, skb, n) {
if ( V_4 == V_463 )
break;
if ( ! F_40 ( V_485 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_282 ( V_2 , V_4 , V_481 ) ;
if ( ! V_4 )
break;
goto V_488;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_449 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_40 ( F_16 ( V_4 ) -> V_82 , V_485 ) ) ) {
V_487 = false ;
break;
}
if ( ! F_263 ( V_481 , V_4 ) ) {
struct V_3 * V_482 = F_264 ( V_481 , V_4 ) ;
if ( V_482 != V_463 &&
F_16 ( V_4 ) -> V_84 != F_16 ( V_482 ) -> V_82 ) {
V_487 = false ;
break;
}
}
V_485 = F_16 ( V_4 ) -> V_84 ;
}
if ( V_487 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_449 )
return;
while ( F_40 ( V_485 , V_458 ) ) {
struct V_3 * V_489 ;
unsigned int V_490 = F_285 ( V_4 ) ;
int V_491 = F_286 ( V_490 , 0 ) ;
if ( V_491 < 0 )
return;
if ( V_458 - V_485 < V_491 )
V_491 = V_458 - V_485 ;
V_489 = F_269 ( V_491 + V_490 , V_492 ) ;
if ( ! V_489 )
return;
F_287 ( V_489 , F_288 ( V_4 ) - V_4 -> V_484 ) ;
F_289 ( V_489 , ( F_290 ( V_4 ) -
V_4 -> V_484 ) ) ;
F_291 ( V_489 , ( F_4 ( V_4 ) -
V_4 -> V_484 ) ) ;
F_292 ( V_489 , V_490 ) ;
memcpy ( V_489 -> V_484 , V_4 -> V_484 , V_490 ) ;
memcpy ( V_489 -> V_493 , V_4 -> V_493 , sizeof( V_4 -> V_493 ) ) ;
F_16 ( V_489 ) -> V_82 = F_16 ( V_489 ) -> V_84 = V_485 ;
F_293 ( V_481 , V_4 , V_489 ) ;
F_265 ( V_489 , V_2 ) ;
while ( V_491 > 0 ) {
int V_494 = V_485 - F_16 ( V_4 ) -> V_82 ;
int V_450 = F_16 ( V_4 ) -> V_84 - V_485 ;
F_80 ( V_494 < 0 ) ;
if ( V_450 > 0 ) {
V_450 = F_9 ( V_491 , V_450 ) ;
if ( F_294 ( V_4 , V_494 , F_270 ( V_489 , V_450 ) , V_450 ) )
F_295 () ;
F_16 ( V_489 ) -> V_84 += V_450 ;
V_491 -= V_450 ;
V_485 += V_450 ;
}
if ( ! F_40 ( V_485 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_282 ( V_2 , V_4 , V_481 ) ;
if ( ! V_4 ||
V_4 == V_463 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_449 )
return;
}
}
}
}
static void F_296 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_244 ( & V_30 -> V_430 ) ;
struct V_3 * V_484 ;
T_1 V_485 , V_458 ;
if ( V_4 == NULL )
return;
V_485 = F_16 ( V_4 ) -> V_82 ;
V_458 = F_16 ( V_4 ) -> V_84 ;
V_484 = V_4 ;
for (; ; ) {
struct V_3 * V_482 = NULL ;
if ( ! F_263 ( & V_30 -> V_430 , V_4 ) )
V_482 = F_264 ( & V_30 -> V_430 , V_4 ) ;
V_4 = V_482 ;
if ( ! V_4 ||
F_47 ( F_16 ( V_4 ) -> V_82 , V_458 ) ||
F_40 ( F_16 ( V_4 ) -> V_84 , V_485 ) ) {
F_283 ( V_2 , & V_30 -> V_430 ,
V_484 , V_4 , V_485 , V_458 ) ;
V_484 = V_4 ;
if ( ! V_4 )
break;
V_485 = F_16 ( V_4 ) -> V_82 ;
V_458 = F_16 ( V_4 ) -> V_84 ;
} else {
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_485 ) )
V_485 = F_16 ( V_4 ) -> V_82 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_458 ) )
V_458 = F_16 ( V_4 ) -> V_84 ;
}
}
}
static bool F_251 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_495 = false ;
if ( ! F_242 ( & V_30 -> V_430 ) ) {
F_59 ( F_60 ( V_2 ) , V_496 ) ;
F_233 ( & V_30 -> V_430 ) ;
if ( V_30 -> V_45 . V_105 )
F_213 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
V_495 = true ;
}
return V_495 ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_209 ( V_2 , L_20 , V_30 -> V_85 ) ;
F_59 ( F_60 ( V_2 ) , V_497 ) ;
if ( F_35 ( & V_2 -> V_72 ) >= V_2 -> V_62 )
F_32 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_296 ( V_2 ) ;
if ( ! F_242 ( & V_2 -> V_448 ) )
F_283 ( V_2 , & V_2 -> V_448 ,
F_244 ( & V_2 -> V_448 ) ,
NULL ,
V_30 -> V_85 , V_30 -> V_81 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_251 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_59 ( F_60 ( V_2 ) , V_498 ) ;
V_30 -> V_341 = 0 ;
return - 1 ;
}
void F_297 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_118 == V_266 &&
V_2 -> V_499 && ! F_298 ( V_500 , & V_2 -> V_499 -> V_331 ) ) {
T_1 V_501 = F_52 ( V_30 , F_206 ( V_2 ) ) ;
T_1 V_502 = F_31 ( V_30 -> V_503 , V_501 ) ;
if ( V_502 < V_30 -> V_220 ) {
V_30 -> V_216 = F_116 ( V_2 ) ;
V_30 -> V_220 = ( V_30 -> V_220 + V_502 ) >> 1 ;
}
V_30 -> V_503 = 0 ;
}
V_30 -> V_70 = V_71 ;
}
static bool F_299 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_64 & V_66 )
return false ;
if ( F_26 ( V_2 ) )
return false ;
if ( F_33 ( V_2 ) >= F_34 ( V_2 , 0 ) )
return false ;
if ( V_30 -> V_200 >= V_30 -> V_220 )
return false ;
return true ;
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_299 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_285 ) +
V_47 ) ;
int V_504 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_504 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_70 = V_71 ;
}
V_2 -> V_505 ( V_2 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
if ( F_226 ( V_2 , V_506 ) ) {
F_302 ( V_2 , V_506 ) ;
if ( V_2 -> V_499 &&
F_298 ( V_500 , & V_2 -> V_499 -> V_331 ) )
F_300 ( V_2 ) ;
}
}
static inline void F_303 ( struct V_1 * V_2 )
{
F_304 ( V_2 ) ;
F_301 ( V_2 ) ;
}
static void F_305 ( struct V_1 * V_2 , int V_507 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_81 - V_30 -> V_350 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_306 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_507 && F_244 ( & V_30 -> V_430 ) ) ) {
F_199 ( V_2 ) ;
} else {
F_307 ( V_2 ) ;
}
}
static inline void F_308 ( struct V_1 * V_2 )
{
if ( ! F_309 ( V_2 ) ) {
return;
}
F_305 ( V_2 , 1 ) ;
}
static void F_310 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_191 = F_141 ( V_41 -> V_508 ) ;
if ( V_191 && ! V_509 )
V_191 -- ;
V_191 += F_217 ( V_41 -> V_82 ) ;
if ( F_47 ( V_30 -> V_85 , V_191 ) )
return;
if ( F_40 ( V_191 , V_30 -> V_81 ) )
return;
if ( V_30 -> V_474 && ! F_47 ( V_191 , V_30 -> V_510 ) )
return;
F_311 ( V_2 ) ;
if ( V_30 -> V_510 == V_30 -> V_85 && V_30 -> V_474 &&
! F_226 ( V_2 , V_511 ) && V_30 -> V_85 != V_30 -> V_81 ) {
struct V_3 * V_4 = F_244 ( & V_2 -> V_448 ) ;
V_30 -> V_85 ++ ;
if ( V_4 && ! F_40 ( V_30 -> V_85 , F_16 ( V_4 ) -> V_84 ) ) {
F_245 ( V_4 , & V_2 -> V_448 ) ;
F_246 ( V_4 ) ;
}
}
V_30 -> V_474 = V_512 ;
V_30 -> V_510 = V_191 ;
V_30 -> V_341 = 0 ;
}
static void F_312 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_513 )
F_310 ( V_2 , V_41 ) ;
if ( V_30 -> V_474 == V_512 ) {
T_1 V_191 = V_30 -> V_510 - F_217 ( V_41 -> V_82 ) + ( V_41 -> V_375 * 4 ) -
V_41 -> V_43 ;
if ( V_191 < V_4 -> V_10 ) {
T_3 V_187 ;
if ( F_294 ( V_4 , V_191 , & V_187 , 1 ) )
F_295 () ;
V_30 -> V_474 = V_514 | V_187 ;
if ( ! F_226 ( V_2 , V_418 ) )
V_2 -> V_479 ( V_2 , 0 ) ;
}
}
}
static int F_313 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_515 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_475 = V_4 -> V_10 - V_515 ;
int V_153 ;
F_279 () ;
if ( F_314 ( V_4 ) )
V_153 = F_280 ( V_4 , V_515 , V_30 -> V_471 . V_477 , V_475 ) ;
else
V_153 = F_315 ( V_4 , V_515 ,
V_30 -> V_471 . V_477 ) ;
if ( ! V_153 ) {
V_30 -> V_471 . V_10 -= V_475 ;
V_30 -> V_85 += V_475 ;
F_42 ( V_2 ) ;
}
F_281 () ;
return V_153 ;
}
static T_12 F_316 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_12 V_516 ;
if ( F_277 ( V_2 ) ) {
F_279 () ;
V_516 = F_317 ( V_4 ) ;
F_281 () ;
} else {
V_516 = F_317 ( V_4 ) ;
}
return V_516 ;
}
static inline bool F_318 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_314 ( V_4 ) &&
F_316 ( V_2 , V_4 ) ;
}
static bool F_319 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_515 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_475 = V_4 -> V_10 - V_515 ;
int V_517 ;
bool V_518 = false ;
if ( V_30 -> V_471 . V_519 )
return false ;
if ( ! V_30 -> V_471 . V_520 && V_30 -> V_471 . V_521 )
V_30 -> V_471 . V_520 = F_320 () ;
if ( V_30 -> V_471 . V_520 && F_314 ( V_4 ) ) {
V_517 = F_321 ( V_30 -> V_471 . V_520 ,
V_4 , V_515 ,
V_30 -> V_471 . V_477 , V_475 ,
V_30 -> V_471 . V_521 ) ;
if ( V_517 < 0 )
goto V_182;
V_30 -> V_471 . V_517 = V_517 ;
V_518 = true ;
V_30 -> V_471 . V_10 -= V_475 ;
V_30 -> V_85 += V_475 ;
F_42 ( V_2 ) ;
if ( ( V_30 -> V_471 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_522 ) ||
( F_35 ( & V_2 -> V_72 ) > ( V_2 -> V_62 >> 1 ) ) ) {
V_30 -> V_471 . V_519 = 1 ;
V_2 -> V_479 ( V_2 , 0 ) ;
}
} else if ( V_475 > 0 ) {
V_30 -> V_471 . V_519 = 1 ;
V_2 -> V_479 ( V_2 , 0 ) ;
}
V_182:
return V_518 ;
}
static bool F_322 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_523 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_218 ( V_4 , V_41 , V_30 ) && V_30 -> V_45 . V_249 &&
F_221 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_524 ) {
F_59 ( F_60 ( V_2 ) , V_525 ) ;
F_238 ( V_2 , V_4 ) ;
goto V_526;
}
}
if ( ! F_222 ( V_30 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) {
if ( ! V_41 -> V_524 ) {
if ( V_41 -> V_43 )
goto V_527;
F_238 ( V_2 , V_4 ) ;
}
goto V_526;
}
if ( V_41 -> V_524 ) {
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 )
F_224 ( V_2 ) ;
else
F_198 ( V_2 ) ;
goto V_526;
}
if ( V_41 -> V_43 ) {
V_527:
if ( V_523 )
F_323 ( F_60 ( V_2 ) , V_528 ) ;
F_59 ( F_60 ( V_2 ) , V_529 ) ;
F_198 ( V_2 ) ;
goto V_526;
}
return true ;
V_526:
F_246 ( V_4 ) ;
return false ;
}
int F_324 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_91 ( V_2 -> V_530 == NULL ) )
F_2 ( V_2 ) -> V_531 -> V_532 ( V_2 , V_4 ) ;
V_30 -> V_45 . V_249 = 0 ;
if ( ( F_5 ( V_41 ) & V_533 ) == V_30 -> V_341 &&
F_16 ( V_4 ) -> V_82 == V_30 -> V_81 &&
! F_47 ( F_16 ( V_4 ) -> V_138 , V_30 -> V_98 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_407 ) {
if ( ! F_215 ( V_30 , V_41 ) )
goto V_534;
if ( ( T_5 ) ( V_30 -> V_45 . V_348 - V_30 -> V_45 . V_347 ) < 0 )
goto V_534;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_407 ) &&
V_30 -> V_81 == V_30 -> V_350 )
F_200 ( V_30 ) ;
F_205 ( V_2 , V_4 , 0 ) ;
F_246 ( V_4 ) ;
F_303 ( V_2 ) ;
return 0 ;
} else {
F_323 ( F_60 ( V_2 ) , V_528 ) ;
goto V_526;
}
} else {
int V_462 = 0 ;
int V_518 = 0 ;
bool V_453 = false ;
if ( V_30 -> V_85 == V_30 -> V_81 &&
V_10 - V_18 <= V_30 -> V_471 . V_10 ) {
#ifdef F_325
if ( V_30 -> V_471 . V_472 == V_473 &&
F_277 ( V_2 ) &&
F_319 ( V_2 , V_4 , V_18 ) ) {
V_518 = 1 ;
V_462 = 1 ;
}
#endif
if ( V_30 -> V_471 . V_472 == V_473 &&
F_277 ( V_2 ) && ! V_518 ) {
F_278 ( V_476 ) ;
if ( ! F_313 ( V_2 , V_4 , V_18 ) )
V_462 = 1 ;
}
if ( V_462 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_407 ) &&
V_30 -> V_81 == V_30 -> V_350 )
F_200 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
F_267 ( V_4 , V_18 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
F_59 ( F_60 ( V_2 ) , V_535 ) ;
}
if ( V_518 )
F_326 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_462 ) {
if ( F_318 ( V_2 , V_4 ) )
goto V_536;
if ( ( int ) V_4 -> V_51 > V_2 -> V_537 )
goto V_538;
if ( V_18 ==
( sizeof( struct V_15 ) + V_407 ) &&
V_30 -> V_81 == V_30 -> V_350 )
F_200 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
F_59 ( F_60 ( V_2 ) , V_539 ) ;
V_462 = F_266 ( V_2 , V_4 , V_18 ,
& V_453 ) ;
}
F_43 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_138 != V_30 -> V_96 ) {
F_205 ( V_2 , V_4 , V_361 ) ;
F_303 ( V_2 ) ;
if ( ! F_309 ( V_2 ) )
goto V_540;
}
if ( ! V_518 || V_30 -> V_81 != V_30 -> V_350 )
F_305 ( V_2 , 0 ) ;
V_540:
#ifdef F_325
if ( V_518 )
F_247 ( & V_2 -> V_541 , V_4 ) ;
else
#endif
if ( V_462 )
F_260 ( V_4 , V_453 ) ;
V_2 -> V_479 ( V_2 , 0 ) ;
return 0 ;
}
}
V_534:
if ( V_10 < ( V_41 -> V_375 << 2 ) || F_318 ( V_2 , V_4 ) )
goto V_536;
if ( ! V_41 -> V_306 && ! V_41 -> V_524 )
goto V_526;
if ( ! F_322 ( V_2 , V_4 , V_41 , 1 ) )
return 0 ;
V_538:
if ( F_205 ( V_2 , V_4 , V_358 | V_357 ) < 0 )
goto V_526;
F_41 ( V_2 , V_4 ) ;
F_312 ( V_2 , V_4 , V_41 ) ;
F_275 ( V_2 , V_4 ) ;
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
return 0 ;
V_536:
F_323 ( F_60 ( V_2 ) , V_542 ) ;
F_323 ( F_60 ( V_2 ) , V_528 ) ;
V_526:
F_246 ( V_4 ) ;
return 0 ;
}
void F_327 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_230 ( V_2 , V_424 ) ;
if ( V_4 != NULL ) {
V_6 -> V_531 -> V_532 ( V_2 , V_4 ) ;
F_328 ( V_2 , V_4 ) ;
}
V_6 -> V_531 -> V_543 ( V_2 ) ;
F_329 ( V_2 ) ;
F_330 ( V_2 ) ;
V_30 -> V_544 = V_71 ;
F_29 ( V_2 ) ;
if ( F_226 ( V_2 , V_545 ) )
F_331 ( V_2 , F_332 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_339 )
F_333 ( V_30 , V_30 -> V_338 ) ;
else
V_30 -> V_341 = 0 ;
if ( ! F_226 ( V_2 , V_418 ) ) {
V_2 -> V_431 ( V_2 ) ;
F_234 ( V_2 , V_546 , V_547 ) ;
}
}
static bool F_334 ( struct V_1 * V_2 , struct V_3 * V_548 ,
struct V_372 * V_549 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_550 ? F_92 ( V_2 ) : NULL ;
T_7 V_58 = V_30 -> V_45 . V_46 ;
bool V_551 ;
if ( V_58 == V_30 -> V_45 . V_383 ) {
struct V_369 V_552 ;
F_335 ( & V_552 ) ;
V_552 . V_383 = V_552 . V_46 = 0 ;
F_210 ( V_548 , & V_552 , 0 , NULL ) ;
V_58 = V_552 . V_46 ;
}
if ( ! V_30 -> V_553 )
V_549 -> V_10 = - 1 ;
V_551 = ( V_549 -> V_10 <= 0 && V_13 && V_30 -> V_554 ) ;
F_336 ( V_2 , V_58 , V_549 , V_551 ) ;
if ( V_13 ) {
F_97 (data, sk) {
if ( V_13 == F_71 ( V_2 ) ||
F_337 ( V_2 , V_13 ) )
break;
}
F_176 ( V_2 ) ;
return true ;
}
V_30 -> V_555 = V_30 -> V_550 ;
return false ;
}
static int F_338 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_372 V_373 = { . V_10 = - 1 } ;
int V_556 = V_30 -> V_45 . V_46 ;
F_210 ( V_4 , & V_30 -> V_45 , 0 , & V_373 ) ;
if ( V_30 -> V_45 . V_249 )
V_30 -> V_45 . V_83 -= V_30 -> V_406 ;
if ( V_41 -> V_306 ) {
if ( ! F_47 ( F_16 ( V_4 ) -> V_138 , V_30 -> V_96 ) ||
F_47 ( F_16 ( V_4 ) -> V_138 , V_30 -> V_98 ) )
goto V_557;
if ( V_30 -> V_45 . V_249 && V_30 -> V_45 . V_83 &&
! F_184 ( V_30 -> V_45 . V_83 , V_30 -> V_248 ,
V_71 ) ) {
F_59 ( F_60 ( V_2 ) , V_558 ) ;
goto V_557;
}
if ( V_41 -> V_524 ) {
F_224 ( V_2 ) ;
goto V_526;
}
if ( ! V_41 -> V_43 )
goto V_559;
F_17 ( V_30 , V_41 ) ;
F_339 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
F_205 ( V_2 , V_4 , V_358 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_350 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_338 = F_141 ( V_41 -> V_52 ) ;
if ( ! V_30 -> V_45 . V_387 ) {
V_30 -> V_45 . V_339 = V_30 -> V_45 . V_560 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_249 ) {
V_30 -> V_45 . V_391 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_407 ;
V_30 -> V_57 -= V_407 ;
F_200 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_132 ( V_30 ) && V_561 )
F_340 ( V_30 ) ;
F_341 ( V_2 ) ;
F_162 ( V_2 , V_6 -> V_287 ) ;
F_36 ( V_2 ) ;
V_30 -> V_85 = V_30 -> V_81 ;
F_342 () ;
F_327 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_553 || V_30 -> V_550 ) &&
F_334 ( V_2 , V_4 , & V_373 ) )
return - 1 ;
if ( V_2 -> V_562 ||
V_6 -> V_563 . V_564 ||
V_6 -> V_8 . V_26 ) {
F_44 ( V_2 ) ;
V_6 -> V_8 . V_89 = V_71 ;
F_10 ( V_2 ) ;
F_122 ( V_2 , V_565 ,
V_566 , V_229 ) ;
V_526:
F_246 ( V_4 ) ;
return 0 ;
} else {
F_199 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_524 ) {
goto V_559;
}
if ( V_30 -> V_45 . V_349 && V_30 -> V_45 . V_249 &&
F_343 ( & V_30 -> V_45 , 0 ) )
goto V_559;
if ( V_41 -> V_43 ) {
F_230 ( V_2 , V_423 ) ;
if ( V_30 -> V_45 . V_249 ) {
V_30 -> V_45 . V_391 = 1 ;
F_200 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_407 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_350 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_338 = F_141 ( V_41 -> V_52 ) ;
V_30 -> V_337 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_131 = V_30 -> V_338 ;
F_18 ( V_30 , V_41 ) ;
F_341 ( V_2 ) ;
F_162 ( V_2 , V_6 -> V_287 ) ;
F_36 ( V_2 ) ;
F_344 ( V_2 ) ;
#if 0
return -1;
#else
goto V_526;
#endif
}
V_559:
F_335 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_556 ;
goto V_526;
V_557:
F_335 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_556 ;
return 1 ;
}
int F_345 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_567 * V_568 ;
int V_569 = 0 ;
V_30 -> V_45 . V_249 = 0 ;
switch ( V_2 -> V_410 ) {
case V_416 :
goto V_526;
case V_570 :
if ( V_41 -> V_306 )
return 1 ;
if ( V_41 -> V_524 )
goto V_526;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_449 )
goto V_526;
if ( V_6 -> V_531 -> V_571 ( V_2 , V_4 ) < 0 )
return 1 ;
F_274 ( V_4 ) ;
return 0 ;
}
goto V_526;
case V_411 :
V_569 = F_338 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_569 >= 0 )
return V_569 ;
F_312 ( V_2 , V_4 , V_41 ) ;
F_246 ( V_4 ) ;
F_303 ( V_2 ) ;
return 0 ;
}
V_568 = V_30 -> V_309 ;
if ( V_568 != NULL ) {
F_273 ( V_2 -> V_410 != V_423 &&
V_2 -> V_410 != V_427 ) ;
if ( F_346 ( V_2 , V_4 , V_568 , NULL , true ) == NULL )
goto V_526;
}
if ( ! V_41 -> V_306 && ! V_41 -> V_524 )
goto V_526;
if ( ! F_322 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
if ( true ) {
int V_572 = F_205 ( V_2 , V_4 , V_358 |
V_357 ) > 0 ;
switch ( V_2 -> V_410 ) {
case V_423 :
if ( V_572 ) {
if ( V_568 ) {
F_347 ( V_2 , V_568 ) ;
V_30 -> V_554 = V_568 -> V_573 ;
F_348 ( V_2 , V_568 , false ) ;
} else {
V_6 -> V_531 -> V_543 ( V_2 ) ;
F_330 ( V_2 ) ;
F_341 ( V_2 ) ;
F_29 ( V_2 ) ;
V_30 -> V_85 = V_30 -> V_81 ;
}
F_342 () ;
F_230 ( V_2 , V_424 ) ;
V_2 -> V_431 ( V_2 ) ;
if ( V_2 -> V_499 )
F_234 ( V_2 ,
V_546 , V_547 ) ;
V_30 -> V_96 = F_16 ( V_4 ) -> V_138 ;
V_30 -> V_338 = F_141 ( V_41 -> V_52 ) <<
V_30 -> V_45 . V_339 ;
F_339 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_30 -> V_45 . V_391 )
V_30 -> V_57 -= V_407 ;
if ( V_568 ) {
F_176 ( V_2 ) ;
} else
F_329 ( V_2 ) ;
V_30 -> V_544 = V_71 ;
F_36 ( V_2 ) ;
F_349 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_427 :
if ( V_568 != NULL ) {
if ( ! V_572 )
return 1 ;
F_348 ( V_2 , V_568 , false ) ;
F_176 ( V_2 ) ;
}
if ( V_30 -> V_96 == V_30 -> V_574 ) {
struct V_99 * V_100 ;
F_230 ( V_2 , V_428 ) ;
V_2 -> V_420 |= V_575 ;
V_100 = F_206 ( V_2 ) ;
if ( V_100 )
F_207 ( V_100 ) ;
if ( ! F_226 ( V_2 , V_418 ) )
V_2 -> V_431 ( V_2 ) ;
else {
int V_576 ;
if ( V_30 -> V_577 < 0 ||
( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_449 , V_30 -> V_81 ) ) ) {
F_227 ( V_2 ) ;
F_59 ( F_60 ( V_2 ) , V_578 ) ;
return 1 ;
}
V_576 = F_350 ( V_2 ) ;
if ( V_576 > V_579 ) {
F_331 ( V_2 , V_576 - V_579 ) ;
} else if ( V_41 -> V_449 || F_277 ( V_2 ) ) {
F_331 ( V_2 , V_576 ) ;
} else {
F_231 ( V_2 , V_428 , V_576 ) ;
goto V_526;
}
}
}
break;
case V_425 :
if ( V_30 -> V_96 == V_30 -> V_574 ) {
F_231 ( V_2 , V_429 , 0 ) ;
goto V_526;
}
break;
case V_426 :
if ( V_30 -> V_96 == V_30 -> V_574 ) {
F_351 ( V_2 ) ;
F_227 ( V_2 ) ;
goto V_526;
}
break;
}
}
F_312 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_410 ) {
case V_414 :
case V_425 :
case V_426 :
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
case V_427 :
case V_428 :
if ( V_2 -> V_420 & V_421 ) {
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_449 , V_30 -> V_81 ) ) {
F_59 ( F_60 ( V_2 ) , V_578 ) ;
F_224 ( V_2 ) ;
return 1 ;
}
}
case V_424 :
F_275 ( V_2 , V_4 ) ;
V_569 = 1 ;
break;
}
if ( V_2 -> V_410 != V_416 ) {
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
}
if ( ! V_569 ) {
V_526:
F_246 ( V_4 ) ;
}
return 0 ;
}
