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
static void F_50 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_97 ;
V_97 = ( T_3 ) V_30 -> V_98 * 2 * ( V_99 << 3 ) ;
V_97 *= F_32 ( V_30 -> V_100 , V_30 -> V_101 ) ;
if ( V_30 -> V_90 > 8 + 2 )
F_51 ( V_97 , V_30 -> V_90 ) ;
V_2 -> V_102 = F_38 ( T_3 , V_97 , ~ 0U ) ;
}
void F_52 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_88 = F_53 ( V_30 ) ;
F_54 ( V_2 ) ;
}
T_2 F_55 ( const struct V_29 * V_30 , const struct V_103 * V_104 )
{
T_2 V_105 = ( V_104 ? F_56 ( V_104 , V_106 ) : 0 ) ;
if ( ! V_105 )
V_105 = V_48 ;
return F_38 ( T_2 , V_105 , V_30 -> V_107 ) ;
}
void F_57 ( struct V_29 * V_30 )
{
if ( F_58 ( V_30 ) )
V_30 -> V_108 = NULL ;
V_30 -> V_45 . V_109 &= ~ V_110 ;
}
static void F_59 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_109 |= V_111 ;
}
static void F_60 ( struct V_1 * V_2 , const int V_112 ,
const int V_113 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_112 > V_30 -> V_114 ) {
int V_115 ;
V_30 -> V_114 = F_9 ( V_116 , V_112 ) ;
if ( V_113 )
V_115 = V_117 ;
else if ( F_61 ( V_30 ) )
V_115 = V_118 ;
else if ( F_58 ( V_30 ) )
V_115 = V_119 ;
else
V_115 = V_120 ;
F_62 ( F_63 ( V_2 ) , V_115 ) ;
#if V_121 > 1
F_64 ( L_1 ,
V_30 -> V_45 . V_109 , F_2 ( V_2 ) -> V_122 ,
V_30 -> V_114 ,
V_30 -> V_123 ,
V_30 -> V_124 ,
V_30 -> V_125 ? V_30 -> V_126 : 0 ) ;
#endif
F_57 ( V_30 ) ;
}
if ( V_112 > 0 )
F_65 ( V_30 ) ;
}
static void F_66 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_127 == NULL ) ||
F_41 ( F_16 ( V_4 ) -> V_80 ,
F_16 ( V_30 -> V_127 ) -> V_80 ) )
V_30 -> V_127 = V_4 ;
if ( ! V_30 -> V_128 ||
F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_129 ) )
V_30 -> V_129 = F_16 ( V_4 ) -> V_82 ;
}
static void F_67 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_130 & ( V_131 | V_132 ) ) ) {
F_66 ( V_30 , V_4 ) ;
V_30 -> V_128 += F_68 ( V_4 ) ;
F_16 ( V_4 ) -> V_130 |= V_131 ;
}
}
static void F_69 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_66 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_130 & ( V_131 | V_132 ) ) ) {
V_30 -> V_128 += F_68 ( V_4 ) ;
F_16 ( V_4 ) -> V_130 |= V_131 ;
}
}
static bool F_70 ( struct V_29 * V_30 , bool V_133 ,
T_1 V_134 , T_1 V_82 )
{
if ( F_48 ( V_82 , V_30 -> V_96 ) || ! F_41 ( V_134 , V_82 ) )
return false ;
if ( ! F_41 ( V_134 , V_30 -> V_96 ) )
return false ;
if ( F_48 ( V_134 , V_30 -> V_94 ) )
return true ;
if ( ! V_133 || ! V_30 -> V_125 )
return false ;
if ( F_48 ( V_82 , V_30 -> V_94 ) )
return false ;
if ( ! F_41 ( V_134 , V_30 -> V_125 ) )
return true ;
if ( ! F_48 ( V_82 , V_30 -> V_125 ) )
return false ;
return ! F_41 ( V_134 , V_82 - V_30 -> V_135 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_136 = 0 ;
T_1 V_137 = V_30 -> V_96 ;
T_1 V_138 = F_72 ( V_30 ) ;
if ( ! F_58 ( V_30 ) || ! V_30 -> V_139 ||
! F_48 ( V_138 , V_30 -> V_140 ) ||
V_6 -> V_122 != V_141 )
return;
F_73 (skb, sk) {
T_1 V_142 = F_16 ( V_4 ) -> V_142 ;
if ( V_4 == F_74 ( V_2 ) )
break;
if ( V_136 == V_30 -> V_139 )
break;
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_94 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_130 & V_143 ) )
continue;
if ( F_48 ( V_138 , V_142 ) ) {
F_16 ( V_4 ) -> V_130 &= ~ V_143 ;
V_30 -> V_139 -= F_68 ( V_4 ) ;
F_69 ( V_30 , V_4 ) ;
F_62 ( F_63 ( V_2 ) , V_144 ) ;
} else {
if ( F_41 ( V_142 , V_137 ) )
V_137 = V_142 ;
V_136 += F_68 ( V_4 ) ;
}
}
if ( V_30 -> V_139 )
V_30 -> V_140 = V_137 ;
}
static bool F_75 ( struct V_1 * V_2 , const struct V_3 * V_145 ,
struct V_146 * V_147 , int V_148 ,
T_1 V_149 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_150 = F_76 ( & V_147 [ 0 ] . V_134 ) ;
T_1 V_151 = F_76 ( & V_147 [ 0 ] . V_82 ) ;
bool V_152 = false ;
if ( F_41 ( V_150 , F_16 ( V_145 ) -> V_142 ) ) {
V_152 = true ;
F_59 ( V_30 ) ;
F_62 ( F_63 ( V_2 ) , V_153 ) ;
} else if ( V_148 > 1 ) {
T_1 V_154 = F_76 ( & V_147 [ 1 ] . V_82 ) ;
T_1 V_155 = F_76 ( & V_147 [ 1 ] . V_134 ) ;
if ( ! F_48 ( V_151 , V_154 ) &&
! F_41 ( V_150 , V_155 ) ) {
V_152 = true ;
F_59 ( V_30 ) ;
F_62 ( F_63 ( V_2 ) ,
V_156 ) ;
}
}
if ( V_152 && V_30 -> V_125 && V_30 -> V_126 &&
! F_48 ( V_151 , V_149 ) &&
F_48 ( V_151 , V_30 -> V_125 ) )
V_30 -> V_126 -- ;
return V_152 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_134 , T_1 V_82 )
{
int V_157 ;
bool V_158 ;
unsigned int V_159 ;
unsigned int V_58 ;
V_158 = ! F_48 ( V_134 , F_16 ( V_4 ) -> V_80 ) &&
! F_41 ( V_82 , F_16 ( V_4 ) -> V_82 ) ;
if ( F_68 ( V_4 ) > 1 && ! V_158 &&
F_48 ( F_16 ( V_4 ) -> V_82 , V_134 ) ) {
V_58 = F_78 ( V_4 ) ;
V_158 = ! F_48 ( V_134 , F_16 ( V_4 ) -> V_80 ) ;
if ( ! V_158 ) {
V_159 = V_134 - F_16 ( V_4 ) -> V_80 ;
if ( V_159 < V_58 )
V_159 = V_58 ;
} else {
V_159 = V_82 - F_16 ( V_4 ) -> V_80 ;
if ( V_159 < V_58 )
return - V_160 ;
}
if ( V_159 > V_58 ) {
unsigned int V_161 = ( V_159 / V_58 ) * V_58 ;
if ( ! V_158 && V_161 < V_159 ) {
V_161 += V_58 ;
if ( V_161 > V_4 -> V_10 )
return 0 ;
}
V_159 = V_161 ;
}
V_157 = F_79 ( V_2 , V_4 , V_159 , V_58 ) ;
if ( V_157 < 0 )
return V_157 ;
}
return V_158 ;
}
static T_4 F_80 ( struct V_1 * V_2 ,
struct V_162 * V_163 , T_4 V_130 ,
T_1 V_134 , T_1 V_82 ,
int V_152 , int V_164 , T_1 V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_166 = V_163 -> V_166 ;
if ( V_152 && ( V_130 & V_167 ) ) {
if ( V_30 -> V_125 && V_30 -> V_126 &&
F_48 ( V_82 , V_30 -> V_125 ) )
V_30 -> V_126 -- ;
if ( V_130 & V_132 )
V_163 -> V_168 = F_9 ( V_166 , V_163 -> V_168 ) ;
}
if ( ! F_48 ( V_82 , V_30 -> V_94 ) )
return V_130 ;
if ( ! ( V_130 & V_132 ) ) {
if ( V_130 & V_143 ) {
if ( V_130 & V_131 ) {
V_130 &= ~ ( V_131 | V_143 ) ;
V_30 -> V_128 -= V_164 ;
V_30 -> V_139 -= V_164 ;
}
} else {
if ( ! ( V_130 & V_167 ) ) {
if ( F_41 ( V_134 ,
F_72 ( V_30 ) ) )
V_163 -> V_168 = F_9 ( V_166 ,
V_163 -> V_168 ) ;
if ( ! F_48 ( V_82 , V_30 -> V_169 ) )
V_163 -> V_170 |= V_171 ;
if ( V_163 -> V_76 < 0 )
V_163 -> V_76 = V_69 - V_165 ;
}
if ( V_130 & V_131 ) {
V_130 &= ~ V_131 ;
V_30 -> V_128 -= V_164 ;
}
}
V_130 |= V_132 ;
V_163 -> V_170 |= V_172 ;
V_30 -> V_124 += V_164 ;
V_166 += V_164 ;
if ( ! F_58 ( V_30 ) && ( V_30 -> V_108 != NULL ) &&
F_41 ( V_134 , F_16 ( V_30 -> V_108 ) -> V_80 ) )
V_30 -> V_173 += V_164 ;
if ( V_166 > V_30 -> V_123 )
V_30 -> V_123 = V_166 ;
}
if ( V_152 && ( V_130 & V_143 ) ) {
V_130 &= ~ V_143 ;
V_30 -> V_139 -= V_164 ;
}
return V_130 ;
}
static bool F_81 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_162 * V_163 ,
unsigned int V_164 , int V_174 , int V_58 ,
bool V_152 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_175 = F_82 ( V_2 , V_4 ) ;
T_1 V_134 = F_16 ( V_4 ) -> V_80 ;
T_1 V_82 = V_134 + V_174 ;
F_83 ( ! V_164 ) ;
F_80 ( V_2 , V_163 , F_16 ( V_4 ) -> V_130 ,
V_134 , V_82 , V_152 , V_164 ,
F_16 ( V_4 ) -> V_176 ) ;
if ( V_4 == V_30 -> V_108 )
V_30 -> V_173 += V_164 ;
F_16 ( V_175 ) -> V_82 += V_174 ;
F_16 ( V_4 ) -> V_80 += V_174 ;
F_3 ( V_175 ) -> V_177 += V_164 ;
F_83 ( F_3 ( V_4 ) -> V_177 < V_164 ) ;
F_3 ( V_4 ) -> V_177 -= V_164 ;
if ( ! F_3 ( V_175 ) -> V_11 ) {
F_3 ( V_175 ) -> V_11 = V_58 ;
F_3 ( V_175 ) -> V_178 = V_2 -> V_179 ;
}
if ( F_3 ( V_4 ) -> V_177 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_178 = 0 ;
}
F_16 ( V_175 ) -> V_130 |= ( F_16 ( V_4 ) -> V_130 & V_180 ) ;
if ( V_4 -> V_10 > 0 ) {
F_83 ( ! F_68 ( V_4 ) ) ;
F_62 ( F_63 ( V_2 ) , V_181 ) ;
return false ;
}
if ( V_4 == V_30 -> V_127 )
V_30 -> V_127 = V_175 ;
if ( V_4 == V_30 -> V_108 ) {
V_30 -> V_108 = V_175 ;
V_30 -> V_173 -= F_68 ( V_175 ) ;
}
F_16 ( V_175 ) -> V_182 |= F_16 ( V_4 ) -> V_182 ;
if ( F_16 ( V_4 ) -> V_182 & V_183 )
F_16 ( V_175 ) -> V_82 ++ ;
if ( V_4 == F_84 ( V_2 ) )
F_85 ( V_2 , V_4 ) ;
F_86 ( V_4 , V_2 ) ;
F_87 ( V_2 , V_4 ) ;
F_62 ( F_63 ( V_2 ) , V_184 ) ;
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
struct V_162 * V_163 ,
T_1 V_134 , T_1 V_82 ,
bool V_152 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_175 ;
int V_58 ;
int V_164 = 0 ;
int V_10 ;
int V_158 ;
if ( ! F_93 ( V_2 ) )
goto V_185;
if ( ! V_152 &&
( F_16 ( V_4 ) -> V_130 & ( V_131 | V_143 ) ) == V_143 )
goto V_185;
if ( ! F_89 ( V_4 ) )
goto V_185;
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_94 ) )
goto V_185;
if ( F_94 ( V_4 == F_95 ( V_2 ) ) )
goto V_185;
V_175 = F_82 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_175 ) -> V_130 & V_186 ) != V_132 )
goto V_185;
V_158 = ! F_48 ( V_134 , F_16 ( V_4 ) -> V_80 ) &&
! F_41 ( V_82 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_158 ) {
V_10 = V_4 -> V_10 ;
V_164 = F_68 ( V_4 ) ;
V_58 = F_88 ( V_4 ) ;
if ( V_58 != F_88 ( V_175 ) )
goto V_185;
} else {
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_134 ) )
goto V_187;
if ( F_68 ( V_4 ) <= 1 )
goto V_187;
V_158 = ! F_48 ( V_134 , F_16 ( V_4 ) -> V_80 ) ;
if ( ! V_158 ) {
goto V_185;
}
V_10 = V_82 - F_16 ( V_4 ) -> V_80 ;
F_83 ( V_10 < 0 ) ;
F_83 ( V_10 > V_4 -> V_10 ) ;
V_58 = F_78 ( V_4 ) ;
if ( V_58 != F_88 ( V_175 ) )
goto V_185;
if ( V_10 == V_58 ) {
V_164 = 1 ;
} else if ( V_10 < V_58 ) {
goto V_187;
} else {
V_164 = V_10 / V_58 ;
V_10 = V_164 * V_58 ;
}
}
if ( ! F_48 ( F_16 ( V_4 ) -> V_80 + V_10 , V_30 -> V_94 ) )
goto V_185;
if ( ! F_96 ( V_175 , V_4 , V_10 ) )
goto V_185;
if ( ! F_81 ( V_2 , V_4 , V_163 , V_164 , V_10 , V_58 , V_152 ) )
goto V_188;
if ( V_175 == F_97 ( V_2 ) )
goto V_188;
V_4 = F_98 ( V_2 , V_175 ) ;
if ( ! F_89 ( V_4 ) ||
( V_4 == F_74 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_130 & V_186 ) != V_132 ) ||
( V_58 != F_88 ( V_4 ) ) )
goto V_188;
V_10 = V_4 -> V_10 ;
if ( F_96 ( V_175 , V_4 , V_10 ) ) {
V_164 += F_68 ( V_4 ) ;
F_81 ( V_2 , V_4 , V_163 , F_68 ( V_4 ) , V_10 , V_58 , 0 ) ;
}
V_188:
V_163 -> V_166 += V_164 ;
return V_175 ;
V_187:
return V_4 ;
V_185:
F_62 ( F_63 ( V_2 ) , V_189 ) ;
return NULL ;
}
static struct V_3 * F_99 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_190 * V_191 ,
struct V_162 * V_163 ,
T_1 V_134 , T_1 V_82 ,
bool V_192 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_193 ;
F_100 (skb, sk) {
int V_158 = 0 ;
bool V_152 = V_192 ;
if ( V_4 == F_74 ( V_2 ) )
break;
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 , V_82 ) )
break;
if ( ( V_191 != NULL ) &&
F_41 ( F_16 ( V_4 ) -> V_80 , V_191 -> V_82 ) ) {
V_158 = F_77 ( V_2 , V_4 ,
V_191 -> V_134 ,
V_191 -> V_82 ) ;
if ( V_158 > 0 )
V_152 = true ;
}
if ( V_158 <= 0 ) {
V_193 = F_92 ( V_2 , V_4 , V_163 ,
V_134 , V_82 , V_152 ) ;
if ( V_193 != NULL ) {
if ( V_193 != V_4 ) {
V_4 = V_193 ;
continue;
}
V_158 = 0 ;
} else {
V_158 = F_77 ( V_2 , V_4 ,
V_134 ,
V_82 ) ;
}
}
if ( F_94 ( V_158 < 0 ) )
break;
if ( V_158 ) {
F_16 ( V_4 ) -> V_130 =
F_80 ( V_2 ,
V_163 ,
F_16 ( V_4 ) -> V_130 ,
F_16 ( V_4 ) -> V_80 ,
F_16 ( V_4 ) -> V_82 ,
V_152 ,
F_68 ( V_4 ) ,
F_16 ( V_4 ) -> V_176 ) ;
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 ,
F_72 ( V_30 ) ) )
F_85 ( V_2 , V_4 ) ;
}
V_163 -> V_166 += F_68 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_101 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_162 * V_163 ,
T_1 V_194 )
{
F_100 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( F_48 ( F_16 ( V_4 ) -> V_82 , V_194 ) )
break;
V_163 -> V_166 += F_68 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_102 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_190 * V_191 ,
struct V_162 * V_163 ,
T_1 V_194 )
{
if ( V_191 == NULL )
return V_4 ;
if ( F_41 ( V_191 -> V_134 , V_194 ) ) {
V_4 = F_101 ( V_4 , V_2 , V_163 , V_191 -> V_134 ) ;
V_4 = F_99 ( V_4 , V_2 , NULL , V_163 ,
V_191 -> V_134 , V_191 -> V_82 ,
1 ) ;
}
return V_4 ;
}
static int F_103 ( const struct V_29 * V_30 , const struct V_190 * V_195 )
{
return V_195 < V_30 -> V_196 + F_104 ( V_30 -> V_196 ) ;
}
static int
F_105 ( struct V_1 * V_2 , const struct V_3 * V_145 ,
T_1 V_149 , T_5 * V_197 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_198 = ( F_4 ( V_145 ) +
F_16 ( V_145 ) -> V_130 ) ;
struct V_146 * V_199 = (struct V_146 * ) ( V_198 + 2 ) ;
struct V_190 V_147 [ V_200 ] ;
struct V_190 * V_195 ;
struct V_162 V_163 ;
struct V_3 * V_4 ;
int V_148 = F_9 ( V_200 , ( V_198 [ 1 ] - V_201 ) >> 3 ) ;
int V_202 ;
bool V_203 = false ;
int V_204 , V_205 ;
int V_206 ;
V_163 . V_170 = 0 ;
V_163 . V_168 = V_30 -> V_101 ;
V_163 . V_76 = - 1 ;
if ( ! V_30 -> V_124 ) {
if ( F_106 ( V_30 -> V_123 ) )
V_30 -> V_123 = 0 ;
F_107 ( V_2 ) ;
}
V_203 = F_75 ( V_2 , V_145 , V_199 ,
V_148 , V_149 ) ;
if ( V_203 )
V_163 . V_170 |= V_207 ;
if ( F_41 ( F_16 ( V_145 ) -> V_142 , V_149 - V_30 -> V_135 ) )
return 0 ;
if ( ! V_30 -> V_101 )
goto V_188;
V_202 = 0 ;
V_206 = 0 ;
for ( V_204 = 0 ; V_204 < V_148 ; V_204 ++ ) {
bool V_152 = ! V_204 && V_203 ;
V_147 [ V_202 ] . V_134 = F_76 ( & V_199 [ V_204 ] . V_134 ) ;
V_147 [ V_202 ] . V_82 = F_76 ( & V_199 [ V_204 ] . V_82 ) ;
if ( ! F_70 ( V_30 , V_152 ,
V_147 [ V_202 ] . V_134 ,
V_147 [ V_202 ] . V_82 ) ) {
int V_115 ;
if ( V_152 ) {
if ( ! V_30 -> V_125 )
V_115 = V_208 ;
else
V_115 = V_209 ;
} else {
if ( ( F_16 ( V_145 ) -> V_142 != V_30 -> V_94 ) &&
! F_48 ( V_147 [ V_202 ] . V_82 , V_30 -> V_94 ) )
continue;
V_115 = V_210 ;
}
F_62 ( F_63 ( V_2 ) , V_115 ) ;
if ( V_204 == 0 )
V_206 = - 1 ;
continue;
}
if ( ! F_48 ( V_147 [ V_202 ] . V_82 , V_149 ) )
continue;
V_202 ++ ;
}
for ( V_204 = V_202 - 1 ; V_204 > 0 ; V_204 -- ) {
for ( V_205 = 0 ; V_205 < V_204 ; V_205 ++ ) {
if ( F_48 ( V_147 [ V_205 ] . V_134 , V_147 [ V_205 + 1 ] . V_134 ) ) {
F_108 ( V_147 [ V_205 ] , V_147 [ V_205 + 1 ] ) ;
if ( V_205 == V_206 )
V_206 = V_205 + 1 ;
}
}
}
V_4 = F_95 ( V_2 ) ;
V_163 . V_166 = 0 ;
V_204 = 0 ;
if ( ! V_30 -> V_124 ) {
V_195 = V_30 -> V_196 + F_104 ( V_30 -> V_196 ) ;
} else {
V_195 = V_30 -> V_196 ;
while ( F_103 ( V_30 , V_195 ) && ! V_195 -> V_134 &&
! V_195 -> V_82 )
V_195 ++ ;
}
while ( V_204 < V_202 ) {
T_1 V_134 = V_147 [ V_204 ] . V_134 ;
T_1 V_82 = V_147 [ V_204 ] . V_82 ;
bool V_152 = ( V_203 && ( V_204 == V_206 ) ) ;
struct V_190 * V_191 = NULL ;
if ( V_203 && ( ( V_204 + 1 ) == V_206 ) )
V_191 = & V_147 [ V_204 + 1 ] ;
while ( F_103 ( V_30 , V_195 ) &&
! F_41 ( V_134 , V_195 -> V_82 ) )
V_195 ++ ;
if ( F_103 ( V_30 , V_195 ) && ! V_152 &&
F_48 ( V_82 , V_195 -> V_134 ) ) {
if ( F_41 ( V_134 , V_195 -> V_134 ) ) {
V_4 = F_101 ( V_4 , V_2 , & V_163 ,
V_134 ) ;
V_4 = F_99 ( V_4 , V_2 , V_191 ,
& V_163 ,
V_134 ,
V_195 -> V_134 ,
V_152 ) ;
}
if ( ! F_48 ( V_82 , V_195 -> V_82 ) )
goto V_211;
V_4 = F_102 ( V_4 , V_2 , V_191 ,
& V_163 ,
V_195 -> V_82 ) ;
if ( F_72 ( V_30 ) == V_195 -> V_82 ) {
V_4 = F_84 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_163 . V_166 = V_30 -> V_123 ;
V_195 ++ ;
goto V_212;
}
V_4 = F_101 ( V_4 , V_2 , & V_163 , V_195 -> V_82 ) ;
V_195 ++ ;
continue;
}
if ( ! F_41 ( V_134 , F_72 ( V_30 ) ) ) {
V_4 = F_84 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_163 . V_166 = V_30 -> V_123 ;
}
V_4 = F_101 ( V_4 , V_2 , & V_163 , V_134 ) ;
V_212:
V_4 = F_99 ( V_4 , V_2 , V_191 , & V_163 ,
V_134 , V_82 , V_152 ) ;
V_211:
V_204 ++ ;
}
for ( V_204 = 0 ; V_204 < F_104 ( V_30 -> V_196 ) - V_202 ; V_204 ++ ) {
V_30 -> V_196 [ V_204 ] . V_134 = 0 ;
V_30 -> V_196 [ V_204 ] . V_82 = 0 ;
}
for ( V_205 = 0 ; V_205 < V_202 ; V_205 ++ )
V_30 -> V_196 [ V_204 ++ ] = V_147 [ V_205 ] ;
F_71 ( V_2 ) ;
F_109 ( V_30 ) ;
if ( ( V_163 . V_168 < V_30 -> V_123 ) &&
( ( F_2 ( V_2 ) -> V_122 != V_213 ) || V_30 -> V_125 ) )
F_60 ( V_2 , V_30 -> V_123 - V_163 . V_168 , 0 ) ;
V_188:
#if V_121 > 0
F_106 ( ( int ) V_30 -> V_124 < 0 ) ;
F_106 ( ( int ) V_30 -> V_128 < 0 ) ;
F_106 ( ( int ) V_30 -> V_139 < 0 ) ;
F_106 ( ( int ) F_110 ( V_30 ) < 0 ) ;
#endif
* V_197 = V_163 . V_76 ;
return V_163 . V_170 ;
}
static bool F_111 ( struct V_29 * V_30 )
{
T_1 V_214 ;
V_214 = F_32 ( V_30 -> V_128 , 1U ) ;
V_214 = F_9 ( V_214 , V_30 -> V_101 ) ;
if ( ( V_30 -> V_124 + V_214 ) > V_30 -> V_101 ) {
V_30 -> V_124 = V_30 -> V_101 - V_214 ;
return true ;
}
return false ;
}
static void F_112 ( struct V_1 * V_2 , const int V_215 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_111 ( V_30 ) )
F_60 ( V_2 , V_30 -> V_101 + V_215 , 0 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_124 ++ ;
F_112 ( V_2 , 0 ) ;
F_109 ( V_30 ) ;
}
static void F_114 ( struct V_1 * V_2 , int V_216 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_216 > 0 ) {
if ( V_216 - 1 >= V_30 -> V_124 )
V_30 -> V_124 = 0 ;
else
V_30 -> V_124 -= V_216 - 1 ;
}
F_112 ( V_2 , V_216 ) ;
F_109 ( V_30 ) ;
}
static inline void F_115 ( struct V_29 * V_30 )
{
V_30 -> V_124 = 0 ;
}
static void F_116 ( struct V_29 * V_30 )
{
V_30 -> V_139 = 0 ;
V_30 -> V_128 = 0 ;
V_30 -> V_125 = 0 ;
V_30 -> V_126 = 0 ;
}
void F_117 ( struct V_29 * V_30 )
{
F_116 ( V_30 ) ;
V_30 -> V_123 = 0 ;
V_30 -> V_124 = 0 ;
}
void F_118 ( struct V_1 * V_2 , int V_217 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_218 = false ;
if ( V_6 -> V_122 <= V_219 ||
! F_48 ( V_30 -> V_169 , V_30 -> V_94 ) ||
( V_6 -> V_122 == V_213 && ! V_6 -> V_220 ) ) {
V_218 = true ;
V_30 -> V_221 = F_119 ( V_2 ) ;
V_30 -> V_222 = V_6 -> V_223 -> V_224 ( V_2 ) ;
F_120 ( V_2 , V_225 ) ;
}
V_30 -> V_100 = 1 ;
V_30 -> V_226 = 0 ;
V_30 -> V_68 = V_69 ;
F_116 ( V_30 ) ;
if ( F_61 ( V_30 ) )
F_115 ( V_30 ) ;
V_30 -> V_125 = V_30 -> V_94 ;
if ( V_217 ) {
V_30 -> V_124 = 0 ;
V_30 -> V_123 = 0 ;
}
F_121 ( V_30 ) ;
F_73 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_130 & V_167 )
V_30 -> V_125 = 0 ;
F_16 ( V_4 ) -> V_130 &= ( ~ V_186 ) | V_132 ;
if ( ! ( F_16 ( V_4 ) -> V_130 & V_132 ) || V_217 ) {
F_16 ( V_4 ) -> V_130 &= ~ V_132 ;
F_16 ( V_4 ) -> V_130 |= V_131 ;
V_30 -> V_128 += F_68 ( V_4 ) ;
V_30 -> V_129 = F_16 ( V_4 ) -> V_82 ;
}
}
F_109 ( V_30 ) ;
if ( V_6 -> V_122 <= V_219 &&
V_30 -> V_124 >= V_227 )
V_30 -> V_114 = F_38 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_122 ( V_2 , V_213 ) ;
V_30 -> V_169 = V_30 -> V_96 ;
F_12 ( V_30 ) ;
V_30 -> V_228 = V_229 &&
( V_218 || V_6 -> V_220 ) &&
! F_2 ( V_2 ) -> V_230 . V_231 ;
}
static bool F_123 ( struct V_1 * V_2 , int V_170 )
{
if ( V_170 & V_232 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_62 ( F_63 ( V_2 ) , V_233 ) ;
F_118 ( V_2 , 1 ) ;
V_6 -> V_220 ++ ;
F_124 ( V_2 , F_95 ( V_2 ) ) ;
F_125 ( V_2 , V_234 ,
V_6 -> V_88 , V_235 ) ;
return true ;
}
return false ;
}
static inline int F_126 ( const struct V_29 * V_30 )
{
return F_61 ( V_30 ) ? V_30 -> V_124 + 1 : V_30 -> V_123 ;
}
static inline int F_127 ( const struct V_29 * V_30 )
{
return F_58 ( V_30 ) ? V_30 -> V_123 : V_30 -> V_124 + 1 ;
}
static bool F_128 ( struct V_1 * V_2 , int V_170 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_236 ;
if ( V_237 < 2 || V_237 > 3 ||
( V_170 & V_238 ) || ! V_30 -> V_90 )
return false ;
V_236 = F_27 (unsigned long, (tp->srtt >> 5), msecs_to_jiffies(2)) ;
if ( ! F_129 ( F_2 ( V_2 ) -> V_239 , ( V_240 + V_236 ) ) )
return false ;
F_125 ( V_2 , V_241 , V_236 ,
V_235 ) ;
return true ;
}
static bool F_130 ( struct V_1 * V_2 , int V_170 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_101 ;
if ( V_30 -> V_128 )
return true ;
if ( F_127 ( V_30 ) > V_30 -> V_114 )
return true ;
V_101 = V_30 -> V_101 ;
if ( V_101 <= V_30 -> V_114 &&
V_30 -> V_124 >= F_27 ( T_2 , V_101 / 2 , V_227 ) &&
! F_131 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_242 || V_243 ) &&
F_132 ( V_30 ) && F_127 ( V_30 ) > 1 &&
F_133 ( V_30 ) && ! F_74 ( V_2 ) )
return true ;
if ( V_30 -> V_244 && ! V_30 -> V_139 && V_30 -> V_124 &&
( V_30 -> V_101 >= ( V_30 -> V_124 + 1 ) && V_30 -> V_101 < 4 ) &&
! F_131 ( V_2 ) )
return ! F_128 ( V_2 , V_170 ) ;
return false ;
}
static void F_134 ( struct V_1 * V_2 , int V_245 , int V_246 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_136 , V_247 ;
int V_157 ;
unsigned int V_58 ;
const T_1 V_248 = F_133 ( V_30 ) ? V_30 -> V_96 : V_30 -> V_169 ;
F_106 ( V_245 > V_30 -> V_101 ) ;
if ( V_30 -> V_108 ) {
V_4 = V_30 -> V_108 ;
V_136 = V_30 -> V_173 ;
if ( V_246 && V_4 != F_95 ( V_2 ) )
return;
} else {
V_4 = F_95 ( V_2 ) ;
V_136 = 0 ;
}
F_100 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
V_30 -> V_108 = V_4 ;
V_30 -> V_173 = V_136 ;
if ( F_48 ( F_16 ( V_4 ) -> V_82 , V_248 ) )
break;
V_247 = V_136 ;
if ( F_58 ( V_30 ) || F_61 ( V_30 ) ||
( F_16 ( V_4 ) -> V_130 & V_132 ) )
V_136 += F_68 ( V_4 ) ;
if ( V_136 > V_245 ) {
if ( ( F_133 ( V_30 ) && ! F_58 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_130 & V_132 ) ||
( V_247 >= V_245 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_157 = F_79 ( V_2 , V_4 , ( V_245 - V_247 ) * V_58 , V_58 ) ;
if ( V_157 < 0 )
break;
V_136 = V_245 ;
}
F_67 ( V_30 , V_4 ) ;
if ( V_246 )
break;
}
F_109 ( V_30 ) ;
}
static void F_135 ( struct V_1 * V_2 , int V_249 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_61 ( V_30 ) ) {
F_134 ( V_2 , 1 , 1 ) ;
} else if ( F_58 ( V_30 ) ) {
int V_250 = V_30 -> V_123 - V_30 -> V_114 ;
if ( V_250 <= 0 )
V_250 = 1 ;
F_134 ( V_2 , V_250 , 0 ) ;
} else {
int V_251 = V_30 -> V_124 - V_30 -> V_114 ;
if ( V_251 >= 0 )
F_134 ( V_2 , V_251 , 0 ) ;
else if ( V_249 )
F_134 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_136 ( struct V_29 * V_30 )
{
V_30 -> V_100 = F_9 ( V_30 -> V_100 ,
F_110 ( V_30 ) + F_137 ( V_30 ) ) ;
V_30 -> V_68 = V_69 ;
}
static inline bool F_138 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_252 ||
( V_30 -> V_45 . V_253 && V_30 -> V_45 . V_81 &&
F_41 ( V_30 -> V_45 . V_81 , V_30 -> V_252 ) ) ;
}
static void F_139 ( struct V_1 * V_2 , const char * V_254 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_255 * V_256 = F_140 ( V_2 ) ;
if ( V_2 -> V_257 == V_258 ) {
F_64 ( L_2 ,
V_254 ,
& V_256 -> V_259 , F_141 ( V_256 -> V_260 ) ,
V_30 -> V_100 , F_142 ( V_30 ) ,
V_30 -> V_222 , V_30 -> V_221 ,
V_30 -> V_101 ) ;
}
#if F_143 ( V_261 )
else if ( V_2 -> V_257 == V_262 ) {
struct V_263 * V_264 = F_144 ( V_2 ) ;
F_64 ( L_3 ,
V_254 ,
& V_264 -> V_265 , F_141 ( V_256 -> V_260 ) ,
V_30 -> V_100 , F_142 ( V_30 ) ,
V_30 -> V_222 , V_30 -> V_221 ,
V_30 -> V_101 ) ;
}
#endif
}
static void F_145 ( struct V_1 * V_2 , bool V_266 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_266 ) {
struct V_3 * V_4 ;
F_73 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_130 &= ~ V_131 ;
}
V_30 -> V_128 = 0 ;
F_121 ( V_30 ) ;
}
if ( V_30 -> V_221 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_223 -> V_267 )
V_30 -> V_100 = V_6 -> V_223 -> V_267 ( V_2 ) ;
else
V_30 -> V_100 = F_32 ( V_30 -> V_100 , V_30 -> V_222 << 1 ) ;
if ( V_30 -> V_221 > V_30 -> V_222 ) {
V_30 -> V_222 = V_30 -> V_221 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_100 = F_32 ( V_30 -> V_100 , V_30 -> V_222 ) ;
}
V_30 -> V_68 = V_69 ;
V_30 -> V_125 = 0 ;
}
static inline bool F_146 ( const struct V_29 * V_30 )
{
return V_30 -> V_125 && ( ! V_30 -> V_126 || F_138 ( V_30 ) ) ;
}
static bool F_147 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_146 ( V_30 ) ) {
int V_115 ;
F_139 ( V_2 , F_2 ( V_2 ) -> V_122 == V_213 ? L_4 : L_5 ) ;
F_145 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_122 == V_213 )
V_115 = V_268 ;
else
V_115 = V_269 ;
F_62 ( F_63 ( V_2 ) , V_115 ) ;
}
if ( V_30 -> V_94 == V_30 -> V_169 && F_61 ( V_30 ) ) {
F_136 ( V_30 ) ;
return true ;
}
F_122 ( V_2 , V_270 ) ;
return false ;
}
static bool F_148 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_125 && ! V_30 -> V_126 ) {
F_139 ( V_2 , L_6 ) ;
F_145 ( V_2 , false ) ;
F_62 ( F_63 ( V_2 ) , V_271 ) ;
return true ;
}
return false ;
}
static bool F_149 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_139 )
return true ;
V_4 = F_95 ( V_2 ) ;
if ( F_94 ( V_4 && F_16 ( V_4 ) -> V_130 & V_180 ) )
return true ;
return false ;
}
static bool F_150 ( struct V_1 * V_2 , bool V_272 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_272 || F_146 ( V_30 ) ) {
F_145 ( V_2 , true ) ;
F_139 ( V_2 , L_7 ) ;
F_62 ( F_63 ( V_2 ) , V_268 ) ;
if ( V_272 )
F_62 ( F_63 ( V_2 ) ,
V_273 ) ;
F_2 ( V_2 ) -> V_220 = 0 ;
if ( V_272 || F_133 ( V_30 ) )
F_122 ( V_2 , V_270 ) ;
return true ;
}
return false ;
}
static void F_151 ( struct V_1 * V_2 , const bool V_274 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_169 = V_30 -> V_96 ;
V_30 -> V_275 = 0 ;
V_30 -> V_226 = 0 ;
V_30 -> V_276 = V_30 -> V_100 ;
V_30 -> V_277 = 0 ;
V_30 -> V_278 = 0 ;
if ( V_274 )
V_30 -> V_222 = F_2 ( V_2 ) -> V_223 -> V_224 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_152 ( struct V_1 * V_2 , const int V_279 ,
int V_249 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_280 = 0 ;
int V_281 = V_30 -> V_222 - F_110 ( V_30 ) ;
int V_282 = V_279 -
( V_30 -> V_101 - V_30 -> V_124 ) ;
V_30 -> V_277 += V_282 ;
if ( F_110 ( V_30 ) > V_30 -> V_222 ) {
T_3 V_283 = ( T_3 ) V_30 -> V_222 * V_30 -> V_277 +
V_30 -> V_276 - 1 ;
V_280 = F_153 ( V_283 , V_30 -> V_276 ) - V_30 -> V_278 ;
} else {
V_280 = F_38 ( int , V_281 ,
F_27 ( int , V_30 -> V_277 - V_30 -> V_278 ,
V_282 ) + 1 ) ;
}
V_280 = F_32 ( V_280 , ( V_249 ? 1 : 0 ) ) ;
V_30 -> V_100 = F_110 ( V_30 ) + V_280 ;
}
static inline void F_154 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_122 == V_284 ||
( V_30 -> V_125 && V_30 -> V_222 < V_285 ) ) {
V_30 -> V_100 = V_30 -> V_222 ;
V_30 -> V_68 = V_69 ;
}
F_120 ( V_2 , V_286 ) ;
}
void F_155 ( struct V_1 * V_2 , const int V_274 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_221 = 0 ;
if ( F_2 ( V_2 ) -> V_122 < V_284 ) {
V_30 -> V_125 = 0 ;
F_151 ( V_2 , V_274 ) ;
F_122 ( V_2 , V_284 ) ;
}
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_163 = V_270 ;
if ( F_142 ( V_30 ) || F_149 ( V_2 ) )
V_163 = V_219 ;
if ( F_2 ( V_2 ) -> V_122 != V_163 ) {
F_122 ( V_2 , V_163 ) ;
V_30 -> V_169 = V_30 -> V_96 ;
}
}
static void F_157 ( struct V_1 * V_2 , int V_170 , const int V_279 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_109 ( V_30 ) ;
if ( ! F_149 ( V_2 ) )
V_30 -> V_252 = 0 ;
if ( V_170 & V_238 )
F_155 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_122 != V_284 ) {
F_156 ( V_2 ) ;
} else {
F_152 ( V_2 , V_279 , 0 ) ;
}
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_230 . V_287 = V_6 -> V_230 . V_231 - 1 ;
V_6 -> V_230 . V_231 = 0 ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_221 = F_119 ( V_2 ) ;
V_30 -> V_100 = V_30 -> V_100 *
F_160 ( V_2 , V_30 -> V_98 ) /
V_6 -> V_230 . V_231 ;
V_30 -> V_226 = 0 ;
V_30 -> V_68 = V_69 ;
V_30 -> V_222 = F_119 ( V_2 ) ;
V_6 -> V_230 . V_288 = V_6 -> V_230 . V_231 ;
V_6 -> V_230 . V_231 = 0 ;
F_161 ( V_2 , V_6 -> V_289 ) ;
}
void F_162 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_163 ( V_2 ) ;
T_1 V_290 = V_30 -> V_128 ;
F_73 (skb, sk) {
if ( V_4 == F_74 ( V_2 ) )
break;
if ( F_88 ( V_4 ) > V_58 &&
! ( F_16 ( V_4 ) -> V_130 & V_132 ) ) {
if ( F_16 ( V_4 ) -> V_130 & V_143 ) {
F_16 ( V_4 ) -> V_130 &= ~ V_143 ;
V_30 -> V_139 -= F_68 ( V_4 ) ;
}
F_69 ( V_30 , V_4 ) ;
}
}
F_164 ( V_30 ) ;
if ( V_290 == V_30 -> V_128 )
return;
if ( F_61 ( V_30 ) )
F_111 ( V_30 ) ;
F_109 ( V_30 ) ;
if ( V_6 -> V_122 != V_213 ) {
V_30 -> V_169 = V_30 -> V_96 ;
V_30 -> V_222 = F_119 ( V_2 ) ;
V_30 -> V_221 = 0 ;
V_30 -> V_125 = 0 ;
F_122 ( V_2 , V_213 ) ;
}
F_165 ( V_2 ) ;
}
static void F_166 ( struct V_1 * V_2 , bool V_291 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_115 ;
if ( F_61 ( V_30 ) )
V_115 = V_292 ;
else
V_115 = V_293 ;
F_62 ( F_63 ( V_2 ) , V_115 ) ;
V_30 -> V_221 = 0 ;
V_30 -> V_125 = V_30 -> V_94 ;
V_30 -> V_126 = V_30 -> V_139 ;
if ( F_2 ( V_2 ) -> V_122 < V_284 ) {
if ( ! V_291 )
V_30 -> V_221 = F_119 ( V_2 ) ;
F_151 ( V_2 , true ) ;
}
F_122 ( V_2 , V_141 ) ;
}
static void F_167 ( struct V_1 * V_2 , int V_170 , bool V_294 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_295 = ! F_41 ( V_30 -> V_94 , V_30 -> V_169 ) ;
if ( V_30 -> V_228 ) {
if ( V_170 & V_171 ) {
F_150 ( V_2 , true ) ;
return;
}
if ( F_48 ( V_30 -> V_96 , V_30 -> V_169 ) &&
( V_170 & V_172 || V_294 ) ) {
V_30 -> V_228 = 0 ;
} else if ( V_170 & V_296 && ! V_295 ) {
V_30 -> V_169 = V_30 -> V_96 ;
F_168 ( V_2 , F_163 ( V_2 ) ,
V_297 ) ;
if ( F_48 ( V_30 -> V_96 , V_30 -> V_169 ) )
return;
V_30 -> V_228 = 0 ;
}
}
if ( V_295 ) {
V_6 -> V_220 = 0 ;
F_147 ( V_2 ) ;
return;
}
if ( V_170 & V_298 )
V_6 -> V_220 = 0 ;
if ( F_61 ( V_30 ) ) {
if ( F_48 ( V_30 -> V_96 , V_30 -> V_169 ) && V_294 )
F_113 ( V_2 ) ;
else if ( V_170 & V_296 )
F_115 ( V_30 ) ;
}
if ( F_150 ( V_2 , false ) )
return;
F_165 ( V_2 ) ;
}
static bool F_169 ( struct V_1 * V_2 , const int V_216 ,
const int V_279 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_125 && F_138 ( V_30 ) ) {
F_60 ( V_2 , F_126 ( V_30 ) + V_216 , 1 ) ;
if ( V_30 -> V_139 ) {
F_152 ( V_2 , V_279 , 0 ) ;
return true ;
}
if ( ! F_149 ( V_2 ) )
V_30 -> V_252 = 0 ;
F_139 ( V_2 , L_8 ) ;
F_145 ( V_2 , true ) ;
F_62 ( F_63 ( V_2 ) , V_299 ) ;
F_156 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_170 ( struct V_1 * V_2 , const int V_216 ,
const int V_279 ,
bool V_294 , int V_170 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_300 = V_294 || ( ( V_170 & V_172 ) &&
( F_126 ( V_30 ) > V_30 -> V_114 ) ) ;
int V_249 = 0 ;
if ( F_106 ( ! V_30 -> V_101 && V_30 -> V_124 ) )
V_30 -> V_124 = 0 ;
if ( F_106 ( ! V_30 -> V_124 && V_30 -> V_123 ) )
V_30 -> V_123 = 0 ;
if ( V_170 & V_238 )
V_30 -> V_221 = 0 ;
if ( F_123 ( V_2 , V_170 ) )
return;
F_109 ( V_30 ) ;
if ( V_6 -> V_122 == V_270 ) {
F_106 ( V_30 -> V_139 != 0 ) ;
V_30 -> V_252 = 0 ;
} else if ( ! F_41 ( V_30 -> V_94 , V_30 -> V_169 ) ) {
switch ( V_6 -> V_122 ) {
case V_284 :
if ( V_30 -> V_94 != V_30 -> V_169 ) {
F_154 ( V_2 ) ;
F_122 ( V_2 , V_270 ) ;
}
break;
case V_141 :
if ( F_61 ( V_30 ) )
F_115 ( V_30 ) ;
if ( F_147 ( V_2 ) )
return;
F_154 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_122 ) {
case V_141 :
if ( ! ( V_170 & V_296 ) ) {
if ( F_61 ( V_30 ) && V_294 )
F_113 ( V_2 ) ;
} else {
if ( F_169 ( V_2 , V_216 , V_279 ) )
return;
V_300 = F_61 ( V_30 ) ||
F_126 ( V_30 ) > V_30 -> V_114 ;
}
if ( F_148 ( V_2 ) ) {
F_156 ( V_2 ) ;
return;
}
break;
case V_213 :
F_167 ( V_2 , V_170 , V_294 ) ;
if ( V_6 -> V_122 != V_270 )
return;
default:
if ( F_61 ( V_30 ) ) {
if ( V_170 & V_296 )
F_115 ( V_30 ) ;
if ( V_294 )
F_113 ( V_2 ) ;
}
if ( V_6 -> V_122 <= V_219 )
F_148 ( V_2 ) ;
if ( ! F_130 ( V_2 , V_170 ) ) {
F_157 ( V_2 , V_170 , V_279 ) ;
return;
}
if ( V_6 -> V_122 < V_284 &&
V_6 -> V_230 . V_231 &&
V_30 -> V_94 == V_30 -> V_301 . V_302 ) {
F_158 ( V_2 ) ;
V_30 -> V_100 ++ ;
F_162 ( V_2 ) ;
return;
}
F_166 ( V_2 , ( V_170 & V_238 ) ) ;
V_249 = 1 ;
}
if ( V_300 )
F_135 ( V_2 , V_249 ) ;
F_152 ( V_2 , V_279 , V_249 ) ;
F_165 ( V_2 ) ;
}
static inline bool F_171 ( struct V_1 * V_2 , const int V_170 ,
T_5 V_303 , T_5 V_197 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_170 & V_304 )
V_303 = - 1 ;
if ( V_303 < 0 )
V_303 = V_197 ;
if ( V_303 < 0 && V_30 -> V_45 . V_253 && V_30 -> V_45 . V_81 )
V_303 = V_69 - V_30 -> V_45 . V_81 ;
if ( V_303 < 0 )
return false ;
F_47 ( V_2 , V_303 ) ;
F_52 ( V_2 ) ;
F_2 ( V_2 ) -> V_305 = 0 ;
return true ;
}
static void F_172 ( struct V_1 * V_2 , struct V_306 * V_307 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_5 V_303 = - 1 ;
if ( V_30 -> V_308 && ! V_30 -> V_309 )
V_303 = V_69 - V_30 -> V_308 ;
F_171 ( V_2 , V_310 , V_303 , - 1 ) ;
}
static void F_173 ( struct V_1 * V_2 , T_1 V_311 , T_1 V_312 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_223 -> V_313 ( V_2 , V_311 , V_312 ) ;
F_7 ( V_2 ) -> V_68 = V_69 ;
}
void F_174 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_314 )
return;
if ( ! V_30 -> V_101 ) {
F_175 ( V_2 , V_234 ) ;
} else {
T_1 V_315 = F_2 ( V_2 ) -> V_88 ;
if ( V_6 -> V_316 == V_241 ||
V_6 -> V_316 == V_317 ) {
struct V_3 * V_4 = F_95 ( V_2 ) ;
const T_1 V_318 = F_16 ( V_4 ) -> V_176 + V_315 ;
T_5 V_281 = ( T_5 ) ( V_318 - V_69 ) ;
if ( V_281 > 0 )
V_315 = V_281 ;
}
F_125 ( V_2 , V_234 , V_315 ,
V_235 ) ;
}
}
void F_176 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_174 ( V_2 ) ;
if ( ! V_30 -> V_244 )
return;
F_166 ( V_2 , false ) ;
F_135 ( V_2 , 1 ) ;
F_165 ( V_2 ) ;
}
static T_1 F_177 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_319 ;
F_83 ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_94 ) ) ;
V_319 = F_68 ( V_4 ) ;
if ( F_178 ( V_2 , V_4 , V_30 -> V_94 - F_16 ( V_4 ) -> V_80 ) )
return 0 ;
V_319 -= F_68 ( V_4 ) ;
if ( V_319 ) {
F_83 ( F_68 ( V_4 ) == 0 ) ;
F_83 ( ! F_41 ( F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ) ;
}
return V_319 ;
}
static int F_179 ( struct V_1 * V_2 , int V_320 ,
T_1 V_149 , T_5 V_197 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_86 = V_69 ;
int V_321 = true ;
int V_170 = 0 ;
T_1 V_322 = 0 ;
T_1 V_168 = V_30 -> V_101 ;
T_1 V_323 = V_30 -> V_124 ;
T_5 V_303 = - 1 ;
T_5 V_324 = - 1 ;
T_6 V_325 = F_180 () ;
while ( ( V_4 = F_95 ( V_2 ) ) && V_4 != F_74 ( V_2 ) ) {
struct V_326 * V_327 = F_16 ( V_4 ) ;
T_1 V_328 ;
T_4 V_130 = V_327 -> V_130 ;
if ( F_48 ( V_327 -> V_82 , V_30 -> V_94 ) ) {
if ( F_68 ( V_4 ) == 1 ||
! F_48 ( V_30 -> V_94 , V_327 -> V_80 ) )
break;
V_328 = F_177 ( V_2 , V_4 ) ;
if ( ! V_328 )
break;
V_321 = false ;
} else {
V_328 = F_68 ( V_4 ) ;
}
if ( V_130 & V_167 ) {
if ( V_130 & V_143 )
V_30 -> V_139 -= V_328 ;
V_170 |= V_304 ;
} else {
V_324 = V_86 - V_327 -> V_176 ;
V_325 = V_4 -> V_329 ;
if ( V_303 < 0 ) {
V_303 = V_324 ;
}
if ( ! ( V_130 & V_132 ) )
V_168 = F_9 ( V_322 , V_168 ) ;
if ( ! F_48 ( V_327 -> V_82 , V_30 -> V_169 ) )
V_170 |= V_171 ;
}
if ( V_130 & V_132 )
V_30 -> V_124 -= V_328 ;
if ( V_130 & V_131 )
V_30 -> V_128 -= V_328 ;
V_30 -> V_101 -= V_328 ;
V_322 += V_328 ;
if ( ! ( V_327 -> V_182 & V_330 ) ) {
V_170 |= V_298 ;
} else {
V_170 |= V_310 ;
V_30 -> V_252 = 0 ;
}
if ( ! V_321 )
break;
F_86 ( V_4 , V_2 ) ;
F_87 ( V_2 , V_4 ) ;
if ( V_4 == V_30 -> V_127 )
V_30 -> V_127 = NULL ;
if ( V_4 == V_30 -> V_108 )
V_30 -> V_108 = NULL ;
}
if ( F_181 ( F_182 ( V_30 -> V_331 , V_149 , V_30 -> V_94 ) ) )
V_30 -> V_331 = V_30 -> V_94 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_130 & V_132 ) )
V_170 |= V_232 ;
if ( F_171 ( V_2 , V_170 , V_303 , V_197 ) ||
( V_170 & V_332 ) )
F_174 ( V_2 ) ;
if ( V_170 & V_332 ) {
const struct V_333 * V_334
= F_2 ( V_2 ) -> V_223 ;
if ( F_94 ( V_6 -> V_230 . V_231 &&
! F_48 ( V_30 -> V_301 . V_335 , V_30 -> V_94 ) ) ) {
F_159 ( V_2 ) ;
}
if ( F_61 ( V_30 ) ) {
F_114 ( V_2 , V_322 ) ;
} else {
int V_281 ;
if ( V_168 < V_320 )
F_60 ( V_2 , V_30 -> V_123 - V_168 , 0 ) ;
V_281 = F_58 ( V_30 ) ? V_322 :
V_323 - V_30 -> V_124 ;
V_30 -> V_173 -= F_9 ( V_30 -> V_173 , V_281 ) ;
}
V_30 -> V_123 -= F_9 ( V_322 , V_30 -> V_123 ) ;
if ( V_334 -> V_322 ) {
T_5 V_336 = - 1 ;
if ( ! ( V_170 & V_304 ) ) {
if ( V_334 -> V_337 & V_338 &&
! F_183 ( V_325 ,
F_180 () ) )
V_336 = F_184 ( F_185 () ,
V_325 ) ;
else if ( V_324 >= 0 )
V_336 = F_186 ( V_324 ) ;
}
V_334 -> V_322 ( V_2 , V_322 , V_336 ) ;
}
}
#if V_121 > 0
F_106 ( ( int ) V_30 -> V_124 < 0 ) ;
F_106 ( ( int ) V_30 -> V_128 < 0 ) ;
F_106 ( ( int ) V_30 -> V_139 < 0 ) ;
if ( ! V_30 -> V_101 && F_133 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_128 ) {
F_64 ( L_9 ,
V_30 -> V_128 , V_6 -> V_122 ) ;
V_30 -> V_128 = 0 ;
}
if ( V_30 -> V_124 ) {
F_64 ( L_10 ,
V_30 -> V_124 , V_6 -> V_122 ) ;
V_30 -> V_124 = 0 ;
}
if ( V_30 -> V_139 ) {
F_64 ( L_11 ,
V_30 -> V_139 , V_6 -> V_122 ) ;
V_30 -> V_139 = 0 ;
}
}
#endif
return V_170 ;
}
static void F_187 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_48 ( F_16 ( F_74 ( V_2 ) ) -> V_82 , F_188 ( V_30 ) ) ) {
V_6 -> V_305 = 0 ;
F_175 ( V_2 , V_339 ) ;
} else {
F_125 ( V_2 , V_339 ,
F_9 ( V_6 -> V_88 << V_6 -> V_305 , V_235 ) ,
V_235 ) ;
}
}
static inline bool F_189 ( const struct V_1 * V_2 , const int V_170 )
{
return ! ( V_170 & V_340 ) || ( V_170 & V_341 ) ||
F_2 ( V_2 ) -> V_122 != V_270 ;
}
static inline bool F_190 ( const struct V_1 * V_2 , const int V_170 )
{
if ( F_191 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_114 > V_227 )
return V_170 & V_342 ;
return V_170 & V_298 ;
}
static inline bool F_192 ( const struct V_29 * V_30 ,
const T_1 V_311 , const T_1 V_142 ,
const T_1 V_343 )
{
return F_48 ( V_311 , V_30 -> V_94 ) ||
F_48 ( V_142 , V_30 -> V_344 ) ||
( V_142 == V_30 -> V_344 && V_343 > V_30 -> V_345 ) ;
}
static int F_193 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_311 ,
T_1 V_142 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_170 = 0 ;
T_1 V_343 = F_141 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_181 ( ! F_6 ( V_4 ) -> V_43 ) )
V_343 <<= V_30 -> V_45 . V_346 ;
if ( F_192 ( V_30 , V_311 , V_142 , V_343 ) ) {
V_170 |= V_347 ;
F_194 ( V_30 , V_142 ) ;
if ( V_30 -> V_345 != V_343 ) {
V_30 -> V_345 = V_343 ;
V_30 -> V_348 = 0 ;
F_195 ( V_2 ) ;
if ( V_343 > V_30 -> V_135 ) {
V_30 -> V_135 = V_343 ;
F_161 ( V_2 , F_2 ( V_2 ) -> V_289 ) ;
}
}
}
V_30 -> V_94 = V_311 ;
return V_170 ;
}
static void F_196 ( struct V_1 * V_2 )
{
static T_1 V_349 ;
static unsigned int V_350 ;
T_1 V_86 = V_240 / V_99 ;
if ( V_86 != V_349 ) {
V_349 = V_86 ;
V_350 = 0 ;
}
if ( ++ V_350 <= V_351 ) {
F_62 ( F_63 ( V_2 ) , V_352 ) ;
F_197 ( V_2 ) ;
}
}
static void F_198 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_353 = V_30 -> V_45 . V_354 ;
V_30 -> V_45 . V_355 = F_199 () ;
}
static void F_200 ( struct V_29 * V_30 , T_1 V_80 )
{
if ( V_30 -> V_45 . V_253 && ! F_48 ( V_80 , V_30 -> V_356 ) ) {
if ( F_201 ( & V_30 -> V_45 , 0 ) )
F_198 ( V_30 ) ;
}
}
static void F_202 ( struct V_1 * V_2 , T_1 V_311 , int V_170 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_357 = ( V_311 == V_30 -> V_275 ) &&
! ( V_170 & ( V_296 |
V_340 | V_172 ) ) ;
if ( V_357 ) {
V_30 -> V_275 = 0 ;
return;
}
if ( F_48 ( V_311 , V_30 -> V_275 ) ) {
V_30 -> V_275 = 0 ;
if ( ! ( V_170 & V_207 ) ) {
F_151 ( V_2 , true ) ;
F_122 ( V_2 , V_284 ) ;
F_154 ( V_2 ) ;
F_156 ( V_2 ) ;
F_62 ( F_63 ( V_2 ) ,
V_358 ) ;
}
}
}
static int F_203 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_170 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_149 = V_30 -> V_94 ;
T_1 V_142 = F_16 ( V_4 ) -> V_80 ;
T_1 V_311 = F_16 ( V_4 ) -> V_142 ;
bool V_294 = false ;
T_1 V_359 , V_276 = V_30 -> V_100 , V_360 = V_30 -> V_90 ;
T_1 V_320 ;
int V_361 = V_30 -> V_101 ;
const int V_279 = V_30 -> V_101 - V_30 -> V_124 ;
int V_216 = 0 ;
T_5 V_197 = - 1 ;
if ( F_41 ( V_311 , V_149 ) ) {
if ( F_41 ( V_311 , V_149 - V_30 -> V_135 ) ) {
F_196 ( V_2 ) ;
return - 1 ;
}
goto V_362;
}
if ( F_48 ( V_311 , V_30 -> V_96 ) )
goto V_363;
if ( V_6 -> V_316 == V_241 ||
V_6 -> V_316 == V_317 )
F_174 ( V_2 ) ;
if ( F_48 ( V_311 , V_149 ) )
V_170 |= V_296 ;
V_320 = V_30 -> V_123 ;
V_359 = F_110 ( V_30 ) ;
if ( V_170 & V_364 )
F_200 ( V_30 , F_16 ( V_4 ) -> V_80 ) ;
if ( ! ( V_170 & V_365 ) && F_48 ( V_311 , V_149 ) ) {
F_194 ( V_30 , V_142 ) ;
V_30 -> V_94 = V_311 ;
V_170 |= V_347 ;
F_120 ( V_2 , V_366 ) ;
F_62 ( F_63 ( V_2 ) , V_367 ) ;
} else {
if ( V_142 != F_16 ( V_4 ) -> V_82 )
V_170 |= V_368 ;
else
F_62 ( F_63 ( V_2 ) , V_369 ) ;
V_170 |= F_193 ( V_2 , V_4 , V_311 , V_142 ) ;
if ( F_16 ( V_4 ) -> V_130 )
V_170 |= F_105 ( V_2 , V_4 , V_149 ,
& V_197 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_170 |= V_238 ;
F_120 ( V_2 , V_370 ) ;
}
V_2 -> V_371 = 0 ;
V_6 -> V_372 = 0 ;
V_30 -> V_373 = V_69 ;
if ( ! V_361 )
goto V_374;
V_216 = V_30 -> V_101 ;
V_170 |= F_179 ( V_2 , V_320 , V_149 , V_197 ) ;
V_216 -= V_30 -> V_101 ;
if ( F_190 ( V_2 , V_170 ) )
F_173 ( V_2 , V_311 , V_359 ) ;
if ( F_189 ( V_2 , V_170 ) ) {
V_294 = ! ( V_170 & ( V_296 | V_340 ) ) ;
F_170 ( V_2 , V_216 , V_279 ,
V_294 , V_170 ) ;
}
if ( V_30 -> V_275 )
F_202 ( V_2 , V_311 , V_170 ) ;
if ( ( V_170 & V_342 ) || ! ( V_170 & V_340 ) ) {
struct V_103 * V_104 = F_204 ( V_2 ) ;
if ( V_104 )
F_205 ( V_104 ) ;
}
if ( V_6 -> V_316 == V_234 )
F_206 ( V_2 ) ;
if ( V_30 -> V_90 != V_360 || V_30 -> V_100 != V_276 )
F_50 ( V_2 ) ;
return 1 ;
V_374:
if ( V_170 & V_207 )
F_170 ( V_2 , V_216 , V_279 ,
V_294 , V_170 ) ;
if ( F_74 ( V_2 ) )
F_187 ( V_2 ) ;
if ( V_30 -> V_275 )
F_202 ( V_2 , V_311 , V_170 ) ;
return 1 ;
V_363:
F_207 ( V_2 , L_12 , V_311 , V_30 -> V_94 , V_30 -> V_96 ) ;
return - 1 ;
V_362:
if ( F_16 ( V_4 ) -> V_130 ) {
V_170 |= F_105 ( V_2 , V_4 , V_149 ,
& V_197 ) ;
F_170 ( V_2 , V_216 , V_279 ,
V_294 , V_170 ) ;
}
F_207 ( V_2 , L_13 , V_311 , V_30 -> V_94 , V_30 -> V_96 ) ;
return 0 ;
}
void F_208 ( const struct V_3 * V_4 ,
struct V_375 * V_376 , int V_377 ,
struct V_378 * V_379 )
{
const unsigned char * V_198 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_380 = ( V_41 -> V_381 * 4 ) - sizeof( struct V_15 ) ;
V_198 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_376 -> V_253 = 0 ;
while ( V_380 > 0 ) {
int V_382 = * V_198 ++ ;
int V_383 ;
switch ( V_382 ) {
case V_384 :
return;
case V_385 :
V_380 -- ;
continue;
default:
V_383 = * V_198 ++ ;
if ( V_383 < 2 )
return;
if ( V_383 > V_380 )
return;
switch ( V_382 ) {
case V_386 :
if ( V_383 == V_387 && V_41 -> V_43 && ! V_377 ) {
T_7 V_388 = F_209 ( V_198 ) ;
if ( V_388 ) {
if ( V_376 -> V_389 &&
V_376 -> V_389 < V_388 )
V_388 = V_376 -> V_389 ;
V_376 -> V_46 = V_388 ;
}
}
break;
case V_390 :
if ( V_383 == V_391 && V_41 -> V_43 &&
! V_377 && V_392 ) {
T_8 V_346 = * ( T_8 * ) V_198 ;
V_376 -> V_393 = 1 ;
if ( V_346 > 14 ) {
F_210 ( L_14 ,
V_394 ,
V_346 ) ;
V_346 = 14 ;
}
V_376 -> V_346 = V_346 ;
}
break;
case V_395 :
if ( ( V_383 == V_396 ) &&
( ( V_377 && V_376 -> V_397 ) ||
( ! V_377 && V_398 ) ) ) {
V_376 -> V_253 = 1 ;
V_376 -> V_354 = F_76 ( V_198 ) ;
V_376 -> V_81 = F_76 ( V_198 + 4 ) ;
}
break;
case V_399 :
if ( V_383 == V_400 && V_41 -> V_43 &&
! V_377 && V_401 ) {
V_376 -> V_109 = V_402 ;
F_211 ( V_376 ) ;
}
break;
case V_403 :
if ( ( V_383 >= ( V_201 + V_404 ) ) &&
! ( ( V_383 - V_201 ) % V_404 ) &&
V_376 -> V_109 ) {
F_16 ( V_4 ) -> V_130 = ( V_198 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_212
case V_405 :
break;
#endif
case V_406 :
if ( V_383 < V_407 ||
F_209 ( V_198 ) != V_408 ||
V_379 == NULL || ! V_41 -> V_43 || ( V_383 & 1 ) )
break;
V_379 -> V_10 = V_383 - V_407 ;
if ( V_379 -> V_10 >= V_409 &&
V_379 -> V_10 <= V_410 )
memcpy ( V_379 -> V_411 , V_198 + 2 , V_379 -> V_10 ) ;
else if ( V_379 -> V_10 != 0 )
V_379 -> V_10 = - 1 ;
break;
}
V_198 += V_383 - 2 ;
V_380 -= V_383 ;
}
}
}
static bool F_213 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_198 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_198 == F_214 ( ( V_385 << 24 ) | ( V_385 << 16 )
| ( V_395 << 8 ) | V_396 ) ) {
V_30 -> V_45 . V_253 = 1 ;
++ V_198 ;
V_30 -> V_45 . V_354 = F_215 ( * V_198 ) ;
++ V_198 ;
if ( * V_198 )
V_30 -> V_45 . V_81 = F_215 ( * V_198 ) - V_30 -> V_412 ;
else
V_30 -> V_45 . V_81 = 0 ;
return true ;
}
return false ;
}
static bool F_216 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 , struct V_29 * V_30 )
{
if ( V_41 -> V_381 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_253 = 0 ;
return false ;
} else if ( V_30 -> V_45 . V_397 &&
V_41 -> V_381 == ( ( sizeof( * V_41 ) + V_413 ) / 4 ) ) {
if ( F_213 ( V_30 , V_41 ) )
return true ;
}
F_208 ( V_4 , & V_30 -> V_45 , 1 , NULL ) ;
if ( V_30 -> V_45 . V_253 && V_30 -> V_45 . V_81 )
V_30 -> V_45 . V_81 -= V_30 -> V_412 ;
return true ;
}
const T_4 * F_217 ( const struct V_15 * V_41 )
{
int V_380 = ( V_41 -> V_381 << 2 ) - sizeof( * V_41 ) ;
const T_4 * V_198 = ( const T_4 * ) ( V_41 + 1 ) ;
if ( V_380 < V_414 )
return NULL ;
while ( V_380 > 0 ) {
int V_382 = * V_198 ++ ;
int V_383 ;
switch( V_382 ) {
case V_384 :
return NULL ;
case V_385 :
V_380 -- ;
continue;
default:
V_383 = * V_198 ++ ;
if ( V_383 < 2 || V_383 > V_380 )
return NULL ;
if ( V_382 == V_405 )
return V_383 == V_414 ? V_198 : NULL ;
}
V_198 += V_383 - 2 ;
V_380 -= V_383 ;
}
return NULL ;
}
static int F_218 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_80 = F_16 ( V_4 ) -> V_80 ;
T_1 V_311 = F_16 ( V_4 ) -> V_142 ;
return (
( V_41 -> V_311 && V_80 == F_16 ( V_4 ) -> V_82 && V_80 == V_30 -> V_79 ) &&
V_311 == V_30 -> V_94 &&
! F_192 ( V_30 , V_311 , V_80 , F_141 ( V_41 -> V_52 ) << V_30 -> V_45 . V_346 ) &&
( T_5 ) ( V_30 -> V_45 . V_353 - V_30 -> V_45 . V_354 ) <= ( F_2 ( V_2 ) -> V_88 * 1024 ) / V_99 ) ;
}
static inline bool F_219 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_201 ( & V_30 -> V_45 , V_415 ) &&
! F_218 ( V_2 , V_4 ) ;
}
static inline bool F_220 ( const struct V_29 * V_30 , T_1 V_80 , T_1 V_82 )
{
return ! F_41 ( V_82 , V_30 -> V_356 ) &&
! F_48 ( V_80 , V_30 -> V_79 + F_221 ( V_30 ) ) ;
}
void F_222 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_416 ) {
case V_417 :
V_2 -> V_418 = V_419 ;
break;
case V_420 :
V_2 -> V_418 = V_421 ;
break;
case V_422 :
return;
default:
V_2 -> V_418 = V_423 ;
}
F_223 () ;
if ( ! F_224 ( V_2 , V_424 ) )
V_2 -> V_425 ( V_2 ) ;
F_225 ( V_2 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_103 * V_104 ;
F_45 ( V_2 ) ;
V_2 -> V_426 |= V_427 ;
F_227 ( V_2 , V_428 ) ;
switch ( V_2 -> V_416 ) {
case V_429 :
case V_430 :
F_228 ( V_2 , V_420 ) ;
V_104 = F_204 ( V_2 ) ;
if ( ! V_104 || ! F_56 ( V_104 , V_431 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_420 :
case V_432 :
break;
case V_433 :
break;
case V_434 :
F_197 ( V_2 ) ;
F_228 ( V_2 , V_432 ) ;
break;
case V_435 :
F_197 ( V_2 ) ;
F_229 ( V_2 , V_436 , 0 ) ;
break;
default:
F_230 ( L_15 ,
V_394 , V_2 -> V_416 ) ;
break;
}
F_231 ( & V_30 -> V_437 ) ;
if ( F_133 ( V_30 ) )
F_211 ( & V_30 -> V_45 ) ;
F_46 ( V_2 ) ;
if ( ! F_224 ( V_2 , V_424 ) ) {
V_2 -> V_438 ( V_2 ) ;
if ( V_2 -> V_426 == V_439 ||
V_2 -> V_416 == V_422 )
F_232 ( V_2 , V_440 , V_441 ) ;
else
F_232 ( V_2 , V_440 , V_442 ) ;
}
}
static inline bool F_233 ( struct V_190 * V_147 , T_1 V_80 ,
T_1 V_82 )
{
if ( ! F_48 ( V_80 , V_147 -> V_82 ) && ! F_48 ( V_147 -> V_134 , V_82 ) ) {
if ( F_41 ( V_80 , V_147 -> V_134 ) )
V_147 -> V_134 = V_80 ;
if ( F_48 ( V_82 , V_147 -> V_82 ) )
V_147 -> V_82 = V_82 ;
return true ;
}
return false ;
}
static void F_234 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_82 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_133 ( V_30 ) && V_443 ) {
int V_115 ;
if ( F_41 ( V_80 , V_30 -> V_79 ) )
V_115 = V_444 ;
else
V_115 = V_445 ;
F_62 ( F_63 ( V_2 ) , V_115 ) ;
V_30 -> V_45 . V_446 = 1 ;
V_30 -> V_447 [ 0 ] . V_134 = V_80 ;
V_30 -> V_447 [ 0 ] . V_82 = V_82 ;
}
}
static void F_235 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_82 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_446 )
F_234 ( V_2 , V_80 , V_82 ) ;
else
F_233 ( V_30 -> V_447 , V_80 , V_82 ) ;
}
static void F_236 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_82 != F_16 ( V_4 ) -> V_80 &&
F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) ) {
F_62 ( F_63 ( V_2 ) , V_448 ) ;
F_10 ( V_2 ) ;
if ( F_133 ( V_30 ) && V_443 ) {
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
int V_449 ;
struct V_190 * V_147 = & V_30 -> V_450 [ 0 ] ;
struct V_190 * V_451 = V_147 + 1 ;
for ( V_449 = 1 ; V_449 < V_30 -> V_45 . V_148 ; ) {
if ( F_233 ( V_147 , V_451 -> V_134 , V_451 -> V_82 ) ) {
int V_204 ;
V_30 -> V_45 . V_148 -- ;
for ( V_204 = V_449 ; V_204 < V_30 -> V_45 . V_148 ; V_204 ++ )
V_147 [ V_204 ] = V_147 [ V_204 + 1 ] ;
continue;
}
V_449 ++ , V_451 ++ ;
}
}
static void F_238 ( struct V_1 * V_2 , T_1 V_80 , T_1 V_82 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_190 * V_147 = & V_30 -> V_450 [ 0 ] ;
int V_452 = V_30 -> V_45 . V_148 ;
int V_449 ;
if ( ! V_452 )
goto V_453;
for ( V_449 = 0 ; V_449 < V_452 ; V_449 ++ , V_147 ++ ) {
if ( F_233 ( V_147 , V_80 , V_82 ) ) {
for (; V_449 > 0 ; V_449 -- , V_147 -- )
F_108 ( * V_147 , * ( V_147 - 1 ) ) ;
if ( V_452 > 1 )
F_237 ( V_30 ) ;
return;
}
}
if ( V_449 >= V_200 ) {
V_449 -- ;
V_30 -> V_45 . V_148 -- ;
V_147 -- ;
}
for (; V_449 > 0 ; V_449 -- , V_147 -- )
* V_147 = * ( V_147 - 1 ) ;
V_453:
V_147 -> V_134 = V_80 ;
V_147 -> V_82 = V_82 ;
V_30 -> V_45 . V_148 ++ ;
}
static void F_239 ( struct V_29 * V_30 )
{
struct V_190 * V_147 = & V_30 -> V_450 [ 0 ] ;
int V_148 = V_30 -> V_45 . V_148 ;
int V_449 ;
if ( F_240 ( & V_30 -> V_437 ) ) {
V_30 -> V_45 . V_148 = 0 ;
return;
}
for ( V_449 = 0 ; V_449 < V_148 ; ) {
if ( ! F_41 ( V_30 -> V_79 , V_147 -> V_134 ) ) {
int V_204 ;
F_106 ( F_41 ( V_30 -> V_79 , V_147 -> V_82 ) ) ;
for ( V_204 = V_449 + 1 ; V_204 < V_148 ; V_204 ++ )
V_30 -> V_450 [ V_204 - 1 ] = V_30 -> V_450 [ V_204 ] ;
V_148 -- ;
continue;
}
V_449 ++ ;
V_147 ++ ;
}
V_30 -> V_45 . V_148 = V_148 ;
}
static void F_241 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_454 = V_30 -> V_79 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_242 ( & V_30 -> V_437 ) ) != NULL ) {
if ( F_48 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) )
break;
if ( F_41 ( F_16 ( V_4 ) -> V_80 , V_454 ) ) {
T_2 V_446 = V_454 ;
if ( F_41 ( F_16 ( V_4 ) -> V_82 , V_454 ) )
V_454 = F_16 ( V_4 ) -> V_82 ;
F_235 ( V_2 , F_16 ( V_4 ) -> V_80 , V_446 ) ;
}
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_79 ) ) {
F_207 ( V_2 , L_16 ) ;
F_243 ( V_4 , & V_30 -> V_437 ) ;
F_244 ( V_4 ) ;
continue;
}
F_207 ( V_2 , L_17 ,
V_30 -> V_79 , F_16 ( V_4 ) -> V_80 ,
F_16 ( V_4 ) -> V_82 ) ;
F_243 ( V_4 , & V_30 -> V_437 ) ;
F_245 ( & V_2 -> V_455 , V_4 ) ;
V_30 -> V_79 = F_16 ( V_4 ) -> V_82 ;
if ( F_6 ( V_4 ) -> V_456 )
F_226 ( V_2 ) ;
}
}
static int F_246 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_457 )
{
if ( F_36 ( & V_2 -> V_70 ) > V_2 -> V_60 ||
! F_247 ( V_2 , V_4 , V_457 ) ) {
if ( F_248 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_247 ( V_2 , V_4 , V_457 ) ) {
if ( ! F_249 ( V_2 ) )
return - 1 ;
if ( ! F_247 ( V_2 , V_4 , V_457 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_250 ( struct V_1 * V_2 ,
struct V_3 * V_458 ,
struct V_3 * V_459 ,
bool * V_460 )
{
int V_281 ;
* V_460 = false ;
if ( F_6 ( V_459 ) -> V_456 )
return false ;
if ( F_16 ( V_459 ) -> V_80 != F_16 ( V_458 ) -> V_82 )
return false ;
if ( ! F_251 ( V_458 , V_459 , V_460 , & V_281 ) )
return false ;
F_252 ( V_281 , & V_2 -> V_70 ) ;
F_253 ( V_2 , V_281 ) ;
F_62 ( F_63 ( V_2 ) , V_461 ) ;
F_16 ( V_458 ) -> V_82 = F_16 ( V_459 ) -> V_82 ;
F_16 ( V_458 ) -> V_142 = F_16 ( V_459 ) -> V_142 ;
return true ;
}
static void F_254 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_462 ;
T_1 V_80 , V_82 ;
F_15 ( V_30 , V_4 ) ;
if ( F_94 ( F_246 ( V_2 , V_4 , V_4 -> V_51 ) ) ) {
F_62 ( F_63 ( V_2 ) , V_463 ) ;
F_244 ( V_4 ) ;
return;
}
V_30 -> V_348 = 0 ;
F_45 ( V_2 ) ;
F_62 ( F_63 ( V_2 ) , V_464 ) ;
F_207 ( V_2 , L_18 ,
V_30 -> V_79 , F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ;
V_462 = F_255 ( & V_30 -> V_437 ) ;
if ( ! V_462 ) {
if ( F_133 ( V_30 ) ) {
V_30 -> V_45 . V_148 = 1 ;
V_30 -> V_450 [ 0 ] . V_134 = F_16 ( V_4 ) -> V_80 ;
V_30 -> V_450 [ 0 ] . V_82 =
F_16 ( V_4 ) -> V_82 ;
}
F_256 ( & V_30 -> V_437 , V_4 ) ;
goto V_465;
}
V_80 = F_16 ( V_4 ) -> V_80 ;
V_82 = F_16 ( V_4 ) -> V_82 ;
if ( V_80 == F_16 ( V_462 ) -> V_82 ) {
bool V_460 ;
if ( ! F_250 ( V_2 , V_462 , V_4 , & V_460 ) ) {
F_257 ( & V_30 -> V_437 , V_462 , V_4 ) ;
} else {
F_24 ( V_2 , V_4 ) ;
F_258 ( V_4 , V_460 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_45 . V_148 ||
V_30 -> V_450 [ 0 ] . V_82 != V_80 )
goto V_466;
V_30 -> V_450 [ 0 ] . V_82 = V_82 ;
goto V_465;
}
while ( 1 ) {
if ( ! F_48 ( F_16 ( V_462 ) -> V_80 , V_80 ) )
break;
if ( F_259 ( & V_30 -> V_437 , V_462 ) ) {
V_462 = NULL ;
break;
}
V_462 = F_260 ( & V_30 -> V_437 , V_462 ) ;
}
if ( V_462 && F_41 ( V_80 , F_16 ( V_462 ) -> V_82 ) ) {
if ( ! F_48 ( V_82 , F_16 ( V_462 ) -> V_82 ) ) {
F_62 ( F_63 ( V_2 ) , V_467 ) ;
F_244 ( V_4 ) ;
V_4 = NULL ;
F_234 ( V_2 , V_80 , V_82 ) ;
goto V_466;
}
if ( F_48 ( V_80 , F_16 ( V_462 ) -> V_80 ) ) {
F_234 ( V_2 , V_80 ,
F_16 ( V_462 ) -> V_82 ) ;
} else {
if ( F_259 ( & V_30 -> V_437 ,
V_462 ) )
V_462 = NULL ;
else
V_462 = F_260 (
& V_30 -> V_437 ,
V_462 ) ;
}
}
if ( ! V_462 )
F_256 ( & V_30 -> V_437 , V_4 ) ;
else
F_257 ( & V_30 -> V_437 , V_462 , V_4 ) ;
while ( ! F_261 ( & V_30 -> V_437 , V_4 ) ) {
V_462 = F_262 ( & V_30 -> V_437 , V_4 ) ;
if ( ! F_48 ( V_82 , F_16 ( V_462 ) -> V_80 ) )
break;
if ( F_41 ( V_82 , F_16 ( V_462 ) -> V_82 ) ) {
F_235 ( V_2 , F_16 ( V_462 ) -> V_80 ,
V_82 ) ;
break;
}
F_243 ( V_462 , & V_30 -> V_437 ) ;
F_235 ( V_2 , F_16 ( V_462 ) -> V_80 ,
F_16 ( V_462 ) -> V_82 ) ;
F_62 ( F_63 ( V_2 ) , V_467 ) ;
F_244 ( V_462 ) ;
}
V_466:
if ( F_133 ( V_30 ) )
F_238 ( V_2 , V_80 , V_82 ) ;
V_465:
if ( V_4 ) {
F_24 ( V_2 , V_4 ) ;
F_263 ( V_4 , V_2 ) ;
}
}
static int T_10 F_264 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_468 ,
bool * V_460 )
{
int V_469 ;
struct V_3 * V_470 = F_255 ( & V_2 -> V_455 ) ;
F_265 ( V_4 , V_468 ) ;
V_469 = ( V_470 &&
F_250 ( V_2 , V_470 , V_4 , V_460 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_79 = F_16 ( V_4 ) -> V_82 ;
if ( ! V_469 ) {
F_245 ( & V_2 -> V_455 , V_4 ) ;
F_263 ( V_4 , V_2 ) ;
}
return V_469 ;
}
int F_266 ( struct V_1 * V_2 , struct V_471 * V_254 , T_11 V_457 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_460 ;
if ( V_457 == 0 )
return 0 ;
V_4 = F_267 ( V_457 + sizeof( * V_41 ) , V_2 -> V_472 ) ;
if ( ! V_4 )
goto V_157;
if ( F_246 ( V_2 , V_4 , V_457 + sizeof( * V_41 ) ) )
goto V_473;
V_41 = (struct V_15 * ) F_268 ( V_4 , sizeof( * V_41 ) ) ;
F_269 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_270 ( F_268 ( V_4 , V_457 ) , V_254 -> V_474 , V_457 ) )
goto V_473;
F_16 ( V_4 ) -> V_80 = F_7 ( V_2 ) -> V_79 ;
F_16 ( V_4 ) -> V_82 = F_16 ( V_4 ) -> V_80 + V_457 ;
F_16 ( V_4 ) -> V_142 = F_7 ( V_2 ) -> V_94 - 1 ;
if ( F_264 ( V_2 , V_4 , sizeof( * V_41 ) , & V_460 ) ) {
F_271 ( V_460 ) ;
F_244 ( V_4 ) ;
}
return V_457 ;
V_473:
F_272 ( V_4 ) ;
V_157:
return - V_475 ;
}
static void F_273 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_469 = - 1 ;
bool V_460 = false ;
if ( F_16 ( V_4 ) -> V_80 == F_16 ( V_4 ) -> V_82 )
goto V_476;
F_274 ( V_4 ) ;
F_265 ( V_4 , V_41 -> V_381 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_446 = 0 ;
if ( F_16 ( V_4 ) -> V_80 == V_30 -> V_79 ) {
if ( F_221 ( V_30 ) == 0 )
goto V_477;
if ( V_30 -> V_478 . V_479 == V_480 &&
V_30 -> V_83 == V_30 -> V_79 && V_30 -> V_478 . V_10 &&
F_275 ( V_2 ) && ! V_30 -> V_481 ) {
int V_482 = F_38 (unsigned int, skb->len,
tp->ucopy.len) ;
F_276 ( V_483 ) ;
F_277 () ;
if ( ! F_278 ( V_4 , 0 , V_30 -> V_478 . V_484 , V_482 ) ) {
V_30 -> V_478 . V_10 -= V_482 ;
V_30 -> V_83 += V_482 ;
V_469 = ( V_482 == V_4 -> V_10 ) ;
F_43 ( V_2 ) ;
}
F_279 () ;
}
if ( V_469 <= 0 ) {
V_485:
if ( V_469 < 0 &&
F_246 ( V_2 , V_4 , V_4 -> V_51 ) )
goto V_476;
V_469 = F_264 ( V_2 , V_4 , 0 , & V_460 ) ;
}
V_30 -> V_79 = F_16 ( V_4 ) -> V_82 ;
if ( V_4 -> V_10 )
F_44 ( V_2 , V_4 ) ;
if ( V_41 -> V_456 )
F_226 ( V_2 ) ;
if ( ! F_240 ( & V_30 -> V_437 ) ) {
F_241 ( V_2 ) ;
if ( F_240 ( & V_30 -> V_437 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_148 )
F_239 ( V_30 ) ;
F_195 ( V_2 ) ;
if ( V_469 > 0 )
F_258 ( V_4 , V_460 ) ;
if ( ! F_224 ( V_2 , V_424 ) )
V_2 -> V_486 ( V_2 , 0 ) ;
return;
}
if ( ! F_48 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_79 ) ) {
F_62 ( F_63 ( V_2 ) , V_448 ) ;
F_234 ( V_2 , F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ;
V_477:
F_10 ( V_2 ) ;
F_45 ( V_2 ) ;
V_476:
F_244 ( V_4 ) ;
return;
}
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 + F_221 ( V_30 ) ) )
goto V_477;
F_10 ( V_2 ) ;
if ( F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) ) {
F_207 ( V_2 , L_19 ,
V_30 -> V_79 , F_16 ( V_4 ) -> V_80 ,
F_16 ( V_4 ) -> V_82 ) ;
F_234 ( V_2 , F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) ;
if ( ! F_221 ( V_30 ) )
goto V_477;
goto V_485;
}
F_254 ( V_2 , V_4 ) ;
}
static struct V_3 * F_280 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_487 * V_488 )
{
struct V_3 * V_489 = NULL ;
if ( ! F_261 ( V_488 , V_4 ) )
V_489 = F_262 ( V_488 , V_4 ) ;
F_243 ( V_4 , V_488 ) ;
F_244 ( V_4 ) ;
F_62 ( F_63 ( V_2 ) , V_490 ) ;
return V_489 ;
}
static void
F_281 ( struct V_1 * V_2 , struct V_487 * V_488 ,
struct V_3 * V_491 , struct V_3 * V_470 ,
T_1 V_492 , T_1 V_465 )
{
struct V_3 * V_4 , * V_493 ;
bool V_494 ;
V_4 = V_491 ;
V_495:
V_494 = true ;
F_282 (list, skb, n) {
if ( V_4 == V_470 )
break;
if ( ! F_41 ( V_492 , F_16 ( V_4 ) -> V_82 ) ) {
V_4 = F_280 ( V_2 , V_4 , V_488 ) ;
if ( ! V_4 )
break;
goto V_495;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_456 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_41 ( F_16 ( V_4 ) -> V_80 , V_492 ) ) ) {
V_494 = false ;
break;
}
if ( ! F_261 ( V_488 , V_4 ) ) {
struct V_3 * V_489 = F_262 ( V_488 , V_4 ) ;
if ( V_489 != V_470 &&
F_16 ( V_4 ) -> V_82 != F_16 ( V_489 ) -> V_80 ) {
V_494 = false ;
break;
}
}
V_492 = F_16 ( V_4 ) -> V_82 ;
}
if ( V_494 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_456 )
return;
while ( F_41 ( V_492 , V_465 ) ) {
struct V_3 * V_496 ;
unsigned int V_497 = F_283 ( V_4 ) ;
int V_498 = F_284 ( V_497 , 0 ) ;
if ( V_498 < 0 )
return;
if ( V_465 - V_492 < V_498 )
V_498 = V_465 - V_492 ;
V_496 = F_267 ( V_498 + V_497 , V_499 ) ;
if ( ! V_496 )
return;
F_285 ( V_496 , F_286 ( V_4 ) - V_4 -> V_491 ) ;
F_287 ( V_496 , ( F_288 ( V_4 ) -
V_4 -> V_491 ) ) ;
F_289 ( V_496 , ( F_4 ( V_4 ) -
V_4 -> V_491 ) ) ;
F_290 ( V_496 , V_497 ) ;
memcpy ( V_496 -> V_491 , V_4 -> V_491 , V_497 ) ;
memcpy ( V_496 -> V_500 , V_4 -> V_500 , sizeof( V_4 -> V_500 ) ) ;
F_16 ( V_496 ) -> V_80 = F_16 ( V_496 ) -> V_82 = V_492 ;
F_291 ( V_488 , V_4 , V_496 ) ;
F_263 ( V_496 , V_2 ) ;
while ( V_498 > 0 ) {
int V_501 = V_492 - F_16 ( V_4 ) -> V_80 ;
int V_457 = F_16 ( V_4 ) -> V_82 - V_492 ;
F_83 ( V_501 < 0 ) ;
if ( V_457 > 0 ) {
V_457 = F_9 ( V_498 , V_457 ) ;
if ( F_292 ( V_4 , V_501 , F_268 ( V_496 , V_457 ) , V_457 ) )
F_293 () ;
F_16 ( V_496 ) -> V_82 += V_457 ;
V_498 -= V_457 ;
V_492 += V_457 ;
}
if ( ! F_41 ( V_492 , F_16 ( V_4 ) -> V_82 ) ) {
V_4 = F_280 ( V_2 , V_4 , V_488 ) ;
if ( ! V_4 ||
V_4 == V_470 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_456 )
return;
}
}
}
}
static void F_294 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_242 ( & V_30 -> V_437 ) ;
struct V_3 * V_491 ;
T_1 V_492 , V_465 ;
if ( V_4 == NULL )
return;
V_492 = F_16 ( V_4 ) -> V_80 ;
V_465 = F_16 ( V_4 ) -> V_82 ;
V_491 = V_4 ;
for (; ; ) {
struct V_3 * V_489 = NULL ;
if ( ! F_261 ( & V_30 -> V_437 , V_4 ) )
V_489 = F_262 ( & V_30 -> V_437 , V_4 ) ;
V_4 = V_489 ;
if ( ! V_4 ||
F_48 ( F_16 ( V_4 ) -> V_80 , V_465 ) ||
F_41 ( F_16 ( V_4 ) -> V_82 , V_492 ) ) {
F_281 ( V_2 , & V_30 -> V_437 ,
V_491 , V_4 , V_492 , V_465 ) ;
V_491 = V_4 ;
if ( ! V_4 )
break;
V_492 = F_16 ( V_4 ) -> V_80 ;
V_465 = F_16 ( V_4 ) -> V_82 ;
} else {
if ( F_41 ( F_16 ( V_4 ) -> V_80 , V_492 ) )
V_492 = F_16 ( V_4 ) -> V_80 ;
if ( F_48 ( F_16 ( V_4 ) -> V_82 , V_465 ) )
V_465 = F_16 ( V_4 ) -> V_82 ;
}
}
}
static bool F_249 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_502 = false ;
if ( ! F_240 ( & V_30 -> V_437 ) ) {
F_62 ( F_63 ( V_2 ) , V_503 ) ;
F_231 ( & V_30 -> V_437 ) ;
if ( V_30 -> V_45 . V_109 )
F_211 ( & V_30 -> V_45 ) ;
F_46 ( V_2 ) ;
V_502 = true ;
}
return V_502 ;
}
static int F_248 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_207 ( V_2 , L_20 , V_30 -> V_83 ) ;
F_62 ( F_63 ( V_2 ) , V_504 ) ;
if ( F_36 ( & V_2 -> V_70 ) >= V_2 -> V_60 )
F_33 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_294 ( V_2 ) ;
if ( ! F_240 ( & V_2 -> V_455 ) )
F_281 ( V_2 , & V_2 -> V_455 ,
F_242 ( & V_2 -> V_455 ) ,
NULL ,
V_30 -> V_83 , V_30 -> V_79 ) ;
F_46 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_70 ) <= V_2 -> V_60 )
return 0 ;
F_249 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_70 ) <= V_2 -> V_60 )
return 0 ;
F_62 ( F_63 ( V_2 ) , V_505 ) ;
V_30 -> V_348 = 0 ;
return - 1 ;
}
void F_295 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_122 == V_270 &&
V_2 -> V_506 && ! F_296 ( V_507 , & V_2 -> V_506 -> V_337 ) ) {
T_1 V_508 = F_55 ( V_30 , F_204 ( V_2 ) ) ;
T_1 V_509 = F_32 ( V_30 -> V_510 , V_508 ) ;
if ( V_509 < V_30 -> V_100 ) {
V_30 -> V_222 = F_119 ( V_2 ) ;
V_30 -> V_100 = ( V_30 -> V_100 + V_509 ) >> 1 ;
}
V_30 -> V_510 = 0 ;
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
if ( V_30 -> V_101 >= V_30 -> V_100 )
return false ;
return true ;
}
static void F_298 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_297 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_98 ) +
V_47 ) ;
int V_511 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_511 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_68 = V_69 ;
}
V_2 -> V_512 ( V_2 ) ;
}
static void F_299 ( struct V_1 * V_2 )
{
if ( F_224 ( V_2 , V_513 ) ) {
F_300 ( V_2 , V_513 ) ;
if ( V_2 -> V_506 &&
F_296 ( V_507 , & V_2 -> V_506 -> V_337 ) )
F_298 ( V_2 ) ;
}
}
static inline void F_301 ( struct V_1 * V_2 )
{
F_302 ( V_2 ) ;
F_299 ( V_2 ) ;
}
static void F_303 ( struct V_1 * V_2 , int V_514 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_79 - V_30 -> V_356 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_304 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_514 && F_242 ( & V_30 -> V_437 ) ) ) {
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
T_1 V_198 = F_141 ( V_41 -> V_515 ) ;
if ( V_198 && ! V_516 )
V_198 -- ;
V_198 += F_215 ( V_41 -> V_80 ) ;
if ( F_48 ( V_30 -> V_83 , V_198 ) )
return;
if ( F_41 ( V_198 , V_30 -> V_79 ) )
return;
if ( V_30 -> V_481 && ! F_48 ( V_198 , V_30 -> V_517 ) )
return;
F_309 ( V_2 ) ;
if ( V_30 -> V_517 == V_30 -> V_83 && V_30 -> V_481 &&
! F_224 ( V_2 , V_518 ) && V_30 -> V_83 != V_30 -> V_79 ) {
struct V_3 * V_4 = F_242 ( & V_2 -> V_455 ) ;
V_30 -> V_83 ++ ;
if ( V_4 && ! F_41 ( V_30 -> V_83 , F_16 ( V_4 ) -> V_82 ) ) {
F_243 ( V_4 , & V_2 -> V_455 ) ;
F_244 ( V_4 ) ;
}
}
V_30 -> V_481 = V_519 ;
V_30 -> V_517 = V_198 ;
V_30 -> V_348 = 0 ;
}
static void F_310 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_520 )
F_308 ( V_2 , V_41 ) ;
if ( V_30 -> V_481 == V_519 ) {
T_1 V_198 = V_30 -> V_517 - F_215 ( V_41 -> V_80 ) + ( V_41 -> V_381 * 4 ) -
V_41 -> V_43 ;
if ( V_198 < V_4 -> V_10 ) {
T_4 V_193 ;
if ( F_292 ( V_4 , V_198 , & V_193 , 1 ) )
F_293 () ;
V_30 -> V_481 = V_521 | V_193 ;
if ( ! F_224 ( V_2 , V_424 ) )
V_2 -> V_486 ( V_2 , 0 ) ;
}
}
}
static int F_311 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_522 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_482 = V_4 -> V_10 - V_522 ;
int V_157 ;
F_277 () ;
if ( F_312 ( V_4 ) )
V_157 = F_278 ( V_4 , V_522 , V_30 -> V_478 . V_484 , V_482 ) ;
else
V_157 = F_313 ( V_4 , V_522 ,
V_30 -> V_478 . V_484 ) ;
if ( ! V_157 ) {
V_30 -> V_478 . V_10 -= V_482 ;
V_30 -> V_83 += V_482 ;
F_43 ( V_2 ) ;
}
F_279 () ;
return V_157 ;
}
static T_12 F_314 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_12 V_523 ;
if ( F_275 ( V_2 ) ) {
F_277 () ;
V_523 = F_315 ( V_4 ) ;
F_279 () ;
} else {
V_523 = F_315 ( V_4 ) ;
}
return V_523 ;
}
static inline bool F_316 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_312 ( V_4 ) &&
F_314 ( V_2 , V_4 ) ;
}
static bool F_317 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_522 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_482 = V_4 -> V_10 - V_522 ;
int V_524 ;
bool V_525 = false ;
if ( V_30 -> V_478 . V_526 )
return false ;
if ( ! V_30 -> V_478 . V_527 && V_30 -> V_478 . V_528 )
V_30 -> V_478 . V_527 = F_318 () ;
if ( V_30 -> V_478 . V_527 && F_312 ( V_4 ) ) {
V_524 = F_319 ( V_30 -> V_478 . V_527 ,
V_4 , V_522 ,
V_30 -> V_478 . V_484 , V_482 ,
V_30 -> V_478 . V_528 ) ;
if ( V_524 < 0 )
goto V_188;
V_30 -> V_478 . V_524 = V_524 ;
V_525 = true ;
V_30 -> V_478 . V_10 -= V_482 ;
V_30 -> V_83 += V_482 ;
F_43 ( V_2 ) ;
if ( ( V_30 -> V_478 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_529 ) ||
( F_36 ( & V_2 -> V_70 ) > ( V_2 -> V_60 >> 1 ) ) ) {
V_30 -> V_478 . V_526 = 1 ;
V_2 -> V_486 ( V_2 , 0 ) ;
}
} else if ( V_482 > 0 ) {
V_30 -> V_478 . V_526 = 1 ;
V_2 -> V_486 ( V_2 , 0 ) ;
}
V_188:
return V_525 ;
}
static bool F_320 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_530 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_216 ( V_4 , V_41 , V_30 ) && V_30 -> V_45 . V_253 &&
F_219 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_531 ) {
F_62 ( F_63 ( V_2 ) , V_532 ) ;
F_236 ( V_2 , V_4 ) ;
goto V_533;
}
}
if ( ! F_220 ( V_30 , F_16 ( V_4 ) -> V_80 , F_16 ( V_4 ) -> V_82 ) ) {
if ( ! V_41 -> V_531 ) {
if ( V_41 -> V_43 )
goto V_534;
F_236 ( V_2 , V_4 ) ;
}
goto V_533;
}
if ( V_41 -> V_531 ) {
if ( F_16 ( V_4 ) -> V_80 == V_30 -> V_79 )
F_222 ( V_2 ) ;
else
F_196 ( V_2 ) ;
goto V_533;
}
if ( V_41 -> V_43 ) {
V_534:
if ( V_530 )
F_321 ( F_63 ( V_2 ) , V_535 ) ;
F_62 ( F_63 ( V_2 ) , V_536 ) ;
F_196 ( V_2 ) ;
goto V_533;
}
return true ;
V_533:
F_244 ( V_4 ) ;
return false ;
}
void F_322 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_94 ( V_2 -> V_537 == NULL ) )
F_2 ( V_2 ) -> V_538 -> V_539 ( V_2 , V_4 ) ;
V_30 -> V_45 . V_253 = 0 ;
if ( ( F_5 ( V_41 ) & V_540 ) == V_30 -> V_348 &&
F_16 ( V_4 ) -> V_80 == V_30 -> V_79 &&
! F_48 ( F_16 ( V_4 ) -> V_142 , V_30 -> V_96 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_413 ) {
if ( ! F_213 ( V_30 , V_41 ) )
goto V_541;
if ( ( T_5 ) ( V_30 -> V_45 . V_354 - V_30 -> V_45 . V_353 ) < 0 )
goto V_541;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_413 ) &&
V_30 -> V_79 == V_30 -> V_356 )
F_198 ( V_30 ) ;
F_203 ( V_2 , V_4 , 0 ) ;
F_244 ( V_4 ) ;
F_301 ( V_2 ) ;
return;
} else {
F_321 ( F_63 ( V_2 ) , V_535 ) ;
goto V_533;
}
} else {
int V_469 = 0 ;
int V_525 = 0 ;
bool V_460 = false ;
if ( V_30 -> V_83 == V_30 -> V_79 &&
V_10 - V_18 <= V_30 -> V_478 . V_10 ) {
#ifdef F_323
if ( V_30 -> V_478 . V_479 == V_480 &&
F_275 ( V_2 ) &&
F_317 ( V_2 , V_4 , V_18 ) ) {
V_525 = 1 ;
V_469 = 1 ;
}
#endif
if ( V_30 -> V_478 . V_479 == V_480 &&
F_275 ( V_2 ) && ! V_525 ) {
F_276 ( V_483 ) ;
if ( ! F_311 ( V_2 , V_4 , V_18 ) )
V_469 = 1 ;
}
if ( V_469 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_413 ) &&
V_30 -> V_79 == V_30 -> V_356 )
F_198 ( V_30 ) ;
F_42 ( V_2 , V_4 ) ;
F_265 ( V_4 , V_18 ) ;
V_30 -> V_79 = F_16 ( V_4 ) -> V_82 ;
F_62 ( F_63 ( V_2 ) , V_542 ) ;
}
if ( V_525 )
F_324 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_469 ) {
if ( F_316 ( V_2 , V_4 ) )
goto V_543;
if ( ( int ) V_4 -> V_51 > V_2 -> V_544 )
goto V_545;
if ( V_18 ==
( sizeof( struct V_15 ) + V_413 ) &&
V_30 -> V_79 == V_30 -> V_356 )
F_198 ( V_30 ) ;
F_42 ( V_2 , V_4 ) ;
F_62 ( F_63 ( V_2 ) , V_546 ) ;
V_469 = F_264 ( V_2 , V_4 , V_18 ,
& V_460 ) ;
}
F_44 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_142 != V_30 -> V_94 ) {
F_203 ( V_2 , V_4 , V_368 ) ;
F_301 ( V_2 ) ;
if ( ! F_307 ( V_2 ) )
goto V_547;
}
if ( ! V_525 || V_30 -> V_79 != V_30 -> V_356 )
F_303 ( V_2 , 0 ) ;
V_547:
#ifdef F_323
if ( V_525 )
F_245 ( & V_2 -> V_548 , V_4 ) ;
else
#endif
if ( V_469 )
F_258 ( V_4 , V_460 ) ;
V_2 -> V_486 ( V_2 , 0 ) ;
return;
}
}
V_541:
if ( V_10 < ( V_41 -> V_381 << 2 ) || F_316 ( V_2 , V_4 ) )
goto V_543;
if ( ! V_41 -> V_311 && ! V_41 -> V_531 )
goto V_533;
if ( ! F_320 ( V_2 , V_4 , V_41 , 1 ) )
return;
V_545:
if ( F_203 ( V_2 , V_4 , V_365 | V_364 ) < 0 )
goto V_533;
F_42 ( V_2 , V_4 ) ;
F_310 ( V_2 , V_4 , V_41 ) ;
F_273 ( V_2 , V_4 ) ;
F_301 ( V_2 ) ;
F_306 ( V_2 ) ;
return;
V_543:
F_321 ( F_63 ( V_2 ) , V_549 ) ;
F_321 ( F_63 ( V_2 ) , V_535 ) ;
V_533:
F_244 ( V_4 ) ;
}
void F_325 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_228 ( V_2 , V_430 ) ;
if ( V_4 != NULL ) {
V_6 -> V_538 -> V_539 ( V_2 , V_4 ) ;
F_326 ( V_2 , V_4 ) ;
}
V_6 -> V_538 -> V_550 ( V_2 ) ;
F_327 ( V_2 ) ;
F_328 ( V_2 ) ;
V_30 -> V_308 = V_69 ;
F_30 ( V_2 ) ;
if ( F_224 ( V_2 , V_551 ) )
F_329 ( V_2 , F_330 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_346 )
F_331 ( V_30 , V_30 -> V_345 ) ;
else
V_30 -> V_348 = 0 ;
if ( ! F_224 ( V_2 , V_424 ) ) {
V_2 -> V_438 ( V_2 ) ;
F_232 ( V_2 , V_552 , V_553 ) ;
}
}
static bool F_332 ( struct V_1 * V_2 , struct V_3 * V_554 ,
struct V_378 * V_555 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_556 ? F_95 ( V_2 ) : NULL ;
T_7 V_58 = V_30 -> V_45 . V_46 ;
bool V_557 ;
if ( V_58 == V_30 -> V_45 . V_389 ) {
struct V_375 V_558 ;
F_333 ( & V_558 ) ;
V_558 . V_389 = V_558 . V_46 = 0 ;
F_208 ( V_554 , & V_558 , 0 , NULL ) ;
V_58 = V_558 . V_46 ;
}
if ( ! V_30 -> V_559 )
V_555 -> V_10 = - 1 ;
V_557 = ( V_555 -> V_10 <= 0 && V_13 && V_30 -> V_309 ) ;
F_334 ( V_2 , V_58 , V_555 , V_557 ) ;
if ( V_13 ) {
F_100 (data, sk) {
if ( V_13 == F_74 ( V_2 ) ||
F_335 ( V_2 , V_13 ) )
break;
}
F_174 ( V_2 ) ;
return true ;
}
V_30 -> V_560 = V_30 -> V_556 ;
return false ;
}
static int F_336 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_378 V_379 = { . V_10 = - 1 } ;
int V_561 = V_30 -> V_45 . V_46 ;
F_208 ( V_4 , & V_30 -> V_45 , 0 , & V_379 ) ;
if ( V_30 -> V_45 . V_253 && V_30 -> V_45 . V_81 )
V_30 -> V_45 . V_81 -= V_30 -> V_412 ;
if ( V_41 -> V_311 ) {
if ( ! F_48 ( F_16 ( V_4 ) -> V_142 , V_30 -> V_94 ) ||
F_48 ( F_16 ( V_4 ) -> V_142 , V_30 -> V_96 ) )
goto V_562;
if ( V_30 -> V_45 . V_253 && V_30 -> V_45 . V_81 &&
! F_182 ( V_30 -> V_45 . V_81 , V_30 -> V_252 ,
V_69 ) ) {
F_62 ( F_63 ( V_2 ) , V_563 ) ;
goto V_562;
}
if ( V_41 -> V_531 ) {
F_222 ( V_2 ) ;
goto V_533;
}
if ( ! V_41 -> V_43 )
goto V_564;
F_17 ( V_30 , V_41 ) ;
F_337 ( V_30 , F_16 ( V_4 ) -> V_80 ) ;
F_203 ( V_2 , V_4 , V_365 ) ;
V_30 -> V_79 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_356 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_345 = F_141 ( V_41 -> V_52 ) ;
if ( ! V_30 -> V_45 . V_393 ) {
V_30 -> V_45 . V_346 = V_30 -> V_45 . V_565 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_253 ) {
V_30 -> V_45 . V_397 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_413 ;
V_30 -> V_57 -= V_413 ;
F_198 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_133 ( V_30 ) && V_566 )
F_338 ( V_30 ) ;
F_339 ( V_2 ) ;
F_161 ( V_2 , V_6 -> V_289 ) ;
F_37 ( V_2 ) ;
V_30 -> V_83 = V_30 -> V_79 ;
F_340 () ;
F_325 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_559 || V_30 -> V_556 ) &&
F_332 ( V_2 , V_4 , & V_379 ) )
return - 1 ;
if ( V_2 -> V_567 ||
V_6 -> V_568 . V_569 ||
V_6 -> V_8 . V_26 ) {
F_45 ( V_2 ) ;
V_6 -> V_8 . V_87 = V_69 ;
F_10 ( V_2 ) ;
F_125 ( V_2 , V_570 ,
V_571 , V_235 ) ;
V_533:
F_244 ( V_4 ) ;
return 0 ;
} else {
F_197 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_531 ) {
goto V_564;
}
if ( V_30 -> V_45 . V_355 && V_30 -> V_45 . V_253 &&
F_341 ( & V_30 -> V_45 , 0 ) )
goto V_564;
if ( V_41 -> V_43 ) {
F_228 ( V_2 , V_429 ) ;
if ( V_30 -> V_45 . V_253 ) {
V_30 -> V_45 . V_397 = 1 ;
F_198 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_413 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_79 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_356 = F_16 ( V_4 ) -> V_80 + 1 ;
V_30 -> V_345 = F_141 ( V_41 -> V_52 ) ;
V_30 -> V_344 = F_16 ( V_4 ) -> V_80 ;
V_30 -> V_135 = V_30 -> V_345 ;
F_18 ( V_30 , V_41 ) ;
F_339 ( V_2 ) ;
F_161 ( V_2 , V_6 -> V_289 ) ;
F_37 ( V_2 ) ;
F_342 ( V_2 ) ;
#if 0
return -1;
#else
goto V_533;
#endif
}
V_564:
F_333 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_561 ;
goto V_533;
V_562:
F_333 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_561 ;
return 1 ;
}
int F_343 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_306 * V_307 ;
int V_572 = 0 ;
bool V_573 ;
V_30 -> V_45 . V_253 = 0 ;
switch ( V_2 -> V_416 ) {
case V_422 :
goto V_533;
case V_574 :
if ( V_41 -> V_311 )
return 1 ;
if ( V_41 -> V_531 )
goto V_533;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_456 )
goto V_533;
if ( V_6 -> V_538 -> V_575 ( V_2 , V_4 ) < 0 )
return 1 ;
F_272 ( V_4 ) ;
return 0 ;
}
goto V_533;
case V_417 :
V_572 = F_336 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_572 >= 0 )
return V_572 ;
F_310 ( V_2 , V_4 , V_41 ) ;
F_244 ( V_4 ) ;
F_301 ( V_2 ) ;
return 0 ;
}
V_307 = V_30 -> V_314 ;
if ( V_307 != NULL ) {
F_271 ( V_2 -> V_416 != V_429 &&
V_2 -> V_416 != V_434 ) ;
if ( F_344 ( V_2 , V_4 , V_307 , NULL , true ) == NULL )
goto V_533;
}
if ( ! V_41 -> V_311 && ! V_41 -> V_531 )
goto V_533;
if ( ! F_320 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
V_573 = F_203 ( V_2 , V_4 , V_365 |
V_364 ) > 0 ;
switch ( V_2 -> V_416 ) {
case V_429 :
if ( ! V_573 )
return 1 ;
if ( V_307 ) {
V_30 -> V_309 = V_307 -> V_576 ;
F_345 ( V_2 , V_307 , false ) ;
} else {
V_6 -> V_538 -> V_550 ( V_2 ) ;
F_328 ( V_2 ) ;
F_339 ( V_2 ) ;
F_30 ( V_2 ) ;
V_30 -> V_83 = V_30 -> V_79 ;
}
F_340 () ;
F_228 ( V_2 , V_430 ) ;
V_2 -> V_438 ( V_2 ) ;
if ( V_2 -> V_506 )
F_232 ( V_2 , V_552 , V_553 ) ;
V_30 -> V_94 = F_16 ( V_4 ) -> V_142 ;
V_30 -> V_345 = F_141 ( V_41 -> V_52 ) << V_30 -> V_45 . V_346 ;
F_337 ( V_30 , F_16 ( V_4 ) -> V_80 ) ;
F_172 ( V_2 , V_307 ) ;
if ( V_30 -> V_45 . V_397 )
V_30 -> V_57 -= V_413 ;
if ( V_307 ) {
F_174 ( V_2 ) ;
} else
F_327 ( V_2 ) ;
F_50 ( V_2 ) ;
V_30 -> V_308 = V_69 ;
F_37 ( V_2 ) ;
F_346 ( V_30 ) ;
break;
case V_434 : {
struct V_103 * V_104 ;
int V_577 ;
if ( V_307 != NULL ) {
if ( ! V_573 )
return 1 ;
F_345 ( V_2 , V_307 , false ) ;
F_174 ( V_2 ) ;
}
if ( V_30 -> V_94 != V_30 -> V_578 )
break;
F_228 ( V_2 , V_435 ) ;
V_2 -> V_426 |= V_579 ;
V_104 = F_204 ( V_2 ) ;
if ( V_104 )
F_205 ( V_104 ) ;
if ( ! F_224 ( V_2 , V_424 ) ) {
V_2 -> V_438 ( V_2 ) ;
break;
}
if ( V_30 -> V_580 < 0 ||
( F_16 ( V_4 ) -> V_82 != F_16 ( V_4 ) -> V_80 &&
F_48 ( F_16 ( V_4 ) -> V_82 - V_41 -> V_456 , V_30 -> V_79 ) ) ) {
F_225 ( V_2 ) ;
F_62 ( F_63 ( V_2 ) , V_581 ) ;
return 1 ;
}
V_577 = F_347 ( V_2 ) ;
if ( V_577 > V_582 ) {
F_329 ( V_2 , V_577 - V_582 ) ;
} else if ( V_41 -> V_456 || F_275 ( V_2 ) ) {
F_329 ( V_2 , V_577 ) ;
} else {
F_229 ( V_2 , V_435 , V_577 ) ;
goto V_533;
}
break;
}
case V_432 :
if ( V_30 -> V_94 == V_30 -> V_578 ) {
F_229 ( V_2 , V_436 , 0 ) ;
goto V_533;
}
break;
case V_433 :
if ( V_30 -> V_94 == V_30 -> V_578 ) {
F_348 ( V_2 ) ;
F_225 ( V_2 ) ;
goto V_533;
}
break;
}
F_310 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_416 ) {
case V_420 :
case V_432 :
case V_433 :
if ( ! F_41 ( F_16 ( V_4 ) -> V_80 , V_30 -> V_79 ) )
break;
case V_434 :
case V_435 :
if ( V_2 -> V_426 & V_427 ) {
if ( F_16 ( V_4 ) -> V_82 != F_16 ( V_4 ) -> V_80 &&
F_48 ( F_16 ( V_4 ) -> V_82 - V_41 -> V_456 , V_30 -> V_79 ) ) {
F_62 ( F_63 ( V_2 ) , V_581 ) ;
F_222 ( V_2 ) ;
return 1 ;
}
}
case V_430 :
F_273 ( V_2 , V_4 ) ;
V_572 = 1 ;
break;
}
if ( V_2 -> V_416 != V_422 ) {
F_301 ( V_2 ) ;
F_306 ( V_2 ) ;
}
if ( ! V_572 ) {
V_533:
F_244 ( V_4 ) ;
}
return 0 ;
}
