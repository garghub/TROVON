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
V_3 = V_2 -> V_3 % 8 ;
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
V_33 = 1000000 * ( ( V_34 * 1000 ) / V_32 ) ;
V_21 -> V_35 = F_12 ( V_33 ) ;
}
static void
F_13 ( struct V_11 * V_12 , T_1 V_20 ,
T_1 * V_40 )
{
int V_41 , V_42 , V_43 , V_24 ;
int V_44 , V_45 , V_46 , V_47 ;
int V_48 = V_49 ;
V_41 = V_20 / V_4 ;
V_42 = V_20 % V_4 ;
V_43 = V_12 -> V_17 [ V_41 ] . V_19 [ V_42 ] . V_35 ;
V_24 = V_12 -> V_17 [ V_41 ] . V_19 [ V_42 ] . V_27 ;
do {
V_44 = V_40 [ V_48 - 1 ] / V_4 ;
V_45 = V_40 [ V_48 - 1 ] % V_4 ;
V_46 = V_12 -> V_17 [ V_44 ] . V_19 [ V_45 ] . V_35 ;
V_47 = V_12 -> V_17 [ V_44 ] . V_19 [ V_45 ] . V_27 ;
if ( V_43 < V_46 ||
( V_43 == V_46 && V_24 <= V_47 ) )
break;
V_48 -- ;
} while ( V_48 > 0 );
if ( V_48 < V_49 - 1 ) {
memmove ( & V_40 [ V_48 + 1 ] , & V_40 [ V_48 ] , ( sizeof( * V_40 ) *
( V_49 - ( V_48 + 1 ) ) ) ) ;
}
if ( V_48 < V_49 )
V_40 [ V_48 ] = V_20 ;
}
static void
F_14 ( struct V_11 * V_12 , T_1 V_20 )
{
struct V_50 * V_51 ;
struct V_8 * V_21 ;
int V_44 , V_45 , V_52 , V_47 , V_53 ;
V_51 = & V_12 -> V_17 [ V_20 / V_4 ] ;
V_21 = & V_51 -> V_19 [ V_20 % V_4 ] ;
V_44 = V_12 -> V_54 / V_4 ;
V_45 = V_12 -> V_54 % V_4 ;
V_52 = V_12 -> V_17 [ V_44 ] . V_19 [ V_45 ] . V_35 ;
V_47 = V_12 -> V_17 [ V_44 ] . V_19 [ V_45 ] . V_27 ;
V_53 = V_12 -> V_55 [ 0 ] / V_4 ;
if( ( V_20 / V_4 == V_15 ) &&
( V_53 != V_15 ) )
return;
if ( V_21 -> V_27 > F_9 ( 75 , 100 ) ) {
if ( V_21 -> V_35 > V_52 )
V_12 -> V_54 = V_20 ;
if ( V_21 -> V_35 > V_51 -> V_19 [ V_51 -> V_56 ] . V_35 )
V_51 -> V_56 = V_20 ;
} else {
if ( V_21 -> V_27 > V_47 )
V_12 -> V_54 = V_20 ;
if ( V_21 -> V_27 > V_51 -> V_19 [ V_51 -> V_56 ] . V_27 )
V_51 -> V_56 = V_20 ;
}
}
static void
F_15 ( struct V_11 * V_12 ,
T_1 V_57 [ V_49 ] ,
T_1 V_58 [ V_49 ] )
{
unsigned int V_44 , V_45 , V_59 , V_60 ;
int V_61 ;
V_44 = V_58 [ 0 ] / V_4 ;
V_45 = V_58 [ 0 ] % V_4 ;
V_59 = V_12 -> V_17 [ V_44 ] . V_19 [ V_45 ] . V_35 ;
V_44 = V_57 [ 0 ] / V_4 ;
V_45 = V_57 [ 0 ] % V_4 ;
V_60 = V_12 -> V_17 [ V_44 ] . V_19 [ V_45 ] . V_35 ;
if ( V_59 > V_60 ) {
for( V_61 = 0 ; V_61 < V_49 ; V_61 ++ ) {
F_13 ( V_12 , V_58 [ V_61 ] ,
V_57 ) ;
}
}
}
static inline void
F_16 ( struct V_11 * V_12 )
{
struct V_50 * V_51 ;
struct V_8 * V_21 ;
int V_62 , V_13 ;
int V_52 = 0 ;
V_62 = V_38 [ V_12 -> V_55 [ 0 ] /
V_4 ] . V_63 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_38 ) ; V_13 ++ ) {
V_51 = & V_12 -> V_17 [ V_13 ] ;
if ( ! V_51 -> V_18 || V_13 == V_15 )
continue;
V_21 = F_6 ( V_12 , V_51 -> V_56 ) ;
if ( V_52 < V_21 -> V_35 &&
( V_38 [ V_13 ] . V_63 < V_62 ) ) {
V_12 -> V_54 = V_51 -> V_56 ;
V_52 = V_21 -> V_35 ;
}
}
}
static void
F_17 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_50 * V_51 ;
struct V_8 * V_21 ;
int V_13 , V_61 , V_48 ;
T_1 V_57 [ V_49 ] , V_64 [ V_49 ] ;
T_1 V_58 [ V_49 ] , V_20 ;
if ( V_12 -> V_65 > 0 ) {
V_12 -> V_37 = F_10 ( V_12 -> V_37 ,
F_9 ( V_12 -> V_66 , V_12 -> V_65 ) , V_28 ) ;
V_12 -> V_66 = 0 ;
V_12 -> V_65 = 0 ;
}
V_12 -> V_67 = 0 ;
V_12 -> V_68 = 0 ;
for( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_57 [ V_48 ] = 0 ;
V_58 [ V_48 ] = 0 ;
}
for ( V_13 = 0 ; V_13 < F_4 ( V_38 ) ; V_13 ++ ) {
V_51 = & V_12 -> V_17 [ V_13 ] ;
if ( ! V_51 -> V_18 )
continue;
V_12 -> V_68 ++ ;
for( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
V_64 [ V_48 ] = V_13 ;
for ( V_61 = 0 ; V_61 < V_4 ; V_61 ++ ) {
if ( ! ( V_51 -> V_18 & F_5 ( V_61 ) ) )
continue;
V_20 = V_4 * V_13 + V_61 ;
V_21 = & V_51 -> V_19 [ V_61 ] ;
V_21 -> V_69 = false ;
F_7 ( V_21 ) ;
F_11 ( V_12 , V_13 , V_61 ) ;
if ( ! V_21 -> V_35 )
continue;
if ( V_13 != V_15 ) {
F_13 ( V_12 , V_20 ,
V_57 ) ;
} else if ( V_13 == V_15 ) {
F_13 ( V_12 , V_20 ,
V_58 ) ;
}
F_13 ( V_12 , V_20 ,
V_64 ) ;
F_14 ( V_12 , V_20 ) ;
}
memcpy ( V_51 -> V_70 , V_64 ,
sizeof( V_51 -> V_70 ) ) ;
}
F_15 ( V_12 , V_57 , V_58 ) ;
memcpy ( V_12 -> V_55 , V_57 , sizeof( V_12 -> V_55 ) ) ;
F_16 ( V_12 ) ;
V_12 -> V_68 *= 8 ;
#ifdef F_18
if ( V_10 -> V_71 != - 1 ) {
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ )
V_12 -> V_55 [ V_61 ] = V_10 -> V_71 ;
V_12 -> V_54 = V_10 -> V_71 ;
}
#endif
V_12 -> V_72 = V_73 ;
}
static bool
F_19 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
if ( V_2 -> V_3 < 0 )
return false ;
if ( ! V_2 -> V_74 )
return false ;
if ( V_2 -> V_5 & V_14 )
return true ;
return V_2 -> V_3 == V_10 -> V_16 [ 0 ] ||
V_2 -> V_3 == V_10 -> V_16 [ 1 ] ||
V_2 -> V_3 == V_10 -> V_16 [ 2 ] ||
V_2 -> V_3 == V_10 -> V_16 [ 3 ] ;
}
static void
F_20 ( struct V_11 * V_12 )
{
struct V_50 * V_51 ;
for (; ; ) {
V_12 -> V_75 ++ ;
V_12 -> V_75 %= F_4 ( V_38 ) ;
V_51 = & V_12 -> V_17 [ V_12 -> V_75 ] ;
if ( ! V_51 -> V_18 )
continue;
if ( ++ V_51 -> V_20 >= V_4 ) {
V_51 -> V_20 = 0 ;
if ( ++ V_51 -> V_76 >= F_4 ( V_77 ) )
V_51 -> V_76 = 0 ;
}
break;
}
}
static void
F_21 ( struct V_11 * V_12 , T_1 * V_3 , bool V_78 )
{
int V_13 , V_79 ;
V_79 = V_13 = * V_3 / V_4 ;
while ( V_13 > 0 ) {
V_13 -- ;
if ( ! V_12 -> V_17 [ V_13 ] . V_18 )
continue;
if ( V_38 [ V_13 ] . V_63 >
V_38 [ V_79 ] . V_63 )
continue;
if ( V_78 )
* V_3 = V_12 -> V_17 [ V_13 ] . V_70 [ 0 ] ;
else
* V_3 = V_12 -> V_17 [ V_13 ] . V_70 [ 1 ] ;
break;
}
}
static void
F_22 ( struct V_80 * V_81 , struct V_82 * V_83 )
{
struct V_84 * V_85 = (struct V_84 * ) V_83 -> V_86 ;
struct V_87 * V_88 = F_23 ( V_81 , struct V_87 , V_88 ) ;
T_2 V_89 ;
if ( F_8 ( ! F_24 ( V_85 -> V_90 ) ) )
return;
if ( F_8 ( V_83 -> V_91 == F_25 ( V_92 ) ) )
return;
V_89 = * F_26 ( V_85 ) & V_93 ;
if ( F_27 ( V_88 -> V_94 . V_95 [ V_89 ] ) )
return;
if ( F_28 ( V_83 ) == V_96 )
return;
F_29 ( V_81 , V_89 , 5000 ) ;
}
static void
F_30 ( void * V_97 , struct V_98 * V_99 ,
struct V_80 * V_88 , void * V_100 ,
struct V_82 * V_83 )
{
struct V_101 * V_102 = V_100 ;
struct V_11 * V_12 = & V_102 -> V_103 ;
struct V_104 * V_105 = F_31 ( V_83 ) ;
struct V_1 * V_106 = V_105 -> V_107 . V_19 ;
struct V_8 * V_2 , * V_108 ;
struct V_9 * V_10 = V_97 ;
bool V_109 , V_110 = false ;
int V_61 ;
if ( ! V_102 -> V_111 )
return V_112 . V_113 ( V_97 , V_99 , V_88 , & V_102 -> V_114 , V_83 ) ;
if ( ( V_105 -> V_5 & V_115 ) &&
! ( V_105 -> V_5 & V_116 ) )
return;
if ( ! ( V_105 -> V_5 & V_116 ) ) {
V_105 -> V_107 . V_117 =
( V_105 -> V_5 & V_118 ? 1 : 0 ) ;
V_105 -> V_107 . V_66 = 1 ;
}
V_12 -> V_65 ++ ;
V_12 -> V_66 += V_105 -> V_107 . V_66 ;
if ( ! V_12 -> V_119 && ! V_12 -> V_120 && V_12 -> V_68 > 0 ) {
V_12 -> V_119 = 16 + 2 * F_12 ( V_12 -> V_37 ) ;
V_12 -> V_120 = 1 ;
V_12 -> V_68 -- ;
}
if ( V_105 -> V_5 & V_121 )
V_12 -> V_122 += V_105 -> V_107 . V_66 ;
V_109 = ! F_19 ( V_10 , & V_106 [ 0 ] ) ;
for ( V_61 = 0 ; ! V_109 ; V_61 ++ ) {
V_109 = ( V_61 == V_123 - 1 ) ||
! F_19 ( V_10 , & V_106 [ V_61 + 1 ] ) ;
V_2 = F_3 ( V_10 , V_12 , & V_106 [ V_61 ] ) ;
if ( V_109 )
V_2 -> V_25 += V_105 -> V_107 . V_117 ;
V_2 -> V_22 += V_106 [ V_61 ] . V_74 * V_105 -> V_107 . V_66 ;
}
V_2 = F_6 ( V_12 , V_12 -> V_55 [ 0 ] ) ;
if ( V_2 -> V_22 > 30 &&
F_9 ( V_2 -> V_25 , V_2 -> V_22 ) <
F_9 ( 20 , 100 ) ) {
F_21 ( V_12 , & V_12 -> V_55 [ 0 ] , true ) ;
V_110 = true ;
}
V_108 = F_6 ( V_12 , V_12 -> V_55 [ 1 ] ) ;
if ( V_108 -> V_22 > 30 &&
F_9 ( V_108 -> V_25 , V_108 -> V_22 ) <
F_9 ( 20 , 100 ) ) {
F_21 ( V_12 , & V_12 -> V_55 [ 1 ] , false ) ;
V_110 = true ;
}
if ( F_32 ( V_73 , V_12 -> V_72 + ( V_10 -> V_124 / 2 * V_125 ) / 1000 ) ) {
V_110 = true ;
F_17 ( V_10 , V_12 ) ;
if ( ! ( V_105 -> V_5 & V_115 ) &&
V_12 -> V_54 / V_4 != V_15 )
F_22 ( V_88 , V_83 ) ;
}
if ( V_110 )
F_33 ( V_10 , V_12 ) ;
}
static void
F_34 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_20 )
{
struct V_8 * V_21 ;
const struct V_126 * V_13 ;
unsigned int V_127 , V_128 , V_129 ;
unsigned int V_130 = V_10 -> V_131 ;
unsigned int ctime = 0 ;
unsigned int V_132 = 9 ;
unsigned int V_66 = F_12 ( V_12 -> V_37 ) ;
unsigned int V_36 = 0 , V_133 = 0 ;
V_21 = F_6 ( V_12 , V_20 ) ;
if ( V_21 -> V_27 < F_9 ( 1 , 10 ) ) {
V_21 -> V_134 = 1 ;
V_21 -> V_135 = 1 ;
return;
}
V_21 -> V_134 = 2 ;
V_21 -> V_135 = 2 ;
V_21 -> V_69 = true ;
V_13 = & V_38 [ V_20 / V_4 ] ;
V_129 = V_13 -> V_39 [ V_20 % V_4 ] * V_66 / 1000 ;
ctime = ( V_132 * V_130 ) >> 1 ;
V_130 = F_35 ( ( V_130 << 1 ) | 1 , V_10 -> V_136 ) ;
ctime += ( V_132 * V_130 ) >> 1 ;
V_130 = F_35 ( ( V_130 << 1 ) | 1 , V_10 -> V_136 ) ;
if ( V_20 / V_4 != V_15 ) {
V_36 = V_12 -> V_36 ;
V_133 = V_12 -> V_133 ;
}
V_127 = ctime + 2 * ( V_36 + V_129 ) ;
V_128 = ctime + 2 * ( V_133 + V_129 ) ;
do {
ctime = ( V_132 * V_130 ) >> 1 ;
V_130 = F_35 ( ( V_130 << 1 ) | 1 , V_10 -> V_136 ) ;
V_127 += ctime + V_36 + V_129 ;
V_128 += ctime + V_133 + V_129 ;
if ( V_128 < V_10 -> V_137 )
V_21 -> V_135 ++ ;
} while ( ( V_127 < V_10 -> V_137 ) &&
( ++ V_21 -> V_134 < V_10 -> V_138 ) );
}
static void
F_36 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_139 * V_140 , int V_141 , int V_20 )
{
const struct V_126 * V_13 = & V_38 [ V_20 / V_4 ] ;
struct V_8 * V_21 ;
T_1 V_3 ;
T_2 V_5 ;
V_21 = F_6 ( V_12 , V_20 ) ;
if ( ! V_21 -> V_69 )
F_34 ( V_10 , V_12 , V_20 ) ;
if ( V_21 -> V_27 < F_9 ( 20 , 100 ) || ! V_21 -> V_134 ) {
V_140 -> V_2 [ V_141 ] . V_74 = 2 ;
V_140 -> V_2 [ V_141 ] . V_142 = 2 ;
V_140 -> V_2 [ V_141 ] . V_143 = 2 ;
} else {
V_140 -> V_2 [ V_141 ] . V_74 = V_21 -> V_134 ;
V_140 -> V_2 [ V_141 ] . V_143 = V_21 -> V_134 ;
V_140 -> V_2 [ V_141 ] . V_142 = V_21 -> V_135 ;
}
if ( V_20 / V_4 == V_15 ) {
V_3 = V_10 -> V_16 [ V_20 % F_4 ( V_10 -> V_16 ) ] ;
V_5 = 0 ;
} else {
V_3 = V_20 % V_4 + ( V_13 -> V_63 - 1 ) * 8 ;
V_5 = V_14 | V_13 -> V_5 ;
}
if ( V_141 > 0 ) {
V_140 -> V_2 [ V_141 ] . V_74 = V_140 -> V_2 [ V_141 ] . V_142 ;
V_5 |= V_144 ;
}
V_140 -> V_2 [ V_141 ] . V_3 = V_3 ;
V_140 -> V_2 [ V_141 ] . V_5 = V_5 ;
}
static void
F_33 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_139 * V_19 ;
int V_61 = 0 ;
V_19 = F_37 ( sizeof( * V_19 ) , V_145 ) ;
if ( ! V_19 )
return;
F_36 ( V_10 , V_12 , V_19 , V_61 ++ , V_12 -> V_55 [ 0 ] ) ;
if ( V_10 -> V_146 -> V_147 >= 3 ) {
F_36 ( V_10 , V_12 , V_19 , V_61 ++ , V_12 -> V_55 [ 1 ] ) ;
}
if ( V_10 -> V_146 -> V_147 >= 2 ) {
F_36 ( V_10 , V_12 , V_19 , V_61 ++ , V_12 -> V_54 ) ;
}
V_19 -> V_2 [ V_61 ] . V_3 = - 1 ;
F_38 ( V_10 -> V_146 , V_12 -> V_88 , V_19 ) ;
}
static inline int
F_39 ( int V_20 )
{
const struct V_126 * V_13 = & V_38 [ V_20 / V_4 ] ;
return V_13 -> V_39 [ V_20 % V_4 ] ;
}
static int
F_40 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_8 * V_21 ;
struct V_50 * V_51 ;
unsigned int V_148 , V_75 , V_149 ;
int V_150 = 0 ;
if ( V_12 -> V_119 > 0 ) {
V_12 -> V_119 -- ;
return - 1 ;
}
if ( ! V_12 -> V_120 )
return - 1 ;
V_75 = V_12 -> V_75 ;
V_51 = & V_12 -> V_17 [ V_75 ] ;
V_150 = V_77 [ V_51 -> V_76 ] [ V_51 -> V_20 ] ;
F_20 ( V_12 ) ;
if ( ! ( V_51 -> V_18 & F_5 ( V_150 ) ) )
return - 1 ;
V_21 = & V_51 -> V_19 [ V_150 ] ;
V_150 += V_75 * V_4 ;
if ( V_150 == V_12 -> V_55 [ 0 ] ||
V_150 == V_12 -> V_55 [ 1 ] ||
V_150 == V_12 -> V_54 )
return - 1 ;
if ( V_21 -> V_27 > F_9 ( 95 , 100 ) )
return - 1 ;
V_149 = V_38 [ V_12 -> V_55 [ 0 ] /
V_4 ] . V_63 ;
V_148 = F_39 ( V_150 ) ;
if ( V_148 >= F_39 ( V_12 -> V_55 [ 1 ] ) &&
( V_149 - 1 <
V_38 [ V_75 ] . V_63 ||
V_148 >= F_39 ( V_12 -> V_54 ) ) ) {
if ( V_21 -> V_23 < 20 )
return - 1 ;
if ( V_12 -> V_67 ++ > 2 )
return - 1 ;
}
V_12 -> V_120 -- ;
return V_150 ;
}
static void
F_41 ( struct V_9 * V_10 ,
struct V_11 * V_12 , bool V_151 )
{
T_1 V_18 = V_12 -> V_17 [ V_15 ] . V_18 ;
if ( ! V_18 || ! V_12 -> V_152 )
return;
if ( V_18 & ( V_12 -> V_152 << ( V_151 * 4 ) ) )
return;
V_18 ^= V_12 -> V_152 | ( V_12 -> V_152 << 4 ) ;
V_12 -> V_17 [ V_15 ] . V_18 = V_18 ;
}
static void
F_42 ( void * V_97 , struct V_80 * V_88 , void * V_100 ,
struct V_153 * V_154 )
{
const struct V_126 * V_75 ;
struct V_104 * V_105 = F_31 ( V_154 -> V_83 ) ;
struct V_1 * V_2 = & V_105 -> V_107 . V_19 [ 0 ] ;
struct V_101 * V_102 = V_100 ;
struct V_11 * V_12 = & V_102 -> V_103 ;
struct V_9 * V_10 = V_97 ;
int V_150 ;
if ( F_43 ( V_88 , V_100 , V_154 ) )
return;
if ( ! V_102 -> V_111 )
return V_112 . V_155 ( V_97 , V_88 , & V_102 -> V_114 , V_154 ) ;
V_105 -> V_5 |= V_12 -> V_156 ;
F_41 ( V_10 , V_12 , V_154 -> V_157 ) ;
#ifdef F_18
if ( V_10 -> V_71 != - 1 )
return;
#endif
if ( V_10 -> V_146 -> V_147 == 1 &&
( V_105 -> V_158 . V_5 & V_159 ) )
V_150 = - 1 ;
else
V_150 = F_40 ( V_10 , V_12 ) ;
V_12 -> V_160 ++ ;
if ( V_12 -> V_160 == ~ 0 ) {
V_12 -> V_160 = 0 ;
V_12 -> V_122 = 0 ;
}
if ( V_150 < 0 )
return;
V_75 = & V_38 [ V_150 / V_4 ] ;
V_105 -> V_5 |= V_121 ;
V_2 -> V_74 = 1 ;
if ( V_150 / V_4 == V_15 ) {
int V_3 = V_150 % F_4 ( V_10 -> V_16 ) ;
V_2 -> V_3 = V_10 -> V_16 [ V_3 ] ;
V_2 -> V_5 = 0 ;
return;
}
V_2 -> V_3 = V_150 % V_4 +
( V_75 -> V_63 - 1 ) * 8 ;
V_2 -> V_5 = V_14 | V_75 -> V_5 ;
}
static void
F_44 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_98 * V_99 ,
struct V_80 * V_88 )
{
int V_61 ;
if ( V_99 -> V_161 != V_162 )
return;
if ( ! ( V_10 -> V_146 -> V_5 & V_163 ) )
return;
V_12 -> V_164 = 0 ;
V_12 -> V_152 = 0 ;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
if ( ! F_45 ( V_88 , V_99 -> V_161 , V_10 -> V_16 [ V_61 ] ) )
continue;
V_12 -> V_164 |= F_5 ( V_61 ) ;
if ( V_99 -> V_165 [ V_61 ] . V_5 & V_166 )
V_12 -> V_152 |= F_5 ( V_61 ) ;
}
V_12 -> V_17 [ V_15 ] . V_18 = V_12 -> V_164 ;
}
static void
F_46 ( void * V_97 , struct V_98 * V_99 ,
struct V_167 * V_168 ,
struct V_80 * V_88 , void * V_100 )
{
struct V_9 * V_10 = V_97 ;
struct V_101 * V_102 = V_100 ;
struct V_11 * V_12 = & V_102 -> V_103 ;
struct V_169 * V_170 = & V_88 -> V_171 . V_170 ;
T_2 V_172 = V_88 -> V_171 . V_173 ;
int V_174 = 0 ;
int V_175 ;
int V_176 ;
int V_61 ;
if ( ! V_88 -> V_171 . V_177 )
goto V_178;
F_47 ( F_4 ( V_38 ) !=
V_179 * V_180 + 1 ) ;
V_102 -> V_111 = true ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_88 = V_88 ;
V_12 -> V_72 = V_73 ;
V_175 = F_48 ( V_99 -> V_161 , 10 , 60 , 1 , 1 , 0 ) ;
V_12 -> V_36 = F_48 ( V_99 -> V_161 , 0 , 60 , 1 , 1 , 0 ) ;
V_12 -> V_36 += V_175 ;
V_12 -> V_133 = V_12 -> V_36 + 2 * V_175 ;
V_12 -> V_37 = F_9 ( 1 , 1 ) ;
if ( V_10 -> V_181 ) {
V_12 -> V_68 = 16 ;
V_12 -> V_119 = 0 ;
} else {
V_12 -> V_68 = 8 ;
V_12 -> V_119 = 8 ;
}
V_12 -> V_120 = 4 ;
V_176 = ( V_172 & V_182 ) >>
V_183 ;
V_12 -> V_156 |= V_176 << V_184 ;
if ( V_172 & V_185 )
V_12 -> V_156 |= V_186 ;
for ( V_61 = 0 ; V_61 < F_4 ( V_12 -> V_17 ) ; V_61 ++ ) {
V_12 -> V_17 [ V_61 ] . V_18 = 0 ;
if ( V_61 == V_15 ) {
F_44 ( V_10 , V_12 , V_99 , V_88 ) ;
continue;
}
if ( V_38 [ V_61 ] . V_5 & V_6 ) {
if ( V_38 [ V_61 ] . V_5 & V_7 ) {
if ( ! ( V_172 & V_187 ) )
continue;
} else {
if ( ! ( V_172 & V_188 ) )
continue;
}
}
if ( V_38 [ V_61 ] . V_5 & V_7 &&
V_88 -> V_189 < V_190 )
continue;
if ( V_88 -> V_191 == V_192 &&
V_38 [ V_61 ] . V_63 > 1 )
continue;
V_12 -> V_17 [ V_61 ] . V_18 =
V_170 -> V_193 [ V_38 [ V_61 ] . V_63 - 1 ] ;
if ( V_12 -> V_17 [ V_61 ] . V_18 )
V_174 ++ ;
}
if ( ! V_174 )
goto V_178;
F_17 ( V_10 , V_12 ) ;
F_33 ( V_10 , V_12 ) ;
return;
V_178:
V_102 -> V_111 = false ;
memset ( & V_102 -> V_114 , 0 , sizeof( V_102 -> V_114 ) ) ;
V_102 -> V_114 . V_194 = V_102 -> V_195 ;
V_102 -> V_114 . V_77 = V_102 -> V_77 ;
return V_112 . V_196 ( V_97 , V_99 , V_168 , V_88 ,
& V_102 -> V_114 ) ;
}
static void
F_49 ( void * V_97 , struct V_98 * V_99 ,
struct V_167 * V_168 ,
struct V_80 * V_88 , void * V_100 )
{
F_46 ( V_97 , V_99 , V_168 , V_88 , V_100 ) ;
}
static void
F_50 ( void * V_97 , struct V_98 * V_99 ,
struct V_167 * V_168 ,
struct V_80 * V_88 , void * V_100 ,
T_3 V_197 )
{
F_46 ( V_97 , V_99 , V_168 , V_88 , V_100 ) ;
}
static void *
F_51 ( void * V_97 , struct V_80 * V_88 , T_4 V_198 )
{
struct V_98 * V_99 ;
struct V_101 * V_102 ;
struct V_9 * V_10 = V_97 ;
struct V_199 * V_146 = V_10 -> V_146 ;
int V_147 = 0 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_200 ; V_61 ++ ) {
V_99 = V_146 -> V_201 -> V_202 [ V_61 ] ;
if ( V_99 && V_99 -> V_203 > V_147 )
V_147 = V_99 -> V_203 ;
}
V_102 = F_37 ( sizeof( * V_102 ) , V_198 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_195 = F_37 ( sizeof( struct V_204 ) * V_147 , V_198 ) ;
if ( ! V_102 -> V_195 )
goto error;
V_102 -> V_77 = F_52 ( V_205 * V_147 , V_198 ) ;
if ( ! V_102 -> V_77 )
goto V_206;
return V_102 ;
V_206:
F_53 ( V_102 -> V_195 ) ;
error:
F_53 ( V_102 ) ;
return NULL ;
}
static void
F_54 ( void * V_97 , struct V_80 * V_88 , void * V_100 )
{
struct V_101 * V_102 = V_100 ;
F_53 ( V_102 -> V_77 ) ;
F_53 ( V_102 -> V_195 ) ;
F_53 ( V_102 ) ;
}
static void *
F_55 ( struct V_199 * V_146 , struct V_207 * V_208 )
{
return V_112 . V_209 ( V_146 , V_208 ) ;
}
static void
F_56 ( void * V_97 )
{
V_112 . free ( V_97 ) ;
}
static T_3 F_57 ( void * V_100 )
{
struct V_101 * V_102 = V_100 ;
struct V_11 * V_12 = & V_102 -> V_103 ;
int V_61 , V_48 ;
if ( ! V_102 -> V_111 )
return V_112 . V_210 ( V_100 ) ;
V_61 = V_12 -> V_55 [ 0 ] / V_4 ;
V_48 = V_12 -> V_55 [ 0 ] % V_4 ;
return V_12 -> V_17 [ V_61 ] . V_19 [ V_48 ] . V_35 * V_211 * 8 / 1024 ;
}
static void T_5 F_58 ( void )
{
int V_212 , V_61 , V_213 ;
T_1 V_214 [ V_4 ] ;
memset ( V_77 , 0xff , sizeof( V_77 ) ) ;
for ( V_212 = 0 ; V_212 < V_205 ; V_212 ++ ) {
F_59 ( V_214 , sizeof( V_214 ) ) ;
for ( V_61 = 0 ; V_61 < V_4 ; V_61 ++ ) {
V_213 = ( V_61 + V_214 [ V_61 ] ) % V_4 ;
while ( V_77 [ V_212 ] [ V_213 ] != 0xff )
V_213 = ( V_213 + 1 ) % V_4 ;
V_77 [ V_212 ] [ V_213 ] = V_61 ;
}
}
}
int T_5
F_60 ( void )
{
F_58 () ;
return F_61 ( & V_215 ) ;
}
void
F_62 ( void )
{
F_63 ( & V_215 ) ;
}
