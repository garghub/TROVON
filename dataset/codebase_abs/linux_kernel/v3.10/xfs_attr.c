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
error = F_25 ( args . V_51 , args . V_50 ,
F_26 ( V_33 ) +
F_27 ( V_33 ) * args . V_50 ,
0 , V_55 ,
V_56 ) ;
if ( error ) {
F_28 ( args . V_51 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_57 ) ;
error = F_29 ( args . V_51 , V_22 , args . V_50 , 0 ,
V_43 ? V_58 | V_59 :
V_58 ) ;
if ( error ) {
F_14 ( V_22 , V_57 ) ;
F_28 ( args . V_51 , V_60 ) ;
return ( error ) ;
}
F_30 ( args . V_51 , V_22 , 0 ) ;
if ( ( V_22 -> V_11 . V_12 == V_25 ) ||
( ( V_22 -> V_11 . V_12 == V_13 ) &&
( V_22 -> V_11 . V_14 == 0 ) ) ) {
if ( V_22 -> V_11 . V_12 == V_13 )
F_31 ( & args ) ;
error = F_32 ( & args ) ;
if ( error != V_61 ) {
ASSERT ( args . V_51 != NULL ) ;
if ( V_33 -> V_62 & V_63 ) {
F_33 ( args . V_51 ) ;
}
if ( ! error && ( V_17 & V_64 ) == 0 ) {
F_34 ( args . V_51 , V_22 ,
V_65 ) ;
}
V_41 = F_35 ( args . V_51 ,
V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error == 0 ? V_41 : error ) ;
}
F_36 ( args . V_40 , args . V_39 ) ;
error = F_37 ( & args ) ;
if ( ! error ) {
error = F_38 ( & args . V_51 , args . V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args . V_51 = NULL ;
F_39 ( & V_40 ) ;
goto V_66;
}
if ( V_42 )
F_30 ( args . V_51 , V_22 , 0 ) ;
error = F_40 ( & args . V_51 , V_22 ) ;
if ( error )
goto V_66;
}
if ( F_7 ( V_22 , V_24 ) ) {
error = F_41 ( & args ) ;
} else {
error = F_42 ( & args ) ;
}
if ( error ) {
goto V_66;
}
if ( V_33 -> V_62 & V_63 ) {
F_33 ( args . V_51 ) ;
}
if ( ( V_17 & V_64 ) == 0 )
F_34 ( args . V_51 , V_22 , V_65 ) ;
F_43 ( args . V_51 , V_22 , V_67 ) ;
error = F_35 ( args . V_51 , V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
V_66:
if ( args . V_51 )
F_28 ( args . V_51 ,
V_60 | V_68 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
}
int
F_44 (
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
F_45 ( T_2 * V_22 , struct V_1 * V_5 , int V_17 )
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
F_46 ( V_33 ) ,
F_47 ( V_33 ) ,
0 , V_55 ,
V_71 ) ) ) {
F_28 ( args . V_51 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_57 ) ;
F_30 ( args . V_51 , V_22 , 0 ) ;
if ( ! F_2 ( V_22 ) ) {
error = F_48 ( V_18 ) ;
goto V_66;
}
if ( V_22 -> V_11 . V_12 == V_25 ) {
ASSERT ( V_22 -> V_72 -> V_73 & V_74 ) ;
error = F_49 ( & args ) ;
if ( error ) {
goto V_66;
}
} else if ( F_7 ( V_22 , V_24 ) ) {
error = F_50 ( & args ) ;
} else {
error = F_51 ( & args ) ;
}
if ( error ) {
goto V_66;
}
if ( V_33 -> V_62 & V_63 ) {
F_33 ( args . V_51 ) ;
}
if ( ( V_17 & V_64 ) == 0 )
F_34 ( args . V_51 , V_22 , V_65 ) ;
F_43 ( args . V_51 , V_22 , V_67 ) ;
error = F_35 ( args . V_51 , V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
V_66:
if ( args . V_51 )
F_28 ( args . V_51 ,
V_60 | V_68 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
}
int
F_52 (
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
return F_48 ( V_18 ) ;
}
F_14 ( V_22 , V_30 ) ;
return F_45 ( V_22 , & V_2 , V_17 ) ;
}
int
F_53 ( T_7 * V_76 )
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
error = F_54 ( V_76 ) ;
} else if ( F_7 ( V_22 , V_24 ) ) {
error = F_55 ( V_76 ) ;
} else {
error = F_56 ( V_76 ) ;
}
F_14 ( V_22 , V_30 ) ;
return error ;
}
STATIC int
F_57 (
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
V_76 -> V_85 -= F_58 ( V_19 ) ;
if ( V_76 -> V_85 < V_81 ) {
F_59 ( V_76 ) ;
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
F_60 ( V_76 ) ;
return 0 ;
}
int
F_61 (
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
return ( F_48 ( V_4 ) ) ;
if ( ( V_97 -> V_100 == 0 ) &&
( V_97 -> V_21 || V_97 -> V_101 || V_97 -> V_102 ) )
return F_48 ( V_4 ) ;
if ( ( ( long ) V_96 ) & ( sizeof( int ) - 1 ) )
return F_48 ( V_8 ) ;
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
V_76 . V_104 = F_57 ;
V_79 = (struct V_78 * ) V_76 . V_79 ;
V_79 -> V_95 = 0 ;
V_79 -> V_91 = 0 ;
V_79 -> V_90 [ 0 ] = V_76 . V_86 ;
error = F_53 ( & V_76 ) ;
ASSERT ( error >= 0 ) ;
return error ;
}
int
F_62 ( T_2 * V_22 )
{
T_10 * V_51 ;
T_6 * V_33 ;
int error ;
V_33 = V_22 -> V_28 ;
ASSERT ( ! F_63 ( V_33 , V_22 ) ) ;
F_13 ( V_22 , V_30 ) ;
if ( ! F_2 ( V_22 ) ||
V_22 -> V_11 . V_12 == V_25 ) {
F_14 ( V_22 , V_30 ) ;
return 0 ;
}
F_14 ( V_22 , V_30 ) ;
V_51 = F_24 ( V_33 , V_105 ) ;
if ( ( error = F_25 ( V_51 , 0 , F_64 ( V_33 ) , 0 ,
V_55 ,
V_106 ) ) ) {
F_28 ( V_51 , 0 ) ;
return ( error ) ;
}
F_13 ( V_22 , V_57 ) ;
F_30 ( V_51 , V_22 , 0 ) ;
if ( ! F_2 ( V_22 ) ||
V_22 -> V_11 . V_12 == V_25 ) {
error = 0 ;
goto V_66;
}
error = F_65 ( & V_51 , V_22 ) ;
if ( error )
goto V_66;
error = F_66 ( & V_51 , V_22 , V_24 , 0 ) ;
if ( error )
goto V_66;
error = F_35 ( V_51 , V_60 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
V_66:
F_28 ( V_51 , V_60 | V_68 ) ;
F_14 ( V_22 , V_57 ) ;
return ( error ) ;
}
STATIC int
F_32 ( T_1 * args )
{
int V_107 , V_108 , V_109 ;
F_67 ( args ) ;
V_109 = F_68 ( args ) ;
if ( ( args -> V_17 & V_110 ) && ( V_109 == V_18 ) ) {
return ( V_109 ) ;
} else if ( V_109 == V_26 ) {
if ( args -> V_17 & V_111 )
return ( V_109 ) ;
V_109 = F_49 ( args ) ;
ASSERT ( V_109 == 0 ) ;
}
if ( args -> V_19 >= V_112 ||
args -> V_20 >= V_112 )
return ( F_48 ( V_61 ) ) ;
V_107 = F_69 ( args -> V_22 ) ;
V_107 += F_22 ( args -> V_19 , args -> V_20 ) ;
V_108 = F_70 ( args -> V_22 , V_107 ) ;
if ( ! V_108 )
return ( F_48 ( V_61 ) ) ;
F_71 ( args , V_108 ) ;
return ( 0 ) ;
}
STATIC int
F_41 ( T_1 * args )
{
T_2 * V_22 ;
struct V_113 * V_114 ;
int V_109 , error , V_42 , V_108 ;
F_72 ( args ) ;
V_22 = args -> V_22 ;
args -> V_101 = 0 ;
error = F_73 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_114 ) ;
if ( error )
return error ;
V_109 = F_74 ( V_114 , args ) ;
if ( ( args -> V_17 & V_110 ) && ( V_109 == V_18 ) ) {
F_75 ( args -> V_51 , V_114 ) ;
return V_109 ;
} else if ( V_109 == V_26 ) {
if ( args -> V_17 & V_111 ) {
F_75 ( args -> V_51 , V_114 ) ;
return V_109 ;
}
F_76 ( args ) ;
args -> V_47 |= V_115 ;
args -> V_116 = args -> V_101 ;
args -> V_117 = args -> V_118 ;
args -> V_119 = args -> V_120 ;
args -> V_121 = args -> V_122 ;
}
V_109 = F_77 ( V_114 , args ) ;
if ( V_109 == V_61 ) {
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_78 ( args ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
error = F_40 ( & args -> V_51 , V_22 ) ;
if ( error )
return ( error ) ;
error = F_42 ( args ) ;
return ( error ) ;
}
error = F_40 ( & args -> V_51 , V_22 ) ;
if ( error )
return ( error ) ;
if ( args -> V_120 > 0 ) {
error = F_79 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_47 & V_115 ) {
error = F_80 ( args ) ;
if ( error )
return ( error ) ;
args -> V_118 = args -> V_117 ;
args -> V_101 = args -> V_116 ;
args -> V_120 = args -> V_119 ;
args -> V_122 = args -> V_121 ;
if ( args -> V_120 ) {
error = F_81 ( args ) ;
if ( error )
return ( error ) ;
}
error = F_73 ( args -> V_51 , args -> V_22 , args -> V_101 ,
- 1 , & V_114 ) ;
if ( error )
return error ;
F_82 ( V_114 , args ) ;
if ( ( V_108 = F_83 ( V_114 , V_22 ) ) ) {
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_84 ( V_114 , args , V_108 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
return ( error ) ;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
}
error = F_40 ( & args -> V_51 , V_22 ) ;
} else if ( args -> V_120 > 0 ) {
error = F_85 ( args ) ;
}
return error ;
}
STATIC int
F_50 ( T_1 * args )
{
T_2 * V_22 ;
struct V_113 * V_114 ;
int error , V_42 , V_108 ;
F_86 ( args ) ;
V_22 = args -> V_22 ;
args -> V_101 = 0 ;
error = F_73 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_114 ) ;
if ( error )
return error ;
error = F_74 ( V_114 , args ) ;
if ( error == V_18 ) {
F_75 ( args -> V_51 , V_114 ) ;
return error ;
}
F_82 ( V_114 , args ) ;
if ( ( V_108 = F_83 ( V_114 , V_22 ) ) ) {
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_84 ( V_114 , args , V_108 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
return error ;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
}
return 0 ;
}
STATIC int
F_8 ( T_1 * args )
{
struct V_113 * V_114 ;
int error ;
F_87 ( args ) ;
args -> V_101 = 0 ;
error = F_73 ( args -> V_51 , args -> V_22 , args -> V_101 , - 1 , & V_114 ) ;
if ( error )
return error ;
error = F_74 ( V_114 , args ) ;
if ( error != V_26 ) {
F_75 ( args -> V_51 , V_114 ) ;
return error ;
}
error = F_88 ( V_114 , args ) ;
F_75 ( args -> V_51 , V_114 ) ;
if ( ! error && ( args -> V_120 > 0 ) && ! ( args -> V_17 & V_82 ) ) {
error = F_89 ( args ) ;
}
return error ;
}
STATIC int
F_55 ( T_7 * V_76 )
{
int error ;
struct V_113 * V_114 ;
F_90 ( V_76 ) ;
V_76 -> V_97 -> V_101 = 0 ;
error = F_73 ( NULL , V_76 -> V_22 , 0 , - 1 , & V_114 ) ;
if ( error )
return F_48 ( error ) ;
error = F_91 ( V_114 , V_76 ) ;
F_75 ( NULL , V_114 ) ;
return F_48 ( error ) ;
}
STATIC int
F_42 ( T_1 * args )
{
T_11 * V_123 ;
T_12 * V_124 ;
T_2 * V_22 ;
T_6 * V_33 ;
int V_42 , V_109 , error ;
F_92 ( args ) ;
V_22 = args -> V_22 ;
V_33 = V_22 -> V_28 ;
V_125:
V_123 = F_93 () ;
V_123 -> args = args ;
V_123 -> V_33 = V_33 ;
V_123 -> V_126 = V_123 -> V_33 -> V_36 . V_37 ;
V_123 -> V_127 = V_123 -> V_33 -> V_128 ;
error = F_94 ( V_123 , & V_109 ) ;
if ( error )
goto V_66;
V_124 = & V_123 -> V_129 . V_124 [ V_123 -> V_129 . V_130 - 1 ] ;
ASSERT ( V_124 -> V_131 == V_132 ) ;
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
V_109 = F_77 ( V_124 -> V_114 , V_123 -> args ) ;
if ( V_109 == V_61 ) {
if ( V_123 -> V_129 . V_130 == 1 ) {
F_96 ( V_123 ) ;
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_78 ( args ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
error = F_40 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
goto V_125;
}
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_97 ( V_123 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
} else {
F_98 ( V_123 , & V_123 -> V_129 ) ;
}
F_96 ( V_123 ) ;
V_123 = NULL ;
error = F_40 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
if ( args -> V_120 > 0 ) {
error = F_79 ( args ) ;
if ( error )
return ( error ) ;
}
if ( args -> V_47 & V_115 ) {
error = F_80 ( args ) ;
if ( error )
goto V_66;
args -> V_118 = args -> V_117 ;
args -> V_101 = args -> V_116 ;
args -> V_120 = args -> V_119 ;
args -> V_122 = args -> V_121 ;
if ( args -> V_120 ) {
error = F_81 ( args ) ;
if ( error )
return ( error ) ;
}
args -> V_17 |= V_133 ;
V_123 = F_93 () ;
V_123 -> args = args ;
V_123 -> V_33 = V_33 ;
V_123 -> V_126 = V_123 -> V_33 -> V_36 . V_37 ;
V_123 -> V_127 = V_123 -> V_33 -> V_128 ;
V_123 -> V_134 = 0 ;
error = F_94 ( V_123 , & V_109 ) ;
if ( error )
goto V_66;
V_124 = & V_123 -> V_129 . V_124 [ V_123 -> V_129 . V_130 - 1 ] ;
ASSERT ( V_124 -> V_131 == V_132 ) ;
error = F_82 ( V_124 -> V_114 , args ) ;
F_98 ( V_123 , & V_123 -> V_129 ) ;
if ( V_109 && ( V_123 -> V_129 . V_130 > 1 ) ) {
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_99 ( V_123 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
}
error = F_40 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
} else if ( args -> V_120 > 0 ) {
error = F_85 ( args ) ;
if ( error )
goto V_66;
}
V_109 = error = 0 ;
V_66:
if ( V_123 )
F_96 ( V_123 ) ;
if ( error )
return ( error ) ;
return ( V_109 ) ;
}
STATIC int
F_51 ( T_1 * args )
{
T_11 * V_123 ;
T_12 * V_124 ;
T_2 * V_22 ;
struct V_113 * V_114 ;
int V_109 , error , V_42 , V_108 ;
F_100 ( args ) ;
V_22 = args -> V_22 ;
V_123 = F_93 () ;
V_123 -> args = args ;
V_123 -> V_33 = V_22 -> V_28 ;
V_123 -> V_126 = V_123 -> V_33 -> V_36 . V_37 ;
V_123 -> V_127 = V_123 -> V_33 -> V_128 ;
error = F_94 ( V_123 , & V_109 ) ;
if ( error || ( V_109 != V_26 ) ) {
if ( error == 0 )
error = V_109 ;
goto V_66;
}
V_124 = & V_123 -> V_129 . V_124 [ V_123 -> V_129 . V_130 - 1 ] ;
ASSERT ( V_124 -> V_114 != NULL ) ;
ASSERT ( V_124 -> V_131 == V_132 ) ;
if ( args -> V_120 > 0 ) {
error = F_101 ( V_123 ) ;
if ( error )
goto V_66;
error = F_102 ( args ) ;
if ( error )
goto V_66;
error = F_81 ( args ) ;
if ( error )
goto V_66;
error = F_103 ( V_123 ) ;
if ( error )
goto V_66;
}
V_124 = & V_123 -> V_129 . V_124 [ V_123 -> V_129 . V_130 - 1 ] ;
ASSERT ( V_124 -> V_131 == V_132 ) ;
V_109 = F_82 ( V_124 -> V_114 , args ) ;
F_98 ( V_123 , & V_123 -> V_129 ) ;
if ( V_109 && ( V_123 -> V_129 . V_130 > 1 ) ) {
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_99 ( V_123 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 , args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
error = F_40 ( & args -> V_51 , V_22 ) ;
if ( error )
goto V_66;
}
if ( F_7 ( V_22 , V_24 ) ) {
ASSERT ( V_123 -> V_129 . V_130 == 1 ) ;
ASSERT ( V_123 -> V_129 . V_124 [ 0 ] . V_114 ) ;
V_123 -> V_129 . V_124 [ 0 ] . V_114 = NULL ;
error = F_73 ( args -> V_51 , args -> V_22 , 0 , - 1 , & V_114 ) ;
if ( error )
goto V_66;
if ( ( V_108 = F_83 ( V_114 , V_22 ) ) ) {
F_36 ( args -> V_40 , args -> V_39 ) ;
error = F_84 ( V_114 , args , V_108 ) ;
if ( ! error ) {
error = F_38 ( & args -> V_51 ,
args -> V_40 ,
& V_42 ) ;
}
if ( error ) {
ASSERT ( V_42 ) ;
args -> V_51 = NULL ;
F_39 ( args -> V_40 ) ;
goto V_66;
}
if ( V_42 )
F_30 ( args -> V_51 , V_22 , 0 ) ;
} else
F_75 ( args -> V_51 , V_114 ) ;
}
error = 0 ;
V_66:
F_96 ( V_123 ) ;
return ( error ) ;
}
STATIC int
F_101 ( T_11 * V_123 )
{
T_13 * V_129 ;
T_12 * V_124 ;
int V_135 ;
F_104 ( V_123 -> args ) ;
V_129 = & V_123 -> V_129 ;
ASSERT ( ( V_129 -> V_130 >= 0 ) && ( V_129 -> V_130 < V_136 ) ) ;
for ( V_124 = V_129 -> V_124 , V_135 = 0 ; V_135 < V_129 -> V_130 ; V_124 ++ , V_135 ++ ) {
if ( V_124 -> V_114 ) {
V_124 -> V_137 = F_105 ( V_124 -> V_114 ) ;
V_124 -> V_114 = NULL ;
} else {
V_124 -> V_137 = 0 ;
}
}
V_129 = & V_123 -> V_138 ;
ASSERT ( ( V_129 -> V_130 >= 0 ) && ( V_129 -> V_130 < V_136 ) ) ;
for ( V_124 = V_129 -> V_124 , V_135 = 0 ; V_135 < V_129 -> V_130 ; V_124 ++ , V_135 ++ ) {
if ( V_124 -> V_114 ) {
V_124 -> V_137 = F_105 ( V_124 -> V_114 ) ;
V_124 -> V_114 = NULL ;
} else {
V_124 -> V_137 = 0 ;
}
}
return ( 0 ) ;
}
STATIC int
F_103 ( T_11 * V_123 )
{
T_13 * V_129 ;
T_12 * V_124 ;
int V_135 , error ;
F_106 ( V_123 -> args ) ;
V_129 = & V_123 -> V_129 ;
ASSERT ( ( V_129 -> V_130 >= 0 ) && ( V_129 -> V_130 < V_136 ) ) ;
for ( V_124 = V_129 -> V_124 , V_135 = 0 ; V_135 < V_129 -> V_130 ; V_124 ++ , V_135 ++ ) {
if ( V_124 -> V_137 ) {
error = F_107 ( V_123 -> args -> V_51 ,
V_123 -> args -> V_22 ,
V_124 -> V_101 , V_124 -> V_137 ,
& V_124 -> V_114 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_124 -> V_114 = NULL ;
}
}
V_129 = & V_123 -> V_138 ;
ASSERT ( ( V_129 -> V_130 >= 0 ) && ( V_129 -> V_130 < V_136 ) ) ;
for ( V_124 = V_129 -> V_124 , V_135 = 0 ; V_135 < V_129 -> V_130 ; V_124 ++ , V_135 ++ ) {
if ( V_124 -> V_137 ) {
error = F_107 ( V_123 -> args -> V_51 ,
V_123 -> args -> V_22 ,
V_124 -> V_101 , V_124 -> V_137 ,
& V_124 -> V_114 , V_24 ) ;
if ( error )
return ( error ) ;
} else {
V_124 -> V_114 = NULL ;
}
}
return ( 0 ) ;
}
STATIC int
F_9 ( T_1 * args )
{
T_11 * V_123 ;
T_12 * V_124 ;
int error , V_109 ;
int V_139 ;
F_108 ( args ) ;
V_123 = F_93 () ;
V_123 -> args = args ;
V_123 -> V_33 = args -> V_22 -> V_28 ;
V_123 -> V_126 = V_123 -> V_33 -> V_36 . V_37 ;
V_123 -> V_127 = V_123 -> V_33 -> V_128 ;
error = F_94 ( V_123 , & V_109 ) ;
if ( error ) {
V_109 = error ;
} else if ( V_109 == V_26 ) {
V_124 = & V_123 -> V_129 . V_124 [ V_123 -> V_129 . V_130 - 1 ] ;
ASSERT ( V_124 -> V_114 != NULL ) ;
ASSERT ( V_124 -> V_131 == V_132 ) ;
V_109 = F_88 ( V_124 -> V_114 , args ) ;
if ( ! V_109 && ( args -> V_120 > 0 )
&& ! ( args -> V_17 & V_82 ) ) {
V_109 = F_89 ( args ) ;
}
}
for ( V_139 = 0 ; V_139 < V_123 -> V_129 . V_130 ; V_139 ++ ) {
F_75 ( args -> V_51 , V_123 -> V_129 . V_124 [ V_139 ] . V_114 ) ;
V_123 -> V_129 . V_124 [ V_139 ] . V_114 = NULL ;
}
F_96 ( V_123 ) ;
return ( V_109 ) ;
}
STATIC int
F_56 ( T_7 * V_76 )
{
T_9 * V_97 ;
T_14 * V_140 ;
T_15 * V_141 ;
struct V_142 V_143 ;
struct V_144 V_145 ;
struct V_146 * V_147 ;
int error , V_139 ;
struct V_113 * V_114 ;
F_109 ( V_76 ) ;
V_97 = V_76 -> V_97 ;
V_97 -> V_100 = 1 ;
V_114 = NULL ;
if ( V_97 -> V_101 > 0 ) {
error = F_107 ( NULL , V_76 -> V_22 , V_97 -> V_101 , - 1 ,
& V_114 , V_24 ) ;
if ( ( error != 0 ) && ( error != V_148 ) )
return ( error ) ;
if ( V_114 ) {
struct V_149 * V_150 ;
V_141 = V_114 -> V_151 ;
switch ( F_110 ( V_141 -> V_152 . V_153 . V_131 ) ) {
case V_154 :
case V_155 :
F_111 ( V_76 ) ;
F_75 ( NULL , V_114 ) ;
V_114 = NULL ;
break;
case V_132 :
case V_156 :
V_140 = V_114 -> V_151 ;
F_112 ( & V_143 , V_140 ) ;
V_150 = F_113 ( V_140 ) ;
if ( V_97 -> V_21 > F_114 (
V_150 [ V_143 . V_83 - 1 ] . V_21 ) ) {
F_111 ( V_76 ) ;
F_75 ( NULL , V_114 ) ;
V_114 = NULL ;
} else if ( V_97 -> V_21 <= F_114 (
V_150 [ 0 ] . V_21 ) ) {
F_111 ( V_76 ) ;
F_75 ( NULL , V_114 ) ;
V_114 = NULL ;
}
break;
default:
F_111 ( V_76 ) ;
F_75 ( NULL , V_114 ) ;
V_114 = NULL ;
}
}
}
if ( V_114 == NULL ) {
V_97 -> V_101 = 0 ;
for (; ; ) {
T_16 V_131 ;
error = F_107 ( NULL , V_76 -> V_22 ,
V_97 -> V_101 , - 1 , & V_114 ,
V_24 ) ;
if ( error )
return ( error ) ;
V_141 = V_114 -> V_151 ;
V_131 = F_110 ( V_141 -> V_152 . V_153 . V_131 ) ;
if ( V_131 == V_132 ||
V_131 == V_156 )
break;
if ( V_131 != V_154 &&
V_131 != V_155 ) {
F_115 ( L_1 ,
V_157 ,
V_76 -> V_22 -> V_28 ,
V_141 ) ;
F_75 ( NULL , V_114 ) ;
return F_48 ( V_148 ) ;
}
F_116 ( & V_145 , V_141 ) ;
V_147 = F_117 ( V_141 ) ;
for ( V_139 = 0 ; V_139 < V_145 . V_83 ; V_147 ++ , V_139 ++ ) {
if ( V_97 -> V_21
<= F_114 ( V_147 -> V_21 ) ) {
V_97 -> V_101 = F_114 ( V_147 -> V_158 ) ;
F_118 ( V_76 ,
V_147 ) ;
break;
}
}
if ( V_139 == V_145 . V_83 ) {
F_75 ( NULL , V_114 ) ;
return 0 ;
}
F_75 ( NULL , V_114 ) ;
}
}
ASSERT ( V_114 != NULL ) ;
for (; ; ) {
V_140 = V_114 -> V_151 ;
error = F_91 ( V_114 , V_76 ) ;
if ( error ) {
F_75 ( NULL , V_114 ) ;
return error ;
}
F_112 ( & V_143 , V_140 ) ;
if ( V_76 -> V_92 || V_143 . V_159 == 0 )
break;
V_97 -> V_101 = V_143 . V_159 ;
F_75 ( NULL , V_114 ) ;
error = F_73 ( NULL , V_76 -> V_22 , V_97 -> V_101 , - 1 ,
& V_114 ) ;
if ( error )
return error ;
}
F_75 ( NULL , V_114 ) ;
return 0 ;
}
