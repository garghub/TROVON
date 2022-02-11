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
int
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
struct V_33 * V_34 ,
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
V_58 = V_34 -> V_62 -> V_63 ( V_46 ) ;
if ( V_48 -> V_64 ) {
if ( F_23 ( V_58 [ 0 ] . V_65 ) >= V_56 ) {
V_60 = ( V_66 * )
( ( char * ) V_46 + F_23 ( V_58 [ 0 ] . V_67 ) ) ;
goto V_68;
}
* V_55 = 1 ;
V_59 = ( T_1 * ) V_50 - 1 ;
V_60 = ( V_66 * ) ( ( char * ) V_46 + F_23 ( * V_59 ) ) ;
if ( F_23 ( V_60 -> V_69 ) == V_70 ) {
if ( F_23 ( V_60 -> V_65 ) + ( F_24 ( V_48 -> V_64 ) - 1 ) *
( V_71 ) sizeof( * V_50 ) < V_56 )
V_60 = NULL ;
} else if ( ( F_24 ( V_48 -> V_64 ) - 1 ) * ( V_71 ) sizeof( * V_50 ) < V_56 )
V_60 = NULL ;
else
V_60 = ( V_66 * ) V_50 ;
goto V_68;
}
V_59 = ( T_1 * ) V_50 - 1 ;
V_61 = ( V_66 * ) ( ( char * ) V_46 + F_23 ( * V_59 ) ) ;
if ( F_23 ( V_61 -> V_69 ) == V_70 ) {
V_60 = ( V_66 * )
( ( char * ) V_46 + F_23 ( V_58 [ 0 ] . V_67 ) ) ;
if ( V_60 != V_61 ) {
if ( F_23 ( V_60 -> V_65 ) < V_56 )
V_60 = NULL ;
goto V_68;
}
if ( F_23 ( V_60 -> V_65 ) < V_56 + ( V_71 ) sizeof( * V_50 ) ) {
if ( F_23 ( V_58 [ 1 ] . V_65 ) >= V_56 )
V_60 = ( V_66 * )
( ( char * ) V_46 + F_23 ( V_58 [ 1 ] . V_67 ) ) ;
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
F_25 (
struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_3 * V_4 ,
struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_50 ,
int * V_72 ,
int * V_73 ,
int * V_74 )
{
int V_75 ;
int V_76 ;
int V_77 = 0 ;
int V_78 ;
V_75 = V_76 = F_24 ( V_48 -> V_79 ) - 1 ;
V_78 = * V_73 = - 1 ;
for (; V_75 >= 0 ; V_75 -- ) {
if ( V_50 [ V_75 ] . V_80 == F_5 ( V_81 ) ) {
if ( V_78 == - 1 )
V_78 = V_76 ;
else {
if ( * V_73 == - 1 )
* V_73 = V_76 ;
continue;
}
}
if ( V_75 < V_76 )
V_50 [ V_76 ] = V_50 [ V_75 ] ;
V_76 -- ;
}
* V_74 = V_76 + 1 - ( F_24 ( V_48 -> V_64 ) - 1 ) ;
* V_73 -= F_24 ( V_48 -> V_64 ) - 1 ;
F_26 ( & V_48 -> V_79 , - ( F_24 ( V_48 -> V_64 ) - 1 ) ) ;
F_27 ( V_32 , V_34 , V_4 ,
( V_82 ) ( ( char * ) V_50 - ( char * ) V_46 ) ,
( V_82 ) ( ( F_24 ( V_48 -> V_64 ) - 1 ) * sizeof( * V_50 ) ) ,
V_72 , & V_77 ) ;
V_50 += F_24 ( V_48 -> V_64 ) - 1 ;
V_48 -> V_64 = F_5 ( 1 ) ;
if ( V_77 )
F_28 ( V_34 , V_46 , V_72 ) ;
}
int
F_29 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
int V_55 ;
T_6 * V_83 ;
T_7 * V_34 ;
V_66 * V_60 ;
int error ;
V_66 * V_61 = NULL ;
T_8 V_84 ;
int V_85 ;
int V_78 ;
int V_73 = 0 ;
int V_74 = 0 ;
int V_56 ;
int V_86 ;
int V_87 ;
int V_88 = 0 ;
T_9 * V_6 ;
int V_72 ;
int V_77 ;
T_1 * V_59 ;
T_10 * V_32 ;
F_30 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_89 ;
V_6 = V_34 -> V_36 ;
error = F_17 ( V_32 , V_34 , & V_4 ) ;
if ( error )
return error ;
V_56 = V_34 -> V_62 -> V_90 ( args -> V_91 ) ;
V_46 = V_4 -> V_11 ;
V_48 = F_31 ( V_6 , V_46 ) ;
V_50 = F_32 ( V_48 ) ;
F_22 ( V_34 , V_46 , V_48 , V_50 , & V_59 , & V_60 ,
& V_61 , & V_55 , V_56 ) ;
if ( args -> V_92 & V_93 ) {
F_33 ( V_32 , V_4 ) ;
if ( ! V_60 )
return F_34 ( V_94 ) ;
return 0 ;
}
if ( ! V_60 ) {
if ( args -> V_95 == 0 )
return F_34 ( V_94 ) ;
error = F_35 ( args , V_4 ) ;
if ( error )
return error ;
return F_36 ( args ) ;
}
V_72 = V_77 = 0 ;
if ( V_55 ) {
F_25 ( V_32 , V_34 , V_4 , V_46 , V_48 , V_50 , & V_72 ,
& V_73 , & V_74 ) ;
V_50 = F_32 ( V_48 ) ;
} else if ( V_48 -> V_64 ) {
V_74 = F_24 ( V_48 -> V_79 ) ;
V_73 = - 1 ;
}
for ( V_86 = 0 , V_85 = F_24 ( V_48 -> V_79 ) - 1 ; V_86 <= V_85 ; ) {
V_88 = ( V_86 + V_85 ) >> 1 ;
if ( ( V_84 = F_24 ( V_50 [ V_88 ] . V_96 ) ) == args -> V_96 )
break;
if ( V_84 < args -> V_96 )
V_86 = V_88 + 1 ;
else
V_85 = V_88 - 1 ;
}
while ( V_88 >= 0 && F_24 ( V_50 [ V_88 ] . V_96 ) >= args -> V_96 ) {
V_88 -- ;
}
if ( ! V_48 -> V_64 ) {
F_37 ( V_32 , V_34 , V_4 , V_61 ,
( V_82 )
( ( char * ) V_61 - ( char * ) V_46 + F_23 ( V_61 -> V_65 ) -
sizeof( * V_50 ) ) ,
( V_82 ) sizeof( * V_50 ) ,
& V_72 , & V_77 ) ;
F_26 ( & V_48 -> V_79 , 1 ) ;
if ( V_77 ) {
F_28 ( V_34 , V_46 , & V_72 ) ;
V_77 = 0 ;
}
V_50 -- ;
V_88 ++ ;
if ( V_88 )
memmove ( V_50 , & V_50 [ 1 ] , V_88 * sizeof( * V_50 ) ) ;
V_74 = 0 ;
V_73 = V_88 ;
}
else {
for ( V_87 = V_88 ;
V_87 >= 0 &&
V_50 [ V_87 ] . V_80 !=
F_5 ( V_81 ) ;
V_87 -- )
continue;
for ( V_78 = V_88 + 1 ;
V_78 < F_24 ( V_48 -> V_79 ) &&
V_50 [ V_78 ] . V_80 !=
F_5 ( V_81 ) &&
( V_87 < 0 || V_88 - V_87 > V_78 - V_88 ) ;
V_78 ++ )
continue;
if ( V_87 >= 0 &&
( V_78 == F_24 ( V_48 -> V_79 ) ||
V_88 - V_87 <= V_78 - V_88 ) ) {
if ( V_88 - V_87 )
memmove ( & V_50 [ V_87 ] , & V_50 [ V_87 + 1 ] ,
( V_88 - V_87 ) * sizeof( * V_50 ) ) ;
V_74 = F_38 ( V_87 , V_74 ) ;
V_73 = F_39 ( V_88 , V_73 ) ;
}
else {
ASSERT ( V_78 < F_24 ( V_48 -> V_79 ) ) ;
V_88 ++ ;
if ( V_78 - V_88 )
memmove ( & V_50 [ V_88 + 1 ] , & V_50 [ V_88 ] ,
( V_78 - V_88 ) * sizeof( * V_50 ) ) ;
V_74 = F_38 ( V_88 , V_74 ) ;
V_73 = F_39 ( V_78 , V_73 ) ;
}
F_26 ( & V_48 -> V_64 , - 1 ) ;
}
V_83 = ( T_6 * ) V_60 ;
V_50 [ V_88 ] . V_96 = F_5 ( args -> V_96 ) ;
V_50 [ V_88 ] . V_80 = F_5 ( F_40 ( V_6 ,
( char * ) V_83 - ( char * ) V_46 ) ) ;
F_41 ( V_32 , V_4 , V_74 , V_73 ) ;
F_37 ( V_32 , V_34 , V_4 , V_60 ,
( V_82 ) ( ( char * ) V_60 - ( char * ) V_46 ) ,
( V_82 ) V_56 , & V_72 , & V_77 ) ;
V_83 -> V_97 = F_15 ( args -> V_97 ) ;
V_83 -> V_91 = args -> V_91 ;
memcpy ( V_83 -> V_98 , args -> V_98 , args -> V_91 ) ;
V_34 -> V_62 -> V_99 ( V_83 , args -> V_100 ) ;
V_59 = V_34 -> V_62 -> V_101 ( V_83 ) ;
* V_59 = F_42 ( ( char * ) V_83 - ( char * ) V_46 ) ;
if ( V_77 )
F_28 ( V_34 , V_46 , & V_72 ) ;
if ( V_72 )
F_43 ( V_32 , V_34 , V_4 ) ;
F_44 ( V_32 , V_4 ) ;
F_45 ( V_32 , V_34 , V_4 , V_83 ) ;
F_46 ( V_34 , V_4 ) ;
return 0 ;
}
static void
F_41 (
T_10 * V_32 ,
struct V_3 * V_4 ,
int V_102 ,
int V_103 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_4 * V_50 ;
T_5 * V_48 ;
V_48 = F_31 ( V_32 -> V_104 , V_46 ) ;
V_50 = F_32 ( V_48 ) ;
F_47 ( V_32 , V_4 , ( V_71 ) ( ( char * ) & V_50 [ V_102 ] - ( char * ) V_46 ) ,
( V_71 ) ( ( char * ) & V_50 [ V_103 + 1 ] - ( char * ) V_46 - 1 ) ) ;
}
static void
F_44 (
T_10 * V_32 ,
struct V_3 * V_4 )
{
T_3 * V_46 = V_4 -> V_11 ;
T_5 * V_48 ;
V_48 = F_31 ( V_32 -> V_104 , V_46 ) ;
F_47 ( V_32 , V_4 , ( V_71 ) ( ( char * ) V_48 - ( char * ) V_46 ) ,
( V_71 ) ( ( char * ) ( V_48 + 1 ) - ( char * ) V_46 - 1 ) ) ;
}
int
F_48 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_83 ;
T_7 * V_34 ;
int V_105 ;
int error ;
T_9 * V_6 ;
F_49 ( args ) ;
if ( ( error = F_50 ( args , & V_4 , & V_105 ) ) )
return error ;
V_34 = args -> V_34 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
F_46 ( V_34 , V_4 ) ;
V_48 = F_31 ( V_6 , V_46 ) ;
V_50 = F_32 ( V_48 ) ;
V_83 = ( T_6 * ) ( ( char * ) V_46 +
F_51 ( V_6 , F_24 ( V_50 [ V_105 ] . V_80 ) ) ) ;
args -> V_97 = F_7 ( V_83 -> V_97 ) ;
args -> V_100 = V_34 -> V_62 -> V_106 ( V_83 ) ;
error = F_52 ( args , V_83 -> V_98 , V_83 -> V_91 ) ;
F_33 ( args -> V_89 , V_4 ) ;
return F_34 ( error ) ;
}
static int
F_50 (
T_2 * args ,
struct V_3 * * V_35 ,
int * V_107 )
{
T_11 V_108 ;
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_83 ;
T_7 * V_34 ;
int error ;
T_8 V_84 ;
int V_85 ;
int V_86 ;
int V_88 ;
T_9 * V_6 ;
T_10 * V_32 ;
enum V_109 V_110 ;
V_34 = args -> V_34 ;
V_32 = args -> V_89 ;
V_6 = V_34 -> V_36 ;
error = F_17 ( V_32 , V_34 , & V_4 ) ;
if ( error )
return error ;
V_46 = V_4 -> V_11 ;
F_46 ( V_34 , V_4 ) ;
V_48 = F_31 ( V_6 , V_46 ) ;
V_50 = F_32 ( V_48 ) ;
for ( V_86 = 0 , V_85 = F_24 ( V_48 -> V_79 ) - 1 ; ; ) {
ASSERT ( V_86 <= V_85 ) ;
V_88 = ( V_86 + V_85 ) >> 1 ;
if ( ( V_84 = F_24 ( V_50 [ V_88 ] . V_96 ) ) == args -> V_96 )
break;
if ( V_84 < args -> V_96 )
V_86 = V_88 + 1 ;
else
V_85 = V_88 - 1 ;
if ( V_86 > V_85 ) {
ASSERT ( args -> V_92 & V_111 ) ;
F_33 ( V_32 , V_4 ) ;
return F_34 ( V_112 ) ;
}
}
while ( V_88 > 0 && F_24 ( V_50 [ V_88 - 1 ] . V_96 ) == args -> V_96 ) {
V_88 -- ;
}
do {
if ( ( V_108 = F_24 ( V_50 [ V_88 ] . V_80 ) ) == V_81 )
continue;
V_83 = ( T_6 * )
( ( char * ) V_46 + F_51 ( V_6 , V_108 ) ) ;
V_110 = V_6 -> V_113 -> V_114 ( args , V_83 -> V_98 , V_83 -> V_91 ) ;
if ( V_110 != V_115 && V_110 != args -> V_116 ) {
args -> V_116 = V_110 ;
* V_35 = V_4 ;
* V_107 = V_88 ;
if ( V_110 == V_117 )
return 0 ;
}
} while ( ++ V_88 < F_24 ( V_48 -> V_79 ) &&
F_24 ( V_50 [ V_88 ] . V_96 ) == V_84 );
ASSERT ( args -> V_92 & V_111 ) ;
if ( args -> V_116 == V_118 )
return 0 ;
F_33 ( V_32 , V_4 ) ;
return F_34 ( V_112 ) ;
}
int
F_53 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_83 ;
T_7 * V_34 ;
int V_105 ;
int error ;
T_9 * V_6 ;
int V_72 ;
int V_77 ;
T_12 V_119 ;
int V_120 ;
T_10 * V_32 ;
F_54 ( args ) ;
if ( ( error = F_50 ( args , & V_4 , & V_105 ) ) ) {
return error ;
}
V_34 = args -> V_34 ;
V_32 = args -> V_89 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
V_48 = F_31 ( V_6 , V_46 ) ;
V_50 = F_32 ( V_48 ) ;
V_83 = ( T_6 * )
( ( char * ) V_46 + F_51 ( V_6 , F_24 ( V_50 [ V_105 ] . V_80 ) ) ) ;
V_72 = V_77 = 0 ;
F_27 ( V_32 , V_34 , V_4 ,
( V_82 ) ( ( char * ) V_83 - ( char * ) V_46 ) ,
V_34 -> V_62 -> V_90 ( V_83 -> V_91 ) , & V_72 , & V_77 ) ;
F_26 ( & V_48 -> V_64 , 1 ) ;
F_44 ( V_32 , V_4 ) ;
V_50 [ V_105 ] . V_80 = F_5 ( V_81 ) ;
F_41 ( V_32 , V_4 , V_105 , V_105 ) ;
if ( V_77 )
F_28 ( V_34 , V_46 , & V_72 ) ;
if ( V_72 )
F_43 ( V_32 , V_34 , V_4 ) ;
F_46 ( V_34 , V_4 ) ;
V_120 = F_55 ( V_34 , V_46 , & V_119 ) ;
if ( V_120 > F_56 ( V_34 ) )
return 0 ;
return F_57 ( args , V_4 , V_120 , & V_119 ) ;
}
int
F_58 (
T_2 * args )
{
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_83 ;
T_7 * V_34 ;
int V_105 ;
int error ;
T_9 * V_6 ;
F_59 ( args ) ;
if ( ( error = F_50 ( args , & V_4 , & V_105 ) ) ) {
return error ;
}
V_34 = args -> V_34 ;
V_6 = V_34 -> V_36 ;
V_46 = V_4 -> V_11 ;
V_48 = F_31 ( V_6 , V_46 ) ;
V_50 = F_32 ( V_48 ) ;
V_83 = ( T_6 * )
( ( char * ) V_46 + F_51 ( V_6 , F_24 ( V_50 [ V_105 ] . V_80 ) ) ) ;
ASSERT ( F_7 ( V_83 -> V_97 ) != args -> V_97 ) ;
V_83 -> V_97 = F_15 ( args -> V_97 ) ;
V_34 -> V_62 -> V_99 ( V_83 , args -> V_100 ) ;
F_45 ( args -> V_89 , V_34 , V_4 , V_83 ) ;
F_46 ( V_34 , V_4 ) ;
return 0 ;
}
static int
F_60 (
const void * V_121 ,
const void * V_122 )
{
const T_4 * V_123 ;
const T_4 * V_124 ;
V_123 = V_121 ;
V_124 = V_122 ;
return F_24 ( V_123 -> V_96 ) < F_24 ( V_124 -> V_96 ) ? - 1 :
( F_24 ( V_123 -> V_96 ) > F_24 ( V_124 -> V_96 ) ? 1 : 0 ) ;
}
int
F_61 (
T_2 * args ,
struct V_3 * V_125 ,
struct V_3 * V_126 )
{
T_1 * V_127 ;
T_3 * V_46 ;
T_5 * V_48 ;
T_7 * V_34 ;
V_66 * V_60 ;
int error ;
int V_128 ;
T_13 * V_129 ;
T_4 * V_130 ;
T_14 * V_131 ;
T_9 * V_6 ;
int V_72 ;
int V_77 ;
T_12 V_119 ;
int V_120 ;
T_1 * V_59 ;
int V_132 ;
T_10 * V_32 ;
struct V_49 * V_133 ;
struct V_134 V_135 ;
F_62 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_89 ;
V_6 = V_34 -> V_36 ;
V_129 = V_125 -> V_11 ;
V_34 -> V_62 -> V_136 ( & V_135 , V_129 ) ;
V_133 = V_34 -> V_62 -> V_137 ( V_129 ) ;
V_131 = F_63 ( V_6 , V_129 ) ;
ASSERT ( V_135 . V_13 == V_138 ||
V_135 . V_13 == V_139 ) ;
while ( V_34 -> V_140 . V_141 > V_6 -> V_142 ) {
int V_143 ;
V_143 = V_34 -> V_62 -> V_144 ;
V_127 = F_64 ( V_131 ) ;
if ( F_23 ( V_127 [ F_24 ( V_131 -> V_145 ) - 1 ] ) ==
V_6 -> V_142 - V_143 ) {
if ( ( error =
F_65 ( args , V_125 ,
( V_146 ) ( F_24 ( V_131 -> V_145 ) - 1 ) ) ) )
return error ;
} else
return 0 ;
}
if ( ! V_126 ) {
error = F_66 ( V_32 , V_34 , V_6 -> V_38 , - 1 , & V_126 ) ;
if ( error )
return error ;
}
V_46 = V_126 -> V_11 ;
ASSERT ( V_46 -> V_13 == F_5 ( V_147 ) ||
V_46 -> V_13 == F_5 ( V_148 ) ) ;
V_120 = ( V_71 ) sizeof( T_5 ) +
( V_71 ) sizeof( * V_130 ) * ( V_135 . V_79 - V_135 . V_64 ) ;
V_59 = ( T_1 * ) ( ( char * ) V_46 + V_6 -> V_142 ) - 1 ;
V_60 = ( V_66 * ) ( ( char * ) V_46 + F_23 ( * V_59 ) ) ;
if ( F_23 ( V_60 -> V_69 ) != V_70 ||
F_23 ( V_60 -> V_65 ) < V_120 )
return 0 ;
F_20 ( V_6 , V_32 , V_126 , V_34 ) ;
V_72 = 1 ;
V_77 = 0 ;
F_37 ( V_32 , V_34 , V_126 , V_60 , V_6 -> V_142 - V_120 , V_120 ,
& V_72 , & V_77 ) ;
V_48 = F_31 ( V_6 , V_46 ) ;
V_48 -> V_79 = F_5 ( V_135 . V_79 - V_135 . V_64 ) ;
V_48 -> V_64 = 0 ;
F_44 ( V_32 , V_126 ) ;
V_130 = F_32 ( V_48 ) ;
for ( V_128 = V_132 = 0 ; V_128 < V_135 . V_79 ; V_128 ++ ) {
if ( V_133 [ V_128 ] . V_80 == F_5 ( V_81 ) )
continue;
V_130 [ V_132 ++ ] = V_133 [ V_128 ] ;
}
ASSERT ( V_132 == F_24 ( V_48 -> V_79 ) ) ;
F_41 ( V_32 , V_126 , 0 , F_24 ( V_48 -> V_79 ) - 1 ) ;
if ( V_77 )
F_28 ( V_34 , V_46 , & V_72 ) ;
if ( V_72 )
F_43 ( V_32 , V_34 , V_126 ) ;
error = F_67 ( args , V_6 -> V_149 , V_125 ) ;
if ( error )
return error ;
V_120 = F_55 ( V_34 , V_46 , & V_119 ) ;
if ( V_120 > F_56 ( V_34 ) )
return 0 ;
return F_57 ( args , V_126 , V_120 , & V_119 ) ;
}
int
F_68 (
T_2 * args )
{
V_146 V_17 ;
T_3 * V_46 ;
T_4 * V_50 ;
struct V_3 * V_4 ;
T_5 * V_48 ;
T_6 * V_83 ;
T_7 * V_34 ;
int V_150 ;
V_66 * V_60 ;
int V_151 ;
int error ;
int V_152 ;
T_9 * V_6 ;
int V_72 ;
int V_77 ;
int V_153 ;
int V_67 ;
T_15 * V_154 ;
T_12 * V_155 ;
T_12 * V_156 ;
T_1 * V_59 ;
T_10 * V_32 ;
struct V_157 V_98 ;
struct V_158 * V_159 ;
F_69 ( args ) ;
V_34 = args -> V_34 ;
V_32 = args -> V_89 ;
V_6 = V_34 -> V_36 ;
V_159 = F_70 ( V_34 , V_39 ) ;
ASSERT ( V_159 -> V_160 & V_161 ) ;
if ( V_34 -> V_140 . V_141 < F_71 ( T_12 , V_162 ) ) {
ASSERT ( F_72 ( V_6 ) ) ;
return F_34 ( V_163 ) ;
}
V_155 = ( T_12 * ) V_159 -> V_164 . V_165 ;
ASSERT ( V_159 -> V_166 == V_34 -> V_140 . V_141 ) ;
ASSERT ( V_159 -> V_164 . V_165 != NULL ) ;
ASSERT ( V_34 -> V_140 . V_141 >= F_73 ( V_155 -> V_167 ) ) ;
ASSERT ( V_34 -> V_140 . V_168 == 0 ) ;
V_156 = F_74 ( V_159 -> V_166 , V_169 ) ;
memcpy ( V_156 , V_155 , V_159 -> V_166 ) ;
F_75 ( V_34 , - V_159 -> V_166 , V_39 ) ;
F_76 ( V_34 , V_39 ) ;
V_34 -> V_140 . V_141 = 0 ;
error = F_77 ( args , V_170 , & V_17 ) ;
if ( error ) {
F_78 ( V_156 ) ;
return error ;
}
error = F_79 ( args , V_17 , & V_4 ) ;
if ( error ) {
F_78 ( V_156 ) ;
return error ;
}
F_20 ( V_6 , V_32 , V_4 , V_34 ) ;
V_46 = V_4 -> V_11 ;
V_152 = ( V_71 ) sizeof( * V_48 ) +
( V_156 -> V_79 + 2 ) * ( V_71 ) sizeof( T_4 ) ;
V_60 = V_34 -> V_62 -> V_171 ( V_46 ) ;
V_72 = V_77 = 0 ;
F_37 ( V_32 , V_34 , V_4 , V_60 , V_6 -> V_142 - V_152 , V_152 , & V_72 ,
& V_77 ) ;
ASSERT ( V_77 == 0 ) ;
V_48 = F_31 ( V_6 , V_46 ) ;
V_48 -> V_79 = F_5 ( V_156 -> V_79 + 2 ) ;
V_48 -> V_64 = 0 ;
V_50 = F_32 ( V_48 ) ;
V_151 = ( V_71 ) ( ( char * ) V_50 - ( char * ) V_46 ) ;
F_37 ( V_32 , V_34 , V_4 , V_60 ,
( V_82 ) ( ( char * ) V_60 - ( char * ) V_46 ) ,
F_23 ( V_60 -> V_65 ) , & V_72 , & V_77 ) ;
V_83 = V_34 -> V_62 -> V_172 ( V_46 ) ;
V_83 -> V_97 = F_15 ( V_34 -> V_44 ) ;
V_83 -> V_91 = 1 ;
V_83 -> V_98 [ 0 ] = '.' ;
V_34 -> V_62 -> V_99 ( V_83 , V_173 ) ;
V_59 = V_34 -> V_62 -> V_101 ( V_83 ) ;
* V_59 = F_42 ( ( char * ) V_83 - ( char * ) V_46 ) ;
F_45 ( V_32 , V_34 , V_4 , V_83 ) ;
V_50 [ 0 ] . V_96 = F_5 ( V_1 ) ;
V_50 [ 0 ] . V_80 = F_5 ( F_40 ( V_6 ,
( char * ) V_83 - ( char * ) V_46 ) ) ;
V_83 = V_34 -> V_62 -> V_174 ( V_46 ) ;
V_83 -> V_97 = F_15 ( V_34 -> V_62 -> V_175 ( V_156 ) ) ;
V_83 -> V_91 = 2 ;
V_83 -> V_98 [ 0 ] = V_83 -> V_98 [ 1 ] = '.' ;
V_34 -> V_62 -> V_99 ( V_83 , V_173 ) ;
V_59 = V_34 -> V_62 -> V_101 ( V_83 ) ;
* V_59 = F_42 ( ( char * ) V_83 - ( char * ) V_46 ) ;
F_45 ( V_32 , V_34 , V_4 , V_83 ) ;
V_50 [ 1 ] . V_96 = F_5 ( V_2 ) ;
V_50 [ 1 ] . V_80 = F_5 ( F_40 ( V_6 ,
( char * ) V_83 - ( char * ) V_46 ) ) ;
V_67 = V_34 -> V_62 -> V_176 ;
V_152 = 0 ;
if ( ! V_156 -> V_79 )
V_154 = NULL ;
else
V_154 = F_80 ( V_156 ) ;
while ( V_67 < V_151 ) {
if ( V_154 == NULL )
V_153 = V_151 ;
else
V_153 = F_81 ( V_154 ) ;
if ( V_67 < V_153 ) {
V_60 = ( V_66 * ) ( ( char * ) V_46 + V_67 ) ;
V_60 -> V_69 = F_42 ( V_70 ) ;
V_60 -> V_65 = F_42 ( V_153 - V_67 ) ;
* F_82 ( V_60 ) = F_42 (
( ( char * ) V_60 - ( char * ) V_46 ) ) ;
F_83 ( V_32 , V_4 , V_60 ) ;
F_84 ( V_46 ,
V_34 -> V_62 -> V_63 ( V_46 ) ,
V_60 , & V_150 ) ;
V_67 += F_23 ( V_60 -> V_65 ) ;
continue;
}
V_83 = ( T_6 * ) ( ( char * ) V_46 + V_153 ) ;
V_83 -> V_97 = F_15 ( V_34 -> V_62 -> V_177 ( V_156 , V_154 ) ) ;
V_83 -> V_91 = V_154 -> V_91 ;
V_34 -> V_62 -> V_99 ( V_83 , V_34 -> V_62 -> V_178 ( V_154 ) ) ;
memcpy ( V_83 -> V_98 , V_154 -> V_98 , V_83 -> V_91 ) ;
V_59 = V_34 -> V_62 -> V_101 ( V_83 ) ;
* V_59 = F_42 ( ( char * ) V_83 - ( char * ) V_46 ) ;
F_45 ( V_32 , V_34 , V_4 , V_83 ) ;
V_98 . V_98 = V_154 -> V_98 ;
V_98 . V_56 = V_154 -> V_91 ;
V_50 [ 2 + V_152 ] . V_96 = F_5 ( V_6 -> V_113 ->
V_179 ( & V_98 ) ) ;
V_50 [ 2 + V_152 ] . V_80 = F_5 ( F_40 ( V_6 ,
( char * ) V_83 - ( char * ) V_46 ) ) ;
V_67 = ( int ) ( ( char * ) ( V_59 + 1 ) - ( char * ) V_46 ) ;
if ( ++ V_152 == V_156 -> V_79 )
V_154 = NULL ;
else
V_154 = V_34 -> V_62 -> V_180 ( V_156 , V_154 ) ;
}
F_78 ( V_156 ) ;
F_85 ( V_50 , F_24 ( V_48 -> V_79 ) , sizeof( * V_50 ) , F_60 ) ;
ASSERT ( V_77 == 0 ) ;
F_41 ( V_32 , V_4 , 0 , F_24 ( V_48 -> V_79 ) - 1 ) ;
F_44 ( V_32 , V_4 ) ;
F_46 ( V_34 , V_4 ) ;
return 0 ;
}
