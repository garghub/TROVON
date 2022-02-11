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
return ( F_92 ( V_103 ) != F_93 () ) || V_103 -> V_128 ;
}
static bool F_94 ( struct V_27 * V_90 ,
struct V_101 * V_129 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
struct V_103 * V_103 = V_129 -> V_103 ;
unsigned int V_130 = F_64 ( V_79 -> V_63 . V_93 . V_131 ) ;
#if ( V_105 < 8192 )
unsigned int V_132 = V_127 ;
#else
unsigned int V_132 = F_84 ( V_130 , V_133 ) ;
#endif
if ( ( V_130 <= V_120 ) && ! F_87 ( V_31 ) ) {
unsigned char * V_118 = F_95 ( V_103 ) + V_129 -> V_108 ;
memcpy ( F_96 ( V_31 , V_130 ) , V_118 , F_84 ( V_130 , sizeof( long ) ) ) ;
if ( F_42 ( ! F_91 ( V_103 ) ) )
return true ;
F_97 ( V_103 ) ;
return false ;
}
F_98 ( V_31 , F_80 ( V_31 ) -> V_134 , V_103 ,
V_129 -> V_108 , V_130 , V_132 ) ;
if ( F_16 ( F_91 ( V_103 ) ) )
return false ;
#if ( V_105 < 8192 )
if ( F_16 ( F_99 ( V_103 ) != 1 ) )
return false ;
V_129 -> V_108 ^= V_127 ;
#else
V_129 -> V_108 += V_132 ;
if ( V_129 -> V_108 > ( V_105 - V_127 ) )
return false ;
#endif
F_100 ( & V_103 -> V_135 ) ;
return true ;
}
static struct V_76 * F_101 ( struct V_27 * V_90 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
struct V_101 * V_129 ;
struct V_103 * V_103 ;
V_129 = & V_90 -> V_110 [ V_90 -> V_60 ] ;
V_103 = V_129 -> V_103 ;
F_102 ( V_103 ) ;
if ( F_42 ( ! V_31 ) ) {
void * V_136 = F_95 ( V_103 ) +
V_129 -> V_108 ;
F_41 ( V_136 ) ;
#if V_133 < 128
F_41 ( V_136 + V_133 ) ;
#endif
V_31 = F_103 ( V_90 -> V_39 ,
V_120 ) ;
if ( F_16 ( ! V_31 ) ) {
V_90 -> V_84 . V_107 ++ ;
return NULL ;
}
F_102 ( V_31 -> V_137 ) ;
}
F_104 ( V_90 -> V_13 ,
V_129 -> V_33 ,
V_129 -> V_108 ,
V_127 ,
V_106 ) ;
if ( F_94 ( V_90 , V_129 , V_79 , V_31 ) ) {
F_89 ( V_90 , V_129 ) ;
} else {
F_26 ( V_90 -> V_13 , V_129 -> V_33 ,
V_105 , V_106 ) ;
}
V_129 -> V_33 = 0 ;
V_129 -> V_103 = NULL ;
return V_31 ;
}
static inline void F_105 ( struct V_1 * V_2 ,
T_1 V_138 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_19 ( V_9 , V_139 , V_138 ) ;
}
static int F_106 ( struct V_52 * V_53 ,
struct V_27 * V_90 ,
int V_58 )
{
unsigned int V_140 = 0 , V_141 = 0 ;
T_6 V_109 = F_50 ( V_90 ) ;
struct V_76 * V_31 = V_90 -> V_31 ;
while ( F_42 ( V_141 < V_58 ) ) {
union V_78 * V_79 ;
if ( V_109 >= V_142 ) {
F_75 ( V_90 , V_109 ) ;
V_109 = 0 ;
}
V_79 = F_69 ( V_90 , V_90 -> V_60 ) ;
if ( ! F_62 ( V_79 , V_143 ) )
break;
F_107 () ;
V_31 = F_101 ( V_90 , V_79 , V_31 ) ;
if ( ! V_31 )
break;
V_109 ++ ;
if ( F_68 ( V_90 , V_79 ) )
continue;
if ( F_86 ( V_90 , V_79 , V_31 ) ) {
V_31 = NULL ;
continue;
}
V_140 += V_31 -> V_32 ;
if ( ( V_31 -> V_144 == V_145 ||
V_31 -> V_144 == V_146 ) &&
F_108 ( V_90 -> V_39 -> V_147 ,
F_109 ( V_31 ) -> V_148 ) ) {
F_110 ( V_31 ) ;
continue;
}
F_63 ( V_90 , V_79 , V_31 ) ;
F_54 ( V_53 , V_31 ) ;
V_31 = NULL ;
V_141 ++ ;
}
V_90 -> V_31 = V_31 ;
F_43 ( & V_90 -> V_68 ) ;
V_90 -> V_37 . V_38 += V_141 ;
V_90 -> V_37 . V_69 += V_140 ;
F_44 ( & V_90 -> V_68 ) ;
V_53 -> V_149 . V_57 += V_141 ;
V_53 -> V_149 . V_56 += V_140 ;
return V_141 ;
}
static int F_111 ( struct V_150 * V_77 , int V_58 )
{
struct V_52 * V_53 =
F_112 ( V_77 , struct V_52 , V_77 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_27 * V_36 ;
int V_151 ;
bool V_152 = true ;
F_113 (ring, q_vector->tx)
V_152 &= F_37 ( V_53 , V_36 ) ;
#ifdef F_55
if ( ! F_114 ( V_53 ) )
return V_58 ;
#endif
if ( V_53 -> V_149 . V_43 > 1 )
V_151 = F_115 ( V_58 / V_53 -> V_149 . V_43 , 1 ) ;
else
V_151 = V_58 ;
F_113 (ring, q_vector->rx)
V_152 &= ( F_106 ( V_53 , V_36 ,
V_151 )
< V_151 ) ;
#ifdef F_55
F_116 ( V_53 ) ;
#endif
if ( ! V_152 )
return V_58 ;
F_117 ( V_77 ) ;
if ( V_2 -> V_153 & 1 )
F_118 ( V_53 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) )
F_105 ( V_2 ,
1 << V_53 -> V_154 ) ;
return 0 ;
}
void F_119 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_154 = V_53 -> V_154 ;
T_1 V_155 = V_53 -> V_156 & V_157 ;
V_155 |= V_158 ;
F_19 ( V_9 , F_120 ( V_154 ) , V_155 ) ;
}
static int F_121 ( struct V_150 * V_77 )
{
struct V_52 * V_53 =
F_112 ( V_77 , struct V_52 , V_77 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_27 * V_36 ;
int V_159 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return V_160 ;
if ( ! F_122 ( V_53 ) )
return V_161 ;
F_113 (ring, q_vector->rx) {
V_159 = F_106 ( V_53 , V_36 , 4 ) ;
#ifdef F_123
if ( V_159 )
V_36 -> V_37 . V_162 += V_159 ;
else
V_36 -> V_37 . V_163 ++ ;
#endif
if ( V_159 )
break;
}
F_124 ( V_53 ) ;
return V_159 ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
int V_164 , V_154 ;
V_164 = V_2 -> V_165 - V_166 ;
V_2 -> V_167 = 0 ;
for ( V_154 = 0 ; V_154 < V_164 ; V_154 ++ ) {
struct V_27 * V_36 ;
V_53 = V_2 -> V_53 [ V_154 ] ;
F_113 (ring, q_vector->rx)
F_17 ( V_2 , 0 , V_36 -> V_41 , V_154 ) ;
F_113 (ring, q_vector->tx)
F_17 ( V_2 , 1 , V_36 -> V_41 , V_154 ) ;
if ( V_53 -> V_70 . V_36 && ! V_53 -> V_149 . V_36 ) {
if ( V_2 -> V_168 == 1 )
V_53 -> V_156 = V_169 ;
else
V_53 -> V_156 = V_2 -> V_168 ;
} else {
if ( V_2 -> V_153 == 1 )
V_53 -> V_156 = V_170 ;
else
V_53 -> V_156 = V_2 -> V_153 ;
}
V_2 -> V_167 |= 1 << V_154 ;
F_119 ( V_53 ) ;
}
F_17 ( V_2 , - 1 , 1 , V_154 ) ;
V_2 -> V_171 = 1 << V_154 ;
V_2 -> V_167 |= V_2 -> V_171 ;
}
static void F_126 ( struct V_52 * V_53 ,
struct V_172 * V_173 )
{
int V_69 = V_173 -> V_56 ;
int V_38 = V_173 -> V_57 ;
T_1 V_174 ;
T_5 V_175 ;
T_2 V_176 = V_173 -> V_156 ;
if ( V_38 == 0 )
return;
V_174 = V_53 -> V_156 >> 2 ;
V_175 = V_69 / V_174 ;
switch ( V_176 ) {
case V_177 :
if ( V_175 > 10 )
V_176 = V_178 ;
break;
case V_178 :
if ( V_175 > 20 )
V_176 = V_179 ;
else if ( V_175 <= 10 )
V_176 = V_177 ;
break;
case V_179 :
if ( V_175 <= 20 )
V_176 = V_178 ;
break;
}
V_173 -> V_56 = 0 ;
V_173 -> V_57 = 0 ;
V_173 -> V_156 = V_176 ;
}
static void F_118 ( struct V_52 * V_53 )
{
T_1 V_180 = V_53 -> V_156 ;
T_2 V_181 ;
F_126 ( V_53 , & V_53 -> V_70 ) ;
F_126 ( V_53 , & V_53 -> V_149 ) ;
V_181 = F_115 ( V_53 -> V_149 . V_156 , V_53 -> V_70 . V_156 ) ;
switch ( V_181 ) {
case V_177 :
V_180 = V_182 ;
break;
case V_178 :
V_180 = V_170 ;
break;
case V_179 :
default:
V_180 = V_183 ;
break;
}
if ( V_180 != V_53 -> V_156 ) {
V_180 = ( 10 * V_180 * V_53 -> V_156 ) /
( ( 9 * V_180 ) + V_53 -> V_156 ) ;
V_53 -> V_156 = V_180 ;
F_119 ( V_53 ) ;
}
}
static T_8 F_127 ( int V_184 , void * V_137 )
{
struct V_1 * V_2 = V_137 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
V_9 -> V_185 . V_186 = 1 ;
F_1 ( V_2 ) ;
F_19 ( V_9 , V_139 , V_2 -> V_171 ) ;
return V_187 ;
}
static T_8 F_128 ( int V_184 , void * V_137 )
{
struct V_52 * V_53 = V_137 ;
if ( V_53 -> V_149 . V_36 || V_53 -> V_70 . V_36 )
F_129 ( & V_53 -> V_77 ) ;
return V_187 ;
}
static inline void F_130 ( struct V_1 * V_188 , int V_154 ,
int V_189 )
{
struct V_52 * V_53 = V_188 -> V_53 [ V_154 ] ;
V_188 -> V_90 [ V_189 ] -> V_190 = V_53 -> V_149 . V_36 ;
V_53 -> V_149 . V_36 = V_188 -> V_90 [ V_189 ] ;
V_53 -> V_149 . V_43 ++ ;
}
static inline void F_131 ( struct V_1 * V_188 , int V_154 ,
int V_191 )
{
struct V_52 * V_53 = V_188 -> V_53 [ V_154 ] ;
V_188 -> V_28 [ V_191 ] -> V_190 = V_53 -> V_70 . V_36 ;
V_53 -> V_70 . V_36 = V_188 -> V_28 [ V_191 ] ;
V_53 -> V_70 . V_43 ++ ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_164 ;
int V_192 = 0 ;
int V_193 = 0 , V_194 = 0 ;
int V_195 = V_2 -> V_196 ;
int V_197 = V_2 -> V_198 ;
int V_59 , V_199 ;
int V_200 , V_201 ;
int V_202 = 0 ;
V_164 = V_2 -> V_165 - V_166 ;
if ( V_164 == V_2 -> V_196 + V_2 -> V_198 ) {
for (; V_193 < V_195 ; V_192 ++ , V_193 ++ )
F_130 ( V_2 , V_192 , V_193 ) ;
for (; V_194 < V_197 ; V_192 ++ , V_194 ++ )
F_131 ( V_2 , V_192 , V_194 ) ;
goto V_203;
}
for ( V_59 = V_192 ; V_59 < V_164 ; V_59 ++ ) {
V_200 = F_133 ( V_195 , V_164 - V_59 ) ;
for ( V_199 = 0 ; V_199 < V_200 ; V_199 ++ ) {
F_130 ( V_2 , V_59 , V_193 ) ;
V_193 ++ ;
V_195 -- ;
}
}
for ( V_59 = V_192 ; V_59 < V_164 ; V_59 ++ ) {
V_201 = F_133 ( V_197 , V_164 - V_59 ) ;
for ( V_199 = 0 ; V_199 < V_201 ; V_199 ++ ) {
F_131 ( V_2 , V_59 , V_194 ) ;
V_194 ++ ;
V_197 -- ;
}
}
V_203:
return V_202 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_164 = V_2 -> V_165 - V_166 ;
int V_204 , V_202 ;
int V_205 = 0 , V_206 = 0 ;
for ( V_204 = 0 ; V_204 < V_164 ; V_204 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_204 ] ;
struct V_207 * V_208 = & V_2 -> V_209 [ V_204 ] ;
if ( V_53 -> V_70 . V_36 && V_53 -> V_149 . V_36 ) {
snprintf ( V_53 -> V_210 , sizeof( V_53 -> V_210 ) - 1 ,
L_12 , V_39 -> V_210 , L_13 , V_205 ++ ) ;
V_206 ++ ;
} else if ( V_53 -> V_149 . V_36 ) {
snprintf ( V_53 -> V_210 , sizeof( V_53 -> V_210 ) - 1 ,
L_12 , V_39 -> V_210 , L_14 , V_205 ++ ) ;
} else if ( V_53 -> V_70 . V_36 ) {
snprintf ( V_53 -> V_210 , sizeof( V_53 -> V_210 ) - 1 ,
L_12 , V_39 -> V_210 , L_15 , V_206 ++ ) ;
} else {
continue;
}
V_202 = F_135 ( V_208 -> V_204 , & F_128 , 0 ,
V_53 -> V_210 , V_53 ) ;
if ( V_202 ) {
F_136 ( & V_2 -> V_9 ,
L_16 ,
V_202 ) ;
goto V_211;
}
}
V_202 = F_135 ( V_2 -> V_209 [ V_204 ] . V_204 ,
& F_127 , 0 , V_39 -> V_210 , V_2 ) ;
if ( V_202 ) {
F_136 ( & V_2 -> V_9 , L_17 ,
V_202 ) ;
goto V_211;
}
return 0 ;
V_211:
while ( V_204 ) {
V_204 -- ;
F_137 ( V_2 -> V_209 [ V_204 ] . V_204 ,
V_2 -> V_53 [ V_204 ] ) ;
}
V_2 -> V_165 = 0 ;
return V_202 ;
}
static inline void F_138 ( struct V_1 * V_2 )
{
int V_59 , V_164 = V_2 -> V_165 - V_166 ;
for ( V_59 = 0 ; V_59 < V_164 ; V_59 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_59 ] ;
V_53 -> V_149 . V_36 = NULL ;
V_53 -> V_70 . V_36 = NULL ;
V_53 -> V_149 . V_43 = 0 ;
V_53 -> V_70 . V_43 = 0 ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
int V_202 = 0 ;
V_202 = F_134 ( V_2 ) ;
if ( V_202 )
F_136 ( & V_2 -> V_9 , L_18 , V_202 ) ;
return V_202 ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_59 , V_164 ;
V_164 = V_2 -> V_165 ;
V_59 = V_164 - 1 ;
F_137 ( V_2 -> V_209 [ V_59 ] . V_204 , V_2 ) ;
V_59 -- ;
for (; V_59 >= 0 ; V_59 -- ) {
if ( ! V_2 -> V_53 [ V_59 ] -> V_149 . V_36 &&
! V_2 -> V_53 [ V_59 ] -> V_70 . V_36 )
continue;
F_137 ( V_2 -> V_209 [ V_59 ] . V_204 ,
V_2 -> V_53 [ V_59 ] ) ;
}
F_138 ( V_2 ) ;
}
static inline void F_141 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
F_19 ( V_9 , V_212 , 0 ) ;
F_19 ( V_9 , V_213 , ~ 0 ) ;
F_19 ( V_9 , V_214 , 0 ) ;
F_142 ( V_9 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_165 ; V_59 ++ )
F_143 ( V_2 -> V_209 [ V_59 ] . V_204 ) ;
}
static inline void F_144 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_19 ( V_9 , V_212 , V_2 -> V_167 ) ;
F_19 ( V_9 , V_214 , V_2 -> V_167 ) ;
F_19 ( V_9 , V_139 , V_2 -> V_167 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_215 = V_36 -> V_33 ;
int V_216 = 10 ;
T_1 V_217 = V_218 ;
T_2 V_41 = V_36 -> V_41 ;
F_19 ( V_9 , F_146 ( V_41 ) , V_219 ) ;
F_142 ( V_9 ) ;
F_19 ( V_9 , F_147 ( V_41 ) , V_215 & F_148 ( 32 ) ) ;
F_19 ( V_9 , F_149 ( V_41 ) , V_215 >> 32 ) ;
F_19 ( V_9 , F_150 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_54 ) ) ;
F_19 ( V_9 , F_151 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_152 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_153 ( V_41 ) ,
( V_220 |
V_221 ) ) ;
F_19 ( V_9 , F_31 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_32 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_222 + F_32 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_217 |= ( 8 << 16 ) ;
V_217 |= ( 1 << 8 ) |
32 ;
F_8 ( V_48 , & V_36 -> V_4 ) ;
F_19 ( V_9 , F_146 ( V_41 ) , V_217 ) ;
do {
F_154 ( 1000 , 2000 ) ;
V_217 = F_18 ( V_9 , F_146 ( V_41 ) ) ;
} while ( -- V_216 && ! ( V_217 & V_218 ) );
if ( ! V_216 )
F_46 ( L_19 , V_41 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_1 V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ )
F_145 ( V_2 , V_2 -> V_28 [ V_59 ] ) ;
}
static void F_156 ( struct V_1 * V_2 , int V_24 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_223 ;
V_223 = V_224 ;
V_223 |= V_120 << V_225 ;
V_223 |= V_127 >> V_226 ;
V_223 |= V_227 ;
F_19 ( V_9 , F_157 ( V_24 ) , V_223 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_228 = V_229 | V_230 |
V_231 | V_232 |
V_233 ;
if ( V_2 -> V_196 > 1 )
V_228 |= 1 << 29 ;
F_19 ( V_9 , V_234 , V_228 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_216 = V_235 ;
T_1 V_236 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
V_236 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
V_236 &= ~ V_237 ;
F_19 ( V_9 , F_160 ( V_41 ) , V_236 ) ;
do {
F_161 ( 10 ) ;
V_236 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
} while ( -- V_216 && ( V_236 & V_237 ) );
if ( ! V_216 )
F_46 ( L_20 ,
V_41 ) ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_216 = V_235 ;
T_1 V_236 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
do {
F_154 ( 1000 , 2000 ) ;
V_236 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
} while ( -- V_216 && ! ( V_236 & V_237 ) );
if ( ! V_216 )
F_46 ( L_21 ,
V_41 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_238 = 0 , V_239 = 0 ;
T_1 V_240 [ 10 ] ;
T_6 V_241 = V_2 -> V_196 ;
int V_59 , V_199 ;
F_164 ( V_240 , sizeof( V_240 ) ) ;
for ( V_59 = 0 ; V_59 < 10 ; V_59 ++ )
F_19 ( V_9 , F_165 ( V_59 ) , V_240 [ V_59 ] ) ;
for ( V_59 = 0 , V_199 = 0 ; V_59 < 64 ; V_59 ++ , V_199 ++ ) {
if ( V_199 == V_241 )
V_199 = 0 ;
V_239 = ( V_239 << 8 ) | ( V_199 * 0x1 ) ;
if ( ( V_59 & 3 ) == 3 )
F_19 ( V_9 , F_166 ( V_59 >> 2 ) , V_239 ) ;
}
V_238 |= V_242 |
V_243 |
V_244 |
V_245 ;
V_238 |= V_246 ;
F_19 ( V_9 , V_247 , V_238 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_248 = V_36 -> V_33 ;
T_1 V_236 ;
T_2 V_41 = V_36 -> V_41 ;
V_236 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
F_159 ( V_2 , V_36 ) ;
F_19 ( V_9 , F_168 ( V_41 ) , V_248 & F_148 ( 32 ) ) ;
F_19 ( V_9 , F_169 ( V_41 ) , V_248 >> 32 ) ;
F_19 ( V_9 , F_170 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_78 ) ) ;
F_19 ( V_9 , F_171 ( V_41 ) ,
V_249 ) ;
F_19 ( V_9 , F_172 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_173 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_222 + F_173 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_36 -> V_114 = 0 ;
F_156 ( V_2 , V_41 ) ;
V_236 &= ~ V_250 ;
V_236 |= V_237 | V_251 ;
F_19 ( V_9 , F_160 ( V_41 ) , V_236 ) ;
F_162 ( V_2 , V_36 ) ;
F_75 ( V_36 , F_50 ( V_36 ) ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_59 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
F_158 ( V_2 ) ;
if ( V_9 -> V_185 . type >= V_252 )
F_163 ( V_2 ) ;
F_175 ( V_9 , V_39 -> V_253 + V_254 + V_255 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ )
F_167 ( V_2 , V_2 -> V_90 [ V_59 ] ) ;
}
static int F_176 ( struct V_51 * V_39 ,
T_9 V_256 , T_6 V_92 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_202 ;
F_177 ( & V_2 -> V_257 ) ;
V_202 = V_9 -> V_185 . V_258 . V_259 ( V_9 , V_92 , 0 , true ) ;
F_178 ( & V_2 -> V_257 ) ;
if ( V_202 == V_260 )
return - V_261 ;
if ( V_202 == V_262 )
return - V_263 ;
F_179 ( V_92 , V_2 -> V_95 ) ;
return V_202 ;
}
static int F_180 ( struct V_51 * V_39 ,
T_9 V_256 , T_6 V_92 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_202 = - V_264 ;
F_177 ( & V_2 -> V_257 ) ;
V_202 = V_9 -> V_185 . V_258 . V_259 ( V_9 , V_92 , 0 , false ) ;
F_178 ( & V_2 -> V_257 ) ;
F_8 ( V_92 , V_2 -> V_95 ) ;
return V_202 ;
}
static void F_181 ( struct V_1 * V_2 )
{
T_6 V_92 ;
F_182 (vid, adapter->active_vlans, VLAN_N_VID)
F_176 ( V_2 -> V_39 ,
F_66 ( V_97 ) , V_92 ) ;
}
static int F_183 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_43 = 0 ;
if ( ( F_184 ( V_39 ) ) > 10 ) {
F_46 ( L_22 ) ;
return - V_265 ;
}
if ( ! F_185 ( V_39 ) ) {
struct V_266 * V_267 ;
F_186 (ha, netdev) {
V_9 -> V_185 . V_258 . V_268 ( V_9 , ++ V_43 , V_267 -> V_269 ) ;
F_161 ( 200 ) ;
}
} else {
V_9 -> V_185 . V_258 . V_268 ( V_9 , 0 , NULL ) ;
}
return V_43 ;
}
static void F_187 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_177 ( & V_2 -> V_257 ) ;
V_9 -> V_185 . V_258 . V_270 ( V_9 , V_39 ) ;
F_183 ( V_39 ) ;
F_178 ( & V_2 -> V_257 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
int V_271 ;
struct V_52 * V_53 ;
int V_164 = V_2 -> V_165 - V_166 ;
for ( V_271 = 0 ; V_271 < V_164 ; V_271 ++ ) {
V_53 = V_2 -> V_53 [ V_271 ] ;
#ifdef F_55
F_189 ( V_2 -> V_53 [ V_271 ] ) ;
#endif
F_190 ( & V_53 -> V_77 ) ;
}
}
static void F_191 ( struct V_1 * V_2 )
{
int V_271 ;
struct V_52 * V_53 ;
int V_164 = V_2 -> V_165 - V_166 ;
for ( V_271 = 0 ; V_271 < V_164 ; V_271 ++ ) {
V_53 = V_2 -> V_53 [ V_271 ] ;
F_192 ( & V_53 -> V_77 ) ;
#ifdef F_55
while ( ! F_193 ( V_2 -> V_53 [ V_271 ] ) ) {
F_194 ( L_23 , V_271 ) ;
F_154 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_272 = 0 ;
unsigned int V_273 = 0 ;
unsigned int V_196 = V_2 -> V_196 ;
unsigned int V_198 = V_2 -> V_198 ;
int V_202 ;
F_177 ( & V_2 -> V_257 ) ;
V_202 = F_196 ( V_9 , & V_273 , & V_272 ) ;
F_178 ( & V_2 -> V_257 ) ;
if ( V_202 )
return V_202 ;
if ( V_273 > 1 ) {
V_198 = 1 ;
V_2 -> V_28 [ 0 ] -> V_41 = V_272 ;
V_196 = V_273 ;
}
if ( ( V_2 -> V_196 != V_196 ) ||
( V_2 -> V_198 != V_198 ) ) {
V_9 -> V_274 . V_275 = 0 ;
V_2 -> V_49 |= V_276 ;
}
return 0 ;
}
static void F_197 ( struct V_1 * V_2 )
{
F_195 ( V_2 ) ;
F_187 ( V_2 -> V_39 ) ;
F_181 ( V_2 ) ;
F_155 ( V_2 ) ;
F_174 ( V_2 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 . V_277 || V_2 -> V_37 . V_278 ) {
V_2 -> V_37 . V_279 += V_2 -> V_37 . V_277 -
V_2 -> V_37 . V_280 ;
V_2 -> V_37 . V_281 += V_2 -> V_37 . V_278 -
V_2 -> V_37 . V_282 ;
V_2 -> V_37 . V_283 += V_2 -> V_37 . V_284 -
V_2 -> V_37 . V_285 ;
V_2 -> V_37 . V_286 += V_2 -> V_37 . V_287 -
V_2 -> V_37 . V_288 ;
V_2 -> V_37 . V_289 += V_2 -> V_37 . V_290 -
V_2 -> V_37 . V_291 ;
}
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
V_2 -> V_37 . V_292 = F_18 ( V_9 , V_293 ) ;
V_2 -> V_37 . V_294 = F_18 ( V_9 , V_295 ) ;
V_2 -> V_37 . V_294 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_296 ) ) ) << 32 ) ;
V_2 -> V_37 . V_297 = F_18 ( V_9 , V_298 ) ;
V_2 -> V_37 . V_299 = F_18 ( V_9 , V_300 ) ;
V_2 -> V_37 . V_299 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_301 ) ) ) << 32 ) ;
V_2 -> V_37 . V_302 = F_18 ( V_9 , V_303 ) ;
V_2 -> V_37 . V_280 = V_2 -> V_37 . V_292 ;
V_2 -> V_37 . V_285 = V_2 -> V_37 . V_294 ;
V_2 -> V_37 . V_282 = V_2 -> V_37 . V_297 ;
V_2 -> V_37 . V_288 = V_2 -> V_37 . V_299 ;
V_2 -> V_37 . V_291 = V_2 -> V_37 . V_302 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_304 [] = { V_305 ,
V_306 ,
V_307 ,
V_308 } ;
int V_202 = 0 , V_309 = 0 ;
F_177 ( & V_2 -> V_257 ) ;
while ( V_304 [ V_309 ] != V_308 ) {
V_202 = F_201 ( V_9 , V_304 [ V_309 ] ) ;
if ( ! V_202 )
break;
V_309 ++ ;
}
F_178 ( & V_2 -> V_257 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_125 ( V_2 ) ;
F_177 ( & V_2 -> V_257 ) ;
if ( F_203 ( V_9 -> V_185 . V_269 ) )
V_9 -> V_185 . V_258 . V_310 ( V_9 , 0 , V_9 -> V_185 . V_269 , 0 ) ;
else
V_9 -> V_185 . V_258 . V_310 ( V_9 , 0 , V_9 -> V_185 . V_311 , 0 ) ;
F_178 ( & V_2 -> V_257 ) ;
F_7 () ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_188 ( V_2 ) ;
F_18 ( V_9 , V_312 ) ;
F_144 ( V_2 ) ;
F_204 ( V_39 ) ;
F_198 ( V_2 ) ;
F_199 ( V_2 ) ;
V_9 -> V_185 . V_186 = 1 ;
F_205 ( & V_2 -> V_313 , V_74 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
F_197 ( V_2 ) ;
F_202 ( V_2 ) ;
}
static void F_207 ( struct V_27 * V_90 )
{
struct V_314 * V_13 = V_90 -> V_13 ;
unsigned long V_130 ;
unsigned int V_59 ;
if ( V_90 -> V_31 ) {
F_208 ( V_90 -> V_31 ) ;
V_90 -> V_31 = NULL ;
}
if ( ! V_90 -> V_110 )
return;
for ( V_59 = 0 ; V_59 < V_90 -> V_43 ; V_59 ++ ) {
struct V_101 * V_129 ;
V_129 = & V_90 -> V_110 [ V_59 ] ;
if ( V_129 -> V_33 )
F_26 ( V_13 , V_129 -> V_33 ,
V_105 , V_106 ) ;
V_129 -> V_33 = 0 ;
if ( V_129 -> V_103 )
F_74 ( V_129 -> V_103 ) ;
V_129 -> V_103 = NULL ;
}
V_130 = sizeof( struct V_101 ) * V_90 -> V_43 ;
memset ( V_90 -> V_110 , 0 , V_130 ) ;
memset ( V_90 -> V_315 , 0 , V_90 -> V_130 ) ;
}
static void F_209 ( struct V_27 * V_28 )
{
struct V_29 * V_61 ;
unsigned long V_130 ;
unsigned int V_59 ;
if ( ! V_28 -> V_61 )
return;
for ( V_59 = 0 ; V_59 < V_28 -> V_43 ; V_59 ++ ) {
V_61 = & V_28 -> V_61 [ V_59 ] ;
F_21 ( V_28 , V_61 ) ;
}
V_130 = sizeof( struct V_29 ) * V_28 -> V_43 ;
memset ( V_28 -> V_61 , 0 , V_130 ) ;
memset ( V_28 -> V_315 , 0 , V_28 -> V_130 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ )
F_207 ( V_2 -> V_90 [ V_59 ] ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ )
F_209 ( V_2 -> V_28 [ V_59 ] ) ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ )
F_159 ( V_2 , V_2 -> V_90 [ V_59 ] ) ;
F_154 ( 10000 , 20000 ) ;
F_213 ( V_39 ) ;
F_214 ( V_39 ) ;
F_215 ( V_39 ) ;
F_141 ( V_2 ) ;
F_191 ( V_2 ) ;
F_216 ( & V_2 -> V_313 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ ) {
T_2 V_41 = V_2 -> V_28 [ V_59 ] -> V_41 ;
F_19 ( V_9 , F_146 ( V_41 ) ,
V_219 ) ;
}
if ( ! F_217 ( V_2 -> V_12 ) )
F_218 ( V_2 ) ;
F_211 ( V_2 ) ;
F_210 ( V_2 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
F_220 ( F_221 () ) ;
while ( F_3 ( V_316 , & V_2 -> V_4 ) )
F_222 ( 1 ) ;
F_212 ( V_2 ) ;
F_206 ( V_2 ) ;
F_8 ( V_316 , & V_2 -> V_4 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
if ( V_9 -> V_185 . V_258 . V_317 ( V_9 ) ) {
F_136 ( V_9 , L_24 ) ;
} else {
V_9 -> V_185 . V_258 . V_318 ( V_9 ) ;
F_200 ( V_2 ) ;
}
if ( F_203 ( V_2 -> V_9 . V_185 . V_269 ) ) {
memcpy ( V_39 -> V_147 , V_2 -> V_9 . V_185 . V_269 ,
V_39 -> V_319 ) ;
memcpy ( V_39 -> V_311 , V_2 -> V_9 . V_185 . V_269 ,
V_39 -> V_319 ) ;
}
V_2 -> V_320 = V_74 ;
}
static int F_223 ( struct V_1 * V_2 ,
int V_321 )
{
int V_322 ;
V_322 = V_323 ;
V_321 = F_224 ( V_2 -> V_12 , V_2 -> V_209 ,
V_322 , V_321 ) ;
if ( V_321 < 0 ) {
F_10 ( & V_2 -> V_12 -> V_13 ,
L_25 ) ;
F_225 ( V_2 -> V_209 ) ;
V_2 -> V_209 = NULL ;
return V_321 ;
}
V_2 -> V_165 = V_321 ;
return 0 ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_272 = 0 ;
unsigned int V_273 = 0 ;
int V_202 ;
V_2 -> V_196 = 1 ;
V_2 -> V_198 = 1 ;
F_177 ( & V_2 -> V_257 ) ;
V_202 = F_196 ( V_9 , & V_273 , & V_272 ) ;
F_178 ( & V_2 -> V_257 ) ;
if ( V_202 )
return;
if ( V_273 > 1 ) {
V_2 -> V_196 = V_273 ;
} else {
T_6 V_324 = F_227 ( T_6 , F_228 () , V_325 ) ;
switch ( V_9 -> V_326 ) {
case V_306 :
case V_305 :
V_2 -> V_196 = V_324 ;
V_2 -> V_198 = V_324 ;
default:
break;
}
}
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_27 * V_36 ;
int V_149 = 0 , V_70 = 0 ;
for (; V_70 < V_2 -> V_198 ; V_70 ++ ) {
V_36 = F_230 ( sizeof( * V_36 ) , V_327 ) ;
if ( ! V_36 )
goto V_328;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_329 ;
V_36 -> V_71 = V_70 ;
V_36 -> V_41 = V_70 ;
V_2 -> V_28 [ V_70 ] = V_36 ;
}
for (; V_149 < V_2 -> V_196 ; V_149 ++ ) {
V_36 = F_230 ( sizeof( * V_36 ) , V_327 ) ;
if ( ! V_36 )
goto V_328;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_330 ;
V_36 -> V_71 = V_149 ;
V_36 -> V_41 = V_149 ;
V_2 -> V_90 [ V_149 ] = V_36 ;
}
return 0 ;
V_328:
while ( V_70 ) {
F_225 ( V_2 -> V_28 [ -- V_70 ] ) ;
V_2 -> V_28 [ V_70 ] = NULL ;
}
while ( V_149 ) {
F_225 ( V_2 -> V_90 [ -- V_149 ] ) ;
V_2 -> V_90 [ V_149 ] = NULL ;
}
return - V_331 ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_202 = 0 ;
int V_204 , V_332 ;
V_332 = F_115 ( V_2 -> V_196 , V_2 -> V_198 ) ;
V_332 = F_227 ( int , V_332 , F_228 () ) ;
V_332 += V_166 ;
V_2 -> V_209 = F_232 ( V_332 ,
sizeof( struct V_207 ) , V_327 ) ;
if ( ! V_2 -> V_209 ) {
V_202 = - V_331 ;
goto V_203;
}
for ( V_204 = 0 ; V_204 < V_332 ; V_204 ++ )
V_2 -> V_209 [ V_204 ] . V_208 = V_204 ;
V_202 = F_223 ( V_2 , V_332 ) ;
if ( V_202 )
goto V_203;
V_202 = F_233 ( V_39 , V_2 -> V_198 ) ;
if ( V_202 )
goto V_203;
V_202 = F_234 ( V_39 , V_2 -> V_196 ) ;
V_203:
return V_202 ;
}
static int F_235 ( struct V_1 * V_2 )
{
int V_271 , V_333 ;
struct V_52 * V_53 ;
V_333 = V_2 -> V_165 - V_166 ;
for ( V_271 = 0 ; V_271 < V_333 ; V_271 ++ ) {
V_53 = F_230 ( sizeof( struct V_52 ) , V_327 ) ;
if ( ! V_53 )
goto V_334;
V_53 -> V_2 = V_2 ;
V_53 -> V_154 = V_271 ;
F_236 ( V_2 -> V_39 , & V_53 -> V_77 ,
F_111 , 64 ) ;
#ifdef F_55
F_237 ( & V_53 -> V_77 ) ;
#endif
V_2 -> V_53 [ V_271 ] = V_53 ;
}
return 0 ;
V_334:
while ( V_271 ) {
V_271 -- ;
V_53 = V_2 -> V_53 [ V_271 ] ;
#ifdef F_55
F_238 ( & V_53 -> V_77 ) ;
#endif
F_239 ( & V_53 -> V_77 ) ;
F_225 ( V_53 ) ;
V_2 -> V_53 [ V_271 ] = NULL ;
}
return - V_331 ;
}
static void F_240 ( struct V_1 * V_2 )
{
int V_271 , V_333 = V_2 -> V_165 - V_166 ;
for ( V_271 = 0 ; V_271 < V_333 ; V_271 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_271 ] ;
V_2 -> V_53 [ V_271 ] = NULL ;
#ifdef F_55
F_238 ( & V_53 -> V_77 ) ;
#endif
F_239 ( & V_53 -> V_77 ) ;
F_225 ( V_53 ) ;
}
}
static void F_241 ( struct V_1 * V_2 )
{
F_242 ( V_2 -> V_12 ) ;
F_225 ( V_2 -> V_209 ) ;
V_2 -> V_209 = NULL ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_202 ;
F_226 ( V_2 ) ;
V_202 = F_231 ( V_2 ) ;
if ( V_202 ) {
F_136 ( & V_2 -> V_9 ,
L_26 ) ;
goto V_335;
}
V_202 = F_235 ( V_2 ) ;
if ( V_202 ) {
F_136 ( & V_2 -> V_9 , L_27 ) ;
goto V_336;
}
V_202 = F_229 ( V_2 ) ;
if ( V_202 ) {
F_46 ( L_28 ) ;
goto V_337;
}
F_136 ( & V_2 -> V_9 , L_29 ,
( V_2 -> V_196 > 1 ) ? L_30 :
L_31 , V_2 -> V_196 , V_2 -> V_198 ) ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_337:
F_240 ( V_2 ) ;
V_336:
F_241 ( V_2 ) ;
V_335:
return V_202 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ ) {
F_225 ( V_2 -> V_28 [ V_59 ] ) ;
V_2 -> V_28 [ V_59 ] = NULL ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ ) {
F_225 ( V_2 -> V_90 [ V_59 ] ) ;
V_2 -> V_90 [ V_59 ] = NULL ;
}
V_2 -> V_198 = 0 ;
V_2 -> V_196 = 0 ;
F_240 ( V_2 ) ;
F_241 ( V_2 ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_338 * V_12 = V_2 -> V_12 ;
struct V_51 * V_39 = V_2 -> V_39 ;
int V_202 ;
V_9 -> V_339 = V_12 -> V_340 ;
V_9 -> V_341 = V_12 -> V_314 ;
V_9 -> V_342 = V_12 -> V_343 ;
V_9 -> V_344 = V_12 -> V_345 ;
V_9 -> V_346 = V_12 -> V_347 ;
V_9 -> V_274 . V_258 . V_348 ( V_9 ) ;
V_9 -> V_185 . V_349 = 2 ;
V_9 -> V_185 . V_350 = 2 ;
F_246 ( & V_2 -> V_257 ) ;
V_202 = V_9 -> V_185 . V_258 . V_317 ( V_9 ) ;
if ( V_202 ) {
F_247 ( & V_12 -> V_13 ,
L_32 ) ;
} else {
V_202 = V_9 -> V_185 . V_258 . V_318 ( V_9 ) ;
if ( V_202 ) {
F_46 ( L_33 , V_202 ) ;
goto V_203;
}
F_200 ( V_2 ) ;
V_202 = V_9 -> V_185 . V_258 . V_351 ( V_9 , V_9 -> V_185 . V_269 ) ;
if ( V_202 )
F_247 ( & V_12 -> V_13 , L_34 ) ;
else if ( F_248 ( V_2 -> V_9 . V_185 . V_269 ) )
F_247 ( & V_12 -> V_13 ,
L_35 ) ;
memcpy ( V_39 -> V_147 , V_9 -> V_185 . V_269 , V_39 -> V_319 ) ;
}
if ( ! F_203 ( V_39 -> V_147 ) ) {
F_247 ( & V_12 -> V_13 , L_36 ) ;
F_249 ( V_39 ) ;
memcpy ( V_9 -> V_185 . V_269 , V_39 -> V_147 , V_39 -> V_319 ) ;
}
V_2 -> V_153 = 1 ;
V_2 -> V_168 = 1 ;
V_2 -> V_329 = V_352 ;
V_2 -> V_330 = V_353 ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_203:
return V_202 ;
}
void F_250 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_316 , & V_2 -> V_4 ) )
return;
F_251 ( V_293 , V_2 -> V_37 . V_292 ,
V_2 -> V_37 . V_277 ) ;
F_251 ( V_298 , V_2 -> V_37 . V_297 ,
V_2 -> V_37 . V_278 ) ;
F_252 ( V_295 , V_296 ,
V_2 -> V_37 . V_294 ,
V_2 -> V_37 . V_284 ) ;
F_252 ( V_300 , V_301 ,
V_2 -> V_37 . V_299 ,
V_2 -> V_37 . V_287 ) ;
F_251 ( V_303 , V_2 -> V_37 . V_302 ,
V_2 -> V_37 . V_290 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ ) {
V_2 -> V_354 +=
V_2 -> V_90 [ V_59 ] -> V_354 ;
V_2 -> V_90 [ V_59 ] -> V_354 = 0 ;
}
}
static void F_253 ( unsigned long V_137 )
{
struct V_1 * V_2 = (struct V_1 * ) V_137 ;
F_205 ( & V_2 -> V_313 , ( V_355 * 2 ) + V_74 ) ;
F_1 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_49 & V_50 ) )
return;
V_2 -> V_49 &= ~ V_50 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_316 , & V_2 -> V_4 ) )
return;
V_2 -> V_356 ++ ;
F_219 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_357 = 0 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_316 , & V_2 -> V_4 ) )
return;
if ( F_49 ( V_2 -> V_39 ) ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ )
F_256 ( V_2 -> V_28 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_165 - V_166 ; V_59 ++ ) {
struct V_52 * V_358 = V_2 -> V_53 [ V_59 ] ;
if ( V_358 -> V_149 . V_36 || V_358 -> V_70 . V_36 )
V_357 |= 1 << V_59 ;
}
F_19 ( V_9 , V_359 , V_357 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_360 = V_2 -> V_360 ;
bool V_361 = V_2 -> V_361 ;
T_10 V_202 ;
F_177 ( & V_2 -> V_257 ) ;
V_202 = V_9 -> V_185 . V_258 . V_362 ( V_9 , & V_360 , & V_361 , false ) ;
F_178 ( & V_2 -> V_257 ) ;
if ( V_202 && F_258 ( V_74 , V_2 -> V_320 + ( 10 * V_355 ) ) ) {
V_2 -> V_49 |= V_50 ;
V_361 = false ;
}
V_2 -> V_361 = V_361 ;
V_2 -> V_360 = V_360 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
if ( F_49 ( V_39 ) )
return;
F_247 ( & V_2 -> V_12 -> V_13 , L_37 ,
( V_2 -> V_360 == V_363 ) ?
L_38 :
( V_2 -> V_360 == V_364 ) ?
L_39 :
( V_2 -> V_360 == V_365 ) ?
L_40 :
L_41 ) ;
F_260 ( V_39 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
V_2 -> V_360 = 0 ;
if ( ! F_49 ( V_39 ) )
return;
F_247 ( & V_2 -> V_12 -> V_13 , L_42 ) ;
F_214 ( V_39 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_316 , & V_2 -> V_4 ) )
return;
F_257 ( V_2 ) ;
if ( V_2 -> V_361 )
F_259 ( V_2 ) ;
else
F_261 ( V_2 ) ;
F_250 ( V_2 ) ;
}
static void F_263 ( struct V_366 * V_367 )
{
struct V_1 * V_2 = F_112 ( V_367 ,
struct V_1 ,
V_7 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( F_14 ( V_9 -> V_11 ) ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_264 () ;
F_212 ( V_2 ) ;
F_265 () ;
}
return;
}
F_266 ( V_2 ) ;
F_254 ( V_2 ) ;
F_262 ( V_2 ) ;
F_255 ( V_2 ) ;
F_5 ( V_2 ) ;
}
void F_267 ( struct V_27 * V_28 )
{
F_209 ( V_28 ) ;
F_268 ( V_28 -> V_61 ) ;
V_28 -> V_61 = NULL ;
if ( ! V_28 -> V_315 )
return;
F_269 ( V_28 -> V_13 , V_28 -> V_130 , V_28 -> V_315 ,
V_28 -> V_33 ) ;
V_28 -> V_315 = NULL ;
}
static void F_270 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ )
if ( V_2 -> V_28 [ V_59 ] -> V_315 )
F_267 ( V_2 -> V_28 [ V_59 ] ) ;
}
int F_271 ( struct V_27 * V_28 )
{
int V_130 ;
V_130 = sizeof( struct V_29 ) * V_28 -> V_43 ;
V_28 -> V_61 = F_272 ( V_130 ) ;
if ( ! V_28 -> V_61 )
goto V_202;
V_28 -> V_130 = V_28 -> V_43 * sizeof( union V_54 ) ;
V_28 -> V_130 = F_84 ( V_28 -> V_130 , 4096 ) ;
V_28 -> V_315 = F_273 ( V_28 -> V_13 , V_28 -> V_130 ,
& V_28 -> V_33 , V_327 ) ;
if ( ! V_28 -> V_315 )
goto V_202;
return 0 ;
V_202:
F_268 ( V_28 -> V_61 ) ;
V_28 -> V_61 = NULL ;
F_136 ( & V_2 -> V_9 , L_43 ) ;
return - V_331 ;
}
static int F_274 ( struct V_1 * V_2 )
{
int V_59 , V_202 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ ) {
V_202 = F_271 ( V_2 -> V_28 [ V_59 ] ) ;
if ( ! V_202 )
continue;
F_136 ( & V_2 -> V_9 , L_44 , V_59 ) ;
break;
}
return V_202 ;
}
int F_275 ( struct V_27 * V_90 )
{
int V_130 ;
V_130 = sizeof( struct V_101 ) * V_90 -> V_43 ;
V_90 -> V_110 = F_272 ( V_130 ) ;
if ( ! V_90 -> V_110 )
goto V_202;
V_90 -> V_130 = V_90 -> V_43 * sizeof( union V_78 ) ;
V_90 -> V_130 = F_84 ( V_90 -> V_130 , 4096 ) ;
V_90 -> V_315 = F_273 ( V_90 -> V_13 , V_90 -> V_130 ,
& V_90 -> V_33 , V_327 ) ;
if ( ! V_90 -> V_315 )
goto V_202;
return 0 ;
V_202:
F_268 ( V_90 -> V_110 ) ;
V_90 -> V_110 = NULL ;
F_10 ( V_90 -> V_13 , L_45 ) ;
return - V_331 ;
}
static int F_276 ( struct V_1 * V_2 )
{
int V_59 , V_202 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ ) {
V_202 = F_275 ( V_2 -> V_90 [ V_59 ] ) ;
if ( ! V_202 )
continue;
F_136 ( & V_2 -> V_9 , L_46 , V_59 ) ;
break;
}
return V_202 ;
}
void F_277 ( struct V_27 * V_90 )
{
F_207 ( V_90 ) ;
F_268 ( V_90 -> V_110 ) ;
V_90 -> V_110 = NULL ;
F_269 ( V_90 -> V_13 , V_90 -> V_130 , V_90 -> V_315 ,
V_90 -> V_33 ) ;
V_90 -> V_315 = NULL ;
}
static void F_278 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ )
if ( V_2 -> V_90 [ V_59 ] -> V_315 )
F_277 ( V_2 -> V_90 [ V_59 ] ) ;
}
static int F_279 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_202 ;
if ( ! V_2 -> V_165 )
return - V_331 ;
if ( V_9 -> V_368 ) {
F_218 ( V_2 ) ;
if ( V_9 -> V_368 ) {
V_202 = V_260 ;
F_46 ( L_47 ) ;
goto V_369;
}
}
if ( F_2 ( V_370 , & V_2 -> V_4 ) )
return - V_371 ;
F_214 ( V_39 ) ;
V_202 = F_274 ( V_2 ) ;
if ( V_202 )
goto V_372;
V_202 = F_276 ( V_2 ) ;
if ( V_202 )
goto V_373;
F_197 ( V_2 ) ;
F_132 ( V_2 ) ;
V_202 = F_139 ( V_2 ) ;
if ( V_202 )
goto V_374;
F_202 ( V_2 ) ;
return 0 ;
V_374:
F_212 ( V_2 ) ;
V_373:
F_278 ( V_2 ) ;
V_372:
F_270 ( V_2 ) ;
F_218 ( V_2 ) ;
V_369:
return V_202 ;
}
static int F_280 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
F_212 ( V_2 ) ;
F_140 ( V_2 ) ;
F_270 ( V_2 ) ;
F_278 ( V_2 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_51 * V_13 = V_2 -> V_39 ;
if ( ! ( V_2 -> V_49 & V_276 ) )
return;
V_2 -> V_49 &= ~ V_276 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_316 , & V_2 -> V_4 ) )
return;
if ( F_281 ( V_13 ) )
F_280 ( V_13 ) ;
F_244 ( V_2 ) ;
F_243 ( V_2 ) ;
if ( F_281 ( V_13 ) )
F_279 ( V_13 ) ;
}
static void F_282 ( struct V_27 * V_28 ,
T_1 V_375 , T_1 V_376 ,
T_1 V_377 )
{
struct V_378 * V_379 ;
T_6 V_59 = V_28 -> V_72 ;
V_379 = F_283 ( V_28 , V_59 ) ;
V_59 ++ ;
V_28 -> V_72 = ( V_59 < V_28 -> V_43 ) ? V_59 : 0 ;
V_376 |= V_380 | V_381 ;
V_379 -> V_375 = F_40 ( V_375 ) ;
V_379 -> V_382 = 0 ;
V_379 -> V_383 = F_40 ( V_376 ) ;
V_379 -> V_377 = F_40 ( V_377 ) ;
}
static int F_284 ( struct V_27 * V_28 ,
struct V_29 * V_384 ,
T_2 * V_385 )
{
struct V_76 * V_31 = V_384 -> V_31 ;
T_1 V_375 , V_376 ;
T_1 V_377 , V_386 ;
int V_202 ;
if ( V_31 -> V_88 != V_387 )
return 0 ;
if ( ! F_285 ( V_31 ) )
return 0 ;
V_202 = F_286 ( V_31 , 0 ) ;
if ( V_202 < 0 )
return V_202 ;
V_376 = V_388 ;
if ( V_384 -> V_98 == F_66 ( V_389 ) ) {
struct V_390 * V_391 = F_287 ( V_31 ) ;
V_391 -> V_392 = 0 ;
V_391 -> V_393 = 0 ;
F_288 ( V_31 ) -> V_393 = ~ F_289 ( V_391 -> V_394 ,
V_391 -> V_395 , 0 ,
V_396 ,
0 ) ;
V_376 |= V_397 ;
V_384 -> V_398 |= V_399 |
V_400 |
V_401 ;
} else if ( F_290 ( V_31 ) ) {
F_291 ( V_31 ) -> V_402 = 0 ;
F_288 ( V_31 ) -> V_393 =
~ F_292 ( & F_291 ( V_31 ) -> V_394 ,
& F_291 ( V_31 ) -> V_395 ,
0 , V_396 , 0 ) ;
V_384 -> V_398 |= V_399 |
V_400 ;
}
V_386 = F_293 ( V_31 ) ;
* V_385 += V_386 ;
* V_385 = F_294 ( V_31 ) + V_386 ;
V_384 -> V_67 = F_80 ( V_31 ) -> V_67 ;
V_384 -> V_66 += ( V_384 -> V_67 - 1 ) * * V_385 ;
V_377 = V_386 << V_403 ;
V_377 |= F_80 ( V_31 ) -> V_404 << V_405 ;
V_377 |= 1 << V_406 ;
V_375 = F_295 ( V_31 ) ;
V_375 |= F_296 ( V_31 ) << V_407 ;
V_375 |= V_384 -> V_398 & V_408 ;
F_282 ( V_28 , V_375 ,
V_376 , V_377 ) ;
return 1 ;
}
static void F_297 ( struct V_27 * V_28 ,
struct V_29 * V_384 )
{
struct V_76 * V_31 = V_384 -> V_31 ;
T_1 V_375 = 0 ;
T_1 V_377 = 0 ;
T_1 V_376 = 0 ;
if ( V_31 -> V_88 == V_387 ) {
T_2 V_409 = 0 ;
switch ( V_384 -> V_98 ) {
case F_66 ( V_389 ) :
V_375 |= F_295 ( V_31 ) ;
V_376 |= V_397 ;
V_409 = F_287 ( V_31 ) -> V_98 ;
break;
case F_66 ( V_410 ) :
V_375 |= F_295 ( V_31 ) ;
V_409 = F_291 ( V_31 ) -> V_411 ;
break;
default:
if ( F_16 ( F_298 () ) ) {
F_299 ( V_28 -> V_13 ,
L_48 ,
V_384 -> V_98 ) ;
}
break;
}
switch ( V_409 ) {
case V_396 :
V_376 |= V_388 ;
V_377 = F_293 ( V_31 ) <<
V_403 ;
break;
case V_412 :
V_376 |= V_413 ;
V_377 = sizeof( struct V_414 ) <<
V_403 ;
break;
case V_415 :
V_377 = sizeof( struct V_416 ) <<
V_403 ;
break;
default:
if ( F_16 ( F_298 () ) ) {
F_299 ( V_28 -> V_13 ,
L_49 ,
V_409 ) ;
}
break;
}
V_384 -> V_398 |= V_400 ;
}
V_375 |= F_296 ( V_31 ) << V_407 ;
V_375 |= V_384 -> V_398 & V_408 ;
F_282 ( V_28 , V_375 ,
V_376 , V_377 ) ;
}
static T_11 F_300 ( T_1 V_398 )
{
T_11 V_417 = F_40 ( V_418 |
V_419 |
V_420 ) ;
if ( V_398 & V_421 )
V_417 |= F_40 ( V_422 ) ;
if ( V_398 & V_399 )
V_417 |= F_40 ( V_423 ) ;
return V_417 ;
}
static void F_301 ( union V_54 * V_55 ,
T_1 V_398 , unsigned int V_424 )
{
T_11 V_425 = F_40 ( V_424 << V_426 ) ;
if ( V_398 & V_400 )
V_425 |= F_40 ( V_427 ) ;
if ( V_398 & V_401 )
V_425 |= F_40 ( V_428 ) ;
if ( V_398 & V_399 )
V_425 |= F_40 ( 1 << V_406 ) ;
V_425 |= F_40 ( V_429 ) ;
V_55 -> V_111 . V_425 = V_425 ;
}
static void F_302 ( struct V_27 * V_28 ,
struct V_29 * V_384 ,
const T_2 V_385 )
{
T_7 V_33 ;
struct V_76 * V_31 = V_384 -> V_31 ;
struct V_29 * V_30 ;
union V_54 * V_55 ;
struct V_115 * V_116 = & F_80 ( V_31 ) -> V_117 [ 0 ] ;
unsigned int V_121 = V_31 -> V_121 ;
unsigned int V_130 = F_303 ( V_31 ) ;
unsigned int V_424 = V_31 -> V_32 - V_385 ;
T_1 V_398 = V_384 -> V_398 ;
T_11 V_417 ;
T_6 V_59 = V_28 -> V_72 ;
V_55 = F_38 ( V_28 , V_59 ) ;
F_301 ( V_55 , V_398 , V_424 ) ;
V_417 = F_300 ( V_398 ) ;
V_33 = F_304 ( V_28 -> V_13 , V_31 -> V_137 , V_130 , V_34 ) ;
if ( F_73 ( V_28 -> V_13 , V_33 ) )
goto V_430;
F_27 ( V_384 , V_32 , V_130 ) ;
F_305 ( V_384 , V_33 , V_33 ) ;
V_55 -> V_111 . V_431 = F_76 ( V_33 ) ;
for (; ; ) {
while ( F_16 ( V_130 > V_432 ) ) {
V_55 -> V_111 . V_433 =
V_417 | F_40 ( V_432 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_33 += V_432 ;
V_130 -= V_432 ;
V_55 -> V_111 . V_431 = F_76 ( V_33 ) ;
V_55 -> V_111 . V_425 = 0 ;
}
if ( F_42 ( ! V_121 ) )
break;
V_55 -> V_111 . V_433 = V_417 | F_40 ( V_130 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_130 = F_306 ( V_116 ) ;
V_121 -= V_130 ;
V_33 = F_307 ( V_28 -> V_13 , V_116 , 0 , V_130 ,
V_34 ) ;
if ( F_73 ( V_28 -> V_13 , V_33 ) )
goto V_430;
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_27 ( V_30 , V_32 , V_130 ) ;
F_305 ( V_30 , V_33 , V_33 ) ;
V_55 -> V_111 . V_431 = F_76 ( V_33 ) ;
V_55 -> V_111 . V_425 = 0 ;
V_116 ++ ;
}
V_417 |= F_40 ( V_130 ) | F_40 ( V_434 ) ;
V_55 -> V_111 . V_433 = V_417 ;
V_384 -> V_73 = V_74 ;
F_77 () ;
V_384 -> V_35 = V_55 ;
V_59 ++ ;
if ( V_59 == V_28 -> V_43 )
V_59 = 0 ;
V_28 -> V_72 = V_59 ;
F_78 ( V_28 , V_59 ) ;
return;
V_430:
F_10 ( V_28 -> V_13 , L_50 ) ;
for (; ; ) {
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_21 ( V_28 , V_30 ) ;
if ( V_30 == V_384 )
break;
if ( V_59 == 0 )
V_59 = V_28 -> V_43 ;
V_59 -- ;
}
V_28 -> V_72 = V_59 ;
}
static int F_308 ( struct V_27 * V_28 , int V_130 )
{
F_47 ( V_28 -> V_39 , V_28 -> V_71 ) ;
F_51 () ;
if ( F_42 ( F_50 ( V_28 ) < V_130 ) )
return - V_371 ;
F_309 ( V_28 -> V_39 , V_28 -> V_71 ) ;
++ V_28 -> V_46 . V_75 ;
return 0 ;
}
static int F_310 ( struct V_27 * V_28 , int V_130 )
{
if ( F_42 ( F_50 ( V_28 ) >= V_130 ) )
return 0 ;
return F_308 ( V_28 , V_130 ) ;
}
static int F_311 ( struct V_76 * V_31 , struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_29 * V_384 ;
struct V_27 * V_28 ;
int V_435 ;
T_1 V_398 = 0 ;
T_6 V_43 = F_312 ( F_303 ( V_31 ) ) ;
#if V_105 > V_432
unsigned short V_436 ;
#endif
T_2 V_385 = 0 ;
T_2 * V_437 = F_313 ( V_31 , 0 , 0 , NULL ) ;
if ( ! V_437 || F_314 ( V_437 ) ) {
F_22 ( V_31 ) ;
return V_438 ;
}
V_28 = V_2 -> V_28 [ V_31 -> V_439 ] ;
#if V_105 > V_432
for ( V_436 = 0 ; V_436 < F_80 ( V_31 ) -> V_134 ; V_436 ++ )
V_43 += F_312 ( F_80 ( V_31 ) -> V_117 [ V_436 ] . V_130 ) ;
#else
V_43 += F_80 ( V_31 ) -> V_134 ;
#endif
if ( F_310 ( V_28 , V_43 + 3 ) ) {
V_28 -> V_46 . V_440 ++ ;
return V_441 ;
}
V_384 = & V_28 -> V_61 [ V_28 -> V_72 ] ;
V_384 -> V_31 = V_31 ;
V_384 -> V_66 = V_31 -> V_32 ;
V_384 -> V_67 = 1 ;
if ( F_315 ( V_31 ) ) {
V_398 |= F_316 ( V_31 ) ;
V_398 <<= V_442 ;
V_398 |= V_421 ;
}
V_384 -> V_398 = V_398 ;
V_384 -> V_98 = F_317 ( V_31 ) ;
V_435 = F_284 ( V_28 , V_384 , & V_385 ) ;
if ( V_435 < 0 )
goto V_443;
else if ( ! V_435 )
F_297 ( V_28 , V_384 ) ;
F_302 ( V_28 , V_384 , V_385 ) ;
F_310 ( V_28 , V_444 ) ;
return V_438 ;
V_443:
F_22 ( V_384 -> V_31 ) ;
V_384 -> V_31 = NULL ;
return V_438 ;
}
static int F_318 ( struct V_51 * V_39 , void * V_445 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_446 * V_269 = V_445 ;
if ( ! F_203 ( V_269 -> V_447 ) )
return - V_448 ;
memcpy ( V_39 -> V_147 , V_269 -> V_447 , V_39 -> V_319 ) ;
memcpy ( V_9 -> V_185 . V_269 , V_269 -> V_447 , V_39 -> V_319 ) ;
F_177 ( & V_2 -> V_257 ) ;
V_9 -> V_185 . V_258 . V_310 ( V_9 , 0 , V_9 -> V_185 . V_269 , 0 ) ;
F_178 ( & V_2 -> V_257 ) ;
return 0 ;
}
static int F_319 ( struct V_51 * V_39 , int V_449 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_450 = V_449 + V_254 + V_255 ;
int V_451 = V_452 ;
switch ( V_2 -> V_9 . V_326 ) {
case V_306 :
case V_305 :
V_451 = V_453 ;
break;
default:
if ( V_2 -> V_9 . V_185 . type != V_454 )
V_451 = V_453 ;
break;
}
if ( ( V_449 < 68 ) || ( V_450 > V_451 ) )
return - V_455 ;
F_136 ( V_9 , L_51 ,
V_39 -> V_253 , V_449 ) ;
V_39 -> V_253 = V_449 ;
F_175 ( V_9 , V_450 ) ;
return 0 ;
}
static void F_320 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ )
F_128 ( 0 , V_2 -> V_53 [ V_59 ] ) ;
}
static int F_321 ( struct V_338 * V_12 , T_12 V_4 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
#ifdef F_323
int V_456 = 0 ;
#endif
F_324 ( V_39 ) ;
if ( F_281 ( V_39 ) ) {
F_264 () ;
F_212 ( V_2 ) ;
F_140 ( V_2 ) ;
F_270 ( V_2 ) ;
F_278 ( V_2 ) ;
F_265 () ;
}
F_244 ( V_2 ) ;
#ifdef F_323
V_456 = F_325 ( V_12 ) ;
if ( V_456 )
return V_456 ;
#endif
if ( ! F_3 ( V_457 , & V_2 -> V_4 ) )
F_326 ( V_12 ) ;
return 0 ;
}
static int F_327 ( struct V_338 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
T_1 V_202 ;
F_328 ( V_12 ) ;
F_325 ( V_12 ) ;
V_202 = F_329 ( V_12 ) ;
if ( V_202 ) {
F_10 ( & V_12 -> V_13 , L_52 ) ;
return V_202 ;
}
F_7 () ;
F_8 ( V_457 , & V_2 -> V_4 ) ;
F_330 ( V_12 ) ;
F_218 ( V_2 ) ;
F_264 () ;
V_202 = F_243 ( V_2 ) ;
F_265 () ;
if ( V_202 ) {
F_10 ( & V_12 -> V_13 , L_53 ) ;
return V_202 ;
}
if ( F_281 ( V_39 ) ) {
V_202 = F_279 ( V_39 ) ;
if ( V_202 )
return V_202 ;
}
F_331 ( V_39 ) ;
return V_202 ;
}
static void F_332 ( struct V_338 * V_12 )
{
F_321 ( V_12 , V_458 ) ;
}
static struct V_459 * F_333 ( struct V_51 * V_39 ,
struct V_459 * V_37 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
unsigned int V_460 ;
T_5 V_69 , V_38 ;
const struct V_27 * V_36 ;
int V_59 ;
F_250 ( V_2 ) ;
V_37 -> V_461 = V_2 -> V_37 . V_290 - V_2 -> V_37 . V_291 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_196 ; V_59 ++ ) {
V_36 = V_2 -> V_90 [ V_59 ] ;
do {
V_460 = F_334 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_335 ( & V_36 -> V_68 , V_460 ) );
V_37 -> V_462 += V_69 ;
V_37 -> V_463 += V_38 ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_198 ; V_59 ++ ) {
V_36 = V_2 -> V_28 [ V_59 ] ;
do {
V_460 = F_334 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_335 ( & V_36 -> V_68 , V_460 ) );
V_37 -> V_464 += V_69 ;
V_37 -> V_465 += V_38 ;
}
return V_37 ;
}
static void F_336 ( struct V_51 * V_13 )
{
V_13 -> V_466 = & V_467 ;
F_337 ( V_13 ) ;
V_13 -> V_468 = 5 * V_355 ;
}
static int F_338 ( struct V_338 * V_12 , const struct V_469 * V_470 )
{
struct V_51 * V_39 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = NULL ;
const struct V_471 * V_472 = V_473 [ V_470 -> V_474 ] ;
int V_202 , V_475 ;
bool V_476 = false ;
V_202 = F_339 ( V_12 ) ;
if ( V_202 )
return V_202 ;
if ( ! F_340 ( & V_12 -> V_13 , F_148 ( 64 ) ) ) {
V_475 = 1 ;
} else {
V_202 = F_340 ( & V_12 -> V_13 , F_148 ( 32 ) ) ;
if ( V_202 ) {
F_10 ( & V_12 -> V_13 , L_54 ) ;
goto V_477;
}
V_475 = 0 ;
}
V_202 = F_341 ( V_12 , V_478 ) ;
if ( V_202 ) {
F_10 ( & V_12 -> V_13 , L_55 , V_202 ) ;
goto V_479;
}
F_330 ( V_12 ) ;
V_39 = F_342 ( sizeof( struct V_1 ) ,
V_480 ) ;
if ( ! V_39 ) {
V_202 = - V_331 ;
goto V_481;
}
F_343 ( V_39 , & V_12 -> V_13 ) ;
V_2 = F_30 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_12 = V_12 ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_10 = V_2 ;
V_2 -> V_482 = F_344 ( V_483 , V_484 ) ;
F_325 ( V_12 ) ;
V_9 -> V_11 = F_345 ( F_346 ( V_12 , 0 ) ,
F_347 ( V_12 , 0 ) ) ;
V_2 -> V_222 = V_9 -> V_11 ;
if ( ! V_9 -> V_11 ) {
V_202 = - V_261 ;
goto V_485;
}
F_336 ( V_39 ) ;
memcpy ( & V_9 -> V_185 . V_258 , V_472 -> V_486 , sizeof( V_9 -> V_185 . V_258 ) ) ;
V_9 -> V_185 . type = V_472 -> V_185 ;
memcpy ( & V_9 -> V_274 . V_258 , & V_487 ,
sizeof( struct V_488 ) ) ;
V_202 = F_245 ( V_2 ) ;
if ( V_202 )
goto V_489;
if ( ! F_203 ( V_39 -> V_147 ) ) {
F_46 ( L_56 ) ;
V_202 = - V_261 ;
goto V_489;
}
V_39 -> V_490 = V_491 |
V_492 |
V_493 |
V_494 |
V_495 |
V_81 ;
V_39 -> V_80 = V_39 -> V_490 |
V_496 |
V_497 |
V_498 ;
V_39 -> V_499 |= V_494 |
V_495 |
V_492 |
V_493 |
V_491 ;
if ( V_475 )
V_39 -> V_80 |= V_500 ;
V_39 -> V_501 |= V_502 ;
if ( F_14 ( V_9 -> V_11 ) ) {
V_202 = - V_261 ;
goto V_489;
}
F_348 ( & V_2 -> V_313 , & F_253 ,
( unsigned long ) V_2 ) ;
F_349 ( & V_2 -> V_7 , F_263 ) ;
F_179 ( V_14 , & V_2 -> V_4 ) ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
V_202 = F_243 ( V_2 ) ;
if ( V_202 )
goto V_489;
strcpy ( V_39 -> V_210 , L_57 ) ;
V_202 = F_350 ( V_39 ) ;
if ( V_202 )
goto V_503;
F_351 ( V_12 , V_39 ) ;
F_214 ( V_39 ) ;
F_199 ( V_2 ) ;
F_247 ( & V_12 -> V_13 , L_58 , V_39 -> V_147 ) ;
F_247 ( & V_12 -> V_13 , L_59 , V_9 -> V_185 . type ) ;
switch ( V_9 -> V_185 . type ) {
case V_252 :
F_247 ( & V_12 -> V_13 , L_60 ) ;
break;
case V_504 :
F_247 ( & V_12 -> V_13 , L_61 ) ;
break;
case V_454 :
default:
F_247 ( & V_12 -> V_13 , L_62 ) ;
break;
}
return 0 ;
V_503:
F_244 ( V_2 ) ;
V_489:
F_241 ( V_2 ) ;
F_352 ( V_2 -> V_222 ) ;
V_485:
V_476 = ! F_3 ( V_457 , & V_2 -> V_4 ) ;
F_353 ( V_39 ) ;
V_481:
F_354 ( V_12 ) ;
V_479:
V_477:
if ( ! V_2 || V_476 )
F_326 ( V_12 ) ;
return V_202 ;
}
static void F_355 ( struct V_338 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 ;
bool V_476 ;
if ( ! V_39 )
return;
V_2 = F_30 ( V_39 ) ;
F_179 ( V_5 , & V_2 -> V_4 ) ;
F_356 ( & V_2 -> V_7 ) ;
if ( V_39 -> V_505 == V_506 )
F_357 ( V_39 ) ;
F_244 ( V_2 ) ;
F_241 ( V_2 ) ;
F_352 ( V_2 -> V_222 ) ;
F_354 ( V_12 ) ;
F_136 ( & V_2 -> V_9 , L_63 ) ;
V_476 = ! F_3 ( V_457 , & V_2 -> V_4 ) ;
F_353 ( V_39 ) ;
if ( V_476 )
F_326 ( V_12 ) ;
}
static T_13 F_358 ( struct V_338 * V_12 ,
T_14 V_4 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( ! F_2 ( V_14 , & V_2 -> V_4 ) )
return V_507 ;
F_264 () ;
F_324 ( V_39 ) ;
if ( V_4 == V_508 ) {
F_265 () ;
return V_507 ;
}
if ( F_281 ( V_39 ) )
F_212 ( V_2 ) ;
if ( ! F_3 ( V_457 , & V_2 -> V_4 ) )
F_326 ( V_12 ) ;
F_265 () ;
return V_509 ;
}
static T_13 F_359 ( struct V_338 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_329 ( V_12 ) ) {
F_10 ( & V_12 -> V_13 ,
L_64 ) ;
return V_507 ;
}
F_7 () ;
F_8 ( V_457 , & V_2 -> V_4 ) ;
F_330 ( V_12 ) ;
F_218 ( V_2 ) ;
return V_510 ;
}
static void F_360 ( struct V_338 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_281 ( V_39 ) )
F_206 ( V_2 ) ;
F_331 ( V_39 ) ;
}
static int T_15 F_361 ( void )
{
int V_511 ;
F_194 ( L_65 , V_512 ,
V_513 ) ;
F_194 ( L_66 , V_514 ) ;
V_511 = F_362 ( & V_515 ) ;
return V_511 ;
}
static void T_16 F_363 ( void )
{
F_364 ( & V_515 ) ;
}
char * F_365 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
return V_2 -> V_39 -> V_210 ;
}
