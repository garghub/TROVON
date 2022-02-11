static int
F_1 ( struct V_1 * V_2 )
{
return F_2 ( ( V_2 -> V_3 / 8 ) + 1 ,
! ! ( V_2 -> V_4 & V_5 ) ,
! ! ( V_2 -> V_4 & V_6 ) ) ;
}
static struct V_7 *
F_3 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_2 )
{
int V_12 , V_3 ;
if ( V_2 -> V_4 & V_13 ) {
V_12 = F_1 ( V_2 ) ;
V_3 = V_2 -> V_3 % 8 ;
} else {
V_12 = V_14 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_9 -> V_15 ) ; V_3 ++ )
if ( V_2 -> V_3 == V_9 -> V_15 [ V_3 ] )
break;
if ( ! ( V_11 -> V_16 [ V_12 ] . V_17 & F_5 ( V_3 ) ) )
V_3 += 4 ;
}
return & V_11 -> V_16 [ V_12 ] . V_18 [ V_3 ] ;
}
static inline struct V_7 *
F_6 ( struct V_10 * V_11 , int V_19 )
{
return & V_11 -> V_16 [ V_19 / V_20 ] . V_18 [ V_19 % V_20 ] ;
}
static void
F_7 ( struct V_7 * V_21 )
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
F_11 ( struct V_10 * V_11 , int V_12 , int V_2 )
{
struct V_7 * V_21 ;
unsigned int V_32 = 0 ;
unsigned int V_33 ;
unsigned int V_34 ;
V_21 = & V_11 -> V_16 [ V_12 ] . V_18 [ V_2 ] ;
V_34 = V_21 -> V_27 ;
if ( V_34 < F_9 ( 1 , 10 ) ) {
V_21 -> V_35 = 0 ;
return;
}
if ( V_34 > F_9 ( 9 , 10 ) )
V_34 = F_9 ( 9 , 10 ) ;
if ( V_12 != V_14 )
V_32 = 1000 * V_11 -> V_36 / F_12 ( V_11 -> V_37 ) ;
V_32 += V_38 [ V_12 ] . V_39 [ V_2 ] ;
V_33 = 1000000 * ( ( V_34 * 1000 ) / V_32 ) ;
V_21 -> V_35 = F_12 ( V_33 ) ;
}
static void
F_13 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_40 * V_41 ;
struct V_7 * V_21 ;
int V_24 , V_42 , V_35 , V_43 ;
int V_12 , V_44 , V_19 ;
bool V_45 = false ;
if ( V_11 -> V_46 > 0 ) {
V_11 -> V_37 = F_10 ( V_11 -> V_37 ,
F_9 ( V_11 -> V_47 , V_11 -> V_46 ) , V_28 ) ;
V_11 -> V_47 = 0 ;
V_11 -> V_46 = 0 ;
}
V_11 -> V_48 = 0 ;
V_11 -> V_49 = 0 ;
for ( V_12 = 0 ; V_12 < F_4 ( V_38 ) ; V_12 ++ ) {
bool V_50 = false ;
V_24 = 0 ;
V_42 = 0 ;
V_35 = 0 ;
V_43 = 0 ;
V_41 = & V_11 -> V_16 [ V_12 ] ;
if ( ! V_41 -> V_17 )
continue;
V_11 -> V_49 ++ ;
for ( V_44 = 0 ; V_44 < V_20 ; V_44 ++ ) {
if ( ! ( V_41 -> V_17 & F_5 ( V_44 ) ) )
continue;
V_19 = V_20 * V_12 + V_44 ;
if ( ! V_50 ) {
V_41 -> V_51 = V_41 -> V_52 =
V_41 -> V_53 = V_44 ;
if ( ! V_45 ) {
V_11 -> V_51 = V_11 -> V_52 =
V_11 -> V_53 = V_19 ;
V_45 = true ;
}
V_50 = true ;
}
V_21 = & V_41 -> V_18 [ V_44 ] ;
V_21 -> V_54 = false ;
F_7 ( V_21 ) ;
F_11 ( V_11 , V_12 , V_44 ) ;
if ( ! V_21 -> V_35 )
continue;
if ( ( V_21 -> V_35 > V_42 && V_21 -> V_27 >
F_9 ( 3 , 4 ) ) || V_21 -> V_27 > V_24 ) {
V_41 -> V_53 = V_19 ;
V_24 = V_21 -> V_27 ;
V_42 = V_21 -> V_35 ;
}
if ( V_21 -> V_35 > V_35 ) {
F_14 ( V_19 , V_41 -> V_51 ) ;
V_35 = V_21 -> V_35 ;
V_21 = F_6 ( V_11 , V_19 ) ;
}
if ( V_19 >= V_41 -> V_51 )
continue;
if ( V_21 -> V_35 > V_43 ) {
V_41 -> V_52 = V_19 ;
V_43 = V_21 -> V_35 ;
}
}
}
V_11 -> V_49 *= 8 ;
V_24 = 0 ;
V_42 = 0 ;
V_35 = 0 ;
V_43 = 0 ;
for ( V_12 = 0 ; V_12 < F_4 ( V_38 ) ; V_12 ++ ) {
V_41 = & V_11 -> V_16 [ V_12 ] ;
if ( ! V_41 -> V_17 )
continue;
V_21 = F_6 ( V_11 , V_41 -> V_51 ) ;
if ( V_35 < V_21 -> V_35 ) {
V_11 -> V_52 = V_11 -> V_51 ;
V_43 = V_35 ;
V_11 -> V_51 = V_41 -> V_51 ;
V_35 = V_21 -> V_35 ;
V_11 -> V_55 = V_38 [ V_12 ] . V_56 - 1 ;
}
V_21 = F_6 ( V_11 , V_41 -> V_52 ) ;
if ( V_43 < V_21 -> V_35 ) {
V_11 -> V_52 = V_41 -> V_52 ;
V_43 = V_21 -> V_35 ;
}
}
if ( V_11 -> V_55 < 1 )
V_11 -> V_55 = 1 ;
for ( V_12 = 0 ; V_12 < F_4 ( V_38 ) ; V_12 ++ ) {
V_41 = & V_11 -> V_16 [ V_12 ] ;
if ( ! V_41 -> V_17 )
continue;
V_21 = F_6 ( V_11 , V_41 -> V_53 ) ;
if ( V_42 < V_21 -> V_35 &&
V_38 [ V_12 ] . V_56 <= V_11 -> V_55 ) {
V_11 -> V_53 = V_41 -> V_53 ;
V_24 = V_21 -> V_24 ;
V_42 = V_21 -> V_35 ;
}
}
#ifdef F_15
if ( V_9 -> V_57 != - 1 ) {
V_11 -> V_51 = V_9 -> V_57 ;
V_11 -> V_52 = V_9 -> V_57 ;
V_11 -> V_53 = V_9 -> V_57 ;
}
#endif
V_11 -> V_58 = V_59 ;
}
static bool
F_16 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( V_2 -> V_3 < 0 )
return false ;
if ( ! V_2 -> V_60 )
return false ;
if ( V_2 -> V_4 & V_13 )
return true ;
return V_2 -> V_3 == V_9 -> V_15 [ 0 ] ||
V_2 -> V_3 == V_9 -> V_15 [ 1 ] ||
V_2 -> V_3 == V_9 -> V_15 [ 2 ] ||
V_2 -> V_3 == V_9 -> V_15 [ 3 ] ;
}
static void
F_17 ( struct V_10 * V_11 )
{
struct V_40 * V_41 ;
for (; ; ) {
V_11 -> V_61 ++ ;
V_11 -> V_61 %= F_4 ( V_38 ) ;
V_41 = & V_11 -> V_16 [ V_11 -> V_61 ] ;
if ( ! V_41 -> V_17 )
continue;
if ( ++ V_41 -> V_19 >= V_20 ) {
V_41 -> V_19 = 0 ;
if ( ++ V_41 -> V_62 >= F_4 ( V_63 ) )
V_41 -> V_62 = 0 ;
}
break;
}
}
static void
F_18 ( struct V_10 * V_11 , unsigned int * V_3 ,
bool V_64 )
{
int V_12 , V_65 ;
V_65 = V_12 = * V_3 / V_20 ;
while ( V_12 > 0 ) {
V_12 -- ;
if ( ! V_11 -> V_16 [ V_12 ] . V_17 )
continue;
if ( V_38 [ V_12 ] . V_56 >
V_38 [ V_65 ] . V_56 )
continue;
if ( V_64 )
* V_3 = V_11 -> V_16 [ V_12 ] . V_51 ;
else
* V_3 = V_11 -> V_16 [ V_12 ] . V_52 ;
break;
}
}
static void
F_19 ( struct V_66 * V_67 , struct V_68 * V_69 )
{
struct V_70 * V_71 = (struct V_70 * ) V_69 -> V_72 ;
struct V_73 * V_74 = F_20 ( V_67 , struct V_73 , V_74 ) ;
T_1 V_75 ;
if ( F_8 ( ! F_21 ( V_71 -> V_76 ) ) )
return;
if ( F_8 ( V_69 -> V_77 == F_22 ( V_78 ) ) )
return;
V_75 = * F_23 ( V_71 ) & V_79 ;
if ( F_24 ( V_74 -> V_80 . V_81 [ V_75 ] ) )
return;
if ( F_25 ( V_69 ) == V_82 )
return;
F_26 ( V_67 , V_75 , 5000 ) ;
}
static void
F_27 ( void * V_83 , struct V_84 * V_85 ,
struct V_66 * V_74 , void * V_86 ,
struct V_68 * V_69 )
{
struct V_87 * V_88 = V_86 ;
struct V_10 * V_11 = & V_88 -> V_89 ;
struct V_90 * V_91 = F_28 ( V_69 ) ;
struct V_1 * V_92 = V_91 -> V_93 . V_18 ;
struct V_7 * V_2 , * V_94 ;
struct V_8 * V_9 = V_83 ;
bool V_95 , V_96 = false ;
int V_44 ;
if ( ! V_88 -> V_97 )
return V_98 . V_99 ( V_83 , V_85 , V_74 , & V_88 -> V_100 , V_69 ) ;
if ( ( V_91 -> V_4 & V_101 ) &&
! ( V_91 -> V_4 & V_102 ) )
return;
if ( ! ( V_91 -> V_4 & V_102 ) ) {
V_91 -> V_93 . V_103 =
( V_91 -> V_4 & V_104 ? 1 : 0 ) ;
V_91 -> V_93 . V_47 = 1 ;
}
V_11 -> V_46 ++ ;
V_11 -> V_47 += V_91 -> V_93 . V_47 ;
if ( ! V_11 -> V_105 && ! V_11 -> V_106 && V_11 -> V_49 > 0 ) {
V_11 -> V_105 = 16 + 2 * F_12 ( V_11 -> V_37 ) ;
V_11 -> V_106 = 1 ;
V_11 -> V_49 -- ;
}
if ( V_91 -> V_4 & V_107 )
V_11 -> V_108 += V_91 -> V_93 . V_47 ;
V_95 = ! F_16 ( V_9 , & V_92 [ 0 ] ) ;
for ( V_44 = 0 ; ! V_95 ; V_44 ++ ) {
V_95 = ( V_44 == V_109 - 1 ) ||
! F_16 ( V_9 , & V_92 [ V_44 + 1 ] ) ;
V_2 = F_3 ( V_9 , V_11 , & V_92 [ V_44 ] ) ;
if ( V_95 )
V_2 -> V_25 += V_91 -> V_93 . V_103 ;
V_2 -> V_22 += V_92 [ V_44 ] . V_60 * V_91 -> V_93 . V_47 ;
}
V_2 = F_6 ( V_11 , V_11 -> V_51 ) ;
if ( V_2 -> V_22 > 30 &&
F_9 ( V_2 -> V_25 , V_2 -> V_22 ) <
F_9 ( 20 , 100 ) ) {
F_18 ( V_11 , & V_11 -> V_51 , true ) ;
V_96 = true ;
}
V_94 = F_6 ( V_11 , V_11 -> V_52 ) ;
if ( V_94 -> V_22 > 30 &&
F_9 ( V_94 -> V_25 , V_94 -> V_22 ) <
F_9 ( 20 , 100 ) ) {
F_18 ( V_11 , & V_11 -> V_52 , false ) ;
V_96 = true ;
}
if ( F_29 ( V_59 , V_11 -> V_58 + ( V_9 -> V_110 / 2 * V_111 ) / 1000 ) ) {
V_96 = true ;
F_13 ( V_9 , V_11 ) ;
if ( ! ( V_91 -> V_4 & V_101 ) &&
V_11 -> V_53 / V_20 != V_14 )
F_19 ( V_74 , V_69 ) ;
}
if ( V_96 )
F_30 ( V_9 , V_11 ) ;
}
static void
F_31 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_19 )
{
struct V_7 * V_21 ;
const struct V_112 * V_12 ;
unsigned int V_113 , V_114 , V_115 ;
unsigned int V_116 = V_9 -> V_117 ;
unsigned int ctime = 0 ;
unsigned int V_118 = 9 ;
unsigned int V_47 = F_12 ( V_11 -> V_37 ) ;
unsigned int V_36 = 0 , V_119 = 0 ;
V_21 = F_6 ( V_11 , V_19 ) ;
if ( V_21 -> V_27 < F_9 ( 1 , 10 ) ) {
V_21 -> V_120 = 1 ;
V_21 -> V_121 = 1 ;
return;
}
V_21 -> V_120 = 2 ;
V_21 -> V_121 = 2 ;
V_21 -> V_54 = true ;
V_12 = & V_38 [ V_19 / V_20 ] ;
V_115 = V_12 -> V_39 [ V_19 % V_20 ] * V_47 / 1000 ;
ctime = ( V_118 * V_116 ) >> 1 ;
V_116 = F_32 ( ( V_116 << 1 ) | 1 , V_9 -> V_122 ) ;
ctime += ( V_118 * V_116 ) >> 1 ;
V_116 = F_32 ( ( V_116 << 1 ) | 1 , V_9 -> V_122 ) ;
if ( V_19 / V_20 != V_14 ) {
V_36 = V_11 -> V_36 ;
V_119 = V_11 -> V_119 ;
}
V_113 = ctime + 2 * ( V_36 + V_115 ) ;
V_114 = ctime + 2 * ( V_119 + V_115 ) ;
do {
ctime = ( V_118 * V_116 ) >> 1 ;
V_116 = F_32 ( ( V_116 << 1 ) | 1 , V_9 -> V_122 ) ;
V_113 += ctime + V_36 + V_115 ;
V_114 += ctime + V_119 + V_115 ;
if ( V_114 < V_9 -> V_123 )
V_21 -> V_121 ++ ;
} while ( ( V_113 < V_9 -> V_123 ) &&
( ++ V_21 -> V_120 < V_9 -> V_124 ) );
}
static void
F_33 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_125 * V_126 , int V_127 , int V_19 )
{
const struct V_112 * V_12 = & V_38 [ V_19 / V_20 ] ;
struct V_7 * V_21 ;
T_2 V_3 ;
T_1 V_4 ;
V_21 = F_6 ( V_11 , V_19 ) ;
if ( ! V_21 -> V_54 )
F_31 ( V_9 , V_11 , V_19 ) ;
if ( V_21 -> V_27 < F_9 ( 20 , 100 ) || ! V_21 -> V_120 ) {
V_126 -> V_2 [ V_127 ] . V_60 = 2 ;
V_126 -> V_2 [ V_127 ] . V_128 = 2 ;
V_126 -> V_2 [ V_127 ] . V_129 = 2 ;
} else {
V_126 -> V_2 [ V_127 ] . V_60 = V_21 -> V_120 ;
V_126 -> V_2 [ V_127 ] . V_129 = V_21 -> V_120 ;
V_126 -> V_2 [ V_127 ] . V_128 = V_21 -> V_121 ;
}
if ( V_19 / V_20 == V_14 ) {
V_3 = V_9 -> V_15 [ V_19 % F_4 ( V_9 -> V_15 ) ] ;
V_4 = 0 ;
} else {
V_3 = V_19 % V_20 + ( V_12 -> V_56 - 1 ) * 8 ;
V_4 = V_13 | V_12 -> V_4 ;
}
if ( V_127 > 0 ) {
V_126 -> V_2 [ V_127 ] . V_60 = V_126 -> V_2 [ V_127 ] . V_128 ;
V_4 |= V_130 ;
}
V_126 -> V_2 [ V_127 ] . V_3 = V_3 ;
V_126 -> V_2 [ V_127 ] . V_4 = V_4 ;
}
static void
F_30 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_125 * V_18 ;
int V_44 = 0 ;
V_18 = F_34 ( sizeof( * V_18 ) , V_131 ) ;
if ( ! V_18 )
return;
F_33 ( V_9 , V_11 , V_18 , V_44 ++ , V_11 -> V_51 ) ;
if ( V_9 -> V_132 -> V_133 >= 3 ) {
F_33 ( V_9 , V_11 , V_18 , V_44 ++ , V_11 -> V_52 ) ;
}
if ( V_9 -> V_132 -> V_133 >= 2 ) {
F_33 ( V_9 , V_11 , V_18 , V_44 ++ , V_11 -> V_53 ) ;
}
V_18 -> V_2 [ V_44 ] . V_3 = - 1 ;
F_35 ( V_9 -> V_132 , V_11 -> V_74 , V_18 ) ;
}
static inline int
F_36 ( int V_19 )
{
const struct V_112 * V_12 = & V_38 [ V_19 / V_20 ] ;
return V_12 -> V_39 [ V_19 % V_20 ] ;
}
static int
F_37 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_7 * V_21 ;
struct V_40 * V_41 ;
unsigned int V_134 , V_61 ;
int V_135 = 0 ;
if ( V_11 -> V_105 > 0 ) {
V_11 -> V_105 -- ;
return - 1 ;
}
if ( ! V_11 -> V_106 )
return - 1 ;
V_61 = V_11 -> V_61 ;
V_41 = & V_11 -> V_16 [ V_61 ] ;
V_135 = V_63 [ V_41 -> V_62 ] [ V_41 -> V_19 ] ;
F_17 ( V_11 ) ;
if ( ! ( V_41 -> V_17 & F_5 ( V_135 ) ) )
return - 1 ;
V_21 = & V_41 -> V_18 [ V_135 ] ;
V_135 += V_61 * V_20 ;
if ( V_135 == V_11 -> V_51 ||
V_135 == V_11 -> V_52 ||
V_135 == V_11 -> V_53 )
return - 1 ;
if ( V_21 -> V_27 > F_9 ( 95 , 100 ) )
return - 1 ;
V_134 = F_36 ( V_135 ) ;
if ( V_134 >= F_36 ( V_11 -> V_52 ) &&
( V_11 -> V_55 <
V_38 [ V_61 ] . V_56 ||
V_134 >= F_36 ( V_11 -> V_53 ) ) ) {
if ( V_21 -> V_23 < 20 )
return - 1 ;
if ( V_11 -> V_48 ++ > 2 )
return - 1 ;
}
V_11 -> V_106 -- ;
return V_135 ;
}
static void
F_38 ( struct V_8 * V_9 ,
struct V_10 * V_11 , bool V_136 )
{
T_2 V_17 = V_11 -> V_16 [ V_14 ] . V_17 ;
if ( ! V_17 || ! V_11 -> V_137 )
return;
if ( V_17 & ( V_11 -> V_137 << ( V_136 * 4 ) ) )
return;
V_17 ^= V_11 -> V_137 | ( V_11 -> V_137 << 4 ) ;
V_11 -> V_16 [ V_14 ] . V_17 = V_17 ;
}
static void
F_39 ( void * V_83 , struct V_66 * V_74 , void * V_86 ,
struct V_138 * V_139 )
{
const struct V_112 * V_61 ;
struct V_90 * V_91 = F_28 ( V_139 -> V_69 ) ;
struct V_1 * V_2 = & V_91 -> V_93 . V_18 [ 0 ] ;
struct V_87 * V_88 = V_86 ;
struct V_10 * V_11 = & V_88 -> V_89 ;
struct V_8 * V_9 = V_83 ;
int V_135 ;
if ( F_40 ( V_74 , V_86 , V_139 ) )
return;
if ( ! V_88 -> V_97 )
return V_98 . V_140 ( V_83 , V_74 , & V_88 -> V_100 , V_139 ) ;
V_91 -> V_4 |= V_11 -> V_141 ;
F_38 ( V_9 , V_11 , V_139 -> V_142 ) ;
#ifdef F_15
if ( V_9 -> V_57 != - 1 )
return;
#endif
if ( V_9 -> V_132 -> V_133 == 1 &&
( V_91 -> V_143 . V_4 & V_144 ) )
V_135 = - 1 ;
else
V_135 = F_37 ( V_9 , V_11 ) ;
V_11 -> V_145 ++ ;
if ( V_11 -> V_145 == ~ 0 ) {
V_11 -> V_145 = 0 ;
V_11 -> V_108 = 0 ;
}
if ( V_135 < 0 )
return;
V_61 = & V_38 [ V_135 / V_20 ] ;
V_91 -> V_4 |= V_107 ;
V_2 -> V_60 = 1 ;
if ( V_135 / V_20 == V_14 ) {
int V_3 = V_135 % F_4 ( V_9 -> V_15 ) ;
V_2 -> V_3 = V_9 -> V_15 [ V_3 ] ;
V_2 -> V_4 = 0 ;
return;
}
V_2 -> V_3 = V_135 % V_20 +
( V_61 -> V_56 - 1 ) * 8 ;
V_2 -> V_4 = V_13 | V_61 -> V_4 ;
}
static void
F_41 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_84 * V_85 ,
struct V_66 * V_74 )
{
int V_44 ;
if ( V_85 -> V_146 != V_147 )
return;
if ( ! ( V_9 -> V_132 -> V_4 & V_148 ) )
return;
V_11 -> V_149 = 0 ;
V_11 -> V_137 = 0 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
if ( ! F_42 ( V_74 , V_85 -> V_146 , V_9 -> V_15 [ V_44 ] ) )
continue;
V_11 -> V_149 |= F_5 ( V_44 ) ;
if ( V_85 -> V_150 [ V_44 ] . V_4 & V_151 )
V_11 -> V_137 |= F_5 ( V_44 ) ;
}
V_11 -> V_16 [ V_14 ] . V_17 = V_11 -> V_149 ;
}
static void
F_43 ( void * V_83 , struct V_84 * V_85 ,
struct V_152 * V_153 ,
struct V_66 * V_74 , void * V_86 )
{
struct V_8 * V_9 = V_83 ;
struct V_87 * V_88 = V_86 ;
struct V_10 * V_11 = & V_88 -> V_89 ;
struct V_154 * V_155 = & V_74 -> V_156 . V_155 ;
T_1 V_157 = V_74 -> V_156 . V_158 ;
int V_159 = 0 ;
int V_160 ;
int V_161 ;
int V_44 ;
if ( ! V_74 -> V_156 . V_162 )
goto V_163;
F_44 ( F_4 ( V_38 ) !=
V_164 * V_165 + 1 ) ;
V_88 -> V_97 = true ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_74 = V_74 ;
V_11 -> V_58 = V_59 ;
V_160 = F_45 ( V_85 -> V_146 , 10 , 60 , 1 , 1 , 0 ) ;
V_11 -> V_36 = F_45 ( V_85 -> V_146 , 0 , 60 , 1 , 1 , 0 ) ;
V_11 -> V_36 += V_160 ;
V_11 -> V_119 = V_11 -> V_36 + 2 * V_160 ;
V_11 -> V_37 = F_9 ( 1 , 1 ) ;
if ( V_9 -> V_166 ) {
V_11 -> V_49 = 16 ;
V_11 -> V_105 = 0 ;
} else {
V_11 -> V_49 = 8 ;
V_11 -> V_105 = 8 ;
}
V_11 -> V_106 = 4 ;
V_161 = ( V_157 & V_167 ) >>
V_168 ;
V_11 -> V_141 |= V_161 << V_169 ;
if ( V_157 & V_170 )
V_11 -> V_141 |= V_171 ;
for ( V_44 = 0 ; V_44 < F_4 ( V_11 -> V_16 ) ; V_44 ++ ) {
V_11 -> V_16 [ V_44 ] . V_17 = 0 ;
if ( V_44 == V_14 ) {
F_41 ( V_9 , V_11 , V_85 , V_74 ) ;
continue;
}
if ( V_38 [ V_44 ] . V_4 & V_5 ) {
if ( V_38 [ V_44 ] . V_4 & V_6 ) {
if ( ! ( V_157 & V_172 ) )
continue;
} else {
if ( ! ( V_157 & V_173 ) )
continue;
}
}
if ( V_38 [ V_44 ] . V_4 & V_6 &&
V_74 -> V_174 < V_175 )
continue;
if ( V_74 -> V_176 == V_177 &&
V_38 [ V_44 ] . V_56 > 1 )
continue;
V_11 -> V_16 [ V_44 ] . V_17 =
V_155 -> V_178 [ V_38 [ V_44 ] . V_56 - 1 ] ;
if ( V_11 -> V_16 [ V_44 ] . V_17 )
V_159 ++ ;
}
if ( ! V_159 )
goto V_163;
F_13 ( V_9 , V_11 ) ;
F_30 ( V_9 , V_11 ) ;
return;
V_163:
V_88 -> V_97 = false ;
memset ( & V_88 -> V_100 , 0 , sizeof( V_88 -> V_100 ) ) ;
V_88 -> V_100 . V_179 = V_88 -> V_180 ;
V_88 -> V_100 . V_63 = V_88 -> V_63 ;
return V_98 . V_181 ( V_83 , V_85 , V_153 , V_74 ,
& V_88 -> V_100 ) ;
}
static void
F_46 ( void * V_83 , struct V_84 * V_85 ,
struct V_152 * V_153 ,
struct V_66 * V_74 , void * V_86 )
{
F_43 ( V_83 , V_85 , V_153 , V_74 , V_86 ) ;
}
static void
F_47 ( void * V_83 , struct V_84 * V_85 ,
struct V_152 * V_153 ,
struct V_66 * V_74 , void * V_86 ,
T_3 V_182 )
{
F_43 ( V_83 , V_85 , V_153 , V_74 , V_86 ) ;
}
static void *
F_48 ( void * V_83 , struct V_66 * V_74 , T_4 V_183 )
{
struct V_84 * V_85 ;
struct V_87 * V_88 ;
struct V_8 * V_9 = V_83 ;
struct V_184 * V_132 = V_9 -> V_132 ;
int V_133 = 0 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_185 ; V_44 ++ ) {
V_85 = V_132 -> V_186 -> V_187 [ V_44 ] ;
if ( V_85 && V_85 -> V_188 > V_133 )
V_133 = V_85 -> V_188 ;
}
V_88 = F_34 ( sizeof( * V_88 ) , V_183 ) ;
if ( ! V_88 )
return NULL ;
V_88 -> V_180 = F_34 ( sizeof( struct V_189 ) * V_133 , V_183 ) ;
if ( ! V_88 -> V_180 )
goto error;
V_88 -> V_63 = F_49 ( V_190 * V_133 , V_183 ) ;
if ( ! V_88 -> V_63 )
goto V_191;
return V_88 ;
V_191:
F_50 ( V_88 -> V_180 ) ;
error:
F_50 ( V_88 ) ;
return NULL ;
}
static void
F_51 ( void * V_83 , struct V_66 * V_74 , void * V_86 )
{
struct V_87 * V_88 = V_86 ;
F_50 ( V_88 -> V_63 ) ;
F_50 ( V_88 -> V_180 ) ;
F_50 ( V_88 ) ;
}
static void *
F_52 ( struct V_184 * V_132 , struct V_192 * V_193 )
{
return V_98 . V_194 ( V_132 , V_193 ) ;
}
static void
F_53 ( void * V_83 )
{
V_98 . free ( V_83 ) ;
}
static T_3 F_54 ( void * V_86 )
{
struct V_87 * V_88 = V_86 ;
struct V_10 * V_11 = & V_88 -> V_89 ;
int V_44 , V_195 ;
if ( ! V_88 -> V_97 )
return V_98 . V_196 ( V_86 ) ;
V_44 = V_11 -> V_51 / V_20 ;
V_195 = V_11 -> V_51 % V_20 ;
return V_11 -> V_16 [ V_44 ] . V_18 [ V_195 ] . V_35 * V_197 * 8 / 1024 ;
}
static void T_5 F_55 ( void )
{
int V_198 , V_44 , V_199 ;
T_2 V_200 [ V_20 ] ;
memset ( V_63 , 0xff , sizeof( V_63 ) ) ;
for ( V_198 = 0 ; V_198 < V_190 ; V_198 ++ ) {
F_56 ( V_200 , sizeof( V_200 ) ) ;
for ( V_44 = 0 ; V_44 < V_20 ; V_44 ++ ) {
V_199 = ( V_44 + V_200 [ V_44 ] ) % V_20 ;
while ( V_63 [ V_198 ] [ V_199 ] != 0xff )
V_199 = ( V_199 + 1 ) % V_20 ;
V_63 [ V_198 ] [ V_199 ] = V_44 ;
}
}
}
int T_5
F_57 ( void )
{
F_55 () ;
return F_58 ( & V_201 ) ;
}
void
F_59 ( void )
{
F_60 ( & V_201 ) ;
}
