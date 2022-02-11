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
int V_160 , V_161 = 0 ;
bool V_162 = true ;
F_113 (ring, q_vector->tx)
V_162 &= F_37 ( V_53 , V_36 ) ;
#ifdef F_55
if ( ! F_114 ( V_53 ) )
return V_58 ;
#endif
if ( V_53 -> V_158 . V_43 > 1 )
V_160 = F_115 ( V_58 / V_53 -> V_158 . V_43 , 1 ) ;
else
V_160 = V_58 ;
F_113 (ring, q_vector->rx) {
int V_163 = F_106 ( V_53 , V_36 ,
V_160 ) ;
V_161 += V_163 ;
V_162 &= ( V_163 < V_160 ) ;
}
#ifdef F_55
F_116 ( V_53 ) ;
#endif
if ( ! V_162 )
return V_58 ;
F_117 ( V_77 , V_161 ) ;
if ( V_2 -> V_164 & 1 )
F_118 ( V_53 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) )
F_105 ( V_2 ,
1 << V_53 -> V_165 ) ;
return 0 ;
}
void F_119 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_165 = V_53 -> V_165 ;
T_1 V_166 = V_53 -> V_167 & V_168 ;
V_166 |= V_169 ;
F_19 ( V_9 , F_120 ( V_165 ) , V_166 ) ;
}
static int F_121 ( struct V_159 * V_77 )
{
struct V_52 * V_53 =
F_112 ( V_77 , struct V_52 , V_77 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_27 * V_36 ;
int V_170 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return V_171 ;
if ( ! F_122 ( V_53 ) )
return V_172 ;
F_113 (ring, q_vector->rx) {
V_170 = F_106 ( V_53 , V_36 , 4 ) ;
#ifdef F_123
if ( V_170 )
V_36 -> V_37 . V_163 += V_170 ;
else
V_36 -> V_37 . V_173 ++ ;
#endif
if ( V_170 )
break;
}
F_124 ( V_53 ) ;
return V_170 ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
int V_174 , V_165 ;
V_174 = V_2 -> V_175 - V_176 ;
V_2 -> V_177 = 0 ;
for ( V_165 = 0 ; V_165 < V_174 ; V_165 ++ ) {
struct V_27 * V_36 ;
V_53 = V_2 -> V_53 [ V_165 ] ;
F_113 (ring, q_vector->rx)
F_17 ( V_2 , 0 , V_36 -> V_41 , V_165 ) ;
F_113 (ring, q_vector->tx)
F_17 ( V_2 , 1 , V_36 -> V_41 , V_165 ) ;
if ( V_53 -> V_70 . V_36 && ! V_53 -> V_158 . V_36 ) {
if ( V_2 -> V_178 == 1 )
V_53 -> V_167 = V_179 ;
else
V_53 -> V_167 = V_2 -> V_178 ;
} else {
if ( V_2 -> V_164 == 1 )
V_53 -> V_167 = V_180 ;
else
V_53 -> V_167 = V_2 -> V_164 ;
}
V_2 -> V_177 |= 1 << V_165 ;
F_119 ( V_53 ) ;
}
F_17 ( V_2 , - 1 , 1 , V_165 ) ;
V_2 -> V_181 = 1 << V_165 ;
V_2 -> V_177 |= V_2 -> V_181 ;
}
static void F_126 ( struct V_52 * V_53 ,
struct V_182 * V_183 )
{
int V_69 = V_183 -> V_56 ;
int V_38 = V_183 -> V_57 ;
T_1 V_184 ;
T_5 V_185 ;
T_2 V_186 = V_183 -> V_167 ;
if ( V_38 == 0 )
return;
V_184 = V_53 -> V_167 >> 2 ;
V_185 = V_69 / V_184 ;
switch ( V_186 ) {
case V_187 :
if ( V_185 > 10 )
V_186 = V_188 ;
break;
case V_188 :
if ( V_185 > 20 )
V_186 = V_189 ;
else if ( V_185 <= 10 )
V_186 = V_187 ;
break;
case V_189 :
if ( V_185 <= 20 )
V_186 = V_188 ;
break;
}
V_183 -> V_56 = 0 ;
V_183 -> V_57 = 0 ;
V_183 -> V_167 = V_186 ;
}
static void F_118 ( struct V_52 * V_53 )
{
T_1 V_190 = V_53 -> V_167 ;
T_2 V_191 ;
F_126 ( V_53 , & V_53 -> V_70 ) ;
F_126 ( V_53 , & V_53 -> V_158 ) ;
V_191 = F_115 ( V_53 -> V_158 . V_167 , V_53 -> V_70 . V_167 ) ;
switch ( V_191 ) {
case V_187 :
V_190 = V_192 ;
break;
case V_188 :
V_190 = V_180 ;
break;
case V_189 :
default:
V_190 = V_193 ;
break;
}
if ( V_190 != V_53 -> V_167 ) {
V_190 = ( 10 * V_190 * V_53 -> V_167 ) /
( ( 9 * V_190 ) + V_53 -> V_167 ) ;
V_53 -> V_167 = V_190 ;
F_119 ( V_53 ) ;
}
}
static T_8 F_127 ( int V_194 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
V_9 -> V_195 . V_196 = 1 ;
F_1 ( V_2 ) ;
F_19 ( V_9 , V_148 , V_2 -> V_181 ) ;
return V_197 ;
}
static T_8 F_128 ( int V_194 , void * V_146 )
{
struct V_52 * V_53 = V_146 ;
if ( V_53 -> V_158 . V_36 || V_53 -> V_70 . V_36 )
F_129 ( & V_53 -> V_77 ) ;
return V_197 ;
}
static inline void F_130 ( struct V_1 * V_198 , int V_165 ,
int V_199 )
{
struct V_52 * V_53 = V_198 -> V_53 [ V_165 ] ;
V_198 -> V_102 [ V_199 ] -> V_200 = V_53 -> V_158 . V_36 ;
V_53 -> V_158 . V_36 = V_198 -> V_102 [ V_199 ] ;
V_53 -> V_158 . V_43 ++ ;
}
static inline void F_131 ( struct V_1 * V_198 , int V_165 ,
int V_201 )
{
struct V_52 * V_53 = V_198 -> V_53 [ V_165 ] ;
V_198 -> V_28 [ V_201 ] -> V_200 = V_53 -> V_70 . V_36 ;
V_53 -> V_70 . V_36 = V_198 -> V_28 [ V_201 ] ;
V_53 -> V_70 . V_43 ++ ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_174 ;
int V_202 = 0 ;
int V_203 = 0 , V_204 = 0 ;
int V_205 = V_2 -> V_206 ;
int V_207 = V_2 -> V_208 ;
int V_59 , V_209 ;
int V_210 , V_211 ;
int V_212 = 0 ;
V_174 = V_2 -> V_175 - V_176 ;
if ( V_174 == V_2 -> V_206 + V_2 -> V_208 ) {
for (; V_203 < V_205 ; V_202 ++ , V_203 ++ )
F_130 ( V_2 , V_202 , V_203 ) ;
for (; V_204 < V_207 ; V_202 ++ , V_204 ++ )
F_131 ( V_2 , V_202 , V_204 ) ;
goto V_213;
}
for ( V_59 = V_202 ; V_59 < V_174 ; V_59 ++ ) {
V_210 = F_133 ( V_205 , V_174 - V_59 ) ;
for ( V_209 = 0 ; V_209 < V_210 ; V_209 ++ ) {
F_130 ( V_2 , V_59 , V_203 ) ;
V_203 ++ ;
V_205 -- ;
}
}
for ( V_59 = V_202 ; V_59 < V_174 ; V_59 ++ ) {
V_211 = F_133 ( V_207 , V_174 - V_59 ) ;
for ( V_209 = 0 ; V_209 < V_211 ; V_209 ++ ) {
F_131 ( V_2 , V_59 , V_204 ) ;
V_204 ++ ;
V_207 -- ;
}
}
V_213:
return V_212 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_174 = V_2 -> V_175 - V_176 ;
int V_214 , V_212 ;
int V_215 = 0 , V_216 = 0 ;
for ( V_214 = 0 ; V_214 < V_174 ; V_214 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_214 ] ;
struct V_217 * V_218 = & V_2 -> V_219 [ V_214 ] ;
if ( V_53 -> V_70 . V_36 && V_53 -> V_158 . V_36 ) {
snprintf ( V_53 -> V_220 , sizeof( V_53 -> V_220 ) - 1 ,
L_12 , V_39 -> V_220 , L_13 , V_215 ++ ) ;
V_216 ++ ;
} else if ( V_53 -> V_158 . V_36 ) {
snprintf ( V_53 -> V_220 , sizeof( V_53 -> V_220 ) - 1 ,
L_12 , V_39 -> V_220 , L_14 , V_215 ++ ) ;
} else if ( V_53 -> V_70 . V_36 ) {
snprintf ( V_53 -> V_220 , sizeof( V_53 -> V_220 ) - 1 ,
L_12 , V_39 -> V_220 , L_15 , V_216 ++ ) ;
} else {
continue;
}
V_212 = F_135 ( V_218 -> V_214 , & F_128 , 0 ,
V_53 -> V_220 , V_53 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_9 ,
L_16 ,
V_212 ) ;
goto V_221;
}
}
V_212 = F_135 ( V_2 -> V_219 [ V_214 ] . V_214 ,
& F_127 , 0 , V_39 -> V_220 , V_2 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_9 , L_17 ,
V_212 ) ;
goto V_221;
}
return 0 ;
V_221:
while ( V_214 ) {
V_214 -- ;
F_137 ( V_2 -> V_219 [ V_214 ] . V_214 ,
V_2 -> V_53 [ V_214 ] ) ;
}
V_2 -> V_175 = 0 ;
return V_212 ;
}
static inline void F_138 ( struct V_1 * V_2 )
{
int V_59 , V_174 = V_2 -> V_175 - V_176 ;
for ( V_59 = 0 ; V_59 < V_174 ; V_59 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_59 ] ;
V_53 -> V_158 . V_36 = NULL ;
V_53 -> V_70 . V_36 = NULL ;
V_53 -> V_158 . V_43 = 0 ;
V_53 -> V_70 . V_43 = 0 ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
int V_212 = 0 ;
V_212 = F_134 ( V_2 ) ;
if ( V_212 )
F_136 ( & V_2 -> V_9 , L_18 , V_212 ) ;
return V_212 ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_59 , V_174 ;
V_174 = V_2 -> V_175 ;
V_59 = V_174 - 1 ;
F_137 ( V_2 -> V_219 [ V_59 ] . V_214 , V_2 ) ;
V_59 -- ;
for (; V_59 >= 0 ; V_59 -- ) {
if ( ! V_2 -> V_53 [ V_59 ] -> V_158 . V_36 &&
! V_2 -> V_53 [ V_59 ] -> V_70 . V_36 )
continue;
F_137 ( V_2 -> V_219 [ V_59 ] . V_214 ,
V_2 -> V_53 [ V_59 ] ) ;
}
F_138 ( V_2 ) ;
}
static inline void F_141 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
F_19 ( V_9 , V_222 , 0 ) ;
F_19 ( V_9 , V_223 , ~ 0 ) ;
F_19 ( V_9 , V_224 , 0 ) ;
F_142 ( V_9 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_175 ; V_59 ++ )
F_143 ( V_2 -> V_219 [ V_59 ] . V_214 ) ;
}
static inline void F_144 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_19 ( V_9 , V_222 , V_2 -> V_177 ) ;
F_19 ( V_9 , V_224 , V_2 -> V_177 ) ;
F_19 ( V_9 , V_148 , V_2 -> V_177 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_225 = V_36 -> V_33 ;
int V_226 = 10 ;
T_1 V_227 = V_228 ;
T_2 V_41 = V_36 -> V_41 ;
F_19 ( V_9 , F_146 ( V_41 ) , V_229 ) ;
F_142 ( V_9 ) ;
F_19 ( V_9 , F_147 ( V_41 ) , V_225 & F_148 ( 32 ) ) ;
F_19 ( V_9 , F_149 ( V_41 ) , V_225 >> 32 ) ;
F_19 ( V_9 , F_150 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_54 ) ) ;
F_19 ( V_9 , F_151 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_152 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_153 ( V_41 ) ,
( V_230 |
V_231 ) ) ;
F_19 ( V_9 , F_31 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_32 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_232 + F_32 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_227 |= ( 8 << 16 ) ;
V_227 |= ( 1 << 8 ) |
32 ;
F_8 ( V_48 , & V_36 -> V_4 ) ;
F_19 ( V_9 , F_146 ( V_41 ) , V_227 ) ;
do {
F_154 ( 1000 , 2000 ) ;
V_227 = F_18 ( V_9 , F_146 ( V_41 ) ) ;
} while ( -- V_226 && ! ( V_227 & V_228 ) );
if ( ! V_226 )
F_46 ( L_19 , V_41 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_1 V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ )
F_145 ( V_2 , V_2 -> V_28 [ V_59 ] ) ;
}
static void F_156 ( struct V_1 * V_2 , int V_24 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_233 ;
V_233 = V_234 ;
V_233 |= V_141 << V_235 ;
V_233 |= V_132 >> V_236 ;
V_233 |= V_237 ;
F_19 ( V_9 , F_157 ( V_24 ) , V_233 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_238 = V_239 | V_240 |
V_241 | V_242 |
V_243 ;
if ( V_2 -> V_206 > 1 )
V_238 |= 1 << 29 ;
F_19 ( V_9 , V_244 , V_238 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_226 = V_245 ;
T_1 V_246 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
V_246 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
V_246 &= ~ V_247 ;
F_19 ( V_9 , F_160 ( V_41 ) , V_246 ) ;
do {
F_161 ( 10 ) ;
V_246 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
} while ( -- V_226 && ( V_246 & V_247 ) );
if ( ! V_226 )
F_46 ( L_20 ,
V_41 ) ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_226 = V_245 ;
T_1 V_246 ;
T_2 V_41 = V_36 -> V_41 ;
if ( F_14 ( V_9 -> V_11 ) )
return;
do {
F_154 ( 1000 , 2000 ) ;
V_246 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
} while ( -- V_226 && ! ( V_246 & V_247 ) );
if ( ! V_226 )
F_46 ( L_21 ,
V_41 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_248 = 0 , V_249 = 0 ;
T_6 V_250 = V_2 -> V_206 ;
T_2 V_59 , V_209 ;
F_164 ( V_2 -> V_251 , sizeof( V_2 -> V_251 ) ) ;
for ( V_59 = 0 ; V_59 < V_252 ; V_59 ++ )
F_19 ( V_9 , F_165 ( V_59 ) , V_2 -> V_251 [ V_59 ] ) ;
for ( V_59 = 0 , V_209 = 0 ; V_59 < V_253 ; V_59 ++ , V_209 ++ ) {
if ( V_209 == V_250 )
V_209 = 0 ;
V_2 -> V_254 [ V_59 ] = V_209 ;
V_249 |= V_209 << ( V_59 & 0x3 ) * 8 ;
if ( ( V_59 & 3 ) == 3 ) {
F_19 ( V_9 , F_166 ( V_59 >> 2 ) , V_249 ) ;
V_249 = 0 ;
}
}
V_248 |= V_255 |
V_256 |
V_257 |
V_258 ;
V_248 |= V_259 ;
F_19 ( V_9 , V_260 , V_248 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_27 * V_36 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_5 V_261 = V_36 -> V_33 ;
T_1 V_246 ;
T_2 V_41 = V_36 -> V_41 ;
V_246 = F_18 ( V_9 , F_160 ( V_41 ) ) ;
F_159 ( V_2 , V_36 ) ;
F_19 ( V_9 , F_168 ( V_41 ) , V_261 & F_148 ( 32 ) ) ;
F_19 ( V_9 , F_169 ( V_41 ) , V_261 >> 32 ) ;
F_19 ( V_9 , F_170 ( V_41 ) ,
V_36 -> V_43 * sizeof( union V_78 ) ) ;
F_19 ( V_9 , F_171 ( V_41 ) ,
V_262 ) ;
F_19 ( V_9 , F_172 ( V_41 ) , 0 ) ;
F_19 ( V_9 , F_173 ( V_41 ) , 0 ) ;
V_36 -> V_42 = V_2 -> V_232 + F_173 ( V_41 ) ;
V_36 -> V_60 = 0 ;
V_36 -> V_72 = 0 ;
V_36 -> V_126 = 0 ;
F_156 ( V_2 , V_41 ) ;
V_246 &= ~ V_263 ;
V_246 |= V_247 | V_264 ;
F_19 ( V_9 , F_160 ( V_41 ) , V_246 ) ;
F_162 ( V_2 , V_36 ) ;
F_78 ( V_36 , F_50 ( V_36 ) ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_59 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
F_158 ( V_2 ) ;
if ( V_9 -> V_195 . type >= V_265 )
F_163 ( V_2 ) ;
F_175 ( V_9 , V_39 -> V_266 + V_267 + V_268 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ )
F_167 ( V_2 , V_2 -> V_102 [ V_59 ] ) ;
}
static int F_176 ( struct V_51 * V_39 ,
T_9 V_269 , T_6 V_104 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_212 ;
F_177 ( & V_2 -> V_270 ) ;
V_212 = V_9 -> V_195 . V_271 . V_272 ( V_9 , V_104 , 0 , true ) ;
F_178 ( & V_2 -> V_270 ) ;
if ( V_212 == V_273 )
return - V_274 ;
if ( V_212 == V_275 )
return - V_276 ;
F_179 ( V_104 , V_2 -> V_107 ) ;
return V_212 ;
}
static int F_180 ( struct V_51 * V_39 ,
T_9 V_269 , T_6 V_104 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_212 = - V_277 ;
F_177 ( & V_2 -> V_270 ) ;
V_212 = V_9 -> V_195 . V_271 . V_272 ( V_9 , V_104 , 0 , false ) ;
F_178 ( & V_2 -> V_270 ) ;
F_8 ( V_104 , V_2 -> V_107 ) ;
return V_212 ;
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
return - V_278 ;
}
if ( ! F_185 ( V_39 ) ) {
struct V_279 * V_280 ;
F_186 (ha, netdev) {
V_9 -> V_195 . V_271 . V_281 ( V_9 , ++ V_43 , V_280 -> V_282 ) ;
F_161 ( 200 ) ;
}
} else {
V_9 -> V_195 . V_271 . V_281 ( V_9 , 0 , NULL ) ;
}
return V_43 ;
}
static void F_187 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_49 = V_39 -> V_49 ;
int V_283 ;
V_283 = ( V_49 & V_284 ) ? V_285 :
( V_49 & ( V_286 | V_287 ) ) ?
V_288 : V_289 ;
F_177 ( & V_2 -> V_270 ) ;
V_9 -> V_195 . V_271 . V_290 ( V_9 , V_39 , V_283 ) ;
V_9 -> V_195 . V_271 . V_291 ( V_9 , V_39 ) ;
F_183 ( V_39 ) ;
F_178 ( & V_2 -> V_270 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
int V_292 ;
struct V_52 * V_53 ;
int V_174 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_174 ; V_292 ++ ) {
V_53 = V_2 -> V_53 [ V_292 ] ;
#ifdef F_55
F_189 ( V_2 -> V_53 [ V_292 ] ) ;
#endif
F_190 ( & V_53 -> V_77 ) ;
}
}
static void F_191 ( struct V_1 * V_2 )
{
int V_292 ;
struct V_52 * V_53 ;
int V_174 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_174 ; V_292 ++ ) {
V_53 = V_2 -> V_53 [ V_292 ] ;
F_192 ( & V_53 -> V_77 ) ;
#ifdef F_55
while ( ! F_193 ( V_2 -> V_53 [ V_292 ] ) ) {
F_194 ( L_23 , V_292 ) ;
F_154 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_293 = 0 ;
unsigned int V_294 = 0 ;
unsigned int V_206 = V_2 -> V_206 ;
unsigned int V_208 = V_2 -> V_208 ;
int V_212 ;
F_177 ( & V_2 -> V_270 ) ;
V_212 = F_196 ( V_9 , & V_294 , & V_293 ) ;
F_178 ( & V_2 -> V_270 ) ;
if ( V_212 )
return V_212 ;
if ( V_294 > 1 ) {
V_208 = 1 ;
V_2 -> V_28 [ 0 ] -> V_41 = V_293 ;
V_206 = V_294 ;
}
if ( ( V_2 -> V_206 != V_206 ) ||
( V_2 -> V_208 != V_208 ) ) {
V_9 -> V_295 . V_296 = 0 ;
V_2 -> V_49 |= V_297 ;
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
if ( V_2 -> V_37 . V_298 || V_2 -> V_37 . V_299 ) {
V_2 -> V_37 . V_300 += V_2 -> V_37 . V_298 -
V_2 -> V_37 . V_301 ;
V_2 -> V_37 . V_302 += V_2 -> V_37 . V_299 -
V_2 -> V_37 . V_303 ;
V_2 -> V_37 . V_304 += V_2 -> V_37 . V_305 -
V_2 -> V_37 . V_306 ;
V_2 -> V_37 . V_307 += V_2 -> V_37 . V_308 -
V_2 -> V_37 . V_309 ;
V_2 -> V_37 . V_310 += V_2 -> V_37 . V_311 -
V_2 -> V_37 . V_312 ;
}
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
V_2 -> V_37 . V_313 = F_18 ( V_9 , V_314 ) ;
V_2 -> V_37 . V_315 = F_18 ( V_9 , V_316 ) ;
V_2 -> V_37 . V_315 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_317 ) ) ) << 32 ) ;
V_2 -> V_37 . V_318 = F_18 ( V_9 , V_319 ) ;
V_2 -> V_37 . V_320 = F_18 ( V_9 , V_321 ) ;
V_2 -> V_37 . V_320 |=
( ( ( T_5 ) ( F_18 ( V_9 , V_322 ) ) ) << 32 ) ;
V_2 -> V_37 . V_323 = F_18 ( V_9 , V_324 ) ;
V_2 -> V_37 . V_301 = V_2 -> V_37 . V_313 ;
V_2 -> V_37 . V_306 = V_2 -> V_37 . V_315 ;
V_2 -> V_37 . V_303 = V_2 -> V_37 . V_318 ;
V_2 -> V_37 . V_309 = V_2 -> V_37 . V_320 ;
V_2 -> V_37 . V_312 = V_2 -> V_37 . V_323 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_325 [] = { V_326 ,
V_327 ,
V_328 ,
V_329 } ;
int V_212 = 0 , V_330 = 0 ;
F_177 ( & V_2 -> V_270 ) ;
while ( V_325 [ V_330 ] != V_329 ) {
V_212 = F_201 ( V_9 , V_325 [ V_330 ] ) ;
if ( ! V_212 )
break;
V_330 ++ ;
}
F_178 ( & V_2 -> V_270 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
F_125 ( V_2 ) ;
F_177 ( & V_2 -> V_270 ) ;
if ( F_203 ( V_9 -> V_195 . V_282 ) )
V_9 -> V_195 . V_271 . V_331 ( V_9 , 0 , V_9 -> V_195 . V_282 , 0 ) ;
else
V_9 -> V_195 . V_271 . V_331 ( V_9 , 0 , V_9 -> V_195 . V_332 , 0 ) ;
F_178 ( & V_2 -> V_270 ) ;
F_7 () ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_188 ( V_2 ) ;
F_18 ( V_9 , V_333 ) ;
F_144 ( V_2 ) ;
F_204 ( V_39 ) ;
F_198 ( V_2 ) ;
F_199 ( V_2 ) ;
V_9 -> V_195 . V_196 = 1 ;
F_205 ( & V_2 -> V_334 , V_74 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
F_197 ( V_2 ) ;
F_202 ( V_2 ) ;
}
static void F_207 ( struct V_27 * V_102 )
{
struct V_335 * V_13 = V_102 -> V_13 ;
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
memset ( V_102 -> V_336 , 0 , V_102 -> V_135 ) ;
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
memset ( V_28 -> V_336 , 0 , V_28 -> V_135 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ )
F_207 ( V_2 -> V_102 [ V_59 ] ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ )
F_209 ( V_2 -> V_28 [ V_59 ] ) ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ )
F_159 ( V_2 , V_2 -> V_102 [ V_59 ] ) ;
F_154 ( 10000 , 20000 ) ;
F_213 ( V_39 ) ;
F_214 ( V_39 ) ;
F_215 ( V_39 ) ;
F_141 ( V_2 ) ;
F_191 ( V_2 ) ;
F_216 ( & V_2 -> V_334 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ ) {
T_2 V_41 = V_2 -> V_28 [ V_59 ] -> V_41 ;
F_19 ( V_9 , F_146 ( V_41 ) ,
V_229 ) ;
}
if ( ! F_217 ( V_2 -> V_12 ) )
F_218 ( V_2 ) ;
F_211 ( V_2 ) ;
F_210 ( V_2 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
F_220 ( F_221 () ) ;
while ( F_3 ( V_337 , & V_2 -> V_4 ) )
F_222 ( 1 ) ;
F_212 ( V_2 ) ;
F_206 ( V_2 ) ;
F_8 ( V_337 , & V_2 -> V_4 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_51 * V_39 = V_2 -> V_39 ;
if ( V_9 -> V_195 . V_271 . V_338 ( V_9 ) ) {
F_136 ( V_9 , L_24 ) ;
} else {
V_9 -> V_195 . V_271 . V_339 ( V_9 ) ;
F_200 ( V_2 ) ;
}
if ( F_203 ( V_2 -> V_9 . V_195 . V_282 ) ) {
memcpy ( V_39 -> V_156 , V_2 -> V_9 . V_195 . V_282 ,
V_39 -> V_340 ) ;
memcpy ( V_39 -> V_332 , V_2 -> V_9 . V_195 . V_282 ,
V_39 -> V_340 ) ;
}
V_2 -> V_341 = V_74 ;
}
static int F_223 ( struct V_1 * V_2 ,
int V_342 )
{
int V_343 ;
V_343 = V_344 ;
V_342 = F_224 ( V_2 -> V_12 , V_2 -> V_219 ,
V_343 , V_342 ) ;
if ( V_342 < 0 ) {
F_10 ( & V_2 -> V_12 -> V_13 ,
L_25 ) ;
F_225 ( V_2 -> V_219 ) ;
V_2 -> V_219 = NULL ;
return V_342 ;
}
V_2 -> V_175 = V_342 ;
return 0 ;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
unsigned int V_293 = 0 ;
unsigned int V_294 = 0 ;
int V_212 ;
V_2 -> V_206 = 1 ;
V_2 -> V_208 = 1 ;
F_177 ( & V_2 -> V_270 ) ;
V_212 = F_196 ( V_9 , & V_294 , & V_293 ) ;
F_178 ( & V_2 -> V_270 ) ;
if ( V_212 )
return;
if ( V_294 > 1 ) {
V_2 -> V_206 = V_294 ;
} else {
T_6 V_89 = F_227 ( T_6 , F_228 () , V_345 ) ;
switch ( V_9 -> V_346 ) {
case V_327 :
case V_326 :
V_2 -> V_206 = V_89 ;
V_2 -> V_208 = V_89 ;
default:
break;
}
}
}
static int F_229 ( struct V_1 * V_2 )
{
struct V_27 * V_36 ;
int V_158 = 0 , V_70 = 0 ;
for (; V_70 < V_2 -> V_208 ; V_70 ++ ) {
V_36 = F_230 ( sizeof( * V_36 ) , V_347 ) ;
if ( ! V_36 )
goto V_348;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_349 ;
V_36 -> V_71 = V_70 ;
V_36 -> V_41 = V_70 ;
V_2 -> V_28 [ V_70 ] = V_36 ;
}
for (; V_158 < V_2 -> V_206 ; V_158 ++ ) {
V_36 = F_230 ( sizeof( * V_36 ) , V_347 ) ;
if ( ! V_36 )
goto V_348;
V_36 -> V_13 = & V_2 -> V_12 -> V_13 ;
V_36 -> V_39 = V_2 -> V_39 ;
V_36 -> V_43 = V_2 -> V_350 ;
V_36 -> V_71 = V_158 ;
V_36 -> V_41 = V_158 ;
V_2 -> V_102 [ V_158 ] = V_36 ;
}
return 0 ;
V_348:
while ( V_70 ) {
F_225 ( V_2 -> V_28 [ -- V_70 ] ) ;
V_2 -> V_28 [ V_70 ] = NULL ;
}
while ( V_158 ) {
F_225 ( V_2 -> V_102 [ -- V_158 ] ) ;
V_2 -> V_102 [ V_158 ] = NULL ;
}
return - V_351 ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
int V_212 = 0 ;
int V_214 , V_352 ;
V_352 = F_115 ( V_2 -> V_206 , V_2 -> V_208 ) ;
V_352 = F_227 ( int , V_352 , F_228 () ) ;
V_352 += V_176 ;
V_2 -> V_219 = F_232 ( V_352 ,
sizeof( struct V_217 ) , V_347 ) ;
if ( ! V_2 -> V_219 ) {
V_212 = - V_351 ;
goto V_213;
}
for ( V_214 = 0 ; V_214 < V_352 ; V_214 ++ )
V_2 -> V_219 [ V_214 ] . V_218 = V_214 ;
V_212 = F_223 ( V_2 , V_352 ) ;
if ( V_212 )
goto V_213;
V_212 = F_233 ( V_39 , V_2 -> V_208 ) ;
if ( V_212 )
goto V_213;
V_212 = F_234 ( V_39 , V_2 -> V_206 ) ;
V_213:
return V_212 ;
}
static int F_235 ( struct V_1 * V_2 )
{
int V_292 , V_353 ;
struct V_52 * V_53 ;
V_353 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_353 ; V_292 ++ ) {
V_53 = F_230 ( sizeof( struct V_52 ) , V_347 ) ;
if ( ! V_53 )
goto V_354;
V_53 -> V_2 = V_2 ;
V_53 -> V_165 = V_292 ;
F_236 ( V_2 -> V_39 , & V_53 -> V_77 ,
F_111 , 64 ) ;
#ifdef F_55
F_237 ( & V_53 -> V_77 ) ;
#endif
V_2 -> V_53 [ V_292 ] = V_53 ;
}
return 0 ;
V_354:
while ( V_292 ) {
V_292 -- ;
V_53 = V_2 -> V_53 [ V_292 ] ;
#ifdef F_55
F_238 ( & V_53 -> V_77 ) ;
#endif
F_239 ( & V_53 -> V_77 ) ;
F_225 ( V_53 ) ;
V_2 -> V_53 [ V_292 ] = NULL ;
}
return - V_351 ;
}
static void F_240 ( struct V_1 * V_2 )
{
int V_292 , V_353 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_353 ; V_292 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_292 ] ;
V_2 -> V_53 [ V_292 ] = NULL ;
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
F_225 ( V_2 -> V_219 ) ;
V_2 -> V_219 = NULL ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_212 ;
F_226 ( V_2 ) ;
V_212 = F_231 ( V_2 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_9 ,
L_26 ) ;
goto V_355;
}
V_212 = F_235 ( V_2 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_9 , L_27 ) ;
goto V_356;
}
V_212 = F_229 ( V_2 ) ;
if ( V_212 ) {
F_46 ( L_28 ) ;
goto V_357;
}
F_136 ( & V_2 -> V_9 , L_29 ,
( V_2 -> V_206 > 1 ) ? L_30 :
L_31 , V_2 -> V_206 , V_2 -> V_208 ) ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_357:
F_240 ( V_2 ) ;
V_356:
F_241 ( V_2 ) ;
V_355:
return V_212 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ ) {
F_225 ( V_2 -> V_28 [ V_59 ] ) ;
V_2 -> V_28 [ V_59 ] = NULL ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ ) {
F_225 ( V_2 -> V_102 [ V_59 ] ) ;
V_2 -> V_102 [ V_59 ] = NULL ;
}
V_2 -> V_208 = 0 ;
V_2 -> V_206 = 0 ;
F_240 ( V_2 ) ;
F_241 ( V_2 ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_358 * V_12 = V_2 -> V_12 ;
struct V_51 * V_39 = V_2 -> V_39 ;
int V_212 ;
V_9 -> V_359 = V_12 -> V_360 ;
V_9 -> V_361 = V_12 -> V_335 ;
V_9 -> V_362 = V_12 -> V_363 ;
V_9 -> V_364 = V_12 -> V_365 ;
V_9 -> V_366 = V_12 -> V_367 ;
V_9 -> V_295 . V_271 . V_368 ( V_9 ) ;
V_9 -> V_195 . V_369 = 2 ;
V_9 -> V_195 . V_370 = 2 ;
F_246 ( & V_2 -> V_270 ) ;
V_212 = V_9 -> V_195 . V_271 . V_338 ( V_9 ) ;
if ( V_212 ) {
F_247 ( & V_12 -> V_13 ,
L_32 ) ;
} else {
V_212 = V_9 -> V_195 . V_271 . V_339 ( V_9 ) ;
if ( V_212 ) {
F_46 ( L_33 , V_212 ) ;
goto V_213;
}
F_200 ( V_2 ) ;
V_212 = V_9 -> V_195 . V_271 . V_371 ( V_9 , V_9 -> V_195 . V_282 ) ;
if ( V_212 )
F_247 ( & V_12 -> V_13 , L_34 ) ;
else if ( F_248 ( V_2 -> V_9 . V_195 . V_282 ) )
F_247 ( & V_12 -> V_13 ,
L_35 ) ;
memcpy ( V_39 -> V_156 , V_9 -> V_195 . V_282 , V_39 -> V_340 ) ;
}
if ( ! F_203 ( V_39 -> V_156 ) ) {
F_247 ( & V_12 -> V_13 , L_36 ) ;
F_249 ( V_39 ) ;
memcpy ( V_9 -> V_195 . V_282 , V_39 -> V_156 , V_39 -> V_340 ) ;
}
V_2 -> V_164 = 1 ;
V_2 -> V_178 = 1 ;
V_2 -> V_349 = V_372 ;
V_2 -> V_350 = V_373 ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_213:
return V_212 ;
}
void F_250 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_337 , & V_2 -> V_4 ) )
return;
F_251 ( V_314 , V_2 -> V_37 . V_313 ,
V_2 -> V_37 . V_298 ) ;
F_251 ( V_319 , V_2 -> V_37 . V_318 ,
V_2 -> V_37 . V_299 ) ;
F_252 ( V_316 , V_317 ,
V_2 -> V_37 . V_315 ,
V_2 -> V_37 . V_305 ) ;
F_252 ( V_321 , V_322 ,
V_2 -> V_37 . V_320 ,
V_2 -> V_37 . V_308 ) ;
F_251 ( V_324 , V_2 -> V_37 . V_323 ,
V_2 -> V_37 . V_311 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ ) {
V_2 -> V_374 +=
V_2 -> V_102 [ V_59 ] -> V_374 ;
V_2 -> V_102 [ V_59 ] -> V_374 = 0 ;
}
}
static void F_253 ( unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_146 ;
F_205 ( & V_2 -> V_334 , ( V_375 * 2 ) + V_74 ) ;
F_1 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_49 & V_50 ) )
return;
V_2 -> V_49 &= ~ V_50 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_337 , & V_2 -> V_4 ) )
return;
V_2 -> V_376 ++ ;
F_219 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_377 = 0 ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_337 , & V_2 -> V_4 ) )
return;
if ( F_49 ( V_2 -> V_39 ) ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ )
F_256 ( V_2 -> V_28 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_175 - V_176 ; V_59 ++ ) {
struct V_52 * V_378 = V_2 -> V_53 [ V_59 ] ;
if ( V_378 -> V_158 . V_36 || V_378 -> V_70 . V_36 )
V_377 |= 1 << V_59 ;
}
F_19 ( V_9 , V_379 , V_377 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_1 V_380 = V_2 -> V_380 ;
bool V_381 = V_2 -> V_381 ;
T_10 V_212 ;
F_177 ( & V_2 -> V_270 ) ;
V_212 = V_9 -> V_195 . V_271 . V_382 ( V_9 , & V_380 , & V_381 , false ) ;
F_178 ( & V_2 -> V_270 ) ;
if ( V_212 && F_258 ( V_74 , V_2 -> V_341 + ( 10 * V_375 ) ) ) {
V_2 -> V_49 |= V_50 ;
V_381 = false ;
}
V_2 -> V_381 = V_381 ;
V_2 -> V_380 = V_380 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
if ( F_49 ( V_39 ) )
return;
F_247 ( & V_2 -> V_12 -> V_13 , L_37 ,
( V_2 -> V_380 == V_383 ) ?
L_38 :
( V_2 -> V_380 == V_384 ) ?
L_39 :
( V_2 -> V_380 == V_385 ) ?
L_40 :
L_41 ) ;
F_260 ( V_39 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_51 * V_39 = V_2 -> V_39 ;
V_2 -> V_380 = 0 ;
if ( ! F_49 ( V_39 ) )
return;
F_247 ( & V_2 -> V_12 -> V_13 , L_42 ) ;
F_214 ( V_39 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_337 , & V_2 -> V_4 ) )
return;
F_257 ( V_2 ) ;
if ( V_2 -> V_381 )
F_259 ( V_2 ) ;
else
F_261 ( V_2 ) ;
F_250 ( V_2 ) ;
}
static void F_263 ( struct V_386 * V_387 )
{
struct V_1 * V_2 = F_112 ( V_387 ,
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
if ( ! V_28 -> V_336 )
return;
F_269 ( V_28 -> V_13 , V_28 -> V_135 , V_28 -> V_336 ,
V_28 -> V_33 ) ;
V_28 -> V_336 = NULL ;
}
static void F_270 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ )
if ( V_2 -> V_28 [ V_59 ] -> V_336 )
F_267 ( V_2 -> V_28 [ V_59 ] ) ;
}
int F_271 ( struct V_27 * V_28 )
{
int V_135 ;
V_135 = sizeof( struct V_29 ) * V_28 -> V_43 ;
V_28 -> V_61 = F_272 ( V_135 ) ;
if ( ! V_28 -> V_61 )
goto V_212;
V_28 -> V_135 = V_28 -> V_43 * sizeof( union V_54 ) ;
V_28 -> V_135 = F_92 ( V_28 -> V_135 , 4096 ) ;
V_28 -> V_336 = F_273 ( V_28 -> V_13 , V_28 -> V_135 ,
& V_28 -> V_33 , V_347 ) ;
if ( ! V_28 -> V_336 )
goto V_212;
return 0 ;
V_212:
F_268 ( V_28 -> V_61 ) ;
V_28 -> V_61 = NULL ;
F_136 ( & V_2 -> V_9 , L_43 ) ;
return - V_351 ;
}
static int F_274 ( struct V_1 * V_2 )
{
int V_59 , V_212 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ ) {
V_212 = F_271 ( V_2 -> V_28 [ V_59 ] ) ;
if ( ! V_212 )
continue;
F_136 ( & V_2 -> V_9 , L_44 , V_59 ) ;
break;
}
return V_212 ;
}
int F_275 ( struct V_27 * V_102 )
{
int V_135 ;
V_135 = sizeof( struct V_113 ) * V_102 -> V_43 ;
V_102 -> V_122 = F_272 ( V_135 ) ;
if ( ! V_102 -> V_122 )
goto V_212;
V_102 -> V_135 = V_102 -> V_43 * sizeof( union V_78 ) ;
V_102 -> V_135 = F_92 ( V_102 -> V_135 , 4096 ) ;
V_102 -> V_336 = F_273 ( V_102 -> V_13 , V_102 -> V_135 ,
& V_102 -> V_33 , V_347 ) ;
if ( ! V_102 -> V_336 )
goto V_212;
return 0 ;
V_212:
F_268 ( V_102 -> V_122 ) ;
V_102 -> V_122 = NULL ;
F_10 ( V_102 -> V_13 , L_45 ) ;
return - V_351 ;
}
static int F_276 ( struct V_1 * V_2 )
{
int V_59 , V_212 = 0 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ ) {
V_212 = F_275 ( V_2 -> V_102 [ V_59 ] ) ;
if ( ! V_212 )
continue;
F_136 ( & V_2 -> V_9 , L_46 , V_59 ) ;
break;
}
return V_212 ;
}
void F_277 ( struct V_27 * V_102 )
{
F_207 ( V_102 ) ;
F_268 ( V_102 -> V_122 ) ;
V_102 -> V_122 = NULL ;
F_269 ( V_102 -> V_13 , V_102 -> V_135 , V_102 -> V_336 ,
V_102 -> V_33 ) ;
V_102 -> V_336 = NULL ;
}
static void F_278 ( struct V_1 * V_2 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ )
if ( V_2 -> V_102 [ V_59 ] -> V_336 )
F_277 ( V_2 -> V_102 [ V_59 ] ) ;
}
static int F_279 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_212 ;
if ( ! V_2 -> V_175 )
return - V_351 ;
if ( V_9 -> V_388 ) {
F_218 ( V_2 ) ;
if ( V_9 -> V_388 ) {
V_212 = V_273 ;
F_46 ( L_47 ) ;
goto V_389;
}
}
if ( F_2 ( V_390 , & V_2 -> V_4 ) )
return - V_391 ;
F_214 ( V_39 ) ;
V_212 = F_274 ( V_2 ) ;
if ( V_212 )
goto V_392;
V_212 = F_276 ( V_2 ) ;
if ( V_212 )
goto V_393;
F_197 ( V_2 ) ;
F_132 ( V_2 ) ;
V_212 = F_139 ( V_2 ) ;
if ( V_212 )
goto V_394;
F_202 ( V_2 ) ;
return 0 ;
V_394:
F_212 ( V_2 ) ;
V_393:
F_278 ( V_2 ) ;
V_392:
F_270 ( V_2 ) ;
F_218 ( V_2 ) ;
V_389:
return V_212 ;
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
if ( ! ( V_2 -> V_49 & V_297 ) )
return;
V_2 -> V_49 &= ~ V_297 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_337 , & V_2 -> V_4 ) )
return;
if ( F_281 ( V_13 ) )
F_280 ( V_13 ) ;
F_244 ( V_2 ) ;
F_243 ( V_2 ) ;
if ( F_281 ( V_13 ) )
F_279 ( V_13 ) ;
}
static void F_282 ( struct V_27 * V_28 ,
T_1 V_395 , T_1 V_396 ,
T_1 V_397 )
{
struct V_398 * V_399 ;
T_6 V_59 = V_28 -> V_72 ;
V_399 = F_283 ( V_28 , V_59 ) ;
V_59 ++ ;
V_28 -> V_72 = ( V_59 < V_28 -> V_43 ) ? V_59 : 0 ;
V_396 |= V_400 | V_401 ;
V_399 -> V_395 = F_40 ( V_395 ) ;
V_399 -> V_402 = 0 ;
V_399 -> V_403 = F_40 ( V_396 ) ;
V_399 -> V_397 = F_40 ( V_397 ) ;
}
static int F_284 ( struct V_27 * V_28 ,
struct V_29 * V_404 ,
T_2 * V_405 )
{
struct V_76 * V_31 = V_404 -> V_31 ;
T_1 V_395 , V_396 ;
T_1 V_397 , V_406 ;
int V_212 ;
if ( V_31 -> V_100 != V_407 )
return 0 ;
if ( ! F_285 ( V_31 ) )
return 0 ;
V_212 = F_286 ( V_31 , 0 ) ;
if ( V_212 < 0 )
return V_212 ;
V_396 = V_408 ;
if ( V_404 -> V_110 == F_69 ( V_409 ) ) {
struct V_410 * V_411 = F_287 ( V_31 ) ;
V_411 -> V_412 = 0 ;
V_411 -> V_413 = 0 ;
F_288 ( V_31 ) -> V_413 = ~ F_289 ( V_411 -> V_414 ,
V_411 -> V_415 , 0 ,
V_416 ,
0 ) ;
V_396 |= V_417 ;
V_404 -> V_418 |= V_419 |
V_420 |
V_421 ;
} else if ( F_290 ( V_31 ) ) {
F_291 ( V_31 ) -> V_422 = 0 ;
F_288 ( V_31 ) -> V_413 =
~ F_292 ( & F_291 ( V_31 ) -> V_414 ,
& F_291 ( V_31 ) -> V_415 ,
0 , V_416 , 0 ) ;
V_404 -> V_418 |= V_419 |
V_420 ;
}
V_406 = F_293 ( V_31 ) ;
* V_405 += V_406 ;
* V_405 = F_294 ( V_31 ) + V_406 ;
V_404 -> V_67 = F_98 ( V_31 ) -> V_67 ;
V_404 -> V_66 += ( V_404 -> V_67 - 1 ) * * V_405 ;
V_397 = V_406 << V_423 ;
V_397 |= F_98 ( V_31 ) -> V_424 << V_425 ;
V_397 |= 1 << V_426 ;
V_395 = F_295 ( V_31 ) ;
V_395 |= F_296 ( V_31 ) << V_427 ;
V_395 |= V_404 -> V_418 & V_428 ;
F_282 ( V_28 , V_395 ,
V_396 , V_397 ) ;
return 1 ;
}
static void F_297 ( struct V_27 * V_28 ,
struct V_29 * V_404 )
{
struct V_76 * V_31 = V_404 -> V_31 ;
T_1 V_395 = 0 ;
T_1 V_397 = 0 ;
T_1 V_396 = 0 ;
if ( V_31 -> V_100 == V_407 ) {
T_2 V_429 = 0 ;
switch ( V_404 -> V_110 ) {
case F_69 ( V_409 ) :
V_395 |= F_295 ( V_31 ) ;
V_396 |= V_417 ;
V_429 = F_287 ( V_31 ) -> V_110 ;
break;
case F_69 ( V_430 ) :
V_395 |= F_295 ( V_31 ) ;
V_429 = F_291 ( V_31 ) -> V_431 ;
break;
default:
if ( F_16 ( F_298 () ) ) {
F_299 ( V_28 -> V_13 ,
L_48 ,
V_404 -> V_110 ) ;
}
break;
}
switch ( V_429 ) {
case V_416 :
V_396 |= V_408 ;
V_397 = F_293 ( V_31 ) <<
V_423 ;
break;
case V_432 :
V_396 |= V_433 ;
V_397 = sizeof( struct V_434 ) <<
V_423 ;
break;
case V_435 :
V_397 = sizeof( struct V_436 ) <<
V_423 ;
break;
default:
if ( F_16 ( F_298 () ) ) {
F_299 ( V_28 -> V_13 ,
L_49 ,
V_429 ) ;
}
break;
}
V_404 -> V_418 |= V_420 ;
}
V_395 |= F_296 ( V_31 ) << V_427 ;
V_395 |= V_404 -> V_418 & V_428 ;
F_282 ( V_28 , V_395 ,
V_396 , V_397 ) ;
}
static T_11 F_300 ( T_1 V_418 )
{
T_11 V_437 = F_40 ( V_438 |
V_439 |
V_440 ) ;
if ( V_418 & V_441 )
V_437 |= F_40 ( V_442 ) ;
if ( V_418 & V_419 )
V_437 |= F_40 ( V_443 ) ;
return V_437 ;
}
static void F_301 ( union V_54 * V_55 ,
T_1 V_418 , unsigned int V_444 )
{
T_11 V_445 = F_40 ( V_444 << V_446 ) ;
if ( V_418 & V_420 )
V_445 |= F_40 ( V_447 ) ;
if ( V_418 & V_421 )
V_445 |= F_40 ( V_448 ) ;
if ( V_418 & V_419 )
V_445 |= F_40 ( 1 << V_426 ) ;
V_445 |= F_40 ( V_449 ) ;
V_55 -> V_123 . V_445 = V_445 ;
}
static void F_302 ( struct V_27 * V_28 ,
struct V_29 * V_404 ,
const T_2 V_405 )
{
T_7 V_33 ;
struct V_76 * V_31 = V_404 -> V_31 ;
struct V_29 * V_30 ;
union V_54 * V_55 ;
struct V_450 * V_451 = & F_98 ( V_31 ) -> V_452 [ 0 ] ;
unsigned int V_453 = V_31 -> V_453 ;
unsigned int V_135 = F_303 ( V_31 ) ;
unsigned int V_444 = V_31 -> V_32 - V_405 ;
T_1 V_418 = V_404 -> V_418 ;
T_11 V_437 ;
T_6 V_59 = V_28 -> V_72 ;
V_55 = F_38 ( V_28 , V_59 ) ;
F_301 ( V_55 , V_418 , V_444 ) ;
V_437 = F_300 ( V_418 ) ;
V_33 = F_304 ( V_28 -> V_13 , V_31 -> V_146 , V_135 , V_34 ) ;
if ( F_76 ( V_28 -> V_13 , V_33 ) )
goto V_454;
F_27 ( V_404 , V_32 , V_135 ) ;
F_305 ( V_404 , V_33 , V_33 ) ;
V_55 -> V_123 . V_455 = F_79 ( V_33 ) ;
for (; ; ) {
while ( F_16 ( V_135 > V_456 ) ) {
V_55 -> V_123 . V_457 =
V_437 | F_40 ( V_456 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_33 += V_456 ;
V_135 -= V_456 ;
V_55 -> V_123 . V_455 = F_79 ( V_33 ) ;
V_55 -> V_123 . V_445 = 0 ;
}
if ( F_42 ( ! V_453 ) )
break;
V_55 -> V_123 . V_457 = V_437 | F_40 ( V_135 ) ;
V_59 ++ ;
V_55 ++ ;
if ( V_59 == V_28 -> V_43 ) {
V_55 = F_38 ( V_28 , 0 ) ;
V_59 = 0 ;
}
V_135 = F_306 ( V_451 ) ;
V_453 -= V_135 ;
V_33 = F_307 ( V_28 -> V_13 , V_451 , 0 , V_135 ,
V_34 ) ;
if ( F_76 ( V_28 -> V_13 , V_33 ) )
goto V_454;
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_27 ( V_30 , V_32 , V_135 ) ;
F_305 ( V_30 , V_33 , V_33 ) ;
V_55 -> V_123 . V_455 = F_79 ( V_33 ) ;
V_55 -> V_123 . V_445 = 0 ;
V_451 ++ ;
}
V_437 |= F_40 ( V_135 ) | F_40 ( V_458 ) ;
V_55 -> V_123 . V_457 = V_437 ;
V_404 -> V_73 = V_74 ;
F_80 () ;
V_404 -> V_35 = V_55 ;
V_59 ++ ;
if ( V_59 == V_28 -> V_43 )
V_59 = 0 ;
V_28 -> V_72 = V_59 ;
F_81 ( V_28 , V_59 ) ;
return;
V_454:
F_10 ( V_28 -> V_13 , L_50 ) ;
for (; ; ) {
V_30 = & V_28 -> V_61 [ V_59 ] ;
F_21 ( V_28 , V_30 ) ;
if ( V_30 == V_404 )
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
return - V_391 ;
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
struct V_29 * V_404 ;
struct V_27 * V_28 ;
int V_459 ;
T_1 V_418 = 0 ;
T_6 V_43 = F_312 ( F_303 ( V_31 ) ) ;
#if V_117 > V_456
unsigned short V_460 ;
#endif
T_2 V_405 = 0 ;
T_2 * V_461 = F_313 ( V_31 , 0 , 0 , NULL ) ;
if ( ! V_461 || F_314 ( V_461 ) ) {
F_22 ( V_31 ) ;
return V_462 ;
}
V_28 = V_2 -> V_28 [ V_31 -> V_463 ] ;
#if V_117 > V_456
for ( V_460 = 0 ; V_460 < F_98 ( V_31 ) -> V_142 ; V_460 ++ )
V_43 += F_312 ( F_98 ( V_31 ) -> V_452 [ V_460 ] . V_135 ) ;
#else
V_43 += F_98 ( V_31 ) -> V_142 ;
#endif
if ( F_310 ( V_28 , V_43 + 3 ) ) {
V_28 -> V_46 . V_464 ++ ;
return V_465 ;
}
V_404 = & V_28 -> V_61 [ V_28 -> V_72 ] ;
V_404 -> V_31 = V_31 ;
V_404 -> V_66 = V_31 -> V_32 ;
V_404 -> V_67 = 1 ;
if ( F_315 ( V_31 ) ) {
V_418 |= F_316 ( V_31 ) ;
V_418 <<= V_466 ;
V_418 |= V_441 ;
}
V_404 -> V_418 = V_418 ;
V_404 -> V_110 = F_317 ( V_31 ) ;
V_459 = F_284 ( V_28 , V_404 , & V_405 ) ;
if ( V_459 < 0 )
goto V_467;
else if ( ! V_459 )
F_297 ( V_28 , V_404 ) ;
F_302 ( V_28 , V_404 , V_405 ) ;
F_310 ( V_28 , V_468 ) ;
return V_462 ;
V_467:
F_22 ( V_404 -> V_31 ) ;
V_404 -> V_31 = NULL ;
return V_462 ;
}
static int F_318 ( struct V_51 * V_39 , void * V_469 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_470 * V_282 = V_469 ;
if ( ! F_203 ( V_282 -> V_471 ) )
return - V_472 ;
memcpy ( V_39 -> V_156 , V_282 -> V_471 , V_39 -> V_340 ) ;
memcpy ( V_9 -> V_195 . V_282 , V_282 -> V_471 , V_39 -> V_340 ) ;
F_177 ( & V_2 -> V_270 ) ;
V_9 -> V_195 . V_271 . V_331 ( V_9 , 0 , V_9 -> V_195 . V_282 , 0 ) ;
F_178 ( & V_2 -> V_270 ) ;
return 0 ;
}
static int F_319 ( struct V_51 * V_39 , int V_473 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_474 = V_473 + V_267 + V_268 ;
int V_475 = V_476 ;
switch ( V_2 -> V_9 . V_346 ) {
case V_327 :
case V_326 :
V_475 = V_477 ;
break;
default:
if ( V_2 -> V_9 . V_195 . type != V_478 )
V_475 = V_477 ;
break;
}
if ( ( V_473 < 68 ) || ( V_474 > V_475 ) )
return - V_479 ;
F_136 ( V_9 , L_51 ,
V_39 -> V_266 , V_473 ) ;
V_39 -> V_266 = V_473 ;
F_175 ( V_9 , V_474 ) ;
return 0 ;
}
static void F_320 ( struct V_51 * V_39 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
int V_59 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ )
F_128 ( 0 , V_2 -> V_53 [ V_59 ] ) ;
}
static int F_321 ( struct V_358 * V_12 , T_12 V_4 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
#ifdef F_323
int V_480 = 0 ;
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
V_480 = F_325 ( V_12 ) ;
if ( V_480 )
return V_480 ;
#endif
if ( ! F_3 ( V_481 , & V_2 -> V_4 ) )
F_326 ( V_12 ) ;
return 0 ;
}
static int F_327 ( struct V_358 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
T_1 V_212 ;
F_328 ( V_12 ) ;
F_325 ( V_12 ) ;
V_212 = F_329 ( V_12 ) ;
if ( V_212 ) {
F_10 ( & V_12 -> V_13 , L_52 ) ;
return V_212 ;
}
F_7 () ;
F_8 ( V_481 , & V_2 -> V_4 ) ;
F_330 ( V_12 ) ;
F_218 ( V_2 ) ;
F_264 () ;
V_212 = F_243 ( V_2 ) ;
F_265 () ;
if ( V_212 ) {
F_10 ( & V_12 -> V_13 , L_53 ) ;
return V_212 ;
}
if ( F_281 ( V_39 ) ) {
V_212 = F_279 ( V_39 ) ;
if ( V_212 )
return V_212 ;
}
F_331 ( V_39 ) ;
return V_212 ;
}
static void F_332 ( struct V_358 * V_12 )
{
F_321 ( V_12 , V_482 ) ;
}
static struct V_483 * F_333 ( struct V_51 * V_39 ,
struct V_483 * V_37 )
{
struct V_1 * V_2 = F_30 ( V_39 ) ;
unsigned int V_484 ;
T_5 V_69 , V_38 ;
const struct V_27 * V_36 ;
int V_59 ;
F_250 ( V_2 ) ;
V_37 -> V_485 = V_2 -> V_37 . V_311 - V_2 -> V_37 . V_312 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_206 ; V_59 ++ ) {
V_36 = V_2 -> V_102 [ V_59 ] ;
do {
V_484 = F_334 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_335 ( & V_36 -> V_68 , V_484 ) );
V_37 -> V_486 += V_69 ;
V_37 -> V_487 += V_38 ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_208 ; V_59 ++ ) {
V_36 = V_2 -> V_28 [ V_59 ] ;
do {
V_484 = F_334 ( & V_36 -> V_68 ) ;
V_69 = V_36 -> V_37 . V_69 ;
V_38 = V_36 -> V_37 . V_38 ;
} while ( F_335 ( & V_36 -> V_68 , V_484 ) );
V_37 -> V_488 += V_69 ;
V_37 -> V_489 += V_38 ;
}
return V_37 ;
}
static void F_336 ( struct V_51 * V_13 )
{
V_13 -> V_490 = & V_491 ;
F_337 ( V_13 ) ;
V_13 -> V_492 = 5 * V_375 ;
}
static int F_338 ( struct V_358 * V_12 , const struct V_493 * V_494 )
{
struct V_51 * V_39 ;
struct V_1 * V_2 = NULL ;
struct V_8 * V_9 = NULL ;
const struct V_495 * V_496 = V_497 [ V_494 -> V_498 ] ;
int V_212 , V_499 ;
bool V_500 = false ;
V_212 = F_339 ( V_12 ) ;
if ( V_212 )
return V_212 ;
if ( ! F_340 ( & V_12 -> V_13 , F_148 ( 64 ) ) ) {
V_499 = 1 ;
} else {
V_212 = F_340 ( & V_12 -> V_13 , F_148 ( 32 ) ) ;
if ( V_212 ) {
F_10 ( & V_12 -> V_13 , L_54 ) ;
goto V_501;
}
V_499 = 0 ;
}
V_212 = F_341 ( V_12 , V_502 ) ;
if ( V_212 ) {
F_10 ( & V_12 -> V_13 , L_55 , V_212 ) ;
goto V_503;
}
F_330 ( V_12 ) ;
V_39 = F_342 ( sizeof( struct V_1 ) ,
V_504 ) ;
if ( ! V_39 ) {
V_212 = - V_351 ;
goto V_505;
}
F_343 ( V_39 , & V_12 -> V_13 ) ;
V_2 = F_30 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_12 = V_12 ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_10 = V_2 ;
V_2 -> V_506 = F_344 ( V_507 , V_508 ) ;
F_325 ( V_12 ) ;
V_9 -> V_11 = F_345 ( F_346 ( V_12 , 0 ) ,
F_347 ( V_12 , 0 ) ) ;
V_2 -> V_232 = V_9 -> V_11 ;
if ( ! V_9 -> V_11 ) {
V_212 = - V_274 ;
goto V_509;
}
F_336 ( V_39 ) ;
memcpy ( & V_9 -> V_195 . V_271 , V_496 -> V_510 , sizeof( V_9 -> V_195 . V_271 ) ) ;
V_9 -> V_195 . type = V_496 -> V_195 ;
memcpy ( & V_9 -> V_295 . V_271 , & V_511 ,
sizeof( struct V_512 ) ) ;
V_212 = F_245 ( V_2 ) ;
if ( V_212 )
goto V_513;
if ( ! F_203 ( V_39 -> V_156 ) ) {
F_46 ( L_56 ) ;
V_212 = - V_274 ;
goto V_513;
}
V_39 -> V_514 = V_515 |
V_516 |
V_517 |
V_518 |
V_519 |
V_93 ;
V_39 -> V_81 = V_39 -> V_514 |
V_520 |
V_521 |
V_522 ;
V_39 -> V_523 |= V_518 |
V_519 |
V_516 |
V_517 |
V_515 ;
if ( V_499 )
V_39 -> V_81 |= V_524 ;
V_39 -> V_525 |= V_526 ;
if ( F_14 ( V_9 -> V_11 ) ) {
V_212 = - V_274 ;
goto V_513;
}
F_348 ( & V_2 -> V_334 , & F_253 ,
( unsigned long ) V_2 ) ;
F_349 ( & V_2 -> V_7 , F_263 ) ;
F_179 ( V_14 , & V_2 -> V_4 ) ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
V_212 = F_243 ( V_2 ) ;
if ( V_212 )
goto V_513;
strcpy ( V_39 -> V_220 , L_57 ) ;
V_212 = F_350 ( V_39 ) ;
if ( V_212 )
goto V_527;
F_351 ( V_12 , V_39 ) ;
F_214 ( V_39 ) ;
F_199 ( V_2 ) ;
F_247 ( & V_12 -> V_13 , L_58 , V_39 -> V_156 ) ;
F_247 ( & V_12 -> V_13 , L_59 , V_9 -> V_195 . type ) ;
switch ( V_9 -> V_195 . type ) {
case V_265 :
F_247 ( & V_12 -> V_13 , L_60 ) ;
break;
case V_528 :
F_247 ( & V_12 -> V_13 , L_61 ) ;
break;
case V_478 :
default:
F_247 ( & V_12 -> V_13 , L_62 ) ;
break;
}
return 0 ;
V_527:
F_244 ( V_2 ) ;
V_513:
F_241 ( V_2 ) ;
F_352 ( V_2 -> V_232 ) ;
V_509:
V_500 = ! F_3 ( V_481 , & V_2 -> V_4 ) ;
F_353 ( V_39 ) ;
V_505:
F_354 ( V_12 ) ;
V_503:
V_501:
if ( ! V_2 || V_500 )
F_326 ( V_12 ) ;
return V_212 ;
}
static void F_355 ( struct V_358 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 ;
bool V_500 ;
if ( ! V_39 )
return;
V_2 = F_30 ( V_39 ) ;
F_179 ( V_5 , & V_2 -> V_4 ) ;
F_356 ( & V_2 -> V_7 ) ;
if ( V_39 -> V_529 == V_530 )
F_357 ( V_39 ) ;
F_244 ( V_2 ) ;
F_241 ( V_2 ) ;
F_352 ( V_2 -> V_232 ) ;
F_354 ( V_12 ) ;
F_136 ( & V_2 -> V_9 , L_63 ) ;
V_500 = ! F_3 ( V_481 , & V_2 -> V_4 ) ;
F_353 ( V_39 ) ;
if ( V_500 )
F_326 ( V_12 ) ;
}
static T_13 F_358 ( struct V_358 * V_12 ,
T_14 V_4 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( ! F_2 ( V_14 , & V_2 -> V_4 ) )
return V_531 ;
F_264 () ;
F_324 ( V_39 ) ;
if ( V_4 == V_532 ) {
F_265 () ;
return V_531 ;
}
if ( F_281 ( V_39 ) )
F_212 ( V_2 ) ;
if ( ! F_3 ( V_481 , & V_2 -> V_4 ) )
F_326 ( V_12 ) ;
F_265 () ;
return V_533 ;
}
static T_13 F_359 ( struct V_358 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_329 ( V_12 ) ) {
F_10 ( & V_12 -> V_13 ,
L_64 ) ;
return V_531 ;
}
F_7 () ;
F_8 ( V_481 , & V_2 -> V_4 ) ;
F_330 ( V_12 ) ;
F_218 ( V_2 ) ;
return V_534 ;
}
static void F_360 ( struct V_358 * V_12 )
{
struct V_51 * V_39 = F_322 ( V_12 ) ;
struct V_1 * V_2 = F_30 ( V_39 ) ;
if ( F_281 ( V_39 ) )
F_206 ( V_2 ) ;
F_331 ( V_39 ) ;
}
static int T_15 F_361 ( void )
{
int V_535 ;
F_194 ( L_65 , V_536 ,
V_537 ) ;
F_194 ( L_66 , V_538 ) ;
V_535 = F_362 ( & V_539 ) ;
return V_535 ;
}
static void T_16 F_363 ( void )
{
F_364 ( & V_539 ) ;
}
char * F_365 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
return V_2 -> V_39 -> V_220 ;
}
