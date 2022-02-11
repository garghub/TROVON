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
F_66 ( args ) ;
V_109 = F_67 ( args ) ;
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
V_107 = F_68 ( args -> V_22 ) ;
V_107 += F_22 ( args -> V_19 , args -> V_20 ) ;
V_108 = F_69 ( args -> V_22 , V_107 ) ;
if ( ! V_108 )
return ( F_47 ( V_61 ) ) ;
F_70 ( args , V_108 ) ;
return ( 0 ) ;
}
STATIC int
F_40 ( T_1 * args )
{
T_2 * V_22 ;
struct V_113 * V_114 ;
int V_109 , error , V_42 , V_108 ;
F_71 ( args ) ;
V_22 = args -> V_22 ;
args -> V_101 = 0 ;
error = F_72 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_114 ,
V_24 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_114 != NULL ) ;
V_109 = F_73 ( V_114 , args ) ;
if ( ( args -> V_17 & V_110 ) && ( V_109 == V_18 ) ) {
F_74 ( args -> V_51 , V_114 ) ;
return ( V_109 ) ;
} else if ( V_109 == V_26 ) {
if ( args -> V_17 & V_111 ) {
F_74 ( args -> V_51 , V_114 ) ;
return ( V_109 ) ;
}
F_75 ( args ) ;
args -> V_47 |= V_115 ;
args -> V_116 = args -> V_101 ;
args -> V_117 = args -> V_118 ;
args -> V_119 = args -> V_120 ;
args -> V_121 = args -> V_122 ;
}
V_109 = F_76 ( V_114 , args ) ;
if ( V_109 == V_61 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_77 ( args ) ;
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
if ( args -> V_120 > 0 ) {
error = F_78 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_47 & V_115 ) {
error = F_79 ( args ) ;
if ( error )
return ( error ) ;
args -> V_118 = args -> V_117 ;
args -> V_101 = args -> V_116 ;
args -> V_120 = args -> V_119 ;
args -> V_122 = args -> V_121 ;
if ( args -> V_120 ) {
error = F_80 ( args ) ;
if ( error )
return ( error ) ;
}
error = F_72 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 ,
& V_114 , V_24 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_114 != NULL ) ;
( void ) F_81 ( V_114 , args ) ;
if ( ( V_108 = F_82 ( V_114 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_83 ( V_114 , args , V_108 ) ;
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
}
error = F_39 ( & args -> V_51 , V_22 ) ;
} else if ( args -> V_120 > 0 ) {
error = F_84 ( args ) ;
}
return ( error ) ;
}
STATIC int
F_49 ( T_1 * args )
{
T_2 * V_22 ;
struct V_113 * V_114 ;
int error , V_42 , V_108 ;
F_85 ( args ) ;
V_22 = args -> V_22 ;
args -> V_101 = 0 ;
error = F_72 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_114 ,
V_24 ) ;
if ( error ) {
return ( error ) ;
}
ASSERT ( V_114 != NULL ) ;
error = F_73 ( V_114 , args ) ;
if ( error == V_18 ) {
F_74 ( args -> V_51 , V_114 ) ;
return ( error ) ;
}
( void ) F_81 ( V_114 , args ) ;
if ( ( V_108 = F_82 ( V_114 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_83 ( V_114 , args , V_108 ) ;
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
}
return ( 0 ) ;
}
STATIC int
F_8 ( T_1 * args )
{
struct V_113 * V_114 ;
int error ;
args -> V_101 = 0 ;
error = F_72 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_114 ,
V_24 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_114 != NULL ) ;
error = F_73 ( V_114 , args ) ;
if ( error != V_26 ) {
F_74 ( args -> V_51 , V_114 ) ;
return ( error ) ;
}
error = F_86 ( V_114 , args ) ;
F_74 ( args -> V_51 , V_114 ) ;
if ( ! error && ( args -> V_120 > 0 ) && ! ( args -> V_17 & V_82 ) ) {
error = F_87 ( args ) ;
}
return ( error ) ;
}
STATIC int
F_54 ( T_7 * V_76 )
{
T_11 * V_123 ;
int error ;
struct V_113 * V_114 ;
V_76 -> V_97 -> V_101 = 0 ;
error = F_72 ( NULL , V_76 -> V_22 , 0 , - 1 , & V_114 , V_24 ) ;
if ( error )
return F_47 ( error ) ;
ASSERT ( V_114 != NULL ) ;
V_123 = V_114 -> V_124 ;
if ( F_88 ( V_123 -> V_125 . V_126 . V_127 != F_89 ( V_128 ) ) ) {
F_90 ( L_1 , V_129 ,
V_76 -> V_22 -> V_28 , V_123 ) ;
F_74 ( NULL , V_114 ) ;
return F_47 ( V_130 ) ;
}
error = F_91 ( V_114 , V_76 ) ;
F_74 ( NULL , V_114 ) ;
return F_47 ( error ) ;
}
STATIC int
F_41 ( T_1 * args )
{
T_12 * V_131 ;
T_13 * V_132 ;
T_2 * V_22 ;
T_6 * V_33 ;
int V_42 , V_109 , error ;
F_92 ( args ) ;
V_22 = args -> V_22 ;
V_33 = V_22 -> V_28 ;
V_133:
V_131 = F_93 () ;
V_131 -> args = args ;
V_131 -> V_33 = V_33 ;
V_131 -> V_134 = V_131 -> V_33 -> V_36 . V_37 ;
V_131 -> V_135 = V_131 -> V_33 -> V_136 ;
error = F_94 ( V_131 , & V_109 ) ;
if ( error )
goto V_66;
V_132 = & V_131 -> V_137 . V_132 [ V_131 -> V_137 . V_138 - 1 ] ;
ASSERT ( V_132 -> V_127 == V_128 ) ;
if ( ( args -> V_17 & V_110 ) && ( V_109 == V_18 ) ) {
goto V_66;
} else if ( V_109 == V_26 ) {
if ( args -> V_17 & V_111 )
goto V_66;
F_95 ( args ) ;
args -> V_47 |= V_115 ;
args -> V_116 = args -> V_101 ;
args -> V_117 = args -> V_118 ;
args -> V_119 = args -> V_120 ;
args -> V_121 = args -> V_122 ;
args -> V_120 = 0 ;
args -> V_122 = 0 ;
}
V_109 = F_76 ( V_132 -> V_114 , V_131 -> args ) ;
if ( V_109 == V_61 ) {
if ( V_131 -> V_137 . V_138 == 1 ) {
F_96 ( V_131 ) ;
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_77 ( args ) ;
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
goto V_133;
}
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_97 ( V_131 ) ;
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
F_98 ( V_131 , & V_131 -> V_137 ) ;
}
F_96 ( V_131 ) ;
V_131 = NULL ;
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
if ( args -> V_120 > 0 ) {
error = F_78 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_47 & V_115 ) {
error = F_79 ( args ) ;
if ( error )
goto V_66;
args -> V_118 = args -> V_117 ;
args -> V_101 = args -> V_116 ;
args -> V_120 = args -> V_119 ;
args -> V_122 = args -> V_121 ;
if ( args -> V_120 ) {
error = F_80 ( args ) ;
if ( error )
return ( error ) ;
}
args -> V_17 |= V_139 ;
V_131 = F_93 () ;
V_131 -> args = args ;
V_131 -> V_33 = V_33 ;
V_131 -> V_134 = V_131 -> V_33 -> V_36 . V_37 ;
V_131 -> V_135 = V_131 -> V_33 -> V_136 ;
V_131 -> V_140 = 0 ;
error = F_94 ( V_131 , & V_109 ) ;
if ( error )
goto V_66;
V_132 = & V_131 -> V_137 . V_132 [ V_131 -> V_137 . V_138 - 1 ] ;
ASSERT ( V_132 -> V_127 == V_128 ) ;
error = F_81 ( V_132 -> V_114 , args ) ;
F_98 ( V_131 , & V_131 -> V_137 ) ;
if ( V_109 && ( V_131 -> V_137 . V_138 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_99 ( V_131 ) ;
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
} else if ( args -> V_120 > 0 ) {
error = F_84 ( args ) ;
if ( error )
goto V_66;
}
V_109 = error = 0 ;
V_66:
if ( V_131 )
F_96 ( V_131 ) ;
if ( error )
return ( error ) ;
return ( V_109 ) ;
}
STATIC int
F_50 ( T_1 * args )
{
T_12 * V_131 ;
T_13 * V_132 ;
T_2 * V_22 ;
struct V_113 * V_114 ;
int V_109 , error , V_42 , V_108 ;
F_100 ( args ) ;
V_22 = args -> V_22 ;
V_131 = F_93 () ;
V_131 -> args = args ;
V_131 -> V_33 = V_22 -> V_28 ;
V_131 -> V_134 = V_131 -> V_33 -> V_36 . V_37 ;
V_131 -> V_135 = V_131 -> V_33 -> V_136 ;
error = F_94 ( V_131 , & V_109 ) ;
if ( error || ( V_109 != V_26 ) ) {
if ( error == 0 )
error = V_109 ;
goto V_66;
}
V_132 = & V_131 -> V_137 . V_132 [ V_131 -> V_137 . V_138 - 1 ] ;
ASSERT ( V_132 -> V_114 != NULL ) ;
ASSERT ( V_132 -> V_127 == V_128 ) ;
if ( args -> V_120 > 0 ) {
error = F_101 ( V_131 ) ;
if ( error )
goto V_66;
error = F_102 ( args ) ;
if ( error )
goto V_66;
error = F_80 ( args ) ;
if ( error )
goto V_66;
error = F_103 ( V_131 ) ;
if ( error )
goto V_66;
}
V_132 = & V_131 -> V_137 . V_132 [ V_131 -> V_137 . V_138 - 1 ] ;
ASSERT ( V_132 -> V_127 == V_128 ) ;
V_109 = F_81 ( V_132 -> V_114 , args ) ;
F_98 ( V_131 , & V_131 -> V_137 ) ;
if ( V_109 && ( V_131 -> V_137 . V_138 > 1 ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_99 ( V_131 ) ;
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
ASSERT ( V_131 -> V_137 . V_138 == 1 ) ;
ASSERT ( V_131 -> V_137 . V_132 [ 0 ] . V_114 ) ;
V_131 -> V_137 . V_132 [ 0 ] . V_114 = NULL ;
error = F_72 ( args -> V_51 , args -> V_22 , 0 , - 1 , & V_114 ,
V_24 ) ;
if ( error )
goto V_66;
ASSERT ( ( ( ( T_11 * ) V_114 -> V_124 ) -> V_125 . V_126 . V_127 ) ==
F_89 ( V_128 ) ) ;
if ( ( V_108 = F_82 ( V_114 , V_22 ) ) ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_83 ( V_114 , args , V_108 ) ;
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
F_74 ( args -> V_51 , V_114 ) ;
}
error = 0 ;
V_66:
F_96 ( V_131 ) ;
return ( error ) ;
}
STATIC int
F_101 ( T_12 * V_131 )
{
T_14 * V_137 ;
T_13 * V_132 ;
int V_141 ;
V_137 = & V_131 -> V_137 ;
ASSERT ( ( V_137 -> V_138 >= 0 ) && ( V_137 -> V_138 < V_142 ) ) ;
for ( V_132 = V_137 -> V_132 , V_141 = 0 ; V_141 < V_137 -> V_138 ; V_132 ++ , V_141 ++ ) {
if ( V_132 -> V_114 ) {
V_132 -> V_143 = F_104 ( V_132 -> V_114 ) ;
V_132 -> V_114 = NULL ;
} else {
V_132 -> V_143 = 0 ;
}
}
V_137 = & V_131 -> V_144 ;
ASSERT ( ( V_137 -> V_138 >= 0 ) && ( V_137 -> V_138 < V_142 ) ) ;
for ( V_132 = V_137 -> V_132 , V_141 = 0 ; V_141 < V_137 -> V_138 ; V_132 ++ , V_141 ++ ) {
if ( V_132 -> V_114 ) {
V_132 -> V_143 = F_104 ( V_132 -> V_114 ) ;
V_132 -> V_114 = NULL ;
} else {
V_132 -> V_143 = 0 ;
}
}
return ( 0 ) ;
}
STATIC int
F_103 ( T_12 * V_131 )
{
T_14 * V_137 ;
T_13 * V_132 ;
int V_141 , error ;
V_137 = & V_131 -> V_137 ;
ASSERT ( ( V_137 -> V_138 >= 0 ) && ( V_137 -> V_138 < V_142 ) ) ;
for ( V_132 = V_137 -> V_132 , V_141 = 0 ; V_141 < V_137 -> V_138 ; V_132 ++ , V_141 ++ ) {
if ( V_132 -> V_143 ) {
error = F_72 ( V_131 -> args -> V_51 ,
V_131 -> args -> V_22 ,
V_132 -> V_101 , V_132 -> V_143 ,
& V_132 -> V_114 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_132 -> V_114 = NULL ;
}
}
V_137 = & V_131 -> V_144 ;
ASSERT ( ( V_137 -> V_138 >= 0 ) && ( V_137 -> V_138 < V_142 ) ) ;
for ( V_132 = V_137 -> V_132 , V_141 = 0 ; V_141 < V_137 -> V_138 ; V_132 ++ , V_141 ++ ) {
if ( V_132 -> V_143 ) {
error = F_72 ( V_131 -> args -> V_51 ,
V_131 -> args -> V_22 ,
V_132 -> V_101 , V_132 -> V_143 ,
& V_132 -> V_114 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_132 -> V_114 = NULL ;
}
}
return ( 0 ) ;
}
STATIC int
F_9 ( T_1 * args )
{
T_12 * V_131 ;
T_13 * V_132 ;
int error , V_109 ;
int V_145 ;
V_131 = F_93 () ;
V_131 -> args = args ;
V_131 -> V_33 = args -> V_22 -> V_28 ;
V_131 -> V_134 = V_131 -> V_33 -> V_36 . V_37 ;
V_131 -> V_135 = V_131 -> V_33 -> V_136 ;
error = F_94 ( V_131 , & V_109 ) ;
if ( error ) {
V_109 = error ;
} else if ( V_109 == V_26 ) {
V_132 = & V_131 -> V_137 . V_132 [ V_131 -> V_137 . V_138 - 1 ] ;
ASSERT ( V_132 -> V_114 != NULL ) ;
ASSERT ( V_132 -> V_127 == V_128 ) ;
V_109 = F_86 ( V_132 -> V_114 , args ) ;
if ( ! V_109 && ( args -> V_120 > 0 )
&& ! ( args -> V_17 & V_82 ) ) {
V_109 = F_87 ( args ) ;
}
}
for ( V_145 = 0 ; V_145 < V_131 -> V_137 . V_138 ; V_145 ++ ) {
F_74 ( args -> V_51 , V_131 -> V_137 . V_132 [ V_145 ] . V_114 ) ;
V_131 -> V_137 . V_132 [ V_145 ] . V_114 = NULL ;
}
F_96 ( V_131 ) ;
return ( V_109 ) ;
}
STATIC int
F_55 ( T_7 * V_76 )
{
T_9 * V_97 ;
T_11 * V_123 ;
T_15 * V_146 ;
T_16 * V_147 ;
int error , V_145 ;
struct V_113 * V_114 ;
V_97 = V_76 -> V_97 ;
V_97 -> V_100 = 1 ;
V_114 = NULL ;
if ( V_97 -> V_101 > 0 ) {
error = F_72 ( NULL , V_76 -> V_22 , V_97 -> V_101 , - 1 ,
& V_114 , V_24 ) ;
if ( ( error != 0 ) && ( error != V_130 ) )
return ( error ) ;
if ( V_114 ) {
V_146 = V_114 -> V_124 ;
switch ( F_105 ( V_146 -> V_125 . V_126 . V_127 ) ) {
case V_148 :
F_106 ( V_76 ) ;
F_74 ( NULL , V_114 ) ;
V_114 = NULL ;
break;
case V_128 :
V_123 = V_114 -> V_124 ;
if ( V_97 -> V_21 > F_107 ( V_123 -> V_149 [
F_105 ( V_123 -> V_125 . V_83 ) - 1 ] . V_21 ) ) {
F_106 ( V_76 ) ;
F_74 ( NULL , V_114 ) ;
V_114 = NULL ;
} else if ( V_97 -> V_21 <=
F_107 ( V_123 -> V_149 [ 0 ] . V_21 ) ) {
F_106 ( V_76 ) ;
F_74 ( NULL , V_114 ) ;
V_114 = NULL ;
}
break;
default:
F_106 ( V_76 ) ;
F_74 ( NULL , V_114 ) ;
V_114 = NULL ;
}
}
}
if ( V_114 == NULL ) {
V_97 -> V_101 = 0 ;
for (; ; ) {
error = F_72 ( NULL , V_76 -> V_22 ,
V_97 -> V_101 , - 1 , & V_114 ,
V_24 ) ;
if ( error )
return ( error ) ;
if ( F_88 ( V_114 == NULL ) ) {
F_108 ( L_2 ,
V_129 ,
V_76 -> V_22 -> V_28 ) ;
return ( F_47 ( V_130 ) ) ;
}
V_146 = V_114 -> V_124 ;
if ( V_146 -> V_125 . V_126 . V_127 ==
F_89 ( V_128 ) )
break;
if ( F_88 ( V_146 -> V_125 . V_126 . V_127 !=
F_89 ( V_148 ) ) ) {
F_90 ( L_3 ,
V_129 ,
V_76 -> V_22 -> V_28 ,
V_146 ) ;
F_74 ( NULL , V_114 ) ;
return ( F_47 ( V_130 ) ) ;
}
V_147 = V_146 -> V_147 ;
for ( V_145 = 0 ; V_145 < F_105 ( V_146 -> V_125 . V_83 ) ;
V_147 ++ , V_145 ++ ) {
if ( V_97 -> V_21
<= F_107 ( V_147 -> V_21 ) ) {
V_97 -> V_101 = F_107 ( V_147 -> V_150 ) ;
F_109 ( V_76 ,
V_147 ) ;
break;
}
}
if ( V_145 == F_105 ( V_146 -> V_125 . V_83 ) ) {
F_74 ( NULL , V_114 ) ;
return ( 0 ) ;
}
F_74 ( NULL , V_114 ) ;
}
}
ASSERT ( V_114 != NULL ) ;
for (; ; ) {
V_123 = V_114 -> V_124 ;
if ( F_88 ( V_123 -> V_125 . V_126 . V_127 !=
F_89 ( V_128 ) ) ) {
F_90 ( L_4 ,
V_129 ,
V_76 -> V_22 -> V_28 , V_123 ) ;
F_74 ( NULL , V_114 ) ;
return ( F_47 ( V_130 ) ) ;
}
error = F_91 ( V_114 , V_76 ) ;
if ( error ) {
F_74 ( NULL , V_114 ) ;
return error ;
}
if ( V_76 -> V_92 || V_123 -> V_125 . V_126 . V_151 == 0 )
break;
V_97 -> V_101 = F_107 ( V_123 -> V_125 . V_126 . V_151 ) ;
F_74 ( NULL , V_114 ) ;
error = F_72 ( NULL , V_76 -> V_22 , V_97 -> V_101 , - 1 ,
& V_114 , V_24 ) ;
if ( error )
return ( error ) ;
if ( F_88 ( ( V_114 == NULL ) ) ) {
F_108 ( L_5 ,
V_129 ,
V_76 -> V_22 -> V_28 ) ;
return ( F_47 ( V_130 ) ) ;
}
}
F_74 ( NULL , V_114 ) ;
return ( 0 ) ;
}
int
F_87 ( T_1 * args )
{
T_17 V_152 [ V_153 ] ;
T_6 * V_33 ;
T_18 V_154 ;
void * V_155 ;
T_19 * V_114 ;
int V_156 , error , V_157 , V_20 , V_158 , V_145 ;
T_20 V_159 ;
ASSERT ( ! ( args -> V_17 & V_82 ) ) ;
V_33 = args -> V_22 -> V_28 ;
V_155 = args -> V_15 ;
V_20 = args -> V_20 ;
V_159 = args -> V_120 ;
while ( V_20 > 0 ) {
V_156 = V_153 ;
error = F_110 ( args -> V_22 , ( V_160 ) V_159 ,
args -> V_122 , V_152 , & V_156 ,
V_161 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_156 >= 1 ) ;
for ( V_145 = 0 ; ( V_145 < V_156 ) && ( V_20 > 0 ) ; V_145 ++ ) {
ASSERT ( ( V_152 [ V_145 ] . V_162 != V_163 ) &&
( V_152 [ V_145 ] . V_162 != V_164 ) ) ;
V_154 = F_111 ( V_33 , V_152 [ V_145 ] . V_162 ) ;
V_158 = F_112 ( V_33 , V_152 [ V_145 ] . V_165 ) ;
error = F_113 ( V_33 , NULL , V_33 -> V_166 ,
V_154 , V_158 , 0 , & V_114 ) ;
if ( error )
return ( error ) ;
V_157 = F_114 ( int , V_20 , F_115 ( V_114 -> V_167 ) ) ;
F_116 ( V_114 , 0 , V_157 , V_155 , V_168 ) ;
F_117 ( V_114 ) ;
V_155 += V_157 ;
V_20 -= V_157 ;
V_159 += V_152 [ V_145 ] . V_165 ;
}
}
ASSERT ( V_20 == 0 ) ;
return ( 0 ) ;
}
STATIC int
F_78 ( T_1 * args )
{
T_6 * V_33 ;
V_160 V_169 ;
T_2 * V_22 ;
T_17 V_152 ;
T_18 V_154 ;
void * V_170 ;
T_19 * V_114 ;
T_20 V_159 ;
int V_158 , V_20 , V_156 , error , V_157 , V_42 ;
V_22 = args -> V_22 ;
V_33 = V_22 -> V_28 ;
V_170 = args -> V_15 ;
V_158 = F_18 ( V_33 , args -> V_20 ) ;
V_169 = 0 ;
error = F_118 ( args -> V_51 , args -> V_22 , V_158 , & V_169 ,
V_24 ) ;
if ( error ) {
return ( error ) ;
}
args -> V_120 = V_159 = ( T_20 ) V_169 ;
args -> V_122 = V_158 ;
while ( V_158 > 0 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
V_156 = 1 ;
error = F_119 ( args -> V_51 , V_22 , ( V_160 ) V_159 ,
V_158 ,
V_161 | V_171 ,
args -> V_39 , args -> V_50 , & V_152 , & V_156 ,
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
ASSERT ( V_156 == 1 ) ;
ASSERT ( ( V_152 . V_162 != V_163 ) &&
( V_152 . V_162 != V_164 ) ) ;
V_159 += V_152 . V_165 ;
V_158 -= V_152 . V_165 ;
error = F_39 ( & args -> V_51 , V_22 ) ;
if ( error )
return ( error ) ;
}
V_159 = args -> V_120 ;
V_20 = args -> V_20 ;
while ( V_20 > 0 ) {
int V_172 ;
F_35 ( args -> V_40 , args -> V_39 ) ;
V_156 = 1 ;
error = F_110 ( V_22 , ( V_160 ) V_159 ,
args -> V_122 , & V_152 , & V_156 ,
V_161 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_156 == 1 ) ;
ASSERT ( ( V_152 . V_162 != V_163 ) &&
( V_152 . V_162 != V_164 ) ) ;
V_154 = F_111 ( V_33 , V_152 . V_162 ) ,
V_158 = F_112 ( V_33 , V_152 . V_165 ) ;
V_114 = F_120 ( V_33 -> V_166 , V_154 , V_158 , 0 ) ;
if ( ! V_114 )
return V_173 ;
V_172 = F_115 ( V_114 -> V_167 ) ;
V_157 = F_114 ( int , V_20 , V_172 ) ;
F_116 ( V_114 , 0 , V_157 , V_170 , V_174 ) ;
if ( V_157 < V_172 )
F_121 ( V_114 , V_157 , V_172 - V_157 ) ;
error = F_122 ( V_114 ) ;
F_117 ( V_114 ) ;
if ( error )
return error ;
V_170 += V_157 ;
V_20 -= V_157 ;
V_159 += V_152 . V_165 ;
}
ASSERT ( V_20 == 0 ) ;
return ( 0 ) ;
}
STATIC int
F_80 ( T_1 * args )
{
T_6 * V_33 ;
T_17 V_152 ;
T_19 * V_114 ;
T_18 V_154 ;
T_20 V_159 ;
int V_20 , V_158 , V_156 , error , V_175 , V_42 ;
V_33 = args -> V_22 -> V_28 ;
V_159 = args -> V_120 ;
V_20 = args -> V_122 ;
while ( V_20 > 0 ) {
V_156 = 1 ;
error = F_110 ( args -> V_22 , ( V_160 ) V_159 ,
args -> V_122 , & V_152 , & V_156 ,
V_161 ) ;
if ( error )
return ( error ) ;
ASSERT ( V_156 == 1 ) ;
ASSERT ( ( V_152 . V_162 != V_163 ) &&
( V_152 . V_162 != V_164 ) ) ;
V_154 = F_111 ( V_33 , V_152 . V_162 ) ,
V_158 = F_112 ( V_33 , V_152 . V_165 ) ;
V_114 = F_123 ( V_33 -> V_166 , V_154 , V_158 , V_176 ) ;
if ( V_114 ) {
F_124 ( V_114 ) ;
F_117 ( V_114 ) ;
V_114 = NULL ;
}
V_20 -= V_152 . V_165 ;
V_159 += V_152 . V_165 ;
}
V_159 = args -> V_120 ;
V_158 = args -> V_122 ;
V_175 = 0 ;
while ( ! V_175 ) {
F_35 ( args -> V_40 , args -> V_39 ) ;
error = F_125 ( args -> V_51 , args -> V_22 , V_159 , V_158 ,
V_161 | V_171 ,
1 , args -> V_39 , args -> V_40 ,
& V_175 ) ;
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
