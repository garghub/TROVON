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
if ( ! ( V_2 & V_32 ) ) {
V_1 = F_15 ( V_1 , - V_65 , V_65 ) ;
V_1 *= V_33 ;
}
V_1 = F_15 ( V_1 , - V_66 , V_66 ) ;
V_57 = ( long ) ( F_16 () - V_67 ) ;
if ( F_17 ( V_2 & V_68 ) )
V_57 = 0 ;
V_67 = F_16 () ;
V_56 = V_1 ;
V_63 = F_12 ( V_56 , V_57 ) ;
if ( F_17 ( V_57 > 1 << ( V_5 + 1 + V_6 ) ) )
V_57 = 1 << ( V_5 + 1 + V_6 ) ;
V_63 += ( V_56 * V_57 ) <<
( V_29 - 2 * ( V_5 + 2 + V_6 ) ) ;
V_63 = F_18 ( V_63 + V_50 , V_69 ) ;
V_50 = F_19 ( V_63 , - V_69 ) ;
V_70 = F_20 ( V_56 << V_29 , V_53 ) ;
}
void F_21 ( void )
{
V_71 = 0 ;
V_2 |= V_21 ;
V_72 = V_73 ;
V_74 = V_73 ;
F_10 () ;
V_54 = V_55 ;
V_70 = 0 ;
V_75 = V_76 ;
F_4 () ;
}
T_2 F_22 ( void )
{
return V_54 ;
}
T_3 F_23 ( void )
{
T_3 V_77 ;
if ( ( V_78 == V_79 ) && ( V_2 & V_80 ) )
return F_24 ( V_75 , 0 ) ;
V_77 = V_81 ;
return V_77 ;
}
int F_25 ( T_4 V_57 )
{
T_1 V_82 ;
int V_83 = 0 ;
T_5 V_84 ;
switch ( V_78 ) {
case V_85 :
if ( V_2 & V_80 ) {
V_78 = V_79 ;
F_26 ( V_57 , V_86 , & V_84 ) ;
V_75 = V_57 + V_86 - V_84 ;
} else if ( V_2 & V_87 ) {
V_78 = V_88 ;
F_26 ( V_57 + 1 , V_86 , & V_84 ) ;
V_75 = V_57 + V_86 - V_84 ;
}
break;
case V_79 :
if ( ! ( V_2 & V_80 ) ) {
V_75 = V_76 ;
V_78 = V_85 ;
} else if ( V_57 == V_75 ) {
V_83 = - 1 ;
V_78 = V_89 ;
F_27 ( V_90
L_1 ) ;
}
break;
case V_88 :
if ( ! ( V_2 & V_87 ) ) {
V_75 = V_76 ;
V_78 = V_85 ;
} else if ( V_57 == V_75 ) {
V_83 = 1 ;
V_75 = V_76 ;
V_78 = V_91 ;
F_27 ( V_90
L_2 ) ;
}
break;
case V_89 :
V_75 = V_76 ;
V_78 = V_91 ;
break;
case V_91 :
if ( ! ( V_2 & ( V_80 | V_87 ) ) )
V_78 = V_85 ;
break;
}
V_72 += V_92 / V_33 ;
if ( V_72 > V_73 ) {
V_72 = V_73 ;
V_2 |= V_21 ;
}
V_54 = V_55 ;
V_82 = F_1 ( V_70 ) ;
V_70 -= V_82 ;
V_54 += V_82 ;
F_5 () ;
if ( ! V_71 )
goto V_93;
if ( V_71 > V_94 ) {
V_71 -= V_94 ;
V_54 += V_95 ;
goto V_93;
}
if ( V_71 < - V_94 ) {
V_71 += V_94 ;
V_54 -= V_95 ;
goto V_93;
}
V_54 += ( T_1 ) ( V_71 * V_33 / V_53 )
<< V_29 ;
V_71 = 0 ;
V_93:
return V_83 ;
}
int __weak F_28 ( struct V_96 V_97 )
{
return - V_98 ;
}
int __weak F_29 ( struct V_99 V_100 )
{
struct V_96 V_97 ;
V_97 = F_30 ( V_100 ) ;
return F_28 ( V_97 ) ;
}
static void F_31 ( struct V_101 * V_102 )
{
struct V_99 V_97 ;
struct V_99 V_103 ;
int V_104 = 1 ;
if ( ! F_9 () ) {
return;
}
F_32 ( & V_97 ) ;
if ( abs ( V_97 . V_13 - ( V_105 / 2 ) ) <= V_51 * 5 ) {
struct V_99 V_106 = V_97 ;
V_104 = - V_98 ;
if ( V_107 )
V_106 . V_12 -= ( V_108 . V_109 * 60 ) ;
#ifdef F_33
V_104 = F_29 ( V_106 ) ;
#endif
#ifdef F_34
if ( V_104 == - V_98 )
V_104 = F_35 ( V_106 ) ;
#endif
}
V_103 . V_13 = ( V_105 / 2 ) - V_97 . V_13 - ( V_110 / 2 ) ;
if ( V_103 . V_13 <= 0 )
V_103 . V_13 += V_105 ;
if ( ! V_104 || V_104 == - V_98 )
V_103 . V_12 = 659 ;
else
V_103 . V_12 = 0 ;
if ( V_103 . V_13 >= V_105 ) {
V_103 . V_12 ++ ;
V_103 . V_13 -= V_105 ;
}
F_36 ( V_111 ,
& V_112 , F_37 ( & V_103 ) ) ;
}
void F_38 ( void )
{
F_36 ( V_111 , & V_112 , 0 ) ;
}
void F_38 ( void ) { }
static inline void F_39 ( struct V_24 * V_25 , struct V_99 * V_113 )
{
if ( ( V_2 & V_64 ) && ! ( V_25 -> V_20 & V_64 ) ) {
V_78 = V_85 ;
V_2 = V_21 ;
V_75 = V_76 ;
F_3 () ;
}
if ( ! ( V_2 & V_64 ) && ( V_25 -> V_20 & V_64 ) )
V_67 = F_16 () ;
V_2 &= V_114 ;
V_2 |= V_25 -> V_20 & ~ V_114 ;
}
static inline void F_40 ( struct V_24 * V_25 ,
struct V_99 * V_113 ,
T_5 * V_115 )
{
if ( V_25 -> V_116 & V_117 )
F_39 ( V_25 , V_113 ) ;
if ( V_25 -> V_116 & V_118 )
V_2 |= V_32 ;
if ( V_25 -> V_116 & V_119 )
V_2 &= ~ V_32 ;
if ( V_25 -> V_116 & V_120 ) {
V_50 = V_25 -> V_19 * V_121 ;
V_50 = F_18 ( V_50 , V_69 ) ;
V_50 = F_19 ( V_50 , - V_69 ) ;
F_6 ( V_50 ) ;
}
if ( V_25 -> V_116 & V_122 )
V_72 = V_25 -> V_123 ;
if ( V_25 -> V_116 & V_124 )
V_74 = V_25 -> V_125 ;
if ( V_25 -> V_116 & V_126 ) {
V_6 = V_25 -> V_127 ;
if ( ! ( V_2 & V_32 ) )
V_6 += 4 ;
V_6 = F_18 ( V_6 , ( long ) V_128 ) ;
V_6 = F_19 ( V_6 , 0l ) ;
}
if ( V_25 -> V_116 & V_129 && V_25 -> V_127 > 0 )
* V_115 = V_25 -> V_127 ;
if ( V_25 -> V_116 & V_130 )
F_14 ( V_25 -> V_1 ) ;
if ( V_25 -> V_116 & V_131 )
V_47 = V_25 -> V_132 ;
if ( V_25 -> V_116 & ( V_131 | V_120 | V_130 ) )
F_10 () ;
}
int F_41 ( struct V_24 * V_25 )
{
if ( V_25 -> V_116 & V_133 ) {
if ( ! ( V_25 -> V_116 & V_134 ) )
return - V_135 ;
if ( ! ( V_25 -> V_116 & V_136 ) &&
! F_42 ( V_137 ) )
return - V_138 ;
} else {
if ( V_25 -> V_116 && ! F_42 ( V_137 ) )
return - V_138 ;
if ( V_25 -> V_116 & V_131 &&
( V_25 -> V_132 < 900000 / V_48 ||
V_25 -> V_132 > 1100000 / V_48 ) )
return - V_135 ;
}
if ( V_25 -> V_116 & V_139 ) {
if ( ! F_42 ( V_137 ) )
return - V_138 ;
if ( V_25 -> V_116 & V_118 ) {
struct V_96 V_113 ;
V_113 . V_12 = V_25 -> time . V_12 ;
V_113 . V_13 = V_25 -> time . V_140 ;
if ( ! F_43 ( & V_113 ) )
return - V_135 ;
} else {
if ( ! F_44 ( & V_25 -> time ) )
return - V_135 ;
}
}
if ( ( V_25 -> V_116 & V_120 ) && ( V_141 == 64 ) ) {
if ( V_142 / V_121 > V_25 -> V_19 )
return - V_135 ;
if ( V_143 / V_121 < V_25 -> V_19 )
return - V_135 ;
}
return 0 ;
}
int F_45 ( struct V_24 * V_25 , struct V_99 * V_113 , T_5 * V_115 )
{
int V_144 ;
if ( V_25 -> V_116 & V_133 ) {
long V_145 = V_71 ;
if ( ! ( V_25 -> V_116 & V_136 ) ) {
V_71 = V_25 -> V_1 ;
F_10 () ;
}
V_25 -> V_1 = V_145 ;
} else {
if ( V_25 -> V_116 )
F_40 ( V_25 , V_113 , V_115 ) ;
V_25 -> V_1 = F_2 ( V_70 * V_53 ,
V_29 ) ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_1 /= V_33 ;
}
V_144 = V_78 ;
if ( F_7 ( V_2 ) )
V_144 = V_146 ;
V_25 -> V_19 = F_2 ( ( V_50 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_123 = V_72 ;
V_25 -> V_125 = V_74 ;
V_25 -> V_20 = V_2 ;
V_25 -> V_127 = V_6 ;
V_25 -> V_147 = 1 ;
V_25 -> V_148 = V_69 / V_121 ;
V_25 -> V_132 = V_47 ;
V_25 -> V_149 = * V_115 ;
F_8 ( V_25 ) ;
V_25 -> time . V_12 = ( V_150 ) V_113 -> V_12 ;
V_25 -> time . V_140 = V_113 -> V_13 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> time . V_140 /= V_33 ;
if ( F_17 ( V_113 -> V_12 >= V_75 ) ) {
if ( ( V_78 == V_79 ) && ( V_2 & V_80 ) ) {
V_144 = V_89 ;
V_25 -> V_149 ++ ;
V_25 -> time . V_12 -- ;
}
if ( ( V_78 == V_88 ) && ( V_2 & V_87 ) ) {
V_144 = V_91 ;
V_25 -> V_149 -- ;
V_25 -> time . V_12 ++ ;
}
if ( ( V_78 == V_89 ) &&
( V_113 -> V_12 == V_75 ) ) {
V_144 = V_91 ;
}
}
return V_144 ;
}
static inline struct V_151 F_46 ( struct V_99 V_113 )
{
struct V_151 V_152 = {
. V_153 = V_113 . V_12 ,
. V_154 = V_113 . V_13
} ;
if ( V_152 . V_154 > ( V_105 >> 1 ) ) {
V_152 . V_154 -= V_105 ;
V_152 . V_153 ++ ;
}
return V_152 ;
}
static inline long F_47 ( long * V_30 )
{
* V_30 = V_10 [ 0 ] - V_10 [ 1 ] ;
if ( * V_30 < 0 )
* V_30 = - * V_30 ;
return V_10 [ 0 ] ;
}
static inline void F_48 ( long V_155 )
{
V_10 [ 2 ] = V_10 [ 1 ] ;
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_155 ;
}
static inline void F_49 ( void )
{
if ( -- V_9 <= - V_156 ) {
V_9 = - V_156 ;
if ( V_7 > V_8 ) {
V_7 -- ;
V_9 = 0 ;
}
}
}
static inline void F_50 ( void )
{
if ( ++ V_9 >= V_156 ) {
V_9 = V_156 ;
if ( V_7 < V_157 ) {
V_7 ++ ;
V_9 = 0 ;
}
}
}
static long F_51 ( struct V_151 V_158 )
{
long V_82 , V_159 ;
T_1 V_160 ;
if ( V_158 . V_153 > ( 2 << V_7 ) ) {
V_2 |= V_18 ;
V_42 ++ ;
F_49 () ;
F_52 ( V_161
L_3 ,
V_158 . V_153 ) ;
return 0 ;
}
V_160 = F_20 ( ( ( T_1 ) ( - V_158 . V_154 ) ) << V_29 ,
V_158 . V_153 ) ;
V_82 = F_2 ( V_160 - V_14 , V_29 ) ;
V_14 = V_160 ;
if ( V_82 > V_162 || V_82 < - V_162 ) {
F_52 ( V_163
L_4 , V_82 ) ;
V_2 |= V_17 ;
V_44 ++ ;
F_49 () ;
} else {
F_50 () ;
}
V_159 = V_82 ;
if ( V_159 < 0 )
V_159 = - V_159 ;
V_36 += ( F_20 ( ( ( T_1 ) V_159 ) <<
( V_29 - V_164 ) ,
V_33 ) - V_36 ) >> V_8 ;
if ( ( V_2 & V_23 ) != 0 &&
( V_2 & V_68 ) == 0 ) {
V_50 = V_14 ;
F_10 () ;
}
return V_82 ;
}
static void F_53 ( long error )
{
long V_165 = - error ;
long V_30 ;
F_48 ( V_165 ) ;
V_165 = F_47 ( & V_30 ) ;
if ( V_30 > ( V_31 << V_166 ) ) {
F_52 ( V_163
L_5 ,
V_30 , ( V_31 << V_166 ) ) ;
V_2 |= V_16 ;
V_38 ++ ;
} else if ( V_2 & V_3 ) {
V_70 = F_20 ( ( ( T_1 ) V_165 ) << V_29 ,
V_53 ) ;
V_71 = 0 ;
}
V_31 += ( V_30 - V_31 ) >> V_8 ;
}
void F_54 ( const struct V_99 * V_167 , const struct V_99 * V_168 )
{
struct V_151 V_169 , V_158 ;
V_169 = F_46 ( * V_167 ) ;
V_2 &= ~ ( V_16 | V_17 | V_18 ) ;
V_2 |= V_4 ;
V_15 = V_170 ;
if ( F_17 ( V_11 . V_12 == 0 ) ) {
V_11 = * V_168 ;
return;
}
V_158 = F_46 ( F_55 ( * V_168 , V_11 ) ) ;
if ( ( V_158 . V_153 == 0 ) ||
( V_158 . V_154 > V_92 * V_158 . V_153 ) ||
( V_158 . V_154 < - V_92 * V_158 . V_153 ) ) {
V_2 |= V_16 ;
V_11 = * V_168 ;
F_52 ( V_161 L_6 ) ;
return;
}
if ( V_158 . V_153 >= ( 1 << V_7 ) ) {
V_40 ++ ;
V_11 = * V_168 ;
F_51 ( V_158 ) ;
}
F_53 ( V_169 . V_154 ) ;
}
static int T_6 F_56 ( char * V_171 )
{
int V_172 = F_57 ( V_171 , 0 , ( long * ) & V_49 ) ;
if ( V_172 )
return V_172 ;
V_49 <<= V_29 ;
return 1 ;
}
void T_6 F_58 ( void )
{
F_21 () ;
}
