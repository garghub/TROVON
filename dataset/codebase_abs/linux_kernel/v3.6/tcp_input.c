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
V_30 -> V_31 |= V_35 ;
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
static void F_29 ( struct V_1 * V_2 )
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
void F_54 ( struct V_1 * V_2 , const int V_104 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_105 = 0 ;
V_30 -> V_106 = 0 ;
if ( V_6 -> V_107 < V_108 ) {
V_30 -> V_109 = 0 ;
if ( V_104 )
V_30 -> V_110 = V_6 -> V_111 -> V_112 ( V_2 ) ;
V_30 -> V_113 = F_9 ( V_30 -> V_113 ,
F_55 ( V_30 ) + 1U ) ;
V_30 -> V_114 = 0 ;
V_30 -> V_115 = V_30 -> V_98 ;
V_30 -> V_70 = V_71 ;
F_12 ( V_30 ) ;
F_56 ( V_2 , V_108 ) ;
}
}
void F_57 ( struct V_29 * V_30 )
{
if ( F_58 ( V_30 ) )
V_30 -> V_116 = NULL ;
V_30 -> V_45 . V_117 &= ~ V_118 ;
}
static void F_59 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_117 |= V_119 ;
}
static void F_60 ( struct V_1 * V_2 , const int V_120 ,
const int V_121 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_120 > V_30 -> V_122 ) {
int V_123 ;
V_30 -> V_122 = F_9 ( V_124 , V_120 ) ;
if ( V_121 )
V_123 = V_125 ;
else if ( F_61 ( V_30 ) )
V_123 = V_126 ;
else if ( F_58 ( V_30 ) )
V_123 = V_127 ;
else
V_123 = V_128 ;
F_62 ( F_63 ( V_2 ) , V_123 ) ;
#if V_129 > 1
F_64 ( L_1 ,
V_30 -> V_45 . V_117 , F_2 ( V_2 ) -> V_107 ,
V_30 -> V_122 ,
V_30 -> V_130 ,
V_30 -> V_131 ,
V_30 -> V_109 ? V_30 -> V_132 : 0 ) ;
#endif
F_57 ( V_30 ) ;
}
if ( V_120 > 0 )
F_65 ( V_30 ) ;
}
static void F_66 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_133 == NULL ) ||
F_40 ( F_16 ( V_4 ) -> V_82 ,
F_16 ( V_30 -> V_133 ) -> V_82 ) )
V_30 -> V_133 = V_4 ;
if ( ! V_30 -> V_134 ||
F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_135 ) )
V_30 -> V_135 = F_16 ( V_4 ) -> V_84 ;
}
static void F_67 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_136 & ( V_137 | V_138 ) ) ) {
F_66 ( V_30 , V_4 ) ;
V_30 -> V_134 += F_68 ( V_4 ) ;
F_16 ( V_4 ) -> V_136 |= V_137 ;
}
}
static void F_69 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_66 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_136 & ( V_137 | V_138 ) ) ) {
V_30 -> V_134 += F_68 ( V_4 ) ;
F_16 ( V_4 ) -> V_136 |= V_137 ;
}
}
static bool F_70 ( struct V_29 * V_30 , bool V_139 ,
T_1 V_140 , T_1 V_84 )
{
if ( F_47 ( V_84 , V_30 -> V_98 ) || ! F_40 ( V_140 , V_84 ) )
return false ;
if ( ! F_40 ( V_140 , V_30 -> V_98 ) )
return false ;
if ( F_47 ( V_140 , V_30 -> V_96 ) )
return true ;
if ( ! V_139 || ! V_30 -> V_109 )
return false ;
if ( F_47 ( V_84 , V_30 -> V_96 ) )
return false ;
if ( ! F_40 ( V_140 , V_30 -> V_109 ) )
return true ;
if ( ! F_47 ( V_84 , V_30 -> V_109 ) )
return false ;
return ! F_40 ( V_140 , V_84 - V_30 -> V_141 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_142 = 0 ;
T_1 V_143 = V_30 -> V_98 ;
T_1 V_144 = F_72 ( V_30 ) ;
if ( ! F_58 ( V_30 ) || ! V_30 -> V_145 ||
! F_47 ( V_144 , V_30 -> V_146 ) ||
V_6 -> V_107 != V_147 )
return;
F_73 (skb, sk) {
T_1 V_148 = F_16 ( V_4 ) -> V_148 ;
if ( V_4 == F_74 ( V_2 ) )
break;
if ( V_142 == V_30 -> V_145 )
break;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_136 & V_149 ) )
continue;
if ( F_47 ( V_144 , V_148 ) ) {
F_16 ( V_4 ) -> V_136 &= ~ V_149 ;
V_30 -> V_145 -= F_68 ( V_4 ) ;
F_69 ( V_30 , V_4 ) ;
F_62 ( F_63 ( V_2 ) , V_150 ) ;
} else {
if ( F_40 ( V_148 , V_143 ) )
V_143 = V_148 ;
V_142 += F_68 ( V_4 ) ;
}
}
if ( V_30 -> V_145 )
V_30 -> V_146 = V_143 ;
}
static bool F_75 ( struct V_1 * V_2 , const struct V_3 * V_151 ,
struct V_152 * V_153 , int V_154 ,
T_1 V_155 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_156 = F_76 ( & V_153 [ 0 ] . V_140 ) ;
T_1 V_157 = F_76 ( & V_153 [ 0 ] . V_84 ) ;
bool V_158 = false ;
if ( F_40 ( V_156 , F_16 ( V_151 ) -> V_148 ) ) {
V_158 = true ;
F_59 ( V_30 ) ;
F_62 ( F_63 ( V_2 ) , V_159 ) ;
} else if ( V_154 > 1 ) {
T_1 V_160 = F_76 ( & V_153 [ 1 ] . V_84 ) ;
T_1 V_161 = F_76 ( & V_153 [ 1 ] . V_140 ) ;
if ( ! F_47 ( V_157 , V_160 ) &&
! F_40 ( V_156 , V_161 ) ) {
V_158 = true ;
F_59 ( V_30 ) ;
F_62 ( F_63 ( V_2 ) ,
V_162 ) ;
}
}
if ( V_158 && V_30 -> V_109 && V_30 -> V_132 &&
! F_47 ( V_157 , V_155 ) &&
F_47 ( V_157 , V_30 -> V_109 ) )
V_30 -> V_132 -- ;
return V_158 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_140 , T_1 V_84 )
{
int V_163 ;
bool V_164 ;
unsigned int V_165 ;
unsigned int V_58 ;
V_164 = ! F_47 ( V_140 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( F_68 ( V_4 ) > 1 && ! V_164 &&
F_47 ( F_16 ( V_4 ) -> V_84 , V_140 ) ) {
V_58 = F_78 ( V_4 ) ;
V_164 = ! F_47 ( V_140 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_164 ) {
V_165 = V_140 - F_16 ( V_4 ) -> V_82 ;
if ( V_165 < V_58 )
V_165 = V_58 ;
} else {
V_165 = V_84 - F_16 ( V_4 ) -> V_82 ;
if ( V_165 < V_58 )
return - V_166 ;
}
if ( V_165 > V_58 ) {
unsigned int V_167 = ( V_165 / V_58 ) * V_58 ;
if ( ! V_164 && V_167 < V_165 ) {
V_167 += V_58 ;
if ( V_167 > V_4 -> V_10 )
return 0 ;
}
V_165 = V_167 ;
}
V_163 = F_79 ( V_2 , V_4 , V_165 , V_58 ) ;
if ( V_163 < 0 )
return V_163 ;
}
return V_164 ;
}
static T_3 F_80 ( struct V_1 * V_2 ,
struct V_168 * V_169 , T_3 V_136 ,
T_1 V_140 , T_1 V_84 ,
bool V_158 , int V_170 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_171 = V_169 -> V_171 ;
if ( V_158 && ( V_136 & V_172 ) ) {
if ( V_30 -> V_109 && V_30 -> V_132 &&
F_47 ( V_84 , V_30 -> V_109 ) )
V_30 -> V_132 -- ;
if ( V_136 & V_138 )
V_169 -> V_173 = F_9 ( V_171 , V_169 -> V_173 ) ;
}
if ( ! F_47 ( V_84 , V_30 -> V_96 ) )
return V_136 ;
if ( ! ( V_136 & V_138 ) ) {
if ( V_136 & V_149 ) {
if ( V_136 & V_137 ) {
V_136 &= ~ ( V_137 | V_149 ) ;
V_30 -> V_134 -= V_170 ;
V_30 -> V_145 -= V_170 ;
}
} else {
if ( ! ( V_136 & V_172 ) ) {
if ( F_40 ( V_140 ,
F_72 ( V_30 ) ) )
V_169 -> V_173 = F_9 ( V_171 ,
V_169 -> V_173 ) ;
if ( ! F_47 ( V_84 , V_30 -> V_174 ) )
V_169 -> V_175 |= V_176 ;
}
if ( V_136 & V_137 ) {
V_136 &= ~ V_137 ;
V_30 -> V_134 -= V_170 ;
}
}
V_136 |= V_138 ;
V_169 -> V_175 |= V_177 ;
V_30 -> V_131 += V_170 ;
V_171 += V_170 ;
if ( ! F_58 ( V_30 ) && ( V_30 -> V_116 != NULL ) &&
F_40 ( V_140 , F_16 ( V_30 -> V_116 ) -> V_82 ) )
V_30 -> V_178 += V_170 ;
if ( V_171 > V_30 -> V_130 )
V_30 -> V_130 = V_171 ;
}
if ( V_158 && ( V_136 & V_149 ) ) {
V_136 &= ~ V_149 ;
V_30 -> V_145 -= V_170 ;
}
return V_136 ;
}
static bool F_81 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_168 * V_169 ,
unsigned int V_170 , int V_179 , int V_58 ,
bool V_158 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_180 = F_82 ( V_2 , V_4 ) ;
T_1 V_140 = F_16 ( V_4 ) -> V_82 ;
T_1 V_84 = V_140 + V_179 ;
F_83 ( ! V_170 ) ;
F_80 ( V_2 , V_169 , F_16 ( V_4 ) -> V_136 ,
V_140 , V_84 , V_158 , V_170 ) ;
if ( V_4 == V_30 -> V_116 )
V_30 -> V_178 += V_170 ;
F_16 ( V_180 ) -> V_84 += V_179 ;
F_16 ( V_4 ) -> V_82 += V_179 ;
F_3 ( V_180 ) -> V_181 += V_170 ;
F_83 ( F_3 ( V_4 ) -> V_181 < V_170 ) ;
F_3 ( V_4 ) -> V_181 -= V_170 ;
if ( ! F_3 ( V_180 ) -> V_11 ) {
F_3 ( V_180 ) -> V_11 = V_58 ;
F_3 ( V_180 ) -> V_182 = V_2 -> V_183 ;
}
if ( F_3 ( V_4 ) -> V_181 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_182 = 0 ;
}
F_16 ( V_180 ) -> V_136 |= ( F_16 ( V_4 ) -> V_136 & V_184 ) ;
if ( V_4 -> V_10 > 0 ) {
F_83 ( ! F_68 ( V_4 ) ) ;
F_62 ( F_63 ( V_2 ) , V_185 ) ;
return false ;
}
if ( V_4 == V_30 -> V_133 )
V_30 -> V_133 = V_180 ;
if ( V_4 == V_30 -> V_186 )
V_30 -> V_186 = V_180 ;
if ( V_4 == V_30 -> V_116 ) {
V_30 -> V_116 = V_180 ;
V_30 -> V_178 -= F_68 ( V_180 ) ;
}
F_16 ( V_4 ) -> V_187 |= F_16 ( V_180 ) -> V_187 ;
if ( V_4 == F_84 ( V_2 ) )
F_85 ( V_2 , V_4 ) ;
F_86 ( V_4 , V_2 ) ;
F_87 ( V_2 , V_4 ) ;
F_62 ( F_63 ( V_2 ) , V_188 ) ;
return true ;
}
static int F_88 ( const struct V_3 * V_4 )
{
return F_68 ( V_4 ) == 1 ? V_4 -> V_10 : F_78 ( V_4 ) ;
}
static int F_89 ( const struct V_3 * V_4 )
{
return ! F_90 ( V_4 ) && F_91 ( V_4 ) ;
}
static struct V_3 * F_92 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_168 * V_169 ,
T_1 V_140 , T_1 V_84 ,
bool V_158 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_180 ;
int V_58 ;
int V_170 = 0 ;
int V_10 ;
int V_164 ;
if ( ! F_93 ( V_2 ) )
goto V_189;
if ( ! V_158 &&
( F_16 ( V_4 ) -> V_136 & ( V_137 | V_149 ) ) == V_149 )
goto V_189;
if ( ! F_89 ( V_4 ) )
goto V_189;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
goto V_189;
if ( F_94 ( V_4 == F_95 ( V_2 ) ) )
goto V_189;
V_180 = F_82 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_180 ) -> V_136 & V_190 ) != V_138 )
goto V_189;
V_164 = ! F_47 ( V_140 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( V_164 ) {
V_10 = V_4 -> V_10 ;
V_170 = F_68 ( V_4 ) ;
V_58 = F_88 ( V_4 ) ;
if ( V_58 != F_88 ( V_180 ) )
goto V_189;
} else {
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_140 ) )
goto V_191;
if ( F_68 ( V_4 ) <= 1 )
goto V_191;
V_164 = ! F_47 ( V_140 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_164 ) {
goto V_189;
}
V_10 = V_84 - F_16 ( V_4 ) -> V_82 ;
F_83 ( V_10 < 0 ) ;
F_83 ( V_10 > V_4 -> V_10 ) ;
V_58 = F_78 ( V_4 ) ;
if ( V_58 != F_88 ( V_180 ) )
goto V_189;
if ( V_10 == V_58 ) {
V_170 = 1 ;
} else if ( V_10 < V_58 ) {
goto V_191;
} else {
V_170 = V_10 / V_58 ;
V_10 = V_170 * V_58 ;
}
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_82 + V_10 , V_30 -> V_96 ) )
goto V_189;
if ( ! F_96 ( V_180 , V_4 , V_10 ) )
goto V_189;
if ( ! F_81 ( V_2 , V_4 , V_169 , V_170 , V_10 , V_58 , V_158 ) )
goto V_192;
if ( V_180 == F_97 ( V_2 ) )
goto V_192;
V_4 = F_98 ( V_2 , V_180 ) ;
if ( ! F_89 ( V_4 ) ||
( V_4 == F_74 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_136 & V_190 ) != V_138 ) ||
( V_58 != F_88 ( V_4 ) ) )
goto V_192;
V_10 = V_4 -> V_10 ;
if ( F_96 ( V_180 , V_4 , V_10 ) ) {
V_170 += F_68 ( V_4 ) ;
F_81 ( V_2 , V_4 , V_169 , F_68 ( V_4 ) , V_10 , V_58 , 0 ) ;
}
V_192:
V_169 -> V_171 += V_170 ;
return V_180 ;
V_191:
return V_4 ;
V_189:
F_62 ( F_63 ( V_2 ) , V_193 ) ;
return NULL ;
}
static struct V_3 * F_99 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_194 * V_195 ,
struct V_168 * V_169 ,
T_1 V_140 , T_1 V_84 ,
bool V_196 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_197 ;
F_100 (skb, sk) {
int V_164 = 0 ;
bool V_158 = V_196 ;
if ( V_4 == F_74 ( V_2 ) )
break;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_84 ) )
break;
if ( ( V_195 != NULL ) &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_195 -> V_84 ) ) {
V_164 = F_77 ( V_2 , V_4 ,
V_195 -> V_140 ,
V_195 -> V_84 ) ;
if ( V_164 > 0 )
V_158 = true ;
}
if ( V_164 <= 0 ) {
V_197 = F_92 ( V_2 , V_4 , V_169 ,
V_140 , V_84 , V_158 ) ;
if ( V_197 != NULL ) {
if ( V_197 != V_4 ) {
V_4 = V_197 ;
continue;
}
V_164 = 0 ;
} else {
V_164 = F_77 ( V_2 , V_4 ,
V_140 ,
V_84 ) ;
}
}
if ( F_94 ( V_164 < 0 ) )
break;
if ( V_164 ) {
F_16 ( V_4 ) -> V_136 =
F_80 ( V_2 ,
V_169 ,
F_16 ( V_4 ) -> V_136 ,
F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ,
V_158 ,
F_68 ( V_4 ) ) ;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 ,
F_72 ( V_30 ) ) )
F_85 ( V_2 , V_4 ) ;
}
V_169 -> V_171 += F_68 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_101 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_168 * V_169 ,
T_1 V_198 )
{
F_100 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_198 ) )
break;
V_169 -> V_171 += F_68 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_102 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_194 * V_195 ,
struct V_168 * V_169 ,
T_1 V_198 )
{
if ( V_195 == NULL )
return V_4 ;
if ( F_40 ( V_195 -> V_140 , V_198 ) ) {
V_4 = F_101 ( V_4 , V_2 , V_169 , V_195 -> V_140 ) ;
V_4 = F_99 ( V_4 , V_2 , NULL , V_169 ,
V_195 -> V_140 , V_195 -> V_84 ,
1 ) ;
}
return V_4 ;
}
static int F_103 ( const struct V_29 * V_30 , const struct V_194 * V_199 )
{
return V_199 < V_30 -> V_200 + F_104 ( V_30 -> V_200 ) ;
}
static int
F_105 ( struct V_1 * V_2 , const struct V_3 * V_151 ,
T_1 V_155 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_201 = ( F_4 ( V_151 ) +
F_16 ( V_151 ) -> V_136 ) ;
struct V_152 * V_202 = (struct V_152 * ) ( V_201 + 2 ) ;
struct V_194 V_153 [ V_203 ] ;
struct V_194 * V_199 ;
struct V_168 V_169 ;
struct V_3 * V_4 ;
int V_154 = F_9 ( V_203 , ( V_201 [ 1 ] - V_204 ) >> 3 ) ;
int V_205 ;
bool V_206 = false ;
int V_207 , V_208 ;
int V_209 ;
V_169 . V_175 = 0 ;
V_169 . V_173 = V_30 -> V_210 ;
if ( ! V_30 -> V_131 ) {
if ( F_106 ( V_30 -> V_130 ) )
V_30 -> V_130 = 0 ;
F_107 ( V_2 ) ;
}
V_206 = F_75 ( V_2 , V_151 , V_202 ,
V_154 , V_155 ) ;
if ( V_206 )
V_169 . V_175 |= V_211 ;
if ( F_40 ( F_16 ( V_151 ) -> V_148 , V_155 - V_30 -> V_141 ) )
return 0 ;
if ( ! V_30 -> V_210 )
goto V_192;
V_205 = 0 ;
V_209 = 0 ;
for ( V_207 = 0 ; V_207 < V_154 ; V_207 ++ ) {
bool V_158 = ! V_207 && V_206 ;
V_153 [ V_205 ] . V_140 = F_76 ( & V_202 [ V_207 ] . V_140 ) ;
V_153 [ V_205 ] . V_84 = F_76 ( & V_202 [ V_207 ] . V_84 ) ;
if ( ! F_70 ( V_30 , V_158 ,
V_153 [ V_205 ] . V_140 ,
V_153 [ V_205 ] . V_84 ) ) {
int V_123 ;
if ( V_158 ) {
if ( ! V_30 -> V_109 )
V_123 = V_212 ;
else
V_123 = V_213 ;
} else {
if ( ( F_16 ( V_151 ) -> V_148 != V_30 -> V_96 ) &&
! F_47 ( V_153 [ V_205 ] . V_84 , V_30 -> V_96 ) )
continue;
V_123 = V_214 ;
}
F_62 ( F_63 ( V_2 ) , V_123 ) ;
if ( V_207 == 0 )
V_209 = - 1 ;
continue;
}
if ( ! F_47 ( V_153 [ V_205 ] . V_84 , V_155 ) )
continue;
V_205 ++ ;
}
for ( V_207 = V_205 - 1 ; V_207 > 0 ; V_207 -- ) {
for ( V_208 = 0 ; V_208 < V_207 ; V_208 ++ ) {
if ( F_47 ( V_153 [ V_208 ] . V_140 , V_153 [ V_208 + 1 ] . V_140 ) ) {
F_108 ( V_153 [ V_208 ] , V_153 [ V_208 + 1 ] ) ;
if ( V_208 == V_209 )
V_209 = V_208 + 1 ;
}
}
}
V_4 = F_95 ( V_2 ) ;
V_169 . V_171 = 0 ;
V_207 = 0 ;
if ( ! V_30 -> V_131 ) {
V_199 = V_30 -> V_200 + F_104 ( V_30 -> V_200 ) ;
} else {
V_199 = V_30 -> V_200 ;
while ( F_103 ( V_30 , V_199 ) && ! V_199 -> V_140 &&
! V_199 -> V_84 )
V_199 ++ ;
}
while ( V_207 < V_205 ) {
T_1 V_140 = V_153 [ V_207 ] . V_140 ;
T_1 V_84 = V_153 [ V_207 ] . V_84 ;
bool V_158 = ( V_206 && ( V_207 == V_209 ) ) ;
struct V_194 * V_195 = NULL ;
if ( V_206 && ( ( V_207 + 1 ) == V_209 ) )
V_195 = & V_153 [ V_207 + 1 ] ;
while ( F_103 ( V_30 , V_199 ) &&
! F_40 ( V_140 , V_199 -> V_84 ) )
V_199 ++ ;
if ( F_103 ( V_30 , V_199 ) && ! V_158 &&
F_47 ( V_84 , V_199 -> V_140 ) ) {
if ( F_40 ( V_140 , V_199 -> V_140 ) ) {
V_4 = F_101 ( V_4 , V_2 , & V_169 ,
V_140 ) ;
V_4 = F_99 ( V_4 , V_2 , V_195 ,
& V_169 ,
V_140 ,
V_199 -> V_140 ,
V_158 ) ;
}
if ( ! F_47 ( V_84 , V_199 -> V_84 ) )
goto V_215;
V_4 = F_102 ( V_4 , V_2 , V_195 ,
& V_169 ,
V_199 -> V_84 ) ;
if ( F_72 ( V_30 ) == V_199 -> V_84 ) {
V_4 = F_84 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_169 . V_171 = V_30 -> V_130 ;
V_199 ++ ;
goto V_216;
}
V_4 = F_101 ( V_4 , V_2 , & V_169 , V_199 -> V_84 ) ;
V_199 ++ ;
continue;
}
if ( ! F_40 ( V_140 , F_72 ( V_30 ) ) ) {
V_4 = F_84 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_169 . V_171 = V_30 -> V_130 ;
}
V_4 = F_101 ( V_4 , V_2 , & V_169 , V_140 ) ;
V_216:
V_4 = F_99 ( V_4 , V_2 , V_195 , & V_169 ,
V_140 , V_84 , V_158 ) ;
V_215:
if ( F_47 ( V_84 , V_30 -> V_174 ) )
V_169 . V_175 &= ~ V_176 ;
V_207 ++ ;
}
for ( V_207 = 0 ; V_207 < F_104 ( V_30 -> V_200 ) - V_205 ; V_207 ++ ) {
V_30 -> V_200 [ V_207 ] . V_140 = 0 ;
V_30 -> V_200 [ V_207 ] . V_84 = 0 ;
}
for ( V_208 = 0 ; V_208 < V_205 ; V_208 ++ )
V_30 -> V_200 [ V_207 ++ ] = V_153 [ V_208 ] ;
F_71 ( V_2 ) ;
F_109 ( V_30 ) ;
if ( ( V_169 . V_173 < V_30 -> V_130 ) &&
( ( V_6 -> V_107 != V_217 ) || V_30 -> V_109 ) &&
( ! V_30 -> V_174 || F_47 ( V_30 -> V_96 , V_30 -> V_174 ) ) )
F_60 ( V_2 , V_30 -> V_130 - V_169 . V_173 , 0 ) ;
V_192:
#if V_129 > 0
F_106 ( ( int ) V_30 -> V_131 < 0 ) ;
F_106 ( ( int ) V_30 -> V_134 < 0 ) ;
F_106 ( ( int ) V_30 -> V_145 < 0 ) ;
F_106 ( ( int ) F_55 ( V_30 ) < 0 ) ;
#endif
return V_169 . V_175 ;
}
static bool F_110 ( struct V_29 * V_30 )
{
T_1 V_218 ;
V_218 = F_31 ( V_30 -> V_134 , 1U ) ;
V_218 = F_9 ( V_218 , V_30 -> V_210 ) ;
if ( ( V_30 -> V_131 + V_218 ) > V_30 -> V_210 ) {
V_30 -> V_131 = V_30 -> V_210 - V_218 ;
return true ;
}
return false ;
}
static void F_111 ( struct V_1 * V_2 , const int V_219 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_110 ( V_30 ) )
F_60 ( V_2 , V_30 -> V_210 + V_219 , 0 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_131 ++ ;
F_111 ( V_2 , 0 ) ;
F_109 ( V_30 ) ;
}
static void F_113 ( struct V_1 * V_2 , int V_220 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_220 > 0 ) {
if ( V_220 - 1 >= V_30 -> V_131 )
V_30 -> V_131 = 0 ;
else
V_30 -> V_131 -= V_220 - 1 ;
}
F_111 ( V_2 , V_220 ) ;
F_109 ( V_30 ) ;
}
static inline void F_114 ( struct V_29 * V_30 )
{
V_30 -> V_131 = 0 ;
}
static int F_115 ( const struct V_29 * V_30 )
{
return ( V_221 == 0x2 ) && ! F_61 ( V_30 ) ;
}
bool F_116 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_221 )
return false ;
if ( V_6 -> V_222 . V_223 )
return false ;
if ( F_115 ( V_30 ) )
return true ;
if ( V_30 -> V_145 > 1 )
return false ;
V_4 = F_95 ( V_2 ) ;
if ( F_117 ( V_2 , V_4 ) )
return true ;
V_4 = F_98 ( V_2 , V_4 ) ;
F_100 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_136 & V_172 )
return false ;
if ( ! ( F_16 ( V_4 ) -> V_136 & V_138 ) )
break;
}
return true ;
}
void F_118 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ( ! V_30 -> V_224 && V_6 -> V_107 <= V_225 ) ||
V_30 -> V_96 == V_30 -> V_115 ||
( ( V_6 -> V_107 == V_217 || V_30 -> V_224 ) &&
! V_6 -> V_226 ) ) {
V_30 -> V_105 = F_119 ( V_2 ) ;
if ( V_30 -> V_224 ) {
T_1 V_227 ;
V_227 = V_30 -> V_113 ;
V_30 -> V_113 = 2 ;
V_30 -> V_110 = V_6 -> V_111 -> V_112 ( V_2 ) ;
V_30 -> V_113 = V_227 ;
} else {
V_30 -> V_110 = V_6 -> V_111 -> V_112 ( V_2 ) ;
}
F_120 ( V_2 , V_228 ) ;
}
V_30 -> V_109 = V_30 -> V_96 ;
V_30 -> V_132 = 0 ;
V_4 = F_95 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_136 & V_172 )
V_30 -> V_109 = 0 ;
if ( F_16 ( V_4 ) -> V_136 & V_149 ) {
F_16 ( V_4 ) -> V_136 &= ~ V_149 ;
V_30 -> V_145 -= F_68 ( V_4 ) ;
}
F_109 ( V_30 ) ;
V_30 -> V_113 = F_9 ( V_30 -> V_113 , F_55 ( V_30 ) + 1 ) ;
if ( F_115 ( V_30 ) && ( V_30 -> V_224 ||
( ( 1 << V_6 -> V_107 ) & ( V_229 | V_230 ) ) ) &&
F_47 ( V_30 -> V_115 , V_30 -> V_96 ) ) {
V_30 -> V_174 = V_30 -> V_115 ;
} else {
V_30 -> V_174 = V_30 -> V_98 ;
}
F_56 ( V_2 , V_225 ) ;
V_30 -> V_115 = V_30 -> V_98 ;
V_30 -> V_224 = 1 ;
}
static void F_121 ( struct V_1 * V_2 , int V_231 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
V_30 -> V_134 = 0 ;
V_30 -> V_145 = 0 ;
if ( F_61 ( V_30 ) )
F_114 ( V_30 ) ;
F_73 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_136 &= ~ V_137 ;
if ( ( V_30 -> V_224 == 1 ) && ! ( V_175 & V_232 ) ) {
if ( F_16 ( V_4 ) -> V_136 & V_149 )
V_30 -> V_145 += F_68 ( V_4 ) ;
V_175 |= V_232 ;
} else {
if ( F_16 ( V_4 ) -> V_136 & V_172 )
V_30 -> V_109 = 0 ;
F_16 ( V_4 ) -> V_136 &= ~ V_149 ;
}
if ( ! ( F_16 ( V_4 ) -> V_136 & V_138 ) ) {
F_16 ( V_4 ) -> V_136 |= V_137 ;
V_30 -> V_134 += F_68 ( V_4 ) ;
V_30 -> V_135 = F_16 ( V_4 ) -> V_84 ;
}
}
F_109 ( V_30 ) ;
V_30 -> V_113 = F_55 ( V_30 ) + V_231 ;
V_30 -> V_114 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_224 = 0 ;
V_30 -> V_106 = 0 ;
V_30 -> V_122 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_56 ( V_2 , V_217 ) ;
V_30 -> V_115 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
F_122 ( V_30 ) ;
}
static void F_123 ( struct V_29 * V_30 )
{
V_30 -> V_145 = 0 ;
V_30 -> V_134 = 0 ;
V_30 -> V_109 = 0 ;
V_30 -> V_132 = 0 ;
}
void F_124 ( struct V_29 * V_30 )
{
F_123 ( V_30 ) ;
V_30 -> V_130 = 0 ;
V_30 -> V_131 = 0 ;
}
void F_125 ( struct V_1 * V_2 , int V_233 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_6 -> V_107 <= V_225 || V_30 -> V_96 == V_30 -> V_115 ||
( V_6 -> V_107 == V_217 && ! V_6 -> V_226 ) ) {
V_30 -> V_105 = F_119 ( V_2 ) ;
V_30 -> V_110 = V_6 -> V_111 -> V_112 ( V_2 ) ;
F_120 ( V_2 , V_234 ) ;
}
V_30 -> V_113 = 1 ;
V_30 -> V_114 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_106 = 0 ;
F_123 ( V_30 ) ;
if ( F_61 ( V_30 ) )
F_114 ( V_30 ) ;
if ( ! V_233 ) {
V_30 -> V_109 = V_30 -> V_96 ;
} else {
V_30 -> V_131 = 0 ;
V_30 -> V_130 = 0 ;
}
F_122 ( V_30 ) ;
F_73 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_136 & V_172 )
V_30 -> V_109 = 0 ;
F_16 ( V_4 ) -> V_136 &= ( ~ V_190 ) | V_138 ;
if ( ! ( F_16 ( V_4 ) -> V_136 & V_138 ) || V_233 ) {
F_16 ( V_4 ) -> V_136 &= ~ V_138 ;
F_16 ( V_4 ) -> V_136 |= V_137 ;
V_30 -> V_134 += F_68 ( V_4 ) ;
V_30 -> V_135 = F_16 ( V_4 ) -> V_84 ;
}
}
F_109 ( V_30 ) ;
V_30 -> V_122 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_56 ( V_2 , V_217 ) ;
V_30 -> V_115 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
V_30 -> V_224 = 0 ;
}
static bool F_126 ( struct V_1 * V_2 , int V_175 )
{
if ( V_175 & V_235 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_62 ( F_63 ( V_2 ) , V_236 ) ;
F_125 ( V_2 , 1 ) ;
V_6 -> V_226 ++ ;
F_127 ( V_2 , F_95 ( V_2 ) ) ;
F_128 ( V_2 , V_237 ,
V_6 -> V_90 , V_238 ) ;
return true ;
}
return false ;
}
static inline int F_129 ( const struct V_29 * V_30 )
{
return F_61 ( V_30 ) ? V_30 -> V_131 + 1 : V_30 -> V_130 ;
}
static inline int F_130 ( const struct V_29 * V_30 )
{
return F_58 ( V_30 ) ? V_30 -> V_130 : V_30 -> V_131 + 1 ;
}
static bool F_131 ( struct V_1 * V_2 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_239 ;
if ( V_240 < 2 || ( V_175 & V_241 ) || ! V_30 -> V_92 )
return false ;
V_239 = F_27 (unsigned long, (tp->srtt >> 5), msecs_to_jiffies(2)) ;
if ( ! F_132 ( F_2 ( V_2 ) -> V_242 , ( V_243 + V_239 ) ) )
return false ;
F_128 ( V_2 , V_237 , V_239 , V_238 ) ;
V_30 -> V_244 = 1 ;
return true ;
}
static inline int F_133 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_71 - F_16 ( V_4 ) -> V_245 > F_2 ( V_2 ) -> V_90 ;
}
static inline int F_134 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_210 &&
F_133 ( V_2 , F_95 ( V_2 ) ) ;
}
static bool F_135 ( struct V_1 * V_2 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_210 ;
if ( V_30 -> V_224 )
return false ;
if ( V_30 -> V_134 )
return true ;
if ( F_130 ( V_30 ) > V_30 -> V_122 )
return true ;
if ( F_58 ( V_30 ) && F_134 ( V_2 ) )
return true ;
V_210 = V_30 -> V_210 ;
if ( V_210 <= V_30 -> V_122 &&
V_30 -> V_131 >= F_27 ( T_2 , V_210 / 2 , V_246 ) &&
! F_136 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_247 || V_248 ) &&
F_137 ( V_30 ) && F_130 ( V_30 ) > 1 &&
F_138 ( V_30 ) && ! F_74 ( V_2 ) )
return true ;
if ( V_30 -> V_249 && ! V_30 -> V_145 && V_30 -> V_131 &&
( V_30 -> V_210 == ( V_30 -> V_131 + 1 ) && V_30 -> V_210 < 4 ) &&
! F_136 ( V_2 ) )
return ! F_131 ( V_2 , V_175 ) ;
return false ;
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_58 ( V_30 ) || ! F_134 ( V_2 ) )
return;
V_4 = V_30 -> V_186 ;
if ( V_30 -> V_186 == NULL )
V_4 = F_95 ( V_2 ) ;
F_100 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( ! F_133 ( V_2 , V_4 ) )
break;
F_67 ( V_30 , V_4 ) ;
}
V_30 -> V_186 = V_4 ;
F_109 ( V_30 ) ;
}
static void F_140 ( struct V_1 * V_2 , int V_250 , int V_251 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_142 , V_252 ;
int V_163 ;
unsigned int V_58 ;
const T_1 V_253 = F_138 ( V_30 ) ? V_30 -> V_98 : V_30 -> V_115 ;
F_106 ( V_250 > V_30 -> V_210 ) ;
if ( V_30 -> V_116 ) {
V_4 = V_30 -> V_116 ;
V_142 = V_30 -> V_178 ;
if ( V_251 && V_4 != F_95 ( V_2 ) )
return;
} else {
V_4 = F_95 ( V_2 ) ;
V_142 = 0 ;
}
F_100 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
V_30 -> V_116 = V_4 ;
V_30 -> V_178 = V_142 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_253 ) )
break;
V_252 = V_142 ;
if ( F_58 ( V_30 ) || F_61 ( V_30 ) ||
( F_16 ( V_4 ) -> V_136 & V_138 ) )
V_142 += F_68 ( V_4 ) ;
if ( V_142 > V_250 ) {
if ( ( F_138 ( V_30 ) && ! F_58 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_136 & V_138 ) ||
( V_252 >= V_250 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_163 = F_79 ( V_2 , V_4 , ( V_250 - V_252 ) * V_58 , V_58 ) ;
if ( V_163 < 0 )
break;
V_142 = V_250 ;
}
F_67 ( V_30 , V_4 ) ;
if ( V_251 )
break;
}
F_109 ( V_30 ) ;
}
static void F_141 ( struct V_1 * V_2 , int V_254 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_61 ( V_30 ) ) {
F_140 ( V_2 , 1 , 1 ) ;
} else if ( F_58 ( V_30 ) ) {
int V_255 = V_30 -> V_130 - V_30 -> V_122 ;
if ( V_255 <= 0 )
V_255 = 1 ;
F_140 ( V_2 , V_255 , 0 ) ;
} else {
int V_256 = V_30 -> V_131 - V_30 -> V_122 ;
if ( V_256 >= 0 )
F_140 ( V_2 , V_256 , 0 ) ;
else if ( V_254 )
F_140 ( V_2 , 1 , 1 ) ;
}
F_139 ( V_2 ) ;
}
static inline void F_142 ( struct V_29 * V_30 )
{
V_30 -> V_113 = F_9 ( V_30 -> V_113 ,
F_55 ( V_30 ) + F_143 ( V_30 ) ) ;
V_30 -> V_70 = V_71 ;
}
static inline T_1 F_144 ( const struct V_1 * V_2 )
{
const struct V_257 * V_258 = F_2 ( V_2 ) -> V_111 ;
return V_258 -> V_259 ? V_258 -> V_259 ( V_2 ) : F_7 ( V_2 ) -> V_110 ;
}
static void F_145 ( struct V_1 * V_2 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_260 = V_30 -> V_114 + 1 ;
if ( ( V_175 & ( V_261 | V_211 ) ) ||
( F_61 ( V_30 ) && ! ( V_175 & V_262 ) ) ) {
V_30 -> V_114 = V_260 & 1 ;
V_260 >>= 1 ;
if ( V_260 && V_30 -> V_113 > F_144 ( V_2 ) )
V_30 -> V_113 -= V_260 ;
V_30 -> V_113 = F_9 ( V_30 -> V_113 , F_55 ( V_30 ) + 1 ) ;
V_30 -> V_70 = V_71 ;
}
}
static inline bool F_146 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_263 ||
( V_30 -> V_45 . V_264 && V_30 -> V_45 . V_83 &&
F_40 ( V_30 -> V_45 . V_83 , V_30 -> V_263 ) ) ;
}
static void F_147 ( struct V_1 * V_2 , const char * V_265 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_266 * V_267 = F_148 ( V_2 ) ;
if ( V_2 -> V_268 == V_269 ) {
F_64 ( L_2 ,
V_265 ,
& V_267 -> V_270 , F_149 ( V_267 -> V_271 ) ,
V_30 -> V_113 , F_150 ( V_30 ) ,
V_30 -> V_110 , V_30 -> V_105 ,
V_30 -> V_210 ) ;
}
#if F_151 ( V_272 )
else if ( V_2 -> V_268 == V_273 ) {
struct V_274 * V_275 = F_152 ( V_2 ) ;
F_64 ( L_3 ,
V_265 ,
& V_275 -> V_276 , F_149 ( V_267 -> V_271 ) ,
V_30 -> V_113 , F_150 ( V_30 ) ,
V_30 -> V_110 , V_30 -> V_105 ,
V_30 -> V_210 ) ;
}
#endif
}
static void F_153 ( struct V_1 * V_2 , const bool V_277 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_105 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_111 -> V_278 )
V_30 -> V_113 = V_6 -> V_111 -> V_278 ( V_2 ) ;
else
V_30 -> V_113 = F_31 ( V_30 -> V_113 , V_30 -> V_110 << 1 ) ;
if ( V_277 && V_30 -> V_105 > V_30 -> V_110 ) {
V_30 -> V_110 = V_30 -> V_105 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_113 = F_31 ( V_30 -> V_113 , V_30 -> V_110 ) ;
}
V_30 -> V_70 = V_71 ;
}
static inline bool F_154 ( const struct V_29 * V_30 )
{
return V_30 -> V_109 && ( ! V_30 -> V_132 || F_146 ( V_30 ) ) ;
}
static bool F_155 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_154 ( V_30 ) ) {
int V_123 ;
F_147 ( V_2 , F_2 ( V_2 ) -> V_107 == V_217 ? L_4 : L_5 ) ;
F_153 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_107 == V_217 )
V_123 = V_279 ;
else
V_123 = V_280 ;
F_62 ( F_63 ( V_2 ) , V_123 ) ;
V_30 -> V_109 = 0 ;
}
if ( V_30 -> V_96 == V_30 -> V_115 && F_61 ( V_30 ) ) {
F_142 ( V_30 ) ;
return true ;
}
F_56 ( V_2 , V_281 ) ;
return false ;
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_109 && ! V_30 -> V_132 ) {
F_147 ( V_2 , L_6 ) ;
F_153 ( V_2 , true ) ;
V_30 -> V_109 = 0 ;
F_62 ( F_63 ( V_2 ) , V_282 ) ;
}
}
static bool F_157 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_145 )
return true ;
V_4 = F_95 ( V_2 ) ;
if ( F_94 ( V_4 && F_16 ( V_4 ) -> V_136 & V_184 ) )
return true ;
return false ;
}
static int F_158 ( struct V_1 * V_2 , int V_220 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_283 = F_61 ( V_30 ) || ( F_129 ( V_30 ) > V_30 -> V_122 ) ;
if ( F_154 ( V_30 ) ) {
if ( ! F_157 ( V_2 ) )
V_30 -> V_263 = 0 ;
F_60 ( V_2 , F_129 ( V_30 ) + V_220 , 1 ) ;
F_147 ( V_2 , L_7 ) ;
F_153 ( V_2 , false ) ;
F_62 ( F_63 ( V_2 ) , V_284 ) ;
V_283 = 0 ;
}
return V_283 ;
}
static bool F_159 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_154 ( V_30 ) ) {
struct V_3 * V_4 ;
F_73 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_136 &= ~ V_137 ;
}
F_122 ( V_30 ) ;
F_147 ( V_2 , L_8 ) ;
V_30 -> V_134 = 0 ;
F_153 ( V_2 , true ) ;
F_62 ( F_63 ( V_2 ) , V_279 ) ;
F_2 ( V_2 ) -> V_226 = 0 ;
V_30 -> V_109 = 0 ;
if ( F_138 ( V_30 ) )
F_56 ( V_2 , V_281 ) ;
return true ;
}
return false ;
}
static inline void F_160 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_109 ) {
if ( F_2 ( V_2 ) -> V_107 == V_108 ) {
V_30 -> V_113 = F_9 ( V_30 -> V_113 , V_30 -> V_110 ) ;
V_30 -> V_70 = V_71 ;
} else if ( V_30 -> V_110 < V_285 ) {
V_30 -> V_113 = V_30 -> V_110 ;
V_30 -> V_70 = V_71 ;
}
}
F_120 ( V_2 , V_286 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_169 = V_281 ;
if ( F_150 ( V_30 ) || F_157 ( V_2 ) )
V_169 = V_225 ;
if ( F_2 ( V_2 ) -> V_107 != V_169 ) {
F_56 ( V_2 , V_169 ) ;
V_30 -> V_115 = V_30 -> V_98 ;
}
}
static void F_162 ( struct V_1 * V_2 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_109 ( V_30 ) ;
if ( ! V_30 -> V_224 && ! F_157 ( V_2 ) )
V_30 -> V_263 = 0 ;
if ( V_175 & V_241 )
F_54 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_107 != V_108 ) {
F_161 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_107 != V_281 )
F_142 ( V_30 ) ;
} else {
F_145 ( V_2 , V_175 ) ;
}
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_222 . V_287 = V_6 -> V_222 . V_223 - 1 ;
V_6 -> V_222 . V_223 = 0 ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_105 = F_119 ( V_2 ) ;
V_30 -> V_113 = V_30 -> V_113 *
F_165 ( V_2 , V_30 -> V_288 ) /
V_6 -> V_222 . V_223 ;
V_30 -> V_114 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_110 = F_119 ( V_2 ) ;
V_6 -> V_222 . V_289 = V_6 -> V_222 . V_223 ;
V_6 -> V_222 . V_223 = 0 ;
F_166 ( V_2 , V_6 -> V_290 ) ;
}
void F_167 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_168 ( V_2 ) ;
T_1 V_291 = V_30 -> V_134 ;
F_73 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( F_88 ( V_4 ) > V_58 &&
! ( F_16 ( V_4 ) -> V_136 & V_138 ) ) {
if ( F_16 ( V_4 ) -> V_136 & V_149 ) {
F_16 ( V_4 ) -> V_136 &= ~ V_149 ;
V_30 -> V_145 -= F_68 ( V_4 ) ;
}
F_69 ( V_30 , V_4 ) ;
}
}
F_169 ( V_30 ) ;
if ( V_291 == V_30 -> V_134 )
return;
if ( F_61 ( V_30 ) )
F_110 ( V_30 ) ;
F_109 ( V_30 ) ;
if ( V_6 -> V_107 != V_217 ) {
V_30 -> V_115 = V_30 -> V_98 ;
V_30 -> V_110 = F_119 ( V_2 ) ;
V_30 -> V_105 = 0 ;
V_30 -> V_109 = 0 ;
F_56 ( V_2 , V_217 ) ;
}
F_170 ( V_2 ) ;
}
static void F_171 ( struct V_1 * V_2 , int V_292 ,
int V_254 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_293 = 0 ;
int V_294 = V_30 -> V_110 - F_55 ( V_30 ) ;
if ( F_55 ( V_30 ) > V_30 -> V_110 ) {
T_4 V_295 = ( T_4 ) V_30 -> V_110 * V_30 -> V_296 +
V_30 -> V_297 - 1 ;
V_293 = F_172 ( V_295 , V_30 -> V_297 ) - V_30 -> V_298 ;
} else {
V_293 = F_37 ( int , V_294 ,
F_27 ( int , V_30 -> V_296 - V_30 -> V_298 ,
V_292 ) + 1 ) ;
}
V_293 = F_31 ( V_293 , ( V_254 ? 1 : 0 ) ) ;
V_30 -> V_113 = F_55 ( V_30 ) + V_293 ;
}
static void F_173 ( struct V_1 * V_2 , bool V_299 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_123 ;
if ( F_61 ( V_30 ) )
V_123 = V_300 ;
else
V_123 = V_301 ;
F_62 ( F_63 ( V_2 ) , V_123 ) ;
V_30 -> V_115 = V_30 -> V_98 ;
V_30 -> V_105 = 0 ;
V_30 -> V_109 = V_30 -> V_96 ;
V_30 -> V_132 = V_30 -> V_145 ;
if ( F_2 ( V_2 ) -> V_107 < V_108 ) {
if ( ! V_299 )
V_30 -> V_105 = F_119 ( V_2 ) ;
V_30 -> V_110 = F_2 ( V_2 ) -> V_111 -> V_112 ( V_2 ) ;
F_12 ( V_30 ) ;
}
V_30 -> V_106 = 0 ;
V_30 -> V_114 = 0 ;
V_30 -> V_297 = V_30 -> V_113 ;
V_30 -> V_296 = 0 ;
V_30 -> V_298 = 0 ;
F_56 ( V_2 , V_147 ) ;
}
static void F_174 ( struct V_1 * V_2 , int V_302 ,
int V_303 , bool V_304 ,
int V_175 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_305 = V_304 || ( ( V_175 & V_177 ) &&
( F_129 ( V_30 ) > V_30 -> V_122 ) ) ;
int V_292 = 0 ;
int V_254 = 0 ;
if ( F_106 ( ! V_30 -> V_210 && V_30 -> V_131 ) )
V_30 -> V_131 = 0 ;
if ( F_106 ( ! V_30 -> V_131 && V_30 -> V_130 ) )
V_30 -> V_130 = 0 ;
if ( V_175 & V_241 )
V_30 -> V_105 = 0 ;
if ( F_126 ( V_2 , V_175 ) )
return;
F_109 ( V_30 ) ;
if ( V_6 -> V_107 == V_281 ) {
F_106 ( V_30 -> V_145 != 0 ) ;
V_30 -> V_263 = 0 ;
} else if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_115 ) ) {
switch ( V_6 -> V_107 ) {
case V_217 :
V_6 -> V_226 = 0 ;
if ( F_155 ( V_2 ) )
return;
break;
case V_108 :
if ( V_30 -> V_96 != V_30 -> V_115 ) {
F_160 ( V_2 ) ;
F_56 ( V_2 , V_281 ) ;
}
break;
case V_147 :
if ( F_61 ( V_30 ) )
F_114 ( V_30 ) ;
if ( F_155 ( V_2 ) )
return;
F_160 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_107 ) {
case V_147 :
if ( ! ( V_175 & V_306 ) ) {
if ( F_61 ( V_30 ) && V_304 )
F_112 ( V_2 ) ;
} else
V_305 = F_158 ( V_2 , V_302 ) ;
V_292 = V_302 + V_30 -> V_131 - V_303 ;
break;
case V_217 :
if ( V_175 & V_232 )
V_6 -> V_226 = 0 ;
if ( F_61 ( V_30 ) && V_175 & V_306 )
F_114 ( V_30 ) ;
if ( ! F_159 ( V_2 ) ) {
F_142 ( V_30 ) ;
F_170 ( V_2 ) ;
return;
}
if ( V_6 -> V_107 != V_281 )
return;
default:
if ( F_61 ( V_30 ) ) {
if ( V_175 & V_306 )
F_114 ( V_30 ) ;
if ( V_304 )
F_112 ( V_2 ) ;
}
V_292 = V_302 + V_30 -> V_131 - V_303 ;
if ( V_6 -> V_107 <= V_225 )
F_156 ( V_2 ) ;
if ( ! F_135 ( V_2 , V_175 ) ) {
F_162 ( V_2 , V_175 ) ;
return;
}
if ( V_6 -> V_107 < V_108 &&
V_6 -> V_222 . V_223 &&
V_30 -> V_96 == V_30 -> V_307 . V_308 ) {
F_163 ( V_2 ) ;
V_30 -> V_113 ++ ;
F_167 ( V_2 ) ;
return;
}
F_173 ( V_2 , ( V_175 & V_241 ) ) ;
V_254 = 1 ;
}
if ( V_305 || ( F_58 ( V_30 ) && F_134 ( V_2 ) ) )
F_141 ( V_2 , V_254 ) ;
V_30 -> V_296 += V_292 ;
F_171 ( V_2 , V_292 , V_254 , V_175 ) ;
F_170 ( V_2 ) ;
}
void F_175 ( struct V_1 * V_2 , T_1 V_309 )
{
F_46 ( V_2 , V_309 ) ;
F_49 ( V_2 ) ;
F_2 ( V_2 ) -> V_310 = 0 ;
}
static void F_176 ( struct V_1 * V_2 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_175 ( V_2 , V_71 - V_30 -> V_45 . V_83 ) ;
}
static void F_177 ( struct V_1 * V_2 , T_1 V_309 , int V_175 )
{
if ( V_175 & V_311 )
return;
F_175 ( V_2 , V_309 ) ;
}
static inline void F_178 ( struct V_1 * V_2 , const int V_175 ,
const T_5 V_309 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_264 && V_30 -> V_45 . V_83 )
F_176 ( V_2 , V_175 ) ;
else if ( V_309 >= 0 )
F_177 ( V_2 , V_309 , V_175 ) ;
}
static void F_179 ( struct V_1 * V_2 , T_1 V_312 , T_1 V_313 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_111 -> V_314 ( V_2 , V_312 , V_313 ) ;
F_7 ( V_2 ) -> V_70 = V_71 ;
}
void F_180 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_210 ) {
F_181 ( V_2 , V_237 ) ;
} else {
T_1 V_315 = F_2 ( V_2 ) -> V_90 ;
if ( V_30 -> V_244 ) {
struct V_3 * V_4 = F_95 ( V_2 ) ;
const T_1 V_316 = F_16 ( V_4 ) -> V_245 + V_315 ;
T_5 V_294 = ( T_5 ) ( V_316 - V_71 ) ;
if ( V_294 > 0 )
V_315 = V_294 ;
}
F_128 ( V_2 , V_237 , V_315 ,
V_238 ) ;
}
V_30 -> V_244 = 0 ;
}
void F_182 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_180 ( V_2 ) ;
if ( ! V_30 -> V_249 )
return;
F_173 ( V_2 , false ) ;
F_141 ( V_2 , 1 ) ;
F_170 ( V_2 ) ;
}
static T_1 F_183 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_317 ;
F_83 ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) ) ;
V_317 = F_68 ( V_4 ) ;
if ( F_184 ( V_2 , V_4 , V_30 -> V_96 - F_16 ( V_4 ) -> V_82 ) )
return 0 ;
V_317 -= F_68 ( V_4 ) ;
if ( V_317 ) {
F_83 ( F_68 ( V_4 ) == 0 ) ;
F_83 ( ! F_40 ( F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) ;
}
return V_317 ;
}
static int F_185 ( struct V_1 * V_2 , int V_318 ,
T_1 V_155 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_88 = V_71 ;
int V_319 = true ;
int V_175 = 0 ;
T_1 V_302 = 0 ;
T_1 V_173 = V_30 -> V_210 ;
T_1 V_303 = V_30 -> V_131 ;
T_5 V_309 = - 1 ;
T_5 V_320 = - 1 ;
T_6 V_321 = F_186 () ;
while ( ( V_4 = F_95 ( V_2 ) ) && V_4 != F_74 ( V_2 ) ) {
struct V_322 * V_323 = F_16 ( V_4 ) ;
T_1 V_324 ;
T_3 V_136 = V_323 -> V_136 ;
if ( F_47 ( V_323 -> V_84 , V_30 -> V_96 ) ) {
if ( F_68 ( V_4 ) == 1 ||
! F_47 ( V_30 -> V_96 , V_323 -> V_82 ) )
break;
V_324 = F_183 ( V_2 , V_4 ) ;
if ( ! V_324 )
break;
V_319 = false ;
} else {
V_324 = F_68 ( V_4 ) ;
}
if ( V_136 & V_172 ) {
if ( V_136 & V_149 )
V_30 -> V_145 -= V_324 ;
V_175 |= V_311 ;
V_320 = - 1 ;
V_309 = - 1 ;
if ( ( V_175 & V_232 ) || ( V_324 > 1 ) )
V_175 |= V_325 ;
} else {
V_320 = V_88 - V_323 -> V_245 ;
V_321 = V_4 -> V_326 ;
if ( V_309 < 0 ) {
V_309 = V_320 ;
}
if ( ! ( V_136 & V_138 ) )
V_173 = F_9 ( V_302 , V_173 ) ;
}
if ( V_136 & V_138 )
V_30 -> V_131 -= V_324 ;
if ( V_136 & V_137 )
V_30 -> V_134 -= V_324 ;
V_30 -> V_210 -= V_324 ;
V_302 += V_324 ;
if ( ! ( V_323 -> V_187 & V_327 ) ) {
V_175 |= V_232 ;
} else {
V_175 |= V_328 ;
V_30 -> V_263 = 0 ;
}
if ( ! V_319 )
break;
F_86 ( V_4 , V_2 ) ;
F_87 ( V_2 , V_4 ) ;
V_30 -> V_186 = NULL ;
if ( V_4 == V_30 -> V_133 )
V_30 -> V_133 = NULL ;
if ( V_4 == V_30 -> V_116 )
V_30 -> V_116 = NULL ;
}
if ( F_187 ( F_188 ( V_30 -> V_329 , V_155 , V_30 -> V_96 ) ) )
V_30 -> V_329 = V_30 -> V_96 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_136 & V_138 ) )
V_175 |= V_235 ;
if ( V_175 & V_330 ) {
const struct V_257 * V_258
= F_2 ( V_2 ) -> V_111 ;
if ( F_94 ( V_6 -> V_222 . V_223 &&
! F_47 ( V_30 -> V_307 . V_331 , V_30 -> V_96 ) ) ) {
F_164 ( V_2 ) ;
}
F_178 ( V_2 , V_175 , V_309 ) ;
F_180 ( V_2 ) ;
if ( F_61 ( V_30 ) ) {
F_113 ( V_2 , V_302 ) ;
} else {
int V_294 ;
if ( V_173 < V_318 )
F_60 ( V_2 , V_30 -> V_130 - V_173 , 0 ) ;
V_294 = F_58 ( V_30 ) ? V_302 :
V_303 - V_30 -> V_131 ;
V_30 -> V_178 -= F_9 ( V_30 -> V_178 , V_294 ) ;
}
V_30 -> V_130 -= F_9 ( V_302 , V_30 -> V_130 ) ;
if ( V_258 -> V_302 ) {
T_5 V_332 = - 1 ;
if ( ! ( V_175 & V_311 ) ) {
if ( V_258 -> V_333 & V_334 &&
! F_189 ( V_321 ,
F_186 () ) )
V_332 = F_190 ( F_191 () ,
V_321 ) ;
else if ( V_320 >= 0 )
V_332 = F_192 ( V_320 ) ;
}
V_258 -> V_302 ( V_2 , V_302 , V_332 ) ;
}
}
#if V_129 > 0
F_106 ( ( int ) V_30 -> V_131 < 0 ) ;
F_106 ( ( int ) V_30 -> V_134 < 0 ) ;
F_106 ( ( int ) V_30 -> V_145 < 0 ) ;
if ( ! V_30 -> V_210 && F_138 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_134 ) {
F_64 ( L_9 ,
V_30 -> V_134 , V_6 -> V_107 ) ;
V_30 -> V_134 = 0 ;
}
if ( V_30 -> V_131 ) {
F_64 ( L_10 ,
V_30 -> V_131 , V_6 -> V_107 ) ;
V_30 -> V_131 = 0 ;
}
if ( V_30 -> V_145 ) {
F_64 ( L_11 ,
V_30 -> V_145 , V_6 -> V_107 ) ;
V_30 -> V_145 = 0 ;
}
}
#endif
return V_175 ;
}
static void F_193 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_47 ( F_16 ( F_74 ( V_2 ) ) -> V_84 , F_194 ( V_30 ) ) ) {
V_6 -> V_310 = 0 ;
F_181 ( V_2 , V_335 ) ;
} else {
F_128 ( V_2 , V_335 ,
F_9 ( V_6 -> V_90 << V_6 -> V_310 , V_238 ) ,
V_238 ) ;
}
}
static inline bool F_195 ( const struct V_1 * V_2 , const int V_175 )
{
return ! ( V_175 & V_262 ) || ( V_175 & V_336 ) ||
F_2 ( V_2 ) -> V_107 != V_281 ;
}
static inline bool F_196 ( const struct V_1 * V_2 , const int V_175 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_175 & V_241 ) || V_30 -> V_113 < V_30 -> V_110 ) &&
! ( ( 1 << F_2 ( V_2 ) -> V_107 ) & ( V_229 | V_337 ) ) ;
}
static inline bool F_197 ( const struct V_29 * V_30 ,
const T_1 V_312 , const T_1 V_148 ,
const T_1 V_338 )
{
return F_47 ( V_312 , V_30 -> V_96 ) ||
F_47 ( V_148 , V_30 -> V_339 ) ||
( V_148 == V_30 -> V_339 && V_338 > V_30 -> V_340 ) ;
}
static int F_198 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_312 ,
T_1 V_148 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_175 = 0 ;
T_1 V_338 = F_149 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_187 ( ! F_6 ( V_4 ) -> V_43 ) )
V_338 <<= V_30 -> V_45 . V_341 ;
if ( F_197 ( V_30 , V_312 , V_148 , V_338 ) ) {
V_175 |= V_342 ;
F_199 ( V_30 , V_148 ) ;
if ( V_30 -> V_340 != V_338 ) {
V_30 -> V_340 = V_338 ;
V_30 -> V_343 = 0 ;
F_200 ( V_2 ) ;
if ( V_338 > V_30 -> V_141 ) {
V_30 -> V_141 = V_338 ;
F_166 ( V_2 , F_2 ( V_2 ) -> V_290 ) ;
}
}
}
V_30 -> V_96 = V_312 ;
return V_175 ;
}
static void F_201 ( struct V_29 * V_30 )
{
V_30 -> V_113 = F_9 ( V_30 -> V_113 , V_30 -> V_110 ) ;
V_30 -> V_114 = 0 ;
V_30 -> V_106 = 0 ;
F_12 ( V_30 ) ;
F_142 ( V_30 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
F_54 ( V_2 , 0 ) ;
}
static void F_203 ( struct V_1 * V_2 , int V_175 )
{
if ( V_175 & V_241 )
F_202 ( V_2 ) ;
else
F_153 ( V_2 , true ) ;
}
static bool F_204 ( struct V_1 * V_2 , int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_109 ( V_30 ) ;
if ( V_175 & V_232 )
F_2 ( V_2 ) -> V_226 = 0 ;
if ( ( V_175 & V_325 ) ||
( ( V_30 -> V_224 >= 2 ) && ( V_175 & V_311 ) ) )
V_30 -> V_109 = 0 ;
if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_174 ) ) {
F_121 ( V_2 , ( V_30 -> V_224 == 1 ? 2 : 3 ) , V_175 ) ;
return true ;
}
if ( ! F_115 ( V_30 ) ) {
if ( ! ( V_175 & V_261 ) && ( V_175 & V_262 ) )
return true ;
if ( ! ( V_175 & V_232 ) ) {
F_121 ( V_2 , ( V_30 -> V_224 == 1 ? 0 : 3 ) ,
V_175 ) ;
return true ;
}
} else {
if ( ! ( V_175 & V_232 ) && ( V_30 -> V_224 == 1 ) ) {
V_30 -> V_113 = F_9 ( V_30 -> V_113 ,
F_55 ( V_30 ) ) ;
return true ;
}
if ( ( V_30 -> V_224 >= 2 ) &&
( ! ( V_175 & V_344 ) ||
( ( V_175 & V_177 ) &&
! ( V_175 & V_176 ) ) ) ) {
if ( ! ( V_175 & V_344 ) &&
( V_175 & V_262 ) )
return true ;
F_121 ( V_2 , 3 , V_175 ) ;
return true ;
}
}
if ( V_30 -> V_224 == 1 ) {
V_30 -> V_113 = F_55 ( V_30 ) + 2 ;
V_30 -> V_224 = 2 ;
if ( ! F_136 ( V_2 ) )
F_121 ( V_2 , 2 , V_175 ) ;
return true ;
} else {
switch ( V_345 ) {
case 2 :
F_203 ( V_2 , V_175 ) ;
break;
case 1 :
F_201 ( V_30 ) ;
break;
default:
F_202 ( V_2 ) ;
break;
}
V_30 -> V_224 = 0 ;
V_30 -> V_109 = 0 ;
F_62 ( F_63 ( V_2 ) , V_346 ) ;
}
return false ;
}
static int F_205 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_175 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_155 = V_30 -> V_96 ;
T_1 V_148 = F_16 ( V_4 ) -> V_82 ;
T_1 V_312 = F_16 ( V_4 ) -> V_148 ;
bool V_304 = false ;
T_1 V_347 ;
T_1 V_318 ;
int V_348 ;
int V_303 = V_30 -> V_131 ;
int V_302 = 0 ;
bool V_349 = false ;
if ( F_40 ( V_312 , V_155 ) )
goto V_350;
if ( F_47 ( V_312 , V_30 -> V_98 ) )
goto V_351;
if ( V_30 -> V_244 )
F_180 ( V_2 ) ;
if ( F_47 ( V_312 , V_155 ) )
V_175 |= V_306 ;
if ( V_352 ) {
if ( V_6 -> V_107 < V_108 )
V_30 -> V_106 += V_312 - V_155 ;
else if ( V_6 -> V_107 == V_217 )
V_30 -> V_106 += F_9 ( V_312 - V_155 ,
V_30 -> V_288 ) ;
}
V_318 = V_30 -> V_130 ;
V_347 = F_55 ( V_30 ) ;
if ( ! ( V_175 & V_353 ) && F_47 ( V_312 , V_155 ) ) {
F_199 ( V_30 , V_148 ) ;
V_30 -> V_96 = V_312 ;
V_175 |= V_342 ;
F_120 ( V_2 , V_354 ) ;
F_62 ( F_63 ( V_2 ) , V_355 ) ;
} else {
if ( V_148 != F_16 ( V_4 ) -> V_84 )
V_175 |= V_356 ;
else
F_62 ( F_63 ( V_2 ) , V_357 ) ;
V_175 |= F_198 ( V_2 , V_4 , V_312 , V_148 ) ;
if ( F_16 ( V_4 ) -> V_136 )
V_175 |= F_105 ( V_2 , V_4 , V_155 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_175 |= V_241 ;
F_120 ( V_2 , V_358 ) ;
}
V_2 -> V_359 = 0 ;
V_6 -> V_360 = 0 ;
V_30 -> V_361 = V_71 ;
V_348 = V_30 -> V_210 ;
if ( ! V_348 )
goto V_362;
V_175 |= F_185 ( V_2 , V_318 , V_155 ) ;
V_302 = V_348 - V_30 -> V_210 ;
if ( V_30 -> V_224 )
V_349 = F_204 ( V_2 , V_175 ) ;
if ( F_40 ( V_30 -> V_174 , V_30 -> V_96 ) )
V_30 -> V_174 = 0 ;
if ( F_195 ( V_2 , V_175 ) ) {
if ( ( V_175 & V_232 ) && ! V_349 &&
F_196 ( V_2 , V_175 ) )
F_179 ( V_2 , V_312 , V_347 ) ;
V_304 = ! ( V_175 & ( V_306 | V_262 ) ) ;
F_174 ( V_2 , V_302 , V_303 ,
V_304 , V_175 ) ;
} else {
if ( ( V_175 & V_232 ) && ! V_349 )
F_179 ( V_2 , V_312 , V_347 ) ;
}
if ( ( V_175 & V_344 ) || ! ( V_175 & V_262 ) ) {
struct V_99 * V_100 = F_206 ( V_2 ) ;
if ( V_100 )
F_207 ( V_100 ) ;
}
return 1 ;
V_362:
if ( V_175 & V_211 )
F_174 ( V_2 , V_302 , V_303 ,
V_304 , V_175 ) ;
if ( F_74 ( V_2 ) )
F_193 ( V_2 ) ;
return 1 ;
V_351:
F_208 ( V_2 , L_12 , V_312 , V_30 -> V_96 , V_30 -> V_98 ) ;
return - 1 ;
V_350:
if ( F_16 ( V_4 ) -> V_136 ) {
V_175 |= F_105 ( V_2 , V_4 , V_155 ) ;
F_174 ( V_2 , V_302 , V_303 ,
V_304 , V_175 ) ;
}
F_208 ( V_2 , L_13 , V_312 , V_30 -> V_96 , V_30 -> V_98 ) ;
return 0 ;
}
void F_209 ( const struct V_3 * V_4 , struct V_363 * V_364 ,
const T_3 * * V_365 , int V_366 ,
struct V_367 * V_368 )
{
const unsigned char * V_201 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_369 = ( V_41 -> V_370 * 4 ) - sizeof( struct V_15 ) ;
V_201 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_364 -> V_264 = 0 ;
while ( V_369 > 0 ) {
int V_371 = * V_201 ++ ;
int V_372 ;
switch ( V_371 ) {
case V_373 :
return;
case V_374 :
V_369 -- ;
continue;
default:
V_372 = * V_201 ++ ;
if ( V_372 < 2 )
return;
if ( V_372 > V_369 )
return;
switch ( V_371 ) {
case V_375 :
if ( V_372 == V_376 && V_41 -> V_43 && ! V_366 ) {
T_7 V_377 = F_210 ( V_201 ) ;
if ( V_377 ) {
if ( V_364 -> V_378 &&
V_364 -> V_378 < V_377 )
V_377 = V_364 -> V_378 ;
V_364 -> V_46 = V_377 ;
}
}
break;
case V_379 :
if ( V_372 == V_380 && V_41 -> V_43 &&
! V_366 && V_381 ) {
T_8 V_341 = * ( T_8 * ) V_201 ;
V_364 -> V_382 = 1 ;
if ( V_341 > 14 ) {
F_211 ( L_14 ,
V_383 ,
V_341 ) ;
V_341 = 14 ;
}
V_364 -> V_341 = V_341 ;
}
break;
case V_384 :
if ( ( V_372 == V_385 ) &&
( ( V_366 && V_364 -> V_386 ) ||
( ! V_366 && V_387 ) ) ) {
V_364 -> V_264 = 1 ;
V_364 -> V_388 = F_76 ( V_201 ) ;
V_364 -> V_83 = F_76 ( V_201 + 4 ) ;
}
break;
case V_389 :
if ( V_372 == V_390 && V_41 -> V_43 &&
! V_366 && V_391 ) {
V_364 -> V_117 = V_392 ;
F_212 ( V_364 ) ;
}
break;
case V_393 :
if ( ( V_372 >= ( V_204 + V_394 ) ) &&
! ( ( V_372 - V_204 ) % V_394 ) &&
V_364 -> V_117 ) {
F_16 ( V_4 ) -> V_136 = ( V_201 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_213
case V_395 :
break;
#endif
case V_396 :
switch ( V_372 ) {
case V_397 :
break;
case V_398 :
break;
case V_399 + 0 :
case V_399 + 2 :
case V_399 + 4 :
case V_399 + 6 :
case V_400 :
V_364 -> V_401 = V_372 ;
* V_365 = V_201 ;
break;
default:
break;
}
break;
case V_402 :
if ( V_372 < V_403 ||
F_210 ( V_201 ) != V_404 ||
V_368 == NULL || ! V_41 -> V_43 || ( V_372 & 1 ) )
break;
V_368 -> V_10 = V_372 - V_403 ;
if ( V_368 -> V_10 >= V_405 &&
V_368 -> V_10 <= V_406 )
memcpy ( V_368 -> V_407 , V_201 + 2 , V_368 -> V_10 ) ;
else if ( V_368 -> V_10 != 0 )
V_368 -> V_10 = - 1 ;
break;
}
V_201 += V_372 - 2 ;
V_369 -= V_372 ;
}
}
}
static bool F_214 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_201 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_201 == F_215 ( ( V_374 << 24 ) | ( V_374 << 16 )
| ( V_384 << 8 ) | V_385 ) ) {
V_30 -> V_45 . V_264 = 1 ;
++ V_201 ;
V_30 -> V_45 . V_388 = F_216 ( * V_201 ) ;
++ V_201 ;
V_30 -> V_45 . V_83 = F_216 ( * V_201 ) ;
return true ;
}
return false ;
}
static bool F_217 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 ,
struct V_29 * V_30 , const T_3 * * V_365 )
{
if ( V_41 -> V_370 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_264 = 0 ;
return false ;
} else if ( V_30 -> V_45 . V_386 &&
V_41 -> V_370 == ( ( sizeof( * V_41 ) + V_408 ) / 4 ) ) {
if ( F_214 ( V_30 , V_41 ) )
return true ;
}
F_209 ( V_4 , & V_30 -> V_45 , V_365 , 1 , NULL ) ;
return true ;
}
const T_3 * F_218 ( const struct V_15 * V_41 )
{
int V_369 = ( V_41 -> V_370 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_201 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_369 < V_409 )
return NULL ;
while ( V_369 > 0 ) {
int V_371 = * V_201 ++ ;
int V_372 ;
switch( V_371 ) {
case V_373 :
return NULL ;
case V_374 :
V_369 -- ;
continue;
default:
V_372 = * V_201 ++ ;
if ( V_372 < 2 || V_372 > V_369 )
return NULL ;
if ( V_371 == V_395 )
return V_372 == V_409 ? V_201 : NULL ;
}
V_201 += V_372 - 2 ;
V_369 -= V_372 ;
}
return NULL ;
}
static inline void F_219 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_410 = V_30 -> V_45 . V_388 ;
V_30 -> V_45 . V_411 = F_220 () ;
}
static inline void F_221 ( struct V_29 * V_30 , T_1 V_82 )
{
if ( V_30 -> V_45 . V_264 && ! F_47 ( V_82 , V_30 -> V_412 ) ) {
if ( F_222 ( & V_30 -> V_45 , 0 ) )
F_219 ( V_30 ) ;
}
}
static int F_223 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
T_1 V_312 = F_16 ( V_4 ) -> V_148 ;
return (
( V_41 -> V_312 && V_82 == F_16 ( V_4 ) -> V_84 && V_82 == V_30 -> V_81 ) &&
V_312 == V_30 -> V_96 &&
! F_197 ( V_30 , V_312 , V_82 , F_149 ( V_41 -> V_52 ) << V_30 -> V_45 . V_341 ) &&
( T_5 ) ( V_30 -> V_45 . V_410 - V_30 -> V_45 . V_388 ) <= ( F_2 ( V_2 ) -> V_90 * 1024 ) / V_413 ) ;
}
static inline bool F_224 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_222 ( & V_30 -> V_45 , V_414 ) &&
! F_223 ( V_2 , V_4 ) ;
}
static inline bool F_225 ( const struct V_29 * V_30 , T_1 V_82 , T_1 V_84 )
{
return ! F_40 ( V_84 , V_30 -> V_412 ) &&
! F_47 ( V_82 , V_30 -> V_81 + F_226 ( V_30 ) ) ;
}
static void F_227 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_415 ) {
case V_416 :
V_2 -> V_417 = V_418 ;
break;
case V_419 :
V_2 -> V_417 = V_420 ;
break;
case V_421 :
return;
default:
V_2 -> V_417 = V_422 ;
}
F_228 () ;
if ( ! F_229 ( V_2 , V_423 ) )
V_2 -> V_424 ( V_2 ) ;
F_230 ( V_2 ) ;
}
static void F_231 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_425 |= V_426 ;
F_232 ( V_2 , V_427 ) ;
switch ( V_2 -> V_415 ) {
case V_428 :
case V_429 :
F_233 ( V_2 , V_419 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_419 :
case V_430 :
break;
case V_431 :
break;
case V_432 :
F_234 ( V_2 ) ;
F_233 ( V_2 , V_430 ) ;
break;
case V_433 :
F_234 ( V_2 ) ;
F_235 ( V_2 , V_434 , 0 ) ;
break;
default:
F_236 ( L_15 ,
V_383 , V_2 -> V_415 ) ;
break;
}
F_237 ( & V_30 -> V_435 ) ;
if ( F_138 ( V_30 ) )
F_212 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
if ( ! F_229 ( V_2 , V_423 ) ) {
V_2 -> V_436 ( V_2 ) ;
if ( V_2 -> V_425 == V_437 ||
V_2 -> V_415 == V_421 )
F_238 ( V_2 , V_438 , V_439 ) ;
else
F_238 ( V_2 , V_438 , V_440 ) ;
}
}
static inline bool F_239 ( struct V_194 * V_153 , T_1 V_82 ,
T_1 V_84 )
{
if ( ! F_47 ( V_82 , V_153 -> V_84 ) && ! F_47 ( V_153 -> V_140 , V_84 ) ) {
if ( F_40 ( V_82 , V_153 -> V_140 ) )
V_153 -> V_140 = V_82 ;
if ( F_47 ( V_84 , V_153 -> V_84 ) )
V_153 -> V_84 = V_84 ;
return true ;
}
return false ;
}
static void F_240 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_138 ( V_30 ) && V_441 ) {
int V_123 ;
if ( F_40 ( V_82 , V_30 -> V_81 ) )
V_123 = V_442 ;
else
V_123 = V_443 ;
F_62 ( F_63 ( V_2 ) , V_123 ) ;
V_30 -> V_45 . V_444 = 1 ;
V_30 -> V_445 [ 0 ] . V_140 = V_82 ;
V_30 -> V_445 [ 0 ] . V_84 = V_84 ;
}
}
static void F_241 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_444 )
F_240 ( V_2 , V_82 , V_84 ) ;
else
F_239 ( V_30 -> V_445 , V_82 , V_84 ) ;
}
static void F_242 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_62 ( F_63 ( V_2 ) , V_446 ) ;
F_10 ( V_2 ) ;
if ( F_138 ( V_30 ) && V_441 ) {
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
int V_447 ;
struct V_194 * V_153 = & V_30 -> V_448 [ 0 ] ;
struct V_194 * V_449 = V_153 + 1 ;
for ( V_447 = 1 ; V_447 < V_30 -> V_45 . V_154 ; ) {
if ( F_239 ( V_153 , V_449 -> V_140 , V_449 -> V_84 ) ) {
int V_207 ;
V_30 -> V_45 . V_154 -- ;
for ( V_207 = V_447 ; V_207 < V_30 -> V_45 . V_154 ; V_207 ++ )
V_153 [ V_207 ] = V_153 [ V_207 + 1 ] ;
continue;
}
V_447 ++ , V_449 ++ ;
}
}
static void F_244 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_194 * V_153 = & V_30 -> V_448 [ 0 ] ;
int V_450 = V_30 -> V_45 . V_154 ;
int V_447 ;
if ( ! V_450 )
goto V_451;
for ( V_447 = 0 ; V_447 < V_450 ; V_447 ++ , V_153 ++ ) {
if ( F_239 ( V_153 , V_82 , V_84 ) ) {
for (; V_447 > 0 ; V_447 -- , V_153 -- )
F_108 ( * V_153 , * ( V_153 - 1 ) ) ;
if ( V_450 > 1 )
F_243 ( V_30 ) ;
return;
}
}
if ( V_447 >= V_203 ) {
V_447 -- ;
V_30 -> V_45 . V_154 -- ;
V_153 -- ;
}
for (; V_447 > 0 ; V_447 -- , V_153 -- )
* V_153 = * ( V_153 - 1 ) ;
V_451:
V_153 -> V_140 = V_82 ;
V_153 -> V_84 = V_84 ;
V_30 -> V_45 . V_154 ++ ;
}
static void F_245 ( struct V_29 * V_30 )
{
struct V_194 * V_153 = & V_30 -> V_448 [ 0 ] ;
int V_154 = V_30 -> V_45 . V_154 ;
int V_447 ;
if ( F_246 ( & V_30 -> V_435 ) ) {
V_30 -> V_45 . V_154 = 0 ;
return;
}
for ( V_447 = 0 ; V_447 < V_154 ; ) {
if ( ! F_40 ( V_30 -> V_81 , V_153 -> V_140 ) ) {
int V_207 ;
F_106 ( F_40 ( V_30 -> V_81 , V_153 -> V_84 ) ) ;
for ( V_207 = V_447 + 1 ; V_207 < V_154 ; V_207 ++ )
V_30 -> V_448 [ V_207 - 1 ] = V_30 -> V_448 [ V_207 ] ;
V_154 -- ;
continue;
}
V_447 ++ ;
V_153 ++ ;
}
V_30 -> V_45 . V_154 = V_154 ;
}
static void F_247 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_452 = V_30 -> V_81 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_248 ( & V_30 -> V_435 ) ) != NULL ) {
if ( F_47 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_452 ) ) {
T_2 V_444 = V_452 ;
if ( F_40 ( F_16 ( V_4 ) -> V_84 , V_452 ) )
V_452 = F_16 ( V_4 ) -> V_84 ;
F_241 ( V_2 , F_16 ( V_4 ) -> V_82 , V_444 ) ;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_208 ( V_2 , L_16 ) ;
F_249 ( V_4 , & V_30 -> V_435 ) ;
F_250 ( V_4 ) ;
continue;
}
F_208 ( V_2 , L_17 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_249 ( V_4 , & V_30 -> V_435 ) ;
F_251 ( & V_2 -> V_453 , V_4 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( F_6 ( V_4 ) -> V_454 )
F_231 ( V_2 ) ;
}
}
static int F_252 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_455 )
{
if ( F_35 ( & V_2 -> V_72 ) > V_2 -> V_62 ||
! F_253 ( V_2 , V_4 , V_455 ) ) {
if ( F_254 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_253 ( V_2 , V_4 , V_455 ) ) {
if ( ! F_255 ( V_2 ) )
return - 1 ;
if ( ! F_253 ( V_2 , V_4 , V_455 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_256 ( struct V_1 * V_2 ,
struct V_3 * V_456 ,
struct V_3 * V_457 ,
bool * V_458 )
{
int V_294 ;
* V_458 = false ;
if ( F_6 ( V_457 ) -> V_454 )
return false ;
if ( F_16 ( V_457 ) -> V_82 != F_16 ( V_456 ) -> V_84 )
return false ;
if ( ! F_257 ( V_456 , V_457 , V_458 , & V_294 ) )
return false ;
F_258 ( V_294 , & V_2 -> V_72 ) ;
F_259 ( V_2 , V_294 ) ;
F_62 ( F_63 ( V_2 ) , V_459 ) ;
F_16 ( V_456 ) -> V_84 = F_16 ( V_457 ) -> V_84 ;
F_16 ( V_456 ) -> V_148 = F_16 ( V_457 ) -> V_148 ;
return true ;
}
static void F_260 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_460 ;
T_1 V_82 , V_84 ;
F_15 ( V_30 , V_4 ) ;
if ( F_94 ( F_252 ( V_2 , V_4 , V_4 -> V_51 ) ) ) {
F_62 ( F_63 ( V_2 ) , V_461 ) ;
F_250 ( V_4 ) ;
return;
}
V_30 -> V_343 = 0 ;
F_44 ( V_2 ) ;
F_62 ( F_63 ( V_2 ) , V_462 ) ;
F_208 ( V_2 , L_18 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_460 = F_261 ( & V_30 -> V_435 ) ;
if ( ! V_460 ) {
if ( F_138 ( V_30 ) ) {
V_30 -> V_45 . V_154 = 1 ;
V_30 -> V_448 [ 0 ] . V_140 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_448 [ 0 ] . V_84 =
F_16 ( V_4 ) -> V_84 ;
}
F_262 ( & V_30 -> V_435 , V_4 ) ;
goto V_463;
}
V_82 = F_16 ( V_4 ) -> V_82 ;
V_84 = F_16 ( V_4 ) -> V_84 ;
if ( V_82 == F_16 ( V_460 ) -> V_84 ) {
bool V_458 ;
if ( ! F_256 ( V_2 , V_460 , V_4 , & V_458 ) ) {
F_263 ( & V_30 -> V_435 , V_460 , V_4 ) ;
} else {
F_264 ( V_4 , V_458 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_45 . V_154 ||
V_30 -> V_448 [ 0 ] . V_84 != V_82 )
goto V_464;
V_30 -> V_448 [ 0 ] . V_84 = V_84 ;
goto V_463;
}
while ( 1 ) {
if ( ! F_47 ( F_16 ( V_460 ) -> V_82 , V_82 ) )
break;
if ( F_265 ( & V_30 -> V_435 , V_460 ) ) {
V_460 = NULL ;
break;
}
V_460 = F_266 ( & V_30 -> V_435 , V_460 ) ;
}
if ( V_460 && F_40 ( V_82 , F_16 ( V_460 ) -> V_84 ) ) {
if ( ! F_47 ( V_84 , F_16 ( V_460 ) -> V_84 ) ) {
F_62 ( F_63 ( V_2 ) , V_465 ) ;
F_250 ( V_4 ) ;
V_4 = NULL ;
F_240 ( V_2 , V_82 , V_84 ) ;
goto V_464;
}
if ( F_47 ( V_82 , F_16 ( V_460 ) -> V_82 ) ) {
F_240 ( V_2 , V_82 ,
F_16 ( V_460 ) -> V_84 ) ;
} else {
if ( F_265 ( & V_30 -> V_435 ,
V_460 ) )
V_460 = NULL ;
else
V_460 = F_266 (
& V_30 -> V_435 ,
V_460 ) ;
}
}
if ( ! V_460 )
F_262 ( & V_30 -> V_435 , V_4 ) ;
else
F_263 ( & V_30 -> V_435 , V_460 , V_4 ) ;
while ( ! F_267 ( & V_30 -> V_435 , V_4 ) ) {
V_460 = F_268 ( & V_30 -> V_435 , V_4 ) ;
if ( ! F_47 ( V_84 , F_16 ( V_460 ) -> V_82 ) )
break;
if ( F_40 ( V_84 , F_16 ( V_460 ) -> V_84 ) ) {
F_241 ( V_2 , F_16 ( V_460 ) -> V_82 ,
V_84 ) ;
break;
}
F_249 ( V_460 , & V_30 -> V_435 ) ;
F_241 ( V_2 , F_16 ( V_460 ) -> V_82 ,
F_16 ( V_460 ) -> V_84 ) ;
F_62 ( F_63 ( V_2 ) , V_465 ) ;
F_250 ( V_460 ) ;
}
V_464:
if ( F_138 ( V_30 ) )
F_244 ( V_2 , V_82 , V_84 ) ;
V_463:
if ( V_4 )
F_269 ( V_4 , V_2 ) ;
}
static int T_10 F_270 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_466 ,
bool * V_458 )
{
int V_467 ;
struct V_3 * V_468 = F_261 ( & V_2 -> V_453 ) ;
F_271 ( V_4 , V_466 ) ;
V_467 = ( V_468 &&
F_256 ( V_2 , V_468 , V_4 , V_458 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( ! V_467 ) {
F_251 ( & V_2 -> V_453 , V_4 ) ;
F_269 ( V_4 , V_2 ) ;
}
return V_467 ;
}
int F_272 ( struct V_1 * V_2 , struct V_469 * V_265 , T_11 V_455 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_458 ;
V_4 = F_273 ( V_455 + sizeof( * V_41 ) , V_2 -> V_470 ) ;
if ( ! V_4 )
goto V_163;
if ( F_252 ( V_2 , V_4 , V_455 + sizeof( * V_41 ) ) )
goto V_471;
V_41 = (struct V_15 * ) F_274 ( V_4 , sizeof( * V_41 ) ) ;
F_275 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_276 ( F_274 ( V_4 , V_455 ) , V_265 -> V_472 , V_455 ) )
goto V_471;
F_16 ( V_4 ) -> V_82 = F_7 ( V_2 ) -> V_81 ;
F_16 ( V_4 ) -> V_84 = F_16 ( V_4 ) -> V_82 + V_455 ;
F_16 ( V_4 ) -> V_148 = F_7 ( V_2 ) -> V_96 - 1 ;
if ( F_270 ( V_2 , V_4 , sizeof( * V_41 ) , & V_458 ) ) {
F_277 ( V_458 ) ;
F_250 ( V_4 ) ;
}
return V_455 ;
V_471:
F_278 ( V_4 ) ;
V_163:
return - V_473 ;
}
static void F_279 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_467 = - 1 ;
bool V_458 = false ;
if ( F_16 ( V_4 ) -> V_82 == F_16 ( V_4 ) -> V_84 )
goto V_474;
F_280 ( V_4 ) ;
F_271 ( V_4 , V_41 -> V_370 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_444 = 0 ;
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 ) {
if ( F_226 ( V_30 ) == 0 )
goto V_475;
if ( V_30 -> V_476 . V_477 == V_478 &&
V_30 -> V_85 == V_30 -> V_81 && V_30 -> V_476 . V_10 &&
F_281 ( V_2 ) && ! V_30 -> V_479 ) {
int V_480 = F_37 (unsigned int, skb->len,
tp->ucopy.len) ;
F_282 ( V_481 ) ;
F_283 () ;
if ( ! F_284 ( V_4 , 0 , V_30 -> V_476 . V_482 , V_480 ) ) {
V_30 -> V_476 . V_10 -= V_480 ;
V_30 -> V_85 += V_480 ;
V_467 = ( V_480 == V_4 -> V_10 ) ;
F_42 ( V_2 ) ;
}
F_285 () ;
}
if ( V_467 <= 0 ) {
V_483:
if ( V_467 < 0 &&
F_252 ( V_2 , V_4 , V_4 -> V_51 ) )
goto V_474;
V_467 = F_270 ( V_2 , V_4 , 0 , & V_458 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( V_4 -> V_10 )
F_43 ( V_2 , V_4 ) ;
if ( V_41 -> V_454 )
F_231 ( V_2 ) ;
if ( ! F_246 ( & V_30 -> V_435 ) ) {
F_247 ( V_2 ) ;
if ( F_246 ( & V_30 -> V_435 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_154 )
F_245 ( V_30 ) ;
F_200 ( V_2 ) ;
if ( V_467 > 0 )
F_264 ( V_4 , V_458 ) ;
if ( ! F_229 ( V_2 , V_423 ) )
V_2 -> V_484 ( V_2 , 0 ) ;
return;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_62 ( F_63 ( V_2 ) , V_446 ) ;
F_240 ( V_2 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_475:
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
V_474:
F_250 ( V_4 ) ;
return;
}
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 + F_226 ( V_30 ) ) )
goto V_475;
F_10 ( V_2 ) ;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_208 ( V_2 , L_19 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_240 ( V_2 , F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ;
if ( ! F_226 ( V_30 ) )
goto V_475;
goto V_483;
}
F_260 ( V_2 , V_4 ) ;
}
static struct V_3 * F_286 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_485 * V_486 )
{
struct V_3 * V_487 = NULL ;
if ( ! F_267 ( V_486 , V_4 ) )
V_487 = F_268 ( V_486 , V_4 ) ;
F_249 ( V_4 , V_486 ) ;
F_250 ( V_4 ) ;
F_62 ( F_63 ( V_2 ) , V_488 ) ;
return V_487 ;
}
static void
F_287 ( struct V_1 * V_2 , struct V_485 * V_486 ,
struct V_3 * V_489 , struct V_3 * V_468 ,
T_1 V_490 , T_1 V_463 )
{
struct V_3 * V_4 , * V_491 ;
bool V_492 ;
V_4 = V_489 ;
V_493:
V_492 = true ;
F_288 (list, skb, n) {
if ( V_4 == V_468 )
break;
if ( ! F_40 ( V_490 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_286 ( V_2 , V_4 , V_486 ) ;
if ( ! V_4 )
break;
goto V_493;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_454 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_40 ( F_16 ( V_4 ) -> V_82 , V_490 ) ) ) {
V_492 = false ;
break;
}
if ( ! F_267 ( V_486 , V_4 ) ) {
struct V_3 * V_487 = F_268 ( V_486 , V_4 ) ;
if ( V_487 != V_468 &&
F_16 ( V_4 ) -> V_84 != F_16 ( V_487 ) -> V_82 ) {
V_492 = false ;
break;
}
}
V_490 = F_16 ( V_4 ) -> V_84 ;
}
if ( V_492 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_454 )
return;
while ( F_40 ( V_490 , V_463 ) ) {
struct V_3 * V_494 ;
unsigned int V_495 = F_289 ( V_4 ) ;
int V_496 = F_290 ( V_495 , 0 ) ;
if ( V_496 < 0 )
return;
if ( V_463 - V_490 < V_496 )
V_496 = V_463 - V_490 ;
V_494 = F_273 ( V_496 + V_495 , V_497 ) ;
if ( ! V_494 )
return;
F_291 ( V_494 , F_292 ( V_4 ) - V_4 -> V_489 ) ;
F_293 ( V_494 , ( F_294 ( V_4 ) -
V_4 -> V_489 ) ) ;
F_295 ( V_494 , ( F_4 ( V_4 ) -
V_4 -> V_489 ) ) ;
F_296 ( V_494 , V_495 ) ;
memcpy ( V_494 -> V_489 , V_4 -> V_489 , V_495 ) ;
memcpy ( V_494 -> V_498 , V_4 -> V_498 , sizeof( V_4 -> V_498 ) ) ;
F_16 ( V_494 ) -> V_82 = F_16 ( V_494 ) -> V_84 = V_490 ;
F_297 ( V_486 , V_4 , V_494 ) ;
F_269 ( V_494 , V_2 ) ;
while ( V_496 > 0 ) {
int V_499 = V_490 - F_16 ( V_4 ) -> V_82 ;
int V_455 = F_16 ( V_4 ) -> V_84 - V_490 ;
F_83 ( V_499 < 0 ) ;
if ( V_455 > 0 ) {
V_455 = F_9 ( V_496 , V_455 ) ;
if ( F_298 ( V_4 , V_499 , F_274 ( V_494 , V_455 ) , V_455 ) )
F_299 () ;
F_16 ( V_494 ) -> V_84 += V_455 ;
V_496 -= V_455 ;
V_490 += V_455 ;
}
if ( ! F_40 ( V_490 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_286 ( V_2 , V_4 , V_486 ) ;
if ( ! V_4 ||
V_4 == V_468 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_454 )
return;
}
}
}
}
static void F_300 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_248 ( & V_30 -> V_435 ) ;
struct V_3 * V_489 ;
T_1 V_490 , V_463 ;
if ( V_4 == NULL )
return;
V_490 = F_16 ( V_4 ) -> V_82 ;
V_463 = F_16 ( V_4 ) -> V_84 ;
V_489 = V_4 ;
for (; ; ) {
struct V_3 * V_487 = NULL ;
if ( ! F_267 ( & V_30 -> V_435 , V_4 ) )
V_487 = F_268 ( & V_30 -> V_435 , V_4 ) ;
V_4 = V_487 ;
if ( ! V_4 ||
F_47 ( F_16 ( V_4 ) -> V_82 , V_463 ) ||
F_40 ( F_16 ( V_4 ) -> V_84 , V_490 ) ) {
F_287 ( V_2 , & V_30 -> V_435 ,
V_489 , V_4 , V_490 , V_463 ) ;
V_489 = V_4 ;
if ( ! V_4 )
break;
V_490 = F_16 ( V_4 ) -> V_82 ;
V_463 = F_16 ( V_4 ) -> V_84 ;
} else {
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_490 ) )
V_490 = F_16 ( V_4 ) -> V_82 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_463 ) )
V_463 = F_16 ( V_4 ) -> V_84 ;
}
}
}
static bool F_255 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_500 = false ;
if ( ! F_246 ( & V_30 -> V_435 ) ) {
F_62 ( F_63 ( V_2 ) , V_501 ) ;
F_237 ( & V_30 -> V_435 ) ;
if ( V_30 -> V_45 . V_117 )
F_212 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
V_500 = true ;
}
return V_500 ;
}
static int F_254 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_208 ( V_2 , L_20 , V_30 -> V_85 ) ;
F_62 ( F_63 ( V_2 ) , V_502 ) ;
if ( F_35 ( & V_2 -> V_72 ) >= V_2 -> V_62 )
F_32 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_300 ( V_2 ) ;
if ( ! F_246 ( & V_2 -> V_453 ) )
F_287 ( V_2 , & V_2 -> V_453 ,
F_248 ( & V_2 -> V_453 ) ,
NULL ,
V_30 -> V_85 , V_30 -> V_81 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_255 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_62 ( F_63 ( V_2 ) , V_503 ) ;
V_30 -> V_343 = 0 ;
return - 1 ;
}
void F_301 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_107 == V_281 &&
V_2 -> V_504 && ! F_302 ( V_505 , & V_2 -> V_504 -> V_333 ) ) {
T_1 V_506 = F_52 ( V_30 , F_206 ( V_2 ) ) ;
T_1 V_507 = F_31 ( V_30 -> V_508 , V_506 ) ;
if ( V_507 < V_30 -> V_113 ) {
V_30 -> V_110 = F_119 ( V_2 ) ;
V_30 -> V_113 = ( V_30 -> V_113 + V_507 ) >> 1 ;
}
V_30 -> V_508 = 0 ;
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
if ( V_30 -> V_210 >= V_30 -> V_113 )
return false ;
return true ;
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_303 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_288 ) +
V_47 ) ;
int V_509 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_509 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_70 = V_71 ;
}
V_2 -> V_510 ( V_2 ) ;
}
static void F_305 ( struct V_1 * V_2 )
{
if ( F_229 ( V_2 , V_511 ) ) {
F_306 ( V_2 , V_511 ) ;
if ( V_2 -> V_504 &&
F_302 ( V_505 , & V_2 -> V_504 -> V_333 ) )
F_304 ( V_2 ) ;
}
}
static inline void F_307 ( struct V_1 * V_2 )
{
F_308 ( V_2 ) ;
F_305 ( V_2 ) ;
}
static void F_309 ( struct V_1 * V_2 , int V_512 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_81 - V_30 -> V_412 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_310 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_512 && F_248 ( & V_30 -> V_435 ) ) ) {
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
T_1 V_201 = F_149 ( V_41 -> V_513 ) ;
if ( V_201 && ! V_514 )
V_201 -- ;
V_201 += F_216 ( V_41 -> V_82 ) ;
if ( F_47 ( V_30 -> V_85 , V_201 ) )
return;
if ( F_40 ( V_201 , V_30 -> V_81 ) )
return;
if ( V_30 -> V_479 && ! F_47 ( V_201 , V_30 -> V_515 ) )
return;
F_315 ( V_2 ) ;
if ( V_30 -> V_515 == V_30 -> V_85 && V_30 -> V_479 &&
! F_229 ( V_2 , V_516 ) && V_30 -> V_85 != V_30 -> V_81 ) {
struct V_3 * V_4 = F_248 ( & V_2 -> V_453 ) ;
V_30 -> V_85 ++ ;
if ( V_4 && ! F_40 ( V_30 -> V_85 , F_16 ( V_4 ) -> V_84 ) ) {
F_249 ( V_4 , & V_2 -> V_453 ) ;
F_250 ( V_4 ) ;
}
}
V_30 -> V_479 = V_517 ;
V_30 -> V_515 = V_201 ;
V_30 -> V_343 = 0 ;
}
static void F_316 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_518 )
F_314 ( V_2 , V_41 ) ;
if ( V_30 -> V_479 == V_517 ) {
T_1 V_201 = V_30 -> V_515 - F_216 ( V_41 -> V_82 ) + ( V_41 -> V_370 * 4 ) -
V_41 -> V_43 ;
if ( V_201 < V_4 -> V_10 ) {
T_3 V_197 ;
if ( F_298 ( V_4 , V_201 , & V_197 , 1 ) )
F_299 () ;
V_30 -> V_479 = V_519 | V_197 ;
if ( ! F_229 ( V_2 , V_423 ) )
V_2 -> V_484 ( V_2 , 0 ) ;
}
}
}
static int F_317 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_520 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_480 = V_4 -> V_10 - V_520 ;
int V_163 ;
F_283 () ;
if ( F_318 ( V_4 ) )
V_163 = F_284 ( V_4 , V_520 , V_30 -> V_476 . V_482 , V_480 ) ;
else
V_163 = F_319 ( V_4 , V_520 ,
V_30 -> V_476 . V_482 ) ;
if ( ! V_163 ) {
V_30 -> V_476 . V_10 -= V_480 ;
V_30 -> V_85 += V_480 ;
F_42 ( V_2 ) ;
}
F_285 () ;
return V_163 ;
}
static T_12 F_320 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_12 V_521 ;
if ( F_281 ( V_2 ) ) {
F_283 () ;
V_521 = F_321 ( V_4 ) ;
F_285 () ;
} else {
V_521 = F_321 ( V_4 ) ;
}
return V_521 ;
}
static inline bool F_322 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_318 ( V_4 ) &&
F_320 ( V_2 , V_4 ) ;
}
static bool F_323 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_520 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_480 = V_4 -> V_10 - V_520 ;
int V_522 ;
bool V_523 = false ;
if ( V_30 -> V_476 . V_524 )
return false ;
if ( ! V_30 -> V_476 . V_525 && V_30 -> V_476 . V_526 )
V_30 -> V_476 . V_525 = F_324 () ;
if ( V_30 -> V_476 . V_525 && F_318 ( V_4 ) ) {
V_522 = F_325 ( V_30 -> V_476 . V_525 ,
V_4 , V_520 ,
V_30 -> V_476 . V_482 , V_480 ,
V_30 -> V_476 . V_526 ) ;
if ( V_522 < 0 )
goto V_192;
V_30 -> V_476 . V_522 = V_522 ;
V_523 = true ;
V_30 -> V_476 . V_10 -= V_480 ;
V_30 -> V_85 += V_480 ;
F_42 ( V_2 ) ;
if ( ( V_30 -> V_476 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_527 ) ||
( F_35 ( & V_2 -> V_72 ) > ( V_2 -> V_62 >> 1 ) ) ) {
V_30 -> V_476 . V_524 = 1 ;
V_2 -> V_484 ( V_2 , 0 ) ;
}
} else if ( V_480 > 0 ) {
V_30 -> V_476 . V_524 = 1 ;
V_2 -> V_484 ( V_2 , 0 ) ;
}
V_192:
return V_523 ;
}
static void F_326 ( struct V_1 * V_2 )
{
static T_1 V_528 ;
static unsigned int V_529 ;
T_1 V_88 = V_243 / V_413 ;
if ( V_88 != V_528 ) {
V_528 = V_88 ;
V_529 = 0 ;
}
if ( ++ V_529 <= V_530 ) {
F_62 ( F_63 ( V_2 ) , V_531 ) ;
F_234 ( V_2 ) ;
}
}
static bool F_327 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_532 )
{
const T_3 * V_533 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_217 ( V_4 , V_41 , V_30 , & V_533 ) &&
V_30 -> V_45 . V_264 &&
F_224 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_534 ) {
F_62 ( F_63 ( V_2 ) , V_535 ) ;
F_242 ( V_2 , V_4 ) ;
goto V_536;
}
}
if ( ! F_225 ( V_30 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) {
if ( ! V_41 -> V_534 ) {
if ( V_41 -> V_43 )
goto V_537;
F_242 ( V_2 , V_4 ) ;
}
goto V_536;
}
if ( V_41 -> V_534 ) {
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 )
F_227 ( V_2 ) ;
else
F_326 ( V_2 ) ;
goto V_536;
}
F_221 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_41 -> V_43 ) {
V_537:
if ( V_532 )
F_328 ( F_63 ( V_2 ) , V_538 ) ;
F_62 ( F_63 ( V_2 ) , V_539 ) ;
F_326 ( V_2 ) ;
goto V_536;
}
return true ;
V_536:
F_250 ( V_4 ) ;
return false ;
}
int F_329 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_94 ( V_2 -> V_540 == NULL ) )
F_2 ( V_2 ) -> V_541 -> V_542 ( V_2 , V_4 ) ;
V_30 -> V_45 . V_264 = 0 ;
if ( ( F_5 ( V_41 ) & V_543 ) == V_30 -> V_343 &&
F_16 ( V_4 ) -> V_82 == V_30 -> V_81 &&
! F_47 ( F_16 ( V_4 ) -> V_148 , V_30 -> V_98 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_408 ) {
if ( ! F_214 ( V_30 , V_41 ) )
goto V_544;
if ( ( T_5 ) ( V_30 -> V_45 . V_388 - V_30 -> V_45 . V_410 ) < 0 )
goto V_544;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_408 ) &&
V_30 -> V_81 == V_30 -> V_412 )
F_219 ( V_30 ) ;
F_205 ( V_2 , V_4 , 0 ) ;
F_250 ( V_4 ) ;
F_307 ( V_2 ) ;
return 0 ;
} else {
F_328 ( F_63 ( V_2 ) , V_538 ) ;
goto V_536;
}
} else {
int V_467 = 0 ;
int V_523 = 0 ;
bool V_458 = false ;
if ( V_30 -> V_85 == V_30 -> V_81 &&
V_10 - V_18 <= V_30 -> V_476 . V_10 ) {
#ifdef F_330
if ( V_30 -> V_476 . V_477 == V_478 &&
F_281 ( V_2 ) &&
F_323 ( V_2 , V_4 , V_18 ) ) {
V_523 = 1 ;
V_467 = 1 ;
}
#endif
if ( V_30 -> V_476 . V_477 == V_478 &&
F_281 ( V_2 ) && ! V_523 ) {
F_282 ( V_481 ) ;
if ( ! F_317 ( V_2 , V_4 , V_18 ) )
V_467 = 1 ;
}
if ( V_467 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_408 ) &&
V_30 -> V_81 == V_30 -> V_412 )
F_219 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
F_271 ( V_4 , V_18 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
F_62 ( F_63 ( V_2 ) , V_545 ) ;
}
if ( V_523 )
F_331 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_467 ) {
if ( F_322 ( V_2 , V_4 ) )
goto V_546;
if ( V_18 ==
( sizeof( struct V_15 ) + V_408 ) &&
V_30 -> V_81 == V_30 -> V_412 )
F_219 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
if ( ( int ) V_4 -> V_51 > V_2 -> V_547 )
goto V_548;
F_62 ( F_63 ( V_2 ) , V_549 ) ;
V_467 = F_270 ( V_2 , V_4 , V_18 ,
& V_458 ) ;
}
F_43 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_148 != V_30 -> V_96 ) {
F_205 ( V_2 , V_4 , V_356 ) ;
F_307 ( V_2 ) ;
if ( ! F_313 ( V_2 ) )
goto V_550;
}
if ( ! V_523 || V_30 -> V_81 != V_30 -> V_412 )
F_309 ( V_2 , 0 ) ;
V_550:
#ifdef F_330
if ( V_523 )
F_251 ( & V_2 -> V_551 , V_4 ) ;
else
#endif
if ( V_467 )
F_264 ( V_4 , V_458 ) ;
V_2 -> V_484 ( V_2 , 0 ) ;
return 0 ;
}
}
V_544:
if ( V_10 < ( V_41 -> V_370 << 2 ) || F_322 ( V_2 , V_4 ) )
goto V_546;
if ( ! F_327 ( V_2 , V_4 , V_41 , 1 ) )
return 0 ;
V_548:
if ( V_41 -> V_312 && F_205 ( V_2 , V_4 , V_353 ) < 0 )
goto V_536;
F_41 ( V_2 , V_4 ) ;
F_316 ( V_2 , V_4 , V_41 ) ;
F_279 ( V_2 , V_4 ) ;
F_307 ( V_2 ) ;
F_312 ( V_2 ) ;
return 0 ;
V_546:
F_328 ( F_63 ( V_2 ) , V_538 ) ;
V_536:
F_250 ( V_4 ) ;
return 0 ;
}
void F_332 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_233 ( V_2 , V_429 ) ;
if ( V_4 != NULL ) {
V_6 -> V_541 -> V_542 ( V_2 , V_4 ) ;
F_333 ( V_2 , V_4 ) ;
}
V_6 -> V_541 -> V_552 ( V_2 ) ;
F_334 ( V_2 ) ;
F_335 ( V_2 ) ;
V_30 -> V_553 = V_71 ;
F_29 ( V_2 ) ;
if ( F_229 ( V_2 , V_554 ) )
F_336 ( V_2 , F_337 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_341 )
F_338 ( V_30 , V_30 -> V_340 ) ;
else
V_30 -> V_343 = 0 ;
if ( ! F_229 ( V_2 , V_423 ) ) {
V_2 -> V_436 ( V_2 ) ;
F_238 ( V_2 , V_555 , V_556 ) ;
}
}
static bool F_339 ( struct V_1 * V_2 , struct V_3 * V_557 ,
struct V_367 * V_558 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_559 ? F_95 ( V_2 ) : NULL ;
T_7 V_58 = V_30 -> V_45 . V_46 ;
bool V_560 ;
if ( V_58 == V_30 -> V_45 . V_378 ) {
struct V_363 V_561 ;
const T_3 * V_533 ;
F_340 ( & V_561 ) ;
V_561 . V_378 = V_561 . V_46 = 0 ;
F_209 ( V_557 , & V_561 , & V_533 , 0 , NULL ) ;
V_58 = V_561 . V_46 ;
}
if ( ! V_30 -> V_562 )
V_558 -> V_10 = - 1 ;
V_560 = ( V_558 -> V_10 <= 0 && V_13 &&
F_2 ( V_2 ) -> V_226 ) ;
F_341 ( V_2 , V_58 , V_558 , V_560 ) ;
if ( V_13 ) {
F_127 ( V_2 , V_13 ) ;
F_180 ( V_2 ) ;
return true ;
}
return false ;
}
static int F_342 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
const T_3 * V_533 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_563 * V_564 = V_30 -> V_565 ;
struct V_367 V_368 = { . V_10 = - 1 } ;
int V_566 = V_30 -> V_45 . V_46 ;
F_209 ( V_4 , & V_30 -> V_45 , & V_533 , 0 , & V_368 ) ;
if ( V_41 -> V_312 ) {
if ( ! F_47 ( F_16 ( V_4 ) -> V_148 , V_30 -> V_96 ) ||
F_47 ( F_16 ( V_4 ) -> V_148 , V_30 -> V_98 ) )
goto V_567;
if ( V_30 -> V_45 . V_264 && V_30 -> V_45 . V_83 &&
! F_188 ( V_30 -> V_45 . V_83 , V_30 -> V_263 ,
V_71 ) ) {
F_62 ( F_63 ( V_2 ) , V_568 ) ;
goto V_567;
}
if ( V_41 -> V_534 ) {
F_227 ( V_2 ) ;
goto V_536;
}
if ( ! V_41 -> V_43 )
goto V_569;
F_17 ( V_30 , V_41 ) ;
V_30 -> V_339 = F_16 ( V_4 ) -> V_82 ;
F_205 ( V_2 , V_4 , V_353 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_412 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_340 = F_149 ( V_41 -> V_52 ) ;
F_343 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_30 -> V_45 . V_382 ) {
V_30 -> V_45 . V_341 = V_30 -> V_45 . V_570 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_264 ) {
V_30 -> V_45 . V_386 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_408 ;
V_30 -> V_57 -= V_408 ;
F_219 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_138 ( V_30 ) && V_571 )
F_344 ( V_30 ) ;
F_345 ( V_2 ) ;
F_166 ( V_2 , V_6 -> V_290 ) ;
F_36 ( V_2 ) ;
V_30 -> V_85 = V_30 -> V_81 ;
if ( V_564 != NULL &&
V_564 -> V_572 > 0 &&
V_30 -> V_45 . V_401 > 0 ) {
int V_573 = V_30 -> V_45 . V_401
- V_397 ;
int V_572 = V_573
+ V_564 -> V_574 ;
if ( sizeof( V_564 -> V_575 ) >= V_572 ) {
memcpy ( & V_564 -> V_575 [ V_564 -> V_574 ] ,
V_533 , V_573 ) ;
V_564 -> V_572 = V_572 ;
}
}
F_346 () ;
F_332 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_562 || V_30 -> V_559 ) &&
F_339 ( V_2 , V_4 , & V_368 ) )
return - 1 ;
if ( V_2 -> V_576 ||
V_6 -> V_577 . V_578 ||
V_6 -> V_8 . V_26 ) {
F_44 ( V_2 ) ;
V_6 -> V_8 . V_89 = V_71 ;
F_10 ( V_2 ) ;
F_128 ( V_2 , V_579 ,
V_580 , V_238 ) ;
V_536:
F_250 ( V_4 ) ;
return 0 ;
} else {
F_234 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_534 ) {
goto V_569;
}
if ( V_30 -> V_45 . V_411 && V_30 -> V_45 . V_264 &&
F_347 ( & V_30 -> V_45 , 0 ) )
goto V_569;
if ( V_41 -> V_43 ) {
F_233 ( V_2 , V_428 ) ;
if ( V_30 -> V_45 . V_264 ) {
V_30 -> V_45 . V_386 = 1 ;
F_219 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_408 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_412 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_340 = F_149 ( V_41 -> V_52 ) ;
V_30 -> V_339 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_141 = V_30 -> V_340 ;
F_18 ( V_30 , V_41 ) ;
F_345 ( V_2 ) ;
F_166 ( V_2 , V_6 -> V_290 ) ;
F_36 ( V_2 ) ;
F_348 ( V_2 ) ;
#if 0
return -1;
#else
goto V_536;
#endif
}
V_569:
F_340 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_566 ;
goto V_536;
V_567:
F_340 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_566 ;
return 1 ;
}
int F_349 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_581 = 0 ;
V_30 -> V_45 . V_264 = 0 ;
switch ( V_2 -> V_415 ) {
case V_421 :
goto V_536;
case V_582 :
if ( V_41 -> V_312 )
return 1 ;
if ( V_41 -> V_534 )
goto V_536;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_454 )
goto V_536;
if ( V_6 -> V_541 -> V_583 ( V_2 , V_4 ) < 0 )
return 1 ;
F_278 ( V_4 ) ;
return 0 ;
}
goto V_536;
case V_416 :
V_581 = F_342 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_581 >= 0 )
return V_581 ;
F_316 ( V_2 , V_4 , V_41 ) ;
F_250 ( V_4 ) ;
F_307 ( V_2 ) ;
return 0 ;
}
if ( ! F_327 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
if ( V_41 -> V_312 ) {
int V_584 = F_205 ( V_2 , V_4 , V_353 ) > 0 ;
switch ( V_2 -> V_415 ) {
case V_428 :
if ( V_584 ) {
V_30 -> V_85 = V_30 -> V_81 ;
F_346 () ;
F_233 ( V_2 , V_429 ) ;
V_2 -> V_436 ( V_2 ) ;
if ( V_2 -> V_504 )
F_238 ( V_2 ,
V_555 , V_556 ) ;
V_30 -> V_96 = F_16 ( V_4 ) -> V_148 ;
V_30 -> V_340 = F_149 ( V_41 -> V_52 ) <<
V_30 -> V_45 . V_341 ;
F_343 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_30 -> V_45 . V_386 )
V_30 -> V_57 -= V_408 ;
V_6 -> V_541 -> V_552 ( V_2 ) ;
F_334 ( V_2 ) ;
F_335 ( V_2 ) ;
V_30 -> V_553 = V_71 ;
F_345 ( V_2 ) ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_350 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_432 :
if ( V_30 -> V_96 == V_30 -> V_585 ) {
struct V_99 * V_100 ;
F_233 ( V_2 , V_433 ) ;
V_2 -> V_425 |= V_586 ;
V_100 = F_206 ( V_2 ) ;
if ( V_100 )
F_207 ( V_100 ) ;
if ( ! F_229 ( V_2 , V_423 ) )
V_2 -> V_436 ( V_2 ) ;
else {
int V_587 ;
if ( V_30 -> V_588 < 0 ||
( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_454 , V_30 -> V_81 ) ) ) {
F_230 ( V_2 ) ;
F_62 ( F_63 ( V_2 ) , V_589 ) ;
return 1 ;
}
V_587 = F_351 ( V_2 ) ;
if ( V_587 > V_590 ) {
F_336 ( V_2 , V_587 - V_590 ) ;
} else if ( V_41 -> V_454 || F_281 ( V_2 ) ) {
F_336 ( V_2 , V_587 ) ;
} else {
F_235 ( V_2 , V_433 , V_587 ) ;
goto V_536;
}
}
}
break;
case V_430 :
if ( V_30 -> V_96 == V_30 -> V_585 ) {
F_235 ( V_2 , V_434 , 0 ) ;
goto V_536;
}
break;
case V_431 :
if ( V_30 -> V_96 == V_30 -> V_585 ) {
F_352 ( V_2 ) ;
F_230 ( V_2 ) ;
goto V_536;
}
break;
}
} else
goto V_536;
F_316 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_415 ) {
case V_419 :
case V_430 :
case V_431 :
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
case V_432 :
case V_433 :
if ( V_2 -> V_425 & V_426 ) {
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_454 , V_30 -> V_81 ) ) {
F_62 ( F_63 ( V_2 ) , V_589 ) ;
F_227 ( V_2 ) ;
return 1 ;
}
}
case V_429 :
F_279 ( V_2 , V_4 ) ;
V_581 = 1 ;
break;
}
if ( V_2 -> V_415 != V_421 ) {
F_307 ( V_2 ) ;
F_312 ( V_2 ) ;
}
if ( ! V_581 ) {
V_536:
F_250 ( V_4 ) ;
}
return 0 ;
}
