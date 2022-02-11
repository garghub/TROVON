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
static void F_49 ( struct V_1 * V_2 , long V_97 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_86 = V_97 ;
T_1 V_98 = V_30 -> V_99 ;
if ( V_98 != 0 ) {
V_86 -= ( V_98 >> 3 ) ;
V_98 += V_86 ;
if ( V_86 < 0 ) {
V_86 = - V_86 ;
V_86 -= ( V_30 -> V_100 >> 2 ) ;
if ( V_86 > 0 )
V_86 >>= 3 ;
} else {
V_86 -= ( V_30 -> V_100 >> 2 ) ;
}
V_30 -> V_100 += V_86 ;
if ( V_30 -> V_100 > V_30 -> V_101 ) {
V_30 -> V_101 = V_30 -> V_100 ;
if ( V_30 -> V_101 > V_30 -> V_102 )
V_30 -> V_102 = V_30 -> V_101 ;
}
if ( F_50 ( V_30 -> V_103 , V_30 -> V_104 ) ) {
if ( V_30 -> V_101 < V_30 -> V_102 )
V_30 -> V_102 -= ( V_30 -> V_102 - V_30 -> V_101 ) >> 2 ;
V_30 -> V_104 = V_30 -> V_105 ;
V_30 -> V_101 = F_51 ( V_2 ) ;
}
} else {
V_98 = V_86 << 3 ;
V_30 -> V_100 = V_86 << 1 ;
V_30 -> V_102 = F_34 ( V_30 -> V_100 , F_51 ( V_2 ) ) ;
V_30 -> V_101 = V_30 -> V_102 ;
V_30 -> V_104 = V_30 -> V_105 ;
}
V_30 -> V_99 = F_34 ( 1U , V_98 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_106 ;
V_106 = ( T_2 ) V_30 -> V_49 * 2 * ( V_107 << 3 ) ;
V_106 *= F_34 ( V_30 -> V_53 , V_30 -> V_108 ) ;
if ( F_53 ( V_30 -> V_99 ) )
F_54 ( V_106 , V_30 -> V_99 ) ;
F_55 ( V_2 -> V_109 ) = F_40 ( T_2 , V_106 ,
V_2 -> V_110 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_96 = F_57 ( V_30 ) ;
F_58 ( V_2 ) ;
}
T_3 F_59 ( const struct V_29 * V_30 , const struct V_111 * V_112 )
{
T_3 V_113 = ( V_112 ? F_60 ( V_112 , V_114 ) : 0 ) ;
if ( ! V_113 )
V_113 = V_52 ;
return F_40 ( T_3 , V_113 , V_30 -> V_115 ) ;
}
void F_61 ( struct V_29 * V_30 )
{
if ( F_62 ( V_30 ) )
V_30 -> V_116 = NULL ;
V_30 -> V_47 . V_117 &= ~ V_118 ;
}
static void F_63 ( struct V_29 * V_30 )
{
V_30 -> V_47 . V_117 |= V_119 ;
}
static void F_64 ( struct V_1 * V_2 , const int V_120 ,
const int V_121 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_120 > V_30 -> V_54 ) {
int V_122 ;
V_30 -> V_54 = F_9 ( V_123 , V_120 ) ;
if ( V_121 )
V_122 = V_124 ;
else if ( F_65 ( V_30 ) )
V_122 = V_125 ;
else if ( F_62 ( V_30 ) )
V_122 = V_126 ;
else
V_122 = V_127 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
#if V_128 > 1
F_68 ( L_1 ,
V_30 -> V_47 . V_117 , F_2 ( V_2 ) -> V_129 ,
V_30 -> V_54 ,
V_30 -> V_130 ,
V_30 -> V_131 ,
V_30 -> V_132 ? V_30 -> V_133 : 0 ) ;
#endif
F_61 ( V_30 ) ;
}
if ( V_120 > 0 )
F_69 ( V_30 ) ;
}
static void F_70 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_134 == NULL ) ||
F_43 ( F_16 ( V_4 ) -> V_75 ,
F_16 ( V_30 -> V_134 ) -> V_75 ) )
V_30 -> V_134 = V_4 ;
if ( ! V_30 -> V_135 ||
F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_136 ) )
V_30 -> V_136 = F_16 ( V_4 ) -> V_90 ;
}
static void F_71 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_137 & ( V_138 | V_139 ) ) ) {
F_70 ( V_30 , V_4 ) ;
V_30 -> V_135 += F_72 ( V_4 ) ;
F_16 ( V_4 ) -> V_137 |= V_138 ;
}
}
static void F_73 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_70 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_137 & ( V_138 | V_139 ) ) ) {
V_30 -> V_135 += F_72 ( V_4 ) ;
F_16 ( V_4 ) -> V_137 |= V_138 ;
}
}
static bool F_74 ( struct V_29 * V_30 , bool V_140 ,
T_1 V_141 , T_1 V_90 )
{
if ( F_50 ( V_90 , V_30 -> V_105 ) || ! F_43 ( V_141 , V_90 ) )
return false ;
if ( ! F_43 ( V_141 , V_30 -> V_105 ) )
return false ;
if ( F_50 ( V_141 , V_30 -> V_103 ) )
return true ;
if ( ! V_140 || ! V_30 -> V_132 )
return false ;
if ( F_50 ( V_90 , V_30 -> V_103 ) )
return false ;
if ( ! F_43 ( V_141 , V_30 -> V_132 ) )
return true ;
if ( ! F_50 ( V_90 , V_30 -> V_132 ) )
return false ;
return ! F_43 ( V_141 , V_90 - V_30 -> V_142 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_143 = 0 ;
T_1 V_144 = V_30 -> V_105 ;
T_1 V_145 = F_76 ( V_30 ) ;
if ( ! F_62 ( V_30 ) || ! V_30 -> V_146 ||
! F_50 ( V_145 , V_30 -> V_147 ) ||
V_6 -> V_129 != V_148 )
return;
F_77 (skb, sk) {
T_1 V_149 = F_16 ( V_4 ) -> V_149 ;
if ( V_4 == F_78 ( V_2 ) )
break;
if ( V_143 == V_30 -> V_146 )
break;
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_103 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_137 & V_150 ) )
continue;
if ( F_50 ( V_145 , V_149 ) ) {
F_16 ( V_4 ) -> V_137 &= ~ V_150 ;
V_30 -> V_146 -= F_72 ( V_4 ) ;
F_73 ( V_30 , V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_151 ) ;
} else {
if ( F_43 ( V_149 , V_144 ) )
V_144 = V_149 ;
V_143 += F_72 ( V_4 ) ;
}
}
if ( V_30 -> V_146 )
V_30 -> V_147 = V_144 ;
}
static bool F_79 ( struct V_1 * V_2 , const struct V_3 * V_152 ,
struct V_153 * V_154 , int V_155 ,
T_1 V_156 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_157 = F_80 ( & V_154 [ 0 ] . V_141 ) ;
T_1 V_158 = F_80 ( & V_154 [ 0 ] . V_90 ) ;
bool V_159 = false ;
if ( F_43 ( V_157 , F_16 ( V_152 ) -> V_149 ) ) {
V_159 = true ;
F_63 ( V_30 ) ;
F_66 ( F_67 ( V_2 ) , V_160 ) ;
} else if ( V_155 > 1 ) {
T_1 V_161 = F_80 ( & V_154 [ 1 ] . V_90 ) ;
T_1 V_162 = F_80 ( & V_154 [ 1 ] . V_141 ) ;
if ( ! F_50 ( V_158 , V_161 ) &&
! F_43 ( V_157 , V_162 ) ) {
V_159 = true ;
F_63 ( V_30 ) ;
F_66 ( F_67 ( V_2 ) ,
V_163 ) ;
}
}
if ( V_159 && V_30 -> V_132 && V_30 -> V_133 &&
! F_50 ( V_158 , V_156 ) &&
F_50 ( V_158 , V_30 -> V_132 ) )
V_30 -> V_133 -- ;
return V_159 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_141 , T_1 V_90 )
{
int V_164 ;
bool V_165 ;
unsigned int V_166 ;
unsigned int V_64 ;
V_165 = ! F_50 ( V_141 , F_16 ( V_4 ) -> V_75 ) &&
! F_43 ( V_90 , F_16 ( V_4 ) -> V_90 ) ;
if ( F_72 ( V_4 ) > 1 && ! V_165 &&
F_50 ( F_16 ( V_4 ) -> V_90 , V_141 ) ) {
V_64 = F_82 ( V_4 ) ;
V_165 = ! F_50 ( V_141 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! V_165 ) {
V_166 = V_141 - F_16 ( V_4 ) -> V_75 ;
if ( V_166 < V_64 )
V_166 = V_64 ;
} else {
V_166 = V_90 - F_16 ( V_4 ) -> V_75 ;
if ( V_166 < V_64 )
return - V_167 ;
}
if ( V_166 > V_64 ) {
unsigned int V_168 = ( V_166 / V_64 ) * V_64 ;
if ( ! V_165 && V_168 < V_166 ) {
V_168 += V_64 ;
if ( V_168 > V_4 -> V_10 )
return 0 ;
}
V_166 = V_168 ;
}
V_164 = F_83 ( V_2 , V_4 , V_166 , V_64 ) ;
if ( V_164 < 0 )
return V_164 ;
}
return V_165 ;
}
static T_4 F_84 ( struct V_1 * V_2 ,
struct V_169 * V_170 , T_4 V_137 ,
T_1 V_141 , T_1 V_90 ,
int V_159 , int V_171 ,
const struct V_172 * V_173 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_174 = V_170 -> V_174 ;
if ( V_159 && ( V_137 & V_175 ) ) {
if ( V_30 -> V_132 && V_30 -> V_133 &&
F_50 ( V_90 , V_30 -> V_132 ) )
V_30 -> V_133 -- ;
if ( V_137 & V_139 )
V_170 -> V_176 = F_9 ( V_174 , V_170 -> V_176 ) ;
}
if ( ! F_50 ( V_90 , V_30 -> V_103 ) )
return V_137 ;
if ( ! ( V_137 & V_139 ) ) {
if ( V_137 & V_150 ) {
if ( V_137 & V_138 ) {
V_137 &= ~ ( V_138 | V_150 ) ;
V_30 -> V_135 -= V_171 ;
V_30 -> V_146 -= V_171 ;
}
} else {
if ( ! ( V_137 & V_175 ) ) {
if ( F_43 ( V_141 ,
F_76 ( V_30 ) ) )
V_170 -> V_176 = F_9 ( V_174 ,
V_170 -> V_176 ) ;
if ( ! F_50 ( V_90 , V_30 -> V_177 ) )
V_170 -> V_178 |= V_179 ;
if ( V_170 -> V_180 < 0 ) {
struct V_172 V_94 ;
F_85 ( & V_94 ) ;
V_170 -> V_180 = F_86 ( & V_94 ,
V_173 ) ;
}
}
if ( V_137 & V_138 ) {
V_137 &= ~ V_138 ;
V_30 -> V_135 -= V_171 ;
}
}
V_137 |= V_139 ;
V_170 -> V_178 |= V_181 ;
V_30 -> V_131 += V_171 ;
V_174 += V_171 ;
if ( ! F_62 ( V_30 ) && ( V_30 -> V_116 != NULL ) &&
F_43 ( V_141 , F_16 ( V_30 -> V_116 ) -> V_75 ) )
V_30 -> V_182 += V_171 ;
if ( V_174 > V_30 -> V_130 )
V_30 -> V_130 = V_174 ;
}
if ( V_159 && ( V_137 & V_150 ) ) {
V_137 &= ~ V_150 ;
V_30 -> V_146 -= V_171 ;
}
return V_137 ;
}
static bool F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_169 * V_170 ,
unsigned int V_171 , int V_183 , int V_64 ,
bool V_159 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_184 = F_88 ( V_2 , V_4 ) ;
T_1 V_141 = F_16 ( V_4 ) -> V_75 ;
T_1 V_90 = V_141 + V_183 ;
F_89 ( ! V_171 ) ;
F_84 ( V_2 , V_170 , F_16 ( V_4 ) -> V_137 ,
V_141 , V_90 , V_159 , V_171 ,
& V_4 -> V_172 ) ;
if ( V_4 == V_30 -> V_116 )
V_30 -> V_182 += V_171 ;
F_16 ( V_184 ) -> V_90 += V_183 ;
F_16 ( V_4 ) -> V_75 += V_183 ;
F_3 ( V_184 ) -> V_185 += V_171 ;
F_89 ( F_3 ( V_4 ) -> V_185 < V_171 ) ;
F_3 ( V_4 ) -> V_185 -= V_171 ;
if ( ! F_3 ( V_184 ) -> V_11 ) {
F_3 ( V_184 ) -> V_11 = V_64 ;
F_3 ( V_184 ) -> V_186 = V_2 -> V_187 ;
}
if ( F_3 ( V_4 ) -> V_185 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_186 = 0 ;
}
F_16 ( V_184 ) -> V_137 |= ( F_16 ( V_4 ) -> V_137 & V_188 ) ;
if ( V_4 -> V_10 > 0 ) {
F_89 ( ! F_72 ( V_4 ) ) ;
F_66 ( F_67 ( V_2 ) , V_189 ) ;
return false ;
}
if ( V_4 == V_30 -> V_134 )
V_30 -> V_134 = V_184 ;
if ( V_4 == V_30 -> V_116 ) {
V_30 -> V_116 = V_184 ;
V_30 -> V_182 -= F_72 ( V_184 ) ;
}
F_16 ( V_184 ) -> V_190 |= F_16 ( V_4 ) -> V_190 ;
if ( F_16 ( V_4 ) -> V_190 & V_191 )
F_16 ( V_184 ) -> V_90 ++ ;
if ( V_4 == F_90 ( V_2 ) )
F_91 ( V_2 , V_4 ) ;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_192 ) ;
return true ;
}
static int F_94 ( const struct V_3 * V_4 )
{
return F_72 ( V_4 ) == 1 ? V_4 -> V_10 : F_82 ( V_4 ) ;
}
static int F_95 ( const struct V_3 * V_4 )
{
return ! F_96 ( V_4 ) && F_97 ( V_4 ) ;
}
static struct V_3 * F_98 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_169 * V_170 ,
T_1 V_141 , T_1 V_90 ,
bool V_159 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_184 ;
int V_64 ;
int V_171 = 0 ;
int V_10 ;
int V_165 ;
if ( ! F_99 ( V_2 ) )
goto V_193;
if ( ! V_159 &&
( F_16 ( V_4 ) -> V_137 & ( V_138 | V_150 ) ) == V_150 )
goto V_193;
if ( ! F_95 ( V_4 ) )
goto V_193;
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_103 ) )
goto V_193;
if ( F_100 ( V_4 == F_101 ( V_2 ) ) )
goto V_193;
V_184 = F_88 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_184 ) -> V_137 & V_194 ) != V_139 )
goto V_193;
V_165 = ! F_50 ( V_141 , F_16 ( V_4 ) -> V_75 ) &&
! F_43 ( V_90 , F_16 ( V_4 ) -> V_90 ) ;
if ( V_165 ) {
V_10 = V_4 -> V_10 ;
V_171 = F_72 ( V_4 ) ;
V_64 = F_94 ( V_4 ) ;
if ( V_64 != F_94 ( V_184 ) )
goto V_193;
} else {
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_141 ) )
goto V_195;
if ( F_72 ( V_4 ) <= 1 )
goto V_195;
V_165 = ! F_50 ( V_141 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! V_165 ) {
goto V_193;
}
V_10 = V_90 - F_16 ( V_4 ) -> V_75 ;
F_89 ( V_10 < 0 ) ;
F_89 ( V_10 > V_4 -> V_10 ) ;
V_64 = F_82 ( V_4 ) ;
if ( V_64 != F_94 ( V_184 ) )
goto V_193;
if ( V_10 == V_64 ) {
V_171 = 1 ;
} else if ( V_10 < V_64 ) {
goto V_195;
} else {
V_171 = V_10 / V_64 ;
V_10 = V_171 * V_64 ;
}
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_75 + V_10 , V_30 -> V_103 ) )
goto V_193;
if ( ! F_102 ( V_184 , V_4 , V_10 ) )
goto V_193;
if ( ! F_87 ( V_2 , V_4 , V_170 , V_171 , V_10 , V_64 , V_159 ) )
goto V_196;
if ( V_184 == F_103 ( V_2 ) )
goto V_196;
V_4 = F_104 ( V_2 , V_184 ) ;
if ( ! F_95 ( V_4 ) ||
( V_4 == F_78 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_137 & V_194 ) != V_139 ) ||
( V_64 != F_94 ( V_4 ) ) )
goto V_196;
V_10 = V_4 -> V_10 ;
if ( F_102 ( V_184 , V_4 , V_10 ) ) {
V_171 += F_72 ( V_4 ) ;
F_87 ( V_2 , V_4 , V_170 , F_72 ( V_4 ) , V_10 , V_64 , 0 ) ;
}
V_196:
V_170 -> V_174 += V_171 ;
return V_184 ;
V_195:
return V_4 ;
V_193:
F_66 ( F_67 ( V_2 ) , V_197 ) ;
return NULL ;
}
static struct V_3 * F_105 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_198 * V_199 ,
struct V_169 * V_170 ,
T_1 V_141 , T_1 V_90 ,
bool V_200 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_201 ;
F_106 (skb, sk) {
int V_165 = 0 ;
bool V_159 = V_200 ;
if ( V_4 == F_78 ( V_2 ) )
break;
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_90 ) )
break;
if ( ( V_199 != NULL ) &&
F_43 ( F_16 ( V_4 ) -> V_75 , V_199 -> V_90 ) ) {
V_165 = F_81 ( V_2 , V_4 ,
V_199 -> V_141 ,
V_199 -> V_90 ) ;
if ( V_165 > 0 )
V_159 = true ;
}
if ( V_165 <= 0 ) {
V_201 = F_98 ( V_2 , V_4 , V_170 ,
V_141 , V_90 , V_159 ) ;
if ( V_201 != NULL ) {
if ( V_201 != V_4 ) {
V_4 = V_201 ;
continue;
}
V_165 = 0 ;
} else {
V_165 = F_81 ( V_2 , V_4 ,
V_141 ,
V_90 ) ;
}
}
if ( F_100 ( V_165 < 0 ) )
break;
if ( V_165 ) {
F_16 ( V_4 ) -> V_137 =
F_84 ( V_2 ,
V_170 ,
F_16 ( V_4 ) -> V_137 ,
F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ,
V_159 ,
F_72 ( V_4 ) ,
& V_4 -> V_172 ) ;
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 ,
F_76 ( V_30 ) ) )
F_91 ( V_2 , V_4 ) ;
}
V_170 -> V_174 += F_72 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_169 * V_170 ,
T_1 V_202 )
{
F_106 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_202 ) )
break;
V_170 -> V_174 += F_72 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_108 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_198 * V_199 ,
struct V_169 * V_170 ,
T_1 V_202 )
{
if ( V_199 == NULL )
return V_4 ;
if ( F_43 ( V_199 -> V_141 , V_202 ) ) {
V_4 = F_107 ( V_4 , V_2 , V_170 , V_199 -> V_141 ) ;
V_4 = F_105 ( V_4 , V_2 , NULL , V_170 ,
V_199 -> V_141 , V_199 -> V_90 ,
1 ) ;
}
return V_4 ;
}
static int F_109 ( const struct V_29 * V_30 , const struct V_198 * V_203 )
{
return V_203 < V_30 -> V_204 + F_110 ( V_30 -> V_204 ) ;
}
static int
F_111 ( struct V_1 * V_2 , const struct V_3 * V_152 ,
T_1 V_156 , long * V_205 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_206 = ( F_4 ( V_152 ) +
F_16 ( V_152 ) -> V_137 ) ;
struct V_153 * V_207 = (struct V_153 * ) ( V_206 + 2 ) ;
struct V_198 V_154 [ V_208 ] ;
struct V_198 * V_203 ;
struct V_169 V_170 ;
struct V_3 * V_4 ;
int V_155 = F_9 ( V_208 , ( V_206 [ 1 ] - V_209 ) >> 3 ) ;
int V_210 ;
bool V_211 = false ;
int V_212 , V_213 ;
int V_214 ;
V_170 . V_178 = 0 ;
V_170 . V_176 = V_30 -> V_108 ;
V_170 . V_180 = - 1L ;
if ( ! V_30 -> V_131 ) {
if ( F_112 ( V_30 -> V_130 ) )
V_30 -> V_130 = 0 ;
F_113 ( V_2 ) ;
}
V_211 = F_79 ( V_2 , V_152 , V_207 ,
V_155 , V_156 ) ;
if ( V_211 )
V_170 . V_178 |= V_215 ;
if ( F_43 ( F_16 ( V_152 ) -> V_149 , V_156 - V_30 -> V_142 ) )
return 0 ;
if ( ! V_30 -> V_108 )
goto V_196;
V_210 = 0 ;
V_214 = 0 ;
for ( V_212 = 0 ; V_212 < V_155 ; V_212 ++ ) {
bool V_159 = ! V_212 && V_211 ;
V_154 [ V_210 ] . V_141 = F_80 ( & V_207 [ V_212 ] . V_141 ) ;
V_154 [ V_210 ] . V_90 = F_80 ( & V_207 [ V_212 ] . V_90 ) ;
if ( ! F_74 ( V_30 , V_159 ,
V_154 [ V_210 ] . V_141 ,
V_154 [ V_210 ] . V_90 ) ) {
int V_122 ;
if ( V_159 ) {
if ( ! V_30 -> V_132 )
V_122 = V_216 ;
else
V_122 = V_217 ;
} else {
if ( ( F_16 ( V_152 ) -> V_149 != V_30 -> V_103 ) &&
! F_50 ( V_154 [ V_210 ] . V_90 , V_30 -> V_103 ) )
continue;
V_122 = V_218 ;
}
F_66 ( F_67 ( V_2 ) , V_122 ) ;
if ( V_212 == 0 )
V_214 = - 1 ;
continue;
}
if ( ! F_50 ( V_154 [ V_210 ] . V_90 , V_156 ) )
continue;
V_210 ++ ;
}
for ( V_212 = V_210 - 1 ; V_212 > 0 ; V_212 -- ) {
for ( V_213 = 0 ; V_213 < V_212 ; V_213 ++ ) {
if ( F_50 ( V_154 [ V_213 ] . V_141 , V_154 [ V_213 + 1 ] . V_141 ) ) {
F_114 ( V_154 [ V_213 ] , V_154 [ V_213 + 1 ] ) ;
if ( V_213 == V_214 )
V_214 = V_213 + 1 ;
}
}
}
V_4 = F_101 ( V_2 ) ;
V_170 . V_174 = 0 ;
V_212 = 0 ;
if ( ! V_30 -> V_131 ) {
V_203 = V_30 -> V_204 + F_110 ( V_30 -> V_204 ) ;
} else {
V_203 = V_30 -> V_204 ;
while ( F_109 ( V_30 , V_203 ) && ! V_203 -> V_141 &&
! V_203 -> V_90 )
V_203 ++ ;
}
while ( V_212 < V_210 ) {
T_1 V_141 = V_154 [ V_212 ] . V_141 ;
T_1 V_90 = V_154 [ V_212 ] . V_90 ;
bool V_159 = ( V_211 && ( V_212 == V_214 ) ) ;
struct V_198 * V_199 = NULL ;
if ( V_211 && ( ( V_212 + 1 ) == V_214 ) )
V_199 = & V_154 [ V_212 + 1 ] ;
while ( F_109 ( V_30 , V_203 ) &&
! F_43 ( V_141 , V_203 -> V_90 ) )
V_203 ++ ;
if ( F_109 ( V_30 , V_203 ) && ! V_159 &&
F_50 ( V_90 , V_203 -> V_141 ) ) {
if ( F_43 ( V_141 , V_203 -> V_141 ) ) {
V_4 = F_107 ( V_4 , V_2 , & V_170 ,
V_141 ) ;
V_4 = F_105 ( V_4 , V_2 , V_199 ,
& V_170 ,
V_141 ,
V_203 -> V_141 ,
V_159 ) ;
}
if ( ! F_50 ( V_90 , V_203 -> V_90 ) )
goto V_219;
V_4 = F_108 ( V_4 , V_2 , V_199 ,
& V_170 ,
V_203 -> V_90 ) ;
if ( F_76 ( V_30 ) == V_203 -> V_90 ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_170 . V_174 = V_30 -> V_130 ;
V_203 ++ ;
goto V_220;
}
V_4 = F_107 ( V_4 , V_2 , & V_170 , V_203 -> V_90 ) ;
V_203 ++ ;
continue;
}
if ( ! F_43 ( V_141 , F_76 ( V_30 ) ) ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_170 . V_174 = V_30 -> V_130 ;
}
V_4 = F_107 ( V_4 , V_2 , & V_170 , V_141 ) ;
V_220:
V_4 = F_105 ( V_4 , V_2 , V_199 , & V_170 ,
V_141 , V_90 , V_159 ) ;
V_219:
V_212 ++ ;
}
for ( V_212 = 0 ; V_212 < F_110 ( V_30 -> V_204 ) - V_210 ; V_212 ++ ) {
V_30 -> V_204 [ V_212 ] . V_141 = 0 ;
V_30 -> V_204 [ V_212 ] . V_90 = 0 ;
}
for ( V_213 = 0 ; V_213 < V_210 ; V_213 ++ )
V_30 -> V_204 [ V_212 ++ ] = V_154 [ V_213 ] ;
F_75 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ( V_170 . V_176 < V_30 -> V_130 ) &&
( ( F_2 ( V_2 ) -> V_129 != V_221 ) || V_30 -> V_132 ) )
F_64 ( V_2 , V_30 -> V_130 - V_170 . V_176 , 0 ) ;
V_196:
#if V_128 > 0
F_112 ( ( int ) V_30 -> V_131 < 0 ) ;
F_112 ( ( int ) V_30 -> V_135 < 0 ) ;
F_112 ( ( int ) V_30 -> V_146 < 0 ) ;
F_112 ( ( int ) F_116 ( V_30 ) < 0 ) ;
#endif
* V_205 = V_170 . V_180 ;
return V_170 . V_178 ;
}
static bool F_117 ( struct V_29 * V_30 )
{
T_1 V_222 ;
V_222 = F_34 ( V_30 -> V_135 , 1U ) ;
V_222 = F_9 ( V_222 , V_30 -> V_108 ) ;
if ( ( V_30 -> V_131 + V_222 ) > V_30 -> V_108 ) {
V_30 -> V_131 = V_30 -> V_108 - V_222 ;
return true ;
}
return false ;
}
static void F_118 ( struct V_1 * V_2 , const int V_223 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_117 ( V_30 ) )
F_64 ( V_2 , V_30 -> V_108 + V_223 , 0 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_131 ++ ;
F_118 ( V_2 , 0 ) ;
F_115 ( V_30 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_224 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_224 > 0 ) {
if ( V_224 - 1 >= V_30 -> V_131 )
V_30 -> V_131 = 0 ;
else
V_30 -> V_131 -= V_224 - 1 ;
}
F_118 ( V_2 , V_224 ) ;
F_115 ( V_30 ) ;
}
static inline void F_121 ( struct V_29 * V_30 )
{
V_30 -> V_131 = 0 ;
}
static void F_122 ( struct V_29 * V_30 )
{
V_30 -> V_146 = 0 ;
V_30 -> V_135 = 0 ;
V_30 -> V_132 = 0 ;
V_30 -> V_133 = 0 ;
}
void F_123 ( struct V_29 * V_30 )
{
F_122 ( V_30 ) ;
V_30 -> V_130 = 0 ;
V_30 -> V_131 = 0 ;
}
void F_124 ( struct V_1 * V_2 , int V_225 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_226 = false ;
if ( V_6 -> V_129 <= V_227 ||
! F_50 ( V_30 -> V_177 , V_30 -> V_103 ) ||
( V_6 -> V_129 == V_221 && ! V_6 -> V_228 ) ) {
V_226 = true ;
V_30 -> V_229 = F_125 ( V_2 ) ;
V_30 -> V_230 = V_6 -> V_231 -> V_232 ( V_2 ) ;
F_126 ( V_2 , V_233 ) ;
}
V_30 -> V_53 = 1 ;
V_30 -> V_234 = 0 ;
V_30 -> V_78 = V_74 ;
F_122 ( V_30 ) ;
if ( F_65 ( V_30 ) )
F_121 ( V_30 ) ;
V_30 -> V_132 = V_30 -> V_103 ;
if ( V_225 ) {
V_30 -> V_131 = 0 ;
V_30 -> V_130 = 0 ;
}
F_127 ( V_30 ) ;
F_77 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_137 & V_150 )
V_30 -> V_132 = 0 ;
F_16 ( V_4 ) -> V_137 &= ( ~ V_194 ) | V_139 ;
if ( ! ( F_16 ( V_4 ) -> V_137 & V_139 ) || V_225 ) {
F_16 ( V_4 ) -> V_137 &= ~ V_139 ;
F_16 ( V_4 ) -> V_137 |= V_138 ;
V_30 -> V_135 += F_72 ( V_4 ) ;
V_30 -> V_136 = F_16 ( V_4 ) -> V_90 ;
}
}
F_115 ( V_30 ) ;
if ( V_6 -> V_129 <= V_227 &&
V_30 -> V_131 >= V_235 )
V_30 -> V_54 = F_40 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_128 ( V_2 , V_221 ) ;
V_30 -> V_177 = V_30 -> V_105 ;
F_12 ( V_30 ) ;
V_30 -> V_236 = V_237 &&
( V_226 || V_6 -> V_228 ) &&
! F_2 ( V_2 ) -> V_238 . V_239 ;
}
static bool F_129 ( struct V_1 * V_2 , int V_178 )
{
if ( V_178 & V_240 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_241 ) ;
F_124 ( V_2 , 1 ) ;
V_6 -> V_228 ++ ;
F_130 ( V_2 , F_101 ( V_2 ) ) ;
F_131 ( V_2 , V_242 ,
V_6 -> V_96 , V_243 ) ;
return true ;
}
return false ;
}
static inline int F_132 ( const struct V_29 * V_30 )
{
return F_65 ( V_30 ) ? V_30 -> V_131 + 1 : V_30 -> V_130 ;
}
static inline int F_133 ( const struct V_29 * V_30 )
{
return F_62 ( V_30 ) ? V_30 -> V_130 : V_30 -> V_131 + 1 ;
}
static bool F_134 ( struct V_1 * V_2 , int V_178 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_244 ;
if ( V_245 < 2 || V_245 > 3 ||
( V_178 & V_246 ) || ! V_30 -> V_99 )
return false ;
V_244 = F_34 ( F_135 ( V_30 -> V_99 >> 5 ) ,
F_136 ( 2 ) ) ;
if ( ! F_137 ( F_2 ( V_2 ) -> V_247 , ( V_248 + V_244 ) ) )
return false ;
F_131 ( V_2 , V_249 , V_244 ,
V_243 ) ;
return true ;
}
static bool F_138 ( struct V_1 * V_2 , int V_178 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_108 ;
if ( V_30 -> V_135 )
return true ;
if ( F_133 ( V_30 ) > V_30 -> V_54 )
return true ;
V_108 = V_30 -> V_108 ;
if ( V_108 <= V_30 -> V_54 &&
V_30 -> V_131 >= F_21 ( T_3 , V_108 / 2 , V_235 ) &&
! F_139 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_250 || V_251 ) &&
F_140 ( V_30 ) && F_133 ( V_30 ) > 1 &&
F_141 ( V_30 ) && ! F_78 ( V_2 ) )
return true ;
if ( V_30 -> V_252 && ! V_30 -> V_146 && V_30 -> V_131 &&
( V_30 -> V_108 >= ( V_30 -> V_131 + 1 ) && V_30 -> V_108 < 4 ) &&
! F_139 ( V_2 ) )
return ! F_134 ( V_2 , V_178 ) ;
return false ;
}
static void F_142 ( struct V_1 * V_2 , int V_253 , int V_254 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_143 , V_255 ;
int V_164 ;
unsigned int V_64 ;
const T_1 V_256 = F_141 ( V_30 ) ? V_30 -> V_105 : V_30 -> V_177 ;
F_112 ( V_253 > V_30 -> V_108 ) ;
if ( V_30 -> V_116 ) {
V_4 = V_30 -> V_116 ;
V_143 = V_30 -> V_182 ;
if ( V_254 && V_4 != F_101 ( V_2 ) )
return;
} else {
V_4 = F_101 ( V_2 ) ;
V_143 = 0 ;
}
F_106 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
V_30 -> V_116 = V_4 ;
V_30 -> V_182 = V_143 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_256 ) )
break;
V_255 = V_143 ;
if ( F_62 ( V_30 ) || F_65 ( V_30 ) ||
( F_16 ( V_4 ) -> V_137 & V_139 ) )
V_143 += F_72 ( V_4 ) ;
if ( V_143 > V_253 ) {
if ( ( F_141 ( V_30 ) && ! F_62 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_137 & V_139 ) ||
( V_255 >= V_253 ) )
break;
V_64 = F_3 ( V_4 ) -> V_11 ;
V_164 = F_83 ( V_2 , V_4 , ( V_253 - V_255 ) * V_64 , V_64 ) ;
if ( V_164 < 0 )
break;
V_143 = V_253 ;
}
F_71 ( V_30 , V_4 ) ;
if ( V_254 )
break;
}
F_115 ( V_30 ) ;
}
static void F_143 ( struct V_1 * V_2 , int V_257 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_65 ( V_30 ) ) {
F_142 ( V_2 , 1 , 1 ) ;
} else if ( F_62 ( V_30 ) ) {
int V_258 = V_30 -> V_130 - V_30 -> V_54 ;
if ( V_258 <= 0 )
V_258 = 1 ;
F_142 ( V_2 , V_258 , 0 ) ;
} else {
int V_259 = V_30 -> V_131 - V_30 -> V_54 ;
if ( V_259 >= 0 )
F_142 ( V_2 , V_259 , 0 ) ;
else if ( V_257 )
F_142 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_144 ( struct V_29 * V_30 )
{
V_30 -> V_53 = F_9 ( V_30 -> V_53 ,
F_116 ( V_30 ) + F_145 ( V_30 ) ) ;
V_30 -> V_78 = V_74 ;
}
static inline bool F_146 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_260 ||
( V_30 -> V_47 . V_261 && V_30 -> V_47 . V_89 &&
F_43 ( V_30 -> V_47 . V_89 , V_30 -> V_260 ) ) ;
}
static void F_147 ( struct V_1 * V_2 , const char * V_262 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_263 * V_264 = F_148 ( V_2 ) ;
if ( V_2 -> V_265 == V_266 ) {
F_68 ( L_2 ,
V_262 ,
& V_264 -> V_267 , F_149 ( V_264 -> V_268 ) ,
V_30 -> V_53 , F_150 ( V_30 ) ,
V_30 -> V_230 , V_30 -> V_229 ,
V_30 -> V_108 ) ;
}
#if F_151 ( V_269 )
else if ( V_2 -> V_265 == V_270 ) {
struct V_271 * V_272 = F_152 ( V_2 ) ;
F_68 ( L_3 ,
V_262 ,
& V_272 -> V_273 , F_149 ( V_264 -> V_268 ) ,
V_30 -> V_53 , F_150 ( V_30 ) ,
V_30 -> V_230 , V_30 -> V_229 ,
V_30 -> V_108 ) ;
}
#endif
}
static void F_153 ( struct V_1 * V_2 , bool V_274 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_274 ) {
struct V_3 * V_4 ;
F_77 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_137 &= ~ V_138 ;
}
V_30 -> V_135 = 0 ;
F_127 ( V_30 ) ;
}
if ( V_30 -> V_229 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_231 -> V_275 )
V_30 -> V_53 = V_6 -> V_231 -> V_275 ( V_2 ) ;
else
V_30 -> V_53 = F_34 ( V_30 -> V_53 , V_30 -> V_230 << 1 ) ;
if ( V_30 -> V_229 > V_30 -> V_230 ) {
V_30 -> V_230 = V_30 -> V_229 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_53 = F_34 ( V_30 -> V_53 , V_30 -> V_230 ) ;
}
V_30 -> V_78 = V_74 ;
V_30 -> V_132 = 0 ;
}
static inline bool F_154 ( const struct V_29 * V_30 )
{
return V_30 -> V_132 && ( ! V_30 -> V_133 || F_146 ( V_30 ) ) ;
}
static bool F_155 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_154 ( V_30 ) ) {
int V_122 ;
F_147 ( V_2 , F_2 ( V_2 ) -> V_129 == V_221 ? L_4 : L_5 ) ;
F_153 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_129 == V_221 )
V_122 = V_276 ;
else
V_122 = V_277 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
}
if ( V_30 -> V_103 == V_30 -> V_177 && F_65 ( V_30 ) ) {
F_144 ( V_30 ) ;
return true ;
}
F_128 ( V_2 , V_278 ) ;
return false ;
}
static bool F_156 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_132 && ! V_30 -> V_133 ) {
F_147 ( V_2 , L_6 ) ;
F_153 ( V_2 , false ) ;
F_66 ( F_67 ( V_2 ) , V_279 ) ;
return true ;
}
return false ;
}
static bool F_157 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_146 )
return true ;
V_4 = F_101 ( V_2 ) ;
if ( F_100 ( V_4 && F_16 ( V_4 ) -> V_137 & V_188 ) )
return true ;
return false ;
}
static bool F_158 ( struct V_1 * V_2 , bool V_280 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_280 || F_154 ( V_30 ) ) {
F_153 ( V_2 , true ) ;
F_147 ( V_2 , L_7 ) ;
F_66 ( F_67 ( V_2 ) , V_276 ) ;
if ( V_280 )
F_66 ( F_67 ( V_2 ) ,
V_281 ) ;
F_2 ( V_2 ) -> V_228 = 0 ;
if ( V_280 || F_141 ( V_30 ) )
F_128 ( V_2 , V_278 ) ;
return true ;
}
return false ;
}
static void F_159 ( struct V_1 * V_2 , const bool V_282 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_177 = V_30 -> V_105 ;
V_30 -> V_283 = 0 ;
V_30 -> V_234 = 0 ;
V_30 -> V_284 = V_30 -> V_53 ;
V_30 -> V_285 = 0 ;
V_30 -> V_286 = 0 ;
if ( V_282 )
V_30 -> V_230 = F_2 ( V_2 ) -> V_231 -> V_232 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_160 ( struct V_1 * V_2 , const int V_287 ,
int V_257 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_288 = 0 ;
int V_289 = V_30 -> V_230 - F_116 ( V_30 ) ;
int V_290 = V_287 -
( V_30 -> V_108 - V_30 -> V_131 ) ;
V_30 -> V_285 += V_290 ;
if ( F_116 ( V_30 ) > V_30 -> V_230 ) {
T_2 V_291 = ( T_2 ) V_30 -> V_230 * V_30 -> V_285 +
V_30 -> V_284 - 1 ;
V_288 = F_161 ( V_291 , V_30 -> V_284 ) - V_30 -> V_286 ;
} else {
V_288 = F_40 ( int , V_289 ,
F_21 ( int , V_30 -> V_285 - V_30 -> V_286 ,
V_290 ) + 1 ) ;
}
V_288 = F_34 ( V_288 , ( V_257 ? 1 : 0 ) ) ;
V_30 -> V_53 = F_116 ( V_30 ) + V_288 ;
}
static inline void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_129 == V_292 ||
( V_30 -> V_132 && V_30 -> V_230 < V_293 ) ) {
V_30 -> V_53 = V_30 -> V_230 ;
V_30 -> V_78 = V_74 ;
}
F_126 ( V_2 , V_294 ) ;
}
void F_163 ( struct V_1 * V_2 , const int V_282 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_229 = 0 ;
if ( F_2 ( V_2 ) -> V_129 < V_292 ) {
V_30 -> V_132 = 0 ;
F_159 ( V_2 , V_282 ) ;
F_128 ( V_2 , V_292 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_170 = V_278 ;
if ( F_150 ( V_30 ) || F_157 ( V_2 ) )
V_170 = V_227 ;
if ( F_2 ( V_2 ) -> V_129 != V_170 ) {
F_128 ( V_2 , V_170 ) ;
V_30 -> V_177 = V_30 -> V_105 ;
}
}
static void F_165 ( struct V_1 * V_2 , int V_178 , const int V_287 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ! F_157 ( V_2 ) )
V_30 -> V_260 = 0 ;
if ( V_178 & V_246 )
F_163 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_129 != V_292 ) {
F_164 ( V_2 ) ;
} else {
F_160 ( V_2 , V_287 , 0 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_238 . V_295 = V_6 -> V_238 . V_239 - 1 ;
V_6 -> V_238 . V_239 = 0 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_229 = F_125 ( V_2 ) ;
V_30 -> V_53 = V_30 -> V_53 *
F_168 ( V_2 , V_30 -> V_49 ) /
V_6 -> V_238 . V_239 ;
V_30 -> V_234 = 0 ;
V_30 -> V_78 = V_74 ;
V_30 -> V_230 = F_125 ( V_2 ) ;
V_6 -> V_238 . V_296 = V_6 -> V_238 . V_239 ;
V_6 -> V_238 . V_239 = 0 ;
F_169 ( V_2 , V_6 -> V_297 ) ;
}
void F_170 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_64 = F_171 ( V_2 ) ;
T_1 V_298 = V_30 -> V_135 ;
F_77 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
if ( F_94 ( V_4 ) > V_64 &&
! ( F_16 ( V_4 ) -> V_137 & V_139 ) ) {
if ( F_16 ( V_4 ) -> V_137 & V_150 ) {
F_16 ( V_4 ) -> V_137 &= ~ V_150 ;
V_30 -> V_146 -= F_72 ( V_4 ) ;
}
F_73 ( V_30 , V_4 ) ;
}
}
F_172 ( V_30 ) ;
if ( V_298 == V_30 -> V_135 )
return;
if ( F_65 ( V_30 ) )
F_117 ( V_30 ) ;
F_115 ( V_30 ) ;
if ( V_6 -> V_129 != V_221 ) {
V_30 -> V_177 = V_30 -> V_105 ;
V_30 -> V_230 = F_125 ( V_2 ) ;
V_30 -> V_229 = 0 ;
V_30 -> V_132 = 0 ;
F_128 ( V_2 , V_221 ) ;
}
F_173 ( V_2 ) ;
}
static void F_174 ( struct V_1 * V_2 , bool V_299 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_122 ;
if ( F_65 ( V_30 ) )
V_122 = V_300 ;
else
V_122 = V_301 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
V_30 -> V_229 = 0 ;
V_30 -> V_132 = V_30 -> V_103 ;
V_30 -> V_133 = V_30 -> V_146 ;
if ( F_2 ( V_2 ) -> V_129 < V_292 ) {
if ( ! V_299 )
V_30 -> V_229 = F_125 ( V_2 ) ;
F_159 ( V_2 , true ) ;
}
F_128 ( V_2 , V_148 ) ;
}
static void F_175 ( struct V_1 * V_2 , int V_178 , bool V_302 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_303 = ! F_43 ( V_30 -> V_103 , V_30 -> V_177 ) ;
if ( V_30 -> V_236 ) {
if ( F_158 ( V_2 , V_178 & V_179 ) )
return;
if ( F_50 ( V_30 -> V_105 , V_30 -> V_177 ) &&
( V_178 & V_181 || V_302 ) ) {
V_30 -> V_236 = 0 ;
} else if ( V_178 & V_304 && ! V_303 ) {
V_30 -> V_177 = V_30 -> V_105 ;
F_176 ( V_2 , F_171 ( V_2 ) ,
V_305 ) ;
if ( F_50 ( V_30 -> V_105 , V_30 -> V_177 ) )
return;
V_30 -> V_236 = 0 ;
}
}
if ( V_303 ) {
V_6 -> V_228 = 0 ;
F_155 ( V_2 ) ;
return;
}
if ( V_178 & V_306 )
V_6 -> V_228 = 0 ;
if ( F_65 ( V_30 ) ) {
if ( F_50 ( V_30 -> V_105 , V_30 -> V_177 ) && V_302 )
F_119 ( V_2 ) ;
else if ( V_178 & V_304 )
F_121 ( V_30 ) ;
}
if ( F_158 ( V_2 , false ) )
return;
F_173 ( V_2 ) ;
}
static bool F_177 ( struct V_1 * V_2 , const int V_224 ,
const int V_287 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_132 && F_146 ( V_30 ) ) {
F_64 ( V_2 , F_132 ( V_30 ) + V_224 , 1 ) ;
if ( V_30 -> V_146 ) {
F_160 ( V_2 , V_287 , 0 ) ;
return true ;
}
if ( ! F_157 ( V_2 ) )
V_30 -> V_260 = 0 ;
F_147 ( V_2 , L_8 ) ;
F_153 ( V_2 , true ) ;
F_66 ( F_67 ( V_2 ) , V_307 ) ;
F_164 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_178 ( struct V_1 * V_2 , const int V_224 ,
const int V_287 ,
bool V_302 , int V_178 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_308 = V_302 || ( ( V_178 & V_181 ) &&
( F_132 ( V_30 ) > V_30 -> V_54 ) ) ;
int V_257 = 0 ;
if ( F_112 ( ! V_30 -> V_108 && V_30 -> V_131 ) )
V_30 -> V_131 = 0 ;
if ( F_112 ( ! V_30 -> V_131 && V_30 -> V_130 ) )
V_30 -> V_130 = 0 ;
if ( V_178 & V_246 )
V_30 -> V_229 = 0 ;
if ( F_129 ( V_2 , V_178 ) )
return;
F_115 ( V_30 ) ;
if ( V_6 -> V_129 == V_278 ) {
F_112 ( V_30 -> V_146 != 0 ) ;
V_30 -> V_260 = 0 ;
} else if ( ! F_43 ( V_30 -> V_103 , V_30 -> V_177 ) ) {
switch ( V_6 -> V_129 ) {
case V_292 :
if ( V_30 -> V_103 != V_30 -> V_177 ) {
F_162 ( V_2 ) ;
F_128 ( V_2 , V_278 ) ;
}
break;
case V_148 :
if ( F_65 ( V_30 ) )
F_121 ( V_30 ) ;
if ( F_155 ( V_2 ) )
return;
F_162 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_129 ) {
case V_148 :
if ( ! ( V_178 & V_304 ) ) {
if ( F_65 ( V_30 ) && V_302 )
F_119 ( V_2 ) ;
} else {
if ( F_177 ( V_2 , V_224 , V_287 ) )
return;
V_308 = F_65 ( V_30 ) ||
F_132 ( V_30 ) > V_30 -> V_54 ;
}
if ( F_156 ( V_2 ) ) {
F_164 ( V_2 ) ;
return;
}
break;
case V_221 :
F_175 ( V_2 , V_178 , V_302 ) ;
if ( V_6 -> V_129 != V_278 )
return;
default:
if ( F_65 ( V_30 ) ) {
if ( V_178 & V_304 )
F_121 ( V_30 ) ;
if ( V_302 )
F_119 ( V_2 ) ;
}
if ( V_6 -> V_129 <= V_227 )
F_156 ( V_2 ) ;
if ( ! F_138 ( V_2 , V_178 ) ) {
F_165 ( V_2 , V_178 , V_287 ) ;
return;
}
if ( V_6 -> V_129 < V_292 &&
V_6 -> V_238 . V_239 &&
V_30 -> V_103 == V_30 -> V_309 . V_310 ) {
F_166 ( V_2 ) ;
V_30 -> V_53 ++ ;
F_170 ( V_2 ) ;
return;
}
F_174 ( V_2 , ( V_178 & V_246 ) ) ;
V_257 = 1 ;
}
if ( V_308 )
F_143 ( V_2 , V_257 ) ;
F_160 ( V_2 , V_287 , V_257 ) ;
F_173 ( V_2 ) ;
}
static inline bool F_179 ( struct V_1 * V_2 , const int V_178 ,
long V_311 , long V_205 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_178 & V_312 )
V_311 = - 1L ;
if ( V_311 < 0 )
V_311 = V_205 ;
if ( V_311 < 0 && V_30 -> V_47 . V_261 && V_30 -> V_47 . V_89 &&
V_178 & V_313 )
V_311 = F_180 ( V_74 - V_30 -> V_47 . V_89 ) ;
if ( V_311 < 0 )
return false ;
F_49 ( V_2 , V_311 ) ;
F_56 ( V_2 ) ;
F_2 ( V_2 ) -> V_314 = 0 ;
return true ;
}
static void F_181 ( struct V_1 * V_2 , const T_1 V_315 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_311 = - 1L ;
if ( V_315 && ! V_30 -> V_316 )
V_311 = F_180 ( V_74 - V_315 ) ;
if ( ! V_30 -> V_99 )
F_179 ( V_2 , V_317 , V_311 , - 1L ) ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_318 , T_1 V_224 , T_1 V_319 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_231 -> V_320 ( V_2 , V_318 , V_224 , V_319 ) ;
F_7 ( V_2 ) -> V_78 = V_74 ;
}
void F_183 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_321 )
return;
if ( ! V_30 -> V_108 ) {
F_184 ( V_2 , V_242 ) ;
} else {
T_1 V_322 = F_2 ( V_2 ) -> V_96 ;
if ( V_6 -> V_323 == V_249 ||
V_6 -> V_323 == V_324 ) {
struct V_3 * V_4 = F_101 ( V_2 ) ;
const T_1 V_325 = F_16 ( V_4 ) -> V_326 + V_322 ;
T_5 V_289 = ( T_5 ) ( V_325 - V_74 ) ;
if ( V_289 > 0 )
V_322 = V_289 ;
}
F_131 ( V_2 , V_242 , V_322 ,
V_243 ) ;
}
}
void F_185 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_183 ( V_2 ) ;
if ( ! V_30 -> V_252 )
return;
F_174 ( V_2 , false ) ;
F_143 ( V_2 , 1 ) ;
F_173 ( V_2 ) ;
}
static T_1 F_186 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_327 ;
F_89 ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_103 ) ) ;
V_327 = F_72 ( V_4 ) ;
if ( F_187 ( V_2 , V_4 , V_30 -> V_103 - F_16 ( V_4 ) -> V_75 ) )
return 0 ;
V_327 -= F_72 ( V_4 ) ;
if ( V_327 ) {
F_89 ( F_72 ( V_4 ) == 0 ) ;
F_89 ( ! F_43 ( F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ) ;
}
return V_327 ;
}
static int F_188 ( struct V_1 * V_2 , int V_328 ,
T_1 V_156 , long V_205 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_172 V_329 , V_330 , V_94 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_331 = V_30 -> V_131 ;
T_1 V_176 = V_30 -> V_108 ;
bool V_332 = true ;
long V_333 = - 1L ;
long V_311 = - 1L ;
struct V_3 * V_4 ;
T_1 V_334 = 0 ;
bool V_335 ;
int V_178 = 0 ;
V_329 . V_336 = 0 ;
while ( ( V_4 = F_101 ( V_2 ) ) && V_4 != F_78 ( V_2 ) ) {
struct V_337 * V_338 = F_16 ( V_4 ) ;
T_4 V_137 = V_338 -> V_137 ;
T_1 V_339 ;
if ( F_50 ( V_338 -> V_90 , V_30 -> V_103 ) ) {
if ( F_72 ( V_4 ) == 1 ||
! F_50 ( V_30 -> V_103 , V_338 -> V_75 ) )
break;
V_339 = F_186 ( V_2 , V_4 ) ;
if ( ! V_339 )
break;
V_332 = false ;
} else {
V_339 = F_72 ( V_4 ) ;
}
if ( V_137 & V_175 ) {
if ( V_137 & V_150 )
V_30 -> V_146 -= V_339 ;
V_178 |= V_312 ;
} else {
V_330 = V_4 -> V_172 ;
F_189 ( V_330 . V_336 == 0 ) ;
if ( ! V_329 . V_336 )
V_329 = V_330 ;
if ( ! ( V_137 & V_139 ) )
V_176 = F_9 ( V_334 , V_176 ) ;
if ( ! F_50 ( V_338 -> V_90 , V_30 -> V_177 ) )
V_178 |= V_179 ;
}
if ( V_137 & V_139 )
V_30 -> V_131 -= V_339 ;
if ( V_137 & V_138 )
V_30 -> V_135 -= V_339 ;
V_30 -> V_108 -= V_339 ;
V_334 += V_339 ;
if ( ! ( V_338 -> V_190 & V_340 ) ) {
V_178 |= V_306 ;
} else {
V_178 |= V_317 ;
V_30 -> V_260 = 0 ;
}
if ( ! V_332 )
break;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
if ( V_4 == V_30 -> V_134 )
V_30 -> V_134 = NULL ;
if ( V_4 == V_30 -> V_116 )
V_30 -> V_116 = NULL ;
}
if ( F_53 ( F_190 ( V_30 -> V_341 , V_156 , V_30 -> V_103 ) ) )
V_30 -> V_341 = V_30 -> V_103 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_137 & V_139 ) )
V_178 |= V_240 ;
F_85 ( & V_94 ) ;
if ( V_329 . V_336 ) {
V_311 = F_86 ( & V_94 , & V_329 ) ;
V_333 = F_86 ( & V_94 , & V_330 ) ;
}
V_335 = F_179 ( V_2 , V_178 , V_311 , V_205 ) ;
if ( V_178 & V_313 ) {
const struct V_342 * V_343
= F_2 ( V_2 ) -> V_231 ;
F_183 ( V_2 ) ;
if ( F_100 ( V_6 -> V_238 . V_239 &&
! F_50 ( V_30 -> V_309 . V_344 , V_30 -> V_103 ) ) ) {
F_167 ( V_2 ) ;
}
if ( F_65 ( V_30 ) ) {
F_120 ( V_2 , V_334 ) ;
} else {
int V_289 ;
if ( V_176 < V_328 )
F_64 ( V_2 , V_30 -> V_130 - V_176 , 0 ) ;
V_289 = F_62 ( V_30 ) ? V_334 :
V_331 - V_30 -> V_131 ;
V_30 -> V_182 -= F_9 ( V_30 -> V_182 , V_289 ) ;
}
V_30 -> V_130 -= F_9 ( V_334 , V_30 -> V_130 ) ;
if ( V_343 -> V_334 )
V_343 -> V_334 ( V_2 , V_334 , V_333 ) ;
} else if ( V_4 && V_335 && V_205 >= 0 &&
V_205 > F_86 ( & V_94 , & V_4 -> V_172 ) ) {
F_183 ( V_2 ) ;
}
#if V_128 > 0
F_112 ( ( int ) V_30 -> V_131 < 0 ) ;
F_112 ( ( int ) V_30 -> V_135 < 0 ) ;
F_112 ( ( int ) V_30 -> V_146 < 0 ) ;
if ( ! V_30 -> V_108 && F_141 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_135 ) {
F_68 ( L_9 ,
V_30 -> V_135 , V_6 -> V_129 ) ;
V_30 -> V_135 = 0 ;
}
if ( V_30 -> V_131 ) {
F_68 ( L_10 ,
V_30 -> V_131 , V_6 -> V_129 ) ;
V_30 -> V_131 = 0 ;
}
if ( V_30 -> V_146 ) {
F_68 ( L_11 ,
V_30 -> V_146 , V_6 -> V_129 ) ;
V_30 -> V_146 = 0 ;
}
}
#endif
return V_178 ;
}
static void F_191 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_50 ( F_16 ( F_78 ( V_2 ) ) -> V_90 , F_192 ( V_30 ) ) ) {
V_6 -> V_314 = 0 ;
F_184 ( V_2 , V_345 ) ;
} else {
F_131 ( V_2 , V_345 ,
F_9 ( V_6 -> V_96 << V_6 -> V_314 , V_243 ) ,
V_243 ) ;
}
}
static inline bool F_193 ( const struct V_1 * V_2 , const int V_178 )
{
return ! ( V_178 & V_346 ) || ( V_178 & V_347 ) ||
F_2 ( V_2 ) -> V_129 != V_278 ;
}
static inline bool F_194 ( const struct V_1 * V_2 , const int V_178 )
{
if ( F_195 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_54 > V_235 )
return V_178 & V_348 ;
return V_178 & V_306 ;
}
static inline bool F_196 ( const struct V_29 * V_30 ,
const T_1 V_318 , const T_1 V_149 ,
const T_1 V_349 )
{
return F_50 ( V_318 , V_30 -> V_103 ) ||
F_50 ( V_149 , V_30 -> V_350 ) ||
( V_149 == V_30 -> V_350 && V_349 > V_30 -> V_351 ) ;
}
static int F_197 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_318 ,
T_1 V_149 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_178 = 0 ;
T_1 V_349 = F_149 ( F_6 ( V_4 ) -> V_58 ) ;
if ( F_53 ( ! F_6 ( V_4 ) -> V_43 ) )
V_349 <<= V_30 -> V_47 . V_352 ;
if ( F_196 ( V_30 , V_318 , V_149 , V_349 ) ) {
V_178 |= V_353 ;
F_198 ( V_30 , V_149 ) ;
if ( V_30 -> V_351 != V_349 ) {
V_30 -> V_351 = V_349 ;
V_30 -> V_354 = 0 ;
F_199 ( V_2 ) ;
if ( V_349 > V_30 -> V_142 ) {
V_30 -> V_142 = V_349 ;
F_169 ( V_2 , F_2 ( V_2 ) -> V_297 ) ;
}
}
}
V_30 -> V_103 = V_318 ;
return V_178 ;
}
static void F_200 ( struct V_1 * V_2 )
{
static T_1 V_355 ;
static unsigned int V_356 ;
T_1 V_94 = V_248 / V_357 ;
if ( V_94 != V_355 ) {
V_355 = V_94 ;
V_356 = 0 ;
}
if ( ++ V_356 <= V_358 ) {
F_66 ( F_67 ( V_2 ) , V_359 ) ;
F_201 ( V_2 ) ;
}
}
static void F_202 ( struct V_29 * V_30 )
{
V_30 -> V_47 . V_360 = V_30 -> V_47 . V_361 ;
V_30 -> V_47 . V_362 = F_203 () ;
}
static void F_204 ( struct V_29 * V_30 , T_1 V_75 )
{
if ( V_30 -> V_47 . V_261 && ! F_50 ( V_75 , V_30 -> V_363 ) ) {
if ( F_205 ( & V_30 -> V_47 , 0 ) )
F_202 ( V_30 ) ;
}
}
static void F_206 ( struct V_1 * V_2 , T_1 V_318 , int V_178 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_364 = ( V_318 == V_30 -> V_283 ) &&
! ( V_178 & ( V_304 |
V_346 | V_181 ) ) ;
if ( V_364 ) {
V_30 -> V_283 = 0 ;
return;
}
if ( F_50 ( V_318 , V_30 -> V_283 ) ) {
V_30 -> V_283 = 0 ;
if ( ! ( V_178 & V_215 ) ) {
F_159 ( V_2 , true ) ;
F_128 ( V_2 , V_292 ) ;
F_162 ( V_2 ) ;
F_164 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) ,
V_365 ) ;
}
}
}
static int F_207 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_178 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_156 = V_30 -> V_103 ;
T_1 V_149 = F_16 ( V_4 ) -> V_75 ;
T_1 V_318 = F_16 ( V_4 ) -> V_149 ;
bool V_302 = false ;
T_1 V_366 ;
T_1 V_328 ;
int V_367 = V_30 -> V_108 ;
const int V_287 = V_30 -> V_108 - V_30 -> V_131 ;
int V_224 = 0 ;
long V_205 = - 1L ;
if ( F_43 ( V_318 , V_156 ) ) {
if ( F_43 ( V_318 , V_156 - V_30 -> V_142 ) ) {
F_200 ( V_2 ) ;
return - 1 ;
}
goto V_368;
}
if ( F_50 ( V_318 , V_30 -> V_105 ) )
goto V_369;
if ( V_6 -> V_323 == V_249 ||
V_6 -> V_323 == V_324 )
F_183 ( V_2 ) ;
if ( F_50 ( V_318 , V_156 ) )
V_178 |= V_304 ;
V_328 = V_30 -> V_130 ;
V_366 = F_116 ( V_30 ) ;
if ( V_178 & V_370 )
F_204 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! ( V_178 & V_371 ) && F_50 ( V_318 , V_156 ) ) {
F_198 ( V_30 , V_149 ) ;
V_30 -> V_103 = V_318 ;
V_178 |= V_353 ;
F_126 ( V_2 , V_372 ) ;
F_66 ( F_67 ( V_2 ) , V_373 ) ;
} else {
if ( V_149 != F_16 ( V_4 ) -> V_90 )
V_178 |= V_374 ;
else
F_66 ( F_67 ( V_2 ) , V_375 ) ;
V_178 |= F_197 ( V_2 , V_4 , V_318 , V_149 ) ;
if ( F_16 ( V_4 ) -> V_137 )
V_178 |= F_111 ( V_2 , V_4 , V_156 ,
& V_205 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_178 |= V_246 ;
F_126 ( V_2 , V_376 ) ;
}
V_2 -> V_377 = 0 ;
V_6 -> V_378 = 0 ;
V_30 -> V_379 = V_74 ;
if ( ! V_367 )
goto V_380;
V_224 = V_30 -> V_108 ;
V_178 |= F_188 ( V_2 , V_328 , V_156 ,
V_205 ) ;
V_224 -= V_30 -> V_108 ;
if ( F_194 ( V_2 , V_178 ) )
F_182 ( V_2 , V_318 , V_224 , V_366 ) ;
if ( F_193 ( V_2 , V_178 ) ) {
V_302 = ! ( V_178 & ( V_304 | V_346 ) ) ;
F_178 ( V_2 , V_224 , V_287 ,
V_302 , V_178 ) ;
}
if ( V_30 -> V_283 )
F_206 ( V_2 , V_318 , V_178 ) ;
if ( ( V_178 & V_348 ) || ! ( V_178 & V_346 ) ) {
struct V_111 * V_112 = F_208 ( V_2 ) ;
if ( V_112 )
F_209 ( V_112 ) ;
}
if ( V_6 -> V_323 == V_242 )
F_210 ( V_2 ) ;
F_52 ( V_2 ) ;
return 1 ;
V_380:
if ( V_178 & V_215 )
F_178 ( V_2 , V_224 , V_287 ,
V_302 , V_178 ) ;
if ( F_78 ( V_2 ) )
F_191 ( V_2 ) ;
if ( V_30 -> V_283 )
F_206 ( V_2 , V_318 , V_178 ) ;
return 1 ;
V_369:
F_211 ( V_2 , L_12 , V_318 , V_30 -> V_103 , V_30 -> V_105 ) ;
return - 1 ;
V_368:
if ( F_16 ( V_4 ) -> V_137 ) {
V_178 |= F_111 ( V_2 , V_4 , V_156 ,
& V_205 ) ;
F_178 ( V_2 , V_224 , V_287 ,
V_302 , V_178 ) ;
}
F_211 ( V_2 , L_13 , V_318 , V_30 -> V_103 , V_30 -> V_105 ) ;
return 0 ;
}
void F_212 ( const struct V_3 * V_4 ,
struct V_381 * V_382 , int V_383 ,
struct V_384 * V_385 )
{
const unsigned char * V_206 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_386 = ( V_41 -> V_387 * 4 ) - sizeof( struct V_15 ) ;
V_206 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_382 -> V_261 = 0 ;
while ( V_386 > 0 ) {
int V_388 = * V_206 ++ ;
int V_389 ;
switch ( V_388 ) {
case V_390 :
return;
case V_391 :
V_386 -- ;
continue;
default:
V_389 = * V_206 ++ ;
if ( V_389 < 2 )
return;
if ( V_389 > V_386 )
return;
switch ( V_388 ) {
case V_392 :
if ( V_389 == V_393 && V_41 -> V_43 && ! V_383 ) {
T_6 V_394 = F_213 ( V_206 ) ;
if ( V_394 ) {
if ( V_382 -> V_395 &&
V_382 -> V_395 < V_394 )
V_394 = V_382 -> V_395 ;
V_382 -> V_48 = V_394 ;
}
}
break;
case V_396 :
if ( V_389 == V_397 && V_41 -> V_43 &&
! V_383 && V_398 ) {
T_7 V_352 = * ( T_7 * ) V_206 ;
V_382 -> V_399 = 1 ;
if ( V_352 > 14 ) {
F_214 ( L_14 ,
V_400 ,
V_352 ) ;
V_352 = 14 ;
}
V_382 -> V_352 = V_352 ;
}
break;
case V_401 :
if ( ( V_389 == V_402 ) &&
( ( V_383 && V_382 -> V_403 ) ||
( ! V_383 && V_404 ) ) ) {
V_382 -> V_261 = 1 ;
V_382 -> V_361 = F_80 ( V_206 ) ;
V_382 -> V_89 = F_80 ( V_206 + 4 ) ;
}
break;
case V_405 :
if ( V_389 == V_406 && V_41 -> V_43 &&
! V_383 && V_407 ) {
V_382 -> V_117 = V_408 ;
F_215 ( V_382 ) ;
}
break;
case V_409 :
if ( ( V_389 >= ( V_209 + V_410 ) ) &&
! ( ( V_389 - V_209 ) % V_410 ) &&
V_382 -> V_117 ) {
F_16 ( V_4 ) -> V_137 = ( V_206 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_216
case V_411 :
break;
#endif
case V_412 :
if ( V_389 < V_413 ||
F_213 ( V_206 ) != V_414 ||
V_385 == NULL || ! V_41 -> V_43 || ( V_389 & 1 ) )
break;
V_385 -> V_10 = V_389 - V_413 ;
if ( V_385 -> V_10 >= V_415 &&
V_385 -> V_10 <= V_416 )
memcpy ( V_385 -> V_417 , V_206 + 2 , V_385 -> V_10 ) ;
else if ( V_385 -> V_10 != 0 )
V_385 -> V_10 = - 1 ;
break;
}
V_206 += V_389 - 2 ;
V_386 -= V_389 ;
}
}
}
static bool F_217 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_8 * V_206 = ( const T_8 * ) ( V_41 + 1 ) ;
if ( * V_206 == F_218 ( ( V_391 << 24 ) | ( V_391 << 16 )
| ( V_401 << 8 ) | V_402 ) ) {
V_30 -> V_47 . V_261 = 1 ;
++ V_206 ;
V_30 -> V_47 . V_361 = F_219 ( * V_206 ) ;
++ V_206 ;
if ( * V_206 )
V_30 -> V_47 . V_89 = F_219 ( * V_206 ) - V_30 -> V_418 ;
else
V_30 -> V_47 . V_89 = 0 ;
return true ;
}
return false ;
}
static bool F_220 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 , struct V_29 * V_30 )
{
if ( V_41 -> V_387 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_47 . V_261 = 0 ;
return false ;
} else if ( V_30 -> V_47 . V_403 &&
V_41 -> V_387 == ( ( sizeof( * V_41 ) + V_419 ) / 4 ) ) {
if ( F_217 ( V_30 , V_41 ) )
return true ;
}
F_212 ( V_4 , & V_30 -> V_47 , 1 , NULL ) ;
if ( V_30 -> V_47 . V_261 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_418 ;
return true ;
}
const T_4 * F_221 ( const struct V_15 * V_41 )
{
int V_386 = ( V_41 -> V_387 << 2 ) - sizeof( * V_41 ) ;
const T_4 * V_206 = ( const T_4 * ) ( V_41 + 1 ) ;
if ( V_386 < V_420 )
return NULL ;
while ( V_386 > 0 ) {
int V_388 = * V_206 ++ ;
int V_389 ;
switch ( V_388 ) {
case V_390 :
return NULL ;
case V_391 :
V_386 -- ;
continue;
default:
V_389 = * V_206 ++ ;
if ( V_389 < 2 || V_389 > V_386 )
return NULL ;
if ( V_388 == V_411 )
return V_389 == V_420 ? V_206 : NULL ;
}
V_206 += V_389 - 2 ;
V_386 -= V_389 ;
}
return NULL ;
}
static int F_222 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_75 = F_16 ( V_4 ) -> V_75 ;
T_1 V_318 = F_16 ( V_4 ) -> V_149 ;
return (
( V_41 -> V_318 && V_75 == F_16 ( V_4 ) -> V_90 && V_75 == V_30 -> V_88 ) &&
V_318 == V_30 -> V_103 &&
! F_196 ( V_30 , V_318 , V_75 , F_149 ( V_41 -> V_58 ) << V_30 -> V_47 . V_352 ) &&
( T_5 ) ( V_30 -> V_47 . V_360 - V_30 -> V_47 . V_361 ) <= ( F_2 ( V_2 ) -> V_96 * 1024 ) / V_357 ) ;
}
static inline bool F_223 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_205 ( & V_30 -> V_47 , V_421 ) &&
! F_222 ( V_2 , V_4 ) ;
}
static inline bool F_224 ( const struct V_29 * V_30 , T_1 V_75 , T_1 V_90 )
{
return ! F_43 ( V_90 , V_30 -> V_363 ) &&
! F_50 ( V_75 , V_30 -> V_88 + F_225 ( V_30 ) ) ;
}
void F_226 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_422 ) {
case V_423 :
V_2 -> V_424 = V_425 ;
break;
case V_426 :
V_2 -> V_424 = V_427 ;
break;
case V_428 :
return;
default:
V_2 -> V_424 = V_429 ;
}
F_227 () ;
if ( ! F_228 ( V_2 , V_430 ) )
V_2 -> V_431 ( V_2 ) ;
F_229 ( V_2 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_111 * V_112 ;
F_47 ( V_2 ) ;
V_2 -> V_432 |= V_433 ;
F_231 ( V_2 , V_434 ) ;
switch ( V_2 -> V_422 ) {
case V_435 :
case V_436 :
F_232 ( V_2 , V_426 ) ;
V_112 = F_208 ( V_2 ) ;
if ( ! V_112 || ! F_60 ( V_112 , V_437 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_426 :
case V_438 :
break;
case V_439 :
break;
case V_440 :
F_201 ( V_2 ) ;
F_232 ( V_2 , V_438 ) ;
break;
case V_441 :
F_201 ( V_2 ) ;
F_233 ( V_2 , V_442 , 0 ) ;
break;
default:
F_234 ( L_15 ,
V_400 , V_2 -> V_422 ) ;
break;
}
F_235 ( & V_30 -> V_443 ) ;
if ( F_141 ( V_30 ) )
F_215 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
if ( ! F_228 ( V_2 , V_430 ) ) {
V_2 -> V_444 ( V_2 ) ;
if ( V_2 -> V_432 == V_445 ||
V_2 -> V_422 == V_428 )
F_236 ( V_2 , V_446 , V_447 ) ;
else
F_236 ( V_2 , V_446 , V_448 ) ;
}
}
static inline bool F_237 ( struct V_198 * V_154 , T_1 V_75 ,
T_1 V_90 )
{
if ( ! F_50 ( V_75 , V_154 -> V_90 ) && ! F_50 ( V_154 -> V_141 , V_90 ) ) {
if ( F_43 ( V_75 , V_154 -> V_141 ) )
V_154 -> V_141 = V_75 ;
if ( F_50 ( V_90 , V_154 -> V_90 ) )
V_154 -> V_90 = V_90 ;
return true ;
}
return false ;
}
static void F_238 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_141 ( V_30 ) && V_449 ) {
int V_122 ;
if ( F_43 ( V_75 , V_30 -> V_88 ) )
V_122 = V_450 ;
else
V_122 = V_451 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
V_30 -> V_47 . V_452 = 1 ;
V_30 -> V_453 [ 0 ] . V_141 = V_75 ;
V_30 -> V_453 [ 0 ] . V_90 = V_90 ;
}
}
static void F_239 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_47 . V_452 )
F_238 ( V_2 , V_75 , V_90 ) ;
else
F_237 ( V_30 -> V_453 , V_75 , V_90 ) ;
}
static void F_240 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_454 ) ;
F_10 ( V_2 ) ;
if ( F_141 ( V_30 ) && V_449 ) {
T_1 V_90 = F_16 ( V_4 ) -> V_90 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) )
V_90 = V_30 -> V_88 ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , V_90 ) ;
}
}
F_201 ( V_2 ) ;
}
static void F_241 ( struct V_29 * V_30 )
{
int V_455 ;
struct V_198 * V_154 = & V_30 -> V_456 [ 0 ] ;
struct V_198 * V_457 = V_154 + 1 ;
for ( V_455 = 1 ; V_455 < V_30 -> V_47 . V_155 ; ) {
if ( F_237 ( V_154 , V_457 -> V_141 , V_457 -> V_90 ) ) {
int V_212 ;
V_30 -> V_47 . V_155 -- ;
for ( V_212 = V_455 ; V_212 < V_30 -> V_47 . V_155 ; V_212 ++ )
V_154 [ V_212 ] = V_154 [ V_212 + 1 ] ;
continue;
}
V_455 ++ , V_457 ++ ;
}
}
static void F_242 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_198 * V_154 = & V_30 -> V_456 [ 0 ] ;
int V_458 = V_30 -> V_47 . V_155 ;
int V_455 ;
if ( ! V_458 )
goto V_459;
for ( V_455 = 0 ; V_455 < V_458 ; V_455 ++ , V_154 ++ ) {
if ( F_237 ( V_154 , V_75 , V_90 ) ) {
for (; V_455 > 0 ; V_455 -- , V_154 -- )
F_114 ( * V_154 , * ( V_154 - 1 ) ) ;
if ( V_458 > 1 )
F_241 ( V_30 ) ;
return;
}
}
if ( V_455 >= V_208 ) {
V_455 -- ;
V_30 -> V_47 . V_155 -- ;
V_154 -- ;
}
for (; V_455 > 0 ; V_455 -- , V_154 -- )
* V_154 = * ( V_154 - 1 ) ;
V_459:
V_154 -> V_141 = V_75 ;
V_154 -> V_90 = V_90 ;
V_30 -> V_47 . V_155 ++ ;
}
static void F_243 ( struct V_29 * V_30 )
{
struct V_198 * V_154 = & V_30 -> V_456 [ 0 ] ;
int V_155 = V_30 -> V_47 . V_155 ;
int V_455 ;
if ( F_244 ( & V_30 -> V_443 ) ) {
V_30 -> V_47 . V_155 = 0 ;
return;
}
for ( V_455 = 0 ; V_455 < V_155 ; ) {
if ( ! F_43 ( V_30 -> V_88 , V_154 -> V_141 ) ) {
int V_212 ;
F_112 ( F_43 ( V_30 -> V_88 , V_154 -> V_90 ) ) ;
for ( V_212 = V_455 + 1 ; V_212 < V_155 ; V_212 ++ )
V_30 -> V_456 [ V_212 - 1 ] = V_30 -> V_456 [ V_212 ] ;
V_155 -- ;
continue;
}
V_455 ++ ;
V_154 ++ ;
}
V_30 -> V_47 . V_155 = V_155 ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_460 = V_30 -> V_88 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_246 ( & V_30 -> V_443 ) ) != NULL ) {
if ( F_50 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) )
break;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_460 ) ) {
T_3 V_452 = V_460 ;
if ( F_43 ( F_16 ( V_4 ) -> V_90 , V_460 ) )
V_460 = F_16 ( V_4 ) -> V_90 ;
F_239 ( V_2 , F_16 ( V_4 ) -> V_75 , V_452 ) ;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_211 ( V_2 , L_16 ) ;
F_247 ( V_4 , & V_30 -> V_443 ) ;
F_248 ( V_4 ) ;
continue;
}
F_211 ( V_2 , L_17 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_247 ( V_4 , & V_30 -> V_443 ) ;
F_249 ( & V_2 -> V_461 , V_4 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( F_6 ( V_4 ) -> V_462 )
F_230 ( V_2 ) ;
}
}
static int F_250 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_463 )
{
if ( F_38 ( & V_2 -> V_79 ) > V_2 -> V_67 ||
! F_251 ( V_2 , V_4 , V_463 ) ) {
if ( F_252 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_251 ( V_2 , V_4 , V_463 ) ) {
if ( ! F_253 ( V_2 ) )
return - 1 ;
if ( ! F_251 ( V_2 , V_4 , V_463 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_254 ( struct V_1 * V_2 ,
struct V_3 * V_464 ,
struct V_3 * V_465 ,
bool * V_466 )
{
int V_289 ;
* V_466 = false ;
if ( F_6 ( V_465 ) -> V_462 )
return false ;
if ( F_16 ( V_465 ) -> V_75 != F_16 ( V_464 ) -> V_90 )
return false ;
if ( ! F_255 ( V_464 , V_465 , V_466 , & V_289 ) )
return false ;
F_256 ( V_289 , & V_2 -> V_79 ) ;
F_257 ( V_2 , V_289 ) ;
F_66 ( F_67 ( V_2 ) , V_467 ) ;
F_16 ( V_464 ) -> V_90 = F_16 ( V_465 ) -> V_90 ;
F_16 ( V_464 ) -> V_149 = F_16 ( V_465 ) -> V_149 ;
return true ;
}
static void F_258 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_468 ;
T_1 V_75 , V_90 ;
F_15 ( V_30 , V_4 ) ;
if ( F_100 ( F_250 ( V_2 , V_4 , V_4 -> V_57 ) ) ) {
F_66 ( F_67 ( V_2 ) , V_469 ) ;
F_248 ( V_4 ) ;
return;
}
V_30 -> V_354 = 0 ;
F_47 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_470 ) ;
F_211 ( V_2 , L_18 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_468 = F_259 ( & V_30 -> V_443 ) ;
if ( ! V_468 ) {
if ( F_141 ( V_30 ) ) {
V_30 -> V_47 . V_155 = 1 ;
V_30 -> V_456 [ 0 ] . V_141 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_456 [ 0 ] . V_90 =
F_16 ( V_4 ) -> V_90 ;
}
F_260 ( & V_30 -> V_443 , V_4 ) ;
goto V_471;
}
V_75 = F_16 ( V_4 ) -> V_75 ;
V_90 = F_16 ( V_4 ) -> V_90 ;
if ( V_75 == F_16 ( V_468 ) -> V_90 ) {
bool V_466 ;
if ( ! F_254 ( V_2 , V_468 , V_4 , & V_466 ) ) {
F_261 ( & V_30 -> V_443 , V_468 , V_4 ) ;
} else {
F_26 ( V_2 , V_4 ) ;
F_262 ( V_4 , V_466 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_47 . V_155 ||
V_30 -> V_456 [ 0 ] . V_90 != V_75 )
goto V_472;
V_30 -> V_456 [ 0 ] . V_90 = V_90 ;
goto V_471;
}
while ( 1 ) {
if ( ! F_50 ( F_16 ( V_468 ) -> V_75 , V_75 ) )
break;
if ( F_263 ( & V_30 -> V_443 , V_468 ) ) {
V_468 = NULL ;
break;
}
V_468 = F_264 ( & V_30 -> V_443 , V_468 ) ;
}
if ( V_468 && F_43 ( V_75 , F_16 ( V_468 ) -> V_90 ) ) {
if ( ! F_50 ( V_90 , F_16 ( V_468 ) -> V_90 ) ) {
F_66 ( F_67 ( V_2 ) , V_473 ) ;
F_248 ( V_4 ) ;
V_4 = NULL ;
F_238 ( V_2 , V_75 , V_90 ) ;
goto V_472;
}
if ( F_50 ( V_75 , F_16 ( V_468 ) -> V_75 ) ) {
F_238 ( V_2 , V_75 ,
F_16 ( V_468 ) -> V_90 ) ;
} else {
if ( F_263 ( & V_30 -> V_443 ,
V_468 ) )
V_468 = NULL ;
else
V_468 = F_264 (
& V_30 -> V_443 ,
V_468 ) ;
}
}
if ( ! V_468 )
F_260 ( & V_30 -> V_443 , V_4 ) ;
else
F_261 ( & V_30 -> V_443 , V_468 , V_4 ) ;
while ( ! F_265 ( & V_30 -> V_443 , V_4 ) ) {
V_468 = F_266 ( & V_30 -> V_443 , V_4 ) ;
if ( ! F_50 ( V_90 , F_16 ( V_468 ) -> V_75 ) )
break;
if ( F_43 ( V_90 , F_16 ( V_468 ) -> V_90 ) ) {
F_239 ( V_2 , F_16 ( V_468 ) -> V_75 ,
V_90 ) ;
break;
}
F_247 ( V_468 , & V_30 -> V_443 ) ;
F_239 ( V_2 , F_16 ( V_468 ) -> V_75 ,
F_16 ( V_468 ) -> V_90 ) ;
F_66 ( F_67 ( V_2 ) , V_473 ) ;
F_248 ( V_468 ) ;
}
V_472:
if ( F_141 ( V_30 ) )
F_242 ( V_2 , V_75 , V_90 ) ;
V_471:
if ( V_4 ) {
F_26 ( V_2 , V_4 ) ;
F_267 ( V_4 , V_2 ) ;
}
}
static int T_9 F_268 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_474 ,
bool * V_466 )
{
int V_475 ;
struct V_3 * V_476 = F_259 ( & V_2 -> V_461 ) ;
F_269 ( V_4 , V_474 ) ;
V_475 = ( V_476 &&
F_254 ( V_2 , V_476 , V_4 , V_466 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( ! V_475 ) {
F_249 ( & V_2 -> V_461 , V_4 ) ;
F_267 ( V_4 , V_2 ) ;
}
return V_475 ;
}
int F_270 ( struct V_1 * V_2 , struct V_477 * V_262 , T_10 V_463 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_466 ;
if ( V_463 == 0 )
return 0 ;
V_4 = F_271 ( V_463 + sizeof( * V_41 ) , V_2 -> V_478 ) ;
if ( ! V_4 )
goto V_164;
if ( F_250 ( V_2 , V_4 , V_463 + sizeof( * V_41 ) ) )
goto V_479;
V_41 = (struct V_15 * ) F_272 ( V_4 , sizeof( * V_41 ) ) ;
F_273 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_274 ( F_272 ( V_4 , V_463 ) , V_262 -> V_480 , V_463 ) )
goto V_479;
F_16 ( V_4 ) -> V_75 = F_7 ( V_2 ) -> V_88 ;
F_16 ( V_4 ) -> V_90 = F_16 ( V_4 ) -> V_75 + V_463 ;
F_16 ( V_4 ) -> V_149 = F_7 ( V_2 ) -> V_103 - 1 ;
if ( F_268 ( V_2 , V_4 , sizeof( * V_41 ) , & V_466 ) ) {
F_189 ( V_466 ) ;
F_248 ( V_4 ) ;
}
return V_463 ;
V_479:
F_275 ( V_4 ) ;
V_164:
return - V_481 ;
}
static void F_276 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_475 = - 1 ;
bool V_466 = false ;
if ( F_16 ( V_4 ) -> V_75 == F_16 ( V_4 ) -> V_90 )
goto V_482;
F_277 ( V_4 ) ;
F_269 ( V_4 , V_41 -> V_387 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_47 . V_452 = 0 ;
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 ) {
if ( F_225 ( V_30 ) == 0 )
goto V_483;
if ( V_30 -> V_484 . V_485 == V_486 &&
V_30 -> V_76 == V_30 -> V_88 && V_30 -> V_484 . V_10 &&
F_278 ( V_2 ) && ! V_30 -> V_487 ) {
int V_488 = F_40 (unsigned int, skb->len,
tp->ucopy.len) ;
F_279 ( V_489 ) ;
F_280 () ;
if ( ! F_281 ( V_4 , 0 , V_30 -> V_484 . V_490 , V_488 ) ) {
V_30 -> V_484 . V_10 -= V_488 ;
V_30 -> V_76 += V_488 ;
V_475 = ( V_488 == V_4 -> V_10 ) ;
F_45 ( V_2 ) ;
}
F_282 () ;
}
if ( V_475 <= 0 ) {
V_491:
if ( V_475 < 0 &&
F_250 ( V_2 , V_4 , V_4 -> V_57 ) )
goto V_482;
V_475 = F_268 ( V_2 , V_4 , 0 , & V_466 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( V_4 -> V_10 )
F_46 ( V_2 , V_4 ) ;
if ( V_41 -> V_462 )
F_230 ( V_2 ) ;
if ( ! F_244 ( & V_30 -> V_443 ) ) {
F_245 ( V_2 ) ;
if ( F_244 ( & V_30 -> V_443 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_47 . V_155 )
F_243 ( V_30 ) ;
F_199 ( V_2 ) ;
if ( V_475 > 0 )
F_262 ( V_4 , V_466 ) ;
if ( ! F_228 ( V_2 , V_430 ) )
V_2 -> V_492 ( V_2 ) ;
return;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_454 ) ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_483:
F_10 ( V_2 ) ;
F_47 ( V_2 ) ;
V_482:
F_248 ( V_4 ) ;
return;
}
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 + F_225 ( V_30 ) ) )
goto V_483;
F_10 ( V_2 ) ;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_211 ( V_2 , L_19 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ;
if ( ! F_225 ( V_30 ) )
goto V_483;
goto V_491;
}
F_258 ( V_2 , V_4 ) ;
}
static struct V_3 * F_283 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_493 * V_494 )
{
struct V_3 * V_495 = NULL ;
if ( ! F_265 ( V_494 , V_4 ) )
V_495 = F_266 ( V_494 , V_4 ) ;
F_247 ( V_4 , V_494 ) ;
F_248 ( V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_496 ) ;
return V_495 ;
}
static void
F_284 ( struct V_1 * V_2 , struct V_493 * V_494 ,
struct V_3 * V_497 , struct V_3 * V_476 ,
T_1 V_498 , T_1 V_471 )
{
struct V_3 * V_4 , * V_499 ;
bool V_500 ;
V_4 = V_497 ;
V_501:
V_500 = true ;
F_285 (list, skb, n) {
if ( V_4 == V_476 )
break;
if ( ! F_43 ( V_498 , F_16 ( V_4 ) -> V_90 ) ) {
V_4 = F_283 ( V_2 , V_4 , V_494 ) ;
if ( ! V_4 )
break;
goto V_501;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_462 &&
( F_25 ( V_4 -> V_57 ) > V_4 -> V_10 ||
F_43 ( F_16 ( V_4 ) -> V_75 , V_498 ) ) ) {
V_500 = false ;
break;
}
if ( ! F_265 ( V_494 , V_4 ) ) {
struct V_3 * V_495 = F_266 ( V_494 , V_4 ) ;
if ( V_495 != V_476 &&
F_16 ( V_4 ) -> V_90 != F_16 ( V_495 ) -> V_75 ) {
V_500 = false ;
break;
}
}
V_498 = F_16 ( V_4 ) -> V_90 ;
}
if ( V_500 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_462 )
return;
while ( F_43 ( V_498 , V_471 ) ) {
struct V_3 * V_502 ;
unsigned int V_503 = F_286 ( V_4 ) ;
int V_504 = F_287 ( V_503 , 0 ) ;
if ( V_504 < 0 )
return;
if ( V_471 - V_498 < V_504 )
V_504 = V_471 - V_498 ;
V_502 = F_271 ( V_504 + V_503 , V_505 ) ;
if ( ! V_502 )
return;
F_288 ( V_502 , F_289 ( V_4 ) - V_4 -> V_497 ) ;
F_290 ( V_502 , ( F_291 ( V_4 ) -
V_4 -> V_497 ) ) ;
F_292 ( V_502 , ( F_4 ( V_4 ) -
V_4 -> V_497 ) ) ;
F_293 ( V_502 , V_503 ) ;
memcpy ( V_502 -> V_497 , V_4 -> V_497 , V_503 ) ;
memcpy ( V_502 -> V_506 , V_4 -> V_506 , sizeof( V_4 -> V_506 ) ) ;
F_16 ( V_502 ) -> V_75 = F_16 ( V_502 ) -> V_90 = V_498 ;
F_294 ( V_494 , V_4 , V_502 ) ;
F_267 ( V_502 , V_2 ) ;
while ( V_504 > 0 ) {
int V_507 = V_498 - F_16 ( V_4 ) -> V_75 ;
int V_463 = F_16 ( V_4 ) -> V_90 - V_498 ;
F_89 ( V_507 < 0 ) ;
if ( V_463 > 0 ) {
V_463 = F_9 ( V_504 , V_463 ) ;
if ( F_295 ( V_4 , V_507 , F_272 ( V_502 , V_463 ) , V_463 ) )
F_296 () ;
F_16 ( V_502 ) -> V_90 += V_463 ;
V_504 -= V_463 ;
V_498 += V_463 ;
}
if ( ! F_43 ( V_498 , F_16 ( V_4 ) -> V_90 ) ) {
V_4 = F_283 ( V_2 , V_4 , V_494 ) ;
if ( ! V_4 ||
V_4 == V_476 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_462 )
return;
}
}
}
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_246 ( & V_30 -> V_443 ) ;
struct V_3 * V_497 ;
T_1 V_498 , V_471 ;
if ( V_4 == NULL )
return;
V_498 = F_16 ( V_4 ) -> V_75 ;
V_471 = F_16 ( V_4 ) -> V_90 ;
V_497 = V_4 ;
for (; ; ) {
struct V_3 * V_495 = NULL ;
if ( ! F_265 ( & V_30 -> V_443 , V_4 ) )
V_495 = F_266 ( & V_30 -> V_443 , V_4 ) ;
V_4 = V_495 ;
if ( ! V_4 ||
F_50 ( F_16 ( V_4 ) -> V_75 , V_471 ) ||
F_43 ( F_16 ( V_4 ) -> V_90 , V_498 ) ) {
F_284 ( V_2 , & V_30 -> V_443 ,
V_497 , V_4 , V_498 , V_471 ) ;
V_497 = V_4 ;
if ( ! V_4 )
break;
V_498 = F_16 ( V_4 ) -> V_75 ;
V_471 = F_16 ( V_4 ) -> V_90 ;
} else {
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_498 ) )
V_498 = F_16 ( V_4 ) -> V_75 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_471 ) )
V_471 = F_16 ( V_4 ) -> V_90 ;
}
}
}
static bool F_253 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_508 = false ;
if ( ! F_244 ( & V_30 -> V_443 ) ) {
F_66 ( F_67 ( V_2 ) , V_509 ) ;
F_235 ( & V_30 -> V_443 ) ;
if ( V_30 -> V_47 . V_117 )
F_215 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
V_508 = true ;
}
return V_508 ;
}
static int F_252 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_211 ( V_2 , L_20 , V_30 -> V_76 ) ;
F_66 ( F_67 ( V_2 ) , V_510 ) ;
if ( F_38 ( & V_2 -> V_79 ) >= V_2 -> V_67 )
F_35 ( V_2 ) ;
else if ( F_28 ( V_2 ) )
V_30 -> V_60 = F_9 ( V_30 -> V_60 , 4U * V_30 -> V_63 ) ;
F_297 ( V_2 ) ;
if ( ! F_244 ( & V_2 -> V_461 ) )
F_284 ( V_2 , & V_2 -> V_461 ,
F_246 ( & V_2 -> V_461 ) ,
NULL ,
V_30 -> V_76 , V_30 -> V_88 ) ;
F_48 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_253 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_66 ( F_67 ( V_2 ) , V_511 ) ;
V_30 -> V_354 = 0 ;
return - 1 ;
}
void F_298 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_129 == V_278 &&
V_2 -> V_512 && ! F_299 ( V_513 , & V_2 -> V_512 -> V_514 ) ) {
T_1 V_515 = F_59 ( V_30 , F_208 ( V_2 ) ) ;
T_1 V_516 = F_34 ( V_30 -> V_517 , V_515 ) ;
if ( V_516 < V_30 -> V_53 ) {
V_30 -> V_230 = F_125 ( V_2 ) ;
V_30 -> V_53 = ( V_30 -> V_53 + V_516 ) >> 1 ;
}
V_30 -> V_517 = 0 ;
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
if ( V_30 -> V_108 >= V_30 -> V_53 )
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
V_2 -> V_518 ( V_2 ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
if ( F_228 ( V_2 , V_519 ) ) {
F_303 ( V_2 , V_519 ) ;
if ( V_2 -> V_512 &&
F_299 ( V_513 , & V_2 -> V_512 -> V_514 ) )
F_301 ( V_2 ) ;
}
}
static inline void F_304 ( struct V_1 * V_2 )
{
F_305 ( V_2 ) ;
F_302 ( V_2 ) ;
}
static void F_306 ( struct V_1 * V_2 , int V_520 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_88 - V_30 -> V_363 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_307 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_520 && F_246 ( & V_30 -> V_443 ) ) ) {
F_201 ( V_2 ) ;
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
T_1 V_206 = F_149 ( V_41 -> V_521 ) ;
if ( V_206 && ! V_522 )
V_206 -- ;
V_206 += F_219 ( V_41 -> V_75 ) ;
if ( F_50 ( V_30 -> V_76 , V_206 ) )
return;
if ( F_43 ( V_206 , V_30 -> V_88 ) )
return;
if ( V_30 -> V_487 && ! F_50 ( V_206 , V_30 -> V_523 ) )
return;
F_312 ( V_2 ) ;
if ( V_30 -> V_523 == V_30 -> V_76 && V_30 -> V_487 &&
! F_228 ( V_2 , V_524 ) && V_30 -> V_76 != V_30 -> V_88 ) {
struct V_3 * V_4 = F_246 ( & V_2 -> V_461 ) ;
V_30 -> V_76 ++ ;
if ( V_4 && ! F_43 ( V_30 -> V_76 , F_16 ( V_4 ) -> V_90 ) ) {
F_247 ( V_4 , & V_2 -> V_461 ) ;
F_248 ( V_4 ) ;
}
}
V_30 -> V_487 = V_525 ;
V_30 -> V_523 = V_206 ;
V_30 -> V_354 = 0 ;
}
static void F_313 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_526 )
F_311 ( V_2 , V_41 ) ;
if ( V_30 -> V_487 == V_525 ) {
T_1 V_206 = V_30 -> V_523 - F_219 ( V_41 -> V_75 ) + ( V_41 -> V_387 * 4 ) -
V_41 -> V_43 ;
if ( V_206 < V_4 -> V_10 ) {
T_4 V_201 ;
if ( F_295 ( V_4 , V_206 , & V_201 , 1 ) )
F_296 () ;
V_30 -> V_487 = V_527 | V_201 ;
if ( ! F_228 ( V_2 , V_430 ) )
V_2 -> V_492 ( V_2 ) ;
}
}
}
static int F_314 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_528 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_488 = V_4 -> V_10 - V_528 ;
int V_164 ;
F_280 () ;
if ( F_315 ( V_4 ) )
V_164 = F_281 ( V_4 , V_528 , V_30 -> V_484 . V_490 , V_488 ) ;
else
V_164 = F_316 ( V_4 , V_528 ,
V_30 -> V_484 . V_490 ) ;
if ( ! V_164 ) {
V_30 -> V_484 . V_10 -= V_488 ;
V_30 -> V_76 += V_488 ;
F_45 ( V_2 ) ;
}
F_282 () ;
return V_164 ;
}
static T_11 F_317 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_529 ;
if ( F_278 ( V_2 ) ) {
F_280 () ;
V_529 = F_318 ( V_4 ) ;
F_282 () ;
} else {
V_529 = F_318 ( V_4 ) ;
}
return V_529 ;
}
static inline bool F_319 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_315 ( V_4 ) &&
F_317 ( V_2 , V_4 ) ;
}
static bool F_320 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_528 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_488 = V_4 -> V_10 - V_528 ;
int V_530 ;
bool V_531 = false ;
if ( V_30 -> V_484 . V_532 )
return false ;
if ( ! V_30 -> V_484 . V_533 && V_30 -> V_484 . V_534 )
V_30 -> V_484 . V_533 = F_321 () ;
if ( V_30 -> V_484 . V_533 && F_315 ( V_4 ) ) {
V_530 = F_322 ( V_30 -> V_484 . V_533 ,
V_4 , V_528 ,
V_30 -> V_484 . V_490 , V_488 ,
V_30 -> V_484 . V_534 ) ;
if ( V_530 < 0 )
goto V_196;
V_30 -> V_484 . V_530 = V_530 ;
V_531 = true ;
V_30 -> V_484 . V_10 -= V_488 ;
V_30 -> V_76 += V_488 ;
F_45 ( V_2 ) ;
if ( ( V_30 -> V_484 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_535 ) ||
( F_38 ( & V_2 -> V_79 ) > ( V_2 -> V_67 >> 1 ) ) ) {
V_30 -> V_484 . V_532 = 1 ;
V_2 -> V_492 ( V_2 ) ;
}
} else if ( V_488 > 0 ) {
V_30 -> V_484 . V_532 = 1 ;
V_2 -> V_492 ( V_2 ) ;
}
V_196:
return V_531 ;
}
static bool F_323 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_536 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_220 ( V_4 , V_41 , V_30 ) && V_30 -> V_47 . V_261 &&
F_223 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_537 ) {
F_66 ( F_67 ( V_2 ) , V_538 ) ;
F_240 ( V_2 , V_4 ) ;
goto V_539;
}
}
if ( ! F_224 ( V_30 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ) {
if ( ! V_41 -> V_537 ) {
if ( V_41 -> V_43 )
goto V_540;
F_240 ( V_2 , V_4 ) ;
}
goto V_539;
}
if ( V_41 -> V_537 ) {
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 )
F_226 ( V_2 ) ;
else
F_200 ( V_2 ) ;
goto V_539;
}
if ( V_41 -> V_43 ) {
V_540:
if ( V_536 )
F_324 ( F_67 ( V_2 ) , V_541 ) ;
F_66 ( F_67 ( V_2 ) , V_542 ) ;
F_200 ( V_2 ) ;
goto V_539;
}
return true ;
V_539:
F_248 ( V_4 ) ;
return false ;
}
void F_325 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_100 ( V_2 -> V_543 == NULL ) )
F_2 ( V_2 ) -> V_544 -> V_545 ( V_2 , V_4 ) ;
V_30 -> V_47 . V_261 = 0 ;
if ( ( F_5 ( V_41 ) & V_546 ) == V_30 -> V_354 &&
F_16 ( V_4 ) -> V_75 == V_30 -> V_88 &&
! F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_105 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_419 ) {
if ( ! F_217 ( V_30 , V_41 ) )
goto V_547;
if ( ( T_5 ) ( V_30 -> V_47 . V_361 - V_30 -> V_47 . V_360 ) < 0 )
goto V_547;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_419 ) &&
V_30 -> V_88 == V_30 -> V_363 )
F_202 ( V_30 ) ;
F_207 ( V_2 , V_4 , 0 ) ;
F_248 ( V_4 ) ;
F_304 ( V_2 ) ;
return;
} else {
F_324 ( F_67 ( V_2 ) , V_541 ) ;
goto V_539;
}
} else {
int V_475 = 0 ;
int V_531 = 0 ;
bool V_466 = false ;
if ( V_30 -> V_76 == V_30 -> V_88 &&
V_10 - V_18 <= V_30 -> V_484 . V_10 ) {
#ifdef F_326
if ( V_30 -> V_484 . V_485 == V_486 &&
F_278 ( V_2 ) &&
F_320 ( V_2 , V_4 , V_18 ) ) {
V_531 = 1 ;
V_475 = 1 ;
}
#endif
if ( V_30 -> V_484 . V_485 == V_486 &&
F_278 ( V_2 ) && ! V_531 ) {
F_279 ( V_489 ) ;
if ( ! F_314 ( V_2 , V_4 , V_18 ) )
V_475 = 1 ;
}
if ( V_475 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_419 ) &&
V_30 -> V_88 == V_30 -> V_363 )
F_202 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_269 ( V_4 , V_18 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
F_66 ( F_67 ( V_2 ) , V_548 ) ;
}
if ( V_531 )
F_327 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_475 ) {
if ( F_319 ( V_2 , V_4 ) )
goto V_549;
if ( ( int ) V_4 -> V_57 > V_2 -> V_550 )
goto V_551;
if ( V_18 ==
( sizeof( struct V_15 ) + V_419 ) &&
V_30 -> V_88 == V_30 -> V_363 )
F_202 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_552 ) ;
V_475 = F_268 ( V_2 , V_4 , V_18 ,
& V_466 ) ;
}
F_46 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_149 != V_30 -> V_103 ) {
F_207 ( V_2 , V_4 , V_374 ) ;
F_304 ( V_2 ) ;
if ( ! F_310 ( V_2 ) )
goto V_553;
}
if ( ! V_531 || V_30 -> V_88 != V_30 -> V_363 )
F_306 ( V_2 , 0 ) ;
V_553:
#ifdef F_326
if ( V_531 )
F_249 ( & V_2 -> V_554 , V_4 ) ;
else
#endif
if ( V_475 )
F_262 ( V_4 , V_466 ) ;
V_2 -> V_492 ( V_2 ) ;
return;
}
}
V_547:
if ( V_10 < ( V_41 -> V_387 << 2 ) || F_319 ( V_2 , V_4 ) )
goto V_549;
if ( ! V_41 -> V_318 && ! V_41 -> V_537 )
goto V_539;
if ( ! F_323 ( V_2 , V_4 , V_41 , 1 ) )
return;
V_551:
if ( F_207 ( V_2 , V_4 , V_371 | V_370 ) < 0 )
goto V_539;
F_44 ( V_2 , V_4 ) ;
F_313 ( V_2 , V_4 , V_41 ) ;
F_276 ( V_2 , V_4 ) ;
F_304 ( V_2 ) ;
F_309 ( V_2 ) ;
return;
V_549:
F_324 ( F_67 ( V_2 ) , V_555 ) ;
F_324 ( F_67 ( V_2 ) , V_541 ) ;
V_539:
F_248 ( V_4 ) ;
}
void F_328 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_232 ( V_2 , V_436 ) ;
if ( V_4 != NULL ) {
V_6 -> V_544 -> V_545 ( V_2 , V_4 ) ;
F_329 ( V_2 , V_4 ) ;
}
V_6 -> V_544 -> V_556 ( V_2 ) ;
F_330 ( V_2 ) ;
F_331 ( V_2 ) ;
V_30 -> V_557 = V_74 ;
F_32 ( V_2 ) ;
if ( F_228 ( V_2 , V_558 ) )
F_332 ( V_2 , F_333 ( V_30 ) ) ;
if ( ! V_30 -> V_47 . V_352 )
F_334 ( V_30 , V_30 -> V_351 ) ;
else
V_30 -> V_354 = 0 ;
if ( ! F_228 ( V_2 , V_430 ) ) {
V_2 -> V_444 ( V_2 ) ;
F_236 ( V_2 , V_559 , V_560 ) ;
}
}
static bool F_335 ( struct V_1 * V_2 , struct V_3 * V_561 ,
struct V_384 * V_562 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_563 ? F_101 ( V_2 ) : NULL ;
T_6 V_64 = V_30 -> V_47 . V_48 ;
bool V_564 ;
if ( V_64 == V_30 -> V_47 . V_395 ) {
struct V_381 V_565 ;
F_336 ( & V_565 ) ;
V_565 . V_395 = V_565 . V_48 = 0 ;
F_212 ( V_561 , & V_565 , 0 , NULL ) ;
V_64 = V_565 . V_48 ;
}
if ( ! V_30 -> V_566 )
V_562 -> V_10 = - 1 ;
V_564 = ( V_562 -> V_10 <= 0 && V_13 && V_30 -> V_316 ) ;
F_337 ( V_2 , V_64 , V_562 , V_564 ) ;
if ( V_13 ) {
F_106 (data, sk) {
if ( V_13 == F_78 ( V_2 ) ||
F_338 ( V_2 , V_13 ) )
break;
}
F_183 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_567 ) ;
return true ;
}
V_30 -> V_568 = V_30 -> V_563 ;
if ( V_30 -> V_568 )
F_66 ( F_67 ( V_2 ) , V_569 ) ;
return false ;
}
static int F_339 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_384 V_385 = { . V_10 = - 1 } ;
int V_570 = V_30 -> V_47 . V_48 ;
F_212 ( V_4 , & V_30 -> V_47 , 0 , & V_385 ) ;
if ( V_30 -> V_47 . V_261 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_418 ;
if ( V_41 -> V_318 ) {
if ( ! F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_103 ) ||
F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_105 ) )
goto V_571;
if ( V_30 -> V_47 . V_261 && V_30 -> V_47 . V_89 &&
! F_190 ( V_30 -> V_47 . V_89 , V_30 -> V_260 ,
V_74 ) ) {
F_66 ( F_67 ( V_2 ) , V_572 ) ;
goto V_571;
}
if ( V_41 -> V_537 ) {
F_226 ( V_2 ) ;
goto V_539;
}
if ( ! V_41 -> V_43 )
goto V_573;
F_17 ( V_30 , V_41 ) ;
F_340 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_207 ( V_2 , V_4 , V_371 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_363 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_351 = F_149 ( V_41 -> V_58 ) ;
if ( ! V_30 -> V_47 . V_399 ) {
V_30 -> V_47 . V_352 = V_30 -> V_47 . V_574 = 0 ;
V_30 -> V_61 = F_9 ( V_30 -> V_61 , 65535U ) ;
}
if ( V_30 -> V_47 . V_261 ) {
V_30 -> V_47 . V_403 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_419 ;
V_30 -> V_63 -= V_419 ;
F_202 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_141 ( V_30 ) && V_575 )
F_341 ( V_30 ) ;
F_342 ( V_2 ) ;
F_169 ( V_2 , V_6 -> V_297 ) ;
F_39 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_343 () ;
F_328 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_566 || V_30 -> V_563 ) &&
F_335 ( V_2 , V_4 , & V_385 ) )
return - 1 ;
if ( V_2 -> V_576 ||
V_6 -> V_577 . V_578 ||
V_6 -> V_8 . V_26 ) {
F_47 ( V_2 ) ;
V_6 -> V_8 . V_95 = V_74 ;
F_10 ( V_2 ) ;
F_131 ( V_2 , V_579 ,
V_580 , V_243 ) ;
V_539:
F_248 ( V_4 ) ;
return 0 ;
} else {
F_201 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_537 ) {
goto V_573;
}
if ( V_30 -> V_47 . V_362 && V_30 -> V_47 . V_261 &&
F_344 ( & V_30 -> V_47 , 0 ) )
goto V_573;
if ( V_41 -> V_43 ) {
F_232 ( V_2 , V_435 ) ;
if ( V_30 -> V_47 . V_261 ) {
V_30 -> V_47 . V_403 = 1 ;
F_202 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_419 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_363 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_351 = F_149 ( V_41 -> V_58 ) ;
V_30 -> V_350 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_142 = V_30 -> V_351 ;
F_18 ( V_30 , V_41 ) ;
F_342 ( V_2 ) ;
F_169 ( V_2 , V_6 -> V_297 ) ;
F_39 ( V_2 ) ;
F_345 ( V_2 ) ;
#if 0
return -1;
#else
goto V_539;
#endif
}
V_573:
F_336 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_570 ;
goto V_539;
V_571:
F_336 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_570 ;
return 1 ;
}
int F_346 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_581 * V_582 ;
int V_583 = 0 ;
bool V_584 ;
T_1 V_315 ;
V_30 -> V_47 . V_261 = 0 ;
switch ( V_2 -> V_422 ) {
case V_428 :
goto V_539;
case V_585 :
if ( V_41 -> V_318 )
return 1 ;
if ( V_41 -> V_537 )
goto V_539;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_462 )
goto V_539;
if ( V_6 -> V_544 -> V_586 ( V_2 , V_4 ) < 0 )
return 1 ;
F_275 ( V_4 ) ;
return 0 ;
}
goto V_539;
case V_423 :
V_583 = F_339 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_583 >= 0 )
return V_583 ;
F_313 ( V_2 , V_4 , V_41 ) ;
F_248 ( V_4 ) ;
F_304 ( V_2 ) ;
return 0 ;
}
V_582 = V_30 -> V_321 ;
if ( V_582 != NULL ) {
F_189 ( V_2 -> V_422 != V_435 &&
V_2 -> V_422 != V_440 ) ;
if ( F_347 ( V_2 , V_4 , V_582 , NULL , true ) == NULL )
goto V_539;
}
if ( ! V_41 -> V_318 && ! V_41 -> V_537 )
goto V_539;
if ( ! F_323 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
V_584 = F_207 ( V_2 , V_4 , V_371 |
V_370 ) > 0 ;
switch ( V_2 -> V_422 ) {
case V_435 :
if ( ! V_584 )
return 1 ;
if ( V_582 ) {
V_315 = F_348 ( V_582 ) -> V_587 ;
V_30 -> V_316 = V_582 -> V_588 ;
F_349 ( V_2 , V_582 , false ) ;
} else {
V_315 = V_30 -> V_557 ;
V_6 -> V_544 -> V_556 ( V_2 ) ;
F_331 ( V_2 ) ;
F_342 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_32 ( V_2 ) ;
}
F_343 () ;
F_232 ( V_2 , V_436 ) ;
V_2 -> V_444 ( V_2 ) ;
if ( V_2 -> V_512 )
F_236 ( V_2 , V_559 , V_560 ) ;
V_30 -> V_103 = F_16 ( V_4 ) -> V_149 ;
V_30 -> V_351 = F_149 ( V_41 -> V_58 ) << V_30 -> V_47 . V_352 ;
F_340 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_181 ( V_2 , V_315 ) ;
if ( V_30 -> V_47 . V_403 )
V_30 -> V_63 -= V_419 ;
if ( V_582 ) {
F_183 ( V_2 ) ;
} else
F_330 ( V_2 ) ;
F_52 ( V_2 ) ;
V_30 -> V_557 = V_74 ;
F_39 ( V_2 ) ;
F_350 ( V_30 ) ;
break;
case V_440 : {
struct V_111 * V_112 ;
int V_589 ;
if ( V_582 != NULL ) {
if ( ! V_584 )
return 1 ;
F_349 ( V_2 , V_582 , false ) ;
F_183 ( V_2 ) ;
}
if ( V_30 -> V_103 != V_30 -> V_590 )
break;
F_232 ( V_2 , V_441 ) ;
V_2 -> V_432 |= V_591 ;
V_112 = F_208 ( V_2 ) ;
if ( V_112 )
F_209 ( V_112 ) ;
if ( ! F_228 ( V_2 , V_430 ) ) {
V_2 -> V_444 ( V_2 ) ;
break;
}
if ( V_30 -> V_592 < 0 ||
( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_50 ( F_16 ( V_4 ) -> V_90 - V_41 -> V_462 , V_30 -> V_88 ) ) ) {
F_229 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_593 ) ;
return 1 ;
}
V_589 = F_351 ( V_2 ) ;
if ( V_589 > V_594 ) {
F_332 ( V_2 , V_589 - V_594 ) ;
} else if ( V_41 -> V_462 || F_278 ( V_2 ) ) {
F_332 ( V_2 , V_589 ) ;
} else {
F_233 ( V_2 , V_441 , V_589 ) ;
goto V_539;
}
break;
}
case V_438 :
if ( V_30 -> V_103 == V_30 -> V_590 ) {
F_233 ( V_2 , V_442 , 0 ) ;
goto V_539;
}
break;
case V_439 :
if ( V_30 -> V_103 == V_30 -> V_590 ) {
F_352 ( V_2 ) ;
F_229 ( V_2 ) ;
goto V_539;
}
break;
}
F_313 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_422 ) {
case V_426 :
case V_438 :
case V_439 :
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) )
break;
case V_440 :
case V_441 :
if ( V_2 -> V_432 & V_433 ) {
if ( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_50 ( F_16 ( V_4 ) -> V_90 - V_41 -> V_462 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_593 ) ;
F_226 ( V_2 ) ;
return 1 ;
}
}
case V_436 :
F_276 ( V_2 , V_4 ) ;
V_583 = 1 ;
break;
}
if ( V_2 -> V_422 != V_428 ) {
F_304 ( V_2 ) ;
F_309 ( V_2 ) ;
}
if ( ! V_583 ) {
V_539:
F_248 ( V_4 ) ;
}
return 0 ;
}
