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
V_7 +
V_7 * ( V_28 ) sizeof( V_29 ) +
V_14 +
( V_10 ?
( V_28 ) sizeof( V_30 ) * V_7 :
( V_28 ) sizeof( V_31 ) * V_7 ) ;
if ( V_16 > F_9 ( V_1 ) )
return V_16 ;
}
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
V_1 -> V_32 -> V_33 ( V_3 , V_15 ) ;
return V_16 ;
}
int
F_10 (
T_10 * args ,
struct V_34 * V_35 ,
int V_16 ,
T_3 * V_3 )
{
T_2 * V_2 ;
T_6 * V_6 ;
T_7 * V_8 ;
T_1 * V_1 ;
T_11 * V_36 ;
char * V_37 ;
int error ;
int V_38 ;
T_8 * V_13 ;
char * V_39 ;
T_12 * V_40 ;
T_3 * V_41 ;
T_3 * V_42 ;
F_11 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_42 = F_12 ( V_13 -> V_22 . V_43 , V_44 ) ;
V_2 = V_35 -> V_45 ;
V_41 = ( T_3 * ) V_42 ;
memcpy ( V_41 , V_3 , F_8 ( V_3 -> V_10 ) ) ;
V_6 = F_3 ( args -> V_19 , V_2 ) ;
V_39 = ( char * ) V_1 -> V_32 -> V_46 ( V_2 ) ;
V_37 = ( char * ) F_4 ( V_6 ) ;
V_40 = F_13 ( V_41 ) ;
while ( V_39 < V_37 ) {
V_36 = ( T_11 * ) V_39 ;
if ( F_14 ( V_36 -> V_47 ) == V_48 ) {
V_39 += F_14 ( V_36 -> V_49 ) ;
continue;
}
V_8 = ( T_7 * ) V_39 ;
if ( V_8 -> V_14 == 1 && V_8 -> V_25 [ 0 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_26 ) == V_1 -> V_50 ) ;
else if ( V_8 -> V_14 == 2 &&
V_8 -> V_25 [ 0 ] == '.' && V_8 -> V_25 [ 1 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_26 ) ==
V_1 -> V_32 -> V_51 ( V_41 ) ) ;
else {
V_40 -> V_14 = V_8 -> V_14 ;
F_15 ( V_40 ,
( V_52 )
( ( char * ) V_8 - ( char * ) V_2 ) ) ;
memcpy ( V_40 -> V_25 , V_8 -> V_25 , V_8 -> V_14 ) ;
V_1 -> V_32 -> V_53 ( V_41 , V_40 ,
F_7 ( V_8 -> V_26 ) ) ;
V_1 -> V_32 -> V_54 ( V_40 ,
V_1 -> V_32 -> V_55 ( V_8 ) ) ;
V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ;
}
V_39 += V_1 -> V_32 -> V_57 ( V_8 -> V_14 ) ;
}
ASSERT ( ( char * ) V_40 - ( char * ) V_41 == V_16 ) ;
V_38 = V_58 ;
error = F_16 ( args , args -> V_19 -> V_59 , V_35 ) ;
if ( error ) {
ASSERT ( error != - V_60 ) ;
goto V_61;
}
V_1 -> V_62 . V_63 &= ~ V_64 ;
V_1 -> V_62 . V_63 |= V_65 ;
V_1 -> V_66 . V_67 = V_68 ;
ASSERT ( V_1 -> V_62 . V_69 == 0 ) ;
F_17 ( V_1 , V_16 , V_70 ) ;
V_38 |= V_71 ;
memcpy ( V_1 -> V_62 . V_72 . V_73 , V_42 , V_16 ) ;
V_1 -> V_66 . V_74 = V_16 ;
F_18 ( args ) ;
V_61:
F_19 ( args -> V_75 , V_1 , V_38 ) ;
F_20 ( V_42 ) ;
return error ;
}
int
F_21 (
T_10 * args )
{
T_1 * V_1 ;
int error ;
int V_76 ;
int V_77 ;
int V_78 ;
V_52 V_79 = 0 ;
int V_80 ;
T_3 * V_41 ;
T_12 * V_40 = NULL ;
F_22 ( args ) ;
ASSERT ( F_23 ( args ) == - V_81 ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_62 . V_63 & V_65 ) ;
if ( V_1 -> V_66 . V_74 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_82 ;
}
ASSERT ( V_1 -> V_62 . V_69 == V_1 -> V_66 . V_74 ) ;
ASSERT ( V_1 -> V_62 . V_72 . V_73 != NULL ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
ASSERT ( V_1 -> V_66 . V_74 >= F_8 ( V_41 -> V_10 ) ) ;
V_76 = V_1 -> V_32 -> V_83 ( V_41 , args -> V_14 ) ;
V_78 = 0 ;
if ( args -> V_26 > V_27 && V_41 -> V_10 == 0 ) {
V_76 +=
( V_41 -> V_7 + 2 ) *
( ( V_28 ) sizeof( V_30 ) -
( V_28 ) sizeof( V_31 ) ) ;
V_78 = 1 ;
}
V_77 = ( int ) V_1 -> V_66 . V_74 + V_76 ;
if ( V_77 > F_9 ( V_1 ) ||
( V_80 =
F_26 ( args , V_78 , & V_40 , & V_79 ) ) == 0 ) {
if ( ( args -> V_84 & V_85 ) || args -> V_86 == 0 )
return - V_60 ;
error = F_27 ( args ) ;
if ( error )
return error ;
return F_28 ( args ) ;
}
if ( args -> V_84 & V_85 )
return 0 ;
if ( V_80 == 1 )
F_29 ( args , V_40 , V_79 , V_77 ) ;
else {
ASSERT ( V_80 == 2 ) ;
if ( V_78 )
F_30 ( args ) ;
F_31 ( args , V_78 , V_77 ) ;
}
F_19 ( args -> V_75 , V_1 , V_58 | V_71 ) ;
return 0 ;
}
static void
F_29 (
T_10 * args ,
T_12 * V_40 ,
V_52 V_79 ,
int V_77 )
{
int V_87 ;
T_1 * V_1 ;
T_3 * V_41 ;
V_1 = args -> V_1 ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_87 = ( int ) ( ( char * ) V_40 - ( char * ) V_41 ) ;
F_17 ( V_1 , V_1 -> V_32 -> V_83 ( V_41 , args -> V_14 ) ,
V_70 ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_40 = ( T_12 * ) ( ( char * ) V_41 + V_87 ) ;
V_40 -> V_14 = args -> V_14 ;
F_15 ( V_40 , V_79 ) ;
memcpy ( V_40 -> V_25 , args -> V_25 , V_40 -> V_14 ) ;
V_1 -> V_32 -> V_53 ( V_41 , V_40 , args -> V_26 ) ;
V_1 -> V_32 -> V_54 ( V_40 , args -> V_88 ) ;
V_41 -> V_7 ++ ;
if ( args -> V_26 > V_27 )
V_41 -> V_10 ++ ;
V_1 -> V_66 . V_74 = V_77 ;
F_18 ( args ) ;
}
static void
F_31 (
T_10 * args ,
int V_78 ,
int V_77 )
{
int V_89 ;
char * V_90 ;
T_1 * V_1 ;
int V_91 ;
int V_92 ;
V_52 V_93 ;
V_52 V_79 ;
int V_94 ;
T_12 * V_95 ;
T_3 * V_96 ;
T_12 * V_40 ;
T_3 * V_41 ;
struct V_97 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_94 = ( int ) V_1 -> V_66 . V_74 ;
V_90 = F_12 ( V_94 , V_44 ) ;
V_96 = ( T_3 * ) V_90 ;
memcpy ( V_96 , V_41 , V_94 ) ;
for ( V_79 = V_1 -> V_32 -> V_98 ,
V_95 = F_13 ( V_96 ) ,
V_89 = V_1 -> V_32 -> V_57 ( args -> V_14 ) ,
V_91 = ( char * ) V_95 == & V_90 [ V_94 ] ;
! V_91 ;
V_79 = V_93 + V_1 -> V_32 -> V_57 ( V_95 -> V_14 ) ,
V_95 = V_1 -> V_32 -> V_56 ( V_96 , V_95 ) ,
V_91 = ( char * ) V_95 == & V_90 [ V_94 ] ) {
V_93 = F_32 ( V_95 ) ;
if ( V_79 + V_89 <= V_93 )
break;
}
F_17 ( V_1 , - V_94 , V_70 ) ;
F_17 ( V_1 , V_77 , V_70 ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_92 = ( int ) ( ( char * ) V_95 - ( char * ) V_96 ) ;
memcpy ( V_41 , V_96 , V_92 ) ;
V_40 = ( T_12 * ) ( ( char * ) V_41 + V_92 ) ;
V_40 -> V_14 = args -> V_14 ;
F_15 ( V_40 , V_79 ) ;
memcpy ( V_40 -> V_25 , args -> V_25 , V_40 -> V_14 ) ;
V_1 -> V_32 -> V_53 ( V_41 , V_40 , args -> V_26 ) ;
V_1 -> V_32 -> V_54 ( V_40 , args -> V_88 ) ;
V_41 -> V_7 ++ ;
if ( args -> V_26 > V_27 && ! V_78 )
V_41 -> V_10 ++ ;
if ( ! V_91 ) {
V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ;
memcpy ( V_40 , V_95 , V_94 - V_92 ) ;
}
F_20 ( V_90 ) ;
V_1 -> V_66 . V_74 = V_77 ;
F_18 ( args ) ;
}
static int
F_26 (
T_10 * args ,
int V_78 ,
T_12 * * V_99 ,
V_52 * V_100 )
{
T_1 * V_1 ;
int V_101 ;
int V_9 ;
T_8 * V_13 ;
V_52 V_79 ;
T_12 * V_40 ;
T_3 * V_41 ;
int V_16 ;
int V_102 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_16 = V_1 -> V_32 -> V_57 ( args -> V_14 ) ;
V_79 = V_1 -> V_32 -> V_98 ;
V_40 = F_13 ( V_41 ) ;
V_101 = 0 ;
for ( V_9 = 0 ; V_9 < V_41 -> V_7 ; V_9 ++ ) {
if ( ! V_101 )
V_101 = V_79 + V_16 <= F_32 ( V_40 ) ;
V_79 = F_32 ( V_40 ) +
V_1 -> V_32 -> V_57 ( V_40 -> V_14 ) ;
V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ;
}
V_102 = V_79 +
( V_41 -> V_7 + 3 ) * ( V_28 ) sizeof( T_5 ) +
( V_28 ) sizeof( T_6 ) ;
if ( V_102 + ( V_101 ? 0 : V_16 ) > args -> V_19 -> V_103 )
return 0 ;
if ( V_78 )
return 2 ;
if ( V_102 + V_16 > args -> V_19 -> V_103 )
return 2 ;
* V_99 = V_40 ;
* V_100 = V_79 ;
return 1 ;
}
static void
F_18 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int V_10 ;
T_9 V_104 ;
int V_79 ;
T_12 * V_40 ;
T_3 * V_41 ;
struct V_97 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_79 = V_1 -> V_32 -> V_98 ;
V_104 = V_1 -> V_32 -> V_51 ( V_41 ) ;
V_10 = V_104 > V_27 ;
for ( V_9 = 0 , V_40 = F_13 ( V_41 ) ;
V_9 < V_41 -> V_7 ;
V_9 ++ , V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ) {
ASSERT ( F_32 ( V_40 ) >= V_79 ) ;
V_104 = V_1 -> V_32 -> V_105 ( V_41 , V_40 ) ;
V_10 += V_104 > V_27 ;
V_79 =
F_32 ( V_40 ) +
V_1 -> V_32 -> V_57 ( V_40 -> V_14 ) ;
ASSERT ( V_1 -> V_32 -> V_106 ( V_40 ) < V_107 ) ;
}
ASSERT ( V_10 == V_41 -> V_10 ) ;
ASSERT ( ( char * ) V_40 - ( char * ) V_41 == V_1 -> V_66 . V_74 ) ;
ASSERT ( V_79 +
( V_41 -> V_7 + 2 ) * ( V_28 ) sizeof( T_5 ) +
( V_28 ) sizeof( T_6 ) <= args -> V_19 -> V_103 ) ;
}
int
F_33 (
T_10 * args ,
T_9 V_108 )
{
T_1 * V_1 ;
int V_10 ;
T_3 * V_41 ;
int V_16 ;
F_34 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_1 -> V_66 . V_74 == 0 ) ;
if ( V_1 -> V_66 . V_67 == V_109 ) {
V_1 -> V_62 . V_63 &= ~ V_64 ;
V_1 -> V_66 . V_67 = V_68 ;
F_19 ( args -> V_75 , V_1 , V_58 ) ;
V_1 -> V_62 . V_63 |= V_65 ;
}
ASSERT ( V_1 -> V_62 . V_63 & V_65 ) ;
ASSERT ( V_1 -> V_62 . V_69 == 0 ) ;
V_10 = V_108 > V_27 ;
V_16 = F_8 ( V_10 ) ;
F_17 ( V_1 , V_16 , V_70 ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_41 -> V_10 = V_10 ;
V_1 -> V_32 -> V_33 ( V_41 , V_108 ) ;
V_41 -> V_7 = 0 ;
V_1 -> V_66 . V_74 = V_16 ;
F_18 ( args ) ;
F_19 ( args -> V_75 , V_1 , V_58 | V_71 ) ;
return 0 ;
}
int
F_23 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int error ;
T_12 * V_40 ;
T_3 * V_41 ;
enum V_110 V_111 ;
T_12 * V_112 ;
F_35 ( args ) ;
F_18 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_62 . V_63 & V_65 ) ;
if ( V_1 -> V_66 . V_74 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_82 ;
}
ASSERT ( V_1 -> V_62 . V_69 == V_1 -> V_66 . V_74 ) ;
ASSERT ( V_1 -> V_62 . V_72 . V_73 != NULL ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
ASSERT ( V_1 -> V_66 . V_74 >= F_8 ( V_41 -> V_10 ) ) ;
if ( args -> V_14 == 1 && args -> V_25 [ 0 ] == '.' ) {
args -> V_26 = V_1 -> V_50 ;
args -> V_113 = V_114 ;
args -> V_88 = V_115 ;
return - V_116 ;
}
if ( args -> V_14 == 2 &&
args -> V_25 [ 0 ] == '.' && args -> V_25 [ 1 ] == '.' ) {
args -> V_26 = V_1 -> V_32 -> V_51 ( V_41 ) ;
args -> V_113 = V_114 ;
args -> V_88 = V_115 ;
return - V_116 ;
}
V_112 = NULL ;
for ( V_9 = 0 , V_40 = F_13 ( V_41 ) ; V_9 < V_41 -> V_7 ;
V_9 ++ , V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ) {
V_111 = V_1 -> V_20 -> V_117 -> V_118 ( args , V_40 -> V_25 ,
V_40 -> V_14 ) ;
if ( V_111 != V_119 && V_111 != args -> V_113 ) {
args -> V_113 = V_111 ;
args -> V_26 = V_1 -> V_32 -> V_105 ( V_41 , V_40 ) ;
args -> V_88 = V_1 -> V_32 -> V_106 ( V_40 ) ;
if ( V_111 == V_114 )
return - V_116 ;
V_112 = V_40 ;
}
}
ASSERT ( args -> V_84 & V_120 ) ;
if ( ! V_112 )
return - V_81 ;
error = F_36 ( args , V_112 -> V_25 , V_112 -> V_14 ) ;
return error ;
}
int
F_37 (
T_10 * args )
{
int V_87 ;
T_1 * V_1 ;
int V_121 ;
int V_9 ;
int V_122 ;
int V_123 ;
T_12 * V_40 ;
T_3 * V_41 ;
F_38 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_62 . V_63 & V_65 ) ;
V_123 = ( int ) V_1 -> V_66 . V_74 ;
if ( V_123 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_82 ;
}
ASSERT ( V_1 -> V_62 . V_69 == V_123 ) ;
ASSERT ( V_1 -> V_62 . V_72 . V_73 != NULL ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
ASSERT ( V_123 >= F_8 ( V_41 -> V_10 ) ) ;
for ( V_9 = 0 , V_40 = F_13 ( V_41 ) ; V_9 < V_41 -> V_7 ;
V_9 ++ , V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ) {
if ( F_39 ( args , V_40 -> V_25 , V_40 -> V_14 ) ==
V_114 ) {
ASSERT ( V_1 -> V_32 -> V_105 ( V_41 , V_40 ) ==
args -> V_26 ) ;
break;
}
}
if ( V_9 == V_41 -> V_7 )
return - V_81 ;
V_87 = ( int ) ( ( char * ) V_40 - ( char * ) V_41 ) ;
V_121 = V_1 -> V_32 -> V_83 ( V_41 , args -> V_14 ) ;
V_122 = V_123 - V_121 ;
if ( V_87 + V_121 < V_123 )
memmove ( ( char * ) V_41 + V_87 , ( char * ) V_41 + V_87 + V_121 ,
V_123 - ( V_87 + V_121 ) ) ;
V_41 -> V_7 -- ;
V_1 -> V_66 . V_74 = V_122 ;
F_17 ( V_1 , V_122 - V_123 , V_70 ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
if ( args -> V_26 > V_27 ) {
if ( V_41 -> V_10 == 1 )
F_40 ( args ) ;
else
V_41 -> V_10 -- ;
}
F_18 ( args ) ;
F_19 ( args -> V_75 , V_1 , V_58 | V_71 ) ;
return 0 ;
}
int
F_41 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
T_9 V_104 = 0 ;
int V_124 ;
T_12 * V_40 ;
T_3 * V_41 ;
F_42 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_62 . V_63 & V_65 ) ;
if ( V_1 -> V_66 . V_74 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return - V_82 ;
}
ASSERT ( V_1 -> V_62 . V_69 == V_1 -> V_66 . V_74 ) ;
ASSERT ( V_1 -> V_62 . V_72 . V_73 != NULL ) ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
ASSERT ( V_1 -> V_66 . V_74 >= F_8 ( V_41 -> V_10 ) ) ;
if ( args -> V_26 > V_27 && V_41 -> V_10 == 0 ) {
int error ;
int V_122 ;
V_122 =
V_1 -> V_62 . V_69 +
( V_41 -> V_7 + 1 ) *
( ( V_28 ) sizeof( V_30 ) -
( V_28 ) sizeof( V_31 ) ) ;
if ( V_122 > F_9 ( V_1 ) ) {
error = F_27 ( args ) ;
if ( error ) {
return error ;
}
return F_43 ( args ) ;
}
F_30 ( args ) ;
V_124 = 1 ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
} else
V_124 = 0 ;
ASSERT ( args -> V_14 != 1 || args -> V_25 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_25 [ 0 ] == '.' && args -> V_25 [ 1 ] == '.' ) {
V_104 = V_1 -> V_32 -> V_51 ( V_41 ) ;
ASSERT ( args -> V_26 != V_104 ) ;
V_1 -> V_32 -> V_33 ( V_41 , args -> V_26 ) ;
}
else {
for ( V_9 = 0 , V_40 = F_13 ( V_41 ) ; V_9 < V_41 -> V_7 ;
V_9 ++ , V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ) {
if ( F_39 ( args , V_40 -> V_25 , V_40 -> V_14 ) ==
V_114 ) {
V_104 = V_1 -> V_32 -> V_105 ( V_41 , V_40 ) ;
ASSERT ( args -> V_26 != V_104 ) ;
V_1 -> V_32 -> V_53 ( V_41 , V_40 , args -> V_26 ) ;
V_1 -> V_32 -> V_54 ( V_40 , args -> V_88 ) ;
break;
}
}
if ( V_9 == V_41 -> V_7 ) {
ASSERT ( args -> V_84 & V_120 ) ;
if ( V_124 )
F_40 ( args ) ;
return - V_81 ;
}
}
if ( V_104 > V_27 &&
args -> V_26 <= V_27 ) {
if ( V_41 -> V_10 == 1 )
F_40 ( args ) ;
else
V_41 -> V_10 -- ;
}
if ( V_104 <= V_27 &&
args -> V_26 > V_27 ) {
ASSERT ( V_41 -> V_10 != 0 ) ;
if ( ! V_124 )
V_41 -> V_10 ++ ;
}
F_18 ( args ) ;
F_19 ( args -> V_75 , V_1 , V_71 ) ;
return 0 ;
}
static void
F_40 (
T_10 * args )
{
char * V_90 ;
T_1 * V_1 ;
int V_9 ;
int V_122 ;
T_12 * V_95 ;
T_3 * V_96 ;
int V_123 ;
T_12 * V_40 ;
T_3 * V_41 ;
struct V_97 * V_13 ;
F_44 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_123 = V_1 -> V_62 . V_69 ;
V_90 = F_12 ( V_123 , V_44 ) ;
V_96 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
ASSERT ( V_96 -> V_10 == 1 ) ;
memcpy ( V_90 , V_96 , V_123 ) ;
V_122 =
V_123 -
( V_96 -> V_7 + 1 ) *
( ( V_28 ) sizeof( V_30 ) - ( V_28 ) sizeof( V_31 ) ) ;
F_17 ( V_1 , - V_123 , V_70 ) ;
F_17 ( V_1 , V_122 , V_70 ) ;
V_96 = ( T_3 * ) V_90 ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_41 -> V_7 = V_96 -> V_7 ;
V_41 -> V_10 = 0 ;
V_1 -> V_32 -> V_33 ( V_41 , V_1 -> V_32 -> V_51 ( V_96 ) ) ;
for ( V_9 = 0 , V_40 = F_13 ( V_41 ) ,
V_95 = F_13 ( V_96 ) ;
V_9 < V_41 -> V_7 ;
V_9 ++ , V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ,
V_95 = V_1 -> V_32 -> V_56 ( V_96 , V_95 ) ) {
V_40 -> V_14 = V_95 -> V_14 ;
V_40 -> V_79 = V_95 -> V_79 ;
memcpy ( V_40 -> V_25 , V_95 -> V_25 , V_40 -> V_14 ) ;
V_1 -> V_32 -> V_53 ( V_41 , V_40 ,
V_1 -> V_32 -> V_105 ( V_96 , V_95 ) ) ;
V_1 -> V_32 -> V_54 ( V_40 , V_1 -> V_32 -> V_106 ( V_95 ) ) ;
}
F_20 ( V_90 ) ;
V_1 -> V_66 . V_74 = V_122 ;
F_19 ( args -> V_75 , V_1 , V_58 | V_71 ) ;
}
static void
F_30 (
T_10 * args )
{
char * V_90 ;
T_1 * V_1 ;
int V_9 ;
int V_122 ;
T_12 * V_95 ;
T_3 * V_96 ;
int V_123 ;
T_12 * V_40 ;
T_3 * V_41 ;
struct V_97 * V_13 ;
F_45 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_123 = V_1 -> V_62 . V_69 ;
V_90 = F_12 ( V_123 , V_44 ) ;
V_96 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
ASSERT ( V_96 -> V_10 == 0 ) ;
memcpy ( V_90 , V_96 , V_123 ) ;
V_122 =
V_123 +
( V_96 -> V_7 + 1 ) *
( ( V_28 ) sizeof( V_30 ) - ( V_28 ) sizeof( V_31 ) ) ;
F_17 ( V_1 , - V_123 , V_70 ) ;
F_17 ( V_1 , V_122 , V_70 ) ;
V_96 = ( T_3 * ) V_90 ;
V_41 = ( T_3 * ) V_1 -> V_62 . V_72 . V_73 ;
V_41 -> V_7 = V_96 -> V_7 ;
V_41 -> V_10 = 1 ;
V_1 -> V_32 -> V_33 ( V_41 , V_1 -> V_32 -> V_51 ( V_96 ) ) ;
for ( V_9 = 0 , V_40 = F_13 ( V_41 ) ,
V_95 = F_13 ( V_96 ) ;
V_9 < V_41 -> V_7 ;
V_9 ++ , V_40 = V_1 -> V_32 -> V_56 ( V_41 , V_40 ) ,
V_95 = V_1 -> V_32 -> V_56 ( V_96 , V_95 ) ) {
V_40 -> V_14 = V_95 -> V_14 ;
V_40 -> V_79 = V_95 -> V_79 ;
memcpy ( V_40 -> V_25 , V_95 -> V_25 , V_40 -> V_14 ) ;
V_1 -> V_32 -> V_53 ( V_41 , V_40 ,
V_1 -> V_32 -> V_105 ( V_96 , V_95 ) ) ;
V_1 -> V_32 -> V_54 ( V_40 , V_1 -> V_32 -> V_106 ( V_95 ) ) ;
}
F_20 ( V_90 ) ;
V_1 -> V_66 . V_74 = V_122 ;
F_19 ( args -> V_75 , V_1 , V_58 | V_71 ) ;
}
