static T_1
F_1 ( int V_1 , int V_2 , T_2 V_3 )
{
T_1 V_4 = 0 ;
if ( V_1 == V_5 ) {
if ( V_2 != 3 && V_2 != 6 )
V_4 = F_2 ( 9 ) ;
} else if ( V_1 == V_6 ) {
if ( V_2 == 3 || V_2 == 7 )
V_4 = F_2 ( 6 ) ;
else if ( V_2 == 6 )
V_4 = F_2 ( 9 ) ;
} else {
F_3 ( V_1 != V_7 ) ;
}
switch ( ( F_4 ( V_3 ) >> ( 2 * ( V_2 - 1 ) ) ) & 3 ) {
case V_8 :
V_4 |= 0x300 ;
break;
case V_9 :
V_4 |= 0x200 ;
break;
case V_10 :
break;
default:
V_4 = 0x3ff ;
}
return 0x3ff & ~ V_4 ;
}
static int
F_5 ( struct V_11 * V_12 )
{
return F_6 ( ( V_12 -> V_13 / 8 ) + 1 ,
! ! ( V_12 -> V_14 & V_15 ) ,
! ! ( V_12 -> V_14 & V_16 ) ) ;
}
static int
F_7 ( struct V_11 * V_12 )
{
return F_8 ( F_9 ( V_12 ) ,
! ! ( V_12 -> V_14 & V_15 ) ,
! ! ( V_12 -> V_14 & V_16 ) +
2 * ! ! ( V_12 -> V_14 & V_17 ) ) ;
}
static struct V_18 *
F_10 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_11 * V_12 )
{
int V_23 , V_13 ;
if ( V_12 -> V_14 & V_24 ) {
V_23 = F_5 ( V_12 ) ;
V_13 = V_12 -> V_13 % 8 ;
} else if ( V_12 -> V_14 & V_25 ) {
V_23 = F_7 ( V_12 ) ;
V_13 = F_11 ( V_12 ) ;
} else {
V_23 = V_26 ;
for ( V_13 = 0 ; V_13 < F_12 ( V_20 -> V_27 ) ; V_13 ++ )
if ( V_12 -> V_13 == V_20 -> V_27 [ V_13 ] )
break;
if ( ! ( V_22 -> V_28 [ V_23 ] & F_2 ( V_13 ) ) )
V_13 += 4 ;
}
return & V_22 -> V_29 [ V_23 ] . V_30 [ V_13 ] ;
}
static inline struct V_18 *
F_13 ( struct V_21 * V_22 , int V_31 )
{
return & V_22 -> V_29 [ V_31 / V_32 ] . V_30 [ V_31 % V_32 ] ;
}
int
F_14 ( struct V_21 * V_22 , int V_23 , int V_12 ,
int V_33 )
{
unsigned int V_34 = 0 ;
if ( V_33 < F_15 ( 10 , 100 ) )
return 0 ;
if ( V_23 != V_26 )
V_34 = 1000 * V_22 -> V_35 / F_16 ( V_22 -> V_36 ) ;
V_34 += V_37 [ V_23 ] . V_38 [ V_12 ] ;
if ( V_33 > F_15 ( 90 , 100 ) )
return F_16 ( 100000 * ( ( F_15 ( 90 , 100 ) * 1000 )
/ V_34 ) ) ;
else
return F_16 ( 100000 * ( ( V_33 * 1000 ) / V_34 ) ) ;
}
static void
F_17 ( struct V_21 * V_22 , T_1 V_31 ,
T_1 * V_39 )
{
int V_40 , V_41 , V_42 , V_43 ;
int V_44 , V_45 , V_46 , V_47 ;
int V_48 = V_49 ;
V_40 = V_31 / V_32 ;
V_41 = V_31 % V_32 ;
V_43 = V_22 -> V_29 [ V_40 ] . V_30 [ V_41 ] . V_33 ;
V_42 = F_14 ( V_22 , V_40 , V_41 , V_43 ) ;
do {
V_44 = V_39 [ V_48 - 1 ] / V_32 ;
V_45 = V_39 [ V_48 - 1 ] % V_32 ;
V_47 = V_22 -> V_29 [ V_44 ] . V_30 [ V_45 ] . V_33 ;
V_46 = F_14 ( V_22 , V_44 , V_45 ,
V_47 ) ;
if ( V_42 < V_46 ||
( V_42 == V_46 && V_43 <= V_47 ) )
break;
V_48 -- ;
} while ( V_48 > 0 );
if ( V_48 < V_49 - 1 ) {
memmove ( & V_39 [ V_48 + 1 ] , & V_39 [ V_48 ] , ( sizeof( * V_39 ) *
( V_49 - ( V_48 + 1 ) ) ) ) ;
}
if ( V_48 < V_49 )
V_39 [ V_48 ] = V_31 ;
}
static void
F_18 ( struct V_21 * V_22 , T_1 V_31 )
{
struct V_50 * V_51 ;
struct V_18 * V_52 ;
int V_44 , V_45 , V_46 , V_47 ;
int V_53 , V_42 , V_40 , V_41 ;
int V_54 , V_55 ;
int V_56 , V_57 ;
V_40 = V_31 / V_32 ;
V_41 = V_31 % V_32 ;
V_51 = & V_22 -> V_29 [ V_31 / V_32 ] ;
V_52 = & V_51 -> V_30 [ V_31 % V_32 ] ;
V_44 = V_22 -> V_58 / V_32 ;
V_45 = V_22 -> V_58 % V_32 ;
V_47 = V_22 -> V_29 [ V_44 ] . V_30 [ V_45 ] . V_33 ;
V_46 = F_14 ( V_22 , V_44 , V_45 , V_47 ) ;
V_53 = V_22 -> V_59 [ 0 ] / V_32 ;
if( ( V_31 / V_32 == V_26 ) &&
( V_53 != V_26 ) )
return;
V_54 = V_51 -> V_60 / V_32 ;
V_55 = V_51 -> V_60 % V_32 ;
V_57 = V_22 -> V_29 [ V_54 ] . V_30 [ V_55 ] . V_33 ;
if ( V_52 -> V_33 > F_15 ( 75 , 100 ) ) {
V_42 = F_14 ( V_22 , V_40 , V_41 ,
V_52 -> V_33 ) ;
if ( V_42 > V_46 )
V_22 -> V_58 = V_31 ;
V_56 = F_14 ( V_22 , V_54 ,
V_55 ,
V_57 ) ;
if ( V_42 > V_56 )
V_51 -> V_60 = V_31 ;
} else {
if ( V_52 -> V_33 > V_47 )
V_22 -> V_58 = V_31 ;
if ( V_52 -> V_33 > V_57 )
V_51 -> V_60 = V_31 ;
}
}
static void
F_19 ( struct V_21 * V_22 ,
T_1 V_61 [ V_49 ] ,
T_1 V_62 [ V_49 ] )
{
unsigned int V_44 , V_45 , V_63 , V_64 , V_47 ;
int V_65 ;
V_44 = V_62 [ 0 ] / V_32 ;
V_45 = V_62 [ 0 ] % V_32 ;
V_47 = V_22 -> V_29 [ V_44 ] . V_30 [ V_45 ] . V_33 ;
V_63 = F_14 ( V_22 , V_44 , V_45 , V_47 ) ;
V_44 = V_61 [ 0 ] / V_32 ;
V_45 = V_61 [ 0 ] % V_32 ;
V_47 = V_22 -> V_29 [ V_44 ] . V_30 [ V_45 ] . V_33 ;
V_64 = F_14 ( V_22 , V_44 , V_45 , V_47 ) ;
if ( V_63 > V_64 ) {
for( V_65 = 0 ; V_65 < V_49 ; V_65 ++ ) {
F_17 ( V_22 , V_62 [ V_65 ] ,
V_61 ) ;
}
}
}
static inline void
F_20 ( struct V_21 * V_22 )
{
struct V_50 * V_51 ;
int V_66 , V_23 , V_45 , V_47 ;
int V_67 = 0 ;
V_66 = V_37 [ V_22 -> V_59 [ 0 ] /
V_32 ] . V_68 ;
for ( V_23 = 0 ; V_23 < F_12 ( V_37 ) ; V_23 ++ ) {
V_51 = & V_22 -> V_29 [ V_23 ] ;
if ( ! V_22 -> V_28 [ V_23 ] || V_23 == V_26 )
continue;
V_45 = V_51 -> V_60 % V_32 ;
V_47 = V_22 -> V_29 [ V_23 ] . V_30 [ V_45 ] . V_33 ;
if ( V_67 < F_14 ( V_22 , V_23 , V_45 , V_47 ) &&
( V_37 [ V_23 ] . V_68 < V_66 ) ) {
V_22 -> V_58 = V_51 -> V_60 ;
V_67 = F_14 ( V_22 , V_23 ,
V_45 ,
V_47 ) ;
}
}
}
static void
F_21 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_50 * V_51 ;
struct V_18 * V_52 ;
int V_23 , V_65 , V_48 , V_43 ;
T_1 V_61 [ V_49 ] , V_69 [ V_49 ] ;
T_1 V_62 [ V_49 ] , V_31 ;
if ( V_22 -> V_70 > 0 ) {
V_22 -> V_36 = F_22 ( V_22 -> V_36 ,
F_15 ( V_22 -> V_71 , V_22 -> V_70 ) , V_72 ) ;
V_22 -> V_71 = 0 ;
V_22 -> V_70 = 0 ;
}
V_22 -> V_73 = 0 ;
V_22 -> V_74 = 0 ;
for( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_61 [ V_48 ] = 0 ;
V_62 [ V_48 ] = 0 ;
}
for ( V_23 = 0 ; V_23 < F_12 ( V_37 ) ; V_23 ++ ) {
V_51 = & V_22 -> V_29 [ V_23 ] ;
if ( ! V_22 -> V_28 [ V_23 ] )
continue;
V_22 -> V_74 ++ ;
for( V_48 = 0 ; V_48 < V_49 ; V_48 ++ )
V_69 [ V_48 ] = V_23 ;
for ( V_65 = 0 ; V_65 < V_32 ; V_65 ++ ) {
if ( ! ( V_22 -> V_28 [ V_23 ] & F_2 ( V_65 ) ) )
continue;
V_31 = V_32 * V_23 + V_65 ;
V_52 = & V_51 -> V_30 [ V_65 ] ;
V_52 -> V_75 = false ;
F_23 ( V_52 ) ;
V_43 = V_52 -> V_33 ;
if ( F_14 ( V_22 , V_23 , V_65 , V_43 ) == 0 )
continue;
if ( V_23 != V_26 ) {
F_17 ( V_22 , V_31 ,
V_61 ) ;
} else if ( V_23 == V_26 ) {
F_17 ( V_22 , V_31 ,
V_62 ) ;
}
F_17 ( V_22 , V_31 ,
V_69 ) ;
F_18 ( V_22 , V_31 ) ;
}
memcpy ( V_51 -> V_76 , V_69 ,
sizeof( V_51 -> V_76 ) ) ;
}
F_19 ( V_22 , V_61 , V_62 ) ;
memcpy ( V_22 -> V_59 , V_61 , sizeof( V_22 -> V_59 ) ) ;
F_20 ( V_22 ) ;
V_22 -> V_74 *= 8 ;
#ifdef F_24
if ( V_20 -> V_77 != - 1 ) {
for ( V_65 = 0 ; V_65 < 4 ; V_65 ++ )
V_22 -> V_59 [ V_65 ] = V_20 -> V_77 ;
V_22 -> V_58 = V_20 -> V_77 ;
}
#endif
V_22 -> V_78 = V_79 ;
}
static bool
F_25 ( struct V_19 * V_20 , struct V_11 * V_12 )
{
if ( V_12 -> V_13 < 0 )
return false ;
if ( ! V_12 -> V_80 )
return false ;
if ( V_12 -> V_14 & V_24 ||
V_12 -> V_14 & V_25 )
return true ;
return V_12 -> V_13 == V_20 -> V_27 [ 0 ] ||
V_12 -> V_13 == V_20 -> V_27 [ 1 ] ||
V_12 -> V_13 == V_20 -> V_27 [ 2 ] ||
V_12 -> V_13 == V_20 -> V_27 [ 3 ] ;
}
static void
F_26 ( struct V_21 * V_22 )
{
struct V_50 * V_51 ;
for (; ; ) {
V_22 -> V_81 ++ ;
V_22 -> V_81 %= F_12 ( V_37 ) ;
V_51 = & V_22 -> V_29 [ V_22 -> V_81 ] ;
if ( ! V_22 -> V_28 [ V_22 -> V_81 ] )
continue;
if ( ++ V_51 -> V_31 >= V_32 ) {
V_51 -> V_31 = 0 ;
if ( ++ V_51 -> V_82 >= F_12 ( V_83 ) )
V_51 -> V_82 = 0 ;
}
break;
}
}
static void
F_27 ( struct V_21 * V_22 , T_1 * V_13 , bool V_84 )
{
int V_23 , V_85 ;
V_85 = V_23 = * V_13 / V_32 ;
while ( V_23 > 0 ) {
V_23 -- ;
if ( ! V_22 -> V_28 [ V_23 ] )
continue;
if ( V_37 [ V_23 ] . V_68 >
V_37 [ V_85 ] . V_68 )
continue;
if ( V_84 )
* V_13 = V_22 -> V_29 [ V_23 ] . V_76 [ 0 ] ;
else
* V_13 = V_22 -> V_29 [ V_23 ] . V_76 [ 1 ] ;
break;
}
}
static void
F_28 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
struct V_90 * V_91 = (struct V_90 * ) V_89 -> V_92 ;
struct V_93 * V_94 = F_29 ( V_87 , struct V_93 , V_94 ) ;
T_1 V_95 ;
if ( F_30 ( V_89 ) == V_96 )
return;
if ( F_31 ( ! F_32 ( V_91 -> V_97 ) ) )
return;
if ( F_31 ( V_89 -> V_98 == F_33 ( V_99 ) ) )
return;
V_95 = * F_34 ( V_91 ) & V_100 ;
if ( F_35 ( V_94 -> V_101 . V_102 [ V_95 ] ) )
return;
F_36 ( V_87 , V_95 , 0 ) ;
}
static void
F_37 ( void * V_103 , struct V_104 * V_105 ,
void * V_106 , struct V_107 * V_108 )
{
struct V_109 * V_110 = V_108 -> V_110 ;
struct V_111 * V_112 = V_106 ;
struct V_21 * V_22 = & V_112 -> V_113 ;
struct V_11 * V_114 = V_110 -> V_115 . V_30 ;
struct V_18 * V_12 , * V_116 ;
struct V_19 * V_20 = V_103 ;
bool V_117 , V_118 = false ;
int V_65 ;
if ( ! V_112 -> V_119 )
return V_120 . V_121 ( V_103 , V_105 ,
& V_112 -> V_122 , V_108 ) ;
if ( ( V_110 -> V_14 & V_123 ) &&
! ( V_110 -> V_14 & V_124 ) )
return;
if ( ! ( V_110 -> V_14 & V_124 ) ) {
V_110 -> V_115 . V_125 =
( V_110 -> V_14 & V_126 ? 1 : 0 ) ;
V_110 -> V_115 . V_71 = 1 ;
}
V_22 -> V_70 ++ ;
V_22 -> V_71 += V_110 -> V_115 . V_71 ;
if ( ! V_22 -> V_127 && ! V_22 -> V_128 && V_22 -> V_74 > 0 ) {
V_22 -> V_127 = 16 + 2 * F_16 ( V_22 -> V_36 ) ;
V_22 -> V_128 = 1 ;
V_22 -> V_74 -- ;
}
if ( V_110 -> V_14 & V_129 )
V_22 -> V_130 += V_110 -> V_115 . V_71 ;
V_117 = ! F_25 ( V_20 , & V_114 [ 0 ] ) ;
for ( V_65 = 0 ; ! V_117 ; V_65 ++ ) {
V_117 = ( V_65 == V_131 - 1 ) ||
! F_25 ( V_20 , & V_114 [ V_65 + 1 ] ) ;
V_12 = F_10 ( V_20 , V_22 , & V_114 [ V_65 ] ) ;
if ( V_117 )
V_12 -> V_132 += V_110 -> V_115 . V_125 ;
V_12 -> V_133 += V_114 [ V_65 ] . V_80 * V_110 -> V_115 . V_71 ;
}
V_12 = F_13 ( V_22 , V_22 -> V_59 [ 0 ] ) ;
if ( V_12 -> V_133 > 30 &&
F_15 ( V_12 -> V_132 , V_12 -> V_133 ) <
F_15 ( 20 , 100 ) ) {
F_27 ( V_22 , & V_22 -> V_59 [ 0 ] , true ) ;
V_118 = true ;
}
V_116 = F_13 ( V_22 , V_22 -> V_59 [ 1 ] ) ;
if ( V_116 -> V_133 > 30 &&
F_15 ( V_116 -> V_132 , V_116 -> V_133 ) <
F_15 ( 20 , 100 ) ) {
F_27 ( V_22 , & V_22 -> V_59 [ 1 ] , false ) ;
V_118 = true ;
}
if ( F_38 ( V_79 , V_22 -> V_78 +
( V_20 -> V_134 / 2 * V_135 ) / 1000 ) ) {
V_118 = true ;
F_21 ( V_20 , V_22 ) ;
}
if ( V_118 )
F_39 ( V_20 , V_22 ) ;
}
static void
F_40 ( struct V_19 * V_20 , struct V_21 * V_22 ,
int V_31 )
{
struct V_18 * V_52 ;
const struct V_136 * V_23 ;
unsigned int V_137 , V_138 , V_139 ;
unsigned int V_140 = V_20 -> V_141 ;
unsigned int ctime = 0 ;
unsigned int V_142 = 9 ;
unsigned int V_71 = F_16 ( V_22 -> V_36 ) ;
unsigned int V_35 = 0 , V_143 = 0 ;
V_52 = F_13 ( V_22 , V_31 ) ;
if ( V_52 -> V_33 < F_15 ( 1 , 10 ) ) {
V_52 -> V_144 = 1 ;
V_52 -> V_145 = 1 ;
return;
}
V_52 -> V_144 = 2 ;
V_52 -> V_145 = 2 ;
V_52 -> V_75 = true ;
V_23 = & V_37 [ V_31 / V_32 ] ;
V_139 = V_23 -> V_38 [ V_31 % V_32 ] * V_71 / 1000 ;
ctime = ( V_142 * V_140 ) >> 1 ;
V_140 = F_41 ( ( V_140 << 1 ) | 1 , V_20 -> V_146 ) ;
ctime += ( V_142 * V_140 ) >> 1 ;
V_140 = F_41 ( ( V_140 << 1 ) | 1 , V_20 -> V_146 ) ;
if ( V_31 / V_32 != V_26 ) {
V_35 = V_22 -> V_35 ;
V_143 = V_22 -> V_143 ;
}
V_137 = ctime + 2 * ( V_35 + V_139 ) ;
V_138 = ctime + 2 * ( V_143 + V_139 ) ;
do {
ctime = ( V_142 * V_140 ) >> 1 ;
V_140 = F_41 ( ( V_140 << 1 ) | 1 , V_20 -> V_146 ) ;
V_137 += ctime + V_35 + V_139 ;
V_138 += ctime + V_143 + V_139 ;
if ( V_138 < V_20 -> V_147 )
V_52 -> V_145 ++ ;
} while ( ( V_137 < V_20 -> V_147 ) &&
( ++ V_52 -> V_144 < V_20 -> V_148 ) );
}
static void
F_42 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_149 * V_150 , int V_151 , int V_31 )
{
const struct V_136 * V_23 = & V_37 [ V_31 / V_32 ] ;
struct V_18 * V_52 ;
T_3 V_13 ;
T_1 V_14 = V_23 -> V_14 ;
V_52 = F_13 ( V_22 , V_31 ) ;
if ( ! V_52 -> V_75 )
F_40 ( V_20 , V_22 , V_31 ) ;
if ( V_52 -> V_33 < F_15 ( 20 , 100 ) || ! V_52 -> V_144 ) {
V_150 -> V_12 [ V_151 ] . V_80 = 2 ;
V_150 -> V_12 [ V_151 ] . V_152 = 2 ;
V_150 -> V_12 [ V_151 ] . V_153 = 2 ;
} else {
V_150 -> V_12 [ V_151 ] . V_80 = V_52 -> V_144 ;
V_150 -> V_12 [ V_151 ] . V_153 = V_52 -> V_144 ;
V_150 -> V_12 [ V_151 ] . V_152 = V_52 -> V_145 ;
}
if ( V_31 / V_32 == V_26 )
V_13 = V_20 -> V_27 [ V_31 % F_12 ( V_20 -> V_27 ) ] ;
else if ( V_14 & V_25 )
V_13 = ( ( V_23 -> V_68 - 1 ) << 4 ) |
( ( V_31 % V_32 ) & 0xF ) ;
else
V_13 = V_31 % V_32 + ( V_23 -> V_68 - 1 ) * 8 ;
if ( V_151 > 0 ||
( V_22 -> V_94 -> V_154 == V_155 &&
V_23 -> V_68 > 1 ) ) {
V_150 -> V_12 [ V_151 ] . V_80 = V_150 -> V_12 [ V_151 ] . V_152 ;
V_14 |= V_156 ;
}
V_150 -> V_12 [ V_151 ] . V_13 = V_13 ;
V_150 -> V_12 [ V_151 ] . V_14 = V_14 ;
}
static inline int
F_43 ( struct V_21 * V_22 , int V_12 )
{
int V_23 = V_12 / V_32 ;
V_12 %= V_32 ;
return V_22 -> V_29 [ V_23 ] . V_30 [ V_12 ] . V_33 ;
}
static int
F_44 ( struct V_21 * V_22 )
{
int V_23 = V_22 -> V_58 / V_32 ;
const struct V_136 * V_157 = & V_37 [ V_23 ] ;
int V_12 = V_22 -> V_58 % V_32 ;
if ( V_22 -> V_29 [ V_23 ] . V_30 [ V_12 ] . V_33 < F_15 ( 50 , 100 ) )
return 1 ;
if ( V_157 -> V_38 [ V_12 ] > F_45 ( 1 , 0 , 52 ) )
return 500 ;
if ( V_157 -> V_38 [ V_12 ] > F_45 ( 1 , 0 , 104 ) )
return 1600 ;
if ( V_157 -> V_38 [ V_12 ] > F_45 ( 1 , 0 , 260 ) ||
( F_43 ( V_22 , V_22 -> V_59 [ 0 ] ) <
F_15 ( 75 , 100 ) ) )
return 3200 ;
if ( ! V_22 -> V_94 -> V_158 . V_159 )
return V_160 ;
return 0 ;
}
static void
F_39 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_149 * V_30 ;
int V_65 = 0 ;
V_30 = F_46 ( sizeof( * V_30 ) , V_161 ) ;
if ( ! V_30 )
return;
F_42 ( V_20 , V_22 , V_30 , V_65 ++ , V_22 -> V_59 [ 0 ] ) ;
if ( V_20 -> V_162 -> V_163 >= 3 ) {
F_42 ( V_20 , V_22 , V_30 , V_65 ++ , V_22 -> V_59 [ 1 ] ) ;
}
if ( V_20 -> V_162 -> V_163 >= 2 ) {
F_42 ( V_20 , V_22 , V_30 , V_65 ++ , V_22 -> V_58 ) ;
}
V_22 -> V_94 -> V_164 = F_44 ( V_22 ) ;
V_30 -> V_12 [ V_65 ] . V_13 = - 1 ;
F_47 ( V_20 -> V_162 , V_22 -> V_94 , V_30 ) ;
}
static inline int
F_48 ( int V_31 )
{
const struct V_136 * V_23 = & V_37 [ V_31 / V_32 ] ;
return V_23 -> V_38 [ V_31 % V_32 ] ;
}
static int
F_49 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_18 * V_52 ;
struct V_50 * V_51 ;
unsigned int V_165 , V_81 , V_166 ;
int V_167 , V_168 ;
int V_169 = 0 ;
if ( V_22 -> V_127 > 0 ) {
V_22 -> V_127 -- ;
return - 1 ;
}
if ( ! V_22 -> V_128 )
return - 1 ;
V_81 = V_22 -> V_81 ;
V_51 = & V_22 -> V_29 [ V_81 ] ;
V_169 = V_83 [ V_51 -> V_82 ] [ V_51 -> V_31 ] ;
F_26 ( V_22 ) ;
if ( ! ( V_22 -> V_28 [ V_81 ] & F_2 ( V_169 ) ) )
return - 1 ;
V_52 = & V_51 -> V_30 [ V_169 ] ;
V_169 += V_81 * V_32 ;
if ( F_48 ( V_22 -> V_59 [ 0 ] ) >
F_48 ( V_22 -> V_59 [ 1 ] ) ) {
V_167 = V_22 -> V_59 [ 1 ] ;
V_168 = V_22 -> V_59 [ 0 ] ;
} else {
V_167 = V_22 -> V_59 [ 0 ] ;
V_168 = V_22 -> V_59 [ 1 ] ;
}
if ( V_169 == V_22 -> V_59 [ 0 ] || V_169 == V_22 -> V_58 )
return - 1 ;
if ( V_52 -> V_33 > F_15 ( 95 , 100 ) )
return - 1 ;
V_166 = V_37 [ V_167 /
V_32 ] . V_68 ;
V_165 = F_48 ( V_169 ) ;
if ( V_165 >= F_48 ( V_168 ) &&
( V_166 - 1 <
V_37 [ V_81 ] . V_68 ||
V_165 >= F_48 ( V_22 -> V_58 ) ) ) {
if ( V_52 -> V_170 < 20 )
return - 1 ;
if ( V_22 -> V_73 ++ > 2 )
return - 1 ;
}
V_22 -> V_128 -- ;
return V_169 ;
}
static void
F_50 ( void * V_103 , struct V_86 * V_94 , void * V_106 ,
struct V_171 * V_172 )
{
const struct V_136 * V_81 ;
struct V_109 * V_110 = F_51 ( V_172 -> V_89 ) ;
struct V_11 * V_12 = & V_110 -> V_115 . V_30 [ 0 ] ;
struct V_111 * V_112 = V_106 ;
struct V_21 * V_22 = & V_112 -> V_113 ;
struct V_19 * V_20 = V_103 ;
int V_169 ;
if ( F_52 ( V_94 , V_106 , V_172 ) )
return;
if ( ! V_112 -> V_119 )
return V_120 . V_173 ( V_103 , V_94 , & V_112 -> V_122 , V_172 ) ;
if ( ! ( V_110 -> V_14 & V_123 ) &&
V_22 -> V_58 / V_32 != V_26 )
F_28 ( V_94 , V_172 -> V_89 ) ;
V_110 -> V_14 |= V_22 -> V_174 ;
#ifdef F_24
if ( V_20 -> V_77 != - 1 )
return;
#endif
if ( V_20 -> V_162 -> V_163 == 1 &&
( V_110 -> V_175 . V_14 & V_176 ) )
V_169 = - 1 ;
else
V_169 = F_49 ( V_20 , V_22 ) ;
V_22 -> V_177 ++ ;
if ( V_22 -> V_177 == ~ 0 ) {
V_22 -> V_177 = 0 ;
V_22 -> V_130 = 0 ;
}
if ( V_169 < 0 )
return;
V_81 = & V_37 [ V_169 / V_32 ] ;
V_110 -> V_14 |= V_129 ;
V_12 -> V_80 = 1 ;
if ( V_169 / V_32 == V_26 ) {
int V_13 = V_169 % F_12 ( V_20 -> V_27 ) ;
V_12 -> V_13 = V_20 -> V_27 [ V_13 ] ;
} else if ( V_81 -> V_14 & V_25 ) {
F_53 ( V_12 , V_169 % V_32 ,
V_81 -> V_68 ) ;
} else {
V_12 -> V_13 = V_169 % V_32 +
( V_81 -> V_68 - 1 ) * 8 ;
}
V_12 -> V_14 = V_81 -> V_14 ;
}
static void
F_54 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_104 * V_105 ,
struct V_86 * V_94 )
{
int V_65 ;
if ( V_105 -> V_178 != V_179 )
return;
if ( ! F_55 ( V_20 -> V_162 , V_180 ) )
return;
V_22 -> V_181 = 0 ;
V_22 -> V_182 = 0 ;
for ( V_65 = 0 ; V_65 < 4 ; V_65 ++ ) {
if ( ! F_56 ( V_94 , V_105 -> V_178 , V_20 -> V_27 [ V_65 ] ) )
continue;
V_22 -> V_181 |= F_2 ( V_65 ) ;
if ( V_105 -> V_183 [ V_65 ] . V_14 & V_184 )
V_22 -> V_182 |= F_2 ( V_65 ) ;
}
V_22 -> V_28 [ V_26 ] = V_22 -> V_181 ;
}
static void
F_57 ( void * V_103 , struct V_104 * V_105 ,
struct V_185 * V_186 ,
struct V_86 * V_94 , void * V_106 )
{
struct V_19 * V_20 = V_103 ;
struct V_111 * V_112 = V_106 ;
struct V_21 * V_22 = & V_112 -> V_113 ;
struct V_187 * V_188 = & V_94 -> V_189 . V_188 ;
T_1 V_190 = V_94 -> V_189 . V_191 ;
struct V_192 * V_158 = & V_94 -> V_158 ;
struct V_93 * V_193 = F_29 ( V_94 , struct V_93 , V_94 ) ;
int V_194 ;
int V_195 = 0 ;
int V_196 ;
int V_197 ;
int V_65 ;
if ( ! V_94 -> V_189 . V_198 )
goto V_199;
F_58 ( F_12 ( V_37 ) != V_200 ) ;
#ifdef F_59
if ( V_158 -> V_159 )
V_194 = V_158 -> V_201 . V_202 != F_60 ( ~ 0 ) ;
else
#endif
V_194 = 0 ;
V_112 -> V_119 = true ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_94 = V_94 ;
V_22 -> V_78 = V_79 ;
V_196 = F_61 ( V_105 -> V_178 , 10 , 60 , 1 , 1 , 0 ) ;
V_22 -> V_35 = F_61 ( V_105 -> V_178 , 0 , 60 , 1 , 1 , 0 ) ;
V_22 -> V_35 += V_196 ;
V_22 -> V_143 = V_22 -> V_35 + 2 * V_196 ;
V_22 -> V_36 = F_15 ( 1 , 1 ) ;
if ( V_20 -> V_203 ) {
V_22 -> V_74 = 16 ;
V_22 -> V_127 = 0 ;
} else {
V_22 -> V_74 = 8 ;
V_22 -> V_127 = 8 ;
}
V_22 -> V_128 = 4 ;
if ( ! V_194 ) {
V_197 = ( V_190 & V_204 ) >>
V_205 ;
V_22 -> V_174 |= V_197 << V_206 ;
if ( V_190 & V_207 )
V_22 -> V_174 |= V_208 ;
}
for ( V_65 = 0 ; V_65 < F_12 ( V_22 -> V_29 ) ; V_65 ++ ) {
T_4 V_209 = V_37 [ V_65 ] . V_14 ;
int V_1 , V_2 ;
V_22 -> V_28 [ V_65 ] = 0 ;
if ( V_65 == V_26 ) {
F_54 ( V_20 , V_22 , V_105 , V_94 ) ;
continue;
}
if ( V_209 & V_15 ) {
if ( V_209 & V_16 ) {
if ( ! ( V_190 & V_210 ) )
continue;
} else {
if ( ! ( V_190 & V_211 ) )
continue;
}
}
if ( V_209 & V_16 &&
V_94 -> V_212 < V_213 )
continue;
V_2 = V_37 [ V_65 ] . V_68 ;
if ( V_94 -> V_154 == V_214 && V_2 > 1 )
continue;
if ( V_209 & V_24 ) {
#ifdef F_59
if ( V_194 && V_215 )
continue;
#endif
V_22 -> V_28 [ V_65 ] = V_188 -> V_216 [ V_2 - 1 ] ;
if ( V_22 -> V_28 [ V_65 ] )
V_195 ++ ;
continue;
}
if ( ! V_158 -> V_159 ||
F_3 ( ! ( V_209 & V_25 ) ) ||
F_3 ( V_209 & V_217 ) )
continue;
if ( V_209 & V_17 ) {
if ( V_94 -> V_212 < V_218 ||
( ( V_209 & V_15 ) &&
! ( V_158 -> V_191 & V_219 ) ) ) {
continue;
}
}
if ( V_209 & V_16 )
V_1 = V_7 ;
else if ( V_209 & V_17 )
V_1 = V_6 ;
else
V_1 = V_5 ;
V_22 -> V_28 [ V_65 ] = F_1 ( V_1 , V_2 ,
V_158 -> V_201 . V_202 ) ;
if ( V_22 -> V_28 [ V_65 ] )
V_195 ++ ;
}
if ( ! V_195 )
goto V_199;
if ( F_62 ( V_193 , V_220 ) )
V_22 -> V_182 |= V_22 -> V_182 << 4 ;
F_21 ( V_20 , V_22 ) ;
F_39 ( V_20 , V_22 ) ;
return;
V_199:
V_112 -> V_119 = false ;
memset ( & V_112 -> V_122 , 0 , sizeof( V_112 -> V_122 ) ) ;
V_112 -> V_122 . V_221 = V_112 -> V_222 ;
V_112 -> V_122 . V_83 = V_112 -> V_83 ;
return V_120 . V_223 ( V_103 , V_105 , V_186 , V_94 ,
& V_112 -> V_122 ) ;
}
static void
F_63 ( void * V_103 , struct V_104 * V_105 ,
struct V_185 * V_186 ,
struct V_86 * V_94 , void * V_106 )
{
F_57 ( V_103 , V_105 , V_186 , V_94 , V_106 ) ;
}
static void
F_64 ( void * V_103 , struct V_104 * V_105 ,
struct V_185 * V_186 ,
struct V_86 * V_94 , void * V_106 ,
T_4 V_224 )
{
F_57 ( V_103 , V_105 , V_186 , V_94 , V_106 ) ;
}
static void *
F_65 ( void * V_103 , struct V_86 * V_94 , T_5 V_225 )
{
struct V_104 * V_105 ;
struct V_111 * V_112 ;
struct V_19 * V_20 = V_103 ;
struct V_226 * V_162 = V_20 -> V_162 ;
int V_163 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_227 ; V_65 ++ ) {
V_105 = V_162 -> V_228 -> V_229 [ V_65 ] ;
if ( V_105 && V_105 -> V_230 > V_163 )
V_163 = V_105 -> V_230 ;
}
V_112 = F_46 ( sizeof( * V_112 ) , V_225 ) ;
if ( ! V_112 )
return NULL ;
V_112 -> V_222 = F_46 ( sizeof( struct V_231 ) * V_163 , V_225 ) ;
if ( ! V_112 -> V_222 )
goto error;
V_112 -> V_83 = F_66 ( V_232 * V_163 , V_225 ) ;
if ( ! V_112 -> V_83 )
goto V_233;
return V_112 ;
V_233:
F_67 ( V_112 -> V_222 ) ;
error:
F_67 ( V_112 ) ;
return NULL ;
}
static void
F_68 ( void * V_103 , struct V_86 * V_94 , void * V_106 )
{
struct V_111 * V_112 = V_106 ;
F_67 ( V_112 -> V_83 ) ;
F_67 ( V_112 -> V_222 ) ;
F_67 ( V_112 ) ;
}
static void *
F_69 ( struct V_226 * V_162 , struct V_234 * V_235 )
{
return V_120 . V_236 ( V_162 , V_235 ) ;
}
static void
F_70 ( void * V_103 )
{
V_120 . free ( V_103 ) ;
}
static T_4 F_71 ( void * V_106 )
{
struct V_111 * V_112 = V_106 ;
struct V_21 * V_22 = & V_112 -> V_113 ;
int V_65 , V_48 , V_237 , V_238 ;
if ( ! V_112 -> V_119 )
return V_120 . V_239 ( V_106 ) ;
V_65 = V_22 -> V_59 [ 0 ] / V_32 ;
V_48 = V_22 -> V_59 [ 0 ] % V_32 ;
V_237 = V_22 -> V_29 [ V_65 ] . V_30 [ V_48 ] . V_33 ;
V_238 = F_14 ( V_22 , V_65 , V_48 , V_237 ) * 10 ;
V_238 = V_238 * V_240 * 8 / 1024 ;
return V_238 ;
}
static void T_6 F_72 ( void )
{
int V_241 , V_65 , V_242 ;
T_3 V_243 [ V_32 ] ;
memset ( V_83 , 0xff , sizeof( V_83 ) ) ;
for ( V_241 = 0 ; V_241 < V_232 ; V_241 ++ ) {
F_73 ( V_243 , sizeof( V_243 ) ) ;
for ( V_65 = 0 ; V_65 < V_32 ; V_65 ++ ) {
V_242 = ( V_65 + V_243 [ V_65 ] ) % V_32 ;
while ( V_83 [ V_241 ] [ V_242 ] != 0xff )
V_242 = ( V_242 + 1 ) % V_32 ;
V_83 [ V_241 ] [ V_242 ] = V_65 ;
}
}
}
int T_6
F_74 ( void )
{
F_72 () ;
return F_75 ( & V_244 ) ;
}
void
F_76 ( void )
{
F_77 ( & V_244 ) ;
}
