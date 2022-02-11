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
if ( V_57 % 86400 == 0 ) {
V_78 = - 1 ;
V_79 = V_85 ;
F_25 ( V_86
L_1 ) ;
}
break;
case V_84 :
if ( ( V_57 + 1 ) % 86400 == 0 ) {
V_78 = 1 ;
V_87 -- ;
V_79 = V_88 ;
F_25 ( V_86
L_2 ) ;
}
break;
case V_85 :
V_87 ++ ;
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
if ( abs ( V_96 . V_13 - ( V_99 / 2 ) ) <= V_51 / 2 )
V_98 = F_28 ( V_96 ) ;
V_97 . V_13 = ( V_99 / 2 ) - V_96 . V_13 - ( V_100 / 2 ) ;
if ( V_97 . V_13 <= 0 )
V_97 . V_13 += V_99 ;
if ( ! V_98 )
V_97 . V_12 = 659 ;
else
V_97 . V_12 = 0 ;
if ( V_97 . V_13 >= V_99 ) {
V_97 . V_12 ++ ;
V_97 . V_13 -= V_99 ;
}
F_29 ( & V_101 , F_30 ( & V_97 ) ) ;
}
static void F_31 ( void )
{
F_29 ( & V_101 , 0 ) ;
}
static inline void F_31 ( void ) { }
static inline void F_32 ( struct V_24 * V_25 , struct V_95 * V_102 )
{
if ( ( V_2 & V_64 ) && ! ( V_25 -> V_20 & V_64 ) ) {
V_79 = V_80 ;
V_2 = V_21 ;
F_3 () ;
}
if ( ! ( V_2 & V_64 ) && ( V_25 -> V_20 & V_64 ) )
V_66 = F_17 () ;
V_2 &= V_103 ;
V_2 |= V_25 -> V_20 & ~ V_103 ;
}
static inline void F_33 ( struct V_24 * V_25 , struct V_95 * V_102 )
{
if ( V_25 -> V_104 & V_105 )
F_32 ( V_25 , V_102 ) ;
if ( V_25 -> V_104 & V_106 )
V_2 |= V_32 ;
if ( V_25 -> V_104 & V_107 )
V_2 &= ~ V_32 ;
if ( V_25 -> V_104 & V_108 ) {
V_50 = V_25 -> V_19 * V_109 ;
V_50 = F_15 ( V_50 , V_68 ) ;
V_50 = F_16 ( V_50 , - V_68 ) ;
F_6 ( V_50 ) ;
}
if ( V_25 -> V_104 & V_110 )
V_73 = V_25 -> V_111 ;
if ( V_25 -> V_104 & V_112 )
V_75 = V_25 -> V_113 ;
if ( V_25 -> V_104 & V_114 ) {
V_6 = V_25 -> V_115 ;
if ( ! ( V_2 & V_32 ) )
V_6 += 4 ;
V_6 = F_15 ( V_6 , ( long ) V_116 ) ;
V_6 = F_16 ( V_6 , 0l ) ;
}
if ( V_25 -> V_104 & V_117 && V_25 -> V_115 > 0 )
V_87 = V_25 -> V_115 ;
if ( V_25 -> V_104 & V_118 )
F_14 ( V_25 -> V_1 ) ;
if ( V_25 -> V_104 & V_119 )
V_47 = V_25 -> V_120 ;
if ( V_25 -> V_104 & ( V_119 | V_108 | V_118 ) )
F_10 () ;
}
int F_34 ( struct V_24 * V_25 )
{
struct V_95 V_102 ;
int V_121 ;
if ( V_25 -> V_104 & V_122 ) {
if ( ! ( V_25 -> V_104 & V_123 ) )
return - V_124 ;
if ( ! ( V_25 -> V_104 & V_125 ) &&
! F_35 ( V_126 ) )
return - V_127 ;
} else {
if ( V_25 -> V_104 && ! F_35 ( V_126 ) )
return - V_127 ;
if ( V_25 -> V_104 & V_119 &&
( V_25 -> V_120 < 900000 / V_48 ||
V_25 -> V_120 > 1100000 / V_48 ) )
return - V_124 ;
}
if ( V_25 -> V_104 & V_128 ) {
struct V_95 V_77 ;
V_77 . V_12 = V_25 -> time . V_12 ;
V_77 . V_13 = V_25 -> time . V_129 ;
if ( ! F_35 ( V_126 ) )
return - V_127 ;
if ( ! ( V_25 -> V_104 & V_106 ) )
V_77 . V_13 *= 1000 ;
V_121 = F_36 ( & V_77 ) ;
if ( V_121 )
return V_121 ;
}
F_27 ( & V_102 ) ;
F_37 ( & V_71 ) ;
if ( V_25 -> V_104 & V_122 ) {
long V_130 = V_72 ;
if ( ! ( V_25 -> V_104 & V_125 ) ) {
V_72 = V_25 -> V_1 ;
F_10 () ;
}
V_25 -> V_1 = V_130 ;
} else {
if ( V_25 -> V_104 )
F_33 ( V_25 , & V_102 ) ;
V_25 -> V_1 = F_2 ( V_69 * V_53 ,
V_29 ) ;
if ( ! ( V_2 & V_32 ) )
V_25 -> V_1 /= V_33 ;
}
V_121 = V_79 ;
if ( F_7 ( V_2 ) )
V_121 = V_131 ;
V_25 -> V_19 = F_2 ( ( V_50 >> V_27 ) *
V_28 , V_29 ) ;
V_25 -> V_111 = V_73 ;
V_25 -> V_113 = V_75 ;
V_25 -> V_20 = V_2 ;
V_25 -> V_115 = V_6 ;
V_25 -> V_132 = 1 ;
V_25 -> V_133 = V_68 / V_109 ;
V_25 -> V_120 = V_47 ;
V_25 -> V_134 = V_87 ;
F_8 ( V_25 ) ;
F_38 ( & V_71 ) ;
V_25 -> time . V_12 = V_102 . V_12 ;
V_25 -> time . V_129 = V_102 . V_13 ;
if ( ! ( V_2 & V_32 ) )
V_25 -> time . V_129 /= V_33 ;
F_31 () ;
return V_121 ;
}
static inline struct V_135 F_39 ( struct V_95 V_102 )
{
struct V_135 V_136 = {
. V_137 = V_102 . V_12 ,
. V_138 = V_102 . V_13
} ;
if ( V_136 . V_138 > ( V_99 >> 1 ) ) {
V_136 . V_138 -= V_99 ;
V_136 . V_137 ++ ;
}
return V_136 ;
}
static inline long F_40 ( long * V_30 )
{
* V_30 = V_10 [ 0 ] - V_10 [ 1 ] ;
if ( * V_30 < 0 )
* V_30 = - * V_30 ;
return V_10 [ 0 ] ;
}
static inline void F_41 ( long V_139 )
{
V_10 [ 2 ] = V_10 [ 1 ] ;
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_139 ;
}
static inline void F_42 ( void )
{
if ( -- V_9 <= - V_140 ) {
V_9 = - V_140 ;
if ( V_7 > V_8 ) {
V_7 -- ;
V_9 = 0 ;
}
}
}
static inline void F_43 ( void )
{
if ( ++ V_9 >= V_140 ) {
V_9 = V_140 ;
if ( V_7 < V_141 ) {
V_7 ++ ;
V_9 = 0 ;
}
}
}
static long F_44 ( struct V_135 V_142 )
{
long V_77 , V_143 ;
T_1 V_144 ;
if ( V_142 . V_137 > ( 2 << V_7 ) ) {
V_2 |= V_18 ;
V_42 ++ ;
F_42 () ;
F_45 ( L_3 ,
V_142 . V_137 ) ;
return 0 ;
}
V_144 = F_19 ( ( ( T_1 ) ( - V_142 . V_138 ) ) << V_29 ,
V_142 . V_137 ) ;
V_77 = F_2 ( V_144 - V_14 , V_29 ) ;
V_14 = V_144 ;
if ( V_77 > V_145 || V_77 < - V_145 ) {
F_46 ( L_4 , V_77 ) ;
V_2 |= V_17 ;
V_44 ++ ;
F_42 () ;
} else {
F_43 () ;
}
V_143 = V_77 ;
if ( V_143 < 0 )
V_143 = - V_143 ;
V_36 += ( F_19 ( ( ( T_1 ) V_143 ) <<
( V_29 - V_146 ) ,
V_33 ) - V_36 ) >> V_8 ;
if ( ( V_2 & V_23 ) != 0 &&
( V_2 & V_67 ) == 0 ) {
V_50 = V_14 ;
F_10 () ;
}
return V_77 ;
}
static void F_47 ( long error )
{
long V_147 = - error ;
long V_30 ;
F_41 ( V_147 ) ;
V_147 = F_40 ( & V_30 ) ;
if ( V_30 > ( V_31 << V_148 ) ) {
F_46 ( L_5 ,
V_30 , ( V_31 << V_148 ) ) ;
V_2 |= V_16 ;
V_38 ++ ;
} else if ( V_2 & V_3 ) {
V_69 = F_19 ( ( ( T_1 ) V_147 ) << V_29 ,
V_53 ) ;
V_72 = 0 ;
}
V_31 += ( V_30 - V_31 ) >> V_8 ;
}
void F_48 ( const struct V_95 * V_149 , const struct V_95 * V_150 )
{
struct V_135 V_151 , V_142 ;
unsigned long V_70 ;
V_151 = F_39 ( * V_149 ) ;
F_21 ( & V_71 , V_70 ) ;
V_2 &= ~ ( V_16 | V_17 | V_18 ) ;
V_2 |= V_4 ;
V_15 = V_152 ;
if ( F_18 ( V_11 . V_12 == 0 ) ) {
V_11 = * V_150 ;
F_22 ( & V_71 , V_70 ) ;
return;
}
V_142 = F_39 ( F_49 ( * V_150 , V_11 ) ) ;
if ( ( V_142 . V_137 == 0 ) ||
( V_142 . V_138 > V_89 * V_142 . V_137 ) ||
( V_142 . V_138 < - V_89 * V_142 . V_137 ) ) {
V_2 |= V_16 ;
V_11 = * V_150 ;
F_22 ( & V_71 , V_70 ) ;
F_45 ( L_6 ) ;
return;
}
if ( V_142 . V_137 >= ( 1 << V_7 ) ) {
V_40 ++ ;
V_11 = * V_150 ;
F_44 ( V_142 ) ;
}
F_47 ( V_151 . V_138 ) ;
F_22 ( & V_71 , V_70 ) ;
}
static int T_3 F_50 ( char * V_153 )
{
V_49 = F_51 ( V_153 , NULL , 0 ) ;
V_49 <<= V_29 ;
return 1 ;
}
void T_3 F_52 ( void )
{
F_20 () ;
}
