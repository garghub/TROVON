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
F_36 ( V_50 , & V_2 -> V_4 ) ;
F_1 ( V_2 ) ;
}
}
static void F_37 ( struct V_51 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
F_35 ( V_2 ) ;
}
static bool F_38 ( struct V_52 * V_53 ,
struct V_28 * V_29 , int V_54 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_30 * V_31 ;
union V_55 * V_56 ;
unsigned int V_57 = 0 , V_58 = 0 ;
unsigned int V_59 = V_29 -> V_44 / 2 ;
unsigned int V_60 = V_29 -> V_61 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return true ;
V_31 = & V_29 -> V_62 [ V_60 ] ;
V_56 = F_39 ( V_29 , V_60 ) ;
V_60 -= V_29 -> V_44 ;
do {
union V_55 * V_63 = V_31 -> V_36 ;
if ( ! V_63 )
break;
F_40 () ;
if ( ! ( V_63 -> V_64 . V_65 & F_41 ( V_66 ) ) )
break;
V_31 -> V_36 = NULL ;
V_57 += V_31 -> V_67 ;
V_58 += V_31 -> V_68 ;
F_42 ( V_31 -> V_32 , V_54 ) ;
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
V_56 = F_39 ( V_29 , 0 ) ;
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
V_56 = F_39 ( V_29 , 0 ) ;
}
F_43 ( V_56 ) ;
V_59 -- ;
} while ( F_44 ( V_59 ) );
V_60 += V_29 -> V_44 ;
V_29 -> V_61 = V_60 ;
F_45 ( & V_29 -> V_69 ) ;
V_29 -> V_38 . V_70 += V_57 ;
V_29 -> V_38 . V_39 += V_58 ;
F_46 ( & V_29 -> V_69 ) ;
V_53 -> V_71 . V_57 += V_57 ;
V_53 -> V_71 . V_58 += V_58 ;
if ( F_47 ( V_29 ) && F_33 ( V_29 ) ) {
struct V_9 * V_10 = & V_2 -> V_10 ;
union V_55 * V_63 ;
V_63 = V_29 -> V_62 [ V_60 ] . V_36 ;
F_48 ( L_2
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
F_49 ( V_29 -> V_40 , V_29 -> V_72 ) ;
F_35 ( V_2 ) ;
return true ;
}
#define F_50 (DESC_NEEDED * 2)
if ( F_16 ( V_58 && F_51 ( V_29 -> V_40 ) &&
( F_52 ( V_29 ) >= F_50 ) ) ) {
F_53 () ;
if ( F_54 ( V_29 -> V_40 ,
V_29 -> V_72 ) &&
! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_55 ( V_29 -> V_40 ,
V_29 -> V_72 ) ;
++ V_29 -> V_47 . V_76 ;
}
}
return ! ! V_59 ;
}
static void F_56 ( struct V_52 * V_53 ,
struct V_77 * V_32 )
{
#ifdef F_57
F_58 ( V_32 , & V_53 -> V_78 ) ;
if ( F_59 ( V_53 ) ) {
F_60 ( V_32 ) ;
return;
}
#endif
F_61 ( & V_53 -> V_78 , V_32 ) ;
}
static inline void F_62 ( struct V_28 * V_37 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
T_6 V_81 ;
if ( ! ( V_37 -> V_40 -> V_82 & V_83 ) )
return;
V_81 = F_63 ( V_80 -> V_64 . V_84 . V_85 . V_86 . V_87 ) &
V_88 ;
if ( ! V_81 )
return;
F_64 ( V_32 , F_65 ( V_80 -> V_64 . V_84 . V_89 . V_90 ) ,
( V_91 & ( 1ul << V_81 ) ) ?
V_92 : V_93 ) ;
}
static inline void F_66 ( struct V_28 * V_37 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
F_67 ( V_32 ) ;
if ( ! ( V_37 -> V_40 -> V_82 & V_94 ) )
return;
if ( F_68 ( V_80 , V_95 ) &&
F_68 ( V_80 , V_96 ) ) {
V_37 -> V_97 . V_98 ++ ;
return;
}
if ( ! F_68 ( V_80 , V_99 ) )
return;
if ( F_68 ( V_80 , V_100 ) ) {
V_37 -> V_97 . V_98 ++ ;
return;
}
V_32 -> V_101 = V_102 ;
}
static void F_69 ( struct V_28 * V_103 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
F_62 ( V_103 , V_80 , V_32 ) ;
F_66 ( V_103 , V_80 , V_32 ) ;
if ( F_68 ( V_80 , V_104 ) ) {
T_6 V_105 = F_63 ( V_80 -> V_64 . V_106 . V_107 ) ;
unsigned long * V_108 = F_30 ( V_103 -> V_40 ) ;
if ( F_2 ( V_105 & V_109 , V_108 ) )
F_70 ( V_32 , F_71 ( V_110 ) , V_105 ) ;
}
V_32 -> V_111 = F_72 ( V_32 , V_103 -> V_40 ) ;
}
static bool F_73 ( struct V_28 * V_103 ,
union V_79 * V_80 )
{
T_1 V_112 = V_103 -> V_61 + 1 ;
V_112 = ( V_112 < V_103 -> V_44 ) ? V_112 : 0 ;
V_103 -> V_61 = V_112 ;
F_43 ( F_74 ( V_103 , V_112 ) ) ;
if ( F_44 ( F_68 ( V_80 , V_113 ) ) )
return false ;
return true ;
}
static bool F_75 ( struct V_28 * V_103 ,
struct V_114 * V_115 )
{
struct V_116 * V_116 = V_115 -> V_116 ;
T_7 V_34 = V_115 -> V_34 ;
if ( F_44 ( V_116 ) )
return true ;
V_116 = F_76 () ;
if ( F_16 ( ! V_116 ) ) {
V_103 -> V_97 . V_117 ++ ;
return false ;
}
V_34 = F_77 ( V_103 -> V_14 , V_116 , 0 ,
V_118 , V_119 ) ;
if ( F_78 ( V_103 -> V_14 , V_34 ) ) {
F_79 ( V_116 ) ;
V_103 -> V_97 . V_120 ++ ;
return false ;
}
V_115 -> V_34 = V_34 ;
V_115 -> V_116 = V_116 ;
V_115 -> V_121 = 0 ;
return true ;
}
static void F_80 ( struct V_28 * V_103 ,
T_6 V_122 )
{
union V_79 * V_80 ;
struct V_114 * V_115 ;
unsigned int V_60 = V_103 -> V_73 ;
if ( ! V_122 || ! V_103 -> V_40 )
return;
V_80 = F_74 ( V_103 , V_60 ) ;
V_115 = & V_103 -> V_123 [ V_60 ] ;
V_60 -= V_103 -> V_44 ;
do {
if ( ! F_75 ( V_103 , V_115 ) )
break;
V_80 -> V_124 . V_125 = F_81 ( V_115 -> V_34 + V_115 -> V_121 ) ;
V_80 ++ ;
V_115 ++ ;
V_60 ++ ;
if ( F_16 ( ! V_60 ) ) {
V_80 = F_74 ( V_103 , 0 ) ;
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
F_82 () ;
F_83 ( V_103 , V_60 ) ;
}
}
static bool F_84 ( struct V_28 * V_103 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
if ( F_16 ( F_68 ( V_80 ,
V_128 ) ) ) {
struct V_51 * V_40 = V_103 -> V_40 ;
if ( ! ( V_40 -> V_82 & V_129 ) ) {
F_22 ( V_32 ) ;
return true ;
}
}
if ( F_85 ( V_32 ) )
return true ;
return false ;
}
static void F_86 ( struct V_28 * V_103 ,
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
F_87 ( V_103 -> V_14 , V_131 -> V_34 ,
V_131 -> V_121 ,
V_133 ,
V_119 ) ;
}
static inline bool F_88 ( struct V_116 * V_116 )
{
return ( F_89 ( V_116 ) != F_90 () ) || F_91 ( V_116 ) ;
}
static bool F_92 ( struct V_28 * V_103 ,
struct V_114 * V_134 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
struct V_116 * V_116 = V_134 -> V_116 ;
unsigned char * V_135 = F_93 ( V_116 ) + V_134 -> V_121 ;
unsigned int V_136 = F_63 ( V_80 -> V_64 . V_106 . V_137 ) ;
#if ( V_118 < 8192 )
unsigned int V_138 = V_133 ;
#else
unsigned int V_138 = F_94 ( V_136 , V_139 ) ;
#endif
unsigned int V_140 ;
if ( F_16 ( F_95 ( V_32 ) ) )
goto V_141;
if ( F_44 ( V_136 <= V_142 ) ) {
memcpy ( F_96 ( V_32 , V_136 ) , V_135 , F_94 ( V_136 , sizeof( long ) ) ) ;
if ( F_44 ( ! F_88 ( V_116 ) ) )
return true ;
F_97 ( V_116 ) ;
return false ;
}
V_140 = F_98 ( V_135 , V_142 ) ;
memcpy ( F_96 ( V_32 , V_140 ) , V_135 , F_94 ( V_140 , sizeof( long ) ) ) ;
V_135 += V_140 ;
V_136 -= V_140 ;
V_141:
F_99 ( V_32 , F_100 ( V_32 ) -> V_143 , V_116 ,
( unsigned long ) V_135 & ~ V_144 , V_136 , V_138 ) ;
if ( F_16 ( F_88 ( V_116 ) ) )
return false ;
#if ( V_118 < 8192 )
if ( F_16 ( F_101 ( V_116 ) != 1 ) )
return false ;
V_134 -> V_121 ^= V_133 ;
#else
V_134 -> V_121 += V_138 ;
if ( V_134 -> V_121 > ( V_118 - V_133 ) )
return false ;
#endif
F_102 ( V_116 ) ;
return true ;
}
static struct V_77 * F_103 ( struct V_28 * V_103 ,
union V_79 * V_80 ,
struct V_77 * V_32 )
{
struct V_114 * V_134 ;
struct V_116 * V_116 ;
V_134 = & V_103 -> V_123 [ V_103 -> V_61 ] ;
V_116 = V_134 -> V_116 ;
F_104 ( V_116 ) ;
if ( F_44 ( ! V_32 ) ) {
void * V_145 = F_93 ( V_116 ) +
V_134 -> V_121 ;
F_43 ( V_145 ) ;
#if V_139 < 128
F_43 ( V_145 + V_139 ) ;
#endif
V_32 = F_105 ( V_103 -> V_40 ,
V_142 ) ;
if ( F_16 ( ! V_32 ) ) {
V_103 -> V_97 . V_120 ++ ;
return NULL ;
}
F_104 ( V_32 -> V_146 ) ;
}
F_106 ( V_103 -> V_14 ,
V_134 -> V_34 ,
V_134 -> V_121 ,
V_133 ,
V_119 ) ;
if ( F_92 ( V_103 , V_134 , V_80 , V_32 ) ) {
F_86 ( V_103 , V_134 ) ;
} else {
F_26 ( V_103 -> V_14 , V_134 -> V_34 ,
V_118 , V_119 ) ;
}
V_134 -> V_34 = 0 ;
V_134 -> V_116 = NULL ;
return V_32 ;
}
static inline void F_107 ( struct V_1 * V_2 ,
T_1 V_147 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_19 ( V_10 , V_148 , V_147 ) ;
}
static int F_108 ( struct V_52 * V_53 ,
struct V_28 * V_103 ,
int V_59 )
{
unsigned int V_149 = 0 , V_150 = 0 ;
T_6 V_122 = F_52 ( V_103 ) ;
struct V_77 * V_32 = V_103 -> V_32 ;
while ( F_44 ( V_150 < V_59 ) ) {
union V_79 * V_80 ;
if ( V_122 >= V_151 ) {
F_80 ( V_103 , V_122 ) ;
V_122 = 0 ;
}
V_80 = F_74 ( V_103 , V_103 -> V_61 ) ;
if ( ! F_68 ( V_80 , V_152 ) )
break;
F_109 () ;
V_32 = F_103 ( V_103 , V_80 , V_32 ) ;
if ( ! V_32 )
break;
V_122 ++ ;
if ( F_73 ( V_103 , V_80 ) )
continue;
if ( F_84 ( V_103 , V_80 , V_32 ) ) {
V_32 = NULL ;
continue;
}
V_149 += V_32 -> V_33 ;
if ( ( V_32 -> V_153 == V_154 ||
V_32 -> V_153 == V_155 ) &&
F_110 ( V_103 -> V_40 -> V_156 ,
F_111 ( V_32 ) -> V_157 ) ) {
F_112 ( V_32 ) ;
continue;
}
F_69 ( V_103 , V_80 , V_32 ) ;
F_56 ( V_53 , V_32 ) ;
V_32 = NULL ;
V_150 ++ ;
}
V_103 -> V_32 = V_32 ;
F_45 ( & V_103 -> V_69 ) ;
V_103 -> V_38 . V_39 += V_150 ;
V_103 -> V_38 . V_70 += V_149 ;
F_46 ( & V_103 -> V_69 ) ;
V_53 -> V_158 . V_58 += V_150 ;
V_53 -> V_158 . V_57 += V_149 ;
return V_150 ;
}
static int F_113 ( struct V_159 * V_78 , int V_59 )
{
struct V_52 * V_53 =
F_114 ( V_78 , struct V_52 , V_78 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_28 * V_37 ;
int V_160 , V_161 = 0 ;
bool V_162 = true ;
F_115 (ring, q_vector->tx) {
if ( ! F_38 ( V_53 , V_37 , V_59 ) )
V_162 = false ;
}
if ( V_59 <= 0 )
return V_59 ;
#ifdef F_57
if ( ! F_116 ( V_53 ) )
return V_59 ;
#endif
if ( V_53 -> V_158 . V_44 > 1 )
V_160 = F_117 ( V_59 / V_53 -> V_158 . V_44 , 1 ) ;
else
V_160 = V_59 ;
F_115 (ring, q_vector->rx) {
int V_163 = F_108 ( V_53 , V_37 ,
V_160 ) ;
V_161 += V_163 ;
if ( V_163 >= V_160 )
V_162 = false ;
}
#ifdef F_57
F_118 ( V_53 ) ;
#endif
if ( ! V_162 )
return V_59 ;
F_119 ( V_78 , V_161 ) ;
if ( V_2 -> V_164 == 1 )
F_120 ( V_53 ) ;
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) &&
! F_2 ( V_5 , & V_2 -> V_4 ) )
F_107 ( V_2 ,
F_121 ( V_53 -> V_165 ) ) ;
return 0 ;
}
void F_122 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_165 = V_53 -> V_165 ;
T_1 V_166 = V_53 -> V_167 & V_168 ;
V_166 |= V_169 ;
F_19 ( V_10 , F_123 ( V_165 ) , V_166 ) ;
}
static int F_124 ( struct V_159 * V_78 )
{
struct V_52 * V_53 =
F_114 ( V_78 , struct V_52 , V_78 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_28 * V_37 ;
int V_170 = 0 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return V_171 ;
if ( ! F_125 ( V_53 ) )
return V_172 ;
F_115 (ring, q_vector->rx) {
V_170 = F_108 ( V_53 , V_37 , 4 ) ;
#ifdef F_126
if ( V_170 )
V_37 -> V_38 . V_163 += V_170 ;
else
V_37 -> V_38 . V_173 ++ ;
#endif
if ( V_170 )
break;
}
F_127 ( V_53 ) ;
return V_170 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
int V_174 , V_165 ;
V_174 = V_2 -> V_175 - V_176 ;
V_2 -> V_177 = 0 ;
for ( V_165 = 0 ; V_165 < V_174 ; V_165 ++ ) {
struct V_28 * V_37 ;
V_53 = V_2 -> V_53 [ V_165 ] ;
F_115 (ring, q_vector->rx)
F_17 ( V_2 , 0 , V_37 -> V_42 , V_165 ) ;
F_115 (ring, q_vector->tx)
F_17 ( V_2 , 1 , V_37 -> V_42 , V_165 ) ;
if ( V_53 -> V_71 . V_37 && ! V_53 -> V_158 . V_37 ) {
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
V_2 -> V_177 |= F_121 ( V_165 ) ;
F_122 ( V_53 ) ;
}
F_17 ( V_2 , - 1 , 1 , V_165 ) ;
V_2 -> V_181 = F_121 ( V_165 ) ;
V_2 -> V_177 |= V_2 -> V_181 ;
}
static void F_129 ( struct V_52 * V_53 ,
struct V_182 * V_183 )
{
int V_70 = V_183 -> V_57 ;
int V_39 = V_183 -> V_58 ;
T_1 V_184 ;
T_5 V_185 ;
T_2 V_186 = V_183 -> V_167 ;
if ( V_39 == 0 )
return;
V_184 = V_53 -> V_167 >> 2 ;
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
static void F_120 ( struct V_52 * V_53 )
{
T_1 V_190 = V_53 -> V_167 ;
T_2 V_191 ;
F_129 ( V_53 , & V_53 -> V_71 ) ;
F_129 ( V_53 , & V_53 -> V_158 ) ;
V_191 = F_117 ( V_53 -> V_158 . V_167 , V_53 -> V_71 . V_167 ) ;
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
if ( V_190 != V_53 -> V_167 ) {
V_190 = ( 10 * V_190 * V_53 -> V_167 ) /
( ( 9 * V_190 ) + V_53 -> V_167 ) ;
V_53 -> V_167 = V_190 ;
F_122 ( V_53 ) ;
}
}
static T_8 F_130 ( int V_193 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
V_10 -> V_194 . V_195 = 1 ;
F_1 ( V_2 ) ;
F_19 ( V_10 , V_148 , V_2 -> V_181 ) ;
return V_196 ;
}
static T_8 F_131 ( int V_193 , void * V_146 )
{
struct V_52 * V_53 = V_146 ;
if ( V_53 -> V_158 . V_37 || V_53 -> V_71 . V_37 )
F_132 ( & V_53 -> V_78 ) ;
return V_196 ;
}
static inline void F_133 ( struct V_1 * V_197 , int V_165 ,
int V_198 )
{
struct V_52 * V_53 = V_197 -> V_53 [ V_165 ] ;
V_197 -> V_103 [ V_198 ] -> V_199 = V_53 -> V_158 . V_37 ;
V_53 -> V_158 . V_37 = V_197 -> V_103 [ V_198 ] ;
V_53 -> V_158 . V_44 ++ ;
}
static inline void F_134 ( struct V_1 * V_197 , int V_165 ,
int V_200 )
{
struct V_52 * V_53 = V_197 -> V_53 [ V_165 ] ;
V_197 -> V_29 [ V_200 ] -> V_199 = V_53 -> V_71 . V_37 ;
V_53 -> V_71 . V_37 = V_197 -> V_29 [ V_200 ] ;
V_53 -> V_71 . V_44 ++ ;
}
static int F_135 ( struct V_1 * V_2 )
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
F_133 ( V_2 , V_201 , V_202 ) ;
for (; V_203 < V_206 ; V_201 ++ , V_203 ++ )
F_134 ( V_2 , V_201 , V_203 ) ;
return 0 ;
}
for ( V_60 = V_201 ; V_60 < V_174 ; V_60 ++ ) {
V_209 = F_136 ( V_204 , V_174 - V_60 ) ;
for ( V_208 = 0 ; V_208 < V_209 ; V_208 ++ ) {
F_133 ( V_2 , V_60 , V_202 ) ;
V_202 ++ ;
V_204 -- ;
}
}
for ( V_60 = V_201 ; V_60 < V_174 ; V_60 ++ ) {
V_210 = F_136 ( V_206 , V_174 - V_60 ) ;
for ( V_208 = 0 ; V_208 < V_210 ; V_208 ++ ) {
F_134 ( V_2 , V_60 , V_203 ) ;
V_203 ++ ;
V_206 -- ;
}
}
return 0 ;
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_51 * V_40 = V_2 -> V_40 ;
int V_174 = V_2 -> V_175 - V_176 ;
int V_211 , V_212 ;
int V_213 = 0 , V_214 = 0 ;
for ( V_211 = 0 ; V_211 < V_174 ; V_211 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_211 ] ;
struct V_215 * V_216 = & V_2 -> V_217 [ V_211 ] ;
if ( V_53 -> V_71 . V_37 && V_53 -> V_158 . V_37 ) {
snprintf ( V_53 -> V_218 , sizeof( V_53 -> V_218 ) - 1 ,
L_12 , V_40 -> V_218 , L_13 , V_213 ++ ) ;
V_214 ++ ;
} else if ( V_53 -> V_158 . V_37 ) {
snprintf ( V_53 -> V_218 , sizeof( V_53 -> V_218 ) - 1 ,
L_12 , V_40 -> V_218 , L_14 , V_213 ++ ) ;
} else if ( V_53 -> V_71 . V_37 ) {
snprintf ( V_53 -> V_218 , sizeof( V_53 -> V_218 ) - 1 ,
L_12 , V_40 -> V_218 , L_15 , V_214 ++ ) ;
} else {
continue;
}
V_212 = F_138 ( V_216 -> V_211 , & F_131 , 0 ,
V_53 -> V_218 , V_53 ) ;
if ( V_212 ) {
F_139 ( & V_2 -> V_10 ,
L_16 ,
V_212 ) ;
goto V_219;
}
}
V_212 = F_138 ( V_2 -> V_217 [ V_211 ] . V_211 ,
& F_130 , 0 , V_40 -> V_218 , V_2 ) ;
if ( V_212 ) {
F_139 ( & V_2 -> V_10 , L_17 ,
V_212 ) ;
goto V_219;
}
return 0 ;
V_219:
while ( V_211 ) {
V_211 -- ;
F_140 ( V_2 -> V_217 [ V_211 ] . V_211 ,
V_2 -> V_53 [ V_211 ] ) ;
}
V_2 -> V_175 = 0 ;
return V_212 ;
}
static inline void F_141 ( struct V_1 * V_2 )
{
int V_60 , V_174 = V_2 -> V_175 - V_176 ;
for ( V_60 = 0 ; V_60 < V_174 ; V_60 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_60 ] ;
V_53 -> V_158 . V_37 = NULL ;
V_53 -> V_71 . V_37 = NULL ;
V_53 -> V_158 . V_44 = 0 ;
V_53 -> V_71 . V_44 = 0 ;
}
}
static int F_142 ( struct V_1 * V_2 )
{
int V_212 = F_137 ( V_2 ) ;
if ( V_212 )
F_139 ( & V_2 -> V_10 , L_18 , V_212 ) ;
return V_212 ;
}
static void F_143 ( struct V_1 * V_2 )
{
int V_60 , V_174 ;
V_174 = V_2 -> V_175 ;
V_60 = V_174 - 1 ;
F_140 ( V_2 -> V_217 [ V_60 ] . V_211 , V_2 ) ;
V_60 -- ;
for (; V_60 >= 0 ; V_60 -- ) {
if ( ! V_2 -> V_53 [ V_60 ] -> V_158 . V_37 &&
! V_2 -> V_53 [ V_60 ] -> V_71 . V_37 )
continue;
F_140 ( V_2 -> V_217 [ V_60 ] . V_211 ,
V_2 -> V_53 [ V_60 ] ) ;
}
F_141 ( V_2 ) ;
}
static inline void F_144 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
F_19 ( V_10 , V_220 , 0 ) ;
F_19 ( V_10 , V_221 , ~ 0 ) ;
F_19 ( V_10 , V_222 , 0 ) ;
F_145 ( V_10 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_175 ; V_60 ++ )
F_146 ( V_2 -> V_217 [ V_60 ] . V_211 ) ;
}
static inline void F_147 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_19 ( V_10 , V_220 , V_2 -> V_177 ) ;
F_19 ( V_10 , V_222 , V_2 -> V_177 ) ;
F_19 ( V_10 , V_148 , V_2 -> V_177 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_5 V_223 = V_37 -> V_34 ;
int V_224 = 10 ;
T_1 V_225 = V_226 ;
T_2 V_42 = V_37 -> V_42 ;
F_19 ( V_10 , F_149 ( V_42 ) , V_227 ) ;
F_145 ( V_10 ) ;
F_19 ( V_10 , F_150 ( V_42 ) , V_223 & F_151 ( 32 ) ) ;
F_19 ( V_10 , F_152 ( V_42 ) , V_223 >> 32 ) ;
F_19 ( V_10 , F_153 ( V_42 ) ,
V_37 -> V_44 * sizeof( union V_55 ) ) ;
F_19 ( V_10 , F_154 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_155 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_156 ( V_42 ) ,
( V_228 |
V_229 ) ) ;
F_19 ( V_10 , F_31 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_32 ( V_42 ) , 0 ) ;
V_37 -> V_43 = V_2 -> V_230 + F_32 ( V_42 ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_73 = 0 ;
V_225 |= ( 8 << 16 ) ;
V_225 |= ( 1u << 8 ) |
32 ;
F_8 ( V_49 , & V_37 -> V_4 ) ;
F_19 ( V_10 , F_149 ( V_42 ) , V_225 ) ;
do {
F_157 ( 1000 , 2000 ) ;
V_225 = F_18 ( V_10 , F_149 ( V_42 ) ) ;
} while ( -- V_224 && ! ( V_225 & V_226 ) );
if ( ! V_224 )
F_48 ( L_19 , V_42 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
T_1 V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
F_148 ( V_2 , V_2 -> V_29 [ V_60 ] ) ;
}
static void F_159 ( struct V_1 * V_2 , int V_25 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_231 ;
V_231 = V_232 ;
V_231 |= V_142 << V_233 ;
V_231 |= V_133 >> V_234 ;
V_231 |= V_235 ;
F_19 ( V_10 , F_160 ( V_25 ) , V_231 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_236 = V_237 | V_238 |
V_239 | V_240 |
V_241 ;
if ( V_2 -> V_205 > 1 )
V_236 |= F_121 ( 29 ) ;
F_19 ( V_10 , V_242 , V_236 ) ;
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
V_244 = F_18 ( V_10 , F_163 ( V_42 ) ) ;
V_244 &= ~ V_245 ;
F_19 ( V_10 , F_163 ( V_42 ) , V_244 ) ;
do {
F_164 ( 10 ) ;
V_244 = F_18 ( V_10 , F_163 ( V_42 ) ) ;
} while ( -- V_224 && ( V_244 & V_245 ) );
if ( ! V_224 )
F_48 ( L_20 ,
V_42 ) ;
}
static void F_165 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_224 = V_243 ;
T_1 V_244 ;
T_2 V_42 = V_37 -> V_42 ;
if ( F_14 ( V_10 -> V_12 ) )
return;
do {
F_157 ( 1000 , 2000 ) ;
V_244 = F_18 ( V_10 , F_163 ( V_42 ) ) ;
} while ( -- V_224 && ! ( V_244 & V_245 ) );
if ( ! V_224 )
F_48 ( L_21 ,
V_42 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_246 = 0 , V_247 = 0 ;
T_6 V_248 = V_2 -> V_205 ;
T_2 V_60 , V_208 ;
F_167 ( V_2 -> V_249 , sizeof( V_2 -> V_249 ) ) ;
for ( V_60 = 0 ; V_60 < V_250 ; V_60 ++ )
F_19 ( V_10 , F_168 ( V_60 ) , V_2 -> V_249 [ V_60 ] ) ;
for ( V_60 = 0 , V_208 = 0 ; V_60 < V_251 ; V_60 ++ , V_208 ++ ) {
if ( V_208 == V_248 )
V_208 = 0 ;
V_2 -> V_252 [ V_60 ] = V_208 ;
V_247 |= V_208 << ( V_60 & 0x3 ) * 8 ;
if ( ( V_60 & 3 ) == 3 ) {
F_19 ( V_10 , F_169 ( V_60 >> 2 ) , V_247 ) ;
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
static void F_170 ( struct V_1 * V_2 ,
struct V_28 * V_37 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_5 V_259 = V_37 -> V_34 ;
T_1 V_244 ;
T_2 V_42 = V_37 -> V_42 ;
V_244 = F_18 ( V_10 , F_163 ( V_42 ) ) ;
F_162 ( V_2 , V_37 ) ;
F_19 ( V_10 , F_171 ( V_42 ) , V_259 & F_151 ( 32 ) ) ;
F_19 ( V_10 , F_172 ( V_42 ) , V_259 >> 32 ) ;
F_19 ( V_10 , F_173 ( V_42 ) ,
V_37 -> V_44 * sizeof( union V_79 ) ) ;
#ifndef F_174
F_19 ( V_10 , F_175 ( V_42 ) ,
V_260 ) ;
#else
F_19 ( V_10 , F_175 ( V_42 ) ,
V_260 |
V_261 ) ;
#endif
F_19 ( V_10 , F_176 ( V_42 ) , 0 ) ;
F_19 ( V_10 , F_177 ( V_42 ) , 0 ) ;
V_37 -> V_43 = V_2 -> V_230 + F_177 ( V_42 ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_73 = 0 ;
V_37 -> V_127 = 0 ;
F_159 ( V_2 , V_42 ) ;
V_244 &= ~ V_262 ;
V_244 |= V_245 | V_263 ;
F_19 ( V_10 , F_163 ( V_42 ) , V_244 ) ;
F_165 ( V_2 , V_37 ) ;
F_80 ( V_37 , F_52 ( V_37 ) ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
int V_60 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_51 * V_40 = V_2 -> V_40 ;
F_161 ( V_2 ) ;
if ( V_10 -> V_194 . type >= V_264 )
F_166 ( V_2 ) ;
V_10 -> V_194 . V_265 . V_266 ( V_10 , V_40 -> V_267 + V_268 + V_269 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_170 ( V_2 , V_2 -> V_103 [ V_60 ] ) ;
}
static int F_179 ( struct V_51 * V_40 ,
T_9 V_270 , T_6 V_105 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_212 ;
F_180 ( & V_2 -> V_271 ) ;
V_212 = V_10 -> V_194 . V_265 . V_272 ( V_10 , V_105 , 0 , true ) ;
F_181 ( & V_2 -> V_271 ) ;
if ( V_212 == V_273 )
return - V_274 ;
if ( V_212 == V_275 )
return - V_276 ;
F_36 ( V_105 , V_2 -> V_108 ) ;
return V_212 ;
}
static int F_182 ( struct V_51 * V_40 ,
T_9 V_270 , T_6 V_105 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_212 ;
F_180 ( & V_2 -> V_271 ) ;
V_212 = V_10 -> V_194 . V_265 . V_272 ( V_10 , V_105 , 0 , false ) ;
F_181 ( & V_2 -> V_271 ) ;
F_8 ( V_105 , V_2 -> V_108 ) ;
return V_212 ;
}
static void F_183 ( struct V_1 * V_2 )
{
T_6 V_105 ;
F_184 (vid, adapter->active_vlans, VLAN_N_VID)
F_179 ( V_2 -> V_40 ,
F_71 ( V_110 ) , V_105 ) ;
}
static int F_185 ( struct V_51 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_44 = 0 ;
if ( ( F_186 ( V_40 ) ) > 10 ) {
F_48 ( L_22 ) ;
return - V_277 ;
}
if ( ! F_187 ( V_40 ) ) {
struct V_278 * V_279 ;
F_188 (ha, netdev) {
V_10 -> V_194 . V_265 . V_280 ( V_10 , ++ V_44 , V_279 -> V_281 ) ;
F_164 ( 200 ) ;
}
} else {
V_10 -> V_194 . V_265 . V_280 ( V_10 , 0 , NULL ) ;
}
return V_44 ;
}
static void F_189 ( struct V_51 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_282 = V_40 -> V_282 ;
int V_283 ;
V_283 = ( V_282 & V_284 ) ? V_285 :
( V_282 & ( V_286 | V_287 ) ) ?
V_288 : V_289 ;
F_180 ( & V_2 -> V_271 ) ;
V_10 -> V_194 . V_265 . V_290 ( V_10 , V_283 ) ;
V_10 -> V_194 . V_265 . V_291 ( V_10 , V_40 ) ;
F_185 ( V_40 ) ;
F_181 ( & V_2 -> V_271 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
int V_292 ;
struct V_52 * V_53 ;
int V_174 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_174 ; V_292 ++ ) {
V_53 = V_2 -> V_53 [ V_292 ] ;
#ifdef F_57
F_191 ( V_2 -> V_53 [ V_292 ] ) ;
#endif
F_192 ( & V_53 -> V_78 ) ;
}
}
static void F_193 ( struct V_1 * V_2 )
{
int V_292 ;
struct V_52 * V_53 ;
int V_174 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_174 ; V_292 ++ ) {
V_53 = V_2 -> V_53 [ V_292 ] ;
F_194 ( & V_53 -> V_78 ) ;
#ifdef F_57
while ( ! F_195 ( V_2 -> V_53 [ V_292 ] ) ) {
F_196 ( L_23 , V_292 ) ;
F_157 ( 1000 , 20000 ) ;
}
#endif
}
}
static int F_197 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_293 = 0 ;
unsigned int V_294 = 0 ;
unsigned int V_205 = V_2 -> V_205 ;
unsigned int V_207 = V_2 -> V_207 ;
int V_212 ;
F_180 ( & V_2 -> V_271 ) ;
V_212 = F_198 ( V_10 , & V_294 , & V_293 ) ;
F_181 ( & V_2 -> V_271 ) ;
if ( V_212 )
return V_212 ;
if ( V_294 > 1 ) {
V_207 = 1 ;
V_2 -> V_29 [ 0 ] -> V_42 = V_293 ;
V_205 = V_294 ;
}
if ( ( V_2 -> V_205 != V_205 ) ||
( V_2 -> V_207 != V_207 ) ) {
V_10 -> V_295 . V_296 = 0 ;
F_36 ( V_297 , & V_2 -> V_4 ) ;
}
return 0 ;
}
static void F_199 ( struct V_1 * V_2 )
{
F_197 ( V_2 ) ;
F_189 ( V_2 -> V_40 ) ;
F_183 ( V_2 ) ;
F_158 ( V_2 ) ;
F_178 ( V_2 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 . V_298 || V_2 -> V_38 . V_299 ) {
V_2 -> V_38 . V_300 += V_2 -> V_38 . V_298 -
V_2 -> V_38 . V_301 ;
V_2 -> V_38 . V_302 += V_2 -> V_38 . V_299 -
V_2 -> V_38 . V_303 ;
V_2 -> V_38 . V_304 += V_2 -> V_38 . V_305 -
V_2 -> V_38 . V_306 ;
V_2 -> V_38 . V_307 += V_2 -> V_38 . V_308 -
V_2 -> V_38 . V_309 ;
V_2 -> V_38 . V_310 += V_2 -> V_38 . V_311 -
V_2 -> V_38 . V_312 ;
}
}
static void F_201 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
V_2 -> V_38 . V_313 = F_18 ( V_10 , V_314 ) ;
V_2 -> V_38 . V_315 = F_18 ( V_10 , V_316 ) ;
V_2 -> V_38 . V_315 |=
( ( ( T_5 ) ( F_18 ( V_10 , V_317 ) ) ) << 32 ) ;
V_2 -> V_38 . V_318 = F_18 ( V_10 , V_319 ) ;
V_2 -> V_38 . V_320 = F_18 ( V_10 , V_321 ) ;
V_2 -> V_38 . V_320 |=
( ( ( T_5 ) ( F_18 ( V_10 , V_322 ) ) ) << 32 ) ;
V_2 -> V_38 . V_323 = F_18 ( V_10 , V_324 ) ;
V_2 -> V_38 . V_301 = V_2 -> V_38 . V_313 ;
V_2 -> V_38 . V_306 = V_2 -> V_38 . V_315 ;
V_2 -> V_38 . V_303 = V_2 -> V_38 . V_318 ;
V_2 -> V_38 . V_309 = V_2 -> V_38 . V_320 ;
V_2 -> V_38 . V_312 = V_2 -> V_38 . V_323 ;
}
static void F_202 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_325 [] = { V_326 ,
V_327 ,
V_328 ,
V_329 } ;
int V_212 , V_330 = 0 ;
F_180 ( & V_2 -> V_271 ) ;
while ( V_325 [ V_330 ] != V_329 ) {
V_212 = V_10 -> V_194 . V_265 . V_331 ( V_10 , V_325 [ V_330 ] ) ;
if ( ! V_212 )
break;
V_330 ++ ;
}
F_181 ( & V_2 -> V_271 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_51 * V_40 = V_2 -> V_40 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
F_128 ( V_2 ) ;
F_180 ( & V_2 -> V_271 ) ;
if ( F_204 ( V_10 -> V_194 . V_281 ) )
V_10 -> V_194 . V_265 . V_332 ( V_10 , 0 , V_10 -> V_194 . V_281 , 0 ) ;
else
V_10 -> V_194 . V_265 . V_332 ( V_10 , 0 , V_10 -> V_194 . V_333 , 0 ) ;
F_181 ( & V_2 -> V_271 ) ;
F_7 () ;
F_8 ( V_3 , & V_2 -> V_4 ) ;
F_190 ( V_2 ) ;
F_18 ( V_10 , V_334 ) ;
F_147 ( V_2 ) ;
F_205 ( V_40 ) ;
F_200 ( V_2 ) ;
F_201 ( V_2 ) ;
V_10 -> V_194 . V_195 = 1 ;
F_206 ( & V_2 -> V_335 , V_75 ) ;
}
void F_207 ( struct V_1 * V_2 )
{
F_199 ( V_2 ) ;
F_203 ( V_2 ) ;
}
static void F_208 ( struct V_28 * V_103 )
{
struct V_336 * V_14 = V_103 -> V_14 ;
unsigned long V_136 ;
unsigned int V_60 ;
if ( V_103 -> V_32 ) {
F_209 ( V_103 -> V_32 ) ;
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
F_79 ( V_134 -> V_116 ) ;
V_134 -> V_116 = NULL ;
}
V_136 = sizeof( struct V_114 ) * V_103 -> V_44 ;
memset ( V_103 -> V_123 , 0 , V_136 ) ;
memset ( V_103 -> V_337 , 0 , V_103 -> V_136 ) ;
}
static void F_210 ( struct V_28 * V_29 )
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
memset ( V_29 -> V_337 , 0 , V_29 -> V_136 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_208 ( V_2 -> V_103 [ V_60 ] ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
F_210 ( V_2 -> V_29 [ V_60 ] ) ;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_51 * V_40 = V_2 -> V_40 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_162 ( V_2 , V_2 -> V_103 [ V_60 ] ) ;
F_157 ( 10000 , 20000 ) ;
F_214 ( V_40 ) ;
F_215 ( V_40 ) ;
F_216 ( V_40 ) ;
F_144 ( V_2 ) ;
F_193 ( V_2 ) ;
F_217 ( & V_2 -> V_335 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
T_2 V_42 = V_2 -> V_29 [ V_60 ] -> V_42 ;
F_19 ( V_10 , F_149 ( V_42 ) ,
V_227 ) ;
}
if ( ! F_218 ( V_2 -> V_13 ) )
F_219 ( V_2 ) ;
F_212 ( V_2 ) ;
F_211 ( V_2 ) ;
}
void F_220 ( struct V_1 * V_2 )
{
F_221 ( F_222 () ) ;
while ( F_3 ( V_338 , & V_2 -> V_4 ) )
F_223 ( 1 ) ;
F_213 ( V_2 ) ;
F_207 ( V_2 ) ;
F_8 ( V_338 , & V_2 -> V_4 ) ;
}
void F_219 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_51 * V_40 = V_2 -> V_40 ;
if ( V_10 -> V_194 . V_265 . V_339 ( V_10 ) ) {
F_139 ( V_10 , L_24 ) ;
} else {
V_10 -> V_194 . V_265 . V_340 ( V_10 ) ;
F_202 ( V_2 ) ;
}
if ( F_204 ( V_2 -> V_10 . V_194 . V_281 ) ) {
F_224 ( V_40 -> V_156 , V_2 -> V_10 . V_194 . V_281 ) ;
F_224 ( V_40 -> V_333 , V_2 -> V_10 . V_194 . V_281 ) ;
}
V_2 -> V_341 = V_75 ;
}
static int F_225 ( struct V_1 * V_2 ,
int V_342 )
{
int V_343 ;
V_343 = V_344 ;
V_342 = F_226 ( V_2 -> V_13 , V_2 -> V_217 ,
V_343 , V_342 ) ;
if ( V_342 < 0 ) {
F_10 ( & V_2 -> V_13 -> V_14 ,
L_25 ) ;
F_227 ( V_2 -> V_217 ) ;
V_2 -> V_217 = NULL ;
return V_342 ;
}
V_2 -> V_175 = V_342 ;
return 0 ;
}
static void F_228 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
unsigned int V_293 = 0 ;
unsigned int V_294 = 0 ;
int V_212 ;
V_2 -> V_205 = 1 ;
V_2 -> V_207 = 1 ;
F_180 ( & V_2 -> V_271 ) ;
V_212 = F_198 ( V_10 , & V_294 , & V_293 ) ;
F_181 ( & V_2 -> V_271 ) ;
if ( V_212 )
return;
if ( V_294 > 1 ) {
V_2 -> V_205 = V_294 ;
} else {
T_6 V_90 = F_229 ( T_6 , F_230 () , V_345 ) ;
switch ( V_10 -> V_346 ) {
case V_327 :
case V_326 :
V_2 -> V_205 = V_90 ;
V_2 -> V_207 = V_90 ;
default:
break;
}
}
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_28 * V_37 ;
int V_158 = 0 , V_71 = 0 ;
for (; V_71 < V_2 -> V_207 ; V_71 ++ ) {
V_37 = F_232 ( sizeof( * V_37 ) , V_347 ) ;
if ( ! V_37 )
goto V_348;
V_37 -> V_14 = & V_2 -> V_13 -> V_14 ;
V_37 -> V_40 = V_2 -> V_40 ;
V_37 -> V_44 = V_2 -> V_349 ;
V_37 -> V_72 = V_71 ;
V_37 -> V_42 = V_71 ;
V_2 -> V_29 [ V_71 ] = V_37 ;
}
for (; V_158 < V_2 -> V_205 ; V_158 ++ ) {
V_37 = F_232 ( sizeof( * V_37 ) , V_347 ) ;
if ( ! V_37 )
goto V_348;
V_37 -> V_14 = & V_2 -> V_13 -> V_14 ;
V_37 -> V_40 = V_2 -> V_40 ;
V_37 -> V_44 = V_2 -> V_350 ;
V_37 -> V_72 = V_158 ;
V_37 -> V_42 = V_158 ;
V_2 -> V_103 [ V_158 ] = V_37 ;
}
return 0 ;
V_348:
while ( V_71 ) {
F_227 ( V_2 -> V_29 [ -- V_71 ] ) ;
V_2 -> V_29 [ V_71 ] = NULL ;
}
while ( V_158 ) {
F_227 ( V_2 -> V_103 [ -- V_158 ] ) ;
V_2 -> V_103 [ V_158 ] = NULL ;
}
return - V_351 ;
}
static int F_233 ( struct V_1 * V_2 )
{
struct V_51 * V_40 = V_2 -> V_40 ;
int V_212 ;
int V_211 , V_352 ;
V_352 = F_117 ( V_2 -> V_205 , V_2 -> V_207 ) ;
V_352 = F_229 ( int , V_352 , F_230 () ) ;
V_352 += V_176 ;
V_2 -> V_217 = F_234 ( V_352 ,
sizeof( struct V_215 ) , V_347 ) ;
if ( ! V_2 -> V_217 )
return - V_351 ;
for ( V_211 = 0 ; V_211 < V_352 ; V_211 ++ )
V_2 -> V_217 [ V_211 ] . V_216 = V_211 ;
V_212 = F_225 ( V_2 , V_352 ) ;
if ( V_212 )
return V_212 ;
V_212 = F_235 ( V_40 , V_2 -> V_207 ) ;
if ( V_212 )
return V_212 ;
return F_236 ( V_40 , V_2 -> V_205 ) ;
}
static int F_237 ( struct V_1 * V_2 )
{
int V_292 , V_353 ;
struct V_52 * V_53 ;
V_353 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_353 ; V_292 ++ ) {
V_53 = F_232 ( sizeof( struct V_52 ) , V_347 ) ;
if ( ! V_53 )
goto V_354;
V_53 -> V_2 = V_2 ;
V_53 -> V_165 = V_292 ;
F_238 ( V_2 -> V_40 , & V_53 -> V_78 ,
F_113 , 64 ) ;
V_2 -> V_53 [ V_292 ] = V_53 ;
}
return 0 ;
V_354:
while ( V_292 ) {
V_292 -- ;
V_53 = V_2 -> V_53 [ V_292 ] ;
#ifdef F_57
F_239 ( & V_53 -> V_78 ) ;
#endif
F_240 ( & V_53 -> V_78 ) ;
F_227 ( V_53 ) ;
V_2 -> V_53 [ V_292 ] = NULL ;
}
return - V_351 ;
}
static void F_241 ( struct V_1 * V_2 )
{
int V_292 , V_353 = V_2 -> V_175 - V_176 ;
for ( V_292 = 0 ; V_292 < V_353 ; V_292 ++ ) {
struct V_52 * V_53 = V_2 -> V_53 [ V_292 ] ;
V_2 -> V_53 [ V_292 ] = NULL ;
#ifdef F_57
F_239 ( & V_53 -> V_78 ) ;
#endif
F_240 ( & V_53 -> V_78 ) ;
F_227 ( V_53 ) ;
}
}
static void F_242 ( struct V_1 * V_2 )
{
F_243 ( V_2 -> V_13 ) ;
F_227 ( V_2 -> V_217 ) ;
V_2 -> V_217 = NULL ;
}
static int F_244 ( struct V_1 * V_2 )
{
int V_212 ;
F_228 ( V_2 ) ;
V_212 = F_233 ( V_2 ) ;
if ( V_212 ) {
F_139 ( & V_2 -> V_10 ,
L_26 ) ;
goto V_355;
}
V_212 = F_237 ( V_2 ) ;
if ( V_212 ) {
F_139 ( & V_2 -> V_10 , L_27 ) ;
goto V_356;
}
V_212 = F_231 ( V_2 ) ;
if ( V_212 ) {
F_48 ( L_28 ) ;
goto V_357;
}
F_139 ( & V_2 -> V_10 , L_29 ,
( V_2 -> V_205 > 1 ) ? L_30 :
L_31 , V_2 -> V_205 , V_2 -> V_207 ) ;
F_36 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_357:
F_241 ( V_2 ) ;
V_356:
F_242 ( V_2 ) ;
V_355:
return V_212 ;
}
static void F_245 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
F_227 ( V_2 -> V_29 [ V_60 ] ) ;
V_2 -> V_29 [ V_60 ] = NULL ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
F_227 ( V_2 -> V_103 [ V_60 ] ) ;
V_2 -> V_103 [ V_60 ] = NULL ;
}
V_2 -> V_207 = 0 ;
V_2 -> V_205 = 0 ;
F_241 ( V_2 ) ;
F_242 ( V_2 ) ;
}
static int F_246 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_358 * V_13 = V_2 -> V_13 ;
struct V_51 * V_40 = V_2 -> V_40 ;
int V_212 ;
V_10 -> V_359 = V_13 -> V_360 ;
V_10 -> V_361 = V_13 -> V_336 ;
V_10 -> V_362 = V_13 -> V_363 ;
V_10 -> V_364 = V_13 -> V_365 ;
V_10 -> V_366 = V_13 -> V_367 ;
V_10 -> V_295 . V_265 . V_368 ( V_10 ) ;
V_10 -> V_194 . V_369 = 2 ;
V_10 -> V_194 . V_370 = 2 ;
F_247 ( & V_2 -> V_271 ) ;
V_212 = V_10 -> V_194 . V_265 . V_339 ( V_10 ) ;
if ( V_212 ) {
F_248 ( & V_13 -> V_14 ,
L_32 ) ;
} else {
V_212 = V_10 -> V_194 . V_265 . V_340 ( V_10 ) ;
if ( V_212 ) {
F_48 ( L_33 , V_212 ) ;
goto V_371;
}
F_202 ( V_2 ) ;
V_212 = V_10 -> V_194 . V_265 . V_372 ( V_10 , V_10 -> V_194 . V_281 ) ;
if ( V_212 )
F_248 ( & V_13 -> V_14 , L_34 ) ;
else if ( F_249 ( V_2 -> V_10 . V_194 . V_281 ) )
F_248 ( & V_13 -> V_14 ,
L_35 ) ;
F_224 ( V_40 -> V_156 , V_10 -> V_194 . V_281 ) ;
}
if ( ! F_204 ( V_40 -> V_156 ) ) {
F_248 ( & V_13 -> V_14 , L_36 ) ;
F_250 ( V_40 ) ;
F_224 ( V_10 -> V_194 . V_281 , V_40 -> V_156 ) ;
F_224 ( V_10 -> V_194 . V_333 , V_40 -> V_156 ) ;
}
V_2 -> V_164 = 1 ;
V_2 -> V_178 = 1 ;
V_2 -> V_349 = V_373 ;
V_2 -> V_350 = V_374 ;
F_36 ( V_3 , & V_2 -> V_4 ) ;
return 0 ;
V_371:
return V_212 ;
}
void F_251 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_338 , & V_2 -> V_4 ) )
return;
F_252 ( V_314 , V_2 -> V_38 . V_313 ,
V_2 -> V_38 . V_298 ) ;
F_252 ( V_319 , V_2 -> V_38 . V_318 ,
V_2 -> V_38 . V_299 ) ;
F_253 ( V_316 , V_317 ,
V_2 -> V_38 . V_315 ,
V_2 -> V_38 . V_305 ) ;
F_253 ( V_321 , V_322 ,
V_2 -> V_38 . V_320 ,
V_2 -> V_38 . V_308 ) ;
F_252 ( V_324 , V_2 -> V_38 . V_323 ,
V_2 -> V_38 . V_311 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
V_2 -> V_375 +=
V_2 -> V_103 [ V_60 ] -> V_375 ;
V_2 -> V_103 [ V_60 ] -> V_375 = 0 ;
}
}
static void F_254 ( unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_146 ;
F_206 ( & V_2 -> V_335 , ( V_376 * 2 ) + V_75 ) ;
F_1 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
if ( ! F_256 ( V_50 , & V_2 -> V_4 ) )
return;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_338 , & V_2 -> V_4 ) )
return;
V_2 -> V_377 ++ ;
F_220 ( V_2 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_378 = 0 ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_338 , & V_2 -> V_4 ) )
return;
if ( F_51 ( V_2 -> V_40 ) ) {
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
F_258 ( V_2 -> V_29 [ V_60 ] ) ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_175 - V_176 ; V_60 ++ ) {
struct V_52 * V_379 = V_2 -> V_53 [ V_60 ] ;
if ( V_379 -> V_158 . V_37 || V_379 -> V_71 . V_37 )
V_378 |= F_121 ( V_60 ) ;
}
F_19 ( V_10 , V_380 , V_378 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_381 = V_2 -> V_381 ;
bool V_382 = V_2 -> V_382 ;
T_10 V_212 ;
F_180 ( & V_2 -> V_271 ) ;
V_212 = V_10 -> V_194 . V_265 . V_383 ( V_10 , & V_381 , & V_382 , false ) ;
F_181 ( & V_2 -> V_271 ) ;
if ( V_212 && F_260 ( V_75 , V_2 -> V_341 + ( 10 * V_376 ) ) ) {
F_36 ( V_50 , & V_2 -> V_4 ) ;
V_382 = false ;
}
V_2 -> V_382 = V_382 ;
V_2 -> V_381 = V_381 ;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_51 * V_40 = V_2 -> V_40 ;
if ( F_51 ( V_40 ) )
return;
F_248 ( & V_2 -> V_13 -> V_14 , L_37 ,
( V_2 -> V_381 == V_384 ) ?
L_38 :
( V_2 -> V_381 == V_385 ) ?
L_39 :
( V_2 -> V_381 == V_386 ) ?
L_40 :
L_41 ) ;
F_262 ( V_40 ) ;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_51 * V_40 = V_2 -> V_40 ;
V_2 -> V_381 = 0 ;
if ( ! F_51 ( V_40 ) )
return;
F_248 ( & V_2 -> V_13 -> V_14 , L_42 ) ;
F_215 ( V_40 ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_338 , & V_2 -> V_4 ) )
return;
F_259 ( V_2 ) ;
if ( V_2 -> V_382 )
F_261 ( V_2 ) ;
else
F_263 ( V_2 ) ;
F_251 ( V_2 ) ;
}
static void F_265 ( struct V_387 * V_388 )
{
struct V_1 * V_2 = F_114 ( V_388 ,
struct V_1 ,
V_8 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
if ( F_14 ( V_10 -> V_12 ) ) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_266 () ;
F_213 ( V_2 ) ;
F_267 () ;
}
return;
}
F_268 ( V_2 ) ;
F_255 ( V_2 ) ;
F_264 ( V_2 ) ;
F_257 ( V_2 ) ;
F_5 ( V_2 ) ;
}
void F_269 ( struct V_28 * V_29 )
{
F_210 ( V_29 ) ;
F_270 ( V_29 -> V_62 ) ;
V_29 -> V_62 = NULL ;
if ( ! V_29 -> V_337 )
return;
F_271 ( V_29 -> V_14 , V_29 -> V_136 , V_29 -> V_337 ,
V_29 -> V_34 ) ;
V_29 -> V_337 = NULL ;
}
static void F_272 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ )
if ( V_2 -> V_29 [ V_60 ] -> V_337 )
F_269 ( V_2 -> V_29 [ V_60 ] ) ;
}
int F_273 ( struct V_28 * V_29 )
{
int V_136 ;
V_136 = sizeof( struct V_30 ) * V_29 -> V_44 ;
V_29 -> V_62 = F_274 ( V_136 ) ;
if ( ! V_29 -> V_62 )
goto V_212;
V_29 -> V_136 = V_29 -> V_44 * sizeof( union V_55 ) ;
V_29 -> V_136 = F_94 ( V_29 -> V_136 , 4096 ) ;
V_29 -> V_337 = F_275 ( V_29 -> V_14 , V_29 -> V_136 ,
& V_29 -> V_34 , V_347 ) ;
if ( ! V_29 -> V_337 )
goto V_212;
return 0 ;
V_212:
F_270 ( V_29 -> V_62 ) ;
V_29 -> V_62 = NULL ;
F_139 ( & V_2 -> V_10 , L_43 ) ;
return - V_351 ;
}
static int F_276 ( struct V_1 * V_2 )
{
int V_60 , V_212 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
V_212 = F_273 ( V_2 -> V_29 [ V_60 ] ) ;
if ( ! V_212 )
continue;
F_139 ( & V_2 -> V_10 , L_44 , V_60 ) ;
break;
}
return V_212 ;
}
int F_277 ( struct V_28 * V_103 )
{
int V_136 ;
V_136 = sizeof( struct V_114 ) * V_103 -> V_44 ;
V_103 -> V_123 = F_274 ( V_136 ) ;
if ( ! V_103 -> V_123 )
goto V_212;
V_103 -> V_136 = V_103 -> V_44 * sizeof( union V_79 ) ;
V_103 -> V_136 = F_94 ( V_103 -> V_136 , 4096 ) ;
V_103 -> V_337 = F_275 ( V_103 -> V_14 , V_103 -> V_136 ,
& V_103 -> V_34 , V_347 ) ;
if ( ! V_103 -> V_337 )
goto V_212;
return 0 ;
V_212:
F_270 ( V_103 -> V_123 ) ;
V_103 -> V_123 = NULL ;
F_10 ( V_103 -> V_14 , L_45 ) ;
return - V_351 ;
}
static int F_278 ( struct V_1 * V_2 )
{
int V_60 , V_212 = 0 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
V_212 = F_277 ( V_2 -> V_103 [ V_60 ] ) ;
if ( ! V_212 )
continue;
F_139 ( & V_2 -> V_10 , L_46 , V_60 ) ;
break;
}
return V_212 ;
}
void F_279 ( struct V_28 * V_103 )
{
F_208 ( V_103 ) ;
F_270 ( V_103 -> V_123 ) ;
V_103 -> V_123 = NULL ;
F_271 ( V_103 -> V_14 , V_103 -> V_136 , V_103 -> V_337 ,
V_103 -> V_34 ) ;
V_103 -> V_337 = NULL ;
}
static void F_280 ( struct V_1 * V_2 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
if ( V_2 -> V_103 [ V_60 ] -> V_337 )
F_279 ( V_2 -> V_103 [ V_60 ] ) ;
}
int F_281 ( struct V_51 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_212 ;
if ( ! V_2 -> V_175 )
return - V_351 ;
if ( V_10 -> V_389 ) {
F_219 ( V_2 ) ;
if ( V_10 -> V_389 ) {
V_212 = V_273 ;
F_48 ( L_47 ) ;
goto V_390;
}
}
if ( F_2 ( V_391 , & V_2 -> V_4 ) )
return - V_392 ;
F_215 ( V_40 ) ;
V_212 = F_276 ( V_2 ) ;
if ( V_212 )
goto V_393;
V_212 = F_278 ( V_2 ) ;
if ( V_212 )
goto V_394;
F_199 ( V_2 ) ;
F_135 ( V_2 ) ;
V_212 = F_142 ( V_2 ) ;
if ( V_212 )
goto V_395;
F_203 ( V_2 ) ;
return 0 ;
V_395:
F_213 ( V_2 ) ;
V_394:
F_280 ( V_2 ) ;
V_393:
F_272 ( V_2 ) ;
F_219 ( V_2 ) ;
V_390:
return V_212 ;
}
int F_282 ( struct V_51 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
F_213 ( V_2 ) ;
F_143 ( V_2 ) ;
F_272 ( V_2 ) ;
F_280 ( V_2 ) ;
return 0 ;
}
static void F_268 ( struct V_1 * V_2 )
{
struct V_51 * V_14 = V_2 -> V_40 ;
if ( ! F_256 ( V_297 ,
& V_2 -> V_4 ) )
return;
if ( F_2 ( V_3 , & V_2 -> V_4 ) ||
F_2 ( V_338 , & V_2 -> V_4 ) )
return;
if ( F_283 ( V_14 ) )
F_282 ( V_14 ) ;
F_245 ( V_2 ) ;
F_244 ( V_2 ) ;
if ( F_283 ( V_14 ) )
F_281 ( V_14 ) ;
}
static void F_284 ( struct V_28 * V_29 ,
T_1 V_396 , T_1 V_397 ,
T_1 V_398 )
{
struct V_399 * V_400 ;
T_6 V_60 = V_29 -> V_73 ;
V_400 = F_285 ( V_29 , V_60 ) ;
V_60 ++ ;
V_29 -> V_73 = ( V_60 < V_29 -> V_44 ) ? V_60 : 0 ;
V_397 |= V_401 | V_402 ;
V_400 -> V_396 = F_41 ( V_396 ) ;
V_400 -> V_403 = 0 ;
V_400 -> V_404 = F_41 ( V_397 ) ;
V_400 -> V_398 = F_41 ( V_398 ) ;
}
static int F_286 ( struct V_28 * V_29 ,
struct V_30 * V_405 ,
T_2 * V_406 )
{
T_1 V_396 , V_397 , V_398 ;
struct V_77 * V_32 = V_405 -> V_32 ;
union {
struct V_407 * V_408 ;
struct V_409 * V_410 ;
unsigned char * V_411 ;
} V_412 ;
union {
struct V_413 * V_414 ;
unsigned char * V_411 ;
} V_415 ;
T_1 V_416 , V_417 ;
int V_212 ;
if ( V_32 -> V_101 != V_418 )
return 0 ;
if ( ! F_287 ( V_32 ) )
return 0 ;
V_212 = F_288 ( V_32 , 0 ) ;
if ( V_212 < 0 )
return V_212 ;
V_412 . V_411 = F_289 ( V_32 ) ;
V_415 . V_411 = F_290 ( V_32 ) ;
V_397 = V_419 ;
if ( V_412 . V_408 -> V_420 == 4 ) {
V_412 . V_408 -> V_421 = F_291 ( F_292 ( F_293 ( V_32 ) ,
F_294 ( V_415 . V_414 -> V_421 ) ) ) ;
V_397 |= V_422 ;
V_412 . V_408 -> V_423 = 0 ;
V_405 -> V_424 |= V_425 |
V_426 |
V_427 ;
} else {
V_412 . V_410 -> V_428 = 0 ;
V_405 -> V_424 |= V_425 |
V_426 ;
}
V_417 = V_415 . V_411 - V_32 -> V_146 ;
* V_406 = ( V_415 . V_414 -> V_429 * 4 ) + V_417 ;
V_416 = V_32 -> V_33 - V_417 ;
F_295 ( & V_415 . V_414 -> V_421 , F_296 ( V_416 ) ) ;
V_405 -> V_68 = F_100 ( V_32 ) -> V_68 ;
V_405 -> V_67 += ( V_405 -> V_68 - 1 ) * * V_406 ;
V_398 = ( * V_406 - V_417 ) << V_430 ;
V_398 |= F_100 ( V_32 ) -> V_431 << V_432 ;
V_398 |= ( 1u << V_433 ) ;
V_396 = V_415 . V_411 - V_412 . V_411 ;
V_396 |= ( V_412 . V_411 - V_32 -> V_146 ) << V_434 ;
V_396 |= V_405 -> V_424 & V_435 ;
F_284 ( V_29 , V_396 ,
V_397 , V_398 ) ;
return 1 ;
}
static inline bool F_297 ( struct V_77 * V_32 )
{
unsigned int V_436 = 0 ;
F_298 ( V_32 , & V_436 , V_437 , NULL , NULL ) ;
return V_436 == F_299 ( V_32 ) ;
}
static void F_300 ( struct V_28 * V_29 ,
struct V_30 * V_405 )
{
struct V_77 * V_32 = V_405 -> V_32 ;
T_1 V_396 = 0 ;
T_1 V_397 = 0 ;
if ( V_32 -> V_101 != V_418 )
goto V_438;
switch ( V_32 -> V_439 ) {
case F_301 ( struct V_413 , V_421 ) :
V_397 = V_419 ;
case F_301 ( struct V_440 , V_421 ) :
break;
case F_301 ( struct V_441 , V_442 ) :
if ( ( ( V_405 -> V_111 == F_71 ( V_443 ) ) &&
( F_302 ( V_32 ) -> V_111 == V_437 ) ) ||
( ( V_405 -> V_111 == F_71 ( V_444 ) ) &&
F_297 ( V_32 ) ) ) {
V_397 = V_445 ;
break;
}
default:
F_303 ( V_32 ) ;
goto V_438;
}
V_405 -> V_424 |= V_426 ;
V_396 = F_299 ( V_32 ) -
F_304 ( V_32 ) ;
V_438:
V_396 |= F_304 ( V_32 ) << V_434 ;
V_396 |= V_405 -> V_424 & V_435 ;
F_284 ( V_29 , V_396 , V_397 , 0 ) ;
}
static T_11 F_305 ( T_1 V_424 )
{
T_11 V_446 = F_41 ( V_447 |
V_448 |
V_449 ) ;
if ( V_424 & V_450 )
V_446 |= F_41 ( V_451 ) ;
if ( V_424 & V_425 )
V_446 |= F_41 ( V_452 ) ;
return V_446 ;
}
static void F_306 ( union V_55 * V_56 ,
T_1 V_424 , unsigned int V_416 )
{
T_11 V_453 = F_41 ( V_416 << V_454 ) ;
if ( V_424 & V_426 )
V_453 |= F_41 ( V_455 ) ;
if ( V_424 & V_427 )
V_453 |= F_41 ( V_456 ) ;
if ( V_424 & V_425 )
V_453 |= F_41 ( 1u << V_433 ) ;
V_453 |= F_41 ( V_457 ) ;
V_56 -> V_124 . V_453 = V_453 ;
}
static void F_307 ( struct V_28 * V_29 ,
struct V_30 * V_405 ,
const T_2 V_406 )
{
T_7 V_34 ;
struct V_77 * V_32 = V_405 -> V_32 ;
struct V_30 * V_31 ;
union V_55 * V_56 ;
struct V_458 * V_459 = & F_100 ( V_32 ) -> V_460 [ 0 ] ;
unsigned int V_461 = V_32 -> V_461 ;
unsigned int V_136 = F_308 ( V_32 ) ;
unsigned int V_416 = V_32 -> V_33 - V_406 ;
T_1 V_424 = V_405 -> V_424 ;
T_11 V_446 ;
T_6 V_60 = V_29 -> V_73 ;
V_56 = F_39 ( V_29 , V_60 ) ;
F_306 ( V_56 , V_424 , V_416 ) ;
V_446 = F_305 ( V_424 ) ;
V_34 = F_309 ( V_29 -> V_14 , V_32 -> V_146 , V_136 , V_35 ) ;
if ( F_78 ( V_29 -> V_14 , V_34 ) )
goto V_462;
F_27 ( V_405 , V_33 , V_136 ) ;
F_310 ( V_405 , V_34 , V_34 ) ;
V_56 -> V_124 . V_463 = F_81 ( V_34 ) ;
for (; ; ) {
while ( F_16 ( V_136 > V_464 ) ) {
V_56 -> V_124 . V_465 =
V_446 | F_41 ( V_464 ) ;
V_60 ++ ;
V_56 ++ ;
if ( V_60 == V_29 -> V_44 ) {
V_56 = F_39 ( V_29 , 0 ) ;
V_60 = 0 ;
}
V_34 += V_464 ;
V_136 -= V_464 ;
V_56 -> V_124 . V_463 = F_81 ( V_34 ) ;
V_56 -> V_124 . V_453 = 0 ;
}
if ( F_44 ( ! V_461 ) )
break;
V_56 -> V_124 . V_465 = V_446 | F_41 ( V_136 ) ;
V_60 ++ ;
V_56 ++ ;
if ( V_60 == V_29 -> V_44 ) {
V_56 = F_39 ( V_29 , 0 ) ;
V_60 = 0 ;
}
V_136 = F_311 ( V_459 ) ;
V_461 -= V_136 ;
V_34 = F_312 ( V_29 -> V_14 , V_459 , 0 , V_136 ,
V_35 ) ;
if ( F_78 ( V_29 -> V_14 , V_34 ) )
goto V_462;
V_31 = & V_29 -> V_62 [ V_60 ] ;
F_27 ( V_31 , V_33 , V_136 ) ;
F_310 ( V_31 , V_34 , V_34 ) ;
V_56 -> V_124 . V_463 = F_81 ( V_34 ) ;
V_56 -> V_124 . V_453 = 0 ;
V_459 ++ ;
}
V_446 |= F_41 ( V_136 ) | F_41 ( V_466 ) ;
V_56 -> V_124 . V_465 = V_446 ;
V_405 -> V_74 = V_75 ;
F_82 () ;
V_405 -> V_36 = V_56 ;
V_60 ++ ;
if ( V_60 == V_29 -> V_44 )
V_60 = 0 ;
V_29 -> V_73 = V_60 ;
F_83 ( V_29 , V_60 ) ;
return;
V_462:
F_10 ( V_29 -> V_14 , L_48 ) ;
for (; ; ) {
V_31 = & V_29 -> V_62 [ V_60 ] ;
F_21 ( V_29 , V_31 ) ;
if ( V_31 == V_405 )
break;
if ( V_60 == 0 )
V_60 = V_29 -> V_44 ;
V_60 -- ;
}
V_29 -> V_73 = V_60 ;
}
static int F_313 ( struct V_28 * V_29 , int V_136 )
{
F_49 ( V_29 -> V_40 , V_29 -> V_72 ) ;
F_53 () ;
if ( F_44 ( F_52 ( V_29 ) < V_136 ) )
return - V_392 ;
F_314 ( V_29 -> V_40 , V_29 -> V_72 ) ;
++ V_29 -> V_47 . V_76 ;
return 0 ;
}
static int F_315 ( struct V_28 * V_29 , int V_136 )
{
if ( F_44 ( F_52 ( V_29 ) >= V_136 ) )
return 0 ;
return F_313 ( V_29 , V_136 ) ;
}
static int F_316 ( struct V_77 * V_32 , struct V_51 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_30 * V_405 ;
struct V_28 * V_29 ;
int V_467 ;
T_1 V_424 = 0 ;
T_6 V_44 = F_317 ( F_308 ( V_32 ) ) ;
#if V_118 > V_464
unsigned short V_468 ;
#endif
T_2 V_406 = 0 ;
T_2 * V_469 = F_318 ( V_32 , 0 , 0 , NULL ) ;
if ( ! V_469 || F_319 ( V_469 ) ) {
F_22 ( V_32 ) ;
return V_470 ;
}
V_29 = V_2 -> V_29 [ V_32 -> V_471 ] ;
#if V_118 > V_464
for ( V_468 = 0 ; V_468 < F_100 ( V_32 ) -> V_143 ; V_468 ++ )
V_44 += F_317 ( F_100 ( V_32 ) -> V_460 [ V_468 ] . V_136 ) ;
#else
V_44 += F_100 ( V_32 ) -> V_143 ;
#endif
if ( F_315 ( V_29 , V_44 + 3 ) ) {
V_29 -> V_47 . V_472 ++ ;
return V_473 ;
}
V_405 = & V_29 -> V_62 [ V_29 -> V_73 ] ;
V_405 -> V_32 = V_32 ;
V_405 -> V_67 = V_32 -> V_33 ;
V_405 -> V_68 = 1 ;
if ( F_320 ( V_32 ) ) {
V_424 |= F_321 ( V_32 ) ;
V_424 <<= V_474 ;
V_424 |= V_450 ;
}
V_405 -> V_424 = V_424 ;
V_405 -> V_111 = F_322 ( V_32 ) ;
V_467 = F_286 ( V_29 , V_405 , & V_406 ) ;
if ( V_467 < 0 )
goto V_475;
else if ( ! V_467 )
F_300 ( V_29 , V_405 ) ;
F_307 ( V_29 , V_405 , V_406 ) ;
F_315 ( V_29 , V_476 ) ;
return V_470 ;
V_475:
F_22 ( V_405 -> V_32 ) ;
V_405 -> V_32 = NULL ;
return V_470 ;
}
static int F_323 ( struct V_51 * V_40 , void * V_477 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_478 * V_281 = V_477 ;
int V_212 ;
if ( ! F_204 ( V_281 -> V_479 ) )
return - V_480 ;
F_180 ( & V_2 -> V_271 ) ;
V_212 = V_10 -> V_194 . V_265 . V_332 ( V_10 , 0 , V_281 -> V_479 , 0 ) ;
F_181 ( & V_2 -> V_271 ) ;
if ( V_212 )
return - V_481 ;
F_224 ( V_10 -> V_194 . V_281 , V_281 -> V_479 ) ;
F_224 ( V_40 -> V_156 , V_281 -> V_479 ) ;
return 0 ;
}
static int F_324 ( struct V_51 * V_40 , int V_482 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_483 = V_482 + V_268 + V_269 ;
int V_484 = V_485 ;
switch ( V_2 -> V_10 . V_346 ) {
case V_327 :
case V_326 :
V_484 = V_486 ;
break;
default:
if ( V_2 -> V_10 . V_194 . type != V_487 )
V_484 = V_486 ;
break;
}
if ( ( V_482 < 68 ) || ( V_483 > V_484 ) )
return - V_488 ;
F_139 ( V_10 , L_49 ,
V_40 -> V_267 , V_482 ) ;
V_40 -> V_267 = V_482 ;
V_10 -> V_194 . V_265 . V_266 ( V_10 , V_483 ) ;
return 0 ;
}
static void F_325 ( struct V_51 * V_40 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
int V_60 ;
if ( F_2 ( V_3 , & V_2 -> V_4 ) )
return;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ )
F_131 ( 0 , V_2 -> V_53 [ V_60 ] ) ;
}
static int F_326 ( struct V_358 * V_13 , T_12 V_4 )
{
struct V_51 * V_40 = F_327 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
#ifdef F_328
int V_489 = 0 ;
#endif
F_329 ( V_40 ) ;
if ( F_283 ( V_40 ) ) {
F_266 () ;
F_213 ( V_2 ) ;
F_143 ( V_2 ) ;
F_272 ( V_2 ) ;
F_280 ( V_2 ) ;
F_267 () ;
}
F_245 ( V_2 ) ;
#ifdef F_328
V_489 = F_330 ( V_13 ) ;
if ( V_489 )
return V_489 ;
#endif
if ( ! F_3 ( V_490 , & V_2 -> V_4 ) )
F_331 ( V_13 ) ;
return 0 ;
}
static int F_332 ( struct V_358 * V_13 )
{
struct V_51 * V_40 = F_327 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
T_1 V_212 ;
F_333 ( V_13 ) ;
F_330 ( V_13 ) ;
V_212 = F_334 ( V_13 ) ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_50 ) ;
return V_212 ;
}
F_7 () ;
F_8 ( V_490 , & V_2 -> V_4 ) ;
F_335 ( V_13 ) ;
F_219 ( V_2 ) ;
F_266 () ;
V_212 = F_244 ( V_2 ) ;
F_267 () ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_51 ) ;
return V_212 ;
}
if ( F_283 ( V_40 ) ) {
V_212 = F_281 ( V_40 ) ;
if ( V_212 )
return V_212 ;
}
F_336 ( V_40 ) ;
return V_212 ;
}
static void F_337 ( struct V_358 * V_13 )
{
F_326 ( V_13 , V_491 ) ;
}
static struct V_492 * F_338 ( struct V_51 * V_40 ,
struct V_492 * V_38 )
{
struct V_1 * V_2 = F_30 ( V_40 ) ;
unsigned int V_493 ;
T_5 V_70 , V_39 ;
const struct V_28 * V_37 ;
int V_60 ;
F_251 ( V_2 ) ;
V_38 -> V_494 = V_2 -> V_38 . V_311 - V_2 -> V_38 . V_312 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_205 ; V_60 ++ ) {
V_37 = V_2 -> V_103 [ V_60 ] ;
do {
V_493 = F_339 ( & V_37 -> V_69 ) ;
V_70 = V_37 -> V_38 . V_70 ;
V_39 = V_37 -> V_38 . V_39 ;
} while ( F_340 ( & V_37 -> V_69 , V_493 ) );
V_38 -> V_495 += V_70 ;
V_38 -> V_496 += V_39 ;
}
for ( V_60 = 0 ; V_60 < V_2 -> V_207 ; V_60 ++ ) {
V_37 = V_2 -> V_29 [ V_60 ] ;
do {
V_493 = F_339 ( & V_37 -> V_69 ) ;
V_70 = V_37 -> V_38 . V_70 ;
V_39 = V_37 -> V_38 . V_39 ;
} while ( F_340 ( & V_37 -> V_69 , V_493 ) );
V_38 -> V_497 += V_70 ;
V_38 -> V_498 += V_39 ;
}
return V_38 ;
}
static T_13
F_341 ( struct V_77 * V_32 , struct V_51 * V_14 ,
T_13 V_82 )
{
unsigned int V_499 , V_500 ;
V_500 = F_289 ( V_32 ) - V_32 -> V_146 ;
if ( F_16 ( V_500 > V_501 ) )
return V_82 & ~ ( V_502 |
V_503 |
V_504 |
V_505 |
V_506 ) ;
V_499 = F_290 ( V_32 ) - F_289 ( V_32 ) ;
if ( F_16 ( V_499 > V_507 ) )
return V_82 & ~ ( V_502 |
V_503 |
V_505 |
V_506 ) ;
if ( V_32 -> V_508 && ! ( V_82 & V_509 ) )
V_82 &= ~ V_505 ;
return V_82 ;
}
static void F_342 ( struct V_51 * V_14 )
{
V_14 -> V_510 = & V_511 ;
F_343 ( V_14 ) ;
V_14 -> V_512 = 5 * V_376 ;
}
static int F_344 ( struct V_358 * V_13 , const struct V_513 * V_514 )
{
struct V_51 * V_40 ;
struct V_1 * V_2 = NULL ;
struct V_9 * V_10 = NULL ;
const struct V_515 * V_516 = V_517 [ V_514 -> V_518 ] ;
int V_212 , V_519 ;
bool V_520 = false ;
V_212 = F_345 ( V_13 ) ;
if ( V_212 )
return V_212 ;
if ( ! F_346 ( & V_13 -> V_14 , F_151 ( 64 ) ) ) {
V_519 = 1 ;
} else {
V_212 = F_346 ( & V_13 -> V_14 , F_151 ( 32 ) ) ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_52 ) ;
goto V_521;
}
V_519 = 0 ;
}
V_212 = F_347 ( V_13 , V_522 ) ;
if ( V_212 ) {
F_10 ( & V_13 -> V_14 , L_53 , V_212 ) ;
goto V_523;
}
F_335 ( V_13 ) ;
V_40 = F_348 ( sizeof( struct V_1 ) ,
V_524 ) ;
if ( ! V_40 ) {
V_212 = - V_351 ;
goto V_525;
}
F_349 ( V_40 , & V_13 -> V_14 ) ;
V_2 = F_30 ( V_40 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_13 = V_13 ;
V_10 = & V_2 -> V_10 ;
V_10 -> V_11 = V_2 ;
V_2 -> V_526 = F_350 ( V_527 , V_528 ) ;
F_330 ( V_13 ) ;
V_10 -> V_12 = F_351 ( F_352 ( V_13 , 0 ) ,
F_353 ( V_13 , 0 ) ) ;
V_2 -> V_230 = V_10 -> V_12 ;
if ( ! V_10 -> V_12 ) {
V_212 = - V_274 ;
goto V_529;
}
F_342 ( V_40 ) ;
memcpy ( & V_10 -> V_194 . V_265 , V_516 -> V_530 , sizeof( V_10 -> V_194 . V_265 ) ) ;
V_10 -> V_194 . type = V_516 -> V_194 ;
memcpy ( & V_10 -> V_295 . V_265 , & V_531 ,
sizeof( struct V_532 ) ) ;
V_212 = F_246 ( V_2 ) ;
if ( V_212 )
goto V_533;
if ( ! F_204 ( V_40 -> V_156 ) ) {
F_48 ( L_54 ) ;
V_212 = - V_274 ;
goto V_533;
}
V_40 -> V_534 = V_535 |
V_505 |
V_506 |
V_94 |
V_502 |
V_503 ;
#define F_354 (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
V_40 -> V_536 = F_354 ;
V_40 -> V_534 |= V_537 |
F_354 ;
V_40 -> V_82 = V_40 -> V_534 ;
if ( V_519 )
V_40 -> V_82 |= V_538 ;
V_40 -> V_539 |= V_40 -> V_82 | V_509 ;
V_40 -> V_540 |= V_502 ;
V_40 -> V_541 |= V_40 -> V_539 ;
V_40 -> V_82 |= V_542 |
V_543 |
V_504 ;
V_40 -> V_544 |= V_545 ;
if ( F_14 ( V_10 -> V_12 ) ) {
V_212 = - V_274 ;
goto V_533;
}
F_355 ( & V_2 -> V_335 , & F_254 ,
( unsigned long ) V_2 ) ;
F_356 ( & V_2 -> V_8 , F_265 ) ;
F_36 ( V_15 , & V_2 -> V_4 ) ;
F_8 ( V_6 , & V_2 -> V_4 ) ;
V_212 = F_244 ( V_2 ) ;
if ( V_212 )
goto V_533;
strcpy ( V_40 -> V_218 , L_55 ) ;
V_212 = F_357 ( V_40 ) ;
if ( V_212 )
goto V_546;
F_358 ( V_13 , V_40 ) ;
F_215 ( V_40 ) ;
F_201 ( V_2 ) ;
F_248 ( & V_13 -> V_14 , L_56 , V_40 -> V_156 ) ;
F_248 ( & V_13 -> V_14 , L_57 , V_10 -> V_194 . type ) ;
switch ( V_10 -> V_194 . type ) {
case V_264 :
F_248 ( & V_13 -> V_14 , L_58 ) ;
break;
case V_547 :
F_248 ( & V_13 -> V_14 , L_59 ) ;
break;
case V_487 :
default:
F_248 ( & V_13 -> V_14 , L_60 ) ;
break;
}
return 0 ;
V_546:
F_245 ( V_2 ) ;
V_533:
F_242 ( V_2 ) ;
F_359 ( V_2 -> V_230 ) ;
V_529:
V_520 = ! F_3 ( V_490 , & V_2 -> V_4 ) ;
F_360 ( V_40 ) ;
V_525:
F_361 ( V_13 ) ;
V_523:
V_521:
if ( ! V_2 || V_520 )
F_331 ( V_13 ) ;
return V_212 ;
}
static void F_362 ( struct V_358 * V_13 )
{
struct V_51 * V_40 = F_327 ( V_13 ) ;
struct V_1 * V_2 ;
bool V_520 ;
if ( ! V_40 )
return;
V_2 = F_30 ( V_40 ) ;
F_36 ( V_5 , & V_2 -> V_4 ) ;
F_363 ( & V_2 -> V_8 ) ;
if ( V_40 -> V_548 == V_549 )
F_364 ( V_40 ) ;
F_245 ( V_2 ) ;
F_242 ( V_2 ) ;
F_359 ( V_2 -> V_230 ) ;
F_361 ( V_13 ) ;
F_139 ( & V_2 -> V_10 , L_61 ) ;
V_520 = ! F_3 ( V_490 , & V_2 -> V_4 ) ;
F_360 ( V_40 ) ;
if ( V_520 )
F_331 ( V_13 ) ;
}
static T_14 F_365 ( struct V_358 * V_13 ,
T_15 V_4 )
{
struct V_51 * V_40 = F_327 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
if ( ! F_2 ( V_15 , & V_2 -> V_4 ) )
return V_550 ;
F_266 () ;
F_329 ( V_40 ) ;
if ( V_4 == V_551 ) {
F_267 () ;
return V_550 ;
}
if ( F_283 ( V_40 ) )
F_213 ( V_2 ) ;
if ( ! F_3 ( V_490 , & V_2 -> V_4 ) )
F_331 ( V_13 ) ;
F_267 () ;
return V_552 ;
}
static T_14 F_366 ( struct V_358 * V_13 )
{
struct V_51 * V_40 = F_327 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
if ( F_334 ( V_13 ) ) {
F_10 ( & V_13 -> V_14 ,
L_62 ) ;
return V_550 ;
}
F_7 () ;
F_8 ( V_490 , & V_2 -> V_4 ) ;
F_335 ( V_13 ) ;
F_219 ( V_2 ) ;
return V_553 ;
}
static void F_367 ( struct V_358 * V_13 )
{
struct V_51 * V_40 = F_327 ( V_13 ) ;
struct V_1 * V_2 = F_30 ( V_40 ) ;
if ( F_283 ( V_40 ) )
F_207 ( V_2 ) ;
F_336 ( V_40 ) ;
}
static int T_16 F_368 ( void )
{
F_196 ( L_63 , V_554 ,
V_555 ) ;
F_196 ( L_64 , V_556 ) ;
V_7 = F_369 ( V_522 ) ;
if ( ! V_7 ) {
F_48 ( L_65 , V_522 ) ;
return - V_351 ;
}
return F_370 ( & V_557 ) ;
}
static void T_17 F_371 ( void )
{
F_372 ( & V_557 ) ;
if ( V_7 ) {
F_373 ( V_7 ) ;
V_7 = NULL ;
}
}
char * F_374 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
return V_2 -> V_40 -> V_218 ;
}
