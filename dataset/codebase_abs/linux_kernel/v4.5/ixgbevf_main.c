static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) &&
! F_3 ( V_6 , & V_2 -> V_4 ) )
F_4 ( V_7 , & V_2 -> V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( ! F_2 ( V_6 , & V_2 -> V_4 ) ) ;
F_7 () ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
if ( ! V_10 -> V_12 )
return;
V_10 -> V_12 = NULL ;
F_10 ( & V_2 -> V_13 -> V_14 , L_1 ) ;
if ( F_2 ( V_15 , & V_2 -> V_4 ) )
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_9 * V_10 , T_1 V_16 )
{
T_1 V_17 ;
if ( V_16 == V_18 ) {
F_9 ( V_10 ) ;
return;
}
V_17 = F_12 ( V_10 , V_18 ) ;
if ( V_17 == V_19 )
F_9 ( V_10 ) ;
}
T_1 F_12 ( struct V_9 * V_10 , T_1 V_16 )
{
T_2 T_3 * V_20 = F_13 ( V_10 -> V_12 ) ;
T_1 V_17 ;
if ( F_14 ( V_20 ) )
return V_19 ;
V_17 = F_15 ( V_20 + V_16 ) ;
if ( F_16 ( V_17 == V_19 ) )
F_11 ( V_10 , V_16 ) ;
return V_17 ;
}
static void F_17 ( struct V_1 * V_2 , T_4 V_21 ,
T_2 V_22 , T_2 V_23 )
{
T_1 V_24 , V_25 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
if ( V_21 == - 1 ) {
V_23 |= V_26 ;
V_24 = F_18 ( V_10 , V_27 ) ;
V_24 &= ~ 0xFF ;
V_24 |= V_23 ;
F_19 ( V_10 , V_27 , V_24 ) ;
} else {
V_23 |= V_26 ;
V_25 = ( ( 16 * ( V_22 & 1 ) ) + ( 8 * V_21 ) ) ;
V_24 = F_18 ( V_10 , F_20 ( V_22 >> 1 ) ) ;
V_24 &= ~ ( 0xFF << V_25 ) ;
V_24 |= ( V_23 << V_25 ) ;
F_19 ( V_10 , F_20 ( V_22 >> 1 ) , V_24 ) ;
}
}
static void F_21 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
if ( V_31 -> V_32 ) {
F_22 ( V_31 -> V_32 ) ;
if ( F_23 ( V_31 , V_33 ) )
F_24 ( V_29 -> V_14 ,
F_25 ( V_31 , V_34 ) ,
F_23 ( V_31 , V_33 ) ,
V_35 ) ;
} else if ( F_23 ( V_31 , V_33 ) ) {
F_26 ( V_29 -> V_14 ,
F_25 ( V_31 , V_34 ) ,
F_23 ( V_31 , V_33 ) ,
V_35 ) ;
}
V_31 -> V_36 = NULL ;
V_31 -> V_32 = NULL ;
F_27 ( V_31 , V_33 , 0 ) ;
}
static T_5 F_28 ( struct V_28 * V_37 )
{
return V_37 -> V_38 . V_39 ;
}
static T_1 F_29 ( struct V_28 * V_37 )
{
struct V_1 * V_2 = F_30 ( V_37 -> V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_41 = F_18 ( V_10 , F_31 ( V_37 -> V_42 ) ) ;
T_1 V_43 = F_18 ( V_10 , F_32 ( V_37 -> V_42 ) ) ;
if ( V_41 != V_43 )
return ( V_41 < V_43 ) ?
V_43 - V_41 : ( V_43 + V_37 -> V_44 - V_41 ) ;
return 0 ;
}
static inline bool F_33 ( struct V_28 * V_29 )
{
T_1 V_45 = F_28 ( V_29 ) ;
T_1 V_46 = V_29 -> V_47 . V_46 ;
T_1 V_48 = F_29 ( V_29 ) ;
F_34 ( V_29 ) ;
if ( ( V_46 == V_45 ) && V_48 ) {
return F_3 ( V_49 ,
& V_29 -> V_4 ) ;
}
F_8 ( V_49 , & V_29 -> V_4 ) ;
V_29 -> V_47 . V_46 = V_45 ;
return false ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_50 |= V_51 ;
F_1 ( V_2 ) ;
}
}
static void F_36 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
F_35 ( V_2 ) ;
}
static bool F_37 ( struct V_53 * V_54 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_30 * V_31 ;
union V_55 * V_56 ;
unsigned int V_57 = 0 , V_58 = 0 ;
unsigned int V_59 = V_29 -> V_44 / 2 ;
unsigned int V_60 = V_29 -> V_61 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return true ;
V_31 = & V_29 -> V_62 [ V_60 ] ;
V_56 = F_38 ( V_29 , V_60 ) ;
V_60 -= V_29 -> V_44 ;
do {
union V_55 * V_63 = V_31 -> V_36 ;
if ( ! V_63 )
break;
F_39 () ;
if ( ! ( V_63 -> V_64 . V_65 & F_40 ( V_66 ) ) )
break;
V_31 -> V_36 = NULL ;
V_57 += V_31 -> V_67 ;
V_58 += V_31 -> V_68 ;
F_22 ( V_31 -> V_32 ) ;
F_24 ( V_29 -> V_14 ,
F_25 ( V_31 , V_34 ) ,
F_23 ( V_31 , V_33 ) ,
V_35 ) ;
V_31 -> V_32 = NULL ;
F_27 ( V_31 , V_33 , 0 ) ;
while ( V_56 != V_63 ) {
V_31 ++ ;
V_56 ++ ;
V_60 ++ ;
if ( F_16 ( ! V_60 ) ) {
V_60 -= V_29 -> V_44 ;
V_31 = V_29 -> V_62 ;
V_56 = F_38 ( V_29 , 0 ) ;
}
if ( F_23 ( V_31 , V_33 ) ) {
F_26 ( V_29 -> V_14 ,
F_25 ( V_31 , V_34 ) ,
F_23 ( V_31 , V_33 ) ,
V_35 ) ;
F_27 ( V_31 , V_33 , 0 ) ;
}
}
V_31 ++ ;
V_56 ++ ;
V_60 ++ ;
if ( F_16 ( ! V_60 ) ) {
V_60 -= V_29 -> V_44 ;
V_31 = V_29 -> V_62 ;
V_56 = F_38 ( V_29 , 0 ) ;
}
F_41 ( V_56 ) ;
V_59 -- ;
} while ( F_42 ( V_59 ) );
V_60 += V_29 -> V_44 ;
V_29 -> V_61 = V_60 ;
F_43 ( & V_29 -> V_69 ) ;
V_29 -> V_38 . V_70 += V_57 ;
V_29 -> V_38 . V_39 += V_58 ;
F_44 ( & V_29 -> V_69 ) ;
V_54 -> V_71 . V_57 += V_57 ;
V_54 -> V_71 . V_58 += V_58 ;
if ( F_45 ( V_29 ) && F_33 ( V_29 ) ) {
struct V_9 * V_10 = & V_2 -> V_10 ;
union V_55 * V_63 ;
V_63 = V_29 -> V_62 [ V_60 ] . V_36 ;
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
V_29 -> V_72 ,
F_18 ( V_10 , F_31 ( V_29 -> V_42 ) ) ,
F_18 ( V_10 , F_32 ( V_29 -> V_42 ) ) ,
V_29 -> V_73 , V_60 ,
V_63 , ( V_63 ? V_63 -> V_64 . V_65 : 0 ) ,
V_29 -> V_62 [ V_60 ] . V_74 , V_75 ) ;
F_47 ( V_29 -> V_40 , V_29 -> V_72 ) ;
F_35 ( V_2 ) ;
return true ;
}
#define F_48 (DESC_NEEDED * 2)
if ( F_16 ( V_58 && F_49 ( V_29 -> V_40 ) &&
( F_50 ( V_29 ) >= F_48 ) ) ) {
F_51 () ;
if ( F_52 ( V_29 -> V_40 ,
V_29 -> V_72 ) &&
! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_53 ( V_29 -> V_40 ,
V_29 -> V_72 ) ;
++ V_29 -> V_47 . V_76 ;
}
}
return ! ! V_59 ;
}
static void F_54 ( struct V_53 * V_54 ,
struct V_77 * V_32 )
{
#ifdef F_55
F_56 ( V_32 , & V_54 -> V_78 ) ;
if ( F_57 ( V_54 ) ) {
F_58 ( V_32 ) ;
return;
}
#endif
F_59 ( & V_54 -> V_78 , V_32 ) ;
}
static inline void F_60 ( struct V_28 * V_37 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
T_6 V_81 ;
if ( ! ( V_37 -> V_40 -> V_82 & V_83 ) )
return;
V_81 = F_61 ( V_80 -> V_64 . V_84 . V_85 . V_86 . V_87 ) &
V_88 ;
if ( ! V_81 )
return;
F_62 ( V_32 , F_63 ( V_80 -> V_64 . V_84 . V_89 . V_90 ) ,
( V_91 & ( 1ul << V_81 ) ) ?
V_92 : V_93 ) ;
}
static inline void F_64 ( struct V_28 * V_37 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
F_65 ( V_32 ) ;
if ( ! ( V_37 -> V_40 -> V_82 & V_94 ) )
return;
if ( F_66 ( V_80 , V_95 ) &&
F_66 ( V_80 , V_96 ) ) {
V_37 -> V_97 . V_98 ++ ;
return;
}
if ( ! F_66 ( V_80 , V_99 ) )
return;
if ( F_66 ( V_80 , V_100 ) ) {
V_37 -> V_97 . V_98 ++ ;
return;
}
V_32 -> V_101 = V_102 ;
}
static void F_67 ( struct V_28 * V_103 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
F_60 ( V_103 , V_80 , V_32 ) ;
F_64 ( V_103 , V_80 , V_32 ) ;
if ( F_66 ( V_80 , V_104 ) ) {
T_6 V_105 = F_61 ( V_80 -> V_64 . V_106 . V_107 ) ;
unsigned long * V_108 = F_30 ( V_103 -> V_40 ) ;
if ( F_2 ( V_105 & V_109 , V_108 ) )
F_68 ( V_32 , F_69 ( V_110 ) , V_105 ) ;
}
V_32 -> V_111 = F_70 ( V_32 , V_103 -> V_40 ) ;
}
static bool F_71 ( struct V_28 * V_103 ,
union V_79 * V_80 )
{
T_1 V_112 = V_103 -> V_61 + 1 ;
V_112 = ( V_112 < V_103 -> V_44 ) ? V_112 : 0 ;
V_103 -> V_61 = V_112 ;
F_41 ( F_72 ( V_103 , V_112 ) ) ;
if ( F_42 ( F_66 ( V_80 , V_113 ) ) )
return false ;
return true ;
}
static bool F_73 ( struct V_28 * V_103 ,
struct V_114 * V_115 )
{
struct V_116 * V_116 = V_115 -> V_116 ;
T_7 V_34 = V_115 -> V_34 ;
if ( F_42 ( V_116 ) )
return true ;
V_116 = F_74 () ;
if ( F_16 ( ! V_116 ) ) {
V_103 -> V_97 . V_117 ++ ;
return false ;
}
V_34 = F_75 ( V_103 -> V_14 , V_116 , 0 ,
V_118 , V_119 ) ;
if ( F_76 ( V_103 -> V_14 , V_34 ) ) {
F_77 ( V_116 ) ;
V_103 -> V_97 . V_120 ++ ;
return false ;
}
V_115 -> V_34 = V_34 ;
V_115 -> V_116 = V_116 ;
V_115 -> V_121 = 0 ;
return true ;
}
static void F_78 ( struct V_28 * V_103 ,
T_6 V_122 )
{
union V_79 * V_80 ;
struct V_114 * V_115 ;
unsigned int V_60 = V_103 -> V_73 ;
if ( ! V_122 || ! V_103 -> V_40 )
return;
V_80 = F_72 ( V_103 , V_60 ) ;
V_115 = & V_103 -> V_123 [ V_60 ] ;
V_60 -= V_103 -> V_44 ;
do {
if ( ! F_73 ( V_103 , V_115 ) )
break;
V_80 -> V_124 . V_125 = F_79 ( V_115 -> V_34 + V_115 -> V_121 ) ;
V_80 ++ ;
V_115 ++ ;
V_60 ++ ;
if ( F_16 ( ! V_60 ) ) {
V_80 = F_72 ( V_103 , 0 ) ;
V_115 = V_103 -> V_123 ;
V_60 -= V_103 -> V_44 ;
}
V_80 -> V_124 . V_126 = 0 ;
V_122 -- ;
} while ( V_122 );
V_60 += V_103 -> V_44 ;
if ( V_103 -> V_73 != V_60 ) {
V_103 -> V_73 = V_60 ;
V_103 -> V_127 = V_60 ;
F_80 () ;
F_81 ( V_103 , V_60 ) ;
}
}
static bool F_82 ( struct V_28 * V_103 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
if ( F_16 ( F_66 ( V_80 ,
V_128 ) ) ) {
struct V_52 * V_40 = V_103 -> V_40 ;
if ( ! ( V_40 -> V_82 & V_129 ) ) {
F_22 ( V_32 ) ;
return true ;
}
}
if ( F_83 ( V_32 ) )
return true ;
return false ;
}
static void F_84 ( struct V_28 * V_103 ,
struct V_114 * V_130 )
{
struct V_114 * V_131 ;
T_6 V_132 = V_103 -> V_127 ;
V_131 = & V_103 -> V_123 [ V_132 ] ;
V_132 ++ ;
V_103 -> V_127 = ( V_132 < V_103 -> V_44 ) ? V_132 : 0 ;
V_131 -> V_116 = V_130 -> V_116 ;
V_131 -> V_34 = V_130 -> V_34 ;
V_131 -> V_121 = V_130 -> V_121 ;
F_85 ( V_103 -> V_14 , V_131 -> V_34 ,
V_131 -> V_121 ,
V_133 ,
V_119 ) ;
}
static inline bool F_86 ( struct V_116 * V_116 )
{
return ( F_87 ( V_116 ) != F_88 () ) || F_89 ( V_116 ) ;
}
static bool F_90 ( struct V_28 * V_103 ,
struct V_114 * V_134 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
struct V_116 * V_116 = V_134 -> V_116 ;
unsigned char * V_135 = F_91 ( V_116 ) + V_134 -> V_121 ;
unsigned int V_136 = F_61 ( V_80 -> V_64 . V_106 . V_137 ) ;
#if ( V_118 < 8192 )
unsigned int V_138 = V_133 ;
#else
unsigned int V_138 = F_92 ( V_136 , V_139 ) ;
#endif
unsigned int V_140 ;
if ( F_16 ( F_93 ( V_32 ) ) )
goto V_141;
if ( F_42 ( V_136 <= V_142 ) ) {
memcpy ( F_94 ( V_32 , V_136 ) , V_135 , F_92 ( V_136 , sizeof( long ) ) ) ;
if ( F_42 ( ! F_86 ( V_116 ) ) )
return true ;
F_95 ( V_116 ) ;
return false ;
}
V_140 = F_96 ( V_135 , V_142 ) ;
memcpy ( F_94 ( V_32 , V_140 ) , V_135 , F_92 ( V_140 , sizeof( long ) ) ) ;
V_135 += V_140 ;
V_136 -= V_140 ;
V_141:
F_97 ( V_32 , F_98 ( V_32 ) -> V_143 , V_116 ,
( unsigned long ) V_135 & ~ V_144 , V_136 , V_138 ) ;
if ( F_16 ( F_86 ( V_116 ) ) )
return false ;
#if ( V_118 < 8192 )
if ( F_16 ( F_99 ( V_116 ) != 1 ) )
return false ;
V_134 -> V_121 ^= V_133 ;
#else
V_134 -> V_121 += V_138 ;
if ( V_134 -> V_121 > ( V_118 - V_133 ) )
return false ;
#endif
F_100 ( & V_116 -> V_145 ) ;
return true ;
}
static struct V_77 * F_101 ( struct V_28 * V_103 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
struct V_114 * V_134 ;
struct V_116 * V_116 ;
V_134 = & V_103 -> V_123 [ V_103 -> V_61 ] ;
V_116 = V_134 -> V_116 ;
F_102 ( V_116 ) ;
if ( F_42 ( ! V_32 ) ) {
void * V_146 = F_91 ( V_116 ) +
V_134 -> V_121 ;
F_41 ( V_146 ) ;
#if V_139 < 128
F_41 ( V_146 + V_139 ) ;
#endif
V_32 = F_103 ( V_103 -> V_40 ,
V_142 ) ;
if ( F_16 ( ! V_32 ) ) {
V_103 -> V_97 . V_120 ++ ;
return NULL ;
}
F_102 ( V_32 -> V_147 ) ;
}
F_104 ( V_103 -> V_14 ,
V_134 -> V_34 ,
V_134 -> V_121 ,
V_133 ,
V_119 ) ;
if ( F_90 ( V_103 , V_134 , V_80 , V_32 ) ) {
F_84 ( V_103 , V_134 ) ;
} else {
F_26 ( V_103 -> V_14 , V_134 -> V_34 ,
V_118 , V_119 ) ;
}
V_134 -> V_34 = 0 ;
V_134 -> V_116 = NULL ;
return V_32 ;
}
static inline void F_105 ( struct V_1 * V_2 ,
T_1 V_148 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_19 ( V_10 , V_149 , V_148 ) ;
}
static int F_106 ( struct V_53 * V_54 ,
struct V_28 * V_103 ,
int V_59 )
{
unsigned int V_150 = 0 , V_151 = 0 ;
T_6 V_122 = F_50 ( V_103 ) ;
struct V_77 * V_32 = V_103 -> V_32 ;
while ( F_42 ( V_151 < V_59 ) ) {
union V_79 * V_80 ;
if ( V_122 >= V_152 ) {
F_78 ( V_103 , V_122 ) ;
V_122 = 0 ;
}
V_80 = F_72 ( V_103 , V_103 -> V_61 ) ;
if ( ! F_66 ( V_80 , V_153 ) )
break;
F_107 () ;
V_32 = F_101 ( V_103 , V_80 , V_32 ) ;
if ( ! V_32 )
break;
V_122 ++ ;
if ( F_71 ( V_103 , V_80 ) )
continue;
if ( F_82 ( V_103 , V_80 , V_32 ) ) {
V_32 = NULL ;
continue;
}
V_150 += V_32 -> V_33 ;
if ( ( V_32 -> V_154 == V_155 ||
V_32 -> V_154 == V_156 ) &&
F_108 ( V_103 -> V_40 -> V_157 ,
F_109 ( V_32 ) -> V_158 ) ) {
F_110 ( V_32 ) ;
continue;
}
F_67 ( V_103 , V_80 , V_32 ) ;
F_54 ( V_54 , V_32 ) ;
V_32 = NULL ;
V_151 ++ ;
}
V_103 -> V_32 = V_32 ;
F_43 ( & V_103 -> V_69 ) ;
V_103 -> V_38 . V_39 += V_151 ;
V_103 -> V_38 . V_70 += V_150 ;
F_44 ( & V_103 -> V_69 ) ;
V_54 -> V_159 . V_58 += V_151 ;
V_54 -> V_159 . V_57 += V_150 ;
return V_151 ;
}
static int F_111 ( struct V_160 * V_78 , int V_59 )
{
struct V_53 * V_54 =
F_112 ( V_78 , struct V_53 , V_78 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_28 * V_37 ;
int V_161 , V_162 = 0 ;
bool V_163 = true ;
F_113 (ring, q_vector->tx)
V_163 &= F_37 ( V_54 , V_37 ) ;
if ( V_59 <= 0 )
return V_59 ;
#ifdef F_55
if ( ! F_114 ( V_54 ) )
return V_59 ;
#endif
if ( V_54 -> V_159 . V_44 > 1 )
V_161 = F_115 ( V_59 / V_54 -> V_159 . V_44 , 1 ) ;
else
V_161 = V_59 ;
F_113 (ring, q_vector->rx) {
int V_164 = F_106 ( V_54 , V_37 ,
V_161 ) ;
V_162 += V_164 ;
V_163 &= ( V_164 < V_161 ) ;
}
#ifdef F_55
F_116 ( V_54 ) ;
#endif
if ( ! V_163 )
return V_59 ;
F_117 ( V_78 , V_162 ) ;
if ( V_2 -> V_165 == 1 )
F_118 ( V_54 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) )
F_105 ( V_2 ,
1 << V_54 -> V_166 ) ;
return 0 ;
}
void F_119 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_166 = V_54 -> V_166 ;
T_1 V_167 = V_54 -> V_168 & V_169 ;
V_167 |= V_170 ;
F_19 ( V_10 , F_120 ( V_166 ) , V_167 ) ;
}
static int F_121 ( struct V_160 * V_78 )
{
struct V_53 * V_54 =
F_112 ( V_78 , struct V_53 , V_78 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_28 * V_37 ;
int V_171 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return V_172 ;
if ( ! F_122 ( V_54 ) )
return V_173 ;
F_113 (ring, q_vector->rx) {
V_171 = F_106 ( V_54 , V_37 , 4 ) ;
#ifdef F_123
if ( V_171 )
V_37 -> V_38 . V_164 += V_171 ;
else
V_37 -> V_38 . V_174 ++ ;
#endif
if ( V_171 )
break;
}
F_124 ( V_54 ) ;
return V_171 ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
int V_175 , V_166 ;
V_175 = V_2 -> V_176 - V_177 ;
V_2 -> V_178 = 0 ;
for ( V_166 = 0 ; V_166 < V_175 ; V_166 ++ ) {
struct V_28 * V_37 ;
V_54 = V_2 -> V_54 [ V_166 ] ;
F_113 (ring, q_vector->rx)
F_17 ( V_2 , 0 , V_37 -> V_42 , V_166 ) ;
F_113 (ring, q_vector->tx)
F_17 ( V_2 , 1 , V_37 -> V_42 , V_166 ) ;
if ( V_54 -> V_71 . V_37 && ! V_54 -> V_159 . V_37 ) {
if ( V_2 -> V_179 == 1 )
V_54 -> V_168 = V_180 ;
else
V_54 -> V_168 = V_2 -> V_179 ;
} else {
if ( V_2 -> V_165 == 1 )
V_54 -> V_168 = V_181 ;
else
V_54 -> V_168 = V_2 -> V_165 ;
}
V_2 -> V_178 |= 1 << V_166 ;
F_119 ( V_54 ) ;
}
F_17 ( V_2 , - 1 , 1 , V_166 ) ;
V_2 -> V_182 = 1 << V_166 ;
V_2 -> V_178 |= V_2 -> V_182 ;
}
static void F_126 ( struct V_53 * V_54 ,
struct V_183 * V_184 )
{
int V_70 = V_184 -> V_57 ;
int V_39 = V_184 -> V_58 ;
T_1 V_185 ;
T_5 V_186 ;
T_2 V_187 = V_184 -> V_168 ;
if ( V_39 == 0 )
return;
V_185 = V_54 -> V_168 >> 2 ;
V_186 = V_70 / V_185 ;
switch ( V_187 ) {
case V_188 :
if ( V_186 > 10 )
V_187 = V_189 ;
break;
case V_189 :
if ( V_186 > 20 )
V_187 = V_190 ;
else if ( V_186 <= 10 )
V_187 = V_188 ;
break;
case V_190 :
if ( V_186 <= 20 )
V_187 = V_189 ;
break;
}
V_184 -> V_57 = 0 ;
V_184 -> V_58 = 0 ;
V_184 -> V_168 = V_187 ;
}
static void F_118 ( struct V_53 * V_54 )
{
T_1 V_191 = V_54 -> V_168 ;
T_2 V_192 ;
F_126 ( V_54 , & V_54 -> V_71 ) ;
F_126 ( V_54 , & V_54 -> V_159 ) ;
V_192 = F_115 ( V_54 -> V_159 . V_168 , V_54 -> V_71 . V_168 ) ;
switch ( V_192 ) {
case V_188 :
V_191 = V_193 ;
break;
case V_189 :
V_191 = V_181 ;
break;
case V_190 :
V_191 = V_180 ;
break;
default:
break;
}
if ( V_191 != V_54 -> V_168 ) {
V_191 = ( 10 * V_191 * V_54 -> V_168 ) /
( ( 9 * V_191 ) + V_54 -> V_168 ) ;
V_54 -> V_168 = V_191 ;
F_119 ( V_54 ) ;
}
}
static T_8 F_127 ( int V_194 , void * V_147 )
{
struct V_1 * V_2 = V_147 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
V_10 -> V_195 . V_196 = 1 ;
F_1 ( V_2 ) ;
F_19 ( V_10 , V_149 , V_2 -> V_182 ) ;
return V_197 ;
}
static T_8 F_128 ( int V_194 , void * V_147 )
{
struct V_53 * V_54 = V_147 ;
if ( V_54 -> V_159 . V_37 || V_54 -> V_71 . V_37 )
F_129 ( & V_54 -> V_78 ) ;
return V_197 ;
}
static inline void F_130 ( struct V_1 * V_198 , int V_166 ,
int V_199 )
{
struct V_53 * V_54 = V_198 -> V_54 [ V_166 ] ;
V_198 -> V_103 [ V_199 ] -> V_200 = V_54 -> V_159 . V_37 ;
V_54 -> V_159 . V_37 = V_198 -> V_103 [ V_199 ] ;
V_54 -> V_159 . V_44 ++ ;
}
static inline void F_131 ( struct V_1 * V_198 , int V_166 ,
int V_201 )
{
struct V_53 * V_54 = V_198 -> V_54 [ V_166 ] ;
V_198 -> V_29 [ V_201 ] -> V_200 = V_54 -> V_71 . V_37 ;
V_54 -> V_71 . V_37 = V_198 -> V_29 [ V_201 ] ;
V_54 -> V_71 . V_44 ++ ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_175 ;
int V_202 = 0 ;
int V_203 = 0 , V_204 = 0 ;
int V_205 = V_2 -> V_206 ;
int V_207 = V_2 -> V_208 ;
int V_60 , V_209 ;
int V_210 , V_211 ;
V_175 = V_2 -> V_176 - V_177 ;
if ( V_175 == V_2 -> V_206 + V_2 -> V_208 ) {
for (; V_203 < V_205 ; V_202 ++ , V_203 ++ )
F_130 ( V_2 , V_202 , V_203 ) ;
for (; V_204 < V_207 ; V_202 ++ , V_204 ++ )
F_131 ( V_2 , V_202 , V_204 ) ;
return 0 ;
}
for ( V_60 = V_202 ; V_60 < V_175 ; V_60 ++ ) {
V_210 = F_133 ( V_205 , V_175 - V_60 ) ;
for ( V_209 = 0 ; V_209 < V_210 ; V_209 ++ ) {
F_130 ( V_2 , V_60 , V_203 ) ;
V_203 ++ ;
V_205 -- ;
}
}
for ( V_60 = V_202 ; V_60 < V_175 ; V_60 ++ ) {
V_211 = F_133 ( V_207 , V_175 - V_60 ) ;
for ( V_209 = 0 ; V_209 < V_211 ; V_209 ++ ) {
F_131 ( V_2 , V_60 , V_204 ) ;
V_204 ++ ;
V_207 -- ;
}
}
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
int V_175 = V_2 -> V_176 - V_177 ;
int V_212 , V_213 ;
int V_214 = 0 , V_215 = 0 ;
for ( V_212 = 0 ; V_212 < V_175 ; V_212 ++ ) {
struct V_53 * V_54 = V_2 -> V_54 [ V_212 ] ;
struct V_216 * V_217 = & V_2 -> V_218 [ V_212 ] ;
if ( V_54 -> V_71 . V_37 && V_54 -> V_159 . V_37 ) {
snprintf ( V_54 -> V_219 , sizeof( V_54 -> V_219 ) - 1 ,
L_12 , V_40 -> V_219 , L_13 , V_214 ++ ) ;
V_215 ++ ;
} else if ( V_54 -> V_159 . V_37 ) {
snprintf ( V_54 -> V_219 , sizeof( V_54 -> V_219 ) - 1 ,
L_12 , V_40 -> V_219 , L_14 , V_214 ++ ) ;
} else if ( V_54 -> V_71 . V_37 ) {
snprintf ( V_54 -> V_219 , sizeof( V_54 -> V_219 ) - 1 ,
L_12 , V_40 -> V_219 , L_15 , V_215 ++ ) ;
} else {
continue;
}
V_213 = F_135 ( V_217 -> V_212 , & F_128 , 0 ,
V_54 -> V_219 , V_54 ) ;
if ( V_213 ) {
F_136 ( & V_2 -> V_10 ,
L_16 ,
V_213 ) ;
goto V_220;
}
}
V_213 = F_135 ( V_2 -> V_218 [ V_212 ] . V_212 ,
& F_127 , 0 , V_40 -> V_219 , V_2 ) ;
if ( V_213 ) {
F_136 ( & V_2 -> V_10 , L_17 ,
V_213 ) ;
goto V_220;
}
return 0 ;
V_220:
while ( V_212 ) {
V_212 -- ;
F_137 ( V_2 -> V_218 [ V_212 ] . V_212 ,
V_2 -> V_54 [ V_212 ] ) ;
}
V_2 -> V_176 = 0 ;
return V_213 ;
}
static inline void F_138 ( struct V_1 * V_2 )
{
int V_60 , V_175 = V_2 -> V_176 - V_177 ;
for ( V_60 = 0 ; V_60 < V_175 ; V_60 ++ ) {
struct V_53 * V_54 = V_2 -> V_54 [ V_60 ] ;
V_54 -> V_159 . V_37 = NULL ;
V_54 -> V_71 . V_37 = NULL ;
V_54 -> V_159 . V_44 = 0 ;
V_54 -> V_71 . V_44 = 0 ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
int V_213 = F_134 ( V_2 ) ;
if ( V_213 )
F_136 ( & V_2 -> V_10 , L_18 , V_213 ) ;
return V_213 ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_60 , V_175 ;
V_175 = V_2 -> V_176 ;
V_60 = V_175 - 1 ;
F_137 ( V_2 -> V_218 [ V_60 ] . V_212 , V_2 ) ;
V_60 -- ;
for (; V_60 >= 0 ; V_60 -- ) {
if ( ! V_2 -> V_54 [ V_60 ] -> V_159 . V_37 &&
! V_2 -> V_54 [ V_60 ] -> V_71 . V_37 )
continue;
F_137 ( V_2 -> V_218 [ V_60 ] . V_212 ,
V_2 -> V_54 [ V_60 ] ) ;
}
F_138 ( V_2 ) ;
}
static inline void F_141 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
F_19 ( V_10 , V_221 , 0 ) ;
F_19 ( V_10 , V_222 , ~ 0 ) ;
F_19 ( V_10 , V_223 , 0 ) ;
F_142 ( V_10 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_176 ; V_60 ++ )
F_143 ( V_2 -> V_218 [ V_60 ] . V_212 ) ;
}
static inline void F_144 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_19 ( V_10 , V_221 , V_2 -> V_178 ) ;
F_19 ( V_10 , V_223 , V_2 -> V_178 ) ;
F_19 ( V_10 , V_149 , V_2 -> V_178 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_5 V_224 = V_37 -> V_34 ;
int V_225 = 10 ;
T_1 V_226 = V_227 ;
T_2 V_42 = V_37 -> V_42 ;
F_19 ( V_10 , F_146 ( V_42 ) , V_228 ) ;
F_142 ( V_10 ) ;
F_19 ( V_10 , F_147 ( V_42 ) , V_224 & F_148 ( 32 ) ) ;
F_19 ( V_10 , F_149 ( V_42 ) , V_224 >> 32 ) ;
F_19 ( V_10 , F_150 ( V_42 ) ,
V_37 -> V_44 * sizeof( union V_55 ) ) ;
F_19 ( V_10 , F_151 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_152 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_153 ( V_42 ) ,
( V_229 |
V_230 ) ) ;
F_19 ( V_10 , F_31 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_32 ( V_42 ) , 0 ) ;
V_37 -> V_43 = V_2 -> V_231 + F_32 ( V_42 ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_73 = 0 ;
V_226 |= ( 8 << 16 ) ;
V_226 |= ( 1 << 8 ) |
32 ;
F_8 ( V_49 , & V_37 -> V_4 ) ;
F_19 ( V_10 , F_146 ( V_42 ) , V_226 ) ;
do {
F_154 ( 1000 , 2000 ) ;
V_226 = F_18 ( V_10 , F_146 ( V_42 ) ) ;
} while ( -- V_225 && ! ( V_226 & V_227 ) );
if ( ! V_225 )
F_46 ( L_19 , V_42 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_1 V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ )
F_145 ( V_2 , V_2 -> V_29 [ V_60 ] ) ;
}
static void F_156 ( struct V_1 * V_2 , int V_25 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_232 ;
V_232 = V_233 ;
V_232 |= V_142 << V_234 ;
V_232 |= V_133 >> V_235 ;
V_232 |= V_236 ;
F_19 ( V_10 , F_157 ( V_25 ) , V_232 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_237 = V_238 | V_239 |
V_240 | V_241 |
V_242 ;
if ( V_2 -> V_206 > 1 )
V_237 |= 1 << 29 ;
F_19 ( V_10 , V_243 , V_237 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_225 = V_244 ;
T_1 V_245 ;
T_2 V_42 = V_37 -> V_42 ;
if ( F_14 ( V_10 -> V_12 ) )
return;
V_245 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
V_245 &= ~ V_246 ;
F_19 ( V_10 , F_160 ( V_42 ) , V_245 ) ;
do {
F_161 ( 10 ) ;
V_245 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
} while ( -- V_225 && ( V_245 & V_246 ) );
if ( ! V_225 )
F_46 ( L_20 ,
V_42 ) ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_225 = V_244 ;
T_1 V_245 ;
T_2 V_42 = V_37 -> V_42 ;
if ( F_14 ( V_10 -> V_12 ) )
return;
do {
F_154 ( 1000 , 2000 ) ;
V_245 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
} while ( -- V_225 && ! ( V_245 & V_246 ) );
if ( ! V_225 )
F_46 ( L_21 ,
V_42 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_247 = 0 , V_248 = 0 ;
T_6 V_249 = V_2 -> V_206 ;
T_2 V_60 , V_209 ;
F_164 ( V_2 -> V_250 , sizeof( V_2 -> V_250 ) ) ;
for ( V_60 = 0 ; V_60 < V_251 ; V_60 ++ )
F_19 ( V_10 , F_165 ( V_60 ) , V_2 -> V_250 [ V_60 ] ) ;
for ( V_60 = 0 , V_209 = 0 ; V_60 < V_252 ; V_60 ++ , V_209 ++ ) {
if ( V_209 == V_249 )
V_209 = 0 ;
V_2 -> V_253 [ V_60 ] = V_209 ;
V_248 |= V_209 << ( V_60 & 0x3 ) * 8 ;
if ( ( V_60 & 3 ) == 3 ) {
F_19 ( V_10 , F_166 ( V_60 >> 2 ) , V_248 ) ;
V_248 = 0 ;
}
}
V_247 |= V_254 |
V_255 |
V_256 |
V_257 ;
V_247 |= V_258 ;
F_19 ( V_10 , V_259 , V_247 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_5 V_260 = V_37 -> V_34 ;
T_1 V_245 ;
T_2 V_42 = V_37 -> V_42 ;
V_245 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
F_159 ( V_2 , V_37 ) ;
F_19 ( V_10 , F_168 ( V_42 ) , V_260 & F_148 ( 32 ) ) ;
F_19 ( V_10 , F_169 ( V_42 ) , V_260 >> 32 ) ;
F_19 ( V_10 , F_170 ( V_42 ) ,
V_37 -> V_44 * sizeof( union V_79 ) ) ;
F_19 ( V_10 , F_171 ( V_42 ) ,
V_261 ) ;
F_19 ( V_10 , F_172 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_173 ( V_42 ) , 0 ) ;
V_37 -> V_43 = V_2 -> V_231 + F_173 ( V_42 ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_73 = 0 ;
V_37 -> V_127 = 0 ;
F_156 ( V_2 , V_42 ) ;
V_245 &= ~ V_262 ;
V_245 |= V_246 | V_263 ;
F_19 ( V_10 , F_160 ( V_42 ) , V_245 ) ;
F_162 ( V_2 , V_37 ) ;
F_78 ( V_37 , F_50 ( V_37 ) ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_60 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_52 * V_40 = V_2 -> V_40 ;
F_158 ( V_2 ) ;
if ( V_10 -> V_195 . type >= V_264 )
F_163 ( V_2 ) ;
F_175 ( V_10 , V_40 -> V_265 + V_266 + V_267 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ )
F_167 ( V_2 , V_2 -> V_103 [ V_60 ] ) ;
}
static int F_176 ( struct V_52 * V_40 ,
T_9 V_268 , T_6 V_105 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_213 ;
F_177 ( & V_2 -> V_269 ) ;
V_213 = V_10 -> V_195 . V_270 . V_271 ( V_10 , V_105 , 0 , true ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_213 == V_272 )
return - V_273 ;
if ( V_213 == V_274 )
return - V_275 ;
F_179 ( V_105 , V_2 -> V_108 ) ;
return V_213 ;
}
static int F_180 ( struct V_52 * V_40 ,
T_9 V_268 , T_6 V_105 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_213 ;
F_177 ( & V_2 -> V_269 ) ;
V_213 = V_10 -> V_195 . V_270 . V_271 ( V_10 , V_105 , 0 , false ) ;
F_178 ( & V_2 -> V_269 ) ;
F_8 ( V_105 , V_2 -> V_108 ) ;
return V_213 ;
}
static void F_181 ( struct V_1 * V_2 )
{
T_6 V_105 ;
F_182 (vid, adapter->active_vlans, VLAN_N_VID)
F_176 ( V_2 -> V_40 ,
F_69 ( V_110 ) , V_105 ) ;
}
static int F_183 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_44 = 0 ;
if ( ( F_184 ( V_40 ) ) > 10 ) {
F_46 ( L_22 ) ;
return - V_276 ;
}
if ( ! F_185 ( V_40 ) ) {
struct V_277 * V_278 ;
F_186 (ha, netdev) {
V_10 -> V_195 . V_270 . V_279 ( V_10 , ++ V_44 , V_278 -> V_280 ) ;
F_161 ( 200 ) ;
}
} else {
V_10 -> V_195 . V_270 . V_279 ( V_10 , 0 , NULL ) ;
}
return V_44 ;
}
static void F_187 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_50 = V_40 -> V_50 ;
int V_281 ;
V_281 = ( V_50 & V_282 ) ? V_283 :
( V_50 & ( V_284 | V_285 ) ) ?
V_286 : V_287 ;
F_177 ( & V_2 -> V_269 ) ;
V_10 -> V_195 . V_270 . V_288 ( V_10 , V_40 , V_281 ) ;
V_10 -> V_195 . V_270 . V_289 ( V_10 , V_40 ) ;
F_183 ( V_40 ) ;
F_178 ( & V_2 -> V_269 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
int V_290 ;
struct V_53 * V_54 ;
int V_175 = V_2 -> V_176 - V_177 ;
for ( V_290 = 0 ; V_290 < V_175 ; V_290 ++ ) {
V_54 = V_2 -> V_54 [ V_290 ] ;
#ifdef F_55
F_189 ( V_2 -> V_54 [ V_290 ] ) ;
#endif
F_190 ( & V_54 -> V_78 ) ;
}
}
static void F_191 ( struct V_1 * V_2 )
{
int V_290 ;
struct V_53 * V_54 ;
int V_175 = V_2 -> V_176 - V_177 ;
for ( V_290 = 0 ; V_290 < V_175 ; V_290 ++ ) {
V_54 = V_2 -> V_54 [ V_290 ] ;
F_192 ( & V_54 -> V_78 ) ;
#ifdef F_55
while ( ! F_193 ( V_2 -> V_54 [ V_290 ] ) ) {
F_194 ( L_23 , V_290 ) ;
F_154 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_291 = 0 ;
unsigned int V_292 = 0 ;
unsigned int V_206 = V_2 -> V_206 ;
unsigned int V_208 = V_2 -> V_208 ;
int V_213 ;
F_177 ( & V_2 -> V_269 ) ;
V_213 = F_196 ( V_10 , & V_292 , & V_291 ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_213 )
return V_213 ;
if ( V_292 > 1 ) {
V_208 = 1 ;
V_2 -> V_29 [ 0 ] -> V_42 = V_291 ;
V_206 = V_292 ;
}
if ( ( V_2 -> V_206 != V_206 ) ||
( V_2 -> V_208 != V_208 ) ) {
V_10 -> V_293 . V_294 = 0 ;
V_2 -> V_50 |= V_295 ;
}
return 0 ;
}
static void F_197 ( struct V_1 * V_2 )
{
F_195 ( V_2 ) ;
F_187 ( V_2 -> V_40 ) ;
F_181 ( V_2 ) ;
F_155 ( V_2 ) ;
F_174 ( V_2 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 . V_296 || V_2 -> V_38 . V_297 ) {
V_2 -> V_38 . V_298 += V_2 -> V_38 . V_296 -
V_2 -> V_38 . V_299 ;
V_2 -> V_38 . V_300 += V_2 -> V_38 . V_297 -
V_2 -> V_38 . V_301 ;
V_2 -> V_38 . V_302 += V_2 -> V_38 . V_303 -
V_2 -> V_38 . V_304 ;
V_2 -> V_38 . V_305 += V_2 -> V_38 . V_306 -
V_2 -> V_38 . V_307 ;
V_2 -> V_38 . V_308 += V_2 -> V_38 . V_309 -
V_2 -> V_38 . V_310 ;
}
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
V_2 -> V_38 . V_311 = F_18 ( V_10 , V_312 ) ;
V_2 -> V_38 . V_313 = F_18 ( V_10 , V_314 ) ;
V_2 -> V_38 . V_313 |=
( ( ( T_5 ) ( F_18 ( V_10 , V_315 ) ) ) << 32 ) ;
V_2 -> V_38 . V_316 = F_18 ( V_10 , V_317 ) ;
V_2 -> V_38 . V_318 = F_18 ( V_10 , V_319 ) ;
V_2 -> V_38 . V_318 |=
( ( ( T_5 ) ( F_18 ( V_10 , V_320 ) ) ) << 32 ) ;
V_2 -> V_38 . V_321 = F_18 ( V_10 , V_322 ) ;
V_2 -> V_38 . V_299 = V_2 -> V_38 . V_311 ;
V_2 -> V_38 . V_304 = V_2 -> V_38 . V_313 ;
V_2 -> V_38 . V_301 = V_2 -> V_38 . V_316 ;
V_2 -> V_38 . V_307 = V_2 -> V_38 . V_318 ;
V_2 -> V_38 . V_310 = V_2 -> V_38 . V_321 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_323 [] = { V_324 ,
V_325 ,
V_326 ,
V_327 } ;
int V_213 , V_328 = 0 ;
F_177 ( & V_2 -> V_269 ) ;
while ( V_323 [ V_328 ] != V_327 ) {
V_213 = F_201 ( V_10 , V_323 [ V_328 ] ) ;
if ( ! V_213 )
break;
V_328 ++ ;
}
F_178 ( & V_2 -> V_269 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
F_125 ( V_2 ) ;
F_177 ( & V_2 -> V_269 ) ;
if ( F_203 ( V_10 -> V_195 . V_280 ) )
V_10 -> V_195 . V_270 . V_329 ( V_10 , 0 , V_10 -> V_195 . V_280 , 0 ) ;
else
V_10 -> V_195 . V_270 . V_329 ( V_10 , 0 , V_10 -> V_195 . V_330 , 0 ) ;
F_178 ( & V_2 -> V_269 ) ;
F_7 () ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_188 ( V_2 ) ;
F_18 ( V_10 , V_331 ) ;
F_144 ( V_2 ) ;
F_204 ( V_40 ) ;
F_198 ( V_2 ) ;
F_199 ( V_2 ) ;
V_10 -> V_195 . V_196 = 1 ;
F_205 ( & V_2 -> V_332 , V_75 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
F_197 ( V_2 ) ;
F_202 ( V_2 ) ;
}
static void F_207 ( struct V_28 * V_103 )
{
struct V_333 * V_14 = V_103 -> V_14 ;
unsigned long V_136 ;
unsigned int V_60 ;
if ( V_103 -> V_32 ) {
F_208 ( V_103 -> V_32 ) ;
V_103 -> V_32 = NULL ;
}
if ( ! V_103 -> V_123 )
return;
for ( V_60 = 0 ; V_60 < V_103 -> V_44 ; V_60 ++ ) {
struct V_114 * V_134 ;
V_134 = & V_103 -> V_123 [ V_60 ] ;
if ( V_134 -> V_34 )
F_26 ( V_14 , V_134 -> V_34 ,
V_118 , V_119 ) ;
V_134 -> V_34 = 0 ;
if ( V_134 -> V_116 )
F_77 ( V_134 -> V_116 ) ;
V_134 -> V_116 = NULL ;
}
V_136 = sizeof( struct V_114 ) * V_103 -> V_44 ;
memset ( V_103 -> V_123 , 0 , V_136 ) ;
memset ( V_103 -> V_334 , 0 , V_103 -> V_136 ) ;
}
static void F_209 ( struct V_28 * V_29 )
{
struct V_30 * V_62 ;
unsigned long V_136 ;
unsigned int V_60 ;
if ( ! V_29 -> V_62 )
return;
for ( V_60 = 0 ; V_60 < V_29 -> V_44 ; V_60 ++ ) {
V_62 = & V_29 -> V_62 [ V_60 ] ;
F_21 ( V_29 , V_62 ) ;
}
V_136 = sizeof( struct V_30 ) * V_29 -> V_44 ;
memset ( V_29 -> V_62 , 0 , V_136 ) ;
memset ( V_29 -> V_334 , 0 , V_29 -> V_136 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ )
F_207 ( V_2 -> V_103 [ V_60 ] ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ )
F_209 ( V_2 -> V_29 [ V_60 ] ) ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ )
F_159 ( V_2 , V_2 -> V_103 [ V_60 ] ) ;
F_154 ( 10000 , 20000 ) ;
F_213 ( V_40 ) ;
F_214 ( V_40 ) ;
F_215 ( V_40 ) ;
F_141 ( V_2 ) ;
F_191 ( V_2 ) ;
F_216 ( & V_2 -> V_332 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ ) {
T_2 V_42 = V_2 -> V_29 [ V_60 ] -> V_42 ;
F_19 ( V_10 , F_146 ( V_42 ) ,
V_228 ) ;
}
if ( ! F_217 ( V_2 -> V_13 ) )
F_218 ( V_2 ) ;
F_211 ( V_2 ) ;
F_210 ( V_2 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
F_220 ( F_221 () ) ;
while ( F_3 ( V_335 , & V_2 -> V_4 ) )
F_222 ( 1 ) ;
F_212 ( V_2 ) ;
F_206 ( V_2 ) ;
F_8 ( V_335 , & V_2 -> V_4 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_52 * V_40 = V_2 -> V_40 ;
if ( V_10 -> V_195 . V_270 . V_336 ( V_10 ) ) {
F_136 ( V_10 , L_24 ) ;
} else {
V_10 -> V_195 . V_270 . V_337 ( V_10 ) ;
F_200 ( V_2 ) ;
}
if ( F_203 ( V_2 -> V_10 . V_195 . V_280 ) ) {
F_223 ( V_40 -> V_157 , V_2 -> V_10 . V_195 . V_280 ) ;
F_223 ( V_40 -> V_330 , V_2 -> V_10 . V_195 . V_280 ) ;
}
V_2 -> V_338 = V_75 ;
}
static int F_224 ( struct V_1 * V_2 ,
int V_339 )
{
int V_340 ;
V_340 = V_341 ;
V_339 = F_225 ( V_2 -> V_13 , V_2 -> V_218 ,
V_340 , V_339 ) ;
if ( V_339 < 0 ) {
F_10 ( & V_2 -> V_13 -> V_14 ,
L_25 ) ;
F_226 ( V_2 -> V_218 ) ;
V_2 -> V_218 = NULL ;
return V_339 ;
}
V_2 -> V_176 = V_339 ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_291 = 0 ;
unsigned int V_292 = 0 ;
int V_213 ;
V_2 -> V_206 = 1 ;
V_2 -> V_208 = 1 ;
F_177 ( & V_2 -> V_269 ) ;
V_213 = F_196 ( V_10 , & V_292 , & V_291 ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_213 )
return;
if ( V_292 > 1 ) {
V_2 -> V_206 = V_292 ;
} else {
T_6 V_90 = F_228 ( T_6 , F_229 () , V_342 ) ;
switch ( V_10 -> V_343 ) {
case V_325 :
case V_324 :
V_2 -> V_206 = V_90 ;
V_2 -> V_208 = V_90 ;
default:
break;
}
}
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_28 * V_37 ;
int V_159 = 0 , V_71 = 0 ;
for (; V_71 < V_2 -> V_208 ; V_71 ++ ) {
V_37 = F_231 ( sizeof( * V_37 ) , V_344 ) ;
if ( ! V_37 )
goto V_345;
V_37 -> V_14 = & V_2 -> V_13 -> V_14 ;
V_37 -> V_40 = V_2 -> V_40 ;
V_37 -> V_44 = V_2 -> V_346 ;
V_37 -> V_72 = V_71 ;
V_37 -> V_42 = V_71 ;
V_2 -> V_29 [ V_71 ] = V_37 ;
}
for (; V_159 < V_2 -> V_206 ; V_159 ++ ) {
V_37 = F_231 ( sizeof( * V_37 ) , V_344 ) ;
if ( ! V_37 )
goto V_345;
V_37 -> V_14 = & V_2 -> V_13 -> V_14 ;
V_37 -> V_40 = V_2 -> V_40 ;
V_37 -> V_44 = V_2 -> V_347 ;
V_37 -> V_72 = V_159 ;
V_37 -> V_42 = V_159 ;
V_2 -> V_103 [ V_159 ] = V_37 ;
}
return 0 ;
V_345:
while ( V_71 ) {
F_226 ( V_2 -> V_29 [ -- V_71 ] ) ;
V_2 -> V_29 [ V_71 ] = NULL ;
}
while ( V_159 ) {
F_226 ( V_2 -> V_103 [ -- V_159 ] ) ;
V_2 -> V_103 [ V_159 ] = NULL ;
}
return - V_348 ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
int V_213 ;
int V_212 , V_349 ;
V_349 = F_115 ( V_2 -> V_206 , V_2 -> V_208 ) ;
V_349 = F_228 ( int , V_349 , F_229 () ) ;
V_349 += V_177 ;
V_2 -> V_218 = F_233 ( V_349 ,
sizeof( struct V_216 ) , V_344 ) ;
if ( ! V_2 -> V_218 )
return - V_348 ;
for ( V_212 = 0 ; V_212 < V_349 ; V_212 ++ )
V_2 -> V_218 [ V_212 ] . V_217 = V_212 ;
V_213 = F_224 ( V_2 , V_349 ) ;
if ( V_213 )
return V_213 ;
V_213 = F_234 ( V_40 , V_2 -> V_208 ) ;
if ( V_213 )
return V_213 ;
return F_235 ( V_40 , V_2 -> V_206 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
int V_290 , V_350 ;
struct V_53 * V_54 ;
V_350 = V_2 -> V_176 - V_177 ;
for ( V_290 = 0 ; V_290 < V_350 ; V_290 ++ ) {
V_54 = F_231 ( sizeof( struct V_53 ) , V_344 ) ;
if ( ! V_54 )
goto V_351;
V_54 -> V_2 = V_2 ;
V_54 -> V_166 = V_290 ;
F_237 ( V_2 -> V_40 , & V_54 -> V_78 ,
F_111 , 64 ) ;
V_2 -> V_54 [ V_290 ] = V_54 ;
}
return 0 ;
V_351:
while ( V_290 ) {
V_290 -- ;
V_54 = V_2 -> V_54 [ V_290 ] ;
#ifdef F_55
F_238 ( & V_54 -> V_78 ) ;
#endif
F_239 ( & V_54 -> V_78 ) ;
F_226 ( V_54 ) ;
V_2 -> V_54 [ V_290 ] = NULL ;
}
return - V_348 ;
}
static void F_240 ( struct V_1 * V_2 )
{
int V_290 , V_350 = V_2 -> V_176 - V_177 ;
for ( V_290 = 0 ; V_290 < V_350 ; V_290 ++ ) {
struct V_53 * V_54 = V_2 -> V_54 [ V_290 ] ;
V_2 -> V_54 [ V_290 ] = NULL ;
#ifdef F_55
F_238 ( & V_54 -> V_78 ) ;
#endif
F_239 ( & V_54 -> V_78 ) ;
F_226 ( V_54 ) ;
}
}
static void F_241 ( struct V_1 * V_2 )
{
F_242 ( V_2 -> V_13 ) ;
F_226 ( V_2 -> V_218 ) ;
V_2 -> V_218 = NULL ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_213 ;
F_227 ( V_2 ) ;
V_213 = F_232 ( V_2 ) ;
if ( V_213 ) {
F_136 ( & V_2 -> V_10 ,
L_26 ) ;
goto V_352;
}
V_213 = F_236 ( V_2 ) ;
if ( V_213 ) {
F_136 ( & V_2 -> V_10 , L_27 ) ;
goto V_353;
}
V_213 = F_230 ( V_2 ) ;
if ( V_213 ) {
F_46 ( L_28 ) ;
goto V_354;
}
F_136 ( & V_2 -> V_10 , L_29 ,
( V_2 -> V_206 > 1 ) ? L_30 :
L_31 , V_2 -> V_206 , V_2 -> V_208 ) ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_354:
F_240 ( V_2 ) ;
V_353:
F_241 ( V_2 ) ;
V_352:
return V_213 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ ) {
F_226 ( V_2 -> V_29 [ V_60 ] ) ;
V_2 -> V_29 [ V_60 ] = NULL ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ ) {
F_226 ( V_2 -> V_103 [ V_60 ] ) ;
V_2 -> V_103 [ V_60 ] = NULL ;
}
V_2 -> V_208 = 0 ;
V_2 -> V_206 = 0 ;
F_240 ( V_2 ) ;
F_241 ( V_2 ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_355 * V_13 = V_2 -> V_13 ;
struct V_52 * V_40 = V_2 -> V_40 ;
int V_213 ;
V_10 -> V_356 = V_13 -> V_357 ;
V_10 -> V_358 = V_13 -> V_333 ;
V_10 -> V_359 = V_13 -> V_360 ;
V_10 -> V_361 = V_13 -> V_362 ;
V_10 -> V_363 = V_13 -> V_364 ;
V_10 -> V_293 . V_270 . V_365 ( V_10 ) ;
V_10 -> V_195 . V_366 = 2 ;
V_10 -> V_195 . V_367 = 2 ;
F_246 ( & V_2 -> V_269 ) ;
V_213 = V_10 -> V_195 . V_270 . V_336 ( V_10 ) ;
if ( V_213 ) {
F_247 ( & V_13 -> V_14 ,
L_32 ) ;
} else {
V_213 = V_10 -> V_195 . V_270 . V_337 ( V_10 ) ;
if ( V_213 ) {
F_46 ( L_33 , V_213 ) ;
goto V_368;
}
F_200 ( V_2 ) ;
V_213 = V_10 -> V_195 . V_270 . V_369 ( V_10 , V_10 -> V_195 . V_280 ) ;
if ( V_213 )
F_247 ( & V_13 -> V_14 , L_34 ) ;
else if ( F_248 ( V_2 -> V_10 . V_195 . V_280 ) )
F_247 ( & V_13 -> V_14 ,
L_35 ) ;
F_223 ( V_40 -> V_157 , V_10 -> V_195 . V_280 ) ;
}
if ( ! F_203 ( V_40 -> V_157 ) ) {
F_247 ( & V_13 -> V_14 , L_36 ) ;
F_249 ( V_40 ) ;
F_223 ( V_10 -> V_195 . V_280 , V_40 -> V_157 ) ;
F_223 ( V_10 -> V_195 . V_330 , V_40 -> V_157 ) ;
}
V_2 -> V_165 = 1 ;
V_2 -> V_179 = 1 ;
V_2 -> V_346 = V_370 ;
V_2 -> V_347 = V_371 ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_368:
return V_213 ;
}
void F_250 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_335 , & V_2 -> V_4 ) )
return;
F_251 ( V_312 , V_2 -> V_38 . V_311 ,
V_2 -> V_38 . V_296 ) ;
F_251 ( V_317 , V_2 -> V_38 . V_316 ,
V_2 -> V_38 . V_297 ) ;
F_252 ( V_314 , V_315 ,
V_2 -> V_38 . V_313 ,
V_2 -> V_38 . V_303 ) ;
F_252 ( V_319 , V_320 ,
V_2 -> V_38 . V_318 ,
V_2 -> V_38 . V_306 ) ;
F_251 ( V_322 , V_2 -> V_38 . V_321 ,
V_2 -> V_38 . V_309 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ ) {
V_2 -> V_372 +=
V_2 -> V_103 [ V_60 ] -> V_372 ;
V_2 -> V_103 [ V_60 ] -> V_372 = 0 ;
}
}
static void F_253 ( unsigned long V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_147 ;
F_205 ( & V_2 -> V_332 , ( V_373 * 2 ) + V_75 ) ;
F_1 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_50 & V_51 ) )
return;
V_2 -> V_50 &= ~ V_51 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_335 , & V_2 -> V_4 ) )
return;
V_2 -> V_374 ++ ;
F_219 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_375 = 0 ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_335 , & V_2 -> V_4 ) )
return;
if ( F_49 ( V_2 -> V_40 ) ) {
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ )
F_256 ( V_2 -> V_29 [ V_60 ] ) ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_176 - V_177 ; V_60 ++ ) {
struct V_53 * V_376 = V_2 -> V_54 [ V_60 ] ;
if ( V_376 -> V_159 . V_37 || V_376 -> V_71 . V_37 )
V_375 |= 1 << V_60 ;
}
F_19 ( V_10 , V_377 , V_375 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_378 = V_2 -> V_378 ;
bool V_379 = V_2 -> V_379 ;
T_10 V_213 ;
F_177 ( & V_2 -> V_269 ) ;
V_213 = V_10 -> V_195 . V_270 . V_380 ( V_10 , & V_378 , & V_379 , false ) ;
F_178 ( & V_2 -> V_269 ) ;
if ( V_213 && F_258 ( V_75 , V_2 -> V_338 + ( 10 * V_373 ) ) ) {
V_2 -> V_50 |= V_51 ;
V_379 = false ;
}
V_2 -> V_379 = V_379 ;
V_2 -> V_378 = V_378 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
if ( F_49 ( V_40 ) )
return;
F_247 ( & V_2 -> V_13 -> V_14 , L_37 ,
( V_2 -> V_378 == V_381 ) ?
L_38 :
( V_2 -> V_378 == V_382 ) ?
L_39 :
( V_2 -> V_378 == V_383 ) ?
L_40 :
L_41 ) ;
F_260 ( V_40 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
V_2 -> V_378 = 0 ;
if ( ! F_49 ( V_40 ) )
return;
F_247 ( & V_2 -> V_13 -> V_14 , L_42 ) ;
F_214 ( V_40 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_335 , & V_2 -> V_4 ) )
return;
F_257 ( V_2 ) ;
if ( V_2 -> V_379 )
F_259 ( V_2 ) ;
else
F_261 ( V_2 ) ;
F_250 ( V_2 ) ;
}
static void F_263 ( struct V_384 * V_385 )
{
struct V_1 * V_2 = F_112 ( V_385 ,
struct V_1 ,
V_8 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
if ( F_14 ( V_10 -> V_12 ) ) {
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
void F_267 ( struct V_28 * V_29 )
{
F_209 ( V_29 ) ;
F_268 ( V_29 -> V_62 ) ;
V_29 -> V_62 = NULL ;
if ( ! V_29 -> V_334 )
return;
F_269 ( V_29 -> V_14 , V_29 -> V_136 , V_29 -> V_334 ,
V_29 -> V_34 ) ;
V_29 -> V_334 = NULL ;
}
static void F_270 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ )
if ( V_2 -> V_29 [ V_60 ] -> V_334 )
F_267 ( V_2 -> V_29 [ V_60 ] ) ;
}
int F_271 ( struct V_28 * V_29 )
{
int V_136 ;
V_136 = sizeof( struct V_30 ) * V_29 -> V_44 ;
V_29 -> V_62 = F_272 ( V_136 ) ;
if ( ! V_29 -> V_62 )
goto V_213;
V_29 -> V_136 = V_29 -> V_44 * sizeof( union V_55 ) ;
V_29 -> V_136 = F_92 ( V_29 -> V_136 , 4096 ) ;
V_29 -> V_334 = F_273 ( V_29 -> V_14 , V_29 -> V_136 ,
& V_29 -> V_34 , V_344 ) ;
if ( ! V_29 -> V_334 )
goto V_213;
return 0 ;
V_213:
F_268 ( V_29 -> V_62 ) ;
V_29 -> V_62 = NULL ;
F_136 ( & V_2 -> V_10 , L_43 ) ;
return - V_348 ;
}
static int F_274 ( struct V_1 * V_2 )
{
int V_60 , V_213 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ ) {
V_213 = F_271 ( V_2 -> V_29 [ V_60 ] ) ;
if ( ! V_213 )
continue;
F_136 ( & V_2 -> V_10 , L_44 , V_60 ) ;
break;
}
return V_213 ;
}
int F_275 ( struct V_28 * V_103 )
{
int V_136 ;
V_136 = sizeof( struct V_114 ) * V_103 -> V_44 ;
V_103 -> V_123 = F_272 ( V_136 ) ;
if ( ! V_103 -> V_123 )
goto V_213;
V_103 -> V_136 = V_103 -> V_44 * sizeof( union V_79 ) ;
V_103 -> V_136 = F_92 ( V_103 -> V_136 , 4096 ) ;
V_103 -> V_334 = F_273 ( V_103 -> V_14 , V_103 -> V_136 ,
& V_103 -> V_34 , V_344 ) ;
if ( ! V_103 -> V_334 )
goto V_213;
return 0 ;
V_213:
F_268 ( V_103 -> V_123 ) ;
V_103 -> V_123 = NULL ;
F_10 ( V_103 -> V_14 , L_45 ) ;
return - V_348 ;
}
static int F_276 ( struct V_1 * V_2 )
{
int V_60 , V_213 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ ) {
V_213 = F_275 ( V_2 -> V_103 [ V_60 ] ) ;
if ( ! V_213 )
continue;
F_136 ( & V_2 -> V_10 , L_46 , V_60 ) ;
break;
}
return V_213 ;
}
void F_277 ( struct V_28 * V_103 )
{
F_207 ( V_103 ) ;
F_268 ( V_103 -> V_123 ) ;
V_103 -> V_123 = NULL ;
F_269 ( V_103 -> V_14 , V_103 -> V_136 , V_103 -> V_334 ,
V_103 -> V_34 ) ;
V_103 -> V_334 = NULL ;
}
static void F_278 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ )
if ( V_2 -> V_103 [ V_60 ] -> V_334 )
F_277 ( V_2 -> V_103 [ V_60 ] ) ;
}
static int F_279 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_213 ;
if ( ! V_2 -> V_176 )
return - V_348 ;
if ( V_10 -> V_386 ) {
F_218 ( V_2 ) ;
if ( V_10 -> V_386 ) {
V_213 = V_272 ;
F_46 ( L_47 ) ;
goto V_387;
}
}
if ( F_2 ( V_388 , & V_2 -> V_4 ) )
return - V_389 ;
F_214 ( V_40 ) ;
V_213 = F_274 ( V_2 ) ;
if ( V_213 )
goto V_390;
V_213 = F_276 ( V_2 ) ;
if ( V_213 )
goto V_391;
F_197 ( V_2 ) ;
F_132 ( V_2 ) ;
V_213 = F_139 ( V_2 ) ;
if ( V_213 )
goto V_392;
F_202 ( V_2 ) ;
return 0 ;
V_392:
F_212 ( V_2 ) ;
V_391:
F_278 ( V_2 ) ;
V_390:
F_270 ( V_2 ) ;
F_218 ( V_2 ) ;
V_387:
return V_213 ;
}
static int F_280 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
F_212 ( V_2 ) ;
F_140 ( V_2 ) ;
F_270 ( V_2 ) ;
F_278 ( V_2 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 )
{
struct V_52 * V_14 = V_2 -> V_40 ;
if ( ! ( V_2 -> V_50 & V_295 ) )
return;
V_2 -> V_50 &= ~ V_295 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_335 , & V_2 -> V_4 ) )
return;
if ( F_281 ( V_14 ) )
F_280 ( V_14 ) ;
F_244 ( V_2 ) ;
F_243 ( V_2 ) ;
if ( F_281 ( V_14 ) )
F_279 ( V_14 ) ;
}
static void F_282 ( struct V_28 * V_29 ,
T_1 V_393 , T_1 V_394 ,
T_1 V_395 )
{
struct V_396 * V_397 ;
T_6 V_60 = V_29 -> V_73 ;
V_397 = F_283 ( V_29 , V_60 ) ;
V_60 ++ ;
V_29 -> V_73 = ( V_60 < V_29 -> V_44 ) ? V_60 : 0 ;
V_394 |= V_398 | V_399 ;
V_397 -> V_393 = F_40 ( V_393 ) ;
V_397 -> V_400 = 0 ;
V_397 -> V_401 = F_40 ( V_394 ) ;
V_397 -> V_395 = F_40 ( V_395 ) ;
}
static int F_284 ( struct V_28 * V_29 ,
struct V_30 * V_402 ,
T_2 * V_403 )
{
struct V_77 * V_32 = V_402 -> V_32 ;
T_1 V_393 , V_394 ;
T_1 V_395 , V_404 ;
int V_213 ;
if ( V_32 -> V_101 != V_405 )
return 0 ;
if ( ! F_285 ( V_32 ) )
return 0 ;
V_213 = F_286 ( V_32 , 0 ) ;
if ( V_213 < 0 )
return V_213 ;
V_394 = V_406 ;
if ( V_402 -> V_111 == F_69 ( V_407 ) ) {
struct V_408 * V_409 = F_287 ( V_32 ) ;
V_409 -> V_410 = 0 ;
V_409 -> V_411 = 0 ;
F_288 ( V_32 ) -> V_411 = ~ F_289 ( V_409 -> V_412 ,
V_409 -> V_413 , 0 ,
V_414 ,
0 ) ;
V_394 |= V_415 ;
V_402 -> V_416 |= V_417 |
V_418 |
V_419 ;
} else if ( F_290 ( V_32 ) ) {
F_291 ( V_32 ) -> V_420 = 0 ;
F_288 ( V_32 ) -> V_411 =
~ F_292 ( & F_291 ( V_32 ) -> V_412 ,
& F_291 ( V_32 ) -> V_413 ,
0 , V_414 , 0 ) ;
V_402 -> V_416 |= V_417 |
V_418 ;
}
V_404 = F_293 ( V_32 ) ;
* V_403 += V_404 ;
* V_403 = F_294 ( V_32 ) + V_404 ;
V_402 -> V_68 = F_98 ( V_32 ) -> V_68 ;
V_402 -> V_67 += ( V_402 -> V_68 - 1 ) * * V_403 ;
V_395 = V_404 << V_421 ;
V_395 |= F_98 ( V_32 ) -> V_422 << V_423 ;
V_395 |= 1 << V_424 ;
V_393 = F_295 ( V_32 ) ;
V_393 |= F_296 ( V_32 ) << V_425 ;
V_393 |= V_402 -> V_416 & V_426 ;
F_282 ( V_29 , V_393 ,
V_394 , V_395 ) ;
return 1 ;
}
static void F_297 ( struct V_28 * V_29 ,
struct V_30 * V_402 )
{
struct V_77 * V_32 = V_402 -> V_32 ;
T_1 V_393 = 0 ;
T_1 V_395 = 0 ;
T_1 V_394 = 0 ;
if ( V_32 -> V_101 == V_405 ) {
T_2 V_427 = 0 ;
T_9 V_428 ;
switch ( V_402 -> V_111 ) {
case F_69 ( V_407 ) :
V_393 |= F_295 ( V_32 ) ;
V_394 |= V_415 ;
V_427 = F_287 ( V_32 ) -> V_111 ;
break;
case F_69 ( V_429 ) :
V_393 |= F_295 ( V_32 ) ;
V_427 = F_291 ( V_32 ) -> V_430 ;
if ( F_42 ( F_295 ( V_32 ) ==
sizeof( struct V_431 ) ) )
break;
F_298 ( V_32 , F_296 ( V_32 ) +
sizeof( struct V_431 ) ,
& V_427 , & V_428 ) ;
if ( F_16 ( V_428 ) )
V_427 = V_432 ;
break;
default:
break;
}
switch ( V_427 ) {
case V_414 :
V_394 |= V_406 ;
V_395 = F_293 ( V_32 ) <<
V_421 ;
break;
case V_433 :
V_394 |= V_434 ;
V_395 = sizeof( struct V_435 ) <<
V_421 ;
break;
case V_436 :
V_395 = sizeof( struct V_437 ) <<
V_421 ;
break;
default:
if ( F_16 ( F_299 () ) ) {
F_300 ( V_29 -> V_14 ,
L_48 ,
V_402 -> V_111 , V_427 ) ;
}
F_301 ( V_32 ) ;
goto V_438;
}
V_402 -> V_416 |= V_418 ;
}
V_438:
V_393 |= F_296 ( V_32 ) << V_425 ;
V_393 |= V_402 -> V_416 & V_426 ;
F_282 ( V_29 , V_393 ,
V_394 , V_395 ) ;
}
static T_11 F_302 ( T_1 V_416 )
{
T_11 V_439 = F_40 ( V_440 |
V_441 |
V_442 ) ;
if ( V_416 & V_443 )
V_439 |= F_40 ( V_444 ) ;
if ( V_416 & V_417 )
V_439 |= F_40 ( V_445 ) ;
return V_439 ;
}
static void F_303 ( union V_55 * V_56 ,
T_1 V_416 , unsigned int V_446 )
{
T_11 V_447 = F_40 ( V_446 << V_448 ) ;
if ( V_416 & V_418 )
V_447 |= F_40 ( V_449 ) ;
if ( V_416 & V_419 )
V_447 |= F_40 ( V_450 ) ;
if ( V_416 & V_417 )
V_447 |= F_40 ( 1 << V_424 ) ;
V_447 |= F_40 ( V_451 ) ;
V_56 -> V_124 . V_447 = V_447 ;
}
static void F_304 ( struct V_28 * V_29 ,
struct V_30 * V_402 ,
const T_2 V_403 )
{
T_7 V_34 ;
struct V_77 * V_32 = V_402 -> V_32 ;
struct V_30 * V_31 ;
union V_55 * V_56 ;
struct V_452 * V_453 = & F_98 ( V_32 ) -> V_454 [ 0 ] ;
unsigned int V_455 = V_32 -> V_455 ;
unsigned int V_136 = F_305 ( V_32 ) ;
unsigned int V_446 = V_32 -> V_33 - V_403 ;
T_1 V_416 = V_402 -> V_416 ;
T_11 V_439 ;
T_6 V_60 = V_29 -> V_73 ;
V_56 = F_38 ( V_29 , V_60 ) ;
F_303 ( V_56 , V_416 , V_446 ) ;
V_439 = F_302 ( V_416 ) ;
V_34 = F_306 ( V_29 -> V_14 , V_32 -> V_147 , V_136 , V_35 ) ;
if ( F_76 ( V_29 -> V_14 , V_34 ) )
goto V_456;
F_27 ( V_402 , V_33 , V_136 ) ;
F_307 ( V_402 , V_34 , V_34 ) ;
V_56 -> V_124 . V_457 = F_79 ( V_34 ) ;
for (; ; ) {
while ( F_16 ( V_136 > V_458 ) ) {
V_56 -> V_124 . V_459 =
V_439 | F_40 ( V_458 ) ;
V_60 ++ ;
V_56 ++ ;
if ( V_60 == V_29 -> V_44 ) {
V_56 = F_38 ( V_29 , 0 ) ;
V_60 = 0 ;
}
V_34 += V_458 ;
V_136 -= V_458 ;
V_56 -> V_124 . V_457 = F_79 ( V_34 ) ;
V_56 -> V_124 . V_447 = 0 ;
}
if ( F_42 ( ! V_455 ) )
break;
V_56 -> V_124 . V_459 = V_439 | F_40 ( V_136 ) ;
V_60 ++ ;
V_56 ++ ;
if ( V_60 == V_29 -> V_44 ) {
V_56 = F_38 ( V_29 , 0 ) ;
V_60 = 0 ;
}
V_136 = F_308 ( V_453 ) ;
V_455 -= V_136 ;
V_34 = F_309 ( V_29 -> V_14 , V_453 , 0 , V_136 ,
V_35 ) ;
if ( F_76 ( V_29 -> V_14 , V_34 ) )
goto V_456;
V_31 = & V_29 -> V_62 [ V_60 ] ;
F_27 ( V_31 , V_33 , V_136 ) ;
F_307 ( V_31 , V_34 , V_34 ) ;
V_56 -> V_124 . V_457 = F_79 ( V_34 ) ;
V_56 -> V_124 . V_447 = 0 ;
V_453 ++ ;
}
V_439 |= F_40 ( V_136 ) | F_40 ( V_460 ) ;
V_56 -> V_124 . V_459 = V_439 ;
V_402 -> V_74 = V_75 ;
F_80 () ;
V_402 -> V_36 = V_56 ;
V_60 ++ ;
if ( V_60 == V_29 -> V_44 )
V_60 = 0 ;
V_29 -> V_73 = V_60 ;
F_81 ( V_29 , V_60 ) ;
return;
V_456:
F_10 ( V_29 -> V_14 , L_49 ) ;
for (; ; ) {
V_31 = & V_29 -> V_62 [ V_60 ] ;
F_21 ( V_29 , V_31 ) ;
if ( V_31 == V_402 )
break;
if ( V_60 == 0 )
V_60 = V_29 -> V_44 ;
V_60 -- ;
}
V_29 -> V_73 = V_60 ;
}
static int F_310 ( struct V_28 * V_29 , int V_136 )
{
F_47 ( V_29 -> V_40 , V_29 -> V_72 ) ;
F_51 () ;
if ( F_42 ( F_50 ( V_29 ) < V_136 ) )
return - V_389 ;
F_311 ( V_29 -> V_40 , V_29 -> V_72 ) ;
++ V_29 -> V_47 . V_76 ;
return 0 ;
}
static int F_312 ( struct V_28 * V_29 , int V_136 )
{
if ( F_42 ( F_50 ( V_29 ) >= V_136 ) )
return 0 ;
return F_310 ( V_29 , V_136 ) ;
}
static int F_313 ( struct V_77 * V_32 , struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_30 * V_402 ;
struct V_28 * V_29 ;
int V_461 ;
T_1 V_416 = 0 ;
T_6 V_44 = F_314 ( F_305 ( V_32 ) ) ;
#if V_118 > V_458
unsigned short V_462 ;
#endif
T_2 V_403 = 0 ;
T_2 * V_463 = F_315 ( V_32 , 0 , 0 , NULL ) ;
if ( ! V_463 || F_316 ( V_463 ) ) {
F_22 ( V_32 ) ;
return V_464 ;
}
V_29 = V_2 -> V_29 [ V_32 -> V_465 ] ;
#if V_118 > V_458
for ( V_462 = 0 ; V_462 < F_98 ( V_32 ) -> V_143 ; V_462 ++ )
V_44 += F_314 ( F_98 ( V_32 ) -> V_454 [ V_462 ] . V_136 ) ;
#else
V_44 += F_98 ( V_32 ) -> V_143 ;
#endif
if ( F_312 ( V_29 , V_44 + 3 ) ) {
V_29 -> V_47 . V_466 ++ ;
return V_467 ;
}
V_402 = & V_29 -> V_62 [ V_29 -> V_73 ] ;
V_402 -> V_32 = V_32 ;
V_402 -> V_67 = V_32 -> V_33 ;
V_402 -> V_68 = 1 ;
if ( F_317 ( V_32 ) ) {
V_416 |= F_318 ( V_32 ) ;
V_416 <<= V_468 ;
V_416 |= V_443 ;
}
V_402 -> V_416 = V_416 ;
V_402 -> V_111 = F_319 ( V_32 ) ;
V_461 = F_284 ( V_29 , V_402 , & V_403 ) ;
if ( V_461 < 0 )
goto V_469;
else if ( ! V_461 )
F_297 ( V_29 , V_402 ) ;
F_304 ( V_29 , V_402 , V_403 ) ;
F_312 ( V_29 , V_470 ) ;
return V_464 ;
V_469:
F_22 ( V_402 -> V_32 ) ;
V_402 -> V_32 = NULL ;
return V_464 ;
}
static int F_320 ( struct V_52 * V_40 , void * V_471 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_472 * V_280 = V_471 ;
if ( ! F_203 ( V_280 -> V_473 ) )
return - V_474 ;
F_223 ( V_40 -> V_157 , V_280 -> V_473 ) ;
F_223 ( V_10 -> V_195 . V_280 , V_280 -> V_473 ) ;
F_177 ( & V_2 -> V_269 ) ;
V_10 -> V_195 . V_270 . V_329 ( V_10 , 0 , V_10 -> V_195 . V_280 , 0 ) ;
F_178 ( & V_2 -> V_269 ) ;
return 0 ;
}
static int F_321 ( struct V_52 * V_40 , int V_475 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_476 = V_475 + V_266 + V_267 ;
int V_477 = V_478 ;
switch ( V_2 -> V_10 . V_343 ) {
case V_325 :
case V_324 :
V_477 = V_479 ;
break;
default:
if ( V_2 -> V_10 . V_195 . type != V_480 )
V_477 = V_479 ;
break;
}
if ( ( V_475 < 68 ) || ( V_476 > V_477 ) )
return - V_481 ;
F_136 ( V_10 , L_50 ,
V_40 -> V_265 , V_475 ) ;
V_40 -> V_265 = V_475 ;
F_175 ( V_10 , V_476 ) ;
return 0 ;
}
static void F_322 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ )
F_128 ( 0 , V_2 -> V_54 [ V_60 ] ) ;
}
static int F_323 ( struct V_355 * V_13 , T_12 V_4 )
{
struct V_52 * V_40 = F_324 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
#ifdef F_325
int V_482 = 0 ;
#endif
F_326 ( V_40 ) ;
if ( F_281 ( V_40 ) ) {
F_264 () ;
F_212 ( V_2 ) ;
F_140 ( V_2 ) ;
F_270 ( V_2 ) ;
F_278 ( V_2 ) ;
F_265 () ;
}
F_244 ( V_2 ) ;
#ifdef F_325
V_482 = F_327 ( V_13 ) ;
if ( V_482 )
return V_482 ;
#endif
if ( ! F_3 ( V_483 , & V_2 -> V_4 ) )
F_328 ( V_13 ) ;
return 0 ;
}
static int F_329 ( struct V_355 * V_13 )
{
struct V_52 * V_40 = F_324 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
T_1 V_213 ;
F_330 ( V_13 ) ;
F_327 ( V_13 ) ;
V_213 = F_331 ( V_13 ) ;
if ( V_213 ) {
F_10 ( & V_13 -> V_14 , L_51 ) ;
return V_213 ;
}
F_7 () ;
F_8 ( V_483 , & V_2 -> V_4 ) ;
F_332 ( V_13 ) ;
F_218 ( V_2 ) ;
F_264 () ;
V_213 = F_243 ( V_2 ) ;
F_265 () ;
if ( V_213 ) {
F_10 ( & V_13 -> V_14 , L_52 ) ;
return V_213 ;
}
if ( F_281 ( V_40 ) ) {
V_213 = F_279 ( V_40 ) ;
if ( V_213 )
return V_213 ;
}
F_333 ( V_40 ) ;
return V_213 ;
}
static void F_334 ( struct V_355 * V_13 )
{
F_323 ( V_13 , V_484 ) ;
}
static struct V_485 * F_335 ( struct V_52 * V_40 ,
struct V_485 * V_38 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
unsigned int V_486 ;
T_5 V_70 , V_39 ;
const struct V_28 * V_37 ;
int V_60 ;
F_250 ( V_2 ) ;
V_38 -> V_487 = V_2 -> V_38 . V_309 - V_2 -> V_38 . V_310 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_206 ; V_60 ++ ) {
V_37 = V_2 -> V_103 [ V_60 ] ;
do {
V_486 = F_336 ( & V_37 -> V_69 ) ;
V_70 = V_37 -> V_38 . V_70 ;
V_39 = V_37 -> V_38 . V_39 ;
} while ( F_337 ( & V_37 -> V_69 , V_486 ) );
V_38 -> V_488 += V_70 ;
V_38 -> V_489 += V_39 ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_208 ; V_60 ++ ) {
V_37 = V_2 -> V_29 [ V_60 ] ;
do {
V_486 = F_336 ( & V_37 -> V_69 ) ;
V_70 = V_37 -> V_38 . V_70 ;
V_39 = V_37 -> V_38 . V_39 ;
} while ( F_337 ( & V_37 -> V_69 , V_486 ) );
V_38 -> V_490 += V_70 ;
V_38 -> V_491 += V_39 ;
}
return V_38 ;
}
static void F_338 ( struct V_52 * V_14 )
{
V_14 -> V_492 = & V_493 ;
F_339 ( V_14 ) ;
V_14 -> V_494 = 5 * V_373 ;
}
static int F_340 ( struct V_355 * V_13 , const struct V_495 * V_496 )
{
struct V_52 * V_40 ;
struct V_1 * V_2 = NULL ;
struct V_9 * V_10 = NULL ;
const struct V_497 * V_498 = V_499 [ V_496 -> V_500 ] ;
int V_213 , V_501 ;
bool V_502 = false ;
V_213 = F_341 ( V_13 ) ;
if ( V_213 )
return V_213 ;
if ( ! F_342 ( & V_13 -> V_14 , F_148 ( 64 ) ) ) {
V_501 = 1 ;
} else {
V_213 = F_342 ( & V_13 -> V_14 , F_148 ( 32 ) ) ;
if ( V_213 ) {
F_10 ( & V_13 -> V_14 , L_53 ) ;
goto V_503;
}
V_501 = 0 ;
}
V_213 = F_343 ( V_13 , V_504 ) ;
if ( V_213 ) {
F_10 ( & V_13 -> V_14 , L_54 , V_213 ) ;
goto V_505;
}
F_332 ( V_13 ) ;
V_40 = F_344 ( sizeof( struct V_1 ) ,
V_506 ) ;
if ( ! V_40 ) {
V_213 = - V_348 ;
goto V_507;
}
F_345 ( V_40 , & V_13 -> V_14 ) ;
V_2 = F_30 ( V_40 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_13 = V_13 ;
V_10 = & V_2 -> V_10 ;
V_10 -> V_11 = V_2 ;
V_2 -> V_508 = F_346 ( V_509 , V_510 ) ;
F_327 ( V_13 ) ;
V_10 -> V_12 = F_347 ( F_348 ( V_13 , 0 ) ,
F_349 ( V_13 , 0 ) ) ;
V_2 -> V_231 = V_10 -> V_12 ;
if ( ! V_10 -> V_12 ) {
V_213 = - V_273 ;
goto V_511;
}
F_338 ( V_40 ) ;
memcpy ( & V_10 -> V_195 . V_270 , V_498 -> V_512 , sizeof( V_10 -> V_195 . V_270 ) ) ;
V_10 -> V_195 . type = V_498 -> V_195 ;
memcpy ( & V_10 -> V_293 . V_270 , & V_513 ,
sizeof( struct V_514 ) ) ;
V_213 = F_245 ( V_2 ) ;
if ( V_213 )
goto V_515;
if ( ! F_203 ( V_40 -> V_157 ) ) {
F_46 ( L_55 ) ;
V_213 = - V_273 ;
goto V_515;
}
V_40 -> V_516 = V_517 |
V_518 |
V_519 |
V_520 |
V_521 |
V_94 ;
V_40 -> V_82 = V_40 -> V_516 |
V_522 |
V_523 |
V_524 ;
V_40 -> V_525 |= V_520 |
V_521 |
V_518 |
V_519 |
V_517 ;
if ( V_501 )
V_40 -> V_82 |= V_526 ;
V_40 -> V_527 |= V_528 ;
if ( F_14 ( V_10 -> V_12 ) ) {
V_213 = - V_273 ;
goto V_515;
}
F_350 ( & V_2 -> V_332 , & F_253 ,
( unsigned long ) V_2 ) ;
F_351 ( & V_2 -> V_8 , F_263 ) ;
F_179 ( V_15 , & V_2 -> V_4 ) ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
V_213 = F_243 ( V_2 ) ;
if ( V_213 )
goto V_515;
strcpy ( V_40 -> V_219 , L_56 ) ;
V_213 = F_352 ( V_40 ) ;
if ( V_213 )
goto V_529;
F_353 ( V_13 , V_40 ) ;
F_214 ( V_40 ) ;
F_199 ( V_2 ) ;
F_247 ( & V_13 -> V_14 , L_57 , V_40 -> V_157 ) ;
F_247 ( & V_13 -> V_14 , L_58 , V_10 -> V_195 . type ) ;
switch ( V_10 -> V_195 . type ) {
case V_264 :
F_247 ( & V_13 -> V_14 , L_59 ) ;
break;
case V_530 :
F_247 ( & V_13 -> V_14 , L_60 ) ;
break;
case V_480 :
default:
F_247 ( & V_13 -> V_14 , L_61 ) ;
break;
}
return 0 ;
V_529:
F_244 ( V_2 ) ;
V_515:
F_241 ( V_2 ) ;
F_354 ( V_2 -> V_231 ) ;
V_511:
V_502 = ! F_3 ( V_483 , & V_2 -> V_4 ) ;
F_355 ( V_40 ) ;
V_507:
F_356 ( V_13 ) ;
V_505:
V_503:
if ( ! V_2 || V_502 )
F_328 ( V_13 ) ;
return V_213 ;
}
static void F_357 ( struct V_355 * V_13 )
{
struct V_52 * V_40 = F_324 ( V_13 ) ;
struct V_1 * V_2 ;
bool V_502 ;
if ( ! V_40 )
return;
V_2 = F_30 ( V_40 ) ;
F_179 ( V_5 , & V_2 -> V_4 ) ;
F_358 ( & V_2 -> V_8 ) ;
if ( V_40 -> V_531 == V_532 )
F_359 ( V_40 ) ;
F_244 ( V_2 ) ;
F_241 ( V_2 ) ;
F_354 ( V_2 -> V_231 ) ;
F_356 ( V_13 ) ;
F_136 ( & V_2 -> V_10 , L_62 ) ;
V_502 = ! F_3 ( V_483 , & V_2 -> V_4 ) ;
F_355 ( V_40 ) ;
if ( V_502 )
F_328 ( V_13 ) ;
}
static T_13 F_360 ( struct V_355 * V_13 ,
T_14 V_4 )
{
struct V_52 * V_40 = F_324 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
if ( ! F_2 ( V_15 , & V_2 -> V_4 ) )
return V_533 ;
F_264 () ;
F_326 ( V_40 ) ;
if ( V_4 == V_534 ) {
F_265 () ;
return V_533 ;
}
if ( F_281 ( V_40 ) )
F_212 ( V_2 ) ;
if ( ! F_3 ( V_483 , & V_2 -> V_4 ) )
F_328 ( V_13 ) ;
F_265 () ;
return V_535 ;
}
static T_13 F_361 ( struct V_355 * V_13 )
{
struct V_52 * V_40 = F_324 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
if ( F_331 ( V_13 ) ) {
F_10 ( & V_13 -> V_14 ,
L_63 ) ;
return V_533 ;
}
F_7 () ;
F_8 ( V_483 , & V_2 -> V_4 ) ;
F_332 ( V_13 ) ;
F_218 ( V_2 ) ;
return V_536 ;
}
static void F_362 ( struct V_355 * V_13 )
{
struct V_52 * V_40 = F_324 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
if ( F_281 ( V_40 ) )
F_206 ( V_2 ) ;
F_333 ( V_40 ) ;
}
static int T_15 F_363 ( void )
{
F_194 ( L_64 , V_537 ,
V_538 ) ;
F_194 ( L_65 , V_539 ) ;
V_7 = F_364 ( V_504 ) ;
if ( ! V_7 ) {
F_46 ( L_66 , V_504 ) ;
return - V_348 ;
}
return F_365 ( & V_540 ) ;
}
static void T_16 F_366 ( void )
{
F_367 ( & V_540 ) ;
if ( V_7 ) {
F_368 ( V_7 ) ;
V_7 = NULL ;
}
}
char * F_369 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
return V_2 -> V_40 -> V_219 ;
}
