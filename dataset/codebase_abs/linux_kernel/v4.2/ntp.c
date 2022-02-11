static inline T_1 F_1 ( T_1 V_1 )
{
if ( V_2 & V_3 && V_2 & V_4 )
return V_1 ;
else
return F_2 ( V_1 , V_5 + V_6 ) ;
}
static inline void F_3 ( void )
{
V_7 = V_8 ;
V_9 = 0 ;
}
static inline void F_4 ( void )
{
F_3 () ;
V_10 [ 0 ] = 0 ;
V_10 [ 1 ] = 0 ;
V_10 [ 2 ] = 0 ;
V_11 . V_12 = V_11 . V_13 = 0 ;
V_14 = 0 ;
}
static inline void F_5 ( void )
{
if ( V_15 > 0 )
V_15 -- ;
else {
V_2 &= ~ ( V_4 | V_16 |
V_17 | V_18 ) ;
F_4 () ;
}
}
static inline void F_6 ( T_1 V_19 )
{
V_14 = V_19 ;
}
static inline int F_7 ( int V_20 )
{
return ( V_20 & ( V_21 | V_22 ) )
|| ( ( V_20 & ( V_23 | V_3 ) )
&& ! ( V_20 & V_4 ) )
|| ( ( V_20 & ( V_3 | V_16 ) )
== ( V_3 | V_16 ) )
|| ( ( V_20 & V_23 )
&& ( V_20 & ( V_17 | V_18 ) ) ) ;
}
static inline void F_8 ( struct V_24 * V_25 )
{
V_25 -> V_26 = F_2 ( ( V_14 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_30 = V_31 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_30 /= V_33 ;
V_25 -> V_34 = V_7 ;
V_25 -> V_35 = V_36 ;
V_25 -> V_37 = V_38 ;
V_25 -> V_39 = V_40 ;
V_25 -> V_41 = V_42 ;
V_25 -> V_43 = V_44 ;
}
static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_1 , V_5 + V_6 ) ;
}
static inline void F_3 ( void ) {}
static inline void F_4 ( void ) {}
static inline void F_5 ( void ) {}
static inline void F_6 ( T_1 V_19 ) {}
static inline int F_7 ( int V_20 )
{
return V_20 & ( V_21 | V_22 ) ;
}
static inline void F_8 ( struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
V_25 -> V_30 = 0 ;
V_25 -> V_34 = 0 ;
V_25 -> V_35 = 0 ;
V_25 -> V_37 = 0 ;
V_25 -> V_39 = 0 ;
V_25 -> V_41 = 0 ;
V_25 -> V_43 = 0 ;
}
static inline int F_9 ( void )
{
return ! ( V_2 & V_21 ) ;
}
static void F_10 ( void )
{
T_2 V_45 ;
T_2 V_46 ;
V_45 = ( T_2 ) ( V_47 * V_33 * V_48 )
<< V_29 ;
V_45 += V_49 ;
V_45 += V_50 ;
V_51 = F_11 ( V_45 , V_52 ) >> V_29 ;
V_46 = F_11 ( V_45 , V_53 ) ;
V_54 += V_46 - V_55 ;
V_55 = V_46 ;
}
static inline T_1 F_12 ( T_1 V_56 , long V_57 )
{
V_2 &= ~ V_58 ;
if ( V_57 < V_59 )
return 0 ;
if ( ! ( V_2 & V_60 ) && ( V_57 <= V_61 ) )
return 0 ;
V_2 |= V_58 ;
return F_13 ( V_56 << ( V_29 - V_62 ) , V_57 ) ;
}
static void F_14 ( long V_1 )
{
T_1 V_63 ;
T_1 V_56 ;
long V_57 ;
if ( ! ( V_2 & V_64 ) )
return;
if ( ! ( V_2 & V_32 ) )
V_1 *= V_33 ;
V_1 = F_15 ( V_1 , V_65 ) ;
V_1 = F_16 ( V_1 , - V_65 ) ;
V_57 = F_17 () - V_66 ;
if ( F_18 ( V_2 & V_67 ) )
V_57 = 0 ;
V_66 = F_17 () ;
V_56 = V_1 ;
V_63 = F_12 ( V_56 , V_57 ) ;
if ( F_18 ( V_57 > 1 << ( V_5 + 1 + V_6 ) ) )
V_57 = 1 << ( V_5 + 1 + V_6 ) ;
V_63 += ( V_56 * V_57 ) <<
( V_29 - 2 * ( V_5 + 2 + V_6 ) ) ;
V_63 = F_15 ( V_63 + V_50 , V_68 ) ;
V_50 = F_16 ( V_63 , - V_68 ) ;
V_69 = F_19 ( V_56 << V_29 , V_53 ) ;
}
void F_20 ( void )
{
V_70 = 0 ;
V_2 |= V_21 ;
V_71 = V_72 ;
V_73 = V_72 ;
F_10 () ;
V_54 = V_55 ;
V_69 = 0 ;
V_74 = V_75 ;
F_4 () ;
}
T_2 F_21 ( void )
{
return V_54 ;
}
T_3 F_22 ( void )
{
T_3 V_76 ;
if ( ( V_77 == V_78 ) && ( V_2 & V_79 ) )
return F_23 ( V_74 , 0 ) ;
V_76 . V_80 = V_81 ;
return V_76 ;
}
int F_24 ( unsigned long V_57 )
{
T_1 V_82 ;
int V_83 = 0 ;
switch ( V_77 ) {
case V_84 :
if ( V_2 & V_79 ) {
V_77 = V_78 ;
V_74 = V_57 + V_85 -
( V_57 % V_85 ) ;
} else if ( V_2 & V_86 ) {
V_77 = V_87 ;
V_74 = V_57 + V_85 -
( ( V_57 + 1 ) % V_85 ) ;
}
break;
case V_78 :
if ( ! ( V_2 & V_79 ) ) {
V_74 = V_75 ;
V_77 = V_84 ;
} else if ( V_57 % V_85 == 0 ) {
V_83 = - 1 ;
V_77 = V_88 ;
F_25 ( V_89
L_1 ) ;
}
break;
case V_87 :
if ( ! ( V_2 & V_86 ) ) {
V_74 = V_75 ;
V_77 = V_84 ;
} else if ( ( V_57 + 1 ) % V_85 == 0 ) {
V_83 = 1 ;
V_74 = V_75 ;
V_77 = V_90 ;
F_25 ( V_89
L_2 ) ;
}
break;
case V_88 :
V_74 = V_75 ;
V_77 = V_90 ;
break;
case V_90 :
if ( ! ( V_2 & ( V_79 | V_86 ) ) )
V_77 = V_84 ;
break;
}
V_71 += V_91 / V_33 ;
if ( V_71 > V_72 ) {
V_71 = V_72 ;
V_2 |= V_21 ;
}
V_54 = V_55 ;
V_82 = F_1 ( V_69 ) ;
V_69 -= V_82 ;
V_54 += V_82 ;
F_5 () ;
if ( ! V_70 )
goto V_92;
if ( V_70 > V_93 ) {
V_70 -= V_93 ;
V_54 += V_94 ;
goto V_92;
}
if ( V_70 < - V_93 ) {
V_70 += V_93 ;
V_54 -= V_94 ;
goto V_92;
}
V_54 += ( T_1 ) ( V_70 * V_33 / V_53 )
<< V_29 ;
V_70 = 0 ;
V_92:
return V_83 ;
}
int __weak F_26 ( struct V_95 V_96 )
{
struct V_97 V_98 ;
V_98 = F_27 ( V_96 ) ;
return F_28 ( V_98 ) ;
}
static void F_29 ( struct V_99 * V_100 )
{
struct V_95 V_98 ;
struct V_97 V_101 ;
int V_102 = 1 ;
if ( ! F_9 () ) {
return;
}
F_30 ( & V_98 ) ;
if ( abs ( V_98 . V_13 - ( V_103 / 2 ) ) <= V_51 * 5 ) {
struct V_95 V_104 = V_98 ;
V_102 = - V_105 ;
if ( V_106 )
V_104 . V_12 -= ( V_107 . V_108 * 60 ) ;
#ifdef F_31
V_102 = F_26 ( V_104 ) ;
#endif
#ifdef F_32
if ( V_102 == - V_105 )
V_102 = F_33 ( V_104 ) ;
#endif
}
V_101 . V_13 = ( V_103 / 2 ) - V_98 . V_13 - ( V_109 / 2 ) ;
if ( V_101 . V_13 <= 0 )
V_101 . V_13 += V_103 ;
if ( ! V_102 || V_102 == - V_105 )
V_101 . V_12 = 659 ;
else
V_101 . V_12 = 0 ;
if ( V_101 . V_13 >= V_103 ) {
V_101 . V_12 ++ ;
V_101 . V_13 -= V_103 ;
}
F_34 ( V_110 ,
& V_111 , F_35 ( & V_101 ) ) ;
}
void F_36 ( void )
{
F_34 ( V_110 , & V_111 , 0 ) ;
}
void F_36 ( void ) { }
static inline void F_37 ( struct V_24 * V_25 , struct V_95 * V_112 )
{
if ( ( V_2 & V_64 ) && ! ( V_25 -> V_20 & V_64 ) ) {
V_77 = V_84 ;
V_2 = V_21 ;
V_74 = V_75 ;
F_3 () ;
}
if ( ! ( V_2 & V_64 ) && ( V_25 -> V_20 & V_64 ) )
V_66 = F_17 () ;
V_2 &= V_113 ;
V_2 |= V_25 -> V_20 & ~ V_113 ;
}
static inline void F_38 ( struct V_24 * V_25 ,
struct V_95 * V_112 ,
T_4 * V_114 )
{
if ( V_25 -> V_115 & V_116 )
F_37 ( V_25 , V_112 ) ;
if ( V_25 -> V_115 & V_117 )
V_2 |= V_32 ;
if ( V_25 -> V_115 & V_118 )
V_2 &= ~ V_32 ;
if ( V_25 -> V_115 & V_119 ) {
V_50 = V_25 -> V_19 * V_120 ;
V_50 = F_15 ( V_50 , V_68 ) ;
V_50 = F_16 ( V_50 , - V_68 ) ;
F_6 ( V_50 ) ;
}
if ( V_25 -> V_115 & V_121 )
V_71 = V_25 -> V_122 ;
if ( V_25 -> V_115 & V_123 )
V_73 = V_25 -> V_124 ;
if ( V_25 -> V_115 & V_125 ) {
V_6 = V_25 -> V_126 ;
if ( ! ( V_2 & V_32 ) )
V_6 += 4 ;
V_6 = F_15 ( V_6 , ( long ) V_127 ) ;
V_6 = F_16 ( V_6 , 0l ) ;
}
if ( V_25 -> V_115 & V_128 && V_25 -> V_126 > 0 )
* V_114 = V_25 -> V_126 ;
if ( V_25 -> V_115 & V_129 )
F_14 ( V_25 -> V_1 ) ;
if ( V_25 -> V_115 & V_130 )
V_47 = V_25 -> V_131 ;
if ( V_25 -> V_115 & ( V_130 | V_119 | V_129 ) )
F_10 () ;
}
int F_39 ( struct V_24 * V_25 )
{
if ( V_25 -> V_115 & V_132 ) {
if ( ! ( V_25 -> V_115 & V_133 ) )
return - V_134 ;
if ( ! ( V_25 -> V_115 & V_135 ) &&
! F_40 ( V_136 ) )
return - V_137 ;
} else {
if ( V_25 -> V_115 && ! F_40 ( V_136 ) )
return - V_137 ;
if ( V_25 -> V_115 & V_130 &&
( V_25 -> V_131 < 900000 / V_48 ||
V_25 -> V_131 > 1100000 / V_48 ) )
return - V_134 ;
}
if ( ( V_25 -> V_115 & V_138 ) && ( ! F_40 ( V_136 ) ) )
return - V_137 ;
if ( ( V_25 -> V_115 & V_119 ) && ( V_139 == 64 ) ) {
if ( V_140 / V_120 > V_25 -> V_19 )
return - V_134 ;
if ( V_141 / V_120 < V_25 -> V_19 )
return - V_134 ;
}
return 0 ;
}
int F_41 ( struct V_24 * V_25 , struct V_95 * V_112 , T_4 * V_114 )
{
int V_142 ;
if ( V_25 -> V_115 & V_132 ) {
long V_143 = V_70 ;
if ( ! ( V_25 -> V_115 & V_135 ) ) {
V_70 = V_25 -> V_1 ;
F_10 () ;
}
V_25 -> V_1 = V_143 ;
} else {
if ( V_25 -> V_115 )
F_38 ( V_25 , V_112 , V_114 ) ;
V_25 -> V_1 = F_2 ( V_69 * V_53 ,
V_29 ) ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_1 /= V_33 ;
}
V_142 = V_77 ;
if ( F_7 ( V_2 ) )
V_142 = V_144 ;
V_25 -> V_19 = F_2 ( ( V_50 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_122 = V_71 ;
V_25 -> V_124 = V_73 ;
V_25 -> V_20 = V_2 ;
V_25 -> V_126 = V_6 ;
V_25 -> V_145 = 1 ;
V_25 -> V_146 = V_68 / V_120 ;
V_25 -> V_131 = V_47 ;
V_25 -> V_147 = * V_114 ;
F_8 ( V_25 ) ;
V_25 -> time . V_12 = ( V_148 ) V_112 -> V_12 ;
V_25 -> time . V_149 = V_112 -> V_13 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> time . V_149 /= V_33 ;
if ( F_18 ( V_112 -> V_12 >= V_74 ) ) {
if ( ( V_77 == V_78 ) && ( V_2 & V_79 ) ) {
V_142 = V_88 ;
V_25 -> V_147 ++ ;
V_25 -> time . V_12 -- ;
}
if ( ( V_77 == V_87 ) && ( V_2 & V_86 ) ) {
V_142 = V_90 ;
V_25 -> V_147 -- ;
V_25 -> time . V_12 ++ ;
}
if ( ( V_77 == V_88 ) &&
( V_112 -> V_12 == V_74 ) ) {
V_142 = V_90 ;
}
}
return V_142 ;
}
static inline struct V_150 F_42 ( struct V_97 V_112 )
{
struct V_150 V_151 = {
. V_152 = V_112 . V_12 ,
. V_153 = V_112 . V_13
} ;
if ( V_151 . V_153 > ( V_103 >> 1 ) ) {
V_151 . V_153 -= V_103 ;
V_151 . V_152 ++ ;
}
return V_151 ;
}
static inline long F_43 ( long * V_30 )
{
* V_30 = V_10 [ 0 ] - V_10 [ 1 ] ;
if ( * V_30 < 0 )
* V_30 = - * V_30 ;
return V_10 [ 0 ] ;
}
static inline void F_44 ( long V_154 )
{
V_10 [ 2 ] = V_10 [ 1 ] ;
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_154 ;
}
static inline void F_45 ( void )
{
if ( -- V_9 <= - V_155 ) {
V_9 = - V_155 ;
if ( V_7 > V_8 ) {
V_7 -- ;
V_9 = 0 ;
}
}
}
static inline void F_46 ( void )
{
if ( ++ V_9 >= V_155 ) {
V_9 = V_155 ;
if ( V_7 < V_156 ) {
V_7 ++ ;
V_9 = 0 ;
}
}
}
static long F_47 ( struct V_150 V_157 )
{
long V_82 , V_158 ;
T_1 V_159 ;
if ( V_157 . V_152 > ( 2 << V_7 ) ) {
V_2 |= V_18 ;
V_42 ++ ;
F_45 () ;
F_48 ( V_160
L_3 ,
V_157 . V_152 ) ;
return 0 ;
}
V_159 = F_19 ( ( ( T_1 ) ( - V_157 . V_153 ) ) << V_29 ,
V_157 . V_152 ) ;
V_82 = F_2 ( V_159 - V_14 , V_29 ) ;
V_14 = V_159 ;
if ( V_82 > V_161 || V_82 < - V_161 ) {
F_48 ( V_162
L_4 , V_82 ) ;
V_2 |= V_17 ;
V_44 ++ ;
F_45 () ;
} else {
F_46 () ;
}
V_158 = V_82 ;
if ( V_158 < 0 )
V_158 = - V_158 ;
V_36 += ( F_19 ( ( ( T_1 ) V_158 ) <<
( V_29 - V_163 ) ,
V_33 ) - V_36 ) >> V_8 ;
if ( ( V_2 & V_23 ) != 0 &&
( V_2 & V_67 ) == 0 ) {
V_50 = V_14 ;
F_10 () ;
}
return V_82 ;
}
static void F_49 ( long error )
{
long V_164 = - error ;
long V_30 ;
F_44 ( V_164 ) ;
V_164 = F_43 ( & V_30 ) ;
if ( V_30 > ( V_31 << V_165 ) ) {
F_48 ( V_162
L_5 ,
V_30 , ( V_31 << V_165 ) ) ;
V_2 |= V_16 ;
V_38 ++ ;
} else if ( V_2 & V_3 ) {
V_69 = F_19 ( ( ( T_1 ) V_164 ) << V_29 ,
V_53 ) ;
V_70 = 0 ;
}
V_31 += ( V_30 - V_31 ) >> V_8 ;
}
void F_50 ( const struct V_97 * V_166 , const struct V_97 * V_167 )
{
struct V_150 V_168 , V_157 ;
V_168 = F_42 ( * V_166 ) ;
V_2 &= ~ ( V_16 | V_17 | V_18 ) ;
V_2 |= V_4 ;
V_15 = V_169 ;
if ( F_18 ( V_11 . V_12 == 0 ) ) {
V_11 = * V_167 ;
return;
}
V_157 = F_42 ( F_51 ( * V_167 , V_11 ) ) ;
if ( ( V_157 . V_152 == 0 ) ||
( V_157 . V_153 > V_91 * V_157 . V_152 ) ||
( V_157 . V_153 < - V_91 * V_157 . V_152 ) ) {
V_2 |= V_16 ;
V_11 = * V_167 ;
F_48 ( V_160 L_6 ) ;
return;
}
if ( V_157 . V_152 >= ( 1 << V_7 ) ) {
V_40 ++ ;
V_11 = * V_167 ;
F_47 ( V_157 ) ;
}
F_49 ( V_168 . V_153 ) ;
}
static int T_5 F_52 ( char * V_170 )
{
int V_171 = F_53 ( V_170 , 0 , ( long * ) & V_49 ) ;
if ( V_171 )
return V_171 ;
V_49 <<= V_29 ;
return 1 ;
}
void T_5 F_54 ( void )
{
F_20 () ;
}
