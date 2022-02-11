static int
F_1 ( int V_1 , int V_2 , int V_3 )
{
return ( V_2 * ( 100 - V_3 ) + V_1 * V_3 ) / 100 ;
}
static int
F_2 ( struct V_4 * V_5 )
{
return F_3 ( ( V_5 -> V_6 / V_7 ) + 1 ,
! ! ( V_5 -> V_8 & V_9 ) ,
! ! ( V_5 -> V_8 & V_10 ) ) ;
}
static struct V_11 *
F_4 ( struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_4 * V_5 )
{
int V_16 , V_6 ;
if ( V_5 -> V_8 & V_17 ) {
V_16 = F_2 ( V_5 ) ;
V_6 = V_5 -> V_6 % V_7 ;
} else {
V_16 = V_18 ;
for ( V_6 = 0 ; V_6 < F_5 ( V_13 -> V_19 ) ; V_6 ++ )
if ( V_5 -> V_6 == V_13 -> V_19 [ V_6 ] )
break;
if ( ! ( V_15 -> V_20 [ V_16 ] . V_21 & F_6 ( V_6 ) ) )
V_6 += 4 ;
}
return & V_15 -> V_20 [ V_16 ] . V_22 [ V_6 ] ;
}
static inline struct V_11 *
F_7 ( struct V_14 * V_15 , int V_23 )
{
return & V_15 -> V_20 [ V_23 / V_7 ] . V_22 [ V_23 % V_7 ] ;
}
static void
F_8 ( struct V_11 * V_24 )
{
if ( F_9 ( V_24 -> V_25 > 0 ) ) {
V_24 -> V_26 = 0 ;
V_24 -> V_27 = F_10 ( V_24 -> V_28 , V_24 -> V_25 ) ;
if ( ! V_24 -> V_29 )
V_24 -> V_30 = V_24 -> V_27 ;
else
V_24 -> V_30 = F_1 ( V_24 -> V_30 ,
V_24 -> V_27 , V_31 ) ;
V_24 -> V_29 += V_24 -> V_25 ;
V_24 -> V_32 += V_24 -> V_28 ;
} else {
V_24 -> V_26 ++ ;
}
V_24 -> V_33 = V_24 -> V_28 ;
V_24 -> V_34 = V_24 -> V_25 ;
V_24 -> V_28 = 0 ;
V_24 -> V_25 = 0 ;
}
static void
F_11 ( struct V_14 * V_15 , int V_16 , int V_5 )
{
struct V_11 * V_24 ;
unsigned int V_35 = 0 ;
V_24 = & V_15 -> V_20 [ V_16 ] . V_22 [ V_5 ] ;
if ( V_24 -> V_30 < F_10 ( 1 , 10 ) ) {
V_24 -> V_36 = 0 ;
return;
}
if ( V_16 != V_18 )
V_35 = V_15 -> V_37 / F_12 ( V_15 -> V_38 ) ;
V_35 += V_39 [ V_16 ] . V_40 [ V_5 ] ;
V_24 -> V_36 = F_12 ( ( 1000000 / V_35 ) * V_24 -> V_30 ) ;
}
static void
F_13 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_41 * V_42 ;
struct V_11 * V_24 ;
int V_27 , V_43 , V_36 , V_44 ;
int V_16 , V_45 , V_23 ;
if ( V_15 -> V_46 > 0 ) {
V_15 -> V_38 = F_1 ( V_15 -> V_38 ,
F_10 ( V_15 -> V_47 , V_15 -> V_46 ) , V_31 ) ;
V_15 -> V_47 = 0 ;
V_15 -> V_46 = 0 ;
}
V_15 -> V_48 = 0 ;
V_15 -> V_49 = 0 ;
V_15 -> V_50 = 0 ;
V_15 -> V_51 = 0 ;
V_15 -> V_52 = 0 ;
for ( V_16 = 0 ; V_16 < F_5 ( V_39 ) ; V_16 ++ ) {
V_27 = 0 ;
V_43 = 0 ;
V_36 = 0 ;
V_44 = 0 ;
V_42 = & V_15 -> V_20 [ V_16 ] ;
if ( ! V_42 -> V_21 )
continue;
V_42 -> V_50 = 0 ;
V_42 -> V_51 = 0 ;
V_42 -> V_52 = 0 ;
V_15 -> V_49 ++ ;
for ( V_45 = 0 ; V_45 < V_7 ; V_45 ++ ) {
if ( ! ( V_42 -> V_21 & F_6 ( V_45 ) ) )
continue;
V_24 = & V_42 -> V_22 [ V_45 ] ;
V_24 -> V_53 = false ;
V_23 = V_7 * V_16 + V_45 ;
F_8 ( V_24 ) ;
F_11 ( V_15 , V_16 , V_45 ) ;
if ( ! V_24 -> V_36 )
continue;
if ( ( V_24 -> V_36 > V_43 && V_24 -> V_30 >
F_10 ( 3 , 4 ) ) || V_24 -> V_30 > V_27 ) {
V_42 -> V_52 = V_23 ;
V_27 = V_24 -> V_30 ;
V_43 = V_24 -> V_36 ;
}
if ( V_24 -> V_36 > V_36 ) {
F_14 ( V_23 , V_42 -> V_50 ) ;
V_36 = V_24 -> V_36 ;
V_24 = F_7 ( V_15 , V_23 ) ;
}
if ( V_23 >= V_42 -> V_50 )
continue;
if ( V_24 -> V_36 > V_44 ) {
V_42 -> V_51 = V_23 ;
V_44 = V_24 -> V_36 ;
}
}
}
V_15 -> V_49 *= 4 ;
V_27 = 0 ;
V_43 = 0 ;
V_36 = 0 ;
V_44 = 0 ;
for ( V_16 = 0 ; V_16 < F_5 ( V_39 ) ; V_16 ++ ) {
V_42 = & V_15 -> V_20 [ V_16 ] ;
if ( ! V_42 -> V_21 )
continue;
V_24 = F_7 ( V_15 , V_42 -> V_52 ) ;
if ( V_43 < V_24 -> V_36 &&
V_39 [ V_16 ] . V_54 == 1 ) {
V_15 -> V_52 = V_42 -> V_52 ;
V_27 = V_24 -> V_27 ;
V_43 = V_24 -> V_36 ;
}
V_24 = F_7 ( V_15 , V_42 -> V_50 ) ;
if ( V_36 < V_24 -> V_36 ) {
V_15 -> V_51 = V_15 -> V_50 ;
V_44 = V_36 ;
V_15 -> V_50 = V_42 -> V_50 ;
V_36 = V_24 -> V_36 ;
}
V_24 = F_7 ( V_15 , V_42 -> V_51 ) ;
if ( V_44 < V_24 -> V_36 ) {
V_15 -> V_51 = V_42 -> V_51 ;
V_44 = V_24 -> V_36 ;
}
}
V_15 -> V_55 = V_56 ;
}
static bool
F_15 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
if ( V_5 -> V_6 < 0 )
return false ;
if ( ! V_5 -> V_57 )
return false ;
if ( V_5 -> V_8 & V_17 )
return true ;
return V_5 -> V_6 == V_13 -> V_19 [ 0 ] ||
V_5 -> V_6 == V_13 -> V_19 [ 1 ] ||
V_5 -> V_6 == V_13 -> V_19 [ 2 ] ||
V_5 -> V_6 == V_13 -> V_19 [ 3 ] ;
}
static void
F_16 ( struct V_14 * V_15 )
{
struct V_41 * V_42 ;
for (; ; ) {
V_15 -> V_58 ++ ;
V_15 -> V_58 %= F_5 ( V_39 ) ;
V_42 = & V_15 -> V_20 [ V_15 -> V_58 ] ;
if ( ! V_42 -> V_21 )
continue;
if ( ++ V_42 -> V_23 >= V_7 ) {
V_42 -> V_23 = 0 ;
if ( ++ V_42 -> V_59 >= F_5 ( V_60 ) )
V_42 -> V_59 = 0 ;
}
break;
}
}
static void
F_17 ( struct V_14 * V_15 , unsigned int * V_6 ,
bool V_61 )
{
int V_16 , V_62 ;
V_62 = V_16 = * V_6 / V_7 ;
while ( V_16 > 0 ) {
V_16 -- ;
if ( ! V_15 -> V_20 [ V_16 ] . V_21 )
continue;
if ( V_39 [ V_16 ] . V_54 >
V_39 [ V_62 ] . V_54 )
continue;
if ( V_61 )
* V_6 = V_15 -> V_20 [ V_16 ] . V_50 ;
else
* V_6 = V_15 -> V_20 [ V_16 ] . V_51 ;
break;
}
}
static void
F_18 ( struct V_63 * V_64 , struct V_65 * V_66 )
{
struct V_67 * V_68 = (struct V_67 * ) V_66 -> V_69 ;
struct V_70 * V_71 = F_19 ( V_64 , struct V_70 , V_71 ) ;
T_1 V_72 ;
if ( F_9 ( ! F_20 ( V_68 -> V_73 ) ) )
return;
if ( F_9 ( V_66 -> V_74 == F_21 ( V_75 ) ) )
return;
V_72 = * F_22 ( V_68 ) & V_76 ;
if ( F_23 ( V_71 -> V_77 . V_78 [ V_72 ] ) )
return;
if ( F_24 ( V_66 ) == V_79 )
return;
F_25 ( V_64 , V_72 , 5000 ) ;
}
static void
F_26 ( void * V_80 , struct V_81 * V_82 ,
struct V_63 * V_71 , void * V_83 ,
struct V_65 * V_66 )
{
struct V_84 * V_85 = V_83 ;
struct V_14 * V_15 = & V_85 -> V_86 ;
struct V_87 * V_88 = F_27 ( V_66 ) ;
struct V_4 * V_89 = V_88 -> V_90 . V_22 ;
struct V_11 * V_5 , * V_91 ;
struct V_12 * V_13 = V_80 ;
bool V_92 ;
int V_45 ;
if ( ! V_85 -> V_93 )
return V_94 . V_95 ( V_80 , V_82 , V_71 , & V_85 -> V_96 , V_66 ) ;
if ( ( V_88 -> V_8 & V_97 ) &&
! ( V_88 -> V_8 & V_98 ) )
return;
if ( ! ( V_88 -> V_8 & V_98 ) ) {
V_88 -> V_90 . V_99 =
( V_88 -> V_8 & V_100 ? 1 : 0 ) ;
V_88 -> V_90 . V_47 = 1 ;
}
V_15 -> V_46 ++ ;
V_15 -> V_47 += V_88 -> V_90 . V_47 ;
if ( ! V_15 -> V_101 && ! V_15 -> V_102 && V_15 -> V_49 > 0 ) {
V_15 -> V_101 = 16 + 2 * F_12 ( V_15 -> V_38 ) ;
V_15 -> V_102 = 2 ;
V_15 -> V_49 -- ;
}
if ( V_88 -> V_8 & V_103 )
V_15 -> V_104 += V_88 -> V_90 . V_47 ;
V_92 = ! F_15 ( V_13 , & V_89 [ 0 ] ) ;
for ( V_45 = 0 ; ! V_92 ; V_45 ++ ) {
V_92 = ( V_45 == V_105 - 1 ) ||
! F_15 ( V_13 , & V_89 [ V_45 + 1 ] ) ;
V_5 = F_4 ( V_13 , V_15 , & V_89 [ V_45 ] ) ;
if ( V_92 )
V_5 -> V_28 += V_88 -> V_90 . V_99 ;
V_5 -> V_25 += V_89 [ V_45 ] . V_57 * V_88 -> V_90 . V_47 ;
}
V_5 = F_7 ( V_15 , V_15 -> V_50 ) ;
if ( V_5 -> V_25 > 30 &&
F_10 ( V_5 -> V_28 , V_5 -> V_25 ) <
F_10 ( 20 , 100 ) )
F_17 ( V_15 , & V_15 -> V_50 , true ) ;
V_91 = F_7 ( V_15 , V_15 -> V_51 ) ;
if ( V_91 -> V_25 > 30 &&
F_10 ( V_91 -> V_28 , V_91 -> V_25 ) <
F_10 ( 20 , 100 ) )
F_17 ( V_15 , & V_15 -> V_51 , false ) ;
if ( F_28 ( V_56 , V_15 -> V_55 + ( V_13 -> V_106 / 2 * V_107 ) / 1000 ) ) {
F_13 ( V_13 , V_15 ) ;
if ( ! ( V_88 -> V_8 & V_97 ) &&
V_15 -> V_52 / V_7 != V_18 )
F_18 ( V_71 , V_66 ) ;
}
}
static void
F_29 ( struct V_12 * V_13 , struct V_14 * V_15 ,
int V_23 )
{
struct V_11 * V_24 ;
const struct V_108 * V_16 ;
unsigned int V_109 , V_110 , V_111 ;
unsigned int V_112 = V_13 -> V_113 ;
unsigned int ctime = 0 ;
unsigned int V_114 = 9 ;
unsigned int V_47 = F_12 ( V_15 -> V_38 ) ;
unsigned int V_37 = 0 , V_115 = 0 ;
V_24 = F_7 ( V_15 , V_23 ) ;
if ( V_24 -> V_30 < F_10 ( 1 , 10 ) ) {
V_24 -> V_116 = 1 ;
V_24 -> V_117 = 1 ;
return;
}
V_24 -> V_116 = 2 ;
V_24 -> V_117 = 2 ;
V_24 -> V_53 = true ;
V_16 = & V_39 [ V_23 / V_7 ] ;
V_111 = V_16 -> V_40 [ V_23 % V_7 ] * V_47 ;
ctime = ( V_114 * V_112 ) >> 1 ;
V_112 = F_30 ( ( V_112 << 1 ) | 1 , V_13 -> V_118 ) ;
ctime += ( V_114 * V_112 ) >> 1 ;
V_112 = F_30 ( ( V_112 << 1 ) | 1 , V_13 -> V_118 ) ;
if ( V_23 / V_7 != V_18 ) {
V_37 = V_15 -> V_37 ;
V_115 = V_15 -> V_115 ;
}
V_109 = ctime + 2 * ( V_37 + V_111 ) ;
V_110 = ctime + 2 * ( V_115 + V_111 ) ;
do {
ctime = ( V_114 * V_112 ) >> 1 ;
V_112 = F_30 ( ( V_112 << 1 ) | 1 , V_13 -> V_118 ) ;
V_109 += ctime + V_37 + V_111 ;
V_110 += ctime + V_115 + V_111 ;
if ( V_110 < V_13 -> V_119 )
V_24 -> V_117 ++ ;
} while ( ( V_109 < V_13 -> V_119 ) &&
( ++ V_24 -> V_116 < V_13 -> V_120 ) );
}
static void
F_31 ( struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_4 * V_5 , int V_23 ,
bool V_121 , bool V_122 )
{
const struct V_108 * V_16 = & V_39 [ V_23 / V_7 ] ;
struct V_11 * V_24 ;
V_24 = F_7 ( V_15 , V_23 ) ;
if ( ! V_24 -> V_53 )
F_29 ( V_13 , V_15 , V_23 ) ;
if ( V_121 )
V_5 -> V_57 = 1 ;
else if ( V_24 -> V_30 < F_10 ( 20 , 100 ) )
V_5 -> V_57 = 2 ;
else if ( V_122 )
V_5 -> V_57 = V_24 -> V_117 ;
else
V_5 -> V_57 = V_24 -> V_116 ;
V_5 -> V_8 = 0 ;
if ( V_122 )
V_5 -> V_8 |= V_123 ;
if ( V_23 / V_7 == V_18 ) {
V_5 -> V_6 = V_13 -> V_19 [ V_23 % F_5 ( V_13 -> V_19 ) ] ;
return;
}
V_5 -> V_8 |= V_17 | V_16 -> V_8 ;
V_5 -> V_6 = V_23 % V_7 + ( V_16 -> V_54 - 1 ) * V_7 ;
}
static inline int
F_32 ( int V_23 )
{
const struct V_108 * V_16 = & V_39 [ V_23 / V_7 ] ;
return V_16 -> V_40 [ V_23 % V_7 ] ;
}
static int
F_33 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_11 * V_24 ;
struct V_41 * V_42 ;
int V_124 = 0 ;
if ( V_15 -> V_101 > 0 ) {
V_15 -> V_101 -- ;
return - 1 ;
}
if ( ! V_15 -> V_102 )
return - 1 ;
V_15 -> V_102 -- ;
V_42 = & V_15 -> V_20 [ V_15 -> V_58 ] ;
V_124 = V_60 [ V_42 -> V_59 ] [ V_42 -> V_23 ] ;
V_24 = & V_42 -> V_22 [ V_124 ] ;
V_124 += V_15 -> V_58 * V_7 ;
F_16 ( V_15 ) ;
if ( V_124 == V_15 -> V_50 )
return - 1 ;
if ( ! V_13 -> V_125 && ( V_24 -> V_30 > F_10 ( 95 , 100 ) ) )
return - 1 ;
if ( F_32 ( V_124 ) >
F_32 ( V_15 -> V_50 ) ) {
if ( V_24 -> V_26 < 20 )
return - 1 ;
if ( V_15 -> V_48 ++ > 2 )
return - 1 ;
}
return V_124 ;
}
static void
F_34 ( struct V_12 * V_13 ,
struct V_14 * V_15 , bool V_126 )
{
T_2 V_21 = V_15 -> V_20 [ V_18 ] . V_21 ;
if ( ! V_21 || ! V_15 -> V_127 )
return;
if ( V_21 & ( V_15 -> V_127 << ( V_126 * 4 ) ) )
return;
V_21 ^= V_15 -> V_127 | ( V_15 -> V_127 << 4 ) ;
V_15 -> V_20 [ V_18 ] . V_21 = V_21 ;
}
static void
F_35 ( void * V_80 , struct V_63 * V_71 , void * V_83 ,
struct V_128 * V_129 )
{
struct V_87 * V_88 = F_27 ( V_129 -> V_66 ) ;
struct V_4 * V_89 = V_88 -> V_90 . V_22 ;
struct V_84 * V_85 = V_83 ;
struct V_14 * V_15 = & V_85 -> V_86 ;
struct V_12 * V_13 = V_80 ;
int V_124 ;
bool V_121 = false ;
if ( F_36 ( V_71 , V_83 , V_129 ) )
return;
if ( ! V_85 -> V_93 )
return V_94 . V_130 ( V_80 , V_71 , & V_85 -> V_96 , V_129 ) ;
V_88 -> V_8 |= V_15 -> V_131 ;
F_34 ( V_13 , V_15 , V_129 -> V_132 ) ;
if ( V_13 -> V_133 -> V_134 == 1 &&
V_129 -> V_66 -> V_74 == F_21 ( V_75 ) )
V_124 = - 1 ;
else
V_124 = F_33 ( V_13 , V_15 ) ;
#ifdef F_37
if ( V_13 -> V_135 != - 1 ) {
V_15 -> V_50 = V_13 -> V_135 ;
V_15 -> V_51 = V_13 -> V_135 ;
V_15 -> V_52 = V_13 -> V_135 ;
V_124 = - 1 ;
}
#endif
if ( V_124 >= 0 ) {
V_121 = true ;
F_31 ( V_13 , V_15 , & V_89 [ 0 ] , V_124 ,
true , false ) ;
V_88 -> V_8 |= V_103 ;
} else {
F_31 ( V_13 , V_15 , & V_89 [ 0 ] , V_15 -> V_50 ,
false , false ) ;
}
if ( V_13 -> V_133 -> V_134 >= 3 ) {
if ( V_124 >= 0 )
F_31 ( V_13 , V_15 , & V_89 [ 1 ] , V_15 -> V_50 ,
false , false ) ;
else
F_31 ( V_13 , V_15 , & V_89 [ 1 ] , V_15 -> V_51 ,
false , true ) ;
F_31 ( V_13 , V_15 , & V_89 [ 2 ] , V_15 -> V_52 ,
false , ! V_121 ) ;
V_89 [ 3 ] . V_57 = 0 ;
V_89 [ 3 ] . V_6 = - 1 ;
} else if ( V_13 -> V_133 -> V_134 == 2 ) {
F_31 ( V_13 , V_15 , & V_89 [ 1 ] , V_15 -> V_52 ,
false , ! V_121 ) ;
V_89 [ 2 ] . V_57 = 0 ;
V_89 [ 2 ] . V_6 = - 1 ;
} else {
V_89 [ 1 ] . V_57 = 0 ;
V_89 [ 1 ] . V_6 = - 1 ;
}
V_15 -> V_136 ++ ;
if ( V_15 -> V_136 == ~ 0 ) {
V_15 -> V_136 = 0 ;
V_15 -> V_104 = 0 ;
}
}
static void
F_38 ( struct V_12 * V_13 , struct V_14 * V_15 ,
struct V_81 * V_82 ,
struct V_63 * V_71 )
{
int V_45 ;
if ( V_82 -> V_137 != V_138 )
return;
V_15 -> V_139 = 0 ;
V_15 -> V_127 = 0 ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
if ( ! F_39 ( V_71 , V_82 -> V_137 , V_13 -> V_19 [ V_45 ] ) )
continue;
V_15 -> V_139 |= F_6 ( V_45 ) ;
if ( V_82 -> V_140 [ V_45 ] . V_8 & V_141 )
V_15 -> V_127 |= F_6 ( V_45 ) ;
}
V_15 -> V_20 [ V_18 ] . V_21 = V_15 -> V_139 ;
}
static void
F_40 ( void * V_80 , struct V_81 * V_82 ,
struct V_63 * V_71 , void * V_83 )
{
struct V_12 * V_13 = V_80 ;
struct V_84 * V_85 = V_83 ;
struct V_14 * V_15 = & V_85 -> V_86 ;
struct V_142 * V_143 = & V_71 -> V_144 . V_143 ;
T_1 V_145 = V_71 -> V_144 . V_146 ;
int V_147 = 0 ;
int V_148 ;
int V_149 ;
int V_45 ;
if ( ! V_71 -> V_144 . V_150 )
goto V_151;
F_41 ( F_5 ( V_39 ) !=
V_152 * V_153 + 1 ) ;
V_85 -> V_93 = true ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_55 = V_56 ;
V_148 = F_42 ( V_82 -> V_137 , 10 , 60 , 1 , 1 ) ;
V_15 -> V_37 = F_42 ( V_82 -> V_137 , 0 , 60 , 1 , 1 ) + V_148 ;
V_15 -> V_115 = V_15 -> V_37 + 2 * V_148 ;
V_15 -> V_38 = F_10 ( 1 , 1 ) ;
if ( V_13 -> V_125 ) {
V_15 -> V_49 = 16 ;
V_15 -> V_101 = 0 ;
} else {
V_15 -> V_49 = 8 ;
V_15 -> V_101 = 8 ;
}
V_15 -> V_102 = 4 ;
V_149 = ( V_145 & V_154 ) >>
V_155 ;
V_15 -> V_131 |= V_149 << V_156 ;
if ( V_145 & V_157 )
V_15 -> V_131 |= V_158 ;
for ( V_45 = 0 ; V_45 < F_5 ( V_15 -> V_20 ) ; V_45 ++ ) {
V_15 -> V_20 [ V_45 ] . V_21 = 0 ;
if ( V_45 == V_18 ) {
F_38 ( V_13 , V_15 , V_82 , V_71 ) ;
continue;
}
if ( V_39 [ V_45 ] . V_8 & V_9 ) {
if ( V_39 [ V_45 ] . V_8 & V_10 ) {
if ( ! ( V_145 & V_159 ) )
continue;
} else {
if ( ! ( V_145 & V_160 ) )
continue;
}
}
if ( V_39 [ V_45 ] . V_8 & V_10 &&
V_71 -> V_161 < V_162 )
continue;
if ( V_71 -> V_163 == V_164 &&
V_39 [ V_45 ] . V_54 > 1 )
continue;
V_15 -> V_20 [ V_45 ] . V_21 =
V_143 -> V_165 [ V_39 [ V_45 ] . V_54 - 1 ] ;
if ( V_15 -> V_20 [ V_45 ] . V_21 )
V_147 ++ ;
}
if ( ! V_147 )
goto V_151;
return;
V_151:
V_85 -> V_93 = false ;
memset ( & V_85 -> V_96 , 0 , sizeof( V_85 -> V_96 ) ) ;
V_85 -> V_96 . V_166 = V_85 -> V_167 ;
V_85 -> V_96 . V_60 = V_85 -> V_60 ;
return V_94 . V_168 ( V_80 , V_82 , V_71 , & V_85 -> V_96 ) ;
}
static void
F_43 ( void * V_80 , struct V_81 * V_82 ,
struct V_63 * V_71 , void * V_83 )
{
F_40 ( V_80 , V_82 , V_71 , V_83 ) ;
}
static void
F_44 ( void * V_80 , struct V_81 * V_82 ,
struct V_63 * V_71 , void * V_83 ,
T_3 V_169 )
{
F_40 ( V_80 , V_82 , V_71 , V_83 ) ;
}
static void *
F_45 ( void * V_80 , struct V_63 * V_71 , T_4 V_170 )
{
struct V_81 * V_82 ;
struct V_84 * V_85 ;
struct V_12 * V_13 = V_80 ;
struct V_171 * V_133 = V_13 -> V_133 ;
int V_134 = 0 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_172 ; V_45 ++ ) {
V_82 = V_133 -> V_173 -> V_174 [ V_45 ] ;
if ( V_82 && V_82 -> V_175 > V_134 )
V_134 = V_82 -> V_175 ;
}
V_85 = F_46 ( sizeof( * V_85 ) , V_170 ) ;
if ( ! V_85 )
return NULL ;
V_85 -> V_167 = F_46 ( sizeof( struct V_176 ) * V_134 , V_170 ) ;
if ( ! V_85 -> V_167 )
goto error;
V_85 -> V_60 = F_47 ( V_177 * V_134 , V_170 ) ;
if ( ! V_85 -> V_60 )
goto V_178;
return V_85 ;
V_178:
F_48 ( V_85 -> V_167 ) ;
error:
F_48 ( V_85 ) ;
return NULL ;
}
static void
F_49 ( void * V_80 , struct V_63 * V_71 , void * V_83 )
{
struct V_84 * V_85 = V_83 ;
F_48 ( V_85 -> V_60 ) ;
F_48 ( V_85 -> V_167 ) ;
F_48 ( V_85 ) ;
}
static void *
F_50 ( struct V_171 * V_133 , struct V_179 * V_180 )
{
return V_94 . V_181 ( V_133 , V_180 ) ;
}
static void
F_51 ( void * V_80 )
{
V_94 . free ( V_80 ) ;
}
static void
F_52 ( void )
{
int V_182 , V_45 , V_183 ;
T_2 V_184 [ V_7 ] ;
memset ( V_60 , 0xff , sizeof( V_60 ) ) ;
for ( V_182 = 0 ; V_182 < V_177 ; V_182 ++ ) {
for ( V_45 = 0 ; V_45 < V_7 ; V_45 ++ ) {
F_53 ( V_184 , sizeof( V_184 ) ) ;
V_183 = ( V_45 + V_184 [ V_45 ] ) % V_7 ;
while ( V_60 [ V_182 ] [ V_183 ] != 0xff )
V_183 = ( V_183 + 1 ) % V_7 ;
V_60 [ V_182 ] [ V_183 ] = V_45 ;
}
}
}
int T_5
F_54 ( void )
{
F_52 () ;
return F_55 ( & V_185 ) ;
}
void
F_56 ( void )
{
F_57 ( & V_185 ) ;
}
