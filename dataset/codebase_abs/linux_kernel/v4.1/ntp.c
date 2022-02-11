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
F_4 () ;
}
T_2 F_21 ( void )
{
return V_54 ;
}
int F_22 ( unsigned long V_57 )
{
T_1 V_74 ;
int V_75 = 0 ;
switch ( V_76 ) {
case V_77 :
if ( V_2 & V_78 )
V_76 = V_79 ;
else if ( V_2 & V_80 )
V_76 = V_81 ;
break;
case V_79 :
if ( ! ( V_2 & V_78 ) )
V_76 = V_77 ;
else if ( V_57 % 86400 == 0 ) {
V_75 = - 1 ;
V_76 = V_82 ;
F_23 ( V_83
L_1 ) ;
}
break;
case V_81 :
if ( ! ( V_2 & V_80 ) )
V_76 = V_77 ;
else if ( ( V_57 + 1 ) % 86400 == 0 ) {
V_75 = 1 ;
V_76 = V_84 ;
F_23 ( V_83
L_2 ) ;
}
break;
case V_82 :
V_76 = V_84 ;
break;
case V_84 :
if ( ! ( V_2 & ( V_78 | V_80 ) ) )
V_76 = V_77 ;
break;
}
V_71 += V_85 / V_33 ;
if ( V_71 > V_72 ) {
V_71 = V_72 ;
V_2 |= V_21 ;
}
V_54 = V_55 ;
V_74 = F_1 ( V_69 ) ;
V_69 -= V_74 ;
V_54 += V_74 ;
F_5 () ;
if ( ! V_70 )
goto V_86;
if ( V_70 > V_87 ) {
V_70 -= V_87 ;
V_54 += V_88 ;
goto V_86;
}
if ( V_70 < - V_87 ) {
V_70 += V_87 ;
V_54 -= V_88 ;
goto V_86;
}
V_54 += ( T_1 ) ( V_70 * V_33 / V_53 )
<< V_29 ;
V_70 = 0 ;
V_86:
return V_75 ;
}
int __weak F_24 ( struct V_89 V_90 )
{
struct V_91 V_92 ;
V_92 = F_25 ( V_90 ) ;
return F_26 ( V_92 ) ;
}
static void F_27 ( struct V_93 * V_94 )
{
struct V_89 V_92 ;
struct V_91 V_95 ;
int V_96 = 1 ;
if ( ! F_9 () ) {
return;
}
F_28 ( & V_92 ) ;
if ( abs ( V_92 . V_13 - ( V_97 / 2 ) ) <= V_51 * 5 ) {
struct V_89 V_98 = V_92 ;
V_96 = - V_99 ;
if ( V_100 )
V_98 . V_12 -= ( V_101 . V_102 * 60 ) ;
#ifdef F_29
V_96 = F_24 ( V_98 ) ;
#endif
#ifdef F_30
if ( V_96 == - V_99 )
V_96 = F_31 ( V_98 ) ;
#endif
}
V_95 . V_13 = ( V_97 / 2 ) - V_92 . V_13 - ( V_103 / 2 ) ;
if ( V_95 . V_13 <= 0 )
V_95 . V_13 += V_97 ;
if ( ! V_96 || V_96 == - V_99 )
V_95 . V_12 = 659 ;
else
V_95 . V_12 = 0 ;
if ( V_95 . V_13 >= V_97 ) {
V_95 . V_12 ++ ;
V_95 . V_13 -= V_97 ;
}
F_32 ( V_104 ,
& V_105 , F_33 ( & V_95 ) ) ;
}
void F_34 ( void )
{
F_32 ( V_104 , & V_105 , 0 ) ;
}
void F_34 ( void ) { }
static inline void F_35 ( struct V_24 * V_25 , struct V_89 * V_106 )
{
if ( ( V_2 & V_64 ) && ! ( V_25 -> V_20 & V_64 ) ) {
V_76 = V_77 ;
V_2 = V_21 ;
F_3 () ;
}
if ( ! ( V_2 & V_64 ) && ( V_25 -> V_20 & V_64 ) )
V_66 = F_17 () ;
V_2 &= V_107 ;
V_2 |= V_25 -> V_20 & ~ V_107 ;
}
static inline void F_36 ( struct V_24 * V_25 ,
struct V_89 * V_106 ,
T_3 * V_108 )
{
if ( V_25 -> V_109 & V_110 )
F_35 ( V_25 , V_106 ) ;
if ( V_25 -> V_109 & V_111 )
V_2 |= V_32 ;
if ( V_25 -> V_109 & V_112 )
V_2 &= ~ V_32 ;
if ( V_25 -> V_109 & V_113 ) {
V_50 = V_25 -> V_19 * V_114 ;
V_50 = F_15 ( V_50 , V_68 ) ;
V_50 = F_16 ( V_50 , - V_68 ) ;
F_6 ( V_50 ) ;
}
if ( V_25 -> V_109 & V_115 )
V_71 = V_25 -> V_116 ;
if ( V_25 -> V_109 & V_117 )
V_73 = V_25 -> V_118 ;
if ( V_25 -> V_109 & V_119 ) {
V_6 = V_25 -> V_120 ;
if ( ! ( V_2 & V_32 ) )
V_6 += 4 ;
V_6 = F_15 ( V_6 , ( long ) V_121 ) ;
V_6 = F_16 ( V_6 , 0l ) ;
}
if ( V_25 -> V_109 & V_122 && V_25 -> V_120 > 0 )
* V_108 = V_25 -> V_120 ;
if ( V_25 -> V_109 & V_123 )
F_14 ( V_25 -> V_1 ) ;
if ( V_25 -> V_109 & V_124 )
V_47 = V_25 -> V_125 ;
if ( V_25 -> V_109 & ( V_124 | V_113 | V_123 ) )
F_10 () ;
}
int F_37 ( struct V_24 * V_25 )
{
if ( V_25 -> V_109 & V_126 ) {
if ( ! ( V_25 -> V_109 & V_127 ) )
return - V_128 ;
if ( ! ( V_25 -> V_109 & V_129 ) &&
! F_38 ( V_130 ) )
return - V_131 ;
} else {
if ( V_25 -> V_109 && ! F_38 ( V_130 ) )
return - V_131 ;
if ( V_25 -> V_109 & V_124 &&
( V_25 -> V_125 < 900000 / V_48 ||
V_25 -> V_125 > 1100000 / V_48 ) )
return - V_128 ;
}
if ( ( V_25 -> V_109 & V_132 ) && ( ! F_38 ( V_130 ) ) )
return - V_131 ;
if ( ( V_25 -> V_109 & V_113 ) && ( V_133 == 64 ) ) {
if ( V_134 / V_114 > V_25 -> V_19 )
return - V_128 ;
if ( V_135 / V_114 < V_25 -> V_19 )
return - V_128 ;
}
return 0 ;
}
int F_39 ( struct V_24 * V_25 , struct V_89 * V_106 , T_3 * V_108 )
{
int V_136 ;
if ( V_25 -> V_109 & V_126 ) {
long V_137 = V_70 ;
if ( ! ( V_25 -> V_109 & V_129 ) ) {
V_70 = V_25 -> V_1 ;
F_10 () ;
}
V_25 -> V_1 = V_137 ;
} else {
if ( V_25 -> V_109 )
F_36 ( V_25 , V_106 , V_108 ) ;
V_25 -> V_1 = F_2 ( V_69 * V_53 ,
V_29 ) ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_1 /= V_33 ;
}
V_136 = V_76 ;
if ( F_7 ( V_2 ) )
V_136 = V_138 ;
V_25 -> V_19 = F_2 ( ( V_50 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_116 = V_71 ;
V_25 -> V_118 = V_73 ;
V_25 -> V_20 = V_2 ;
V_25 -> V_120 = V_6 ;
V_25 -> V_139 = 1 ;
V_25 -> V_140 = V_68 / V_114 ;
V_25 -> V_125 = V_47 ;
V_25 -> V_141 = * V_108 ;
F_8 ( V_25 ) ;
V_25 -> time . V_12 = ( V_142 ) V_106 -> V_12 ;
V_25 -> time . V_143 = V_106 -> V_13 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> time . V_143 /= V_33 ;
return V_136 ;
}
static inline struct V_144 F_40 ( struct V_91 V_106 )
{
struct V_144 V_145 = {
. V_146 = V_106 . V_12 ,
. V_147 = V_106 . V_13
} ;
if ( V_145 . V_147 > ( V_97 >> 1 ) ) {
V_145 . V_147 -= V_97 ;
V_145 . V_146 ++ ;
}
return V_145 ;
}
static inline long F_41 ( long * V_30 )
{
* V_30 = V_10 [ 0 ] - V_10 [ 1 ] ;
if ( * V_30 < 0 )
* V_30 = - * V_30 ;
return V_10 [ 0 ] ;
}
static inline void F_42 ( long V_148 )
{
V_10 [ 2 ] = V_10 [ 1 ] ;
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_148 ;
}
static inline void F_43 ( void )
{
if ( -- V_9 <= - V_149 ) {
V_9 = - V_149 ;
if ( V_7 > V_8 ) {
V_7 -- ;
V_9 = 0 ;
}
}
}
static inline void F_44 ( void )
{
if ( ++ V_9 >= V_149 ) {
V_9 = V_149 ;
if ( V_7 < V_150 ) {
V_7 ++ ;
V_9 = 0 ;
}
}
}
static long F_45 ( struct V_144 V_151 )
{
long V_74 , V_152 ;
T_1 V_153 ;
if ( V_151 . V_146 > ( 2 << V_7 ) ) {
V_2 |= V_18 ;
V_42 ++ ;
F_43 () ;
F_46 ( V_154
L_3 ,
V_151 . V_146 ) ;
return 0 ;
}
V_153 = F_19 ( ( ( T_1 ) ( - V_151 . V_147 ) ) << V_29 ,
V_151 . V_146 ) ;
V_74 = F_2 ( V_153 - V_14 , V_29 ) ;
V_14 = V_153 ;
if ( V_74 > V_155 || V_74 < - V_155 ) {
F_46 ( V_156
L_4 , V_74 ) ;
V_2 |= V_17 ;
V_44 ++ ;
F_43 () ;
} else {
F_44 () ;
}
V_152 = V_74 ;
if ( V_152 < 0 )
V_152 = - V_152 ;
V_36 += ( F_19 ( ( ( T_1 ) V_152 ) <<
( V_29 - V_157 ) ,
V_33 ) - V_36 ) >> V_8 ;
if ( ( V_2 & V_23 ) != 0 &&
( V_2 & V_67 ) == 0 ) {
V_50 = V_14 ;
F_10 () ;
}
return V_74 ;
}
static void F_47 ( long error )
{
long V_158 = - error ;
long V_30 ;
F_42 ( V_158 ) ;
V_158 = F_41 ( & V_30 ) ;
if ( V_30 > ( V_31 << V_159 ) ) {
F_46 ( V_156
L_5 ,
V_30 , ( V_31 << V_159 ) ) ;
V_2 |= V_16 ;
V_38 ++ ;
} else if ( V_2 & V_3 ) {
V_69 = F_19 ( ( ( T_1 ) V_158 ) << V_29 ,
V_53 ) ;
V_70 = 0 ;
}
V_31 += ( V_30 - V_31 ) >> V_8 ;
}
void F_48 ( const struct V_91 * V_160 , const struct V_91 * V_161 )
{
struct V_144 V_162 , V_151 ;
V_162 = F_40 ( * V_160 ) ;
V_2 &= ~ ( V_16 | V_17 | V_18 ) ;
V_2 |= V_4 ;
V_15 = V_163 ;
if ( F_18 ( V_11 . V_12 == 0 ) ) {
V_11 = * V_161 ;
return;
}
V_151 = F_40 ( F_49 ( * V_161 , V_11 ) ) ;
if ( ( V_151 . V_146 == 0 ) ||
( V_151 . V_147 > V_85 * V_151 . V_146 ) ||
( V_151 . V_147 < - V_85 * V_151 . V_146 ) ) {
V_2 |= V_16 ;
V_11 = * V_161 ;
F_46 ( V_154 L_6 ) ;
return;
}
if ( V_151 . V_146 >= ( 1 << V_7 ) ) {
V_40 ++ ;
V_11 = * V_161 ;
F_45 ( V_151 ) ;
}
F_47 ( V_162 . V_147 ) ;
}
static int T_4 F_50 ( char * V_164 )
{
int V_165 = F_51 ( V_164 , 0 , ( long * ) & V_49 ) ;
if ( V_165 )
return V_165 ;
V_49 <<= V_29 ;
return 1 ;
}
void T_4 F_52 ( void )
{
F_20 () ;
}
