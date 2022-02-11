void
F_1 ( void )
{
V_1 = F_2 ( ( unsigned char * ) L_1 , 1 ) ;
V_2 = F_2 ( ( unsigned char * ) L_2 , 2 ) ;
}
static void
F_3 (
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 ;
int V_12 = 0 ;
V_12 = V_10 -> V_13 == F_4 ( V_14 ) ;
V_12 = V_12 && F_5 ( NULL , V_4 ) == 0 ;
if ( ! V_12 ) {
F_6 ( V_15 , V_16 , V_6 , V_10 ) ;
F_7 ( V_4 , V_17 ) ;
}
}
static void
F_8 (
struct V_3 * V_4 )
{
F_3 ( V_4 ) ;
}
static void
F_9 (
struct V_3 * V_4 )
{
F_3 ( V_4 ) ;
}
static int
F_10 (
struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_3 * * V_22 )
{
struct V_5 * V_6 = V_21 -> V_23 ;
return F_11 ( V_19 , V_21 , V_6 -> V_24 , - 1 , V_22 ,
V_25 , & V_26 ) ;
}
static void
F_12 (
struct V_9 * V_10 ,
struct V_27 * V_28 ,
struct V_29 * V_30 ,
T_1 * * V_31 ,
struct V_32 * * V_33 ,
struct V_32 * * V_34 ,
int * V_35 ,
int V_36 )
{
struct V_37 * V_38 ;
T_1 * V_39 = NULL ;
struct V_32 * V_40 = NULL ;
struct V_32 * V_41 = NULL ;
* V_35 = 0 ;
V_38 = V_10 -> V_42 ;
if ( V_28 -> V_43 ) {
if ( F_13 ( V_38 [ 0 ] . V_44 ) >= V_36 ) {
V_40 = ( V_45 * )
( ( char * ) V_10 + F_13 ( V_38 [ 0 ] . V_46 ) ) ;
goto V_47;
}
* V_35 = 1 ;
V_39 = ( T_1 * ) V_30 - 1 ;
V_40 = ( V_45 * ) ( ( char * ) V_10 + F_13 ( * V_39 ) ) ;
if ( F_13 ( V_40 -> V_48 ) == V_49 ) {
if ( F_13 ( V_40 -> V_44 ) + ( F_14 ( V_28 -> V_43 ) - 1 ) *
( V_50 ) sizeof( * V_30 ) < V_36 )
V_40 = NULL ;
} else if ( ( F_14 ( V_28 -> V_43 ) - 1 ) * ( V_50 ) sizeof( * V_30 ) < V_36 )
V_40 = NULL ;
else
V_40 = ( V_45 * ) V_30 ;
goto V_47;
}
V_39 = ( T_1 * ) V_30 - 1 ;
V_41 = ( V_45 * ) ( ( char * ) V_10 + F_13 ( * V_39 ) ) ;
if ( F_13 ( V_41 -> V_48 ) == V_49 ) {
V_40 = ( V_45 * )
( ( char * ) V_10 + F_13 ( V_38 [ 0 ] . V_46 ) ) ;
if ( V_40 != V_41 ) {
if ( F_13 ( V_40 -> V_44 ) < V_36 )
V_40 = NULL ;
goto V_47;
}
if ( F_13 ( V_40 -> V_44 ) < V_36 + ( V_50 ) sizeof( * V_30 ) ) {
if ( F_13 ( V_38 [ 1 ] . V_44 ) >= V_36 )
V_40 = ( V_45 * )
( ( char * ) V_10 + F_13 ( V_38 [ 1 ] . V_46 ) ) ;
else
V_40 = NULL ;
}
}
V_47:
* V_31 = V_39 ;
* V_33 = V_40 ;
* V_34 = V_41 ;
}
static void
F_15 (
struct V_18 * V_19 ,
struct V_3 * V_4 ,
struct V_9 * V_10 ,
struct V_27 * V_28 ,
struct V_29 * V_30 ,
int * V_51 ,
int * V_52 ,
int * V_53 )
{
int V_54 ;
int V_55 ;
int V_56 = 0 ;
int V_57 ;
V_54 = V_55 = F_14 ( V_28 -> V_58 ) - 1 ;
V_57 = * V_52 = - 1 ;
for (; V_54 >= 0 ; V_54 -- ) {
if ( V_30 [ V_54 ] . V_59 == F_4 ( V_60 ) ) {
if ( V_57 == - 1 )
V_57 = V_55 ;
else {
if ( * V_52 == - 1 )
* V_52 = V_55 ;
continue;
}
}
if ( V_54 < V_55 )
V_30 [ V_55 ] = V_30 [ V_54 ] ;
V_55 -- ;
}
* V_53 = V_55 + 1 - ( F_14 ( V_28 -> V_43 ) - 1 ) ;
* V_52 -= F_14 ( V_28 -> V_43 ) - 1 ;
F_16 ( & V_28 -> V_58 , - ( F_14 ( V_28 -> V_43 ) - 1 ) ) ;
F_17 ( V_19 , V_4 ,
( V_61 ) ( ( char * ) V_30 - ( char * ) V_10 ) ,
( V_61 ) ( ( F_14 ( V_28 -> V_43 ) - 1 ) * sizeof( * V_30 ) ) ,
V_51 , & V_56 ) ;
V_30 += F_14 ( V_28 -> V_43 ) - 1 ;
V_28 -> V_43 = F_4 ( 1 ) ;
if ( V_56 )
F_18 ( V_19 -> V_62 , V_10 , V_51 ) ;
}
int
F_19 (
T_2 * args )
{
T_3 * V_10 ;
T_4 * V_30 ;
struct V_3 * V_4 ;
T_5 * V_28 ;
int V_35 ;
T_6 * V_63 ;
T_7 * V_21 ;
V_45 * V_40 ;
int error ;
V_45 * V_41 = NULL ;
T_8 V_64 ;
int V_65 ;
int V_57 ;
int V_52 = 0 ;
int V_53 = 0 ;
int V_36 ;
int V_66 ;
int V_67 ;
int V_68 = 0 ;
T_9 * V_6 ;
int V_51 ;
int V_56 ;
T_1 * V_39 ;
T_10 * V_19 ;
F_20 ( args ) ;
V_21 = args -> V_21 ;
V_19 = args -> V_69 ;
V_6 = V_21 -> V_23 ;
error = F_10 ( V_19 , V_21 , & V_4 ) ;
if ( error )
return error ;
V_36 = F_21 ( args -> V_70 ) ;
V_10 = V_4 -> V_11 ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_30 = F_23 ( V_28 ) ;
F_12 ( V_10 , V_28 , V_30 , & V_39 , & V_40 ,
& V_41 , & V_35 , V_36 ) ;
if ( args -> V_71 & V_72 ) {
F_24 ( V_19 , V_4 ) ;
if ( ! V_40 )
return F_25 ( V_73 ) ;
return 0 ;
}
if ( ! V_40 ) {
if ( args -> V_74 == 0 )
return F_25 ( V_73 ) ;
error = F_26 ( args , V_4 ) ;
if ( error )
return error ;
return F_27 ( args ) ;
}
V_51 = V_56 = 0 ;
if ( V_35 ) {
F_15 ( V_19 , V_4 , V_10 , V_28 , V_30 , & V_51 ,
& V_52 , & V_53 ) ;
V_30 = F_23 ( V_28 ) ;
} else if ( V_28 -> V_43 ) {
V_53 = F_14 ( V_28 -> V_58 ) ;
V_52 = - 1 ;
}
for ( V_66 = 0 , V_65 = F_14 ( V_28 -> V_58 ) - 1 ; V_66 <= V_65 ; ) {
V_68 = ( V_66 + V_65 ) >> 1 ;
if ( ( V_64 = F_14 ( V_30 [ V_68 ] . V_75 ) ) == args -> V_75 )
break;
if ( V_64 < args -> V_75 )
V_66 = V_68 + 1 ;
else
V_65 = V_68 - 1 ;
}
while ( V_68 >= 0 && F_14 ( V_30 [ V_68 ] . V_75 ) >= args -> V_75 ) {
V_68 -- ;
}
if ( ! V_28 -> V_43 ) {
F_28 ( V_19 , V_4 , V_41 ,
( V_61 )
( ( char * ) V_41 - ( char * ) V_10 + F_13 ( V_41 -> V_44 ) -
sizeof( * V_30 ) ) ,
( V_61 ) sizeof( * V_30 ) ,
& V_51 , & V_56 ) ;
F_16 ( & V_28 -> V_58 , 1 ) ;
if ( V_56 ) {
F_18 ( V_6 , V_10 , & V_51 ) ;
V_56 = 0 ;
}
V_30 -- ;
V_68 ++ ;
if ( V_68 )
memmove ( V_30 , & V_30 [ 1 ] , V_68 * sizeof( * V_30 ) ) ;
V_53 = 0 ;
V_52 = V_68 ;
}
else {
for ( V_67 = V_68 ;
V_67 >= 0 &&
V_30 [ V_67 ] . V_59 !=
F_4 ( V_60 ) ;
V_67 -- )
continue;
for ( V_57 = V_68 + 1 ;
V_57 < F_14 ( V_28 -> V_58 ) &&
V_30 [ V_57 ] . V_59 !=
F_4 ( V_60 ) &&
( V_67 < 0 || V_68 - V_67 > V_57 - V_68 ) ;
V_57 ++ )
continue;
if ( V_67 >= 0 &&
( V_57 == F_14 ( V_28 -> V_58 ) ||
V_68 - V_67 <= V_57 - V_68 ) ) {
if ( V_68 - V_67 )
memmove ( & V_30 [ V_67 ] , & V_30 [ V_67 + 1 ] ,
( V_68 - V_67 ) * sizeof( * V_30 ) ) ;
V_53 = F_29 ( V_67 , V_53 ) ;
V_52 = F_30 ( V_68 , V_52 ) ;
}
else {
ASSERT ( V_57 < F_14 ( V_28 -> V_58 ) ) ;
V_68 ++ ;
if ( V_57 - V_68 )
memmove ( & V_30 [ V_68 + 1 ] , & V_30 [ V_68 ] ,
( V_57 - V_68 ) * sizeof( * V_30 ) ) ;
V_53 = F_29 ( V_68 , V_53 ) ;
V_52 = F_30 ( V_57 , V_52 ) ;
}
F_16 ( & V_28 -> V_43 , - 1 ) ;
}
V_63 = ( T_6 * ) V_40 ;
V_30 [ V_68 ] . V_75 = F_4 ( args -> V_75 ) ;
V_30 [ V_68 ] . V_59 = F_4 ( F_31 ( V_6 ,
( char * ) V_63 - ( char * ) V_10 ) ) ;
F_32 ( V_19 , V_4 , V_53 , V_52 ) ;
F_28 ( V_19 , V_4 , V_40 ,
( V_61 ) ( ( char * ) V_40 - ( char * ) V_10 ) ,
( V_61 ) V_36 , & V_51 , & V_56 ) ;
V_63 -> V_76 = F_33 ( args -> V_76 ) ;
V_63 -> V_70 = args -> V_70 ;
memcpy ( V_63 -> V_77 , args -> V_77 , args -> V_70 ) ;
V_39 = F_34 ( V_63 ) ;
* V_39 = F_35 ( ( char * ) V_63 - ( char * ) V_10 ) ;
if ( V_56 )
F_18 ( V_6 , V_10 , & V_51 ) ;
if ( V_51 )
F_36 ( V_19 , V_4 ) ;
F_37 ( V_19 , V_4 ) ;
F_38 ( V_19 , V_4 , V_63 ) ;
F_39 ( V_21 , V_4 ) ;
return 0 ;
}
int
F_40 (
T_7 * V_21 ,
void * V_78 ,
T_11 * V_46 ,
T_12 V_79 )
{
T_3 * V_10 ;
struct V_3 * V_4 ;
T_5 * V_28 ;
T_6 * V_63 ;
V_45 * V_40 ;
char * V_80 ;
int error ;
T_9 * V_6 ;
char * V_81 ;
int V_82 ;
T_11 V_83 ;
V_6 = V_21 -> V_23 ;
if ( F_41 ( V_6 , * V_46 ) > V_6 -> V_24 )
return 0 ;
error = F_10 ( NULL , V_21 , & V_4 ) ;
if ( error )
return error ;
V_82 = F_42 ( V_6 , * V_46 ) ;
V_10 = V_4 -> V_11 ;
F_39 ( V_21 , V_4 ) ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_81 = ( char * ) ( V_10 + 1 ) ;
V_80 = ( char * ) F_23 ( V_28 ) ;
while ( V_81 < V_80 ) {
V_40 = ( V_45 * ) V_81 ;
if ( F_13 ( V_40 -> V_48 ) == V_49 ) {
V_81 += F_13 ( V_40 -> V_44 ) ;
continue;
}
V_63 = ( T_6 * ) V_81 ;
V_81 += F_21 ( V_63 -> V_70 ) ;
if ( ( char * ) V_63 - ( char * ) V_10 < V_82 )
continue;
V_83 = F_43 ( V_6 , V_6 -> V_24 ,
( char * ) V_63 - ( char * ) V_10 ) ;
if ( V_79 ( V_78 , ( char * ) V_63 -> V_77 , V_63 -> V_70 ,
V_83 & 0x7fffffff , F_44 ( V_63 -> V_76 ) ,
V_84 ) ) {
* V_46 = V_83 & 0x7fffffff ;
F_24 ( NULL , V_4 ) ;
return 0 ;
}
}
* V_46 = F_43 ( V_6 , V_6 -> V_24 + 1 , 0 ) &
0x7fffffff ;
F_24 ( NULL , V_4 ) ;
return 0 ;
}
static void
F_32 (
T_10 * V_19 ,
struct V_3 * V_4 ,
int V_85 ,
int V_86 )
{
T_3 * V_10 = V_4 -> V_11 ;
T_4 * V_30 ;
T_5 * V_28 ;
V_28 = F_22 ( V_19 -> V_62 , V_10 ) ;
V_30 = F_23 ( V_28 ) ;
F_45 ( V_19 , V_4 , ( V_50 ) ( ( char * ) & V_30 [ V_85 ] - ( char * ) V_10 ) ,
( V_50 ) ( ( char * ) & V_30 [ V_86 + 1 ] - ( char * ) V_10 - 1 ) ) ;
}
static void
F_37 (
T_10 * V_19 ,
struct V_3 * V_4 )
{
T_3 * V_10 = V_4 -> V_11 ;
T_5 * V_28 ;
V_28 = F_22 ( V_19 -> V_62 , V_10 ) ;
F_45 ( V_19 , V_4 , ( V_50 ) ( ( char * ) V_28 - ( char * ) V_10 ) ,
( V_50 ) ( ( char * ) ( V_28 + 1 ) - ( char * ) V_10 - 1 ) ) ;
}
int
F_46 (
T_2 * args )
{
T_3 * V_10 ;
T_4 * V_30 ;
struct V_3 * V_4 ;
T_5 * V_28 ;
T_6 * V_63 ;
T_7 * V_21 ;
int V_87 ;
int error ;
T_9 * V_6 ;
F_47 ( args ) ;
if ( ( error = F_48 ( args , & V_4 , & V_87 ) ) )
return error ;
V_21 = args -> V_21 ;
V_6 = V_21 -> V_23 ;
V_10 = V_4 -> V_11 ;
F_39 ( V_21 , V_4 ) ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_30 = F_23 ( V_28 ) ;
V_63 = ( T_6 * ) ( ( char * ) V_10 +
F_42 ( V_6 , F_14 ( V_30 [ V_87 ] . V_59 ) ) ) ;
args -> V_76 = F_44 ( V_63 -> V_76 ) ;
error = F_49 ( args , V_63 -> V_77 , V_63 -> V_70 ) ;
F_24 ( args -> V_69 , V_4 ) ;
return F_25 ( error ) ;
}
static int
F_48 (
T_2 * args ,
struct V_3 * * V_22 ,
int * V_88 )
{
T_13 V_89 ;
T_3 * V_10 ;
T_4 * V_30 ;
struct V_3 * V_4 ;
T_5 * V_28 ;
T_6 * V_63 ;
T_7 * V_21 ;
int error ;
T_8 V_64 ;
int V_65 ;
int V_66 ;
int V_68 ;
T_9 * V_6 ;
T_10 * V_19 ;
enum V_90 V_91 ;
V_21 = args -> V_21 ;
V_19 = args -> V_69 ;
V_6 = V_21 -> V_23 ;
error = F_10 ( V_19 , V_21 , & V_4 ) ;
if ( error )
return error ;
V_10 = V_4 -> V_11 ;
F_39 ( V_21 , V_4 ) ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_30 = F_23 ( V_28 ) ;
for ( V_66 = 0 , V_65 = F_14 ( V_28 -> V_58 ) - 1 ; ; ) {
ASSERT ( V_66 <= V_65 ) ;
V_68 = ( V_66 + V_65 ) >> 1 ;
if ( ( V_64 = F_14 ( V_30 [ V_68 ] . V_75 ) ) == args -> V_75 )
break;
if ( V_64 < args -> V_75 )
V_66 = V_68 + 1 ;
else
V_65 = V_68 - 1 ;
if ( V_66 > V_65 ) {
ASSERT ( args -> V_71 & V_92 ) ;
F_24 ( V_19 , V_4 ) ;
return F_25 ( V_93 ) ;
}
}
while ( V_68 > 0 && F_14 ( V_30 [ V_68 - 1 ] . V_75 ) == args -> V_75 ) {
V_68 -- ;
}
do {
if ( ( V_89 = F_14 ( V_30 [ V_68 ] . V_59 ) ) == V_60 )
continue;
V_63 = ( T_6 * )
( ( char * ) V_10 + F_42 ( V_6 , V_89 ) ) ;
V_91 = V_6 -> V_94 -> V_95 ( args , V_63 -> V_77 , V_63 -> V_70 ) ;
if ( V_91 != V_96 && V_91 != args -> V_97 ) {
args -> V_97 = V_91 ;
* V_22 = V_4 ;
* V_88 = V_68 ;
if ( V_91 == V_98 )
return 0 ;
}
} while ( ++ V_68 < F_14 ( V_28 -> V_58 ) &&
F_14 ( V_30 [ V_68 ] . V_75 ) == V_64 );
ASSERT ( args -> V_71 & V_92 ) ;
if ( args -> V_97 == V_99 )
return 0 ;
F_24 ( V_19 , V_4 ) ;
return F_25 ( V_93 ) ;
}
int
F_50 (
T_2 * args )
{
T_3 * V_10 ;
T_4 * V_30 ;
struct V_3 * V_4 ;
T_5 * V_28 ;
T_6 * V_63 ;
T_7 * V_21 ;
int V_87 ;
int error ;
T_9 * V_6 ;
int V_51 ;
int V_56 ;
T_14 V_100 ;
int V_101 ;
T_10 * V_19 ;
F_51 ( args ) ;
if ( ( error = F_48 ( args , & V_4 , & V_87 ) ) ) {
return error ;
}
V_21 = args -> V_21 ;
V_19 = args -> V_69 ;
V_6 = V_21 -> V_23 ;
V_10 = V_4 -> V_11 ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_30 = F_23 ( V_28 ) ;
V_63 = ( T_6 * )
( ( char * ) V_10 + F_42 ( V_6 , F_14 ( V_30 [ V_87 ] . V_59 ) ) ) ;
V_51 = V_56 = 0 ;
F_17 ( V_19 , V_4 ,
( V_61 ) ( ( char * ) V_63 - ( char * ) V_10 ) ,
F_21 ( V_63 -> V_70 ) , & V_51 , & V_56 ) ;
F_16 ( & V_28 -> V_43 , 1 ) ;
F_37 ( V_19 , V_4 ) ;
V_30 [ V_87 ] . V_59 = F_4 ( V_60 ) ;
F_32 ( V_19 , V_4 , V_87 , V_87 ) ;
if ( V_56 )
F_18 ( V_6 , V_10 , & V_51 ) ;
if ( V_51 )
F_36 ( V_19 , V_4 ) ;
F_39 ( V_21 , V_4 ) ;
V_101 = F_52 ( V_21 , V_10 , & V_100 ) ;
if ( V_101 > F_53 ( V_21 ) )
return 0 ;
return F_54 ( args , V_4 , V_101 , & V_100 ) ;
}
int
F_55 (
T_2 * args )
{
T_3 * V_10 ;
T_4 * V_30 ;
struct V_3 * V_4 ;
T_5 * V_28 ;
T_6 * V_63 ;
T_7 * V_21 ;
int V_87 ;
int error ;
T_9 * V_6 ;
F_56 ( args ) ;
if ( ( error = F_48 ( args , & V_4 , & V_87 ) ) ) {
return error ;
}
V_21 = args -> V_21 ;
V_6 = V_21 -> V_23 ;
V_10 = V_4 -> V_11 ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_30 = F_23 ( V_28 ) ;
V_63 = ( T_6 * )
( ( char * ) V_10 + F_42 ( V_6 , F_14 ( V_30 [ V_87 ] . V_59 ) ) ) ;
ASSERT ( F_44 ( V_63 -> V_76 ) != args -> V_76 ) ;
V_63 -> V_76 = F_33 ( args -> V_76 ) ;
F_38 ( args -> V_69 , V_4 , V_63 ) ;
F_39 ( V_21 , V_4 ) ;
return 0 ;
}
static int
F_57 (
const void * V_102 ,
const void * V_103 )
{
const T_4 * V_104 ;
const T_4 * V_105 ;
V_104 = V_102 ;
V_105 = V_103 ;
return F_14 ( V_104 -> V_75 ) < F_14 ( V_105 -> V_75 ) ? - 1 :
( F_14 ( V_104 -> V_75 ) > F_14 ( V_105 -> V_75 ) ? 1 : 0 ) ;
}
int
F_58 (
T_2 * args ,
struct V_3 * V_106 ,
struct V_3 * V_107 )
{
T_1 * V_108 ;
T_3 * V_10 ;
T_5 * V_28 ;
T_7 * V_21 ;
V_45 * V_40 ;
int error ;
int V_109 ;
T_15 * V_110 ;
T_4 * V_111 ;
T_16 * V_112 ;
T_9 * V_6 ;
int V_51 ;
int V_56 ;
T_14 V_100 ;
int V_101 ;
T_1 * V_39 ;
int V_113 ;
T_10 * V_19 ;
F_59 ( args ) ;
V_21 = args -> V_21 ;
V_19 = args -> V_69 ;
V_6 = V_21 -> V_23 ;
V_110 = V_106 -> V_11 ;
ASSERT ( V_110 -> V_10 . V_114 . V_13 == F_35 ( V_115 ) ) ;
V_112 = F_60 ( V_6 , V_110 ) ;
while ( V_21 -> V_116 . V_117 > V_6 -> V_118 ) {
V_108 = F_61 ( V_112 ) ;
if ( F_13 ( V_108 [ F_14 ( V_112 -> V_119 ) - 1 ] ) ==
V_6 -> V_118 - ( V_50 ) sizeof( * V_10 ) ) {
if ( ( error =
F_62 ( args , V_106 ,
( V_120 ) ( F_14 ( V_112 -> V_119 ) - 1 ) ) ) )
return error ;
} else
return 0 ;
}
if ( ! V_107 ) {
error = F_63 ( V_19 , V_21 , V_6 -> V_24 , - 1 , & V_107 ) ;
if ( error )
return error ;
}
V_10 = V_107 -> V_11 ;
ASSERT ( V_10 -> V_13 == F_4 ( V_121 ) ) ;
V_101 = ( V_50 ) sizeof( T_5 ) +
( V_50 ) sizeof( * V_111 ) * ( F_13 ( V_110 -> V_10 . V_58 ) - F_13 ( V_110 -> V_10 . V_43 ) ) ;
V_39 = ( T_1 * ) ( ( char * ) V_10 + V_6 -> V_118 ) - 1 ;
V_40 = ( V_45 * ) ( ( char * ) V_10 + F_13 ( * V_39 ) ) ;
if ( F_13 ( V_40 -> V_48 ) != V_49 ||
F_13 ( V_40 -> V_44 ) < V_101 )
return 0 ;
V_107 -> V_122 = & V_26 ;
V_10 -> V_13 = F_4 ( V_14 ) ;
V_51 = 1 ;
V_56 = 0 ;
F_28 ( V_19 , V_107 , V_40 , V_6 -> V_118 - V_101 , V_101 ,
& V_51 , & V_56 ) ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_28 -> V_58 = F_4 ( F_13 ( V_110 -> V_10 . V_58 ) - F_13 ( V_110 -> V_10 . V_43 ) ) ;
V_28 -> V_43 = 0 ;
F_37 ( V_19 , V_107 ) ;
V_111 = F_23 ( V_28 ) ;
for ( V_109 = V_113 = 0 ; V_109 < F_13 ( V_110 -> V_10 . V_58 ) ; V_109 ++ ) {
if ( V_110 -> V_123 [ V_109 ] . V_59 ==
F_4 ( V_60 ) )
continue;
V_111 [ V_113 ++ ] = V_110 -> V_123 [ V_109 ] ;
}
ASSERT ( V_113 == F_14 ( V_28 -> V_58 ) ) ;
F_32 ( V_19 , V_107 , 0 , F_14 ( V_28 -> V_58 ) - 1 ) ;
if ( V_56 )
F_18 ( V_6 , V_10 , & V_51 ) ;
if ( V_51 )
F_36 ( V_19 , V_107 ) ;
error = F_64 ( args , V_6 -> V_124 , V_106 ) ;
if ( error )
return error ;
V_101 = F_52 ( V_21 , V_10 , & V_100 ) ;
if ( V_101 > F_53 ( V_21 ) )
return 0 ;
return F_54 ( args , V_107 , V_101 , & V_100 ) ;
}
int
F_65 (
T_2 * args )
{
V_120 V_125 ;
T_3 * V_10 ;
T_4 * V_30 ;
struct V_3 * V_4 ;
T_5 * V_28 ;
T_6 * V_63 ;
T_7 * V_21 ;
int V_126 ;
V_45 * V_40 ;
int V_127 ;
int error ;
int V_128 ;
T_9 * V_6 ;
int V_51 ;
int V_56 ;
int V_129 ;
int V_46 ;
T_17 * V_130 ;
T_14 * V_131 ;
T_14 * V_132 ;
T_1 * V_39 ;
T_10 * V_19 ;
struct V_133 V_77 ;
F_66 ( args ) ;
V_21 = args -> V_21 ;
V_19 = args -> V_69 ;
V_6 = V_21 -> V_23 ;
ASSERT ( V_21 -> V_134 . V_135 & V_136 ) ;
if ( V_21 -> V_116 . V_117 < F_67 ( T_14 , V_137 ) ) {
ASSERT ( F_68 ( V_6 ) ) ;
return F_25 ( V_138 ) ;
}
V_131 = ( T_14 * ) V_21 -> V_134 . V_139 . V_140 ;
ASSERT ( V_21 -> V_134 . V_141 == V_21 -> V_116 . V_117 ) ;
ASSERT ( V_21 -> V_134 . V_139 . V_140 != NULL ) ;
ASSERT ( V_21 -> V_116 . V_117 >= F_69 ( V_131 -> V_142 ) ) ;
V_132 = F_70 ( V_21 -> V_134 . V_141 , V_143 ) ;
memcpy ( V_132 , V_131 , V_21 -> V_134 . V_141 ) ;
F_71 ( V_21 , - V_21 -> V_134 . V_141 , V_25 ) ;
V_21 -> V_116 . V_117 = 0 ;
F_72 ( V_19 , V_21 , V_144 ) ;
error = F_73 ( args , V_145 , & V_125 ) ;
if ( error ) {
F_74 ( V_132 ) ;
return error ;
}
error = F_75 ( args , V_125 , & V_4 ) ;
if ( error ) {
F_74 ( V_132 ) ;
return error ;
}
V_4 -> V_122 = & V_26 ;
V_10 = V_4 -> V_11 ;
V_10 -> V_13 = F_4 ( V_14 ) ;
V_128 = ( V_50 ) sizeof( * V_28 ) +
( V_132 -> V_58 + 2 ) * ( V_50 ) sizeof( T_4 ) ;
V_40 = ( V_45 * ) ( V_10 + 1 ) ;
V_51 = V_56 = 0 ;
F_28 ( V_19 , V_4 , V_40 , V_6 -> V_118 - V_128 , V_128 , & V_51 ,
& V_56 ) ;
ASSERT ( V_56 == 0 ) ;
V_28 = F_22 ( V_6 , V_10 ) ;
V_28 -> V_58 = F_4 ( V_132 -> V_58 + 2 ) ;
V_28 -> V_43 = 0 ;
V_30 = F_23 ( V_28 ) ;
V_127 = ( V_50 ) ( ( char * ) V_30 - ( char * ) V_10 ) ;
F_28 ( V_19 , V_4 , V_40 ,
( V_61 ) ( ( char * ) V_40 - ( char * ) V_10 ) ,
F_13 ( V_40 -> V_44 ) , & V_51 , & V_56 ) ;
V_63 = ( T_6 * )
( ( char * ) V_10 + V_146 ) ;
V_63 -> V_76 = F_33 ( V_21 -> V_147 ) ;
V_63 -> V_70 = 1 ;
V_63 -> V_77 [ 0 ] = '.' ;
V_39 = F_34 ( V_63 ) ;
* V_39 = F_35 ( ( char * ) V_63 - ( char * ) V_10 ) ;
F_38 ( V_19 , V_4 , V_63 ) ;
V_30 [ 0 ] . V_75 = F_4 ( V_1 ) ;
V_30 [ 0 ] . V_59 = F_4 ( F_31 ( V_6 ,
( char * ) V_63 - ( char * ) V_10 ) ) ;
V_63 = ( T_6 * )
( ( char * ) V_10 + V_148 ) ;
V_63 -> V_76 = F_33 ( F_76 ( V_132 ) ) ;
V_63 -> V_70 = 2 ;
V_63 -> V_77 [ 0 ] = V_63 -> V_77 [ 1 ] = '.' ;
V_39 = F_34 ( V_63 ) ;
* V_39 = F_35 ( ( char * ) V_63 - ( char * ) V_10 ) ;
F_38 ( V_19 , V_4 , V_63 ) ;
V_30 [ 1 ] . V_75 = F_4 ( V_2 ) ;
V_30 [ 1 ] . V_59 = F_4 ( F_31 ( V_6 ,
( char * ) V_63 - ( char * ) V_10 ) ) ;
V_46 = V_149 ;
V_128 = 0 ;
if ( ! V_132 -> V_58 )
V_130 = NULL ;
else
V_130 = F_77 ( V_132 ) ;
while ( V_46 < V_127 ) {
if ( V_130 == NULL )
V_129 = V_127 ;
else
V_129 = F_78 ( V_130 ) ;
if ( V_46 < V_129 ) {
V_40 = ( V_45 * ) ( ( char * ) V_10 + V_46 ) ;
V_40 -> V_48 = F_35 ( V_49 ) ;
V_40 -> V_44 = F_35 ( V_129 - V_46 ) ;
* F_79 ( V_40 ) = F_35 (
( ( char * ) V_40 - ( char * ) V_10 ) ) ;
F_80 ( V_19 , V_4 , V_40 ) ;
F_81 ( V_10 , V_40 , & V_126 ) ;
V_46 += F_13 ( V_40 -> V_44 ) ;
continue;
}
V_63 = ( T_6 * ) ( ( char * ) V_10 + V_129 ) ;
V_63 -> V_76 = F_33 ( F_82 ( V_132 , V_130 ) ) ;
V_63 -> V_70 = V_130 -> V_70 ;
memcpy ( V_63 -> V_77 , V_130 -> V_77 , V_63 -> V_70 ) ;
V_39 = F_34 ( V_63 ) ;
* V_39 = F_35 ( ( char * ) V_63 - ( char * ) V_10 ) ;
F_38 ( V_19 , V_4 , V_63 ) ;
V_77 . V_77 = V_130 -> V_77 ;
V_77 . V_36 = V_130 -> V_70 ;
V_30 [ 2 + V_128 ] . V_75 = F_4 ( V_6 -> V_94 ->
V_150 ( & V_77 ) ) ;
V_30 [ 2 + V_128 ] . V_59 = F_4 ( F_31 ( V_6 ,
( char * ) V_63 - ( char * ) V_10 ) ) ;
V_46 = ( int ) ( ( char * ) ( V_39 + 1 ) - ( char * ) V_10 ) ;
if ( ++ V_128 == V_132 -> V_58 )
V_130 = NULL ;
else
V_130 = F_83 ( V_132 , V_130 ) ;
}
F_74 ( V_132 ) ;
F_84 ( V_30 , F_14 ( V_28 -> V_58 ) , sizeof( * V_30 ) , F_57 ) ;
ASSERT ( V_56 == 0 ) ;
F_32 ( V_19 , V_4 , 0 , F_14 ( V_28 -> V_58 ) - 1 ) ;
F_37 ( V_19 , V_4 ) ;
F_39 ( V_21 , V_4 ) ;
return 0 ;
}
