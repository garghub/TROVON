static void F_1 ( struct V_1 * V_2 , int V_3 [] ,
int V_4 )
{
int V_5 = 0 ;
if ( V_3 [ 0 ] == 256 && V_3 [ 1 ] == 256 )
return;
if ( V_4 == 4 ) {
short * V_6 , * V_7 ;
V_6 = ( short * ) V_2 -> V_8 ;
V_7 = V_6 + V_2 -> V_9 / sizeof( * V_6 ) ;
for (; V_6 < V_7 ; ++ V_6 ) {
* V_6 = ( * V_6 * V_3 [ V_5 & 1 ] ) >> 8 ;
++ V_5 ;
}
} else if ( V_4 == 6 ) {
unsigned char * V_6 , * V_7 ;
V_6 = ( unsigned char * ) V_2 -> V_8 ;
V_7 = V_6 + V_2 -> V_9 ;
for (; V_6 < V_7 ; V_6 += 3 ) {
int V_10 ;
V_10 = V_6 [ 0 ] + ( V_6 [ 1 ] << 8 ) + ( ( signed char ) V_6 [ 2 ] << 16 ) ;
V_10 = ( V_10 * V_3 [ V_5 & 1 ] ) >> 8 ;
V_6 [ 0 ] = V_10 ;
V_6 [ 1 ] = V_10 >> 8 ;
V_6 [ 2 ] = V_10 >> 16 ;
++ V_5 ;
}
}
}
static void F_2 ( struct V_11 * V_12 ,
struct V_1 * V_2 , int V_4 )
{
int V_13 = V_2 -> V_9 / V_4 ;
if ( V_4 == 4 ) {
int V_14 ;
short * V_15 = ( short * ) V_12 -> V_16 ;
short * V_17 = ( short * ) V_2 -> V_8 ;
for ( V_14 = 0 ; V_14 < V_13 ; ++ V_14 ) {
V_17 [ 0 ] = V_15 [ 0 ] ;
V_17 [ 1 ] = 0 ;
V_15 += 2 ;
V_17 += 2 ;
}
} else if ( V_4 == 6 ) {
int V_14 , V_18 ;
unsigned char * V_15 = V_12 -> V_16 ;
unsigned char * V_17 = V_2 -> V_8 ;
for ( V_14 = 0 ; V_14 < V_13 ; ++ V_14 ) {
for ( V_18 = 0 ; V_18 < V_4 / 2 ; ++ V_18 )
V_17 [ V_18 ] = V_15 [ V_18 ] ;
for (; V_18 < V_4 ; ++ V_18 )
V_17 [ V_18 ] = 0 ;
V_15 += V_4 ;
V_17 += V_4 ;
}
}
if ( -- V_12 -> V_19 <= 0 ) {
( ( unsigned char * ) ( V_2 -> V_8 ) ) [ V_4 -
1 ] =
V_12 -> V_20 ;
V_12 -> V_19 = V_12 -> V_21 ;
}
}
static void F_3 ( struct V_1 * V_2 , unsigned char * signal ,
int V_3 , int V_4 )
{
if ( V_3 == 0 )
return;
if ( V_4 == 4 ) {
short * V_15 , * V_17 , * V_7 ;
V_15 = ( short * ) signal ;
V_17 = ( short * ) V_2 -> V_8 ;
V_7 = V_17 + V_2 -> V_9 / sizeof( * V_17 ) ;
for (; V_17 < V_7 ; ++ V_15 , ++ V_17 )
* V_17 += ( * V_15 * V_3 ) >> 8 ;
}
}
static int F_4 ( struct V_11 * V_12 )
{
int V_22 ;
unsigned long V_23 ;
int V_14 , V_24 , V_25 ;
int V_26 ;
const int V_4 = V_12 -> V_27 -> V_4 ;
const int V_28 =
V_12 -> V_27 -> V_29 . V_30 [ 0 ] . V_31 ;
const int V_32 =
V_12 -> V_27 -> V_29 . V_30 [ 0 ] . V_33 *
( V_34 / V_35 ) ;
struct V_1 * V_2 ;
F_5 ( & V_12 -> V_36 , V_23 ) ;
V_22 =
F_6 ( & V_12 -> V_37 , V_38 ) ;
if ( V_22 < 0 || V_22 >= V_38 ) {
F_7 ( & V_12 -> V_36 , V_23 ) ;
F_8 ( V_12 -> V_39 -> V_40 , L_1 ) ;
return - V_41 ;
}
V_2 = V_12 -> V_42 [ V_22 ] ;
V_24 = 0 ;
for ( V_14 = 0 ; V_14 < V_43 ; ++ V_14 ) {
int V_44 = 0 ;
struct V_45 * V_46 =
& V_2 -> V_47 [ V_14 ] ;
if ( V_12 -> V_23 & V_48 )
V_44 = V_12 -> V_49 ;
if ( V_44 == 0 ) {
int V_50 ;
V_12 -> V_51 += V_28 ;
V_50 = V_12 -> V_51 / V_32 ;
V_12 -> V_51 -= V_50 * V_32 ;
V_44 = V_50 * V_4 ;
}
V_46 -> V_52 = V_24 ;
V_46 -> V_53 = V_44 ;
V_24 += V_44 ;
}
if ( V_24 == 0 ) {
F_7 ( & V_12 -> V_36 , V_23 ) ;
F_8 ( V_12 -> V_39 -> V_40 , L_2 ) ;
return - V_41 ;
}
V_25 = V_24 / V_4 ;
V_2 -> V_8 =
V_12 -> V_54 +
V_22 * V_43 * V_12 -> V_55 ;
V_2 -> V_9 = V_24 ;
V_2 -> V_56 = V_12 ;
if ( F_9 ( V_57 , & V_12 -> V_23 ) &&
! F_9 ( V_58 , & V_12 -> V_23 ) ) {
struct V_59 * V_60 =
F_10 ( V_12 , V_61 ) -> V_60 ;
if ( V_12 -> V_62 + V_25 > V_60 -> V_63 ) {
int V_64 ;
V_64 = V_60 -> V_63 - V_12 -> V_62 ;
if ( V_64 > 0 ) {
memcpy ( V_2 -> V_8 ,
V_60 -> V_65 +
V_12 -> V_62 * V_4 ,
V_64 * V_4 ) ;
memcpy ( V_2 -> V_8 +
V_64 * V_4 , V_60 -> V_65 ,
( V_25 - V_64 ) * V_4 ) ;
} else
F_8 ( V_12 -> V_39 -> V_40 , L_3 ,
V_64 ) ;
} else {
memcpy ( V_2 -> V_8 ,
V_60 -> V_65 +
V_12 -> V_62 * V_4 ,
V_2 -> V_9 ) ;
}
V_12 -> V_62 += V_25 ;
if ( V_12 -> V_62 >= V_60 -> V_63 )
V_12 -> V_62 -= V_60 -> V_63 ;
} else {
memset ( V_2 -> V_8 , 0 ,
V_2 -> V_9 ) ;
}
F_1 ( V_2 , V_12 -> V_66 , V_4 ) ;
if ( V_12 -> V_16 != NULL ) {
#ifdef F_11
if ( V_12 -> V_23 & V_67 ) {
F_2 ( V_12 , V_2 ,
V_4 ) ;
if ( V_12 -> V_23 & V_68 ) {
F_12 ( V_12 ,
V_2 -> V_8 ,
V_2 ->
V_9 ) ;
F_13 ( V_12 ,
V_2 -> V_9 ) ;
}
} else {
#endif
if ( !
( V_12 -> V_39 ->
V_27 -> V_69 & V_70 )
&& ( V_12 -> V_23 & V_71 )
&& ( V_12 -> V_23 & V_48 ) )
F_3 ( V_2 , V_12 -> V_16 ,
V_12 -> V_72 ,
V_4 ) ;
#ifdef F_11
}
#endif
}
V_26 = F_14 ( V_2 , V_73 ) ;
if ( V_26 == 0 )
F_15 ( V_22 , & V_12 -> V_37 ) ;
else
F_8 ( V_12 -> V_39 -> V_40 ,
L_4 , V_22 , V_26 ) ;
F_7 ( & V_12 -> V_36 , V_23 ) ;
return 0 ;
}
int F_16 ( struct V_11 * V_12 )
{
int V_26 , V_14 ;
for ( V_14 = 0 ; V_14 < V_38 ; ++ V_14 ) {
V_26 = F_4 ( V_12 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
void F_17 ( struct V_11 * V_12 )
{
unsigned int V_14 ;
for ( V_14 = V_38 ; V_14 -- ; ) {
if ( F_9 ( V_14 , & V_12 -> V_37 ) ) {
if ( ! F_18 ( V_14 , & V_12 -> V_74 ) ) {
struct V_1 * V_75 = V_12 -> V_42 [ V_14 ] ;
F_19 ( V_75 ) ;
}
}
}
}
void F_20 ( struct V_11 * V_12 )
{
int V_76 = V_77 ;
unsigned int V_14 ;
int V_78 ;
do {
V_78 = 0 ;
for ( V_14 = V_38 ; V_14 -- ; ) {
if ( F_9 ( V_14 , & V_12 -> V_37 ) )
V_78 ++ ;
}
if ( ! V_78 )
break;
F_21 ( V_79 ) ;
F_22 ( 1 ) ;
} while ( -- V_76 > 0 );
if ( V_78 )
F_23 ( V_80 L_5 , V_78 ) ;
}
void F_24 ( struct V_11 * V_12 )
{
F_17 ( V_12 ) ;
F_20 ( V_12 ) ;
}
void F_25 ( struct V_11 * V_12 )
{
F_26 ( V_12 -> V_54 ) ;
V_12 -> V_54 = NULL ;
}
static void F_27 ( struct V_1 * V_1 )
{
int V_14 , V_22 , V_53 = 0 , V_81 = 0 ;
unsigned long V_23 ;
struct V_11 * V_12 = (struct V_11 * ) V_1 -> V_56 ;
struct V_82 * V_83 =
F_10 ( V_12 , V_61 ) ;
#if V_84
memset ( V_1 -> V_8 , 0 , V_1 -> V_9 ) ;
#endif
V_12 -> V_85 = V_1 -> V_86 ;
for ( V_22 = V_38 ; V_22 -- ; )
if ( V_1 == V_12 -> V_42 [ V_22 ] )
break;
if ( V_22 < 0 )
return;
for ( V_14 = V_43 ; V_14 -- ; )
V_53 += V_1 -> V_47 [ V_14 ] . V_53 ;
F_5 ( & V_12 -> V_36 , V_23 ) ;
if ( F_9 ( V_57 , & V_12 -> V_23 ) ) {
struct V_59 * V_60 = V_83 -> V_60 ;
V_12 -> V_87 +=
V_53 / V_12 -> V_27 -> V_4 ;
if ( V_12 -> V_87 >= V_60 -> V_63 )
V_12 -> V_87 -= V_60 -> V_63 ;
}
F_28 ( V_22 , & V_12 -> V_37 ) ;
for ( V_14 = V_43 ; V_14 -- ; )
if ( V_1 -> V_47 [ V_14 ] . V_88 == - V_89 ) {
V_81 = 1 ;
break;
}
if ( F_29 ( V_22 , & V_12 -> V_74 ) )
V_81 = 1 ;
F_7 ( & V_12 -> V_36 , V_23 ) ;
if ( ! V_81 ) {
F_4 ( V_12 ) ;
if ( F_9 ( V_57 ,
& V_12 -> V_23 ) ) {
V_12 -> V_90 += V_53 ;
if ( V_12 -> V_90 >= V_12 -> V_91 ) {
V_12 -> V_90 %= V_12 -> V_91 ;
F_30 ( V_83 ) ;
}
}
}
}
static int F_31 ( struct V_82 * V_83 )
{
int V_92 ;
struct V_59 * V_60 = V_83 -> V_60 ;
struct V_11 * V_12 = F_32 ( V_83 ) ;
V_92 = F_33 ( V_60 , 0 , V_93 ,
( & V_12 ->
V_27 -> V_29 ) ) ;
if ( V_92 < 0 )
return V_92 ;
V_60 -> V_94 = V_12 -> V_27 -> V_95 ;
return 0 ;
}
static int F_34 ( struct V_82 * V_83 )
{
return 0 ;
}
static int F_35 ( struct V_82 * V_83 ,
struct V_96 * V_97 )
{
int V_26 ;
struct V_11 * V_12 = F_32 ( V_83 ) ;
if ( V_12 == NULL ) {
if ( V_83 -> V_98 == NULL )
return - V_99 ;
if ( V_83 -> V_98 -> V_100 == NULL )
return - V_99 ;
V_83 -> V_100 = V_83 -> V_98 -> V_100 ;
V_12 = F_32 ( V_83 ) ;
}
V_26 = F_36 ( V_12 , V_101 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_37 ( V_83 ,
F_38 ( V_97 ) ) ;
if ( V_26 < 0 ) {
F_39 ( V_12 , V_101 ) ;
return V_26 ;
}
V_12 -> V_91 = F_40 ( V_97 ) ;
return 0 ;
}
static int F_41 ( struct V_82 * V_83 )
{
struct V_11 * V_12 = F_32 ( V_83 ) ;
F_39 ( V_12 , V_101 ) ;
return F_42 ( V_83 ) ;
}
int F_43 ( struct V_11 * V_12 , int V_102 )
{
int V_92 ;
switch ( V_102 ) {
case V_103 :
#ifdef F_44
case V_104 :
#endif
V_92 = F_36 ( V_12 ,
V_105 ) ;
if ( V_92 < 0 )
return V_92 ;
break;
case V_106 :
#ifdef F_44
case V_107 :
#endif
V_92 = F_39 ( V_12 ,
V_105 ) ;
if ( V_92 < 0 )
return V_92 ;
break;
case V_108 :
F_15 ( V_58 , & V_12 -> V_23 ) ;
break;
case V_109 :
F_28 ( V_58 , & V_12 -> V_23 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static T_1
F_45 ( struct V_82 * V_83 )
{
struct V_11 * V_12 = F_32 ( V_83 ) ;
return V_12 -> V_87 ;
}
int F_46 ( struct V_11 * V_12 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_38 ; ++ V_14 ) {
struct V_1 * V_1 ;
V_1 = V_12 -> V_42 [ V_14 ] =
F_47 ( V_43 , V_110 ) ;
if ( V_1 == NULL ) {
F_8 ( V_12 -> V_39 -> V_40 , L_6 ) ;
return - V_99 ;
}
V_1 -> V_111 = V_12 -> V_39 -> V_112 ;
V_1 -> V_113 =
F_48 ( V_12 -> V_39 -> V_112 ,
V_12 -> V_114 &
V_115 ) ;
V_1 -> V_116 = V_117 ;
V_1 -> V_86 = - 1 ;
V_1 -> V_118 = V_43 ;
V_1 -> V_119 = V_35 ;
V_1 -> V_120 = 0 ;
V_1 -> V_121 = F_27 ;
}
return 0 ;
}
