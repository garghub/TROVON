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
F_100 ( V_116 ) ;
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
void * V_145 = F_91 ( V_116 ) +
V_134 -> V_121 ;
F_41 ( V_145 ) ;
#if V_139 < 128
F_41 ( V_145 + V_139 ) ;
#endif
V_32 = F_103 ( V_103 -> V_40 ,
V_142 ) ;
if ( F_16 ( ! V_32 ) ) {
V_103 -> V_97 . V_120 ++ ;
return NULL ;
}
F_102 ( V_32 -> V_146 ) ;
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
T_1 V_147 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_19 ( V_10 , V_148 , V_147 ) ;
}
static int F_106 ( struct V_53 * V_54 ,
struct V_28 * V_103 ,
int V_59 )
{
unsigned int V_149 = 0 , V_150 = 0 ;
T_6 V_122 = F_50 ( V_103 ) ;
struct V_77 * V_32 = V_103 -> V_32 ;
while ( F_42 ( V_150 < V_59 ) ) {
union V_79 * V_80 ;
if ( V_122 >= V_151 ) {
F_78 ( V_103 , V_122 ) ;
V_122 = 0 ;
}
V_80 = F_72 ( V_103 , V_103 -> V_61 ) ;
if ( ! F_66 ( V_80 , V_152 ) )
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
V_149 += V_32 -> V_33 ;
if ( ( V_32 -> V_153 == V_154 ||
V_32 -> V_153 == V_155 ) &&
F_108 ( V_103 -> V_40 -> V_156 ,
F_109 ( V_32 ) -> V_157 ) ) {
F_110 ( V_32 ) ;
continue;
}
F_67 ( V_103 , V_80 , V_32 ) ;
F_54 ( V_54 , V_32 ) ;
V_32 = NULL ;
V_150 ++ ;
}
V_103 -> V_32 = V_32 ;
F_43 ( & V_103 -> V_69 ) ;
V_103 -> V_38 . V_39 += V_150 ;
V_103 -> V_38 . V_70 += V_149 ;
F_44 ( & V_103 -> V_69 ) ;
V_54 -> V_158 . V_58 += V_150 ;
V_54 -> V_158 . V_57 += V_149 ;
return V_150 ;
}
static int F_111 ( struct V_159 * V_78 , int V_59 )
{
struct V_53 * V_54 =
F_112 ( V_78 , struct V_53 , V_78 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_28 * V_37 ;
int V_160 , V_161 = 0 ;
bool V_162 = true ;
F_113 (ring, q_vector->tx)
V_162 &= F_37 ( V_54 , V_37 ) ;
if ( V_59 <= 0 )
return V_59 ;
#ifdef F_55
if ( ! F_114 ( V_54 ) )
return V_59 ;
#endif
if ( V_54 -> V_158 . V_44 > 1 )
V_160 = F_115 ( V_59 / V_54 -> V_158 . V_44 , 1 ) ;
else
V_160 = V_59 ;
F_113 (ring, q_vector->rx) {
int V_163 = F_106 ( V_54 , V_37 ,
V_160 ) ;
V_161 += V_163 ;
V_162 &= ( V_163 < V_160 ) ;
}
#ifdef F_55
F_116 ( V_54 ) ;
#endif
if ( ! V_162 )
return V_59 ;
F_117 ( V_78 , V_161 ) ;
if ( V_2 -> V_164 == 1 )
F_118 ( V_54 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) )
F_105 ( V_2 ,
1 << V_54 -> V_165 ) ;
return 0 ;
}
void F_119 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_165 = V_54 -> V_165 ;
T_1 V_166 = V_54 -> V_167 & V_168 ;
V_166 |= V_169 ;
F_19 ( V_10 , F_120 ( V_165 ) , V_166 ) ;
}
static int F_121 ( struct V_159 * V_78 )
{
struct V_53 * V_54 =
F_112 ( V_78 , struct V_53 , V_78 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_28 * V_37 ;
int V_170 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return V_171 ;
if ( ! F_122 ( V_54 ) )
return V_172 ;
F_113 (ring, q_vector->rx) {
V_170 = F_106 ( V_54 , V_37 , 4 ) ;
#ifdef F_123
if ( V_170 )
V_37 -> V_38 . V_163 += V_170 ;
else
V_37 -> V_38 . V_173 ++ ;
#endif
if ( V_170 )
break;
}
F_124 ( V_54 ) ;
return V_170 ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
int V_174 , V_165 ;
V_174 = V_2 -> V_175 - V_176 ;
V_2 -> V_177 = 0 ;
for ( V_165 = 0 ; V_165 < V_174 ; V_165 ++ ) {
struct V_28 * V_37 ;
V_54 = V_2 -> V_54 [ V_165 ] ;
F_113 (ring, q_vector->rx)
F_17 ( V_2 , 0 , V_37 -> V_42 , V_165 ) ;
F_113 (ring, q_vector->tx)
F_17 ( V_2 , 1 , V_37 -> V_42 , V_165 ) ;
if ( V_54 -> V_71 . V_37 && ! V_54 -> V_158 . V_37 ) {
if ( V_2 -> V_178 == 1 )
V_54 -> V_167 = V_179 ;
else
V_54 -> V_167 = V_2 -> V_178 ;
} else {
if ( V_2 -> V_164 == 1 )
V_54 -> V_167 = V_180 ;
else
V_54 -> V_167 = V_2 -> V_164 ;
}
V_2 -> V_177 |= 1 << V_165 ;
F_119 ( V_54 ) ;
}
F_17 ( V_2 , - 1 , 1 , V_165 ) ;
V_2 -> V_181 = 1 << V_165 ;
V_2 -> V_177 |= V_2 -> V_181 ;
}
static void F_126 ( struct V_53 * V_54 ,
struct V_182 * V_183 )
{
int V_70 = V_183 -> V_57 ;
int V_39 = V_183 -> V_58 ;
T_1 V_184 ;
T_5 V_185 ;
T_2 V_186 = V_183 -> V_167 ;
if ( V_39 == 0 )
return;
V_184 = V_54 -> V_167 >> 2 ;
V_185 = V_70 / V_184 ;
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
V_183 -> V_57 = 0 ;
V_183 -> V_58 = 0 ;
V_183 -> V_167 = V_186 ;
}
static void F_118 ( struct V_53 * V_54 )
{
T_1 V_190 = V_54 -> V_167 ;
T_2 V_191 ;
F_126 ( V_54 , & V_54 -> V_71 ) ;
F_126 ( V_54 , & V_54 -> V_158 ) ;
V_191 = F_115 ( V_54 -> V_158 . V_167 , V_54 -> V_71 . V_167 ) ;
switch ( V_191 ) {
case V_187 :
V_190 = V_192 ;
break;
case V_188 :
V_190 = V_180 ;
break;
case V_189 :
V_190 = V_179 ;
break;
default:
break;
}
if ( V_190 != V_54 -> V_167 ) {
V_190 = ( 10 * V_190 * V_54 -> V_167 ) /
( ( 9 * V_190 ) + V_54 -> V_167 ) ;
V_54 -> V_167 = V_190 ;
F_119 ( V_54 ) ;
}
}
static T_8 F_127 ( int V_193 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
V_10 -> V_194 . V_195 = 1 ;
F_1 ( V_2 ) ;
F_19 ( V_10 , V_148 , V_2 -> V_181 ) ;
return V_196 ;
}
static T_8 F_128 ( int V_193 , void * V_146 )
{
struct V_53 * V_54 = V_146 ;
if ( V_54 -> V_158 . V_37 || V_54 -> V_71 . V_37 )
F_129 ( & V_54 -> V_78 ) ;
return V_196 ;
}
static inline void F_130 ( struct V_1 * V_197 , int V_165 ,
int V_198 )
{
struct V_53 * V_54 = V_197 -> V_54 [ V_165 ] ;
V_197 -> V_103 [ V_198 ] -> V_199 = V_54 -> V_158 . V_37 ;
V_54 -> V_158 . V_37 = V_197 -> V_103 [ V_198 ] ;
V_54 -> V_158 . V_44 ++ ;
}
static inline void F_131 ( struct V_1 * V_197 , int V_165 ,
int V_200 )
{
struct V_53 * V_54 = V_197 -> V_54 [ V_165 ] ;
V_197 -> V_29 [ V_200 ] -> V_199 = V_54 -> V_71 . V_37 ;
V_54 -> V_71 . V_37 = V_197 -> V_29 [ V_200 ] ;
V_54 -> V_71 . V_44 ++ ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_174 ;
int V_201 = 0 ;
int V_202 = 0 , V_203 = 0 ;
int V_204 = V_2 -> V_205 ;
int V_206 = V_2 -> V_207 ;
int V_60 , V_208 ;
int V_209 , V_210 ;
V_174 = V_2 -> V_175 - V_176 ;
if ( V_174 == V_2 -> V_205 + V_2 -> V_207 ) {
for (; V_202 < V_204 ; V_201 ++ , V_202 ++ )
F_130 ( V_2 , V_201 , V_202 ) ;
for (; V_203 < V_206 ; V_201 ++ , V_203 ++ )
F_131 ( V_2 , V_201 , V_203 ) ;
return 0 ;
}
for ( V_60 = V_201 ; V_60 < V_174 ; V_60 ++ ) {
V_209 = F_133 ( V_204 , V_174 - V_60 ) ;
for ( V_208 = 0 ; V_208 < V_209 ; V_208 ++ ) {
F_130 ( V_2 , V_60 , V_202 ) ;
V_202 ++ ;
V_204 -- ;
}
}
for ( V_60 = V_201 ; V_60 < V_174 ; V_60 ++ ) {
V_210 = F_133 ( V_206 , V_174 - V_60 ) ;
for ( V_208 = 0 ; V_208 < V_210 ; V_208 ++ ) {
F_131 ( V_2 , V_60 , V_203 ) ;
V_203 ++ ;
V_206 -- ;
}
}
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
int V_174 = V_2 -> V_175 - V_176 ;
int V_211 , V_212 ;
int V_213 = 0 , V_214 = 0 ;
for ( V_211 = 0 ; V_211 < V_174 ; V_211 ++ ) {
struct V_53 * V_54 = V_2 -> V_54 [ V_211 ] ;
struct V_215 * V_216 = & V_2 -> V_217 [ V_211 ] ;
if ( V_54 -> V_71 . V_37 && V_54 -> V_158 . V_37 ) {
snprintf ( V_54 -> V_218 , sizeof( V_54 -> V_218 ) - 1 ,
L_12 , V_40 -> V_218 , L_13 , V_213 ++ ) ;
V_214 ++ ;
} else if ( V_54 -> V_158 . V_37 ) {
snprintf ( V_54 -> V_218 , sizeof( V_54 -> V_218 ) - 1 ,
L_12 , V_40 -> V_218 , L_14 , V_213 ++ ) ;
} else if ( V_54 -> V_71 . V_37 ) {
snprintf ( V_54 -> V_218 , sizeof( V_54 -> V_218 ) - 1 ,
L_12 , V_40 -> V_218 , L_15 , V_214 ++ ) ;
} else {
continue;
}
V_212 = F_135 ( V_216 -> V_211 , & F_128 , 0 ,
V_54 -> V_218 , V_54 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_10 ,
L_16 ,
V_212 ) ;
goto V_219;
}
}
V_212 = F_135 ( V_2 -> V_217 [ V_211 ] . V_211 ,
& F_127 , 0 , V_40 -> V_218 , V_2 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_10 , L_17 ,
V_212 ) ;
goto V_219;
}
return 0 ;
V_219:
while ( V_211 ) {
V_211 -- ;
F_137 ( V_2 -> V_217 [ V_211 ] . V_211 ,
V_2 -> V_54 [ V_211 ] ) ;
}
V_2 -> V_175 = 0 ;
return V_212 ;
}
static inline void F_138 ( struct V_1 * V_2 )
{
int V_60 , V_174 = V_2 -> V_175 - V_176 ;
for ( V_60 = 0 ; V_60 < V_174 ; V_60 ++ ) {
struct V_53 * V_54 = V_2 -> V_54 [ V_60 ] ;
V_54 -> V_158 . V_37 = NULL ;
V_54 -> V_71 . V_37 = NULL ;
V_54 -> V_158 . V_44 = 0 ;
V_54 -> V_71 . V_44 = 0 ;
}
}
static int F_139 ( struct V_1 * V_2 )
{
int V_212 = F_134 ( V_2 ) ;
if ( V_212 )
F_136 ( & V_2 -> V_10 , L_18 , V_212 ) ;
return V_212 ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_60 , V_174 ;
V_174 = V_2 -> V_175 ;
V_60 = V_174 - 1 ;
F_137 ( V_2 -> V_217 [ V_60 ] . V_211 , V_2 ) ;
V_60 -- ;
for (; V_60 >= 0 ; V_60 -- ) {
if ( ! V_2 -> V_54 [ V_60 ] -> V_158 . V_37 &&
! V_2 -> V_54 [ V_60 ] -> V_71 . V_37 )
continue;
F_137 ( V_2 -> V_217 [ V_60 ] . V_211 ,
V_2 -> V_54 [ V_60 ] ) ;
}
F_138 ( V_2 ) ;
}
static inline void F_141 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
F_19 ( V_10 , V_220 , 0 ) ;
F_19 ( V_10 , V_221 , ~ 0 ) ;
F_19 ( V_10 , V_222 , 0 ) ;
F_142 ( V_10 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_175 ; V_60 ++ )
F_143 ( V_2 -> V_217 [ V_60 ] . V_211 ) ;
}
static inline void F_144 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_19 ( V_10 , V_220 , V_2 -> V_177 ) ;
F_19 ( V_10 , V_222 , V_2 -> V_177 ) ;
F_19 ( V_10 , V_148 , V_2 -> V_177 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_5 V_223 = V_37 -> V_34 ;
int V_224 = 10 ;
T_1 V_225 = V_226 ;
T_2 V_42 = V_37 -> V_42 ;
F_19 ( V_10 , F_146 ( V_42 ) , V_227 ) ;
F_142 ( V_10 ) ;
F_19 ( V_10 , F_147 ( V_42 ) , V_223 & F_148 ( 32 ) ) ;
F_19 ( V_10 , F_149 ( V_42 ) , V_223 >> 32 ) ;
F_19 ( V_10 , F_150 ( V_42 ) ,
V_37 -> V_44 * sizeof( union V_55 ) ) ;
F_19 ( V_10 , F_151 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_152 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_153 ( V_42 ) ,
( V_228 |
V_229 ) ) ;
F_19 ( V_10 , F_31 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_32 ( V_42 ) , 0 ) ;
V_37 -> V_43 = V_2 -> V_230 + F_32 ( V_42 ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_73 = 0 ;
V_225 |= ( 8 << 16 ) ;
V_225 |= ( 1 << 8 ) |
32 ;
F_8 ( V_49 , & V_37 -> V_4 ) ;
F_19 ( V_10 , F_146 ( V_42 ) , V_225 ) ;
do {
F_154 ( 1000 , 2000 ) ;
V_225 = F_18 ( V_10 , F_146 ( V_42 ) ) ;
} while ( -- V_224 && ! ( V_225 & V_226 ) );
if ( ! V_224 )
F_46 ( L_19 , V_42 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_1 V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
F_145 ( V_2 , V_2 -> V_29 [ V_60 ] ) ;
}
static void F_156 ( struct V_1 * V_2 , int V_25 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_231 ;
V_231 = V_232 ;
V_231 |= V_142 << V_233 ;
V_231 |= V_133 >> V_234 ;
V_231 |= V_235 ;
F_19 ( V_10 , F_157 ( V_25 ) , V_231 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_236 = V_237 | V_238 |
V_239 | V_240 |
V_241 ;
if ( V_2 -> V_205 > 1 )
V_236 |= 1 << 29 ;
F_19 ( V_10 , V_242 , V_236 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_224 = V_243 ;
T_1 V_244 ;
T_2 V_42 = V_37 -> V_42 ;
if ( F_14 ( V_10 -> V_12 ) )
return;
V_244 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
V_244 &= ~ V_245 ;
F_19 ( V_10 , F_160 ( V_42 ) , V_244 ) ;
do {
F_161 ( 10 ) ;
V_244 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
} while ( -- V_224 && ( V_244 & V_245 ) );
if ( ! V_224 )
F_46 ( L_20 ,
V_42 ) ;
}
static void F_162 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_224 = V_243 ;
T_1 V_244 ;
T_2 V_42 = V_37 -> V_42 ;
if ( F_14 ( V_10 -> V_12 ) )
return;
do {
F_154 ( 1000 , 2000 ) ;
V_244 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
} while ( -- V_224 && ! ( V_244 & V_245 ) );
if ( ! V_224 )
F_46 ( L_21 ,
V_42 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_246 = 0 , V_247 = 0 ;
T_6 V_248 = V_2 -> V_205 ;
T_2 V_60 , V_208 ;
F_164 ( V_2 -> V_249 , sizeof( V_2 -> V_249 ) ) ;
for ( V_60 = 0 ; V_60 < V_250 ; V_60 ++ )
F_19 ( V_10 , F_165 ( V_60 ) , V_2 -> V_249 [ V_60 ] ) ;
for ( V_60 = 0 , V_208 = 0 ; V_60 < V_251 ; V_60 ++ , V_208 ++ ) {
if ( V_208 == V_248 )
V_208 = 0 ;
V_2 -> V_252 [ V_60 ] = V_208 ;
V_247 |= V_208 << ( V_60 & 0x3 ) * 8 ;
if ( ( V_60 & 3 ) == 3 ) {
F_19 ( V_10 , F_166 ( V_60 >> 2 ) , V_247 ) ;
V_247 = 0 ;
}
}
V_246 |= V_253 |
V_254 |
V_255 |
V_256 ;
V_246 |= V_257 ;
F_19 ( V_10 , V_258 , V_246 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_5 V_259 = V_37 -> V_34 ;
T_1 V_244 ;
T_2 V_42 = V_37 -> V_42 ;
V_244 = F_18 ( V_10 , F_160 ( V_42 ) ) ;
F_159 ( V_2 , V_37 ) ;
F_19 ( V_10 , F_168 ( V_42 ) , V_259 & F_148 ( 32 ) ) ;
F_19 ( V_10 , F_169 ( V_42 ) , V_259 >> 32 ) ;
F_19 ( V_10 , F_170 ( V_42 ) ,
V_37 -> V_44 * sizeof( union V_79 ) ) ;
F_19 ( V_10 , F_171 ( V_42 ) ,
V_260 ) ;
F_19 ( V_10 , F_172 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_173 ( V_42 ) , 0 ) ;
V_37 -> V_43 = V_2 -> V_230 + F_173 ( V_42 ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_73 = 0 ;
V_37 -> V_127 = 0 ;
F_156 ( V_2 , V_42 ) ;
V_244 &= ~ V_261 ;
V_244 |= V_245 | V_262 ;
F_19 ( V_10 , F_160 ( V_42 ) , V_244 ) ;
F_162 ( V_2 , V_37 ) ;
F_78 ( V_37 , F_50 ( V_37 ) ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_60 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_52 * V_40 = V_2 -> V_40 ;
F_158 ( V_2 ) ;
if ( V_10 -> V_194 . type >= V_263 )
F_163 ( V_2 ) ;
F_175 ( V_10 , V_40 -> V_264 + V_265 + V_266 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_167 ( V_2 , V_2 -> V_103 [ V_60 ] ) ;
}
static int F_176 ( struct V_52 * V_40 ,
T_9 V_267 , T_6 V_105 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_212 ;
F_177 ( & V_2 -> V_268 ) ;
V_212 = V_10 -> V_194 . V_269 . V_270 ( V_10 , V_105 , 0 , true ) ;
F_178 ( & V_2 -> V_268 ) ;
if ( V_212 == V_271 )
return - V_272 ;
if ( V_212 == V_273 )
return - V_274 ;
F_179 ( V_105 , V_2 -> V_108 ) ;
return V_212 ;
}
static int F_180 ( struct V_52 * V_40 ,
T_9 V_267 , T_6 V_105 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_212 ;
F_177 ( & V_2 -> V_268 ) ;
V_212 = V_10 -> V_194 . V_269 . V_270 ( V_10 , V_105 , 0 , false ) ;
F_178 ( & V_2 -> V_268 ) ;
F_8 ( V_105 , V_2 -> V_108 ) ;
return V_212 ;
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
return - V_275 ;
}
if ( ! F_185 ( V_40 ) ) {
struct V_276 * V_277 ;
F_186 (ha, netdev) {
V_10 -> V_194 . V_269 . V_278 ( V_10 , ++ V_44 , V_277 -> V_279 ) ;
F_161 ( 200 ) ;
}
} else {
V_10 -> V_194 . V_269 . V_278 ( V_10 , 0 , NULL ) ;
}
return V_44 ;
}
static void F_187 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_50 = V_40 -> V_50 ;
int V_280 ;
V_280 = ( V_50 & V_281 ) ? V_282 :
( V_50 & ( V_283 | V_284 ) ) ?
V_285 : V_286 ;
F_177 ( & V_2 -> V_268 ) ;
V_10 -> V_194 . V_269 . V_287 ( V_10 , V_40 , V_280 ) ;
V_10 -> V_194 . V_269 . V_288 ( V_10 , V_40 ) ;
F_183 ( V_40 ) ;
F_178 ( & V_2 -> V_268 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
int V_289 ;
struct V_53 * V_54 ;
int V_174 = V_2 -> V_175 - V_176 ;
for ( V_289 = 0 ; V_289 < V_174 ; V_289 ++ ) {
V_54 = V_2 -> V_54 [ V_289 ] ;
#ifdef F_55
F_189 ( V_2 -> V_54 [ V_289 ] ) ;
#endif
F_190 ( & V_54 -> V_78 ) ;
}
}
static void F_191 ( struct V_1 * V_2 )
{
int V_289 ;
struct V_53 * V_54 ;
int V_174 = V_2 -> V_175 - V_176 ;
for ( V_289 = 0 ; V_289 < V_174 ; V_289 ++ ) {
V_54 = V_2 -> V_54 [ V_289 ] ;
F_192 ( & V_54 -> V_78 ) ;
#ifdef F_55
while ( ! F_193 ( V_2 -> V_54 [ V_289 ] ) ) {
F_194 ( L_23 , V_289 ) ;
F_154 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_195 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_290 = 0 ;
unsigned int V_291 = 0 ;
unsigned int V_205 = V_2 -> V_205 ;
unsigned int V_207 = V_2 -> V_207 ;
int V_212 ;
F_177 ( & V_2 -> V_268 ) ;
V_212 = F_196 ( V_10 , & V_291 , & V_290 ) ;
F_178 ( & V_2 -> V_268 ) ;
if ( V_212 )
return V_212 ;
if ( V_291 > 1 ) {
V_207 = 1 ;
V_2 -> V_29 [ 0 ] -> V_42 = V_290 ;
V_205 = V_291 ;
}
if ( ( V_2 -> V_205 != V_205 ) ||
( V_2 -> V_207 != V_207 ) ) {
V_10 -> V_292 . V_293 = 0 ;
V_2 -> V_50 |= V_294 ;
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
if ( V_2 -> V_38 . V_295 || V_2 -> V_38 . V_296 ) {
V_2 -> V_38 . V_297 += V_2 -> V_38 . V_295 -
V_2 -> V_38 . V_298 ;
V_2 -> V_38 . V_299 += V_2 -> V_38 . V_296 -
V_2 -> V_38 . V_300 ;
V_2 -> V_38 . V_301 += V_2 -> V_38 . V_302 -
V_2 -> V_38 . V_303 ;
V_2 -> V_38 . V_304 += V_2 -> V_38 . V_305 -
V_2 -> V_38 . V_306 ;
V_2 -> V_38 . V_307 += V_2 -> V_38 . V_308 -
V_2 -> V_38 . V_309 ;
}
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
V_2 -> V_38 . V_310 = F_18 ( V_10 , V_311 ) ;
V_2 -> V_38 . V_312 = F_18 ( V_10 , V_313 ) ;
V_2 -> V_38 . V_312 |=
( ( ( T_5 ) ( F_18 ( V_10 , V_314 ) ) ) << 32 ) ;
V_2 -> V_38 . V_315 = F_18 ( V_10 , V_316 ) ;
V_2 -> V_38 . V_317 = F_18 ( V_10 , V_318 ) ;
V_2 -> V_38 . V_317 |=
( ( ( T_5 ) ( F_18 ( V_10 , V_319 ) ) ) << 32 ) ;
V_2 -> V_38 . V_320 = F_18 ( V_10 , V_321 ) ;
V_2 -> V_38 . V_298 = V_2 -> V_38 . V_310 ;
V_2 -> V_38 . V_303 = V_2 -> V_38 . V_312 ;
V_2 -> V_38 . V_300 = V_2 -> V_38 . V_315 ;
V_2 -> V_38 . V_306 = V_2 -> V_38 . V_317 ;
V_2 -> V_38 . V_309 = V_2 -> V_38 . V_320 ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_322 [] = { V_323 ,
V_324 ,
V_325 ,
V_326 } ;
int V_212 , V_327 = 0 ;
F_177 ( & V_2 -> V_268 ) ;
while ( V_322 [ V_327 ] != V_326 ) {
V_212 = F_201 ( V_10 , V_322 [ V_327 ] ) ;
if ( ! V_212 )
break;
V_327 ++ ;
}
F_178 ( & V_2 -> V_268 ) ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
F_125 ( V_2 ) ;
F_177 ( & V_2 -> V_268 ) ;
if ( F_203 ( V_10 -> V_194 . V_279 ) )
V_10 -> V_194 . V_269 . V_328 ( V_10 , 0 , V_10 -> V_194 . V_279 , 0 ) ;
else
V_10 -> V_194 . V_269 . V_328 ( V_10 , 0 , V_10 -> V_194 . V_329 , 0 ) ;
F_178 ( & V_2 -> V_268 ) ;
F_7 () ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_188 ( V_2 ) ;
F_18 ( V_10 , V_330 ) ;
F_144 ( V_2 ) ;
F_204 ( V_40 ) ;
F_198 ( V_2 ) ;
F_199 ( V_2 ) ;
V_10 -> V_194 . V_195 = 1 ;
F_205 ( & V_2 -> V_331 , V_75 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
F_197 ( V_2 ) ;
F_202 ( V_2 ) ;
}
static void F_207 ( struct V_28 * V_103 )
{
struct V_332 * V_14 = V_103 -> V_14 ;
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
memset ( V_103 -> V_333 , 0 , V_103 -> V_136 ) ;
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
memset ( V_29 -> V_333 , 0 , V_29 -> V_136 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_207 ( V_2 -> V_103 [ V_60 ] ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
F_209 ( V_2 -> V_29 [ V_60 ] ) ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_159 ( V_2 , V_2 -> V_103 [ V_60 ] ) ;
F_154 ( 10000 , 20000 ) ;
F_213 ( V_40 ) ;
F_214 ( V_40 ) ;
F_215 ( V_40 ) ;
F_141 ( V_2 ) ;
F_191 ( V_2 ) ;
F_216 ( & V_2 -> V_331 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
T_2 V_42 = V_2 -> V_29 [ V_60 ] -> V_42 ;
F_19 ( V_10 , F_146 ( V_42 ) ,
V_227 ) ;
}
if ( ! F_217 ( V_2 -> V_13 ) )
F_218 ( V_2 ) ;
F_211 ( V_2 ) ;
F_210 ( V_2 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
F_220 ( F_221 () ) ;
while ( F_3 ( V_334 , & V_2 -> V_4 ) )
F_222 ( 1 ) ;
F_212 ( V_2 ) ;
F_206 ( V_2 ) ;
F_8 ( V_334 , & V_2 -> V_4 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_52 * V_40 = V_2 -> V_40 ;
if ( V_10 -> V_194 . V_269 . V_335 ( V_10 ) ) {
F_136 ( V_10 , L_24 ) ;
} else {
V_10 -> V_194 . V_269 . V_336 ( V_10 ) ;
F_200 ( V_2 ) ;
}
if ( F_203 ( V_2 -> V_10 . V_194 . V_279 ) ) {
F_223 ( V_40 -> V_156 , V_2 -> V_10 . V_194 . V_279 ) ;
F_223 ( V_40 -> V_329 , V_2 -> V_10 . V_194 . V_279 ) ;
}
V_2 -> V_337 = V_75 ;
}
static int F_224 ( struct V_1 * V_2 ,
int V_338 )
{
int V_339 ;
V_339 = V_340 ;
V_338 = F_225 ( V_2 -> V_13 , V_2 -> V_217 ,
V_339 , V_338 ) ;
if ( V_338 < 0 ) {
F_10 ( & V_2 -> V_13 -> V_14 ,
L_25 ) ;
F_226 ( V_2 -> V_217 ) ;
V_2 -> V_217 = NULL ;
return V_338 ;
}
V_2 -> V_175 = V_338 ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_290 = 0 ;
unsigned int V_291 = 0 ;
int V_212 ;
V_2 -> V_205 = 1 ;
V_2 -> V_207 = 1 ;
F_177 ( & V_2 -> V_268 ) ;
V_212 = F_196 ( V_10 , & V_291 , & V_290 ) ;
F_178 ( & V_2 -> V_268 ) ;
if ( V_212 )
return;
if ( V_291 > 1 ) {
V_2 -> V_205 = V_291 ;
} else {
T_6 V_90 = F_228 ( T_6 , F_229 () , V_341 ) ;
switch ( V_10 -> V_342 ) {
case V_324 :
case V_323 :
V_2 -> V_205 = V_90 ;
V_2 -> V_207 = V_90 ;
default:
break;
}
}
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_28 * V_37 ;
int V_158 = 0 , V_71 = 0 ;
for (; V_71 < V_2 -> V_207 ; V_71 ++ ) {
V_37 = F_231 ( sizeof( * V_37 ) , V_343 ) ;
if ( ! V_37 )
goto V_344;
V_37 -> V_14 = & V_2 -> V_13 -> V_14 ;
V_37 -> V_40 = V_2 -> V_40 ;
V_37 -> V_44 = V_2 -> V_345 ;
V_37 -> V_72 = V_71 ;
V_37 -> V_42 = V_71 ;
V_2 -> V_29 [ V_71 ] = V_37 ;
}
for (; V_158 < V_2 -> V_205 ; V_158 ++ ) {
V_37 = F_231 ( sizeof( * V_37 ) , V_343 ) ;
if ( ! V_37 )
goto V_344;
V_37 -> V_14 = & V_2 -> V_13 -> V_14 ;
V_37 -> V_40 = V_2 -> V_40 ;
V_37 -> V_44 = V_2 -> V_346 ;
V_37 -> V_72 = V_158 ;
V_37 -> V_42 = V_158 ;
V_2 -> V_103 [ V_158 ] = V_37 ;
}
return 0 ;
V_344:
while ( V_71 ) {
F_226 ( V_2 -> V_29 [ -- V_71 ] ) ;
V_2 -> V_29 [ V_71 ] = NULL ;
}
while ( V_158 ) {
F_226 ( V_2 -> V_103 [ -- V_158 ] ) ;
V_2 -> V_103 [ V_158 ] = NULL ;
}
return - V_347 ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
int V_212 ;
int V_211 , V_348 ;
V_348 = F_115 ( V_2 -> V_205 , V_2 -> V_207 ) ;
V_348 = F_228 ( int , V_348 , F_229 () ) ;
V_348 += V_176 ;
V_2 -> V_217 = F_233 ( V_348 ,
sizeof( struct V_215 ) , V_343 ) ;
if ( ! V_2 -> V_217 )
return - V_347 ;
for ( V_211 = 0 ; V_211 < V_348 ; V_211 ++ )
V_2 -> V_217 [ V_211 ] . V_216 = V_211 ;
V_212 = F_224 ( V_2 , V_348 ) ;
if ( V_212 )
return V_212 ;
V_212 = F_234 ( V_40 , V_2 -> V_207 ) ;
if ( V_212 )
return V_212 ;
return F_235 ( V_40 , V_2 -> V_205 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
int V_289 , V_349 ;
struct V_53 * V_54 ;
V_349 = V_2 -> V_175 - V_176 ;
for ( V_289 = 0 ; V_289 < V_349 ; V_289 ++ ) {
V_54 = F_231 ( sizeof( struct V_53 ) , V_343 ) ;
if ( ! V_54 )
goto V_350;
V_54 -> V_2 = V_2 ;
V_54 -> V_165 = V_289 ;
F_237 ( V_2 -> V_40 , & V_54 -> V_78 ,
F_111 , 64 ) ;
V_2 -> V_54 [ V_289 ] = V_54 ;
}
return 0 ;
V_350:
while ( V_289 ) {
V_289 -- ;
V_54 = V_2 -> V_54 [ V_289 ] ;
#ifdef F_55
F_238 ( & V_54 -> V_78 ) ;
#endif
F_239 ( & V_54 -> V_78 ) ;
F_226 ( V_54 ) ;
V_2 -> V_54 [ V_289 ] = NULL ;
}
return - V_347 ;
}
static void F_240 ( struct V_1 * V_2 )
{
int V_289 , V_349 = V_2 -> V_175 - V_176 ;
for ( V_289 = 0 ; V_289 < V_349 ; V_289 ++ ) {
struct V_53 * V_54 = V_2 -> V_54 [ V_289 ] ;
V_2 -> V_54 [ V_289 ] = NULL ;
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
F_226 ( V_2 -> V_217 ) ;
V_2 -> V_217 = NULL ;
}
static int F_243 ( struct V_1 * V_2 )
{
int V_212 ;
F_227 ( V_2 ) ;
V_212 = F_232 ( V_2 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_10 ,
L_26 ) ;
goto V_351;
}
V_212 = F_236 ( V_2 ) ;
if ( V_212 ) {
F_136 ( & V_2 -> V_10 , L_27 ) ;
goto V_352;
}
V_212 = F_230 ( V_2 ) ;
if ( V_212 ) {
F_46 ( L_28 ) ;
goto V_353;
}
F_136 ( & V_2 -> V_10 , L_29 ,
( V_2 -> V_205 > 1 ) ? L_30 :
L_31 , V_2 -> V_205 , V_2 -> V_207 ) ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_353:
F_240 ( V_2 ) ;
V_352:
F_241 ( V_2 ) ;
V_351:
return V_212 ;
}
static void F_244 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
F_226 ( V_2 -> V_29 [ V_60 ] ) ;
V_2 -> V_29 [ V_60 ] = NULL ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
F_226 ( V_2 -> V_103 [ V_60 ] ) ;
V_2 -> V_103 [ V_60 ] = NULL ;
}
V_2 -> V_207 = 0 ;
V_2 -> V_205 = 0 ;
F_240 ( V_2 ) ;
F_241 ( V_2 ) ;
}
static int F_245 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_354 * V_13 = V_2 -> V_13 ;
struct V_52 * V_40 = V_2 -> V_40 ;
int V_212 ;
V_10 -> V_355 = V_13 -> V_356 ;
V_10 -> V_357 = V_13 -> V_332 ;
V_10 -> V_358 = V_13 -> V_359 ;
V_10 -> V_360 = V_13 -> V_361 ;
V_10 -> V_362 = V_13 -> V_363 ;
V_10 -> V_292 . V_269 . V_364 ( V_10 ) ;
V_10 -> V_194 . V_365 = 2 ;
V_10 -> V_194 . V_366 = 2 ;
F_246 ( & V_2 -> V_268 ) ;
V_212 = V_10 -> V_194 . V_269 . V_335 ( V_10 ) ;
if ( V_212 ) {
F_247 ( & V_13 -> V_14 ,
L_32 ) ;
} else {
V_212 = V_10 -> V_194 . V_269 . V_336 ( V_10 ) ;
if ( V_212 ) {
F_46 ( L_33 , V_212 ) ;
goto V_367;
}
F_200 ( V_2 ) ;
V_212 = V_10 -> V_194 . V_269 . V_368 ( V_10 , V_10 -> V_194 . V_279 ) ;
if ( V_212 )
F_247 ( & V_13 -> V_14 , L_34 ) ;
else if ( F_248 ( V_2 -> V_10 . V_194 . V_279 ) )
F_247 ( & V_13 -> V_14 ,
L_35 ) ;
F_223 ( V_40 -> V_156 , V_10 -> V_194 . V_279 ) ;
}
if ( ! F_203 ( V_40 -> V_156 ) ) {
F_247 ( & V_13 -> V_14 , L_36 ) ;
F_249 ( V_40 ) ;
F_223 ( V_10 -> V_194 . V_279 , V_40 -> V_156 ) ;
F_223 ( V_10 -> V_194 . V_329 , V_40 -> V_156 ) ;
}
V_2 -> V_164 = 1 ;
V_2 -> V_178 = 1 ;
V_2 -> V_345 = V_369 ;
V_2 -> V_346 = V_370 ;
F_179 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_367:
return V_212 ;
}
void F_250 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_334 , & V_2 -> V_4 ) )
return;
F_251 ( V_311 , V_2 -> V_38 . V_310 ,
V_2 -> V_38 . V_295 ) ;
F_251 ( V_316 , V_2 -> V_38 . V_315 ,
V_2 -> V_38 . V_296 ) ;
F_252 ( V_313 , V_314 ,
V_2 -> V_38 . V_312 ,
V_2 -> V_38 . V_302 ) ;
F_252 ( V_318 , V_319 ,
V_2 -> V_38 . V_317 ,
V_2 -> V_38 . V_305 ) ;
F_251 ( V_321 , V_2 -> V_38 . V_320 ,
V_2 -> V_38 . V_308 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
V_2 -> V_371 +=
V_2 -> V_103 [ V_60 ] -> V_371 ;
V_2 -> V_103 [ V_60 ] -> V_371 = 0 ;
}
}
static void F_253 ( unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_146 ;
F_205 ( & V_2 -> V_331 , ( V_372 * 2 ) + V_75 ) ;
F_1 ( V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_50 & V_51 ) )
return;
V_2 -> V_50 &= ~ V_51 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_334 , & V_2 -> V_4 ) )
return;
V_2 -> V_373 ++ ;
F_219 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_374 = 0 ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_334 , & V_2 -> V_4 ) )
return;
if ( F_49 ( V_2 -> V_40 ) ) {
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
F_256 ( V_2 -> V_29 [ V_60 ] ) ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_175 - V_176 ; V_60 ++ ) {
struct V_53 * V_375 = V_2 -> V_54 [ V_60 ] ;
if ( V_375 -> V_158 . V_37 || V_375 -> V_71 . V_37 )
V_374 |= 1 << V_60 ;
}
F_19 ( V_10 , V_376 , V_374 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_377 = V_2 -> V_377 ;
bool V_378 = V_2 -> V_378 ;
T_10 V_212 ;
F_177 ( & V_2 -> V_268 ) ;
V_212 = V_10 -> V_194 . V_269 . V_379 ( V_10 , & V_377 , & V_378 , false ) ;
F_178 ( & V_2 -> V_268 ) ;
if ( V_212 && F_258 ( V_75 , V_2 -> V_337 + ( 10 * V_372 ) ) ) {
V_2 -> V_50 |= V_51 ;
V_378 = false ;
}
V_2 -> V_378 = V_378 ;
V_2 -> V_377 = V_377 ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
if ( F_49 ( V_40 ) )
return;
F_247 ( & V_2 -> V_13 -> V_14 , L_37 ,
( V_2 -> V_377 == V_380 ) ?
L_38 :
( V_2 -> V_377 == V_381 ) ?
L_39 :
( V_2 -> V_377 == V_382 ) ?
L_40 :
L_41 ) ;
F_260 ( V_40 ) ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_52 * V_40 = V_2 -> V_40 ;
V_2 -> V_377 = 0 ;
if ( ! F_49 ( V_40 ) )
return;
F_247 ( & V_2 -> V_13 -> V_14 , L_42 ) ;
F_214 ( V_40 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_334 , & V_2 -> V_4 ) )
return;
F_257 ( V_2 ) ;
if ( V_2 -> V_378 )
F_259 ( V_2 ) ;
else
F_261 ( V_2 ) ;
F_250 ( V_2 ) ;
}
static void F_263 ( struct V_383 * V_384 )
{
struct V_1 * V_2 = F_112 ( V_384 ,
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
if ( ! V_29 -> V_333 )
return;
F_269 ( V_29 -> V_14 , V_29 -> V_136 , V_29 -> V_333 ,
V_29 -> V_34 ) ;
V_29 -> V_333 = NULL ;
}
static void F_270 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
if ( V_2 -> V_29 [ V_60 ] -> V_333 )
F_267 ( V_2 -> V_29 [ V_60 ] ) ;
}
int F_271 ( struct V_28 * V_29 )
{
int V_136 ;
V_136 = sizeof( struct V_30 ) * V_29 -> V_44 ;
V_29 -> V_62 = F_272 ( V_136 ) ;
if ( ! V_29 -> V_62 )
goto V_212;
V_29 -> V_136 = V_29 -> V_44 * sizeof( union V_55 ) ;
V_29 -> V_136 = F_92 ( V_29 -> V_136 , 4096 ) ;
V_29 -> V_333 = F_273 ( V_29 -> V_14 , V_29 -> V_136 ,
& V_29 -> V_34 , V_343 ) ;
if ( ! V_29 -> V_333 )
goto V_212;
return 0 ;
V_212:
F_268 ( V_29 -> V_62 ) ;
V_29 -> V_62 = NULL ;
F_136 ( & V_2 -> V_10 , L_43 ) ;
return - V_347 ;
}
static int F_274 ( struct V_1 * V_2 )
{
int V_60 , V_212 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
V_212 = F_271 ( V_2 -> V_29 [ V_60 ] ) ;
if ( ! V_212 )
continue;
F_136 ( & V_2 -> V_10 , L_44 , V_60 ) ;
break;
}
return V_212 ;
}
int F_275 ( struct V_28 * V_103 )
{
int V_136 ;
V_136 = sizeof( struct V_114 ) * V_103 -> V_44 ;
V_103 -> V_123 = F_272 ( V_136 ) ;
if ( ! V_103 -> V_123 )
goto V_212;
V_103 -> V_136 = V_103 -> V_44 * sizeof( union V_79 ) ;
V_103 -> V_136 = F_92 ( V_103 -> V_136 , 4096 ) ;
V_103 -> V_333 = F_273 ( V_103 -> V_14 , V_103 -> V_136 ,
& V_103 -> V_34 , V_343 ) ;
if ( ! V_103 -> V_333 )
goto V_212;
return 0 ;
V_212:
F_268 ( V_103 -> V_123 ) ;
V_103 -> V_123 = NULL ;
F_10 ( V_103 -> V_14 , L_45 ) ;
return - V_347 ;
}
static int F_276 ( struct V_1 * V_2 )
{
int V_60 , V_212 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
V_212 = F_275 ( V_2 -> V_103 [ V_60 ] ) ;
if ( ! V_212 )
continue;
F_136 ( & V_2 -> V_10 , L_46 , V_60 ) ;
break;
}
return V_212 ;
}
void F_277 ( struct V_28 * V_103 )
{
F_207 ( V_103 ) ;
F_268 ( V_103 -> V_123 ) ;
V_103 -> V_123 = NULL ;
F_269 ( V_103 -> V_14 , V_103 -> V_136 , V_103 -> V_333 ,
V_103 -> V_34 ) ;
V_103 -> V_333 = NULL ;
}
static void F_278 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
if ( V_2 -> V_103 [ V_60 ] -> V_333 )
F_277 ( V_2 -> V_103 [ V_60 ] ) ;
}
int F_279 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_212 ;
if ( ! V_2 -> V_175 )
return - V_347 ;
if ( V_10 -> V_385 ) {
F_218 ( V_2 ) ;
if ( V_10 -> V_385 ) {
V_212 = V_271 ;
F_46 ( L_47 ) ;
goto V_386;
}
}
if ( F_2 ( V_387 , & V_2 -> V_4 ) )
return - V_388 ;
F_214 ( V_40 ) ;
V_212 = F_274 ( V_2 ) ;
if ( V_212 )
goto V_389;
V_212 = F_276 ( V_2 ) ;
if ( V_212 )
goto V_390;
F_197 ( V_2 ) ;
F_132 ( V_2 ) ;
V_212 = F_139 ( V_2 ) ;
if ( V_212 )
goto V_391;
F_202 ( V_2 ) ;
return 0 ;
V_391:
F_212 ( V_2 ) ;
V_390:
F_278 ( V_2 ) ;
V_389:
F_270 ( V_2 ) ;
F_218 ( V_2 ) ;
V_386:
return V_212 ;
}
int F_280 ( struct V_52 * V_40 )
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
if ( ! ( V_2 -> V_50 & V_294 ) )
return;
V_2 -> V_50 &= ~ V_294 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_334 , & V_2 -> V_4 ) )
return;
if ( F_281 ( V_14 ) )
F_280 ( V_14 ) ;
F_244 ( V_2 ) ;
F_243 ( V_2 ) ;
if ( F_281 ( V_14 ) )
F_279 ( V_14 ) ;
}
static void F_282 ( struct V_28 * V_29 ,
T_1 V_392 , T_1 V_393 ,
T_1 V_394 )
{
struct V_395 * V_396 ;
T_6 V_60 = V_29 -> V_73 ;
V_396 = F_283 ( V_29 , V_60 ) ;
V_60 ++ ;
V_29 -> V_73 = ( V_60 < V_29 -> V_44 ) ? V_60 : 0 ;
V_393 |= V_397 | V_398 ;
V_396 -> V_392 = F_40 ( V_392 ) ;
V_396 -> V_399 = 0 ;
V_396 -> V_400 = F_40 ( V_393 ) ;
V_396 -> V_394 = F_40 ( V_394 ) ;
}
static int F_284 ( struct V_28 * V_29 ,
struct V_30 * V_401 ,
T_2 * V_402 )
{
struct V_77 * V_32 = V_401 -> V_32 ;
T_1 V_392 , V_393 ;
T_1 V_394 , V_403 ;
int V_212 ;
if ( V_32 -> V_101 != V_404 )
return 0 ;
if ( ! F_285 ( V_32 ) )
return 0 ;
V_212 = F_286 ( V_32 , 0 ) ;
if ( V_212 < 0 )
return V_212 ;
V_393 = V_405 ;
if ( V_401 -> V_111 == F_69 ( V_406 ) ) {
struct V_407 * V_408 = F_287 ( V_32 ) ;
V_408 -> V_409 = 0 ;
V_408 -> V_410 = 0 ;
F_288 ( V_32 ) -> V_410 = ~ F_289 ( V_408 -> V_411 ,
V_408 -> V_412 , 0 ,
V_413 ,
0 ) ;
V_393 |= V_414 ;
V_401 -> V_415 |= V_416 |
V_417 |
V_418 ;
} else if ( F_290 ( V_32 ) ) {
F_291 ( V_32 ) -> V_419 = 0 ;
F_288 ( V_32 ) -> V_410 =
~ F_292 ( & F_291 ( V_32 ) -> V_411 ,
& F_291 ( V_32 ) -> V_412 ,
0 , V_413 , 0 ) ;
V_401 -> V_415 |= V_416 |
V_417 ;
}
V_403 = F_293 ( V_32 ) ;
* V_402 += V_403 ;
* V_402 = F_294 ( V_32 ) + V_403 ;
V_401 -> V_68 = F_98 ( V_32 ) -> V_68 ;
V_401 -> V_67 += ( V_401 -> V_68 - 1 ) * * V_402 ;
V_394 = V_403 << V_420 ;
V_394 |= F_98 ( V_32 ) -> V_421 << V_422 ;
V_394 |= 1 << V_423 ;
V_392 = F_295 ( V_32 ) ;
V_392 |= F_296 ( V_32 ) << V_424 ;
V_392 |= V_401 -> V_415 & V_425 ;
F_282 ( V_29 , V_392 ,
V_393 , V_394 ) ;
return 1 ;
}
static void F_297 ( struct V_28 * V_29 ,
struct V_30 * V_401 )
{
struct V_77 * V_32 = V_401 -> V_32 ;
T_1 V_392 = 0 ;
T_1 V_394 = 0 ;
T_1 V_393 = 0 ;
if ( V_32 -> V_101 == V_404 ) {
T_2 V_426 = 0 ;
T_9 V_427 ;
switch ( V_401 -> V_111 ) {
case F_69 ( V_406 ) :
V_392 |= F_295 ( V_32 ) ;
V_393 |= V_414 ;
V_426 = F_287 ( V_32 ) -> V_111 ;
break;
case F_69 ( V_428 ) :
V_392 |= F_295 ( V_32 ) ;
V_426 = F_291 ( V_32 ) -> V_429 ;
if ( F_42 ( F_295 ( V_32 ) ==
sizeof( struct V_430 ) ) )
break;
F_298 ( V_32 , F_296 ( V_32 ) +
sizeof( struct V_430 ) ,
& V_426 , & V_427 ) ;
if ( F_16 ( V_427 ) )
V_426 = V_431 ;
break;
default:
break;
}
switch ( V_426 ) {
case V_413 :
V_393 |= V_405 ;
V_394 = F_293 ( V_32 ) <<
V_420 ;
break;
case V_432 :
V_393 |= V_433 ;
V_394 = sizeof( struct V_434 ) <<
V_420 ;
break;
case V_435 :
V_394 = sizeof( struct V_436 ) <<
V_420 ;
break;
default:
if ( F_16 ( F_299 () ) ) {
F_300 ( V_29 -> V_14 ,
L_48 ,
V_401 -> V_111 , V_426 ) ;
}
F_301 ( V_32 ) ;
goto V_437;
}
V_401 -> V_415 |= V_417 ;
}
V_437:
V_392 |= F_296 ( V_32 ) << V_424 ;
V_392 |= V_401 -> V_415 & V_425 ;
F_282 ( V_29 , V_392 ,
V_393 , V_394 ) ;
}
static T_11 F_302 ( T_1 V_415 )
{
T_11 V_438 = F_40 ( V_439 |
V_440 |
V_441 ) ;
if ( V_415 & V_442 )
V_438 |= F_40 ( V_443 ) ;
if ( V_415 & V_416 )
V_438 |= F_40 ( V_444 ) ;
return V_438 ;
}
static void F_303 ( union V_55 * V_56 ,
T_1 V_415 , unsigned int V_445 )
{
T_11 V_446 = F_40 ( V_445 << V_447 ) ;
if ( V_415 & V_417 )
V_446 |= F_40 ( V_448 ) ;
if ( V_415 & V_418 )
V_446 |= F_40 ( V_449 ) ;
if ( V_415 & V_416 )
V_446 |= F_40 ( 1 << V_423 ) ;
V_446 |= F_40 ( V_450 ) ;
V_56 -> V_124 . V_446 = V_446 ;
}
static void F_304 ( struct V_28 * V_29 ,
struct V_30 * V_401 ,
const T_2 V_402 )
{
T_7 V_34 ;
struct V_77 * V_32 = V_401 -> V_32 ;
struct V_30 * V_31 ;
union V_55 * V_56 ;
struct V_451 * V_452 = & F_98 ( V_32 ) -> V_453 [ 0 ] ;
unsigned int V_454 = V_32 -> V_454 ;
unsigned int V_136 = F_305 ( V_32 ) ;
unsigned int V_445 = V_32 -> V_33 - V_402 ;
T_1 V_415 = V_401 -> V_415 ;
T_11 V_438 ;
T_6 V_60 = V_29 -> V_73 ;
V_56 = F_38 ( V_29 , V_60 ) ;
F_303 ( V_56 , V_415 , V_445 ) ;
V_438 = F_302 ( V_415 ) ;
V_34 = F_306 ( V_29 -> V_14 , V_32 -> V_146 , V_136 , V_35 ) ;
if ( F_76 ( V_29 -> V_14 , V_34 ) )
goto V_455;
F_27 ( V_401 , V_33 , V_136 ) ;
F_307 ( V_401 , V_34 , V_34 ) ;
V_56 -> V_124 . V_456 = F_79 ( V_34 ) ;
for (; ; ) {
while ( F_16 ( V_136 > V_457 ) ) {
V_56 -> V_124 . V_458 =
V_438 | F_40 ( V_457 ) ;
V_60 ++ ;
V_56 ++ ;
if ( V_60 == V_29 -> V_44 ) {
V_56 = F_38 ( V_29 , 0 ) ;
V_60 = 0 ;
}
V_34 += V_457 ;
V_136 -= V_457 ;
V_56 -> V_124 . V_456 = F_79 ( V_34 ) ;
V_56 -> V_124 . V_446 = 0 ;
}
if ( F_42 ( ! V_454 ) )
break;
V_56 -> V_124 . V_458 = V_438 | F_40 ( V_136 ) ;
V_60 ++ ;
V_56 ++ ;
if ( V_60 == V_29 -> V_44 ) {
V_56 = F_38 ( V_29 , 0 ) ;
V_60 = 0 ;
}
V_136 = F_308 ( V_452 ) ;
V_454 -= V_136 ;
V_34 = F_309 ( V_29 -> V_14 , V_452 , 0 , V_136 ,
V_35 ) ;
if ( F_76 ( V_29 -> V_14 , V_34 ) )
goto V_455;
V_31 = & V_29 -> V_62 [ V_60 ] ;
F_27 ( V_31 , V_33 , V_136 ) ;
F_307 ( V_31 , V_34 , V_34 ) ;
V_56 -> V_124 . V_456 = F_79 ( V_34 ) ;
V_56 -> V_124 . V_446 = 0 ;
V_452 ++ ;
}
V_438 |= F_40 ( V_136 ) | F_40 ( V_459 ) ;
V_56 -> V_124 . V_458 = V_438 ;
V_401 -> V_74 = V_75 ;
F_80 () ;
V_401 -> V_36 = V_56 ;
V_60 ++ ;
if ( V_60 == V_29 -> V_44 )
V_60 = 0 ;
V_29 -> V_73 = V_60 ;
F_81 ( V_29 , V_60 ) ;
return;
V_455:
F_10 ( V_29 -> V_14 , L_49 ) ;
for (; ; ) {
V_31 = & V_29 -> V_62 [ V_60 ] ;
F_21 ( V_29 , V_31 ) ;
if ( V_31 == V_401 )
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
return - V_388 ;
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
struct V_30 * V_401 ;
struct V_28 * V_29 ;
int V_460 ;
T_1 V_415 = 0 ;
T_6 V_44 = F_314 ( F_305 ( V_32 ) ) ;
#if V_118 > V_457
unsigned short V_461 ;
#endif
T_2 V_402 = 0 ;
T_2 * V_462 = F_315 ( V_32 , 0 , 0 , NULL ) ;
if ( ! V_462 || F_316 ( V_462 ) ) {
F_22 ( V_32 ) ;
return V_463 ;
}
V_29 = V_2 -> V_29 [ V_32 -> V_464 ] ;
#if V_118 > V_457
for ( V_461 = 0 ; V_461 < F_98 ( V_32 ) -> V_143 ; V_461 ++ )
V_44 += F_314 ( F_98 ( V_32 ) -> V_453 [ V_461 ] . V_136 ) ;
#else
V_44 += F_98 ( V_32 ) -> V_143 ;
#endif
if ( F_312 ( V_29 , V_44 + 3 ) ) {
V_29 -> V_47 . V_465 ++ ;
return V_466 ;
}
V_401 = & V_29 -> V_62 [ V_29 -> V_73 ] ;
V_401 -> V_32 = V_32 ;
V_401 -> V_67 = V_32 -> V_33 ;
V_401 -> V_68 = 1 ;
if ( F_317 ( V_32 ) ) {
V_415 |= F_318 ( V_32 ) ;
V_415 <<= V_467 ;
V_415 |= V_442 ;
}
V_401 -> V_415 = V_415 ;
V_401 -> V_111 = F_319 ( V_32 ) ;
V_460 = F_284 ( V_29 , V_401 , & V_402 ) ;
if ( V_460 < 0 )
goto V_468;
else if ( ! V_460 )
F_297 ( V_29 , V_401 ) ;
F_304 ( V_29 , V_401 , V_402 ) ;
F_312 ( V_29 , V_469 ) ;
return V_463 ;
V_468:
F_22 ( V_401 -> V_32 ) ;
V_401 -> V_32 = NULL ;
return V_463 ;
}
static int F_320 ( struct V_52 * V_40 , void * V_470 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_471 * V_279 = V_470 ;
int V_212 ;
if ( ! F_203 ( V_279 -> V_472 ) )
return - V_473 ;
F_177 ( & V_2 -> V_268 ) ;
V_212 = V_10 -> V_194 . V_269 . V_328 ( V_10 , 0 , V_279 -> V_472 , 0 ) ;
F_178 ( & V_2 -> V_268 ) ;
if ( V_212 )
return - V_474 ;
F_223 ( V_10 -> V_194 . V_279 , V_279 -> V_472 ) ;
F_223 ( V_40 -> V_156 , V_279 -> V_472 ) ;
return 0 ;
}
static int F_321 ( struct V_52 * V_40 , int V_475 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_476 = V_475 + V_265 + V_266 ;
int V_477 = V_478 ;
switch ( V_2 -> V_10 . V_342 ) {
case V_324 :
case V_323 :
V_477 = V_479 ;
break;
default:
if ( V_2 -> V_10 . V_194 . type != V_480 )
V_477 = V_479 ;
break;
}
if ( ( V_475 < 68 ) || ( V_476 > V_477 ) )
return - V_481 ;
F_136 ( V_10 , L_50 ,
V_40 -> V_264 , V_475 ) ;
V_40 -> V_264 = V_475 ;
F_175 ( V_10 , V_476 ) ;
return 0 ;
}
static void F_322 ( struct V_52 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_128 ( 0 , V_2 -> V_54 [ V_60 ] ) ;
}
static int F_323 ( struct V_354 * V_13 , T_12 V_4 )
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
static int F_329 ( struct V_354 * V_13 )
{
struct V_52 * V_40 = F_324 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
T_1 V_212 ;
F_330 ( V_13 ) ;
F_327 ( V_13 ) ;
V_212 = F_331 ( V_13 ) ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_51 ) ;
return V_212 ;
}
F_7 () ;
F_8 ( V_483 , & V_2 -> V_4 ) ;
F_332 ( V_13 ) ;
F_218 ( V_2 ) ;
F_264 () ;
V_212 = F_243 ( V_2 ) ;
F_265 () ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_52 ) ;
return V_212 ;
}
if ( F_281 ( V_40 ) ) {
V_212 = F_279 ( V_40 ) ;
if ( V_212 )
return V_212 ;
}
F_333 ( V_40 ) ;
return V_212 ;
}
static void F_334 ( struct V_354 * V_13 )
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
V_38 -> V_487 = V_2 -> V_38 . V_308 - V_2 -> V_38 . V_309 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
V_37 = V_2 -> V_103 [ V_60 ] ;
do {
V_486 = F_336 ( & V_37 -> V_69 ) ;
V_70 = V_37 -> V_38 . V_70 ;
V_39 = V_37 -> V_38 . V_39 ;
} while ( F_337 ( & V_37 -> V_69 , V_486 ) );
V_38 -> V_488 += V_70 ;
V_38 -> V_489 += V_39 ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
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
V_14 -> V_494 = 5 * V_372 ;
}
static int F_340 ( struct V_354 * V_13 , const struct V_495 * V_496 )
{
struct V_52 * V_40 ;
struct V_1 * V_2 = NULL ;
struct V_9 * V_10 = NULL ;
const struct V_497 * V_498 = V_499 [ V_496 -> V_500 ] ;
int V_212 , V_501 ;
bool V_502 = false ;
V_212 = F_341 ( V_13 ) ;
if ( V_212 )
return V_212 ;
if ( ! F_342 ( & V_13 -> V_14 , F_148 ( 64 ) ) ) {
V_501 = 1 ;
} else {
V_212 = F_342 ( & V_13 -> V_14 , F_148 ( 32 ) ) ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_53 ) ;
goto V_503;
}
V_501 = 0 ;
}
V_212 = F_343 ( V_13 , V_504 ) ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_54 , V_212 ) ;
goto V_505;
}
F_332 ( V_13 ) ;
V_40 = F_344 ( sizeof( struct V_1 ) ,
V_506 ) ;
if ( ! V_40 ) {
V_212 = - V_347 ;
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
V_2 -> V_230 = V_10 -> V_12 ;
if ( ! V_10 -> V_12 ) {
V_212 = - V_272 ;
goto V_511;
}
F_338 ( V_40 ) ;
memcpy ( & V_10 -> V_194 . V_269 , V_498 -> V_512 , sizeof( V_10 -> V_194 . V_269 ) ) ;
V_10 -> V_194 . type = V_498 -> V_194 ;
memcpy ( & V_10 -> V_292 . V_269 , & V_513 ,
sizeof( struct V_514 ) ) ;
V_212 = F_245 ( V_2 ) ;
if ( V_212 )
goto V_515;
if ( ! F_203 ( V_40 -> V_156 ) ) {
F_46 ( L_55 ) ;
V_212 = - V_272 ;
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
V_212 = - V_272 ;
goto V_515;
}
F_350 ( & V_2 -> V_331 , & F_253 ,
( unsigned long ) V_2 ) ;
F_351 ( & V_2 -> V_8 , F_263 ) ;
F_179 ( V_15 , & V_2 -> V_4 ) ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
V_212 = F_243 ( V_2 ) ;
if ( V_212 )
goto V_515;
strcpy ( V_40 -> V_218 , L_56 ) ;
V_212 = F_352 ( V_40 ) ;
if ( V_212 )
goto V_529;
F_353 ( V_13 , V_40 ) ;
F_214 ( V_40 ) ;
F_199 ( V_2 ) ;
F_247 ( & V_13 -> V_14 , L_57 , V_40 -> V_156 ) ;
F_247 ( & V_13 -> V_14 , L_58 , V_10 -> V_194 . type ) ;
switch ( V_10 -> V_194 . type ) {
case V_263 :
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
F_354 ( V_2 -> V_230 ) ;
V_511:
V_502 = ! F_3 ( V_483 , & V_2 -> V_4 ) ;
F_355 ( V_40 ) ;
V_507:
F_356 ( V_13 ) ;
V_505:
V_503:
if ( ! V_2 || V_502 )
F_328 ( V_13 ) ;
return V_212 ;
}
static void F_357 ( struct V_354 * V_13 )
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
F_354 ( V_2 -> V_230 ) ;
F_356 ( V_13 ) ;
F_136 ( & V_2 -> V_10 , L_62 ) ;
V_502 = ! F_3 ( V_483 , & V_2 -> V_4 ) ;
F_355 ( V_40 ) ;
if ( V_502 )
F_328 ( V_13 ) ;
}
static T_13 F_360 ( struct V_354 * V_13 ,
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
static T_13 F_361 ( struct V_354 * V_13 )
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
static void F_362 ( struct V_354 * V_13 )
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
return - V_347 ;
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
return V_2 -> V_40 -> V_218 ;
}
