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
V_19 = V_4 -> V_24 -> V_25 ;
V_9 = V_4 -> V_26 ;
V_6 = F_2 ( V_9 ) ;
V_20 = ( char * ) F_3 ( V_9 ) ;
switch ( V_9 -> V_27 ) {
case F_4 ( V_28 ) :
case F_4 ( V_29 ) :
V_7 = F_5 ( V_19 , V_9 ) ;
V_18 = F_6 ( V_7 ) ;
V_13 = ( char * ) V_18 ;
break;
case F_4 ( V_30 ) :
case F_4 ( V_31 ) :
V_13 = ( char * ) V_9 + V_19 -> V_32 ;
break;
default:
F_7 ( L_1 , V_33 , V_19 ) ;
return V_34 ;
}
V_8 = V_17 = V_14 = 0 ;
if ( ! V_6 [ 0 ] . V_35 ) {
F_8 ( ! V_6 [ 0 ] . V_36 ) ;
V_14 |= 1 << 0 ;
}
if ( ! V_6 [ 1 ] . V_35 ) {
F_8 ( ! V_6 [ 1 ] . V_36 ) ;
V_14 |= 1 << 1 ;
}
if ( ! V_6 [ 2 ] . V_35 ) {
F_8 ( ! V_6 [ 2 ] . V_36 ) ;
V_14 |= 1 << 2 ;
}
F_8 ( F_9 ( V_6 [ 0 ] . V_35 ) >=
F_9 ( V_6 [ 1 ] . V_35 ) ) ;
F_8 ( F_9 ( V_6 [ 1 ] . V_35 ) >=
F_9 ( V_6 [ 2 ] . V_35 ) ) ;
while ( V_20 < V_13 ) {
V_12 = ( T_6 * ) V_20 ;
if ( F_9 ( V_12 -> V_37 ) == V_38 ) {
F_8 ( V_17 == 0 ) ;
F_8 (
F_9 ( * F_10 ( V_12 ) ) ==
( char * ) V_12 - ( char * ) V_9 ) ;
V_11 = F_11 ( V_9 , V_12 ) ;
if ( V_11 ) {
V_16 = ( int ) ( V_11 - V_6 ) ;
F_8 (
( V_14 & ( 1 << V_16 ) ) == 0 ) ;
V_14 |= 1 << V_16 ;
} else {
F_8 (
F_9 ( V_12 -> V_35 ) <=
F_9 ( V_6 [ 2 ] . V_35 ) ) ;
}
V_20 += F_9 ( V_12 -> V_35 ) ;
V_17 = 1 ;
continue;
}
V_10 = ( T_5 * ) V_20 ;
F_8 ( V_10 -> V_39 != 0 ) ;
F_8 (
! F_12 ( V_19 , F_13 ( V_10 -> V_40 ) ) ) ;
F_8 (
F_9 ( * F_14 ( V_19 , V_10 ) ) ==
( char * ) V_10 - ( char * ) V_9 ) ;
F_8 (
F_15 ( V_19 , V_10 ) < V_41 ) ;
V_8 ++ ;
V_17 = 0 ;
if ( V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) {
V_5 = F_16 ( V_19 , V_19 -> V_42 ,
( V_43 )
( ( char * ) V_10 - ( char * ) V_9 ) ) ;
V_23 . V_23 = V_10 -> V_23 ;
V_23 . V_44 = V_10 -> V_39 ;
V_15 = V_19 -> V_45 -> V_46 ( & V_23 ) ;
for ( V_16 = 0 ; V_16 < F_17 ( V_7 -> V_8 ) ; V_16 ++ ) {
if ( F_17 ( V_18 [ V_16 ] . V_47 ) == V_5 &&
F_17 ( V_18 [ V_16 ] . V_48 ) == V_15 )
break;
}
F_8 ( V_16 < F_17 ( V_7 -> V_8 ) ) ;
}
V_20 += F_18 ( V_19 , V_10 -> V_39 ) ;
}
F_8 ( V_14 == 7 ) ;
if ( V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) {
for ( V_16 = V_21 = 0 ; V_16 < F_17 ( V_7 -> V_8 ) ; V_16 ++ ) {
if ( V_18 [ V_16 ] . V_47 ==
F_4 ( V_49 ) )
V_21 ++ ;
if ( V_16 > 0 )
F_8 (
F_17 ( V_18 [ V_16 ] . V_48 ) >=
F_17 ( V_18 [ V_16 - 1 ] . V_48 ) ) ;
}
F_8 ( V_8 ==
F_17 ( V_7 -> V_8 ) - F_17 ( V_7 -> V_21 ) ) ;
F_8 ( V_21 == F_17 ( V_7 -> V_21 ) ) ;
}
return 0 ;
}
static bool
F_19 (
struct V_3 * V_4 )
{
struct V_50 * V_19 = V_4 -> V_24 -> V_25 ;
struct V_51 * V_52 = V_4 -> V_26 ;
if ( F_20 ( & V_19 -> V_53 ) ) {
if ( V_52 -> V_27 != F_4 ( V_30 ) )
return false ;
if ( ! F_21 ( & V_52 -> V_54 , & V_19 -> V_53 . V_55 ) )
return false ;
if ( F_13 ( V_52 -> V_56 ) != V_4 -> V_57 )
return false ;
} else {
if ( V_52 -> V_27 != F_4 ( V_31 ) )
return false ;
}
if ( F_1 ( NULL , V_4 ) )
return false ;
return true ;
}
static void
F_22 (
struct V_3 * V_4 )
{
struct V_50 * V_19 = V_4 -> V_24 -> V_25 ;
struct V_58 * V_9 = V_4 -> V_26 ;
switch ( V_9 -> V_27 ) {
case F_4 ( V_29 ) :
case F_4 ( V_28 ) :
V_4 -> V_59 = & V_60 ;
V_4 -> V_59 -> V_61 ( V_4 ) ;
return;
case F_4 ( V_31 ) :
case F_4 ( V_30 ) :
F_19 ( V_4 ) ;
return;
default:
F_23 ( V_62 , V_33 , V_19 , V_9 ) ;
F_24 ( V_4 , V_34 ) ;
break;
}
}
static void
F_25 (
struct V_3 * V_4 )
{
struct V_50 * V_19 = V_4 -> V_24 -> V_25 ;
if ( ( F_20 ( & V_19 -> V_53 ) &&
! F_26 ( V_4 -> V_26 , F_27 ( V_4 -> V_63 ) ,
V_64 ) ) ||
! F_19 ( V_4 ) ) {
F_23 ( V_62 , V_33 , V_19 , V_4 -> V_26 ) ;
F_24 ( V_4 , V_34 ) ;
}
}
static void
F_28 (
struct V_3 * V_4 )
{
struct V_50 * V_19 = V_4 -> V_24 -> V_25 ;
struct V_65 * V_66 = V_4 -> V_67 ;
struct V_51 * V_52 = V_4 -> V_26 ;
if ( ! F_19 ( V_4 ) ) {
F_23 ( V_62 , V_33 , V_19 , V_4 -> V_26 ) ;
F_24 ( V_4 , V_34 ) ;
return;
}
if ( ! F_20 ( & V_19 -> V_53 ) )
return;
if ( V_66 )
V_52 -> V_68 = F_29 ( V_66 -> V_69 . V_70 ) ;
F_30 ( V_4 -> V_26 , F_27 ( V_4 -> V_63 ) , V_64 ) ;
}
int
F_31 (
struct V_71 * V_72 ,
struct V_1 * V_2 ,
T_10 V_73 ,
T_11 V_74 ,
struct V_3 * * V_75 )
{
int V_76 ;
V_76 = F_32 ( V_72 , V_2 , V_73 , V_74 , V_75 ,
V_77 , & V_78 ) ;
if ( ! V_76 && V_72 )
F_33 ( V_72 , * V_75 , V_79 ) ;
return V_76 ;
}
int
F_34 (
struct V_71 * V_72 ,
struct V_1 * V_2 ,
T_10 V_73 ,
T_11 V_74 )
{
return F_35 ( V_72 , V_2 , V_73 , V_74 ,
V_77 , & V_80 ) ;
}
T_2 *
F_11 (
T_4 * V_9 ,
T_6 * V_12 )
{
T_2 * V_11 ;
V_43 V_81 ;
struct V_82 * V_6 ;
#ifdef F_36
int V_83 ;
int V_84 ;
#endif
V_81 = ( V_43 ) ( ( char * ) V_12 - ( char * ) V_9 ) ;
V_6 = F_2 ( V_9 ) ;
#ifdef F_36
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
for ( V_11 = & V_6 [ 0 ] , V_84 = V_83 = 0 ;
V_11 < & V_6 [ V_85 ] ;
V_11 ++ ) {
if ( ! V_11 -> V_36 ) {
ASSERT ( ! V_11 -> V_35 ) ;
V_84 = 1 ;
continue;
}
ASSERT ( V_84 == 0 ) ;
if ( F_9 ( V_11 -> V_36 ) == V_81 ) {
V_83 = 1 ;
ASSERT ( V_11 -> V_35 == V_12 -> V_35 ) ;
} else if ( V_81 < F_9 ( V_11 -> V_36 ) )
ASSERT ( V_81 + F_9 ( V_12 -> V_35 ) <= F_9 ( V_11 -> V_36 ) ) ;
else
ASSERT ( F_9 ( V_11 -> V_36 ) + F_9 ( V_11 -> V_35 ) <= V_81 ) ;
ASSERT ( V_83 || F_9 ( V_11 -> V_35 ) >= F_9 ( V_12 -> V_35 ) ) ;
if ( V_11 > & V_6 [ 0 ] )
ASSERT ( F_9 ( V_11 [ - 1 ] . V_35 ) >= F_9 ( V_11 [ 0 ] . V_35 ) ) ;
}
#endif
if ( F_9 ( V_12 -> V_35 ) <
F_9 ( V_6 [ V_85 - 1 ] . V_35 ) )
return NULL ;
for ( V_11 = & V_6 [ 0 ] ; V_11 < & V_6 [ V_85 ] ; V_11 ++ ) {
if ( ! V_11 -> V_36 )
return NULL ;
if ( F_9 ( V_11 -> V_36 ) == V_81 )
return V_11 ;
}
return NULL ;
}
T_2 *
F_37 (
T_4 * V_9 ,
T_6 * V_12 ,
int * V_86 )
{
T_2 * V_11 ;
T_2 V_87 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
V_11 = F_2 ( V_9 ) ;
V_87 . V_35 = V_12 -> V_35 ;
V_87 . V_36 = F_38 ( ( char * ) V_12 - ( char * ) V_9 ) ;
if ( F_9 ( V_87 . V_35 ) > F_9 ( V_11 [ 0 ] . V_35 ) ) {
V_11 [ 2 ] = V_11 [ 1 ] ;
V_11 [ 1 ] = V_11 [ 0 ] ;
V_11 [ 0 ] = V_87 ;
* V_86 = 1 ;
return & V_11 [ 0 ] ;
}
if ( F_9 ( V_87 . V_35 ) > F_9 ( V_11 [ 1 ] . V_35 ) ) {
V_11 [ 2 ] = V_11 [ 1 ] ;
V_11 [ 1 ] = V_87 ;
* V_86 = 1 ;
return & V_11 [ 1 ] ;
}
if ( F_9 ( V_87 . V_35 ) > F_9 ( V_11 [ 2 ] . V_35 ) ) {
V_11 [ 2 ] = V_87 ;
* V_86 = 1 ;
return & V_11 [ 2 ] ;
}
return NULL ;
}
STATIC void
F_39 (
T_4 * V_9 ,
T_2 * V_11 ,
int * V_86 )
{
struct V_82 * V_6 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
V_6 = F_2 ( V_9 ) ;
if ( V_11 == & V_6 [ 0 ] ) {
V_6 [ 0 ] = V_6 [ 1 ] ;
V_6 [ 1 ] = V_6 [ 2 ] ;
}
else if ( V_11 == & V_6 [ 1 ] )
V_6 [ 1 ] = V_6 [ 2 ] ;
else
ASSERT ( V_11 == & V_6 [ 2 ] ) ;
V_6 [ 2 ] . V_35 = 0 ;
V_6 [ 2 ] . V_36 = 0 ;
* V_86 = 1 ;
}
void
F_40 (
T_9 * V_19 ,
T_4 * V_9 ,
int * V_86 )
{
T_3 * V_7 ;
T_5 * V_10 ;
T_6 * V_12 ;
struct V_82 * V_6 ;
char * V_13 ;
char * V_20 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
V_6 = F_2 ( V_9 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) * V_85 ) ;
* V_86 = 1 ;
V_20 = ( char * ) F_3 ( V_9 ) ;
if ( V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) {
V_7 = F_5 ( V_19 , V_9 ) ;
V_13 = ( char * ) F_6 ( V_7 ) ;
} else
V_13 = ( char * ) V_9 + V_19 -> V_32 ;
while ( V_20 < V_13 ) {
V_12 = ( T_6 * ) V_20 ;
if ( F_9 ( V_12 -> V_37 ) == V_38 ) {
ASSERT ( ( char * ) V_12 - ( char * ) V_9 ==
F_9 ( * F_10 ( V_12 ) ) ) ;
F_37 ( V_9 , V_12 , V_86 ) ;
V_20 += F_9 ( V_12 -> V_35 ) ;
}
else {
V_10 = ( T_5 * ) V_20 ;
ASSERT ( ( char * ) V_10 - ( char * ) V_9 ==
F_9 ( * F_14 ( V_19 , V_10 ) ) ) ;
V_20 += F_18 ( V_19 , V_10 -> V_39 ) ;
}
}
}
int
F_41 (
T_12 * args ,
T_13 V_56 ,
struct V_3 * * V_75 )
{
struct V_3 * V_4 ;
T_4 * V_9 ;
T_14 * V_2 ;
T_6 * V_12 ;
struct V_82 * V_6 ;
int error ;
int V_16 ;
T_9 * V_19 ;
T_15 * V_72 ;
int V_88 ;
V_2 = args -> V_2 ;
V_19 = V_2 -> V_89 ;
V_72 = args -> V_90 ;
error = F_42 ( V_72 , V_2 , F_43 ( V_19 , V_56 ) , - 1 , & V_4 ,
V_77 ) ;
if ( error )
return error ;
V_4 -> V_59 = & V_78 ;
F_33 ( V_72 , V_4 , V_79 ) ;
V_9 = V_4 -> V_26 ;
if ( F_20 ( & V_19 -> V_53 ) ) {
struct V_51 * V_52 = V_4 -> V_26 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> V_27 = F_4 ( V_30 ) ;
V_52 -> V_56 = F_29 ( V_4 -> V_57 ) ;
V_52 -> V_91 = F_29 ( V_2 -> V_92 ) ;
F_44 ( & V_52 -> V_54 , & V_19 -> V_53 . V_55 ) ;
} else
V_9 -> V_27 = F_4 ( V_31 ) ;
V_6 = F_2 ( V_9 ) ;
V_6 [ 0 ] . V_36 = F_38 ( F_45 ( V_9 ) ) ;
for ( V_16 = 1 ; V_16 < V_85 ; V_16 ++ ) {
V_6 [ V_16 ] . V_35 = 0 ;
V_6 [ V_16 ] . V_36 = 0 ;
}
V_12 = F_46 ( V_9 ) ;
V_12 -> V_37 = F_38 ( V_38 ) ;
V_88 = V_19 -> V_32 - ( V_93 ) F_45 ( V_9 ) ;
V_6 [ 0 ] . V_35 = F_38 ( V_88 ) ;
V_12 -> V_35 = F_38 ( V_88 ) ;
* F_10 ( V_12 ) = F_38 ( ( char * ) V_12 - ( char * ) V_9 ) ;
F_47 ( V_72 , V_4 ) ;
F_48 ( V_72 , V_4 , V_12 ) ;
* V_75 = V_4 ;
return 0 ;
}
void
F_49 (
struct V_71 * V_72 ,
struct V_3 * V_4 ,
T_5 * V_10 )
{
struct V_58 * V_9 = V_4 -> V_26 ;
struct V_50 * V_19 = V_72 -> V_94 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
F_50 ( V_72 , V_4 , ( V_93 ) ( ( char * ) V_10 - ( char * ) V_9 ) ,
( V_93 ) ( ( char * ) ( F_14 ( V_19 , V_10 ) + 1 ) -
( char * ) V_9 - 1 ) ) ;
}
void
F_47 (
struct V_71 * V_72 ,
struct V_3 * V_4 )
{
T_4 * V_9 = V_4 -> V_26 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
F_50 ( V_72 , V_4 , 0 , F_45 ( V_9 ) - 1 ) ;
}
void
F_48 (
struct V_71 * V_72 ,
struct V_3 * V_4 ,
T_6 * V_12 )
{
T_4 * V_9 = V_4 -> V_26 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
F_50 ( V_72 , V_4 , ( V_93 ) ( ( char * ) V_12 - ( char * ) V_9 ) ,
( V_93 ) ( ( char * ) & V_12 -> V_35 + sizeof( V_12 -> V_35 ) -
1 - ( char * ) V_9 ) ) ;
F_50 ( V_72 , V_4 ,
( V_93 ) ( ( char * ) F_10 ( V_12 ) - ( char * ) V_9 ) ,
( V_93 ) ( ( char * ) F_10 ( V_12 ) - ( char * ) V_9 +
sizeof( V_95 ) - 1 ) ) ;
}
void
F_51 (
struct V_71 * V_72 ,
struct V_3 * V_4 ,
V_43 V_36 ,
V_43 V_44 ,
int * V_96 ,
int * V_97 )
{
T_4 * V_9 ;
T_2 * V_11 ;
char * V_98 ;
T_9 * V_19 ;
int V_99 ;
T_6 * V_100 ;
T_6 * V_101 ;
T_6 * V_102 ;
struct V_82 * V_6 ;
V_19 = V_72 -> V_94 ;
V_9 = V_4 -> V_26 ;
if ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_30 ) )
V_98 = ( char * ) V_9 + V_19 -> V_32 ;
else {
T_3 * V_7 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
V_7 = F_5 ( V_19 , V_9 ) ;
V_98 = ( char * ) F_6 ( V_7 ) ;
}
if ( V_36 > F_45 ( V_9 ) ) {
T_16 * V_103 ;
V_103 = ( T_16 * ) ( ( char * ) V_9 + V_36 ) - 1 ;
V_102 = ( T_6 * ) ( ( char * ) V_9 + F_9 ( * V_103 ) ) ;
if ( F_9 ( V_102 -> V_37 ) != V_38 )
V_102 = NULL ;
} else
V_102 = NULL ;
if ( ( char * ) V_9 + V_36 + V_44 < V_98 ) {
V_101 =
( T_6 * ) ( ( char * ) V_9 + V_36 + V_44 ) ;
if ( F_9 ( V_101 -> V_37 ) != V_38 )
V_101 = NULL ;
} else
V_101 = NULL ;
ASSERT ( * V_97 == 0 ) ;
V_99 = 0 ;
V_6 = F_2 ( V_9 ) ;
if ( V_102 && V_101 ) {
T_2 * V_104 ;
V_11 = F_11 ( V_9 , V_102 ) ;
V_104 = F_11 ( V_9 , V_101 ) ;
V_99 = ( V_6 [ 2 ] . V_35 != 0 ) ;
F_52 ( & V_102 -> V_35 , V_44 + F_9 ( V_101 -> V_35 ) ) ;
* F_10 ( V_102 ) =
F_38 ( ( char * ) V_102 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_102 ) ;
if ( ! V_99 ) {
ASSERT ( V_11 && V_104 ) ;
if ( V_11 == & V_6 [ 1 ] ) {
V_11 = & V_6 [ 0 ] ;
ASSERT ( V_104 == V_11 ) ;
V_104 = & V_6 [ 1 ] ;
}
F_39 ( V_9 , V_104 , V_96 ) ;
F_39 ( V_9 , V_11 , V_96 ) ;
V_11 = F_37 ( V_9 , V_102 , V_96 ) ;
ASSERT ( V_11 == & V_6 [ 0 ] ) ;
ASSERT ( V_11 -> V_35 == V_102 -> V_35 ) ;
ASSERT ( ! V_11 [ 1 ] . V_35 ) ;
ASSERT ( ! V_11 [ 2 ] . V_35 ) ;
}
}
else if ( V_102 ) {
V_11 = F_11 ( V_9 , V_102 ) ;
F_52 ( & V_102 -> V_35 , V_44 ) ;
* F_10 ( V_102 ) =
F_38 ( ( char * ) V_102 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_102 ) ;
if ( V_11 ) {
F_39 ( V_9 , V_11 , V_96 ) ;
F_37 ( V_9 , V_102 , V_96 ) ;
}
else {
V_99 = F_9 ( V_102 -> V_35 ) >
F_9 ( V_6 [ 2 ] . V_35 ) ;
}
}
else if ( V_101 ) {
V_11 = F_11 ( V_9 , V_101 ) ;
V_100 = ( T_6 * ) ( ( char * ) V_9 + V_36 ) ;
V_100 -> V_37 = F_38 ( V_38 ) ;
V_100 -> V_35 = F_38 ( V_44 + F_9 ( V_101 -> V_35 ) ) ;
* F_10 ( V_100 ) =
F_38 ( ( char * ) V_100 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_100 ) ;
if ( V_11 ) {
F_39 ( V_9 , V_11 , V_96 ) ;
F_37 ( V_9 , V_100 , V_96 ) ;
}
else {
V_99 = F_9 ( V_100 -> V_35 ) >
F_9 ( V_6 [ 2 ] . V_35 ) ;
}
}
else {
V_100 = ( T_6 * ) ( ( char * ) V_9 + V_36 ) ;
V_100 -> V_37 = F_38 ( V_38 ) ;
V_100 -> V_35 = F_38 ( V_44 ) ;
* F_10 ( V_100 ) =
F_38 ( ( char * ) V_100 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_100 ) ;
F_37 ( V_9 , V_100 , V_96 ) ;
}
* V_97 = V_99 ;
}
void
F_53 (
struct V_71 * V_72 ,
struct V_3 * V_4 ,
T_6 * V_12 ,
V_43 V_36 ,
V_43 V_44 ,
int * V_96 ,
int * V_97 )
{
T_4 * V_9 ;
T_2 * V_11 ;
int V_105 ;
int V_106 ;
int V_99 ;
T_6 * V_100 ;
T_6 * V_107 ;
int V_108 ;
struct V_82 * V_6 ;
V_9 = V_4 -> V_26 ;
ASSERT ( V_9 -> V_27 == F_4 ( V_31 ) ||
V_9 -> V_27 == F_4 ( V_30 ) ||
V_9 -> V_27 == F_4 ( V_29 ) ||
V_9 -> V_27 == F_4 ( V_28 ) ) ;
ASSERT ( F_9 ( V_12 -> V_37 ) == V_38 ) ;
ASSERT ( V_36 >= ( char * ) V_12 - ( char * ) V_9 ) ;
ASSERT ( V_36 + V_44 <= ( char * ) V_12 + F_9 ( V_12 -> V_35 ) - ( char * ) V_9 ) ;
ASSERT ( ( char * ) V_12 - ( char * ) V_9 == F_9 ( * F_10 ( V_12 ) ) ) ;
V_11 = F_11 ( V_9 , V_12 ) ;
V_108 = F_9 ( V_12 -> V_35 ) ;
V_6 = F_2 ( V_9 ) ;
ASSERT ( V_11 || V_108 <= F_9 ( V_6 [ 2 ] . V_35 ) ) ;
V_106 = ( char * ) V_12 - ( char * ) V_9 == V_36 ;
V_105 = ( char * ) V_12 + V_108 - ( char * ) V_9 == V_36 + V_44 ;
ASSERT ( * V_97 == 0 ) ;
V_99 = 0 ;
if ( V_106 && V_105 ) {
if ( V_11 ) {
V_99 = ( V_6 [ 2 ] . V_36 != 0 ) ;
if ( ! V_99 )
F_39 ( V_9 , V_11 , V_96 ) ;
}
}
else if ( V_106 ) {
V_100 = ( T_6 * ) ( ( char * ) V_9 + V_36 + V_44 ) ;
V_100 -> V_37 = F_38 ( V_38 ) ;
V_100 -> V_35 = F_38 ( V_108 - V_44 ) ;
* F_10 ( V_100 ) =
F_38 ( ( char * ) V_100 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_100 ) ;
if ( V_11 ) {
F_39 ( V_9 , V_11 , V_96 ) ;
V_11 = F_37 ( V_9 , V_100 , V_96 ) ;
ASSERT ( V_11 != NULL ) ;
ASSERT ( V_11 -> V_35 == V_100 -> V_35 ) ;
ASSERT ( F_9 ( V_11 -> V_36 ) == ( char * ) V_100 - ( char * ) V_9 ) ;
V_99 = V_11 == & V_6 [ 2 ] ;
}
}
else if ( V_105 ) {
V_100 = V_12 ;
V_100 -> V_35 = F_38 ( ( ( char * ) V_9 + V_36 ) - ( char * ) V_100 ) ;
* F_10 ( V_100 ) =
F_38 ( ( char * ) V_100 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_100 ) ;
if ( V_11 ) {
F_39 ( V_9 , V_11 , V_96 ) ;
V_11 = F_37 ( V_9 , V_100 , V_96 ) ;
ASSERT ( V_11 != NULL ) ;
ASSERT ( V_11 -> V_35 == V_100 -> V_35 ) ;
ASSERT ( F_9 ( V_11 -> V_36 ) == ( char * ) V_100 - ( char * ) V_9 ) ;
V_99 = V_11 == & V_6 [ 2 ] ;
}
}
else {
V_100 = V_12 ;
V_100 -> V_35 = F_38 ( ( ( char * ) V_9 + V_36 ) - ( char * ) V_100 ) ;
* F_10 ( V_100 ) =
F_38 ( ( char * ) V_100 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_100 ) ;
V_107 = ( T_6 * ) ( ( char * ) V_9 + V_36 + V_44 ) ;
V_107 -> V_37 = F_38 ( V_38 ) ;
V_107 -> V_35 = F_38 ( V_108 - V_44 - F_9 ( V_100 -> V_35 ) ) ;
* F_10 ( V_107 ) =
F_38 ( ( char * ) V_107 - ( char * ) V_9 ) ;
F_48 ( V_72 , V_4 , V_107 ) ;
if ( V_11 ) {
V_99 = ( V_6 [ 2 ] . V_35 != 0 ) ;
if ( ! V_99 ) {
F_39 ( V_9 , V_11 , V_96 ) ;
F_37 ( V_9 , V_100 , V_96 ) ;
F_37 ( V_9 , V_107 ,
V_96 ) ;
}
}
}
* V_97 = V_99 ;
}
