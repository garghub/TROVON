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
if ( V_159 && V_30 -> V_132 && V_30 -> V_133 > 0 &&
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
if ( V_168 >= V_4 -> V_10 )
return 0 ;
}
V_166 = V_168 ;
}
V_164 = F_83 ( V_2 , V_4 , V_166 , V_64 , V_169 ) ;
if ( V_164 < 0 )
return V_164 ;
}
return V_165 ;
}
static T_4 F_84 ( struct V_1 * V_2 ,
struct V_170 * V_171 , T_4 V_137 ,
T_1 V_141 , T_1 V_90 ,
int V_159 , int V_172 ,
const struct V_173 * V_174 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_175 = V_171 -> V_175 ;
if ( V_159 && ( V_137 & V_176 ) ) {
if ( V_30 -> V_132 && V_30 -> V_133 > 0 &&
F_50 ( V_90 , V_30 -> V_132 ) )
V_30 -> V_133 -- ;
if ( V_137 & V_139 )
V_171 -> V_177 = F_9 ( V_175 , V_171 -> V_177 ) ;
}
if ( ! F_50 ( V_90 , V_30 -> V_103 ) )
return V_137 ;
if ( ! ( V_137 & V_139 ) ) {
if ( V_137 & V_150 ) {
if ( V_137 & V_138 ) {
V_137 &= ~ ( V_138 | V_150 ) ;
V_30 -> V_135 -= V_172 ;
V_30 -> V_146 -= V_172 ;
}
} else {
if ( ! ( V_137 & V_176 ) ) {
if ( F_43 ( V_141 ,
F_76 ( V_30 ) ) )
V_171 -> V_177 = F_9 ( V_175 ,
V_171 -> V_177 ) ;
if ( ! F_50 ( V_90 , V_30 -> V_178 ) )
V_171 -> V_179 |= V_180 ;
if ( V_171 -> V_181 < 0 ) {
struct V_173 V_94 ;
F_85 ( & V_94 ) ;
V_171 -> V_181 = F_86 ( & V_94 ,
V_174 ) ;
}
}
if ( V_137 & V_138 ) {
V_137 &= ~ V_138 ;
V_30 -> V_135 -= V_172 ;
}
}
V_137 |= V_139 ;
V_171 -> V_179 |= V_182 ;
V_30 -> V_131 += V_172 ;
V_175 += V_172 ;
if ( ! F_62 ( V_30 ) && ( V_30 -> V_116 != NULL ) &&
F_43 ( V_141 , F_16 ( V_30 -> V_116 ) -> V_75 ) )
V_30 -> V_183 += V_172 ;
if ( V_175 > V_30 -> V_130 )
V_30 -> V_130 = V_175 ;
}
if ( V_159 && ( V_137 & V_150 ) ) {
V_137 &= ~ V_150 ;
V_30 -> V_146 -= V_172 ;
}
return V_137 ;
}
static bool F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_170 * V_171 ,
unsigned int V_172 , int V_184 , int V_64 ,
bool V_159 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_185 = F_88 ( V_2 , V_4 ) ;
T_1 V_141 = F_16 ( V_4 ) -> V_75 ;
T_1 V_90 = V_141 + V_184 ;
F_89 ( ! V_172 ) ;
F_84 ( V_2 , V_171 , F_16 ( V_4 ) -> V_137 ,
V_141 , V_90 , V_159 , V_172 ,
& V_4 -> V_173 ) ;
if ( V_4 == V_30 -> V_116 )
V_30 -> V_183 += V_172 ;
F_16 ( V_185 ) -> V_90 += V_184 ;
F_16 ( V_4 ) -> V_75 += V_184 ;
F_3 ( V_185 ) -> V_186 += V_172 ;
F_89 ( F_3 ( V_4 ) -> V_186 < V_172 ) ;
F_3 ( V_4 ) -> V_186 -= V_172 ;
if ( ! F_3 ( V_185 ) -> V_11 ) {
F_3 ( V_185 ) -> V_11 = V_64 ;
F_3 ( V_185 ) -> V_187 = V_2 -> V_188 ;
}
if ( F_3 ( V_4 ) -> V_186 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_187 = 0 ;
}
F_16 ( V_185 ) -> V_137 |= ( F_16 ( V_4 ) -> V_137 & V_189 ) ;
if ( V_4 -> V_10 > 0 ) {
F_89 ( ! F_72 ( V_4 ) ) ;
F_66 ( F_67 ( V_2 ) , V_190 ) ;
return false ;
}
if ( V_4 == V_30 -> V_134 )
V_30 -> V_134 = V_185 ;
if ( V_4 == V_30 -> V_116 ) {
V_30 -> V_116 = V_185 ;
V_30 -> V_183 -= F_72 ( V_185 ) ;
}
F_16 ( V_185 ) -> V_191 |= F_16 ( V_4 ) -> V_191 ;
if ( F_16 ( V_4 ) -> V_191 & V_192 )
F_16 ( V_185 ) -> V_90 ++ ;
if ( V_4 == F_90 ( V_2 ) )
F_91 ( V_2 , V_4 ) ;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_193 ) ;
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
struct V_170 * V_171 ,
T_1 V_141 , T_1 V_90 ,
bool V_159 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_185 ;
int V_64 ;
int V_172 = 0 ;
int V_10 ;
int V_165 ;
if ( ! F_99 ( V_2 ) )
goto V_194;
if ( ! V_159 &&
( F_16 ( V_4 ) -> V_137 & ( V_138 | V_150 ) ) == V_150 )
goto V_194;
if ( ! F_95 ( V_4 ) )
goto V_194;
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_103 ) )
goto V_194;
if ( F_100 ( V_4 == F_101 ( V_2 ) ) )
goto V_194;
V_185 = F_88 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_185 ) -> V_137 & V_195 ) != V_139 )
goto V_194;
V_165 = ! F_50 ( V_141 , F_16 ( V_4 ) -> V_75 ) &&
! F_43 ( V_90 , F_16 ( V_4 ) -> V_90 ) ;
if ( V_165 ) {
V_10 = V_4 -> V_10 ;
V_172 = F_72 ( V_4 ) ;
V_64 = F_94 ( V_4 ) ;
if ( V_64 != F_94 ( V_185 ) )
goto V_194;
} else {
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_141 ) )
goto V_196;
if ( F_72 ( V_4 ) <= 1 )
goto V_196;
V_165 = ! F_50 ( V_141 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! V_165 ) {
goto V_194;
}
V_10 = V_90 - F_16 ( V_4 ) -> V_75 ;
F_89 ( V_10 < 0 ) ;
F_89 ( V_10 > V_4 -> V_10 ) ;
V_64 = F_82 ( V_4 ) ;
if ( V_64 != F_94 ( V_185 ) )
goto V_194;
if ( V_10 == V_64 ) {
V_172 = 1 ;
} else if ( V_10 < V_64 ) {
goto V_196;
} else {
V_172 = V_10 / V_64 ;
V_10 = V_172 * V_64 ;
}
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_75 + V_10 , V_30 -> V_103 ) )
goto V_194;
if ( ! F_102 ( V_185 , V_4 , V_10 ) )
goto V_194;
if ( ! F_87 ( V_2 , V_4 , V_171 , V_172 , V_10 , V_64 , V_159 ) )
goto V_197;
if ( V_185 == F_103 ( V_2 ) )
goto V_197;
V_4 = F_104 ( V_2 , V_185 ) ;
if ( ! F_95 ( V_4 ) ||
( V_4 == F_78 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_137 & V_195 ) != V_139 ) ||
( V_64 != F_94 ( V_4 ) ) )
goto V_197;
V_10 = V_4 -> V_10 ;
if ( F_102 ( V_185 , V_4 , V_10 ) ) {
V_172 += F_72 ( V_4 ) ;
F_87 ( V_2 , V_4 , V_171 , F_72 ( V_4 ) , V_10 , V_64 , 0 ) ;
}
V_197:
V_171 -> V_175 += V_172 ;
return V_185 ;
V_196:
return V_4 ;
V_194:
F_66 ( F_67 ( V_2 ) , V_198 ) ;
return NULL ;
}
static struct V_3 * F_105 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_199 * V_200 ,
struct V_170 * V_171 ,
T_1 V_141 , T_1 V_90 ,
bool V_201 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_202 ;
F_106 (skb, sk) {
int V_165 = 0 ;
bool V_159 = V_201 ;
if ( V_4 == F_78 ( V_2 ) )
break;
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_90 ) )
break;
if ( ( V_200 != NULL ) &&
F_43 ( F_16 ( V_4 ) -> V_75 , V_200 -> V_90 ) ) {
V_165 = F_81 ( V_2 , V_4 ,
V_200 -> V_141 ,
V_200 -> V_90 ) ;
if ( V_165 > 0 )
V_159 = true ;
}
if ( V_165 <= 0 ) {
V_202 = F_98 ( V_2 , V_4 , V_171 ,
V_141 , V_90 , V_159 ) ;
if ( V_202 != NULL ) {
if ( V_202 != V_4 ) {
V_4 = V_202 ;
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
V_171 ,
F_16 ( V_4 ) -> V_137 ,
F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ,
V_159 ,
F_72 ( V_4 ) ,
& V_4 -> V_173 ) ;
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 ,
F_76 ( V_30 ) ) )
F_91 ( V_2 , V_4 ) ;
}
V_171 -> V_175 += F_72 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_170 * V_171 ,
T_1 V_203 )
{
F_106 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_203 ) )
break;
V_171 -> V_175 += F_72 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_108 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_199 * V_200 ,
struct V_170 * V_171 ,
T_1 V_203 )
{
if ( V_200 == NULL )
return V_4 ;
if ( F_43 ( V_200 -> V_141 , V_203 ) ) {
V_4 = F_107 ( V_4 , V_2 , V_171 , V_200 -> V_141 ) ;
V_4 = F_105 ( V_4 , V_2 , NULL , V_171 ,
V_200 -> V_141 , V_200 -> V_90 ,
1 ) ;
}
return V_4 ;
}
static int F_109 ( const struct V_29 * V_30 , const struct V_199 * V_204 )
{
return V_204 < V_30 -> V_205 + F_110 ( V_30 -> V_205 ) ;
}
static int
F_111 ( struct V_1 * V_2 , const struct V_3 * V_152 ,
T_1 V_156 , long * V_206 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_207 = ( F_4 ( V_152 ) +
F_16 ( V_152 ) -> V_137 ) ;
struct V_153 * V_208 = (struct V_153 * ) ( V_207 + 2 ) ;
struct V_199 V_154 [ V_209 ] ;
struct V_199 * V_204 ;
struct V_170 V_171 ;
struct V_3 * V_4 ;
int V_155 = F_9 ( V_209 , ( V_207 [ 1 ] - V_210 ) >> 3 ) ;
int V_211 ;
bool V_212 = false ;
int V_213 , V_214 ;
int V_215 ;
V_171 . V_179 = 0 ;
V_171 . V_177 = V_30 -> V_108 ;
V_171 . V_181 = - 1L ;
if ( ! V_30 -> V_131 ) {
if ( F_112 ( V_30 -> V_130 ) )
V_30 -> V_130 = 0 ;
F_113 ( V_2 ) ;
}
V_212 = F_79 ( V_2 , V_152 , V_208 ,
V_155 , V_156 ) ;
if ( V_212 )
V_171 . V_179 |= V_216 ;
if ( F_43 ( F_16 ( V_152 ) -> V_149 , V_156 - V_30 -> V_142 ) )
return 0 ;
if ( ! V_30 -> V_108 )
goto V_197;
V_211 = 0 ;
V_215 = 0 ;
for ( V_213 = 0 ; V_213 < V_155 ; V_213 ++ ) {
bool V_159 = ! V_213 && V_212 ;
V_154 [ V_211 ] . V_141 = F_80 ( & V_208 [ V_213 ] . V_141 ) ;
V_154 [ V_211 ] . V_90 = F_80 ( & V_208 [ V_213 ] . V_90 ) ;
if ( ! F_74 ( V_30 , V_159 ,
V_154 [ V_211 ] . V_141 ,
V_154 [ V_211 ] . V_90 ) ) {
int V_122 ;
if ( V_159 ) {
if ( ! V_30 -> V_132 )
V_122 = V_217 ;
else
V_122 = V_218 ;
} else {
if ( ( F_16 ( V_152 ) -> V_149 != V_30 -> V_103 ) &&
! F_50 ( V_154 [ V_211 ] . V_90 , V_30 -> V_103 ) )
continue;
V_122 = V_219 ;
}
F_66 ( F_67 ( V_2 ) , V_122 ) ;
if ( V_213 == 0 )
V_215 = - 1 ;
continue;
}
if ( ! F_50 ( V_154 [ V_211 ] . V_90 , V_156 ) )
continue;
V_211 ++ ;
}
for ( V_213 = V_211 - 1 ; V_213 > 0 ; V_213 -- ) {
for ( V_214 = 0 ; V_214 < V_213 ; V_214 ++ ) {
if ( F_50 ( V_154 [ V_214 ] . V_141 , V_154 [ V_214 + 1 ] . V_141 ) ) {
F_114 ( V_154 [ V_214 ] , V_154 [ V_214 + 1 ] ) ;
if ( V_214 == V_215 )
V_215 = V_214 + 1 ;
}
}
}
V_4 = F_101 ( V_2 ) ;
V_171 . V_175 = 0 ;
V_213 = 0 ;
if ( ! V_30 -> V_131 ) {
V_204 = V_30 -> V_205 + F_110 ( V_30 -> V_205 ) ;
} else {
V_204 = V_30 -> V_205 ;
while ( F_109 ( V_30 , V_204 ) && ! V_204 -> V_141 &&
! V_204 -> V_90 )
V_204 ++ ;
}
while ( V_213 < V_211 ) {
T_1 V_141 = V_154 [ V_213 ] . V_141 ;
T_1 V_90 = V_154 [ V_213 ] . V_90 ;
bool V_159 = ( V_212 && ( V_213 == V_215 ) ) ;
struct V_199 * V_200 = NULL ;
if ( V_212 && ( ( V_213 + 1 ) == V_215 ) )
V_200 = & V_154 [ V_213 + 1 ] ;
while ( F_109 ( V_30 , V_204 ) &&
! F_43 ( V_141 , V_204 -> V_90 ) )
V_204 ++ ;
if ( F_109 ( V_30 , V_204 ) && ! V_159 &&
F_50 ( V_90 , V_204 -> V_141 ) ) {
if ( F_43 ( V_141 , V_204 -> V_141 ) ) {
V_4 = F_107 ( V_4 , V_2 , & V_171 ,
V_141 ) ;
V_4 = F_105 ( V_4 , V_2 , V_200 ,
& V_171 ,
V_141 ,
V_204 -> V_141 ,
V_159 ) ;
}
if ( ! F_50 ( V_90 , V_204 -> V_90 ) )
goto V_220;
V_4 = F_108 ( V_4 , V_2 , V_200 ,
& V_171 ,
V_204 -> V_90 ) ;
if ( F_76 ( V_30 ) == V_204 -> V_90 ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_171 . V_175 = V_30 -> V_130 ;
V_204 ++ ;
goto V_221;
}
V_4 = F_107 ( V_4 , V_2 , & V_171 , V_204 -> V_90 ) ;
V_204 ++ ;
continue;
}
if ( ! F_43 ( V_141 , F_76 ( V_30 ) ) ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_171 . V_175 = V_30 -> V_130 ;
}
V_4 = F_107 ( V_4 , V_2 , & V_171 , V_141 ) ;
V_221:
V_4 = F_105 ( V_4 , V_2 , V_200 , & V_171 ,
V_141 , V_90 , V_159 ) ;
V_220:
V_213 ++ ;
}
for ( V_213 = 0 ; V_213 < F_110 ( V_30 -> V_205 ) - V_211 ; V_213 ++ ) {
V_30 -> V_205 [ V_213 ] . V_141 = 0 ;
V_30 -> V_205 [ V_213 ] . V_90 = 0 ;
}
for ( V_214 = 0 ; V_214 < V_211 ; V_214 ++ )
V_30 -> V_205 [ V_213 ++ ] = V_154 [ V_214 ] ;
F_75 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ( V_171 . V_177 < V_30 -> V_130 ) &&
( ( F_2 ( V_2 ) -> V_129 != V_222 ) || V_30 -> V_132 ) )
F_64 ( V_2 , V_30 -> V_130 - V_171 . V_177 , 0 ) ;
V_197:
#if V_128 > 0
F_112 ( ( int ) V_30 -> V_131 < 0 ) ;
F_112 ( ( int ) V_30 -> V_135 < 0 ) ;
F_112 ( ( int ) V_30 -> V_146 < 0 ) ;
F_112 ( ( int ) F_116 ( V_30 ) < 0 ) ;
#endif
* V_206 = V_171 . V_181 ;
return V_171 . V_179 ;
}
static bool F_117 ( struct V_29 * V_30 )
{
T_1 V_223 ;
V_223 = F_34 ( V_30 -> V_135 , 1U ) ;
V_223 = F_9 ( V_223 , V_30 -> V_108 ) ;
if ( ( V_30 -> V_131 + V_223 ) > V_30 -> V_108 ) {
V_30 -> V_131 = V_30 -> V_108 - V_223 ;
return true ;
}
return false ;
}
static void F_118 ( struct V_1 * V_2 , const int V_224 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_117 ( V_30 ) )
F_64 ( V_2 , V_30 -> V_108 + V_224 , 0 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_131 ++ ;
F_118 ( V_2 , 0 ) ;
F_115 ( V_30 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_225 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_225 > 0 ) {
if ( V_225 - 1 >= V_30 -> V_131 )
V_30 -> V_131 = 0 ;
else
V_30 -> V_131 -= V_225 - 1 ;
}
F_118 ( V_2 , V_225 ) ;
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
V_30 -> V_133 = - 1 ;
}
void F_123 ( struct V_29 * V_30 )
{
F_122 ( V_30 ) ;
V_30 -> V_130 = 0 ;
V_30 -> V_131 = 0 ;
}
void F_124 ( struct V_1 * V_2 , int V_226 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_227 = false ;
if ( V_6 -> V_129 <= V_228 ||
! F_50 ( V_30 -> V_178 , V_30 -> V_103 ) ||
( V_6 -> V_129 == V_222 && ! V_6 -> V_229 ) ) {
V_227 = true ;
V_30 -> V_230 = F_125 ( V_2 ) ;
V_30 -> V_231 = V_6 -> V_232 -> V_233 ( V_2 ) ;
F_126 ( V_2 , V_234 ) ;
}
V_30 -> V_53 = 1 ;
V_30 -> V_235 = 0 ;
V_30 -> V_78 = V_74 ;
F_122 ( V_30 ) ;
if ( F_65 ( V_30 ) )
F_121 ( V_30 ) ;
V_30 -> V_132 = V_30 -> V_103 ;
if ( V_226 ) {
V_30 -> V_131 = 0 ;
V_30 -> V_130 = 0 ;
}
F_127 ( V_30 ) ;
F_77 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_137 & V_150 )
V_30 -> V_132 = 0 ;
F_16 ( V_4 ) -> V_137 &= ( ~ V_195 ) | V_139 ;
if ( ! ( F_16 ( V_4 ) -> V_137 & V_139 ) || V_226 ) {
F_16 ( V_4 ) -> V_137 &= ~ V_139 ;
F_16 ( V_4 ) -> V_137 |= V_138 ;
V_30 -> V_135 += F_72 ( V_4 ) ;
V_30 -> V_136 = F_16 ( V_4 ) -> V_90 ;
}
}
F_115 ( V_30 ) ;
if ( V_6 -> V_129 <= V_228 &&
V_30 -> V_131 >= V_236 )
V_30 -> V_54 = F_40 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_128 ( V_2 , V_222 ) ;
V_30 -> V_178 = V_30 -> V_105 ;
F_12 ( V_30 ) ;
V_30 -> V_237 = V_238 &&
( V_227 || V_6 -> V_229 ) &&
! F_2 ( V_2 ) -> V_239 . V_240 ;
}
static bool F_129 ( struct V_1 * V_2 , int V_179 )
{
if ( V_179 & V_241 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_242 ) ;
F_124 ( V_2 , 1 ) ;
V_6 -> V_229 ++ ;
F_130 ( V_2 , F_101 ( V_2 ) ) ;
F_131 ( V_2 , V_243 ,
V_6 -> V_96 , V_244 ) ;
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
static bool F_134 ( struct V_1 * V_2 , int V_179 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_245 ;
if ( V_246 < 2 || V_246 > 3 ||
( V_179 & V_247 ) || ! V_30 -> V_99 )
return false ;
V_245 = F_34 ( F_135 ( V_30 -> V_99 >> 5 ) ,
F_136 ( 2 ) ) ;
if ( ! F_137 ( F_2 ( V_2 ) -> V_248 , ( V_249 + V_245 ) ) )
return false ;
F_131 ( V_2 , V_250 , V_245 ,
V_244 ) ;
return true ;
}
static bool F_138 ( struct V_1 * V_2 , int V_179 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_108 ;
if ( V_30 -> V_135 )
return true ;
if ( F_133 ( V_30 ) > V_30 -> V_54 )
return true ;
V_108 = V_30 -> V_108 ;
if ( V_108 <= V_30 -> V_54 &&
V_30 -> V_131 >= F_21 ( T_3 , V_108 / 2 , V_236 ) &&
! F_139 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_251 || V_252 ) &&
F_140 ( V_30 ) && F_133 ( V_30 ) > 1 &&
F_141 ( V_30 ) && ! F_78 ( V_2 ) )
return true ;
if ( V_30 -> V_253 && ! V_30 -> V_146 && V_30 -> V_131 &&
( V_30 -> V_108 >= ( V_30 -> V_131 + 1 ) && V_30 -> V_108 < 4 ) &&
! F_139 ( V_2 ) )
return ! F_134 ( V_2 , V_179 ) ;
return false ;
}
static void F_142 ( struct V_1 * V_2 , int V_254 , int V_255 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_143 , V_256 ;
int V_164 ;
unsigned int V_64 ;
const T_1 V_257 = F_141 ( V_30 ) ? V_30 -> V_105 : V_30 -> V_178 ;
F_112 ( V_254 > V_30 -> V_108 ) ;
if ( V_30 -> V_116 ) {
V_4 = V_30 -> V_116 ;
V_143 = V_30 -> V_183 ;
if ( V_255 && V_4 != F_101 ( V_2 ) )
return;
} else {
V_4 = F_101 ( V_2 ) ;
V_143 = 0 ;
}
F_106 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
V_30 -> V_116 = V_4 ;
V_30 -> V_183 = V_143 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_257 ) )
break;
V_256 = V_143 ;
if ( F_62 ( V_30 ) || F_65 ( V_30 ) ||
( F_16 ( V_4 ) -> V_137 & V_139 ) )
V_143 += F_72 ( V_4 ) ;
if ( V_143 > V_254 ) {
if ( ( F_141 ( V_30 ) && ! F_62 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_137 & V_139 ) ||
( V_256 >= V_254 ) )
break;
V_64 = F_3 ( V_4 ) -> V_11 ;
V_164 = F_83 ( V_2 , V_4 , ( V_254 - V_256 ) * V_64 ,
V_64 , V_169 ) ;
if ( V_164 < 0 )
break;
V_143 = V_254 ;
}
F_71 ( V_30 , V_4 ) ;
if ( V_255 )
break;
}
F_115 ( V_30 ) ;
}
static void F_143 ( struct V_1 * V_2 , int V_258 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_65 ( V_30 ) ) {
F_142 ( V_2 , 1 , 1 ) ;
} else if ( F_62 ( V_30 ) ) {
int V_259 = V_30 -> V_130 - V_30 -> V_54 ;
if ( V_259 <= 0 )
V_259 = 1 ;
F_142 ( V_2 , V_259 , 0 ) ;
} else {
int V_260 = V_30 -> V_131 - V_30 -> V_54 ;
if ( V_260 >= 0 )
F_142 ( V_2 , V_260 , 0 ) ;
else if ( V_258 )
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
return ! V_30 -> V_261 ||
( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 &&
F_43 ( V_30 -> V_47 . V_89 , V_30 -> V_261 ) ) ;
}
static void F_147 ( struct V_1 * V_2 , const char * V_263 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_264 * V_265 = F_148 ( V_2 ) ;
if ( V_2 -> V_266 == V_267 ) {
F_68 ( L_2 ,
V_263 ,
& V_265 -> V_268 , F_149 ( V_265 -> V_269 ) ,
V_30 -> V_53 , F_150 ( V_30 ) ,
V_30 -> V_231 , V_30 -> V_230 ,
V_30 -> V_108 ) ;
}
#if F_151 ( V_270 )
else if ( V_2 -> V_266 == V_271 ) {
struct V_272 * V_273 = F_152 ( V_2 ) ;
F_68 ( L_3 ,
V_263 ,
& V_273 -> V_274 , F_149 ( V_265 -> V_269 ) ,
V_30 -> V_53 , F_150 ( V_30 ) ,
V_30 -> V_231 , V_30 -> V_230 ,
V_30 -> V_108 ) ;
}
#endif
}
static void F_153 ( struct V_1 * V_2 , bool V_275 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_275 ) {
struct V_3 * V_4 ;
F_77 (skb, sk) {
if ( V_4 == F_78 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_137 &= ~ V_138 ;
}
V_30 -> V_135 = 0 ;
F_127 ( V_30 ) ;
}
if ( V_30 -> V_230 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_232 -> V_276 )
V_30 -> V_53 = V_6 -> V_232 -> V_276 ( V_2 ) ;
else
V_30 -> V_53 = F_34 ( V_30 -> V_53 , V_30 -> V_231 << 1 ) ;
if ( V_30 -> V_230 > V_30 -> V_231 ) {
V_30 -> V_231 = V_30 -> V_230 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_53 = F_34 ( V_30 -> V_53 , V_30 -> V_231 ) ;
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
F_147 ( V_2 , F_2 ( V_2 ) -> V_129 == V_222 ? L_4 : L_5 ) ;
F_153 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_129 == V_222 )
V_122 = V_277 ;
else
V_122 = V_278 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
}
if ( V_30 -> V_103 == V_30 -> V_178 && F_65 ( V_30 ) ) {
F_144 ( V_30 ) ;
return true ;
}
F_128 ( V_2 , V_279 ) ;
return false ;
}
static bool F_156 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_132 && ! V_30 -> V_133 ) {
F_147 ( V_2 , L_6 ) ;
F_153 ( V_2 , false ) ;
F_66 ( F_67 ( V_2 ) , V_280 ) ;
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
if ( F_100 ( V_4 && F_16 ( V_4 ) -> V_137 & V_189 ) )
return true ;
return false ;
}
static bool F_158 ( struct V_1 * V_2 , bool V_281 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_281 || F_154 ( V_30 ) ) {
F_153 ( V_2 , true ) ;
F_147 ( V_2 , L_7 ) ;
F_66 ( F_67 ( V_2 ) , V_277 ) ;
if ( V_281 )
F_66 ( F_67 ( V_2 ) ,
V_282 ) ;
F_2 ( V_2 ) -> V_229 = 0 ;
if ( V_281 || F_141 ( V_30 ) )
F_128 ( V_2 , V_279 ) ;
return true ;
}
return false ;
}
static void F_159 ( struct V_1 * V_2 , const bool V_283 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_178 = V_30 -> V_105 ;
V_30 -> V_284 = 0 ;
V_30 -> V_235 = 0 ;
V_30 -> V_285 = V_30 -> V_53 ;
V_30 -> V_286 = 0 ;
V_30 -> V_287 = 0 ;
if ( V_283 )
V_30 -> V_231 = F_2 ( V_2 ) -> V_232 -> V_233 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_160 ( struct V_1 * V_2 , const int V_288 ,
int V_258 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_289 = 0 ;
int V_290 = V_30 -> V_231 - F_116 ( V_30 ) ;
int V_291 = V_288 -
( V_30 -> V_108 - V_30 -> V_131 ) ;
V_30 -> V_286 += V_291 ;
if ( F_116 ( V_30 ) > V_30 -> V_231 ) {
T_2 V_292 = ( T_2 ) V_30 -> V_231 * V_30 -> V_286 +
V_30 -> V_285 - 1 ;
V_289 = F_161 ( V_292 , V_30 -> V_285 ) - V_30 -> V_287 ;
} else {
V_289 = F_40 ( int , V_290 ,
F_21 ( int , V_30 -> V_286 - V_30 -> V_287 ,
V_291 ) + 1 ) ;
}
V_289 = F_34 ( V_289 , ( V_258 ? 1 : 0 ) ) ;
V_30 -> V_53 = F_116 ( V_30 ) + V_289 ;
}
static inline void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_129 == V_293 ||
( V_30 -> V_132 && V_30 -> V_231 < V_294 ) ) {
V_30 -> V_53 = V_30 -> V_231 ;
V_30 -> V_78 = V_74 ;
}
F_126 ( V_2 , V_295 ) ;
}
void F_163 ( struct V_1 * V_2 , const int V_283 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_230 = 0 ;
if ( F_2 ( V_2 ) -> V_129 < V_293 ) {
V_30 -> V_132 = 0 ;
F_159 ( V_2 , V_283 ) ;
F_128 ( V_2 , V_293 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_171 = V_279 ;
if ( F_150 ( V_30 ) || F_157 ( V_2 ) )
V_171 = V_228 ;
if ( F_2 ( V_2 ) -> V_129 != V_171 ) {
F_128 ( V_2 , V_171 ) ;
V_30 -> V_178 = V_30 -> V_105 ;
}
}
static void F_165 ( struct V_1 * V_2 , int V_179 , const int V_288 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ! F_157 ( V_2 ) )
V_30 -> V_261 = 0 ;
if ( V_179 & V_247 )
F_163 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_129 != V_293 ) {
F_164 ( V_2 ) ;
} else {
F_160 ( V_2 , V_288 , 0 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_239 . V_296 = V_6 -> V_239 . V_240 - 1 ;
V_6 -> V_239 . V_240 = 0 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_230 = F_125 ( V_2 ) ;
V_30 -> V_53 = V_30 -> V_53 *
F_168 ( V_2 , V_30 -> V_49 ) /
V_6 -> V_239 . V_240 ;
V_30 -> V_235 = 0 ;
V_30 -> V_78 = V_74 ;
V_30 -> V_231 = F_125 ( V_2 ) ;
V_6 -> V_239 . V_297 = V_6 -> V_239 . V_240 ;
V_6 -> V_239 . V_240 = 0 ;
F_169 ( V_2 , V_6 -> V_298 ) ;
}
void F_170 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_64 = F_171 ( V_2 ) ;
T_1 V_299 = V_30 -> V_135 ;
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
if ( V_299 == V_30 -> V_135 )
return;
if ( F_65 ( V_30 ) )
F_117 ( V_30 ) ;
F_115 ( V_30 ) ;
if ( V_6 -> V_129 != V_222 ) {
V_30 -> V_178 = V_30 -> V_105 ;
V_30 -> V_231 = F_125 ( V_2 ) ;
V_30 -> V_230 = 0 ;
V_30 -> V_132 = 0 ;
F_128 ( V_2 , V_222 ) ;
}
F_173 ( V_2 ) ;
}
static void F_174 ( struct V_1 * V_2 , bool V_300 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_122 ;
if ( F_65 ( V_30 ) )
V_122 = V_301 ;
else
V_122 = V_302 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
V_30 -> V_230 = 0 ;
V_30 -> V_132 = V_30 -> V_103 ;
V_30 -> V_133 = V_30 -> V_146 ? : - 1 ;
if ( F_2 ( V_2 ) -> V_129 < V_293 ) {
if ( ! V_300 )
V_30 -> V_230 = F_125 ( V_2 ) ;
F_159 ( V_2 , true ) ;
}
F_128 ( V_2 , V_148 ) ;
}
static void F_175 ( struct V_1 * V_2 , int V_179 , bool V_303 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_304 = ! F_43 ( V_30 -> V_103 , V_30 -> V_178 ) ;
if ( V_30 -> V_237 ) {
if ( F_158 ( V_2 , V_179 & V_180 ) )
return;
if ( F_50 ( V_30 -> V_105 , V_30 -> V_178 ) &&
( V_179 & V_182 || V_303 ) ) {
V_30 -> V_237 = 0 ;
} else if ( V_179 & V_305 && ! V_304 ) {
V_30 -> V_178 = V_30 -> V_105 ;
F_176 ( V_2 , F_171 ( V_2 ) ,
V_306 ) ;
if ( F_50 ( V_30 -> V_105 , V_30 -> V_178 ) )
return;
V_30 -> V_237 = 0 ;
}
}
if ( V_304 ) {
V_6 -> V_229 = 0 ;
F_155 ( V_2 ) ;
return;
}
if ( V_179 & V_307 )
V_6 -> V_229 = 0 ;
if ( F_65 ( V_30 ) ) {
if ( F_50 ( V_30 -> V_105 , V_30 -> V_178 ) && V_303 )
F_119 ( V_2 ) ;
else if ( V_179 & V_305 )
F_121 ( V_30 ) ;
}
if ( F_158 ( V_2 , false ) )
return;
F_173 ( V_2 ) ;
}
static bool F_177 ( struct V_1 * V_2 , const int V_225 ,
const int V_288 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_132 && F_146 ( V_30 ) ) {
F_64 ( V_2 , F_132 ( V_30 ) + V_225 , 1 ) ;
if ( V_30 -> V_146 ) {
F_160 ( V_2 , V_288 , 0 ) ;
return true ;
}
if ( ! F_157 ( V_2 ) )
V_30 -> V_261 = 0 ;
F_147 ( V_2 , L_8 ) ;
F_153 ( V_2 , true ) ;
F_66 ( F_67 ( V_2 ) , V_308 ) ;
F_164 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_178 ( struct V_1 * V_2 , const int V_225 ,
const int V_288 ,
bool V_303 , int V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_309 = V_303 || ( ( V_179 & V_182 ) &&
( F_132 ( V_30 ) > V_30 -> V_54 ) ) ;
int V_258 = 0 ;
if ( F_112 ( ! V_30 -> V_108 && V_30 -> V_131 ) )
V_30 -> V_131 = 0 ;
if ( F_112 ( ! V_30 -> V_131 && V_30 -> V_130 ) )
V_30 -> V_130 = 0 ;
if ( V_179 & V_247 )
V_30 -> V_230 = 0 ;
if ( F_129 ( V_2 , V_179 ) )
return;
F_115 ( V_30 ) ;
if ( V_6 -> V_129 == V_279 ) {
F_112 ( V_30 -> V_146 != 0 ) ;
V_30 -> V_261 = 0 ;
} else if ( ! F_43 ( V_30 -> V_103 , V_30 -> V_178 ) ) {
switch ( V_6 -> V_129 ) {
case V_293 :
if ( V_30 -> V_103 != V_30 -> V_178 ) {
F_162 ( V_2 ) ;
F_128 ( V_2 , V_279 ) ;
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
if ( ! ( V_179 & V_305 ) ) {
if ( F_65 ( V_30 ) && V_303 )
F_119 ( V_2 ) ;
} else {
if ( F_177 ( V_2 , V_225 , V_288 ) )
return;
V_309 = F_65 ( V_30 ) ||
F_132 ( V_30 ) > V_30 -> V_54 ;
}
if ( F_156 ( V_2 ) ) {
F_164 ( V_2 ) ;
return;
}
break;
case V_222 :
F_175 ( V_2 , V_179 , V_303 ) ;
if ( V_6 -> V_129 != V_279 )
return;
default:
if ( F_65 ( V_30 ) ) {
if ( V_179 & V_305 )
F_121 ( V_30 ) ;
if ( V_303 )
F_119 ( V_2 ) ;
}
if ( V_6 -> V_129 <= V_228 )
F_156 ( V_2 ) ;
if ( ! F_138 ( V_2 , V_179 ) ) {
F_165 ( V_2 , V_179 , V_288 ) ;
return;
}
if ( V_6 -> V_129 < V_293 &&
V_6 -> V_239 . V_240 &&
V_30 -> V_103 == V_30 -> V_310 . V_311 ) {
F_166 ( V_2 ) ;
V_30 -> V_53 ++ ;
F_170 ( V_2 ) ;
return;
}
F_174 ( V_2 , ( V_179 & V_247 ) ) ;
V_258 = 1 ;
}
if ( V_309 )
F_143 ( V_2 , V_258 ) ;
F_160 ( V_2 , V_288 , V_258 ) ;
F_173 ( V_2 ) ;
}
static inline bool F_179 ( struct V_1 * V_2 , const int V_179 ,
long V_312 , long V_206 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_179 & V_313 )
V_312 = - 1L ;
if ( V_312 < 0 )
V_312 = V_206 ;
if ( V_312 < 0 && V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 &&
V_179 & V_314 )
V_312 = F_180 ( V_74 - V_30 -> V_47 . V_89 ) ;
if ( V_312 < 0 )
return false ;
F_49 ( V_2 , V_312 ) ;
F_56 ( V_2 ) ;
F_2 ( V_2 ) -> V_315 = 0 ;
return true ;
}
static void F_181 ( struct V_1 * V_2 , const T_1 V_316 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_312 = - 1L ;
if ( V_316 && ! V_30 -> V_317 )
V_312 = F_180 ( V_74 - V_316 ) ;
if ( ! V_30 -> V_99 )
F_179 ( V_2 , V_318 , V_312 , - 1L ) ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_319 , T_1 V_225 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_232 -> V_320 ( V_2 , V_319 , V_225 ) ;
F_7 ( V_2 ) -> V_78 = V_74 ;
}
void F_183 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_321 )
return;
if ( ! V_30 -> V_108 ) {
F_184 ( V_2 , V_243 ) ;
} else {
T_1 V_322 = F_2 ( V_2 ) -> V_96 ;
if ( V_6 -> V_323 == V_250 ||
V_6 -> V_323 == V_324 ) {
struct V_3 * V_4 = F_101 ( V_2 ) ;
const T_1 V_325 = F_16 ( V_4 ) -> V_326 + V_322 ;
T_5 V_290 = ( T_5 ) ( V_325 - V_74 ) ;
if ( V_290 > 0 )
V_322 = V_290 ;
}
F_131 ( V_2 , V_243 , V_322 ,
V_244 ) ;
}
}
void F_185 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_183 ( V_2 ) ;
if ( ! V_30 -> V_253 )
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
T_1 V_156 , long V_206 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_173 V_329 , V_330 , V_94 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_331 = V_30 -> V_131 ;
T_1 V_177 = V_30 -> V_108 ;
bool V_332 = true ;
long V_333 = - 1L ;
long V_312 = - 1L ;
struct V_3 * V_4 ;
T_1 V_334 = 0 ;
bool V_335 ;
int V_179 = 0 ;
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
if ( V_137 & V_176 ) {
if ( V_137 & V_150 )
V_30 -> V_146 -= V_339 ;
V_179 |= V_313 ;
} else {
V_330 = V_4 -> V_173 ;
F_189 ( V_330 . V_336 == 0 ) ;
if ( ! V_329 . V_336 )
V_329 = V_330 ;
if ( ! ( V_137 & V_139 ) )
V_177 = F_9 ( V_334 , V_177 ) ;
if ( ! F_50 ( V_338 -> V_90 , V_30 -> V_178 ) )
V_179 |= V_180 ;
}
if ( V_137 & V_139 )
V_30 -> V_131 -= V_339 ;
if ( V_137 & V_138 )
V_30 -> V_135 -= V_339 ;
V_30 -> V_108 -= V_339 ;
V_334 += V_339 ;
if ( ! ( V_338 -> V_191 & V_340 ) ) {
V_179 |= V_307 ;
} else {
V_179 |= V_318 ;
V_30 -> V_261 = 0 ;
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
V_179 |= V_241 ;
F_85 ( & V_94 ) ;
if ( V_329 . V_336 ) {
V_312 = F_86 ( & V_94 , & V_329 ) ;
V_333 = F_86 ( & V_94 , & V_330 ) ;
}
V_335 = F_179 ( V_2 , V_179 , V_312 , V_206 ) ;
if ( V_179 & V_314 ) {
const struct V_342 * V_343
= F_2 ( V_2 ) -> V_232 ;
F_183 ( V_2 ) ;
if ( F_100 ( V_6 -> V_239 . V_240 &&
! F_50 ( V_30 -> V_310 . V_344 , V_30 -> V_103 ) ) ) {
F_167 ( V_2 ) ;
}
if ( F_65 ( V_30 ) ) {
F_120 ( V_2 , V_334 ) ;
} else {
int V_290 ;
if ( V_177 < V_328 )
F_64 ( V_2 , V_30 -> V_130 - V_177 , 0 ) ;
V_290 = F_62 ( V_30 ) ? V_334 :
V_331 - V_30 -> V_131 ;
V_30 -> V_183 -= F_9 ( V_30 -> V_183 , V_290 ) ;
}
V_30 -> V_130 -= F_9 ( V_334 , V_30 -> V_130 ) ;
if ( V_343 -> V_334 )
V_343 -> V_334 ( V_2 , V_334 , V_333 ) ;
} else if ( V_4 && V_335 && V_206 >= 0 &&
V_206 > F_86 ( & V_94 , & V_4 -> V_173 ) ) {
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
return V_179 ;
}
static void F_191 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_50 ( F_16 ( F_78 ( V_2 ) ) -> V_90 , F_192 ( V_30 ) ) ) {
V_6 -> V_315 = 0 ;
F_184 ( V_2 , V_345 ) ;
} else {
F_131 ( V_2 , V_345 ,
F_9 ( V_6 -> V_96 << V_6 -> V_315 , V_244 ) ,
V_244 ) ;
}
}
static inline bool F_193 ( const struct V_1 * V_2 , const int V_179 )
{
return ! ( V_179 & V_346 ) || ( V_179 & V_347 ) ||
F_2 ( V_2 ) -> V_129 != V_279 ;
}
static inline bool F_194 ( const struct V_1 * V_2 , const int V_179 )
{
if ( F_195 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_54 > V_236 )
return V_179 & V_348 ;
return V_179 & V_307 ;
}
static inline bool F_196 ( const struct V_29 * V_30 ,
const T_1 V_319 , const T_1 V_149 ,
const T_1 V_349 )
{
return F_50 ( V_319 , V_30 -> V_103 ) ||
F_50 ( V_149 , V_30 -> V_350 ) ||
( V_149 == V_30 -> V_350 && V_349 > V_30 -> V_351 ) ;
}
static int F_197 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_319 ,
T_1 V_149 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_179 = 0 ;
T_1 V_349 = F_149 ( F_6 ( V_4 ) -> V_58 ) ;
if ( F_53 ( ! F_6 ( V_4 ) -> V_43 ) )
V_349 <<= V_30 -> V_47 . V_352 ;
if ( F_196 ( V_30 , V_319 , V_149 , V_349 ) ) {
V_179 |= V_353 ;
F_198 ( V_30 , V_149 ) ;
if ( V_30 -> V_351 != V_349 ) {
V_30 -> V_351 = V_349 ;
V_30 -> V_354 = 0 ;
F_199 ( V_2 ) ;
if ( V_349 > V_30 -> V_142 ) {
V_30 -> V_142 = V_349 ;
F_169 ( V_2 , F_2 ( V_2 ) -> V_298 ) ;
}
}
}
V_30 -> V_103 = V_319 ;
return V_179 ;
}
static void F_200 ( struct V_1 * V_2 )
{
static T_1 V_355 ;
static unsigned int V_356 ;
T_1 V_94 = V_249 / V_357 ;
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
if ( V_30 -> V_47 . V_262 && ! F_50 ( V_75 , V_30 -> V_363 ) ) {
if ( F_205 ( & V_30 -> V_47 , 0 ) )
F_202 ( V_30 ) ;
}
}
static void F_206 ( struct V_1 * V_2 , T_1 V_319 , int V_179 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_364 = ( V_319 == V_30 -> V_284 ) &&
! ( V_179 & ( V_305 |
V_346 | V_182 ) ) ;
if ( V_364 ) {
V_30 -> V_284 = 0 ;
return;
}
if ( F_50 ( V_319 , V_30 -> V_284 ) ) {
V_30 -> V_284 = 0 ;
if ( ! ( V_179 & V_216 ) ) {
F_159 ( V_2 , true ) ;
F_128 ( V_2 , V_293 ) ;
F_162 ( V_2 ) ;
F_164 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) ,
V_365 ) ;
}
}
}
static int F_207 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_156 = V_30 -> V_103 ;
T_1 V_149 = F_16 ( V_4 ) -> V_75 ;
T_1 V_319 = F_16 ( V_4 ) -> V_149 ;
bool V_303 = false ;
T_1 V_328 ;
int V_366 = V_30 -> V_108 ;
const int V_288 = V_30 -> V_108 - V_30 -> V_131 ;
int V_225 = 0 ;
long V_206 = - 1L ;
if ( F_43 ( V_319 , V_156 ) ) {
if ( F_43 ( V_319 , V_156 - V_30 -> V_142 ) ) {
F_200 ( V_2 ) ;
return - 1 ;
}
goto V_367;
}
if ( F_50 ( V_319 , V_30 -> V_105 ) )
goto V_368;
if ( V_6 -> V_323 == V_250 ||
V_6 -> V_323 == V_324 )
F_183 ( V_2 ) ;
if ( F_50 ( V_319 , V_156 ) )
V_179 |= V_305 ;
V_328 = V_30 -> V_130 ;
if ( V_179 & V_369 )
F_204 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! ( V_179 & V_370 ) && F_50 ( V_319 , V_156 ) ) {
F_198 ( V_30 , V_149 ) ;
V_30 -> V_103 = V_319 ;
V_179 |= V_353 ;
F_126 ( V_2 , V_371 ) ;
F_66 ( F_67 ( V_2 ) , V_372 ) ;
} else {
if ( V_149 != F_16 ( V_4 ) -> V_90 )
V_179 |= V_373 ;
else
F_66 ( F_67 ( V_2 ) , V_374 ) ;
V_179 |= F_197 ( V_2 , V_4 , V_319 , V_149 ) ;
if ( F_16 ( V_4 ) -> V_137 )
V_179 |= F_111 ( V_2 , V_4 , V_156 ,
& V_206 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_179 |= V_247 ;
F_126 ( V_2 , V_375 ) ;
}
V_2 -> V_376 = 0 ;
V_6 -> V_377 = 0 ;
V_30 -> V_378 = V_74 ;
if ( ! V_366 )
goto V_379;
V_225 = V_30 -> V_108 ;
V_179 |= F_188 ( V_2 , V_328 , V_156 ,
V_206 ) ;
V_225 -= V_30 -> V_108 ;
if ( F_194 ( V_2 , V_179 ) )
F_182 ( V_2 , V_319 , V_225 ) ;
if ( F_193 ( V_2 , V_179 ) ) {
V_303 = ! ( V_179 & ( V_305 | V_346 ) ) ;
F_178 ( V_2 , V_225 , V_288 ,
V_303 , V_179 ) ;
}
if ( V_30 -> V_284 )
F_206 ( V_2 , V_319 , V_179 ) ;
if ( ( V_179 & V_348 ) || ! ( V_179 & V_346 ) ) {
struct V_111 * V_112 = F_208 ( V_2 ) ;
if ( V_112 )
F_209 ( V_112 ) ;
}
if ( V_6 -> V_323 == V_243 )
F_210 ( V_2 ) ;
F_52 ( V_2 ) ;
return 1 ;
V_379:
if ( V_179 & V_216 )
F_178 ( V_2 , V_225 , V_288 ,
V_303 , V_179 ) ;
if ( F_78 ( V_2 ) )
F_191 ( V_2 ) ;
if ( V_30 -> V_284 )
F_206 ( V_2 , V_319 , V_179 ) ;
return 1 ;
V_368:
F_211 ( V_2 , L_12 , V_319 , V_30 -> V_103 , V_30 -> V_105 ) ;
return - 1 ;
V_367:
if ( F_16 ( V_4 ) -> V_137 ) {
V_179 |= F_111 ( V_2 , V_4 , V_156 ,
& V_206 ) ;
F_178 ( V_2 , V_225 , V_288 ,
V_303 , V_179 ) ;
}
F_211 ( V_2 , L_13 , V_319 , V_30 -> V_103 , V_30 -> V_105 ) ;
return 0 ;
}
void F_212 ( const struct V_3 * V_4 ,
struct V_380 * V_381 , int V_382 ,
struct V_383 * V_384 )
{
const unsigned char * V_207 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_385 = ( V_41 -> V_386 * 4 ) - sizeof( struct V_15 ) ;
V_207 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_381 -> V_262 = 0 ;
while ( V_385 > 0 ) {
int V_387 = * V_207 ++ ;
int V_388 ;
switch ( V_387 ) {
case V_389 :
return;
case V_390 :
V_385 -- ;
continue;
default:
V_388 = * V_207 ++ ;
if ( V_388 < 2 )
return;
if ( V_388 > V_385 )
return;
switch ( V_387 ) {
case V_391 :
if ( V_388 == V_392 && V_41 -> V_43 && ! V_382 ) {
T_6 V_393 = F_213 ( V_207 ) ;
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
T_7 V_352 = * ( T_7 * ) V_207 ;
V_381 -> V_398 = 1 ;
if ( V_352 > 14 ) {
F_214 ( L_14 ,
V_399 ,
V_352 ) ;
V_352 = 14 ;
}
V_381 -> V_352 = V_352 ;
}
break;
case V_400 :
if ( ( V_388 == V_401 ) &&
( ( V_382 && V_381 -> V_402 ) ||
( ! V_382 && V_403 ) ) ) {
V_381 -> V_262 = 1 ;
V_381 -> V_361 = F_80 ( V_207 ) ;
V_381 -> V_89 = F_80 ( V_207 + 4 ) ;
}
break;
case V_404 :
if ( V_388 == V_405 && V_41 -> V_43 &&
! V_382 && V_406 ) {
V_381 -> V_117 = V_407 ;
F_215 ( V_381 ) ;
}
break;
case V_408 :
if ( ( V_388 >= ( V_210 + V_409 ) ) &&
! ( ( V_388 - V_210 ) % V_409 ) &&
V_381 -> V_117 ) {
F_16 ( V_4 ) -> V_137 = ( V_207 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_216
case V_410 :
break;
#endif
case V_411 :
if ( V_388 < V_412 ||
F_213 ( V_207 ) != V_413 ||
V_384 == NULL || ! V_41 -> V_43 || ( V_388 & 1 ) )
break;
V_384 -> V_10 = V_388 - V_412 ;
if ( V_384 -> V_10 >= V_414 &&
V_384 -> V_10 <= V_415 )
memcpy ( V_384 -> V_416 , V_207 + 2 , V_384 -> V_10 ) ;
else if ( V_384 -> V_10 != 0 )
V_384 -> V_10 = - 1 ;
break;
}
V_207 += V_388 - 2 ;
V_385 -= V_388 ;
}
}
}
static bool F_217 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_8 * V_207 = ( const T_8 * ) ( V_41 + 1 ) ;
if ( * V_207 == F_218 ( ( V_390 << 24 ) | ( V_390 << 16 )
| ( V_400 << 8 ) | V_401 ) ) {
V_30 -> V_47 . V_262 = 1 ;
++ V_207 ;
V_30 -> V_47 . V_361 = F_219 ( * V_207 ) ;
++ V_207 ;
if ( * V_207 )
V_30 -> V_47 . V_89 = F_219 ( * V_207 ) - V_30 -> V_417 ;
else
V_30 -> V_47 . V_89 = 0 ;
return true ;
}
return false ;
}
static bool F_220 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 , struct V_29 * V_30 )
{
if ( V_41 -> V_386 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_47 . V_262 = 0 ;
return false ;
} else if ( V_30 -> V_47 . V_402 &&
V_41 -> V_386 == ( ( sizeof( * V_41 ) + V_418 ) / 4 ) ) {
if ( F_217 ( V_30 , V_41 ) )
return true ;
}
F_212 ( V_4 , & V_30 -> V_47 , 1 , NULL ) ;
if ( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_417 ;
return true ;
}
const T_4 * F_221 ( const struct V_15 * V_41 )
{
int V_385 = ( V_41 -> V_386 << 2 ) - sizeof( * V_41 ) ;
const T_4 * V_207 = ( const T_4 * ) ( V_41 + 1 ) ;
if ( V_385 < V_419 )
return NULL ;
while ( V_385 > 0 ) {
int V_387 = * V_207 ++ ;
int V_388 ;
switch ( V_387 ) {
case V_389 :
return NULL ;
case V_390 :
V_385 -- ;
continue;
default:
V_388 = * V_207 ++ ;
if ( V_388 < 2 || V_388 > V_385 )
return NULL ;
if ( V_387 == V_410 )
return V_388 == V_419 ? V_207 : NULL ;
}
V_207 += V_388 - 2 ;
V_385 -= V_388 ;
}
return NULL ;
}
static int F_222 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_75 = F_16 ( V_4 ) -> V_75 ;
T_1 V_319 = F_16 ( V_4 ) -> V_149 ;
return (
( V_41 -> V_319 && V_75 == F_16 ( V_4 ) -> V_90 && V_75 == V_30 -> V_88 ) &&
V_319 == V_30 -> V_103 &&
! F_196 ( V_30 , V_319 , V_75 , F_149 ( V_41 -> V_58 ) << V_30 -> V_47 . V_352 ) &&
( T_5 ) ( V_30 -> V_47 . V_360 - V_30 -> V_47 . V_361 ) <= ( F_2 ( V_2 ) -> V_96 * 1024 ) / V_357 ) ;
}
static inline bool F_223 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_205 ( & V_30 -> V_47 , V_420 ) &&
! F_222 ( V_2 , V_4 ) ;
}
static inline bool F_224 ( const struct V_29 * V_30 , T_1 V_75 , T_1 V_90 )
{
return ! F_43 ( V_90 , V_30 -> V_363 ) &&
! F_50 ( V_75 , V_30 -> V_88 + F_225 ( V_30 ) ) ;
}
void F_226 ( struct V_1 * V_2 )
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
F_227 () ;
if ( ! F_228 ( V_2 , V_429 ) )
V_2 -> V_430 ( V_2 ) ;
F_229 ( V_2 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_111 * V_112 ;
F_47 ( V_2 ) ;
V_2 -> V_431 |= V_432 ;
F_231 ( V_2 , V_433 ) ;
switch ( V_2 -> V_421 ) {
case V_434 :
case V_435 :
F_232 ( V_2 , V_425 ) ;
V_112 = F_208 ( V_2 ) ;
if ( ! V_112 || ! F_60 ( V_112 , V_436 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_425 :
case V_437 :
break;
case V_438 :
break;
case V_439 :
F_201 ( V_2 ) ;
F_232 ( V_2 , V_437 ) ;
break;
case V_440 :
F_201 ( V_2 ) ;
F_233 ( V_2 , V_441 , 0 ) ;
break;
default:
F_234 ( L_15 ,
V_399 , V_2 -> V_421 ) ;
break;
}
F_235 ( & V_30 -> V_442 ) ;
if ( F_141 ( V_30 ) )
F_215 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
if ( ! F_228 ( V_2 , V_429 ) ) {
V_2 -> V_443 ( V_2 ) ;
if ( V_2 -> V_431 == V_444 ||
V_2 -> V_421 == V_427 )
F_236 ( V_2 , V_445 , V_446 ) ;
else
F_236 ( V_2 , V_445 , V_447 ) ;
}
}
static inline bool F_237 ( struct V_199 * V_154 , T_1 V_75 ,
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
if ( F_141 ( V_30 ) && V_448 ) {
int V_122 ;
if ( F_43 ( V_75 , V_30 -> V_88 ) )
V_122 = V_449 ;
else
V_122 = V_450 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
V_30 -> V_47 . V_451 = 1 ;
V_30 -> V_452 [ 0 ] . V_141 = V_75 ;
V_30 -> V_452 [ 0 ] . V_90 = V_90 ;
}
}
static void F_239 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_47 . V_451 )
F_238 ( V_2 , V_75 , V_90 ) ;
else
F_237 ( V_30 -> V_452 , V_75 , V_90 ) ;
}
static void F_240 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_453 ) ;
F_10 ( V_2 ) ;
if ( F_141 ( V_30 ) && V_448 ) {
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
int V_454 ;
struct V_199 * V_154 = & V_30 -> V_455 [ 0 ] ;
struct V_199 * V_456 = V_154 + 1 ;
for ( V_454 = 1 ; V_454 < V_30 -> V_47 . V_155 ; ) {
if ( F_237 ( V_154 , V_456 -> V_141 , V_456 -> V_90 ) ) {
int V_213 ;
V_30 -> V_47 . V_155 -- ;
for ( V_213 = V_454 ; V_213 < V_30 -> V_47 . V_155 ; V_213 ++ )
V_154 [ V_213 ] = V_154 [ V_213 + 1 ] ;
continue;
}
V_454 ++ , V_456 ++ ;
}
}
static void F_242 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_199 * V_154 = & V_30 -> V_455 [ 0 ] ;
int V_457 = V_30 -> V_47 . V_155 ;
int V_454 ;
if ( ! V_457 )
goto V_458;
for ( V_454 = 0 ; V_454 < V_457 ; V_454 ++ , V_154 ++ ) {
if ( F_237 ( V_154 , V_75 , V_90 ) ) {
for (; V_454 > 0 ; V_454 -- , V_154 -- )
F_114 ( * V_154 , * ( V_154 - 1 ) ) ;
if ( V_457 > 1 )
F_241 ( V_30 ) ;
return;
}
}
if ( V_454 >= V_209 ) {
V_454 -- ;
V_30 -> V_47 . V_155 -- ;
V_154 -- ;
}
for (; V_454 > 0 ; V_454 -- , V_154 -- )
* V_154 = * ( V_154 - 1 ) ;
V_458:
V_154 -> V_141 = V_75 ;
V_154 -> V_90 = V_90 ;
V_30 -> V_47 . V_155 ++ ;
}
static void F_243 ( struct V_29 * V_30 )
{
struct V_199 * V_154 = & V_30 -> V_455 [ 0 ] ;
int V_155 = V_30 -> V_47 . V_155 ;
int V_454 ;
if ( F_244 ( & V_30 -> V_442 ) ) {
V_30 -> V_47 . V_155 = 0 ;
return;
}
for ( V_454 = 0 ; V_454 < V_155 ; ) {
if ( ! F_43 ( V_30 -> V_88 , V_154 -> V_141 ) ) {
int V_213 ;
F_112 ( F_43 ( V_30 -> V_88 , V_154 -> V_90 ) ) ;
for ( V_213 = V_454 + 1 ; V_213 < V_155 ; V_213 ++ )
V_30 -> V_455 [ V_213 - 1 ] = V_30 -> V_455 [ V_213 ] ;
V_155 -- ;
continue;
}
V_454 ++ ;
V_154 ++ ;
}
V_30 -> V_47 . V_155 = V_155 ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_459 = V_30 -> V_88 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_246 ( & V_30 -> V_442 ) ) != NULL ) {
if ( F_50 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) )
break;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_459 ) ) {
T_3 V_451 = V_459 ;
if ( F_43 ( F_16 ( V_4 ) -> V_90 , V_459 ) )
V_459 = F_16 ( V_4 ) -> V_90 ;
F_239 ( V_2 , F_16 ( V_4 ) -> V_75 , V_451 ) ;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_211 ( V_2 , L_16 ) ;
F_247 ( V_4 , & V_30 -> V_442 ) ;
F_248 ( V_4 ) ;
continue;
}
F_211 ( V_2 , L_17 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_247 ( V_4 , & V_30 -> V_442 ) ;
F_249 ( & V_2 -> V_460 , V_4 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( F_6 ( V_4 ) -> V_461 )
F_230 ( V_2 ) ;
}
}
static int F_250 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_462 )
{
if ( F_38 ( & V_2 -> V_79 ) > V_2 -> V_67 ||
! F_251 ( V_2 , V_4 , V_462 ) ) {
if ( F_252 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_251 ( V_2 , V_4 , V_462 ) ) {
if ( ! F_253 ( V_2 ) )
return - 1 ;
if ( ! F_251 ( V_2 , V_4 , V_462 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_254 ( struct V_1 * V_2 ,
struct V_3 * V_463 ,
struct V_3 * V_464 ,
bool * V_465 )
{
int V_290 ;
* V_465 = false ;
if ( F_6 ( V_464 ) -> V_461 )
return false ;
if ( F_16 ( V_464 ) -> V_75 != F_16 ( V_463 ) -> V_90 )
return false ;
if ( ! F_255 ( V_463 , V_464 , V_465 , & V_290 ) )
return false ;
F_256 ( V_290 , & V_2 -> V_79 ) ;
F_257 ( V_2 , V_290 ) ;
F_66 ( F_67 ( V_2 ) , V_466 ) ;
F_16 ( V_463 ) -> V_90 = F_16 ( V_464 ) -> V_90 ;
F_16 ( V_463 ) -> V_149 = F_16 ( V_464 ) -> V_149 ;
return true ;
}
static void F_258 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_467 ;
T_1 V_75 , V_90 ;
F_15 ( V_30 , V_4 ) ;
if ( F_100 ( F_250 ( V_2 , V_4 , V_4 -> V_57 ) ) ) {
F_66 ( F_67 ( V_2 ) , V_468 ) ;
F_248 ( V_4 ) ;
return;
}
V_30 -> V_354 = 0 ;
F_47 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_469 ) ;
F_211 ( V_2 , L_18 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_467 = F_259 ( & V_30 -> V_442 ) ;
if ( ! V_467 ) {
if ( F_141 ( V_30 ) ) {
V_30 -> V_47 . V_155 = 1 ;
V_30 -> V_455 [ 0 ] . V_141 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_455 [ 0 ] . V_90 =
F_16 ( V_4 ) -> V_90 ;
}
F_260 ( & V_30 -> V_442 , V_4 ) ;
goto V_470;
}
V_75 = F_16 ( V_4 ) -> V_75 ;
V_90 = F_16 ( V_4 ) -> V_90 ;
if ( V_75 == F_16 ( V_467 ) -> V_90 ) {
bool V_465 ;
if ( ! F_254 ( V_2 , V_467 , V_4 , & V_465 ) ) {
F_261 ( & V_30 -> V_442 , V_467 , V_4 ) ;
} else {
F_26 ( V_2 , V_4 ) ;
F_262 ( V_4 , V_465 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_47 . V_155 ||
V_30 -> V_455 [ 0 ] . V_90 != V_75 )
goto V_471;
V_30 -> V_455 [ 0 ] . V_90 = V_90 ;
goto V_470;
}
while ( 1 ) {
if ( ! F_50 ( F_16 ( V_467 ) -> V_75 , V_75 ) )
break;
if ( F_263 ( & V_30 -> V_442 , V_467 ) ) {
V_467 = NULL ;
break;
}
V_467 = F_264 ( & V_30 -> V_442 , V_467 ) ;
}
if ( V_467 && F_43 ( V_75 , F_16 ( V_467 ) -> V_90 ) ) {
if ( ! F_50 ( V_90 , F_16 ( V_467 ) -> V_90 ) ) {
F_66 ( F_67 ( V_2 ) , V_472 ) ;
F_248 ( V_4 ) ;
V_4 = NULL ;
F_238 ( V_2 , V_75 , V_90 ) ;
goto V_471;
}
if ( F_50 ( V_75 , F_16 ( V_467 ) -> V_75 ) ) {
F_238 ( V_2 , V_75 ,
F_16 ( V_467 ) -> V_90 ) ;
} else {
if ( F_263 ( & V_30 -> V_442 ,
V_467 ) )
V_467 = NULL ;
else
V_467 = F_264 (
& V_30 -> V_442 ,
V_467 ) ;
}
}
if ( ! V_467 )
F_260 ( & V_30 -> V_442 , V_4 ) ;
else
F_261 ( & V_30 -> V_442 , V_467 , V_4 ) ;
while ( ! F_265 ( & V_30 -> V_442 , V_4 ) ) {
V_467 = F_266 ( & V_30 -> V_442 , V_4 ) ;
if ( ! F_50 ( V_90 , F_16 ( V_467 ) -> V_75 ) )
break;
if ( F_43 ( V_90 , F_16 ( V_467 ) -> V_90 ) ) {
F_239 ( V_2 , F_16 ( V_467 ) -> V_75 ,
V_90 ) ;
break;
}
F_247 ( V_467 , & V_30 -> V_442 ) ;
F_239 ( V_2 , F_16 ( V_467 ) -> V_75 ,
F_16 ( V_467 ) -> V_90 ) ;
F_66 ( F_67 ( V_2 ) , V_472 ) ;
F_248 ( V_467 ) ;
}
V_471:
if ( F_141 ( V_30 ) )
F_242 ( V_2 , V_75 , V_90 ) ;
V_470:
if ( V_4 ) {
F_26 ( V_2 , V_4 ) ;
F_267 ( V_4 , V_2 ) ;
}
}
static int T_9 F_268 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_473 ,
bool * V_465 )
{
int V_474 ;
struct V_3 * V_475 = F_259 ( & V_2 -> V_460 ) ;
F_269 ( V_4 , V_473 ) ;
V_474 = ( V_475 &&
F_254 ( V_2 , V_475 , V_4 , V_465 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( ! V_474 ) {
F_249 ( & V_2 -> V_460 , V_4 ) ;
F_267 ( V_4 , V_2 ) ;
}
return V_474 ;
}
int F_270 ( struct V_1 * V_2 , struct V_476 * V_263 , T_10 V_462 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_465 ;
if ( V_462 == 0 )
return 0 ;
V_4 = F_271 ( V_462 + sizeof( * V_41 ) , V_2 -> V_477 ) ;
if ( ! V_4 )
goto V_164;
if ( F_250 ( V_2 , V_4 , V_462 + sizeof( * V_41 ) ) )
goto V_478;
V_41 = (struct V_15 * ) F_272 ( V_4 , sizeof( * V_41 ) ) ;
F_273 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_274 ( F_272 ( V_4 , V_462 ) , V_263 -> V_479 , V_462 ) )
goto V_478;
F_16 ( V_4 ) -> V_75 = F_7 ( V_2 ) -> V_88 ;
F_16 ( V_4 ) -> V_90 = F_16 ( V_4 ) -> V_75 + V_462 ;
F_16 ( V_4 ) -> V_149 = F_7 ( V_2 ) -> V_103 - 1 ;
if ( F_268 ( V_2 , V_4 , sizeof( * V_41 ) , & V_465 ) ) {
F_189 ( V_465 ) ;
F_248 ( V_4 ) ;
}
return V_462 ;
V_478:
F_275 ( V_4 ) ;
V_164:
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
F_269 ( V_4 , V_41 -> V_386 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_47 . V_451 = 0 ;
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 ) {
if ( F_225 ( V_30 ) == 0 )
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
F_250 ( V_2 , V_4 , V_4 -> V_57 ) )
goto V_481;
V_474 = F_268 ( V_2 , V_4 , 0 , & V_465 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( V_4 -> V_10 )
F_46 ( V_2 , V_4 ) ;
if ( V_41 -> V_461 )
F_230 ( V_2 ) ;
if ( ! F_244 ( & V_30 -> V_442 ) ) {
F_245 ( V_2 ) ;
if ( F_244 ( & V_30 -> V_442 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_47 . V_155 )
F_243 ( V_30 ) ;
F_199 ( V_2 ) ;
if ( V_474 > 0 )
F_262 ( V_4 , V_465 ) ;
if ( ! F_228 ( V_2 , V_429 ) )
V_2 -> V_491 ( V_2 ) ;
return;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_453 ) ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_482:
F_10 ( V_2 ) ;
F_47 ( V_2 ) ;
V_481:
F_248 ( V_4 ) ;
return;
}
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 + F_225 ( V_30 ) ) )
goto V_482;
F_10 ( V_2 ) ;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_211 ( V_2 , L_19 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ;
if ( ! F_225 ( V_30 ) )
goto V_482;
goto V_490;
}
F_258 ( V_2 , V_4 ) ;
}
static struct V_3 * F_283 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_492 * V_493 )
{
struct V_3 * V_494 = NULL ;
if ( ! F_265 ( V_493 , V_4 ) )
V_494 = F_266 ( V_493 , V_4 ) ;
F_247 ( V_4 , V_493 ) ;
F_248 ( V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_495 ) ;
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
if ( ! F_265 ( V_493 , V_4 ) ) {
struct V_3 * V_494 = F_266 ( V_493 , V_4 ) ;
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
V_501 = F_271 ( V_503 + V_502 , V_169 ) ;
if ( ! V_501 )
return;
F_288 ( V_501 , F_289 ( V_4 ) - V_4 -> V_496 ) ;
F_290 ( V_501 , ( F_291 ( V_4 ) -
V_4 -> V_496 ) ) ;
F_292 ( V_501 , ( F_4 ( V_4 ) -
V_4 -> V_496 ) ) ;
F_293 ( V_501 , V_502 ) ;
memcpy ( V_501 -> V_496 , V_4 -> V_496 , V_502 ) ;
memcpy ( V_501 -> V_504 , V_4 -> V_504 , sizeof( V_4 -> V_504 ) ) ;
F_16 ( V_501 ) -> V_75 = F_16 ( V_501 ) -> V_90 = V_497 ;
F_294 ( V_493 , V_4 , V_501 ) ;
F_267 ( V_501 , V_2 ) ;
while ( V_503 > 0 ) {
int V_505 = V_497 - F_16 ( V_4 ) -> V_75 ;
int V_462 = F_16 ( V_4 ) -> V_90 - V_497 ;
F_89 ( V_505 < 0 ) ;
if ( V_462 > 0 ) {
V_462 = F_9 ( V_503 , V_462 ) ;
if ( F_295 ( V_4 , V_505 , F_272 ( V_501 , V_462 ) , V_462 ) )
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
struct V_3 * V_4 = F_246 ( & V_30 -> V_442 ) ;
struct V_3 * V_496 ;
T_1 V_497 , V_470 ;
if ( V_4 == NULL )
return;
V_497 = F_16 ( V_4 ) -> V_75 ;
V_470 = F_16 ( V_4 ) -> V_90 ;
V_496 = V_4 ;
for (; ; ) {
struct V_3 * V_494 = NULL ;
if ( ! F_265 ( & V_30 -> V_442 , V_4 ) )
V_494 = F_266 ( & V_30 -> V_442 , V_4 ) ;
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
static bool F_253 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_506 = false ;
if ( ! F_244 ( & V_30 -> V_442 ) ) {
F_66 ( F_67 ( V_2 ) , V_507 ) ;
F_235 ( & V_30 -> V_442 ) ;
if ( V_30 -> V_47 . V_117 )
F_215 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
V_506 = true ;
}
return V_506 ;
}
static int F_252 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_211 ( V_2 , L_20 , V_30 -> V_76 ) ;
F_66 ( F_67 ( V_2 ) , V_508 ) ;
if ( F_38 ( & V_2 -> V_79 ) >= V_2 -> V_67 )
F_35 ( V_2 ) ;
else if ( F_28 ( V_2 ) )
V_30 -> V_60 = F_9 ( V_30 -> V_60 , 4U * V_30 -> V_63 ) ;
F_297 ( V_2 ) ;
if ( ! F_244 ( & V_2 -> V_460 ) )
F_284 ( V_2 , & V_2 -> V_460 ,
F_246 ( & V_2 -> V_460 ) ,
NULL ,
V_30 -> V_76 , V_30 -> V_88 ) ;
F_48 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_253 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_66 ( F_67 ( V_2 ) , V_509 ) ;
V_30 -> V_354 = 0 ;
return - 1 ;
}
static bool F_298 ( const struct V_1 * V_2 )
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
static void F_299 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_298 ( V_2 ) ) {
F_20 ( V_2 ) ;
V_30 -> V_78 = V_74 ;
}
V_2 -> V_510 ( V_2 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
if ( F_228 ( V_2 , V_511 ) ) {
F_301 ( V_2 , V_511 ) ;
if ( V_2 -> V_512 &&
F_302 ( V_513 , & V_2 -> V_512 -> V_514 ) )
F_299 ( V_2 ) ;
}
}
static inline void F_303 ( struct V_1 * V_2 )
{
F_304 ( V_2 ) ;
F_300 ( V_2 ) ;
}
static void F_305 ( struct V_1 * V_2 , int V_515 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_88 - V_30 -> V_363 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_306 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_515 && F_246 ( & V_30 -> V_442 ) ) ) {
F_201 ( V_2 ) ;
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
T_1 V_207 = F_149 ( V_41 -> V_516 ) ;
if ( V_207 && ! V_517 )
V_207 -- ;
V_207 += F_219 ( V_41 -> V_75 ) ;
if ( F_50 ( V_30 -> V_76 , V_207 ) )
return;
if ( F_43 ( V_207 , V_30 -> V_88 ) )
return;
if ( V_30 -> V_486 && ! F_50 ( V_207 , V_30 -> V_518 ) )
return;
F_311 ( V_2 ) ;
if ( V_30 -> V_518 == V_30 -> V_76 && V_30 -> V_486 &&
! F_228 ( V_2 , V_519 ) && V_30 -> V_76 != V_30 -> V_88 ) {
struct V_3 * V_4 = F_246 ( & V_2 -> V_460 ) ;
V_30 -> V_76 ++ ;
if ( V_4 && ! F_43 ( V_30 -> V_76 , F_16 ( V_4 ) -> V_90 ) ) {
F_247 ( V_4 , & V_2 -> V_460 ) ;
F_248 ( V_4 ) ;
}
}
V_30 -> V_486 = V_520 ;
V_30 -> V_518 = V_207 ;
V_30 -> V_354 = 0 ;
}
static void F_312 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_521 )
F_310 ( V_2 , V_41 ) ;
if ( V_30 -> V_486 == V_520 ) {
T_1 V_207 = V_30 -> V_518 - F_219 ( V_41 -> V_75 ) + ( V_41 -> V_386 * 4 ) -
V_41 -> V_43 ;
if ( V_207 < V_4 -> V_10 ) {
T_4 V_202 ;
if ( F_295 ( V_4 , V_207 , & V_202 , 1 ) )
F_296 () ;
V_30 -> V_486 = V_522 | V_202 ;
if ( ! F_228 ( V_2 , V_429 ) )
V_2 -> V_491 ( V_2 ) ;
}
}
}
static int F_313 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_523 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_487 = V_4 -> V_10 - V_523 ;
int V_164 ;
F_280 () ;
if ( F_314 ( V_4 ) )
V_164 = F_281 ( V_4 , V_523 , V_30 -> V_483 . V_489 , V_487 ) ;
else
V_164 = F_315 ( V_4 , V_523 ,
V_30 -> V_483 . V_489 ) ;
if ( ! V_164 ) {
V_30 -> V_483 . V_10 -= V_487 ;
V_30 -> V_76 += V_487 ;
F_45 ( V_2 ) ;
}
F_282 () ;
return V_164 ;
}
static T_11 F_316 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_524 ;
if ( F_278 ( V_2 ) ) {
F_280 () ;
V_524 = F_317 ( V_4 ) ;
F_282 () ;
} else {
V_524 = F_317 ( V_4 ) ;
}
return V_524 ;
}
static inline bool F_318 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_314 ( V_4 ) &&
F_316 ( V_2 , V_4 ) ;
}
static bool F_319 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_523 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_487 = V_4 -> V_10 - V_523 ;
int V_525 ;
bool V_526 = false ;
if ( V_30 -> V_483 . V_527 )
return false ;
if ( ! V_30 -> V_483 . V_528 && V_30 -> V_483 . V_529 )
V_30 -> V_483 . V_528 = F_320 () ;
if ( V_30 -> V_483 . V_528 && F_314 ( V_4 ) ) {
V_525 = F_321 ( V_30 -> V_483 . V_528 ,
V_4 , V_523 ,
V_30 -> V_483 . V_489 , V_487 ,
V_30 -> V_483 . V_529 ) ;
if ( V_525 < 0 )
goto V_197;
V_30 -> V_483 . V_525 = V_525 ;
V_526 = true ;
V_30 -> V_483 . V_10 -= V_487 ;
V_30 -> V_76 += V_487 ;
F_45 ( V_2 ) ;
if ( ( V_30 -> V_483 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_530 ) ||
( F_38 ( & V_2 -> V_79 ) > ( V_2 -> V_67 >> 1 ) ) ) {
V_30 -> V_483 . V_527 = 1 ;
V_2 -> V_491 ( V_2 ) ;
}
} else if ( V_487 > 0 ) {
V_30 -> V_483 . V_527 = 1 ;
V_2 -> V_491 ( V_2 ) ;
}
V_197:
return V_526 ;
}
static bool F_322 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_531 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_220 ( V_4 , V_41 , V_30 ) && V_30 -> V_47 . V_262 &&
F_223 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_532 ) {
F_66 ( F_67 ( V_2 ) , V_533 ) ;
F_240 ( V_2 , V_4 ) ;
goto V_534;
}
}
if ( ! F_224 ( V_30 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ) {
if ( ! V_41 -> V_532 ) {
if ( V_41 -> V_43 )
goto V_535;
F_240 ( V_2 , V_4 ) ;
}
goto V_534;
}
if ( V_41 -> V_532 ) {
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 )
F_226 ( V_2 ) ;
else
F_200 ( V_2 ) ;
goto V_534;
}
if ( V_41 -> V_43 ) {
V_535:
if ( V_531 )
F_323 ( F_67 ( V_2 ) , V_536 ) ;
F_66 ( F_67 ( V_2 ) , V_537 ) ;
F_200 ( V_2 ) ;
goto V_534;
}
return true ;
V_534:
F_248 ( V_4 ) ;
return false ;
}
void F_324 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_100 ( V_2 -> V_538 == NULL ) )
F_2 ( V_2 ) -> V_539 -> V_540 ( V_2 , V_4 ) ;
V_30 -> V_47 . V_262 = 0 ;
if ( ( F_5 ( V_41 ) & V_541 ) == V_30 -> V_354 &&
F_16 ( V_4 ) -> V_75 == V_30 -> V_88 &&
! F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_105 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_418 ) {
if ( ! F_217 ( V_30 , V_41 ) )
goto V_542;
if ( ( T_5 ) ( V_30 -> V_47 . V_361 - V_30 -> V_47 . V_360 ) < 0 )
goto V_542;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_418 ) &&
V_30 -> V_88 == V_30 -> V_363 )
F_202 ( V_30 ) ;
F_207 ( V_2 , V_4 , 0 ) ;
F_248 ( V_4 ) ;
F_303 ( V_2 ) ;
return;
} else {
F_323 ( F_67 ( V_2 ) , V_536 ) ;
goto V_534;
}
} else {
int V_474 = 0 ;
int V_526 = 0 ;
bool V_465 = false ;
if ( V_30 -> V_76 == V_30 -> V_88 &&
V_10 - V_18 <= V_30 -> V_483 . V_10 ) {
#ifdef F_325
if ( V_30 -> V_483 . V_484 == V_485 &&
F_278 ( V_2 ) &&
F_319 ( V_2 , V_4 , V_18 ) ) {
V_526 = 1 ;
V_474 = 1 ;
}
#endif
if ( V_30 -> V_483 . V_484 == V_485 &&
F_278 ( V_2 ) && ! V_526 ) {
F_279 ( V_488 ) ;
if ( ! F_313 ( V_2 , V_4 , V_18 ) )
V_474 = 1 ;
}
if ( V_474 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_418 ) &&
V_30 -> V_88 == V_30 -> V_363 )
F_202 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_269 ( V_4 , V_18 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
F_66 ( F_67 ( V_2 ) , V_543 ) ;
}
if ( V_526 )
F_326 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_474 ) {
if ( F_318 ( V_2 , V_4 ) )
goto V_544;
if ( ( int ) V_4 -> V_57 > V_2 -> V_545 )
goto V_546;
if ( V_18 ==
( sizeof( struct V_15 ) + V_418 ) &&
V_30 -> V_88 == V_30 -> V_363 )
F_202 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_547 ) ;
V_474 = F_268 ( V_2 , V_4 , V_18 ,
& V_465 ) ;
}
F_46 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_149 != V_30 -> V_103 ) {
F_207 ( V_2 , V_4 , V_373 ) ;
F_303 ( V_2 ) ;
if ( ! F_309 ( V_2 ) )
goto V_548;
}
if ( ! V_526 || V_30 -> V_88 != V_30 -> V_363 )
F_305 ( V_2 , 0 ) ;
V_548:
#ifdef F_325
if ( V_526 )
F_249 ( & V_2 -> V_549 , V_4 ) ;
else
#endif
if ( V_474 )
F_262 ( V_4 , V_465 ) ;
V_2 -> V_491 ( V_2 ) ;
return;
}
}
V_542:
if ( V_10 < ( V_41 -> V_386 << 2 ) || F_318 ( V_2 , V_4 ) )
goto V_544;
if ( ! V_41 -> V_319 && ! V_41 -> V_532 )
goto V_534;
if ( ! F_322 ( V_2 , V_4 , V_41 , 1 ) )
return;
V_546:
if ( F_207 ( V_2 , V_4 , V_370 | V_369 ) < 0 )
goto V_534;
F_44 ( V_2 , V_4 ) ;
F_312 ( V_2 , V_4 , V_41 ) ;
F_276 ( V_2 , V_4 ) ;
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
return;
V_544:
F_323 ( F_67 ( V_2 ) , V_550 ) ;
F_323 ( F_67 ( V_2 ) , V_536 ) ;
V_534:
F_248 ( V_4 ) ;
}
void F_327 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_232 ( V_2 , V_435 ) ;
if ( V_4 != NULL ) {
V_6 -> V_539 -> V_540 ( V_2 , V_4 ) ;
F_328 ( V_2 , V_4 ) ;
}
V_6 -> V_539 -> V_551 ( V_2 ) ;
F_329 ( V_2 ) ;
F_330 ( V_2 ) ;
V_30 -> V_552 = V_74 ;
F_32 ( V_2 ) ;
if ( F_228 ( V_2 , V_553 ) )
F_331 ( V_2 , F_332 ( V_30 ) ) ;
if ( ! V_30 -> V_47 . V_352 )
F_333 ( V_30 , V_30 -> V_351 ) ;
else
V_30 -> V_354 = 0 ;
if ( ! F_228 ( V_2 , V_429 ) ) {
V_2 -> V_443 ( V_2 ) ;
F_236 ( V_2 , V_554 , V_555 ) ;
}
}
static bool F_334 ( struct V_1 * V_2 , struct V_3 * V_556 ,
struct V_383 * V_557 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_558 ? F_101 ( V_2 ) : NULL ;
T_6 V_64 = V_30 -> V_47 . V_48 ;
bool V_559 ;
if ( V_64 == V_30 -> V_47 . V_394 ) {
struct V_380 V_560 ;
F_335 ( & V_560 ) ;
V_560 . V_394 = V_560 . V_48 = 0 ;
F_212 ( V_556 , & V_560 , 0 , NULL ) ;
V_64 = V_560 . V_48 ;
}
if ( ! V_30 -> V_561 )
V_557 -> V_10 = - 1 ;
V_559 = ( V_557 -> V_10 <= 0 && V_13 && V_30 -> V_317 ) ;
F_336 ( V_2 , V_64 , V_557 , V_559 ) ;
if ( V_13 ) {
F_106 (data, sk) {
if ( V_13 == F_78 ( V_2 ) ||
F_337 ( V_2 , V_13 ) )
break;
}
F_183 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_562 ) ;
return true ;
}
V_30 -> V_563 = V_30 -> V_558 ;
if ( V_30 -> V_563 )
F_66 ( F_67 ( V_2 ) , V_564 ) ;
return false ;
}
static int F_338 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_383 V_384 = { . V_10 = - 1 } ;
int V_565 = V_30 -> V_47 . V_48 ;
F_212 ( V_4 , & V_30 -> V_47 , 0 , & V_384 ) ;
if ( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_417 ;
if ( V_41 -> V_319 ) {
if ( ! F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_103 ) ||
F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_105 ) )
goto V_566;
if ( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 &&
! F_190 ( V_30 -> V_47 . V_89 , V_30 -> V_261 ,
V_74 ) ) {
F_66 ( F_67 ( V_2 ) , V_567 ) ;
goto V_566;
}
if ( V_41 -> V_532 ) {
F_226 ( V_2 ) ;
goto V_534;
}
if ( ! V_41 -> V_43 )
goto V_568;
F_17 ( V_30 , V_41 ) ;
F_339 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_207 ( V_2 , V_4 , V_370 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_363 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_351 = F_149 ( V_41 -> V_58 ) ;
if ( ! V_30 -> V_47 . V_398 ) {
V_30 -> V_47 . V_352 = V_30 -> V_47 . V_569 = 0 ;
V_30 -> V_61 = F_9 ( V_30 -> V_61 , 65535U ) ;
}
if ( V_30 -> V_47 . V_262 ) {
V_30 -> V_47 . V_402 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_418 ;
V_30 -> V_63 -= V_418 ;
F_202 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_141 ( V_30 ) && V_570 )
F_340 ( V_30 ) ;
F_341 ( V_2 ) ;
F_169 ( V_2 , V_6 -> V_298 ) ;
F_39 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_342 () ;
F_327 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_561 || V_30 -> V_558 ) &&
F_334 ( V_2 , V_4 , & V_384 ) )
return - 1 ;
if ( V_2 -> V_571 ||
V_6 -> V_572 . V_573 ||
V_6 -> V_8 . V_26 ) {
F_47 ( V_2 ) ;
V_6 -> V_8 . V_95 = V_74 ;
F_10 ( V_2 ) ;
F_131 ( V_2 , V_574 ,
V_575 , V_244 ) ;
V_534:
F_248 ( V_4 ) ;
return 0 ;
} else {
F_201 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_532 ) {
goto V_568;
}
if ( V_30 -> V_47 . V_362 && V_30 -> V_47 . V_262 &&
F_343 ( & V_30 -> V_47 , 0 ) )
goto V_568;
if ( V_41 -> V_43 ) {
F_232 ( V_2 , V_434 ) ;
if ( V_30 -> V_47 . V_262 ) {
V_30 -> V_47 . V_402 = 1 ;
F_202 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_418 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_363 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_351 = F_149 ( V_41 -> V_58 ) ;
V_30 -> V_350 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_142 = V_30 -> V_351 ;
F_18 ( V_30 , V_41 ) ;
F_341 ( V_2 ) ;
F_169 ( V_2 , V_6 -> V_298 ) ;
F_39 ( V_2 ) ;
F_344 ( V_2 ) ;
#if 0
return -1;
#else
goto V_534;
#endif
}
V_568:
F_335 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_565 ;
goto V_534;
V_566:
F_335 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_565 ;
return 1 ;
}
int F_345 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_576 * V_577 ;
int V_578 = 0 ;
bool V_579 ;
T_1 V_316 ;
V_30 -> V_47 . V_262 = 0 ;
switch ( V_2 -> V_421 ) {
case V_427 :
goto V_534;
case V_580 :
if ( V_41 -> V_319 )
return 1 ;
if ( V_41 -> V_532 )
goto V_534;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_461 )
goto V_534;
if ( V_6 -> V_539 -> V_581 ( V_2 , V_4 ) < 0 )
return 1 ;
F_275 ( V_4 ) ;
return 0 ;
}
goto V_534;
case V_422 :
V_578 = F_338 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_578 >= 0 )
return V_578 ;
F_312 ( V_2 , V_4 , V_41 ) ;
F_248 ( V_4 ) ;
F_303 ( V_2 ) ;
return 0 ;
}
V_577 = V_30 -> V_321 ;
if ( V_577 != NULL ) {
F_189 ( V_2 -> V_421 != V_434 &&
V_2 -> V_421 != V_439 ) ;
if ( F_346 ( V_2 , V_4 , V_577 , NULL , true ) == NULL )
goto V_534;
}
if ( ! V_41 -> V_319 && ! V_41 -> V_532 )
goto V_534;
if ( ! F_322 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
V_579 = F_207 ( V_2 , V_4 , V_370 |
V_369 ) > 0 ;
switch ( V_2 -> V_421 ) {
case V_434 :
if ( ! V_579 )
return 1 ;
if ( V_577 ) {
V_316 = F_347 ( V_577 ) -> V_582 ;
V_30 -> V_317 = V_577 -> V_583 ;
F_348 ( V_2 , V_577 , false ) ;
} else {
V_316 = V_30 -> V_552 ;
V_6 -> V_539 -> V_551 ( V_2 ) ;
F_330 ( V_2 ) ;
F_341 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_32 ( V_2 ) ;
}
F_342 () ;
F_232 ( V_2 , V_435 ) ;
V_2 -> V_443 ( V_2 ) ;
if ( V_2 -> V_512 )
F_236 ( V_2 , V_554 , V_555 ) ;
V_30 -> V_103 = F_16 ( V_4 ) -> V_149 ;
V_30 -> V_351 = F_149 ( V_41 -> V_58 ) << V_30 -> V_47 . V_352 ;
F_339 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_181 ( V_2 , V_316 ) ;
if ( V_30 -> V_47 . V_402 )
V_30 -> V_63 -= V_418 ;
if ( V_577 ) {
F_183 ( V_2 ) ;
} else
F_329 ( V_2 ) ;
F_52 ( V_2 ) ;
V_30 -> V_552 = V_74 ;
F_39 ( V_2 ) ;
F_349 ( V_30 ) ;
break;
case V_439 : {
struct V_111 * V_112 ;
int V_584 ;
if ( V_577 != NULL ) {
if ( ! V_579 )
return 1 ;
F_348 ( V_2 , V_577 , false ) ;
F_183 ( V_2 ) ;
}
if ( V_30 -> V_103 != V_30 -> V_585 )
break;
F_232 ( V_2 , V_440 ) ;
V_2 -> V_431 |= V_586 ;
V_112 = F_208 ( V_2 ) ;
if ( V_112 )
F_209 ( V_112 ) ;
if ( ! F_228 ( V_2 , V_429 ) ) {
V_2 -> V_443 ( V_2 ) ;
break;
}
if ( V_30 -> V_587 < 0 ||
( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_50 ( F_16 ( V_4 ) -> V_90 - V_41 -> V_461 , V_30 -> V_88 ) ) ) {
F_229 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_588 ) ;
return 1 ;
}
V_584 = F_350 ( V_2 ) ;
if ( V_584 > V_589 ) {
F_331 ( V_2 , V_584 - V_589 ) ;
} else if ( V_41 -> V_461 || F_278 ( V_2 ) ) {
F_331 ( V_2 , V_584 ) ;
} else {
F_233 ( V_2 , V_440 , V_584 ) ;
goto V_534;
}
break;
}
case V_437 :
if ( V_30 -> V_103 == V_30 -> V_585 ) {
F_233 ( V_2 , V_441 , 0 ) ;
goto V_534;
}
break;
case V_438 :
if ( V_30 -> V_103 == V_30 -> V_585 ) {
F_351 ( V_2 ) ;
F_229 ( V_2 ) ;
goto V_534;
}
break;
}
F_312 ( V_2 , V_4 , V_41 ) ;
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
F_66 ( F_67 ( V_2 ) , V_588 ) ;
F_226 ( V_2 ) ;
return 1 ;
}
}
case V_435 :
F_276 ( V_2 , V_4 ) ;
V_578 = 1 ;
break;
}
if ( V_2 -> V_421 != V_427 ) {
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
}
if ( ! V_578 ) {
V_534:
F_248 ( V_4 ) ;
}
return 0 ;
}
