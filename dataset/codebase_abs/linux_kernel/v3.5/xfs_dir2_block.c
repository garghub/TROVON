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
T_5 * V_6 ;
T_6 * V_7 ;
int V_8 ;
T_7 * V_9 ;
T_8 * V_10 ;
T_9 * V_11 ;
int error ;
T_9 * V_12 = NULL ;
T_10 V_13 ;
int V_14 ;
int V_15 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 ;
int V_19 ;
int V_20 ;
int V_21 = 0 ;
T_11 * V_22 ;
int V_23 ;
int V_24 ;
T_12 * V_25 ;
T_13 * V_26 ;
F_4 ( args ) ;
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
if ( ( error =
F_5 ( V_26 , V_10 , V_22 -> V_29 , - 1 , & V_6 , V_30 ) ) ) {
return error ;
}
ASSERT ( V_6 != NULL ) ;
V_4 = V_6 -> V_31 ;
if ( F_6 ( V_4 -> V_32 != F_7 ( V_33 ) ) ) {
F_8 ( L_3 ,
V_34 , V_22 , V_4 ) ;
F_9 ( V_26 , V_6 ) ;
return F_10 ( V_35 ) ;
}
V_18 = F_11 ( args -> V_36 ) ;
V_3 = V_4 -> V_37 ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
if ( ! V_7 -> V_38 ) {
V_25 = ( T_12 * ) V_5 - 1 ;
V_12 = ( T_9 * ) ( ( char * ) V_4 + F_14 ( * V_25 ) ) ;
if ( F_14 ( V_12 -> V_39 ) != V_40 )
V_11 = V_12 = NULL ;
else {
V_11 = ( T_9 * )
( ( char * ) V_4 + F_14 ( V_3 [ 0 ] . V_41 ) ) ;
if ( V_11 == V_12 ) {
if ( F_14 ( V_11 -> V_42 ) < V_18 + ( V_43 ) sizeof( * V_5 ) ) {
if ( F_14 ( V_3 [ 1 ] . V_42 ) >= V_18 )
V_11 = ( T_9 * )
( ( char * ) V_4 +
F_14 ( V_3 [ 1 ] . V_41 ) ) ;
else
V_11 = NULL ;
}
} else {
if ( F_14 ( V_11 -> V_42 ) < V_18 ) {
V_11 = NULL ;
}
}
}
V_8 = 0 ;
}
else if ( F_14 ( V_3 [ 0 ] . V_42 ) >= V_18 ) {
V_11 = ( T_9 * )
( ( char * ) V_4 + F_14 ( V_3 [ 0 ] . V_41 ) ) ;
V_8 = 0 ;
}
else {
V_25 = ( T_12 * ) V_5 - 1 ;
V_11 = ( T_9 * ) ( ( char * ) V_4 + F_14 ( * V_25 ) ) ;
if ( F_14 ( V_11 -> V_39 ) == V_40 ) {
if ( F_14 ( V_11 -> V_42 ) + ( F_15 ( V_7 -> V_38 ) - 1 ) *
( V_43 ) sizeof( * V_5 ) < V_18 )
V_11 = NULL ;
} else if ( ( F_15 ( V_7 -> V_38 ) - 1 ) * ( V_43 ) sizeof( * V_5 ) < V_18 )
V_11 = NULL ;
else
V_11 = ( T_9 * ) V_5 ;
V_8 = 1 ;
}
if ( args -> V_44 & V_45 )
F_9 ( V_26 , V_6 ) ;
if ( ! V_11 ) {
if ( ( args -> V_44 & V_45 ) || args -> V_46 == 0 )
return F_10 ( V_47 ) ;
error = F_16 ( args , V_6 ) ;
F_17 ( V_6 ) ;
if ( error )
return error ;
return F_18 ( args ) ;
}
if ( args -> V_44 & V_45 )
return 0 ;
V_23 = V_24 = 0 ;
if ( V_8 ) {
int V_48 ;
int V_49 ;
for ( V_48 = V_49 = F_15 ( V_7 -> V_50 ) - 1 ,
V_15 = V_16 = - 1 ;
V_48 >= 0 ;
V_48 -- ) {
if ( V_5 [ V_48 ] . V_51 ==
F_7 ( V_52 ) ) {
if ( V_15 == - 1 )
V_15 = V_49 ;
else {
if ( V_16 == - 1 )
V_16 = V_49 ;
continue;
}
}
if ( V_48 < V_49 )
V_5 [ V_49 ] = V_5 [ V_48 ] ;
V_49 -- ;
}
V_17 = V_49 + 1 - ( F_15 ( V_7 -> V_38 ) - 1 ) ;
V_16 -= F_15 ( V_7 -> V_38 ) - 1 ;
F_19 ( & V_7 -> V_50 , - ( F_15 ( V_7 -> V_38 ) - 1 ) ) ;
F_20 ( V_26 , V_6 ,
( V_53 ) ( ( char * ) V_5 - ( char * ) V_4 ) ,
( V_53 ) ( ( F_15 ( V_7 -> V_38 ) - 1 ) * sizeof( * V_5 ) ) ,
& V_23 , & V_24 ) ;
V_5 += F_15 ( V_7 -> V_38 ) - 1 ;
V_7 -> V_38 = F_7 ( 1 ) ;
if ( V_24 ) {
F_21 ( V_22 , V_4 , & V_23 ) ;
V_24 = 0 ;
}
}
else if ( V_7 -> V_38 ) {
V_17 = F_15 ( V_7 -> V_50 ) ;
V_16 = - 1 ;
}
for ( V_19 = 0 , V_14 = F_15 ( V_7 -> V_50 ) - 1 ; V_19 <= V_14 ; ) {
V_21 = ( V_19 + V_14 ) >> 1 ;
if ( ( V_13 = F_15 ( V_5 [ V_21 ] . V_54 ) ) == args -> V_54 )
break;
if ( V_13 < args -> V_54 )
V_19 = V_21 + 1 ;
else
V_14 = V_21 - 1 ;
}
while ( V_21 >= 0 && F_15 ( V_5 [ V_21 ] . V_54 ) >= args -> V_54 ) {
V_21 -- ;
}
if ( ! V_7 -> V_38 ) {
F_22 ( V_26 , V_6 , V_12 ,
( V_53 )
( ( char * ) V_12 - ( char * ) V_4 + F_14 ( V_12 -> V_42 ) -
sizeof( * V_5 ) ) ,
( V_53 ) sizeof( * V_5 ) ,
& V_23 , & V_24 ) ;
F_19 ( & V_7 -> V_50 , 1 ) ;
if ( V_24 ) {
F_21 ( V_22 , V_4 , & V_23 ) ;
V_24 = 0 ;
}
V_5 -- ;
V_21 ++ ;
if ( V_21 )
memmove ( V_5 , & V_5 [ 1 ] , V_21 * sizeof( * V_5 ) ) ;
V_17 = 0 ;
V_16 = V_21 ;
}
else {
for ( V_20 = V_21 ;
V_20 >= 0 &&
V_5 [ V_20 ] . V_51 !=
F_7 ( V_52 ) ;
V_20 -- )
continue;
for ( V_15 = V_21 + 1 ;
V_15 < F_15 ( V_7 -> V_50 ) &&
V_5 [ V_15 ] . V_51 !=
F_7 ( V_52 ) &&
( V_20 < 0 || V_21 - V_20 > V_15 - V_21 ) ;
V_15 ++ )
continue;
if ( V_20 >= 0 &&
( V_15 == F_15 ( V_7 -> V_50 ) ||
V_21 - V_20 <= V_15 - V_21 ) ) {
if ( V_21 - V_20 )
memmove ( & V_5 [ V_20 ] , & V_5 [ V_20 + 1 ] ,
( V_21 - V_20 ) * sizeof( * V_5 ) ) ;
V_17 = F_23 ( V_20 , V_17 ) ;
V_16 = F_24 ( V_21 , V_16 ) ;
}
else {
ASSERT ( V_15 < F_15 ( V_7 -> V_50 ) ) ;
V_21 ++ ;
if ( V_15 - V_21 )
memmove ( & V_5 [ V_21 + 1 ] , & V_5 [ V_21 ] ,
( V_15 - V_21 ) * sizeof( * V_5 ) ) ;
V_17 = F_23 ( V_21 , V_17 ) ;
V_16 = F_24 ( V_15 , V_16 ) ;
}
F_19 ( & V_7 -> V_38 , - 1 ) ;
}
V_9 = ( T_7 * ) V_11 ;
V_5 [ V_21 ] . V_54 = F_7 ( args -> V_54 ) ;
V_5 [ V_21 ] . V_51 = F_7 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
F_26 ( V_26 , V_6 , V_17 , V_16 ) ;
F_22 ( V_26 , V_6 , V_11 ,
( V_53 ) ( ( char * ) V_11 - ( char * ) V_4 ) ,
( V_53 ) V_18 , & V_23 , & V_24 ) ;
V_9 -> V_55 = F_27 ( args -> V_55 ) ;
V_9 -> V_36 = args -> V_36 ;
memcpy ( V_9 -> V_56 , args -> V_56 , args -> V_36 ) ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
if ( V_24 )
F_21 ( V_22 , V_4 , & V_23 ) ;
if ( V_23 )
F_30 ( V_26 , V_6 ) ;
F_31 ( V_26 , V_6 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
F_33 ( V_10 , V_6 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
int
F_34 (
T_8 * V_10 ,
void * V_57 ,
T_14 * V_41 ,
T_15 V_58 )
{
T_3 * V_4 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_9 ;
T_9 * V_11 ;
char * V_59 ;
int error ;
T_11 * V_22 ;
char * V_60 ;
int V_61 ;
T_14 V_62 ;
V_22 = V_10 -> V_28 ;
if ( F_35 ( V_22 , * V_41 ) > V_22 -> V_29 ) {
return 0 ;
}
error = F_5 ( NULL , V_10 , V_22 -> V_29 , - 1 ,
& V_6 , V_30 ) ;
if ( error )
return error ;
ASSERT ( V_6 != NULL ) ;
V_61 = F_36 ( V_22 , * V_41 ) ;
V_4 = V_6 -> V_31 ;
F_33 ( V_10 , V_6 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_60 = ( char * ) ( V_4 + 1 ) ;
V_59 = ( char * ) F_13 ( V_7 ) ;
while ( V_60 < V_59 ) {
V_11 = ( T_9 * ) V_60 ;
if ( F_14 ( V_11 -> V_39 ) == V_40 ) {
V_60 += F_14 ( V_11 -> V_42 ) ;
continue;
}
V_9 = ( T_7 * ) V_60 ;
V_60 += F_11 ( V_9 -> V_36 ) ;
if ( ( char * ) V_9 - ( char * ) V_4 < V_61 )
continue;
V_62 = F_37 ( V_22 , V_22 -> V_29 ,
( char * ) V_9 - ( char * ) V_4 ) ;
if ( V_58 ( V_57 , ( char * ) V_9 -> V_56 , V_9 -> V_36 ,
V_62 & 0x7fffffff , F_38 ( V_9 -> V_55 ) ,
V_63 ) ) {
* V_41 = V_62 & 0x7fffffff ;
F_9 ( NULL , V_6 ) ;
return 0 ;
}
}
* V_41 = F_37 ( V_22 , V_22 -> V_29 + 1 , 0 ) &
0x7fffffff ;
F_9 ( NULL , V_6 ) ;
return 0 ;
}
static void
F_26 (
T_13 * V_26 ,
T_5 * V_6 ,
int V_64 ,
int V_65 )
{
T_3 * V_4 = V_6 -> V_31 ;
T_4 * V_5 ;
T_6 * V_7 ;
V_7 = F_12 ( V_26 -> V_66 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
F_39 ( V_26 , V_6 , ( V_43 ) ( ( char * ) & V_5 [ V_64 ] - ( char * ) V_4 ) ,
( V_43 ) ( ( char * ) & V_5 [ V_65 + 1 ] - ( char * ) V_4 - 1 ) ) ;
}
static void
F_31 (
T_13 * V_26 ,
T_5 * V_6 )
{
T_3 * V_4 = V_6 -> V_31 ;
T_6 * V_7 ;
V_7 = F_12 ( V_26 -> V_66 , V_4 ) ;
F_39 ( V_26 , V_6 , ( V_43 ) ( ( char * ) V_7 - ( char * ) V_4 ) ,
( V_43 ) ( ( char * ) ( V_7 + 1 ) - ( char * ) V_4 - 1 ) ) ;
}
int
F_40 (
T_1 * args )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_9 ;
T_8 * V_10 ;
int V_67 ;
int error ;
T_11 * V_22 ;
F_41 ( args ) ;
if ( ( error = F_42 ( args , & V_6 , & V_67 ) ) )
return error ;
V_10 = args -> V_10 ;
V_22 = V_10 -> V_28 ;
V_4 = V_6 -> V_31 ;
F_33 ( V_10 , V_6 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
V_9 = ( T_7 * ) ( ( char * ) V_4 +
F_36 ( V_22 , F_15 ( V_5 [ V_67 ] . V_51 ) ) ) ;
args -> V_55 = F_38 ( V_9 -> V_55 ) ;
error = F_43 ( args , V_9 -> V_56 , V_9 -> V_36 ) ;
F_9 ( args -> V_27 , V_6 ) ;
return F_10 ( error ) ;
}
static int
F_42 (
T_1 * args ,
T_5 * * V_68 ,
int * V_69 )
{
T_16 V_70 ;
T_3 * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_9 ;
T_8 * V_10 ;
int error ;
T_10 V_13 ;
int V_14 ;
int V_19 ;
int V_21 ;
T_11 * V_22 ;
T_13 * V_26 ;
enum V_71 V_72 ;
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
if ( ( error =
F_5 ( V_26 , V_10 , V_22 -> V_29 , - 1 , & V_6 , V_30 ) ) ) {
return error ;
}
ASSERT ( V_6 != NULL ) ;
V_4 = V_6 -> V_31 ;
F_33 ( V_10 , V_6 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
for ( V_19 = 0 , V_14 = F_15 ( V_7 -> V_50 ) - 1 ; ; ) {
ASSERT ( V_19 <= V_14 ) ;
V_21 = ( V_19 + V_14 ) >> 1 ;
if ( ( V_13 = F_15 ( V_5 [ V_21 ] . V_54 ) ) == args -> V_54 )
break;
if ( V_13 < args -> V_54 )
V_19 = V_21 + 1 ;
else
V_14 = V_21 - 1 ;
if ( V_19 > V_14 ) {
ASSERT ( args -> V_44 & V_73 ) ;
F_9 ( V_26 , V_6 ) ;
return F_10 ( V_74 ) ;
}
}
while ( V_21 > 0 && F_15 ( V_5 [ V_21 - 1 ] . V_54 ) == args -> V_54 ) {
V_21 -- ;
}
do {
if ( ( V_70 = F_15 ( V_5 [ V_21 ] . V_51 ) ) == V_52 )
continue;
V_9 = ( T_7 * )
( ( char * ) V_4 + F_36 ( V_22 , V_70 ) ) ;
V_72 = V_22 -> V_75 -> V_76 ( args , V_9 -> V_56 , V_9 -> V_36 ) ;
if ( V_72 != V_77 && V_72 != args -> V_78 ) {
args -> V_78 = V_72 ;
* V_68 = V_6 ;
* V_69 = V_21 ;
if ( V_72 == V_79 )
return 0 ;
}
} while ( ++ V_21 < F_15 ( V_7 -> V_50 ) &&
F_15 ( V_5 [ V_21 ] . V_54 ) == V_13 );
ASSERT ( args -> V_44 & V_73 ) ;
if ( args -> V_78 == V_80 )
return 0 ;
F_9 ( V_26 , V_6 ) ;
return F_10 ( V_74 ) ;
}
int
F_44 (
T_1 * args )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_9 ;
T_8 * V_10 ;
int V_67 ;
int error ;
T_11 * V_22 ;
int V_23 ;
int V_24 ;
T_17 V_81 ;
int V_82 ;
T_13 * V_26 ;
F_45 ( args ) ;
if ( ( error = F_42 ( args , & V_6 , & V_67 ) ) ) {
return error ;
}
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
V_4 = V_6 -> V_31 ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + F_36 ( V_22 , F_15 ( V_5 [ V_67 ] . V_51 ) ) ) ;
V_23 = V_24 = 0 ;
F_20 ( V_26 , V_6 ,
( V_53 ) ( ( char * ) V_9 - ( char * ) V_4 ) ,
F_11 ( V_9 -> V_36 ) , & V_23 , & V_24 ) ;
F_19 ( & V_7 -> V_38 , 1 ) ;
F_31 ( V_26 , V_6 ) ;
V_5 [ V_67 ] . V_51 = F_7 ( V_52 ) ;
F_26 ( V_26 , V_6 , V_67 , V_67 ) ;
if ( V_24 )
F_21 ( V_22 , V_4 , & V_23 ) ;
if ( V_23 )
F_30 ( V_26 , V_6 ) ;
F_33 ( V_10 , V_6 ) ;
V_82 = F_46 ( V_10 , V_4 , & V_81 ) ;
if ( V_82 > F_47 ( V_10 ) ) {
F_17 ( V_6 ) ;
return 0 ;
}
return F_48 ( args , V_6 , V_82 , & V_81 ) ;
}
int
F_49 (
T_1 * args )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_9 ;
T_8 * V_10 ;
int V_67 ;
int error ;
T_11 * V_22 ;
F_50 ( args ) ;
if ( ( error = F_42 ( args , & V_6 , & V_67 ) ) ) {
return error ;
}
V_10 = args -> V_10 ;
V_22 = V_10 -> V_28 ;
V_4 = V_6 -> V_31 ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + F_36 ( V_22 , F_15 ( V_5 [ V_67 ] . V_51 ) ) ) ;
ASSERT ( F_38 ( V_9 -> V_55 ) != args -> V_55 ) ;
V_9 -> V_55 = F_27 ( args -> V_55 ) ;
F_32 ( args -> V_27 , V_6 , V_9 ) ;
F_33 ( V_10 , V_6 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
static int
F_51 (
const void * V_83 ,
const void * V_84 )
{
const T_4 * V_85 ;
const T_4 * V_86 ;
V_85 = V_83 ;
V_86 = V_84 ;
return F_15 ( V_85 -> V_54 ) < F_15 ( V_86 -> V_54 ) ? - 1 :
( F_15 ( V_85 -> V_54 ) > F_15 ( V_86 -> V_54 ) ? 1 : 0 ) ;
}
int
F_52 (
T_1 * args ,
T_5 * V_87 ,
T_5 * V_88 )
{
T_12 * V_89 ;
T_3 * V_4 ;
T_6 * V_7 ;
T_8 * V_10 ;
T_9 * V_11 ;
int error ;
int V_90 ;
T_18 * V_91 ;
T_4 * V_92 ;
T_19 * V_93 ;
T_11 * V_22 ;
int V_23 ;
int V_24 ;
T_17 V_81 ;
int V_82 ;
T_12 * V_25 ;
int V_94 ;
T_13 * V_26 ;
F_53 ( args ) ;
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
V_91 = V_87 -> V_31 ;
ASSERT ( V_91 -> V_4 . V_95 . V_32 == F_29 ( V_96 ) ) ;
V_93 = F_54 ( V_22 , V_91 ) ;
while ( V_10 -> V_97 . V_98 > V_22 -> V_99 ) {
V_89 = F_55 ( V_93 ) ;
if ( F_14 ( V_89 [ F_15 ( V_93 -> V_100 ) - 1 ] ) ==
V_22 -> V_99 - ( V_43 ) sizeof( * V_4 ) ) {
if ( ( error =
F_56 ( args , V_87 ,
( V_101 ) ( F_15 ( V_93 -> V_100 ) - 1 ) ) ) )
goto V_102;
} else {
error = 0 ;
goto V_102;
}
}
if ( V_88 == NULL &&
( error = F_5 ( V_26 , V_10 , V_22 -> V_29 , - 1 , & V_88 ,
V_30 ) ) ) {
goto V_102;
}
V_4 = V_88 -> V_31 ;
ASSERT ( V_4 -> V_32 == F_7 ( V_103 ) ) ;
V_82 = ( V_43 ) sizeof( T_6 ) +
( V_43 ) sizeof( * V_92 ) * ( F_14 ( V_91 -> V_4 . V_50 ) - F_14 ( V_91 -> V_4 . V_38 ) ) ;
V_25 = ( T_12 * ) ( ( char * ) V_4 + V_22 -> V_99 ) - 1 ;
V_11 = ( T_9 * ) ( ( char * ) V_4 + F_14 ( * V_25 ) ) ;
if ( F_14 ( V_11 -> V_39 ) != V_40 ||
F_14 ( V_11 -> V_42 ) < V_82 ) {
error = 0 ;
goto V_102;
}
V_4 -> V_32 = F_7 ( V_33 ) ;
V_23 = 1 ;
V_24 = 0 ;
F_22 ( V_26 , V_88 , V_11 , V_22 -> V_99 - V_82 , V_82 ,
& V_23 , & V_24 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_7 -> V_50 = F_7 ( F_14 ( V_91 -> V_4 . V_50 ) - F_14 ( V_91 -> V_4 . V_38 ) ) ;
V_7 -> V_38 = 0 ;
F_31 ( V_26 , V_88 ) ;
V_92 = F_13 ( V_7 ) ;
for ( V_90 = V_94 = 0 ; V_90 < F_14 ( V_91 -> V_4 . V_50 ) ; V_90 ++ ) {
if ( V_91 -> V_104 [ V_90 ] . V_51 ==
F_7 ( V_52 ) )
continue;
V_92 [ V_94 ++ ] = V_91 -> V_104 [ V_90 ] ;
}
ASSERT ( V_94 == F_15 ( V_7 -> V_50 ) ) ;
F_26 ( V_26 , V_88 , 0 , F_15 ( V_7 -> V_50 ) - 1 ) ;
if ( V_24 )
F_21 ( V_22 , V_4 , & V_23 ) ;
if ( V_23 )
F_30 ( V_26 , V_88 ) ;
error = F_57 ( args , V_22 -> V_105 , V_87 ) ;
V_87 = NULL ;
if ( error ) {
goto V_102;
}
V_82 = F_46 ( V_10 , V_4 , & V_81 ) ;
if ( V_82 > F_47 ( V_10 ) ) {
error = 0 ;
goto V_102;
}
return F_48 ( args , V_88 , V_82 , & V_81 ) ;
V_102:
if ( V_87 )
F_17 ( V_87 ) ;
if ( V_88 )
F_17 ( V_88 ) ;
return error ;
}
int
F_58 (
T_1 * args )
{
V_101 V_106 ;
T_3 * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_9 ;
T_8 * V_10 ;
int V_107 ;
T_9 * V_11 ;
int V_108 ;
int error ;
int V_109 ;
T_11 * V_22 ;
int V_23 ;
int V_24 ;
int V_110 ;
int V_41 ;
T_20 * V_111 ;
T_17 * V_112 ;
T_17 * V_113 ;
T_12 * V_25 ;
T_13 * V_26 ;
struct V_114 V_56 ;
F_59 ( args ) ;
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
ASSERT ( V_10 -> V_115 . V_116 & V_117 ) ;
if ( V_10 -> V_97 . V_98 < F_60 ( T_17 , V_118 ) ) {
ASSERT ( F_61 ( V_22 ) ) ;
return F_10 ( V_119 ) ;
}
V_112 = ( T_17 * ) V_10 -> V_115 . V_120 . V_121 ;
ASSERT ( V_10 -> V_115 . V_122 == V_10 -> V_97 . V_98 ) ;
ASSERT ( V_10 -> V_115 . V_120 . V_121 != NULL ) ;
ASSERT ( V_10 -> V_97 . V_98 >= F_62 ( V_112 -> V_123 ) ) ;
V_113 = F_63 ( V_10 -> V_115 . V_122 , V_124 ) ;
memcpy ( V_113 , V_112 , V_10 -> V_115 . V_122 ) ;
F_64 ( V_10 , - V_10 -> V_115 . V_122 , V_30 ) ;
V_10 -> V_97 . V_98 = 0 ;
F_65 ( V_26 , V_10 , V_125 ) ;
error = F_66 ( args , V_126 , & V_106 ) ;
if ( error ) {
F_67 ( V_113 ) ;
return error ;
}
error = F_68 ( args , V_106 , & V_6 ) ;
if ( error ) {
F_67 ( V_113 ) ;
return error ;
}
V_4 = V_6 -> V_31 ;
V_4 -> V_32 = F_7 ( V_33 ) ;
V_109 = ( V_43 ) sizeof( * V_7 ) +
( V_113 -> V_50 + 2 ) * ( V_43 ) sizeof( T_4 ) ;
V_11 = ( T_9 * ) ( V_4 + 1 ) ;
V_23 = V_24 = 0 ;
F_22 ( V_26 , V_6 , V_11 , V_22 -> V_99 - V_109 , V_109 , & V_23 ,
& V_24 ) ;
ASSERT ( V_24 == 0 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_7 -> V_50 = F_7 ( V_113 -> V_50 + 2 ) ;
V_7 -> V_38 = 0 ;
V_5 = F_13 ( V_7 ) ;
V_108 = ( V_43 ) ( ( char * ) V_5 - ( char * ) V_4 ) ;
F_22 ( V_26 , V_6 , V_11 ,
( V_53 ) ( ( char * ) V_11 - ( char * ) V_4 ) ,
F_14 ( V_11 -> V_42 ) , & V_23 , & V_24 ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + V_127 ) ;
V_9 -> V_55 = F_27 ( V_10 -> V_128 ) ;
V_9 -> V_36 = 1 ;
V_9 -> V_56 [ 0 ] = '.' ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
V_5 [ 0 ] . V_54 = F_7 ( V_1 ) ;
V_5 [ 0 ] . V_51 = F_7 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + V_129 ) ;
V_9 -> V_55 = F_27 ( F_69 ( V_113 ) ) ;
V_9 -> V_36 = 2 ;
V_9 -> V_56 [ 0 ] = V_9 -> V_56 [ 1 ] = '.' ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
V_5 [ 1 ] . V_54 = F_7 ( V_2 ) ;
V_5 [ 1 ] . V_51 = F_7 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
V_41 = V_130 ;
V_109 = 0 ;
if ( ! V_113 -> V_50 )
V_111 = NULL ;
else
V_111 = F_70 ( V_113 ) ;
while ( V_41 < V_108 ) {
if ( V_111 == NULL )
V_110 = V_108 ;
else
V_110 = F_71 ( V_111 ) ;
if ( V_41 < V_110 ) {
V_11 = ( T_9 * ) ( ( char * ) V_4 + V_41 ) ;
V_11 -> V_39 = F_29 ( V_40 ) ;
V_11 -> V_42 = F_29 ( V_110 - V_41 ) ;
* F_72 ( V_11 ) = F_29 (
( ( char * ) V_11 - ( char * ) V_4 ) ) ;
F_73 ( V_26 , V_6 , V_11 ) ;
F_74 ( V_4 , V_11 , & V_107 ) ;
V_41 += F_14 ( V_11 -> V_42 ) ;
continue;
}
V_9 = ( T_7 * ) ( ( char * ) V_4 + V_110 ) ;
V_9 -> V_55 = F_27 ( F_75 ( V_113 , V_111 ) ) ;
V_9 -> V_36 = V_111 -> V_36 ;
memcpy ( V_9 -> V_56 , V_111 -> V_56 , V_9 -> V_36 ) ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
V_56 . V_56 = V_111 -> V_56 ;
V_56 . V_18 = V_111 -> V_36 ;
V_5 [ 2 + V_109 ] . V_54 = F_7 ( V_22 -> V_75 ->
V_131 ( & V_56 ) ) ;
V_5 [ 2 + V_109 ] . V_51 = F_7 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
V_41 = ( int ) ( ( char * ) ( V_25 + 1 ) - ( char * ) V_4 ) ;
if ( ++ V_109 == V_113 -> V_50 )
V_111 = NULL ;
else
V_111 = F_76 ( V_113 , V_111 ) ;
}
F_67 ( V_113 ) ;
F_77 ( V_5 , F_15 ( V_7 -> V_50 ) , sizeof( * V_5 ) , F_51 ) ;
ASSERT ( V_24 == 0 ) ;
F_26 ( V_26 , V_6 , 0 , F_15 ( V_7 -> V_50 ) - 1 ) ;
F_31 ( V_26 , V_6 ) ;
F_33 ( V_10 , V_6 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
