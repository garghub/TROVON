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
struct V_97 * V_98 )
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
if ( F_51 ( V_6 , V_98 -> V_103 ) > V_6 -> V_38 )
return 0 ;
error = F_17 ( NULL , V_34 , & V_4 ) ;
if ( error )
return error ;
V_101 = F_52 ( V_6 , V_98 -> V_103 ) ;
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
V_98 -> V_103 = V_102 & 0x7fffffff ;
if ( ! F_55 ( V_98 , ( char * ) V_82 -> V_96 , V_82 -> V_89 ,
F_7 ( V_82 -> V_95 ) , V_104 ) ) {
F_35 ( NULL , V_4 ) ;
return 0 ;
}
}
V_98 -> V_103 = F_54 ( V_6 , V_6 -> V_38 + 1 , 0 ) &
0x7fffffff ;
F_35 ( NULL , V_4 ) ;
return 0 ;
}
static void
F_43 (
T_10 * V_32 ,
struct V_3 * V_4 ,
int V_105 ,
int V_106 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_4 * V_50 ;
T_5 * V_48 ;
V_48 = F_33 ( V_32 -> V_81 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
F_56 ( V_32 , V_4 , ( V_69 ) ( ( char * ) & V_50 [ V_105 ] - ( char * ) V_46 ) ,
( V_69 ) ( ( char * ) & V_50 [ V_106 + 1 ] - ( char * ) V_46 - 1 ) ) ;
}
static void
F_47 (
T_10 * V_32 ,
struct V_3 * V_4 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_5 * V_48 ;
V_48 = F_33 ( V_32 -> V_81 , V_46 ) ;
F_56 ( V_32 , V_4 , ( V_69 ) ( ( char * ) V_48 - ( char * ) V_46 ) ,
( V_69 ) ( ( char * ) ( V_48 + 1 ) - ( char * ) V_46 - 1 ) ) ;
}
int
F_57 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_107 ;
int error ;
T_9 * V_6 ;
F_58 ( args ) ;
if ( ( error = F_59 ( args , & V_4 , & V_107 ) ) )
return error ;
V_34 = args -> V_34 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
F_49 ( V_34 , V_4 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
V_82 = ( T_6 * ) ( ( char * ) V_46 +
F_52 ( V_6 , F_25 ( V_50 [ V_107 ] . V_78 ) ) ) ;
args -> V_95 = F_7 ( V_82 -> V_95 ) ;
error = F_60 ( args , V_82 -> V_96 , V_82 -> V_89 ) ;
F_35 ( args -> V_88 , V_4 ) ;
return F_36 ( error ) ;
}
static int
F_59 (
T_2 * args ,
struct V_3 * * V_35 ,
int * V_108 )
{
T_12 V_109 ;
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
enum V_110 V_111 ;
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
ASSERT ( args -> V_90 & V_112 ) ;
F_35 ( V_32 , V_4 ) ;
return F_36 ( V_113 ) ;
}
}
while ( V_87 > 0 && F_25 ( V_50 [ V_87 - 1 ] . V_94 ) == args -> V_94 ) {
V_87 -- ;
}
do {
if ( ( V_109 = F_25 ( V_50 [ V_87 ] . V_78 ) ) == V_79 )
continue;
V_82 = ( T_6 * )
( ( char * ) V_46 + F_52 ( V_6 , V_109 ) ) ;
V_111 = V_6 -> V_114 -> V_115 ( args , V_82 -> V_96 , V_82 -> V_89 ) ;
if ( V_111 != V_116 && V_111 != args -> V_117 ) {
args -> V_117 = V_111 ;
* V_35 = V_4 ;
* V_108 = V_87 ;
if ( V_111 == V_118 )
return 0 ;
}
} while ( ++ V_87 < F_25 ( V_48 -> V_77 ) &&
F_25 ( V_50 [ V_87 ] . V_94 ) == V_83 );
ASSERT ( args -> V_90 & V_112 ) ;
if ( args -> V_117 == V_119 )
return 0 ;
F_35 ( V_32 , V_4 ) ;
return F_36 ( V_113 ) ;
}
int
F_61 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_107 ;
int error ;
T_9 * V_6 ;
int V_70 ;
int V_75 ;
T_13 V_120 ;
int V_121 ;
T_10 * V_32 ;
F_62 ( args ) ;
if ( ( error = F_59 ( args , & V_4 , & V_107 ) ) ) {
return error ;
}
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
V_82 = ( T_6 * )
( ( char * ) V_46 + F_52 ( V_6 , F_25 ( V_50 [ V_107 ] . V_78 ) ) ) ;
V_70 = V_75 = 0 ;
F_28 ( V_32 , V_4 ,
( V_80 ) ( ( char * ) V_82 - ( char * ) V_46 ) ,
F_32 ( V_82 -> V_89 ) , & V_70 , & V_75 ) ;
F_27 ( & V_48 -> V_62 , 1 ) ;
F_47 ( V_32 , V_4 ) ;
V_50 [ V_107 ] . V_78 = F_5 ( V_79 ) ;
F_43 ( V_32 , V_4 , V_107 , V_107 ) ;
if ( V_75 )
F_29 ( V_6 , V_46 , & V_70 ) ;
if ( V_70 )
F_46 ( V_32 , V_4 ) ;
F_49 ( V_34 , V_4 ) ;
V_121 = F_63 ( V_34 , V_46 , & V_120 ) ;
if ( V_121 > F_64 ( V_34 ) )
return 0 ;
return F_65 ( args , V_4 , V_121 , & V_120 ) ;
}
int
F_66 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_107 ;
int error ;
T_9 * V_6 ;
F_67 ( args ) ;
if ( ( error = F_59 ( args , & V_4 , & V_107 ) ) ) {
return error ;
}
V_34 = args -> V_34 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_50 = F_34 ( V_48 ) ;
V_82 = ( T_6 * )
( ( char * ) V_46 + F_52 ( V_6 , F_25 ( V_50 [ V_107 ] . V_78 ) ) ) ;
ASSERT ( F_7 ( V_82 -> V_95 ) != args -> V_95 ) ;
V_82 -> V_95 = F_15 ( args -> V_95 ) ;
F_48 ( args -> V_88 , V_4 , V_82 ) ;
F_49 ( V_34 , V_4 ) ;
return 0 ;
}
static int
F_68 (
const void * V_122 ,
const void * V_123 )
{
const T_4 * V_124 ;
const T_4 * V_125 ;
V_124 = V_122 ;
V_125 = V_123 ;
return F_25 ( V_124 -> V_94 ) < F_25 ( V_125 -> V_94 ) ? - 1 :
( F_25 ( V_124 -> V_94 ) > F_25 ( V_125 -> V_94 ) ? 1 : 0 ) ;
}
int
F_69 (
T_2 * args ,
struct V_3 * V_126 ,
struct V_3 * V_127 )
{
T_1 * V_128 ;
T_3 * V_46 ;
T_5 * V_48 ;
T_7 * V_34 ;
V_64 * V_60 ;
int error ;
int V_129 ;
T_14 * V_130 ;
T_4 * V_131 ;
T_15 * V_132 ;
T_9 * V_6 ;
int V_70 ;
int V_75 ;
T_13 V_120 ;
int V_121 ;
T_1 * V_59 ;
int V_133 ;
T_10 * V_32 ;
struct V_49 * V_134 ;
struct V_135 V_136 ;
F_70 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
V_130 = V_126 -> V_11 ;
F_71 ( & V_136 , V_130 ) ;
V_134 = F_72 ( V_130 ) ;
V_132 = F_73 ( V_6 , V_130 ) ;
ASSERT ( V_136 . V_13 == V_137 ||
V_136 . V_13 == V_138 ) ;
while ( V_34 -> V_139 . V_140 > V_6 -> V_141 ) {
int V_142 ;
V_142 = F_74 ( F_4 ( & V_6 -> V_12 ) ) ;
V_128 = F_75 ( V_132 ) ;
if ( F_24 ( V_128 [ F_25 ( V_132 -> V_143 ) - 1 ] ) ==
V_6 -> V_141 - V_142 ) {
if ( ( error =
F_76 ( args , V_126 ,
( V_144 ) ( F_25 ( V_132 -> V_143 ) - 1 ) ) ) )
return error ;
} else
return 0 ;
}
if ( ! V_127 ) {
error = F_77 ( V_32 , V_34 , V_6 -> V_38 , - 1 , & V_127 ) ;
if ( error )
return error ;
}
V_46 = V_127 -> V_11 ;
ASSERT ( V_46 -> V_13 == F_5 ( V_145 ) ||
V_46 -> V_13 == F_5 ( V_146 ) ) ;
V_121 = ( V_69 ) sizeof( T_5 ) +
( V_69 ) sizeof( * V_131 ) * ( V_136 . V_77 - V_136 . V_62 ) ;
V_59 = ( T_1 * ) ( ( char * ) V_46 + V_6 -> V_141 ) - 1 ;
V_60 = ( V_64 * ) ( ( char * ) V_46 + F_24 ( * V_59 ) ) ;
if ( F_24 ( V_60 -> V_67 ) != V_68 ||
F_24 ( V_60 -> V_63 ) < V_121 )
return 0 ;
F_20 ( V_6 , V_32 , V_127 , V_34 ) ;
V_70 = 1 ;
V_75 = 0 ;
F_39 ( V_32 , V_127 , V_60 , V_6 -> V_141 - V_121 , V_121 ,
& V_70 , & V_75 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_48 -> V_77 = F_5 ( V_136 . V_77 - V_136 . V_62 ) ;
V_48 -> V_62 = 0 ;
F_47 ( V_32 , V_127 ) ;
V_131 = F_34 ( V_48 ) ;
for ( V_129 = V_133 = 0 ; V_129 < V_136 . V_77 ; V_129 ++ ) {
if ( V_134 [ V_129 ] . V_78 == F_5 ( V_79 ) )
continue;
V_131 [ V_133 ++ ] = V_134 [ V_129 ] ;
}
ASSERT ( V_133 == F_25 ( V_48 -> V_77 ) ) ;
F_43 ( V_32 , V_127 , 0 , F_25 ( V_48 -> V_77 ) - 1 ) ;
if ( V_75 )
F_29 ( V_6 , V_46 , & V_70 ) ;
if ( V_70 )
F_46 ( V_32 , V_127 ) ;
error = F_78 ( args , V_6 -> V_147 , V_126 ) ;
if ( error )
return error ;
V_121 = F_63 ( V_34 , V_46 , & V_120 ) ;
if ( V_121 > F_64 ( V_34 ) )
return 0 ;
return F_65 ( args , V_127 , V_121 , & V_120 ) ;
}
int
F_79 (
T_2 * args )
{
V_144 V_17 ;
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_82 ;
T_7 * V_34 ;
int V_148 ;
V_64 * V_60 ;
int V_149 ;
int error ;
int V_150 ;
T_9 * V_6 ;
int V_70 ;
int V_75 ;
int V_151 ;
int V_65 ;
T_16 * V_152 ;
T_13 * V_153 ;
T_13 * V_154 ;
T_1 * V_59 ;
T_10 * V_32 ;
struct V_155 V_96 ;
struct V_156 * V_157 ;
F_80 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_88 ;
V_6 = V_34 -> V_36 ;
V_157 = F_81 ( V_34 , V_39 ) ;
ASSERT ( V_157 -> V_158 & V_159 ) ;
if ( V_34 -> V_139 . V_140 < F_82 ( T_13 , V_160 ) ) {
ASSERT ( F_83 ( V_6 ) ) ;
return F_36 ( V_161 ) ;
}
V_153 = ( T_13 * ) V_157 -> V_162 . V_163 ;
ASSERT ( V_157 -> V_164 == V_34 -> V_139 . V_140 ) ;
ASSERT ( V_157 -> V_162 . V_163 != NULL ) ;
ASSERT ( V_34 -> V_139 . V_140 >= F_84 ( V_153 -> V_165 ) ) ;
ASSERT ( V_34 -> V_139 . V_166 == 0 ) ;
V_154 = F_85 ( V_157 -> V_164 , V_167 ) ;
memcpy ( V_154 , V_153 , V_157 -> V_164 ) ;
F_86 ( V_34 , - V_157 -> V_164 , V_39 ) ;
F_87 ( V_34 , V_39 ) ;
V_34 -> V_139 . V_140 = 0 ;
error = F_88 ( args , V_168 , & V_17 ) ;
if ( error ) {
F_89 ( V_154 ) ;
return error ;
}
error = F_90 ( args , V_17 , & V_4 ) ;
if ( error ) {
F_89 ( V_154 ) ;
return error ;
}
F_20 ( V_6 , V_32 , V_4 , V_34 ) ;
V_46 = V_4 -> V_11 ;
V_150 = ( V_69 ) sizeof( * V_48 ) +
( V_154 -> V_77 + 2 ) * ( V_69 ) sizeof( T_4 ) ;
V_60 = F_91 ( V_46 ) ;
V_70 = V_75 = 0 ;
F_39 ( V_32 , V_4 , V_60 , V_6 -> V_141 - V_150 , V_150 , & V_70 ,
& V_75 ) ;
ASSERT ( V_75 == 0 ) ;
V_48 = F_33 ( V_6 , V_46 ) ;
V_48 -> V_77 = F_5 ( V_154 -> V_77 + 2 ) ;
V_48 -> V_62 = 0 ;
V_50 = F_34 ( V_48 ) ;
V_149 = ( V_69 ) ( ( char * ) V_50 - ( char * ) V_46 ) ;
F_39 ( V_32 , V_4 , V_60 ,
( V_80 ) ( ( char * ) V_60 - ( char * ) V_46 ) ,
F_24 ( V_60 -> V_63 ) , & V_70 , & V_75 ) ;
V_82 = F_92 ( V_46 ) ;
V_82 -> V_95 = F_15 ( V_34 -> V_44 ) ;
V_82 -> V_89 = 1 ;
V_82 -> V_96 [ 0 ] = '.' ;
V_59 = F_44 ( V_82 ) ;
* V_59 = F_45 ( ( char * ) V_82 - ( char * ) V_46 ) ;
F_48 ( V_32 , V_4 , V_82 ) ;
V_50 [ 0 ] . V_94 = F_5 ( V_1 ) ;
V_50 [ 0 ] . V_78 = F_5 ( F_42 ( V_6 ,
( char * ) V_82 - ( char * ) V_46 ) ) ;
V_82 = F_93 ( V_46 ) ;
V_82 -> V_95 = F_15 ( F_94 ( V_154 ) ) ;
V_82 -> V_89 = 2 ;
V_82 -> V_96 [ 0 ] = V_82 -> V_96 [ 1 ] = '.' ;
V_59 = F_44 ( V_82 ) ;
* V_59 = F_45 ( ( char * ) V_82 - ( char * ) V_46 ) ;
F_48 ( V_32 , V_4 , V_82 ) ;
V_50 [ 1 ] . V_94 = F_5 ( V_2 ) ;
V_50 [ 1 ] . V_78 = F_5 ( F_42 ( V_6 ,
( char * ) V_82 - ( char * ) V_46 ) ) ;
V_65 = F_95 ( V_46 ) ;
V_150 = 0 ;
if ( ! V_154 -> V_77 )
V_152 = NULL ;
else
V_152 = F_96 ( V_154 ) ;
while ( V_65 < V_149 ) {
if ( V_152 == NULL )
V_151 = V_149 ;
else
V_151 = F_97 ( V_152 ) ;
if ( V_65 < V_151 ) {
V_60 = ( V_64 * ) ( ( char * ) V_46 + V_65 ) ;
V_60 -> V_67 = F_45 ( V_68 ) ;
V_60 -> V_63 = F_45 ( V_151 - V_65 ) ;
* F_98 ( V_60 ) = F_45 (
( ( char * ) V_60 - ( char * ) V_46 ) ) ;
F_99 ( V_32 , V_4 , V_60 ) ;
F_100 ( V_46 , V_60 , & V_148 ) ;
V_65 += F_24 ( V_60 -> V_63 ) ;
continue;
}
V_82 = ( T_6 * ) ( ( char * ) V_46 + V_151 ) ;
V_82 -> V_95 = F_15 ( F_101 ( V_154 , V_152 ) ) ;
V_82 -> V_89 = V_152 -> V_89 ;
memcpy ( V_82 -> V_96 , V_152 -> V_96 , V_82 -> V_89 ) ;
V_59 = F_44 ( V_82 ) ;
* V_59 = F_45 ( ( char * ) V_82 - ( char * ) V_46 ) ;
F_48 ( V_32 , V_4 , V_82 ) ;
V_96 . V_96 = V_152 -> V_96 ;
V_96 . V_56 = V_152 -> V_89 ;
V_50 [ 2 + V_150 ] . V_94 = F_5 ( V_6 -> V_114 ->
V_169 ( & V_96 ) ) ;
V_50 [ 2 + V_150 ] . V_78 = F_5 ( F_42 ( V_6 ,
( char * ) V_82 - ( char * ) V_46 ) ) ;
V_65 = ( int ) ( ( char * ) ( V_59 + 1 ) - ( char * ) V_46 ) ;
if ( ++ V_150 == V_154 -> V_77 )
V_152 = NULL ;
else
V_152 = F_102 ( V_154 , V_152 ) ;
}
F_89 ( V_154 ) ;
F_103 ( V_50 , F_25 ( V_48 -> V_77 ) , sizeof( * V_50 ) , F_68 ) ;
ASSERT ( V_75 == 0 ) ;
F_43 ( V_32 , V_4 , 0 , F_25 ( V_48 -> V_77 ) - 1 ) ;
F_47 ( V_32 , V_4 ) ;
F_49 ( V_34 , V_4 ) ;
return 0 ;
}
