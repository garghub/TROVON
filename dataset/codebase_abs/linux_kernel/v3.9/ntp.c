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
return ( V_2 & ( V_21 | V_22 ) )
|| ( ( V_2 & ( V_23 | V_3 ) )
&& ! ( V_2 & V_4 ) )
|| ( ( V_2 & ( V_3 | V_16 ) )
== ( V_3 | V_16 ) )
|| ( ( V_2 & V_23 )
&& ( V_2 & ( V_17 | V_18 ) ) ) ;
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
unsigned long V_70 ;
F_21 ( & V_71 , V_70 ) ;
V_72 = 0 ;
V_2 |= V_21 ;
V_73 = V_74 ;
V_75 = V_74 ;
F_10 () ;
V_54 = V_55 ;
V_69 = 0 ;
F_4 () ;
F_22 ( & V_71 , V_70 ) ;
}
T_2 F_23 ( void )
{
unsigned long V_70 ;
T_1 V_76 ;
F_21 ( & V_71 , V_70 ) ;
V_76 = V_54 ;
F_22 ( & V_71 , V_70 ) ;
return V_76 ;
}
int F_24 ( unsigned long V_57 )
{
T_1 V_77 ;
int V_78 = 0 ;
unsigned long V_70 ;
F_21 ( & V_71 , V_70 ) ;
switch ( V_79 ) {
case V_80 :
if ( V_2 & V_81 )
V_79 = V_82 ;
else if ( V_2 & V_83 )
V_79 = V_84 ;
break;
case V_82 :
if ( ! ( V_2 & V_81 ) )
V_79 = V_80 ;
else if ( V_57 % 86400 == 0 ) {
V_78 = - 1 ;
V_79 = V_85 ;
V_86 ++ ;
F_25 ( V_87
L_1 ) ;
}
break;
case V_84 :
if ( ! ( V_2 & V_83 ) )
V_79 = V_80 ;
else if ( ( V_57 + 1 ) % 86400 == 0 ) {
V_78 = 1 ;
V_86 -- ;
V_79 = V_88 ;
F_25 ( V_87
L_2 ) ;
}
break;
case V_85 :
V_79 = V_88 ;
break;
case V_88 :
if ( ! ( V_2 & ( V_81 | V_83 ) ) )
V_79 = V_80 ;
break;
}
V_73 += V_89 / V_33 ;
if ( V_73 > V_74 ) {
V_73 = V_74 ;
V_2 |= V_21 ;
}
V_54 = V_55 ;
V_77 = F_1 ( V_69 ) ;
V_69 -= V_77 ;
V_54 += V_77 ;
F_5 () ;
if ( ! V_72 )
goto V_90;
if ( V_72 > V_91 ) {
V_72 -= V_91 ;
V_54 += V_92 ;
goto V_90;
}
if ( V_72 < - V_91 ) {
V_72 += V_91 ;
V_54 -= V_92 ;
goto V_90;
}
V_54 += ( T_1 ) ( V_72 * V_33 / V_53 )
<< V_29 ;
V_72 = 0 ;
V_90:
F_22 ( & V_71 , V_70 ) ;
return V_78 ;
}
static void F_26 ( struct V_93 * V_94 )
{
struct V_95 V_96 , V_97 ;
int V_98 = 1 ;
if ( ! F_9 () ) {
return;
}
F_27 ( & V_96 ) ;
if ( abs ( V_96 . V_13 - ( V_99 / 2 ) ) <= V_51 / 2 ) {
struct V_95 V_100 = V_96 ;
V_98 = - V_101 ;
if ( V_102 )
V_100 . V_12 -= ( V_103 . V_104 * 60 ) ;
#ifdef F_28
V_98 = F_29 ( V_100 ) ;
#endif
#ifdef F_30
if ( V_98 == - V_101 )
V_98 = F_31 ( V_100 ) ;
#endif
}
V_97 . V_13 = ( V_99 / 2 ) - V_96 . V_13 - ( V_105 / 2 ) ;
if ( V_97 . V_13 <= 0 )
V_97 . V_13 += V_99 ;
if ( ! V_98 || V_98 == - V_101 )
V_97 . V_12 = 659 ;
else
V_97 . V_12 = 0 ;
if ( V_97 . V_13 >= V_99 ) {
V_97 . V_12 ++ ;
V_97 . V_13 -= V_99 ;
}
F_32 ( & V_106 , F_33 ( & V_97 ) ) ;
}
static void F_34 ( void )
{
F_32 ( & V_106 , 0 ) ;
}
static inline void F_34 ( void ) { }
static inline void F_35 ( struct V_24 * V_25 , struct V_95 * V_107 )
{
if ( ( V_2 & V_64 ) && ! ( V_25 -> V_20 & V_64 ) ) {
V_79 = V_80 ;
V_2 = V_21 ;
F_3 () ;
}
if ( ! ( V_2 & V_64 ) && ( V_25 -> V_20 & V_64 ) )
V_66 = F_17 () ;
V_2 &= V_108 ;
V_2 |= V_25 -> V_20 & ~ V_108 ;
}
static inline void F_36 ( struct V_24 * V_25 , struct V_95 * V_107 )
{
if ( V_25 -> V_109 & V_110 )
F_35 ( V_25 , V_107 ) ;
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
V_73 = V_25 -> V_116 ;
if ( V_25 -> V_109 & V_117 )
V_75 = V_25 -> V_118 ;
if ( V_25 -> V_109 & V_119 ) {
V_6 = V_25 -> V_120 ;
if ( ! ( V_2 & V_32 ) )
V_6 += 4 ;
V_6 = F_15 ( V_6 , ( long ) V_121 ) ;
V_6 = F_16 ( V_6 , 0l ) ;
}
if ( V_25 -> V_109 & V_122 && V_25 -> V_120 > 0 )
V_86 = V_25 -> V_120 ;
if ( V_25 -> V_109 & V_123 )
F_14 ( V_25 -> V_1 ) ;
if ( V_25 -> V_109 & V_124 )
V_47 = V_25 -> V_125 ;
if ( V_25 -> V_109 & ( V_124 | V_113 | V_123 ) )
F_10 () ;
}
int F_37 ( struct V_24 * V_25 )
{
struct V_95 V_107 ;
int V_126 ;
if ( V_25 -> V_109 & V_127 ) {
if ( ! ( V_25 -> V_109 & V_128 ) )
return - V_129 ;
if ( ! ( V_25 -> V_109 & V_130 ) &&
! F_38 ( V_131 ) )
return - V_132 ;
} else {
if ( V_25 -> V_109 && ! F_38 ( V_131 ) )
return - V_132 ;
if ( V_25 -> V_109 & V_124 &&
( V_25 -> V_125 < 900000 / V_48 ||
V_25 -> V_125 > 1100000 / V_48 ) )
return - V_129 ;
}
if ( V_25 -> V_109 & V_133 ) {
struct V_95 V_77 ;
V_77 . V_12 = V_25 -> time . V_12 ;
V_77 . V_13 = V_25 -> time . V_134 ;
if ( ! F_38 ( V_131 ) )
return - V_132 ;
if ( ! ( V_25 -> V_109 & V_111 ) )
V_77 . V_13 *= 1000 ;
V_126 = F_39 ( & V_77 ) ;
if ( V_126 )
return V_126 ;
}
F_27 ( & V_107 ) ;
F_40 ( & V_71 ) ;
if ( V_25 -> V_109 & V_127 ) {
long V_135 = V_72 ;
if ( ! ( V_25 -> V_109 & V_130 ) ) {
V_72 = V_25 -> V_1 ;
F_10 () ;
}
V_25 -> V_1 = V_135 ;
} else {
if ( V_25 -> V_109 )
F_36 ( V_25 , & V_107 ) ;
V_25 -> V_1 = F_2 ( V_69 * V_53 ,
V_29 ) ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_1 /= V_33 ;
}
V_126 = V_79 ;
if ( F_7 ( V_2 ) )
V_126 = V_136 ;
V_25 -> V_19 = F_2 ( ( V_50 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_116 = V_73 ;
V_25 -> V_118 = V_75 ;
V_25 -> V_20 = V_2 ;
V_25 -> V_120 = V_6 ;
V_25 -> V_137 = 1 ;
V_25 -> V_138 = V_68 / V_114 ;
V_25 -> V_125 = V_47 ;
V_25 -> V_139 = V_86 ;
F_8 ( V_25 ) ;
F_41 ( & V_71 ) ;
V_25 -> time . V_12 = V_107 . V_12 ;
V_25 -> time . V_134 = V_107 . V_13 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> time . V_134 /= V_33 ;
F_34 () ;
return V_126 ;
}
static inline struct V_140 F_42 ( struct V_95 V_107 )
{
struct V_140 V_141 = {
. V_142 = V_107 . V_12 ,
. V_143 = V_107 . V_13
} ;
if ( V_141 . V_143 > ( V_99 >> 1 ) ) {
V_141 . V_143 -= V_99 ;
V_141 . V_142 ++ ;
}
return V_141 ;
}
static inline long F_43 ( long * V_30 )
{
* V_30 = V_10 [ 0 ] - V_10 [ 1 ] ;
if ( * V_30 < 0 )
* V_30 = - * V_30 ;
return V_10 [ 0 ] ;
}
static inline void F_44 ( long V_144 )
{
V_10 [ 2 ] = V_10 [ 1 ] ;
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_144 ;
}
static inline void F_45 ( void )
{
if ( -- V_9 <= - V_145 ) {
V_9 = - V_145 ;
if ( V_7 > V_8 ) {
V_7 -- ;
V_9 = 0 ;
}
}
}
static inline void F_46 ( void )
{
if ( ++ V_9 >= V_145 ) {
V_9 = V_145 ;
if ( V_7 < V_146 ) {
V_7 ++ ;
V_9 = 0 ;
}
}
}
static long F_47 ( struct V_140 V_147 )
{
long V_77 , V_148 ;
T_1 V_149 ;
if ( V_147 . V_142 > ( 2 << V_7 ) ) {
V_2 |= V_18 ;
V_42 ++ ;
F_45 () ;
F_48 ( L_3 ,
V_147 . V_142 ) ;
return 0 ;
}
V_149 = F_19 ( ( ( T_1 ) ( - V_147 . V_143 ) ) << V_29 ,
V_147 . V_142 ) ;
V_77 = F_2 ( V_149 - V_14 , V_29 ) ;
V_14 = V_149 ;
if ( V_77 > V_150 || V_77 < - V_150 ) {
F_49 ( L_4 , V_77 ) ;
V_2 |= V_17 ;
V_44 ++ ;
F_45 () ;
} else {
F_46 () ;
}
V_148 = V_77 ;
if ( V_148 < 0 )
V_148 = - V_148 ;
V_36 += ( F_19 ( ( ( T_1 ) V_148 ) <<
( V_29 - V_151 ) ,
V_33 ) - V_36 ) >> V_8 ;
if ( ( V_2 & V_23 ) != 0 &&
( V_2 & V_67 ) == 0 ) {
V_50 = V_14 ;
F_10 () ;
}
return V_77 ;
}
static void F_50 ( long error )
{
long V_152 = - error ;
long V_30 ;
F_44 ( V_152 ) ;
V_152 = F_43 ( & V_30 ) ;
if ( V_30 > ( V_31 << V_153 ) ) {
F_49 ( L_5 ,
V_30 , ( V_31 << V_153 ) ) ;
V_2 |= V_16 ;
V_38 ++ ;
} else if ( V_2 & V_3 ) {
V_69 = F_19 ( ( ( T_1 ) V_152 ) << V_29 ,
V_53 ) ;
V_72 = 0 ;
}
V_31 += ( V_30 - V_31 ) >> V_8 ;
}
void F_51 ( const struct V_95 * V_154 , const struct V_95 * V_155 )
{
struct V_140 V_156 , V_147 ;
unsigned long V_70 ;
V_156 = F_42 ( * V_154 ) ;
F_21 ( & V_71 , V_70 ) ;
V_2 &= ~ ( V_16 | V_17 | V_18 ) ;
V_2 |= V_4 ;
V_15 = V_157 ;
if ( F_18 ( V_11 . V_12 == 0 ) ) {
V_11 = * V_155 ;
F_22 ( & V_71 , V_70 ) ;
return;
}
V_147 = F_42 ( F_52 ( * V_155 , V_11 ) ) ;
if ( ( V_147 . V_142 == 0 ) ||
( V_147 . V_143 > V_89 * V_147 . V_142 ) ||
( V_147 . V_143 < - V_89 * V_147 . V_142 ) ) {
V_2 |= V_16 ;
V_11 = * V_155 ;
F_22 ( & V_71 , V_70 ) ;
F_48 ( L_6 ) ;
return;
}
if ( V_147 . V_142 >= ( 1 << V_7 ) ) {
V_40 ++ ;
V_11 = * V_155 ;
F_47 ( V_147 ) ;
}
F_50 ( V_156 . V_143 ) ;
F_22 ( & V_71 , V_70 ) ;
}
static int T_3 F_53 ( char * V_158 )
{
V_49 = F_54 ( V_158 , NULL , 0 ) ;
V_49 <<= V_29 ;
return 1 ;
}
void T_3 F_55 ( void )
{
F_20 () ;
}
