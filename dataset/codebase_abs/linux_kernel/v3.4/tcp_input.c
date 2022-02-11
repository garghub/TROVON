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
T_1 V_59 = V_60 ;
int V_61 ;
if ( V_58 > 1460 )
V_59 = F_27 ( T_1 , ( 1460 * V_60 ) / V_58 , 2 ) ;
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
F_28 ( V_2 ) ;
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
} else {
V_79 <<= 3 ;
if ( V_79 < V_76 )
V_76 = V_79 ;
}
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
F_38 ( V_30 , V_71 - V_30 -> V_77 . time , 1 ) ;
V_80:
V_30 -> V_77 . V_82 = V_30 -> V_81 + V_30 -> V_23 ;
V_30 -> V_77 . time = V_71 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_83 &&
( F_16 ( V_4 ) -> V_84 -
F_16 ( V_4 ) -> V_82 >= F_2 ( V_2 ) -> V_8 . V_12 ) )
F_38 ( V_30 , V_71 - V_30 -> V_45 . V_83 , 0 ) ;
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
V_68 = 2 * ( V_30 -> V_85 - V_30 -> V_67 . V_82 ) ;
V_68 = F_31 ( V_30 -> V_67 . V_68 , V_68 ) ;
if ( V_30 -> V_67 . V_68 != V_68 ) {
int V_61 ;
V_30 -> V_67 . V_68 = V_68 ;
if ( V_86 &&
! ( V_2 -> V_64 & V_65 ) ) {
int V_87 = V_68 ;
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
V_30 -> V_55 = V_87 ;
}
}
}
V_80:
V_30 -> V_67 . V_82 = V_30 -> V_85 ;
V_30 -> V_67 . time = V_71 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_88 ;
F_44 ( V_2 ) ;
F_1 ( V_2 , V_4 ) ;
F_39 ( V_30 ) ;
V_88 = V_71 ;
if ( ! V_6 -> V_8 . V_27 ) {
F_8 ( V_2 ) ;
V_6 -> V_8 . V_27 = V_28 ;
} else {
int V_79 = V_88 - V_6 -> V_8 . V_89 ;
if ( V_79 <= V_28 / 2 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_28 / 2 ;
} else if ( V_79 < V_6 -> V_8 . V_27 ) {
V_6 -> V_8 . V_27 = ( V_6 -> V_8 . V_27 >> 1 ) + V_79 ;
if ( V_6 -> V_8 . V_27 > V_6 -> V_90 )
V_6 -> V_8 . V_27 = V_6 -> V_90 ;
} else if ( V_79 > V_6 -> V_90 ) {
F_8 ( V_2 ) ;
F_45 ( V_2 ) ;
}
}
V_6 -> V_8 . V_89 = V_88 ;
F_15 ( V_30 , V_4 ) ;
if ( V_4 -> V_10 >= 128 )
F_24 ( V_2 , V_4 ) ;
}
static void F_46 ( struct V_1 * V_2 , const T_2 V_91 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
long V_79 = V_91 ;
if ( V_79 == 0 )
V_79 = 1 ;
if ( V_30 -> V_92 != 0 ) {
V_79 -= ( V_30 -> V_92 >> 3 ) ;
V_30 -> V_92 += V_79 ;
if ( V_79 < 0 ) {
V_79 = - V_79 ;
V_79 -= ( V_30 -> V_93 >> 2 ) ;
if ( V_79 > 0 )
V_79 >>= 3 ;
} else {
V_79 -= ( V_30 -> V_93 >> 2 ) ;
}
V_30 -> V_93 += V_79 ;
if ( V_30 -> V_93 > V_30 -> V_94 ) {
V_30 -> V_94 = V_30 -> V_93 ;
if ( V_30 -> V_94 > V_30 -> V_95 )
V_30 -> V_95 = V_30 -> V_94 ;
}
if ( F_47 ( V_30 -> V_96 , V_30 -> V_97 ) ) {
if ( V_30 -> V_94 < V_30 -> V_95 )
V_30 -> V_95 -= ( V_30 -> V_95 - V_30 -> V_94 ) >> 2 ;
V_30 -> V_97 = V_30 -> V_98 ;
V_30 -> V_94 = F_48 ( V_2 ) ;
}
} else {
V_30 -> V_92 = V_79 << 3 ;
V_30 -> V_93 = V_79 << 1 ;
V_30 -> V_94 = V_30 -> V_95 = F_31 ( V_30 -> V_93 , F_48 ( V_2 ) ) ;
V_30 -> V_97 = V_30 -> V_98 ;
}
}
static inline void F_49 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
F_2 ( V_2 ) -> V_90 = F_50 ( V_30 ) ;
F_51 ( V_2 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_99 * V_100 = F_53 ( V_2 ) ;
if ( V_101 )
return;
F_54 ( V_100 ) ;
if ( V_100 && ( V_100 -> V_102 & V_103 ) ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_79 ;
unsigned long V_78 ;
if ( V_6 -> V_104 || ! V_30 -> V_92 ) {
if ( ! ( F_55 ( V_100 , V_105 ) ) )
F_56 ( V_100 , V_105 , 0 ) ;
return;
}
V_78 = F_57 ( V_100 , V_105 ) ;
V_79 = V_78 - V_30 -> V_92 ;
if ( ! ( F_55 ( V_100 , V_105 ) ) ) {
if ( V_79 <= 0 )
F_58 ( V_100 , V_105 , V_30 -> V_92 ) ;
else
F_58 ( V_100 , V_105 , V_78 - ( V_79 >> 3 ) ) ;
}
if ( ! ( F_55 ( V_100 , V_106 ) ) ) {
unsigned long V_107 ;
if ( V_79 < 0 )
V_79 = - V_79 ;
V_79 >>= 1 ;
if ( V_79 < V_30 -> V_93 )
V_79 = V_30 -> V_93 ;
V_107 = F_57 ( V_100 , V_106 ) ;
if ( V_79 >= V_107 )
V_107 = V_79 ;
else
V_107 -= ( V_107 - V_79 ) >> 2 ;
F_58 ( V_100 , V_106 , V_107 ) ;
}
if ( F_59 ( V_30 ) ) {
if ( F_60 ( V_100 , V_108 ) &&
! F_55 ( V_100 , V_108 ) &&
( V_30 -> V_109 >> 1 ) > F_60 ( V_100 , V_108 ) )
F_56 ( V_100 , V_108 , V_30 -> V_109 >> 1 ) ;
if ( ! F_55 ( V_100 , V_110 ) &&
V_30 -> V_109 > F_60 ( V_100 , V_110 ) )
F_56 ( V_100 , V_110 , V_30 -> V_109 ) ;
} else if ( V_30 -> V_109 > V_30 -> V_111 &&
V_6 -> V_112 == V_113 ) {
if ( ! F_55 ( V_100 , V_108 ) )
F_56 ( V_100 , V_108 ,
F_31 ( V_30 -> V_109 >> 1 , V_30 -> V_111 ) ) ;
if ( ! F_55 ( V_100 , V_110 ) )
F_56 ( V_100 , V_110 ,
( F_60 ( V_100 , V_110 ) +
V_30 -> V_109 ) >> 1 ) ;
} else {
if ( ! F_55 ( V_100 , V_110 ) )
F_56 ( V_100 , V_110 ,
( F_60 ( V_100 , V_110 ) +
V_30 -> V_111 ) >> 1 ) ;
if ( F_60 ( V_100 , V_108 ) &&
! F_55 ( V_100 , V_108 ) &&
V_30 -> V_111 > F_60 ( V_100 , V_108 ) )
F_56 ( V_100 , V_108 , V_30 -> V_111 ) ;
}
if ( ! F_55 ( V_100 , V_114 ) ) {
if ( F_60 ( V_100 , V_114 ) < V_30 -> V_115 &&
V_30 -> V_115 != V_116 )
F_56 ( V_100 , V_114 , V_30 -> V_115 ) ;
}
}
}
T_2 F_61 ( const struct V_29 * V_30 , const struct V_99 * V_100 )
{
T_2 V_117 = ( V_100 ? F_60 ( V_100 , V_118 ) : 0 ) ;
if ( ! V_117 )
V_117 = V_48 ;
return F_37 ( T_2 , V_117 , V_30 -> V_119 ) ;
}
void F_62 ( struct V_1 * V_2 , const int V_120 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_121 = 0 ;
V_30 -> V_122 = 0 ;
if ( V_6 -> V_112 < V_123 ) {
V_30 -> V_124 = 0 ;
if ( V_120 )
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
V_30 -> V_109 = F_9 ( V_30 -> V_109 ,
F_63 ( V_30 ) + 1U ) ;
V_30 -> V_127 = 0 ;
V_30 -> V_128 = V_30 -> V_98 ;
V_30 -> V_70 = V_71 ;
F_12 ( V_30 ) ;
F_64 ( V_2 , V_123 ) ;
}
}
static void F_65 ( struct V_29 * V_30 )
{
if ( F_66 ( V_30 ) )
V_30 -> V_129 = NULL ;
V_30 -> V_45 . V_130 &= ~ V_131 ;
}
static void F_67 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_130 |= V_132 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_99 * V_100 = F_53 ( V_2 ) ;
if ( V_100 == NULL )
goto V_133;
F_54 ( V_100 ) ;
if ( F_55 ( V_100 , V_110 ) )
V_30 -> V_119 = F_60 ( V_100 , V_110 ) ;
if ( F_60 ( V_100 , V_108 ) ) {
V_30 -> V_111 = F_60 ( V_100 , V_108 ) ;
if ( V_30 -> V_111 > V_30 -> V_119 )
V_30 -> V_111 = V_30 -> V_119 ;
} else {
V_30 -> V_111 = V_134 ;
}
if ( F_60 ( V_100 , V_114 ) &&
V_30 -> V_115 != F_60 ( V_100 , V_114 ) ) {
F_65 ( V_30 ) ;
V_30 -> V_115 = F_60 ( V_100 , V_114 ) ;
}
if ( F_60 ( V_100 , V_105 ) == 0 || V_30 -> V_92 == 0 )
goto V_133;
if ( F_57 ( V_100 , V_105 ) > V_30 -> V_92 ) {
V_30 -> V_92 = F_57 ( V_100 , V_105 ) ;
V_30 -> V_97 = V_30 -> V_98 ;
}
if ( F_57 ( V_100 , V_106 ) > V_30 -> V_93 ) {
V_30 -> V_93 = F_57 ( V_100 , V_106 ) ;
V_30 -> V_94 = V_30 -> V_95 = F_31 ( V_30 -> V_93 , F_48 ( V_2 ) ) ;
}
F_49 ( V_2 ) ;
V_133:
if ( V_30 -> V_92 == 0 ) {
V_30 -> V_93 = V_30 -> V_94 = V_30 -> V_95 = V_135 ;
F_2 ( V_2 ) -> V_90 = V_135 ;
}
if ( V_30 -> V_136 > 1 )
V_30 -> V_109 = 1 ;
else
V_30 -> V_109 = F_61 ( V_30 , V_100 ) ;
V_30 -> V_70 = V_71 ;
}
static void F_69 ( struct V_1 * V_2 , const int V_137 ,
const int V_138 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_137 > V_30 -> V_115 ) {
int V_139 ;
V_30 -> V_115 = F_9 ( V_140 , V_137 ) ;
if ( V_138 )
V_139 = V_141 ;
else if ( F_70 ( V_30 ) )
V_139 = V_142 ;
else if ( F_66 ( V_30 ) )
V_139 = V_143 ;
else
V_139 = V_144 ;
F_71 ( F_72 ( V_2 ) , V_139 ) ;
#if V_145 > 1
F_73 ( V_146 L_1 ,
V_30 -> V_45 . V_130 , F_2 ( V_2 ) -> V_112 ,
V_30 -> V_115 ,
V_30 -> V_147 ,
V_30 -> V_148 ,
V_30 -> V_124 ? V_30 -> V_149 : 0 ) ;
#endif
F_65 ( V_30 ) ;
}
}
static void F_74 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_150 == NULL ) ||
F_40 ( F_16 ( V_4 ) -> V_82 ,
F_16 ( V_30 -> V_150 ) -> V_82 ) )
V_30 -> V_150 = V_4 ;
if ( ! V_30 -> V_151 ||
F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_152 ) )
V_30 -> V_152 = F_16 ( V_4 ) -> V_84 ;
}
static void F_75 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_153 & ( V_154 | V_155 ) ) ) {
F_74 ( V_30 , V_4 ) ;
V_30 -> V_151 += F_76 ( V_4 ) ;
F_16 ( V_4 ) -> V_153 |= V_154 ;
}
}
static void F_77 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_74 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_153 & ( V_154 | V_155 ) ) ) {
V_30 -> V_151 += F_76 ( V_4 ) ;
F_16 ( V_4 ) -> V_153 |= V_154 ;
}
}
static int F_78 ( struct V_29 * V_30 , int V_156 ,
T_1 V_157 , T_1 V_84 )
{
if ( F_47 ( V_84 , V_30 -> V_98 ) || ! F_40 ( V_157 , V_84 ) )
return 0 ;
if ( ! F_40 ( V_157 , V_30 -> V_98 ) )
return 0 ;
if ( F_47 ( V_157 , V_30 -> V_96 ) )
return 1 ;
if ( ! V_156 || ! V_30 -> V_124 )
return 0 ;
if ( F_47 ( V_84 , V_30 -> V_96 ) )
return 0 ;
if ( ! F_40 ( V_157 , V_30 -> V_124 ) )
return 1 ;
if ( ! F_47 ( V_84 , V_30 -> V_124 ) )
return 0 ;
return ! F_40 ( V_157 , V_84 - V_30 -> V_158 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_159 = 0 ;
T_1 V_160 = V_30 -> V_98 ;
T_1 V_161 = F_80 ( V_30 ) ;
if ( ! F_66 ( V_30 ) || ! V_30 -> V_162 ||
! F_47 ( V_161 , V_30 -> V_163 ) ||
V_6 -> V_112 != V_164 )
return;
F_81 (skb, sk) {
T_1 V_165 = F_16 ( V_4 ) -> V_165 ;
if ( V_4 == F_82 ( V_2 ) )
break;
if ( V_159 == V_30 -> V_162 )
break;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_153 & V_166 ) )
continue;
if ( F_47 ( V_161 , V_165 ) ) {
F_16 ( V_4 ) -> V_153 &= ~ V_166 ;
V_30 -> V_162 -= F_76 ( V_4 ) ;
F_77 ( V_30 , V_4 ) ;
F_71 ( F_72 ( V_2 ) , V_167 ) ;
} else {
if ( F_40 ( V_165 , V_160 ) )
V_160 = V_165 ;
V_159 += F_76 ( V_4 ) ;
}
}
if ( V_30 -> V_162 )
V_30 -> V_163 = V_160 ;
}
static int F_83 ( struct V_1 * V_2 , const struct V_3 * V_168 ,
struct V_169 * V_170 , int V_171 ,
T_1 V_172 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_173 = F_84 ( & V_170 [ 0 ] . V_157 ) ;
T_1 V_174 = F_84 ( & V_170 [ 0 ] . V_84 ) ;
int V_175 = 0 ;
if ( F_40 ( V_173 , F_16 ( V_168 ) -> V_165 ) ) {
V_175 = 1 ;
F_67 ( V_30 ) ;
F_71 ( F_72 ( V_2 ) , V_176 ) ;
} else if ( V_171 > 1 ) {
T_1 V_177 = F_84 ( & V_170 [ 1 ] . V_84 ) ;
T_1 V_178 = F_84 ( & V_170 [ 1 ] . V_157 ) ;
if ( ! F_47 ( V_174 , V_177 ) &&
! F_40 ( V_173 , V_178 ) ) {
V_175 = 1 ;
F_67 ( V_30 ) ;
F_71 ( F_72 ( V_2 ) ,
V_179 ) ;
}
}
if ( V_175 && V_30 -> V_124 && V_30 -> V_149 &&
! F_47 ( V_174 , V_172 ) &&
F_47 ( V_174 , V_30 -> V_124 ) )
V_30 -> V_149 -- ;
return V_175 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_157 , T_1 V_84 )
{
int V_180 , V_181 ;
unsigned int V_182 ;
unsigned int V_58 ;
V_180 = ! F_47 ( V_157 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( F_76 ( V_4 ) > 1 && ! V_180 &&
F_47 ( F_16 ( V_4 ) -> V_84 , V_157 ) ) {
V_58 = F_86 ( V_4 ) ;
V_180 = ! F_47 ( V_157 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_180 ) {
V_182 = V_157 - F_16 ( V_4 ) -> V_82 ;
if ( V_182 < V_58 )
V_182 = V_58 ;
} else {
V_182 = V_84 - F_16 ( V_4 ) -> V_82 ;
if ( V_182 < V_58 )
return - V_183 ;
}
if ( V_182 > V_58 ) {
unsigned int V_184 = ( V_182 / V_58 ) * V_58 ;
if ( ! V_180 && V_184 < V_182 ) {
V_184 += V_58 ;
if ( V_184 > V_4 -> V_10 )
return 0 ;
}
V_182 = V_184 ;
}
V_181 = F_87 ( V_2 , V_4 , V_182 , V_58 ) ;
if ( V_181 < 0 )
return V_181 ;
}
return V_180 ;
}
static T_3 F_88 ( struct V_1 * V_2 ,
struct V_185 * V_186 , T_3 V_153 ,
T_1 V_157 , T_1 V_84 ,
int V_175 , int V_187 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_188 = V_186 -> V_188 ;
if ( V_175 && ( V_153 & V_189 ) ) {
if ( V_30 -> V_124 && V_30 -> V_149 &&
F_47 ( V_84 , V_30 -> V_124 ) )
V_30 -> V_149 -- ;
if ( V_153 & V_155 )
V_186 -> V_190 = F_9 ( V_188 , V_186 -> V_190 ) ;
}
if ( ! F_47 ( V_84 , V_30 -> V_96 ) )
return V_153 ;
if ( ! ( V_153 & V_155 ) ) {
if ( V_153 & V_166 ) {
if ( V_153 & V_154 ) {
V_153 &= ~ ( V_154 | V_166 ) ;
V_30 -> V_151 -= V_187 ;
V_30 -> V_162 -= V_187 ;
}
} else {
if ( ! ( V_153 & V_189 ) ) {
if ( F_40 ( V_157 ,
F_80 ( V_30 ) ) )
V_186 -> V_190 = F_9 ( V_188 ,
V_186 -> V_190 ) ;
if ( ! F_47 ( V_84 , V_30 -> V_191 ) )
V_186 -> V_192 |= V_193 ;
}
if ( V_153 & V_154 ) {
V_153 &= ~ V_154 ;
V_30 -> V_151 -= V_187 ;
}
}
V_153 |= V_155 ;
V_186 -> V_192 |= V_194 ;
V_30 -> V_148 += V_187 ;
V_188 += V_187 ;
if ( ! F_66 ( V_30 ) && ( V_30 -> V_129 != NULL ) &&
F_40 ( V_157 , F_16 ( V_30 -> V_129 ) -> V_82 ) )
V_30 -> V_195 += V_187 ;
if ( V_188 > V_30 -> V_147 )
V_30 -> V_147 = V_188 ;
}
if ( V_175 && ( V_153 & V_166 ) ) {
V_153 &= ~ V_166 ;
V_30 -> V_162 -= V_187 ;
}
return V_153 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_185 * V_186 ,
unsigned int V_187 , int V_196 , int V_58 ,
int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_197 = F_90 ( V_2 , V_4 ) ;
T_1 V_157 = F_16 ( V_4 ) -> V_82 ;
T_1 V_84 = V_157 + V_196 ;
F_91 ( ! V_187 ) ;
F_88 ( V_2 , V_186 , F_16 ( V_4 ) -> V_153 ,
V_157 , V_84 , V_175 , V_187 ) ;
if ( V_4 == V_30 -> V_129 )
V_30 -> V_195 += V_187 ;
F_16 ( V_197 ) -> V_84 += V_196 ;
F_16 ( V_4 ) -> V_82 += V_196 ;
F_3 ( V_197 ) -> V_198 += V_187 ;
F_91 ( F_3 ( V_4 ) -> V_198 < V_187 ) ;
F_3 ( V_4 ) -> V_198 -= V_187 ;
if ( ! F_3 ( V_197 ) -> V_11 ) {
F_3 ( V_197 ) -> V_11 = V_58 ;
F_3 ( V_197 ) -> V_199 = V_2 -> V_200 ;
}
if ( F_3 ( V_4 ) -> V_198 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_199 = 0 ;
}
F_16 ( V_197 ) -> V_153 |= ( F_16 ( V_4 ) -> V_153 & V_201 ) ;
if ( V_4 -> V_10 > 0 ) {
F_91 ( ! F_76 ( V_4 ) ) ;
F_71 ( F_72 ( V_2 ) , V_202 ) ;
return 0 ;
}
if ( V_4 == V_30 -> V_150 )
V_30 -> V_150 = V_197 ;
if ( V_4 == V_30 -> V_203 )
V_30 -> V_203 = V_197 ;
if ( V_4 == V_30 -> V_129 ) {
V_30 -> V_129 = V_197 ;
V_30 -> V_195 -= F_76 ( V_197 ) ;
}
F_16 ( V_4 ) -> V_204 |= F_16 ( V_197 ) -> V_204 ;
if ( V_4 == F_92 ( V_2 ) )
F_93 ( V_2 , V_4 ) ;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
F_71 ( F_72 ( V_2 ) , V_205 ) ;
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
struct V_185 * V_186 ,
T_1 V_157 , T_1 V_84 ,
int V_175 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_197 ;
int V_58 ;
int V_187 = 0 ;
int V_10 ;
int V_180 ;
if ( ! F_101 ( V_2 ) )
goto V_206;
if ( ! V_175 &&
( F_16 ( V_4 ) -> V_153 & ( V_154 | V_166 ) ) == V_166 )
goto V_206;
if ( ! F_97 ( V_4 ) )
goto V_206;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
goto V_206;
if ( F_102 ( V_4 == F_103 ( V_2 ) ) )
goto V_206;
V_197 = F_90 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_197 ) -> V_153 & V_207 ) != V_155 )
goto V_206;
V_180 = ! F_47 ( V_157 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( V_180 ) {
V_10 = V_4 -> V_10 ;
V_187 = F_76 ( V_4 ) ;
V_58 = F_96 ( V_4 ) ;
if ( V_58 != F_96 ( V_197 ) )
goto V_206;
} else {
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_157 ) )
goto V_208;
if ( F_76 ( V_4 ) <= 1 )
goto V_208;
V_180 = ! F_47 ( V_157 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_180 ) {
goto V_206;
}
V_10 = V_84 - F_16 ( V_4 ) -> V_82 ;
F_91 ( V_10 < 0 ) ;
F_91 ( V_10 > V_4 -> V_10 ) ;
V_58 = F_86 ( V_4 ) ;
if ( V_58 != F_96 ( V_197 ) )
goto V_206;
if ( V_10 == V_58 ) {
V_187 = 1 ;
} else if ( V_10 < V_58 ) {
goto V_208;
} else {
V_187 = V_10 / V_58 ;
V_10 = V_187 * V_58 ;
}
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_82 + V_10 , V_30 -> V_96 ) )
goto V_206;
if ( ! F_104 ( V_197 , V_4 , V_10 ) )
goto V_206;
if ( ! F_89 ( V_2 , V_4 , V_186 , V_187 , V_10 , V_58 , V_175 ) )
goto V_209;
if ( V_197 == F_105 ( V_2 ) )
goto V_209;
V_4 = F_106 ( V_2 , V_197 ) ;
if ( ! F_97 ( V_4 ) ||
( V_4 == F_82 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_153 & V_207 ) != V_155 ) ||
( V_58 != F_96 ( V_4 ) ) )
goto V_209;
V_10 = V_4 -> V_10 ;
if ( F_104 ( V_197 , V_4 , V_10 ) ) {
V_187 += F_76 ( V_4 ) ;
F_89 ( V_2 , V_4 , V_186 , F_76 ( V_4 ) , V_10 , V_58 , 0 ) ;
}
V_209:
V_186 -> V_188 += V_187 ;
return V_197 ;
V_208:
return V_4 ;
V_206:
F_71 ( F_72 ( V_2 ) , V_210 ) ;
return NULL ;
}
static struct V_3 * F_107 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_211 * V_212 ,
struct V_185 * V_186 ,
T_1 V_157 , T_1 V_84 ,
int V_213 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_214 ;
F_108 (skb, sk) {
int V_180 = 0 ;
int V_175 = V_213 ;
if ( V_4 == F_82 ( V_2 ) )
break;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_84 ) )
break;
if ( ( V_212 != NULL ) &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_212 -> V_84 ) ) {
V_180 = F_85 ( V_2 , V_4 ,
V_212 -> V_157 ,
V_212 -> V_84 ) ;
if ( V_180 > 0 )
V_175 = 1 ;
}
if ( V_180 <= 0 ) {
V_214 = F_100 ( V_2 , V_4 , V_186 ,
V_157 , V_84 , V_175 ) ;
if ( V_214 != NULL ) {
if ( V_214 != V_4 ) {
V_4 = V_214 ;
continue;
}
V_180 = 0 ;
} else {
V_180 = F_85 ( V_2 , V_4 ,
V_157 ,
V_84 ) ;
}
}
if ( F_102 ( V_180 < 0 ) )
break;
if ( V_180 ) {
F_16 ( V_4 ) -> V_153 =
F_88 ( V_2 ,
V_186 ,
F_16 ( V_4 ) -> V_153 ,
F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ,
V_175 ,
F_76 ( V_4 ) ) ;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 ,
F_80 ( V_30 ) ) )
F_93 ( V_2 , V_4 ) ;
}
V_186 -> V_188 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_109 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_185 * V_186 ,
T_1 V_215 )
{
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_215 ) )
break;
V_186 -> V_188 += F_76 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_110 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_211 * V_212 ,
struct V_185 * V_186 ,
T_1 V_215 )
{
if ( V_212 == NULL )
return V_4 ;
if ( F_40 ( V_212 -> V_157 , V_215 ) ) {
V_4 = F_109 ( V_4 , V_2 , V_186 , V_212 -> V_157 ) ;
V_4 = F_107 ( V_4 , V_2 , NULL , V_186 ,
V_212 -> V_157 , V_212 -> V_84 ,
1 ) ;
}
return V_4 ;
}
static int F_111 ( const struct V_29 * V_30 , const struct V_211 * V_216 )
{
return V_216 < V_30 -> V_217 + F_112 ( V_30 -> V_217 ) ;
}
static int
F_113 ( struct V_1 * V_2 , const struct V_3 * V_168 ,
T_1 V_172 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_218 = ( F_4 ( V_168 ) +
F_16 ( V_168 ) -> V_153 ) ;
struct V_169 * V_219 = (struct V_169 * ) ( V_218 + 2 ) ;
struct V_211 V_170 [ V_220 ] ;
struct V_211 * V_216 ;
struct V_185 V_186 ;
struct V_3 * V_4 ;
int V_171 = F_9 ( V_220 , ( V_218 [ 1 ] - V_221 ) >> 3 ) ;
int V_222 ;
int V_223 = 0 ;
int V_224 , V_225 ;
int V_226 ;
V_186 . V_192 = 0 ;
V_186 . V_190 = V_30 -> V_227 ;
if ( ! V_30 -> V_148 ) {
if ( F_114 ( V_30 -> V_147 ) )
V_30 -> V_147 = 0 ;
F_115 ( V_2 ) ;
}
V_223 = F_83 ( V_2 , V_168 , V_219 ,
V_171 , V_172 ) ;
if ( V_223 )
V_186 . V_192 |= V_228 ;
if ( F_40 ( F_16 ( V_168 ) -> V_165 , V_172 - V_30 -> V_158 ) )
return 0 ;
if ( ! V_30 -> V_227 )
goto V_209;
V_222 = 0 ;
V_226 = 0 ;
for ( V_224 = 0 ; V_224 < V_171 ; V_224 ++ ) {
int V_175 = ! V_224 && V_223 ;
V_170 [ V_222 ] . V_157 = F_84 ( & V_219 [ V_224 ] . V_157 ) ;
V_170 [ V_222 ] . V_84 = F_84 ( & V_219 [ V_224 ] . V_84 ) ;
if ( ! F_78 ( V_30 , V_175 ,
V_170 [ V_222 ] . V_157 ,
V_170 [ V_222 ] . V_84 ) ) {
int V_139 ;
if ( V_175 ) {
if ( ! V_30 -> V_124 )
V_139 = V_229 ;
else
V_139 = V_230 ;
} else {
if ( ( F_16 ( V_168 ) -> V_165 != V_30 -> V_96 ) &&
! F_47 ( V_170 [ V_222 ] . V_84 , V_30 -> V_96 ) )
continue;
V_139 = V_231 ;
}
F_71 ( F_72 ( V_2 ) , V_139 ) ;
if ( V_224 == 0 )
V_226 = - 1 ;
continue;
}
if ( ! F_47 ( V_170 [ V_222 ] . V_84 , V_172 ) )
continue;
V_222 ++ ;
}
for ( V_224 = V_222 - 1 ; V_224 > 0 ; V_224 -- ) {
for ( V_225 = 0 ; V_225 < V_224 ; V_225 ++ ) {
if ( F_47 ( V_170 [ V_225 ] . V_157 , V_170 [ V_225 + 1 ] . V_157 ) ) {
F_116 ( V_170 [ V_225 ] , V_170 [ V_225 + 1 ] ) ;
if ( V_225 == V_226 )
V_226 = V_225 + 1 ;
}
}
}
V_4 = F_103 ( V_2 ) ;
V_186 . V_188 = 0 ;
V_224 = 0 ;
if ( ! V_30 -> V_148 ) {
V_216 = V_30 -> V_217 + F_112 ( V_30 -> V_217 ) ;
} else {
V_216 = V_30 -> V_217 ;
while ( F_111 ( V_30 , V_216 ) && ! V_216 -> V_157 &&
! V_216 -> V_84 )
V_216 ++ ;
}
while ( V_224 < V_222 ) {
T_1 V_157 = V_170 [ V_224 ] . V_157 ;
T_1 V_84 = V_170 [ V_224 ] . V_84 ;
int V_175 = ( V_223 && ( V_224 == V_226 ) ) ;
struct V_211 * V_212 = NULL ;
if ( V_223 && ( ( V_224 + 1 ) == V_226 ) )
V_212 = & V_170 [ V_224 + 1 ] ;
while ( F_111 ( V_30 , V_216 ) &&
! F_40 ( V_157 , V_216 -> V_84 ) )
V_216 ++ ;
if ( F_111 ( V_30 , V_216 ) && ! V_175 &&
F_47 ( V_84 , V_216 -> V_157 ) ) {
if ( F_40 ( V_157 , V_216 -> V_157 ) ) {
V_4 = F_109 ( V_4 , V_2 , & V_186 ,
V_157 ) ;
V_4 = F_107 ( V_4 , V_2 , V_212 ,
& V_186 ,
V_157 ,
V_216 -> V_157 ,
V_175 ) ;
}
if ( ! F_47 ( V_84 , V_216 -> V_84 ) )
goto V_232;
V_4 = F_110 ( V_4 , V_2 , V_212 ,
& V_186 ,
V_216 -> V_84 ) ;
if ( F_80 ( V_30 ) == V_216 -> V_84 ) {
V_4 = F_92 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_186 . V_188 = V_30 -> V_147 ;
V_216 ++ ;
goto V_233;
}
V_4 = F_109 ( V_4 , V_2 , & V_186 , V_216 -> V_84 ) ;
V_216 ++ ;
continue;
}
if ( ! F_40 ( V_157 , F_80 ( V_30 ) ) ) {
V_4 = F_92 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_186 . V_188 = V_30 -> V_147 ;
}
V_4 = F_109 ( V_4 , V_2 , & V_186 , V_157 ) ;
V_233:
V_4 = F_107 ( V_4 , V_2 , V_212 , & V_186 ,
V_157 , V_84 , V_175 ) ;
V_232:
if ( F_47 ( V_84 , V_30 -> V_191 ) )
V_186 . V_192 &= ~ V_193 ;
V_224 ++ ;
}
for ( V_224 = 0 ; V_224 < F_112 ( V_30 -> V_217 ) - V_222 ; V_224 ++ ) {
V_30 -> V_217 [ V_224 ] . V_157 = 0 ;
V_30 -> V_217 [ V_224 ] . V_84 = 0 ;
}
for ( V_225 = 0 ; V_225 < V_222 ; V_225 ++ )
V_30 -> V_217 [ V_224 ++ ] = V_170 [ V_225 ] ;
F_79 ( V_2 ) ;
F_117 ( V_30 ) ;
if ( ( V_186 . V_190 < V_30 -> V_147 ) &&
( ( V_6 -> V_112 != V_234 ) || V_30 -> V_124 ) &&
( ! V_30 -> V_191 || F_47 ( V_30 -> V_96 , V_30 -> V_191 ) ) )
F_69 ( V_2 , V_30 -> V_147 - V_186 . V_190 , 0 ) ;
V_209:
#if V_145 > 0
F_114 ( ( int ) V_30 -> V_148 < 0 ) ;
F_114 ( ( int ) V_30 -> V_151 < 0 ) ;
F_114 ( ( int ) V_30 -> V_162 < 0 ) ;
F_114 ( ( int ) F_63 ( V_30 ) < 0 ) ;
#endif
return V_186 . V_192 ;
}
static int F_118 ( struct V_29 * V_30 )
{
T_1 V_235 ;
V_235 = F_31 ( V_30 -> V_151 , 1U ) ;
V_235 = F_9 ( V_235 , V_30 -> V_227 ) ;
if ( ( V_30 -> V_148 + V_235 ) > V_30 -> V_227 ) {
V_30 -> V_148 = V_30 -> V_227 - V_235 ;
return 1 ;
}
return 0 ;
}
static void F_119 ( struct V_1 * V_2 , const int V_236 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_118 ( V_30 ) )
F_69 ( V_2 , V_30 -> V_227 + V_236 , 0 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_148 ++ ;
F_119 ( V_2 , 0 ) ;
F_117 ( V_30 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_237 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_237 > 0 ) {
if ( V_237 - 1 >= V_30 -> V_148 )
V_30 -> V_148 = 0 ;
else
V_30 -> V_148 -= V_237 - 1 ;
}
F_119 ( V_2 , V_237 ) ;
F_117 ( V_30 ) ;
}
static inline void F_122 ( struct V_29 * V_30 )
{
V_30 -> V_148 = 0 ;
}
static int F_123 ( const struct V_29 * V_30 )
{
return ( V_238 == 0x2 ) && ! F_70 ( V_30 ) ;
}
int F_124 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_238 )
return 0 ;
if ( V_6 -> V_239 . V_240 )
return 0 ;
if ( F_123 ( V_30 ) )
return 1 ;
if ( V_30 -> V_162 > 1 )
return 0 ;
V_4 = F_103 ( V_2 ) ;
if ( F_125 ( V_2 , V_4 ) )
return 1 ;
V_4 = F_106 ( V_2 , V_4 ) ;
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_153 & V_189 )
return 0 ;
if ( ! ( F_16 ( V_4 ) -> V_153 & V_155 ) )
break;
}
return 1 ;
}
void F_126 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ( ! V_30 -> V_241 && V_6 -> V_112 <= V_242 ) ||
V_30 -> V_96 == V_30 -> V_128 ||
( ( V_6 -> V_112 == V_234 || V_30 -> V_241 ) &&
! V_6 -> V_243 ) ) {
V_30 -> V_121 = F_127 ( V_2 ) ;
if ( V_30 -> V_241 ) {
T_1 V_244 ;
V_244 = V_30 -> V_109 ;
V_30 -> V_109 = 2 ;
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
V_30 -> V_109 = V_244 ;
} else {
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
}
F_128 ( V_2 , V_245 ) ;
}
V_30 -> V_124 = V_30 -> V_96 ;
V_30 -> V_149 = 0 ;
V_4 = F_103 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_153 & V_189 )
V_30 -> V_124 = 0 ;
if ( F_16 ( V_4 ) -> V_153 & V_166 ) {
F_16 ( V_4 ) -> V_153 &= ~ V_166 ;
V_30 -> V_162 -= F_76 ( V_4 ) ;
}
F_117 ( V_30 ) ;
V_30 -> V_109 = F_9 ( V_30 -> V_109 , F_63 ( V_30 ) + 1 ) ;
if ( F_123 ( V_30 ) && ( V_30 -> V_241 ||
( ( 1 << V_6 -> V_112 ) & ( V_246 | V_247 ) ) ) &&
F_47 ( V_30 -> V_128 , V_30 -> V_96 ) ) {
V_30 -> V_191 = V_30 -> V_128 ;
} else {
V_30 -> V_191 = V_30 -> V_98 ;
}
F_64 ( V_2 , V_242 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
V_30 -> V_241 = 1 ;
}
static void F_129 ( struct V_1 * V_2 , int V_248 , int V_192 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
V_30 -> V_151 = 0 ;
V_30 -> V_162 = 0 ;
if ( F_70 ( V_30 ) )
F_122 ( V_30 ) ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_153 &= ~ V_154 ;
if ( ( V_30 -> V_241 == 1 ) && ! ( V_192 & V_249 ) ) {
if ( F_16 ( V_4 ) -> V_153 & V_166 )
V_30 -> V_162 += F_76 ( V_4 ) ;
V_192 |= V_249 ;
} else {
if ( F_16 ( V_4 ) -> V_153 & V_189 )
V_30 -> V_124 = 0 ;
F_16 ( V_4 ) -> V_153 &= ~ V_166 ;
}
if ( ! ( F_16 ( V_4 ) -> V_153 & V_155 ) ) {
F_16 ( V_4 ) -> V_153 |= V_154 ;
V_30 -> V_151 += F_76 ( V_4 ) ;
V_30 -> V_152 = F_16 ( V_4 ) -> V_84 ;
}
}
F_117 ( V_30 ) ;
V_30 -> V_109 = F_63 ( V_30 ) + V_248 ;
V_30 -> V_127 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_241 = 0 ;
V_30 -> V_122 = 0 ;
V_30 -> V_115 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_64 ( V_2 , V_234 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
F_130 ( V_30 ) ;
}
static void F_131 ( struct V_29 * V_30 )
{
V_30 -> V_162 = 0 ;
V_30 -> V_151 = 0 ;
V_30 -> V_124 = 0 ;
V_30 -> V_149 = 0 ;
}
void F_132 ( struct V_29 * V_30 )
{
F_131 ( V_30 ) ;
V_30 -> V_147 = 0 ;
V_30 -> V_148 = 0 ;
}
void F_133 ( struct V_1 * V_2 , int V_250 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_6 -> V_112 <= V_242 || V_30 -> V_96 == V_30 -> V_128 ||
( V_6 -> V_112 == V_234 && ! V_6 -> V_243 ) ) {
V_30 -> V_121 = F_127 ( V_2 ) ;
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
F_128 ( V_2 , V_251 ) ;
}
V_30 -> V_109 = 1 ;
V_30 -> V_127 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_122 = 0 ;
F_131 ( V_30 ) ;
if ( F_70 ( V_30 ) )
F_122 ( V_30 ) ;
if ( ! V_250 ) {
V_30 -> V_124 = V_30 -> V_96 ;
} else {
V_30 -> V_148 = 0 ;
V_30 -> V_147 = 0 ;
}
F_130 ( V_30 ) ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_153 & V_189 )
V_30 -> V_124 = 0 ;
F_16 ( V_4 ) -> V_153 &= ( ~ V_207 ) | V_155 ;
if ( ! ( F_16 ( V_4 ) -> V_153 & V_155 ) || V_250 ) {
F_16 ( V_4 ) -> V_153 &= ~ V_155 ;
F_16 ( V_4 ) -> V_153 |= V_154 ;
V_30 -> V_151 += F_76 ( V_4 ) ;
V_30 -> V_152 = F_16 ( V_4 ) -> V_84 ;
}
}
F_117 ( V_30 ) ;
V_30 -> V_115 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_64 ( V_2 , V_234 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
V_30 -> V_241 = 0 ;
}
static int F_134 ( struct V_1 * V_2 , int V_192 )
{
if ( V_192 & V_252 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_71 ( F_72 ( V_2 ) , V_253 ) ;
F_133 ( V_2 , 1 ) ;
V_6 -> V_243 ++ ;
F_135 ( V_2 , F_103 ( V_2 ) ) ;
F_136 ( V_2 , V_254 ,
V_6 -> V_90 , V_255 ) ;
return 1 ;
}
return 0 ;
}
static inline int F_137 ( const struct V_29 * V_30 )
{
return F_70 ( V_30 ) ? V_30 -> V_148 + 1 : V_30 -> V_147 ;
}
static inline int F_138 ( const struct V_29 * V_30 )
{
return F_66 ( V_30 ) ? V_30 -> V_147 : V_30 -> V_148 + 1 ;
}
static inline int F_139 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_71 - F_16 ( V_4 ) -> V_256 > F_2 ( V_2 ) -> V_90 ;
}
static inline int F_140 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_227 &&
F_139 ( V_2 , F_103 ( V_2 ) ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_227 ;
if ( V_30 -> V_241 )
return 0 ;
if ( V_30 -> V_151 )
return 1 ;
if ( F_138 ( V_30 ) > V_30 -> V_115 )
return 1 ;
if ( F_66 ( V_30 ) && F_140 ( V_2 ) )
return 1 ;
V_227 = V_30 -> V_227 ;
if ( V_227 <= V_30 -> V_115 &&
V_30 -> V_148 >= F_27 ( T_2 , V_227 / 2 , V_116 ) &&
! F_142 ( V_2 ) ) {
return 1 ;
}
if ( ( V_30 -> V_257 || V_258 ) &&
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
V_4 = V_30 -> V_203 ;
if ( V_30 -> V_203 == NULL )
V_4 = F_103 ( V_2 ) ;
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( ! F_139 ( V_2 , V_4 ) )
break;
F_75 ( V_30 , V_4 ) ;
}
V_30 -> V_203 = V_4 ;
F_117 ( V_30 ) ;
}
static void F_146 ( struct V_1 * V_2 , int V_259 , int V_260 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_159 , V_261 ;
int V_181 ;
unsigned int V_58 ;
const T_1 V_262 = F_144 ( V_30 ) ? V_30 -> V_98 : V_30 -> V_128 ;
F_114 ( V_259 > V_30 -> V_227 ) ;
if ( V_30 -> V_129 ) {
V_4 = V_30 -> V_129 ;
V_159 = V_30 -> V_195 ;
if ( V_260 && V_4 != F_103 ( V_2 ) )
return;
} else {
V_4 = F_103 ( V_2 ) ;
V_159 = 0 ;
}
F_108 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
V_30 -> V_129 = V_4 ;
V_30 -> V_195 = V_159 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_262 ) )
break;
V_261 = V_159 ;
if ( F_66 ( V_30 ) || F_70 ( V_30 ) ||
( F_16 ( V_4 ) -> V_153 & V_155 ) )
V_159 += F_76 ( V_4 ) ;
if ( V_159 > V_259 ) {
if ( ( F_144 ( V_30 ) && ! F_66 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_153 & V_155 ) ||
( V_261 >= V_259 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_181 = F_87 ( V_2 , V_4 , ( V_259 - V_261 ) * V_58 , V_58 ) ;
if ( V_181 < 0 )
break;
V_159 = V_259 ;
}
F_75 ( V_30 , V_4 ) ;
if ( V_260 )
break;
}
F_117 ( V_30 ) ;
}
static void F_147 ( struct V_1 * V_2 , int V_263 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_70 ( V_30 ) ) {
F_146 ( V_2 , 1 , 1 ) ;
} else if ( F_66 ( V_30 ) ) {
int V_264 = V_30 -> V_147 - V_30 -> V_115 ;
if ( V_264 <= 0 )
V_264 = 1 ;
F_146 ( V_2 , V_264 , 0 ) ;
} else {
int V_265 = V_30 -> V_148 - V_30 -> V_115 ;
if ( V_265 >= 0 )
F_146 ( V_2 , V_265 , 0 ) ;
else if ( V_263 )
F_146 ( V_2 , 1 , 1 ) ;
}
F_145 ( V_2 ) ;
}
static inline void F_148 ( struct V_29 * V_30 )
{
V_30 -> V_109 = F_9 ( V_30 -> V_109 ,
F_63 ( V_30 ) + F_149 ( V_30 ) ) ;
V_30 -> V_70 = V_71 ;
}
static inline T_1 F_150 ( const struct V_1 * V_2 )
{
const struct V_266 * V_267 = F_2 ( V_2 ) -> V_125 ;
return V_267 -> V_268 ? V_267 -> V_268 ( V_2 ) : F_7 ( V_2 ) -> V_111 ;
}
static void F_151 ( struct V_1 * V_2 , int V_192 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_269 = V_30 -> V_127 + 1 ;
if ( ( V_192 & ( V_270 | V_228 ) ) ||
( F_70 ( V_30 ) && ! ( V_192 & V_271 ) ) ) {
V_30 -> V_127 = V_269 & 1 ;
V_269 >>= 1 ;
if ( V_269 && V_30 -> V_109 > F_150 ( V_2 ) )
V_30 -> V_109 -= V_269 ;
V_30 -> V_109 = F_9 ( V_30 -> V_109 , F_63 ( V_30 ) + 1 ) ;
V_30 -> V_70 = V_71 ;
}
}
static inline int F_152 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_272 ||
( V_30 -> V_45 . V_273 && V_30 -> V_45 . V_83 &&
F_40 ( V_30 -> V_45 . V_83 , V_30 -> V_272 ) ) ;
}
static void F_153 ( struct V_1 * V_2 , const char * V_274 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_275 * V_276 = F_154 ( V_2 ) ;
if ( V_2 -> V_277 == V_278 ) {
F_73 ( V_146 L_2 ,
V_274 ,
& V_276 -> V_279 , F_155 ( V_276 -> V_280 ) ,
V_30 -> V_109 , F_156 ( V_30 ) ,
V_30 -> V_111 , V_30 -> V_121 ,
V_30 -> V_227 ) ;
}
#if F_157 ( V_281 )
else if ( V_2 -> V_277 == V_282 ) {
struct V_283 * V_284 = F_158 ( V_2 ) ;
F_73 ( V_146 L_3 ,
V_274 ,
& V_284 -> V_285 , F_155 ( V_276 -> V_280 ) ,
V_30 -> V_109 , F_156 ( V_30 ) ,
V_30 -> V_111 , V_30 -> V_121 ,
V_30 -> V_227 ) ;
}
#endif
}
static void F_159 ( struct V_1 * V_2 , const bool V_286 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_121 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_125 -> V_287 )
V_30 -> V_109 = V_6 -> V_125 -> V_287 ( V_2 ) ;
else
V_30 -> V_109 = F_31 ( V_30 -> V_109 , V_30 -> V_111 << 1 ) ;
if ( V_286 && V_30 -> V_121 > V_30 -> V_111 ) {
V_30 -> V_111 = V_30 -> V_121 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_109 = F_31 ( V_30 -> V_109 , V_30 -> V_111 ) ;
}
V_30 -> V_70 = V_71 ;
}
static inline int F_160 ( const struct V_29 * V_30 )
{
return V_30 -> V_124 && ( ! V_30 -> V_149 || F_152 ( V_30 ) ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_160 ( V_30 ) ) {
int V_139 ;
F_153 ( V_2 , F_2 ( V_2 ) -> V_112 == V_234 ? L_4 : L_5 ) ;
F_159 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_112 == V_234 )
V_139 = V_288 ;
else
V_139 = V_289 ;
F_71 ( F_72 ( V_2 ) , V_139 ) ;
V_30 -> V_124 = 0 ;
}
if ( V_30 -> V_96 == V_30 -> V_128 && F_70 ( V_30 ) ) {
F_148 ( V_30 ) ;
return 1 ;
}
F_64 ( V_2 , V_113 ) ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_124 && ! V_30 -> V_149 ) {
F_153 ( V_2 , L_6 ) ;
F_159 ( V_2 , true ) ;
V_30 -> V_124 = 0 ;
F_71 ( F_72 ( V_2 ) , V_290 ) ;
}
}
static int F_163 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_162 )
return 1 ;
V_4 = F_103 ( V_2 ) ;
if ( F_102 ( V_4 && F_16 ( V_4 ) -> V_153 & V_201 ) )
return 1 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , int V_237 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_291 = F_70 ( V_30 ) || ( F_137 ( V_30 ) > V_30 -> V_115 ) ;
if ( F_160 ( V_30 ) ) {
if ( ! F_163 ( V_2 ) )
V_30 -> V_272 = 0 ;
F_69 ( V_2 , F_137 ( V_30 ) + V_237 , 1 ) ;
F_153 ( V_2 , L_7 ) ;
F_159 ( V_2 , false ) ;
F_71 ( F_72 ( V_2 ) , V_292 ) ;
V_291 = 0 ;
}
return V_291 ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_160 ( V_30 ) ) {
struct V_3 * V_4 ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_153 &= ~ V_154 ;
}
F_130 ( V_30 ) ;
F_153 ( V_2 , L_8 ) ;
V_30 -> V_151 = 0 ;
F_159 ( V_2 , true ) ;
F_71 ( F_72 ( V_2 ) , V_288 ) ;
F_2 ( V_2 ) -> V_243 = 0 ;
V_30 -> V_124 = 0 ;
if ( F_144 ( V_30 ) )
F_64 ( V_2 , V_113 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_166 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_124 ) {
if ( F_2 ( V_2 ) -> V_112 == V_123 ) {
V_30 -> V_109 = F_9 ( V_30 -> V_109 , V_30 -> V_111 ) ;
V_30 -> V_70 = V_71 ;
} else if ( V_30 -> V_111 < V_134 ) {
V_30 -> V_109 = V_30 -> V_111 ;
V_30 -> V_70 = V_71 ;
}
}
F_128 ( V_2 , V_293 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_186 = V_113 ;
if ( F_156 ( V_30 ) || F_163 ( V_2 ) )
V_186 = V_242 ;
if ( F_2 ( V_2 ) -> V_112 != V_186 ) {
F_64 ( V_2 , V_186 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
}
}
static void F_168 ( struct V_1 * V_2 , int V_192 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_117 ( V_30 ) ;
if ( ! V_30 -> V_241 && ! F_163 ( V_2 ) )
V_30 -> V_272 = 0 ;
if ( V_192 & V_294 )
F_62 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_112 != V_123 ) {
F_167 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_112 != V_113 )
F_148 ( V_30 ) ;
} else {
F_151 ( V_2 , V_192 ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_239 . V_295 = V_6 -> V_239 . V_240 - 1 ;
V_6 -> V_239 . V_240 = 0 ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_121 = F_127 ( V_2 ) ;
V_30 -> V_109 = V_30 -> V_109 *
F_171 ( V_2 , V_30 -> V_296 ) /
V_6 -> V_239 . V_240 ;
V_30 -> V_127 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_111 = F_127 ( V_2 ) ;
V_6 -> V_239 . V_297 = V_6 -> V_239 . V_240 ;
V_6 -> V_239 . V_240 = 0 ;
F_172 ( V_2 , V_6 -> V_298 ) ;
}
void F_173 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_174 ( V_2 ) ;
T_1 V_299 = V_30 -> V_151 ;
F_81 (skb, sk) {
if ( V_4 == F_82 ( V_2 ) )
break;
if ( F_96 ( V_4 ) > V_58 &&
! ( F_16 ( V_4 ) -> V_153 & V_155 ) ) {
if ( F_16 ( V_4 ) -> V_153 & V_166 ) {
F_16 ( V_4 ) -> V_153 &= ~ V_166 ;
V_30 -> V_162 -= F_76 ( V_4 ) ;
}
F_77 ( V_30 , V_4 ) ;
}
}
F_175 ( V_30 ) ;
if ( V_299 == V_30 -> V_151 )
return;
if ( F_70 ( V_30 ) )
F_118 ( V_30 ) ;
F_117 ( V_30 ) ;
if ( V_6 -> V_112 != V_234 ) {
V_30 -> V_128 = V_30 -> V_98 ;
V_30 -> V_111 = F_127 ( V_2 ) ;
V_30 -> V_121 = 0 ;
V_30 -> V_124 = 0 ;
F_64 ( V_2 , V_234 ) ;
}
F_176 ( V_2 ) ;
}
static void F_177 ( struct V_1 * V_2 , int V_300 ,
int V_263 , int V_192 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_301 = 0 ;
int V_302 = V_30 -> V_111 - F_63 ( V_30 ) ;
if ( F_63 ( V_30 ) > V_30 -> V_111 ) {
T_4 V_303 = ( T_4 ) V_30 -> V_111 * V_30 -> V_304 +
V_30 -> V_305 - 1 ;
V_301 = F_178 ( V_303 , V_30 -> V_305 ) - V_30 -> V_306 ;
} else {
V_301 = F_37 ( int , V_302 ,
F_27 ( int , V_30 -> V_304 - V_30 -> V_306 ,
V_300 ) + 1 ) ;
}
V_301 = F_31 ( V_301 , ( V_263 ? 1 : 0 ) ) ;
V_30 -> V_109 = F_63 ( V_30 ) + V_301 ;
}
static void F_179 ( struct V_1 * V_2 , int V_307 ,
int V_300 , bool V_308 ,
int V_192 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_309 = V_308 || ( ( V_192 & V_194 ) &&
( F_137 ( V_30 ) > V_30 -> V_115 ) ) ;
int V_263 = 0 , V_139 ;
if ( F_114 ( ! V_30 -> V_227 && V_30 -> V_148 ) )
V_30 -> V_148 = 0 ;
if ( F_114 ( ! V_30 -> V_148 && V_30 -> V_147 ) )
V_30 -> V_147 = 0 ;
if ( V_192 & V_294 )
V_30 -> V_121 = 0 ;
if ( F_134 ( V_2 , V_192 ) )
return;
F_117 ( V_30 ) ;
if ( V_6 -> V_112 == V_113 ) {
F_114 ( V_30 -> V_162 != 0 ) ;
V_30 -> V_272 = 0 ;
} else if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_128 ) ) {
switch ( V_6 -> V_112 ) {
case V_234 :
V_6 -> V_243 = 0 ;
if ( F_161 ( V_2 ) )
return;
break;
case V_123 :
if ( V_30 -> V_96 != V_30 -> V_128 ) {
F_166 ( V_2 ) ;
F_64 ( V_2 , V_113 ) ;
}
break;
case V_164 :
if ( F_70 ( V_30 ) )
F_122 ( V_30 ) ;
if ( F_161 ( V_2 ) )
return;
F_166 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_112 ) {
case V_164 :
if ( ! ( V_192 & V_310 ) ) {
if ( F_70 ( V_30 ) && V_308 )
F_120 ( V_2 ) ;
} else
V_309 = F_164 ( V_2 , V_307 ) ;
break;
case V_234 :
if ( V_192 & V_249 )
V_6 -> V_243 = 0 ;
if ( F_70 ( V_30 ) && V_192 & V_310 )
F_122 ( V_30 ) ;
if ( ! F_165 ( V_2 ) ) {
F_148 ( V_30 ) ;
F_176 ( V_2 ) ;
return;
}
if ( V_6 -> V_112 != V_113 )
return;
default:
if ( F_70 ( V_30 ) ) {
if ( V_192 & V_310 )
F_122 ( V_30 ) ;
if ( V_308 )
F_120 ( V_2 ) ;
}
if ( V_6 -> V_112 <= V_242 )
F_162 ( V_2 ) ;
if ( ! F_141 ( V_2 ) ) {
F_168 ( V_2 , V_192 ) ;
return;
}
if ( V_6 -> V_112 < V_123 &&
V_6 -> V_239 . V_240 &&
V_30 -> V_96 == V_30 -> V_311 . V_312 ) {
F_169 ( V_2 ) ;
V_30 -> V_109 ++ ;
F_173 ( V_2 ) ;
return;
}
if ( F_70 ( V_30 ) )
V_139 = V_313 ;
else
V_139 = V_314 ;
F_71 ( F_72 ( V_2 ) , V_139 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
V_30 -> V_121 = 0 ;
V_30 -> V_124 = V_30 -> V_96 ;
V_30 -> V_149 = V_30 -> V_162 ;
if ( V_6 -> V_112 < V_123 ) {
if ( ! ( V_192 & V_294 ) )
V_30 -> V_121 = F_127 ( V_2 ) ;
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
F_12 ( V_30 ) ;
}
V_30 -> V_122 = 0 ;
V_30 -> V_127 = 0 ;
V_30 -> V_305 = V_30 -> V_109 ;
V_30 -> V_304 = 0 ;
V_30 -> V_306 = 0 ;
F_64 ( V_2 , V_164 ) ;
V_263 = 1 ;
}
if ( V_309 || ( F_66 ( V_30 ) && F_140 ( V_2 ) ) )
F_147 ( V_2 , V_263 ) ;
V_30 -> V_304 += V_300 ;
F_177 ( V_2 , V_300 , V_263 , V_192 ) ;
F_176 ( V_2 ) ;
}
void F_180 ( struct V_1 * V_2 , T_1 V_315 )
{
F_46 ( V_2 , V_315 ) ;
F_49 ( V_2 ) ;
F_2 ( V_2 ) -> V_104 = 0 ;
}
static void F_181 ( struct V_1 * V_2 , int V_192 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_180 ( V_2 , V_71 - V_30 -> V_45 . V_83 ) ;
}
static void F_182 ( struct V_1 * V_2 , T_1 V_315 , int V_192 )
{
if ( V_192 & V_316 )
return;
F_180 ( V_2 , V_315 ) ;
}
static inline void F_183 ( struct V_1 * V_2 , const int V_192 ,
const T_5 V_315 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_273 && V_30 -> V_45 . V_83 )
F_181 ( V_2 , V_192 ) ;
else if ( V_315 >= 0 )
F_182 ( V_2 , V_315 , V_192 ) ;
}
static void F_184 ( struct V_1 * V_2 , T_1 V_317 , T_1 V_318 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_125 -> V_319 ( V_2 , V_317 , V_318 ) ;
F_7 ( V_2 ) -> V_70 = V_71 ;
}
static void F_185 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_227 ) {
F_186 ( V_2 , V_254 ) ;
} else {
F_136 ( V_2 , V_254 ,
F_2 ( V_2 ) -> V_90 , V_255 ) ;
}
}
static T_1 F_187 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_320 ;
F_91 ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) ) ;
V_320 = F_76 ( V_4 ) ;
if ( F_188 ( V_2 , V_4 , V_30 -> V_96 - F_16 ( V_4 ) -> V_82 ) )
return 0 ;
V_320 -= F_76 ( V_4 ) ;
if ( V_320 ) {
F_91 ( F_76 ( V_4 ) == 0 ) ;
F_91 ( ! F_40 ( F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) ;
}
return V_320 ;
}
static int F_189 ( struct V_1 * V_2 , int V_321 ,
T_1 V_172 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_88 = V_71 ;
int V_322 = 1 ;
int V_192 = 0 ;
T_1 V_307 = 0 ;
T_1 V_190 = V_30 -> V_227 ;
T_1 V_323 = V_30 -> V_148 ;
T_5 V_315 = - 1 ;
T_5 V_324 = - 1 ;
T_6 V_325 = F_190 () ;
while ( ( V_4 = F_103 ( V_2 ) ) && V_4 != F_82 ( V_2 ) ) {
struct V_326 * V_327 = F_16 ( V_4 ) ;
T_1 V_328 ;
T_3 V_153 = V_327 -> V_153 ;
if ( F_47 ( V_327 -> V_84 , V_30 -> V_96 ) ) {
if ( F_76 ( V_4 ) == 1 ||
! F_47 ( V_30 -> V_96 , V_327 -> V_82 ) )
break;
V_328 = F_187 ( V_2 , V_4 ) ;
if ( ! V_328 )
break;
V_322 = 0 ;
} else {
V_328 = F_76 ( V_4 ) ;
}
if ( V_153 & V_189 ) {
if ( V_153 & V_166 )
V_30 -> V_162 -= V_328 ;
V_192 |= V_316 ;
V_324 = - 1 ;
V_315 = - 1 ;
if ( ( V_192 & V_249 ) || ( V_328 > 1 ) )
V_192 |= V_329 ;
} else {
V_324 = V_88 - V_327 -> V_256 ;
V_325 = V_4 -> V_330 ;
if ( V_315 < 0 ) {
V_315 = V_324 ;
}
if ( ! ( V_153 & V_155 ) )
V_190 = F_9 ( V_307 , V_190 ) ;
}
if ( V_153 & V_155 )
V_30 -> V_148 -= V_328 ;
if ( V_153 & V_154 )
V_30 -> V_151 -= V_328 ;
V_30 -> V_227 -= V_328 ;
V_307 += V_328 ;
if ( ! ( V_327 -> V_204 & V_331 ) ) {
V_192 |= V_249 ;
} else {
V_192 |= V_332 ;
V_30 -> V_272 = 0 ;
}
if ( ! V_322 )
break;
F_94 ( V_4 , V_2 ) ;
F_95 ( V_2 , V_4 ) ;
V_30 -> V_203 = NULL ;
if ( V_4 == V_30 -> V_150 )
V_30 -> V_150 = NULL ;
if ( V_4 == V_30 -> V_129 )
V_30 -> V_129 = NULL ;
}
if ( F_191 ( F_192 ( V_30 -> V_333 , V_172 , V_30 -> V_96 ) ) )
V_30 -> V_333 = V_30 -> V_96 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_153 & V_155 ) )
V_192 |= V_252 ;
if ( V_192 & V_334 ) {
const struct V_266 * V_267
= F_2 ( V_2 ) -> V_125 ;
if ( F_102 ( V_6 -> V_239 . V_240 &&
! F_47 ( V_30 -> V_311 . V_335 , V_30 -> V_96 ) ) ) {
F_170 ( V_2 ) ;
}
F_183 ( V_2 , V_192 , V_315 ) ;
F_185 ( V_2 ) ;
if ( F_70 ( V_30 ) ) {
F_121 ( V_2 , V_307 ) ;
} else {
int V_302 ;
if ( V_190 < V_321 )
F_69 ( V_2 , V_30 -> V_147 - V_190 , 0 ) ;
V_302 = F_66 ( V_30 ) ? V_307 :
V_323 - V_30 -> V_148 ;
V_30 -> V_195 -= F_9 ( V_30 -> V_195 , V_302 ) ;
}
V_30 -> V_147 -= F_9 ( V_307 , V_30 -> V_147 ) ;
if ( V_267 -> V_307 ) {
T_5 V_336 = - 1 ;
if ( ! ( V_192 & V_316 ) ) {
if ( V_267 -> V_102 & V_337 &&
! F_193 ( V_325 ,
F_190 () ) )
V_336 = F_194 ( F_195 () ,
V_325 ) ;
else if ( V_324 >= 0 )
V_336 = F_196 ( V_324 ) ;
}
V_267 -> V_307 ( V_2 , V_307 , V_336 ) ;
}
}
#if V_145 > 0
F_114 ( ( int ) V_30 -> V_148 < 0 ) ;
F_114 ( ( int ) V_30 -> V_151 < 0 ) ;
F_114 ( ( int ) V_30 -> V_162 < 0 ) ;
if ( ! V_30 -> V_227 && F_144 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_151 ) {
F_73 ( V_146 L_9 ,
V_30 -> V_151 , V_6 -> V_112 ) ;
V_30 -> V_151 = 0 ;
}
if ( V_30 -> V_148 ) {
F_73 ( V_146 L_10 ,
V_30 -> V_148 , V_6 -> V_112 ) ;
V_30 -> V_148 = 0 ;
}
if ( V_30 -> V_162 ) {
F_73 ( V_146 L_11 ,
V_30 -> V_162 , V_6 -> V_112 ) ;
V_30 -> V_162 = 0 ;
}
}
#endif
return V_192 ;
}
static void F_197 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_47 ( F_16 ( F_82 ( V_2 ) ) -> V_84 , F_198 ( V_30 ) ) ) {
V_6 -> V_104 = 0 ;
F_186 ( V_2 , V_338 ) ;
} else {
F_136 ( V_2 , V_338 ,
F_9 ( V_6 -> V_90 << V_6 -> V_104 , V_255 ) ,
V_255 ) ;
}
}
static inline int F_199 ( const struct V_1 * V_2 , const int V_192 )
{
return ! ( V_192 & V_271 ) || ( V_192 & V_339 ) ||
F_2 ( V_2 ) -> V_112 != V_113 ;
}
static inline int F_200 ( const struct V_1 * V_2 , const int V_192 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_192 & V_294 ) || V_30 -> V_109 < V_30 -> V_111 ) &&
! ( ( 1 << F_2 ( V_2 ) -> V_112 ) & ( V_246 | V_340 ) ) ;
}
static inline int F_201 ( const struct V_29 * V_30 ,
const T_1 V_317 , const T_1 V_165 ,
const T_1 V_341 )
{
return F_47 ( V_317 , V_30 -> V_96 ) ||
F_47 ( V_165 , V_30 -> V_342 ) ||
( V_165 == V_30 -> V_342 && V_341 > V_30 -> V_343 ) ;
}
static int F_202 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_317 ,
T_1 V_165 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_192 = 0 ;
T_1 V_341 = F_155 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_191 ( ! F_6 ( V_4 ) -> V_43 ) )
V_341 <<= V_30 -> V_45 . V_344 ;
if ( F_201 ( V_30 , V_317 , V_165 , V_341 ) ) {
V_192 |= V_345 ;
F_203 ( V_30 , V_165 ) ;
if ( V_30 -> V_343 != V_341 ) {
V_30 -> V_343 = V_341 ;
V_30 -> V_346 = 0 ;
F_204 ( V_2 ) ;
if ( V_341 > V_30 -> V_158 ) {
V_30 -> V_158 = V_341 ;
F_172 ( V_2 , F_2 ( V_2 ) -> V_298 ) ;
}
}
}
V_30 -> V_96 = V_317 ;
return V_192 ;
}
static void F_205 ( struct V_29 * V_30 )
{
V_30 -> V_109 = F_9 ( V_30 -> V_109 , V_30 -> V_111 ) ;
V_30 -> V_127 = 0 ;
V_30 -> V_122 = 0 ;
F_12 ( V_30 ) ;
F_148 ( V_30 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
F_62 ( V_2 , 0 ) ;
}
static void F_207 ( struct V_1 * V_2 , int V_192 )
{
if ( V_192 & V_294 )
F_206 ( V_2 ) ;
else
F_159 ( V_2 , true ) ;
}
static int F_208 ( struct V_1 * V_2 , int V_192 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_117 ( V_30 ) ;
if ( V_192 & V_249 )
F_2 ( V_2 ) -> V_243 = 0 ;
if ( ( V_192 & V_329 ) ||
( ( V_30 -> V_241 >= 2 ) && ( V_192 & V_316 ) ) )
V_30 -> V_124 = 0 ;
if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_191 ) ) {
F_129 ( V_2 , ( V_30 -> V_241 == 1 ? 2 : 3 ) , V_192 ) ;
return 1 ;
}
if ( ! F_123 ( V_30 ) ) {
if ( ! ( V_192 & V_270 ) && ( V_192 & V_271 ) )
return 1 ;
if ( ! ( V_192 & V_249 ) ) {
F_129 ( V_2 , ( V_30 -> V_241 == 1 ? 0 : 3 ) ,
V_192 ) ;
return 1 ;
}
} else {
if ( ! ( V_192 & V_249 ) && ( V_30 -> V_241 == 1 ) ) {
V_30 -> V_109 = F_9 ( V_30 -> V_109 ,
F_63 ( V_30 ) ) ;
return 1 ;
}
if ( ( V_30 -> V_241 >= 2 ) &&
( ! ( V_192 & V_347 ) ||
( ( V_192 & V_194 ) &&
! ( V_192 & V_193 ) ) ) ) {
if ( ! ( V_192 & V_347 ) &&
( V_192 & V_271 ) )
return 1 ;
F_129 ( V_2 , 3 , V_192 ) ;
return 1 ;
}
}
if ( V_30 -> V_241 == 1 ) {
V_30 -> V_109 = F_63 ( V_30 ) + 2 ;
V_30 -> V_241 = 2 ;
if ( ! F_142 ( V_2 ) )
F_129 ( V_2 , 2 , V_192 ) ;
return 1 ;
} else {
switch ( V_348 ) {
case 2 :
F_207 ( V_2 , V_192 ) ;
break;
case 1 :
F_205 ( V_30 ) ;
break;
default:
F_206 ( V_2 ) ;
break;
}
V_30 -> V_241 = 0 ;
V_30 -> V_124 = 0 ;
F_71 ( F_72 ( V_2 ) , V_349 ) ;
}
return 0 ;
}
static int F_209 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_192 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_172 = V_30 -> V_96 ;
T_1 V_165 = F_16 ( V_4 ) -> V_82 ;
T_1 V_317 = F_16 ( V_4 ) -> V_165 ;
bool V_308 = false ;
T_1 V_350 ;
T_1 V_321 ;
int V_351 ;
int V_323 = V_30 -> V_148 ;
int V_307 = 0 ;
int V_300 = 0 ;
int V_352 = 0 ;
if ( F_40 ( V_317 , V_172 ) )
goto V_353;
if ( F_47 ( V_317 , V_30 -> V_98 ) )
goto V_354;
if ( F_47 ( V_317 , V_172 ) )
V_192 |= V_310 ;
if ( V_355 ) {
if ( V_6 -> V_112 < V_123 )
V_30 -> V_122 += V_317 - V_172 ;
else if ( V_6 -> V_112 == V_234 )
V_30 -> V_122 += F_9 ( V_317 - V_172 ,
V_30 -> V_296 ) ;
}
V_321 = V_30 -> V_147 ;
V_350 = F_63 ( V_30 ) ;
if ( ! ( V_192 & V_356 ) && F_47 ( V_317 , V_172 ) ) {
F_203 ( V_30 , V_165 ) ;
V_30 -> V_96 = V_317 ;
V_192 |= V_345 ;
F_128 ( V_2 , V_357 ) ;
F_71 ( F_72 ( V_2 ) , V_358 ) ;
} else {
if ( V_165 != F_16 ( V_4 ) -> V_84 )
V_192 |= V_359 ;
else
F_71 ( F_72 ( V_2 ) , V_360 ) ;
V_192 |= F_202 ( V_2 , V_4 , V_317 , V_165 ) ;
if ( F_16 ( V_4 ) -> V_153 )
V_192 |= F_113 ( V_2 , V_4 , V_172 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_192 |= V_294 ;
F_128 ( V_2 , V_361 ) ;
}
V_2 -> V_362 = 0 ;
V_6 -> V_363 = 0 ;
V_30 -> V_364 = V_71 ;
V_351 = V_30 -> V_227 ;
if ( ! V_351 )
goto V_365;
V_192 |= F_189 ( V_2 , V_321 , V_172 ) ;
V_307 = V_351 - V_30 -> V_227 ;
V_300 = ( V_351 - V_323 ) -
( V_30 -> V_227 - V_30 -> V_148 ) ;
if ( V_30 -> V_241 )
V_352 = F_208 ( V_2 , V_192 ) ;
if ( F_40 ( V_30 -> V_191 , V_30 -> V_96 ) )
V_30 -> V_191 = 0 ;
if ( F_199 ( V_2 , V_192 ) ) {
if ( ( V_192 & V_249 ) && ! V_352 &&
F_200 ( V_2 , V_192 ) )
F_184 ( V_2 , V_317 , V_350 ) ;
V_308 = ! ( V_192 & ( V_310 | V_271 ) ) ;
F_179 ( V_2 , V_307 , V_300 ,
V_308 , V_192 ) ;
} else {
if ( ( V_192 & V_249 ) && ! V_352 )
F_184 ( V_2 , V_317 , V_350 ) ;
}
if ( ( V_192 & V_347 ) || ! ( V_192 & V_271 ) )
F_54 ( F_53 ( V_2 ) ) ;
return 1 ;
V_365:
if ( V_192 & V_228 )
F_179 ( V_2 , V_307 , V_300 ,
V_308 , V_192 ) ;
if ( F_82 ( V_2 ) )
F_197 ( V_2 ) ;
return 1 ;
V_354:
F_210 ( V_2 , L_12 , V_317 , V_30 -> V_96 , V_30 -> V_98 ) ;
return - 1 ;
V_353:
if ( F_16 ( V_4 ) -> V_153 ) {
V_192 |= F_113 ( V_2 , V_4 , V_172 ) ;
V_300 = V_30 -> V_148 - V_323 ;
F_179 ( V_2 , V_307 , V_300 ,
V_308 , V_192 ) ;
}
F_210 ( V_2 , L_13 , V_317 , V_30 -> V_96 , V_30 -> V_98 ) ;
return 0 ;
}
void F_211 ( const struct V_3 * V_4 , struct V_366 * V_367 ,
const T_3 * * V_368 , int V_369 )
{
const unsigned char * V_218 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_370 = ( V_41 -> V_371 * 4 ) - sizeof( struct V_15 ) ;
V_218 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_367 -> V_273 = 0 ;
while ( V_370 > 0 ) {
int V_372 = * V_218 ++ ;
int V_373 ;
switch ( V_372 ) {
case V_374 :
return;
case V_375 :
V_370 -- ;
continue;
default:
V_373 = * V_218 ++ ;
if ( V_373 < 2 )
return;
if ( V_373 > V_370 )
return;
switch ( V_372 ) {
case V_376 :
if ( V_373 == V_377 && V_41 -> V_43 && ! V_369 ) {
T_7 V_378 = F_212 ( V_218 ) ;
if ( V_378 ) {
if ( V_367 -> V_379 &&
V_367 -> V_379 < V_378 )
V_378 = V_367 -> V_379 ;
V_367 -> V_46 = V_378 ;
}
}
break;
case V_380 :
if ( V_373 == V_381 && V_41 -> V_43 &&
! V_369 && V_382 ) {
T_8 V_344 = * ( T_8 * ) V_218 ;
V_367 -> V_383 = 1 ;
if ( V_344 > 14 ) {
if ( F_213 () )
F_214 ( L_14 ,
V_384 ,
V_344 ) ;
V_344 = 14 ;
}
V_367 -> V_344 = V_344 ;
}
break;
case V_385 :
if ( ( V_373 == V_386 ) &&
( ( V_369 && V_367 -> V_387 ) ||
( ! V_369 && V_388 ) ) ) {
V_367 -> V_273 = 1 ;
V_367 -> V_389 = F_84 ( V_218 ) ;
V_367 -> V_83 = F_84 ( V_218 + 4 ) ;
}
break;
case V_390 :
if ( V_373 == V_391 && V_41 -> V_43 &&
! V_369 && V_392 ) {
V_367 -> V_130 = V_393 ;
F_215 ( V_367 ) ;
}
break;
case V_394 :
if ( ( V_373 >= ( V_221 + V_395 ) ) &&
! ( ( V_373 - V_221 ) % V_395 ) &&
V_367 -> V_130 ) {
F_16 ( V_4 ) -> V_153 = ( V_218 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_216
case V_396 :
break;
#endif
case V_397 :
switch ( V_373 ) {
case V_398 :
break;
case V_399 :
break;
case V_400 + 0 :
case V_400 + 2 :
case V_400 + 4 :
case V_400 + 6 :
case V_401 :
V_367 -> V_402 = V_373 ;
* V_368 = V_218 ;
break;
default:
break;
}
break;
}
V_218 += V_373 - 2 ;
V_370 -= V_373 ;
}
}
}
static int F_217 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_218 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_218 == F_218 ( ( V_375 << 24 ) | ( V_375 << 16 )
| ( V_385 << 8 ) | V_386 ) ) {
V_30 -> V_45 . V_273 = 1 ;
++ V_218 ;
V_30 -> V_45 . V_389 = F_219 ( * V_218 ) ;
++ V_218 ;
V_30 -> V_45 . V_83 = F_219 ( * V_218 ) ;
return 1 ;
}
return 0 ;
}
static int F_220 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 ,
struct V_29 * V_30 , const T_3 * * V_368 )
{
if ( V_41 -> V_371 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_273 = 0 ;
return 0 ;
} else if ( V_30 -> V_45 . V_387 &&
V_41 -> V_371 == ( ( sizeof( * V_41 ) + V_403 ) / 4 ) ) {
if ( F_217 ( V_30 , V_41 ) )
return 1 ;
}
F_211 ( V_4 , & V_30 -> V_45 , V_368 , 1 ) ;
return 1 ;
}
const T_3 * F_221 ( const struct V_15 * V_41 )
{
int V_370 = ( V_41 -> V_371 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_218 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_370 < V_404 )
return NULL ;
while ( V_370 > 0 ) {
int V_372 = * V_218 ++ ;
int V_373 ;
switch( V_372 ) {
case V_374 :
return NULL ;
case V_375 :
V_370 -- ;
continue;
default:
V_373 = * V_218 ++ ;
if ( V_373 < 2 || V_373 > V_370 )
return NULL ;
if ( V_372 == V_396 )
return V_373 == V_404 ? V_218 : NULL ;
}
V_218 += V_373 - 2 ;
V_370 -= V_373 ;
}
return NULL ;
}
static inline void F_222 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_405 = V_30 -> V_45 . V_389 ;
V_30 -> V_45 . V_406 = F_223 () ;
}
static inline void F_224 ( struct V_29 * V_30 , T_1 V_82 )
{
if ( V_30 -> V_45 . V_273 && ! F_47 ( V_82 , V_30 -> V_407 ) ) {
if ( F_225 ( & V_30 -> V_45 , 0 ) )
F_222 ( V_30 ) ;
}
}
static int F_226 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
T_1 V_317 = F_16 ( V_4 ) -> V_165 ;
return (
( V_41 -> V_317 && V_82 == F_16 ( V_4 ) -> V_84 && V_82 == V_30 -> V_81 ) &&
V_317 == V_30 -> V_96 &&
! F_201 ( V_30 , V_317 , V_82 , F_155 ( V_41 -> V_52 ) << V_30 -> V_45 . V_344 ) &&
( T_5 ) ( V_30 -> V_45 . V_405 - V_30 -> V_45 . V_389 ) <= ( F_2 ( V_2 ) -> V_90 * 1024 ) / V_408 ) ;
}
static inline int F_227 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_225 ( & V_30 -> V_45 , V_409 ) &&
! F_226 ( V_2 , V_4 ) ;
}
static inline int F_228 ( const struct V_29 * V_30 , T_1 V_82 , T_1 V_84 )
{
return ! F_40 ( V_84 , V_30 -> V_407 ) &&
! F_47 ( V_82 , V_30 -> V_81 + F_229 ( V_30 ) ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_410 ) {
case V_411 :
V_2 -> V_412 = V_413 ;
break;
case V_414 :
V_2 -> V_412 = V_415 ;
break;
case V_416 :
return;
default:
V_2 -> V_412 = V_417 ;
}
F_231 () ;
if ( ! F_232 ( V_2 , V_418 ) )
V_2 -> V_419 ( V_2 ) ;
F_233 ( V_2 ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_420 |= V_421 ;
F_235 ( V_2 , V_422 ) ;
switch ( V_2 -> V_410 ) {
case V_423 :
case V_424 :
F_236 ( V_2 , V_414 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_414 :
case V_425 :
break;
case V_426 :
break;
case V_427 :
F_237 ( V_2 ) ;
F_236 ( V_2 , V_425 ) ;
break;
case V_428 :
F_237 ( V_2 ) ;
F_238 ( V_2 , V_429 , 0 ) ;
break;
default:
F_239 ( L_15 ,
V_384 , V_2 -> V_410 ) ;
break;
}
F_240 ( & V_30 -> V_430 ) ;
if ( F_144 ( V_30 ) )
F_215 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
if ( ! F_232 ( V_2 , V_418 ) ) {
V_2 -> V_431 ( V_2 ) ;
if ( V_2 -> V_420 == V_432 ||
V_2 -> V_410 == V_416 )
F_241 ( V_2 , V_433 , V_434 ) ;
else
F_241 ( V_2 , V_433 , V_435 ) ;
}
}
static inline int F_242 ( struct V_211 * V_170 , T_1 V_82 ,
T_1 V_84 )
{
if ( ! F_47 ( V_82 , V_170 -> V_84 ) && ! F_47 ( V_170 -> V_157 , V_84 ) ) {
if ( F_40 ( V_82 , V_170 -> V_157 ) )
V_170 -> V_157 = V_82 ;
if ( F_47 ( V_84 , V_170 -> V_84 ) )
V_170 -> V_84 = V_84 ;
return 1 ;
}
return 0 ;
}
static void F_243 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_144 ( V_30 ) && V_436 ) {
int V_139 ;
if ( F_40 ( V_82 , V_30 -> V_81 ) )
V_139 = V_437 ;
else
V_139 = V_438 ;
F_71 ( F_72 ( V_2 ) , V_139 ) ;
V_30 -> V_45 . V_439 = 1 ;
V_30 -> V_440 [ 0 ] . V_157 = V_82 ;
V_30 -> V_440 [ 0 ] . V_84 = V_84 ;
}
}
static void F_244 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_439 )
F_243 ( V_2 , V_82 , V_84 ) ;
else
F_242 ( V_30 -> V_440 , V_82 , V_84 ) ;
}
static void F_245 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_71 ( F_72 ( V_2 ) , V_441 ) ;
F_10 ( V_2 ) ;
if ( F_144 ( V_30 ) && V_436 ) {
T_1 V_84 = F_16 ( V_4 ) -> V_84 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) )
V_84 = V_30 -> V_81 ;
F_243 ( V_2 , F_16 ( V_4 ) -> V_82 , V_84 ) ;
}
}
F_237 ( V_2 ) ;
}
static void F_246 ( struct V_29 * V_30 )
{
int V_442 ;
struct V_211 * V_170 = & V_30 -> V_443 [ 0 ] ;
struct V_211 * V_444 = V_170 + 1 ;
for ( V_442 = 1 ; V_442 < V_30 -> V_45 . V_171 ; ) {
if ( F_242 ( V_170 , V_444 -> V_157 , V_444 -> V_84 ) ) {
int V_224 ;
V_30 -> V_45 . V_171 -- ;
for ( V_224 = V_442 ; V_224 < V_30 -> V_45 . V_171 ; V_224 ++ )
V_170 [ V_224 ] = V_170 [ V_224 + 1 ] ;
continue;
}
V_442 ++ , V_444 ++ ;
}
}
static void F_247 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_211 * V_170 = & V_30 -> V_443 [ 0 ] ;
int V_445 = V_30 -> V_45 . V_171 ;
int V_442 ;
if ( ! V_445 )
goto V_446;
for ( V_442 = 0 ; V_442 < V_445 ; V_442 ++ , V_170 ++ ) {
if ( F_242 ( V_170 , V_82 , V_84 ) ) {
for (; V_442 > 0 ; V_442 -- , V_170 -- )
F_116 ( * V_170 , * ( V_170 - 1 ) ) ;
if ( V_445 > 1 )
F_246 ( V_30 ) ;
return;
}
}
if ( V_442 >= V_220 ) {
V_442 -- ;
V_30 -> V_45 . V_171 -- ;
V_170 -- ;
}
for (; V_442 > 0 ; V_442 -- , V_170 -- )
* V_170 = * ( V_170 - 1 ) ;
V_446:
V_170 -> V_157 = V_82 ;
V_170 -> V_84 = V_84 ;
V_30 -> V_45 . V_171 ++ ;
}
static void F_248 ( struct V_29 * V_30 )
{
struct V_211 * V_170 = & V_30 -> V_443 [ 0 ] ;
int V_171 = V_30 -> V_45 . V_171 ;
int V_442 ;
if ( F_249 ( & V_30 -> V_430 ) ) {
V_30 -> V_45 . V_171 = 0 ;
return;
}
for ( V_442 = 0 ; V_442 < V_171 ; ) {
if ( ! F_40 ( V_30 -> V_81 , V_170 -> V_157 ) ) {
int V_224 ;
F_114 ( F_40 ( V_30 -> V_81 , V_170 -> V_84 ) ) ;
for ( V_224 = V_442 + 1 ; V_224 < V_171 ; V_224 ++ )
V_30 -> V_443 [ V_224 - 1 ] = V_30 -> V_443 [ V_224 ] ;
V_171 -- ;
continue;
}
V_442 ++ ;
V_170 ++ ;
}
V_30 -> V_45 . V_171 = V_171 ;
}
static void F_250 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_447 = V_30 -> V_81 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_251 ( & V_30 -> V_430 ) ) != NULL ) {
if ( F_47 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_447 ) ) {
T_2 V_439 = V_447 ;
if ( F_40 ( F_16 ( V_4 ) -> V_84 , V_447 ) )
V_447 = F_16 ( V_4 ) -> V_84 ;
F_244 ( V_2 , F_16 ( V_4 ) -> V_82 , V_439 ) ;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_210 ( V_2 , L_16 ) ;
F_252 ( V_4 , & V_30 -> V_430 ) ;
F_253 ( V_4 ) ;
continue;
}
F_210 ( V_2 , L_17 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_252 ( V_4 , & V_30 -> V_430 ) ;
F_254 ( & V_2 -> V_448 , V_4 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( F_6 ( V_4 ) -> V_449 )
F_234 ( V_2 ) ;
}
}
static inline int F_255 ( struct V_1 * V_2 , unsigned int V_450 )
{
if ( F_35 ( & V_2 -> V_72 ) > V_2 -> V_62 ||
! F_256 ( V_2 , V_450 ) ) {
if ( F_257 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_256 ( V_2 , V_450 ) ) {
if ( ! F_258 ( V_2 ) )
return - 1 ;
if ( ! F_256 ( V_2 , V_450 ) )
return - 1 ;
}
}
return 0 ;
}
static void F_259 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_451 ;
T_1 V_82 , V_84 ;
F_15 ( V_30 , V_4 ) ;
if ( F_255 ( V_2 , V_4 -> V_51 ) ) {
F_253 ( V_4 ) ;
return;
}
V_30 -> V_346 = 0 ;
F_44 ( V_2 ) ;
F_210 ( V_2 , L_18 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_451 = F_260 ( & V_30 -> V_430 ) ;
if ( ! V_451 ) {
if ( F_144 ( V_30 ) ) {
V_30 -> V_45 . V_171 = 1 ;
V_30 -> V_443 [ 0 ] . V_157 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_443 [ 0 ] . V_84 =
F_16 ( V_4 ) -> V_84 ;
}
F_261 ( & V_30 -> V_430 , V_4 ) ;
goto V_452;
}
V_82 = F_16 ( V_4 ) -> V_82 ;
V_84 = F_16 ( V_4 ) -> V_84 ;
if ( V_82 == F_16 ( V_451 ) -> V_84 ) {
if ( V_4 -> V_10 <= F_262 ( V_451 ) && ! F_6 ( V_4 ) -> V_449 ) {
F_71 ( F_72 ( V_2 ) ,
V_453 ) ;
F_91 ( F_263 ( V_4 , 0 ,
F_264 ( V_451 , V_4 -> V_10 ) ,
V_4 -> V_10 ) ) ;
F_16 ( V_451 ) -> V_84 = V_84 ;
F_16 ( V_451 ) -> V_165 = F_16 ( V_4 ) -> V_165 ;
F_253 ( V_4 ) ;
V_4 = NULL ;
} else {
F_265 ( & V_30 -> V_430 , V_451 , V_4 ) ;
}
if ( ! V_30 -> V_45 . V_171 ||
V_30 -> V_443 [ 0 ] . V_84 != V_82 )
goto V_454;
V_30 -> V_443 [ 0 ] . V_84 = V_84 ;
goto V_452;
}
while ( 1 ) {
if ( ! F_47 ( F_16 ( V_451 ) -> V_82 , V_82 ) )
break;
if ( F_266 ( & V_30 -> V_430 , V_451 ) ) {
V_451 = NULL ;
break;
}
V_451 = F_267 ( & V_30 -> V_430 , V_451 ) ;
}
if ( V_451 && F_40 ( V_82 , F_16 ( V_451 ) -> V_84 ) ) {
if ( ! F_47 ( V_84 , F_16 ( V_451 ) -> V_84 ) ) {
F_253 ( V_4 ) ;
V_4 = NULL ;
F_243 ( V_2 , V_82 , V_84 ) ;
goto V_454;
}
if ( F_47 ( V_82 , F_16 ( V_451 ) -> V_82 ) ) {
F_243 ( V_2 , V_82 ,
F_16 ( V_451 ) -> V_84 ) ;
} else {
if ( F_266 ( & V_30 -> V_430 ,
V_451 ) )
V_451 = NULL ;
else
V_451 = F_267 (
& V_30 -> V_430 ,
V_451 ) ;
}
}
if ( ! V_451 )
F_261 ( & V_30 -> V_430 , V_4 ) ;
else
F_265 ( & V_30 -> V_430 , V_451 , V_4 ) ;
while ( ! F_268 ( & V_30 -> V_430 , V_4 ) ) {
V_451 = F_269 ( & V_30 -> V_430 , V_4 ) ;
if ( ! F_47 ( V_84 , F_16 ( V_451 ) -> V_82 ) )
break;
if ( F_40 ( V_84 , F_16 ( V_451 ) -> V_84 ) ) {
F_244 ( V_2 , F_16 ( V_451 ) -> V_82 ,
V_84 ) ;
break;
}
F_252 ( V_451 , & V_30 -> V_430 ) ;
F_244 ( V_2 , F_16 ( V_451 ) -> V_82 ,
F_16 ( V_451 ) -> V_84 ) ;
F_253 ( V_451 ) ;
}
V_454:
if ( F_144 ( V_30 ) )
F_247 ( V_2 , V_82 , V_84 ) ;
V_452:
if ( V_4 )
F_270 ( V_4 , V_2 ) ;
}
static void F_271 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_455 = - 1 ;
if ( F_16 ( V_4 ) -> V_82 == F_16 ( V_4 ) -> V_84 )
goto V_456;
F_272 ( V_4 ) ;
F_273 ( V_4 , V_41 -> V_371 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_439 = 0 ;
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 ) {
if ( F_229 ( V_30 ) == 0 )
goto V_457;
if ( V_30 -> V_458 . V_459 == V_460 &&
V_30 -> V_85 == V_30 -> V_81 && V_30 -> V_458 . V_10 &&
F_274 ( V_2 ) && ! V_30 -> V_461 ) {
int V_462 = F_37 (unsigned int, skb->len,
tp->ucopy.len) ;
F_275 ( V_463 ) ;
F_276 () ;
if ( ! F_277 ( V_4 , 0 , V_30 -> V_458 . V_464 , V_462 ) ) {
V_30 -> V_458 . V_10 -= V_462 ;
V_30 -> V_85 += V_462 ;
V_455 = ( V_462 == V_4 -> V_10 ) ;
F_42 ( V_2 ) ;
}
F_278 () ;
}
if ( V_455 <= 0 ) {
V_465:
if ( V_455 < 0 &&
F_255 ( V_2 , V_4 -> V_51 ) )
goto V_456;
F_270 ( V_4 , V_2 ) ;
F_254 ( & V_2 -> V_448 , V_4 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( V_4 -> V_10 )
F_43 ( V_2 , V_4 ) ;
if ( V_41 -> V_449 )
F_234 ( V_2 ) ;
if ( ! F_249 ( & V_30 -> V_430 ) ) {
F_250 ( V_2 ) ;
if ( F_249 ( & V_30 -> V_430 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_171 )
F_248 ( V_30 ) ;
F_204 ( V_2 ) ;
if ( V_455 > 0 )
F_253 ( V_4 ) ;
else if ( ! F_232 ( V_2 , V_418 ) )
V_2 -> V_466 ( V_2 , 0 ) ;
return;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_71 ( F_72 ( V_2 ) , V_441 ) ;
F_243 ( V_2 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_457:
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
V_456:
F_253 ( V_4 ) ;
return;
}
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 + F_229 ( V_30 ) ) )
goto V_457;
F_10 ( V_2 ) ;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_210 ( V_2 , L_19 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_243 ( V_2 , F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ;
if ( ! F_229 ( V_30 ) )
goto V_457;
goto V_465;
}
F_259 ( V_2 , V_4 ) ;
}
static struct V_3 * F_279 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_467 * V_468 )
{
struct V_3 * V_469 = NULL ;
if ( ! F_268 ( V_468 , V_4 ) )
V_469 = F_269 ( V_468 , V_4 ) ;
F_252 ( V_4 , V_468 ) ;
F_253 ( V_4 ) ;
F_71 ( F_72 ( V_2 ) , V_470 ) ;
return V_469 ;
}
static void
F_280 ( struct V_1 * V_2 , struct V_467 * V_468 ,
struct V_3 * V_471 , struct V_3 * V_472 ,
T_1 V_473 , T_1 V_452 )
{
struct V_3 * V_4 , * V_474 ;
bool V_475 ;
V_4 = V_471 ;
V_476:
V_475 = true ;
F_281 (list, skb, n) {
if ( V_4 == V_472 )
break;
if ( ! F_40 ( V_473 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_279 ( V_2 , V_4 , V_468 ) ;
if ( ! V_4 )
break;
goto V_476;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_449 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_40 ( F_16 ( V_4 ) -> V_82 , V_473 ) ) ) {
V_475 = false ;
break;
}
if ( ! F_268 ( V_468 , V_4 ) ) {
struct V_3 * V_469 = F_269 ( V_468 , V_4 ) ;
if ( V_469 != V_472 &&
F_16 ( V_4 ) -> V_84 != F_16 ( V_469 ) -> V_82 ) {
V_475 = false ;
break;
}
}
V_473 = F_16 ( V_4 ) -> V_84 ;
}
if ( V_475 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_449 )
return;
while ( F_40 ( V_473 , V_452 ) ) {
struct V_3 * V_477 ;
unsigned int V_478 = F_282 ( V_4 ) ;
int V_479 = F_283 ( V_478 , 0 ) ;
if ( V_479 < 0 )
return;
if ( V_452 - V_473 < V_479 )
V_479 = V_452 - V_473 ;
V_477 = F_284 ( V_479 + V_478 , V_480 ) ;
if ( ! V_477 )
return;
F_285 ( V_477 , F_286 ( V_4 ) - V_4 -> V_471 ) ;
F_287 ( V_477 , ( F_288 ( V_4 ) -
V_4 -> V_471 ) ) ;
F_289 ( V_477 , ( F_4 ( V_4 ) -
V_4 -> V_471 ) ) ;
F_290 ( V_477 , V_478 ) ;
memcpy ( V_477 -> V_471 , V_4 -> V_471 , V_478 ) ;
memcpy ( V_477 -> V_481 , V_4 -> V_481 , sizeof( V_4 -> V_481 ) ) ;
F_16 ( V_477 ) -> V_82 = F_16 ( V_477 ) -> V_84 = V_473 ;
F_291 ( V_468 , V_4 , V_477 ) ;
F_270 ( V_477 , V_2 ) ;
while ( V_479 > 0 ) {
int V_482 = V_473 - F_16 ( V_4 ) -> V_82 ;
int V_450 = F_16 ( V_4 ) -> V_84 - V_473 ;
F_91 ( V_482 < 0 ) ;
if ( V_450 > 0 ) {
V_450 = F_9 ( V_479 , V_450 ) ;
if ( F_263 ( V_4 , V_482 , F_264 ( V_477 , V_450 ) , V_450 ) )
F_292 () ;
F_16 ( V_477 ) -> V_84 += V_450 ;
V_479 -= V_450 ;
V_473 += V_450 ;
}
if ( ! F_40 ( V_473 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_279 ( V_2 , V_4 , V_468 ) ;
if ( ! V_4 ||
V_4 == V_472 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_449 )
return;
}
}
}
}
static void F_293 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_251 ( & V_30 -> V_430 ) ;
struct V_3 * V_471 ;
T_1 V_473 , V_452 ;
if ( V_4 == NULL )
return;
V_473 = F_16 ( V_4 ) -> V_82 ;
V_452 = F_16 ( V_4 ) -> V_84 ;
V_471 = V_4 ;
for (; ; ) {
struct V_3 * V_469 = NULL ;
if ( ! F_268 ( & V_30 -> V_430 , V_4 ) )
V_469 = F_269 ( & V_30 -> V_430 , V_4 ) ;
V_4 = V_469 ;
if ( ! V_4 ||
F_47 ( F_16 ( V_4 ) -> V_82 , V_452 ) ||
F_40 ( F_16 ( V_4 ) -> V_84 , V_473 ) ) {
F_280 ( V_2 , & V_30 -> V_430 ,
V_471 , V_4 , V_473 , V_452 ) ;
V_471 = V_4 ;
if ( ! V_4 )
break;
V_473 = F_16 ( V_4 ) -> V_82 ;
V_452 = F_16 ( V_4 ) -> V_84 ;
} else {
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_473 ) )
V_473 = F_16 ( V_4 ) -> V_82 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_452 ) )
V_452 = F_16 ( V_4 ) -> V_84 ;
}
}
}
static int F_258 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_483 = 0 ;
if ( ! F_249 ( & V_30 -> V_430 ) ) {
F_71 ( F_72 ( V_2 ) , V_484 ) ;
F_240 ( & V_30 -> V_430 ) ;
if ( V_30 -> V_45 . V_130 )
F_215 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
V_483 = 1 ;
}
return V_483 ;
}
static int F_257 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_210 ( V_2 , L_20 , V_30 -> V_85 ) ;
F_71 ( F_72 ( V_2 ) , V_485 ) ;
if ( F_35 ( & V_2 -> V_72 ) >= V_2 -> V_62 )
F_32 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_293 ( V_2 ) ;
if ( ! F_249 ( & V_2 -> V_448 ) )
F_280 ( V_2 , & V_2 -> V_448 ,
F_251 ( & V_2 -> V_448 ) ,
NULL ,
V_30 -> V_85 , V_30 -> V_81 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_258 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_71 ( F_72 ( V_2 ) , V_486 ) ;
V_30 -> V_346 = 0 ;
return - 1 ;
}
void F_294 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_112 == V_113 &&
V_2 -> V_487 && ! F_295 ( V_488 , & V_2 -> V_487 -> V_102 ) ) {
T_1 V_489 = F_61 ( V_30 , F_53 ( V_2 ) ) ;
T_1 V_490 = F_31 ( V_30 -> V_491 , V_489 ) ;
if ( V_490 < V_30 -> V_109 ) {
V_30 -> V_111 = F_127 ( V_2 ) ;
V_30 -> V_109 = ( V_30 -> V_109 + V_490 ) >> 1 ;
}
V_30 -> V_491 = 0 ;
}
V_30 -> V_70 = V_71 ;
}
static int F_296 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_64 & V_66 )
return 0 ;
if ( F_26 ( V_2 ) )
return 0 ;
if ( F_33 ( V_2 ) >= F_34 ( V_2 , 0 ) )
return 0 ;
if ( V_30 -> V_227 >= V_30 -> V_109 )
return 0 ;
return 1 ;
}
static void F_297 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_296 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_296 ) +
V_47 ) ;
int V_492 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_492 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_70 = V_71 ;
}
V_2 -> V_493 ( V_2 ) ;
}
static void F_298 ( struct V_1 * V_2 )
{
if ( F_232 ( V_2 , V_494 ) ) {
F_299 ( V_2 , V_494 ) ;
if ( V_2 -> V_487 &&
F_295 ( V_488 , & V_2 -> V_487 -> V_102 ) )
F_297 ( V_2 ) ;
}
}
static inline void F_300 ( struct V_1 * V_2 )
{
F_301 ( V_2 ) ;
F_298 ( V_2 ) ;
}
static void F_302 ( struct V_1 * V_2 , int V_495 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_81 - V_30 -> V_407 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_303 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_495 && F_251 ( & V_30 -> V_430 ) ) ) {
F_237 ( V_2 ) ;
} else {
F_304 ( V_2 ) ;
}
}
static inline void F_305 ( struct V_1 * V_2 )
{
if ( ! F_306 ( V_2 ) ) {
return;
}
F_302 ( V_2 , 1 ) ;
}
static void F_307 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_218 = F_155 ( V_41 -> V_496 ) ;
if ( V_218 && ! V_497 )
V_218 -- ;
V_218 += F_219 ( V_41 -> V_82 ) ;
if ( F_47 ( V_30 -> V_85 , V_218 ) )
return;
if ( F_40 ( V_218 , V_30 -> V_81 ) )
return;
if ( V_30 -> V_461 && ! F_47 ( V_218 , V_30 -> V_498 ) )
return;
F_308 ( V_2 ) ;
if ( V_30 -> V_498 == V_30 -> V_85 && V_30 -> V_461 &&
! F_232 ( V_2 , V_499 ) && V_30 -> V_85 != V_30 -> V_81 ) {
struct V_3 * V_4 = F_251 ( & V_2 -> V_448 ) ;
V_30 -> V_85 ++ ;
if ( V_4 && ! F_40 ( V_30 -> V_85 , F_16 ( V_4 ) -> V_84 ) ) {
F_252 ( V_4 , & V_2 -> V_448 ) ;
F_253 ( V_4 ) ;
}
}
V_30 -> V_461 = V_500 ;
V_30 -> V_498 = V_218 ;
V_30 -> V_346 = 0 ;
}
static void F_309 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_501 )
F_307 ( V_2 , V_41 ) ;
if ( V_30 -> V_461 == V_500 ) {
T_1 V_218 = V_30 -> V_498 - F_219 ( V_41 -> V_82 ) + ( V_41 -> V_371 * 4 ) -
V_41 -> V_43 ;
if ( V_218 < V_4 -> V_10 ) {
T_3 V_214 ;
if ( F_263 ( V_4 , V_218 , & V_214 , 1 ) )
F_292 () ;
V_30 -> V_461 = V_502 | V_214 ;
if ( ! F_232 ( V_2 , V_418 ) )
V_2 -> V_466 ( V_2 , 0 ) ;
}
}
}
static int F_310 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_503 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_462 = V_4 -> V_10 - V_503 ;
int V_181 ;
F_276 () ;
if ( F_311 ( V_4 ) )
V_181 = F_277 ( V_4 , V_503 , V_30 -> V_458 . V_464 , V_462 ) ;
else
V_181 = F_312 ( V_4 , V_503 ,
V_30 -> V_458 . V_464 ) ;
if ( ! V_181 ) {
V_30 -> V_458 . V_10 -= V_462 ;
V_30 -> V_85 += V_462 ;
F_42 ( V_2 ) ;
}
F_278 () ;
return V_181 ;
}
static T_10 F_313 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_10 V_504 ;
if ( F_274 ( V_2 ) ) {
F_276 () ;
V_504 = F_314 ( V_4 ) ;
F_278 () ;
} else {
V_504 = F_314 ( V_4 ) ;
}
return V_504 ;
}
static inline int F_315 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_311 ( V_4 ) &&
F_313 ( V_2 , V_4 ) ;
}
static int F_316 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_503 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_462 = V_4 -> V_10 - V_503 ;
int V_505 ;
int V_506 = 0 ;
if ( V_30 -> V_458 . V_507 )
return 0 ;
if ( ! V_30 -> V_458 . V_508 && V_30 -> V_458 . V_509 )
V_30 -> V_458 . V_508 = F_317 () ;
if ( V_30 -> V_458 . V_508 && F_311 ( V_4 ) ) {
V_505 = F_318 ( V_30 -> V_458 . V_508 ,
V_4 , V_503 ,
V_30 -> V_458 . V_464 , V_462 ,
V_30 -> V_458 . V_509 ) ;
if ( V_505 < 0 )
goto V_209;
V_30 -> V_458 . V_505 = V_505 ;
V_506 = 1 ;
V_30 -> V_458 . V_10 -= V_462 ;
V_30 -> V_85 += V_462 ;
F_42 ( V_2 ) ;
if ( ( V_30 -> V_458 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_510 ) ||
( F_35 ( & V_2 -> V_72 ) > ( V_2 -> V_62 >> 1 ) ) ) {
V_30 -> V_458 . V_507 = 1 ;
V_2 -> V_466 ( V_2 , 0 ) ;
}
} else if ( V_462 > 0 ) {
V_30 -> V_458 . V_507 = 1 ;
V_2 -> V_466 ( V_2 , 0 ) ;
}
V_209:
return V_506 ;
}
static int F_319 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_511 )
{
const T_3 * V_512 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_220 ( V_4 , V_41 , V_30 , & V_512 ) &&
V_30 -> V_45 . V_273 &&
F_227 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_513 ) {
F_71 ( F_72 ( V_2 ) , V_514 ) ;
F_245 ( V_2 , V_4 ) ;
goto V_515;
}
}
if ( ! F_228 ( V_30 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) {
if ( ! V_41 -> V_513 )
F_245 ( V_2 , V_4 ) ;
goto V_515;
}
if ( V_41 -> V_513 ) {
F_230 ( V_2 ) ;
goto V_515;
}
F_224 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_41 -> V_43 && ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
if ( V_511 )
F_320 ( F_72 ( V_2 ) , V_516 ) ;
F_71 ( F_72 ( V_2 ) , V_517 ) ;
F_230 ( V_2 ) ;
return - 1 ;
}
return 1 ;
V_515:
F_253 ( V_4 ) ;
return 0 ;
}
int F_321 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_483 ;
V_30 -> V_45 . V_273 = 0 ;
if ( ( F_5 ( V_41 ) & V_518 ) == V_30 -> V_346 &&
F_16 ( V_4 ) -> V_82 == V_30 -> V_81 &&
! F_47 ( F_16 ( V_4 ) -> V_165 , V_30 -> V_98 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_403 ) {
if ( ! F_217 ( V_30 , V_41 ) )
goto V_519;
if ( ( T_5 ) ( V_30 -> V_45 . V_389 - V_30 -> V_45 . V_405 ) < 0 )
goto V_519;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_403 ) &&
V_30 -> V_81 == V_30 -> V_407 )
F_222 ( V_30 ) ;
F_209 ( V_2 , V_4 , 0 ) ;
F_253 ( V_4 ) ;
F_300 ( V_2 ) ;
return 0 ;
} else {
F_320 ( F_72 ( V_2 ) , V_516 ) ;
goto V_515;
}
} else {
int V_455 = 0 ;
int V_506 = 0 ;
if ( V_30 -> V_85 == V_30 -> V_81 &&
V_10 - V_18 <= V_30 -> V_458 . V_10 ) {
#ifdef F_322
if ( F_316 ( V_2 , V_4 , V_18 ) ) {
V_506 = 1 ;
V_455 = 1 ;
}
#endif
if ( V_30 -> V_458 . V_459 == V_460 &&
F_274 ( V_2 ) && ! V_506 ) {
F_275 ( V_463 ) ;
if ( ! F_310 ( V_2 , V_4 , V_18 ) )
V_455 = 1 ;
}
if ( V_455 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_403 ) &&
V_30 -> V_81 == V_30 -> V_407 )
F_222 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
F_273 ( V_4 , V_18 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
F_71 ( F_72 ( V_2 ) , V_520 ) ;
}
if ( V_506 )
F_323 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_455 ) {
if ( F_315 ( V_2 , V_4 ) )
goto V_521;
if ( V_18 ==
( sizeof( struct V_15 ) + V_403 ) &&
V_30 -> V_81 == V_30 -> V_407 )
F_222 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
if ( ( int ) V_4 -> V_51 > V_2 -> V_522 )
goto V_523;
F_71 ( F_72 ( V_2 ) , V_524 ) ;
F_273 ( V_4 , V_18 ) ;
F_254 ( & V_2 -> V_448 , V_4 ) ;
F_270 ( V_4 , V_2 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
}
F_43 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_165 != V_30 -> V_96 ) {
F_209 ( V_2 , V_4 , V_359 ) ;
F_300 ( V_2 ) ;
if ( ! F_306 ( V_2 ) )
goto V_525;
}
if ( ! V_506 || V_30 -> V_81 != V_30 -> V_407 )
F_302 ( V_2 , 0 ) ;
V_525:
#ifdef F_322
if ( V_506 )
F_254 ( & V_2 -> V_526 , V_4 ) ;
else
#endif
if ( V_455 )
F_253 ( V_4 ) ;
else
V_2 -> V_466 ( V_2 , 0 ) ;
return 0 ;
}
}
V_519:
if ( V_10 < ( V_41 -> V_371 << 2 ) || F_315 ( V_2 , V_4 ) )
goto V_521;
V_483 = F_319 ( V_2 , V_4 , V_41 , 1 ) ;
if ( V_483 <= 0 )
return - V_483 ;
V_523:
if ( V_41 -> V_317 && F_209 ( V_2 , V_4 , V_356 ) < 0 )
goto V_515;
F_41 ( V_2 , V_4 ) ;
F_309 ( V_2 , V_4 , V_41 ) ;
F_271 ( V_2 , V_4 ) ;
F_300 ( V_2 ) ;
F_305 ( V_2 ) ;
return 0 ;
V_521:
F_320 ( F_72 ( V_2 ) , V_516 ) ;
V_515:
F_253 ( V_4 ) ;
return 0 ;
}
static int F_324 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
const T_3 * V_512 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_527 * V_528 = V_30 -> V_529 ;
int V_530 = V_30 -> V_45 . V_46 ;
F_211 ( V_4 , & V_30 -> V_45 , & V_512 , 0 ) ;
if ( V_41 -> V_317 ) {
if ( F_16 ( V_4 ) -> V_165 != V_30 -> V_98 )
goto V_531;
if ( V_30 -> V_45 . V_273 && V_30 -> V_45 . V_83 &&
! F_192 ( V_30 -> V_45 . V_83 , V_30 -> V_272 ,
V_71 ) ) {
F_71 ( F_72 ( V_2 ) , V_532 ) ;
goto V_531;
}
if ( V_41 -> V_513 ) {
F_230 ( V_2 ) ;
goto V_515;
}
if ( ! V_41 -> V_43 )
goto V_533;
F_17 ( V_30 , V_41 ) ;
V_30 -> V_342 = F_16 ( V_4 ) -> V_82 ;
F_209 ( V_2 , V_4 , V_356 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_407 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_343 = F_155 ( V_41 -> V_52 ) ;
F_325 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_30 -> V_45 . V_383 ) {
V_30 -> V_45 . V_344 = V_30 -> V_45 . V_534 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_273 ) {
V_30 -> V_45 . V_387 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_403 ;
V_30 -> V_57 -= V_403 ;
F_222 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_144 ( V_30 ) && V_535 )
F_326 ( V_30 ) ;
F_327 ( V_2 ) ;
F_172 ( V_2 , V_6 -> V_298 ) ;
F_36 ( V_2 ) ;
V_30 -> V_85 = V_30 -> V_81 ;
if ( V_528 != NULL &&
V_528 -> V_536 > 0 &&
V_30 -> V_45 . V_402 > 0 ) {
int V_537 = V_30 -> V_45 . V_402
- V_398 ;
int V_536 = V_537
+ V_528 -> V_538 ;
if ( sizeof( V_528 -> V_539 ) >= V_536 ) {
memcpy ( & V_528 -> V_539 [ V_528 -> V_538 ] ,
V_512 , V_537 ) ;
V_528 -> V_536 = V_536 ;
}
}
F_328 () ;
F_236 ( V_2 , V_424 ) ;
F_329 ( V_2 , V_4 ) ;
V_6 -> V_540 -> V_541 ( V_2 ) ;
F_68 ( V_2 ) ;
F_330 ( V_2 ) ;
V_30 -> V_542 = V_71 ;
F_29 ( V_2 ) ;
if ( F_232 ( V_2 , V_543 ) )
F_331 ( V_2 , F_332 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_344 )
F_333 ( V_30 , V_30 -> V_343 ) ;
else
V_30 -> V_346 = 0 ;
if ( ! F_232 ( V_2 , V_418 ) ) {
V_2 -> V_431 ( V_2 ) ;
F_241 ( V_2 , V_544 , V_545 ) ;
}
if ( V_2 -> V_546 ||
V_6 -> V_547 . V_548 ||
V_6 -> V_8 . V_26 ) {
F_44 ( V_2 ) ;
V_6 -> V_8 . V_89 = V_71 ;
V_6 -> V_8 . V_27 = V_28 ;
F_8 ( V_2 ) ;
F_10 ( V_2 ) ;
F_136 ( V_2 , V_549 ,
V_550 , V_255 ) ;
V_515:
F_253 ( V_4 ) ;
return 0 ;
} else {
F_237 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_513 ) {
goto V_533;
}
if ( V_30 -> V_45 . V_406 && V_30 -> V_45 . V_273 &&
F_334 ( & V_30 -> V_45 , 0 ) )
goto V_533;
if ( V_41 -> V_43 ) {
F_236 ( V_2 , V_423 ) ;
if ( V_30 -> V_45 . V_273 ) {
V_30 -> V_45 . V_387 = 1 ;
F_222 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_403 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_407 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_343 = F_155 ( V_41 -> V_52 ) ;
V_30 -> V_342 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_158 = V_30 -> V_343 ;
F_18 ( V_30 , V_41 ) ;
F_327 ( V_2 ) ;
F_172 ( V_2 , V_6 -> V_298 ) ;
F_36 ( V_2 ) ;
F_335 ( V_2 ) ;
#if 0
return -1;
#else
goto V_515;
#endif
}
V_533:
F_336 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_530 ;
goto V_515;
V_531:
F_336 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_530 ;
return 1 ;
}
int F_337 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_551 = 0 ;
int V_483 ;
V_30 -> V_45 . V_273 = 0 ;
switch ( V_2 -> V_410 ) {
case V_416 :
goto V_515;
case V_552 :
if ( V_41 -> V_317 )
return 1 ;
if ( V_41 -> V_513 )
goto V_515;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_449 )
goto V_515;
if ( V_6 -> V_540 -> V_553 ( V_2 , V_4 ) < 0 )
return 1 ;
F_338 ( V_4 ) ;
return 0 ;
}
goto V_515;
case V_411 :
V_551 = F_324 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_551 >= 0 )
return V_551 ;
F_309 ( V_2 , V_4 , V_41 ) ;
F_253 ( V_4 ) ;
F_300 ( V_2 ) ;
return 0 ;
}
V_483 = F_319 ( V_2 , V_4 , V_41 , 0 ) ;
if ( V_483 <= 0 )
return - V_483 ;
if ( V_41 -> V_317 ) {
int V_554 = F_209 ( V_2 , V_4 , V_356 ) > 0 ;
switch ( V_2 -> V_410 ) {
case V_423 :
if ( V_554 ) {
V_30 -> V_85 = V_30 -> V_81 ;
F_328 () ;
F_236 ( V_2 , V_424 ) ;
V_2 -> V_431 ( V_2 ) ;
if ( V_2 -> V_487 )
F_241 ( V_2 ,
V_544 , V_545 ) ;
V_30 -> V_96 = F_16 ( V_4 ) -> V_165 ;
V_30 -> V_343 = F_155 ( V_41 -> V_52 ) <<
V_30 -> V_45 . V_344 ;
F_325 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_30 -> V_45 . V_387 )
V_30 -> V_57 -= V_403 ;
V_6 -> V_540 -> V_541 ( V_2 ) ;
F_68 ( V_2 ) ;
F_330 ( V_2 ) ;
V_30 -> V_542 = V_71 ;
F_327 ( V_2 ) ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_339 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_427 :
if ( V_30 -> V_96 == V_30 -> V_555 ) {
F_236 ( V_2 , V_428 ) ;
V_2 -> V_420 |= V_556 ;
F_54 ( F_53 ( V_2 ) ) ;
if ( ! F_232 ( V_2 , V_418 ) )
V_2 -> V_431 ( V_2 ) ;
else {
int V_557 ;
if ( V_30 -> V_558 < 0 ||
( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_449 , V_30 -> V_81 ) ) ) {
F_233 ( V_2 ) ;
F_71 ( F_72 ( V_2 ) , V_559 ) ;
return 1 ;
}
V_557 = F_340 ( V_2 ) ;
if ( V_557 > V_560 ) {
F_331 ( V_2 , V_557 - V_560 ) ;
} else if ( V_41 -> V_449 || F_274 ( V_2 ) ) {
F_331 ( V_2 , V_557 ) ;
} else {
F_238 ( V_2 , V_428 , V_557 ) ;
goto V_515;
}
}
}
break;
case V_425 :
if ( V_30 -> V_96 == V_30 -> V_555 ) {
F_238 ( V_2 , V_429 , 0 ) ;
goto V_515;
}
break;
case V_426 :
if ( V_30 -> V_96 == V_30 -> V_555 ) {
F_52 ( V_2 ) ;
F_233 ( V_2 ) ;
goto V_515;
}
break;
}
} else
goto V_515;
F_309 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_410 ) {
case V_414 :
case V_425 :
case V_426 :
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
case V_427 :
case V_428 :
if ( V_2 -> V_420 & V_421 ) {
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_449 , V_30 -> V_81 ) ) {
F_71 ( F_72 ( V_2 ) , V_559 ) ;
F_230 ( V_2 ) ;
return 1 ;
}
}
case V_424 :
F_271 ( V_2 , V_4 ) ;
V_551 = 1 ;
break;
}
if ( V_2 -> V_410 != V_416 ) {
F_300 ( V_2 ) ;
F_305 ( V_2 ) ;
}
if ( ! V_551 ) {
V_515:
F_253 ( V_4 ) ;
}
return 0 ;
}
