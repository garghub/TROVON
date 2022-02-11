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
if ( F_4 ( & V_6 -> V_12 ) &&
! F_10 ( V_4 , V_20 ) )
F_11 ( V_4 , - V_21 ) ;
else if ( ! F_3 ( V_4 ) )
F_11 ( V_4 , - V_22 ) ;
if ( V_4 -> V_23 )
F_12 ( V_4 ) ;
}
static void
F_13 (
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
struct V_24 * V_25 = V_4 -> V_26 ;
struct V_9 * V_10 = V_4 -> V_11 ;
if ( ! F_3 ( V_4 ) ) {
F_11 ( V_4 , - V_22 ) ;
F_12 ( V_4 ) ;
return;
}
if ( ! F_4 ( & V_6 -> V_12 ) )
return;
if ( V_25 )
V_10 -> V_27 = F_14 ( V_25 -> V_28 . V_29 ) ;
F_15 ( V_4 , V_20 ) ;
}
int
F_16 (
struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_3 * * V_34 )
{
struct V_5 * V_6 = V_33 -> V_35 ;
int V_36 ;
V_36 = F_17 ( V_31 , V_33 , V_6 -> V_37 -> V_38 , - 1 , V_34 ,
V_39 , & V_40 ) ;
if ( ! V_36 && V_31 )
F_18 ( V_31 , * V_34 , V_41 ) ;
return V_36 ;
}
static void
F_19 (
struct V_5 * V_6 ,
struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = V_4 -> V_11 ;
V_4 -> V_42 = & V_40 ;
F_18 ( V_31 , V_4 , V_41 ) ;
if ( F_4 ( & V_6 -> V_12 ) ) {
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_13 = F_5 ( V_14 ) ;
V_10 -> V_17 = F_14 ( V_4 -> V_18 ) ;
V_10 -> V_43 = F_14 ( V_33 -> V_44 ) ;
F_20 ( & V_10 -> V_15 , & V_6 -> V_12 . V_16 ) ;
return;
}
V_10 -> V_13 = F_5 ( V_19 ) ;
}
static void
F_21 (
struct V_32 * V_33 ,
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
V_58 = V_33 -> V_62 -> V_63 ( V_46 ) ;
if ( V_48 -> V_64 ) {
if ( F_22 ( V_58 [ 0 ] . V_65 ) >= V_56 ) {
V_60 = ( V_66 * )
( ( char * ) V_46 + F_22 ( V_58 [ 0 ] . V_67 ) ) ;
goto V_68;
}
* V_55 = 1 ;
V_59 = ( T_1 * ) V_50 - 1 ;
V_60 = ( V_66 * ) ( ( char * ) V_46 + F_22 ( * V_59 ) ) ;
if ( F_22 ( V_60 -> V_69 ) == V_70 ) {
if ( F_22 ( V_60 -> V_65 ) + ( F_23 ( V_48 -> V_64 ) - 1 ) *
( V_71 ) sizeof( * V_50 ) < V_56 )
V_60 = NULL ;
} else if ( ( F_23 ( V_48 -> V_64 ) - 1 ) * ( V_71 ) sizeof( * V_50 ) < V_56 )
V_60 = NULL ;
else
V_60 = ( V_66 * ) V_50 ;
goto V_68;
}
V_59 = ( T_1 * ) V_50 - 1 ;
V_61 = ( V_66 * ) ( ( char * ) V_46 + F_22 ( * V_59 ) ) ;
if ( F_22 ( V_61 -> V_69 ) == V_70 ) {
V_60 = ( V_66 * )
( ( char * ) V_46 + F_22 ( V_58 [ 0 ] . V_67 ) ) ;
if ( V_60 != V_61 ) {
if ( F_22 ( V_60 -> V_65 ) < V_56 )
V_60 = NULL ;
goto V_68;
}
if ( F_22 ( V_60 -> V_65 ) < V_56 + ( V_71 ) sizeof( * V_50 ) ) {
if ( F_22 ( V_58 [ 1 ] . V_65 ) >= V_56 )
V_60 = ( V_66 * )
( ( char * ) V_46 + F_22 ( V_58 [ 1 ] . V_67 ) ) ;
else
V_60 = NULL ;
}
}
V_68:
* V_51 = V_59 ;
* V_53 = V_60 ;
* V_54 = V_61 ;
}
static void
F_24 (
struct V_72 * args ,
struct V_3 * V_4 ,
struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_50 ,
int * V_73 ,
int * V_74 ,
int * V_75 )
{
int V_76 ;
int V_77 ;
int V_78 = 0 ;
int V_79 ;
V_76 = V_77 = F_23 ( V_48 -> V_80 ) - 1 ;
V_79 = * V_74 = - 1 ;
for (; V_76 >= 0 ; V_76 -- ) {
if ( V_50 [ V_76 ] . V_81 == F_5 ( V_82 ) ) {
if ( V_79 == - 1 )
V_79 = V_77 ;
else {
if ( * V_74 == - 1 )
* V_74 = V_77 ;
continue;
}
}
if ( V_76 < V_77 )
V_50 [ V_77 ] = V_50 [ V_76 ] ;
V_77 -- ;
}
* V_75 = V_77 + 1 - ( F_23 ( V_48 -> V_64 ) - 1 ) ;
* V_74 -= F_23 ( V_48 -> V_64 ) - 1 ;
F_25 ( & V_48 -> V_80 , - ( F_23 ( V_48 -> V_64 ) - 1 ) ) ;
F_26 ( args , V_4 ,
( V_83 ) ( ( char * ) V_50 - ( char * ) V_46 ) ,
( V_83 ) ( ( F_23 ( V_48 -> V_64 ) - 1 ) * sizeof( * V_50 ) ) ,
V_73 , & V_78 ) ;
V_48 -> V_64 = F_5 ( 1 ) ;
if ( V_78 )
F_27 ( args -> V_33 , V_46 , V_73 ) ;
}
int
F_28 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
int V_55 ;
T_6 * V_84 ;
T_7 * V_33 ;
V_66 * V_60 ;
int error ;
V_66 * V_61 = NULL ;
T_8 V_85 ;
int V_86 ;
int V_79 ;
int V_74 = 0 ;
int V_75 = 0 ;
int V_56 ;
int V_87 ;
int V_88 ;
int V_89 = 0 ;
T_9 * V_6 ;
int V_73 ;
int V_78 ;
T_1 * V_59 ;
T_10 * V_31 ;
F_29 ( args ) ;
V_33 = args -> V_33 ;
V_31 = args -> V_90 ;
V_6 = V_33 -> V_35 ;
error = F_16 ( V_31 , V_33 , & V_4 ) ;
if ( error )
return error ;
V_56 = V_33 -> V_62 -> V_91 ( args -> V_92 ) ;
V_46 = V_4 -> V_11 ;
V_48 = F_30 ( args -> V_93 , V_46 ) ;
V_50 = F_31 ( V_48 ) ;
F_21 ( V_33 , V_46 , V_48 , V_50 , & V_59 , & V_60 ,
& V_61 , & V_55 , V_56 ) ;
if ( args -> V_94 & V_95 ) {
F_32 ( V_31 , V_4 ) ;
if ( ! V_60 )
return - V_96 ;
return 0 ;
}
if ( ! V_60 ) {
if ( args -> V_97 == 0 )
return - V_96 ;
error = F_33 ( args , V_4 ) ;
if ( error )
return error ;
return F_34 ( args ) ;
}
V_73 = V_78 = 0 ;
if ( V_55 ) {
F_24 ( args , V_4 , V_46 , V_48 , V_50 , & V_73 ,
& V_74 , & V_75 ) ;
V_50 = F_31 ( V_48 ) ;
} else if ( V_48 -> V_64 ) {
V_75 = F_23 ( V_48 -> V_80 ) ;
V_74 = - 1 ;
}
for ( V_87 = 0 , V_86 = F_23 ( V_48 -> V_80 ) - 1 ; V_87 <= V_86 ; ) {
V_89 = ( V_87 + V_86 ) >> 1 ;
if ( ( V_85 = F_23 ( V_50 [ V_89 ] . V_98 ) ) == args -> V_98 )
break;
if ( V_85 < args -> V_98 )
V_87 = V_89 + 1 ;
else
V_86 = V_89 - 1 ;
}
while ( V_89 >= 0 && F_23 ( V_50 [ V_89 ] . V_98 ) >= args -> V_98 ) {
V_89 -- ;
}
if ( ! V_48 -> V_64 ) {
F_35 ( args , V_4 , V_61 ,
( V_83 )
( ( char * ) V_61 - ( char * ) V_46 + F_22 ( V_61 -> V_65 ) -
sizeof( * V_50 ) ) ,
( V_83 ) sizeof( * V_50 ) ,
& V_73 , & V_78 ) ;
F_25 ( & V_48 -> V_80 , 1 ) ;
if ( V_78 ) {
F_27 ( V_33 , V_46 , & V_73 ) ;
V_78 = 0 ;
}
V_50 -- ;
V_89 ++ ;
if ( V_89 )
memmove ( V_50 , & V_50 [ 1 ] , V_89 * sizeof( * V_50 ) ) ;
V_75 = 0 ;
V_74 = V_89 ;
}
else {
for ( V_88 = V_89 ;
V_88 >= 0 &&
V_50 [ V_88 ] . V_81 !=
F_5 ( V_82 ) ;
V_88 -- )
continue;
for ( V_79 = V_89 + 1 ;
V_79 < F_23 ( V_48 -> V_80 ) &&
V_50 [ V_79 ] . V_81 !=
F_5 ( V_82 ) &&
( V_88 < 0 || V_89 - V_88 > V_79 - V_89 ) ;
V_79 ++ )
continue;
if ( V_88 >= 0 &&
( V_79 == F_23 ( V_48 -> V_80 ) ||
V_89 - V_88 <= V_79 - V_89 ) ) {
if ( V_89 - V_88 )
memmove ( & V_50 [ V_88 ] , & V_50 [ V_88 + 1 ] ,
( V_89 - V_88 ) * sizeof( * V_50 ) ) ;
V_75 = F_36 ( V_88 , V_75 ) ;
V_74 = F_37 ( V_89 , V_74 ) ;
}
else {
ASSERT ( V_79 < F_23 ( V_48 -> V_80 ) ) ;
V_89 ++ ;
if ( V_79 - V_89 )
memmove ( & V_50 [ V_89 + 1 ] , & V_50 [ V_89 ] ,
( V_79 - V_89 ) * sizeof( * V_50 ) ) ;
V_75 = F_36 ( V_89 , V_75 ) ;
V_74 = F_37 ( V_79 , V_74 ) ;
}
F_25 ( & V_48 -> V_64 , - 1 ) ;
}
V_84 = ( T_6 * ) V_60 ;
V_50 [ V_89 ] . V_98 = F_5 ( args -> V_98 ) ;
V_50 [ V_89 ] . V_81 = F_5 ( F_38 (
( char * ) V_84 - ( char * ) V_46 ) ) ;
F_39 ( V_31 , V_4 , V_75 , V_74 ) ;
F_35 ( args , V_4 , V_60 ,
( V_83 ) ( ( char * ) V_60 - ( char * ) V_46 ) ,
( V_83 ) V_56 , & V_73 , & V_78 ) ;
V_84 -> V_99 = F_14 ( args -> V_99 ) ;
V_84 -> V_92 = args -> V_92 ;
memcpy ( V_84 -> V_100 , args -> V_100 , args -> V_92 ) ;
V_33 -> V_62 -> V_101 ( V_84 , args -> V_102 ) ;
V_59 = V_33 -> V_62 -> V_103 ( V_84 ) ;
* V_59 = F_40 ( ( char * ) V_84 - ( char * ) V_46 ) ;
if ( V_78 )
F_27 ( V_33 , V_46 , & V_73 ) ;
if ( V_73 )
F_41 ( args , V_4 ) ;
F_42 ( V_31 , V_4 ) ;
F_43 ( args , V_4 , V_84 ) ;
F_44 ( V_33 , V_4 ) ;
return 0 ;
}
static void
F_39 (
T_10 * V_31 ,
struct V_3 * V_4 ,
int V_104 ,
int V_105 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_4 * V_50 ;
T_5 * V_48 ;
V_48 = F_30 ( V_31 -> V_106 -> V_37 , V_46 ) ;
V_50 = F_31 ( V_48 ) ;
F_45 ( V_31 , V_4 , ( V_71 ) ( ( char * ) & V_50 [ V_104 ] - ( char * ) V_46 ) ,
( V_71 ) ( ( char * ) & V_50 [ V_105 + 1 ] - ( char * ) V_46 - 1 ) ) ;
}
static void
F_42 (
T_10 * V_31 ,
struct V_3 * V_4 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_5 * V_48 ;
V_48 = F_30 ( V_31 -> V_106 -> V_37 , V_46 ) ;
F_45 ( V_31 , V_4 , ( V_71 ) ( ( char * ) V_48 - ( char * ) V_46 ) ,
( V_71 ) ( ( char * ) ( V_48 + 1 ) - ( char * ) V_46 - 1 ) ) ;
}
int
F_46 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_84 ;
T_7 * V_33 ;
int V_107 ;
int error ;
T_9 * V_6 ;
F_47 ( args ) ;
if ( ( error = F_48 ( args , & V_4 , & V_107 ) ) )
return error ;
V_33 = args -> V_33 ;
V_6 = V_33 -> V_35 ;
V_46 = V_4 -> V_11 ;
F_44 ( V_33 , V_4 ) ;
V_48 = F_30 ( args -> V_93 , V_46 ) ;
V_50 = F_31 ( V_48 ) ;
V_84 = ( T_6 * ) ( ( char * ) V_46 +
F_49 ( args -> V_93 ,
F_23 ( V_50 [ V_107 ] . V_81 ) ) ) ;
args -> V_99 = F_7 ( V_84 -> V_99 ) ;
args -> V_102 = V_33 -> V_62 -> V_108 ( V_84 ) ;
error = F_50 ( args , V_84 -> V_100 , V_84 -> V_92 ) ;
F_32 ( args -> V_90 , V_4 ) ;
return error ;
}
static int
F_48 (
T_2 * args ,
struct V_3 * * V_34 ,
int * V_109 )
{
T_11 V_110 ;
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_84 ;
T_7 * V_33 ;
int error ;
T_8 V_85 ;
int V_86 ;
int V_87 ;
int V_89 ;
T_9 * V_6 ;
T_10 * V_31 ;
enum V_111 V_112 ;
V_33 = args -> V_33 ;
V_31 = args -> V_90 ;
V_6 = V_33 -> V_35 ;
error = F_16 ( V_31 , V_33 , & V_4 ) ;
if ( error )
return error ;
V_46 = V_4 -> V_11 ;
F_44 ( V_33 , V_4 ) ;
V_48 = F_30 ( args -> V_93 , V_46 ) ;
V_50 = F_31 ( V_48 ) ;
for ( V_87 = 0 , V_86 = F_23 ( V_48 -> V_80 ) - 1 ; ; ) {
ASSERT ( V_87 <= V_86 ) ;
V_89 = ( V_87 + V_86 ) >> 1 ;
if ( ( V_85 = F_23 ( V_50 [ V_89 ] . V_98 ) ) == args -> V_98 )
break;
if ( V_85 < args -> V_98 )
V_87 = V_89 + 1 ;
else
V_86 = V_89 - 1 ;
if ( V_87 > V_86 ) {
ASSERT ( args -> V_94 & V_113 ) ;
F_32 ( V_31 , V_4 ) ;
return - V_114 ;
}
}
while ( V_89 > 0 && F_23 ( V_50 [ V_89 - 1 ] . V_98 ) == args -> V_98 ) {
V_89 -- ;
}
do {
if ( ( V_110 = F_23 ( V_50 [ V_89 ] . V_81 ) ) == V_82 )
continue;
V_84 = ( T_6 * )
( ( char * ) V_46 + F_49 ( args -> V_93 , V_110 ) ) ;
V_112 = V_6 -> V_115 -> V_116 ( args , V_84 -> V_100 , V_84 -> V_92 ) ;
if ( V_112 != V_117 && V_112 != args -> V_118 ) {
args -> V_118 = V_112 ;
* V_34 = V_4 ;
* V_109 = V_89 ;
if ( V_112 == V_119 )
return 0 ;
}
} while ( ++ V_89 < F_23 ( V_48 -> V_80 ) &&
F_23 ( V_50 [ V_89 ] . V_98 ) == V_85 );
ASSERT ( args -> V_94 & V_113 ) ;
if ( args -> V_118 == V_120 )
return 0 ;
F_32 ( V_31 , V_4 ) ;
return - V_114 ;
}
int
F_51 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_84 ;
T_7 * V_33 ;
int V_107 ;
int error ;
T_9 * V_6 ;
int V_73 ;
int V_78 ;
T_12 V_121 ;
int V_122 ;
T_10 * V_31 ;
F_52 ( args ) ;
if ( ( error = F_48 ( args , & V_4 , & V_107 ) ) ) {
return error ;
}
V_33 = args -> V_33 ;
V_31 = args -> V_90 ;
V_6 = V_33 -> V_35 ;
V_46 = V_4 -> V_11 ;
V_48 = F_30 ( args -> V_93 , V_46 ) ;
V_50 = F_31 ( V_48 ) ;
V_84 = ( T_6 * ) ( ( char * ) V_46 +
F_49 ( args -> V_93 ,
F_23 ( V_50 [ V_107 ] . V_81 ) ) ) ;
V_73 = V_78 = 0 ;
F_26 ( args , V_4 ,
( V_83 ) ( ( char * ) V_84 - ( char * ) V_46 ) ,
V_33 -> V_62 -> V_91 ( V_84 -> V_92 ) , & V_73 , & V_78 ) ;
F_25 ( & V_48 -> V_64 , 1 ) ;
F_42 ( V_31 , V_4 ) ;
V_50 [ V_107 ] . V_81 = F_5 ( V_82 ) ;
F_39 ( V_31 , V_4 , V_107 , V_107 ) ;
if ( V_78 )
F_27 ( V_33 , V_46 , & V_73 ) ;
if ( V_73 )
F_41 ( args , V_4 ) ;
F_44 ( V_33 , V_4 ) ;
V_122 = F_53 ( V_33 , V_46 , & V_121 ) ;
if ( V_122 > F_54 ( V_33 ) )
return 0 ;
return F_55 ( args , V_4 , V_122 , & V_121 ) ;
}
int
F_56 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_84 ;
T_7 * V_33 ;
int V_107 ;
int error ;
T_9 * V_6 ;
F_57 ( args ) ;
if ( ( error = F_48 ( args , & V_4 , & V_107 ) ) ) {
return error ;
}
V_33 = args -> V_33 ;
V_6 = V_33 -> V_35 ;
V_46 = V_4 -> V_11 ;
V_48 = F_30 ( args -> V_93 , V_46 ) ;
V_50 = F_31 ( V_48 ) ;
V_84 = ( T_6 * ) ( ( char * ) V_46 +
F_49 ( args -> V_93 ,
F_23 ( V_50 [ V_107 ] . V_81 ) ) ) ;
ASSERT ( F_7 ( V_84 -> V_99 ) != args -> V_99 ) ;
V_84 -> V_99 = F_14 ( args -> V_99 ) ;
V_33 -> V_62 -> V_101 ( V_84 , args -> V_102 ) ;
F_43 ( args , V_4 , V_84 ) ;
F_44 ( V_33 , V_4 ) ;
return 0 ;
}
static int
F_58 (
const void * V_123 ,
const void * V_124 )
{
const T_4 * V_125 ;
const T_4 * V_126 ;
V_125 = V_123 ;
V_126 = V_124 ;
return F_23 ( V_125 -> V_98 ) < F_23 ( V_126 -> V_98 ) ? - 1 :
( F_23 ( V_125 -> V_98 ) > F_23 ( V_126 -> V_98 ) ? 1 : 0 ) ;
}
int
F_59 (
T_2 * args ,
struct V_3 * V_127 ,
struct V_3 * V_128 )
{
T_1 * V_129 ;
T_3 * V_46 ;
T_5 * V_48 ;
T_7 * V_33 ;
V_66 * V_60 ;
int error ;
int V_130 ;
T_13 * V_131 ;
T_4 * V_132 ;
T_14 * V_133 ;
T_9 * V_6 ;
int V_73 ;
int V_78 ;
T_12 V_121 ;
int V_122 ;
T_1 * V_59 ;
int V_134 ;
T_10 * V_31 ;
struct V_49 * V_135 ;
struct V_136 V_137 ;
F_60 ( args ) ;
V_33 = args -> V_33 ;
V_31 = args -> V_90 ;
V_6 = V_33 -> V_35 ;
V_131 = V_127 -> V_11 ;
V_33 -> V_62 -> V_138 ( & V_137 , V_131 ) ;
V_135 = V_33 -> V_62 -> V_139 ( V_131 ) ;
V_133 = F_61 ( args -> V_93 , V_131 ) ;
ASSERT ( V_137 . V_13 == V_140 ||
V_137 . V_13 == V_141 ) ;
while ( V_33 -> V_142 . V_143 > args -> V_93 -> V_144 ) {
int V_145 ;
V_145 = V_33 -> V_62 -> V_146 ;
V_129 = F_62 ( V_133 ) ;
if ( F_22 ( V_129 [ F_23 ( V_133 -> V_147 ) - 1 ] ) ==
args -> V_93 -> V_144 - V_145 ) {
if ( ( error =
F_63 ( args , V_127 ,
( V_148 ) ( F_23 ( V_133 -> V_147 ) - 1 ) ) ) )
return error ;
} else
return 0 ;
}
if ( ! V_128 ) {
error = F_64 ( V_31 , V_33 , args -> V_93 -> V_38 , - 1 , & V_128 ) ;
if ( error )
return error ;
}
V_46 = V_128 -> V_11 ;
ASSERT ( V_46 -> V_13 == F_5 ( V_149 ) ||
V_46 -> V_13 == F_5 ( V_150 ) ) ;
V_122 = ( V_71 ) sizeof( T_5 ) +
( V_71 ) sizeof( * V_132 ) * ( V_137 . V_80 - V_137 . V_64 ) ;
V_59 = ( T_1 * ) ( ( char * ) V_46 + args -> V_93 -> V_144 ) - 1 ;
V_60 = ( V_66 * ) ( ( char * ) V_46 + F_22 ( * V_59 ) ) ;
if ( F_22 ( V_60 -> V_69 ) != V_70 ||
F_22 ( V_60 -> V_65 ) < V_122 )
return 0 ;
F_19 ( V_6 , V_31 , V_128 , V_33 ) ;
V_73 = 1 ;
V_78 = 0 ;
F_35 ( args , V_128 , V_60 , args -> V_93 -> V_144 - V_122 , V_122 ,
& V_73 , & V_78 ) ;
V_48 = F_30 ( args -> V_93 , V_46 ) ;
V_48 -> V_80 = F_5 ( V_137 . V_80 - V_137 . V_64 ) ;
V_48 -> V_64 = 0 ;
F_42 ( V_31 , V_128 ) ;
V_132 = F_31 ( V_48 ) ;
for ( V_130 = V_134 = 0 ; V_130 < V_137 . V_80 ; V_130 ++ ) {
if ( V_135 [ V_130 ] . V_81 == F_5 ( V_82 ) )
continue;
V_132 [ V_134 ++ ] = V_135 [ V_130 ] ;
}
ASSERT ( V_134 == F_23 ( V_48 -> V_80 ) ) ;
F_39 ( V_31 , V_128 , 0 , F_23 ( V_48 -> V_80 ) - 1 ) ;
if ( V_78 )
F_27 ( V_33 , V_46 , & V_73 ) ;
if ( V_73 )
F_41 ( args , V_128 ) ;
error = F_65 ( args , args -> V_93 -> V_151 , V_127 ) ;
if ( error )
return error ;
V_122 = F_53 ( V_33 , V_46 , & V_121 ) ;
if ( V_122 > F_54 ( V_33 ) )
return 0 ;
return F_55 ( args , V_128 , V_122 , & V_121 ) ;
}
int
F_66 (
T_2 * args )
{
V_148 V_17 ;
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_84 ;
T_7 * V_33 ;
int V_152 ;
V_66 * V_60 ;
int V_153 ;
int error ;
int V_154 ;
T_9 * V_6 ;
int V_73 ;
int V_78 ;
int V_155 ;
int V_67 ;
T_15 * V_156 ;
T_12 * V_157 ;
T_12 * V_158 ;
T_1 * V_59 ;
T_10 * V_31 ;
struct V_159 V_100 ;
struct V_160 * V_161 ;
F_67 ( args ) ;
V_33 = args -> V_33 ;
V_31 = args -> V_90 ;
V_6 = V_33 -> V_35 ;
V_161 = F_68 ( V_33 , V_39 ) ;
ASSERT ( V_161 -> V_162 & V_163 ) ;
if ( V_33 -> V_142 . V_143 < F_69 ( T_12 , V_164 ) ) {
ASSERT ( F_70 ( V_6 ) ) ;
return - V_165 ;
}
V_157 = ( T_12 * ) V_161 -> V_166 . V_167 ;
ASSERT ( V_161 -> V_168 == V_33 -> V_142 . V_143 ) ;
ASSERT ( V_161 -> V_166 . V_167 != NULL ) ;
ASSERT ( V_33 -> V_142 . V_143 >= F_71 ( V_157 -> V_169 ) ) ;
ASSERT ( V_33 -> V_142 . V_170 == 0 ) ;
V_158 = F_72 ( V_161 -> V_168 , V_171 ) ;
memcpy ( V_158 , V_157 , V_161 -> V_168 ) ;
F_73 ( V_33 , - V_161 -> V_168 , V_39 ) ;
F_74 ( V_33 , V_39 ) ;
V_33 -> V_142 . V_143 = 0 ;
error = F_75 ( args , V_172 , & V_17 ) ;
if ( error ) {
F_76 ( V_158 ) ;
return error ;
}
error = F_77 ( args , V_17 , & V_4 ) ;
if ( error ) {
F_76 ( V_158 ) ;
return error ;
}
F_19 ( V_6 , V_31 , V_4 , V_33 ) ;
V_46 = V_4 -> V_11 ;
V_154 = ( V_71 ) sizeof( * V_48 ) +
( V_158 -> V_80 + 2 ) * ( V_71 ) sizeof( T_4 ) ;
V_60 = V_33 -> V_62 -> V_173 ( V_46 ) ;
V_73 = V_78 = 0 ;
F_35 ( args , V_4 , V_60 , args -> V_93 -> V_144 - V_154 ,
V_154 , & V_73 , & V_78 ) ;
ASSERT ( V_78 == 0 ) ;
V_48 = F_30 ( args -> V_93 , V_46 ) ;
V_48 -> V_80 = F_5 ( V_158 -> V_80 + 2 ) ;
V_48 -> V_64 = 0 ;
V_50 = F_31 ( V_48 ) ;
V_153 = ( V_71 ) ( ( char * ) V_50 - ( char * ) V_46 ) ;
F_35 ( args , V_4 , V_60 ,
( V_83 ) ( ( char * ) V_60 - ( char * ) V_46 ) ,
F_22 ( V_60 -> V_65 ) , & V_73 , & V_78 ) ;
V_84 = V_33 -> V_62 -> V_174 ( V_46 ) ;
V_84 -> V_99 = F_14 ( V_33 -> V_44 ) ;
V_84 -> V_92 = 1 ;
V_84 -> V_100 [ 0 ] = '.' ;
V_33 -> V_62 -> V_101 ( V_84 , V_175 ) ;
V_59 = V_33 -> V_62 -> V_103 ( V_84 ) ;
* V_59 = F_40 ( ( char * ) V_84 - ( char * ) V_46 ) ;
F_43 ( args , V_4 , V_84 ) ;
V_50 [ 0 ] . V_98 = F_5 ( V_1 ) ;
V_50 [ 0 ] . V_81 = F_5 ( F_38 (
( char * ) V_84 - ( char * ) V_46 ) ) ;
V_84 = V_33 -> V_62 -> V_176 ( V_46 ) ;
V_84 -> V_99 = F_14 ( V_33 -> V_62 -> V_177 ( V_158 ) ) ;
V_84 -> V_92 = 2 ;
V_84 -> V_100 [ 0 ] = V_84 -> V_100 [ 1 ] = '.' ;
V_33 -> V_62 -> V_101 ( V_84 , V_175 ) ;
V_59 = V_33 -> V_62 -> V_103 ( V_84 ) ;
* V_59 = F_40 ( ( char * ) V_84 - ( char * ) V_46 ) ;
F_43 ( args , V_4 , V_84 ) ;
V_50 [ 1 ] . V_98 = F_5 ( V_2 ) ;
V_50 [ 1 ] . V_81 = F_5 ( F_38 (
( char * ) V_84 - ( char * ) V_46 ) ) ;
V_67 = V_33 -> V_62 -> V_178 ;
V_154 = 0 ;
if ( ! V_158 -> V_80 )
V_156 = NULL ;
else
V_156 = F_78 ( V_158 ) ;
while ( V_67 < V_153 ) {
if ( V_156 == NULL )
V_155 = V_153 ;
else
V_155 = F_79 ( V_156 ) ;
if ( V_67 < V_155 ) {
V_60 = ( V_66 * ) ( ( char * ) V_46 + V_67 ) ;
V_60 -> V_69 = F_40 ( V_70 ) ;
V_60 -> V_65 = F_40 ( V_155 - V_67 ) ;
* F_80 ( V_60 ) = F_40 (
( ( char * ) V_60 - ( char * ) V_46 ) ) ;
F_81 ( args , V_4 , V_60 ) ;
F_82 ( V_46 ,
V_33 -> V_62 -> V_63 ( V_46 ) ,
V_60 , & V_152 ) ;
V_67 += F_22 ( V_60 -> V_65 ) ;
continue;
}
V_84 = ( T_6 * ) ( ( char * ) V_46 + V_155 ) ;
V_84 -> V_99 = F_14 ( V_33 -> V_62 -> V_179 ( V_158 , V_156 ) ) ;
V_84 -> V_92 = V_156 -> V_92 ;
V_33 -> V_62 -> V_101 ( V_84 , V_33 -> V_62 -> V_180 ( V_156 ) ) ;
memcpy ( V_84 -> V_100 , V_156 -> V_100 , V_84 -> V_92 ) ;
V_59 = V_33 -> V_62 -> V_103 ( V_84 ) ;
* V_59 = F_40 ( ( char * ) V_84 - ( char * ) V_46 ) ;
F_43 ( args , V_4 , V_84 ) ;
V_100 . V_100 = V_156 -> V_100 ;
V_100 . V_56 = V_156 -> V_92 ;
V_50 [ 2 + V_154 ] . V_98 = F_5 ( V_6 -> V_115 ->
V_181 ( & V_100 ) ) ;
V_50 [ 2 + V_154 ] . V_81 = F_5 ( F_38 (
( char * ) V_84 - ( char * ) V_46 ) ) ;
V_67 = ( int ) ( ( char * ) ( V_59 + 1 ) - ( char * ) V_46 ) ;
if ( ++ V_154 == V_158 -> V_80 )
V_156 = NULL ;
else
V_156 = V_33 -> V_62 -> V_182 ( V_158 , V_156 ) ;
}
F_76 ( V_158 ) ;
F_83 ( V_50 , F_23 ( V_48 -> V_80 ) , sizeof( * V_50 ) , F_58 ) ;
ASSERT ( V_78 == 0 ) ;
F_39 ( V_31 , V_4 , 0 , F_23 ( V_48 -> V_80 ) - 1 ) ;
F_42 ( V_31 , V_4 ) ;
F_44 ( V_33 , V_4 ) ;
return 0 ;
}
