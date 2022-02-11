static T_1 int
F_1 ( const T_2 * * V_1 , const T_2 * V_2 , unsigned V_3 )
{
if ( ( V_2 - * V_1 ) >= V_3 ) {
* V_1 += V_3 ;
return 0 ;
}
F_2 ( L_1 ) ;
return 1 ;
}
static T_1 T_3 * F_3 ( T_4 * V_4 ,
unsigned long V_5 ,
unsigned long V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
T_3 * V_11 = V_4 -> V_12 ;
if ( V_11 && V_11 -> V_5 <= V_5
&& ( V_5 + V_6 ) <= ( V_11 -> V_5 + V_11 -> V_6 ) ) {
return V_11 ;
}
F_4 (r_list, &dev->maplist, head) {
V_11 = V_10 -> V_11 ;
if ( ! V_11 )
continue;
if ( V_11 -> V_5 <= V_5
&& ( V_5 + V_6 ) <= ( V_11 -> V_5 + V_11 -> V_6 )
&& ! ( V_11 -> V_13 & V_14 )
&& ( V_11 -> type == V_15 ) ) {
V_4 -> V_12 = V_11 ;
return V_11 ;
}
}
return NULL ;
}
static T_1 int F_5 ( T_4 * V_16 )
{
switch ( V_16 -> V_17 ) {
case V_18 :
F_6 ( L_2 , V_16 -> V_19 ) ;
break;
case V_20 :
F_6 ( L_3 ,
V_16 -> V_21 ) ;
break;
case V_22 :
if ( V_16 -> V_23 ) {
unsigned V_24 =
V_16 -> V_25 [ V_16 -> V_26 ] ;
unsigned V_27 = V_16 -> V_28 [ V_16 -> V_26 ] ;
unsigned long V_29 = ~ 0 , V_30 = 0 , V_31 ;
T_2 * V_32 , * V_33 , * V_34 , V_35 ;
unsigned V_36 ;
int V_37 ;
if ( V_27 > 9 )
V_27 = 9 ;
if ( V_24 > 9 )
V_24 = 9 ;
V_32 =
& ( V_16 -> V_38 [ V_35 = V_16 -> V_26 ] [ V_24 ] ) ;
V_33 = & ( V_16 -> V_33 [ V_35 ] [ V_24 ] ) ;
V_34 = & ( V_16 -> V_34 [ V_35 ] [ V_24 ] ) ;
V_37 = V_16 -> V_39 [ V_35 ] ;
for ( V_36 = V_24 ; V_36 <= V_27 ; ++ V_36 ) {
V_31 = * V_32 ++ ;
if ( V_31 < V_29 )
V_29 = V_31 ;
if ( V_36 == 0 && V_37 )
V_31 += ( * V_34 ++ * * V_33 ++ ) ;
else
V_31 += ( * V_34 ++ << * V_33 ++ ) ;
if ( V_31 > V_30 )
V_30 = V_31 ;
}
if ( ! F_3
( V_16 , V_29 , V_30 - V_29 , V_16 -> V_8 ) ) {
F_2
( L_4 ) ;
return 2 ;
}
}
break;
default:
break;
}
V_16 -> V_17 = V_40 ;
return 0 ;
}
static T_1 int
F_7 ( T_2 V_41 , T_5 V_42 , T_4 * V_16 )
{
register T_2 V_31 , * V_43 ;
if ( V_16 -> V_17 && ( V_16 -> V_17 != V_44 [ V_42 ] ) ) {
int V_45 ;
if ( ( V_45 = F_5 ( V_16 ) ) )
return V_45 ;
}
switch ( V_42 ) {
case V_46 :
if ( V_41 == V_47 )
return 1 ;
return 0 ;
case V_48 :
if ( ( V_41 & V_49 ) == V_50 )
return 1 ;
return 0 ;
case V_51 :
if ( V_41 == V_47 )
return 1 ;
F_2 ( L_5 ) ;
break;
case V_52 :
if ( ( V_41 & V_49 ) == V_50 )
return 1 ;
F_2 ( L_6 ) ;
break;
case V_53 :
if ( ( V_41 & V_54 ) == V_55 )
return 1 ;
F_2 ( L_7 ) ;
break;
case V_56 :
if ( V_57 == V_41 )
return 0 ;
F_2 ( L_8 ) ;
break;
case V_58 :
if ( 0xdddddddd == V_41 )
return 0 ;
F_2 ( L_9 ) ;
break;
case V_59 :
V_16 -> V_17 = V_18 ;
V_16 -> V_19 = ( V_16 -> V_19 & 0xFF000000 ) |
( V_41 & 0x00FFFFFF ) ;
return 0 ;
case V_60 :
V_16 -> V_17 = V_18 ;
V_16 -> V_19 = ( V_16 -> V_19 & 0x00FFFFFF ) |
( ( V_41 & 0xFF ) << 24 ) ;
return 0 ;
case V_61 :
V_16 -> V_17 = V_18 ;
if ( ( V_41 & 0x0000C000 ) == 0 )
return 0 ;
F_2 ( L_10 ) ;
return 2 ;
case V_62 :
V_16 -> V_17 = V_20 ;
V_16 -> V_21 = ( V_16 -> V_21 & 0xFF000000 ) |
( V_41 & 0x00FFFFFF ) ;
return 0 ;
case V_63 :
V_16 -> V_17 = V_20 ;
V_16 -> V_21 = ( V_16 -> V_21 & 0x00FFFFFF ) |
( ( V_41 & 0xFF ) << 24 ) ;
return 0 ;
case V_64 :
V_16 -> V_17 = V_20 ;
if ( ( V_41 & 0x0000C000 ) == 0 )
return 0 ;
F_2
( L_11 ) ;
return 2 ;
case V_65 :
V_16 -> V_17 = V_22 ;
V_31 = ( V_41 >> 24 ) ;
V_43 = & V_16 -> V_38 [ V_16 -> V_26 ] [ V_31 ] ;
* V_43 = ( * V_43 & 0xFF000000 ) | ( V_41 & 0x00FFFFFF ) ;
return 0 ;
case V_66 :
V_16 -> V_17 = V_22 ;
V_31 = ( ( V_41 >> 24 ) - 0x20 ) ;
V_31 += V_31 << 1 ;
V_43 = & V_16 -> V_38 [ V_16 -> V_26 ] [ V_31 ] ;
* V_43 = ( * V_43 & 0x00FFFFFF ) | ( ( V_41 & 0xFF ) << 24 ) ;
V_43 ++ ;
* V_43 = ( * V_43 & 0x00FFFFFF ) | ( ( V_41 & 0xFF00 ) << 16 ) ;
V_43 ++ ;
* V_43 = ( * V_43 & 0x00FFFFFF ) | ( ( V_41 & 0xFF0000 ) << 8 ) ;
return 0 ;
case V_67 :
V_16 -> V_17 = V_22 ;
V_16 -> V_25 [ V_31 = V_16 -> V_26 ] = V_41 & 0x3F ;
V_16 -> V_28 [ V_31 ] = ( V_41 & 0xFC0 ) >> 6 ;
return 0 ;
case V_68 :
V_16 -> V_17 = V_22 ;
V_31 = ( ( V_41 >> 24 ) - V_69 ) ;
if ( V_31 == 0 &&
( V_41 & V_70 ) ) {
V_16 -> V_33 [ V_16 -> V_26 ] [ V_31 ] =
( V_41 & V_71 ) ;
V_16 -> V_39 [ V_16 -> V_26 ] = 1 ;
} else {
V_16 -> V_33 [ V_16 -> V_26 ] [ V_31 ] =
( V_41 & V_72 ) >> V_73 ;
V_16 -> V_39 [ V_16 -> V_26 ] = 0 ;
if ( V_41 & 0x000FFFFF ) {
F_2
( L_12 ) ;
return 2 ;
}
}
return 0 ;
case V_74 :
V_16 -> V_17 = V_22 ;
V_43 = & V_16 -> V_38 [ V_16 -> V_26 ] [ 9 ] ;
* V_43 = ( * V_43 & 0x00FFFFFF ) | ( ( V_41 & 0xFF ) << 24 ) ;
return 0 ;
case V_75 :
case V_76 :
V_16 -> V_17 = V_22 ;
return 0 ;
case V_77 :
V_16 -> V_17 = V_22 ;
V_43 = & ( V_16 -> V_34 [ V_16 -> V_26 ] [ 0 ] ) ;
V_43 [ 5 ] = 1 << ( ( V_41 & 0x00F00000 ) >> 20 ) ;
V_43 [ 4 ] = 1 << ( ( V_41 & 0x000F0000 ) >> 16 ) ;
V_43 [ 3 ] = 1 << ( ( V_41 & 0x0000F000 ) >> 12 ) ;
V_43 [ 2 ] = 1 << ( ( V_41 & 0x00000F00 ) >> 8 ) ;
V_43 [ 1 ] = 1 << ( ( V_41 & 0x000000F0 ) >> 4 ) ;
V_43 [ 0 ] = 1 << ( V_41 & 0x0000000F ) ;
return 0 ;
case V_78 :
V_16 -> V_17 = V_22 ;
V_43 = & ( V_16 -> V_34 [ V_16 -> V_26 ] [ 0 ] ) ;
V_43 [ 9 ] = 1 << ( ( V_41 & 0x0000F000 ) >> 12 ) ;
V_43 [ 8 ] = 1 << ( ( V_41 & 0x00000F00 ) >> 8 ) ;
V_43 [ 7 ] = 1 << ( ( V_41 & 0x000000F0 ) >> 4 ) ;
V_43 [ 6 ] = 1 << ( V_41 & 0x0000000F ) ;
return 0 ;
case V_79 :
V_16 -> V_17 = V_22 ;
if ( 2 == ( V_31 = V_41 & 0x00000003 ) ) {
F_2
( L_13 ) ;
return 2 ;
}
V_16 -> V_23 = ( V_31 == 3 ) ;
V_16 -> V_80 [ V_16 -> V_26 ] =
( V_41 >> 16 ) & 0x000000007 ;
return 0 ;
case V_81 :
V_16 -> V_82 = V_41 & 0x0000FFFF ;
return 0 ;
case V_83 :
V_16 -> V_84 = ( V_41 >> 3 ) & 1 ;
return 0 ;
default:
F_2 ( L_14 , V_41 ) ;
return 2 ;
}
return 2 ;
}
static T_1 int
F_8 ( T_2 const * * V_85 , const T_2 * V_2 ,
T_4 * V_16 )
{
T_6 * V_86 =
( T_6 * ) V_16 -> V_8 -> V_87 ;
T_2 V_88 , V_89 , V_90 ;
int V_45 = 0 ;
int V_91 ;
const T_2 * V_1 = * V_85 ;
while ( V_1 < V_2 ) {
V_91 = 0 ;
if ( ( V_2 - V_1 ) < 2 ) {
F_2
( L_15 ) ;
V_45 = 1 ;
break;
}
if ( ( * V_1 & V_92 ) != V_93 )
break;
V_89 = * V_1 ++ ;
if ( ( * V_1 & V_92 ) != V_94 ) {
F_2 ( L_16 ,
* V_1 ) ;
V_45 = 1 ;
break;
}
V_88 =
* V_1 ++ | V_95 | V_96 |
V_97 ;
if ( V_16 -> V_98 && ( ( V_89 & ( 0xF << 11 ) ) == 0 ) ) {
F_2 ( L_17 ) ;
V_45 = 1 ;
break;
}
V_90 = 0 ;
if ( V_89 & ( 1 << 7 ) )
V_90 += ( V_16 -> V_84 ) ? 2 : 1 ;
if ( V_89 & ( 1 << 8 ) )
V_90 += ( V_16 -> V_84 ) ? 2 : 1 ;
if ( V_89 & ( 1 << 9 ) )
V_90 ++ ;
if ( V_89 & ( 1 << 10 ) )
V_90 ++ ;
if ( V_89 & ( 1 << 11 ) )
V_90 ++ ;
if ( V_89 & ( 1 << 12 ) )
V_90 ++ ;
if ( V_89 & ( 1 << 13 ) )
V_90 ++ ;
if ( V_89 & ( 1 << 14 ) )
V_90 ++ ;
while ( V_1 < V_2 ) {
if ( * V_1 == V_88 ) {
if ( V_86 -> V_99 >=
V_100 ) {
F_2 ( L_18 ) ;
V_45 = 1 ;
break;
}
V_86 -> V_101 [ V_86 ->
V_99 ++ ] =
V_1 ;
V_91 = 1 ;
V_1 ++ ;
if ( V_1 < V_2 && * V_1 == V_88 )
V_1 ++ ;
break;
}
if ( ( * V_1 == V_47 ) ||
( ( * V_1 & V_54 ) == V_55 ) ) {
F_2 ( L_19
L_20
L_21 ) ;
V_45 = 1 ;
break;
}
if ( ( V_45 = F_1 ( & V_1 , V_2 , V_90 ) ) )
break;
}
if ( V_1 >= V_2 && ! V_91 ) {
F_2 ( L_22
L_21 ) ;
V_45 = 1 ;
break;
}
if ( V_16 -> V_98 && ( ( V_1 - V_16 -> V_102 ) & 0x01 ) ) {
F_2 ( L_23 ) ;
V_45 = 1 ;
break;
}
}
* V_85 = V_1 ;
return V_45 ;
}
static T_1 T_7
F_9 ( T_2 const * * V_85 , const T_2 * V_2 ,
T_4 * V_103 )
{
T_2 V_41 ;
int V_104 ;
T_5 V_42 ;
const T_2 * V_1 = * V_85 ;
const T_5 * V_105 ;
if ( ( V_2 - V_1 ) < 2 ) {
F_2
( L_24 ) ;
return V_106 ;
}
V_1 ++ ;
V_41 = ( * V_1 ++ & 0xFFFF0000 ) >> 16 ;
switch ( V_41 ) {
case V_107 :
if ( F_8 ( & V_1 , V_2 , V_103 ) )
return V_106 ;
* V_85 = V_1 ;
return V_108 ;
case V_109 :
V_105 = V_110 ;
break;
case V_111 :
V_103 -> V_26 = 0 ;
V_105 = V_112 ;
break;
case ( V_111 | ( V_113 << 8 ) ) :
V_103 -> V_26 = 1 ;
V_105 = V_112 ;
break;
case ( V_111 | ( V_114 << 8 ) ) :
V_105 = V_115 ;
break;
case V_116 :
if ( F_1 ( & V_1 , V_2 , 2 ) )
return V_106 ;
* V_85 = V_1 ;
return V_108 ;
case ( V_117 | ( V_118 << 8 ) ) :
if ( F_1 ( & V_1 , V_2 , 32 ) )
return V_106 ;
* V_85 = V_1 ;
return V_108 ;
case ( V_117 | ( V_119 << 8 ) ) :
case ( V_117 | ( V_120 << 8 ) ) :
F_2 ( L_25
L_26 ) ;
return V_106 ;
case ( V_117 | ( V_121 << 8 ) ) :
F_2 ( L_27
L_26 ) ;
return V_106 ;
default:
F_2 ( L_28
L_29 ,
V_41 , * ( V_1 - 2 ) ) ;
* V_85 = V_1 ;
return V_106 ;
}
while ( V_1 < V_2 ) {
V_41 = * V_1 ++ ;
if ( ( V_42 = V_105 [ V_41 >> 24 ] ) ) {
if ( ( V_104 = F_7 ( V_41 , V_42 , V_103 ) ) ) {
if ( V_104 == 1 ) {
V_1 -- ;
break;
}
return V_106 ;
}
} else if ( V_103 -> V_17 &&
F_5 ( V_103 ) ) {
return V_106 ;
}
}
if ( V_103 -> V_17 && F_5 ( V_103 ) )
return V_106 ;
* V_85 = V_1 ;
return V_108 ;
}
static T_1 T_7
F_10 ( T_6 * V_86 , T_2 const * * V_85 ,
const T_2 * V_2 , int * V_122 )
{
T_2 V_41 ;
const T_2 * V_1 = * V_85 ;
const T_2 * V_123 ;
int V_124 = 0 ;
V_123 = V_86 -> V_101 [ * V_122 ] ;
V_1 ++ ;
V_41 = ( * V_1 & 0xFFFF0000 ) >> 16 ;
F_11 ( V_125 + V_126 , * V_1 ++ ) ;
switch ( V_41 ) {
case V_107 :
while ( ( V_1 < V_2 ) &&
( * V_122 < V_86 -> V_99 ) &&
( * V_1 & V_92 ) == V_93 ) {
while ( V_1 <= V_123 ) {
F_11 ( V_127 + V_126 +
( V_124 & 63 ) , * V_1 ++ ) ;
V_124 += 4 ;
}
if ( ( V_1 < V_2 )
&& ( ( * V_1 & V_54 ) == V_55 ) )
V_1 ++ ;
if ( ++ ( * V_122 ) < V_86 -> V_99 )
V_123 = V_86 -> V_101 [ * V_122 ] ;
}
break;
default:
while ( V_1 < V_2 ) {
if ( * V_1 == V_128 ||
( * V_1 & V_49 ) == V_50 ||
( * V_1 & V_129 ) == V_130 ||
( * V_1 & V_129 ) == V_131 )
break;
F_11 ( V_127 + V_126 +
( V_124 & 63 ) , * V_1 ++ ) ;
V_124 += 4 ;
}
}
* V_85 = V_1 ;
return V_108 ;
}
static T_1 int F_12 ( T_2 V_132 )
{
if ( ( V_132 > 0x3FF ) && ( V_132 < 0xC00 ) ) {
F_2 ( L_30
L_31 ) ;
return 1 ;
} else if ( ( V_132 > 0xCFF ) && ( V_132 < 0x1300 ) ) {
F_2 ( L_30
L_32 ) ;
return 1 ;
} else if ( V_132 > 0x13FF ) {
F_2 ( L_30
L_33 ) ;
return 1 ;
}
return 0 ;
}
static T_1 int
F_13 ( T_2 const * * V_85 , const T_2 * V_2 ,
T_2 V_133 )
{
const T_2 * V_1 = * V_85 ;
if ( V_2 - V_1 < V_133 ) {
F_2 ( L_34 ) ;
return 1 ;
}
while ( V_133 -- ) {
if ( * V_1 ++ ) {
F_2 ( L_35 ) ;
return 1 ;
}
}
* V_85 = V_1 ;
return 0 ;
}
static T_1 T_7
F_14 ( T_2 const * * V_85 , const T_2 * V_2 )
{
T_2 V_41 ;
const T_2 * V_1 = * V_85 ;
T_7 V_45 = V_108 ;
while ( V_1 < V_2 ) {
V_41 = * V_1 ;
if ( ( V_41 > ( ( 0x3FF >> 2 ) | V_50 ) ) &&
( V_41 < ( ( 0xC00 >> 2 ) | V_50 ) ) ) {
if ( ( V_41 & V_49 ) != V_50 )
break;
F_2 ( L_36
L_31 ) ;
V_45 = V_106 ;
break;
} else if ( V_41 > ( ( 0xCFF >> 2 ) | V_50 ) ) {
if ( ( V_41 & V_49 ) != V_50 )
break;
F_2 ( L_36
L_33 ) ;
V_45 = V_106 ;
break;
} else {
V_1 += 2 ;
}
}
* V_85 = V_1 ;
return V_45 ;
}
static T_1 T_7
F_15 ( T_6 * V_86 , T_2 const * * V_85 ,
const T_2 * V_2 )
{
register T_2 V_41 ;
const T_2 * V_1 = * V_85 ;
while ( V_1 < V_2 ) {
V_41 = * V_1 ;
if ( ( V_41 & V_49 ) != V_50 )
break;
F_11 ( ( V_41 & ~ V_49 ) << 2 , * ++ V_1 ) ;
V_1 ++ ;
}
* V_85 = V_1 ;
return V_108 ;
}
static T_1 T_7
F_16 ( T_2 const * * V_85 , const T_2 * V_2 )
{
T_2 V_134 ;
const T_2 * V_1 = * V_85 ;
if ( V_2 - V_1 < 4 ) {
F_2 ( L_37 ) ;
return V_106 ;
}
V_134 = * V_1 ++ & ~ V_129 ;
if ( F_12 ( V_134 ) )
return V_106 ;
V_134 = * V_1 ++ ;
if ( * V_1 ++ != 0x00F50000 ) {
F_2 ( L_38 ) ;
return V_106 ;
}
if ( * V_1 ++ != 0x00000000 ) {
F_2 ( L_38 ) ;
return V_106 ;
}
if ( F_1 ( & V_1 , V_2 , V_134 ) )
return V_106 ;
if ( ( V_134 & 3 ) && F_13 ( & V_1 , V_2 , 4 - ( V_134 & 3 ) ) )
return V_106 ;
* V_85 = V_1 ;
return V_108 ;
}
static T_1 T_7
F_17 ( T_6 * V_86 , T_2 const * * V_85 ,
const T_2 * V_2 )
{
T_2 V_32 , V_135 , V_36 ;
const T_2 * V_1 = * V_85 ;
V_32 = * V_1 ++ & ~ V_129 ;
V_36 = V_135 = * V_1 ;
V_1 += 3 ;
while ( V_36 -- )
F_11 ( V_32 , * V_1 ++ ) ;
if ( V_135 & 3 )
V_1 += 4 - ( V_135 & 3 ) ;
* V_85 = V_1 ;
return V_108 ;
}
static T_1 T_7
F_18 ( T_2 const * * V_85 , const T_2 * V_2 )
{
T_2 V_134 ;
const T_2 * V_1 = * V_85 ;
T_2 V_36 ;
if ( V_2 - V_1 < 4 ) {
F_2 ( L_39 ) ;
return V_106 ;
}
V_1 ++ ;
V_134 = * V_1 ++ ;
if ( * V_1 ++ != 0x00F60000 ) {
F_2 ( L_40 ) ;
return V_106 ;
}
if ( * V_1 ++ != 0x00000000 ) {
F_2 ( L_40 ) ;
return V_106 ;
}
if ( ( V_2 - V_1 ) < ( V_134 << 1 ) ) {
F_2 ( L_39 ) ;
return V_106 ;
}
for ( V_36 = 0 ; V_36 < V_134 ; ++ V_36 ) {
if ( F_12 ( * V_1 ++ ) )
return V_106 ;
V_1 ++ ;
}
V_134 <<= 1 ;
if ( ( V_134 & 3 ) && F_13 ( & V_1 , V_2 , 4 - ( V_134 & 3 ) ) )
return V_106 ;
* V_85 = V_1 ;
return V_108 ;
}
static T_1 T_7
F_19 ( T_6 * V_86 , T_2 const * * V_85 ,
const T_2 * V_2 )
{
T_2 V_32 , V_135 , V_36 ;
const T_2 * V_1 = * V_85 ;
V_36 = V_135 = * ++ V_1 ;
V_1 += 3 ;
while ( V_36 -- ) {
V_32 = * V_1 ++ ;
F_11 ( V_32 , * V_1 ++ ) ;
}
V_135 <<= 1 ;
if ( V_135 & 3 )
V_1 += 4 - ( V_135 & 3 ) ;
* V_85 = V_1 ;
return V_108 ;
}
int
F_20 ( const T_2 * V_1 , unsigned int V_6 ,
struct V_7 * V_8 , int V_98 )
{
T_6 * V_86 = ( T_6 * ) V_8 -> V_87 ;
T_4 * V_103 = & V_86 -> V_103 ;
T_4 V_136 = * V_103 ;
T_2 V_41 ;
const T_2 * V_2 = V_1 + ( V_6 >> 2 ) ;
T_7 V_137 = V_108 ;
int V_138 ;
int V_139 ;
V_138 = ( V_86 -> V_140 == V_141 ||
V_86 -> V_140 == V_142 ) ;
V_139 = V_86 -> V_140 != V_142 ;
V_103 -> V_8 = V_8 ;
V_103 -> V_17 = V_40 ;
V_103 -> V_12 = NULL ;
V_103 -> V_98 = V_98 ;
V_103 -> V_102 = V_1 ;
V_86 -> V_99 = 0 ;
while ( V_1 < V_2 ) {
switch ( V_137 ) {
case V_143 :
V_137 = F_9 ( & V_1 , V_2 , V_103 ) ;
break;
case V_144 :
V_137 = F_14 ( & V_1 , V_2 ) ;
break;
case V_145 :
V_137 = F_16 ( & V_1 , V_2 ) ;
break;
case V_146 :
V_137 = F_18 ( & V_1 , V_2 ) ;
break;
case V_108 :
if ( ( V_47 == ( V_41 = * V_1 ) ) &&
V_139 )
V_137 = V_143 ;
else if ( ( V_41 & V_49 ) == V_50 )
V_137 = V_144 ;
else if ( V_138
&& ( V_41 & V_129 ) == V_130 )
V_137 = V_145 ;
else if ( V_138
&& ( V_41 & V_129 ) == V_131 )
V_137 = V_146 ;
else if ( ( V_41 == V_47 ) && ! V_139 ) {
F_2 ( L_41 ) ;
V_137 = V_106 ;
} else {
F_2
( L_42 ,
V_41 ) ;
V_137 = V_106 ;
}
break;
case V_106 :
default:
* V_103 = V_136 ;
return - V_147 ;
}
}
if ( V_137 == V_106 ) {
* V_103 = V_136 ;
return - V_147 ;
}
return 0 ;
}
int
F_21 ( struct V_7 * V_8 , const T_2 * V_1 ,
unsigned int V_6 )
{
T_6 * V_86 = ( T_6 * ) V_8 -> V_87 ;
T_2 V_41 ;
const T_2 * V_2 = V_1 + ( V_6 >> 2 ) ;
T_7 V_137 = V_108 ;
int V_122 = 0 ;
while ( V_1 < V_2 ) {
switch ( V_137 ) {
case V_143 :
V_137 =
F_10 ( V_86 , & V_1 , V_2 ,
& V_122 ) ;
break;
case V_144 :
V_137 = F_15 ( V_86 , & V_1 , V_2 ) ;
break;
case V_145 :
V_137 = F_17 ( V_86 , & V_1 , V_2 ) ;
break;
case V_146 :
V_137 = F_19 ( V_86 , & V_1 , V_2 ) ;
break;
case V_108 :
if ( V_47 == ( V_41 = * V_1 ) )
V_137 = V_143 ;
else if ( ( V_41 & V_49 ) == V_50 )
V_137 = V_144 ;
else if ( ( V_41 & V_129 ) == V_130 )
V_137 = V_145 ;
else if ( ( V_41 & V_129 ) == V_131 )
V_137 = V_146 ;
else {
F_2
( L_42 ,
V_41 ) ;
V_137 = V_106 ;
}
break;
case V_106 :
default:
return - V_147 ;
}
}
if ( V_137 == V_106 )
return - V_147 ;
return 0 ;
}
static void
F_22 ( T_8 V_148 [] , T_5 V_149 [] , int V_6 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < 256 ; ++ V_36 )
V_149 [ V_36 ] = V_150 ;
for ( V_36 = 0 ; V_36 < V_6 ; ++ V_36 )
V_149 [ V_148 [ V_36 ] . V_151 ] = V_148 [ V_36 ] . V_42 ;
}
void F_23 ( void )
{
F_22 ( V_152 , V_110 ,
sizeof( V_152 ) / sizeof( T_8 ) ) ;
F_22 ( V_153 , V_112 ,
sizeof( V_153 ) / sizeof( T_8 ) ) ;
F_22 ( V_154 , V_115 ,
sizeof( V_154 ) / sizeof( T_8 ) ) ;
}
