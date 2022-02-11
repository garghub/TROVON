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
static void F_9 ( void )
{
T_2 V_45 ;
T_2 V_46 ;
V_45 = ( T_2 ) ( V_47 * V_33 * V_48 )
<< V_29 ;
V_45 += V_49 ;
V_45 += V_50 ;
V_51 = F_10 ( V_45 , V_52 ) >> V_29 ;
V_46 = F_10 ( V_45 , V_53 ) ;
V_54 += V_46 - V_55 ;
V_55 = V_46 ;
}
static inline T_1 F_11 ( T_1 V_56 , long V_57 )
{
V_2 &= ~ V_58 ;
if ( V_57 < V_59 )
return 0 ;
if ( ! ( V_2 & V_60 ) && ( V_57 <= V_61 ) )
return 0 ;
V_2 |= V_58 ;
return F_12 ( V_56 << ( V_29 - V_62 ) , V_57 ) ;
}
static void F_13 ( long V_1 )
{
T_1 V_63 ;
T_1 V_56 ;
long V_57 ;
if ( ! ( V_2 & V_64 ) )
return;
if ( ! ( V_2 & V_32 ) )
V_1 *= V_33 ;
V_1 = F_14 ( V_1 , V_65 ) ;
V_1 = F_15 ( V_1 , - V_65 ) ;
V_57 = F_16 () - V_66 ;
if ( F_17 ( V_2 & V_67 ) )
V_57 = 0 ;
V_66 = F_16 () ;
V_56 = V_1 ;
V_63 = F_11 ( V_56 , V_57 ) ;
if ( F_17 ( V_57 > 1 << ( V_5 + 1 + V_6 ) ) )
V_57 = 1 << ( V_5 + 1 + V_6 ) ;
V_63 += ( V_56 * V_57 ) <<
( V_29 - 2 * ( V_5 + 2 + V_6 ) ) ;
V_63 = F_14 ( V_63 + V_50 , V_68 ) ;
V_50 = F_15 ( V_63 , - V_68 ) ;
V_69 = F_12 ( V_56 << V_29 , V_53 ) ;
}
void F_18 ( void )
{
V_70 = 0 ;
V_2 |= V_21 ;
V_71 = V_72 ;
V_73 = V_72 ;
F_9 () ;
V_54 = V_55 ;
V_69 = 0 ;
F_4 () ;
}
static enum V_74 F_19 ( struct V_75 * V_76 )
{
enum V_74 V_77 = V_78 ;
F_20 ( & V_79 ) ;
switch ( V_80 ) {
case V_81 :
break;
case V_82 :
F_21 ( - 1 ) ;
V_80 = V_83 ;
F_22 ( V_84
L_1 ) ;
F_23 ( & V_85 , V_86 ) ;
V_77 = V_87 ;
break;
case V_88 :
F_21 ( 1 ) ;
V_89 -- ;
V_80 = V_90 ;
F_22 ( V_84
L_2 ) ;
break;
case V_83 :
V_89 ++ ;
V_80 = V_90 ;
case V_90 :
if ( ! ( V_2 & ( V_91 | V_92 ) ) )
V_80 = V_81 ;
break;
}
F_24 ( & V_79 ) ;
return V_77 ;
}
void F_25 ( void )
{
T_1 V_93 ;
V_71 += V_94 / V_33 ;
if ( V_71 > V_72 ) {
V_71 = V_72 ;
V_2 |= V_21 ;
}
V_54 = V_55 ;
V_93 = F_1 ( V_69 ) ;
V_69 -= V_93 ;
V_54 += V_93 ;
F_5 () ;
if ( ! V_70 )
return;
if ( V_70 > V_95 ) {
V_70 -= V_95 ;
V_54 += V_96 ;
return;
}
if ( V_70 < - V_95 ) {
V_70 += V_95 ;
V_54 -= V_96 ;
return;
}
V_54 += ( T_1 ) ( V_70 * V_33 / V_53 )
<< V_29 ;
V_70 = 0 ;
}
static void F_26 ( struct V_97 * V_98 )
{
struct V_99 V_100 , V_101 ;
int V_102 = 1 ;
if ( ! F_27 () ) {
return;
}
F_28 ( & V_100 ) ;
if ( abs ( V_100 . V_13 - ( V_86 / 2 ) ) <= V_51 / 2 )
V_102 = F_29 ( V_100 ) ;
V_101 . V_13 = ( V_86 / 2 ) - V_100 . V_13 - ( V_103 / 2 ) ;
if ( V_101 . V_13 <= 0 )
V_101 . V_13 += V_86 ;
if ( ! V_102 )
V_101 . V_12 = 659 ;
else
V_101 . V_12 = 0 ;
if ( V_101 . V_13 >= V_86 ) {
V_101 . V_12 ++ ;
V_101 . V_13 -= V_86 ;
}
F_30 ( & V_104 , F_31 ( & V_101 ) ) ;
}
static void F_32 ( void )
{
if ( ! V_105 )
F_30 ( & V_104 , 0 ) ;
}
static inline void F_32 ( void ) { }
static inline void F_33 ( struct V_99 * V_106 )
{
long V_100 = V_106 -> V_12 ;
if ( V_2 & V_91 ) {
V_80 = V_82 ;
V_100 += 86400 - V_100 % 86400 ;
F_34 ( & V_85 , F_35 ( V_100 , 0 ) , V_107 ) ;
return;
}
if ( V_2 & V_92 ) {
V_80 = V_88 ;
V_100 += 86400 - ( V_100 + 1 ) % 86400 ;
F_34 ( & V_85 , F_35 ( V_100 , 0 ) , V_107 ) ;
}
}
static inline void F_36 ( struct V_24 * V_25 , struct V_99 * V_106 )
{
if ( ( V_2 & V_64 ) && ! ( V_25 -> V_20 & V_64 ) ) {
V_80 = V_81 ;
V_2 = V_21 ;
F_3 () ;
}
if ( ! ( V_2 & V_64 ) && ( V_25 -> V_20 & V_64 ) )
V_66 = F_16 () ;
V_2 &= V_108 ;
V_2 |= V_25 -> V_20 & ~ V_108 ;
switch ( V_80 ) {
case V_81 :
F_33 ( V_106 ) ;
break;
case V_82 :
case V_88 :
V_80 = V_81 ;
F_33 ( V_106 ) ;
case V_90 :
if ( ! ( V_2 & ( V_91 | V_92 ) ) )
V_80 = V_81 ;
break;
case V_83 :
V_74 ( & V_85 ) ;
break;
}
}
static inline void F_37 ( struct V_24 * V_25 , struct V_99 * V_106 )
{
if ( V_25 -> V_109 & V_110 )
F_36 ( V_25 , V_106 ) ;
if ( V_25 -> V_109 & V_111 )
V_2 |= V_32 ;
if ( V_25 -> V_109 & V_112 )
V_2 &= ~ V_32 ;
if ( V_25 -> V_109 & V_113 ) {
V_50 = V_25 -> V_19 * V_114 ;
V_50 = F_14 ( V_50 , V_68 ) ;
V_50 = F_15 ( V_50 , - V_68 ) ;
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
V_6 = F_14 ( V_6 , ( long ) V_121 ) ;
V_6 = F_15 ( V_6 , 0l ) ;
}
if ( V_25 -> V_109 & V_122 && V_25 -> V_120 > 0 )
V_89 = V_25 -> V_120 ;
if ( V_25 -> V_109 & V_123 )
F_13 ( V_25 -> V_1 ) ;
if ( V_25 -> V_109 & V_124 )
V_47 = V_25 -> V_125 ;
if ( V_25 -> V_109 & ( V_124 | V_113 | V_123 ) )
F_9 () ;
}
int F_38 ( struct V_24 * V_25 )
{
struct V_99 V_106 ;
int V_126 ;
if ( V_25 -> V_109 & V_127 ) {
if ( ! ( V_25 -> V_109 & V_128 ) )
return - V_129 ;
if ( ! ( V_25 -> V_109 & V_130 ) &&
! F_39 ( V_131 ) )
return - V_132 ;
} else {
if ( V_25 -> V_109 && ! F_39 ( V_131 ) )
return - V_132 ;
if ( V_25 -> V_109 & V_124 &&
( V_25 -> V_125 < 900000 / V_48 ||
V_25 -> V_125 > 1100000 / V_48 ) )
return - V_129 ;
if ( V_25 -> V_109 & V_110 && V_80 != V_81 )
F_40 ( & V_85 ) ;
}
if ( V_25 -> V_109 & V_133 ) {
struct V_99 V_93 ;
V_93 . V_12 = V_25 -> time . V_12 ;
V_93 . V_13 = V_25 -> time . V_134 ;
if ( ! F_39 ( V_131 ) )
return - V_132 ;
if ( ! ( V_25 -> V_109 & V_111 ) )
V_93 . V_13 *= 1000 ;
V_126 = F_41 ( & V_93 ) ;
if ( V_126 )
return V_126 ;
}
F_28 ( & V_106 ) ;
F_42 ( & V_79 ) ;
if ( V_25 -> V_109 & V_127 ) {
long V_135 = V_70 ;
if ( ! ( V_25 -> V_109 & V_130 ) ) {
V_70 = V_25 -> V_1 ;
F_9 () ;
}
V_25 -> V_1 = V_135 ;
} else {
if ( V_25 -> V_109 )
F_37 ( V_25 , & V_106 ) ;
V_25 -> V_1 = F_2 ( V_69 * V_53 ,
V_29 ) ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_1 /= V_33 ;
}
V_126 = V_80 ;
if ( F_7 ( V_2 ) )
V_126 = V_136 ;
V_25 -> V_19 = F_2 ( ( V_50 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_116 = V_71 ;
V_25 -> V_118 = V_73 ;
V_25 -> V_20 = V_2 ;
V_25 -> V_120 = V_6 ;
V_25 -> V_137 = 1 ;
V_25 -> V_138 = V_68 / V_114 ;
V_25 -> V_125 = V_47 ;
V_25 -> V_139 = V_89 ;
F_8 ( V_25 ) ;
F_43 ( & V_79 ) ;
V_25 -> time . V_12 = V_106 . V_12 ;
V_25 -> time . V_134 = V_106 . V_13 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> time . V_134 /= V_33 ;
F_32 () ;
return V_126 ;
}
static inline struct V_140 F_44 ( struct V_99 V_106 )
{
struct V_140 V_141 = {
. V_142 = V_106 . V_12 ,
. V_143 = V_106 . V_13
} ;
if ( V_141 . V_143 > ( V_86 >> 1 ) ) {
V_141 . V_143 -= V_86 ;
V_141 . V_142 ++ ;
}
return V_141 ;
}
static inline long F_45 ( long * V_30 )
{
* V_30 = V_10 [ 0 ] - V_10 [ 1 ] ;
if ( * V_30 < 0 )
* V_30 = - * V_30 ;
return V_10 [ 0 ] ;
}
static inline void F_46 ( long V_144 )
{
V_10 [ 2 ] = V_10 [ 1 ] ;
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_144 ;
}
static inline void F_47 ( void )
{
if ( -- V_9 <= - V_145 ) {
V_9 = - V_145 ;
if ( V_7 > V_8 ) {
V_7 -- ;
V_9 = 0 ;
}
}
}
static inline void F_48 ( void )
{
if ( ++ V_9 >= V_145 ) {
V_9 = V_145 ;
if ( V_7 < V_146 ) {
V_7 ++ ;
V_9 = 0 ;
}
}
}
static long F_49 ( struct V_140 V_147 )
{
long V_93 , V_148 ;
T_1 V_149 ;
if ( V_147 . V_142 > ( 2 << V_7 ) ) {
V_2 |= V_18 ;
V_42 ++ ;
F_47 () ;
F_50 ( L_3 ,
V_147 . V_142 ) ;
return 0 ;
}
V_149 = F_12 ( ( ( T_1 ) ( - V_147 . V_143 ) ) << V_29 ,
V_147 . V_142 ) ;
V_93 = F_2 ( V_149 - V_14 , V_29 ) ;
V_14 = V_149 ;
if ( V_93 > V_150 || V_93 < - V_150 ) {
F_51 ( L_4 , V_93 ) ;
V_2 |= V_17 ;
V_44 ++ ;
F_47 () ;
} else {
F_48 () ;
}
V_148 = V_93 ;
if ( V_148 < 0 )
V_148 = - V_148 ;
V_36 += ( F_12 ( ( ( T_1 ) V_148 ) <<
( V_29 - V_151 ) ,
V_33 ) - V_36 ) >> V_8 ;
if ( ( V_2 & V_23 ) != 0 &&
( V_2 & V_67 ) == 0 ) {
V_50 = V_14 ;
F_9 () ;
}
return V_93 ;
}
static void F_52 ( long error )
{
long V_152 = - error ;
long V_30 ;
F_46 ( V_152 ) ;
V_152 = F_45 ( & V_30 ) ;
if ( V_30 > ( V_31 << V_153 ) ) {
F_51 ( L_5 ,
V_30 , ( V_31 << V_153 ) ) ;
V_2 |= V_16 ;
V_38 ++ ;
} else if ( V_2 & V_3 ) {
V_69 = F_12 ( ( ( T_1 ) V_152 ) << V_29 ,
V_53 ) ;
V_70 = 0 ;
}
V_31 += ( V_30 - V_31 ) >> V_8 ;
}
void F_53 ( const struct V_99 * V_154 , const struct V_99 * V_155 )
{
struct V_140 V_156 , V_147 ;
unsigned long V_157 ;
V_156 = F_44 ( * V_154 ) ;
F_54 ( & V_79 , V_157 ) ;
V_2 &= ~ ( V_16 | V_17 | V_18 ) ;
V_2 |= V_4 ;
V_15 = V_158 ;
if ( F_17 ( V_11 . V_12 == 0 ) ) {
V_11 = * V_155 ;
F_55 ( & V_79 , V_157 ) ;
return;
}
V_147 = F_44 ( F_56 ( * V_155 , V_11 ) ) ;
if ( ( V_147 . V_142 == 0 ) ||
( V_147 . V_143 > V_94 * V_147 . V_142 ) ||
( V_147 . V_143 < - V_94 * V_147 . V_142 ) ) {
V_2 |= V_16 ;
V_11 = * V_155 ;
F_55 ( & V_79 , V_157 ) ;
F_50 ( L_6 ) ;
return;
}
if ( V_147 . V_142 >= ( 1 << V_7 ) ) {
V_40 ++ ;
V_11 = * V_155 ;
F_49 ( V_147 ) ;
}
F_52 ( V_156 . V_143 ) ;
F_55 ( & V_79 , V_157 ) ;
}
static int T_3 F_57 ( char * V_159 )
{
V_49 = F_58 ( V_159 , NULL , 0 ) ;
V_49 <<= V_29 ;
return 1 ;
}
void T_3 F_59 ( void )
{
F_18 () ;
F_60 ( & V_85 , V_160 , V_107 ) ;
V_85 . V_161 = F_19 ;
}
