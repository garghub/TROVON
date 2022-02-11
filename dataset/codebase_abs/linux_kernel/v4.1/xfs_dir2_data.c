int
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 * V_6 ;
T_3 * V_7 = NULL ;
int V_8 ;
T_4 * V_9 ;
T_5 * V_10 ;
T_2 * V_11 ;
T_6 * V_12 ;
char * V_13 ;
int V_14 ;
T_7 V_15 ;
int V_16 ;
int V_17 ;
T_8 * V_18 = NULL ;
T_9 * V_19 ;
char * V_20 ;
int V_21 ;
struct V_22 V_23 ;
const struct V_24 * V_25 ;
struct V_26 * V_27 ;
V_19 = V_4 -> V_28 -> V_29 ;
V_27 = V_19 -> V_30 ;
V_25 = F_2 ( V_19 , V_2 ) ;
V_9 = V_4 -> V_31 ;
V_20 = ( char * ) V_25 -> V_32 ( V_9 ) ;
switch ( V_9 -> V_33 ) {
case F_3 ( V_34 ) :
case F_3 ( V_35 ) :
V_7 = F_4 ( V_27 , V_9 ) ;
V_18 = F_5 ( V_7 ) ;
V_13 = ( char * ) V_18 ;
F_6 ( V_19 , F_7 ( V_7 -> V_8 ) <
( ( char * ) V_7 - V_20 ) / sizeof( struct V_36 ) ) ;
break;
case F_3 ( V_37 ) :
case F_3 ( V_38 ) :
V_13 = ( char * ) V_9 + V_27 -> V_39 ;
break;
default:
F_8 ( L_1 , V_40 , V_19 ) ;
return - V_41 ;
}
V_6 = V_25 -> V_42 ( V_9 ) ;
V_8 = V_17 = V_14 = 0 ;
if ( ! V_6 [ 0 ] . V_43 ) {
F_6 ( V_19 , ! V_6 [ 0 ] . V_44 ) ;
V_14 |= 1 << 0 ;
}
if ( ! V_6 [ 1 ] . V_43 ) {
F_6 ( V_19 , ! V_6 [ 1 ] . V_44 ) ;
V_14 |= 1 << 1 ;
}
if ( ! V_6 [ 2 ] . V_43 ) {
F_6 ( V_19 , ! V_6 [ 2 ] . V_44 ) ;
V_14 |= 1 << 2 ;
}
F_6 ( V_19 , F_9 ( V_6 [ 0 ] . V_43 ) >=
F_9 ( V_6 [ 1 ] . V_43 ) ) ;
F_6 ( V_19 , F_9 ( V_6 [ 1 ] . V_43 ) >=
F_9 ( V_6 [ 2 ] . V_43 ) ) ;
while ( V_20 < V_13 ) {
V_12 = ( T_6 * ) V_20 ;
if ( F_9 ( V_12 -> V_45 ) == V_46 ) {
F_6 ( V_19 , V_17 == 0 ) ;
F_6 ( V_19 ,
F_9 ( * F_10 ( V_12 ) ) ==
( char * ) V_12 - ( char * ) V_9 ) ;
V_11 = F_11 ( V_9 , V_6 , V_12 ) ;
if ( V_11 ) {
V_16 = ( int ) ( V_11 - V_6 ) ;
F_6 ( V_19 ,
( V_14 & ( 1 << V_16 ) ) == 0 ) ;
V_14 |= 1 << V_16 ;
} else {
F_6 ( V_19 ,
F_9 ( V_12 -> V_43 ) <=
F_9 ( V_6 [ 2 ] . V_43 ) ) ;
}
V_20 += F_9 ( V_12 -> V_43 ) ;
V_17 = 1 ;
continue;
}
V_10 = ( T_5 * ) V_20 ;
F_6 ( V_19 , V_10 -> V_47 != 0 ) ;
F_6 ( V_19 ,
! F_12 ( V_19 , F_13 ( V_10 -> V_48 ) ) ) ;
F_6 ( V_19 ,
F_9 ( * V_25 -> V_49 ( V_10 ) ) ==
( char * ) V_10 - ( char * ) V_9 ) ;
F_6 ( V_19 ,
V_25 -> V_50 ( V_10 ) < V_51 ) ;
V_8 ++ ;
V_17 = 0 ;
if ( V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) {
V_5 = F_14 ( V_27 , V_27 -> V_52 ,
( V_53 )
( ( char * ) V_10 - ( char * ) V_9 ) ) ;
V_23 . V_23 = V_10 -> V_23 ;
V_23 . V_54 = V_10 -> V_47 ;
V_15 = V_19 -> V_55 -> V_56 ( & V_23 ) ;
for ( V_16 = 0 ; V_16 < F_7 ( V_7 -> V_8 ) ; V_16 ++ ) {
if ( F_7 ( V_18 [ V_16 ] . V_57 ) == V_5 &&
F_7 ( V_18 [ V_16 ] . V_58 ) == V_15 )
break;
}
F_6 ( V_19 ,
V_16 < F_7 ( V_7 -> V_8 ) ) ;
}
V_20 += V_25 -> V_59 ( V_10 -> V_47 ) ;
}
F_6 ( V_19 , V_14 == 7 ) ;
if ( V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) {
for ( V_16 = V_21 = 0 ; V_16 < F_7 ( V_7 -> V_8 ) ; V_16 ++ ) {
if ( V_18 [ V_16 ] . V_57 ==
F_3 ( V_60 ) )
V_21 ++ ;
if ( V_16 > 0 )
F_6 ( V_19 ,
F_7 ( V_18 [ V_16 ] . V_58 ) >=
F_7 ( V_18 [ V_16 - 1 ] . V_58 ) ) ;
}
F_6 ( V_19 , V_8 ==
F_7 ( V_7 -> V_8 ) - F_7 ( V_7 -> V_21 ) ) ;
F_6 ( V_19 , V_21 == F_7 ( V_7 -> V_21 ) ) ;
}
return 0 ;
}
static bool
F_15 (
struct V_3 * V_4 )
{
struct V_61 * V_19 = V_4 -> V_28 -> V_29 ;
struct V_62 * V_63 = V_4 -> V_31 ;
if ( F_16 ( & V_19 -> V_64 ) ) {
if ( V_63 -> V_33 != F_3 ( V_37 ) )
return false ;
if ( ! F_17 ( & V_63 -> V_65 , & V_19 -> V_64 . V_66 ) )
return false ;
if ( F_13 ( V_63 -> V_67 ) != V_4 -> V_68 )
return false ;
} else {
if ( V_63 -> V_33 != F_3 ( V_38 ) )
return false ;
}
if ( F_1 ( NULL , V_4 ) )
return false ;
return true ;
}
static void
F_18 (
struct V_3 * V_4 )
{
struct V_69 * V_9 = V_4 -> V_31 ;
switch ( V_9 -> V_33 ) {
case F_3 ( V_35 ) :
case F_3 ( V_34 ) :
V_4 -> V_70 = & V_71 ;
V_4 -> V_70 -> V_72 ( V_4 ) ;
return;
case F_3 ( V_38 ) :
case F_3 ( V_37 ) :
F_15 ( V_4 ) ;
return;
default:
F_19 ( V_4 , - V_41 ) ;
F_20 ( V_4 ) ;
break;
}
}
static void
F_21 (
struct V_3 * V_4 )
{
struct V_61 * V_19 = V_4 -> V_28 -> V_29 ;
if ( F_16 ( & V_19 -> V_64 ) &&
! F_22 ( V_4 , V_73 ) )
F_19 ( V_4 , - V_74 ) ;
else if ( ! F_15 ( V_4 ) )
F_19 ( V_4 , - V_41 ) ;
if ( V_4 -> V_75 )
F_20 ( V_4 ) ;
}
static void
F_23 (
struct V_3 * V_4 )
{
struct V_61 * V_19 = V_4 -> V_28 -> V_29 ;
struct V_76 * V_77 = V_4 -> V_78 ;
struct V_62 * V_63 = V_4 -> V_31 ;
if ( ! F_15 ( V_4 ) ) {
F_19 ( V_4 , - V_41 ) ;
F_20 ( V_4 ) ;
return;
}
if ( ! F_16 ( & V_19 -> V_64 ) )
return;
if ( V_77 )
V_63 -> V_79 = F_24 ( V_77 -> V_80 . V_81 ) ;
F_25 ( V_4 , V_73 ) ;
}
int
F_26 (
struct V_82 * V_83 ,
struct V_1 * V_2 ,
T_10 V_84 ,
T_11 V_85 ,
struct V_3 * * V_86 )
{
int V_87 ;
V_87 = F_27 ( V_83 , V_2 , V_84 , V_85 , V_86 ,
V_88 , & V_89 ) ;
if ( ! V_87 && V_83 )
F_28 ( V_83 , * V_86 , V_90 ) ;
return V_87 ;
}
int
F_29 (
struct V_1 * V_2 ,
T_10 V_84 ,
T_11 V_85 )
{
return F_30 ( V_2 , V_84 , V_85 ,
V_88 , & V_91 ) ;
}
T_2 *
F_11 (
struct V_69 * V_9 ,
struct V_92 * V_6 ,
struct V_93 * V_12 )
{
T_2 * V_11 ;
V_53 V_94 ;
#ifdef F_31
int V_95 ;
int V_96 ;
#endif
V_94 = ( V_53 ) ( ( char * ) V_12 - ( char * ) V_9 ) ;
#ifdef F_31
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
for ( V_11 = & V_6 [ 0 ] , V_96 = V_95 = 0 ;
V_11 < & V_6 [ V_97 ] ;
V_11 ++ ) {
if ( ! V_11 -> V_44 ) {
ASSERT ( ! V_11 -> V_43 ) ;
V_96 = 1 ;
continue;
}
ASSERT ( V_96 == 0 ) ;
if ( F_9 ( V_11 -> V_44 ) == V_94 ) {
V_95 = 1 ;
ASSERT ( V_11 -> V_43 == V_12 -> V_43 ) ;
} else if ( V_94 < F_9 ( V_11 -> V_44 ) )
ASSERT ( V_94 + F_9 ( V_12 -> V_43 ) <= F_9 ( V_11 -> V_44 ) ) ;
else
ASSERT ( F_9 ( V_11 -> V_44 ) + F_9 ( V_11 -> V_43 ) <= V_94 ) ;
ASSERT ( V_95 || F_9 ( V_11 -> V_43 ) >= F_9 ( V_12 -> V_43 ) ) ;
if ( V_11 > & V_6 [ 0 ] )
ASSERT ( F_9 ( V_11 [ - 1 ] . V_43 ) >= F_9 ( V_11 [ 0 ] . V_43 ) ) ;
}
#endif
if ( F_9 ( V_12 -> V_43 ) <
F_9 ( V_6 [ V_97 - 1 ] . V_43 ) )
return NULL ;
for ( V_11 = & V_6 [ 0 ] ; V_11 < & V_6 [ V_97 ] ; V_11 ++ ) {
if ( ! V_11 -> V_44 )
return NULL ;
if ( F_9 ( V_11 -> V_44 ) == V_94 )
return V_11 ;
}
return NULL ;
}
T_2 *
F_32 (
struct V_69 * V_9 ,
struct V_92 * V_11 ,
struct V_93 * V_12 ,
int * V_98 )
{
T_2 V_99 ;
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
V_99 . V_43 = V_12 -> V_43 ;
V_99 . V_44 = F_33 ( ( char * ) V_12 - ( char * ) V_9 ) ;
if ( F_9 ( V_99 . V_43 ) > F_9 ( V_11 [ 0 ] . V_43 ) ) {
V_11 [ 2 ] = V_11 [ 1 ] ;
V_11 [ 1 ] = V_11 [ 0 ] ;
V_11 [ 0 ] = V_99 ;
* V_98 = 1 ;
return & V_11 [ 0 ] ;
}
if ( F_9 ( V_99 . V_43 ) > F_9 ( V_11 [ 1 ] . V_43 ) ) {
V_11 [ 2 ] = V_11 [ 1 ] ;
V_11 [ 1 ] = V_99 ;
* V_98 = 1 ;
return & V_11 [ 1 ] ;
}
if ( F_9 ( V_99 . V_43 ) > F_9 ( V_11 [ 2 ] . V_43 ) ) {
V_11 [ 2 ] = V_99 ;
* V_98 = 1 ;
return & V_11 [ 2 ] ;
}
return NULL ;
}
STATIC void
F_34 (
struct V_69 * V_9 ,
struct V_92 * V_6 ,
struct V_92 * V_11 ,
int * V_98 )
{
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
if ( V_11 == & V_6 [ 0 ] ) {
V_6 [ 0 ] = V_6 [ 1 ] ;
V_6 [ 1 ] = V_6 [ 2 ] ;
}
else if ( V_11 == & V_6 [ 1 ] )
V_6 [ 1 ] = V_6 [ 2 ] ;
else
ASSERT ( V_11 == & V_6 [ 2 ] ) ;
V_6 [ 2 ] . V_43 = 0 ;
V_6 [ 2 ] . V_44 = 0 ;
* V_98 = 1 ;
}
void
F_35 (
struct V_1 * V_2 ,
struct V_69 * V_9 ,
int * V_98 )
{
T_3 * V_7 ;
T_5 * V_10 ;
T_6 * V_12 ;
struct V_92 * V_6 ;
char * V_13 ;
char * V_20 ;
struct V_26 * V_27 = V_2 -> V_100 -> V_30 ;
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
V_6 = V_2 -> V_101 -> V_42 ( V_9 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) * V_97 ) ;
* V_98 = 1 ;
V_20 = ( char * ) V_2 -> V_101 -> V_32 ( V_9 ) ;
if ( V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) {
V_7 = F_4 ( V_27 , V_9 ) ;
V_13 = ( char * ) F_5 ( V_7 ) ;
} else
V_13 = ( char * ) V_9 + V_27 -> V_39 ;
while ( V_20 < V_13 ) {
V_12 = ( T_6 * ) V_20 ;
if ( F_9 ( V_12 -> V_45 ) == V_46 ) {
ASSERT ( ( char * ) V_12 - ( char * ) V_9 ==
F_9 ( * F_10 ( V_12 ) ) ) ;
F_32 ( V_9 , V_6 , V_12 , V_98 ) ;
V_20 += F_9 ( V_12 -> V_43 ) ;
}
else {
V_10 = ( T_5 * ) V_20 ;
ASSERT ( ( char * ) V_10 - ( char * ) V_9 ==
F_9 ( * V_2 -> V_101 -> V_49 ( V_10 ) ) ) ;
V_20 += V_2 -> V_101 -> V_59 ( V_10 -> V_47 ) ;
}
}
}
int
F_36 (
T_12 * args ,
T_13 V_67 ,
struct V_3 * * V_86 )
{
struct V_3 * V_4 ;
T_4 * V_9 ;
T_14 * V_2 ;
T_6 * V_12 ;
struct V_92 * V_6 ;
int error ;
int V_16 ;
T_9 * V_19 ;
T_15 * V_83 ;
int V_102 ;
V_2 = args -> V_2 ;
V_19 = V_2 -> V_100 ;
V_83 = args -> V_103 ;
error = F_37 ( V_83 , V_2 , F_38 ( args -> V_27 , V_67 ) ,
- 1 , & V_4 , V_88 ) ;
if ( error )
return error ;
V_4 -> V_70 = & V_89 ;
F_28 ( V_83 , V_4 , V_90 ) ;
V_9 = V_4 -> V_31 ;
if ( F_16 ( & V_19 -> V_64 ) ) {
struct V_62 * V_63 = V_4 -> V_31 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_33 = F_3 ( V_37 ) ;
V_63 -> V_67 = F_24 ( V_4 -> V_68 ) ;
V_63 -> V_104 = F_24 ( V_2 -> V_105 ) ;
F_39 ( & V_63 -> V_65 , & V_19 -> V_64 . V_66 ) ;
} else
V_9 -> V_33 = F_3 ( V_38 ) ;
V_6 = V_2 -> V_101 -> V_42 ( V_9 ) ;
V_6 [ 0 ] . V_44 = F_33 ( V_2 -> V_101 -> V_106 ) ;
for ( V_16 = 1 ; V_16 < V_97 ; V_16 ++ ) {
V_6 [ V_16 ] . V_43 = 0 ;
V_6 [ V_16 ] . V_44 = 0 ;
}
V_12 = V_2 -> V_101 -> V_107 ( V_9 ) ;
V_12 -> V_45 = F_33 ( V_46 ) ;
V_102 = args -> V_27 -> V_39 - ( V_108 ) V_2 -> V_101 -> V_106 ;
V_6 [ 0 ] . V_43 = F_33 ( V_102 ) ;
V_12 -> V_43 = F_33 ( V_102 ) ;
* F_10 ( V_12 ) = F_33 ( ( char * ) V_12 - ( char * ) V_9 ) ;
F_40 ( args , V_4 ) ;
F_41 ( args , V_4 , V_12 ) ;
* V_86 = V_4 ;
return 0 ;
}
void
F_42 (
struct V_109 * args ,
struct V_3 * V_4 ,
T_5 * V_10 )
{
struct V_69 * V_9 = V_4 -> V_31 ;
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
F_43 ( args -> V_103 , V_4 , ( V_108 ) ( ( char * ) V_10 - ( char * ) V_9 ) ,
( V_108 ) ( ( char * ) ( args -> V_2 -> V_101 -> V_49 ( V_10 ) + 1 ) -
( char * ) V_9 - 1 ) ) ;
}
void
F_40 (
struct V_109 * args ,
struct V_3 * V_4 )
{
#ifdef F_31
struct V_69 * V_9 = V_4 -> V_31 ;
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
#endif
F_43 ( args -> V_103 , V_4 , 0 ,
args -> V_2 -> V_101 -> V_106 - 1 ) ;
}
void
F_41 (
struct V_109 * args ,
struct V_3 * V_4 ,
T_6 * V_12 )
{
T_4 * V_9 = V_4 -> V_31 ;
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
F_43 ( args -> V_103 , V_4 , ( V_108 ) ( ( char * ) V_12 - ( char * ) V_9 ) ,
( V_108 ) ( ( char * ) & V_12 -> V_43 + sizeof( V_12 -> V_43 ) -
1 - ( char * ) V_9 ) ) ;
F_43 ( args -> V_103 , V_4 ,
( V_108 ) ( ( char * ) F_10 ( V_12 ) - ( char * ) V_9 ) ,
( V_108 ) ( ( char * ) F_10 ( V_12 ) - ( char * ) V_9 +
sizeof( V_110 ) - 1 ) ) ;
}
void
F_44 (
struct V_109 * args ,
struct V_3 * V_4 ,
V_53 V_44 ,
V_53 V_54 ,
int * V_111 ,
int * V_112 )
{
T_4 * V_9 ;
T_2 * V_11 ;
char * V_113 ;
int V_114 ;
T_6 * V_115 ;
T_6 * V_116 ;
T_6 * V_117 ;
struct V_92 * V_6 ;
V_9 = V_4 -> V_31 ;
if ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_37 ) )
V_113 = ( char * ) V_9 + args -> V_27 -> V_39 ;
else {
T_3 * V_7 ;
ASSERT ( V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
V_7 = F_4 ( args -> V_27 , V_9 ) ;
V_113 = ( char * ) F_5 ( V_7 ) ;
}
if ( V_44 > args -> V_2 -> V_101 -> V_106 ) {
T_16 * V_118 ;
V_118 = ( T_16 * ) ( ( char * ) V_9 + V_44 ) - 1 ;
V_117 = ( T_6 * ) ( ( char * ) V_9 + F_9 ( * V_118 ) ) ;
if ( F_9 ( V_117 -> V_45 ) != V_46 )
V_117 = NULL ;
} else
V_117 = NULL ;
if ( ( char * ) V_9 + V_44 + V_54 < V_113 ) {
V_116 =
( T_6 * ) ( ( char * ) V_9 + V_44 + V_54 ) ;
if ( F_9 ( V_116 -> V_45 ) != V_46 )
V_116 = NULL ;
} else
V_116 = NULL ;
ASSERT ( * V_112 == 0 ) ;
V_114 = 0 ;
V_6 = args -> V_2 -> V_101 -> V_42 ( V_9 ) ;
if ( V_117 && V_116 ) {
T_2 * V_119 ;
V_11 = F_11 ( V_9 , V_6 , V_117 ) ;
V_119 = F_11 ( V_9 , V_6 , V_116 ) ;
V_114 = ( V_6 [ 2 ] . V_43 != 0 ) ;
F_45 ( & V_117 -> V_43 , V_54 + F_9 ( V_116 -> V_43 ) ) ;
* F_10 ( V_117 ) =
F_33 ( ( char * ) V_117 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_117 ) ;
if ( ! V_114 ) {
ASSERT ( V_11 && V_119 ) ;
if ( V_11 == & V_6 [ 1 ] ) {
V_11 = & V_6 [ 0 ] ;
ASSERT ( V_119 == V_11 ) ;
V_119 = & V_6 [ 1 ] ;
}
F_34 ( V_9 , V_6 , V_119 , V_111 ) ;
F_34 ( V_9 , V_6 , V_11 , V_111 ) ;
V_11 = F_32 ( V_9 , V_6 , V_117 ,
V_111 ) ;
ASSERT ( V_11 == & V_6 [ 0 ] ) ;
ASSERT ( V_11 -> V_43 == V_117 -> V_43 ) ;
ASSERT ( ! V_11 [ 1 ] . V_43 ) ;
ASSERT ( ! V_11 [ 2 ] . V_43 ) ;
}
}
else if ( V_117 ) {
V_11 = F_11 ( V_9 , V_6 , V_117 ) ;
F_45 ( & V_117 -> V_43 , V_54 ) ;
* F_10 ( V_117 ) =
F_33 ( ( char * ) V_117 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_117 ) ;
if ( V_11 ) {
F_34 ( V_9 , V_6 , V_11 , V_111 ) ;
F_32 ( V_9 , V_6 , V_117 , V_111 ) ;
}
else {
V_114 = F_9 ( V_117 -> V_43 ) >
F_9 ( V_6 [ 2 ] . V_43 ) ;
}
}
else if ( V_116 ) {
V_11 = F_11 ( V_9 , V_6 , V_116 ) ;
V_115 = ( T_6 * ) ( ( char * ) V_9 + V_44 ) ;
V_115 -> V_45 = F_33 ( V_46 ) ;
V_115 -> V_43 = F_33 ( V_54 + F_9 ( V_116 -> V_43 ) ) ;
* F_10 ( V_115 ) =
F_33 ( ( char * ) V_115 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_115 ) ;
if ( V_11 ) {
F_34 ( V_9 , V_6 , V_11 , V_111 ) ;
F_32 ( V_9 , V_6 , V_115 , V_111 ) ;
}
else {
V_114 = F_9 ( V_115 -> V_43 ) >
F_9 ( V_6 [ 2 ] . V_43 ) ;
}
}
else {
V_115 = ( T_6 * ) ( ( char * ) V_9 + V_44 ) ;
V_115 -> V_45 = F_33 ( V_46 ) ;
V_115 -> V_43 = F_33 ( V_54 ) ;
* F_10 ( V_115 ) =
F_33 ( ( char * ) V_115 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_115 ) ;
F_32 ( V_9 , V_6 , V_115 , V_111 ) ;
}
* V_112 = V_114 ;
}
void
F_46 (
struct V_109 * args ,
struct V_3 * V_4 ,
T_6 * V_12 ,
V_53 V_44 ,
V_53 V_54 ,
int * V_111 ,
int * V_112 )
{
T_4 * V_9 ;
T_2 * V_11 ;
int V_120 ;
int V_121 ;
int V_114 ;
T_6 * V_115 ;
T_6 * V_122 ;
int V_123 ;
struct V_92 * V_6 ;
V_9 = V_4 -> V_31 ;
ASSERT ( V_9 -> V_33 == F_3 ( V_38 ) ||
V_9 -> V_33 == F_3 ( V_37 ) ||
V_9 -> V_33 == F_3 ( V_35 ) ||
V_9 -> V_33 == F_3 ( V_34 ) ) ;
ASSERT ( F_9 ( V_12 -> V_45 ) == V_46 ) ;
ASSERT ( V_44 >= ( char * ) V_12 - ( char * ) V_9 ) ;
ASSERT ( V_44 + V_54 <= ( char * ) V_12 + F_9 ( V_12 -> V_43 ) - ( char * ) V_9 ) ;
ASSERT ( ( char * ) V_12 - ( char * ) V_9 == F_9 ( * F_10 ( V_12 ) ) ) ;
V_123 = F_9 ( V_12 -> V_43 ) ;
V_6 = args -> V_2 -> V_101 -> V_42 ( V_9 ) ;
V_11 = F_11 ( V_9 , V_6 , V_12 ) ;
ASSERT ( V_11 || V_123 <= F_9 ( V_6 [ 2 ] . V_43 ) ) ;
V_121 = ( char * ) V_12 - ( char * ) V_9 == V_44 ;
V_120 = ( char * ) V_12 + V_123 - ( char * ) V_9 == V_44 + V_54 ;
ASSERT ( * V_112 == 0 ) ;
V_114 = 0 ;
if ( V_121 && V_120 ) {
if ( V_11 ) {
V_114 = ( V_6 [ 2 ] . V_44 != 0 ) ;
if ( ! V_114 )
F_34 ( V_9 , V_6 , V_11 ,
V_111 ) ;
}
}
else if ( V_121 ) {
V_115 = ( T_6 * ) ( ( char * ) V_9 + V_44 + V_54 ) ;
V_115 -> V_45 = F_33 ( V_46 ) ;
V_115 -> V_43 = F_33 ( V_123 - V_54 ) ;
* F_10 ( V_115 ) =
F_33 ( ( char * ) V_115 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_115 ) ;
if ( V_11 ) {
F_34 ( V_9 , V_6 , V_11 , V_111 ) ;
V_11 = F_32 ( V_9 , V_6 , V_115 ,
V_111 ) ;
ASSERT ( V_11 != NULL ) ;
ASSERT ( V_11 -> V_43 == V_115 -> V_43 ) ;
ASSERT ( F_9 ( V_11 -> V_44 ) == ( char * ) V_115 - ( char * ) V_9 ) ;
V_114 = V_11 == & V_6 [ 2 ] ;
}
}
else if ( V_120 ) {
V_115 = V_12 ;
V_115 -> V_43 = F_33 ( ( ( char * ) V_9 + V_44 ) - ( char * ) V_115 ) ;
* F_10 ( V_115 ) =
F_33 ( ( char * ) V_115 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_115 ) ;
if ( V_11 ) {
F_34 ( V_9 , V_6 , V_11 , V_111 ) ;
V_11 = F_32 ( V_9 , V_6 , V_115 ,
V_111 ) ;
ASSERT ( V_11 != NULL ) ;
ASSERT ( V_11 -> V_43 == V_115 -> V_43 ) ;
ASSERT ( F_9 ( V_11 -> V_44 ) == ( char * ) V_115 - ( char * ) V_9 ) ;
V_114 = V_11 == & V_6 [ 2 ] ;
}
}
else {
V_115 = V_12 ;
V_115 -> V_43 = F_33 ( ( ( char * ) V_9 + V_44 ) - ( char * ) V_115 ) ;
* F_10 ( V_115 ) =
F_33 ( ( char * ) V_115 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_115 ) ;
V_122 = ( T_6 * ) ( ( char * ) V_9 + V_44 + V_54 ) ;
V_122 -> V_45 = F_33 ( V_46 ) ;
V_122 -> V_43 = F_33 ( V_123 - V_54 - F_9 ( V_115 -> V_43 ) ) ;
* F_10 ( V_122 ) =
F_33 ( ( char * ) V_122 - ( char * ) V_9 ) ;
F_41 ( args , V_4 , V_122 ) ;
if ( V_11 ) {
V_114 = ( V_6 [ 2 ] . V_43 != 0 ) ;
if ( ! V_114 ) {
F_34 ( V_9 , V_6 , V_11 ,
V_111 ) ;
F_32 ( V_9 , V_6 , V_115 ,
V_111 ) ;
F_32 ( V_9 , V_6 , V_122 ,
V_111 ) ;
}
}
}
* V_112 = V_114 ;
}
