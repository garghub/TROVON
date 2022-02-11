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
if ( ( V_30 -> V_136 == NULL ) ||
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
if ( V_173 -> V_183 < 0 ) {
struct V_175 V_96 ;
F_88 ( & V_96 ) ;
V_173 -> V_183 = F_89 ( & V_96 ,
V_176 ) ;
}
}
if ( V_139 & V_140 ) {
V_139 &= ~ V_140 ;
V_30 -> V_137 -= V_174 ;
}
}
V_139 |= V_141 ;
V_173 -> V_181 |= V_184 ;
V_30 -> V_133 += V_174 ;
V_177 += V_174 ;
if ( ! F_65 ( V_30 ) && ( V_30 -> V_118 != NULL ) &&
F_46 ( V_143 , F_16 ( V_30 -> V_118 ) -> V_77 ) )
V_30 -> V_185 += V_174 ;
if ( V_177 > V_30 -> V_132 )
V_30 -> V_132 = V_177 ;
}
if ( V_161 && ( V_139 & V_152 ) ) {
V_139 &= ~ V_152 ;
V_30 -> V_148 -= V_174 ;
}
return V_139 ;
}
static bool F_90 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_172 * V_173 ,
unsigned int V_174 , int V_186 , int V_66 ,
bool V_161 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_187 = F_91 ( V_2 , V_4 ) ;
T_1 V_143 = F_16 ( V_4 ) -> V_77 ;
T_1 V_92 = V_143 + V_186 ;
F_92 ( ! V_174 ) ;
F_87 ( V_2 , V_173 , F_16 ( V_4 ) -> V_139 ,
V_143 , V_92 , V_161 , V_174 ,
& V_4 -> V_175 ) ;
if ( V_4 == V_30 -> V_118 )
V_30 -> V_185 += V_174 ;
F_16 ( V_187 ) -> V_92 += V_186 ;
F_16 ( V_4 ) -> V_77 += V_186 ;
F_93 ( V_187 , V_174 ) ;
F_92 ( F_75 ( V_4 ) < V_174 ) ;
F_93 ( V_4 , - V_174 ) ;
if ( ! F_3 ( V_187 ) -> V_11 ) {
F_3 ( V_187 ) -> V_11 = V_66 ;
F_3 ( V_187 ) -> V_188 = V_2 -> V_189 ;
}
if ( F_75 ( V_4 ) <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_188 = 0 ;
}
F_16 ( V_187 ) -> V_139 |= ( F_16 ( V_4 ) -> V_139 & V_190 ) ;
if ( V_4 -> V_10 > 0 ) {
F_92 ( ! F_75 ( V_4 ) ) ;
F_69 ( F_70 ( V_2 ) , V_191 ) ;
return false ;
}
if ( V_4 == V_30 -> V_136 )
V_30 -> V_136 = V_187 ;
if ( V_4 == V_30 -> V_118 ) {
V_30 -> V_118 = V_187 ;
V_30 -> V_185 -= F_75 ( V_187 ) ;
}
F_16 ( V_187 ) -> V_192 |= F_16 ( V_4 ) -> V_192 ;
if ( F_16 ( V_4 ) -> V_192 & V_193 )
F_16 ( V_187 ) -> V_92 ++ ;
if ( V_4 == F_94 ( V_2 ) )
F_95 ( V_2 , V_4 ) ;
F_96 ( V_4 , V_2 ) ;
F_97 ( V_2 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_194 ) ;
return true ;
}
static int F_98 ( const struct V_3 * V_4 )
{
return F_75 ( V_4 ) == 1 ? V_4 -> V_10 : F_85 ( V_4 ) ;
}
static int F_99 ( const struct V_3 * V_4 )
{
return ! F_100 ( V_4 ) && F_101 ( V_4 ) ;
}
static struct V_3 * F_102 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_172 * V_173 ,
T_1 V_143 , T_1 V_92 ,
bool V_161 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_187 ;
int V_66 ;
int V_174 = 0 ;
int V_10 ;
int V_167 ;
if ( ! F_103 ( V_2 ) )
goto V_195;
if ( ! V_161 &&
( F_16 ( V_4 ) -> V_139 & ( V_140 | V_152 ) ) == V_152 )
goto V_195;
if ( ! F_99 ( V_4 ) )
goto V_195;
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_105 ) )
goto V_195;
if ( F_104 ( V_4 == F_105 ( V_2 ) ) )
goto V_195;
V_187 = F_91 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_187 ) -> V_139 & V_196 ) != V_141 )
goto V_195;
V_167 = ! F_53 ( V_143 , F_16 ( V_4 ) -> V_77 ) &&
! F_46 ( V_92 , F_16 ( V_4 ) -> V_92 ) ;
if ( V_167 ) {
V_10 = V_4 -> V_10 ;
V_174 = F_75 ( V_4 ) ;
V_66 = F_98 ( V_4 ) ;
if ( V_66 != F_98 ( V_187 ) )
goto V_195;
} else {
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_143 ) )
goto V_197;
if ( F_75 ( V_4 ) <= 1 )
goto V_197;
V_167 = ! F_53 ( V_143 , F_16 ( V_4 ) -> V_77 ) ;
if ( ! V_167 ) {
goto V_195;
}
V_10 = V_92 - F_16 ( V_4 ) -> V_77 ;
F_92 ( V_10 < 0 ) ;
F_92 ( V_10 > V_4 -> V_10 ) ;
V_66 = F_85 ( V_4 ) ;
if ( V_66 != F_98 ( V_187 ) )
goto V_195;
if ( V_10 == V_66 ) {
V_174 = 1 ;
} else if ( V_10 < V_66 ) {
goto V_197;
} else {
V_174 = V_10 / V_66 ;
V_10 = V_174 * V_66 ;
}
}
if ( ! F_53 ( F_16 ( V_4 ) -> V_77 + V_10 , V_30 -> V_105 ) )
goto V_195;
if ( ! F_106 ( V_187 , V_4 , V_10 ) )
goto V_195;
if ( ! F_90 ( V_2 , V_4 , V_173 , V_174 , V_10 , V_66 , V_161 ) )
goto V_198;
if ( V_187 == F_107 ( V_2 ) )
goto V_198;
V_4 = F_108 ( V_2 , V_187 ) ;
if ( ! F_99 ( V_4 ) ||
( V_4 == F_81 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_139 & V_196 ) != V_141 ) ||
( V_66 != F_98 ( V_4 ) ) )
goto V_198;
V_10 = V_4 -> V_10 ;
if ( F_106 ( V_187 , V_4 , V_10 ) ) {
V_174 += F_75 ( V_4 ) ;
F_90 ( V_2 , V_4 , V_173 , F_75 ( V_4 ) , V_10 , V_66 , 0 ) ;
}
V_198:
V_173 -> V_177 += V_174 ;
return V_187 ;
V_197:
return V_4 ;
V_195:
F_69 ( F_70 ( V_2 ) , V_199 ) ;
return NULL ;
}
static struct V_3 * F_109 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_172 * V_173 ,
T_1 V_143 , T_1 V_92 ,
bool V_202 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_203 ;
F_110 (skb, sk) {
int V_167 = 0 ;
bool V_161 = V_202 ;
if ( V_4 == F_81 ( V_2 ) )
break;
if ( ! F_46 ( F_16 ( V_4 ) -> V_77 , V_92 ) )
break;
if ( ( V_201 != NULL ) &&
F_46 ( F_16 ( V_4 ) -> V_77 , V_201 -> V_92 ) ) {
V_167 = F_84 ( V_2 , V_4 ,
V_201 -> V_143 ,
V_201 -> V_92 ) ;
if ( V_167 > 0 )
V_161 = true ;
}
if ( V_167 <= 0 ) {
V_203 = F_102 ( V_2 , V_4 , V_173 ,
V_143 , V_92 , V_161 ) ;
if ( V_203 != NULL ) {
if ( V_203 != V_4 ) {
V_4 = V_203 ;
continue;
}
V_167 = 0 ;
} else {
V_167 = F_84 ( V_2 , V_4 ,
V_143 ,
V_92 ) ;
}
}
if ( F_104 ( V_167 < 0 ) )
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
F_95 ( V_2 , V_4 ) ;
}
V_173 -> V_177 += F_75 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_111 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_172 * V_173 ,
T_1 V_204 )
{
F_110 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_204 ) )
break;
V_173 -> V_177 += F_75 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_112 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_200 * V_201 ,
struct V_172 * V_173 ,
T_1 V_204 )
{
if ( V_201 == NULL )
return V_4 ;
if ( F_46 ( V_201 -> V_143 , V_204 ) ) {
V_4 = F_111 ( V_4 , V_2 , V_173 , V_201 -> V_143 ) ;
V_4 = F_109 ( V_4 , V_2 , NULL , V_173 ,
V_201 -> V_143 , V_201 -> V_92 ,
1 ) ;
}
return V_4 ;
}
static int F_113 ( const struct V_29 * V_30 , const struct V_200 * V_205 )
{
return V_205 < V_30 -> V_206 + F_114 ( V_30 -> V_206 ) ;
}
static int
F_115 ( struct V_1 * V_2 , const struct V_3 * V_154 ,
T_1 V_158 , long * V_207 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_208 = ( F_4 ( V_154 ) +
F_16 ( V_154 ) -> V_139 ) ;
struct V_155 * V_209 = (struct V_155 * ) ( V_208 + 2 ) ;
struct V_200 V_156 [ V_210 ] ;
struct V_200 * V_205 ;
struct V_172 V_173 ;
struct V_3 * V_4 ;
int V_157 = F_9 ( V_210 , ( V_208 [ 1 ] - V_211 ) >> 3 ) ;
int V_212 ;
bool V_213 = false ;
int V_214 , V_215 ;
int V_216 ;
V_173 . V_181 = 0 ;
V_173 . V_179 = V_30 -> V_110 ;
V_173 . V_183 = - 1L ;
if ( ! V_30 -> V_133 ) {
if ( F_116 ( V_30 -> V_132 ) )
V_30 -> V_132 = 0 ;
F_117 ( V_2 ) ;
}
V_213 = F_82 ( V_2 , V_154 , V_209 ,
V_157 , V_158 ) ;
if ( V_213 )
V_173 . V_181 |= V_217 ;
if ( F_46 ( F_16 ( V_154 ) -> V_151 , V_158 - V_30 -> V_144 ) )
return 0 ;
if ( ! V_30 -> V_110 )
goto V_198;
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
F_118 ( V_156 [ V_215 ] , V_156 [ V_215 + 1 ] ) ;
if ( V_215 == V_216 )
V_216 = V_215 + 1 ;
}
}
}
V_4 = F_105 ( V_2 ) ;
V_173 . V_177 = 0 ;
V_214 = 0 ;
if ( ! V_30 -> V_133 ) {
V_205 = V_30 -> V_206 + F_114 ( V_30 -> V_206 ) ;
} else {
V_205 = V_30 -> V_206 ;
while ( F_113 ( V_30 , V_205 ) && ! V_205 -> V_143 &&
! V_205 -> V_92 )
V_205 ++ ;
}
while ( V_214 < V_212 ) {
T_1 V_143 = V_156 [ V_214 ] . V_143 ;
T_1 V_92 = V_156 [ V_214 ] . V_92 ;
bool V_161 = ( V_213 && ( V_214 == V_216 ) ) ;
struct V_200 * V_201 = NULL ;
if ( V_213 && ( ( V_214 + 1 ) == V_216 ) )
V_201 = & V_156 [ V_214 + 1 ] ;
while ( F_113 ( V_30 , V_205 ) &&
! F_46 ( V_143 , V_205 -> V_92 ) )
V_205 ++ ;
if ( F_113 ( V_30 , V_205 ) && ! V_161 &&
F_53 ( V_92 , V_205 -> V_143 ) ) {
if ( F_46 ( V_143 , V_205 -> V_143 ) ) {
V_4 = F_111 ( V_4 , V_2 , & V_173 ,
V_143 ) ;
V_4 = F_109 ( V_4 , V_2 , V_201 ,
& V_173 ,
V_143 ,
V_205 -> V_143 ,
V_161 ) ;
}
if ( ! F_53 ( V_92 , V_205 -> V_92 ) )
goto V_221;
V_4 = F_112 ( V_4 , V_2 , V_201 ,
& V_173 ,
V_205 -> V_92 ) ;
if ( F_79 ( V_30 ) == V_205 -> V_92 ) {
V_4 = F_94 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_173 . V_177 = V_30 -> V_132 ;
V_205 ++ ;
goto V_222;
}
V_4 = F_111 ( V_4 , V_2 , & V_173 , V_205 -> V_92 ) ;
V_205 ++ ;
continue;
}
if ( ! F_46 ( V_143 , F_79 ( V_30 ) ) ) {
V_4 = F_94 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_173 . V_177 = V_30 -> V_132 ;
}
V_4 = F_111 ( V_4 , V_2 , & V_173 , V_143 ) ;
V_222:
V_4 = F_109 ( V_4 , V_2 , V_201 , & V_173 ,
V_143 , V_92 , V_161 ) ;
V_221:
V_214 ++ ;
}
for ( V_214 = 0 ; V_214 < F_114 ( V_30 -> V_206 ) - V_212 ; V_214 ++ ) {
V_30 -> V_206 [ V_214 ] . V_143 = 0 ;
V_30 -> V_206 [ V_214 ] . V_92 = 0 ;
}
for ( V_215 = 0 ; V_215 < V_212 ; V_215 ++ )
V_30 -> V_206 [ V_214 ++ ] = V_156 [ V_215 ] ;
F_78 ( V_2 ) ;
F_119 ( V_30 ) ;
if ( ( V_173 . V_179 < V_30 -> V_132 ) &&
( ( F_2 ( V_2 ) -> V_131 != V_223 ) || V_30 -> V_134 ) )
F_67 ( V_2 , V_30 -> V_132 - V_173 . V_179 , 0 ) ;
V_198:
#if V_130 > 0
F_116 ( ( int ) V_30 -> V_133 < 0 ) ;
F_116 ( ( int ) V_30 -> V_137 < 0 ) ;
F_116 ( ( int ) V_30 -> V_148 < 0 ) ;
F_116 ( ( int ) F_120 ( V_30 ) < 0 ) ;
#endif
* V_207 = V_173 . V_183 ;
return V_173 . V_181 ;
}
static bool F_121 ( struct V_29 * V_30 )
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
static void F_122 ( struct V_1 * V_2 , const int V_225 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_121 ( V_30 ) )
F_67 ( V_2 , V_30 -> V_110 + V_225 , 0 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_133 ++ ;
F_122 ( V_2 , 0 ) ;
F_119 ( V_30 ) ;
}
static void F_124 ( struct V_1 * V_2 , int V_226 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_226 > 0 ) {
if ( V_226 - 1 >= V_30 -> V_133 )
V_30 -> V_133 = 0 ;
else
V_30 -> V_133 -= V_226 - 1 ;
}
F_122 ( V_2 , V_226 ) ;
F_119 ( V_30 ) ;
}
static inline void F_125 ( struct V_29 * V_30 )
{
V_30 -> V_133 = 0 ;
}
void F_126 ( struct V_29 * V_30 )
{
V_30 -> V_148 = 0 ;
V_30 -> V_137 = 0 ;
V_30 -> V_134 = 0 ;
V_30 -> V_135 = - 1 ;
V_30 -> V_132 = 0 ;
V_30 -> V_133 = 0 ;
}
static inline void F_127 ( struct V_29 * V_30 )
{
V_30 -> V_134 = V_30 -> V_105 ;
V_30 -> V_135 = V_30 -> V_148 ? : - 1 ;
}
void F_128 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
bool V_227 = false ;
bool V_228 ;
if ( V_6 -> V_131 <= V_229 ||
! F_53 ( V_30 -> V_180 , V_30 -> V_105 ) ||
( V_6 -> V_131 == V_223 && ! V_6 -> V_230 ) ) {
V_227 = true ;
V_30 -> V_231 = F_129 ( V_2 ) ;
V_30 -> V_232 = V_6 -> V_233 -> V_234 ( V_2 ) ;
F_18 ( V_2 , V_235 ) ;
F_127 ( V_30 ) ;
}
V_30 -> V_55 = 1 ;
V_30 -> V_236 = 0 ;
V_30 -> V_80 = V_76 ;
V_30 -> V_148 = 0 ;
V_30 -> V_137 = 0 ;
if ( F_68 ( V_30 ) )
F_125 ( V_30 ) ;
V_4 = F_105 ( V_2 ) ;
V_228 = V_4 && ( F_16 ( V_4 ) -> V_139 & V_141 ) ;
if ( V_228 ) {
F_69 ( F_70 ( V_2 ) , V_237 ) ;
V_30 -> V_133 = 0 ;
V_30 -> V_132 = 0 ;
}
F_130 ( V_30 ) ;
F_80 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_139 &= ( ~ V_196 ) | V_141 ;
if ( ! ( F_16 ( V_4 ) -> V_139 & V_141 ) || V_228 ) {
F_16 ( V_4 ) -> V_139 &= ~ V_141 ;
F_16 ( V_4 ) -> V_139 |= V_140 ;
V_30 -> V_137 += F_75 ( V_4 ) ;
V_30 -> V_138 = F_16 ( V_4 ) -> V_92 ;
}
}
F_119 ( V_30 ) ;
if ( V_6 -> V_131 <= V_229 &&
V_30 -> V_133 >= V_238 )
V_30 -> V_56 = F_43 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_131 ( V_2 , V_223 ) ;
V_30 -> V_180 = V_30 -> V_107 ;
F_12 ( V_30 ) ;
V_30 -> V_239 = V_240 &&
( V_227 || V_6 -> V_230 ) &&
! F_2 ( V_2 ) -> V_241 . V_242 ;
}
static bool F_132 ( struct V_1 * V_2 , int V_181 )
{
if ( V_181 & V_243 ) {
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_244 = F_37 ( F_133 ( V_30 -> V_101 >> 4 ) ,
F_134 ( 10 ) ) ;
F_135 ( V_2 , V_245 ,
V_244 , V_246 ) ;
return true ;
}
return false ;
}
static inline int F_136 ( const struct V_29 * V_30 )
{
return F_68 ( V_30 ) ? V_30 -> V_133 + 1 : V_30 -> V_132 ;
}
static inline int F_137 ( const struct V_29 * V_30 )
{
return F_65 ( V_30 ) ? V_30 -> V_132 : V_30 -> V_133 + 1 ;
}
static bool F_138 ( struct V_1 * V_2 , int V_181 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_244 ;
if ( V_247 < 2 || V_247 > 3 ||
( V_181 & V_248 ) || ! V_30 -> V_101 )
return false ;
V_244 = F_37 ( F_133 ( V_30 -> V_101 >> 5 ) ,
F_134 ( 2 ) ) ;
if ( ! F_139 ( F_2 ( V_2 ) -> V_249 , ( V_250 + V_244 ) ) )
return false ;
F_135 ( V_2 , V_251 , V_244 ,
V_246 ) ;
return true ;
}
static bool F_140 ( struct V_1 * V_2 , int V_181 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_110 ;
if ( V_30 -> V_137 )
return true ;
if ( F_137 ( V_30 ) > V_30 -> V_56 )
return true ;
V_110 = V_30 -> V_110 ;
if ( V_110 <= V_30 -> V_56 &&
V_30 -> V_133 >= F_24 ( T_3 , V_110 / 2 , V_238 ) &&
! F_141 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_252 || V_253 ) &&
F_142 ( V_30 ) && F_137 ( V_30 ) > 1 &&
F_143 ( V_30 ) && ! F_81 ( V_2 ) )
return true ;
if ( V_30 -> V_254 && ! V_30 -> V_148 && V_30 -> V_133 &&
( V_30 -> V_110 >= ( V_30 -> V_133 + 1 ) && V_30 -> V_110 < 4 ) &&
! F_141 ( V_2 ) )
return ! F_138 ( V_2 , V_181 ) ;
return false ;
}
static void F_144 ( struct V_1 * V_2 , int V_255 , int V_256 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_145 , V_257 ;
int V_166 ;
unsigned int V_66 ;
const T_1 V_258 = F_143 ( V_30 ) ? V_30 -> V_107 : V_30 -> V_180 ;
F_116 ( V_255 > V_30 -> V_110 ) ;
if ( V_30 -> V_118 ) {
V_4 = V_30 -> V_118 ;
V_145 = V_30 -> V_185 ;
if ( V_256 && V_4 != F_105 ( V_2 ) )
return;
} else {
V_4 = F_105 ( V_2 ) ;
V_145 = 0 ;
}
F_110 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
V_30 -> V_118 = V_4 ;
V_30 -> V_185 = V_145 ;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_258 ) )
break;
V_257 = V_145 ;
if ( F_65 ( V_30 ) || F_68 ( V_30 ) ||
( F_16 ( V_4 ) -> V_139 & V_141 ) )
V_145 += F_75 ( V_4 ) ;
if ( V_145 > V_255 ) {
if ( ( F_143 ( V_30 ) && ! F_65 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_139 & V_141 ) ||
( V_257 >= V_255 ) )
break;
V_66 = F_3 ( V_4 ) -> V_11 ;
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
F_119 ( V_30 ) ;
}
static void F_145 ( struct V_1 * V_2 , int V_259 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_68 ( V_30 ) ) {
F_144 ( V_2 , 1 , 1 ) ;
} else if ( F_65 ( V_30 ) ) {
int V_260 = V_30 -> V_132 - V_30 -> V_56 ;
if ( V_260 <= 0 )
V_260 = 1 ;
F_144 ( V_2 , V_260 , 0 ) ;
} else {
int V_261 = V_30 -> V_133 - V_30 -> V_56 ;
if ( V_261 >= 0 )
F_144 ( V_2 , V_261 , 0 ) ;
else if ( V_259 )
F_144 ( V_2 , 1 , 1 ) ;
}
}
static inline void F_146 ( struct V_29 * V_30 )
{
V_30 -> V_55 = F_9 ( V_30 -> V_55 ,
F_120 ( V_30 ) + F_147 ( V_30 ) ) ;
V_30 -> V_80 = V_76 ;
}
static inline bool F_148 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_262 ||
( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 &&
F_46 ( V_30 -> V_49 . V_91 , V_30 -> V_262 ) ) ;
}
static bool F_149 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_148 )
return true ;
V_4 = F_105 ( V_2 ) ;
if ( F_104 ( V_4 && F_16 ( V_4 ) -> V_139 & V_190 ) )
return true ;
return false ;
}
static void F_150 ( struct V_1 * V_2 , const char * V_264 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_265 * V_266 = F_151 ( V_2 ) ;
if ( V_2 -> V_267 == V_268 ) {
F_71 ( L_2 ,
V_264 ,
& V_266 -> V_269 , F_152 ( V_266 -> V_270 ) ,
V_30 -> V_55 , F_153 ( V_30 ) ,
V_30 -> V_232 , V_30 -> V_231 ,
V_30 -> V_110 ) ;
}
#if F_154 ( V_271 )
else if ( V_2 -> V_267 == V_272 ) {
struct V_273 * V_274 = F_155 ( V_2 ) ;
F_71 ( L_3 ,
V_264 ,
& V_274 -> V_275 , F_152 ( V_266 -> V_270 ) ,
V_30 -> V_55 , F_153 ( V_30 ) ,
V_30 -> V_232 , V_30 -> V_231 ,
V_30 -> V_110 ) ;
}
#endif
}
static void F_156 ( struct V_1 * V_2 , bool V_276 )
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
F_130 ( V_30 ) ;
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
static inline bool F_157 ( const struct V_29 * V_30 )
{
return V_30 -> V_134 && ( ! V_30 -> V_135 || F_148 ( V_30 ) ) ;
}
static bool F_158 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_157 ( V_30 ) ) {
int V_124 ;
F_150 ( V_2 , F_2 ( V_2 ) -> V_131 == V_223 ? L_4 : L_5 ) ;
F_156 ( V_2 , false ) ;
if ( F_2 ( V_2 ) -> V_131 == V_223 )
V_124 = V_278 ;
else
V_124 = V_279 ;
F_69 ( F_70 ( V_2 ) , V_124 ) ;
}
if ( V_30 -> V_105 == V_30 -> V_180 && F_68 ( V_30 ) ) {
F_146 ( V_30 ) ;
if ( ! F_149 ( V_2 ) )
V_30 -> V_262 = 0 ;
return true ;
}
F_131 ( V_2 , V_280 ) ;
return false ;
}
static bool F_159 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_134 && ! V_30 -> V_135 ) {
F_150 ( V_2 , L_6 ) ;
F_156 ( V_2 , false ) ;
F_69 ( F_70 ( V_2 ) , V_281 ) ;
return true ;
}
return false ;
}
static bool F_160 ( struct V_1 * V_2 , bool V_282 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_282 || F_157 ( V_30 ) ) {
F_156 ( V_2 , true ) ;
F_150 ( V_2 , L_7 ) ;
F_69 ( F_70 ( V_2 ) , V_278 ) ;
if ( V_282 )
F_69 ( F_70 ( V_2 ) ,
V_283 ) ;
F_2 ( V_2 ) -> V_230 = 0 ;
if ( V_282 || F_143 ( V_30 ) )
F_131 ( V_2 , V_280 ) ;
return true ;
}
return false ;
}
static void F_161 ( struct V_1 * V_2 )
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
static void F_162 ( struct V_1 * V_2 , const int V_288 ,
int V_259 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_289 = 0 ;
int V_290 = V_30 -> V_232 - F_120 ( V_30 ) ;
int V_291 = V_288 -
( V_30 -> V_110 - V_30 -> V_133 ) ;
V_30 -> V_286 += V_291 ;
if ( F_120 ( V_30 ) > V_30 -> V_232 ) {
T_2 V_292 = ( T_2 ) V_30 -> V_232 * V_30 -> V_286 +
V_30 -> V_285 - 1 ;
V_289 = F_163 ( V_292 , V_30 -> V_285 ) - V_30 -> V_287 ;
} else {
V_289 = F_43 ( int , V_290 ,
F_24 ( int , V_30 -> V_286 - V_30 -> V_287 ,
V_291 ) + 1 ) ;
}
V_289 = F_37 ( V_289 , ( V_259 ? 1 : 0 ) ) ;
V_30 -> V_55 = F_120 ( V_30 ) + V_289 ;
}
static inline void F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_131 == V_293 ||
( V_30 -> V_134 && V_30 -> V_232 < V_294 ) ) {
V_30 -> V_55 = V_30 -> V_232 ;
V_30 -> V_80 = V_76 ;
}
F_18 ( V_2 , V_295 ) ;
}
void F_165 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_231 = 0 ;
if ( F_2 ( V_2 ) -> V_131 < V_293 ) {
V_30 -> V_134 = 0 ;
F_161 ( V_2 ) ;
F_131 ( V_2 , V_293 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_173 = V_280 ;
if ( F_153 ( V_30 ) || F_149 ( V_2 ) )
V_173 = V_229 ;
if ( F_2 ( V_2 ) -> V_131 != V_173 ) {
F_131 ( V_2 , V_173 ) ;
V_30 -> V_180 = V_30 -> V_107 ;
}
}
static void F_167 ( struct V_1 * V_2 , int V_181 , const int V_288 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_119 ( V_30 ) ;
if ( ! F_149 ( V_2 ) )
V_30 -> V_262 = 0 ;
if ( V_181 & V_248 )
F_165 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_131 != V_293 ) {
F_166 ( V_2 ) ;
} else {
F_162 ( V_2 , V_288 , 0 ) ;
}
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_241 . V_296 = V_6 -> V_241 . V_242 - 1 ;
V_6 -> V_241 . V_242 = 0 ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_231 = F_129 ( V_2 ) ;
V_30 -> V_55 = V_30 -> V_55 *
F_170 ( V_2 , V_30 -> V_51 ) /
V_6 -> V_241 . V_242 ;
V_30 -> V_236 = 0 ;
V_30 -> V_80 = V_76 ;
V_30 -> V_232 = F_129 ( V_2 ) ;
V_6 -> V_241 . V_297 = V_6 -> V_241 . V_242 ;
V_6 -> V_241 . V_242 = 0 ;
F_171 ( V_2 , V_6 -> V_298 ) ;
}
void F_172 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_66 = F_173 ( V_2 ) ;
T_1 V_299 = V_30 -> V_137 ;
F_80 (skb, sk) {
if ( V_4 == F_81 ( V_2 ) )
break;
if ( F_98 ( V_4 ) > V_66 &&
! ( F_16 ( V_4 ) -> V_139 & V_141 ) ) {
if ( F_16 ( V_4 ) -> V_139 & V_152 ) {
F_16 ( V_4 ) -> V_139 &= ~ V_152 ;
V_30 -> V_148 -= F_75 ( V_4 ) ;
}
F_76 ( V_30 , V_4 ) ;
}
}
F_174 ( V_30 ) ;
if ( V_299 == V_30 -> V_137 )
return;
if ( F_68 ( V_30 ) )
F_121 ( V_30 ) ;
F_119 ( V_30 ) ;
if ( V_6 -> V_131 != V_223 ) {
V_30 -> V_180 = V_30 -> V_107 ;
V_30 -> V_232 = F_129 ( V_2 ) ;
V_30 -> V_231 = 0 ;
V_30 -> V_134 = 0 ;
F_131 ( V_2 , V_223 ) ;
}
F_175 ( V_2 ) ;
}
static void F_176 ( struct V_1 * V_2 , bool V_300 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_124 ;
if ( F_68 ( V_30 ) )
V_124 = V_301 ;
else
V_124 = V_302 ;
F_69 ( F_70 ( V_2 ) , V_124 ) ;
V_30 -> V_231 = 0 ;
F_127 ( V_30 ) ;
if ( F_2 ( V_2 ) -> V_131 < V_293 ) {
if ( ! V_300 )
V_30 -> V_231 = F_129 ( V_2 ) ;
F_161 ( V_2 ) ;
}
F_131 ( V_2 , V_150 ) ;
}
static void F_177 ( struct V_1 * V_2 , int V_181 , bool V_303 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_304 = ! F_46 ( V_30 -> V_105 , V_30 -> V_180 ) ;
if ( V_30 -> V_239 ) {
if ( F_160 ( V_2 , V_181 & V_182 ) )
return;
if ( F_53 ( V_30 -> V_107 , V_30 -> V_180 ) &&
( V_181 & V_184 || V_303 ) ) {
V_30 -> V_239 = 0 ;
} else if ( V_181 & V_305 && ! V_304 ) {
V_30 -> V_180 = V_30 -> V_107 ;
F_178 ( V_2 , F_173 ( V_2 ) ,
V_306 ) ;
if ( F_53 ( V_30 -> V_107 , V_30 -> V_180 ) )
return;
V_30 -> V_239 = 0 ;
}
}
if ( V_304 ) {
F_158 ( V_2 ) ;
return;
}
if ( F_68 ( V_30 ) ) {
if ( F_53 ( V_30 -> V_107 , V_30 -> V_180 ) && V_303 )
F_123 ( V_2 ) ;
else if ( V_181 & V_305 )
F_125 ( V_30 ) ;
}
if ( F_160 ( V_2 , false ) )
return;
F_175 ( V_2 ) ;
}
static bool F_179 ( struct V_1 * V_2 , const int V_226 ,
const int V_288 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_134 && F_148 ( V_30 ) ) {
F_67 ( V_2 , F_136 ( V_30 ) + V_226 , 1 ) ;
if ( V_30 -> V_148 ) {
F_162 ( V_2 , V_288 , 0 ) ;
return true ;
}
if ( ! F_149 ( V_2 ) )
V_30 -> V_262 = 0 ;
F_150 ( V_2 , L_8 ) ;
F_156 ( V_2 , true ) ;
F_69 ( F_70 ( V_2 ) , V_307 ) ;
F_166 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_180 ( struct V_1 * V_2 , const int V_226 ,
const int V_288 ,
bool V_303 , int V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_308 = V_303 || ( ( V_181 & V_184 ) &&
( F_136 ( V_30 ) > V_30 -> V_56 ) ) ;
int V_259 = 0 ;
if ( F_116 ( ! V_30 -> V_110 && V_30 -> V_133 ) )
V_30 -> V_133 = 0 ;
if ( F_116 ( ! V_30 -> V_133 && V_30 -> V_132 ) )
V_30 -> V_132 = 0 ;
if ( V_181 & V_248 )
V_30 -> V_231 = 0 ;
if ( F_132 ( V_2 , V_181 ) )
return;
F_119 ( V_30 ) ;
if ( V_6 -> V_131 == V_280 ) {
F_116 ( V_30 -> V_148 != 0 ) ;
V_30 -> V_262 = 0 ;
} else if ( ! F_46 ( V_30 -> V_105 , V_30 -> V_180 ) ) {
switch ( V_6 -> V_131 ) {
case V_293 :
if ( V_30 -> V_105 != V_30 -> V_180 ) {
F_164 ( V_2 ) ;
F_131 ( V_2 , V_280 ) ;
}
break;
case V_150 :
if ( F_68 ( V_30 ) )
F_125 ( V_30 ) ;
if ( F_158 ( V_2 ) )
return;
F_164 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_131 ) {
case V_150 :
if ( ! ( V_181 & V_305 ) ) {
if ( F_68 ( V_30 ) && V_303 )
F_123 ( V_2 ) ;
} else {
if ( F_179 ( V_2 , V_226 , V_288 ) )
return;
V_308 = F_68 ( V_30 ) ||
F_136 ( V_30 ) > V_30 -> V_56 ;
}
if ( F_159 ( V_2 ) ) {
F_166 ( V_2 ) ;
return;
}
break;
case V_223 :
F_177 ( V_2 , V_181 , V_303 ) ;
if ( V_6 -> V_131 != V_280 )
return;
default:
if ( F_68 ( V_30 ) ) {
if ( V_181 & V_305 )
F_125 ( V_30 ) ;
if ( V_303 )
F_123 ( V_2 ) ;
}
if ( V_6 -> V_131 <= V_229 )
F_159 ( V_2 ) ;
if ( ! F_140 ( V_2 , V_181 ) ) {
F_167 ( V_2 , V_181 , V_288 ) ;
return;
}
if ( V_6 -> V_131 < V_293 &&
V_6 -> V_241 . V_242 &&
V_30 -> V_105 == V_30 -> V_309 . V_310 ) {
F_168 ( V_2 ) ;
V_30 -> V_55 ++ ;
F_172 ( V_2 ) ;
return;
}
F_176 ( V_2 , ( V_181 & V_248 ) ) ;
V_259 = 1 ;
}
if ( V_308 )
F_145 ( V_2 , V_259 ) ;
F_162 ( V_2 , V_288 , V_259 ) ;
F_175 ( V_2 ) ;
}
static inline bool F_181 ( struct V_1 * V_2 , const int V_181 ,
long V_311 , long V_207 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_181 & V_312 )
V_311 = - 1L ;
if ( V_311 < 0 )
V_311 = V_207 ;
if ( V_311 < 0 && V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 &&
V_181 & V_313 )
V_311 = F_182 ( V_76 - V_30 -> V_49 . V_91 ) ;
if ( V_311 < 0 )
return false ;
F_52 ( V_2 , V_311 ) ;
F_59 ( V_2 ) ;
F_2 ( V_2 ) -> V_314 = 0 ;
return true ;
}
static void F_183 ( struct V_1 * V_2 , const T_1 V_315 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_311 = - 1L ;
if ( V_315 && ! V_30 -> V_316 )
V_311 = F_182 ( V_76 - V_315 ) ;
if ( ! V_30 -> V_101 )
F_181 ( V_2 , V_317 , V_311 , - 1L ) ;
}
static void F_184 ( struct V_1 * V_2 , T_1 V_318 , T_1 V_226 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_233 -> V_319 ( V_2 , V_318 , V_226 ) ;
F_7 ( V_2 ) -> V_80 = V_76 ;
}
void F_185 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_320 )
return;
if ( ! V_30 -> V_110 ) {
F_186 ( V_2 , V_245 ) ;
} else {
T_1 V_321 = F_2 ( V_2 ) -> V_98 ;
if ( V_6 -> V_322 == V_251 ||
V_6 -> V_322 == V_323 ) {
struct V_3 * V_4 = F_105 ( V_2 ) ;
const T_1 V_324 =
F_187 ( V_4 ) + V_321 ;
T_5 V_290 = ( T_5 ) ( V_324 - V_76 ) ;
if ( V_290 > 0 )
V_321 = V_290 ;
}
F_135 ( V_2 , V_245 , V_321 ,
V_246 ) ;
}
}
void F_188 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_185 ( V_2 ) ;
if ( ! V_30 -> V_254 )
return;
F_176 ( V_2 , false ) ;
F_145 ( V_2 , 1 ) ;
F_175 ( V_2 ) ;
}
static T_1 F_189 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_325 ;
F_92 ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_105 ) ) ;
V_325 = F_75 ( V_4 ) ;
if ( F_190 ( V_2 , V_4 , V_30 -> V_105 - F_16 ( V_4 ) -> V_77 ) )
return 0 ;
V_325 -= F_75 ( V_4 ) ;
if ( V_325 ) {
F_92 ( F_75 ( V_4 ) == 0 ) ;
F_92 ( ! F_46 ( F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ) ;
}
return V_325 ;
}
static void F_191 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_158 )
{
const struct V_53 * V_326 ;
if ( F_56 ( ! ( V_2 -> V_327 & V_328 ) ) )
return;
V_326 = F_3 ( V_4 ) ;
if ( ( V_326 -> V_329 & V_330 ) &&
F_192 ( V_326 -> V_331 , V_158 , F_7 ( V_2 ) -> V_105 - 1 ) )
F_193 ( V_4 , NULL , V_2 , V_332 ) ;
}
static int F_194 ( struct V_1 * V_2 , int V_333 ,
T_1 V_158 , long V_207 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_175 V_334 , V_335 , V_96 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_336 = V_30 -> V_133 ;
T_1 V_179 = V_30 -> V_110 ;
bool V_337 = true ;
long V_338 = - 1L ;
long V_311 = - 1L ;
struct V_3 * V_4 ;
T_1 V_339 = 0 ;
bool V_340 ;
int V_181 = 0 ;
V_334 . V_341 = 0 ;
while ( ( V_4 = F_105 ( V_2 ) ) && V_4 != F_81 ( V_2 ) ) {
struct V_342 * V_343 = F_16 ( V_4 ) ;
T_4 V_139 = V_343 -> V_139 ;
T_1 V_344 ;
F_191 ( V_2 , V_4 , V_158 ) ;
if ( F_53 ( V_343 -> V_92 , V_30 -> V_105 ) ) {
if ( F_75 ( V_4 ) == 1 ||
! F_53 ( V_30 -> V_105 , V_343 -> V_77 ) )
break;
V_344 = F_189 ( V_2 , V_4 ) ;
if ( ! V_344 )
break;
V_337 = false ;
} else {
F_195 ( V_4 -> V_345 ) ;
V_344 = F_75 ( V_4 ) ;
}
if ( F_104 ( V_139 & V_178 ) ) {
if ( V_139 & V_152 )
V_30 -> V_148 -= V_344 ;
V_181 |= V_312 ;
} else {
V_335 = V_4 -> V_175 ;
F_196 ( V_335 . V_341 == 0 ) ;
if ( ! V_334 . V_341 )
V_334 = V_335 ;
if ( ! ( V_139 & V_141 ) )
V_179 = F_9 ( V_339 , V_179 ) ;
if ( ! F_53 ( V_343 -> V_92 , V_30 -> V_180 ) )
V_181 |= V_182 ;
}
if ( V_139 & V_141 )
V_30 -> V_133 -= V_344 ;
if ( V_139 & V_140 )
V_30 -> V_137 -= V_344 ;
V_30 -> V_110 -= V_344 ;
V_339 += V_344 ;
if ( F_56 ( ! ( V_343 -> V_192 & V_346 ) ) ) {
V_181 |= V_347 ;
} else {
V_181 |= V_317 ;
V_30 -> V_262 = 0 ;
}
if ( ! V_337 )
break;
F_96 ( V_4 , V_2 ) ;
F_97 ( V_2 , V_4 ) ;
if ( F_104 ( V_4 == V_30 -> V_136 ) )
V_30 -> V_136 = NULL ;
if ( F_104 ( V_4 == V_30 -> V_118 ) )
V_30 -> V_118 = NULL ;
}
if ( F_56 ( F_192 ( V_30 -> V_348 , V_158 , V_30 -> V_105 ) ) )
V_30 -> V_348 = V_30 -> V_105 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_139 & V_141 ) )
V_181 |= V_243 ;
F_88 ( & V_96 ) ;
if ( F_56 ( V_334 . V_341 ) ) {
V_311 = F_89 ( & V_96 , & V_334 ) ;
V_338 = F_89 ( & V_96 , & V_335 ) ;
}
V_340 = F_181 ( V_2 , V_181 , V_311 , V_207 ) ;
if ( V_181 & V_313 ) {
const struct V_349 * V_350
= F_2 ( V_2 ) -> V_233 ;
F_185 ( V_2 ) ;
if ( F_104 ( V_6 -> V_241 . V_242 &&
! F_53 ( V_30 -> V_309 . V_351 , V_30 -> V_105 ) ) ) {
F_169 ( V_2 ) ;
}
if ( F_68 ( V_30 ) ) {
F_124 ( V_2 , V_339 ) ;
} else {
int V_290 ;
if ( V_179 < V_333 )
F_67 ( V_2 , V_30 -> V_132 - V_179 , 0 ) ;
V_290 = F_65 ( V_30 ) ? V_339 :
V_336 - V_30 -> V_133 ;
V_30 -> V_185 -= F_9 ( V_30 -> V_185 , V_290 ) ;
}
V_30 -> V_132 -= F_9 ( V_339 , V_30 -> V_132 ) ;
if ( V_350 -> V_339 )
V_350 -> V_339 ( V_2 , V_339 , V_338 ) ;
} else if ( V_4 && V_340 && V_207 >= 0 &&
V_207 > F_89 ( & V_96 , & V_4 -> V_175 ) ) {
F_185 ( V_2 ) ;
}
#if V_130 > 0
F_116 ( ( int ) V_30 -> V_133 < 0 ) ;
F_116 ( ( int ) V_30 -> V_137 < 0 ) ;
F_116 ( ( int ) V_30 -> V_148 < 0 ) ;
if ( ! V_30 -> V_110 && F_143 ( V_30 ) ) {
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
V_6 -> V_314 = 0 ;
F_186 ( V_2 , V_352 ) ;
} else {
unsigned long V_353 = F_199 ( V_6 , V_246 ) ;
F_135 ( V_2 , V_352 ,
V_353 , V_246 ) ;
}
}
static inline bool F_200 ( const struct V_1 * V_2 , const int V_181 )
{
return ! ( V_181 & V_354 ) || ( V_181 & V_355 ) ||
F_2 ( V_2 ) -> V_131 != V_280 ;
}
static inline bool F_201 ( const struct V_1 * V_2 , const int V_181 )
{
if ( F_202 ( V_2 ) )
return false ;
if ( F_7 ( V_2 ) -> V_56 > V_238 )
return V_181 & V_356 ;
return V_181 & V_347 ;
}
static inline bool F_203 ( const struct V_29 * V_30 ,
const T_1 V_318 , const T_1 V_151 ,
const T_1 V_357 )
{
return F_53 ( V_318 , V_30 -> V_105 ) ||
F_53 ( V_151 , V_30 -> V_358 ) ||
( V_151 == V_30 -> V_358 && V_357 > V_30 -> V_359 ) ;
}
static int F_204 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_318 ,
T_1 V_151 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_181 = 0 ;
T_1 V_357 = F_152 ( F_6 ( V_4 ) -> V_60 ) ;
if ( F_56 ( ! F_6 ( V_4 ) -> V_45 ) )
V_357 <<= V_30 -> V_49 . V_360 ;
if ( F_203 ( V_30 , V_318 , V_151 , V_357 ) ) {
V_181 |= V_361 ;
F_205 ( V_30 , V_151 ) ;
if ( V_30 -> V_359 != V_357 ) {
V_30 -> V_359 = V_357 ;
V_30 -> V_362 = 0 ;
F_206 ( V_2 ) ;
if ( V_357 > V_30 -> V_144 ) {
V_30 -> V_144 = V_357 ;
F_171 ( V_2 , F_2 ( V_2 ) -> V_298 ) ;
}
}
}
V_30 -> V_105 = V_318 ;
return V_181 ;
}
static void F_207 ( struct V_1 * V_2 )
{
static T_1 V_363 ;
static unsigned int V_364 ;
T_1 V_96 = V_250 / V_365 ;
if ( V_96 != V_363 ) {
V_363 = V_96 ;
V_364 = 0 ;
}
if ( ++ V_364 <= V_366 ) {
F_69 ( F_70 ( V_2 ) , V_367 ) ;
F_208 ( V_2 ) ;
}
}
static void F_209 ( struct V_29 * V_30 )
{
V_30 -> V_49 . V_368 = V_30 -> V_49 . V_369 ;
V_30 -> V_49 . V_370 = F_210 () ;
}
static void F_211 ( struct V_29 * V_30 , T_1 V_77 )
{
if ( V_30 -> V_49 . V_263 && ! F_53 ( V_77 , V_30 -> V_371 ) ) {
if ( F_212 ( & V_30 -> V_49 , 0 ) )
F_209 ( V_30 ) ;
}
}
static void F_213 ( struct V_1 * V_2 , T_1 V_318 , int V_181 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_372 = ( V_318 == V_30 -> V_284 ) &&
! ( V_181 & ( V_305 |
V_354 | V_184 ) ) ;
if ( V_372 ) {
V_30 -> V_284 = 0 ;
return;
}
if ( F_53 ( V_318 , V_30 -> V_284 ) ) {
V_30 -> V_284 = 0 ;
if ( ! ( V_181 & V_217 ) ) {
F_161 ( V_2 ) ;
F_131 ( V_2 , V_293 ) ;
F_164 ( V_2 ) ;
F_166 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) ,
V_373 ) ;
}
}
}
static inline void F_214 ( struct V_1 * V_2 , T_1 V_374 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_233 -> V_375 )
V_6 -> V_233 -> V_375 ( V_2 , V_374 ) ;
}
static int F_215 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_158 = V_30 -> V_105 ;
T_1 V_151 = F_16 ( V_4 ) -> V_77 ;
T_1 V_318 = F_16 ( V_4 ) -> V_151 ;
bool V_303 = false ;
T_1 V_333 ;
int V_376 = V_30 -> V_110 ;
const int V_288 = V_30 -> V_110 - V_30 -> V_133 ;
int V_226 = 0 ;
long V_207 = - 1L ;
F_195 ( V_2 -> V_377 . V_345 ) ;
if ( F_46 ( V_318 , V_158 ) ) {
if ( F_46 ( V_318 , V_158 - V_30 -> V_144 ) ) {
F_207 ( V_2 ) ;
return - 1 ;
}
goto V_378;
}
if ( F_53 ( V_318 , V_30 -> V_107 ) )
goto V_379;
if ( V_6 -> V_322 == V_251 ||
V_6 -> V_322 == V_323 )
F_185 ( V_2 ) ;
if ( F_53 ( V_318 , V_158 ) ) {
V_181 |= V_305 ;
V_6 -> V_230 = 0 ;
}
V_333 = V_30 -> V_132 ;
if ( V_181 & V_380 )
F_211 ( V_30 , F_16 ( V_4 ) -> V_77 ) ;
if ( ! ( V_181 & V_381 ) && F_53 ( V_318 , V_158 ) ) {
F_205 ( V_30 , V_151 ) ;
V_30 -> V_105 = V_318 ;
V_181 |= V_361 ;
F_214 ( V_2 , V_382 ) ;
F_69 ( F_70 ( V_2 ) , V_383 ) ;
} else {
T_1 V_384 = V_385 ;
if ( V_151 != F_16 ( V_4 ) -> V_92 )
V_181 |= V_386 ;
else
F_69 ( F_70 ( V_2 ) , V_387 ) ;
V_181 |= F_204 ( V_2 , V_4 , V_318 , V_151 ) ;
if ( F_16 ( V_4 ) -> V_139 )
V_181 |= F_115 ( V_2 , V_4 , V_158 ,
& V_207 ) ;
if ( F_22 ( V_30 , F_6 ( V_4 ) ) ) {
V_181 |= V_248 ;
V_384 |= V_388 ;
}
if ( V_181 & V_361 )
V_384 |= V_382 ;
F_214 ( V_2 , V_384 ) ;
}
V_2 -> V_389 = 0 ;
V_6 -> V_390 = 0 ;
V_30 -> V_391 = V_76 ;
if ( ! V_376 )
goto V_392;
V_226 = V_30 -> V_110 ;
V_181 |= F_194 ( V_2 , V_333 , V_158 ,
V_207 ) ;
V_226 -= V_30 -> V_110 ;
if ( F_201 ( V_2 , V_181 ) )
F_184 ( V_2 , V_318 , V_226 ) ;
if ( F_200 ( V_2 , V_181 ) ) {
V_303 = ! ( V_181 & ( V_305 | V_354 ) ) ;
F_180 ( V_2 , V_226 , V_288 ,
V_303 , V_181 ) ;
}
if ( V_30 -> V_284 )
F_213 ( V_2 , V_318 , V_181 ) ;
if ( ( V_181 & V_356 ) || ! ( V_181 & V_354 ) ) {
struct V_113 * V_114 = F_216 ( V_2 ) ;
if ( V_114 )
F_217 ( V_114 ) ;
}
if ( V_6 -> V_322 == V_245 )
F_218 ( V_2 ) ;
F_55 ( V_2 ) ;
return 1 ;
V_392:
if ( V_181 & V_217 )
F_180 ( V_2 , V_226 , V_288 ,
V_303 , V_181 ) ;
if ( F_81 ( V_2 ) )
F_197 ( V_2 ) ;
if ( V_30 -> V_284 )
F_213 ( V_2 , V_318 , V_181 ) ;
return 1 ;
V_379:
F_219 ( V_2 , L_12 , V_318 , V_30 -> V_105 , V_30 -> V_107 ) ;
return - 1 ;
V_378:
if ( F_16 ( V_4 ) -> V_139 ) {
V_181 |= F_115 ( V_2 , V_4 , V_158 ,
& V_207 ) ;
F_180 ( V_2 , V_226 , V_288 ,
V_303 , V_181 ) ;
}
F_219 ( V_2 , L_13 , V_318 , V_30 -> V_105 , V_30 -> V_107 ) ;
return 0 ;
}
void F_220 ( const struct V_3 * V_4 ,
struct V_393 * V_394 , int V_395 ,
struct V_396 * V_397 )
{
const unsigned char * V_208 ;
const struct V_15 * V_43 = F_6 ( V_4 ) ;
int V_398 = ( V_43 -> V_399 * 4 ) - sizeof( struct V_15 ) ;
V_208 = ( const unsigned char * ) ( V_43 + 1 ) ;
V_394 -> V_263 = 0 ;
while ( V_398 > 0 ) {
int V_400 = * V_208 ++ ;
int V_401 ;
switch ( V_400 ) {
case V_402 :
return;
case V_403 :
V_398 -- ;
continue;
default:
V_401 = * V_208 ++ ;
if ( V_401 < 2 )
return;
if ( V_401 > V_398 )
return;
switch ( V_400 ) {
case V_404 :
if ( V_401 == V_405 && V_43 -> V_45 && ! V_395 ) {
T_6 V_406 = F_221 ( V_208 ) ;
if ( V_406 ) {
if ( V_394 -> V_407 &&
V_394 -> V_407 < V_406 )
V_406 = V_394 -> V_407 ;
V_394 -> V_50 = V_406 ;
}
}
break;
case V_408 :
if ( V_401 == V_409 && V_43 -> V_45 &&
! V_395 && V_410 ) {
T_7 V_360 = * ( T_7 * ) V_208 ;
V_394 -> V_411 = 1 ;
if ( V_360 > 14 ) {
F_222 ( L_14 ,
V_412 ,
V_360 ) ;
V_360 = 14 ;
}
V_394 -> V_360 = V_360 ;
}
break;
case V_413 :
if ( ( V_401 == V_414 ) &&
( ( V_395 && V_394 -> V_415 ) ||
( ! V_395 && V_416 ) ) ) {
V_394 -> V_263 = 1 ;
V_394 -> V_369 = F_83 ( V_208 ) ;
V_394 -> V_91 = F_83 ( V_208 + 4 ) ;
}
break;
case V_417 :
if ( V_401 == V_418 && V_43 -> V_45 &&
! V_395 && V_419 ) {
V_394 -> V_119 = V_420 ;
F_223 ( V_394 ) ;
}
break;
case V_421 :
if ( ( V_401 >= ( V_211 + V_422 ) ) &&
! ( ( V_401 - V_211 ) % V_422 ) &&
V_394 -> V_119 ) {
F_16 ( V_4 ) -> V_139 = ( V_208 - 2 ) - ( unsigned char * ) V_43 ;
}
break;
#ifdef F_224
case V_423 :
break;
#endif
case V_424 :
if ( V_401 < V_425 ||
F_221 ( V_208 ) != V_426 ||
V_397 == NULL || ! V_43 -> V_45 || ( V_401 & 1 ) )
break;
V_397 -> V_10 = V_401 - V_425 ;
if ( V_397 -> V_10 >= V_427 &&
V_397 -> V_10 <= V_428 )
memcpy ( V_397 -> V_429 , V_208 + 2 , V_397 -> V_10 ) ;
else if ( V_397 -> V_10 != 0 )
V_397 -> V_10 = - 1 ;
break;
}
V_208 += V_401 - 2 ;
V_398 -= V_401 ;
}
}
}
static bool F_225 ( struct V_29 * V_30 , const struct V_15 * V_43 )
{
const T_8 * V_208 = ( const T_8 * ) ( V_43 + 1 ) ;
if ( * V_208 == F_226 ( ( V_403 << 24 ) | ( V_403 << 16 )
| ( V_413 << 8 ) | V_414 ) ) {
V_30 -> V_49 . V_263 = 1 ;
++ V_208 ;
V_30 -> V_49 . V_369 = F_227 ( * V_208 ) ;
++ V_208 ;
if ( * V_208 )
V_30 -> V_49 . V_91 = F_227 ( * V_208 ) - V_30 -> V_430 ;
else
V_30 -> V_49 . V_91 = 0 ;
return true ;
}
return false ;
}
static bool F_228 ( const struct V_3 * V_4 ,
const struct V_15 * V_43 , struct V_29 * V_30 )
{
if ( V_43 -> V_399 == ( sizeof( * V_43 ) / 4 ) ) {
V_30 -> V_49 . V_263 = 0 ;
return false ;
} else if ( V_30 -> V_49 . V_415 &&
V_43 -> V_399 == ( ( sizeof( * V_43 ) + V_431 ) / 4 ) ) {
if ( F_225 ( V_30 , V_43 ) )
return true ;
}
F_220 ( V_4 , & V_30 -> V_49 , 1 , NULL ) ;
if ( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 )
V_30 -> V_49 . V_91 -= V_30 -> V_430 ;
return true ;
}
const T_4 * F_229 ( const struct V_15 * V_43 )
{
int V_398 = ( V_43 -> V_399 << 2 ) - sizeof( * V_43 ) ;
const T_4 * V_208 = ( const T_4 * ) ( V_43 + 1 ) ;
if ( V_398 < V_432 )
return NULL ;
while ( V_398 > 0 ) {
int V_400 = * V_208 ++ ;
int V_401 ;
switch ( V_400 ) {
case V_402 :
return NULL ;
case V_403 :
V_398 -- ;
continue;
default:
V_401 = * V_208 ++ ;
if ( V_401 < 2 || V_401 > V_398 )
return NULL ;
if ( V_400 == V_423 )
return V_401 == V_432 ? V_208 : NULL ;
}
V_208 += V_401 - 2 ;
V_398 -= V_401 ;
}
return NULL ;
}
static int F_230 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_43 = F_6 ( V_4 ) ;
T_1 V_77 = F_16 ( V_4 ) -> V_77 ;
T_1 V_318 = F_16 ( V_4 ) -> V_151 ;
return (
( V_43 -> V_318 && V_77 == F_16 ( V_4 ) -> V_92 && V_77 == V_30 -> V_90 ) &&
V_318 == V_30 -> V_105 &&
! F_203 ( V_30 , V_318 , V_77 , F_152 ( V_43 -> V_60 ) << V_30 -> V_49 . V_360 ) &&
( T_5 ) ( V_30 -> V_49 . V_368 - V_30 -> V_49 . V_369 ) <= ( F_2 ( V_2 ) -> V_98 * 1024 ) / V_365 ) ;
}
static inline bool F_231 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_212 ( & V_30 -> V_49 , V_433 ) &&
! F_230 ( V_2 , V_4 ) ;
}
static inline bool F_232 ( const struct V_29 * V_30 , T_1 V_77 , T_1 V_92 )
{
return ! F_46 ( V_92 , V_30 -> V_371 ) &&
! F_53 ( V_77 , V_30 -> V_90 + F_233 ( V_30 ) ) ;
}
void F_234 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_434 ) {
case V_435 :
V_2 -> V_436 = V_437 ;
break;
case V_438 :
V_2 -> V_436 = V_439 ;
break;
case V_440 :
return;
default:
V_2 -> V_436 = V_441 ;
}
F_235 () ;
if ( ! F_236 ( V_2 , V_442 ) )
V_2 -> V_443 ( V_2 ) ;
F_237 ( V_2 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_113 * V_114 ;
F_50 ( V_2 ) ;
V_2 -> V_444 |= V_445 ;
F_239 ( V_2 , V_446 ) ;
switch ( V_2 -> V_434 ) {
case V_447 :
case V_448 :
F_240 ( V_2 , V_438 ) ;
V_114 = F_216 ( V_2 ) ;
if ( ! V_114 || ! F_63 ( V_114 , V_449 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_438 :
case V_450 :
break;
case V_451 :
break;
case V_452 :
F_208 ( V_2 ) ;
F_240 ( V_2 , V_450 ) ;
break;
case V_453 :
F_208 ( V_2 ) ;
F_241 ( V_2 , V_454 , 0 ) ;
break;
default:
F_242 ( L_15 ,
V_412 , V_2 -> V_434 ) ;
break;
}
F_243 ( & V_30 -> V_455 ) ;
if ( F_143 ( V_30 ) )
F_223 ( & V_30 -> V_49 ) ;
F_51 ( V_2 ) ;
if ( ! F_236 ( V_2 , V_442 ) ) {
V_2 -> V_456 ( V_2 ) ;
if ( V_2 -> V_444 == V_457 ||
V_2 -> V_434 == V_440 )
F_244 ( V_2 , V_458 , V_459 ) ;
else
F_244 ( V_2 , V_458 , V_460 ) ;
}
}
static inline bool F_245 ( struct V_200 * V_156 , T_1 V_77 ,
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
static void F_246 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_92 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_143 ( V_30 ) && V_461 ) {
int V_124 ;
if ( F_46 ( V_77 , V_30 -> V_90 ) )
V_124 = V_462 ;
else
V_124 = V_463 ;
F_69 ( F_70 ( V_2 ) , V_124 ) ;
V_30 -> V_49 . V_464 = 1 ;
V_30 -> V_465 [ 0 ] . V_143 = V_77 ;
V_30 -> V_465 [ 0 ] . V_92 = V_92 ;
}
}
static void F_247 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_92 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_49 . V_464 )
F_246 ( V_2 , V_77 , V_92 ) ;
else
F_245 ( V_30 -> V_465 , V_77 , V_92 ) ;
}
static void F_248 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_92 != F_16 ( V_4 ) -> V_77 &&
F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) ) {
F_69 ( F_70 ( V_2 ) , V_466 ) ;
F_10 ( V_2 ) ;
if ( F_143 ( V_30 ) && V_461 ) {
T_1 V_92 = F_16 ( V_4 ) -> V_92 ;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_90 ) )
V_92 = V_30 -> V_90 ;
F_246 ( V_2 , F_16 ( V_4 ) -> V_77 , V_92 ) ;
}
}
F_208 ( V_2 ) ;
}
static void F_249 ( struct V_29 * V_30 )
{
int V_467 ;
struct V_200 * V_156 = & V_30 -> V_468 [ 0 ] ;
struct V_200 * V_469 = V_156 + 1 ;
for ( V_467 = 1 ; V_467 < V_30 -> V_49 . V_157 ; ) {
if ( F_245 ( V_156 , V_469 -> V_143 , V_469 -> V_92 ) ) {
int V_214 ;
V_30 -> V_49 . V_157 -- ;
for ( V_214 = V_467 ; V_214 < V_30 -> V_49 . V_157 ; V_214 ++ )
V_156 [ V_214 ] = V_156 [ V_214 + 1 ] ;
continue;
}
V_467 ++ , V_469 ++ ;
}
}
static void F_250 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_92 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_200 * V_156 = & V_30 -> V_468 [ 0 ] ;
int V_470 = V_30 -> V_49 . V_157 ;
int V_467 ;
if ( ! V_470 )
goto V_471;
for ( V_467 = 0 ; V_467 < V_470 ; V_467 ++ , V_156 ++ ) {
if ( F_245 ( V_156 , V_77 , V_92 ) ) {
for (; V_467 > 0 ; V_467 -- , V_156 -- )
F_118 ( * V_156 , * ( V_156 - 1 ) ) ;
if ( V_470 > 1 )
F_249 ( V_30 ) ;
return;
}
}
if ( V_467 >= V_210 ) {
V_467 -- ;
V_30 -> V_49 . V_157 -- ;
V_156 -- ;
}
for (; V_467 > 0 ; V_467 -- , V_156 -- )
* V_156 = * ( V_156 - 1 ) ;
V_471:
V_156 -> V_143 = V_77 ;
V_156 -> V_92 = V_92 ;
V_30 -> V_49 . V_157 ++ ;
}
static void F_251 ( struct V_29 * V_30 )
{
struct V_200 * V_156 = & V_30 -> V_468 [ 0 ] ;
int V_157 = V_30 -> V_49 . V_157 ;
int V_467 ;
if ( F_252 ( & V_30 -> V_455 ) ) {
V_30 -> V_49 . V_157 = 0 ;
return;
}
for ( V_467 = 0 ; V_467 < V_157 ; ) {
if ( ! F_46 ( V_30 -> V_90 , V_156 -> V_143 ) ) {
int V_214 ;
F_116 ( F_46 ( V_30 -> V_90 , V_156 -> V_92 ) ) ;
for ( V_214 = V_467 + 1 ; V_214 < V_157 ; V_214 ++ )
V_30 -> V_468 [ V_214 - 1 ] = V_30 -> V_468 [ V_214 ] ;
V_157 -- ;
continue;
}
V_467 ++ ;
V_156 ++ ;
}
V_30 -> V_49 . V_157 = V_157 ;
}
static bool F_253 ( struct V_1 * V_2 ,
struct V_3 * V_472 ,
struct V_3 * V_473 ,
bool * V_474 )
{
int V_290 ;
* V_474 = false ;
if ( F_16 ( V_473 ) -> V_77 != F_16 ( V_472 ) -> V_92 )
return false ;
if ( ! F_254 ( V_472 , V_473 , V_474 , & V_290 ) )
return false ;
F_255 ( V_290 , & V_2 -> V_81 ) ;
F_256 ( V_2 , V_290 ) ;
F_69 ( F_70 ( V_2 ) , V_475 ) ;
F_16 ( V_472 ) -> V_92 = F_16 ( V_473 ) -> V_92 ;
F_16 ( V_472 ) -> V_151 = F_16 ( V_473 ) -> V_151 ;
F_16 ( V_472 ) -> V_192 |= F_16 ( V_473 ) -> V_192 ;
return true ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_476 = V_30 -> V_90 ;
struct V_3 * V_4 , * V_477 ;
bool V_474 , V_478 ;
while ( ( V_4 = F_258 ( & V_30 -> V_455 ) ) != NULL ) {
if ( F_53 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) )
break;
if ( F_46 ( F_16 ( V_4 ) -> V_77 , V_476 ) ) {
T_3 V_464 = V_476 ;
if ( F_46 ( F_16 ( V_4 ) -> V_92 , V_476 ) )
V_476 = F_16 ( V_4 ) -> V_92 ;
F_247 ( V_2 , F_16 ( V_4 ) -> V_77 , V_464 ) ;
}
F_259 ( V_4 , & V_30 -> V_455 ) ;
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_90 ) ) {
F_219 ( V_2 , L_16 ) ;
F_260 ( V_4 ) ;
continue;
}
F_219 ( V_2 , L_17 ,
V_30 -> V_90 , F_16 ( V_4 ) -> V_77 ,
F_16 ( V_4 ) -> V_92 ) ;
V_477 = F_261 ( & V_2 -> V_479 ) ;
V_478 = V_477 && F_253 ( V_2 , V_477 , V_4 , & V_474 ) ;
V_30 -> V_90 = F_16 ( V_4 ) -> V_92 ;
if ( ! V_478 )
F_262 ( & V_2 -> V_479 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_192 & V_193 )
F_238 ( V_2 ) ;
if ( V_478 )
F_263 ( V_4 , V_474 ) ;
}
}
static int F_264 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_480 )
{
if ( F_41 ( & V_2 -> V_81 ) > V_2 -> V_69 ||
! F_265 ( V_2 , V_4 , V_480 ) ) {
if ( F_266 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_265 ( V_2 , V_4 , V_480 ) ) {
if ( ! F_267 ( V_2 ) )
return - 1 ;
if ( ! F_265 ( V_2 , V_4 , V_480 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_268 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_481 ;
T_1 V_77 , V_92 ;
F_19 ( V_30 , V_4 ) ;
if ( F_104 ( F_264 ( V_2 , V_4 , V_4 -> V_59 ) ) ) {
F_69 ( F_70 ( V_2 ) , V_482 ) ;
F_260 ( V_4 ) ;
return;
}
V_30 -> V_362 = 0 ;
F_50 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_483 ) ;
F_219 ( V_2 , L_18 ,
V_30 -> V_90 , F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ;
V_481 = F_261 ( & V_30 -> V_455 ) ;
if ( ! V_481 ) {
if ( F_143 ( V_30 ) ) {
V_30 -> V_49 . V_157 = 1 ;
V_30 -> V_468 [ 0 ] . V_143 = F_16 ( V_4 ) -> V_77 ;
V_30 -> V_468 [ 0 ] . V_92 =
F_16 ( V_4 ) -> V_92 ;
}
F_269 ( & V_30 -> V_455 , V_4 ) ;
goto V_484;
}
V_77 = F_16 ( V_4 ) -> V_77 ;
V_92 = F_16 ( V_4 ) -> V_92 ;
if ( V_77 == F_16 ( V_481 ) -> V_92 ) {
bool V_474 ;
if ( ! F_253 ( V_2 , V_481 , V_4 , & V_474 ) ) {
F_270 ( & V_30 -> V_455 , V_481 , V_4 ) ;
} else {
F_29 ( V_2 , V_4 ) ;
F_263 ( V_4 , V_474 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_49 . V_157 ||
V_30 -> V_468 [ 0 ] . V_92 != V_77 )
goto V_485;
V_30 -> V_468 [ 0 ] . V_92 = V_92 ;
goto V_484;
}
while ( 1 ) {
if ( ! F_53 ( F_16 ( V_481 ) -> V_77 , V_77 ) )
break;
if ( F_271 ( & V_30 -> V_455 , V_481 ) ) {
V_481 = NULL ;
break;
}
V_481 = F_272 ( & V_30 -> V_455 , V_481 ) ;
}
if ( V_481 && F_46 ( V_77 , F_16 ( V_481 ) -> V_92 ) ) {
if ( ! F_53 ( V_92 , F_16 ( V_481 ) -> V_92 ) ) {
F_69 ( F_70 ( V_2 ) , V_486 ) ;
F_260 ( V_4 ) ;
V_4 = NULL ;
F_246 ( V_2 , V_77 , V_92 ) ;
goto V_485;
}
if ( F_53 ( V_77 , F_16 ( V_481 ) -> V_77 ) ) {
F_246 ( V_2 , V_77 ,
F_16 ( V_481 ) -> V_92 ) ;
} else {
if ( F_271 ( & V_30 -> V_455 ,
V_481 ) )
V_481 = NULL ;
else
V_481 = F_272 (
& V_30 -> V_455 ,
V_481 ) ;
}
}
if ( ! V_481 )
F_269 ( & V_30 -> V_455 , V_4 ) ;
else
F_270 ( & V_30 -> V_455 , V_481 , V_4 ) ;
while ( ! F_273 ( & V_30 -> V_455 , V_4 ) ) {
V_481 = F_274 ( & V_30 -> V_455 , V_4 ) ;
if ( ! F_53 ( V_92 , F_16 ( V_481 ) -> V_77 ) )
break;
if ( F_46 ( V_92 , F_16 ( V_481 ) -> V_92 ) ) {
F_247 ( V_2 , F_16 ( V_481 ) -> V_77 ,
V_92 ) ;
break;
}
F_259 ( V_481 , & V_30 -> V_455 ) ;
F_247 ( V_2 , F_16 ( V_481 ) -> V_77 ,
F_16 ( V_481 ) -> V_92 ) ;
F_69 ( F_70 ( V_2 ) , V_486 ) ;
F_260 ( V_481 ) ;
}
V_485:
if ( F_143 ( V_30 ) )
F_250 ( V_2 , V_77 , V_92 ) ;
V_484:
if ( V_4 ) {
F_29 ( V_2 , V_4 ) ;
F_275 ( V_4 , V_2 ) ;
}
}
static int T_9 F_276 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_487 ,
bool * V_474 )
{
int V_478 ;
struct V_3 * V_477 = F_261 ( & V_2 -> V_479 ) ;
F_277 ( V_4 , V_487 ) ;
V_478 = ( V_477 &&
F_253 ( V_2 , V_477 , V_4 , V_474 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_90 = F_16 ( V_4 ) -> V_92 ;
if ( ! V_478 ) {
F_262 ( & V_2 -> V_479 , V_4 ) ;
F_275 ( V_4 , V_2 ) ;
}
return V_478 ;
}
int F_278 ( struct V_1 * V_2 , struct V_488 * V_264 , T_10 V_480 )
{
struct V_3 * V_4 ;
bool V_474 ;
if ( V_480 == 0 )
return 0 ;
V_4 = F_279 ( V_480 , V_2 -> V_489 ) ;
if ( ! V_4 )
goto V_166;
if ( F_264 ( V_2 , V_4 , V_4 -> V_59 ) )
goto V_490;
if ( F_280 ( F_281 ( V_4 , V_480 ) , V_264 , V_480 ) )
goto V_490;
F_16 ( V_4 ) -> V_77 = F_7 ( V_2 ) -> V_90 ;
F_16 ( V_4 ) -> V_92 = F_16 ( V_4 ) -> V_77 + V_480 ;
F_16 ( V_4 ) -> V_151 = F_7 ( V_2 ) -> V_105 - 1 ;
if ( F_276 ( V_2 , V_4 , 0 , & V_474 ) ) {
F_196 ( V_474 ) ;
F_260 ( V_4 ) ;
}
return V_480 ;
V_490:
F_282 ( V_4 ) ;
V_166:
return - V_491 ;
}
static void F_283 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_478 = - 1 ;
bool V_474 = false ;
if ( F_16 ( V_4 ) -> V_77 == F_16 ( V_4 ) -> V_92 )
goto V_492;
F_284 ( V_4 ) ;
F_277 ( V_4 , F_6 ( V_4 ) -> V_399 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_49 . V_464 = 0 ;
if ( F_16 ( V_4 ) -> V_77 == V_30 -> V_90 ) {
if ( F_233 ( V_30 ) == 0 )
goto V_493;
if ( V_30 -> V_494 . V_495 == V_496 &&
V_30 -> V_78 == V_30 -> V_90 && V_30 -> V_494 . V_10 &&
F_285 ( V_2 ) && ! V_30 -> V_497 ) {
int V_498 = F_43 (unsigned int, skb->len,
tp->ucopy.len) ;
F_286 ( V_499 ) ;
F_287 () ;
if ( ! F_288 ( V_4 , 0 , V_30 -> V_494 . V_264 , V_498 ) ) {
V_30 -> V_494 . V_10 -= V_498 ;
V_30 -> V_78 += V_498 ;
V_478 = ( V_498 == V_4 -> V_10 ) ;
F_48 ( V_2 ) ;
}
F_289 () ;
}
if ( V_478 <= 0 ) {
V_500:
if ( V_478 < 0 &&
F_264 ( V_2 , V_4 , V_4 -> V_59 ) )
goto V_492;
V_478 = F_276 ( V_2 , V_4 , 0 , & V_474 ) ;
}
V_30 -> V_90 = F_16 ( V_4 ) -> V_92 ;
if ( V_4 -> V_10 )
F_49 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_192 & V_193 )
F_238 ( V_2 ) ;
if ( ! F_252 ( & V_30 -> V_455 ) ) {
F_257 ( V_2 ) ;
if ( F_252 ( & V_30 -> V_455 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_49 . V_157 )
F_251 ( V_30 ) ;
F_206 ( V_2 ) ;
if ( V_478 > 0 )
F_263 ( V_4 , V_474 ) ;
if ( ! F_236 ( V_2 , V_442 ) )
V_2 -> V_501 ( V_2 ) ;
return;
}
if ( ! F_53 ( F_16 ( V_4 ) -> V_92 , V_30 -> V_90 ) ) {
F_69 ( F_70 ( V_2 ) , V_466 ) ;
F_246 ( V_2 , F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ;
V_493:
F_10 ( V_2 ) ;
F_50 ( V_2 ) ;
V_492:
F_260 ( V_4 ) ;
return;
}
if ( ! F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 + F_233 ( V_30 ) ) )
goto V_493;
F_10 ( V_2 ) ;
if ( F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) ) {
F_219 ( V_2 , L_19 ,
V_30 -> V_90 , F_16 ( V_4 ) -> V_77 ,
F_16 ( V_4 ) -> V_92 ) ;
F_246 ( V_2 , F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) ;
if ( ! F_233 ( V_30 ) )
goto V_493;
goto V_500;
}
F_268 ( V_2 , V_4 ) ;
}
static struct V_3 * F_290 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_502 * V_503 )
{
struct V_3 * V_345 = NULL ;
if ( ! F_273 ( V_503 , V_4 ) )
V_345 = F_274 ( V_503 , V_4 ) ;
F_259 ( V_4 , V_503 ) ;
F_260 ( V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_504 ) ;
return V_345 ;
}
static void
F_291 ( struct V_1 * V_2 , struct V_502 * V_503 ,
struct V_3 * V_505 , struct V_3 * V_477 ,
T_1 V_506 , T_1 V_484 )
{
struct V_3 * V_4 , * V_507 ;
bool V_508 ;
V_4 = V_505 ;
V_509:
V_508 = true ;
F_292 (list, skb, n) {
if ( V_4 == V_477 )
break;
if ( ! F_46 ( V_506 , F_16 ( V_4 ) -> V_92 ) ) {
V_4 = F_290 ( V_2 , V_4 , V_503 ) ;
if ( ! V_4 )
break;
goto V_509;
}
if ( ! ( F_16 ( V_4 ) -> V_192 & ( V_346 | V_193 ) ) &&
( F_28 ( V_4 -> V_59 ) > V_4 -> V_10 ||
F_46 ( F_16 ( V_4 ) -> V_77 , V_506 ) ) ) {
V_508 = false ;
break;
}
if ( ! F_273 ( V_503 , V_4 ) ) {
struct V_3 * V_345 = F_274 ( V_503 , V_4 ) ;
if ( V_345 != V_477 &&
F_16 ( V_4 ) -> V_92 != F_16 ( V_345 ) -> V_77 ) {
V_508 = false ;
break;
}
}
V_506 = F_16 ( V_4 ) -> V_92 ;
}
if ( V_508 ||
( F_16 ( V_4 ) -> V_192 & ( V_346 | V_193 ) ) )
return;
while ( F_46 ( V_506 , V_484 ) ) {
int V_510 = F_43 ( int , F_293 ( 0 , 0 ) , V_484 - V_506 ) ;
struct V_3 * V_511 ;
V_511 = F_279 ( V_510 , V_171 ) ;
if ( ! V_511 )
return;
memcpy ( V_511 -> V_512 , V_4 -> V_512 , sizeof( V_4 -> V_512 ) ) ;
F_16 ( V_511 ) -> V_77 = F_16 ( V_511 ) -> V_92 = V_506 ;
F_294 ( V_503 , V_4 , V_511 ) ;
F_275 ( V_511 , V_2 ) ;
while ( V_510 > 0 ) {
int V_513 = V_506 - F_16 ( V_4 ) -> V_77 ;
int V_480 = F_16 ( V_4 ) -> V_92 - V_506 ;
F_92 ( V_513 < 0 ) ;
if ( V_480 > 0 ) {
V_480 = F_9 ( V_510 , V_480 ) ;
if ( F_295 ( V_4 , V_513 , F_281 ( V_511 , V_480 ) , V_480 ) )
F_296 () ;
F_16 ( V_511 ) -> V_92 += V_480 ;
V_510 -= V_480 ;
V_506 += V_480 ;
}
if ( ! F_46 ( V_506 , F_16 ( V_4 ) -> V_92 ) ) {
V_4 = F_290 ( V_2 , V_4 , V_503 ) ;
if ( ! V_4 ||
V_4 == V_477 ||
( F_16 ( V_4 ) -> V_192 & ( V_346 | V_193 ) ) )
return;
}
}
}
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_258 ( & V_30 -> V_455 ) ;
struct V_3 * V_505 ;
T_1 V_506 , V_484 ;
if ( V_4 == NULL )
return;
V_506 = F_16 ( V_4 ) -> V_77 ;
V_484 = F_16 ( V_4 ) -> V_92 ;
V_505 = V_4 ;
for (; ; ) {
struct V_3 * V_345 = NULL ;
if ( ! F_273 ( & V_30 -> V_455 , V_4 ) )
V_345 = F_274 ( & V_30 -> V_455 , V_4 ) ;
V_4 = V_345 ;
if ( ! V_4 ||
F_53 ( F_16 ( V_4 ) -> V_77 , V_484 ) ||
F_46 ( F_16 ( V_4 ) -> V_92 , V_506 ) ) {
F_291 ( V_2 , & V_30 -> V_455 ,
V_505 , V_4 , V_506 , V_484 ) ;
V_505 = V_4 ;
if ( ! V_4 )
break;
V_506 = F_16 ( V_4 ) -> V_77 ;
V_484 = F_16 ( V_4 ) -> V_92 ;
} else {
if ( F_46 ( F_16 ( V_4 ) -> V_77 , V_506 ) )
V_506 = F_16 ( V_4 ) -> V_77 ;
if ( F_53 ( F_16 ( V_4 ) -> V_92 , V_484 ) )
V_484 = F_16 ( V_4 ) -> V_92 ;
}
}
}
static bool F_267 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_514 = false ;
if ( ! F_252 ( & V_30 -> V_455 ) ) {
F_69 ( F_70 ( V_2 ) , V_515 ) ;
F_243 ( & V_30 -> V_455 ) ;
if ( V_30 -> V_49 . V_119 )
F_223 ( & V_30 -> V_49 ) ;
F_51 ( V_2 ) ;
V_514 = true ;
}
return V_514 ;
}
static int F_266 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_219 ( V_2 , L_20 , V_30 -> V_78 ) ;
F_69 ( F_70 ( V_2 ) , V_516 ) ;
if ( F_41 ( & V_2 -> V_81 ) >= V_2 -> V_69 )
F_38 ( V_2 ) ;
else if ( F_31 ( V_2 ) )
V_30 -> V_62 = F_9 ( V_30 -> V_62 , 4U * V_30 -> V_65 ) ;
F_297 ( V_2 ) ;
if ( ! F_252 ( & V_2 -> V_479 ) )
F_291 ( V_2 , & V_2 -> V_479 ,
F_258 ( & V_2 -> V_479 ) ,
NULL ,
V_30 -> V_78 , V_30 -> V_90 ) ;
F_51 ( V_2 ) ;
if ( F_41 ( & V_2 -> V_81 ) <= V_2 -> V_69 )
return 0 ;
F_267 ( V_2 ) ;
if ( F_41 ( & V_2 -> V_81 ) <= V_2 -> V_69 )
return 0 ;
F_69 ( F_70 ( V_2 ) , V_517 ) ;
V_30 -> V_362 = 0 ;
return - 1 ;
}
static bool F_298 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_71 & V_73 )
return false ;
if ( F_31 ( V_2 ) )
return false ;
if ( F_39 ( V_2 ) >= F_40 ( V_2 , 0 ) )
return false ;
if ( V_30 -> V_110 >= V_30 -> V_55 )
return false ;
return true ;
}
static void F_299 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_298 ( V_2 ) ) {
F_23 ( V_2 ) ;
V_30 -> V_80 = V_76 ;
}
V_2 -> V_518 ( V_2 ) ;
}
static void F_300 ( struct V_1 * V_2 )
{
if ( F_236 ( V_2 , V_519 ) ) {
F_301 ( V_2 , V_519 ) ;
if ( V_2 -> V_520 &&
F_302 ( V_521 , & V_2 -> V_520 -> V_374 ) )
F_299 ( V_2 ) ;
}
}
static inline void F_303 ( struct V_1 * V_2 )
{
F_304 ( V_2 ) ;
F_300 ( V_2 ) ;
}
static void F_305 ( struct V_1 * V_2 , int V_522 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_90 - V_30 -> V_371 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_306 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_522 && F_258 ( & V_30 -> V_455 ) ) ) {
F_208 ( V_2 ) ;
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
static void F_310 ( struct V_1 * V_2 , const struct V_15 * V_43 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_208 = F_152 ( V_43 -> V_523 ) ;
if ( V_208 && ! V_524 )
V_208 -- ;
V_208 += F_227 ( V_43 -> V_77 ) ;
if ( F_53 ( V_30 -> V_78 , V_208 ) )
return;
if ( F_46 ( V_208 , V_30 -> V_90 ) )
return;
if ( V_30 -> V_497 && ! F_53 ( V_208 , V_30 -> V_525 ) )
return;
F_311 ( V_2 ) ;
if ( V_30 -> V_525 == V_30 -> V_78 && V_30 -> V_497 &&
! F_236 ( V_2 , V_526 ) && V_30 -> V_78 != V_30 -> V_90 ) {
struct V_3 * V_4 = F_258 ( & V_2 -> V_479 ) ;
V_30 -> V_78 ++ ;
if ( V_4 && ! F_46 ( V_30 -> V_78 , F_16 ( V_4 ) -> V_92 ) ) {
F_259 ( V_4 , & V_2 -> V_479 ) ;
F_260 ( V_4 ) ;
}
}
V_30 -> V_497 = V_527 ;
V_30 -> V_525 = V_208 ;
V_30 -> V_362 = 0 ;
}
static void F_312 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_43 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_43 -> V_528 )
F_310 ( V_2 , V_43 ) ;
if ( V_30 -> V_497 == V_527 ) {
T_1 V_208 = V_30 -> V_525 - F_227 ( V_43 -> V_77 ) + ( V_43 -> V_399 * 4 ) -
V_43 -> V_45 ;
if ( V_208 < V_4 -> V_10 ) {
T_4 V_203 ;
if ( F_295 ( V_4 , V_208 , & V_203 , 1 ) )
F_296 () ;
V_30 -> V_497 = V_529 | V_203 ;
if ( ! F_236 ( V_2 , V_442 ) )
V_2 -> V_501 ( V_2 ) ;
}
}
}
static int F_313 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_530 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_498 = V_4 -> V_10 - V_530 ;
int V_166 ;
F_287 () ;
if ( F_314 ( V_4 ) )
V_166 = F_288 ( V_4 , V_530 , V_30 -> V_494 . V_264 , V_498 ) ;
else
V_166 = F_315 ( V_4 , V_530 , V_30 -> V_494 . V_264 ) ;
if ( ! V_166 ) {
V_30 -> V_494 . V_10 -= V_498 ;
V_30 -> V_78 += V_498 ;
F_48 ( V_2 ) ;
}
F_289 () ;
return V_166 ;
}
static T_11 F_316 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_531 ;
if ( F_285 ( V_2 ) ) {
F_287 () ;
V_531 = F_317 ( V_4 ) ;
F_289 () ;
} else {
V_531 = F_317 ( V_4 ) ;
}
return V_531 ;
}
static inline bool F_318 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_314 ( V_4 ) &&
F_316 ( V_2 , V_4 ) ;
}
static bool F_319 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , int V_532 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_228 ( V_4 , V_43 , V_30 ) && V_30 -> V_49 . V_263 &&
F_231 ( V_2 , V_4 ) ) {
if ( ! V_43 -> V_533 ) {
F_69 ( F_70 ( V_2 ) , V_534 ) ;
F_248 ( V_2 , V_4 ) ;
goto V_535;
}
}
if ( ! F_232 ( V_30 , F_16 ( V_4 ) -> V_77 , F_16 ( V_4 ) -> V_92 ) ) {
if ( ! V_43 -> V_533 ) {
if ( V_43 -> V_45 )
goto V_536;
F_248 ( V_2 , V_4 ) ;
}
goto V_535;
}
if ( V_43 -> V_533 ) {
if ( F_16 ( V_4 ) -> V_77 == V_30 -> V_90 )
F_234 ( V_2 ) ;
else
F_207 ( V_2 ) ;
goto V_535;
}
if ( V_43 -> V_45 ) {
V_536:
if ( V_532 )
F_320 ( F_70 ( V_2 ) , V_537 ) ;
F_69 ( F_70 ( V_2 ) , V_538 ) ;
F_207 ( V_2 ) ;
goto V_535;
}
return true ;
V_535:
F_260 ( V_4 ) ;
return false ;
}
void F_321 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_104 ( V_2 -> V_539 == NULL ) )
F_2 ( V_2 ) -> V_540 -> V_541 ( V_2 , V_4 ) ;
V_30 -> V_49 . V_263 = 0 ;
if ( ( F_5 ( V_43 ) & V_542 ) == V_30 -> V_362 &&
F_16 ( V_4 ) -> V_77 == V_30 -> V_90 &&
! F_53 ( F_16 ( V_4 ) -> V_151 , V_30 -> V_107 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_431 ) {
if ( ! F_225 ( V_30 , V_43 ) )
goto V_543;
if ( ( T_5 ) ( V_30 -> V_49 . V_369 - V_30 -> V_49 . V_368 ) < 0 )
goto V_543;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_431 ) &&
V_30 -> V_90 == V_30 -> V_371 )
F_209 ( V_30 ) ;
F_215 ( V_2 , V_4 , 0 ) ;
F_260 ( V_4 ) ;
F_303 ( V_2 ) ;
return;
} else {
F_320 ( F_70 ( V_2 ) , V_537 ) ;
goto V_535;
}
} else {
int V_478 = 0 ;
bool V_474 = false ;
if ( V_30 -> V_494 . V_495 == V_496 &&
V_30 -> V_78 == V_30 -> V_90 &&
V_10 - V_18 <= V_30 -> V_494 . V_10 &&
F_285 ( V_2 ) ) {
F_286 ( V_499 ) ;
if ( ! F_313 ( V_2 , V_4 , V_18 ) ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_431 ) &&
V_30 -> V_90 == V_30 -> V_371 )
F_209 ( V_30 ) ;
F_47 ( V_2 , V_4 ) ;
F_277 ( V_4 , V_18 ) ;
V_30 -> V_90 = F_16 ( V_4 ) -> V_92 ;
F_69 ( F_70 ( V_2 ) , V_544 ) ;
V_478 = 1 ;
}
}
if ( ! V_478 ) {
if ( F_318 ( V_2 , V_4 ) )
goto V_545;
if ( ( int ) V_4 -> V_59 > V_2 -> V_546 )
goto V_547;
if ( V_18 ==
( sizeof( struct V_15 ) + V_431 ) &&
V_30 -> V_90 == V_30 -> V_371 )
F_209 ( V_30 ) ;
F_47 ( V_2 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_548 ) ;
V_478 = F_276 ( V_2 , V_4 , V_18 ,
& V_474 ) ;
}
F_49 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_151 != V_30 -> V_105 ) {
F_215 ( V_2 , V_4 , V_386 ) ;
F_303 ( V_2 ) ;
if ( ! F_309 ( V_2 ) )
goto V_549;
}
F_305 ( V_2 , 0 ) ;
V_549:
if ( V_478 )
F_263 ( V_4 , V_474 ) ;
V_2 -> V_501 ( V_2 ) ;
return;
}
}
V_543:
if ( V_10 < ( V_43 -> V_399 << 2 ) || F_318 ( V_2 , V_4 ) )
goto V_545;
if ( ! V_43 -> V_318 && ! V_43 -> V_533 && ! V_43 -> V_45 )
goto V_535;
if ( ! F_319 ( V_2 , V_4 , V_43 , 1 ) )
return;
V_547:
if ( F_215 ( V_2 , V_4 , V_381 | V_380 ) < 0 )
goto V_535;
F_47 ( V_2 , V_4 ) ;
F_312 ( V_2 , V_4 , V_43 ) ;
F_283 ( V_2 , V_4 ) ;
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
return;
V_545:
F_320 ( F_70 ( V_2 ) , V_550 ) ;
F_320 ( F_70 ( V_2 ) , V_537 ) ;
V_535:
F_260 ( V_4 ) ;
}
void F_322 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_240 ( V_2 , V_448 ) ;
if ( V_4 != NULL ) {
V_6 -> V_540 -> V_541 ( V_2 , V_4 ) ;
F_323 ( V_2 , V_4 ) ;
}
V_6 -> V_540 -> V_551 ( V_2 ) ;
F_324 ( V_2 ) ;
F_325 ( V_2 ) ;
V_30 -> V_552 = V_76 ;
F_35 ( V_2 ) ;
if ( F_236 ( V_2 , V_553 ) )
F_326 ( V_2 , F_327 ( V_30 ) ) ;
if ( ! V_30 -> V_49 . V_360 )
F_328 ( V_30 , V_30 -> V_359 ) ;
else
V_30 -> V_362 = 0 ;
if ( ! F_236 ( V_2 , V_442 ) ) {
V_2 -> V_456 ( V_2 ) ;
F_244 ( V_2 , V_554 , V_555 ) ;
}
}
static bool F_329 ( struct V_1 * V_2 , struct V_3 * V_556 ,
struct V_396 * V_557 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_13 = V_30 -> V_558 ? F_105 ( V_2 ) : NULL ;
T_6 V_66 = V_30 -> V_49 . V_50 ;
bool V_559 ;
if ( V_66 == V_30 -> V_49 . V_407 ) {
struct V_393 V_560 ;
F_330 ( & V_560 ) ;
V_560 . V_407 = V_560 . V_50 = 0 ;
F_220 ( V_556 , & V_560 , 0 , NULL ) ;
V_66 = V_560 . V_50 ;
}
if ( ! V_30 -> V_561 )
V_557 -> V_10 = - 1 ;
V_559 = ( V_557 -> V_10 <= 0 && V_13 && V_30 -> V_316 ) ;
F_331 ( V_2 , V_66 , V_557 , V_559 ) ;
if ( V_13 ) {
F_110 (data, sk) {
if ( V_13 == F_81 ( V_2 ) ||
F_332 ( V_2 , V_13 ) )
break;
}
F_185 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_562 ) ;
return true ;
}
V_30 -> V_563 = V_30 -> V_558 ;
if ( V_30 -> V_563 )
F_69 ( F_70 ( V_2 ) , V_564 ) ;
return false ;
}
static int F_333 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , unsigned int V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_396 V_397 = { . V_10 = - 1 } ;
int V_565 = V_30 -> V_49 . V_50 ;
F_220 ( V_4 , & V_30 -> V_49 , 0 , & V_397 ) ;
if ( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 )
V_30 -> V_49 . V_91 -= V_30 -> V_430 ;
if ( V_43 -> V_318 ) {
if ( ! F_53 ( F_16 ( V_4 ) -> V_151 , V_30 -> V_105 ) ||
F_53 ( F_16 ( V_4 ) -> V_151 , V_30 -> V_107 ) )
goto V_566;
if ( V_30 -> V_49 . V_263 && V_30 -> V_49 . V_91 &&
! F_192 ( V_30 -> V_49 . V_91 , V_30 -> V_262 ,
V_76 ) ) {
F_69 ( F_70 ( V_2 ) , V_567 ) ;
goto V_566;
}
if ( V_43 -> V_533 ) {
F_234 ( V_2 ) ;
goto V_535;
}
if ( ! V_43 -> V_45 )
goto V_568;
F_20 ( V_30 , V_43 ) ;
F_334 ( V_30 , F_16 ( V_4 ) -> V_77 ) ;
F_215 ( V_2 , V_4 , V_381 ) ;
V_30 -> V_90 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_371 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_359 = F_152 ( V_43 -> V_60 ) ;
if ( ! V_30 -> V_49 . V_411 ) {
V_30 -> V_49 . V_360 = V_30 -> V_49 . V_569 = 0 ;
V_30 -> V_63 = F_9 ( V_30 -> V_63 , 65535U ) ;
}
if ( V_30 -> V_49 . V_263 ) {
V_30 -> V_49 . V_415 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_431 ;
V_30 -> V_65 -= V_431 ;
F_209 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_143 ( V_30 ) && V_570 )
F_335 ( V_30 ) ;
F_336 ( V_2 ) ;
F_171 ( V_2 , V_6 -> V_298 ) ;
F_42 ( V_2 ) ;
V_30 -> V_78 = V_30 -> V_90 ;
F_337 () ;
F_322 ( V_2 , V_4 ) ;
if ( ( V_30 -> V_561 || V_30 -> V_558 ) &&
F_329 ( V_2 , V_4 , & V_397 ) )
return - 1 ;
if ( V_2 -> V_571 ||
V_6 -> V_572 . V_573 ||
V_6 -> V_8 . V_26 ) {
F_50 ( V_2 ) ;
V_6 -> V_8 . V_97 = V_76 ;
F_10 ( V_2 ) ;
F_135 ( V_2 , V_574 ,
V_575 , V_246 ) ;
V_535:
F_260 ( V_4 ) ;
return 0 ;
} else {
F_208 ( V_2 ) ;
}
return - 1 ;
}
if ( V_43 -> V_533 ) {
goto V_568;
}
if ( V_30 -> V_49 . V_370 && V_30 -> V_49 . V_263 &&
F_338 ( & V_30 -> V_49 , 0 ) )
goto V_568;
if ( V_43 -> V_45 ) {
F_240 ( V_2 , V_447 ) ;
if ( V_30 -> V_49 . V_263 ) {
V_30 -> V_49 . V_415 = 1 ;
F_209 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_431 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_90 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_371 = F_16 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_359 = F_152 ( V_43 -> V_60 ) ;
V_30 -> V_358 = F_16 ( V_4 ) -> V_77 ;
V_30 -> V_144 = V_30 -> V_359 ;
F_21 ( V_30 , V_43 ) ;
F_336 ( V_2 ) ;
F_171 ( V_2 , V_6 -> V_298 ) ;
F_42 ( V_2 ) ;
F_339 ( V_2 ) ;
#if 0
return -1;
#else
goto V_535;
#endif
}
V_568:
F_330 ( & V_30 -> V_49 ) ;
V_30 -> V_49 . V_50 = V_565 ;
goto V_535;
V_566:
F_330 ( & V_30 -> V_49 ) ;
V_30 -> V_49 . V_50 = V_565 ;
return 1 ;
}
int F_340 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_43 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_576 * V_577 ;
int V_578 = 0 ;
bool V_579 ;
T_1 V_315 ;
V_30 -> V_49 . V_263 = 0 ;
switch ( V_2 -> V_434 ) {
case V_440 :
goto V_535;
case V_580 :
if ( V_43 -> V_318 )
return 1 ;
if ( V_43 -> V_533 )
goto V_535;
if ( V_43 -> V_45 ) {
if ( V_43 -> V_581 )
goto V_535;
if ( V_6 -> V_540 -> V_582 ( V_2 , V_4 ) < 0 )
return 1 ;
F_282 ( V_4 ) ;
return 0 ;
}
goto V_535;
case V_435 :
V_578 = F_333 ( V_2 , V_4 , V_43 , V_10 ) ;
if ( V_578 >= 0 )
return V_578 ;
F_312 ( V_2 , V_4 , V_43 ) ;
F_260 ( V_4 ) ;
F_303 ( V_2 ) ;
return 0 ;
}
V_577 = V_30 -> V_320 ;
if ( V_577 != NULL ) {
F_196 ( V_2 -> V_434 != V_447 &&
V_2 -> V_434 != V_452 ) ;
if ( F_341 ( V_2 , V_4 , V_577 , NULL , true ) == NULL )
goto V_535;
}
if ( ! V_43 -> V_318 && ! V_43 -> V_533 && ! V_43 -> V_45 )
goto V_535;
if ( ! F_319 ( V_2 , V_4 , V_43 , 0 ) )
return 0 ;
V_579 = F_215 ( V_2 , V_4 , V_381 |
V_380 ) > 0 ;
switch ( V_2 -> V_434 ) {
case V_447 :
if ( ! V_579 )
return 1 ;
if ( V_577 ) {
V_315 = F_342 ( V_577 ) -> V_583 ;
V_30 -> V_316 = V_577 -> V_584 ;
F_343 ( V_2 , V_577 , false ) ;
} else {
V_315 = V_30 -> V_552 ;
V_6 -> V_540 -> V_551 ( V_2 ) ;
F_325 ( V_2 ) ;
F_336 ( V_2 ) ;
V_30 -> V_78 = V_30 -> V_90 ;
F_35 ( V_2 ) ;
}
F_337 () ;
F_240 ( V_2 , V_448 ) ;
V_2 -> V_456 ( V_2 ) ;
if ( V_2 -> V_520 )
F_244 ( V_2 , V_554 , V_555 ) ;
V_30 -> V_105 = F_16 ( V_4 ) -> V_151 ;
V_30 -> V_359 = F_152 ( V_43 -> V_60 ) << V_30 -> V_49 . V_360 ;
F_334 ( V_30 , F_16 ( V_4 ) -> V_77 ) ;
F_183 ( V_2 , V_315 ) ;
if ( V_30 -> V_49 . V_415 )
V_30 -> V_65 -= V_431 ;
if ( V_577 ) {
F_185 ( V_2 ) ;
} else
F_324 ( V_2 ) ;
F_55 ( V_2 ) ;
V_30 -> V_552 = V_76 ;
F_42 ( V_2 ) ;
F_344 ( V_30 ) ;
break;
case V_452 : {
struct V_113 * V_114 ;
int V_585 ;
if ( V_577 != NULL ) {
if ( ! V_579 )
return 1 ;
F_343 ( V_2 , V_577 , false ) ;
F_185 ( V_2 ) ;
}
if ( V_30 -> V_105 != V_30 -> V_586 )
break;
F_240 ( V_2 , V_453 ) ;
V_2 -> V_444 |= V_587 ;
V_114 = F_216 ( V_2 ) ;
if ( V_114 )
F_217 ( V_114 ) ;
if ( ! F_236 ( V_2 , V_442 ) ) {
V_2 -> V_456 ( V_2 ) ;
break;
}
if ( V_30 -> V_588 < 0 ||
( F_16 ( V_4 ) -> V_92 != F_16 ( V_4 ) -> V_77 &&
F_53 ( F_16 ( V_4 ) -> V_92 - V_43 -> V_581 , V_30 -> V_90 ) ) ) {
F_237 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_589 ) ;
return 1 ;
}
V_585 = F_345 ( V_2 ) ;
if ( V_585 > V_590 ) {
F_326 ( V_2 , V_585 - V_590 ) ;
} else if ( V_43 -> V_581 || F_285 ( V_2 ) ) {
F_326 ( V_2 , V_585 ) ;
} else {
F_241 ( V_2 , V_453 , V_585 ) ;
goto V_535;
}
break;
}
case V_450 :
if ( V_30 -> V_105 == V_30 -> V_586 ) {
F_241 ( V_2 , V_454 , 0 ) ;
goto V_535;
}
break;
case V_451 :
if ( V_30 -> V_105 == V_30 -> V_586 ) {
F_346 ( V_2 ) ;
F_237 ( V_2 ) ;
goto V_535;
}
break;
}
F_312 ( V_2 , V_4 , V_43 ) ;
switch ( V_2 -> V_434 ) {
case V_438 :
case V_450 :
case V_451 :
if ( ! F_46 ( F_16 ( V_4 ) -> V_77 , V_30 -> V_90 ) )
break;
case V_452 :
case V_453 :
if ( V_2 -> V_444 & V_445 ) {
if ( F_16 ( V_4 ) -> V_92 != F_16 ( V_4 ) -> V_77 &&
F_53 ( F_16 ( V_4 ) -> V_92 - V_43 -> V_581 , V_30 -> V_90 ) ) {
F_69 ( F_70 ( V_2 ) , V_589 ) ;
F_234 ( V_2 ) ;
return 1 ;
}
}
case V_448 :
F_283 ( V_2 , V_4 ) ;
V_578 = 1 ;
break;
}
if ( V_2 -> V_434 != V_440 ) {
F_303 ( V_2 ) ;
F_308 ( V_2 ) ;
}
if ( ! V_578 ) {
V_535:
F_260 ( V_4 ) ;
}
return 0 ;
}
static inline void F_347 ( struct V_576 * V_577 , T_12 V_591 , int V_592 )
{
struct V_593 * V_594 = F_348 ( V_577 ) ;
if ( V_592 == V_268 )
F_349 ( L_21 ,
& V_594 -> V_595 , V_591 ) ;
#if F_154 ( V_271 )
else if ( V_592 == V_272 )
F_349 ( L_22 ,
& V_594 -> V_596 , V_591 ) ;
#endif
}
static void F_350 ( struct V_576 * V_577 ,
const struct V_3 * V_4 ,
const struct V_1 * V_597 ,
const struct V_113 * V_114 )
{
const struct V_15 * V_43 = F_6 ( V_4 ) ;
const struct V_598 * V_598 = F_70 ( V_597 ) ;
bool V_599 = V_43 -> V_44 && V_43 -> V_34 ;
bool V_600 , V_601 , V_602 ;
if ( ! V_599 )
return;
V_600 = ! F_351 ( F_16 ( V_4 ) -> V_36 ) ;
V_601 = F_17 ( V_597 ) ;
V_602 = V_598 -> V_603 . V_604 || F_352 ( V_114 , V_605 ) ;
if ( ! V_600 && ! V_601 && V_602 )
F_348 ( V_577 ) -> V_602 = 1 ;
else if ( V_600 && V_601 )
F_348 ( V_577 ) -> V_602 = 1 ;
}
int F_353 ( struct V_606 * V_607 ,
const struct V_608 * V_609 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_393 V_610 ;
struct V_576 * V_577 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_113 * V_114 = NULL ;
T_3 V_611 = F_16 ( V_4 ) -> V_612 ;
bool V_613 = false , V_614 ;
struct V_615 V_616 ;
struct V_396 V_397 = { . V_10 = - 1 } ;
int V_166 ;
if ( ( V_617 == 2 ||
F_354 ( V_2 ) ) && ! V_611 ) {
V_613 = F_355 ( V_2 , V_4 , V_607 -> V_618 ) ;
if ( ! V_613 )
goto V_492;
}
if ( F_356 ( V_2 ) && F_357 ( V_2 ) > 1 ) {
F_69 ( F_70 ( V_2 ) , V_619 ) ;
goto V_492;
}
V_577 = F_358 ( V_607 ) ;
if ( ! V_577 )
goto V_492;
F_342 ( V_577 ) -> V_620 = V_609 ;
F_330 ( & V_610 ) ;
V_610 . V_50 = V_609 -> V_50 ;
V_610 . V_407 = V_30 -> V_49 . V_407 ;
F_220 ( V_4 , & V_610 , 0 , V_613 ? NULL : & V_397 ) ;
if ( V_613 && ! V_610 . V_263 )
F_330 ( & V_610 ) ;
V_610 . V_415 = V_610 . V_263 ;
F_359 ( V_577 , & V_610 , V_4 , V_2 ) ;
V_609 -> V_621 ( V_577 , V_2 , V_4 ) ;
if ( F_360 ( V_2 , V_4 , V_577 ) )
goto V_622;
if ( ! V_613 && ! V_611 ) {
if ( V_623 . V_624 ) {
bool V_625 ;
V_114 = V_609 -> V_626 ( V_2 , & V_616 , V_577 , & V_625 ) ;
if ( V_114 && V_625 &&
! F_361 ( V_577 , V_114 , true ,
V_610 . V_263 ) ) {
F_69 ( F_70 ( V_2 ) , V_627 ) ;
goto V_628;
}
}
else if ( ! V_617 &&
( V_629 - F_362 ( V_2 ) <
( V_629 >> 2 ) ) &&
! F_361 ( V_577 , V_114 , false ,
V_610 . V_263 ) ) {
F_347 ( V_577 , F_152 ( F_6 ( V_4 ) -> V_630 ) ,
V_607 -> V_592 ) ;
goto V_628;
}
V_611 = V_609 -> V_631 ( V_4 ) ;
}
if ( ! V_114 ) {
V_114 = V_609 -> V_626 ( V_2 , & V_616 , V_577 , NULL ) ;
if ( ! V_114 )
goto V_622;
}
F_350 ( V_577 , V_4 , V_2 , V_114 ) ;
if ( V_613 ) {
V_611 = F_363 ( V_609 , V_2 , V_4 , & V_577 -> V_66 ) ;
V_577 -> V_632 = V_610 . V_415 ;
if ( ! V_610 . V_415 )
F_348 ( V_577 ) -> V_602 = 0 ;
}
F_342 ( V_577 ) -> V_633 = V_611 ;
F_364 ( V_577 , V_2 , V_114 ) ;
V_614 = ! V_613 &&
F_365 ( V_2 , V_4 , V_577 , & V_397 , V_114 ) ;
V_166 = V_609 -> V_634 ( V_2 , V_114 , & V_616 , V_577 ,
F_366 ( V_4 ) , & V_397 ) ;
if ( ! V_614 ) {
if ( V_166 || V_613 )
goto V_622;
F_342 ( V_577 ) -> V_635 = NULL ;
V_609 -> V_636 ( V_2 , V_577 , V_637 ) ;
}
return 0 ;
V_628:
F_367 ( V_114 ) ;
V_622:
F_368 ( V_577 ) ;
V_492:
F_69 ( F_70 ( V_2 ) , V_638 ) ;
return 0 ;
}
