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
static void F_12 ( struct V_29 * V_30 )
{
if ( V_30 -> V_31 & V_32 )
V_30 -> V_31 |= V_33 ;
}
static void F_13 ( struct V_29 * V_30 , const struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) -> V_34 )
V_30 -> V_31 &= ~ V_35 ;
}
static void F_14 ( struct V_29 * V_30 )
{
V_30 -> V_31 &= ~ V_35 ;
}
static void F_15 ( struct V_29 * V_30 , const struct V_3 * V_4 )
{
switch ( F_16 ( V_4 ) -> V_36 & V_37 ) {
case V_38 :
if ( V_30 -> V_31 & V_39 )
F_10 ( (struct V_1 * ) V_30 ) ;
break;
case V_40 :
if ( F_17 ( (struct V_1 * ) V_30 ) )
F_18 ( (struct V_1 * ) V_30 , V_41 ) ;
if ( ! ( V_30 -> V_31 & V_35 ) ) {
F_10 ( (struct V_1 * ) V_30 ) ;
V_30 -> V_31 |= V_35 ;
}
V_30 -> V_31 |= V_39 ;
break;
default:
if ( F_17 ( (struct V_1 * ) V_30 ) )
F_18 ( (struct V_1 * ) V_30 , V_42 ) ;
V_30 -> V_31 |= V_39 ;
break;
}
}
static void F_19 ( struct V_29 * V_30 , const struct V_3 * V_4 )
{
if ( V_30 -> V_31 & V_32 )
F_15 ( V_30 , V_4 ) ;
}
static void F_20 ( struct V_29 * V_30 , const struct V_15 * V_43 )
{
if ( ( V_30 -> V_31 & V_32 ) && ( ! V_43 -> V_44 || V_43 -> V_34 ) )
V_30 -> V_31 &= ~ V_32 ;
}
static void F_21 ( struct V_29 * V_30 , const struct V_15 * V_43 )
{
if ( ( V_30 -> V_31 & V_32 ) && ( ! V_43 -> V_44 || ! V_43 -> V_34 ) )
V_30 -> V_31 &= ~ V_32 ;
}
static bool F_22 ( const struct V_29 * V_30 , const struct V_15 * V_43 )
{
if ( V_43 -> V_44 && ! V_43 -> V_45 && ( V_30 -> V_31 & V_32 ) )
return true ;
return false ;
}
static void F_23 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_46 , V_47 ;
T_1 V_48 ;
V_47 = F_24 ( T_1 , V_30 -> V_49 . V_50 , V_30 -> V_51 ) +
V_52 +
F_25 ( sizeof( struct V_53 ) ) ;
V_47 = F_26 ( V_47 ) +
F_25 ( sizeof( struct V_3 ) ) ;
V_48 = F_24 ( T_1 , V_54 , V_30 -> V_55 ) ;
V_48 = F_24 ( T_1 , V_48 , V_30 -> V_56 + 1 ) ;
V_46 = 2 * V_48 * V_47 ;
if ( V_2 -> V_57 < V_46 )
V_2 -> V_57 = F_9 ( V_46 , V_58 [ 2 ] ) ;
}
static int F_27 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_59 = F_28 ( V_4 -> V_59 ) >> 1 ;
int V_60 = F_28 ( V_61 [ 2 ] ) >> 1 ;
while ( V_30 -> V_62 <= V_60 ) {
if ( V_59 <= V_4 -> V_10 )
return 2 * F_2 ( V_2 ) -> V_8 . V_12 ;
V_59 >>= 1 ;
V_60 >>= 1 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_62 < V_30 -> V_63 &&
( int ) V_30 -> V_62 < F_30 ( V_2 ) &&
! F_31 ( V_2 ) ) {
int V_64 ;
if ( F_28 ( V_4 -> V_59 ) <= V_4 -> V_10 )
V_64 = 2 * V_30 -> V_65 ;
else
V_64 = F_27 ( V_2 , V_4 ) ;
if ( V_64 ) {
V_64 = F_24 ( int , V_64 , 2 * V_4 -> V_10 ) ;
V_30 -> V_62 = F_9 ( V_30 -> V_62 + V_64 ,
V_30 -> V_63 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_66 = F_7 ( V_2 ) -> V_65 ;
int V_67 ;
V_67 = 2 * F_33 ( V_66 + V_52 ) *
F_34 ( V_66 ) ;
if ( V_68 )
V_67 <<= 2 ;
if ( V_2 -> V_69 < V_67 )
V_2 -> V_69 = F_9 ( V_67 , V_61 [ 2 ] ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_70 ;
if ( ! ( V_2 -> V_71 & V_72 ) )
F_32 ( V_2 ) ;
if ( ! ( V_2 -> V_71 & V_73 ) )
F_23 ( V_2 ) ;
V_30 -> V_74 . V_75 = V_30 -> V_23 ;
V_30 -> V_74 . time = V_76 ;
V_30 -> V_74 . V_77 = V_30 -> V_78 ;
V_70 = F_36 ( V_2 ) ;
if ( V_30 -> V_63 >= V_70 ) {
V_30 -> V_63 = V_70 ;
if ( V_79 && V_70 > 4 * V_30 -> V_65 )
V_30 -> V_63 = F_37 ( V_70 -
( V_70 >> V_79 ) ,
4 * V_30 -> V_65 ) ;
}
if ( V_79 &&
V_30 -> V_63 > 2 * V_30 -> V_65 &&
V_30 -> V_63 + V_30 -> V_65 > V_70 )
V_30 -> V_63 = F_37 ( 2 * V_30 -> V_65 , V_70 - V_30 -> V_65 ) ;
V_30 -> V_62 = F_9 ( V_30 -> V_62 , V_30 -> V_63 ) ;
V_30 -> V_80 = V_76 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_69 < V_61 [ 2 ] &&
! ( V_2 -> V_71 & V_72 ) &&
! F_31 ( V_2 ) &&
F_39 ( V_2 ) < F_40 ( V_2 , 0 ) ) {
V_2 -> V_69 = F_9 ( F_41 ( & V_2 -> V_81 ) ,
V_61 [ 2 ] ) ;
}
if ( F_41 ( & V_2 -> V_81 ) > V_2 -> V_69 )
V_30 -> V_62 = F_9 ( V_30 -> V_63 , 2U * V_30 -> V_65 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned int V_82 = F_43 (unsigned int, tp->advmss, tp->mss_cache) ;
V_82 = F_9 ( V_82 , V_30 -> V_23 / 2 ) ;
V_82 = F_9 ( V_82 , V_14 ) ;
V_82 = F_37 ( V_82 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_82 ;
}
static void F_44 ( struct V_29 * V_30 , T_1 V_83 , int V_84 )
{
T_1 V_85 = V_30 -> V_86 . V_87 ;
long V_88 = V_83 ;
if ( V_88 == 0 )
V_88 = 1 ;
if ( V_85 != 0 ) {
if ( ! V_84 ) {
V_88 -= ( V_85 >> 3 ) ;
V_85 += V_88 ;
} else {
V_88 <<= 3 ;
if ( V_88 < V_85 )
V_85 = V_88 ;
}
} else {
V_85 = V_88 << 3 ;
}
if ( V_30 -> V_86 . V_87 != V_85 )
V_30 -> V_86 . V_87 = V_85 ;
}
static inline void F_45 ( struct V_29 * V_30 )
{
if ( V_30 -> V_86 . time == 0 )
goto V_89;
if ( F_46 ( V_30 -> V_90 , V_30 -> V_86 . V_77 ) )
return;
F_44 ( V_30 , V_76 - V_30 -> V_86 . time , 1 ) ;
V_89:
V_30 -> V_86 . V_77 = V_30 -> V_90 + V_30 -> V_23 ;
V_30 -> V_86 . time = V_76 ;
}
static inline void F_47 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_49 . V_91 &&
( F_16 ( V_4 ) -> V_92 -
F_16 ( V_4 ) -> V_77 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_44 ( V_30 , V_76 - V_30 -> V_49 . V_91 , 0 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int time ;
int V_93 ;
time = V_76 - V_30 -> V_74 . time ;
if ( time < ( V_30 -> V_86 . V_87 >> 3 ) || V_30 -> V_86 . V_87 == 0 )
return;
V_93 = V_30 -> V_78 - V_30 -> V_74 . V_77 ;
if ( V_93 <= V_30 -> V_74 . V_75 )
goto V_89;
if ( V_68 &&
! ( V_2 -> V_71 & V_72 ) ) {
int V_94 , V_67 , V_95 ;
V_94 = ( V_93 << 1 ) + 16 * V_30 -> V_65 ;
if ( V_93 >=
V_30 -> V_74 . V_75 + ( V_30 -> V_74 . V_75 >> 2 ) ) {
if ( V_93 >=
V_30 -> V_74 . V_75 + ( V_30 -> V_74 . V_75 >> 1 ) )
V_94 <<= 1 ;
else
V_94 += ( V_94 >> 1 ) ;
}
V_67 = F_33 ( V_30 -> V_65 + V_52 ) ;
while ( F_28 ( V_67 ) < V_30 -> V_65 )
V_67 += 128 ;
V_95 = F_9 ( V_94 / V_30 -> V_65 * V_67 , V_61 [ 2 ] ) ;
if ( V_95 > V_2 -> V_69 ) {
V_2 -> V_69 = V_95 ;
V_30 -> V_63 = V_94 ;
}
}
V_30 -> V_74 . V_75 = V_93 ;
V_89:
V_30 -> V_74 . V_77 = V_30 -> V_78 ;
V_30 -> V_74 . time = V_76 ;
}
static void F_49 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_96 ;
F_50 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_45 ( V_30 ) ;
V_96 = V_76 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_88 = V_96 - V_6 -> V_8 . V_97 ;
if ( V_88 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_88 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_88 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_98 )
V_6 -> V_8 . V_27 = V_6 -> V_98 ;
} else if ( V_88 > V_6 -> V_98 ) {
F_8 ( V_2 ) ;
F_51 ( V_2 ) ;
}
}
V_6 -> V_8 . V_97 = V_96 ;
F_19 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_29 ( V_2 , V_4 ) ;
}
static void F_52 ( struct V_1 * V_2 , long V_99 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_88 = V_99 ;
T_1 V_100 = V_30 -> V_101 ;
if ( V_100 != 0 ) {
V_88 -= ( V_100 >> 3 ) ;
V_100 += V_88 ;
if ( V_88 < 0 ) {
V_88 = - V_88 ;
V_88 -= ( V_30 -> V_102 >> 2 ) ;
if ( V_88 > 0 )
V_88 >>= 3 ;
} else {
V_88 -= ( V_30 -> V_102 >> 2 ) ;
}
V_30 -> V_102 += V_88 ;
if ( V_30 -> V_102 > V_30 -> V_103 ) {
V_30 -> V_103 = V_30 -> V_102 ;
if ( V_30 -> V_103 > V_30 -> V_104 )
V_30 -> V_104 = V_30 -> V_103 ;
}
if ( F_53 ( V_30 -> V_105 , V_30 -> V_106 ) ) {
if ( V_30 -> V_103 < V_30 -> V_104 )
V_30 -> V_104 -= ( V_30 -> V_104 - V_30 -> V_103 ) >> 2 ;
V_30 -> V_106 = V_30 -> V_107 ;
V_30 -> V_103 = F_54 ( V_2 ) ;
}
} else {
V_100 = V_88 << 3 ;
V_30 -> V_102 = V_88 << 1 ;
V_30 -> V_104 = F_37 ( V_30 -> V_102 , F_54 ( V_2 ) ) ;
V_30 -> V_103 = V_30 -> V_104 ;
V_30 -> V_106 = V_30 -> V_107 ;
}
V_30 -> V_101 = F_37 ( 1U , V_100 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_108 ;
V_108 = ( T_2 ) V_30 -> V_51 * 2 * ( V_109 << 3 ) ;
V_108 *= F_37 ( V_30 -> V_55 , V_30 -> V_110 ) ;
if ( F_56 ( V_30 -> V_101 ) )
F_57 ( V_108 , V_30 -> V_101 ) ;
F_58 ( V_2 -> V_111 ) = F_43 ( T_2 , V_108 ,
V_2 -> V_112 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_98 = F_60 ( V_30 ) ;
F_61 ( V_2 ) ;
}
T_3 F_62 ( const struct V_29 * V_30 , const struct V_113 * V_114 )
{
T_3 V_115 = ( V_114 ? F_63 ( V_114 , V_116 ) : 0 ) ;
if ( ! V_115 )
V_115 = V_54 ;
return F_43 ( T_3 , V_115 , V_30 -> V_117 ) ;
}
void F_64 ( struct V_29 * V_30 )
{
if ( F_65 ( V_30 ) )
V_30 -> V_118 = NULL ;
V_30 -> V_49 . V_119 &= ~ V_120 ;
}
static void F_66 ( struct V_29 * V_30 )
{
V_30 -> V_49 . V_119 |= V_121 ;
}
static void F_67 ( struct V_1 * V_2 , const int V_122 ,
const int V_123 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_122 > V_30 -> V_56 ) {
int V_124 ;
V_30 -> V_56 = F_9 ( V_125 , V_122 ) ;
if ( V_123 )
V_124 = V_126 ;
else if ( F_68 ( V_30 ) )
V_124 = V_127 ;
else if ( F_65 ( V_30 ) )
V_124 = V_128 ;
else
V_124 = V_129 ;
F_69 ( F_70 ( V_2 ) , V_124 ) ;
#if V_130 > 1
F_71 ( L_1 ,
V_30 -> V_49 . V_119 , F_2 ( V_2 ) -> V_131 ,
V_30 -> V_56 ,
V_30 -> V_132 ,
V_30 -> V_133 ,
V_30 -> V_134 ? V_30 -> V_135 : 0 ) ;
#endif
F_64 ( V_30 ) ;
}
if ( V_122 > 0 )
F_72 ( V_30 ) ;
}
static void F_73 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! V_30 -> V_136 ||
F_46 ( F_16 ( V_4 ) -> V_77 ,
F_16 ( V_30 -> V_136 ) -> V_77 ) )
V_30 -> V_136 = V_4 ;
if ( ! V_30 -> V_137 ||
F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_138 ) )
V_30 -> V_138 = F_16 ( V_4 ) -> V_92 ;
}
static void F_74 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_139 & ( V_140 | V_141 ) ) ) {
F_73 ( V_30 , V_4 ) ;
V_30 -> V_137 += F_75 ( V_4 ) ;
F_16 ( V_4 ) -> V_139 |= V_140 ;
}
}
static void F_76 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_73 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_139 & ( V_140 | V_141 ) ) ) {
V_30 -> V_137 += F_75 ( V_4 ) ;
F_16 ( V_4 ) -> V_139 |= V_140 ;
}
}
static bool F_77 ( struct V_29 * V_30 , bool V_142 ,
T_1 V_143 , T_1 V_92 )
{
if ( F_53 ( V_92 , V_30 -> V_107 ) || ! F_46 ( V_143 , V_92 ) )
return false ;
if ( ! F_46 ( V_143 , V_30 -> V_107 ) )
return false ;
if ( F_53 ( V_143 , V_30 -> V_105 ) )
return true ;
if ( ! V_142 || ! V_30 -> V_134 )
return false ;
if ( F_53 ( V_92 , V_30 -> V_105 ) )
return false ;
if ( ! F_46 ( V_143 , V_30 -> V_134 ) )
return true ;
if ( ! F_53 ( V_92 , V_30 -> V_134 ) )
return false ;
return ! F_46 ( V_143 , V_92 - V_30 -> V_144 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_145 = 0 ;
T_1 V_146 = V_30 -> V_107 ;
T_1 V_147 = F_79 ( V_30 ) ;
if ( ! F_65 ( V_30 ) || ! V_30 -> V_148 ||
! F_53 ( V_147 , V_30 -> V_149 ) ||
V_6 -> V_131 != V_150 )
return;
F_80 (skb, sk) {
T_1 V_151 = F_16 ( V_4 ) -> V_151 ;
if ( V_4 == F_81 ( V_2 ) )
break;
if ( V_145 == V_30 -> V_148 )
break;
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_105 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_139 & V_152 ) )
continue;
if ( F_53 ( V_147 , V_151 ) ) {
F_16 ( V_4 ) -> V_139 &= ~ V_152 ;
V_30 -> V_148 -= F_75 ( V_4 ) ;
F_76 ( V_30 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_153 ) ;
} else {
if ( F_46 ( V_151 , V_146 ) )
V_146 = V_151 ;
V_145 += F_75 ( V_4 ) ;
}
}
if ( V_30 -> V_148 )
V_30 -> V_149 = V_146 ;
}
static bool F_82 ( struct V_1 * V_2 , const struct V_3 * V_154 ,
struct V_155 * V_156 , int V_157 ,
T_1 V_158 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_159 = F_83 ( & V_156 [ 0 ] . V_143 ) ;
T_1 V_160 = F_83 ( & V_156 [ 0 ] . V_92 ) ;
bool V_161 = false ;
if ( F_46 ( V_159 , F_16 ( V_154 ) -> V_151 ) ) {
V_161 = true ;
F_66 ( V_30 ) ;
F_69 ( F_70 ( V_2 ) , V_162 ) ;
} else if ( V_157 > 1 ) {
T_1 V_163 = F_83 ( & V_156 [ 1 ] . V_92 ) ;
T_1 V_164 = F_83 ( & V_156 [ 1 ] . V_143 ) ;
if ( ! F_53 ( V_160 , V_163 ) &&
! F_46 ( V_159 , V_164 ) ) {
V_161 = true ;
F_66 ( V_30 ) ;
F_69 ( F_70 ( V_2 ) ,
V_165 ) ;
}
}
if ( V_161 && V_30 -> V_134 && V_30 -> V_135 > 0 &&
! F_53 ( V_160 , V_158 ) &&
F_53 ( V_160 , V_30 -> V_134 ) )
V_30 -> V_135 -- ;
return V_161 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_143 , T_1 V_92 )
{
int V_166 ;
bool V_167 ;
unsigned int V_168 ;
unsigned int V_66 ;
V_167 = ! F_53 ( V_143 , F_16 ( V_4 ) -> V_77 ) &&
! F_46 ( V_92 , F_16 ( V_4 ) -> V_92 ) ;
if ( F_75 ( V_4 ) > 1 && ! V_167 &&
F_53 ( F_16 ( V_4 ) -> V_92 , V_143 ) ) {
V_66 = F_85 ( V_4 ) ;
V_167 = ! F_53 ( V_143 , F_16 ( V_4 ) -> V_77 ) ;
if ( ! V_167 ) {
V_168 = V_143 - F_16 ( V_4 ) -> V_77 ;
if ( V_168 < V_66 )
V_168 = V_66 ;
} else {
V_168 = V_92 - F_16 ( V_4 ) -> V_77 ;
if ( V_168 < V_66 )
return - V_169 ;
}
if ( V_168 > V_66 ) {
unsigned int V_170 = ( V_168 / V_66 ) * V_66 ;
if ( ! V_167 && V_170 < V_168 ) {
V_170 += V_66 ;
if ( V_170 >= V_4 -> V_10 )
return 0 ;
}
V_168 = V_170 ;
}
V_166 = F_86 ( V_2 , V_4 , V_168 , V_66 , V_171 ) ;
if ( V_166 < 0 )
return V_166 ;
}
return V_167 ;
}
static T_4 F_87 ( struct V_1 * V_2 ,
struct V_172 * V_173 , T_4 V_139 ,
T_1 V_143 , T_1 V_92 ,
int V_161 , int V_174 ,
const struct V_175 * V_176 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_177 = V_173 -> V_177 ;
if ( V_161 && ( V_139 & V_178 ) ) {
if ( V_30 -> V_134 && V_30 -> V_135 > 0 &&
F_53 ( V_92 , V_30 -> V_134 ) )
V_30 -> V_135 -- ;
if ( V_139 & V_141 )
V_173 -> V_179 = F_9 ( V_177 , V_173 -> V_179 ) ;
}
if ( ! F_53 ( V_92 , V_30 -> V_105 ) )
return V_139 ;
if ( ! ( V_139 & V_141 ) ) {
if ( V_139 & V_152 ) {
if ( V_139 & V_140 ) {
V_139 &= ~ ( V_140 | V_152 ) ;
V_30 -> V_137 -= V_174 ;
V_30 -> V_148 -= V_174 ;
}
} else {
if ( ! ( V_139 & V_178 ) ) {
if ( F_46 ( V_143 ,
F_79 ( V_30 ) ) )
V_173 -> V_179 = F_9 ( V_177 ,
V_173 -> V_179 ) ;
if ( ! F_53 ( V_92 , V_30 -> V_180 ) )
V_173 -> V_181 |= V_182 ;
if ( V_173 -> V_183 . V_184 == 0 )
V_173 -> V_183 = * V_176 ;
V_173 -> V_185 = * V_176 ;
}
if ( V_139 & V_140 ) {
V_139 &= ~ V_140 ;
V_30 -> V_137 -= V_174 ;
}
}
V_139 |= V_141 ;
V_173 -> V_181 |= V_186 ;
V_30 -> V_133 += V_174 ;
V_177 += V_174 ;
if ( ! F_65 ( V_30 ) && V_30 -> V_118 &&
F_46 ( V_143 , F_16 ( V_30 -> V_118 ) -> V_77 ) )
V_30 -> V_187 += V_174 ;
if ( V_177 > V_30 -> V_132 )
V_30 -> V_132 = V_177 ;
}
if ( V_161 && ( V_139 & V_152 ) ) {
V_139 &= ~ V_152 ;
V_30 -> V_148 -= V_174 ;
}
return V_139 ;
}
static bool F_88 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_172 * V_173 ,
unsigned int V_174 , int V_188 , int V_66 ,
bool V_161 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_189 = F_89 ( V_2 , V_4 ) ;
T_1 V_143 = F_16 ( V_4 ) -> V_77 ;
T_1 V_92 = V_143 + V_188 ;
F_90 ( ! V_174 ) ;
F_87 ( V_2 , V_173 , F_16 ( V_4 ) -> V_139 ,
V_143 , V_92 , V_161 , V_174 ,
& V_4 -> V_175 ) ;
if ( V_4 == V_30 -> V_118 )
V_30 -> V_187 += V_174 ;
F_16 ( V_189 ) -> V_92 += V_188 ;
F_16 ( V_4 ) -> V_77 += V_188 ;
F_91 ( V_189 , V_174 ) ;
F_90 ( F_75 ( V_4 ) < V_174 ) ;
F_91 ( V_4 , - V_174 ) ;
if ( ! F_16 ( V_189 ) -> V_190 )
F_16 ( V_189 ) -> V_190 = V_66 ;
if ( F_75 ( V_4 ) <= 1 )
F_16 ( V_4 ) -> V_190 = 0 ;
F_16 ( V_189 ) -> V_139 |= ( F_16 ( V_4 ) -> V_139 & V_191 ) ;
if ( V_4 -> V_10 > 0 ) {
F_90 ( ! F_75 ( V_4 ) ) ;
F_69 ( F_70 ( V_2 ) , V_192 ) ;
return false ;
}
if ( V_4 == V_30 -> V_136 )
V_30 -> V_136 = V_189 ;
if ( V_4 == V_30 -> V_118 ) {
V_30 -> V_118 = V_189 ;
V_30 -> V_187 -= F_75 ( V_189 ) ;
}
F_16 ( V_189 ) -> V_193 |= F_16 ( V_4 ) -> V_193 ;
if ( F_16 ( V_4 ) -> V_193 & V_194 )
F_16 ( V_189 ) -> V_92 ++ ;
if ( V_4 == F_92 ( V_2 ) )
F_93 ( V_2 , V_4 ) ;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_195 ) ;
return true ;
}
static int F_96 ( const struct V_3 * V_4 )
{
return F_75 ( V_4 ) == 1 ? V_4 -> V_10 : F_85 ( V_4 ) ;
}
static int F_97 ( const struct V_3 * V_4 )
{
return ! F_98 ( V_4 ) && F_99 ( V_4 ) ;
}
static struct V_3 * F_100 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_172 * V_173 ,
T_1 V_143 , T_1 V_92 ,
bool V_161 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_189 ;
int V_66 ;
int V_174 = 0 ;
int V_10 ;
int V_167 ;
if ( ! F_101 ( V_2 ) )
goto V_196;
if ( ! V_161 &&
( F_16 ( V_4 ) -> V_139 & ( V_140 | V_152 ) ) == V_152 )
goto V_196;
if ( ! F_97 ( V_4 ) )
goto V_196;
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_105 ) )
goto V_196;
if ( F_102 ( V_4 == F_103 ( V_2 ) ) )
goto V_196;
V_189 = F_89 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_189 ) -> V_139 & V_197 ) != V_141 )
goto V_196;
V_167 = ! F_53 ( V_143 , F_16 ( V_4 ) -> V_77 ) &&
! F_46 ( V_92 , F_16 ( V_4 ) -> V_92 ) ;
if ( V_167 ) {
V_10 = V_4 -> V_10 ;
V_174 = F_75 ( V_4 ) ;
V_66 = F_96 ( V_4 ) ;
if ( V_66 != F_96 ( V_189 ) )
goto V_196;
} else {
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_143 ) )
goto V_198;
if ( F_75 ( V_4 ) <= 1 )
goto V_198;
V_167 = ! F_53 ( V_143 , F_16 ( V_4 ) -> V_77 ) ;
if ( ! V_167 ) {
goto V_196;
}
V_10 = V_92 - F_16 ( V_4 ) -> V_77 ;
F_90 ( V_10 < 0 ) ;
F_90 ( V_10 > V_4 -> V_10 ) ;
V_66 = F_85 ( V_4 ) ;
if ( V_66 != F_96 ( V_189 ) )
goto V_196;
if ( V_10 == V_66 ) {
V_174 = 1 ;
} else if ( V_10 < V_66 ) {
goto V_198;
} else {
V_174 = V_10 / V_66 ;
V_10 = V_174 * V_66 ;
}
}
if ( ! F_53 ( F_16 ( V_4 ) -> V_77 + V_10 , V_30 -> V_105 ) )
goto V_196;
if ( ! F_104 ( V_189 , V_4 , V_10 ) )
goto V_196;
if ( ! F_88 ( V_2 , V_4 , V_173 , V_174 , V_10 , V_66 , V_161 ) )
goto V_199;
if ( V_189 == F_105 ( V_2 ) )
goto V_199;
V_4 = F_106 ( V_2 , V_189 ) ;
if ( ! F_97 ( V_4 ) ||
( V_4 == F_81 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_139 & V_197 ) != V_141 ) ||
( V_66 != F_96 ( V_4 ) ) )
goto V_199;
V_10 = V_4 -> V_10 ;
if ( F_104 ( V_189 , V_4 , V_10 ) ) {
V_174 += F_75 ( V_4 ) ;
F_88 ( V_2 , V_4 , V_173 , F_75 ( V_4 ) , V_10 , V_66 , 0 ) ;
}
V_199:
V_173 -> V_177 += V_174 ;
return V_189 ;
V_198:
return V_4 ;
V_196:
F_69 ( F_70 ( V_2 ) , V_200 ) ;
return NULL ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_201 * V_202 ,
struct V_172 * V_173 ,
T_1 V_143 , T_1 V_92 ,
bool V_203 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_204 ;
F_108 (skb, sk) {
int V_167 = 0 ;
bool V_161 = V_203 ;
if ( V_4 == F_81 ( V_2 ) )
break;
if ( ! F_46 ( F_16 ( V_4 ) -> V_77 , V_92 ) )
break;
if ( V_202 &&
F_46 ( F_16 ( V_4 ) -> V_77 , V_202 -> V_92 ) ) {
V_167 = F_84 ( V_2 , V_4 ,
V_202 -> V_143 ,
V_202 -> V_92 ) ;
if ( V_167 > 0 )
V_161 = true ;
}
if ( V_167 <= 0 ) {
V_204 = F_100 ( V_2 , V_4 , V_173 ,
V_143 , V_92 , V_161 ) ;
if ( V_204 ) {
if ( V_204 != V_4 ) {
V_4 = V_204 ;
continue;
}
V_167 = 0 ;
} else {
V_167 = F_84 ( V_2 , V_4 ,
V_143 ,
V_92 ) ;
}
}
if ( F_102 ( V_167 < 0 ) )
break;
if ( V_167 ) {
F_16 ( V_4 ) -> V_139 =
F_87 ( V_2 ,
V_173 ,
F_16 ( V_4 ) -> V_139 ,
F_16 ( V_4 ) -> V_77 ,
F_16 ( V_4 ) -> V_92 ,
V_161 ,
F_75 ( V_4 ) ,
& V_4 -> V_175 ) ;
if ( ! F_46 ( F_16 ( V_4 ) -> V_77 ,
F_79 ( V_30 ) ) )
F_93 ( V_2 , V_4 ) ;
}
V_173 -> V_177 += F_75 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_109 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_172 * V_173 ,
T_1 V_205 )
{
F_108 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_205 ) )
break;
V_173 -> V_177 += F_75 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_110 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_201 * V_202 ,
struct V_172 * V_173 ,
T_1 V_205 )
{
if ( ! V_202 )
return V_4 ;
if ( F_46 ( V_202 -> V_143 , V_205 ) ) {
V_4 = F_109 ( V_4 , V_2 , V_173 , V_202 -> V_143 ) ;
V_4 = F_107 ( V_4 , V_2 , NULL , V_173 ,
V_202 -> V_143 , V_202 -> V_92 ,
1 ) ;
}
return V_4 ;
}
static int F_111 ( const struct V_29 * V_30 , const struct V_201 * V_206 )
{
return V_206 < V_30 -> V_207 + F_112 ( V_30 -> V_207 ) ;
}
static int
F_113 ( struct V_1 * V_2 , const struct V_3 * V_154 ,
T_1 V_158 , struct V_172 * V_173 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_208 = ( F_4 ( V_154 ) +
F_16 ( V_154 ) -> V_139 ) ;
struct V_155 * V_209 = (struct V_155 * ) ( V_208 + 2 ) ;
struct V_201 V_156 [ V_210 ] ;
struct V_201 * V_206 ;
struct V_3 * V_4 ;
int V_157 = F_9 ( V_210 , ( V_208 [ 1 ] - V_211 ) >> 3 ) ;
int V_212 ;
bool V_213 = false ;
int V_214 , V_215 ;
int V_216 ;
V_173 -> V_181 = 0 ;
V_173 -> V_179 = V_30 -> V_110 ;
if ( ! V_30 -> V_133 ) {
if ( F_114 ( V_30 -> V_132 ) )
V_30 -> V_132 = 0 ;
F_115 ( V_2 ) ;
}
V_213 = F_82 ( V_2 , V_154 , V_209 ,
V_157 , V_158 ) ;
if ( V_213 )
V_173 -> V_181 |= V_217 ;
if ( F_46 ( F_16 ( V_154 ) -> V_151 , V_158 - V_30 -> V_144 ) )
return 0 ;
if ( ! V_30 -> V_110 )
goto V_199;
V_212 = 0 ;
V_216 = 0 ;
for ( V_214 = 0 ; V_214 < V_157 ; V_214 ++ ) {
bool V_161 = ! V_214 && V_213 ;
V_156 [ V_212 ] . V_143 = F_83 ( & V_209 [ V_214 ] . V_143 ) ;
V_156 [ V_212 ] . V_92 = F_83 ( & V_209 [ V_214 ] . V_92 ) ;
if ( ! F_77 ( V_30 , V_161 ,
V_156 [ V_212 ] . V_143 ,
V_156 [ V_212 ] . V_92 ) ) {
int V_124 ;
if ( V_161 ) {
if ( ! V_30 -> V_134 )
V_124 = V_218 ;
else
V_124 = V_219 ;
} else {
if ( ( F_16 ( V_154 ) -> V_151 != V_30 -> V_105 ) &&
! F_53 ( V_156 [ V_212 ] . V_92 , V_30 -> V_105 ) )
continue;
V_124 = V_220 ;
}
F_69 ( F_70 ( V_2 ) , V_124 ) ;
if ( V_214 == 0 )
V_216 = - 1 ;
continue;
}
if ( ! F_53 ( V_156 [ V_212 ] . V_92 , V_158 ) )
continue;
V_212 ++ ;
}
for ( V_214 = V_212 - 1 ; V_214 > 0 ; V_214 -- ) {
for ( V_215 = 0 ; V_215 < V_214 ; V_215 ++ ) {
if ( F_53 ( V_156 [ V_215 ] . V_143 , V_156 [ V_215 + 1 ] . V_143 ) ) {
F_116 ( V_156 [ V_215 ] , V_156 [ V_215 + 1 ] ) ;
if ( V_215 == V_216 )
V_216 = V_215 + 1 ;
}
}
}
V_4 = F_103 ( V_2 ) ;
V_173 -> V_177 = 0 ;
V_214 = 0 ;
if ( ! V_30 -> V_133 ) {
V_206 = V_30 -> V_207 + F_112 ( V_30 -> V_207 ) ;
} else {
V_206 = V_30 -> V_207 ;
while ( F_111 ( V_30 , V_206 ) && ! V_206 -> V_143 &&
! V_206 -> V_92 )
V_206 ++ ;
}
while ( V_214 < V_212 ) {
T_1 V_143 = V_156 [ V_214 ] . V_143 ;
T_1 V_92 = V_156 [ V_214 ] . V_92 ;
bool V_161 = ( V_213 && ( V_214 == V_216 ) ) ;
struct V_201 * V_202 = NULL ;
if ( V_213 && ( ( V_214 + 1 ) == V_216 ) )
V_202 = & V_156 [ V_214 + 1 ] ;
while ( F_111 ( V_30 , V_206 ) &&
! F_46 ( V_143 , V_206 -> V_92 ) )
V_206 ++ ;
if ( F_111 ( V_30 , V_206 ) && ! V_161 &&
F_53 ( V_92 , V_206 -> V_143 ) ) {
if ( F_46 ( V_143 , V_206 -> V_143 ) ) {
V_4 = F_109 ( V_4 , V_2 , V_173 ,
V_143 ) ;
V_4 = F_107 ( V_4 , V_2 , V_202 ,
V_173 ,
V_143 ,
V_206 -> V_143 ,
V_161 ) ;
}
if ( ! F_53 ( V_92 , V_206 -> V_92 ) )
goto V_221;
V_4 = F_110 ( V_4 , V_2 , V_202 ,
V_173 ,
V_206 -> V_92 ) ;
if ( F_79 ( V_30 ) == V_206 -> V_92 ) {
V_4 = F_92 ( V_2 ) ;
if ( ! V_4 )
break;
V_173 -> V_177 = V_30 -> V_132 ;
V_206 ++ ;
goto V_222;
}
V_4 = F_109 ( V_4 , V_2 , V_173 , V_206 -> V_92 ) ;
V_206 ++ ;
continue;
}
if ( ! F_46 ( V_143 , F_79 ( V_30 ) ) ) {
V_4 = F_92 ( V_2 ) ;
if ( ! V_4 )
break;
V_173 -> V_177 = V_30 -> V_132 ;
}
V_4 = F_109 ( V_4 , V_2 , V_173 , V_143 ) ;
V_222:
V_4 = F_107 ( V_4 , V_2 , V_202 , V_173 ,
V_143 , V_92 , V_161 ) ;
V_221:
V_214 ++ ;
}
for ( V_214 = 0 ; V_214 < F_112 ( V_30 -> V_207 ) - V_212 ; V_214 ++ ) {
V_30 -> V_207 [ V_214 ] . V_143 = 0 ;
V_30 -> V_207 [ V_214 ] . V_92 = 0 ;
}
for ( V_215 = 0 ; V_215 < V_212 ; V_215 ++ )
V_30 -> V_207 [ V_214 ++ ] = V_156 [ V_215 ] ;
if ( ( V_173 -> V_179 < V_30 -> V_132 ) &&
( ( F_2 ( V_2 ) -> V_131 != V_223 ) || V_30 -> V_134 ) )
F_67 ( V_2 , V_30 -> V_132 - V_173 -> V_179 , 0 ) ;
F_78 ( V_2 ) ;
F_117 ( V_30 ) ;
V_199:
#if V_130 > 0
F_114 ( ( int ) V_30 -> V_133 < 0 ) ;
F_114 ( ( int ) V_30 -> V_137 < 0 ) ;
F_114 ( ( int ) V_30 -> V_148 < 0 ) ;
F_114 ( ( int ) F_118 ( V_30 ) < 0 ) ;
#endif
return V_173 -> V_181 ;
}
static bool F_119 ( struct V_29 * V_30 )
{
T_1 V_224 ;
V_224 = F_37 ( V_30 -> V_137 , 1U ) ;
V_224 = F_9 ( V_224 , V_30 -> V_110 ) ;
if ( ( V_30 -> V_133 + V_224 ) > V_30 -> V_110 ) {
V_30 -> V_133 = V_30 -> V_110 - V_224 ;
return true ;
}
return false ;
}
static void F_120 ( struct V_1 * V_2 , const int V_225 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_119 ( V_30 ) )
F_67 ( V_2 , V_30 -> V_110 + V_225 , 0 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_133 ++ ;
F_120 ( V_2 , 0 ) ;
F_117 ( V_30 ) ;
}
static void F_122 ( struct V_1 * V_2 , int V_226 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_226 > 0 ) {
if ( V_226 - 1 >= V_30 -> V_133 )
V_30 -> V_133 = 0 ;
else
V_30 -> V_133 -= V_226 - 1 ;
}
F_120 ( V_2 , V_226 ) ;
F_117 ( V_30 ) ;
}
static inline void F_123 ( struct V_29 * V_30 )
{
V_30 -> V_133 = 0 ;
}
void F_124 ( struct V_29 * V_30 )
{
V_30 -> V_148 = 0 ;
V_30 -> V_137 = 0 ;
V_30 -> V_134 = 0 ;
V_30 -> V_135 = - 1 ;
V_30 -> V_132 = 0 ;
V_30 -> V_133 = 0 ;
}
static inline void F_125 ( struct V_29 * V_30 )
{
V_30 -> V_134 = V_30 -> V_105 ;
V_30 -> V_135 = V_30 -> V_148 ? : - 1 ;
}
void F_126 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_227 = V_6 -> V_131 < V_150 ;
bool V_228 ;
if ( V_6 -> V_131 <= V_229 ||
! F_53 ( V_30 -> V_180 , V_30 -> V_105 ) ||
( V_6 -> V_131 == V_223 && ! V_6 -> V_230 ) ) {
V_30 -> V_231 = F_127 ( V_2 ) ;
V_30 -> V_232 = V_6 -> V_233 -> V_234 ( V_2 ) ;
F_18 ( V_2 , V_235 ) ;
F_125 ( V_30 ) ;
}
V_30 -> V_55 = 1 ;
V_30 -> V_236 = 0 ;
V_30 -> V_80 = V_76 ;
V_30 -> V_148 = 0 ;
V_30 -> V_137 = 0 ;
if ( F_68 ( V_30 ) )
F_123 ( V_30 ) ;
V_4 = F_103 ( V_2 ) ;
V_228 = V_4 && ( F_16 ( V_4 ) -> V_139 & V_141 ) ;
if ( V_228 ) {
F_69 ( F_70 ( V_2 ) , V_237 ) ;
V_30 -> V_133 = 0 ;
V_30 -> V_132 = 0 ;
}
F_128 ( V_30 ) ;
F_80 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_139 &= ( ~ V_197 ) | V_141 ;
if ( ! ( F_16 ( V_4 ) -> V_139 & V_141 ) || V_228 ) {
F_16 ( V_4 ) -> V_139 &= ~ V_141 ;
F_16 ( V_4 ) -> V_139 |= V_140 ;
V_30 -> V_137 += F_75 ( V_4 ) ;
V_30 -> V_138 = F_16 ( V_4 ) -> V_92 ;
}
}
F_117 ( V_30 ) ;
if ( V_6 -> V_131 <= V_229 &&
V_30 -> V_133 >= V_238 )
V_30 -> V_56 = F_43 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_129 ( V_2 , V_223 ) ;
V_30 -> V_180 = V_30 -> V_107 ;
F_12 ( V_30 ) ;
V_30 -> V_239 = V_240 &&
( V_227 || V_6 -> V_230 ) &&
! F_2 ( V_2 ) -> V_241 . V_242 ;
}
static bool F_130 ( struct V_1 * V_2 , int V_181 )
{
if ( V_181 & V_243 ) {
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_244 = F_37 ( F_131 ( V_30 -> V_101 >> 4 ) ,
F_132 ( 10 ) ) ;
F_133 ( V_2 , V_245 ,
V_244 , V_246 ) ;
return true ;
}
return false ;
}
static inline int F_134 ( const struct V_29 * V_30 )
{
return F_68 ( V_30 ) ? V_30 -> V_133 + 1 : V_30 -> V_132 ;
}
static inline int F_135 ( const struct V_29 * V_30 )
{
return F_65 ( V_30 ) ? V_30 -> V_132 : V_30 -> V_133 + 1 ;
}
static bool F_136 ( struct V_1 * V_2 , int V_181 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_244 ;
if ( V_247 < 2 || V_247 > 3 ||
( V_181 & V_248 ) || ! V_30 -> V_101 )
return false ;
V_244 = F_37 ( F_131 ( V_30 -> V_101 >> 5 ) ,
F_132 ( 2 ) ) ;
if ( ! F_137 ( F_2 ( V_2 ) -> V_249 , ( V_250 + V_244 ) ) )
return false ;
F_133 ( V_2 , V_251 , V_244 ,
V_246 ) ;
return true ;
}
static bool F_138 ( struct V_1 * V_2 , int V_181 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_110 ;
if ( V_30 -> V_137 )
return true ;
if ( F_135 ( V_30 ) > V_30 -> V_56 )
return true ;
V_110 = V_30 -> V_110 ;
if ( V_110 <= V_30 -> V_56 &&
V_30 -> V_133 >= F_24 ( T_3 , V_110 / 2 , V_238 ) &&
! F_139 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_252 || V_253 ) &&
F_140 ( V_30 ) && F_135 ( V_30 ) > 1 &&
F_141 ( V_30 ) && ! F_81 ( V_2 ) )
return true ;
if ( V_30 -> V_254 && ! V_30 -> V_148 && V_30 -> V_133 &&
( V_30 -> V_110 >= ( V_30 -> V_133 + 1 ) && V_30 -> V_110 < 4 ) &&
! F_139 ( V_2 ) )
return ! F_136 ( V_2 , V_181 ) ;
return false ;
}
static void F_142 ( struct V_1 * V_2 , int V_255 , int V_256 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_145 , V_257 ;
int V_166 ;
unsigned int V_66 ;
const T_1 V_258 = F_141 ( V_30 ) ? V_30 -> V_107 : V_30 -> V_180 ;
F_114 ( V_255 > V_30 -> V_110 ) ;
if ( V_30 -> V_118 ) {
V_4 = V_30 -> V_118 ;
V_145 = V_30 -> V_187 ;
if ( V_256 && V_4 != F_103 ( V_2 ) )
return;
} else {
V_4 = F_103 ( V_2 ) ;
V_145 = 0 ;
}
F_108 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
V_30 -> V_118 = V_4 ;
V_30 -> V_187 = V_145 ;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_258 ) )
break;
V_257 = V_145 ;
if ( F_65 ( V_30 ) || F_68 ( V_30 ) ||
( F_16 ( V_4 ) -> V_139 & V_141 ) )
V_145 += F_75 ( V_4 ) ;
if ( V_145 > V_255 ) {
if ( ( F_141 ( V_30 ) && ! F_65 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_139 & V_141 ) ||
( V_257 >= V_255 ) )
break;
V_66 = F_85 ( V_4 ) ;
V_166 = F_86 ( V_2 , V_4 , ( V_255 - V_257 ) * V_66 ,
V_66 , V_171 ) ;
if ( V_166 < 0 )
break;
V_145 = V_255 ;
}
F_74 ( V_30 , V_4 ) ;
if ( V_256 )
break;
}
F_117 ( V_30 ) ;
}
static void F_143 ( struct V_1 * V_2 , int V_259 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_68 ( V_30 ) ) {
F_142 ( V_2 , 1 , 1 ) ;
} else if ( F_65 ( V_30 ) ) {
int V_260 = V_30 -> V_132 - V_30 -> V_56 ;
if ( V_260 <= 0 )
V_260 = 1 ;
F_142 ( V_2 , V_260 , 0 ) ;
} else {
int V_261 = V_30 -> V_133 - V_30 -> V_56 ;
if ( V_261 >= 0 )
F_142 ( V_2 , V_261 , 0 ) ;
else if ( V_259 )
F_142 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_144 ( struct V_29 * V_30 )
{
V_30 -> V_55 = F_9 ( V_30 -> V_55 ,
F_118 ( V_30 ) + F_145 ( V_30 ) ) ;
V_30 -> V_80 = V_76 ;
}
static inline bool F_146 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_262 ||
( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 &&
F_46 ( V_30 -> V_49 . V_91 , V_30 -> V_262 ) ) ;
}
static bool F_147 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_148 )
return true ;
V_4 = F_103 ( V_2 ) ;
if ( F_102 ( V_4 && F_16 ( V_4 ) -> V_139 & V_191 ) )
return true ;
return false ;
}
static void F_148 ( struct V_1 * V_2 , const char * V_264 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_265 * V_266 = F_149 ( V_2 ) ;
if ( V_2 -> V_267 == V_268 ) {
F_71 ( L_2 ,
V_264 ,
& V_266 -> V_269 , F_150 ( V_266 -> V_270 ) ,
V_30 -> V_55 , F_151 ( V_30 ) ,
V_30 -> V_232 , V_30 -> V_231 ,
V_30 -> V_110 ) ;
}
#if F_152 ( V_271 )
else if ( V_2 -> V_267 == V_272 ) {
struct V_273 * V_274 = F_153 ( V_2 ) ;
F_71 ( L_3 ,
V_264 ,
& V_274 -> V_275 , F_150 ( V_266 -> V_270 ) ,
V_30 -> V_55 , F_151 ( V_30 ) ,
V_30 -> V_232 , V_30 -> V_231 ,
V_30 -> V_110 ) ;
}
#endif
}
static void F_154 ( struct V_1 * V_2 , bool V_276 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_276 ) {
struct V_3 * V_4 ;
F_80 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_139 &= ~ V_140 ;
}
V_30 -> V_137 = 0 ;
F_128 ( V_30 ) ;
}
if ( V_30 -> V_231 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_233 -> V_277 )
V_30 -> V_55 = V_6 -> V_233 -> V_277 ( V_2 ) ;
else
V_30 -> V_55 = F_37 ( V_30 -> V_55 , V_30 -> V_232 << 1 ) ;
if ( V_30 -> V_231 > V_30 -> V_232 ) {
V_30 -> V_232 = V_30 -> V_231 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_55 = F_37 ( V_30 -> V_55 , V_30 -> V_232 ) ;
}
V_30 -> V_80 = V_76 ;
V_30 -> V_134 = 0 ;
}
static inline bool F_155 ( const struct V_29 * V_30 )
{
return V_30 -> V_134 && ( ! V_30 -> V_135 || F_146 ( V_30 ) ) ;
}
static bool F_156 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_155 ( V_30 ) ) {
int V_124 ;
F_148 ( V_2 , F_2 ( V_2 ) -> V_131 == V_223 ? L_4 : L_5 ) ;
F_154 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_131 == V_223 )
V_124 = V_278 ;
else
V_124 = V_279 ;
F_69 ( F_70 ( V_2 ) , V_124 ) ;
}
if ( V_30 -> V_105 == V_30 -> V_180 && F_68 ( V_30 ) ) {
F_144 ( V_30 ) ;
if ( ! F_147 ( V_2 ) )
V_30 -> V_262 = 0 ;
return true ;
}
F_129 ( V_2 , V_280 ) ;
return false ;
}
static bool F_157 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_134 && ! V_30 -> V_135 ) {
F_148 ( V_2 , L_6 ) ;
F_154 ( V_2 , false ) ;
F_69 ( F_70 ( V_2 ) , V_281 ) ;
return true ;
}
return false ;
}
static bool F_158 ( struct V_1 * V_2 , bool V_282 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_282 || F_155 ( V_30 ) ) {
F_154 ( V_2 , true ) ;
F_148 ( V_2 , L_7 ) ;
F_69 ( F_70 ( V_2 ) , V_278 ) ;
if ( V_282 )
F_69 ( F_70 ( V_2 ) ,
V_283 ) ;
F_2 ( V_2 ) -> V_230 = 0 ;
if ( V_282 || F_141 ( V_30 ) )
F_129 ( V_2 , V_280 ) ;
return true ;
}
return false ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_180 = V_30 -> V_107 ;
V_30 -> V_284 = 0 ;
V_30 -> V_236 = 0 ;
V_30 -> V_285 = V_30 -> V_55 ;
V_30 -> V_286 = 0 ;
V_30 -> V_287 = 0 ;
V_30 -> V_232 = F_2 ( V_2 ) -> V_233 -> V_234 ( V_2 ) ;
F_12 ( V_30 ) ;
}
static void F_160 ( struct V_1 * V_2 , const int V_288 ,
int V_259 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_289 = 0 ;
int V_290 = V_30 -> V_232 - F_118 ( V_30 ) ;
int V_291 = V_288 -
( V_30 -> V_110 - V_30 -> V_133 ) ;
V_30 -> V_286 += V_291 ;
if ( F_118 ( V_30 ) > V_30 -> V_232 ) {
T_2 V_292 = ( T_2 ) V_30 -> V_232 * V_30 -> V_286 +
V_30 -> V_285 - 1 ;
V_289 = F_161 ( V_292 , V_30 -> V_285 ) - V_30 -> V_287 ;
} else {
V_289 = F_43 ( int , V_290 ,
F_24 ( int , V_30 -> V_286 - V_30 -> V_287 ,
V_291 ) + 1 ) ;
}
V_289 = F_37 ( V_289 , ( V_259 ? 1 : 0 ) ) ;
V_30 -> V_55 = F_118 ( V_30 ) + V_289 ;
}
static inline void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_131 == V_293 ||
( V_30 -> V_134 && V_30 -> V_232 < V_294 ) ) {
V_30 -> V_55 = V_30 -> V_232 ;
V_30 -> V_80 = V_76 ;
}
F_18 ( V_2 , V_295 ) ;
}
void F_163 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_231 = 0 ;
if ( F_2 ( V_2 ) -> V_131 < V_293 ) {
V_30 -> V_134 = 0 ;
F_159 ( V_2 ) ;
F_129 ( V_2 , V_293 ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_173 = V_280 ;
if ( F_151 ( V_30 ) || F_147 ( V_2 ) )
V_173 = V_229 ;
if ( F_2 ( V_2 ) -> V_131 != V_173 ) {
F_129 ( V_2 , V_173 ) ;
V_30 -> V_180 = V_30 -> V_107 ;
}
}
static void F_165 ( struct V_1 * V_2 , int V_181 , const int V_288 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_117 ( V_30 ) ;
if ( ! F_147 ( V_2 ) )
V_30 -> V_262 = 0 ;
if ( V_181 & V_248 )
F_163 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_131 != V_293 ) {
F_164 ( V_2 ) ;
} else {
F_160 ( V_2 , V_288 , 0 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_241 . V_296 = V_6 -> V_241 . V_242 - 1 ;
V_6 -> V_241 . V_242 = 0 ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_231 = F_127 ( V_2 ) ;
V_30 -> V_55 = V_30 -> V_55 *
F_168 ( V_2 , V_30 -> V_51 ) /
V_6 -> V_241 . V_242 ;
V_30 -> V_236 = 0 ;
V_30 -> V_80 = V_76 ;
V_30 -> V_232 = F_127 ( V_2 ) ;
V_6 -> V_241 . V_297 = V_6 -> V_241 . V_242 ;
V_6 -> V_241 . V_242 = 0 ;
F_169 ( V_2 , V_6 -> V_298 ) ;
}
void F_170 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_66 = F_171 ( V_2 ) ;
T_1 V_299 = V_30 -> V_137 ;
F_80 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
if ( F_96 ( V_4 ) > V_66 &&
! ( F_16 ( V_4 ) -> V_139 & V_141 ) ) {
if ( F_16 ( V_4 ) -> V_139 & V_152 ) {
F_16 ( V_4 ) -> V_139 &= ~ V_152 ;
V_30 -> V_148 -= F_75 ( V_4 ) ;
}
F_76 ( V_30 , V_4 ) ;
}
}
F_172 ( V_30 ) ;
if ( V_299 == V_30 -> V_137 )
return;
if ( F_68 ( V_30 ) )
F_119 ( V_30 ) ;
F_117 ( V_30 ) ;
if ( V_6 -> V_131 != V_223 ) {
V_30 -> V_180 = V_30 -> V_107 ;
V_30 -> V_232 = F_127 ( V_2 ) ;
V_30 -> V_231 = 0 ;
V_30 -> V_134 = 0 ;
F_129 ( V_2 , V_223 ) ;
}
F_173 ( V_2 ) ;
}
static void F_174 ( struct V_1 * V_2 , bool V_300 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_124 ;
if ( F_68 ( V_30 ) )
V_124 = V_301 ;
else
V_124 = V_302 ;
F_69 ( F_70 ( V_2 ) , V_124 ) ;
V_30 -> V_231 = 0 ;
F_125 ( V_30 ) ;
if ( F_2 ( V_2 ) -> V_131 < V_293 ) {
if ( ! V_300 )
V_30 -> V_231 = F_127 ( V_2 ) ;
F_159 ( V_2 ) ;
}
F_129 ( V_2 , V_150 ) ;
}
static void F_175 ( struct V_1 * V_2 , int V_181 , bool V_303 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_304 = ! F_46 ( V_30 -> V_105 , V_30 -> V_180 ) ;
if ( ( V_181 & V_305 ) &&
F_158 ( V_2 , false ) )
return;
if ( V_30 -> V_239 ) {
if ( ( V_181 & V_182 ) &&
F_158 ( V_2 , true ) )
return;
if ( F_53 ( V_30 -> V_107 , V_30 -> V_180 ) ) {
if ( V_181 & V_186 || V_303 )
V_30 -> V_239 = 0 ;
} else if ( V_181 & V_305 && ! V_304 ) {
V_30 -> V_180 = V_30 -> V_107 ;
F_176 ( V_2 , F_171 ( V_2 ) ,
V_306 ) ;
if ( F_53 ( V_30 -> V_107 , V_30 -> V_180 ) )
return;
V_30 -> V_239 = 0 ;
}
}
if ( V_304 ) {
F_156 ( V_2 ) ;
return;
}
if ( F_68 ( V_30 ) ) {
if ( F_53 ( V_30 -> V_107 , V_30 -> V_180 ) && V_303 )
F_121 ( V_2 ) ;
else if ( V_181 & V_305 )
F_123 ( V_30 ) ;
}
F_173 ( V_2 ) ;
}
static bool F_177 ( struct V_1 * V_2 , const int V_226 ,
const int V_288 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_134 && F_146 ( V_30 ) ) {
F_67 ( V_2 , F_134 ( V_30 ) + V_226 , 1 ) ;
if ( V_30 -> V_148 ) {
F_160 ( V_2 , V_288 , 0 ) ;
return true ;
}
if ( ! F_147 ( V_2 ) )
V_30 -> V_262 = 0 ;
F_148 ( V_2 , L_8 ) ;
F_154 ( V_2 , true ) ;
F_69 ( F_70 ( V_2 ) , V_307 ) ;
F_164 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_178 ( struct V_1 * V_2 , const int V_226 ,
const int V_288 ,
bool V_303 , int V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_308 = V_303 || ( ( V_181 & V_186 ) &&
( F_134 ( V_30 ) > V_30 -> V_56 ) ) ;
int V_259 = 0 ;
if ( F_114 ( ! V_30 -> V_110 && V_30 -> V_133 ) )
V_30 -> V_133 = 0 ;
if ( F_114 ( ! V_30 -> V_133 && V_30 -> V_132 ) )
V_30 -> V_132 = 0 ;
if ( V_181 & V_248 )
V_30 -> V_231 = 0 ;
if ( F_130 ( V_2 , V_181 ) )
return;
F_117 ( V_30 ) ;
if ( V_6 -> V_131 == V_280 ) {
F_114 ( V_30 -> V_148 != 0 ) ;
V_30 -> V_262 = 0 ;
} else if ( ! F_46 ( V_30 -> V_105 , V_30 -> V_180 ) ) {
switch ( V_6 -> V_131 ) {
case V_293 :
if ( V_30 -> V_105 != V_30 -> V_180 ) {
F_162 ( V_2 ) ;
F_129 ( V_2 , V_280 ) ;
}
break;
case V_150 :
if ( F_68 ( V_30 ) )
F_123 ( V_30 ) ;
if ( F_156 ( V_2 ) )
return;
F_162 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_131 ) {
case V_150 :
if ( ! ( V_181 & V_305 ) ) {
if ( F_68 ( V_30 ) && V_303 )
F_121 ( V_2 ) ;
} else {
if ( F_177 ( V_2 , V_226 , V_288 ) )
return;
V_308 = F_68 ( V_30 ) ||
F_134 ( V_30 ) > V_30 -> V_56 ;
}
if ( F_157 ( V_2 ) ) {
F_164 ( V_2 ) ;
return;
}
break;
case V_223 :
F_175 ( V_2 , V_181 , V_303 ) ;
if ( V_6 -> V_131 != V_280 )
return;
default:
if ( F_68 ( V_30 ) ) {
if ( V_181 & V_305 )
F_123 ( V_30 ) ;
if ( V_303 )
F_121 ( V_2 ) ;
}
if ( V_6 -> V_131 <= V_229 )
F_157 ( V_2 ) ;
if ( ! F_138 ( V_2 , V_181 ) ) {
F_165 ( V_2 , V_181 , V_288 ) ;
return;
}
if ( V_6 -> V_131 < V_293 &&
V_6 -> V_241 . V_242 &&
V_30 -> V_105 == V_30 -> V_309 . V_310 ) {
F_166 ( V_2 ) ;
V_30 -> V_55 ++ ;
F_170 ( V_2 ) ;
return;
}
F_174 ( V_2 , ( V_181 & V_248 ) ) ;
V_259 = 1 ;
}
if ( V_308 )
F_143 ( V_2 , V_259 ) ;
F_160 ( V_2 , V_288 , V_259 ) ;
F_173 ( V_2 ) ;
}
static inline bool F_179 ( struct V_1 * V_2 , const int V_181 ,
long V_311 , long V_312 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_181 & V_313 )
V_311 = - 1L ;
if ( V_311 < 0 )
V_311 = V_312 ;
if ( V_311 < 0 && V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 &&
V_181 & V_314 )
V_311 = F_180 ( V_76 - V_30 -> V_49 . V_91 ) ;
if ( V_311 < 0 )
return false ;
F_52 ( V_2 , V_311 ) ;
F_59 ( V_2 ) ;
F_2 ( V_2 ) -> V_315 = 0 ;
return true ;
}
static void F_181 ( struct V_1 * V_2 , const T_1 V_316 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_311 = - 1L ;
if ( V_316 && ! V_30 -> V_317 )
V_311 = F_180 ( V_76 - V_316 ) ;
if ( ! V_30 -> V_101 )
F_179 ( V_2 , V_318 , V_311 , - 1L ) ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_319 , T_1 V_226 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_233 -> V_320 ( V_2 , V_319 , V_226 ) ;
F_7 ( V_2 ) -> V_80 = V_76 ;
}
void F_183 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_321 )
return;
if ( ! V_30 -> V_110 ) {
F_184 ( V_2 , V_245 ) ;
} else {
T_1 V_322 = F_2 ( V_2 ) -> V_98 ;
if ( V_6 -> V_323 == V_251 ||
V_6 -> V_323 == V_324 ) {
struct V_3 * V_4 = F_103 ( V_2 ) ;
const T_1 V_325 =
F_185 ( V_4 ) + V_322 ;
T_5 V_290 = ( T_5 ) ( V_325 - V_76 ) ;
if ( V_290 > 0 )
V_322 = V_290 ;
}
F_133 ( V_2 , V_245 , V_322 ,
V_246 ) ;
}
}
void F_186 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_183 ( V_2 ) ;
if ( ! V_30 -> V_254 )
return;
F_174 ( V_2 , false ) ;
F_143 ( V_2 , 1 ) ;
F_173 ( V_2 ) ;
}
static T_1 F_187 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_326 ;
F_90 ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_105 ) ) ;
V_326 = F_75 ( V_4 ) ;
if ( F_188 ( V_2 , V_4 , V_30 -> V_105 - F_16 ( V_4 ) -> V_77 ) )
return 0 ;
V_326 -= F_75 ( V_4 ) ;
if ( V_326 ) {
F_90 ( F_75 ( V_4 ) == 0 ) ;
F_90 ( ! F_46 ( F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ) ;
}
return V_326 ;
}
static void F_189 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_158 )
{
const struct V_53 * V_327 ;
if ( F_56 ( ! ( V_2 -> V_328 & V_329 ) ) )
return;
V_327 = F_3 ( V_4 ) ;
if ( ( V_327 -> V_330 & V_331 ) &&
F_190 ( V_327 -> V_332 , V_158 , F_7 ( V_2 ) -> V_105 - 1 ) )
F_191 ( V_4 , NULL , V_2 , V_333 ) ;
}
static int F_192 ( struct V_1 * V_2 , int V_334 ,
T_1 V_158 ,
struct V_172 * V_335 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_175 V_336 , V_337 , V_96 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_338 = V_30 -> V_133 ;
T_1 V_179 = V_30 -> V_110 ;
bool V_339 = true ;
long V_312 = - 1L ;
long V_311 = - 1L ;
long V_340 = - 1L ;
struct V_3 * V_4 ;
T_1 V_341 = 0 ;
bool V_342 ;
int V_181 = 0 ;
V_336 . V_184 = 0 ;
while ( ( V_4 = F_103 ( V_2 ) ) && V_4 != F_81 ( V_2 ) ) {
struct V_343 * V_344 = F_16 ( V_4 ) ;
T_4 V_139 = V_344 -> V_139 ;
T_1 V_345 ;
F_189 ( V_2 , V_4 , V_158 ) ;
if ( F_53 ( V_344 -> V_92 , V_30 -> V_105 ) ) {
if ( F_75 ( V_4 ) == 1 ||
! F_53 ( V_30 -> V_105 , V_344 -> V_77 ) )
break;
V_345 = F_187 ( V_2 , V_4 ) ;
if ( ! V_345 )
break;
V_339 = false ;
} else {
F_193 ( V_4 -> V_346 ) ;
V_345 = F_75 ( V_4 ) ;
}
if ( F_102 ( V_139 & V_178 ) ) {
if ( V_139 & V_152 )
V_30 -> V_148 -= V_345 ;
V_181 |= V_313 ;
} else if ( ! ( V_139 & V_141 ) ) {
V_337 = V_4 -> V_175 ;
F_194 ( V_337 . V_184 == 0 ) ;
if ( ! V_336 . V_184 )
V_336 = V_337 ;
V_179 = F_9 ( V_341 , V_179 ) ;
if ( ! F_53 ( V_344 -> V_92 , V_30 -> V_180 ) )
V_181 |= V_182 ;
}
if ( V_139 & V_141 )
V_30 -> V_133 -= V_345 ;
if ( V_139 & V_140 )
V_30 -> V_137 -= V_345 ;
V_30 -> V_110 -= V_345 ;
V_341 += V_345 ;
if ( F_56 ( ! ( V_344 -> V_193 & V_347 ) ) ) {
V_181 |= V_348 ;
} else {
V_181 |= V_318 ;
V_30 -> V_262 = 0 ;
}
if ( ! V_339 )
break;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
if ( F_102 ( V_4 == V_30 -> V_136 ) )
V_30 -> V_136 = NULL ;
if ( F_102 ( V_4 == V_30 -> V_118 ) )
V_30 -> V_118 = NULL ;
}
if ( F_56 ( F_190 ( V_30 -> V_349 , V_158 , V_30 -> V_105 ) ) )
V_30 -> V_349 = V_30 -> V_105 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_139 & V_141 ) )
V_181 |= V_243 ;
F_195 ( & V_96 ) ;
if ( F_56 ( V_336 . V_184 ) ) {
V_311 = F_196 ( & V_96 , & V_336 ) ;
V_340 = F_196 ( & V_96 , & V_337 ) ;
}
if ( V_335 -> V_183 . V_184 ) {
V_312 = F_196 ( & V_96 , & V_335 -> V_183 ) ;
V_340 = F_196 ( & V_96 , & V_335 -> V_185 ) ;
}
V_342 = F_179 ( V_2 , V_181 , V_311 , V_312 ) ;
if ( V_181 & V_314 ) {
F_183 ( V_2 ) ;
if ( F_102 ( V_6 -> V_241 . V_242 &&
! F_53 ( V_30 -> V_309 . V_350 , V_30 -> V_105 ) ) ) {
F_167 ( V_2 ) ;
}
if ( F_68 ( V_30 ) ) {
F_122 ( V_2 , V_341 ) ;
} else {
int V_290 ;
if ( V_179 < V_334 )
F_67 ( V_2 , V_30 -> V_132 - V_179 , 0 ) ;
V_290 = F_65 ( V_30 ) ? V_341 :
V_338 - V_30 -> V_133 ;
V_30 -> V_187 -= F_9 ( V_30 -> V_187 , V_290 ) ;
}
V_30 -> V_132 -= F_9 ( V_341 , V_30 -> V_132 ) ;
} else if ( V_4 && V_342 && V_312 >= 0 &&
V_312 > F_196 ( & V_96 , & V_4 -> V_175 ) ) {
F_183 ( V_2 ) ;
}
if ( V_6 -> V_233 -> V_341 )
V_6 -> V_233 -> V_341 ( V_2 , V_341 , V_340 ) ;
#if V_130 > 0
F_114 ( ( int ) V_30 -> V_133 < 0 ) ;
F_114 ( ( int ) V_30 -> V_137 < 0 ) ;
F_114 ( ( int ) V_30 -> V_148 < 0 ) ;
if ( ! V_30 -> V_110 && F_141 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_137 ) {
F_71 ( L_9 ,
V_30 -> V_137 , V_6 -> V_131 ) ;
V_30 -> V_137 = 0 ;
}
if ( V_30 -> V_133 ) {
F_71 ( L_10 ,
V_30 -> V_133 , V_6 -> V_131 ) ;
V_30 -> V_133 = 0 ;
}
if ( V_30 -> V_148 ) {
F_71 ( L_11 ,
V_30 -> V_148 , V_6 -> V_131 ) ;
V_30 -> V_148 = 0 ;
}
}
#endif
return V_181 ;
}
static void F_197 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_53 ( F_16 ( F_81 ( V_2 ) ) -> V_92 , F_198 ( V_30 ) ) ) {
V_6 -> V_315 = 0 ;
F_184 ( V_2 , V_351 ) ;
} else {
unsigned long V_352 = F_199 ( V_2 , V_246 ) ;
F_133 ( V_2 , V_351 ,
V_352 , V_246 ) ;
}
}
static inline bool F_200 ( const struct V_1 * V_2 , const int V_181 )
{
return ! ( V_181 & V_353 ) || ( V_181 & V_354 ) ||
F_2 ( V_2 ) -> V_131 != V_280 ;
}
static inline bool F_201 ( const struct V_1 * V_2 , const int V_181 )
{
if ( F_202 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_56 > V_238 )
return V_181 & V_355 ;
return V_181 & V_348 ;
}
static inline bool F_203 ( const struct V_29 * V_30 ,
const T_1 V_319 , const T_1 V_151 ,
const T_1 V_356 )
{
return F_53 ( V_319 , V_30 -> V_105 ) ||
F_53 ( V_151 , V_30 -> V_357 ) ||
( V_151 == V_30 -> V_357 && V_356 > V_30 -> V_358 ) ;
}
static void F_204 ( struct V_29 * V_30 , T_1 V_319 )
{
T_1 V_290 = V_319 - V_30 -> V_105 ;
F_205 ( & V_30 -> V_359 ) ;
V_30 -> V_360 += V_290 ;
F_206 ( & V_30 -> V_359 ) ;
V_30 -> V_105 = V_319 ;
}
static void F_207 ( struct V_29 * V_30 , T_1 V_77 )
{
T_1 V_290 = V_77 - V_30 -> V_90 ;
F_205 ( & V_30 -> V_359 ) ;
V_30 -> V_361 += V_290 ;
F_206 ( & V_30 -> V_359 ) ;
V_30 -> V_90 = V_77 ;
}
static int F_208 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_319 ,
T_1 V_151 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_181 = 0 ;
T_1 V_356 = F_150 ( F_6 ( V_4 ) -> V_60 ) ;
if ( F_56 ( ! F_6 ( V_4 ) -> V_45 ) )
V_356 <<= V_30 -> V_49 . V_362 ;
if ( F_203 ( V_30 , V_319 , V_151 , V_356 ) ) {
V_181 |= V_363 ;
F_209 ( V_30 , V_151 ) ;
if ( V_30 -> V_358 != V_356 ) {
V_30 -> V_358 = V_356 ;
V_30 -> V_364 = 0 ;
F_210 ( V_2 ) ;
if ( V_356 > V_30 -> V_144 ) {
V_30 -> V_144 = V_356 ;
F_169 ( V_2 , F_2 ( V_2 ) -> V_298 ) ;
}
}
}
F_204 ( V_30 , V_319 ) ;
return V_181 ;
}
bool F_211 ( struct V_365 * V_365 , const struct V_3 * V_4 ,
int V_124 , T_1 * V_366 )
{
if ( ( F_16 ( V_4 ) -> V_77 != F_16 ( V_4 ) -> V_92 ) &&
! F_6 ( V_4 ) -> V_45 )
goto V_367;
if ( * V_366 ) {
T_5 V_368 = ( T_5 ) ( V_76 - * V_366 ) ;
if ( 0 <= V_368 && V_368 < V_369 ) {
F_69 ( V_365 , V_124 ) ;
return true ;
}
}
* V_366 = V_76 ;
V_367:
return false ;
}
static void F_212 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static T_1 V_370 ;
static unsigned int V_371 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_96 ;
if ( F_211 ( F_70 ( V_2 ) , V_4 ,
V_372 ,
& V_30 -> V_366 ) )
return;
V_96 = V_250 / V_373 ;
if ( V_96 != V_370 ) {
V_370 = V_96 ;
V_371 = 0 ;
}
if ( ++ V_371 <= V_374 ) {
F_69 ( F_70 ( V_2 ) , V_375 ) ;
F_213 ( V_2 ) ;
}
}
static void F_214 ( struct V_29 * V_30 )
{
V_30 -> V_49 . V_376 = V_30 -> V_49 . V_377 ;
V_30 -> V_49 . V_378 = F_215 () ;
}
static void F_216 ( struct V_29 * V_30 , T_1 V_77 )
{
if ( V_30 -> V_49 . V_263 && ! F_53 ( V_77 , V_30 -> V_379 ) ) {
if ( F_217 ( & V_30 -> V_49 , 0 ) )
F_214 ( V_30 ) ;
}
}
static void F_218 ( struct V_1 * V_2 , T_1 V_319 , int V_181 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_46 ( V_319 , V_30 -> V_284 ) )
return;
if ( V_181 & V_217 ) {
V_30 -> V_284 = 0 ;
} else if ( F_53 ( V_319 , V_30 -> V_284 ) ) {
F_159 ( V_2 ) ;
F_129 ( V_2 , V_293 ) ;
F_162 ( V_2 ) ;
F_164 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) ,
V_380 ) ;
} else if ( ! ( V_181 & ( V_305 |
V_353 | V_186 ) ) ) {
V_30 -> V_284 = 0 ;
}
}
static inline void F_219 ( struct V_1 * V_2 , T_1 V_381 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_233 -> V_382 )
V_6 -> V_233 -> V_382 ( V_2 , V_381 ) ;
}
static int F_220 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_172 V_383 ;
T_1 V_158 = V_30 -> V_105 ;
T_1 V_151 = F_16 ( V_4 ) -> V_77 ;
T_1 V_319 = F_16 ( V_4 ) -> V_151 ;
bool V_303 = false ;
T_1 V_334 ;
int V_384 = V_30 -> V_110 ;
const int V_288 = V_30 -> V_110 - V_30 -> V_133 ;
int V_226 = 0 ;
V_383 . V_183 . V_184 = 0 ;
F_193 ( V_2 -> V_385 . V_346 ) ;
if ( F_46 ( V_319 , V_158 ) ) {
if ( F_46 ( V_319 , V_158 - V_30 -> V_144 ) ) {
F_212 ( V_2 , V_4 ) ;
return - 1 ;
}
goto V_386;
}
if ( F_53 ( V_319 , V_30 -> V_107 ) )
goto V_387;
if ( V_6 -> V_323 == V_251 ||
V_6 -> V_323 == V_324 )
F_183 ( V_2 ) ;
if ( F_53 ( V_319 , V_158 ) ) {
V_181 |= V_305 ;
V_6 -> V_230 = 0 ;
}
V_334 = V_30 -> V_132 ;
if ( V_181 & V_388 )
F_216 ( V_30 , F_16 ( V_4 ) -> V_77 ) ;
if ( ! ( V_181 & V_389 ) && F_53 ( V_319 , V_158 ) ) {
F_209 ( V_30 , V_151 ) ;
F_204 ( V_30 , V_319 ) ;
V_181 |= V_363 ;
F_219 ( V_2 , V_390 ) ;
F_69 ( F_70 ( V_2 ) , V_391 ) ;
} else {
T_1 V_392 = V_393 ;
if ( V_151 != F_16 ( V_4 ) -> V_92 )
V_181 |= V_394 ;
else
F_69 ( F_70 ( V_2 ) , V_395 ) ;
V_181 |= F_208 ( V_2 , V_4 , V_319 , V_151 ) ;
if ( F_16 ( V_4 ) -> V_139 )
V_181 |= F_113 ( V_2 , V_4 , V_158 ,
& V_383 ) ;
if ( F_22 ( V_30 , F_6 ( V_4 ) ) ) {
V_181 |= V_248 ;
V_392 |= V_396 ;
}
if ( V_181 & V_363 )
V_392 |= V_390 ;
F_219 ( V_2 , V_392 ) ;
}
V_2 -> V_397 = 0 ;
V_6 -> V_398 = 0 ;
V_30 -> V_399 = V_76 ;
if ( ! V_384 )
goto V_400;
V_226 = V_30 -> V_110 ;
V_181 |= F_192 ( V_2 , V_334 , V_158 ,
& V_383 ) ;
V_226 -= V_30 -> V_110 ;
if ( F_201 ( V_2 , V_181 ) )
F_182 ( V_2 , V_319 , V_226 ) ;
if ( F_200 ( V_2 , V_181 ) ) {
V_303 = ! ( V_181 & ( V_305 | V_353 ) ) ;
F_178 ( V_2 , V_226 , V_288 ,
V_303 , V_181 ) ;
}
if ( V_30 -> V_284 )
F_218 ( V_2 , V_319 , V_181 ) ;
if ( ( V_181 & V_355 ) || ! ( V_181 & V_353 ) ) {
struct V_113 * V_114 = F_221 ( V_2 ) ;
if ( V_114 )
F_222 ( V_114 ) ;
}
if ( V_6 -> V_323 == V_245 )
F_223 ( V_2 ) ;
F_55 ( V_2 ) ;
return 1 ;
V_400:
if ( V_181 & V_217 )
F_178 ( V_2 , V_226 , V_288 ,
V_303 , V_181 ) ;
if ( F_81 ( V_2 ) )
F_197 ( V_2 ) ;
if ( V_30 -> V_284 )
F_218 ( V_2 , V_319 , V_181 ) ;
return 1 ;
V_387:
F_224 ( V_2 , L_12 , V_319 , V_30 -> V_105 , V_30 -> V_107 ) ;
return - 1 ;
V_386:
if ( F_16 ( V_4 ) -> V_139 ) {
V_181 |= F_113 ( V_2 , V_4 , V_158 ,
& V_383 ) ;
F_178 ( V_2 , V_226 , V_288 ,
V_303 , V_181 ) ;
}
F_224 ( V_2 , L_13 , V_319 , V_30 -> V_105 , V_30 -> V_107 ) ;
return 0 ;
}
static void F_225 ( int V_10 , const unsigned char * V_401 ,
bool V_45 , struct V_402 * V_403 ,
bool V_404 )
{
if ( ! V_403 || ! V_45 || V_10 < 0 || ( V_10 & 1 ) )
return;
if ( V_10 >= V_405 &&
V_10 <= V_406 )
memcpy ( V_403 -> V_407 , V_401 , V_10 ) ;
else if ( V_10 != 0 )
V_10 = - 1 ;
V_403 -> V_10 = V_10 ;
V_403 -> exp = V_404 ;
}
void F_226 ( const struct V_3 * V_4 ,
struct V_408 * V_409 , int V_410 ,
struct V_402 * V_403 )
{
const unsigned char * V_208 ;
const struct V_15 * V_43 = F_6 ( V_4 ) ;
int V_411 = ( V_43 -> V_412 * 4 ) - sizeof( struct V_15 ) ;
V_208 = ( const unsigned char * ) ( V_43 + 1 ) ;
V_409 -> V_263 = 0 ;
while ( V_411 > 0 ) {
int V_413 = * V_208 ++ ;
int V_414 ;
switch ( V_413 ) {
case V_415 :
return;
case V_416 :
V_411 -- ;
continue;
default:
V_414 = * V_208 ++ ;
if ( V_414 < 2 )
return;
if ( V_414 > V_411 )
return;
switch ( V_413 ) {
case V_417 :
if ( V_414 == V_418 && V_43 -> V_45 && ! V_410 ) {
T_6 V_419 = F_227 ( V_208 ) ;
if ( V_419 ) {
if ( V_409 -> V_420 &&
V_409 -> V_420 < V_419 )
V_419 = V_409 -> V_420 ;
V_409 -> V_50 = V_419 ;
}
}
break;
case V_421 :
if ( V_414 == V_422 && V_43 -> V_45 &&
! V_410 && V_423 ) {
T_7 V_362 = * ( T_7 * ) V_208 ;
V_409 -> V_424 = 1 ;
if ( V_362 > 14 ) {
F_228 ( L_14 ,
V_425 ,
V_362 ) ;
V_362 = 14 ;
}
V_409 -> V_362 = V_362 ;
}
break;
case V_426 :
if ( ( V_414 == V_427 ) &&
( ( V_410 && V_409 -> V_428 ) ||
( ! V_410 && V_429 ) ) ) {
V_409 -> V_263 = 1 ;
V_409 -> V_377 = F_83 ( V_208 ) ;
V_409 -> V_91 = F_83 ( V_208 + 4 ) ;
}
break;
case V_430 :
if ( V_414 == V_431 && V_43 -> V_45 &&
! V_410 && V_432 ) {
V_409 -> V_119 = V_433 ;
F_229 ( V_409 ) ;
}
break;
case V_434 :
if ( ( V_414 >= ( V_211 + V_435 ) ) &&
! ( ( V_414 - V_211 ) % V_435 ) &&
V_409 -> V_119 ) {
F_16 ( V_4 ) -> V_139 = ( V_208 - 2 ) - ( unsigned char * ) V_43 ;
}
break;
#ifdef F_230
case V_436 :
break;
#endif
case V_437 :
F_225 (
V_414 - V_438 ,
V_208 , V_43 -> V_45 , V_403 , false ) ;
break;
case V_439 :
if ( V_414 >= V_440 &&
F_227 ( V_208 ) ==
V_441 )
F_225 ( V_414 -
V_440 ,
V_208 + 2 , V_43 -> V_45 , V_403 , true ) ;
break;
}
V_208 += V_414 - 2 ;
V_411 -= V_414 ;
}
}
}
static bool F_231 ( struct V_29 * V_30 , const struct V_15 * V_43 )
{
const T_8 * V_208 = ( const T_8 * ) ( V_43 + 1 ) ;
if ( * V_208 == F_232 ( ( V_416 << 24 ) | ( V_416 << 16 )
| ( V_426 << 8 ) | V_427 ) ) {
V_30 -> V_49 . V_263 = 1 ;
++ V_208 ;
V_30 -> V_49 . V_377 = F_233 ( * V_208 ) ;
++ V_208 ;
if ( * V_208 )
V_30 -> V_49 . V_91 = F_233 ( * V_208 ) - V_30 -> V_442 ;
else
V_30 -> V_49 . V_91 = 0 ;
return true ;
}
return false ;
}
static bool F_234 ( const struct V_3 * V_4 ,
const struct V_15 * V_43 , struct V_29 * V_30 )
{
if ( V_43 -> V_412 == ( sizeof( * V_43 ) / 4 ) ) {
V_30 -> V_49 . V_263 = 0 ;
return false ;
} else if ( V_30 -> V_49 . V_428 &&
V_43 -> V_412 == ( ( sizeof( * V_43 ) + V_443 ) / 4 ) ) {
if ( F_231 ( V_30 , V_43 ) )
return true ;
}
F_226 ( V_4 , & V_30 -> V_49 , 1 , NULL ) ;
if ( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 )
V_30 -> V_49 . V_91 -= V_30 -> V_442 ;
return true ;
}
const T_4 * F_235 ( const struct V_15 * V_43 )
{
int V_411 = ( V_43 -> V_412 << 2 ) - sizeof( * V_43 ) ;
const T_4 * V_208 = ( const T_4 * ) ( V_43 + 1 ) ;
if ( V_411 < V_444 )
return NULL ;
while ( V_411 > 0 ) {
int V_413 = * V_208 ++ ;
int V_414 ;
switch ( V_413 ) {
case V_415 :
return NULL ;
case V_416 :
V_411 -- ;
continue;
default:
V_414 = * V_208 ++ ;
if ( V_414 < 2 || V_414 > V_411 )
return NULL ;
if ( V_413 == V_436 )
return V_414 == V_444 ? V_208 : NULL ;
}
V_208 += V_414 - 2 ;
V_411 -= V_414 ;
}
return NULL ;
}
static int F_236 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_43 = F_6 ( V_4 ) ;
T_1 V_77 = F_16 ( V_4 ) -> V_77 ;
T_1 V_319 = F_16 ( V_4 ) -> V_151 ;
return (
( V_43 -> V_319 && V_77 == F_16 ( V_4 ) -> V_92 && V_77 == V_30 -> V_90 ) &&
V_319 == V_30 -> V_105 &&
! F_203 ( V_30 , V_319 , V_77 , F_150 ( V_43 -> V_60 ) << V_30 -> V_49 . V_362 ) &&
( T_5 ) ( V_30 -> V_49 . V_376 - V_30 -> V_49 . V_377 ) <= ( F_2 ( V_2 ) -> V_98 * 1024 ) / V_373 ) ;
}
static inline bool F_237 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_217 ( & V_30 -> V_49 , V_445 ) &&
! F_236 ( V_2 , V_4 ) ;
}
static inline bool F_238 ( const struct V_29 * V_30 , T_1 V_77 , T_1 V_92 )
{
return ! F_46 ( V_92 , V_30 -> V_379 ) &&
! F_53 ( V_77 , V_30 -> V_90 + F_239 ( V_30 ) ) ;
}
void F_240 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_446 ) {
case V_447 :
V_2 -> V_448 = V_449 ;
break;
case V_450 :
V_2 -> V_448 = V_451 ;
break;
case V_452 :
return;
default:
V_2 -> V_448 = V_453 ;
}
F_241 () ;
if ( ! F_242 ( V_2 , V_454 ) )
V_2 -> V_455 ( V_2 ) ;
F_243 ( V_2 ) ;
}
static void F_244 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_113 * V_114 ;
F_50 ( V_2 ) ;
V_2 -> V_456 |= V_457 ;
F_245 ( V_2 , V_458 ) ;
switch ( V_2 -> V_446 ) {
case V_459 :
case V_460 :
F_246 ( V_2 , V_450 ) ;
V_114 = F_221 ( V_2 ) ;
if ( ! V_114 || ! F_63 ( V_114 , V_461 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_450 :
case V_462 :
break;
case V_463 :
break;
case V_464 :
F_213 ( V_2 ) ;
F_246 ( V_2 , V_462 ) ;
break;
case V_465 :
F_213 ( V_2 ) ;
F_247 ( V_2 , V_466 , 0 ) ;
break;
default:
F_248 ( L_15 ,
V_425 , V_2 -> V_446 ) ;
break;
}
F_249 ( & V_30 -> V_467 ) ;
if ( F_141 ( V_30 ) )
F_229 ( & V_30 -> V_49 ) ;
F_51 ( V_2 ) ;
if ( ! F_242 ( V_2 , V_454 ) ) {
V_2 -> V_468 ( V_2 ) ;
if ( V_2 -> V_456 == V_469 ||
V_2 -> V_446 == V_452 )
F_250 ( V_2 , V_470 , V_471 ) ;
else
F_250 ( V_2 , V_470 , V_472 ) ;
}
}
static inline bool F_251 ( struct V_201 * V_156 , T_1 V_77 ,
T_1 V_92 )
{
if ( ! F_53 ( V_77 , V_156 -> V_92 ) && ! F_53 ( V_156 -> V_143 , V_92 ) ) {
if ( F_46 ( V_77 , V_156 -> V_143 ) )
V_156 -> V_143 = V_77 ;
if ( F_53 ( V_92 , V_156 -> V_92 ) )
V_156 -> V_92 = V_92 ;
return true ;
}
return false ;
}
static void F_252 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_92 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_141 ( V_30 ) && V_473 ) {
int V_124 ;
if ( F_46 ( V_77 , V_30 -> V_90 ) )
V_124 = V_474 ;
else
V_124 = V_475 ;
F_69 ( F_70 ( V_2 ) , V_124 ) ;
V_30 -> V_49 . V_476 = 1 ;
V_30 -> V_477 [ 0 ] . V_143 = V_77 ;
V_30 -> V_477 [ 0 ] . V_92 = V_92 ;
}
}
static void F_253 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_92 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_49 . V_476 )
F_252 ( V_2 , V_77 , V_92 ) ;
else
F_251 ( V_30 -> V_477 , V_77 , V_92 ) ;
}
static void F_254 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_92 != F_16 ( V_4 ) -> V_77 &&
F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) ) {
F_69 ( F_70 ( V_2 ) , V_478 ) ;
F_10 ( V_2 ) ;
if ( F_141 ( V_30 ) && V_473 ) {
T_1 V_92 = F_16 ( V_4 ) -> V_92 ;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_90 ) )
V_92 = V_30 -> V_90 ;
F_252 ( V_2 , F_16 ( V_4 ) -> V_77 , V_92 ) ;
}
}
F_213 ( V_2 ) ;
}
static void F_255 ( struct V_29 * V_30 )
{
int V_479 ;
struct V_201 * V_156 = & V_30 -> V_480 [ 0 ] ;
struct V_201 * V_481 = V_156 + 1 ;
for ( V_479 = 1 ; V_479 < V_30 -> V_49 . V_157 ; ) {
if ( F_251 ( V_156 , V_481 -> V_143 , V_481 -> V_92 ) ) {
int V_214 ;
V_30 -> V_49 . V_157 -- ;
for ( V_214 = V_479 ; V_214 < V_30 -> V_49 . V_157 ; V_214 ++ )
V_156 [ V_214 ] = V_156 [ V_214 + 1 ] ;
continue;
}
V_479 ++ , V_481 ++ ;
}
}
static void F_256 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_92 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_201 * V_156 = & V_30 -> V_480 [ 0 ] ;
int V_482 = V_30 -> V_49 . V_157 ;
int V_479 ;
if ( ! V_482 )
goto V_483;
for ( V_479 = 0 ; V_479 < V_482 ; V_479 ++ , V_156 ++ ) {
if ( F_251 ( V_156 , V_77 , V_92 ) ) {
for (; V_479 > 0 ; V_479 -- , V_156 -- )
F_116 ( * V_156 , * ( V_156 - 1 ) ) ;
if ( V_482 > 1 )
F_255 ( V_30 ) ;
return;
}
}
if ( V_479 >= V_210 ) {
V_479 -- ;
V_30 -> V_49 . V_157 -- ;
V_156 -- ;
}
for (; V_479 > 0 ; V_479 -- , V_156 -- )
* V_156 = * ( V_156 - 1 ) ;
V_483:
V_156 -> V_143 = V_77 ;
V_156 -> V_92 = V_92 ;
V_30 -> V_49 . V_157 ++ ;
}
static void F_257 ( struct V_29 * V_30 )
{
struct V_201 * V_156 = & V_30 -> V_480 [ 0 ] ;
int V_157 = V_30 -> V_49 . V_157 ;
int V_479 ;
if ( F_258 ( & V_30 -> V_467 ) ) {
V_30 -> V_49 . V_157 = 0 ;
return;
}
for ( V_479 = 0 ; V_479 < V_157 ; ) {
if ( ! F_46 ( V_30 -> V_90 , V_156 -> V_143 ) ) {
int V_214 ;
F_114 ( F_46 ( V_30 -> V_90 , V_156 -> V_92 ) ) ;
for ( V_214 = V_479 + 1 ; V_214 < V_157 ; V_214 ++ )
V_30 -> V_480 [ V_214 - 1 ] = V_30 -> V_480 [ V_214 ] ;
V_157 -- ;
continue;
}
V_479 ++ ;
V_156 ++ ;
}
V_30 -> V_49 . V_157 = V_157 ;
}
static bool F_259 ( struct V_1 * V_2 ,
struct V_3 * V_484 ,
struct V_3 * V_485 ,
bool * V_486 )
{
int V_290 ;
* V_486 = false ;
if ( F_16 ( V_485 ) -> V_77 != F_16 ( V_484 ) -> V_92 )
return false ;
if ( ! F_260 ( V_484 , V_485 , V_486 , & V_290 ) )
return false ;
F_261 ( V_290 , & V_2 -> V_81 ) ;
F_262 ( V_2 , V_290 ) ;
F_69 ( F_70 ( V_2 ) , V_487 ) ;
F_16 ( V_484 ) -> V_92 = F_16 ( V_485 ) -> V_92 ;
F_16 ( V_484 ) -> V_151 = F_16 ( V_485 ) -> V_151 ;
F_16 ( V_484 ) -> V_193 |= F_16 ( V_485 ) -> V_193 ;
return true ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_488 = V_30 -> V_90 ;
struct V_3 * V_4 , * V_489 ;
bool V_486 , V_490 ;
while ( ( V_4 = F_264 ( & V_30 -> V_467 ) ) != NULL ) {
if ( F_53 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) )
break;
if ( F_46 ( F_16 ( V_4 ) -> V_77 , V_488 ) ) {
T_3 V_476 = V_488 ;
if ( F_46 ( F_16 ( V_4 ) -> V_92 , V_488 ) )
V_488 = F_16 ( V_4 ) -> V_92 ;
F_253 ( V_2 , F_16 ( V_4 ) -> V_77 , V_476 ) ;
}
F_265 ( V_4 , & V_30 -> V_467 ) ;
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_90 ) ) {
F_224 ( V_2 , L_16 ) ;
F_266 ( V_4 ) ;
continue;
}
F_224 ( V_2 , L_17 ,
V_30 -> V_90 , F_16 ( V_4 ) -> V_77 ,
F_16 ( V_4 ) -> V_92 ) ;
V_489 = F_267 ( & V_2 -> V_491 ) ;
V_490 = V_489 && F_259 ( V_2 , V_489 , V_4 , & V_486 ) ;
F_207 ( V_30 , F_16 ( V_4 ) -> V_92 ) ;
if ( ! V_490 )
F_268 ( & V_2 -> V_491 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_193 & V_194 )
F_244 ( V_2 ) ;
if ( V_490 )
F_269 ( V_4 , V_486 ) ;
}
}
static int F_270 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_492 )
{
if ( F_41 ( & V_2 -> V_81 ) > V_2 -> V_69 ||
! F_271 ( V_2 , V_4 , V_492 ) ) {
if ( F_272 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_271 ( V_2 , V_4 , V_492 ) ) {
if ( ! F_273 ( V_2 ) )
return - 1 ;
if ( ! F_271 ( V_2 , V_4 , V_492 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_274 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_493 ;
T_1 V_77 , V_92 ;
F_19 ( V_30 , V_4 ) ;
if ( F_102 ( F_270 ( V_2 , V_4 , V_4 -> V_59 ) ) ) {
F_69 ( F_70 ( V_2 ) , V_494 ) ;
F_266 ( V_4 ) ;
return;
}
V_30 -> V_364 = 0 ;
F_50 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_495 ) ;
F_224 ( V_2 , L_18 ,
V_30 -> V_90 , F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ;
V_493 = F_267 ( & V_30 -> V_467 ) ;
if ( ! V_493 ) {
if ( F_141 ( V_30 ) ) {
V_30 -> V_49 . V_157 = 1 ;
V_30 -> V_480 [ 0 ] . V_143 = F_16 ( V_4 ) -> V_77 ;
V_30 -> V_480 [ 0 ] . V_92 =
F_16 ( V_4 ) -> V_92 ;
}
F_275 ( & V_30 -> V_467 , V_4 ) ;
goto V_496;
}
V_77 = F_16 ( V_4 ) -> V_77 ;
V_92 = F_16 ( V_4 ) -> V_92 ;
if ( V_77 == F_16 ( V_493 ) -> V_92 ) {
bool V_486 ;
if ( ! F_259 ( V_2 , V_493 , V_4 , & V_486 ) ) {
F_276 ( & V_30 -> V_467 , V_493 , V_4 ) ;
} else {
F_29 ( V_2 , V_4 ) ;
F_269 ( V_4 , V_486 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_49 . V_157 ||
V_30 -> V_480 [ 0 ] . V_92 != V_77 )
goto V_497;
V_30 -> V_480 [ 0 ] . V_92 = V_92 ;
goto V_496;
}
while ( 1 ) {
if ( ! F_53 ( F_16 ( V_493 ) -> V_77 , V_77 ) )
break;
if ( F_277 ( & V_30 -> V_467 , V_493 ) ) {
V_493 = NULL ;
break;
}
V_493 = F_278 ( & V_30 -> V_467 , V_493 ) ;
}
if ( V_493 && F_46 ( V_77 , F_16 ( V_493 ) -> V_92 ) ) {
if ( ! F_53 ( V_92 , F_16 ( V_493 ) -> V_92 ) ) {
F_69 ( F_70 ( V_2 ) , V_498 ) ;
F_266 ( V_4 ) ;
V_4 = NULL ;
F_252 ( V_2 , V_77 , V_92 ) ;
goto V_497;
}
if ( F_53 ( V_77 , F_16 ( V_493 ) -> V_77 ) ) {
F_252 ( V_2 , V_77 ,
F_16 ( V_493 ) -> V_92 ) ;
} else {
if ( F_277 ( & V_30 -> V_467 ,
V_493 ) )
V_493 = NULL ;
else
V_493 = F_278 (
& V_30 -> V_467 ,
V_493 ) ;
}
}
if ( ! V_493 )
F_275 ( & V_30 -> V_467 , V_4 ) ;
else
F_276 ( & V_30 -> V_467 , V_493 , V_4 ) ;
while ( ! F_279 ( & V_30 -> V_467 , V_4 ) ) {
V_493 = F_280 ( & V_30 -> V_467 , V_4 ) ;
if ( ! F_53 ( V_92 , F_16 ( V_493 ) -> V_77 ) )
break;
if ( F_46 ( V_92 , F_16 ( V_493 ) -> V_92 ) ) {
F_253 ( V_2 , F_16 ( V_493 ) -> V_77 ,
V_92 ) ;
break;
}
F_265 ( V_493 , & V_30 -> V_467 ) ;
F_253 ( V_2 , F_16 ( V_493 ) -> V_77 ,
F_16 ( V_493 ) -> V_92 ) ;
F_69 ( F_70 ( V_2 ) , V_498 ) ;
F_266 ( V_493 ) ;
}
V_497:
if ( F_141 ( V_30 ) )
F_256 ( V_2 , V_77 , V_92 ) ;
V_496:
if ( V_4 ) {
F_29 ( V_2 , V_4 ) ;
F_281 ( V_4 , V_2 ) ;
}
}
static int T_9 F_282 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_499 ,
bool * V_486 )
{
int V_490 ;
struct V_3 * V_489 = F_267 ( & V_2 -> V_491 ) ;
F_283 ( V_4 , V_499 ) ;
V_490 = ( V_489 &&
F_259 ( V_2 , V_489 , V_4 , V_486 ) ) ? 1 : 0 ;
F_207 ( F_7 ( V_2 ) , F_16 ( V_4 ) -> V_92 ) ;
if ( ! V_490 ) {
F_268 ( & V_2 -> V_491 , V_4 ) ;
F_281 ( V_4 , V_2 ) ;
}
return V_490 ;
}
int F_284 ( struct V_1 * V_2 , struct V_500 * V_264 , T_10 V_492 )
{
struct V_3 * V_4 ;
bool V_486 ;
if ( V_492 == 0 )
return 0 ;
V_4 = F_285 ( V_492 , V_2 -> V_501 ) ;
if ( ! V_4 )
goto V_166;
if ( F_270 ( V_2 , V_4 , V_4 -> V_59 ) )
goto V_502;
if ( F_286 ( F_287 ( V_4 , V_492 ) , V_264 , V_492 ) )
goto V_502;
F_16 ( V_4 ) -> V_77 = F_7 ( V_2 ) -> V_90 ;
F_16 ( V_4 ) -> V_92 = F_16 ( V_4 ) -> V_77 + V_492 ;
F_16 ( V_4 ) -> V_151 = F_7 ( V_2 ) -> V_105 - 1 ;
if ( F_282 ( V_2 , V_4 , 0 , & V_486 ) ) {
F_194 ( V_486 ) ;
F_266 ( V_4 ) ;
}
return V_492 ;
V_502:
F_288 ( V_4 ) ;
V_166:
return - V_503 ;
}
static void F_289 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_490 = - 1 ;
bool V_486 = false ;
if ( F_16 ( V_4 ) -> V_77 == F_16 ( V_4 ) -> V_92 )
goto V_504;
F_290 ( V_4 ) ;
F_283 ( V_4 , F_6 ( V_4 ) -> V_412 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_49 . V_476 = 0 ;
if ( F_16 ( V_4 ) -> V_77 == V_30 -> V_90 ) {
if ( F_239 ( V_30 ) == 0 )
goto V_505;
if ( V_30 -> V_506 . V_507 == V_508 &&
V_30 -> V_78 == V_30 -> V_90 && V_30 -> V_506 . V_10 &&
F_291 ( V_2 ) && ! V_30 -> V_509 ) {
int V_510 = F_43 (unsigned int, skb->len,
tp->ucopy.len) ;
F_292 ( V_511 ) ;
F_293 () ;
if ( ! F_294 ( V_4 , 0 , V_30 -> V_506 . V_264 , V_510 ) ) {
V_30 -> V_506 . V_10 -= V_510 ;
V_30 -> V_78 += V_510 ;
V_490 = ( V_510 == V_4 -> V_10 ) ;
F_48 ( V_2 ) ;
}
F_295 () ;
}
if ( V_490 <= 0 ) {
V_512:
if ( V_490 < 0 ) {
if ( F_296 ( & V_2 -> V_491 ) == 0 )
F_297 ( V_2 , V_4 -> V_59 ) ;
else if ( F_270 ( V_2 , V_4 , V_4 -> V_59 ) )
goto V_504;
}
V_490 = F_282 ( V_2 , V_4 , 0 , & V_486 ) ;
}
F_207 ( V_30 , F_16 ( V_4 ) -> V_92 ) ;
if ( V_4 -> V_10 )
F_49 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_193 & V_194 )
F_244 ( V_2 ) ;
if ( ! F_258 ( & V_30 -> V_467 ) ) {
F_263 ( V_2 ) ;
if ( F_258 ( & V_30 -> V_467 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_49 . V_157 )
F_257 ( V_30 ) ;
F_210 ( V_2 ) ;
if ( V_490 > 0 )
F_269 ( V_4 , V_486 ) ;
if ( ! F_242 ( V_2 , V_454 ) )
V_2 -> V_513 ( V_2 ) ;
return;
}
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_90 ) ) {
F_69 ( F_70 ( V_2 ) , V_478 ) ;
F_252 ( V_2 , F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ;
V_505:
F_10 ( V_2 ) ;
F_50 ( V_2 ) ;
V_504:
F_266 ( V_4 ) ;
return;
}
if ( ! F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 + F_239 ( V_30 ) ) )
goto V_505;
F_10 ( V_2 ) ;
if ( F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) ) {
F_224 ( V_2 , L_19 ,
V_30 -> V_90 , F_16 ( V_4 ) -> V_77 ,
F_16 ( V_4 ) -> V_92 ) ;
F_252 ( V_2 , F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) ;
if ( ! F_239 ( V_30 ) )
goto V_505;
goto V_512;
}
F_274 ( V_2 , V_4 ) ;
}
static struct V_3 * F_298 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_514 * V_515 )
{
struct V_3 * V_346 = NULL ;
if ( ! F_279 ( V_515 , V_4 ) )
V_346 = F_280 ( V_515 , V_4 ) ;
F_265 ( V_4 , V_515 ) ;
F_266 ( V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_516 ) ;
return V_346 ;
}
static void
F_299 ( struct V_1 * V_2 , struct V_514 * V_515 ,
struct V_3 * V_517 , struct V_3 * V_489 ,
T_1 V_518 , T_1 V_496 )
{
struct V_3 * V_4 , * V_519 ;
bool V_520 ;
V_4 = V_517 ;
V_521:
V_520 = true ;
F_300 (list, skb, n) {
if ( V_4 == V_489 )
break;
if ( ! F_46 ( V_518 , F_16 ( V_4 ) -> V_92 ) ) {
V_4 = F_298 ( V_2 , V_4 , V_515 ) ;
if ( ! V_4 )
break;
goto V_521;
}
if ( ! ( F_16 ( V_4 ) -> V_193 & ( V_347 | V_194 ) ) &&
( F_28 ( V_4 -> V_59 ) > V_4 -> V_10 ||
F_46 ( F_16 ( V_4 ) -> V_77 , V_518 ) ) ) {
V_520 = false ;
break;
}
if ( ! F_279 ( V_515 , V_4 ) ) {
struct V_3 * V_346 = F_280 ( V_515 , V_4 ) ;
if ( V_346 != V_489 &&
F_16 ( V_4 ) -> V_92 != F_16 ( V_346 ) -> V_77 ) {
V_520 = false ;
break;
}
}
V_518 = F_16 ( V_4 ) -> V_92 ;
}
if ( V_520 ||
( F_16 ( V_4 ) -> V_193 & ( V_347 | V_194 ) ) )
return;
while ( F_46 ( V_518 , V_496 ) ) {
int V_522 = F_43 ( int , F_301 ( 0 , 0 ) , V_496 - V_518 ) ;
struct V_3 * V_523 ;
V_523 = F_285 ( V_522 , V_171 ) ;
if ( ! V_523 )
return;
memcpy ( V_523 -> V_524 , V_4 -> V_524 , sizeof( V_4 -> V_524 ) ) ;
F_16 ( V_523 ) -> V_77 = F_16 ( V_523 ) -> V_92 = V_518 ;
F_302 ( V_515 , V_4 , V_523 ) ;
F_281 ( V_523 , V_2 ) ;
while ( V_522 > 0 ) {
int V_525 = V_518 - F_16 ( V_4 ) -> V_77 ;
int V_492 = F_16 ( V_4 ) -> V_92 - V_518 ;
F_90 ( V_525 < 0 ) ;
if ( V_492 > 0 ) {
V_492 = F_9 ( V_522 , V_492 ) ;
if ( F_303 ( V_4 , V_525 , F_287 ( V_523 , V_492 ) , V_492 ) )
F_304 () ;
F_16 ( V_523 ) -> V_92 += V_492 ;
V_522 -= V_492 ;
V_518 += V_492 ;
}
if ( ! F_46 ( V_518 , F_16 ( V_4 ) -> V_92 ) ) {
V_4 = F_298 ( V_2 , V_4 , V_515 ) ;
if ( ! V_4 ||
V_4 == V_489 ||
( F_16 ( V_4 ) -> V_193 & ( V_347 | V_194 ) ) )
return;
}
}
}
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_264 ( & V_30 -> V_467 ) ;
struct V_3 * V_517 ;
T_1 V_518 , V_496 ;
if ( ! V_4 )
return;
V_518 = F_16 ( V_4 ) -> V_77 ;
V_496 = F_16 ( V_4 ) -> V_92 ;
V_517 = V_4 ;
for (; ; ) {
struct V_3 * V_346 = NULL ;
if ( ! F_279 ( & V_30 -> V_467 , V_4 ) )
V_346 = F_280 ( & V_30 -> V_467 , V_4 ) ;
V_4 = V_346 ;
if ( ! V_4 ||
F_53 ( F_16 ( V_4 ) -> V_77 , V_496 ) ||
F_46 ( F_16 ( V_4 ) -> V_92 , V_518 ) ) {
F_299 ( V_2 , & V_30 -> V_467 ,
V_517 , V_4 , V_518 , V_496 ) ;
V_517 = V_4 ;
if ( ! V_4 )
break;
V_518 = F_16 ( V_4 ) -> V_77 ;
V_496 = F_16 ( V_4 ) -> V_92 ;
} else {
if ( F_46 ( F_16 ( V_4 ) -> V_77 , V_518 ) )
V_518 = F_16 ( V_4 ) -> V_77 ;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_496 ) )
V_496 = F_16 ( V_4 ) -> V_92 ;
}
}
}
static bool F_273 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_526 = false ;
if ( ! F_258 ( & V_30 -> V_467 ) ) {
F_69 ( F_70 ( V_2 ) , V_527 ) ;
F_249 ( & V_30 -> V_467 ) ;
if ( V_30 -> V_49 . V_119 )
F_229 ( & V_30 -> V_49 ) ;
F_51 ( V_2 ) ;
V_526 = true ;
}
return V_526 ;
}
static int F_272 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_224 ( V_2 , L_20 , V_30 -> V_78 ) ;
F_69 ( F_70 ( V_2 ) , V_528 ) ;
if ( F_41 ( & V_2 -> V_81 ) >= V_2 -> V_69 )
F_38 ( V_2 ) ;
else if ( F_31 ( V_2 ) )
V_30 -> V_62 = F_9 ( V_30 -> V_62 , 4U * V_30 -> V_65 ) ;
F_305 ( V_2 ) ;
if ( ! F_258 ( & V_2 -> V_491 ) )
F_299 ( V_2 , & V_2 -> V_491 ,
F_264 ( & V_2 -> V_491 ) ,
NULL ,
V_30 -> V_78 , V_30 -> V_90 ) ;
F_51 ( V_2 ) ;
if ( F_41 ( & V_2 -> V_81 ) <= V_2 -> V_69 )
return 0 ;
F_273 ( V_2 ) ;
if ( F_41 ( & V_2 -> V_81 ) <= V_2 -> V_69 )
return 0 ;
F_69 ( F_70 ( V_2 ) , V_529 ) ;
V_30 -> V_364 = 0 ;
return - 1 ;
}
static bool F_306 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_71 & V_73 )
return false ;
if ( F_31 ( V_2 ) )
return false ;
if ( F_39 ( V_2 ) >= F_40 ( V_2 , 0 ) )
return false ;
if ( F_118 ( V_30 ) >= V_30 -> V_55 )
return false ;
return true ;
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_306 ( V_2 ) ) {
F_23 ( V_2 ) ;
V_30 -> V_80 = V_76 ;
}
V_2 -> V_530 ( V_2 ) ;
}
static void F_308 ( struct V_1 * V_2 )
{
if ( F_242 ( V_2 , V_531 ) ) {
F_309 ( V_2 , V_531 ) ;
F_310 () ;
if ( V_2 -> V_532 &&
F_311 ( V_533 , & V_2 -> V_532 -> V_381 ) )
F_307 ( V_2 ) ;
}
}
static inline void F_312 ( struct V_1 * V_2 )
{
F_313 ( V_2 ) ;
F_308 ( V_2 ) ;
}
static void F_314 ( struct V_1 * V_2 , int V_534 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_90 - V_30 -> V_379 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_315 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_534 && F_264 ( & V_30 -> V_467 ) ) ) {
F_213 ( V_2 ) ;
} else {
F_316 ( V_2 ) ;
}
}
static inline void F_317 ( struct V_1 * V_2 )
{
if ( ! F_318 ( V_2 ) ) {
return;
}
F_314 ( V_2 , 1 ) ;
}
static void F_319 ( struct V_1 * V_2 , const struct V_15 * V_43 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_208 = F_150 ( V_43 -> V_535 ) ;
if ( V_208 && ! V_536 )
V_208 -- ;
V_208 += F_233 ( V_43 -> V_77 ) ;
if ( F_53 ( V_30 -> V_78 , V_208 ) )
return;
if ( F_46 ( V_208 , V_30 -> V_90 ) )
return;
if ( V_30 -> V_509 && ! F_53 ( V_208 , V_30 -> V_537 ) )
return;
F_320 ( V_2 ) ;
if ( V_30 -> V_537 == V_30 -> V_78 && V_30 -> V_509 &&
! F_242 ( V_2 , V_538 ) && V_30 -> V_78 != V_30 -> V_90 ) {
struct V_3 * V_4 = F_264 ( & V_2 -> V_491 ) ;
V_30 -> V_78 ++ ;
if ( V_4 && ! F_46 ( V_30 -> V_78 , F_16 ( V_4 ) -> V_92 ) ) {
F_265 ( V_4 , & V_2 -> V_491 ) ;
F_266 ( V_4 ) ;
}
}
V_30 -> V_509 = V_539 ;
V_30 -> V_537 = V_208 ;
V_30 -> V_364 = 0 ;
}
static void F_321 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_43 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_43 -> V_540 )
F_319 ( V_2 , V_43 ) ;
if ( V_30 -> V_509 == V_539 ) {
T_1 V_208 = V_30 -> V_537 - F_233 ( V_43 -> V_77 ) + ( V_43 -> V_412 * 4 ) -
V_43 -> V_45 ;
if ( V_208 < V_4 -> V_10 ) {
T_4 V_204 ;
if ( F_303 ( V_4 , V_208 , & V_204 , 1 ) )
F_304 () ;
V_30 -> V_509 = V_541 | V_204 ;
if ( ! F_242 ( V_2 , V_454 ) )
V_2 -> V_513 ( V_2 ) ;
}
}
}
static int F_322 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_542 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_510 = V_4 -> V_10 - V_542 ;
int V_166 ;
F_293 () ;
if ( F_323 ( V_4 ) )
V_166 = F_294 ( V_4 , V_542 , V_30 -> V_506 . V_264 , V_510 ) ;
else
V_166 = F_324 ( V_4 , V_542 , V_30 -> V_506 . V_264 ) ;
if ( ! V_166 ) {
V_30 -> V_506 . V_10 -= V_510 ;
V_30 -> V_78 += V_510 ;
F_48 ( V_2 ) ;
}
F_295 () ;
return V_166 ;
}
static T_11 F_325 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_543 ;
if ( F_291 ( V_2 ) ) {
F_293 () ;
V_543 = F_326 ( V_4 ) ;
F_295 () ;
} else {
V_543 = F_326 ( V_4 ) ;
}
return V_543 ;
}
static inline bool F_327 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_323 ( V_4 ) &&
F_325 ( V_2 , V_4 ) ;
}
static bool F_328 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , int V_544 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_234 ( V_4 , V_43 , V_30 ) && V_30 -> V_49 . V_263 &&
F_237 ( V_2 , V_4 ) ) {
if ( ! V_43 -> V_545 ) {
F_69 ( F_70 ( V_2 ) , V_546 ) ;
if ( ! F_211 ( F_70 ( V_2 ) , V_4 ,
V_547 ,
& V_30 -> V_366 ) )
F_254 ( V_2 , V_4 ) ;
goto V_548;
}
}
if ( ! F_238 ( V_30 , F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ) {
if ( ! V_43 -> V_545 ) {
if ( V_43 -> V_45 )
goto V_549;
if ( ! F_211 ( F_70 ( V_2 ) , V_4 ,
V_550 ,
& V_30 -> V_366 ) )
F_254 ( V_2 , V_4 ) ;
}
goto V_548;
}
if ( V_43 -> V_545 ) {
if ( F_16 ( V_4 ) -> V_77 == V_30 -> V_90 )
F_240 ( V_2 ) ;
else
F_212 ( V_2 , V_4 ) ;
goto V_548;
}
if ( V_43 -> V_45 ) {
V_549:
if ( V_544 )
F_329 ( F_70 ( V_2 ) , V_551 ) ;
F_69 ( F_70 ( V_2 ) , V_552 ) ;
F_212 ( V_2 , V_4 ) ;
goto V_548;
}
return true ;
V_548:
F_266 ( V_4 ) ;
return false ;
}
void F_330 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_102 ( ! V_2 -> V_553 ) )
F_2 ( V_2 ) -> V_554 -> V_555 ( V_2 , V_4 ) ;
V_30 -> V_49 . V_263 = 0 ;
if ( ( F_5 ( V_43 ) & V_556 ) == V_30 -> V_364 &&
F_16 ( V_4 ) -> V_77 == V_30 -> V_90 &&
! F_53 ( F_16 ( V_4 ) -> V_151 , V_30 -> V_107 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_443 ) {
if ( ! F_231 ( V_30 , V_43 ) )
goto V_557;
if ( ( T_5 ) ( V_30 -> V_49 . V_377 - V_30 -> V_49 . V_376 ) < 0 )
goto V_557;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_443 ) &&
V_30 -> V_90 == V_30 -> V_379 )
F_214 ( V_30 ) ;
F_220 ( V_2 , V_4 , 0 ) ;
F_266 ( V_4 ) ;
F_312 ( V_2 ) ;
return;
} else {
F_329 ( F_70 ( V_2 ) , V_551 ) ;
goto V_548;
}
} else {
int V_490 = 0 ;
bool V_486 = false ;
if ( V_30 -> V_506 . V_507 == V_508 &&
V_30 -> V_78 == V_30 -> V_90 &&
V_10 - V_18 <= V_30 -> V_506 . V_10 &&
F_291 ( V_2 ) ) {
F_292 ( V_511 ) ;
if ( ! F_322 ( V_2 , V_4 , V_18 ) ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_443 ) &&
V_30 -> V_90 == V_30 -> V_379 )
F_214 ( V_30 ) ;
F_47 ( V_2 , V_4 ) ;
F_283 ( V_4 , V_18 ) ;
F_207 ( V_30 , F_16 ( V_4 ) -> V_92 ) ;
F_69 ( F_70 ( V_2 ) , V_558 ) ;
V_490 = 1 ;
}
}
if ( ! V_490 ) {
if ( F_327 ( V_2 , V_4 ) )
goto V_559;
if ( ( int ) V_4 -> V_59 > V_2 -> V_560 )
goto V_561;
if ( V_18 ==
( sizeof( struct V_15 ) + V_443 ) &&
V_30 -> V_90 == V_30 -> V_379 )
F_214 ( V_30 ) ;
F_47 ( V_2 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_562 ) ;
V_490 = F_282 ( V_2 , V_4 , V_18 ,
& V_486 ) ;
}
F_49 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_151 != V_30 -> V_105 ) {
F_220 ( V_2 , V_4 , V_394 ) ;
F_312 ( V_2 ) ;
if ( ! F_318 ( V_2 ) )
goto V_563;
}
F_314 ( V_2 , 0 ) ;
V_563:
if ( V_490 )
F_269 ( V_4 , V_486 ) ;
V_2 -> V_513 ( V_2 ) ;
return;
}
}
V_557:
if ( V_10 < ( V_43 -> V_412 << 2 ) || F_327 ( V_2 , V_4 ) )
goto V_559;
if ( ! V_43 -> V_319 && ! V_43 -> V_545 && ! V_43 -> V_45 )
goto V_548;
if ( ! F_328 ( V_2 , V_4 , V_43 , 1 ) )
return;
V_561:
if ( F_220 ( V_2 , V_4 , V_389 | V_388 ) < 0 )
goto V_548;
F_47 ( V_2 , V_4 ) ;
F_321 ( V_2 , V_4 , V_43 ) ;
F_289 ( V_2 , V_4 ) ;
F_312 ( V_2 ) ;
F_317 ( V_2 ) ;
return;
V_559:
F_329 ( F_70 ( V_2 ) , V_564 ) ;
F_329 ( F_70 ( V_2 ) , V_551 ) ;
V_548:
F_266 ( V_4 ) ;
}
void F_331 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_246 ( V_2 , V_460 ) ;
if ( V_4 ) {
V_6 -> V_554 -> V_555 ( V_2 , V_4 ) ;
F_332 ( V_2 , V_4 ) ;
}
V_6 -> V_554 -> V_565 ( V_2 ) ;
F_333 ( V_2 ) ;
F_334 ( V_2 ) ;
V_30 -> V_566 = V_76 ;
F_35 ( V_2 ) ;
if ( F_242 ( V_2 , V_567 ) )
F_335 ( V_2 , F_336 ( V_30 ) ) ;
if ( ! V_30 -> V_49 . V_362 )
F_337 ( V_30 , V_30 -> V_358 ) ;
else
V_30 -> V_364 = 0 ;
if ( ! F_242 ( V_2 , V_454 ) ) {
V_2 -> V_468 ( V_2 ) ;
F_250 ( V_2 , V_568 , V_569 ) ;
}
}
static bool F_338 ( struct V_1 * V_2 , struct V_3 * V_570 ,
struct V_402 * V_401 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_571 ? F_103 ( V_2 ) : NULL ;
T_6 V_66 = V_30 -> V_49 . V_50 , V_572 = 0 ;
bool V_573 = false ;
if ( V_66 == V_30 -> V_49 . V_420 ) {
struct V_408 V_574 ;
F_339 ( & V_574 ) ;
V_574 . V_420 = V_574 . V_50 = 0 ;
F_226 ( V_570 , & V_574 , 0 , NULL ) ;
V_66 = V_574 . V_50 ;
}
if ( ! V_30 -> V_575 ) {
V_401 -> V_10 = - 1 ;
} else if ( V_30 -> V_317 ) {
V_573 = ( V_401 -> V_10 < 0 && V_13 ) ;
} else if ( V_401 -> V_10 < 0 && ! V_30 -> V_571 ) {
V_572 = V_30 -> V_576 ? 2 : 1 ;
}
F_340 ( V_2 , V_66 , V_401 , V_573 , V_572 ) ;
if ( V_13 ) {
F_108 (data, sk) {
if ( V_13 == F_81 ( V_2 ) ||
F_341 ( V_2 , V_13 ) )
break;
}
F_183 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_577 ) ;
return true ;
}
V_30 -> V_578 = V_30 -> V_571 ;
if ( V_30 -> V_578 )
F_69 ( F_70 ( V_2 ) , V_579 ) ;
return false ;
}
static int F_342 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_402 V_403 = { . V_10 = - 1 } ;
int V_580 = V_30 -> V_49 . V_50 ;
F_226 ( V_4 , & V_30 -> V_49 , 0 , & V_403 ) ;
if ( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 )
V_30 -> V_49 . V_91 -= V_30 -> V_442 ;
if ( V_43 -> V_319 ) {
if ( ! F_53 ( F_16 ( V_4 ) -> V_151 , V_30 -> V_105 ) ||
F_53 ( F_16 ( V_4 ) -> V_151 , V_30 -> V_107 ) )
goto V_581;
if ( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 &&
! F_190 ( V_30 -> V_49 . V_91 , V_30 -> V_262 ,
V_76 ) ) {
F_69 ( F_70 ( V_2 ) , V_582 ) ;
goto V_581;
}
if ( V_43 -> V_545 ) {
F_240 ( V_2 ) ;
goto V_548;
}
if ( ! V_43 -> V_45 )
goto V_583;
F_20 ( V_30 , V_43 ) ;
F_343 ( V_30 , F_16 ( V_4 ) -> V_77 ) ;
F_220 ( V_2 , V_4 , V_389 ) ;
V_30 -> V_90 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_379 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_358 = F_150 ( V_43 -> V_60 ) ;
if ( ! V_30 -> V_49 . V_424 ) {
V_30 -> V_49 . V_362 = V_30 -> V_49 . V_584 = 0 ;
V_30 -> V_63 = F_9 ( V_30 -> V_63 , 65535U ) ;
}
if ( V_30 -> V_49 . V_263 ) {
V_30 -> V_49 . V_428 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_443 ;
V_30 -> V_65 -= V_443 ;
F_214 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_141 ( V_30 ) && V_585 )
F_344 ( V_30 ) ;
F_345 ( V_2 ) ;
F_169 ( V_2 , V_6 -> V_298 ) ;
F_42 ( V_2 ) ;
V_30 -> V_78 = V_30 -> V_90 ;
F_346 () ;
F_331 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_575 || V_30 -> V_571 ) &&
F_338 ( V_2 , V_4 , & V_403 ) )
return - 1 ;
if ( V_2 -> V_586 ||
V_6 -> V_587 . V_588 ||
V_6 -> V_8 . V_26 ) {
F_50 ( V_2 ) ;
V_6 -> V_8 . V_97 = V_76 ;
F_10 ( V_2 ) ;
F_133 ( V_2 , V_589 ,
V_590 , V_246 ) ;
V_548:
F_266 ( V_4 ) ;
return 0 ;
} else {
F_213 ( V_2 ) ;
}
return - 1 ;
}
if ( V_43 -> V_545 ) {
goto V_583;
}
if ( V_30 -> V_49 . V_378 && V_30 -> V_49 . V_263 &&
F_347 ( & V_30 -> V_49 , 0 ) )
goto V_583;
if ( V_43 -> V_45 ) {
F_246 ( V_2 , V_459 ) ;
if ( V_30 -> V_49 . V_263 ) {
V_30 -> V_49 . V_428 = 1 ;
F_214 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_443 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_90 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_379 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_358 = F_150 ( V_43 -> V_60 ) ;
V_30 -> V_357 = F_16 ( V_4 ) -> V_77 ;
V_30 -> V_144 = V_30 -> V_358 ;
F_21 ( V_30 , V_43 ) ;
F_345 ( V_2 ) ;
F_169 ( V_2 , V_6 -> V_298 ) ;
F_42 ( V_2 ) ;
F_348 ( V_2 ) ;
#if 0
return -1;
#else
goto V_548;
#endif
}
V_583:
F_339 ( & V_30 -> V_49 ) ;
V_30 -> V_49 . V_50 = V_580 ;
goto V_548;
V_581:
F_339 ( & V_30 -> V_49 ) ;
V_30 -> V_49 . V_50 = V_580 ;
return 1 ;
}
int F_349 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_591 * V_592 ;
int V_593 = 0 ;
bool V_594 ;
T_1 V_316 ;
V_30 -> V_49 . V_263 = 0 ;
switch ( V_2 -> V_446 ) {
case V_452 :
goto V_548;
case V_595 :
if ( V_43 -> V_319 )
return 1 ;
if ( V_43 -> V_545 )
goto V_548;
if ( V_43 -> V_45 ) {
if ( V_43 -> V_596 )
goto V_548;
if ( V_6 -> V_554 -> V_597 ( V_2 , V_4 ) < 0 )
return 1 ;
F_288 ( V_4 ) ;
return 0 ;
}
goto V_548;
case V_447 :
V_593 = F_342 ( V_2 , V_4 , V_43 , V_10 ) ;
if ( V_593 >= 0 )
return V_593 ;
F_321 ( V_2 , V_4 , V_43 ) ;
F_266 ( V_4 ) ;
F_312 ( V_2 ) ;
return 0 ;
}
V_592 = V_30 -> V_321 ;
if ( V_592 ) {
F_194 ( V_2 -> V_446 != V_459 &&
V_2 -> V_446 != V_464 ) ;
if ( ! F_350 ( V_2 , V_4 , V_592 , true ) )
goto V_548;
}
if ( ! V_43 -> V_319 && ! V_43 -> V_545 && ! V_43 -> V_45 )
goto V_548;
if ( ! F_328 ( V_2 , V_4 , V_43 , 0 ) )
return 0 ;
V_594 = F_220 ( V_2 , V_4 , V_389 |
V_388 ) > 0 ;
switch ( V_2 -> V_446 ) {
case V_459 :
if ( ! V_594 )
return 1 ;
if ( V_592 ) {
V_316 = F_351 ( V_592 ) -> V_598 ;
V_30 -> V_317 = V_592 -> V_599 ;
F_352 ( V_2 , V_592 , false ) ;
} else {
V_316 = V_30 -> V_566 ;
V_6 -> V_554 -> V_565 ( V_2 ) ;
F_334 ( V_2 ) ;
F_345 ( V_2 ) ;
V_30 -> V_78 = V_30 -> V_90 ;
F_35 ( V_2 ) ;
}
F_346 () ;
F_246 ( V_2 , V_460 ) ;
V_2 -> V_468 ( V_2 ) ;
if ( V_2 -> V_532 )
F_250 ( V_2 , V_568 , V_569 ) ;
V_30 -> V_105 = F_16 ( V_4 ) -> V_151 ;
V_30 -> V_358 = F_150 ( V_43 -> V_60 ) << V_30 -> V_49 . V_362 ;
F_343 ( V_30 , F_16 ( V_4 ) -> V_77 ) ;
F_181 ( V_2 , V_316 ) ;
if ( V_30 -> V_49 . V_428 )
V_30 -> V_65 -= V_443 ;
if ( V_592 ) {
F_183 ( V_2 ) ;
} else
F_333 ( V_2 ) ;
F_55 ( V_2 ) ;
V_30 -> V_566 = V_76 ;
F_42 ( V_2 ) ;
F_353 ( V_30 ) ;
break;
case V_464 : {
struct V_113 * V_114 ;
int V_600 ;
if ( V_592 ) {
if ( ! V_594 )
return 1 ;
F_352 ( V_2 , V_592 , false ) ;
F_183 ( V_2 ) ;
}
if ( V_30 -> V_105 != V_30 -> V_601 )
break;
F_246 ( V_2 , V_465 ) ;
V_2 -> V_456 |= V_602 ;
V_114 = F_221 ( V_2 ) ;
if ( V_114 )
F_222 ( V_114 ) ;
if ( ! F_242 ( V_2 , V_454 ) ) {
V_2 -> V_468 ( V_2 ) ;
break;
}
if ( V_30 -> V_603 < 0 ||
( F_16 ( V_4 ) -> V_92 != F_16 ( V_4 ) -> V_77 &&
F_53 ( F_16 ( V_4 ) -> V_92 - V_43 -> V_596 , V_30 -> V_90 ) ) ) {
F_243 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_604 ) ;
return 1 ;
}
V_600 = F_354 ( V_2 ) ;
if ( V_600 > V_605 ) {
F_335 ( V_2 , V_600 - V_605 ) ;
} else if ( V_43 -> V_596 || F_291 ( V_2 ) ) {
F_335 ( V_2 , V_600 ) ;
} else {
F_247 ( V_2 , V_465 , V_600 ) ;
goto V_548;
}
break;
}
case V_462 :
if ( V_30 -> V_105 == V_30 -> V_601 ) {
F_247 ( V_2 , V_466 , 0 ) ;
goto V_548;
}
break;
case V_463 :
if ( V_30 -> V_105 == V_30 -> V_601 ) {
F_355 ( V_2 ) ;
F_243 ( V_2 ) ;
goto V_548;
}
break;
}
F_321 ( V_2 , V_4 , V_43 ) ;
switch ( V_2 -> V_446 ) {
case V_450 :
case V_462 :
case V_463 :
if ( ! F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) )
break;
case V_464 :
case V_465 :
if ( V_2 -> V_456 & V_457 ) {
if ( F_16 ( V_4 ) -> V_92 != F_16 ( V_4 ) -> V_77 &&
F_53 ( F_16 ( V_4 ) -> V_92 - V_43 -> V_596 , V_30 -> V_90 ) ) {
F_69 ( F_70 ( V_2 ) , V_604 ) ;
F_240 ( V_2 ) ;
return 1 ;
}
}
case V_460 :
F_289 ( V_2 , V_4 ) ;
V_593 = 1 ;
break;
}
if ( V_2 -> V_446 != V_452 ) {
F_312 ( V_2 ) ;
F_317 ( V_2 ) ;
}
if ( ! V_593 ) {
V_548:
F_266 ( V_4 ) ;
}
return 0 ;
}
static inline void F_356 ( struct V_591 * V_592 , T_12 V_606 , int V_607 )
{
struct V_608 * V_609 = F_357 ( V_592 ) ;
if ( V_607 == V_268 )
F_358 ( L_21 ,
& V_609 -> V_610 , V_606 ) ;
#if F_152 ( V_271 )
else if ( V_607 == V_272 )
F_358 ( L_22 ,
& V_609 -> V_611 , V_606 ) ;
#endif
}
static void F_359 ( struct V_591 * V_592 ,
const struct V_3 * V_4 ,
const struct V_1 * V_612 ,
const struct V_113 * V_114 )
{
const struct V_15 * V_43 = F_6 ( V_4 ) ;
const struct V_365 * V_365 = F_70 ( V_612 ) ;
bool V_613 = V_43 -> V_44 && V_43 -> V_34 ;
bool V_614 , V_615 ;
if ( ! V_613 )
return;
V_614 = ! F_360 ( F_16 ( V_4 ) -> V_36 ) ;
V_615 = V_365 -> V_616 . V_617 || F_361 ( V_114 , V_618 ) ;
if ( ( ! V_614 && V_615 ) || F_17 ( V_612 ) )
F_357 ( V_592 ) -> V_615 = 1 ;
}
static void F_362 ( struct V_591 * V_592 ,
const struct V_408 * V_49 ,
struct V_3 * V_4 , const struct V_1 * V_2 )
{
struct V_608 * V_609 = F_357 ( V_592 ) ;
V_592 -> V_23 = 0 ;
V_592 -> V_619 = 0 ;
F_351 ( V_592 ) -> V_620 = F_16 ( V_4 ) -> V_77 ;
F_351 ( V_592 ) -> V_90 = F_16 ( V_4 ) -> V_77 + 1 ;
F_351 ( V_592 ) -> V_598 = V_76 ;
F_351 ( V_592 ) -> V_366 = 0 ;
V_592 -> V_66 = V_49 -> V_50 ;
V_592 -> V_376 = V_49 -> V_263 ? V_49 -> V_377 : 0 ;
V_609 -> V_428 = V_49 -> V_428 ;
V_609 -> V_119 = V_49 -> V_119 ;
V_609 -> V_362 = V_49 -> V_362 ;
V_609 -> V_424 = V_49 -> V_424 ;
V_609 -> V_226 = 0 ;
V_609 -> V_615 = 0 ;
V_609 -> V_621 = F_6 ( V_4 ) -> V_622 ;
V_609 -> V_623 = F_150 ( F_6 ( V_4 ) -> V_624 ) ;
V_609 -> V_625 = F_363 ( V_2 , V_4 ) ;
}
struct V_591 * F_364 ( const struct V_626 * V_627 ,
struct V_1 * V_628 )
{
struct V_591 * V_592 = F_365 ( V_627 , V_628 ) ;
if ( V_592 ) {
struct V_608 * V_609 = F_357 ( V_592 ) ;
F_366 ( V_609 , V_381 ) ;
V_609 -> V_574 = NULL ;
F_367 ( & V_609 -> V_629 , 0 ) ;
V_609 -> V_630 = V_631 ;
F_368 ( & V_609 -> V_632 , F_70 ( V_628 ) ) ;
V_609 -> V_633 = V_628 -> V_267 ;
}
return V_592 ;
}
static bool F_369 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const char * V_634 )
{
const char * V_264 = L_23 ;
bool V_635 = false ;
struct V_636 * V_637 ;
#ifdef F_370
if ( V_638 ) {
V_264 = L_24 ;
V_635 = true ;
F_69 ( F_70 ( V_2 ) , V_639 ) ;
} else
#endif
F_69 ( F_70 ( V_2 ) , V_640 ) ;
V_637 = F_2 ( V_2 ) -> V_587 . V_641 ;
if ( ! V_637 -> V_642 && V_638 != 2 ) {
V_637 -> V_642 = 1 ;
F_371 ( L_25 ,
V_634 , F_150 ( F_6 ( V_4 ) -> V_624 ) , V_264 ) ;
}
return V_635 ;
}
static void F_372 ( const struct V_1 * V_2 ,
struct V_591 * V_592 ,
const struct V_3 * V_4 )
{
if ( F_7 ( V_2 ) -> V_643 ) {
T_1 V_10 = F_373 ( V_4 ) + F_374 ( V_4 ) ;
T_1 * V_522 ;
V_522 = F_375 ( V_10 + sizeof( T_1 ) , V_171 ) ;
if ( V_522 ) {
V_522 [ 0 ] = V_10 ;
memcpy ( & V_522 [ 1 ] , F_376 ( V_4 ) , V_10 ) ;
V_592 -> V_644 = V_522 ;
}
}
}
int F_377 ( struct V_626 * V_645 ,
const struct V_646 * V_647 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_408 V_648 ;
struct V_591 * V_592 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_113 * V_114 = NULL ;
T_3 V_649 = F_16 ( V_4 ) -> V_650 ;
bool V_635 = false , V_651 ;
struct V_652 V_653 ;
struct V_402 V_403 = { . V_10 = - 1 } ;
int V_166 ;
if ( ( V_638 == 2 ||
F_378 ( V_2 ) ) && ! V_649 ) {
V_635 = F_369 ( V_2 , V_4 , V_645 -> V_654 ) ;
if ( ! V_635 )
goto V_504;
}
if ( F_379 ( V_2 ) && F_380 ( V_2 ) > 1 ) {
F_69 ( F_70 ( V_2 ) , V_655 ) ;
goto V_504;
}
V_592 = F_364 ( V_645 , V_2 ) ;
if ( ! V_592 )
goto V_504;
F_351 ( V_592 ) -> V_656 = V_647 ;
F_339 ( & V_648 ) ;
V_648 . V_50 = V_647 -> V_50 ;
V_648 . V_420 = V_30 -> V_49 . V_420 ;
F_226 ( V_4 , & V_648 , 0 , V_635 ? NULL : & V_403 ) ;
if ( V_635 && ! V_648 . V_263 )
F_339 ( & V_648 ) ;
V_648 . V_428 = V_648 . V_263 ;
F_362 ( V_592 , & V_648 , V_4 , V_2 ) ;
F_357 ( V_592 ) -> V_657 = V_2 -> V_658 ;
V_647 -> V_659 ( V_592 , V_2 , V_4 ) ;
if ( F_381 ( V_2 , V_4 , V_592 ) )
goto V_660;
if ( ! V_635 && ! V_649 ) {
if ( V_661 . V_662 ) {
bool V_663 ;
V_114 = V_647 -> V_664 ( V_2 , & V_653 , V_592 , & V_663 ) ;
if ( V_114 && V_663 &&
! F_382 ( V_592 , V_114 , true ,
V_648 . V_263 ) ) {
F_69 ( F_70 ( V_2 ) , V_665 ) ;
goto V_666;
}
}
else if ( ! V_638 &&
( V_667 - F_383 ( V_2 ) <
( V_667 >> 2 ) ) &&
! F_382 ( V_592 , V_114 , false ,
V_648 . V_263 ) ) {
F_356 ( V_592 , F_150 ( F_6 ( V_4 ) -> V_622 ) ,
V_645 -> V_607 ) ;
goto V_666;
}
V_649 = V_647 -> V_668 ( V_4 ) ;
}
if ( ! V_114 ) {
V_114 = V_647 -> V_664 ( V_2 , & V_653 , V_592 , NULL ) ;
if ( ! V_114 )
goto V_660;
}
F_359 ( V_592 , V_4 , V_2 , V_114 ) ;
if ( V_635 ) {
V_649 = F_384 ( V_647 , V_2 , V_4 , & V_592 -> V_66 ) ;
V_592 -> V_619 = V_648 . V_428 ;
if ( ! V_648 . V_428 )
F_357 ( V_592 ) -> V_615 = 0 ;
}
F_351 ( V_592 ) -> V_669 = V_649 ;
F_385 ( V_592 , V_2 , V_114 ) ;
V_651 = ! V_635 &&
F_386 ( V_2 , V_4 , V_592 , & V_403 , V_114 ) ;
V_166 = V_647 -> V_670 ( V_2 , V_114 , & V_653 , V_592 ,
F_387 ( V_4 ) , & V_403 ) ;
if ( ! V_651 ) {
if ( V_166 || V_635 )
goto V_660;
F_351 ( V_592 ) -> V_671 = false ;
V_647 -> V_672 ( V_2 , V_592 , V_673 ) ;
}
F_372 ( V_2 , V_592 , V_4 ) ;
return 0 ;
V_666:
F_388 ( V_114 ) ;
V_660:
F_389 ( V_592 ) ;
V_504:
F_69 ( F_70 ( V_2 ) , V_674 ) ;
return 0 ;
}
