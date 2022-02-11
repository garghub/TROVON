STATIC int
F_1 (
struct V_1 * V_2 ,
const unsigned char * V_3 )
{
if ( ! V_3 )
return V_4 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = strlen ( ( char * ) V_3 ) ;
if ( V_2 -> V_6 >= V_7 )
return V_8 ;
return 0 ;
}
STATIC int
F_2 (
struct V_9 * V_10 )
{
if ( ! F_3 ( V_10 ) ||
( V_10 -> V_11 . V_12 == V_13 &&
V_10 -> V_11 . V_14 == 0 ) )
return 0 ;
return 1 ;
}
STATIC int
F_4 (
struct V_9 * V_10 ,
struct V_1 * V_5 ,
unsigned char * V_15 ,
int * V_16 ,
int V_17 )
{
T_1 args ;
int error ;
if ( ! F_2 ( V_10 ) )
return V_18 ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_5 = V_5 -> V_5 ;
args . V_19 = V_5 -> V_6 ;
args . V_15 = V_15 ;
args . V_20 = * V_16 ;
args . V_17 = V_17 ;
args . V_21 = F_5 ( args . V_5 , args . V_19 ) ;
args . V_22 = V_10 ;
args . V_23 = V_24 ;
if ( V_10 -> V_11 . V_12 == V_25 ) {
error = F_6 ( & args ) ;
} else if ( F_7 ( V_10 , V_24 ) ) {
error = F_8 ( & args ) ;
} else {
error = F_9 ( & args ) ;
}
* V_16 = args . V_20 ;
if ( error == V_26 )
error = 0 ;
return ( error ) ;
}
int
F_10 (
T_2 * V_10 ,
const unsigned char * V_5 ,
unsigned char * V_15 ,
int * V_16 ,
int V_17 )
{
int error ;
struct V_1 V_2 ;
F_11 ( V_27 ) ;
if ( F_12 ( V_10 -> V_28 ) )
return ( V_29 ) ;
error = F_1 ( & V_2 , V_5 ) ;
if ( error )
return error ;
F_13 ( V_10 , V_30 ) ;
error = F_4 ( V_10 , & V_2 , V_15 , V_16 , V_17 ) ;
F_14 ( V_10 , V_30 ) ;
return ( error ) ;
}
STATIC int
F_15 (
struct V_9 * V_10 ,
int V_19 ,
int V_20 ,
int * V_31 )
{
struct V_32 * V_33 = V_10 -> V_28 ;
int V_34 ;
int V_35 ;
V_34 = F_16 ( V_19 , V_20 ,
V_33 -> V_36 . V_37 , V_31 ) ;
V_35 = F_17 ( V_33 , V_24 ) ;
if ( * V_31 ) {
if ( V_34 > ( V_33 -> V_36 . V_37 >> 1 ) ) {
V_35 *= 2 ;
}
} else {
T_3 V_38 = F_18 ( V_33 , V_20 ) ;
V_35 += V_38 ;
V_35 += F_19 ( V_33 , V_38 , V_24 ) ;
}
return V_35 ;
}
STATIC int
F_20 (
struct V_9 * V_22 ,
struct V_1 * V_5 ,
unsigned char * V_15 ,
int V_20 ,
int V_17 )
{
T_1 args ;
T_4 V_39 ;
T_5 V_40 ;
int error , V_41 , V_42 ;
T_6 * V_33 = V_22 -> V_28 ;
int V_43 = ( V_17 & V_44 ) != 0 ;
int V_31 ;
error = F_21 ( V_22 , 0 ) ;
if ( error )
return error ;
if ( F_3 ( V_22 ) == 0 ) {
int V_45 = sizeof( V_46 ) +
F_22 ( V_5 -> V_6 , V_20 ) ;
if ( ( error = F_23 ( V_22 , V_45 , V_43 ) ) )
return ( error ) ;
}
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_5 = V_5 -> V_5 ;
args . V_19 = V_5 -> V_6 ;
args . V_15 = V_15 ;
args . V_20 = V_20 ;
args . V_17 = V_17 ;
args . V_21 = F_5 ( args . V_5 , args . V_19 ) ;
args . V_22 = V_22 ;
args . V_39 = & V_39 ;
args . V_40 = & V_40 ;
args . V_23 = V_24 ;
args . V_47 = V_48 | V_49 ;
args . V_50 = F_15 ( V_22 , V_5 -> V_6 , V_20 , & V_31 ) ;
args . V_51 = F_24 ( V_33 , V_52 ) ;
if ( V_43 )
args . V_51 -> V_53 |= V_54 ;
if ( ( error = F_25 ( args . V_51 , args . V_50 ,
F_26 ( V_33 , args . V_50 ) , 0 ,
V_55 , V_56 ) ) ) {
F_27 ( args . V_51 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_57 ) ;
error = F_28 ( args . V_51 , V_22 , args . V_50 , 0 ,
V_43 ? V_58 | V_59 :
V_58 ) ;
if ( error ) {
F_14 ( V_22 , V_57 ) ;
F_27 ( args . V_51 , V_60 ) ;
return ( error ) ;
}
F_29 ( args . V_51 , V_22 , 0 ) ;
if ( ( V_22 -> V_11 . V_12 == V_25 ) ||
( ( V_22 -> V_11 . V_12 == V_13 ) &&
( V_22 -> V_11 . V_14 == 0 ) ) ) {
if ( V_22 -> V_11 . V_12 == V_13 )
F_30 ( & args ) ;
error = F_31 ( & args ) ;
if ( error != V_61 ) {
ASSERT ( args . V_51 != NULL ) ;
if ( V_33 -> V_62 & V_63 ) {
F_32 ( args . V_51 ) ;
}
if ( ! error && ( V_17 & V_64 ) == 0 ) {
F_33 ( args . V_51 , V_22 ,
V_65 ) ;
}
V_41 = F_34 ( args . V_51 ,
V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error == 0 ? V_41 : error ) ;
}
F_35 ( args . V_40 , args . V_39 ) ;
error = F_36 ( & args ) ;
if ( ! error ) {
error = F_37 ( & args . V_51 , args . V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args . V_51 = NULL ;
F_38 ( & V_40 ) ;
goto V_66;
}
if ( V_42 )
F_29 ( args . V_51 , V_22 , 0 ) ;
error = F_39 ( & args . V_51 , V_22 ) ;
if ( error )
goto V_66;
}
if ( F_7 ( V_22 , V_24 ) ) {
error = F_40 ( & args ) ;
} else {
error = F_41 ( & args ) ;
}
if ( error ) {
goto V_66;
}
if ( V_33 -> V_62 & V_63 ) {
F_32 ( args . V_51 ) ;
}
if ( ( V_17 & V_64 ) == 0 )
F_33 ( args . V_51 , V_22 , V_65 ) ;
F_42 ( args . V_51 , V_22 , V_67 ) ;
error = F_34 ( args . V_51 , V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
V_66:
if ( args . V_51 )
F_27 ( args . V_51 ,
V_60 | V_68 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
}
int
F_43 (
T_2 * V_22 ,
const unsigned char * V_5 ,
unsigned char * V_15 ,
int V_20 ,
int V_17 )
{
int error ;
struct V_1 V_2 ;
F_11 ( V_69 ) ;
if ( F_12 ( V_22 -> V_28 ) )
return ( V_29 ) ;
error = F_1 ( & V_2 , V_5 ) ;
if ( error )
return error ;
return F_20 ( V_22 , & V_2 , V_15 , V_20 , V_17 ) ;
}
STATIC int
F_44 ( T_2 * V_22 , struct V_1 * V_5 , int V_17 )
{
T_1 args ;
T_4 V_39 ;
T_5 V_40 ;
int error ;
T_6 * V_33 = V_22 -> V_28 ;
memset ( ( char * ) & args , 0 , sizeof( args ) ) ;
args . V_5 = V_5 -> V_5 ;
args . V_19 = V_5 -> V_6 ;
args . V_17 = V_17 ;
args . V_21 = F_5 ( args . V_5 , args . V_19 ) ;
args . V_22 = V_22 ;
args . V_39 = & V_39 ;
args . V_40 = & V_40 ;
args . V_50 = 0 ;
args . V_23 = V_24 ;
args . V_47 = V_49 ;
error = F_21 ( V_22 , 0 ) ;
if ( error )
return error ;
args . V_51 = F_24 ( V_33 , V_70 ) ;
if ( V_17 & V_44 )
args . V_51 -> V_53 |= V_54 ;
if ( ( error = F_25 ( args . V_51 ,
F_45 ( V_33 ) ,
F_46 ( V_33 ) ,
0 , V_55 ,
V_71 ) ) ) {
F_27 ( args . V_51 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_57 ) ;
F_29 ( args . V_51 , V_22 , 0 ) ;
if ( ! F_2 ( V_22 ) ) {
error = F_47 ( V_18 ) ;
goto V_66;
}
if ( V_22 -> V_11 . V_12 == V_25 ) {
ASSERT ( V_22 -> V_72 -> V_73 & V_74 ) ;
error = F_48 ( & args ) ;
if ( error ) {
goto V_66;
}
} else if ( F_7 ( V_22 , V_24 ) ) {
error = F_49 ( & args ) ;
} else {
error = F_50 ( & args ) ;
}
if ( error ) {
goto V_66;
}
if ( V_33 -> V_62 & V_63 ) {
F_32 ( args . V_51 ) ;
}
if ( ( V_17 & V_64 ) == 0 )
F_33 ( args . V_51 , V_22 , V_65 ) ;
F_42 ( args . V_51 , V_22 , V_67 ) ;
error = F_34 ( args . V_51 , V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
V_66:
if ( args . V_51 )
F_27 ( args . V_51 ,
V_60 | V_68 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
}
int
F_51 (
T_2 * V_22 ,
const unsigned char * V_5 ,
int V_17 )
{
int error ;
struct V_1 V_2 ;
F_11 ( V_75 ) ;
if ( F_12 ( V_22 -> V_28 ) )
return ( V_29 ) ;
error = F_1 ( & V_2 , V_5 ) ;
if ( error )
return error ;
F_13 ( V_22 , V_30 ) ;
if ( ! F_2 ( V_22 ) ) {
F_14 ( V_22 , V_30 ) ;
return F_47 ( V_18 ) ;
}
F_14 ( V_22 , V_30 ) ;
return F_44 ( V_22 , & V_2 , V_17 ) ;
}
int
F_52 ( T_7 * V_76 )
{
int error ;
T_2 * V_22 = V_76 -> V_22 ;
F_11 ( V_77 ) ;
if ( F_12 ( V_22 -> V_28 ) )
return V_29 ;
F_13 ( V_22 , V_30 ) ;
if ( ! F_2 ( V_22 ) ) {
error = 0 ;
} else if ( V_22 -> V_11 . V_12 == V_25 ) {
error = F_53 ( V_76 ) ;
} else if ( F_7 ( V_22 , V_24 ) ) {
error = F_54 ( V_76 ) ;
} else {
error = F_55 ( V_76 ) ;
}
F_14 ( V_22 , V_30 ) ;
return error ;
}
STATIC int
F_56 (
T_7 * V_76 ,
int V_17 ,
unsigned char * V_5 ,
int V_19 ,
int V_20 ,
unsigned char * V_15 )
{
struct V_78 * V_79 = (struct V_78 * ) V_76 -> V_79 ;
T_8 * V_80 ;
int V_81 ;
ASSERT ( ! ( V_76 -> V_17 & V_82 ) ) ;
ASSERT ( V_76 -> V_83 >= 0 ) ;
ASSERT ( V_76 -> V_83 < ( V_84 / 8 ) ) ;
ASSERT ( V_76 -> V_85 >= sizeof( * V_79 ) ) ;
ASSERT ( V_76 -> V_85 <= V_76 -> V_86 ) ;
if ( ( ( V_76 -> V_17 & V_87 ) == 0 ) !=
( ( V_17 & V_88 ) == 0 ) )
return 0 ;
if ( ( ( V_76 -> V_17 & V_44 ) == 0 ) !=
( ( V_17 & V_89 ) == 0 ) )
return 0 ;
V_81 = sizeof( * V_79 ) +
V_76 -> V_83 * sizeof( V_79 -> V_90 [ 0 ] ) ;
V_76 -> V_85 -= F_57 ( V_19 ) ;
if ( V_76 -> V_85 < V_81 ) {
F_58 ( V_76 ) ;
V_79 -> V_91 = 1 ;
V_76 -> V_92 = 1 ;
return 1 ;
}
V_80 = ( T_8 * ) & V_76 -> V_79 [ V_76 -> V_85 ] ;
V_80 -> V_93 = V_20 ;
memcpy ( V_80 -> V_94 , V_5 , V_19 ) ;
V_80 -> V_94 [ V_19 ] = 0 ;
V_79 -> V_90 [ V_76 -> V_83 ++ ] = V_76 -> V_85 ;
V_79 -> V_95 = V_76 -> V_83 ;
F_59 ( V_76 ) ;
return 0 ;
}
int
F_60 (
T_2 * V_22 ,
char * V_96 ,
int V_86 ,
int V_17 ,
T_9 * V_97 )
{
T_7 V_76 ;
struct V_78 * V_79 ;
int error ;
if ( V_97 -> V_98 || V_97 -> V_99 )
return ( F_47 ( V_4 ) ) ;
if ( ( V_97 -> V_100 == 0 ) &&
( V_97 -> V_21 || V_97 -> V_101 || V_97 -> V_102 ) )
return F_47 ( V_4 ) ;
if ( ( ( long ) V_96 ) & ( sizeof( int ) - 1 ) )
return F_47 ( V_8 ) ;
if ( V_17 & V_82 )
V_86 = 0 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_22 = V_22 ;
V_76 . V_97 = V_97 ;
V_76 . V_103 = 1 ;
V_76 . V_17 = V_17 ;
V_76 . V_79 = V_96 ;
V_76 . V_86 = ( V_86 & ~ ( sizeof( int ) - 1 ) ) ;
V_76 . V_85 = V_76 . V_86 ;
V_76 . V_104 = F_56 ;
V_79 = (struct V_78 * ) V_76 . V_79 ;
V_79 -> V_95 = 0 ;
V_79 -> V_91 = 0 ;
V_79 -> V_90 [ 0 ] = V_76 . V_86 ;
error = F_52 ( & V_76 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
int
F_61 ( T_2 * V_22 )
{
T_10 * V_51 ;
T_6 * V_33 ;
int error ;
V_33 = V_22 -> V_28 ;
ASSERT ( ! F_62 ( V_33 , V_22 ) ) ;
F_13 ( V_22 , V_30 ) ;
if ( ! F_2 ( V_22 ) ||
V_22 -> V_11 . V_12 == V_25 ) {
F_14 ( V_22 , V_30 ) ;
return 0 ;
}
F_14 ( V_22 , V_30 ) ;
V_51 = F_24 ( V_33 , V_105 ) ;
if ( ( error = F_25 ( V_51 , 0 , F_63 ( V_33 ) , 0 ,
V_55 ,
V_106 ) ) ) {
F_27 ( V_51 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_57 ) ;
F_29 ( V_51 , V_22 , 0 ) ;
if ( ! F_2 ( V_22 ) ||
V_22 -> V_11 . V_12 == V_25 ) {
error = 0 ;
goto V_66;
}
error = F_64 ( & V_51 , V_22 ) ;
if ( error )
goto V_66;
error = F_65 ( & V_51 , V_22 , V_24 , 0 ) ;
if ( error )
goto V_66;
error = F_34 ( V_51 , V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
V_66:
F_27 ( V_51 , V_60 | V_68 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
}
STATIC int
F_31 ( T_1 * args )
{
int V_107 , V_108 , V_109 ;
V_109 = F_66 ( args ) ;
if ( ( args -> V_17 & V_110 ) && ( V_109 == V_18 ) ) {
return ( V_109 ) ;
} else if ( V_109 == V_26 ) {
if ( args -> V_17 & V_111 )
return ( V_109 ) ;
V_109 = F_48 ( args ) ;
ASSERT ( V_109 == 0 ) ;
}
if ( args -> V_19 >= V_112 ||
args -> V_20 >= V_112 )
return ( F_47 ( V_61 ) ) ;
V_107 = F_67 ( args -> V_22 ) ;
V_107 += F_22 ( args -> V_19 , args -> V_20 ) ;
V_108 = F_68 ( args -> V_22 , V_107 ) ;
if ( ! V_108 )
return ( F_47 ( V_61 ) ) ;
F_69 ( args , V_108 ) ;
return ( 0 ) ;
}
STATIC int
F_40 ( T_1 * args )
{
T_2 * V_22 ;
T_11 * V_113 ;
int V_109 , error , V_42 , V_108 ;
V_22 = args -> V_22 ;
args -> V_101 = 0 ;
error = F_70 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_113 ,
V_24 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_113 != NULL ) ;
V_109 = F_71 ( V_113 , args ) ;
if ( ( args -> V_17 & V_110 ) && ( V_109 == V_18 ) ) {
F_72 ( args -> V_51 , V_113 ) ;
return ( V_109 ) ;
} else if ( V_109 == V_26 ) {
if ( args -> V_17 & V_111 ) {
F_72 ( args -> V_51 , V_113 ) ;
return ( V_109 ) ;
}
args -> V_47 |= V_114 ;
args -> V_115 = args -> V_101 ;
args -> V_116 = args -> V_117 ;
args -> V_118 = args -> V_119 ;
args -> V_120 = args -> V_121 ;
}
V_109 = F_73 ( V_113 , args ) ;
F_74 ( V_113 ) ;
if ( V_109 == V_61 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_75 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
return ( error ) ;
error = F_41 ( args ) ;
return ( error ) ;
}
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
return ( error ) ;
if ( args -> V_119 > 0 ) {
error = F_76 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_47 & V_114 ) {
error = F_77 ( args ) ;
if ( error )
return ( error ) ;
args -> V_117 = args -> V_116 ;
args -> V_101 = args -> V_115 ;
args -> V_119 = args -> V_118 ;
args -> V_121 = args -> V_120 ;
if ( args -> V_119 ) {
error = F_78 ( args ) ;
if ( error )
return ( error ) ;
}
error = F_70 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 ,
& V_113 , V_24 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_113 != NULL ) ;
( void ) F_79 ( V_113 , args ) ;
if ( ( V_108 = F_80 ( V_113 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_81 ( V_113 , args , V_108 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
} else
F_74 ( V_113 ) ;
error = F_39 ( & args -> V_51 , V_22 ) ;
} else if ( args -> V_119 > 0 ) {
error = F_82 ( args ) ;
}
return ( error ) ;
}
STATIC int
F_49 ( T_1 * args )
{
T_2 * V_22 ;
T_11 * V_113 ;
int error , V_42 , V_108 ;
V_22 = args -> V_22 ;
args -> V_101 = 0 ;
error = F_70 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_113 ,
V_24 ) ;
if ( error ) {
return ( error ) ;
}
ASSERT ( V_113 != NULL ) ;
error = F_71 ( V_113 , args ) ;
if ( error == V_18 ) {
F_72 ( args -> V_51 , V_113 ) ;
return ( error ) ;
}
( void ) F_79 ( V_113 , args ) ;
if ( ( V_108 = F_80 ( V_113 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_81 ( V_113 , args , V_108 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
} else
F_74 ( V_113 ) ;
return ( 0 ) ;
}
STATIC int
F_8 ( T_1 * args )
{
T_11 * V_113 ;
int error ;
args -> V_101 = 0 ;
error = F_70 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_113 ,
V_24 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_113 != NULL ) ;
error = F_71 ( V_113 , args ) ;
if ( error != V_26 ) {
F_72 ( args -> V_51 , V_113 ) ;
return ( error ) ;
}
error = F_83 ( V_113 , args ) ;
F_72 ( args -> V_51 , V_113 ) ;
if ( ! error && ( args -> V_119 > 0 ) && ! ( args -> V_17 & V_82 ) ) {
error = F_84 ( args ) ;
}
return ( error ) ;
}
STATIC int
F_54 ( T_7 * V_76 )
{
T_12 * V_122 ;
int error ;
T_11 * V_113 ;
V_76 -> V_97 -> V_101 = 0 ;
error = F_70 ( NULL , V_76 -> V_22 , 0 , - 1 , & V_113 , V_24 ) ;
if ( error )
return F_47 ( error ) ;
ASSERT ( V_113 != NULL ) ;
V_122 = V_113 -> V_123 ;
if ( F_85 ( V_122 -> V_124 . V_125 . V_126 != F_86 ( V_127 ) ) ) {
F_87 ( L_1 , V_128 ,
V_76 -> V_22 -> V_28 , V_122 ) ;
F_72 ( NULL , V_113 ) ;
return F_47 ( V_129 ) ;
}
error = F_88 ( V_113 , V_76 ) ;
F_72 ( NULL , V_113 ) ;
return F_47 ( error ) ;
}
STATIC int
F_41 ( T_1 * args )
{
T_13 * V_130 ;
T_14 * V_131 ;
T_2 * V_22 ;
T_6 * V_33 ;
int V_42 , V_109 , error ;
V_22 = args -> V_22 ;
V_33 = V_22 -> V_28 ;
V_132:
V_130 = F_89 () ;
V_130 -> args = args ;
V_130 -> V_33 = V_33 ;
V_130 -> V_133 = V_130 -> V_33 -> V_36 . V_37 ;
V_130 -> V_134 = V_130 -> V_33 -> V_135 ;
error = F_90 ( V_130 , & V_109 ) ;
if ( error )
goto V_66;
V_131 = & V_130 -> V_136 . V_131 [ V_130 -> V_136 . V_137 - 1 ] ;
ASSERT ( V_131 -> V_126 == V_127 ) ;
if ( ( args -> V_17 & V_110 ) && ( V_109 == V_18 ) ) {
goto V_66;
} else if ( V_109 == V_26 ) {
if ( args -> V_17 & V_111 )
goto V_66;
args -> V_47 |= V_114 ;
args -> V_115 = args -> V_101 ;
args -> V_116 = args -> V_117 ;
args -> V_118 = args -> V_119 ;
args -> V_120 = args -> V_121 ;
args -> V_119 = 0 ;
args -> V_121 = 0 ;
}
V_109 = F_73 ( V_131 -> V_113 , V_130 -> args ) ;
if ( V_109 == V_61 ) {
if ( V_130 -> V_136 . V_137 == 1 ) {
F_91 ( V_130 ) ;
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_75 ( args ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
goto V_132;
}
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_92 ( V_130 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
} else {
F_93 ( V_130 , & V_130 -> V_136 ) ;
}
F_91 ( V_130 ) ;
V_130 = NULL ;
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
if ( args -> V_119 > 0 ) {
error = F_76 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_47 & V_114 ) {
error = F_77 ( args ) ;
if ( error )
goto V_66;
args -> V_117 = args -> V_116 ;
args -> V_101 = args -> V_115 ;
args -> V_119 = args -> V_118 ;
args -> V_121 = args -> V_120 ;
if ( args -> V_119 ) {
error = F_78 ( args ) ;
if ( error )
return ( error ) ;
}
args -> V_17 |= V_138 ;
V_130 = F_89 () ;
V_130 -> args = args ;
V_130 -> V_33 = V_33 ;
V_130 -> V_133 = V_130 -> V_33 -> V_36 . V_37 ;
V_130 -> V_134 = V_130 -> V_33 -> V_135 ;
V_130 -> V_139 = 0 ;
error = F_90 ( V_130 , & V_109 ) ;
if ( error )
goto V_66;
V_131 = & V_130 -> V_136 . V_131 [ V_130 -> V_136 . V_137 - 1 ] ;
ASSERT ( V_131 -> V_126 == V_127 ) ;
error = F_79 ( V_131 -> V_113 , args ) ;
F_93 ( V_130 , & V_130 -> V_136 ) ;
if ( V_109 && ( V_130 -> V_136 . V_137 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_94 ( V_130 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
}
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
} else if ( args -> V_119 > 0 ) {
error = F_82 ( args ) ;
if ( error )
goto V_66;
}
V_109 = error = 0 ;
V_66:
if ( V_130 )
F_91 ( V_130 ) ;
if ( error )
return ( error ) ;
return ( V_109 ) ;
}
STATIC int
F_50 ( T_1 * args )
{
T_13 * V_130 ;
T_14 * V_131 ;
T_2 * V_22 ;
T_11 * V_113 ;
int V_109 , error , V_42 , V_108 ;
V_22 = args -> V_22 ;
V_130 = F_89 () ;
V_130 -> args = args ;
V_130 -> V_33 = V_22 -> V_28 ;
V_130 -> V_133 = V_130 -> V_33 -> V_36 . V_37 ;
V_130 -> V_134 = V_130 -> V_33 -> V_135 ;
error = F_90 ( V_130 , & V_109 ) ;
if ( error || ( V_109 != V_26 ) ) {
if ( error == 0 )
error = V_109 ;
goto V_66;
}
V_131 = & V_130 -> V_136 . V_131 [ V_130 -> V_136 . V_137 - 1 ] ;
ASSERT ( V_131 -> V_113 != NULL ) ;
ASSERT ( V_131 -> V_126 == V_127 ) ;
if ( args -> V_119 > 0 ) {
error = F_95 ( V_130 ) ;
if ( error )
goto V_66;
error = F_96 ( args ) ;
if ( error )
goto V_66;
error = F_78 ( args ) ;
if ( error )
goto V_66;
error = F_97 ( V_130 ) ;
if ( error )
goto V_66;
}
V_131 = & V_130 -> V_136 . V_131 [ V_130 -> V_136 . V_137 - 1 ] ;
ASSERT ( V_131 -> V_126 == V_127 ) ;
V_109 = F_79 ( V_131 -> V_113 , args ) ;
F_93 ( V_130 , & V_130 -> V_136 ) ;
if ( V_109 && ( V_130 -> V_136 . V_137 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_94 ( V_130 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
}
if ( F_7 ( V_22 , V_24 ) ) {
ASSERT ( V_130 -> V_136 . V_137 == 1 ) ;
ASSERT ( V_130 -> V_136 . V_131 [ 0 ] . V_113 ) ;
F_74 ( V_130 -> V_136 . V_131 [ 0 ] . V_113 ) ;
V_130 -> V_136 . V_131 [ 0 ] . V_113 = NULL ;
error = F_70 ( args -> V_51 , args -> V_22 , 0 , - 1 , & V_113 ,
V_24 ) ;
if ( error )
goto V_66;
ASSERT ( ( ( ( T_12 * ) V_113 -> V_123 ) -> V_124 . V_125 . V_126 ) ==
F_86 ( V_127 ) ) ;
if ( ( V_108 = F_80 ( V_113 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_81 ( V_113 , args , V_108 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
} else
F_72 ( args -> V_51 , V_113 ) ;
}
error = 0 ;
V_66:
F_91 ( V_130 ) ;
return ( error ) ;
}
STATIC int
F_95 ( T_13 * V_130 )
{
T_15 * V_136 ;
T_14 * V_131 ;
int V_140 ;
V_136 = & V_130 -> V_136 ;
ASSERT ( ( V_136 -> V_137 >= 0 ) && ( V_136 -> V_137 < V_141 ) ) ;
for ( V_131 = V_136 -> V_131 , V_140 = 0 ; V_140 < V_136 -> V_137 ; V_131 ++ , V_140 ++ ) {
if ( V_131 -> V_113 ) {
V_131 -> V_142 = F_98 ( V_131 -> V_113 ) ;
F_74 ( V_131 -> V_113 ) ;
V_131 -> V_113 = NULL ;
} else {
V_131 -> V_142 = 0 ;
}
}
V_136 = & V_130 -> V_143 ;
ASSERT ( ( V_136 -> V_137 >= 0 ) && ( V_136 -> V_137 < V_141 ) ) ;
for ( V_131 = V_136 -> V_131 , V_140 = 0 ; V_140 < V_136 -> V_137 ; V_131 ++ , V_140 ++ ) {
if ( V_131 -> V_113 ) {
V_131 -> V_142 = F_98 ( V_131 -> V_113 ) ;
F_74 ( V_131 -> V_113 ) ;
V_131 -> V_113 = NULL ;
} else {
V_131 -> V_142 = 0 ;
}
}
return ( 0 ) ;
}
STATIC int
F_97 ( T_13 * V_130 )
{
T_15 * V_136 ;
T_14 * V_131 ;
int V_140 , error ;
V_136 = & V_130 -> V_136 ;
ASSERT ( ( V_136 -> V_137 >= 0 ) && ( V_136 -> V_137 < V_141 ) ) ;
for ( V_131 = V_136 -> V_131 , V_140 = 0 ; V_140 < V_136 -> V_137 ; V_131 ++ , V_140 ++ ) {
if ( V_131 -> V_142 ) {
error = F_70 ( V_130 -> args -> V_51 ,
V_130 -> args -> V_22 ,
V_131 -> V_101 , V_131 -> V_142 ,
& V_131 -> V_113 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_131 -> V_113 = NULL ;
}
}
V_136 = & V_130 -> V_143 ;
ASSERT ( ( V_136 -> V_137 >= 0 ) && ( V_136 -> V_137 < V_141 ) ) ;
for ( V_131 = V_136 -> V_131 , V_140 = 0 ; V_140 < V_136 -> V_137 ; V_131 ++ , V_140 ++ ) {
if ( V_131 -> V_142 ) {
error = F_70 ( V_130 -> args -> V_51 ,
V_130 -> args -> V_22 ,
V_131 -> V_101 , V_131 -> V_142 ,
& V_131 -> V_113 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_131 -> V_113 = NULL ;
}
}
return ( 0 ) ;
}
STATIC int
F_9 ( T_1 * args )
{
T_13 * V_130 ;
T_14 * V_131 ;
int error , V_109 ;
int V_144 ;
V_130 = F_89 () ;
V_130 -> args = args ;
V_130 -> V_33 = args -> V_22 -> V_28 ;
V_130 -> V_133 = V_130 -> V_33 -> V_36 . V_37 ;
V_130 -> V_134 = V_130 -> V_33 -> V_135 ;
error = F_90 ( V_130 , & V_109 ) ;
if ( error ) {
V_109 = error ;
} else if ( V_109 == V_26 ) {
V_131 = & V_130 -> V_136 . V_131 [ V_130 -> V_136 . V_137 - 1 ] ;
ASSERT ( V_131 -> V_113 != NULL ) ;
ASSERT ( V_131 -> V_126 == V_127 ) ;
V_109 = F_83 ( V_131 -> V_113 , args ) ;
if ( ! V_109 && ( args -> V_119 > 0 )
&& ! ( args -> V_17 & V_82 ) ) {
V_109 = F_84 ( args ) ;
}
}
for ( V_144 = 0 ; V_144 < V_130 -> V_136 . V_137 ; V_144 ++ ) {
F_72 ( args -> V_51 , V_130 -> V_136 . V_131 [ V_144 ] . V_113 ) ;
V_130 -> V_136 . V_131 [ V_144 ] . V_113 = NULL ;
}
F_91 ( V_130 ) ;
return ( V_109 ) ;
}
STATIC int
F_55 ( T_7 * V_76 )
{
T_9 * V_97 ;
T_12 * V_122 ;
T_16 * V_145 ;
T_17 * V_146 ;
int error , V_144 ;
T_11 * V_113 ;
V_97 = V_76 -> V_97 ;
V_97 -> V_100 = 1 ;
V_113 = NULL ;
if ( V_97 -> V_101 > 0 ) {
error = F_70 ( NULL , V_76 -> V_22 , V_97 -> V_101 , - 1 ,
& V_113 , V_24 ) ;
if ( ( error != 0 ) && ( error != V_129 ) )
return ( error ) ;
if ( V_113 ) {
V_145 = V_113 -> V_123 ;
switch ( F_99 ( V_145 -> V_124 . V_125 . V_126 ) ) {
case V_147 :
F_100 ( V_76 ) ;
F_72 ( NULL , V_113 ) ;
V_113 = NULL ;
break;
case V_127 :
V_122 = V_113 -> V_123 ;
if ( V_97 -> V_21 > F_101 ( V_122 -> V_148 [
F_99 ( V_122 -> V_124 . V_83 ) - 1 ] . V_21 ) ) {
F_100 ( V_76 ) ;
F_72 ( NULL , V_113 ) ;
V_113 = NULL ;
} else if ( V_97 -> V_21 <=
F_101 ( V_122 -> V_148 [ 0 ] . V_21 ) ) {
F_100 ( V_76 ) ;
F_72 ( NULL , V_113 ) ;
V_113 = NULL ;
}
break;
default:
F_100 ( V_76 ) ;
F_72 ( NULL , V_113 ) ;
V_113 = NULL ;
}
}
}
if ( V_113 == NULL ) {
V_97 -> V_101 = 0 ;
for (; ; ) {
error = F_70 ( NULL , V_76 -> V_22 ,
V_97 -> V_101 , - 1 , & V_113 ,
V_24 ) ;
if ( error )
return ( error ) ;
if ( F_85 ( V_113 == NULL ) ) {
F_102 ( L_2 ,
V_128 ,
V_76 -> V_22 -> V_28 ) ;
return ( F_47 ( V_129 ) ) ;
}
V_145 = V_113 -> V_123 ;
if ( V_145 -> V_124 . V_125 . V_126 ==
F_86 ( V_127 ) )
break;
if ( F_85 ( V_145 -> V_124 . V_125 . V_126 !=
F_86 ( V_147 ) ) ) {
F_87 ( L_3 ,
V_128 ,
V_76 -> V_22 -> V_28 ,
V_145 ) ;
F_72 ( NULL , V_113 ) ;
return ( F_47 ( V_129 ) ) ;
}
V_146 = V_145 -> V_146 ;
for ( V_144 = 0 ; V_144 < F_99 ( V_145 -> V_124 . V_83 ) ;
V_146 ++ , V_144 ++ ) {
if ( V_97 -> V_21
<= F_101 ( V_146 -> V_21 ) ) {
V_97 -> V_101 = F_101 ( V_146 -> V_149 ) ;
F_103 ( V_76 ,
V_146 ) ;
break;
}
}
if ( V_144 == F_99 ( V_145 -> V_124 . V_83 ) ) {
F_72 ( NULL , V_113 ) ;
return ( 0 ) ;
}
F_72 ( NULL , V_113 ) ;
}
}
ASSERT ( V_113 != NULL ) ;
for (; ; ) {
V_122 = V_113 -> V_123 ;
if ( F_85 ( V_122 -> V_124 . V_125 . V_126 !=
F_86 ( V_127 ) ) ) {
F_87 ( L_4 ,
V_128 ,
V_76 -> V_22 -> V_28 , V_122 ) ;
F_72 ( NULL , V_113 ) ;
return ( F_47 ( V_129 ) ) ;
}
error = F_88 ( V_113 , V_76 ) ;
if ( error ) {
F_72 ( NULL , V_113 ) ;
return error ;
}
if ( V_76 -> V_92 || V_122 -> V_124 . V_125 . V_150 == 0 )
break;
V_97 -> V_101 = F_101 ( V_122 -> V_124 . V_125 . V_150 ) ;
F_72 ( NULL , V_113 ) ;
error = F_70 ( NULL , V_76 -> V_22 , V_97 -> V_101 , - 1 ,
& V_113 , V_24 ) ;
if ( error )
return ( error ) ;
if ( F_85 ( ( V_113 == NULL ) ) ) {
F_102 ( L_5 ,
V_128 ,
V_76 -> V_22 -> V_28 ) ;
return ( F_47 ( V_129 ) ) ;
}
}
F_72 ( NULL , V_113 ) ;
return ( 0 ) ;
}
int
F_84 ( T_1 * args )
{
T_18 V_151 [ V_152 ] ;
T_6 * V_33 ;
T_19 V_153 ;
void * V_154 ;
T_20 * V_113 ;
int V_155 , error , V_156 , V_20 , V_157 , V_144 ;
T_21 V_158 ;
ASSERT ( ! ( args -> V_17 & V_82 ) ) ;
V_33 = args -> V_22 -> V_28 ;
V_154 = args -> V_15 ;
V_20 = args -> V_20 ;
V_158 = args -> V_119 ;
while ( V_20 > 0 ) {
V_155 = V_152 ;
error = F_104 ( args -> V_22 , ( V_159 ) V_158 ,
args -> V_121 , V_151 , & V_155 ,
V_160 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_155 >= 1 ) ;
for ( V_144 = 0 ; ( V_144 < V_155 ) && ( V_20 > 0 ) ; V_144 ++ ) {
ASSERT ( ( V_151 [ V_144 ] . V_161 != V_162 ) &&
( V_151 [ V_144 ] . V_161 != V_163 ) ) ;
V_153 = F_105 ( V_33 , V_151 [ V_144 ] . V_161 ) ;
V_157 = F_106 ( V_33 , V_151 [ V_144 ] . V_164 ) ;
error = F_107 ( V_33 , V_33 -> V_165 , V_153 ,
V_157 , V_166 | V_167 ,
& V_113 ) ;
if ( error )
return ( error ) ;
V_156 = ( V_20 < F_108 ( V_113 ) )
? V_20 : F_108 ( V_113 ) ;
F_109 ( V_113 , 0 , V_156 , V_154 , V_168 ) ;
F_110 ( V_113 ) ;
V_154 += V_156 ;
V_20 -= V_156 ;
V_158 += V_151 [ V_144 ] . V_164 ;
}
}
ASSERT ( V_20 == 0 ) ;
return ( 0 ) ;
}
STATIC int
F_76 ( T_1 * args )
{
T_6 * V_33 ;
V_159 V_169 ;
T_2 * V_22 ;
T_18 V_151 ;
T_19 V_153 ;
void * V_170 ;
T_20 * V_113 ;
T_21 V_158 ;
int V_157 , V_20 , V_155 , error , V_156 , V_42 ;
V_22 = args -> V_22 ;
V_33 = V_22 -> V_28 ;
V_170 = args -> V_15 ;
V_157 = F_18 ( V_33 , args -> V_20 ) ;
V_169 = 0 ;
error = F_111 ( args -> V_51 , args -> V_22 , V_157 , & V_169 ,
V_24 ) ;
if ( error ) {
return ( error ) ;
}
args -> V_119 = V_158 = ( T_21 ) V_169 ;
args -> V_121 = V_157 ;
while ( V_157 > 0 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
V_155 = 1 ;
error = F_112 ( args -> V_51 , V_22 , ( V_159 ) V_158 ,
V_157 ,
V_160 | V_171 ,
args -> V_39 , args -> V_50 , & V_151 , & V_155 ,
args -> V_40 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_29 ( args -> V_51 , V_22 , 0 ) ;
ASSERT ( V_155 == 1 ) ;
ASSERT ( ( V_151 . V_161 != V_162 ) &&
( V_151 . V_161 != V_163 ) ) ;
V_158 += V_151 . V_164 ;
V_157 -= V_151 . V_164 ;
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
return ( error ) ;
}
V_158 = args -> V_119 ;
V_20 = args -> V_20 ;
while ( V_20 > 0 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
V_155 = 1 ;
error = F_104 ( V_22 , ( V_159 ) V_158 ,
args -> V_121 , & V_151 , & V_155 ,
V_160 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_155 == 1 ) ;
ASSERT ( ( V_151 . V_161 != V_162 ) &&
( V_151 . V_161 != V_163 ) ) ;
V_153 = F_105 ( V_33 , V_151 . V_161 ) ,
V_157 = F_106 ( V_33 , V_151 . V_164 ) ;
V_113 = F_113 ( V_33 -> V_165 , V_153 , V_157 ,
V_166 | V_167 ) ;
if ( ! V_113 )
return V_172 ;
V_156 = ( V_20 < F_108 ( V_113 ) ) ? V_20 :
F_108 ( V_113 ) ;
F_109 ( V_113 , 0 , V_156 , V_170 , V_173 ) ;
if ( V_156 < F_108 ( V_113 ) )
F_114 ( V_113 , V_156 , F_108 ( V_113 ) - V_156 ) ;
error = F_115 ( V_113 ) ;
F_110 ( V_113 ) ;
if ( error )
return error ;
V_170 += V_156 ;
V_20 -= V_156 ;
V_158 += V_151 . V_164 ;
}
ASSERT ( V_20 == 0 ) ;
return ( 0 ) ;
}
STATIC int
F_78 ( T_1 * args )
{
T_6 * V_33 ;
T_18 V_151 ;
T_20 * V_113 ;
T_19 V_153 ;
T_21 V_158 ;
int V_20 , V_157 , V_155 , error , V_174 , V_42 ;
V_33 = args -> V_22 -> V_28 ;
V_158 = args -> V_119 ;
V_20 = args -> V_121 ;
while ( V_20 > 0 ) {
V_155 = 1 ;
error = F_104 ( args -> V_22 , ( V_159 ) V_158 ,
args -> V_121 , & V_151 , & V_155 ,
V_160 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_155 == 1 ) ;
ASSERT ( ( V_151 . V_161 != V_162 ) &&
( V_151 . V_161 != V_163 ) ) ;
V_153 = F_105 ( V_33 , V_151 . V_161 ) ,
V_157 = F_106 ( V_33 , V_151 . V_164 ) ;
V_113 = F_116 ( V_33 -> V_165 , V_153 , V_157 , V_175 ) ;
if ( V_113 ) {
F_117 ( V_113 ) ;
F_110 ( V_113 ) ;
V_113 = NULL ;
}
V_20 -= V_151 . V_164 ;
V_158 += V_151 . V_164 ;
}
V_158 = args -> V_119 ;
V_157 = args -> V_121 ;
V_174 = 0 ;
while ( ! V_174 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_118 ( args -> V_51 , args -> V_22 , V_158 , V_157 ,
V_160 | V_171 ,
1 , args -> V_39 , args -> V_40 ,
& V_174 ) ;
if ( ! error ) {
error = F_37 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_38 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_29 ( args -> V_51 , args -> V_22 , 0 ) ;
error = F_39 ( & args -> V_51 , args -> V_22 ) ;
if ( error )
return ( error ) ;
}
return ( 0 ) ;
}
