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
V_77 . V_81 = V_82 ;
return V_77 ;
}
int F_25 ( T_4 V_57 )
{
T_1 V_83 ;
int V_84 = 0 ;
T_5 V_85 ;
switch ( V_78 ) {
case V_86 :
if ( V_2 & V_80 ) {
V_78 = V_79 ;
F_26 ( V_57 , V_87 , & V_85 ) ;
V_75 = V_57 + V_87 - V_85 ;
} else if ( V_2 & V_88 ) {
V_78 = V_89 ;
F_26 ( V_57 + 1 , V_87 , & V_85 ) ;
V_75 = V_57 + V_87 - V_85 ;
}
break;
case V_79 :
if ( ! ( V_2 & V_80 ) ) {
V_75 = V_76 ;
V_78 = V_86 ;
} else if ( V_57 == V_75 ) {
V_84 = - 1 ;
V_78 = V_90 ;
F_27 ( V_91
L_1 ) ;
}
break;
case V_89 :
if ( ! ( V_2 & V_88 ) ) {
V_75 = V_76 ;
V_78 = V_86 ;
} else if ( V_57 == V_75 ) {
V_84 = 1 ;
V_75 = V_76 ;
V_78 = V_92 ;
F_27 ( V_91
L_2 ) ;
}
break;
case V_90 :
V_75 = V_76 ;
V_78 = V_92 ;
break;
case V_92 :
if ( ! ( V_2 & ( V_80 | V_88 ) ) )
V_78 = V_86 ;
break;
}
V_72 += V_93 / V_33 ;
if ( V_72 > V_73 ) {
V_72 = V_73 ;
V_2 |= V_21 ;
}
V_54 = V_55 ;
V_83 = F_1 ( V_70 ) ;
V_70 -= V_83 ;
V_54 += V_83 ;
F_5 () ;
if ( ! V_71 )
goto V_94;
if ( V_71 > V_95 ) {
V_71 -= V_95 ;
V_54 += V_96 ;
goto V_94;
}
if ( V_71 < - V_95 ) {
V_71 += V_95 ;
V_54 -= V_96 ;
goto V_94;
}
V_54 += ( T_1 ) ( V_71 * V_33 / V_53 )
<< V_29 ;
V_71 = 0 ;
V_94:
return V_84 ;
}
int __weak F_28 ( struct V_97 V_98 )
{
return - V_99 ;
}
int __weak F_29 ( struct V_100 V_101 )
{
struct V_97 V_98 ;
V_98 = F_30 ( V_101 ) ;
return F_28 ( V_98 ) ;
}
static void F_31 ( struct V_102 * V_103 )
{
struct V_100 V_98 ;
struct V_100 V_104 ;
int V_105 = 1 ;
if ( ! F_9 () ) {
return;
}
F_32 ( & V_98 ) ;
if ( abs ( V_98 . V_13 - ( V_106 / 2 ) ) <= V_51 * 5 ) {
struct V_100 V_107 = V_98 ;
V_105 = - V_99 ;
if ( V_108 )
V_107 . V_12 -= ( V_109 . V_110 * 60 ) ;
#ifdef F_33
V_105 = F_29 ( V_107 ) ;
#endif
#ifdef F_34
if ( V_105 == - V_99 )
V_105 = F_35 ( V_107 ) ;
#endif
}
V_104 . V_13 = ( V_106 / 2 ) - V_98 . V_13 - ( V_111 / 2 ) ;
if ( V_104 . V_13 <= 0 )
V_104 . V_13 += V_106 ;
if ( ! V_105 || V_105 == - V_99 )
V_104 . V_12 = 659 ;
else
V_104 . V_12 = 0 ;
if ( V_104 . V_13 >= V_106 ) {
V_104 . V_12 ++ ;
V_104 . V_13 -= V_106 ;
}
F_36 ( V_112 ,
& V_113 , F_37 ( & V_104 ) ) ;
}
void F_38 ( void )
{
F_36 ( V_112 , & V_113 , 0 ) ;
}
void F_38 ( void ) { }
static inline void F_39 ( struct V_24 * V_25 , struct V_100 * V_114 )
{
if ( ( V_2 & V_64 ) && ! ( V_25 -> V_20 & V_64 ) ) {
V_78 = V_86 ;
V_2 = V_21 ;
V_75 = V_76 ;
F_3 () ;
}
if ( ! ( V_2 & V_64 ) && ( V_25 -> V_20 & V_64 ) )
V_67 = F_16 () ;
V_2 &= V_115 ;
V_2 |= V_25 -> V_20 & ~ V_115 ;
}
static inline void F_40 ( struct V_24 * V_25 ,
struct V_100 * V_114 ,
T_5 * V_116 )
{
if ( V_25 -> V_117 & V_118 )
F_39 ( V_25 , V_114 ) ;
if ( V_25 -> V_117 & V_119 )
V_2 |= V_32 ;
if ( V_25 -> V_117 & V_120 )
V_2 &= ~ V_32 ;
if ( V_25 -> V_117 & V_121 ) {
V_50 = V_25 -> V_19 * V_122 ;
V_50 = F_18 ( V_50 , V_69 ) ;
V_50 = F_19 ( V_50 , - V_69 ) ;
F_6 ( V_50 ) ;
}
if ( V_25 -> V_117 & V_123 )
V_72 = V_25 -> V_124 ;
if ( V_25 -> V_117 & V_125 )
V_74 = V_25 -> V_126 ;
if ( V_25 -> V_117 & V_127 ) {
V_6 = V_25 -> V_128 ;
if ( ! ( V_2 & V_32 ) )
V_6 += 4 ;
V_6 = F_18 ( V_6 , ( long ) V_129 ) ;
V_6 = F_19 ( V_6 , 0l ) ;
}
if ( V_25 -> V_117 & V_130 && V_25 -> V_128 > 0 )
* V_116 = V_25 -> V_128 ;
if ( V_25 -> V_117 & V_131 )
F_14 ( V_25 -> V_1 ) ;
if ( V_25 -> V_117 & V_132 )
V_47 = V_25 -> V_133 ;
if ( V_25 -> V_117 & ( V_132 | V_121 | V_131 ) )
F_10 () ;
}
int F_41 ( struct V_24 * V_25 )
{
if ( V_25 -> V_117 & V_134 ) {
if ( ! ( V_25 -> V_117 & V_135 ) )
return - V_136 ;
if ( ! ( V_25 -> V_117 & V_137 ) &&
! F_42 ( V_138 ) )
return - V_139 ;
} else {
if ( V_25 -> V_117 && ! F_42 ( V_138 ) )
return - V_139 ;
if ( V_25 -> V_117 & V_132 &&
( V_25 -> V_133 < 900000 / V_48 ||
V_25 -> V_133 > 1100000 / V_48 ) )
return - V_136 ;
}
if ( V_25 -> V_117 & V_140 ) {
if ( ! F_42 ( V_138 ) )
return - V_139 ;
if ( V_25 -> V_117 & V_119 ) {
struct V_97 V_114 ;
V_114 . V_12 = V_25 -> time . V_12 ;
V_114 . V_13 = V_25 -> time . V_141 ;
if ( ! F_43 ( & V_114 ) )
return - V_136 ;
} else {
if ( ! F_44 ( & V_25 -> time ) )
return - V_136 ;
}
}
if ( ( V_25 -> V_117 & V_121 ) && ( V_142 == 64 ) ) {
if ( V_143 / V_122 > V_25 -> V_19 )
return - V_136 ;
if ( V_144 / V_122 < V_25 -> V_19 )
return - V_136 ;
}
return 0 ;
}
int F_45 ( struct V_24 * V_25 , struct V_100 * V_114 , T_5 * V_116 )
{
int V_145 ;
if ( V_25 -> V_117 & V_134 ) {
long V_146 = V_71 ;
if ( ! ( V_25 -> V_117 & V_137 ) ) {
V_71 = V_25 -> V_1 ;
F_10 () ;
}
V_25 -> V_1 = V_146 ;
} else {
if ( V_25 -> V_117 )
F_40 ( V_25 , V_114 , V_116 ) ;
V_25 -> V_1 = F_2 ( V_70 * V_53 ,
V_29 ) ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_1 /= V_33 ;
}
V_145 = V_78 ;
if ( F_7 ( V_2 ) )
V_145 = V_147 ;
V_25 -> V_19 = F_2 ( ( V_50 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_124 = V_72 ;
V_25 -> V_126 = V_74 ;
V_25 -> V_20 = V_2 ;
V_25 -> V_128 = V_6 ;
V_25 -> V_148 = 1 ;
V_25 -> V_149 = V_69 / V_122 ;
V_25 -> V_133 = V_47 ;
V_25 -> V_150 = * V_116 ;
F_8 ( V_25 ) ;
V_25 -> time . V_12 = ( V_151 ) V_114 -> V_12 ;
V_25 -> time . V_141 = V_114 -> V_13 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> time . V_141 /= V_33 ;
if ( F_17 ( V_114 -> V_12 >= V_75 ) ) {
if ( ( V_78 == V_79 ) && ( V_2 & V_80 ) ) {
V_145 = V_90 ;
V_25 -> V_150 ++ ;
V_25 -> time . V_12 -- ;
}
if ( ( V_78 == V_89 ) && ( V_2 & V_88 ) ) {
V_145 = V_92 ;
V_25 -> V_150 -- ;
V_25 -> time . V_12 ++ ;
}
if ( ( V_78 == V_90 ) &&
( V_114 -> V_12 == V_75 ) ) {
V_145 = V_92 ;
}
}
return V_145 ;
}
static inline struct V_152 F_46 ( struct V_100 V_114 )
{
struct V_152 V_153 = {
. V_154 = V_114 . V_12 ,
. V_155 = V_114 . V_13
} ;
if ( V_153 . V_155 > ( V_106 >> 1 ) ) {
V_153 . V_155 -= V_106 ;
V_153 . V_154 ++ ;
}
return V_153 ;
}
static inline long F_47 ( long * V_30 )
{
* V_30 = V_10 [ 0 ] - V_10 [ 1 ] ;
if ( * V_30 < 0 )
* V_30 = - * V_30 ;
return V_10 [ 0 ] ;
}
static inline void F_48 ( long V_156 )
{
V_10 [ 2 ] = V_10 [ 1 ] ;
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_156 ;
}
static inline void F_49 ( void )
{
if ( -- V_9 <= - V_157 ) {
V_9 = - V_157 ;
if ( V_7 > V_8 ) {
V_7 -- ;
V_9 = 0 ;
}
}
}
static inline void F_50 ( void )
{
if ( ++ V_9 >= V_157 ) {
V_9 = V_157 ;
if ( V_7 < V_158 ) {
V_7 ++ ;
V_9 = 0 ;
}
}
}
static long F_51 ( struct V_152 V_159 )
{
long V_83 , V_160 ;
T_1 V_161 ;
if ( V_159 . V_154 > ( 2 << V_7 ) ) {
V_2 |= V_18 ;
V_42 ++ ;
F_49 () ;
F_52 ( V_162
L_3 ,
V_159 . V_154 ) ;
return 0 ;
}
V_161 = F_20 ( ( ( T_1 ) ( - V_159 . V_155 ) ) << V_29 ,
V_159 . V_154 ) ;
V_83 = F_2 ( V_161 - V_14 , V_29 ) ;
V_14 = V_161 ;
if ( V_83 > V_163 || V_83 < - V_163 ) {
F_52 ( V_164
L_4 , V_83 ) ;
V_2 |= V_17 ;
V_44 ++ ;
F_49 () ;
} else {
F_50 () ;
}
V_160 = V_83 ;
if ( V_160 < 0 )
V_160 = - V_160 ;
V_36 += ( F_20 ( ( ( T_1 ) V_160 ) <<
( V_29 - V_165 ) ,
V_33 ) - V_36 ) >> V_8 ;
if ( ( V_2 & V_23 ) != 0 &&
( V_2 & V_68 ) == 0 ) {
V_50 = V_14 ;
F_10 () ;
}
return V_83 ;
}
static void F_53 ( long error )
{
long V_166 = - error ;
long V_30 ;
F_48 ( V_166 ) ;
V_166 = F_47 ( & V_30 ) ;
if ( V_30 > ( V_31 << V_167 ) ) {
F_52 ( V_164
L_5 ,
V_30 , ( V_31 << V_167 ) ) ;
V_2 |= V_16 ;
V_38 ++ ;
} else if ( V_2 & V_3 ) {
V_70 = F_20 ( ( ( T_1 ) V_166 ) << V_29 ,
V_53 ) ;
V_71 = 0 ;
}
V_31 += ( V_30 - V_31 ) >> V_8 ;
}
void F_54 ( const struct V_100 * V_168 , const struct V_100 * V_169 )
{
struct V_152 V_170 , V_159 ;
V_170 = F_46 ( * V_168 ) ;
V_2 &= ~ ( V_16 | V_17 | V_18 ) ;
V_2 |= V_4 ;
V_15 = V_171 ;
if ( F_17 ( V_11 . V_12 == 0 ) ) {
V_11 = * V_169 ;
return;
}
V_159 = F_46 ( F_55 ( * V_169 , V_11 ) ) ;
if ( ( V_159 . V_154 == 0 ) ||
( V_159 . V_155 > V_93 * V_159 . V_154 ) ||
( V_159 . V_155 < - V_93 * V_159 . V_154 ) ) {
V_2 |= V_16 ;
V_11 = * V_169 ;
F_52 ( V_162 L_6 ) ;
return;
}
if ( V_159 . V_154 >= ( 1 << V_7 ) ) {
V_40 ++ ;
V_11 = * V_169 ;
F_51 ( V_159 ) ;
}
F_53 ( V_170 . V_155 ) ;
}
static int T_6 F_56 ( char * V_172 )
{
int V_173 = F_57 ( V_172 , 0 , ( long * ) & V_49 ) ;
if ( V_173 )
return V_173 ;
V_49 <<= V_29 ;
return 1 ;
}
void T_6 F_58 ( void )
{
F_21 () ;
}
