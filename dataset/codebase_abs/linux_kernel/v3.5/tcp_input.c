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
static bool F_19 ( const struct V_29 * V_30 , const struct V_15 * V_41 )
{
if ( V_41 -> V_42 && ! V_41 -> V_43 && ( V_30 -> V_31 & V_32 ) )
return true ;
return false ;
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
F_69 ( V_30 ) ;
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
static void F_70 ( struct V_1 * V_2 , const int V_137 ,
const int V_138 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_137 > V_30 -> V_115 ) {
int V_139 ;
V_30 -> V_115 = F_9 ( V_140 , V_137 ) ;
if ( V_138 )
V_139 = V_141 ;
else if ( F_71 ( V_30 ) )
V_139 = V_142 ;
else if ( F_66 ( V_30 ) )
V_139 = V_143 ;
else
V_139 = V_144 ;
F_72 ( F_73 ( V_2 ) , V_139 ) ;
#if V_145 > 1
F_74 ( L_1 ,
V_30 -> V_45 . V_130 , F_2 ( V_2 ) -> V_112 ,
V_30 -> V_115 ,
V_30 -> V_146 ,
V_30 -> V_147 ,
V_30 -> V_124 ? V_30 -> V_148 : 0 ) ;
#endif
F_65 ( V_30 ) ;
}
if ( V_137 > 0 )
F_69 ( V_30 ) ;
}
static void F_75 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ( V_30 -> V_149 == NULL ) ||
F_40 ( F_16 ( V_4 ) -> V_82 ,
F_16 ( V_30 -> V_149 ) -> V_82 ) )
V_30 -> V_149 = V_4 ;
if ( ! V_30 -> V_150 ||
F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_151 ) )
V_30 -> V_151 = F_16 ( V_4 ) -> V_84 ;
}
static void F_76 ( struct V_29 * V_30 , struct V_3 * V_4 )
{
if ( ! ( F_16 ( V_4 ) -> V_152 & ( V_153 | V_154 ) ) ) {
F_75 ( V_30 , V_4 ) ;
V_30 -> V_150 += F_77 ( V_4 ) ;
F_16 ( V_4 ) -> V_152 |= V_153 ;
}
}
static void F_78 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
F_75 ( V_30 , V_4 ) ;
if ( ! ( F_16 ( V_4 ) -> V_152 & ( V_153 | V_154 ) ) ) {
V_30 -> V_150 += F_77 ( V_4 ) ;
F_16 ( V_4 ) -> V_152 |= V_153 ;
}
}
static bool F_79 ( struct V_29 * V_30 , bool V_155 ,
T_1 V_156 , T_1 V_84 )
{
if ( F_47 ( V_84 , V_30 -> V_98 ) || ! F_40 ( V_156 , V_84 ) )
return false ;
if ( ! F_40 ( V_156 , V_30 -> V_98 ) )
return false ;
if ( F_47 ( V_156 , V_30 -> V_96 ) )
return true ;
if ( ! V_155 || ! V_30 -> V_124 )
return false ;
if ( F_47 ( V_84 , V_30 -> V_96 ) )
return false ;
if ( ! F_40 ( V_156 , V_30 -> V_124 ) )
return true ;
if ( ! F_47 ( V_84 , V_30 -> V_124 ) )
return false ;
return ! F_40 ( V_156 , V_84 - V_30 -> V_157 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_158 = 0 ;
T_1 V_159 = V_30 -> V_98 ;
T_1 V_160 = F_81 ( V_30 ) ;
if ( ! F_66 ( V_30 ) || ! V_30 -> V_161 ||
! F_47 ( V_160 , V_30 -> V_162 ) ||
V_6 -> V_112 != V_163 )
return;
F_82 (skb, sk) {
T_1 V_164 = F_16 ( V_4 ) -> V_164 ;
if ( V_4 == F_83 ( V_2 ) )
break;
if ( V_158 == V_30 -> V_161 )
break;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
continue;
if ( ! ( F_16 ( V_4 ) -> V_152 & V_165 ) )
continue;
if ( F_47 ( V_160 , V_164 ) ) {
F_16 ( V_4 ) -> V_152 &= ~ V_165 ;
V_30 -> V_161 -= F_77 ( V_4 ) ;
F_78 ( V_30 , V_4 ) ;
F_72 ( F_73 ( V_2 ) , V_166 ) ;
} else {
if ( F_40 ( V_164 , V_159 ) )
V_159 = V_164 ;
V_158 += F_77 ( V_4 ) ;
}
}
if ( V_30 -> V_161 )
V_30 -> V_162 = V_159 ;
}
static bool F_84 ( struct V_1 * V_2 , const struct V_3 * V_167 ,
struct V_168 * V_169 , int V_170 ,
T_1 V_171 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_172 = F_85 ( & V_169 [ 0 ] . V_156 ) ;
T_1 V_173 = F_85 ( & V_169 [ 0 ] . V_84 ) ;
bool V_174 = false ;
if ( F_40 ( V_172 , F_16 ( V_167 ) -> V_164 ) ) {
V_174 = true ;
F_67 ( V_30 ) ;
F_72 ( F_73 ( V_2 ) , V_175 ) ;
} else if ( V_170 > 1 ) {
T_1 V_176 = F_85 ( & V_169 [ 1 ] . V_84 ) ;
T_1 V_177 = F_85 ( & V_169 [ 1 ] . V_156 ) ;
if ( ! F_47 ( V_173 , V_176 ) &&
! F_40 ( V_172 , V_177 ) ) {
V_174 = true ;
F_67 ( V_30 ) ;
F_72 ( F_73 ( V_2 ) ,
V_178 ) ;
}
}
if ( V_174 && V_30 -> V_124 && V_30 -> V_148 &&
! F_47 ( V_173 , V_171 ) &&
F_47 ( V_173 , V_30 -> V_124 ) )
V_30 -> V_148 -- ;
return V_174 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_156 , T_1 V_84 )
{
int V_179 ;
bool V_180 ;
unsigned int V_181 ;
unsigned int V_58 ;
V_180 = ! F_47 ( V_156 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( F_77 ( V_4 ) > 1 && ! V_180 &&
F_47 ( F_16 ( V_4 ) -> V_84 , V_156 ) ) {
V_58 = F_87 ( V_4 ) ;
V_180 = ! F_47 ( V_156 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_180 ) {
V_181 = V_156 - F_16 ( V_4 ) -> V_82 ;
if ( V_181 < V_58 )
V_181 = V_58 ;
} else {
V_181 = V_84 - F_16 ( V_4 ) -> V_82 ;
if ( V_181 < V_58 )
return - V_182 ;
}
if ( V_181 > V_58 ) {
unsigned int V_183 = ( V_181 / V_58 ) * V_58 ;
if ( ! V_180 && V_183 < V_181 ) {
V_183 += V_58 ;
if ( V_183 > V_4 -> V_10 )
return 0 ;
}
V_181 = V_183 ;
}
V_179 = F_88 ( V_2 , V_4 , V_181 , V_58 ) ;
if ( V_179 < 0 )
return V_179 ;
}
return V_180 ;
}
static T_3 F_89 ( struct V_1 * V_2 ,
struct V_184 * V_185 , T_3 V_152 ,
T_1 V_156 , T_1 V_84 ,
bool V_174 , int V_186 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_187 = V_185 -> V_187 ;
if ( V_174 && ( V_152 & V_188 ) ) {
if ( V_30 -> V_124 && V_30 -> V_148 &&
F_47 ( V_84 , V_30 -> V_124 ) )
V_30 -> V_148 -- ;
if ( V_152 & V_154 )
V_185 -> V_189 = F_9 ( V_187 , V_185 -> V_189 ) ;
}
if ( ! F_47 ( V_84 , V_30 -> V_96 ) )
return V_152 ;
if ( ! ( V_152 & V_154 ) ) {
if ( V_152 & V_165 ) {
if ( V_152 & V_153 ) {
V_152 &= ~ ( V_153 | V_165 ) ;
V_30 -> V_150 -= V_186 ;
V_30 -> V_161 -= V_186 ;
}
} else {
if ( ! ( V_152 & V_188 ) ) {
if ( F_40 ( V_156 ,
F_81 ( V_30 ) ) )
V_185 -> V_189 = F_9 ( V_187 ,
V_185 -> V_189 ) ;
if ( ! F_47 ( V_84 , V_30 -> V_190 ) )
V_185 -> V_191 |= V_192 ;
}
if ( V_152 & V_153 ) {
V_152 &= ~ V_153 ;
V_30 -> V_150 -= V_186 ;
}
}
V_152 |= V_154 ;
V_185 -> V_191 |= V_193 ;
V_30 -> V_147 += V_186 ;
V_187 += V_186 ;
if ( ! F_66 ( V_30 ) && ( V_30 -> V_129 != NULL ) &&
F_40 ( V_156 , F_16 ( V_30 -> V_129 ) -> V_82 ) )
V_30 -> V_194 += V_186 ;
if ( V_187 > V_30 -> V_146 )
V_30 -> V_146 = V_187 ;
}
if ( V_174 && ( V_152 & V_165 ) ) {
V_152 &= ~ V_165 ;
V_30 -> V_161 -= V_186 ;
}
return V_152 ;
}
static bool F_90 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_184 * V_185 ,
unsigned int V_186 , int V_195 , int V_58 ,
bool V_174 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_196 = F_91 ( V_2 , V_4 ) ;
T_1 V_156 = F_16 ( V_4 ) -> V_82 ;
T_1 V_84 = V_156 + V_195 ;
F_92 ( ! V_186 ) ;
F_89 ( V_2 , V_185 , F_16 ( V_4 ) -> V_152 ,
V_156 , V_84 , V_174 , V_186 ) ;
if ( V_4 == V_30 -> V_129 )
V_30 -> V_194 += V_186 ;
F_16 ( V_196 ) -> V_84 += V_195 ;
F_16 ( V_4 ) -> V_82 += V_195 ;
F_3 ( V_196 ) -> V_197 += V_186 ;
F_92 ( F_3 ( V_4 ) -> V_197 < V_186 ) ;
F_3 ( V_4 ) -> V_197 -= V_186 ;
if ( ! F_3 ( V_196 ) -> V_11 ) {
F_3 ( V_196 ) -> V_11 = V_58 ;
F_3 ( V_196 ) -> V_198 = V_2 -> V_199 ;
}
if ( F_3 ( V_4 ) -> V_197 <= 1 ) {
F_3 ( V_4 ) -> V_11 = 0 ;
F_3 ( V_4 ) -> V_198 = 0 ;
}
F_16 ( V_196 ) -> V_152 |= ( F_16 ( V_4 ) -> V_152 & V_200 ) ;
if ( V_4 -> V_10 > 0 ) {
F_92 ( ! F_77 ( V_4 ) ) ;
F_72 ( F_73 ( V_2 ) , V_201 ) ;
return false ;
}
if ( V_4 == V_30 -> V_149 )
V_30 -> V_149 = V_196 ;
if ( V_4 == V_30 -> V_202 )
V_30 -> V_202 = V_196 ;
if ( V_4 == V_30 -> V_129 ) {
V_30 -> V_129 = V_196 ;
V_30 -> V_194 -= F_77 ( V_196 ) ;
}
F_16 ( V_4 ) -> V_203 |= F_16 ( V_196 ) -> V_203 ;
if ( V_4 == F_93 ( V_2 ) )
F_94 ( V_2 , V_4 ) ;
F_95 ( V_4 , V_2 ) ;
F_96 ( V_2 , V_4 ) ;
F_72 ( F_73 ( V_2 ) , V_204 ) ;
return true ;
}
static int F_97 ( const struct V_3 * V_4 )
{
return F_77 ( V_4 ) == 1 ? V_4 -> V_10 : F_87 ( V_4 ) ;
}
static int F_98 ( const struct V_3 * V_4 )
{
return ! F_99 ( V_4 ) && F_100 ( V_4 ) ;
}
static struct V_3 * F_101 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_184 * V_185 ,
T_1 V_156 , T_1 V_84 ,
bool V_174 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_196 ;
int V_58 ;
int V_186 = 0 ;
int V_10 ;
int V_180 ;
if ( ! F_102 ( V_2 ) )
goto V_205;
if ( ! V_174 &&
( F_16 ( V_4 ) -> V_152 & ( V_153 | V_165 ) ) == V_165 )
goto V_205;
if ( ! F_98 ( V_4 ) )
goto V_205;
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) )
goto V_205;
if ( F_103 ( V_4 == F_104 ( V_2 ) ) )
goto V_205;
V_196 = F_91 ( V_2 , V_4 ) ;
if ( ( F_16 ( V_196 ) -> V_152 & V_206 ) != V_154 )
goto V_205;
V_180 = ! F_47 ( V_156 , F_16 ( V_4 ) -> V_82 ) &&
! F_40 ( V_84 , F_16 ( V_4 ) -> V_84 ) ;
if ( V_180 ) {
V_10 = V_4 -> V_10 ;
V_186 = F_77 ( V_4 ) ;
V_58 = F_97 ( V_4 ) ;
if ( V_58 != F_97 ( V_196 ) )
goto V_205;
} else {
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_156 ) )
goto V_207;
if ( F_77 ( V_4 ) <= 1 )
goto V_207;
V_180 = ! F_47 ( V_156 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_180 ) {
goto V_205;
}
V_10 = V_84 - F_16 ( V_4 ) -> V_82 ;
F_92 ( V_10 < 0 ) ;
F_92 ( V_10 > V_4 -> V_10 ) ;
V_58 = F_87 ( V_4 ) ;
if ( V_58 != F_97 ( V_196 ) )
goto V_205;
if ( V_10 == V_58 ) {
V_186 = 1 ;
} else if ( V_10 < V_58 ) {
goto V_207;
} else {
V_186 = V_10 / V_58 ;
V_10 = V_186 * V_58 ;
}
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_82 + V_10 , V_30 -> V_96 ) )
goto V_205;
if ( ! F_105 ( V_196 , V_4 , V_10 ) )
goto V_205;
if ( ! F_90 ( V_2 , V_4 , V_185 , V_186 , V_10 , V_58 , V_174 ) )
goto V_208;
if ( V_196 == F_106 ( V_2 ) )
goto V_208;
V_4 = F_107 ( V_2 , V_196 ) ;
if ( ! F_98 ( V_4 ) ||
( V_4 == F_83 ( V_2 ) ) ||
( ( F_16 ( V_4 ) -> V_152 & V_206 ) != V_154 ) ||
( V_58 != F_97 ( V_4 ) ) )
goto V_208;
V_10 = V_4 -> V_10 ;
if ( F_105 ( V_196 , V_4 , V_10 ) ) {
V_186 += F_77 ( V_4 ) ;
F_90 ( V_2 , V_4 , V_185 , F_77 ( V_4 ) , V_10 , V_58 , 0 ) ;
}
V_208:
V_185 -> V_187 += V_186 ;
return V_196 ;
V_207:
return V_4 ;
V_205:
F_72 ( F_73 ( V_2 ) , V_209 ) ;
return NULL ;
}
static struct V_3 * F_108 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_210 * V_211 ,
struct V_184 * V_185 ,
T_1 V_156 , T_1 V_84 ,
bool V_212 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_213 ;
F_109 (skb, sk) {
int V_180 = 0 ;
bool V_174 = V_212 ;
if ( V_4 == F_83 ( V_2 ) )
break;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_84 ) )
break;
if ( ( V_211 != NULL ) &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_211 -> V_84 ) ) {
V_180 = F_86 ( V_2 , V_4 ,
V_211 -> V_156 ,
V_211 -> V_84 ) ;
if ( V_180 > 0 )
V_174 = true ;
}
if ( V_180 <= 0 ) {
V_213 = F_101 ( V_2 , V_4 , V_185 ,
V_156 , V_84 , V_174 ) ;
if ( V_213 != NULL ) {
if ( V_213 != V_4 ) {
V_4 = V_213 ;
continue;
}
V_180 = 0 ;
} else {
V_180 = F_86 ( V_2 , V_4 ,
V_156 ,
V_84 ) ;
}
}
if ( F_103 ( V_180 < 0 ) )
break;
if ( V_180 ) {
F_16 ( V_4 ) -> V_152 =
F_89 ( V_2 ,
V_185 ,
F_16 ( V_4 ) -> V_152 ,
F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ,
V_174 ,
F_77 ( V_4 ) ) ;
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 ,
F_81 ( V_30 ) ) )
F_94 ( V_2 , V_4 ) ;
}
V_185 -> V_187 += F_77 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_110 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_184 * V_185 ,
T_1 V_214 )
{
F_109 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_214 ) )
break;
V_185 -> V_187 += F_77 ( V_4 ) ;
}
return V_4 ;
}
static struct V_3 * F_111 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_210 * V_211 ,
struct V_184 * V_185 ,
T_1 V_214 )
{
if ( V_211 == NULL )
return V_4 ;
if ( F_40 ( V_211 -> V_156 , V_214 ) ) {
V_4 = F_110 ( V_4 , V_2 , V_185 , V_211 -> V_156 ) ;
V_4 = F_108 ( V_4 , V_2 , NULL , V_185 ,
V_211 -> V_156 , V_211 -> V_84 ,
1 ) ;
}
return V_4 ;
}
static int F_112 ( const struct V_29 * V_30 , const struct V_210 * V_215 )
{
return V_215 < V_30 -> V_216 + F_113 ( V_30 -> V_216 ) ;
}
static int
F_114 ( struct V_1 * V_2 , const struct V_3 * V_167 ,
T_1 V_171 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
const unsigned char * V_217 = ( F_4 ( V_167 ) +
F_16 ( V_167 ) -> V_152 ) ;
struct V_168 * V_218 = (struct V_168 * ) ( V_217 + 2 ) ;
struct V_210 V_169 [ V_219 ] ;
struct V_210 * V_215 ;
struct V_184 V_185 ;
struct V_3 * V_4 ;
int V_170 = F_9 ( V_219 , ( V_217 [ 1 ] - V_220 ) >> 3 ) ;
int V_221 ;
bool V_222 = false ;
int V_223 , V_224 ;
int V_225 ;
V_185 . V_191 = 0 ;
V_185 . V_189 = V_30 -> V_226 ;
if ( ! V_30 -> V_147 ) {
if ( F_115 ( V_30 -> V_146 ) )
V_30 -> V_146 = 0 ;
F_116 ( V_2 ) ;
}
V_222 = F_84 ( V_2 , V_167 , V_218 ,
V_170 , V_171 ) ;
if ( V_222 )
V_185 . V_191 |= V_227 ;
if ( F_40 ( F_16 ( V_167 ) -> V_164 , V_171 - V_30 -> V_157 ) )
return 0 ;
if ( ! V_30 -> V_226 )
goto V_208;
V_221 = 0 ;
V_225 = 0 ;
for ( V_223 = 0 ; V_223 < V_170 ; V_223 ++ ) {
bool V_174 = ! V_223 && V_222 ;
V_169 [ V_221 ] . V_156 = F_85 ( & V_218 [ V_223 ] . V_156 ) ;
V_169 [ V_221 ] . V_84 = F_85 ( & V_218 [ V_223 ] . V_84 ) ;
if ( ! F_79 ( V_30 , V_174 ,
V_169 [ V_221 ] . V_156 ,
V_169 [ V_221 ] . V_84 ) ) {
int V_139 ;
if ( V_174 ) {
if ( ! V_30 -> V_124 )
V_139 = V_228 ;
else
V_139 = V_229 ;
} else {
if ( ( F_16 ( V_167 ) -> V_164 != V_30 -> V_96 ) &&
! F_47 ( V_169 [ V_221 ] . V_84 , V_30 -> V_96 ) )
continue;
V_139 = V_230 ;
}
F_72 ( F_73 ( V_2 ) , V_139 ) ;
if ( V_223 == 0 )
V_225 = - 1 ;
continue;
}
if ( ! F_47 ( V_169 [ V_221 ] . V_84 , V_171 ) )
continue;
V_221 ++ ;
}
for ( V_223 = V_221 - 1 ; V_223 > 0 ; V_223 -- ) {
for ( V_224 = 0 ; V_224 < V_223 ; V_224 ++ ) {
if ( F_47 ( V_169 [ V_224 ] . V_156 , V_169 [ V_224 + 1 ] . V_156 ) ) {
F_117 ( V_169 [ V_224 ] , V_169 [ V_224 + 1 ] ) ;
if ( V_224 == V_225 )
V_225 = V_224 + 1 ;
}
}
}
V_4 = F_104 ( V_2 ) ;
V_185 . V_187 = 0 ;
V_223 = 0 ;
if ( ! V_30 -> V_147 ) {
V_215 = V_30 -> V_216 + F_113 ( V_30 -> V_216 ) ;
} else {
V_215 = V_30 -> V_216 ;
while ( F_112 ( V_30 , V_215 ) && ! V_215 -> V_156 &&
! V_215 -> V_84 )
V_215 ++ ;
}
while ( V_223 < V_221 ) {
T_1 V_156 = V_169 [ V_223 ] . V_156 ;
T_1 V_84 = V_169 [ V_223 ] . V_84 ;
bool V_174 = ( V_222 && ( V_223 == V_225 ) ) ;
struct V_210 * V_211 = NULL ;
if ( V_222 && ( ( V_223 + 1 ) == V_225 ) )
V_211 = & V_169 [ V_223 + 1 ] ;
while ( F_112 ( V_30 , V_215 ) &&
! F_40 ( V_156 , V_215 -> V_84 ) )
V_215 ++ ;
if ( F_112 ( V_30 , V_215 ) && ! V_174 &&
F_47 ( V_84 , V_215 -> V_156 ) ) {
if ( F_40 ( V_156 , V_215 -> V_156 ) ) {
V_4 = F_110 ( V_4 , V_2 , & V_185 ,
V_156 ) ;
V_4 = F_108 ( V_4 , V_2 , V_211 ,
& V_185 ,
V_156 ,
V_215 -> V_156 ,
V_174 ) ;
}
if ( ! F_47 ( V_84 , V_215 -> V_84 ) )
goto V_231;
V_4 = F_111 ( V_4 , V_2 , V_211 ,
& V_185 ,
V_215 -> V_84 ) ;
if ( F_81 ( V_30 ) == V_215 -> V_84 ) {
V_4 = F_93 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_185 . V_187 = V_30 -> V_146 ;
V_215 ++ ;
goto V_232;
}
V_4 = F_110 ( V_4 , V_2 , & V_185 , V_215 -> V_84 ) ;
V_215 ++ ;
continue;
}
if ( ! F_40 ( V_156 , F_81 ( V_30 ) ) ) {
V_4 = F_93 ( V_2 ) ;
if ( V_4 == NULL )
break;
V_185 . V_187 = V_30 -> V_146 ;
}
V_4 = F_110 ( V_4 , V_2 , & V_185 , V_156 ) ;
V_232:
V_4 = F_108 ( V_4 , V_2 , V_211 , & V_185 ,
V_156 , V_84 , V_174 ) ;
V_231:
if ( F_47 ( V_84 , V_30 -> V_190 ) )
V_185 . V_191 &= ~ V_192 ;
V_223 ++ ;
}
for ( V_223 = 0 ; V_223 < F_113 ( V_30 -> V_216 ) - V_221 ; V_223 ++ ) {
V_30 -> V_216 [ V_223 ] . V_156 = 0 ;
V_30 -> V_216 [ V_223 ] . V_84 = 0 ;
}
for ( V_224 = 0 ; V_224 < V_221 ; V_224 ++ )
V_30 -> V_216 [ V_223 ++ ] = V_169 [ V_224 ] ;
F_80 ( V_2 ) ;
F_118 ( V_30 ) ;
if ( ( V_185 . V_189 < V_30 -> V_146 ) &&
( ( V_6 -> V_112 != V_233 ) || V_30 -> V_124 ) &&
( ! V_30 -> V_190 || F_47 ( V_30 -> V_96 , V_30 -> V_190 ) ) )
F_70 ( V_2 , V_30 -> V_146 - V_185 . V_189 , 0 ) ;
V_208:
#if V_145 > 0
F_115 ( ( int ) V_30 -> V_147 < 0 ) ;
F_115 ( ( int ) V_30 -> V_150 < 0 ) ;
F_115 ( ( int ) V_30 -> V_161 < 0 ) ;
F_115 ( ( int ) F_63 ( V_30 ) < 0 ) ;
#endif
return V_185 . V_191 ;
}
static bool F_119 ( struct V_29 * V_30 )
{
T_1 V_234 ;
V_234 = F_31 ( V_30 -> V_150 , 1U ) ;
V_234 = F_9 ( V_234 , V_30 -> V_226 ) ;
if ( ( V_30 -> V_147 + V_234 ) > V_30 -> V_226 ) {
V_30 -> V_147 = V_30 -> V_226 - V_234 ;
return true ;
}
return false ;
}
static void F_120 ( struct V_1 * V_2 , const int V_235 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_119 ( V_30 ) )
F_70 ( V_2 , V_30 -> V_226 + V_235 , 0 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
V_30 -> V_147 ++ ;
F_120 ( V_2 , 0 ) ;
F_118 ( V_30 ) ;
}
static void F_122 ( struct V_1 * V_2 , int V_236 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_236 > 0 ) {
if ( V_236 - 1 >= V_30 -> V_147 )
V_30 -> V_147 = 0 ;
else
V_30 -> V_147 -= V_236 - 1 ;
}
F_120 ( V_2 , V_236 ) ;
F_118 ( V_30 ) ;
}
static inline void F_123 ( struct V_29 * V_30 )
{
V_30 -> V_147 = 0 ;
}
static int F_124 ( const struct V_29 * V_30 )
{
return ( V_237 == 0x2 ) && ! F_71 ( V_30 ) ;
}
bool F_125 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! V_237 )
return false ;
if ( V_6 -> V_238 . V_239 )
return false ;
if ( F_124 ( V_30 ) )
return true ;
if ( V_30 -> V_161 > 1 )
return false ;
V_4 = F_104 ( V_2 ) ;
if ( F_126 ( V_2 , V_4 ) )
return true ;
V_4 = F_107 ( V_2 , V_4 ) ;
F_109 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_152 & V_188 )
return false ;
if ( ! ( F_16 ( V_4 ) -> V_152 & V_154 ) )
break;
}
return true ;
}
void F_127 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ( ! V_30 -> V_240 && V_6 -> V_112 <= V_241 ) ||
V_30 -> V_96 == V_30 -> V_128 ||
( ( V_6 -> V_112 == V_233 || V_30 -> V_240 ) &&
! V_6 -> V_242 ) ) {
V_30 -> V_121 = F_128 ( V_2 ) ;
if ( V_30 -> V_240 ) {
T_1 V_243 ;
V_243 = V_30 -> V_109 ;
V_30 -> V_109 = 2 ;
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
V_30 -> V_109 = V_243 ;
} else {
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
}
F_129 ( V_2 , V_244 ) ;
}
V_30 -> V_124 = V_30 -> V_96 ;
V_30 -> V_148 = 0 ;
V_4 = F_104 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_152 & V_188 )
V_30 -> V_124 = 0 ;
if ( F_16 ( V_4 ) -> V_152 & V_165 ) {
F_16 ( V_4 ) -> V_152 &= ~ V_165 ;
V_30 -> V_161 -= F_77 ( V_4 ) ;
}
F_118 ( V_30 ) ;
V_30 -> V_109 = F_9 ( V_30 -> V_109 , F_63 ( V_30 ) + 1 ) ;
if ( F_124 ( V_30 ) && ( V_30 -> V_240 ||
( ( 1 << V_6 -> V_112 ) & ( V_245 | V_246 ) ) ) &&
F_47 ( V_30 -> V_128 , V_30 -> V_96 ) ) {
V_30 -> V_190 = V_30 -> V_128 ;
} else {
V_30 -> V_190 = V_30 -> V_98 ;
}
F_64 ( V_2 , V_241 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
V_30 -> V_240 = 1 ;
}
static void F_130 ( struct V_1 * V_2 , int V_247 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
V_30 -> V_150 = 0 ;
V_30 -> V_161 = 0 ;
if ( F_71 ( V_30 ) )
F_123 ( V_30 ) ;
F_82 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_152 &= ~ V_153 ;
if ( ( V_30 -> V_240 == 1 ) && ! ( V_191 & V_248 ) ) {
if ( F_16 ( V_4 ) -> V_152 & V_165 )
V_30 -> V_161 += F_77 ( V_4 ) ;
V_191 |= V_248 ;
} else {
if ( F_16 ( V_4 ) -> V_152 & V_188 )
V_30 -> V_124 = 0 ;
F_16 ( V_4 ) -> V_152 &= ~ V_165 ;
}
if ( ! ( F_16 ( V_4 ) -> V_152 & V_154 ) ) {
F_16 ( V_4 ) -> V_152 |= V_153 ;
V_30 -> V_150 += F_77 ( V_4 ) ;
V_30 -> V_151 = F_16 ( V_4 ) -> V_84 ;
}
}
F_118 ( V_30 ) ;
V_30 -> V_109 = F_63 ( V_30 ) + V_247 ;
V_30 -> V_127 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_240 = 0 ;
V_30 -> V_122 = 0 ;
V_30 -> V_115 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_64 ( V_2 , V_233 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
F_131 ( V_30 ) ;
}
static void F_132 ( struct V_29 * V_30 )
{
V_30 -> V_161 = 0 ;
V_30 -> V_150 = 0 ;
V_30 -> V_124 = 0 ;
V_30 -> V_148 = 0 ;
}
void F_133 ( struct V_29 * V_30 )
{
F_132 ( V_30 ) ;
V_30 -> V_146 = 0 ;
V_30 -> V_147 = 0 ;
}
void F_134 ( struct V_1 * V_2 , int V_249 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_6 -> V_112 <= V_241 || V_30 -> V_96 == V_30 -> V_128 ||
( V_6 -> V_112 == V_233 && ! V_6 -> V_242 ) ) {
V_30 -> V_121 = F_128 ( V_2 ) ;
V_30 -> V_111 = V_6 -> V_125 -> V_126 ( V_2 ) ;
F_129 ( V_2 , V_250 ) ;
}
V_30 -> V_109 = 1 ;
V_30 -> V_127 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_122 = 0 ;
F_132 ( V_30 ) ;
if ( F_71 ( V_30 ) )
F_123 ( V_30 ) ;
if ( ! V_249 ) {
V_30 -> V_124 = V_30 -> V_96 ;
} else {
V_30 -> V_147 = 0 ;
V_30 -> V_146 = 0 ;
}
F_131 ( V_30 ) ;
F_82 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
if ( F_16 ( V_4 ) -> V_152 & V_188 )
V_30 -> V_124 = 0 ;
F_16 ( V_4 ) -> V_152 &= ( ~ V_206 ) | V_154 ;
if ( ! ( F_16 ( V_4 ) -> V_152 & V_154 ) || V_249 ) {
F_16 ( V_4 ) -> V_152 &= ~ V_154 ;
F_16 ( V_4 ) -> V_152 |= V_153 ;
V_30 -> V_150 += F_77 ( V_4 ) ;
V_30 -> V_151 = F_16 ( V_4 ) -> V_84 ;
}
}
F_118 ( V_30 ) ;
V_30 -> V_115 = F_37 (unsigned int, tp->reordering,
sysctl_tcp_reordering) ;
F_64 ( V_2 , V_233 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
F_12 ( V_30 ) ;
V_30 -> V_240 = 0 ;
}
static bool F_135 ( struct V_1 * V_2 , int V_191 )
{
if ( V_191 & V_251 ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_72 ( F_73 ( V_2 ) , V_252 ) ;
F_134 ( V_2 , 1 ) ;
V_6 -> V_242 ++ ;
F_136 ( V_2 , F_104 ( V_2 ) ) ;
F_137 ( V_2 , V_253 ,
V_6 -> V_90 , V_254 ) ;
return true ;
}
return false ;
}
static inline int F_138 ( const struct V_29 * V_30 )
{
return F_71 ( V_30 ) ? V_30 -> V_147 + 1 : V_30 -> V_146 ;
}
static inline int F_139 ( const struct V_29 * V_30 )
{
return F_66 ( V_30 ) ? V_30 -> V_146 : V_30 -> V_147 + 1 ;
}
static bool F_140 ( struct V_1 * V_2 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
unsigned long V_255 ;
if ( V_256 < 2 || ( V_191 & V_257 ) || ! V_30 -> V_92 )
return false ;
V_255 = F_27 (unsigned long, (tp->srtt >> 5), msecs_to_jiffies(2)) ;
if ( ! F_141 ( F_2 ( V_2 ) -> V_258 , ( V_259 + V_255 ) ) )
return false ;
F_137 ( V_2 , V_253 , V_255 , V_254 ) ;
V_30 -> V_260 = 1 ;
return true ;
}
static inline int F_142 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_71 - F_16 ( V_4 ) -> V_261 > F_2 ( V_2 ) -> V_90 ;
}
static inline int F_143 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return V_30 -> V_226 &&
F_142 ( V_2 , F_104 ( V_2 ) ) ;
}
static bool F_144 ( struct V_1 * V_2 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_226 ;
if ( V_30 -> V_240 )
return false ;
if ( V_30 -> V_150 )
return true ;
if ( F_139 ( V_30 ) > V_30 -> V_115 )
return true ;
if ( F_66 ( V_30 ) && F_143 ( V_2 ) )
return true ;
V_226 = V_30 -> V_226 ;
if ( V_226 <= V_30 -> V_115 &&
V_30 -> V_147 >= F_27 ( T_2 , V_226 / 2 , V_116 ) &&
! F_145 ( V_2 ) ) {
return true ;
}
if ( ( V_30 -> V_262 || V_263 ) &&
F_146 ( V_30 ) && F_139 ( V_30 ) > 1 &&
F_147 ( V_30 ) && ! F_83 ( V_2 ) )
return true ;
if ( V_30 -> V_264 && ! V_30 -> V_161 && V_30 -> V_147 &&
( V_30 -> V_226 == ( V_30 -> V_147 + 1 ) && V_30 -> V_226 < 4 ) &&
! F_145 ( V_2 ) )
return ! F_140 ( V_2 , V_191 ) ;
return false ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( ! F_66 ( V_30 ) || ! F_143 ( V_2 ) )
return;
V_4 = V_30 -> V_202 ;
if ( V_30 -> V_202 == NULL )
V_4 = F_104 ( V_2 ) ;
F_109 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
if ( ! F_142 ( V_2 , V_4 ) )
break;
F_76 ( V_30 , V_4 ) ;
}
V_30 -> V_202 = V_4 ;
F_118 ( V_30 ) ;
}
static void F_149 ( struct V_1 * V_2 , int V_265 , int V_266 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_158 , V_267 ;
int V_179 ;
unsigned int V_58 ;
const T_1 V_268 = F_147 ( V_30 ) ? V_30 -> V_98 : V_30 -> V_128 ;
F_115 ( V_265 > V_30 -> V_226 ) ;
if ( V_30 -> V_129 ) {
V_4 = V_30 -> V_129 ;
V_158 = V_30 -> V_194 ;
if ( V_266 && V_4 != F_104 ( V_2 ) )
return;
} else {
V_4 = F_104 ( V_2 ) ;
V_158 = 0 ;
}
F_109 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
V_30 -> V_129 = V_4 ;
V_30 -> V_194 = V_158 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_268 ) )
break;
V_267 = V_158 ;
if ( F_66 ( V_30 ) || F_71 ( V_30 ) ||
( F_16 ( V_4 ) -> V_152 & V_154 ) )
V_158 += F_77 ( V_4 ) ;
if ( V_158 > V_265 ) {
if ( ( F_147 ( V_30 ) && ! F_66 ( V_30 ) ) ||
( F_16 ( V_4 ) -> V_152 & V_154 ) ||
( V_267 >= V_265 ) )
break;
V_58 = F_3 ( V_4 ) -> V_11 ;
V_179 = F_88 ( V_2 , V_4 , ( V_265 - V_267 ) * V_58 , V_58 ) ;
if ( V_179 < 0 )
break;
V_158 = V_265 ;
}
F_76 ( V_30 , V_4 ) ;
if ( V_266 )
break;
}
F_118 ( V_30 ) ;
}
static void F_150 ( struct V_1 * V_2 , int V_269 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_71 ( V_30 ) ) {
F_149 ( V_2 , 1 , 1 ) ;
} else if ( F_66 ( V_30 ) ) {
int V_270 = V_30 -> V_146 - V_30 -> V_115 ;
if ( V_270 <= 0 )
V_270 = 1 ;
F_149 ( V_2 , V_270 , 0 ) ;
} else {
int V_271 = V_30 -> V_147 - V_30 -> V_115 ;
if ( V_271 >= 0 )
F_149 ( V_2 , V_271 , 0 ) ;
else if ( V_269 )
F_149 ( V_2 , 1 , 1 ) ;
}
F_148 ( V_2 ) ;
}
static inline void F_151 ( struct V_29 * V_30 )
{
V_30 -> V_109 = F_9 ( V_30 -> V_109 ,
F_63 ( V_30 ) + F_152 ( V_30 ) ) ;
V_30 -> V_70 = V_71 ;
}
static inline T_1 F_153 ( const struct V_1 * V_2 )
{
const struct V_272 * V_273 = F_2 ( V_2 ) -> V_125 ;
return V_273 -> V_274 ? V_273 -> V_274 ( V_2 ) : F_7 ( V_2 ) -> V_111 ;
}
static void F_154 ( struct V_1 * V_2 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_275 = V_30 -> V_127 + 1 ;
if ( ( V_191 & ( V_276 | V_227 ) ) ||
( F_71 ( V_30 ) && ! ( V_191 & V_277 ) ) ) {
V_30 -> V_127 = V_275 & 1 ;
V_275 >>= 1 ;
if ( V_275 && V_30 -> V_109 > F_153 ( V_2 ) )
V_30 -> V_109 -= V_275 ;
V_30 -> V_109 = F_9 ( V_30 -> V_109 , F_63 ( V_30 ) + 1 ) ;
V_30 -> V_70 = V_71 ;
}
}
static inline int F_155 ( const struct V_29 * V_30 )
{
return ! V_30 -> V_278 ||
( V_30 -> V_45 . V_279 && V_30 -> V_45 . V_83 &&
F_40 ( V_30 -> V_45 . V_83 , V_30 -> V_278 ) ) ;
}
static void F_156 ( struct V_1 * V_2 , const char * V_280 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_281 * V_282 = F_157 ( V_2 ) ;
if ( V_2 -> V_283 == V_284 ) {
F_74 ( L_2 ,
V_280 ,
& V_282 -> V_285 , F_158 ( V_282 -> V_286 ) ,
V_30 -> V_109 , F_159 ( V_30 ) ,
V_30 -> V_111 , V_30 -> V_121 ,
V_30 -> V_226 ) ;
}
#if F_160 ( V_287 )
else if ( V_2 -> V_283 == V_288 ) {
struct V_289 * V_290 = F_161 ( V_2 ) ;
F_74 ( L_3 ,
V_280 ,
& V_290 -> V_291 , F_158 ( V_282 -> V_286 ) ,
V_30 -> V_109 , F_159 ( V_30 ) ,
V_30 -> V_111 , V_30 -> V_121 ,
V_30 -> V_226 ) ;
}
#endif
}
static void F_162 ( struct V_1 * V_2 , const bool V_292 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_121 ) {
const struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_125 -> V_293 )
V_30 -> V_109 = V_6 -> V_125 -> V_293 ( V_2 ) ;
else
V_30 -> V_109 = F_31 ( V_30 -> V_109 , V_30 -> V_111 << 1 ) ;
if ( V_292 && V_30 -> V_121 > V_30 -> V_111 ) {
V_30 -> V_111 = V_30 -> V_121 ;
F_14 ( V_30 ) ;
}
} else {
V_30 -> V_109 = F_31 ( V_30 -> V_109 , V_30 -> V_111 ) ;
}
V_30 -> V_70 = V_71 ;
}
static inline int F_163 ( const struct V_29 * V_30 )
{
return V_30 -> V_124 && ( ! V_30 -> V_148 || F_155 ( V_30 ) ) ;
}
static bool F_164 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_163 ( V_30 ) ) {
int V_139 ;
F_156 ( V_2 , F_2 ( V_2 ) -> V_112 == V_233 ? L_4 : L_5 ) ;
F_162 ( V_2 , true ) ;
if ( F_2 ( V_2 ) -> V_112 == V_233 )
V_139 = V_294 ;
else
V_139 = V_295 ;
F_72 ( F_73 ( V_2 ) , V_139 ) ;
V_30 -> V_124 = 0 ;
}
if ( V_30 -> V_96 == V_30 -> V_128 && F_71 ( V_30 ) ) {
F_151 ( V_30 ) ;
return true ;
}
F_64 ( V_2 , V_113 ) ;
return false ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_124 && ! V_30 -> V_148 ) {
F_156 ( V_2 , L_6 ) ;
F_162 ( V_2 , true ) ;
V_30 -> V_124 = 0 ;
F_72 ( F_73 ( V_2 ) , V_296 ) ;
}
}
static bool F_166 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
if ( V_30 -> V_161 )
return true ;
V_4 = F_104 ( V_2 ) ;
if ( F_103 ( V_4 && F_16 ( V_4 ) -> V_152 & V_200 ) )
return true ;
return false ;
}
static int F_167 ( struct V_1 * V_2 , int V_236 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_297 = F_71 ( V_30 ) || ( F_138 ( V_30 ) > V_30 -> V_115 ) ;
if ( F_163 ( V_30 ) ) {
if ( ! F_166 ( V_2 ) )
V_30 -> V_278 = 0 ;
F_70 ( V_2 , F_138 ( V_30 ) + V_236 , 1 ) ;
F_156 ( V_2 , L_7 ) ;
F_162 ( V_2 , false ) ;
F_72 ( F_73 ( V_2 ) , V_298 ) ;
V_297 = 0 ;
}
return V_297 ;
}
static bool F_168 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_163 ( V_30 ) ) {
struct V_3 * V_4 ;
F_82 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
F_16 ( V_4 ) -> V_152 &= ~ V_153 ;
}
F_131 ( V_30 ) ;
F_156 ( V_2 , L_8 ) ;
V_30 -> V_150 = 0 ;
F_162 ( V_2 , true ) ;
F_72 ( F_73 ( V_2 ) , V_294 ) ;
F_2 ( V_2 ) -> V_242 = 0 ;
V_30 -> V_124 = 0 ;
if ( F_147 ( V_30 ) )
F_64 ( V_2 , V_113 ) ;
return true ;
}
return false ;
}
static inline void F_169 ( struct V_1 * V_2 )
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
F_129 ( V_2 , V_299 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_185 = V_113 ;
if ( F_159 ( V_30 ) || F_166 ( V_2 ) )
V_185 = V_241 ;
if ( F_2 ( V_2 ) -> V_112 != V_185 ) {
F_64 ( V_2 , V_185 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
}
}
static void F_171 ( struct V_1 * V_2 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_118 ( V_30 ) ;
if ( ! V_30 -> V_240 && ! F_166 ( V_2 ) )
V_30 -> V_278 = 0 ;
if ( V_191 & V_257 )
F_62 ( V_2 , 1 ) ;
if ( F_2 ( V_2 ) -> V_112 != V_123 ) {
F_170 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_112 != V_113 )
F_151 ( V_30 ) ;
} else {
F_154 ( V_2 , V_191 ) ;
}
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_238 . V_300 = V_6 -> V_238 . V_239 - 1 ;
V_6 -> V_238 . V_239 = 0 ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_30 -> V_121 = F_128 ( V_2 ) ;
V_30 -> V_109 = V_30 -> V_109 *
F_174 ( V_2 , V_30 -> V_301 ) /
V_6 -> V_238 . V_239 ;
V_30 -> V_127 = 0 ;
V_30 -> V_70 = V_71 ;
V_30 -> V_111 = F_128 ( V_2 ) ;
V_6 -> V_238 . V_302 = V_6 -> V_238 . V_239 ;
V_6 -> V_238 . V_239 = 0 ;
F_175 ( V_2 , V_6 -> V_303 ) ;
}
void F_176 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned int V_58 = F_177 ( V_2 ) ;
T_1 V_304 = V_30 -> V_150 ;
F_82 (skb, sk) {
if ( V_4 == F_83 ( V_2 ) )
break;
if ( F_97 ( V_4 ) > V_58 &&
! ( F_16 ( V_4 ) -> V_152 & V_154 ) ) {
if ( F_16 ( V_4 ) -> V_152 & V_165 ) {
F_16 ( V_4 ) -> V_152 &= ~ V_165 ;
V_30 -> V_161 -= F_77 ( V_4 ) ;
}
F_78 ( V_30 , V_4 ) ;
}
}
F_178 ( V_30 ) ;
if ( V_304 == V_30 -> V_150 )
return;
if ( F_71 ( V_30 ) )
F_119 ( V_30 ) ;
F_118 ( V_30 ) ;
if ( V_6 -> V_112 != V_233 ) {
V_30 -> V_128 = V_30 -> V_98 ;
V_30 -> V_111 = F_128 ( V_2 ) ;
V_30 -> V_121 = 0 ;
V_30 -> V_124 = 0 ;
F_64 ( V_2 , V_233 ) ;
}
F_179 ( V_2 ) ;
}
static void F_180 ( struct V_1 * V_2 , int V_305 ,
int V_269 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_306 = 0 ;
int V_307 = V_30 -> V_111 - F_63 ( V_30 ) ;
if ( F_63 ( V_30 ) > V_30 -> V_111 ) {
T_4 V_308 = ( T_4 ) V_30 -> V_111 * V_30 -> V_309 +
V_30 -> V_310 - 1 ;
V_306 = F_181 ( V_308 , V_30 -> V_310 ) - V_30 -> V_311 ;
} else {
V_306 = F_37 ( int , V_307 ,
F_27 ( int , V_30 -> V_309 - V_30 -> V_311 ,
V_305 ) + 1 ) ;
}
V_306 = F_31 ( V_306 , ( V_269 ? 1 : 0 ) ) ;
V_30 -> V_109 = F_63 ( V_30 ) + V_306 ;
}
static void F_182 ( struct V_1 * V_2 , bool V_312 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_139 ;
if ( F_71 ( V_30 ) )
V_139 = V_313 ;
else
V_139 = V_314 ;
F_72 ( F_73 ( V_2 ) , V_139 ) ;
V_30 -> V_128 = V_30 -> V_98 ;
V_30 -> V_121 = 0 ;
V_30 -> V_124 = V_30 -> V_96 ;
V_30 -> V_148 = V_30 -> V_161 ;
if ( F_2 ( V_2 ) -> V_112 < V_123 ) {
if ( ! V_312 )
V_30 -> V_121 = F_128 ( V_2 ) ;
V_30 -> V_111 = F_2 ( V_2 ) -> V_125 -> V_126 ( V_2 ) ;
F_12 ( V_30 ) ;
}
V_30 -> V_122 = 0 ;
V_30 -> V_127 = 0 ;
V_30 -> V_310 = V_30 -> V_109 ;
V_30 -> V_309 = 0 ;
V_30 -> V_311 = 0 ;
F_64 ( V_2 , V_163 ) ;
}
static void F_183 ( struct V_1 * V_2 , int V_315 ,
int V_305 , bool V_316 ,
int V_191 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_317 = V_316 || ( ( V_191 & V_193 ) &&
( F_138 ( V_30 ) > V_30 -> V_115 ) ) ;
int V_269 = 0 ;
if ( F_115 ( ! V_30 -> V_226 && V_30 -> V_147 ) )
V_30 -> V_147 = 0 ;
if ( F_115 ( ! V_30 -> V_147 && V_30 -> V_146 ) )
V_30 -> V_146 = 0 ;
if ( V_191 & V_257 )
V_30 -> V_121 = 0 ;
if ( F_135 ( V_2 , V_191 ) )
return;
F_118 ( V_30 ) ;
if ( V_6 -> V_112 == V_113 ) {
F_115 ( V_30 -> V_161 != 0 ) ;
V_30 -> V_278 = 0 ;
} else if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_128 ) ) {
switch ( V_6 -> V_112 ) {
case V_233 :
V_6 -> V_242 = 0 ;
if ( F_164 ( V_2 ) )
return;
break;
case V_123 :
if ( V_30 -> V_96 != V_30 -> V_128 ) {
F_169 ( V_2 ) ;
F_64 ( V_2 , V_113 ) ;
}
break;
case V_163 :
if ( F_71 ( V_30 ) )
F_123 ( V_30 ) ;
if ( F_164 ( V_2 ) )
return;
F_169 ( V_2 ) ;
break;
}
}
switch ( V_6 -> V_112 ) {
case V_163 :
if ( ! ( V_191 & V_318 ) ) {
if ( F_71 ( V_30 ) && V_316 )
F_121 ( V_2 ) ;
} else
V_317 = F_167 ( V_2 , V_315 ) ;
break;
case V_233 :
if ( V_191 & V_248 )
V_6 -> V_242 = 0 ;
if ( F_71 ( V_30 ) && V_191 & V_318 )
F_123 ( V_30 ) ;
if ( ! F_168 ( V_2 ) ) {
F_151 ( V_30 ) ;
F_179 ( V_2 ) ;
return;
}
if ( V_6 -> V_112 != V_113 )
return;
default:
if ( F_71 ( V_30 ) ) {
if ( V_191 & V_318 )
F_123 ( V_30 ) ;
if ( V_316 )
F_121 ( V_2 ) ;
}
if ( V_6 -> V_112 <= V_241 )
F_165 ( V_2 ) ;
if ( ! F_144 ( V_2 , V_191 ) ) {
F_171 ( V_2 , V_191 ) ;
return;
}
if ( V_6 -> V_112 < V_123 &&
V_6 -> V_238 . V_239 &&
V_30 -> V_96 == V_30 -> V_319 . V_320 ) {
F_172 ( V_2 ) ;
V_30 -> V_109 ++ ;
F_176 ( V_2 ) ;
return;
}
F_182 ( V_2 , ( V_191 & V_257 ) ) ;
V_269 = 1 ;
}
if ( V_317 || ( F_66 ( V_30 ) && F_143 ( V_2 ) ) )
F_150 ( V_2 , V_269 ) ;
V_30 -> V_309 += V_305 ;
F_180 ( V_2 , V_305 , V_269 , V_191 ) ;
F_179 ( V_2 ) ;
}
void F_184 ( struct V_1 * V_2 , T_1 V_321 )
{
F_46 ( V_2 , V_321 ) ;
F_49 ( V_2 ) ;
F_2 ( V_2 ) -> V_104 = 0 ;
}
static void F_185 ( struct V_1 * V_2 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_184 ( V_2 , V_71 - V_30 -> V_45 . V_83 ) ;
}
static void F_186 ( struct V_1 * V_2 , T_1 V_321 , int V_191 )
{
if ( V_191 & V_322 )
return;
F_184 ( V_2 , V_321 ) ;
}
static inline void F_187 ( struct V_1 * V_2 , const int V_191 ,
const T_5 V_321 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_30 -> V_45 . V_279 && V_30 -> V_45 . V_83 )
F_185 ( V_2 , V_191 ) ;
else if ( V_321 >= 0 )
F_186 ( V_2 , V_321 , V_191 ) ;
}
static void F_188 ( struct V_1 * V_2 , T_1 V_323 , T_1 V_324 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_125 -> V_325 ( V_2 , V_323 , V_324 ) ;
F_7 ( V_2 ) -> V_70 = V_71 ;
}
void F_189 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_226 ) {
F_190 ( V_2 , V_253 ) ;
} else {
T_1 V_326 = F_2 ( V_2 ) -> V_90 ;
if ( V_30 -> V_260 ) {
struct V_3 * V_4 = F_104 ( V_2 ) ;
const T_1 V_327 = F_16 ( V_4 ) -> V_261 + V_326 ;
T_5 V_307 = ( T_5 ) ( V_327 - V_71 ) ;
if ( V_307 > 0 )
V_326 = V_307 ;
}
F_137 ( V_2 , V_253 , V_326 ,
V_254 ) ;
}
V_30 -> V_260 = 0 ;
}
void F_191 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_189 ( V_2 ) ;
if ( ! V_30 -> V_264 )
return;
F_182 ( V_2 , false ) ;
F_150 ( V_2 , 1 ) ;
F_179 ( V_2 ) ;
}
static T_1 F_192 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_328 ;
F_92 ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_96 ) ) ;
V_328 = F_77 ( V_4 ) ;
if ( F_193 ( V_2 , V_4 , V_30 -> V_96 - F_16 ( V_4 ) -> V_82 ) )
return 0 ;
V_328 -= F_77 ( V_4 ) ;
if ( V_328 ) {
F_92 ( F_77 ( V_4 ) == 0 ) ;
F_92 ( ! F_40 ( F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) ;
}
return V_328 ;
}
static int F_194 ( struct V_1 * V_2 , int V_329 ,
T_1 V_171 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
T_1 V_88 = V_71 ;
int V_330 = true ;
int V_191 = 0 ;
T_1 V_315 = 0 ;
T_1 V_189 = V_30 -> V_226 ;
T_1 V_331 = V_30 -> V_147 ;
T_5 V_321 = - 1 ;
T_5 V_332 = - 1 ;
T_6 V_333 = F_195 () ;
while ( ( V_4 = F_104 ( V_2 ) ) && V_4 != F_83 ( V_2 ) ) {
struct V_334 * V_335 = F_16 ( V_4 ) ;
T_1 V_336 ;
T_3 V_152 = V_335 -> V_152 ;
if ( F_47 ( V_335 -> V_84 , V_30 -> V_96 ) ) {
if ( F_77 ( V_4 ) == 1 ||
! F_47 ( V_30 -> V_96 , V_335 -> V_82 ) )
break;
V_336 = F_192 ( V_2 , V_4 ) ;
if ( ! V_336 )
break;
V_330 = false ;
} else {
V_336 = F_77 ( V_4 ) ;
}
if ( V_152 & V_188 ) {
if ( V_152 & V_165 )
V_30 -> V_161 -= V_336 ;
V_191 |= V_322 ;
V_332 = - 1 ;
V_321 = - 1 ;
if ( ( V_191 & V_248 ) || ( V_336 > 1 ) )
V_191 |= V_337 ;
} else {
V_332 = V_88 - V_335 -> V_261 ;
V_333 = V_4 -> V_338 ;
if ( V_321 < 0 ) {
V_321 = V_332 ;
}
if ( ! ( V_152 & V_154 ) )
V_189 = F_9 ( V_315 , V_189 ) ;
}
if ( V_152 & V_154 )
V_30 -> V_147 -= V_336 ;
if ( V_152 & V_153 )
V_30 -> V_150 -= V_336 ;
V_30 -> V_226 -= V_336 ;
V_315 += V_336 ;
if ( ! ( V_335 -> V_203 & V_339 ) ) {
V_191 |= V_248 ;
} else {
V_191 |= V_340 ;
V_30 -> V_278 = 0 ;
}
if ( ! V_330 )
break;
F_95 ( V_4 , V_2 ) ;
F_96 ( V_2 , V_4 ) ;
V_30 -> V_202 = NULL ;
if ( V_4 == V_30 -> V_149 )
V_30 -> V_149 = NULL ;
if ( V_4 == V_30 -> V_129 )
V_30 -> V_129 = NULL ;
}
if ( F_196 ( F_197 ( V_30 -> V_341 , V_171 , V_30 -> V_96 ) ) )
V_30 -> V_341 = V_30 -> V_96 ;
if ( V_4 && ( F_16 ( V_4 ) -> V_152 & V_154 ) )
V_191 |= V_251 ;
if ( V_191 & V_342 ) {
const struct V_272 * V_273
= F_2 ( V_2 ) -> V_125 ;
if ( F_103 ( V_6 -> V_238 . V_239 &&
! F_47 ( V_30 -> V_319 . V_343 , V_30 -> V_96 ) ) ) {
F_173 ( V_2 ) ;
}
F_187 ( V_2 , V_191 , V_321 ) ;
F_189 ( V_2 ) ;
if ( F_71 ( V_30 ) ) {
F_122 ( V_2 , V_315 ) ;
} else {
int V_307 ;
if ( V_189 < V_329 )
F_70 ( V_2 , V_30 -> V_146 - V_189 , 0 ) ;
V_307 = F_66 ( V_30 ) ? V_315 :
V_331 - V_30 -> V_147 ;
V_30 -> V_194 -= F_9 ( V_30 -> V_194 , V_307 ) ;
}
V_30 -> V_146 -= F_9 ( V_315 , V_30 -> V_146 ) ;
if ( V_273 -> V_315 ) {
T_5 V_344 = - 1 ;
if ( ! ( V_191 & V_322 ) ) {
if ( V_273 -> V_102 & V_345 &&
! F_198 ( V_333 ,
F_195 () ) )
V_344 = F_199 ( F_200 () ,
V_333 ) ;
else if ( V_332 >= 0 )
V_344 = F_201 ( V_332 ) ;
}
V_273 -> V_315 ( V_2 , V_315 , V_344 ) ;
}
}
#if V_145 > 0
F_115 ( ( int ) V_30 -> V_147 < 0 ) ;
F_115 ( ( int ) V_30 -> V_150 < 0 ) ;
F_115 ( ( int ) V_30 -> V_161 < 0 ) ;
if ( ! V_30 -> V_226 && F_147 ( V_30 ) ) {
V_6 = F_2 ( V_2 ) ;
if ( V_30 -> V_150 ) {
F_74 ( L_9 ,
V_30 -> V_150 , V_6 -> V_112 ) ;
V_30 -> V_150 = 0 ;
}
if ( V_30 -> V_147 ) {
F_74 ( L_10 ,
V_30 -> V_147 , V_6 -> V_112 ) ;
V_30 -> V_147 = 0 ;
}
if ( V_30 -> V_161 ) {
F_74 ( L_11 ,
V_30 -> V_161 , V_6 -> V_112 ) ;
V_30 -> V_161 = 0 ;
}
}
#endif
return V_191 ;
}
static void F_202 ( struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_47 ( F_16 ( F_83 ( V_2 ) ) -> V_84 , F_203 ( V_30 ) ) ) {
V_6 -> V_104 = 0 ;
F_190 ( V_2 , V_346 ) ;
} else {
F_137 ( V_2 , V_346 ,
F_9 ( V_6 -> V_90 << V_6 -> V_104 , V_254 ) ,
V_254 ) ;
}
}
static inline int F_204 ( const struct V_1 * V_2 , const int V_191 )
{
return ! ( V_191 & V_277 ) || ( V_191 & V_347 ) ||
F_2 ( V_2 ) -> V_112 != V_113 ;
}
static inline int F_205 ( const struct V_1 * V_2 , const int V_191 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ( ! ( V_191 & V_257 ) || V_30 -> V_109 < V_30 -> V_111 ) &&
! ( ( 1 << F_2 ( V_2 ) -> V_112 ) & ( V_245 | V_348 ) ) ;
}
static inline int F_206 ( const struct V_29 * V_30 ,
const T_1 V_323 , const T_1 V_164 ,
const T_1 V_349 )
{
return F_47 ( V_323 , V_30 -> V_96 ) ||
F_47 ( V_164 , V_30 -> V_350 ) ||
( V_164 == V_30 -> V_350 && V_349 > V_30 -> V_351 ) ;
}
static int F_207 ( struct V_1 * V_2 , const struct V_3 * V_4 , T_1 V_323 ,
T_1 V_164 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_191 = 0 ;
T_1 V_349 = F_158 ( F_6 ( V_4 ) -> V_52 ) ;
if ( F_196 ( ! F_6 ( V_4 ) -> V_43 ) )
V_349 <<= V_30 -> V_45 . V_352 ;
if ( F_206 ( V_30 , V_323 , V_164 , V_349 ) ) {
V_191 |= V_353 ;
F_208 ( V_30 , V_164 ) ;
if ( V_30 -> V_351 != V_349 ) {
V_30 -> V_351 = V_349 ;
V_30 -> V_354 = 0 ;
F_209 ( V_2 ) ;
if ( V_349 > V_30 -> V_157 ) {
V_30 -> V_157 = V_349 ;
F_175 ( V_2 , F_2 ( V_2 ) -> V_303 ) ;
}
}
}
V_30 -> V_96 = V_323 ;
return V_191 ;
}
static void F_210 ( struct V_29 * V_30 )
{
V_30 -> V_109 = F_9 ( V_30 -> V_109 , V_30 -> V_111 ) ;
V_30 -> V_127 = 0 ;
V_30 -> V_122 = 0 ;
F_12 ( V_30 ) ;
F_151 ( V_30 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
F_62 ( V_2 , 0 ) ;
}
static void F_212 ( struct V_1 * V_2 , int V_191 )
{
if ( V_191 & V_257 )
F_211 ( V_2 ) ;
else
F_162 ( V_2 , true ) ;
}
static bool F_213 ( struct V_1 * V_2 , int V_191 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_118 ( V_30 ) ;
if ( V_191 & V_248 )
F_2 ( V_2 ) -> V_242 = 0 ;
if ( ( V_191 & V_337 ) ||
( ( V_30 -> V_240 >= 2 ) && ( V_191 & V_322 ) ) )
V_30 -> V_124 = 0 ;
if ( ! F_40 ( V_30 -> V_96 , V_30 -> V_190 ) ) {
F_130 ( V_2 , ( V_30 -> V_240 == 1 ? 2 : 3 ) , V_191 ) ;
return true ;
}
if ( ! F_124 ( V_30 ) ) {
if ( ! ( V_191 & V_276 ) && ( V_191 & V_277 ) )
return true ;
if ( ! ( V_191 & V_248 ) ) {
F_130 ( V_2 , ( V_30 -> V_240 == 1 ? 0 : 3 ) ,
V_191 ) ;
return true ;
}
} else {
if ( ! ( V_191 & V_248 ) && ( V_30 -> V_240 == 1 ) ) {
V_30 -> V_109 = F_9 ( V_30 -> V_109 ,
F_63 ( V_30 ) ) ;
return true ;
}
if ( ( V_30 -> V_240 >= 2 ) &&
( ! ( V_191 & V_355 ) ||
( ( V_191 & V_193 ) &&
! ( V_191 & V_192 ) ) ) ) {
if ( ! ( V_191 & V_355 ) &&
( V_191 & V_277 ) )
return true ;
F_130 ( V_2 , 3 , V_191 ) ;
return true ;
}
}
if ( V_30 -> V_240 == 1 ) {
V_30 -> V_109 = F_63 ( V_30 ) + 2 ;
V_30 -> V_240 = 2 ;
if ( ! F_145 ( V_2 ) )
F_130 ( V_2 , 2 , V_191 ) ;
return true ;
} else {
switch ( V_356 ) {
case 2 :
F_212 ( V_2 , V_191 ) ;
break;
case 1 :
F_210 ( V_30 ) ;
break;
default:
F_211 ( V_2 ) ;
break;
}
V_30 -> V_240 = 0 ;
V_30 -> V_124 = 0 ;
F_72 ( F_73 ( V_2 ) , V_357 ) ;
}
return false ;
}
static int F_214 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_191 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_171 = V_30 -> V_96 ;
T_1 V_164 = F_16 ( V_4 ) -> V_82 ;
T_1 V_323 = F_16 ( V_4 ) -> V_164 ;
bool V_316 = false ;
T_1 V_358 ;
T_1 V_329 ;
int V_359 ;
int V_331 = V_30 -> V_147 ;
int V_315 = 0 ;
int V_305 = 0 ;
bool V_360 = false ;
if ( F_40 ( V_323 , V_171 ) )
goto V_361;
if ( F_47 ( V_323 , V_30 -> V_98 ) )
goto V_362;
if ( V_30 -> V_260 )
F_189 ( V_2 ) ;
if ( F_47 ( V_323 , V_171 ) )
V_191 |= V_318 ;
if ( V_363 ) {
if ( V_6 -> V_112 < V_123 )
V_30 -> V_122 += V_323 - V_171 ;
else if ( V_6 -> V_112 == V_233 )
V_30 -> V_122 += F_9 ( V_323 - V_171 ,
V_30 -> V_301 ) ;
}
V_329 = V_30 -> V_146 ;
V_358 = F_63 ( V_30 ) ;
if ( ! ( V_191 & V_364 ) && F_47 ( V_323 , V_171 ) ) {
F_208 ( V_30 , V_164 ) ;
V_30 -> V_96 = V_323 ;
V_191 |= V_353 ;
F_129 ( V_2 , V_365 ) ;
F_72 ( F_73 ( V_2 ) , V_366 ) ;
} else {
if ( V_164 != F_16 ( V_4 ) -> V_84 )
V_191 |= V_367 ;
else
F_72 ( F_73 ( V_2 ) , V_368 ) ;
V_191 |= F_207 ( V_2 , V_4 , V_323 , V_164 ) ;
if ( F_16 ( V_4 ) -> V_152 )
V_191 |= F_114 ( V_2 , V_4 , V_171 ) ;
if ( F_19 ( V_30 , F_6 ( V_4 ) ) )
V_191 |= V_257 ;
F_129 ( V_2 , V_369 ) ;
}
V_2 -> V_370 = 0 ;
V_6 -> V_371 = 0 ;
V_30 -> V_372 = V_71 ;
V_359 = V_30 -> V_226 ;
if ( ! V_359 )
goto V_373;
V_191 |= F_194 ( V_2 , V_329 , V_171 ) ;
V_315 = V_359 - V_30 -> V_226 ;
V_305 = ( V_359 - V_331 ) -
( V_30 -> V_226 - V_30 -> V_147 ) ;
if ( V_30 -> V_240 )
V_360 = F_213 ( V_2 , V_191 ) ;
if ( F_40 ( V_30 -> V_190 , V_30 -> V_96 ) )
V_30 -> V_190 = 0 ;
if ( F_204 ( V_2 , V_191 ) ) {
if ( ( V_191 & V_248 ) && ! V_360 &&
F_205 ( V_2 , V_191 ) )
F_188 ( V_2 , V_323 , V_358 ) ;
V_316 = ! ( V_191 & ( V_318 | V_277 ) ) ;
F_183 ( V_2 , V_315 , V_305 ,
V_316 , V_191 ) ;
} else {
if ( ( V_191 & V_248 ) && ! V_360 )
F_188 ( V_2 , V_323 , V_358 ) ;
}
if ( ( V_191 & V_355 ) || ! ( V_191 & V_277 ) )
F_54 ( F_53 ( V_2 ) ) ;
return 1 ;
V_373:
if ( V_191 & V_227 )
F_183 ( V_2 , V_315 , V_305 ,
V_316 , V_191 ) ;
if ( F_83 ( V_2 ) )
F_202 ( V_2 ) ;
return 1 ;
V_362:
F_215 ( V_2 , L_12 , V_323 , V_30 -> V_96 , V_30 -> V_98 ) ;
return - 1 ;
V_361:
if ( F_16 ( V_4 ) -> V_152 ) {
V_191 |= F_114 ( V_2 , V_4 , V_171 ) ;
V_305 = V_30 -> V_147 - V_331 ;
F_183 ( V_2 , V_315 , V_305 ,
V_316 , V_191 ) ;
}
F_215 ( V_2 , L_13 , V_323 , V_30 -> V_96 , V_30 -> V_98 ) ;
return 0 ;
}
void F_216 ( const struct V_3 * V_4 , struct V_374 * V_375 ,
const T_3 * * V_376 , int V_377 )
{
const unsigned char * V_217 ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
int V_378 = ( V_41 -> V_379 * 4 ) - sizeof( struct V_15 ) ;
V_217 = ( const unsigned char * ) ( V_41 + 1 ) ;
V_375 -> V_279 = 0 ;
while ( V_378 > 0 ) {
int V_380 = * V_217 ++ ;
int V_381 ;
switch ( V_380 ) {
case V_382 :
return;
case V_383 :
V_378 -- ;
continue;
default:
V_381 = * V_217 ++ ;
if ( V_381 < 2 )
return;
if ( V_381 > V_378 )
return;
switch ( V_380 ) {
case V_384 :
if ( V_381 == V_385 && V_41 -> V_43 && ! V_377 ) {
T_7 V_386 = F_217 ( V_217 ) ;
if ( V_386 ) {
if ( V_375 -> V_387 &&
V_375 -> V_387 < V_386 )
V_386 = V_375 -> V_387 ;
V_375 -> V_46 = V_386 ;
}
}
break;
case V_388 :
if ( V_381 == V_389 && V_41 -> V_43 &&
! V_377 && V_390 ) {
T_8 V_352 = * ( T_8 * ) V_217 ;
V_375 -> V_391 = 1 ;
if ( V_352 > 14 ) {
F_218 ( L_14 ,
V_392 ,
V_352 ) ;
V_352 = 14 ;
}
V_375 -> V_352 = V_352 ;
}
break;
case V_393 :
if ( ( V_381 == V_394 ) &&
( ( V_377 && V_375 -> V_395 ) ||
( ! V_377 && V_396 ) ) ) {
V_375 -> V_279 = 1 ;
V_375 -> V_397 = F_85 ( V_217 ) ;
V_375 -> V_83 = F_85 ( V_217 + 4 ) ;
}
break;
case V_398 :
if ( V_381 == V_399 && V_41 -> V_43 &&
! V_377 && V_400 ) {
V_375 -> V_130 = V_401 ;
F_219 ( V_375 ) ;
}
break;
case V_402 :
if ( ( V_381 >= ( V_220 + V_403 ) ) &&
! ( ( V_381 - V_220 ) % V_403 ) &&
V_375 -> V_130 ) {
F_16 ( V_4 ) -> V_152 = ( V_217 - 2 ) - ( unsigned char * ) V_41 ;
}
break;
#ifdef F_220
case V_404 :
break;
#endif
case V_405 :
switch ( V_381 ) {
case V_406 :
break;
case V_407 :
break;
case V_408 + 0 :
case V_408 + 2 :
case V_408 + 4 :
case V_408 + 6 :
case V_409 :
V_375 -> V_410 = V_381 ;
* V_376 = V_217 ;
break;
default:
break;
}
break;
}
V_217 += V_381 - 2 ;
V_378 -= V_381 ;
}
}
}
static bool F_221 ( struct V_29 * V_30 , const struct V_15 * V_41 )
{
const T_9 * V_217 = ( const T_9 * ) ( V_41 + 1 ) ;
if ( * V_217 == F_222 ( ( V_383 << 24 ) | ( V_383 << 16 )
| ( V_393 << 8 ) | V_394 ) ) {
V_30 -> V_45 . V_279 = 1 ;
++ V_217 ;
V_30 -> V_45 . V_397 = F_223 ( * V_217 ) ;
++ V_217 ;
V_30 -> V_45 . V_83 = F_223 ( * V_217 ) ;
return true ;
}
return false ;
}
static bool F_224 ( const struct V_3 * V_4 ,
const struct V_15 * V_41 ,
struct V_29 * V_30 , const T_3 * * V_376 )
{
if ( V_41 -> V_379 == ( sizeof( * V_41 ) / 4 ) ) {
V_30 -> V_45 . V_279 = 0 ;
return false ;
} else if ( V_30 -> V_45 . V_395 &&
V_41 -> V_379 == ( ( sizeof( * V_41 ) + V_411 ) / 4 ) ) {
if ( F_221 ( V_30 , V_41 ) )
return true ;
}
F_216 ( V_4 , & V_30 -> V_45 , V_376 , 1 ) ;
return true ;
}
const T_3 * F_225 ( const struct V_15 * V_41 )
{
int V_378 = ( V_41 -> V_379 << 2 ) - sizeof( * V_41 ) ;
const T_3 * V_217 = ( const T_3 * ) ( V_41 + 1 ) ;
if ( V_378 < V_412 )
return NULL ;
while ( V_378 > 0 ) {
int V_380 = * V_217 ++ ;
int V_381 ;
switch( V_380 ) {
case V_382 :
return NULL ;
case V_383 :
V_378 -- ;
continue;
default:
V_381 = * V_217 ++ ;
if ( V_381 < 2 || V_381 > V_378 )
return NULL ;
if ( V_380 == V_404 )
return V_381 == V_412 ? V_217 : NULL ;
}
V_217 += V_381 - 2 ;
V_378 -= V_381 ;
}
return NULL ;
}
static inline void F_226 ( struct V_29 * V_30 )
{
V_30 -> V_45 . V_413 = V_30 -> V_45 . V_397 ;
V_30 -> V_45 . V_414 = F_227 () ;
}
static inline void F_228 ( struct V_29 * V_30 , T_1 V_82 )
{
if ( V_30 -> V_45 . V_279 && ! F_47 ( V_82 , V_30 -> V_415 ) ) {
if ( F_229 ( & V_30 -> V_45 , 0 ) )
F_226 ( V_30 ) ;
}
}
static int F_230 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
const struct V_15 * V_41 = F_6 ( V_4 ) ;
T_1 V_82 = F_16 ( V_4 ) -> V_82 ;
T_1 V_323 = F_16 ( V_4 ) -> V_164 ;
return (
( V_41 -> V_323 && V_82 == F_16 ( V_4 ) -> V_84 && V_82 == V_30 -> V_81 ) &&
V_323 == V_30 -> V_96 &&
! F_206 ( V_30 , V_323 , V_82 , F_158 ( V_41 -> V_52 ) << V_30 -> V_45 . V_352 ) &&
( T_5 ) ( V_30 -> V_45 . V_413 - V_30 -> V_45 . V_397 ) <= ( F_2 ( V_2 ) -> V_90 * 1024 ) / V_416 ) ;
}
static inline int F_231 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
return ! F_229 ( & V_30 -> V_45 , V_417 ) &&
! F_230 ( V_2 , V_4 ) ;
}
static inline int F_232 ( const struct V_29 * V_30 , T_1 V_82 , T_1 V_84 )
{
return ! F_40 ( V_84 , V_30 -> V_415 ) &&
! F_47 ( V_82 , V_30 -> V_81 + F_233 ( V_30 ) ) ;
}
static void F_234 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_418 ) {
case V_419 :
V_2 -> V_420 = V_421 ;
break;
case V_422 :
V_2 -> V_420 = V_423 ;
break;
case V_424 :
return;
default:
V_2 -> V_420 = V_425 ;
}
F_235 () ;
if ( ! F_236 ( V_2 , V_426 ) )
V_2 -> V_427 ( V_2 ) ;
F_237 ( V_2 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_428 |= V_429 ;
F_239 ( V_2 , V_430 ) ;
switch ( V_2 -> V_418 ) {
case V_431 :
case V_432 :
F_240 ( V_2 , V_422 ) ;
F_2 ( V_2 ) -> V_8 . V_26 = 1 ;
break;
case V_422 :
case V_433 :
break;
case V_434 :
break;
case V_435 :
F_241 ( V_2 ) ;
F_240 ( V_2 , V_433 ) ;
break;
case V_436 :
F_241 ( V_2 ) ;
F_242 ( V_2 , V_437 , 0 ) ;
break;
default:
F_243 ( L_15 ,
V_392 , V_2 -> V_418 ) ;
break;
}
F_244 ( & V_30 -> V_438 ) ;
if ( F_147 ( V_30 ) )
F_219 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
if ( ! F_236 ( V_2 , V_426 ) ) {
V_2 -> V_439 ( V_2 ) ;
if ( V_2 -> V_428 == V_440 ||
V_2 -> V_418 == V_424 )
F_245 ( V_2 , V_441 , V_442 ) ;
else
F_245 ( V_2 , V_441 , V_443 ) ;
}
}
static inline bool F_246 ( struct V_210 * V_169 , T_1 V_82 ,
T_1 V_84 )
{
if ( ! F_47 ( V_82 , V_169 -> V_84 ) && ! F_47 ( V_169 -> V_156 , V_84 ) ) {
if ( F_40 ( V_82 , V_169 -> V_156 ) )
V_169 -> V_156 = V_82 ;
if ( F_47 ( V_84 , V_169 -> V_84 ) )
V_169 -> V_84 = V_84 ;
return true ;
}
return false ;
}
static void F_247 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_147 ( V_30 ) && V_444 ) {
int V_139 ;
if ( F_40 ( V_82 , V_30 -> V_81 ) )
V_139 = V_445 ;
else
V_139 = V_446 ;
F_72 ( F_73 ( V_2 ) , V_139 ) ;
V_30 -> V_45 . V_447 = 1 ;
V_30 -> V_448 [ 0 ] . V_156 = V_82 ;
V_30 -> V_448 [ 0 ] . V_84 = V_84 ;
}
}
static void F_248 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ! V_30 -> V_45 . V_447 )
F_247 ( V_2 , V_82 , V_84 ) ;
else
F_246 ( V_30 -> V_448 , V_82 , V_84 ) ;
}
static void F_249 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_72 ( F_73 ( V_2 ) , V_449 ) ;
F_10 ( V_2 ) ;
if ( F_147 ( V_30 ) && V_444 ) {
T_1 V_84 = F_16 ( V_4 ) -> V_84 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) )
V_84 = V_30 -> V_81 ;
F_247 ( V_2 , F_16 ( V_4 ) -> V_82 , V_84 ) ;
}
}
F_241 ( V_2 ) ;
}
static void F_250 ( struct V_29 * V_30 )
{
int V_450 ;
struct V_210 * V_169 = & V_30 -> V_451 [ 0 ] ;
struct V_210 * V_452 = V_169 + 1 ;
for ( V_450 = 1 ; V_450 < V_30 -> V_45 . V_170 ; ) {
if ( F_246 ( V_169 , V_452 -> V_156 , V_452 -> V_84 ) ) {
int V_223 ;
V_30 -> V_45 . V_170 -- ;
for ( V_223 = V_450 ; V_223 < V_30 -> V_45 . V_170 ; V_223 ++ )
V_169 [ V_223 ] = V_169 [ V_223 + 1 ] ;
continue;
}
V_450 ++ , V_452 ++ ;
}
}
static void F_251 ( struct V_1 * V_2 , T_1 V_82 , T_1 V_84 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_210 * V_169 = & V_30 -> V_451 [ 0 ] ;
int V_453 = V_30 -> V_45 . V_170 ;
int V_450 ;
if ( ! V_453 )
goto V_454;
for ( V_450 = 0 ; V_450 < V_453 ; V_450 ++ , V_169 ++ ) {
if ( F_246 ( V_169 , V_82 , V_84 ) ) {
for (; V_450 > 0 ; V_450 -- , V_169 -- )
F_117 ( * V_169 , * ( V_169 - 1 ) ) ;
if ( V_453 > 1 )
F_250 ( V_30 ) ;
return;
}
}
if ( V_450 >= V_219 ) {
V_450 -- ;
V_30 -> V_45 . V_170 -- ;
V_169 -- ;
}
for (; V_450 > 0 ; V_450 -- , V_169 -- )
* V_169 = * ( V_169 - 1 ) ;
V_454:
V_169 -> V_156 = V_82 ;
V_169 -> V_84 = V_84 ;
V_30 -> V_45 . V_170 ++ ;
}
static void F_252 ( struct V_29 * V_30 )
{
struct V_210 * V_169 = & V_30 -> V_451 [ 0 ] ;
int V_170 = V_30 -> V_45 . V_170 ;
int V_450 ;
if ( F_253 ( & V_30 -> V_438 ) ) {
V_30 -> V_45 . V_170 = 0 ;
return;
}
for ( V_450 = 0 ; V_450 < V_170 ; ) {
if ( ! F_40 ( V_30 -> V_81 , V_169 -> V_156 ) ) {
int V_223 ;
F_115 ( F_40 ( V_30 -> V_81 , V_169 -> V_84 ) ) ;
for ( V_223 = V_450 + 1 ; V_223 < V_170 ; V_223 ++ )
V_30 -> V_451 [ V_223 - 1 ] = V_30 -> V_451 [ V_223 ] ;
V_170 -- ;
continue;
}
V_450 ++ ;
V_169 ++ ;
}
V_30 -> V_45 . V_170 = V_170 ;
}
static void F_254 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_2 V_455 = V_30 -> V_81 ;
struct V_3 * V_4 ;
while ( ( V_4 = F_255 ( & V_30 -> V_438 ) ) != NULL ) {
if ( F_47 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_455 ) ) {
T_2 V_447 = V_455 ;
if ( F_40 ( F_16 ( V_4 ) -> V_84 , V_455 ) )
V_455 = F_16 ( V_4 ) -> V_84 ;
F_248 ( V_2 , F_16 ( V_4 ) -> V_82 , V_447 ) ;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_215 ( V_2 , L_16 ) ;
F_256 ( V_4 , & V_30 -> V_438 ) ;
F_257 ( V_4 ) ;
continue;
}
F_215 ( V_2 , L_17 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_256 ( V_4 , & V_30 -> V_438 ) ;
F_258 ( & V_2 -> V_456 , V_4 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( F_6 ( V_4 ) -> V_457 )
F_238 ( V_2 ) ;
}
}
static int F_259 ( struct V_1 * V_2 , unsigned int V_458 )
{
if ( F_35 ( & V_2 -> V_72 ) > V_2 -> V_62 ||
! F_260 ( V_2 , V_458 ) ) {
if ( F_261 ( V_2 ) < 0 )
return - 1 ;
if ( ! F_260 ( V_2 , V_458 ) ) {
if ( ! F_262 ( V_2 ) )
return - 1 ;
if ( ! F_260 ( V_2 , V_458 ) )
return - 1 ;
}
}
return 0 ;
}
static bool F_263 ( struct V_1 * V_2 ,
struct V_3 * V_459 ,
struct V_3 * V_460 ,
bool * V_461 )
{
int V_307 ;
* V_461 = false ;
if ( F_6 ( V_460 ) -> V_457 )
return false ;
if ( F_16 ( V_460 ) -> V_82 != F_16 ( V_459 ) -> V_84 )
return false ;
if ( ! F_264 ( V_459 , V_460 , V_461 , & V_307 ) )
return false ;
F_265 ( V_307 , & V_2 -> V_72 ) ;
F_266 ( V_2 , V_307 ) ;
F_72 ( F_73 ( V_2 ) , V_462 ) ;
F_16 ( V_459 ) -> V_84 = F_16 ( V_460 ) -> V_84 ;
F_16 ( V_459 ) -> V_164 = F_16 ( V_460 ) -> V_164 ;
return true ;
}
static void F_267 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_463 ;
T_1 V_82 , V_84 ;
F_15 ( V_30 , V_4 ) ;
if ( F_259 ( V_2 , V_4 -> V_51 ) ) {
F_257 ( V_4 ) ;
return;
}
V_30 -> V_354 = 0 ;
F_44 ( V_2 ) ;
F_215 ( V_2 , L_18 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_463 = F_268 ( & V_30 -> V_438 ) ;
if ( ! V_463 ) {
if ( F_147 ( V_30 ) ) {
V_30 -> V_45 . V_170 = 1 ;
V_30 -> V_451 [ 0 ] . V_156 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_451 [ 0 ] . V_84 =
F_16 ( V_4 ) -> V_84 ;
}
F_269 ( & V_30 -> V_438 , V_4 ) ;
goto V_464;
}
V_82 = F_16 ( V_4 ) -> V_82 ;
V_84 = F_16 ( V_4 ) -> V_84 ;
if ( V_82 == F_16 ( V_463 ) -> V_84 ) {
bool V_461 ;
if ( ! F_263 ( V_2 , V_463 , V_4 , & V_461 ) ) {
F_270 ( & V_30 -> V_438 , V_463 , V_4 ) ;
} else {
F_271 ( V_4 , V_461 ) ;
V_4 = NULL ;
}
if ( ! V_30 -> V_45 . V_170 ||
V_30 -> V_451 [ 0 ] . V_84 != V_82 )
goto V_465;
V_30 -> V_451 [ 0 ] . V_84 = V_84 ;
goto V_464;
}
while ( 1 ) {
if ( ! F_47 ( F_16 ( V_463 ) -> V_82 , V_82 ) )
break;
if ( F_272 ( & V_30 -> V_438 , V_463 ) ) {
V_463 = NULL ;
break;
}
V_463 = F_273 ( & V_30 -> V_438 , V_463 ) ;
}
if ( V_463 && F_40 ( V_82 , F_16 ( V_463 ) -> V_84 ) ) {
if ( ! F_47 ( V_84 , F_16 ( V_463 ) -> V_84 ) ) {
F_257 ( V_4 ) ;
V_4 = NULL ;
F_247 ( V_2 , V_82 , V_84 ) ;
goto V_465;
}
if ( F_47 ( V_82 , F_16 ( V_463 ) -> V_82 ) ) {
F_247 ( V_2 , V_82 ,
F_16 ( V_463 ) -> V_84 ) ;
} else {
if ( F_272 ( & V_30 -> V_438 ,
V_463 ) )
V_463 = NULL ;
else
V_463 = F_273 (
& V_30 -> V_438 ,
V_463 ) ;
}
}
if ( ! V_463 )
F_269 ( & V_30 -> V_438 , V_4 ) ;
else
F_270 ( & V_30 -> V_438 , V_463 , V_4 ) ;
while ( ! F_274 ( & V_30 -> V_438 , V_4 ) ) {
V_463 = F_275 ( & V_30 -> V_438 , V_4 ) ;
if ( ! F_47 ( V_84 , F_16 ( V_463 ) -> V_82 ) )
break;
if ( F_40 ( V_84 , F_16 ( V_463 ) -> V_84 ) ) {
F_248 ( V_2 , F_16 ( V_463 ) -> V_82 ,
V_84 ) ;
break;
}
F_256 ( V_463 , & V_30 -> V_438 ) ;
F_248 ( V_2 , F_16 ( V_463 ) -> V_82 ,
F_16 ( V_463 ) -> V_84 ) ;
F_257 ( V_463 ) ;
}
V_465:
if ( F_147 ( V_30 ) )
F_251 ( V_2 , V_82 , V_84 ) ;
V_464:
if ( V_4 )
F_276 ( V_4 , V_2 ) ;
}
static int T_10 F_277 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_466 ,
bool * V_461 )
{
int V_467 ;
struct V_3 * V_468 = F_268 ( & V_2 -> V_456 ) ;
F_278 ( V_4 , V_466 ) ;
V_467 = ( V_468 &&
F_263 ( V_2 , V_468 , V_4 , V_461 ) ) ? 1 : 0 ;
F_7 ( V_2 ) -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( ! V_467 ) {
F_258 ( & V_2 -> V_456 , V_4 ) ;
F_276 ( V_4 , V_2 ) ;
}
return V_467 ;
}
int F_279 ( struct V_1 * V_2 , struct V_469 * V_280 , T_11 V_458 )
{
struct V_3 * V_4 ;
struct V_15 * V_41 ;
bool V_461 ;
if ( F_259 ( V_2 , V_458 + sizeof( * V_41 ) ) )
goto V_179;
V_4 = F_280 ( V_458 + sizeof( * V_41 ) , V_2 -> V_470 ) ;
if ( ! V_4 )
goto V_179;
V_41 = (struct V_15 * ) F_281 ( V_4 , sizeof( * V_41 ) ) ;
F_282 ( V_4 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( F_283 ( F_281 ( V_4 , V_458 ) , V_280 -> V_471 , V_458 ) )
goto V_472;
F_16 ( V_4 ) -> V_82 = F_7 ( V_2 ) -> V_81 ;
F_16 ( V_4 ) -> V_84 = F_16 ( V_4 ) -> V_82 + V_458 ;
F_16 ( V_4 ) -> V_164 = F_7 ( V_2 ) -> V_96 - 1 ;
if ( F_277 ( V_2 , V_4 , sizeof( * V_41 ) , & V_461 ) ) {
F_284 ( V_461 ) ;
F_257 ( V_4 ) ;
}
return V_458 ;
V_472:
F_285 ( V_4 ) ;
V_179:
return - V_473 ;
}
static void F_286 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_15 * V_41 = F_6 ( V_4 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_467 = - 1 ;
bool V_461 = false ;
if ( F_16 ( V_4 ) -> V_82 == F_16 ( V_4 ) -> V_84 )
goto V_474;
F_287 ( V_4 ) ;
F_278 ( V_4 , V_41 -> V_379 * 4 ) ;
F_13 ( V_30 , V_4 ) ;
V_30 -> V_45 . V_447 = 0 ;
if ( F_16 ( V_4 ) -> V_82 == V_30 -> V_81 ) {
if ( F_233 ( V_30 ) == 0 )
goto V_475;
if ( V_30 -> V_476 . V_477 == V_478 &&
V_30 -> V_85 == V_30 -> V_81 && V_30 -> V_476 . V_10 &&
F_288 ( V_2 ) && ! V_30 -> V_479 ) {
int V_480 = F_37 (unsigned int, skb->len,
tp->ucopy.len) ;
F_289 ( V_481 ) ;
F_290 () ;
if ( ! F_291 ( V_4 , 0 , V_30 -> V_476 . V_482 , V_480 ) ) {
V_30 -> V_476 . V_10 -= V_480 ;
V_30 -> V_85 += V_480 ;
V_467 = ( V_480 == V_4 -> V_10 ) ;
F_42 ( V_2 ) ;
}
F_292 () ;
}
if ( V_467 <= 0 ) {
V_483:
if ( V_467 < 0 &&
F_259 ( V_2 , V_4 -> V_51 ) )
goto V_474;
V_467 = F_277 ( V_2 , V_4 , 0 , & V_461 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
if ( V_4 -> V_10 )
F_43 ( V_2 , V_4 ) ;
if ( V_41 -> V_457 )
F_238 ( V_2 ) ;
if ( ! F_253 ( & V_30 -> V_438 ) ) {
F_254 ( V_2 ) ;
if ( F_253 ( & V_30 -> V_438 ) )
F_2 ( V_2 ) -> V_8 . V_26 = 0 ;
}
if ( V_30 -> V_45 . V_170 )
F_252 ( V_30 ) ;
F_209 ( V_2 ) ;
if ( V_467 > 0 )
F_271 ( V_4 , V_461 ) ;
else if ( ! F_236 ( V_2 , V_426 ) )
V_2 -> V_484 ( V_2 , 0 ) ;
return;
}
if ( ! F_47 ( F_16 ( V_4 ) -> V_84 , V_30 -> V_81 ) ) {
F_72 ( F_73 ( V_2 ) , V_449 ) ;
F_247 ( V_2 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ;
V_475:
F_10 ( V_2 ) ;
F_44 ( V_2 ) ;
V_474:
F_257 ( V_4 ) ;
return;
}
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 + F_233 ( V_30 ) ) )
goto V_475;
F_10 ( V_2 ) ;
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
F_215 ( V_2 , L_19 ,
V_30 -> V_81 , F_16 ( V_4 ) -> V_82 ,
F_16 ( V_4 ) -> V_84 ) ;
F_247 ( V_2 , F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ;
if ( ! F_233 ( V_30 ) )
goto V_475;
goto V_483;
}
F_267 ( V_2 , V_4 ) ;
}
static struct V_3 * F_293 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_485 * V_486 )
{
struct V_3 * V_487 = NULL ;
if ( ! F_274 ( V_486 , V_4 ) )
V_487 = F_275 ( V_486 , V_4 ) ;
F_256 ( V_4 , V_486 ) ;
F_257 ( V_4 ) ;
F_72 ( F_73 ( V_2 ) , V_488 ) ;
return V_487 ;
}
static void
F_294 ( struct V_1 * V_2 , struct V_485 * V_486 ,
struct V_3 * V_489 , struct V_3 * V_468 ,
T_1 V_490 , T_1 V_464 )
{
struct V_3 * V_4 , * V_491 ;
bool V_492 ;
V_4 = V_489 ;
V_493:
V_492 = true ;
F_295 (list, skb, n) {
if ( V_4 == V_468 )
break;
if ( ! F_40 ( V_490 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_293 ( V_2 , V_4 , V_486 ) ;
if ( ! V_4 )
break;
goto V_493;
}
if ( ! F_6 ( V_4 ) -> V_43 && ! F_6 ( V_4 ) -> V_457 &&
( F_23 ( V_4 -> V_51 ) > V_4 -> V_10 ||
F_40 ( F_16 ( V_4 ) -> V_82 , V_490 ) ) ) {
V_492 = false ;
break;
}
if ( ! F_274 ( V_486 , V_4 ) ) {
struct V_3 * V_487 = F_275 ( V_486 , V_4 ) ;
if ( V_487 != V_468 &&
F_16 ( V_4 ) -> V_84 != F_16 ( V_487 ) -> V_82 ) {
V_492 = false ;
break;
}
}
V_490 = F_16 ( V_4 ) -> V_84 ;
}
if ( V_492 || F_6 ( V_4 ) -> V_43 || F_6 ( V_4 ) -> V_457 )
return;
while ( F_40 ( V_490 , V_464 ) ) {
struct V_3 * V_494 ;
unsigned int V_495 = F_296 ( V_4 ) ;
int V_496 = F_297 ( V_495 , 0 ) ;
if ( V_496 < 0 )
return;
if ( V_464 - V_490 < V_496 )
V_496 = V_464 - V_490 ;
V_494 = F_280 ( V_496 + V_495 , V_497 ) ;
if ( ! V_494 )
return;
F_298 ( V_494 , F_299 ( V_4 ) - V_4 -> V_489 ) ;
F_300 ( V_494 , ( F_301 ( V_4 ) -
V_4 -> V_489 ) ) ;
F_302 ( V_494 , ( F_4 ( V_4 ) -
V_4 -> V_489 ) ) ;
F_303 ( V_494 , V_495 ) ;
memcpy ( V_494 -> V_489 , V_4 -> V_489 , V_495 ) ;
memcpy ( V_494 -> V_498 , V_4 -> V_498 , sizeof( V_4 -> V_498 ) ) ;
F_16 ( V_494 ) -> V_82 = F_16 ( V_494 ) -> V_84 = V_490 ;
F_304 ( V_486 , V_4 , V_494 ) ;
F_276 ( V_494 , V_2 ) ;
while ( V_496 > 0 ) {
int V_499 = V_490 - F_16 ( V_4 ) -> V_82 ;
int V_458 = F_16 ( V_4 ) -> V_84 - V_490 ;
F_92 ( V_499 < 0 ) ;
if ( V_458 > 0 ) {
V_458 = F_9 ( V_496 , V_458 ) ;
if ( F_305 ( V_4 , V_499 , F_281 ( V_494 , V_458 ) , V_458 ) )
F_306 () ;
F_16 ( V_494 ) -> V_84 += V_458 ;
V_496 -= V_458 ;
V_490 += V_458 ;
}
if ( ! F_40 ( V_490 , F_16 ( V_4 ) -> V_84 ) ) {
V_4 = F_293 ( V_2 , V_4 , V_486 ) ;
if ( ! V_4 ||
V_4 == V_468 ||
F_6 ( V_4 ) -> V_43 ||
F_6 ( V_4 ) -> V_457 )
return;
}
}
}
}
static void F_307 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_255 ( & V_30 -> V_438 ) ;
struct V_3 * V_489 ;
T_1 V_490 , V_464 ;
if ( V_4 == NULL )
return;
V_490 = F_16 ( V_4 ) -> V_82 ;
V_464 = F_16 ( V_4 ) -> V_84 ;
V_489 = V_4 ;
for (; ; ) {
struct V_3 * V_487 = NULL ;
if ( ! F_274 ( & V_30 -> V_438 , V_4 ) )
V_487 = F_275 ( & V_30 -> V_438 , V_4 ) ;
V_4 = V_487 ;
if ( ! V_4 ||
F_47 ( F_16 ( V_4 ) -> V_82 , V_464 ) ||
F_40 ( F_16 ( V_4 ) -> V_84 , V_490 ) ) {
F_294 ( V_2 , & V_30 -> V_438 ,
V_489 , V_4 , V_490 , V_464 ) ;
V_489 = V_4 ;
if ( ! V_4 )
break;
V_490 = F_16 ( V_4 ) -> V_82 ;
V_464 = F_16 ( V_4 ) -> V_84 ;
} else {
if ( F_40 ( F_16 ( V_4 ) -> V_82 , V_490 ) )
V_490 = F_16 ( V_4 ) -> V_82 ;
if ( F_47 ( F_16 ( V_4 ) -> V_84 , V_464 ) )
V_464 = F_16 ( V_4 ) -> V_84 ;
}
}
}
static bool F_262 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
bool V_500 = false ;
if ( ! F_253 ( & V_30 -> V_438 ) ) {
F_72 ( F_73 ( V_2 ) , V_501 ) ;
F_244 ( & V_30 -> V_438 ) ;
if ( V_30 -> V_45 . V_130 )
F_219 ( & V_30 -> V_45 ) ;
F_45 ( V_2 ) ;
V_500 = true ;
}
return V_500 ;
}
static int F_261 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
F_215 ( V_2 , L_20 , V_30 -> V_85 ) ;
F_72 ( F_73 ( V_2 ) , V_502 ) ;
if ( F_35 ( & V_2 -> V_72 ) >= V_2 -> V_62 )
F_32 ( V_2 ) ;
else if ( F_26 ( V_2 ) )
V_30 -> V_54 = F_9 ( V_30 -> V_54 , 4U * V_30 -> V_57 ) ;
F_307 ( V_2 ) ;
if ( ! F_253 ( & V_2 -> V_456 ) )
F_294 ( V_2 , & V_2 -> V_456 ,
F_255 ( & V_2 -> V_456 ) ,
NULL ,
V_30 -> V_85 , V_30 -> V_81 ) ;
F_45 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_262 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_72 ) <= V_2 -> V_62 )
return 0 ;
F_72 ( F_73 ( V_2 ) , V_503 ) ;
V_30 -> V_354 = 0 ;
return - 1 ;
}
void F_308 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_2 ( V_2 ) -> V_112 == V_113 &&
V_2 -> V_504 && ! F_309 ( V_505 , & V_2 -> V_504 -> V_102 ) ) {
T_1 V_506 = F_61 ( V_30 , F_53 ( V_2 ) ) ;
T_1 V_507 = F_31 ( V_30 -> V_508 , V_506 ) ;
if ( V_507 < V_30 -> V_109 ) {
V_30 -> V_111 = F_128 ( V_2 ) ;
V_30 -> V_109 = ( V_30 -> V_109 + V_507 ) >> 1 ;
}
V_30 -> V_508 = 0 ;
}
V_30 -> V_70 = V_71 ;
}
static bool F_310 ( const struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_2 -> V_64 & V_66 )
return false ;
if ( F_26 ( V_2 ) )
return false ;
if ( F_33 ( V_2 ) >= F_34 ( V_2 , 0 ) )
return false ;
if ( V_30 -> V_226 >= V_30 -> V_109 )
return false ;
return true ;
}
static void F_311 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_310 ( V_2 ) ) {
int V_44 = F_21 ( F_27 ( T_1 ,
V_30 -> V_45 . V_46 ,
V_30 -> V_301 ) +
V_47 ) ;
int V_509 = F_27 (unsigned int, tp->snd_cwnd,
tp->reordering + 1 ) ;
V_44 *= 2 * V_509 ;
if ( V_44 > V_2 -> V_49 )
V_2 -> V_49 = F_9 ( V_44 , V_50 [ 2 ] ) ;
V_30 -> V_70 = V_71 ;
}
V_2 -> V_510 ( V_2 ) ;
}
static void F_312 ( struct V_1 * V_2 )
{
if ( F_236 ( V_2 , V_511 ) ) {
F_313 ( V_2 , V_511 ) ;
if ( V_2 -> V_504 &&
F_309 ( V_505 , & V_2 -> V_504 -> V_102 ) )
F_311 ( V_2 ) ;
}
}
static inline void F_314 ( struct V_1 * V_2 )
{
F_315 ( V_2 ) ;
F_312 ( V_2 ) ;
}
static void F_316 ( struct V_1 * V_2 , int V_512 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( ( ( V_30 -> V_81 - V_30 -> V_415 ) > F_2 ( V_2 ) -> V_8 . V_12 &&
F_317 ( V_2 ) >= V_30 -> V_23 ) ||
F_11 ( V_2 ) ||
( V_512 && F_255 ( & V_30 -> V_438 ) ) ) {
F_241 ( V_2 ) ;
} else {
F_318 ( V_2 ) ;
}
}
static inline void F_319 ( struct V_1 * V_2 )
{
if ( ! F_320 ( V_2 ) ) {
return;
}
F_316 ( V_2 , 1 ) ;
}
static void F_321 ( struct V_1 * V_2 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
T_1 V_217 = F_158 ( V_41 -> V_513 ) ;
if ( V_217 && ! V_514 )
V_217 -- ;
V_217 += F_223 ( V_41 -> V_82 ) ;
if ( F_47 ( V_30 -> V_85 , V_217 ) )
return;
if ( F_40 ( V_217 , V_30 -> V_81 ) )
return;
if ( V_30 -> V_479 && ! F_47 ( V_217 , V_30 -> V_515 ) )
return;
F_322 ( V_2 ) ;
if ( V_30 -> V_515 == V_30 -> V_85 && V_30 -> V_479 &&
! F_236 ( V_2 , V_516 ) && V_30 -> V_85 != V_30 -> V_81 ) {
struct V_3 * V_4 = F_255 ( & V_2 -> V_456 ) ;
V_30 -> V_85 ++ ;
if ( V_4 && ! F_40 ( V_30 -> V_85 , F_16 ( V_4 ) -> V_84 ) ) {
F_256 ( V_4 , & V_2 -> V_456 ) ;
F_257 ( V_4 ) ;
}
}
V_30 -> V_479 = V_517 ;
V_30 -> V_515 = V_217 ;
V_30 -> V_354 = 0 ;
}
static void F_323 ( struct V_1 * V_2 , struct V_3 * V_4 , const struct V_15 * V_41 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( V_41 -> V_518 )
F_321 ( V_2 , V_41 ) ;
if ( V_30 -> V_479 == V_517 ) {
T_1 V_217 = V_30 -> V_515 - F_223 ( V_41 -> V_82 ) + ( V_41 -> V_379 * 4 ) -
V_41 -> V_43 ;
if ( V_217 < V_4 -> V_10 ) {
T_3 V_213 ;
if ( F_305 ( V_4 , V_217 , & V_213 , 1 ) )
F_306 () ;
V_30 -> V_479 = V_519 | V_213 ;
if ( ! F_236 ( V_2 , V_426 ) )
V_2 -> V_484 ( V_2 , 0 ) ;
}
}
}
static int F_324 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_520 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_480 = V_4 -> V_10 - V_520 ;
int V_179 ;
F_290 () ;
if ( F_325 ( V_4 ) )
V_179 = F_291 ( V_4 , V_520 , V_30 -> V_476 . V_482 , V_480 ) ;
else
V_179 = F_326 ( V_4 , V_520 ,
V_30 -> V_476 . V_482 ) ;
if ( ! V_179 ) {
V_30 -> V_476 . V_10 -= V_480 ;
V_30 -> V_85 += V_480 ;
F_42 ( V_2 ) ;
}
F_292 () ;
return V_179 ;
}
static T_12 F_327 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_12 V_521 ;
if ( F_288 ( V_2 ) ) {
F_290 () ;
V_521 = F_328 ( V_4 ) ;
F_292 () ;
} else {
V_521 = F_328 ( V_4 ) ;
}
return V_521 ;
}
static inline int F_329 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return ! F_325 ( V_4 ) &&
F_327 ( V_2 , V_4 ) ;
}
static bool F_330 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_520 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_480 = V_4 -> V_10 - V_520 ;
int V_522 ;
bool V_523 = false ;
if ( V_30 -> V_476 . V_524 )
return false ;
if ( ! V_30 -> V_476 . V_525 && V_30 -> V_476 . V_526 )
V_30 -> V_476 . V_525 = F_331 () ;
if ( V_30 -> V_476 . V_525 && F_325 ( V_4 ) ) {
V_522 = F_332 ( V_30 -> V_476 . V_525 ,
V_4 , V_520 ,
V_30 -> V_476 . V_482 , V_480 ,
V_30 -> V_476 . V_526 ) ;
if ( V_522 < 0 )
goto V_208;
V_30 -> V_476 . V_522 = V_522 ;
V_523 = true ;
V_30 -> V_476 . V_10 -= V_480 ;
V_30 -> V_85 += V_480 ;
F_42 ( V_2 ) ;
if ( ( V_30 -> V_476 . V_10 == 0 ) ||
( F_5 ( F_6 ( V_4 ) ) & V_527 ) ||
( F_35 ( & V_2 -> V_72 ) > ( V_2 -> V_62 >> 1 ) ) ) {
V_30 -> V_476 . V_524 = 1 ;
V_2 -> V_484 ( V_2 , 0 ) ;
}
} else if ( V_480 > 0 ) {
V_30 -> V_476 . V_524 = 1 ;
V_2 -> V_484 ( V_2 , 0 ) ;
}
V_208:
return V_523 ;
}
static int F_333 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , int V_528 )
{
const T_3 * V_529 ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
if ( F_224 ( V_4 , V_41 , V_30 , & V_529 ) &&
V_30 -> V_45 . V_279 &&
F_231 ( V_2 , V_4 ) ) {
if ( ! V_41 -> V_530 ) {
F_72 ( F_73 ( V_2 ) , V_531 ) ;
F_249 ( V_2 , V_4 ) ;
goto V_532;
}
}
if ( ! F_232 ( V_30 , F_16 ( V_4 ) -> V_82 , F_16 ( V_4 ) -> V_84 ) ) {
if ( ! V_41 -> V_530 )
F_249 ( V_2 , V_4 ) ;
goto V_532;
}
if ( V_41 -> V_530 ) {
F_234 ( V_2 ) ;
goto V_532;
}
F_228 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_41 -> V_43 && ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) ) {
if ( V_528 )
F_334 ( F_73 ( V_2 ) , V_533 ) ;
F_72 ( F_73 ( V_2 ) , V_534 ) ;
F_234 ( V_2 ) ;
return - 1 ;
}
return 1 ;
V_532:
F_257 ( V_4 ) ;
return 0 ;
}
int F_335 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
int V_500 ;
V_30 -> V_45 . V_279 = 0 ;
if ( ( F_5 ( V_41 ) & V_535 ) == V_30 -> V_354 &&
F_16 ( V_4 ) -> V_82 == V_30 -> V_81 &&
! F_47 ( F_16 ( V_4 ) -> V_164 , V_30 -> V_98 ) ) {
int V_18 = V_30 -> V_18 ;
if ( V_18 == sizeof( struct V_15 ) + V_411 ) {
if ( ! F_221 ( V_30 , V_41 ) )
goto V_536;
if ( ( T_5 ) ( V_30 -> V_45 . V_397 - V_30 -> V_45 . V_413 ) < 0 )
goto V_536;
}
if ( V_10 <= V_18 ) {
if ( V_10 == V_18 ) {
if ( V_18 ==
( sizeof( struct V_15 ) + V_411 ) &&
V_30 -> V_81 == V_30 -> V_415 )
F_226 ( V_30 ) ;
F_214 ( V_2 , V_4 , 0 ) ;
F_257 ( V_4 ) ;
F_314 ( V_2 ) ;
return 0 ;
} else {
F_334 ( F_73 ( V_2 ) , V_533 ) ;
goto V_532;
}
} else {
int V_467 = 0 ;
int V_523 = 0 ;
bool V_461 = false ;
if ( V_30 -> V_85 == V_30 -> V_81 &&
V_10 - V_18 <= V_30 -> V_476 . V_10 ) {
#ifdef F_336
if ( F_330 ( V_2 , V_4 , V_18 ) ) {
V_523 = 1 ;
V_467 = 1 ;
}
#endif
if ( V_30 -> V_476 . V_477 == V_478 &&
F_288 ( V_2 ) && ! V_523 ) {
F_289 ( V_481 ) ;
if ( ! F_324 ( V_2 , V_4 , V_18 ) )
V_467 = 1 ;
}
if ( V_467 ) {
if ( V_18 ==
( sizeof( struct V_15 ) +
V_411 ) &&
V_30 -> V_81 == V_30 -> V_415 )
F_226 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
F_278 ( V_4 , V_18 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_84 ;
F_72 ( F_73 ( V_2 ) , V_537 ) ;
}
if ( V_523 )
F_337 ( V_2 , V_4 -> V_10 ) ;
}
if ( ! V_467 ) {
if ( F_329 ( V_2 , V_4 ) )
goto V_538;
if ( V_18 ==
( sizeof( struct V_15 ) + V_411 ) &&
V_30 -> V_81 == V_30 -> V_415 )
F_226 ( V_30 ) ;
F_41 ( V_2 , V_4 ) ;
if ( ( int ) V_4 -> V_51 > V_2 -> V_539 )
goto V_540;
F_72 ( F_73 ( V_2 ) , V_541 ) ;
V_467 = F_277 ( V_2 , V_4 , V_18 ,
& V_461 ) ;
}
F_43 ( V_2 , V_4 ) ;
if ( F_16 ( V_4 ) -> V_164 != V_30 -> V_96 ) {
F_214 ( V_2 , V_4 , V_367 ) ;
F_314 ( V_2 ) ;
if ( ! F_320 ( V_2 ) )
goto V_542;
}
if ( ! V_523 || V_30 -> V_81 != V_30 -> V_415 )
F_316 ( V_2 , 0 ) ;
V_542:
#ifdef F_336
if ( V_523 )
F_258 ( & V_2 -> V_543 , V_4 ) ;
else
#endif
if ( V_467 )
F_271 ( V_4 , V_461 ) ;
else
V_2 -> V_484 ( V_2 , 0 ) ;
return 0 ;
}
}
V_536:
if ( V_10 < ( V_41 -> V_379 << 2 ) || F_329 ( V_2 , V_4 ) )
goto V_538;
V_500 = F_333 ( V_2 , V_4 , V_41 , 1 ) ;
if ( V_500 <= 0 )
return - V_500 ;
V_540:
if ( V_41 -> V_323 && F_214 ( V_2 , V_4 , V_364 ) < 0 )
goto V_532;
F_41 ( V_2 , V_4 ) ;
F_323 ( V_2 , V_4 , V_41 ) ;
F_286 ( V_2 , V_4 ) ;
F_314 ( V_2 ) ;
F_319 ( V_2 ) ;
return 0 ;
V_538:
F_334 ( F_73 ( V_2 ) , V_533 ) ;
V_532:
F_257 ( V_4 ) ;
return 0 ;
}
void F_338 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_240 ( V_2 , V_432 ) ;
if ( V_4 != NULL )
F_339 ( V_2 , V_4 ) ;
V_6 -> V_544 -> V_545 ( V_2 ) ;
F_68 ( V_2 ) ;
F_340 ( V_2 ) ;
V_30 -> V_546 = V_71 ;
F_29 ( V_2 ) ;
if ( F_236 ( V_2 , V_547 ) )
F_341 ( V_2 , F_342 ( V_30 ) ) ;
if ( ! V_30 -> V_45 . V_352 )
F_343 ( V_30 , V_30 -> V_351 ) ;
else
V_30 -> V_354 = 0 ;
if ( ! F_236 ( V_2 , V_426 ) ) {
V_2 -> V_439 ( V_2 ) ;
F_245 ( V_2 , V_548 , V_549 ) ;
}
}
static int F_344 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
const T_3 * V_529 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_550 * V_551 = V_30 -> V_552 ;
int V_553 = V_30 -> V_45 . V_46 ;
F_216 ( V_4 , & V_30 -> V_45 , & V_529 , 0 ) ;
if ( V_41 -> V_323 ) {
if ( F_16 ( V_4 ) -> V_164 != V_30 -> V_98 )
goto V_554;
if ( V_30 -> V_45 . V_279 && V_30 -> V_45 . V_83 &&
! F_197 ( V_30 -> V_45 . V_83 , V_30 -> V_278 ,
V_71 ) ) {
F_72 ( F_73 ( V_2 ) , V_555 ) ;
goto V_554;
}
if ( V_41 -> V_530 ) {
F_234 ( V_2 ) ;
goto V_532;
}
if ( ! V_41 -> V_43 )
goto V_556;
F_17 ( V_30 , V_41 ) ;
V_30 -> V_350 = F_16 ( V_4 ) -> V_82 ;
F_214 ( V_2 , V_4 , V_364 ) ;
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_415 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_351 = F_158 ( V_41 -> V_52 ) ;
F_345 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( ! V_30 -> V_45 . V_391 ) {
V_30 -> V_45 . V_352 = V_30 -> V_45 . V_557 = 0 ;
V_30 -> V_55 = F_9 ( V_30 -> V_55 , 65535U ) ;
}
if ( V_30 -> V_45 . V_279 ) {
V_30 -> V_45 . V_395 = 1 ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_411 ;
V_30 -> V_57 -= V_411 ;
F_226 ( V_30 ) ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
if ( F_147 ( V_30 ) && V_558 )
F_346 ( V_30 ) ;
F_347 ( V_2 ) ;
F_175 ( V_2 , V_6 -> V_303 ) ;
F_36 ( V_2 ) ;
V_30 -> V_85 = V_30 -> V_81 ;
if ( V_551 != NULL &&
V_551 -> V_559 > 0 &&
V_30 -> V_45 . V_410 > 0 ) {
int V_560 = V_30 -> V_45 . V_410
- V_406 ;
int V_559 = V_560
+ V_551 -> V_561 ;
if ( sizeof( V_551 -> V_562 ) >= V_559 ) {
memcpy ( & V_551 -> V_562 [ V_551 -> V_561 ] ,
V_529 , V_560 ) ;
V_551 -> V_559 = V_559 ;
}
}
F_348 () ;
F_338 ( V_2 , V_4 ) ;
if ( V_2 -> V_563 ||
V_6 -> V_564 . V_565 ||
V_6 -> V_8 . V_26 ) {
F_44 ( V_2 ) ;
V_6 -> V_8 . V_89 = V_71 ;
F_10 ( V_2 ) ;
F_137 ( V_2 , V_566 ,
V_567 , V_254 ) ;
V_532:
F_257 ( V_4 ) ;
return 0 ;
} else {
F_241 ( V_2 ) ;
}
return - 1 ;
}
if ( V_41 -> V_530 ) {
goto V_556;
}
if ( V_30 -> V_45 . V_414 && V_30 -> V_45 . V_279 &&
F_349 ( & V_30 -> V_45 , 0 ) )
goto V_556;
if ( V_41 -> V_43 ) {
F_240 ( V_2 , V_431 ) ;
if ( V_30 -> V_45 . V_279 ) {
V_30 -> V_45 . V_395 = 1 ;
F_226 ( V_30 ) ;
V_30 -> V_18 =
sizeof( struct V_15 ) + V_411 ;
} else {
V_30 -> V_18 = sizeof( struct V_15 ) ;
}
V_30 -> V_81 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_415 = F_16 ( V_4 ) -> V_82 + 1 ;
V_30 -> V_351 = F_158 ( V_41 -> V_52 ) ;
V_30 -> V_350 = F_16 ( V_4 ) -> V_82 ;
V_30 -> V_157 = V_30 -> V_351 ;
F_18 ( V_30 , V_41 ) ;
F_347 ( V_2 ) ;
F_175 ( V_2 , V_6 -> V_303 ) ;
F_36 ( V_2 ) ;
F_350 ( V_2 ) ;
#if 0
return -1;
#else
goto V_532;
#endif
}
V_556:
F_351 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_553 ;
goto V_532;
V_554:
F_351 ( & V_30 -> V_45 ) ;
V_30 -> V_45 . V_46 = V_553 ;
return 1 ;
}
int F_352 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_15 * V_41 , unsigned int V_10 )
{
struct V_29 * V_30 = F_7 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_568 = 0 ;
int V_500 ;
V_30 -> V_45 . V_279 = 0 ;
switch ( V_2 -> V_418 ) {
case V_424 :
goto V_532;
case V_569 :
if ( V_41 -> V_323 )
return 1 ;
if ( V_41 -> V_530 )
goto V_532;
if ( V_41 -> V_43 ) {
if ( V_41 -> V_457 )
goto V_532;
if ( V_6 -> V_544 -> V_570 ( V_2 , V_4 ) < 0 )
return 1 ;
F_285 ( V_4 ) ;
return 0 ;
}
goto V_532;
case V_419 :
V_568 = F_344 ( V_2 , V_4 , V_41 , V_10 ) ;
if ( V_568 >= 0 )
return V_568 ;
F_323 ( V_2 , V_4 , V_41 ) ;
F_257 ( V_4 ) ;
F_314 ( V_2 ) ;
return 0 ;
}
V_500 = F_333 ( V_2 , V_4 , V_41 , 0 ) ;
if ( V_500 <= 0 )
return - V_500 ;
if ( V_41 -> V_323 ) {
int V_571 = F_214 ( V_2 , V_4 , V_364 ) > 0 ;
switch ( V_2 -> V_418 ) {
case V_431 :
if ( V_571 ) {
V_30 -> V_85 = V_30 -> V_81 ;
F_348 () ;
F_240 ( V_2 , V_432 ) ;
V_2 -> V_439 ( V_2 ) ;
if ( V_2 -> V_504 )
F_245 ( V_2 ,
V_548 , V_549 ) ;
V_30 -> V_96 = F_16 ( V_4 ) -> V_164 ;
V_30 -> V_351 = F_158 ( V_41 -> V_52 ) <<
V_30 -> V_45 . V_352 ;
F_345 ( V_30 , F_16 ( V_4 ) -> V_82 ) ;
if ( V_30 -> V_45 . V_395 )
V_30 -> V_57 -= V_411 ;
V_6 -> V_544 -> V_545 ( V_2 ) ;
F_68 ( V_2 ) ;
F_340 ( V_2 ) ;
V_30 -> V_546 = V_71 ;
F_347 ( V_2 ) ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_353 ( V_30 ) ;
} else {
return 1 ;
}
break;
case V_435 :
if ( V_30 -> V_96 == V_30 -> V_572 ) {
F_240 ( V_2 , V_436 ) ;
V_2 -> V_428 |= V_573 ;
F_54 ( F_53 ( V_2 ) ) ;
if ( ! F_236 ( V_2 , V_426 ) )
V_2 -> V_439 ( V_2 ) ;
else {
int V_574 ;
if ( V_30 -> V_575 < 0 ||
( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_457 , V_30 -> V_81 ) ) ) {
F_237 ( V_2 ) ;
F_72 ( F_73 ( V_2 ) , V_576 ) ;
return 1 ;
}
V_574 = F_354 ( V_2 ) ;
if ( V_574 > V_577 ) {
F_341 ( V_2 , V_574 - V_577 ) ;
} else if ( V_41 -> V_457 || F_288 ( V_2 ) ) {
F_341 ( V_2 , V_574 ) ;
} else {
F_242 ( V_2 , V_436 , V_574 ) ;
goto V_532;
}
}
}
break;
case V_433 :
if ( V_30 -> V_96 == V_30 -> V_572 ) {
F_242 ( V_2 , V_437 , 0 ) ;
goto V_532;
}
break;
case V_434 :
if ( V_30 -> V_96 == V_30 -> V_572 ) {
F_52 ( V_2 ) ;
F_237 ( V_2 ) ;
goto V_532;
}
break;
}
} else
goto V_532;
F_323 ( V_2 , V_4 , V_41 ) ;
switch ( V_2 -> V_418 ) {
case V_422 :
case V_433 :
case V_434 :
if ( ! F_40 ( F_16 ( V_4 ) -> V_82 , V_30 -> V_81 ) )
break;
case V_435 :
case V_436 :
if ( V_2 -> V_428 & V_429 ) {
if ( F_16 ( V_4 ) -> V_84 != F_16 ( V_4 ) -> V_82 &&
F_47 ( F_16 ( V_4 ) -> V_84 - V_41 -> V_457 , V_30 -> V_81 ) ) {
F_72 ( F_73 ( V_2 ) , V_576 ) ;
F_234 ( V_2 ) ;
return 1 ;
}
}
case V_432 :
F_286 ( V_2 , V_4 ) ;
V_568 = 1 ;
break;
}
if ( V_2 -> V_418 != V_424 ) {
F_314 ( V_2 ) ;
F_319 ( V_2 ) ;
}
if ( ! V_568 ) {
V_532:
F_257 ( V_4 ) ;
}
return 0 ;
}
