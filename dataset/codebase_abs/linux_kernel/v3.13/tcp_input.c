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
const struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_44 , V_45 ;
T_1 V_46 ;
V_45 = F_21 ( T_1 , V_30 -> V_47 . V_48 , V_30 -> V_49 ) +
V_50 +
F_22 ( sizeof( struct V_51 ) ) ;
V_45 = F_23 ( V_45 ) +
F_22 ( sizeof( struct V_3 ) ) ;
V_46 = F_21 ( T_1 , V_52 , V_30 -> V_53 ) ;
V_46 = F_21 ( T_1 , V_46 , V_30 -> V_54 + 1 ) ;
V_44 = 2 * V_46 * V_45 ;
if ( V_2 -> V_55 < V_44 )
V_2 -> V_55 = F_9 ( V_44 , V_56 [ 2 ] ) ;
}
static int F_24 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_57 = F_25 ( V_4 -> V_57 ) >> 1 ;
int V_58 = F_25 ( V_59 [ 2 ] ) >> 1 ;
while ( V_30 -> V_60 <= V_58 ) {
if ( V_57 <= V_4 -> V_10 )
return 2 * F_2 ( V_2 ) -> V_8 . V_12 ;
V_57 >>= 1 ;
V_58 >>= 1 ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_60 < V_30 -> V_61 &&
( int ) V_30 -> V_60 < F_27 ( V_2 ) &&
! F_28 ( V_2 ) ) {
int V_62 ;
if ( F_25 ( V_4 -> V_57 ) <= V_4 -> V_10 )
V_62 = 2 * V_30 -> V_63 ;
else
V_62 = F_24 ( V_2 , V_4 ) ;
if ( V_62 ) {
V_62 = F_21 ( int , V_62 , 2 * V_4 -> V_10 ) ;
V_30 -> V_60 = F_9 ( V_30 -> V_60 + V_62 ,
V_30 -> V_61 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_64 = F_7 ( V_2 ) -> V_63 ;
int V_65 ;
V_65 = 2 * F_30 ( V_64 + V_50 ) *
F_31 ( V_64 ) ;
if ( V_66 )
V_65 <<= 2 ;
if ( V_2 -> V_67 < V_65 )
V_2 -> V_67 = F_9 ( V_65 , V_59 [ 2 ] ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_68 ;
if ( ! ( V_2 -> V_69 & V_70 ) )
F_29 ( V_2 ) ;
if ( ! ( V_2 -> V_69 & V_71 ) )
F_20 ( V_2 ) ;
V_30 -> V_72 . V_73 = V_30 -> V_23 ;
V_30 -> V_72 . time = V_74 ;
V_30 -> V_72 . V_75 = V_30 -> V_76 ;
V_68 = F_33 ( V_2 ) ;
if ( V_30 -> V_61 >= V_68 ) {
V_30 -> V_61 = V_68 ;
if ( V_77 && V_68 > 4 * V_30 -> V_63 )
V_30 -> V_61 = F_34 ( V_68 -
( V_68 >> V_77 ) ,
4 * V_30 -> V_63 ) ;
}
if ( V_77 &&
V_30 -> V_61 > 2 * V_30 -> V_63 &&
V_30 -> V_61 + V_30 -> V_63 > V_68 )
V_30 -> V_61 = F_34 ( 2 * V_30 -> V_63 , V_68 - V_30 -> V_63 ) ;
V_30 -> V_60 = F_9 ( V_30 -> V_60 , V_30 -> V_61 ) ;
V_30 -> V_78 = V_74 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_67 < V_59 [ 2 ] &&
! ( V_2 -> V_69 & V_70 ) &&
! F_28 ( V_2 ) &&
F_36 ( V_2 ) < F_37 ( V_2 , 0 ) ) {
V_2 -> V_67 = F_9 ( F_38 ( & V_2 -> V_79 ) ,
V_59 [ 2 ] ) ;
}
if ( F_38 ( & V_2 -> V_79 ) > V_2 -> V_67 )
V_30 -> V_60 = F_9 ( V_30 -> V_61 , 2U * V_30 -> V_63 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned int V_80 = F_40 (unsigned int, tp->advmss, tp->mss_cache) ;
V_80 = F_9 ( V_80 , V_30 -> V_23 / 2 ) ;
V_80 = F_9 ( V_80 , V_14 ) ;
V_80 = F_34 ( V_80 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_80 ;
}
static void F_41 ( struct V_29 * V_30 , T_1 V_81 , int V_82 )
{
T_1 V_83 = V_30 -> V_84 . V_85 ;
long V_86 = V_81 ;
if ( V_86 == 0 )
V_86 = 1 ;
if ( V_83 != 0 ) {
if ( ! V_82 ) {
V_86 -= ( V_83 >> 3 ) ;
V_83 += V_86 ;
} else {
V_86 <<= 3 ;
if ( V_86 < V_83 )
V_83 = V_86 ;
}
} else {
V_83 = V_86 << 3 ;
}
if ( V_30 -> V_84 . V_85 != V_83 )
V_30 -> V_84 . V_85 = V_83 ;
}
static inline void F_42 ( struct V_29 * V_30 )
{
if ( V_30 -> V_84 . time == 0 )
goto V_87;
if ( F_43 ( V_30 -> V_88 , V_30 -> V_84 . V_75 ) )
return;
F_41 ( V_30 , V_74 - V_30 -> V_84 . time , 1 ) ;
V_87:
V_30 -> V_84 . V_75 = V_30 -> V_88 + V_30 -> V_23 ;
V_30 -> V_84 . time = V_74 ;
}
static inline void F_44 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_47 . V_89 &&
( F_16 ( V_4 ) -> V_90 -
F_16 ( V_4 ) -> V_75 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_41 ( V_30 , V_74 - V_30 -> V_47 . V_89 , 0 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int time ;
int V_91 ;
time = V_74 - V_30 -> V_72 . time ;
if ( time < ( V_30 -> V_84 . V_85 >> 3 ) || V_30 -> V_84 . V_85 == 0 )
return;
V_91 = V_30 -> V_76 - V_30 -> V_72 . V_75 ;
if ( V_91 <= V_30 -> V_72 . V_73 )
goto V_87;
if ( V_66 &&
! ( V_2 -> V_69 & V_70 ) ) {
int V_92 , V_65 , V_93 ;
V_92 = ( V_91 << 1 ) + 16 * V_30 -> V_63 ;
if ( V_91 >=
V_30 -> V_72 . V_73 + ( V_30 -> V_72 . V_73 >> 2 ) ) {
if ( V_91 >=
V_30 -> V_72 . V_73 + ( V_30 -> V_72 . V_73 >> 1 ) )
V_92 <<= 1 ;
else
V_92 += ( V_92 >> 1 ) ;
}
V_65 = F_30 ( V_30 -> V_63 + V_50 ) ;
while ( F_25 ( V_65 ) < V_30 -> V_63 )
V_65 += 128 ;
V_93 = F_9 ( V_92 / V_30 -> V_63 * V_65 , V_59 [ 2 ] ) ;
if ( V_93 > V_2 -> V_67 ) {
V_2 -> V_67 = V_93 ;
V_30 -> V_61 = V_92 ;
}
}
V_30 -> V_72 . V_73 = V_91 ;
V_87:
V_30 -> V_72 . V_75 = V_30 -> V_76 ;
V_30 -> V_72 . time = V_74 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_94 ;
F_47 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_42 ( V_30 ) ;
V_94 = V_74 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_86 = V_94 - V_6 -> V_8 . V_95 ;
if ( V_86 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_86 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_86 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_96 )
V_6 -> V_8 . V_27 = V_6 -> V_96 ;
} else if ( V_86 > V_6 -> V_96 ) {
F_8 ( V_2 ) ;
F_48 ( V_2 ) ;
}
}
V_6 -> V_8 . V_95 = V_94 ;
F_15 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_26 ( V_2 , V_4 ) ;
}
static void F_49 ( struct V_1 * V_2 , const T_2 V_97 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_86 = V_97 ;
if ( V_86 == 0 )
V_86 = 1 ;
if ( V_30 -> V_98 != 0 ) {
V_86 -= ( V_30 -> V_98 >> 3 ) ;
V_30 -> V_98 += V_86 ;
if ( V_86 < 0 ) {
V_86 = - V_86 ;
V_86 -= ( V_30 -> V_99 >> 2 ) ;
if ( V_86 > 0 )
V_86 >>= 3 ;
} else {
V_86 -= ( V_30 -> V_99 >> 2 ) ;
}
V_30 -> V_99 += V_86 ;
if ( V_30 -> V_99 > V_30 -> V_100 ) {
V_30 -> V_100 = V_30 -> V_99 ;
if ( V_30 -> V_100 > V_30 -> V_101 )
V_30 -> V_101 = V_30 -> V_100 ;
}
if ( F_50 ( V_30 -> V_102 , V_30 -> V_103 ) ) {
if ( V_30 -> V_100 < V_30 -> V_101 )
V_30 -> V_101 -= ( V_30 -> V_101 - V_30 -> V_100 ) >> 2 ;
V_30 -> V_103 = V_30 -> V_104 ;
V_30 -> V_100 = F_51 ( V_2 ) ;
}
} else {
V_30 -> V_98 = V_86 << 3 ;
V_30 -> V_99 = V_86 << 1 ;
V_30 -> V_100 = V_30 -> V_101 = F_34 ( V_30 -> V_99 , F_51 ( V_2 ) ) ;
V_30 -> V_103 = V_30 -> V_104 ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_105 ;
V_105 = ( T_3 ) V_30 -> V_49 * 2 * ( V_106 << 3 ) ;
V_105 *= F_34 ( V_30 -> V_53 , V_30 -> V_107 ) ;
if ( V_30 -> V_98 > 8 + 2 )
F_53 ( V_105 , V_30 -> V_98 ) ;
F_54 ( V_2 -> V_108 ) = F_40 ( T_3 , V_105 ,
V_2 -> V_109 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_96 = F_56 ( V_30 ) ;
F_57 ( V_2 ) ;
}
T_2 F_58 ( const struct V_29 * V_30 , const struct V_110 * V_111 )
{
T_2 V_112 = ( V_111 ? F_59 ( V_111 , V_113 ) : 0 ) ;
if ( ! V_112 )
V_112 = V_52 ;
return F_40 ( T_2 , V_112 , V_30 -> V_114 ) ;
}
void F_60 ( struct V_29 * V_30 )
{
if ( F_61 ( V_30 ) )
V_30 -> V_115 = NULL ;
V_30 -> V_47 . V_116 &= ~ V_117 ;
}
static void F_62 ( struct V_29 * V_30 )
{
V_30 -> V_47 . V_116 |= V_118 ;
}
static void F_63 ( struct V_1 * V_2 , const int V_119 ,
const int V_120 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_119 > V_30 -> V_54 ) {
int V_121 ;
V_30 -> V_54 = F_9 ( V_122 , V_119 ) ;
if ( V_120 )
V_121 = V_123 ;
else if ( F_64 ( V_30 ) )
V_121 = V_124 ;
else if ( F_61 ( V_30 ) )
V_121 = V_125 ;
else
V_121 = V_126 ;
F_65 ( F_66 ( V_2 ) , V_121 ) ;
#if V_127 > 1
F_67 ( L_1 ,
V_30 -> V_47 . V_116 , F_2 ( V_2 ) -> V_128 ,
V_30 -> V_54 ,
V_30 -> V_129 ,
V_30 -> V_130 ,
V_30 -> V_131 ? V_30 -> V_132 : 0 ) ;
#endif
F_60 ( V_30 ) ;
}
if ( V_119 > 0 )
F_68 ( V_30 ) ;
}
static void F_69 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_133 == NULL ) ||
F_43 ( F_16 ( V_4 ) -> V_75 ,
F_16 ( V_30 -> V_133 ) -> V_75 ) )
V_30 -> V_133 = V_4 ;
if ( ! V_30 -> V_134 ||
F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_135 ) )
V_30 -> V_135 = F_16 ( V_4 ) -> V_90 ;
}
static void F_70 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_136 & ( V_137 | V_138 ) ) ) {
F_69 ( V_30 , V_4 ) ;
V_30 -> V_134 += F_71 ( V_4 ) ;
F_16 ( V_4 ) -> V_136 |= V_137 ;
}
}
static void F_72 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_69 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_136 & ( V_137 | V_138 ) ) ) {
V_30 -> V_134 += F_71 ( V_4 ) ;
F_16 ( V_4 ) -> V_136 |= V_137 ;
}
}
static bool F_73 ( struct V_29 * V_30 , bool V_139 ,
T_1 V_140 , T_1 V_90 )
{
if ( F_50 ( V_90 , V_30 -> V_104 ) || ! F_43 ( V_140 , V_90 ) )
return false ;
if ( ! F_43 ( V_140 , V_30 -> V_104 ) )
return false ;
if ( F_50 ( V_140 , V_30 -> V_102 ) )
return true ;
if ( ! V_139 || ! V_30 -> V_131 )
return false ;
if ( F_50 ( V_90 , V_30 -> V_102 ) )
return false ;
if ( ! F_43 ( V_140 , V_30 -> V_131 ) )
return true ;
if ( ! F_50 ( V_90 , V_30 -> V_131 ) )
return false ;
return ! F_43 ( V_140 , V_90 - V_30 -> V_141 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_142 = 0 ;
T_1 V_143 = V_30 -> V_104 ;
T_1 V_144 = F_75 ( V_30 ) ;
if ( ! F_61 ( V_30 ) || ! V_30 -> V_145 ||
! F_50 ( V_144 , V_30 -> V_146 ) ||
V_6 -> V_128 != V_147 )
return;
F_76 (skb, sk) {
T_1 V_148 = F_16 ( V_4 ) -> V_148 ;
if ( V_4 == F_77 ( V_2 ) )
break;
if ( V_142 == V_30 -> V_145 )
break;
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_102 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_136 & V_149 ) )
continue;
if ( F_50 ( V_144 , V_148 ) ) {
F_16 ( V_4 ) -> V_136 &= ~ V_149 ;
V_30 -> V_145 -= F_71 ( V_4 ) ;
F_72 ( V_30 , V_4 ) ;
F_65 ( F_66 ( V_2 ) , V_150 ) ;
} else {
if ( F_43 ( V_148 , V_143 ) )
V_143 = V_148 ;
V_142 += F_71 ( V_4 ) ;
}
}
if ( V_30 -> V_145 )
V_30 -> V_146 = V_143 ;
}
static bool F_78 ( struct V_1 * V_2 , const struct V_3 * V_151 ,
struct V_152 * V_153 , int V_154 ,
T_1 V_155 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_156 = F_79 ( & V_153 [ 0 ] . V_140 ) ;
T_1 V_157 = F_79 ( & V_153 [ 0 ] . V_90 ) ;
bool V_158 = false ;
if ( F_43 ( V_156 , F_16 ( V_151 ) -> V_148 ) ) {
V_158 = true ;
F_62 ( V_30 ) ;
F_65 ( F_66 ( V_2 ) , V_159 ) ;
} else if ( V_154 > 1 ) {
T_1 V_160 = F_79 ( & V_153 [ 1 ] . V_90 ) ;
T_1 V_161 = F_79 ( & V_153 [ 1 ] . V_140 ) ;
if ( ! F_50 ( V_157 , V_160 ) &&
! F_43 ( V_156 , V_161 ) ) {
V_158 = true ;
F_62 ( V_30 ) ;
F_65 ( F_66 ( V_2 ) ,
V_162 ) ;
}
}
if ( V_158 && V_30 -> V_131 && V_30 -> V_132 &&
! F_50 ( V_157 , V_155 ) &&
F_50 ( V_157 , V_30 -> V_131 ) )
V_30 -> V_132 -- ;
return V_158 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_140 , T_1 V_90 )
{
int V_163 ;
bool V_164 ;
unsigned int V_165 ;
unsigned int V_64 ;
V_164 = ! F_50 ( V_140 , F_16 ( V_4 ) -> V_75 ) &&
! F_43 ( V_90 , F_16 ( V_4 ) -> V_90 ) ;
if ( F_71 ( V_4 ) > 1 && ! V_164 &&
F_50 ( F_16 ( V_4 ) -> V_90 , V_140 ) ) {
V_64 = F_81 ( V_4 ) ;
V_164 = ! F_50 ( V_140 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! V_164 ) {
V_165 = V_140 - F_16 ( V_4 ) -> V_75 ;
if ( V_165 < V_64 )
V_165 = V_64 ;
} else {
V_165 = V_90 - F_16 ( V_4 ) -> V_75 ;
if ( V_165 < V_64 )
return - V_166 ;
}
if ( V_165 > V_64 ) {
unsigned int V_167 = ( V_165 / V_64 ) * V_64 ;
if ( ! V_164 && V_167 < V_165 ) {
V_167 += V_64 ;
if ( V_167 > V_4 -> V_10 )
return 0 ;
}
V_165 = V_167 ;
}
V_163 = F_82 ( V_2 , V_4 , V_165 , V_64 ) ;
if ( V_163 < 0 )
return V_163 ;
}
return V_164 ;
}
static T_4 F_83 ( struct V_1 * V_2 ,
struct V_168 * V_169 , T_4 V_136 ,
T_1 V_140 , T_1 V_90 ,
int V_158 , int V_170 , T_1 V_171 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_172 = V_169 -> V_172 ;
if ( V_158 && ( V_136 & V_173 ) ) {
if ( V_30 -> V_131 && V_30 -> V_132 &&
F_50 ( V_90 , V_30 -> V_131 ) )
V_30 -> V_132 -- ;
if ( V_136 & V_138 )
V_169 -> V_174 = F_9 ( V_172 , V_169 -> V_174 ) ;
}
if ( ! F_50 ( V_90 , V_30 -> V_102 ) )
return V_136 ;
if ( ! ( V_136 & V_138 ) ) {
if ( V_136 & V_149 ) {
if ( V_136 & V_137 ) {
V_136 &= ~ ( V_137 | V_149 ) ;
V_30 -> V_134 -= V_170 ;
V_30 -> V_145 -= V_170 ;
}
} else {
if ( ! ( V_136 & V_173 ) ) {
if ( F_43 ( V_140 ,
F_75 ( V_30 ) ) )
V_169 -> V_174 = F_9 ( V_172 ,
V_169 -> V_174 ) ;
if ( ! F_50 ( V_90 , V_30 -> V_175 ) )
V_169 -> V_176 |= V_177 ;
if ( V_169 -> V_85 < 0 )
V_169 -> V_85 = V_74 - V_171 ;
}
if ( V_136 & V_137 ) {
V_136 &= ~ V_137 ;
V_30 -> V_134 -= V_170 ;
}
}
V_136 |= V_138 ;
V_169 -> V_176 |= V_178 ;
V_30 -> V_130 += V_170 ;
V_172 += V_170 ;
if ( ! F_61 ( V_30 ) && ( V_30 -> V_115 != NULL ) &&
F_43 ( V_140 , F_16 ( V_30 -> V_115 ) -> V_75 ) )
V_30 -> V_179 += V_170 ;
if ( V_172 > V_30 -> V_129 )
V_30 -> V_129 = V_172 ;
}
if ( V_158 && ( V_136 & V_149 ) ) {
V_136 &= ~ V_149 ;
V_30 -> V_145 -= V_170 ;
}
return V_136 ;
}
static bool F_84 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_168 * V_169 ,
unsigned int V_170 , int V_180 , int V_64 ,
bool V_158 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_181 = F_85 ( V_2 , V_4 ) ;
T_1 V_140 = F_16 ( V_4 ) -> V_75 ;
T_1 V_90 = V_140 + V_180 ;
F_86 ( ! V_170 ) ;
F_83 ( V_2 , V_169 , F_16 ( V_4 ) -> V_136 ,
V_140 , V_90 , V_158 , V_170 ,
F_16 ( V_4 ) -> V_182 ) ;
if ( V_4 == V_30 -> V_115 )
V_30 -> V_179 += V_170 ;
F_16 ( V_181 ) -> V_90 += V_180 ;
F_16 ( V_4 ) -> V_75 += V_180 ;
F_3 ( V_181 ) -> V_183 += V_170 ;
F_86 ( F_3 ( V_4 ) -> V_183 < V_170 ) ;
F_3 ( V_4 ) -> V_183 -= V_170 ;
if ( ! F_3 ( V_181 ) -> V_11 ) {
F_3 ( V_181 ) -> V_11 = V_64 ;
F_3 ( V_181 ) -> V_184 = V_2 -> V_185 ;
}
if ( F_3 ( V_4 ) -> V_183 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_184 = 0 ;
}
F_16 ( V_181 ) -> V_136 |= ( F_16 ( V_4 ) -> V_136 & V_186 ) ;
if ( V_4 -> V_10 > 0 ) {
F_86 ( ! F_71 ( V_4 ) ) ;
F_65 ( F_66 ( V_2 ) , V_187 ) ;
return false ;
}
if ( V_4 == V_30 -> V_133 )
V_30 -> V_133 = V_181 ;
if ( V_4 == V_30 -> V_115 ) {
V_30 -> V_115 = V_181 ;
V_30 -> V_179 -= F_71 ( V_181 ) ;
}
F_16 ( V_181 ) -> V_188 |= F_16 ( V_4 ) -> V_188 ;
if ( F_16 ( V_4 ) -> V_188 & V_189 )
F_16 ( V_181 ) -> V_90 ++ ;
if ( V_4 == F_87 ( V_2 ) )
F_88 ( V_2 , V_4 ) ;
F_89 ( V_4 , V_2 ) ;
F_90 ( V_2 , V_4 ) ;
F_65 ( F_66 ( V_2 ) , V_190 ) ;
return true ;
}
static int F_91 ( const struct V_3 * V_4 )
{
return F_71 ( V_4 ) == 1 ? V_4 -> V_10 : F_81 ( V_4 ) ;
}
static int F_92 ( const struct V_3 * V_4 )
{
return ! F_93 ( V_4 ) && F_94 ( V_4 ) ;
}
static struct V_3 * F_95 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_168 * V_169 ,
T_1 V_140 , T_1 V_90 ,
bool V_158 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_181 ;
int V_64 ;
int V_170 = 0 ;
int V_10 ;
int V_164 ;
if ( ! F_96 ( V_2 ) )
goto V_191;
if ( ! V_158 &&
( F_16 ( V_4 ) -> V_136 & ( V_137 | V_149 ) ) == V_149 )
goto V_191;
if ( ! F_92 ( V_4 ) )
goto V_191;
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_102 ) )
goto V_191;
if ( F_97 ( V_4 == F_98 ( V_2 ) ) )
goto V_191;
V_181 = F_85 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_181 ) -> V_136 & V_192 ) != V_138 )
goto V_191;
V_164 = ! F_50 ( V_140 , F_16 ( V_4 ) -> V_75 ) &&
! F_43 ( V_90 , F_16 ( V_4 ) -> V_90 ) ;
if ( V_164 ) {
V_10 = V_4 -> V_10 ;
V_170 = F_71 ( V_4 ) ;
V_64 = F_91 ( V_4 ) ;
if ( V_64 != F_91 ( V_181 ) )
goto V_191;
} else {
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_140 ) )
goto V_193;
if ( F_71 ( V_4 ) <= 1 )
goto V_193;
V_164 = ! F_50 ( V_140 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! V_164 ) {
goto V_191;
}
V_10 = V_90 - F_16 ( V_4 ) -> V_75 ;
F_86 ( V_10 < 0 ) ;
F_86 ( V_10 > V_4 -> V_10 ) ;
V_64 = F_81 ( V_4 ) ;
if ( V_64 != F_91 ( V_181 ) )
goto V_191;
if ( V_10 == V_64 ) {
V_170 = 1 ;
} else if ( V_10 < V_64 ) {
goto V_193;
} else {
V_170 = V_10 / V_64 ;
V_10 = V_170 * V_64 ;
}
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_75 + V_10 , V_30 -> V_102 ) )
goto V_191;
if ( ! F_99 ( V_181 , V_4 , V_10 ) )
goto V_191;
if ( ! F_84 ( V_2 , V_4 , V_169 , V_170 , V_10 , V_64 , V_158 ) )
goto V_194;
if ( V_181 == F_100 ( V_2 ) )
goto V_194;
V_4 = F_101 ( V_2 , V_181 ) ;
if ( ! F_92 ( V_4 ) ||
( V_4 == F_77 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_136 & V_192 ) != V_138 ) ||
( V_64 != F_91 ( V_4 ) ) )
goto V_194;
V_10 = V_4 -> V_10 ;
if ( F_99 ( V_181 , V_4 , V_10 ) ) {
V_170 += F_71 ( V_4 ) ;
F_84 ( V_2 , V_4 , V_169 , F_71 ( V_4 ) , V_10 , V_64 , 0 ) ;
}
V_194:
V_169 -> V_172 += V_170 ;
return V_181 ;
V_193:
return V_4 ;
V_191:
F_65 ( F_66 ( V_2 ) , V_195 ) ;
return NULL ;
}
static struct V_3 * F_102 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_196 * V_197 ,
struct V_168 * V_169 ,
T_1 V_140 , T_1 V_90 ,
bool V_198 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_199 ;
F_103 (skb, sk) {
int V_164 = 0 ;
bool V_158 = V_198 ;
if ( V_4 == F_77 ( V_2 ) )
break;
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_90 ) )
break;
if ( ( V_197 != NULL ) &&
F_43 ( F_16 ( V_4 ) -> V_75 , V_197 -> V_90 ) ) {
V_164 = F_80 ( V_2 , V_4 ,
V_197 -> V_140 ,
V_197 -> V_90 ) ;
if ( V_164 > 0 )
V_158 = true ;
}
if ( V_164 <= 0 ) {
V_199 = F_95 ( V_2 , V_4 , V_169 ,
V_140 , V_90 , V_158 ) ;
if ( V_199 != NULL ) {
if ( V_199 != V_4 ) {
V_4 = V_199 ;
continue;
}
V_164 = 0 ;
} else {
V_164 = F_80 ( V_2 , V_4 ,
V_140 ,
V_90 ) ;
}
}
if ( F_97 ( V_164 < 0 ) )
break;
if ( V_164 ) {
F_16 ( V_4 ) -> V_136 =
F_83 ( V_2 ,
V_169 ,
F_16 ( V_4 ) -> V_136 ,
F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ,
V_158 ,
F_71 ( V_4 ) ,
F_16 ( V_4 ) -> V_182 ) ;
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 ,
F_75 ( V_30 ) ) )
F_88 ( V_2 , V_4 ) ;
}
V_169 -> V_172 += F_71 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_104 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_168 * V_169 ,
T_1 V_200 )
{
F_103 (skb, sk) {
if ( V_4 == F_77 ( V_2 ) )
break;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_200 ) )
break;
V_169 -> V_172 += F_71 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_105 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_196 * V_197 ,
struct V_168 * V_169 ,
T_1 V_200 )
{
if ( V_197 == NULL )
return V_4 ;
if ( F_43 ( V_197 -> V_140 , V_200 ) ) {
V_4 = F_104 ( V_4 , V_2 , V_169 , V_197 -> V_140 ) ;
V_4 = F_102 ( V_4 , V_2 , NULL , V_169 ,
V_197 -> V_140 , V_197 -> V_90 ,
1 ) ;
}
return V_4 ;
}
static int F_106 ( const struct V_29 * V_30 , const struct V_196 * V_201 )
{
return V_201 < V_30 -> V_202 + F_107 ( V_30 -> V_202 ) ;
}
static int
F_108 ( struct V_1 * V_2 , const struct V_3 * V_151 ,
T_1 V_155 , T_5 * V_203 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_204 = ( F_4 ( V_151 ) +
F_16 ( V_151 ) -> V_136 ) ;
struct V_152 * V_205 = (struct V_152 * ) ( V_204 + 2 ) ;
struct V_196 V_153 [ V_206 ] ;
struct V_196 * V_201 ;
struct V_168 V_169 ;
struct V_3 * V_4 ;
int V_154 = F_9 ( V_206 , ( V_204 [ 1 ] - V_207 ) >> 3 ) ;
int V_208 ;
bool V_209 = false ;
int V_210 , V_211 ;
int V_212 ;
V_169 . V_176 = 0 ;
V_169 . V_174 = V_30 -> V_107 ;
V_169 . V_85 = - 1 ;
if ( ! V_30 -> V_130 ) {
if ( F_109 ( V_30 -> V_129 ) )
V_30 -> V_129 = 0 ;
F_110 ( V_2 ) ;
}
V_209 = F_78 ( V_2 , V_151 , V_205 ,
V_154 , V_155 ) ;
if ( V_209 )
V_169 . V_176 |= V_213 ;
if ( F_43 ( F_16 ( V_151 ) -> V_148 , V_155 - V_30 -> V_141 ) )
return 0 ;
if ( ! V_30 -> V_107 )
goto V_194;
V_208 = 0 ;
V_212 = 0 ;
for ( V_210 = 0 ; V_210 < V_154 ; V_210 ++ ) {
bool V_158 = ! V_210 && V_209 ;
V_153 [ V_208 ] . V_140 = F_79 ( & V_205 [ V_210 ] . V_140 ) ;
V_153 [ V_208 ] . V_90 = F_79 ( & V_205 [ V_210 ] . V_90 ) ;
if ( ! F_73 ( V_30 , V_158 ,
V_153 [ V_208 ] . V_140 ,
V_153 [ V_208 ] . V_90 ) ) {
int V_121 ;
if ( V_158 ) {
if ( ! V_30 -> V_131 )
V_121 = V_214 ;
else
V_121 = V_215 ;
} else {
if ( ( F_16 ( V_151 ) -> V_148 != V_30 -> V_102 ) &&
! F_50 ( V_153 [ V_208 ] . V_90 , V_30 -> V_102 ) )
continue;
V_121 = V_216 ;
}
F_65 ( F_66 ( V_2 ) , V_121 ) ;
if ( V_210 == 0 )
V_212 = - 1 ;
continue;
}
if ( ! F_50 ( V_153 [ V_208 ] . V_90 , V_155 ) )
continue;
V_208 ++ ;
}
for ( V_210 = V_208 - 1 ; V_210 > 0 ; V_210 -- ) {
for ( V_211 = 0 ; V_211 < V_210 ; V_211 ++ ) {
if ( F_50 ( V_153 [ V_211 ] . V_140 , V_153 [ V_211 + 1 ] . V_140 ) ) {
F_111 ( V_153 [ V_211 ] , V_153 [ V_211 + 1 ] ) ;
if ( V_211 == V_212 )
V_212 = V_211 + 1 ;
}
}
}
V_4 = F_98 ( V_2 ) ;
V_169 . V_172 = 0 ;
V_210 = 0 ;
if ( ! V_30 -> V_130 ) {
V_201 = V_30 -> V_202 + F_107 ( V_30 -> V_202 ) ;
} else {
V_201 = V_30 -> V_202 ;
while ( F_106 ( V_30 , V_201 ) && ! V_201 -> V_140 &&
! V_201 -> V_90 )
V_201 ++ ;
}
while ( V_210 < V_208 ) {
T_1 V_140 = V_153 [ V_210 ] . V_140 ;
T_1 V_90 = V_153 [ V_210 ] . V_90 ;
bool V_158 = ( V_209 && ( V_210 == V_212 ) ) ;
struct V_196 * V_197 = NULL ;
if ( V_209 && ( ( V_210 + 1 ) == V_212 ) )
V_197 = & V_153 [ V_210 + 1 ] ;
while ( F_106 ( V_30 , V_201 ) &&
! F_43 ( V_140 , V_201 -> V_90 ) )
V_201 ++ ;
if ( F_106 ( V_30 , V_201 ) && ! V_158 &&
F_50 ( V_90 , V_201 -> V_140 ) ) {
if ( F_43 ( V_140 , V_201 -> V_140 ) ) {
V_4 = F_104 ( V_4 , V_2 , & V_169 ,
V_140 ) ;
V_4 = F_102 ( V_4 , V_2 , V_197 ,
& V_169 ,
V_140 ,
V_201 -> V_140 ,
V_158 ) ;
}
if ( ! F_50 ( V_90 , V_201 -> V_90 ) )
goto V_217;
V_4 = F_105 ( V_4 , V_2 , V_197 ,
& V_169 ,
V_201 -> V_90 ) ;
if ( F_75 ( V_30 ) == V_201 -> V_90 ) {
V_4 = F_87 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_169 . V_172 = V_30 -> V_129 ;
V_201 ++ ;
goto V_218;
}
V_4 = F_104 ( V_4 , V_2 , & V_169 , V_201 -> V_90 ) ;
V_201 ++ ;
continue;
}
if ( ! F_43 ( V_140 , F_75 ( V_30 ) ) ) {
V_4 = F_87 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_169 . V_172 = V_30 -> V_129 ;
}
V_4 = F_104 ( V_4 , V_2 , & V_169 , V_140 ) ;
V_218:
V_4 = F_102 ( V_4 , V_2 , V_197 , & V_169 ,
V_140 , V_90 , V_158 ) ;
V_217:
V_210 ++ ;
}
for ( V_210 = 0 ; V_210 < F_107 ( V_30 -> V_202 ) - V_208 ; V_210 ++ ) {
V_30 -> V_202 [ V_210 ] . V_140 = 0 ;
V_30 -> V_202 [ V_210 ] . V_90 = 0 ;
}
for ( V_211 = 0 ; V_211 < V_208 ; V_211 ++ )
V_30 -> V_202 [ V_210 ++ ] = V_153 [ V_211 ] ;
F_74 ( V_2 ) ;
F_112 ( V_30 ) ;
if ( ( V_169 . V_174 < V_30 -> V_129 ) &&
( ( F_2 ( V_2 ) -> V_128 != V_219 ) || V_30 -> V_131 ) )
F_63 ( V_2 , V_30 -> V_129 - V_169 . V_174 , 0 ) ;
V_194:
#if V_127 > 0
F_109 ( ( int ) V_30 -> V_130 < 0 ) ;
F_109 ( ( int ) V_30 -> V_134 < 0 ) ;
F_109 ( ( int ) V_30 -> V_145 < 0 ) ;
F_109 ( ( int ) F_113 ( V_30 ) < 0 ) ;
#endif
* V_203 = V_169 . V_85 ;
return V_169 . V_176 ;
}
static bool F_114 ( struct V_29 * V_30 )
{
T_1 V_220 ;
V_220 = F_34 ( V_30 -> V_134 , 1U ) ;
V_220 = F_9 ( V_220 , V_30 -> V_107 ) ;
if ( ( V_30 -> V_130 + V_220 ) > V_30 -> V_107 ) {
V_30 -> V_130 = V_30 -> V_107 - V_220 ;
return true ;
}
return false ;
}
static void F_115 ( struct V_1 * V_2 , const int V_221 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_114 ( V_30 ) )
F_63 ( V_2 , V_30 -> V_107 + V_221 , 0 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_130 ++ ;
F_115 ( V_2 , 0 ) ;
F_112 ( V_30 ) ;
}
static void F_117 ( struct V_1 * V_2 , int V_222 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_222 > 0 ) {
if ( V_222 - 1 >= V_30 -> V_130 )
V_30 -> V_130 = 0 ;
else
V_30 -> V_130 -= V_222 - 1 ;
}
F_115 ( V_2 , V_222 ) ;
F_112 ( V_30 ) ;
}
static inline void F_118 ( struct V_29 * V_30 )
{
V_30 -> V_130 = 0 ;
}
static void F_119 ( struct V_29 * V_30 )
{
V_30 -> V_145 = 0 ;
V_30 -> V_134 = 0 ;
V_30 -> V_131 = 0 ;
V_30 -> V_132 = 0 ;
}
void F_120 ( struct V_29 * V_30 )
{
F_119 ( V_30 ) ;
V_30 -> V_129 = 0 ;
V_30 -> V_130 = 0 ;
}
void F_121 ( struct V_1 * V_2 , int V_223 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_224 = false ;
if ( V_6 -> V_128 <= V_225 ||
! F_50 ( V_30 -> V_175 , V_30 -> V_102 ) ||
( V_6 -> V_128 == V_219 && ! V_6 -> V_226 ) ) {
V_224 = true ;
V_30 -> V_227 = F_122 ( V_2 ) ;
V_30 -> V_228 = V_6 -> V_229 -> V_230 ( V_2 ) ;
F_123 ( V_2 , V_231 ) ;
}
V_30 -> V_53 = 1 ;
V_30 -> V_232 = 0 ;
V_30 -> V_78 = V_74 ;
F_119 ( V_30 ) ;
if ( F_64 ( V_30 ) )
F_118 ( V_30 ) ;
V_30 -> V_131 = V_30 -> V_102 ;
if ( V_223 ) {
V_30 -> V_130 = 0 ;
V_30 -> V_129 = 0 ;
}
F_124 ( V_30 ) ;
F_76 (skb, sk) {
if ( V_4 == F_77 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_136 & V_173 )
V_30 -> V_131 = 0 ;
F_16 ( V_4 ) -> V_136 &= ( ~ V_192 ) | V_138 ;
if ( ! ( F_16 ( V_4 ) -> V_136 & V_138 ) || V_223 ) {
F_16 ( V_4 ) -> V_136 &= ~ V_138 ;
F_16 ( V_4 ) -> V_136 |= V_137 ;
V_30 -> V_134 += F_71 ( V_4 ) ;
V_30 -> V_135 = F_16 ( V_4 ) -> V_90 ;
}
}
F_112 ( V_30 ) ;
if ( V_6 -> V_128 <= V_225 &&
V_30 -> V_130 >= V_233 )
V_30 -> V_54 = F_40 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_125 ( V_2 , V_219 ) ;
V_30 -> V_175 = V_30 -> V_104 ;
F_12 ( V_30 ) ;
V_30 -> V_234 = V_235 &&
( V_224 || V_6 -> V_226 ) &&
! F_2 ( V_2 ) -> V_236 . V_237 ;
}
static bool F_126 ( struct V_1 * V_2 , int V_176 )
{
if ( V_176 & V_238 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_65 ( F_66 ( V_2 ) , V_239 ) ;
F_121 ( V_2 , 1 ) ;
V_6 -> V_226 ++ ;
F_127 ( V_2 , F_98 ( V_2 ) ) ;
F_128 ( V_2 , V_240 ,
V_6 -> V_96 , V_241 ) ;
return true ;
}
return false ;
}
static inline int F_129 ( const struct V_29 * V_30 )
{
return F_64 ( V_30 ) ? V_30 -> V_130 + 1 : V_30 -> V_129 ;
}
static inline int F_130 ( const struct V_29 * V_30 )
{
return F_61 ( V_30 ) ? V_30 -> V_129 : V_30 -> V_130 + 1 ;
}
static bool F_131 ( struct V_1 * V_2 , int V_176 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_242 ;
if ( V_243 < 2 || V_243 > 3 ||
( V_176 & V_244 ) || ! V_30 -> V_98 )
return false ;
V_242 = F_21 (unsigned long, (tp->srtt >> 5), msecs_to_jiffies(2)) ;
if ( ! F_132 ( F_2 ( V_2 ) -> V_245 , ( V_246 + V_242 ) ) )
return false ;
F_128 ( V_2 , V_247 , V_242 ,
V_241 ) ;
return true ;
}
static bool F_133 ( struct V_1 * V_2 , int V_176 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_107 ;
if ( V_30 -> V_134 )
return true ;
if ( F_130 ( V_30 ) > V_30 -> V_54 )
return true ;
V_107 = V_30 -> V_107 ;
if ( V_107 <= V_30 -> V_54 &&
V_30 -> V_130 >= F_21 ( T_2 , V_107 / 2 , V_233 ) &&
! F_134 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_248 || V_249 ) &&
F_135 ( V_30 ) && F_130 ( V_30 ) > 1 &&
F_136 ( V_30 ) && ! F_77 ( V_2 ) )
return true ;
if ( V_30 -> V_250 && ! V_30 -> V_145 && V_30 -> V_130 &&
( V_30 -> V_107 >= ( V_30 -> V_130 + 1 ) && V_30 -> V_107 < 4 ) &&
! F_134 ( V_2 ) )
return ! F_131 ( V_2 , V_176 ) ;
return false ;
}
static void F_137 ( struct V_1 * V_2 , int V_251 , int V_252 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_142 , V_253 ;
int V_163 ;
unsigned int V_64 ;
const T_1 V_254 = F_136 ( V_30 ) ? V_30 -> V_104 : V_30 -> V_175 ;
F_109 ( V_251 > V_30 -> V_107 ) ;
if ( V_30 -> V_115 ) {
V_4 = V_30 -> V_115 ;
V_142 = V_30 -> V_179 ;
if ( V_252 && V_4 != F_98 ( V_2 ) )
return;
} else {
V_4 = F_98 ( V_2 ) ;
V_142 = 0 ;
}
F_103 (skb, sk) {
if ( V_4 == F_77 ( V_2 ) )
break;
V_30 -> V_115 = V_4 ;
V_30 -> V_179 = V_142 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_254 ) )
break;
V_253 = V_142 ;
if ( F_61 ( V_30 ) || F_64 ( V_30 ) ||
( F_16 ( V_4 ) -> V_136 & V_138 ) )
V_142 += F_71 ( V_4 ) ;
if ( V_142 > V_251 ) {
if ( ( F_136 ( V_30 ) && ! F_61 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_136 & V_138 ) ||
( V_253 >= V_251 ) )
break;
V_64 = F_3 ( V_4 ) -> V_11 ;
V_163 = F_82 ( V_2 , V_4 , ( V_251 - V_253 ) * V_64 , V_64 ) ;
if ( V_163 < 0 )
break;
V_142 = V_251 ;
}
F_70 ( V_30 , V_4 ) ;
if ( V_252 )
break;
}
F_112 ( V_30 ) ;
}
static void F_138 ( struct V_1 * V_2 , int V_255 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_64 ( V_30 ) ) {
F_137 ( V_2 , 1 , 1 ) ;
} else if ( F_61 ( V_30 ) ) {
int V_256 = V_30 -> V_129 - V_30 -> V_54 ;
if ( V_256 <= 0 )
V_256 = 1 ;
F_137 ( V_2 , V_256 , 0 ) ;
} else {
int V_257 = V_30 -> V_130 - V_30 -> V_54 ;
if ( V_257 >= 0 )
F_137 ( V_2 , V_257 , 0 ) ;
else if ( V_255 )
F_137 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_139 ( struct V_29 * V_30 )
{
V_30 -> V_53 = F_9 ( V_30 -> V_53 ,
F_113 ( V_30 ) + F_140 ( V_30 ) ) ;
V_30 -> V_78 = V_74 ;
}
static inline bool F_141 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_258 ||
( V_30 -> V_47 . V_259 && V_30 -> V_47 . V_89 &&
F_43 ( V_30 -> V_47 . V_89 , V_30 -> V_258 ) ) ;
}
static void F_142 ( struct V_1 * V_2 , const char * V_260 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_261 * V_262 = F_143 ( V_2 ) ;
if ( V_2 -> V_263 == V_264 ) {
F_67 ( L_2 ,
V_260 ,
& V_262 -> V_265 , F_144 ( V_262 -> V_266 ) ,
V_30 -> V_53 , F_145 ( V_30 ) ,
V_30 -> V_228 , V_30 -> V_227 ,
V_30 -> V_107 ) ;
}
#if F_146 ( V_267 )
else if ( V_2 -> V_263 == V_268 ) {
struct V_269 * V_270 = F_147 ( V_2 ) ;
F_67 ( L_3 ,
V_260 ,
& V_270 -> V_271 , F_144 ( V_262 -> V_266 ) ,
V_30 -> V_53 , F_145 ( V_30 ) ,
V_30 -> V_228 , V_30 -> V_227 ,
V_30 -> V_107 ) ;
}
#endif
}
static void F_148 ( struct V_1 * V_2 , bool V_272 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_272 ) {
struct V_3 * V_4 ;
F_76 (skb, sk) {
if ( V_4 == F_77 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_136 &= ~ V_137 ;
}
V_30 -> V_134 = 0 ;
F_124 ( V_30 ) ;
}
if ( V_30 -> V_227 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_229 -> V_273 )
V_30 -> V_53 = V_6 -> V_229 -> V_273 ( V_2 ) ;
else
V_30 -> V_53 = F_34 ( V_30 -> V_53 , V_30 -> V_228 << 1 ) ;
if ( V_30 -> V_227 > V_30 -> V_228 ) {
V_30 -> V_228 = V_30 -> V_227 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_53 = F_34 ( V_30 -> V_53 , V_30 -> V_228 ) ;
}
V_30 -> V_78 = V_74 ;
V_30 -> V_131 = 0 ;
}
static inline bool F_149 ( const struct V_29 * V_30 )
{
return V_30 -> V_131 && ( ! V_30 -> V_132 || F_141 ( V_30 ) ) ;
}
static bool F_150 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_149 ( V_30 ) ) {
int V_121 ;
F_142 ( V_2 , F_2 ( V_2 ) -> V_128 == V_219 ? L_4 : L_5 ) ;
F_148 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_128 == V_219 )
V_121 = V_274 ;
else
V_121 = V_275 ;
F_65 ( F_66 ( V_2 ) , V_121 ) ;
}
if ( V_30 -> V_102 == V_30 -> V_175 && F_64 ( V_30 ) ) {
F_139 ( V_30 ) ;
return true ;
}
F_125 ( V_2 , V_276 ) ;
return false ;
}
static bool F_151 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_131 && ! V_30 -> V_132 ) {
F_142 ( V_2 , L_6 ) ;
F_148 ( V_2 , false ) ;
F_65 ( F_66 ( V_2 ) , V_277 ) ;
return true ;
}
return false ;
}
static bool F_152 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_145 )
return true ;
V_4 = F_98 ( V_2 ) ;
if ( F_97 ( V_4 && F_16 ( V_4 ) -> V_136 & V_186 ) )
return true ;
return false ;
}
static bool F_153 ( struct V_1 * V_2 , bool V_278 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_278 || F_149 ( V_30 ) ) {
F_148 ( V_2 , true ) ;
F_142 ( V_2 , L_7 ) ;
F_65 ( F_66 ( V_2 ) , V_274 ) ;
if ( V_278 )
F_65 ( F_66 ( V_2 ) ,
V_279 ) ;
F_2 ( V_2 ) -> V_226 = 0 ;
if ( V_278 || F_136 ( V_30 ) )
F_125 ( V_2 , V_276 ) ;
return true ;
}
return false ;
}
static void F_154 ( struct V_1 * V_2 , const bool V_280 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_175 = V_30 -> V_104 ;
V_30 -> V_281 = 0 ;
V_30 -> V_232 = 0 ;
V_30 -> V_282 = V_30 -> V_53 ;
V_30 -> V_283 = 0 ;
V_30 -> V_284 = 0 ;
if ( V_280 )
V_30 -> V_228 = F_2 ( V_2 ) -> V_229 -> V_230 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_155 ( struct V_1 * V_2 , const int V_285 ,
int V_255 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_286 = 0 ;
int V_287 = V_30 -> V_228 - F_113 ( V_30 ) ;
int V_288 = V_285 -
( V_30 -> V_107 - V_30 -> V_130 ) ;
V_30 -> V_283 += V_288 ;
if ( F_113 ( V_30 ) > V_30 -> V_228 ) {
T_3 V_289 = ( T_3 ) V_30 -> V_228 * V_30 -> V_283 +
V_30 -> V_282 - 1 ;
V_286 = F_156 ( V_289 , V_30 -> V_282 ) - V_30 -> V_284 ;
} else {
V_286 = F_40 ( int , V_287 ,
F_21 ( int , V_30 -> V_283 - V_30 -> V_284 ,
V_288 ) + 1 ) ;
}
V_286 = F_34 ( V_286 , ( V_255 ? 1 : 0 ) ) ;
V_30 -> V_53 = F_113 ( V_30 ) + V_286 ;
}
static inline void F_157 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_128 == V_290 ||
( V_30 -> V_131 && V_30 -> V_228 < V_291 ) ) {
V_30 -> V_53 = V_30 -> V_228 ;
V_30 -> V_78 = V_74 ;
}
F_123 ( V_2 , V_292 ) ;
}
void F_158 ( struct V_1 * V_2 , const int V_280 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_227 = 0 ;
if ( F_2 ( V_2 ) -> V_128 < V_290 ) {
V_30 -> V_131 = 0 ;
F_154 ( V_2 , V_280 ) ;
F_125 ( V_2 , V_290 ) ;
}
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_169 = V_276 ;
if ( F_145 ( V_30 ) || F_152 ( V_2 ) )
V_169 = V_225 ;
if ( F_2 ( V_2 ) -> V_128 != V_169 ) {
F_125 ( V_2 , V_169 ) ;
V_30 -> V_175 = V_30 -> V_104 ;
}
}
static void F_160 ( struct V_1 * V_2 , int V_176 , const int V_285 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_112 ( V_30 ) ;
if ( ! F_152 ( V_2 ) )
V_30 -> V_258 = 0 ;
if ( V_176 & V_244 )
F_158 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_128 != V_290 ) {
F_159 ( V_2 ) ;
} else {
F_155 ( V_2 , V_285 , 0 ) ;
}
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_236 . V_293 = V_6 -> V_236 . V_237 - 1 ;
V_6 -> V_236 . V_237 = 0 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_227 = F_122 ( V_2 ) ;
V_30 -> V_53 = V_30 -> V_53 *
F_163 ( V_2 , V_30 -> V_49 ) /
V_6 -> V_236 . V_237 ;
V_30 -> V_232 = 0 ;
V_30 -> V_78 = V_74 ;
V_30 -> V_228 = F_122 ( V_2 ) ;
V_6 -> V_236 . V_294 = V_6 -> V_236 . V_237 ;
V_6 -> V_236 . V_237 = 0 ;
F_164 ( V_2 , V_6 -> V_295 ) ;
}
void F_165 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_64 = F_166 ( V_2 ) ;
T_1 V_296 = V_30 -> V_134 ;
F_76 (skb, sk) {
if ( V_4 == F_77 ( V_2 ) )
break;
if ( F_91 ( V_4 ) > V_64 &&
! ( F_16 ( V_4 ) -> V_136 & V_138 ) ) {
if ( F_16 ( V_4 ) -> V_136 & V_149 ) {
F_16 ( V_4 ) -> V_136 &= ~ V_149 ;
V_30 -> V_145 -= F_71 ( V_4 ) ;
}
F_72 ( V_30 , V_4 ) ;
}
}
F_167 ( V_30 ) ;
if ( V_296 == V_30 -> V_134 )
return;
if ( F_64 ( V_30 ) )
F_114 ( V_30 ) ;
F_112 ( V_30 ) ;
if ( V_6 -> V_128 != V_219 ) {
V_30 -> V_175 = V_30 -> V_104 ;
V_30 -> V_228 = F_122 ( V_2 ) ;
V_30 -> V_227 = 0 ;
V_30 -> V_131 = 0 ;
F_125 ( V_2 , V_219 ) ;
}
F_168 ( V_2 ) ;
}
static void F_169 ( struct V_1 * V_2 , bool V_297 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_121 ;
if ( F_64 ( V_30 ) )
V_121 = V_298 ;
else
V_121 = V_299 ;
F_65 ( F_66 ( V_2 ) , V_121 ) ;
V_30 -> V_227 = 0 ;
V_30 -> V_131 = V_30 -> V_102 ;
V_30 -> V_132 = V_30 -> V_145 ;
if ( F_2 ( V_2 ) -> V_128 < V_290 ) {
if ( ! V_297 )
V_30 -> V_227 = F_122 ( V_2 ) ;
F_154 ( V_2 , true ) ;
}
F_125 ( V_2 , V_147 ) ;
}
static void F_170 ( struct V_1 * V_2 , int V_176 , bool V_300 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_301 = ! F_43 ( V_30 -> V_102 , V_30 -> V_175 ) ;
if ( V_30 -> V_234 ) {
if ( V_176 & V_177 ) {
F_153 ( V_2 , true ) ;
return;
}
if ( F_50 ( V_30 -> V_104 , V_30 -> V_175 ) &&
( V_176 & V_178 || V_300 ) ) {
V_30 -> V_234 = 0 ;
} else if ( V_176 & V_302 && ! V_301 ) {
V_30 -> V_175 = V_30 -> V_104 ;
F_171 ( V_2 , F_166 ( V_2 ) ,
V_303 ) ;
if ( F_50 ( V_30 -> V_104 , V_30 -> V_175 ) )
return;
V_30 -> V_234 = 0 ;
}
}
if ( V_301 ) {
V_6 -> V_226 = 0 ;
F_150 ( V_2 ) ;
return;
}
if ( V_176 & V_304 )
V_6 -> V_226 = 0 ;
if ( F_64 ( V_30 ) ) {
if ( F_50 ( V_30 -> V_104 , V_30 -> V_175 ) && V_300 )
F_116 ( V_2 ) ;
else if ( V_176 & V_302 )
F_118 ( V_30 ) ;
}
if ( F_153 ( V_2 , false ) )
return;
F_168 ( V_2 ) ;
}
static bool F_172 ( struct V_1 * V_2 , const int V_222 ,
const int V_285 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_131 && F_141 ( V_30 ) ) {
F_63 ( V_2 , F_129 ( V_30 ) + V_222 , 1 ) ;
if ( V_30 -> V_145 ) {
F_155 ( V_2 , V_285 , 0 ) ;
return true ;
}
if ( ! F_152 ( V_2 ) )
V_30 -> V_258 = 0 ;
F_142 ( V_2 , L_8 ) ;
F_148 ( V_2 , true ) ;
F_65 ( F_66 ( V_2 ) , V_305 ) ;
F_159 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_173 ( struct V_1 * V_2 , const int V_222 ,
const int V_285 ,
bool V_300 , int V_176 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_306 = V_300 || ( ( V_176 & V_178 ) &&
( F_129 ( V_30 ) > V_30 -> V_54 ) ) ;
int V_255 = 0 ;
if ( F_109 ( ! V_30 -> V_107 && V_30 -> V_130 ) )
V_30 -> V_130 = 0 ;
if ( F_109 ( ! V_30 -> V_130 && V_30 -> V_129 ) )
V_30 -> V_129 = 0 ;
if ( V_176 & V_244 )
V_30 -> V_227 = 0 ;
if ( F_126 ( V_2 , V_176 ) )
return;
F_112 ( V_30 ) ;
if ( V_6 -> V_128 == V_276 ) {
F_109 ( V_30 -> V_145 != 0 ) ;
V_30 -> V_258 = 0 ;
} else if ( ! F_43 ( V_30 -> V_102 , V_30 -> V_175 ) ) {
switch ( V_6 -> V_128 ) {
case V_290 :
if ( V_30 -> V_102 != V_30 -> V_175 ) {
F_157 ( V_2 ) ;
F_125 ( V_2 , V_276 ) ;
}
break;
case V_147 :
if ( F_64 ( V_30 ) )
F_118 ( V_30 ) ;
if ( F_150 ( V_2 ) )
return;
F_157 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_128 ) {
case V_147 :
if ( ! ( V_176 & V_302 ) ) {
if ( F_64 ( V_30 ) && V_300 )
F_116 ( V_2 ) ;
} else {
if ( F_172 ( V_2 , V_222 , V_285 ) )
return;
V_306 = F_64 ( V_30 ) ||
F_129 ( V_30 ) > V_30 -> V_54 ;
}
if ( F_151 ( V_2 ) ) {
F_159 ( V_2 ) ;
return;
}
break;
case V_219 :
F_170 ( V_2 , V_176 , V_300 ) ;
if ( V_6 -> V_128 != V_276 )
return;
default:
if ( F_64 ( V_30 ) ) {
if ( V_176 & V_302 )
F_118 ( V_30 ) ;
if ( V_300 )
F_116 ( V_2 ) ;
}
if ( V_6 -> V_128 <= V_225 )
F_151 ( V_2 ) ;
if ( ! F_133 ( V_2 , V_176 ) ) {
F_160 ( V_2 , V_176 , V_285 ) ;
return;
}
if ( V_6 -> V_128 < V_290 &&
V_6 -> V_236 . V_237 &&
V_30 -> V_102 == V_30 -> V_307 . V_308 ) {
F_161 ( V_2 ) ;
V_30 -> V_53 ++ ;
F_165 ( V_2 ) ;
return;
}
F_169 ( V_2 , ( V_176 & V_244 ) ) ;
V_255 = 1 ;
}
if ( V_306 )
F_138 ( V_2 , V_255 ) ;
F_155 ( V_2 , V_285 , V_255 ) ;
F_168 ( V_2 ) ;
}
static inline bool F_174 ( struct V_1 * V_2 , const int V_176 ,
T_5 V_309 , T_5 V_203 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_176 & V_310 )
V_309 = - 1 ;
if ( V_309 < 0 )
V_309 = V_203 ;
if ( V_309 < 0 && V_30 -> V_47 . V_259 && V_30 -> V_47 . V_89 &&
V_176 & V_311 )
V_309 = V_74 - V_30 -> V_47 . V_89 ;
if ( V_309 < 0 )
return false ;
F_49 ( V_2 , V_309 ) ;
F_55 ( V_2 ) ;
F_2 ( V_2 ) -> V_312 = 0 ;
return true ;
}
static void F_175 ( struct V_1 * V_2 , const T_1 V_313 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_5 V_309 = - 1 ;
if ( V_313 && ! V_30 -> V_314 )
V_309 = V_74 - V_313 ;
if ( ! V_30 -> V_98 )
F_174 ( V_2 , V_315 , V_309 , - 1 ) ;
}
static void F_176 ( struct V_1 * V_2 , T_1 V_316 , T_1 V_222 , T_1 V_317 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_229 -> V_318 ( V_2 , V_316 , V_222 , V_317 ) ;
F_7 ( V_2 ) -> V_78 = V_74 ;
}
void F_177 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_319 )
return;
if ( ! V_30 -> V_107 ) {
F_178 ( V_2 , V_240 ) ;
} else {
T_1 V_320 = F_2 ( V_2 ) -> V_96 ;
if ( V_6 -> V_321 == V_247 ||
V_6 -> V_321 == V_322 ) {
struct V_3 * V_4 = F_98 ( V_2 ) ;
const T_1 V_323 = F_16 ( V_4 ) -> V_182 + V_320 ;
T_5 V_287 = ( T_5 ) ( V_323 - V_74 ) ;
if ( V_287 > 0 )
V_320 = V_287 ;
}
F_128 ( V_2 , V_240 , V_320 ,
V_241 ) ;
}
}
void F_179 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_177 ( V_2 ) ;
if ( ! V_30 -> V_250 )
return;
F_169 ( V_2 , false ) ;
F_138 ( V_2 , 1 ) ;
F_168 ( V_2 ) ;
}
static T_1 F_180 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_324 ;
F_86 ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_102 ) ) ;
V_324 = F_71 ( V_4 ) ;
if ( F_181 ( V_2 , V_4 , V_30 -> V_102 - F_16 ( V_4 ) -> V_75 ) )
return 0 ;
V_324 -= F_71 ( V_4 ) ;
if ( V_324 ) {
F_86 ( F_71 ( V_4 ) == 0 ) ;
F_86 ( ! F_43 ( F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ) ;
}
return V_324 ;
}
static int F_182 ( struct V_1 * V_2 , int V_325 ,
T_1 V_155 , T_5 V_203 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_94 = V_74 ;
bool V_326 = true ;
int V_176 = 0 ;
T_1 V_327 = 0 ;
T_1 V_174 = V_30 -> V_107 ;
T_1 V_328 = V_30 -> V_130 ;
T_5 V_309 = - 1 ;
T_5 V_329 = - 1 ;
T_6 V_330 = F_183 () ;
bool V_331 ;
while ( ( V_4 = F_98 ( V_2 ) ) && V_4 != F_77 ( V_2 ) ) {
struct V_332 * V_333 = F_16 ( V_4 ) ;
T_1 V_334 ;
T_4 V_136 = V_333 -> V_136 ;
if ( F_50 ( V_333 -> V_90 , V_30 -> V_102 ) ) {
if ( F_71 ( V_4 ) == 1 ||
! F_50 ( V_30 -> V_102 , V_333 -> V_75 ) )
break;
V_334 = F_180 ( V_2 , V_4 ) ;
if ( ! V_334 )
break;
V_326 = false ;
} else {
V_334 = F_71 ( V_4 ) ;
}
if ( V_136 & V_173 ) {
if ( V_136 & V_149 )
V_30 -> V_145 -= V_334 ;
V_176 |= V_310 ;
} else {
V_329 = V_94 - V_333 -> V_182 ;
V_330 = V_4 -> V_335 ;
if ( V_309 < 0 ) {
V_309 = V_329 ;
}
if ( ! ( V_136 & V_138 ) )
V_174 = F_9 ( V_327 , V_174 ) ;
if ( ! F_50 ( V_333 -> V_90 , V_30 -> V_175 ) )
V_176 |= V_177 ;
}
if ( V_136 & V_138 )
V_30 -> V_130 -= V_334 ;
if ( V_136 & V_137 )
V_30 -> V_134 -= V_334 ;
V_30 -> V_107 -= V_334 ;
V_327 += V_334 ;
if ( ! ( V_333 -> V_188 & V_336 ) ) {
V_176 |= V_304 ;
} else {
V_176 |= V_315 ;
V_30 -> V_258 = 0 ;
}
if ( ! V_326 )
break;
F_89 ( V_4 , V_2 ) ;
F_90 ( V_2 , V_4 ) ;
if ( V_4 == V_30 -> V_133 )
V_30 -> V_133 = NULL ;
if ( V_4 == V_30 -> V_115 )
V_30 -> V_115 = NULL ;
}
if ( F_184 ( F_185 ( V_30 -> V_337 , V_155 , V_30 -> V_102 ) ) )
V_30 -> V_337 = V_30 -> V_102 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_136 & V_138 ) )
V_176 |= V_238 ;
V_331 = F_174 ( V_2 , V_176 , V_309 , V_203 ) ;
if ( V_176 & V_311 ) {
const struct V_338 * V_339
= F_2 ( V_2 ) -> V_229 ;
F_177 ( V_2 ) ;
if ( F_97 ( V_6 -> V_236 . V_237 &&
! F_50 ( V_30 -> V_307 . V_340 , V_30 -> V_102 ) ) ) {
F_162 ( V_2 ) ;
}
if ( F_64 ( V_30 ) ) {
F_117 ( V_2 , V_327 ) ;
} else {
int V_287 ;
if ( V_174 < V_325 )
F_63 ( V_2 , V_30 -> V_129 - V_174 , 0 ) ;
V_287 = F_61 ( V_30 ) ? V_327 :
V_328 - V_30 -> V_130 ;
V_30 -> V_179 -= F_9 ( V_30 -> V_179 , V_287 ) ;
}
V_30 -> V_129 -= F_9 ( V_327 , V_30 -> V_129 ) ;
if ( V_339 -> V_327 ) {
T_5 V_341 = - 1 ;
if ( ! ( V_176 & V_310 ) ) {
if ( V_339 -> V_342 & V_343 &&
! F_186 ( V_330 ,
F_183 () ) )
V_341 = F_187 ( F_188 () ,
V_330 ) ;
else if ( V_329 >= 0 )
V_341 = F_189 ( V_329 ) ;
}
V_339 -> V_327 ( V_2 , V_327 , V_341 ) ;
}
} else if ( V_4 && V_331 && V_203 >= 0 &&
V_203 > ( T_5 ) ( V_94 - F_16 ( V_4 ) -> V_182 ) ) {
F_177 ( V_2 ) ;
}
#if V_127 > 0
F_109 ( ( int ) V_30 -> V_130 < 0 ) ;
F_109 ( ( int ) V_30 -> V_134 < 0 ) ;
F_109 ( ( int ) V_30 -> V_145 < 0 ) ;
if ( ! V_30 -> V_107 && F_136 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_134 ) {
F_67 ( L_9 ,
V_30 -> V_134 , V_6 -> V_128 ) ;
V_30 -> V_134 = 0 ;
}
if ( V_30 -> V_130 ) {
F_67 ( L_10 ,
V_30 -> V_130 , V_6 -> V_128 ) ;
V_30 -> V_130 = 0 ;
}
if ( V_30 -> V_145 ) {
F_67 ( L_11 ,
V_30 -> V_145 , V_6 -> V_128 ) ;
V_30 -> V_145 = 0 ;
}
}
#endif
return V_176 ;
}
static void F_190 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_50 ( F_16 ( F_77 ( V_2 ) ) -> V_90 , F_191 ( V_30 ) ) ) {
V_6 -> V_312 = 0 ;
F_178 ( V_2 , V_344 ) ;
} else {
F_128 ( V_2 , V_344 ,
F_9 ( V_6 -> V_96 << V_6 -> V_312 , V_241 ) ,
V_241 ) ;
}
}
static inline bool F_192 ( const struct V_1 * V_2 , const int V_176 )
{
return ! ( V_176 & V_345 ) || ( V_176 & V_346 ) ||
F_2 ( V_2 ) -> V_128 != V_276 ;
}
static inline bool F_193 ( const struct V_1 * V_2 , const int V_176 )
{
if ( F_194 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_54 > V_233 )
return V_176 & V_347 ;
return V_176 & V_304 ;
}
static inline bool F_195 ( const struct V_29 * V_30 ,
const T_1 V_316 , const T_1 V_148 ,
const T_1 V_348 )
{
return F_50 ( V_316 , V_30 -> V_102 ) ||
F_50 ( V_148 , V_30 -> V_349 ) ||
( V_148 == V_30 -> V_349 && V_348 > V_30 -> V_350 ) ;
}
static int F_196 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_316 ,
T_1 V_148 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_176 = 0 ;
T_1 V_348 = F_144 ( F_6 ( V_4 ) -> V_58 ) ;
if ( F_184 ( ! F_6 ( V_4 ) -> V_43 ) )
V_348 <<= V_30 -> V_47 . V_351 ;
if ( F_195 ( V_30 , V_316 , V_148 , V_348 ) ) {
V_176 |= V_352 ;
F_197 ( V_30 , V_148 ) ;
if ( V_30 -> V_350 != V_348 ) {
V_30 -> V_350 = V_348 ;
V_30 -> V_353 = 0 ;
F_198 ( V_2 ) ;
if ( V_348 > V_30 -> V_141 ) {
V_30 -> V_141 = V_348 ;
F_164 ( V_2 , F_2 ( V_2 ) -> V_295 ) ;
}
}
}
V_30 -> V_102 = V_316 ;
return V_176 ;
}
static void F_199 ( struct V_1 * V_2 )
{
static T_1 V_354 ;
static unsigned int V_355 ;
T_1 V_94 = V_246 / V_106 ;
if ( V_94 != V_354 ) {
V_354 = V_94 ;
V_355 = 0 ;
}
if ( ++ V_355 <= V_356 ) {
F_65 ( F_66 ( V_2 ) , V_357 ) ;
F_200 ( V_2 ) ;
}
}
static void F_201 ( struct V_29 * V_30 )
{
V_30 -> V_47 . V_358 = V_30 -> V_47 . V_359 ;
V_30 -> V_47 . V_360 = F_202 () ;
}
static void F_203 ( struct V_29 * V_30 , T_1 V_75 )
{
if ( V_30 -> V_47 . V_259 && ! F_50 ( V_75 , V_30 -> V_361 ) ) {
if ( F_204 ( & V_30 -> V_47 , 0 ) )
F_201 ( V_30 ) ;
}
}
static void F_205 ( struct V_1 * V_2 , T_1 V_316 , int V_176 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_362 = ( V_316 == V_30 -> V_281 ) &&
! ( V_176 & ( V_302 |
V_345 | V_178 ) ) ;
if ( V_362 ) {
V_30 -> V_281 = 0 ;
return;
}
if ( F_50 ( V_316 , V_30 -> V_281 ) ) {
V_30 -> V_281 = 0 ;
if ( ! ( V_176 & V_213 ) ) {
F_154 ( V_2 , true ) ;
F_125 ( V_2 , V_290 ) ;
F_157 ( V_2 ) ;
F_159 ( V_2 ) ;
F_65 ( F_66 ( V_2 ) ,
V_363 ) ;
}
}
}
static int F_206 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_176 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_155 = V_30 -> V_102 ;
T_1 V_148 = F_16 ( V_4 ) -> V_75 ;
T_1 V_316 = F_16 ( V_4 ) -> V_148 ;
bool V_300 = false ;
T_1 V_364 , V_282 = V_30 -> V_53 , V_365 = V_30 -> V_98 ;
T_1 V_325 ;
int V_366 = V_30 -> V_107 ;
const int V_285 = V_30 -> V_107 - V_30 -> V_130 ;
int V_222 = 0 ;
T_5 V_203 = - 1 ;
if ( F_43 ( V_316 , V_155 ) ) {
if ( F_43 ( V_316 , V_155 - V_30 -> V_141 ) ) {
F_199 ( V_2 ) ;
return - 1 ;
}
goto V_367;
}
if ( F_50 ( V_316 , V_30 -> V_104 ) )
goto V_368;
if ( V_6 -> V_321 == V_247 ||
V_6 -> V_321 == V_322 )
F_177 ( V_2 ) ;
if ( F_50 ( V_316 , V_155 ) )
V_176 |= V_302 ;
V_325 = V_30 -> V_129 ;
V_364 = F_113 ( V_30 ) ;
if ( V_176 & V_369 )
F_203 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! ( V_176 & V_370 ) && F_50 ( V_316 , V_155 ) ) {
F_197 ( V_30 , V_148 ) ;
V_30 -> V_102 = V_316 ;
V_176 |= V_352 ;
F_123 ( V_2 , V_371 ) ;
F_65 ( F_66 ( V_2 ) , V_372 ) ;
} else {
if ( V_148 != F_16 ( V_4 ) -> V_90 )
V_176 |= V_373 ;
else
F_65 ( F_66 ( V_2 ) , V_374 ) ;
V_176 |= F_196 ( V_2 , V_4 , V_316 , V_148 ) ;
if ( F_16 ( V_4 ) -> V_136 )
V_176 |= F_108 ( V_2 , V_4 , V_155 ,
& V_203 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_176 |= V_244 ;
F_123 ( V_2 , V_375 ) ;
}
V_2 -> V_376 = 0 ;
V_6 -> V_377 = 0 ;
V_30 -> V_378 = V_74 ;
if ( ! V_366 )
goto V_379;
V_222 = V_30 -> V_107 ;
V_176 |= F_182 ( V_2 , V_325 , V_155 , V_203 ) ;
V_222 -= V_30 -> V_107 ;
if ( F_193 ( V_2 , V_176 ) )
F_176 ( V_2 , V_316 , V_222 , V_364 ) ;
if ( F_192 ( V_2 , V_176 ) ) {
V_300 = ! ( V_176 & ( V_302 | V_345 ) ) ;
F_173 ( V_2 , V_222 , V_285 ,
V_300 , V_176 ) ;
}
if ( V_30 -> V_281 )
F_205 ( V_2 , V_316 , V_176 ) ;
if ( ( V_176 & V_347 ) || ! ( V_176 & V_345 ) ) {
struct V_110 * V_111 = F_207 ( V_2 ) ;
if ( V_111 )
F_208 ( V_111 ) ;
}
if ( V_6 -> V_321 == V_240 )
F_209 ( V_2 ) ;
if ( V_30 -> V_98 != V_365 || V_30 -> V_53 != V_282 )
F_52 ( V_2 ) ;
return 1 ;
V_379:
if ( V_176 & V_213 )
F_173 ( V_2 , V_222 , V_285 ,
V_300 , V_176 ) ;
if ( F_77 ( V_2 ) )
F_190 ( V_2 ) ;
if ( V_30 -> V_281 )
F_205 ( V_2 , V_316 , V_176 ) ;
return 1 ;
V_368:
F_210 ( V_2 , L_12 , V_316 , V_30 -> V_102 , V_30 -> V_104 ) ;
return - 1 ;
V_367:
if ( F_16 ( V_4 ) -> V_136 ) {
V_176 |= F_108 ( V_2 , V_4 , V_155 ,
& V_203 ) ;
F_173 ( V_2 , V_222 , V_285 ,
V_300 , V_176 ) ;
}
F_210 ( V_2 , L_13 , V_316 , V_30 -> V_102 , V_30 -> V_104 ) ;
return 0 ;
}
void F_211 ( const struct V_3 * V_4 ,
struct V_380 * V_381 , int V_382 ,
struct V_383 * V_384 )
{
const unsigned char * V_204 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_385 = ( V_41 -> V_386 * 4 ) - sizeof( struct V_15 ) ;
V_204 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_381 -> V_259 = 0 ;
while ( V_385 > 0 ) {
int V_387 = * V_204 ++ ;
int V_388 ;
switch ( V_387 ) {
case V_389 :
return;
case V_390 :
V_385 -- ;
continue;
default:
V_388 = * V_204 ++ ;
if ( V_388 < 2 )
return;
if ( V_388 > V_385 )
return;
switch ( V_387 ) {
case V_391 :
if ( V_388 == V_392 && V_41 -> V_43 && ! V_382 ) {
T_7 V_393 = F_212 ( V_204 ) ;
if ( V_393 ) {
if ( V_381 -> V_394 &&
V_381 -> V_394 < V_393 )
V_393 = V_381 -> V_394 ;
V_381 -> V_48 = V_393 ;
}
}
break;
case V_395 :
if ( V_388 == V_396 && V_41 -> V_43 &&
! V_382 && V_397 ) {
T_8 V_351 = * ( T_8 * ) V_204 ;
V_381 -> V_398 = 1 ;
if ( V_351 > 14 ) {
F_213 ( L_14 ,
V_399 ,
V_351 ) ;
V_351 = 14 ;
}
V_381 -> V_351 = V_351 ;
}
break;
case V_400 :
if ( ( V_388 == V_401 ) &&
( ( V_382 && V_381 -> V_402 ) ||
( ! V_382 && V_403 ) ) ) {
V_381 -> V_259 = 1 ;
V_381 -> V_359 = F_79 ( V_204 ) ;
V_381 -> V_89 = F_79 ( V_204 + 4 ) ;
}
break;
case V_404 :
if ( V_388 == V_405 && V_41 -> V_43 &&
! V_382 && V_406 ) {
V_381 -> V_116 = V_407 ;
F_214 ( V_381 ) ;
}
break;
case V_408 :
if ( ( V_388 >= ( V_207 + V_409 ) ) &&
! ( ( V_388 - V_207 ) % V_409 ) &&
V_381 -> V_116 ) {
F_16 ( V_4 ) -> V_136 = ( V_204 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_215
case V_410 :
break;
#endif
case V_411 :
if ( V_388 < V_412 ||
F_212 ( V_204 ) != V_413 ||
V_384 == NULL || ! V_41 -> V_43 || ( V_388 & 1 ) )
break;
V_384 -> V_10 = V_388 - V_412 ;
if ( V_384 -> V_10 >= V_414 &&
V_384 -> V_10 <= V_415 )
memcpy ( V_384 -> V_416 , V_204 + 2 , V_384 -> V_10 ) ;
else if ( V_384 -> V_10 != 0 )
V_384 -> V_10 = - 1 ;
break;
}
V_204 += V_388 - 2 ;
V_385 -= V_388 ;
}
}
}
static bool F_216 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_204 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_204 == F_217 ( ( V_390 << 24 ) | ( V_390 << 16 )
| ( V_400 << 8 ) | V_401 ) ) {
V_30 -> V_47 . V_259 = 1 ;
++ V_204 ;
V_30 -> V_47 . V_359 = F_218 ( * V_204 ) ;
++ V_204 ;
if ( * V_204 )
V_30 -> V_47 . V_89 = F_218 ( * V_204 ) - V_30 -> V_417 ;
else
V_30 -> V_47 . V_89 = 0 ;
return true ;
}
return false ;
}
static bool F_219 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 , struct V_29 * V_30 )
{
if ( V_41 -> V_386 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_47 . V_259 = 0 ;
return false ;
} else if ( V_30 -> V_47 . V_402 &&
V_41 -> V_386 == ( ( sizeof( * V_41 ) + V_418 ) / 4 ) ) {
if ( F_216 ( V_30 , V_41 ) )
return true ;
}
F_211 ( V_4 , & V_30 -> V_47 , 1 , NULL ) ;
if ( V_30 -> V_47 . V_259 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_417 ;
return true ;
}
const T_4 * F_220 ( const struct V_15 * V_41 )
{
int V_385 = ( V_41 -> V_386 << 2 ) - sizeof( * V_41 ) ;
const T_4 * V_204 = ( const T_4 * ) ( V_41 + 1 ) ;
if ( V_385 < V_419 )
return NULL ;
while ( V_385 > 0 ) {
int V_387 = * V_204 ++ ;
int V_388 ;
switch( V_387 ) {
case V_389 :
return NULL ;
case V_390 :
V_385 -- ;
continue;
default:
V_388 = * V_204 ++ ;
if ( V_388 < 2 || V_388 > V_385 )
return NULL ;
if ( V_387 == V_410 )
return V_388 == V_419 ? V_204 : NULL ;
}
V_204 += V_388 - 2 ;
V_385 -= V_388 ;
}
return NULL ;
}
static int F_221 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_75 = F_16 ( V_4 ) -> V_75 ;
T_1 V_316 = F_16 ( V_4 ) -> V_148 ;
return (
( V_41 -> V_316 && V_75 == F_16 ( V_4 ) -> V_90 && V_75 == V_30 -> V_88 ) &&
V_316 == V_30 -> V_102 &&
! F_195 ( V_30 , V_316 , V_75 , F_144 ( V_41 -> V_58 ) << V_30 -> V_47 . V_351 ) &&
( T_5 ) ( V_30 -> V_47 . V_358 - V_30 -> V_47 . V_359 ) <= ( F_2 ( V_2 ) -> V_96 * 1024 ) / V_106 ) ;
}
static inline bool F_222 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_204 ( & V_30 -> V_47 , V_420 ) &&
! F_221 ( V_2 , V_4 ) ;
}
static inline bool F_223 ( const struct V_29 * V_30 , T_1 V_75 , T_1 V_90 )
{
return ! F_43 ( V_90 , V_30 -> V_361 ) &&
! F_50 ( V_75 , V_30 -> V_88 + F_224 ( V_30 ) ) ;
}
void F_225 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_421 ) {
case V_422 :
V_2 -> V_423 = V_424 ;
break;
case V_425 :
V_2 -> V_423 = V_426 ;
break;
case V_427 :
return;
default:
V_2 -> V_423 = V_428 ;
}
F_226 () ;
if ( ! F_227 ( V_2 , V_429 ) )
V_2 -> V_430 ( V_2 ) ;
F_228 ( V_2 ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_110 * V_111 ;
F_47 ( V_2 ) ;
V_2 -> V_431 |= V_432 ;
F_230 ( V_2 , V_433 ) ;
switch ( V_2 -> V_421 ) {
case V_434 :
case V_435 :
F_231 ( V_2 , V_425 ) ;
V_111 = F_207 ( V_2 ) ;
if ( ! V_111 || ! F_59 ( V_111 , V_436 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_425 :
case V_437 :
break;
case V_438 :
break;
case V_439 :
F_200 ( V_2 ) ;
F_231 ( V_2 , V_437 ) ;
break;
case V_440 :
F_200 ( V_2 ) ;
F_232 ( V_2 , V_441 , 0 ) ;
break;
default:
F_233 ( L_15 ,
V_399 , V_2 -> V_421 ) ;
break;
}
F_234 ( & V_30 -> V_442 ) ;
if ( F_136 ( V_30 ) )
F_214 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
if ( ! F_227 ( V_2 , V_429 ) ) {
V_2 -> V_443 ( V_2 ) ;
if ( V_2 -> V_431 == V_444 ||
V_2 -> V_421 == V_427 )
F_235 ( V_2 , V_445 , V_446 ) ;
else
F_235 ( V_2 , V_445 , V_447 ) ;
}
}
static inline bool F_236 ( struct V_196 * V_153 , T_1 V_75 ,
T_1 V_90 )
{
if ( ! F_50 ( V_75 , V_153 -> V_90 ) && ! F_50 ( V_153 -> V_140 , V_90 ) ) {
if ( F_43 ( V_75 , V_153 -> V_140 ) )
V_153 -> V_140 = V_75 ;
if ( F_50 ( V_90 , V_153 -> V_90 ) )
V_153 -> V_90 = V_90 ;
return true ;
}
return false ;
}
static void F_237 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_136 ( V_30 ) && V_448 ) {
int V_121 ;
if ( F_43 ( V_75 , V_30 -> V_88 ) )
V_121 = V_449 ;
else
V_121 = V_450 ;
F_65 ( F_66 ( V_2 ) , V_121 ) ;
V_30 -> V_47 . V_451 = 1 ;
V_30 -> V_452 [ 0 ] . V_140 = V_75 ;
V_30 -> V_452 [ 0 ] . V_90 = V_90 ;
}
}
static void F_238 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_47 . V_451 )
F_237 ( V_2 , V_75 , V_90 ) ;
else
F_236 ( V_30 -> V_452 , V_75 , V_90 ) ;
}
static void F_239 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_65 ( F_66 ( V_2 ) , V_453 ) ;
F_10 ( V_2 ) ;
if ( F_136 ( V_30 ) && V_448 ) {
T_1 V_90 = F_16 ( V_4 ) -> V_90 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) )
V_90 = V_30 -> V_88 ;
F_237 ( V_2 , F_16 ( V_4 ) -> V_75 , V_90 ) ;
}
}
F_200 ( V_2 ) ;
}
static void F_240 ( struct V_29 * V_30 )
{
int V_454 ;
struct V_196 * V_153 = & V_30 -> V_455 [ 0 ] ;
struct V_196 * V_456 = V_153 + 1 ;
for ( V_454 = 1 ; V_454 < V_30 -> V_47 . V_154 ; ) {
if ( F_236 ( V_153 , V_456 -> V_140 , V_456 -> V_90 ) ) {
int V_210 ;
V_30 -> V_47 . V_154 -- ;
for ( V_210 = V_454 ; V_210 < V_30 -> V_47 . V_154 ; V_210 ++ )
V_153 [ V_210 ] = V_153 [ V_210 + 1 ] ;
continue;
}
V_454 ++ , V_456 ++ ;
}
}
static void F_241 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_196 * V_153 = & V_30 -> V_455 [ 0 ] ;
int V_457 = V_30 -> V_47 . V_154 ;
int V_454 ;
if ( ! V_457 )
goto V_458;
for ( V_454 = 0 ; V_454 < V_457 ; V_454 ++ , V_153 ++ ) {
if ( F_236 ( V_153 , V_75 , V_90 ) ) {
for (; V_454 > 0 ; V_454 -- , V_153 -- )
F_111 ( * V_153 , * ( V_153 - 1 ) ) ;
if ( V_457 > 1 )
F_240 ( V_30 ) ;
return;
}
}
if ( V_454 >= V_206 ) {
V_454 -- ;
V_30 -> V_47 . V_154 -- ;
V_153 -- ;
}
for (; V_454 > 0 ; V_454 -- , V_153 -- )
* V_153 = * ( V_153 - 1 ) ;
V_458:
V_153 -> V_140 = V_75 ;
V_153 -> V_90 = V_90 ;
V_30 -> V_47 . V_154 ++ ;
}
static void F_242 ( struct V_29 * V_30 )
{
struct V_196 * V_153 = & V_30 -> V_455 [ 0 ] ;
int V_154 = V_30 -> V_47 . V_154 ;
int V_454 ;
if ( F_243 ( & V_30 -> V_442 ) ) {
V_30 -> V_47 . V_154 = 0 ;
return;
}
for ( V_454 = 0 ; V_454 < V_154 ; ) {
if ( ! F_43 ( V_30 -> V_88 , V_153 -> V_140 ) ) {
int V_210 ;
F_109 ( F_43 ( V_30 -> V_88 , V_153 -> V_90 ) ) ;
for ( V_210 = V_454 + 1 ; V_210 < V_154 ; V_210 ++ )
V_30 -> V_455 [ V_210 - 1 ] = V_30 -> V_455 [ V_210 ] ;
V_154 -- ;
continue;
}
V_454 ++ ;
V_153 ++ ;
}
V_30 -> V_47 . V_154 = V_154 ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_459 = V_30 -> V_88 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_245 ( & V_30 -> V_442 ) ) != NULL ) {
if ( F_50 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) )
break;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_459 ) ) {
T_2 V_451 = V_459 ;
if ( F_43 ( F_16 ( V_4 ) -> V_90 , V_459 ) )
V_459 = F_16 ( V_4 ) -> V_90 ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , V_451 ) ;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_210 ( V_2 , L_16 ) ;
F_246 ( V_4 , & V_30 -> V_442 ) ;
F_247 ( V_4 ) ;
continue;
}
F_210 ( V_2 , L_17 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_246 ( V_4 , & V_30 -> V_442 ) ;
F_248 ( & V_2 -> V_460 , V_4 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( F_6 ( V_4 ) -> V_461 )
F_229 ( V_2 ) ;
}
}
static int F_249 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_462 )
{
if ( F_38 ( & V_2 -> V_79 ) > V_2 -> V_67 ||
! F_250 ( V_2 , V_4 , V_462 ) ) {
if ( F_251 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_250 ( V_2 , V_4 , V_462 ) ) {
if ( ! F_252 ( V_2 ) )
return - 1 ;
if ( ! F_250 ( V_2 , V_4 , V_462 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_253 ( struct V_1 * V_2 ,
struct V_3 * V_463 ,
struct V_3 * V_464 ,
bool * V_465 )
{
int V_287 ;
* V_465 = false ;
if ( F_6 ( V_464 ) -> V_461 )
return false ;
if ( F_16 ( V_464 ) -> V_75 != F_16 ( V_463 ) -> V_90 )
return false ;
if ( ! F_254 ( V_463 , V_464 , V_465 , & V_287 ) )
return false ;
F_255 ( V_287 , & V_2 -> V_79 ) ;
F_256 ( V_2 , V_287 ) ;
F_65 ( F_66 ( V_2 ) , V_466 ) ;
F_16 ( V_463 ) -> V_90 = F_16 ( V_464 ) -> V_90 ;
F_16 ( V_463 ) -> V_148 = F_16 ( V_464 ) -> V_148 ;
return true ;
}
static void F_257 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_467 ;
T_1 V_75 , V_90 ;
F_15 ( V_30 , V_4 ) ;
if ( F_97 ( F_249 ( V_2 , V_4 , V_4 -> V_57 ) ) ) {
F_65 ( F_66 ( V_2 ) , V_468 ) ;
F_247 ( V_4 ) ;
return;
}
V_30 -> V_353 = 0 ;
F_47 ( V_2 ) ;
F_65 ( F_66 ( V_2 ) , V_469 ) ;
F_210 ( V_2 , L_18 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_467 = F_258 ( & V_30 -> V_442 ) ;
if ( ! V_467 ) {
if ( F_136 ( V_30 ) ) {
V_30 -> V_47 . V_154 = 1 ;
V_30 -> V_455 [ 0 ] . V_140 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_455 [ 0 ] . V_90 =
F_16 ( V_4 ) -> V_90 ;
}
F_259 ( & V_30 -> V_442 , V_4 ) ;
goto V_470;
}
V_75 = F_16 ( V_4 ) -> V_75 ;
V_90 = F_16 ( V_4 ) -> V_90 ;
if ( V_75 == F_16 ( V_467 ) -> V_90 ) {
bool V_465 ;
if ( ! F_253 ( V_2 , V_467 , V_4 , & V_465 ) ) {
F_260 ( & V_30 -> V_442 , V_467 , V_4 ) ;
} else {
F_26 ( V_2 , V_4 ) ;
F_261 ( V_4 , V_465 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_47 . V_154 ||
V_30 -> V_455 [ 0 ] . V_90 != V_75 )
goto V_471;
V_30 -> V_455 [ 0 ] . V_90 = V_90 ;
goto V_470;
}
while ( 1 ) {
if ( ! F_50 ( F_16 ( V_467 ) -> V_75 , V_75 ) )
break;
if ( F_262 ( & V_30 -> V_442 , V_467 ) ) {
V_467 = NULL ;
break;
}
V_467 = F_263 ( & V_30 -> V_442 , V_467 ) ;
}
if ( V_467 && F_43 ( V_75 , F_16 ( V_467 ) -> V_90 ) ) {
if ( ! F_50 ( V_90 , F_16 ( V_467 ) -> V_90 ) ) {
F_65 ( F_66 ( V_2 ) , V_472 ) ;
F_247 ( V_4 ) ;
V_4 = NULL ;
F_237 ( V_2 , V_75 , V_90 ) ;
goto V_471;
}
if ( F_50 ( V_75 , F_16 ( V_467 ) -> V_75 ) ) {
F_237 ( V_2 , V_75 ,
F_16 ( V_467 ) -> V_90 ) ;
} else {
if ( F_262 ( & V_30 -> V_442 ,
V_467 ) )
V_467 = NULL ;
else
V_467 = F_263 (
& V_30 -> V_442 ,
V_467 ) ;
}
}
if ( ! V_467 )
F_259 ( & V_30 -> V_442 , V_4 ) ;
else
F_260 ( & V_30 -> V_442 , V_467 , V_4 ) ;
while ( ! F_264 ( & V_30 -> V_442 , V_4 ) ) {
V_467 = F_265 ( & V_30 -> V_442 , V_4 ) ;
if ( ! F_50 ( V_90 , F_16 ( V_467 ) -> V_75 ) )
break;
if ( F_43 ( V_90 , F_16 ( V_467 ) -> V_90 ) ) {
F_238 ( V_2 , F_16 ( V_467 ) -> V_75 ,
V_90 ) ;
break;
}
F_246 ( V_467 , & V_30 -> V_442 ) ;
F_238 ( V_2 , F_16 ( V_467 ) -> V_75 ,
F_16 ( V_467 ) -> V_90 ) ;
F_65 ( F_66 ( V_2 ) , V_472 ) ;
F_247 ( V_467 ) ;
}
V_471:
if ( F_136 ( V_30 ) )
F_241 ( V_2 , V_75 , V_90 ) ;
V_470:
if ( V_4 ) {
F_26 ( V_2 , V_4 ) ;
F_266 ( V_4 , V_2 ) ;
}
}
static int T_10 F_267 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_473 ,
bool * V_465 )
{
int V_474 ;
struct V_3 * V_475 = F_258 ( & V_2 -> V_460 ) ;
F_268 ( V_4 , V_473 ) ;
V_474 = ( V_475 &&
F_253 ( V_2 , V_475 , V_4 , V_465 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( ! V_474 ) {
F_248 ( & V_2 -> V_460 , V_4 ) ;
F_266 ( V_4 , V_2 ) ;
}
return V_474 ;
}
int F_269 ( struct V_1 * V_2 , struct V_476 * V_260 , T_11 V_462 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_465 ;
if ( V_462 == 0 )
return 0 ;
V_4 = F_270 ( V_462 + sizeof( * V_41 ) , V_2 -> V_477 ) ;
if ( ! V_4 )
goto V_163;
if ( F_249 ( V_2 , V_4 , V_462 + sizeof( * V_41 ) ) )
goto V_478;
V_41 = (struct V_15 * ) F_271 ( V_4 , sizeof( * V_41 ) ) ;
F_272 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_273 ( F_271 ( V_4 , V_462 ) , V_260 -> V_479 , V_462 ) )
goto V_478;
F_16 ( V_4 ) -> V_75 = F_7 ( V_2 ) -> V_88 ;
F_16 ( V_4 ) -> V_90 = F_16 ( V_4 ) -> V_75 + V_462 ;
F_16 ( V_4 ) -> V_148 = F_7 ( V_2 ) -> V_102 - 1 ;
if ( F_267 ( V_2 , V_4 , sizeof( * V_41 ) , & V_465 ) ) {
F_274 ( V_465 ) ;
F_247 ( V_4 ) ;
}
return V_462 ;
V_478:
F_275 ( V_4 ) ;
V_163:
return - V_480 ;
}
static void F_276 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_474 = - 1 ;
bool V_465 = false ;
if ( F_16 ( V_4 ) -> V_75 == F_16 ( V_4 ) -> V_90 )
goto V_481;
F_277 ( V_4 ) ;
F_268 ( V_4 , V_41 -> V_386 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_47 . V_451 = 0 ;
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 ) {
if ( F_224 ( V_30 ) == 0 )
goto V_482;
if ( V_30 -> V_483 . V_484 == V_485 &&
V_30 -> V_76 == V_30 -> V_88 && V_30 -> V_483 . V_10 &&
F_278 ( V_2 ) && ! V_30 -> V_486 ) {
int V_487 = F_40 (unsigned int, skb->len,
tp->ucopy.len) ;
F_279 ( V_488 ) ;
F_280 () ;
if ( ! F_281 ( V_4 , 0 , V_30 -> V_483 . V_489 , V_487 ) ) {
V_30 -> V_483 . V_10 -= V_487 ;
V_30 -> V_76 += V_487 ;
V_474 = ( V_487 == V_4 -> V_10 ) ;
F_45 ( V_2 ) ;
}
F_282 () ;
}
if ( V_474 <= 0 ) {
V_490:
if ( V_474 < 0 &&
F_249 ( V_2 , V_4 , V_4 -> V_57 ) )
goto V_481;
V_474 = F_267 ( V_2 , V_4 , 0 , & V_465 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( V_4 -> V_10 )
F_46 ( V_2 , V_4 ) ;
if ( V_41 -> V_461 )
F_229 ( V_2 ) ;
if ( ! F_243 ( & V_30 -> V_442 ) ) {
F_244 ( V_2 ) ;
if ( F_243 ( & V_30 -> V_442 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_47 . V_154 )
F_242 ( V_30 ) ;
F_198 ( V_2 ) ;
if ( V_474 > 0 )
F_261 ( V_4 , V_465 ) ;
if ( ! F_227 ( V_2 , V_429 ) )
V_2 -> V_491 ( V_2 , 0 ) ;
return;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_65 ( F_66 ( V_2 ) , V_453 ) ;
F_237 ( V_2 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_482:
F_10 ( V_2 ) ;
F_47 ( V_2 ) ;
V_481:
F_247 ( V_4 ) ;
return;
}
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 + F_224 ( V_30 ) ) )
goto V_482;
F_10 ( V_2 ) ;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_210 ( V_2 , L_19 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_237 ( V_2 , F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ;
if ( ! F_224 ( V_30 ) )
goto V_482;
goto V_490;
}
F_257 ( V_2 , V_4 ) ;
}
static struct V_3 * F_283 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_492 * V_493 )
{
struct V_3 * V_494 = NULL ;
if ( ! F_264 ( V_493 , V_4 ) )
V_494 = F_265 ( V_493 , V_4 ) ;
F_246 ( V_4 , V_493 ) ;
F_247 ( V_4 ) ;
F_65 ( F_66 ( V_2 ) , V_495 ) ;
return V_494 ;
}
static void
F_284 ( struct V_1 * V_2 , struct V_492 * V_493 ,
struct V_3 * V_496 , struct V_3 * V_475 ,
T_1 V_497 , T_1 V_470 )
{
struct V_3 * V_4 , * V_498 ;
bool V_499 ;
V_4 = V_496 ;
V_500:
V_499 = true ;
F_285 (list, skb, n) {
if ( V_4 == V_475 )
break;
if ( ! F_43 ( V_497 , F_16 ( V_4 ) -> V_90 ) ) {
V_4 = F_283 ( V_2 , V_4 , V_493 ) ;
if ( ! V_4 )
break;
goto V_500;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_461 &&
( F_25 ( V_4 -> V_57 ) > V_4 -> V_10 ||
F_43 ( F_16 ( V_4 ) -> V_75 , V_497 ) ) ) {
V_499 = false ;
break;
}
if ( ! F_264 ( V_493 , V_4 ) ) {
struct V_3 * V_494 = F_265 ( V_493 , V_4 ) ;
if ( V_494 != V_475 &&
F_16 ( V_4 ) -> V_90 != F_16 ( V_494 ) -> V_75 ) {
V_499 = false ;
break;
}
}
V_497 = F_16 ( V_4 ) -> V_90 ;
}
if ( V_499 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_461 )
return;
while ( F_43 ( V_497 , V_470 ) ) {
struct V_3 * V_501 ;
unsigned int V_502 = F_286 ( V_4 ) ;
int V_503 = F_287 ( V_502 , 0 ) ;
if ( V_503 < 0 )
return;
if ( V_470 - V_497 < V_503 )
V_503 = V_470 - V_497 ;
V_501 = F_270 ( V_503 + V_502 , V_504 ) ;
if ( ! V_501 )
return;
F_288 ( V_501 , F_289 ( V_4 ) - V_4 -> V_496 ) ;
F_290 ( V_501 , ( F_291 ( V_4 ) -
V_4 -> V_496 ) ) ;
F_292 ( V_501 , ( F_4 ( V_4 ) -
V_4 -> V_496 ) ) ;
F_293 ( V_501 , V_502 ) ;
memcpy ( V_501 -> V_496 , V_4 -> V_496 , V_502 ) ;
memcpy ( V_501 -> V_505 , V_4 -> V_505 , sizeof( V_4 -> V_505 ) ) ;
F_16 ( V_501 ) -> V_75 = F_16 ( V_501 ) -> V_90 = V_497 ;
F_294 ( V_493 , V_4 , V_501 ) ;
F_266 ( V_501 , V_2 ) ;
while ( V_503 > 0 ) {
int V_506 = V_497 - F_16 ( V_4 ) -> V_75 ;
int V_462 = F_16 ( V_4 ) -> V_90 - V_497 ;
F_86 ( V_506 < 0 ) ;
if ( V_462 > 0 ) {
V_462 = F_9 ( V_503 , V_462 ) ;
if ( F_295 ( V_4 , V_506 , F_271 ( V_501 , V_462 ) , V_462 ) )
F_296 () ;
F_16 ( V_501 ) -> V_90 += V_462 ;
V_503 -= V_462 ;
V_497 += V_462 ;
}
if ( ! F_43 ( V_497 , F_16 ( V_4 ) -> V_90 ) ) {
V_4 = F_283 ( V_2 , V_4 , V_493 ) ;
if ( ! V_4 ||
V_4 == V_475 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_461 )
return;
}
}
}
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_245 ( & V_30 -> V_442 ) ;
struct V_3 * V_496 ;
T_1 V_497 , V_470 ;
if ( V_4 == NULL )
return;
V_497 = F_16 ( V_4 ) -> V_75 ;
V_470 = F_16 ( V_4 ) -> V_90 ;
V_496 = V_4 ;
for (; ; ) {
struct V_3 * V_494 = NULL ;
if ( ! F_264 ( & V_30 -> V_442 , V_4 ) )
V_494 = F_265 ( & V_30 -> V_442 , V_4 ) ;
V_4 = V_494 ;
if ( ! V_4 ||
F_50 ( F_16 ( V_4 ) -> V_75 , V_470 ) ||
F_43 ( F_16 ( V_4 ) -> V_90 , V_497 ) ) {
F_284 ( V_2 , & V_30 -> V_442 ,
V_496 , V_4 , V_497 , V_470 ) ;
V_496 = V_4 ;
if ( ! V_4 )
break;
V_497 = F_16 ( V_4 ) -> V_75 ;
V_470 = F_16 ( V_4 ) -> V_90 ;
} else {
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_497 ) )
V_497 = F_16 ( V_4 ) -> V_75 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_470 ) )
V_470 = F_16 ( V_4 ) -> V_90 ;
}
}
}
static bool F_252 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_507 = false ;
if ( ! F_243 ( & V_30 -> V_442 ) ) {
F_65 ( F_66 ( V_2 ) , V_508 ) ;
F_234 ( & V_30 -> V_442 ) ;
if ( V_30 -> V_47 . V_116 )
F_214 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
V_507 = true ;
}
return V_507 ;
}
static int F_251 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_210 ( V_2 , L_20 , V_30 -> V_76 ) ;
F_65 ( F_66 ( V_2 ) , V_509 ) ;
if ( F_38 ( & V_2 -> V_79 ) >= V_2 -> V_67 )
F_35 ( V_2 ) ;
else if ( F_28 ( V_2 ) )
V_30 -> V_60 = F_9 ( V_30 -> V_60 , 4U * V_30 -> V_63 ) ;
F_297 ( V_2 ) ;
if ( ! F_243 ( & V_2 -> V_460 ) )
F_284 ( V_2 , & V_2 -> V_460 ,
F_245 ( & V_2 -> V_460 ) ,
NULL ,
V_30 -> V_76 , V_30 -> V_88 ) ;
F_48 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_252 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_65 ( F_66 ( V_2 ) , V_510 ) ;
V_30 -> V_353 = 0 ;
return - 1 ;
}
void F_298 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_128 == V_276 &&
V_2 -> V_511 && ! F_299 ( V_512 , & V_2 -> V_511 -> V_342 ) ) {
T_1 V_513 = F_58 ( V_30 , F_207 ( V_2 ) ) ;
T_1 V_514 = F_34 ( V_30 -> V_515 , V_513 ) ;
if ( V_514 < V_30 -> V_53 ) {
V_30 -> V_228 = F_122 ( V_2 ) ;
V_30 -> V_53 = ( V_30 -> V_53 + V_514 ) >> 1 ;
}
V_30 -> V_515 = 0 ;
}
V_30 -> V_78 = V_74 ;
}
static bool F_300 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_69 & V_71 )
return false ;
if ( F_28 ( V_2 ) )
return false ;
if ( F_36 ( V_2 ) >= F_37 ( V_2 , 0 ) )
return false ;
if ( V_30 -> V_107 >= V_30 -> V_53 )
return false ;
return true ;
}
static void F_301 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_300 ( V_2 ) ) {
F_20 ( V_2 ) ;
V_30 -> V_78 = V_74 ;
}
V_2 -> V_516 ( V_2 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
if ( F_227 ( V_2 , V_517 ) ) {
F_303 ( V_2 , V_517 ) ;
if ( V_2 -> V_511 &&
F_299 ( V_512 , & V_2 -> V_511 -> V_342 ) )
F_301 ( V_2 ) ;
}
}
static inline void F_304 ( struct V_1 * V_2 )
{
F_305 ( V_2 ) ;
F_302 ( V_2 ) ;
}
static void F_306 ( struct V_1 * V_2 , int V_518 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_88 - V_30 -> V_361 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_307 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_518 && F_245 ( & V_30 -> V_442 ) ) ) {
F_200 ( V_2 ) ;
} else {
F_308 ( V_2 ) ;
}
}
static inline void F_309 ( struct V_1 * V_2 )
{
if ( ! F_310 ( V_2 ) ) {
return;
}
F_306 ( V_2 , 1 ) ;
}
static void F_311 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_204 = F_144 ( V_41 -> V_519 ) ;
if ( V_204 && ! V_520 )
V_204 -- ;
V_204 += F_218 ( V_41 -> V_75 ) ;
if ( F_50 ( V_30 -> V_76 , V_204 ) )
return;
if ( F_43 ( V_204 , V_30 -> V_88 ) )
return;
if ( V_30 -> V_486 && ! F_50 ( V_204 , V_30 -> V_521 ) )
return;
F_312 ( V_2 ) ;
if ( V_30 -> V_521 == V_30 -> V_76 && V_30 -> V_486 &&
! F_227 ( V_2 , V_522 ) && V_30 -> V_76 != V_30 -> V_88 ) {
struct V_3 * V_4 = F_245 ( & V_2 -> V_460 ) ;
V_30 -> V_76 ++ ;
if ( V_4 && ! F_43 ( V_30 -> V_76 , F_16 ( V_4 ) -> V_90 ) ) {
F_246 ( V_4 , & V_2 -> V_460 ) ;
F_247 ( V_4 ) ;
}
}
V_30 -> V_486 = V_523 ;
V_30 -> V_521 = V_204 ;
V_30 -> V_353 = 0 ;
}
static void F_313 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_524 )
F_311 ( V_2 , V_41 ) ;
if ( V_30 -> V_486 == V_523 ) {
T_1 V_204 = V_30 -> V_521 - F_218 ( V_41 -> V_75 ) + ( V_41 -> V_386 * 4 ) -
V_41 -> V_43 ;
if ( V_204 < V_4 -> V_10 ) {
T_4 V_199 ;
if ( F_295 ( V_4 , V_204 , & V_199 , 1 ) )
F_296 () ;
V_30 -> V_486 = V_525 | V_199 ;
if ( ! F_227 ( V_2 , V_429 ) )
V_2 -> V_491 ( V_2 , 0 ) ;
}
}
}
static int F_314 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_526 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_487 = V_4 -> V_10 - V_526 ;
int V_163 ;
F_280 () ;
if ( F_315 ( V_4 ) )
V_163 = F_281 ( V_4 , V_526 , V_30 -> V_483 . V_489 , V_487 ) ;
else
V_163 = F_316 ( V_4 , V_526 ,
V_30 -> V_483 . V_489 ) ;
if ( ! V_163 ) {
V_30 -> V_483 . V_10 -= V_487 ;
V_30 -> V_76 += V_487 ;
F_45 ( V_2 ) ;
}
F_282 () ;
return V_163 ;
}
static T_12 F_317 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_12 V_527 ;
if ( F_278 ( V_2 ) ) {
F_280 () ;
V_527 = F_318 ( V_4 ) ;
F_282 () ;
} else {
V_527 = F_318 ( V_4 ) ;
}
return V_527 ;
}
static inline bool F_319 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_315 ( V_4 ) &&
F_317 ( V_2 , V_4 ) ;
}
static bool F_320 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_526 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_487 = V_4 -> V_10 - V_526 ;
int V_528 ;
bool V_529 = false ;
if ( V_30 -> V_483 . V_530 )
return false ;
if ( ! V_30 -> V_483 . V_531 && V_30 -> V_483 . V_532 )
V_30 -> V_483 . V_531 = F_321 () ;
if ( V_30 -> V_483 . V_531 && F_315 ( V_4 ) ) {
V_528 = F_322 ( V_30 -> V_483 . V_531 ,
V_4 , V_526 ,
V_30 -> V_483 . V_489 , V_487 ,
V_30 -> V_483 . V_532 ) ;
if ( V_528 < 0 )
goto V_194;
V_30 -> V_483 . V_528 = V_528 ;
V_529 = true ;
V_30 -> V_483 . V_10 -= V_487 ;
V_30 -> V_76 += V_487 ;
F_45 ( V_2 ) ;
if ( ( V_30 -> V_483 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_533 ) ||
( F_38 ( & V_2 -> V_79 ) > ( V_2 -> V_67 >> 1 ) ) ) {
V_30 -> V_483 . V_530 = 1 ;
V_2 -> V_491 ( V_2 , 0 ) ;
}
} else if ( V_487 > 0 ) {
V_30 -> V_483 . V_530 = 1 ;
V_2 -> V_491 ( V_2 , 0 ) ;
}
V_194:
return V_529 ;
}
static bool F_323 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_534 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_219 ( V_4 , V_41 , V_30 ) && V_30 -> V_47 . V_259 &&
F_222 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_535 ) {
F_65 ( F_66 ( V_2 ) , V_536 ) ;
F_239 ( V_2 , V_4 ) ;
goto V_537;
}
}
if ( ! F_223 ( V_30 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ) {
if ( ! V_41 -> V_535 ) {
if ( V_41 -> V_43 )
goto V_538;
F_239 ( V_2 , V_4 ) ;
}
goto V_537;
}
if ( V_41 -> V_535 ) {
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 )
F_225 ( V_2 ) ;
else
F_199 ( V_2 ) ;
goto V_537;
}
if ( V_41 -> V_43 ) {
V_538:
if ( V_534 )
F_324 ( F_66 ( V_2 ) , V_539 ) ;
F_65 ( F_66 ( V_2 ) , V_540 ) ;
F_199 ( V_2 ) ;
goto V_537;
}
return true ;
V_537:
F_247 ( V_4 ) ;
return false ;
}
void F_325 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_97 ( V_2 -> V_541 == NULL ) )
F_2 ( V_2 ) -> V_542 -> V_543 ( V_2 , V_4 ) ;
V_30 -> V_47 . V_259 = 0 ;
if ( ( F_5 ( V_41 ) & V_544 ) == V_30 -> V_353 &&
F_16 ( V_4 ) -> V_75 == V_30 -> V_88 &&
! F_50 ( F_16 ( V_4 ) -> V_148 , V_30 -> V_104 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_418 ) {
if ( ! F_216 ( V_30 , V_41 ) )
goto V_545;
if ( ( T_5 ) ( V_30 -> V_47 . V_359 - V_30 -> V_47 . V_358 ) < 0 )
goto V_545;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_418 ) &&
V_30 -> V_88 == V_30 -> V_361 )
F_201 ( V_30 ) ;
F_206 ( V_2 , V_4 , 0 ) ;
F_247 ( V_4 ) ;
F_304 ( V_2 ) ;
return;
} else {
F_324 ( F_66 ( V_2 ) , V_539 ) ;
goto V_537;
}
} else {
int V_474 = 0 ;
int V_529 = 0 ;
bool V_465 = false ;
if ( V_30 -> V_76 == V_30 -> V_88 &&
V_10 - V_18 <= V_30 -> V_483 . V_10 ) {
#ifdef F_326
if ( V_30 -> V_483 . V_484 == V_485 &&
F_278 ( V_2 ) &&
F_320 ( V_2 , V_4 , V_18 ) ) {
V_529 = 1 ;
V_474 = 1 ;
}
#endif
if ( V_30 -> V_483 . V_484 == V_485 &&
F_278 ( V_2 ) && ! V_529 ) {
F_279 ( V_488 ) ;
if ( ! F_314 ( V_2 , V_4 , V_18 ) )
V_474 = 1 ;
}
if ( V_474 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_418 ) &&
V_30 -> V_88 == V_30 -> V_361 )
F_201 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_268 ( V_4 , V_18 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
F_65 ( F_66 ( V_2 ) , V_546 ) ;
}
if ( V_529 )
F_327 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_474 ) {
if ( F_319 ( V_2 , V_4 ) )
goto V_547;
if ( ( int ) V_4 -> V_57 > V_2 -> V_548 )
goto V_549;
if ( V_18 ==
( sizeof( struct V_15 ) + V_418 ) &&
V_30 -> V_88 == V_30 -> V_361 )
F_201 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_65 ( F_66 ( V_2 ) , V_550 ) ;
V_474 = F_267 ( V_2 , V_4 , V_18 ,
& V_465 ) ;
}
F_46 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_148 != V_30 -> V_102 ) {
F_206 ( V_2 , V_4 , V_373 ) ;
F_304 ( V_2 ) ;
if ( ! F_310 ( V_2 ) )
goto V_551;
}
if ( ! V_529 || V_30 -> V_88 != V_30 -> V_361 )
F_306 ( V_2 , 0 ) ;
V_551:
#ifdef F_326
if ( V_529 )
F_248 ( & V_2 -> V_552 , V_4 ) ;
else
#endif
if ( V_474 )
F_261 ( V_4 , V_465 ) ;
V_2 -> V_491 ( V_2 , 0 ) ;
return;
}
}
V_545:
if ( V_10 < ( V_41 -> V_386 << 2 ) || F_319 ( V_2 , V_4 ) )
goto V_547;
if ( ! V_41 -> V_316 && ! V_41 -> V_535 )
goto V_537;
if ( ! F_323 ( V_2 , V_4 , V_41 , 1 ) )
return;
V_549:
if ( F_206 ( V_2 , V_4 , V_370 | V_369 ) < 0 )
goto V_537;
F_44 ( V_2 , V_4 ) ;
F_313 ( V_2 , V_4 , V_41 ) ;
F_276 ( V_2 , V_4 ) ;
F_304 ( V_2 ) ;
F_309 ( V_2 ) ;
return;
V_547:
F_324 ( F_66 ( V_2 ) , V_553 ) ;
F_324 ( F_66 ( V_2 ) , V_539 ) ;
V_537:
F_247 ( V_4 ) ;
}
void F_328 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_231 ( V_2 , V_435 ) ;
if ( V_4 != NULL ) {
V_6 -> V_542 -> V_543 ( V_2 , V_4 ) ;
F_329 ( V_2 , V_4 ) ;
}
V_6 -> V_542 -> V_554 ( V_2 ) ;
F_330 ( V_2 ) ;
F_331 ( V_2 ) ;
V_30 -> V_555 = V_74 ;
F_32 ( V_2 ) ;
if ( F_227 ( V_2 , V_556 ) )
F_332 ( V_2 , F_333 ( V_30 ) ) ;
if ( ! V_30 -> V_47 . V_351 )
F_334 ( V_30 , V_30 -> V_350 ) ;
else
V_30 -> V_353 = 0 ;
if ( ! F_227 ( V_2 , V_429 ) ) {
V_2 -> V_443 ( V_2 ) ;
F_235 ( V_2 , V_557 , V_558 ) ;
}
}
static bool F_335 ( struct V_1 * V_2 , struct V_3 * V_559 ,
struct V_383 * V_560 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_561 ? F_98 ( V_2 ) : NULL ;
T_7 V_64 = V_30 -> V_47 . V_48 ;
bool V_562 ;
if ( V_64 == V_30 -> V_47 . V_394 ) {
struct V_380 V_563 ;
F_336 ( & V_563 ) ;
V_563 . V_394 = V_563 . V_48 = 0 ;
F_211 ( V_559 , & V_563 , 0 , NULL ) ;
V_64 = V_563 . V_48 ;
}
if ( ! V_30 -> V_564 )
V_560 -> V_10 = - 1 ;
V_562 = ( V_560 -> V_10 <= 0 && V_13 && V_30 -> V_314 ) ;
F_337 ( V_2 , V_64 , V_560 , V_562 ) ;
if ( V_13 ) {
F_103 (data, sk) {
if ( V_13 == F_77 ( V_2 ) ||
F_338 ( V_2 , V_13 ) )
break;
}
F_177 ( V_2 ) ;
return true ;
}
V_30 -> V_565 = V_30 -> V_561 ;
return false ;
}
static int F_339 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_383 V_384 = { . V_10 = - 1 } ;
int V_566 = V_30 -> V_47 . V_48 ;
F_211 ( V_4 , & V_30 -> V_47 , 0 , & V_384 ) ;
if ( V_30 -> V_47 . V_259 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_417 ;
if ( V_41 -> V_316 ) {
if ( ! F_50 ( F_16 ( V_4 ) -> V_148 , V_30 -> V_102 ) ||
F_50 ( F_16 ( V_4 ) -> V_148 , V_30 -> V_104 ) )
goto V_567;
if ( V_30 -> V_47 . V_259 && V_30 -> V_47 . V_89 &&
! F_185 ( V_30 -> V_47 . V_89 , V_30 -> V_258 ,
V_74 ) ) {
F_65 ( F_66 ( V_2 ) , V_568 ) ;
goto V_567;
}
if ( V_41 -> V_535 ) {
F_225 ( V_2 ) ;
goto V_537;
}
if ( ! V_41 -> V_43 )
goto V_569;
F_17 ( V_30 , V_41 ) ;
F_340 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_206 ( V_2 , V_4 , V_370 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_361 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_350 = F_144 ( V_41 -> V_58 ) ;
if ( ! V_30 -> V_47 . V_398 ) {
V_30 -> V_47 . V_351 = V_30 -> V_47 . V_570 = 0 ;
V_30 -> V_61 = F_9 ( V_30 -> V_61 , 65535U ) ;
}
if ( V_30 -> V_47 . V_259 ) {
V_30 -> V_47 . V_402 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_418 ;
V_30 -> V_63 -= V_418 ;
F_201 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_136 ( V_30 ) && V_571 )
F_341 ( V_30 ) ;
F_342 ( V_2 ) ;
F_164 ( V_2 , V_6 -> V_295 ) ;
F_39 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_343 () ;
F_328 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_564 || V_30 -> V_561 ) &&
F_335 ( V_2 , V_4 , & V_384 ) )
return - 1 ;
if ( V_2 -> V_572 ||
V_6 -> V_573 . V_574 ||
V_6 -> V_8 . V_26 ) {
F_47 ( V_2 ) ;
V_6 -> V_8 . V_95 = V_74 ;
F_10 ( V_2 ) ;
F_128 ( V_2 , V_575 ,
V_576 , V_241 ) ;
V_537:
F_247 ( V_4 ) ;
return 0 ;
} else {
F_200 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_535 ) {
goto V_569;
}
if ( V_30 -> V_47 . V_360 && V_30 -> V_47 . V_259 &&
F_344 ( & V_30 -> V_47 , 0 ) )
goto V_569;
if ( V_41 -> V_43 ) {
F_231 ( V_2 , V_434 ) ;
if ( V_30 -> V_47 . V_259 ) {
V_30 -> V_47 . V_402 = 1 ;
F_201 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_418 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_361 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_350 = F_144 ( V_41 -> V_58 ) ;
V_30 -> V_349 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_141 = V_30 -> V_350 ;
F_18 ( V_30 , V_41 ) ;
F_342 ( V_2 ) ;
F_164 ( V_2 , V_6 -> V_295 ) ;
F_39 ( V_2 ) ;
F_345 ( V_2 ) ;
#if 0
return -1;
#else
goto V_537;
#endif
}
V_569:
F_336 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_566 ;
goto V_537;
V_567:
F_336 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_566 ;
return 1 ;
}
int F_346 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_577 * V_578 ;
int V_579 = 0 ;
bool V_580 ;
T_1 V_313 ;
V_30 -> V_47 . V_259 = 0 ;
switch ( V_2 -> V_421 ) {
case V_427 :
goto V_537;
case V_581 :
if ( V_41 -> V_316 )
return 1 ;
if ( V_41 -> V_535 )
goto V_537;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_461 )
goto V_537;
if ( V_6 -> V_542 -> V_582 ( V_2 , V_4 ) < 0 )
return 1 ;
F_275 ( V_4 ) ;
return 0 ;
}
goto V_537;
case V_422 :
V_579 = F_339 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_579 >= 0 )
return V_579 ;
F_313 ( V_2 , V_4 , V_41 ) ;
F_247 ( V_4 ) ;
F_304 ( V_2 ) ;
return 0 ;
}
V_578 = V_30 -> V_319 ;
if ( V_578 != NULL ) {
F_274 ( V_2 -> V_421 != V_434 &&
V_2 -> V_421 != V_439 ) ;
if ( F_347 ( V_2 , V_4 , V_578 , NULL , true ) == NULL )
goto V_537;
}
if ( ! V_41 -> V_316 && ! V_41 -> V_535 )
goto V_537;
if ( ! F_323 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
V_580 = F_206 ( V_2 , V_4 , V_370 |
V_369 ) > 0 ;
switch ( V_2 -> V_421 ) {
case V_434 :
if ( ! V_580 )
return 1 ;
if ( V_578 ) {
V_313 = F_348 ( V_578 ) -> V_583 ;
V_30 -> V_314 = V_578 -> V_584 ;
F_349 ( V_2 , V_578 , false ) ;
} else {
V_313 = V_30 -> V_555 ;
V_6 -> V_542 -> V_554 ( V_2 ) ;
F_331 ( V_2 ) ;
F_342 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_32 ( V_2 ) ;
}
F_343 () ;
F_231 ( V_2 , V_435 ) ;
V_2 -> V_443 ( V_2 ) ;
if ( V_2 -> V_511 )
F_235 ( V_2 , V_557 , V_558 ) ;
V_30 -> V_102 = F_16 ( V_4 ) -> V_148 ;
V_30 -> V_350 = F_144 ( V_41 -> V_58 ) << V_30 -> V_47 . V_351 ;
F_340 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_175 ( V_2 , V_313 ) ;
if ( V_30 -> V_47 . V_402 )
V_30 -> V_63 -= V_418 ;
if ( V_578 ) {
F_177 ( V_2 ) ;
} else
F_330 ( V_2 ) ;
F_52 ( V_2 ) ;
V_30 -> V_555 = V_74 ;
F_39 ( V_2 ) ;
F_350 ( V_30 ) ;
break;
case V_439 : {
struct V_110 * V_111 ;
int V_585 ;
if ( V_578 != NULL ) {
if ( ! V_580 )
return 1 ;
F_349 ( V_2 , V_578 , false ) ;
F_177 ( V_2 ) ;
}
if ( V_30 -> V_102 != V_30 -> V_586 )
break;
F_231 ( V_2 , V_440 ) ;
V_2 -> V_431 |= V_587 ;
V_111 = F_207 ( V_2 ) ;
if ( V_111 )
F_208 ( V_111 ) ;
if ( ! F_227 ( V_2 , V_429 ) ) {
V_2 -> V_443 ( V_2 ) ;
break;
}
if ( V_30 -> V_588 < 0 ||
( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_50 ( F_16 ( V_4 ) -> V_90 - V_41 -> V_461 , V_30 -> V_88 ) ) ) {
F_228 ( V_2 ) ;
F_65 ( F_66 ( V_2 ) , V_589 ) ;
return 1 ;
}
V_585 = F_351 ( V_2 ) ;
if ( V_585 > V_590 ) {
F_332 ( V_2 , V_585 - V_590 ) ;
} else if ( V_41 -> V_461 || F_278 ( V_2 ) ) {
F_332 ( V_2 , V_585 ) ;
} else {
F_232 ( V_2 , V_440 , V_585 ) ;
goto V_537;
}
break;
}
case V_437 :
if ( V_30 -> V_102 == V_30 -> V_586 ) {
F_232 ( V_2 , V_441 , 0 ) ;
goto V_537;
}
break;
case V_438 :
if ( V_30 -> V_102 == V_30 -> V_586 ) {
F_352 ( V_2 ) ;
F_228 ( V_2 ) ;
goto V_537;
}
break;
}
F_313 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_421 ) {
case V_425 :
case V_437 :
case V_438 :
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) )
break;
case V_439 :
case V_440 :
if ( V_2 -> V_431 & V_432 ) {
if ( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_50 ( F_16 ( V_4 ) -> V_90 - V_41 -> V_461 , V_30 -> V_88 ) ) {
F_65 ( F_66 ( V_2 ) , V_589 ) ;
F_225 ( V_2 ) ;
return 1 ;
}
}
case V_435 :
F_276 ( V_2 , V_4 ) ;
V_579 = 1 ;
break;
}
if ( V_2 -> V_421 != V_427 ) {
F_304 ( V_2 ) ;
F_309 ( V_2 ) ;
}
if ( ! V_579 ) {
V_537:
F_247 ( V_4 ) ;
}
return 0 ;
}
