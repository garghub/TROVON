static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) &&
! F_3 ( V_6 , & V_2 -> V_4 ) )
F_4 ( & V_2 -> V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( ! F_2 ( V_6 , & V_2 -> V_4 ) ) ;
F_7 () ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
if ( ! V_9 -> V_11 )
return;
V_9 -> V_11 = NULL ;
F_10 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
if ( F_2 ( V_14 , & V_2 -> V_4 ) )
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_8 * V_9 , T_1 V_15 )
{
T_1 V_16 ;
if ( V_15 == V_17 ) {
F_9 ( V_9 ) ;
return;
}
V_16 = F_12 ( V_9 , V_17 ) ;
if ( V_16 == V_18 )
F_9 ( V_9 ) ;
}
T_1 F_12 ( struct V_8 * V_9 , T_1 V_15 )
{
T_2 T_3 * V_19 = F_13 ( V_9 -> V_11 ) ;
T_1 V_16 ;
if ( F_14 ( V_19 ) )
return V_18 ;
V_16 = F_15 ( V_19 + V_15 ) ;
if ( F_16 ( V_16 == V_18 ) )
F_11 ( V_9 , V_15 ) ;
return V_16 ;
}
static void F_17 ( struct V_1 * V_2 , T_4 V_20 ,
T_2 V_21 , T_2 V_22 )
{
T_1 V_23 , V_24 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( V_20 == - 1 ) {
V_22 |= V_25 ;
V_23 = F_18 ( V_9 , V_26 ) ;
V_23 &= ~ 0xFF ;
V_23 |= V_22 ;
F_19 ( V_9 , V_26 , V_23 ) ;
} else {
V_22 |= V_25 ;
V_24 = ( ( 16 * ( V_21 & 1 ) ) + ( 8 * V_20 ) ) ;
V_23 = F_18 ( V_9 , F_20 ( V_21 >> 1 ) ) ;
V_23 &= ~ ( 0xFF << V_24 ) ;
V_23 |= ( V_22 << V_24 ) ;
F_19 ( V_9 , F_20 ( V_21 >> 1 ) , V_23 ) ;
}
}
static void F_21 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_31 ) {
F_22 ( V_30 -> V_31 ) ;
if ( F_23 ( V_30 , V_32 ) )
F_24 ( V_28 -> V_13 ,
F_25 ( V_30 , V_33 ) ,
F_23 ( V_30 , V_32 ) ,
V_34 ) ;
} else if ( F_23 ( V_30 , V_32 ) ) {
F_26 ( V_28 -> V_13 ,
F_25 ( V_30 , V_33 ) ,
F_23 ( V_30 , V_32 ) ,
V_34 ) ;
}
V_30 -> V_35 = NULL ;
V_30 -> V_31 = NULL ;
F_27 ( V_30 , V_32 , 0 ) ;
}
static T_5 F_28 ( struct V_27 * V_36 )
{
return V_36 -> V_37 . V_38 ;
}
static T_1 F_29 ( struct V_27 * V_36 )
{
struct V_1 * V_2 = F_30 ( V_36 -> V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_40 = F_18 ( V_9 , F_31 ( V_36 -> V_41 ) ) ;
T_1 V_42 = F_18 ( V_9 , F_32 ( V_36 -> V_41 ) ) ;
if ( V_40 != V_42 )
return ( V_40 < V_42 ) ?
V_42 - V_40 : ( V_42 + V_36 -> V_43 - V_40 ) ;
return 0 ;
}
static inline bool F_33 ( struct V_27 * V_28 )
{
T_1 V_44 = F_28 ( V_28 ) ;
T_1 V_45 = V_28 -> V_46 . V_45 ;
T_1 V_47 = F_29 ( V_28 ) ;
F_34 ( V_28 ) ;
if ( ( V_45 == V_44 ) && V_47 ) {
return F_3 ( V_48 ,
& V_28 -> V_4 ) ;
}
F_8 ( V_48 , & V_28 -> V_4 ) ;
V_28 -> V_46 . V_45 = V_44 ;
return false ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_49 |= V_50 ;
F_1 ( V_2 ) ;
}
}
static void F_36 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
F_35 ( V_2 ) ;
}
static bool F_37 ( struct V_52 * V_53 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_29 * V_30 ;
union V_54 * V_55 ;
unsigned int V_56 = 0 , V_57 = 0 ;
unsigned int V_58 = V_28 -> V_43 / 2 ;
unsigned int V_59 = V_28 -> V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return true ;
V_30 = & V_28 -> V_61 [ V_59 ] ;
V_55 = F_38 ( V_28 , V_59 ) ;
V_59 -= V_28 -> V_43 ;
do {
union V_54 * V_62 = V_30 -> V_35 ;
if ( ! V_62 )
break;
F_39 () ;
if ( ! ( V_62 -> V_63 . V_64 & F_40 ( V_65 ) ) )
break;
V_30 -> V_35 = NULL ;
V_56 += V_30 -> V_66 ;
V_57 += V_30 -> V_67 ;
F_22 ( V_30 -> V_31 ) ;
F_24 ( V_28 -> V_13 ,
F_25 ( V_30 , V_33 ) ,
F_23 ( V_30 , V_32 ) ,
V_34 ) ;
V_30 -> V_31 = NULL ;
F_27 ( V_30 , V_32 , 0 ) ;
while ( V_55 != V_62 ) {
V_30 ++ ;
V_55 ++ ;
V_59 ++ ;
if ( F_16 ( ! V_59 ) ) {
V_59 -= V_28 -> V_43 ;
V_30 = V_28 -> V_61 ;
V_55 = F_38 ( V_28 , 0 ) ;
}
if ( F_23 ( V_30 , V_32 ) ) {
F_26 ( V_28 -> V_13 ,
F_25 ( V_30 , V_33 ) ,
F_23 ( V_30 , V_32 ) ,
V_34 ) ;
F_27 ( V_30 , V_32 , 0 ) ;
}
}
V_30 ++ ;
V_55 ++ ;
V_59 ++ ;
if ( F_16 ( ! V_59 ) ) {
V_59 -= V_28 -> V_43 ;
V_30 = V_28 -> V_61 ;
V_55 = F_38 ( V_28 , 0 ) ;
}
F_41 ( V_55 ) ;
V_58 -- ;
} while ( F_42 ( V_58 ) );
V_59 += V_28 -> V_43 ;
V_28 -> V_60 = V_59 ;
F_43 ( & V_28 -> V_68 ) ;
V_28 -> V_37 . V_69 += V_56 ;
V_28 -> V_37 . V_38 += V_57 ;
F_44 ( & V_28 -> V_68 ) ;
V_53 -> V_70 . V_56 += V_56 ;
V_53 -> V_70 . V_57 += V_57 ;
if ( F_45 ( V_28 ) && F_33 ( V_28 ) ) {
struct V_8 * V_9 = & V_2 -> V_9 ;
union V_54 * V_62 ;
V_62 = V_28 -> V_61 [ V_59 ] . V_35 ;
F_46 ( L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11 ,
V_28 -> V_71 ,
F_18 ( V_9 , F_31 ( V_28 -> V_41 ) ) ,
F_18 ( V_9 , F_32 ( V_28 -> V_41 ) ) ,
V_28 -> V_72 , V_59 ,
V_62 , ( V_62 ? V_62 -> V_63 . V_64 : 0 ) ,
V_28 -> V_61 [ V_59 ] . V_73 , V_74 ) ;
F_47 ( V_28 -> V_39 , V_28 -> V_71 ) ;
F_35 ( V_2 ) ;
return true ;
}
#define F_48 (DESC_NEEDED * 2)
if ( F_16 ( V_57 && F_49 ( V_28 -> V_39 ) &&
( F_50 ( V_28 ) >= F_48 ) ) ) {
F_51 () ;
if ( F_52 ( V_28 -> V_39 ,
V_28 -> V_71 ) &&
! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_53 ( V_28 -> V_39 ,
V_28 -> V_71 ) ;
++ V_28 -> V_46 . V_75 ;
}
}
return ! ! V_58 ;
}
static void F_54 ( struct V_52 * V_53 ,
struct V_76 * V_31 )
{
#ifdef F_55
F_56 ( V_31 , & V_53 -> V_77 ) ;
if ( F_57 ( V_53 ) ) {
F_58 ( V_31 ) ;
return;
}
#endif
F_59 ( & V_53 -> V_77 , V_31 ) ;
}
static inline void F_60 ( struct V_27 * V_36 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
F_61 ( V_31 ) ;
if ( ! ( V_36 -> V_39 -> V_80 & V_81 ) )
return;
if ( F_62 ( V_79 , V_82 ) &&
F_62 ( V_79 , V_83 ) ) {
V_36 -> V_84 . V_85 ++ ;
return;
}
if ( ! F_62 ( V_79 , V_86 ) )
return;
if ( F_62 ( V_79 , V_87 ) ) {
V_36 -> V_84 . V_85 ++ ;
return;
}
V_31 -> V_88 = V_89 ;
}
static void F_63 ( struct V_27 * V_90 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
F_60 ( V_90 , V_79 , V_31 ) ;
if ( F_62 ( V_79 , V_91 ) ) {
T_6 V_92 = F_64 ( V_79 -> V_63 . V_93 . V_94 ) ;
unsigned long * V_95 = F_30 ( V_90 -> V_39 ) ;
if ( F_2 ( V_92 & V_96 , V_95 ) )
F_65 ( V_31 , F_66 ( V_97 ) , V_92 ) ;
}
V_31 -> V_98 = F_67 ( V_31 , V_90 -> V_39 ) ;
}
static bool F_68 ( struct V_27 * V_90 ,
union V_78 * V_79 )
{
T_1 V_99 = V_90 -> V_60 + 1 ;
V_99 = ( V_99 < V_90 -> V_43 ) ? V_99 : 0 ;
V_90 -> V_60 = V_99 ;
F_41 ( F_69 ( V_90 , V_99 ) ) ;
if ( F_42 ( F_62 ( V_79 , V_100 ) ) )
return false ;
return true ;
}
static bool F_70 ( struct V_27 * V_90 ,
struct V_101 * V_102 )
{
struct V_103 * V_103 = V_102 -> V_103 ;
T_7 V_33 = V_102 -> V_33 ;
if ( F_42 ( V_103 ) )
return true ;
V_103 = F_71 () ;
if ( F_16 ( ! V_103 ) ) {
V_90 -> V_84 . V_104 ++ ;
return false ;
}
V_33 = F_72 ( V_90 -> V_13 , V_103 , 0 ,
V_105 , V_106 ) ;
if ( F_73 ( V_90 -> V_13 , V_33 ) ) {
F_74 ( V_103 ) ;
V_90 -> V_84 . V_107 ++ ;
return false ;
}
V_102 -> V_33 = V_33 ;
V_102 -> V_103 = V_103 ;
V_102 -> V_108 = 0 ;
return true ;
}
static void F_75 ( struct V_27 * V_90 ,
T_6 V_109 )
{
union V_78 * V_79 ;
struct V_101 * V_102 ;
unsigned int V_59 = V_90 -> V_72 ;
if ( ! V_109 || ! V_90 -> V_39 )
return;
V_79 = F_69 ( V_90 , V_59 ) ;
V_102 = & V_90 -> V_110 [ V_59 ] ;
V_59 -= V_90 -> V_43 ;
do {
if ( ! F_70 ( V_90 , V_102 ) )
break;
V_79 -> V_111 . V_112 = F_76 ( V_102 -> V_33 + V_102 -> V_108 ) ;
V_79 ++ ;
V_102 ++ ;
V_59 ++ ;
if ( F_16 ( ! V_59 ) ) {
V_79 = F_69 ( V_90 , 0 ) ;
V_102 = V_90 -> V_110 ;
V_59 -= V_90 -> V_43 ;
}
V_79 -> V_111 . V_113 = 0 ;
V_109 -- ;
} while ( V_109 );
V_59 += V_90 -> V_43 ;
if ( V_90 -> V_72 != V_59 ) {
V_90 -> V_72 = V_59 ;
V_90 -> V_114 = V_59 ;
F_77 () ;
F_78 ( V_90 , V_59 ) ;
}
}
static void F_79 ( struct V_27 * V_90 ,
struct V_76 * V_31 )
{
struct V_115 * V_116 = & F_80 ( V_31 ) -> V_117 [ 0 ] ;
unsigned char * V_118 ;
unsigned int V_119 ;
V_118 = F_81 ( V_116 ) ;
V_119 = F_82 ( V_118 , V_120 ) ;
F_83 ( V_31 , V_118 , F_84 ( V_119 , sizeof( long ) ) ) ;
F_85 ( V_116 , V_119 ) ;
V_116 -> V_108 += V_119 ;
V_31 -> V_121 -= V_119 ;
V_31 -> V_42 += V_119 ;
}
static bool F_86 ( struct V_27 * V_90 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
if ( F_16 ( F_62 ( V_79 ,
V_122 ) ) ) {
struct V_51 * V_39 = V_90 -> V_39 ;
if ( ! ( V_39 -> V_80 & V_123 ) ) {
F_22 ( V_31 ) ;
return true ;
}
}
if ( F_87 ( V_31 ) )
F_79 ( V_90 , V_31 ) ;
if ( F_88 ( V_31 ) )
return true ;
return false ;
}
static void F_89 ( struct V_27 * V_90 ,
struct V_101 * V_124 )
{
struct V_101 * V_125 ;
T_6 V_126 = V_90 -> V_114 ;
V_125 = & V_90 -> V_110 [ V_126 ] ;
V_126 ++ ;
V_90 -> V_114 = ( V_126 < V_90 -> V_43 ) ? V_126 : 0 ;
V_125 -> V_103 = V_124 -> V_103 ;
V_125 -> V_33 = V_124 -> V_33 ;
V_125 -> V_108 = V_124 -> V_108 ;
F_90 ( V_90 -> V_13 , V_125 -> V_33 ,
V_125 -> V_108 ,
V_127 ,
V_106 ) ;
}
static inline bool F_91 ( struct V_103 * V_103 )
{
return ( F_92 ( V_103 ) != F_93 () ) || F_94 ( V_103 ) ;
}
static bool F_95 ( struct V_27 * V_90 ,
struct V_101 * V_128 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
struct V_103 * V_103 = V_128 -> V_103 ;
unsigned int V_129 = F_64 ( V_79 -> V_63 . V_93 . V_130 ) ;
#if ( V_105 < 8192 )
unsigned int V_131 = V_127 ;
#else
unsigned int V_131 = F_84 ( V_129 , V_132 ) ;
#endif
if ( ( V_129 <= V_120 ) && ! F_87 ( V_31 ) ) {
unsigned char * V_118 = F_96 ( V_103 ) + V_128 -> V_108 ;
memcpy ( F_97 ( V_31 , V_129 ) , V_118 , F_84 ( V_129 , sizeof( long ) ) ) ;
if ( F_42 ( ! F_91 ( V_103 ) ) )
return true ;
F_98 ( V_103 ) ;
return false ;
}
F_99 ( V_31 , F_80 ( V_31 ) -> V_133 , V_103 ,
V_128 -> V_108 , V_129 , V_131 ) ;
if ( F_16 ( F_91 ( V_103 ) ) )
return false ;
#if ( V_105 < 8192 )
if ( F_16 ( F_100 ( V_103 ) != 1 ) )
return false ;
V_128 -> V_108 ^= V_127 ;
#else
V_128 -> V_108 += V_131 ;
if ( V_128 -> V_108 > ( V_105 - V_127 ) )
return false ;
#endif
F_101 ( & V_103 -> V_134 ) ;
return true ;
}
static struct V_76 * F_102 ( struct V_27 * V_90 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
struct V_101 * V_128 ;
struct V_103 * V_103 ;
V_128 = & V_90 -> V_110 [ V_90 -> V_60 ] ;
V_103 = V_128 -> V_103 ;
F_103 ( V_103 ) ;
if ( F_42 ( ! V_31 ) ) {
void * V_135 = F_96 ( V_103 ) +
V_128 -> V_108 ;
F_41 ( V_135 ) ;
#if V_132 < 128
F_41 ( V_135 + V_132 ) ;
#endif
V_31 = F_104 ( V_90 -> V_39 ,
V_120 ) ;
if ( F_16 ( ! V_31 ) ) {
V_90 -> V_84 . V_107 ++ ;
return NULL ;
}
F_103 ( V_31 -> V_136 ) ;
}
F_105 ( V_90 -> V_13 ,
V_128 -> V_33 ,
V_128 -> V_108 ,
V_127 ,
V_106 ) ;
if ( F_95 ( V_90 , V_128 , V_79 , V_31 ) ) {
F_89 ( V_90 , V_128 ) ;
} else {
F_26 ( V_90 -> V_13 , V_128 -> V_33 ,
V_105 , V_106 ) ;
}
V_128 -> V_33 = 0 ;
V_128 -> V_103 = NULL ;
return V_31 ;
}
static inline void F_106 ( struct V_1 * V_2 ,
T_1 V_137 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_19 ( V_9 , V_138 , V_137 ) ;
}
static int F_107 ( struct V_52 * V_53 ,
struct V_27 * V_90 ,
int V_58 )
{
unsigned int V_139 = 0 , V_140 = 0 ;
T_6 V_109 = F_50 ( V_90 ) ;
struct V_76 * V_31 = V_90 -> V_31 ;
while ( F_42 ( V_140 < V_58 ) ) {
union V_78 * V_79 ;
if ( V_109 >= V_141 ) {
F_75 ( V_90 , V_109 ) ;
V_109 = 0 ;
}
V_79 = F_69 ( V_90 , V_90 -> V_60 ) ;
if ( ! F_62 ( V_79 , V_142 ) )
break;
F_108 () ;
V_31 = F_102 ( V_90 , V_79 , V_31 ) ;
if ( ! V_31 )
break;
V_109 ++ ;
if ( F_68 ( V_90 , V_79 ) )
continue;
if ( F_86 ( V_90 , V_79 , V_31 ) ) {
V_31 = NULL ;
continue;
}
V_139 += V_31 -> V_32 ;
if ( ( V_31 -> V_143 == V_144 ||
V_31 -> V_143 == V_145 ) &&
F_109 ( V_90 -> V_39 -> V_146 ,
F_110 ( V_31 ) -> V_147 ) ) {
F_111 ( V_31 ) ;
continue;
}
F_63 ( V_90 , V_79 , V_31 ) ;
F_54 ( V_53 , V_31 ) ;
V_31 = NULL ;
V_140 ++ ;
}
V_90 -> V_31 = V_31 ;
F_43 ( & V_90 -> V_68 ) ;
V_90 -> V_37 . V_38 += V_140 ;
V_90 -> V_37 . V_69 += V_139 ;
F_44 ( & V_90 -> V_68 ) ;
V_53 -> V_148 . V_57 += V_140 ;
V_53 -> V_148 . V_56 += V_139 ;
return V_140 ;
}
static int F_112 ( struct V_149 * V_77 , int V_58 )
{
struct V_52 * V_53 =
F_113 ( V_77 , struct V_52 , V_77 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_27 * V_36 ;
int V_150 ;
bool V_151 = true ;
F_114 (ring, q_vector->tx)
V_151 &= F_37 ( V_53 , V_36 ) ;
#ifdef F_55
if ( ! F_115 ( V_53 ) )
return V_58 ;
#endif
if ( V_53 -> V_148 . V_43 > 1 )
V_150 = F_116 ( V_58 / V_53 -> V_148 . V_43 , 1 ) ;
else
V_150 = V_58 ;
F_114 (ring, q_vector->rx)
V_151 &= ( F_107 ( V_53 , V_36 ,
V_150 )
< V_150 ) ;
#ifdef F_55
F_117 ( V_53 ) ;
#endif
if ( ! V_151 )
return V_58 ;
F_118 ( V_77 ) ;
if ( V_2 -> V_152 & 1 )
F_119 ( V_53 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) )
F_106 ( V_2 ,
1 << V_53 -> V_153 ) ;
return 0 ;
}
void F_120 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_153 = V_53 -> V_153 ;
T_1 V_154 = V_53 -> V_155 & V_156 ;
V_154 |= V_157 ;
F_19 ( V_9 , F_121 ( V_153 ) , V_154 ) ;
}
static int F_122 ( struct V_149 * V_77 )
{
struct V_52 * V_53 =
F_113 ( V_77 , struct V_52 , V_77 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_27 * V_36 ;
int V_158 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return V_159 ;
if ( ! F_123 ( V_53 ) )
return V_160 ;
F_114 (ring, q_vector->rx) {
V_158 = F_107 ( V_53 , V_36 , 4 ) ;
#ifdef F_124
if ( V_158 )
V_36 -> V_37 . V_161 += V_158 ;
else
V_36 -> V_37 . V_162 ++ ;
#endif
if ( V_158 )
break;
}
F_125 ( V_53 ) ;
return V_158 ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
int V_163 , V_153 ;
V_163 = V_2 -> V_164 - V_165 ;
V_2 -> V_166 = 0 ;
for ( V_153 = 0 ; V_153 < V_163 ; V_153 ++ ) {
struct V_27 * V_36 ;
V_53 = V_2 -> V_53 [ V_153 ] ;
F_114 (ring, q_vector->rx)
F_17 ( V_2 , 0 , V_36 -> V_41 , V_153 ) ;
F_114 (ring, q_vector->tx)
F_17 ( V_2 , 1 , V_36 -> V_41 , V_153 ) ;
if ( V_53 -> V_70 . V_36 && ! V_53 -> V_148 . V_36 ) {
if ( V_2 -> V_167 == 1 )
V_53 -> V_155 = V_168 ;
else
V_53 -> V_155 = V_2 -> V_167 ;
} else {
if ( V_2 -> V_152 == 1 )
V_53 -> V_155 = V_169 ;
else
V_53 -> V_155 = V_2 -> V_152 ;
}
V_2 -> V_166 |= 1 << V_153 ;
F_120 ( V_53 ) ;
}
F_17 ( V_2 , - 1 , 1 , V_153 ) ;
V_2 -> V_170 = 1 << V_153 ;
V_2 -> V_166 |= V_2 -> V_170 ;
}
static void F_127 ( struct V_52 * V_53 ,
struct V_171 * V_172 )
{
int V_69 = V_172 -> V_56 ;
int V_38 = V_172 -> V_57 ;
T_1 V_173 ;
T_5 V_174 ;
T_2 V_175 = V_172 -> V_155 ;
if ( V_38 == 0 )
return;
V_173 = V_53 -> V_155 >> 2 ;
V_174 = V_69 / V_173 ;
switch ( V_175 ) {
case V_176 :
if ( V_174 > 10 )
V_175 = V_177 ;
break;
case V_177 :
if ( V_174 > 20 )
V_175 = V_178 ;
else if ( V_174 <= 10 )
V_175 = V_176 ;
break;
case V_178 :
if ( V_174 <= 20 )
V_175 = V_177 ;
break;
}
V_172 -> V_56 = 0 ;
V_172 -> V_57 = 0 ;
V_172 -> V_155 = V_175 ;
}
static void F_119 ( struct V_52 * V_53 )
{
T_1 V_179 = V_53 -> V_155 ;
T_2 V_180 ;
F_127 ( V_53 , & V_53 -> V_70 ) ;
F_127 ( V_53 , & V_53 -> V_148 ) ;
V_180 = F_116 ( V_53 -> V_148 . V_155 , V_53 -> V_70 . V_155 ) ;
switch ( V_180 ) {
case V_176 :
V_179 = V_181 ;
break;
case V_177 :
V_179 = V_169 ;
break;
case V_178 :
default:
V_179 = V_182 ;
break;
}
if ( V_179 != V_53 -> V_155 ) {
V_179 = ( 10 * V_179 * V_53 -> V_155 ) /
( ( 9 * V_179 ) + V_53 -> V_155 ) ;
V_53 -> V_155 = V_179 ;
F_120 ( V_53 ) ;
}
}
static T_8 F_128 ( int V_183 , void * V_136 )
{
struct V_1 * V_2 = V_136 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
V_9 -> V_184 . V_185 = 1 ;
F_1 ( V_2 ) ;
F_19 ( V_9 , V_138 , V_2 -> V_170 ) ;
return V_186 ;
}
static T_8 F_129 ( int V_183 , void * V_136 )
{
struct V_52 * V_53 = V_136 ;
if ( V_53 -> V_148 . V_36 || V_53 -> V_70 . V_36 )
F_130 ( & V_53 -> V_77 ) ;
return V_186 ;
}
static inline void F_131 ( struct V_1 * V_187 , int V_153 ,
int V_188 )
{
struct V_52 * V_53 = V_187 -> V_53 [ V_153 ] ;
V_187 -> V_90 [ V_188 ] -> V_189 = V_53 -> V_148 . V_36 ;
V_53 -> V_148 . V_36 = V_187 -> V_90 [ V_188 ] ;
V_53 -> V_148 . V_43 ++ ;
}
static inline void F_132 ( struct V_1 * V_187 , int V_153 ,
int V_190 )
{
struct V_52 * V_53 = V_187 -> V_53 [ V_153 ] ;
V_187 -> V_28 [ V_190 ] -> V_189 = V_53 -> V_70 . V_36 ;
V_53 -> V_70 . V_36 = V_187 -> V_28 [ V_190 ] ;
V_53 -> V_70 . V_43 ++ ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_163 ;
int V_191 = 0 ;
int V_192 = 0 , V_193 = 0 ;
int V_194 = V_2 -> V_195 ;
int V_196 = V_2 -> V_197 ;
int V_59 , V_198 ;
int V_199 , V_200 ;
int V_201 = 0 ;
V_163 = V_2 -> V_164 - V_165 ;
if ( V_163 == V_2 -> V_195 + V_2 -> V_197 ) {
for (; V_192 < V_194 ; V_191 ++ , V_192 ++ )
F_131 ( V_2 , V_191 , V_192 ) ;
for (; V_193 < V_196 ; V_191 ++ , V_193 ++ )
F_132 ( V_2 , V_191 , V_193 ) ;
goto V_202;
}
for ( V_59 = V_191 ; V_59 < V_163 ; V_59 ++ ) {
V_199 = F_134 ( V_194 , V_163 - V_59 ) ;
for ( V_198 = 0 ; V_198 < V_199 ; V_198 ++ ) {
F_131 ( V_2 , V_59 , V_192 ) ;
V_192 ++ ;
V_194 -- ;
}
}
for ( V_59 = V_191 ; V_59 < V_163 ; V_59 ++ ) {
V_200 = F_134 ( V_196 , V_163 - V_59 ) ;
for ( V_198 = 0 ; V_198 < V_200 ; V_198 ++ ) {
F_132 ( V_2 , V_59 , V_193 ) ;
V_193 ++ ;
V_196 -- ;
}
}
V_202:
return V_201 ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_163 = V_2 -> V_164 - V_165 ;
int V_203 , V_201 ;
int V_204 = 0 , V_205 = 0 ;
for ( V_203 = 0 ; V_203 < V_163 ; V_203 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_203 ] ;
struct V_206 * V_207 = & V_2 -> V_208 [ V_203 ] ;
if ( V_53 -> V_70 . V_36 && V_53 -> V_148 . V_36 ) {
snprintf ( V_53 -> V_209 , sizeof( V_53 -> V_209 ) - 1 ,
L_12 , V_39 -> V_209 , L_13 , V_204 ++ ) ;
V_205 ++ ;
} else if ( V_53 -> V_148 . V_36 ) {
snprintf ( V_53 -> V_209 , sizeof( V_53 -> V_209 ) - 1 ,
L_12 , V_39 -> V_209 , L_14 , V_204 ++ ) ;
} else if ( V_53 -> V_70 . V_36 ) {
snprintf ( V_53 -> V_209 , sizeof( V_53 -> V_209 ) - 1 ,
L_12 , V_39 -> V_209 , L_15 , V_205 ++ ) ;
} else {
continue;
}
V_201 = F_136 ( V_207 -> V_203 , & F_129 , 0 ,
V_53 -> V_209 , V_53 ) ;
if ( V_201 ) {
F_137 ( & V_2 -> V_9 ,
L_16 ,
V_201 ) ;
goto V_210;
}
}
V_201 = F_136 ( V_2 -> V_208 [ V_203 ] . V_203 ,
& F_128 , 0 , V_39 -> V_209 , V_2 ) ;
if ( V_201 ) {
F_137 ( & V_2 -> V_9 , L_17 ,
V_201 ) ;
goto V_210;
}
return 0 ;
V_210:
while ( V_203 ) {
V_203 -- ;
F_138 ( V_2 -> V_208 [ V_203 ] . V_203 ,
V_2 -> V_53 [ V_203 ] ) ;
}
V_2 -> V_164 = 0 ;
return V_201 ;
}
static inline void F_139 ( struct V_1 * V_2 )
{
int V_59 , V_163 = V_2 -> V_164 - V_165 ;
for ( V_59 = 0 ; V_59 < V_163 ; V_59 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_59 ] ;
V_53 -> V_148 . V_36 = NULL ;
V_53 -> V_70 . V_36 = NULL ;
V_53 -> V_148 . V_43 = 0 ;
V_53 -> V_70 . V_43 = 0 ;
}
}
static int F_140 ( struct V_1 * V_2 )
{
int V_201 = 0 ;
V_201 = F_135 ( V_2 ) ;
if ( V_201 )
F_137 ( & V_2 -> V_9 , L_18 , V_201 ) ;
return V_201 ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_59 , V_163 ;
V_163 = V_2 -> V_164 ;
V_59 = V_163 - 1 ;
F_138 ( V_2 -> V_208 [ V_59 ] . V_203 , V_2 ) ;
V_59 -- ;
for (; V_59 >= 0 ; V_59 -- ) {
if ( ! V_2 -> V_53 [ V_59 ] -> V_148 . V_36 &&
! V_2 -> V_53 [ V_59 ] -> V_70 . V_36 )
continue;
F_138 ( V_2 -> V_208 [ V_59 ] . V_203 ,
V_2 -> V_53 [ V_59 ] ) ;
}
F_139 ( V_2 ) ;
}
static inline void F_142 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
F_19 ( V_9 , V_211 , 0 ) ;
F_19 ( V_9 , V_212 , ~ 0 ) ;
F_19 ( V_9 , V_213 , 0 ) ;
F_143 ( V_9 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_164 ; V_59 ++ )
F_144 ( V_2 -> V_208 [ V_59 ] . V_203 ) ;
}
static inline void F_145 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_19 ( V_9 , V_211 , V_2 -> V_166 ) ;
F_19 ( V_9 , V_213 , V_2 -> V_166 ) ;
F_19 ( V_9 , V_138 , V_2 -> V_166 ) ;
}
static void F_146 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_214 = V_36 -> V_33 ;
int V_215 = 10 ;
T_1 V_216 = V_217 ;
T_2 V_41 = V_36 -> V_41 ;
F_19 ( V_9 , F_147 ( V_41 ) , V_218 ) ;
F_143 ( V_9 ) ;
F_19 ( V_9 , F_148 ( V_41 ) , V_214 & F_149 ( 32 ) ) ;
F_19 ( V_9 , F_150 ( V_41 ) , V_214 >> 32 ) ;
F_19 ( V_9 , F_151 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_54 ) ) ;
F_19 ( V_9 , F_152 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_153 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_154 ( V_41 ) ,
( V_219 |
V_220 ) ) ;
F_19 ( V_9 , F_31 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_32 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_221 + F_32 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_216 |= ( 8 << 16 ) ;
V_216 |= ( 1 << 8 ) |
32 ;
F_8 ( V_48 , & V_36 -> V_4 ) ;
F_19 ( V_9 , F_147 ( V_41 ) , V_216 ) ;
do {
F_155 ( 1000 , 2000 ) ;
V_216 = F_18 ( V_9 , F_147 ( V_41 ) ) ;
} while ( -- V_215 && ! ( V_216 & V_217 ) );
if ( ! V_215 )
F_46 ( L_19 , V_41 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
T_1 V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ )
F_146 ( V_2 , V_2 -> V_28 [ V_59 ] ) ;
}
static void F_157 ( struct V_1 * V_2 , int V_24 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_222 ;
V_222 = V_223 ;
V_222 |= V_120 << V_224 ;
V_222 |= V_127 >> V_225 ;
V_222 |= V_226 ;
F_19 ( V_9 , F_158 ( V_24 ) , V_222 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_227 = V_228 | V_229 |
V_230 | V_231 |
V_232 ;
if ( V_2 -> V_195 > 1 )
V_227 |= 1 << 29 ;
F_19 ( V_9 , V_233 , V_227 ) ;
}
static void F_160 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_215 = V_234 ;
T_1 V_235 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
V_235 = F_18 ( V_9 , F_161 ( V_41 ) ) ;
V_235 &= ~ V_236 ;
F_19 ( V_9 , F_161 ( V_41 ) , V_235 ) ;
do {
F_162 ( 10 ) ;
V_235 = F_18 ( V_9 , F_161 ( V_41 ) ) ;
} while ( -- V_215 && ( V_235 & V_236 ) );
if ( ! V_215 )
F_46 ( L_20 ,
V_41 ) ;
}
static void F_163 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_215 = V_234 ;
T_1 V_235 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
do {
F_155 ( 1000 , 2000 ) ;
V_235 = F_18 ( V_9 , F_161 ( V_41 ) ) ;
} while ( -- V_215 && ! ( V_235 & V_236 ) );
if ( ! V_215 )
F_46 ( L_21 ,
V_41 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_237 = 0 , V_238 = 0 ;
T_1 V_239 [ 10 ] ;
T_6 V_240 = V_2 -> V_195 ;
int V_59 , V_198 ;
F_165 ( V_239 , sizeof( V_239 ) ) ;
for ( V_59 = 0 ; V_59 < 10 ; V_59 ++ )
F_19 ( V_9 , F_166 ( V_59 ) , V_239 [ V_59 ] ) ;
for ( V_59 = 0 , V_198 = 0 ; V_59 < 64 ; V_59 ++ , V_198 ++ ) {
if ( V_198 == V_240 )
V_198 = 0 ;
V_238 = ( V_238 << 8 ) | ( V_198 * 0x1 ) ;
if ( ( V_59 & 3 ) == 3 )
F_19 ( V_9 , F_167 ( V_59 >> 2 ) , V_238 ) ;
}
V_237 |= V_241 |
V_242 |
V_243 |
V_244 ;
V_237 |= V_245 ;
F_19 ( V_9 , V_246 , V_237 ) ;
}
static void F_168 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_247 = V_36 -> V_33 ;
T_1 V_235 ;
T_2 V_41 = V_36 -> V_41 ;
V_235 = F_18 ( V_9 , F_161 ( V_41 ) ) ;
F_160 ( V_2 , V_36 ) ;
F_19 ( V_9 , F_169 ( V_41 ) , V_247 & F_149 ( 32 ) ) ;
F_19 ( V_9 , F_170 ( V_41 ) , V_247 >> 32 ) ;
F_19 ( V_9 , F_171 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_78 ) ) ;
F_19 ( V_9 , F_172 ( V_41 ) ,
V_248 ) ;
F_19 ( V_9 , F_173 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_174 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_221 + F_174 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_36 -> V_114 = 0 ;
F_157 ( V_2 , V_41 ) ;
V_235 &= ~ V_249 ;
V_235 |= V_236 | V_250 ;
F_19 ( V_9 , F_161 ( V_41 ) , V_235 ) ;
F_163 ( V_2 , V_36 ) ;
F_75 ( V_36 , F_50 ( V_36 ) ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
int V_59 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
F_159 ( V_2 ) ;
if ( V_9 -> V_184 . type >= V_251 )
F_164 ( V_2 ) ;
F_176 ( V_9 , V_39 -> V_252 + V_253 + V_254 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ )
F_168 ( V_2 , V_2 -> V_90 [ V_59 ] ) ;
}
static int F_177 ( struct V_51 * V_39 ,
T_9 V_255 , T_6 V_92 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_201 ;
F_178 ( & V_2 -> V_256 ) ;
V_201 = V_9 -> V_184 . V_257 . V_258 ( V_9 , V_92 , 0 , true ) ;
F_179 ( & V_2 -> V_256 ) ;
if ( V_201 == V_259 )
return - V_260 ;
if ( V_201 == V_261 )
return - V_262 ;
F_180 ( V_92 , V_2 -> V_95 ) ;
return V_201 ;
}
static int F_181 ( struct V_51 * V_39 ,
T_9 V_255 , T_6 V_92 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_201 = - V_263 ;
F_178 ( & V_2 -> V_256 ) ;
V_201 = V_9 -> V_184 . V_257 . V_258 ( V_9 , V_92 , 0 , false ) ;
F_179 ( & V_2 -> V_256 ) ;
F_8 ( V_92 , V_2 -> V_95 ) ;
return V_201 ;
}
static void F_182 ( struct V_1 * V_2 )
{
T_6 V_92 ;
F_183 (vid, adapter->active_vlans, VLAN_N_VID)
F_177 ( V_2 -> V_39 ,
F_66 ( V_97 ) , V_92 ) ;
}
static int F_184 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_43 = 0 ;
if ( ( F_185 ( V_39 ) ) > 10 ) {
F_46 ( L_22 ) ;
return - V_264 ;
}
if ( ! F_186 ( V_39 ) ) {
struct V_265 * V_266 ;
F_187 (ha, netdev) {
V_9 -> V_184 . V_257 . V_267 ( V_9 , ++ V_43 , V_266 -> V_268 ) ;
F_162 ( 200 ) ;
}
} else {
V_9 -> V_184 . V_257 . V_267 ( V_9 , 0 , NULL ) ;
}
return V_43 ;
}
static void F_188 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_178 ( & V_2 -> V_256 ) ;
V_9 -> V_184 . V_257 . V_269 ( V_9 , V_39 ) ;
F_184 ( V_39 ) ;
F_179 ( & V_2 -> V_256 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
int V_270 ;
struct V_52 * V_53 ;
int V_163 = V_2 -> V_164 - V_165 ;
for ( V_270 = 0 ; V_270 < V_163 ; V_270 ++ ) {
V_53 = V_2 -> V_53 [ V_270 ] ;
#ifdef F_55
F_190 ( V_2 -> V_53 [ V_270 ] ) ;
#endif
F_191 ( & V_53 -> V_77 ) ;
}
}
static void F_192 ( struct V_1 * V_2 )
{
int V_270 ;
struct V_52 * V_53 ;
int V_163 = V_2 -> V_164 - V_165 ;
for ( V_270 = 0 ; V_270 < V_163 ; V_270 ++ ) {
V_53 = V_2 -> V_53 [ V_270 ] ;
F_193 ( & V_53 -> V_77 ) ;
#ifdef F_55
while ( ! F_194 ( V_2 -> V_53 [ V_270 ] ) ) {
F_195 ( L_23 , V_270 ) ;
F_155 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_271 = 0 ;
unsigned int V_272 = 0 ;
unsigned int V_195 = V_2 -> V_195 ;
unsigned int V_197 = V_2 -> V_197 ;
int V_201 ;
F_178 ( & V_2 -> V_256 ) ;
V_201 = F_197 ( V_9 , & V_272 , & V_271 ) ;
F_179 ( & V_2 -> V_256 ) ;
if ( V_201 )
return V_201 ;
if ( V_272 > 1 ) {
V_197 = 1 ;
V_2 -> V_28 [ 0 ] -> V_41 = V_271 ;
V_195 = V_272 ;
}
if ( ( V_2 -> V_195 != V_195 ) ||
( V_2 -> V_197 != V_197 ) ) {
V_9 -> V_273 . V_274 = 0 ;
V_2 -> V_49 |= V_275 ;
}
return 0 ;
}
static void F_198 ( struct V_1 * V_2 )
{
F_196 ( V_2 ) ;
F_188 ( V_2 -> V_39 ) ;
F_182 ( V_2 ) ;
F_156 ( V_2 ) ;
F_175 ( V_2 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 . V_276 || V_2 -> V_37 . V_277 ) {
V_2 -> V_37 . V_278 += V_2 -> V_37 . V_276 -
V_2 -> V_37 . V_279 ;
V_2 -> V_37 . V_280 += V_2 -> V_37 . V_277 -
V_2 -> V_37 . V_281 ;
V_2 -> V_37 . V_282 += V_2 -> V_37 . V_283 -
V_2 -> V_37 . V_284 ;
V_2 -> V_37 . V_285 += V_2 -> V_37 . V_286 -
V_2 -> V_37 . V_287 ;
V_2 -> V_37 . V_288 += V_2 -> V_37 . V_289 -
V_2 -> V_37 . V_290 ;
}
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
V_2 -> V_37 . V_291 = F_18 ( V_9 , V_292 ) ;
V_2 -> V_37 . V_293 = F_18 ( V_9 , V_294 ) ;
V_2 -> V_37 . V_293 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_295 ) ) ) << 32 ) ;
V_2 -> V_37 . V_296 = F_18 ( V_9 , V_297 ) ;
V_2 -> V_37 . V_298 = F_18 ( V_9 , V_299 ) ;
V_2 -> V_37 . V_298 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_300 ) ) ) << 32 ) ;
V_2 -> V_37 . V_301 = F_18 ( V_9 , V_302 ) ;
V_2 -> V_37 . V_279 = V_2 -> V_37 . V_291 ;
V_2 -> V_37 . V_284 = V_2 -> V_37 . V_293 ;
V_2 -> V_37 . V_281 = V_2 -> V_37 . V_296 ;
V_2 -> V_37 . V_287 = V_2 -> V_37 . V_298 ;
V_2 -> V_37 . V_290 = V_2 -> V_37 . V_301 ;
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_303 [] = { V_304 ,
V_305 ,
V_306 ,
V_307 } ;
int V_201 = 0 , V_308 = 0 ;
F_178 ( & V_2 -> V_256 ) ;
while ( V_303 [ V_308 ] != V_307 ) {
V_201 = F_202 ( V_9 , V_303 [ V_308 ] ) ;
if ( ! V_201 )
break;
V_308 ++ ;
}
F_179 ( & V_2 -> V_256 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_126 ( V_2 ) ;
F_178 ( & V_2 -> V_256 ) ;
if ( F_204 ( V_9 -> V_184 . V_268 ) )
V_9 -> V_184 . V_257 . V_309 ( V_9 , 0 , V_9 -> V_184 . V_268 , 0 ) ;
else
V_9 -> V_184 . V_257 . V_309 ( V_9 , 0 , V_9 -> V_184 . V_310 , 0 ) ;
F_179 ( & V_2 -> V_256 ) ;
F_7 () ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_189 ( V_2 ) ;
F_18 ( V_9 , V_311 ) ;
F_145 ( V_2 ) ;
F_205 ( V_39 ) ;
F_199 ( V_2 ) ;
F_200 ( V_2 ) ;
V_9 -> V_184 . V_185 = 1 ;
F_206 ( & V_2 -> V_312 , V_74 ) ;
}
void F_207 ( struct V_1 * V_2 )
{
F_198 ( V_2 ) ;
F_203 ( V_2 ) ;
}
static void F_208 ( struct V_27 * V_90 )
{
struct V_313 * V_13 = V_90 -> V_13 ;
unsigned long V_129 ;
unsigned int V_59 ;
if ( V_90 -> V_31 ) {
F_209 ( V_90 -> V_31 ) ;
V_90 -> V_31 = NULL ;
}
if ( ! V_90 -> V_110 )
return;
for ( V_59 = 0 ; V_59 < V_90 -> V_43 ; V_59 ++ ) {
struct V_101 * V_128 ;
V_128 = & V_90 -> V_110 [ V_59 ] ;
if ( V_128 -> V_33 )
F_26 ( V_13 , V_128 -> V_33 ,
V_105 , V_106 ) ;
V_128 -> V_33 = 0 ;
if ( V_128 -> V_103 )
F_74 ( V_128 -> V_103 ) ;
V_128 -> V_103 = NULL ;
}
V_129 = sizeof( struct V_101 ) * V_90 -> V_43 ;
memset ( V_90 -> V_110 , 0 , V_129 ) ;
memset ( V_90 -> V_314 , 0 , V_90 -> V_129 ) ;
}
static void F_210 ( struct V_27 * V_28 )
{
struct V_29 * V_61 ;
unsigned long V_129 ;
unsigned int V_59 ;
if ( ! V_28 -> V_61 )
return;
for ( V_59 = 0 ; V_59 < V_28 -> V_43 ; V_59 ++ ) {
V_61 = & V_28 -> V_61 [ V_59 ] ;
F_21 ( V_28 , V_61 ) ;
}
V_129 = sizeof( struct V_29 ) * V_28 -> V_43 ;
memset ( V_28 -> V_61 , 0 , V_129 ) ;
memset ( V_28 -> V_314 , 0 , V_28 -> V_129 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ )
F_208 ( V_2 -> V_90 [ V_59 ] ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ )
F_210 ( V_2 -> V_28 [ V_59 ] ) ;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ )
F_160 ( V_2 , V_2 -> V_90 [ V_59 ] ) ;
F_155 ( 10000 , 20000 ) ;
F_214 ( V_39 ) ;
F_215 ( V_39 ) ;
F_216 ( V_39 ) ;
F_142 ( V_2 ) ;
F_192 ( V_2 ) ;
F_217 ( & V_2 -> V_312 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ ) {
T_2 V_41 = V_2 -> V_28 [ V_59 ] -> V_41 ;
F_19 ( V_9 , F_147 ( V_41 ) ,
V_218 ) ;
}
if ( ! F_218 ( V_2 -> V_12 ) )
F_219 ( V_2 ) ;
F_212 ( V_2 ) ;
F_211 ( V_2 ) ;
}
void F_220 ( struct V_1 * V_2 )
{
F_221 ( F_222 () ) ;
while ( F_3 ( V_315 , & V_2 -> V_4 ) )
F_223 ( 1 ) ;
F_213 ( V_2 ) ;
F_207 ( V_2 ) ;
F_8 ( V_315 , & V_2 -> V_4 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
if ( V_9 -> V_184 . V_257 . V_316 ( V_9 ) ) {
F_137 ( V_9 , L_24 ) ;
} else {
V_9 -> V_184 . V_257 . V_317 ( V_9 ) ;
F_201 ( V_2 ) ;
}
if ( F_204 ( V_2 -> V_9 . V_184 . V_268 ) ) {
memcpy ( V_39 -> V_146 , V_2 -> V_9 . V_184 . V_268 ,
V_39 -> V_318 ) ;
memcpy ( V_39 -> V_310 , V_2 -> V_9 . V_184 . V_268 ,
V_39 -> V_318 ) ;
}
V_2 -> V_319 = V_74 ;
}
static int F_224 ( struct V_1 * V_2 ,
int V_320 )
{
int V_321 ;
V_321 = V_322 ;
V_320 = F_225 ( V_2 -> V_12 , V_2 -> V_208 ,
V_321 , V_320 ) ;
if ( V_320 < 0 ) {
F_10 ( & V_2 -> V_12 -> V_13 ,
L_25 ) ;
F_226 ( V_2 -> V_208 ) ;
V_2 -> V_208 = NULL ;
return V_320 ;
}
V_2 -> V_164 = V_320 ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_271 = 0 ;
unsigned int V_272 = 0 ;
int V_201 ;
V_2 -> V_195 = 1 ;
V_2 -> V_197 = 1 ;
F_178 ( & V_2 -> V_256 ) ;
V_201 = F_197 ( V_9 , & V_272 , & V_271 ) ;
F_179 ( & V_2 -> V_256 ) ;
if ( V_201 )
return;
if ( V_272 > 1 ) {
V_2 -> V_195 = V_272 ;
} else {
T_6 V_323 = F_228 ( T_6 , F_229 () , V_324 ) ;
switch ( V_9 -> V_325 ) {
case V_305 :
case V_304 :
V_2 -> V_195 = V_323 ;
V_2 -> V_197 = V_323 ;
default:
break;
}
}
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_27 * V_36 ;
int V_148 = 0 , V_70 = 0 ;
for (; V_70 < V_2 -> V_197 ; V_70 ++ ) {
V_36 = F_231 ( sizeof( * V_36 ) , V_326 ) ;
if ( ! V_36 )
goto V_327;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_328 ;
V_36 -> V_71 = V_70 ;
V_36 -> V_41 = V_70 ;
V_2 -> V_28 [ V_70 ] = V_36 ;
}
for (; V_148 < V_2 -> V_195 ; V_148 ++ ) {
V_36 = F_231 ( sizeof( * V_36 ) , V_326 ) ;
if ( ! V_36 )
goto V_327;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_329 ;
V_36 -> V_71 = V_148 ;
V_36 -> V_41 = V_148 ;
V_2 -> V_90 [ V_148 ] = V_36 ;
}
return 0 ;
V_327:
while ( V_70 ) {
F_226 ( V_2 -> V_28 [ -- V_70 ] ) ;
V_2 -> V_28 [ V_70 ] = NULL ;
}
while ( V_148 ) {
F_226 ( V_2 -> V_90 [ -- V_148 ] ) ;
V_2 -> V_90 [ V_148 ] = NULL ;
}
return - V_330 ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_201 = 0 ;
int V_203 , V_331 ;
V_331 = F_116 ( V_2 -> V_195 , V_2 -> V_197 ) ;
V_331 = F_228 ( int , V_331 , F_229 () ) ;
V_331 += V_165 ;
V_2 -> V_208 = F_233 ( V_331 ,
sizeof( struct V_206 ) , V_326 ) ;
if ( ! V_2 -> V_208 ) {
V_201 = - V_330 ;
goto V_202;
}
for ( V_203 = 0 ; V_203 < V_331 ; V_203 ++ )
V_2 -> V_208 [ V_203 ] . V_207 = V_203 ;
V_201 = F_224 ( V_2 , V_331 ) ;
if ( V_201 )
goto V_202;
V_201 = F_234 ( V_39 , V_2 -> V_197 ) ;
if ( V_201 )
goto V_202;
V_201 = F_235 ( V_39 , V_2 -> V_195 ) ;
V_202:
return V_201 ;
}
static int F_236 ( struct V_1 * V_2 )
{
int V_270 , V_332 ;
struct V_52 * V_53 ;
V_332 = V_2 -> V_164 - V_165 ;
for ( V_270 = 0 ; V_270 < V_332 ; V_270 ++ ) {
V_53 = F_231 ( sizeof( struct V_52 ) , V_326 ) ;
if ( ! V_53 )
goto V_333;
V_53 -> V_2 = V_2 ;
V_53 -> V_153 = V_270 ;
F_237 ( V_2 -> V_39 , & V_53 -> V_77 ,
F_112 , 64 ) ;
#ifdef F_55
F_238 ( & V_53 -> V_77 ) ;
#endif
V_2 -> V_53 [ V_270 ] = V_53 ;
}
return 0 ;
V_333:
while ( V_270 ) {
V_270 -- ;
V_53 = V_2 -> V_53 [ V_270 ] ;
#ifdef F_55
F_239 ( & V_53 -> V_77 ) ;
#endif
F_240 ( & V_53 -> V_77 ) ;
F_226 ( V_53 ) ;
V_2 -> V_53 [ V_270 ] = NULL ;
}
return - V_330 ;
}
static void F_241 ( struct V_1 * V_2 )
{
int V_270 , V_332 = V_2 -> V_164 - V_165 ;
for ( V_270 = 0 ; V_270 < V_332 ; V_270 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_270 ] ;
V_2 -> V_53 [ V_270 ] = NULL ;
#ifdef F_55
F_239 ( & V_53 -> V_77 ) ;
#endif
F_240 ( & V_53 -> V_77 ) ;
F_226 ( V_53 ) ;
}
}
static void F_242 ( struct V_1 * V_2 )
{
F_243 ( V_2 -> V_12 ) ;
F_226 ( V_2 -> V_208 ) ;
V_2 -> V_208 = NULL ;
}
static int F_244 ( struct V_1 * V_2 )
{
int V_201 ;
F_227 ( V_2 ) ;
V_201 = F_232 ( V_2 ) ;
if ( V_201 ) {
F_137 ( & V_2 -> V_9 ,
L_26 ) ;
goto V_334;
}
V_201 = F_236 ( V_2 ) ;
if ( V_201 ) {
F_137 ( & V_2 -> V_9 , L_27 ) ;
goto V_335;
}
V_201 = F_230 ( V_2 ) ;
if ( V_201 ) {
F_46 ( L_28 ) ;
goto V_336;
}
F_137 ( & V_2 -> V_9 , L_29 ,
( V_2 -> V_195 > 1 ) ? L_30 :
L_31 , V_2 -> V_195 , V_2 -> V_197 ) ;
F_180 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_336:
F_241 ( V_2 ) ;
V_335:
F_242 ( V_2 ) ;
V_334:
return V_201 ;
}
static void F_245 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ ) {
F_226 ( V_2 -> V_28 [ V_59 ] ) ;
V_2 -> V_28 [ V_59 ] = NULL ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ ) {
F_226 ( V_2 -> V_90 [ V_59 ] ) ;
V_2 -> V_90 [ V_59 ] = NULL ;
}
V_2 -> V_197 = 0 ;
V_2 -> V_195 = 0 ;
F_241 ( V_2 ) ;
F_242 ( V_2 ) ;
}
static int F_246 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_337 * V_12 = V_2 -> V_12 ;
struct V_51 * V_39 = V_2 -> V_39 ;
int V_201 ;
V_9 -> V_338 = V_12 -> V_339 ;
V_9 -> V_340 = V_12 -> V_313 ;
V_9 -> V_341 = V_12 -> V_342 ;
V_9 -> V_343 = V_12 -> V_344 ;
V_9 -> V_345 = V_12 -> V_346 ;
V_9 -> V_273 . V_257 . V_347 ( V_9 ) ;
V_9 -> V_184 . V_348 = 2 ;
V_9 -> V_184 . V_349 = 2 ;
F_247 ( & V_2 -> V_256 ) ;
V_201 = V_9 -> V_184 . V_257 . V_316 ( V_9 ) ;
if ( V_201 ) {
F_248 ( & V_12 -> V_13 ,
L_32 ) ;
} else {
V_201 = V_9 -> V_184 . V_257 . V_317 ( V_9 ) ;
if ( V_201 ) {
F_46 ( L_33 , V_201 ) ;
goto V_202;
}
F_201 ( V_2 ) ;
V_201 = V_9 -> V_184 . V_257 . V_350 ( V_9 , V_9 -> V_184 . V_268 ) ;
if ( V_201 )
F_248 ( & V_12 -> V_13 , L_34 ) ;
else if ( F_249 ( V_2 -> V_9 . V_184 . V_268 ) )
F_248 ( & V_12 -> V_13 ,
L_35 ) ;
memcpy ( V_39 -> V_146 , V_9 -> V_184 . V_268 , V_39 -> V_318 ) ;
}
if ( ! F_204 ( V_39 -> V_146 ) ) {
F_248 ( & V_12 -> V_13 , L_36 ) ;
F_250 ( V_39 ) ;
memcpy ( V_9 -> V_184 . V_268 , V_39 -> V_146 , V_39 -> V_318 ) ;
}
V_2 -> V_152 = 1 ;
V_2 -> V_167 = 1 ;
V_2 -> V_328 = V_351 ;
V_2 -> V_329 = V_352 ;
F_180 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_202:
return V_201 ;
}
void F_251 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_315 , & V_2 -> V_4 ) )
return;
F_252 ( V_292 , V_2 -> V_37 . V_291 ,
V_2 -> V_37 . V_276 ) ;
F_252 ( V_297 , V_2 -> V_37 . V_296 ,
V_2 -> V_37 . V_277 ) ;
F_253 ( V_294 , V_295 ,
V_2 -> V_37 . V_293 ,
V_2 -> V_37 . V_283 ) ;
F_253 ( V_299 , V_300 ,
V_2 -> V_37 . V_298 ,
V_2 -> V_37 . V_286 ) ;
F_252 ( V_302 , V_2 -> V_37 . V_301 ,
V_2 -> V_37 . V_289 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ ) {
V_2 -> V_353 +=
V_2 -> V_90 [ V_59 ] -> V_353 ;
V_2 -> V_90 [ V_59 ] -> V_353 = 0 ;
}
}
static void F_254 ( unsigned long V_136 )
{
struct V_1 * V_2 = (struct V_1 * ) V_136 ;
F_206 ( & V_2 -> V_312 , ( V_354 * 2 ) + V_74 ) ;
F_1 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_49 & V_50 ) )
return;
V_2 -> V_49 &= ~ V_50 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_315 , & V_2 -> V_4 ) )
return;
V_2 -> V_355 ++ ;
F_220 ( V_2 ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_356 = 0 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_315 , & V_2 -> V_4 ) )
return;
if ( F_49 ( V_2 -> V_39 ) ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ )
F_257 ( V_2 -> V_28 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_164 - V_165 ; V_59 ++ ) {
struct V_52 * V_357 = V_2 -> V_53 [ V_59 ] ;
if ( V_357 -> V_148 . V_36 || V_357 -> V_70 . V_36 )
V_356 |= 1 << V_59 ;
}
F_19 ( V_9 , V_358 , V_356 ) ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_359 = V_2 -> V_359 ;
bool V_360 = V_2 -> V_360 ;
T_10 V_201 ;
F_178 ( & V_2 -> V_256 ) ;
V_201 = V_9 -> V_184 . V_257 . V_361 ( V_9 , & V_359 , & V_360 , false ) ;
F_179 ( & V_2 -> V_256 ) ;
if ( V_201 && F_259 ( V_74 , V_2 -> V_319 + ( 10 * V_354 ) ) ) {
V_2 -> V_49 |= V_50 ;
V_360 = false ;
}
V_2 -> V_360 = V_360 ;
V_2 -> V_359 = V_359 ;
}
static void F_260 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
if ( F_49 ( V_39 ) )
return;
F_248 ( & V_2 -> V_12 -> V_13 , L_37 ,
( V_2 -> V_359 == V_362 ) ?
L_38 :
( V_2 -> V_359 == V_363 ) ?
L_39 :
( V_2 -> V_359 == V_364 ) ?
L_40 :
L_41 ) ;
F_261 ( V_39 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
V_2 -> V_359 = 0 ;
if ( ! F_49 ( V_39 ) )
return;
F_248 ( & V_2 -> V_12 -> V_13 , L_42 ) ;
F_215 ( V_39 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_315 , & V_2 -> V_4 ) )
return;
F_258 ( V_2 ) ;
if ( V_2 -> V_360 )
F_260 ( V_2 ) ;
else
F_262 ( V_2 ) ;
F_251 ( V_2 ) ;
}
static void F_264 ( struct V_365 * V_366 )
{
struct V_1 * V_2 = F_113 ( V_366 ,
struct V_1 ,
V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( F_14 ( V_9 -> V_11 ) ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_265 () ;
F_213 ( V_2 ) ;
F_266 () ;
}
return;
}
F_267 ( V_2 ) ;
F_255 ( V_2 ) ;
F_263 ( V_2 ) ;
F_256 ( V_2 ) ;
F_5 ( V_2 ) ;
}
void F_268 ( struct V_27 * V_28 )
{
F_210 ( V_28 ) ;
F_269 ( V_28 -> V_61 ) ;
V_28 -> V_61 = NULL ;
if ( ! V_28 -> V_314 )
return;
F_270 ( V_28 -> V_13 , V_28 -> V_129 , V_28 -> V_314 ,
V_28 -> V_33 ) ;
V_28 -> V_314 = NULL ;
}
static void F_271 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ )
if ( V_2 -> V_28 [ V_59 ] -> V_314 )
F_268 ( V_2 -> V_28 [ V_59 ] ) ;
}
int F_272 ( struct V_27 * V_28 )
{
int V_129 ;
V_129 = sizeof( struct V_29 ) * V_28 -> V_43 ;
V_28 -> V_61 = F_273 ( V_129 ) ;
if ( ! V_28 -> V_61 )
goto V_201;
V_28 -> V_129 = V_28 -> V_43 * sizeof( union V_54 ) ;
V_28 -> V_129 = F_84 ( V_28 -> V_129 , 4096 ) ;
V_28 -> V_314 = F_274 ( V_28 -> V_13 , V_28 -> V_129 ,
& V_28 -> V_33 , V_326 ) ;
if ( ! V_28 -> V_314 )
goto V_201;
return 0 ;
V_201:
F_269 ( V_28 -> V_61 ) ;
V_28 -> V_61 = NULL ;
F_137 ( & V_2 -> V_9 , L_43 ) ;
return - V_330 ;
}
static int F_275 ( struct V_1 * V_2 )
{
int V_59 , V_201 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ ) {
V_201 = F_272 ( V_2 -> V_28 [ V_59 ] ) ;
if ( ! V_201 )
continue;
F_137 ( & V_2 -> V_9 , L_44 , V_59 ) ;
break;
}
return V_201 ;
}
int F_276 ( struct V_27 * V_90 )
{
int V_129 ;
V_129 = sizeof( struct V_101 ) * V_90 -> V_43 ;
V_90 -> V_110 = F_273 ( V_129 ) ;
if ( ! V_90 -> V_110 )
goto V_201;
V_90 -> V_129 = V_90 -> V_43 * sizeof( union V_78 ) ;
V_90 -> V_129 = F_84 ( V_90 -> V_129 , 4096 ) ;
V_90 -> V_314 = F_274 ( V_90 -> V_13 , V_90 -> V_129 ,
& V_90 -> V_33 , V_326 ) ;
if ( ! V_90 -> V_314 )
goto V_201;
return 0 ;
V_201:
F_269 ( V_90 -> V_110 ) ;
V_90 -> V_110 = NULL ;
F_10 ( V_90 -> V_13 , L_45 ) ;
return - V_330 ;
}
static int F_277 ( struct V_1 * V_2 )
{
int V_59 , V_201 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ ) {
V_201 = F_276 ( V_2 -> V_90 [ V_59 ] ) ;
if ( ! V_201 )
continue;
F_137 ( & V_2 -> V_9 , L_46 , V_59 ) ;
break;
}
return V_201 ;
}
void F_278 ( struct V_27 * V_90 )
{
F_208 ( V_90 ) ;
F_269 ( V_90 -> V_110 ) ;
V_90 -> V_110 = NULL ;
F_270 ( V_90 -> V_13 , V_90 -> V_129 , V_90 -> V_314 ,
V_90 -> V_33 ) ;
V_90 -> V_314 = NULL ;
}
static void F_279 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ )
if ( V_2 -> V_90 [ V_59 ] -> V_314 )
F_278 ( V_2 -> V_90 [ V_59 ] ) ;
}
static int F_280 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_201 ;
if ( ! V_2 -> V_164 )
return - V_330 ;
if ( V_9 -> V_367 ) {
F_219 ( V_2 ) ;
if ( V_9 -> V_367 ) {
V_201 = V_259 ;
F_46 ( L_47 ) ;
goto V_368;
}
}
if ( F_2 ( V_369 , & V_2 -> V_4 ) )
return - V_370 ;
F_215 ( V_39 ) ;
V_201 = F_275 ( V_2 ) ;
if ( V_201 )
goto V_371;
V_201 = F_277 ( V_2 ) ;
if ( V_201 )
goto V_372;
F_198 ( V_2 ) ;
F_133 ( V_2 ) ;
V_201 = F_140 ( V_2 ) ;
if ( V_201 )
goto V_373;
F_203 ( V_2 ) ;
return 0 ;
V_373:
F_213 ( V_2 ) ;
V_372:
F_279 ( V_2 ) ;
V_371:
F_271 ( V_2 ) ;
F_219 ( V_2 ) ;
V_368:
return V_201 ;
}
static int F_281 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
F_213 ( V_2 ) ;
F_141 ( V_2 ) ;
F_271 ( V_2 ) ;
F_279 ( V_2 ) ;
return 0 ;
}
static void F_267 ( struct V_1 * V_2 )
{
struct V_51 * V_13 = V_2 -> V_39 ;
if ( ! ( V_2 -> V_49 & V_275 ) )
return;
V_2 -> V_49 &= ~ V_275 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_315 , & V_2 -> V_4 ) )
return;
if ( F_282 ( V_13 ) )
F_281 ( V_13 ) ;
F_245 ( V_2 ) ;
F_244 ( V_2 ) ;
if ( F_282 ( V_13 ) )
F_280 ( V_13 ) ;
}
static void F_283 ( struct V_27 * V_28 ,
T_1 V_374 , T_1 V_375 ,
T_1 V_376 )
{
struct V_377 * V_378 ;
T_6 V_59 = V_28 -> V_72 ;
V_378 = F_284 ( V_28 , V_59 ) ;
V_59 ++ ;
V_28 -> V_72 = ( V_59 < V_28 -> V_43 ) ? V_59 : 0 ;
V_375 |= V_379 | V_380 ;
V_378 -> V_374 = F_40 ( V_374 ) ;
V_378 -> V_381 = 0 ;
V_378 -> V_382 = F_40 ( V_375 ) ;
V_378 -> V_376 = F_40 ( V_376 ) ;
}
static int F_285 ( struct V_27 * V_28 ,
struct V_29 * V_383 ,
T_2 * V_384 )
{
struct V_76 * V_31 = V_383 -> V_31 ;
T_1 V_374 , V_375 ;
T_1 V_376 , V_385 ;
int V_201 ;
if ( V_31 -> V_88 != V_386 )
return 0 ;
if ( ! F_286 ( V_31 ) )
return 0 ;
V_201 = F_287 ( V_31 , 0 ) ;
if ( V_201 < 0 )
return V_201 ;
V_375 = V_387 ;
if ( V_383 -> V_98 == F_66 ( V_388 ) ) {
struct V_389 * V_390 = F_288 ( V_31 ) ;
V_390 -> V_391 = 0 ;
V_390 -> V_392 = 0 ;
F_289 ( V_31 ) -> V_392 = ~ F_290 ( V_390 -> V_393 ,
V_390 -> V_394 , 0 ,
V_395 ,
0 ) ;
V_375 |= V_396 ;
V_383 -> V_397 |= V_398 |
V_399 |
V_400 ;
} else if ( F_291 ( V_31 ) ) {
F_292 ( V_31 ) -> V_401 = 0 ;
F_289 ( V_31 ) -> V_392 =
~ F_293 ( & F_292 ( V_31 ) -> V_393 ,
& F_292 ( V_31 ) -> V_394 ,
0 , V_395 , 0 ) ;
V_383 -> V_397 |= V_398 |
V_399 ;
}
V_385 = F_294 ( V_31 ) ;
* V_384 += V_385 ;
* V_384 = F_295 ( V_31 ) + V_385 ;
V_383 -> V_67 = F_80 ( V_31 ) -> V_67 ;
V_383 -> V_66 += ( V_383 -> V_67 - 1 ) * * V_384 ;
V_376 = V_385 << V_402 ;
V_376 |= F_80 ( V_31 ) -> V_403 << V_404 ;
V_376 |= 1 << V_405 ;
V_374 = F_296 ( V_31 ) ;
V_374 |= F_297 ( V_31 ) << V_406 ;
V_374 |= V_383 -> V_397 & V_407 ;
F_283 ( V_28 , V_374 ,
V_375 , V_376 ) ;
return 1 ;
}
static void F_298 ( struct V_27 * V_28 ,
struct V_29 * V_383 )
{
struct V_76 * V_31 = V_383 -> V_31 ;
T_1 V_374 = 0 ;
T_1 V_376 = 0 ;
T_1 V_375 = 0 ;
if ( V_31 -> V_88 == V_386 ) {
T_2 V_408 = 0 ;
switch ( V_383 -> V_98 ) {
case F_66 ( V_388 ) :
V_374 |= F_296 ( V_31 ) ;
V_375 |= V_396 ;
V_408 = F_288 ( V_31 ) -> V_98 ;
break;
case F_66 ( V_409 ) :
V_374 |= F_296 ( V_31 ) ;
V_408 = F_292 ( V_31 ) -> V_410 ;
break;
default:
if ( F_16 ( F_299 () ) ) {
F_300 ( V_28 -> V_13 ,
L_48 ,
V_383 -> V_98 ) ;
}
break;
}
switch ( V_408 ) {
case V_395 :
V_375 |= V_387 ;
V_376 = F_294 ( V_31 ) <<
V_402 ;
break;
case V_411 :
V_375 |= V_412 ;
V_376 = sizeof( struct V_413 ) <<
V_402 ;
break;
case V_414 :
V_376 = sizeof( struct V_415 ) <<
V_402 ;
break;
default:
if ( F_16 ( F_299 () ) ) {
F_300 ( V_28 -> V_13 ,
L_49 ,
V_408 ) ;
}
break;
}
V_383 -> V_397 |= V_399 ;
}
V_374 |= F_297 ( V_31 ) << V_406 ;
V_374 |= V_383 -> V_397 & V_407 ;
F_283 ( V_28 , V_374 ,
V_375 , V_376 ) ;
}
static T_11 F_301 ( T_1 V_397 )
{
T_11 V_416 = F_40 ( V_417 |
V_418 |
V_419 ) ;
if ( V_397 & V_420 )
V_416 |= F_40 ( V_421 ) ;
if ( V_397 & V_398 )
V_416 |= F_40 ( V_422 ) ;
return V_416 ;
}
static void F_302 ( union V_54 * V_55 ,
T_1 V_397 , unsigned int V_423 )
{
T_11 V_424 = F_40 ( V_423 << V_425 ) ;
if ( V_397 & V_399 )
V_424 |= F_40 ( V_426 ) ;
if ( V_397 & V_400 )
V_424 |= F_40 ( V_427 ) ;
if ( V_397 & V_398 )
V_424 |= F_40 ( 1 << V_405 ) ;
V_424 |= F_40 ( V_428 ) ;
V_55 -> V_111 . V_424 = V_424 ;
}
static void F_303 ( struct V_27 * V_28 ,
struct V_29 * V_383 ,
const T_2 V_384 )
{
T_7 V_33 ;
struct V_76 * V_31 = V_383 -> V_31 ;
struct V_29 * V_30 ;
union V_54 * V_55 ;
struct V_115 * V_116 = & F_80 ( V_31 ) -> V_117 [ 0 ] ;
unsigned int V_121 = V_31 -> V_121 ;
unsigned int V_129 = F_304 ( V_31 ) ;
unsigned int V_423 = V_31 -> V_32 - V_384 ;
T_1 V_397 = V_383 -> V_397 ;
T_11 V_416 ;
T_6 V_59 = V_28 -> V_72 ;
V_55 = F_38 ( V_28 , V_59 ) ;
F_302 ( V_55 , V_397 , V_423 ) ;
V_416 = F_301 ( V_397 ) ;
V_33 = F_305 ( V_28 -> V_13 , V_31 -> V_136 , V_129 , V_34 ) ;
if ( F_73 ( V_28 -> V_13 , V_33 ) )
goto V_429;
F_27 ( V_383 , V_32 , V_129 ) ;
F_306 ( V_383 , V_33 , V_33 ) ;
V_55 -> V_111 . V_430 = F_76 ( V_33 ) ;
for (; ; ) {
while ( F_16 ( V_129 > V_431 ) ) {
V_55 -> V_111 . V_432 =
V_416 | F_40 ( V_431 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_33 += V_431 ;
V_129 -= V_431 ;
V_55 -> V_111 . V_430 = F_76 ( V_33 ) ;
V_55 -> V_111 . V_424 = 0 ;
}
if ( F_42 ( ! V_121 ) )
break;
V_55 -> V_111 . V_432 = V_416 | F_40 ( V_129 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_129 = F_307 ( V_116 ) ;
V_121 -= V_129 ;
V_33 = F_308 ( V_28 -> V_13 , V_116 , 0 , V_129 ,
V_34 ) ;
if ( F_73 ( V_28 -> V_13 , V_33 ) )
goto V_429;
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_27 ( V_30 , V_32 , V_129 ) ;
F_306 ( V_30 , V_33 , V_33 ) ;
V_55 -> V_111 . V_430 = F_76 ( V_33 ) ;
V_55 -> V_111 . V_424 = 0 ;
V_116 ++ ;
}
V_416 |= F_40 ( V_129 ) | F_40 ( V_433 ) ;
V_55 -> V_111 . V_432 = V_416 ;
V_383 -> V_73 = V_74 ;
F_77 () ;
V_383 -> V_35 = V_55 ;
V_59 ++ ;
if ( V_59 == V_28 -> V_43 )
V_59 = 0 ;
V_28 -> V_72 = V_59 ;
F_78 ( V_28 , V_59 ) ;
return;
V_429:
F_10 ( V_28 -> V_13 , L_50 ) ;
for (; ; ) {
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_21 ( V_28 , V_30 ) ;
if ( V_30 == V_383 )
break;
if ( V_59 == 0 )
V_59 = V_28 -> V_43 ;
V_59 -- ;
}
V_28 -> V_72 = V_59 ;
}
static int F_309 ( struct V_27 * V_28 , int V_129 )
{
F_47 ( V_28 -> V_39 , V_28 -> V_71 ) ;
F_51 () ;
if ( F_42 ( F_50 ( V_28 ) < V_129 ) )
return - V_370 ;
F_310 ( V_28 -> V_39 , V_28 -> V_71 ) ;
++ V_28 -> V_46 . V_75 ;
return 0 ;
}
static int F_311 ( struct V_27 * V_28 , int V_129 )
{
if ( F_42 ( F_50 ( V_28 ) >= V_129 ) )
return 0 ;
return F_309 ( V_28 , V_129 ) ;
}
static int F_312 ( struct V_76 * V_31 , struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_29 * V_383 ;
struct V_27 * V_28 ;
int V_434 ;
T_1 V_397 = 0 ;
T_6 V_43 = F_313 ( F_304 ( V_31 ) ) ;
#if V_105 > V_431
unsigned short V_435 ;
#endif
T_2 V_384 = 0 ;
T_2 * V_436 = F_314 ( V_31 , 0 , 0 , NULL ) ;
if ( ! V_436 || F_315 ( V_436 ) ) {
F_22 ( V_31 ) ;
return V_437 ;
}
V_28 = V_2 -> V_28 [ V_31 -> V_438 ] ;
#if V_105 > V_431
for ( V_435 = 0 ; V_435 < F_80 ( V_31 ) -> V_133 ; V_435 ++ )
V_43 += F_313 ( F_80 ( V_31 ) -> V_117 [ V_435 ] . V_129 ) ;
#else
V_43 += F_80 ( V_31 ) -> V_133 ;
#endif
if ( F_311 ( V_28 , V_43 + 3 ) ) {
V_28 -> V_46 . V_439 ++ ;
return V_440 ;
}
V_383 = & V_28 -> V_61 [ V_28 -> V_72 ] ;
V_383 -> V_31 = V_31 ;
V_383 -> V_66 = V_31 -> V_32 ;
V_383 -> V_67 = 1 ;
if ( F_316 ( V_31 ) ) {
V_397 |= F_317 ( V_31 ) ;
V_397 <<= V_441 ;
V_397 |= V_420 ;
}
V_383 -> V_397 = V_397 ;
V_383 -> V_98 = F_318 ( V_31 ) ;
V_434 = F_285 ( V_28 , V_383 , & V_384 ) ;
if ( V_434 < 0 )
goto V_442;
else if ( ! V_434 )
F_298 ( V_28 , V_383 ) ;
F_303 ( V_28 , V_383 , V_384 ) ;
F_311 ( V_28 , V_443 ) ;
return V_437 ;
V_442:
F_22 ( V_383 -> V_31 ) ;
V_383 -> V_31 = NULL ;
return V_437 ;
}
static int F_319 ( struct V_51 * V_39 , void * V_444 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_445 * V_268 = V_444 ;
if ( ! F_204 ( V_268 -> V_446 ) )
return - V_447 ;
memcpy ( V_39 -> V_146 , V_268 -> V_446 , V_39 -> V_318 ) ;
memcpy ( V_9 -> V_184 . V_268 , V_268 -> V_446 , V_39 -> V_318 ) ;
F_178 ( & V_2 -> V_256 ) ;
V_9 -> V_184 . V_257 . V_309 ( V_9 , 0 , V_9 -> V_184 . V_268 , 0 ) ;
F_179 ( & V_2 -> V_256 ) ;
return 0 ;
}
static int F_320 ( struct V_51 * V_39 , int V_448 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_449 = V_448 + V_253 + V_254 ;
int V_450 = V_451 ;
switch ( V_2 -> V_9 . V_325 ) {
case V_305 :
case V_304 :
V_450 = V_452 ;
break;
default:
if ( V_2 -> V_9 . V_184 . type != V_453 )
V_450 = V_452 ;
break;
}
if ( ( V_448 < 68 ) || ( V_449 > V_450 ) )
return - V_454 ;
F_137 ( V_9 , L_51 ,
V_39 -> V_252 , V_448 ) ;
V_39 -> V_252 = V_448 ;
F_176 ( V_9 , V_449 ) ;
return 0 ;
}
static void F_321 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ )
F_129 ( 0 , V_2 -> V_53 [ V_59 ] ) ;
}
static int F_322 ( struct V_337 * V_12 , T_12 V_4 )
{
struct V_51 * V_39 = F_323 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
#ifdef F_324
int V_455 = 0 ;
#endif
F_325 ( V_39 ) ;
if ( F_282 ( V_39 ) ) {
F_265 () ;
F_213 ( V_2 ) ;
F_141 ( V_2 ) ;
F_271 ( V_2 ) ;
F_279 ( V_2 ) ;
F_266 () ;
}
F_245 ( V_2 ) ;
#ifdef F_324
V_455 = F_326 ( V_12 ) ;
if ( V_455 )
return V_455 ;
#endif
if ( ! F_3 ( V_456 , & V_2 -> V_4 ) )
F_327 ( V_12 ) ;
return 0 ;
}
static int F_328 ( struct V_337 * V_12 )
{
struct V_51 * V_39 = F_323 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
T_1 V_201 ;
F_329 ( V_12 ) ;
F_326 ( V_12 ) ;
V_201 = F_330 ( V_12 ) ;
if ( V_201 ) {
F_10 ( & V_12 -> V_13 , L_52 ) ;
return V_201 ;
}
F_7 () ;
F_8 ( V_456 , & V_2 -> V_4 ) ;
F_331 ( V_12 ) ;
F_219 ( V_2 ) ;
F_265 () ;
V_201 = F_244 ( V_2 ) ;
F_266 () ;
if ( V_201 ) {
F_10 ( & V_12 -> V_13 , L_53 ) ;
return V_201 ;
}
if ( F_282 ( V_39 ) ) {
V_201 = F_280 ( V_39 ) ;
if ( V_201 )
return V_201 ;
}
F_332 ( V_39 ) ;
return V_201 ;
}
static void F_333 ( struct V_337 * V_12 )
{
F_322 ( V_12 , V_457 ) ;
}
static struct V_458 * F_334 ( struct V_51 * V_39 ,
struct V_458 * V_37 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
unsigned int V_459 ;
T_5 V_69 , V_38 ;
const struct V_27 * V_36 ;
int V_59 ;
F_251 ( V_2 ) ;
V_37 -> V_460 = V_2 -> V_37 . V_289 - V_2 -> V_37 . V_290 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_195 ; V_59 ++ ) {
V_36 = V_2 -> V_90 [ V_59 ] ;
do {
V_459 = F_335 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_336 ( & V_36 -> V_68 , V_459 ) );
V_37 -> V_461 += V_69 ;
V_37 -> V_462 += V_38 ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_197 ; V_59 ++ ) {
V_36 = V_2 -> V_28 [ V_59 ] ;
do {
V_459 = F_335 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_336 ( & V_36 -> V_68 , V_459 ) );
V_37 -> V_463 += V_69 ;
V_37 -> V_464 += V_38 ;
}
return V_37 ;
}
static void F_337 ( struct V_51 * V_13 )
{
V_13 -> V_465 = & V_466 ;
F_338 ( V_13 ) ;
V_13 -> V_467 = 5 * V_354 ;
}
static int F_339 ( struct V_337 * V_12 , const struct V_468 * V_469 )
{
struct V_51 * V_39 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = NULL ;
const struct V_470 * V_471 = V_472 [ V_469 -> V_473 ] ;
int V_201 , V_474 ;
bool V_475 = false ;
V_201 = F_340 ( V_12 ) ;
if ( V_201 )
return V_201 ;
if ( ! F_341 ( & V_12 -> V_13 , F_149 ( 64 ) ) ) {
V_474 = 1 ;
} else {
V_201 = F_341 ( & V_12 -> V_13 , F_149 ( 32 ) ) ;
if ( V_201 ) {
F_10 ( & V_12 -> V_13 , L_54 ) ;
goto V_476;
}
V_474 = 0 ;
}
V_201 = F_342 ( V_12 , V_477 ) ;
if ( V_201 ) {
F_10 ( & V_12 -> V_13 , L_55 , V_201 ) ;
goto V_478;
}
F_331 ( V_12 ) ;
V_39 = F_343 ( sizeof( struct V_1 ) ,
V_479 ) ;
if ( ! V_39 ) {
V_201 = - V_330 ;
goto V_480;
}
F_344 ( V_39 , & V_12 -> V_13 ) ;
V_2 = F_30 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_12 = V_12 ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_10 = V_2 ;
V_2 -> V_481 = F_345 ( V_482 , V_483 ) ;
F_326 ( V_12 ) ;
V_9 -> V_11 = F_346 ( F_347 ( V_12 , 0 ) ,
F_348 ( V_12 , 0 ) ) ;
V_2 -> V_221 = V_9 -> V_11 ;
if ( ! V_9 -> V_11 ) {
V_201 = - V_260 ;
goto V_484;
}
F_337 ( V_39 ) ;
memcpy ( & V_9 -> V_184 . V_257 , V_471 -> V_485 , sizeof( V_9 -> V_184 . V_257 ) ) ;
V_9 -> V_184 . type = V_471 -> V_184 ;
memcpy ( & V_9 -> V_273 . V_257 , & V_486 ,
sizeof( struct V_487 ) ) ;
V_201 = F_246 ( V_2 ) ;
if ( V_201 )
goto V_488;
if ( ! F_204 ( V_39 -> V_146 ) ) {
F_46 ( L_56 ) ;
V_201 = - V_260 ;
goto V_488;
}
V_39 -> V_489 = V_490 |
V_491 |
V_492 |
V_493 |
V_494 |
V_81 ;
V_39 -> V_80 = V_39 -> V_489 |
V_495 |
V_496 |
V_497 ;
V_39 -> V_498 |= V_493 |
V_494 |
V_491 |
V_492 |
V_490 ;
if ( V_474 )
V_39 -> V_80 |= V_499 ;
V_39 -> V_500 |= V_501 ;
if ( F_14 ( V_9 -> V_11 ) ) {
V_201 = - V_260 ;
goto V_488;
}
F_349 ( & V_2 -> V_312 , & F_254 ,
( unsigned long ) V_2 ) ;
F_350 ( & V_2 -> V_7 , F_264 ) ;
F_180 ( V_14 , & V_2 -> V_4 ) ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
V_201 = F_244 ( V_2 ) ;
if ( V_201 )
goto V_488;
strcpy ( V_39 -> V_209 , L_57 ) ;
V_201 = F_351 ( V_39 ) ;
if ( V_201 )
goto V_502;
F_352 ( V_12 , V_39 ) ;
F_215 ( V_39 ) ;
F_200 ( V_2 ) ;
F_248 ( & V_12 -> V_13 , L_58 , V_39 -> V_146 ) ;
F_248 ( & V_12 -> V_13 , L_59 , V_9 -> V_184 . type ) ;
switch ( V_9 -> V_184 . type ) {
case V_251 :
F_248 ( & V_12 -> V_13 , L_60 ) ;
break;
case V_503 :
F_248 ( & V_12 -> V_13 , L_61 ) ;
break;
case V_453 :
default:
F_248 ( & V_12 -> V_13 , L_62 ) ;
break;
}
return 0 ;
V_502:
F_245 ( V_2 ) ;
V_488:
F_242 ( V_2 ) ;
F_353 ( V_2 -> V_221 ) ;
V_484:
V_475 = ! F_3 ( V_456 , & V_2 -> V_4 ) ;
F_354 ( V_39 ) ;
V_480:
F_355 ( V_12 ) ;
V_478:
V_476:
if ( ! V_2 || V_475 )
F_327 ( V_12 ) ;
return V_201 ;
}
static void F_356 ( struct V_337 * V_12 )
{
struct V_51 * V_39 = F_323 ( V_12 ) ;
struct V_1 * V_2 ;
bool V_475 ;
if ( ! V_39 )
return;
V_2 = F_30 ( V_39 ) ;
F_180 ( V_5 , & V_2 -> V_4 ) ;
F_357 ( & V_2 -> V_7 ) ;
if ( V_39 -> V_504 == V_505 )
F_358 ( V_39 ) ;
F_245 ( V_2 ) ;
F_242 ( V_2 ) ;
F_353 ( V_2 -> V_221 ) ;
F_355 ( V_12 ) ;
F_137 ( & V_2 -> V_9 , L_63 ) ;
V_475 = ! F_3 ( V_456 , & V_2 -> V_4 ) ;
F_354 ( V_39 ) ;
if ( V_475 )
F_327 ( V_12 ) ;
}
static T_13 F_359 ( struct V_337 * V_12 ,
T_14 V_4 )
{
struct V_51 * V_39 = F_323 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( ! F_2 ( V_14 , & V_2 -> V_4 ) )
return V_506 ;
F_265 () ;
F_325 ( V_39 ) ;
if ( V_4 == V_507 ) {
F_266 () ;
return V_506 ;
}
if ( F_282 ( V_39 ) )
F_213 ( V_2 ) ;
if ( ! F_3 ( V_456 , & V_2 -> V_4 ) )
F_327 ( V_12 ) ;
F_266 () ;
return V_508 ;
}
static T_13 F_360 ( struct V_337 * V_12 )
{
struct V_51 * V_39 = F_323 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_330 ( V_12 ) ) {
F_10 ( & V_12 -> V_13 ,
L_64 ) ;
return V_506 ;
}
F_7 () ;
F_8 ( V_456 , & V_2 -> V_4 ) ;
F_331 ( V_12 ) ;
F_219 ( V_2 ) ;
return V_509 ;
}
static void F_361 ( struct V_337 * V_12 )
{
struct V_51 * V_39 = F_323 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_282 ( V_39 ) )
F_207 ( V_2 ) ;
F_332 ( V_39 ) ;
}
static int T_15 F_362 ( void )
{
int V_510 ;
F_195 ( L_65 , V_511 ,
V_512 ) ;
F_195 ( L_66 , V_513 ) ;
V_510 = F_363 ( & V_514 ) ;
return V_510 ;
}
static void T_16 F_364 ( void )
{
F_365 ( & V_514 ) ;
}
char * F_366 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
return V_2 -> V_39 -> V_209 ;
}
