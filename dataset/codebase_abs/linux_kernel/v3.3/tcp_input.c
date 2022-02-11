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
! F_26 ( V_2 ) ) {
int V_56 ;
if ( F_23 ( V_4 -> V_51 ) <= V_4 -> V_10 )
V_56 = 2 * V_30 -> V_57 ;
else
V_56 = F_22 ( V_2 , V_4 ) ;
if ( V_56 ) {
V_30 -> V_54 = F_9 ( V_30 -> V_54 + V_56 ,
V_30 -> V_55 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_58 = F_7 ( V_2 ) -> V_57 ;
T_1 V_59 = V_60 ;
int V_61 ;
if ( V_58 > 1460 )
V_59 = F_28 ( T_1 , ( 1460 * V_60 ) / V_58 , 2 ) ;
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
F_27 ( V_2 ) ;
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
} else if ( V_79 < V_76 )
V_76 = V_79 << 3 ;
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
F_38 ( V_30 , V_83 - V_30 -> V_77 . time , 1 ) ;
V_80:
V_30 -> V_77 . V_82 = V_30 -> V_81 + V_30 -> V_23 ;
V_30 -> V_77 . time = V_71 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_84 &&
( F_16 ( V_4 ) -> V_85 -
F_16 ( V_4 ) -> V_82 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_38 ( V_30 , V_71 - V_30 -> V_45 . V_84 , 0 ) ;
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
V_68 = 2 * ( V_30 -> V_86 - V_30 -> V_67 . V_82 ) ;
V_68 = F_31 ( V_30 -> V_67 . V_68 , V_68 ) ;
if ( V_30 -> V_67 . V_68 != V_68 ) {
int V_61 ;
V_30 -> V_67 . V_68 = V_68 ;
if ( V_87 &&
! ( V_2 -> V_64 & V_65 ) ) {
int V_88 = V_68 ;
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
V_30 -> V_55 = V_88 ;
}
}
}
V_80:
V_30 -> V_67 . V_82 = V_30 -> V_86 ;
V_30 -> V_67 . time = V_71 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_89 ;
F_44 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_39 ( V_30 ) ;
V_89 = V_71 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_79 = V_89 - V_6 -> V_8 . V_90 ;
if ( V_79 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_79 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_79 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_91 )
V_6 -> V_8 . V_27 = V_6 -> V_91 ;
} else if ( V_79 > V_6 -> V_91 ) {
F_8 ( V_2 ) ;
F_45 ( V_2 ) ;
}
}
V_6 -> V_8 . V_90 = V_89 ;
F_15 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_24 ( V_2 , V_4 ) ;
}
static void F_46 ( struct V_1 * V_2 , const T_2 V_92 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_79 = V_92 ;
if ( V_79 == 0 )
V_79 = 1 ;
if ( V_30 -> V_93 != 0 ) {
V_79 -= ( V_30 -> V_93 >> 3 ) ;
V_30 -> V_93 += V_79 ;
if ( V_79 < 0 ) {
V_79 = - V_79 ;
V_79 -= ( V_30 -> V_94 >> 2 ) ;
if ( V_79 > 0 )
V_79 >>= 3 ;
} else {
V_79 -= ( V_30 -> V_94 >> 2 ) ;
}
V_30 -> V_94 += V_79 ;
if ( V_30 -> V_94 > V_30 -> V_95 ) {
V_30 -> V_95 = V_30 -> V_94 ;
if ( V_30 -> V_95 > V_30 -> V_96 )
V_30 -> V_96 = V_30 -> V_95 ;
}
if ( F_47 ( V_30 -> V_97 , V_30 -> V_98 ) ) {
if ( V_30 -> V_95 < V_30 -> V_96 )
V_30 -> V_96 -= ( V_30 -> V_96 - V_30 -> V_95 ) >> 2 ;
V_30 -> V_98 = V_30 -> V_99 ;
V_30 -> V_95 = F_48 ( V_2 ) ;
}
} else {
V_30 -> V_93 = V_79 << 3 ;
V_30 -> V_94 = V_79 << 1 ;
V_30 -> V_95 = V_30 -> V_96 = F_31 ( V_30 -> V_94 , F_48 ( V_2 ) ) ;
V_30 -> V_98 = V_30 -> V_99 ;
}
}
static inline void F_49 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_91 = F_50 ( V_30 ) ;
F_51 ( V_2 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_100 * V_101 = F_53 ( V_2 ) ;
if ( V_102 )
return;
F_54 ( V_101 ) ;
if ( V_101 && ( V_101 -> V_103 & V_104 ) ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_79 ;
unsigned long V_78 ;
if ( V_6 -> V_105 || ! V_30 -> V_93 ) {
if ( ! ( F_55 ( V_101 , V_106 ) ) )
F_56 ( V_101 , V_106 , 0 ) ;
return;
}
V_78 = F_57 ( V_101 , V_106 ) ;
V_79 = V_78 - V_30 -> V_93 ;
if ( ! ( F_55 ( V_101 , V_106 ) ) ) {
if ( V_79 <= 0 )
F_58 ( V_101 , V_106 , V_30 -> V_93 ) ;
else
F_58 ( V_101 , V_106 , V_78 - ( V_79 >> 3 ) ) ;
}
if ( ! ( F_55 ( V_101 , V_107 ) ) ) {
unsigned long V_108 ;
if ( V_79 < 0 )
V_79 = - V_79 ;
V_79 >>= 1 ;
if ( V_79 < V_30 -> V_94 )
V_79 = V_30 -> V_94 ;
V_108 = F_57 ( V_101 , V_107 ) ;
if ( V_79 >= V_108 )
V_108 = V_79 ;
else
V_108 -= ( V_108 - V_79 ) >> 2 ;
F_58 ( V_101 , V_107 , V_108 ) ;
}
if ( F_59 ( V_30 ) ) {
if ( F_60 ( V_101 , V_109 ) &&
! F_55 ( V_101 , V_109 ) &&
( V_30 -> V_110 >> 1 ) > F_60 ( V_101 , V_109 ) )
F_56 ( V_101 , V_109 , V_30 -> V_110 >> 1 ) ;
if ( ! F_55 ( V_101 , V_111 ) &&
V_30 -> V_110 > F_60 ( V_101 , V_111 ) )
F_56 ( V_101 , V_111 , V_30 -> V_110 ) ;
} else if ( V_30 -> V_110 > V_30 -> V_112 &&
V_6 -> V_113 == V_114 ) {
if ( ! F_55 ( V_101 , V_109 ) )
F_56 ( V_101 , V_109 ,
F_31 ( V_30 -> V_110 >> 1 , V_30 -> V_112 ) ) ;
if ( ! F_55 ( V_101 , V_111 ) )
F_56 ( V_101 , V_111 ,
( F_60 ( V_101 , V_111 ) +
V_30 -> V_110 ) >> 1 ) ;
} else {
if ( ! F_55 ( V_101 , V_111 ) )
F_56 ( V_101 , V_111 ,
( F_60 ( V_101 , V_111 ) +
V_30 -> V_112 ) >> 1 ) ;
if ( F_60 ( V_101 , V_109 ) &&
! F_55 ( V_101 , V_109 ) &&
V_30 -> V_112 > F_60 ( V_101 , V_109 ) )
F_56 ( V_101 , V_109 , V_30 -> V_112 ) ;
}
if ( ! F_55 ( V_101 , V_115 ) ) {
if ( F_60 ( V_101 , V_115 ) < V_30 -> V_116 &&
V_30 -> V_116 != V_117 )
F_56 ( V_101 , V_115 , V_30 -> V_116 ) ;
}
}
}
T_2 F_61 ( const struct V_29 * V_30 , const struct V_100 * V_101 )
{
T_2 V_118 = ( V_101 ? F_60 ( V_101 , V_119 ) : 0 ) ;
if ( ! V_118 )
V_118 = V_48 ;
return F_37 ( T_2 , V_118 , V_30 -> V_120 ) ;
}
void F_62 ( struct V_1 * V_2 , const int V_121 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_122 = 0 ;
V_30 -> V_123 = 0 ;
if ( V_6 -> V_113 < V_124 ) {
V_30 -> V_125 = 0 ;
if ( V_121 )
V_30 -> V_112 = V_6 -> V_126 -> V_127 ( V_2 ) ;
V_30 -> V_110 = F_9 ( V_30 -> V_110 ,
F_63 ( V_30 ) + 1U ) ;
V_30 -> V_128 = 0 ;
V_30 -> V_129 = V_30 -> V_99 ;
V_30 -> V_70 = V_71 ;
F_12 ( V_30 ) ;
F_64 ( V_2 , V_124 ) ;
}
}
static void F_65 ( struct V_29 * V_30 )
{
if ( F_66 ( V_30 ) )
V_30 -> V_130 = NULL ;
V_30 -> V_45 . V_131 &= ~ V_132 ;
}
static void F_67 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_131 |= V_133 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_100 * V_101 = F_53 ( V_2 ) ;
if ( V_101 == NULL )
goto V_134;
F_54 ( V_101 ) ;
if ( F_55 ( V_101 , V_111 ) )
V_30 -> V_120 = F_60 ( V_101 , V_111 ) ;
if ( F_60 ( V_101 , V_109 ) ) {
V_30 -> V_112 = F_60 ( V_101 , V_109 ) ;
if ( V_30 -> V_112 > V_30 -> V_120 )
V_30 -> V_112 = V_30 -> V_120 ;
} else {
V_30 -> V_112 = V_135 ;
}
if ( F_60 ( V_101 , V_115 ) &&
V_30 -> V_116 != F_60 ( V_101 , V_115 ) ) {
F_65 ( V_30 ) ;
V_30 -> V_116 = F_60 ( V_101 , V_115 ) ;
}
if ( F_60 ( V_101 , V_106 ) == 0 || V_30 -> V_93 == 0 )
goto V_134;
if ( F_57 ( V_101 , V_106 ) > V_30 -> V_93 ) {
V_30 -> V_93 = F_57 ( V_101 , V_106 ) ;
V_30 -> V_98 = V_30 -> V_99 ;
}
if ( F_57 ( V_101 , V_107 ) > V_30 -> V_94 ) {
V_30 -> V_94 = F_57 ( V_101 , V_107 ) ;
V_30 -> V_95 = V_30 -> V_96 = F_31 ( V_30 -> V_94 , F_48 ( V_2 ) ) ;
}
F_49 ( V_2 ) ;
V_134:
if ( V_30 -> V_93 == 0 ) {
V_30 -> V_94 = V_30 -> V_95 = V_30 -> V_96 = V_136 ;
F_2 ( V_2 ) -> V_91 = V_136 ;
}
if ( V_30 -> V_137 > 1 )
V_30 -> V_110 = 1 ;
else
V_30 -> V_110 = F_61 ( V_30 , V_101 ) ;
V_30 -> V_70 = V_71 ;
}
static void F_69 ( struct V_1 * V_2 , const int V_138 ,
const int V_139 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_138 > V_30 -> V_116 ) {
int V_140 ;
V_30 -> V_116 = F_9 ( V_141 , V_138 ) ;
if ( V_139 )
V_140 = V_142 ;
else if ( F_70 ( V_30 ) )
V_140 = V_143 ;
else if ( F_66 ( V_30 ) )
V_140 = V_144 ;
else
V_140 = V_145 ;
F_71 ( F_72 ( V_2 ) , V_140 ) ;
#if V_146 > 1
F_73 ( V_147 L_1 ,
V_30 -> V_45 . V_131 , F_2 ( V_2 ) -> V_113 ,
V_30 -> V_116 ,
V_30 -> V_148 ,
V_30 -> V_149 ,
V_30 -> V_125 ? V_30 -> V_150 : 0 ) ;
#endif
F_65 ( V_30 ) ;
}
}
static void F_74 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_151 == NULL ) ||
F_40 ( F_16 ( V_4 ) -> V_82 ,
F_16 ( V_30 -> V_151 ) -> V_82 ) )
V_30 -> V_151 = V_4 ;
if ( ! V_30 -> V_152 ||
F_47 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_153 ) )
V_30 -> V_153 = F_16 ( V_4 ) -> V_85 ;
}
static void F_75 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_154 & ( V_155 | V_156 ) ) ) {
F_74 ( V_30 , V_4 ) ;
V_30 -> V_152 += F_76 ( V_4 ) ;
F_16 ( V_4 ) -> V_154 |= V_155 ;
}
}
static void F_77 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_74 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_154 & ( V_155 | V_156 ) ) ) {
V_30 -> V_152 += F_76 ( V_4 ) ;
F_16 ( V_4 ) -> V_154 |= V_155 ;
}
}
static int F_78 ( struct V_29 * V_30 , int V_157 ,
T_1 V_158 , T_1 V_85 )
{
if ( F_47 ( V_85 , V_30 -> V_99 ) || ! F_40 ( V_158 , V_85 ) )
return 0 ;
if ( ! F_40 ( V_158 , V_30 -> V_99 ) )
return 0 ;
if ( F_47 ( V_158 , V_30 -> V_97 ) )
return 1 ;
if ( ! V_157 || ! V_30 -> V_125 )
return 0 ;
if ( F_47 ( V_85 , V_30 -> V_97 ) )
return 0 ;
if ( ! F_40 ( V_158 , V_30 -> V_125 ) )
return 1 ;
if ( ! F_47 ( V_85 , V_30 -> V_125 ) )
return 0 ;
return ! F_40 ( V_158 , V_85 - V_30 -> V_159 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_160 = 0 ;
T_1 V_161 = V_30 -> V_99 ;
T_1 V_162 = F_80 ( V_30 ) ;
if ( ! F_66 ( V_30 ) || ! V_30 -> V_163 ||
! F_47 ( V_162 , V_30 -> V_164 ) ||
V_6 -> V_113 != V_165 )
return;
F_81 (skb, sk) {
T_1 V_166 = F_16 ( V_4 ) -> V_166 ;
if ( V_4 == F_82 ( V_2 ) )
break;
if ( V_160 == V_30 -> V_163 )
break;
if ( ! F_47 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_97 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_154 & V_167 ) )
continue;
if ( F_47 ( V_162 , V_166 ) ) {
F_16 ( V_4 ) -> V_154 &= ~ V_167 ;
V_30 -> V_163 -= F_76 ( V_4 ) ;
F_77 ( V_30 , V_4 ) ;
F_71 ( F_72 ( V_2 ) , V_168 ) ;
} else {
if ( F_40 ( V_166 , V_161 ) )
V_161 = V_166 ;
V_160 += F_76 ( V_4 ) ;
}
}
if ( V_30 -> V_163 )
V_30 -> V_164 = V_161 ;
}
static int F_83 ( struct V_1 * V_2 , const struct V_3 * V_169 ,
struct V_170 * V_171 , int V_172 ,
T_1 V_173 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_174 = F_84 ( & V_171 [ 0 ] . V_158 ) ;
T_1 V_175 = F_84 ( & V_171 [ 0 ] . V_85 ) ;
int V_176 = 0 ;
if ( F_40 ( V_174 , F_16 ( V_169 ) -> V_166 ) ) {
V_176 = 1 ;
F_67 ( V_30 ) ;
F_71 ( F_72 ( V_2 ) , V_177 ) ;
} else if ( V_172 > 1 ) {
T_1 V_178 = F_84 ( & V_171 [ 1 ] . V_85 ) ;
T_1 V_179 = F_84 ( & V_171 [ 1 ] . V_158 ) ;
if ( ! F_47 ( V_175 , V_178 ) &&
! F_40 ( V_174 , V_179 ) ) {
V_176 = 1 ;
F_67 ( V_30 ) ;
F_71 ( F_72 ( V_2 ) ,
V_180 ) ;
}
}
if ( V_176 && V_30 -> V_125 && V_30 -> V_150 &&
! F_47 ( V_175 , V_173 ) &&
F_47 ( V_175 , V_30 -> V_125 ) )
V_30 -> V_150 -- ;
return V_176 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_158 , T_1 V_85 )
{
int V_181 , V_182 ;
unsigned int V_183 ;
unsigned int V_58 ;
V_181 = ! F_47 ( V_158 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_85 , F_16 ( V_4 ) -> V_85 ) ;
if ( F_76 ( V_4 ) > 1 && ! V_181 &&
F_47 ( F_16 ( V_4 ) -> V_85 , V_158 ) ) {
V_58 = F_86 ( V_4 ) ;
V_181 = ! F_47 ( V_158 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_181 ) {
V_183 = V_158 - F_16 ( V_4 ) -> V_82 ;
if ( V_183 < V_58 )
V_183 = V_58 ;
} else {
V_183 = V_85 - F_16 ( V_4 ) -> V_82 ;
if ( V_183 < V_58 )
return - V_184 ;
}
if ( V_183 > V_58 ) {
unsigned int V_185 = ( V_183 / V_58 ) * V_58 ;
if ( ! V_181 && V_185 < V_183 ) {
V_185 += V_58 ;
if ( V_185 > V_4 -> V_10 )
return 0 ;
}
V_183 = V_185 ;
}
V_182 = F_87 ( V_2 , V_4 , V_183 , V_58 ) ;
if ( V_182 < 0 )
return V_182 ;
}
return V_181 ;
}
static T_3 F_88 ( struct V_1 * V_2 ,
struct V_186 * V_187 , T_3 V_154 ,
T_1 V_158 , T_1 V_85 ,
int V_176 , int V_188 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_189 = V_187 -> V_189 ;
if ( V_176 && ( V_154 & V_190 ) ) {
if ( V_30 -> V_125 && V_30 -> V_150 &&
F_47 ( V_85 , V_30 -> V_125 ) )
V_30 -> V_150 -- ;
if ( V_154 & V_156 )
V_187 -> V_191 = F_9 ( V_189 , V_187 -> V_191 ) ;
}
if ( ! F_47 ( V_85 , V_30 -> V_97 ) )
return V_154 ;
if ( ! ( V_154 & V_156 ) ) {
if ( V_154 & V_167 ) {
if ( V_154 & V_155 ) {
V_154 &= ~ ( V_155 | V_167 ) ;
V_30 -> V_152 -= V_188 ;
V_30 -> V_163 -= V_188 ;
}
} else {
if ( ! ( V_154 & V_190 ) ) {
if ( F_40 ( V_158 ,
F_80 ( V_30 ) ) )
V_187 -> V_191 = F_9 ( V_189 ,
V_187 -> V_191 ) ;
if ( ! F_47 ( V_85 , V_30 -> V_192 ) )
V_187 -> V_193 |= V_194 ;
}
if ( V_154 & V_155 ) {
V_154 &= ~ V_155 ;
V_30 -> V_152 -= V_188 ;
}
}
V_154 |= V_156 ;
V_187 -> V_193 |= V_195 ;
V_30 -> V_149 += V_188 ;
V_189 += V_188 ;
if ( ! F_66 ( V_30 ) && ( V_30 -> V_130 != NULL ) &&
F_40 ( V_158 , F_16 ( V_30 -> V_130 ) -> V_82 ) )
V_30 -> V_196 += V_188 ;
if ( V_189 > V_30 -> V_148 )
V_30 -> V_148 = V_189 ;
}
if ( V_176 && ( V_154 & V_167 ) ) {
V_154 &= ~ V_167 ;
V_30 -> V_163 -= V_188 ;
}
return V_154 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_186 * V_187 ,
unsigned int V_188 , int V_197 , int V_58 ,
int V_176 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_198 = F_90 ( V_2 , V_4 ) ;
T_1 V_158 = F_16 ( V_4 ) -> V_82 ;
T_1 V_85 = V_158 + V_197 ;
F_91 ( ! V_188 ) ;
F_88 ( V_2 , V_187 , F_16 ( V_4 ) -> V_154 ,
V_158 , V_85 , V_176 , V_188 ) ;
if ( V_4 == V_30 -> V_130 )
V_30 -> V_196 += V_188 ;
F_16 ( V_198 ) -> V_85 += V_197 ;
F_16 ( V_4 ) -> V_82 += V_197 ;
F_3 ( V_198 ) -> V_199 += V_188 ;
F_91 ( F_3 ( V_4 ) -> V_199 < V_188 ) ;
F_3 ( V_4 ) -> V_199 -= V_188 ;
if ( ! F_3 ( V_198 ) -> V_11 ) {
F_3 ( V_198 ) -> V_11 = V_58 ;
F_3 ( V_198 ) -> V_200 = V_2 -> V_201 ;
}
if ( F_3 ( V_4 ) -> V_199 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_200 = 0 ;
}
F_16 ( V_198 ) -> V_154 |= ( F_16 ( V_4 ) -> V_154 & V_202 ) ;
if ( V_4 -> V_10 > 0 ) {
F_91 ( ! F_76 ( V_4 ) ) ;
F_71 ( F_72 ( V_2 ) , V_203 ) ;
return 0 ;
}
if ( V_4 == V_30 -> V_151 )
V_30 -> V_151 = V_198 ;
if ( V_4 == V_30 -> V_204 )
V_30 -> V_204 = V_198 ;
if ( V_4 == V_30 -> V_130 ) {
V_30 -> V_130 = V_198 ;
V_30 -> V_196 -= F_76 ( V_198 ) ;
}
F_16 ( V_4 ) -> V_205 |= F_16 ( V_198 ) -> V_205 ;
if ( V_4 == F_92 ( V_2 ) )
F_93 ( V_2 , V_4 ) ;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
F_71 ( F_72 ( V_2 ) , V_206 ) ;
return 1 ;
}
static int F_96 ( const struct V_3 * V_4 )
{
return F_76 ( V_4 ) == 1 ? V_4 -> V_10 : F_86 ( V_4 ) ;
}
static int F_97 ( const struct V_3 * V_4 )
{
return ! F_98 ( V_4 ) && F_99 ( V_4 ) ;
}
static struct V_3 * F_100 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_186 * V_187 ,
T_1 V_158 , T_1 V_85 ,
int V_176 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_198 ;
int V_58 ;
int V_188 = 0 ;
int V_10 ;
int V_181 ;
if ( ! F_101 ( V_2 ) )
goto V_207;
if ( ! V_176 &&
( F_16 ( V_4 ) -> V_154 & ( V_155 | V_167 ) ) == V_167 )
goto V_207;
if ( ! F_97 ( V_4 ) )
goto V_207;
if ( ! F_47 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_97 ) )
goto V_207;
if ( F_102 ( V_4 == F_103 ( V_2 ) ) )
goto V_207;
V_198 = F_90 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_198 ) -> V_154 & V_208 ) != V_156 )
goto V_207;
V_181 = ! F_47 ( V_158 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_85 , F_16 ( V_4 ) -> V_85 ) ;
if ( V_181 ) {
V_10 = V_4 -> V_10 ;
V_188 = F_76 ( V_4 ) ;
V_58 = F_96 ( V_4 ) ;
if ( V_58 != F_96 ( V_198 ) )
goto V_207;
} else {
if ( ! F_47 ( F_16 ( V_4 ) -> V_85 , V_158 ) )
goto V_209;
if ( F_76 ( V_4 ) <= 1 )
goto V_209;
V_181 = ! F_47 ( V_158 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_181 ) {
goto V_207;
}
V_10 = V_85 - F_16 ( V_4 ) -> V_82 ;
F_91 ( V_10 < 0 ) ;
F_91 ( V_10 > V_4 -> V_10 ) ;
V_58 = F_86 ( V_4 ) ;
if ( V_58 != F_96 ( V_198 ) )
goto V_207;
if ( V_10 == V_58 ) {
V_188 = 1 ;
} else if ( V_10 < V_58 ) {
goto V_209;
} else {
V_188 = V_10 / V_58 ;
V_10 = V_188 * V_58 ;
}
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_82 + V_10 , V_30 -> V_97 ) )
goto V_207;
if ( ! F_104 ( V_198 , V_4 , V_10 ) )
goto V_207;
if ( ! F_89 ( V_2 , V_4 , V_187 , V_188 , V_10 , V_58 , V_176 ) )
goto V_210;
if ( V_198 == F_105 ( V_2 ) )
goto V_210;
V_4 = F_106 ( V_2 , V_198 ) ;
if ( ! F_97 ( V_4 ) ||
( V_4 == F_82 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_154 & V_208 ) != V_156 ) ||
( V_58 != F_96 ( V_4 ) ) )
goto V_210;
V_10 = V_4 -> V_10 ;
if ( F_104 ( V_198 , V_4 , V_10 ) ) {
V_188 += F_76 ( V_4 ) ;
F_89 ( V_2 , V_4 , V_187 , F_76 ( V_4 ) , V_10 , V_58 , 0 ) ;
}
V_210:
V_187 -> V_189 += V_188 ;
return V_198 ;
V_209:
return V_4 ;
V_207:
F_71 ( F_72 ( V_2 ) , V_211 ) ;
return NULL ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_212 * V_213 ,
struct V_186 * V_187 ,
T_1 V_158 , T_1 V_85 ,
int V_214 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_215 ;
F_108 (skb, sk) {
int V_181 = 0 ;
int V_176 = V_214 ;
if ( V_4 == F_82 ( V_2 ) )
break;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_85 ) )
break;
if ( ( V_213 != NULL ) &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_213 -> V_85 ) ) {
V_181 = F_85 ( V_2 , V_4 ,
V_213 -> V_158 ,
V_213 -> V_85 ) ;
if ( V_181 > 0 )
V_176 = 1 ;
}
if ( V_181 <= 0 ) {
V_215 = F_100 ( V_2 , V_4 , V_187 ,
V_158 , V_85 , V_176 ) ;
if ( V_215 != NULL ) {
if ( V_215 != V_4 ) {
V_4 = V_215 ;
continue;
}
V_181 = 0 ;
} else {
V_181 = F_85 ( V_2 , V_4 ,
V_158 ,
V_85 ) ;
}
}
if ( F_102 ( V_181 < 0 ) )
break;
if ( V_181 ) {
F_16 ( V_4 ) -> V_154 =
F_88 ( V_2 ,
V_187 ,
F_16 ( V_4 ) -> V_154 ,
F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_85 ,
V_176 ,
F_76 ( V_4 ) ) ;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 ,
F_80 ( V_30 ) ) )
F_93 ( V_2 , V_4 ) ;
}
V_187 -> V_189 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_109 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_186 * V_187 ,
T_1 V_216 )
{
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_47 ( F_16 ( V_4 ) -> V_85 , V_216 ) )
break;
V_187 -> V_189 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_110 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_212 * V_213 ,
struct V_186 * V_187 ,
T_1 V_216 )
{
if ( V_213 == NULL )
return V_4 ;
if ( F_40 ( V_213 -> V_158 , V_216 ) ) {
V_4 = F_109 ( V_4 , V_2 , V_187 , V_213 -> V_158 ) ;
V_4 = F_107 ( V_4 , V_2 , NULL , V_187 ,
V_213 -> V_158 , V_213 -> V_85 ,
1 ) ;
}
return V_4 ;
}
static int F_111 ( const struct V_29 * V_30 , const struct V_212 * V_217 )
{
return V_217 < V_30 -> V_218 + F_112 ( V_30 -> V_218 ) ;
}
static int
F_113 ( struct V_1 * V_2 , const struct V_3 * V_169 ,
T_1 V_173 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_219 = ( F_4 ( V_169 ) +
F_16 ( V_169 ) -> V_154 ) ;
struct V_170 * V_220 = (struct V_170 * ) ( V_219 + 2 ) ;
struct V_212 V_171 [ V_221 ] ;
struct V_212 * V_217 ;
struct V_186 V_187 ;
struct V_3 * V_4 ;
int V_172 = F_9 ( V_221 , ( V_219 [ 1 ] - V_222 ) >> 3 ) ;
int V_223 ;
int V_224 = 0 ;
int V_225 , V_226 ;
int V_227 ;
V_187 . V_193 = 0 ;
V_187 . V_191 = V_30 -> V_228 ;
if ( ! V_30 -> V_149 ) {
if ( F_114 ( V_30 -> V_148 ) )
V_30 -> V_148 = 0 ;
F_115 ( V_2 ) ;
}
V_224 = F_83 ( V_2 , V_169 , V_220 ,
V_172 , V_173 ) ;
if ( V_224 )
V_187 . V_193 |= V_229 ;
if ( F_40 ( F_16 ( V_169 ) -> V_166 , V_173 - V_30 -> V_159 ) )
return 0 ;
if ( ! V_30 -> V_228 )
goto V_210;
V_223 = 0 ;
V_227 = 0 ;
for ( V_225 = 0 ; V_225 < V_172 ; V_225 ++ ) {
int V_176 = ! V_225 && V_224 ;
V_171 [ V_223 ] . V_158 = F_84 ( & V_220 [ V_225 ] . V_158 ) ;
V_171 [ V_223 ] . V_85 = F_84 ( & V_220 [ V_225 ] . V_85 ) ;
if ( ! F_78 ( V_30 , V_176 ,
V_171 [ V_223 ] . V_158 ,
V_171 [ V_223 ] . V_85 ) ) {
int V_140 ;
if ( V_176 ) {
if ( ! V_30 -> V_125 )
V_140 = V_230 ;
else
V_140 = V_231 ;
} else {
if ( ( F_16 ( V_169 ) -> V_166 != V_30 -> V_97 ) &&
! F_47 ( V_171 [ V_223 ] . V_85 , V_30 -> V_97 ) )
continue;
V_140 = V_232 ;
}
F_71 ( F_72 ( V_2 ) , V_140 ) ;
if ( V_225 == 0 )
V_227 = - 1 ;
continue;
}
if ( ! F_47 ( V_171 [ V_223 ] . V_85 , V_173 ) )
continue;
V_223 ++ ;
}
for ( V_225 = V_223 - 1 ; V_225 > 0 ; V_225 -- ) {
for ( V_226 = 0 ; V_226 < V_225 ; V_226 ++ ) {
if ( F_47 ( V_171 [ V_226 ] . V_158 , V_171 [ V_226 + 1 ] . V_158 ) ) {
F_116 ( V_171 [ V_226 ] , V_171 [ V_226 + 1 ] ) ;
if ( V_226 == V_227 )
V_227 = V_226 + 1 ;
}
}
}
V_4 = F_103 ( V_2 ) ;
V_187 . V_189 = 0 ;
V_225 = 0 ;
if ( ! V_30 -> V_149 ) {
V_217 = V_30 -> V_218 + F_112 ( V_30 -> V_218 ) ;
} else {
V_217 = V_30 -> V_218 ;
while ( F_111 ( V_30 , V_217 ) && ! V_217 -> V_158 &&
! V_217 -> V_85 )
V_217 ++ ;
}
while ( V_225 < V_223 ) {
T_1 V_158 = V_171 [ V_225 ] . V_158 ;
T_1 V_85 = V_171 [ V_225 ] . V_85 ;
int V_176 = ( V_224 && ( V_225 == V_227 ) ) ;
struct V_212 * V_213 = NULL ;
if ( V_224 && ( ( V_225 + 1 ) == V_227 ) )
V_213 = & V_171 [ V_225 + 1 ] ;
while ( F_111 ( V_30 , V_217 ) &&
! F_40 ( V_158 , V_217 -> V_85 ) )
V_217 ++ ;
if ( F_111 ( V_30 , V_217 ) && ! V_176 &&
F_47 ( V_85 , V_217 -> V_158 ) ) {
if ( F_40 ( V_158 , V_217 -> V_158 ) ) {
V_4 = F_109 ( V_4 , V_2 , & V_187 ,
V_158 ) ;
V_4 = F_107 ( V_4 , V_2 , V_213 ,
& V_187 ,
V_158 ,
V_217 -> V_158 ,
V_176 ) ;
}
if ( ! F_47 ( V_85 , V_217 -> V_85 ) )
goto V_233;
V_4 = F_110 ( V_4 , V_2 , V_213 ,
& V_187 ,
V_217 -> V_85 ) ;
if ( F_80 ( V_30 ) == V_217 -> V_85 ) {
V_4 = F_92 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_187 . V_189 = V_30 -> V_148 ;
V_217 ++ ;
goto V_234;
}
V_4 = F_109 ( V_4 , V_2 , & V_187 , V_217 -> V_85 ) ;
V_217 ++ ;
continue;
}
if ( ! F_40 ( V_158 , F_80 ( V_30 ) ) ) {
V_4 = F_92 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_187 . V_189 = V_30 -> V_148 ;
}
V_4 = F_109 ( V_4 , V_2 , & V_187 , V_158 ) ;
V_234:
V_4 = F_107 ( V_4 , V_2 , V_213 , & V_187 ,
V_158 , V_85 , V_176 ) ;
V_233:
if ( F_47 ( V_85 , V_30 -> V_192 ) )
V_187 . V_193 &= ~ V_194 ;
V_225 ++ ;
}
for ( V_225 = 0 ; V_225 < F_112 ( V_30 -> V_218 ) - V_223 ; V_225 ++ ) {
V_30 -> V_218 [ V_225 ] . V_158 = 0 ;
V_30 -> V_218 [ V_225 ] . V_85 = 0 ;
}
for ( V_226 = 0 ; V_226 < V_223 ; V_226 ++ )
V_30 -> V_218 [ V_225 ++ ] = V_171 [ V_226 ] ;
F_79 ( V_2 ) ;
F_117 ( V_30 ) ;
if ( ( V_187 . V_191 < V_30 -> V_148 ) &&
( ( V_6 -> V_113 != V_235 ) || V_30 -> V_125 ) &&
( ! V_30 -> V_192 || F_47 ( V_30 -> V_97 , V_30 -> V_192 ) ) )
F_69 ( V_2 , V_30 -> V_148 - V_187 . V_191 , 0 ) ;
V_210:
#if V_146 > 0
F_114 ( ( int ) V_30 -> V_149 < 0 ) ;
F_114 ( ( int ) V_30 -> V_152 < 0 ) ;
F_114 ( ( int ) V_30 -> V_163 < 0 ) ;
F_114 ( ( int ) F_63 ( V_30 ) < 0 ) ;
#endif
return V_187 . V_193 ;
}
static int F_118 ( struct V_29 * V_30 )
{
T_1 V_236 ;
V_236 = F_31 ( V_30 -> V_152 , 1U ) ;
V_236 = F_9 ( V_236 , V_30 -> V_228 ) ;
if ( ( V_30 -> V_149 + V_236 ) > V_30 -> V_228 ) {
V_30 -> V_149 = V_30 -> V_228 - V_236 ;
return 1 ;
}
return 0 ;
}
static void F_119 ( struct V_1 * V_2 , const int V_237 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_118 ( V_30 ) )
F_69 ( V_2 , V_30 -> V_228 + V_237 , 0 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_149 ++ ;
F_119 ( V_2 , 0 ) ;
F_117 ( V_30 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_238 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_238 > 0 ) {
if ( V_238 - 1 >= V_30 -> V_149 )
V_30 -> V_149 = 0 ;
else
V_30 -> V_149 -= V_238 - 1 ;
}
F_119 ( V_2 , V_238 ) ;
F_117 ( V_30 ) ;
}
static inline void F_122 ( struct V_29 * V_30 )
{
V_30 -> V_149 = 0 ;
}
static int F_123 ( const struct V_29 * V_30 )
{
return ( V_239 == 0x2 ) && ! F_70 ( V_30 ) ;
}
int F_124 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_239 )
return 0 ;
if ( V_6 -> V_240 . V_241 )
return 0 ;
if ( F_123 ( V_30 ) )
return 1 ;
if ( V_30 -> V_163 > 1 )
return 0 ;
V_4 = F_103 ( V_2 ) ;
if ( F_125 ( V_2 , V_4 ) )
return 1 ;
V_4 = F_106 ( V_2 , V_4 ) ;
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_154 & V_190 )
return 0 ;
if ( ! ( F_16 ( V_4 ) -> V_154 & V_156 ) )
break;
}
return 1 ;
}
void F_126 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ( ! V_30 -> V_242 && V_6 -> V_113 <= V_243 ) ||
V_30 -> V_97 == V_30 -> V_129 ||
( ( V_6 -> V_113 == V_235 || V_30 -> V_242 ) &&
! V_6 -> V_244 ) ) {
V_30 -> V_122 = F_127 ( V_2 ) ;
if ( V_30 -> V_242 ) {
T_1 V_245 ;
V_245 = V_30 -> V_110 ;
V_30 -> V_110 = 2 ;
V_30 -> V_112 = V_6 -> V_126 -> V_127 ( V_2 ) ;
V_30 -> V_110 = V_245 ;
} else {
V_30 -> V_112 = V_6 -> V_126 -> V_127 ( V_2 ) ;
}
F_128 ( V_2 , V_246 ) ;
}
V_30 -> V_125 = V_30 -> V_97 ;
V_30 -> V_150 = 0 ;
V_4 = F_103 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_154 & V_190 )
V_30 -> V_125 = 0 ;
if ( F_16 ( V_4 ) -> V_154 & V_167 ) {
F_16 ( V_4 ) -> V_154 &= ~ V_167 ;
V_30 -> V_163 -= F_76 ( V_4 ) ;
}
F_117 ( V_30 ) ;
V_30 -> V_110 = F_9 ( V_30 -> V_110 , F_63 ( V_30 ) + 1 ) ;
if ( F_123 ( V_30 ) && ( V_30 -> V_242 ||
( ( 1 << V_6 -> V_113 ) & ( V_247 | V_248 ) ) ) &&
F_47 ( V_30 -> V_129 , V_30 -> V_97 ) ) {
V_30 -> V_192 = V_30 -> V_129 ;
} else {
V_30 -> V_192 = V_30 -> V_99 ;
}
F_64 ( V_2 , V_243 ) ;
V_30 -> V_129 = V_30 -> V_99 ;
V_30 -> V_242 = 1 ;
}
static void F_129 ( struct V_1 * V_2 , int V_249 , int V_193 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
V_30 -> V_152 = 0 ;
V_30 -> V_163 = 0 ;
if ( F_70 ( V_30 ) )
F_122 ( V_30 ) ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_154 &= ~ V_155 ;
if ( ( V_30 -> V_242 == 1 ) && ! ( V_193 & V_250 ) ) {
if ( F_16 ( V_4 ) -> V_154 & V_167 )
V_30 -> V_163 += F_76 ( V_4 ) ;
V_193 |= V_250 ;
} else {
if ( F_16 ( V_4 ) -> V_154 & V_190 )
V_30 -> V_125 = 0 ;
F_16 ( V_4 ) -> V_154 &= ~ V_167 ;
}
if ( ! ( F_16 ( V_4 ) -> V_154 & V_156 ) ) {
F_16 ( V_4 ) -> V_154 |= V_155 ;
V_30 -> V_152 += F_76 ( V_4 ) ;
V_30 -> V_153 = F_16 ( V_4 ) -> V_85 ;
}
}
F_117 ( V_30 ) ;
V_30 -> V_110 = F_63 ( V_30 ) + V_249 ;
V_30 -> V_128 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_242 = 0 ;
V_30 -> V_123 = 0 ;
V_30 -> V_116 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_64 ( V_2 , V_235 ) ;
V_30 -> V_129 = V_30 -> V_99 ;
F_12 ( V_30 ) ;
F_130 ( V_30 ) ;
}
static void F_131 ( struct V_29 * V_30 )
{
V_30 -> V_163 = 0 ;
V_30 -> V_152 = 0 ;
V_30 -> V_125 = 0 ;
V_30 -> V_150 = 0 ;
}
void F_132 ( struct V_29 * V_30 )
{
F_131 ( V_30 ) ;
V_30 -> V_148 = 0 ;
V_30 -> V_149 = 0 ;
}
void F_133 ( struct V_1 * V_2 , int V_251 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_6 -> V_113 <= V_243 || V_30 -> V_97 == V_30 -> V_129 ||
( V_6 -> V_113 == V_235 && ! V_6 -> V_244 ) ) {
V_30 -> V_122 = F_127 ( V_2 ) ;
V_30 -> V_112 = V_6 -> V_126 -> V_127 ( V_2 ) ;
F_128 ( V_2 , V_252 ) ;
}
V_30 -> V_110 = 1 ;
V_30 -> V_128 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_123 = 0 ;
F_131 ( V_30 ) ;
if ( F_70 ( V_30 ) )
F_122 ( V_30 ) ;
if ( ! V_251 ) {
V_30 -> V_125 = V_30 -> V_97 ;
} else {
V_30 -> V_149 = 0 ;
V_30 -> V_148 = 0 ;
}
F_130 ( V_30 ) ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_154 & V_190 )
V_30 -> V_125 = 0 ;
F_16 ( V_4 ) -> V_154 &= ( ~ V_208 ) | V_156 ;
if ( ! ( F_16 ( V_4 ) -> V_154 & V_156 ) || V_251 ) {
F_16 ( V_4 ) -> V_154 &= ~ V_156 ;
F_16 ( V_4 ) -> V_154 |= V_155 ;
V_30 -> V_152 += F_76 ( V_4 ) ;
V_30 -> V_153 = F_16 ( V_4 ) -> V_85 ;
}
}
F_117 ( V_30 ) ;
V_30 -> V_116 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_64 ( V_2 , V_235 ) ;
V_30 -> V_129 = V_30 -> V_99 ;
F_12 ( V_30 ) ;
V_30 -> V_242 = 0 ;
}
static int F_134 ( struct V_1 * V_2 , int V_193 )
{
if ( V_193 & V_253 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_71 ( F_72 ( V_2 ) , V_254 ) ;
F_133 ( V_2 , 1 ) ;
V_6 -> V_244 ++ ;
F_135 ( V_2 , F_103 ( V_2 ) ) ;
F_136 ( V_2 , V_255 ,
V_6 -> V_91 , V_256 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_137 ( const struct V_29 * V_30 )
{
return F_70 ( V_30 ) ? V_30 -> V_149 + 1 : V_30 -> V_148 ;
}
static inline int F_138 ( const struct V_29 * V_30 )
{
return F_66 ( V_30 ) ? V_30 -> V_148 : V_30 -> V_149 + 1 ;
}
static inline int F_139 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_71 - F_16 ( V_4 ) -> V_257 > F_2 ( V_2 ) -> V_91 ;
}
static inline int F_140 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_228 &&
F_139 ( V_2 , F_103 ( V_2 ) ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_228 ;
if ( V_30 -> V_242 )
return 0 ;
if ( V_30 -> V_152 )
return 1 ;
if ( F_138 ( V_30 ) > V_30 -> V_116 )
return 1 ;
if ( F_66 ( V_30 ) && F_140 ( V_2 ) )
return 1 ;
V_228 = V_30 -> V_228 ;
if ( V_228 <= V_30 -> V_116 &&
V_30 -> V_149 >= F_28 ( T_2 , V_228 / 2 , V_117 ) &&
! F_142 ( V_2 ) ) {
return 1 ;
}
if ( ( V_30 -> V_258 || V_259 ) &&
F_143 ( V_30 ) && F_138 ( V_30 ) > 1 &&
F_144 ( V_30 ) && ! F_82 ( V_2 ) )
return 1 ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_66 ( V_30 ) || ! F_140 ( V_2 ) )
return;
V_4 = V_30 -> V_204 ;
if ( V_30 -> V_204 == NULL )
V_4 = F_103 ( V_2 ) ;
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( ! F_139 ( V_2 , V_4 ) )
break;
F_75 ( V_30 , V_4 ) ;
}
V_30 -> V_204 = V_4 ;
F_117 ( V_30 ) ;
}
static void F_146 ( struct V_1 * V_2 , int V_260 , int V_261 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_160 , V_262 ;
int V_182 ;
unsigned int V_58 ;
const T_1 V_263 = F_144 ( V_30 ) ? V_30 -> V_99 : V_30 -> V_129 ;
F_114 ( V_260 > V_30 -> V_228 ) ;
if ( V_30 -> V_130 ) {
V_4 = V_30 -> V_130 ;
V_160 = V_30 -> V_196 ;
if ( V_261 && V_4 != F_103 ( V_2 ) )
return;
} else {
V_4 = F_103 ( V_2 ) ;
V_160 = 0 ;
}
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
V_30 -> V_130 = V_4 ;
V_30 -> V_196 = V_160 ;
if ( F_47 ( F_16 ( V_4 ) -> V_85 , V_263 ) )
break;
V_262 = V_160 ;
if ( F_66 ( V_30 ) || F_70 ( V_30 ) ||
( F_16 ( V_4 ) -> V_154 & V_156 ) )
V_160 += F_76 ( V_4 ) ;
if ( V_160 > V_260 ) {
if ( ( F_144 ( V_30 ) && ! F_66 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_154 & V_156 ) ||
( V_262 >= V_260 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_182 = F_87 ( V_2 , V_4 , ( V_260 - V_262 ) * V_58 , V_58 ) ;
if ( V_182 < 0 )
break;
V_160 = V_260 ;
}
F_75 ( V_30 , V_4 ) ;
if ( V_261 )
break;
}
F_117 ( V_30 ) ;
}
static void F_147 ( struct V_1 * V_2 , int V_264 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_70 ( V_30 ) ) {
F_146 ( V_2 , 1 , 1 ) ;
} else if ( F_66 ( V_30 ) ) {
int V_265 = V_30 -> V_148 - V_30 -> V_116 ;
if ( V_265 <= 0 )
V_265 = 1 ;
F_146 ( V_2 , V_265 , 0 ) ;
} else {
int V_266 = V_30 -> V_149 - V_30 -> V_116 ;
if ( V_266 >= 0 )
F_146 ( V_2 , V_266 , 0 ) ;
else if ( V_264 )
F_146 ( V_2 , 1 , 1 ) ;
}
F_145 ( V_2 ) ;
}
static inline void F_148 ( struct V_29 * V_30 )
{
V_30 -> V_110 = F_9 ( V_30 -> V_110 ,
F_63 ( V_30 ) + F_149 ( V_30 ) ) ;
V_30 -> V_70 = V_71 ;
}
static inline T_1 F_150 ( const struct V_1 * V_2 )
{
const struct V_267 * V_268 = F_2 ( V_2 ) -> V_126 ;
return V_268 -> V_269 ? V_268 -> V_269 ( V_2 ) : F_7 ( V_2 ) -> V_112 ;
}
static void F_151 ( struct V_1 * V_2 , int V_193 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_270 = V_30 -> V_128 + 1 ;
if ( ( V_193 & ( V_271 | V_229 ) ) ||
( F_70 ( V_30 ) && ! ( V_193 & V_272 ) ) ) {
V_30 -> V_128 = V_270 & 1 ;
V_270 >>= 1 ;
if ( V_270 && V_30 -> V_110 > F_150 ( V_2 ) )
V_30 -> V_110 -= V_270 ;
V_30 -> V_110 = F_9 ( V_30 -> V_110 , F_63 ( V_30 ) + 1 ) ;
V_30 -> V_70 = V_71 ;
}
}
static inline int F_152 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_273 ||
( V_30 -> V_45 . V_274 && V_30 -> V_45 . V_84 &&
F_40 ( V_30 -> V_45 . V_84 , V_30 -> V_273 ) ) ;
}
static void F_153 ( struct V_1 * V_2 , const char * V_275 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_276 * V_277 = F_154 ( V_2 ) ;
if ( V_2 -> V_278 == V_279 ) {
F_73 ( V_147 L_2 ,
V_275 ,
& V_277 -> V_280 , F_155 ( V_277 -> V_281 ) ,
V_30 -> V_110 , F_156 ( V_30 ) ,
V_30 -> V_112 , V_30 -> V_122 ,
V_30 -> V_228 ) ;
}
#if F_157 ( V_282 )
else if ( V_2 -> V_278 == V_283 ) {
struct V_284 * V_285 = F_158 ( V_2 ) ;
F_73 ( V_147 L_3 ,
V_275 ,
& V_285 -> V_286 , F_155 ( V_277 -> V_281 ) ,
V_30 -> V_110 , F_156 ( V_30 ) ,
V_30 -> V_112 , V_30 -> V_122 ,
V_30 -> V_228 ) ;
}
#endif
}
static void F_159 ( struct V_1 * V_2 , const bool V_287 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_122 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_126 -> V_288 )
V_30 -> V_110 = V_6 -> V_126 -> V_288 ( V_2 ) ;
else
V_30 -> V_110 = F_31 ( V_30 -> V_110 , V_30 -> V_112 << 1 ) ;
if ( V_287 && V_30 -> V_122 > V_30 -> V_112 ) {
V_30 -> V_112 = V_30 -> V_122 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_110 = F_31 ( V_30 -> V_110 , V_30 -> V_112 ) ;
}
V_30 -> V_70 = V_71 ;
}
static inline int F_160 ( const struct V_29 * V_30 )
{
return V_30 -> V_125 && ( ! V_30 -> V_150 || F_152 ( V_30 ) ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_160 ( V_30 ) ) {
int V_140 ;
F_153 ( V_2 , F_2 ( V_2 ) -> V_113 == V_235 ? L_4 : L_5 ) ;
F_159 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_113 == V_235 )
V_140 = V_289 ;
else
V_140 = V_290 ;
F_71 ( F_72 ( V_2 ) , V_140 ) ;
V_30 -> V_125 = 0 ;
}
if ( V_30 -> V_97 == V_30 -> V_129 && F_70 ( V_30 ) ) {
F_148 ( V_30 ) ;
return 1 ;
}
F_64 ( V_2 , V_114 ) ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_125 && ! V_30 -> V_150 ) {
F_153 ( V_2 , L_6 ) ;
F_159 ( V_2 , true ) ;
V_30 -> V_125 = 0 ;
F_71 ( F_72 ( V_2 ) , V_291 ) ;
}
}
static int F_163 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_163 )
return 1 ;
V_4 = F_103 ( V_2 ) ;
if ( F_102 ( V_4 && F_16 ( V_4 ) -> V_154 & V_202 ) )
return 1 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , int V_238 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_292 = F_70 ( V_30 ) || ( F_137 ( V_30 ) > V_30 -> V_116 ) ;
if ( F_160 ( V_30 ) ) {
if ( ! F_163 ( V_2 ) )
V_30 -> V_273 = 0 ;
F_69 ( V_2 , F_137 ( V_30 ) + V_238 , 1 ) ;
F_153 ( V_2 , L_7 ) ;
F_159 ( V_2 , false ) ;
F_71 ( F_72 ( V_2 ) , V_293 ) ;
V_292 = 0 ;
}
return V_292 ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_160 ( V_30 ) ) {
struct V_3 * V_4 ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_154 &= ~ V_155 ;
}
F_130 ( V_30 ) ;
F_153 ( V_2 , L_8 ) ;
V_30 -> V_152 = 0 ;
F_159 ( V_2 , true ) ;
F_71 ( F_72 ( V_2 ) , V_289 ) ;
F_2 ( V_2 ) -> V_244 = 0 ;
V_30 -> V_125 = 0 ;
if ( F_144 ( V_30 ) )
F_64 ( V_2 , V_114 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_166 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_125 ) {
if ( F_2 ( V_2 ) -> V_113 == V_124 )
V_30 -> V_110 = F_9 ( V_30 -> V_110 , V_30 -> V_112 ) ;
else
V_30 -> V_110 = V_30 -> V_112 ;
V_30 -> V_70 = V_71 ;
}
F_128 ( V_2 , V_294 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_187 = V_114 ;
if ( F_156 ( V_30 ) || F_163 ( V_2 ) )
V_187 = V_243 ;
if ( F_2 ( V_2 ) -> V_113 != V_187 ) {
F_64 ( V_2 , V_187 ) ;
V_30 -> V_129 = V_30 -> V_99 ;
}
}
static void F_168 ( struct V_1 * V_2 , int V_193 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_117 ( V_30 ) ;
if ( ! V_30 -> V_242 && ! F_163 ( V_2 ) )
V_30 -> V_273 = 0 ;
if ( V_193 & V_295 )
F_62 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_113 != V_124 ) {
F_167 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_113 != V_114 )
F_148 ( V_30 ) ;
} else {
F_151 ( V_2 , V_193 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_240 . V_296 = V_6 -> V_240 . V_241 - 1 ;
V_6 -> V_240 . V_241 = 0 ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_122 = F_127 ( V_2 ) ;
V_30 -> V_110 = V_30 -> V_110 *
F_171 ( V_2 , V_30 -> V_297 ) /
V_6 -> V_240 . V_241 ;
V_30 -> V_128 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_112 = F_127 ( V_2 ) ;
V_6 -> V_240 . V_298 = V_6 -> V_240 . V_241 ;
V_6 -> V_240 . V_241 = 0 ;
F_172 ( V_2 , V_6 -> V_299 ) ;
}
void F_173 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_174 ( V_2 ) ;
T_1 V_300 = V_30 -> V_152 ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_96 ( V_4 ) > V_58 &&
! ( F_16 ( V_4 ) -> V_154 & V_156 ) ) {
if ( F_16 ( V_4 ) -> V_154 & V_167 ) {
F_16 ( V_4 ) -> V_154 &= ~ V_167 ;
V_30 -> V_163 -= F_76 ( V_4 ) ;
}
F_77 ( V_30 , V_4 ) ;
}
}
F_175 ( V_30 ) ;
if ( V_300 == V_30 -> V_152 )
return;
if ( F_70 ( V_30 ) )
F_118 ( V_30 ) ;
F_117 ( V_30 ) ;
if ( V_6 -> V_113 != V_235 ) {
V_30 -> V_129 = V_30 -> V_99 ;
V_30 -> V_112 = F_127 ( V_2 ) ;
V_30 -> V_122 = 0 ;
V_30 -> V_125 = 0 ;
F_64 ( V_2 , V_235 ) ;
}
F_176 ( V_2 ) ;
}
static void F_177 ( struct V_1 * V_2 , int V_301 ,
int V_264 , int V_193 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_302 = 0 ;
int V_303 = V_30 -> V_112 - F_63 ( V_30 ) ;
if ( F_63 ( V_30 ) > V_30 -> V_112 ) {
T_4 V_304 = ( T_4 ) V_30 -> V_112 * V_30 -> V_305 +
V_30 -> V_306 - 1 ;
V_302 = F_178 ( V_304 , V_30 -> V_306 ) - V_30 -> V_307 ;
} else {
V_302 = F_37 ( int , V_303 ,
F_28 ( int , V_30 -> V_305 - V_30 -> V_307 ,
V_301 ) + 1 ) ;
}
V_302 = F_31 ( V_302 , ( V_264 ? 1 : 0 ) ) ;
V_30 -> V_110 = F_63 ( V_30 ) + V_302 ;
}
static void F_179 ( struct V_1 * V_2 , int V_308 ,
int V_301 , bool V_309 ,
int V_193 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_310 = V_309 || ( ( V_193 & V_195 ) &&
( F_137 ( V_30 ) > V_30 -> V_116 ) ) ;
int V_264 = 0 , V_140 ;
if ( F_114 ( ! V_30 -> V_228 && V_30 -> V_149 ) )
V_30 -> V_149 = 0 ;
if ( F_114 ( ! V_30 -> V_149 && V_30 -> V_148 ) )
V_30 -> V_148 = 0 ;
if ( V_193 & V_295 )
V_30 -> V_122 = 0 ;
if ( F_134 ( V_2 , V_193 ) )
return;
F_117 ( V_30 ) ;
if ( V_6 -> V_113 == V_114 ) {
F_114 ( V_30 -> V_163 != 0 ) ;
V_30 -> V_273 = 0 ;
} else if ( ! F_40 ( V_30 -> V_97 , V_30 -> V_129 ) ) {
switch ( V_6 -> V_113 ) {
case V_235 :
V_6 -> V_244 = 0 ;
if ( F_161 ( V_2 ) )
return;
break;
case V_124 :
if ( V_30 -> V_97 != V_30 -> V_129 ) {
F_166 ( V_2 ) ;
F_64 ( V_2 , V_114 ) ;
}
break;
case V_165 :
if ( F_70 ( V_30 ) )
F_122 ( V_30 ) ;
if ( F_161 ( V_2 ) )
return;
F_166 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_113 ) {
case V_165 :
if ( ! ( V_193 & V_311 ) ) {
if ( F_70 ( V_30 ) && V_309 )
F_120 ( V_2 ) ;
} else
V_310 = F_164 ( V_2 , V_308 ) ;
break;
case V_235 :
if ( V_193 & V_250 )
V_6 -> V_244 = 0 ;
if ( F_70 ( V_30 ) && V_193 & V_311 )
F_122 ( V_30 ) ;
if ( ! F_165 ( V_2 ) ) {
F_148 ( V_30 ) ;
F_176 ( V_2 ) ;
return;
}
if ( V_6 -> V_113 != V_114 )
return;
default:
if ( F_70 ( V_30 ) ) {
if ( V_193 & V_311 )
F_122 ( V_30 ) ;
if ( V_309 )
F_120 ( V_2 ) ;
}
if ( V_6 -> V_113 <= V_243 )
F_162 ( V_2 ) ;
if ( ! F_141 ( V_2 ) ) {
F_168 ( V_2 , V_193 ) ;
return;
}
if ( V_6 -> V_113 < V_124 &&
V_6 -> V_240 . V_241 &&
V_30 -> V_97 == V_30 -> V_312 . V_313 ) {
F_169 ( V_2 ) ;
V_30 -> V_110 ++ ;
F_173 ( V_2 ) ;
return;
}
if ( F_70 ( V_30 ) )
V_140 = V_314 ;
else
V_140 = V_315 ;
F_71 ( F_72 ( V_2 ) , V_140 ) ;
V_30 -> V_129 = V_30 -> V_99 ;
V_30 -> V_122 = 0 ;
V_30 -> V_125 = V_30 -> V_97 ;
V_30 -> V_150 = V_30 -> V_163 ;
if ( V_6 -> V_113 < V_124 ) {
if ( ! ( V_193 & V_295 ) )
V_30 -> V_122 = F_127 ( V_2 ) ;
V_30 -> V_112 = V_6 -> V_126 -> V_127 ( V_2 ) ;
F_12 ( V_30 ) ;
}
V_30 -> V_123 = 0 ;
V_30 -> V_128 = 0 ;
V_30 -> V_306 = V_30 -> V_110 ;
V_30 -> V_305 = 0 ;
V_30 -> V_307 = 0 ;
F_64 ( V_2 , V_165 ) ;
V_264 = 1 ;
}
if ( V_310 || ( F_66 ( V_30 ) && F_140 ( V_2 ) ) )
F_147 ( V_2 , V_264 ) ;
V_30 -> V_305 += V_301 ;
F_177 ( V_2 , V_301 , V_264 , V_193 ) ;
F_176 ( V_2 ) ;
}
void F_180 ( struct V_1 * V_2 , T_1 V_316 )
{
F_46 ( V_2 , V_316 ) ;
F_49 ( V_2 ) ;
F_2 ( V_2 ) -> V_105 = 0 ;
}
static void F_181 ( struct V_1 * V_2 , int V_193 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_180 ( V_2 , V_71 - V_30 -> V_45 . V_84 ) ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_316 , int V_193 )
{
if ( V_193 & V_317 )
return;
F_180 ( V_2 , V_316 ) ;
}
static inline void F_183 ( struct V_1 * V_2 , const int V_193 ,
const T_5 V_316 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_274 && V_30 -> V_45 . V_84 )
F_181 ( V_2 , V_193 ) ;
else if ( V_316 >= 0 )
F_182 ( V_2 , V_316 , V_193 ) ;
}
static void F_184 ( struct V_1 * V_2 , T_1 V_318 , T_1 V_319 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_126 -> V_320 ( V_2 , V_318 , V_319 ) ;
F_7 ( V_2 ) -> V_70 = V_71 ;
}
static void F_185 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_228 ) {
F_186 ( V_2 , V_255 ) ;
} else {
F_136 ( V_2 , V_255 ,
F_2 ( V_2 ) -> V_91 , V_256 ) ;
}
}
static T_1 F_187 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_321 ;
F_91 ( ! F_47 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_97 ) ) ;
V_321 = F_76 ( V_4 ) ;
if ( F_188 ( V_2 , V_4 , V_30 -> V_97 - F_16 ( V_4 ) -> V_82 ) )
return 0 ;
V_321 -= F_76 ( V_4 ) ;
if ( V_321 ) {
F_91 ( F_76 ( V_4 ) == 0 ) ;
F_91 ( ! F_40 ( F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_85 ) ) ;
}
return V_321 ;
}
static int F_189 ( struct V_1 * V_2 , int V_322 ,
T_1 V_173 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_89 = V_71 ;
int V_323 = 1 ;
int V_193 = 0 ;
T_1 V_308 = 0 ;
T_1 V_191 = V_30 -> V_228 ;
T_1 V_324 = V_30 -> V_149 ;
T_5 V_316 = - 1 ;
T_5 V_325 = - 1 ;
T_6 V_326 = F_190 () ;
while ( ( V_4 = F_103 ( V_2 ) ) && V_4 != F_82 ( V_2 ) ) {
struct V_327 * V_328 = F_16 ( V_4 ) ;
T_1 V_329 ;
T_3 V_154 = V_328 -> V_154 ;
if ( F_47 ( V_328 -> V_85 , V_30 -> V_97 ) ) {
if ( F_76 ( V_4 ) == 1 ||
! F_47 ( V_30 -> V_97 , V_328 -> V_82 ) )
break;
V_329 = F_187 ( V_2 , V_4 ) ;
if ( ! V_329 )
break;
V_323 = 0 ;
} else {
V_329 = F_76 ( V_4 ) ;
}
if ( V_154 & V_190 ) {
if ( V_154 & V_167 )
V_30 -> V_163 -= V_329 ;
V_193 |= V_317 ;
V_325 = - 1 ;
V_316 = - 1 ;
if ( ( V_193 & V_250 ) || ( V_329 > 1 ) )
V_193 |= V_330 ;
} else {
V_325 = V_89 - V_328 -> V_257 ;
V_326 = V_4 -> V_331 ;
if ( V_316 < 0 ) {
V_316 = V_325 ;
}
if ( ! ( V_154 & V_156 ) )
V_191 = F_9 ( V_308 , V_191 ) ;
}
if ( V_154 & V_156 )
V_30 -> V_149 -= V_329 ;
if ( V_154 & V_155 )
V_30 -> V_152 -= V_329 ;
V_30 -> V_228 -= V_329 ;
V_308 += V_329 ;
if ( ! ( V_328 -> V_205 & V_332 ) ) {
V_193 |= V_250 ;
} else {
V_193 |= V_333 ;
V_30 -> V_273 = 0 ;
}
if ( ! V_323 )
break;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
V_30 -> V_204 = NULL ;
if ( V_4 == V_30 -> V_151 )
V_30 -> V_151 = NULL ;
if ( V_4 == V_30 -> V_130 )
V_30 -> V_130 = NULL ;
}
if ( F_191 ( F_192 ( V_30 -> V_334 , V_173 , V_30 -> V_97 ) ) )
V_30 -> V_334 = V_30 -> V_97 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_154 & V_156 ) )
V_193 |= V_253 ;
if ( V_193 & V_335 ) {
const struct V_267 * V_268
= F_2 ( V_2 ) -> V_126 ;
if ( F_102 ( V_6 -> V_240 . V_241 &&
! F_47 ( V_30 -> V_312 . V_336 , V_30 -> V_97 ) ) ) {
F_170 ( V_2 ) ;
}
F_183 ( V_2 , V_193 , V_316 ) ;
F_185 ( V_2 ) ;
if ( F_70 ( V_30 ) ) {
F_121 ( V_2 , V_308 ) ;
} else {
int V_303 ;
if ( V_191 < V_322 )
F_69 ( V_2 , V_30 -> V_148 - V_191 , 0 ) ;
V_303 = F_66 ( V_30 ) ? V_308 :
V_324 - V_30 -> V_149 ;
V_30 -> V_196 -= F_9 ( V_30 -> V_196 , V_303 ) ;
}
V_30 -> V_148 -= F_9 ( V_308 , V_30 -> V_148 ) ;
if ( V_268 -> V_308 ) {
T_5 V_337 = - 1 ;
if ( ! ( V_193 & V_317 ) ) {
if ( V_268 -> V_103 & V_338 &&
! F_193 ( V_326 ,
F_190 () ) )
V_337 = F_194 ( F_195 () ,
V_326 ) ;
else if ( V_325 >= 0 )
V_337 = F_196 ( V_325 ) ;
}
V_268 -> V_308 ( V_2 , V_308 , V_337 ) ;
}
}
#if V_146 > 0
F_114 ( ( int ) V_30 -> V_149 < 0 ) ;
F_114 ( ( int ) V_30 -> V_152 < 0 ) ;
F_114 ( ( int ) V_30 -> V_163 < 0 ) ;
if ( ! V_30 -> V_228 && F_144 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_152 ) {
F_73 ( V_147 L_9 ,
V_30 -> V_152 , V_6 -> V_113 ) ;
V_30 -> V_152 = 0 ;
}
if ( V_30 -> V_149 ) {
F_73 ( V_147 L_10 ,
V_30 -> V_149 , V_6 -> V_113 ) ;
V_30 -> V_149 = 0 ;
}
if ( V_30 -> V_163 ) {
F_73 ( V_147 L_11 ,
V_30 -> V_163 , V_6 -> V_113 ) ;
V_30 -> V_163 = 0 ;
}
}
#endif
return V_193 ;
}
static void F_197 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_47 ( F_16 ( F_82 ( V_2 ) ) -> V_85 , F_198 ( V_30 ) ) ) {
V_6 -> V_105 = 0 ;
F_186 ( V_2 , V_339 ) ;
} else {
F_136 ( V_2 , V_339 ,
F_9 ( V_6 -> V_91 << V_6 -> V_105 , V_256 ) ,
V_256 ) ;
}
}
static inline int F_199 ( const struct V_1 * V_2 , const int V_193 )
{
return ! ( V_193 & V_272 ) || ( V_193 & V_340 ) ||
F_2 ( V_2 ) -> V_113 != V_114 ;
}
static inline int F_200 ( const struct V_1 * V_2 , const int V_193 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_193 & V_295 ) || V_30 -> V_110 < V_30 -> V_112 ) &&
! ( ( 1 << F_2 ( V_2 ) -> V_113 ) & ( V_247 | V_341 ) ) ;
}
static inline int F_201 ( const struct V_29 * V_30 ,
const T_1 V_318 , const T_1 V_166 ,
const T_1 V_342 )
{
return F_47 ( V_318 , V_30 -> V_97 ) ||
F_47 ( V_166 , V_30 -> V_343 ) ||
( V_166 == V_30 -> V_343 && V_342 > V_30 -> V_344 ) ;
}
static int F_202 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_318 ,
T_1 V_166 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_193 = 0 ;
T_1 V_342 = F_155 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_191 ( ! F_6 ( V_4 ) -> V_43 ) )
V_342 <<= V_30 -> V_45 . V_345 ;
if ( F_201 ( V_30 , V_318 , V_166 , V_342 ) ) {
V_193 |= V_346 ;
F_203 ( V_30 , V_166 ) ;
if ( V_30 -> V_344 != V_342 ) {
V_30 -> V_344 = V_342 ;
V_30 -> V_347 = 0 ;
F_204 ( V_2 ) ;
if ( V_342 > V_30 -> V_159 ) {
V_30 -> V_159 = V_342 ;
F_172 ( V_2 , F_2 ( V_2 ) -> V_299 ) ;
}
}
}
V_30 -> V_97 = V_318 ;
return V_193 ;
}
static void F_205 ( struct V_29 * V_30 )
{
V_30 -> V_110 = F_9 ( V_30 -> V_110 , V_30 -> V_112 ) ;
V_30 -> V_128 = 0 ;
V_30 -> V_123 = 0 ;
F_12 ( V_30 ) ;
F_148 ( V_30 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
F_62 ( V_2 , 0 ) ;
}
static void F_207 ( struct V_1 * V_2 , int V_193 )
{
if ( V_193 & V_295 )
F_206 ( V_2 ) ;
else
F_159 ( V_2 , true ) ;
}
static int F_208 ( struct V_1 * V_2 , int V_193 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_117 ( V_30 ) ;
if ( V_193 & V_250 )
F_2 ( V_2 ) -> V_244 = 0 ;
if ( ( V_193 & V_330 ) ||
( ( V_30 -> V_242 >= 2 ) && ( V_193 & V_317 ) ) )
V_30 -> V_125 = 0 ;
if ( ! F_40 ( V_30 -> V_97 , V_30 -> V_192 ) ) {
F_129 ( V_2 , ( V_30 -> V_242 == 1 ? 2 : 3 ) , V_193 ) ;
return 1 ;
}
if ( ! F_123 ( V_30 ) ) {
if ( ! ( V_193 & V_271 ) && ( V_193 & V_272 ) )
return 1 ;
if ( ! ( V_193 & V_250 ) ) {
F_129 ( V_2 , ( V_30 -> V_242 == 1 ? 0 : 3 ) ,
V_193 ) ;
return 1 ;
}
} else {
if ( ! ( V_193 & V_250 ) && ( V_30 -> V_242 == 1 ) ) {
V_30 -> V_110 = F_9 ( V_30 -> V_110 ,
F_63 ( V_30 ) ) ;
return 1 ;
}
if ( ( V_30 -> V_242 >= 2 ) &&
( ! ( V_193 & V_348 ) ||
( ( V_193 & V_195 ) &&
! ( V_193 & V_194 ) ) ) ) {
if ( ! ( V_193 & V_348 ) &&
( V_193 & V_272 ) )
return 1 ;
F_129 ( V_2 , 3 , V_193 ) ;
return 1 ;
}
}
if ( V_30 -> V_242 == 1 ) {
V_30 -> V_110 = F_63 ( V_30 ) + 2 ;
V_30 -> V_242 = 2 ;
if ( ! F_142 ( V_2 ) )
F_129 ( V_2 , 2 , V_193 ) ;
return 1 ;
} else {
switch ( V_349 ) {
case 2 :
F_207 ( V_2 , V_193 ) ;
break;
case 1 :
F_205 ( V_30 ) ;
break;
default:
F_206 ( V_2 ) ;
break;
}
V_30 -> V_242 = 0 ;
V_30 -> V_125 = 0 ;
F_71 ( F_72 ( V_2 ) , V_350 ) ;
}
return 0 ;
}
static int F_209 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_193 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_173 = V_30 -> V_97 ;
T_1 V_166 = F_16 ( V_4 ) -> V_82 ;
T_1 V_318 = F_16 ( V_4 ) -> V_166 ;
bool V_309 = false ;
T_1 V_351 ;
T_1 V_322 ;
int V_352 ;
int V_324 = V_30 -> V_149 ;
int V_308 = 0 ;
int V_301 = 0 ;
int V_353 = 0 ;
if ( F_40 ( V_318 , V_173 ) )
goto V_354;
if ( F_47 ( V_318 , V_30 -> V_99 ) )
goto V_355;
if ( F_47 ( V_318 , V_173 ) )
V_193 |= V_311 ;
if ( V_356 ) {
if ( V_6 -> V_113 < V_124 )
V_30 -> V_123 += V_318 - V_173 ;
else if ( V_6 -> V_113 == V_235 )
V_30 -> V_123 += F_9 ( V_318 - V_173 ,
V_30 -> V_297 ) ;
}
V_322 = V_30 -> V_148 ;
V_351 = F_63 ( V_30 ) ;
if ( ! ( V_193 & V_357 ) && F_47 ( V_318 , V_173 ) ) {
F_203 ( V_30 , V_166 ) ;
V_30 -> V_97 = V_318 ;
V_193 |= V_346 ;
F_128 ( V_2 , V_358 ) ;
F_71 ( F_72 ( V_2 ) , V_359 ) ;
} else {
if ( V_166 != F_16 ( V_4 ) -> V_85 )
V_193 |= V_360 ;
else
F_71 ( F_72 ( V_2 ) , V_361 ) ;
V_193 |= F_202 ( V_2 , V_4 , V_318 , V_166 ) ;
if ( F_16 ( V_4 ) -> V_154 )
V_193 |= F_113 ( V_2 , V_4 , V_173 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_193 |= V_295 ;
F_128 ( V_2 , V_362 ) ;
}
V_2 -> V_363 = 0 ;
V_6 -> V_364 = 0 ;
V_30 -> V_365 = V_71 ;
V_352 = V_30 -> V_228 ;
if ( ! V_352 )
goto V_366;
V_193 |= F_189 ( V_2 , V_322 , V_173 ) ;
V_308 = V_352 - V_30 -> V_228 ;
V_301 = ( V_352 - V_324 ) -
( V_30 -> V_228 - V_30 -> V_149 ) ;
if ( V_30 -> V_242 )
V_353 = F_208 ( V_2 , V_193 ) ;
if ( F_40 ( V_30 -> V_192 , V_30 -> V_97 ) )
V_30 -> V_192 = 0 ;
if ( F_199 ( V_2 , V_193 ) ) {
if ( ( V_193 & V_250 ) && ! V_353 &&
F_200 ( V_2 , V_193 ) )
F_184 ( V_2 , V_318 , V_351 ) ;
V_309 = ! ( V_193 & ( V_311 | V_272 ) ) ;
F_179 ( V_2 , V_308 , V_301 ,
V_309 , V_193 ) ;
} else {
if ( ( V_193 & V_250 ) && ! V_353 )
F_184 ( V_2 , V_318 , V_351 ) ;
}
if ( ( V_193 & V_348 ) || ! ( V_193 & V_272 ) )
F_54 ( F_53 ( V_2 ) ) ;
return 1 ;
V_366:
if ( V_193 & V_229 )
F_179 ( V_2 , V_308 , V_301 ,
V_309 , V_193 ) ;
if ( F_82 ( V_2 ) )
F_197 ( V_2 ) ;
return 1 ;
V_355:
F_210 ( V_2 , L_12 , V_318 , V_30 -> V_97 , V_30 -> V_99 ) ;
return - 1 ;
V_354:
if ( F_16 ( V_4 ) -> V_154 ) {
V_193 |= F_113 ( V_2 , V_4 , V_173 ) ;
V_301 = V_30 -> V_149 - V_324 ;
F_179 ( V_2 , V_308 , V_301 ,
V_309 , V_193 ) ;
}
F_210 ( V_2 , L_13 , V_318 , V_30 -> V_97 , V_30 -> V_99 ) ;
return 0 ;
}
void F_211 ( const struct V_3 * V_4 , struct V_367 * V_368 ,
const T_3 * * V_369 , int V_370 )
{
const unsigned char * V_219 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_371 = ( V_41 -> V_372 * 4 ) - sizeof( struct V_15 ) ;
V_219 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_368 -> V_274 = 0 ;
while ( V_371 > 0 ) {
int V_373 = * V_219 ++ ;
int V_374 ;
switch ( V_373 ) {
case V_375 :
return;
case V_376 :
V_371 -- ;
continue;
default:
V_374 = * V_219 ++ ;
if ( V_374 < 2 )
return;
if ( V_374 > V_371 )
return;
switch ( V_373 ) {
case V_377 :
if ( V_374 == V_378 && V_41 -> V_43 && ! V_370 ) {
T_7 V_379 = F_212 ( V_219 ) ;
if ( V_379 ) {
if ( V_368 -> V_380 &&
V_368 -> V_380 < V_379 )
V_379 = V_368 -> V_380 ;
V_368 -> V_46 = V_379 ;
}
}
break;
case V_381 :
if ( V_374 == V_382 && V_41 -> V_43 &&
! V_370 && V_383 ) {
T_8 V_345 = * ( T_8 * ) V_219 ;
V_368 -> V_384 = 1 ;
if ( V_345 > 14 ) {
if ( F_213 () )
F_73 ( V_385 L_14
L_15 ,
V_345 ) ;
V_345 = 14 ;
}
V_368 -> V_345 = V_345 ;
}
break;
case V_386 :
if ( ( V_374 == V_387 ) &&
( ( V_370 && V_368 -> V_388 ) ||
( ! V_370 && V_389 ) ) ) {
V_368 -> V_274 = 1 ;
V_368 -> V_390 = F_84 ( V_219 ) ;
V_368 -> V_84 = F_84 ( V_219 + 4 ) ;
}
break;
case V_391 :
if ( V_374 == V_392 && V_41 -> V_43 &&
! V_370 && V_393 ) {
V_368 -> V_131 = V_394 ;
F_214 ( V_368 ) ;
}
break;
case V_395 :
if ( ( V_374 >= ( V_222 + V_396 ) ) &&
! ( ( V_374 - V_222 ) % V_396 ) &&
V_368 -> V_131 ) {
F_16 ( V_4 ) -> V_154 = ( V_219 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_215
case V_397 :
break;
#endif
case V_398 :
switch ( V_374 ) {
case V_399 :
break;
case V_400 :
break;
case V_401 + 0 :
case V_401 + 2 :
case V_401 + 4 :
case V_401 + 6 :
case V_402 :
V_368 -> V_403 = V_374 ;
* V_369 = V_219 ;
break;
default:
break;
}
break;
}
V_219 += V_374 - 2 ;
V_371 -= V_374 ;
}
}
}
static int F_216 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_219 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_219 == F_217 ( ( V_376 << 24 ) | ( V_376 << 16 )
| ( V_386 << 8 ) | V_387 ) ) {
V_30 -> V_45 . V_274 = 1 ;
++ V_219 ;
V_30 -> V_45 . V_390 = F_218 ( * V_219 ) ;
++ V_219 ;
V_30 -> V_45 . V_84 = F_218 ( * V_219 ) ;
return 1 ;
}
return 0 ;
}
static int F_219 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 ,
struct V_29 * V_30 , const T_3 * * V_369 )
{
if ( V_41 -> V_372 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_274 = 0 ;
return 0 ;
} else if ( V_30 -> V_45 . V_388 &&
V_41 -> V_372 == ( ( sizeof( * V_41 ) + V_404 ) / 4 ) ) {
if ( F_216 ( V_30 , V_41 ) )
return 1 ;
}
F_211 ( V_4 , & V_30 -> V_45 , V_369 , 1 ) ;
return 1 ;
}
const T_3 * F_220 ( const struct V_15 * V_41 )
{
int V_371 = ( V_41 -> V_372 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_219 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_371 < V_405 )
return NULL ;
while ( V_371 > 0 ) {
int V_373 = * V_219 ++ ;
int V_374 ;
switch( V_373 ) {
case V_375 :
return NULL ;
case V_376 :
V_371 -- ;
continue;
default:
V_374 = * V_219 ++ ;
if ( V_374 < 2 || V_374 > V_371 )
return NULL ;
if ( V_373 == V_397 )
return V_374 == V_405 ? V_219 : NULL ;
}
V_219 += V_374 - 2 ;
V_371 -= V_374 ;
}
return NULL ;
}
static inline void F_221 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_406 = V_30 -> V_45 . V_390 ;
V_30 -> V_45 . V_407 = F_222 () ;
}
static inline void F_223 ( struct V_29 * V_30 , T_1 V_82 )
{
if ( V_30 -> V_45 . V_274 && ! F_47 ( V_82 , V_30 -> V_408 ) ) {
if ( F_224 ( & V_30 -> V_45 , 0 ) )
F_221 ( V_30 ) ;
}
}
static int F_225 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
T_1 V_318 = F_16 ( V_4 ) -> V_166 ;
return (
( V_41 -> V_318 && V_82 == F_16 ( V_4 ) -> V_85 && V_82 == V_30 -> V_81 ) &&
V_318 == V_30 -> V_97 &&
! F_201 ( V_30 , V_318 , V_82 , F_155 ( V_41 -> V_52 ) << V_30 -> V_45 . V_345 ) &&
( T_5 ) ( V_30 -> V_45 . V_406 - V_30 -> V_45 . V_390 ) <= ( F_2 ( V_2 ) -> V_91 * 1024 ) / V_409 ) ;
}
static inline int F_226 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_224 ( & V_30 -> V_45 , V_410 ) &&
! F_225 ( V_2 , V_4 ) ;
}
static inline int F_227 ( const struct V_29 * V_30 , T_1 V_82 , T_1 V_85 )
{
return ! F_40 ( V_85 , V_30 -> V_408 ) &&
! F_47 ( V_82 , V_30 -> V_81 + F_228 ( V_30 ) ) ;
}
static void F_229 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_411 ) {
case V_412 :
V_2 -> V_413 = V_414 ;
break;
case V_415 :
V_2 -> V_413 = V_416 ;
break;
case V_417 :
return;
default:
V_2 -> V_413 = V_418 ;
}
F_230 () ;
if ( ! F_231 ( V_2 , V_419 ) )
V_2 -> V_420 ( V_2 ) ;
F_232 ( V_2 ) ;
}
static void F_233 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_421 |= V_422 ;
F_234 ( V_2 , V_423 ) ;
switch ( V_2 -> V_411 ) {
case V_424 :
case V_425 :
F_235 ( V_2 , V_415 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_415 :
case V_426 :
break;
case V_427 :
break;
case V_428 :
F_236 ( V_2 ) ;
F_235 ( V_2 , V_426 ) ;
break;
case V_429 :
F_236 ( V_2 ) ;
F_237 ( V_2 , V_430 , 0 ) ;
break;
default:
F_73 ( V_431 L_16 ,
V_432 , V_2 -> V_411 ) ;
break;
}
F_238 ( & V_30 -> V_433 ) ;
if ( F_144 ( V_30 ) )
F_214 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
if ( ! F_231 ( V_2 , V_419 ) ) {
V_2 -> V_434 ( V_2 ) ;
if ( V_2 -> V_421 == V_435 ||
V_2 -> V_411 == V_417 )
F_239 ( V_2 , V_436 , V_437 ) ;
else
F_239 ( V_2 , V_436 , V_438 ) ;
}
}
static inline int F_240 ( struct V_212 * V_171 , T_1 V_82 ,
T_1 V_85 )
{
if ( ! F_47 ( V_82 , V_171 -> V_85 ) && ! F_47 ( V_171 -> V_158 , V_85 ) ) {
if ( F_40 ( V_82 , V_171 -> V_158 ) )
V_171 -> V_158 = V_82 ;
if ( F_47 ( V_85 , V_171 -> V_85 ) )
V_171 -> V_85 = V_85 ;
return 1 ;
}
return 0 ;
}
static void F_241 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_85 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_144 ( V_30 ) && V_439 ) {
int V_140 ;
if ( F_40 ( V_82 , V_30 -> V_81 ) )
V_140 = V_440 ;
else
V_140 = V_441 ;
F_71 ( F_72 ( V_2 ) , V_140 ) ;
V_30 -> V_45 . V_442 = 1 ;
V_30 -> V_443 [ 0 ] . V_158 = V_82 ;
V_30 -> V_443 [ 0 ] . V_85 = V_85 ;
}
}
static void F_242 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_85 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_442 )
F_241 ( V_2 , V_82 , V_85 ) ;
else
F_240 ( V_30 -> V_443 , V_82 , V_85 ) ;
}
static void F_243 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_85 != F_16 ( V_4 ) -> V_82 &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_71 ( F_72 ( V_2 ) , V_444 ) ;
F_10 ( V_2 ) ;
if ( F_144 ( V_30 ) && V_439 ) {
T_1 V_85 = F_16 ( V_4 ) -> V_85 ;
if ( F_47 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_81 ) )
V_85 = V_30 -> V_81 ;
F_241 ( V_2 , F_16 ( V_4 ) -> V_82 , V_85 ) ;
}
}
F_236 ( V_2 ) ;
}
static void F_244 ( struct V_29 * V_30 )
{
int V_445 ;
struct V_212 * V_171 = & V_30 -> V_446 [ 0 ] ;
struct V_212 * V_447 = V_171 + 1 ;
for ( V_445 = 1 ; V_445 < V_30 -> V_45 . V_172 ; ) {
if ( F_240 ( V_171 , V_447 -> V_158 , V_447 -> V_85 ) ) {
int V_225 ;
V_30 -> V_45 . V_172 -- ;
for ( V_225 = V_445 ; V_225 < V_30 -> V_45 . V_172 ; V_225 ++ )
V_171 [ V_225 ] = V_171 [ V_225 + 1 ] ;
continue;
}
V_445 ++ , V_447 ++ ;
}
}
static void F_245 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_85 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_212 * V_171 = & V_30 -> V_446 [ 0 ] ;
int V_448 = V_30 -> V_45 . V_172 ;
int V_445 ;
if ( ! V_448 )
goto V_449;
for ( V_445 = 0 ; V_445 < V_448 ; V_445 ++ , V_171 ++ ) {
if ( F_240 ( V_171 , V_82 , V_85 ) ) {
for (; V_445 > 0 ; V_445 -- , V_171 -- )
F_116 ( * V_171 , * ( V_171 - 1 ) ) ;
if ( V_448 > 1 )
F_244 ( V_30 ) ;
return;
}
}
if ( V_445 >= V_221 ) {
V_445 -- ;
V_30 -> V_45 . V_172 -- ;
V_171 -- ;
}
for (; V_445 > 0 ; V_445 -- , V_171 -- )
* V_171 = * ( V_171 - 1 ) ;
V_449:
V_171 -> V_158 = V_82 ;
V_171 -> V_85 = V_85 ;
V_30 -> V_45 . V_172 ++ ;
}
static void F_246 ( struct V_29 * V_30 )
{
struct V_212 * V_171 = & V_30 -> V_446 [ 0 ] ;
int V_172 = V_30 -> V_45 . V_172 ;
int V_445 ;
if ( F_247 ( & V_30 -> V_433 ) ) {
V_30 -> V_45 . V_172 = 0 ;
return;
}
for ( V_445 = 0 ; V_445 < V_172 ; ) {
if ( ! F_40 ( V_30 -> V_81 , V_171 -> V_158 ) ) {
int V_225 ;
F_114 ( F_40 ( V_30 -> V_81 , V_171 -> V_85 ) ) ;
for ( V_225 = V_445 + 1 ; V_225 < V_172 ; V_225 ++ )
V_30 -> V_446 [ V_225 - 1 ] = V_30 -> V_446 [ V_225 ] ;
V_172 -- ;
continue;
}
V_445 ++ ;
V_171 ++ ;
}
V_30 -> V_45 . V_172 = V_172 ;
}
static void F_248 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_450 = V_30 -> V_81 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_249 ( & V_30 -> V_433 ) ) != NULL ) {
if ( F_47 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_450 ) ) {
T_2 V_442 = V_450 ;
if ( F_40 ( F_16 ( V_4 ) -> V_85 , V_450 ) )
V_450 = F_16 ( V_4 ) -> V_85 ;
F_242 ( V_2 , F_16 ( V_4 ) -> V_82 , V_442 ) ;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_81 ) ) {
F_210 ( V_2 , L_17 ) ;
F_250 ( V_4 , & V_30 -> V_433 ) ;
F_251 ( V_4 ) ;
continue;
}
F_210 ( V_2 , L_18 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_85 ) ;
F_250 ( V_4 , & V_30 -> V_433 ) ;
F_252 ( & V_2 -> V_451 , V_4 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_85 ;
if ( F_6 ( V_4 ) -> V_452 )
F_233 ( V_2 ) ;
}
}
static inline int F_253 ( struct V_1 * V_2 , unsigned int V_453 )
{
if ( F_35 ( & V_2 -> V_72 ) > V_2 -> V_62 ||
! F_254 ( V_2 , V_453 ) ) {
if ( F_255 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_254 ( V_2 , V_453 ) ) {
if ( ! F_256 ( V_2 ) )
return - 1 ;
if ( ! F_254 ( V_2 , V_453 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_257 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_454 = - 1 ;
if ( F_16 ( V_4 ) -> V_82 == F_16 ( V_4 ) -> V_85 )
goto V_455;
F_258 ( V_4 ) ;
F_259 ( V_4 , V_41 -> V_372 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_442 = 0 ;
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 ) {
if ( F_228 ( V_30 ) == 0 )
goto V_456;
if ( V_30 -> V_457 . V_458 == V_459 &&
V_30 -> V_86 == V_30 -> V_81 && V_30 -> V_457 . V_10 &&
F_260 ( V_2 ) && ! V_30 -> V_460 ) {
int V_461 = F_37 (unsigned int, skb->len,
tp->ucopy.len) ;
F_261 ( V_462 ) ;
F_262 () ;
if ( ! F_263 ( V_4 , 0 , V_30 -> V_457 . V_463 , V_461 ) ) {
V_30 -> V_457 . V_10 -= V_461 ;
V_30 -> V_86 += V_461 ;
V_454 = ( V_461 == V_4 -> V_10 ) ;
F_42 ( V_2 ) ;
}
F_264 () ;
}
if ( V_454 <= 0 ) {
V_464:
if ( V_454 < 0 &&
F_253 ( V_2 , V_4 -> V_51 ) )
goto V_455;
F_265 ( V_4 , V_2 ) ;
F_252 ( & V_2 -> V_451 , V_4 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_85 ;
if ( V_4 -> V_10 )
F_43 ( V_2 , V_4 ) ;
if ( V_41 -> V_452 )
F_233 ( V_2 ) ;
if ( ! F_247 ( & V_30 -> V_433 ) ) {
F_248 ( V_2 ) ;
if ( F_247 ( & V_30 -> V_433 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_172 )
F_246 ( V_30 ) ;
F_204 ( V_2 ) ;
if ( V_454 > 0 )
F_251 ( V_4 ) ;
else if ( ! F_231 ( V_2 , V_419 ) )
V_2 -> V_465 ( V_2 , 0 ) ;
return;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_85 , V_30 -> V_81 ) ) {
F_71 ( F_72 ( V_2 ) , V_444 ) ;
F_241 ( V_2 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_85 ) ;
V_456:
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
V_455:
F_251 ( V_4 ) ;
return;
}
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 + F_228 ( V_30 ) ) )
goto V_456;
F_10 ( V_2 ) ;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_210 ( V_2 , L_19 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_85 ) ;
F_241 ( V_2 , F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ;
if ( ! F_228 ( V_30 ) )
goto V_456;
goto V_464;
}
F_15 ( V_30 , V_4 ) ;
if ( F_253 ( V_2 , V_4 -> V_51 ) )
goto V_455;
V_30 -> V_347 = 0 ;
F_44 ( V_2 ) ;
F_210 ( V_2 , L_20 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_85 ) ;
F_265 ( V_4 , V_2 ) ;
if ( ! F_249 ( & V_30 -> V_433 ) ) {
if ( F_144 ( V_30 ) ) {
V_30 -> V_45 . V_172 = 1 ;
V_30 -> V_446 [ 0 ] . V_158 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_446 [ 0 ] . V_85 =
F_16 ( V_4 ) -> V_85 ;
}
F_266 ( & V_30 -> V_433 , V_4 ) ;
} else {
struct V_3 * V_466 = F_267 ( & V_30 -> V_433 ) ;
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
T_1 V_85 = F_16 ( V_4 ) -> V_85 ;
if ( V_82 == F_16 ( V_466 ) -> V_85 ) {
F_268 ( & V_30 -> V_433 , V_466 , V_4 ) ;
if ( ! V_30 -> V_45 . V_172 ||
V_30 -> V_446 [ 0 ] . V_85 != V_82 )
goto V_467;
V_30 -> V_446 [ 0 ] . V_85 = V_85 ;
return;
}
while ( 1 ) {
if ( ! F_47 ( F_16 ( V_466 ) -> V_82 , V_82 ) )
break;
if ( F_269 ( & V_30 -> V_433 , V_466 ) ) {
V_466 = NULL ;
break;
}
V_466 = F_270 ( & V_30 -> V_433 , V_466 ) ;
}
if ( V_466 && F_40 ( V_82 , F_16 ( V_466 ) -> V_85 ) ) {
if ( ! F_47 ( V_85 , F_16 ( V_466 ) -> V_85 ) ) {
F_251 ( V_4 ) ;
F_241 ( V_2 , V_82 , V_85 ) ;
goto V_467;
}
if ( F_47 ( V_82 , F_16 ( V_466 ) -> V_82 ) ) {
F_241 ( V_2 , V_82 ,
F_16 ( V_466 ) -> V_85 ) ;
} else {
if ( F_269 ( & V_30 -> V_433 ,
V_466 ) )
V_466 = NULL ;
else
V_466 = F_270 (
& V_30 -> V_433 ,
V_466 ) ;
}
}
if ( ! V_466 )
F_266 ( & V_30 -> V_433 , V_4 ) ;
else
F_268 ( & V_30 -> V_433 , V_466 , V_4 ) ;
while ( ! F_271 ( & V_30 -> V_433 , V_4 ) ) {
V_466 = F_272 ( & V_30 -> V_433 , V_4 ) ;
if ( ! F_47 ( V_85 , F_16 ( V_466 ) -> V_82 ) )
break;
if ( F_40 ( V_85 , F_16 ( V_466 ) -> V_85 ) ) {
F_242 ( V_2 , F_16 ( V_466 ) -> V_82 ,
V_85 ) ;
break;
}
F_250 ( V_466 , & V_30 -> V_433 ) ;
F_242 ( V_2 , F_16 ( V_466 ) -> V_82 ,
F_16 ( V_466 ) -> V_85 ) ;
F_251 ( V_466 ) ;
}
V_467:
if ( F_144 ( V_30 ) )
F_245 ( V_2 , V_82 , V_85 ) ;
}
}
static struct V_3 * F_273 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_468 * V_469 )
{
struct V_3 * V_470 = NULL ;
if ( ! F_271 ( V_469 , V_4 ) )
V_470 = F_272 ( V_469 , V_4 ) ;
F_250 ( V_4 , V_469 ) ;
F_251 ( V_4 ) ;
F_71 ( F_72 ( V_2 ) , V_471 ) ;
return V_470 ;
}
static void
F_274 ( struct V_1 * V_2 , struct V_468 * V_469 ,
struct V_3 * V_472 , struct V_3 * V_473 ,
T_1 V_474 , T_1 V_475 )
{
struct V_3 * V_4 , * V_476 ;
bool V_477 ;
V_4 = V_472 ;
V_478:
V_477 = true ;
F_275 (list, skb, n) {
if ( V_4 == V_473 )
break;
if ( ! F_40 ( V_474 , F_16 ( V_4 ) -> V_85 ) ) {
V_4 = F_273 ( V_2 , V_4 , V_469 ) ;
if ( ! V_4 )
break;
goto V_478;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_452 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_40 ( F_16 ( V_4 ) -> V_82 , V_474 ) ) ) {
V_477 = false ;
break;
}
if ( ! F_271 ( V_469 , V_4 ) ) {
struct V_3 * V_470 = F_272 ( V_469 , V_4 ) ;
if ( V_470 != V_473 &&
F_16 ( V_4 ) -> V_85 != F_16 ( V_470 ) -> V_82 ) {
V_477 = false ;
break;
}
}
V_474 = F_16 ( V_4 ) -> V_85 ;
}
if ( V_477 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_452 )
return;
while ( F_40 ( V_474 , V_475 ) ) {
struct V_3 * V_479 ;
unsigned int V_480 = F_276 ( V_4 ) ;
int V_481 = F_277 ( V_480 , 0 ) ;
if ( V_481 < 0 )
return;
if ( V_475 - V_474 < V_481 )
V_481 = V_475 - V_474 ;
V_479 = F_278 ( V_481 + V_480 , V_482 ) ;
if ( ! V_479 )
return;
F_279 ( V_479 , F_280 ( V_4 ) - V_4 -> V_472 ) ;
F_281 ( V_479 , ( F_282 ( V_4 ) -
V_4 -> V_472 ) ) ;
F_283 ( V_479 , ( F_4 ( V_4 ) -
V_4 -> V_472 ) ) ;
F_284 ( V_479 , V_480 ) ;
memcpy ( V_479 -> V_472 , V_4 -> V_472 , V_480 ) ;
memcpy ( V_479 -> V_483 , V_4 -> V_483 , sizeof( V_4 -> V_483 ) ) ;
F_16 ( V_479 ) -> V_82 = F_16 ( V_479 ) -> V_85 = V_474 ;
F_285 ( V_469 , V_4 , V_479 ) ;
F_265 ( V_479 , V_2 ) ;
while ( V_481 > 0 ) {
int V_484 = V_474 - F_16 ( V_4 ) -> V_82 ;
int V_453 = F_16 ( V_4 ) -> V_85 - V_474 ;
F_91 ( V_484 < 0 ) ;
if ( V_453 > 0 ) {
V_453 = F_9 ( V_481 , V_453 ) ;
if ( F_286 ( V_4 , V_484 , F_287 ( V_479 , V_453 ) , V_453 ) )
F_288 () ;
F_16 ( V_479 ) -> V_85 += V_453 ;
V_481 -= V_453 ;
V_474 += V_453 ;
}
if ( ! F_40 ( V_474 , F_16 ( V_4 ) -> V_85 ) ) {
V_4 = F_273 ( V_2 , V_4 , V_469 ) ;
if ( ! V_4 ||
V_4 == V_473 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_452 )
return;
}
}
}
}
static void F_289 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_249 ( & V_30 -> V_433 ) ;
struct V_3 * V_472 ;
T_1 V_474 , V_475 ;
if ( V_4 == NULL )
return;
V_474 = F_16 ( V_4 ) -> V_82 ;
V_475 = F_16 ( V_4 ) -> V_85 ;
V_472 = V_4 ;
for (; ; ) {
struct V_3 * V_470 = NULL ;
if ( ! F_271 ( & V_30 -> V_433 , V_4 ) )
V_470 = F_272 ( & V_30 -> V_433 , V_4 ) ;
V_4 = V_470 ;
if ( ! V_4 ||
F_47 ( F_16 ( V_4 ) -> V_82 , V_475 ) ||
F_40 ( F_16 ( V_4 ) -> V_85 , V_474 ) ) {
F_274 ( V_2 , & V_30 -> V_433 ,
V_472 , V_4 , V_474 , V_475 ) ;
V_472 = V_4 ;
if ( ! V_4 )
break;
V_474 = F_16 ( V_4 ) -> V_82 ;
V_475 = F_16 ( V_4 ) -> V_85 ;
} else {
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_474 ) )
V_474 = F_16 ( V_4 ) -> V_82 ;
if ( F_47 ( F_16 ( V_4 ) -> V_85 , V_475 ) )
V_475 = F_16 ( V_4 ) -> V_85 ;
}
}
}
static int F_256 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_485 = 0 ;
if ( ! F_247 ( & V_30 -> V_433 ) ) {
F_71 ( F_72 ( V_2 ) , V_486 ) ;
F_238 ( & V_30 -> V_433 ) ;
if ( V_30 -> V_45 . V_131 )
F_214 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
V_485 = 1 ;
}
return V_485 ;
}
static int F_255 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_210 ( V_2 , L_21 , V_30 -> V_86 ) ;
F_71 ( F_72 ( V_2 ) , V_487 ) ;
if ( F_35 ( & V_2 -> V_72 ) >= V_2 -> V_62 )
F_32 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_289 ( V_2 ) ;
if ( ! F_247 ( & V_2 -> V_451 ) )
F_274 ( V_2 , & V_2 -> V_451 ,
F_249 ( & V_2 -> V_451 ) ,
NULL ,
V_30 -> V_86 , V_30 -> V_81 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_256 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_71 ( F_72 ( V_2 ) , V_488 ) ;
V_30 -> V_347 = 0 ;
return - 1 ;
}
void F_290 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_113 == V_114 &&
V_2 -> V_489 && ! F_291 ( V_490 , & V_2 -> V_489 -> V_103 ) ) {
T_1 V_491 = F_61 ( V_30 , F_53 ( V_2 ) ) ;
T_1 V_492 = F_31 ( V_30 -> V_493 , V_491 ) ;
if ( V_492 < V_30 -> V_110 ) {
V_30 -> V_112 = F_127 ( V_2 ) ;
V_30 -> V_110 = ( V_30 -> V_110 + V_492 ) >> 1 ;
}
V_30 -> V_493 = 0 ;
}
V_30 -> V_70 = V_71 ;
}
static int F_292 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_64 & V_66 )
return 0 ;
if ( F_26 ( V_2 ) )
return 0 ;
if ( F_33 ( V_2 ) >= F_34 ( V_2 , 0 ) )
return 0 ;
if ( V_30 -> V_228 >= V_30 -> V_110 )
return 0 ;
return 1 ;
}
static void F_293 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_292 ( V_2 ) ) {
int V_44 = F_21 ( F_28 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_297 ) +
V_47 ) ;
int V_494 = F_28 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_494 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_70 = V_71 ;
}
V_2 -> V_495 ( V_2 ) ;
}
static void F_294 ( struct V_1 * V_2 )
{
if ( F_231 ( V_2 , V_496 ) ) {
F_295 ( V_2 , V_496 ) ;
if ( V_2 -> V_489 &&
F_291 ( V_490 , & V_2 -> V_489 -> V_103 ) )
F_293 ( V_2 ) ;
}
}
static inline void F_296 ( struct V_1 * V_2 )
{
F_297 ( V_2 ) ;
F_294 ( V_2 ) ;
}
static void F_298 ( struct V_1 * V_2 , int V_497 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_81 - V_30 -> V_408 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_299 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_497 && F_249 ( & V_30 -> V_433 ) ) ) {
F_236 ( V_2 ) ;
} else {
F_300 ( V_2 ) ;
}
}
static inline void F_301 ( struct V_1 * V_2 )
{
if ( ! F_302 ( V_2 ) ) {
return;
}
F_298 ( V_2 , 1 ) ;
}
static void F_303 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_219 = F_155 ( V_41 -> V_498 ) ;
if ( V_219 && ! V_499 )
V_219 -- ;
V_219 += F_218 ( V_41 -> V_82 ) ;
if ( F_47 ( V_30 -> V_86 , V_219 ) )
return;
if ( F_40 ( V_219 , V_30 -> V_81 ) )
return;
if ( V_30 -> V_460 && ! F_47 ( V_219 , V_30 -> V_500 ) )
return;
F_304 ( V_2 ) ;
if ( V_30 -> V_500 == V_30 -> V_86 && V_30 -> V_460 &&
! F_231 ( V_2 , V_501 ) && V_30 -> V_86 != V_30 -> V_81 ) {
struct V_3 * V_4 = F_249 ( & V_2 -> V_451 ) ;
V_30 -> V_86 ++ ;
if ( V_4 && ! F_40 ( V_30 -> V_86 , F_16 ( V_4 ) -> V_85 ) ) {
F_250 ( V_4 , & V_2 -> V_451 ) ;
F_251 ( V_4 ) ;
}
}
V_30 -> V_460 = V_502 ;
V_30 -> V_500 = V_219 ;
V_30 -> V_347 = 0 ;
}
static void F_305 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_503 )
F_303 ( V_2 , V_41 ) ;
if ( V_30 -> V_460 == V_502 ) {
T_1 V_219 = V_30 -> V_500 - F_218 ( V_41 -> V_82 ) + ( V_41 -> V_372 * 4 ) -
V_41 -> V_43 ;
if ( V_219 < V_4 -> V_10 ) {
T_3 V_215 ;
if ( F_286 ( V_4 , V_219 , & V_215 , 1 ) )
F_288 () ;
V_30 -> V_460 = V_504 | V_215 ;
if ( ! F_231 ( V_2 , V_419 ) )
V_2 -> V_465 ( V_2 , 0 ) ;
}
}
}
static int F_306 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_505 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_461 = V_4 -> V_10 - V_505 ;
int V_182 ;
F_262 () ;
if ( F_307 ( V_4 ) )
V_182 = F_263 ( V_4 , V_505 , V_30 -> V_457 . V_463 , V_461 ) ;
else
V_182 = F_308 ( V_4 , V_505 ,
V_30 -> V_457 . V_463 ) ;
if ( ! V_182 ) {
V_30 -> V_457 . V_10 -= V_461 ;
V_30 -> V_86 += V_461 ;
F_42 ( V_2 ) ;
}
F_264 () ;
return V_182 ;
}
static T_10 F_309 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_10 V_506 ;
if ( F_260 ( V_2 ) ) {
F_262 () ;
V_506 = F_310 ( V_4 ) ;
F_264 () ;
} else {
V_506 = F_310 ( V_4 ) ;
}
return V_506 ;
}
static inline int F_311 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_307 ( V_4 ) &&
F_309 ( V_2 , V_4 ) ;
}
static int F_312 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_505 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_461 = V_4 -> V_10 - V_505 ;
int V_507 ;
int V_508 = 0 ;
if ( V_30 -> V_457 . V_509 )
return 0 ;
if ( ! V_30 -> V_457 . V_510 && V_30 -> V_457 . V_511 )
V_30 -> V_457 . V_510 = F_313 ( V_512 ) ;
if ( V_30 -> V_457 . V_510 && F_307 ( V_4 ) ) {
V_507 = F_314 ( V_30 -> V_457 . V_510 ,
V_4 , V_505 ,
V_30 -> V_457 . V_463 , V_461 ,
V_30 -> V_457 . V_511 ) ;
if ( V_507 < 0 )
goto V_210;
V_30 -> V_457 . V_507 = V_507 ;
V_508 = 1 ;
V_30 -> V_457 . V_10 -= V_461 ;
V_30 -> V_86 += V_461 ;
F_42 ( V_2 ) ;
if ( ( V_30 -> V_457 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_513 ) ||
( F_35 ( & V_2 -> V_72 ) > ( V_2 -> V_62 >> 1 ) ) ) {
V_30 -> V_457 . V_509 = 1 ;
V_2 -> V_465 ( V_2 , 0 ) ;
}
} else if ( V_461 > 0 ) {
V_30 -> V_457 . V_509 = 1 ;
V_2 -> V_465 ( V_2 , 0 ) ;
}
V_210:
return V_508 ;
}
static int F_315 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_514 )
{
const T_3 * V_515 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_219 ( V_4 , V_41 , V_30 , & V_515 ) &&
V_30 -> V_45 . V_274 &&
F_226 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_516 ) {
F_71 ( F_72 ( V_2 ) , V_517 ) ;
F_243 ( V_2 , V_4 ) ;
goto V_518;
}
}
if ( ! F_227 ( V_30 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_85 ) ) {
if ( ! V_41 -> V_516 )
F_243 ( V_2 , V_4 ) ;
goto V_518;
}
if ( V_41 -> V_516 ) {
F_229 ( V_2 ) ;
goto V_518;
}
F_223 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_41 -> V_43 && ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
if ( V_514 )
F_316 ( F_72 ( V_2 ) , V_519 ) ;
F_71 ( F_72 ( V_2 ) , V_520 ) ;
F_229 ( V_2 ) ;
return - 1 ;
}
return 1 ;
V_518:
F_251 ( V_4 ) ;
return 0 ;
}
int F_317 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_485 ;
V_30 -> V_45 . V_274 = 0 ;
if ( ( F_5 ( V_41 ) & V_521 ) == V_30 -> V_347 &&
F_16 ( V_4 ) -> V_82 == V_30 -> V_81 &&
! F_47 ( F_16 ( V_4 ) -> V_166 , V_30 -> V_99 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_404 ) {
if ( ! F_216 ( V_30 , V_41 ) )
goto V_522;
if ( ( T_5 ) ( V_30 -> V_45 . V_390 - V_30 -> V_45 . V_406 ) < 0 )
goto V_522;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_404 ) &&
V_30 -> V_81 == V_30 -> V_408 )
F_221 ( V_30 ) ;
F_209 ( V_2 , V_4 , 0 ) ;
F_251 ( V_4 ) ;
F_296 ( V_2 ) ;
return 0 ;
} else {
F_316 ( F_72 ( V_2 ) , V_519 ) ;
goto V_518;
}
} else {
int V_454 = 0 ;
int V_508 = 0 ;
if ( V_30 -> V_86 == V_30 -> V_81 &&
V_10 - V_18 <= V_30 -> V_457 . V_10 ) {
#ifdef F_318
if ( F_312 ( V_2 , V_4 , V_18 ) ) {
V_508 = 1 ;
V_454 = 1 ;
}
#endif
if ( V_30 -> V_457 . V_458 == V_459 &&
F_260 ( V_2 ) && ! V_508 ) {
F_261 ( V_462 ) ;
if ( ! F_306 ( V_2 , V_4 , V_18 ) )
V_454 = 1 ;
}
if ( V_454 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_404 ) &&
V_30 -> V_81 == V_30 -> V_408 )
F_221 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
F_259 ( V_4 , V_18 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_85 ;
F_71 ( F_72 ( V_2 ) , V_523 ) ;
}
if ( V_508 )
F_319 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_454 ) {
if ( F_311 ( V_2 , V_4 ) )
goto V_524;
if ( V_18 ==
( sizeof( struct V_15 ) + V_404 ) &&
V_30 -> V_81 == V_30 -> V_408 )
F_221 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
if ( ( int ) V_4 -> V_51 > V_2 -> V_525 )
goto V_526;
F_71 ( F_72 ( V_2 ) , V_527 ) ;
F_259 ( V_4 , V_18 ) ;
F_252 ( & V_2 -> V_451 , V_4 ) ;
F_265 ( V_4 , V_2 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_85 ;
}
F_43 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_166 != V_30 -> V_97 ) {
F_209 ( V_2 , V_4 , V_360 ) ;
F_296 ( V_2 ) ;
if ( ! F_302 ( V_2 ) )
goto V_528;
}
if ( ! V_508 || V_30 -> V_81 != V_30 -> V_408 )
F_298 ( V_2 , 0 ) ;
V_528:
#ifdef F_318
if ( V_508 )
F_252 ( & V_2 -> V_529 , V_4 ) ;
else
#endif
if ( V_454 )
F_251 ( V_4 ) ;
else
V_2 -> V_465 ( V_2 , 0 ) ;
return 0 ;
}
}
V_522:
if ( V_10 < ( V_41 -> V_372 << 2 ) || F_311 ( V_2 , V_4 ) )
goto V_524;
V_485 = F_315 ( V_2 , V_4 , V_41 , 1 ) ;
if ( V_485 <= 0 )
return - V_485 ;
V_526:
if ( V_41 -> V_318 && F_209 ( V_2 , V_4 , V_357 ) < 0 )
goto V_518;
F_41 ( V_2 , V_4 ) ;
F_305 ( V_2 , V_4 , V_41 ) ;
F_257 ( V_2 , V_4 ) ;
F_296 ( V_2 ) ;
F_301 ( V_2 ) ;
return 0 ;
V_524:
F_316 ( F_72 ( V_2 ) , V_519 ) ;
V_518:
F_251 ( V_4 ) ;
return 0 ;
}
static int F_320 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
const T_3 * V_515 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_530 * V_531 = V_30 -> V_532 ;
int V_533 = V_30 -> V_45 . V_46 ;
F_211 ( V_4 , & V_30 -> V_45 , & V_515 , 0 ) ;
if ( V_41 -> V_318 ) {
if ( F_16 ( V_4 ) -> V_166 != V_30 -> V_99 )
goto V_534;
if ( V_30 -> V_45 . V_274 && V_30 -> V_45 . V_84 &&
! F_192 ( V_30 -> V_45 . V_84 , V_30 -> V_273 ,
V_71 ) ) {
F_71 ( F_72 ( V_2 ) , V_535 ) ;
goto V_534;
}
if ( V_41 -> V_516 ) {
F_229 ( V_2 ) ;
goto V_518;
}
if ( ! V_41 -> V_43 )
goto V_536;
F_17 ( V_30 , V_41 ) ;
V_30 -> V_343 = F_16 ( V_4 ) -> V_82 ;
F_209 ( V_2 , V_4 , V_357 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_408 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_344 = F_155 ( V_41 -> V_52 ) ;
F_321 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_30 -> V_45 . V_384 ) {
V_30 -> V_45 . V_345 = V_30 -> V_45 . V_537 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_274 ) {
V_30 -> V_45 . V_388 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_404 ;
V_30 -> V_57 -= V_404 ;
F_221 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_144 ( V_30 ) && V_538 )
F_322 ( V_30 ) ;
F_323 ( V_2 ) ;
F_172 ( V_2 , V_6 -> V_299 ) ;
F_36 ( V_2 ) ;
V_30 -> V_86 = V_30 -> V_81 ;
if ( V_531 != NULL &&
V_531 -> V_539 > 0 &&
V_30 -> V_45 . V_403 > 0 ) {
int V_540 = V_30 -> V_45 . V_403
- V_399 ;
int V_539 = V_540
+ V_531 -> V_541 ;
if ( sizeof( V_531 -> V_542 ) >= V_539 ) {
memcpy ( & V_531 -> V_542 [ V_531 -> V_541 ] ,
V_515 , V_540 ) ;
V_531 -> V_539 = V_539 ;
}
}
F_324 () ;
F_235 ( V_2 , V_425 ) ;
F_325 ( V_2 , V_4 ) ;
V_6 -> V_543 -> V_544 ( V_2 ) ;
F_68 ( V_2 ) ;
F_326 ( V_2 ) ;
V_30 -> V_545 = V_71 ;
F_29 ( V_2 ) ;
if ( F_231 ( V_2 , V_546 ) )
F_327 ( V_2 , F_328 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_345 )
F_329 ( V_30 , V_30 -> V_344 ) ;
else
V_30 -> V_347 = 0 ;
if ( ! F_231 ( V_2 , V_419 ) ) {
V_2 -> V_434 ( V_2 ) ;
F_239 ( V_2 , V_547 , V_548 ) ;
}
if ( V_2 -> V_549 ||
V_6 -> V_550 . V_551 ||
V_6 -> V_8 . V_26 ) {
F_44 ( V_2 ) ;
V_6 -> V_8 . V_90 = V_71 ;
V_6 -> V_8 . V_27 = V_28 ;
F_8 ( V_2 ) ;
F_10 ( V_2 ) ;
F_136 ( V_2 , V_552 ,
V_553 , V_256 ) ;
V_518:
F_251 ( V_4 ) ;
return 0 ;
} else {
F_236 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_516 ) {
goto V_536;
}
if ( V_30 -> V_45 . V_407 && V_30 -> V_45 . V_274 &&
F_330 ( & V_30 -> V_45 , 0 ) )
goto V_536;
if ( V_41 -> V_43 ) {
F_235 ( V_2 , V_424 ) ;
if ( V_30 -> V_45 . V_274 ) {
V_30 -> V_45 . V_388 = 1 ;
F_221 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_404 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_408 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_344 = F_155 ( V_41 -> V_52 ) ;
V_30 -> V_343 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_159 = V_30 -> V_344 ;
F_18 ( V_30 , V_41 ) ;
F_323 ( V_2 ) ;
F_172 ( V_2 , V_6 -> V_299 ) ;
F_36 ( V_2 ) ;
F_331 ( V_2 ) ;
#if 0
return -1;
#else
goto V_518;
#endif
}
V_536:
F_332 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_533 ;
goto V_518;
V_534:
F_332 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_533 ;
return 1 ;
}
int F_333 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_554 = 0 ;
int V_485 ;
V_30 -> V_45 . V_274 = 0 ;
switch ( V_2 -> V_411 ) {
case V_417 :
goto V_518;
case V_555 :
if ( V_41 -> V_318 )
return 1 ;
if ( V_41 -> V_516 )
goto V_518;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_452 )
goto V_518;
if ( V_6 -> V_543 -> V_556 ( V_2 , V_4 ) < 0 )
return 1 ;
F_334 ( V_4 ) ;
return 0 ;
}
goto V_518;
case V_412 :
V_554 = F_320 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_554 >= 0 )
return V_554 ;
F_305 ( V_2 , V_4 , V_41 ) ;
F_251 ( V_4 ) ;
F_296 ( V_2 ) ;
return 0 ;
}
V_485 = F_315 ( V_2 , V_4 , V_41 , 0 ) ;
if ( V_485 <= 0 )
return - V_485 ;
if ( V_41 -> V_318 ) {
int V_557 = F_209 ( V_2 , V_4 , V_357 ) > 0 ;
switch ( V_2 -> V_411 ) {
case V_424 :
if ( V_557 ) {
V_30 -> V_86 = V_30 -> V_81 ;
F_324 () ;
F_235 ( V_2 , V_425 ) ;
V_2 -> V_434 ( V_2 ) ;
if ( V_2 -> V_489 )
F_239 ( V_2 ,
V_547 , V_548 ) ;
V_30 -> V_97 = F_16 ( V_4 ) -> V_166 ;
V_30 -> V_344 = F_155 ( V_41 -> V_52 ) <<
V_30 -> V_45 . V_345 ;
F_321 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_30 -> V_45 . V_388 )
V_30 -> V_57 -= V_404 ;
V_6 -> V_543 -> V_544 ( V_2 ) ;
F_68 ( V_2 ) ;
F_326 ( V_2 ) ;
V_30 -> V_545 = V_71 ;
F_323 ( V_2 ) ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_335 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_428 :
if ( V_30 -> V_97 == V_30 -> V_558 ) {
F_235 ( V_2 , V_429 ) ;
V_2 -> V_421 |= V_559 ;
F_54 ( F_53 ( V_2 ) ) ;
if ( ! F_231 ( V_2 , V_419 ) )
V_2 -> V_434 ( V_2 ) ;
else {
int V_560 ;
if ( V_30 -> V_561 < 0 ||
( F_16 ( V_4 ) -> V_85 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_85 - V_41 -> V_452 , V_30 -> V_81 ) ) ) {
F_232 ( V_2 ) ;
F_71 ( F_72 ( V_2 ) , V_562 ) ;
return 1 ;
}
V_560 = F_336 ( V_2 ) ;
if ( V_560 > V_563 ) {
F_327 ( V_2 , V_560 - V_563 ) ;
} else if ( V_41 -> V_452 || F_260 ( V_2 ) ) {
F_327 ( V_2 , V_560 ) ;
} else {
F_237 ( V_2 , V_429 , V_560 ) ;
goto V_518;
}
}
}
break;
case V_426 :
if ( V_30 -> V_97 == V_30 -> V_558 ) {
F_237 ( V_2 , V_430 , 0 ) ;
goto V_518;
}
break;
case V_427 :
if ( V_30 -> V_97 == V_30 -> V_558 ) {
F_52 ( V_2 ) ;
F_232 ( V_2 ) ;
goto V_518;
}
break;
}
} else
goto V_518;
F_305 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_411 ) {
case V_415 :
case V_426 :
case V_427 :
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
case V_428 :
case V_429 :
if ( V_2 -> V_421 & V_422 ) {
if ( F_16 ( V_4 ) -> V_85 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_85 - V_41 -> V_452 , V_30 -> V_81 ) ) {
F_71 ( F_72 ( V_2 ) , V_562 ) ;
F_229 ( V_2 ) ;
return 1 ;
}
}
case V_425 :
F_257 ( V_2 , V_4 ) ;
V_554 = 1 ;
break;
}
if ( V_2 -> V_411 != V_417 ) {
F_296 ( V_2 ) ;
F_301 ( V_2 ) ;
}
if ( ! V_554 ) {
V_518:
F_251 ( V_4 ) ;
}
return 0 ;
}
