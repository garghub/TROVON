static void F_1 (
T_1 * V_1 ,
int V_2 ,
int V_3
)
{
F_2 ( ( V_4 , L_1 , V_3 , V_2 ) ) ;
Assert ( V_3 > 0 && V_3 <= 15 , L_2 ) ;
V_1 -> V_5 += ( V_6 ) V_3 ;
if ( V_1 -> V_7 > ( int ) V_8 - V_3 ) {
V_1 -> V_9 |= ( V_2 << V_1 -> V_7 ) ;
F_3 ( V_1 , V_1 -> V_9 ) ;
V_1 -> V_9 = ( V_10 ) V_2 >> ( V_8 - V_1 -> V_7 ) ;
V_1 -> V_7 += V_3 - V_8 ;
} else {
V_1 -> V_9 |= V_2 << V_1 -> V_7 ;
V_1 -> V_7 += V_3 ;
}
}
static void F_4 ( void )
{
static int V_11 ;
int V_12 ;
int V_13 ;
int V_3 ;
int V_14 ;
int V_15 ;
V_10 V_16 [ V_17 + 1 ] ;
if ( V_11 ) return;
V_3 = 0 ;
for ( V_14 = 0 ; V_14 < V_18 - 1 ; V_14 ++ ) {
V_19 [ V_14 ] = V_3 ;
for ( V_12 = 0 ; V_12 < ( 1 << V_20 [ V_14 ] ) ; V_12 ++ ) {
V_21 [ V_3 ++ ] = ( V_22 ) V_14 ;
}
}
Assert ( V_3 == 256 , L_3 ) ;
V_21 [ V_3 - 1 ] = ( V_22 ) V_14 ;
V_15 = 0 ;
for ( V_14 = 0 ; V_14 < 16 ; V_14 ++ ) {
V_23 [ V_14 ] = V_15 ;
for ( V_12 = 0 ; V_12 < ( 1 << V_24 [ V_14 ] ) ; V_12 ++ ) {
V_25 [ V_15 ++ ] = ( V_22 ) V_14 ;
}
}
Assert ( V_15 == 256 , L_4 ) ;
V_15 >>= 7 ;
for ( ; V_14 < V_26 ; V_14 ++ ) {
V_23 [ V_14 ] = V_15 << 7 ;
for ( V_12 = 0 ; V_12 < ( 1 << ( V_24 [ V_14 ] - 7 ) ) ; V_12 ++ ) {
V_25 [ 256 + V_15 ++ ] = ( V_22 ) V_14 ;
}
}
Assert ( V_15 == 256 , L_5 ) ;
for ( V_13 = 0 ; V_13 <= V_17 ; V_13 ++ ) V_16 [ V_13 ] = 0 ;
V_12 = 0 ;
while ( V_12 <= 143 ) V_27 [ V_12 ++ ] . V_28 = 8 , V_16 [ 8 ] ++ ;
while ( V_12 <= 255 ) V_27 [ V_12 ++ ] . V_28 = 9 , V_16 [ 9 ] ++ ;
while ( V_12 <= 279 ) V_27 [ V_12 ++ ] . V_28 = 7 , V_16 [ 7 ] ++ ;
while ( V_12 <= 287 ) V_27 [ V_12 ++ ] . V_28 = 8 , V_16 [ 8 ] ++ ;
F_5 ( ( V_29 * ) V_27 , V_30 + 1 , V_16 ) ;
for ( V_12 = 0 ; V_12 < V_26 ; V_12 ++ ) {
V_31 [ V_12 ] . V_28 = 5 ;
V_31 [ V_12 ] . V_32 = F_6 ( ( V_33 ) V_12 ) >> ( 32 - 5 ) ;
}
V_11 = 1 ;
}
void F_7 (
T_1 * V_1
)
{
F_4 () ;
V_1 -> V_34 = 0L ;
V_1 -> V_35 . V_36 = V_1 -> V_37 ;
V_1 -> V_35 . V_38 = & V_39 ;
V_1 -> V_40 . V_36 = V_1 -> V_41 ;
V_1 -> V_40 . V_38 = & V_42 ;
V_1 -> V_43 . V_36 = V_1 -> V_44 ;
V_1 -> V_43 . V_38 = & V_45 ;
V_1 -> V_9 = 0 ;
V_1 -> V_7 = 0 ;
V_1 -> V_46 = 8 ;
#ifdef F_8
V_1 -> V_5 = 0L ;
#endif
F_9 ( V_1 ) ;
}
static void F_9 (
T_1 * V_1
)
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_30 ; V_12 ++ ) V_1 -> V_37 [ V_12 ] . V_47 = 0 ;
for ( V_12 = 0 ; V_12 < V_26 ; V_12 ++ ) V_1 -> V_41 [ V_12 ] . V_47 = 0 ;
for ( V_12 = 0 ; V_12 < V_48 ; V_12 ++ ) V_1 -> V_44 [ V_12 ] . V_47 = 0 ;
V_1 -> V_37 [ V_49 ] . V_47 = 1 ;
V_1 -> V_50 = V_1 -> V_51 = 0L ;
V_1 -> V_52 = V_1 -> V_53 = 0 ;
}
static void F_10 (
T_1 * V_1 ,
V_29 * V_54 ,
int V_55
)
{
int V_56 = V_1 -> V_57 [ V_55 ] ;
int V_58 = V_55 << 1 ;
while ( V_58 <= V_1 -> V_59 ) {
if ( V_58 < V_1 -> V_59 &&
F_11 ( V_54 , V_1 -> V_57 [ V_58 + 1 ] , V_1 -> V_57 [ V_58 ] , V_1 -> V_60 ) ) {
V_58 ++ ;
}
if ( F_11 ( V_54 , V_56 , V_1 -> V_57 [ V_58 ] , V_1 -> V_60 ) ) break;
V_1 -> V_57 [ V_55 ] = V_1 -> V_57 [ V_58 ] ; V_55 = V_58 ;
V_58 <<= 1 ;
}
V_1 -> V_57 [ V_55 ] = V_56 ;
}
static void F_12 (
T_1 * V_1 ,
T_2 * V_61
)
{
V_29 * V_54 = V_61 -> V_36 ;
int V_62 = V_61 -> V_62 ;
const V_29 * V_63 = V_61 -> V_38 -> V_64 ;
const int * V_65 = V_61 -> V_38 -> V_66 ;
int V_67 = V_61 -> V_38 -> V_68 ;
int V_69 = V_61 -> V_38 -> V_69 ;
int V_70 ;
int V_12 , V_71 ;
int V_13 ;
int V_72 ;
V_10 V_73 ;
int V_74 = 0 ;
for ( V_13 = 0 ; V_13 <= V_17 ; V_13 ++ ) V_1 -> V_16 [ V_13 ] = 0 ;
V_54 [ V_1 -> V_57 [ V_1 -> V_75 ] ] . V_28 = 0 ;
for ( V_70 = V_1 -> V_75 + 1 ; V_70 < V_76 ; V_70 ++ ) {
V_12 = V_1 -> V_57 [ V_70 ] ;
V_13 = V_54 [ V_54 [ V_12 ] . V_77 ] . V_28 + 1 ;
if ( V_13 > V_69 ) V_13 = V_69 , V_74 ++ ;
V_54 [ V_12 ] . V_28 = ( V_10 ) V_13 ;
if ( V_12 > V_62 ) continue;
V_1 -> V_16 [ V_13 ] ++ ;
V_72 = 0 ;
if ( V_12 >= V_67 ) V_72 = V_65 [ V_12 - V_67 ] ;
V_73 = V_54 [ V_12 ] . V_47 ;
V_1 -> V_50 += ( V_6 ) V_73 * ( V_13 + V_72 ) ;
if ( V_63 ) V_1 -> V_51 += ( V_6 ) V_73 * ( V_63 [ V_12 ] . V_28 + V_72 ) ;
}
if ( V_74 == 0 ) return;
F_13 ( ( V_4 , L_6 ) ) ;
do {
V_13 = V_69 - 1 ;
while ( V_1 -> V_16 [ V_13 ] == 0 ) V_13 -- ;
V_1 -> V_16 [ V_13 ] -- ;
V_1 -> V_16 [ V_13 + 1 ] += 2 ;
V_1 -> V_16 [ V_69 ] -- ;
V_74 -= 2 ;
} while ( V_74 > 0 );
for ( V_13 = V_69 ; V_13 != 0 ; V_13 -- ) {
V_12 = V_1 -> V_16 [ V_13 ] ;
while ( V_12 != 0 ) {
V_71 = V_1 -> V_57 [ -- V_70 ] ;
if ( V_71 > V_62 ) continue;
if ( V_54 [ V_71 ] . V_28 != ( unsigned ) V_13 ) {
F_13 ( ( V_4 , L_7 , V_71 , V_54 [ V_71 ] . V_28 , V_13 ) ) ;
V_1 -> V_50 += ( ( long ) V_13 - ( long ) V_54 [ V_71 ] . V_28 )
* ( long ) V_54 [ V_71 ] . V_47 ;
V_54 [ V_71 ] . V_28 = ( V_10 ) V_13 ;
}
V_12 -- ;
}
}
}
static void F_5 (
V_29 * V_54 ,
int V_62 ,
V_10 * V_16
)
{
V_10 V_78 [ V_17 + 1 ] ;
V_10 V_14 = 0 ;
int V_13 ;
int V_12 ;
for ( V_13 = 1 ; V_13 <= V_17 ; V_13 ++ ) {
V_78 [ V_13 ] = V_14 = ( V_14 + V_16 [ V_13 - 1 ] ) << 1 ;
}
Assert ( V_14 + V_16 [ V_17 ] - 1 == ( 1 << V_17 ) - 1 ,
L_8 ) ;
F_14 ( ( V_4 , L_9 , V_62 ) ) ;
for ( V_12 = 0 ; V_12 <= V_62 ; V_12 ++ ) {
int V_79 = V_54 [ V_12 ] . V_28 ;
if ( V_79 == 0 ) continue;
V_54 [ V_12 ] . V_32 = F_6 ( ( V_33 ) ( V_78 [ V_79 ] ++ ) ) >> ( 32 - V_79 ) ;
F_15 ( V_54 != V_27 , ( V_4 , L_10 ,
V_12 , ( isgraph ( V_12 ) ? V_12 : ' ' ) , V_79 , V_54 [ V_12 ] . V_32 , V_78 [ V_79 ] - 1 ) ) ;
}
}
static void F_16 (
T_1 * V_1 ,
T_2 * V_61
)
{
V_29 * V_54 = V_61 -> V_36 ;
const V_29 * V_63 = V_61 -> V_38 -> V_64 ;
int V_80 = V_61 -> V_38 -> V_80 ;
int V_12 , V_71 ;
int V_62 = - 1 ;
int V_81 ;
V_1 -> V_59 = 0 , V_1 -> V_75 = V_76 ;
for ( V_12 = 0 ; V_12 < V_80 ; V_12 ++ ) {
if ( V_54 [ V_12 ] . V_47 != 0 ) {
V_1 -> V_57 [ ++ ( V_1 -> V_59 ) ] = V_62 = V_12 ;
V_1 -> V_60 [ V_12 ] = 0 ;
} else {
V_54 [ V_12 ] . V_28 = 0 ;
}
}
while ( V_1 -> V_59 < 2 ) {
V_81 = V_1 -> V_57 [ ++ ( V_1 -> V_59 ) ] = ( V_62 < 2 ? ++ V_62 : 0 ) ;
V_54 [ V_81 ] . V_47 = 1 ;
V_1 -> V_60 [ V_81 ] = 0 ;
V_1 -> V_50 -- ; if ( V_63 ) V_1 -> V_51 -= V_63 [ V_81 ] . V_28 ;
}
V_61 -> V_62 = V_62 ;
for ( V_12 = V_1 -> V_59 / 2 ; V_12 >= 1 ; V_12 -- ) F_10 ( V_1 , V_54 , V_12 ) ;
V_81 = V_80 ;
do {
F_17 ( V_1 , V_54 , V_12 ) ;
V_71 = V_1 -> V_57 [ V_82 ] ;
V_1 -> V_57 [ -- ( V_1 -> V_75 ) ] = V_12 ;
V_1 -> V_57 [ -- ( V_1 -> V_75 ) ] = V_71 ;
V_54 [ V_81 ] . V_47 = V_54 [ V_12 ] . V_47 + V_54 [ V_71 ] . V_47 ;
V_1 -> V_60 [ V_81 ] = ( V_22 ) ( F_18 ( V_1 -> V_60 [ V_12 ] , V_1 -> V_60 [ V_71 ] ) + 1 ) ;
V_54 [ V_12 ] . V_77 = V_54 [ V_71 ] . V_77 = ( V_10 ) V_81 ;
#ifdef F_19
if ( V_54 == V_1 -> V_44 ) {
fprintf ( V_4 , L_11 ,
V_81 , V_54 [ V_81 ] . V_47 , V_12 , V_54 [ V_12 ] . V_47 , V_71 , V_54 [ V_71 ] . V_47 ) ;
}
#endif
V_1 -> V_57 [ V_82 ] = V_81 ++ ;
F_10 ( V_1 , V_54 , V_82 ) ;
} while ( V_1 -> V_59 >= 2 );
V_1 -> V_57 [ -- ( V_1 -> V_75 ) ] = V_1 -> V_57 [ V_82 ] ;
F_12 ( V_1 , ( T_2 * ) V_61 ) ;
F_5 ( ( V_29 * ) V_54 , V_62 , V_1 -> V_16 ) ;
}
static void F_20 (
T_1 * V_1 ,
V_29 * V_54 ,
int V_62
)
{
int V_12 ;
int V_83 = - 1 ;
int V_84 ;
int V_85 = V_54 [ 0 ] . V_28 ;
int V_86 = 0 ;
int V_87 = 7 ;
int V_88 = 4 ;
if ( V_85 == 0 ) V_87 = 138 , V_88 = 3 ;
V_54 [ V_62 + 1 ] . V_28 = ( V_10 ) 0xffff ;
for ( V_12 = 0 ; V_12 <= V_62 ; V_12 ++ ) {
V_84 = V_85 ; V_85 = V_54 [ V_12 + 1 ] . V_28 ;
if ( ++ V_86 < V_87 && V_84 == V_85 ) {
continue;
} else if ( V_86 < V_88 ) {
V_1 -> V_44 [ V_84 ] . V_47 += V_86 ;
} else if ( V_84 != 0 ) {
if ( V_84 != V_83 ) V_1 -> V_44 [ V_84 ] . V_47 ++ ;
V_1 -> V_44 [ V_89 ] . V_47 ++ ;
} else if ( V_86 <= 10 ) {
V_1 -> V_44 [ V_90 ] . V_47 ++ ;
} else {
V_1 -> V_44 [ V_91 ] . V_47 ++ ;
}
V_86 = 0 ; V_83 = V_84 ;
if ( V_85 == 0 ) {
V_87 = 138 , V_88 = 3 ;
} else if ( V_84 == V_85 ) {
V_87 = 6 , V_88 = 3 ;
} else {
V_87 = 7 , V_88 = 4 ;
}
}
}
static void F_21 (
T_1 * V_1 ,
V_29 * V_54 ,
int V_62
)
{
int V_12 ;
int V_83 = - 1 ;
int V_84 ;
int V_85 = V_54 [ 0 ] . V_28 ;
int V_86 = 0 ;
int V_87 = 7 ;
int V_88 = 4 ;
if ( V_85 == 0 ) V_87 = 138 , V_88 = 3 ;
for ( V_12 = 0 ; V_12 <= V_62 ; V_12 ++ ) {
V_84 = V_85 ; V_85 = V_54 [ V_12 + 1 ] . V_28 ;
if ( ++ V_86 < V_87 && V_84 == V_85 ) {
continue;
} else if ( V_86 < V_88 ) {
do { F_22 ( V_1 , V_84 , V_1 -> V_44 ) ; } while ( -- V_86 != 0 );
} else if ( V_84 != 0 ) {
if ( V_84 != V_83 ) {
F_22 ( V_1 , V_84 , V_1 -> V_44 ) ; V_86 -- ;
}
Assert ( V_86 >= 3 && V_86 <= 6 , L_12 ) ;
F_22 ( V_1 , V_89 , V_1 -> V_44 ) ; F_1 ( V_1 , V_86 - 3 , 2 ) ;
} else if ( V_86 <= 10 ) {
F_22 ( V_1 , V_90 , V_1 -> V_44 ) ; F_1 ( V_1 , V_86 - 3 , 3 ) ;
} else {
F_22 ( V_1 , V_91 , V_1 -> V_44 ) ; F_1 ( V_1 , V_86 - 11 , 7 ) ;
}
V_86 = 0 ; V_83 = V_84 ;
if ( V_85 == 0 ) {
V_87 = 138 , V_88 = 3 ;
} else if ( V_84 == V_85 ) {
V_87 = 6 , V_88 = 3 ;
} else {
V_87 = 7 , V_88 = 4 ;
}
}
}
static int F_23 (
T_1 * V_1
)
{
int V_92 ;
F_20 ( V_1 , ( V_29 * ) V_1 -> V_37 , V_1 -> V_35 . V_62 ) ;
F_20 ( V_1 , ( V_29 * ) V_1 -> V_41 , V_1 -> V_40 . V_62 ) ;
F_16 ( V_1 , ( T_2 * ) ( & ( V_1 -> V_43 ) ) ) ;
for ( V_92 = V_48 - 1 ; V_92 >= 3 ; V_92 -- ) {
if ( V_1 -> V_44 [ V_93 [ V_92 ] ] . V_28 != 0 ) break;
}
V_1 -> V_50 += 3 * ( V_92 + 1 ) + 5 + 5 + 4 ;
F_14 ( ( V_4 , L_13 ,
V_1 -> V_50 , V_1 -> V_51 ) ) ;
return V_92 ;
}
static void F_24 (
T_1 * V_1 ,
int V_94 ,
int V_95 ,
int V_96
)
{
int V_97 ;
Assert ( V_94 >= 257 && V_95 >= 1 && V_96 >= 4 , L_14 ) ;
Assert ( V_94 <= V_30 && V_95 <= V_26 && V_96 <= V_48 ,
L_15 ) ;
F_14 ( ( V_4 , L_16 ) ) ;
F_1 ( V_1 , V_94 - 257 , 5 ) ;
F_1 ( V_1 , V_95 - 1 , 5 ) ;
F_1 ( V_1 , V_96 - 4 , 4 ) ;
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ ) {
F_14 ( ( V_4 , L_17 , V_93 [ V_97 ] ) ) ;
F_1 ( V_1 , V_1 -> V_44 [ V_93 [ V_97 ] ] . V_28 , 3 ) ;
}
F_14 ( ( V_4 , L_18 , V_1 -> V_5 ) ) ;
F_21 ( V_1 , ( V_29 * ) V_1 -> V_37 , V_94 - 1 ) ;
F_14 ( ( V_4 , L_19 , V_1 -> V_5 ) ) ;
F_21 ( V_1 , ( V_29 * ) V_1 -> V_41 , V_95 - 1 ) ;
F_14 ( ( V_4 , L_20 , V_1 -> V_5 ) ) ;
}
void F_25 (
T_1 * V_1 ,
char * V_98 ,
V_6 V_99 ,
int V_100
)
{
F_1 ( V_1 , ( V_101 << 1 ) + V_100 , 3 ) ;
V_1 -> V_34 = ( V_1 -> V_34 + 3 + 7 ) & ( V_6 ) ~ 7L ;
V_1 -> V_34 += ( V_99 + 4 ) << 3 ;
F_26 ( V_1 , V_98 , ( unsigned ) V_99 , 1 ) ;
}
void F_27 (
T_1 * V_1
)
{
F_1 ( V_1 , ( V_101 << 1 ) , 3 ) ;
F_28 ( V_1 ) ;
V_1 -> V_34 = ( V_1 -> V_34 + 3 ) & ~ 7L ;
}
void F_29 (
T_1 * V_1
)
{
F_1 ( V_1 , V_102 << 1 , 3 ) ;
F_22 ( V_1 , V_49 , V_27 ) ;
V_1 -> V_34 += 10L ;
F_30 ( V_1 ) ;
if ( 1 + V_1 -> V_46 + 10 - V_1 -> V_7 < 9 ) {
F_1 ( V_1 , V_102 << 1 , 3 ) ;
F_22 ( V_1 , V_49 , V_27 ) ;
V_1 -> V_34 += 10L ;
F_30 ( V_1 ) ;
}
V_1 -> V_46 = 7 ;
}
int F_31 (
T_1 * V_1 ,
unsigned V_15 ,
unsigned V_103
)
{
V_1 -> V_104 [ V_1 -> V_52 ] = ( V_10 ) V_15 ;
V_1 -> V_105 [ V_1 -> V_52 ++ ] = ( V_22 ) V_103 ;
if ( V_15 == 0 ) {
V_1 -> V_37 [ V_103 ] . V_47 ++ ;
} else {
V_1 -> V_53 ++ ;
V_15 -- ;
Assert ( ( V_10 ) V_15 < ( V_10 ) F_32 ( V_1 ) &&
( V_10 ) V_103 <= ( V_10 ) ( V_106 - V_107 ) &&
( V_10 ) F_33 ( V_15 ) < ( V_10 ) V_26 , L_21 ) ;
V_1 -> V_37 [ V_21 [ V_103 ] + V_108 + 1 ] . V_47 ++ ;
V_1 -> V_41 [ F_33 ( V_15 ) ] . V_47 ++ ;
}
if ( ( V_1 -> V_52 & 0xfff ) == 0 && V_1 -> V_109 > 2 ) {
V_6 V_110 = ( V_6 ) V_1 -> V_52 * 8L ;
V_6 V_111 = ( V_6 ) ( ( long ) V_1 -> V_112 - V_1 -> V_113 ) ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_26 ; V_114 ++ ) {
V_110 += ( V_6 ) V_1 -> V_41 [ V_114 ] . V_47 *
( 5L + V_24 [ V_114 ] ) ;
}
V_110 >>= 3 ;
F_14 ( ( V_4 , L_22 ,
V_1 -> V_52 , V_111 , V_110 ,
100L - V_110 * 100L / V_111 ) ) ;
if ( V_1 -> V_53 < V_1 -> V_52 / 2 && V_110 < V_111 / 2 ) return 1 ;
}
return ( V_1 -> V_52 == V_1 -> V_115 - 1 ) ;
}
static void F_34 (
T_1 * V_1 ,
V_29 * V_116 ,
V_29 * V_117
)
{
unsigned V_15 ;
int V_103 ;
unsigned V_118 = 0 ;
unsigned V_14 ;
int V_65 ;
if ( V_1 -> V_52 != 0 ) do {
V_15 = V_1 -> V_104 [ V_118 ] ;
V_103 = V_1 -> V_105 [ V_118 ++ ] ;
if ( V_15 == 0 ) {
F_22 ( V_1 , V_103 , V_116 ) ;
F_15 ( isgraph ( V_103 ) , ( V_4 , L_23 , V_103 ) ) ;
} else {
V_14 = V_21 [ V_103 ] ;
F_22 ( V_1 , V_14 + V_108 + 1 , V_116 ) ;
V_65 = V_20 [ V_14 ] ;
if ( V_65 != 0 ) {
V_103 -= V_19 [ V_14 ] ;
F_1 ( V_1 , V_103 , V_65 ) ;
}
V_15 -- ;
V_14 = F_33 ( V_15 ) ;
Assert ( V_14 < V_26 , L_24 ) ;
F_22 ( V_1 , V_14 , V_117 ) ;
V_65 = V_24 [ V_14 ] ;
if ( V_65 != 0 ) {
V_15 -= V_23 [ V_14 ] ;
F_1 ( V_1 , V_15 , V_65 ) ;
}
}
Assert ( V_1 -> V_119 < V_1 -> V_115 + 2 * V_118 , L_25 ) ;
} while ( V_118 < V_1 -> V_52 );
F_22 ( V_1 , V_49 , V_116 ) ;
V_1 -> V_46 = V_116 [ V_49 ] . V_28 ;
}
static void F_35 (
T_1 * V_1
)
{
int V_12 = 0 ;
unsigned V_120 = 0 ;
unsigned V_121 = 0 ;
while ( V_12 < 7 ) V_121 += V_1 -> V_37 [ V_12 ++ ] . V_47 ;
while ( V_12 < 128 ) V_120 += V_1 -> V_37 [ V_12 ++ ] . V_47 ;
while ( V_12 < V_108 ) V_121 += V_1 -> V_37 [ V_12 ++ ] . V_47 ;
V_1 -> V_122 = ( V_123 ) ( V_121 > ( V_120 >> 2 ) ? V_124 : V_125 ) ;
}
static void F_26 (
T_1 * V_1 ,
char * V_98 ,
unsigned V_79 ,
int V_126
)
{
F_28 ( V_1 ) ;
V_1 -> V_46 = 8 ;
if ( V_126 ) {
F_3 ( V_1 , ( V_10 ) V_79 ) ;
F_3 ( V_1 , ( V_10 ) ~ V_79 ) ;
#ifdef F_8
V_1 -> V_5 += 2 * 16 ;
#endif
}
#ifdef F_8
V_1 -> V_5 += ( V_6 ) V_79 << 3 ;
#endif
memcpy ( & V_1 -> V_127 [ V_1 -> V_119 ] , V_98 , V_79 ) ;
V_1 -> V_119 += V_79 ;
}
