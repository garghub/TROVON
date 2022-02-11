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
const struct V_5 * V_6 = F_2 ( V_2 ) ;
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
if ( F_47 ( V_84 , V_30 -> V_164 ) )
V_159 . V_165 &= ~ V_166 ;
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
( ( V_6 -> V_118 != V_207 ) || V_30 -> V_121 ) &&
( ! V_30 -> V_164 || F_47 ( V_30 -> V_96 , V_30 -> V_164 ) ) )
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
static int F_113 ( const struct V_29 * V_30 )
{
return ( V_211 == 0x2 ) && ! F_58 ( V_30 ) ;
}
bool F_114 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_211 )
return false ;
if ( V_6 -> V_212 . V_213 )
return false ;
if ( F_113 ( V_30 ) )
return true ;
if ( V_30 -> V_135 > 1 )
return false ;
V_4 = F_92 ( V_2 ) ;
if ( F_115 ( V_2 , V_4 ) )
return true ;
V_4 = F_95 ( V_2 , V_4 ) ;
F_97 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_126 & V_162 )
return false ;
if ( ! ( F_16 ( V_4 ) -> V_126 & V_128 ) )
break;
}
return true ;
}
void F_116 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ( ! V_30 -> V_214 && V_6 -> V_118 <= V_215 ) ||
V_30 -> V_96 == V_30 -> V_216 ||
( ( V_6 -> V_118 == V_207 || V_30 -> V_214 ) &&
! V_6 -> V_217 ) ) {
V_30 -> V_218 = F_117 ( V_2 ) ;
if ( V_30 -> V_214 ) {
T_1 V_219 ;
V_219 = V_30 -> V_220 ;
V_30 -> V_220 = 2 ;
V_30 -> V_221 = V_6 -> V_222 -> V_223 ( V_2 ) ;
V_30 -> V_220 = V_219 ;
} else {
V_30 -> V_221 = V_6 -> V_222 -> V_223 ( V_2 ) ;
}
F_118 ( V_2 , V_224 ) ;
}
V_30 -> V_121 = V_30 -> V_96 ;
V_30 -> V_122 = 0 ;
V_4 = F_92 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_126 & V_162 )
V_30 -> V_121 = 0 ;
if ( F_16 ( V_4 ) -> V_126 & V_139 ) {
F_16 ( V_4 ) -> V_126 &= ~ V_139 ;
V_30 -> V_135 -= F_65 ( V_4 ) ;
}
F_106 ( V_30 ) ;
V_30 -> V_220 = F_9 ( V_30 -> V_220 , F_107 ( V_30 ) + 1 ) ;
if ( F_113 ( V_30 ) && ( V_30 -> V_214 ||
( ( 1 << V_6 -> V_118 ) & ( V_225 | V_226 ) ) ) &&
F_47 ( V_30 -> V_216 , V_30 -> V_96 ) ) {
V_30 -> V_164 = V_30 -> V_216 ;
} else {
V_30 -> V_164 = V_30 -> V_98 ;
}
F_119 ( V_2 , V_215 ) ;
V_30 -> V_216 = V_30 -> V_98 ;
V_30 -> V_214 = 1 ;
}
static void F_120 ( struct V_1 * V_2 , int V_227 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
V_30 -> V_124 = 0 ;
V_30 -> V_135 = 0 ;
if ( F_58 ( V_30 ) )
F_112 ( V_30 ) ;
F_70 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_126 &= ~ V_127 ;
if ( ( V_30 -> V_214 == 1 ) && ! ( V_165 & V_228 ) ) {
if ( F_16 ( V_4 ) -> V_126 & V_139 )
V_30 -> V_135 += F_65 ( V_4 ) ;
V_165 |= V_228 ;
} else {
if ( F_16 ( V_4 ) -> V_126 & V_162 )
V_30 -> V_121 = 0 ;
F_16 ( V_4 ) -> V_126 &= ~ V_139 ;
}
if ( ! ( F_16 ( V_4 ) -> V_126 & V_128 ) ) {
F_16 ( V_4 ) -> V_126 |= V_127 ;
V_30 -> V_124 += F_65 ( V_4 ) ;
V_30 -> V_125 = F_16 ( V_4 ) -> V_84 ;
}
}
F_106 ( V_30 ) ;
V_30 -> V_220 = F_107 ( V_30 ) + V_227 ;
V_30 -> V_229 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_214 = 0 ;
V_30 -> V_230 = 0 ;
V_30 -> V_110 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_119 ( V_2 , V_207 ) ;
V_30 -> V_216 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
F_121 ( V_30 ) ;
}
static void F_122 ( struct V_29 * V_30 )
{
V_30 -> V_135 = 0 ;
V_30 -> V_124 = 0 ;
V_30 -> V_121 = 0 ;
V_30 -> V_122 = 0 ;
}
void F_123 ( struct V_29 * V_30 )
{
F_122 ( V_30 ) ;
V_30 -> V_119 = 0 ;
V_30 -> V_120 = 0 ;
}
void F_124 ( struct V_1 * V_2 , int V_231 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_6 -> V_118 <= V_215 || V_30 -> V_96 == V_30 -> V_216 ||
( V_6 -> V_118 == V_207 && ! V_6 -> V_217 ) ) {
V_30 -> V_218 = F_117 ( V_2 ) ;
V_30 -> V_221 = V_6 -> V_222 -> V_223 ( V_2 ) ;
F_118 ( V_2 , V_232 ) ;
}
V_30 -> V_220 = 1 ;
V_30 -> V_229 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_230 = 0 ;
F_122 ( V_30 ) ;
if ( F_58 ( V_30 ) )
F_112 ( V_30 ) ;
if ( ! V_231 ) {
V_30 -> V_121 = V_30 -> V_96 ;
} else {
V_30 -> V_120 = 0 ;
V_30 -> V_119 = 0 ;
}
F_121 ( V_30 ) ;
F_70 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_126 & V_162 )
V_30 -> V_121 = 0 ;
F_16 ( V_4 ) -> V_126 &= ( ~ V_180 ) | V_128 ;
if ( ! ( F_16 ( V_4 ) -> V_126 & V_128 ) || V_231 ) {
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
V_30 -> V_216 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
V_30 -> V_214 = 0 ;
}
static bool F_125 ( struct V_1 * V_2 , int V_165 )
{
if ( V_165 & V_233 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_59 ( F_60 ( V_2 ) , V_234 ) ;
F_124 ( V_2 , 1 ) ;
V_6 -> V_217 ++ ;
F_126 ( V_2 , F_92 ( V_2 ) ) ;
F_127 ( V_2 , V_235 ,
V_6 -> V_90 , V_236 ) ;
return true ;
}
return false ;
}
static inline int F_128 ( const struct V_29 * V_30 )
{
return F_58 ( V_30 ) ? V_30 -> V_120 + 1 : V_30 -> V_119 ;
}
static inline int F_129 ( const struct V_29 * V_30 )
{
return F_55 ( V_30 ) ? V_30 -> V_119 : V_30 -> V_120 + 1 ;
}
static bool F_130 ( struct V_1 * V_2 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_237 ;
if ( V_238 < 2 || ( V_165 & V_239 ) || ! V_30 -> V_92 )
return false ;
V_237 = F_27 (unsigned long, (tp->srtt >> 5), msecs_to_jiffies(2)) ;
if ( ! F_131 ( F_2 ( V_2 ) -> V_240 , ( V_241 + V_237 ) ) )
return false ;
F_127 ( V_2 , V_235 , V_237 , V_236 ) ;
V_30 -> V_242 = 1 ;
return true ;
}
static inline int F_132 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_71 - F_16 ( V_4 ) -> V_243 > F_2 ( V_2 ) -> V_90 ;
}
static inline int F_133 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_200 &&
F_132 ( V_2 , F_92 ( V_2 ) ) ;
}
static bool F_134 ( struct V_1 * V_2 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_200 ;
if ( V_30 -> V_214 )
return false ;
if ( V_30 -> V_124 )
return true ;
if ( F_129 ( V_30 ) > V_30 -> V_110 )
return true ;
if ( F_55 ( V_30 ) && F_133 ( V_2 ) )
return true ;
V_200 = V_30 -> V_200 ;
if ( V_200 <= V_30 -> V_110 &&
V_30 -> V_120 >= F_27 ( T_2 , V_200 / 2 , V_244 ) &&
! F_135 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_245 || V_246 ) &&
F_136 ( V_30 ) && F_129 ( V_30 ) > 1 &&
F_137 ( V_30 ) && ! F_71 ( V_2 ) )
return true ;
if ( V_30 -> V_247 && ! V_30 -> V_135 && V_30 -> V_120 &&
( V_30 -> V_200 == ( V_30 -> V_120 + 1 ) && V_30 -> V_200 < 4 ) &&
! F_135 ( V_2 ) )
return ! F_130 ( V_2 , V_165 ) ;
return false ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_55 ( V_30 ) || ! F_133 ( V_2 ) )
return;
V_4 = V_30 -> V_176 ;
if ( V_30 -> V_176 == NULL )
V_4 = F_92 ( V_2 ) ;
F_97 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
if ( ! F_132 ( V_2 , V_4 ) )
break;
F_64 ( V_30 , V_4 ) ;
}
V_30 -> V_176 = V_4 ;
F_106 ( V_30 ) ;
}
static void F_139 ( struct V_1 * V_2 , int V_248 , int V_249 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_132 , V_250 ;
int V_153 ;
unsigned int V_58 ;
const T_1 V_251 = F_137 ( V_30 ) ? V_30 -> V_98 : V_30 -> V_216 ;
F_103 ( V_248 > V_30 -> V_200 ) ;
if ( V_30 -> V_104 ) {
V_4 = V_30 -> V_104 ;
V_132 = V_30 -> V_168 ;
if ( V_249 && V_4 != F_92 ( V_2 ) )
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
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_251 ) )
break;
V_250 = V_132 ;
if ( F_55 ( V_30 ) || F_58 ( V_30 ) ||
( F_16 ( V_4 ) -> V_126 & V_128 ) )
V_132 += F_65 ( V_4 ) ;
if ( V_132 > V_248 ) {
if ( ( F_137 ( V_30 ) && ! F_55 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_126 & V_128 ) ||
( V_250 >= V_248 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_153 = F_76 ( V_2 , V_4 , ( V_248 - V_250 ) * V_58 , V_58 ) ;
if ( V_153 < 0 )
break;
V_132 = V_248 ;
}
F_64 ( V_30 , V_4 ) ;
if ( V_249 )
break;
}
F_106 ( V_30 ) ;
}
static void F_140 ( struct V_1 * V_2 , int V_252 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_58 ( V_30 ) ) {
F_139 ( V_2 , 1 , 1 ) ;
} else if ( F_55 ( V_30 ) ) {
int V_253 = V_30 -> V_119 - V_30 -> V_110 ;
if ( V_253 <= 0 )
V_253 = 1 ;
F_139 ( V_2 , V_253 , 0 ) ;
} else {
int V_254 = V_30 -> V_120 - V_30 -> V_110 ;
if ( V_254 >= 0 )
F_139 ( V_2 , V_254 , 0 ) ;
else if ( V_252 )
F_139 ( V_2 , 1 , 1 ) ;
}
F_138 ( V_2 ) ;
}
static inline void F_141 ( struct V_29 * V_30 )
{
V_30 -> V_220 = F_9 ( V_30 -> V_220 ,
F_107 ( V_30 ) + F_142 ( V_30 ) ) ;
V_30 -> V_70 = V_71 ;
}
static inline bool F_143 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_255 ||
( V_30 -> V_45 . V_256 && V_30 -> V_45 . V_83 &&
F_40 ( V_30 -> V_45 . V_83 , V_30 -> V_255 ) ) ;
}
static void F_144 ( struct V_1 * V_2 , const char * V_257 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_258 * V_259 = F_145 ( V_2 ) ;
if ( V_2 -> V_260 == V_261 ) {
F_61 ( L_2 ,
V_257 ,
& V_259 -> V_262 , F_146 ( V_259 -> V_263 ) ,
V_30 -> V_220 , F_147 ( V_30 ) ,
V_30 -> V_221 , V_30 -> V_218 ,
V_30 -> V_200 ) ;
}
#if F_148 ( V_264 )
else if ( V_2 -> V_260 == V_265 ) {
struct V_266 * V_267 = F_149 ( V_2 ) ;
F_61 ( L_3 ,
V_257 ,
& V_267 -> V_268 , F_146 ( V_259 -> V_263 ) ,
V_30 -> V_220 , F_147 ( V_30 ) ,
V_30 -> V_221 , V_30 -> V_218 ,
V_30 -> V_200 ) ;
}
#endif
}
static void F_150 ( struct V_1 * V_2 , const bool V_269 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_218 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_222 -> V_270 )
V_30 -> V_220 = V_6 -> V_222 -> V_270 ( V_2 ) ;
else
V_30 -> V_220 = F_31 ( V_30 -> V_220 , V_30 -> V_221 << 1 ) ;
if ( V_269 && V_30 -> V_218 > V_30 -> V_221 ) {
V_30 -> V_221 = V_30 -> V_218 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_220 = F_31 ( V_30 -> V_220 , V_30 -> V_221 ) ;
}
V_30 -> V_70 = V_71 ;
}
static inline bool F_151 ( const struct V_29 * V_30 )
{
return V_30 -> V_121 && ( ! V_30 -> V_122 || F_143 ( V_30 ) ) ;
}
static bool F_152 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_151 ( V_30 ) ) {
int V_111 ;
F_144 ( V_2 , F_2 ( V_2 ) -> V_118 == V_207 ? L_4 : L_5 ) ;
F_150 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_118 == V_207 )
V_111 = V_271 ;
else
V_111 = V_272 ;
F_59 ( F_60 ( V_2 ) , V_111 ) ;
V_30 -> V_121 = 0 ;
}
if ( V_30 -> V_96 == V_30 -> V_216 && F_58 ( V_30 ) ) {
F_141 ( V_30 ) ;
return true ;
}
F_119 ( V_2 , V_273 ) ;
return false ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_121 && ! V_30 -> V_122 ) {
F_144 ( V_2 , L_6 ) ;
F_150 ( V_2 , true ) ;
V_30 -> V_121 = 0 ;
F_59 ( F_60 ( V_2 ) , V_274 ) ;
}
}
static bool F_154 ( const struct V_1 * V_2 )
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
static int F_155 ( struct V_1 * V_2 , int V_210 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_275 = F_58 ( V_30 ) || ( F_128 ( V_30 ) > V_30 -> V_110 ) ;
if ( F_151 ( V_30 ) ) {
if ( ! F_154 ( V_2 ) )
V_30 -> V_255 = 0 ;
F_57 ( V_2 , F_128 ( V_30 ) + V_210 , 1 ) ;
F_144 ( V_2 , L_7 ) ;
F_150 ( V_2 , false ) ;
F_59 ( F_60 ( V_2 ) , V_276 ) ;
V_275 = 0 ;
}
return V_275 ;
}
static bool F_156 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_151 ( V_30 ) ) {
struct V_3 * V_4 ;
F_70 (skb, sk) {
if ( V_4 == F_71 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_126 &= ~ V_127 ;
}
F_121 ( V_30 ) ;
F_144 ( V_2 , L_8 ) ;
V_30 -> V_124 = 0 ;
F_150 ( V_2 , true ) ;
F_59 ( F_60 ( V_2 ) , V_271 ) ;
F_2 ( V_2 ) -> V_217 = 0 ;
V_30 -> V_121 = 0 ;
if ( F_137 ( V_30 ) )
F_119 ( V_2 , V_273 ) ;
return true ;
}
return false ;
}
static void F_157 ( struct V_1 * V_2 , const bool V_277 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_216 = V_30 -> V_98 ;
V_30 -> V_230 = 0 ;
V_30 -> V_229 = 0 ;
V_30 -> V_278 = V_30 -> V_220 ;
V_30 -> V_279 = 0 ;
V_30 -> V_280 = 0 ;
if ( V_277 )
V_30 -> V_221 = F_2 ( V_2 ) -> V_222 -> V_223 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_158 ( struct V_1 * V_2 , int V_281 ,
int V_252 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_282 = 0 ;
int V_283 = V_30 -> V_221 - F_107 ( V_30 ) ;
V_30 -> V_279 += V_281 ;
if ( F_107 ( V_30 ) > V_30 -> V_221 ) {
T_4 V_284 = ( T_4 ) V_30 -> V_221 * V_30 -> V_279 +
V_30 -> V_278 - 1 ;
V_282 = F_159 ( V_284 , V_30 -> V_278 ) - V_30 -> V_280 ;
} else {
V_282 = F_37 ( int , V_283 ,
F_27 ( int , V_30 -> V_279 - V_30 -> V_280 ,
V_281 ) + 1 ) ;
}
V_282 = F_31 ( V_282 , ( V_252 ? 1 : 0 ) ) ;
V_30 -> V_220 = F_107 ( V_30 ) + V_282 ;
}
static inline void F_160 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_118 == V_285 ||
( V_30 -> V_121 && V_30 -> V_221 < V_286 ) ) {
V_30 -> V_220 = V_30 -> V_221 ;
V_30 -> V_70 = V_71 ;
}
F_118 ( V_2 , V_287 ) ;
}
void F_161 ( struct V_1 * V_2 , const int V_277 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_218 = 0 ;
V_30 -> V_230 = 0 ;
if ( F_2 ( V_2 ) -> V_118 < V_285 ) {
V_30 -> V_121 = 0 ;
F_157 ( V_2 , V_277 ) ;
F_119 ( V_2 , V_285 ) ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_159 = V_273 ;
if ( F_147 ( V_30 ) || F_154 ( V_2 ) )
V_159 = V_215 ;
if ( F_2 ( V_2 ) -> V_118 != V_159 ) {
F_119 ( V_2 , V_159 ) ;
V_30 -> V_216 = V_30 -> V_98 ;
}
}
static void F_163 ( struct V_1 * V_2 , int V_165 , int V_281 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_106 ( V_30 ) ;
if ( ! V_30 -> V_214 && ! F_154 ( V_2 ) )
V_30 -> V_255 = 0 ;
if ( V_165 & V_239 )
F_161 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_118 != V_285 ) {
F_162 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_118 != V_273 )
F_141 ( V_30 ) ;
} else {
F_158 ( V_2 , V_281 , 0 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_212 . V_288 = V_6 -> V_212 . V_213 - 1 ;
V_6 -> V_212 . V_213 = 0 ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_218 = F_117 ( V_2 ) ;
V_30 -> V_220 = V_30 -> V_220 *
F_166 ( V_2 , V_30 -> V_289 ) /
V_6 -> V_212 . V_213 ;
V_30 -> V_229 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_221 = F_117 ( V_2 ) ;
V_6 -> V_212 . V_290 = V_6 -> V_212 . V_213 ;
V_6 -> V_212 . V_213 = 0 ;
F_167 ( V_2 , V_6 -> V_291 ) ;
}
void F_168 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_169 ( V_2 ) ;
T_1 V_292 = V_30 -> V_124 ;
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
F_170 ( V_30 ) ;
if ( V_292 == V_30 -> V_124 )
return;
if ( F_58 ( V_30 ) )
F_108 ( V_30 ) ;
F_106 ( V_30 ) ;
if ( V_6 -> V_118 != V_207 ) {
V_30 -> V_216 = V_30 -> V_98 ;
V_30 -> V_221 = F_117 ( V_2 ) ;
V_30 -> V_218 = 0 ;
V_30 -> V_121 = 0 ;
F_119 ( V_2 , V_207 ) ;
}
F_171 ( V_2 ) ;
}
static void F_172 ( struct V_1 * V_2 , bool V_293 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_111 ;
if ( F_58 ( V_30 ) )
V_111 = V_294 ;
else
V_111 = V_295 ;
F_59 ( F_60 ( V_2 ) , V_111 ) ;
V_30 -> V_218 = 0 ;
V_30 -> V_121 = V_30 -> V_96 ;
V_30 -> V_122 = V_30 -> V_135 ;
if ( F_2 ( V_2 ) -> V_118 < V_285 ) {
if ( ! V_293 )
V_30 -> V_218 = F_117 ( V_2 ) ;
F_157 ( V_2 , true ) ;
}
F_119 ( V_2 , V_137 ) ;
}
static void F_173 ( struct V_1 * V_2 , int V_296 ,
int V_297 , bool V_298 ,
int V_165 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_299 = V_298 || ( ( V_165 & V_167 ) &&
( F_128 ( V_30 ) > V_30 -> V_110 ) ) ;
int V_281 = 0 ;
int V_252 = 0 ;
if ( F_103 ( ! V_30 -> V_200 && V_30 -> V_120 ) )
V_30 -> V_120 = 0 ;
if ( F_103 ( ! V_30 -> V_120 && V_30 -> V_119 ) )
V_30 -> V_119 = 0 ;
if ( V_165 & V_239 )
V_30 -> V_218 = 0 ;
if ( F_125 ( V_2 , V_165 ) )
return;
F_106 ( V_30 ) ;
if ( V_6 -> V_118 == V_273 ) {
F_103 ( V_30 -> V_135 != 0 ) ;
V_30 -> V_255 = 0 ;
} else if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_216 ) ) {
switch ( V_6 -> V_118 ) {
case V_207 :
V_6 -> V_217 = 0 ;
if ( F_152 ( V_2 ) )
return;
break;
case V_285 :
if ( V_30 -> V_96 != V_30 -> V_216 ) {
F_160 ( V_2 ) ;
F_119 ( V_2 , V_273 ) ;
}
break;
case V_137 :
if ( F_58 ( V_30 ) )
F_112 ( V_30 ) ;
if ( F_152 ( V_2 ) )
return;
F_160 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_118 ) {
case V_137 :
if ( ! ( V_165 & V_300 ) ) {
if ( F_58 ( V_30 ) && V_298 )
F_110 ( V_2 ) ;
} else
V_299 = F_155 ( V_2 , V_296 ) ;
V_281 = V_296 + V_30 -> V_120 - V_297 ;
break;
case V_207 :
if ( V_165 & V_228 )
V_6 -> V_217 = 0 ;
if ( F_58 ( V_30 ) && V_165 & V_300 )
F_112 ( V_30 ) ;
if ( ! F_156 ( V_2 ) ) {
F_141 ( V_30 ) ;
F_171 ( V_2 ) ;
return;
}
if ( V_6 -> V_118 != V_273 )
return;
default:
if ( F_58 ( V_30 ) ) {
if ( V_165 & V_300 )
F_112 ( V_30 ) ;
if ( V_298 )
F_110 ( V_2 ) ;
}
V_281 = V_296 + V_30 -> V_120 - V_297 ;
if ( V_6 -> V_118 <= V_215 )
F_153 ( V_2 ) ;
if ( ! F_134 ( V_2 , V_165 ) ) {
F_163 ( V_2 , V_165 , V_281 ) ;
return;
}
if ( V_6 -> V_118 < V_285 &&
V_6 -> V_212 . V_213 &&
V_30 -> V_96 == V_30 -> V_301 . V_302 ) {
F_164 ( V_2 ) ;
V_30 -> V_220 ++ ;
F_168 ( V_2 ) ;
return;
}
F_172 ( V_2 , ( V_165 & V_239 ) ) ;
V_252 = 1 ;
}
if ( V_299 || ( F_55 ( V_30 ) && F_133 ( V_2 ) ) )
F_140 ( V_2 , V_252 ) ;
F_158 ( V_2 , V_281 , V_252 ) ;
F_171 ( V_2 ) ;
}
void F_174 ( struct V_1 * V_2 , T_1 V_303 )
{
F_46 ( V_2 , V_303 ) ;
F_49 ( V_2 ) ;
F_2 ( V_2 ) -> V_304 = 0 ;
}
static void F_175 ( struct V_1 * V_2 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_174 ( V_2 , V_71 - V_30 -> V_45 . V_83 ) ;
}
static void F_176 ( struct V_1 * V_2 , T_1 V_303 , int V_165 )
{
if ( V_165 & V_305 )
return;
F_174 ( V_2 , V_303 ) ;
}
static inline void F_177 ( struct V_1 * V_2 , const int V_165 ,
const T_5 V_303 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_256 && V_30 -> V_45 . V_83 )
F_175 ( V_2 , V_165 ) ;
else if ( V_303 >= 0 )
F_176 ( V_2 , V_303 , V_165 ) ;
}
static void F_178 ( struct V_1 * V_2 , T_1 V_306 , T_1 V_307 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_222 -> V_308 ( V_2 , V_306 , V_307 ) ;
F_7 ( V_2 ) -> V_70 = V_71 ;
}
void F_179 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_309 )
return;
if ( ! V_30 -> V_200 ) {
F_180 ( V_2 , V_235 ) ;
} else {
T_1 V_310 = F_2 ( V_2 ) -> V_90 ;
if ( V_30 -> V_242 ) {
struct V_3 * V_4 = F_92 ( V_2 ) ;
const T_1 V_311 = F_16 ( V_4 ) -> V_243 + V_310 ;
T_5 V_283 = ( T_5 ) ( V_311 - V_71 ) ;
if ( V_283 > 0 )
V_310 = V_283 ;
}
F_127 ( V_2 , V_235 , V_310 ,
V_236 ) ;
}
V_30 -> V_242 = 0 ;
}
void F_181 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_179 ( V_2 ) ;
if ( ! V_30 -> V_247 )
return;
F_172 ( V_2 , false ) ;
F_140 ( V_2 , 1 ) ;
F_171 ( V_2 ) ;
}
static T_1 F_182 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_312 ;
F_80 ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) ) ;
V_312 = F_65 ( V_4 ) ;
if ( F_183 ( V_2 , V_4 , V_30 -> V_96 - F_16 ( V_4 ) -> V_82 ) )
return 0 ;
V_312 -= F_65 ( V_4 ) ;
if ( V_312 ) {
F_80 ( F_65 ( V_4 ) == 0 ) ;
F_80 ( ! F_40 ( F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) ;
}
return V_312 ;
}
static int F_184 ( struct V_1 * V_2 , int V_313 ,
T_1 V_145 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_88 = V_71 ;
int V_314 = true ;
int V_165 = 0 ;
T_1 V_296 = 0 ;
T_1 V_163 = V_30 -> V_200 ;
T_1 V_297 = V_30 -> V_120 ;
T_5 V_303 = - 1 ;
T_5 V_315 = - 1 ;
T_6 V_316 = F_185 () ;
while ( ( V_4 = F_92 ( V_2 ) ) && V_4 != F_71 ( V_2 ) ) {
struct V_317 * V_318 = F_16 ( V_4 ) ;
T_1 V_319 ;
T_3 V_126 = V_318 -> V_126 ;
if ( F_47 ( V_318 -> V_84 , V_30 -> V_96 ) ) {
if ( F_65 ( V_4 ) == 1 ||
! F_47 ( V_30 -> V_96 , V_318 -> V_82 ) )
break;
V_319 = F_182 ( V_2 , V_4 ) ;
if ( ! V_319 )
break;
V_314 = false ;
} else {
V_319 = F_65 ( V_4 ) ;
}
if ( V_126 & V_162 ) {
if ( V_126 & V_139 )
V_30 -> V_135 -= V_319 ;
V_165 |= V_305 ;
V_315 = - 1 ;
V_303 = - 1 ;
if ( ( V_165 & V_228 ) || ( V_319 > 1 ) )
V_165 |= V_320 ;
} else {
V_315 = V_88 - V_318 -> V_243 ;
V_316 = V_4 -> V_321 ;
if ( V_303 < 0 ) {
V_303 = V_315 ;
}
if ( ! ( V_126 & V_128 ) )
V_163 = F_9 ( V_296 , V_163 ) ;
}
if ( V_126 & V_128 )
V_30 -> V_120 -= V_319 ;
if ( V_126 & V_127 )
V_30 -> V_124 -= V_319 ;
V_30 -> V_200 -= V_319 ;
V_296 += V_319 ;
if ( ! ( V_318 -> V_177 & V_322 ) ) {
V_165 |= V_228 ;
} else {
V_165 |= V_323 ;
V_30 -> V_255 = 0 ;
}
if ( ! V_314 )
break;
F_83 ( V_4 , V_2 ) ;
F_84 ( V_2 , V_4 ) ;
V_30 -> V_176 = NULL ;
if ( V_4 == V_30 -> V_123 )
V_30 -> V_123 = NULL ;
if ( V_4 == V_30 -> V_104 )
V_30 -> V_104 = NULL ;
}
if ( F_186 ( F_187 ( V_30 -> V_324 , V_145 , V_30 -> V_96 ) ) )
V_30 -> V_324 = V_30 -> V_96 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_126 & V_128 ) )
V_165 |= V_233 ;
if ( V_165 & V_325 ) {
const struct V_326 * V_327
= F_2 ( V_2 ) -> V_222 ;
if ( F_91 ( V_6 -> V_212 . V_213 &&
! F_47 ( V_30 -> V_301 . V_328 , V_30 -> V_96 ) ) ) {
F_165 ( V_2 ) ;
}
F_177 ( V_2 , V_165 , V_303 ) ;
F_179 ( V_2 ) ;
if ( F_58 ( V_30 ) ) {
F_111 ( V_2 , V_296 ) ;
} else {
int V_283 ;
if ( V_163 < V_313 )
F_57 ( V_2 , V_30 -> V_119 - V_163 , 0 ) ;
V_283 = F_55 ( V_30 ) ? V_296 :
V_297 - V_30 -> V_120 ;
V_30 -> V_168 -= F_9 ( V_30 -> V_168 , V_283 ) ;
}
V_30 -> V_119 -= F_9 ( V_296 , V_30 -> V_119 ) ;
if ( V_327 -> V_296 ) {
T_5 V_329 = - 1 ;
if ( ! ( V_165 & V_305 ) ) {
if ( V_327 -> V_330 & V_331 &&
! F_188 ( V_316 ,
F_185 () ) )
V_329 = F_189 ( F_190 () ,
V_316 ) ;
else if ( V_315 >= 0 )
V_329 = F_191 ( V_315 ) ;
}
V_327 -> V_296 ( V_2 , V_296 , V_329 ) ;
}
}
#if V_117 > 0
F_103 ( ( int ) V_30 -> V_120 < 0 ) ;
F_103 ( ( int ) V_30 -> V_124 < 0 ) ;
F_103 ( ( int ) V_30 -> V_135 < 0 ) ;
if ( ! V_30 -> V_200 && F_137 ( V_30 ) ) {
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
static void F_192 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_47 ( F_16 ( F_71 ( V_2 ) ) -> V_84 , F_193 ( V_30 ) ) ) {
V_6 -> V_304 = 0 ;
F_180 ( V_2 , V_332 ) ;
} else {
F_127 ( V_2 , V_332 ,
F_9 ( V_6 -> V_90 << V_6 -> V_304 , V_236 ) ,
V_236 ) ;
}
}
static inline bool F_194 ( const struct V_1 * V_2 , const int V_165 )
{
return ! ( V_165 & V_333 ) || ( V_165 & V_334 ) ||
F_2 ( V_2 ) -> V_118 != V_273 ;
}
static inline bool F_195 ( const struct V_1 * V_2 , const int V_165 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_165 & V_239 ) || V_30 -> V_220 < V_30 -> V_221 ) &&
! F_196 ( V_2 ) ;
}
static inline bool F_197 ( const struct V_29 * V_30 ,
const T_1 V_306 , const T_1 V_138 ,
const T_1 V_335 )
{
return F_47 ( V_306 , V_30 -> V_96 ) ||
F_47 ( V_138 , V_30 -> V_336 ) ||
( V_138 == V_30 -> V_336 && V_335 > V_30 -> V_337 ) ;
}
static int F_198 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_306 ,
T_1 V_138 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_165 = 0 ;
T_1 V_335 = F_146 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_186 ( ! F_6 ( V_4 ) -> V_43 ) )
V_335 <<= V_30 -> V_45 . V_338 ;
if ( F_197 ( V_30 , V_306 , V_138 , V_335 ) ) {
V_165 |= V_339 ;
F_199 ( V_30 , V_138 ) ;
if ( V_30 -> V_337 != V_335 ) {
V_30 -> V_337 = V_335 ;
V_30 -> V_340 = 0 ;
F_200 ( V_2 ) ;
if ( V_335 > V_30 -> V_131 ) {
V_30 -> V_131 = V_335 ;
F_167 ( V_2 , F_2 ( V_2 ) -> V_291 ) ;
}
}
}
V_30 -> V_96 = V_306 ;
return V_165 ;
}
static void F_201 ( struct V_29 * V_30 )
{
V_30 -> V_220 = F_9 ( V_30 -> V_220 , V_30 -> V_221 ) ;
V_30 -> V_229 = 0 ;
V_30 -> V_230 = 0 ;
F_12 ( V_30 ) ;
F_141 ( V_30 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
F_161 ( V_2 , 0 ) ;
}
static void F_203 ( struct V_1 * V_2 , int V_165 )
{
if ( V_165 & V_239 )
F_202 ( V_2 ) ;
else
F_150 ( V_2 , true ) ;
}
static bool F_204 ( struct V_1 * V_2 , int V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_106 ( V_30 ) ;
if ( V_165 & V_228 )
F_2 ( V_2 ) -> V_217 = 0 ;
if ( ( V_165 & V_320 ) ||
( ( V_30 -> V_214 >= 2 ) && ( V_165 & V_305 ) ) )
V_30 -> V_121 = 0 ;
if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_164 ) ) {
F_120 ( V_2 , ( V_30 -> V_214 == 1 ? 2 : 3 ) , V_165 ) ;
return true ;
}
if ( ! F_113 ( V_30 ) ) {
if ( ! ( V_165 & V_341 ) && ( V_165 & V_333 ) )
return true ;
if ( ! ( V_165 & V_228 ) ) {
F_120 ( V_2 , ( V_30 -> V_214 == 1 ? 0 : 3 ) ,
V_165 ) ;
return true ;
}
} else {
if ( ! ( V_165 & V_228 ) && ( V_30 -> V_214 == 1 ) ) {
V_30 -> V_220 = F_9 ( V_30 -> V_220 ,
F_107 ( V_30 ) ) ;
return true ;
}
if ( ( V_30 -> V_214 >= 2 ) &&
( ! ( V_165 & V_342 ) ||
( ( V_165 & V_167 ) &&
! ( V_165 & V_166 ) ) ) ) {
if ( ! ( V_165 & V_342 ) &&
( V_165 & V_333 ) )
return true ;
F_120 ( V_2 , 3 , V_165 ) ;
return true ;
}
}
if ( V_30 -> V_214 == 1 ) {
V_30 -> V_220 = F_107 ( V_30 ) + 2 ;
V_30 -> V_214 = 2 ;
if ( ! F_135 ( V_2 ) )
F_120 ( V_2 , 2 , V_165 ) ;
return true ;
} else {
switch ( V_343 ) {
case 2 :
F_203 ( V_2 , V_165 ) ;
break;
case 1 :
F_201 ( V_30 ) ;
break;
default:
F_202 ( V_2 ) ;
break;
}
V_30 -> V_214 = 0 ;
V_30 -> V_121 = 0 ;
F_59 ( F_60 ( V_2 ) , V_344 ) ;
}
return false ;
}
static int F_205 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_165 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_145 = V_30 -> V_96 ;
T_1 V_138 = F_16 ( V_4 ) -> V_82 ;
T_1 V_306 = F_16 ( V_4 ) -> V_138 ;
bool V_298 = false ;
T_1 V_345 ;
T_1 V_313 ;
int V_346 ;
int V_297 = V_30 -> V_120 ;
int V_296 = 0 ;
bool V_347 = false ;
if ( F_40 ( V_306 , V_145 ) )
goto V_348;
if ( F_47 ( V_306 , V_30 -> V_98 ) )
goto V_349;
if ( V_30 -> V_242 )
F_179 ( V_2 ) ;
if ( F_47 ( V_306 , V_145 ) )
V_165 |= V_300 ;
if ( V_350 ) {
if ( V_6 -> V_118 < V_285 )
V_30 -> V_230 += V_306 - V_145 ;
else if ( V_6 -> V_118 == V_207 )
V_30 -> V_230 += F_9 ( V_306 - V_145 ,
V_30 -> V_289 ) ;
}
V_313 = V_30 -> V_119 ;
V_345 = F_107 ( V_30 ) ;
if ( ! ( V_165 & V_351 ) && F_47 ( V_306 , V_145 ) ) {
F_199 ( V_30 , V_138 ) ;
V_30 -> V_96 = V_306 ;
V_165 |= V_339 ;
F_118 ( V_2 , V_352 ) ;
F_59 ( F_60 ( V_2 ) , V_353 ) ;
} else {
if ( V_138 != F_16 ( V_4 ) -> V_84 )
V_165 |= V_354 ;
else
F_59 ( F_60 ( V_2 ) , V_355 ) ;
V_165 |= F_198 ( V_2 , V_4 , V_306 , V_138 ) ;
if ( F_16 ( V_4 ) -> V_126 )
V_165 |= F_102 ( V_2 , V_4 , V_145 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_165 |= V_239 ;
F_118 ( V_2 , V_356 ) ;
}
V_2 -> V_357 = 0 ;
V_6 -> V_358 = 0 ;
V_30 -> V_359 = V_71 ;
V_346 = V_30 -> V_200 ;
if ( ! V_346 )
goto V_360;
V_165 |= F_184 ( V_2 , V_313 , V_145 ) ;
V_296 = V_346 - V_30 -> V_200 ;
if ( V_30 -> V_214 )
V_347 = F_204 ( V_2 , V_165 ) ;
if ( F_40 ( V_30 -> V_164 , V_30 -> V_96 ) )
V_30 -> V_164 = 0 ;
if ( F_194 ( V_2 , V_165 ) ) {
if ( ( V_165 & V_228 ) && ! V_347 &&
F_195 ( V_2 , V_165 ) )
F_178 ( V_2 , V_306 , V_345 ) ;
V_298 = ! ( V_165 & ( V_300 | V_333 ) ) ;
F_173 ( V_2 , V_296 , V_297 ,
V_298 , V_165 ) ;
} else {
if ( ( V_165 & V_228 ) && ! V_347 )
F_178 ( V_2 , V_306 , V_345 ) ;
}
if ( ( V_165 & V_342 ) || ! ( V_165 & V_333 ) ) {
struct V_99 * V_100 = F_206 ( V_2 ) ;
if ( V_100 )
F_207 ( V_100 ) ;
}
return 1 ;
V_360:
if ( V_165 & V_201 )
F_173 ( V_2 , V_296 , V_297 ,
V_298 , V_165 ) ;
if ( F_71 ( V_2 ) )
F_192 ( V_2 ) ;
return 1 ;
V_349:
F_208 ( V_2 , L_12 , V_306 , V_30 -> V_96 , V_30 -> V_98 ) ;
return - 1 ;
V_348:
if ( F_16 ( V_4 ) -> V_126 ) {
V_165 |= F_102 ( V_2 , V_4 , V_145 ) ;
F_173 ( V_2 , V_296 , V_297 ,
V_298 , V_165 ) ;
}
F_208 ( V_2 , L_13 , V_306 , V_30 -> V_96 , V_30 -> V_98 ) ;
return 0 ;
}
void F_209 ( const struct V_3 * V_4 , struct V_361 * V_362 ,
const T_3 * * V_363 , int V_364 ,
struct V_365 * V_366 )
{
const unsigned char * V_191 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_367 = ( V_41 -> V_368 * 4 ) - sizeof( struct V_15 ) ;
V_191 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_362 -> V_256 = 0 ;
while ( V_367 > 0 ) {
int V_369 = * V_191 ++ ;
int V_370 ;
switch ( V_369 ) {
case V_371 :
return;
case V_372 :
V_367 -- ;
continue;
default:
V_370 = * V_191 ++ ;
if ( V_370 < 2 )
return;
if ( V_370 > V_367 )
return;
switch ( V_369 ) {
case V_373 :
if ( V_370 == V_374 && V_41 -> V_43 && ! V_364 ) {
T_7 V_375 = F_210 ( V_191 ) ;
if ( V_375 ) {
if ( V_362 -> V_376 &&
V_362 -> V_376 < V_375 )
V_375 = V_362 -> V_376 ;
V_362 -> V_46 = V_375 ;
}
}
break;
case V_377 :
if ( V_370 == V_378 && V_41 -> V_43 &&
! V_364 && V_379 ) {
T_8 V_338 = * ( T_8 * ) V_191 ;
V_362 -> V_380 = 1 ;
if ( V_338 > 14 ) {
F_211 ( L_14 ,
V_381 ,
V_338 ) ;
V_338 = 14 ;
}
V_362 -> V_338 = V_338 ;
}
break;
case V_382 :
if ( ( V_370 == V_383 ) &&
( ( V_364 && V_362 -> V_384 ) ||
( ! V_364 && V_385 ) ) ) {
V_362 -> V_256 = 1 ;
V_362 -> V_386 = F_73 ( V_191 ) ;
V_362 -> V_83 = F_73 ( V_191 + 4 ) ;
}
break;
case V_387 :
if ( V_370 == V_388 && V_41 -> V_43 &&
! V_364 && V_389 ) {
V_362 -> V_105 = V_390 ;
F_212 ( V_362 ) ;
}
break;
case V_391 :
if ( ( V_370 >= ( V_194 + V_392 ) ) &&
! ( ( V_370 - V_194 ) % V_392 ) &&
V_362 -> V_105 ) {
F_16 ( V_4 ) -> V_126 = ( V_191 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_213
case V_393 :
break;
#endif
case V_394 :
switch ( V_370 ) {
case V_395 :
break;
case V_396 :
break;
case V_397 + 0 :
case V_397 + 2 :
case V_397 + 4 :
case V_397 + 6 :
case V_398 :
V_362 -> V_399 = V_370 ;
* V_363 = V_191 ;
break;
default:
break;
}
break;
case V_400 :
if ( V_370 < V_401 ||
F_210 ( V_191 ) != V_402 ||
V_366 == NULL || ! V_41 -> V_43 || ( V_370 & 1 ) )
break;
V_366 -> V_10 = V_370 - V_401 ;
if ( V_366 -> V_10 >= V_403 &&
V_366 -> V_10 <= V_404 )
memcpy ( V_366 -> V_405 , V_191 + 2 , V_366 -> V_10 ) ;
else if ( V_366 -> V_10 != 0 )
V_366 -> V_10 = - 1 ;
break;
}
V_191 += V_370 - 2 ;
V_367 -= V_370 ;
}
}
}
static bool F_214 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_191 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_191 == F_215 ( ( V_372 << 24 ) | ( V_372 << 16 )
| ( V_382 << 8 ) | V_383 ) ) {
V_30 -> V_45 . V_256 = 1 ;
++ V_191 ;
V_30 -> V_45 . V_386 = F_216 ( * V_191 ) ;
++ V_191 ;
V_30 -> V_45 . V_83 = F_216 ( * V_191 ) ;
return true ;
}
return false ;
}
static bool F_217 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 ,
struct V_29 * V_30 , const T_3 * * V_363 )
{
if ( V_41 -> V_368 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_256 = 0 ;
return false ;
} else if ( V_30 -> V_45 . V_384 &&
V_41 -> V_368 == ( ( sizeof( * V_41 ) + V_406 ) / 4 ) ) {
if ( F_214 ( V_30 , V_41 ) )
return true ;
}
F_209 ( V_4 , & V_30 -> V_45 , V_363 , 1 , NULL ) ;
return true ;
}
const T_3 * F_218 ( const struct V_15 * V_41 )
{
int V_367 = ( V_41 -> V_368 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_191 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_367 < V_407 )
return NULL ;
while ( V_367 > 0 ) {
int V_369 = * V_191 ++ ;
int V_370 ;
switch( V_369 ) {
case V_371 :
return NULL ;
case V_372 :
V_367 -- ;
continue;
default:
V_370 = * V_191 ++ ;
if ( V_370 < 2 || V_370 > V_367 )
return NULL ;
if ( V_369 == V_393 )
return V_370 == V_407 ? V_191 : NULL ;
}
V_191 += V_370 - 2 ;
V_367 -= V_370 ;
}
return NULL ;
}
static inline void F_219 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_408 = V_30 -> V_45 . V_386 ;
V_30 -> V_45 . V_409 = F_220 () ;
}
static inline void F_221 ( struct V_29 * V_30 , T_1 V_82 )
{
if ( V_30 -> V_45 . V_256 && ! F_47 ( V_82 , V_30 -> V_410 ) ) {
if ( F_222 ( & V_30 -> V_45 , 0 ) )
F_219 ( V_30 ) ;
}
}
static int F_223 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
T_1 V_306 = F_16 ( V_4 ) -> V_138 ;
return (
( V_41 -> V_306 && V_82 == F_16 ( V_4 ) -> V_84 && V_82 == V_30 -> V_81 ) &&
V_306 == V_30 -> V_96 &&
! F_197 ( V_30 , V_306 , V_82 , F_146 ( V_41 -> V_52 ) << V_30 -> V_45 . V_338 ) &&
( T_5 ) ( V_30 -> V_45 . V_408 - V_30 -> V_45 . V_386 ) <= ( F_2 ( V_2 ) -> V_90 * 1024 ) / V_411 ) ;
}
static inline bool F_224 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_222 ( & V_30 -> V_45 , V_412 ) &&
! F_223 ( V_2 , V_4 ) ;
}
static inline bool F_225 ( const struct V_29 * V_30 , T_1 V_82 , T_1 V_84 )
{
return ! F_40 ( V_84 , V_30 -> V_410 ) &&
! F_47 ( V_82 , V_30 -> V_81 + F_226 ( V_30 ) ) ;
}
void F_227 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_413 ) {
case V_414 :
V_2 -> V_415 = V_416 ;
break;
case V_417 :
V_2 -> V_415 = V_418 ;
break;
case V_419 :
return;
default:
V_2 -> V_415 = V_420 ;
}
F_228 () ;
if ( ! F_229 ( V_2 , V_421 ) )
V_2 -> V_422 ( V_2 ) ;
F_230 ( V_2 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_423 |= V_424 ;
F_232 ( V_2 , V_425 ) ;
switch ( V_2 -> V_413 ) {
case V_426 :
case V_427 :
F_233 ( V_2 , V_417 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_417 :
case V_428 :
break;
case V_429 :
break;
case V_430 :
F_234 ( V_2 ) ;
F_233 ( V_2 , V_428 ) ;
break;
case V_431 :
F_234 ( V_2 ) ;
F_235 ( V_2 , V_432 , 0 ) ;
break;
default:
F_236 ( L_15 ,
V_381 , V_2 -> V_413 ) ;
break;
}
F_237 ( & V_30 -> V_433 ) ;
if ( F_137 ( V_30 ) )
F_212 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
if ( ! F_229 ( V_2 , V_421 ) ) {
V_2 -> V_434 ( V_2 ) ;
if ( V_2 -> V_423 == V_435 ||
V_2 -> V_413 == V_419 )
F_238 ( V_2 , V_436 , V_437 ) ;
else
F_238 ( V_2 , V_436 , V_438 ) ;
}
}
static inline bool F_239 ( struct V_184 * V_143 , T_1 V_82 ,
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
static void F_240 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_137 ( V_30 ) && V_439 ) {
int V_111 ;
if ( F_40 ( V_82 , V_30 -> V_81 ) )
V_111 = V_440 ;
else
V_111 = V_441 ;
F_59 ( F_60 ( V_2 ) , V_111 ) ;
V_30 -> V_45 . V_442 = 1 ;
V_30 -> V_443 [ 0 ] . V_130 = V_82 ;
V_30 -> V_443 [ 0 ] . V_84 = V_84 ;
}
}
static void F_241 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_442 )
F_240 ( V_2 , V_82 , V_84 ) ;
else
F_239 ( V_30 -> V_443 , V_82 , V_84 ) ;
}
static void F_242 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_59 ( F_60 ( V_2 ) , V_444 ) ;
F_10 ( V_2 ) ;
if ( F_137 ( V_30 ) && V_439 ) {
T_1 V_84 = F_16 ( V_4 ) -> V_84 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) )
V_84 = V_30 -> V_81 ;
F_240 ( V_2 , F_16 ( V_4 ) -> V_82 , V_84 ) ;
}
}
F_234 ( V_2 ) ;
}
static void F_243 ( struct V_29 * V_30 )
{
int V_445 ;
struct V_184 * V_143 = & V_30 -> V_446 [ 0 ] ;
struct V_184 * V_447 = V_143 + 1 ;
for ( V_445 = 1 ; V_445 < V_30 -> V_45 . V_144 ; ) {
if ( F_239 ( V_143 , V_447 -> V_130 , V_447 -> V_84 ) ) {
int V_197 ;
V_30 -> V_45 . V_144 -- ;
for ( V_197 = V_445 ; V_197 < V_30 -> V_45 . V_144 ; V_197 ++ )
V_143 [ V_197 ] = V_143 [ V_197 + 1 ] ;
continue;
}
V_445 ++ , V_447 ++ ;
}
}
static void F_244 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_184 * V_143 = & V_30 -> V_446 [ 0 ] ;
int V_448 = V_30 -> V_45 . V_144 ;
int V_445 ;
if ( ! V_448 )
goto V_449;
for ( V_445 = 0 ; V_445 < V_448 ; V_445 ++ , V_143 ++ ) {
if ( F_239 ( V_143 , V_82 , V_84 ) ) {
for (; V_445 > 0 ; V_445 -- , V_143 -- )
F_105 ( * V_143 , * ( V_143 - 1 ) ) ;
if ( V_448 > 1 )
F_243 ( V_30 ) ;
return;
}
}
if ( V_445 >= V_193 ) {
V_445 -- ;
V_30 -> V_45 . V_144 -- ;
V_143 -- ;
}
for (; V_445 > 0 ; V_445 -- , V_143 -- )
* V_143 = * ( V_143 - 1 ) ;
V_449:
V_143 -> V_130 = V_82 ;
V_143 -> V_84 = V_84 ;
V_30 -> V_45 . V_144 ++ ;
}
static void F_245 ( struct V_29 * V_30 )
{
struct V_184 * V_143 = & V_30 -> V_446 [ 0 ] ;
int V_144 = V_30 -> V_45 . V_144 ;
int V_445 ;
if ( F_246 ( & V_30 -> V_433 ) ) {
V_30 -> V_45 . V_144 = 0 ;
return;
}
for ( V_445 = 0 ; V_445 < V_144 ; ) {
if ( ! F_40 ( V_30 -> V_81 , V_143 -> V_130 ) ) {
int V_197 ;
F_103 ( F_40 ( V_30 -> V_81 , V_143 -> V_84 ) ) ;
for ( V_197 = V_445 + 1 ; V_197 < V_144 ; V_197 ++ )
V_30 -> V_446 [ V_197 - 1 ] = V_30 -> V_446 [ V_197 ] ;
V_144 -- ;
continue;
}
V_445 ++ ;
V_143 ++ ;
}
V_30 -> V_45 . V_144 = V_144 ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_450 = V_30 -> V_81 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_248 ( & V_30 -> V_433 ) ) != NULL ) {
if ( F_47 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_450 ) ) {
T_2 V_442 = V_450 ;
if ( F_40 ( F_16 ( V_4 ) -> V_84 , V_450 ) )
V_450 = F_16 ( V_4 ) -> V_84 ;
F_241 ( V_2 , F_16 ( V_4 ) -> V_82 , V_442 ) ;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_208 ( V_2 , L_16 ) ;
F_249 ( V_4 , & V_30 -> V_433 ) ;
F_250 ( V_4 ) ;
continue;
}
F_208 ( V_2 , L_17 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_249 ( V_4 , & V_30 -> V_433 ) ;
F_251 ( & V_2 -> V_451 , V_4 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( F_6 ( V_4 ) -> V_452 )
F_231 ( V_2 ) ;
}
}
static int F_252 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_453 )
{
if ( F_35 ( & V_2 -> V_72 ) > V_2 -> V_62 ||
! F_253 ( V_2 , V_4 , V_453 ) ) {
if ( F_254 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_253 ( V_2 , V_4 , V_453 ) ) {
if ( ! F_255 ( V_2 ) )
return - 1 ;
if ( ! F_253 ( V_2 , V_4 , V_453 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_256 ( struct V_1 * V_2 ,
struct V_3 * V_454 ,
struct V_3 * V_455 ,
bool * V_456 )
{
int V_283 ;
* V_456 = false ;
if ( F_6 ( V_455 ) -> V_452 )
return false ;
if ( F_16 ( V_455 ) -> V_82 != F_16 ( V_454 ) -> V_84 )
return false ;
if ( ! F_257 ( V_454 , V_455 , V_456 , & V_283 ) )
return false ;
F_258 ( V_283 , & V_2 -> V_72 ) ;
F_259 ( V_2 , V_283 ) ;
F_59 ( F_60 ( V_2 ) , V_457 ) ;
F_16 ( V_454 ) -> V_84 = F_16 ( V_455 ) -> V_84 ;
F_16 ( V_454 ) -> V_138 = F_16 ( V_455 ) -> V_138 ;
return true ;
}
static void F_260 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_458 ;
T_1 V_82 , V_84 ;
F_15 ( V_30 , V_4 ) ;
if ( F_91 ( F_252 ( V_2 , V_4 , V_4 -> V_51 ) ) ) {
F_59 ( F_60 ( V_2 ) , V_459 ) ;
F_250 ( V_4 ) ;
return;
}
V_30 -> V_340 = 0 ;
F_44 ( V_2 ) ;
F_59 ( F_60 ( V_2 ) , V_460 ) ;
F_208 ( V_2 , L_18 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_458 = F_261 ( & V_30 -> V_433 ) ;
if ( ! V_458 ) {
if ( F_137 ( V_30 ) ) {
V_30 -> V_45 . V_144 = 1 ;
V_30 -> V_446 [ 0 ] . V_130 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_446 [ 0 ] . V_84 =
F_16 ( V_4 ) -> V_84 ;
}
F_262 ( & V_30 -> V_433 , V_4 ) ;
goto V_461;
}
V_82 = F_16 ( V_4 ) -> V_82 ;
V_84 = F_16 ( V_4 ) -> V_84 ;
if ( V_82 == F_16 ( V_458 ) -> V_84 ) {
bool V_456 ;
if ( ! F_256 ( V_2 , V_458 , V_4 , & V_456 ) ) {
F_263 ( & V_30 -> V_433 , V_458 , V_4 ) ;
} else {
F_264 ( V_4 , V_456 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_45 . V_144 ||
V_30 -> V_446 [ 0 ] . V_84 != V_82 )
goto V_462;
V_30 -> V_446 [ 0 ] . V_84 = V_84 ;
goto V_461;
}
while ( 1 ) {
if ( ! F_47 ( F_16 ( V_458 ) -> V_82 , V_82 ) )
break;
if ( F_265 ( & V_30 -> V_433 , V_458 ) ) {
V_458 = NULL ;
break;
}
V_458 = F_266 ( & V_30 -> V_433 , V_458 ) ;
}
if ( V_458 && F_40 ( V_82 , F_16 ( V_458 ) -> V_84 ) ) {
if ( ! F_47 ( V_84 , F_16 ( V_458 ) -> V_84 ) ) {
F_59 ( F_60 ( V_2 ) , V_463 ) ;
F_250 ( V_4 ) ;
V_4 = NULL ;
F_240 ( V_2 , V_82 , V_84 ) ;
goto V_462;
}
if ( F_47 ( V_82 , F_16 ( V_458 ) -> V_82 ) ) {
F_240 ( V_2 , V_82 ,
F_16 ( V_458 ) -> V_84 ) ;
} else {
if ( F_265 ( & V_30 -> V_433 ,
V_458 ) )
V_458 = NULL ;
else
V_458 = F_266 (
& V_30 -> V_433 ,
V_458 ) ;
}
}
if ( ! V_458 )
F_262 ( & V_30 -> V_433 , V_4 ) ;
else
F_263 ( & V_30 -> V_433 , V_458 , V_4 ) ;
while ( ! F_267 ( & V_30 -> V_433 , V_4 ) ) {
V_458 = F_268 ( & V_30 -> V_433 , V_4 ) ;
if ( ! F_47 ( V_84 , F_16 ( V_458 ) -> V_82 ) )
break;
if ( F_40 ( V_84 , F_16 ( V_458 ) -> V_84 ) ) {
F_241 ( V_2 , F_16 ( V_458 ) -> V_82 ,
V_84 ) ;
break;
}
F_249 ( V_458 , & V_30 -> V_433 ) ;
F_241 ( V_2 , F_16 ( V_458 ) -> V_82 ,
F_16 ( V_458 ) -> V_84 ) ;
F_59 ( F_60 ( V_2 ) , V_463 ) ;
F_250 ( V_458 ) ;
}
V_462:
if ( F_137 ( V_30 ) )
F_244 ( V_2 , V_82 , V_84 ) ;
V_461:
if ( V_4 )
F_269 ( V_4 , V_2 ) ;
}
static int T_10 F_270 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_464 ,
bool * V_456 )
{
int V_465 ;
struct V_3 * V_466 = F_261 ( & V_2 -> V_451 ) ;
F_271 ( V_4 , V_464 ) ;
V_465 = ( V_466 &&
F_256 ( V_2 , V_466 , V_4 , V_456 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( ! V_465 ) {
F_251 ( & V_2 -> V_451 , V_4 ) ;
F_269 ( V_4 , V_2 ) ;
}
return V_465 ;
}
int F_272 ( struct V_1 * V_2 , struct V_467 * V_257 , T_11 V_453 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_456 ;
if ( V_453 == 0 )
return 0 ;
V_4 = F_273 ( V_453 + sizeof( * V_41 ) , V_2 -> V_468 ) ;
if ( ! V_4 )
goto V_153;
if ( F_252 ( V_2 , V_4 , V_453 + sizeof( * V_41 ) ) )
goto V_469;
V_41 = (struct V_15 * ) F_274 ( V_4 , sizeof( * V_41 ) ) ;
F_275 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_276 ( F_274 ( V_4 , V_453 ) , V_257 -> V_470 , V_453 ) )
goto V_469;
F_16 ( V_4 ) -> V_82 = F_7 ( V_2 ) -> V_81 ;
F_16 ( V_4 ) -> V_84 = F_16 ( V_4 ) -> V_82 + V_453 ;
F_16 ( V_4 ) -> V_138 = F_7 ( V_2 ) -> V_96 - 1 ;
if ( F_270 ( V_2 , V_4 , sizeof( * V_41 ) , & V_456 ) ) {
F_277 ( V_456 ) ;
F_250 ( V_4 ) ;
}
return V_453 ;
V_469:
F_278 ( V_4 ) ;
V_153:
return - V_471 ;
}
static void F_279 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_465 = - 1 ;
bool V_456 = false ;
if ( F_16 ( V_4 ) -> V_82 == F_16 ( V_4 ) -> V_84 )
goto V_472;
F_280 ( V_4 ) ;
F_271 ( V_4 , V_41 -> V_368 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_442 = 0 ;
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 ) {
if ( F_226 ( V_30 ) == 0 )
goto V_473;
if ( V_30 -> V_474 . V_475 == V_476 &&
V_30 -> V_85 == V_30 -> V_81 && V_30 -> V_474 . V_10 &&
F_281 ( V_2 ) && ! V_30 -> V_477 ) {
int V_478 = F_37 (unsigned int, skb->len,
tp->ucopy.len) ;
F_282 ( V_479 ) ;
F_283 () ;
if ( ! F_284 ( V_4 , 0 , V_30 -> V_474 . V_480 , V_478 ) ) {
V_30 -> V_474 . V_10 -= V_478 ;
V_30 -> V_85 += V_478 ;
V_465 = ( V_478 == V_4 -> V_10 ) ;
F_42 ( V_2 ) ;
}
F_285 () ;
}
if ( V_465 <= 0 ) {
V_481:
if ( V_465 < 0 &&
F_252 ( V_2 , V_4 , V_4 -> V_51 ) )
goto V_472;
V_465 = F_270 ( V_2 , V_4 , 0 , & V_456 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( V_4 -> V_10 )
F_43 ( V_2 , V_4 ) ;
if ( V_41 -> V_452 )
F_231 ( V_2 ) ;
if ( ! F_246 ( & V_30 -> V_433 ) ) {
F_247 ( V_2 ) ;
if ( F_246 ( & V_30 -> V_433 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_144 )
F_245 ( V_30 ) ;
F_200 ( V_2 ) ;
if ( V_465 > 0 )
F_264 ( V_4 , V_456 ) ;
if ( ! F_229 ( V_2 , V_421 ) )
V_2 -> V_482 ( V_2 , 0 ) ;
return;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_59 ( F_60 ( V_2 ) , V_444 ) ;
F_240 ( V_2 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_473:
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
V_472:
F_250 ( V_4 ) ;
return;
}
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 + F_226 ( V_30 ) ) )
goto V_473;
F_10 ( V_2 ) ;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_208 ( V_2 , L_19 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_240 ( V_2 , F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ;
if ( ! F_226 ( V_30 ) )
goto V_473;
goto V_481;
}
F_260 ( V_2 , V_4 ) ;
}
static struct V_3 * F_286 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_483 * V_484 )
{
struct V_3 * V_485 = NULL ;
if ( ! F_267 ( V_484 , V_4 ) )
V_485 = F_268 ( V_484 , V_4 ) ;
F_249 ( V_4 , V_484 ) ;
F_250 ( V_4 ) ;
F_59 ( F_60 ( V_2 ) , V_486 ) ;
return V_485 ;
}
static void
F_287 ( struct V_1 * V_2 , struct V_483 * V_484 ,
struct V_3 * V_487 , struct V_3 * V_466 ,
T_1 V_488 , T_1 V_461 )
{
struct V_3 * V_4 , * V_489 ;
bool V_490 ;
V_4 = V_487 ;
V_491:
V_490 = true ;
F_288 (list, skb, n) {
if ( V_4 == V_466 )
break;
if ( ! F_40 ( V_488 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_286 ( V_2 , V_4 , V_484 ) ;
if ( ! V_4 )
break;
goto V_491;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_452 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_40 ( F_16 ( V_4 ) -> V_82 , V_488 ) ) ) {
V_490 = false ;
break;
}
if ( ! F_267 ( V_484 , V_4 ) ) {
struct V_3 * V_485 = F_268 ( V_484 , V_4 ) ;
if ( V_485 != V_466 &&
F_16 ( V_4 ) -> V_84 != F_16 ( V_485 ) -> V_82 ) {
V_490 = false ;
break;
}
}
V_488 = F_16 ( V_4 ) -> V_84 ;
}
if ( V_490 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_452 )
return;
while ( F_40 ( V_488 , V_461 ) ) {
struct V_3 * V_492 ;
unsigned int V_493 = F_289 ( V_4 ) ;
int V_494 = F_290 ( V_493 , 0 ) ;
if ( V_494 < 0 )
return;
if ( V_461 - V_488 < V_494 )
V_494 = V_461 - V_488 ;
V_492 = F_273 ( V_494 + V_493 , V_495 ) ;
if ( ! V_492 )
return;
F_291 ( V_492 , F_292 ( V_4 ) - V_4 -> V_487 ) ;
F_293 ( V_492 , ( F_294 ( V_4 ) -
V_4 -> V_487 ) ) ;
F_295 ( V_492 , ( F_4 ( V_4 ) -
V_4 -> V_487 ) ) ;
F_296 ( V_492 , V_493 ) ;
memcpy ( V_492 -> V_487 , V_4 -> V_487 , V_493 ) ;
memcpy ( V_492 -> V_496 , V_4 -> V_496 , sizeof( V_4 -> V_496 ) ) ;
F_16 ( V_492 ) -> V_82 = F_16 ( V_492 ) -> V_84 = V_488 ;
F_297 ( V_484 , V_4 , V_492 ) ;
F_269 ( V_492 , V_2 ) ;
while ( V_494 > 0 ) {
int V_497 = V_488 - F_16 ( V_4 ) -> V_82 ;
int V_453 = F_16 ( V_4 ) -> V_84 - V_488 ;
F_80 ( V_497 < 0 ) ;
if ( V_453 > 0 ) {
V_453 = F_9 ( V_494 , V_453 ) ;
if ( F_298 ( V_4 , V_497 , F_274 ( V_492 , V_453 ) , V_453 ) )
F_299 () ;
F_16 ( V_492 ) -> V_84 += V_453 ;
V_494 -= V_453 ;
V_488 += V_453 ;
}
if ( ! F_40 ( V_488 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_286 ( V_2 , V_4 , V_484 ) ;
if ( ! V_4 ||
V_4 == V_466 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_452 )
return;
}
}
}
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_248 ( & V_30 -> V_433 ) ;
struct V_3 * V_487 ;
T_1 V_488 , V_461 ;
if ( V_4 == NULL )
return;
V_488 = F_16 ( V_4 ) -> V_82 ;
V_461 = F_16 ( V_4 ) -> V_84 ;
V_487 = V_4 ;
for (; ; ) {
struct V_3 * V_485 = NULL ;
if ( ! F_267 ( & V_30 -> V_433 , V_4 ) )
V_485 = F_268 ( & V_30 -> V_433 , V_4 ) ;
V_4 = V_485 ;
if ( ! V_4 ||
F_47 ( F_16 ( V_4 ) -> V_82 , V_461 ) ||
F_40 ( F_16 ( V_4 ) -> V_84 , V_488 ) ) {
F_287 ( V_2 , & V_30 -> V_433 ,
V_487 , V_4 , V_488 , V_461 ) ;
V_487 = V_4 ;
if ( ! V_4 )
break;
V_488 = F_16 ( V_4 ) -> V_82 ;
V_461 = F_16 ( V_4 ) -> V_84 ;
} else {
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_488 ) )
V_488 = F_16 ( V_4 ) -> V_82 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_461 ) )
V_461 = F_16 ( V_4 ) -> V_84 ;
}
}
}
static bool F_255 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_498 = false ;
if ( ! F_246 ( & V_30 -> V_433 ) ) {
F_59 ( F_60 ( V_2 ) , V_499 ) ;
F_237 ( & V_30 -> V_433 ) ;
if ( V_30 -> V_45 . V_105 )
F_212 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
V_498 = true ;
}
return V_498 ;
}
static int F_254 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_208 ( V_2 , L_20 , V_30 -> V_85 ) ;
F_59 ( F_60 ( V_2 ) , V_500 ) ;
if ( F_35 ( & V_2 -> V_72 ) >= V_2 -> V_62 )
F_32 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_300 ( V_2 ) ;
if ( ! F_246 ( & V_2 -> V_451 ) )
F_287 ( V_2 , & V_2 -> V_451 ,
F_248 ( & V_2 -> V_451 ) ,
NULL ,
V_30 -> V_85 , V_30 -> V_81 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_255 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_59 ( F_60 ( V_2 ) , V_501 ) ;
V_30 -> V_340 = 0 ;
return - 1 ;
}
void F_301 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_118 == V_273 &&
V_2 -> V_502 && ! F_302 ( V_503 , & V_2 -> V_502 -> V_330 ) ) {
T_1 V_504 = F_52 ( V_30 , F_206 ( V_2 ) ) ;
T_1 V_505 = F_31 ( V_30 -> V_506 , V_504 ) ;
if ( V_505 < V_30 -> V_220 ) {
V_30 -> V_221 = F_117 ( V_2 ) ;
V_30 -> V_220 = ( V_30 -> V_220 + V_505 ) >> 1 ;
}
V_30 -> V_506 = 0 ;
}
V_30 -> V_70 = V_71 ;
}
static bool F_303 ( const struct V_1 * V_2 )
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
static void F_304 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_303 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_289 ) +
V_47 ) ;
int V_507 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_507 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_70 = V_71 ;
}
V_2 -> V_508 ( V_2 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
if ( F_229 ( V_2 , V_509 ) ) {
F_306 ( V_2 , V_509 ) ;
if ( V_2 -> V_502 &&
F_302 ( V_503 , & V_2 -> V_502 -> V_330 ) )
F_304 ( V_2 ) ;
}
}
static inline void F_307 ( struct V_1 * V_2 )
{
F_308 ( V_2 ) ;
F_305 ( V_2 ) ;
}
static void F_309 ( struct V_1 * V_2 , int V_510 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_81 - V_30 -> V_410 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_310 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_510 && F_248 ( & V_30 -> V_433 ) ) ) {
F_234 ( V_2 ) ;
} else {
F_311 ( V_2 ) ;
}
}
static inline void F_312 ( struct V_1 * V_2 )
{
if ( ! F_313 ( V_2 ) ) {
return;
}
F_309 ( V_2 , 1 ) ;
}
static void F_314 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_191 = F_146 ( V_41 -> V_511 ) ;
if ( V_191 && ! V_512 )
V_191 -- ;
V_191 += F_216 ( V_41 -> V_82 ) ;
if ( F_47 ( V_30 -> V_85 , V_191 ) )
return;
if ( F_40 ( V_191 , V_30 -> V_81 ) )
return;
if ( V_30 -> V_477 && ! F_47 ( V_191 , V_30 -> V_513 ) )
return;
F_315 ( V_2 ) ;
if ( V_30 -> V_513 == V_30 -> V_85 && V_30 -> V_477 &&
! F_229 ( V_2 , V_514 ) && V_30 -> V_85 != V_30 -> V_81 ) {
struct V_3 * V_4 = F_248 ( & V_2 -> V_451 ) ;
V_30 -> V_85 ++ ;
if ( V_4 && ! F_40 ( V_30 -> V_85 , F_16 ( V_4 ) -> V_84 ) ) {
F_249 ( V_4 , & V_2 -> V_451 ) ;
F_250 ( V_4 ) ;
}
}
V_30 -> V_477 = V_515 ;
V_30 -> V_513 = V_191 ;
V_30 -> V_340 = 0 ;
}
static void F_316 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_516 )
F_314 ( V_2 , V_41 ) ;
if ( V_30 -> V_477 == V_515 ) {
T_1 V_191 = V_30 -> V_513 - F_216 ( V_41 -> V_82 ) + ( V_41 -> V_368 * 4 ) -
V_41 -> V_43 ;
if ( V_191 < V_4 -> V_10 ) {
T_3 V_187 ;
if ( F_298 ( V_4 , V_191 , & V_187 , 1 ) )
F_299 () ;
V_30 -> V_477 = V_517 | V_187 ;
if ( ! F_229 ( V_2 , V_421 ) )
V_2 -> V_482 ( V_2 , 0 ) ;
}
}
}
static int F_317 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_518 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_478 = V_4 -> V_10 - V_518 ;
int V_153 ;
F_283 () ;
if ( F_318 ( V_4 ) )
V_153 = F_284 ( V_4 , V_518 , V_30 -> V_474 . V_480 , V_478 ) ;
else
V_153 = F_319 ( V_4 , V_518 ,
V_30 -> V_474 . V_480 ) ;
if ( ! V_153 ) {
V_30 -> V_474 . V_10 -= V_478 ;
V_30 -> V_85 += V_478 ;
F_42 ( V_2 ) ;
}
F_285 () ;
return V_153 ;
}
static T_12 F_320 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_12 V_519 ;
if ( F_281 ( V_2 ) ) {
F_283 () ;
V_519 = F_321 ( V_4 ) ;
F_285 () ;
} else {
V_519 = F_321 ( V_4 ) ;
}
return V_519 ;
}
static inline bool F_322 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_318 ( V_4 ) &&
F_320 ( V_2 , V_4 ) ;
}
static bool F_323 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_518 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_478 = V_4 -> V_10 - V_518 ;
int V_520 ;
bool V_521 = false ;
if ( V_30 -> V_474 . V_522 )
return false ;
if ( ! V_30 -> V_474 . V_523 && V_30 -> V_474 . V_524 )
V_30 -> V_474 . V_523 = F_324 () ;
if ( V_30 -> V_474 . V_523 && F_318 ( V_4 ) ) {
V_520 = F_325 ( V_30 -> V_474 . V_523 ,
V_4 , V_518 ,
V_30 -> V_474 . V_480 , V_478 ,
V_30 -> V_474 . V_524 ) ;
if ( V_520 < 0 )
goto V_182;
V_30 -> V_474 . V_520 = V_520 ;
V_521 = true ;
V_30 -> V_474 . V_10 -= V_478 ;
V_30 -> V_85 += V_478 ;
F_42 ( V_2 ) ;
if ( ( V_30 -> V_474 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_525 ) ||
( F_35 ( & V_2 -> V_72 ) > ( V_2 -> V_62 >> 1 ) ) ) {
V_30 -> V_474 . V_522 = 1 ;
V_2 -> V_482 ( V_2 , 0 ) ;
}
} else if ( V_478 > 0 ) {
V_30 -> V_474 . V_522 = 1 ;
V_2 -> V_482 ( V_2 , 0 ) ;
}
V_182:
return V_521 ;
}
static void F_326 ( struct V_1 * V_2 )
{
static T_1 V_526 ;
static unsigned int V_527 ;
T_1 V_88 = V_241 / V_411 ;
if ( V_88 != V_526 ) {
V_526 = V_88 ;
V_527 = 0 ;
}
if ( ++ V_527 <= V_528 ) {
F_59 ( F_60 ( V_2 ) , V_529 ) ;
F_234 ( V_2 ) ;
}
}
static bool F_327 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_530 )
{
const T_3 * V_531 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_217 ( V_4 , V_41 , V_30 , & V_531 ) &&
V_30 -> V_45 . V_256 &&
F_224 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_532 ) {
F_59 ( F_60 ( V_2 ) , V_533 ) ;
F_242 ( V_2 , V_4 ) ;
goto V_534;
}
}
if ( ! F_225 ( V_30 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) {
if ( ! V_41 -> V_532 ) {
if ( V_41 -> V_43 )
goto V_535;
F_242 ( V_2 , V_4 ) ;
}
goto V_534;
}
if ( V_41 -> V_532 ) {
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 )
F_227 ( V_2 ) ;
else
F_326 ( V_2 ) ;
goto V_534;
}
if ( V_41 -> V_43 ) {
V_535:
if ( V_530 )
F_328 ( F_60 ( V_2 ) , V_536 ) ;
F_59 ( F_60 ( V_2 ) , V_537 ) ;
F_326 ( V_2 ) ;
goto V_534;
}
return true ;
V_534:
F_250 ( V_4 ) ;
return false ;
}
int F_329 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_91 ( V_2 -> V_538 == NULL ) )
F_2 ( V_2 ) -> V_539 -> V_540 ( V_2 , V_4 ) ;
V_30 -> V_45 . V_256 = 0 ;
if ( ( F_5 ( V_41 ) & V_541 ) == V_30 -> V_340 &&
F_16 ( V_4 ) -> V_82 == V_30 -> V_81 &&
! F_47 ( F_16 ( V_4 ) -> V_138 , V_30 -> V_98 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_406 ) {
if ( ! F_214 ( V_30 , V_41 ) )
goto V_542;
if ( ( T_5 ) ( V_30 -> V_45 . V_386 - V_30 -> V_45 . V_408 ) < 0 )
goto V_542;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_406 ) &&
V_30 -> V_81 == V_30 -> V_410 )
F_219 ( V_30 ) ;
F_205 ( V_2 , V_4 , 0 ) ;
F_250 ( V_4 ) ;
F_307 ( V_2 ) ;
return 0 ;
} else {
F_328 ( F_60 ( V_2 ) , V_536 ) ;
goto V_534;
}
} else {
int V_465 = 0 ;
int V_521 = 0 ;
bool V_456 = false ;
if ( V_30 -> V_85 == V_30 -> V_81 &&
V_10 - V_18 <= V_30 -> V_474 . V_10 ) {
#ifdef F_330
if ( V_30 -> V_474 . V_475 == V_476 &&
F_281 ( V_2 ) &&
F_323 ( V_2 , V_4 , V_18 ) ) {
V_521 = 1 ;
V_465 = 1 ;
}
#endif
if ( V_30 -> V_474 . V_475 == V_476 &&
F_281 ( V_2 ) && ! V_521 ) {
F_282 ( V_479 ) ;
if ( ! F_317 ( V_2 , V_4 , V_18 ) )
V_465 = 1 ;
}
if ( V_465 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_406 ) &&
V_30 -> V_81 == V_30 -> V_410 )
F_219 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
F_271 ( V_4 , V_18 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
F_59 ( F_60 ( V_2 ) , V_543 ) ;
}
if ( V_521 )
F_331 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_465 ) {
if ( F_322 ( V_2 , V_4 ) )
goto V_544;
if ( V_18 ==
( sizeof( struct V_15 ) + V_406 ) &&
V_30 -> V_81 == V_30 -> V_410 )
F_219 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
if ( ( int ) V_4 -> V_51 > V_2 -> V_545 )
goto V_546;
F_59 ( F_60 ( V_2 ) , V_547 ) ;
V_465 = F_270 ( V_2 , V_4 , V_18 ,
& V_456 ) ;
}
F_43 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_138 != V_30 -> V_96 ) {
F_205 ( V_2 , V_4 , V_354 ) ;
F_307 ( V_2 ) ;
if ( ! F_313 ( V_2 ) )
goto V_548;
}
if ( ! V_521 || V_30 -> V_81 != V_30 -> V_410 )
F_309 ( V_2 , 0 ) ;
V_548:
#ifdef F_330
if ( V_521 )
F_251 ( & V_2 -> V_549 , V_4 ) ;
else
#endif
if ( V_465 )
F_264 ( V_4 , V_456 ) ;
V_2 -> V_482 ( V_2 , 0 ) ;
return 0 ;
}
}
V_542:
if ( V_10 < ( V_41 -> V_368 << 2 ) || F_322 ( V_2 , V_4 ) )
goto V_544;
if ( ! F_327 ( V_2 , V_4 , V_41 , 1 ) )
return 0 ;
V_546:
if ( V_41 -> V_306 && F_205 ( V_2 , V_4 , V_351 ) < 0 )
goto V_534;
F_221 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
F_41 ( V_2 , V_4 ) ;
F_316 ( V_2 , V_4 , V_41 ) ;
F_279 ( V_2 , V_4 ) ;
F_307 ( V_2 ) ;
F_312 ( V_2 ) ;
return 0 ;
V_544:
F_328 ( F_60 ( V_2 ) , V_536 ) ;
V_534:
F_250 ( V_4 ) ;
return 0 ;
}
void F_332 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_233 ( V_2 , V_427 ) ;
if ( V_4 != NULL ) {
V_6 -> V_539 -> V_540 ( V_2 , V_4 ) ;
F_333 ( V_2 , V_4 ) ;
}
V_6 -> V_539 -> V_550 ( V_2 ) ;
F_334 ( V_2 ) ;
F_335 ( V_2 ) ;
V_30 -> V_551 = V_71 ;
F_29 ( V_2 ) ;
if ( F_229 ( V_2 , V_552 ) )
F_336 ( V_2 , F_337 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_338 )
F_338 ( V_30 , V_30 -> V_337 ) ;
else
V_30 -> V_340 = 0 ;
if ( ! F_229 ( V_2 , V_421 ) ) {
V_2 -> V_434 ( V_2 ) ;
F_238 ( V_2 , V_553 , V_554 ) ;
}
}
static bool F_339 ( struct V_1 * V_2 , struct V_3 * V_555 ,
struct V_365 * V_556 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_557 ? F_92 ( V_2 ) : NULL ;
T_7 V_58 = V_30 -> V_45 . V_46 ;
bool V_558 ;
if ( V_58 == V_30 -> V_45 . V_376 ) {
struct V_361 V_559 ;
const T_3 * V_531 ;
F_340 ( & V_559 ) ;
V_559 . V_376 = V_559 . V_46 = 0 ;
F_209 ( V_555 , & V_559 , & V_531 , 0 , NULL ) ;
V_58 = V_559 . V_46 ;
}
if ( ! V_30 -> V_560 )
V_556 -> V_10 = - 1 ;
V_558 = ( V_556 -> V_10 <= 0 && V_13 &&
F_2 ( V_2 ) -> V_217 ) ;
F_341 ( V_2 , V_58 , V_556 , V_558 ) ;
if ( V_13 ) {
F_97 (data, sk) {
if ( V_13 == F_71 ( V_2 ) ||
F_342 ( V_2 , V_13 ) )
break;
}
F_179 ( V_2 ) ;
return true ;
}
V_30 -> V_561 = V_30 -> V_557 ;
return false ;
}
static int F_343 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
const T_3 * V_531 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_562 * V_563 = V_30 -> V_564 ;
struct V_365 V_366 = { . V_10 = - 1 } ;
int V_565 = V_30 -> V_45 . V_46 ;
F_209 ( V_4 , & V_30 -> V_45 , & V_531 , 0 , & V_366 ) ;
if ( V_41 -> V_306 ) {
if ( ! F_47 ( F_16 ( V_4 ) -> V_138 , V_30 -> V_96 ) ||
F_47 ( F_16 ( V_4 ) -> V_138 , V_30 -> V_98 ) )
goto V_566;
if ( V_30 -> V_45 . V_256 && V_30 -> V_45 . V_83 &&
! F_187 ( V_30 -> V_45 . V_83 , V_30 -> V_255 ,
V_71 ) ) {
F_59 ( F_60 ( V_2 ) , V_567 ) ;
goto V_566;
}
if ( V_41 -> V_532 ) {
F_227 ( V_2 ) ;
goto V_534;
}
if ( ! V_41 -> V_43 )
goto V_568;
F_17 ( V_30 , V_41 ) ;
F_344 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
F_205 ( V_2 , V_4 , V_351 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_410 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_337 = F_146 ( V_41 -> V_52 ) ;
if ( ! V_30 -> V_45 . V_380 ) {
V_30 -> V_45 . V_338 = V_30 -> V_45 . V_569 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_256 ) {
V_30 -> V_45 . V_384 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_406 ;
V_30 -> V_57 -= V_406 ;
F_219 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_137 ( V_30 ) && V_570 )
F_345 ( V_30 ) ;
F_346 ( V_2 ) ;
F_167 ( V_2 , V_6 -> V_291 ) ;
F_36 ( V_2 ) ;
V_30 -> V_85 = V_30 -> V_81 ;
if ( V_563 != NULL &&
V_563 -> V_571 > 0 &&
V_30 -> V_45 . V_399 > 0 ) {
int V_572 = V_30 -> V_45 . V_399
- V_395 ;
int V_571 = V_572
+ V_563 -> V_573 ;
if ( sizeof( V_563 -> V_574 ) >= V_571 ) {
memcpy ( & V_563 -> V_574 [ V_563 -> V_573 ] ,
V_531 , V_572 ) ;
V_563 -> V_571 = V_571 ;
}
}
F_347 () ;
F_332 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_560 || V_30 -> V_557 ) &&
F_339 ( V_2 , V_4 , & V_366 ) )
return - 1 ;
if ( V_2 -> V_575 ||
V_6 -> V_576 . V_577 ||
V_6 -> V_8 . V_26 ) {
F_44 ( V_2 ) ;
V_6 -> V_8 . V_89 = V_71 ;
F_10 ( V_2 ) ;
F_127 ( V_2 , V_578 ,
V_579 , V_236 ) ;
V_534:
F_250 ( V_4 ) ;
return 0 ;
} else {
F_234 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_532 ) {
goto V_568;
}
if ( V_30 -> V_45 . V_409 && V_30 -> V_45 . V_256 &&
F_348 ( & V_30 -> V_45 , 0 ) )
goto V_568;
if ( V_41 -> V_43 ) {
F_233 ( V_2 , V_426 ) ;
if ( V_30 -> V_45 . V_256 ) {
V_30 -> V_45 . V_384 = 1 ;
F_219 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_406 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_410 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_337 = F_146 ( V_41 -> V_52 ) ;
V_30 -> V_336 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_131 = V_30 -> V_337 ;
F_18 ( V_30 , V_41 ) ;
F_346 ( V_2 ) ;
F_167 ( V_2 , V_6 -> V_291 ) ;
F_36 ( V_2 ) ;
F_349 ( V_2 ) ;
#if 0
return -1;
#else
goto V_534;
#endif
}
V_568:
F_340 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_565 ;
goto V_534;
V_566:
F_340 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_565 ;
return 1 ;
}
int F_350 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_580 * V_581 ;
int V_582 = 0 ;
V_30 -> V_45 . V_256 = 0 ;
switch ( V_2 -> V_413 ) {
case V_419 :
goto V_534;
case V_583 :
if ( V_41 -> V_306 )
return 1 ;
if ( V_41 -> V_532 )
goto V_534;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_452 )
goto V_534;
if ( V_6 -> V_539 -> V_584 ( V_2 , V_4 ) < 0 )
return 1 ;
F_278 ( V_4 ) ;
return 0 ;
}
goto V_534;
case V_414 :
V_582 = F_343 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_582 >= 0 )
return V_582 ;
F_316 ( V_2 , V_4 , V_41 ) ;
F_250 ( V_4 ) ;
F_307 ( V_2 ) ;
return 0 ;
}
V_581 = V_30 -> V_309 ;
if ( V_581 != NULL ) {
F_277 ( V_2 -> V_413 != V_426 &&
V_2 -> V_413 != V_430 ) ;
if ( F_351 ( V_2 , V_4 , V_581 , NULL , true ) == NULL )
goto V_534;
}
if ( ! F_327 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
if ( V_41 -> V_306 ) {
int V_585 = F_205 ( V_2 , V_4 , V_351 ) > 0 ;
switch ( V_2 -> V_413 ) {
case V_426 :
if ( V_585 ) {
if ( V_581 ) {
F_352 ( V_2 , V_581 ) ;
V_30 -> V_586 = V_581 -> V_587 ;
F_353 ( V_2 , V_581 , false ) ;
} else {
V_6 -> V_539 -> V_550 ( V_2 ) ;
F_335 ( V_2 ) ;
F_346 ( V_2 ) ;
F_29 ( V_2 ) ;
V_30 -> V_85 = V_30 -> V_81 ;
}
F_347 () ;
F_233 ( V_2 , V_427 ) ;
V_2 -> V_434 ( V_2 ) ;
if ( V_2 -> V_502 )
F_238 ( V_2 ,
V_553 , V_554 ) ;
V_30 -> V_96 = F_16 ( V_4 ) -> V_138 ;
V_30 -> V_337 = F_146 ( V_41 -> V_52 ) <<
V_30 -> V_45 . V_338 ;
F_344 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_30 -> V_45 . V_384 )
V_30 -> V_57 -= V_406 ;
if ( V_581 ) {
F_179 ( V_2 ) ;
} else
F_334 ( V_2 ) ;
V_30 -> V_551 = V_71 ;
F_36 ( V_2 ) ;
F_354 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_430 :
if ( V_581 != NULL ) {
if ( ! V_585 )
return 1 ;
F_353 ( V_2 , V_581 , false ) ;
F_179 ( V_2 ) ;
}
if ( V_30 -> V_96 == V_30 -> V_588 ) {
struct V_99 * V_100 ;
F_233 ( V_2 , V_431 ) ;
V_2 -> V_423 |= V_589 ;
V_100 = F_206 ( V_2 ) ;
if ( V_100 )
F_207 ( V_100 ) ;
if ( ! F_229 ( V_2 , V_421 ) )
V_2 -> V_434 ( V_2 ) ;
else {
int V_590 ;
if ( V_30 -> V_591 < 0 ||
( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_452 , V_30 -> V_81 ) ) ) {
F_230 ( V_2 ) ;
F_59 ( F_60 ( V_2 ) , V_592 ) ;
return 1 ;
}
V_590 = F_355 ( V_2 ) ;
if ( V_590 > V_593 ) {
F_336 ( V_2 , V_590 - V_593 ) ;
} else if ( V_41 -> V_452 || F_281 ( V_2 ) ) {
F_336 ( V_2 , V_590 ) ;
} else {
F_235 ( V_2 , V_431 , V_590 ) ;
goto V_534;
}
}
}
break;
case V_428 :
if ( V_30 -> V_96 == V_30 -> V_588 ) {
F_235 ( V_2 , V_432 , 0 ) ;
goto V_534;
}
break;
case V_429 :
if ( V_30 -> V_96 == V_30 -> V_588 ) {
F_356 ( V_2 ) ;
F_230 ( V_2 ) ;
goto V_534;
}
break;
}
} else
goto V_534;
F_221 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
F_316 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_413 ) {
case V_417 :
case V_428 :
case V_429 :
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
case V_430 :
case V_431 :
if ( V_2 -> V_423 & V_424 ) {
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_452 , V_30 -> V_81 ) ) {
F_59 ( F_60 ( V_2 ) , V_592 ) ;
F_227 ( V_2 ) ;
return 1 ;
}
}
case V_427 :
F_279 ( V_2 , V_4 ) ;
V_582 = 1 ;
break;
}
if ( V_2 -> V_413 != V_419 ) {
F_307 ( V_2 ) ;
F_312 ( V_2 ) ;
}
if ( ! V_582 ) {
V_534:
F_250 ( V_4 ) ;
}
return 0 ;
}
