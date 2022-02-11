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
if ( F_6 ( F_7 ( V_4 -> V_32 . V_33 ) != V_34 ) ) {
F_8 ( L_3 ,
V_35 , V_22 , V_4 ) ;
F_9 ( V_26 , V_6 ) ;
return F_10 ( V_36 ) ;
}
V_18 = F_11 ( args -> V_37 ) ;
V_3 = V_4 -> V_32 . V_38 ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
if ( ! V_7 -> V_39 ) {
V_25 = ( T_12 * ) V_5 - 1 ;
V_12 = ( T_9 * ) ( ( char * ) V_4 + F_14 ( * V_25 ) ) ;
if ( F_14 ( V_12 -> V_40 ) != V_41 )
V_11 = V_12 = NULL ;
else {
V_11 = ( T_9 * )
( ( char * ) V_4 + F_14 ( V_3 [ 0 ] . V_42 ) ) ;
if ( V_11 == V_12 ) {
if ( F_14 ( V_11 -> V_43 ) < V_18 + ( V_44 ) sizeof( * V_5 ) ) {
if ( F_14 ( V_3 [ 1 ] . V_43 ) >= V_18 )
V_11 = ( T_9 * )
( ( char * ) V_4 +
F_14 ( V_3 [ 1 ] . V_42 ) ) ;
else
V_11 = NULL ;
}
} else {
if ( F_14 ( V_11 -> V_43 ) < V_18 ) {
V_11 = NULL ;
}
}
}
V_8 = 0 ;
}
else if ( F_14 ( V_3 [ 0 ] . V_43 ) >= V_18 ) {
V_11 = ( T_9 * )
( ( char * ) V_4 + F_14 ( V_3 [ 0 ] . V_42 ) ) ;
V_8 = 0 ;
}
else {
V_25 = ( T_12 * ) V_5 - 1 ;
V_11 = ( T_9 * ) ( ( char * ) V_4 + F_14 ( * V_25 ) ) ;
if ( F_14 ( V_11 -> V_40 ) == V_41 ) {
if ( F_14 ( V_11 -> V_43 ) + ( F_7 ( V_7 -> V_39 ) - 1 ) *
( V_44 ) sizeof( * V_5 ) < V_18 )
V_11 = NULL ;
} else if ( ( F_7 ( V_7 -> V_39 ) - 1 ) * ( V_44 ) sizeof( * V_5 ) < V_18 )
V_11 = NULL ;
else
V_11 = ( T_9 * ) V_5 ;
V_8 = 1 ;
}
if ( args -> V_45 & V_46 )
F_9 ( V_26 , V_6 ) ;
if ( ! V_11 ) {
if ( ( args -> V_45 & V_46 ) || args -> V_47 == 0 )
return F_10 ( V_48 ) ;
error = F_15 ( args , V_6 ) ;
F_16 ( V_6 ) ;
if ( error )
return error ;
return F_17 ( args ) ;
}
if ( args -> V_45 & V_46 )
return 0 ;
V_23 = V_24 = 0 ;
if ( V_8 ) {
int V_49 ;
int V_50 ;
for ( V_49 = V_50 = F_7 ( V_7 -> V_51 ) - 1 ,
V_15 = V_16 = - 1 ;
V_49 >= 0 ;
V_49 -- ) {
if ( F_7 ( V_5 [ V_49 ] . V_52 ) == V_53 ) {
if ( V_15 == - 1 )
V_15 = V_50 ;
else {
if ( V_16 == - 1 )
V_16 = V_50 ;
continue;
}
}
if ( V_49 < V_50 )
V_5 [ V_50 ] = V_5 [ V_49 ] ;
V_50 -- ;
}
V_17 = V_50 + 1 - ( F_7 ( V_7 -> V_39 ) - 1 ) ;
V_16 -= F_7 ( V_7 -> V_39 ) - 1 ;
F_18 ( & V_7 -> V_51 , - ( F_7 ( V_7 -> V_39 ) - 1 ) ) ;
F_19 ( V_26 , V_6 ,
( V_54 ) ( ( char * ) V_5 - ( char * ) V_4 ) ,
( V_54 ) ( ( F_7 ( V_7 -> V_39 ) - 1 ) * sizeof( * V_5 ) ) ,
& V_23 , & V_24 ) ;
V_5 += F_7 ( V_7 -> V_39 ) - 1 ;
V_7 -> V_39 = F_20 ( 1 ) ;
if ( V_24 ) {
F_21 ( V_22 , ( V_55 * ) V_4 , & V_23 ) ;
V_24 = 0 ;
}
}
else if ( V_7 -> V_39 ) {
V_17 = F_7 ( V_7 -> V_51 ) ;
V_16 = - 1 ;
}
for ( V_19 = 0 , V_14 = F_7 ( V_7 -> V_51 ) - 1 ; V_19 <= V_14 ; ) {
V_21 = ( V_19 + V_14 ) >> 1 ;
if ( ( V_13 = F_7 ( V_5 [ V_21 ] . V_56 ) ) == args -> V_56 )
break;
if ( V_13 < args -> V_56 )
V_19 = V_21 + 1 ;
else
V_14 = V_21 - 1 ;
}
while ( V_21 >= 0 && F_7 ( V_5 [ V_21 ] . V_56 ) >= args -> V_56 ) {
V_21 -- ;
}
if ( ! V_7 -> V_39 ) {
F_22 ( V_26 , V_6 , V_12 ,
( V_54 )
( ( char * ) V_12 - ( char * ) V_4 + F_14 ( V_12 -> V_43 ) -
sizeof( * V_5 ) ) ,
( V_54 ) sizeof( * V_5 ) ,
& V_23 , & V_24 ) ;
F_18 ( & V_7 -> V_51 , 1 ) ;
if ( V_24 ) {
F_21 ( V_22 , ( V_55 * ) V_4 ,
& V_23 ) ;
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
F_7 ( V_5 [ V_20 ] . V_52 ) != V_53 ;
V_20 -- )
continue;
for ( V_15 = V_21 + 1 ;
V_15 < F_7 ( V_7 -> V_51 ) &&
F_7 ( V_5 [ V_15 ] . V_52 ) != V_53 &&
( V_20 < 0 || V_21 - V_20 > V_15 - V_21 ) ;
V_15 ++ )
continue;
if ( V_20 >= 0 &&
( V_15 == F_7 ( V_7 -> V_51 ) ||
V_21 - V_20 <= V_15 - V_21 ) ) {
if ( V_21 - V_20 )
memmove ( & V_5 [ V_20 ] , & V_5 [ V_20 + 1 ] ,
( V_21 - V_20 ) * sizeof( * V_5 ) ) ;
V_17 = F_23 ( V_20 , V_17 ) ;
V_16 = F_24 ( V_21 , V_16 ) ;
}
else {
ASSERT ( V_15 < F_7 ( V_7 -> V_51 ) ) ;
V_21 ++ ;
if ( V_15 - V_21 )
memmove ( & V_5 [ V_21 + 1 ] , & V_5 [ V_21 ] ,
( V_15 - V_21 ) * sizeof( * V_5 ) ) ;
V_17 = F_23 ( V_21 , V_17 ) ;
V_16 = F_24 ( V_15 , V_16 ) ;
}
F_18 ( & V_7 -> V_39 , - 1 ) ;
}
V_9 = ( T_7 * ) V_11 ;
V_5 [ V_21 ] . V_56 = F_20 ( args -> V_56 ) ;
V_5 [ V_21 ] . V_52 = F_20 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
F_26 ( V_26 , V_6 , V_17 , V_16 ) ;
F_22 ( V_26 , V_6 , V_11 ,
( V_54 ) ( ( char * ) V_11 - ( char * ) V_4 ) ,
( V_54 ) V_18 , & V_23 , & V_24 ) ;
V_9 -> V_57 = F_27 ( args -> V_57 ) ;
V_9 -> V_37 = args -> V_37 ;
memcpy ( V_9 -> V_58 , args -> V_58 , args -> V_37 ) ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
if ( V_24 )
F_21 ( V_22 , ( V_55 * ) V_4 , & V_23 ) ;
if ( V_23 )
F_30 ( V_26 , V_6 ) ;
F_31 ( V_26 , V_6 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
F_33 ( V_10 , V_6 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
int
F_34 (
T_8 * V_10 ,
void * V_59 ,
T_14 * V_42 ,
T_15 V_60 )
{
T_3 * V_4 ;
T_5 * V_6 ;
T_6 * V_7 ;
T_7 * V_9 ;
T_9 * V_11 ;
char * V_61 ;
int error ;
T_11 * V_22 ;
char * V_62 ;
int V_63 ;
T_14 V_64 ;
V_22 = V_10 -> V_28 ;
if ( F_35 ( V_22 , * V_42 ) > V_22 -> V_29 ) {
return 0 ;
}
error = F_5 ( NULL , V_10 , V_22 -> V_29 , - 1 ,
& V_6 , V_30 ) ;
if ( error )
return error ;
ASSERT ( V_6 != NULL ) ;
V_63 = F_36 ( V_22 , * V_42 ) ;
V_4 = V_6 -> V_31 ;
F_33 ( V_10 , V_6 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_62 = ( char * ) V_4 -> V_65 ;
V_61 = ( char * ) F_13 ( V_7 ) ;
while ( V_62 < V_61 ) {
V_11 = ( T_9 * ) V_62 ;
if ( F_14 ( V_11 -> V_40 ) == V_41 ) {
V_62 += F_14 ( V_11 -> V_43 ) ;
continue;
}
V_9 = ( T_7 * ) V_62 ;
V_62 += F_11 ( V_9 -> V_37 ) ;
if ( ( char * ) V_9 - ( char * ) V_4 < V_63 )
continue;
V_64 = F_37 ( V_22 , V_22 -> V_29 ,
( char * ) V_9 - ( char * ) V_4 ) ;
if ( V_60 ( V_59 , ( char * ) V_9 -> V_58 , V_9 -> V_37 ,
V_64 & 0x7fffffff , F_38 ( V_9 -> V_57 ) ,
V_66 ) ) {
* V_42 = V_64 & 0x7fffffff ;
F_9 ( NULL , V_6 ) ;
return 0 ;
}
}
* V_42 = F_37 ( V_22 , V_22 -> V_29 + 1 , 0 ) &
0x7fffffff ;
F_9 ( NULL , V_6 ) ;
return 0 ;
}
static void
F_26 (
T_13 * V_26 ,
T_5 * V_6 ,
int V_67 ,
int V_68 )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_6 * V_7 ;
T_11 * V_22 ;
V_22 = V_26 -> V_69 ;
V_4 = V_6 -> V_31 ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
F_39 ( V_26 , V_6 , ( V_44 ) ( ( char * ) & V_5 [ V_67 ] - ( char * ) V_4 ) ,
( V_44 ) ( ( char * ) & V_5 [ V_68 + 1 ] - ( char * ) V_4 - 1 ) ) ;
}
static void
F_31 (
T_13 * V_26 ,
T_5 * V_6 )
{
T_3 * V_4 ;
T_6 * V_7 ;
T_11 * V_22 ;
V_22 = V_26 -> V_69 ;
V_4 = V_6 -> V_31 ;
V_7 = F_12 ( V_22 , V_4 ) ;
F_39 ( V_26 , V_6 , ( V_44 ) ( ( char * ) V_7 - ( char * ) V_4 ) ,
( V_44 ) ( ( char * ) ( V_7 + 1 ) - ( char * ) V_4 - 1 ) ) ;
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
int V_70 ;
int error ;
T_11 * V_22 ;
F_41 ( args ) ;
if ( ( error = F_42 ( args , & V_6 , & V_70 ) ) )
return error ;
V_10 = args -> V_10 ;
V_22 = V_10 -> V_28 ;
V_4 = V_6 -> V_31 ;
F_33 ( V_10 , V_6 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
V_9 = ( T_7 * ) ( ( char * ) V_4 +
F_36 ( V_22 , F_7 ( V_5 [ V_70 ] . V_52 ) ) ) ;
args -> V_57 = F_38 ( V_9 -> V_57 ) ;
error = F_43 ( args , V_9 -> V_58 , V_9 -> V_37 ) ;
F_9 ( args -> V_27 , V_6 ) ;
return F_10 ( error ) ;
}
static int
F_42 (
T_1 * args ,
T_5 * * V_71 ,
int * V_72 )
{
T_16 V_73 ;
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
enum V_74 V_75 ;
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
for ( V_19 = 0 , V_14 = F_7 ( V_7 -> V_51 ) - 1 ; ; ) {
ASSERT ( V_19 <= V_14 ) ;
V_21 = ( V_19 + V_14 ) >> 1 ;
if ( ( V_13 = F_7 ( V_5 [ V_21 ] . V_56 ) ) == args -> V_56 )
break;
if ( V_13 < args -> V_56 )
V_19 = V_21 + 1 ;
else
V_14 = V_21 - 1 ;
if ( V_19 > V_14 ) {
ASSERT ( args -> V_45 & V_76 ) ;
F_9 ( V_26 , V_6 ) ;
return F_10 ( V_77 ) ;
}
}
while ( V_21 > 0 && F_7 ( V_5 [ V_21 - 1 ] . V_56 ) == args -> V_56 ) {
V_21 -- ;
}
do {
if ( ( V_73 = F_7 ( V_5 [ V_21 ] . V_52 ) ) == V_53 )
continue;
V_9 = ( T_7 * )
( ( char * ) V_4 + F_36 ( V_22 , V_73 ) ) ;
V_75 = V_22 -> V_78 -> V_79 ( args , V_9 -> V_58 , V_9 -> V_37 ) ;
if ( V_75 != V_80 && V_75 != args -> V_81 ) {
args -> V_81 = V_75 ;
* V_71 = V_6 ;
* V_72 = V_21 ;
if ( V_75 == V_82 )
return 0 ;
}
} while ( ++ V_21 < F_7 ( V_7 -> V_51 ) &&
F_7 ( V_5 [ V_21 ] . V_56 ) == V_13 );
ASSERT ( args -> V_45 & V_76 ) ;
if ( args -> V_81 == V_83 )
return 0 ;
F_9 ( V_26 , V_6 ) ;
return F_10 ( V_77 ) ;
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
int V_70 ;
int error ;
T_11 * V_22 ;
int V_23 ;
int V_24 ;
T_17 V_84 ;
int V_85 ;
T_13 * V_26 ;
F_45 ( args ) ;
if ( ( error = F_42 ( args , & V_6 , & V_70 ) ) ) {
return error ;
}
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
V_4 = V_6 -> V_31 ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + F_36 ( V_22 , F_7 ( V_5 [ V_70 ] . V_52 ) ) ) ;
V_23 = V_24 = 0 ;
F_19 ( V_26 , V_6 ,
( V_54 ) ( ( char * ) V_9 - ( char * ) V_4 ) ,
F_11 ( V_9 -> V_37 ) , & V_23 , & V_24 ) ;
F_18 ( & V_7 -> V_39 , 1 ) ;
F_31 ( V_26 , V_6 ) ;
V_5 [ V_70 ] . V_52 = F_20 ( V_53 ) ;
F_26 ( V_26 , V_6 , V_70 , V_70 ) ;
if ( V_24 )
F_21 ( V_22 , ( V_55 * ) V_4 , & V_23 ) ;
if ( V_23 )
F_30 ( V_26 , V_6 ) ;
F_33 ( V_10 , V_6 ) ;
if ( ( V_85 = F_46 ( V_10 , V_4 , & V_84 ) ) >
F_47 ( V_10 ) ) {
F_16 ( V_6 ) ;
return 0 ;
}
return F_48 ( args , V_6 , V_85 , & V_84 ) ;
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
int V_70 ;
int error ;
T_11 * V_22 ;
F_50 ( args ) ;
if ( ( error = F_42 ( args , & V_6 , & V_70 ) ) ) {
return error ;
}
V_10 = args -> V_10 ;
V_22 = V_10 -> V_28 ;
V_4 = V_6 -> V_31 ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_5 = F_13 ( V_7 ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + F_36 ( V_22 , F_7 ( V_5 [ V_70 ] . V_52 ) ) ) ;
ASSERT ( F_38 ( V_9 -> V_57 ) != args -> V_57 ) ;
V_9 -> V_57 = F_27 ( args -> V_57 ) ;
F_32 ( args -> V_27 , V_6 , V_9 ) ;
F_33 ( V_10 , V_6 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
static int
F_51 (
const void * V_86 ,
const void * V_87 )
{
const T_4 * V_88 ;
const T_4 * V_89 ;
V_88 = V_86 ;
V_89 = V_87 ;
return F_7 ( V_88 -> V_56 ) < F_7 ( V_89 -> V_56 ) ? - 1 :
( F_7 ( V_88 -> V_56 ) > F_7 ( V_89 -> V_56 ) ? 1 : 0 ) ;
}
int
F_52 (
T_1 * args ,
T_5 * V_90 ,
T_5 * V_91 )
{
T_12 * V_92 ;
T_3 * V_4 ;
T_6 * V_7 ;
T_8 * V_10 ;
T_9 * V_11 ;
int error ;
int V_93 ;
T_18 * V_94 ;
T_4 * V_95 ;
T_19 * V_96 ;
T_11 * V_22 ;
int V_23 ;
int V_24 ;
T_17 V_84 ;
int V_85 ;
T_12 * V_25 ;
int V_97 ;
T_13 * V_26 ;
F_53 ( args ) ;
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
V_94 = V_90 -> V_31 ;
ASSERT ( F_14 ( V_94 -> V_32 . V_98 . V_33 ) == V_99 ) ;
V_96 = F_54 ( V_22 , V_94 ) ;
while ( V_10 -> V_100 . V_101 > V_22 -> V_102 ) {
V_92 = F_55 ( V_96 ) ;
if ( F_14 ( V_92 [ F_7 ( V_96 -> V_103 ) - 1 ] ) ==
V_22 -> V_102 - ( V_44 ) sizeof( V_4 -> V_32 ) ) {
if ( ( error =
F_56 ( args , V_90 ,
( V_104 ) ( F_7 ( V_96 -> V_103 ) - 1 ) ) ) )
goto V_105;
} else {
error = 0 ;
goto V_105;
}
}
if ( V_91 == NULL &&
( error = F_5 ( V_26 , V_10 , V_22 -> V_29 , - 1 , & V_91 ,
V_30 ) ) ) {
goto V_105;
}
V_4 = V_91 -> V_31 ;
ASSERT ( F_7 ( V_4 -> V_32 . V_33 ) == V_106 ) ;
V_85 = ( V_44 ) sizeof( V_4 -> V_107 ) +
( V_44 ) sizeof( * V_95 ) * ( F_14 ( V_94 -> V_32 . V_51 ) - F_14 ( V_94 -> V_32 . V_39 ) ) ;
V_25 = ( T_12 * ) ( ( char * ) V_4 + V_22 -> V_102 ) - 1 ;
V_11 = ( T_9 * ) ( ( char * ) V_4 + F_14 ( * V_25 ) ) ;
if ( F_14 ( V_11 -> V_40 ) != V_41 ||
F_14 ( V_11 -> V_43 ) < V_85 ) {
error = 0 ;
goto V_105;
}
V_4 -> V_32 . V_33 = F_20 ( V_34 ) ;
V_23 = 1 ;
V_24 = 0 ;
F_22 ( V_26 , V_91 , V_11 , V_22 -> V_102 - V_85 , V_85 ,
& V_23 , & V_24 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_7 -> V_51 = F_20 ( F_14 ( V_94 -> V_32 . V_51 ) - F_14 ( V_94 -> V_32 . V_39 ) ) ;
V_7 -> V_39 = 0 ;
F_31 ( V_26 , V_91 ) ;
V_95 = F_13 ( V_7 ) ;
for ( V_93 = V_97 = 0 ; V_93 < F_14 ( V_94 -> V_32 . V_51 ) ; V_93 ++ ) {
if ( F_7 ( V_94 -> V_108 [ V_93 ] . V_52 ) == V_53 )
continue;
V_95 [ V_97 ++ ] = V_94 -> V_108 [ V_93 ] ;
}
ASSERT ( V_97 == F_7 ( V_7 -> V_51 ) ) ;
F_26 ( V_26 , V_91 , 0 , F_7 ( V_7 -> V_51 ) - 1 ) ;
if ( V_24 )
F_21 ( V_22 , ( V_55 * ) V_4 , & V_23 ) ;
if ( V_23 )
F_30 ( V_26 , V_91 ) ;
error = F_57 ( args , V_22 -> V_109 , V_90 ) ;
V_90 = NULL ;
if ( error ) {
goto V_105;
}
if ( ( V_85 = F_46 ( V_10 , V_4 , & V_84 ) ) >
F_47 ( V_10 ) ) {
error = 0 ;
goto V_105;
}
return F_48 ( args , V_91 , V_85 , & V_84 ) ;
V_105:
if ( V_90 )
F_16 ( V_90 ) ;
if ( V_91 )
F_16 ( V_91 ) ;
return error ;
}
int
F_58 (
T_1 * args )
{
V_104 V_110 ;
T_3 * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_6 * V_7 ;
char * V_111 ;
int V_112 ;
T_7 * V_9 ;
T_8 * V_10 ;
int V_113 ;
T_9 * V_11 ;
int V_114 ;
int error ;
int V_115 ;
T_11 * V_22 ;
int V_23 ;
int V_24 ;
int V_116 ;
int V_42 ;
T_20 * V_117 ;
T_21 * V_118 ;
T_12 * V_25 ;
T_13 * V_26 ;
struct V_119 V_58 ;
F_59 ( args ) ;
V_10 = args -> V_10 ;
V_26 = args -> V_27 ;
V_22 = V_10 -> V_28 ;
ASSERT ( V_10 -> V_120 . V_121 & V_122 ) ;
if ( V_10 -> V_100 . V_101 < F_60 ( T_17 , V_123 ) ) {
ASSERT ( F_61 ( V_22 ) ) ;
return F_10 ( V_124 ) ;
}
ASSERT ( V_10 -> V_120 . V_125 == V_10 -> V_100 . V_101 ) ;
ASSERT ( V_10 -> V_120 . V_126 . V_127 != NULL ) ;
V_118 = ( T_21 * ) V_10 -> V_120 . V_126 . V_127 ;
ASSERT ( V_10 -> V_100 . V_101 >= F_62 ( V_118 -> V_32 . V_128 ) ) ;
V_112 = V_10 -> V_120 . V_125 ;
V_111 = F_63 ( V_112 , V_129 ) ;
memcpy ( V_111 , V_118 , V_112 ) ;
F_64 ( V_10 , - V_112 , V_30 ) ;
V_10 -> V_100 . V_101 = 0 ;
F_65 ( V_26 , V_10 , V_130 ) ;
V_118 = ( T_21 * ) V_111 ;
error = F_66 ( args , V_131 , & V_110 ) ;
if ( error ) {
F_67 ( V_111 ) ;
return error ;
}
error = F_68 ( args , V_110 , & V_6 ) ;
if ( error ) {
F_67 ( V_111 ) ;
return error ;
}
V_4 = V_6 -> V_31 ;
V_4 -> V_32 . V_33 = F_20 ( V_34 ) ;
V_115 = ( V_44 ) sizeof( * V_7 ) +
( V_118 -> V_32 . V_51 + 2 ) * ( V_44 ) sizeof( T_4 ) ;
V_11 = ( T_9 * ) V_4 -> V_65 ;
V_23 = V_24 = 0 ;
F_22 ( V_26 , V_6 , V_11 , V_22 -> V_102 - V_115 , V_115 , & V_23 ,
& V_24 ) ;
ASSERT ( V_24 == 0 ) ;
V_7 = F_12 ( V_22 , V_4 ) ;
V_7 -> V_51 = F_20 ( V_118 -> V_32 . V_51 + 2 ) ;
V_7 -> V_39 = 0 ;
V_5 = F_13 ( V_7 ) ;
V_114 = ( V_44 ) ( ( char * ) V_5 - ( char * ) V_4 ) ;
F_22 ( V_26 , V_6 , V_11 ,
( V_54 ) ( ( char * ) V_11 - ( char * ) V_4 ) ,
F_14 ( V_11 -> V_43 ) , & V_23 , & V_24 ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + V_132 ) ;
V_9 -> V_57 = F_27 ( V_10 -> V_133 ) ;
V_9 -> V_37 = 1 ;
V_9 -> V_58 [ 0 ] = '.' ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
V_5 [ 0 ] . V_56 = F_20 ( V_1 ) ;
V_5 [ 0 ] . V_52 = F_20 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
V_9 = ( T_7 * )
( ( char * ) V_4 + V_134 ) ;
V_9 -> V_57 = F_27 ( F_69 ( V_118 , & V_118 -> V_32 . V_123 ) ) ;
V_9 -> V_37 = 2 ;
V_9 -> V_58 [ 0 ] = V_9 -> V_58 [ 1 ] = '.' ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
V_5 [ 1 ] . V_56 = F_20 ( V_2 ) ;
V_5 [ 1 ] . V_52 = F_20 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
V_42 = V_135 ;
if ( ( V_115 = 0 ) == V_118 -> V_32 . V_51 )
V_117 = NULL ;
else
V_117 = F_70 ( V_118 ) ;
while ( V_42 < V_114 ) {
if ( V_117 == NULL )
V_116 = V_114 ;
else
V_116 = F_71 ( V_117 ) ;
if ( V_42 < V_116 ) {
V_11 = ( T_9 * )
( ( char * ) V_4 + V_42 ) ;
V_11 -> V_40 = F_29 ( V_41 ) ;
V_11 -> V_43 = F_29 ( V_116 - V_42 ) ;
* F_72 ( V_11 ) = F_29 (
( ( char * ) V_11 - ( char * ) V_4 ) ) ;
F_73 ( V_26 , V_6 , V_11 ) ;
( void ) F_74 ( ( V_55 * ) V_4 ,
V_11 , & V_113 ) ;
V_42 += F_14 ( V_11 -> V_43 ) ;
continue;
}
V_9 = ( T_7 * ) ( ( char * ) V_4 + V_116 ) ;
V_9 -> V_57 = F_27 ( F_69 ( V_118 ,
F_75 ( V_117 ) ) ) ;
V_9 -> V_37 = V_117 -> V_37 ;
memcpy ( V_9 -> V_58 , V_117 -> V_58 , V_9 -> V_37 ) ;
V_25 = F_28 ( V_9 ) ;
* V_25 = F_29 ( ( char * ) V_9 - ( char * ) V_4 ) ;
F_32 ( V_26 , V_6 , V_9 ) ;
V_58 . V_58 = V_117 -> V_58 ;
V_58 . V_18 = V_117 -> V_37 ;
V_5 [ 2 + V_115 ] . V_56 = F_20 ( V_22 -> V_78 ->
V_136 ( & V_58 ) ) ;
V_5 [ 2 + V_115 ] . V_52 = F_20 ( F_25 ( V_22 ,
( char * ) V_9 - ( char * ) V_4 ) ) ;
V_42 = ( int ) ( ( char * ) ( V_25 + 1 ) - ( char * ) V_4 ) ;
if ( ++ V_115 == V_118 -> V_32 . V_51 )
V_117 = NULL ;
else
V_117 = F_76 ( V_118 , V_117 ) ;
}
F_67 ( V_111 ) ;
F_77 ( V_5 , F_7 ( V_7 -> V_51 ) , sizeof( * V_5 ) , F_51 ) ;
ASSERT ( V_24 == 0 ) ;
F_26 ( V_26 , V_6 , 0 , F_7 ( V_7 -> V_51 ) - 1 ) ;
F_31 ( V_26 , V_6 ) ;
F_33 ( V_10 , V_6 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
