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
static inline void F_13 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( F_6 ( V_4 ) -> V_34 )
V_30 -> V_31 &= ~ V_35 ;
}
static inline void F_14 ( struct V_29 * V_30 )
{
V_30 -> V_31 &= ~ V_35 ;
}
static inline void F_15 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( V_30 -> V_31 & V_32 ) {
if ( F_16 ( F_17 ( V_4 ) -> V_36 ) )
V_30 -> V_31 |= V_35 ;
else if ( F_18 ( ( F_17 ( V_4 ) -> V_36 ) ) )
F_10 ( (struct V_1 * ) V_30 ) ;
}
}
static inline void F_19 ( struct V_29 * V_30 , struct V_15 * V_37 )
{
if ( ( V_30 -> V_31 & V_32 ) && ( ! V_37 -> V_38 || V_37 -> V_34 ) )
V_30 -> V_31 &= ~ V_32 ;
}
static inline void F_20 ( struct V_29 * V_30 , struct V_15 * V_37 )
{
if ( ( V_30 -> V_31 & V_32 ) && ( ! V_37 -> V_38 || ! V_37 -> V_34 ) )
V_30 -> V_31 &= ~ V_32 ;
}
static inline int F_21 ( struct V_29 * V_30 , struct V_15 * V_37 )
{
if ( V_37 -> V_38 && ! V_37 -> V_39 && ( V_30 -> V_31 & V_32 ) )
return 1 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_40 = F_7 ( V_2 ) -> V_41 . V_42 + V_43 + 16 +
sizeof( struct V_3 ) ;
if ( V_2 -> V_44 < 3 * V_40 ) {
V_2 -> V_44 = 3 * V_40 ;
if ( V_2 -> V_44 > V_45 [ 2 ] )
V_2 -> V_44 = V_45 [ 2 ] ;
}
}
static int F_23 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_46 = F_24 ( V_4 -> V_46 ) >> 1 ;
int V_47 = F_24 ( V_48 [ 2 ] ) >> 1 ;
while ( V_30 -> V_49 <= V_47 ) {
if ( V_46 <= V_4 -> V_10 )
return 2 * F_2 ( V_2 ) -> V_8 . V_12 ;
V_46 >>= 1 ;
V_47 >>= 1 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_49 < V_30 -> V_50 &&
( int ) V_30 -> V_49 < F_26 ( V_2 ) &&
! V_51 ) {
int V_52 ;
if ( F_24 ( V_4 -> V_46 ) <= V_4 -> V_10 )
V_52 = 2 * V_30 -> V_53 ;
else
V_52 = F_23 ( V_2 , V_4 ) ;
if ( V_52 ) {
V_30 -> V_49 = F_9 ( V_30 -> V_49 + V_52 ,
V_30 -> V_50 ) ;
F_2 ( V_2 ) -> V_8 . V_24 |= 1 ;
}
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_54 = V_30 -> V_53 + V_43 + 16 + sizeof( struct V_3 ) ;
while ( F_24 ( V_54 ) < V_30 -> V_53 )
V_54 += 128 ;
if ( V_2 -> V_55 < 4 * V_54 )
V_2 -> V_55 = F_9 ( 4 * V_54 , V_48 [ 2 ] ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_56 ;
if ( ! ( V_2 -> V_57 & V_58 ) )
F_27 ( V_2 ) ;
if ( ! ( V_2 -> V_57 & V_59 ) )
F_22 ( V_2 ) ;
V_30 -> V_60 . V_61 = V_30 -> V_23 ;
V_56 = F_29 ( V_2 ) ;
if ( V_30 -> V_50 >= V_56 ) {
V_30 -> V_50 = V_56 ;
if ( V_62 && V_56 > 4 * V_30 -> V_53 )
V_30 -> V_50 = F_30 ( V_56 -
( V_56 >> V_62 ) ,
4 * V_30 -> V_53 ) ;
}
if ( V_62 &&
V_30 -> V_50 > 2 * V_30 -> V_53 &&
V_30 -> V_50 + V_30 -> V_53 > V_56 )
V_30 -> V_50 = F_30 ( 2 * V_30 -> V_53 , V_56 - V_30 -> V_53 ) ;
V_30 -> V_49 = F_9 ( V_30 -> V_49 , V_30 -> V_50 ) ;
V_30 -> V_63 = V_64 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_24 = 0 ;
if ( V_2 -> V_55 < V_48 [ 2 ] &&
! ( V_2 -> V_57 & V_58 ) &&
! V_51 &&
F_32 ( & V_65 ) < V_66 [ 0 ] ) {
V_2 -> V_55 = F_9 ( F_33 ( & V_2 -> V_67 ) ,
V_48 [ 2 ] ) ;
}
if ( F_33 ( & V_2 -> V_67 ) > V_2 -> V_55 )
V_30 -> V_49 = F_9 ( V_30 -> V_50 , 2U * V_30 -> V_53 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned int V_68 = F_35 (unsigned int, tp->advmss, tp->mss_cache) ;
V_68 = F_9 ( V_68 , V_30 -> V_23 / 2 ) ;
V_68 = F_9 ( V_68 , V_14 ) ;
V_68 = F_30 ( V_68 , V_16 ) ;
F_2 ( V_2 ) -> V_8 . V_12 = V_68 ;
}
static void F_36 ( struct V_29 * V_30 , T_1 V_69 , int V_70 )
{
T_1 V_71 = V_30 -> V_72 . V_73 ;
long V_74 = V_69 ;
if ( V_74 == 0 )
V_74 = 1 ;
if ( V_71 != 0 ) {
if ( ! V_70 ) {
V_74 -= ( V_71 >> 3 ) ;
V_71 += V_74 ;
} else if ( V_74 < V_71 )
V_71 = V_74 << 3 ;
} else {
V_71 = V_74 << 3 ;
}
if ( V_30 -> V_72 . V_73 != V_71 )
V_30 -> V_72 . V_73 = V_71 ;
}
static inline void F_37 ( struct V_29 * V_30 )
{
if ( V_30 -> V_72 . time == 0 )
goto V_75;
if ( F_38 ( V_30 -> V_76 , V_30 -> V_72 . V_77 ) )
return;
F_36 ( V_30 , V_78 - V_30 -> V_72 . time , 1 ) ;
V_75:
V_30 -> V_72 . V_77 = V_30 -> V_76 + V_30 -> V_23 ;
V_30 -> V_72 . time = V_64 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_41 . V_79 &&
( F_17 ( V_4 ) -> V_80 -
F_17 ( V_4 ) -> V_77 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_36 ( V_30 , V_64 - V_30 -> V_41 . V_79 , 0 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int time ;
int V_61 ;
if ( V_30 -> V_60 . time == 0 )
goto V_75;
time = V_64 - V_30 -> V_60 . time ;
if ( time < ( V_30 -> V_72 . V_73 >> 3 ) || V_30 -> V_72 . V_73 == 0 )
return;
V_61 = 2 * ( V_30 -> V_81 - V_30 -> V_60 . V_77 ) ;
V_61 = F_30 ( V_30 -> V_60 . V_61 , V_61 ) ;
if ( V_30 -> V_60 . V_61 != V_61 ) {
int V_54 ;
V_30 -> V_60 . V_61 = V_61 ;
if ( V_82 &&
! ( V_2 -> V_57 & V_58 ) ) {
int V_83 = V_61 ;
V_61 /= V_30 -> V_53 ;
if ( ! V_61 )
V_61 = 1 ;
V_54 = ( V_30 -> V_53 + V_43 +
16 + sizeof( struct V_3 ) ) ;
while ( F_24 ( V_54 ) < V_30 -> V_53 )
V_54 += 128 ;
V_61 *= V_54 ;
V_61 = F_9 ( V_61 , V_48 [ 2 ] ) ;
if ( V_61 > V_2 -> V_55 ) {
V_2 -> V_55 = V_61 ;
V_30 -> V_50 = V_83 ;
}
}
}
V_75:
V_30 -> V_60 . V_77 = V_30 -> V_81 ;
V_30 -> V_60 . time = V_64 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_84 ;
F_42 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_37 ( V_30 ) ;
V_84 = V_64 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_74 = V_84 - V_6 -> V_8 . V_85 ;
if ( V_74 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_74 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_74 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_86 )
V_6 -> V_8 . V_27 = V_6 -> V_86 ;
} else if ( V_74 > V_6 -> V_86 ) {
F_8 ( V_2 ) ;
F_43 ( V_2 ) ;
}
}
V_6 -> V_8 . V_85 = V_84 ;
F_15 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_25 ( V_2 , V_4 ) ;
}
static void F_44 ( struct V_1 * V_2 , const T_2 V_87 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_74 = V_87 ;
if ( V_74 == 0 )
V_74 = 1 ;
if ( V_30 -> V_88 != 0 ) {
V_74 -= ( V_30 -> V_88 >> 3 ) ;
V_30 -> V_88 += V_74 ;
if ( V_74 < 0 ) {
V_74 = - V_74 ;
V_74 -= ( V_30 -> V_89 >> 2 ) ;
if ( V_74 > 0 )
V_74 >>= 3 ;
} else {
V_74 -= ( V_30 -> V_89 >> 2 ) ;
}
V_30 -> V_89 += V_74 ;
if ( V_30 -> V_89 > V_30 -> V_90 ) {
V_30 -> V_90 = V_30 -> V_89 ;
if ( V_30 -> V_90 > V_30 -> V_91 )
V_30 -> V_91 = V_30 -> V_90 ;
}
if ( F_45 ( V_30 -> V_92 , V_30 -> V_93 ) ) {
if ( V_30 -> V_90 < V_30 -> V_91 )
V_30 -> V_91 -= ( V_30 -> V_91 - V_30 -> V_90 ) >> 2 ;
V_30 -> V_93 = V_30 -> V_94 ;
V_30 -> V_90 = F_46 ( V_2 ) ;
}
} else {
V_30 -> V_88 = V_74 << 3 ;
V_30 -> V_89 = V_74 << 1 ;
V_30 -> V_90 = V_30 -> V_91 = F_30 ( V_30 -> V_89 , F_46 ( V_2 ) ) ;
V_30 -> V_93 = V_30 -> V_94 ;
}
}
static inline void F_47 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_86 = F_48 ( V_30 ) ;
F_49 ( V_2 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_95 * V_96 = F_51 ( V_2 ) ;
if ( V_97 )
return;
F_52 ( V_96 ) ;
if ( V_96 && ( V_96 -> V_36 & V_98 ) ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_74 ;
unsigned long V_73 ;
if ( V_6 -> V_99 || ! V_30 -> V_88 ) {
if ( ! ( F_53 ( V_96 , V_100 ) ) )
F_54 ( V_96 , V_100 , 0 ) ;
return;
}
V_73 = F_55 ( V_96 , V_100 ) ;
V_74 = V_73 - V_30 -> V_88 ;
if ( ! ( F_53 ( V_96 , V_100 ) ) ) {
if ( V_74 <= 0 )
F_56 ( V_96 , V_100 , V_30 -> V_88 ) ;
else
F_56 ( V_96 , V_100 , V_73 - ( V_74 >> 3 ) ) ;
}
if ( ! ( F_53 ( V_96 , V_101 ) ) ) {
unsigned long V_102 ;
if ( V_74 < 0 )
V_74 = - V_74 ;
V_74 >>= 1 ;
if ( V_74 < V_30 -> V_89 )
V_74 = V_30 -> V_89 ;
V_102 = F_55 ( V_96 , V_101 ) ;
if ( V_74 >= V_102 )
V_102 = V_74 ;
else
V_102 -= ( V_102 - V_74 ) >> 2 ;
F_56 ( V_96 , V_101 , V_102 ) ;
}
if ( F_57 ( V_30 ) ) {
if ( F_58 ( V_96 , V_103 ) &&
! F_53 ( V_96 , V_103 ) &&
( V_30 -> V_104 >> 1 ) > F_58 ( V_96 , V_103 ) )
F_54 ( V_96 , V_103 , V_30 -> V_104 >> 1 ) ;
if ( ! F_53 ( V_96 , V_105 ) &&
V_30 -> V_104 > F_58 ( V_96 , V_105 ) )
F_54 ( V_96 , V_105 , V_30 -> V_104 ) ;
} else if ( V_30 -> V_104 > V_30 -> V_106 &&
V_6 -> V_107 == V_108 ) {
if ( ! F_53 ( V_96 , V_103 ) )
F_54 ( V_96 , V_103 ,
F_30 ( V_30 -> V_104 >> 1 , V_30 -> V_106 ) ) ;
if ( ! F_53 ( V_96 , V_105 ) )
F_54 ( V_96 , V_105 ,
( F_58 ( V_96 , V_105 ) +
V_30 -> V_104 ) >> 1 ) ;
} else {
if ( ! F_53 ( V_96 , V_105 ) )
F_54 ( V_96 , V_105 ,
( F_58 ( V_96 , V_105 ) +
V_30 -> V_106 ) >> 1 ) ;
if ( F_58 ( V_96 , V_103 ) &&
! F_53 ( V_96 , V_103 ) &&
V_30 -> V_106 > F_58 ( V_96 , V_103 ) )
F_54 ( V_96 , V_103 , V_30 -> V_106 ) ;
}
if ( ! F_53 ( V_96 , V_109 ) ) {
if ( F_58 ( V_96 , V_109 ) < V_30 -> V_110 &&
V_30 -> V_110 != V_111 )
F_54 ( V_96 , V_109 , V_30 -> V_110 ) ;
}
}
}
T_2 F_59 ( struct V_29 * V_30 , struct V_95 * V_96 )
{
T_2 V_112 = ( V_96 ? F_58 ( V_96 , V_113 ) : 0 ) ;
if ( ! V_112 )
V_112 = V_114 ;
return F_35 ( T_2 , V_112 , V_30 -> V_115 ) ;
}
void F_60 ( struct V_1 * V_2 , const int V_116 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_117 = 0 ;
V_30 -> V_118 = 0 ;
if ( V_6 -> V_107 < V_119 ) {
V_30 -> V_120 = 0 ;
if ( V_116 )
V_30 -> V_106 = V_6 -> V_121 -> V_122 ( V_2 ) ;
V_30 -> V_104 = F_9 ( V_30 -> V_104 ,
F_61 ( V_30 ) + 1U ) ;
V_30 -> V_123 = 0 ;
V_30 -> V_124 = V_30 -> V_94 ;
V_30 -> V_63 = V_64 ;
F_12 ( V_30 ) ;
F_62 ( V_2 , V_119 ) ;
}
}
static void F_63 ( struct V_29 * V_30 )
{
if ( F_64 ( V_30 ) )
V_30 -> V_125 = NULL ;
V_30 -> V_41 . V_126 &= ~ 2 ;
}
static void F_65 ( struct V_29 * V_30 )
{
V_30 -> V_41 . V_126 |= 4 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_95 * V_96 = F_51 ( V_2 ) ;
if ( V_96 == NULL )
goto V_127;
F_52 ( V_96 ) ;
if ( F_53 ( V_96 , V_105 ) )
V_30 -> V_115 = F_58 ( V_96 , V_105 ) ;
if ( F_58 ( V_96 , V_103 ) ) {
V_30 -> V_106 = F_58 ( V_96 , V_103 ) ;
if ( V_30 -> V_106 > V_30 -> V_115 )
V_30 -> V_106 = V_30 -> V_115 ;
} else {
V_30 -> V_106 = V_128 ;
}
if ( F_58 ( V_96 , V_109 ) &&
V_30 -> V_110 != F_58 ( V_96 , V_109 ) ) {
F_63 ( V_30 ) ;
V_30 -> V_110 = F_58 ( V_96 , V_109 ) ;
}
if ( F_58 ( V_96 , V_100 ) == 0 || V_30 -> V_88 == 0 )
goto V_127;
if ( F_55 ( V_96 , V_100 ) > V_30 -> V_88 ) {
V_30 -> V_88 = F_55 ( V_96 , V_100 ) ;
V_30 -> V_93 = V_30 -> V_94 ;
}
if ( F_55 ( V_96 , V_101 ) > V_30 -> V_89 ) {
V_30 -> V_89 = F_55 ( V_96 , V_101 ) ;
V_30 -> V_90 = V_30 -> V_91 = F_30 ( V_30 -> V_89 , F_46 ( V_2 ) ) ;
}
F_47 ( V_2 ) ;
V_127:
if ( V_30 -> V_88 == 0 ) {
V_30 -> V_89 = V_30 -> V_90 = V_30 -> V_91 = V_129 ;
F_2 ( V_2 ) -> V_86 = V_129 ;
}
if ( V_30 -> V_130 > 1 )
V_30 -> V_104 = 1 ;
else
V_30 -> V_104 = F_59 ( V_30 , V_96 ) ;
V_30 -> V_63 = V_64 ;
}
static void F_67 ( struct V_1 * V_2 , const int V_131 ,
const int V_132 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_131 > V_30 -> V_110 ) {
int V_133 ;
V_30 -> V_110 = F_9 ( V_134 , V_131 ) ;
if ( V_132 )
V_133 = V_135 ;
else if ( F_68 ( V_30 ) )
V_133 = V_136 ;
else if ( F_64 ( V_30 ) )
V_133 = V_137 ;
else
V_133 = V_138 ;
F_69 ( F_70 ( V_2 ) , V_133 ) ;
#if V_139 > 1
F_71 ( V_140 L_1 ,
V_30 -> V_41 . V_126 , F_2 ( V_2 ) -> V_107 ,
V_30 -> V_110 ,
V_30 -> V_141 ,
V_30 -> V_142 ,
V_30 -> V_120 ? V_30 -> V_143 : 0 ) ;
#endif
F_63 ( V_30 ) ;
}
}
static void F_72 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_144 == NULL ) ||
F_38 ( F_17 ( V_4 ) -> V_77 ,
F_17 ( V_30 -> V_144 ) -> V_77 ) )
V_30 -> V_144 = V_4 ;
if ( ! V_30 -> V_145 ||
F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_146 ) )
V_30 -> V_146 = F_17 ( V_4 ) -> V_80 ;
}
static void F_73 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_17 ( V_4 ) -> V_147 & ( V_148 | V_149 ) ) ) {
F_72 ( V_30 , V_4 ) ;
V_30 -> V_145 += F_74 ( V_4 ) ;
F_17 ( V_4 ) -> V_147 |= V_148 ;
}
}
static void F_75 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_72 ( V_30 , V_4 ) ;
if ( ! ( F_17 ( V_4 ) -> V_147 & ( V_148 | V_149 ) ) ) {
V_30 -> V_145 += F_74 ( V_4 ) ;
F_17 ( V_4 ) -> V_147 |= V_148 ;
}
}
static int F_76 ( struct V_29 * V_30 , int V_150 ,
T_1 V_151 , T_1 V_80 )
{
if ( F_45 ( V_80 , V_30 -> V_94 ) || ! F_38 ( V_151 , V_80 ) )
return 0 ;
if ( ! F_38 ( V_151 , V_30 -> V_94 ) )
return 0 ;
if ( F_45 ( V_151 , V_30 -> V_92 ) )
return 1 ;
if ( ! V_150 || ! V_30 -> V_120 )
return 0 ;
if ( F_45 ( V_80 , V_30 -> V_92 ) )
return 0 ;
if ( ! F_38 ( V_151 , V_30 -> V_120 ) )
return 1 ;
if ( ! F_45 ( V_80 , V_30 -> V_120 ) )
return 0 ;
return ! F_38 ( V_151 , V_80 - V_30 -> V_152 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_153 = 0 ;
T_1 V_154 = V_30 -> V_94 ;
T_1 V_155 = F_78 ( V_30 ) ;
if ( ! F_64 ( V_30 ) || ! V_30 -> V_156 ||
! F_45 ( V_155 , V_30 -> V_157 ) ||
V_6 -> V_107 != V_158 )
return;
F_79 (skb, sk) {
T_1 V_159 = F_17 ( V_4 ) -> V_159 ;
if ( V_4 == F_80 ( V_2 ) )
break;
if ( V_153 == V_30 -> V_156 )
break;
if ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_92 ) )
continue;
if ( ! ( F_17 ( V_4 ) -> V_147 & V_160 ) )
continue;
if ( F_45 ( V_155 , V_159 ) ) {
F_17 ( V_4 ) -> V_147 &= ~ V_160 ;
V_30 -> V_156 -= F_74 ( V_4 ) ;
F_75 ( V_30 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_161 ) ;
} else {
if ( F_38 ( V_159 , V_154 ) )
V_154 = V_159 ;
V_153 += F_74 ( V_4 ) ;
}
}
if ( V_30 -> V_156 )
V_30 -> V_157 = V_154 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_3 * V_162 ,
struct V_163 * V_164 , int V_165 ,
T_1 V_166 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_167 = F_82 ( & V_164 [ 0 ] . V_151 ) ;
T_1 V_168 = F_82 ( & V_164 [ 0 ] . V_80 ) ;
int V_169 = 0 ;
if ( F_38 ( V_167 , F_17 ( V_162 ) -> V_159 ) ) {
V_169 = 1 ;
F_65 ( V_30 ) ;
F_69 ( F_70 ( V_2 ) , V_170 ) ;
} else if ( V_165 > 1 ) {
T_1 V_171 = F_82 ( & V_164 [ 1 ] . V_80 ) ;
T_1 V_172 = F_82 ( & V_164 [ 1 ] . V_151 ) ;
if ( ! F_45 ( V_168 , V_171 ) &&
! F_38 ( V_167 , V_172 ) ) {
V_169 = 1 ;
F_65 ( V_30 ) ;
F_69 ( F_70 ( V_2 ) ,
V_173 ) ;
}
}
if ( V_169 && V_30 -> V_120 && V_30 -> V_143 &&
! F_45 ( V_168 , V_166 ) &&
F_45 ( V_168 , V_30 -> V_120 ) )
V_30 -> V_143 -- ;
return V_169 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_151 , T_1 V_80 )
{
int V_174 , V_175 ;
unsigned int V_176 ;
unsigned int V_177 ;
V_174 = ! F_45 ( V_151 , F_17 ( V_4 ) -> V_77 ) &&
! F_38 ( V_80 , F_17 ( V_4 ) -> V_80 ) ;
if ( F_74 ( V_4 ) > 1 && ! V_174 &&
F_45 ( F_17 ( V_4 ) -> V_80 , V_151 ) ) {
V_177 = F_84 ( V_4 ) ;
V_174 = ! F_45 ( V_151 , F_17 ( V_4 ) -> V_77 ) ;
if ( ! V_174 ) {
V_176 = V_151 - F_17 ( V_4 ) -> V_77 ;
if ( V_176 < V_177 )
V_176 = V_177 ;
} else {
V_176 = V_80 - F_17 ( V_4 ) -> V_77 ;
if ( V_176 < V_177 )
return - V_178 ;
}
if ( V_176 > V_177 ) {
unsigned int V_179 = ( V_176 / V_177 ) * V_177 ;
if ( ! V_174 && V_179 < V_176 ) {
V_179 += V_177 ;
if ( V_179 > V_4 -> V_10 )
return 0 ;
}
V_176 = V_179 ;
}
V_175 = F_85 ( V_2 , V_4 , V_176 , V_177 ) ;
if ( V_175 < 0 )
return V_175 ;
}
return V_174 ;
}
static T_3 F_86 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_180 * V_181 ,
int V_169 , int V_182 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_3 V_147 = F_17 ( V_4 ) -> V_147 ;
int V_183 = V_181 -> V_183 ;
if ( V_169 && ( V_147 & V_184 ) ) {
if ( V_30 -> V_120 && V_30 -> V_143 &&
F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_120 ) )
V_30 -> V_143 -- ;
if ( V_147 & V_149 )
V_181 -> V_185 = F_9 ( V_183 , V_181 -> V_185 ) ;
}
if ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_92 ) )
return V_147 ;
if ( ! ( V_147 & V_149 ) ) {
if ( V_147 & V_160 ) {
if ( V_147 & V_148 ) {
V_147 &= ~ ( V_148 | V_160 ) ;
V_30 -> V_145 -= V_182 ;
V_30 -> V_156 -= V_182 ;
}
} else {
if ( ! ( V_147 & V_184 ) ) {
if ( F_38 ( F_17 ( V_4 ) -> V_77 ,
F_78 ( V_30 ) ) )
V_181 -> V_185 = F_9 ( V_183 ,
V_181 -> V_185 ) ;
if ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_186 ) )
V_181 -> V_187 |= V_188 ;
}
if ( V_147 & V_148 ) {
V_147 &= ~ V_148 ;
V_30 -> V_145 -= V_182 ;
}
}
V_147 |= V_149 ;
V_181 -> V_187 |= V_189 ;
V_30 -> V_142 += V_182 ;
V_183 += V_182 ;
if ( ! F_64 ( V_30 ) && ( V_30 -> V_125 != NULL ) &&
F_38 ( F_17 ( V_4 ) -> V_77 ,
F_17 ( V_30 -> V_125 ) -> V_77 ) )
V_30 -> V_190 += V_182 ;
if ( V_183 > V_30 -> V_141 )
V_30 -> V_141 = V_183 ;
}
if ( V_169 && ( V_147 & V_160 ) ) {
V_147 &= ~ V_160 ;
V_30 -> V_156 -= V_182 ;
}
return V_147 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_180 * V_181 ,
unsigned int V_182 , int V_191 , int V_177 ,
int V_169 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_192 = F_88 ( V_2 , V_4 ) ;
F_89 ( ! V_182 ) ;
if ( V_4 == V_30 -> V_125 )
V_30 -> V_190 += V_182 ;
F_17 ( V_192 ) -> V_80 += V_191 ;
F_17 ( V_4 ) -> V_77 += V_191 ;
F_3 ( V_192 ) -> V_193 += V_182 ;
F_89 ( F_3 ( V_4 ) -> V_193 < V_182 ) ;
F_3 ( V_4 ) -> V_193 -= V_182 ;
if ( ! F_3 ( V_192 ) -> V_11 ) {
F_3 ( V_192 ) -> V_11 = V_177 ;
F_3 ( V_192 ) -> V_194 = V_2 -> V_195 ;
}
if ( F_3 ( V_4 ) -> V_193 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_194 = 0 ;
}
F_86 ( V_4 , V_2 , V_181 , V_169 , V_182 ) ;
F_17 ( V_192 ) -> V_147 |= ( F_17 ( V_4 ) -> V_147 & V_196 ) ;
if ( V_4 -> V_10 > 0 ) {
F_89 ( ! F_74 ( V_4 ) ) ;
F_69 ( F_70 ( V_2 ) , V_197 ) ;
return 0 ;
}
if ( V_4 == V_30 -> V_144 )
V_30 -> V_144 = V_192 ;
if ( V_4 == V_30 -> V_198 )
V_30 -> V_198 = V_192 ;
if ( V_4 == V_30 -> V_125 ) {
V_30 -> V_125 = V_192 ;
V_30 -> V_190 -= F_74 ( V_192 ) ;
}
F_17 ( V_4 ) -> V_36 |= F_17 ( V_192 ) -> V_36 ;
if ( V_4 == F_90 ( V_2 ) )
F_91 ( V_2 , V_4 ) ;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_199 ) ;
return 1 ;
}
static int F_94 ( struct V_3 * V_4 )
{
return F_74 ( V_4 ) == 1 ? V_4 -> V_10 : F_84 ( V_4 ) ;
}
static int F_95 ( struct V_3 * V_4 )
{
return ! F_96 ( V_4 ) && F_97 ( V_4 ) ;
}
static struct V_3 * F_98 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_180 * V_181 ,
T_1 V_151 , T_1 V_80 ,
int V_169 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_192 ;
int V_177 ;
int V_182 = 0 ;
int V_10 ;
int V_174 ;
if ( ! F_99 ( V_2 ) )
goto V_200;
if ( ! V_169 &&
( F_17 ( V_4 ) -> V_147 & ( V_148 | V_160 ) ) == V_160 )
goto V_200;
if ( ! F_95 ( V_4 ) )
goto V_200;
if ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_92 ) )
goto V_200;
if ( F_100 ( V_4 == F_101 ( V_2 ) ) )
goto V_200;
V_192 = F_88 ( V_2 , V_4 ) ;
if ( ( F_17 ( V_192 ) -> V_147 & V_201 ) != V_149 )
goto V_200;
V_174 = ! F_45 ( V_151 , F_17 ( V_4 ) -> V_77 ) &&
! F_38 ( V_80 , F_17 ( V_4 ) -> V_80 ) ;
if ( V_174 ) {
V_10 = V_4 -> V_10 ;
V_182 = F_74 ( V_4 ) ;
V_177 = F_94 ( V_4 ) ;
if ( V_177 != F_94 ( V_192 ) )
goto V_200;
} else {
if ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_151 ) )
goto V_202;
if ( F_74 ( V_4 ) <= 1 )
goto V_202;
V_174 = ! F_45 ( V_151 , F_17 ( V_4 ) -> V_77 ) ;
if ( ! V_174 ) {
goto V_200;
}
V_10 = V_80 - F_17 ( V_4 ) -> V_77 ;
F_89 ( V_10 < 0 ) ;
F_89 ( V_10 > V_4 -> V_10 ) ;
V_177 = F_84 ( V_4 ) ;
if ( V_177 != F_94 ( V_192 ) )
goto V_200;
if ( V_10 == V_177 ) {
V_182 = 1 ;
} else if ( V_10 < V_177 ) {
goto V_202;
} else {
V_182 = V_10 / V_177 ;
V_10 = V_182 * V_177 ;
}
}
if ( ! F_102 ( V_192 , V_4 , V_10 ) )
goto V_200;
if ( ! F_87 ( V_2 , V_4 , V_181 , V_182 , V_10 , V_177 , V_169 ) )
goto V_203;
if ( V_192 == F_103 ( V_2 ) )
goto V_203;
V_4 = F_104 ( V_2 , V_192 ) ;
if ( ! F_95 ( V_4 ) ||
( V_4 == F_80 ( V_2 ) ) ||
( ( F_17 ( V_4 ) -> V_147 & V_201 ) != V_149 ) ||
( V_177 != F_94 ( V_4 ) ) )
goto V_203;
V_10 = V_4 -> V_10 ;
if ( F_102 ( V_192 , V_4 , V_10 ) ) {
V_182 += F_74 ( V_4 ) ;
F_87 ( V_2 , V_4 , V_181 , F_74 ( V_4 ) , V_10 , V_177 , 0 ) ;
}
V_203:
V_181 -> V_183 += V_182 ;
return V_192 ;
V_202:
return V_4 ;
V_200:
F_69 ( F_70 ( V_2 ) , V_204 ) ;
return NULL ;
}
static struct V_3 * F_105 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_205 * V_206 ,
struct V_180 * V_181 ,
T_1 V_151 , T_1 V_80 ,
int V_207 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_208 ;
F_106 (skb, sk) {
int V_174 = 0 ;
int V_169 = V_207 ;
if ( V_4 == F_80 ( V_2 ) )
break;
if ( ! F_38 ( F_17 ( V_4 ) -> V_77 , V_80 ) )
break;
if ( ( V_206 != NULL ) &&
F_38 ( F_17 ( V_4 ) -> V_77 , V_206 -> V_80 ) ) {
V_174 = F_83 ( V_2 , V_4 ,
V_206 -> V_151 ,
V_206 -> V_80 ) ;
if ( V_174 > 0 )
V_169 = 1 ;
}
if ( V_174 <= 0 ) {
V_208 = F_98 ( V_2 , V_4 , V_181 ,
V_151 , V_80 , V_169 ) ;
if ( V_208 != NULL ) {
if ( V_208 != V_4 ) {
V_4 = V_208 ;
continue;
}
V_174 = 0 ;
} else {
V_174 = F_83 ( V_2 , V_4 ,
V_151 ,
V_80 ) ;
}
}
if ( F_100 ( V_174 < 0 ) )
break;
if ( V_174 ) {
F_17 ( V_4 ) -> V_147 = F_86 ( V_4 , V_2 ,
V_181 ,
V_169 ,
F_74 ( V_4 ) ) ;
if ( ! F_38 ( F_17 ( V_4 ) -> V_77 ,
F_78 ( V_30 ) ) )
F_91 ( V_2 , V_4 ) ;
}
V_181 -> V_183 += F_74 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_180 * V_181 ,
T_1 V_209 )
{
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_45 ( F_17 ( V_4 ) -> V_80 , V_209 ) )
break;
V_181 -> V_183 += F_74 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_108 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_205 * V_206 ,
struct V_180 * V_181 ,
T_1 V_209 )
{
if ( V_206 == NULL )
return V_4 ;
if ( F_38 ( V_206 -> V_151 , V_209 ) ) {
V_4 = F_107 ( V_4 , V_2 , V_181 , V_206 -> V_151 ) ;
V_4 = F_105 ( V_4 , V_2 , NULL , V_181 ,
V_206 -> V_151 , V_206 -> V_80 ,
1 ) ;
}
return V_4 ;
}
static int F_109 ( struct V_29 * V_30 , struct V_205 * V_210 )
{
return V_210 < V_30 -> V_211 + F_110 ( V_30 -> V_211 ) ;
}
static int
F_111 ( struct V_1 * V_2 , struct V_3 * V_162 ,
T_1 V_166 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned char * V_212 = ( F_4 ( V_162 ) +
F_17 ( V_162 ) -> V_147 ) ;
struct V_163 * V_213 = (struct V_163 * ) ( V_212 + 2 ) ;
struct V_205 V_164 [ V_214 ] ;
struct V_205 * V_210 ;
struct V_180 V_181 ;
struct V_3 * V_4 ;
int V_165 = F_9 ( V_214 , ( V_212 [ 1 ] - V_215 ) >> 3 ) ;
int V_216 ;
int V_217 = 0 ;
int V_218 , V_219 ;
int V_220 ;
V_181 . V_187 = 0 ;
V_181 . V_185 = V_30 -> V_221 ;
if ( ! V_30 -> V_142 ) {
if ( F_112 ( V_30 -> V_141 ) )
V_30 -> V_141 = 0 ;
F_113 ( V_2 ) ;
}
V_217 = F_81 ( V_2 , V_162 , V_213 ,
V_165 , V_166 ) ;
if ( V_217 )
V_181 . V_187 |= V_222 ;
if ( F_38 ( F_17 ( V_162 ) -> V_159 , V_166 - V_30 -> V_152 ) )
return 0 ;
if ( ! V_30 -> V_221 )
goto V_203;
V_216 = 0 ;
V_220 = 0 ;
for ( V_218 = 0 ; V_218 < V_165 ; V_218 ++ ) {
int V_169 = ! V_218 && V_217 ;
V_164 [ V_216 ] . V_151 = F_82 ( & V_213 [ V_218 ] . V_151 ) ;
V_164 [ V_216 ] . V_80 = F_82 ( & V_213 [ V_218 ] . V_80 ) ;
if ( ! F_76 ( V_30 , V_169 ,
V_164 [ V_216 ] . V_151 ,
V_164 [ V_216 ] . V_80 ) ) {
int V_133 ;
if ( V_169 ) {
if ( ! V_30 -> V_120 )
V_133 = V_223 ;
else
V_133 = V_224 ;
} else {
if ( ( F_17 ( V_162 ) -> V_159 != V_30 -> V_92 ) &&
! F_45 ( V_164 [ V_216 ] . V_80 , V_30 -> V_92 ) )
continue;
V_133 = V_225 ;
}
F_69 ( F_70 ( V_2 ) , V_133 ) ;
if ( V_218 == 0 )
V_220 = - 1 ;
continue;
}
if ( ! F_45 ( V_164 [ V_216 ] . V_80 , V_166 ) )
continue;
V_216 ++ ;
}
for ( V_218 = V_216 - 1 ; V_218 > 0 ; V_218 -- ) {
for ( V_219 = 0 ; V_219 < V_218 ; V_219 ++ ) {
if ( F_45 ( V_164 [ V_219 ] . V_151 , V_164 [ V_219 + 1 ] . V_151 ) ) {
F_114 ( V_164 [ V_219 ] , V_164 [ V_219 + 1 ] ) ;
if ( V_219 == V_220 )
V_220 = V_219 + 1 ;
}
}
}
V_4 = F_101 ( V_2 ) ;
V_181 . V_183 = 0 ;
V_218 = 0 ;
if ( ! V_30 -> V_142 ) {
V_210 = V_30 -> V_211 + F_110 ( V_30 -> V_211 ) ;
} else {
V_210 = V_30 -> V_211 ;
while ( F_109 ( V_30 , V_210 ) && ! V_210 -> V_151 &&
! V_210 -> V_80 )
V_210 ++ ;
}
while ( V_218 < V_216 ) {
T_1 V_151 = V_164 [ V_218 ] . V_151 ;
T_1 V_80 = V_164 [ V_218 ] . V_80 ;
int V_169 = ( V_217 && ( V_218 == V_220 ) ) ;
struct V_205 * V_206 = NULL ;
if ( V_217 && ( ( V_218 + 1 ) == V_220 ) )
V_206 = & V_164 [ V_218 + 1 ] ;
if ( F_45 ( V_80 , V_30 -> V_124 ) )
V_181 . V_187 |= V_226 ;
while ( F_109 ( V_30 , V_210 ) &&
! F_38 ( V_151 , V_210 -> V_80 ) )
V_210 ++ ;
if ( F_109 ( V_30 , V_210 ) && ! V_169 &&
F_45 ( V_80 , V_210 -> V_151 ) ) {
if ( F_38 ( V_151 , V_210 -> V_151 ) ) {
V_4 = F_107 ( V_4 , V_2 , & V_181 ,
V_151 ) ;
V_4 = F_105 ( V_4 , V_2 , V_206 ,
& V_181 ,
V_151 ,
V_210 -> V_151 ,
V_169 ) ;
}
if ( ! F_45 ( V_80 , V_210 -> V_80 ) )
goto V_227;
V_4 = F_108 ( V_4 , V_2 , V_206 ,
& V_181 ,
V_210 -> V_80 ) ;
if ( F_78 ( V_30 ) == V_210 -> V_80 ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_181 . V_183 = V_30 -> V_141 ;
V_210 ++ ;
goto V_228;
}
V_4 = F_107 ( V_4 , V_2 , & V_181 , V_210 -> V_80 ) ;
V_210 ++ ;
continue;
}
if ( ! F_38 ( V_151 , F_78 ( V_30 ) ) ) {
V_4 = F_90 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_181 . V_183 = V_30 -> V_141 ;
}
V_4 = F_107 ( V_4 , V_2 , & V_181 , V_151 ) ;
V_228:
V_4 = F_105 ( V_4 , V_2 , V_206 , & V_181 ,
V_151 , V_80 , V_169 ) ;
V_227:
if ( F_45 ( V_80 , V_30 -> V_186 ) )
V_181 . V_187 &= ~ V_188 ;
V_218 ++ ;
}
for ( V_218 = 0 ; V_218 < F_110 ( V_30 -> V_211 ) - V_216 ; V_218 ++ ) {
V_30 -> V_211 [ V_218 ] . V_151 = 0 ;
V_30 -> V_211 [ V_218 ] . V_80 = 0 ;
}
for ( V_219 = 0 ; V_219 < V_216 ; V_219 ++ )
V_30 -> V_211 [ V_218 ++ ] = V_164 [ V_219 ] ;
F_77 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ( V_181 . V_185 < V_30 -> V_141 ) &&
( ( V_6 -> V_107 != V_229 ) || V_30 -> V_120 ) &&
( ! V_30 -> V_186 || F_45 ( V_30 -> V_92 , V_30 -> V_186 ) ) )
F_67 ( V_2 , V_30 -> V_141 - V_181 . V_185 , 0 ) ;
V_203:
#if V_139 > 0
F_112 ( ( int ) V_30 -> V_142 < 0 ) ;
F_112 ( ( int ) V_30 -> V_145 < 0 ) ;
F_112 ( ( int ) V_30 -> V_156 < 0 ) ;
F_112 ( ( int ) F_61 ( V_30 ) < 0 ) ;
#endif
return V_181 . V_187 ;
}
static int F_116 ( struct V_29 * V_30 )
{
T_1 V_230 ;
V_230 = F_30 ( V_30 -> V_145 , 1U ) ;
V_230 = F_9 ( V_230 , V_30 -> V_221 ) ;
if ( ( V_30 -> V_142 + V_230 ) > V_30 -> V_221 ) {
V_30 -> V_142 = V_30 -> V_221 - V_230 ;
return 1 ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_2 , const int V_231 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_116 ( V_30 ) )
F_67 ( V_2 , V_30 -> V_221 + V_231 , 0 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_142 ++ ;
F_117 ( V_2 , 0 ) ;
F_115 ( V_30 ) ;
}
static void F_119 ( struct V_1 * V_2 , int V_232 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_232 > 0 ) {
if ( V_232 - 1 >= V_30 -> V_142 )
V_30 -> V_142 = 0 ;
else
V_30 -> V_142 -= V_232 - 1 ;
}
F_117 ( V_2 , V_232 ) ;
F_115 ( V_30 ) ;
}
static inline void F_120 ( struct V_29 * V_30 )
{
V_30 -> V_142 = 0 ;
}
static int F_121 ( const struct V_29 * V_30 )
{
return ( V_233 == 0x2 ) && ! F_68 ( V_30 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_233 )
return 0 ;
if ( V_6 -> V_234 . V_235 )
return 0 ;
if ( F_121 ( V_30 ) )
return 1 ;
if ( V_30 -> V_156 > 1 )
return 0 ;
V_4 = F_101 ( V_2 ) ;
if ( F_123 ( V_2 , V_4 ) )
return 1 ;
V_4 = F_104 ( V_2 , V_4 ) ;
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_17 ( V_4 ) -> V_147 & V_184 )
return 0 ;
if ( ! ( F_17 ( V_4 ) -> V_147 & V_149 ) )
break;
}
return 1 ;
}
void F_124 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ( ! V_30 -> V_236 && V_6 -> V_107 <= V_237 ) ||
V_30 -> V_92 == V_30 -> V_124 ||
( ( V_6 -> V_107 == V_229 || V_30 -> V_236 ) &&
! V_6 -> V_238 ) ) {
V_30 -> V_117 = F_125 ( V_2 ) ;
if ( V_30 -> V_236 ) {
T_1 V_239 ;
V_239 = V_30 -> V_104 ;
V_30 -> V_104 = 2 ;
V_30 -> V_106 = V_6 -> V_121 -> V_122 ( V_2 ) ;
V_30 -> V_104 = V_239 ;
} else {
V_30 -> V_106 = V_6 -> V_121 -> V_122 ( V_2 ) ;
}
F_126 ( V_2 , V_240 ) ;
}
V_30 -> V_120 = V_30 -> V_92 ;
V_30 -> V_143 = 0 ;
V_4 = F_101 ( V_2 ) ;
if ( F_17 ( V_4 ) -> V_147 & V_184 )
V_30 -> V_120 = 0 ;
if ( F_17 ( V_4 ) -> V_147 & V_160 ) {
F_17 ( V_4 ) -> V_147 &= ~ V_160 ;
V_30 -> V_156 -= F_74 ( V_4 ) ;
}
F_115 ( V_30 ) ;
V_30 -> V_104 = F_9 ( V_30 -> V_104 , F_61 ( V_30 ) + 1 ) ;
if ( F_121 ( V_30 ) && ( V_30 -> V_236 ||
( ( 1 << V_6 -> V_107 ) & ( V_241 | V_242 ) ) ) &&
F_45 ( V_30 -> V_124 , V_30 -> V_92 ) ) {
V_30 -> V_186 = V_30 -> V_124 ;
} else {
V_30 -> V_186 = V_30 -> V_94 ;
}
F_62 ( V_2 , V_237 ) ;
V_30 -> V_124 = V_30 -> V_94 ;
V_30 -> V_236 = 1 ;
}
static void F_127 ( struct V_1 * V_2 , int V_243 , int V_187 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
V_30 -> V_145 = 0 ;
V_30 -> V_156 = 0 ;
if ( F_68 ( V_30 ) )
F_120 ( V_30 ) ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
F_17 ( V_4 ) -> V_147 &= ~ V_148 ;
if ( ( V_30 -> V_236 == 1 ) && ! ( V_187 & V_244 ) ) {
if ( F_17 ( V_4 ) -> V_147 & V_160 )
V_30 -> V_156 += F_74 ( V_4 ) ;
V_187 |= V_244 ;
} else {
if ( F_17 ( V_4 ) -> V_147 & V_184 )
V_30 -> V_120 = 0 ;
F_17 ( V_4 ) -> V_147 &= ~ V_160 ;
}
if ( ! ( F_17 ( V_4 ) -> V_147 & V_149 ) ) {
F_17 ( V_4 ) -> V_147 |= V_148 ;
V_30 -> V_145 += F_74 ( V_4 ) ;
V_30 -> V_146 = F_17 ( V_4 ) -> V_80 ;
}
}
F_115 ( V_30 ) ;
V_30 -> V_104 = F_61 ( V_30 ) + V_243 ;
V_30 -> V_123 = 0 ;
V_30 -> V_63 = V_64 ;
V_30 -> V_236 = 0 ;
V_30 -> V_118 = 0 ;
V_30 -> V_110 = F_35 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_62 ( V_2 , V_229 ) ;
V_30 -> V_124 = V_30 -> V_94 ;
F_12 ( V_30 ) ;
F_128 ( V_30 ) ;
}
static void F_129 ( struct V_29 * V_30 )
{
V_30 -> V_156 = 0 ;
V_30 -> V_145 = 0 ;
V_30 -> V_120 = 0 ;
V_30 -> V_143 = 0 ;
}
void F_130 ( struct V_29 * V_30 )
{
F_129 ( V_30 ) ;
V_30 -> V_141 = 0 ;
V_30 -> V_142 = 0 ;
}
void F_131 ( struct V_1 * V_2 , int V_245 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_6 -> V_107 <= V_237 || V_30 -> V_92 == V_30 -> V_124 ||
( V_6 -> V_107 == V_229 && ! V_6 -> V_238 ) ) {
V_30 -> V_117 = F_125 ( V_2 ) ;
V_30 -> V_106 = V_6 -> V_121 -> V_122 ( V_2 ) ;
F_126 ( V_2 , V_246 ) ;
}
V_30 -> V_104 = 1 ;
V_30 -> V_123 = 0 ;
V_30 -> V_63 = V_64 ;
V_30 -> V_118 = 0 ;
F_129 ( V_30 ) ;
if ( F_68 ( V_30 ) )
F_120 ( V_30 ) ;
if ( ! V_245 ) {
V_30 -> V_120 = V_30 -> V_92 ;
} else {
V_30 -> V_142 = 0 ;
V_30 -> V_141 = 0 ;
}
F_128 ( V_30 ) ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_17 ( V_4 ) -> V_147 & V_184 )
V_30 -> V_120 = 0 ;
F_17 ( V_4 ) -> V_147 &= ( ~ V_201 ) | V_149 ;
if ( ! ( F_17 ( V_4 ) -> V_147 & V_149 ) || V_245 ) {
F_17 ( V_4 ) -> V_147 &= ~ V_149 ;
F_17 ( V_4 ) -> V_147 |= V_148 ;
V_30 -> V_145 += F_74 ( V_4 ) ;
V_30 -> V_146 = F_17 ( V_4 ) -> V_80 ;
}
}
F_115 ( V_30 ) ;
V_30 -> V_110 = F_35 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_62 ( V_2 , V_229 ) ;
V_30 -> V_124 = V_30 -> V_94 ;
F_12 ( V_30 ) ;
V_30 -> V_236 = 0 ;
}
static int F_132 ( struct V_1 * V_2 , int V_187 )
{
if ( V_187 & V_247 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_248 ) ;
F_131 ( V_2 , 1 ) ;
V_6 -> V_238 ++ ;
F_133 ( V_2 , F_101 ( V_2 ) ) ;
F_134 ( V_2 , V_249 ,
V_6 -> V_86 , V_250 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_135 ( struct V_29 * V_30 )
{
return F_68 ( V_30 ) ? V_30 -> V_142 + 1 : V_30 -> V_141 ;
}
static inline int F_136 ( struct V_29 * V_30 )
{
return F_64 ( V_30 ) ? V_30 -> V_141 : V_30 -> V_142 + 1 ;
}
static inline int F_137 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return V_64 - F_17 ( V_4 ) -> V_251 > F_2 ( V_2 ) -> V_86 ;
}
static inline int F_138 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_221 &&
F_137 ( V_2 , F_101 ( V_2 ) ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_221 ;
if ( V_30 -> V_236 )
return 0 ;
if ( V_30 -> V_145 )
return 1 ;
if ( F_136 ( V_30 ) > V_30 -> V_110 )
return 1 ;
if ( F_64 ( V_30 ) && F_138 ( V_2 ) )
return 1 ;
V_221 = V_30 -> V_221 ;
if ( V_221 <= V_30 -> V_110 &&
V_30 -> V_142 >= F_140 ( T_2 , V_221 / 2 , V_111 ) &&
! F_141 ( V_2 ) ) {
return 1 ;
}
if ( ( V_30 -> V_252 || V_253 ) &&
F_142 ( V_30 ) && F_136 ( V_30 ) > 1 &&
F_143 ( V_30 ) && ! F_80 ( V_2 ) )
return 1 ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_64 ( V_30 ) || ! F_138 ( V_2 ) )
return;
V_4 = V_30 -> V_198 ;
if ( V_30 -> V_198 == NULL )
V_4 = F_101 ( V_2 ) ;
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( ! F_137 ( V_2 , V_4 ) )
break;
F_73 ( V_30 , V_4 ) ;
}
V_30 -> V_198 = V_4 ;
F_115 ( V_30 ) ;
}
static void F_145 ( struct V_1 * V_2 , int V_254 , int V_255 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_153 , V_256 ;
int V_175 ;
unsigned int V_177 ;
F_112 ( V_254 > V_30 -> V_221 ) ;
if ( V_30 -> V_125 ) {
V_4 = V_30 -> V_125 ;
V_153 = V_30 -> V_190 ;
if ( V_255 && V_4 != F_101 ( V_2 ) )
return;
} else {
V_4 = F_101 ( V_2 ) ;
V_153 = 0 ;
}
F_106 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
V_30 -> V_125 = V_4 ;
V_30 -> V_190 = V_153 ;
if ( F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_124 ) )
break;
V_256 = V_153 ;
if ( F_64 ( V_30 ) || F_68 ( V_30 ) ||
( F_17 ( V_4 ) -> V_147 & V_149 ) )
V_153 += F_74 ( V_4 ) ;
if ( V_153 > V_254 ) {
if ( ( F_143 ( V_30 ) && ! F_64 ( V_30 ) ) ||
( V_256 >= V_254 ) )
break;
V_177 = F_3 ( V_4 ) -> V_11 ;
V_175 = F_85 ( V_2 , V_4 , ( V_254 - V_256 ) * V_177 , V_177 ) ;
if ( V_175 < 0 )
break;
V_153 = V_254 ;
}
F_73 ( V_30 , V_4 ) ;
if ( V_255 )
break;
}
F_115 ( V_30 ) ;
}
static void F_146 ( struct V_1 * V_2 , int V_257 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_68 ( V_30 ) ) {
F_145 ( V_2 , 1 , 1 ) ;
} else if ( F_64 ( V_30 ) ) {
int V_258 = V_30 -> V_141 - V_30 -> V_110 ;
if ( V_258 <= 0 )
V_258 = 1 ;
F_145 ( V_2 , V_258 , 0 ) ;
} else {
int V_259 = V_30 -> V_142 - V_30 -> V_110 ;
if ( V_259 >= 0 )
F_145 ( V_2 , V_259 , 0 ) ;
else if ( V_257 )
F_145 ( V_2 , 1 , 1 ) ;
}
F_144 ( V_2 ) ;
}
static inline void F_147 ( struct V_29 * V_30 )
{
V_30 -> V_104 = F_9 ( V_30 -> V_104 ,
F_61 ( V_30 ) + F_148 ( V_30 ) ) ;
V_30 -> V_63 = V_64 ;
}
static inline T_1 F_149 ( const struct V_1 * V_2 )
{
const struct V_260 * V_261 = F_2 ( V_2 ) -> V_121 ;
return V_261 -> V_262 ? V_261 -> V_262 ( V_2 ) : F_7 ( V_2 ) -> V_106 ;
}
static void F_150 ( struct V_1 * V_2 , int V_187 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_263 = V_30 -> V_123 + 1 ;
if ( ( V_187 & ( V_264 | V_222 ) ) ||
( F_68 ( V_30 ) && ! ( V_187 & V_265 ) ) ) {
V_30 -> V_123 = V_263 & 1 ;
V_263 >>= 1 ;
if ( V_263 && V_30 -> V_104 > F_149 ( V_2 ) )
V_30 -> V_104 -= V_263 ;
V_30 -> V_104 = F_9 ( V_30 -> V_104 , F_61 ( V_30 ) + 1 ) ;
V_30 -> V_63 = V_64 ;
}
}
static inline int F_151 ( struct V_29 * V_30 )
{
return ! V_30 -> V_266 ||
( V_30 -> V_41 . V_267 && V_30 -> V_41 . V_79 &&
F_38 ( V_30 -> V_41 . V_79 , V_30 -> V_266 ) ) ;
}
static void F_152 ( struct V_1 * V_2 , const char * V_268 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_269 * V_270 = F_153 ( V_2 ) ;
if ( V_2 -> V_271 == V_272 ) {
F_71 ( V_140 L_2 ,
V_268 ,
& V_270 -> V_273 , F_154 ( V_270 -> V_274 ) ,
V_30 -> V_104 , F_155 ( V_30 ) ,
V_30 -> V_106 , V_30 -> V_117 ,
V_30 -> V_221 ) ;
}
#if F_156 ( V_275 ) || F_156 ( V_276 )
else if ( V_2 -> V_271 == V_277 ) {
struct V_278 * V_279 = F_157 ( V_2 ) ;
F_71 ( V_140 L_3 ,
V_268 ,
& V_279 -> V_280 , F_154 ( V_270 -> V_274 ) ,
V_30 -> V_104 , F_155 ( V_30 ) ,
V_30 -> V_106 , V_30 -> V_117 ,
V_30 -> V_221 ) ;
}
#endif
}
static void F_158 ( struct V_1 * V_2 , const bool V_281 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_117 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_121 -> V_282 )
V_30 -> V_104 = V_6 -> V_121 -> V_282 ( V_2 ) ;
else
V_30 -> V_104 = F_30 ( V_30 -> V_104 , V_30 -> V_106 << 1 ) ;
if ( V_281 && V_30 -> V_117 > V_30 -> V_106 ) {
V_30 -> V_106 = V_30 -> V_117 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_104 = F_30 ( V_30 -> V_104 , V_30 -> V_106 ) ;
}
V_30 -> V_63 = V_64 ;
}
static inline int F_159 ( struct V_29 * V_30 )
{
return V_30 -> V_120 && ( ! V_30 -> V_143 || F_151 ( V_30 ) ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_159 ( V_30 ) ) {
int V_133 ;
F_152 ( V_2 , F_2 ( V_2 ) -> V_107 == V_229 ? L_4 : L_5 ) ;
F_158 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_107 == V_229 )
V_133 = V_283 ;
else
V_133 = V_284 ;
F_69 ( F_70 ( V_2 ) , V_133 ) ;
V_30 -> V_120 = 0 ;
}
if ( V_30 -> V_92 == V_30 -> V_124 && F_68 ( V_30 ) ) {
F_147 ( V_30 ) ;
return 1 ;
}
F_62 ( V_2 , V_108 ) ;
return 0 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_120 && ! V_30 -> V_143 ) {
F_152 ( V_2 , L_6 ) ;
F_158 ( V_2 , true ) ;
V_30 -> V_120 = 0 ;
F_69 ( F_70 ( V_2 ) , V_285 ) ;
}
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_156 )
return 1 ;
V_4 = F_101 ( V_2 ) ;
if ( F_100 ( V_4 && F_17 ( V_4 ) -> V_147 & V_196 ) )
return 1 ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 , int V_232 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_286 = F_68 ( V_30 ) || ( F_135 ( V_30 ) > V_30 -> V_110 ) ;
if ( F_159 ( V_30 ) ) {
if ( ! F_162 ( V_2 ) )
V_30 -> V_266 = 0 ;
F_67 ( V_2 , F_135 ( V_30 ) + V_232 , 1 ) ;
F_152 ( V_2 , L_7 ) ;
F_158 ( V_2 , false ) ;
F_69 ( F_70 ( V_2 ) , V_287 ) ;
V_286 = 0 ;
}
return V_286 ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_159 ( V_30 ) ) {
struct V_3 * V_4 ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
F_17 ( V_4 ) -> V_147 &= ~ V_148 ;
}
F_128 ( V_30 ) ;
F_152 ( V_2 , L_8 ) ;
V_30 -> V_145 = 0 ;
F_158 ( V_2 , true ) ;
F_69 ( F_70 ( V_2 ) , V_283 ) ;
F_2 ( V_2 ) -> V_238 = 0 ;
V_30 -> V_120 = 0 ;
if ( F_143 ( V_30 ) )
F_62 ( V_2 , V_108 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_165 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_120 && V_30 -> V_104 > V_30 -> V_106 ) {
V_30 -> V_104 = V_30 -> V_106 ;
V_30 -> V_63 = V_64 ;
}
F_126 ( V_2 , V_288 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_181 = V_108 ;
if ( F_155 ( V_30 ) || F_162 ( V_2 ) || V_30 -> V_120 )
V_181 = V_237 ;
if ( F_2 ( V_2 ) -> V_107 != V_181 ) {
F_62 ( V_2 , V_181 ) ;
V_30 -> V_124 = V_30 -> V_94 ;
}
}
static void F_167 ( struct V_1 * V_2 , int V_187 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( ! V_30 -> V_236 && ! F_162 ( V_2 ) )
V_30 -> V_266 = 0 ;
if ( V_187 & V_289 )
F_60 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_107 != V_119 ) {
F_166 ( V_2 ) ;
F_147 ( V_30 ) ;
} else {
F_150 ( V_2 , V_187 ) ;
}
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_234 . V_290 = V_6 -> V_234 . V_235 - 1 ;
V_6 -> V_234 . V_235 = 0 ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_117 = F_125 ( V_2 ) ;
V_30 -> V_104 = V_30 -> V_104 *
F_170 ( V_2 , V_30 -> V_291 ) /
V_6 -> V_234 . V_235 ;
V_30 -> V_123 = 0 ;
V_30 -> V_63 = V_64 ;
V_30 -> V_106 = F_125 ( V_2 ) ;
V_6 -> V_234 . V_292 = V_6 -> V_234 . V_235 ;
V_6 -> V_234 . V_235 = 0 ;
F_171 ( V_2 , V_6 -> V_293 ) ;
}
void F_172 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_177 = F_173 ( V_2 ) ;
T_1 V_294 = V_30 -> V_145 ;
F_79 (skb, sk) {
if ( V_4 == F_80 ( V_2 ) )
break;
if ( F_94 ( V_4 ) > V_177 &&
! ( F_17 ( V_4 ) -> V_147 & V_149 ) ) {
if ( F_17 ( V_4 ) -> V_147 & V_160 ) {
F_17 ( V_4 ) -> V_147 &= ~ V_160 ;
V_30 -> V_156 -= F_74 ( V_4 ) ;
}
F_75 ( V_30 , V_4 ) ;
}
}
F_174 ( V_30 ) ;
if ( V_294 == V_30 -> V_145 )
return;
if ( F_68 ( V_30 ) )
F_116 ( V_30 ) ;
F_115 ( V_30 ) ;
if ( V_6 -> V_107 != V_229 ) {
V_30 -> V_124 = V_30 -> V_94 ;
V_30 -> V_106 = F_125 ( V_2 ) ;
V_30 -> V_117 = 0 ;
V_30 -> V_120 = 0 ;
F_62 ( V_2 , V_229 ) ;
}
F_175 ( V_2 ) ;
}
static void F_176 ( struct V_1 * V_2 , int V_295 , int V_187 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_296 = ! ( V_187 & ( V_297 | V_265 ) ) ;
int V_298 = V_296 || ( ( V_187 & V_189 ) &&
( F_135 ( V_30 ) > V_30 -> V_110 ) ) ;
int V_257 = 0 , V_133 ;
if ( F_112 ( ! V_30 -> V_221 && V_30 -> V_142 ) )
V_30 -> V_142 = 0 ;
if ( F_112 ( ! V_30 -> V_142 && V_30 -> V_141 ) )
V_30 -> V_141 = 0 ;
if ( V_187 & V_289 )
V_30 -> V_117 = 0 ;
if ( F_132 ( V_2 , V_187 ) )
return;
if ( F_64 ( V_30 ) && ( V_187 & V_226 ) &&
F_38 ( V_30 -> V_92 , V_30 -> V_124 ) &&
V_6 -> V_107 != V_108 &&
V_30 -> V_141 > V_30 -> V_110 ) {
F_145 ( V_2 , V_30 -> V_141 - V_30 -> V_110 , 0 ) ;
F_69 ( F_70 ( V_2 ) , V_299 ) ;
}
F_115 ( V_30 ) ;
if ( V_6 -> V_107 == V_108 ) {
F_112 ( V_30 -> V_156 != 0 ) ;
V_30 -> V_266 = 0 ;
} else if ( ! F_38 ( V_30 -> V_92 , V_30 -> V_124 ) ) {
switch ( V_6 -> V_107 ) {
case V_229 :
V_6 -> V_238 = 0 ;
if ( F_160 ( V_2 ) )
return;
break;
case V_119 :
if ( V_30 -> V_92 != V_30 -> V_124 ) {
F_165 ( V_2 ) ;
F_62 ( V_2 , V_108 ) ;
}
break;
case V_237 :
F_161 ( V_2 ) ;
if ( ! V_30 -> V_120 ||
F_68 ( V_30 ) || V_30 -> V_92 != V_30 -> V_124 ) {
V_30 -> V_120 = 0 ;
F_62 ( V_2 , V_108 ) ;
}
break;
case V_158 :
if ( F_68 ( V_30 ) )
F_120 ( V_30 ) ;
if ( F_160 ( V_2 ) )
return;
F_165 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_107 ) {
case V_158 :
if ( ! ( V_187 & V_297 ) ) {
if ( F_68 ( V_30 ) && V_296 )
F_118 ( V_2 ) ;
} else
V_298 = F_163 ( V_2 , V_295 ) ;
break;
case V_229 :
if ( V_187 & V_244 )
V_6 -> V_238 = 0 ;
if ( F_68 ( V_30 ) && V_187 & V_297 )
F_120 ( V_30 ) ;
if ( ! F_164 ( V_2 ) ) {
F_147 ( V_30 ) ;
F_175 ( V_2 ) ;
return;
}
if ( V_6 -> V_107 != V_108 )
return;
default:
if ( F_68 ( V_30 ) ) {
if ( V_187 & V_297 )
F_120 ( V_30 ) ;
if ( V_296 )
F_118 ( V_2 ) ;
}
if ( V_6 -> V_107 == V_237 )
F_161 ( V_2 ) ;
if ( ! F_139 ( V_2 ) ) {
F_167 ( V_2 , V_187 ) ;
return;
}
if ( V_6 -> V_107 < V_119 &&
V_6 -> V_234 . V_235 &&
V_30 -> V_92 == V_30 -> V_300 . V_301 ) {
F_168 ( V_2 ) ;
V_30 -> V_104 ++ ;
F_172 ( V_2 ) ;
return;
}
if ( F_68 ( V_30 ) )
V_133 = V_302 ;
else
V_133 = V_303 ;
F_69 ( F_70 ( V_2 ) , V_133 ) ;
V_30 -> V_124 = V_30 -> V_94 ;
V_30 -> V_117 = 0 ;
V_30 -> V_120 = V_30 -> V_92 ;
V_30 -> V_143 = V_30 -> V_156 ;
if ( V_6 -> V_107 < V_119 ) {
if ( ! ( V_187 & V_289 ) )
V_30 -> V_117 = F_125 ( V_2 ) ;
V_30 -> V_106 = V_6 -> V_121 -> V_122 ( V_2 ) ;
F_12 ( V_30 ) ;
}
V_30 -> V_118 = 0 ;
V_30 -> V_123 = 0 ;
F_62 ( V_2 , V_158 ) ;
V_257 = 1 ;
}
if ( V_298 || ( F_64 ( V_30 ) && F_138 ( V_2 ) ) )
F_146 ( V_2 , V_257 ) ;
F_150 ( V_2 , V_187 ) ;
F_175 ( V_2 ) ;
}
void F_177 ( struct V_1 * V_2 , T_1 V_304 )
{
F_44 ( V_2 , V_304 ) ;
F_47 ( V_2 ) ;
F_2 ( V_2 ) -> V_99 = 0 ;
}
static void F_178 ( struct V_1 * V_2 , int V_187 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_177 ( V_2 , V_64 - V_30 -> V_41 . V_79 ) ;
}
static void F_179 ( struct V_1 * V_2 , T_1 V_304 , int V_187 )
{
if ( V_187 & V_305 )
return;
F_177 ( V_2 , V_304 ) ;
}
static inline void F_180 ( struct V_1 * V_2 , const int V_187 ,
const T_4 V_304 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_41 . V_267 && V_30 -> V_41 . V_79 )
F_178 ( V_2 , V_187 ) ;
else if ( V_304 >= 0 )
F_179 ( V_2 , V_304 , V_187 ) ;
}
static void F_181 ( struct V_1 * V_2 , T_1 V_306 , T_1 V_307 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_121 -> V_308 ( V_2 , V_306 , V_307 ) ;
F_7 ( V_2 ) -> V_63 = V_64 ;
}
static void F_182 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_221 ) {
F_183 ( V_2 , V_249 ) ;
} else {
F_134 ( V_2 , V_249 ,
F_2 ( V_2 ) -> V_86 , V_250 ) ;
}
}
static T_1 F_184 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_309 ;
F_89 ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_92 ) ) ;
V_309 = F_74 ( V_4 ) ;
if ( F_185 ( V_2 , V_4 , V_30 -> V_92 - F_17 ( V_4 ) -> V_77 ) )
return 0 ;
V_309 -= F_74 ( V_4 ) ;
if ( V_309 ) {
F_89 ( F_74 ( V_4 ) == 0 ) ;
F_89 ( ! F_38 ( F_17 ( V_4 ) -> V_77 , F_17 ( V_4 ) -> V_80 ) ) ;
}
return V_309 ;
}
static int F_186 ( struct V_1 * V_2 , int V_310 ,
T_1 V_166 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_84 = V_64 ;
int V_311 = 1 ;
int V_187 = 0 ;
T_1 V_295 = 0 ;
T_1 V_185 = V_30 -> V_221 ;
T_1 V_312 = V_30 -> V_142 ;
T_4 V_304 = - 1 ;
T_4 V_313 = - 1 ;
T_5 V_314 = F_187 () ;
while ( ( V_4 = F_101 ( V_2 ) ) && V_4 != F_80 ( V_2 ) ) {
struct V_315 * V_316 = F_17 ( V_4 ) ;
T_1 V_317 ;
T_3 V_147 = V_316 -> V_147 ;
if ( F_45 ( V_316 -> V_80 , V_30 -> V_92 ) ) {
if ( F_74 ( V_4 ) == 1 ||
! F_45 ( V_30 -> V_92 , V_316 -> V_77 ) )
break;
V_317 = F_184 ( V_2 , V_4 ) ;
if ( ! V_317 )
break;
V_311 = 0 ;
} else {
V_317 = F_74 ( V_4 ) ;
}
if ( V_147 & V_184 ) {
if ( V_147 & V_160 )
V_30 -> V_156 -= V_317 ;
V_187 |= V_305 ;
V_313 = - 1 ;
V_304 = - 1 ;
if ( ( V_187 & V_244 ) || ( V_317 > 1 ) )
V_187 |= V_318 ;
} else {
V_313 = V_84 - V_316 -> V_251 ;
V_314 = V_4 -> V_319 ;
if ( V_304 < 0 ) {
V_304 = V_313 ;
}
if ( ! ( V_147 & V_149 ) )
V_185 = F_9 ( V_295 , V_185 ) ;
}
if ( V_147 & V_149 )
V_30 -> V_142 -= V_317 ;
if ( V_147 & V_148 )
V_30 -> V_145 -= V_317 ;
V_30 -> V_221 -= V_317 ;
V_295 += V_317 ;
if ( ! ( V_316 -> V_36 & V_320 ) ) {
V_187 |= V_244 ;
} else {
V_187 |= V_321 ;
V_30 -> V_266 = 0 ;
}
if ( ! V_311 )
break;
F_92 ( V_4 , V_2 ) ;
F_93 ( V_2 , V_4 ) ;
V_30 -> V_198 = NULL ;
if ( V_4 == V_30 -> V_144 )
V_30 -> V_144 = NULL ;
if ( V_4 == V_30 -> V_125 )
V_30 -> V_125 = NULL ;
}
if ( F_188 ( F_189 ( V_30 -> V_322 , V_166 , V_30 -> V_92 ) ) )
V_30 -> V_322 = V_30 -> V_92 ;
if ( V_4 && ( F_17 ( V_4 ) -> V_147 & V_149 ) )
V_187 |= V_247 ;
if ( V_187 & V_323 ) {
const struct V_260 * V_261
= F_2 ( V_2 ) -> V_121 ;
if ( F_100 ( V_6 -> V_234 . V_235 &&
! F_45 ( V_30 -> V_300 . V_324 , V_30 -> V_92 ) ) ) {
F_169 ( V_2 ) ;
}
F_180 ( V_2 , V_187 , V_304 ) ;
F_182 ( V_2 ) ;
if ( F_68 ( V_30 ) ) {
F_119 ( V_2 , V_295 ) ;
} else {
int V_325 ;
if ( V_185 < V_310 )
F_67 ( V_2 , V_30 -> V_141 - V_185 , 0 ) ;
V_325 = F_64 ( V_30 ) ? V_295 :
V_312 - V_30 -> V_142 ;
V_30 -> V_190 -= F_9 ( V_30 -> V_190 , V_325 ) ;
}
V_30 -> V_141 -= F_9 ( V_295 , V_30 -> V_141 ) ;
if ( V_261 -> V_295 ) {
T_4 V_326 = - 1 ;
if ( ! ( V_187 & V_305 ) ) {
if ( V_261 -> V_36 & V_327 &&
! F_190 ( V_314 ,
F_187 () ) )
V_326 = F_191 ( F_192 () ,
V_314 ) ;
else if ( V_313 >= 0 )
V_326 = F_193 ( V_313 ) ;
}
V_261 -> V_295 ( V_2 , V_295 , V_326 ) ;
}
}
#if V_139 > 0
F_112 ( ( int ) V_30 -> V_142 < 0 ) ;
F_112 ( ( int ) V_30 -> V_145 < 0 ) ;
F_112 ( ( int ) V_30 -> V_156 < 0 ) ;
if ( ! V_30 -> V_221 && F_143 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_145 ) {
F_71 ( V_140 L_9 ,
V_30 -> V_145 , V_6 -> V_107 ) ;
V_30 -> V_145 = 0 ;
}
if ( V_30 -> V_142 ) {
F_71 ( V_140 L_10 ,
V_30 -> V_142 , V_6 -> V_107 ) ;
V_30 -> V_142 = 0 ;
}
if ( V_30 -> V_156 ) {
F_71 ( V_140 L_11 ,
V_30 -> V_156 , V_6 -> V_107 ) ;
V_30 -> V_156 = 0 ;
}
}
#endif
return V_187 ;
}
static void F_194 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_45 ( F_17 ( F_80 ( V_2 ) ) -> V_80 , F_195 ( V_30 ) ) ) {
V_6 -> V_99 = 0 ;
F_183 ( V_2 , V_328 ) ;
} else {
F_134 ( V_2 , V_328 ,
F_9 ( V_6 -> V_86 << V_6 -> V_99 , V_250 ) ,
V_250 ) ;
}
}
static inline int F_196 ( const struct V_1 * V_2 , const int V_187 )
{
return ! ( V_187 & V_265 ) || ( V_187 & V_329 ) ||
F_2 ( V_2 ) -> V_107 != V_108 ;
}
static inline int F_197 ( const struct V_1 * V_2 , const int V_187 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_187 & V_289 ) || V_30 -> V_104 < V_30 -> V_106 ) &&
! ( ( 1 << F_2 ( V_2 ) -> V_107 ) & ( V_241 | V_330 ) ) ;
}
static inline int F_198 ( const struct V_29 * V_30 ,
const T_1 V_306 , const T_1 V_159 ,
const T_1 V_331 )
{
return F_45 ( V_306 , V_30 -> V_92 ) ||
F_45 ( V_159 , V_30 -> V_332 ) ||
( V_159 == V_30 -> V_332 && V_331 > V_30 -> V_333 ) ;
}
static int F_199 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_306 ,
T_1 V_159 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_187 = 0 ;
T_1 V_331 = F_154 ( F_6 ( V_4 ) -> V_47 ) ;
if ( F_188 ( ! F_6 ( V_4 ) -> V_39 ) )
V_331 <<= V_30 -> V_41 . V_334 ;
if ( F_198 ( V_30 , V_306 , V_159 , V_331 ) ) {
V_187 |= V_335 ;
F_200 ( V_30 , V_159 ) ;
if ( V_30 -> V_333 != V_331 ) {
V_30 -> V_333 = V_331 ;
V_30 -> V_336 = 0 ;
F_201 ( V_2 ) ;
if ( V_331 > V_30 -> V_152 ) {
V_30 -> V_152 = V_331 ;
F_171 ( V_2 , F_2 ( V_2 ) -> V_293 ) ;
}
}
}
V_30 -> V_92 = V_306 ;
return V_187 ;
}
static void F_202 ( struct V_29 * V_30 )
{
V_30 -> V_104 = F_9 ( V_30 -> V_104 , V_30 -> V_106 ) ;
V_30 -> V_123 = 0 ;
V_30 -> V_118 = 0 ;
F_12 ( V_30 ) ;
F_147 ( V_30 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
F_60 ( V_2 , 0 ) ;
}
static void F_204 ( struct V_1 * V_2 , int V_187 )
{
if ( V_187 & V_289 )
F_203 ( V_2 ) ;
else
F_158 ( V_2 , true ) ;
}
static int F_205 ( struct V_1 * V_2 , int V_187 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_115 ( V_30 ) ;
if ( V_187 & V_244 )
F_2 ( V_2 ) -> V_238 = 0 ;
if ( ( V_187 & V_318 ) ||
( ( V_30 -> V_236 >= 2 ) && ( V_187 & V_305 ) ) )
V_30 -> V_120 = 0 ;
if ( ! F_38 ( V_30 -> V_92 , V_30 -> V_186 ) ) {
F_127 ( V_2 , ( V_30 -> V_236 == 1 ? 2 : 3 ) , V_187 ) ;
return 1 ;
}
if ( ! F_121 ( V_30 ) ) {
if ( ! ( V_187 & V_264 ) && ( V_187 & V_265 ) )
return 1 ;
if ( ! ( V_187 & V_244 ) ) {
F_127 ( V_2 , ( V_30 -> V_236 == 1 ? 0 : 3 ) ,
V_187 ) ;
return 1 ;
}
} else {
if ( ! ( V_187 & V_244 ) && ( V_30 -> V_236 == 1 ) ) {
V_30 -> V_104 = F_9 ( V_30 -> V_104 ,
F_61 ( V_30 ) ) ;
return 1 ;
}
if ( ( V_30 -> V_236 >= 2 ) &&
( ! ( V_187 & V_337 ) ||
( ( V_187 & V_189 ) &&
! ( V_187 & V_188 ) ) ) ) {
if ( ! ( V_187 & V_337 ) &&
( V_187 & V_265 ) )
return 1 ;
F_127 ( V_2 , 3 , V_187 ) ;
return 1 ;
}
}
if ( V_30 -> V_236 == 1 ) {
V_30 -> V_104 = F_61 ( V_30 ) + 2 ;
V_30 -> V_236 = 2 ;
if ( ! F_141 ( V_2 ) )
F_127 ( V_2 , 2 , V_187 ) ;
return 1 ;
} else {
switch ( V_338 ) {
case 2 :
F_204 ( V_2 , V_187 ) ;
break;
case 1 :
F_202 ( V_30 ) ;
break;
default:
F_203 ( V_2 ) ;
break;
}
V_30 -> V_236 = 0 ;
V_30 -> V_120 = 0 ;
F_69 ( F_70 ( V_2 ) , V_339 ) ;
}
return 0 ;
}
static int F_206 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_187 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_166 = V_30 -> V_92 ;
T_1 V_159 = F_17 ( V_4 ) -> V_77 ;
T_1 V_306 = F_17 ( V_4 ) -> V_159 ;
T_1 V_340 ;
T_1 V_310 ;
int V_341 ;
int V_342 = 0 ;
if ( F_38 ( V_306 , V_166 ) )
goto V_343;
if ( F_45 ( V_306 , V_30 -> V_94 ) )
goto V_344;
if ( F_45 ( V_306 , V_166 ) )
V_187 |= V_297 ;
if ( V_345 ) {
if ( V_6 -> V_107 < V_119 )
V_30 -> V_118 += V_306 - V_166 ;
else if ( V_6 -> V_107 == V_229 )
V_30 -> V_118 += F_9 ( V_306 - V_166 ,
V_30 -> V_291 ) ;
}
V_310 = V_30 -> V_141 ;
V_340 = F_61 ( V_30 ) ;
if ( ! ( V_187 & V_346 ) && F_45 ( V_306 , V_166 ) ) {
F_200 ( V_30 , V_159 ) ;
V_30 -> V_92 = V_306 ;
V_187 |= V_335 ;
F_126 ( V_2 , V_347 ) ;
F_69 ( F_70 ( V_2 ) , V_348 ) ;
} else {
if ( V_159 != F_17 ( V_4 ) -> V_80 )
V_187 |= V_349 ;
else
F_69 ( F_70 ( V_2 ) , V_350 ) ;
V_187 |= F_199 ( V_2 , V_4 , V_306 , V_159 ) ;
if ( F_17 ( V_4 ) -> V_147 )
V_187 |= F_111 ( V_2 , V_4 , V_166 ) ;
if ( F_21 ( V_30 , F_6 ( V_4 ) ) )
V_187 |= V_289 ;
F_126 ( V_2 , V_351 ) ;
}
V_2 -> V_352 = 0 ;
V_6 -> V_353 = 0 ;
V_30 -> V_354 = V_64 ;
V_341 = V_30 -> V_221 ;
if ( ! V_341 )
goto V_355;
V_187 |= F_186 ( V_2 , V_310 , V_166 ) ;
if ( V_30 -> V_236 )
V_342 = F_205 ( V_2 , V_187 ) ;
if ( F_38 ( V_30 -> V_186 , V_30 -> V_92 ) )
V_30 -> V_186 = 0 ;
if ( F_196 ( V_2 , V_187 ) ) {
if ( ( V_187 & V_244 ) && ! V_342 &&
F_197 ( V_2 , V_187 ) )
F_181 ( V_2 , V_306 , V_340 ) ;
F_176 ( V_2 , V_341 - V_30 -> V_221 ,
V_187 ) ;
} else {
if ( ( V_187 & V_244 ) && ! V_342 )
F_181 ( V_2 , V_306 , V_340 ) ;
}
if ( ( V_187 & V_337 ) || ! ( V_187 & V_265 ) )
F_52 ( F_51 ( V_2 ) ) ;
return 1 ;
V_355:
if ( F_80 ( V_2 ) )
F_194 ( V_2 ) ;
return 1 ;
V_344:
F_207 ( V_2 , L_12 , V_306 , V_30 -> V_92 , V_30 -> V_94 ) ;
return - 1 ;
V_343:
if ( F_17 ( V_4 ) -> V_147 ) {
F_111 ( V_2 , V_4 , V_166 ) ;
if ( V_6 -> V_107 == V_108 )
F_166 ( V_2 ) ;
}
F_207 ( V_2 , L_13 , V_306 , V_30 -> V_92 , V_30 -> V_94 ) ;
return 0 ;
}
void F_208 ( struct V_3 * V_4 , struct V_356 * V_357 ,
T_3 * * V_358 , int V_359 )
{
unsigned char * V_212 ;
struct V_15 * V_37 = F_6 ( V_4 ) ;
int V_360 = ( V_37 -> V_361 * 4 ) - sizeof( struct V_15 ) ;
V_212 = ( unsigned char * ) ( V_37 + 1 ) ;
V_357 -> V_267 = 0 ;
while ( V_360 > 0 ) {
int V_362 = * V_212 ++ ;
int V_363 ;
switch ( V_362 ) {
case V_364 :
return;
case V_365 :
V_360 -- ;
continue;
default:
V_363 = * V_212 ++ ;
if ( V_363 < 2 )
return;
if ( V_363 > V_360 )
return;
switch ( V_362 ) {
case V_366 :
if ( V_363 == V_367 && V_37 -> V_39 && ! V_359 ) {
T_6 V_368 = F_209 ( V_212 ) ;
if ( V_368 ) {
if ( V_357 -> V_369 &&
V_357 -> V_369 < V_368 )
V_368 = V_357 -> V_369 ;
V_357 -> V_42 = V_368 ;
}
}
break;
case V_370 :
if ( V_363 == V_371 && V_37 -> V_39 &&
! V_359 && V_372 ) {
T_7 V_334 = * ( T_7 * ) V_212 ;
V_357 -> V_373 = 1 ;
if ( V_334 > 14 ) {
if ( F_210 () )
F_71 ( V_374 L_14
L_15 ,
V_334 ) ;
V_334 = 14 ;
}
V_357 -> V_334 = V_334 ;
}
break;
case V_375 :
if ( ( V_363 == V_376 ) &&
( ( V_359 && V_357 -> V_377 ) ||
( ! V_359 && V_378 ) ) ) {
V_357 -> V_267 = 1 ;
V_357 -> V_379 = F_82 ( V_212 ) ;
V_357 -> V_79 = F_82 ( V_212 + 4 ) ;
}
break;
case V_380 :
if ( V_363 == V_381 && V_37 -> V_39 &&
! V_359 && V_382 ) {
V_357 -> V_126 = 1 ;
F_211 ( V_357 ) ;
}
break;
case V_383 :
if ( ( V_363 >= ( V_215 + V_384 ) ) &&
! ( ( V_363 - V_215 ) % V_384 ) &&
V_357 -> V_126 ) {
F_17 ( V_4 ) -> V_147 = ( V_212 - 2 ) - ( unsigned char * ) V_37 ;
}
break;
#ifdef F_212
case V_385 :
break;
#endif
case V_386 :
switch ( V_363 ) {
case V_387 :
break;
case V_388 :
break;
case V_389 + 0 :
case V_389 + 2 :
case V_389 + 4 :
case V_389 + 6 :
case V_390 :
V_357 -> V_391 = V_363 ;
* V_358 = V_212 ;
break;
default:
break;
}
break;
}
V_212 += V_363 - 2 ;
V_360 -= V_363 ;
}
}
}
static int F_213 ( struct V_29 * V_30 , struct V_15 * V_37 )
{
T_8 * V_212 = ( T_8 * ) ( V_37 + 1 ) ;
if ( * V_212 == F_214 ( ( V_365 << 24 ) | ( V_365 << 16 )
| ( V_375 << 8 ) | V_376 ) ) {
V_30 -> V_41 . V_267 = 1 ;
++ V_212 ;
V_30 -> V_41 . V_379 = F_215 ( * V_212 ) ;
++ V_212 ;
V_30 -> V_41 . V_79 = F_215 ( * V_212 ) ;
return 1 ;
}
return 0 ;
}
static int F_216 ( struct V_3 * V_4 , struct V_15 * V_37 ,
struct V_29 * V_30 , T_3 * * V_358 )
{
if ( V_37 -> V_361 == ( sizeof( * V_37 ) / 4 ) ) {
V_30 -> V_41 . V_267 = 0 ;
return 0 ;
} else if ( V_30 -> V_41 . V_377 &&
V_37 -> V_361 == ( ( sizeof( * V_37 ) + V_392 ) / 4 ) ) {
if ( F_213 ( V_30 , V_37 ) )
return 1 ;
}
F_208 ( V_4 , & V_30 -> V_41 , V_358 , 1 ) ;
return 1 ;
}
T_3 * F_217 ( struct V_15 * V_37 )
{
int V_360 = ( V_37 -> V_361 << 2 ) - sizeof ( * V_37 ) ;
T_3 * V_212 = ( T_3 * ) ( V_37 + 1 ) ;
if ( V_360 < V_393 )
return NULL ;
while ( V_360 > 0 ) {
int V_362 = * V_212 ++ ;
int V_363 ;
switch( V_362 ) {
case V_364 :
return NULL ;
case V_365 :
V_360 -- ;
continue;
default:
V_363 = * V_212 ++ ;
if ( V_363 < 2 || V_363 > V_360 )
return NULL ;
if ( V_362 == V_385 )
return V_363 == V_393 ? V_212 : NULL ;
}
V_212 += V_363 - 2 ;
V_360 -= V_363 ;
}
return NULL ;
}
static inline void F_218 ( struct V_29 * V_30 )
{
V_30 -> V_41 . V_394 = V_30 -> V_41 . V_379 ;
V_30 -> V_41 . V_395 = F_219 () ;
}
static inline void F_220 ( struct V_29 * V_30 , T_1 V_77 )
{
if ( V_30 -> V_41 . V_267 && ! F_45 ( V_77 , V_30 -> V_396 ) ) {
if ( F_221 ( & V_30 -> V_41 , 0 ) )
F_218 ( V_30 ) ;
}
}
static int F_222 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_15 * V_37 = F_6 ( V_4 ) ;
T_1 V_77 = F_17 ( V_4 ) -> V_77 ;
T_1 V_306 = F_17 ( V_4 ) -> V_159 ;
return (
( V_37 -> V_306 && V_77 == F_17 ( V_4 ) -> V_80 && V_77 == V_30 -> V_76 ) &&
V_306 == V_30 -> V_92 &&
! F_198 ( V_30 , V_306 , V_77 , F_154 ( V_37 -> V_47 ) << V_30 -> V_41 . V_334 ) &&
( T_4 ) ( V_30 -> V_41 . V_394 - V_30 -> V_41 . V_379 ) <= ( F_2 ( V_2 ) -> V_86 * 1024 ) / V_397 ) ;
}
static inline int F_223 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_221 ( & V_30 -> V_41 , V_398 ) &&
! F_222 ( V_2 , V_4 ) ;
}
static inline int F_224 ( struct V_29 * V_30 , T_1 V_77 , T_1 V_80 )
{
return ! F_38 ( V_80 , V_30 -> V_396 ) &&
! F_45 ( V_77 , V_30 -> V_76 + F_225 ( V_30 ) ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_399 ) {
case V_400 :
V_2 -> V_401 = V_402 ;
break;
case V_403 :
V_2 -> V_401 = V_404 ;
break;
case V_405 :
return;
default:
V_2 -> V_401 = V_406 ;
}
F_227 () ;
if ( ! F_228 ( V_2 , V_407 ) )
V_2 -> V_408 ( V_2 ) ;
F_229 ( V_2 ) ;
}
static void F_230 ( struct V_3 * V_4 , struct V_1 * V_2 , struct V_15 * V_37 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_42 ( V_2 ) ;
V_2 -> V_409 |= V_410 ;
F_231 ( V_2 , V_411 ) ;
switch ( V_2 -> V_399 ) {
case V_412 :
case V_413 :
F_232 ( V_2 , V_403 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_403 :
case V_414 :
break;
case V_415 :
break;
case V_416 :
F_233 ( V_2 ) ;
F_232 ( V_2 , V_414 ) ;
break;
case V_417 :
F_233 ( V_2 ) ;
F_234 ( V_2 , V_418 , 0 ) ;
break;
default:
F_71 ( V_419 L_16 ,
V_420 , V_2 -> V_399 ) ;
break;
}
F_235 ( & V_30 -> V_421 ) ;
if ( F_143 ( V_30 ) )
F_211 ( & V_30 -> V_41 ) ;
F_43 ( V_2 ) ;
if ( ! F_228 ( V_2 , V_407 ) ) {
V_2 -> V_422 ( V_2 ) ;
if ( V_2 -> V_409 == V_423 ||
V_2 -> V_399 == V_405 )
F_236 ( V_2 , V_424 , V_425 ) ;
else
F_236 ( V_2 , V_424 , V_426 ) ;
}
}
static inline int F_237 ( struct V_205 * V_164 , T_1 V_77 ,
T_1 V_80 )
{
if ( ! F_45 ( V_77 , V_164 -> V_80 ) && ! F_45 ( V_164 -> V_151 , V_80 ) ) {
if ( F_38 ( V_77 , V_164 -> V_151 ) )
V_164 -> V_151 = V_77 ;
if ( F_45 ( V_80 , V_164 -> V_80 ) )
V_164 -> V_80 = V_80 ;
return 1 ;
}
return 0 ;
}
static void F_238 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_80 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_143 ( V_30 ) && V_427 ) {
int V_133 ;
if ( F_38 ( V_77 , V_30 -> V_76 ) )
V_133 = V_428 ;
else
V_133 = V_429 ;
F_69 ( F_70 ( V_2 ) , V_133 ) ;
V_30 -> V_41 . V_430 = 1 ;
V_30 -> V_431 [ 0 ] . V_151 = V_77 ;
V_30 -> V_431 [ 0 ] . V_80 = V_80 ;
}
}
static void F_239 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_80 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_41 . V_430 )
F_238 ( V_2 , V_77 , V_80 ) ;
else
F_237 ( V_30 -> V_431 , V_77 , V_80 ) ;
}
static void F_240 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_17 ( V_4 ) -> V_80 != F_17 ( V_4 ) -> V_77 &&
F_38 ( F_17 ( V_4 ) -> V_77 , V_30 -> V_76 ) ) {
F_69 ( F_70 ( V_2 ) , V_432 ) ;
F_10 ( V_2 ) ;
if ( F_143 ( V_30 ) && V_427 ) {
T_1 V_80 = F_17 ( V_4 ) -> V_80 ;
if ( F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_76 ) )
V_80 = V_30 -> V_76 ;
F_238 ( V_2 , F_17 ( V_4 ) -> V_77 , V_80 ) ;
}
}
F_233 ( V_2 ) ;
}
static void F_241 ( struct V_29 * V_30 )
{
int V_433 ;
struct V_205 * V_164 = & V_30 -> V_434 [ 0 ] ;
struct V_205 * V_435 = V_164 + 1 ;
for ( V_433 = 1 ; V_433 < V_30 -> V_41 . V_165 ; ) {
if ( F_237 ( V_164 , V_435 -> V_151 , V_435 -> V_80 ) ) {
int V_218 ;
V_30 -> V_41 . V_165 -- ;
for ( V_218 = V_433 ; V_218 < V_30 -> V_41 . V_165 ; V_218 ++ )
V_164 [ V_218 ] = V_164 [ V_218 + 1 ] ;
continue;
}
V_433 ++ , V_435 ++ ;
}
}
static void F_242 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_80 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_205 * V_164 = & V_30 -> V_434 [ 0 ] ;
int V_436 = V_30 -> V_41 . V_165 ;
int V_433 ;
if ( ! V_436 )
goto V_437;
for ( V_433 = 0 ; V_433 < V_436 ; V_433 ++ , V_164 ++ ) {
if ( F_237 ( V_164 , V_77 , V_80 ) ) {
for (; V_433 > 0 ; V_433 -- , V_164 -- )
F_114 ( * V_164 , * ( V_164 - 1 ) ) ;
if ( V_436 > 1 )
F_241 ( V_30 ) ;
return;
}
}
if ( V_433 >= V_214 ) {
V_433 -- ;
V_30 -> V_41 . V_165 -- ;
V_164 -- ;
}
for (; V_433 > 0 ; V_433 -- , V_164 -- )
* V_164 = * ( V_164 - 1 ) ;
V_437:
V_164 -> V_151 = V_77 ;
V_164 -> V_80 = V_80 ;
V_30 -> V_41 . V_165 ++ ;
}
static void F_243 ( struct V_29 * V_30 )
{
struct V_205 * V_164 = & V_30 -> V_434 [ 0 ] ;
int V_165 = V_30 -> V_41 . V_165 ;
int V_433 ;
if ( F_244 ( & V_30 -> V_421 ) ) {
V_30 -> V_41 . V_165 = 0 ;
return;
}
for ( V_433 = 0 ; V_433 < V_165 ; ) {
if ( ! F_38 ( V_30 -> V_76 , V_164 -> V_151 ) ) {
int V_218 ;
F_112 ( F_38 ( V_30 -> V_76 , V_164 -> V_80 ) ) ;
for ( V_218 = V_433 + 1 ; V_218 < V_165 ; V_218 ++ )
V_30 -> V_434 [ V_218 - 1 ] = V_30 -> V_434 [ V_218 ] ;
V_165 -- ;
continue;
}
V_433 ++ ;
V_164 ++ ;
}
V_30 -> V_41 . V_165 = V_165 ;
}
static void F_245 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_438 = V_30 -> V_76 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_246 ( & V_30 -> V_421 ) ) != NULL ) {
if ( F_45 ( F_17 ( V_4 ) -> V_77 , V_30 -> V_76 ) )
break;
if ( F_38 ( F_17 ( V_4 ) -> V_77 , V_438 ) ) {
T_2 V_430 = V_438 ;
if ( F_38 ( F_17 ( V_4 ) -> V_80 , V_438 ) )
V_438 = F_17 ( V_4 ) -> V_80 ;
F_239 ( V_2 , F_17 ( V_4 ) -> V_77 , V_430 ) ;
}
if ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_76 ) ) {
F_207 ( V_2 , L_17 ) ;
F_247 ( V_4 , & V_30 -> V_421 ) ;
F_248 ( V_4 ) ;
continue;
}
F_207 ( V_2 , L_18 ,
V_30 -> V_76 , F_17 ( V_4 ) -> V_77 ,
F_17 ( V_4 ) -> V_80 ) ;
F_247 ( V_4 , & V_30 -> V_421 ) ;
F_249 ( & V_2 -> V_439 , V_4 ) ;
V_30 -> V_76 = F_17 ( V_4 ) -> V_80 ;
if ( F_6 ( V_4 ) -> V_440 )
F_230 ( V_4 , V_2 , F_6 ( V_4 ) ) ;
}
}
static inline int F_250 ( struct V_1 * V_2 , unsigned int V_441 )
{
if ( F_33 ( & V_2 -> V_67 ) > V_2 -> V_55 ||
! F_251 ( V_2 , V_441 ) ) {
if ( F_252 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_251 ( V_2 , V_441 ) ) {
if ( ! F_253 ( V_2 ) )
return - 1 ;
if ( ! F_251 ( V_2 , V_441 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_254 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_37 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_442 = - 1 ;
if ( F_17 ( V_4 ) -> V_77 == F_17 ( V_4 ) -> V_80 )
goto V_443;
F_255 ( V_4 ) ;
F_256 ( V_4 , V_37 -> V_361 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_41 . V_430 = 0 ;
if ( F_17 ( V_4 ) -> V_77 == V_30 -> V_76 ) {
if ( F_225 ( V_30 ) == 0 )
goto V_444;
if ( V_30 -> V_445 . V_446 == V_447 &&
V_30 -> V_81 == V_30 -> V_76 && V_30 -> V_445 . V_10 &&
F_257 ( V_2 ) && ! V_30 -> V_448 ) {
int V_449 = F_35 (unsigned int, skb->len,
tp->ucopy.len) ;
F_258 ( V_450 ) ;
F_259 () ;
if ( ! F_260 ( V_4 , 0 , V_30 -> V_445 . V_451 , V_449 ) ) {
V_30 -> V_445 . V_10 -= V_449 ;
V_30 -> V_81 += V_449 ;
V_442 = ( V_449 == V_4 -> V_10 ) ;
F_40 ( V_2 ) ;
}
F_261 () ;
}
if ( V_442 <= 0 ) {
V_452:
if ( V_442 < 0 &&
F_250 ( V_2 , V_4 -> V_46 ) )
goto V_443;
F_262 ( V_4 , V_2 ) ;
F_249 ( & V_2 -> V_439 , V_4 ) ;
}
V_30 -> V_76 = F_17 ( V_4 ) -> V_80 ;
if ( V_4 -> V_10 )
F_41 ( V_2 , V_4 ) ;
if ( V_37 -> V_440 )
F_230 ( V_4 , V_2 , V_37 ) ;
if ( ! F_244 ( & V_30 -> V_421 ) ) {
F_245 ( V_2 ) ;
if ( F_244 ( & V_30 -> V_421 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_41 . V_165 )
F_243 ( V_30 ) ;
F_201 ( V_2 ) ;
if ( V_442 > 0 )
F_248 ( V_4 ) ;
else if ( ! F_228 ( V_2 , V_407 ) )
V_2 -> V_453 ( V_2 , 0 ) ;
return;
}
if ( ! F_45 ( F_17 ( V_4 ) -> V_80 , V_30 -> V_76 ) ) {
F_69 ( F_70 ( V_2 ) , V_432 ) ;
F_238 ( V_2 , F_17 ( V_4 ) -> V_77 , F_17 ( V_4 ) -> V_80 ) ;
V_444:
F_10 ( V_2 ) ;
F_42 ( V_2 ) ;
V_443:
F_248 ( V_4 ) ;
return;
}
if ( ! F_38 ( F_17 ( V_4 ) -> V_77 , V_30 -> V_76 + F_225 ( V_30 ) ) )
goto V_444;
F_10 ( V_2 ) ;
if ( F_38 ( F_17 ( V_4 ) -> V_77 , V_30 -> V_76 ) ) {
F_207 ( V_2 , L_19 ,
V_30 -> V_76 , F_17 ( V_4 ) -> V_77 ,
F_17 ( V_4 ) -> V_80 ) ;
F_238 ( V_2 , F_17 ( V_4 ) -> V_77 , V_30 -> V_76 ) ;
if ( ! F_225 ( V_30 ) )
goto V_444;
goto V_452;
}
F_15 ( V_30 , V_4 ) ;
if ( F_250 ( V_2 , V_4 -> V_46 ) )
goto V_443;
V_30 -> V_336 = 0 ;
F_42 ( V_2 ) ;
F_207 ( V_2 , L_20 ,
V_30 -> V_76 , F_17 ( V_4 ) -> V_77 , F_17 ( V_4 ) -> V_80 ) ;
F_262 ( V_4 , V_2 ) ;
if ( ! F_246 ( & V_30 -> V_421 ) ) {
if ( F_143 ( V_30 ) ) {
V_30 -> V_41 . V_165 = 1 ;
V_30 -> V_434 [ 0 ] . V_151 = F_17 ( V_4 ) -> V_77 ;
V_30 -> V_434 [ 0 ] . V_80 =
F_17 ( V_4 ) -> V_80 ;
}
F_263 ( & V_30 -> V_421 , V_4 ) ;
} else {
struct V_3 * V_454 = F_264 ( & V_30 -> V_421 ) ;
T_1 V_77 = F_17 ( V_4 ) -> V_77 ;
T_1 V_80 = F_17 ( V_4 ) -> V_80 ;
if ( V_77 == F_17 ( V_454 ) -> V_80 ) {
F_265 ( & V_30 -> V_421 , V_454 , V_4 ) ;
if ( ! V_30 -> V_41 . V_165 ||
V_30 -> V_434 [ 0 ] . V_80 != V_77 )
goto V_455;
V_30 -> V_434 [ 0 ] . V_80 = V_80 ;
return;
}
while ( 1 ) {
if ( ! F_45 ( F_17 ( V_454 ) -> V_77 , V_77 ) )
break;
if ( F_266 ( & V_30 -> V_421 , V_454 ) ) {
V_454 = NULL ;
break;
}
V_454 = F_267 ( & V_30 -> V_421 , V_454 ) ;
}
if ( V_454 && F_38 ( V_77 , F_17 ( V_454 ) -> V_80 ) ) {
if ( ! F_45 ( V_80 , F_17 ( V_454 ) -> V_80 ) ) {
F_248 ( V_4 ) ;
F_238 ( V_2 , V_77 , V_80 ) ;
goto V_455;
}
if ( F_45 ( V_77 , F_17 ( V_454 ) -> V_77 ) ) {
F_238 ( V_2 , V_77 ,
F_17 ( V_454 ) -> V_80 ) ;
} else {
if ( F_266 ( & V_30 -> V_421 ,
V_454 ) )
V_454 = NULL ;
else
V_454 = F_267 (
& V_30 -> V_421 ,
V_454 ) ;
}
}
if ( ! V_454 )
F_263 ( & V_30 -> V_421 , V_4 ) ;
else
F_265 ( & V_30 -> V_421 , V_454 , V_4 ) ;
while ( ! F_268 ( & V_30 -> V_421 , V_4 ) ) {
V_454 = F_269 ( & V_30 -> V_421 , V_4 ) ;
if ( ! F_45 ( V_80 , F_17 ( V_454 ) -> V_77 ) )
break;
if ( F_38 ( V_80 , F_17 ( V_454 ) -> V_80 ) ) {
F_239 ( V_2 , F_17 ( V_454 ) -> V_77 ,
V_80 ) ;
break;
}
F_247 ( V_454 , & V_30 -> V_421 ) ;
F_239 ( V_2 , F_17 ( V_454 ) -> V_77 ,
F_17 ( V_454 ) -> V_80 ) ;
F_248 ( V_454 ) ;
}
V_455:
if ( F_143 ( V_30 ) )
F_242 ( V_2 , V_77 , V_80 ) ;
}
}
static struct V_3 * F_270 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_456 * V_457 )
{
struct V_3 * V_458 = NULL ;
if ( ! F_268 ( V_457 , V_4 ) )
V_458 = F_269 ( V_457 , V_4 ) ;
F_247 ( V_4 , V_457 ) ;
F_248 ( V_4 ) ;
F_69 ( F_70 ( V_2 ) , V_459 ) ;
return V_458 ;
}
static void
F_271 ( struct V_1 * V_2 , struct V_456 * V_457 ,
struct V_3 * V_460 , struct V_3 * V_461 ,
T_1 V_462 , T_1 V_463 )
{
struct V_3 * V_4 , * V_464 ;
bool V_465 ;
V_4 = V_460 ;
V_466:
V_465 = true ;
F_272 (list, skb, n) {
if ( V_4 == V_461 )
break;
if ( ! F_38 ( V_462 , F_17 ( V_4 ) -> V_80 ) ) {
V_4 = F_270 ( V_2 , V_4 , V_457 ) ;
if ( ! V_4 )
break;
goto V_466;
}
if ( ! F_6 ( V_4 ) -> V_39 && ! F_6 ( V_4 ) -> V_440 &&
( F_24 ( V_4 -> V_46 ) > V_4 -> V_10 ||
F_38 ( F_17 ( V_4 ) -> V_77 , V_462 ) ) ) {
V_465 = false ;
break;
}
if ( ! F_268 ( V_457 , V_4 ) ) {
struct V_3 * V_458 = F_269 ( V_457 , V_4 ) ;
if ( V_458 != V_461 &&
F_17 ( V_4 ) -> V_80 != F_17 ( V_458 ) -> V_77 ) {
V_465 = false ;
break;
}
}
V_462 = F_17 ( V_4 ) -> V_80 ;
}
if ( V_465 || F_6 ( V_4 ) -> V_39 || F_6 ( V_4 ) -> V_440 )
return;
while ( F_38 ( V_462 , V_463 ) ) {
struct V_3 * V_467 ;
unsigned int V_468 = F_273 ( V_4 ) ;
int V_469 = F_274 ( V_468 , 0 ) ;
if ( V_469 < 0 )
return;
if ( V_463 - V_462 < V_469 )
V_469 = V_463 - V_462 ;
V_467 = F_275 ( V_469 + V_468 , V_470 ) ;
if ( ! V_467 )
return;
F_276 ( V_467 , F_277 ( V_4 ) - V_4 -> V_460 ) ;
F_278 ( V_467 , ( F_279 ( V_4 ) -
V_4 -> V_460 ) ) ;
F_280 ( V_467 , ( F_4 ( V_4 ) -
V_4 -> V_460 ) ) ;
F_281 ( V_467 , V_468 ) ;
memcpy ( V_467 -> V_460 , V_4 -> V_460 , V_468 ) ;
memcpy ( V_467 -> V_471 , V_4 -> V_471 , sizeof( V_4 -> V_471 ) ) ;
F_17 ( V_467 ) -> V_77 = F_17 ( V_467 ) -> V_80 = V_462 ;
F_282 ( V_457 , V_4 , V_467 ) ;
F_262 ( V_467 , V_2 ) ;
while ( V_469 > 0 ) {
int V_472 = V_462 - F_17 ( V_4 ) -> V_77 ;
int V_441 = F_17 ( V_4 ) -> V_80 - V_462 ;
F_89 ( V_472 < 0 ) ;
if ( V_441 > 0 ) {
V_441 = F_9 ( V_469 , V_441 ) ;
if ( F_283 ( V_4 , V_472 , F_284 ( V_467 , V_441 ) , V_441 ) )
F_285 () ;
F_17 ( V_467 ) -> V_80 += V_441 ;
V_469 -= V_441 ;
V_462 += V_441 ;
}
if ( ! F_38 ( V_462 , F_17 ( V_4 ) -> V_80 ) ) {
V_4 = F_270 ( V_2 , V_4 , V_457 ) ;
if ( ! V_4 ||
V_4 == V_461 ||
F_6 ( V_4 ) -> V_39 ||
F_6 ( V_4 ) -> V_440 )
return;
}
}
}
}
static void F_286 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_246 ( & V_30 -> V_421 ) ;
struct V_3 * V_460 ;
T_1 V_462 , V_463 ;
if ( V_4 == NULL )
return;
V_462 = F_17 ( V_4 ) -> V_77 ;
V_463 = F_17 ( V_4 ) -> V_80 ;
V_460 = V_4 ;
for (; ; ) {
struct V_3 * V_458 = NULL ;
if ( ! F_268 ( & V_30 -> V_421 , V_4 ) )
V_458 = F_269 ( & V_30 -> V_421 , V_4 ) ;
V_4 = V_458 ;
if ( ! V_4 ||
F_45 ( F_17 ( V_4 ) -> V_77 , V_463 ) ||
F_38 ( F_17 ( V_4 ) -> V_80 , V_462 ) ) {
F_271 ( V_2 , & V_30 -> V_421 ,
V_460 , V_4 , V_462 , V_463 ) ;
V_460 = V_4 ;
if ( ! V_4 )
break;
V_462 = F_17 ( V_4 ) -> V_77 ;
V_463 = F_17 ( V_4 ) -> V_80 ;
} else {
if ( F_38 ( F_17 ( V_4 ) -> V_77 , V_462 ) )
V_462 = F_17 ( V_4 ) -> V_77 ;
if ( F_45 ( F_17 ( V_4 ) -> V_80 , V_463 ) )
V_463 = F_17 ( V_4 ) -> V_80 ;
}
}
}
static int F_253 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_473 = 0 ;
if ( ! F_244 ( & V_30 -> V_421 ) ) {
F_69 ( F_70 ( V_2 ) , V_474 ) ;
F_235 ( & V_30 -> V_421 ) ;
if ( V_30 -> V_41 . V_126 )
F_211 ( & V_30 -> V_41 ) ;
F_43 ( V_2 ) ;
V_473 = 1 ;
}
return V_473 ;
}
static int F_252 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_207 ( V_2 , L_21 , V_30 -> V_81 ) ;
F_69 ( F_70 ( V_2 ) , V_475 ) ;
if ( F_33 ( & V_2 -> V_67 ) >= V_2 -> V_55 )
F_31 ( V_2 ) ;
else if ( V_51 )
V_30 -> V_49 = F_9 ( V_30 -> V_49 , 4U * V_30 -> V_53 ) ;
F_286 ( V_2 ) ;
if ( ! F_244 ( & V_2 -> V_439 ) )
F_271 ( V_2 , & V_2 -> V_439 ,
F_246 ( & V_2 -> V_439 ) ,
NULL ,
V_30 -> V_81 , V_30 -> V_76 ) ;
F_43 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_67 ) <= V_2 -> V_55 )
return 0 ;
F_253 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_67 ) <= V_2 -> V_55 )
return 0 ;
F_69 ( F_70 ( V_2 ) , V_476 ) ;
V_30 -> V_336 = 0 ;
return - 1 ;
}
void F_287 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_107 == V_108 &&
V_2 -> V_477 && ! F_288 ( V_478 , & V_2 -> V_477 -> V_36 ) ) {
T_1 V_479 = F_59 ( V_30 , F_51 ( V_2 ) ) ;
T_1 V_480 = F_30 ( V_30 -> V_481 , V_479 ) ;
if ( V_480 < V_30 -> V_104 ) {
V_30 -> V_106 = F_125 ( V_2 ) ;
V_30 -> V_104 = ( V_30 -> V_104 + V_480 ) >> 1 ;
}
V_30 -> V_481 = 0 ;
}
V_30 -> V_63 = V_64 ;
}
static int F_289 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_57 & V_59 )
return 0 ;
if ( V_51 )
return 0 ;
if ( F_32 ( & V_65 ) >= V_66 [ 0 ] )
return 0 ;
if ( V_30 -> V_221 >= V_30 -> V_104 )
return 0 ;
return 1 ;
}
static void F_290 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_289 ( V_2 ) ) {
int V_40 = F_140 ( T_1 , V_30 -> V_41 . V_42 , V_30 -> V_291 ) +
V_43 + 16 + sizeof( struct V_3 ) ;
int V_482 = F_140 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_40 *= 2 * V_482 ;
if ( V_40 > V_2 -> V_44 )
V_2 -> V_44 = F_9 ( V_40 , V_45 [ 2 ] ) ;
V_30 -> V_63 = V_64 ;
}
V_2 -> V_483 ( V_2 ) ;
}
static void F_291 ( struct V_1 * V_2 )
{
if ( F_228 ( V_2 , V_484 ) ) {
F_292 ( V_2 , V_484 ) ;
if ( V_2 -> V_477 &&
F_288 ( V_478 , & V_2 -> V_477 -> V_36 ) )
F_290 ( V_2 ) ;
}
}
static inline void F_293 ( struct V_1 * V_2 )
{
F_294 ( V_2 ) ;
F_291 ( V_2 ) ;
}
static void F_295 ( struct V_1 * V_2 , int V_485 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_76 - V_30 -> V_396 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_296 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_485 && F_246 ( & V_30 -> V_421 ) ) ) {
F_233 ( V_2 ) ;
} else {
F_297 ( V_2 ) ;
}
}
static inline void F_298 ( struct V_1 * V_2 )
{
if ( ! F_299 ( V_2 ) ) {
return;
}
F_295 ( V_2 , 1 ) ;
}
static void F_300 ( struct V_1 * V_2 , struct V_15 * V_37 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_212 = F_154 ( V_37 -> V_486 ) ;
if ( V_212 && ! V_487 )
V_212 -- ;
V_212 += F_215 ( V_37 -> V_77 ) ;
if ( F_45 ( V_30 -> V_81 , V_212 ) )
return;
if ( F_38 ( V_212 , V_30 -> V_76 ) )
return;
if ( V_30 -> V_448 && ! F_45 ( V_212 , V_30 -> V_488 ) )
return;
F_301 ( V_2 ) ;
if ( V_30 -> V_488 == V_30 -> V_81 && V_30 -> V_448 &&
! F_228 ( V_2 , V_489 ) && V_30 -> V_81 != V_30 -> V_76 ) {
struct V_3 * V_4 = F_246 ( & V_2 -> V_439 ) ;
V_30 -> V_81 ++ ;
if ( V_4 && ! F_38 ( V_30 -> V_81 , F_17 ( V_4 ) -> V_80 ) ) {
F_247 ( V_4 , & V_2 -> V_439 ) ;
F_248 ( V_4 ) ;
}
}
V_30 -> V_448 = V_490 ;
V_30 -> V_488 = V_212 ;
V_30 -> V_336 = 0 ;
}
static void F_302 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_15 * V_37 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_37 -> V_491 )
F_300 ( V_2 , V_37 ) ;
if ( V_30 -> V_448 == V_490 ) {
T_1 V_212 = V_30 -> V_488 - F_215 ( V_37 -> V_77 ) + ( V_37 -> V_361 * 4 ) -
V_37 -> V_39 ;
if ( V_212 < V_4 -> V_10 ) {
T_3 V_208 ;
if ( F_283 ( V_4 , V_212 , & V_208 , 1 ) )
F_285 () ;
V_30 -> V_448 = V_492 | V_208 ;
if ( ! F_228 ( V_2 , V_407 ) )
V_2 -> V_453 ( V_2 , 0 ) ;
}
}
}
static int F_303 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_493 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_449 = V_4 -> V_10 - V_493 ;
int V_175 ;
F_259 () ;
if ( F_304 ( V_4 ) )
V_175 = F_260 ( V_4 , V_493 , V_30 -> V_445 . V_451 , V_449 ) ;
else
V_175 = F_305 ( V_4 , V_493 ,
V_30 -> V_445 . V_451 ) ;
if ( ! V_175 ) {
V_30 -> V_445 . V_10 -= V_449 ;
V_30 -> V_81 += V_449 ;
F_40 ( V_2 ) ;
}
F_261 () ;
return V_175 ;
}
static T_9 F_306 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_9 V_494 ;
if ( F_257 ( V_2 ) ) {
F_259 () ;
V_494 = F_307 ( V_4 ) ;
F_261 () ;
} else {
V_494 = F_307 ( V_4 ) ;
}
return V_494 ;
}
static inline int F_308 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_304 ( V_4 ) &&
F_306 ( V_2 , V_4 ) ;
}
static int F_309 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_493 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_449 = V_4 -> V_10 - V_493 ;
int V_495 ;
int V_496 = 0 ;
if ( V_30 -> V_445 . V_497 )
return 0 ;
if ( ! V_30 -> V_445 . V_498 && V_30 -> V_445 . V_499 )
V_30 -> V_445 . V_498 = F_310 ( V_500 ) ;
if ( V_30 -> V_445 . V_498 && F_304 ( V_4 ) ) {
V_495 = F_311 ( V_30 -> V_445 . V_498 ,
V_4 , V_493 ,
V_30 -> V_445 . V_451 , V_449 ,
V_30 -> V_445 . V_499 ) ;
if ( V_495 < 0 )
goto V_203;
V_30 -> V_445 . V_495 = V_495 ;
V_496 = 1 ;
V_30 -> V_445 . V_10 -= V_449 ;
V_30 -> V_81 += V_449 ;
F_40 ( V_2 ) ;
if ( ( V_30 -> V_445 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_501 ) ||
( F_33 ( & V_2 -> V_67 ) > ( V_2 -> V_55 >> 1 ) ) ) {
V_30 -> V_445 . V_497 = 1 ;
V_2 -> V_453 ( V_2 , 0 ) ;
}
} else if ( V_449 > 0 ) {
V_30 -> V_445 . V_497 = 1 ;
V_2 -> V_453 ( V_2 , 0 ) ;
}
V_203:
return V_496 ;
}
static int F_312 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_37 , int V_502 )
{
T_3 * V_503 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_216 ( V_4 , V_37 , V_30 , & V_503 ) &&
V_30 -> V_41 . V_267 &&
F_223 ( V_2 , V_4 ) ) {
if ( ! V_37 -> V_504 ) {
F_69 ( F_70 ( V_2 ) , V_505 ) ;
F_240 ( V_2 , V_4 ) ;
goto V_506;
}
}
if ( ! F_224 ( V_30 , F_17 ( V_4 ) -> V_77 , F_17 ( V_4 ) -> V_80 ) ) {
if ( ! V_37 -> V_504 )
F_240 ( V_2 , V_4 ) ;
goto V_506;
}
if ( V_37 -> V_504 ) {
F_226 ( V_2 ) ;
goto V_506;
}
F_220 ( V_30 , F_17 ( V_4 ) -> V_77 ) ;
if ( V_37 -> V_39 && ! F_38 ( F_17 ( V_4 ) -> V_77 , V_30 -> V_76 ) ) {
if ( V_502 )
F_313 ( F_70 ( V_2 ) , V_507 ) ;
F_69 ( F_70 ( V_2 ) , V_508 ) ;
F_226 ( V_2 ) ;
return - 1 ;
}
return 1 ;
V_506:
F_248 ( V_4 ) ;
return 0 ;
}
int F_314 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_37 , unsigned V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_473 ;
V_30 -> V_41 . V_267 = 0 ;
if ( ( F_5 ( V_37 ) & V_509 ) == V_30 -> V_336 &&
F_17 ( V_4 ) -> V_77 == V_30 -> V_76 &&
! F_45 ( F_17 ( V_4 ) -> V_159 , V_30 -> V_94 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_392 ) {
if ( ! F_213 ( V_30 , V_37 ) )
goto V_510;
if ( ( T_4 ) ( V_30 -> V_41 . V_379 - V_30 -> V_41 . V_394 ) < 0 )
goto V_510;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_392 ) &&
V_30 -> V_76 == V_30 -> V_396 )
F_218 ( V_30 ) ;
F_206 ( V_2 , V_4 , 0 ) ;
F_248 ( V_4 ) ;
F_293 ( V_2 ) ;
return 0 ;
} else {
F_313 ( F_70 ( V_2 ) , V_507 ) ;
goto V_506;
}
} else {
int V_442 = 0 ;
int V_496 = 0 ;
if ( V_30 -> V_81 == V_30 -> V_76 &&
V_10 - V_18 <= V_30 -> V_445 . V_10 ) {
#ifdef F_315
if ( F_309 ( V_2 , V_4 , V_18 ) ) {
V_496 = 1 ;
V_442 = 1 ;
}
#endif
if ( V_30 -> V_445 . V_446 == V_447 &&
F_257 ( V_2 ) && ! V_496 ) {
F_258 ( V_450 ) ;
if ( ! F_303 ( V_2 , V_4 , V_18 ) )
V_442 = 1 ;
}
if ( V_442 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_392 ) &&
V_30 -> V_76 == V_30 -> V_396 )
F_218 ( V_30 ) ;
F_39 ( V_2 , V_4 ) ;
F_256 ( V_4 , V_18 ) ;
V_30 -> V_76 = F_17 ( V_4 ) -> V_80 ;
F_69 ( F_70 ( V_2 ) , V_511 ) ;
}
if ( V_496 )
F_316 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_442 ) {
if ( F_308 ( V_2 , V_4 ) )
goto V_512;
if ( V_18 ==
( sizeof( struct V_15 ) + V_392 ) &&
V_30 -> V_76 == V_30 -> V_396 )
F_218 ( V_30 ) ;
F_39 ( V_2 , V_4 ) ;
if ( ( int ) V_4 -> V_46 > V_2 -> V_513 )
goto V_514;
F_69 ( F_70 ( V_2 ) , V_515 ) ;
F_256 ( V_4 , V_18 ) ;
F_249 ( & V_2 -> V_439 , V_4 ) ;
F_262 ( V_4 , V_2 ) ;
V_30 -> V_76 = F_17 ( V_4 ) -> V_80 ;
}
F_41 ( V_2 , V_4 ) ;
if ( F_17 ( V_4 ) -> V_159 != V_30 -> V_92 ) {
F_206 ( V_2 , V_4 , V_349 ) ;
F_293 ( V_2 ) ;
if ( ! F_299 ( V_2 ) )
goto V_516;
}
if ( ! V_496 || V_30 -> V_76 != V_30 -> V_396 )
F_295 ( V_2 , 0 ) ;
V_516:
#ifdef F_315
if ( V_496 )
F_249 ( & V_2 -> V_517 , V_4 ) ;
else
#endif
if ( V_442 )
F_248 ( V_4 ) ;
else
V_2 -> V_453 ( V_2 , 0 ) ;
return 0 ;
}
}
V_510:
if ( V_10 < ( V_37 -> V_361 << 2 ) || F_308 ( V_2 , V_4 ) )
goto V_512;
V_473 = F_312 ( V_2 , V_4 , V_37 , 1 ) ;
if ( V_473 <= 0 )
return - V_473 ;
V_514:
if ( V_37 -> V_306 && F_206 ( V_2 , V_4 , V_346 ) < 0 )
goto V_506;
F_39 ( V_2 , V_4 ) ;
F_302 ( V_2 , V_4 , V_37 ) ;
F_254 ( V_2 , V_4 ) ;
F_293 ( V_2 ) ;
F_298 ( V_2 ) ;
return 0 ;
V_512:
F_313 ( F_70 ( V_2 ) , V_507 ) ;
V_506:
F_248 ( V_4 ) ;
return 0 ;
}
static int F_317 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_37 , unsigned V_10 )
{
T_3 * V_503 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_518 * V_519 = V_30 -> V_520 ;
int V_521 = V_30 -> V_41 . V_42 ;
F_208 ( V_4 , & V_30 -> V_41 , & V_503 , 0 ) ;
if ( V_37 -> V_306 ) {
if ( F_17 ( V_4 ) -> V_159 != V_30 -> V_94 )
goto V_522;
if ( V_30 -> V_41 . V_267 && V_30 -> V_41 . V_79 &&
! F_189 ( V_30 -> V_41 . V_79 , V_30 -> V_266 ,
V_64 ) ) {
F_69 ( F_70 ( V_2 ) , V_523 ) ;
goto V_522;
}
if ( V_37 -> V_504 ) {
F_226 ( V_2 ) ;
goto V_506;
}
if ( ! V_37 -> V_39 )
goto V_524;
F_19 ( V_30 , V_37 ) ;
V_30 -> V_332 = F_17 ( V_4 ) -> V_77 ;
F_206 ( V_2 , V_4 , V_346 ) ;
V_30 -> V_76 = F_17 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_396 = F_17 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_333 = F_154 ( V_37 -> V_47 ) ;
F_318 ( V_30 , F_17 ( V_4 ) -> V_77 ) ;
if ( ! V_30 -> V_41 . V_373 ) {
V_30 -> V_41 . V_334 = V_30 -> V_41 . V_525 = 0 ;
V_30 -> V_50 = F_9 ( V_30 -> V_50 , 65535U ) ;
}
if ( V_30 -> V_41 . V_267 ) {
V_30 -> V_41 . V_377 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_392 ;
V_30 -> V_53 -= V_392 ;
F_218 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_143 ( V_30 ) && V_526 )
F_319 ( V_30 ) ;
F_320 ( V_2 ) ;
F_171 ( V_2 , V_6 -> V_293 ) ;
F_34 ( V_2 ) ;
V_30 -> V_81 = V_30 -> V_76 ;
if ( V_519 != NULL &&
V_519 -> V_527 > 0 &&
V_30 -> V_41 . V_391 > 0 ) {
int V_528 = V_30 -> V_41 . V_391
- V_387 ;
int V_527 = V_528
+ V_519 -> V_529 ;
if ( sizeof( V_519 -> V_530 ) >= V_527 ) {
memcpy ( & V_519 -> V_530 [ V_519 -> V_529 ] ,
V_503 , V_528 ) ;
V_519 -> V_527 = V_527 ;
}
}
F_321 () ;
F_232 ( V_2 , V_413 ) ;
F_322 ( V_2 , V_4 ) ;
V_6 -> V_531 -> V_532 ( V_2 ) ;
F_66 ( V_2 ) ;
F_323 ( V_2 ) ;
V_30 -> V_533 = V_64 ;
F_28 ( V_2 ) ;
if ( F_228 ( V_2 , V_534 ) )
F_324 ( V_2 , F_325 ( V_30 ) ) ;
if ( ! V_30 -> V_41 . V_334 )
F_326 ( V_30 , V_30 -> V_333 ) ;
else
V_30 -> V_336 = 0 ;
if ( ! F_228 ( V_2 , V_407 ) ) {
V_2 -> V_422 ( V_2 ) ;
F_236 ( V_2 , V_535 , V_536 ) ;
}
if ( V_2 -> V_537 ||
V_6 -> V_538 . V_539 ||
V_6 -> V_8 . V_26 ) {
F_42 ( V_2 ) ;
V_6 -> V_8 . V_85 = V_64 ;
V_6 -> V_8 . V_27 = V_28 ;
F_8 ( V_2 ) ;
F_10 ( V_2 ) ;
F_134 ( V_2 , V_540 ,
V_541 , V_250 ) ;
V_506:
F_248 ( V_4 ) ;
return 0 ;
} else {
F_233 ( V_2 ) ;
}
return - 1 ;
}
if ( V_37 -> V_504 ) {
goto V_524;
}
if ( V_30 -> V_41 . V_395 && V_30 -> V_41 . V_267 &&
F_327 ( & V_30 -> V_41 , 0 ) )
goto V_524;
if ( V_37 -> V_39 ) {
F_232 ( V_2 , V_412 ) ;
if ( V_30 -> V_41 . V_267 ) {
V_30 -> V_41 . V_377 = 1 ;
F_218 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_392 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_76 = F_17 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_396 = F_17 ( V_4 ) -> V_77 + 1 ;
V_30 -> V_333 = F_154 ( V_37 -> V_47 ) ;
V_30 -> V_332 = F_17 ( V_4 ) -> V_77 ;
V_30 -> V_152 = V_30 -> V_333 ;
F_20 ( V_30 , V_37 ) ;
F_320 ( V_2 ) ;
F_171 ( V_2 , V_6 -> V_293 ) ;
F_34 ( V_2 ) ;
F_328 ( V_2 ) ;
#if 0
return -1;
#else
goto V_506;
#endif
}
V_524:
F_329 ( & V_30 -> V_41 ) ;
V_30 -> V_41 . V_42 = V_521 ;
goto V_506;
V_522:
F_329 ( & V_30 -> V_41 ) ;
V_30 -> V_41 . V_42 = V_521 ;
return 1 ;
}
int F_330 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_37 , unsigned V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_542 = 0 ;
int V_473 ;
V_30 -> V_41 . V_267 = 0 ;
switch ( V_2 -> V_399 ) {
case V_405 :
goto V_506;
case V_543 :
if ( V_37 -> V_306 )
return 1 ;
if ( V_37 -> V_504 )
goto V_506;
if ( V_37 -> V_39 ) {
if ( V_6 -> V_531 -> V_544 ( V_2 , V_4 ) < 0 )
return 1 ;
F_331 ( V_4 ) ;
return 0 ;
}
goto V_506;
case V_400 :
V_542 = F_317 ( V_2 , V_4 , V_37 , V_10 ) ;
if ( V_542 >= 0 )
return V_542 ;
F_302 ( V_2 , V_4 , V_37 ) ;
F_248 ( V_4 ) ;
F_293 ( V_2 ) ;
return 0 ;
}
V_473 = F_312 ( V_2 , V_4 , V_37 , 0 ) ;
if ( V_473 <= 0 )
return - V_473 ;
if ( V_37 -> V_306 ) {
int V_545 = F_206 ( V_2 , V_4 , V_346 ) > 0 ;
switch ( V_2 -> V_399 ) {
case V_412 :
if ( V_545 ) {
V_30 -> V_81 = V_30 -> V_76 ;
F_321 () ;
F_232 ( V_2 , V_413 ) ;
V_2 -> V_422 ( V_2 ) ;
if ( V_2 -> V_477 )
F_236 ( V_2 ,
V_535 , V_536 ) ;
V_30 -> V_92 = F_17 ( V_4 ) -> V_159 ;
V_30 -> V_333 = F_154 ( V_37 -> V_47 ) <<
V_30 -> V_41 . V_334 ;
F_318 ( V_30 , F_17 ( V_4 ) -> V_77 ) ;
if ( V_30 -> V_41 . V_377 )
V_30 -> V_53 -= V_392 ;
V_6 -> V_531 -> V_532 ( V_2 ) ;
F_66 ( V_2 ) ;
F_323 ( V_2 ) ;
V_30 -> V_533 = V_64 ;
F_320 ( V_2 ) ;
F_34 ( V_2 ) ;
F_28 ( V_2 ) ;
F_332 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_416 :
if ( V_30 -> V_92 == V_30 -> V_546 ) {
F_232 ( V_2 , V_417 ) ;
V_2 -> V_409 |= V_547 ;
F_52 ( F_51 ( V_2 ) ) ;
if ( ! F_228 ( V_2 , V_407 ) )
V_2 -> V_422 ( V_2 ) ;
else {
int V_548 ;
if ( V_30 -> V_549 < 0 ||
( F_17 ( V_4 ) -> V_80 != F_17 ( V_4 ) -> V_77 &&
F_45 ( F_17 ( V_4 ) -> V_80 - V_37 -> V_440 , V_30 -> V_76 ) ) ) {
F_229 ( V_2 ) ;
F_69 ( F_70 ( V_2 ) , V_550 ) ;
return 1 ;
}
V_548 = F_333 ( V_2 ) ;
if ( V_548 > V_551 ) {
F_324 ( V_2 , V_548 - V_551 ) ;
} else if ( V_37 -> V_440 || F_257 ( V_2 ) ) {
F_324 ( V_2 , V_548 ) ;
} else {
F_234 ( V_2 , V_417 , V_548 ) ;
goto V_506;
}
}
}
break;
case V_414 :
if ( V_30 -> V_92 == V_30 -> V_546 ) {
F_234 ( V_2 , V_418 , 0 ) ;
goto V_506;
}
break;
case V_415 :
if ( V_30 -> V_92 == V_30 -> V_546 ) {
F_50 ( V_2 ) ;
F_229 ( V_2 ) ;
goto V_506;
}
break;
}
} else
goto V_506;
F_302 ( V_2 , V_4 , V_37 ) ;
switch ( V_2 -> V_399 ) {
case V_403 :
case V_414 :
case V_415 :
if ( ! F_38 ( F_17 ( V_4 ) -> V_77 , V_30 -> V_76 ) )
break;
case V_416 :
case V_417 :
if ( V_2 -> V_409 & V_410 ) {
if ( F_17 ( V_4 ) -> V_80 != F_17 ( V_4 ) -> V_77 &&
F_45 ( F_17 ( V_4 ) -> V_80 - V_37 -> V_440 , V_30 -> V_76 ) ) {
F_69 ( F_70 ( V_2 ) , V_550 ) ;
F_226 ( V_2 ) ;
return 1 ;
}
}
case V_413 :
F_254 ( V_2 , V_4 ) ;
V_542 = 1 ;
break;
}
if ( V_2 -> V_399 != V_405 ) {
F_293 ( V_2 ) ;
F_298 ( V_2 ) ;
}
if ( ! V_542 ) {
V_506:
F_248 ( V_4 ) ;
}
return 0 ;
}
