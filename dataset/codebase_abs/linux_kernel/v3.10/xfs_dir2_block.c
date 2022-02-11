void
F_1 ( void )
{
V_1 = F_2 ( ( unsigned char * ) L_1 , 1 ) ;
V_2 = F_2 ( ( unsigned char * ) L_2 , 2 ) ;
}
static bool
F_3 (
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_11 ;
if ( F_4 ( & V_6 -> V_12 ) ) {
if ( V_10 -> V_13 != F_5 ( V_14 ) )
return false ;
if ( ! F_6 ( & V_10 -> V_15 , & V_6 -> V_12 . V_16 ) )
return false ;
if ( F_7 ( V_10 -> V_17 ) != V_4 -> V_18 )
return false ;
} else {
if ( V_10 -> V_13 != F_5 ( V_19 ) )
return false ;
}
if ( F_8 ( NULL , V_4 ) )
return false ;
return true ;
}
static void
F_9 (
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
if ( ( F_4 ( & V_6 -> V_12 ) &&
! F_10 ( V_4 -> V_11 , F_11 ( V_4 -> V_20 ) ,
V_21 ) ) ||
! F_3 ( V_4 ) ) {
F_12 ( V_22 , V_23 , V_6 , V_4 -> V_11 ) ;
F_13 ( V_4 , V_24 ) ;
}
}
static void
F_14 (
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_25 * V_26 = V_4 -> V_27 ;
struct V_9 * V_10 = V_4 -> V_11 ;
if ( ! F_3 ( V_4 ) ) {
F_12 ( V_22 , V_23 , V_6 , V_4 -> V_11 ) ;
F_13 ( V_4 , V_24 ) ;
return;
}
if ( ! F_4 ( & V_6 -> V_12 ) )
return;
if ( V_26 )
V_10 -> V_28 = F_15 ( V_26 -> V_29 . V_30 ) ;
F_16 ( V_4 -> V_11 , F_11 ( V_4 -> V_20 ) , V_21 ) ;
}
static int
F_17 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_3 * * V_35 )
{
struct V_5 * V_6 = V_34 -> V_36 ;
int V_37 ;
V_37 = F_18 ( V_32 , V_34 , V_6 -> V_38 , - 1 , V_35 ,
V_39 , & V_40 ) ;
if ( ! V_37 && V_32 )
F_19 ( V_32 , * V_35 , V_41 ) ;
return V_37 ;
}
static void
F_20 (
struct V_5 * V_6 ,
struct V_31 * V_32 ,
struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_9 * V_10 = V_4 -> V_11 ;
V_4 -> V_42 = & V_40 ;
F_19 ( V_32 , V_4 , V_41 ) ;
if ( F_4 ( & V_6 -> V_12 ) ) {
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_13 = F_5 ( V_14 ) ;
V_10 -> V_17 = F_15 ( V_4 -> V_18 ) ;
V_10 -> V_43 = F_15 ( V_34 -> V_44 ) ;
F_21 ( & V_10 -> V_15 , & V_6 -> V_12 . V_16 ) ;
return;
}
V_10 -> V_13 = F_5 ( V_19 ) ;
}
static void
F_22 (
struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_50 ,
T_1 * * V_51 ,
struct V_52 * * V_53 ,
struct V_52 * * V_54 ,
int * V_55 ,
int V_56 )
{
struct V_57 * V_58 ;
T_1 * V_59 = NULL ;
struct V_52 * V_60 = NULL ;
struct V_52 * V_61 = NULL ;
* V_55 = 0 ;
V_58 = F_23 ( V_46 ) ;
if ( V_48 -> V_62 ) {
if ( F_24 ( V_58 [ 0 ] . V_63 ) >= V_56 ) {
V_60 = ( V_64 * )
( ( char * ) V_46 + F_24 ( V_58 [ 0 ] . V_65 ) ) ;
goto V_66;
}
* V_55 = 1 ;
V_59 = ( T_1 * ) V_50 - 1 ;
V_60 = ( V_64 * ) ( ( char * ) V_46 + F_24 ( * V_59 ) ) ;
if ( F_24 ( V_60 -> V_67 ) == V_68 ) {
if ( F_24 ( V_60 -> V_63 ) + ( F_25 ( V_48 -> V_62 ) - 1 ) *
( V_69 ) sizeof( * V_50 ) < V_56 )
V_60 = NULL ;
} else if ( ( F_25 ( V_48 -> V_62 ) - 1 ) * ( V_69 ) sizeof( * V_50 ) < V_56 )
V_60 = NULL ;
else
V_60 = ( V_64 * ) V_50 ;
goto V_66;
}
V_59 = ( T_1 * ) V_50 - 1 ;
V_61 = ( V_64 * ) ( ( char * ) V_46 + F_24 ( * V_59 ) ) ;
if ( F_24 ( V_61 -> V_67 ) == V_68 ) {
V_60 = ( V_64 * )
( ( char * ) V_46 + F_24 ( V_58 [ 0 ] . V_65 ) ) ;
if ( V_60 != V_61 ) {
if ( F_24 ( V_60 -> V_63 ) < V_56 )
V_60 = NULL ;
goto V_66;
}
if ( F_24 ( V_60 -> V_63 ) < V_56 + ( V_69 ) sizeof( * V_50 ) ) {
if ( F_24 ( V_58 [ 1 ] . V_63 ) >= V_56 )
V_60 = ( V_64 * )
( ( char * ) V_46 + F_24 ( V_58 [ 1 ] . V_65 ) ) ;
else
V_60 = NULL ;
}
}
V_66:
* V_51 = V_59 ;
* V_53 = V_60 ;
* V_54 = V_61 ;
}
static void
F_26 (
struct V_31 * V_32 ,
struct V_3 * V_4 ,
struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_50 ,
int * V_70 ,
int * V_71 ,
int * V_72 )
{
int V_73 ;
int V_74 ;
int V_75 = 0 ;
int V_76 ;
V_73 = V_74 = F_25 ( V_48 -> V_77 ) - 1 ;
V_76 = * V_71 = - 1 ;
for (; V_73 >= 0 ; V_73 -- ) {
if ( V_50 [ V_73 ] . V_78 == F_5 ( V_79 ) ) {
if ( V_76 == - 1 )
V_76 = V_74 ;
else {
if ( * V_71 == - 1 )
* V_71 = V_74 ;
continue;
}
}
if ( V_73 < V_74 )
V_50 [ V_74 ] = V_50 [ V_73 ] ;
V_74 -- ;
}
* V_72 = V_74 + 1 - ( F_25 ( V_48 -> V_62 ) - 1 ) ;
* V_71 -= F_25 ( V_48 -> V_62 ) - 1 ;
F_27 ( & V_48 -> V_77 , - ( F_25 ( V_48 -> V_62 ) - 1 ) ) ;
F_28 ( V_32 , V_4 ,
( V_80 ) ( ( char * ) V_50 - ( char * ) V_46 ) ,
( V_80 ) ( ( F_25 ( V_48 -> V_62 ) - 1 ) * sizeof( * V_50 ) ) ,
V_70 , & V_75 ) ;
V_50 += F_25 ( V_48 -> V_62 ) - 1 ;
V_48 -> V_62 = F_5 ( 1 ) ;
if ( V_75 )
F_29 ( V_32 -> V_81 , V_46 , V_70 ) ;
}
int
F_30 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
int V_55 ;
T_6 * V_82 ;
T_7 * V_34 ;
V_64 * V_60 ;
int error ;
V_64 * V_61 = NULL ;
T_8 V_83 ;
int V_84 ;
int V_76 ;
int V_71 = 0 ;
int V_72 = 0 ;
int V_56 ;
int V_85 ;
int V_86 ;
int V_87 = 0 ;
T_9 * V_6 ;
int V_70 ;
int V_75 ;
T_1 * V_59 ;
T_10 * V_32 ;
F_31 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
error = F_17 ( V_32 , V_34 , & V_4 ) ;
if ( error )
return error ;
V_56 = F_32 ( args -> V_89 ) ;
V_46 = V_4 -> V_11 ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
F_22 ( V_46 , V_48 , V_50 , & V_59 , & V_60 ,
& V_61 , & V_55 , V_56 ) ;
if ( args -> V_90 & V_91 ) {
F_35 ( V_32 , V_4 ) ;
if ( ! V_60 )
return F_36 ( V_92 ) ;
return 0 ;
}
if ( ! V_60 ) {
if ( args -> V_93 == 0 )
return F_36 ( V_92 ) ;
error = F_37 ( args , V_4 ) ;
if ( error )
return error ;
return F_38 ( args ) ;
}
V_70 = V_75 = 0 ;
if ( V_55 ) {
F_26 ( V_32 , V_4 , V_46 , V_48 , V_50 , & V_70 ,
& V_71 , & V_72 ) ;
V_50 = F_34 ( V_48 ) ;
} else if ( V_48 -> V_62 ) {
V_72 = F_25 ( V_48 -> V_77 ) ;
V_71 = - 1 ;
}
for ( V_85 = 0 , V_84 = F_25 ( V_48 -> V_77 ) - 1 ; V_85 <= V_84 ; ) {
V_87 = ( V_85 + V_84 ) >> 1 ;
if ( ( V_83 = F_25 ( V_50 [ V_87 ] . V_94 ) ) == args -> V_94 )
break;
if ( V_83 < args -> V_94 )
V_85 = V_87 + 1 ;
else
V_84 = V_87 - 1 ;
}
while ( V_87 >= 0 && F_25 ( V_50 [ V_87 ] . V_94 ) >= args -> V_94 ) {
V_87 -- ;
}
if ( ! V_48 -> V_62 ) {
F_39 ( V_32 , V_4 , V_61 ,
( V_80 )
( ( char * ) V_61 - ( char * ) V_46 + F_24 ( V_61 -> V_63 ) -
sizeof( * V_50 ) ) ,
( V_80 ) sizeof( * V_50 ) ,
& V_70 , & V_75 ) ;
F_27 ( & V_48 -> V_77 , 1 ) ;
if ( V_75 ) {
F_29 ( V_6 , V_46 , & V_70 ) ;
V_75 = 0 ;
}
V_50 -- ;
V_87 ++ ;
if ( V_87 )
memmove ( V_50 , & V_50 [ 1 ] , V_87 * sizeof( * V_50 ) ) ;
V_72 = 0 ;
V_71 = V_87 ;
}
else {
for ( V_86 = V_87 ;
V_86 >= 0 &&
V_50 [ V_86 ] . V_78 !=
F_5 ( V_79 ) ;
V_86 -- )
continue;
for ( V_76 = V_87 + 1 ;
V_76 < F_25 ( V_48 -> V_77 ) &&
V_50 [ V_76 ] . V_78 !=
F_5 ( V_79 ) &&
( V_86 < 0 || V_87 - V_86 > V_76 - V_87 ) ;
V_76 ++ )
continue;
if ( V_86 >= 0 &&
( V_76 == F_25 ( V_48 -> V_77 ) ||
V_87 - V_86 <= V_76 - V_87 ) ) {
if ( V_87 - V_86 )
memmove ( & V_50 [ V_86 ] , & V_50 [ V_86 + 1 ] ,
( V_87 - V_86 ) * sizeof( * V_50 ) ) ;
V_72 = F_40 ( V_86 , V_72 ) ;
V_71 = F_41 ( V_87 , V_71 ) ;
}
else {
ASSERT ( V_76 < F_25 ( V_48 -> V_77 ) ) ;
V_87 ++ ;
if ( V_76 - V_87 )
memmove ( & V_50 [ V_87 + 1 ] , & V_50 [ V_87 ] ,
( V_76 - V_87 ) * sizeof( * V_50 ) ) ;
V_72 = F_40 ( V_87 , V_72 ) ;
V_71 = F_41 ( V_76 , V_71 ) ;
}
F_27 ( & V_48 -> V_62 , - 1 ) ;
}
V_82 = ( T_6 * ) V_60 ;
V_50 [ V_87 ] . V_94 = F_5 ( args -> V_94 ) ;
V_50 [ V_87 ] . V_78 = F_5 ( F_42 ( V_6 ,
( char * ) V_82 - ( char * ) V_46 ) ) ;
F_43 ( V_32 , V_4 , V_72 , V_71 ) ;
F_39 ( V_32 , V_4 , V_60 ,
( V_80 ) ( ( char * ) V_60 - ( char * ) V_46 ) ,
( V_80 ) V_56 , & V_70 , & V_75 ) ;
V_82 -> V_95 = F_15 ( args -> V_95 ) ;
V_82 -> V_89 = args -> V_89 ;
memcpy ( V_82 -> V_96 , args -> V_96 , args -> V_89 ) ;
V_59 = F_44 ( V_82 ) ;
* V_59 = F_45 ( ( char * ) V_82 - ( char * ) V_46 ) ;
if ( V_75 )
F_29 ( V_6 , V_46 , & V_70 ) ;
if ( V_70 )
F_46 ( V_32 , V_4 ) ;
F_47 ( V_32 , V_4 ) ;
F_48 ( V_32 , V_4 , V_82 ) ;
F_49 ( V_34 , V_4 ) ;
return 0 ;
}
int
F_50 (
T_7 * V_34 ,
void * V_97 ,
T_11 * V_65 ,
T_12 V_98 )
{
T_3 * V_46 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
V_64 * V_60 ;
char * V_99 ;
int error ;
T_9 * V_6 ;
char * V_100 ;
int V_101 ;
T_11 V_102 ;
V_6 = V_34 -> V_36 ;
if ( F_51 ( V_6 , * V_65 ) > V_6 -> V_38 )
return 0 ;
error = F_17 ( NULL , V_34 , & V_4 ) ;
if ( error )
return error ;
V_101 = F_52 ( V_6 , * V_65 ) ;
V_46 = V_4 -> V_11 ;
F_49 ( V_34 , V_4 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_100 = ( char * ) F_53 ( V_46 ) ;
V_99 = ( char * ) F_34 ( V_48 ) ;
while ( V_100 < V_99 ) {
V_60 = ( V_64 * ) V_100 ;
if ( F_24 ( V_60 -> V_67 ) == V_68 ) {
V_100 += F_24 ( V_60 -> V_63 ) ;
continue;
}
V_82 = ( T_6 * ) V_100 ;
V_100 += F_32 ( V_82 -> V_89 ) ;
if ( ( char * ) V_82 - ( char * ) V_46 < V_101 )
continue;
V_102 = F_54 ( V_6 , V_6 -> V_38 ,
( char * ) V_82 - ( char * ) V_46 ) ;
if ( V_98 ( V_97 , ( char * ) V_82 -> V_96 , V_82 -> V_89 ,
V_102 & 0x7fffffff , F_7 ( V_82 -> V_95 ) ,
V_103 ) ) {
* V_65 = V_102 & 0x7fffffff ;
F_35 ( NULL , V_4 ) ;
return 0 ;
}
}
* V_65 = F_54 ( V_6 , V_6 -> V_38 + 1 , 0 ) &
0x7fffffff ;
F_35 ( NULL , V_4 ) ;
return 0 ;
}
static void
F_43 (
T_10 * V_32 ,
struct V_3 * V_4 ,
int V_104 ,
int V_105 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_4 * V_50 ;
T_5 * V_48 ;
V_48 = F_33 ( V_32 -> V_81 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
F_55 ( V_32 , V_4 , ( V_69 ) ( ( char * ) & V_50 [ V_104 ] - ( char * ) V_46 ) ,
( V_69 ) ( ( char * ) & V_50 [ V_105 + 1 ] - ( char * ) V_46 - 1 ) ) ;
}
static void
F_47 (
T_10 * V_32 ,
struct V_3 * V_4 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_5 * V_48 ;
V_48 = F_33 ( V_32 -> V_81 , V_46 ) ;
F_55 ( V_32 , V_4 , ( V_69 ) ( ( char * ) V_48 - ( char * ) V_46 ) ,
( V_69 ) ( ( char * ) ( V_48 + 1 ) - ( char * ) V_46 - 1 ) ) ;
}
int
F_56 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_106 ;
int error ;
T_9 * V_6 ;
F_57 ( args ) ;
if ( ( error = F_58 ( args , & V_4 , & V_106 ) ) )
return error ;
V_34 = args -> V_34 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
F_49 ( V_34 , V_4 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
V_82 = ( T_6 * ) ( ( char * ) V_46 +
F_52 ( V_6 , F_25 ( V_50 [ V_106 ] . V_78 ) ) ) ;
args -> V_95 = F_7 ( V_82 -> V_95 ) ;
error = F_59 ( args , V_82 -> V_96 , V_82 -> V_89 ) ;
F_35 ( args -> V_88 , V_4 ) ;
return F_36 ( error ) ;
}
static int
F_58 (
T_2 * args ,
struct V_3 * * V_35 ,
int * V_107 )
{
T_13 V_108 ;
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int error ;
T_8 V_83 ;
int V_84 ;
int V_85 ;
int V_87 ;
T_9 * V_6 ;
T_10 * V_32 ;
enum V_109 V_110 ;
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
error = F_17 ( V_32 , V_34 , & V_4 ) ;
if ( error )
return error ;
V_46 = V_4 -> V_11 ;
F_49 ( V_34 , V_4 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
for ( V_85 = 0 , V_84 = F_25 ( V_48 -> V_77 ) - 1 ; ; ) {
ASSERT ( V_85 <= V_84 ) ;
V_87 = ( V_85 + V_84 ) >> 1 ;
if ( ( V_83 = F_25 ( V_50 [ V_87 ] . V_94 ) ) == args -> V_94 )
break;
if ( V_83 < args -> V_94 )
V_85 = V_87 + 1 ;
else
V_84 = V_87 - 1 ;
if ( V_85 > V_84 ) {
ASSERT ( args -> V_90 & V_111 ) ;
F_35 ( V_32 , V_4 ) ;
return F_36 ( V_112 ) ;
}
}
while ( V_87 > 0 && F_25 ( V_50 [ V_87 - 1 ] . V_94 ) == args -> V_94 ) {
V_87 -- ;
}
do {
if ( ( V_108 = F_25 ( V_50 [ V_87 ] . V_78 ) ) == V_79 )
continue;
V_82 = ( T_6 * )
( ( char * ) V_46 + F_52 ( V_6 , V_108 ) ) ;
V_110 = V_6 -> V_113 -> V_114 ( args , V_82 -> V_96 , V_82 -> V_89 ) ;
if ( V_110 != V_115 && V_110 != args -> V_116 ) {
args -> V_116 = V_110 ;
* V_35 = V_4 ;
* V_107 = V_87 ;
if ( V_110 == V_117 )
return 0 ;
}
} while ( ++ V_87 < F_25 ( V_48 -> V_77 ) &&
F_25 ( V_50 [ V_87 ] . V_94 ) == V_83 );
ASSERT ( args -> V_90 & V_111 ) ;
if ( args -> V_116 == V_118 )
return 0 ;
F_35 ( V_32 , V_4 ) ;
return F_36 ( V_112 ) ;
}
int
F_60 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_106 ;
int error ;
T_9 * V_6 ;
int V_70 ;
int V_75 ;
T_14 V_119 ;
int V_120 ;
T_10 * V_32 ;
F_61 ( args ) ;
if ( ( error = F_58 ( args , & V_4 , & V_106 ) ) ) {
return error ;
}
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
V_82 = ( T_6 * )
( ( char * ) V_46 + F_52 ( V_6 , F_25 ( V_50 [ V_106 ] . V_78 ) ) ) ;
V_70 = V_75 = 0 ;
F_28 ( V_32 , V_4 ,
( V_80 ) ( ( char * ) V_82 - ( char * ) V_46 ) ,
F_32 ( V_82 -> V_89 ) , & V_70 , & V_75 ) ;
F_27 ( & V_48 -> V_62 , 1 ) ;
F_47 ( V_32 , V_4 ) ;
V_50 [ V_106 ] . V_78 = F_5 ( V_79 ) ;
F_43 ( V_32 , V_4 , V_106 , V_106 ) ;
if ( V_75 )
F_29 ( V_6 , V_46 , & V_70 ) ;
if ( V_70 )
F_46 ( V_32 , V_4 ) ;
F_49 ( V_34 , V_4 ) ;
V_120 = F_62 ( V_34 , V_46 , & V_119 ) ;
if ( V_120 > F_63 ( V_34 ) )
return 0 ;
return F_64 ( args , V_4 , V_120 , & V_119 ) ;
}
int
F_65 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_106 ;
int error ;
T_9 * V_6 ;
F_66 ( args ) ;
if ( ( error = F_58 ( args , & V_4 , & V_106 ) ) ) {
return error ;
}
V_34 = args -> V_34 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
V_82 = ( T_6 * )
( ( char * ) V_46 + F_52 ( V_6 , F_25 ( V_50 [ V_106 ] . V_78 ) ) ) ;
ASSERT ( F_7 ( V_82 -> V_95 ) != args -> V_95 ) ;
V_82 -> V_95 = F_15 ( args -> V_95 ) ;
F_48 ( args -> V_88 , V_4 , V_82 ) ;
F_49 ( V_34 , V_4 ) ;
return 0 ;
}
static int
F_67 (
const void * V_121 ,
const void * V_122 )
{
const T_4 * V_123 ;
const T_4 * V_124 ;
V_123 = V_121 ;
V_124 = V_122 ;
return F_25 ( V_123 -> V_94 ) < F_25 ( V_124 -> V_94 ) ? - 1 :
( F_25 ( V_123 -> V_94 ) > F_25 ( V_124 -> V_94 ) ? 1 : 0 ) ;
}
int
F_68 (
T_2 * args ,
struct V_3 * V_125 ,
struct V_3 * V_126 )
{
T_1 * V_127 ;
T_3 * V_46 ;
T_5 * V_48 ;
T_7 * V_34 ;
V_64 * V_60 ;
int error ;
int V_128 ;
T_15 * V_129 ;
T_4 * V_130 ;
T_16 * V_131 ;
T_9 * V_6 ;
int V_70 ;
int V_75 ;
T_14 V_119 ;
int V_120 ;
T_1 * V_59 ;
int V_132 ;
T_10 * V_32 ;
struct V_49 * V_133 ;
struct V_134 V_135 ;
F_69 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
V_129 = V_125 -> V_11 ;
F_70 ( & V_135 , V_129 ) ;
V_133 = F_71 ( V_129 ) ;
V_131 = F_72 ( V_6 , V_129 ) ;
ASSERT ( V_135 . V_13 == V_136 ||
V_135 . V_13 == V_137 ) ;
while ( V_34 -> V_138 . V_139 > V_6 -> V_140 ) {
int V_141 ;
V_141 = F_73 ( F_4 ( & V_6 -> V_12 ) ) ;
V_127 = F_74 ( V_131 ) ;
if ( F_24 ( V_127 [ F_25 ( V_131 -> V_142 ) - 1 ] ) ==
V_6 -> V_140 - V_141 ) {
if ( ( error =
F_75 ( args , V_125 ,
( V_143 ) ( F_25 ( V_131 -> V_142 ) - 1 ) ) ) )
return error ;
} else
return 0 ;
}
if ( ! V_126 ) {
error = F_76 ( V_32 , V_34 , V_6 -> V_38 , - 1 , & V_126 ) ;
if ( error )
return error ;
}
V_46 = V_126 -> V_11 ;
ASSERT ( V_46 -> V_13 == F_5 ( V_144 ) ||
V_46 -> V_13 == F_5 ( V_145 ) ) ;
V_120 = ( V_69 ) sizeof( T_5 ) +
( V_69 ) sizeof( * V_130 ) * ( V_135 . V_77 - V_135 . V_62 ) ;
V_59 = ( T_1 * ) ( ( char * ) V_46 + V_6 -> V_140 ) - 1 ;
V_60 = ( V_64 * ) ( ( char * ) V_46 + F_24 ( * V_59 ) ) ;
if ( F_24 ( V_60 -> V_67 ) != V_68 ||
F_24 ( V_60 -> V_63 ) < V_120 )
return 0 ;
F_20 ( V_6 , V_32 , V_126 , V_34 ) ;
V_70 = 1 ;
V_75 = 0 ;
F_39 ( V_32 , V_126 , V_60 , V_6 -> V_140 - V_120 , V_120 ,
& V_70 , & V_75 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_48 -> V_77 = F_5 ( V_135 . V_77 - V_135 . V_62 ) ;
V_48 -> V_62 = 0 ;
F_47 ( V_32 , V_126 ) ;
V_130 = F_34 ( V_48 ) ;
for ( V_128 = V_132 = 0 ; V_128 < V_135 . V_77 ; V_128 ++ ) {
if ( V_133 [ V_128 ] . V_78 == F_5 ( V_79 ) )
continue;
V_130 [ V_132 ++ ] = V_133 [ V_128 ] ;
}
ASSERT ( V_132 == F_25 ( V_48 -> V_77 ) ) ;
F_43 ( V_32 , V_126 , 0 , F_25 ( V_48 -> V_77 ) - 1 ) ;
if ( V_75 )
F_29 ( V_6 , V_46 , & V_70 ) ;
if ( V_70 )
F_46 ( V_32 , V_126 ) ;
error = F_77 ( args , V_6 -> V_146 , V_125 ) ;
if ( error )
return error ;
V_120 = F_62 ( V_34 , V_46 , & V_119 ) ;
if ( V_120 > F_63 ( V_34 ) )
return 0 ;
return F_64 ( args , V_126 , V_120 , & V_119 ) ;
}
int
F_78 (
T_2 * args )
{
V_143 V_17 ;
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_147 ;
V_64 * V_60 ;
int V_148 ;
int error ;
int V_149 ;
T_9 * V_6 ;
int V_70 ;
int V_75 ;
int V_150 ;
int V_65 ;
T_17 * V_151 ;
T_14 * V_152 ;
T_14 * V_153 ;
T_1 * V_59 ;
T_10 * V_32 ;
struct V_154 V_96 ;
F_79 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
ASSERT ( V_34 -> V_155 . V_156 & V_157 ) ;
if ( V_34 -> V_138 . V_139 < F_80 ( T_14 , V_158 ) ) {
ASSERT ( F_81 ( V_6 ) ) ;
return F_36 ( V_159 ) ;
}
V_152 = ( T_14 * ) V_34 -> V_155 . V_160 . V_161 ;
ASSERT ( V_34 -> V_155 . V_162 == V_34 -> V_138 . V_139 ) ;
ASSERT ( V_34 -> V_155 . V_160 . V_161 != NULL ) ;
ASSERT ( V_34 -> V_138 . V_139 >= F_82 ( V_152 -> V_163 ) ) ;
V_153 = F_83 ( V_34 -> V_155 . V_162 , V_164 ) ;
memcpy ( V_153 , V_152 , V_34 -> V_155 . V_162 ) ;
F_84 ( V_34 , - V_34 -> V_155 . V_162 , V_39 ) ;
V_34 -> V_138 . V_139 = 0 ;
F_85 ( V_32 , V_34 , V_165 ) ;
error = F_86 ( args , V_166 , & V_17 ) ;
if ( error ) {
F_87 ( V_153 ) ;
return error ;
}
error = F_88 ( args , V_17 , & V_4 ) ;
if ( error ) {
F_87 ( V_153 ) ;
return error ;
}
F_20 ( V_6 , V_32 , V_4 , V_34 ) ;
V_46 = V_4 -> V_11 ;
V_149 = ( V_69 ) sizeof( * V_48 ) +
( V_153 -> V_77 + 2 ) * ( V_69 ) sizeof( T_4 ) ;
V_60 = F_89 ( V_46 ) ;
V_70 = V_75 = 0 ;
F_39 ( V_32 , V_4 , V_60 , V_6 -> V_140 - V_149 , V_149 , & V_70 ,
& V_75 ) ;
ASSERT ( V_75 == 0 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_48 -> V_77 = F_5 ( V_153 -> V_77 + 2 ) ;
V_48 -> V_62 = 0 ;
V_50 = F_34 ( V_48 ) ;
V_148 = ( V_69 ) ( ( char * ) V_50 - ( char * ) V_46 ) ;
F_39 ( V_32 , V_4 , V_60 ,
( V_80 ) ( ( char * ) V_60 - ( char * ) V_46 ) ,
F_24 ( V_60 -> V_63 ) , & V_70 , & V_75 ) ;
V_82 = F_90 ( V_46 ) ;
V_82 -> V_95 = F_15 ( V_34 -> V_44 ) ;
V_82 -> V_89 = 1 ;
V_82 -> V_96 [ 0 ] = '.' ;
V_59 = F_44 ( V_82 ) ;
* V_59 = F_45 ( ( char * ) V_82 - ( char * ) V_46 ) ;
F_48 ( V_32 , V_4 , V_82 ) ;
V_50 [ 0 ] . V_94 = F_5 ( V_1 ) ;
V_50 [ 0 ] . V_78 = F_5 ( F_42 ( V_6 ,
( char * ) V_82 - ( char * ) V_46 ) ) ;
V_82 = F_91 ( V_46 ) ;
V_82 -> V_95 = F_15 ( F_92 ( V_153 ) ) ;
V_82 -> V_89 = 2 ;
V_82 -> V_96 [ 0 ] = V_82 -> V_96 [ 1 ] = '.' ;
V_59 = F_44 ( V_82 ) ;
* V_59 = F_45 ( ( char * ) V_82 - ( char * ) V_46 ) ;
F_48 ( V_32 , V_4 , V_82 ) ;
V_50 [ 1 ] . V_94 = F_5 ( V_2 ) ;
V_50 [ 1 ] . V_78 = F_5 ( F_42 ( V_6 ,
( char * ) V_82 - ( char * ) V_46 ) ) ;
V_65 = F_93 ( V_46 ) ;
V_149 = 0 ;
if ( ! V_153 -> V_77 )
V_151 = NULL ;
else
V_151 = F_94 ( V_153 ) ;
while ( V_65 < V_148 ) {
if ( V_151 == NULL )
V_150 = V_148 ;
else
V_150 = F_95 ( V_151 ) ;
if ( V_65 < V_150 ) {
V_60 = ( V_64 * ) ( ( char * ) V_46 + V_65 ) ;
V_60 -> V_67 = F_45 ( V_68 ) ;
V_60 -> V_63 = F_45 ( V_150 - V_65 ) ;
* F_96 ( V_60 ) = F_45 (
( ( char * ) V_60 - ( char * ) V_46 ) ) ;
F_97 ( V_32 , V_4 , V_60 ) ;
F_98 ( V_46 , V_60 , & V_147 ) ;
V_65 += F_24 ( V_60 -> V_63 ) ;
continue;
}
V_82 = ( T_6 * ) ( ( char * ) V_46 + V_150 ) ;
V_82 -> V_95 = F_15 ( F_99 ( V_153 , V_151 ) ) ;
V_82 -> V_89 = V_151 -> V_89 ;
memcpy ( V_82 -> V_96 , V_151 -> V_96 , V_82 -> V_89 ) ;
V_59 = F_44 ( V_82 ) ;
* V_59 = F_45 ( ( char * ) V_82 - ( char * ) V_46 ) ;
F_48 ( V_32 , V_4 , V_82 ) ;
V_96 . V_96 = V_151 -> V_96 ;
V_96 . V_56 = V_151 -> V_89 ;
V_50 [ 2 + V_149 ] . V_94 = F_5 ( V_6 -> V_113 ->
V_167 ( & V_96 ) ) ;
V_50 [ 2 + V_149 ] . V_78 = F_5 ( F_42 ( V_6 ,
( char * ) V_82 - ( char * ) V_46 ) ) ;
V_65 = ( int ) ( ( char * ) ( V_59 + 1 ) - ( char * ) V_46 ) ;
if ( ++ V_149 == V_153 -> V_77 )
V_151 = NULL ;
else
V_151 = F_100 ( V_153 , V_151 ) ;
}
F_87 ( V_153 ) ;
F_101 ( V_50 , F_25 ( V_48 -> V_77 ) , sizeof( * V_50 ) , F_67 ) ;
ASSERT ( V_75 == 0 ) ;
F_43 ( V_32 , V_4 , 0 , F_25 ( V_48 -> V_77 ) - 1 ) ;
F_47 ( V_32 , V_4 ) ;
F_49 ( V_34 , V_4 ) ;
return 0 ;
}
