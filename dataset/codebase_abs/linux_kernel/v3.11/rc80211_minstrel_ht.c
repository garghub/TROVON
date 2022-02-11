static int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( ( V_2 -> V_3 / V_4 ) + 1 ,
! ! ( V_2 -> V_5 & V_6 ) ,
! ! ( V_2 -> V_5 & V_7 ) ) ;
}
static struct V_8 *
F_3 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_1 * V_2 )
{
int V_13 , V_3 ;
if ( V_2 -> V_5 & V_14 ) {
V_13 = F_1 ( V_2 ) ;
V_3 = V_2 -> V_3 % V_4 ;
} else {
V_13 = V_15 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_10 -> V_16 ) ; V_3 ++ )
if ( V_2 -> V_3 == V_10 -> V_16 [ V_3 ] )
break;
if ( ! ( V_12 -> V_17 [ V_13 ] . V_18 & F_5 ( V_3 ) ) )
V_3 += 4 ;
}
return & V_12 -> V_17 [ V_13 ] . V_19 [ V_3 ] ;
}
static inline struct V_8 *
F_6 ( struct V_11 * V_12 , int V_20 )
{
return & V_12 -> V_17 [ V_20 / V_4 ] . V_19 [ V_20 % V_4 ] ;
}
static void
F_7 ( struct V_8 * V_21 )
{
if ( F_8 ( V_21 -> V_22 > 0 ) ) {
V_21 -> V_23 = 0 ;
V_21 -> V_24 = F_9 ( V_21 -> V_25 , V_21 -> V_22 ) ;
if ( ! V_21 -> V_26 )
V_21 -> V_27 = V_21 -> V_24 ;
else
V_21 -> V_27 = F_10 ( V_21 -> V_27 ,
V_21 -> V_24 , V_28 ) ;
V_21 -> V_26 += V_21 -> V_22 ;
V_21 -> V_29 += V_21 -> V_25 ;
} else {
V_21 -> V_23 ++ ;
}
V_21 -> V_30 = V_21 -> V_25 ;
V_21 -> V_31 = V_21 -> V_22 ;
V_21 -> V_25 = 0 ;
V_21 -> V_22 = 0 ;
}
static void
F_11 ( struct V_11 * V_12 , int V_13 , int V_2 )
{
struct V_8 * V_21 ;
unsigned int V_32 = 0 ;
unsigned int V_33 ;
unsigned int V_34 ;
V_21 = & V_12 -> V_17 [ V_13 ] . V_19 [ V_2 ] ;
V_34 = V_21 -> V_27 ;
if ( V_34 < F_9 ( 1 , 10 ) ) {
V_21 -> V_35 = 0 ;
return;
}
if ( V_34 > F_9 ( 9 , 10 ) )
V_34 = F_9 ( 9 , 10 ) ;
if ( V_13 != V_15 )
V_32 = 1000 * V_12 -> V_36 / F_12 ( V_12 -> V_37 ) ;
V_32 += V_38 [ V_13 ] . V_39 [ V_2 ] ;
V_33 = 1000000 * ( ( V_21 -> V_27 * 1000 ) / V_32 ) ;
V_21 -> V_35 = F_12 ( V_33 ) ;
}
static void
F_13 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_40 * V_41 ;
struct V_8 * V_21 ;
int V_24 , V_42 , V_35 , V_43 ;
int V_13 , V_44 , V_20 ;
bool V_45 = false ;
if ( V_12 -> V_46 > 0 ) {
V_12 -> V_37 = F_10 ( V_12 -> V_37 ,
F_9 ( V_12 -> V_47 , V_12 -> V_46 ) , V_28 ) ;
V_12 -> V_47 = 0 ;
V_12 -> V_46 = 0 ;
}
V_12 -> V_48 = 0 ;
V_12 -> V_49 = 0 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_38 ) ; V_13 ++ ) {
bool V_50 = false ;
V_24 = 0 ;
V_42 = 0 ;
V_35 = 0 ;
V_43 = 0 ;
V_41 = & V_12 -> V_17 [ V_13 ] ;
if ( ! V_41 -> V_18 )
continue;
V_12 -> V_49 ++ ;
for ( V_44 = 0 ; V_44 < V_4 ; V_44 ++ ) {
if ( ! ( V_41 -> V_18 & F_5 ( V_44 ) ) )
continue;
if ( ! V_50 ) {
V_41 -> V_51 = V_41 -> V_52 =
V_41 -> V_53 = V_44 ;
if ( ! V_45 ) {
V_12 -> V_51 = V_12 -> V_52 =
V_12 -> V_53 = V_44 ;
V_45 = true ;
}
V_50 = true ;
}
V_21 = & V_41 -> V_19 [ V_44 ] ;
V_21 -> V_54 = false ;
V_20 = V_4 * V_13 + V_44 ;
F_7 ( V_21 ) ;
F_11 ( V_12 , V_13 , V_44 ) ;
if ( ! V_21 -> V_35 )
continue;
if ( ( V_21 -> V_35 > V_42 && V_21 -> V_27 >
F_9 ( 3 , 4 ) ) || V_21 -> V_27 > V_24 ) {
V_41 -> V_53 = V_20 ;
V_24 = V_21 -> V_27 ;
V_42 = V_21 -> V_35 ;
}
if ( V_21 -> V_35 > V_35 ) {
F_14 ( V_20 , V_41 -> V_51 ) ;
V_35 = V_21 -> V_35 ;
V_21 = F_6 ( V_12 , V_20 ) ;
}
if ( V_20 >= V_41 -> V_51 )
continue;
if ( V_21 -> V_35 > V_43 ) {
V_41 -> V_52 = V_20 ;
V_43 = V_21 -> V_35 ;
}
}
}
V_12 -> V_49 *= 8 ;
V_24 = 0 ;
V_42 = 0 ;
V_35 = 0 ;
V_43 = 0 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_38 ) ; V_13 ++ ) {
V_41 = & V_12 -> V_17 [ V_13 ] ;
if ( ! V_41 -> V_18 )
continue;
V_21 = F_6 ( V_12 , V_41 -> V_51 ) ;
if ( V_35 < V_21 -> V_35 ) {
V_12 -> V_52 = V_12 -> V_51 ;
V_43 = V_35 ;
V_12 -> V_51 = V_41 -> V_51 ;
V_35 = V_21 -> V_35 ;
V_12 -> V_55 = V_38 [ V_13 ] . V_56 - 1 ;
}
V_21 = F_6 ( V_12 , V_41 -> V_52 ) ;
if ( V_43 < V_21 -> V_35 ) {
V_12 -> V_52 = V_41 -> V_52 ;
V_43 = V_21 -> V_35 ;
}
}
if ( V_12 -> V_55 < 1 )
V_12 -> V_55 = 1 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_38 ) ; V_13 ++ ) {
V_41 = & V_12 -> V_17 [ V_13 ] ;
if ( ! V_41 -> V_18 )
continue;
V_21 = F_6 ( V_12 , V_41 -> V_53 ) ;
if ( V_42 < V_21 -> V_35 &&
V_38 [ V_13 ] . V_56 <= V_12 -> V_55 ) {
V_12 -> V_53 = V_41 -> V_53 ;
V_24 = V_21 -> V_24 ;
V_42 = V_21 -> V_35 ;
}
}
V_12 -> V_57 = V_58 ;
}
static bool
F_15 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
if ( V_2 -> V_3 < 0 )
return false ;
if ( ! V_2 -> V_59 )
return false ;
if ( V_2 -> V_5 & V_14 )
return true ;
return V_2 -> V_3 == V_10 -> V_16 [ 0 ] ||
V_2 -> V_3 == V_10 -> V_16 [ 1 ] ||
V_2 -> V_3 == V_10 -> V_16 [ 2 ] ||
V_2 -> V_3 == V_10 -> V_16 [ 3 ] ;
}
static void
F_16 ( struct V_11 * V_12 )
{
struct V_40 * V_41 ;
for (; ; ) {
V_12 -> V_60 ++ ;
V_12 -> V_60 %= F_4 ( V_38 ) ;
V_41 = & V_12 -> V_17 [ V_12 -> V_60 ] ;
if ( ! V_41 -> V_18 )
continue;
if ( ++ V_41 -> V_20 >= V_4 ) {
V_41 -> V_20 = 0 ;
if ( ++ V_41 -> V_61 >= F_4 ( V_62 ) )
V_41 -> V_61 = 0 ;
}
break;
}
}
static void
F_17 ( struct V_11 * V_12 , unsigned int * V_3 ,
bool V_63 )
{
int V_13 , V_64 ;
V_64 = V_13 = * V_3 / V_4 ;
while ( V_13 > 0 ) {
V_13 -- ;
if ( ! V_12 -> V_17 [ V_13 ] . V_18 )
continue;
if ( V_38 [ V_13 ] . V_56 >
V_38 [ V_64 ] . V_56 )
continue;
if ( V_63 )
* V_3 = V_12 -> V_17 [ V_13 ] . V_51 ;
else
* V_3 = V_12 -> V_17 [ V_13 ] . V_52 ;
break;
}
}
static void
F_18 ( struct V_65 * V_66 , struct V_67 * V_68 )
{
struct V_69 * V_70 = (struct V_69 * ) V_68 -> V_71 ;
struct V_72 * V_73 = F_19 ( V_66 , struct V_72 , V_73 ) ;
T_1 V_74 ;
if ( F_8 ( ! F_20 ( V_70 -> V_75 ) ) )
return;
if ( F_8 ( V_68 -> V_76 == F_21 ( V_77 ) ) )
return;
V_74 = * F_22 ( V_70 ) & V_78 ;
if ( F_23 ( V_73 -> V_79 . V_80 [ V_74 ] ) )
return;
if ( F_24 ( V_68 ) == V_81 )
return;
F_25 ( V_66 , V_74 , 5000 ) ;
}
static void
F_26 ( void * V_82 , struct V_83 * V_84 ,
struct V_65 * V_73 , void * V_85 ,
struct V_67 * V_68 )
{
struct V_86 * V_87 = V_85 ;
struct V_11 * V_12 = & V_87 -> V_88 ;
struct V_89 * V_90 = F_27 ( V_68 ) ;
struct V_1 * V_91 = V_90 -> V_92 . V_19 ;
struct V_8 * V_2 , * V_93 ;
struct V_9 * V_10 = V_82 ;
bool V_94 , V_95 = false ;
int V_44 ;
if ( ! V_87 -> V_96 )
return V_97 . V_98 ( V_82 , V_84 , V_73 , & V_87 -> V_99 , V_68 ) ;
if ( ( V_90 -> V_5 & V_100 ) &&
! ( V_90 -> V_5 & V_101 ) )
return;
if ( ! ( V_90 -> V_5 & V_101 ) ) {
V_90 -> V_92 . V_102 =
( V_90 -> V_5 & V_103 ? 1 : 0 ) ;
V_90 -> V_92 . V_47 = 1 ;
}
V_12 -> V_46 ++ ;
V_12 -> V_47 += V_90 -> V_92 . V_47 ;
if ( ! V_12 -> V_104 && ! V_12 -> V_105 && V_12 -> V_49 > 0 ) {
V_12 -> V_104 = 16 + 2 * F_12 ( V_12 -> V_37 ) ;
V_12 -> V_105 = 1 ;
V_12 -> V_49 -- ;
}
if ( V_90 -> V_5 & V_106 )
V_12 -> V_107 += V_90 -> V_92 . V_47 ;
V_94 = ! F_15 ( V_10 , & V_91 [ 0 ] ) ;
for ( V_44 = 0 ; ! V_94 ; V_44 ++ ) {
V_94 = ( V_44 == V_108 - 1 ) ||
! F_15 ( V_10 , & V_91 [ V_44 + 1 ] ) ;
V_2 = F_3 ( V_10 , V_12 , & V_91 [ V_44 ] ) ;
if ( V_94 )
V_2 -> V_25 += V_90 -> V_92 . V_102 ;
V_2 -> V_22 += V_91 [ V_44 ] . V_59 * V_90 -> V_92 . V_47 ;
}
V_2 = F_6 ( V_12 , V_12 -> V_51 ) ;
if ( V_2 -> V_22 > 30 &&
F_9 ( V_2 -> V_25 , V_2 -> V_22 ) <
F_9 ( 20 , 100 ) ) {
F_17 ( V_12 , & V_12 -> V_51 , true ) ;
V_95 = true ;
}
V_93 = F_6 ( V_12 , V_12 -> V_52 ) ;
if ( V_93 -> V_22 > 30 &&
F_9 ( V_93 -> V_25 , V_93 -> V_22 ) <
F_9 ( 20 , 100 ) ) {
F_17 ( V_12 , & V_12 -> V_52 , false ) ;
V_95 = true ;
}
if ( F_28 ( V_58 , V_12 -> V_57 + ( V_10 -> V_109 / 2 * V_110 ) / 1000 ) ) {
V_95 = true ;
F_13 ( V_10 , V_12 ) ;
if ( ! ( V_90 -> V_5 & V_100 ) &&
V_12 -> V_53 / V_4 != V_15 )
F_18 ( V_73 , V_68 ) ;
}
if ( V_95 )
F_29 ( V_10 , V_12 ) ;
}
static void
F_30 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_20 )
{
struct V_8 * V_21 ;
const struct V_111 * V_13 ;
unsigned int V_112 , V_113 , V_114 ;
unsigned int V_115 = V_10 -> V_116 ;
unsigned int ctime = 0 ;
unsigned int V_117 = 9 ;
unsigned int V_47 = F_12 ( V_12 -> V_37 ) ;
unsigned int V_36 = 0 , V_118 = 0 ;
V_21 = F_6 ( V_12 , V_20 ) ;
if ( V_21 -> V_27 < F_9 ( 1 , 10 ) ) {
V_21 -> V_119 = 1 ;
V_21 -> V_120 = 1 ;
return;
}
V_21 -> V_119 = 2 ;
V_21 -> V_120 = 2 ;
V_21 -> V_54 = true ;
V_13 = & V_38 [ V_20 / V_4 ] ;
V_114 = V_13 -> V_39 [ V_20 % V_4 ] * V_47 / 1000 ;
ctime = ( V_117 * V_115 ) >> 1 ;
V_115 = F_31 ( ( V_115 << 1 ) | 1 , V_10 -> V_121 ) ;
ctime += ( V_117 * V_115 ) >> 1 ;
V_115 = F_31 ( ( V_115 << 1 ) | 1 , V_10 -> V_121 ) ;
if ( V_20 / V_4 != V_15 ) {
V_36 = V_12 -> V_36 ;
V_118 = V_12 -> V_118 ;
}
V_112 = ctime + 2 * ( V_36 + V_114 ) ;
V_113 = ctime + 2 * ( V_118 + V_114 ) ;
do {
ctime = ( V_117 * V_115 ) >> 1 ;
V_115 = F_31 ( ( V_115 << 1 ) | 1 , V_10 -> V_121 ) ;
V_112 += ctime + V_36 + V_114 ;
V_113 += ctime + V_118 + V_114 ;
if ( V_113 < V_10 -> V_122 )
V_21 -> V_120 ++ ;
} while ( ( V_112 < V_10 -> V_122 ) &&
( ++ V_21 -> V_119 < V_10 -> V_123 ) );
}
static void
F_32 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_124 * V_125 , int V_126 , int V_20 )
{
const struct V_111 * V_13 = & V_38 [ V_20 / V_4 ] ;
struct V_8 * V_21 ;
T_2 V_3 ;
T_1 V_5 ;
V_21 = F_6 ( V_12 , V_20 ) ;
if ( ! V_21 -> V_54 )
F_30 ( V_10 , V_12 , V_20 ) ;
if ( V_21 -> V_27 < F_9 ( 20 , 100 ) || ! V_21 -> V_119 ) {
V_125 -> V_2 [ V_126 ] . V_59 = 2 ;
V_125 -> V_2 [ V_126 ] . V_127 = 2 ;
V_125 -> V_2 [ V_126 ] . V_128 = 2 ;
} else {
V_125 -> V_2 [ V_126 ] . V_59 = V_21 -> V_119 ;
V_125 -> V_2 [ V_126 ] . V_128 = V_21 -> V_119 ;
V_125 -> V_2 [ V_126 ] . V_127 = V_21 -> V_120 ;
}
if ( V_20 / V_4 == V_15 ) {
V_3 = V_10 -> V_16 [ V_20 % F_4 ( V_10 -> V_16 ) ] ;
V_5 = 0 ;
} else {
V_3 = V_20 % V_4 +
( V_13 -> V_56 - 1 ) * V_4 ;
V_5 = V_14 | V_13 -> V_5 ;
}
if ( V_126 > 0 ) {
V_125 -> V_2 [ V_126 ] . V_59 = V_125 -> V_2 [ V_126 ] . V_127 ;
V_5 |= V_129 ;
}
V_125 -> V_2 [ V_126 ] . V_3 = V_3 ;
V_125 -> V_2 [ V_126 ] . V_5 = V_5 ;
}
static void
F_29 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_124 * V_19 ;
int V_44 = 0 ;
V_19 = F_33 ( sizeof( * V_19 ) , V_130 ) ;
if ( ! V_19 )
return;
F_32 ( V_10 , V_12 , V_19 , V_44 ++ , V_12 -> V_51 ) ;
if ( V_10 -> V_131 -> V_132 >= 3 ) {
F_32 ( V_10 , V_12 , V_19 , V_44 ++ , V_12 -> V_52 ) ;
}
if ( V_10 -> V_131 -> V_132 >= 2 ) {
F_32 ( V_10 , V_12 , V_19 , V_44 ++ , V_12 -> V_53 ) ;
}
V_19 -> V_2 [ V_44 ] . V_3 = - 1 ;
F_34 ( V_10 -> V_131 , V_12 -> V_73 , V_19 ) ;
}
static inline int
F_35 ( int V_20 )
{
const struct V_111 * V_13 = & V_38 [ V_20 / V_4 ] ;
return V_13 -> V_39 [ V_20 % V_4 ] ;
}
static int
F_36 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_8 * V_21 ;
struct V_40 * V_41 ;
unsigned int V_133 , V_60 ;
int V_134 = 0 ;
if ( V_12 -> V_104 > 0 ) {
V_12 -> V_104 -- ;
return - 1 ;
}
if ( ! V_12 -> V_105 )
return - 1 ;
V_41 = & V_12 -> V_17 [ V_12 -> V_60 ] ;
V_134 = V_62 [ V_41 -> V_61 ] [ V_41 -> V_20 ] ;
V_21 = & V_41 -> V_19 [ V_134 ] ;
V_60 = V_12 -> V_60 ;
V_134 += V_60 * V_4 ;
F_16 ( V_12 ) ;
if ( V_134 == V_12 -> V_51 ||
V_134 == V_12 -> V_52 ||
V_134 == V_12 -> V_53 )
return - 1 ;
if ( V_21 -> V_27 > F_9 ( 95 , 100 ) )
return - 1 ;
V_133 = F_35 ( V_134 ) ;
if ( V_133 >= F_35 ( V_12 -> V_52 ) &&
( V_12 -> V_55 <
V_38 [ V_60 ] . V_56 ||
V_133 >= F_35 ( V_12 -> V_53 ) ) ) {
if ( V_21 -> V_23 < 20 )
return - 1 ;
if ( V_12 -> V_48 ++ > 2 )
return - 1 ;
}
V_12 -> V_105 -- ;
return V_134 ;
}
static void
F_37 ( struct V_9 * V_10 ,
struct V_11 * V_12 , bool V_135 )
{
T_2 V_18 = V_12 -> V_17 [ V_15 ] . V_18 ;
if ( ! V_18 || ! V_12 -> V_136 )
return;
if ( V_18 & ( V_12 -> V_136 << ( V_135 * 4 ) ) )
return;
V_18 ^= V_12 -> V_136 | ( V_12 -> V_136 << 4 ) ;
V_12 -> V_17 [ V_15 ] . V_18 = V_18 ;
}
static void
F_38 ( void * V_82 , struct V_65 * V_73 , void * V_85 ,
struct V_137 * V_138 )
{
const struct V_111 * V_60 ;
struct V_89 * V_90 = F_27 ( V_138 -> V_68 ) ;
struct V_1 * V_2 = & V_90 -> V_92 . V_19 [ 0 ] ;
struct V_86 * V_87 = V_85 ;
struct V_11 * V_12 = & V_87 -> V_88 ;
struct V_9 * V_10 = V_82 ;
int V_134 ;
if ( F_39 ( V_73 , V_85 , V_138 ) )
return;
if ( ! V_87 -> V_96 )
return V_97 . V_139 ( V_82 , V_73 , & V_87 -> V_99 , V_138 ) ;
V_90 -> V_5 |= V_12 -> V_140 ;
F_37 ( V_10 , V_12 , V_138 -> V_141 ) ;
if ( V_10 -> V_131 -> V_132 == 1 &&
V_138 -> V_68 -> V_76 == F_21 ( V_77 ) )
V_134 = - 1 ;
else
V_134 = F_36 ( V_10 , V_12 ) ;
#ifdef F_40
if ( V_10 -> V_142 != - 1 ) {
V_12 -> V_51 = V_10 -> V_142 ;
V_12 -> V_52 = V_10 -> V_142 ;
V_12 -> V_53 = V_10 -> V_142 ;
V_134 = - 1 ;
}
#endif
V_12 -> V_143 ++ ;
if ( V_12 -> V_143 == ~ 0 ) {
V_12 -> V_143 = 0 ;
V_12 -> V_107 = 0 ;
}
if ( V_134 < 0 )
return;
V_60 = & V_38 [ V_134 / V_4 ] ;
V_90 -> V_5 |= V_106 ;
V_2 -> V_59 = 1 ;
if ( V_134 / V_4 == V_15 ) {
int V_3 = V_134 % F_4 ( V_10 -> V_16 ) ;
V_2 -> V_3 = V_10 -> V_16 [ V_3 ] ;
V_2 -> V_5 = 0 ;
return;
}
V_2 -> V_3 = V_134 % V_4 +
( V_60 -> V_56 - 1 ) * V_4 ;
V_2 -> V_5 = V_14 | V_60 -> V_5 ;
}
static void
F_41 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_83 * V_84 ,
struct V_65 * V_73 )
{
int V_44 ;
if ( V_84 -> V_144 != V_145 )
return;
if ( ! ( V_10 -> V_131 -> V_5 & V_146 ) )
return;
V_12 -> V_147 = 0 ;
V_12 -> V_136 = 0 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
if ( ! F_42 ( V_73 , V_84 -> V_144 , V_10 -> V_16 [ V_44 ] ) )
continue;
V_12 -> V_147 |= F_5 ( V_44 ) ;
if ( V_84 -> V_148 [ V_44 ] . V_5 & V_149 )
V_12 -> V_136 |= F_5 ( V_44 ) ;
}
V_12 -> V_17 [ V_15 ] . V_18 = V_12 -> V_147 ;
}
static void
F_43 ( void * V_82 , struct V_83 * V_84 ,
struct V_65 * V_73 , void * V_85 )
{
struct V_9 * V_10 = V_82 ;
struct V_86 * V_87 = V_85 ;
struct V_11 * V_12 = & V_87 -> V_88 ;
struct V_150 * V_151 = & V_73 -> V_152 . V_151 ;
T_1 V_153 = V_73 -> V_152 . V_154 ;
int V_155 = 0 ;
int V_156 ;
int V_157 ;
int V_44 ;
if ( ! V_73 -> V_152 . V_158 )
goto V_159;
F_44 ( F_4 ( V_38 ) !=
V_160 * V_161 + 1 ) ;
V_87 -> V_96 = true ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_73 = V_73 ;
V_12 -> V_57 = V_58 ;
V_156 = F_45 ( V_84 -> V_144 , 10 , 60 , 1 , 1 ) ;
V_12 -> V_36 = F_45 ( V_84 -> V_144 , 0 , 60 , 1 , 1 ) + V_156 ;
V_12 -> V_118 = V_12 -> V_36 + 2 * V_156 ;
V_12 -> V_37 = F_9 ( 1 , 1 ) ;
if ( V_10 -> V_162 ) {
V_12 -> V_49 = 16 ;
V_12 -> V_104 = 0 ;
} else {
V_12 -> V_49 = 8 ;
V_12 -> V_104 = 8 ;
}
V_12 -> V_105 = 4 ;
V_157 = ( V_153 & V_163 ) >>
V_164 ;
V_12 -> V_140 |= V_157 << V_165 ;
if ( V_153 & V_166 )
V_12 -> V_140 |= V_167 ;
for ( V_44 = 0 ; V_44 < F_4 ( V_12 -> V_17 ) ; V_44 ++ ) {
V_12 -> V_17 [ V_44 ] . V_18 = 0 ;
if ( V_44 == V_15 ) {
F_41 ( V_10 , V_12 , V_84 , V_73 ) ;
continue;
}
if ( V_38 [ V_44 ] . V_5 & V_6 ) {
if ( V_38 [ V_44 ] . V_5 & V_7 ) {
if ( ! ( V_153 & V_168 ) )
continue;
} else {
if ( ! ( V_153 & V_169 ) )
continue;
}
}
if ( V_38 [ V_44 ] . V_5 & V_7 &&
V_73 -> V_170 < V_171 )
continue;
if ( V_73 -> V_172 == V_173 &&
V_38 [ V_44 ] . V_56 > 1 )
continue;
V_12 -> V_17 [ V_44 ] . V_18 =
V_151 -> V_174 [ V_38 [ V_44 ] . V_56 - 1 ] ;
if ( V_12 -> V_17 [ V_44 ] . V_18 )
V_155 ++ ;
}
if ( ! V_155 )
goto V_159;
F_13 ( V_10 , V_12 ) ;
F_29 ( V_10 , V_12 ) ;
return;
V_159:
V_87 -> V_96 = false ;
memset ( & V_87 -> V_99 , 0 , sizeof( V_87 -> V_99 ) ) ;
V_87 -> V_99 . V_175 = V_87 -> V_176 ;
V_87 -> V_99 . V_62 = V_87 -> V_62 ;
return V_97 . V_177 ( V_82 , V_84 , V_73 , & V_87 -> V_99 ) ;
}
static void
F_46 ( void * V_82 , struct V_83 * V_84 ,
struct V_65 * V_73 , void * V_85 )
{
F_43 ( V_82 , V_84 , V_73 , V_85 ) ;
}
static void
F_47 ( void * V_82 , struct V_83 * V_84 ,
struct V_65 * V_73 , void * V_85 ,
T_3 V_178 )
{
F_43 ( V_82 , V_84 , V_73 , V_85 ) ;
}
static void *
F_48 ( void * V_82 , struct V_65 * V_73 , T_4 V_179 )
{
struct V_83 * V_84 ;
struct V_86 * V_87 ;
struct V_9 * V_10 = V_82 ;
struct V_180 * V_131 = V_10 -> V_131 ;
int V_132 = 0 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_181 ; V_44 ++ ) {
V_84 = V_131 -> V_182 -> V_183 [ V_44 ] ;
if ( V_84 && V_84 -> V_184 > V_132 )
V_132 = V_84 -> V_184 ;
}
V_87 = F_33 ( sizeof( * V_87 ) , V_179 ) ;
if ( ! V_87 )
return NULL ;
V_87 -> V_176 = F_33 ( sizeof( struct V_185 ) * V_132 , V_179 ) ;
if ( ! V_87 -> V_176 )
goto error;
V_87 -> V_62 = F_49 ( V_186 * V_132 , V_179 ) ;
if ( ! V_87 -> V_62 )
goto V_187;
return V_87 ;
V_187:
F_50 ( V_87 -> V_176 ) ;
error:
F_50 ( V_87 ) ;
return NULL ;
}
static void
F_51 ( void * V_82 , struct V_65 * V_73 , void * V_85 )
{
struct V_86 * V_87 = V_85 ;
F_50 ( V_87 -> V_62 ) ;
F_50 ( V_87 -> V_176 ) ;
F_50 ( V_87 ) ;
}
static void *
F_52 ( struct V_180 * V_131 , struct V_188 * V_189 )
{
return V_97 . V_190 ( V_131 , V_189 ) ;
}
static void
F_53 ( void * V_82 )
{
V_97 . free ( V_82 ) ;
}
static void
F_54 ( void )
{
int V_191 , V_44 , V_192 ;
T_2 V_193 [ V_4 ] ;
memset ( V_62 , 0xff , sizeof( V_62 ) ) ;
for ( V_191 = 0 ; V_191 < V_186 ; V_191 ++ ) {
for ( V_44 = 0 ; V_44 < V_4 ; V_44 ++ ) {
F_55 ( V_193 , sizeof( V_193 ) ) ;
V_192 = ( V_44 + V_193 [ V_44 ] ) % V_4 ;
while ( V_62 [ V_191 ] [ V_192 ] != 0xff )
V_192 = ( V_192 + 1 ) % V_4 ;
V_62 [ V_191 ] [ V_192 ] = V_44 ;
}
}
}
int T_5
F_56 ( void )
{
F_54 () ;
return F_57 ( & V_194 ) ;
}
void
F_58 ( void )
{
F_59 ( & V_194 ) ;
}
