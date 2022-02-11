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
V_13 = V_1 -> V_18 ;
V_17 = F_2 ( & V_13 -> V_19 ) ? 1 : 0 ;
V_7 = V_10 = V_14 = 0 ;
V_6 = F_3 ( V_13 , V_2 ) ;
V_5 = F_4 ( V_6 ) ;
for ( V_9 = 0 ; V_9 < F_5 ( V_6 -> V_7 ) ; V_9 ++ ) {
if ( ( V_4 = F_5 ( V_5 [ V_9 ] . V_20 ) ) == V_21 )
continue;
V_8 = ( T_7 * )
( ( char * ) V_2 + F_6 ( V_13 , V_4 ) ) ;
V_11 = V_8 -> V_14 == 1 && V_8 -> V_22 [ 0 ] == '.' ;
V_12 =
V_8 -> V_14 == 2 &&
V_8 -> V_22 [ 0 ] == '.' && V_8 -> V_22 [ 1 ] == '.' ;
#if V_23
if ( ! V_11 )
V_10 += F_7 ( V_8 -> V_24 ) > V_25 ;
#endif
if ( ! V_11 && ! V_12 ) {
V_7 ++ ;
V_14 += V_8 -> V_14 + V_17 ;
} else if ( V_12 )
V_15 = F_7 ( V_8 -> V_24 ) ;
V_16 = F_8 ( V_10 ) +
V_7 +
V_7 * ( V_26 ) sizeof( V_27 ) +
V_14 +
( V_10 ?
( V_26 ) sizeof( V_28 ) * V_7 :
( V_26 ) sizeof( V_29 ) * V_7 ) ;
if ( V_16 > F_9 ( V_1 ) )
return V_16 ;
}
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
V_1 -> V_30 -> V_31 ( V_3 , V_15 ) ;
return V_16 ;
}
int
F_10 (
T_10 * args ,
struct V_32 * V_33 ,
int V_16 ,
T_3 * V_3 )
{
T_2 * V_2 ;
T_6 * V_6 ;
T_7 * V_8 ;
T_1 * V_1 ;
T_11 * V_34 ;
char * V_35 ;
int error ;
int V_36 ;
T_8 * V_13 ;
char * V_37 ;
T_12 * V_38 ;
T_3 * V_39 ;
T_3 * V_40 ;
F_11 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_40 = F_12 ( V_13 -> V_19 . V_41 , V_42 ) ;
V_2 = V_33 -> V_43 ;
V_39 = ( T_3 * ) V_40 ;
memcpy ( V_39 , V_3 , F_8 ( V_3 -> V_10 ) ) ;
V_6 = F_3 ( V_13 , V_2 ) ;
V_37 = ( char * ) V_1 -> V_30 -> V_44 ( V_2 ) ;
V_35 = ( char * ) F_4 ( V_6 ) ;
V_38 = F_13 ( V_39 ) ;
while ( V_37 < V_35 ) {
V_34 = ( T_11 * ) V_37 ;
if ( F_14 ( V_34 -> V_45 ) == V_46 ) {
V_37 += F_14 ( V_34 -> V_47 ) ;
continue;
}
V_8 = ( T_7 * ) V_37 ;
if ( V_8 -> V_14 == 1 && V_8 -> V_22 [ 0 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_24 ) == V_1 -> V_48 ) ;
else if ( V_8 -> V_14 == 2 &&
V_8 -> V_22 [ 0 ] == '.' && V_8 -> V_22 [ 1 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_24 ) ==
V_1 -> V_30 -> V_49 ( V_39 ) ) ;
else {
V_38 -> V_14 = V_8 -> V_14 ;
F_15 ( V_38 ,
( V_50 )
( ( char * ) V_8 - ( char * ) V_2 ) ) ;
memcpy ( V_38 -> V_22 , V_8 -> V_22 , V_8 -> V_14 ) ;
V_1 -> V_30 -> V_51 ( V_39 , V_38 ,
F_7 ( V_8 -> V_24 ) ) ;
V_1 -> V_30 -> V_52 ( V_38 ,
V_1 -> V_30 -> V_53 ( V_8 ) ) ;
V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ;
}
V_37 += V_1 -> V_30 -> V_55 ( V_8 -> V_14 ) ;
}
ASSERT ( ( char * ) V_38 - ( char * ) V_39 == V_16 ) ;
V_36 = V_56 ;
error = F_16 ( args , V_13 -> V_57 , V_33 ) ;
if ( error ) {
ASSERT ( error != V_58 ) ;
goto V_59;
}
V_1 -> V_60 . V_61 &= ~ V_62 ;
V_1 -> V_60 . V_61 |= V_63 ;
V_1 -> V_64 . V_65 = V_66 ;
ASSERT ( V_1 -> V_60 . V_67 == 0 ) ;
F_17 ( V_1 , V_16 , V_68 ) ;
V_36 |= V_69 ;
memcpy ( V_1 -> V_60 . V_70 . V_71 , V_40 , V_16 ) ;
V_1 -> V_64 . V_72 = V_16 ;
F_18 ( args ) ;
V_59:
F_19 ( args -> V_73 , V_1 , V_36 ) ;
F_20 ( V_40 ) ;
return error ;
}
int
F_21 (
T_10 * args )
{
int V_74 ;
T_1 * V_1 ;
int error ;
int V_75 ;
int V_76 ;
int V_77 ;
V_50 V_78 = 0 ;
int V_79 ;
int V_80 ;
T_3 * V_39 ;
T_12 * V_38 = NULL ;
F_22 ( args ) ;
ASSERT ( F_23 ( args ) == V_81 ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_60 . V_61 & V_63 ) ;
if ( V_1 -> V_64 . V_72 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_82 ) ;
}
ASSERT ( V_1 -> V_60 . V_67 == V_1 -> V_64 . V_72 ) ;
ASSERT ( V_1 -> V_60 . V_70 . V_71 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
ASSERT ( V_1 -> V_64 . V_72 >= F_8 ( V_39 -> V_10 ) ) ;
V_74 = V_1 -> V_30 -> V_83 ( V_39 , args -> V_14 ) ;
V_75 = V_74 ;
V_77 = 0 ;
#if V_23
if ( args -> V_24 > V_25 && V_39 -> V_10 == 0 ) {
V_74 +=
( V_26 ) sizeof( V_28 ) -
( V_26 ) sizeof( V_29 ) ;
V_75 +=
( V_39 -> V_7 + 2 ) *
( ( V_26 ) sizeof( V_28 ) -
( V_26 ) sizeof( V_29 ) ) ;
V_77 = 1 ;
}
#endif
V_79 = ( int ) V_1 -> V_64 . V_72 ;
V_76 = V_79 + V_75 ;
if ( V_76 > F_9 ( V_1 ) ||
( V_80 =
F_27 ( args , V_77 , & V_38 , & V_78 ) ) == 0 ) {
if ( ( args -> V_84 & V_85 ) || args -> V_86 == 0 )
return F_26 ( V_58 ) ;
error = F_28 ( args ) ;
if ( error )
return error ;
return F_29 ( args ) ;
}
if ( args -> V_84 & V_85 )
return 0 ;
if ( V_80 == 1 )
F_30 ( args , V_38 , V_78 , V_76 ) ;
else {
ASSERT ( V_80 == 2 ) ;
#if V_23
if ( V_77 )
F_31 ( args ) ;
#endif
F_32 ( args , V_77 , V_76 ) ;
}
F_19 ( args -> V_73 , V_1 , V_56 | V_69 ) ;
return 0 ;
}
static void
F_30 (
T_10 * args ,
T_12 * V_38 ,
V_50 V_78 ,
int V_76 )
{
int V_87 ;
T_1 * V_1 ;
T_3 * V_39 ;
V_1 = args -> V_1 ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_87 = ( int ) ( ( char * ) V_38 - ( char * ) V_39 ) ;
F_17 ( V_1 , V_1 -> V_30 -> V_83 ( V_39 , args -> V_14 ) ,
V_68 ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_38 = ( T_12 * ) ( ( char * ) V_39 + V_87 ) ;
V_38 -> V_14 = args -> V_14 ;
F_15 ( V_38 , V_78 ) ;
memcpy ( V_38 -> V_22 , args -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_51 ( V_39 , V_38 , args -> V_24 ) ;
V_1 -> V_30 -> V_52 ( V_38 , args -> V_88 ) ;
V_39 -> V_7 ++ ;
#if V_23
if ( args -> V_24 > V_25 )
V_39 -> V_10 ++ ;
#endif
V_1 -> V_64 . V_72 = V_76 ;
F_18 ( args ) ;
}
static void
F_32 (
T_10 * args ,
int V_77 ,
int V_76 )
{
int V_89 ;
char * V_90 ;
T_1 * V_1 ;
int V_91 ;
int V_92 ;
V_50 V_93 ;
V_50 V_78 ;
int V_79 ;
T_12 * V_94 ;
T_3 * V_95 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_96 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_79 = ( int ) V_1 -> V_64 . V_72 ;
V_90 = F_12 ( V_79 , V_42 ) ;
V_95 = ( T_3 * ) V_90 ;
memcpy ( V_95 , V_39 , V_79 ) ;
for ( V_78 = V_1 -> V_30 -> V_97 ,
V_94 = F_13 ( V_95 ) ,
V_89 = V_1 -> V_30 -> V_55 ( args -> V_14 ) ,
V_91 = ( char * ) V_94 == & V_90 [ V_79 ] ;
! V_91 ;
V_78 = V_93 + V_1 -> V_30 -> V_55 ( V_94 -> V_14 ) ,
V_94 = V_1 -> V_30 -> V_54 ( V_95 , V_94 ) ,
V_91 = ( char * ) V_94 == & V_90 [ V_79 ] ) {
V_93 = F_33 ( V_94 ) ;
if ( V_78 + V_89 <= V_93 )
break;
}
F_17 ( V_1 , - V_79 , V_68 ) ;
F_17 ( V_1 , V_76 , V_68 ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_92 = ( int ) ( ( char * ) V_94 - ( char * ) V_95 ) ;
memcpy ( V_39 , V_95 , V_92 ) ;
V_38 = ( T_12 * ) ( ( char * ) V_39 + V_92 ) ;
V_38 -> V_14 = args -> V_14 ;
F_15 ( V_38 , V_78 ) ;
memcpy ( V_38 -> V_22 , args -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_51 ( V_39 , V_38 , args -> V_24 ) ;
V_1 -> V_30 -> V_52 ( V_38 , args -> V_88 ) ;
V_39 -> V_7 ++ ;
#if V_23
if ( args -> V_24 > V_25 && ! V_77 )
V_39 -> V_10 ++ ;
#endif
if ( ! V_91 ) {
V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ;
memcpy ( V_38 , V_94 , V_79 - V_92 ) ;
}
F_20 ( V_90 ) ;
V_1 -> V_64 . V_72 = V_76 ;
F_18 ( args ) ;
}
static int
F_27 (
T_10 * args ,
int V_77 ,
T_12 * * V_98 ,
V_50 * V_99 )
{
T_1 * V_1 ;
int V_100 ;
int V_9 ;
T_8 * V_13 ;
V_50 V_78 ;
T_12 * V_38 ;
T_3 * V_39 ;
int V_16 ;
int V_101 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_16 = V_1 -> V_30 -> V_55 ( args -> V_14 ) ;
V_78 = V_1 -> V_30 -> V_97 ;
V_38 = F_13 ( V_39 ) ;
V_100 = 0 ;
for ( V_9 = 0 ; V_9 < V_39 -> V_7 ; V_9 ++ ) {
if ( ! V_100 )
V_100 = V_78 + V_16 <= F_33 ( V_38 ) ;
V_78 = F_33 ( V_38 ) +
V_1 -> V_30 -> V_55 ( V_38 -> V_14 ) ;
V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ;
}
V_101 = V_78 +
( V_39 -> V_7 + 3 ) * ( V_26 ) sizeof( T_5 ) +
( V_26 ) sizeof( T_6 ) ;
if ( V_101 + ( V_100 ? 0 : V_16 ) > V_13 -> V_102 )
return 0 ;
#if V_23
if ( V_77 ) {
return 2 ;
}
#else
ASSERT ( V_77 == 0 ) ;
#endif
if ( V_101 + V_16 > V_13 -> V_102 )
return 2 ;
* V_98 = V_38 ;
* V_99 = V_78 ;
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
int V_78 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_96 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_78 = V_1 -> V_30 -> V_97 ;
V_103 = V_1 -> V_30 -> V_49 ( V_39 ) ;
V_10 = V_103 > V_25 ;
for ( V_9 = 0 , V_38 = F_13 ( V_39 ) ;
V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ) {
ASSERT ( F_33 ( V_38 ) >= V_78 ) ;
V_103 = V_1 -> V_30 -> V_104 ( V_39 , V_38 ) ;
V_10 += V_103 > V_25 ;
V_78 =
F_33 ( V_38 ) +
V_1 -> V_30 -> V_55 ( V_38 -> V_14 ) ;
ASSERT ( V_1 -> V_30 -> V_105 ( V_38 ) < V_106 ) ;
}
ASSERT ( V_10 == V_39 -> V_10 ) ;
ASSERT ( V_23 || V_10 == 0 ) ;
ASSERT ( ( char * ) V_38 - ( char * ) V_39 == V_1 -> V_64 . V_72 ) ;
ASSERT ( V_78 +
( V_39 -> V_7 + 2 ) * ( V_26 ) sizeof( T_5 ) +
( V_26 ) sizeof( T_6 ) <= V_13 -> V_102 ) ;
}
int
F_34 (
T_10 * args ,
T_9 V_107 )
{
T_1 * V_1 ;
int V_10 ;
T_3 * V_39 ;
int V_16 ;
F_35 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_1 -> V_64 . V_72 == 0 ) ;
if ( V_1 -> V_64 . V_65 == V_108 ) {
V_1 -> V_60 . V_61 &= ~ V_62 ;
V_1 -> V_64 . V_65 = V_66 ;
F_19 ( args -> V_73 , V_1 , V_56 ) ;
V_1 -> V_60 . V_61 |= V_63 ;
}
ASSERT ( V_1 -> V_60 . V_61 & V_63 ) ;
ASSERT ( V_1 -> V_60 . V_67 == 0 ) ;
V_10 = V_107 > V_25 ;
V_16 = F_8 ( V_10 ) ;
F_17 ( V_1 , V_16 , V_68 ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_39 -> V_10 = V_10 ;
V_1 -> V_30 -> V_31 ( V_39 , V_107 ) ;
V_39 -> V_7 = 0 ;
V_1 -> V_64 . V_72 = V_16 ;
F_18 ( args ) ;
F_19 ( args -> V_73 , V_1 , V_56 | V_69 ) ;
return 0 ;
}
int
F_23 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int error ;
T_12 * V_38 ;
T_3 * V_39 ;
enum V_109 V_110 ;
T_12 * V_111 ;
F_36 ( args ) ;
F_18 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_60 . V_61 & V_63 ) ;
if ( V_1 -> V_64 . V_72 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_82 ) ;
}
ASSERT ( V_1 -> V_60 . V_67 == V_1 -> V_64 . V_72 ) ;
ASSERT ( V_1 -> V_60 . V_70 . V_71 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
ASSERT ( V_1 -> V_64 . V_72 >= F_8 ( V_39 -> V_10 ) ) ;
if ( args -> V_14 == 1 && args -> V_22 [ 0 ] == '.' ) {
args -> V_24 = V_1 -> V_48 ;
args -> V_112 = V_113 ;
args -> V_88 = V_114 ;
return F_26 ( V_115 ) ;
}
if ( args -> V_14 == 2 &&
args -> V_22 [ 0 ] == '.' && args -> V_22 [ 1 ] == '.' ) {
args -> V_24 = V_1 -> V_30 -> V_49 ( V_39 ) ;
args -> V_112 = V_113 ;
args -> V_88 = V_114 ;
return F_26 ( V_115 ) ;
}
V_111 = NULL ;
for ( V_9 = 0 , V_38 = F_13 ( V_39 ) ; V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ) {
V_110 = V_1 -> V_18 -> V_116 -> V_117 ( args , V_38 -> V_22 ,
V_38 -> V_14 ) ;
if ( V_110 != V_118 && V_110 != args -> V_112 ) {
args -> V_112 = V_110 ;
args -> V_24 = V_1 -> V_30 -> V_104 ( V_39 , V_38 ) ;
args -> V_88 = V_1 -> V_30 -> V_105 ( V_38 ) ;
if ( V_110 == V_113 )
return F_26 ( V_115 ) ;
V_111 = V_38 ;
}
}
ASSERT ( args -> V_84 & V_119 ) ;
if ( ! V_111 )
return F_26 ( V_81 ) ;
error = F_37 ( args , V_111 -> V_22 , V_111 -> V_14 ) ;
return F_26 ( error ) ;
}
int
F_38 (
T_10 * args )
{
int V_87 ;
T_1 * V_1 ;
int V_120 ;
int V_9 ;
int V_121 ;
int V_122 ;
T_12 * V_38 ;
T_3 * V_39 ;
F_39 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_60 . V_61 & V_63 ) ;
V_122 = ( int ) V_1 -> V_64 . V_72 ;
if ( V_122 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_82 ) ;
}
ASSERT ( V_1 -> V_60 . V_67 == V_122 ) ;
ASSERT ( V_1 -> V_60 . V_70 . V_71 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
ASSERT ( V_122 >= F_8 ( V_39 -> V_10 ) ) ;
for ( V_9 = 0 , V_38 = F_13 ( V_39 ) ; V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ) {
if ( F_40 ( args , V_38 -> V_22 , V_38 -> V_14 ) ==
V_113 ) {
ASSERT ( V_1 -> V_30 -> V_104 ( V_39 , V_38 ) ==
args -> V_24 ) ;
break;
}
}
if ( V_9 == V_39 -> V_7 )
return F_26 ( V_81 ) ;
V_87 = ( int ) ( ( char * ) V_38 - ( char * ) V_39 ) ;
V_120 = V_1 -> V_30 -> V_83 ( V_39 , args -> V_14 ) ;
V_121 = V_122 - V_120 ;
if ( V_87 + V_120 < V_122 )
memmove ( ( char * ) V_39 + V_87 , ( char * ) V_39 + V_87 + V_120 ,
V_122 - ( V_87 + V_120 ) ) ;
V_39 -> V_7 -- ;
V_1 -> V_64 . V_72 = V_121 ;
F_17 ( V_1 , V_121 - V_122 , V_68 ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
#if V_23
if ( args -> V_24 > V_25 ) {
if ( V_39 -> V_10 == 1 )
F_41 ( args ) ;
else
V_39 -> V_10 -- ;
}
#endif
F_18 ( args ) ;
F_19 ( args -> V_73 , V_1 , V_56 | V_69 ) ;
return 0 ;
}
int
F_42 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
#if V_23 || F_43 ( V_123 )
T_9 V_103 = 0 ;
#endif
#if V_23
int V_124 ;
#endif
T_12 * V_38 ;
T_3 * V_39 ;
F_44 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_60 . V_61 & V_63 ) ;
if ( V_1 -> V_64 . V_72 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_82 ) ;
}
ASSERT ( V_1 -> V_60 . V_67 == V_1 -> V_64 . V_72 ) ;
ASSERT ( V_1 -> V_60 . V_70 . V_71 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
ASSERT ( V_1 -> V_64 . V_72 >= F_8 ( V_39 -> V_10 ) ) ;
#if V_23
if ( args -> V_24 > V_25 && V_39 -> V_10 == 0 ) {
int error ;
int V_121 ;
V_121 =
V_1 -> V_60 . V_67 +
( V_39 -> V_7 + 1 ) *
( ( V_26 ) sizeof( V_28 ) -
( V_26 ) sizeof( V_29 ) ) ;
if ( V_121 > F_9 ( V_1 ) ) {
error = F_28 ( args ) ;
if ( error ) {
return error ;
}
return F_45 ( args ) ;
}
F_31 ( args ) ;
V_124 = 1 ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
} else
V_124 = 0 ;
#endif
ASSERT ( args -> V_14 != 1 || args -> V_22 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_22 [ 0 ] == '.' && args -> V_22 [ 1 ] == '.' ) {
#if V_23 || F_43 ( V_123 )
V_103 = V_1 -> V_30 -> V_49 ( V_39 ) ;
ASSERT ( args -> V_24 != V_103 ) ;
#endif
V_1 -> V_30 -> V_31 ( V_39 , args -> V_24 ) ;
}
else {
for ( V_9 = 0 , V_38 = F_13 ( V_39 ) ; V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ) {
if ( F_40 ( args , V_38 -> V_22 , V_38 -> V_14 ) ==
V_113 ) {
#if V_23 || F_43 ( V_123 )
V_103 = V_1 -> V_30 -> V_104 ( V_39 , V_38 ) ;
ASSERT ( args -> V_24 != V_103 ) ;
#endif
V_1 -> V_30 -> V_51 ( V_39 , V_38 , args -> V_24 ) ;
V_1 -> V_30 -> V_52 ( V_38 , args -> V_88 ) ;
break;
}
}
if ( V_9 == V_39 -> V_7 ) {
ASSERT ( args -> V_84 & V_119 ) ;
#if V_23
if ( V_124 )
F_41 ( args ) ;
#endif
return F_26 ( V_81 ) ;
}
}
#if V_23
if ( V_103 > V_25 &&
args -> V_24 <= V_25 ) {
if ( V_39 -> V_10 == 1 )
F_41 ( args ) ;
else
V_39 -> V_10 -- ;
}
if ( V_103 <= V_25 &&
args -> V_24 > V_25 ) {
ASSERT ( V_39 -> V_10 != 0 ) ;
if ( ! V_124 )
V_39 -> V_10 ++ ;
}
#endif
F_18 ( args ) ;
F_19 ( args -> V_73 , V_1 , V_69 ) ;
return 0 ;
}
static void
F_41 (
T_10 * args )
{
char * V_90 ;
T_1 * V_1 ;
int V_9 ;
int V_121 ;
T_12 * V_94 ;
T_3 * V_95 ;
int V_122 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_96 * V_13 ;
F_46 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_122 = V_1 -> V_60 . V_67 ;
V_90 = F_12 ( V_122 , V_42 ) ;
V_95 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
ASSERT ( V_95 -> V_10 == 1 ) ;
memcpy ( V_90 , V_95 , V_122 ) ;
V_121 =
V_122 -
( V_95 -> V_7 + 1 ) *
( ( V_26 ) sizeof( V_28 ) - ( V_26 ) sizeof( V_29 ) ) ;
F_17 ( V_1 , - V_122 , V_68 ) ;
F_17 ( V_1 , V_121 , V_68 ) ;
V_95 = ( T_3 * ) V_90 ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_39 -> V_7 = V_95 -> V_7 ;
V_39 -> V_10 = 0 ;
V_1 -> V_30 -> V_31 ( V_39 , V_1 -> V_30 -> V_49 ( V_95 ) ) ;
for ( V_9 = 0 , V_38 = F_13 ( V_39 ) ,
V_94 = F_13 ( V_95 ) ;
V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ,
V_94 = V_1 -> V_30 -> V_54 ( V_95 , V_94 ) ) {
V_38 -> V_14 = V_94 -> V_14 ;
V_38 -> V_78 = V_94 -> V_78 ;
memcpy ( V_38 -> V_22 , V_94 -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_51 ( V_39 , V_38 ,
V_1 -> V_30 -> V_104 ( V_95 , V_94 ) ) ;
V_1 -> V_30 -> V_52 ( V_38 , V_1 -> V_30 -> V_105 ( V_94 ) ) ;
}
F_20 ( V_90 ) ;
V_1 -> V_64 . V_72 = V_121 ;
F_19 ( args -> V_73 , V_1 , V_56 | V_69 ) ;
}
static void
F_31 (
T_10 * args )
{
char * V_90 ;
T_1 * V_1 ;
int V_9 ;
int V_121 ;
T_12 * V_94 ;
T_3 * V_95 ;
int V_122 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_96 * V_13 ;
F_47 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_122 = V_1 -> V_60 . V_67 ;
V_90 = F_12 ( V_122 , V_42 ) ;
V_95 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
ASSERT ( V_95 -> V_10 == 0 ) ;
memcpy ( V_90 , V_95 , V_122 ) ;
V_121 =
V_122 +
( V_95 -> V_7 + 1 ) *
( ( V_26 ) sizeof( V_28 ) - ( V_26 ) sizeof( V_29 ) ) ;
F_17 ( V_1 , - V_122 , V_68 ) ;
F_17 ( V_1 , V_121 , V_68 ) ;
V_95 = ( T_3 * ) V_90 ;
V_39 = ( T_3 * ) V_1 -> V_60 . V_70 . V_71 ;
V_39 -> V_7 = V_95 -> V_7 ;
V_39 -> V_10 = 1 ;
V_1 -> V_30 -> V_31 ( V_39 , V_1 -> V_30 -> V_49 ( V_95 ) ) ;
for ( V_9 = 0 , V_38 = F_13 ( V_39 ) ,
V_94 = F_13 ( V_95 ) ;
V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_54 ( V_39 , V_38 ) ,
V_94 = V_1 -> V_30 -> V_54 ( V_95 , V_94 ) ) {
V_38 -> V_14 = V_94 -> V_14 ;
V_38 -> V_78 = V_94 -> V_78 ;
memcpy ( V_38 -> V_22 , V_94 -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_51 ( V_39 , V_38 ,
V_1 -> V_30 -> V_104 ( V_95 , V_94 ) ) ;
V_1 -> V_30 -> V_52 ( V_38 , V_1 -> V_30 -> V_105 ( V_94 ) ) ;
}
F_20 ( V_90 ) ;
V_1 -> V_64 . V_72 = V_121 ;
F_19 ( args -> V_73 , V_1 , V_56 | V_69 ) ;
}
