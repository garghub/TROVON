int
F_1 (
T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 )
{
T_4 V_4 ;
T_5 * V_5 ;
T_6 * V_6 ;
int V_7 ;
T_7 * V_8 ;
int V_9 ;
int V_10 ;
int V_11 ;
int V_12 ;
T_8 * V_13 ;
int V_14 ;
T_9 V_15 = 0 ;
int V_16 = 0 ;
int V_17 ;
struct V_18 * V_19 ;
V_13 = V_1 -> V_20 ;
V_19 = V_13 -> V_21 ;
V_17 = F_2 ( & V_13 -> V_22 ) ? 1 : 0 ;
V_7 = V_10 = V_14 = 0 ;
V_6 = F_3 ( V_19 , V_2 ) ;
V_5 = F_4 ( V_6 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 -> V_7 ) ; V_9 ++ ) {
if ( ( V_4 = F_5 ( V_5 [ V_9 ] . V_23 ) ) == V_24 )
continue;
V_8 = ( T_7 * ) ( ( char * ) V_2 +
F_6 ( V_19 , V_4 ) ) ;
V_11 = V_8 -> V_14 == 1 && V_8 -> V_25 [ 0 ] == '.' ;
V_12 =
V_8 -> V_14 == 2 &&
V_8 -> V_25 [ 0 ] == '.' && V_8 -> V_25 [ 1 ] == '.' ;
if ( ! V_11 )
V_10 += F_7 ( V_8 -> V_26 ) > V_27 ;
if ( ! V_11 && ! V_12 ) {
V_7 ++ ;
V_14 += V_8 -> V_14 + V_17 ;
} else if ( V_12 )
V_15 = F_7 ( V_8 -> V_26 ) ;
V_16 = F_8 ( V_10 ) +
V_7 * 3 * sizeof( V_28 ) +
V_14 +
( V_10 ?
V_7 * V_29 :
V_7 * V_30 ) ;
if ( V_16 > F_9 ( V_1 ) )
return V_16 ;
}
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
V_1 -> V_31 -> V_32 ( V_3 , V_15 ) ;
return V_16 ;
}
int
F_10 (
T_10 * args ,
struct V_33 * V_34 ,
int V_16 ,
T_3 * V_3 )
{
T_2 * V_2 ;
T_6 * V_6 ;
T_7 * V_8 ;
T_1 * V_1 ;
T_11 * V_35 ;
char * V_36 ;
int error ;
int V_37 ;
T_8 * V_13 ;
char * V_38 ;
T_12 * V_39 ;
T_3 * V_40 ;
T_3 * V_41 ;
F_11 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_41 = F_12 ( V_13 -> V_22 . V_42 , V_43 ) ;
V_2 = V_34 -> V_44 ;
V_40 = ( T_3 * ) V_41 ;
memcpy ( V_40 , V_3 , F_8 ( V_3 -> V_10 ) ) ;
V_6 = F_3 ( args -> V_19 , V_2 ) ;
V_38 = ( char * ) V_1 -> V_31 -> V_45 ( V_2 ) ;
V_36 = ( char * ) F_4 ( V_6 ) ;
V_39 = F_13 ( V_40 ) ;
while ( V_38 < V_36 ) {
V_35 = ( T_11 * ) V_38 ;
if ( F_14 ( V_35 -> V_46 ) == V_47 ) {
V_38 += F_14 ( V_35 -> V_48 ) ;
continue;
}
V_8 = ( T_7 * ) V_38 ;
if ( V_8 -> V_14 == 1 && V_8 -> V_25 [ 0 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_26 ) == V_1 -> V_49 ) ;
else if ( V_8 -> V_14 == 2 &&
V_8 -> V_25 [ 0 ] == '.' && V_8 -> V_25 [ 1 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_26 ) ==
V_1 -> V_31 -> V_50 ( V_40 ) ) ;
else {
V_39 -> V_14 = V_8 -> V_14 ;
F_15 ( V_39 ,
( V_51 )
( ( char * ) V_8 - ( char * ) V_2 ) ) ;
memcpy ( V_39 -> V_25 , V_8 -> V_25 , V_8 -> V_14 ) ;
V_1 -> V_31 -> V_52 ( V_40 , V_39 ,
F_7 ( V_8 -> V_26 ) ) ;
V_1 -> V_31 -> V_53 ( V_39 ,
V_1 -> V_31 -> V_54 ( V_8 ) ) ;
V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ;
}
V_38 += V_1 -> V_31 -> V_56 ( V_8 -> V_14 ) ;
}
ASSERT ( ( char * ) V_39 - ( char * ) V_40 == V_16 ) ;
V_37 = V_57 ;
error = F_16 ( args , args -> V_19 -> V_58 , V_34 ) ;
if ( error ) {
ASSERT ( error != - V_59 ) ;
goto V_60;
}
ASSERT ( V_1 -> V_61 . V_62 == 0 ) ;
F_17 ( V_1 , V_63 , V_41 , V_16 ) ;
V_1 -> V_64 . V_65 = V_66 ;
V_1 -> V_64 . V_67 = V_16 ;
V_37 |= V_68 ;
F_18 ( args ) ;
V_60:
F_19 ( args -> V_69 , V_1 , V_37 ) ;
F_20 ( V_41 ) ;
return error ;
}
int
F_21 (
T_10 * args )
{
T_1 * V_1 ;
int error ;
int V_70 ;
int V_71 ;
int V_72 ;
V_51 V_73 = 0 ;
int V_74 ;
T_3 * V_40 ;
T_12 * V_39 = NULL ;
F_22 ( args ) ;
ASSERT ( F_23 ( args ) == - V_75 ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_61 . V_76 & V_77 ) ;
if ( V_1 -> V_64 . V_67 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_78 ;
}
ASSERT ( V_1 -> V_61 . V_62 == V_1 -> V_64 . V_67 ) ;
ASSERT ( V_1 -> V_61 . V_79 . V_80 != NULL ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
ASSERT ( V_1 -> V_64 . V_67 >= F_8 ( V_40 -> V_10 ) ) ;
V_70 = V_1 -> V_31 -> V_81 ( V_40 , args -> V_14 ) ;
V_72 = 0 ;
if ( args -> V_26 > V_27 && V_40 -> V_10 == 0 ) {
V_70 += ( V_40 -> V_7 + 2 ) * V_82 ;
V_72 = 1 ;
}
V_71 = ( int ) V_1 -> V_64 . V_67 + V_70 ;
if ( V_71 > F_9 ( V_1 ) ||
( V_74 =
F_26 ( args , V_72 , & V_39 , & V_73 ) ) == 0 ) {
if ( ( args -> V_83 & V_84 ) || args -> V_85 == 0 )
return - V_59 ;
error = F_27 ( args ) ;
if ( error )
return error ;
return F_28 ( args ) ;
}
if ( args -> V_83 & V_84 )
return 0 ;
if ( V_74 == 1 )
F_29 ( args , V_39 , V_73 , V_71 ) ;
else {
ASSERT ( V_74 == 2 ) ;
if ( V_72 )
F_30 ( args ) ;
F_31 ( args , V_72 , V_71 ) ;
}
F_19 ( args -> V_69 , V_1 , V_57 | V_68 ) ;
return 0 ;
}
static void
F_29 (
T_10 * args ,
T_12 * V_39 ,
V_51 V_73 ,
int V_71 )
{
int V_86 ;
T_1 * V_1 ;
T_3 * V_40 ;
V_1 = args -> V_1 ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_86 = ( int ) ( ( char * ) V_39 - ( char * ) V_40 ) ;
F_32 ( V_1 , V_1 -> V_31 -> V_81 ( V_40 , args -> V_14 ) ,
V_63 ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_39 = ( T_12 * ) ( ( char * ) V_40 + V_86 ) ;
V_39 -> V_14 = args -> V_14 ;
F_15 ( V_39 , V_73 ) ;
memcpy ( V_39 -> V_25 , args -> V_25 , V_39 -> V_14 ) ;
V_1 -> V_31 -> V_52 ( V_40 , V_39 , args -> V_26 ) ;
V_1 -> V_31 -> V_53 ( V_39 , args -> V_87 ) ;
V_40 -> V_7 ++ ;
if ( args -> V_26 > V_27 )
V_40 -> V_10 ++ ;
V_1 -> V_64 . V_67 = V_71 ;
F_18 ( args ) ;
}
static void
F_31 (
T_10 * args ,
int V_72 ,
int V_71 )
{
int V_88 ;
char * V_89 ;
T_1 * V_1 ;
int V_90 ;
int V_91 ;
V_51 V_92 ;
V_51 V_73 ;
int V_93 ;
T_12 * V_94 ;
T_3 * V_95 ;
T_12 * V_39 ;
T_3 * V_40 ;
V_1 = args -> V_1 ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_93 = ( int ) V_1 -> V_64 . V_67 ;
V_89 = F_12 ( V_93 , V_43 ) ;
V_95 = ( T_3 * ) V_89 ;
memcpy ( V_95 , V_40 , V_93 ) ;
for ( V_73 = V_1 -> V_31 -> V_96 ,
V_94 = F_13 ( V_95 ) ,
V_88 = V_1 -> V_31 -> V_56 ( args -> V_14 ) ,
V_90 = ( char * ) V_94 == & V_89 [ V_93 ] ;
! V_90 ;
V_73 = V_92 + V_1 -> V_31 -> V_56 ( V_94 -> V_14 ) ,
V_94 = V_1 -> V_31 -> V_55 ( V_95 , V_94 ) ,
V_90 = ( char * ) V_94 == & V_89 [ V_93 ] ) {
V_92 = F_33 ( V_94 ) ;
if ( V_73 + V_88 <= V_92 )
break;
}
F_32 ( V_1 , - V_93 , V_63 ) ;
F_32 ( V_1 , V_71 , V_63 ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_91 = ( int ) ( ( char * ) V_94 - ( char * ) V_95 ) ;
memcpy ( V_40 , V_95 , V_91 ) ;
V_39 = ( T_12 * ) ( ( char * ) V_40 + V_91 ) ;
V_39 -> V_14 = args -> V_14 ;
F_15 ( V_39 , V_73 ) ;
memcpy ( V_39 -> V_25 , args -> V_25 , V_39 -> V_14 ) ;
V_1 -> V_31 -> V_52 ( V_40 , V_39 , args -> V_26 ) ;
V_1 -> V_31 -> V_53 ( V_39 , args -> V_87 ) ;
V_40 -> V_7 ++ ;
if ( args -> V_26 > V_27 && ! V_72 )
V_40 -> V_10 ++ ;
if ( ! V_90 ) {
V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ;
memcpy ( V_39 , V_94 , V_93 - V_91 ) ;
}
F_20 ( V_89 ) ;
V_1 -> V_64 . V_67 = V_71 ;
F_18 ( args ) ;
}
static int
F_26 (
T_10 * args ,
int V_72 ,
T_12 * * V_97 ,
V_51 * V_98 )
{
T_1 * V_1 ;
int V_99 ;
int V_9 ;
V_51 V_73 ;
T_12 * V_39 ;
T_3 * V_40 ;
int V_16 ;
int V_100 ;
V_1 = args -> V_1 ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_16 = V_1 -> V_31 -> V_56 ( args -> V_14 ) ;
V_73 = V_1 -> V_31 -> V_96 ;
V_39 = F_13 ( V_40 ) ;
V_99 = 0 ;
for ( V_9 = 0 ; V_9 < V_40 -> V_7 ; V_9 ++ ) {
if ( ! V_99 )
V_99 = V_73 + V_16 <= F_33 ( V_39 ) ;
V_73 = F_33 ( V_39 ) +
V_1 -> V_31 -> V_56 ( V_39 -> V_14 ) ;
V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ;
}
V_100 = V_73 +
( V_40 -> V_7 + 3 ) * ( V_101 ) sizeof( T_5 ) +
( V_101 ) sizeof( T_6 ) ;
if ( V_100 + ( V_99 ? 0 : V_16 ) > args -> V_19 -> V_102 )
return 0 ;
if ( V_72 )
return 2 ;
if ( V_100 + V_16 > args -> V_19 -> V_102 )
return 2 ;
* V_97 = V_39 ;
* V_98 = V_73 ;
return 1 ;
}
static void
F_18 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int V_10 ;
T_9 V_103 ;
int V_73 ;
T_12 * V_39 ;
T_3 * V_40 ;
V_1 = args -> V_1 ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_73 = V_1 -> V_31 -> V_96 ;
V_103 = V_1 -> V_31 -> V_50 ( V_40 ) ;
V_10 = V_103 > V_27 ;
for ( V_9 = 0 , V_39 = F_13 ( V_40 ) ;
V_9 < V_40 -> V_7 ;
V_9 ++ , V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ) {
ASSERT ( F_33 ( V_39 ) >= V_73 ) ;
V_103 = V_1 -> V_31 -> V_104 ( V_40 , V_39 ) ;
V_10 += V_103 > V_27 ;
V_73 =
F_33 ( V_39 ) +
V_1 -> V_31 -> V_56 ( V_39 -> V_14 ) ;
ASSERT ( V_1 -> V_31 -> V_105 ( V_39 ) < V_106 ) ;
}
ASSERT ( V_10 == V_40 -> V_10 ) ;
ASSERT ( ( char * ) V_39 - ( char * ) V_40 == V_1 -> V_64 . V_67 ) ;
ASSERT ( V_73 +
( V_40 -> V_7 + 2 ) * ( V_101 ) sizeof( T_5 ) +
( V_101 ) sizeof( T_6 ) <= args -> V_19 -> V_102 ) ;
}
int
F_34 (
struct V_107 * V_108 )
{
struct V_109 * V_13 = V_108 -> V_20 ;
struct V_110 * V_40 ;
struct V_111 * V_39 ;
struct V_111 * V_112 ;
char * V_113 ;
const struct V_114 * V_115 ;
struct V_116 * V_117 ;
T_9 V_103 ;
int V_9 ;
int V_10 ;
int V_73 ;
int V_16 ;
int error ;
T_13 V_87 ;
ASSERT ( V_108 -> V_64 . V_65 == V_66 ) ;
V_115 = F_35 ( V_13 , NULL ) ;
V_117 = F_36 ( V_108 , V_63 ) ;
V_40 = (struct V_110 * ) V_117 -> V_79 . V_80 ;
V_16 = V_117 -> V_62 ;
if ( V_16 <= F_24 ( struct V_110 , V_15 ) ||
V_16 < F_8 ( V_40 -> V_10 ) )
return - V_118 ;
V_113 = ( char * ) V_40 + V_16 ;
V_103 = V_115 -> V_50 ( V_40 ) ;
V_10 = V_103 > V_27 ;
error = F_37 ( V_13 , V_103 ) ;
if ( error )
return error ;
V_73 = V_115 -> V_96 ;
V_39 = F_13 ( V_40 ) ;
for ( V_9 = 0 ; V_9 < V_40 -> V_7 ; V_9 ++ ) {
if ( ( ( char * ) V_39 + sizeof( * V_39 ) ) >= V_113 )
return - V_118 ;
if ( V_39 -> V_14 == 0 )
return - V_118 ;
V_112 = V_115 -> V_55 ( V_40 , V_39 ) ;
if ( V_113 < ( char * ) V_112 )
return - V_118 ;
if ( F_33 ( V_39 ) < V_73 )
return - V_118 ;
V_103 = V_115 -> V_104 ( V_40 , V_39 ) ;
V_10 += V_103 > V_27 ;
error = F_37 ( V_13 , V_103 ) ;
if ( error )
return error ;
V_87 = V_115 -> V_105 ( V_39 ) ;
if ( V_87 >= V_106 )
return - V_118 ;
V_73 = F_33 ( V_39 ) +
V_115 -> V_56 ( V_39 -> V_14 ) ;
V_39 = V_112 ;
}
if ( V_10 != V_40 -> V_10 )
return - V_118 ;
if ( ( void * ) V_39 != ( void * ) V_113 )
return - V_118 ;
if ( V_73 + ( V_40 -> V_7 + 2 ) * ( V_101 ) sizeof( T_5 ) +
( V_101 ) sizeof( T_6 ) > V_13 -> V_21 -> V_102 )
return - V_118 ;
return 0 ;
}
int
F_38 (
T_10 * args ,
T_9 V_119 )
{
T_1 * V_1 ;
int V_10 ;
T_3 * V_40 ;
int V_16 ;
F_39 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_1 -> V_64 . V_67 == 0 ) ;
if ( V_1 -> V_64 . V_65 == V_120 ) {
V_1 -> V_61 . V_76 &= ~ V_121 ;
V_1 -> V_64 . V_65 = V_66 ;
F_19 ( args -> V_69 , V_1 , V_57 ) ;
V_1 -> V_61 . V_76 |= V_77 ;
}
ASSERT ( V_1 -> V_61 . V_76 & V_77 ) ;
ASSERT ( V_1 -> V_61 . V_62 == 0 ) ;
V_10 = V_119 > V_27 ;
V_16 = F_8 ( V_10 ) ;
F_32 ( V_1 , V_16 , V_63 ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_40 -> V_10 = V_10 ;
V_1 -> V_31 -> V_32 ( V_40 , V_119 ) ;
V_40 -> V_7 = 0 ;
V_1 -> V_64 . V_67 = V_16 ;
F_18 ( args ) ;
F_19 ( args -> V_69 , V_1 , V_57 | V_68 ) ;
return 0 ;
}
int
F_23 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int error ;
T_12 * V_39 ;
T_3 * V_40 ;
enum V_122 V_123 ;
T_12 * V_124 ;
F_40 ( args ) ;
F_18 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_61 . V_76 & V_77 ) ;
if ( V_1 -> V_64 . V_67 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_78 ;
}
ASSERT ( V_1 -> V_61 . V_62 == V_1 -> V_64 . V_67 ) ;
ASSERT ( V_1 -> V_61 . V_79 . V_80 != NULL ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
ASSERT ( V_1 -> V_64 . V_67 >= F_8 ( V_40 -> V_10 ) ) ;
if ( args -> V_14 == 1 && args -> V_25 [ 0 ] == '.' ) {
args -> V_26 = V_1 -> V_49 ;
args -> V_125 = V_126 ;
args -> V_87 = V_127 ;
return - V_128 ;
}
if ( args -> V_14 == 2 &&
args -> V_25 [ 0 ] == '.' && args -> V_25 [ 1 ] == '.' ) {
args -> V_26 = V_1 -> V_31 -> V_50 ( V_40 ) ;
args -> V_125 = V_126 ;
args -> V_87 = V_127 ;
return - V_128 ;
}
V_124 = NULL ;
for ( V_9 = 0 , V_39 = F_13 ( V_40 ) ; V_9 < V_40 -> V_7 ;
V_9 ++ , V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ) {
V_123 = V_1 -> V_20 -> V_129 -> V_130 ( args , V_39 -> V_25 ,
V_39 -> V_14 ) ;
if ( V_123 != V_131 && V_123 != args -> V_125 ) {
args -> V_125 = V_123 ;
args -> V_26 = V_1 -> V_31 -> V_104 ( V_40 , V_39 ) ;
args -> V_87 = V_1 -> V_31 -> V_105 ( V_39 ) ;
if ( V_123 == V_126 )
return - V_128 ;
V_124 = V_39 ;
}
}
ASSERT ( args -> V_83 & V_132 ) ;
if ( ! V_124 )
return - V_75 ;
error = F_41 ( args , V_124 -> V_25 , V_124 -> V_14 ) ;
return error ;
}
int
F_42 (
T_10 * args )
{
int V_86 ;
T_1 * V_1 ;
int V_133 ;
int V_9 ;
int V_134 ;
int V_135 ;
T_12 * V_39 ;
T_3 * V_40 ;
F_43 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_61 . V_76 & V_77 ) ;
V_135 = ( int ) V_1 -> V_64 . V_67 ;
if ( V_135 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_78 ;
}
ASSERT ( V_1 -> V_61 . V_62 == V_135 ) ;
ASSERT ( V_1 -> V_61 . V_79 . V_80 != NULL ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
ASSERT ( V_135 >= F_8 ( V_40 -> V_10 ) ) ;
for ( V_9 = 0 , V_39 = F_13 ( V_40 ) ; V_9 < V_40 -> V_7 ;
V_9 ++ , V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ) {
if ( F_44 ( args , V_39 -> V_25 , V_39 -> V_14 ) ==
V_126 ) {
ASSERT ( V_1 -> V_31 -> V_104 ( V_40 , V_39 ) ==
args -> V_26 ) ;
break;
}
}
if ( V_9 == V_40 -> V_7 )
return - V_75 ;
V_86 = ( int ) ( ( char * ) V_39 - ( char * ) V_40 ) ;
V_133 = V_1 -> V_31 -> V_81 ( V_40 , args -> V_14 ) ;
V_134 = V_135 - V_133 ;
if ( V_86 + V_133 < V_135 )
memmove ( ( char * ) V_40 + V_86 , ( char * ) V_40 + V_86 + V_133 ,
V_135 - ( V_86 + V_133 ) ) ;
V_40 -> V_7 -- ;
V_1 -> V_64 . V_67 = V_134 ;
F_32 ( V_1 , V_134 - V_135 , V_63 ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
if ( args -> V_26 > V_27 ) {
if ( V_40 -> V_10 == 1 )
F_45 ( args ) ;
else
V_40 -> V_10 -- ;
}
F_18 ( args ) ;
F_19 ( args -> V_69 , V_1 , V_57 | V_68 ) ;
return 0 ;
}
int
F_46 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
T_9 V_103 = 0 ;
int V_136 ;
T_12 * V_39 ;
T_3 * V_40 ;
F_47 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_61 . V_76 & V_77 ) ;
if ( V_1 -> V_64 . V_67 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_78 ;
}
ASSERT ( V_1 -> V_61 . V_62 == V_1 -> V_64 . V_67 ) ;
ASSERT ( V_1 -> V_61 . V_79 . V_80 != NULL ) ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
ASSERT ( V_1 -> V_64 . V_67 >= F_8 ( V_40 -> V_10 ) ) ;
if ( args -> V_26 > V_27 && V_40 -> V_10 == 0 ) {
int error ;
int V_134 ;
V_134 = V_1 -> V_61 . V_62 + ( V_40 -> V_7 + 1 ) * V_82 ;
if ( V_134 > F_9 ( V_1 ) ) {
error = F_27 ( args ) ;
if ( error ) {
return error ;
}
return F_48 ( args ) ;
}
F_30 ( args ) ;
V_136 = 1 ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
} else
V_136 = 0 ;
ASSERT ( args -> V_14 != 1 || args -> V_25 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_25 [ 0 ] == '.' && args -> V_25 [ 1 ] == '.' ) {
V_103 = V_1 -> V_31 -> V_50 ( V_40 ) ;
ASSERT ( args -> V_26 != V_103 ) ;
V_1 -> V_31 -> V_32 ( V_40 , args -> V_26 ) ;
}
else {
for ( V_9 = 0 , V_39 = F_13 ( V_40 ) ; V_9 < V_40 -> V_7 ;
V_9 ++ , V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ) {
if ( F_44 ( args , V_39 -> V_25 , V_39 -> V_14 ) ==
V_126 ) {
V_103 = V_1 -> V_31 -> V_104 ( V_40 , V_39 ) ;
ASSERT ( args -> V_26 != V_103 ) ;
V_1 -> V_31 -> V_52 ( V_40 , V_39 , args -> V_26 ) ;
V_1 -> V_31 -> V_53 ( V_39 , args -> V_87 ) ;
break;
}
}
if ( V_9 == V_40 -> V_7 ) {
ASSERT ( args -> V_83 & V_132 ) ;
if ( V_136 )
F_45 ( args ) ;
return - V_75 ;
}
}
if ( V_103 > V_27 &&
args -> V_26 <= V_27 ) {
if ( V_40 -> V_10 == 1 )
F_45 ( args ) ;
else
V_40 -> V_10 -- ;
}
if ( V_103 <= V_27 &&
args -> V_26 > V_27 ) {
ASSERT ( V_40 -> V_10 != 0 ) ;
if ( ! V_136 )
V_40 -> V_10 ++ ;
}
F_18 ( args ) ;
F_19 ( args -> V_69 , V_1 , V_68 ) ;
return 0 ;
}
static void
F_45 (
T_10 * args )
{
char * V_89 ;
T_1 * V_1 ;
int V_9 ;
int V_134 ;
T_12 * V_94 ;
T_3 * V_95 ;
int V_135 ;
T_12 * V_39 ;
T_3 * V_40 ;
F_49 ( args ) ;
V_1 = args -> V_1 ;
V_135 = V_1 -> V_61 . V_62 ;
V_89 = F_12 ( V_135 , V_43 ) ;
V_95 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
ASSERT ( V_95 -> V_10 == 1 ) ;
memcpy ( V_89 , V_95 , V_135 ) ;
V_134 = V_135 - ( V_95 -> V_7 + 1 ) * V_82 ;
F_32 ( V_1 , - V_135 , V_63 ) ;
F_32 ( V_1 , V_134 , V_63 ) ;
V_95 = ( T_3 * ) V_89 ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_40 -> V_7 = V_95 -> V_7 ;
V_40 -> V_10 = 0 ;
V_1 -> V_31 -> V_32 ( V_40 , V_1 -> V_31 -> V_50 ( V_95 ) ) ;
for ( V_9 = 0 , V_39 = F_13 ( V_40 ) ,
V_94 = F_13 ( V_95 ) ;
V_9 < V_40 -> V_7 ;
V_9 ++ , V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ,
V_94 = V_1 -> V_31 -> V_55 ( V_95 , V_94 ) ) {
V_39 -> V_14 = V_94 -> V_14 ;
memcpy ( V_39 -> V_73 , V_94 -> V_73 , sizeof( V_39 -> V_73 ) ) ;
memcpy ( V_39 -> V_25 , V_94 -> V_25 , V_39 -> V_14 ) ;
V_1 -> V_31 -> V_52 ( V_40 , V_39 ,
V_1 -> V_31 -> V_104 ( V_95 , V_94 ) ) ;
V_1 -> V_31 -> V_53 ( V_39 , V_1 -> V_31 -> V_105 ( V_94 ) ) ;
}
F_20 ( V_89 ) ;
V_1 -> V_64 . V_67 = V_134 ;
F_19 ( args -> V_69 , V_1 , V_57 | V_68 ) ;
}
static void
F_30 (
T_10 * args )
{
char * V_89 ;
T_1 * V_1 ;
int V_9 ;
int V_134 ;
T_12 * V_94 ;
T_3 * V_95 ;
int V_135 ;
T_12 * V_39 ;
T_3 * V_40 ;
F_50 ( args ) ;
V_1 = args -> V_1 ;
V_135 = V_1 -> V_61 . V_62 ;
V_89 = F_12 ( V_135 , V_43 ) ;
V_95 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
ASSERT ( V_95 -> V_10 == 0 ) ;
memcpy ( V_89 , V_95 , V_135 ) ;
V_134 = V_135 + ( V_95 -> V_7 + 1 ) * V_82 ;
F_32 ( V_1 , - V_135 , V_63 ) ;
F_32 ( V_1 , V_134 , V_63 ) ;
V_95 = ( T_3 * ) V_89 ;
V_40 = ( T_3 * ) V_1 -> V_61 . V_79 . V_80 ;
V_40 -> V_7 = V_95 -> V_7 ;
V_40 -> V_10 = 1 ;
V_1 -> V_31 -> V_32 ( V_40 , V_1 -> V_31 -> V_50 ( V_95 ) ) ;
for ( V_9 = 0 , V_39 = F_13 ( V_40 ) ,
V_94 = F_13 ( V_95 ) ;
V_9 < V_40 -> V_7 ;
V_9 ++ , V_39 = V_1 -> V_31 -> V_55 ( V_40 , V_39 ) ,
V_94 = V_1 -> V_31 -> V_55 ( V_95 , V_94 ) ) {
V_39 -> V_14 = V_94 -> V_14 ;
memcpy ( V_39 -> V_73 , V_94 -> V_73 , sizeof( V_39 -> V_73 ) ) ;
memcpy ( V_39 -> V_25 , V_94 -> V_25 , V_39 -> V_14 ) ;
V_1 -> V_31 -> V_52 ( V_40 , V_39 ,
V_1 -> V_31 -> V_104 ( V_95 , V_94 ) ) ;
V_1 -> V_31 -> V_53 ( V_39 , V_1 -> V_31 -> V_105 ( V_94 ) ) ;
}
F_20 ( V_89 ) ;
V_1 -> V_64 . V_67 = V_134 ;
F_19 ( args -> V_69 , V_1 , V_57 | V_68 ) ;
}
