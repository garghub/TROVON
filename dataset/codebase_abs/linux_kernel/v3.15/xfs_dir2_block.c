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
F_11 ( V_4 , V_21 ) ;
else if ( ! F_3 ( V_4 ) )
F_11 ( V_4 , V_22 ) ;
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
F_11 ( V_4 , V_22 ) ;
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
V_36 = F_17 ( V_31 , V_33 , V_6 -> V_37 , - 1 , V_34 ,
V_38 , & V_39 ) ;
if ( ! V_36 && V_31 )
F_18 ( V_31 , * V_34 , V_40 ) ;
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
V_4 -> V_41 = & V_39 ;
F_18 ( V_31 , V_4 , V_40 ) ;
if ( F_4 ( & V_6 -> V_12 ) ) {
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_13 = F_5 ( V_14 ) ;
V_10 -> V_17 = F_14 ( V_4 -> V_18 ) ;
V_10 -> V_42 = F_14 ( V_33 -> V_43 ) ;
F_20 ( & V_10 -> V_15 , & V_6 -> V_12 . V_16 ) ;
return;
}
V_10 -> V_13 = F_5 ( V_19 ) ;
}
static void
F_21 (
struct V_32 * V_33 ,
struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
T_1 * * V_50 ,
struct V_51 * * V_52 ,
struct V_51 * * V_53 ,
int * V_54 ,
int V_55 )
{
struct V_56 * V_57 ;
T_1 * V_58 = NULL ;
struct V_51 * V_59 = NULL ;
struct V_51 * V_60 = NULL ;
* V_54 = 0 ;
V_57 = V_33 -> V_61 -> V_62 ( V_45 ) ;
if ( V_47 -> V_63 ) {
if ( F_22 ( V_57 [ 0 ] . V_64 ) >= V_55 ) {
V_59 = ( V_65 * )
( ( char * ) V_45 + F_22 ( V_57 [ 0 ] . V_66 ) ) ;
goto V_67;
}
* V_54 = 1 ;
V_58 = ( T_1 * ) V_49 - 1 ;
V_59 = ( V_65 * ) ( ( char * ) V_45 + F_22 ( * V_58 ) ) ;
if ( F_22 ( V_59 -> V_68 ) == V_69 ) {
if ( F_22 ( V_59 -> V_64 ) + ( F_23 ( V_47 -> V_63 ) - 1 ) *
( V_70 ) sizeof( * V_49 ) < V_55 )
V_59 = NULL ;
} else if ( ( F_23 ( V_47 -> V_63 ) - 1 ) * ( V_70 ) sizeof( * V_49 ) < V_55 )
V_59 = NULL ;
else
V_59 = ( V_65 * ) V_49 ;
goto V_67;
}
V_58 = ( T_1 * ) V_49 - 1 ;
V_60 = ( V_65 * ) ( ( char * ) V_45 + F_22 ( * V_58 ) ) ;
if ( F_22 ( V_60 -> V_68 ) == V_69 ) {
V_59 = ( V_65 * )
( ( char * ) V_45 + F_22 ( V_57 [ 0 ] . V_66 ) ) ;
if ( V_59 != V_60 ) {
if ( F_22 ( V_59 -> V_64 ) < V_55 )
V_59 = NULL ;
goto V_67;
}
if ( F_22 ( V_59 -> V_64 ) < V_55 + ( V_70 ) sizeof( * V_49 ) ) {
if ( F_22 ( V_57 [ 1 ] . V_64 ) >= V_55 )
V_59 = ( V_65 * )
( ( char * ) V_45 + F_22 ( V_57 [ 1 ] . V_66 ) ) ;
else
V_59 = NULL ;
}
}
V_67:
* V_50 = V_58 ;
* V_52 = V_59 ;
* V_53 = V_60 ;
}
static void
F_24 (
struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_3 * V_4 ,
struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
int * V_71 ,
int * V_72 ,
int * V_73 )
{
int V_74 ;
int V_75 ;
int V_76 = 0 ;
int V_77 ;
V_74 = V_75 = F_23 ( V_47 -> V_78 ) - 1 ;
V_77 = * V_72 = - 1 ;
for (; V_74 >= 0 ; V_74 -- ) {
if ( V_49 [ V_74 ] . V_79 == F_5 ( V_80 ) ) {
if ( V_77 == - 1 )
V_77 = V_75 ;
else {
if ( * V_72 == - 1 )
* V_72 = V_75 ;
continue;
}
}
if ( V_74 < V_75 )
V_49 [ V_75 ] = V_49 [ V_74 ] ;
V_75 -- ;
}
* V_73 = V_75 + 1 - ( F_23 ( V_47 -> V_63 ) - 1 ) ;
* V_72 -= F_23 ( V_47 -> V_63 ) - 1 ;
F_25 ( & V_47 -> V_78 , - ( F_23 ( V_47 -> V_63 ) - 1 ) ) ;
F_26 ( V_31 , V_33 , V_4 ,
( V_81 ) ( ( char * ) V_49 - ( char * ) V_45 ) ,
( V_81 ) ( ( F_23 ( V_47 -> V_63 ) - 1 ) * sizeof( * V_49 ) ) ,
V_71 , & V_76 ) ;
V_49 += F_23 ( V_47 -> V_63 ) - 1 ;
V_47 -> V_63 = F_5 ( 1 ) ;
if ( V_76 )
F_27 ( V_33 , V_45 , V_71 ) ;
}
int
F_28 (
T_2 * args )
{
T_3 * V_45 ;
T_4 * V_49 ;
struct V_3 * V_4 ;
T_5 * V_47 ;
int V_54 ;
T_6 * V_82 ;
T_7 * V_33 ;
V_65 * V_59 ;
int error ;
V_65 * V_60 = NULL ;
T_8 V_83 ;
int V_84 ;
int V_77 ;
int V_72 = 0 ;
int V_73 = 0 ;
int V_55 ;
int V_85 ;
int V_86 ;
int V_87 = 0 ;
T_9 * V_6 ;
int V_71 ;
int V_76 ;
T_1 * V_58 ;
T_10 * V_31 ;
F_29 ( args ) ;
V_33 = args -> V_33 ;
V_31 = args -> V_88 ;
V_6 = V_33 -> V_35 ;
error = F_16 ( V_31 , V_33 , & V_4 ) ;
if ( error )
return error ;
V_55 = V_33 -> V_61 -> V_89 ( args -> V_90 ) ;
V_45 = V_4 -> V_11 ;
V_47 = F_30 ( V_6 , V_45 ) ;
V_49 = F_31 ( V_47 ) ;
F_21 ( V_33 , V_45 , V_47 , V_49 , & V_58 , & V_59 ,
& V_60 , & V_54 , V_55 ) ;
if ( args -> V_91 & V_92 ) {
F_32 ( V_31 , V_4 ) ;
if ( ! V_59 )
return F_33 ( V_93 ) ;
return 0 ;
}
if ( ! V_59 ) {
if ( args -> V_94 == 0 )
return F_33 ( V_93 ) ;
error = F_34 ( args , V_4 ) ;
if ( error )
return error ;
return F_35 ( args ) ;
}
V_71 = V_76 = 0 ;
if ( V_54 ) {
F_24 ( V_31 , V_33 , V_4 , V_45 , V_47 , V_49 , & V_71 ,
& V_72 , & V_73 ) ;
V_49 = F_31 ( V_47 ) ;
} else if ( V_47 -> V_63 ) {
V_73 = F_23 ( V_47 -> V_78 ) ;
V_72 = - 1 ;
}
for ( V_85 = 0 , V_84 = F_23 ( V_47 -> V_78 ) - 1 ; V_85 <= V_84 ; ) {
V_87 = ( V_85 + V_84 ) >> 1 ;
if ( ( V_83 = F_23 ( V_49 [ V_87 ] . V_95 ) ) == args -> V_95 )
break;
if ( V_83 < args -> V_95 )
V_85 = V_87 + 1 ;
else
V_84 = V_87 - 1 ;
}
while ( V_87 >= 0 && F_23 ( V_49 [ V_87 ] . V_95 ) >= args -> V_95 ) {
V_87 -- ;
}
if ( ! V_47 -> V_63 ) {
F_36 ( V_31 , V_33 , V_4 , V_60 ,
( V_81 )
( ( char * ) V_60 - ( char * ) V_45 + F_22 ( V_60 -> V_64 ) -
sizeof( * V_49 ) ) ,
( V_81 ) sizeof( * V_49 ) ,
& V_71 , & V_76 ) ;
F_25 ( & V_47 -> V_78 , 1 ) ;
if ( V_76 ) {
F_27 ( V_33 , V_45 , & V_71 ) ;
V_76 = 0 ;
}
V_49 -- ;
V_87 ++ ;
if ( V_87 )
memmove ( V_49 , & V_49 [ 1 ] , V_87 * sizeof( * V_49 ) ) ;
V_73 = 0 ;
V_72 = V_87 ;
}
else {
for ( V_86 = V_87 ;
V_86 >= 0 &&
V_49 [ V_86 ] . V_79 !=
F_5 ( V_80 ) ;
V_86 -- )
continue;
for ( V_77 = V_87 + 1 ;
V_77 < F_23 ( V_47 -> V_78 ) &&
V_49 [ V_77 ] . V_79 !=
F_5 ( V_80 ) &&
( V_86 < 0 || V_87 - V_86 > V_77 - V_87 ) ;
V_77 ++ )
continue;
if ( V_86 >= 0 &&
( V_77 == F_23 ( V_47 -> V_78 ) ||
V_87 - V_86 <= V_77 - V_87 ) ) {
if ( V_87 - V_86 )
memmove ( & V_49 [ V_86 ] , & V_49 [ V_86 + 1 ] ,
( V_87 - V_86 ) * sizeof( * V_49 ) ) ;
V_73 = F_37 ( V_86 , V_73 ) ;
V_72 = F_38 ( V_87 , V_72 ) ;
}
else {
ASSERT ( V_77 < F_23 ( V_47 -> V_78 ) ) ;
V_87 ++ ;
if ( V_77 - V_87 )
memmove ( & V_49 [ V_87 + 1 ] , & V_49 [ V_87 ] ,
( V_77 - V_87 ) * sizeof( * V_49 ) ) ;
V_73 = F_37 ( V_87 , V_73 ) ;
V_72 = F_38 ( V_77 , V_72 ) ;
}
F_25 ( & V_47 -> V_63 , - 1 ) ;
}
V_82 = ( T_6 * ) V_59 ;
V_49 [ V_87 ] . V_95 = F_5 ( args -> V_95 ) ;
V_49 [ V_87 ] . V_79 = F_5 ( F_39 ( V_6 ,
( char * ) V_82 - ( char * ) V_45 ) ) ;
F_40 ( V_31 , V_4 , V_73 , V_72 ) ;
F_36 ( V_31 , V_33 , V_4 , V_59 ,
( V_81 ) ( ( char * ) V_59 - ( char * ) V_45 ) ,
( V_81 ) V_55 , & V_71 , & V_76 ) ;
V_82 -> V_96 = F_14 ( args -> V_96 ) ;
V_82 -> V_90 = args -> V_90 ;
memcpy ( V_82 -> V_97 , args -> V_97 , args -> V_90 ) ;
V_33 -> V_61 -> V_98 ( V_82 , args -> V_99 ) ;
V_58 = V_33 -> V_61 -> V_100 ( V_82 ) ;
* V_58 = F_41 ( ( char * ) V_82 - ( char * ) V_45 ) ;
if ( V_76 )
F_27 ( V_33 , V_45 , & V_71 ) ;
if ( V_71 )
F_42 ( V_31 , V_33 , V_4 ) ;
F_43 ( V_31 , V_4 ) ;
F_44 ( V_31 , V_33 , V_4 , V_82 ) ;
F_45 ( V_33 , V_4 ) ;
return 0 ;
}
static void
F_40 (
T_10 * V_31 ,
struct V_3 * V_4 ,
int V_101 ,
int V_102 )
{
T_3 * V_45 = V_4 -> V_11 ;
T_4 * V_49 ;
T_5 * V_47 ;
V_47 = F_30 ( V_31 -> V_103 , V_45 ) ;
V_49 = F_31 ( V_47 ) ;
F_46 ( V_31 , V_4 , ( V_70 ) ( ( char * ) & V_49 [ V_101 ] - ( char * ) V_45 ) ,
( V_70 ) ( ( char * ) & V_49 [ V_102 + 1 ] - ( char * ) V_45 - 1 ) ) ;
}
static void
F_43 (
T_10 * V_31 ,
struct V_3 * V_4 )
{
T_3 * V_45 = V_4 -> V_11 ;
T_5 * V_47 ;
V_47 = F_30 ( V_31 -> V_103 , V_45 ) ;
F_46 ( V_31 , V_4 , ( V_70 ) ( ( char * ) V_47 - ( char * ) V_45 ) ,
( V_70 ) ( ( char * ) ( V_47 + 1 ) - ( char * ) V_45 - 1 ) ) ;
}
int
F_47 (
T_2 * args )
{
T_3 * V_45 ;
T_4 * V_49 ;
struct V_3 * V_4 ;
T_5 * V_47 ;
T_6 * V_82 ;
T_7 * V_33 ;
int V_104 ;
int error ;
T_9 * V_6 ;
F_48 ( args ) ;
if ( ( error = F_49 ( args , & V_4 , & V_104 ) ) )
return error ;
V_33 = args -> V_33 ;
V_6 = V_33 -> V_35 ;
V_45 = V_4 -> V_11 ;
F_45 ( V_33 , V_4 ) ;
V_47 = F_30 ( V_6 , V_45 ) ;
V_49 = F_31 ( V_47 ) ;
V_82 = ( T_6 * ) ( ( char * ) V_45 +
F_50 ( V_6 , F_23 ( V_49 [ V_104 ] . V_79 ) ) ) ;
args -> V_96 = F_7 ( V_82 -> V_96 ) ;
args -> V_99 = V_33 -> V_61 -> V_105 ( V_82 ) ;
error = F_51 ( args , V_82 -> V_97 , V_82 -> V_90 ) ;
F_32 ( args -> V_88 , V_4 ) ;
return F_33 ( error ) ;
}
static int
F_49 (
T_2 * args ,
struct V_3 * * V_34 ,
int * V_106 )
{
T_11 V_107 ;
T_3 * V_45 ;
T_4 * V_49 ;
struct V_3 * V_4 ;
T_5 * V_47 ;
T_6 * V_82 ;
T_7 * V_33 ;
int error ;
T_8 V_83 ;
int V_84 ;
int V_85 ;
int V_87 ;
T_9 * V_6 ;
T_10 * V_31 ;
enum V_108 V_109 ;
V_33 = args -> V_33 ;
V_31 = args -> V_88 ;
V_6 = V_33 -> V_35 ;
error = F_16 ( V_31 , V_33 , & V_4 ) ;
if ( error )
return error ;
V_45 = V_4 -> V_11 ;
F_45 ( V_33 , V_4 ) ;
V_47 = F_30 ( V_6 , V_45 ) ;
V_49 = F_31 ( V_47 ) ;
for ( V_85 = 0 , V_84 = F_23 ( V_47 -> V_78 ) - 1 ; ; ) {
ASSERT ( V_85 <= V_84 ) ;
V_87 = ( V_85 + V_84 ) >> 1 ;
if ( ( V_83 = F_23 ( V_49 [ V_87 ] . V_95 ) ) == args -> V_95 )
break;
if ( V_83 < args -> V_95 )
V_85 = V_87 + 1 ;
else
V_84 = V_87 - 1 ;
if ( V_85 > V_84 ) {
ASSERT ( args -> V_91 & V_110 ) ;
F_32 ( V_31 , V_4 ) ;
return F_33 ( V_111 ) ;
}
}
while ( V_87 > 0 && F_23 ( V_49 [ V_87 - 1 ] . V_95 ) == args -> V_95 ) {
V_87 -- ;
}
do {
if ( ( V_107 = F_23 ( V_49 [ V_87 ] . V_79 ) ) == V_80 )
continue;
V_82 = ( T_6 * )
( ( char * ) V_45 + F_50 ( V_6 , V_107 ) ) ;
V_109 = V_6 -> V_112 -> V_113 ( args , V_82 -> V_97 , V_82 -> V_90 ) ;
if ( V_109 != V_114 && V_109 != args -> V_115 ) {
args -> V_115 = V_109 ;
* V_34 = V_4 ;
* V_106 = V_87 ;
if ( V_109 == V_116 )
return 0 ;
}
} while ( ++ V_87 < F_23 ( V_47 -> V_78 ) &&
F_23 ( V_49 [ V_87 ] . V_95 ) == V_83 );
ASSERT ( args -> V_91 & V_110 ) ;
if ( args -> V_115 == V_117 )
return 0 ;
F_32 ( V_31 , V_4 ) ;
return F_33 ( V_111 ) ;
}
int
F_52 (
T_2 * args )
{
T_3 * V_45 ;
T_4 * V_49 ;
struct V_3 * V_4 ;
T_5 * V_47 ;
T_6 * V_82 ;
T_7 * V_33 ;
int V_104 ;
int error ;
T_9 * V_6 ;
int V_71 ;
int V_76 ;
T_12 V_118 ;
int V_119 ;
T_10 * V_31 ;
F_53 ( args ) ;
if ( ( error = F_49 ( args , & V_4 , & V_104 ) ) ) {
return error ;
}
V_33 = args -> V_33 ;
V_31 = args -> V_88 ;
V_6 = V_33 -> V_35 ;
V_45 = V_4 -> V_11 ;
V_47 = F_30 ( V_6 , V_45 ) ;
V_49 = F_31 ( V_47 ) ;
V_82 = ( T_6 * )
( ( char * ) V_45 + F_50 ( V_6 , F_23 ( V_49 [ V_104 ] . V_79 ) ) ) ;
V_71 = V_76 = 0 ;
F_26 ( V_31 , V_33 , V_4 ,
( V_81 ) ( ( char * ) V_82 - ( char * ) V_45 ) ,
V_33 -> V_61 -> V_89 ( V_82 -> V_90 ) , & V_71 , & V_76 ) ;
F_25 ( & V_47 -> V_63 , 1 ) ;
F_43 ( V_31 , V_4 ) ;
V_49 [ V_104 ] . V_79 = F_5 ( V_80 ) ;
F_40 ( V_31 , V_4 , V_104 , V_104 ) ;
if ( V_76 )
F_27 ( V_33 , V_45 , & V_71 ) ;
if ( V_71 )
F_42 ( V_31 , V_33 , V_4 ) ;
F_45 ( V_33 , V_4 ) ;
V_119 = F_54 ( V_33 , V_45 , & V_118 ) ;
if ( V_119 > F_55 ( V_33 ) )
return 0 ;
return F_56 ( args , V_4 , V_119 , & V_118 ) ;
}
int
F_57 (
T_2 * args )
{
T_3 * V_45 ;
T_4 * V_49 ;
struct V_3 * V_4 ;
T_5 * V_47 ;
T_6 * V_82 ;
T_7 * V_33 ;
int V_104 ;
int error ;
T_9 * V_6 ;
F_58 ( args ) ;
if ( ( error = F_49 ( args , & V_4 , & V_104 ) ) ) {
return error ;
}
V_33 = args -> V_33 ;
V_6 = V_33 -> V_35 ;
V_45 = V_4 -> V_11 ;
V_47 = F_30 ( V_6 , V_45 ) ;
V_49 = F_31 ( V_47 ) ;
V_82 = ( T_6 * )
( ( char * ) V_45 + F_50 ( V_6 , F_23 ( V_49 [ V_104 ] . V_79 ) ) ) ;
ASSERT ( F_7 ( V_82 -> V_96 ) != args -> V_96 ) ;
V_82 -> V_96 = F_14 ( args -> V_96 ) ;
V_33 -> V_61 -> V_98 ( V_82 , args -> V_99 ) ;
F_44 ( args -> V_88 , V_33 , V_4 , V_82 ) ;
F_45 ( V_33 , V_4 ) ;
return 0 ;
}
static int
F_59 (
const void * V_120 ,
const void * V_121 )
{
const T_4 * V_122 ;
const T_4 * V_123 ;
V_122 = V_120 ;
V_123 = V_121 ;
return F_23 ( V_122 -> V_95 ) < F_23 ( V_123 -> V_95 ) ? - 1 :
( F_23 ( V_122 -> V_95 ) > F_23 ( V_123 -> V_95 ) ? 1 : 0 ) ;
}
int
F_60 (
T_2 * args ,
struct V_3 * V_124 ,
struct V_3 * V_125 )
{
T_1 * V_126 ;
T_3 * V_45 ;
T_5 * V_47 ;
T_7 * V_33 ;
V_65 * V_59 ;
int error ;
int V_127 ;
T_13 * V_128 ;
T_4 * V_129 ;
T_14 * V_130 ;
T_9 * V_6 ;
int V_71 ;
int V_76 ;
T_12 V_118 ;
int V_119 ;
T_1 * V_58 ;
int V_131 ;
T_10 * V_31 ;
struct V_48 * V_132 ;
struct V_133 V_134 ;
F_61 ( args ) ;
V_33 = args -> V_33 ;
V_31 = args -> V_88 ;
V_6 = V_33 -> V_35 ;
V_128 = V_124 -> V_11 ;
V_33 -> V_61 -> V_135 ( & V_134 , V_128 ) ;
V_132 = V_33 -> V_61 -> V_136 ( V_128 ) ;
V_130 = F_62 ( V_6 , V_128 ) ;
ASSERT ( V_134 . V_13 == V_137 ||
V_134 . V_13 == V_138 ) ;
while ( V_33 -> V_139 . V_140 > V_6 -> V_141 ) {
int V_142 ;
V_142 = V_33 -> V_61 -> V_143 ;
V_126 = F_63 ( V_130 ) ;
if ( F_22 ( V_126 [ F_23 ( V_130 -> V_144 ) - 1 ] ) ==
V_6 -> V_141 - V_142 ) {
if ( ( error =
F_64 ( args , V_124 ,
( V_145 ) ( F_23 ( V_130 -> V_144 ) - 1 ) ) ) )
return error ;
} else
return 0 ;
}
if ( ! V_125 ) {
error = F_65 ( V_31 , V_33 , V_6 -> V_37 , - 1 , & V_125 ) ;
if ( error )
return error ;
}
V_45 = V_125 -> V_11 ;
ASSERT ( V_45 -> V_13 == F_5 ( V_146 ) ||
V_45 -> V_13 == F_5 ( V_147 ) ) ;
V_119 = ( V_70 ) sizeof( T_5 ) +
( V_70 ) sizeof( * V_129 ) * ( V_134 . V_78 - V_134 . V_63 ) ;
V_58 = ( T_1 * ) ( ( char * ) V_45 + V_6 -> V_141 ) - 1 ;
V_59 = ( V_65 * ) ( ( char * ) V_45 + F_22 ( * V_58 ) ) ;
if ( F_22 ( V_59 -> V_68 ) != V_69 ||
F_22 ( V_59 -> V_64 ) < V_119 )
return 0 ;
F_19 ( V_6 , V_31 , V_125 , V_33 ) ;
V_71 = 1 ;
V_76 = 0 ;
F_36 ( V_31 , V_33 , V_125 , V_59 , V_6 -> V_141 - V_119 , V_119 ,
& V_71 , & V_76 ) ;
V_47 = F_30 ( V_6 , V_45 ) ;
V_47 -> V_78 = F_5 ( V_134 . V_78 - V_134 . V_63 ) ;
V_47 -> V_63 = 0 ;
F_43 ( V_31 , V_125 ) ;
V_129 = F_31 ( V_47 ) ;
for ( V_127 = V_131 = 0 ; V_127 < V_134 . V_78 ; V_127 ++ ) {
if ( V_132 [ V_127 ] . V_79 == F_5 ( V_80 ) )
continue;
V_129 [ V_131 ++ ] = V_132 [ V_127 ] ;
}
ASSERT ( V_131 == F_23 ( V_47 -> V_78 ) ) ;
F_40 ( V_31 , V_125 , 0 , F_23 ( V_47 -> V_78 ) - 1 ) ;
if ( V_76 )
F_27 ( V_33 , V_45 , & V_71 ) ;
if ( V_71 )
F_42 ( V_31 , V_33 , V_125 ) ;
error = F_66 ( args , V_6 -> V_148 , V_124 ) ;
if ( error )
return error ;
V_119 = F_54 ( V_33 , V_45 , & V_118 ) ;
if ( V_119 > F_55 ( V_33 ) )
return 0 ;
return F_56 ( args , V_125 , V_119 , & V_118 ) ;
}
int
F_67 (
T_2 * args )
{
V_145 V_17 ;
T_3 * V_45 ;
T_4 * V_49 ;
struct V_3 * V_4 ;
T_5 * V_47 ;
T_6 * V_82 ;
T_7 * V_33 ;
int V_149 ;
V_65 * V_59 ;
int V_150 ;
int error ;
int V_151 ;
T_9 * V_6 ;
int V_71 ;
int V_76 ;
int V_152 ;
int V_66 ;
T_15 * V_153 ;
T_12 * V_154 ;
T_12 * V_155 ;
T_1 * V_58 ;
T_10 * V_31 ;
struct V_156 V_97 ;
struct V_157 * V_158 ;
F_68 ( args ) ;
V_33 = args -> V_33 ;
V_31 = args -> V_88 ;
V_6 = V_33 -> V_35 ;
V_158 = F_69 ( V_33 , V_38 ) ;
ASSERT ( V_158 -> V_159 & V_160 ) ;
if ( V_33 -> V_139 . V_140 < F_70 ( T_12 , V_161 ) ) {
ASSERT ( F_71 ( V_6 ) ) ;
return F_33 ( V_162 ) ;
}
V_154 = ( T_12 * ) V_158 -> V_163 . V_164 ;
ASSERT ( V_158 -> V_165 == V_33 -> V_139 . V_140 ) ;
ASSERT ( V_158 -> V_163 . V_164 != NULL ) ;
ASSERT ( V_33 -> V_139 . V_140 >= F_72 ( V_154 -> V_166 ) ) ;
ASSERT ( V_33 -> V_139 . V_167 == 0 ) ;
V_155 = F_73 ( V_158 -> V_165 , V_168 ) ;
memcpy ( V_155 , V_154 , V_158 -> V_165 ) ;
F_74 ( V_33 , - V_158 -> V_165 , V_38 ) ;
F_75 ( V_33 , V_38 ) ;
V_33 -> V_139 . V_140 = 0 ;
error = F_76 ( args , V_169 , & V_17 ) ;
if ( error ) {
F_77 ( V_155 ) ;
return error ;
}
error = F_78 ( args , V_17 , & V_4 ) ;
if ( error ) {
F_77 ( V_155 ) ;
return error ;
}
F_19 ( V_6 , V_31 , V_4 , V_33 ) ;
V_45 = V_4 -> V_11 ;
V_151 = ( V_70 ) sizeof( * V_47 ) +
( V_155 -> V_78 + 2 ) * ( V_70 ) sizeof( T_4 ) ;
V_59 = V_33 -> V_61 -> V_170 ( V_45 ) ;
V_71 = V_76 = 0 ;
F_36 ( V_31 , V_33 , V_4 , V_59 , V_6 -> V_141 - V_151 , V_151 , & V_71 ,
& V_76 ) ;
ASSERT ( V_76 == 0 ) ;
V_47 = F_30 ( V_6 , V_45 ) ;
V_47 -> V_78 = F_5 ( V_155 -> V_78 + 2 ) ;
V_47 -> V_63 = 0 ;
V_49 = F_31 ( V_47 ) ;
V_150 = ( V_70 ) ( ( char * ) V_49 - ( char * ) V_45 ) ;
F_36 ( V_31 , V_33 , V_4 , V_59 ,
( V_81 ) ( ( char * ) V_59 - ( char * ) V_45 ) ,
F_22 ( V_59 -> V_64 ) , & V_71 , & V_76 ) ;
V_82 = V_33 -> V_61 -> V_171 ( V_45 ) ;
V_82 -> V_96 = F_14 ( V_33 -> V_43 ) ;
V_82 -> V_90 = 1 ;
V_82 -> V_97 [ 0 ] = '.' ;
V_33 -> V_61 -> V_98 ( V_82 , V_172 ) ;
V_58 = V_33 -> V_61 -> V_100 ( V_82 ) ;
* V_58 = F_41 ( ( char * ) V_82 - ( char * ) V_45 ) ;
F_44 ( V_31 , V_33 , V_4 , V_82 ) ;
V_49 [ 0 ] . V_95 = F_5 ( V_1 ) ;
V_49 [ 0 ] . V_79 = F_5 ( F_39 ( V_6 ,
( char * ) V_82 - ( char * ) V_45 ) ) ;
V_82 = V_33 -> V_61 -> V_173 ( V_45 ) ;
V_82 -> V_96 = F_14 ( V_33 -> V_61 -> V_174 ( V_155 ) ) ;
V_82 -> V_90 = 2 ;
V_82 -> V_97 [ 0 ] = V_82 -> V_97 [ 1 ] = '.' ;
V_33 -> V_61 -> V_98 ( V_82 , V_172 ) ;
V_58 = V_33 -> V_61 -> V_100 ( V_82 ) ;
* V_58 = F_41 ( ( char * ) V_82 - ( char * ) V_45 ) ;
F_44 ( V_31 , V_33 , V_4 , V_82 ) ;
V_49 [ 1 ] . V_95 = F_5 ( V_2 ) ;
V_49 [ 1 ] . V_79 = F_5 ( F_39 ( V_6 ,
( char * ) V_82 - ( char * ) V_45 ) ) ;
V_66 = V_33 -> V_61 -> V_175 ;
V_151 = 0 ;
if ( ! V_155 -> V_78 )
V_153 = NULL ;
else
V_153 = F_79 ( V_155 ) ;
while ( V_66 < V_150 ) {
if ( V_153 == NULL )
V_152 = V_150 ;
else
V_152 = F_80 ( V_153 ) ;
if ( V_66 < V_152 ) {
V_59 = ( V_65 * ) ( ( char * ) V_45 + V_66 ) ;
V_59 -> V_68 = F_41 ( V_69 ) ;
V_59 -> V_64 = F_41 ( V_152 - V_66 ) ;
* F_81 ( V_59 ) = F_41 (
( ( char * ) V_59 - ( char * ) V_45 ) ) ;
F_82 ( V_31 , V_4 , V_59 ) ;
F_83 ( V_45 ,
V_33 -> V_61 -> V_62 ( V_45 ) ,
V_59 , & V_149 ) ;
V_66 += F_22 ( V_59 -> V_64 ) ;
continue;
}
V_82 = ( T_6 * ) ( ( char * ) V_45 + V_152 ) ;
V_82 -> V_96 = F_14 ( V_33 -> V_61 -> V_176 ( V_155 , V_153 ) ) ;
V_82 -> V_90 = V_153 -> V_90 ;
V_33 -> V_61 -> V_98 ( V_82 , V_33 -> V_61 -> V_177 ( V_153 ) ) ;
memcpy ( V_82 -> V_97 , V_153 -> V_97 , V_82 -> V_90 ) ;
V_58 = V_33 -> V_61 -> V_100 ( V_82 ) ;
* V_58 = F_41 ( ( char * ) V_82 - ( char * ) V_45 ) ;
F_44 ( V_31 , V_33 , V_4 , V_82 ) ;
V_97 . V_97 = V_153 -> V_97 ;
V_97 . V_55 = V_153 -> V_90 ;
V_49 [ 2 + V_151 ] . V_95 = F_5 ( V_6 -> V_112 ->
V_178 ( & V_97 ) ) ;
V_49 [ 2 + V_151 ] . V_79 = F_5 ( F_39 ( V_6 ,
( char * ) V_82 - ( char * ) V_45 ) ) ;
V_66 = ( int ) ( ( char * ) ( V_58 + 1 ) - ( char * ) V_45 ) ;
if ( ++ V_151 == V_155 -> V_78 )
V_153 = NULL ;
else
V_153 = V_33 -> V_61 -> V_179 ( V_155 , V_153 ) ;
}
F_77 ( V_155 ) ;
F_84 ( V_49 , F_23 ( V_47 -> V_78 ) , sizeof( * V_49 ) , F_59 ) ;
ASSERT ( V_76 == 0 ) ;
F_40 ( V_31 , V_4 , 0 , F_23 ( V_47 -> V_78 ) - 1 ) ;
F_43 ( V_31 , V_4 ) ;
F_45 ( V_33 , V_4 ) ;
return 0 ;
}
