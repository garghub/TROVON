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
T_6 V_80 ;
if ( ! ( V_36 -> V_39 -> V_81 & V_82 ) )
return;
V_80 = F_61 ( V_79 -> V_63 . V_83 . V_84 . V_85 . V_86 ) &
V_87 ;
if ( ! V_80 )
return;
F_62 ( V_31 , F_63 ( V_79 -> V_63 . V_83 . V_88 . V_89 ) ,
( V_90 & ( 1ul << V_80 ) ) ?
V_91 : V_92 ) ;
}
static inline void F_64 ( struct V_27 * V_36 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
F_65 ( V_31 ) ;
if ( ! ( V_36 -> V_39 -> V_81 & V_93 ) )
return;
if ( F_66 ( V_79 , V_94 ) &&
F_66 ( V_79 , V_95 ) ) {
V_36 -> V_96 . V_97 ++ ;
return;
}
if ( ! F_66 ( V_79 , V_98 ) )
return;
if ( F_66 ( V_79 , V_99 ) ) {
V_36 -> V_96 . V_97 ++ ;
return;
}
V_31 -> V_100 = V_101 ;
}
static void F_67 ( struct V_27 * V_102 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
F_60 ( V_102 , V_79 , V_31 ) ;
F_64 ( V_102 , V_79 , V_31 ) ;
if ( F_66 ( V_79 , V_103 ) ) {
T_6 V_104 = F_61 ( V_79 -> V_63 . V_105 . V_106 ) ;
unsigned long * V_107 = F_30 ( V_102 -> V_39 ) ;
if ( F_2 ( V_104 & V_108 , V_107 ) )
F_68 ( V_31 , F_69 ( V_109 ) , V_104 ) ;
}
V_31 -> V_110 = F_70 ( V_31 , V_102 -> V_39 ) ;
}
static bool F_71 ( struct V_27 * V_102 ,
union V_78 * V_79 )
{
T_1 V_111 = V_102 -> V_60 + 1 ;
V_111 = ( V_111 < V_102 -> V_43 ) ? V_111 : 0 ;
V_102 -> V_60 = V_111 ;
F_41 ( F_72 ( V_102 , V_111 ) ) ;
if ( F_42 ( F_66 ( V_79 , V_112 ) ) )
return false ;
return true ;
}
static bool F_73 ( struct V_27 * V_102 ,
struct V_113 * V_114 )
{
struct V_115 * V_115 = V_114 -> V_115 ;
T_7 V_33 = V_114 -> V_33 ;
if ( F_42 ( V_115 ) )
return true ;
V_115 = F_74 () ;
if ( F_16 ( ! V_115 ) ) {
V_102 -> V_96 . V_116 ++ ;
return false ;
}
V_33 = F_75 ( V_102 -> V_13 , V_115 , 0 ,
V_117 , V_118 ) ;
if ( F_76 ( V_102 -> V_13 , V_33 ) ) {
F_77 ( V_115 ) ;
V_102 -> V_96 . V_119 ++ ;
return false ;
}
V_114 -> V_33 = V_33 ;
V_114 -> V_115 = V_115 ;
V_114 -> V_120 = 0 ;
return true ;
}
static void F_78 ( struct V_27 * V_102 ,
T_6 V_121 )
{
union V_78 * V_79 ;
struct V_113 * V_114 ;
unsigned int V_59 = V_102 -> V_72 ;
if ( ! V_121 || ! V_102 -> V_39 )
return;
V_79 = F_72 ( V_102 , V_59 ) ;
V_114 = & V_102 -> V_122 [ V_59 ] ;
V_59 -= V_102 -> V_43 ;
do {
if ( ! F_73 ( V_102 , V_114 ) )
break;
V_79 -> V_123 . V_124 = F_79 ( V_114 -> V_33 + V_114 -> V_120 ) ;
V_79 ++ ;
V_114 ++ ;
V_59 ++ ;
if ( F_16 ( ! V_59 ) ) {
V_79 = F_72 ( V_102 , 0 ) ;
V_114 = V_102 -> V_122 ;
V_59 -= V_102 -> V_43 ;
}
V_79 -> V_123 . V_125 = 0 ;
V_121 -- ;
} while ( V_121 );
V_59 += V_102 -> V_43 ;
if ( V_102 -> V_72 != V_59 ) {
V_102 -> V_72 = V_59 ;
V_102 -> V_126 = V_59 ;
F_80 () ;
F_81 ( V_102 , V_59 ) ;
}
}
static bool F_82 ( struct V_27 * V_102 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
if ( F_16 ( F_66 ( V_79 ,
V_127 ) ) ) {
struct V_51 * V_39 = V_102 -> V_39 ;
if ( ! ( V_39 -> V_81 & V_128 ) ) {
F_22 ( V_31 ) ;
return true ;
}
}
if ( F_83 ( V_31 ) )
return true ;
return false ;
}
static void F_84 ( struct V_27 * V_102 ,
struct V_113 * V_129 )
{
struct V_113 * V_130 ;
T_6 V_131 = V_102 -> V_126 ;
V_130 = & V_102 -> V_122 [ V_131 ] ;
V_131 ++ ;
V_102 -> V_126 = ( V_131 < V_102 -> V_43 ) ? V_131 : 0 ;
V_130 -> V_115 = V_129 -> V_115 ;
V_130 -> V_33 = V_129 -> V_33 ;
V_130 -> V_120 = V_129 -> V_120 ;
F_85 ( V_102 -> V_13 , V_130 -> V_33 ,
V_130 -> V_120 ,
V_132 ,
V_118 ) ;
}
static inline bool F_86 ( struct V_115 * V_115 )
{
return ( F_87 ( V_115 ) != F_88 () ) || F_89 ( V_115 ) ;
}
static bool F_90 ( struct V_27 * V_102 ,
struct V_113 * V_133 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
struct V_115 * V_115 = V_133 -> V_115 ;
unsigned char * V_134 = F_91 ( V_115 ) + V_133 -> V_120 ;
unsigned int V_135 = F_61 ( V_79 -> V_63 . V_105 . V_136 ) ;
#if ( V_117 < 8192 )
unsigned int V_137 = V_132 ;
#else
unsigned int V_137 = F_92 ( V_135 , V_138 ) ;
#endif
unsigned int V_139 ;
if ( F_16 ( F_93 ( V_31 ) ) )
goto V_140;
if ( F_42 ( V_135 <= V_141 ) ) {
memcpy ( F_94 ( V_31 , V_135 ) , V_134 , F_92 ( V_135 , sizeof( long ) ) ) ;
if ( F_42 ( ! F_86 ( V_115 ) ) )
return true ;
F_95 ( V_115 ) ;
return false ;
}
V_139 = F_96 ( V_134 , V_141 ) ;
memcpy ( F_94 ( V_31 , V_139 ) , V_134 , F_92 ( V_139 , sizeof( long ) ) ) ;
V_134 += V_139 ;
V_135 -= V_139 ;
V_140:
F_97 ( V_31 , F_98 ( V_31 ) -> V_142 , V_115 ,
( unsigned long ) V_134 & ~ V_143 , V_135 , V_137 ) ;
if ( F_16 ( F_86 ( V_115 ) ) )
return false ;
#if ( V_117 < 8192 )
if ( F_16 ( F_99 ( V_115 ) != 1 ) )
return false ;
V_133 -> V_120 ^= V_132 ;
#else
V_133 -> V_120 += V_137 ;
if ( V_133 -> V_120 > ( V_117 - V_132 ) )
return false ;
#endif
F_100 ( & V_115 -> V_144 ) ;
return true ;
}
static struct V_76 * F_101 ( struct V_27 * V_102 ,
union V_78 * V_79 ,
struct V_76 * V_31 )
{
struct V_113 * V_133 ;
struct V_115 * V_115 ;
V_133 = & V_102 -> V_122 [ V_102 -> V_60 ] ;
V_115 = V_133 -> V_115 ;
F_102 ( V_115 ) ;
if ( F_42 ( ! V_31 ) ) {
void * V_145 = F_91 ( V_115 ) +
V_133 -> V_120 ;
F_41 ( V_145 ) ;
#if V_138 < 128
F_41 ( V_145 + V_138 ) ;
#endif
V_31 = F_103 ( V_102 -> V_39 ,
V_141 ) ;
if ( F_16 ( ! V_31 ) ) {
V_102 -> V_96 . V_119 ++ ;
return NULL ;
}
F_102 ( V_31 -> V_146 ) ;
}
F_104 ( V_102 -> V_13 ,
V_133 -> V_33 ,
V_133 -> V_120 ,
V_132 ,
V_118 ) ;
if ( F_90 ( V_102 , V_133 , V_79 , V_31 ) ) {
F_84 ( V_102 , V_133 ) ;
} else {
F_26 ( V_102 -> V_13 , V_133 -> V_33 ,
V_117 , V_118 ) ;
}
V_133 -> V_33 = 0 ;
V_133 -> V_115 = NULL ;
return V_31 ;
}
static inline void F_105 ( struct V_1 * V_2 ,
T_1 V_147 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_19 ( V_9 , V_148 , V_147 ) ;
}
static int F_106 ( struct V_52 * V_53 ,
struct V_27 * V_102 ,
int V_58 )
{
unsigned int V_149 = 0 , V_150 = 0 ;
T_6 V_121 = F_50 ( V_102 ) ;
struct V_76 * V_31 = V_102 -> V_31 ;
while ( F_42 ( V_150 < V_58 ) ) {
union V_78 * V_79 ;
if ( V_121 >= V_151 ) {
F_78 ( V_102 , V_121 ) ;
V_121 = 0 ;
}
V_79 = F_72 ( V_102 , V_102 -> V_60 ) ;
if ( ! F_66 ( V_79 , V_152 ) )
break;
F_107 () ;
V_31 = F_101 ( V_102 , V_79 , V_31 ) ;
if ( ! V_31 )
break;
V_121 ++ ;
if ( F_71 ( V_102 , V_79 ) )
continue;
if ( F_82 ( V_102 , V_79 , V_31 ) ) {
V_31 = NULL ;
continue;
}
V_149 += V_31 -> V_32 ;
if ( ( V_31 -> V_153 == V_154 ||
V_31 -> V_153 == V_155 ) &&
F_108 ( V_102 -> V_39 -> V_156 ,
F_109 ( V_31 ) -> V_157 ) ) {
F_110 ( V_31 ) ;
continue;
}
F_67 ( V_102 , V_79 , V_31 ) ;
F_54 ( V_53 , V_31 ) ;
V_31 = NULL ;
V_150 ++ ;
}
V_102 -> V_31 = V_31 ;
F_43 ( & V_102 -> V_68 ) ;
V_102 -> V_37 . V_38 += V_150 ;
V_102 -> V_37 . V_69 += V_149 ;
F_44 ( & V_102 -> V_68 ) ;
V_53 -> V_158 . V_57 += V_150 ;
V_53 -> V_158 . V_56 += V_149 ;
return V_150 ;
}
static int F_111 ( struct V_159 * V_77 , int V_58 )
{
struct V_52 * V_53 =
F_112 ( V_77 , struct V_52 , V_77 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_27 * V_36 ;
int V_160 ;
bool V_161 = true ;
F_113 (ring, q_vector->tx)
V_161 &= F_37 ( V_53 , V_36 ) ;
#ifdef F_55
if ( ! F_114 ( V_53 ) )
return V_58 ;
#endif
if ( V_53 -> V_158 . V_43 > 1 )
V_160 = F_115 ( V_58 / V_53 -> V_158 . V_43 , 1 ) ;
else
V_160 = V_58 ;
F_113 (ring, q_vector->rx)
V_161 &= ( F_106 ( V_53 , V_36 ,
V_160 )
< V_160 ) ;
#ifdef F_55
F_116 ( V_53 ) ;
#endif
if ( ! V_161 )
return V_58 ;
F_117 ( V_77 ) ;
if ( V_2 -> V_162 & 1 )
F_118 ( V_53 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) )
F_105 ( V_2 ,
1 << V_53 -> V_163 ) ;
return 0 ;
}
void F_119 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_163 = V_53 -> V_163 ;
T_1 V_164 = V_53 -> V_165 & V_166 ;
V_164 |= V_167 ;
F_19 ( V_9 , F_120 ( V_163 ) , V_164 ) ;
}
static int F_121 ( struct V_159 * V_77 )
{
struct V_52 * V_53 =
F_112 ( V_77 , struct V_52 , V_77 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_27 * V_36 ;
int V_168 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return V_169 ;
if ( ! F_122 ( V_53 ) )
return V_170 ;
F_113 (ring, q_vector->rx) {
V_168 = F_106 ( V_53 , V_36 , 4 ) ;
#ifdef F_123
if ( V_168 )
V_36 -> V_37 . V_171 += V_168 ;
else
V_36 -> V_37 . V_172 ++ ;
#endif
if ( V_168 )
break;
}
F_124 ( V_53 ) ;
return V_168 ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
int V_173 , V_163 ;
V_173 = V_2 -> V_174 - V_175 ;
V_2 -> V_176 = 0 ;
for ( V_163 = 0 ; V_163 < V_173 ; V_163 ++ ) {
struct V_27 * V_36 ;
V_53 = V_2 -> V_53 [ V_163 ] ;
F_113 (ring, q_vector->rx)
F_17 ( V_2 , 0 , V_36 -> V_41 , V_163 ) ;
F_113 (ring, q_vector->tx)
F_17 ( V_2 , 1 , V_36 -> V_41 , V_163 ) ;
if ( V_53 -> V_70 . V_36 && ! V_53 -> V_158 . V_36 ) {
if ( V_2 -> V_177 == 1 )
V_53 -> V_165 = V_178 ;
else
V_53 -> V_165 = V_2 -> V_177 ;
} else {
if ( V_2 -> V_162 == 1 )
V_53 -> V_165 = V_179 ;
else
V_53 -> V_165 = V_2 -> V_162 ;
}
V_2 -> V_176 |= 1 << V_163 ;
F_119 ( V_53 ) ;
}
F_17 ( V_2 , - 1 , 1 , V_163 ) ;
V_2 -> V_180 = 1 << V_163 ;
V_2 -> V_176 |= V_2 -> V_180 ;
}
static void F_126 ( struct V_52 * V_53 ,
struct V_181 * V_182 )
{
int V_69 = V_182 -> V_56 ;
int V_38 = V_182 -> V_57 ;
T_1 V_183 ;
T_5 V_184 ;
T_2 V_185 = V_182 -> V_165 ;
if ( V_38 == 0 )
return;
V_183 = V_53 -> V_165 >> 2 ;
V_184 = V_69 / V_183 ;
switch ( V_185 ) {
case V_186 :
if ( V_184 > 10 )
V_185 = V_187 ;
break;
case V_187 :
if ( V_184 > 20 )
V_185 = V_188 ;
else if ( V_184 <= 10 )
V_185 = V_186 ;
break;
case V_188 :
if ( V_184 <= 20 )
V_185 = V_187 ;
break;
}
V_182 -> V_56 = 0 ;
V_182 -> V_57 = 0 ;
V_182 -> V_165 = V_185 ;
}
static void F_118 ( struct V_52 * V_53 )
{
T_1 V_189 = V_53 -> V_165 ;
T_2 V_190 ;
F_126 ( V_53 , & V_53 -> V_70 ) ;
F_126 ( V_53 , & V_53 -> V_158 ) ;
V_190 = F_115 ( V_53 -> V_158 . V_165 , V_53 -> V_70 . V_165 ) ;
switch ( V_190 ) {
case V_186 :
V_189 = V_191 ;
break;
case V_187 :
V_189 = V_179 ;
break;
case V_188 :
default:
V_189 = V_192 ;
break;
}
if ( V_189 != V_53 -> V_165 ) {
V_189 = ( 10 * V_189 * V_53 -> V_165 ) /
( ( 9 * V_189 ) + V_53 -> V_165 ) ;
V_53 -> V_165 = V_189 ;
F_119 ( V_53 ) ;
}
}
static T_8 F_127 ( int V_193 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
V_9 -> V_194 . V_195 = 1 ;
F_1 ( V_2 ) ;
F_19 ( V_9 , V_148 , V_2 -> V_180 ) ;
return V_196 ;
}
static T_8 F_128 ( int V_193 , void * V_146 )
{
struct V_52 * V_53 = V_146 ;
if ( V_53 -> V_158 . V_36 || V_53 -> V_70 . V_36 )
F_129 ( & V_53 -> V_77 ) ;
return V_196 ;
}
static inline void F_130 ( struct V_1 * V_197 , int V_163 ,
int V_198 )
{
struct V_52 * V_53 = V_197 -> V_53 [ V_163 ] ;
V_197 -> V_102 [ V_198 ] -> V_199 = V_53 -> V_158 . V_36 ;
V_53 -> V_158 . V_36 = V_197 -> V_102 [ V_198 ] ;
V_53 -> V_158 . V_43 ++ ;
}
static inline void F_131 ( struct V_1 * V_197 , int V_163 ,
int V_200 )
{
struct V_52 * V_53 = V_197 -> V_53 [ V_163 ] ;
V_197 -> V_28 [ V_200 ] -> V_199 = V_53 -> V_70 . V_36 ;
V_53 -> V_70 . V_36 = V_197 -> V_28 [ V_200 ] ;
V_53 -> V_70 . V_43 ++ ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_173 ;
int V_201 = 0 ;
int V_202 = 0 , V_203 = 0 ;
int V_204 = V_2 -> V_205 ;
int V_206 = V_2 -> V_207 ;
int V_59 , V_208 ;
int V_209 , V_210 ;
int V_211 = 0 ;
V_173 = V_2 -> V_174 - V_175 ;
if ( V_173 == V_2 -> V_205 + V_2 -> V_207 ) {
for (; V_202 < V_204 ; V_201 ++ , V_202 ++ )
F_130 ( V_2 , V_201 , V_202 ) ;
for (; V_203 < V_206 ; V_201 ++ , V_203 ++ )
F_131 ( V_2 , V_201 , V_203 ) ;
goto V_212;
}
for ( V_59 = V_201 ; V_59 < V_173 ; V_59 ++ ) {
V_209 = F_133 ( V_204 , V_173 - V_59 ) ;
for ( V_208 = 0 ; V_208 < V_209 ; V_208 ++ ) {
F_130 ( V_2 , V_59 , V_202 ) ;
V_202 ++ ;
V_204 -- ;
}
}
for ( V_59 = V_201 ; V_59 < V_173 ; V_59 ++ ) {
V_210 = F_133 ( V_206 , V_173 - V_59 ) ;
for ( V_208 = 0 ; V_208 < V_210 ; V_208 ++ ) {
F_131 ( V_2 , V_59 , V_203 ) ;
V_203 ++ ;
V_206 -- ;
}
}
V_212:
return V_211 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_173 = V_2 -> V_174 - V_175 ;
int V_213 , V_211 ;
int V_214 = 0 , V_215 = 0 ;
for ( V_213 = 0 ; V_213 < V_173 ; V_213 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_213 ] ;
struct V_216 * V_217 = & V_2 -> V_218 [ V_213 ] ;
if ( V_53 -> V_70 . V_36 && V_53 -> V_158 . V_36 ) {
snprintf ( V_53 -> V_219 , sizeof( V_53 -> V_219 ) - 1 ,
L_12 , V_39 -> V_219 , L_13 , V_214 ++ ) ;
V_215 ++ ;
} else if ( V_53 -> V_158 . V_36 ) {
snprintf ( V_53 -> V_219 , sizeof( V_53 -> V_219 ) - 1 ,
L_12 , V_39 -> V_219 , L_14 , V_214 ++ ) ;
} else if ( V_53 -> V_70 . V_36 ) {
snprintf ( V_53 -> V_219 , sizeof( V_53 -> V_219 ) - 1 ,
L_12 , V_39 -> V_219 , L_15 , V_215 ++ ) ;
} else {
continue;
}
V_211 = F_135 ( V_217 -> V_213 , & F_128 , 0 ,
V_53 -> V_219 , V_53 ) ;
if ( V_211 ) {
F_136 ( & V_2 -> V_9 ,
L_16 ,
V_211 ) ;
goto V_220;
}
}
V_211 = F_135 ( V_2 -> V_218 [ V_213 ] . V_213 ,
& F_127 , 0 , V_39 -> V_219 , V_2 ) ;
if ( V_211 ) {
F_136 ( & V_2 -> V_9 , L_17 ,
V_211 ) ;
goto V_220;
}
return 0 ;
V_220:
while ( V_213 ) {
V_213 -- ;
F_137 ( V_2 -> V_218 [ V_213 ] . V_213 ,
V_2 -> V_53 [ V_213 ] ) ;
}
V_2 -> V_174 = 0 ;
return V_211 ;
}
static inline void F_138 ( struct V_1 * V_2 )
{
int V_59 , V_173 = V_2 -> V_174 - V_175 ;
for ( V_59 = 0 ; V_59 < V_173 ; V_59 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_59 ] ;
V_53 -> V_158 . V_36 = NULL ;
V_53 -> V_70 . V_36 = NULL ;
V_53 -> V_158 . V_43 = 0 ;
V_53 -> V_70 . V_43 = 0 ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
int V_211 = 0 ;
V_211 = F_134 ( V_2 ) ;
if ( V_211 )
F_136 ( & V_2 -> V_9 , L_18 , V_211 ) ;
return V_211 ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_59 , V_173 ;
V_173 = V_2 -> V_174 ;
V_59 = V_173 - 1 ;
F_137 ( V_2 -> V_218 [ V_59 ] . V_213 , V_2 ) ;
V_59 -- ;
for (; V_59 >= 0 ; V_59 -- ) {
if ( ! V_2 -> V_53 [ V_59 ] -> V_158 . V_36 &&
! V_2 -> V_53 [ V_59 ] -> V_70 . V_36 )
continue;
F_137 ( V_2 -> V_218 [ V_59 ] . V_213 ,
V_2 -> V_53 [ V_59 ] ) ;
}
F_138 ( V_2 ) ;
}
static inline void F_141 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
F_19 ( V_9 , V_221 , 0 ) ;
F_19 ( V_9 , V_222 , ~ 0 ) ;
F_19 ( V_9 , V_223 , 0 ) ;
F_142 ( V_9 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_174 ; V_59 ++ )
F_143 ( V_2 -> V_218 [ V_59 ] . V_213 ) ;
}
static inline void F_144 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_19 ( V_9 , V_221 , V_2 -> V_176 ) ;
F_19 ( V_9 , V_223 , V_2 -> V_176 ) ;
F_19 ( V_9 , V_148 , V_2 -> V_176 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_224 = V_36 -> V_33 ;
int V_225 = 10 ;
T_1 V_226 = V_227 ;
T_2 V_41 = V_36 -> V_41 ;
F_19 ( V_9 , F_146 ( V_41 ) , V_228 ) ;
F_142 ( V_9 ) ;
F_19 ( V_9 , F_147 ( V_41 ) , V_224 & F_148 ( 32 ) ) ;
F_19 ( V_9 , F_149 ( V_41 ) , V_224 >> 32 ) ;
F_19 ( V_9 , F_150 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_54 ) ) ;
F_19 ( V_9 , F_151 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_152 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_153 ( V_41 ) ,
( V_229 |
V_230 ) ) ;
F_19 ( V_9 , F_31 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_32 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_231 + F_32 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_226 |= ( 8 << 16 ) ;
V_226 |= ( 1 << 8 ) |
32 ;
F_8 ( V_48 , & V_36 -> V_4 ) ;
F_19 ( V_9 , F_146 ( V_41 ) , V_226 ) ;
do {
F_154 ( 1000 , 2000 ) ;
V_226 = F_18 ( V_9 , F_146 ( V_41 ) ) ;
} while ( -- V_225 && ! ( V_226 & V_227 ) );
if ( ! V_225 )
F_46 ( L_19 , V_41 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_1 V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ )
F_145 ( V_2 , V_2 -> V_28 [ V_59 ] ) ;
}
static void F_156 ( struct V_1 * V_2 , int V_24 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_232 ;
V_232 = V_233 ;
V_232 |= V_141 << V_234 ;
V_232 |= V_132 >> V_235 ;
V_232 |= V_236 ;
F_19 ( V_9 , F_157 ( V_24 ) , V_232 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_237 = V_238 | V_239 |
V_240 | V_241 |
V_242 ;
if ( V_2 -> V_205 > 1 )
V_237 |= 1 << 29 ;
F_19 ( V_9 , V_243 , V_237 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_225 = V_244 ;
T_1 V_245 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
V_245 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
V_245 &= ~ V_246 ;
F_19 ( V_9 , F_160 ( V_41 ) , V_245 ) ;
do {
F_161 ( 10 ) ;
V_245 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
} while ( -- V_225 && ( V_245 & V_246 ) );
if ( ! V_225 )
F_46 ( L_20 ,
V_41 ) ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_225 = V_244 ;
T_1 V_245 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
do {
F_154 ( 1000 , 2000 ) ;
V_245 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
} while ( -- V_225 && ! ( V_245 & V_246 ) );
if ( ! V_225 )
F_46 ( L_21 ,
V_41 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_247 = 0 , V_248 = 0 ;
T_6 V_249 = V_2 -> V_205 ;
T_2 V_59 , V_208 ;
F_164 ( V_2 -> V_250 , sizeof( V_2 -> V_250 ) ) ;
for ( V_59 = 0 ; V_59 < V_251 ; V_59 ++ )
F_19 ( V_9 , F_165 ( V_59 ) , V_2 -> V_250 [ V_59 ] ) ;
for ( V_59 = 0 , V_208 = 0 ; V_59 < V_252 ; V_59 ++ , V_208 ++ ) {
if ( V_208 == V_249 )
V_208 = 0 ;
V_2 -> V_253 [ V_59 ] = V_208 ;
V_248 |= V_208 << ( V_59 & 0x3 ) * 8 ;
if ( ( V_59 & 3 ) == 3 ) {
F_19 ( V_9 , F_166 ( V_59 >> 2 ) , V_248 ) ;
V_248 = 0 ;
}
}
V_247 |= V_254 |
V_255 |
V_256 |
V_257 ;
V_247 |= V_258 ;
F_19 ( V_9 , V_259 , V_247 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_260 = V_36 -> V_33 ;
T_1 V_245 ;
T_2 V_41 = V_36 -> V_41 ;
V_245 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
F_159 ( V_2 , V_36 ) ;
F_19 ( V_9 , F_168 ( V_41 ) , V_260 & F_148 ( 32 ) ) ;
F_19 ( V_9 , F_169 ( V_41 ) , V_260 >> 32 ) ;
F_19 ( V_9 , F_170 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_78 ) ) ;
F_19 ( V_9 , F_171 ( V_41 ) ,
V_261 ) ;
F_19 ( V_9 , F_172 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_173 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_231 + F_173 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_36 -> V_126 = 0 ;
F_156 ( V_2 , V_41 ) ;
V_245 &= ~ V_262 ;
V_245 |= V_246 | V_263 ;
F_19 ( V_9 , F_160 ( V_41 ) , V_245 ) ;
F_162 ( V_2 , V_36 ) ;
F_78 ( V_36 , F_50 ( V_36 ) ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_59 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
F_158 ( V_2 ) ;
if ( V_9 -> V_194 . type >= V_264 )
F_163 ( V_2 ) ;
F_175 ( V_9 , V_39 -> V_265 + V_266 + V_267 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ )
F_167 ( V_2 , V_2 -> V_102 [ V_59 ] ) ;
}
static int F_176 ( struct V_51 * V_39 ,
T_9 V_268 , T_6 V_104 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_211 ;
F_177 ( & V_2 -> V_269 ) ;
V_211 = V_9 -> V_194 . V_270 . V_271 ( V_9 , V_104 , 0 , true ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_211 == V_272 )
return - V_273 ;
if ( V_211 == V_274 )
return - V_275 ;
F_179 ( V_104 , V_2 -> V_107 ) ;
return V_211 ;
}
static int F_180 ( struct V_51 * V_39 ,
T_9 V_268 , T_6 V_104 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_211 = - V_276 ;
F_177 ( & V_2 -> V_269 ) ;
V_211 = V_9 -> V_194 . V_270 . V_271 ( V_9 , V_104 , 0 , false ) ;
F_178 ( & V_2 -> V_269 ) ;
F_8 ( V_104 , V_2 -> V_107 ) ;
return V_211 ;
}
static void F_181 ( struct V_1 * V_2 )
{
T_6 V_104 ;
F_182 (vid, adapter->active_vlans, VLAN_N_VID)
F_176 ( V_2 -> V_39 ,
F_69 ( V_109 ) , V_104 ) ;
}
static int F_183 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_43 = 0 ;
if ( ( F_184 ( V_39 ) ) > 10 ) {
F_46 ( L_22 ) ;
return - V_277 ;
}
if ( ! F_185 ( V_39 ) ) {
struct V_278 * V_279 ;
F_186 (ha, netdev) {
V_9 -> V_194 . V_270 . V_280 ( V_9 , ++ V_43 , V_279 -> V_281 ) ;
F_161 ( 200 ) ;
}
} else {
V_9 -> V_194 . V_270 . V_280 ( V_9 , 0 , NULL ) ;
}
return V_43 ;
}
static void F_187 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_177 ( & V_2 -> V_269 ) ;
V_9 -> V_194 . V_270 . V_282 ( V_9 , V_39 ) ;
F_183 ( V_39 ) ;
F_178 ( & V_2 -> V_269 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
int V_283 ;
struct V_52 * V_53 ;
int V_173 = V_2 -> V_174 - V_175 ;
for ( V_283 = 0 ; V_283 < V_173 ; V_283 ++ ) {
V_53 = V_2 -> V_53 [ V_283 ] ;
#ifdef F_55
F_189 ( V_2 -> V_53 [ V_283 ] ) ;
#endif
F_190 ( & V_53 -> V_77 ) ;
}
}
static void F_191 ( struct V_1 * V_2 )
{
int V_283 ;
struct V_52 * V_53 ;
int V_173 = V_2 -> V_174 - V_175 ;
for ( V_283 = 0 ; V_283 < V_173 ; V_283 ++ ) {
V_53 = V_2 -> V_53 [ V_283 ] ;
F_192 ( & V_53 -> V_77 ) ;
#ifdef F_55
while ( ! F_193 ( V_2 -> V_53 [ V_283 ] ) ) {
F_194 ( L_23 , V_283 ) ;
F_154 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_284 = 0 ;
unsigned int V_285 = 0 ;
unsigned int V_205 = V_2 -> V_205 ;
unsigned int V_207 = V_2 -> V_207 ;
int V_211 ;
F_177 ( & V_2 -> V_269 ) ;
V_211 = F_196 ( V_9 , & V_285 , & V_284 ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_211 )
return V_211 ;
if ( V_285 > 1 ) {
V_207 = 1 ;
V_2 -> V_28 [ 0 ] -> V_41 = V_284 ;
V_205 = V_285 ;
}
if ( ( V_2 -> V_205 != V_205 ) ||
( V_2 -> V_207 != V_207 ) ) {
V_9 -> V_286 . V_287 = 0 ;
V_2 -> V_49 |= V_288 ;
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
if ( V_2 -> V_37 . V_289 || V_2 -> V_37 . V_290 ) {
V_2 -> V_37 . V_291 += V_2 -> V_37 . V_289 -
V_2 -> V_37 . V_292 ;
V_2 -> V_37 . V_293 += V_2 -> V_37 . V_290 -
V_2 -> V_37 . V_294 ;
V_2 -> V_37 . V_295 += V_2 -> V_37 . V_296 -
V_2 -> V_37 . V_297 ;
V_2 -> V_37 . V_298 += V_2 -> V_37 . V_299 -
V_2 -> V_37 . V_300 ;
V_2 -> V_37 . V_301 += V_2 -> V_37 . V_302 -
V_2 -> V_37 . V_303 ;
}
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
V_2 -> V_37 . V_304 = F_18 ( V_9 , V_305 ) ;
V_2 -> V_37 . V_306 = F_18 ( V_9 , V_307 ) ;
V_2 -> V_37 . V_306 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_308 ) ) ) << 32 ) ;
V_2 -> V_37 . V_309 = F_18 ( V_9 , V_310 ) ;
V_2 -> V_37 . V_311 = F_18 ( V_9 , V_312 ) ;
V_2 -> V_37 . V_311 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_313 ) ) ) << 32 ) ;
V_2 -> V_37 . V_314 = F_18 ( V_9 , V_315 ) ;
V_2 -> V_37 . V_292 = V_2 -> V_37 . V_304 ;
V_2 -> V_37 . V_297 = V_2 -> V_37 . V_306 ;
V_2 -> V_37 . V_294 = V_2 -> V_37 . V_309 ;
V_2 -> V_37 . V_300 = V_2 -> V_37 . V_311 ;
V_2 -> V_37 . V_303 = V_2 -> V_37 . V_314 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_316 [] = { V_317 ,
V_318 ,
V_319 ,
V_320 } ;
int V_211 = 0 , V_321 = 0 ;
F_177 ( & V_2 -> V_269 ) ;
while ( V_316 [ V_321 ] != V_320 ) {
V_211 = F_201 ( V_9 , V_316 [ V_321 ] ) ;
if ( ! V_211 )
break;
V_321 ++ ;
}
F_178 ( & V_2 -> V_269 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_125 ( V_2 ) ;
F_177 ( & V_2 -> V_269 ) ;
if ( F_203 ( V_9 -> V_194 . V_281 ) )
V_9 -> V_194 . V_270 . V_322 ( V_9 , 0 , V_9 -> V_194 . V_281 , 0 ) ;
else
V_9 -> V_194 . V_270 . V_322 ( V_9 , 0 , V_9 -> V_194 . V_323 , 0 ) ;
F_178 ( & V_2 -> V_269 ) ;
F_7 () ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_188 ( V_2 ) ;
F_18 ( V_9 , V_324 ) ;
F_144 ( V_2 ) ;
F_204 ( V_39 ) ;
F_198 ( V_2 ) ;
F_199 ( V_2 ) ;
V_9 -> V_194 . V_195 = 1 ;
F_205 ( & V_2 -> V_325 , V_74 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
F_197 ( V_2 ) ;
F_202 ( V_2 ) ;
}
static void F_207 ( struct V_27 * V_102 )
{
struct V_326 * V_13 = V_102 -> V_13 ;
unsigned long V_135 ;
unsigned int V_59 ;
if ( V_102 -> V_31 ) {
F_208 ( V_102 -> V_31 ) ;
V_102 -> V_31 = NULL ;
}
if ( ! V_102 -> V_122 )
return;
for ( V_59 = 0 ; V_59 < V_102 -> V_43 ; V_59 ++ ) {
struct V_113 * V_133 ;
V_133 = & V_102 -> V_122 [ V_59 ] ;
if ( V_133 -> V_33 )
F_26 ( V_13 , V_133 -> V_33 ,
V_117 , V_118 ) ;
V_133 -> V_33 = 0 ;
if ( V_133 -> V_115 )
F_77 ( V_133 -> V_115 ) ;
V_133 -> V_115 = NULL ;
}
V_135 = sizeof( struct V_113 ) * V_102 -> V_43 ;
memset ( V_102 -> V_122 , 0 , V_135 ) ;
memset ( V_102 -> V_327 , 0 , V_102 -> V_135 ) ;
}
static void F_209 ( struct V_27 * V_28 )
{
struct V_29 * V_61 ;
unsigned long V_135 ;
unsigned int V_59 ;
if ( ! V_28 -> V_61 )
return;
for ( V_59 = 0 ; V_59 < V_28 -> V_43 ; V_59 ++ ) {
V_61 = & V_28 -> V_61 [ V_59 ] ;
F_21 ( V_28 , V_61 ) ;
}
V_135 = sizeof( struct V_29 ) * V_28 -> V_43 ;
memset ( V_28 -> V_61 , 0 , V_135 ) ;
memset ( V_28 -> V_327 , 0 , V_28 -> V_135 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ )
F_207 ( V_2 -> V_102 [ V_59 ] ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ )
F_209 ( V_2 -> V_28 [ V_59 ] ) ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ )
F_159 ( V_2 , V_2 -> V_102 [ V_59 ] ) ;
F_154 ( 10000 , 20000 ) ;
F_213 ( V_39 ) ;
F_214 ( V_39 ) ;
F_215 ( V_39 ) ;
F_141 ( V_2 ) ;
F_191 ( V_2 ) ;
F_216 ( & V_2 -> V_325 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ ) {
T_2 V_41 = V_2 -> V_28 [ V_59 ] -> V_41 ;
F_19 ( V_9 , F_146 ( V_41 ) ,
V_228 ) ;
}
if ( ! F_217 ( V_2 -> V_12 ) )
F_218 ( V_2 ) ;
F_211 ( V_2 ) ;
F_210 ( V_2 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
F_220 ( F_221 () ) ;
while ( F_3 ( V_328 , & V_2 -> V_4 ) )
F_222 ( 1 ) ;
F_212 ( V_2 ) ;
F_206 ( V_2 ) ;
F_8 ( V_328 , & V_2 -> V_4 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
if ( V_9 -> V_194 . V_270 . V_329 ( V_9 ) ) {
F_136 ( V_9 , L_24 ) ;
} else {
V_9 -> V_194 . V_270 . V_330 ( V_9 ) ;
F_200 ( V_2 ) ;
}
if ( F_203 ( V_2 -> V_9 . V_194 . V_281 ) ) {
memcpy ( V_39 -> V_156 , V_2 -> V_9 . V_194 . V_281 ,
V_39 -> V_331 ) ;
memcpy ( V_39 -> V_323 , V_2 -> V_9 . V_194 . V_281 ,
V_39 -> V_331 ) ;
}
V_2 -> V_332 = V_74 ;
}
static int F_223 ( struct V_1 * V_2 ,
int V_333 )
{
int V_334 ;
V_334 = V_335 ;
V_333 = F_224 ( V_2 -> V_12 , V_2 -> V_218 ,
V_334 , V_333 ) ;
if ( V_333 < 0 ) {
F_10 ( & V_2 -> V_12 -> V_13 ,
L_25 ) ;
F_225 ( V_2 -> V_218 ) ;
V_2 -> V_218 = NULL ;
return V_333 ;
}
V_2 -> V_174 = V_333 ;
return 0 ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_284 = 0 ;
unsigned int V_285 = 0 ;
int V_211 ;
V_2 -> V_205 = 1 ;
V_2 -> V_207 = 1 ;
F_177 ( & V_2 -> V_269 ) ;
V_211 = F_196 ( V_9 , & V_285 , & V_284 ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_211 )
return;
if ( V_285 > 1 ) {
V_2 -> V_205 = V_285 ;
} else {
T_6 V_89 = F_227 ( T_6 , F_228 () , V_336 ) ;
switch ( V_9 -> V_337 ) {
case V_318 :
case V_317 :
V_2 -> V_205 = V_89 ;
V_2 -> V_207 = V_89 ;
default:
break;
}
}
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_27 * V_36 ;
int V_158 = 0 , V_70 = 0 ;
for (; V_70 < V_2 -> V_207 ; V_70 ++ ) {
V_36 = F_230 ( sizeof( * V_36 ) , V_338 ) ;
if ( ! V_36 )
goto V_339;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_340 ;
V_36 -> V_71 = V_70 ;
V_36 -> V_41 = V_70 ;
V_2 -> V_28 [ V_70 ] = V_36 ;
}
for (; V_158 < V_2 -> V_205 ; V_158 ++ ) {
V_36 = F_230 ( sizeof( * V_36 ) , V_338 ) ;
if ( ! V_36 )
goto V_339;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_341 ;
V_36 -> V_71 = V_158 ;
V_36 -> V_41 = V_158 ;
V_2 -> V_102 [ V_158 ] = V_36 ;
}
return 0 ;
V_339:
while ( V_70 ) {
F_225 ( V_2 -> V_28 [ -- V_70 ] ) ;
V_2 -> V_28 [ V_70 ] = NULL ;
}
while ( V_158 ) {
F_225 ( V_2 -> V_102 [ -- V_158 ] ) ;
V_2 -> V_102 [ V_158 ] = NULL ;
}
return - V_342 ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_211 = 0 ;
int V_213 , V_343 ;
V_343 = F_115 ( V_2 -> V_205 , V_2 -> V_207 ) ;
V_343 = F_227 ( int , V_343 , F_228 () ) ;
V_343 += V_175 ;
V_2 -> V_218 = F_232 ( V_343 ,
sizeof( struct V_216 ) , V_338 ) ;
if ( ! V_2 -> V_218 ) {
V_211 = - V_342 ;
goto V_212;
}
for ( V_213 = 0 ; V_213 < V_343 ; V_213 ++ )
V_2 -> V_218 [ V_213 ] . V_217 = V_213 ;
V_211 = F_223 ( V_2 , V_343 ) ;
if ( V_211 )
goto V_212;
V_211 = F_233 ( V_39 , V_2 -> V_207 ) ;
if ( V_211 )
goto V_212;
V_211 = F_234 ( V_39 , V_2 -> V_205 ) ;
V_212:
return V_211 ;
}
static int F_235 ( struct V_1 * V_2 )
{
int V_283 , V_344 ;
struct V_52 * V_53 ;
V_344 = V_2 -> V_174 - V_175 ;
for ( V_283 = 0 ; V_283 < V_344 ; V_283 ++ ) {
V_53 = F_230 ( sizeof( struct V_52 ) , V_338 ) ;
if ( ! V_53 )
goto V_345;
V_53 -> V_2 = V_2 ;
V_53 -> V_163 = V_283 ;
F_236 ( V_2 -> V_39 , & V_53 -> V_77 ,
F_111 , 64 ) ;
#ifdef F_55
F_237 ( & V_53 -> V_77 ) ;
#endif
V_2 -> V_53 [ V_283 ] = V_53 ;
}
return 0 ;
V_345:
while ( V_283 ) {
V_283 -- ;
V_53 = V_2 -> V_53 [ V_283 ] ;
#ifdef F_55
F_238 ( & V_53 -> V_77 ) ;
#endif
F_239 ( & V_53 -> V_77 ) ;
F_225 ( V_53 ) ;
V_2 -> V_53 [ V_283 ] = NULL ;
}
return - V_342 ;
}
static void F_240 ( struct V_1 * V_2 )
{
int V_283 , V_344 = V_2 -> V_174 - V_175 ;
for ( V_283 = 0 ; V_283 < V_344 ; V_283 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_283 ] ;
V_2 -> V_53 [ V_283 ] = NULL ;
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
F_225 ( V_2 -> V_218 ) ;
V_2 -> V_218 = NULL ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_211 ;
F_226 ( V_2 ) ;
V_211 = F_231 ( V_2 ) ;
if ( V_211 ) {
F_136 ( & V_2 -> V_9 ,
L_26 ) ;
goto V_346;
}
V_211 = F_235 ( V_2 ) ;
if ( V_211 ) {
F_136 ( & V_2 -> V_9 , L_27 ) ;
goto V_347;
}
V_211 = F_229 ( V_2 ) ;
if ( V_211 ) {
F_46 ( L_28 ) ;
goto V_348;
}
F_136 ( & V_2 -> V_9 , L_29 ,
( V_2 -> V_205 > 1 ) ? L_30 :
L_31 , V_2 -> V_205 , V_2 -> V_207 ) ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_348:
F_240 ( V_2 ) ;
V_347:
F_241 ( V_2 ) ;
V_346:
return V_211 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ ) {
F_225 ( V_2 -> V_28 [ V_59 ] ) ;
V_2 -> V_28 [ V_59 ] = NULL ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ ) {
F_225 ( V_2 -> V_102 [ V_59 ] ) ;
V_2 -> V_102 [ V_59 ] = NULL ;
}
V_2 -> V_207 = 0 ;
V_2 -> V_205 = 0 ;
F_240 ( V_2 ) ;
F_241 ( V_2 ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_349 * V_12 = V_2 -> V_12 ;
struct V_51 * V_39 = V_2 -> V_39 ;
int V_211 ;
V_9 -> V_350 = V_12 -> V_351 ;
V_9 -> V_352 = V_12 -> V_326 ;
V_9 -> V_353 = V_12 -> V_354 ;
V_9 -> V_355 = V_12 -> V_356 ;
V_9 -> V_357 = V_12 -> V_358 ;
V_9 -> V_286 . V_270 . V_359 ( V_9 ) ;
V_9 -> V_194 . V_360 = 2 ;
V_9 -> V_194 . V_361 = 2 ;
F_246 ( & V_2 -> V_269 ) ;
V_211 = V_9 -> V_194 . V_270 . V_329 ( V_9 ) ;
if ( V_211 ) {
F_247 ( & V_12 -> V_13 ,
L_32 ) ;
} else {
V_211 = V_9 -> V_194 . V_270 . V_330 ( V_9 ) ;
if ( V_211 ) {
F_46 ( L_33 , V_211 ) ;
goto V_212;
}
F_200 ( V_2 ) ;
V_211 = V_9 -> V_194 . V_270 . V_362 ( V_9 , V_9 -> V_194 . V_281 ) ;
if ( V_211 )
F_247 ( & V_12 -> V_13 , L_34 ) ;
else if ( F_248 ( V_2 -> V_9 . V_194 . V_281 ) )
F_247 ( & V_12 -> V_13 ,
L_35 ) ;
memcpy ( V_39 -> V_156 , V_9 -> V_194 . V_281 , V_39 -> V_331 ) ;
}
if ( ! F_203 ( V_39 -> V_156 ) ) {
F_247 ( & V_12 -> V_13 , L_36 ) ;
F_249 ( V_39 ) ;
memcpy ( V_9 -> V_194 . V_281 , V_39 -> V_156 , V_39 -> V_331 ) ;
}
V_2 -> V_162 = 1 ;
V_2 -> V_177 = 1 ;
V_2 -> V_340 = V_363 ;
V_2 -> V_341 = V_364 ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_212:
return V_211 ;
}
void F_250 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_328 , & V_2 -> V_4 ) )
return;
F_251 ( V_305 , V_2 -> V_37 . V_304 ,
V_2 -> V_37 . V_289 ) ;
F_251 ( V_310 , V_2 -> V_37 . V_309 ,
V_2 -> V_37 . V_290 ) ;
F_252 ( V_307 , V_308 ,
V_2 -> V_37 . V_306 ,
V_2 -> V_37 . V_296 ) ;
F_252 ( V_312 , V_313 ,
V_2 -> V_37 . V_311 ,
V_2 -> V_37 . V_299 ) ;
F_251 ( V_315 , V_2 -> V_37 . V_314 ,
V_2 -> V_37 . V_302 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ ) {
V_2 -> V_365 +=
V_2 -> V_102 [ V_59 ] -> V_365 ;
V_2 -> V_102 [ V_59 ] -> V_365 = 0 ;
}
}
static void F_253 ( unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_146 ;
F_205 ( & V_2 -> V_325 , ( V_366 * 2 ) + V_74 ) ;
F_1 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_49 & V_50 ) )
return;
V_2 -> V_49 &= ~ V_50 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_328 , & V_2 -> V_4 ) )
return;
V_2 -> V_367 ++ ;
F_219 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_368 = 0 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_328 , & V_2 -> V_4 ) )
return;
if ( F_49 ( V_2 -> V_39 ) ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ )
F_256 ( V_2 -> V_28 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_174 - V_175 ; V_59 ++ ) {
struct V_52 * V_369 = V_2 -> V_53 [ V_59 ] ;
if ( V_369 -> V_158 . V_36 || V_369 -> V_70 . V_36 )
V_368 |= 1 << V_59 ;
}
F_19 ( V_9 , V_370 , V_368 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_371 = V_2 -> V_371 ;
bool V_372 = V_2 -> V_372 ;
T_10 V_211 ;
F_177 ( & V_2 -> V_269 ) ;
V_211 = V_9 -> V_194 . V_270 . V_373 ( V_9 , & V_371 , & V_372 , false ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_211 && F_258 ( V_74 , V_2 -> V_332 + ( 10 * V_366 ) ) ) {
V_2 -> V_49 |= V_50 ;
V_372 = false ;
}
V_2 -> V_372 = V_372 ;
V_2 -> V_371 = V_371 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
if ( F_49 ( V_39 ) )
return;
F_247 ( & V_2 -> V_12 -> V_13 , L_37 ,
( V_2 -> V_371 == V_374 ) ?
L_38 :
( V_2 -> V_371 == V_375 ) ?
L_39 :
( V_2 -> V_371 == V_376 ) ?
L_40 :
L_41 ) ;
F_260 ( V_39 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
V_2 -> V_371 = 0 ;
if ( ! F_49 ( V_39 ) )
return;
F_247 ( & V_2 -> V_12 -> V_13 , L_42 ) ;
F_214 ( V_39 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_328 , & V_2 -> V_4 ) )
return;
F_257 ( V_2 ) ;
if ( V_2 -> V_372 )
F_259 ( V_2 ) ;
else
F_261 ( V_2 ) ;
F_250 ( V_2 ) ;
}
static void F_263 ( struct V_377 * V_378 )
{
struct V_1 * V_2 = F_112 ( V_378 ,
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
if ( ! V_28 -> V_327 )
return;
F_269 ( V_28 -> V_13 , V_28 -> V_135 , V_28 -> V_327 ,
V_28 -> V_33 ) ;
V_28 -> V_327 = NULL ;
}
static void F_270 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ )
if ( V_2 -> V_28 [ V_59 ] -> V_327 )
F_267 ( V_2 -> V_28 [ V_59 ] ) ;
}
int F_271 ( struct V_27 * V_28 )
{
int V_135 ;
V_135 = sizeof( struct V_29 ) * V_28 -> V_43 ;
V_28 -> V_61 = F_272 ( V_135 ) ;
if ( ! V_28 -> V_61 )
goto V_211;
V_28 -> V_135 = V_28 -> V_43 * sizeof( union V_54 ) ;
V_28 -> V_135 = F_92 ( V_28 -> V_135 , 4096 ) ;
V_28 -> V_327 = F_273 ( V_28 -> V_13 , V_28 -> V_135 ,
& V_28 -> V_33 , V_338 ) ;
if ( ! V_28 -> V_327 )
goto V_211;
return 0 ;
V_211:
F_268 ( V_28 -> V_61 ) ;
V_28 -> V_61 = NULL ;
F_136 ( & V_2 -> V_9 , L_43 ) ;
return - V_342 ;
}
static int F_274 ( struct V_1 * V_2 )
{
int V_59 , V_211 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ ) {
V_211 = F_271 ( V_2 -> V_28 [ V_59 ] ) ;
if ( ! V_211 )
continue;
F_136 ( & V_2 -> V_9 , L_44 , V_59 ) ;
break;
}
return V_211 ;
}
int F_275 ( struct V_27 * V_102 )
{
int V_135 ;
V_135 = sizeof( struct V_113 ) * V_102 -> V_43 ;
V_102 -> V_122 = F_272 ( V_135 ) ;
if ( ! V_102 -> V_122 )
goto V_211;
V_102 -> V_135 = V_102 -> V_43 * sizeof( union V_78 ) ;
V_102 -> V_135 = F_92 ( V_102 -> V_135 , 4096 ) ;
V_102 -> V_327 = F_273 ( V_102 -> V_13 , V_102 -> V_135 ,
& V_102 -> V_33 , V_338 ) ;
if ( ! V_102 -> V_327 )
goto V_211;
return 0 ;
V_211:
F_268 ( V_102 -> V_122 ) ;
V_102 -> V_122 = NULL ;
F_10 ( V_102 -> V_13 , L_45 ) ;
return - V_342 ;
}
static int F_276 ( struct V_1 * V_2 )
{
int V_59 , V_211 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ ) {
V_211 = F_275 ( V_2 -> V_102 [ V_59 ] ) ;
if ( ! V_211 )
continue;
F_136 ( & V_2 -> V_9 , L_46 , V_59 ) ;
break;
}
return V_211 ;
}
void F_277 ( struct V_27 * V_102 )
{
F_207 ( V_102 ) ;
F_268 ( V_102 -> V_122 ) ;
V_102 -> V_122 = NULL ;
F_269 ( V_102 -> V_13 , V_102 -> V_135 , V_102 -> V_327 ,
V_102 -> V_33 ) ;
V_102 -> V_327 = NULL ;
}
static void F_278 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ )
if ( V_2 -> V_102 [ V_59 ] -> V_327 )
F_277 ( V_2 -> V_102 [ V_59 ] ) ;
}
static int F_279 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_211 ;
if ( ! V_2 -> V_174 )
return - V_342 ;
if ( V_9 -> V_379 ) {
F_218 ( V_2 ) ;
if ( V_9 -> V_379 ) {
V_211 = V_272 ;
F_46 ( L_47 ) ;
goto V_380;
}
}
if ( F_2 ( V_381 , & V_2 -> V_4 ) )
return - V_382 ;
F_214 ( V_39 ) ;
V_211 = F_274 ( V_2 ) ;
if ( V_211 )
goto V_383;
V_211 = F_276 ( V_2 ) ;
if ( V_211 )
goto V_384;
F_197 ( V_2 ) ;
F_132 ( V_2 ) ;
V_211 = F_139 ( V_2 ) ;
if ( V_211 )
goto V_385;
F_202 ( V_2 ) ;
return 0 ;
V_385:
F_212 ( V_2 ) ;
V_384:
F_278 ( V_2 ) ;
V_383:
F_270 ( V_2 ) ;
F_218 ( V_2 ) ;
V_380:
return V_211 ;
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
if ( ! ( V_2 -> V_49 & V_288 ) )
return;
V_2 -> V_49 &= ~ V_288 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_328 , & V_2 -> V_4 ) )
return;
if ( F_281 ( V_13 ) )
F_280 ( V_13 ) ;
F_244 ( V_2 ) ;
F_243 ( V_2 ) ;
if ( F_281 ( V_13 ) )
F_279 ( V_13 ) ;
}
static void F_282 ( struct V_27 * V_28 ,
T_1 V_386 , T_1 V_387 ,
T_1 V_388 )
{
struct V_389 * V_390 ;
T_6 V_59 = V_28 -> V_72 ;
V_390 = F_283 ( V_28 , V_59 ) ;
V_59 ++ ;
V_28 -> V_72 = ( V_59 < V_28 -> V_43 ) ? V_59 : 0 ;
V_387 |= V_391 | V_392 ;
V_390 -> V_386 = F_40 ( V_386 ) ;
V_390 -> V_393 = 0 ;
V_390 -> V_394 = F_40 ( V_387 ) ;
V_390 -> V_388 = F_40 ( V_388 ) ;
}
static int F_284 ( struct V_27 * V_28 ,
struct V_29 * V_395 ,
T_2 * V_396 )
{
struct V_76 * V_31 = V_395 -> V_31 ;
T_1 V_386 , V_387 ;
T_1 V_388 , V_397 ;
int V_211 ;
if ( V_31 -> V_100 != V_398 )
return 0 ;
if ( ! F_285 ( V_31 ) )
return 0 ;
V_211 = F_286 ( V_31 , 0 ) ;
if ( V_211 < 0 )
return V_211 ;
V_387 = V_399 ;
if ( V_395 -> V_110 == F_69 ( V_400 ) ) {
struct V_401 * V_402 = F_287 ( V_31 ) ;
V_402 -> V_403 = 0 ;
V_402 -> V_404 = 0 ;
F_288 ( V_31 ) -> V_404 = ~ F_289 ( V_402 -> V_405 ,
V_402 -> V_406 , 0 ,
V_407 ,
0 ) ;
V_387 |= V_408 ;
V_395 -> V_409 |= V_410 |
V_411 |
V_412 ;
} else if ( F_290 ( V_31 ) ) {
F_291 ( V_31 ) -> V_413 = 0 ;
F_288 ( V_31 ) -> V_404 =
~ F_292 ( & F_291 ( V_31 ) -> V_405 ,
& F_291 ( V_31 ) -> V_406 ,
0 , V_407 , 0 ) ;
V_395 -> V_409 |= V_410 |
V_411 ;
}
V_397 = F_293 ( V_31 ) ;
* V_396 += V_397 ;
* V_396 = F_294 ( V_31 ) + V_397 ;
V_395 -> V_67 = F_98 ( V_31 ) -> V_67 ;
V_395 -> V_66 += ( V_395 -> V_67 - 1 ) * * V_396 ;
V_388 = V_397 << V_414 ;
V_388 |= F_98 ( V_31 ) -> V_415 << V_416 ;
V_388 |= 1 << V_417 ;
V_386 = F_295 ( V_31 ) ;
V_386 |= F_296 ( V_31 ) << V_418 ;
V_386 |= V_395 -> V_409 & V_419 ;
F_282 ( V_28 , V_386 ,
V_387 , V_388 ) ;
return 1 ;
}
static void F_297 ( struct V_27 * V_28 ,
struct V_29 * V_395 )
{
struct V_76 * V_31 = V_395 -> V_31 ;
T_1 V_386 = 0 ;
T_1 V_388 = 0 ;
T_1 V_387 = 0 ;
if ( V_31 -> V_100 == V_398 ) {
T_2 V_420 = 0 ;
switch ( V_395 -> V_110 ) {
case F_69 ( V_400 ) :
V_386 |= F_295 ( V_31 ) ;
V_387 |= V_408 ;
V_420 = F_287 ( V_31 ) -> V_110 ;
break;
case F_69 ( V_421 ) :
V_386 |= F_295 ( V_31 ) ;
V_420 = F_291 ( V_31 ) -> V_422 ;
break;
default:
if ( F_16 ( F_298 () ) ) {
F_299 ( V_28 -> V_13 ,
L_48 ,
V_395 -> V_110 ) ;
}
break;
}
switch ( V_420 ) {
case V_407 :
V_387 |= V_399 ;
V_388 = F_293 ( V_31 ) <<
V_414 ;
break;
case V_423 :
V_387 |= V_424 ;
V_388 = sizeof( struct V_425 ) <<
V_414 ;
break;
case V_426 :
V_388 = sizeof( struct V_427 ) <<
V_414 ;
break;
default:
if ( F_16 ( F_298 () ) ) {
F_299 ( V_28 -> V_13 ,
L_49 ,
V_420 ) ;
}
break;
}
V_395 -> V_409 |= V_411 ;
}
V_386 |= F_296 ( V_31 ) << V_418 ;
V_386 |= V_395 -> V_409 & V_419 ;
F_282 ( V_28 , V_386 ,
V_387 , V_388 ) ;
}
static T_11 F_300 ( T_1 V_409 )
{
T_11 V_428 = F_40 ( V_429 |
V_430 |
V_431 ) ;
if ( V_409 & V_432 )
V_428 |= F_40 ( V_433 ) ;
if ( V_409 & V_410 )
V_428 |= F_40 ( V_434 ) ;
return V_428 ;
}
static void F_301 ( union V_54 * V_55 ,
T_1 V_409 , unsigned int V_435 )
{
T_11 V_436 = F_40 ( V_435 << V_437 ) ;
if ( V_409 & V_411 )
V_436 |= F_40 ( V_438 ) ;
if ( V_409 & V_412 )
V_436 |= F_40 ( V_439 ) ;
if ( V_409 & V_410 )
V_436 |= F_40 ( 1 << V_417 ) ;
V_436 |= F_40 ( V_440 ) ;
V_55 -> V_123 . V_436 = V_436 ;
}
static void F_302 ( struct V_27 * V_28 ,
struct V_29 * V_395 ,
const T_2 V_396 )
{
T_7 V_33 ;
struct V_76 * V_31 = V_395 -> V_31 ;
struct V_29 * V_30 ;
union V_54 * V_55 ;
struct V_441 * V_442 = & F_98 ( V_31 ) -> V_443 [ 0 ] ;
unsigned int V_444 = V_31 -> V_444 ;
unsigned int V_135 = F_303 ( V_31 ) ;
unsigned int V_435 = V_31 -> V_32 - V_396 ;
T_1 V_409 = V_395 -> V_409 ;
T_11 V_428 ;
T_6 V_59 = V_28 -> V_72 ;
V_55 = F_38 ( V_28 , V_59 ) ;
F_301 ( V_55 , V_409 , V_435 ) ;
V_428 = F_300 ( V_409 ) ;
V_33 = F_304 ( V_28 -> V_13 , V_31 -> V_146 , V_135 , V_34 ) ;
if ( F_76 ( V_28 -> V_13 , V_33 ) )
goto V_445;
F_27 ( V_395 , V_32 , V_135 ) ;
F_305 ( V_395 , V_33 , V_33 ) ;
V_55 -> V_123 . V_446 = F_79 ( V_33 ) ;
for (; ; ) {
while ( F_16 ( V_135 > V_447 ) ) {
V_55 -> V_123 . V_448 =
V_428 | F_40 ( V_447 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_33 += V_447 ;
V_135 -= V_447 ;
V_55 -> V_123 . V_446 = F_79 ( V_33 ) ;
V_55 -> V_123 . V_436 = 0 ;
}
if ( F_42 ( ! V_444 ) )
break;
V_55 -> V_123 . V_448 = V_428 | F_40 ( V_135 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_135 = F_306 ( V_442 ) ;
V_444 -= V_135 ;
V_33 = F_307 ( V_28 -> V_13 , V_442 , 0 , V_135 ,
V_34 ) ;
if ( F_76 ( V_28 -> V_13 , V_33 ) )
goto V_445;
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_27 ( V_30 , V_32 , V_135 ) ;
F_305 ( V_30 , V_33 , V_33 ) ;
V_55 -> V_123 . V_446 = F_79 ( V_33 ) ;
V_55 -> V_123 . V_436 = 0 ;
V_442 ++ ;
}
V_428 |= F_40 ( V_135 ) | F_40 ( V_449 ) ;
V_55 -> V_123 . V_448 = V_428 ;
V_395 -> V_73 = V_74 ;
F_80 () ;
V_395 -> V_35 = V_55 ;
V_59 ++ ;
if ( V_59 == V_28 -> V_43 )
V_59 = 0 ;
V_28 -> V_72 = V_59 ;
F_81 ( V_28 , V_59 ) ;
return;
V_445:
F_10 ( V_28 -> V_13 , L_50 ) ;
for (; ; ) {
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_21 ( V_28 , V_30 ) ;
if ( V_30 == V_395 )
break;
if ( V_59 == 0 )
V_59 = V_28 -> V_43 ;
V_59 -- ;
}
V_28 -> V_72 = V_59 ;
}
static int F_308 ( struct V_27 * V_28 , int V_135 )
{
F_47 ( V_28 -> V_39 , V_28 -> V_71 ) ;
F_51 () ;
if ( F_42 ( F_50 ( V_28 ) < V_135 ) )
return - V_382 ;
F_309 ( V_28 -> V_39 , V_28 -> V_71 ) ;
++ V_28 -> V_46 . V_75 ;
return 0 ;
}
static int F_310 ( struct V_27 * V_28 , int V_135 )
{
if ( F_42 ( F_50 ( V_28 ) >= V_135 ) )
return 0 ;
return F_308 ( V_28 , V_135 ) ;
}
static int F_311 ( struct V_76 * V_31 , struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_29 * V_395 ;
struct V_27 * V_28 ;
int V_450 ;
T_1 V_409 = 0 ;
T_6 V_43 = F_312 ( F_303 ( V_31 ) ) ;
#if V_117 > V_447
unsigned short V_451 ;
#endif
T_2 V_396 = 0 ;
T_2 * V_452 = F_313 ( V_31 , 0 , 0 , NULL ) ;
if ( ! V_452 || F_314 ( V_452 ) ) {
F_22 ( V_31 ) ;
return V_453 ;
}
V_28 = V_2 -> V_28 [ V_31 -> V_454 ] ;
#if V_117 > V_447
for ( V_451 = 0 ; V_451 < F_98 ( V_31 ) -> V_142 ; V_451 ++ )
V_43 += F_312 ( F_98 ( V_31 ) -> V_443 [ V_451 ] . V_135 ) ;
#else
V_43 += F_98 ( V_31 ) -> V_142 ;
#endif
if ( F_310 ( V_28 , V_43 + 3 ) ) {
V_28 -> V_46 . V_455 ++ ;
return V_456 ;
}
V_395 = & V_28 -> V_61 [ V_28 -> V_72 ] ;
V_395 -> V_31 = V_31 ;
V_395 -> V_66 = V_31 -> V_32 ;
V_395 -> V_67 = 1 ;
if ( F_315 ( V_31 ) ) {
V_409 |= F_316 ( V_31 ) ;
V_409 <<= V_457 ;
V_409 |= V_432 ;
}
V_395 -> V_409 = V_409 ;
V_395 -> V_110 = F_317 ( V_31 ) ;
V_450 = F_284 ( V_28 , V_395 , & V_396 ) ;
if ( V_450 < 0 )
goto V_458;
else if ( ! V_450 )
F_297 ( V_28 , V_395 ) ;
F_302 ( V_28 , V_395 , V_396 ) ;
F_310 ( V_28 , V_459 ) ;
return V_453 ;
V_458:
F_22 ( V_395 -> V_31 ) ;
V_395 -> V_31 = NULL ;
return V_453 ;
}
static int F_318 ( struct V_51 * V_39 , void * V_460 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_461 * V_281 = V_460 ;
if ( ! F_203 ( V_281 -> V_462 ) )
return - V_463 ;
memcpy ( V_39 -> V_156 , V_281 -> V_462 , V_39 -> V_331 ) ;
memcpy ( V_9 -> V_194 . V_281 , V_281 -> V_462 , V_39 -> V_331 ) ;
F_177 ( & V_2 -> V_269 ) ;
V_9 -> V_194 . V_270 . V_322 ( V_9 , 0 , V_9 -> V_194 . V_281 , 0 ) ;
F_178 ( & V_2 -> V_269 ) ;
return 0 ;
}
static int F_319 ( struct V_51 * V_39 , int V_464 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_465 = V_464 + V_266 + V_267 ;
int V_466 = V_467 ;
switch ( V_2 -> V_9 . V_337 ) {
case V_318 :
case V_317 :
V_466 = V_468 ;
break;
default:
if ( V_2 -> V_9 . V_194 . type != V_469 )
V_466 = V_468 ;
break;
}
if ( ( V_464 < 68 ) || ( V_465 > V_466 ) )
return - V_470 ;
F_136 ( V_9 , L_51 ,
V_39 -> V_265 , V_464 ) ;
V_39 -> V_265 = V_464 ;
F_175 ( V_9 , V_465 ) ;
return 0 ;
}
static void F_320 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ )
F_128 ( 0 , V_2 -> V_53 [ V_59 ] ) ;
}
static int F_321 ( struct V_349 * V_12 , T_12 V_4 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
#ifdef F_323
int V_471 = 0 ;
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
V_471 = F_325 ( V_12 ) ;
if ( V_471 )
return V_471 ;
#endif
if ( ! F_3 ( V_472 , & V_2 -> V_4 ) )
F_326 ( V_12 ) ;
return 0 ;
}
static int F_327 ( struct V_349 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
T_1 V_211 ;
F_328 ( V_12 ) ;
F_325 ( V_12 ) ;
V_211 = F_329 ( V_12 ) ;
if ( V_211 ) {
F_10 ( & V_12 -> V_13 , L_52 ) ;
return V_211 ;
}
F_7 () ;
F_8 ( V_472 , & V_2 -> V_4 ) ;
F_330 ( V_12 ) ;
F_218 ( V_2 ) ;
F_264 () ;
V_211 = F_243 ( V_2 ) ;
F_265 () ;
if ( V_211 ) {
F_10 ( & V_12 -> V_13 , L_53 ) ;
return V_211 ;
}
if ( F_281 ( V_39 ) ) {
V_211 = F_279 ( V_39 ) ;
if ( V_211 )
return V_211 ;
}
F_331 ( V_39 ) ;
return V_211 ;
}
static void F_332 ( struct V_349 * V_12 )
{
F_321 ( V_12 , V_473 ) ;
}
static struct V_474 * F_333 ( struct V_51 * V_39 ,
struct V_474 * V_37 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
unsigned int V_475 ;
T_5 V_69 , V_38 ;
const struct V_27 * V_36 ;
int V_59 ;
F_250 ( V_2 ) ;
V_37 -> V_476 = V_2 -> V_37 . V_302 - V_2 -> V_37 . V_303 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_205 ; V_59 ++ ) {
V_36 = V_2 -> V_102 [ V_59 ] ;
do {
V_475 = F_334 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_335 ( & V_36 -> V_68 , V_475 ) );
V_37 -> V_477 += V_69 ;
V_37 -> V_478 += V_38 ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_207 ; V_59 ++ ) {
V_36 = V_2 -> V_28 [ V_59 ] ;
do {
V_475 = F_334 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_335 ( & V_36 -> V_68 , V_475 ) );
V_37 -> V_479 += V_69 ;
V_37 -> V_480 += V_38 ;
}
return V_37 ;
}
static void F_336 ( struct V_51 * V_13 )
{
V_13 -> V_481 = & V_482 ;
F_337 ( V_13 ) ;
V_13 -> V_483 = 5 * V_366 ;
}
static int F_338 ( struct V_349 * V_12 , const struct V_484 * V_485 )
{
struct V_51 * V_39 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = NULL ;
const struct V_486 * V_487 = V_488 [ V_485 -> V_489 ] ;
int V_211 , V_490 ;
bool V_491 = false ;
V_211 = F_339 ( V_12 ) ;
if ( V_211 )
return V_211 ;
if ( ! F_340 ( & V_12 -> V_13 , F_148 ( 64 ) ) ) {
V_490 = 1 ;
} else {
V_211 = F_340 ( & V_12 -> V_13 , F_148 ( 32 ) ) ;
if ( V_211 ) {
F_10 ( & V_12 -> V_13 , L_54 ) ;
goto V_492;
}
V_490 = 0 ;
}
V_211 = F_341 ( V_12 , V_493 ) ;
if ( V_211 ) {
F_10 ( & V_12 -> V_13 , L_55 , V_211 ) ;
goto V_494;
}
F_330 ( V_12 ) ;
V_39 = F_342 ( sizeof( struct V_1 ) ,
V_495 ) ;
if ( ! V_39 ) {
V_211 = - V_342 ;
goto V_496;
}
F_343 ( V_39 , & V_12 -> V_13 ) ;
V_2 = F_30 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_12 = V_12 ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_10 = V_2 ;
V_2 -> V_497 = F_344 ( V_498 , V_499 ) ;
F_325 ( V_12 ) ;
V_9 -> V_11 = F_345 ( F_346 ( V_12 , 0 ) ,
F_347 ( V_12 , 0 ) ) ;
V_2 -> V_231 = V_9 -> V_11 ;
if ( ! V_9 -> V_11 ) {
V_211 = - V_273 ;
goto V_500;
}
F_336 ( V_39 ) ;
memcpy ( & V_9 -> V_194 . V_270 , V_487 -> V_501 , sizeof( V_9 -> V_194 . V_270 ) ) ;
V_9 -> V_194 . type = V_487 -> V_194 ;
memcpy ( & V_9 -> V_286 . V_270 , & V_502 ,
sizeof( struct V_503 ) ) ;
V_211 = F_245 ( V_2 ) ;
if ( V_211 )
goto V_504;
if ( ! F_203 ( V_39 -> V_156 ) ) {
F_46 ( L_56 ) ;
V_211 = - V_273 ;
goto V_504;
}
V_39 -> V_505 = V_506 |
V_507 |
V_508 |
V_509 |
V_510 |
V_93 ;
V_39 -> V_81 = V_39 -> V_505 |
V_511 |
V_512 |
V_513 ;
V_39 -> V_514 |= V_509 |
V_510 |
V_507 |
V_508 |
V_506 ;
if ( V_490 )
V_39 -> V_81 |= V_515 ;
V_39 -> V_516 |= V_517 ;
if ( F_14 ( V_9 -> V_11 ) ) {
V_211 = - V_273 ;
goto V_504;
}
F_348 ( & V_2 -> V_325 , & F_253 ,
( unsigned long ) V_2 ) ;
F_349 ( & V_2 -> V_7 , F_263 ) ;
F_179 ( V_14 , & V_2 -> V_4 ) ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
V_211 = F_243 ( V_2 ) ;
if ( V_211 )
goto V_504;
strcpy ( V_39 -> V_219 , L_57 ) ;
V_211 = F_350 ( V_39 ) ;
if ( V_211 )
goto V_518;
F_351 ( V_12 , V_39 ) ;
F_214 ( V_39 ) ;
F_199 ( V_2 ) ;
F_247 ( & V_12 -> V_13 , L_58 , V_39 -> V_156 ) ;
F_247 ( & V_12 -> V_13 , L_59 , V_9 -> V_194 . type ) ;
switch ( V_9 -> V_194 . type ) {
case V_264 :
F_247 ( & V_12 -> V_13 , L_60 ) ;
break;
case V_519 :
F_247 ( & V_12 -> V_13 , L_61 ) ;
break;
case V_469 :
default:
F_247 ( & V_12 -> V_13 , L_62 ) ;
break;
}
return 0 ;
V_518:
F_244 ( V_2 ) ;
V_504:
F_241 ( V_2 ) ;
F_352 ( V_2 -> V_231 ) ;
V_500:
V_491 = ! F_3 ( V_472 , & V_2 -> V_4 ) ;
F_353 ( V_39 ) ;
V_496:
F_354 ( V_12 ) ;
V_494:
V_492:
if ( ! V_2 || V_491 )
F_326 ( V_12 ) ;
return V_211 ;
}
static void F_355 ( struct V_349 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 ;
bool V_491 ;
if ( ! V_39 )
return;
V_2 = F_30 ( V_39 ) ;
F_179 ( V_5 , & V_2 -> V_4 ) ;
F_356 ( & V_2 -> V_7 ) ;
if ( V_39 -> V_520 == V_521 )
F_357 ( V_39 ) ;
F_244 ( V_2 ) ;
F_241 ( V_2 ) ;
F_352 ( V_2 -> V_231 ) ;
F_354 ( V_12 ) ;
F_136 ( & V_2 -> V_9 , L_63 ) ;
V_491 = ! F_3 ( V_472 , & V_2 -> V_4 ) ;
F_353 ( V_39 ) ;
if ( V_491 )
F_326 ( V_12 ) ;
}
static T_13 F_358 ( struct V_349 * V_12 ,
T_14 V_4 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( ! F_2 ( V_14 , & V_2 -> V_4 ) )
return V_522 ;
F_264 () ;
F_324 ( V_39 ) ;
if ( V_4 == V_523 ) {
F_265 () ;
return V_522 ;
}
if ( F_281 ( V_39 ) )
F_212 ( V_2 ) ;
if ( ! F_3 ( V_472 , & V_2 -> V_4 ) )
F_326 ( V_12 ) ;
F_265 () ;
return V_524 ;
}
static T_13 F_359 ( struct V_349 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_329 ( V_12 ) ) {
F_10 ( & V_12 -> V_13 ,
L_64 ) ;
return V_522 ;
}
F_7 () ;
F_8 ( V_472 , & V_2 -> V_4 ) ;
F_330 ( V_12 ) ;
F_218 ( V_2 ) ;
return V_525 ;
}
static void F_360 ( struct V_349 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_281 ( V_39 ) )
F_206 ( V_2 ) ;
F_331 ( V_39 ) ;
}
static int T_15 F_361 ( void )
{
int V_526 ;
F_194 ( L_65 , V_527 ,
V_528 ) ;
F_194 ( L_66 , V_529 ) ;
V_526 = F_362 ( & V_530 ) ;
return V_526 ;
}
static void T_16 F_363 ( void )
{
F_364 ( & V_530 ) ;
}
char * F_365 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
return V_2 -> V_39 -> V_219 ;
}
