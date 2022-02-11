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
F_11 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_2 = F_12 ( V_13 -> V_40 , V_41 ) ;
memcpy ( V_2 , V_33 -> V_42 , V_13 -> V_40 ) ;
V_36 = V_43 ;
if ( ( error = F_13 ( args , V_13 -> V_44 , V_33 ) ) ) {
ASSERT ( error != V_45 ) ;
goto V_46;
}
V_1 -> V_47 . V_48 &= ~ V_49 ;
V_1 -> V_47 . V_48 |= V_50 ;
V_1 -> V_51 . V_52 = V_53 ;
ASSERT ( V_1 -> V_47 . V_54 == 0 ) ;
F_14 ( V_1 , V_16 , V_55 ) ;
V_36 |= V_56 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
memcpy ( V_39 , V_3 , F_8 ( V_3 -> V_10 ) ) ;
V_1 -> V_51 . V_59 = V_16 ;
V_6 = F_3 ( V_13 , V_2 ) ;
V_37 = ( char * ) V_1 -> V_30 -> V_60 ( V_2 ) ;
V_35 = ( char * ) F_4 ( V_6 ) ;
V_38 = F_15 ( V_39 ) ;
while ( V_37 < V_35 ) {
V_34 = ( T_11 * ) V_37 ;
if ( F_16 ( V_34 -> V_61 ) == V_62 ) {
V_37 += F_16 ( V_34 -> V_63 ) ;
continue;
}
V_8 = ( T_7 * ) V_37 ;
if ( V_8 -> V_14 == 1 && V_8 -> V_22 [ 0 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_24 ) == V_1 -> V_64 ) ;
else if ( V_8 -> V_14 == 2 &&
V_8 -> V_22 [ 0 ] == '.' && V_8 -> V_22 [ 1 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_24 ) ==
V_1 -> V_30 -> V_65 ( V_39 ) ) ;
else {
V_38 -> V_14 = V_8 -> V_14 ;
F_17 ( V_38 ,
( V_66 )
( ( char * ) V_8 - ( char * ) V_2 ) ) ;
memcpy ( V_38 -> V_22 , V_8 -> V_22 , V_8 -> V_14 ) ;
V_1 -> V_30 -> V_67 ( V_39 , V_38 ,
F_7 ( V_8 -> V_24 ) ) ;
V_1 -> V_30 -> V_68 ( V_38 ,
V_1 -> V_30 -> V_69 ( V_8 ) ) ;
V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ;
}
V_37 += V_1 -> V_30 -> V_71 ( V_8 -> V_14 ) ;
}
ASSERT ( ( char * ) V_38 - ( char * ) V_39 == V_16 ) ;
F_18 ( args ) ;
V_46:
F_19 ( args -> V_72 , V_1 , V_36 ) ;
F_20 ( V_2 ) ;
return error ;
}
int
F_21 (
T_10 * args )
{
int V_73 ;
T_1 * V_1 ;
int error ;
int V_74 ;
int V_75 ;
int V_76 ;
V_66 V_77 = 0 ;
int V_78 ;
int V_79 ;
T_3 * V_39 ;
T_12 * V_38 = NULL ;
F_22 ( args ) ;
ASSERT ( F_23 ( args ) == V_80 ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_47 . V_48 & V_50 ) ;
if ( V_1 -> V_51 . V_59 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_81 ) ;
}
ASSERT ( V_1 -> V_47 . V_54 == V_1 -> V_51 . V_59 ) ;
ASSERT ( V_1 -> V_47 . V_57 . V_58 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
ASSERT ( V_1 -> V_51 . V_59 >= F_8 ( V_39 -> V_10 ) ) ;
V_73 = V_1 -> V_30 -> V_82 ( V_39 , args -> V_14 ) ;
V_74 = V_73 ;
V_76 = 0 ;
#if V_23
if ( args -> V_24 > V_25 && V_39 -> V_10 == 0 ) {
V_73 +=
( V_26 ) sizeof( V_28 ) -
( V_26 ) sizeof( V_29 ) ;
V_74 +=
( V_39 -> V_7 + 2 ) *
( ( V_26 ) sizeof( V_28 ) -
( V_26 ) sizeof( V_29 ) ) ;
V_76 = 1 ;
}
#endif
V_78 = ( int ) V_1 -> V_51 . V_59 ;
V_75 = V_78 + V_74 ;
if ( V_75 > F_9 ( V_1 ) ||
( V_79 =
F_27 ( args , V_76 , & V_38 , & V_77 ) ) == 0 ) {
if ( ( args -> V_83 & V_84 ) || args -> V_85 == 0 )
return F_26 ( V_45 ) ;
error = F_28 ( args ) ;
if ( error )
return error ;
return F_29 ( args ) ;
}
if ( args -> V_83 & V_84 )
return 0 ;
if ( V_79 == 1 )
F_30 ( args , V_38 , V_77 , V_75 ) ;
else {
ASSERT ( V_79 == 2 ) ;
#if V_23
if ( V_76 )
F_31 ( args ) ;
#endif
F_32 ( args , V_76 , V_75 ) ;
}
F_19 ( args -> V_72 , V_1 , V_43 | V_56 ) ;
return 0 ;
}
static void
F_30 (
T_10 * args ,
T_12 * V_38 ,
V_66 V_77 ,
int V_75 )
{
int V_86 ;
T_1 * V_1 ;
T_3 * V_39 ;
V_1 = args -> V_1 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_86 = ( int ) ( ( char * ) V_38 - ( char * ) V_39 ) ;
F_14 ( V_1 , V_1 -> V_30 -> V_82 ( V_39 , args -> V_14 ) ,
V_55 ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_38 = ( T_12 * ) ( ( char * ) V_39 + V_86 ) ;
V_38 -> V_14 = args -> V_14 ;
F_17 ( V_38 , V_77 ) ;
memcpy ( V_38 -> V_22 , args -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_67 ( V_39 , V_38 , args -> V_24 ) ;
V_1 -> V_30 -> V_68 ( V_38 , args -> V_87 ) ;
V_39 -> V_7 ++ ;
#if V_23
if ( args -> V_24 > V_25 )
V_39 -> V_10 ++ ;
#endif
V_1 -> V_51 . V_59 = V_75 ;
F_18 ( args ) ;
}
static void
F_32 (
T_10 * args ,
int V_76 ,
int V_75 )
{
int V_88 ;
char * V_89 ;
T_1 * V_1 ;
int V_90 ;
int V_91 ;
V_66 V_92 ;
V_66 V_77 ;
int V_78 ;
T_12 * V_93 ;
T_3 * V_94 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_95 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_78 = ( int ) V_1 -> V_51 . V_59 ;
V_89 = F_12 ( V_78 , V_41 ) ;
V_94 = ( T_3 * ) V_89 ;
memcpy ( V_94 , V_39 , V_78 ) ;
for ( V_77 = V_1 -> V_30 -> V_96 ,
V_93 = F_15 ( V_94 ) ,
V_88 = V_1 -> V_30 -> V_71 ( args -> V_14 ) ,
V_90 = ( char * ) V_93 == & V_89 [ V_78 ] ;
! V_90 ;
V_77 = V_92 + V_1 -> V_30 -> V_71 ( V_93 -> V_14 ) ,
V_93 = V_1 -> V_30 -> V_70 ( V_94 , V_93 ) ,
V_90 = ( char * ) V_93 == & V_89 [ V_78 ] ) {
V_92 = F_33 ( V_93 ) ;
if ( V_77 + V_88 <= V_92 )
break;
}
F_14 ( V_1 , - V_78 , V_55 ) ;
F_14 ( V_1 , V_75 , V_55 ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_91 = ( int ) ( ( char * ) V_93 - ( char * ) V_94 ) ;
memcpy ( V_39 , V_94 , V_91 ) ;
V_38 = ( T_12 * ) ( ( char * ) V_39 + V_91 ) ;
V_38 -> V_14 = args -> V_14 ;
F_17 ( V_38 , V_77 ) ;
memcpy ( V_38 -> V_22 , args -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_67 ( V_39 , V_38 , args -> V_24 ) ;
V_1 -> V_30 -> V_68 ( V_38 , args -> V_87 ) ;
V_39 -> V_7 ++ ;
#if V_23
if ( args -> V_24 > V_25 && ! V_76 )
V_39 -> V_10 ++ ;
#endif
if ( ! V_90 ) {
V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ;
memcpy ( V_38 , V_93 , V_78 - V_91 ) ;
}
F_20 ( V_89 ) ;
V_1 -> V_51 . V_59 = V_75 ;
F_18 ( args ) ;
}
static int
F_27 (
T_10 * args ,
int V_76 ,
T_12 * * V_97 ,
V_66 * V_98 )
{
T_1 * V_1 ;
int V_99 ;
int V_9 ;
T_8 * V_13 ;
V_66 V_77 ;
T_12 * V_38 ;
T_3 * V_39 ;
int V_16 ;
int V_100 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_16 = V_1 -> V_30 -> V_71 ( args -> V_14 ) ;
V_77 = V_1 -> V_30 -> V_96 ;
V_38 = F_15 ( V_39 ) ;
V_99 = 0 ;
for ( V_9 = 0 ; V_9 < V_39 -> V_7 ; V_9 ++ ) {
if ( ! V_99 )
V_99 = V_77 + V_16 <= F_33 ( V_38 ) ;
V_77 = F_33 ( V_38 ) +
V_1 -> V_30 -> V_71 ( V_38 -> V_14 ) ;
V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ;
}
V_100 = V_77 +
( V_39 -> V_7 + 3 ) * ( V_26 ) sizeof( T_5 ) +
( V_26 ) sizeof( T_6 ) ;
if ( V_100 + ( V_99 ? 0 : V_16 ) > V_13 -> V_40 )
return 0 ;
#if V_23
if ( V_76 ) {
return 2 ;
}
#else
ASSERT ( V_76 == 0 ) ;
#endif
if ( V_100 + V_16 > V_13 -> V_40 )
return 2 ;
* V_97 = V_38 ;
* V_98 = V_77 ;
return 1 ;
}
static void
F_18 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int V_10 ;
T_9 V_101 ;
int V_77 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_95 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_77 = V_1 -> V_30 -> V_96 ;
V_101 = V_1 -> V_30 -> V_65 ( V_39 ) ;
V_10 = V_101 > V_25 ;
for ( V_9 = 0 , V_38 = F_15 ( V_39 ) ;
V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ) {
ASSERT ( F_33 ( V_38 ) >= V_77 ) ;
V_101 = V_1 -> V_30 -> V_102 ( V_39 , V_38 ) ;
V_10 += V_101 > V_25 ;
V_77 =
F_33 ( V_38 ) +
V_1 -> V_30 -> V_71 ( V_38 -> V_14 ) ;
ASSERT ( V_1 -> V_30 -> V_103 ( V_38 ) < V_104 ) ;
}
ASSERT ( V_10 == V_39 -> V_10 ) ;
ASSERT ( V_23 || V_10 == 0 ) ;
ASSERT ( ( char * ) V_38 - ( char * ) V_39 == V_1 -> V_51 . V_59 ) ;
ASSERT ( V_77 +
( V_39 -> V_7 + 2 ) * ( V_26 ) sizeof( T_5 ) +
( V_26 ) sizeof( T_6 ) <= V_13 -> V_40 ) ;
}
int
F_34 (
T_10 * args ,
T_9 V_105 )
{
T_1 * V_1 ;
int V_10 ;
T_3 * V_39 ;
int V_16 ;
F_35 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_1 -> V_51 . V_59 == 0 ) ;
if ( V_1 -> V_51 . V_52 == V_106 ) {
V_1 -> V_47 . V_48 &= ~ V_49 ;
V_1 -> V_51 . V_52 = V_53 ;
F_19 ( args -> V_72 , V_1 , V_43 ) ;
V_1 -> V_47 . V_48 |= V_50 ;
}
ASSERT ( V_1 -> V_47 . V_48 & V_50 ) ;
ASSERT ( V_1 -> V_47 . V_54 == 0 ) ;
V_10 = V_105 > V_25 ;
V_16 = F_8 ( V_10 ) ;
F_14 ( V_1 , V_16 , V_55 ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_39 -> V_10 = V_10 ;
V_1 -> V_30 -> V_31 ( V_39 , V_105 ) ;
V_39 -> V_7 = 0 ;
V_1 -> V_51 . V_59 = V_16 ;
F_18 ( args ) ;
F_19 ( args -> V_72 , V_1 , V_43 | V_56 ) ;
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
enum V_107 V_108 ;
T_12 * V_109 ;
F_36 ( args ) ;
F_18 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_47 . V_48 & V_50 ) ;
if ( V_1 -> V_51 . V_59 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_81 ) ;
}
ASSERT ( V_1 -> V_47 . V_54 == V_1 -> V_51 . V_59 ) ;
ASSERT ( V_1 -> V_47 . V_57 . V_58 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
ASSERT ( V_1 -> V_51 . V_59 >= F_8 ( V_39 -> V_10 ) ) ;
if ( args -> V_14 == 1 && args -> V_22 [ 0 ] == '.' ) {
args -> V_24 = V_1 -> V_64 ;
args -> V_110 = V_111 ;
args -> V_87 = V_112 ;
return F_26 ( V_113 ) ;
}
if ( args -> V_14 == 2 &&
args -> V_22 [ 0 ] == '.' && args -> V_22 [ 1 ] == '.' ) {
args -> V_24 = V_1 -> V_30 -> V_65 ( V_39 ) ;
args -> V_110 = V_111 ;
args -> V_87 = V_112 ;
return F_26 ( V_113 ) ;
}
V_109 = NULL ;
for ( V_9 = 0 , V_38 = F_15 ( V_39 ) ; V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ) {
V_108 = V_1 -> V_18 -> V_114 -> V_115 ( args , V_38 -> V_22 ,
V_38 -> V_14 ) ;
if ( V_108 != V_116 && V_108 != args -> V_110 ) {
args -> V_110 = V_108 ;
args -> V_24 = V_1 -> V_30 -> V_102 ( V_39 , V_38 ) ;
args -> V_87 = V_1 -> V_30 -> V_103 ( V_38 ) ;
if ( V_108 == V_111 )
return F_26 ( V_113 ) ;
V_109 = V_38 ;
}
}
ASSERT ( args -> V_83 & V_117 ) ;
if ( ! V_109 )
return F_26 ( V_80 ) ;
error = F_37 ( args , V_109 -> V_22 , V_109 -> V_14 ) ;
return F_26 ( error ) ;
}
int
F_38 (
T_10 * args )
{
int V_86 ;
T_1 * V_1 ;
int V_118 ;
int V_9 ;
int V_119 ;
int V_120 ;
T_12 * V_38 ;
T_3 * V_39 ;
F_39 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_47 . V_48 & V_50 ) ;
V_120 = ( int ) V_1 -> V_51 . V_59 ;
if ( V_120 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_81 ) ;
}
ASSERT ( V_1 -> V_47 . V_54 == V_120 ) ;
ASSERT ( V_1 -> V_47 . V_57 . V_58 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
ASSERT ( V_120 >= F_8 ( V_39 -> V_10 ) ) ;
for ( V_9 = 0 , V_38 = F_15 ( V_39 ) ; V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ) {
if ( F_40 ( args , V_38 -> V_22 , V_38 -> V_14 ) ==
V_111 ) {
ASSERT ( V_1 -> V_30 -> V_102 ( V_39 , V_38 ) ==
args -> V_24 ) ;
break;
}
}
if ( V_9 == V_39 -> V_7 )
return F_26 ( V_80 ) ;
V_86 = ( int ) ( ( char * ) V_38 - ( char * ) V_39 ) ;
V_118 = V_1 -> V_30 -> V_82 ( V_39 , args -> V_14 ) ;
V_119 = V_120 - V_118 ;
if ( V_86 + V_118 < V_120 )
memmove ( ( char * ) V_39 + V_86 , ( char * ) V_39 + V_86 + V_118 ,
V_120 - ( V_86 + V_118 ) ) ;
V_39 -> V_7 -- ;
V_1 -> V_51 . V_59 = V_119 ;
F_14 ( V_1 , V_119 - V_120 , V_55 ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
#if V_23
if ( args -> V_24 > V_25 ) {
if ( V_39 -> V_10 == 1 )
F_41 ( args ) ;
else
V_39 -> V_10 -- ;
}
#endif
F_18 ( args ) ;
F_19 ( args -> V_72 , V_1 , V_43 | V_56 ) ;
return 0 ;
}
int
F_42 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
#if V_23 || F_43 ( V_121 )
T_9 V_101 = 0 ;
#endif
#if V_23
int V_122 ;
#endif
T_12 * V_38 ;
T_3 * V_39 ;
F_44 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_47 . V_48 & V_50 ) ;
if ( V_1 -> V_51 . V_59 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_18 ) ) ;
return F_26 ( V_81 ) ;
}
ASSERT ( V_1 -> V_47 . V_54 == V_1 -> V_51 . V_59 ) ;
ASSERT ( V_1 -> V_47 . V_57 . V_58 != NULL ) ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
ASSERT ( V_1 -> V_51 . V_59 >= F_8 ( V_39 -> V_10 ) ) ;
#if V_23
if ( args -> V_24 > V_25 && V_39 -> V_10 == 0 ) {
int error ;
int V_119 ;
V_119 =
V_1 -> V_47 . V_54 +
( V_39 -> V_7 + 1 ) *
( ( V_26 ) sizeof( V_28 ) -
( V_26 ) sizeof( V_29 ) ) ;
if ( V_119 > F_9 ( V_1 ) ) {
error = F_28 ( args ) ;
if ( error ) {
return error ;
}
return F_45 ( args ) ;
}
F_31 ( args ) ;
V_122 = 1 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
} else
V_122 = 0 ;
#endif
ASSERT ( args -> V_14 != 1 || args -> V_22 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_22 [ 0 ] == '.' && args -> V_22 [ 1 ] == '.' ) {
#if V_23 || F_43 ( V_121 )
V_101 = V_1 -> V_30 -> V_65 ( V_39 ) ;
ASSERT ( args -> V_24 != V_101 ) ;
#endif
V_1 -> V_30 -> V_31 ( V_39 , args -> V_24 ) ;
}
else {
for ( V_9 = 0 , V_38 = F_15 ( V_39 ) ; V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ) {
if ( F_40 ( args , V_38 -> V_22 , V_38 -> V_14 ) ==
V_111 ) {
#if V_23 || F_43 ( V_121 )
V_101 = V_1 -> V_30 -> V_102 ( V_39 , V_38 ) ;
ASSERT ( args -> V_24 != V_101 ) ;
#endif
V_1 -> V_30 -> V_67 ( V_39 , V_38 , args -> V_24 ) ;
V_1 -> V_30 -> V_68 ( V_38 , args -> V_87 ) ;
break;
}
}
if ( V_9 == V_39 -> V_7 ) {
ASSERT ( args -> V_83 & V_117 ) ;
#if V_23
if ( V_122 )
F_41 ( args ) ;
#endif
return F_26 ( V_80 ) ;
}
}
#if V_23
if ( V_101 > V_25 &&
args -> V_24 <= V_25 ) {
if ( V_39 -> V_10 == 1 )
F_41 ( args ) ;
else
V_39 -> V_10 -- ;
}
if ( V_101 <= V_25 &&
args -> V_24 > V_25 ) {
ASSERT ( V_39 -> V_10 != 0 ) ;
if ( ! V_122 )
V_39 -> V_10 ++ ;
}
#endif
F_18 ( args ) ;
F_19 ( args -> V_72 , V_1 , V_56 ) ;
return 0 ;
}
static void
F_41 (
T_10 * args )
{
char * V_89 ;
T_1 * V_1 ;
int V_9 ;
int V_119 ;
T_12 * V_93 ;
T_3 * V_94 ;
int V_120 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_95 * V_13 ;
F_46 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_120 = V_1 -> V_47 . V_54 ;
V_89 = F_12 ( V_120 , V_41 ) ;
V_94 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
ASSERT ( V_94 -> V_10 == 1 ) ;
memcpy ( V_89 , V_94 , V_120 ) ;
V_119 =
V_120 -
( V_94 -> V_7 + 1 ) *
( ( V_26 ) sizeof( V_28 ) - ( V_26 ) sizeof( V_29 ) ) ;
F_14 ( V_1 , - V_120 , V_55 ) ;
F_14 ( V_1 , V_119 , V_55 ) ;
V_94 = ( T_3 * ) V_89 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_39 -> V_7 = V_94 -> V_7 ;
V_39 -> V_10 = 0 ;
V_1 -> V_30 -> V_31 ( V_39 , V_1 -> V_30 -> V_65 ( V_94 ) ) ;
for ( V_9 = 0 , V_38 = F_15 ( V_39 ) ,
V_93 = F_15 ( V_94 ) ;
V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ,
V_93 = V_1 -> V_30 -> V_70 ( V_94 , V_93 ) ) {
V_38 -> V_14 = V_93 -> V_14 ;
V_38 -> V_77 = V_93 -> V_77 ;
memcpy ( V_38 -> V_22 , V_93 -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_67 ( V_39 , V_38 ,
V_1 -> V_30 -> V_102 ( V_94 , V_93 ) ) ;
V_1 -> V_30 -> V_68 ( V_38 , V_1 -> V_30 -> V_103 ( V_93 ) ) ;
}
F_20 ( V_89 ) ;
V_1 -> V_51 . V_59 = V_119 ;
F_19 ( args -> V_72 , V_1 , V_43 | V_56 ) ;
}
static void
F_31 (
T_10 * args )
{
char * V_89 ;
T_1 * V_1 ;
int V_9 ;
int V_119 ;
T_12 * V_93 ;
T_3 * V_94 ;
int V_120 ;
T_12 * V_38 ;
T_3 * V_39 ;
struct V_95 * V_13 ;
F_47 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_18 ;
V_120 = V_1 -> V_47 . V_54 ;
V_89 = F_12 ( V_120 , V_41 ) ;
V_94 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
ASSERT ( V_94 -> V_10 == 0 ) ;
memcpy ( V_89 , V_94 , V_120 ) ;
V_119 =
V_120 +
( V_94 -> V_7 + 1 ) *
( ( V_26 ) sizeof( V_28 ) - ( V_26 ) sizeof( V_29 ) ) ;
F_14 ( V_1 , - V_120 , V_55 ) ;
F_14 ( V_1 , V_119 , V_55 ) ;
V_94 = ( T_3 * ) V_89 ;
V_39 = ( T_3 * ) V_1 -> V_47 . V_57 . V_58 ;
V_39 -> V_7 = V_94 -> V_7 ;
V_39 -> V_10 = 1 ;
V_1 -> V_30 -> V_31 ( V_39 , V_1 -> V_30 -> V_65 ( V_94 ) ) ;
for ( V_9 = 0 , V_38 = F_15 ( V_39 ) ,
V_93 = F_15 ( V_94 ) ;
V_9 < V_39 -> V_7 ;
V_9 ++ , V_38 = V_1 -> V_30 -> V_70 ( V_39 , V_38 ) ,
V_93 = V_1 -> V_30 -> V_70 ( V_94 , V_93 ) ) {
V_38 -> V_14 = V_93 -> V_14 ;
V_38 -> V_77 = V_93 -> V_77 ;
memcpy ( V_38 -> V_22 , V_93 -> V_22 , V_38 -> V_14 ) ;
V_1 -> V_30 -> V_67 ( V_39 , V_38 ,
V_1 -> V_30 -> V_102 ( V_94 , V_93 ) ) ;
V_1 -> V_30 -> V_68 ( V_38 , V_1 -> V_30 -> V_103 ( V_93 ) ) ;
}
F_20 ( V_89 ) ;
V_1 -> V_51 . V_59 = V_119 ;
F_19 ( args -> V_72 , V_1 , V_43 | V_56 ) ;
}
