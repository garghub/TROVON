static inline int F_1 ( int V_1 , int V_2 , int V_3 )
{
if ( V_3 == V_4 || V_3 == V_5 || V_1 < V_2 )
return V_1 ;
if ( V_3 == V_6 ) {
F_2 ( V_1 == 0 ,
L_1 ) ;
return V_1 - 1 ;
}
F_2 ( V_3 != V_7 ,
L_2 ,
V_3 ) ;
return V_1 + 1 ;
}
static void F_3 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 = V_9 -> V_15 ;
int V_1 ;
struct V_16 * V_17 ;
V_17 = F_4 ( V_9 -> V_18 , V_10 ) ;
V_14 -> V_19 =
F_5 ( V_17 ) - F_6 ( V_17 ) + V_9 -> V_20 [ V_10 ] ;
if ( V_10 ) {
V_14 -> V_21 = ( V_14 -> V_19 - V_22 ) / ( V_22 + V_23 ) ;
return;
}
V_14 -> V_21 =
F_7 ( V_17 ) + ( ( V_14 -> V_24 == V_6 ) ? 1 : 0 ) -
( ( V_14 -> V_24 == V_7 ) ? 1 : 0 ) ;
V_14 -> V_25 = (struct V_26 * ) ( V_9 -> V_15 + 1 ) ;
memset ( V_14 -> V_25 , 0 , V_14 -> V_21 * sizeof( struct V_26 ) ) ;
V_14 -> V_27 += V_14 -> V_21 * sizeof( struct V_26 ) ;
V_12 = F_8 ( V_17 , 0 ) ;
if ( F_9 ( & ( V_12 -> V_28 ) , V_17 -> V_29 )
&& ( V_14 -> V_24 != V_7 || V_14 -> V_30 ) )
V_14 -> V_25 [ 0 ] . V_31 |= V_32 ;
for ( V_1 = 0 ; V_1 < V_14 -> V_21 ; V_1 ++ ) {
int V_33 ;
struct V_26 * V_34 = V_14 -> V_25 + V_1 ;
int V_35 =
( ( V_1 != V_14 -> V_30 ) ? 0 : 1 ) ;
if ( V_35 && V_14 -> V_24 == V_6 )
continue;
V_33 = F_1 ( V_1 , V_14 -> V_30 ,
V_14 -> V_24 ) ;
V_34 -> V_36 += F_10 ( V_12 + V_33 ) + V_37 ;
V_34 -> V_38 = V_12 + V_33 ;
V_34 -> V_39 = F_11 ( V_17 , V_12 + V_33 ) ;
V_34 -> V_40 = V_14 -> V_27 ;
V_14 -> V_27 +=
F_12 ( V_14 , V_34 , V_35 , V_9 -> V_20 [ 0 ] ) ;
if ( V_9 -> V_41 + V_9 -> V_42 < V_14 -> V_27 )
F_13 ( V_9 -> V_43 , L_3 ,
L_4 ) ;
if ( ! V_35 )
continue;
if ( V_14 -> V_24 == V_4 || V_14 -> V_24 == V_5 ) {
V_14 -> V_25 [ V_1 ] . V_36 += V_9 -> V_20 [ 0 ] ;
V_34 -> V_44 = V_14 -> V_45 ;
}
}
if ( V_14 -> V_24 == V_6 ) {
struct V_26 * V_34 = V_14 -> V_25 + V_14 -> V_30 ;
F_2 ( V_14 -> V_46 == NULL ,
L_5 ) ;
V_34 -> V_36 = V_9 -> V_20 [ 0 ] ;
V_34 -> V_38 = V_14 -> V_46 ;
V_34 -> V_39 = V_14 -> V_45 ;
V_34 -> V_40 = V_14 -> V_27 ;
F_12 ( V_14 , V_34 , 0 ,
V_9 -> V_20 [ 0 ] ) ;
}
if ( V_9 -> V_47 [ 0 ] ) {
struct V_48 * V_49 ;
V_49 = F_14 ( V_9 -> V_47 [ 0 ] , V_9 -> V_50 [ 0 ] ) ;
if ( F_9 ( V_49 , V_17 -> V_29 )
&& ( V_14 -> V_24 != V_7
|| V_14 -> V_30 != F_7 ( V_17 ) - 1 ) )
V_14 -> V_25 [ V_14 -> V_21 - 1 ] . V_31 |=
V_51 ;
#ifdef F_15
if ( F_9 ( V_49 , V_17 -> V_29 ) &&
! ( V_14 -> V_24 != V_7
|| V_14 -> V_30 != F_7 ( V_17 ) - 1 ) ) {
if ( !
( F_7 ( V_17 ) == 1
&& F_16 ( F_8 ( V_17 , 0 ) )
&& F_17 ( F_8 ( V_17 , 0 ) ) == 1 ) ) {
F_18 ( V_17 , 0 , - 1 , - 1 ) ;
F_13 ( V_9 -> V_43 , L_6 ,
L_7
L_8 ,
V_49 , V_14 -> V_30 ,
V_14 -> V_24 , V_7 ) ;
}
}
#endif
}
}
static void F_19 ( struct V_8 * V_9 , int V_10 , int V_52 )
{
int V_53 ;
struct V_13 * V_14 = V_9 -> V_15 ;
struct V_26 * V_34 ;
int V_54 , V_55 ;
F_2 ( V_52 < 0 , L_9 , V_52 ) ;
if ( V_10 > 0 ) {
V_9 -> V_56 [ V_10 ] = V_52 / ( V_22 + V_23 ) ;
return;
}
if ( ! V_52 || ! V_14 -> V_21 ) {
V_9 -> V_56 [ V_10 ] = 0 ;
V_9 -> V_57 = - 1 ;
return;
}
F_2 ( ! F_20 ( V_9 -> V_18 , 0 ) ,
L_10 ) ;
V_34 = V_14 -> V_25 ;
if ( ( unsigned int ) V_52 >=
( V_14 -> V_19 -
( ( V_34 -> V_31 & V_32 ) ? V_37 : 0 ) ) ) {
F_2 ( V_14 -> V_24 == V_6 || V_14 -> V_24 == V_4 ,
L_11 ) ;
V_9 -> V_56 [ 0 ] = V_14 -> V_21 ;
V_9 -> V_57 = - 1 ;
return;
}
V_54 = 0 , V_55 = V_37 ;
if ( V_34 -> V_31 & V_32 )
V_54 = - ( ( int ) V_37 ) , V_55 = 0 ;
V_9 -> V_56 [ 0 ] = 0 ;
for ( V_53 = 0 ; V_53 < V_14 -> V_21 ;
V_53 ++ , V_55 = V_37 , V_54 = 0 , V_34 ++ ) {
V_54 += V_34 -> V_36 ;
if ( V_52 >= V_54 ) {
V_52 -= V_54 ;
V_9 -> V_56 [ 0 ] ++ ;
continue;
}
if ( V_52 <= V_55 ) {
V_9 -> V_57 = - 1 ;
return;
}
V_52 -= V_55 ;
V_9 -> V_57 = F_21 ( V_34 , V_52 , 0 , 0 ) ;
if ( V_9 -> V_57 != - 1 )
V_9 -> V_56 [ 0 ] ++ ;
break;
}
return;
}
static void F_22 ( struct V_8 * V_9 , int V_10 , int V_52 )
{
int V_53 ;
struct V_13 * V_14 = V_9 -> V_15 ;
struct V_26 * V_34 ;
int V_54 , V_55 ;
F_2 ( V_52 < 0 , L_12 ) ;
if ( V_10 > 0 ) {
V_9 -> V_58 [ V_10 ] = V_52 / ( V_22 + V_23 ) ;
return;
}
if ( ! V_52 || ! V_14 -> V_21 ) {
V_9 -> V_58 [ V_10 ] = 0 ;
V_9 -> V_59 = - 1 ;
return;
}
F_2 ( ! F_20 ( V_9 -> V_18 , 0 ) ,
L_13 ) ;
V_34 = V_14 -> V_25 + V_14 -> V_21 - 1 ;
if ( ( unsigned int ) V_52 >=
( V_14 -> V_19 -
( ( V_34 -> V_31 & V_51 ) ? V_37 : 0 ) ) ) {
F_2 ( V_14 -> V_24 == V_6 || V_14 -> V_24 == V_4 ,
L_14 ) ;
V_9 -> V_58 [ V_10 ] = V_14 -> V_21 ;
V_9 -> V_59 = - 1 ;
return;
}
V_54 = 0 , V_55 = V_37 ;
if ( V_34 -> V_31 & V_51 )
V_54 = - ( int ) V_37 , V_55 = 0 ;
V_9 -> V_58 [ 0 ] = 0 ;
for ( V_53 = V_14 -> V_21 - 1 ; V_53 >= 0 ;
V_53 -- , V_54 = 0 , V_55 = V_37 , V_34 -- ) {
V_54 += V_34 -> V_36 ;
if ( V_52 >= V_54 ) {
V_52 -= V_54 ;
V_9 -> V_58 [ 0 ] ++ ;
continue;
}
if ( V_52 <= V_55 ) {
V_9 -> V_59 = - 1 ;
return;
}
V_52 -= V_55 ;
V_9 -> V_59 = F_23 ( V_34 , V_52 ) ;
if ( V_9 -> V_59 != - 1 )
V_9 -> V_58 [ 0 ] ++ ;
break;
}
return;
}
static int F_24 ( int V_3 , struct V_8 * V_9 , int V_10 ,
int V_60 , int V_61 ,
int V_62 , int V_63 , short * V_64 , int V_65 )
{
int V_53 ;
int V_52 ;
int V_66 ;
struct V_13 * V_14 = V_9 -> V_15 ;
int V_67 , V_68 , V_69 ;
int V_70 ;
int V_71 ,
V_72 ,
V_73 ,
V_74 ;
int V_75 [ 2 ] ;
V_75 [ 0 ] = - 1 ;
V_75 [ 1 ] = - 1 ;
F_2 ( V_9 -> V_20 [ V_10 ] < 0 || ( V_3 != V_6 && V_3 != V_4 ) ,
L_15 ) ;
V_68 = F_5 ( F_4 ( V_9 -> V_18 , V_10 ) ) ;
V_64 [ 3 ] = - 1 ;
V_64 [ 4 ] = - 1 ;
if ( V_10 > 0 ) {
V_53 = ( ( V_62 - V_60 ) * ( V_23 + V_22 ) + V_22 ) ;
if ( V_53 == V_68 )
return 1 ;
return ( V_53 / V_68 + 1 ) ;
}
V_70 = 1 ;
V_67 = 0 ;
V_52 = V_68 ;
V_71 = V_60 ;
V_73 = ( ( V_61 != - 1 ) ? V_61 : 0 ) ;
V_72 = V_14 -> V_21 - V_62 - 1 ;
V_74 = ( V_63 != - 1 ) ? V_63 : 0 ;
for ( V_53 = V_71 ; V_53 <= V_72 ; V_53 ++ ) {
struct V_26 * V_34 = V_14 -> V_25 + V_53 ;
int V_76 = ( ( V_53 == V_72 ) ? V_74 : 0 ) ;
F_2 ( V_70 > 3 , L_16 ) ;
V_69 = V_34 -> V_36 ;
V_69 -=
F_25 ( V_34 , 0 , V_73 ) ;
V_69 -=
F_25 ( V_34 , 1 , V_76 ) ;
if ( V_67 + V_69 <= V_68 ) {
V_64 [ V_70 - 1 ] ++ ;
V_67 += V_69 ;
V_73 = 0 ;
continue;
}
if ( V_69 > V_68 ) {
F_2 ( F_26 ( V_34 -> V_38 ) ,
L_17
L_18 ,
V_69 , V_68 ) ;
V_65 = 1 ;
}
if ( ! V_65 ) {
V_70 ++ ;
V_53 -- ;
V_67 = 0 ;
continue;
}
{
int V_77 ;
V_77 = V_68 - V_67 - V_37 ;
V_66 =
F_21 ( V_34 , V_77 , V_73 ,
V_76 ) ;
if ( V_66 == - 1 ) {
V_70 ++ , V_53 -- , V_67 = 0 ;
continue;
}
}
V_73 += V_66 ;
V_64 [ V_70 - 1 + 3 ] = V_66 ;
if ( V_70 > 2 )
F_27 ( V_9 -> V_43 , L_19 ,
L_20 ) ;
V_64 [ V_70 - 1 ] ++ ;
V_75 [ V_70 - 1 ] = V_53 ;
V_70 ++ ;
V_71 = V_53 ;
V_53 -- ;
V_67 = 0 ;
}
if ( V_64 [ 4 ] > 0 ) {
int V_78 ;
int V_79 , V_80 ;
int V_81 ;
V_78 = V_75 [ 1 ] ;
V_80 =
( ( V_60 == V_78
&& V_61 != - 1 ) ? V_61 : 0 ) ;
V_79 =
( ( V_72 == V_78
&& V_74 != - 1 ) ? V_74 : 0 ) ;
V_81 =
( ( V_75 [ 0 ] ==
V_75 [ 1 ] ) ? V_64 [ 3 ] : 0 ) ;
V_64 [ 4 ] =
F_28 ( & V_14 -> V_25 [ V_78 ] ) - V_64 [ 4 ] -
V_79 - V_80 - V_81 ;
if ( V_14 -> V_25 [ V_78 ] . V_82 != V_83 &&
V_14 -> V_25 [ V_78 ] . V_82 != V_84 )
F_27 ( V_9 -> V_43 , L_21 ,
L_22 ) ;
}
if ( V_64 [ 3 ] > 0 ) {
int V_78 ;
int V_79 , V_80 ;
int V_85 ;
V_78 = V_75 [ 0 ] ;
V_80 =
( ( V_60 == V_78
&& V_61 != - 1 ) ? V_61 : 0 ) ;
V_79 =
( ( V_72 == V_78
&& V_74 != - 1 ) ? V_74 : 0 ) ;
V_85 =
( ( V_75 [ 0 ] == V_75 [ 1 ]
&& V_64 [ 4 ] != - 1 ) ? V_64 [ 4 ] : 0 ) ;
V_64 [ 3 ] =
F_28 ( & V_14 -> V_25 [ V_78 ] ) - V_64 [ 3 ] -
V_79 - V_80 - V_85 ;
}
return V_70 ;
}
static void F_29 ( struct V_8 * V_9 , int V_10 , int V_56 ,
int V_58 , int V_86 , short * V_87 , int V_88 , int V_89 )
{
V_9 -> V_56 [ V_10 ] = V_56 ;
V_9 -> V_58 [ V_10 ] = V_58 ;
V_9 -> V_90 [ V_10 ] = V_86 ;
if ( V_10 == 0 ) {
if ( V_87 != NULL ) {
V_9 -> V_91 = * V_87 ++ ,
V_9 -> V_92 = * V_87 ++ , V_9 -> V_93 = * V_87 ++ ;
V_9 -> V_94 = * V_87 ++ ;
V_9 -> V_95 = * V_87 ;
}
V_9 -> V_57 = V_88 ;
V_9 -> V_59 = V_89 ;
}
F_30 ( V_9 -> V_43 , V_56 [ V_10 ] , V_56 ) ;
F_30 ( V_9 -> V_43 , V_58 [ V_10 ] , V_58 ) ;
F_30 ( V_9 -> V_43 , V_57 [ V_10 ] , V_88 ) ;
F_30 ( V_9 -> V_43 , V_59 [ V_10 ] , V_89 ) ;
}
static int F_31 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
int V_96 , V_97 ;
int V_98 ;
int V_99 ;
V_96 = V_9 -> V_56 [ 0 ] - ( ( V_9 -> V_57 != - 1 ) ? 1 : 0 ) ;
V_97 = V_9 -> V_58 [ 0 ] - ( ( V_9 -> V_59 != - 1 ) ? 1 : 0 ) ;
V_99 = V_14 -> V_21 ;
V_99 -= ( V_96 + V_97 ) ;
if ( V_99 < 1 ) {
F_29 ( V_9 , 0 , V_96 , V_14 -> V_21 - V_96 , 0 ,
NULL , - 1 , - 1 ) ;
return 1 ;
}
if ( V_99 > 1 || V_9 -> V_57 == - 1 || V_9 -> V_59 == - 1 )
return 0 ;
V_98 = F_28 ( & ( V_14 -> V_25 [ V_96 ] ) ) ;
if ( V_9 -> V_57 + V_9 -> V_59 >= V_98 ) {
F_29 ( V_9 , 0 , V_96 + 1 , V_97 + 1 , 0 , NULL ,
V_9 -> V_57 , - 1 ) ;
return 1 ;
}
return 0 ;
}
static int F_32 ( struct V_8 * V_9 , int V_100 , int V_101 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
int V_55 ;
struct V_16 * V_102 ;
V_102 = F_4 ( V_9 -> V_18 , 0 ) ;
V_55 = 0 ;
if ( V_14 -> V_21 ) {
if ( V_14 -> V_25 [ 0 ] . V_31 & V_32 )
V_55 += V_37 ;
if ( V_14 -> V_25 [ V_14 -> V_21 - 1 ] .
V_31 & V_51 )
V_55 += V_37 ;
} else {
struct V_11 * V_12 ;
F_2 ( F_7 ( V_102 ) != 1 ,
L_23 ,
F_7 ( V_102 ) ) ;
V_12 = F_8 ( V_102 , 0 ) ;
if ( V_9 -> V_47 [ 0 ]
&& ! F_33 ( & ( V_12 -> V_28 ) ,
F_14 ( V_9 -> V_47 [ 0 ] ,
V_9 -> V_50 [ 0 ] ) ) )
if ( F_16 ( V_12 ) ) {
V_55 = V_37 ;
F_2 ( F_34 ( V_12 ) == V_103 ,
L_24 ) ;
}
}
if ( F_5 ( V_102 ) + V_14 -> V_19 <= V_101 + V_100 + V_55 ) {
F_29 ( V_9 , 0 , - 1 , - 1 , - 1 , NULL , - 1 , - 1 ) ;
F_35 ( V_9 -> V_43 , V_104 ) ;
return 1 ;
}
return 0 ;
}
static void F_36 ( struct V_8 * V_9 )
{
int V_53 ;
F_37 ( V_9 -> V_18 ) ;
for ( V_53 = 0 ; V_53 < V_105 ; V_53 ++ ) {
F_38 ( V_9 -> V_106 [ V_53 ] ) ;
F_38 ( V_9 -> V_107 [ V_53 ] ) ;
F_38 ( V_9 -> V_108 [ V_53 ] ) ;
F_38 ( V_9 -> V_109 [ V_53 ] ) ;
F_38 ( V_9 -> V_110 [ V_53 ] ) ;
F_38 ( V_9 -> V_47 [ V_53 ] ) ;
V_9 -> V_106 [ V_53 ] = NULL ;
V_9 -> V_107 [ V_53 ] = NULL ;
V_9 -> V_108 [ V_53 ] = NULL ;
V_9 -> V_109 [ V_53 ] = NULL ;
V_9 -> V_110 [ V_53 ] = NULL ;
V_9 -> V_47 [ V_53 ] = NULL ;
}
}
static int F_39 ( struct V_8 * V_9 , int V_10 )
{
struct V_16 * V_111 ,
* V_17 = F_4 ( V_9 -> V_18 , V_10 ) ;
T_1 * V_112 , V_113 [ V_114 ] = { 0 , } ;
int V_115 , V_116 , V_117 ,
V_118 = V_119 ;
struct V_120 * V_121 = V_9 -> V_43 ;
for ( V_115 = 0 , V_116 = V_9 -> V_122 ;
V_115 < V_10 ; V_115 ++ )
V_116 -=
( V_9 -> V_90 [ V_115 ] ) ? ( V_9 -> V_90 [ V_115 ] -
1 ) : 0 ;
V_117 = ( V_17 ) ? ( V_9 -> V_90 [ V_10 ] - 1 ) : 1 ;
if ( V_117 > V_116 )
V_117 -= V_116 ;
else
return V_119 ;
if ( F_40 ( V_9 , V_113 ,
V_117 ) == V_123 )
return V_123 ;
for ( V_112 = V_113 , V_115 = 0 ;
V_115 < V_117 ; V_112 ++ , V_115 ++ ) {
F_2 ( ! * V_112 ,
L_25 ) ;
V_111 = F_41 ( V_121 , * V_112 ) ;
F_2 ( F_42 ( V_111 ) ||
F_43 ( V_111 ) ||
F_44 ( V_111 ) ,
L_26 ,
V_111 ) ;
F_2 ( V_9 -> V_124 [ V_9 -> V_122 ] ,
L_27 ) ;
F_45 ( V_111 ) ;
V_9 -> V_124 [ V_9 -> V_122 ++ ] = V_111 ;
}
if ( V_118 == V_119 && F_46 ( V_9 ) )
V_118 = V_125 ;
return V_118 ;
}
static int F_47 ( struct V_8 * V_9 , int V_10 )
{
struct V_16 * V_126 , * V_127 ;
int V_128 ;
if ( ( V_127 = F_20 ( V_9 -> V_18 , V_10 ) ) == NULL ||
( V_126 = V_9 -> V_108 [ V_10 ] ) == NULL )
return 0 ;
if ( V_127 == V_126 )
V_128 = F_48 ( V_9 -> V_18 , V_10 ) - 1 ;
else {
V_128 = F_7 ( V_126 ) ;
V_127 = V_126 ;
}
return ( F_5 ( V_127 ) - F_49 ( F_50 ( V_127 , V_128 ) ) ) ;
}
static int F_51 ( struct V_8 * V_9 , int V_10 )
{
struct V_16 * V_129 , * V_127 ;
int V_128 ;
if ( ( V_127 = F_20 ( V_9 -> V_18 , V_10 ) ) == NULL ||
( V_129 = V_9 -> V_109 [ V_10 ] ) == NULL )
return 0 ;
if ( V_127 == V_129 )
V_128 = F_48 ( V_9 -> V_18 , V_10 ) + 1 ;
else {
V_128 = 0 ;
V_127 = V_129 ;
}
return ( F_5 ( V_127 ) - F_49 ( F_50 ( V_127 , V_128 ) ) ) ;
}
static int F_52 ( struct V_8 * V_9 , int V_10 )
{
struct V_16 * V_130 , * V_131 ;
struct V_120 * V_121 = V_9 -> V_43 ;
T_1 V_132 ;
int V_133 ;
if ( ! V_9 -> V_108 [ V_10 ] )
return 0 ;
V_130 = F_4 ( V_9 -> V_18 , V_10 + 1 ) ;
F_2 ( ! V_130 ||
! F_53 ( V_130 ) ||
! F_53 ( V_9 -> V_108 [ V_10 ] ) ||
! F_54 ( V_130 ) ||
! F_54 ( V_9 -> V_108 [ V_10 ] ) ,
L_28 ,
V_130 , V_9 -> V_108 [ V_10 ] ) ;
V_133 = ( V_130 == V_9 -> V_108 [ V_10 ] ) ?
V_9 -> V_134 [ V_10 ] : F_7 ( V_9 -> V_108 [ V_10 ] ) ;
V_132 =
F_55 ( V_9 -> V_108 [ V_10 ] , V_133 ) ;
if ( ( V_131 = F_56 ( V_121 , V_132 ) ) ) {
F_2 ( F_54 ( V_131 ) && ! F_53 ( V_131 ) ,
L_29 ,
V_131 , V_131 ) ;
F_57 ( V_131 ) ;
return 1 ;
}
return 0 ;
}
static void F_58 ( struct V_135 * V_49 )
{
V_136 [ F_59 ( V_49 ) ] -> F_58 ( V_49 ) ;
}
static int F_60 ( struct V_8 * V_9 ,
int V_10 ,
struct V_16 * * V_137 ,
struct V_16 * * V_138 , char V_139 )
{
struct V_16 * V_140 ;
F_61 ( V_141 ) ;
struct V_142 * V_143 = V_9 -> V_18 ;
struct V_135 V_144 ;
int V_115 ,
V_145 = V_146 ,
V_147 = 0 ,
V_148 = F_62 ( V_143 , V_10 ) ;
V_115 = V_148 ;
F_2 ( V_115 < V_149 ,
L_30 ) ;
for (; V_115 > V_149 ; V_115 -- ) {
if ( ! F_53
( V_140 = F_63 ( V_143 , V_115 - 1 ) ) )
return V_125 ;
if ( ( V_145 =
F_64 ( V_143 ,
V_115 - 1 ) ) >
F_7 ( V_140 ) )
return V_125 ;
if ( F_55 ( V_140 , V_145 ) !=
F_63 ( V_143 , V_115 ) -> V_150 )
return V_125 ;
if ( V_139 == V_151 )
V_147 = F_7 ( V_140 ) ;
if ( V_145 != V_147 ) {
* V_138 = V_140 ;
F_65 ( * V_138 ) ;
break;
}
}
if ( V_115 == V_149 ) {
if ( F_63
( V_9 -> V_18 ,
V_149 ) -> V_150 ==
F_66 ( V_9 -> V_43 ) ) {
* V_137 = * V_138 = NULL ;
return V_119 ;
}
return V_125 ;
}
F_2 ( F_67 ( * V_138 ) <= V_152 ,
L_31 ,
* V_138 , * V_138 ) ;
if ( F_68 ( * V_138 ) ) {
int V_153 = F_69 ( V_9 -> V_43 ) ;
F_70 ( * V_138 ) ;
F_71 ( V_9 -> V_43 , V_153 ) ;
if ( F_46 ( V_9 ) ) {
F_38 ( * V_138 ) ;
return V_125 ;
}
}
F_72 ( & V_144 ,
F_14 ( * V_138 ,
( V_139 ==
V_154 ) ? ( V_9 -> V_134 [ V_10 - 1 ] =
V_145 -
1 ) : ( V_9 -> V_50 [ V_10 -
1 ] =
V_145 ) ) ) ;
if ( V_139 == V_154 )
F_58 ( & V_144 ) ;
if ( F_73
( V_9 -> V_43 , & V_144 , & V_141 ,
V_10 + 1 ) == V_155 )
return V_155 ;
if ( F_46 ( V_9 ) ) {
F_37 ( & V_141 ) ;
F_38 ( * V_138 ) ;
return V_125 ;
}
* V_137 = F_74 ( & V_141 ) ;
F_2 ( F_67 ( * V_137 ) != V_10 + 1 ,
L_32 , * V_137 , * V_137 ) ;
F_2 ( V_141 . V_156 <
V_149 , L_33 ) ;
V_141 . V_156 -- ;
F_37 ( & V_141 ) ;
return V_119 ;
}
static int F_75 ( struct V_8 * V_9 , int V_10 )
{
struct V_142 * V_143 = V_9 -> V_18 ;
int V_145 ,
V_157 ,
V_148 = F_62 ( V_9 -> V_18 , V_10 ) ;
struct V_16 * V_158 , * V_159 ;
if ( V_148 <= V_149 ) {
F_38 ( V_9 -> V_108 [ V_10 ] ) ;
F_38 ( V_9 -> V_110 [ V_10 ] ) ;
F_38 ( V_9 -> V_109 [ V_10 ] ) ;
F_38 ( V_9 -> V_47 [ V_10 ] ) ;
V_9 -> V_108 [ V_10 ] = NULL ;
V_9 -> V_110 [ V_10 ] = NULL ;
V_9 -> V_109 [ V_10 ] = NULL ;
V_9 -> V_47 [ V_10 ] = NULL ;
return V_119 ;
}
V_145 = F_64 ( V_143 , V_148 - 1 ) ;
if ( V_145 ) {
V_158 = F_63 ( V_143 , V_148 - 1 ) ;
V_159 = F_63 ( V_143 , V_148 - 1 ) ;
F_65 ( V_158 ) ;
F_65 ( V_158 ) ;
V_9 -> V_134 [ V_10 ] = V_145 - 1 ;
} else {
if ( ( V_157 = F_60 ( V_9 , V_10 + 1 , & V_158 ,
& V_159 ,
V_154 ) ) != V_119 )
return V_157 ;
}
F_38 ( V_9 -> V_108 [ V_10 ] ) ;
V_9 -> V_108 [ V_10 ] = V_158 ;
F_38 ( V_9 -> V_110 [ V_10 ] ) ;
V_9 -> V_110 [ V_10 ] = V_159 ;
F_2 ( ( V_158 && ! F_53 ( V_158 ) ) ||
( V_159 && ! F_53 ( V_159 ) ) ,
L_34 , V_158 , V_159 ) ;
if ( V_145 == F_7 ( F_4 ( V_143 , V_10 + 1 ) ) ) {
if ( ( V_157 =
F_60 ( V_9 , V_10 + 1 , & V_158 , & V_159 ,
V_151 ) ) != V_119 )
return V_157 ;
} else {
V_158 = F_63 ( V_143 , V_148 - 1 ) ;
V_159 = F_63 ( V_143 , V_148 - 1 ) ;
F_65 ( V_158 ) ;
F_65 ( V_158 ) ;
V_9 -> V_50 [ V_10 ] = V_145 ;
}
F_38 ( V_9 -> V_109 [ V_10 ] ) ;
V_9 -> V_109 [ V_10 ] = V_158 ;
F_38 ( V_9 -> V_47 [ V_10 ] ) ;
V_9 -> V_47 [ V_10 ] = V_159 ;
F_2 ( ( V_158 && ! F_53 ( V_158 ) ) ||
( V_159 && ! F_53 ( V_159 ) ) ,
L_35 , V_158 , V_159 ) ;
return V_119 ;
}
static inline int F_76 ( int V_3 , int V_100 , int V_160 , int V_101 ,
struct V_8 * V_9 , int V_10 )
{
struct V_16 * V_17 = F_4 ( V_9 -> V_18 , V_10 ) ;
int V_161 = V_9 -> V_20 [ V_10 ] ;
struct V_11 * V_12 ;
struct V_48 * V_162 = NULL ;
V_12 = F_8 ( V_17 , 0 ) ;
if ( V_9 -> V_47 [ V_10 ] )
V_162 = F_14 ( V_9 -> V_47 [ V_10 ] , V_9 -> V_50 [ V_10 ] ) ;
if ( V_100 + V_101 + V_160 < F_5 ( V_17 ) + V_161
-
( ( ! V_10
&& F_9 ( & ( V_12 -> V_28 ) , V_17 -> V_29 ) ) ? V_37 : 0 )
-
( ( ! V_10 && V_162
&& F_9 ( V_162 , V_17 -> V_29 ) ) ? V_37 : 0 )
+ ( ( V_10 ) ? V_23 : 0 ) ) {
if ( V_160 >= V_161 ) {
if ( ! V_10 )
V_9 -> V_91 =
F_7 ( V_17 ) +
( ( V_3 == V_6 ) ? 1 : 0 ) ;
F_29 ( V_9 , V_10 , 0 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_163 ;
}
}
F_35 ( V_9 -> V_43 , F_76 [ V_10 ] ) ;
return ! V_163 ;
}
static int F_77 ( struct V_8 * V_9 , int V_10 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
int V_161 ,
V_157 ;
int V_100 , V_160 , V_101 ;
int V_164 , V_165 , V_166 , V_167 ;
short V_64 [ 40 ] = { 0 , } ;
struct V_16 * V_17 ;
V_17 = F_4 ( V_9 -> V_18 , V_10 ) ;
V_161 = V_9 -> V_20 [ V_10 ] ;
if ( ! V_17 ) {
if ( ! V_10 )
F_13 ( V_9 -> V_43 , L_36 ,
L_37 ) ;
switch ( V_157 = F_39 ( V_9 , V_10 ) ) {
case V_119 :
F_29 ( V_9 , V_10 , 0 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_163 ;
case V_123 :
case V_125 :
return V_157 ;
default:
F_13 ( V_9 -> V_43 , L_38 , L_39
L_40 ) ;
}
}
if ( ( V_157 = F_75 ( V_9 , V_10 ) ) != V_119 )
return V_157 ;
V_160 = F_6 ( V_17 ) ;
V_101 = F_51 ( V_9 , V_10 ) ;
V_100 = F_47 ( V_9 , V_10 ) ;
if ( F_76 ( V_14 -> V_24 , V_100 , V_160 , V_101 , V_9 , V_10 ) ==
V_163 )
return V_163 ;
F_3 ( V_9 , V_10 ) ;
F_19 ( V_9 , V_10 , V_100 ) ;
F_22 ( V_9 , V_10 , V_101 ) ;
if ( V_10 && ( V_9 -> V_58 [ V_10 ] + V_9 -> V_56 [ V_10 ] >= V_14 -> V_21 + 1 ) ) {
int V_168 ;
V_168 =
( ( F_78 ( V_17 ) << 1 ) + 2 - V_9 -> V_56 [ V_10 ] - V_9 -> V_58 [ V_10 ] +
V_14 -> V_21 + 1 ) / 2 - ( F_78 ( V_17 ) + 1 -
V_9 -> V_58 [ V_10 ] ) ;
F_29 ( V_9 , V_10 , V_14 -> V_21 + 1 - V_168 , V_168 , 0 , NULL ,
- 1 , - 1 ) ;
return V_119 ;
}
F_2 ( V_10 &&
( V_9 -> V_56 [ V_10 ] >= V_14 -> V_21 + 1 ||
V_9 -> V_58 [ V_10 ] >= V_14 -> V_21 + 1 ) ,
L_41 ) ;
F_2 ( ! V_10 && ( ( V_9 -> V_56 [ V_10 ] >= V_14 -> V_21 && ( V_9 -> V_57 == - 1 ) ) ||
( V_9 -> V_58 [ V_10 ] >= V_14 -> V_21 && ( V_9 -> V_59 == - 1 ) ) ) ,
L_42 ) ;
if ( ! V_10 && F_31 ( V_9 ) )
return V_119 ;
if ( V_160 >= V_161 ) {
if ( ! V_10 )
V_9 -> V_91 = V_14 -> V_21 ;
F_29 ( V_9 , V_10 , 0 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_163 ;
}
{
int V_169 , V_170 , V_171 , V_172 , V_173 , V_174 ;
#define F_79 1
#define F_80 0
#define F_81 0
#define F_82 5
#define F_83 10
#define F_84 15
#define F_85 20
#define F_86 25
#define F_87 30
#define F_88 35
V_169 = V_9 -> V_56 [ V_10 ] ;
V_170 = V_9 -> V_58 [ V_10 ] ;
V_171 = F_81 ;
V_164 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
0 , - 1 , V_10 ? V_14 -> V_21 : 0 , - 1 ,
V_64 , F_80 ) ;
if ( ! V_10 ) {
int V_175 ;
V_175 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
0 , - 1 , 0 , - 1 ,
V_64 + F_82 , F_79 ) ;
if ( V_164 > V_175 )
V_171 = F_82 , V_164 = V_175 ;
}
V_172 = F_83 ;
V_165 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
V_169 - ( ( V_10 || V_9 -> V_57 == - 1 ) ? 0 : 1 ) ,
- 1 , V_10 ? V_14 -> V_21 : 0 , - 1 ,
V_64 + F_83 , F_80 ) ;
if ( ! V_10 ) {
int V_176 ;
V_176 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
V_169 -
( ( V_9 -> V_57 != - 1 ) ? 1 : 0 ) ,
V_9 -> V_57 , 0 , - 1 ,
V_64 + F_84 , F_79 ) ;
if ( V_165 > V_176 )
V_172 = F_84 , V_165 = V_176 ;
}
V_173 = F_85 ;
V_166 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
0 , - 1 ,
V_10 ? ( V_14 -> V_21 - V_170 ) : ( V_170 -
( ( V_9 ->
V_59 !=
- 1 ) ? 1 :
0 ) ) , - 1 ,
V_64 + F_85 , F_80 ) ;
if ( ! V_10 ) {
int V_177 ;
V_177 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
0 , - 1 ,
( V_170 -
( ( V_9 -> V_59 != - 1 ) ? 1 : 0 ) ) ,
V_9 -> V_59 ,
V_64 + F_86 , F_79 ) ;
if ( V_166 > V_177 )
V_173 = F_86 , V_166 = V_177 ;
}
V_174 = F_87 ;
V_167 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
V_169 - ( ( V_10 || V_9 -> V_57 == - 1 ) ? 0 : 1 ) ,
- 1 ,
V_10 ? ( V_14 -> V_21 - V_170 ) : ( V_170 -
( ( V_9 ->
V_59 !=
- 1 ) ? 1 :
0 ) ) , - 1 ,
V_64 + F_87 , F_80 ) ;
if ( ! V_10 ) {
int V_178 ;
V_178 = F_24 ( V_14 -> V_24 , V_9 , V_10 ,
V_169 -
( ( V_9 -> V_57 != - 1 ) ? 1 : 0 ) ,
V_9 -> V_57 ,
( V_170 -
( ( V_9 -> V_59 != - 1 ) ? 1 : 0 ) ) ,
V_9 -> V_59 ,
V_64 + F_88 , F_79 ) ;
if ( V_167 > V_178 )
V_174 = F_88 , V_167 = V_178 ;
}
if ( V_167 < V_165 && V_167 < V_166 ) {
F_2 ( V_10 &&
( V_9 -> V_56 [ V_10 ] != 1 ||
V_9 -> V_58 [ V_10 ] != 1 ||
V_167 != 1 || V_166 != 2 || V_165 != 2
|| V_10 != 1 ) , L_43 ) ;
if ( V_174 == F_88 )
F_29 ( V_9 , V_10 , V_9 -> V_56 [ V_10 ] , V_9 -> V_58 [ V_10 ] ,
V_167 , V_64 + V_174 ,
V_9 -> V_57 , V_9 -> V_59 ) ;
else
F_29 ( V_9 , V_10 ,
V_9 -> V_56 [ V_10 ] -
( ( V_9 -> V_57 == - 1 ) ? 0 : 1 ) ,
V_9 -> V_58 [ V_10 ] -
( ( V_9 -> V_59 == - 1 ) ? 0 : 1 ) ,
V_167 , V_64 + V_174 , - 1 , - 1 ) ;
return V_119 ;
}
if ( V_164 == V_167 ) {
F_29 ( V_9 , V_10 , 0 , 0 , V_164 , V_64 + V_171 , - 1 ,
- 1 ) ;
return V_119 ;
}
if ( V_165 < V_166 ) {
V_179 ;
return V_119 ;
}
if ( V_165 > V_166 ) {
V_180 ;
return V_119 ;
}
if ( F_52 ( V_9 , V_10 ) ) {
V_179 ;
return V_119 ;
}
V_180 ;
return V_119 ;
}
}
static int F_89 ( struct V_8 * V_9 , int V_10 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
struct V_16 * V_17 , * V_181 ;
int V_182 , V_157 ;
int V_100 , V_101 ;
V_17 = F_4 ( V_9 -> V_18 , V_10 ) ;
V_181 = F_20 ( V_9 -> V_18 , V_10 ) ;
V_182 = F_5 ( V_17 ) ;
F_3 ( V_9 , V_10 ) ;
if ( ! V_181 ) {
if ( V_14 -> V_21 > 0 ) {
F_29 ( V_9 , V_10 , 0 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_163 ;
}
F_29 ( V_9 , V_10 , 0 , 0 , 0 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
if ( ( V_157 = F_75 ( V_9 , V_10 ) ) != V_119 )
return V_157 ;
V_101 = F_51 ( V_9 , V_10 ) ;
V_100 = F_47 ( V_9 , V_10 ) ;
F_19 ( V_9 , V_10 , V_100 ) ;
F_22 ( V_9 , V_10 , V_101 ) ;
if ( V_14 -> V_21 >= F_90 ( V_17 ) ) {
if ( V_14 -> V_21 == F_90 ( V_17 ) ) {
if ( V_9 -> V_56 [ V_10 ] >= V_14 -> V_21 + 1 ) {
int V_183 ;
int V_184 ;
V_184 =
( ( V_183 =
F_48 ( V_9 -> V_18 ,
V_10 ) ) ==
0 ) ? F_7 ( V_9 -> V_108 [ V_10 ] ) : V_183 - 1 ;
V_183 = F_49 ( F_50 ( V_9 -> V_108 [ V_10 ] , V_184 ) ) /
( V_22 + V_23 ) ;
F_29 ( V_9 , V_10 , - V_183 - 1 , 0 , 0 , NULL , - 1 ,
- 1 ) ;
return V_119 ;
}
if ( V_9 -> V_58 [ V_10 ] >= V_14 -> V_21 + 1 ) {
int V_183 ;
int V_185 ;
V_185 =
( ( V_183 =
F_48 ( V_9 -> V_18 ,
V_10 ) ) ==
F_7 ( V_181 ) ) ? 0 : V_183 + 1 ;
V_183 = F_49 ( F_50 ( V_9 -> V_109 [ V_10 ] , V_185 ) ) /
( V_22 + V_23 ) ;
F_29 ( V_9 , V_10 , 0 , - V_183 - 1 , 0 , NULL , - 1 ,
- 1 ) ;
return V_119 ;
}
}
if ( V_9 -> V_58 [ V_10 ] + V_9 -> V_56 [ V_10 ] >= V_14 -> V_21 + 1 ) {
int V_168 ;
V_168 =
( ( F_78 ( V_17 ) << 1 ) + 2 - V_9 -> V_56 [ V_10 ] -
V_9 -> V_58 [ V_10 ] + V_14 -> V_21 + 1 ) / 2 -
( F_78 ( V_17 ) + 1 - V_9 -> V_58 [ V_10 ] ) ;
F_29 ( V_9 , V_10 , V_14 -> V_21 + 1 - V_168 , V_168 ,
0 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
F_29 ( V_9 , V_10 , 0 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_163 ;
}
if ( V_9 -> V_56 [ V_10 ] >= V_14 -> V_21 + 1 )
if ( F_52 ( V_9 , V_10 )
|| V_9 -> V_58 [ V_10 ] < V_14 -> V_21 + 1 || ! V_9 -> V_109 [ V_10 ] ) {
int V_183 ;
int V_184 ;
V_184 =
( ( V_183 =
F_48 ( V_9 -> V_18 ,
V_10 ) ) ==
0 ) ? F_7 ( V_9 -> V_108 [ V_10 ] ) : V_183 - 1 ;
V_183 = F_49 ( F_50 ( V_9 -> V_108 [ V_10 ] , V_184 ) ) / ( V_22 +
V_23 ) ;
F_29 ( V_9 , V_10 , - V_183 - 1 , 0 , 0 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
if ( V_9 -> V_58 [ V_10 ] >= V_14 -> V_21 + 1 ) {
int V_183 ;
int V_185 ;
V_185 =
( ( V_183 =
F_48 ( V_9 -> V_18 ,
V_10 ) ) == F_7 ( V_181 ) ) ? 0 : ( V_183 + 1 ) ;
V_183 = F_49 ( F_50 ( V_9 -> V_109 [ V_10 ] , V_185 ) ) / ( V_22 +
V_23 ) ;
F_29 ( V_9 , V_10 , 0 , - V_183 - 1 , 0 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
if ( V_9 -> V_58 [ V_10 ] + V_9 -> V_56 [ V_10 ] >= V_14 -> V_21 + 1 ) {
int V_168 ;
V_168 =
( ( F_78 ( V_17 ) << 1 ) + 2 - V_9 -> V_56 [ V_10 ] - V_9 -> V_58 [ V_10 ] +
V_14 -> V_21 + 1 ) / 2 - ( F_78 ( V_17 ) + 1 -
V_9 -> V_58 [ V_10 ] ) ;
F_29 ( V_9 , V_10 , V_14 -> V_21 + 1 - V_168 , V_168 , 0 , NULL ,
- 1 , - 1 ) ;
return V_119 ;
}
F_2 ( ! V_9 -> V_108 [ V_10 ] && ! V_9 -> V_109 [ V_10 ] , L_44 ) ;
if ( F_52 ( V_9 , V_10 ) || ! V_9 -> V_109 [ V_10 ] ) {
int V_186 ;
V_186 =
( F_78 ( V_17 ) + 1 - V_9 -> V_56 [ V_10 ] + V_14 -> V_21 +
1 ) / 2 - ( V_14 -> V_21 + 1 ) ;
F_29 ( V_9 , V_10 , - V_186 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
F_29 ( V_9 , V_10 , 0 ,
- ( ( F_78 ( V_17 ) + 1 - V_9 -> V_58 [ V_10 ] + V_14 -> V_21 +
1 ) / 2 - ( V_14 -> V_21 + 1 ) ) , 1 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
static int F_91 ( struct V_8 * V_9 , int V_10 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
int V_161 ;
int V_182 , V_157 ;
struct V_16 * V_102 , * V_187 ;
int V_100 , V_101 ;
V_102 = F_4 ( V_9 -> V_18 , 0 ) ;
V_187 = F_20 ( V_9 -> V_18 , 0 ) ;
V_161 = V_9 -> V_20 [ V_10 ] ;
V_182 = F_5 ( V_102 ) ;
if ( ! V_187 ) {
F_2 ( - V_161 >= V_182 - F_6 ( V_102 ) ,
L_45 ) ;
F_29 ( V_9 , V_10 , 0 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_163 ;
}
if ( ( V_157 = F_75 ( V_9 , V_10 ) ) != V_119 )
return V_157 ;
V_101 = F_51 ( V_9 , V_10 ) ;
V_100 = F_47 ( V_9 , V_10 ) ;
F_3 ( V_9 , V_10 ) ;
if ( F_32 ( V_9 , V_100 , V_101 ) )
return V_119 ;
F_19 ( V_9 , V_10 , V_100 ) ;
F_22 ( V_9 , V_10 , V_101 ) ;
if ( V_9 -> V_56 [ 0 ] >= V_14 -> V_21 && V_9 -> V_57 == - 1 )
if ( F_52 ( V_9 , V_10 ) || ( ( V_9 -> V_58 [ 0 ] - ( ( V_9 -> V_59 == - 1 ) ? 0 : 1 ) ) < V_14 -> V_21 ) ||
! V_9 -> V_109 [ V_10 ] ) {
F_2 ( ! V_9 -> V_108 [ V_10 ] ,
L_46 ) ;
F_29 ( V_9 , V_10 , - 1 , 0 , 0 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
if ( V_9 -> V_58 [ 0 ] >= V_14 -> V_21 && V_9 -> V_59 == - 1 ) {
F_29 ( V_9 , V_10 , 0 , - 1 , 0 , NULL , - 1 , - 1 ) ;
return V_119 ;
}
if ( F_31 ( V_9 ) )
return V_119 ;
V_9 -> V_91 = V_14 -> V_21 ;
F_29 ( V_9 , V_10 , 0 , 0 , 1 , NULL , - 1 , - 1 ) ;
return V_163 ;
}
static int F_92 ( struct V_8 * V_9 , int V_10 )
{
F_2 ( ! ( F_4 ( V_9 -> V_18 , V_10 ) ) ,
L_47 ) ;
if ( V_10 )
return F_89 ( V_9 , V_10 ) ;
else
return F_91 ( V_9 , V_10 ) ;
}
static int F_93 ( int V_3 ,
struct V_8 * V_9 ,
int V_10 ,
int V_188 ,
int V_189 ,
struct V_11 * V_190 , const void * V_191 )
{
struct V_13 * V_14 ;
V_14 = V_9 -> V_15 = (struct V_13 * ) ( V_9 -> V_41 ) ;
V_14 -> V_27 = ( char * ) ( V_9 -> V_15 + 1 ) ;
V_14 -> V_24 = V_3 ;
V_14 -> V_30 = V_188 ;
V_14 -> V_192 = V_189 ;
V_14 -> V_46 = V_190 ;
V_14 -> V_45 = V_191 ;
F_2 ( V_3 == V_6 && ! V_14 -> V_46 ,
L_48 ) ;
if ( V_9 -> V_20 [ V_10 ] > 0 )
return F_77 ( V_9 , V_10 ) ;
return F_92 ( V_9 , V_10 ) ;
}
static int F_94 ( struct V_8 * V_9 , int V_10 )
{
struct V_16 * V_193 ;
struct V_142 * V_143 = V_9 -> V_18 ;
int V_145 ,
V_148 = F_62 ( V_9 -> V_18 , V_10 ) ;
if ( V_148 <= V_149 ) {
F_2 ( V_148 < V_149 - 1 ,
L_49 ) ;
if ( F_63 ( V_143 , V_149 ) ->
V_150 == F_66 ( V_9 -> V_43 ) ) {
F_63 ( V_143 , V_148 - 1 ) = NULL ;
F_64 ( V_143 , V_148 - 1 ) = 0 ;
return V_119 ;
}
return V_125 ;
}
if ( ! F_53
( V_193 = F_63 ( V_143 , V_148 - 1 ) ) )
return V_125 ;
if ( ( V_145 =
F_64 ( V_143 ,
V_148 - 1 ) ) > F_7 ( V_193 ) )
return V_125 ;
if ( F_55 ( V_193 , V_145 ) !=
F_63 ( V_143 , V_148 ) -> V_150 )
return V_125 ;
if ( F_68 ( V_193 ) ) {
int V_153 = F_69 ( V_9 -> V_43 ) ;
F_70 ( V_193 ) ;
F_71 ( V_9 -> V_43 , V_153 ) ;
if ( F_46 ( V_9 ) )
return V_125 ;
}
return V_119 ;
}
static int F_95 ( struct V_8 * V_9 , int V_10 )
{
int V_194 ,
V_148 = F_62 ( V_9 -> V_18 , V_10 + 1 ) ;
unsigned long V_195 ;
struct V_120 * V_121 = V_9 -> V_43 ;
struct V_16 * V_193 ;
int V_153 ;
F_35 ( V_121 , F_95 [ V_10 ] ) ;
if ( V_9 -> V_56 [ V_10 ] ) {
F_35 ( V_121 , V_196 [ V_10 ] ) ;
V_193 = F_63 ( V_9 -> V_18 , V_148 ) ;
F_2 ( V_193 == V_9 -> V_108 [ V_10 ] &&
! F_64 ( V_9 -> V_18 , V_148 ) ,
L_50 ) ;
V_194 =
( V_193 ==
V_9 -> V_108 [ V_10 ] ) ? V_9 -> V_134 [ V_10 ] : F_7 ( V_9 ->
V_108 [ V_10 ] ) ;
V_195 = F_55 ( V_9 -> V_108 [ V_10 ] , V_194 ) ;
V_153 = F_69 ( V_9 -> V_43 ) ;
V_193 = F_96 ( V_121 , V_195 ) ;
F_71 ( V_9 -> V_43 , V_153 ) ;
if ( ! V_193 )
return V_155 ;
if ( F_46 ( V_9 ) ) {
F_38 ( V_193 ) ;
F_35 ( V_121 , V_197 [ V_10 ] ) ;
return V_125 ;
}
F_2 ( ! F_53 ( V_9 -> V_108 [ V_10 ] ) ||
V_194 > F_7 ( V_9 -> V_108 [ V_10 ] ) ||
F_55 ( V_9 -> V_108 [ V_10 ] , V_194 ) !=
V_193 -> V_150 , L_51 ) ;
F_2 ( ! F_53 ( V_193 ) , L_52 ) ;
F_2 ( ! V_10 &&
F_6 ( V_193 ) !=
F_5 ( V_193 ) -
F_49 ( F_50 ( V_9 -> V_108 [ 0 ] , V_194 ) ) ,
L_53 ) ;
F_38 ( V_9 -> V_106 [ V_10 ] ) ;
V_9 -> V_106 [ V_10 ] = V_193 ;
}
if ( V_9 -> V_58 [ V_10 ] ) {
F_35 ( V_121 , V_198 [ V_10 ] ) ;
V_193 = F_63 ( V_9 -> V_18 , V_148 ) ;
F_2 ( V_193 == V_9 -> V_109 [ V_10 ] &&
F_64 ( V_9 -> V_18 ,
V_148 ) >=
F_7 ( V_193 ) ,
L_54 ) ;
V_194 =
( V_193 == V_9 -> V_109 [ V_10 ] ) ? V_9 -> V_50 [ V_10 ] + 1 : 0 ;
V_195 = F_55 ( V_9 -> V_109 [ V_10 ] , V_194 ) ;
V_153 = F_69 ( V_9 -> V_43 ) ;
V_193 = F_96 ( V_121 , V_195 ) ;
F_71 ( V_9 -> V_43 , V_153 ) ;
if ( ! V_193 )
return V_155 ;
if ( F_46 ( V_9 ) ) {
F_38 ( V_193 ) ;
F_35 ( V_121 , V_197 [ V_10 ] ) ;
return V_125 ;
}
F_38 ( V_9 -> V_107 [ V_10 ] ) ;
V_9 -> V_107 [ V_10 ] = V_193 ;
F_2 ( ! V_10
&& F_6 ( V_193 ) !=
F_5 ( V_193 ) -
F_49 ( F_50 ( V_9 -> V_109 [ 0 ] , V_194 ) ) ,
L_55 ,
F_6 ( V_193 ) , F_5 ( V_193 ) ,
F_49 ( F_50 ( V_9 -> V_109 [ 0 ] , V_194 ) ) ) ;
}
return V_119 ;
}
static int F_97 ( struct V_120 * V_121 , struct V_16 * V_193 )
{
int V_199 ;
int V_200 ;
unsigned long V_201 = V_121 -> V_202 ;
#define F_98 1
V_199 = ( V_201 - V_203 ) / ( V_37 + V_204 ) ;
V_200 = ( V_201 - V_203 - V_37 ) /
( V_205 + F_98 ) ;
return sizeof( struct V_13 ) +
F_99 ( V_199 * sizeof( struct V_26 ) ,
sizeof( struct V_26 ) + sizeof( struct V_206 ) +
( V_200 - 1 ) * sizeof( V_207 ) ) ;
}
static int F_100 ( struct V_8 * V_9 )
{
int V_208 = 0 ;
int V_98 ;
char * V_209 ;
V_98 = F_97 ( V_9 -> V_43 , F_74 ( V_9 -> V_18 ) ) ;
if ( V_98 > V_9 -> V_42 ) {
if ( V_9 -> V_41 ) {
F_101 ( V_9 -> V_41 ) ;
V_208 = 1 ;
}
V_9 -> V_42 = V_98 ;
V_209 = F_102 ( V_98 , V_210 | V_211 ) ;
if ( ! V_209 ) {
F_36 ( V_9 ) ;
V_209 = F_102 ( V_98 , V_212 ) ;
if ( ! V_209 ) {
V_9 -> V_42 = 0 ;
}
V_9 -> V_41 = V_209 ;
F_103 () ;
return V_125 ;
}
V_9 -> V_41 = V_209 ;
}
if ( V_208 && F_46 ( V_9 ) )
return V_125 ;
return V_119 ;
}
static void F_104 ( struct V_120 * V_121 ,
struct V_16 * V_193 ,
const char * V_213 , int V_214 )
{
if ( V_193 ) {
if ( F_105 ( & ( V_193 -> V_215 ) ) <= 0 )
F_13 ( V_121 , L_56 , L_57
L_58
L_59 , V_213 , V_214 , V_193 ) ;
if ( ! F_54 ( V_193 ) )
F_13 ( V_121 , L_60 , L_61
L_62 ,
V_213 , V_214 , V_193 ) ;
if ( ! F_53 ( V_193 ) )
F_13 ( V_121 , L_63 , L_64
L_65 ,
V_213 , V_214 , V_193 ) ;
if ( V_193 -> V_216 != V_121 -> V_217 )
F_13 ( V_121 , L_66 , L_67
L_68 ,
V_213 , V_214 , V_193 ) ;
if ( V_193 -> V_29 != V_121 -> V_202 )
F_13 ( V_121 , L_69 , L_67
L_70 ,
V_213 , V_214 , V_193 ) ;
if ( V_193 -> V_150 > F_106 ( V_121 ) )
F_13 ( V_121 , L_71 , L_72
L_73 ,
V_213 , V_214 , V_193 ) ;
}
}
static void F_104 ( struct V_120 * V_121 ,
struct V_16 * V_193 ,
const char * V_213 , int V_214 )
{ ;
}
static int F_107 ( struct V_120 * V_218 , struct V_16 * V_193 )
{
return F_108 ( V_218 , V_193 , 0 ) ;
}
static int F_109 ( struct V_8 * V_9 )
{
struct V_16 * V_219 ;
#ifdef F_15
int V_220 = 0 ;
#endif
int V_53 ;
do {
V_219 = NULL ;
for ( V_53 = V_9 -> V_18 -> V_156 ;
! V_219 && V_53 > V_221 ; V_53 -- ) {
if ( F_63 ( V_9 -> V_18 , V_53 ) ) {
#ifdef F_15
if ( F_74 ( V_9 -> V_18 ) ==
F_63 ( V_9 -> V_18 , V_53 ) )
F_104 ( V_9 -> V_43 ,
F_63
( V_9 -> V_18 ,
V_53 ) , L_74 ,
V_9 -> V_18 ->
V_156 - V_53 ) ;
#endif
if ( ! F_107 ( V_9 -> V_43 ,
F_63
( V_9 -> V_18 ,
V_53 ) ) ) {
V_219 =
F_63 ( V_9 -> V_18 ,
V_53 ) ;
}
}
}
for ( V_53 = 0 ; ! V_219 && V_53 < V_105 && V_9 -> V_20 [ V_53 ] ;
V_53 ++ ) {
if ( V_9 -> V_56 [ V_53 ] ) {
if ( V_9 -> V_106 [ V_53 ] ) {
F_104 ( V_9 -> V_43 ,
V_9 -> V_106 [ V_53 ] ,
L_75 , V_53 ) ;
if ( ! F_107
( V_9 -> V_43 , V_9 -> V_106 [ V_53 ] ) )
V_219 = V_9 -> V_106 [ V_53 ] ;
}
if ( ! V_219 && V_9 -> V_108 [ V_53 ] ) {
F_104 ( V_9 -> V_43 ,
V_9 -> V_108 [ V_53 ] ,
L_76 , V_53 ) ;
if ( ! F_107
( V_9 -> V_43 , V_9 -> V_108 [ V_53 ] ) )
V_219 = V_9 -> V_108 [ V_53 ] ;
}
if ( ! V_219 && V_9 -> V_110 [ V_53 ] ) {
F_104 ( V_9 -> V_43 ,
V_9 -> V_110 [ V_53 ] ,
L_77 , V_53 ) ;
if ( ! F_107
( V_9 -> V_43 , V_9 -> V_110 [ V_53 ] ) )
V_219 = V_9 -> V_110 [ V_53 ] ;
}
}
if ( ! V_219 && ( V_9 -> V_58 [ V_53 ] ) ) {
if ( V_9 -> V_107 [ V_53 ] ) {
F_104 ( V_9 -> V_43 ,
V_9 -> V_107 [ V_53 ] ,
L_78 , V_53 ) ;
if ( ! F_107
( V_9 -> V_43 , V_9 -> V_107 [ V_53 ] ) )
V_219 = V_9 -> V_107 [ V_53 ] ;
}
if ( ! V_219 && V_9 -> V_109 [ V_53 ] ) {
F_104 ( V_9 -> V_43 ,
V_9 -> V_109 [ V_53 ] ,
L_79 , V_53 ) ;
if ( ! F_107
( V_9 -> V_43 , V_9 -> V_109 [ V_53 ] ) )
V_219 = V_9 -> V_109 [ V_53 ] ;
}
if ( ! V_219 && V_9 -> V_47 [ V_53 ] ) {
F_104 ( V_9 -> V_43 ,
V_9 -> V_47 [ V_53 ] ,
L_80 , V_53 ) ;
if ( ! F_107
( V_9 -> V_43 , V_9 -> V_47 [ V_53 ] ) )
V_219 = V_9 -> V_47 [ V_53 ] ;
}
}
}
for ( V_53 = 0 ; ! V_219 && V_53 < V_222 ; V_53 ++ ) {
if ( V_9 -> V_124 [ V_53 ] ) {
if ( ! F_107
( V_9 -> V_43 , V_9 -> V_124 [ V_53 ] ) )
V_219 = V_9 -> V_124 [ V_53 ] ;
}
}
if ( V_219 ) {
int V_153 ;
#ifdef F_15
V_220 ++ ;
if ( ( V_220 % 10000 ) == 0 ) {
F_27 ( V_9 -> V_43 , L_81 ,
L_82
L_83
L_59 , V_219 ) ;
return ( F_46 ( V_9 ) ) ?
V_125 : V_119 ;
}
#endif
V_153 = F_69 ( V_9 -> V_43 ) ;
F_70 ( V_219 ) ;
F_71 ( V_9 -> V_43 , V_153 ) ;
if ( F_46 ( V_9 ) )
return V_125 ;
}
} while ( V_219 );
return V_119 ;
}
int F_110 ( int V_223 , struct V_8 * V_9 ,
struct V_11 * V_190 , const void * V_191 )
{
int V_157 , V_10 , V_224 = F_111 ( V_9 -> V_18 ) ;
int V_189 ;
int V_225 = 0 ;
struct V_16 * V_226 = F_74 ( V_9 -> V_18 ) ;
++ F_112 ( V_9 -> V_43 ) -> V_227 ;
V_189 = V_9 -> V_18 -> V_189 ;
V_9 -> V_228 = F_113 ( V_9 -> V_43 ) ;
F_108 ( V_9 -> V_43 ,
F_114 ( V_9 -> V_43 ) , 1 ) ;
F_115 ( V_9 -> V_229 , V_9 -> V_43 ,
F_114 ( V_9 -> V_43 ) ) ;
if ( F_46 ( V_9 ) )
return V_125 ;
if ( F_68 ( V_226 ) ) {
int V_153 = F_69 ( V_9 -> V_43 ) ;
F_70 ( V_226 ) ;
F_71 ( V_9 -> V_43 , V_153 ) ;
if ( F_46 ( V_9 ) )
return V_125 ;
}
#ifdef F_15
if ( F_112 ( V_9 -> V_43 ) -> V_230 ) {
F_116 ( L_84 ) ;
F_13 ( V_9 -> V_43 , L_85 ,
L_86 ) ;
}
if ( ! F_54 ( V_226 ) || ! F_53 ( V_226 ) )
F_13 ( V_9 -> V_43 , L_87 , L_88
L_89
L_90 ,
V_226 , V_226 , V_223 ) ;
switch ( V_223 ) {
case V_6 :
if ( V_224 <= 0 || V_224 > F_7 ( V_226 ) )
F_13 ( V_9 -> V_43 , L_91 , L_92
L_93
L_94 , V_224 ,
F_7 ( V_226 ) ) ;
break;
case V_4 :
case V_7 :
case V_5 :
if ( V_224 < 0 || V_224 >= F_7 ( V_226 ) ) {
F_18 ( V_226 , 0 , - 1 , - 1 ) ;
F_13 ( V_9 -> V_43 , L_95 , L_92
L_96
L_97 ,
V_224 , V_223 ,
V_9 -> V_20 [ 0 ] ) ;
}
break;
default:
F_13 ( V_9 -> V_43 , L_98 , L_99
L_100 ) ;
}
#endif
if ( F_100 ( V_9 ) == V_125 )
return V_125 ;
for ( V_10 = 0 ; V_10 < V_105 && V_9 -> V_20 [ V_10 ] ; V_10 ++ ) {
V_157 = F_94 ( V_9 , V_10 ) ;
if ( V_157 != V_119 )
goto V_231;
V_157 = F_93 ( V_223 , V_9 , V_10 , V_224 ,
V_189 , V_190 , V_191 ) ;
if ( V_157 != V_119 ) {
if ( V_157 == V_163 ) {
V_157 = F_95 ( V_9 , V_10 ) ;
if ( V_157 != V_119 )
goto V_231;
if ( V_10 != V_105 - 1 )
V_9 -> V_20 [ V_10 + 1 ] = 0 ;
break;
}
goto V_231;
}
V_157 = F_95 ( V_9 , V_10 ) ;
if ( V_157 != V_119 )
goto V_231;
V_157 = F_39 ( V_9 , V_10 ) ;
if ( V_157 != V_119 )
goto V_231;
if ( ! F_4 ( V_9 -> V_18 , V_10 ) ) {
F_2 ( V_9 -> V_90 [ V_10 ] != 1 ,
L_101 ) ;
if ( V_10 < V_105 - 1 )
V_9 -> V_20 [ V_10 + 1 ] = 0 ;
} else if ( ! F_4 ( V_9 -> V_18 , V_10 + 1 ) ) {
if ( V_9 -> V_90 [ V_10 ] > 1 ) {
F_2 ( V_10 == V_105 - 1 ,
L_102 ) ;
V_9 -> V_20 [ V_10 + 1 ] =
( V_22 +
V_23 ) * ( V_9 -> V_90 [ V_10 ] - 1 ) +
V_22 ;
} else if ( V_10 < V_105 - 1 )
V_9 -> V_20 [ V_10 + 1 ] = 0 ;
} else
V_9 -> V_20 [ V_10 + 1 ] =
( V_22 + V_23 ) * ( V_9 -> V_90 [ V_10 ] - 1 ) ;
}
V_157 = F_109 ( V_9 ) ;
if ( V_157 == V_119 ) {
if ( F_46 ( V_9 ) ) {
V_225 = 1 ;
V_157 = V_125 ;
goto V_231;
} else {
return V_119 ;
}
} else {
V_225 = 1 ;
goto V_231;
}
V_231:
{
int V_53 ;
if ( V_225 ) {
F_117 ( V_9 -> V_43 , V_9 -> V_18 ) ;
} else {
F_37 ( V_9 -> V_18 ) ;
}
for ( V_53 = 0 ; V_53 < V_105 ; V_53 ++ ) {
if ( V_225 ) {
F_118 ( V_9 -> V_43 ,
V_9 -> V_106 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 ,
V_9 -> V_107 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 ,
V_9 -> V_108 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 ,
V_9 -> V_109 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 ,
V_9 ->
V_110 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 ,
V_9 ->
V_47 [ V_53 ] ) ;
}
F_38 ( V_9 -> V_106 [ V_53 ] ) ;
F_38 ( V_9 -> V_107 [ V_53 ] ) ;
F_38 ( V_9 -> V_108 [ V_53 ] ) ;
F_38 ( V_9 -> V_109 [ V_53 ] ) ;
F_38 ( V_9 -> V_110 [ V_53 ] ) ;
F_38 ( V_9 -> V_47 [ V_53 ] ) ;
V_9 -> V_106 [ V_53 ] = NULL ;
V_9 -> V_107 [ V_53 ] = NULL ;
V_9 -> V_108 [ V_53 ] = NULL ;
V_9 -> V_109 [ V_53 ] = NULL ;
V_9 -> V_110 [ V_53 ] = NULL ;
V_9 -> V_47 [ V_53 ] = NULL ;
}
if ( V_225 ) {
for ( V_53 = 0 ; V_53 < V_222 ; V_53 ++ ) {
if ( V_9 -> V_124 [ V_53 ] )
F_118
( V_9 -> V_43 , V_9 -> V_124 [ V_53 ] ) ;
}
}
return V_157 ;
}
}
void F_119 ( struct V_8 * V_9 )
{
int V_53 ;
F_117 ( V_9 -> V_43 , V_9 -> V_18 ) ;
for ( V_53 = 0 ; V_53 < V_105 ; V_53 ++ ) {
F_118 ( V_9 -> V_43 , V_9 -> V_106 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 , V_9 -> V_107 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 , V_9 -> V_108 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 , V_9 -> V_109 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 , V_9 -> V_110 [ V_53 ] ) ;
F_118 ( V_9 -> V_43 , V_9 -> V_47 [ V_53 ] ) ;
F_38 ( V_9 -> V_106 [ V_53 ] ) ;
F_38 ( V_9 -> V_107 [ V_53 ] ) ;
F_38 ( V_9 -> V_108 [ V_53 ] ) ;
F_38 ( V_9 -> V_109 [ V_53 ] ) ;
F_38 ( V_9 -> V_110 [ V_53 ] ) ;
F_38 ( V_9 -> V_47 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < V_222 ; V_53 ++ ) {
if ( V_9 -> V_124 [ V_53 ] ) {
T_1 V_112 = V_9 -> V_124 [ V_53 ] -> V_150 ;
F_38 ( V_9 -> V_124 [ V_53 ] ) ;
F_120 ( V_9 -> V_229 , NULL ,
V_112 , 0 ) ;
}
if ( V_9 -> V_232 [ V_53 ] ) {
F_38 ( V_9 -> V_232 [ V_53 ] ) ;
}
}
F_101 ( V_9 -> V_41 ) ;
}
