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
int V_59 ;
V_59 = 2 * F_21 ( V_58 + V_47 ) *
F_29 ( V_58 ) ;
if ( V_2 -> V_60 < V_59 )
V_2 -> V_60 = F_9 ( V_59 , V_53 [ 2 ] ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_61 ;
if ( ! ( V_2 -> V_62 & V_63 ) )
F_28 ( V_2 ) ;
if ( ! ( V_2 -> V_62 & V_64 ) )
F_20 ( V_2 ) ;
V_30 -> V_65 . V_66 = V_30 -> V_23 ;
V_61 = F_31 ( V_2 ) ;
if ( V_30 -> V_55 >= V_61 ) {
V_30 -> V_55 = V_61 ;
if ( V_67 && V_61 > 4 * V_30 -> V_57 )
V_30 -> V_55 = F_32 ( V_61 -
( V_61 >> V_67 ) ,
4 * V_30 -> V_57 ) ;
}
if ( V_67 &&
V_30 -> V_55 > 2 * V_30 -> V_57 &&
V_30 -> V_55 + V_30 -> V_57 > V_61 )
V_30 -> V_55 = F_32 ( 2 * V_30 -> V_57 , V_61 - V_30 -> V_57 ) ;
V_30 -> V_54 = F_9 ( V_30 -> V_54 , V_30 -> V_55 ) ;
V_30 -> V_68 = V_69 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_60 < V_53 [ 2 ] &&
! ( V_2 -> V_62 & V_63 ) &&
! F_26 ( V_2 ) &&
F_34 ( V_2 ) < F_35 ( V_2 , 0 ) ) {
V_2 -> V_60 = F_9 ( F_36 ( & V_2 -> V_70 ) ,
V_53 [ 2 ] ) ;
}
if ( F_36 ( & V_2 -> V_70 ) > V_2 -> V_60 )
V_30 -> V_54 = F_9 ( V_30 -> V_55 , 2U * V_30 -> V_57 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned int V_71 = F_38 (unsigned int, tp->advmss, tp->mss_cache) ;
V_71 = F_9 ( V_71 , V_30 -> V_23 / 2 ) ;
V_71 = F_9 ( V_71 , V_14 ) ;
V_71 = F_32 ( V_71 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_71 ;
}
static void F_39 ( struct V_29 * V_30 , T_1 V_72 , int V_73 )
{
T_1 V_74 = V_30 -> V_75 . V_76 ;
long V_77 = V_72 ;
if ( V_77 == 0 )
V_77 = 1 ;
if ( V_74 != 0 ) {
if ( ! V_73 ) {
V_77 -= ( V_74 >> 3 ) ;
V_74 += V_77 ;
} else {
V_77 <<= 3 ;
if ( V_77 < V_74 )
V_74 = V_77 ;
}
} else {
V_74 = V_77 << 3 ;
}
if ( V_30 -> V_75 . V_76 != V_74 )
V_30 -> V_75 . V_76 = V_74 ;
}
static inline void F_40 ( struct V_29 * V_30 )
{
if ( V_30 -> V_75 . time == 0 )
goto V_78;
if ( F_41 ( V_30 -> V_79 , V_30 -> V_75 . V_80 ) )
return;
F_39 ( V_30 , V_69 - V_30 -> V_75 . time , 1 ) ;
V_78:
V_30 -> V_75 . V_80 = V_30 -> V_79 + V_30 -> V_23 ;
V_30 -> V_75 . time = V_69 ;
}
static inline void F_42 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_81 &&
( F_16 ( V_4 ) -> V_82 -
F_16 ( V_4 ) -> V_80 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_39 ( V_30 , V_69 - V_30 -> V_45 . V_81 , 0 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int time ;
int V_66 ;
if ( V_30 -> V_65 . time == 0 )
goto V_78;
time = V_69 - V_30 -> V_65 . time ;
if ( time < ( V_30 -> V_75 . V_76 >> 3 ) || V_30 -> V_75 . V_76 == 0 )
return;
V_66 = 2 * ( V_30 -> V_83 - V_30 -> V_65 . V_80 ) ;
V_66 = F_32 ( V_30 -> V_65 . V_66 , V_66 ) ;
if ( V_30 -> V_65 . V_66 != V_66 ) {
int V_59 ;
V_30 -> V_65 . V_66 = V_66 ;
if ( V_84 &&
! ( V_2 -> V_62 & V_63 ) ) {
int V_85 = V_66 ;
V_66 /= V_30 -> V_57 ;
if ( ! V_66 )
V_66 = 1 ;
V_59 = F_21 ( V_30 -> V_57 + V_47 ) ;
while ( F_23 ( V_59 ) < V_30 -> V_57 )
V_59 += 128 ;
V_66 *= V_59 ;
V_66 = F_9 ( V_66 , V_53 [ 2 ] ) ;
if ( V_66 > V_2 -> V_60 ) {
V_2 -> V_60 = V_66 ;
V_30 -> V_55 = V_85 ;
}
}
}
V_78:
V_30 -> V_65 . V_80 = V_30 -> V_83 ;
V_30 -> V_65 . time = V_69 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_86 ;
F_45 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_40 ( V_30 ) ;
V_86 = V_69 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_77 = V_86 - V_6 -> V_8 . V_87 ;
if ( V_77 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_77 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_77 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_88 )
V_6 -> V_8 . V_27 = V_6 -> V_88 ;
} else if ( V_77 > V_6 -> V_88 ) {
F_8 ( V_2 ) ;
F_46 ( V_2 ) ;
}
}
V_6 -> V_8 . V_87 = V_86 ;
F_15 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_24 ( V_2 , V_4 ) ;
}
static void F_47 ( struct V_1 * V_2 , const T_2 V_89 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_77 = V_89 ;
if ( V_77 == 0 )
V_77 = 1 ;
if ( V_30 -> V_90 != 0 ) {
V_77 -= ( V_30 -> V_90 >> 3 ) ;
V_30 -> V_90 += V_77 ;
if ( V_77 < 0 ) {
V_77 = - V_77 ;
V_77 -= ( V_30 -> V_91 >> 2 ) ;
if ( V_77 > 0 )
V_77 >>= 3 ;
} else {
V_77 -= ( V_30 -> V_91 >> 2 ) ;
}
V_30 -> V_91 += V_77 ;
if ( V_30 -> V_91 > V_30 -> V_92 ) {
V_30 -> V_92 = V_30 -> V_91 ;
if ( V_30 -> V_92 > V_30 -> V_93 )
V_30 -> V_93 = V_30 -> V_92 ;
}
if ( F_48 ( V_30 -> V_94 , V_30 -> V_95 ) ) {
if ( V_30 -> V_92 < V_30 -> V_93 )
V_30 -> V_93 -= ( V_30 -> V_93 - V_30 -> V_92 ) >> 2 ;
V_30 -> V_95 = V_30 -> V_96 ;
V_30 -> V_92 = F_49 ( V_2 ) ;
}
} else {
V_30 -> V_90 = V_77 << 3 ;
V_30 -> V_91 = V_77 << 1 ;
V_30 -> V_92 = V_30 -> V_93 = F_32 ( V_30 -> V_91 , F_49 ( V_2 ) ) ;
V_30 -> V_95 = V_30 -> V_96 ;
}
}
void F_50 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_88 = F_51 ( V_30 ) ;
F_52 ( V_2 ) ;
}
T_2 F_53 ( const struct V_29 * V_30 , const struct V_97 * V_98 )
{
T_2 V_99 = ( V_98 ? F_54 ( V_98 , V_100 ) : 0 ) ;
if ( ! V_99 )
V_99 = V_48 ;
return F_38 ( T_2 , V_99 , V_30 -> V_101 ) ;
}
void F_55 ( struct V_29 * V_30 )
{
if ( F_56 ( V_30 ) )
V_30 -> V_102 = NULL ;
V_30 -> V_45 . V_103 &= ~ V_104 ;
}
static void F_57 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_103 |= V_105 ;
}
static void F_58 ( struct V_1 * V_2 , const int V_106 ,
const int V_107 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_106 > V_30 -> V_108 ) {
int V_109 ;
V_30 -> V_108 = F_9 ( V_110 , V_106 ) ;
if ( V_107 )
V_109 = V_111 ;
else if ( F_59 ( V_30 ) )
V_109 = V_112 ;
else if ( F_56 ( V_30 ) )
V_109 = V_113 ;
else
V_109 = V_114 ;
F_60 ( F_61 ( V_2 ) , V_109 ) ;
#if V_115 > 1
F_62 ( L_1 ,
V_30 -> V_45 . V_103 , F_2 ( V_2 ) -> V_116 ,
V_30 -> V_108 ,
V_30 -> V_117 ,
V_30 -> V_118 ,
V_30 -> V_119 ? V_30 -> V_120 : 0 ) ;
#endif
F_55 ( V_30 ) ;
}
if ( V_106 > 0 )
F_63 ( V_30 ) ;
}
static void F_64 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_121 == NULL ) ||
F_41 ( F_16 ( V_4 ) -> V_80 ,
F_16 ( V_30 -> V_121 ) -> V_80 ) )
V_30 -> V_121 = V_4 ;
if ( ! V_30 -> V_122 ||
F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_123 ) )
V_30 -> V_123 = F_16 ( V_4 ) -> V_82 ;
}
static void F_65 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_124 & ( V_125 | V_126 ) ) ) {
F_64 ( V_30 , V_4 ) ;
V_30 -> V_122 += F_66 ( V_4 ) ;
F_16 ( V_4 ) -> V_124 |= V_125 ;
}
}
static void F_67 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_64 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_124 & ( V_125 | V_126 ) ) ) {
V_30 -> V_122 += F_66 ( V_4 ) ;
F_16 ( V_4 ) -> V_124 |= V_125 ;
}
}
static bool F_68 ( struct V_29 * V_30 , bool V_127 ,
T_1 V_128 , T_1 V_82 )
{
if ( F_48 ( V_82 , V_30 -> V_96 ) || ! F_41 ( V_128 , V_82 ) )
return false ;
if ( ! F_41 ( V_128 , V_30 -> V_96 ) )
return false ;
if ( F_48 ( V_128 , V_30 -> V_94 ) )
return true ;
if ( ! V_127 || ! V_30 -> V_119 )
return false ;
if ( F_48 ( V_82 , V_30 -> V_94 ) )
return false ;
if ( ! F_41 ( V_128 , V_30 -> V_119 ) )
return true ;
if ( ! F_48 ( V_82 , V_30 -> V_119 ) )
return false ;
return ! F_41 ( V_128 , V_82 - V_30 -> V_129 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_130 = 0 ;
T_1 V_131 = V_30 -> V_96 ;
T_1 V_132 = F_70 ( V_30 ) ;
if ( ! F_56 ( V_30 ) || ! V_30 -> V_133 ||
! F_48 ( V_132 , V_30 -> V_134 ) ||
V_6 -> V_116 != V_135 )
return;
F_71 (skb, sk) {
T_1 V_136 = F_16 ( V_4 ) -> V_136 ;
if ( V_4 == F_72 ( V_2 ) )
break;
if ( V_130 == V_30 -> V_133 )
break;
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_94 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_124 & V_137 ) )
continue;
if ( F_48 ( V_132 , V_136 ) ) {
F_16 ( V_4 ) -> V_124 &= ~ V_137 ;
V_30 -> V_133 -= F_66 ( V_4 ) ;
F_67 ( V_30 , V_4 ) ;
F_60 ( F_61 ( V_2 ) , V_138 ) ;
} else {
if ( F_41 ( V_136 , V_131 ) )
V_131 = V_136 ;
V_130 += F_66 ( V_4 ) ;
}
}
if ( V_30 -> V_133 )
V_30 -> V_134 = V_131 ;
}
static bool F_73 ( struct V_1 * V_2 , const struct V_3 * V_139 ,
struct V_140 * V_141 , int V_142 ,
T_1 V_143 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_144 = F_74 ( & V_141 [ 0 ] . V_128 ) ;
T_1 V_145 = F_74 ( & V_141 [ 0 ] . V_82 ) ;
bool V_146 = false ;
if ( F_41 ( V_144 , F_16 ( V_139 ) -> V_136 ) ) {
V_146 = true ;
F_57 ( V_30 ) ;
F_60 ( F_61 ( V_2 ) , V_147 ) ;
} else if ( V_142 > 1 ) {
T_1 V_148 = F_74 ( & V_141 [ 1 ] . V_82 ) ;
T_1 V_149 = F_74 ( & V_141 [ 1 ] . V_128 ) ;
if ( ! F_48 ( V_145 , V_148 ) &&
! F_41 ( V_144 , V_149 ) ) {
V_146 = true ;
F_57 ( V_30 ) ;
F_60 ( F_61 ( V_2 ) ,
V_150 ) ;
}
}
if ( V_146 && V_30 -> V_119 && V_30 -> V_120 &&
! F_48 ( V_145 , V_143 ) &&
F_48 ( V_145 , V_30 -> V_119 ) )
V_30 -> V_120 -- ;
return V_146 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_128 , T_1 V_82 )
{
int V_151 ;
bool V_152 ;
unsigned int V_153 ;
unsigned int V_58 ;
V_152 = ! F_48 ( V_128 , F_16 ( V_4 ) -> V_80 ) &&
! F_41 ( V_82 , F_16 ( V_4 ) -> V_82 ) ;
if ( F_66 ( V_4 ) > 1 && ! V_152 &&
F_48 ( F_16 ( V_4 ) -> V_82 , V_128 ) ) {
V_58 = F_76 ( V_4 ) ;
V_152 = ! F_48 ( V_128 , F_16 ( V_4 ) -> V_80 ) ;
if ( ! V_152 ) {
V_153 = V_128 - F_16 ( V_4 ) -> V_80 ;
if ( V_153 < V_58 )
V_153 = V_58 ;
} else {
V_153 = V_82 - F_16 ( V_4 ) -> V_80 ;
if ( V_153 < V_58 )
return - V_154 ;
}
if ( V_153 > V_58 ) {
unsigned int V_155 = ( V_153 / V_58 ) * V_58 ;
if ( ! V_152 && V_155 < V_153 ) {
V_155 += V_58 ;
if ( V_155 > V_4 -> V_10 )
return 0 ;
}
V_153 = V_155 ;
}
V_151 = F_77 ( V_2 , V_4 , V_153 , V_58 ) ;
if ( V_151 < 0 )
return V_151 ;
}
return V_152 ;
}
static T_3 F_78 ( struct V_1 * V_2 ,
struct V_156 * V_157 , T_3 V_124 ,
T_1 V_128 , T_1 V_82 ,
bool V_146 , int V_158 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_159 = V_157 -> V_159 ;
if ( V_146 && ( V_124 & V_160 ) ) {
if ( V_30 -> V_119 && V_30 -> V_120 &&
F_48 ( V_82 , V_30 -> V_119 ) )
V_30 -> V_120 -- ;
if ( V_124 & V_126 )
V_157 -> V_161 = F_9 ( V_159 , V_157 -> V_161 ) ;
}
if ( ! F_48 ( V_82 , V_30 -> V_94 ) )
return V_124 ;
if ( ! ( V_124 & V_126 ) ) {
if ( V_124 & V_137 ) {
if ( V_124 & V_125 ) {
V_124 &= ~ ( V_125 | V_137 ) ;
V_30 -> V_122 -= V_158 ;
V_30 -> V_133 -= V_158 ;
}
} else {
if ( ! ( V_124 & V_160 ) ) {
if ( F_41 ( V_128 ,
F_70 ( V_30 ) ) )
V_157 -> V_161 = F_9 ( V_159 ,
V_157 -> V_161 ) ;
if ( ! F_48 ( V_82 , V_30 -> V_162 ) )
V_157 -> V_163 |= V_164 ;
}
if ( V_124 & V_125 ) {
V_124 &= ~ V_125 ;
V_30 -> V_122 -= V_158 ;
}
}
V_124 |= V_126 ;
V_157 -> V_163 |= V_165 ;
V_30 -> V_118 += V_158 ;
V_159 += V_158 ;
if ( ! F_56 ( V_30 ) && ( V_30 -> V_102 != NULL ) &&
F_41 ( V_128 , F_16 ( V_30 -> V_102 ) -> V_80 ) )
V_30 -> V_166 += V_158 ;
if ( V_159 > V_30 -> V_117 )
V_30 -> V_117 = V_159 ;
}
if ( V_146 && ( V_124 & V_137 ) ) {
V_124 &= ~ V_137 ;
V_30 -> V_133 -= V_158 ;
}
return V_124 ;
}
static bool F_79 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_156 * V_157 ,
unsigned int V_158 , int V_167 , int V_58 ,
bool V_146 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_168 = F_80 ( V_2 , V_4 ) ;
T_1 V_128 = F_16 ( V_4 ) -> V_80 ;
T_1 V_82 = V_128 + V_167 ;
F_81 ( ! V_158 ) ;
F_78 ( V_2 , V_157 , F_16 ( V_4 ) -> V_124 ,
V_128 , V_82 , V_146 , V_158 ) ;
if ( V_4 == V_30 -> V_102 )
V_30 -> V_166 += V_158 ;
F_16 ( V_168 ) -> V_82 += V_167 ;
F_16 ( V_4 ) -> V_80 += V_167 ;
F_3 ( V_168 ) -> V_169 += V_158 ;
F_81 ( F_3 ( V_4 ) -> V_169 < V_158 ) ;
F_3 ( V_4 ) -> V_169 -= V_158 ;
if ( ! F_3 ( V_168 ) -> V_11 ) {
F_3 ( V_168 ) -> V_11 = V_58 ;
F_3 ( V_168 ) -> V_170 = V_2 -> V_171 ;
}
if ( F_3 ( V_4 ) -> V_169 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_170 = 0 ;
}
F_16 ( V_168 ) -> V_124 |= ( F_16 ( V_4 ) -> V_124 & V_172 ) ;
if ( V_4 -> V_10 > 0 ) {
F_81 ( ! F_66 ( V_4 ) ) ;
F_60 ( F_61 ( V_2 ) , V_173 ) ;
return false ;
}
if ( V_4 == V_30 -> V_121 )
V_30 -> V_121 = V_168 ;
if ( V_4 == V_30 -> V_102 ) {
V_30 -> V_102 = V_168 ;
V_30 -> V_166 -= F_66 ( V_168 ) ;
}
F_16 ( V_4 ) -> V_174 |= F_16 ( V_168 ) -> V_174 ;
if ( V_4 == F_82 ( V_2 ) )
F_83 ( V_2 , V_4 ) ;
F_84 ( V_4 , V_2 ) ;
F_85 ( V_2 , V_4 ) ;
F_60 ( F_61 ( V_2 ) , V_175 ) ;
return true ;
}
static int F_86 ( const struct V_3 * V_4 )
{
return F_66 ( V_4 ) == 1 ? V_4 -> V_10 : F_76 ( V_4 ) ;
}
static int F_87 ( const struct V_3 * V_4 )
{
return ! F_88 ( V_4 ) && F_89 ( V_4 ) ;
}
static struct V_3 * F_90 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_156 * V_157 ,
T_1 V_128 , T_1 V_82 ,
bool V_146 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_168 ;
int V_58 ;
int V_158 = 0 ;
int V_10 ;
int V_152 ;
if ( ! F_91 ( V_2 ) )
goto V_176;
if ( ! V_146 &&
( F_16 ( V_4 ) -> V_124 & ( V_125 | V_137 ) ) == V_137 )
goto V_176;
if ( ! F_87 ( V_4 ) )
goto V_176;
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_94 ) )
goto V_176;
if ( F_92 ( V_4 == F_93 ( V_2 ) ) )
goto V_176;
V_168 = F_80 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_168 ) -> V_124 & V_177 ) != V_126 )
goto V_176;
V_152 = ! F_48 ( V_128 , F_16 ( V_4 ) -> V_80 ) &&
! F_41 ( V_82 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_152 ) {
V_10 = V_4 -> V_10 ;
V_158 = F_66 ( V_4 ) ;
V_58 = F_86 ( V_4 ) ;
if ( V_58 != F_86 ( V_168 ) )
goto V_176;
} else {
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_128 ) )
goto V_178;
if ( F_66 ( V_4 ) <= 1 )
goto V_178;
V_152 = ! F_48 ( V_128 , F_16 ( V_4 ) -> V_80 ) ;
if ( ! V_152 ) {
goto V_176;
}
V_10 = V_82 - F_16 ( V_4 ) -> V_80 ;
F_81 ( V_10 < 0 ) ;
F_81 ( V_10 > V_4 -> V_10 ) ;
V_58 = F_76 ( V_4 ) ;
if ( V_58 != F_86 ( V_168 ) )
goto V_176;
if ( V_10 == V_58 ) {
V_158 = 1 ;
} else if ( V_10 < V_58 ) {
goto V_178;
} else {
V_158 = V_10 / V_58 ;
V_10 = V_158 * V_58 ;
}
}
if ( ! F_48 ( F_16 ( V_4 ) -> V_80 + V_10 , V_30 -> V_94 ) )
goto V_176;
if ( ! F_94 ( V_168 , V_4 , V_10 ) )
goto V_176;
if ( ! F_79 ( V_2 , V_4 , V_157 , V_158 , V_10 , V_58 , V_146 ) )
goto V_179;
if ( V_168 == F_95 ( V_2 ) )
goto V_179;
V_4 = F_96 ( V_2 , V_168 ) ;
if ( ! F_87 ( V_4 ) ||
( V_4 == F_72 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_124 & V_177 ) != V_126 ) ||
( V_58 != F_86 ( V_4 ) ) )
goto V_179;
V_10 = V_4 -> V_10 ;
if ( F_94 ( V_168 , V_4 , V_10 ) ) {
V_158 += F_66 ( V_4 ) ;
F_79 ( V_2 , V_4 , V_157 , F_66 ( V_4 ) , V_10 , V_58 , 0 ) ;
}
V_179:
V_157 -> V_159 += V_158 ;
return V_168 ;
V_178:
return V_4 ;
V_176:
F_60 ( F_61 ( V_2 ) , V_180 ) ;
return NULL ;
}
static struct V_3 * F_97 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_181 * V_182 ,
struct V_156 * V_157 ,
T_1 V_128 , T_1 V_82 ,
bool V_183 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_184 ;
F_98 (skb, sk) {
int V_152 = 0 ;
bool V_146 = V_183 ;
if ( V_4 == F_72 ( V_2 ) )
break;
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 , V_82 ) )
break;
if ( ( V_182 != NULL ) &&
F_41 ( F_16 ( V_4 ) -> V_80 , V_182 -> V_82 ) ) {
V_152 = F_75 ( V_2 , V_4 ,
V_182 -> V_128 ,
V_182 -> V_82 ) ;
if ( V_152 > 0 )
V_146 = true ;
}
if ( V_152 <= 0 ) {
V_184 = F_90 ( V_2 , V_4 , V_157 ,
V_128 , V_82 , V_146 ) ;
if ( V_184 != NULL ) {
if ( V_184 != V_4 ) {
V_4 = V_184 ;
continue;
}
V_152 = 0 ;
} else {
V_152 = F_75 ( V_2 , V_4 ,
V_128 ,
V_82 ) ;
}
}
if ( F_92 ( V_152 < 0 ) )
break;
if ( V_152 ) {
F_16 ( V_4 ) -> V_124 =
F_78 ( V_2 ,
V_157 ,
F_16 ( V_4 ) -> V_124 ,
F_16 ( V_4 ) -> V_80 ,
F_16 ( V_4 ) -> V_82 ,
V_146 ,
F_66 ( V_4 ) ) ;
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 ,
F_70 ( V_30 ) ) )
F_83 ( V_2 , V_4 ) ;
}
V_157 -> V_159 += F_66 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_99 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_156 * V_157 ,
T_1 V_185 )
{
F_98 (skb, sk) {
if ( V_4 == F_72 ( V_2 ) )
break;
if ( F_48 ( F_16 ( V_4 ) -> V_82 , V_185 ) )
break;
V_157 -> V_159 += F_66 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_100 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_181 * V_182 ,
struct V_156 * V_157 ,
T_1 V_185 )
{
if ( V_182 == NULL )
return V_4 ;
if ( F_41 ( V_182 -> V_128 , V_185 ) ) {
V_4 = F_99 ( V_4 , V_2 , V_157 , V_182 -> V_128 ) ;
V_4 = F_97 ( V_4 , V_2 , NULL , V_157 ,
V_182 -> V_128 , V_182 -> V_82 ,
1 ) ;
}
return V_4 ;
}
static int F_101 ( const struct V_29 * V_30 , const struct V_181 * V_186 )
{
return V_186 < V_30 -> V_187 + F_102 ( V_30 -> V_187 ) ;
}
static int
F_103 ( struct V_1 * V_2 , const struct V_3 * V_139 ,
T_1 V_143 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_188 = ( F_4 ( V_139 ) +
F_16 ( V_139 ) -> V_124 ) ;
struct V_140 * V_189 = (struct V_140 * ) ( V_188 + 2 ) ;
struct V_181 V_141 [ V_190 ] ;
struct V_181 * V_186 ;
struct V_156 V_157 ;
struct V_3 * V_4 ;
int V_142 = F_9 ( V_190 , ( V_188 [ 1 ] - V_191 ) >> 3 ) ;
int V_192 ;
bool V_193 = false ;
int V_194 , V_195 ;
int V_196 ;
V_157 . V_163 = 0 ;
V_157 . V_161 = V_30 -> V_197 ;
if ( ! V_30 -> V_118 ) {
if ( F_104 ( V_30 -> V_117 ) )
V_30 -> V_117 = 0 ;
F_105 ( V_2 ) ;
}
V_193 = F_73 ( V_2 , V_139 , V_189 ,
V_142 , V_143 ) ;
if ( V_193 )
V_157 . V_163 |= V_198 ;
if ( F_41 ( F_16 ( V_139 ) -> V_136 , V_143 - V_30 -> V_129 ) )
return 0 ;
if ( ! V_30 -> V_197 )
goto V_179;
V_192 = 0 ;
V_196 = 0 ;
for ( V_194 = 0 ; V_194 < V_142 ; V_194 ++ ) {
bool V_146 = ! V_194 && V_193 ;
V_141 [ V_192 ] . V_128 = F_74 ( & V_189 [ V_194 ] . V_128 ) ;
V_141 [ V_192 ] . V_82 = F_74 ( & V_189 [ V_194 ] . V_82 ) ;
if ( ! F_68 ( V_30 , V_146 ,
V_141 [ V_192 ] . V_128 ,
V_141 [ V_192 ] . V_82 ) ) {
int V_109 ;
if ( V_146 ) {
if ( ! V_30 -> V_119 )
V_109 = V_199 ;
else
V_109 = V_200 ;
} else {
if ( ( F_16 ( V_139 ) -> V_136 != V_30 -> V_94 ) &&
! F_48 ( V_141 [ V_192 ] . V_82 , V_30 -> V_94 ) )
continue;
V_109 = V_201 ;
}
F_60 ( F_61 ( V_2 ) , V_109 ) ;
if ( V_194 == 0 )
V_196 = - 1 ;
continue;
}
if ( ! F_48 ( V_141 [ V_192 ] . V_82 , V_143 ) )
continue;
V_192 ++ ;
}
for ( V_194 = V_192 - 1 ; V_194 > 0 ; V_194 -- ) {
for ( V_195 = 0 ; V_195 < V_194 ; V_195 ++ ) {
if ( F_48 ( V_141 [ V_195 ] . V_128 , V_141 [ V_195 + 1 ] . V_128 ) ) {
F_106 ( V_141 [ V_195 ] , V_141 [ V_195 + 1 ] ) ;
if ( V_195 == V_196 )
V_196 = V_195 + 1 ;
}
}
}
V_4 = F_93 ( V_2 ) ;
V_157 . V_159 = 0 ;
V_194 = 0 ;
if ( ! V_30 -> V_118 ) {
V_186 = V_30 -> V_187 + F_102 ( V_30 -> V_187 ) ;
} else {
V_186 = V_30 -> V_187 ;
while ( F_101 ( V_30 , V_186 ) && ! V_186 -> V_128 &&
! V_186 -> V_82 )
V_186 ++ ;
}
while ( V_194 < V_192 ) {
T_1 V_128 = V_141 [ V_194 ] . V_128 ;
T_1 V_82 = V_141 [ V_194 ] . V_82 ;
bool V_146 = ( V_193 && ( V_194 == V_196 ) ) ;
struct V_181 * V_182 = NULL ;
if ( V_193 && ( ( V_194 + 1 ) == V_196 ) )
V_182 = & V_141 [ V_194 + 1 ] ;
while ( F_101 ( V_30 , V_186 ) &&
! F_41 ( V_128 , V_186 -> V_82 ) )
V_186 ++ ;
if ( F_101 ( V_30 , V_186 ) && ! V_146 &&
F_48 ( V_82 , V_186 -> V_128 ) ) {
if ( F_41 ( V_128 , V_186 -> V_128 ) ) {
V_4 = F_99 ( V_4 , V_2 , & V_157 ,
V_128 ) ;
V_4 = F_97 ( V_4 , V_2 , V_182 ,
& V_157 ,
V_128 ,
V_186 -> V_128 ,
V_146 ) ;
}
if ( ! F_48 ( V_82 , V_186 -> V_82 ) )
goto V_202;
V_4 = F_100 ( V_4 , V_2 , V_182 ,
& V_157 ,
V_186 -> V_82 ) ;
if ( F_70 ( V_30 ) == V_186 -> V_82 ) {
V_4 = F_82 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_157 . V_159 = V_30 -> V_117 ;
V_186 ++ ;
goto V_203;
}
V_4 = F_99 ( V_4 , V_2 , & V_157 , V_186 -> V_82 ) ;
V_186 ++ ;
continue;
}
if ( ! F_41 ( V_128 , F_70 ( V_30 ) ) ) {
V_4 = F_82 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_157 . V_159 = V_30 -> V_117 ;
}
V_4 = F_99 ( V_4 , V_2 , & V_157 , V_128 ) ;
V_203:
V_4 = F_97 ( V_4 , V_2 , V_182 , & V_157 ,
V_128 , V_82 , V_146 ) ;
V_202:
V_194 ++ ;
}
for ( V_194 = 0 ; V_194 < F_102 ( V_30 -> V_187 ) - V_192 ; V_194 ++ ) {
V_30 -> V_187 [ V_194 ] . V_128 = 0 ;
V_30 -> V_187 [ V_194 ] . V_82 = 0 ;
}
for ( V_195 = 0 ; V_195 < V_192 ; V_195 ++ )
V_30 -> V_187 [ V_194 ++ ] = V_141 [ V_195 ] ;
F_69 ( V_2 ) ;
F_107 ( V_30 ) ;
if ( ( V_157 . V_161 < V_30 -> V_117 ) &&
( ( F_2 ( V_2 ) -> V_116 != V_204 ) || V_30 -> V_119 ) )
F_58 ( V_2 , V_30 -> V_117 - V_157 . V_161 , 0 ) ;
V_179:
#if V_115 > 0
F_104 ( ( int ) V_30 -> V_118 < 0 ) ;
F_104 ( ( int ) V_30 -> V_122 < 0 ) ;
F_104 ( ( int ) V_30 -> V_133 < 0 ) ;
F_104 ( ( int ) F_108 ( V_30 ) < 0 ) ;
#endif
return V_157 . V_163 ;
}
static bool F_109 ( struct V_29 * V_30 )
{
T_1 V_205 ;
V_205 = F_32 ( V_30 -> V_122 , 1U ) ;
V_205 = F_9 ( V_205 , V_30 -> V_197 ) ;
if ( ( V_30 -> V_118 + V_205 ) > V_30 -> V_197 ) {
V_30 -> V_118 = V_30 -> V_197 - V_205 ;
return true ;
}
return false ;
}
static void F_110 ( struct V_1 * V_2 , const int V_206 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_109 ( V_30 ) )
F_58 ( V_2 , V_30 -> V_197 + V_206 , 0 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_118 ++ ;
F_110 ( V_2 , 0 ) ;
F_107 ( V_30 ) ;
}
static void F_112 ( struct V_1 * V_2 , int V_207 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_207 > 0 ) {
if ( V_207 - 1 >= V_30 -> V_118 )
V_30 -> V_118 = 0 ;
else
V_30 -> V_118 -= V_207 - 1 ;
}
F_110 ( V_2 , V_207 ) ;
F_107 ( V_30 ) ;
}
static inline void F_113 ( struct V_29 * V_30 )
{
V_30 -> V_118 = 0 ;
}
static void F_114 ( struct V_29 * V_30 )
{
V_30 -> V_133 = 0 ;
V_30 -> V_122 = 0 ;
V_30 -> V_119 = 0 ;
V_30 -> V_120 = 0 ;
}
void F_115 ( struct V_29 * V_30 )
{
F_114 ( V_30 ) ;
V_30 -> V_117 = 0 ;
V_30 -> V_118 = 0 ;
}
void F_116 ( struct V_1 * V_2 , int V_208 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_209 = false ;
if ( V_6 -> V_116 <= V_210 ||
! F_48 ( V_30 -> V_162 , V_30 -> V_94 ) ||
( V_6 -> V_116 == V_204 && ! V_6 -> V_211 ) ) {
V_209 = true ;
V_30 -> V_212 = F_117 ( V_2 ) ;
V_30 -> V_213 = V_6 -> V_214 -> V_215 ( V_2 ) ;
F_118 ( V_2 , V_216 ) ;
}
V_30 -> V_217 = 1 ;
V_30 -> V_218 = 0 ;
V_30 -> V_68 = V_69 ;
F_114 ( V_30 ) ;
if ( F_59 ( V_30 ) )
F_113 ( V_30 ) ;
V_30 -> V_119 = V_30 -> V_94 ;
if ( V_208 ) {
V_30 -> V_118 = 0 ;
V_30 -> V_117 = 0 ;
}
F_119 ( V_30 ) ;
F_71 (skb, sk) {
if ( V_4 == F_72 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_124 & V_160 )
V_30 -> V_119 = 0 ;
F_16 ( V_4 ) -> V_124 &= ( ~ V_177 ) | V_126 ;
if ( ! ( F_16 ( V_4 ) -> V_124 & V_126 ) || V_208 ) {
F_16 ( V_4 ) -> V_124 &= ~ V_126 ;
F_16 ( V_4 ) -> V_124 |= V_125 ;
V_30 -> V_122 += F_66 ( V_4 ) ;
V_30 -> V_123 = F_16 ( V_4 ) -> V_82 ;
}
}
F_107 ( V_30 ) ;
V_30 -> V_108 = F_38 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_120 ( V_2 , V_204 ) ;
V_30 -> V_162 = V_30 -> V_96 ;
F_12 ( V_30 ) ;
V_30 -> V_219 = V_220 &&
( V_209 || V_6 -> V_211 ) &&
! F_2 ( V_2 ) -> V_221 . V_222 ;
}
static bool F_121 ( struct V_1 * V_2 , int V_163 )
{
if ( V_163 & V_223 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_60 ( F_61 ( V_2 ) , V_224 ) ;
F_116 ( V_2 , 1 ) ;
V_6 -> V_211 ++ ;
F_122 ( V_2 , F_93 ( V_2 ) ) ;
F_123 ( V_2 , V_225 ,
V_6 -> V_88 , V_226 ) ;
return true ;
}
return false ;
}
static inline int F_124 ( const struct V_29 * V_30 )
{
return F_59 ( V_30 ) ? V_30 -> V_118 + 1 : V_30 -> V_117 ;
}
static inline int F_125 ( const struct V_29 * V_30 )
{
return F_56 ( V_30 ) ? V_30 -> V_117 : V_30 -> V_118 + 1 ;
}
static bool F_126 ( struct V_1 * V_2 , int V_163 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_227 ;
if ( V_228 < 2 || V_228 > 3 ||
( V_163 & V_229 ) || ! V_30 -> V_90 )
return false ;
V_227 = F_27 (unsigned long, (tp->srtt >> 5), msecs_to_jiffies(2)) ;
if ( ! F_127 ( F_2 ( V_2 ) -> V_230 , ( V_231 + V_227 ) ) )
return false ;
F_123 ( V_2 , V_232 , V_227 ,
V_226 ) ;
return true ;
}
static bool F_128 ( struct V_1 * V_2 , int V_163 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_197 ;
if ( V_30 -> V_122 )
return true ;
if ( F_125 ( V_30 ) > V_30 -> V_108 )
return true ;
V_197 = V_30 -> V_197 ;
if ( V_197 <= V_30 -> V_108 &&
V_30 -> V_118 >= F_27 ( T_2 , V_197 / 2 , V_233 ) &&
! F_129 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_234 || V_235 ) &&
F_130 ( V_30 ) && F_125 ( V_30 ) > 1 &&
F_131 ( V_30 ) && ! F_72 ( V_2 ) )
return true ;
if ( V_30 -> V_236 && ! V_30 -> V_133 && V_30 -> V_118 &&
( V_30 -> V_197 >= ( V_30 -> V_118 + 1 ) && V_30 -> V_197 < 4 ) &&
! F_129 ( V_2 ) )
return ! F_126 ( V_2 , V_163 ) ;
return false ;
}
static void F_132 ( struct V_1 * V_2 , int V_237 , int V_238 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_130 , V_239 ;
int V_151 ;
unsigned int V_58 ;
const T_1 V_240 = F_131 ( V_30 ) ? V_30 -> V_96 : V_30 -> V_162 ;
F_104 ( V_237 > V_30 -> V_197 ) ;
if ( V_30 -> V_102 ) {
V_4 = V_30 -> V_102 ;
V_130 = V_30 -> V_166 ;
if ( V_238 && V_4 != F_93 ( V_2 ) )
return;
} else {
V_4 = F_93 ( V_2 ) ;
V_130 = 0 ;
}
F_98 (skb, sk) {
if ( V_4 == F_72 ( V_2 ) )
break;
V_30 -> V_102 = V_4 ;
V_30 -> V_166 = V_130 ;
if ( F_48 ( F_16 ( V_4 ) -> V_82 , V_240 ) )
break;
V_239 = V_130 ;
if ( F_56 ( V_30 ) || F_59 ( V_30 ) ||
( F_16 ( V_4 ) -> V_124 & V_126 ) )
V_130 += F_66 ( V_4 ) ;
if ( V_130 > V_237 ) {
if ( ( F_131 ( V_30 ) && ! F_56 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_124 & V_126 ) ||
( V_239 >= V_237 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_151 = F_77 ( V_2 , V_4 , ( V_237 - V_239 ) * V_58 , V_58 ) ;
if ( V_151 < 0 )
break;
V_130 = V_237 ;
}
F_65 ( V_30 , V_4 ) ;
if ( V_238 )
break;
}
F_107 ( V_30 ) ;
}
static void F_133 ( struct V_1 * V_2 , int V_241 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_59 ( V_30 ) ) {
F_132 ( V_2 , 1 , 1 ) ;
} else if ( F_56 ( V_30 ) ) {
int V_242 = V_30 -> V_117 - V_30 -> V_108 ;
if ( V_242 <= 0 )
V_242 = 1 ;
F_132 ( V_2 , V_242 , 0 ) ;
} else {
int V_243 = V_30 -> V_118 - V_30 -> V_108 ;
if ( V_243 >= 0 )
F_132 ( V_2 , V_243 , 0 ) ;
else if ( V_241 )
F_132 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_134 ( struct V_29 * V_30 )
{
V_30 -> V_217 = F_9 ( V_30 -> V_217 ,
F_108 ( V_30 ) + F_135 ( V_30 ) ) ;
V_30 -> V_68 = V_69 ;
}
static inline bool F_136 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_244 ||
( V_30 -> V_45 . V_245 && V_30 -> V_45 . V_81 &&
F_41 ( V_30 -> V_45 . V_81 , V_30 -> V_244 ) ) ;
}
static void F_137 ( struct V_1 * V_2 , const char * V_246 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_247 * V_248 = F_138 ( V_2 ) ;
if ( V_2 -> V_249 == V_250 ) {
F_62 ( L_2 ,
V_246 ,
& V_248 -> V_251 , F_139 ( V_248 -> V_252 ) ,
V_30 -> V_217 , F_140 ( V_30 ) ,
V_30 -> V_213 , V_30 -> V_212 ,
V_30 -> V_197 ) ;
}
#if F_141 ( V_253 )
else if ( V_2 -> V_249 == V_254 ) {
struct V_255 * V_256 = F_142 ( V_2 ) ;
F_62 ( L_3 ,
V_246 ,
& V_256 -> V_257 , F_139 ( V_248 -> V_252 ) ,
V_30 -> V_217 , F_140 ( V_30 ) ,
V_30 -> V_213 , V_30 -> V_212 ,
V_30 -> V_197 ) ;
}
#endif
}
static void F_143 ( struct V_1 * V_2 , bool V_258 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_258 ) {
struct V_3 * V_4 ;
F_71 (skb, sk) {
if ( V_4 == F_72 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_124 &= ~ V_125 ;
}
V_30 -> V_122 = 0 ;
F_119 ( V_30 ) ;
}
if ( V_30 -> V_212 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_214 -> V_259 )
V_30 -> V_217 = V_6 -> V_214 -> V_259 ( V_2 ) ;
else
V_30 -> V_217 = F_32 ( V_30 -> V_217 , V_30 -> V_213 << 1 ) ;
if ( V_30 -> V_212 > V_30 -> V_213 ) {
V_30 -> V_213 = V_30 -> V_212 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_217 = F_32 ( V_30 -> V_217 , V_30 -> V_213 ) ;
}
V_30 -> V_68 = V_69 ;
V_30 -> V_119 = 0 ;
}
static inline bool F_144 ( const struct V_29 * V_30 )
{
return V_30 -> V_119 && ( ! V_30 -> V_120 || F_136 ( V_30 ) ) ;
}
static bool F_145 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_144 ( V_30 ) ) {
int V_109 ;
F_137 ( V_2 , F_2 ( V_2 ) -> V_116 == V_204 ? L_4 : L_5 ) ;
F_143 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_116 == V_204 )
V_109 = V_260 ;
else
V_109 = V_261 ;
F_60 ( F_61 ( V_2 ) , V_109 ) ;
}
if ( V_30 -> V_94 == V_30 -> V_162 && F_59 ( V_30 ) ) {
F_134 ( V_30 ) ;
return true ;
}
F_120 ( V_2 , V_262 ) ;
return false ;
}
static bool F_146 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_119 && ! V_30 -> V_120 ) {
F_137 ( V_2 , L_6 ) ;
F_143 ( V_2 , false ) ;
F_60 ( F_61 ( V_2 ) , V_263 ) ;
return true ;
}
return false ;
}
static bool F_147 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_133 )
return true ;
V_4 = F_93 ( V_2 ) ;
if ( F_92 ( V_4 && F_16 ( V_4 ) -> V_124 & V_172 ) )
return true ;
return false ;
}
static bool F_148 ( struct V_1 * V_2 , bool V_264 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_264 || F_144 ( V_30 ) ) {
F_143 ( V_2 , true ) ;
F_137 ( V_2 , L_7 ) ;
F_60 ( F_61 ( V_2 ) , V_260 ) ;
if ( V_264 )
F_60 ( F_61 ( V_2 ) ,
V_265 ) ;
F_2 ( V_2 ) -> V_211 = 0 ;
if ( V_264 || F_131 ( V_30 ) )
F_120 ( V_2 , V_262 ) ;
return true ;
}
return false ;
}
static void F_149 ( struct V_1 * V_2 , const bool V_266 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_162 = V_30 -> V_96 ;
V_30 -> V_267 = 0 ;
V_30 -> V_218 = 0 ;
V_30 -> V_268 = V_30 -> V_217 ;
V_30 -> V_269 = 0 ;
V_30 -> V_270 = 0 ;
if ( V_266 )
V_30 -> V_213 = F_2 ( V_2 ) -> V_214 -> V_215 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_150 ( struct V_1 * V_2 , const int V_271 ,
int V_241 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_272 = 0 ;
int V_273 = V_30 -> V_213 - F_108 ( V_30 ) ;
int V_274 = V_271 -
( V_30 -> V_197 - V_30 -> V_118 ) ;
V_30 -> V_269 += V_274 ;
if ( F_108 ( V_30 ) > V_30 -> V_213 ) {
T_4 V_275 = ( T_4 ) V_30 -> V_213 * V_30 -> V_269 +
V_30 -> V_268 - 1 ;
V_272 = F_151 ( V_275 , V_30 -> V_268 ) - V_30 -> V_270 ;
} else {
V_272 = F_38 ( int , V_273 ,
F_27 ( int , V_30 -> V_269 - V_30 -> V_270 ,
V_274 ) + 1 ) ;
}
V_272 = F_32 ( V_272 , ( V_241 ? 1 : 0 ) ) ;
V_30 -> V_217 = F_108 ( V_30 ) + V_272 ;
}
static inline void F_152 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_116 == V_276 ||
( V_30 -> V_119 && V_30 -> V_213 < V_277 ) ) {
V_30 -> V_217 = V_30 -> V_213 ;
V_30 -> V_68 = V_69 ;
}
F_118 ( V_2 , V_278 ) ;
}
void F_153 ( struct V_1 * V_2 , const int V_266 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_212 = 0 ;
if ( F_2 ( V_2 ) -> V_116 < V_276 ) {
V_30 -> V_119 = 0 ;
F_149 ( V_2 , V_266 ) ;
F_120 ( V_2 , V_276 ) ;
}
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_157 = V_262 ;
if ( F_140 ( V_30 ) || F_147 ( V_2 ) )
V_157 = V_210 ;
if ( F_2 ( V_2 ) -> V_116 != V_157 ) {
F_120 ( V_2 , V_157 ) ;
V_30 -> V_162 = V_30 -> V_96 ;
}
}
static void F_155 ( struct V_1 * V_2 , int V_163 , const int V_271 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_107 ( V_30 ) ;
if ( ! F_147 ( V_2 ) )
V_30 -> V_244 = 0 ;
if ( V_163 & V_229 )
F_153 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_116 != V_276 ) {
F_154 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_116 != V_262 )
F_134 ( V_30 ) ;
} else {
F_150 ( V_2 , V_271 , 0 ) ;
}
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_221 . V_279 = V_6 -> V_221 . V_222 - 1 ;
V_6 -> V_221 . V_222 = 0 ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_212 = F_117 ( V_2 ) ;
V_30 -> V_217 = V_30 -> V_217 *
F_158 ( V_2 , V_30 -> V_280 ) /
V_6 -> V_221 . V_222 ;
V_30 -> V_218 = 0 ;
V_30 -> V_68 = V_69 ;
V_30 -> V_213 = F_117 ( V_2 ) ;
V_6 -> V_221 . V_281 = V_6 -> V_221 . V_222 ;
V_6 -> V_221 . V_222 = 0 ;
F_159 ( V_2 , V_6 -> V_282 ) ;
}
void F_160 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_161 ( V_2 ) ;
T_1 V_283 = V_30 -> V_122 ;
F_71 (skb, sk) {
if ( V_4 == F_72 ( V_2 ) )
break;
if ( F_86 ( V_4 ) > V_58 &&
! ( F_16 ( V_4 ) -> V_124 & V_126 ) ) {
if ( F_16 ( V_4 ) -> V_124 & V_137 ) {
F_16 ( V_4 ) -> V_124 &= ~ V_137 ;
V_30 -> V_133 -= F_66 ( V_4 ) ;
}
F_67 ( V_30 , V_4 ) ;
}
}
F_162 ( V_30 ) ;
if ( V_283 == V_30 -> V_122 )
return;
if ( F_59 ( V_30 ) )
F_109 ( V_30 ) ;
F_107 ( V_30 ) ;
if ( V_6 -> V_116 != V_204 ) {
V_30 -> V_162 = V_30 -> V_96 ;
V_30 -> V_213 = F_117 ( V_2 ) ;
V_30 -> V_212 = 0 ;
V_30 -> V_119 = 0 ;
F_120 ( V_2 , V_204 ) ;
}
F_163 ( V_2 ) ;
}
static void F_164 ( struct V_1 * V_2 , bool V_284 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_109 ;
if ( F_59 ( V_30 ) )
V_109 = V_285 ;
else
V_109 = V_286 ;
F_60 ( F_61 ( V_2 ) , V_109 ) ;
V_30 -> V_212 = 0 ;
V_30 -> V_119 = V_30 -> V_94 ;
V_30 -> V_120 = V_30 -> V_133 ;
if ( F_2 ( V_2 ) -> V_116 < V_276 ) {
if ( ! V_284 )
V_30 -> V_212 = F_117 ( V_2 ) ;
F_149 ( V_2 , true ) ;
}
F_120 ( V_2 , V_135 ) ;
}
static void F_165 ( struct V_1 * V_2 , int V_163 , bool V_287 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_288 = ! F_41 ( V_30 -> V_94 , V_30 -> V_162 ) ;
if ( V_30 -> V_219 ) {
if ( V_163 & V_164 ) {
F_148 ( V_2 , true ) ;
return;
}
if ( F_48 ( V_30 -> V_96 , V_30 -> V_162 ) &&
( V_163 & V_165 || V_287 ) ) {
V_30 -> V_219 = 0 ;
} else if ( V_163 & V_289 && ! V_288 ) {
V_30 -> V_162 = V_30 -> V_96 ;
F_166 ( V_2 , F_161 ( V_2 ) ,
V_290 ) ;
if ( F_48 ( V_30 -> V_96 , V_30 -> V_162 ) )
return;
V_30 -> V_219 = 0 ;
}
}
if ( V_288 ) {
V_6 -> V_211 = 0 ;
F_145 ( V_2 ) ;
return;
}
if ( V_163 & V_291 )
V_6 -> V_211 = 0 ;
if ( F_59 ( V_30 ) ) {
if ( F_48 ( V_30 -> V_96 , V_30 -> V_162 ) && V_287 )
F_111 ( V_2 ) ;
else if ( V_163 & V_289 )
F_113 ( V_30 ) ;
}
if ( F_148 ( V_2 , false ) )
return;
F_163 ( V_2 ) ;
}
static bool F_167 ( struct V_1 * V_2 , const int V_207 ,
const int V_271 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_119 && F_136 ( V_30 ) ) {
F_58 ( V_2 , F_124 ( V_30 ) + V_207 , 1 ) ;
if ( V_30 -> V_133 ) {
F_150 ( V_2 , V_271 , 0 ) ;
return true ;
}
if ( ! F_147 ( V_2 ) )
V_30 -> V_244 = 0 ;
F_137 ( V_2 , L_8 ) ;
F_143 ( V_2 , true ) ;
F_60 ( F_61 ( V_2 ) , V_292 ) ;
F_154 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_168 ( struct V_1 * V_2 , const int V_207 ,
const int V_271 ,
bool V_287 , int V_163 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_293 = V_287 || ( ( V_163 & V_165 ) &&
( F_124 ( V_30 ) > V_30 -> V_108 ) ) ;
int V_241 = 0 ;
if ( F_104 ( ! V_30 -> V_197 && V_30 -> V_118 ) )
V_30 -> V_118 = 0 ;
if ( F_104 ( ! V_30 -> V_118 && V_30 -> V_117 ) )
V_30 -> V_117 = 0 ;
if ( V_163 & V_229 )
V_30 -> V_212 = 0 ;
if ( F_121 ( V_2 , V_163 ) )
return;
F_107 ( V_30 ) ;
if ( V_6 -> V_116 == V_262 ) {
F_104 ( V_30 -> V_133 != 0 ) ;
V_30 -> V_244 = 0 ;
} else if ( ! F_41 ( V_30 -> V_94 , V_30 -> V_162 ) ) {
switch ( V_6 -> V_116 ) {
case V_276 :
if ( V_30 -> V_94 != V_30 -> V_162 ) {
F_152 ( V_2 ) ;
F_120 ( V_2 , V_262 ) ;
}
break;
case V_135 :
if ( F_59 ( V_30 ) )
F_113 ( V_30 ) ;
if ( F_145 ( V_2 ) )
return;
F_152 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_116 ) {
case V_135 :
if ( ! ( V_163 & V_289 ) ) {
if ( F_59 ( V_30 ) && V_287 )
F_111 ( V_2 ) ;
} else {
if ( F_167 ( V_2 , V_207 , V_271 ) )
return;
V_293 = F_59 ( V_30 ) ||
F_124 ( V_30 ) > V_30 -> V_108 ;
}
if ( F_146 ( V_2 ) ) {
F_154 ( V_2 ) ;
return;
}
break;
case V_204 :
F_165 ( V_2 , V_163 , V_287 ) ;
if ( V_6 -> V_116 != V_262 )
return;
default:
if ( F_59 ( V_30 ) ) {
if ( V_163 & V_289 )
F_113 ( V_30 ) ;
if ( V_287 )
F_111 ( V_2 ) ;
}
if ( V_6 -> V_116 <= V_210 )
F_146 ( V_2 ) ;
if ( ! F_128 ( V_2 , V_163 ) ) {
F_155 ( V_2 , V_163 , V_271 ) ;
return;
}
if ( V_6 -> V_116 < V_276 &&
V_6 -> V_221 . V_222 &&
V_30 -> V_94 == V_30 -> V_294 . V_295 ) {
F_156 ( V_2 ) ;
V_30 -> V_217 ++ ;
F_160 ( V_2 ) ;
return;
}
F_164 ( V_2 , ( V_163 & V_229 ) ) ;
V_241 = 1 ;
}
if ( V_293 )
F_133 ( V_2 , V_241 ) ;
F_150 ( V_2 , V_271 , V_241 ) ;
F_163 ( V_2 ) ;
}
void F_169 ( struct V_1 * V_2 , T_1 V_296 )
{
F_47 ( V_2 , V_296 ) ;
F_50 ( V_2 ) ;
F_2 ( V_2 ) -> V_297 = 0 ;
}
static void F_170 ( struct V_1 * V_2 , int V_163 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_169 ( V_2 , V_69 - V_30 -> V_45 . V_81 ) ;
}
static void F_171 ( struct V_1 * V_2 , T_1 V_296 , int V_163 )
{
if ( V_163 & V_298 )
return;
F_169 ( V_2 , V_296 ) ;
}
static inline void F_172 ( struct V_1 * V_2 , const int V_163 ,
const T_5 V_296 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_245 && V_30 -> V_45 . V_81 )
F_170 ( V_2 , V_163 ) ;
else if ( V_296 >= 0 )
F_171 ( V_2 , V_296 , V_163 ) ;
}
static void F_173 ( struct V_1 * V_2 , T_1 V_299 , T_1 V_300 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_214 -> V_301 ( V_2 , V_299 , V_300 ) ;
F_7 ( V_2 ) -> V_68 = V_69 ;
}
void F_174 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_302 )
return;
if ( ! V_30 -> V_197 ) {
F_175 ( V_2 , V_225 ) ;
} else {
T_1 V_303 = F_2 ( V_2 ) -> V_88 ;
if ( V_6 -> V_304 == V_232 ||
V_6 -> V_304 == V_305 ) {
struct V_3 * V_4 = F_93 ( V_2 ) ;
const T_1 V_306 = F_16 ( V_4 ) -> V_307 + V_303 ;
T_5 V_273 = ( T_5 ) ( V_306 - V_69 ) ;
if ( V_273 > 0 )
V_303 = V_273 ;
}
F_123 ( V_2 , V_225 , V_303 ,
V_226 ) ;
}
}
void F_176 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_174 ( V_2 ) ;
if ( ! V_30 -> V_236 )
return;
F_164 ( V_2 , false ) ;
F_133 ( V_2 , 1 ) ;
F_163 ( V_2 ) ;
}
static T_1 F_177 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_308 ;
F_81 ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_94 ) ) ;
V_308 = F_66 ( V_4 ) ;
if ( F_178 ( V_2 , V_4 , V_30 -> V_94 - F_16 ( V_4 ) -> V_80 ) )
return 0 ;
V_308 -= F_66 ( V_4 ) ;
if ( V_308 ) {
F_81 ( F_66 ( V_4 ) == 0 ) ;
F_81 ( ! F_41 ( F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ) ;
}
return V_308 ;
}
static int F_179 ( struct V_1 * V_2 , int V_309 ,
T_1 V_143 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_86 = V_69 ;
int V_310 = true ;
int V_163 = 0 ;
T_1 V_311 = 0 ;
T_1 V_161 = V_30 -> V_197 ;
T_1 V_312 = V_30 -> V_118 ;
T_5 V_296 = - 1 ;
T_5 V_313 = - 1 ;
T_6 V_314 = F_180 () ;
while ( ( V_4 = F_93 ( V_2 ) ) && V_4 != F_72 ( V_2 ) ) {
struct V_315 * V_316 = F_16 ( V_4 ) ;
T_1 V_317 ;
T_3 V_124 = V_316 -> V_124 ;
if ( F_48 ( V_316 -> V_82 , V_30 -> V_94 ) ) {
if ( F_66 ( V_4 ) == 1 ||
! F_48 ( V_30 -> V_94 , V_316 -> V_80 ) )
break;
V_317 = F_177 ( V_2 , V_4 ) ;
if ( ! V_317 )
break;
V_310 = false ;
} else {
V_317 = F_66 ( V_4 ) ;
}
if ( V_124 & V_160 ) {
if ( V_124 & V_137 )
V_30 -> V_133 -= V_317 ;
V_163 |= V_298 ;
V_313 = - 1 ;
V_296 = - 1 ;
} else {
V_313 = V_86 - V_316 -> V_307 ;
V_314 = V_4 -> V_318 ;
if ( V_296 < 0 ) {
V_296 = V_313 ;
}
if ( ! ( V_124 & V_126 ) )
V_161 = F_9 ( V_311 , V_161 ) ;
if ( ! F_48 ( V_316 -> V_82 , V_30 -> V_162 ) )
V_163 |= V_164 ;
}
if ( V_124 & V_126 )
V_30 -> V_118 -= V_317 ;
if ( V_124 & V_125 )
V_30 -> V_122 -= V_317 ;
V_30 -> V_197 -= V_317 ;
V_311 += V_317 ;
if ( ! ( V_316 -> V_174 & V_319 ) ) {
V_163 |= V_291 ;
} else {
V_163 |= V_320 ;
V_30 -> V_244 = 0 ;
}
if ( ! V_310 )
break;
F_84 ( V_4 , V_2 ) ;
F_85 ( V_2 , V_4 ) ;
if ( V_4 == V_30 -> V_121 )
V_30 -> V_121 = NULL ;
if ( V_4 == V_30 -> V_102 )
V_30 -> V_102 = NULL ;
}
if ( F_181 ( F_182 ( V_30 -> V_321 , V_143 , V_30 -> V_94 ) ) )
V_30 -> V_321 = V_30 -> V_94 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_124 & V_126 ) )
V_163 |= V_223 ;
if ( V_163 & V_322 ) {
const struct V_323 * V_324
= F_2 ( V_2 ) -> V_214 ;
if ( F_92 ( V_6 -> V_221 . V_222 &&
! F_48 ( V_30 -> V_294 . V_325 , V_30 -> V_94 ) ) ) {
F_157 ( V_2 ) ;
}
F_172 ( V_2 , V_163 , V_296 ) ;
F_174 ( V_2 ) ;
if ( F_59 ( V_30 ) ) {
F_112 ( V_2 , V_311 ) ;
} else {
int V_273 ;
if ( V_161 < V_309 )
F_58 ( V_2 , V_30 -> V_117 - V_161 , 0 ) ;
V_273 = F_56 ( V_30 ) ? V_311 :
V_312 - V_30 -> V_118 ;
V_30 -> V_166 -= F_9 ( V_30 -> V_166 , V_273 ) ;
}
V_30 -> V_117 -= F_9 ( V_311 , V_30 -> V_117 ) ;
if ( V_324 -> V_311 ) {
T_5 V_326 = - 1 ;
if ( ! ( V_163 & V_298 ) ) {
if ( V_324 -> V_327 & V_328 &&
! F_183 ( V_314 ,
F_180 () ) )
V_326 = F_184 ( F_185 () ,
V_314 ) ;
else if ( V_313 >= 0 )
V_326 = F_186 ( V_313 ) ;
}
V_324 -> V_311 ( V_2 , V_311 , V_326 ) ;
}
}
#if V_115 > 0
F_104 ( ( int ) V_30 -> V_118 < 0 ) ;
F_104 ( ( int ) V_30 -> V_122 < 0 ) ;
F_104 ( ( int ) V_30 -> V_133 < 0 ) ;
if ( ! V_30 -> V_197 && F_131 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_122 ) {
F_62 ( L_9 ,
V_30 -> V_122 , V_6 -> V_116 ) ;
V_30 -> V_122 = 0 ;
}
if ( V_30 -> V_118 ) {
F_62 ( L_10 ,
V_30 -> V_118 , V_6 -> V_116 ) ;
V_30 -> V_118 = 0 ;
}
if ( V_30 -> V_133 ) {
F_62 ( L_11 ,
V_30 -> V_133 , V_6 -> V_116 ) ;
V_30 -> V_133 = 0 ;
}
}
#endif
return V_163 ;
}
static void F_187 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_48 ( F_16 ( F_72 ( V_2 ) ) -> V_82 , F_188 ( V_30 ) ) ) {
V_6 -> V_297 = 0 ;
F_175 ( V_2 , V_329 ) ;
} else {
F_123 ( V_2 , V_329 ,
F_9 ( V_6 -> V_88 << V_6 -> V_297 , V_226 ) ,
V_226 ) ;
}
}
static inline bool F_189 ( const struct V_1 * V_2 , const int V_163 )
{
return ! ( V_163 & V_330 ) || ( V_163 & V_331 ) ||
F_2 ( V_2 ) -> V_116 != V_262 ;
}
static inline bool F_190 ( const struct V_1 * V_2 , const int V_163 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_163 & V_229 ) || V_30 -> V_217 < V_30 -> V_213 ) &&
! F_191 ( V_2 ) ;
}
static inline bool F_192 ( const struct V_29 * V_30 ,
const T_1 V_299 , const T_1 V_136 ,
const T_1 V_332 )
{
return F_48 ( V_299 , V_30 -> V_94 ) ||
F_48 ( V_136 , V_30 -> V_333 ) ||
( V_136 == V_30 -> V_333 && V_332 > V_30 -> V_334 ) ;
}
static int F_193 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_299 ,
T_1 V_136 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_163 = 0 ;
T_1 V_332 = F_139 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_181 ( ! F_6 ( V_4 ) -> V_43 ) )
V_332 <<= V_30 -> V_45 . V_335 ;
if ( F_192 ( V_30 , V_299 , V_136 , V_332 ) ) {
V_163 |= V_336 ;
F_194 ( V_30 , V_136 ) ;
if ( V_30 -> V_334 != V_332 ) {
V_30 -> V_334 = V_332 ;
V_30 -> V_337 = 0 ;
F_195 ( V_2 ) ;
if ( V_332 > V_30 -> V_129 ) {
V_30 -> V_129 = V_332 ;
F_159 ( V_2 , F_2 ( V_2 ) -> V_282 ) ;
}
}
}
V_30 -> V_94 = V_299 ;
return V_163 ;
}
static void F_196 ( struct V_1 * V_2 )
{
static T_1 V_338 ;
static unsigned int V_339 ;
T_1 V_86 = V_231 / V_340 ;
if ( V_86 != V_338 ) {
V_338 = V_86 ;
V_339 = 0 ;
}
if ( ++ V_339 <= V_341 ) {
F_60 ( F_61 ( V_2 ) , V_342 ) ;
F_197 ( V_2 ) ;
}
}
static void F_198 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_343 = V_30 -> V_45 . V_344 ;
V_30 -> V_45 . V_345 = F_199 () ;
}
static void F_200 ( struct V_29 * V_30 , T_1 V_80 )
{
if ( V_30 -> V_45 . V_245 && ! F_48 ( V_80 , V_30 -> V_346 ) ) {
if ( F_201 ( & V_30 -> V_45 , 0 ) )
F_198 ( V_30 ) ;
}
}
static void F_202 ( struct V_1 * V_2 , T_1 V_299 , int V_163 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_347 = ( V_299 == V_30 -> V_267 ) &&
! ( V_163 & ( V_289 |
V_330 | V_165 ) ) ;
if ( V_347 ) {
V_30 -> V_267 = 0 ;
return;
}
if ( F_48 ( V_299 , V_30 -> V_267 ) ) {
V_30 -> V_267 = 0 ;
if ( ! ( V_163 & V_198 ) ) {
F_149 ( V_2 , true ) ;
F_120 ( V_2 , V_276 ) ;
F_152 ( V_2 ) ;
F_120 ( V_2 , V_262 ) ;
F_60 ( F_61 ( V_2 ) ,
V_348 ) ;
}
}
}
static int F_203 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_163 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_143 = V_30 -> V_94 ;
T_1 V_136 = F_16 ( V_4 ) -> V_80 ;
T_1 V_299 = F_16 ( V_4 ) -> V_136 ;
bool V_287 = false ;
T_1 V_349 ;
T_1 V_309 ;
int V_350 = V_30 -> V_197 ;
const int V_271 = V_30 -> V_197 - V_30 -> V_118 ;
int V_207 = 0 ;
if ( F_41 ( V_299 , V_143 ) ) {
if ( F_41 ( V_299 , V_143 - V_30 -> V_129 ) ) {
F_196 ( V_2 ) ;
return - 1 ;
}
goto V_351;
}
if ( F_48 ( V_299 , V_30 -> V_96 ) )
goto V_352;
if ( V_6 -> V_304 == V_232 ||
V_6 -> V_304 == V_305 )
F_174 ( V_2 ) ;
if ( F_48 ( V_299 , V_143 ) )
V_163 |= V_289 ;
V_309 = V_30 -> V_117 ;
V_349 = F_108 ( V_30 ) ;
if ( V_163 & V_353 )
F_200 ( V_30 , F_16 ( V_4 ) -> V_80 ) ;
if ( ! ( V_163 & V_354 ) && F_48 ( V_299 , V_143 ) ) {
F_194 ( V_30 , V_136 ) ;
V_30 -> V_94 = V_299 ;
V_163 |= V_336 ;
F_118 ( V_2 , V_355 ) ;
F_60 ( F_61 ( V_2 ) , V_356 ) ;
} else {
if ( V_136 != F_16 ( V_4 ) -> V_82 )
V_163 |= V_357 ;
else
F_60 ( F_61 ( V_2 ) , V_358 ) ;
V_163 |= F_193 ( V_2 , V_4 , V_299 , V_136 ) ;
if ( F_16 ( V_4 ) -> V_124 )
V_163 |= F_103 ( V_2 , V_4 , V_143 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_163 |= V_229 ;
F_118 ( V_2 , V_359 ) ;
}
V_2 -> V_360 = 0 ;
V_6 -> V_361 = 0 ;
V_30 -> V_362 = V_69 ;
if ( ! V_350 )
goto V_363;
V_207 = V_30 -> V_197 ;
V_163 |= F_179 ( V_2 , V_309 , V_143 ) ;
V_207 -= V_30 -> V_197 ;
if ( F_189 ( V_2 , V_163 ) ) {
if ( ( V_163 & V_291 ) && F_190 ( V_2 , V_163 ) )
F_173 ( V_2 , V_299 , V_349 ) ;
V_287 = ! ( V_163 & ( V_289 | V_330 ) ) ;
F_168 ( V_2 , V_207 , V_271 ,
V_287 , V_163 ) ;
} else {
if ( V_163 & V_291 )
F_173 ( V_2 , V_299 , V_349 ) ;
}
if ( V_30 -> V_267 )
F_202 ( V_2 , V_299 , V_163 ) ;
if ( ( V_163 & V_364 ) || ! ( V_163 & V_330 ) ) {
struct V_97 * V_98 = F_204 ( V_2 ) ;
if ( V_98 )
F_205 ( V_98 ) ;
}
if ( V_6 -> V_304 == V_225 )
F_206 ( V_2 ) ;
return 1 ;
V_363:
if ( V_163 & V_198 )
F_168 ( V_2 , V_207 , V_271 ,
V_287 , V_163 ) ;
if ( F_72 ( V_2 ) )
F_187 ( V_2 ) ;
if ( V_30 -> V_267 )
F_202 ( V_2 , V_299 , V_163 ) ;
return 1 ;
V_352:
F_207 ( V_2 , L_12 , V_299 , V_30 -> V_94 , V_30 -> V_96 ) ;
return - 1 ;
V_351:
if ( F_16 ( V_4 ) -> V_124 ) {
V_163 |= F_103 ( V_2 , V_4 , V_143 ) ;
F_168 ( V_2 , V_207 , V_271 ,
V_287 , V_163 ) ;
}
F_207 ( V_2 , L_13 , V_299 , V_30 -> V_94 , V_30 -> V_96 ) ;
return 0 ;
}
void F_208 ( const struct V_3 * V_4 ,
struct V_365 * V_366 , int V_367 ,
struct V_368 * V_369 )
{
const unsigned char * V_188 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_370 = ( V_41 -> V_371 * 4 ) - sizeof( struct V_15 ) ;
V_188 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_366 -> V_245 = 0 ;
while ( V_370 > 0 ) {
int V_372 = * V_188 ++ ;
int V_373 ;
switch ( V_372 ) {
case V_374 :
return;
case V_375 :
V_370 -- ;
continue;
default:
V_373 = * V_188 ++ ;
if ( V_373 < 2 )
return;
if ( V_373 > V_370 )
return;
switch ( V_372 ) {
case V_376 :
if ( V_373 == V_377 && V_41 -> V_43 && ! V_367 ) {
T_7 V_378 = F_209 ( V_188 ) ;
if ( V_378 ) {
if ( V_366 -> V_379 &&
V_366 -> V_379 < V_378 )
V_378 = V_366 -> V_379 ;
V_366 -> V_46 = V_378 ;
}
}
break;
case V_380 :
if ( V_373 == V_381 && V_41 -> V_43 &&
! V_367 && V_382 ) {
T_8 V_335 = * ( T_8 * ) V_188 ;
V_366 -> V_383 = 1 ;
if ( V_335 > 14 ) {
F_210 ( L_14 ,
V_384 ,
V_335 ) ;
V_335 = 14 ;
}
V_366 -> V_335 = V_335 ;
}
break;
case V_385 :
if ( ( V_373 == V_386 ) &&
( ( V_367 && V_366 -> V_387 ) ||
( ! V_367 && V_388 ) ) ) {
V_366 -> V_245 = 1 ;
V_366 -> V_344 = F_74 ( V_188 ) ;
V_366 -> V_81 = F_74 ( V_188 + 4 ) ;
}
break;
case V_389 :
if ( V_373 == V_390 && V_41 -> V_43 &&
! V_367 && V_391 ) {
V_366 -> V_103 = V_392 ;
F_211 ( V_366 ) ;
}
break;
case V_393 :
if ( ( V_373 >= ( V_191 + V_394 ) ) &&
! ( ( V_373 - V_191 ) % V_394 ) &&
V_366 -> V_103 ) {
F_16 ( V_4 ) -> V_124 = ( V_188 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_212
case V_395 :
break;
#endif
case V_396 :
if ( V_373 < V_397 ||
F_209 ( V_188 ) != V_398 ||
V_369 == NULL || ! V_41 -> V_43 || ( V_373 & 1 ) )
break;
V_369 -> V_10 = V_373 - V_397 ;
if ( V_369 -> V_10 >= V_399 &&
V_369 -> V_10 <= V_400 )
memcpy ( V_369 -> V_401 , V_188 + 2 , V_369 -> V_10 ) ;
else if ( V_369 -> V_10 != 0 )
V_369 -> V_10 = - 1 ;
break;
}
V_188 += V_373 - 2 ;
V_370 -= V_373 ;
}
}
}
static bool F_213 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_188 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_188 == F_214 ( ( V_375 << 24 ) | ( V_375 << 16 )
| ( V_385 << 8 ) | V_386 ) ) {
V_30 -> V_45 . V_245 = 1 ;
++ V_188 ;
V_30 -> V_45 . V_344 = F_215 ( * V_188 ) ;
++ V_188 ;
if ( * V_188 )
V_30 -> V_45 . V_81 = F_215 ( * V_188 ) - V_30 -> V_402 ;
else
V_30 -> V_45 . V_81 = 0 ;
return true ;
}
return false ;
}
static bool F_216 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 , struct V_29 * V_30 )
{
if ( V_41 -> V_371 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_245 = 0 ;
return false ;
} else if ( V_30 -> V_45 . V_387 &&
V_41 -> V_371 == ( ( sizeof( * V_41 ) + V_403 ) / 4 ) ) {
if ( F_213 ( V_30 , V_41 ) )
return true ;
}
F_208 ( V_4 , & V_30 -> V_45 , 1 , NULL ) ;
if ( V_30 -> V_45 . V_245 && V_30 -> V_45 . V_81 )
V_30 -> V_45 . V_81 -= V_30 -> V_402 ;
return true ;
}
const T_3 * F_217 ( const struct V_15 * V_41 )
{
int V_370 = ( V_41 -> V_371 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_188 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_370 < V_404 )
return NULL ;
while ( V_370 > 0 ) {
int V_372 = * V_188 ++ ;
int V_373 ;
switch( V_372 ) {
case V_374 :
return NULL ;
case V_375 :
V_370 -- ;
continue;
default:
V_373 = * V_188 ++ ;
if ( V_373 < 2 || V_373 > V_370 )
return NULL ;
if ( V_372 == V_395 )
return V_373 == V_404 ? V_188 : NULL ;
}
V_188 += V_373 - 2 ;
V_370 -= V_373 ;
}
return NULL ;
}
static int F_218 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_80 = F_16 ( V_4 ) -> V_80 ;
T_1 V_299 = F_16 ( V_4 ) -> V_136 ;
return (
( V_41 -> V_299 && V_80 == F_16 ( V_4 ) -> V_82 && V_80 == V_30 -> V_79 ) &&
V_299 == V_30 -> V_94 &&
! F_192 ( V_30 , V_299 , V_80 , F_139 ( V_41 -> V_52 ) << V_30 -> V_45 . V_335 ) &&
( T_5 ) ( V_30 -> V_45 . V_343 - V_30 -> V_45 . V_344 ) <= ( F_2 ( V_2 ) -> V_88 * 1024 ) / V_340 ) ;
}
static inline bool F_219 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_201 ( & V_30 -> V_45 , V_405 ) &&
! F_218 ( V_2 , V_4 ) ;
}
static inline bool F_220 ( const struct V_29 * V_30 , T_1 V_80 , T_1 V_82 )
{
return ! F_41 ( V_82 , V_30 -> V_346 ) &&
! F_48 ( V_80 , V_30 -> V_79 + F_221 ( V_30 ) ) ;
}
void F_222 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_406 ) {
case V_407 :
V_2 -> V_408 = V_409 ;
break;
case V_410 :
V_2 -> V_408 = V_411 ;
break;
case V_412 :
return;
default:
V_2 -> V_408 = V_413 ;
}
F_223 () ;
if ( ! F_224 ( V_2 , V_414 ) )
V_2 -> V_415 ( V_2 ) ;
F_225 ( V_2 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_97 * V_98 ;
F_45 ( V_2 ) ;
V_2 -> V_416 |= V_417 ;
F_227 ( V_2 , V_418 ) ;
switch ( V_2 -> V_406 ) {
case V_419 :
case V_420 :
F_228 ( V_2 , V_410 ) ;
V_98 = F_204 ( V_2 ) ;
if ( ! V_98 || ! F_54 ( V_98 , V_421 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_410 :
case V_422 :
break;
case V_423 :
break;
case V_424 :
F_197 ( V_2 ) ;
F_228 ( V_2 , V_422 ) ;
break;
case V_425 :
F_197 ( V_2 ) ;
F_229 ( V_2 , V_426 , 0 ) ;
break;
default:
F_230 ( L_15 ,
V_384 , V_2 -> V_406 ) ;
break;
}
F_231 ( & V_30 -> V_427 ) ;
if ( F_131 ( V_30 ) )
F_211 ( & V_30 -> V_45 ) ;
F_46 ( V_2 ) ;
if ( ! F_224 ( V_2 , V_414 ) ) {
V_2 -> V_428 ( V_2 ) ;
if ( V_2 -> V_416 == V_429 ||
V_2 -> V_406 == V_412 )
F_232 ( V_2 , V_430 , V_431 ) ;
else
F_232 ( V_2 , V_430 , V_432 ) ;
}
}
static inline bool F_233 ( struct V_181 * V_141 , T_1 V_80 ,
T_1 V_82 )
{
if ( ! F_48 ( V_80 , V_141 -> V_82 ) && ! F_48 ( V_141 -> V_128 , V_82 ) ) {
if ( F_41 ( V_80 , V_141 -> V_128 ) )
V_141 -> V_128 = V_80 ;
if ( F_48 ( V_82 , V_141 -> V_82 ) )
V_141 -> V_82 = V_82 ;
return true ;
}
return false ;
}
static void F_234 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_82 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_131 ( V_30 ) && V_433 ) {
int V_109 ;
if ( F_41 ( V_80 , V_30 -> V_79 ) )
V_109 = V_434 ;
else
V_109 = V_435 ;
F_60 ( F_61 ( V_2 ) , V_109 ) ;
V_30 -> V_45 . V_436 = 1 ;
V_30 -> V_437 [ 0 ] . V_128 = V_80 ;
V_30 -> V_437 [ 0 ] . V_82 = V_82 ;
}
}
static void F_235 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_82 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_436 )
F_234 ( V_2 , V_80 , V_82 ) ;
else
F_233 ( V_30 -> V_437 , V_80 , V_82 ) ;
}
static void F_236 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_82 != F_16 ( V_4 ) -> V_80 &&
F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) ) {
F_60 ( F_61 ( V_2 ) , V_438 ) ;
F_10 ( V_2 ) ;
if ( F_131 ( V_30 ) && V_433 ) {
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
if ( F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_79 ) )
V_82 = V_30 -> V_79 ;
F_234 ( V_2 , F_16 ( V_4 ) -> V_80 , V_82 ) ;
}
}
F_197 ( V_2 ) ;
}
static void F_237 ( struct V_29 * V_30 )
{
int V_439 ;
struct V_181 * V_141 = & V_30 -> V_440 [ 0 ] ;
struct V_181 * V_441 = V_141 + 1 ;
for ( V_439 = 1 ; V_439 < V_30 -> V_45 . V_142 ; ) {
if ( F_233 ( V_141 , V_441 -> V_128 , V_441 -> V_82 ) ) {
int V_194 ;
V_30 -> V_45 . V_142 -- ;
for ( V_194 = V_439 ; V_194 < V_30 -> V_45 . V_142 ; V_194 ++ )
V_141 [ V_194 ] = V_141 [ V_194 + 1 ] ;
continue;
}
V_439 ++ , V_441 ++ ;
}
}
static void F_238 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_82 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_181 * V_141 = & V_30 -> V_440 [ 0 ] ;
int V_442 = V_30 -> V_45 . V_142 ;
int V_439 ;
if ( ! V_442 )
goto V_443;
for ( V_439 = 0 ; V_439 < V_442 ; V_439 ++ , V_141 ++ ) {
if ( F_233 ( V_141 , V_80 , V_82 ) ) {
for (; V_439 > 0 ; V_439 -- , V_141 -- )
F_106 ( * V_141 , * ( V_141 - 1 ) ) ;
if ( V_442 > 1 )
F_237 ( V_30 ) ;
return;
}
}
if ( V_439 >= V_190 ) {
V_439 -- ;
V_30 -> V_45 . V_142 -- ;
V_141 -- ;
}
for (; V_439 > 0 ; V_439 -- , V_141 -- )
* V_141 = * ( V_141 - 1 ) ;
V_443:
V_141 -> V_128 = V_80 ;
V_141 -> V_82 = V_82 ;
V_30 -> V_45 . V_142 ++ ;
}
static void F_239 ( struct V_29 * V_30 )
{
struct V_181 * V_141 = & V_30 -> V_440 [ 0 ] ;
int V_142 = V_30 -> V_45 . V_142 ;
int V_439 ;
if ( F_240 ( & V_30 -> V_427 ) ) {
V_30 -> V_45 . V_142 = 0 ;
return;
}
for ( V_439 = 0 ; V_439 < V_142 ; ) {
if ( ! F_41 ( V_30 -> V_79 , V_141 -> V_128 ) ) {
int V_194 ;
F_104 ( F_41 ( V_30 -> V_79 , V_141 -> V_82 ) ) ;
for ( V_194 = V_439 + 1 ; V_194 < V_142 ; V_194 ++ )
V_30 -> V_440 [ V_194 - 1 ] = V_30 -> V_440 [ V_194 ] ;
V_142 -- ;
continue;
}
V_439 ++ ;
V_141 ++ ;
}
V_30 -> V_45 . V_142 = V_142 ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_444 = V_30 -> V_79 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_242 ( & V_30 -> V_427 ) ) != NULL ) {
if ( F_48 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) )
break;
if ( F_41 ( F_16 ( V_4 ) -> V_80 , V_444 ) ) {
T_2 V_436 = V_444 ;
if ( F_41 ( F_16 ( V_4 ) -> V_82 , V_444 ) )
V_444 = F_16 ( V_4 ) -> V_82 ;
F_235 ( V_2 , F_16 ( V_4 ) -> V_80 , V_436 ) ;
}
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_79 ) ) {
F_207 ( V_2 , L_16 ) ;
F_243 ( V_4 , & V_30 -> V_427 ) ;
F_244 ( V_4 ) ;
continue;
}
F_207 ( V_2 , L_17 ,
V_30 -> V_79 , F_16 ( V_4 ) -> V_80 ,
F_16 ( V_4 ) -> V_82 ) ;
F_243 ( V_4 , & V_30 -> V_427 ) ;
F_245 ( & V_2 -> V_445 , V_4 ) ;
V_30 -> V_79 = F_16 ( V_4 ) -> V_82 ;
if ( F_6 ( V_4 ) -> V_446 )
F_226 ( V_2 ) ;
}
}
static int F_246 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_447 )
{
if ( F_36 ( & V_2 -> V_70 ) > V_2 -> V_60 ||
! F_247 ( V_2 , V_4 , V_447 ) ) {
if ( F_248 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_247 ( V_2 , V_4 , V_447 ) ) {
if ( ! F_249 ( V_2 ) )
return - 1 ;
if ( ! F_247 ( V_2 , V_4 , V_447 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_250 ( struct V_1 * V_2 ,
struct V_3 * V_448 ,
struct V_3 * V_449 ,
bool * V_450 )
{
int V_273 ;
* V_450 = false ;
if ( F_6 ( V_449 ) -> V_446 )
return false ;
if ( F_16 ( V_449 ) -> V_80 != F_16 ( V_448 ) -> V_82 )
return false ;
if ( ! F_251 ( V_448 , V_449 , V_450 , & V_273 ) )
return false ;
F_252 ( V_273 , & V_2 -> V_70 ) ;
F_253 ( V_2 , V_273 ) ;
F_60 ( F_61 ( V_2 ) , V_451 ) ;
F_16 ( V_448 ) -> V_82 = F_16 ( V_449 ) -> V_82 ;
F_16 ( V_448 ) -> V_136 = F_16 ( V_449 ) -> V_136 ;
return true ;
}
static void F_254 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_452 ;
T_1 V_80 , V_82 ;
F_15 ( V_30 , V_4 ) ;
if ( F_92 ( F_246 ( V_2 , V_4 , V_4 -> V_51 ) ) ) {
F_60 ( F_61 ( V_2 ) , V_453 ) ;
F_244 ( V_4 ) ;
return;
}
V_30 -> V_337 = 0 ;
F_45 ( V_2 ) ;
F_60 ( F_61 ( V_2 ) , V_454 ) ;
F_207 ( V_2 , L_18 ,
V_30 -> V_79 , F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ;
V_452 = F_255 ( & V_30 -> V_427 ) ;
if ( ! V_452 ) {
if ( F_131 ( V_30 ) ) {
V_30 -> V_45 . V_142 = 1 ;
V_30 -> V_440 [ 0 ] . V_128 = F_16 ( V_4 ) -> V_80 ;
V_30 -> V_440 [ 0 ] . V_82 =
F_16 ( V_4 ) -> V_82 ;
}
F_256 ( & V_30 -> V_427 , V_4 ) ;
goto V_455;
}
V_80 = F_16 ( V_4 ) -> V_80 ;
V_82 = F_16 ( V_4 ) -> V_82 ;
if ( V_80 == F_16 ( V_452 ) -> V_82 ) {
bool V_450 ;
if ( ! F_250 ( V_2 , V_452 , V_4 , & V_450 ) ) {
F_257 ( & V_30 -> V_427 , V_452 , V_4 ) ;
} else {
F_258 ( V_4 , V_450 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_45 . V_142 ||
V_30 -> V_440 [ 0 ] . V_82 != V_80 )
goto V_456;
V_30 -> V_440 [ 0 ] . V_82 = V_82 ;
goto V_455;
}
while ( 1 ) {
if ( ! F_48 ( F_16 ( V_452 ) -> V_80 , V_80 ) )
break;
if ( F_259 ( & V_30 -> V_427 , V_452 ) ) {
V_452 = NULL ;
break;
}
V_452 = F_260 ( & V_30 -> V_427 , V_452 ) ;
}
if ( V_452 && F_41 ( V_80 , F_16 ( V_452 ) -> V_82 ) ) {
if ( ! F_48 ( V_82 , F_16 ( V_452 ) -> V_82 ) ) {
F_60 ( F_61 ( V_2 ) , V_457 ) ;
F_244 ( V_4 ) ;
V_4 = NULL ;
F_234 ( V_2 , V_80 , V_82 ) ;
goto V_456;
}
if ( F_48 ( V_80 , F_16 ( V_452 ) -> V_80 ) ) {
F_234 ( V_2 , V_80 ,
F_16 ( V_452 ) -> V_82 ) ;
} else {
if ( F_259 ( & V_30 -> V_427 ,
V_452 ) )
V_452 = NULL ;
else
V_452 = F_260 (
& V_30 -> V_427 ,
V_452 ) ;
}
}
if ( ! V_452 )
F_256 ( & V_30 -> V_427 , V_4 ) ;
else
F_257 ( & V_30 -> V_427 , V_452 , V_4 ) ;
while ( ! F_261 ( & V_30 -> V_427 , V_4 ) ) {
V_452 = F_262 ( & V_30 -> V_427 , V_4 ) ;
if ( ! F_48 ( V_82 , F_16 ( V_452 ) -> V_80 ) )
break;
if ( F_41 ( V_82 , F_16 ( V_452 ) -> V_82 ) ) {
F_235 ( V_2 , F_16 ( V_452 ) -> V_80 ,
V_82 ) ;
break;
}
F_243 ( V_452 , & V_30 -> V_427 ) ;
F_235 ( V_2 , F_16 ( V_452 ) -> V_80 ,
F_16 ( V_452 ) -> V_82 ) ;
F_60 ( F_61 ( V_2 ) , V_457 ) ;
F_244 ( V_452 ) ;
}
V_456:
if ( F_131 ( V_30 ) )
F_238 ( V_2 , V_80 , V_82 ) ;
V_455:
if ( V_4 )
F_263 ( V_4 , V_2 ) ;
}
static int T_10 F_264 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_458 ,
bool * V_450 )
{
int V_459 ;
struct V_3 * V_460 = F_255 ( & V_2 -> V_445 ) ;
F_265 ( V_4 , V_458 ) ;
V_459 = ( V_460 &&
F_250 ( V_2 , V_460 , V_4 , V_450 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_79 = F_16 ( V_4 ) -> V_82 ;
if ( ! V_459 ) {
F_245 ( & V_2 -> V_445 , V_4 ) ;
F_263 ( V_4 , V_2 ) ;
}
return V_459 ;
}
int F_266 ( struct V_1 * V_2 , struct V_461 * V_246 , T_11 V_447 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_450 ;
if ( V_447 == 0 )
return 0 ;
V_4 = F_267 ( V_447 + sizeof( * V_41 ) , V_2 -> V_462 ) ;
if ( ! V_4 )
goto V_151;
if ( F_246 ( V_2 , V_4 , V_447 + sizeof( * V_41 ) ) )
goto V_463;
V_41 = (struct V_15 * ) F_268 ( V_4 , sizeof( * V_41 ) ) ;
F_269 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_270 ( F_268 ( V_4 , V_447 ) , V_246 -> V_464 , V_447 ) )
goto V_463;
F_16 ( V_4 ) -> V_80 = F_7 ( V_2 ) -> V_79 ;
F_16 ( V_4 ) -> V_82 = F_16 ( V_4 ) -> V_80 + V_447 ;
F_16 ( V_4 ) -> V_136 = F_7 ( V_2 ) -> V_94 - 1 ;
if ( F_264 ( V_2 , V_4 , sizeof( * V_41 ) , & V_450 ) ) {
F_271 ( V_450 ) ;
F_244 ( V_4 ) ;
}
return V_447 ;
V_463:
F_272 ( V_4 ) ;
V_151:
return - V_465 ;
}
static void F_273 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_459 = - 1 ;
bool V_450 = false ;
if ( F_16 ( V_4 ) -> V_80 == F_16 ( V_4 ) -> V_82 )
goto V_466;
F_274 ( V_4 ) ;
F_265 ( V_4 , V_41 -> V_371 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_436 = 0 ;
if ( F_16 ( V_4 ) -> V_80 == V_30 -> V_79 ) {
if ( F_221 ( V_30 ) == 0 )
goto V_467;
if ( V_30 -> V_468 . V_469 == V_470 &&
V_30 -> V_83 == V_30 -> V_79 && V_30 -> V_468 . V_10 &&
F_275 ( V_2 ) && ! V_30 -> V_471 ) {
int V_472 = F_38 (unsigned int, skb->len,
tp->ucopy.len) ;
F_276 ( V_473 ) ;
F_277 () ;
if ( ! F_278 ( V_4 , 0 , V_30 -> V_468 . V_474 , V_472 ) ) {
V_30 -> V_468 . V_10 -= V_472 ;
V_30 -> V_83 += V_472 ;
V_459 = ( V_472 == V_4 -> V_10 ) ;
F_43 ( V_2 ) ;
}
F_279 () ;
}
if ( V_459 <= 0 ) {
V_475:
if ( V_459 < 0 &&
F_246 ( V_2 , V_4 , V_4 -> V_51 ) )
goto V_466;
V_459 = F_264 ( V_2 , V_4 , 0 , & V_450 ) ;
}
V_30 -> V_79 = F_16 ( V_4 ) -> V_82 ;
if ( V_4 -> V_10 )
F_44 ( V_2 , V_4 ) ;
if ( V_41 -> V_446 )
F_226 ( V_2 ) ;
if ( ! F_240 ( & V_30 -> V_427 ) ) {
F_241 ( V_2 ) ;
if ( F_240 ( & V_30 -> V_427 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_142 )
F_239 ( V_30 ) ;
F_195 ( V_2 ) ;
if ( V_459 > 0 )
F_258 ( V_4 , V_450 ) ;
if ( ! F_224 ( V_2 , V_414 ) )
V_2 -> V_476 ( V_2 , 0 ) ;
return;
}
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_79 ) ) {
F_60 ( F_61 ( V_2 ) , V_438 ) ;
F_234 ( V_2 , F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ;
V_467:
F_10 ( V_2 ) ;
F_45 ( V_2 ) ;
V_466:
F_244 ( V_4 ) ;
return;
}
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 + F_221 ( V_30 ) ) )
goto V_467;
F_10 ( V_2 ) ;
if ( F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) ) {
F_207 ( V_2 , L_19 ,
V_30 -> V_79 , F_16 ( V_4 ) -> V_80 ,
F_16 ( V_4 ) -> V_82 ) ;
F_234 ( V_2 , F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) ;
if ( ! F_221 ( V_30 ) )
goto V_467;
goto V_475;
}
F_254 ( V_2 , V_4 ) ;
}
static struct V_3 * F_280 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_477 * V_478 )
{
struct V_3 * V_479 = NULL ;
if ( ! F_261 ( V_478 , V_4 ) )
V_479 = F_262 ( V_478 , V_4 ) ;
F_243 ( V_4 , V_478 ) ;
F_244 ( V_4 ) ;
F_60 ( F_61 ( V_2 ) , V_480 ) ;
return V_479 ;
}
static void
F_281 ( struct V_1 * V_2 , struct V_477 * V_478 ,
struct V_3 * V_481 , struct V_3 * V_460 ,
T_1 V_482 , T_1 V_455 )
{
struct V_3 * V_4 , * V_483 ;
bool V_484 ;
V_4 = V_481 ;
V_485:
V_484 = true ;
F_282 (list, skb, n) {
if ( V_4 == V_460 )
break;
if ( ! F_41 ( V_482 , F_16 ( V_4 ) -> V_82 ) ) {
V_4 = F_280 ( V_2 , V_4 , V_478 ) ;
if ( ! V_4 )
break;
goto V_485;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_446 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_41 ( F_16 ( V_4 ) -> V_80 , V_482 ) ) ) {
V_484 = false ;
break;
}
if ( ! F_261 ( V_478 , V_4 ) ) {
struct V_3 * V_479 = F_262 ( V_478 , V_4 ) ;
if ( V_479 != V_460 &&
F_16 ( V_4 ) -> V_82 != F_16 ( V_479 ) -> V_80 ) {
V_484 = false ;
break;
}
}
V_482 = F_16 ( V_4 ) -> V_82 ;
}
if ( V_484 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_446 )
return;
while ( F_41 ( V_482 , V_455 ) ) {
struct V_3 * V_486 ;
unsigned int V_487 = F_283 ( V_4 ) ;
int V_488 = F_284 ( V_487 , 0 ) ;
if ( V_488 < 0 )
return;
if ( V_455 - V_482 < V_488 )
V_488 = V_455 - V_482 ;
V_486 = F_267 ( V_488 + V_487 , V_489 ) ;
if ( ! V_486 )
return;
F_285 ( V_486 , F_286 ( V_4 ) - V_4 -> V_481 ) ;
F_287 ( V_486 , ( F_288 ( V_4 ) -
V_4 -> V_481 ) ) ;
F_289 ( V_486 , ( F_4 ( V_4 ) -
V_4 -> V_481 ) ) ;
F_290 ( V_486 , V_487 ) ;
memcpy ( V_486 -> V_481 , V_4 -> V_481 , V_487 ) ;
memcpy ( V_486 -> V_490 , V_4 -> V_490 , sizeof( V_4 -> V_490 ) ) ;
F_16 ( V_486 ) -> V_80 = F_16 ( V_486 ) -> V_82 = V_482 ;
F_291 ( V_478 , V_4 , V_486 ) ;
F_263 ( V_486 , V_2 ) ;
while ( V_488 > 0 ) {
int V_491 = V_482 - F_16 ( V_4 ) -> V_80 ;
int V_447 = F_16 ( V_4 ) -> V_82 - V_482 ;
F_81 ( V_491 < 0 ) ;
if ( V_447 > 0 ) {
V_447 = F_9 ( V_488 , V_447 ) ;
if ( F_292 ( V_4 , V_491 , F_268 ( V_486 , V_447 ) , V_447 ) )
F_293 () ;
F_16 ( V_486 ) -> V_82 += V_447 ;
V_488 -= V_447 ;
V_482 += V_447 ;
}
if ( ! F_41 ( V_482 , F_16 ( V_4 ) -> V_82 ) ) {
V_4 = F_280 ( V_2 , V_4 , V_478 ) ;
if ( ! V_4 ||
V_4 == V_460 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_446 )
return;
}
}
}
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_242 ( & V_30 -> V_427 ) ;
struct V_3 * V_481 ;
T_1 V_482 , V_455 ;
if ( V_4 == NULL )
return;
V_482 = F_16 ( V_4 ) -> V_80 ;
V_455 = F_16 ( V_4 ) -> V_82 ;
V_481 = V_4 ;
for (; ; ) {
struct V_3 * V_479 = NULL ;
if ( ! F_261 ( & V_30 -> V_427 , V_4 ) )
V_479 = F_262 ( & V_30 -> V_427 , V_4 ) ;
V_4 = V_479 ;
if ( ! V_4 ||
F_48 ( F_16 ( V_4 ) -> V_80 , V_455 ) ||
F_41 ( F_16 ( V_4 ) -> V_82 , V_482 ) ) {
F_281 ( V_2 , & V_30 -> V_427 ,
V_481 , V_4 , V_482 , V_455 ) ;
V_481 = V_4 ;
if ( ! V_4 )
break;
V_482 = F_16 ( V_4 ) -> V_80 ;
V_455 = F_16 ( V_4 ) -> V_82 ;
} else {
if ( F_41 ( F_16 ( V_4 ) -> V_80 , V_482 ) )
V_482 = F_16 ( V_4 ) -> V_80 ;
if ( F_48 ( F_16 ( V_4 ) -> V_82 , V_455 ) )
V_455 = F_16 ( V_4 ) -> V_82 ;
}
}
}
static bool F_249 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_492 = false ;
if ( ! F_240 ( & V_30 -> V_427 ) ) {
F_60 ( F_61 ( V_2 ) , V_493 ) ;
F_231 ( & V_30 -> V_427 ) ;
if ( V_30 -> V_45 . V_103 )
F_211 ( & V_30 -> V_45 ) ;
F_46 ( V_2 ) ;
V_492 = true ;
}
return V_492 ;
}
static int F_248 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_207 ( V_2 , L_20 , V_30 -> V_83 ) ;
F_60 ( F_61 ( V_2 ) , V_494 ) ;
if ( F_36 ( & V_2 -> V_70 ) >= V_2 -> V_60 )
F_33 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_294 ( V_2 ) ;
if ( ! F_240 ( & V_2 -> V_445 ) )
F_281 ( V_2 , & V_2 -> V_445 ,
F_242 ( & V_2 -> V_445 ) ,
NULL ,
V_30 -> V_83 , V_30 -> V_79 ) ;
F_46 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_70 ) <= V_2 -> V_60 )
return 0 ;
F_249 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_70 ) <= V_2 -> V_60 )
return 0 ;
F_60 ( F_61 ( V_2 ) , V_495 ) ;
V_30 -> V_337 = 0 ;
return - 1 ;
}
void F_295 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_116 == V_262 &&
V_2 -> V_496 && ! F_296 ( V_497 , & V_2 -> V_496 -> V_327 ) ) {
T_1 V_498 = F_53 ( V_30 , F_204 ( V_2 ) ) ;
T_1 V_499 = F_32 ( V_30 -> V_500 , V_498 ) ;
if ( V_499 < V_30 -> V_217 ) {
V_30 -> V_213 = F_117 ( V_2 ) ;
V_30 -> V_217 = ( V_30 -> V_217 + V_499 ) >> 1 ;
}
V_30 -> V_500 = 0 ;
}
V_30 -> V_68 = V_69 ;
}
static bool F_297 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_62 & V_64 )
return false ;
if ( F_26 ( V_2 ) )
return false ;
if ( F_34 ( V_2 ) >= F_35 ( V_2 , 0 ) )
return false ;
if ( V_30 -> V_197 >= V_30 -> V_217 )
return false ;
return true ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_297 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_280 ) +
V_47 ) ;
int V_501 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_501 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_68 = V_69 ;
}
V_2 -> V_502 ( V_2 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
if ( F_224 ( V_2 , V_503 ) ) {
F_300 ( V_2 , V_503 ) ;
if ( V_2 -> V_496 &&
F_296 ( V_497 , & V_2 -> V_496 -> V_327 ) )
F_298 ( V_2 ) ;
}
}
static inline void F_301 ( struct V_1 * V_2 )
{
F_302 ( V_2 ) ;
F_299 ( V_2 ) ;
}
static void F_303 ( struct V_1 * V_2 , int V_504 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_79 - V_30 -> V_346 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_304 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_504 && F_242 ( & V_30 -> V_427 ) ) ) {
F_197 ( V_2 ) ;
} else {
F_305 ( V_2 ) ;
}
}
static inline void F_306 ( struct V_1 * V_2 )
{
if ( ! F_307 ( V_2 ) ) {
return;
}
F_303 ( V_2 , 1 ) ;
}
static void F_308 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_188 = F_139 ( V_41 -> V_505 ) ;
if ( V_188 && ! V_506 )
V_188 -- ;
V_188 += F_215 ( V_41 -> V_80 ) ;
if ( F_48 ( V_30 -> V_83 , V_188 ) )
return;
if ( F_41 ( V_188 , V_30 -> V_79 ) )
return;
if ( V_30 -> V_471 && ! F_48 ( V_188 , V_30 -> V_507 ) )
return;
F_309 ( V_2 ) ;
if ( V_30 -> V_507 == V_30 -> V_83 && V_30 -> V_471 &&
! F_224 ( V_2 , V_508 ) && V_30 -> V_83 != V_30 -> V_79 ) {
struct V_3 * V_4 = F_242 ( & V_2 -> V_445 ) ;
V_30 -> V_83 ++ ;
if ( V_4 && ! F_41 ( V_30 -> V_83 , F_16 ( V_4 ) -> V_82 ) ) {
F_243 ( V_4 , & V_2 -> V_445 ) ;
F_244 ( V_4 ) ;
}
}
V_30 -> V_471 = V_509 ;
V_30 -> V_507 = V_188 ;
V_30 -> V_337 = 0 ;
}
static void F_310 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_510 )
F_308 ( V_2 , V_41 ) ;
if ( V_30 -> V_471 == V_509 ) {
T_1 V_188 = V_30 -> V_507 - F_215 ( V_41 -> V_80 ) + ( V_41 -> V_371 * 4 ) -
V_41 -> V_43 ;
if ( V_188 < V_4 -> V_10 ) {
T_3 V_184 ;
if ( F_292 ( V_4 , V_188 , & V_184 , 1 ) )
F_293 () ;
V_30 -> V_471 = V_511 | V_184 ;
if ( ! F_224 ( V_2 , V_414 ) )
V_2 -> V_476 ( V_2 , 0 ) ;
}
}
}
static int F_311 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_512 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_472 = V_4 -> V_10 - V_512 ;
int V_151 ;
F_277 () ;
if ( F_312 ( V_4 ) )
V_151 = F_278 ( V_4 , V_512 , V_30 -> V_468 . V_474 , V_472 ) ;
else
V_151 = F_313 ( V_4 , V_512 ,
V_30 -> V_468 . V_474 ) ;
if ( ! V_151 ) {
V_30 -> V_468 . V_10 -= V_472 ;
V_30 -> V_83 += V_472 ;
F_43 ( V_2 ) ;
}
F_279 () ;
return V_151 ;
}
static T_12 F_314 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_12 V_513 ;
if ( F_275 ( V_2 ) ) {
F_277 () ;
V_513 = F_315 ( V_4 ) ;
F_279 () ;
} else {
V_513 = F_315 ( V_4 ) ;
}
return V_513 ;
}
static inline bool F_316 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_312 ( V_4 ) &&
F_314 ( V_2 , V_4 ) ;
}
static bool F_317 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_512 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_472 = V_4 -> V_10 - V_512 ;
int V_514 ;
bool V_515 = false ;
if ( V_30 -> V_468 . V_516 )
return false ;
if ( ! V_30 -> V_468 . V_517 && V_30 -> V_468 . V_518 )
V_30 -> V_468 . V_517 = F_318 () ;
if ( V_30 -> V_468 . V_517 && F_312 ( V_4 ) ) {
V_514 = F_319 ( V_30 -> V_468 . V_517 ,
V_4 , V_512 ,
V_30 -> V_468 . V_474 , V_472 ,
V_30 -> V_468 . V_518 ) ;
if ( V_514 < 0 )
goto V_179;
V_30 -> V_468 . V_514 = V_514 ;
V_515 = true ;
V_30 -> V_468 . V_10 -= V_472 ;
V_30 -> V_83 += V_472 ;
F_43 ( V_2 ) ;
if ( ( V_30 -> V_468 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_519 ) ||
( F_36 ( & V_2 -> V_70 ) > ( V_2 -> V_60 >> 1 ) ) ) {
V_30 -> V_468 . V_516 = 1 ;
V_2 -> V_476 ( V_2 , 0 ) ;
}
} else if ( V_472 > 0 ) {
V_30 -> V_468 . V_516 = 1 ;
V_2 -> V_476 ( V_2 , 0 ) ;
}
V_179:
return V_515 ;
}
static bool F_320 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_520 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_216 ( V_4 , V_41 , V_30 ) && V_30 -> V_45 . V_245 &&
F_219 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_521 ) {
F_60 ( F_61 ( V_2 ) , V_522 ) ;
F_236 ( V_2 , V_4 ) ;
goto V_523;
}
}
if ( ! F_220 ( V_30 , F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ) {
if ( ! V_41 -> V_521 ) {
if ( V_41 -> V_43 )
goto V_524;
F_236 ( V_2 , V_4 ) ;
}
goto V_523;
}
if ( V_41 -> V_521 ) {
if ( F_16 ( V_4 ) -> V_80 == V_30 -> V_79 )
F_222 ( V_2 ) ;
else
F_196 ( V_2 ) ;
goto V_523;
}
if ( V_41 -> V_43 ) {
V_524:
if ( V_520 )
F_321 ( F_61 ( V_2 ) , V_525 ) ;
F_60 ( F_61 ( V_2 ) , V_526 ) ;
F_196 ( V_2 ) ;
goto V_523;
}
return true ;
V_523:
F_244 ( V_4 ) ;
return false ;
}
int F_322 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_92 ( V_2 -> V_527 == NULL ) )
F_2 ( V_2 ) -> V_528 -> V_529 ( V_2 , V_4 ) ;
V_30 -> V_45 . V_245 = 0 ;
if ( ( F_5 ( V_41 ) & V_530 ) == V_30 -> V_337 &&
F_16 ( V_4 ) -> V_80 == V_30 -> V_79 &&
! F_48 ( F_16 ( V_4 ) -> V_136 , V_30 -> V_96 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_403 ) {
if ( ! F_213 ( V_30 , V_41 ) )
goto V_531;
if ( ( T_5 ) ( V_30 -> V_45 . V_344 - V_30 -> V_45 . V_343 ) < 0 )
goto V_531;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_403 ) &&
V_30 -> V_79 == V_30 -> V_346 )
F_198 ( V_30 ) ;
F_203 ( V_2 , V_4 , 0 ) ;
F_244 ( V_4 ) ;
F_301 ( V_2 ) ;
return 0 ;
} else {
F_321 ( F_61 ( V_2 ) , V_525 ) ;
goto V_523;
}
} else {
int V_459 = 0 ;
int V_515 = 0 ;
bool V_450 = false ;
if ( V_30 -> V_83 == V_30 -> V_79 &&
V_10 - V_18 <= V_30 -> V_468 . V_10 ) {
#ifdef F_323
if ( V_30 -> V_468 . V_469 == V_470 &&
F_275 ( V_2 ) &&
F_317 ( V_2 , V_4 , V_18 ) ) {
V_515 = 1 ;
V_459 = 1 ;
}
#endif
if ( V_30 -> V_468 . V_469 == V_470 &&
F_275 ( V_2 ) && ! V_515 ) {
F_276 ( V_473 ) ;
if ( ! F_311 ( V_2 , V_4 , V_18 ) )
V_459 = 1 ;
}
if ( V_459 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_403 ) &&
V_30 -> V_79 == V_30 -> V_346 )
F_198 ( V_30 ) ;
F_42 ( V_2 , V_4 ) ;
F_265 ( V_4 , V_18 ) ;
V_30 -> V_79 = F_16 ( V_4 ) -> V_82 ;
F_60 ( F_61 ( V_2 ) , V_532 ) ;
}
if ( V_515 )
F_324 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_459 ) {
if ( F_316 ( V_2 , V_4 ) )
goto V_533;
if ( ( int ) V_4 -> V_51 > V_2 -> V_534 )
goto V_535;
if ( V_18 ==
( sizeof( struct V_15 ) + V_403 ) &&
V_30 -> V_79 == V_30 -> V_346 )
F_198 ( V_30 ) ;
F_42 ( V_2 , V_4 ) ;
F_60 ( F_61 ( V_2 ) , V_536 ) ;
V_459 = F_264 ( V_2 , V_4 , V_18 ,
& V_450 ) ;
}
F_44 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_136 != V_30 -> V_94 ) {
F_203 ( V_2 , V_4 , V_357 ) ;
F_301 ( V_2 ) ;
if ( ! F_307 ( V_2 ) )
goto V_537;
}
if ( ! V_515 || V_30 -> V_79 != V_30 -> V_346 )
F_303 ( V_2 , 0 ) ;
V_537:
#ifdef F_323
if ( V_515 )
F_245 ( & V_2 -> V_538 , V_4 ) ;
else
#endif
if ( V_459 )
F_258 ( V_4 , V_450 ) ;
V_2 -> V_476 ( V_2 , 0 ) ;
return 0 ;
}
}
V_531:
if ( V_10 < ( V_41 -> V_371 << 2 ) || F_316 ( V_2 , V_4 ) )
goto V_533;
if ( ! V_41 -> V_299 && ! V_41 -> V_521 )
goto V_523;
if ( ! F_320 ( V_2 , V_4 , V_41 , 1 ) )
return 0 ;
V_535:
if ( F_203 ( V_2 , V_4 , V_354 | V_353 ) < 0 )
goto V_523;
F_42 ( V_2 , V_4 ) ;
F_310 ( V_2 , V_4 , V_41 ) ;
F_273 ( V_2 , V_4 ) ;
F_301 ( V_2 ) ;
F_306 ( V_2 ) ;
return 0 ;
V_533:
F_321 ( F_61 ( V_2 ) , V_539 ) ;
F_321 ( F_61 ( V_2 ) , V_525 ) ;
V_523:
F_244 ( V_4 ) ;
return 0 ;
}
void F_325 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_228 ( V_2 , V_420 ) ;
if ( V_4 != NULL ) {
V_6 -> V_528 -> V_529 ( V_2 , V_4 ) ;
F_326 ( V_2 , V_4 ) ;
}
V_6 -> V_528 -> V_540 ( V_2 ) ;
F_327 ( V_2 ) ;
F_328 ( V_2 ) ;
V_30 -> V_541 = V_69 ;
F_30 ( V_2 ) ;
if ( F_224 ( V_2 , V_542 ) )
F_329 ( V_2 , F_330 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_335 )
F_331 ( V_30 , V_30 -> V_334 ) ;
else
V_30 -> V_337 = 0 ;
if ( ! F_224 ( V_2 , V_414 ) ) {
V_2 -> V_428 ( V_2 ) ;
F_232 ( V_2 , V_543 , V_544 ) ;
}
}
static bool F_332 ( struct V_1 * V_2 , struct V_3 * V_545 ,
struct V_368 * V_546 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_547 ? F_93 ( V_2 ) : NULL ;
T_7 V_58 = V_30 -> V_45 . V_46 ;
bool V_548 ;
if ( V_58 == V_30 -> V_45 . V_379 ) {
struct V_365 V_549 ;
F_333 ( & V_549 ) ;
V_549 . V_379 = V_549 . V_46 = 0 ;
F_208 ( V_545 , & V_549 , 0 , NULL ) ;
V_58 = V_549 . V_46 ;
}
if ( ! V_30 -> V_550 )
V_546 -> V_10 = - 1 ;
V_548 = ( V_546 -> V_10 <= 0 && V_13 && V_30 -> V_551 ) ;
F_334 ( V_2 , V_58 , V_546 , V_548 ) ;
if ( V_13 ) {
F_98 (data, sk) {
if ( V_13 == F_72 ( V_2 ) ||
F_335 ( V_2 , V_13 ) )
break;
}
F_174 ( V_2 ) ;
return true ;
}
V_30 -> V_552 = V_30 -> V_547 ;
return false ;
}
static int F_336 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_368 V_369 = { . V_10 = - 1 } ;
int V_553 = V_30 -> V_45 . V_46 ;
F_208 ( V_4 , & V_30 -> V_45 , 0 , & V_369 ) ;
if ( V_30 -> V_45 . V_245 && V_30 -> V_45 . V_81 )
V_30 -> V_45 . V_81 -= V_30 -> V_402 ;
if ( V_41 -> V_299 ) {
if ( ! F_48 ( F_16 ( V_4 ) -> V_136 , V_30 -> V_94 ) ||
F_48 ( F_16 ( V_4 ) -> V_136 , V_30 -> V_96 ) )
goto V_554;
if ( V_30 -> V_45 . V_245 && V_30 -> V_45 . V_81 &&
! F_182 ( V_30 -> V_45 . V_81 , V_30 -> V_244 ,
V_69 ) ) {
F_60 ( F_61 ( V_2 ) , V_555 ) ;
goto V_554;
}
if ( V_41 -> V_521 ) {
F_222 ( V_2 ) ;
goto V_523;
}
if ( ! V_41 -> V_43 )
goto V_556;
F_17 ( V_30 , V_41 ) ;
F_337 ( V_30 , F_16 ( V_4 ) -> V_80 ) ;
F_203 ( V_2 , V_4 , V_354 ) ;
V_30 -> V_79 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_346 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_334 = F_139 ( V_41 -> V_52 ) ;
if ( ! V_30 -> V_45 . V_383 ) {
V_30 -> V_45 . V_335 = V_30 -> V_45 . V_557 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_245 ) {
V_30 -> V_45 . V_387 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_403 ;
V_30 -> V_57 -= V_403 ;
F_198 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_131 ( V_30 ) && V_558 )
F_338 ( V_30 ) ;
F_339 ( V_2 ) ;
F_159 ( V_2 , V_6 -> V_282 ) ;
F_37 ( V_2 ) ;
V_30 -> V_83 = V_30 -> V_79 ;
F_340 () ;
F_325 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_550 || V_30 -> V_547 ) &&
F_332 ( V_2 , V_4 , & V_369 ) )
return - 1 ;
if ( V_2 -> V_559 ||
V_6 -> V_560 . V_561 ||
V_6 -> V_8 . V_26 ) {
F_45 ( V_2 ) ;
V_6 -> V_8 . V_87 = V_69 ;
F_10 ( V_2 ) ;
F_123 ( V_2 , V_562 ,
V_563 , V_226 ) ;
V_523:
F_244 ( V_4 ) ;
return 0 ;
} else {
F_197 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_521 ) {
goto V_556;
}
if ( V_30 -> V_45 . V_345 && V_30 -> V_45 . V_245 &&
F_341 ( & V_30 -> V_45 , 0 ) )
goto V_556;
if ( V_41 -> V_43 ) {
F_228 ( V_2 , V_419 ) ;
if ( V_30 -> V_45 . V_245 ) {
V_30 -> V_45 . V_387 = 1 ;
F_198 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_403 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_79 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_346 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_334 = F_139 ( V_41 -> V_52 ) ;
V_30 -> V_333 = F_16 ( V_4 ) -> V_80 ;
V_30 -> V_129 = V_30 -> V_334 ;
F_18 ( V_30 , V_41 ) ;
F_339 ( V_2 ) ;
F_159 ( V_2 , V_6 -> V_282 ) ;
F_37 ( V_2 ) ;
F_342 ( V_2 ) ;
#if 0
return -1;
#else
goto V_523;
#endif
}
V_556:
F_333 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_553 ;
goto V_523;
V_554:
F_333 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_553 ;
return 1 ;
}
int F_343 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_564 * V_565 ;
int V_566 = 0 ;
bool V_567 ;
V_30 -> V_45 . V_245 = 0 ;
switch ( V_2 -> V_406 ) {
case V_412 :
goto V_523;
case V_568 :
if ( V_41 -> V_299 )
return 1 ;
if ( V_41 -> V_521 )
goto V_523;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_446 )
goto V_523;
if ( V_6 -> V_528 -> V_569 ( V_2 , V_4 ) < 0 )
return 1 ;
F_272 ( V_4 ) ;
return 0 ;
}
goto V_523;
case V_407 :
V_566 = F_336 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_566 >= 0 )
return V_566 ;
F_310 ( V_2 , V_4 , V_41 ) ;
F_244 ( V_4 ) ;
F_301 ( V_2 ) ;
return 0 ;
}
V_565 = V_30 -> V_302 ;
if ( V_565 != NULL ) {
F_271 ( V_2 -> V_406 != V_419 &&
V_2 -> V_406 != V_424 ) ;
if ( F_344 ( V_2 , V_4 , V_565 , NULL , true ) == NULL )
goto V_523;
}
if ( ! V_41 -> V_299 && ! V_41 -> V_521 )
goto V_523;
if ( ! F_320 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
V_567 = F_203 ( V_2 , V_4 , V_354 |
V_353 ) > 0 ;
switch ( V_2 -> V_406 ) {
case V_419 :
if ( ! V_567 )
return 1 ;
if ( V_565 ) {
F_345 ( V_2 , V_565 ) ;
V_30 -> V_551 = V_565 -> V_570 ;
F_346 ( V_2 , V_565 , false ) ;
} else {
V_6 -> V_528 -> V_540 ( V_2 ) ;
F_328 ( V_2 ) ;
F_339 ( V_2 ) ;
F_30 ( V_2 ) ;
V_30 -> V_83 = V_30 -> V_79 ;
}
F_340 () ;
F_228 ( V_2 , V_420 ) ;
V_2 -> V_428 ( V_2 ) ;
if ( V_2 -> V_496 )
F_232 ( V_2 , V_543 , V_544 ) ;
V_30 -> V_94 = F_16 ( V_4 ) -> V_136 ;
V_30 -> V_334 = F_139 ( V_41 -> V_52 ) << V_30 -> V_45 . V_335 ;
F_337 ( V_30 , F_16 ( V_4 ) -> V_80 ) ;
if ( V_30 -> V_45 . V_387 )
V_30 -> V_57 -= V_403 ;
if ( V_565 ) {
F_174 ( V_2 ) ;
} else
F_327 ( V_2 ) ;
V_30 -> V_541 = V_69 ;
F_37 ( V_2 ) ;
F_347 ( V_30 ) ;
break;
case V_424 : {
struct V_97 * V_98 ;
int V_571 ;
if ( V_565 != NULL ) {
if ( ! V_567 )
return 1 ;
F_346 ( V_2 , V_565 , false ) ;
F_174 ( V_2 ) ;
}
if ( V_30 -> V_94 != V_30 -> V_572 )
break;
F_228 ( V_2 , V_425 ) ;
V_2 -> V_416 |= V_573 ;
V_98 = F_204 ( V_2 ) ;
if ( V_98 )
F_205 ( V_98 ) ;
if ( ! F_224 ( V_2 , V_414 ) ) {
V_2 -> V_428 ( V_2 ) ;
break;
}
if ( V_30 -> V_574 < 0 ||
( F_16 ( V_4 ) -> V_82 != F_16 ( V_4 ) -> V_80 &&
F_48 ( F_16 ( V_4 ) -> V_82 - V_41 -> V_446 , V_30 -> V_79 ) ) ) {
F_225 ( V_2 ) ;
F_60 ( F_61 ( V_2 ) , V_575 ) ;
return 1 ;
}
V_571 = F_348 ( V_2 ) ;
if ( V_571 > V_576 ) {
F_329 ( V_2 , V_571 - V_576 ) ;
} else if ( V_41 -> V_446 || F_275 ( V_2 ) ) {
F_329 ( V_2 , V_571 ) ;
} else {
F_229 ( V_2 , V_425 , V_571 ) ;
goto V_523;
}
break;
}
case V_422 :
if ( V_30 -> V_94 == V_30 -> V_572 ) {
F_229 ( V_2 , V_426 , 0 ) ;
goto V_523;
}
break;
case V_423 :
if ( V_30 -> V_94 == V_30 -> V_572 ) {
F_349 ( V_2 ) ;
F_225 ( V_2 ) ;
goto V_523;
}
break;
}
F_310 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_406 ) {
case V_410 :
case V_422 :
case V_423 :
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) )
break;
case V_424 :
case V_425 :
if ( V_2 -> V_416 & V_417 ) {
if ( F_16 ( V_4 ) -> V_82 != F_16 ( V_4 ) -> V_80 &&
F_48 ( F_16 ( V_4 ) -> V_82 - V_41 -> V_446 , V_30 -> V_79 ) ) {
F_60 ( F_61 ( V_2 ) , V_575 ) ;
F_222 ( V_2 ) ;
return 1 ;
}
}
case V_420 :
F_273 ( V_2 , V_4 ) ;
V_566 = 1 ;
break;
}
if ( V_2 -> V_406 != V_412 ) {
F_301 ( V_2 ) ;
F_306 ( V_2 ) ;
}
if ( ! V_566 ) {
V_523:
F_244 ( V_4 ) ;
}
return 0 ;
}
