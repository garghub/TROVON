void
F_1 ( void )
{
V_1 = F_2 ( ( unsigned char * ) L_1 , 1 ) ;
V_2 = F_2 ( ( unsigned char * ) L_2 , 2 ) ;
}
int
F_3 (
T_1 * args )
{
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
struct V_6 * V_7 ;
T_5 * V_8 ;
int V_9 ;
T_6 * V_10 ;
T_7 * V_11 ;
T_8 * V_12 ;
int error ;
T_8 * V_13 = NULL ;
T_9 V_14 ;
int V_15 ;
int V_16 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 ;
int V_20 ;
int V_21 ;
int V_22 = 0 ;
T_10 * V_23 ;
int V_24 ;
int V_25 ;
T_11 * V_26 ;
T_12 * V_27 ;
F_4 ( args ) ;
V_11 = args -> V_11 ;
V_27 = args -> V_28 ;
V_23 = V_11 -> V_29 ;
if ( ( error =
F_5 ( V_27 , V_11 , V_23 -> V_30 , - 1 , & V_7 , V_31 ) ) ) {
return error ;
}
ASSERT ( V_7 != NULL ) ;
V_4 = V_7 -> V_32 ;
if ( F_6 ( V_4 -> V_33 != F_7 ( V_34 ) ) ) {
F_8 ( L_3 ,
V_35 , V_23 , V_4 ) ;
F_9 ( V_27 , V_7 ) ;
return F_10 ( V_36 ) ;
}
V_19 = F_11 ( args -> V_37 ) ;
V_3 = V_4 -> V_38 ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_5 = F_13 ( V_8 ) ;
if ( ! V_8 -> V_39 ) {
V_26 = ( T_11 * ) V_5 - 1 ;
V_13 = ( T_8 * ) ( ( char * ) V_4 + F_14 ( * V_26 ) ) ;
if ( F_14 ( V_13 -> V_40 ) != V_41 )
V_12 = V_13 = NULL ;
else {
V_12 = ( T_8 * )
( ( char * ) V_4 + F_14 ( V_3 [ 0 ] . V_42 ) ) ;
if ( V_12 == V_13 ) {
if ( F_14 ( V_12 -> V_43 ) < V_19 + ( V_44 ) sizeof( * V_5 ) ) {
if ( F_14 ( V_3 [ 1 ] . V_43 ) >= V_19 )
V_12 = ( T_8 * )
( ( char * ) V_4 +
F_14 ( V_3 [ 1 ] . V_42 ) ) ;
else
V_12 = NULL ;
}
} else {
if ( F_14 ( V_12 -> V_43 ) < V_19 ) {
V_12 = NULL ;
}
}
}
V_9 = 0 ;
}
else if ( F_14 ( V_3 [ 0 ] . V_43 ) >= V_19 ) {
V_12 = ( T_8 * )
( ( char * ) V_4 + F_14 ( V_3 [ 0 ] . V_42 ) ) ;
V_9 = 0 ;
}
else {
V_26 = ( T_11 * ) V_5 - 1 ;
V_12 = ( T_8 * ) ( ( char * ) V_4 + F_14 ( * V_26 ) ) ;
if ( F_14 ( V_12 -> V_40 ) == V_41 ) {
if ( F_14 ( V_12 -> V_43 ) + ( F_15 ( V_8 -> V_39 ) - 1 ) *
( V_44 ) sizeof( * V_5 ) < V_19 )
V_12 = NULL ;
} else if ( ( F_15 ( V_8 -> V_39 ) - 1 ) * ( V_44 ) sizeof( * V_5 ) < V_19 )
V_12 = NULL ;
else
V_12 = ( T_8 * ) V_5 ;
V_9 = 1 ;
}
if ( args -> V_45 & V_46 )
F_9 ( V_27 , V_7 ) ;
if ( ! V_12 ) {
if ( ( args -> V_45 & V_46 ) || args -> V_47 == 0 )
return F_10 ( V_48 ) ;
error = F_16 ( args , V_7 ) ;
if ( error )
return error ;
return F_17 ( args ) ;
}
if ( args -> V_45 & V_46 )
return 0 ;
V_24 = V_25 = 0 ;
if ( V_9 ) {
int V_49 ;
int V_50 ;
for ( V_49 = V_50 = F_15 ( V_8 -> V_51 ) - 1 ,
V_16 = V_17 = - 1 ;
V_49 >= 0 ;
V_49 -- ) {
if ( V_5 [ V_49 ] . V_52 ==
F_7 ( V_53 ) ) {
if ( V_16 == - 1 )
V_16 = V_50 ;
else {
if ( V_17 == - 1 )
V_17 = V_50 ;
continue;
}
}
if ( V_49 < V_50 )
V_5 [ V_50 ] = V_5 [ V_49 ] ;
V_50 -- ;
}
V_18 = V_50 + 1 - ( F_15 ( V_8 -> V_39 ) - 1 ) ;
V_17 -= F_15 ( V_8 -> V_39 ) - 1 ;
F_18 ( & V_8 -> V_51 , - ( F_15 ( V_8 -> V_39 ) - 1 ) ) ;
F_19 ( V_27 , V_7 ,
( V_54 ) ( ( char * ) V_5 - ( char * ) V_4 ) ,
( V_54 ) ( ( F_15 ( V_8 -> V_39 ) - 1 ) * sizeof( * V_5 ) ) ,
& V_24 , & V_25 ) ;
V_5 += F_15 ( V_8 -> V_39 ) - 1 ;
V_8 -> V_39 = F_7 ( 1 ) ;
if ( V_25 ) {
F_20 ( V_23 , V_4 , & V_24 ) ;
V_25 = 0 ;
}
}
else if ( V_8 -> V_39 ) {
V_18 = F_15 ( V_8 -> V_51 ) ;
V_17 = - 1 ;
}
for ( V_20 = 0 , V_15 = F_15 ( V_8 -> V_51 ) - 1 ; V_20 <= V_15 ; ) {
V_22 = ( V_20 + V_15 ) >> 1 ;
if ( ( V_14 = F_15 ( V_5 [ V_22 ] . V_55 ) ) == args -> V_55 )
break;
if ( V_14 < args -> V_55 )
V_20 = V_22 + 1 ;
else
V_15 = V_22 - 1 ;
}
while ( V_22 >= 0 && F_15 ( V_5 [ V_22 ] . V_55 ) >= args -> V_55 ) {
V_22 -- ;
}
if ( ! V_8 -> V_39 ) {
F_21 ( V_27 , V_7 , V_13 ,
( V_54 )
( ( char * ) V_13 - ( char * ) V_4 + F_14 ( V_13 -> V_43 ) -
sizeof( * V_5 ) ) ,
( V_54 ) sizeof( * V_5 ) ,
& V_24 , & V_25 ) ;
F_18 ( & V_8 -> V_51 , 1 ) ;
if ( V_25 ) {
F_20 ( V_23 , V_4 , & V_24 ) ;
V_25 = 0 ;
}
V_5 -- ;
V_22 ++ ;
if ( V_22 )
memmove ( V_5 , & V_5 [ 1 ] , V_22 * sizeof( * V_5 ) ) ;
V_18 = 0 ;
V_17 = V_22 ;
}
else {
for ( V_21 = V_22 ;
V_21 >= 0 &&
V_5 [ V_21 ] . V_52 !=
F_7 ( V_53 ) ;
V_21 -- )
continue;
for ( V_16 = V_22 + 1 ;
V_16 < F_15 ( V_8 -> V_51 ) &&
V_5 [ V_16 ] . V_52 !=
F_7 ( V_53 ) &&
( V_21 < 0 || V_22 - V_21 > V_16 - V_22 ) ;
V_16 ++ )
continue;
if ( V_21 >= 0 &&
( V_16 == F_15 ( V_8 -> V_51 ) ||
V_22 - V_21 <= V_16 - V_22 ) ) {
if ( V_22 - V_21 )
memmove ( & V_5 [ V_21 ] , & V_5 [ V_21 + 1 ] ,
( V_22 - V_21 ) * sizeof( * V_5 ) ) ;
V_18 = F_22 ( V_21 , V_18 ) ;
V_17 = F_23 ( V_22 , V_17 ) ;
}
else {
ASSERT ( V_16 < F_15 ( V_8 -> V_51 ) ) ;
V_22 ++ ;
if ( V_16 - V_22 )
memmove ( & V_5 [ V_22 + 1 ] , & V_5 [ V_22 ] ,
( V_16 - V_22 ) * sizeof( * V_5 ) ) ;
V_18 = F_22 ( V_22 , V_18 ) ;
V_17 = F_23 ( V_16 , V_17 ) ;
}
F_18 ( & V_8 -> V_39 , - 1 ) ;
}
V_10 = ( T_6 * ) V_12 ;
V_5 [ V_22 ] . V_55 = F_7 ( args -> V_55 ) ;
V_5 [ V_22 ] . V_52 = F_7 ( F_24 ( V_23 ,
( char * ) V_10 - ( char * ) V_4 ) ) ;
F_25 ( V_27 , V_7 , V_18 , V_17 ) ;
F_21 ( V_27 , V_7 , V_12 ,
( V_54 ) ( ( char * ) V_12 - ( char * ) V_4 ) ,
( V_54 ) V_19 , & V_24 , & V_25 ) ;
V_10 -> V_56 = F_26 ( args -> V_56 ) ;
V_10 -> V_37 = args -> V_37 ;
memcpy ( V_10 -> V_57 , args -> V_57 , args -> V_37 ) ;
V_26 = F_27 ( V_10 ) ;
* V_26 = F_28 ( ( char * ) V_10 - ( char * ) V_4 ) ;
if ( V_25 )
F_20 ( V_23 , V_4 , & V_24 ) ;
if ( V_24 )
F_29 ( V_27 , V_7 ) ;
F_30 ( V_27 , V_7 ) ;
F_31 ( V_27 , V_7 , V_10 ) ;
F_32 ( V_11 , V_7 ) ;
return 0 ;
}
int
F_33 (
T_7 * V_11 ,
void * V_58 ,
T_13 * V_42 ,
T_14 V_59 )
{
T_3 * V_4 ;
struct V_6 * V_7 ;
T_5 * V_8 ;
T_6 * V_10 ;
T_8 * V_12 ;
char * V_60 ;
int error ;
T_10 * V_23 ;
char * V_61 ;
int V_62 ;
T_13 V_63 ;
V_23 = V_11 -> V_29 ;
if ( F_34 ( V_23 , * V_42 ) > V_23 -> V_30 ) {
return 0 ;
}
error = F_5 ( NULL , V_11 , V_23 -> V_30 , - 1 ,
& V_7 , V_31 ) ;
if ( error )
return error ;
ASSERT ( V_7 != NULL ) ;
V_62 = F_35 ( V_23 , * V_42 ) ;
V_4 = V_7 -> V_32 ;
F_32 ( V_11 , V_7 ) ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_61 = ( char * ) ( V_4 + 1 ) ;
V_60 = ( char * ) F_13 ( V_8 ) ;
while ( V_61 < V_60 ) {
V_12 = ( T_8 * ) V_61 ;
if ( F_14 ( V_12 -> V_40 ) == V_41 ) {
V_61 += F_14 ( V_12 -> V_43 ) ;
continue;
}
V_10 = ( T_6 * ) V_61 ;
V_61 += F_11 ( V_10 -> V_37 ) ;
if ( ( char * ) V_10 - ( char * ) V_4 < V_62 )
continue;
V_63 = F_36 ( V_23 , V_23 -> V_30 ,
( char * ) V_10 - ( char * ) V_4 ) ;
if ( V_59 ( V_58 , ( char * ) V_10 -> V_57 , V_10 -> V_37 ,
V_63 & 0x7fffffff , F_37 ( V_10 -> V_56 ) ,
V_64 ) ) {
* V_42 = V_63 & 0x7fffffff ;
F_9 ( NULL , V_7 ) ;
return 0 ;
}
}
* V_42 = F_36 ( V_23 , V_23 -> V_30 + 1 , 0 ) &
0x7fffffff ;
F_9 ( NULL , V_7 ) ;
return 0 ;
}
static void
F_25 (
T_12 * V_27 ,
struct V_6 * V_7 ,
int V_65 ,
int V_66 )
{
T_3 * V_4 = V_7 -> V_32 ;
T_4 * V_5 ;
T_5 * V_8 ;
V_8 = F_12 ( V_27 -> V_67 , V_4 ) ;
V_5 = F_13 ( V_8 ) ;
F_38 ( V_27 , V_7 , ( V_44 ) ( ( char * ) & V_5 [ V_65 ] - ( char * ) V_4 ) ,
( V_44 ) ( ( char * ) & V_5 [ V_66 + 1 ] - ( char * ) V_4 - 1 ) ) ;
}
static void
F_30 (
T_12 * V_27 ,
struct V_6 * V_7 )
{
T_3 * V_4 = V_7 -> V_32 ;
T_5 * V_8 ;
V_8 = F_12 ( V_27 -> V_67 , V_4 ) ;
F_38 ( V_27 , V_7 , ( V_44 ) ( ( char * ) V_8 - ( char * ) V_4 ) ,
( V_44 ) ( ( char * ) ( V_8 + 1 ) - ( char * ) V_4 - 1 ) ) ;
}
int
F_39 (
T_1 * args )
{
T_3 * V_4 ;
T_4 * V_5 ;
struct V_6 * V_7 ;
T_5 * V_8 ;
T_6 * V_10 ;
T_7 * V_11 ;
int V_68 ;
int error ;
T_10 * V_23 ;
F_40 ( args ) ;
if ( ( error = F_41 ( args , & V_7 , & V_68 ) ) )
return error ;
V_11 = args -> V_11 ;
V_23 = V_11 -> V_29 ;
V_4 = V_7 -> V_32 ;
F_32 ( V_11 , V_7 ) ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_5 = F_13 ( V_8 ) ;
V_10 = ( T_6 * ) ( ( char * ) V_4 +
F_35 ( V_23 , F_15 ( V_5 [ V_68 ] . V_52 ) ) ) ;
args -> V_56 = F_37 ( V_10 -> V_56 ) ;
error = F_42 ( args , V_10 -> V_57 , V_10 -> V_37 ) ;
F_9 ( args -> V_28 , V_7 ) ;
return F_10 ( error ) ;
}
static int
F_41 (
T_1 * args ,
struct V_6 * * V_69 ,
int * V_70 )
{
T_15 V_71 ;
T_3 * V_4 ;
T_4 * V_5 ;
struct V_6 * V_7 ;
T_5 * V_8 ;
T_6 * V_10 ;
T_7 * V_11 ;
int error ;
T_9 V_14 ;
int V_15 ;
int V_20 ;
int V_22 ;
T_10 * V_23 ;
T_12 * V_27 ;
enum V_72 V_73 ;
V_11 = args -> V_11 ;
V_27 = args -> V_28 ;
V_23 = V_11 -> V_29 ;
if ( ( error =
F_5 ( V_27 , V_11 , V_23 -> V_30 , - 1 , & V_7 , V_31 ) ) ) {
return error ;
}
ASSERT ( V_7 != NULL ) ;
V_4 = V_7 -> V_32 ;
F_32 ( V_11 , V_7 ) ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_5 = F_13 ( V_8 ) ;
for ( V_20 = 0 , V_15 = F_15 ( V_8 -> V_51 ) - 1 ; ; ) {
ASSERT ( V_20 <= V_15 ) ;
V_22 = ( V_20 + V_15 ) >> 1 ;
if ( ( V_14 = F_15 ( V_5 [ V_22 ] . V_55 ) ) == args -> V_55 )
break;
if ( V_14 < args -> V_55 )
V_20 = V_22 + 1 ;
else
V_15 = V_22 - 1 ;
if ( V_20 > V_15 ) {
ASSERT ( args -> V_45 & V_74 ) ;
F_9 ( V_27 , V_7 ) ;
return F_10 ( V_75 ) ;
}
}
while ( V_22 > 0 && F_15 ( V_5 [ V_22 - 1 ] . V_55 ) == args -> V_55 ) {
V_22 -- ;
}
do {
if ( ( V_71 = F_15 ( V_5 [ V_22 ] . V_52 ) ) == V_53 )
continue;
V_10 = ( T_6 * )
( ( char * ) V_4 + F_35 ( V_23 , V_71 ) ) ;
V_73 = V_23 -> V_76 -> V_77 ( args , V_10 -> V_57 , V_10 -> V_37 ) ;
if ( V_73 != V_78 && V_73 != args -> V_79 ) {
args -> V_79 = V_73 ;
* V_69 = V_7 ;
* V_70 = V_22 ;
if ( V_73 == V_80 )
return 0 ;
}
} while ( ++ V_22 < F_15 ( V_8 -> V_51 ) &&
F_15 ( V_5 [ V_22 ] . V_55 ) == V_14 );
ASSERT ( args -> V_45 & V_74 ) ;
if ( args -> V_79 == V_81 )
return 0 ;
F_9 ( V_27 , V_7 ) ;
return F_10 ( V_75 ) ;
}
int
F_43 (
T_1 * args )
{
T_3 * V_4 ;
T_4 * V_5 ;
struct V_6 * V_7 ;
T_5 * V_8 ;
T_6 * V_10 ;
T_7 * V_11 ;
int V_68 ;
int error ;
T_10 * V_23 ;
int V_24 ;
int V_25 ;
T_16 V_82 ;
int V_83 ;
T_12 * V_27 ;
F_44 ( args ) ;
if ( ( error = F_41 ( args , & V_7 , & V_68 ) ) ) {
return error ;
}
V_11 = args -> V_11 ;
V_27 = args -> V_28 ;
V_23 = V_11 -> V_29 ;
V_4 = V_7 -> V_32 ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_5 = F_13 ( V_8 ) ;
V_10 = ( T_6 * )
( ( char * ) V_4 + F_35 ( V_23 , F_15 ( V_5 [ V_68 ] . V_52 ) ) ) ;
V_24 = V_25 = 0 ;
F_19 ( V_27 , V_7 ,
( V_54 ) ( ( char * ) V_10 - ( char * ) V_4 ) ,
F_11 ( V_10 -> V_37 ) , & V_24 , & V_25 ) ;
F_18 ( & V_8 -> V_39 , 1 ) ;
F_30 ( V_27 , V_7 ) ;
V_5 [ V_68 ] . V_52 = F_7 ( V_53 ) ;
F_25 ( V_27 , V_7 , V_68 , V_68 ) ;
if ( V_25 )
F_20 ( V_23 , V_4 , & V_24 ) ;
if ( V_24 )
F_29 ( V_27 , V_7 ) ;
F_32 ( V_11 , V_7 ) ;
V_83 = F_45 ( V_11 , V_4 , & V_82 ) ;
if ( V_83 > F_46 ( V_11 ) )
return 0 ;
return F_47 ( args , V_7 , V_83 , & V_82 ) ;
}
int
F_48 (
T_1 * args )
{
T_3 * V_4 ;
T_4 * V_5 ;
struct V_6 * V_7 ;
T_5 * V_8 ;
T_6 * V_10 ;
T_7 * V_11 ;
int V_68 ;
int error ;
T_10 * V_23 ;
F_49 ( args ) ;
if ( ( error = F_41 ( args , & V_7 , & V_68 ) ) ) {
return error ;
}
V_11 = args -> V_11 ;
V_23 = V_11 -> V_29 ;
V_4 = V_7 -> V_32 ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_5 = F_13 ( V_8 ) ;
V_10 = ( T_6 * )
( ( char * ) V_4 + F_35 ( V_23 , F_15 ( V_5 [ V_68 ] . V_52 ) ) ) ;
ASSERT ( F_37 ( V_10 -> V_56 ) != args -> V_56 ) ;
V_10 -> V_56 = F_26 ( args -> V_56 ) ;
F_31 ( args -> V_28 , V_7 , V_10 ) ;
F_32 ( V_11 , V_7 ) ;
return 0 ;
}
static int
F_50 (
const void * V_84 ,
const void * V_85 )
{
const T_4 * V_86 ;
const T_4 * V_87 ;
V_86 = V_84 ;
V_87 = V_85 ;
return F_15 ( V_86 -> V_55 ) < F_15 ( V_87 -> V_55 ) ? - 1 :
( F_15 ( V_86 -> V_55 ) > F_15 ( V_87 -> V_55 ) ? 1 : 0 ) ;
}
int
F_51 (
T_1 * args ,
struct V_6 * V_88 ,
struct V_6 * V_89 )
{
T_11 * V_90 ;
T_3 * V_4 ;
T_5 * V_8 ;
T_7 * V_11 ;
T_8 * V_12 ;
int error ;
int V_91 ;
T_17 * V_92 ;
T_4 * V_93 ;
T_18 * V_94 ;
T_10 * V_23 ;
int V_24 ;
int V_25 ;
T_16 V_82 ;
int V_83 ;
T_11 * V_26 ;
int V_95 ;
T_12 * V_27 ;
F_52 ( args ) ;
V_11 = args -> V_11 ;
V_27 = args -> V_28 ;
V_23 = V_11 -> V_29 ;
V_92 = V_88 -> V_32 ;
ASSERT ( V_92 -> V_4 . V_96 . V_33 == F_28 ( V_97 ) ) ;
V_94 = F_53 ( V_23 , V_92 ) ;
while ( V_11 -> V_98 . V_99 > V_23 -> V_100 ) {
V_90 = F_54 ( V_94 ) ;
if ( F_14 ( V_90 [ F_15 ( V_94 -> V_101 ) - 1 ] ) ==
V_23 -> V_100 - ( V_44 ) sizeof( * V_4 ) ) {
if ( ( error =
F_55 ( args , V_88 ,
( V_102 ) ( F_15 ( V_94 -> V_101 ) - 1 ) ) ) )
return error ;
} else
return 0 ;
}
if ( V_89 == NULL &&
( error = F_5 ( V_27 , V_11 , V_23 -> V_30 , - 1 , & V_89 ,
V_31 ) ) ) {
return error ;
}
V_4 = V_89 -> V_32 ;
ASSERT ( V_4 -> V_33 == F_7 ( V_103 ) ) ;
V_83 = ( V_44 ) sizeof( T_5 ) +
( V_44 ) sizeof( * V_93 ) * ( F_14 ( V_92 -> V_4 . V_51 ) - F_14 ( V_92 -> V_4 . V_39 ) ) ;
V_26 = ( T_11 * ) ( ( char * ) V_4 + V_23 -> V_100 ) - 1 ;
V_12 = ( T_8 * ) ( ( char * ) V_4 + F_14 ( * V_26 ) ) ;
if ( F_14 ( V_12 -> V_40 ) != V_41 ||
F_14 ( V_12 -> V_43 ) < V_83 )
return 0 ;
V_4 -> V_33 = F_7 ( V_34 ) ;
V_24 = 1 ;
V_25 = 0 ;
F_21 ( V_27 , V_89 , V_12 , V_23 -> V_100 - V_83 , V_83 ,
& V_24 , & V_25 ) ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_8 -> V_51 = F_7 ( F_14 ( V_92 -> V_4 . V_51 ) - F_14 ( V_92 -> V_4 . V_39 ) ) ;
V_8 -> V_39 = 0 ;
F_30 ( V_27 , V_89 ) ;
V_93 = F_13 ( V_8 ) ;
for ( V_91 = V_95 = 0 ; V_91 < F_14 ( V_92 -> V_4 . V_51 ) ; V_91 ++ ) {
if ( V_92 -> V_104 [ V_91 ] . V_52 ==
F_7 ( V_53 ) )
continue;
V_93 [ V_95 ++ ] = V_92 -> V_104 [ V_91 ] ;
}
ASSERT ( V_95 == F_15 ( V_8 -> V_51 ) ) ;
F_25 ( V_27 , V_89 , 0 , F_15 ( V_8 -> V_51 ) - 1 ) ;
if ( V_25 )
F_20 ( V_23 , V_4 , & V_24 ) ;
if ( V_24 )
F_29 ( V_27 , V_89 ) ;
error = F_56 ( args , V_23 -> V_105 , V_88 ) ;
if ( error )
return error ;
V_83 = F_45 ( V_11 , V_4 , & V_82 ) ;
if ( V_83 > F_46 ( V_11 ) )
return 0 ;
return F_47 ( args , V_89 , V_83 , & V_82 ) ;
}
int
F_57 (
T_1 * args )
{
V_102 V_106 ;
T_3 * V_4 ;
T_4 * V_5 ;
struct V_6 * V_7 ;
T_5 * V_8 ;
T_6 * V_10 ;
T_7 * V_11 ;
int V_107 ;
T_8 * V_12 ;
int V_108 ;
int error ;
int V_109 ;
T_10 * V_23 ;
int V_24 ;
int V_25 ;
int V_110 ;
int V_42 ;
T_19 * V_111 ;
T_16 * V_112 ;
T_16 * V_113 ;
T_11 * V_26 ;
T_12 * V_27 ;
struct V_114 V_57 ;
F_58 ( args ) ;
V_11 = args -> V_11 ;
V_27 = args -> V_28 ;
V_23 = V_11 -> V_29 ;
ASSERT ( V_11 -> V_115 . V_116 & V_117 ) ;
if ( V_11 -> V_98 . V_99 < F_59 ( T_16 , V_118 ) ) {
ASSERT ( F_60 ( V_23 ) ) ;
return F_10 ( V_119 ) ;
}
V_112 = ( T_16 * ) V_11 -> V_115 . V_120 . V_121 ;
ASSERT ( V_11 -> V_115 . V_122 == V_11 -> V_98 . V_99 ) ;
ASSERT ( V_11 -> V_115 . V_120 . V_121 != NULL ) ;
ASSERT ( V_11 -> V_98 . V_99 >= F_61 ( V_112 -> V_123 ) ) ;
V_113 = F_62 ( V_11 -> V_115 . V_122 , V_124 ) ;
memcpy ( V_113 , V_112 , V_11 -> V_115 . V_122 ) ;
F_63 ( V_11 , - V_11 -> V_115 . V_122 , V_31 ) ;
V_11 -> V_98 . V_99 = 0 ;
F_64 ( V_27 , V_11 , V_125 ) ;
error = F_65 ( args , V_126 , & V_106 ) ;
if ( error ) {
F_66 ( V_113 ) ;
return error ;
}
error = F_67 ( args , V_106 , & V_7 ) ;
if ( error ) {
F_66 ( V_113 ) ;
return error ;
}
V_4 = V_7 -> V_32 ;
V_4 -> V_33 = F_7 ( V_34 ) ;
V_109 = ( V_44 ) sizeof( * V_8 ) +
( V_113 -> V_51 + 2 ) * ( V_44 ) sizeof( T_4 ) ;
V_12 = ( T_8 * ) ( V_4 + 1 ) ;
V_24 = V_25 = 0 ;
F_21 ( V_27 , V_7 , V_12 , V_23 -> V_100 - V_109 , V_109 , & V_24 ,
& V_25 ) ;
ASSERT ( V_25 == 0 ) ;
V_8 = F_12 ( V_23 , V_4 ) ;
V_8 -> V_51 = F_7 ( V_113 -> V_51 + 2 ) ;
V_8 -> V_39 = 0 ;
V_5 = F_13 ( V_8 ) ;
V_108 = ( V_44 ) ( ( char * ) V_5 - ( char * ) V_4 ) ;
F_21 ( V_27 , V_7 , V_12 ,
( V_54 ) ( ( char * ) V_12 - ( char * ) V_4 ) ,
F_14 ( V_12 -> V_43 ) , & V_24 , & V_25 ) ;
V_10 = ( T_6 * )
( ( char * ) V_4 + V_127 ) ;
V_10 -> V_56 = F_26 ( V_11 -> V_128 ) ;
V_10 -> V_37 = 1 ;
V_10 -> V_57 [ 0 ] = '.' ;
V_26 = F_27 ( V_10 ) ;
* V_26 = F_28 ( ( char * ) V_10 - ( char * ) V_4 ) ;
F_31 ( V_27 , V_7 , V_10 ) ;
V_5 [ 0 ] . V_55 = F_7 ( V_1 ) ;
V_5 [ 0 ] . V_52 = F_7 ( F_24 ( V_23 ,
( char * ) V_10 - ( char * ) V_4 ) ) ;
V_10 = ( T_6 * )
( ( char * ) V_4 + V_129 ) ;
V_10 -> V_56 = F_26 ( F_68 ( V_113 ) ) ;
V_10 -> V_37 = 2 ;
V_10 -> V_57 [ 0 ] = V_10 -> V_57 [ 1 ] = '.' ;
V_26 = F_27 ( V_10 ) ;
* V_26 = F_28 ( ( char * ) V_10 - ( char * ) V_4 ) ;
F_31 ( V_27 , V_7 , V_10 ) ;
V_5 [ 1 ] . V_55 = F_7 ( V_2 ) ;
V_5 [ 1 ] . V_52 = F_7 ( F_24 ( V_23 ,
( char * ) V_10 - ( char * ) V_4 ) ) ;
V_42 = V_130 ;
V_109 = 0 ;
if ( ! V_113 -> V_51 )
V_111 = NULL ;
else
V_111 = F_69 ( V_113 ) ;
while ( V_42 < V_108 ) {
if ( V_111 == NULL )
V_110 = V_108 ;
else
V_110 = F_70 ( V_111 ) ;
if ( V_42 < V_110 ) {
V_12 = ( T_8 * ) ( ( char * ) V_4 + V_42 ) ;
V_12 -> V_40 = F_28 ( V_41 ) ;
V_12 -> V_43 = F_28 ( V_110 - V_42 ) ;
* F_71 ( V_12 ) = F_28 (
( ( char * ) V_12 - ( char * ) V_4 ) ) ;
F_72 ( V_27 , V_7 , V_12 ) ;
F_73 ( V_4 , V_12 , & V_107 ) ;
V_42 += F_14 ( V_12 -> V_43 ) ;
continue;
}
V_10 = ( T_6 * ) ( ( char * ) V_4 + V_110 ) ;
V_10 -> V_56 = F_26 ( F_74 ( V_113 , V_111 ) ) ;
V_10 -> V_37 = V_111 -> V_37 ;
memcpy ( V_10 -> V_57 , V_111 -> V_57 , V_10 -> V_37 ) ;
V_26 = F_27 ( V_10 ) ;
* V_26 = F_28 ( ( char * ) V_10 - ( char * ) V_4 ) ;
F_31 ( V_27 , V_7 , V_10 ) ;
V_57 . V_57 = V_111 -> V_57 ;
V_57 . V_19 = V_111 -> V_37 ;
V_5 [ 2 + V_109 ] . V_55 = F_7 ( V_23 -> V_76 ->
V_131 ( & V_57 ) ) ;
V_5 [ 2 + V_109 ] . V_52 = F_7 ( F_24 ( V_23 ,
( char * ) V_10 - ( char * ) V_4 ) ) ;
V_42 = ( int ) ( ( char * ) ( V_26 + 1 ) - ( char * ) V_4 ) ;
if ( ++ V_109 == V_113 -> V_51 )
V_111 = NULL ;
else
V_111 = F_75 ( V_113 , V_111 ) ;
}
F_66 ( V_113 ) ;
F_76 ( V_5 , F_15 ( V_8 -> V_51 ) , sizeof( * V_5 ) , F_50 ) ;
ASSERT ( V_25 == 0 ) ;
F_25 ( V_27 , V_7 , 0 , F_15 ( V_8 -> V_51 ) - 1 ) ;
F_30 ( V_27 , V_7 ) ;
F_32 ( V_11 , V_7 ) ;
return 0 ;
}
