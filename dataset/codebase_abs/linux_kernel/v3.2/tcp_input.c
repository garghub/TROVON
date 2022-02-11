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
unsigned V_22 = F_7 ( V_2 ) -> V_23 / ( 2 * V_6 -> V_8 . V_12 ) ;
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
static inline int F_11 ( const struct V_1 * V_2 )
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
static inline int F_19 ( const struct V_29 * V_30 , const struct V_15 * V_41 )
{
if ( V_41 -> V_42 && ! V_41 -> V_43 && ( V_30 -> V_31 & V_32 ) )
return 1 ;
return 0 ;
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
! V_56 ) {
int V_57 ;
if ( F_23 ( V_4 -> V_51 ) <= V_4 -> V_10 )
V_57 = 2 * V_30 -> V_58 ;
else
V_57 = F_22 ( V_2 , V_4 ) ;
if ( V_57 ) {
V_30 -> V_54 = F_9 ( V_30 -> V_54 + V_57 ,
V_30 -> V_55 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_59 = F_7 ( V_2 ) -> V_58 ;
T_1 V_60 = V_61 ;
int V_62 ;
if ( V_59 > 1460 )
V_60 = F_27 ( T_1 , ( 1460 * V_61 ) / V_59 , 2 ) ;
V_62 = F_21 ( V_59 + V_47 ) ;
while ( F_23 ( V_62 ) < V_59 )
V_62 += 128 ;
V_62 *= V_60 ;
if ( V_2 -> V_63 < V_62 )
V_2 -> V_63 = F_9 ( V_62 , V_53 [ 2 ] ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_64 ;
if ( ! ( V_2 -> V_65 & V_66 ) )
F_26 ( V_2 ) ;
if ( ! ( V_2 -> V_65 & V_67 ) )
F_20 ( V_2 ) ;
V_30 -> V_68 . V_69 = V_30 -> V_23 ;
V_64 = F_29 ( V_2 ) ;
if ( V_30 -> V_55 >= V_64 ) {
V_30 -> V_55 = V_64 ;
if ( V_70 && V_64 > 4 * V_30 -> V_58 )
V_30 -> V_55 = F_30 ( V_64 -
( V_64 >> V_70 ) ,
4 * V_30 -> V_58 ) ;
}
if ( V_70 &&
V_30 -> V_55 > 2 * V_30 -> V_58 &&
V_30 -> V_55 + V_30 -> V_58 > V_64 )
V_30 -> V_55 = F_30 ( 2 * V_30 -> V_58 , V_64 - V_30 -> V_58 ) ;
V_30 -> V_54 = F_9 ( V_30 -> V_54 , V_30 -> V_55 ) ;
V_30 -> V_71 = V_72 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_63 < V_53 [ 2 ] &&
! ( V_2 -> V_65 & V_66 ) &&
! V_56 &&
F_32 ( & V_73 ) < V_74 [ 0 ] ) {
V_2 -> V_63 = F_9 ( F_33 ( & V_2 -> V_75 ) ,
V_53 [ 2 ] ) ;
}
if ( F_33 ( & V_2 -> V_75 ) > V_2 -> V_63 )
V_30 -> V_54 = F_9 ( V_30 -> V_55 , 2U * V_30 -> V_58 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned int V_76 = F_35 (unsigned int, tp->advmss, tp->mss_cache) ;
V_76 = F_9 ( V_76 , V_30 -> V_23 / 2 ) ;
V_76 = F_9 ( V_76 , V_14 ) ;
V_76 = F_30 ( V_76 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_76 ;
}
static void F_36 ( struct V_29 * V_30 , T_1 V_77 , int V_78 )
{
T_1 V_79 = V_30 -> V_80 . V_81 ;
long V_82 = V_77 ;
if ( V_82 == 0 )
V_82 = 1 ;
if ( V_79 != 0 ) {
if ( ! V_78 ) {
V_82 -= ( V_79 >> 3 ) ;
V_79 += V_82 ;
} else if ( V_82 < V_79 )
V_79 = V_82 << 3 ;
} else {
V_79 = V_82 << 3 ;
}
if ( V_30 -> V_80 . V_81 != V_79 )
V_30 -> V_80 . V_81 = V_79 ;
}
static inline void F_37 ( struct V_29 * V_30 )
{
if ( V_30 -> V_80 . time == 0 )
goto V_83;
if ( F_38 ( V_30 -> V_84 , V_30 -> V_80 . V_85 ) )
return;
F_36 ( V_30 , V_86 - V_30 -> V_80 . time , 1 ) ;
V_83:
V_30 -> V_80 . V_85 = V_30 -> V_84 + V_30 -> V_23 ;
V_30 -> V_80 . time = V_72 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_87 &&
( F_16 ( V_4 ) -> V_88 -
F_16 ( V_4 ) -> V_85 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_36 ( V_30 , V_72 - V_30 -> V_45 . V_87 , 0 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int time ;
int V_69 ;
if ( V_30 -> V_68 . time == 0 )
goto V_83;
time = V_72 - V_30 -> V_68 . time ;
if ( time < ( V_30 -> V_80 . V_81 >> 3 ) || V_30 -> V_80 . V_81 == 0 )
return;
V_69 = 2 * ( V_30 -> V_89 - V_30 -> V_68 . V_85 ) ;
V_69 = F_30 ( V_30 -> V_68 . V_69 , V_69 ) ;
if ( V_30 -> V_68 . V_69 != V_69 ) {
int V_62 ;
V_30 -> V_68 . V_69 = V_69 ;
if ( V_90 &&
! ( V_2 -> V_65 & V_66 ) ) {
int V_91 = V_69 ;
V_69 /= V_30 -> V_58 ;
if ( ! V_69 )
V_69 = 1 ;
V_62 = F_21 ( V_30 -> V_58 + V_47 ) ;
while ( F_23 ( V_62 ) < V_30 -> V_58 )
V_62 += 128 ;
V_69 *= V_62 ;
V_69 = F_9 ( V_69 , V_53 [ 2 ] ) ;
if ( V_69 > V_2 -> V_63 ) {
V_2 -> V_63 = V_69 ;
V_30 -> V_55 = V_91 ;
}
}
}
V_83:
V_30 -> V_68 . V_85 = V_30 -> V_89 ;
V_30 -> V_68 . time = V_72 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_92 ;
F_42 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_37 ( V_30 ) ;
V_92 = V_72 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_82 = V_92 - V_6 -> V_8 . V_93 ;
if ( V_82 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_82 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_82 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_94 )
V_6 -> V_8 . V_27 = V_6 -> V_94 ;
} else if ( V_82 > V_6 -> V_94 ) {
F_8 ( V_2 ) ;
F_43 ( V_2 ) ;
}
}
V_6 -> V_8 . V_93 = V_92 ;
F_15 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_24 ( V_2 , V_4 ) ;
}
static void F_44 ( struct V_1 * V_2 , const T_2 V_95 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_82 = V_95 ;
if ( V_82 == 0 )
V_82 = 1 ;
if ( V_30 -> V_96 != 0 ) {
V_82 -= ( V_30 -> V_96 >> 3 ) ;
V_30 -> V_96 += V_82 ;
if ( V_82 < 0 ) {
V_82 = - V_82 ;
V_82 -= ( V_30 -> V_97 >> 2 ) ;
if ( V_82 > 0 )
V_82 >>= 3 ;
} else {
V_82 -= ( V_30 -> V_97 >> 2 ) ;
}
V_30 -> V_97 += V_82 ;
if ( V_30 -> V_97 > V_30 -> V_98 ) {
V_30 -> V_98 = V_30 -> V_97 ;
if ( V_30 -> V_98 > V_30 -> V_99 )
V_30 -> V_99 = V_30 -> V_98 ;
}
if ( F_45 ( V_30 -> V_100 , V_30 -> V_101 ) ) {
if ( V_30 -> V_98 < V_30 -> V_99 )
V_30 -> V_99 -= ( V_30 -> V_99 - V_30 -> V_98 ) >> 2 ;
V_30 -> V_101 = V_30 -> V_102 ;
V_30 -> V_98 = F_46 ( V_2 ) ;
}
} else {
V_30 -> V_96 = V_82 << 3 ;
V_30 -> V_97 = V_82 << 1 ;
V_30 -> V_98 = V_30 -> V_99 = F_30 ( V_30 -> V_97 , F_46 ( V_2 ) ) ;
V_30 -> V_101 = V_30 -> V_102 ;
}
}
static inline void F_47 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_94 = F_48 ( V_30 ) ;
F_49 ( V_2 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_103 * V_104 = F_51 ( V_2 ) ;
if ( V_105 )
return;
F_52 ( V_104 ) ;
if ( V_104 && ( V_104 -> V_106 & V_107 ) ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_82 ;
unsigned long V_81 ;
if ( V_6 -> V_108 || ! V_30 -> V_96 ) {
if ( ! ( F_53 ( V_104 , V_109 ) ) )
F_54 ( V_104 , V_109 , 0 ) ;
return;
}
V_81 = F_55 ( V_104 , V_109 ) ;
V_82 = V_81 - V_30 -> V_96 ;
if ( ! ( F_53 ( V_104 , V_109 ) ) ) {
if ( V_82 <= 0 )
F_56 ( V_104 , V_109 , V_30 -> V_96 ) ;
else
F_56 ( V_104 , V_109 , V_81 - ( V_82 >> 3 ) ) ;
}
if ( ! ( F_53 ( V_104 , V_110 ) ) ) {
unsigned long V_111 ;
if ( V_82 < 0 )
V_82 = - V_82 ;
V_82 >>= 1 ;
if ( V_82 < V_30 -> V_97 )
V_82 = V_30 -> V_97 ;
V_111 = F_55 ( V_104 , V_110 ) ;
if ( V_82 >= V_111 )
V_111 = V_82 ;
else
V_111 -= ( V_111 - V_82 ) >> 2 ;
F_56 ( V_104 , V_110 , V_111 ) ;
}
if ( F_57 ( V_30 ) ) {
if ( F_58 ( V_104 , V_112 ) &&
! F_53 ( V_104 , V_112 ) &&
( V_30 -> V_113 >> 1 ) > F_58 ( V_104 , V_112 ) )
F_54 ( V_104 , V_112 , V_30 -> V_113 >> 1 ) ;
if ( ! F_53 ( V_104 , V_114 ) &&
V_30 -> V_113 > F_58 ( V_104 , V_114 ) )
F_54 ( V_104 , V_114 , V_30 -> V_113 ) ;
} else if ( V_30 -> V_113 > V_30 -> V_115 &&
V_6 -> V_116 == V_117 ) {
if ( ! F_53 ( V_104 , V_112 ) )
F_54 ( V_104 , V_112 ,
F_30 ( V_30 -> V_113 >> 1 , V_30 -> V_115 ) ) ;
if ( ! F_53 ( V_104 , V_114 ) )
F_54 ( V_104 , V_114 ,
( F_58 ( V_104 , V_114 ) +
V_30 -> V_113 ) >> 1 ) ;
} else {
if ( ! F_53 ( V_104 , V_114 ) )
F_54 ( V_104 , V_114 ,
( F_58 ( V_104 , V_114 ) +
V_30 -> V_115 ) >> 1 ) ;
if ( F_58 ( V_104 , V_112 ) &&
! F_53 ( V_104 , V_112 ) &&
V_30 -> V_115 > F_58 ( V_104 , V_112 ) )
F_54 ( V_104 , V_112 , V_30 -> V_115 ) ;
}
if ( ! F_53 ( V_104 , V_118 ) ) {
if ( F_58 ( V_104 , V_118 ) < V_30 -> V_119 &&
V_30 -> V_119 != V_120 )
F_54 ( V_104 , V_118 , V_30 -> V_119 ) ;
}
}
}
T_2 F_59 ( const struct V_29 * V_30 , const struct V_103 * V_104 )
{
T_2 V_121 = ( V_104 ? F_58 ( V_104 , V_122 ) : 0 ) ;
if ( ! V_121 )
V_121 = V_48 ;
return F_35 ( T_2 , V_121 , V_30 -> V_123 ) ;
}
void F_60 ( struct V_1 * V_2 , const int V_124 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_125 = 0 ;
V_30 -> V_126 = 0 ;
if ( V_6 -> V_116 < V_127 ) {
V_30 -> V_128 = 0 ;
if ( V_124 )
V_30 -> V_115 = V_6 -> V_129 -> V_130 ( V_2 ) ;
V_30 -> V_113 = F_9 ( V_30 -> V_113 ,
F_61 ( V_30 ) + 1U ) ;
V_30 -> V_131 = 0 ;
V_30 -> V_132 = V_30 -> V_102 ;
V_30 -> V_71 = V_72 ;
F_12 ( V_30 ) ;
F_62 ( V_2 , V_127 ) ;
}
}
static void F_63 ( struct V_29 * V_30 )
{
if ( F_64 ( V_30 ) )
V_30 -> V_133 = NULL ;
V_30 -> V_45 . V_134 &= ~ 2 ;
}
static void F_65 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_134 |= 4 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_103 * V_104 = F_51 ( V_2 ) ;
if ( V_104 == NULL )
goto V_135;
F_52 ( V_104 ) ;
if ( F_53 ( V_104 , V_114 ) )
V_30 -> V_123 = F_58 ( V_104 , V_114 ) ;
if ( F_58 ( V_104 , V_112 ) ) {
V_30 -> V_115 = F_58 ( V_104 , V_112 ) ;
if ( V_30 -> V_115 > V_30 -> V_123 )
V_30 -> V_115 = V_30 -> V_123 ;
} else {
V_30 -> V_115 = V_136 ;
}
if ( F_58 ( V_104 , V_118 ) &&
V_30 -> V_119 != F_58 ( V_104 , V_118 ) ) {
F_63 ( V_30 ) ;
V_30 -> V_119 = F_58 ( V_104 , V_118 ) ;
}
if ( F_58 ( V_104 , V_109 ) == 0 || V_30 -> V_96 == 0 )
goto V_135;
if ( F_55 ( V_104 , V_109 ) > V_30 -> V_96 ) {
V_30 -> V_96 = F_55 ( V_104 , V_109 ) ;
V_30 -> V_101 = V_30 -> V_102 ;
}
if ( F_55 ( V_104 , V_110 ) > V_30 -> V_97 ) {
V_30 -> V_97 = F_55 ( V_104 , V_110 ) ;
V_30 -> V_98 = V_30 -> V_99 = F_30 ( V_30 -> V_97 , F_46 ( V_2 ) ) ;
}
F_47 ( V_2 ) ;
V_135:
if ( V_30 -> V_96 == 0 ) {
V_30 -> V_97 = V_30 -> V_98 = V_30 -> V_99 = V_137 ;
F_2 ( V_2 ) -> V_94 = V_137 ;
}
if ( V_30 -> V_138 > 1 )
V_30 -> V_113 = 1 ;
else
V_30 -> V_113 = F_59 ( V_30 , V_104 ) ;
V_30 -> V_71 = V_72 ;
}
static void F_67 ( struct V_1 * V_2 , const int V_139 ,
const int V_140 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_139 > V_30 -> V_119 ) {
int V_141 ;
V_30 -> V_119 = F_9 ( V_142 , V_139 ) ;
if ( V_140 )
V_141 = V_143 ;
else if ( F_68 ( V_30 ) )
V_141 = V_144 ;
else if ( F_64 ( V_30 ) )
V_141 = V_145 ;
else
V_141 = V_146 ;
F_69 ( F_70 ( V_2 ) , V_141 ) ;
#if V_147 > 1
F_71 ( V_148 L_1 ,
V_30 -> V_45 . V_134 , F_2 ( V_2 ) -> V_116 ,
V_30 -> V_119 ,
V_30 -> V_149 ,
V_30 -> V_150 ,
V_30 -> V_128 ? V_30 -> V_151 : 0 ) ;
#endif
F_63 ( V_30 ) ;
}
}
static void F_72 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_152 == NULL ) ||
F_38 ( F_16 ( V_4 ) -> V_85 ,
F_16 ( V_30 -> V_152 ) -> V_85 ) )
V_30 -> V_152 = V_4 ;
if ( ! V_30 -> V_153 ||
F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_154 ) )
V_30 -> V_154 = F_16 ( V_4 ) -> V_88 ;
}
static void F_73 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_155 & ( V_156 | V_157 ) ) ) {
F_72 ( V_30 , V_4 ) ;
V_30 -> V_153 += F_74 ( V_4 ) ;
F_16 ( V_4 ) -> V_155 |= V_156 ;
}
}
static void F_75 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_72 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_155 & ( V_156 | V_157 ) ) ) {
V_30 -> V_153 += F_74 ( V_4 ) ;
F_16 ( V_4 ) -> V_155 |= V_156 ;
}
}
static int F_76 ( struct V_29 * V_30 , int V_158 ,
T_1 V_159 , T_1 V_88 )
{
if ( F_45 ( V_88 , V_30 -> V_102 ) || ! F_38 ( V_159 , V_88 ) )
return 0 ;
if ( ! F_38 ( V_159 , V_30 -> V_102 ) )
return 0 ;
if ( F_45 ( V_159 , V_30 -> V_100 ) )
return 1 ;
if ( ! V_158 || ! V_30 -> V_128 )
return 0 ;
if ( F_45 ( V_88 , V_30 -> V_100 ) )
return 0 ;
if ( ! F_38 ( V_159 , V_30 -> V_128 ) )
return 1 ;
if ( ! F_45 ( V_88 , V_30 -> V_128 ) )
return 0 ;
return ! F_38 ( V_159 , V_88 - V_30 -> V_160 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_161 = 0 ;
T_1 V_162 = V_30 -> V_102 ;
T_1 V_163 = F_78 ( V_30 ) ;
if ( ! F_64 ( V_30 ) || ! V_30 -> V_164 ||
! F_45 ( V_163 , V_30 -> V_165 ) ||
V_6 -> V_116 != V_166 )
return;
F_79 (skb, sk) {
T_1 V_167 = F_16 ( V_4 ) -> V_167 ;
if ( V_4 == F_80 ( V_2 ) )
break;
if ( V_161 == V_30 -> V_164 )
break;
if ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_100 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_155 & V_168 ) )
continue;
if ( F_45 ( V_163 , V_167 ) ) {
F_16 ( V_4 ) -> V_155 &= ~ V_168 ;
V_30 -> V_164 -= F_74 ( V_4 ) ;
F_75 ( V_30 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_169 ) ;
} else {
if ( F_38 ( V_167 , V_162 ) )
V_162 = V_167 ;
V_161 += F_74 ( V_4 ) ;
}
}
if ( V_30 -> V_164 )
V_30 -> V_165 = V_162 ;
}
static int F_81 ( struct V_1 * V_2 , const struct V_3 * V_170 ,
struct V_171 * V_172 , int V_173 ,
T_1 V_174 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_175 = F_82 ( & V_172 [ 0 ] . V_159 ) ;
T_1 V_176 = F_82 ( & V_172 [ 0 ] . V_88 ) ;
int V_177 = 0 ;
if ( F_38 ( V_175 , F_16 ( V_170 ) -> V_167 ) ) {
V_177 = 1 ;
F_65 ( V_30 ) ;
F_69 ( F_70 ( V_2 ) , V_178 ) ;
} else if ( V_173 > 1 ) {
T_1 V_179 = F_82 ( & V_172 [ 1 ] . V_88 ) ;
T_1 V_180 = F_82 ( & V_172 [ 1 ] . V_159 ) ;
if ( ! F_45 ( V_176 , V_179 ) &&
! F_38 ( V_175 , V_180 ) ) {
V_177 = 1 ;
F_65 ( V_30 ) ;
F_69 ( F_70 ( V_2 ) ,
V_181 ) ;
}
}
if ( V_177 && V_30 -> V_128 && V_30 -> V_151 &&
! F_45 ( V_176 , V_174 ) &&
F_45 ( V_176 , V_30 -> V_128 ) )
V_30 -> V_151 -- ;
return V_177 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_159 , T_1 V_88 )
{
int V_182 , V_183 ;
unsigned int V_184 ;
unsigned int V_59 ;
V_182 = ! F_45 ( V_159 , F_16 ( V_4 ) -> V_85 ) &&
! F_38 ( V_88 , F_16 ( V_4 ) -> V_88 ) ;
if ( F_74 ( V_4 ) > 1 && ! V_182 &&
F_45 ( F_16 ( V_4 ) -> V_88 , V_159 ) ) {
V_59 = F_84 ( V_4 ) ;
V_182 = ! F_45 ( V_159 , F_16 ( V_4 ) -> V_85 ) ;
if ( ! V_182 ) {
V_184 = V_159 - F_16 ( V_4 ) -> V_85 ;
if ( V_184 < V_59 )
V_184 = V_59 ;
} else {
V_184 = V_88 - F_16 ( V_4 ) -> V_85 ;
if ( V_184 < V_59 )
return - V_185 ;
}
if ( V_184 > V_59 ) {
unsigned int V_186 = ( V_184 / V_59 ) * V_59 ;
if ( ! V_182 && V_186 < V_184 ) {
V_186 += V_59 ;
if ( V_186 > V_4 -> V_10 )
return 0 ;
}
V_184 = V_186 ;
}
V_183 = F_85 ( V_2 , V_4 , V_184 , V_59 ) ;
if ( V_183 < 0 )
return V_183 ;
}
return V_182 ;
}
static T_3 F_86 ( const struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_187 * V_188 ,
int V_177 , int V_189 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_155 = F_16 ( V_4 ) -> V_155 ;
int V_190 = V_188 -> V_190 ;
if ( V_177 && ( V_155 & V_191 ) ) {
if ( V_30 -> V_128 && V_30 -> V_151 &&
F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_128 ) )
V_30 -> V_151 -- ;
if ( V_155 & V_157 )
V_188 -> V_192 = F_9 ( V_190 , V_188 -> V_192 ) ;
}
if ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_100 ) )
return V_155 ;
if ( ! ( V_155 & V_157 ) ) {
if ( V_155 & V_168 ) {
if ( V_155 & V_156 ) {
V_155 &= ~ ( V_156 | V_168 ) ;
V_30 -> V_153 -= V_189 ;
V_30 -> V_164 -= V_189 ;
}
} else {
if ( ! ( V_155 & V_191 ) ) {
if ( F_38 ( F_16 ( V_4 ) -> V_85 ,
F_78 ( V_30 ) ) )
V_188 -> V_192 = F_9 ( V_190 ,
V_188 -> V_192 ) ;
if ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_193 ) )
V_188 -> V_194 |= V_195 ;
}
if ( V_155 & V_156 ) {
V_155 &= ~ V_156 ;
V_30 -> V_153 -= V_189 ;
}
}
V_155 |= V_157 ;
V_188 -> V_194 |= V_196 ;
V_30 -> V_150 += V_189 ;
V_190 += V_189 ;
if ( ! F_64 ( V_30 ) && ( V_30 -> V_133 != NULL ) &&
F_38 ( F_16 ( V_4 ) -> V_85 ,
F_16 ( V_30 -> V_133 ) -> V_85 ) )
V_30 -> V_197 += V_189 ;
if ( V_190 > V_30 -> V_149 )
V_30 -> V_149 = V_190 ;
}
if ( V_177 && ( V_155 & V_168 ) ) {
V_155 &= ~ V_168 ;
V_30 -> V_164 -= V_189 ;
}
return V_155 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_187 * V_188 ,
unsigned int V_189 , int V_198 , int V_59 ,
int V_177 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_199 = F_88 ( V_2 , V_4 ) ;
F_89 ( ! V_189 ) ;
if ( V_4 == V_30 -> V_133 )
V_30 -> V_197 += V_189 ;
F_16 ( V_199 ) -> V_88 += V_198 ;
F_16 ( V_4 ) -> V_85 += V_198 ;
F_3 ( V_199 ) -> V_200 += V_189 ;
F_89 ( F_3 ( V_4 ) -> V_200 < V_189 ) ;
F_3 ( V_4 ) -> V_200 -= V_189 ;
if ( ! F_3 ( V_199 ) -> V_11 ) {
F_3 ( V_199 ) -> V_11 = V_59 ;
F_3 ( V_199 ) -> V_201 = V_2 -> V_202 ;
}
if ( F_3 ( V_4 ) -> V_200 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_201 = 0 ;
}
F_86 ( V_4 , V_2 , V_188 , V_177 , V_189 ) ;
F_16 ( V_199 ) -> V_155 |= ( F_16 ( V_4 ) -> V_155 & V_203 ) ;
if ( V_4 -> V_10 > 0 ) {
F_89 ( ! F_74 ( V_4 ) ) ;
F_69 ( F_70 ( V_2 ) , V_204 ) ;
return 0 ;
}
if ( V_4 == V_30 -> V_152 )
V_30 -> V_152 = V_199 ;
if ( V_4 == V_30 -> V_205 )
V_30 -> V_205 = V_199 ;
if ( V_4 == V_30 -> V_133 ) {
V_30 -> V_133 = V_199 ;
V_30 -> V_197 -= F_74 ( V_199 ) ;
}
F_16 ( V_4 ) -> V_206 |= F_16 ( V_199 ) -> V_206 ;
if ( V_4 == F_90 ( V_2 ) )
F_91 ( V_2 , V_4 ) ;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_207 ) ;
return 1 ;
}
static int F_94 ( const struct V_3 * V_4 )
{
return F_74 ( V_4 ) == 1 ? V_4 -> V_10 : F_84 ( V_4 ) ;
}
static int F_95 ( const struct V_3 * V_4 )
{
return ! F_96 ( V_4 ) && F_97 ( V_4 ) ;
}
static struct V_3 * F_98 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_187 * V_188 ,
T_1 V_159 , T_1 V_88 ,
int V_177 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_199 ;
int V_59 ;
int V_189 = 0 ;
int V_10 ;
int V_182 ;
if ( ! F_99 ( V_2 ) )
goto V_208;
if ( ! V_177 &&
( F_16 ( V_4 ) -> V_155 & ( V_156 | V_168 ) ) == V_168 )
goto V_208;
if ( ! F_95 ( V_4 ) )
goto V_208;
if ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_100 ) )
goto V_208;
if ( F_100 ( V_4 == F_101 ( V_2 ) ) )
goto V_208;
V_199 = F_88 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_199 ) -> V_155 & V_209 ) != V_157 )
goto V_208;
V_182 = ! F_45 ( V_159 , F_16 ( V_4 ) -> V_85 ) &&
! F_38 ( V_88 , F_16 ( V_4 ) -> V_88 ) ;
if ( V_182 ) {
V_10 = V_4 -> V_10 ;
V_189 = F_74 ( V_4 ) ;
V_59 = F_94 ( V_4 ) ;
if ( V_59 != F_94 ( V_199 ) )
goto V_208;
} else {
if ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_159 ) )
goto V_210;
if ( F_74 ( V_4 ) <= 1 )
goto V_210;
V_182 = ! F_45 ( V_159 , F_16 ( V_4 ) -> V_85 ) ;
if ( ! V_182 ) {
goto V_208;
}
V_10 = V_88 - F_16 ( V_4 ) -> V_85 ;
F_89 ( V_10 < 0 ) ;
F_89 ( V_10 > V_4 -> V_10 ) ;
V_59 = F_84 ( V_4 ) ;
if ( V_59 != F_94 ( V_199 ) )
goto V_208;
if ( V_10 == V_59 ) {
V_189 = 1 ;
} else if ( V_10 < V_59 ) {
goto V_210;
} else {
V_189 = V_10 / V_59 ;
V_10 = V_189 * V_59 ;
}
}
if ( ! F_102 ( V_199 , V_4 , V_10 ) )
goto V_208;
if ( ! F_87 ( V_2 , V_4 , V_188 , V_189 , V_10 , V_59 , V_177 ) )
goto V_211;
if ( V_199 == F_103 ( V_2 ) )
goto V_211;
V_4 = F_104 ( V_2 , V_199 ) ;
if ( ! F_95 ( V_4 ) ||
( V_4 == F_80 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_155 & V_209 ) != V_157 ) ||
( V_59 != F_94 ( V_4 ) ) )
goto V_211;
V_10 = V_4 -> V_10 ;
if ( F_102 ( V_199 , V_4 , V_10 ) ) {
V_189 += F_74 ( V_4 ) ;
F_87 ( V_2 , V_4 , V_188 , F_74 ( V_4 ) , V_10 , V_59 , 0 ) ;
}
V_211:
V_188 -> V_190 += V_189 ;
return V_199 ;
V_210:
return V_4 ;
V_208:
F_69 ( F_70 ( V_2 ) , V_212 ) ;
return NULL ;
}
static struct V_3 * F_105 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_213 * V_214 ,
struct V_187 * V_188 ,
T_1 V_159 , T_1 V_88 ,
int V_215 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_216 ;
F_106 (skb, sk) {
int V_182 = 0 ;
int V_177 = V_215 ;
if ( V_4 == F_80 ( V_2 ) )
break;
if ( ! F_38 ( F_16 ( V_4 ) -> V_85 , V_88 ) )
break;
if ( ( V_214 != NULL ) &&
F_38 ( F_16 ( V_4 ) -> V_85 , V_214 -> V_88 ) ) {
V_182 = F_83 ( V_2 , V_4 ,
V_214 -> V_159 ,
V_214 -> V_88 ) ;
if ( V_182 > 0 )
V_177 = 1 ;
}
if ( V_182 <= 0 ) {
V_216 = F_98 ( V_2 , V_4 , V_188 ,
V_159 , V_88 , V_177 ) ;
if ( V_216 != NULL ) {
if ( V_216 != V_4 ) {
V_4 = V_216 ;
continue;
}
V_182 = 0 ;
} else {
V_182 = F_83 ( V_2 , V_4 ,
V_159 ,
V_88 ) ;
}
}
if ( F_100 ( V_182 < 0 ) )
break;
if ( V_182 ) {
F_16 ( V_4 ) -> V_155 = F_86 ( V_4 , V_2 ,
V_188 ,
V_177 ,
F_74 ( V_4 ) ) ;
if ( ! F_38 ( F_16 ( V_4 ) -> V_85 ,
F_78 ( V_30 ) ) )
F_91 ( V_2 , V_4 ) ;
}
V_188 -> V_190 += F_74 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_187 * V_188 ,
T_1 V_217 )
{
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_45 ( F_16 ( V_4 ) -> V_88 , V_217 ) )
break;
V_188 -> V_190 += F_74 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_108 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_213 * V_214 ,
struct V_187 * V_188 ,
T_1 V_217 )
{
if ( V_214 == NULL )
return V_4 ;
if ( F_38 ( V_214 -> V_159 , V_217 ) ) {
V_4 = F_107 ( V_4 , V_2 , V_188 , V_214 -> V_159 ) ;
V_4 = F_105 ( V_4 , V_2 , NULL , V_188 ,
V_214 -> V_159 , V_214 -> V_88 ,
1 ) ;
}
return V_4 ;
}
static int F_109 ( const struct V_29 * V_30 , const struct V_213 * V_218 )
{
return V_218 < V_30 -> V_219 + F_110 ( V_30 -> V_219 ) ;
}
static int
F_111 ( struct V_1 * V_2 , const struct V_3 * V_170 ,
T_1 V_174 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_220 = ( F_4 ( V_170 ) +
F_16 ( V_170 ) -> V_155 ) ;
struct V_171 * V_221 = (struct V_171 * ) ( V_220 + 2 ) ;
struct V_213 V_172 [ V_222 ] ;
struct V_213 * V_218 ;
struct V_187 V_188 ;
struct V_3 * V_4 ;
int V_173 = F_9 ( V_222 , ( V_220 [ 1 ] - V_223 ) >> 3 ) ;
int V_224 ;
int V_225 = 0 ;
int V_226 , V_227 ;
int V_228 ;
V_188 . V_194 = 0 ;
V_188 . V_192 = V_30 -> V_229 ;
if ( ! V_30 -> V_150 ) {
if ( F_112 ( V_30 -> V_149 ) )
V_30 -> V_149 = 0 ;
F_113 ( V_2 ) ;
}
V_225 = F_81 ( V_2 , V_170 , V_221 ,
V_173 , V_174 ) ;
if ( V_225 )
V_188 . V_194 |= V_230 ;
if ( F_38 ( F_16 ( V_170 ) -> V_167 , V_174 - V_30 -> V_160 ) )
return 0 ;
if ( ! V_30 -> V_229 )
goto V_211;
V_224 = 0 ;
V_228 = 0 ;
for ( V_226 = 0 ; V_226 < V_173 ; V_226 ++ ) {
int V_177 = ! V_226 && V_225 ;
V_172 [ V_224 ] . V_159 = F_82 ( & V_221 [ V_226 ] . V_159 ) ;
V_172 [ V_224 ] . V_88 = F_82 ( & V_221 [ V_226 ] . V_88 ) ;
if ( ! F_76 ( V_30 , V_177 ,
V_172 [ V_224 ] . V_159 ,
V_172 [ V_224 ] . V_88 ) ) {
int V_141 ;
if ( V_177 ) {
if ( ! V_30 -> V_128 )
V_141 = V_231 ;
else
V_141 = V_232 ;
} else {
if ( ( F_16 ( V_170 ) -> V_167 != V_30 -> V_100 ) &&
! F_45 ( V_172 [ V_224 ] . V_88 , V_30 -> V_100 ) )
continue;
V_141 = V_233 ;
}
F_69 ( F_70 ( V_2 ) , V_141 ) ;
if ( V_226 == 0 )
V_228 = - 1 ;
continue;
}
if ( ! F_45 ( V_172 [ V_224 ] . V_88 , V_174 ) )
continue;
V_224 ++ ;
}
for ( V_226 = V_224 - 1 ; V_226 > 0 ; V_226 -- ) {
for ( V_227 = 0 ; V_227 < V_226 ; V_227 ++ ) {
if ( F_45 ( V_172 [ V_227 ] . V_159 , V_172 [ V_227 + 1 ] . V_159 ) ) {
F_114 ( V_172 [ V_227 ] , V_172 [ V_227 + 1 ] ) ;
if ( V_227 == V_228 )
V_228 = V_227 + 1 ;
}
}
}
V_4 = F_101 ( V_2 ) ;
V_188 . V_190 = 0 ;
V_226 = 0 ;
if ( ! V_30 -> V_150 ) {
V_218 = V_30 -> V_219 + F_110 ( V_30 -> V_219 ) ;
} else {
V_218 = V_30 -> V_219 ;
while ( F_109 ( V_30 , V_218 ) && ! V_218 -> V_159 &&
! V_218 -> V_88 )
V_218 ++ ;
}
while ( V_226 < V_224 ) {
T_1 V_159 = V_172 [ V_226 ] . V_159 ;
T_1 V_88 = V_172 [ V_226 ] . V_88 ;
int V_177 = ( V_225 && ( V_226 == V_228 ) ) ;
struct V_213 * V_214 = NULL ;
if ( V_225 && ( ( V_226 + 1 ) == V_228 ) )
V_214 = & V_172 [ V_226 + 1 ] ;
if ( F_45 ( V_88 , V_30 -> V_132 ) )
V_188 . V_194 |= V_234 ;
while ( F_109 ( V_30 , V_218 ) &&
! F_38 ( V_159 , V_218 -> V_88 ) )
V_218 ++ ;
if ( F_109 ( V_30 , V_218 ) && ! V_177 &&
F_45 ( V_88 , V_218 -> V_159 ) ) {
if ( F_38 ( V_159 , V_218 -> V_159 ) ) {
V_4 = F_107 ( V_4 , V_2 , & V_188 ,
V_159 ) ;
V_4 = F_105 ( V_4 , V_2 , V_214 ,
& V_188 ,
V_159 ,
V_218 -> V_159 ,
V_177 ) ;
}
if ( ! F_45 ( V_88 , V_218 -> V_88 ) )
goto V_235;
V_4 = F_108 ( V_4 , V_2 , V_214 ,
& V_188 ,
V_218 -> V_88 ) ;
if ( F_78 ( V_30 ) == V_218 -> V_88 ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_188 . V_190 = V_30 -> V_149 ;
V_218 ++ ;
goto V_236;
}
V_4 = F_107 ( V_4 , V_2 , & V_188 , V_218 -> V_88 ) ;
V_218 ++ ;
continue;
}
if ( ! F_38 ( V_159 , F_78 ( V_30 ) ) ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_188 . V_190 = V_30 -> V_149 ;
}
V_4 = F_107 ( V_4 , V_2 , & V_188 , V_159 ) ;
V_236:
V_4 = F_105 ( V_4 , V_2 , V_214 , & V_188 ,
V_159 , V_88 , V_177 ) ;
V_235:
if ( F_45 ( V_88 , V_30 -> V_193 ) )
V_188 . V_194 &= ~ V_195 ;
V_226 ++ ;
}
for ( V_226 = 0 ; V_226 < F_110 ( V_30 -> V_219 ) - V_224 ; V_226 ++ ) {
V_30 -> V_219 [ V_226 ] . V_159 = 0 ;
V_30 -> V_219 [ V_226 ] . V_88 = 0 ;
}
for ( V_227 = 0 ; V_227 < V_224 ; V_227 ++ )
V_30 -> V_219 [ V_226 ++ ] = V_172 [ V_227 ] ;
F_77 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ( V_188 . V_192 < V_30 -> V_149 ) &&
( ( V_6 -> V_116 != V_237 ) || V_30 -> V_128 ) &&
( ! V_30 -> V_193 || F_45 ( V_30 -> V_100 , V_30 -> V_193 ) ) )
F_67 ( V_2 , V_30 -> V_149 - V_188 . V_192 , 0 ) ;
V_211:
#if V_147 > 0
F_112 ( ( int ) V_30 -> V_150 < 0 ) ;
F_112 ( ( int ) V_30 -> V_153 < 0 ) ;
F_112 ( ( int ) V_30 -> V_164 < 0 ) ;
F_112 ( ( int ) F_61 ( V_30 ) < 0 ) ;
#endif
return V_188 . V_194 ;
}
static int F_116 ( struct V_29 * V_30 )
{
T_1 V_238 ;
V_238 = F_30 ( V_30 -> V_153 , 1U ) ;
V_238 = F_9 ( V_238 , V_30 -> V_229 ) ;
if ( ( V_30 -> V_150 + V_238 ) > V_30 -> V_229 ) {
V_30 -> V_150 = V_30 -> V_229 - V_238 ;
return 1 ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_2 , const int V_239 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_116 ( V_30 ) )
F_67 ( V_2 , V_30 -> V_229 + V_239 , 0 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_150 ++ ;
F_117 ( V_2 , 0 ) ;
F_115 ( V_30 ) ;
}
static void F_119 ( struct V_1 * V_2 , int V_240 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_240 > 0 ) {
if ( V_240 - 1 >= V_30 -> V_150 )
V_30 -> V_150 = 0 ;
else
V_30 -> V_150 -= V_240 - 1 ;
}
F_117 ( V_2 , V_240 ) ;
F_115 ( V_30 ) ;
}
static inline void F_120 ( struct V_29 * V_30 )
{
V_30 -> V_150 = 0 ;
}
static int F_121 ( const struct V_29 * V_30 )
{
return ( V_241 == 0x2 ) && ! F_68 ( V_30 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_241 )
return 0 ;
if ( V_6 -> V_242 . V_243 )
return 0 ;
if ( F_121 ( V_30 ) )
return 1 ;
if ( V_30 -> V_164 > 1 )
return 0 ;
V_4 = F_101 ( V_2 ) ;
if ( F_123 ( V_2 , V_4 ) )
return 1 ;
V_4 = F_104 ( V_2 , V_4 ) ;
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_155 & V_191 )
return 0 ;
if ( ! ( F_16 ( V_4 ) -> V_155 & V_157 ) )
break;
}
return 1 ;
}
void F_124 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ( ! V_30 -> V_244 && V_6 -> V_116 <= V_245 ) ||
V_30 -> V_100 == V_30 -> V_132 ||
( ( V_6 -> V_116 == V_237 || V_30 -> V_244 ) &&
! V_6 -> V_246 ) ) {
V_30 -> V_125 = F_125 ( V_2 ) ;
if ( V_30 -> V_244 ) {
T_1 V_247 ;
V_247 = V_30 -> V_113 ;
V_30 -> V_113 = 2 ;
V_30 -> V_115 = V_6 -> V_129 -> V_130 ( V_2 ) ;
V_30 -> V_113 = V_247 ;
} else {
V_30 -> V_115 = V_6 -> V_129 -> V_130 ( V_2 ) ;
}
F_126 ( V_2 , V_248 ) ;
}
V_30 -> V_128 = V_30 -> V_100 ;
V_30 -> V_151 = 0 ;
V_4 = F_101 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_155 & V_191 )
V_30 -> V_128 = 0 ;
if ( F_16 ( V_4 ) -> V_155 & V_168 ) {
F_16 ( V_4 ) -> V_155 &= ~ V_168 ;
V_30 -> V_164 -= F_74 ( V_4 ) ;
}
F_115 ( V_30 ) ;
V_30 -> V_113 = F_9 ( V_30 -> V_113 , F_61 ( V_30 ) + 1 ) ;
if ( F_121 ( V_30 ) && ( V_30 -> V_244 ||
( ( 1 << V_6 -> V_116 ) & ( V_249 | V_250 ) ) ) &&
F_45 ( V_30 -> V_132 , V_30 -> V_100 ) ) {
V_30 -> V_193 = V_30 -> V_132 ;
} else {
V_30 -> V_193 = V_30 -> V_102 ;
}
F_62 ( V_2 , V_245 ) ;
V_30 -> V_132 = V_30 -> V_102 ;
V_30 -> V_244 = 1 ;
}
static void F_127 ( struct V_1 * V_2 , int V_251 , int V_194 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
V_30 -> V_153 = 0 ;
V_30 -> V_164 = 0 ;
if ( F_68 ( V_30 ) )
F_120 ( V_30 ) ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_155 &= ~ V_156 ;
if ( ( V_30 -> V_244 == 1 ) && ! ( V_194 & V_252 ) ) {
if ( F_16 ( V_4 ) -> V_155 & V_168 )
V_30 -> V_164 += F_74 ( V_4 ) ;
V_194 |= V_252 ;
} else {
if ( F_16 ( V_4 ) -> V_155 & V_191 )
V_30 -> V_128 = 0 ;
F_16 ( V_4 ) -> V_155 &= ~ V_168 ;
}
if ( ! ( F_16 ( V_4 ) -> V_155 & V_157 ) ) {
F_16 ( V_4 ) -> V_155 |= V_156 ;
V_30 -> V_153 += F_74 ( V_4 ) ;
V_30 -> V_154 = F_16 ( V_4 ) -> V_88 ;
}
}
F_115 ( V_30 ) ;
V_30 -> V_113 = F_61 ( V_30 ) + V_251 ;
V_30 -> V_131 = 0 ;
V_30 -> V_71 = V_72 ;
V_30 -> V_244 = 0 ;
V_30 -> V_126 = 0 ;
V_30 -> V_119 = F_35 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_62 ( V_2 , V_237 ) ;
V_30 -> V_132 = V_30 -> V_102 ;
F_12 ( V_30 ) ;
F_128 ( V_30 ) ;
}
static void F_129 ( struct V_29 * V_30 )
{
V_30 -> V_164 = 0 ;
V_30 -> V_153 = 0 ;
V_30 -> V_128 = 0 ;
V_30 -> V_151 = 0 ;
}
void F_130 ( struct V_29 * V_30 )
{
F_129 ( V_30 ) ;
V_30 -> V_149 = 0 ;
V_30 -> V_150 = 0 ;
}
void F_131 ( struct V_1 * V_2 , int V_253 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_6 -> V_116 <= V_245 || V_30 -> V_100 == V_30 -> V_132 ||
( V_6 -> V_116 == V_237 && ! V_6 -> V_246 ) ) {
V_30 -> V_125 = F_125 ( V_2 ) ;
V_30 -> V_115 = V_6 -> V_129 -> V_130 ( V_2 ) ;
F_126 ( V_2 , V_254 ) ;
}
V_30 -> V_113 = 1 ;
V_30 -> V_131 = 0 ;
V_30 -> V_71 = V_72 ;
V_30 -> V_126 = 0 ;
F_129 ( V_30 ) ;
if ( F_68 ( V_30 ) )
F_120 ( V_30 ) ;
if ( ! V_253 ) {
V_30 -> V_128 = V_30 -> V_100 ;
} else {
V_30 -> V_150 = 0 ;
V_30 -> V_149 = 0 ;
}
F_128 ( V_30 ) ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_155 & V_191 )
V_30 -> V_128 = 0 ;
F_16 ( V_4 ) -> V_155 &= ( ~ V_209 ) | V_157 ;
if ( ! ( F_16 ( V_4 ) -> V_155 & V_157 ) || V_253 ) {
F_16 ( V_4 ) -> V_155 &= ~ V_157 ;
F_16 ( V_4 ) -> V_155 |= V_156 ;
V_30 -> V_153 += F_74 ( V_4 ) ;
V_30 -> V_154 = F_16 ( V_4 ) -> V_88 ;
}
}
F_115 ( V_30 ) ;
V_30 -> V_119 = F_35 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_62 ( V_2 , V_237 ) ;
V_30 -> V_132 = V_30 -> V_102 ;
F_12 ( V_30 ) ;
V_30 -> V_244 = 0 ;
}
static int F_132 ( struct V_1 * V_2 , int V_194 )
{
if ( V_194 & V_255 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_256 ) ;
F_131 ( V_2 , 1 ) ;
V_6 -> V_246 ++ ;
F_133 ( V_2 , F_101 ( V_2 ) ) ;
F_134 ( V_2 , V_257 ,
V_6 -> V_94 , V_258 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_135 ( const struct V_29 * V_30 )
{
return F_68 ( V_30 ) ? V_30 -> V_150 + 1 : V_30 -> V_149 ;
}
static inline int F_136 ( const struct V_29 * V_30 )
{
return F_64 ( V_30 ) ? V_30 -> V_149 : V_30 -> V_150 + 1 ;
}
static inline int F_137 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_72 - F_16 ( V_4 ) -> V_259 > F_2 ( V_2 ) -> V_94 ;
}
static inline int F_138 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_229 &&
F_137 ( V_2 , F_101 ( V_2 ) ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_229 ;
if ( V_30 -> V_244 )
return 0 ;
if ( V_30 -> V_153 )
return 1 ;
if ( F_136 ( V_30 ) > V_30 -> V_119 )
return 1 ;
if ( F_64 ( V_30 ) && F_138 ( V_2 ) )
return 1 ;
V_229 = V_30 -> V_229 ;
if ( V_229 <= V_30 -> V_119 &&
V_30 -> V_150 >= F_27 ( T_2 , V_229 / 2 , V_120 ) &&
! F_140 ( V_2 ) ) {
return 1 ;
}
if ( ( V_30 -> V_260 || V_261 ) &&
F_141 ( V_30 ) && F_136 ( V_30 ) > 1 &&
F_142 ( V_30 ) && ! F_80 ( V_2 ) )
return 1 ;
return 0 ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_64 ( V_30 ) || ! F_138 ( V_2 ) )
return;
V_4 = V_30 -> V_205 ;
if ( V_30 -> V_205 == NULL )
V_4 = F_101 ( V_2 ) ;
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( ! F_137 ( V_2 , V_4 ) )
break;
F_73 ( V_30 , V_4 ) ;
}
V_30 -> V_205 = V_4 ;
F_115 ( V_30 ) ;
}
static void F_144 ( struct V_1 * V_2 , int V_262 , int V_263 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_161 , V_264 ;
int V_183 ;
unsigned int V_59 ;
F_112 ( V_262 > V_30 -> V_229 ) ;
if ( V_30 -> V_133 ) {
V_4 = V_30 -> V_133 ;
V_161 = V_30 -> V_197 ;
if ( V_263 && V_4 != F_101 ( V_2 ) )
return;
} else {
V_4 = F_101 ( V_2 ) ;
V_161 = 0 ;
}
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
V_30 -> V_133 = V_4 ;
V_30 -> V_197 = V_161 ;
if ( F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_132 ) )
break;
V_264 = V_161 ;
if ( F_64 ( V_30 ) || F_68 ( V_30 ) ||
( F_16 ( V_4 ) -> V_155 & V_157 ) )
V_161 += F_74 ( V_4 ) ;
if ( V_161 > V_262 ) {
if ( ( F_142 ( V_30 ) && ! F_64 ( V_30 ) ) ||
( V_264 >= V_262 ) )
break;
V_59 = F_3 ( V_4 ) -> V_11 ;
V_183 = F_85 ( V_2 , V_4 , ( V_262 - V_264 ) * V_59 , V_59 ) ;
if ( V_183 < 0 )
break;
V_161 = V_262 ;
}
F_73 ( V_30 , V_4 ) ;
if ( V_263 )
break;
}
F_115 ( V_30 ) ;
}
static void F_145 ( struct V_1 * V_2 , int V_265 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_68 ( V_30 ) ) {
F_144 ( V_2 , 1 , 1 ) ;
} else if ( F_64 ( V_30 ) ) {
int V_266 = V_30 -> V_149 - V_30 -> V_119 ;
if ( V_266 <= 0 )
V_266 = 1 ;
F_144 ( V_2 , V_266 , 0 ) ;
} else {
int V_267 = V_30 -> V_150 - V_30 -> V_119 ;
if ( V_267 >= 0 )
F_144 ( V_2 , V_267 , 0 ) ;
else if ( V_265 )
F_144 ( V_2 , 1 , 1 ) ;
}
F_143 ( V_2 ) ;
}
static inline void F_146 ( struct V_29 * V_30 )
{
V_30 -> V_113 = F_9 ( V_30 -> V_113 ,
F_61 ( V_30 ) + F_147 ( V_30 ) ) ;
V_30 -> V_71 = V_72 ;
}
static inline T_1 F_148 ( const struct V_1 * V_2 )
{
const struct V_268 * V_269 = F_2 ( V_2 ) -> V_129 ;
return V_269 -> V_270 ? V_269 -> V_270 ( V_2 ) : F_7 ( V_2 ) -> V_115 ;
}
static void F_149 ( struct V_1 * V_2 , int V_194 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_271 = V_30 -> V_131 + 1 ;
if ( ( V_194 & ( V_272 | V_230 ) ) ||
( F_68 ( V_30 ) && ! ( V_194 & V_273 ) ) ) {
V_30 -> V_131 = V_271 & 1 ;
V_271 >>= 1 ;
if ( V_271 && V_30 -> V_113 > F_148 ( V_2 ) )
V_30 -> V_113 -= V_271 ;
V_30 -> V_113 = F_9 ( V_30 -> V_113 , F_61 ( V_30 ) + 1 ) ;
V_30 -> V_71 = V_72 ;
}
}
static inline int F_150 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_274 ||
( V_30 -> V_45 . V_275 && V_30 -> V_45 . V_87 &&
F_38 ( V_30 -> V_45 . V_87 , V_30 -> V_274 ) ) ;
}
static void F_151 ( struct V_1 * V_2 , const char * V_276 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_277 * V_278 = F_152 ( V_2 ) ;
if ( V_2 -> V_279 == V_280 ) {
F_71 ( V_148 L_2 ,
V_276 ,
& V_278 -> V_281 , F_153 ( V_278 -> V_282 ) ,
V_30 -> V_113 , F_154 ( V_30 ) ,
V_30 -> V_115 , V_30 -> V_125 ,
V_30 -> V_229 ) ;
}
#if F_155 ( V_283 ) || F_155 ( V_284 )
else if ( V_2 -> V_279 == V_285 ) {
struct V_286 * V_287 = F_156 ( V_2 ) ;
F_71 ( V_148 L_3 ,
V_276 ,
& V_287 -> V_288 , F_153 ( V_278 -> V_282 ) ,
V_30 -> V_113 , F_154 ( V_30 ) ,
V_30 -> V_115 , V_30 -> V_125 ,
V_30 -> V_229 ) ;
}
#endif
}
static void F_157 ( struct V_1 * V_2 , const bool V_289 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_125 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_129 -> V_290 )
V_30 -> V_113 = V_6 -> V_129 -> V_290 ( V_2 ) ;
else
V_30 -> V_113 = F_30 ( V_30 -> V_113 , V_30 -> V_115 << 1 ) ;
if ( V_289 && V_30 -> V_125 > V_30 -> V_115 ) {
V_30 -> V_115 = V_30 -> V_125 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_113 = F_30 ( V_30 -> V_113 , V_30 -> V_115 ) ;
}
V_30 -> V_71 = V_72 ;
}
static inline int F_158 ( const struct V_29 * V_30 )
{
return V_30 -> V_128 && ( ! V_30 -> V_151 || F_150 ( V_30 ) ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_158 ( V_30 ) ) {
int V_141 ;
F_151 ( V_2 , F_2 ( V_2 ) -> V_116 == V_237 ? L_4 : L_5 ) ;
F_157 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_116 == V_237 )
V_141 = V_291 ;
else
V_141 = V_292 ;
F_69 ( F_70 ( V_2 ) , V_141 ) ;
V_30 -> V_128 = 0 ;
}
if ( V_30 -> V_100 == V_30 -> V_132 && F_68 ( V_30 ) ) {
F_146 ( V_30 ) ;
return 1 ;
}
F_62 ( V_2 , V_117 ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_128 && ! V_30 -> V_151 ) {
F_151 ( V_2 , L_6 ) ;
F_157 ( V_2 , true ) ;
V_30 -> V_128 = 0 ;
F_69 ( F_70 ( V_2 ) , V_293 ) ;
}
}
static int F_161 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_164 )
return 1 ;
V_4 = F_101 ( V_2 ) ;
if ( F_100 ( V_4 && F_16 ( V_4 ) -> V_155 & V_203 ) )
return 1 ;
return 0 ;
}
static int F_162 ( struct V_1 * V_2 , int V_240 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_294 = F_68 ( V_30 ) || ( F_135 ( V_30 ) > V_30 -> V_119 ) ;
if ( F_158 ( V_30 ) ) {
if ( ! F_161 ( V_2 ) )
V_30 -> V_274 = 0 ;
F_67 ( V_2 , F_135 ( V_30 ) + V_240 , 1 ) ;
F_151 ( V_2 , L_7 ) ;
F_157 ( V_2 , false ) ;
F_69 ( F_70 ( V_2 ) , V_295 ) ;
V_294 = 0 ;
}
return V_294 ;
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_158 ( V_30 ) ) {
struct V_3 * V_4 ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_155 &= ~ V_156 ;
}
F_128 ( V_30 ) ;
F_151 ( V_2 , L_8 ) ;
V_30 -> V_153 = 0 ;
F_157 ( V_2 , true ) ;
F_69 ( F_70 ( V_2 ) , V_291 ) ;
F_2 ( V_2 ) -> V_246 = 0 ;
V_30 -> V_128 = 0 ;
if ( F_142 ( V_30 ) )
F_62 ( V_2 , V_117 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_128 ) {
if ( F_2 ( V_2 ) -> V_116 == V_127 )
V_30 -> V_113 = F_9 ( V_30 -> V_113 , V_30 -> V_115 ) ;
else
V_30 -> V_113 = V_30 -> V_115 ;
V_30 -> V_71 = V_72 ;
}
F_126 ( V_2 , V_296 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_188 = V_117 ;
if ( F_154 ( V_30 ) || F_161 ( V_2 ) || V_30 -> V_128 )
V_188 = V_245 ;
if ( F_2 ( V_2 ) -> V_116 != V_188 ) {
F_62 ( V_2 , V_188 ) ;
V_30 -> V_132 = V_30 -> V_102 ;
}
}
static void F_166 ( struct V_1 * V_2 , int V_194 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ! V_30 -> V_244 && ! F_161 ( V_2 ) )
V_30 -> V_274 = 0 ;
if ( V_194 & V_297 )
F_60 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_116 != V_127 ) {
F_165 ( V_2 ) ;
F_146 ( V_30 ) ;
} else {
F_149 ( V_2 , V_194 ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_242 . V_298 = V_6 -> V_242 . V_243 - 1 ;
V_6 -> V_242 . V_243 = 0 ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_125 = F_125 ( V_2 ) ;
V_30 -> V_113 = V_30 -> V_113 *
F_169 ( V_2 , V_30 -> V_299 ) /
V_6 -> V_242 . V_243 ;
V_30 -> V_131 = 0 ;
V_30 -> V_71 = V_72 ;
V_30 -> V_115 = F_125 ( V_2 ) ;
V_6 -> V_242 . V_300 = V_6 -> V_242 . V_243 ;
V_6 -> V_242 . V_243 = 0 ;
F_170 ( V_2 , V_6 -> V_301 ) ;
}
void F_171 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_59 = F_172 ( V_2 ) ;
T_1 V_302 = V_30 -> V_153 ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_94 ( V_4 ) > V_59 &&
! ( F_16 ( V_4 ) -> V_155 & V_157 ) ) {
if ( F_16 ( V_4 ) -> V_155 & V_168 ) {
F_16 ( V_4 ) -> V_155 &= ~ V_168 ;
V_30 -> V_164 -= F_74 ( V_4 ) ;
}
F_75 ( V_30 , V_4 ) ;
}
}
F_173 ( V_30 ) ;
if ( V_302 == V_30 -> V_153 )
return;
if ( F_68 ( V_30 ) )
F_116 ( V_30 ) ;
F_115 ( V_30 ) ;
if ( V_6 -> V_116 != V_237 ) {
V_30 -> V_132 = V_30 -> V_102 ;
V_30 -> V_115 = F_125 ( V_2 ) ;
V_30 -> V_125 = 0 ;
V_30 -> V_128 = 0 ;
F_62 ( V_2 , V_237 ) ;
}
F_174 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 , int V_303 ,
int V_265 , int V_194 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_304 = 0 ;
int V_305 = V_30 -> V_115 - F_61 ( V_30 ) ;
if ( F_61 ( V_30 ) > V_30 -> V_115 ) {
T_4 V_306 = ( T_4 ) V_30 -> V_115 * V_30 -> V_307 +
V_30 -> V_308 - 1 ;
V_304 = F_176 ( V_306 , V_30 -> V_308 ) - V_30 -> V_309 ;
} else {
V_304 = F_35 ( int , V_305 ,
F_27 ( int , V_30 -> V_307 - V_30 -> V_309 ,
V_303 ) + 1 ) ;
}
V_304 = F_30 ( V_304 , ( V_265 ? 1 : 0 ) ) ;
V_30 -> V_113 = F_61 ( V_30 ) + V_304 ;
}
static void F_177 ( struct V_1 * V_2 , int V_310 ,
int V_303 , int V_194 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_311 = ! ( V_194 & ( V_312 | V_273 ) ) ;
int V_313 = V_311 || ( ( V_194 & V_196 ) &&
( F_135 ( V_30 ) > V_30 -> V_119 ) ) ;
int V_265 = 0 , V_141 ;
if ( F_112 ( ! V_30 -> V_229 && V_30 -> V_150 ) )
V_30 -> V_150 = 0 ;
if ( F_112 ( ! V_30 -> V_150 && V_30 -> V_149 ) )
V_30 -> V_149 = 0 ;
if ( V_194 & V_297 )
V_30 -> V_125 = 0 ;
if ( F_132 ( V_2 , V_194 ) )
return;
if ( F_64 ( V_30 ) && ( V_194 & V_234 ) &&
F_38 ( V_30 -> V_100 , V_30 -> V_132 ) &&
V_6 -> V_116 != V_117 &&
V_30 -> V_149 > V_30 -> V_119 ) {
F_144 ( V_2 , V_30 -> V_149 - V_30 -> V_119 , 0 ) ;
F_69 ( F_70 ( V_2 ) , V_314 ) ;
}
F_115 ( V_30 ) ;
if ( V_6 -> V_116 == V_117 ) {
F_112 ( V_30 -> V_164 != 0 ) ;
V_30 -> V_274 = 0 ;
} else if ( ! F_38 ( V_30 -> V_100 , V_30 -> V_132 ) ) {
switch ( V_6 -> V_116 ) {
case V_237 :
V_6 -> V_246 = 0 ;
if ( F_159 ( V_2 ) )
return;
break;
case V_127 :
if ( V_30 -> V_100 != V_30 -> V_132 ) {
F_164 ( V_2 ) ;
F_62 ( V_2 , V_117 ) ;
}
break;
case V_245 :
F_160 ( V_2 ) ;
if ( ! V_30 -> V_128 ||
F_68 ( V_30 ) || V_30 -> V_100 != V_30 -> V_132 ) {
V_30 -> V_128 = 0 ;
F_62 ( V_2 , V_117 ) ;
}
break;
case V_166 :
if ( F_68 ( V_30 ) )
F_120 ( V_30 ) ;
if ( F_159 ( V_2 ) )
return;
F_164 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_116 ) {
case V_166 :
if ( ! ( V_194 & V_312 ) ) {
if ( F_68 ( V_30 ) && V_311 )
F_118 ( V_2 ) ;
} else
V_313 = F_162 ( V_2 , V_310 ) ;
break;
case V_237 :
if ( V_194 & V_252 )
V_6 -> V_246 = 0 ;
if ( F_68 ( V_30 ) && V_194 & V_312 )
F_120 ( V_30 ) ;
if ( ! F_163 ( V_2 ) ) {
F_146 ( V_30 ) ;
F_174 ( V_2 ) ;
return;
}
if ( V_6 -> V_116 != V_117 )
return;
default:
if ( F_68 ( V_30 ) ) {
if ( V_194 & V_312 )
F_120 ( V_30 ) ;
if ( V_311 )
F_118 ( V_2 ) ;
}
if ( V_6 -> V_116 == V_245 )
F_160 ( V_2 ) ;
if ( ! F_139 ( V_2 ) ) {
F_166 ( V_2 , V_194 ) ;
return;
}
if ( V_6 -> V_116 < V_127 &&
V_6 -> V_242 . V_243 &&
V_30 -> V_100 == V_30 -> V_315 . V_316 ) {
F_167 ( V_2 ) ;
V_30 -> V_113 ++ ;
F_171 ( V_2 ) ;
return;
}
if ( F_68 ( V_30 ) )
V_141 = V_317 ;
else
V_141 = V_318 ;
F_69 ( F_70 ( V_2 ) , V_141 ) ;
V_30 -> V_132 = V_30 -> V_102 ;
V_30 -> V_125 = 0 ;
V_30 -> V_128 = V_30 -> V_100 ;
V_30 -> V_151 = V_30 -> V_164 ;
if ( V_6 -> V_116 < V_127 ) {
if ( ! ( V_194 & V_297 ) )
V_30 -> V_125 = F_125 ( V_2 ) ;
V_30 -> V_115 = V_6 -> V_129 -> V_130 ( V_2 ) ;
F_12 ( V_30 ) ;
}
V_30 -> V_126 = 0 ;
V_30 -> V_131 = 0 ;
V_30 -> V_308 = V_30 -> V_113 ;
V_30 -> V_307 = 0 ;
V_30 -> V_309 = 0 ;
F_62 ( V_2 , V_166 ) ;
V_265 = 1 ;
}
if ( V_313 || ( F_64 ( V_30 ) && F_138 ( V_2 ) ) )
F_145 ( V_2 , V_265 ) ;
V_30 -> V_307 += V_303 ;
F_175 ( V_2 , V_303 , V_265 , V_194 ) ;
F_174 ( V_2 ) ;
}
void F_178 ( struct V_1 * V_2 , T_1 V_319 )
{
F_44 ( V_2 , V_319 ) ;
F_47 ( V_2 ) ;
F_2 ( V_2 ) -> V_108 = 0 ;
}
static void F_179 ( struct V_1 * V_2 , int V_194 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_178 ( V_2 , V_72 - V_30 -> V_45 . V_87 ) ;
}
static void F_180 ( struct V_1 * V_2 , T_1 V_319 , int V_194 )
{
if ( V_194 & V_320 )
return;
F_178 ( V_2 , V_319 ) ;
}
static inline void F_181 ( struct V_1 * V_2 , const int V_194 ,
const T_5 V_319 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_275 && V_30 -> V_45 . V_87 )
F_179 ( V_2 , V_194 ) ;
else if ( V_319 >= 0 )
F_180 ( V_2 , V_319 , V_194 ) ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_321 , T_1 V_322 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_129 -> V_323 ( V_2 , V_321 , V_322 ) ;
F_7 ( V_2 ) -> V_71 = V_72 ;
}
static void F_183 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_229 ) {
F_184 ( V_2 , V_257 ) ;
} else {
F_134 ( V_2 , V_257 ,
F_2 ( V_2 ) -> V_94 , V_258 ) ;
}
}
static T_1 F_185 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_324 ;
F_89 ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_100 ) ) ;
V_324 = F_74 ( V_4 ) ;
if ( F_186 ( V_2 , V_4 , V_30 -> V_100 - F_16 ( V_4 ) -> V_85 ) )
return 0 ;
V_324 -= F_74 ( V_4 ) ;
if ( V_324 ) {
F_89 ( F_74 ( V_4 ) == 0 ) ;
F_89 ( ! F_38 ( F_16 ( V_4 ) -> V_85 , F_16 ( V_4 ) -> V_88 ) ) ;
}
return V_324 ;
}
static int F_187 ( struct V_1 * V_2 , int V_325 ,
T_1 V_174 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_92 = V_72 ;
int V_326 = 1 ;
int V_194 = 0 ;
T_1 V_310 = 0 ;
T_1 V_192 = V_30 -> V_229 ;
T_1 V_327 = V_30 -> V_150 ;
T_5 V_319 = - 1 ;
T_5 V_328 = - 1 ;
T_6 V_329 = F_188 () ;
while ( ( V_4 = F_101 ( V_2 ) ) && V_4 != F_80 ( V_2 ) ) {
struct V_330 * V_331 = F_16 ( V_4 ) ;
T_1 V_332 ;
T_3 V_155 = V_331 -> V_155 ;
if ( F_45 ( V_331 -> V_88 , V_30 -> V_100 ) ) {
if ( F_74 ( V_4 ) == 1 ||
! F_45 ( V_30 -> V_100 , V_331 -> V_85 ) )
break;
V_332 = F_185 ( V_2 , V_4 ) ;
if ( ! V_332 )
break;
V_326 = 0 ;
} else {
V_332 = F_74 ( V_4 ) ;
}
if ( V_155 & V_191 ) {
if ( V_155 & V_168 )
V_30 -> V_164 -= V_332 ;
V_194 |= V_320 ;
V_328 = - 1 ;
V_319 = - 1 ;
if ( ( V_194 & V_252 ) || ( V_332 > 1 ) )
V_194 |= V_333 ;
} else {
V_328 = V_92 - V_331 -> V_259 ;
V_329 = V_4 -> V_334 ;
if ( V_319 < 0 ) {
V_319 = V_328 ;
}
if ( ! ( V_155 & V_157 ) )
V_192 = F_9 ( V_310 , V_192 ) ;
}
if ( V_155 & V_157 )
V_30 -> V_150 -= V_332 ;
if ( V_155 & V_156 )
V_30 -> V_153 -= V_332 ;
V_30 -> V_229 -= V_332 ;
V_310 += V_332 ;
if ( ! ( V_331 -> V_206 & V_335 ) ) {
V_194 |= V_252 ;
} else {
V_194 |= V_336 ;
V_30 -> V_274 = 0 ;
}
if ( ! V_326 )
break;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
V_30 -> V_205 = NULL ;
if ( V_4 == V_30 -> V_152 )
V_30 -> V_152 = NULL ;
if ( V_4 == V_30 -> V_133 )
V_30 -> V_133 = NULL ;
}
if ( F_189 ( F_190 ( V_30 -> V_337 , V_174 , V_30 -> V_100 ) ) )
V_30 -> V_337 = V_30 -> V_100 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_155 & V_157 ) )
V_194 |= V_255 ;
if ( V_194 & V_338 ) {
const struct V_268 * V_269
= F_2 ( V_2 ) -> V_129 ;
if ( F_100 ( V_6 -> V_242 . V_243 &&
! F_45 ( V_30 -> V_315 . V_339 , V_30 -> V_100 ) ) ) {
F_168 ( V_2 ) ;
}
F_181 ( V_2 , V_194 , V_319 ) ;
F_183 ( V_2 ) ;
if ( F_68 ( V_30 ) ) {
F_119 ( V_2 , V_310 ) ;
} else {
int V_305 ;
if ( V_192 < V_325 )
F_67 ( V_2 , V_30 -> V_149 - V_192 , 0 ) ;
V_305 = F_64 ( V_30 ) ? V_310 :
V_327 - V_30 -> V_150 ;
V_30 -> V_197 -= F_9 ( V_30 -> V_197 , V_305 ) ;
}
V_30 -> V_149 -= F_9 ( V_310 , V_30 -> V_149 ) ;
if ( V_269 -> V_310 ) {
T_5 V_340 = - 1 ;
if ( ! ( V_194 & V_320 ) ) {
if ( V_269 -> V_106 & V_341 &&
! F_191 ( V_329 ,
F_188 () ) )
V_340 = F_192 ( F_193 () ,
V_329 ) ;
else if ( V_328 >= 0 )
V_340 = F_194 ( V_328 ) ;
}
V_269 -> V_310 ( V_2 , V_310 , V_340 ) ;
}
}
#if V_147 > 0
F_112 ( ( int ) V_30 -> V_150 < 0 ) ;
F_112 ( ( int ) V_30 -> V_153 < 0 ) ;
F_112 ( ( int ) V_30 -> V_164 < 0 ) ;
if ( ! V_30 -> V_229 && F_142 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_153 ) {
F_71 ( V_148 L_9 ,
V_30 -> V_153 , V_6 -> V_116 ) ;
V_30 -> V_153 = 0 ;
}
if ( V_30 -> V_150 ) {
F_71 ( V_148 L_10 ,
V_30 -> V_150 , V_6 -> V_116 ) ;
V_30 -> V_150 = 0 ;
}
if ( V_30 -> V_164 ) {
F_71 ( V_148 L_11 ,
V_30 -> V_164 , V_6 -> V_116 ) ;
V_30 -> V_164 = 0 ;
}
}
#endif
return V_194 ;
}
static void F_195 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_45 ( F_16 ( F_80 ( V_2 ) ) -> V_88 , F_196 ( V_30 ) ) ) {
V_6 -> V_108 = 0 ;
F_184 ( V_2 , V_342 ) ;
} else {
F_134 ( V_2 , V_342 ,
F_9 ( V_6 -> V_94 << V_6 -> V_108 , V_258 ) ,
V_258 ) ;
}
}
static inline int F_197 ( const struct V_1 * V_2 , const int V_194 )
{
return ! ( V_194 & V_273 ) || ( V_194 & V_343 ) ||
F_2 ( V_2 ) -> V_116 != V_117 ;
}
static inline int F_198 ( const struct V_1 * V_2 , const int V_194 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_194 & V_297 ) || V_30 -> V_113 < V_30 -> V_115 ) &&
! ( ( 1 << F_2 ( V_2 ) -> V_116 ) & ( V_249 | V_344 ) ) ;
}
static inline int F_199 ( const struct V_29 * V_30 ,
const T_1 V_321 , const T_1 V_167 ,
const T_1 V_345 )
{
return F_45 ( V_321 , V_30 -> V_100 ) ||
F_45 ( V_167 , V_30 -> V_346 ) ||
( V_167 == V_30 -> V_346 && V_345 > V_30 -> V_347 ) ;
}
static int F_200 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_321 ,
T_1 V_167 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_194 = 0 ;
T_1 V_345 = F_153 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_189 ( ! F_6 ( V_4 ) -> V_43 ) )
V_345 <<= V_30 -> V_45 . V_348 ;
if ( F_199 ( V_30 , V_321 , V_167 , V_345 ) ) {
V_194 |= V_349 ;
F_201 ( V_30 , V_167 ) ;
if ( V_30 -> V_347 != V_345 ) {
V_30 -> V_347 = V_345 ;
V_30 -> V_350 = 0 ;
F_202 ( V_2 ) ;
if ( V_345 > V_30 -> V_160 ) {
V_30 -> V_160 = V_345 ;
F_170 ( V_2 , F_2 ( V_2 ) -> V_301 ) ;
}
}
}
V_30 -> V_100 = V_321 ;
return V_194 ;
}
static void F_203 ( struct V_29 * V_30 )
{
V_30 -> V_113 = F_9 ( V_30 -> V_113 , V_30 -> V_115 ) ;
V_30 -> V_131 = 0 ;
V_30 -> V_126 = 0 ;
F_12 ( V_30 ) ;
F_146 ( V_30 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
F_60 ( V_2 , 0 ) ;
}
static void F_205 ( struct V_1 * V_2 , int V_194 )
{
if ( V_194 & V_297 )
F_204 ( V_2 ) ;
else
F_157 ( V_2 , true ) ;
}
static int F_206 ( struct V_1 * V_2 , int V_194 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( V_194 & V_252 )
F_2 ( V_2 ) -> V_246 = 0 ;
if ( ( V_194 & V_333 ) ||
( ( V_30 -> V_244 >= 2 ) && ( V_194 & V_320 ) ) )
V_30 -> V_128 = 0 ;
if ( ! F_38 ( V_30 -> V_100 , V_30 -> V_193 ) ) {
F_127 ( V_2 , ( V_30 -> V_244 == 1 ? 2 : 3 ) , V_194 ) ;
return 1 ;
}
if ( ! F_121 ( V_30 ) ) {
if ( ! ( V_194 & V_272 ) && ( V_194 & V_273 ) )
return 1 ;
if ( ! ( V_194 & V_252 ) ) {
F_127 ( V_2 , ( V_30 -> V_244 == 1 ? 0 : 3 ) ,
V_194 ) ;
return 1 ;
}
} else {
if ( ! ( V_194 & V_252 ) && ( V_30 -> V_244 == 1 ) ) {
V_30 -> V_113 = F_9 ( V_30 -> V_113 ,
F_61 ( V_30 ) ) ;
return 1 ;
}
if ( ( V_30 -> V_244 >= 2 ) &&
( ! ( V_194 & V_351 ) ||
( ( V_194 & V_196 ) &&
! ( V_194 & V_195 ) ) ) ) {
if ( ! ( V_194 & V_351 ) &&
( V_194 & V_273 ) )
return 1 ;
F_127 ( V_2 , 3 , V_194 ) ;
return 1 ;
}
}
if ( V_30 -> V_244 == 1 ) {
V_30 -> V_113 = F_61 ( V_30 ) + 2 ;
V_30 -> V_244 = 2 ;
if ( ! F_140 ( V_2 ) )
F_127 ( V_2 , 2 , V_194 ) ;
return 1 ;
} else {
switch ( V_352 ) {
case 2 :
F_205 ( V_2 , V_194 ) ;
break;
case 1 :
F_203 ( V_30 ) ;
break;
default:
F_204 ( V_2 ) ;
break;
}
V_30 -> V_244 = 0 ;
V_30 -> V_128 = 0 ;
F_69 ( F_70 ( V_2 ) , V_353 ) ;
}
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_194 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_174 = V_30 -> V_100 ;
T_1 V_167 = F_16 ( V_4 ) -> V_85 ;
T_1 V_321 = F_16 ( V_4 ) -> V_167 ;
T_1 V_354 ;
T_1 V_325 ;
int V_355 ;
int V_327 = V_30 -> V_150 ;
int V_303 = 0 ;
int V_356 = 0 ;
if ( F_38 ( V_321 , V_174 ) )
goto V_357;
if ( F_45 ( V_321 , V_30 -> V_102 ) )
goto V_358;
if ( F_45 ( V_321 , V_174 ) )
V_194 |= V_312 ;
if ( V_359 ) {
if ( V_6 -> V_116 < V_127 )
V_30 -> V_126 += V_321 - V_174 ;
else if ( V_6 -> V_116 == V_237 )
V_30 -> V_126 += F_9 ( V_321 - V_174 ,
V_30 -> V_299 ) ;
}
V_325 = V_30 -> V_149 ;
V_354 = F_61 ( V_30 ) ;
if ( ! ( V_194 & V_360 ) && F_45 ( V_321 , V_174 ) ) {
F_201 ( V_30 , V_167 ) ;
V_30 -> V_100 = V_321 ;
V_194 |= V_349 ;
F_126 ( V_2 , V_361 ) ;
F_69 ( F_70 ( V_2 ) , V_362 ) ;
} else {
if ( V_167 != F_16 ( V_4 ) -> V_88 )
V_194 |= V_363 ;
else
F_69 ( F_70 ( V_2 ) , V_364 ) ;
V_194 |= F_200 ( V_2 , V_4 , V_321 , V_167 ) ;
if ( F_16 ( V_4 ) -> V_155 )
V_194 |= F_111 ( V_2 , V_4 , V_174 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_194 |= V_297 ;
F_126 ( V_2 , V_365 ) ;
}
V_2 -> V_366 = 0 ;
V_6 -> V_367 = 0 ;
V_30 -> V_368 = V_72 ;
V_355 = V_30 -> V_229 ;
if ( ! V_355 )
goto V_369;
V_194 |= F_187 ( V_2 , V_325 , V_174 ) ;
V_303 = ( V_355 - V_327 ) -
( V_30 -> V_229 - V_30 -> V_150 ) ;
if ( V_30 -> V_244 )
V_356 = F_206 ( V_2 , V_194 ) ;
if ( F_38 ( V_30 -> V_193 , V_30 -> V_100 ) )
V_30 -> V_193 = 0 ;
if ( F_197 ( V_2 , V_194 ) ) {
if ( ( V_194 & V_252 ) && ! V_356 &&
F_198 ( V_2 , V_194 ) )
F_182 ( V_2 , V_321 , V_354 ) ;
F_177 ( V_2 , V_355 - V_30 -> V_229 ,
V_303 , V_194 ) ;
} else {
if ( ( V_194 & V_252 ) && ! V_356 )
F_182 ( V_2 , V_321 , V_354 ) ;
}
if ( ( V_194 & V_351 ) || ! ( V_194 & V_273 ) )
F_52 ( F_51 ( V_2 ) ) ;
return 1 ;
V_369:
if ( F_80 ( V_2 ) )
F_195 ( V_2 ) ;
return 1 ;
V_358:
F_208 ( V_2 , L_12 , V_321 , V_30 -> V_100 , V_30 -> V_102 ) ;
return - 1 ;
V_357:
if ( F_16 ( V_4 ) -> V_155 ) {
F_111 ( V_2 , V_4 , V_174 ) ;
if ( V_6 -> V_116 == V_117 )
F_165 ( V_2 ) ;
}
F_208 ( V_2 , L_13 , V_321 , V_30 -> V_100 , V_30 -> V_102 ) ;
return 0 ;
}
void F_209 ( const struct V_3 * V_4 , struct V_370 * V_371 ,
const T_3 * * V_372 , int V_373 )
{
const unsigned char * V_220 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_374 = ( V_41 -> V_375 * 4 ) - sizeof( struct V_15 ) ;
V_220 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_371 -> V_275 = 0 ;
while ( V_374 > 0 ) {
int V_376 = * V_220 ++ ;
int V_377 ;
switch ( V_376 ) {
case V_378 :
return;
case V_379 :
V_374 -- ;
continue;
default:
V_377 = * V_220 ++ ;
if ( V_377 < 2 )
return;
if ( V_377 > V_374 )
return;
switch ( V_376 ) {
case V_380 :
if ( V_377 == V_381 && V_41 -> V_43 && ! V_373 ) {
T_7 V_382 = F_210 ( V_220 ) ;
if ( V_382 ) {
if ( V_371 -> V_383 &&
V_371 -> V_383 < V_382 )
V_382 = V_371 -> V_383 ;
V_371 -> V_46 = V_382 ;
}
}
break;
case V_384 :
if ( V_377 == V_385 && V_41 -> V_43 &&
! V_373 && V_386 ) {
T_8 V_348 = * ( T_8 * ) V_220 ;
V_371 -> V_387 = 1 ;
if ( V_348 > 14 ) {
if ( F_211 () )
F_71 ( V_388 L_14
L_15 ,
V_348 ) ;
V_348 = 14 ;
}
V_371 -> V_348 = V_348 ;
}
break;
case V_389 :
if ( ( V_377 == V_390 ) &&
( ( V_373 && V_371 -> V_391 ) ||
( ! V_373 && V_392 ) ) ) {
V_371 -> V_275 = 1 ;
V_371 -> V_393 = F_82 ( V_220 ) ;
V_371 -> V_87 = F_82 ( V_220 + 4 ) ;
}
break;
case V_394 :
if ( V_377 == V_395 && V_41 -> V_43 &&
! V_373 && V_396 ) {
V_371 -> V_134 = 1 ;
F_212 ( V_371 ) ;
}
break;
case V_397 :
if ( ( V_377 >= ( V_223 + V_398 ) ) &&
! ( ( V_377 - V_223 ) % V_398 ) &&
V_371 -> V_134 ) {
F_16 ( V_4 ) -> V_155 = ( V_220 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_213
case V_399 :
break;
#endif
case V_400 :
switch ( V_377 ) {
case V_401 :
break;
case V_402 :
break;
case V_403 + 0 :
case V_403 + 2 :
case V_403 + 4 :
case V_403 + 6 :
case V_404 :
V_371 -> V_405 = V_377 ;
* V_372 = V_220 ;
break;
default:
break;
}
break;
}
V_220 += V_377 - 2 ;
V_374 -= V_377 ;
}
}
}
static int F_214 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_220 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_220 == F_215 ( ( V_379 << 24 ) | ( V_379 << 16 )
| ( V_389 << 8 ) | V_390 ) ) {
V_30 -> V_45 . V_275 = 1 ;
++ V_220 ;
V_30 -> V_45 . V_393 = F_216 ( * V_220 ) ;
++ V_220 ;
V_30 -> V_45 . V_87 = F_216 ( * V_220 ) ;
return 1 ;
}
return 0 ;
}
static int F_217 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 ,
struct V_29 * V_30 , const T_3 * * V_372 )
{
if ( V_41 -> V_375 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_275 = 0 ;
return 0 ;
} else if ( V_30 -> V_45 . V_391 &&
V_41 -> V_375 == ( ( sizeof( * V_41 ) + V_406 ) / 4 ) ) {
if ( F_214 ( V_30 , V_41 ) )
return 1 ;
}
F_209 ( V_4 , & V_30 -> V_45 , V_372 , 1 ) ;
return 1 ;
}
const T_3 * F_218 ( const struct V_15 * V_41 )
{
int V_374 = ( V_41 -> V_375 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_220 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_374 < V_407 )
return NULL ;
while ( V_374 > 0 ) {
int V_376 = * V_220 ++ ;
int V_377 ;
switch( V_376 ) {
case V_378 :
return NULL ;
case V_379 :
V_374 -- ;
continue;
default:
V_377 = * V_220 ++ ;
if ( V_377 < 2 || V_377 > V_374 )
return NULL ;
if ( V_376 == V_399 )
return V_377 == V_407 ? V_220 : NULL ;
}
V_220 += V_377 - 2 ;
V_374 -= V_377 ;
}
return NULL ;
}
static inline void F_219 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_408 = V_30 -> V_45 . V_393 ;
V_30 -> V_45 . V_409 = F_220 () ;
}
static inline void F_221 ( struct V_29 * V_30 , T_1 V_85 )
{
if ( V_30 -> V_45 . V_275 && ! F_45 ( V_85 , V_30 -> V_410 ) ) {
if ( F_222 ( & V_30 -> V_45 , 0 ) )
F_219 ( V_30 ) ;
}
}
static int F_223 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_85 = F_16 ( V_4 ) -> V_85 ;
T_1 V_321 = F_16 ( V_4 ) -> V_167 ;
return (
( V_41 -> V_321 && V_85 == F_16 ( V_4 ) -> V_88 && V_85 == V_30 -> V_84 ) &&
V_321 == V_30 -> V_100 &&
! F_199 ( V_30 , V_321 , V_85 , F_153 ( V_41 -> V_52 ) << V_30 -> V_45 . V_348 ) &&
( T_5 ) ( V_30 -> V_45 . V_408 - V_30 -> V_45 . V_393 ) <= ( F_2 ( V_2 ) -> V_94 * 1024 ) / V_411 ) ;
}
static inline int F_224 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_222 ( & V_30 -> V_45 , V_412 ) &&
! F_223 ( V_2 , V_4 ) ;
}
static inline int F_225 ( const struct V_29 * V_30 , T_1 V_85 , T_1 V_88 )
{
return ! F_38 ( V_88 , V_30 -> V_410 ) &&
! F_45 ( V_85 , V_30 -> V_84 + F_226 ( V_30 ) ) ;
}
static void F_227 ( struct V_1 * V_2 )
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
F_42 ( V_2 ) ;
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
F_71 ( V_433 L_16 ,
V_434 , V_2 -> V_413 ) ;
break;
}
F_236 ( & V_30 -> V_435 ) ;
if ( F_142 ( V_30 ) )
F_212 ( & V_30 -> V_45 ) ;
F_43 ( V_2 ) ;
if ( ! F_229 ( V_2 , V_421 ) ) {
V_2 -> V_436 ( V_2 ) ;
if ( V_2 -> V_423 == V_437 ||
V_2 -> V_413 == V_419 )
F_237 ( V_2 , V_438 , V_439 ) ;
else
F_237 ( V_2 , V_438 , V_440 ) ;
}
}
static inline int F_238 ( struct V_213 * V_172 , T_1 V_85 ,
T_1 V_88 )
{
if ( ! F_45 ( V_85 , V_172 -> V_88 ) && ! F_45 ( V_172 -> V_159 , V_88 ) ) {
if ( F_38 ( V_85 , V_172 -> V_159 ) )
V_172 -> V_159 = V_85 ;
if ( F_45 ( V_88 , V_172 -> V_88 ) )
V_172 -> V_88 = V_88 ;
return 1 ;
}
return 0 ;
}
static void F_239 ( struct V_1 * V_2 , T_1 V_85 , T_1 V_88 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_142 ( V_30 ) && V_441 ) {
int V_141 ;
if ( F_38 ( V_85 , V_30 -> V_84 ) )
V_141 = V_442 ;
else
V_141 = V_443 ;
F_69 ( F_70 ( V_2 ) , V_141 ) ;
V_30 -> V_45 . V_444 = 1 ;
V_30 -> V_445 [ 0 ] . V_159 = V_85 ;
V_30 -> V_445 [ 0 ] . V_88 = V_88 ;
}
}
static void F_240 ( struct V_1 * V_2 , T_1 V_85 , T_1 V_88 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_444 )
F_239 ( V_2 , V_85 , V_88 ) ;
else
F_238 ( V_30 -> V_445 , V_85 , V_88 ) ;
}
static void F_241 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_88 != F_16 ( V_4 ) -> V_85 &&
F_38 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_84 ) ) {
F_69 ( F_70 ( V_2 ) , V_446 ) ;
F_10 ( V_2 ) ;
if ( F_142 ( V_30 ) && V_441 ) {
T_1 V_88 = F_16 ( V_4 ) -> V_88 ;
if ( F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_84 ) )
V_88 = V_30 -> V_84 ;
F_239 ( V_2 , F_16 ( V_4 ) -> V_85 , V_88 ) ;
}
}
F_234 ( V_2 ) ;
}
static void F_242 ( struct V_29 * V_30 )
{
int V_447 ;
struct V_213 * V_172 = & V_30 -> V_448 [ 0 ] ;
struct V_213 * V_449 = V_172 + 1 ;
for ( V_447 = 1 ; V_447 < V_30 -> V_45 . V_173 ; ) {
if ( F_238 ( V_172 , V_449 -> V_159 , V_449 -> V_88 ) ) {
int V_226 ;
V_30 -> V_45 . V_173 -- ;
for ( V_226 = V_447 ; V_226 < V_30 -> V_45 . V_173 ; V_226 ++ )
V_172 [ V_226 ] = V_172 [ V_226 + 1 ] ;
continue;
}
V_447 ++ , V_449 ++ ;
}
}
static void F_243 ( struct V_1 * V_2 , T_1 V_85 , T_1 V_88 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_213 * V_172 = & V_30 -> V_448 [ 0 ] ;
int V_450 = V_30 -> V_45 . V_173 ;
int V_447 ;
if ( ! V_450 )
goto V_451;
for ( V_447 = 0 ; V_447 < V_450 ; V_447 ++ , V_172 ++ ) {
if ( F_238 ( V_172 , V_85 , V_88 ) ) {
for (; V_447 > 0 ; V_447 -- , V_172 -- )
F_114 ( * V_172 , * ( V_172 - 1 ) ) ;
if ( V_450 > 1 )
F_242 ( V_30 ) ;
return;
}
}
if ( V_447 >= V_222 ) {
V_447 -- ;
V_30 -> V_45 . V_173 -- ;
V_172 -- ;
}
for (; V_447 > 0 ; V_447 -- , V_172 -- )
* V_172 = * ( V_172 - 1 ) ;
V_451:
V_172 -> V_159 = V_85 ;
V_172 -> V_88 = V_88 ;
V_30 -> V_45 . V_173 ++ ;
}
static void F_244 ( struct V_29 * V_30 )
{
struct V_213 * V_172 = & V_30 -> V_448 [ 0 ] ;
int V_173 = V_30 -> V_45 . V_173 ;
int V_447 ;
if ( F_245 ( & V_30 -> V_435 ) ) {
V_30 -> V_45 . V_173 = 0 ;
return;
}
for ( V_447 = 0 ; V_447 < V_173 ; ) {
if ( ! F_38 ( V_30 -> V_84 , V_172 -> V_159 ) ) {
int V_226 ;
F_112 ( F_38 ( V_30 -> V_84 , V_172 -> V_88 ) ) ;
for ( V_226 = V_447 + 1 ; V_226 < V_173 ; V_226 ++ )
V_30 -> V_448 [ V_226 - 1 ] = V_30 -> V_448 [ V_226 ] ;
V_173 -- ;
continue;
}
V_447 ++ ;
V_172 ++ ;
}
V_30 -> V_45 . V_173 = V_173 ;
}
static void F_246 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_452 = V_30 -> V_84 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_247 ( & V_30 -> V_435 ) ) != NULL ) {
if ( F_45 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_84 ) )
break;
if ( F_38 ( F_16 ( V_4 ) -> V_85 , V_452 ) ) {
T_2 V_444 = V_452 ;
if ( F_38 ( F_16 ( V_4 ) -> V_88 , V_452 ) )
V_452 = F_16 ( V_4 ) -> V_88 ;
F_240 ( V_2 , F_16 ( V_4 ) -> V_85 , V_444 ) ;
}
if ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_84 ) ) {
F_208 ( V_2 , L_17 ) ;
F_248 ( V_4 , & V_30 -> V_435 ) ;
F_249 ( V_4 ) ;
continue;
}
F_208 ( V_2 , L_18 ,
V_30 -> V_84 , F_16 ( V_4 ) -> V_85 ,
F_16 ( V_4 ) -> V_88 ) ;
F_248 ( V_4 , & V_30 -> V_435 ) ;
F_250 ( & V_2 -> V_453 , V_4 ) ;
V_30 -> V_84 = F_16 ( V_4 ) -> V_88 ;
if ( F_6 ( V_4 ) -> V_454 )
F_231 ( V_2 ) ;
}
}
static inline int F_251 ( struct V_1 * V_2 , unsigned int V_455 )
{
if ( F_33 ( & V_2 -> V_75 ) > V_2 -> V_63 ||
! F_252 ( V_2 , V_455 ) ) {
if ( F_253 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_252 ( V_2 , V_455 ) ) {
if ( ! F_254 ( V_2 ) )
return - 1 ;
if ( ! F_252 ( V_2 , V_455 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_255 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_456 = - 1 ;
if ( F_16 ( V_4 ) -> V_85 == F_16 ( V_4 ) -> V_88 )
goto V_457;
F_256 ( V_4 ) ;
F_257 ( V_4 , V_41 -> V_375 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_444 = 0 ;
if ( F_16 ( V_4 ) -> V_85 == V_30 -> V_84 ) {
if ( F_226 ( V_30 ) == 0 )
goto V_458;
if ( V_30 -> V_459 . V_460 == V_461 &&
V_30 -> V_89 == V_30 -> V_84 && V_30 -> V_459 . V_10 &&
F_258 ( V_2 ) && ! V_30 -> V_462 ) {
int V_463 = F_35 (unsigned int, skb->len,
tp->ucopy.len) ;
F_259 ( V_464 ) ;
F_260 () ;
if ( ! F_261 ( V_4 , 0 , V_30 -> V_459 . V_465 , V_463 ) ) {
V_30 -> V_459 . V_10 -= V_463 ;
V_30 -> V_89 += V_463 ;
V_456 = ( V_463 == V_4 -> V_10 ) ;
F_40 ( V_2 ) ;
}
F_262 () ;
}
if ( V_456 <= 0 ) {
V_466:
if ( V_456 < 0 &&
F_251 ( V_2 , V_4 -> V_51 ) )
goto V_457;
F_263 ( V_4 , V_2 ) ;
F_250 ( & V_2 -> V_453 , V_4 ) ;
}
V_30 -> V_84 = F_16 ( V_4 ) -> V_88 ;
if ( V_4 -> V_10 )
F_41 ( V_2 , V_4 ) ;
if ( V_41 -> V_454 )
F_231 ( V_2 ) ;
if ( ! F_245 ( & V_30 -> V_435 ) ) {
F_246 ( V_2 ) ;
if ( F_245 ( & V_30 -> V_435 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_173 )
F_244 ( V_30 ) ;
F_202 ( V_2 ) ;
if ( V_456 > 0 )
F_249 ( V_4 ) ;
else if ( ! F_229 ( V_2 , V_421 ) )
V_2 -> V_467 ( V_2 , 0 ) ;
return;
}
if ( ! F_45 ( F_16 ( V_4 ) -> V_88 , V_30 -> V_84 ) ) {
F_69 ( F_70 ( V_2 ) , V_446 ) ;
F_239 ( V_2 , F_16 ( V_4 ) -> V_85 , F_16 ( V_4 ) -> V_88 ) ;
V_458:
F_10 ( V_2 ) ;
F_42 ( V_2 ) ;
V_457:
F_249 ( V_4 ) ;
return;
}
if ( ! F_38 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_84 + F_226 ( V_30 ) ) )
goto V_458;
F_10 ( V_2 ) ;
if ( F_38 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_84 ) ) {
F_208 ( V_2 , L_19 ,
V_30 -> V_84 , F_16 ( V_4 ) -> V_85 ,
F_16 ( V_4 ) -> V_88 ) ;
F_239 ( V_2 , F_16 ( V_4 ) -> V_85 , V_30 -> V_84 ) ;
if ( ! F_226 ( V_30 ) )
goto V_458;
goto V_466;
}
F_15 ( V_30 , V_4 ) ;
if ( F_251 ( V_2 , V_4 -> V_51 ) )
goto V_457;
V_30 -> V_350 = 0 ;
F_42 ( V_2 ) ;
F_208 ( V_2 , L_20 ,
V_30 -> V_84 , F_16 ( V_4 ) -> V_85 , F_16 ( V_4 ) -> V_88 ) ;
F_263 ( V_4 , V_2 ) ;
if ( ! F_247 ( & V_30 -> V_435 ) ) {
if ( F_142 ( V_30 ) ) {
V_30 -> V_45 . V_173 = 1 ;
V_30 -> V_448 [ 0 ] . V_159 = F_16 ( V_4 ) -> V_85 ;
V_30 -> V_448 [ 0 ] . V_88 =
F_16 ( V_4 ) -> V_88 ;
}
F_264 ( & V_30 -> V_435 , V_4 ) ;
} else {
struct V_3 * V_468 = F_265 ( & V_30 -> V_435 ) ;
T_1 V_85 = F_16 ( V_4 ) -> V_85 ;
T_1 V_88 = F_16 ( V_4 ) -> V_88 ;
if ( V_85 == F_16 ( V_468 ) -> V_88 ) {
F_266 ( & V_30 -> V_435 , V_468 , V_4 ) ;
if ( ! V_30 -> V_45 . V_173 ||
V_30 -> V_448 [ 0 ] . V_88 != V_85 )
goto V_469;
V_30 -> V_448 [ 0 ] . V_88 = V_88 ;
return;
}
while ( 1 ) {
if ( ! F_45 ( F_16 ( V_468 ) -> V_85 , V_85 ) )
break;
if ( F_267 ( & V_30 -> V_435 , V_468 ) ) {
V_468 = NULL ;
break;
}
V_468 = F_268 ( & V_30 -> V_435 , V_468 ) ;
}
if ( V_468 && F_38 ( V_85 , F_16 ( V_468 ) -> V_88 ) ) {
if ( ! F_45 ( V_88 , F_16 ( V_468 ) -> V_88 ) ) {
F_249 ( V_4 ) ;
F_239 ( V_2 , V_85 , V_88 ) ;
goto V_469;
}
if ( F_45 ( V_85 , F_16 ( V_468 ) -> V_85 ) ) {
F_239 ( V_2 , V_85 ,
F_16 ( V_468 ) -> V_88 ) ;
} else {
if ( F_267 ( & V_30 -> V_435 ,
V_468 ) )
V_468 = NULL ;
else
V_468 = F_268 (
& V_30 -> V_435 ,
V_468 ) ;
}
}
if ( ! V_468 )
F_264 ( & V_30 -> V_435 , V_4 ) ;
else
F_266 ( & V_30 -> V_435 , V_468 , V_4 ) ;
while ( ! F_269 ( & V_30 -> V_435 , V_4 ) ) {
V_468 = F_270 ( & V_30 -> V_435 , V_4 ) ;
if ( ! F_45 ( V_88 , F_16 ( V_468 ) -> V_85 ) )
break;
if ( F_38 ( V_88 , F_16 ( V_468 ) -> V_88 ) ) {
F_240 ( V_2 , F_16 ( V_468 ) -> V_85 ,
V_88 ) ;
break;
}
F_248 ( V_468 , & V_30 -> V_435 ) ;
F_240 ( V_2 , F_16 ( V_468 ) -> V_85 ,
F_16 ( V_468 ) -> V_88 ) ;
F_249 ( V_468 ) ;
}
V_469:
if ( F_142 ( V_30 ) )
F_243 ( V_2 , V_85 , V_88 ) ;
}
}
static struct V_3 * F_271 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_470 * V_471 )
{
struct V_3 * V_472 = NULL ;
if ( ! F_269 ( V_471 , V_4 ) )
V_472 = F_270 ( V_471 , V_4 ) ;
F_248 ( V_4 , V_471 ) ;
F_249 ( V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_473 ) ;
return V_472 ;
}
static void
F_272 ( struct V_1 * V_2 , struct V_470 * V_471 ,
struct V_3 * V_474 , struct V_3 * V_475 ,
T_1 V_476 , T_1 V_477 )
{
struct V_3 * V_4 , * V_478 ;
bool V_479 ;
V_4 = V_474 ;
V_480:
V_479 = true ;
F_273 (list, skb, n) {
if ( V_4 == V_475 )
break;
if ( ! F_38 ( V_476 , F_16 ( V_4 ) -> V_88 ) ) {
V_4 = F_271 ( V_2 , V_4 , V_471 ) ;
if ( ! V_4 )
break;
goto V_480;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_454 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_38 ( F_16 ( V_4 ) -> V_85 , V_476 ) ) ) {
V_479 = false ;
break;
}
if ( ! F_269 ( V_471 , V_4 ) ) {
struct V_3 * V_472 = F_270 ( V_471 , V_4 ) ;
if ( V_472 != V_475 &&
F_16 ( V_4 ) -> V_88 != F_16 ( V_472 ) -> V_85 ) {
V_479 = false ;
break;
}
}
V_476 = F_16 ( V_4 ) -> V_88 ;
}
if ( V_479 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_454 )
return;
while ( F_38 ( V_476 , V_477 ) ) {
struct V_3 * V_481 ;
unsigned int V_482 = F_274 ( V_4 ) ;
int V_483 = F_275 ( V_482 , 0 ) ;
if ( V_483 < 0 )
return;
if ( V_477 - V_476 < V_483 )
V_483 = V_477 - V_476 ;
V_481 = F_276 ( V_483 + V_482 , V_484 ) ;
if ( ! V_481 )
return;
F_277 ( V_481 , F_278 ( V_4 ) - V_4 -> V_474 ) ;
F_279 ( V_481 , ( F_280 ( V_4 ) -
V_4 -> V_474 ) ) ;
F_281 ( V_481 , ( F_4 ( V_4 ) -
V_4 -> V_474 ) ) ;
F_282 ( V_481 , V_482 ) ;
memcpy ( V_481 -> V_474 , V_4 -> V_474 , V_482 ) ;
memcpy ( V_481 -> V_485 , V_4 -> V_485 , sizeof( V_4 -> V_485 ) ) ;
F_16 ( V_481 ) -> V_85 = F_16 ( V_481 ) -> V_88 = V_476 ;
F_283 ( V_471 , V_4 , V_481 ) ;
F_263 ( V_481 , V_2 ) ;
while ( V_483 > 0 ) {
int V_486 = V_476 - F_16 ( V_4 ) -> V_85 ;
int V_455 = F_16 ( V_4 ) -> V_88 - V_476 ;
F_89 ( V_486 < 0 ) ;
if ( V_455 > 0 ) {
V_455 = F_9 ( V_483 , V_455 ) ;
if ( F_284 ( V_4 , V_486 , F_285 ( V_481 , V_455 ) , V_455 ) )
F_286 () ;
F_16 ( V_481 ) -> V_88 += V_455 ;
V_483 -= V_455 ;
V_476 += V_455 ;
}
if ( ! F_38 ( V_476 , F_16 ( V_4 ) -> V_88 ) ) {
V_4 = F_271 ( V_2 , V_4 , V_471 ) ;
if ( ! V_4 ||
V_4 == V_475 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_454 )
return;
}
}
}
}
static void F_287 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_247 ( & V_30 -> V_435 ) ;
struct V_3 * V_474 ;
T_1 V_476 , V_477 ;
if ( V_4 == NULL )
return;
V_476 = F_16 ( V_4 ) -> V_85 ;
V_477 = F_16 ( V_4 ) -> V_88 ;
V_474 = V_4 ;
for (; ; ) {
struct V_3 * V_472 = NULL ;
if ( ! F_269 ( & V_30 -> V_435 , V_4 ) )
V_472 = F_270 ( & V_30 -> V_435 , V_4 ) ;
V_4 = V_472 ;
if ( ! V_4 ||
F_45 ( F_16 ( V_4 ) -> V_85 , V_477 ) ||
F_38 ( F_16 ( V_4 ) -> V_88 , V_476 ) ) {
F_272 ( V_2 , & V_30 -> V_435 ,
V_474 , V_4 , V_476 , V_477 ) ;
V_474 = V_4 ;
if ( ! V_4 )
break;
V_476 = F_16 ( V_4 ) -> V_85 ;
V_477 = F_16 ( V_4 ) -> V_88 ;
} else {
if ( F_38 ( F_16 ( V_4 ) -> V_85 , V_476 ) )
V_476 = F_16 ( V_4 ) -> V_85 ;
if ( F_45 ( F_16 ( V_4 ) -> V_88 , V_477 ) )
V_477 = F_16 ( V_4 ) -> V_88 ;
}
}
}
static int F_254 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_487 = 0 ;
if ( ! F_245 ( & V_30 -> V_435 ) ) {
F_69 ( F_70 ( V_2 ) , V_488 ) ;
F_236 ( & V_30 -> V_435 ) ;
if ( V_30 -> V_45 . V_134 )
F_212 ( & V_30 -> V_45 ) ;
F_43 ( V_2 ) ;
V_487 = 1 ;
}
return V_487 ;
}
static int F_253 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_208 ( V_2 , L_21 , V_30 -> V_89 ) ;
F_69 ( F_70 ( V_2 ) , V_489 ) ;
if ( F_33 ( & V_2 -> V_75 ) >= V_2 -> V_63 )
F_31 ( V_2 ) ;
else if ( V_56 )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_58 ) ;
F_287 ( V_2 ) ;
if ( ! F_245 ( & V_2 -> V_453 ) )
F_272 ( V_2 , & V_2 -> V_453 ,
F_247 ( & V_2 -> V_453 ) ,
NULL ,
V_30 -> V_89 , V_30 -> V_84 ) ;
F_43 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_75 ) <= V_2 -> V_63 )
return 0 ;
F_254 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_75 ) <= V_2 -> V_63 )
return 0 ;
F_69 ( F_70 ( V_2 ) , V_490 ) ;
V_30 -> V_350 = 0 ;
return - 1 ;
}
void F_288 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_116 == V_117 &&
V_2 -> V_491 && ! F_289 ( V_492 , & V_2 -> V_491 -> V_106 ) ) {
T_1 V_493 = F_59 ( V_30 , F_51 ( V_2 ) ) ;
T_1 V_494 = F_30 ( V_30 -> V_495 , V_493 ) ;
if ( V_494 < V_30 -> V_113 ) {
V_30 -> V_115 = F_125 ( V_2 ) ;
V_30 -> V_113 = ( V_30 -> V_113 + V_494 ) >> 1 ;
}
V_30 -> V_495 = 0 ;
}
V_30 -> V_71 = V_72 ;
}
static int F_290 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_65 & V_67 )
return 0 ;
if ( V_56 )
return 0 ;
if ( F_32 ( & V_73 ) >= V_74 [ 0 ] )
return 0 ;
if ( V_30 -> V_229 >= V_30 -> V_113 )
return 0 ;
return 1 ;
}
static void F_291 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_290 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_299 ) +
V_47 ) ;
int V_496 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_496 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_71 = V_72 ;
}
V_2 -> V_497 ( V_2 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
if ( F_229 ( V_2 , V_498 ) ) {
F_293 ( V_2 , V_498 ) ;
if ( V_2 -> V_491 &&
F_289 ( V_492 , & V_2 -> V_491 -> V_106 ) )
F_291 ( V_2 ) ;
}
}
static inline void F_294 ( struct V_1 * V_2 )
{
F_295 ( V_2 ) ;
F_292 ( V_2 ) ;
}
static void F_296 ( struct V_1 * V_2 , int V_499 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_84 - V_30 -> V_410 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_297 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_499 && F_247 ( & V_30 -> V_435 ) ) ) {
F_234 ( V_2 ) ;
} else {
F_298 ( V_2 ) ;
}
}
static inline void F_299 ( struct V_1 * V_2 )
{
if ( ! F_300 ( V_2 ) ) {
return;
}
F_296 ( V_2 , 1 ) ;
}
static void F_301 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_220 = F_153 ( V_41 -> V_500 ) ;
if ( V_220 && ! V_501 )
V_220 -- ;
V_220 += F_216 ( V_41 -> V_85 ) ;
if ( F_45 ( V_30 -> V_89 , V_220 ) )
return;
if ( F_38 ( V_220 , V_30 -> V_84 ) )
return;
if ( V_30 -> V_462 && ! F_45 ( V_220 , V_30 -> V_502 ) )
return;
F_302 ( V_2 ) ;
if ( V_30 -> V_502 == V_30 -> V_89 && V_30 -> V_462 &&
! F_229 ( V_2 , V_503 ) && V_30 -> V_89 != V_30 -> V_84 ) {
struct V_3 * V_4 = F_247 ( & V_2 -> V_453 ) ;
V_30 -> V_89 ++ ;
if ( V_4 && ! F_38 ( V_30 -> V_89 , F_16 ( V_4 ) -> V_88 ) ) {
F_248 ( V_4 , & V_2 -> V_453 ) ;
F_249 ( V_4 ) ;
}
}
V_30 -> V_462 = V_504 ;
V_30 -> V_502 = V_220 ;
V_30 -> V_350 = 0 ;
}
static void F_303 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_505 )
F_301 ( V_2 , V_41 ) ;
if ( V_30 -> V_462 == V_504 ) {
T_1 V_220 = V_30 -> V_502 - F_216 ( V_41 -> V_85 ) + ( V_41 -> V_375 * 4 ) -
V_41 -> V_43 ;
if ( V_220 < V_4 -> V_10 ) {
T_3 V_216 ;
if ( F_284 ( V_4 , V_220 , & V_216 , 1 ) )
F_286 () ;
V_30 -> V_462 = V_506 | V_216 ;
if ( ! F_229 ( V_2 , V_421 ) )
V_2 -> V_467 ( V_2 , 0 ) ;
}
}
}
static int F_304 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_507 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_463 = V_4 -> V_10 - V_507 ;
int V_183 ;
F_260 () ;
if ( F_305 ( V_4 ) )
V_183 = F_261 ( V_4 , V_507 , V_30 -> V_459 . V_465 , V_463 ) ;
else
V_183 = F_306 ( V_4 , V_507 ,
V_30 -> V_459 . V_465 ) ;
if ( ! V_183 ) {
V_30 -> V_459 . V_10 -= V_463 ;
V_30 -> V_89 += V_463 ;
F_40 ( V_2 ) ;
}
F_262 () ;
return V_183 ;
}
static T_10 F_307 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_10 V_508 ;
if ( F_258 ( V_2 ) ) {
F_260 () ;
V_508 = F_308 ( V_4 ) ;
F_262 () ;
} else {
V_508 = F_308 ( V_4 ) ;
}
return V_508 ;
}
static inline int F_309 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_305 ( V_4 ) &&
F_307 ( V_2 , V_4 ) ;
}
static int F_310 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_507 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_463 = V_4 -> V_10 - V_507 ;
int V_509 ;
int V_510 = 0 ;
if ( V_30 -> V_459 . V_511 )
return 0 ;
if ( ! V_30 -> V_459 . V_512 && V_30 -> V_459 . V_513 )
V_30 -> V_459 . V_512 = F_311 ( V_514 ) ;
if ( V_30 -> V_459 . V_512 && F_305 ( V_4 ) ) {
V_509 = F_312 ( V_30 -> V_459 . V_512 ,
V_4 , V_507 ,
V_30 -> V_459 . V_465 , V_463 ,
V_30 -> V_459 . V_513 ) ;
if ( V_509 < 0 )
goto V_211;
V_30 -> V_459 . V_509 = V_509 ;
V_510 = 1 ;
V_30 -> V_459 . V_10 -= V_463 ;
V_30 -> V_89 += V_463 ;
F_40 ( V_2 ) ;
if ( ( V_30 -> V_459 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_515 ) ||
( F_33 ( & V_2 -> V_75 ) > ( V_2 -> V_63 >> 1 ) ) ) {
V_30 -> V_459 . V_511 = 1 ;
V_2 -> V_467 ( V_2 , 0 ) ;
}
} else if ( V_463 > 0 ) {
V_30 -> V_459 . V_511 = 1 ;
V_2 -> V_467 ( V_2 , 0 ) ;
}
V_211:
return V_510 ;
}
static int F_313 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_516 )
{
const T_3 * V_517 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_217 ( V_4 , V_41 , V_30 , & V_517 ) &&
V_30 -> V_45 . V_275 &&
F_224 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_518 ) {
F_69 ( F_70 ( V_2 ) , V_519 ) ;
F_241 ( V_2 , V_4 ) ;
goto V_520;
}
}
if ( ! F_225 ( V_30 , F_16 ( V_4 ) -> V_85 , F_16 ( V_4 ) -> V_88 ) ) {
if ( ! V_41 -> V_518 )
F_241 ( V_2 , V_4 ) ;
goto V_520;
}
if ( V_41 -> V_518 ) {
F_227 ( V_2 ) ;
goto V_520;
}
F_221 ( V_30 , F_16 ( V_4 ) -> V_85 ) ;
if ( V_41 -> V_43 && ! F_38 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_84 ) ) {
if ( V_516 )
F_314 ( F_70 ( V_2 ) , V_521 ) ;
F_69 ( F_70 ( V_2 ) , V_522 ) ;
F_227 ( V_2 ) ;
return - 1 ;
}
return 1 ;
V_520:
F_249 ( V_4 ) ;
return 0 ;
}
int F_315 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_487 ;
V_30 -> V_45 . V_275 = 0 ;
if ( ( F_5 ( V_41 ) & V_523 ) == V_30 -> V_350 &&
F_16 ( V_4 ) -> V_85 == V_30 -> V_84 &&
! F_45 ( F_16 ( V_4 ) -> V_167 , V_30 -> V_102 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_406 ) {
if ( ! F_214 ( V_30 , V_41 ) )
goto V_524;
if ( ( T_5 ) ( V_30 -> V_45 . V_393 - V_30 -> V_45 . V_408 ) < 0 )
goto V_524;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_406 ) &&
V_30 -> V_84 == V_30 -> V_410 )
F_219 ( V_30 ) ;
F_207 ( V_2 , V_4 , 0 ) ;
F_249 ( V_4 ) ;
F_294 ( V_2 ) ;
return 0 ;
} else {
F_314 ( F_70 ( V_2 ) , V_521 ) ;
goto V_520;
}
} else {
int V_456 = 0 ;
int V_510 = 0 ;
if ( V_30 -> V_89 == V_30 -> V_84 &&
V_10 - V_18 <= V_30 -> V_459 . V_10 ) {
#ifdef F_316
if ( F_310 ( V_2 , V_4 , V_18 ) ) {
V_510 = 1 ;
V_456 = 1 ;
}
#endif
if ( V_30 -> V_459 . V_460 == V_461 &&
F_258 ( V_2 ) && ! V_510 ) {
F_259 ( V_464 ) ;
if ( ! F_304 ( V_2 , V_4 , V_18 ) )
V_456 = 1 ;
}
if ( V_456 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_406 ) &&
V_30 -> V_84 == V_30 -> V_410 )
F_219 ( V_30 ) ;
F_39 ( V_2 , V_4 ) ;
F_257 ( V_4 , V_18 ) ;
V_30 -> V_84 = F_16 ( V_4 ) -> V_88 ;
F_69 ( F_70 ( V_2 ) , V_525 ) ;
}
if ( V_510 )
F_317 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_456 ) {
if ( F_309 ( V_2 , V_4 ) )
goto V_526;
if ( V_18 ==
( sizeof( struct V_15 ) + V_406 ) &&
V_30 -> V_84 == V_30 -> V_410 )
F_219 ( V_30 ) ;
F_39 ( V_2 , V_4 ) ;
if ( ( int ) V_4 -> V_51 > V_2 -> V_527 )
goto V_528;
F_69 ( F_70 ( V_2 ) , V_529 ) ;
F_257 ( V_4 , V_18 ) ;
F_250 ( & V_2 -> V_453 , V_4 ) ;
F_263 ( V_4 , V_2 ) ;
V_30 -> V_84 = F_16 ( V_4 ) -> V_88 ;
}
F_41 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_167 != V_30 -> V_100 ) {
F_207 ( V_2 , V_4 , V_363 ) ;
F_294 ( V_2 ) ;
if ( ! F_300 ( V_2 ) )
goto V_530;
}
if ( ! V_510 || V_30 -> V_84 != V_30 -> V_410 )
F_296 ( V_2 , 0 ) ;
V_530:
#ifdef F_316
if ( V_510 )
F_250 ( & V_2 -> V_531 , V_4 ) ;
else
#endif
if ( V_456 )
F_249 ( V_4 ) ;
else
V_2 -> V_467 ( V_2 , 0 ) ;
return 0 ;
}
}
V_524:
if ( V_10 < ( V_41 -> V_375 << 2 ) || F_309 ( V_2 , V_4 ) )
goto V_526;
V_487 = F_313 ( V_2 , V_4 , V_41 , 1 ) ;
if ( V_487 <= 0 )
return - V_487 ;
V_528:
if ( V_41 -> V_321 && F_207 ( V_2 , V_4 , V_360 ) < 0 )
goto V_520;
F_39 ( V_2 , V_4 ) ;
F_303 ( V_2 , V_4 , V_41 ) ;
F_255 ( V_2 , V_4 ) ;
F_294 ( V_2 ) ;
F_299 ( V_2 ) ;
return 0 ;
V_526:
F_314 ( F_70 ( V_2 ) , V_521 ) ;
V_520:
F_249 ( V_4 ) ;
return 0 ;
}
static int F_318 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
const T_3 * V_517 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_532 * V_533 = V_30 -> V_534 ;
int V_535 = V_30 -> V_45 . V_46 ;
F_209 ( V_4 , & V_30 -> V_45 , & V_517 , 0 ) ;
if ( V_41 -> V_321 ) {
if ( F_16 ( V_4 ) -> V_167 != V_30 -> V_102 )
goto V_536;
if ( V_30 -> V_45 . V_275 && V_30 -> V_45 . V_87 &&
! F_190 ( V_30 -> V_45 . V_87 , V_30 -> V_274 ,
V_72 ) ) {
F_69 ( F_70 ( V_2 ) , V_537 ) ;
goto V_536;
}
if ( V_41 -> V_518 ) {
F_227 ( V_2 ) ;
goto V_520;
}
if ( ! V_41 -> V_43 )
goto V_538;
F_17 ( V_30 , V_41 ) ;
V_30 -> V_346 = F_16 ( V_4 ) -> V_85 ;
F_207 ( V_2 , V_4 , V_360 ) ;
V_30 -> V_84 = F_16 ( V_4 ) -> V_85 + 1 ;
V_30 -> V_410 = F_16 ( V_4 ) -> V_85 + 1 ;
V_30 -> V_347 = F_153 ( V_41 -> V_52 ) ;
F_319 ( V_30 , F_16 ( V_4 ) -> V_85 ) ;
if ( ! V_30 -> V_45 . V_387 ) {
V_30 -> V_45 . V_348 = V_30 -> V_45 . V_539 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_275 ) {
V_30 -> V_45 . V_391 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_406 ;
V_30 -> V_58 -= V_406 ;
F_219 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_142 ( V_30 ) && V_540 )
F_320 ( V_30 ) ;
F_321 ( V_2 ) ;
F_170 ( V_2 , V_6 -> V_301 ) ;
F_34 ( V_2 ) ;
V_30 -> V_89 = V_30 -> V_84 ;
if ( V_533 != NULL &&
V_533 -> V_541 > 0 &&
V_30 -> V_45 . V_405 > 0 ) {
int V_542 = V_30 -> V_45 . V_405
- V_401 ;
int V_541 = V_542
+ V_533 -> V_543 ;
if ( sizeof( V_533 -> V_544 ) >= V_541 ) {
memcpy ( & V_533 -> V_544 [ V_533 -> V_543 ] ,
V_517 , V_542 ) ;
V_533 -> V_541 = V_541 ;
}
}
F_322 () ;
F_233 ( V_2 , V_427 ) ;
F_323 ( V_2 , V_4 ) ;
V_6 -> V_545 -> V_546 ( V_2 ) ;
F_66 ( V_2 ) ;
F_324 ( V_2 ) ;
V_30 -> V_547 = V_72 ;
F_28 ( V_2 ) ;
if ( F_229 ( V_2 , V_548 ) )
F_325 ( V_2 , F_326 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_348 )
F_327 ( V_30 , V_30 -> V_347 ) ;
else
V_30 -> V_350 = 0 ;
if ( ! F_229 ( V_2 , V_421 ) ) {
V_2 -> V_436 ( V_2 ) ;
F_237 ( V_2 , V_549 , V_550 ) ;
}
if ( V_2 -> V_551 ||
V_6 -> V_552 . V_553 ||
V_6 -> V_8 . V_26 ) {
F_42 ( V_2 ) ;
V_6 -> V_8 . V_93 = V_72 ;
V_6 -> V_8 . V_27 = V_28 ;
F_8 ( V_2 ) ;
F_10 ( V_2 ) ;
F_134 ( V_2 , V_554 ,
V_555 , V_258 ) ;
V_520:
F_249 ( V_4 ) ;
return 0 ;
} else {
F_234 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_518 ) {
goto V_538;
}
if ( V_30 -> V_45 . V_409 && V_30 -> V_45 . V_275 &&
F_328 ( & V_30 -> V_45 , 0 ) )
goto V_538;
if ( V_41 -> V_43 ) {
F_233 ( V_2 , V_426 ) ;
if ( V_30 -> V_45 . V_275 ) {
V_30 -> V_45 . V_391 = 1 ;
F_219 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_406 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_84 = F_16 ( V_4 ) -> V_85 + 1 ;
V_30 -> V_410 = F_16 ( V_4 ) -> V_85 + 1 ;
V_30 -> V_347 = F_153 ( V_41 -> V_52 ) ;
V_30 -> V_346 = F_16 ( V_4 ) -> V_85 ;
V_30 -> V_160 = V_30 -> V_347 ;
F_18 ( V_30 , V_41 ) ;
F_321 ( V_2 ) ;
F_170 ( V_2 , V_6 -> V_301 ) ;
F_34 ( V_2 ) ;
F_329 ( V_2 ) ;
#if 0
return -1;
#else
goto V_520;
#endif
}
V_538:
F_330 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_535 ;
goto V_520;
V_536:
F_330 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_535 ;
return 1 ;
}
int F_331 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_556 = 0 ;
int V_487 ;
V_30 -> V_45 . V_275 = 0 ;
switch ( V_2 -> V_413 ) {
case V_419 :
goto V_520;
case V_557 :
if ( V_41 -> V_321 )
return 1 ;
if ( V_41 -> V_518 )
goto V_520;
if ( V_41 -> V_43 ) {
if ( V_6 -> V_545 -> V_558 ( V_2 , V_4 ) < 0 )
return 1 ;
F_332 ( V_4 ) ;
return 0 ;
}
goto V_520;
case V_414 :
V_556 = F_318 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_556 >= 0 )
return V_556 ;
F_303 ( V_2 , V_4 , V_41 ) ;
F_249 ( V_4 ) ;
F_294 ( V_2 ) ;
return 0 ;
}
V_487 = F_313 ( V_2 , V_4 , V_41 , 0 ) ;
if ( V_487 <= 0 )
return - V_487 ;
if ( V_41 -> V_321 ) {
int V_559 = F_207 ( V_2 , V_4 , V_360 ) > 0 ;
switch ( V_2 -> V_413 ) {
case V_426 :
if ( V_559 ) {
V_30 -> V_89 = V_30 -> V_84 ;
F_322 () ;
F_233 ( V_2 , V_427 ) ;
V_2 -> V_436 ( V_2 ) ;
if ( V_2 -> V_491 )
F_237 ( V_2 ,
V_549 , V_550 ) ;
V_30 -> V_100 = F_16 ( V_4 ) -> V_167 ;
V_30 -> V_347 = F_153 ( V_41 -> V_52 ) <<
V_30 -> V_45 . V_348 ;
F_319 ( V_30 , F_16 ( V_4 ) -> V_85 ) ;
if ( V_30 -> V_45 . V_391 )
V_30 -> V_58 -= V_406 ;
V_6 -> V_545 -> V_546 ( V_2 ) ;
F_66 ( V_2 ) ;
F_324 ( V_2 ) ;
V_30 -> V_547 = V_72 ;
F_321 ( V_2 ) ;
F_34 ( V_2 ) ;
F_28 ( V_2 ) ;
F_333 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_430 :
if ( V_30 -> V_100 == V_30 -> V_560 ) {
F_233 ( V_2 , V_431 ) ;
V_2 -> V_423 |= V_561 ;
F_52 ( F_51 ( V_2 ) ) ;
if ( ! F_229 ( V_2 , V_421 ) )
V_2 -> V_436 ( V_2 ) ;
else {
int V_562 ;
if ( V_30 -> V_563 < 0 ||
( F_16 ( V_4 ) -> V_88 != F_16 ( V_4 ) -> V_85 &&
F_45 ( F_16 ( V_4 ) -> V_88 - V_41 -> V_454 , V_30 -> V_84 ) ) ) {
F_230 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_564 ) ;
return 1 ;
}
V_562 = F_334 ( V_2 ) ;
if ( V_562 > V_565 ) {
F_325 ( V_2 , V_562 - V_565 ) ;
} else if ( V_41 -> V_454 || F_258 ( V_2 ) ) {
F_325 ( V_2 , V_562 ) ;
} else {
F_235 ( V_2 , V_431 , V_562 ) ;
goto V_520;
}
}
}
break;
case V_428 :
if ( V_30 -> V_100 == V_30 -> V_560 ) {
F_235 ( V_2 , V_432 , 0 ) ;
goto V_520;
}
break;
case V_429 :
if ( V_30 -> V_100 == V_30 -> V_560 ) {
F_50 ( V_2 ) ;
F_230 ( V_2 ) ;
goto V_520;
}
break;
}
} else
goto V_520;
F_303 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_413 ) {
case V_417 :
case V_428 :
case V_429 :
if ( ! F_38 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_84 ) )
break;
case V_430 :
case V_431 :
if ( V_2 -> V_423 & V_424 ) {
if ( F_16 ( V_4 ) -> V_88 != F_16 ( V_4 ) -> V_85 &&
F_45 ( F_16 ( V_4 ) -> V_88 - V_41 -> V_454 , V_30 -> V_84 ) ) {
F_69 ( F_70 ( V_2 ) , V_564 ) ;
F_227 ( V_2 ) ;
return 1 ;
}
}
case V_427 :
F_255 ( V_2 , V_4 ) ;
V_556 = 1 ;
break;
}
if ( V_2 -> V_413 != V_419 ) {
F_294 ( V_2 ) ;
F_299 ( V_2 ) ;
}
if ( ! V_556 ) {
V_520:
F_249 ( V_4 ) ;
}
return 0 ;
}
