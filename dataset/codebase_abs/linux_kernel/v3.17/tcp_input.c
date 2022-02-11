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
void F_124 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_226 = false ;
bool V_227 ;
if ( V_6 -> V_129 <= V_228 ||
! F_50 ( V_30 -> V_178 , V_30 -> V_103 ) ||
( V_6 -> V_129 == V_222 && ! V_6 -> V_229 ) ) {
V_226 = true ;
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
V_4 = F_101 ( V_2 ) ;
V_227 = V_4 && ( F_16 ( V_4 ) -> V_137 & V_139 ) ;
if ( V_227 ) {
F_66 ( F_67 ( V_2 ) , V_236 ) ;
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
if ( ! ( F_16 ( V_4 ) -> V_137 & V_139 ) || V_227 ) {
F_16 ( V_4 ) -> V_137 &= ~ V_139 ;
F_16 ( V_4 ) -> V_137 |= V_138 ;
V_30 -> V_135 += F_72 ( V_4 ) ;
V_30 -> V_136 = F_16 ( V_4 ) -> V_90 ;
}
}
F_115 ( V_30 ) ;
if ( V_6 -> V_129 <= V_228 &&
V_30 -> V_131 >= V_237 )
V_30 -> V_54 = F_40 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_128 ( V_2 , V_222 ) ;
V_30 -> V_178 = V_30 -> V_105 ;
F_12 ( V_30 ) ;
V_30 -> V_238 = V_239 &&
( V_226 || V_6 -> V_229 ) &&
! F_2 ( V_2 ) -> V_240 . V_241 ;
}
static bool F_129 ( struct V_1 * V_2 , int V_179 )
{
if ( V_179 & V_242 ) {
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_243 = F_34 ( F_130 ( V_30 -> V_99 >> 4 ) ,
F_131 ( 10 ) ) ;
F_132 ( V_2 , V_244 ,
V_243 , V_245 ) ;
return true ;
}
return false ;
}
static inline int F_133 ( const struct V_29 * V_30 )
{
return F_65 ( V_30 ) ? V_30 -> V_131 + 1 : V_30 -> V_130 ;
}
static inline int F_134 ( const struct V_29 * V_30 )
{
return F_62 ( V_30 ) ? V_30 -> V_130 : V_30 -> V_131 + 1 ;
}
static bool F_135 ( struct V_1 * V_2 , int V_179 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_243 ;
if ( V_246 < 2 || V_246 > 3 ||
( V_179 & V_247 ) || ! V_30 -> V_99 )
return false ;
V_243 = F_34 ( F_130 ( V_30 -> V_99 >> 5 ) ,
F_131 ( 2 ) ) ;
if ( ! F_136 ( F_2 ( V_2 ) -> V_248 , ( V_249 + V_243 ) ) )
return false ;
F_132 ( V_2 , V_250 , V_243 ,
V_245 ) ;
return true ;
}
static bool F_137 ( struct V_1 * V_2 , int V_179 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_108 ;
if ( V_30 -> V_135 )
return true ;
if ( F_134 ( V_30 ) > V_30 -> V_54 )
return true ;
V_108 = V_30 -> V_108 ;
if ( V_108 <= V_30 -> V_54 &&
V_30 -> V_131 >= F_21 ( T_3 , V_108 / 2 , V_237 ) &&
! F_138 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_251 || V_252 ) &&
F_139 ( V_30 ) && F_134 ( V_30 ) > 1 &&
F_140 ( V_30 ) && ! F_78 ( V_2 ) )
return true ;
if ( V_30 -> V_253 && ! V_30 -> V_146 && V_30 -> V_131 &&
( V_30 -> V_108 >= ( V_30 -> V_131 + 1 ) && V_30 -> V_108 < 4 ) &&
! F_138 ( V_2 ) )
return ! F_135 ( V_2 , V_179 ) ;
return false ;
}
static void F_141 ( struct V_1 * V_2 , int V_254 , int V_255 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_143 , V_256 ;
int V_164 ;
unsigned int V_64 ;
const T_1 V_257 = F_140 ( V_30 ) ? V_30 -> V_105 : V_30 -> V_178 ;
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
if ( ( F_140 ( V_30 ) && ! F_62 ( V_30 ) ) ||
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
static void F_142 ( struct V_1 * V_2 , int V_258 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_65 ( V_30 ) ) {
F_141 ( V_2 , 1 , 1 ) ;
} else if ( F_62 ( V_30 ) ) {
int V_259 = V_30 -> V_130 - V_30 -> V_54 ;
if ( V_259 <= 0 )
V_259 = 1 ;
F_141 ( V_2 , V_259 , 0 ) ;
} else {
int V_260 = V_30 -> V_131 - V_30 -> V_54 ;
if ( V_260 >= 0 )
F_141 ( V_2 , V_260 , 0 ) ;
else if ( V_258 )
F_141 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_143 ( struct V_29 * V_30 )
{
V_30 -> V_53 = F_9 ( V_30 -> V_53 ,
F_116 ( V_30 ) + F_144 ( V_30 ) ) ;
V_30 -> V_78 = V_74 ;
}
static inline bool F_145 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_261 ||
( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 &&
F_43 ( V_30 -> V_47 . V_89 , V_30 -> V_261 ) ) ;
}
static void F_146 ( struct V_1 * V_2 , const char * V_263 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_264 * V_265 = F_147 ( V_2 ) ;
if ( V_2 -> V_266 == V_267 ) {
F_68 ( L_2 ,
V_263 ,
& V_265 -> V_268 , F_148 ( V_265 -> V_269 ) ,
V_30 -> V_53 , F_149 ( V_30 ) ,
V_30 -> V_231 , V_30 -> V_230 ,
V_30 -> V_108 ) ;
}
#if F_150 ( V_270 )
else if ( V_2 -> V_266 == V_271 ) {
struct V_272 * V_273 = F_151 ( V_2 ) ;
F_68 ( L_3 ,
V_263 ,
& V_273 -> V_274 , F_148 ( V_265 -> V_269 ) ,
V_30 -> V_53 , F_149 ( V_30 ) ,
V_30 -> V_231 , V_30 -> V_230 ,
V_30 -> V_108 ) ;
}
#endif
}
static void F_152 ( struct V_1 * V_2 , bool V_275 )
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
static inline bool F_153 ( const struct V_29 * V_30 )
{
return V_30 -> V_132 && ( ! V_30 -> V_133 || F_145 ( V_30 ) ) ;
}
static bool F_154 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_153 ( V_30 ) ) {
int V_122 ;
F_146 ( V_2 , F_2 ( V_2 ) -> V_129 == V_222 ? L_4 : L_5 ) ;
F_152 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_129 == V_222 )
V_122 = V_277 ;
else
V_122 = V_278 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
}
if ( V_30 -> V_103 == V_30 -> V_178 && F_65 ( V_30 ) ) {
F_143 ( V_30 ) ;
return true ;
}
F_128 ( V_2 , V_279 ) ;
return false ;
}
static bool F_155 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_132 && ! V_30 -> V_133 ) {
F_146 ( V_2 , L_6 ) ;
F_152 ( V_2 , false ) ;
F_66 ( F_67 ( V_2 ) , V_280 ) ;
return true ;
}
return false ;
}
static bool F_156 ( const struct V_1 * V_2 )
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
static bool F_157 ( struct V_1 * V_2 , bool V_281 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_281 || F_153 ( V_30 ) ) {
F_152 ( V_2 , true ) ;
F_146 ( V_2 , L_7 ) ;
F_66 ( F_67 ( V_2 ) , V_277 ) ;
if ( V_281 )
F_66 ( F_67 ( V_2 ) ,
V_282 ) ;
F_2 ( V_2 ) -> V_229 = 0 ;
if ( V_281 || F_140 ( V_30 ) )
F_128 ( V_2 , V_279 ) ;
return true ;
}
return false ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_178 = V_30 -> V_105 ;
V_30 -> V_283 = 0 ;
V_30 -> V_235 = 0 ;
V_30 -> V_284 = V_30 -> V_53 ;
V_30 -> V_285 = 0 ;
V_30 -> V_286 = 0 ;
V_30 -> V_231 = F_2 ( V_2 ) -> V_232 -> V_233 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_159 ( struct V_1 * V_2 , const int V_287 ,
int V_258 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_288 = 0 ;
int V_289 = V_30 -> V_231 - F_116 ( V_30 ) ;
int V_290 = V_287 -
( V_30 -> V_108 - V_30 -> V_131 ) ;
V_30 -> V_285 += V_290 ;
if ( F_116 ( V_30 ) > V_30 -> V_231 ) {
T_2 V_291 = ( T_2 ) V_30 -> V_231 * V_30 -> V_285 +
V_30 -> V_284 - 1 ;
V_288 = F_160 ( V_291 , V_30 -> V_284 ) - V_30 -> V_286 ;
} else {
V_288 = F_40 ( int , V_289 ,
F_21 ( int , V_30 -> V_285 - V_30 -> V_286 ,
V_290 ) + 1 ) ;
}
V_288 = F_34 ( V_288 , ( V_258 ? 1 : 0 ) ) ;
V_30 -> V_53 = F_116 ( V_30 ) + V_288 ;
}
static inline void F_161 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_129 == V_292 ||
( V_30 -> V_132 && V_30 -> V_231 < V_293 ) ) {
V_30 -> V_53 = V_30 -> V_231 ;
V_30 -> V_78 = V_74 ;
}
F_126 ( V_2 , V_294 ) ;
}
void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_230 = 0 ;
if ( F_2 ( V_2 ) -> V_129 < V_292 ) {
V_30 -> V_132 = 0 ;
F_158 ( V_2 ) ;
F_128 ( V_2 , V_292 ) ;
}
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_171 = V_279 ;
if ( F_149 ( V_30 ) || F_156 ( V_2 ) )
V_171 = V_228 ;
if ( F_2 ( V_2 ) -> V_129 != V_171 ) {
F_128 ( V_2 , V_171 ) ;
V_30 -> V_178 = V_30 -> V_105 ;
}
}
static void F_164 ( struct V_1 * V_2 , int V_179 , const int V_287 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ! F_156 ( V_2 ) )
V_30 -> V_261 = 0 ;
if ( V_179 & V_247 )
F_162 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_129 != V_292 ) {
F_163 ( V_2 ) ;
} else {
F_159 ( V_2 , V_287 , 0 ) ;
}
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_240 . V_295 = V_6 -> V_240 . V_241 - 1 ;
V_6 -> V_240 . V_241 = 0 ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_230 = F_125 ( V_2 ) ;
V_30 -> V_53 = V_30 -> V_53 *
F_167 ( V_2 , V_30 -> V_49 ) /
V_6 -> V_240 . V_241 ;
V_30 -> V_235 = 0 ;
V_30 -> V_78 = V_74 ;
V_30 -> V_231 = F_125 ( V_2 ) ;
V_6 -> V_240 . V_296 = V_6 -> V_240 . V_241 ;
V_6 -> V_240 . V_241 = 0 ;
F_168 ( V_2 , V_6 -> V_297 ) ;
}
void F_169 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_64 = F_170 ( V_2 ) ;
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
F_171 ( V_30 ) ;
if ( V_298 == V_30 -> V_135 )
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
F_172 ( V_2 ) ;
}
static void F_173 ( struct V_1 * V_2 , bool V_299 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_122 ;
if ( F_65 ( V_30 ) )
V_122 = V_300 ;
else
V_122 = V_301 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
V_30 -> V_230 = 0 ;
V_30 -> V_132 = V_30 -> V_103 ;
V_30 -> V_133 = V_30 -> V_146 ? : - 1 ;
if ( F_2 ( V_2 ) -> V_129 < V_292 ) {
if ( ! V_299 )
V_30 -> V_230 = F_125 ( V_2 ) ;
F_158 ( V_2 ) ;
}
F_128 ( V_2 , V_148 ) ;
}
static void F_174 ( struct V_1 * V_2 , int V_179 , bool V_302 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_303 = ! F_43 ( V_30 -> V_103 , V_30 -> V_178 ) ;
if ( V_30 -> V_238 ) {
if ( F_157 ( V_2 , V_179 & V_180 ) )
return;
if ( F_50 ( V_30 -> V_105 , V_30 -> V_178 ) &&
( V_179 & V_182 || V_302 ) ) {
V_30 -> V_238 = 0 ;
} else if ( V_179 & V_304 && ! V_303 ) {
V_30 -> V_178 = V_30 -> V_105 ;
F_175 ( V_2 , F_170 ( V_2 ) ,
V_305 ) ;
if ( F_50 ( V_30 -> V_105 , V_30 -> V_178 ) )
return;
V_30 -> V_238 = 0 ;
}
}
if ( V_303 ) {
F_154 ( V_2 ) ;
return;
}
if ( F_65 ( V_30 ) ) {
if ( F_50 ( V_30 -> V_105 , V_30 -> V_178 ) && V_302 )
F_119 ( V_2 ) ;
else if ( V_179 & V_304 )
F_121 ( V_30 ) ;
}
if ( F_157 ( V_2 , false ) )
return;
F_172 ( V_2 ) ;
}
static bool F_176 ( struct V_1 * V_2 , const int V_225 ,
const int V_287 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_132 && F_145 ( V_30 ) ) {
F_64 ( V_2 , F_133 ( V_30 ) + V_225 , 1 ) ;
if ( V_30 -> V_146 ) {
F_159 ( V_2 , V_287 , 0 ) ;
return true ;
}
if ( ! F_156 ( V_2 ) )
V_30 -> V_261 = 0 ;
F_146 ( V_2 , L_8 ) ;
F_152 ( V_2 , true ) ;
F_66 ( F_67 ( V_2 ) , V_306 ) ;
F_163 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_177 ( struct V_1 * V_2 , const int V_225 ,
const int V_287 ,
bool V_302 , int V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_307 = V_302 || ( ( V_179 & V_182 ) &&
( F_133 ( V_30 ) > V_30 -> V_54 ) ) ;
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
case V_292 :
if ( V_30 -> V_103 != V_30 -> V_178 ) {
F_161 ( V_2 ) ;
F_128 ( V_2 , V_279 ) ;
}
break;
case V_148 :
if ( F_65 ( V_30 ) )
F_121 ( V_30 ) ;
if ( F_154 ( V_2 ) )
return;
F_161 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_129 ) {
case V_148 :
if ( ! ( V_179 & V_304 ) ) {
if ( F_65 ( V_30 ) && V_302 )
F_119 ( V_2 ) ;
} else {
if ( F_176 ( V_2 , V_225 , V_287 ) )
return;
V_307 = F_65 ( V_30 ) ||
F_133 ( V_30 ) > V_30 -> V_54 ;
}
if ( F_155 ( V_2 ) ) {
F_163 ( V_2 ) ;
return;
}
break;
case V_222 :
F_174 ( V_2 , V_179 , V_302 ) ;
if ( V_6 -> V_129 != V_279 )
return;
default:
if ( F_65 ( V_30 ) ) {
if ( V_179 & V_304 )
F_121 ( V_30 ) ;
if ( V_302 )
F_119 ( V_2 ) ;
}
if ( V_6 -> V_129 <= V_228 )
F_155 ( V_2 ) ;
if ( ! F_137 ( V_2 , V_179 ) ) {
F_164 ( V_2 , V_179 , V_287 ) ;
return;
}
if ( V_6 -> V_129 < V_292 &&
V_6 -> V_240 . V_241 &&
V_30 -> V_103 == V_30 -> V_308 . V_309 ) {
F_165 ( V_2 ) ;
V_30 -> V_53 ++ ;
F_169 ( V_2 ) ;
return;
}
F_173 ( V_2 , ( V_179 & V_247 ) ) ;
V_258 = 1 ;
}
if ( V_307 )
F_142 ( V_2 , V_258 ) ;
F_159 ( V_2 , V_287 , V_258 ) ;
F_172 ( V_2 ) ;
}
static inline bool F_178 ( struct V_1 * V_2 , const int V_179 ,
long V_310 , long V_206 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_179 & V_311 )
V_310 = - 1L ;
if ( V_310 < 0 )
V_310 = V_206 ;
if ( V_310 < 0 && V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 &&
V_179 & V_312 )
V_310 = F_179 ( V_74 - V_30 -> V_47 . V_89 ) ;
if ( V_310 < 0 )
return false ;
F_49 ( V_2 , V_310 ) ;
F_56 ( V_2 ) ;
F_2 ( V_2 ) -> V_313 = 0 ;
return true ;
}
static void F_180 ( struct V_1 * V_2 , const T_1 V_314 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_310 = - 1L ;
if ( V_314 && ! V_30 -> V_315 )
V_310 = F_179 ( V_74 - V_314 ) ;
if ( ! V_30 -> V_99 )
F_178 ( V_2 , V_316 , V_310 , - 1L ) ;
}
static void F_181 ( struct V_1 * V_2 , T_1 V_317 , T_1 V_225 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_232 -> V_318 ( V_2 , V_317 , V_225 ) ;
F_7 ( V_2 ) -> V_78 = V_74 ;
}
void F_182 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_319 )
return;
if ( ! V_30 -> V_108 ) {
F_183 ( V_2 , V_244 ) ;
} else {
T_1 V_320 = F_2 ( V_2 ) -> V_96 ;
if ( V_6 -> V_321 == V_250 ||
V_6 -> V_321 == V_322 ) {
struct V_3 * V_4 = F_101 ( V_2 ) ;
const T_1 V_323 = F_16 ( V_4 ) -> V_324 + V_320 ;
T_5 V_289 = ( T_5 ) ( V_323 - V_74 ) ;
if ( V_289 > 0 )
V_320 = V_289 ;
}
F_132 ( V_2 , V_244 , V_320 ,
V_245 ) ;
}
}
void F_184 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_182 ( V_2 ) ;
if ( ! V_30 -> V_253 )
return;
F_173 ( V_2 , false ) ;
F_142 ( V_2 , 1 ) ;
F_172 ( V_2 ) ;
}
static T_1 F_185 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_325 ;
F_89 ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_103 ) ) ;
V_325 = F_72 ( V_4 ) ;
if ( F_186 ( V_2 , V_4 , V_30 -> V_103 - F_16 ( V_4 ) -> V_75 ) )
return 0 ;
V_325 -= F_72 ( V_4 ) ;
if ( V_325 ) {
F_89 ( F_72 ( V_4 ) == 0 ) ;
F_89 ( ! F_43 ( F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ) ;
}
return V_325 ;
}
static int F_187 ( struct V_1 * V_2 , int V_326 ,
T_1 V_156 , long V_206 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_173 V_327 , V_328 , V_94 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_329 = V_30 -> V_131 ;
T_1 V_177 = V_30 -> V_108 ;
bool V_330 = true ;
long V_331 = - 1L ;
long V_310 = - 1L ;
struct V_3 * V_4 ;
T_1 V_332 = 0 ;
bool V_333 ;
int V_179 = 0 ;
V_327 . V_334 = 0 ;
while ( ( V_4 = F_101 ( V_2 ) ) && V_4 != F_78 ( V_2 ) ) {
struct V_51 * V_335 = F_3 ( V_4 ) ;
struct V_336 * V_337 = F_16 ( V_4 ) ;
T_4 V_137 = V_337 -> V_137 ;
T_1 V_338 ;
if ( F_100 ( V_335 -> V_339 & V_340 ) &&
F_188 ( V_335 -> V_341 , V_156 , V_30 -> V_103 - 1 ) )
F_189 ( V_4 , NULL , V_2 , V_342 ) ;
if ( F_50 ( V_337 -> V_90 , V_30 -> V_103 ) ) {
if ( F_72 ( V_4 ) == 1 ||
! F_50 ( V_30 -> V_103 , V_337 -> V_75 ) )
break;
V_338 = F_185 ( V_2 , V_4 ) ;
if ( ! V_338 )
break;
V_330 = false ;
} else {
V_338 = F_72 ( V_4 ) ;
}
if ( V_137 & V_176 ) {
if ( V_137 & V_150 )
V_30 -> V_146 -= V_338 ;
V_179 |= V_311 ;
} else {
V_328 = V_4 -> V_173 ;
F_190 ( V_328 . V_334 == 0 ) ;
if ( ! V_327 . V_334 )
V_327 = V_328 ;
if ( ! ( V_137 & V_139 ) )
V_177 = F_9 ( V_332 , V_177 ) ;
if ( ! F_50 ( V_337 -> V_90 , V_30 -> V_178 ) )
V_179 |= V_180 ;
}
if ( V_137 & V_139 )
V_30 -> V_131 -= V_338 ;
if ( V_137 & V_138 )
V_30 -> V_135 -= V_338 ;
V_30 -> V_108 -= V_338 ;
V_332 += V_338 ;
if ( ! ( V_337 -> V_191 & V_343 ) ) {
V_179 |= V_344 ;
} else {
V_179 |= V_316 ;
V_30 -> V_261 = 0 ;
}
if ( ! V_330 )
break;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
if ( V_4 == V_30 -> V_134 )
V_30 -> V_134 = NULL ;
if ( V_4 == V_30 -> V_116 )
V_30 -> V_116 = NULL ;
}
if ( F_53 ( F_188 ( V_30 -> V_345 , V_156 , V_30 -> V_103 ) ) )
V_30 -> V_345 = V_30 -> V_103 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_137 & V_139 ) )
V_179 |= V_242 ;
F_85 ( & V_94 ) ;
if ( V_327 . V_334 ) {
V_310 = F_86 ( & V_94 , & V_327 ) ;
V_331 = F_86 ( & V_94 , & V_328 ) ;
}
V_333 = F_178 ( V_2 , V_179 , V_310 , V_206 ) ;
if ( V_179 & V_312 ) {
const struct V_346 * V_347
= F_2 ( V_2 ) -> V_232 ;
F_182 ( V_2 ) ;
if ( F_100 ( V_6 -> V_240 . V_241 &&
! F_50 ( V_30 -> V_308 . V_348 , V_30 -> V_103 ) ) ) {
F_166 ( V_2 ) ;
}
if ( F_65 ( V_30 ) ) {
F_120 ( V_2 , V_332 ) ;
} else {
int V_289 ;
if ( V_177 < V_326 )
F_64 ( V_2 , V_30 -> V_130 - V_177 , 0 ) ;
V_289 = F_62 ( V_30 ) ? V_332 :
V_329 - V_30 -> V_131 ;
V_30 -> V_183 -= F_9 ( V_30 -> V_183 , V_289 ) ;
}
V_30 -> V_130 -= F_9 ( V_332 , V_30 -> V_130 ) ;
if ( V_347 -> V_332 )
V_347 -> V_332 ( V_2 , V_332 , V_331 ) ;
} else if ( V_4 && V_333 && V_206 >= 0 &&
V_206 > F_86 ( & V_94 , & V_4 -> V_173 ) ) {
F_182 ( V_2 ) ;
}
#if V_128 > 0
F_112 ( ( int ) V_30 -> V_131 < 0 ) ;
F_112 ( ( int ) V_30 -> V_135 < 0 ) ;
F_112 ( ( int ) V_30 -> V_146 < 0 ) ;
if ( ! V_30 -> V_108 && F_140 ( V_30 ) ) {
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
V_6 -> V_313 = 0 ;
F_183 ( V_2 , V_349 ) ;
} else {
F_132 ( V_2 , V_349 ,
F_9 ( V_6 -> V_96 << V_6 -> V_313 , V_245 ) ,
V_245 ) ;
}
}
static inline bool F_193 ( const struct V_1 * V_2 , const int V_179 )
{
return ! ( V_179 & V_350 ) || ( V_179 & V_351 ) ||
F_2 ( V_2 ) -> V_129 != V_279 ;
}
static inline bool F_194 ( const struct V_1 * V_2 , const int V_179 )
{
if ( F_195 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_54 > V_237 )
return V_179 & V_352 ;
return V_179 & V_344 ;
}
static inline bool F_196 ( const struct V_29 * V_30 ,
const T_1 V_317 , const T_1 V_149 ,
const T_1 V_353 )
{
return F_50 ( V_317 , V_30 -> V_103 ) ||
F_50 ( V_149 , V_30 -> V_354 ) ||
( V_149 == V_30 -> V_354 && V_353 > V_30 -> V_355 ) ;
}
static int F_197 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_317 ,
T_1 V_149 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_179 = 0 ;
T_1 V_353 = F_148 ( F_6 ( V_4 ) -> V_58 ) ;
if ( F_53 ( ! F_6 ( V_4 ) -> V_43 ) )
V_353 <<= V_30 -> V_47 . V_356 ;
if ( F_196 ( V_30 , V_317 , V_149 , V_353 ) ) {
V_179 |= V_357 ;
F_198 ( V_30 , V_149 ) ;
if ( V_30 -> V_355 != V_353 ) {
V_30 -> V_355 = V_353 ;
V_30 -> V_358 = 0 ;
F_199 ( V_2 ) ;
if ( V_353 > V_30 -> V_142 ) {
V_30 -> V_142 = V_353 ;
F_168 ( V_2 , F_2 ( V_2 ) -> V_297 ) ;
}
}
}
V_30 -> V_103 = V_317 ;
return V_179 ;
}
static void F_200 ( struct V_1 * V_2 )
{
static T_1 V_359 ;
static unsigned int V_360 ;
T_1 V_94 = V_249 / V_361 ;
if ( V_94 != V_359 ) {
V_359 = V_94 ;
V_360 = 0 ;
}
if ( ++ V_360 <= V_362 ) {
F_66 ( F_67 ( V_2 ) , V_363 ) ;
F_201 ( V_2 ) ;
}
}
static void F_202 ( struct V_29 * V_30 )
{
V_30 -> V_47 . V_364 = V_30 -> V_47 . V_365 ;
V_30 -> V_47 . V_366 = F_203 () ;
}
static void F_204 ( struct V_29 * V_30 , T_1 V_75 )
{
if ( V_30 -> V_47 . V_262 && ! F_50 ( V_75 , V_30 -> V_367 ) ) {
if ( F_205 ( & V_30 -> V_47 , 0 ) )
F_202 ( V_30 ) ;
}
}
static void F_206 ( struct V_1 * V_2 , T_1 V_317 , int V_179 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_368 = ( V_317 == V_30 -> V_283 ) &&
! ( V_179 & ( V_304 |
V_350 | V_182 ) ) ;
if ( V_368 ) {
V_30 -> V_283 = 0 ;
return;
}
if ( F_50 ( V_317 , V_30 -> V_283 ) ) {
V_30 -> V_283 = 0 ;
if ( ! ( V_179 & V_216 ) ) {
F_158 ( V_2 ) ;
F_128 ( V_2 , V_292 ) ;
F_161 ( V_2 ) ;
F_163 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) ,
V_369 ) ;
}
}
}
static int F_207 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_179 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_156 = V_30 -> V_103 ;
T_1 V_149 = F_16 ( V_4 ) -> V_75 ;
T_1 V_317 = F_16 ( V_4 ) -> V_149 ;
bool V_302 = false ;
T_1 V_326 ;
int V_370 = V_30 -> V_108 ;
const int V_287 = V_30 -> V_108 - V_30 -> V_131 ;
int V_225 = 0 ;
long V_206 = - 1L ;
if ( F_43 ( V_317 , V_156 ) ) {
if ( F_43 ( V_317 , V_156 - V_30 -> V_142 ) ) {
F_200 ( V_2 ) ;
return - 1 ;
}
goto V_371;
}
if ( F_50 ( V_317 , V_30 -> V_105 ) )
goto V_372;
if ( V_6 -> V_321 == V_250 ||
V_6 -> V_321 == V_322 )
F_182 ( V_2 ) ;
if ( F_50 ( V_317 , V_156 ) ) {
V_179 |= V_304 ;
V_6 -> V_229 = 0 ;
}
V_326 = V_30 -> V_130 ;
if ( V_179 & V_373 )
F_204 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
if ( ! ( V_179 & V_374 ) && F_50 ( V_317 , V_156 ) ) {
F_198 ( V_30 , V_149 ) ;
V_30 -> V_103 = V_317 ;
V_179 |= V_357 ;
F_126 ( V_2 , V_375 ) ;
F_66 ( F_67 ( V_2 ) , V_376 ) ;
} else {
if ( V_149 != F_16 ( V_4 ) -> V_90 )
V_179 |= V_377 ;
else
F_66 ( F_67 ( V_2 ) , V_378 ) ;
V_179 |= F_197 ( V_2 , V_4 , V_317 , V_149 ) ;
if ( F_16 ( V_4 ) -> V_137 )
V_179 |= F_111 ( V_2 , V_4 , V_156 ,
& V_206 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_179 |= V_247 ;
F_126 ( V_2 , V_379 ) ;
}
V_2 -> V_380 = 0 ;
V_6 -> V_381 = 0 ;
V_30 -> V_382 = V_74 ;
if ( ! V_370 )
goto V_383;
V_225 = V_30 -> V_108 ;
V_179 |= F_187 ( V_2 , V_326 , V_156 ,
V_206 ) ;
V_225 -= V_30 -> V_108 ;
if ( F_194 ( V_2 , V_179 ) )
F_181 ( V_2 , V_317 , V_225 ) ;
if ( F_193 ( V_2 , V_179 ) ) {
V_302 = ! ( V_179 & ( V_304 | V_350 ) ) ;
F_177 ( V_2 , V_225 , V_287 ,
V_302 , V_179 ) ;
}
if ( V_30 -> V_283 )
F_206 ( V_2 , V_317 , V_179 ) ;
if ( ( V_179 & V_352 ) || ! ( V_179 & V_350 ) ) {
struct V_111 * V_112 = F_208 ( V_2 ) ;
if ( V_112 )
F_209 ( V_112 ) ;
}
if ( V_6 -> V_321 == V_244 )
F_210 ( V_2 ) ;
F_52 ( V_2 ) ;
return 1 ;
V_383:
if ( V_179 & V_216 )
F_177 ( V_2 , V_225 , V_287 ,
V_302 , V_179 ) ;
if ( F_78 ( V_2 ) )
F_191 ( V_2 ) ;
if ( V_30 -> V_283 )
F_206 ( V_2 , V_317 , V_179 ) ;
return 1 ;
V_372:
F_211 ( V_2 , L_12 , V_317 , V_30 -> V_103 , V_30 -> V_105 ) ;
return - 1 ;
V_371:
if ( F_16 ( V_4 ) -> V_137 ) {
V_179 |= F_111 ( V_2 , V_4 , V_156 ,
& V_206 ) ;
F_177 ( V_2 , V_225 , V_287 ,
V_302 , V_179 ) ;
}
F_211 ( V_2 , L_13 , V_317 , V_30 -> V_103 , V_30 -> V_105 ) ;
return 0 ;
}
void F_212 ( const struct V_3 * V_4 ,
struct V_384 * V_385 , int V_386 ,
struct V_387 * V_388 )
{
const unsigned char * V_207 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_389 = ( V_41 -> V_390 * 4 ) - sizeof( struct V_15 ) ;
V_207 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_385 -> V_262 = 0 ;
while ( V_389 > 0 ) {
int V_391 = * V_207 ++ ;
int V_392 ;
switch ( V_391 ) {
case V_393 :
return;
case V_394 :
V_389 -- ;
continue;
default:
V_392 = * V_207 ++ ;
if ( V_392 < 2 )
return;
if ( V_392 > V_389 )
return;
switch ( V_391 ) {
case V_395 :
if ( V_392 == V_396 && V_41 -> V_43 && ! V_386 ) {
T_6 V_397 = F_213 ( V_207 ) ;
if ( V_397 ) {
if ( V_385 -> V_398 &&
V_385 -> V_398 < V_397 )
V_397 = V_385 -> V_398 ;
V_385 -> V_48 = V_397 ;
}
}
break;
case V_399 :
if ( V_392 == V_400 && V_41 -> V_43 &&
! V_386 && V_401 ) {
T_7 V_356 = * ( T_7 * ) V_207 ;
V_385 -> V_402 = 1 ;
if ( V_356 > 14 ) {
F_214 ( L_14 ,
V_403 ,
V_356 ) ;
V_356 = 14 ;
}
V_385 -> V_356 = V_356 ;
}
break;
case V_404 :
if ( ( V_392 == V_405 ) &&
( ( V_386 && V_385 -> V_406 ) ||
( ! V_386 && V_407 ) ) ) {
V_385 -> V_262 = 1 ;
V_385 -> V_365 = F_80 ( V_207 ) ;
V_385 -> V_89 = F_80 ( V_207 + 4 ) ;
}
break;
case V_408 :
if ( V_392 == V_409 && V_41 -> V_43 &&
! V_386 && V_410 ) {
V_385 -> V_117 = V_411 ;
F_215 ( V_385 ) ;
}
break;
case V_412 :
if ( ( V_392 >= ( V_210 + V_413 ) ) &&
! ( ( V_392 - V_210 ) % V_413 ) &&
V_385 -> V_117 ) {
F_16 ( V_4 ) -> V_137 = ( V_207 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_216
case V_414 :
break;
#endif
case V_415 :
if ( V_392 < V_416 ||
F_213 ( V_207 ) != V_417 ||
V_388 == NULL || ! V_41 -> V_43 || ( V_392 & 1 ) )
break;
V_388 -> V_10 = V_392 - V_416 ;
if ( V_388 -> V_10 >= V_418 &&
V_388 -> V_10 <= V_419 )
memcpy ( V_388 -> V_420 , V_207 + 2 , V_388 -> V_10 ) ;
else if ( V_388 -> V_10 != 0 )
V_388 -> V_10 = - 1 ;
break;
}
V_207 += V_392 - 2 ;
V_389 -= V_392 ;
}
}
}
static bool F_217 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_8 * V_207 = ( const T_8 * ) ( V_41 + 1 ) ;
if ( * V_207 == F_218 ( ( V_394 << 24 ) | ( V_394 << 16 )
| ( V_404 << 8 ) | V_405 ) ) {
V_30 -> V_47 . V_262 = 1 ;
++ V_207 ;
V_30 -> V_47 . V_365 = F_219 ( * V_207 ) ;
++ V_207 ;
if ( * V_207 )
V_30 -> V_47 . V_89 = F_219 ( * V_207 ) - V_30 -> V_421 ;
else
V_30 -> V_47 . V_89 = 0 ;
return true ;
}
return false ;
}
static bool F_220 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 , struct V_29 * V_30 )
{
if ( V_41 -> V_390 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_47 . V_262 = 0 ;
return false ;
} else if ( V_30 -> V_47 . V_406 &&
V_41 -> V_390 == ( ( sizeof( * V_41 ) + V_422 ) / 4 ) ) {
if ( F_217 ( V_30 , V_41 ) )
return true ;
}
F_212 ( V_4 , & V_30 -> V_47 , 1 , NULL ) ;
if ( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_421 ;
return true ;
}
const T_4 * F_221 ( const struct V_15 * V_41 )
{
int V_389 = ( V_41 -> V_390 << 2 ) - sizeof( * V_41 ) ;
const T_4 * V_207 = ( const T_4 * ) ( V_41 + 1 ) ;
if ( V_389 < V_423 )
return NULL ;
while ( V_389 > 0 ) {
int V_391 = * V_207 ++ ;
int V_392 ;
switch ( V_391 ) {
case V_393 :
return NULL ;
case V_394 :
V_389 -- ;
continue;
default:
V_392 = * V_207 ++ ;
if ( V_392 < 2 || V_392 > V_389 )
return NULL ;
if ( V_391 == V_414 )
return V_392 == V_423 ? V_207 : NULL ;
}
V_207 += V_392 - 2 ;
V_389 -= V_392 ;
}
return NULL ;
}
static int F_222 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_75 = F_16 ( V_4 ) -> V_75 ;
T_1 V_317 = F_16 ( V_4 ) -> V_149 ;
return (
( V_41 -> V_317 && V_75 == F_16 ( V_4 ) -> V_90 && V_75 == V_30 -> V_88 ) &&
V_317 == V_30 -> V_103 &&
! F_196 ( V_30 , V_317 , V_75 , F_148 ( V_41 -> V_58 ) << V_30 -> V_47 . V_356 ) &&
( T_5 ) ( V_30 -> V_47 . V_364 - V_30 -> V_47 . V_365 ) <= ( F_2 ( V_2 ) -> V_96 * 1024 ) / V_361 ) ;
}
static inline bool F_223 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_205 ( & V_30 -> V_47 , V_424 ) &&
! F_222 ( V_2 , V_4 ) ;
}
static inline bool F_224 ( const struct V_29 * V_30 , T_1 V_75 , T_1 V_90 )
{
return ! F_43 ( V_90 , V_30 -> V_367 ) &&
! F_50 ( V_75 , V_30 -> V_88 + F_225 ( V_30 ) ) ;
}
void F_226 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_425 ) {
case V_426 :
V_2 -> V_427 = V_428 ;
break;
case V_429 :
V_2 -> V_427 = V_430 ;
break;
case V_431 :
return;
default:
V_2 -> V_427 = V_432 ;
}
F_227 () ;
if ( ! F_228 ( V_2 , V_433 ) )
V_2 -> V_434 ( V_2 ) ;
F_229 ( V_2 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_111 * V_112 ;
F_47 ( V_2 ) ;
V_2 -> V_435 |= V_436 ;
F_231 ( V_2 , V_437 ) ;
switch ( V_2 -> V_425 ) {
case V_438 :
case V_439 :
F_232 ( V_2 , V_429 ) ;
V_112 = F_208 ( V_2 ) ;
if ( ! V_112 || ! F_60 ( V_112 , V_440 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_429 :
case V_441 :
break;
case V_442 :
break;
case V_443 :
F_201 ( V_2 ) ;
F_232 ( V_2 , V_441 ) ;
break;
case V_444 :
F_201 ( V_2 ) ;
F_233 ( V_2 , V_445 , 0 ) ;
break;
default:
F_234 ( L_15 ,
V_403 , V_2 -> V_425 ) ;
break;
}
F_235 ( & V_30 -> V_446 ) ;
if ( F_140 ( V_30 ) )
F_215 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
if ( ! F_228 ( V_2 , V_433 ) ) {
V_2 -> V_447 ( V_2 ) ;
if ( V_2 -> V_435 == V_448 ||
V_2 -> V_425 == V_431 )
F_236 ( V_2 , V_449 , V_450 ) ;
else
F_236 ( V_2 , V_449 , V_451 ) ;
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
if ( F_140 ( V_30 ) && V_452 ) {
int V_122 ;
if ( F_43 ( V_75 , V_30 -> V_88 ) )
V_122 = V_453 ;
else
V_122 = V_454 ;
F_66 ( F_67 ( V_2 ) , V_122 ) ;
V_30 -> V_47 . V_455 = 1 ;
V_30 -> V_456 [ 0 ] . V_141 = V_75 ;
V_30 -> V_456 [ 0 ] . V_90 = V_90 ;
}
}
static void F_239 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_47 . V_455 )
F_238 ( V_2 , V_75 , V_90 ) ;
else
F_237 ( V_30 -> V_456 , V_75 , V_90 ) ;
}
static void F_240 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_457 ) ;
F_10 ( V_2 ) ;
if ( F_140 ( V_30 ) && V_452 ) {
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
int V_458 ;
struct V_199 * V_154 = & V_30 -> V_459 [ 0 ] ;
struct V_199 * V_460 = V_154 + 1 ;
for ( V_458 = 1 ; V_458 < V_30 -> V_47 . V_155 ; ) {
if ( F_237 ( V_154 , V_460 -> V_141 , V_460 -> V_90 ) ) {
int V_213 ;
V_30 -> V_47 . V_155 -- ;
for ( V_213 = V_458 ; V_213 < V_30 -> V_47 . V_155 ; V_213 ++ )
V_154 [ V_213 ] = V_154 [ V_213 + 1 ] ;
continue;
}
V_458 ++ , V_460 ++ ;
}
}
static void F_242 ( struct V_1 * V_2 , T_1 V_75 , T_1 V_90 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_199 * V_154 = & V_30 -> V_459 [ 0 ] ;
int V_461 = V_30 -> V_47 . V_155 ;
int V_458 ;
if ( ! V_461 )
goto V_462;
for ( V_458 = 0 ; V_458 < V_461 ; V_458 ++ , V_154 ++ ) {
if ( F_237 ( V_154 , V_75 , V_90 ) ) {
for (; V_458 > 0 ; V_458 -- , V_154 -- )
F_114 ( * V_154 , * ( V_154 - 1 ) ) ;
if ( V_461 > 1 )
F_241 ( V_30 ) ;
return;
}
}
if ( V_458 >= V_209 ) {
V_458 -- ;
V_30 -> V_47 . V_155 -- ;
V_154 -- ;
}
for (; V_458 > 0 ; V_458 -- , V_154 -- )
* V_154 = * ( V_154 - 1 ) ;
V_462:
V_154 -> V_141 = V_75 ;
V_154 -> V_90 = V_90 ;
V_30 -> V_47 . V_155 ++ ;
}
static void F_243 ( struct V_29 * V_30 )
{
struct V_199 * V_154 = & V_30 -> V_459 [ 0 ] ;
int V_155 = V_30 -> V_47 . V_155 ;
int V_458 ;
if ( F_244 ( & V_30 -> V_446 ) ) {
V_30 -> V_47 . V_155 = 0 ;
return;
}
for ( V_458 = 0 ; V_458 < V_155 ; ) {
if ( ! F_43 ( V_30 -> V_88 , V_154 -> V_141 ) ) {
int V_213 ;
F_112 ( F_43 ( V_30 -> V_88 , V_154 -> V_90 ) ) ;
for ( V_213 = V_458 + 1 ; V_213 < V_155 ; V_213 ++ )
V_30 -> V_459 [ V_213 - 1 ] = V_30 -> V_459 [ V_213 ] ;
V_155 -- ;
continue;
}
V_458 ++ ;
V_154 ++ ;
}
V_30 -> V_47 . V_155 = V_155 ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_463 = V_30 -> V_88 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_246 ( & V_30 -> V_446 ) ) != NULL ) {
if ( F_50 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) )
break;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_463 ) ) {
T_3 V_455 = V_463 ;
if ( F_43 ( F_16 ( V_4 ) -> V_90 , V_463 ) )
V_463 = F_16 ( V_4 ) -> V_90 ;
F_239 ( V_2 , F_16 ( V_4 ) -> V_75 , V_455 ) ;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_211 ( V_2 , L_16 ) ;
F_247 ( V_4 , & V_30 -> V_446 ) ;
F_248 ( V_4 ) ;
continue;
}
F_211 ( V_2 , L_17 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_247 ( V_4 , & V_30 -> V_446 ) ;
F_249 ( & V_2 -> V_464 , V_4 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( F_6 ( V_4 ) -> V_465 )
F_230 ( V_2 ) ;
}
}
static int F_250 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_466 )
{
if ( F_38 ( & V_2 -> V_79 ) > V_2 -> V_67 ||
! F_251 ( V_2 , V_4 , V_466 ) ) {
if ( F_252 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_251 ( V_2 , V_4 , V_466 ) ) {
if ( ! F_253 ( V_2 ) )
return - 1 ;
if ( ! F_251 ( V_2 , V_4 , V_466 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_254 ( struct V_1 * V_2 ,
struct V_3 * V_467 ,
struct V_3 * V_468 ,
bool * V_469 )
{
int V_289 ;
* V_469 = false ;
if ( F_6 ( V_468 ) -> V_465 )
return false ;
if ( F_16 ( V_468 ) -> V_75 != F_16 ( V_467 ) -> V_90 )
return false ;
if ( ! F_255 ( V_467 , V_468 , V_469 , & V_289 ) )
return false ;
F_256 ( V_289 , & V_2 -> V_79 ) ;
F_257 ( V_2 , V_289 ) ;
F_66 ( F_67 ( V_2 ) , V_470 ) ;
F_16 ( V_467 ) -> V_90 = F_16 ( V_468 ) -> V_90 ;
F_16 ( V_467 ) -> V_149 = F_16 ( V_468 ) -> V_149 ;
return true ;
}
static void F_258 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_471 ;
T_1 V_75 , V_90 ;
F_15 ( V_30 , V_4 ) ;
if ( F_100 ( F_250 ( V_2 , V_4 , V_4 -> V_57 ) ) ) {
F_66 ( F_67 ( V_2 ) , V_472 ) ;
F_248 ( V_4 ) ;
return;
}
V_30 -> V_358 = 0 ;
F_47 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_473 ) ;
F_211 ( V_2 , L_18 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_471 = F_259 ( & V_30 -> V_446 ) ;
if ( ! V_471 ) {
if ( F_140 ( V_30 ) ) {
V_30 -> V_47 . V_155 = 1 ;
V_30 -> V_459 [ 0 ] . V_141 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_459 [ 0 ] . V_90 =
F_16 ( V_4 ) -> V_90 ;
}
F_260 ( & V_30 -> V_446 , V_4 ) ;
goto V_474;
}
V_75 = F_16 ( V_4 ) -> V_75 ;
V_90 = F_16 ( V_4 ) -> V_90 ;
if ( V_75 == F_16 ( V_471 ) -> V_90 ) {
bool V_469 ;
if ( ! F_254 ( V_2 , V_471 , V_4 , & V_469 ) ) {
F_261 ( & V_30 -> V_446 , V_471 , V_4 ) ;
} else {
F_26 ( V_2 , V_4 ) ;
F_262 ( V_4 , V_469 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_47 . V_155 ||
V_30 -> V_459 [ 0 ] . V_90 != V_75 )
goto V_475;
V_30 -> V_459 [ 0 ] . V_90 = V_90 ;
goto V_474;
}
while ( 1 ) {
if ( ! F_50 ( F_16 ( V_471 ) -> V_75 , V_75 ) )
break;
if ( F_263 ( & V_30 -> V_446 , V_471 ) ) {
V_471 = NULL ;
break;
}
V_471 = F_264 ( & V_30 -> V_446 , V_471 ) ;
}
if ( V_471 && F_43 ( V_75 , F_16 ( V_471 ) -> V_90 ) ) {
if ( ! F_50 ( V_90 , F_16 ( V_471 ) -> V_90 ) ) {
F_66 ( F_67 ( V_2 ) , V_476 ) ;
F_248 ( V_4 ) ;
V_4 = NULL ;
F_238 ( V_2 , V_75 , V_90 ) ;
goto V_475;
}
if ( F_50 ( V_75 , F_16 ( V_471 ) -> V_75 ) ) {
F_238 ( V_2 , V_75 ,
F_16 ( V_471 ) -> V_90 ) ;
} else {
if ( F_263 ( & V_30 -> V_446 ,
V_471 ) )
V_471 = NULL ;
else
V_471 = F_264 (
& V_30 -> V_446 ,
V_471 ) ;
}
}
if ( ! V_471 )
F_260 ( & V_30 -> V_446 , V_4 ) ;
else
F_261 ( & V_30 -> V_446 , V_471 , V_4 ) ;
while ( ! F_265 ( & V_30 -> V_446 , V_4 ) ) {
V_471 = F_266 ( & V_30 -> V_446 , V_4 ) ;
if ( ! F_50 ( V_90 , F_16 ( V_471 ) -> V_75 ) )
break;
if ( F_43 ( V_90 , F_16 ( V_471 ) -> V_90 ) ) {
F_239 ( V_2 , F_16 ( V_471 ) -> V_75 ,
V_90 ) ;
break;
}
F_247 ( V_471 , & V_30 -> V_446 ) ;
F_239 ( V_2 , F_16 ( V_471 ) -> V_75 ,
F_16 ( V_471 ) -> V_90 ) ;
F_66 ( F_67 ( V_2 ) , V_476 ) ;
F_248 ( V_471 ) ;
}
V_475:
if ( F_140 ( V_30 ) )
F_242 ( V_2 , V_75 , V_90 ) ;
V_474:
if ( V_4 ) {
F_26 ( V_2 , V_4 ) ;
F_267 ( V_4 , V_2 ) ;
}
}
static int T_9 F_268 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_477 ,
bool * V_469 )
{
int V_478 ;
struct V_3 * V_479 = F_259 ( & V_2 -> V_464 ) ;
F_269 ( V_4 , V_477 ) ;
V_478 = ( V_479 &&
F_254 ( V_2 , V_479 , V_4 , V_469 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( ! V_478 ) {
F_249 ( & V_2 -> V_464 , V_4 ) ;
F_267 ( V_4 , V_2 ) ;
}
return V_478 ;
}
int F_270 ( struct V_1 * V_2 , struct V_480 * V_263 , T_10 V_466 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_41 ;
bool V_469 ;
if ( V_466 == 0 )
return 0 ;
V_4 = F_271 ( V_466 + sizeof( * V_41 ) , V_2 -> V_481 ) ;
if ( ! V_4 )
goto V_164;
if ( F_250 ( V_2 , V_4 , V_466 + sizeof( * V_41 ) ) )
goto V_482;
V_41 = (struct V_15 * ) F_272 ( V_4 , sizeof( * V_41 ) ) ;
F_273 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_274 ( F_272 ( V_4 , V_466 ) , V_263 -> V_483 , V_466 ) )
goto V_482;
F_16 ( V_4 ) -> V_75 = F_7 ( V_2 ) -> V_88 ;
F_16 ( V_4 ) -> V_90 = F_16 ( V_4 ) -> V_75 + V_466 ;
F_16 ( V_4 ) -> V_149 = F_7 ( V_2 ) -> V_103 - 1 ;
if ( F_268 ( V_2 , V_4 , sizeof( * V_41 ) , & V_469 ) ) {
F_190 ( V_469 ) ;
F_248 ( V_4 ) ;
}
return V_466 ;
V_482:
F_275 ( V_4 ) ;
V_164:
return - V_484 ;
}
static void F_276 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_478 = - 1 ;
bool V_469 = false ;
if ( F_16 ( V_4 ) -> V_75 == F_16 ( V_4 ) -> V_90 )
goto V_485;
F_277 ( V_4 ) ;
F_269 ( V_4 , V_41 -> V_390 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_47 . V_455 = 0 ;
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 ) {
if ( F_225 ( V_30 ) == 0 )
goto V_486;
if ( V_30 -> V_487 . V_488 == V_489 &&
V_30 -> V_76 == V_30 -> V_88 && V_30 -> V_487 . V_10 &&
F_278 ( V_2 ) && ! V_30 -> V_490 ) {
int V_491 = F_40 (unsigned int, skb->len,
tp->ucopy.len) ;
F_279 ( V_492 ) ;
F_280 () ;
if ( ! F_281 ( V_4 , 0 , V_30 -> V_487 . V_493 , V_491 ) ) {
V_30 -> V_487 . V_10 -= V_491 ;
V_30 -> V_76 += V_491 ;
V_478 = ( V_491 == V_4 -> V_10 ) ;
F_45 ( V_2 ) ;
}
F_282 () ;
}
if ( V_478 <= 0 ) {
V_494:
if ( V_478 < 0 &&
F_250 ( V_2 , V_4 , V_4 -> V_57 ) )
goto V_485;
V_478 = F_268 ( V_2 , V_4 , 0 , & V_469 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
if ( V_4 -> V_10 )
F_46 ( V_2 , V_4 ) ;
if ( V_41 -> V_465 )
F_230 ( V_2 ) ;
if ( ! F_244 ( & V_30 -> V_446 ) ) {
F_245 ( V_2 ) ;
if ( F_244 ( & V_30 -> V_446 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_47 . V_155 )
F_243 ( V_30 ) ;
F_199 ( V_2 ) ;
if ( V_478 > 0 )
F_262 ( V_4 , V_469 ) ;
if ( ! F_228 ( V_2 , V_433 ) )
V_2 -> V_495 ( V_2 ) ;
return;
}
if ( ! F_50 ( F_16 ( V_4 ) -> V_90 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_457 ) ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ;
V_486:
F_10 ( V_2 ) ;
F_47 ( V_2 ) ;
V_485:
F_248 ( V_4 ) ;
return;
}
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 + F_225 ( V_30 ) ) )
goto V_486;
F_10 ( V_2 ) ;
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ) {
F_211 ( V_2 , L_19 ,
V_30 -> V_88 , F_16 ( V_4 ) -> V_75 ,
F_16 ( V_4 ) -> V_90 ) ;
F_238 ( V_2 , F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) ;
if ( ! F_225 ( V_30 ) )
goto V_486;
goto V_494;
}
F_258 ( V_2 , V_4 ) ;
}
static struct V_3 * F_283 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_496 * V_497 )
{
struct V_3 * V_498 = NULL ;
if ( ! F_265 ( V_497 , V_4 ) )
V_498 = F_266 ( V_497 , V_4 ) ;
F_247 ( V_4 , V_497 ) ;
F_248 ( V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_499 ) ;
return V_498 ;
}
static void
F_284 ( struct V_1 * V_2 , struct V_496 * V_497 ,
struct V_3 * V_500 , struct V_3 * V_479 ,
T_1 V_501 , T_1 V_474 )
{
struct V_3 * V_4 , * V_502 ;
bool V_503 ;
V_4 = V_500 ;
V_504:
V_503 = true ;
F_285 (list, skb, n) {
if ( V_4 == V_479 )
break;
if ( ! F_43 ( V_501 , F_16 ( V_4 ) -> V_90 ) ) {
V_4 = F_283 ( V_2 , V_4 , V_497 ) ;
if ( ! V_4 )
break;
goto V_504;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_465 &&
( F_25 ( V_4 -> V_57 ) > V_4 -> V_10 ||
F_43 ( F_16 ( V_4 ) -> V_75 , V_501 ) ) ) {
V_503 = false ;
break;
}
if ( ! F_265 ( V_497 , V_4 ) ) {
struct V_3 * V_498 = F_266 ( V_497 , V_4 ) ;
if ( V_498 != V_479 &&
F_16 ( V_4 ) -> V_90 != F_16 ( V_498 ) -> V_75 ) {
V_503 = false ;
break;
}
}
V_501 = F_16 ( V_4 ) -> V_90 ;
}
if ( V_503 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_465 )
return;
while ( F_43 ( V_501 , V_474 ) ) {
struct V_3 * V_505 ;
unsigned int V_506 = F_286 ( V_4 ) ;
int V_507 = F_287 ( V_506 , 0 ) ;
if ( V_507 < 0 )
return;
if ( V_474 - V_501 < V_507 )
V_507 = V_474 - V_501 ;
V_505 = F_271 ( V_507 + V_506 , V_169 ) ;
if ( ! V_505 )
return;
F_288 ( V_505 , F_289 ( V_4 ) - V_4 -> V_500 ) ;
F_290 ( V_505 , ( F_291 ( V_4 ) -
V_4 -> V_500 ) ) ;
F_292 ( V_505 , ( F_4 ( V_4 ) -
V_4 -> V_500 ) ) ;
F_293 ( V_505 , V_506 ) ;
memcpy ( V_505 -> V_500 , V_4 -> V_500 , V_506 ) ;
memcpy ( V_505 -> V_508 , V_4 -> V_508 , sizeof( V_4 -> V_508 ) ) ;
F_16 ( V_505 ) -> V_75 = F_16 ( V_505 ) -> V_90 = V_501 ;
F_294 ( V_497 , V_4 , V_505 ) ;
F_267 ( V_505 , V_2 ) ;
while ( V_507 > 0 ) {
int V_509 = V_501 - F_16 ( V_4 ) -> V_75 ;
int V_466 = F_16 ( V_4 ) -> V_90 - V_501 ;
F_89 ( V_509 < 0 ) ;
if ( V_466 > 0 ) {
V_466 = F_9 ( V_507 , V_466 ) ;
if ( F_295 ( V_4 , V_509 , F_272 ( V_505 , V_466 ) , V_466 ) )
F_296 () ;
F_16 ( V_505 ) -> V_90 += V_466 ;
V_507 -= V_466 ;
V_501 += V_466 ;
}
if ( ! F_43 ( V_501 , F_16 ( V_4 ) -> V_90 ) ) {
V_4 = F_283 ( V_2 , V_4 , V_497 ) ;
if ( ! V_4 ||
V_4 == V_479 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_465 )
return;
}
}
}
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_246 ( & V_30 -> V_446 ) ;
struct V_3 * V_500 ;
T_1 V_501 , V_474 ;
if ( V_4 == NULL )
return;
V_501 = F_16 ( V_4 ) -> V_75 ;
V_474 = F_16 ( V_4 ) -> V_90 ;
V_500 = V_4 ;
for (; ; ) {
struct V_3 * V_498 = NULL ;
if ( ! F_265 ( & V_30 -> V_446 , V_4 ) )
V_498 = F_266 ( & V_30 -> V_446 , V_4 ) ;
V_4 = V_498 ;
if ( ! V_4 ||
F_50 ( F_16 ( V_4 ) -> V_75 , V_474 ) ||
F_43 ( F_16 ( V_4 ) -> V_90 , V_501 ) ) {
F_284 ( V_2 , & V_30 -> V_446 ,
V_500 , V_4 , V_501 , V_474 ) ;
V_500 = V_4 ;
if ( ! V_4 )
break;
V_501 = F_16 ( V_4 ) -> V_75 ;
V_474 = F_16 ( V_4 ) -> V_90 ;
} else {
if ( F_43 ( F_16 ( V_4 ) -> V_75 , V_501 ) )
V_501 = F_16 ( V_4 ) -> V_75 ;
if ( F_50 ( F_16 ( V_4 ) -> V_90 , V_474 ) )
V_474 = F_16 ( V_4 ) -> V_90 ;
}
}
}
static bool F_253 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_510 = false ;
if ( ! F_244 ( & V_30 -> V_446 ) ) {
F_66 ( F_67 ( V_2 ) , V_511 ) ;
F_235 ( & V_30 -> V_446 ) ;
if ( V_30 -> V_47 . V_117 )
F_215 ( & V_30 -> V_47 ) ;
F_48 ( V_2 ) ;
V_510 = true ;
}
return V_510 ;
}
static int F_252 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_211 ( V_2 , L_20 , V_30 -> V_76 ) ;
F_66 ( F_67 ( V_2 ) , V_512 ) ;
if ( F_38 ( & V_2 -> V_79 ) >= V_2 -> V_67 )
F_35 ( V_2 ) ;
else if ( F_28 ( V_2 ) )
V_30 -> V_60 = F_9 ( V_30 -> V_60 , 4U * V_30 -> V_63 ) ;
F_297 ( V_2 ) ;
if ( ! F_244 ( & V_2 -> V_464 ) )
F_284 ( V_2 , & V_2 -> V_464 ,
F_246 ( & V_2 -> V_464 ) ,
NULL ,
V_30 -> V_76 , V_30 -> V_88 ) ;
F_48 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_253 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_79 ) <= V_2 -> V_67 )
return 0 ;
F_66 ( F_67 ( V_2 ) , V_513 ) ;
V_30 -> V_358 = 0 ;
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
V_2 -> V_514 ( V_2 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
if ( F_228 ( V_2 , V_515 ) ) {
F_301 ( V_2 , V_515 ) ;
if ( V_2 -> V_516 &&
F_302 ( V_517 , & V_2 -> V_516 -> V_518 ) )
F_299 ( V_2 ) ;
}
}
static inline void F_303 ( struct V_1 * V_2 )
{
F_304 ( V_2 ) ;
F_300 ( V_2 ) ;
}
static void F_305 ( struct V_1 * V_2 , int V_519 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_88 - V_30 -> V_367 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_306 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_519 && F_246 ( & V_30 -> V_446 ) ) ) {
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
T_1 V_207 = F_148 ( V_41 -> V_520 ) ;
if ( V_207 && ! V_521 )
V_207 -- ;
V_207 += F_219 ( V_41 -> V_75 ) ;
if ( F_50 ( V_30 -> V_76 , V_207 ) )
return;
if ( F_43 ( V_207 , V_30 -> V_88 ) )
return;
if ( V_30 -> V_490 && ! F_50 ( V_207 , V_30 -> V_522 ) )
return;
F_311 ( V_2 ) ;
if ( V_30 -> V_522 == V_30 -> V_76 && V_30 -> V_490 &&
! F_228 ( V_2 , V_523 ) && V_30 -> V_76 != V_30 -> V_88 ) {
struct V_3 * V_4 = F_246 ( & V_2 -> V_464 ) ;
V_30 -> V_76 ++ ;
if ( V_4 && ! F_43 ( V_30 -> V_76 , F_16 ( V_4 ) -> V_90 ) ) {
F_247 ( V_4 , & V_2 -> V_464 ) ;
F_248 ( V_4 ) ;
}
}
V_30 -> V_490 = V_524 ;
V_30 -> V_522 = V_207 ;
V_30 -> V_358 = 0 ;
}
static void F_312 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_525 )
F_310 ( V_2 , V_41 ) ;
if ( V_30 -> V_490 == V_524 ) {
T_1 V_207 = V_30 -> V_522 - F_219 ( V_41 -> V_75 ) + ( V_41 -> V_390 * 4 ) -
V_41 -> V_43 ;
if ( V_207 < V_4 -> V_10 ) {
T_4 V_202 ;
if ( F_295 ( V_4 , V_207 , & V_202 , 1 ) )
F_296 () ;
V_30 -> V_490 = V_526 | V_202 ;
if ( ! F_228 ( V_2 , V_433 ) )
V_2 -> V_495 ( V_2 ) ;
}
}
}
static int F_313 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_527 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_491 = V_4 -> V_10 - V_527 ;
int V_164 ;
F_280 () ;
if ( F_314 ( V_4 ) )
V_164 = F_281 ( V_4 , V_527 , V_30 -> V_487 . V_493 , V_491 ) ;
else
V_164 = F_315 ( V_4 , V_527 ,
V_30 -> V_487 . V_493 ) ;
if ( ! V_164 ) {
V_30 -> V_487 . V_10 -= V_491 ;
V_30 -> V_76 += V_491 ;
F_45 ( V_2 ) ;
}
F_282 () ;
return V_164 ;
}
static T_11 F_316 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_528 ;
if ( F_278 ( V_2 ) ) {
F_280 () ;
V_528 = F_317 ( V_4 ) ;
F_282 () ;
} else {
V_528 = F_317 ( V_4 ) ;
}
return V_528 ;
}
static inline bool F_318 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_314 ( V_4 ) &&
F_316 ( V_2 , V_4 ) ;
}
static bool F_319 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_527 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_491 = V_4 -> V_10 - V_527 ;
int V_529 ;
bool V_530 = false ;
if ( V_30 -> V_487 . V_531 )
return false ;
if ( ! V_30 -> V_487 . V_532 && V_30 -> V_487 . V_533 )
V_30 -> V_487 . V_532 = F_320 () ;
if ( V_30 -> V_487 . V_532 && F_314 ( V_4 ) ) {
V_529 = F_321 ( V_30 -> V_487 . V_532 ,
V_4 , V_527 ,
V_30 -> V_487 . V_493 , V_491 ,
V_30 -> V_487 . V_533 ) ;
if ( V_529 < 0 )
goto V_197;
V_30 -> V_487 . V_529 = V_529 ;
V_530 = true ;
V_30 -> V_487 . V_10 -= V_491 ;
V_30 -> V_76 += V_491 ;
F_45 ( V_2 ) ;
if ( ( V_30 -> V_487 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_534 ) ||
( F_38 ( & V_2 -> V_79 ) > ( V_2 -> V_67 >> 1 ) ) ) {
V_30 -> V_487 . V_531 = 1 ;
V_2 -> V_495 ( V_2 ) ;
}
} else if ( V_491 > 0 ) {
V_30 -> V_487 . V_531 = 1 ;
V_2 -> V_495 ( V_2 ) ;
}
V_197:
return V_530 ;
}
static bool F_322 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_535 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_220 ( V_4 , V_41 , V_30 ) && V_30 -> V_47 . V_262 &&
F_223 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_536 ) {
F_66 ( F_67 ( V_2 ) , V_537 ) ;
F_240 ( V_2 , V_4 ) ;
goto V_538;
}
}
if ( ! F_224 ( V_30 , F_16 ( V_4 ) -> V_75 , F_16 ( V_4 ) -> V_90 ) ) {
if ( ! V_41 -> V_536 ) {
if ( V_41 -> V_43 )
goto V_539;
F_240 ( V_2 , V_4 ) ;
}
goto V_538;
}
if ( V_41 -> V_536 ) {
if ( F_16 ( V_4 ) -> V_75 == V_30 -> V_88 )
F_226 ( V_2 ) ;
else
F_200 ( V_2 ) ;
goto V_538;
}
if ( V_41 -> V_43 ) {
V_539:
if ( V_535 )
F_323 ( F_67 ( V_2 ) , V_540 ) ;
F_66 ( F_67 ( V_2 ) , V_541 ) ;
F_200 ( V_2 ) ;
goto V_538;
}
return true ;
V_538:
F_248 ( V_4 ) ;
return false ;
}
void F_324 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_100 ( V_2 -> V_542 == NULL ) )
F_2 ( V_2 ) -> V_543 -> V_544 ( V_2 , V_4 ) ;
V_30 -> V_47 . V_262 = 0 ;
if ( ( F_5 ( V_41 ) & V_545 ) == V_30 -> V_358 &&
F_16 ( V_4 ) -> V_75 == V_30 -> V_88 &&
! F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_105 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_422 ) {
if ( ! F_217 ( V_30 , V_41 ) )
goto V_546;
if ( ( T_5 ) ( V_30 -> V_47 . V_365 - V_30 -> V_47 . V_364 ) < 0 )
goto V_546;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_422 ) &&
V_30 -> V_88 == V_30 -> V_367 )
F_202 ( V_30 ) ;
F_207 ( V_2 , V_4 , 0 ) ;
F_248 ( V_4 ) ;
F_303 ( V_2 ) ;
return;
} else {
F_323 ( F_67 ( V_2 ) , V_540 ) ;
goto V_538;
}
} else {
int V_478 = 0 ;
int V_530 = 0 ;
bool V_469 = false ;
if ( V_30 -> V_76 == V_30 -> V_88 &&
V_10 - V_18 <= V_30 -> V_487 . V_10 ) {
#ifdef F_325
if ( V_30 -> V_487 . V_488 == V_489 &&
F_278 ( V_2 ) &&
F_319 ( V_2 , V_4 , V_18 ) ) {
V_530 = 1 ;
V_478 = 1 ;
}
#endif
if ( V_30 -> V_487 . V_488 == V_489 &&
F_278 ( V_2 ) && ! V_530 ) {
F_279 ( V_492 ) ;
if ( ! F_313 ( V_2 , V_4 , V_18 ) )
V_478 = 1 ;
}
if ( V_478 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_422 ) &&
V_30 -> V_88 == V_30 -> V_367 )
F_202 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_269 ( V_4 , V_18 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_90 ;
F_66 ( F_67 ( V_2 ) , V_547 ) ;
}
if ( V_530 )
F_326 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_478 ) {
if ( F_318 ( V_2 , V_4 ) )
goto V_548;
if ( ( int ) V_4 -> V_57 > V_2 -> V_549 )
goto V_550;
if ( V_18 ==
( sizeof( struct V_15 ) + V_422 ) &&
V_30 -> V_88 == V_30 -> V_367 )
F_202 ( V_30 ) ;
F_44 ( V_2 , V_4 ) ;
F_66 ( F_67 ( V_2 ) , V_551 ) ;
V_478 = F_268 ( V_2 , V_4 , V_18 ,
& V_469 ) ;
}
F_46 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_149 != V_30 -> V_103 ) {
F_207 ( V_2 , V_4 , V_377 ) ;
F_303 ( V_2 ) ;
if ( ! F_309 ( V_2 ) )
goto V_552;
}
if ( ! V_530 || V_30 -> V_88 != V_30 -> V_367 )
F_305 ( V_2 , 0 ) ;
V_552:
#ifdef F_325
if ( V_530 )
F_249 ( & V_2 -> V_553 , V_4 ) ;
else
#endif
if ( V_478 )
F_262 ( V_4 , V_469 ) ;
V_2 -> V_495 ( V_2 ) ;
return;
}
}
V_546:
if ( V_10 < ( V_41 -> V_390 << 2 ) || F_318 ( V_2 , V_4 ) )
goto V_548;
if ( ! V_41 -> V_317 && ! V_41 -> V_536 )
goto V_538;
if ( ! F_322 ( V_2 , V_4 , V_41 , 1 ) )
return;
V_550:
if ( F_207 ( V_2 , V_4 , V_374 | V_373 ) < 0 )
goto V_538;
F_44 ( V_2 , V_4 ) ;
F_312 ( V_2 , V_4 , V_41 ) ;
F_276 ( V_2 , V_4 ) ;
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
return;
V_548:
F_323 ( F_67 ( V_2 ) , V_554 ) ;
F_323 ( F_67 ( V_2 ) , V_540 ) ;
V_538:
F_248 ( V_4 ) ;
}
void F_327 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_232 ( V_2 , V_439 ) ;
if ( V_4 != NULL ) {
V_6 -> V_543 -> V_544 ( V_2 , V_4 ) ;
F_328 ( V_2 , V_4 ) ;
}
V_6 -> V_543 -> V_555 ( V_2 ) ;
F_329 ( V_2 ) ;
F_330 ( V_2 ) ;
V_30 -> V_556 = V_74 ;
F_32 ( V_2 ) ;
if ( F_228 ( V_2 , V_557 ) )
F_331 ( V_2 , F_332 ( V_30 ) ) ;
if ( ! V_30 -> V_47 . V_356 )
F_333 ( V_30 , V_30 -> V_355 ) ;
else
V_30 -> V_358 = 0 ;
if ( ! F_228 ( V_2 , V_433 ) ) {
V_2 -> V_447 ( V_2 ) ;
F_236 ( V_2 , V_558 , V_559 ) ;
}
}
static bool F_334 ( struct V_1 * V_2 , struct V_3 * V_560 ,
struct V_387 * V_561 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_562 ? F_101 ( V_2 ) : NULL ;
T_6 V_64 = V_30 -> V_47 . V_48 ;
bool V_563 ;
if ( V_64 == V_30 -> V_47 . V_398 ) {
struct V_384 V_564 ;
F_335 ( & V_564 ) ;
V_564 . V_398 = V_564 . V_48 = 0 ;
F_212 ( V_560 , & V_564 , 0 , NULL ) ;
V_64 = V_564 . V_48 ;
}
if ( ! V_30 -> V_565 )
V_561 -> V_10 = - 1 ;
V_563 = ( V_561 -> V_10 <= 0 && V_13 && V_30 -> V_315 ) ;
F_336 ( V_2 , V_64 , V_561 , V_563 ) ;
if ( V_13 ) {
F_106 (data, sk) {
if ( V_13 == F_78 ( V_2 ) ||
F_337 ( V_2 , V_13 ) )
break;
}
F_182 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_566 ) ;
return true ;
}
V_30 -> V_567 = V_30 -> V_562 ;
if ( V_30 -> V_567 )
F_66 ( F_67 ( V_2 ) , V_568 ) ;
return false ;
}
static int F_338 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_387 V_388 = { . V_10 = - 1 } ;
int V_569 = V_30 -> V_47 . V_48 ;
F_212 ( V_4 , & V_30 -> V_47 , 0 , & V_388 ) ;
if ( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 )
V_30 -> V_47 . V_89 -= V_30 -> V_421 ;
if ( V_41 -> V_317 ) {
if ( ! F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_103 ) ||
F_50 ( F_16 ( V_4 ) -> V_149 , V_30 -> V_105 ) )
goto V_570;
if ( V_30 -> V_47 . V_262 && V_30 -> V_47 . V_89 &&
! F_188 ( V_30 -> V_47 . V_89 , V_30 -> V_261 ,
V_74 ) ) {
F_66 ( F_67 ( V_2 ) , V_571 ) ;
goto V_570;
}
if ( V_41 -> V_536 ) {
F_226 ( V_2 ) ;
goto V_538;
}
if ( ! V_41 -> V_43 )
goto V_572;
F_17 ( V_30 , V_41 ) ;
F_339 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_207 ( V_2 , V_4 , V_374 ) ;
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_367 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_355 = F_148 ( V_41 -> V_58 ) ;
if ( ! V_30 -> V_47 . V_402 ) {
V_30 -> V_47 . V_356 = V_30 -> V_47 . V_573 = 0 ;
V_30 -> V_61 = F_9 ( V_30 -> V_61 , 65535U ) ;
}
if ( V_30 -> V_47 . V_262 ) {
V_30 -> V_47 . V_406 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_422 ;
V_30 -> V_63 -= V_422 ;
F_202 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_140 ( V_30 ) && V_574 )
F_340 ( V_30 ) ;
F_341 ( V_2 ) ;
F_168 ( V_2 , V_6 -> V_297 ) ;
F_39 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_342 () ;
F_327 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_565 || V_30 -> V_562 ) &&
F_334 ( V_2 , V_4 , & V_388 ) )
return - 1 ;
if ( V_2 -> V_575 ||
V_6 -> V_576 . V_577 ||
V_6 -> V_8 . V_26 ) {
F_47 ( V_2 ) ;
V_6 -> V_8 . V_95 = V_74 ;
F_10 ( V_2 ) ;
F_132 ( V_2 , V_578 ,
V_579 , V_245 ) ;
V_538:
F_248 ( V_4 ) ;
return 0 ;
} else {
F_201 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_536 ) {
goto V_572;
}
if ( V_30 -> V_47 . V_366 && V_30 -> V_47 . V_262 &&
F_343 ( & V_30 -> V_47 , 0 ) )
goto V_572;
if ( V_41 -> V_43 ) {
F_232 ( V_2 , V_438 ) ;
if ( V_30 -> V_47 . V_262 ) {
V_30 -> V_47 . V_406 = 1 ;
F_202 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_422 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_88 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_367 = F_16 ( V_4 ) -> V_75 + 1 ;
V_30 -> V_355 = F_148 ( V_41 -> V_58 ) ;
V_30 -> V_354 = F_16 ( V_4 ) -> V_75 ;
V_30 -> V_142 = V_30 -> V_355 ;
F_18 ( V_30 , V_41 ) ;
F_341 ( V_2 ) ;
F_168 ( V_2 , V_6 -> V_297 ) ;
F_39 ( V_2 ) ;
F_344 ( V_2 ) ;
#if 0
return -1;
#else
goto V_538;
#endif
}
V_572:
F_335 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_569 ;
goto V_538;
V_570:
F_335 ( & V_30 -> V_47 ) ;
V_30 -> V_47 . V_48 = V_569 ;
return 1 ;
}
int F_345 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_580 * V_581 ;
int V_582 = 0 ;
bool V_583 ;
T_1 V_314 ;
V_30 -> V_47 . V_262 = 0 ;
switch ( V_2 -> V_425 ) {
case V_431 :
goto V_538;
case V_584 :
if ( V_41 -> V_317 )
return 1 ;
if ( V_41 -> V_536 )
goto V_538;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_465 )
goto V_538;
if ( V_6 -> V_543 -> V_585 ( V_2 , V_4 ) < 0 )
return 1 ;
F_275 ( V_4 ) ;
return 0 ;
}
goto V_538;
case V_426 :
V_582 = F_338 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_582 >= 0 )
return V_582 ;
F_312 ( V_2 , V_4 , V_41 ) ;
F_248 ( V_4 ) ;
F_303 ( V_2 ) ;
return 0 ;
}
V_581 = V_30 -> V_319 ;
if ( V_581 != NULL ) {
F_190 ( V_2 -> V_425 != V_438 &&
V_2 -> V_425 != V_443 ) ;
if ( F_346 ( V_2 , V_4 , V_581 , NULL , true ) == NULL )
goto V_538;
}
if ( ! V_41 -> V_317 && ! V_41 -> V_536 )
goto V_538;
if ( ! F_322 ( V_2 , V_4 , V_41 , 0 ) )
return 0 ;
V_583 = F_207 ( V_2 , V_4 , V_374 |
V_373 ) > 0 ;
switch ( V_2 -> V_425 ) {
case V_438 :
if ( ! V_583 )
return 1 ;
if ( V_581 ) {
V_314 = F_347 ( V_581 ) -> V_586 ;
V_30 -> V_315 = V_581 -> V_587 ;
F_348 ( V_2 , V_581 , false ) ;
} else {
V_314 = V_30 -> V_556 ;
V_6 -> V_543 -> V_555 ( V_2 ) ;
F_330 ( V_2 ) ;
F_341 ( V_2 ) ;
V_30 -> V_76 = V_30 -> V_88 ;
F_32 ( V_2 ) ;
}
F_342 () ;
F_232 ( V_2 , V_439 ) ;
V_2 -> V_447 ( V_2 ) ;
if ( V_2 -> V_516 )
F_236 ( V_2 , V_558 , V_559 ) ;
V_30 -> V_103 = F_16 ( V_4 ) -> V_149 ;
V_30 -> V_355 = F_148 ( V_41 -> V_58 ) << V_30 -> V_47 . V_356 ;
F_339 ( V_30 , F_16 ( V_4 ) -> V_75 ) ;
F_180 ( V_2 , V_314 ) ;
if ( V_30 -> V_47 . V_406 )
V_30 -> V_63 -= V_422 ;
if ( V_581 ) {
F_182 ( V_2 ) ;
} else
F_329 ( V_2 ) ;
F_52 ( V_2 ) ;
V_30 -> V_556 = V_74 ;
F_39 ( V_2 ) ;
F_349 ( V_30 ) ;
break;
case V_443 : {
struct V_111 * V_112 ;
int V_588 ;
if ( V_581 != NULL ) {
if ( ! V_583 )
return 1 ;
F_348 ( V_2 , V_581 , false ) ;
F_182 ( V_2 ) ;
}
if ( V_30 -> V_103 != V_30 -> V_589 )
break;
F_232 ( V_2 , V_444 ) ;
V_2 -> V_435 |= V_590 ;
V_112 = F_208 ( V_2 ) ;
if ( V_112 )
F_209 ( V_112 ) ;
if ( ! F_228 ( V_2 , V_433 ) ) {
V_2 -> V_447 ( V_2 ) ;
break;
}
if ( V_30 -> V_591 < 0 ||
( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_50 ( F_16 ( V_4 ) -> V_90 - V_41 -> V_465 , V_30 -> V_88 ) ) ) {
F_229 ( V_2 ) ;
F_66 ( F_67 ( V_2 ) , V_592 ) ;
return 1 ;
}
V_588 = F_350 ( V_2 ) ;
if ( V_588 > V_593 ) {
F_331 ( V_2 , V_588 - V_593 ) ;
} else if ( V_41 -> V_465 || F_278 ( V_2 ) ) {
F_331 ( V_2 , V_588 ) ;
} else {
F_233 ( V_2 , V_444 , V_588 ) ;
goto V_538;
}
break;
}
case V_441 :
if ( V_30 -> V_103 == V_30 -> V_589 ) {
F_233 ( V_2 , V_445 , 0 ) ;
goto V_538;
}
break;
case V_442 :
if ( V_30 -> V_103 == V_30 -> V_589 ) {
F_351 ( V_2 ) ;
F_229 ( V_2 ) ;
goto V_538;
}
break;
}
F_312 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_425 ) {
case V_429 :
case V_441 :
case V_442 :
if ( ! F_43 ( F_16 ( V_4 ) -> V_75 , V_30 -> V_88 ) )
break;
case V_443 :
case V_444 :
if ( V_2 -> V_435 & V_436 ) {
if ( F_16 ( V_4 ) -> V_90 != F_16 ( V_4 ) -> V_75 &&
F_50 ( F_16 ( V_4 ) -> V_90 - V_41 -> V_465 , V_30 -> V_88 ) ) {
F_66 ( F_67 ( V_2 ) , V_592 ) ;
F_226 ( V_2 ) ;
return 1 ;
}
}
case V_439 :
F_276 ( V_2 , V_4 ) ;
V_582 = 1 ;
break;
}
if ( V_2 -> V_425 != V_431 ) {
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
}
if ( ! V_582 ) {
V_538:
F_248 ( V_4 ) ;
}
return 0 ;
}
static inline void F_352 ( struct V_580 * V_581 , T_12 V_594 , int V_595 )
{
struct V_596 * V_597 = F_353 ( V_581 ) ;
if ( V_595 == V_267 )
F_354 (KERN_DEBUG pr_fmt(L_21),
&ireq->ir_rmt_addr, port) ;
#if F_150 ( V_270 )
else if ( V_595 == V_271 )
F_354 (KERN_DEBUG pr_fmt(L_22),
&ireq->ir_v6_rmt_addr, port) ;
#endif
}
int F_355 ( struct V_598 * V_599 ,
const struct V_600 * V_601 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_384 V_602 ;
struct V_580 * V_581 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_111 * V_112 = NULL ;
T_3 V_603 = F_16 ( V_4 ) -> V_324 ;
bool V_604 = false , V_605 ;
struct V_606 V_607 ;
struct V_387 V_388 = { . V_10 = - 1 } ;
int V_164 ;
if ( ( V_608 == 2 ||
F_356 ( V_2 ) ) && ! V_603 ) {
V_604 = F_357 ( V_2 , V_4 , V_599 -> V_609 ) ;
if ( ! V_604 )
goto V_485;
}
if ( F_358 ( V_2 ) && F_359 ( V_2 ) > 1 ) {
F_66 ( F_67 ( V_2 ) , V_610 ) ;
goto V_485;
}
V_581 = F_360 ( V_599 ) ;
if ( ! V_581 )
goto V_485;
F_347 ( V_581 ) -> V_611 = V_601 ;
F_335 ( & V_602 ) ;
V_602 . V_48 = V_601 -> V_48 ;
V_602 . V_398 = V_30 -> V_47 . V_398 ;
F_212 ( V_4 , & V_602 , 0 , V_604 ? NULL : & V_388 ) ;
if ( V_604 && ! V_602 . V_262 )
F_335 ( & V_602 ) ;
V_602 . V_406 = V_602 . V_262 ;
F_361 ( V_581 , & V_602 , V_4 , V_2 ) ;
V_601 -> V_612 ( V_581 , V_2 , V_4 ) ;
if ( F_362 ( V_2 , V_4 , V_581 ) )
goto V_613;
if ( ! V_604 || V_602 . V_406 )
F_363 ( V_581 , V_4 , F_67 ( V_2 ) ) ;
if ( V_604 ) {
V_603 = F_364 ( V_601 , V_2 , V_4 , & V_581 -> V_64 ) ;
V_581 -> V_614 = V_602 . V_406 ;
} else if ( ! V_603 ) {
if ( V_615 . V_616 ) {
bool V_617 ;
V_112 = V_601 -> V_618 ( V_2 , & V_607 , V_581 , & V_617 ) ;
if ( V_112 && V_617 &&
! F_365 ( V_581 , V_112 , true ,
V_602 . V_262 ) ) {
F_66 ( F_67 ( V_2 ) , V_619 ) ;
goto V_620;
}
}
else if ( ! V_608 &&
( V_621 - F_366 ( V_2 ) <
( V_621 >> 2 ) ) &&
! F_365 ( V_581 , V_112 , false ,
V_602 . V_262 ) ) {
F_352 ( V_581 , F_148 ( F_6 ( V_4 ) -> V_622 ) ,
V_599 -> V_595 ) ;
goto V_620;
}
V_603 = V_601 -> V_623 ( V_4 ) ;
}
if ( ! V_112 ) {
V_112 = V_601 -> V_618 ( V_2 , & V_607 , V_581 , NULL ) ;
if ( ! V_112 )
goto V_613;
}
F_347 ( V_581 ) -> V_624 = V_603 ;
F_367 ( V_581 , V_2 , V_112 ) ;
V_605 = ! V_604 &&
F_368 ( V_2 , V_4 , V_581 , & V_388 , V_112 ) ;
V_164 = V_601 -> V_625 ( V_2 , V_112 , & V_607 , V_581 ,
F_369 ( V_4 ) , & V_388 ) ;
if ( ! V_605 ) {
if ( V_164 || V_604 )
goto V_613;
F_347 ( V_581 ) -> V_626 = NULL ;
V_601 -> V_627 ( V_2 , V_581 , V_628 ) ;
}
return 0 ;
V_620:
F_370 ( V_112 ) ;
V_613:
F_371 ( V_581 ) ;
V_485:
F_66 ( F_67 ( V_2 ) , V_629 ) ;
return 0 ;
}
