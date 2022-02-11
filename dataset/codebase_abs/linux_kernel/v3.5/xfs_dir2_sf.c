static T_1
F_1 (
struct V_1 * V_2 ,
T_2 * V_3 )
{
if ( V_2 -> V_4 )
return F_2 ( & V_3 -> V_5 . V_6 ) & 0x00ffffffffffffffULL ;
else
return F_3 ( & V_3 -> V_7 . V_6 ) ;
}
static void
F_4 (
struct V_1 * V_2 ,
T_2 * V_8 ,
T_1 V_9 )
{
ASSERT ( ( V_9 & 0xff00000000000000ULL ) == 0 ) ;
if ( V_2 -> V_4 )
F_5 ( V_9 , & V_8 -> V_5 . V_6 ) ;
else
F_6 ( V_9 , & V_8 -> V_7 . V_6 ) ;
}
T_1
F_7 (
struct V_1 * V_2 )
{
return F_1 ( V_2 , & V_2 -> V_10 ) ;
}
static void
F_8 (
struct V_1 * V_2 ,
T_1 V_9 )
{
F_4 ( V_2 , & V_2 -> V_10 , V_9 ) ;
}
static T_2 *
F_9 (
struct V_11 * V_12 )
{
return ( T_2 * ) & V_12 -> V_13 [ V_12 -> V_14 ] ;
}
T_1
F_10 (
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
return F_1 ( V_2 , F_9 ( V_12 ) ) ;
}
static void
F_11 (
struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_1 V_9 )
{
F_4 ( V_2 , F_9 ( V_12 ) , V_9 ) ;
}
int
F_12 (
T_3 * V_15 ,
T_4 * V_2 ,
T_5 * V_16 )
{
T_6 V_17 ;
T_7 * V_18 ;
T_8 * V_19 ;
int V_20 ;
T_9 * V_21 ;
int V_6 ;
int V_4 ;
int V_22 ;
int V_23 ;
T_10 * V_24 ;
int V_14 ;
T_1 V_10 = 0 ;
int V_25 = 0 ;
V_24 = V_15 -> V_26 ;
V_20 = V_4 = V_14 = 0 ;
V_19 = F_13 ( V_24 , V_2 ) ;
V_18 = F_14 ( V_19 ) ;
for ( V_6 = 0 ; V_6 < F_15 ( V_19 -> V_20 ) ; V_6 ++ ) {
if ( ( V_17 = F_15 ( V_18 [ V_6 ] . V_27 ) ) == V_28 )
continue;
V_21 = ( T_9 * )
( ( char * ) V_2 + F_16 ( V_24 , V_17 ) ) ;
V_22 = V_21 -> V_14 == 1 && V_21 -> V_13 [ 0 ] == '.' ;
V_23 =
V_21 -> V_14 == 2 &&
V_21 -> V_13 [ 0 ] == '.' && V_21 -> V_13 [ 1 ] == '.' ;
#if V_29
if ( ! V_22 )
V_4 += F_17 ( V_21 -> V_30 ) > V_31 ;
#endif
if ( ! V_22 && ! V_23 ) {
V_20 ++ ;
V_14 += V_21 -> V_14 ;
} else if ( V_23 )
V_10 = F_17 ( V_21 -> V_30 ) ;
V_25 = F_18 ( V_4 ) +
V_20 +
V_20 * ( V_32 ) sizeof( V_33 ) +
V_14 +
( V_4 ?
( V_32 ) sizeof( V_34 ) * V_20 :
( V_32 ) sizeof( V_35 ) * V_20 ) ;
if ( V_25 > F_19 ( V_15 ) )
return V_25 ;
}
V_16 -> V_20 = V_20 ;
V_16 -> V_4 = V_4 ;
F_8 ( V_16 , V_10 ) ;
return V_25 ;
}
int
F_20 (
T_11 * args ,
T_12 * V_36 ,
int V_25 ,
T_5 * V_16 )
{
T_4 * V_2 ;
T_8 * V_19 ;
T_9 * V_21 ;
T_3 * V_15 ;
T_13 * V_37 ;
char * V_38 ;
int error ;
int V_39 ;
T_10 * V_24 ;
char * V_40 ;
T_14 * V_12 ;
T_5 * V_41 ;
F_21 ( args ) ;
V_15 = args -> V_15 ;
V_24 = V_15 -> V_26 ;
V_2 = F_22 ( V_24 -> V_42 , V_43 ) ;
memcpy ( V_2 , V_36 -> V_44 , V_24 -> V_42 ) ;
V_39 = V_45 ;
if ( ( error = F_23 ( args , V_24 -> V_46 , V_36 ) ) ) {
ASSERT ( error != V_47 ) ;
goto V_48;
}
V_15 -> V_49 . V_50 &= ~ V_51 ;
V_15 -> V_49 . V_50 |= V_52 ;
V_15 -> V_53 . V_54 = V_55 ;
ASSERT ( V_15 -> V_49 . V_56 == 0 ) ;
F_24 ( V_15 , V_25 , V_57 ) ;
V_39 |= V_58 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
memcpy ( V_41 , V_16 , F_18 ( V_16 -> V_4 ) ) ;
V_15 -> V_53 . V_61 = V_25 ;
V_19 = F_13 ( V_24 , V_2 ) ;
V_40 = ( char * ) ( V_2 + 1 ) ;
V_38 = ( char * ) F_14 ( V_19 ) ;
V_12 = F_25 ( V_41 ) ;
while ( V_40 < V_38 ) {
V_37 = ( T_13 * ) V_40 ;
if ( F_26 ( V_37 -> V_62 ) == V_63 ) {
V_40 += F_26 ( V_37 -> V_64 ) ;
continue;
}
V_21 = ( T_9 * ) V_40 ;
if ( V_21 -> V_14 == 1 && V_21 -> V_13 [ 0 ] == '.' )
ASSERT ( F_17 ( V_21 -> V_30 ) == V_15 -> V_65 ) ;
else if ( V_21 -> V_14 == 2 &&
V_21 -> V_13 [ 0 ] == '.' && V_21 -> V_13 [ 1 ] == '.' )
ASSERT ( F_17 ( V_21 -> V_30 ) ==
F_7 ( V_41 ) ) ;
else {
V_12 -> V_14 = V_21 -> V_14 ;
F_27 ( V_12 ,
( V_66 )
( ( char * ) V_21 - ( char * ) V_2 ) ) ;
memcpy ( V_12 -> V_13 , V_21 -> V_13 , V_21 -> V_14 ) ;
F_11 ( V_41 , V_12 ,
F_17 ( V_21 -> V_30 ) ) ;
V_12 = F_28 ( V_41 , V_12 ) ;
}
V_40 += F_29 ( V_21 -> V_14 ) ;
}
ASSERT ( ( char * ) V_12 - ( char * ) V_41 == V_25 ) ;
F_30 ( args ) ;
V_48:
F_31 ( args -> V_67 , V_15 , V_39 ) ;
F_32 ( V_2 ) ;
return error ;
}
int
F_33 (
T_11 * args )
{
int V_68 ;
T_3 * V_15 ;
int error ;
int V_69 ;
int V_70 ;
int V_71 ;
V_66 V_72 = 0 ;
int V_73 ;
int V_74 ;
T_5 * V_41 ;
T_14 * V_12 = NULL ;
F_34 ( args ) ;
ASSERT ( F_35 ( args ) == V_75 ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_49 . V_50 & V_52 ) ;
if ( V_15 -> V_53 . V_61 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_76 ) ;
}
ASSERT ( V_15 -> V_49 . V_56 == V_15 -> V_53 . V_61 ) ;
ASSERT ( V_15 -> V_49 . V_59 . V_60 != NULL ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
ASSERT ( V_15 -> V_53 . V_61 >= F_18 ( V_41 -> V_4 ) ) ;
V_68 = F_39 ( V_41 , args -> V_14 ) ;
V_69 = V_68 ;
V_71 = 0 ;
#if V_29
if ( args -> V_30 > V_31 && V_41 -> V_4 == 0 ) {
V_68 +=
( V_32 ) sizeof( V_34 ) -
( V_32 ) sizeof( V_35 ) ;
V_69 +=
( V_41 -> V_20 + 2 ) *
( ( V_32 ) sizeof( V_34 ) -
( V_32 ) sizeof( V_35 ) ) ;
V_71 = 1 ;
}
#endif
V_73 = ( int ) V_15 -> V_53 . V_61 ;
V_70 = V_73 + V_69 ;
if ( V_70 > F_19 ( V_15 ) ||
( V_74 =
F_40 ( args , V_71 , & V_12 , & V_72 ) ) == 0 ) {
if ( ( args -> V_77 & V_78 ) || args -> V_79 == 0 )
return F_38 ( V_47 ) ;
error = F_41 ( args ) ;
if ( error )
return error ;
return F_42 ( args ) ;
}
if ( args -> V_77 & V_78 )
return 0 ;
if ( V_74 == 1 )
F_43 ( args , V_12 , V_72 , V_70 ) ;
else {
ASSERT ( V_74 == 2 ) ;
#if V_29
if ( V_71 )
F_44 ( args ) ;
#endif
F_45 ( args , V_71 , V_70 ) ;
}
F_31 ( args -> V_67 , V_15 , V_45 | V_58 ) ;
return 0 ;
}
static void
F_43 (
T_11 * args ,
T_14 * V_12 ,
V_66 V_72 ,
int V_70 )
{
int V_80 ;
T_3 * V_15 ;
T_5 * V_41 ;
V_15 = args -> V_15 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_80 = ( int ) ( ( char * ) V_12 - ( char * ) V_41 ) ;
F_24 ( V_15 , F_39 ( V_41 , args -> V_14 ) ,
V_57 ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_12 = ( T_14 * ) ( ( char * ) V_41 + V_80 ) ;
V_12 -> V_14 = args -> V_14 ;
F_27 ( V_12 , V_72 ) ;
memcpy ( V_12 -> V_13 , args -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_41 , V_12 , args -> V_30 ) ;
V_41 -> V_20 ++ ;
#if V_29
if ( args -> V_30 > V_31 )
V_41 -> V_4 ++ ;
#endif
V_15 -> V_53 . V_61 = V_70 ;
F_30 ( args ) ;
}
static void
F_45 (
T_11 * args ,
int V_71 ,
int V_70 )
{
int V_81 ;
char * V_82 ;
T_3 * V_15 ;
int V_83 ;
int V_84 ;
V_66 V_85 ;
V_66 V_72 ;
int V_73 ;
T_14 * V_86 ;
T_5 * V_87 ;
T_14 * V_12 ;
T_5 * V_41 ;
V_15 = args -> V_15 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_73 = ( int ) V_15 -> V_53 . V_61 ;
V_82 = F_22 ( V_73 , V_43 ) ;
V_87 = ( T_5 * ) V_82 ;
memcpy ( V_87 , V_41 , V_73 ) ;
for ( V_72 = V_88 ,
V_86 = F_25 ( V_87 ) ,
V_81 = F_29 ( args -> V_14 ) ,
V_83 = ( char * ) V_86 == & V_82 [ V_73 ] ;
! V_83 ;
V_72 = V_85 + F_29 ( V_86 -> V_14 ) ,
V_86 = F_28 ( V_87 , V_86 ) ,
V_83 = ( char * ) V_86 == & V_82 [ V_73 ] ) {
V_85 = F_46 ( V_86 ) ;
if ( V_72 + V_81 <= V_85 )
break;
}
F_24 ( V_15 , - V_73 , V_57 ) ;
F_24 ( V_15 , V_70 , V_57 ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_84 = ( int ) ( ( char * ) V_86 - ( char * ) V_87 ) ;
memcpy ( V_41 , V_87 , V_84 ) ;
V_12 = ( T_14 * ) ( ( char * ) V_41 + V_84 ) ;
V_12 -> V_14 = args -> V_14 ;
F_27 ( V_12 , V_72 ) ;
memcpy ( V_12 -> V_13 , args -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_41 , V_12 , args -> V_30 ) ;
V_41 -> V_20 ++ ;
#if V_29
if ( args -> V_30 > V_31 && ! V_71 )
V_41 -> V_4 ++ ;
#endif
if ( ! V_83 ) {
V_12 = F_28 ( V_41 , V_12 ) ;
memcpy ( V_12 , V_86 , V_73 - V_84 ) ;
}
F_32 ( V_82 ) ;
V_15 -> V_53 . V_61 = V_70 ;
F_30 ( args ) ;
}
static int
F_40 (
T_11 * args ,
int V_71 ,
T_14 * * V_89 ,
V_66 * V_90 )
{
T_3 * V_15 ;
int V_91 ;
int V_6 ;
T_10 * V_24 ;
V_66 V_72 ;
T_14 * V_12 ;
T_5 * V_41 ;
int V_25 ;
int V_92 ;
V_15 = args -> V_15 ;
V_24 = V_15 -> V_26 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_25 = F_29 ( args -> V_14 ) ;
V_72 = V_88 ;
V_12 = F_25 ( V_41 ) ;
V_91 = 0 ;
for ( V_6 = 0 ; V_6 < V_41 -> V_20 ; V_6 ++ ) {
if ( ! V_91 )
V_91 = V_72 + V_25 <= F_46 ( V_12 ) ;
V_72 = F_46 ( V_12 ) +
F_29 ( V_12 -> V_14 ) ;
V_12 = F_28 ( V_41 , V_12 ) ;
}
V_92 = V_72 +
( V_41 -> V_20 + 3 ) * ( V_32 ) sizeof( T_7 ) +
( V_32 ) sizeof( T_8 ) ;
if ( V_92 + ( V_91 ? 0 : V_25 ) > V_24 -> V_42 )
return 0 ;
#if V_29
if ( V_71 ) {
return 2 ;
}
#else
ASSERT ( V_71 == 0 ) ;
#endif
if ( V_92 + V_25 > V_24 -> V_42 )
return 2 ;
* V_89 = V_12 ;
* V_90 = V_72 ;
return 1 ;
}
static void
F_30 (
T_11 * args )
{
T_3 * V_15 ;
int V_6 ;
int V_4 ;
T_1 V_9 ;
int V_72 ;
T_14 * V_12 ;
T_5 * V_41 ;
V_15 = args -> V_15 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_72 = V_88 ;
V_9 = F_7 ( V_41 ) ;
V_4 = V_9 > V_31 ;
for ( V_6 = 0 , V_12 = F_25 ( V_41 ) ;
V_6 < V_41 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_41 , V_12 ) ) {
ASSERT ( F_46 ( V_12 ) >= V_72 ) ;
V_9 = F_10 ( V_41 , V_12 ) ;
V_4 += V_9 > V_31 ;
V_72 =
F_46 ( V_12 ) +
F_29 ( V_12 -> V_14 ) ;
}
ASSERT ( V_4 == V_41 -> V_4 ) ;
ASSERT ( V_29 || V_4 == 0 ) ;
ASSERT ( ( char * ) V_12 - ( char * ) V_41 == V_15 -> V_53 . V_61 ) ;
ASSERT ( V_72 +
( V_41 -> V_20 + 2 ) * ( V_32 ) sizeof( T_7 ) +
( V_32 ) sizeof( T_8 ) <=
V_15 -> V_26 -> V_42 ) ;
}
int
F_47 (
T_11 * args ,
T_1 V_93 )
{
T_3 * V_15 ;
int V_4 ;
T_5 * V_41 ;
int V_25 ;
F_48 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 != NULL ) ;
ASSERT ( V_15 -> V_53 . V_61 == 0 ) ;
if ( V_15 -> V_53 . V_54 == V_94 ) {
V_15 -> V_49 . V_50 &= ~ V_51 ;
V_15 -> V_53 . V_54 = V_55 ;
F_31 ( args -> V_67 , V_15 , V_45 ) ;
V_15 -> V_49 . V_50 |= V_52 ;
}
ASSERT ( V_15 -> V_49 . V_50 & V_52 ) ;
ASSERT ( V_15 -> V_49 . V_56 == 0 ) ;
V_4 = V_93 > V_31 ;
V_25 = F_18 ( V_4 ) ;
F_24 ( V_15 , V_25 , V_57 ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_41 -> V_4 = V_4 ;
F_8 ( V_41 , V_93 ) ;
V_41 -> V_20 = 0 ;
V_15 -> V_53 . V_61 = V_25 ;
F_30 ( args ) ;
F_31 ( args -> V_67 , V_15 , V_45 | V_58 ) ;
return 0 ;
}
int
F_49 (
T_3 * V_15 ,
void * V_95 ,
T_15 * V_72 ,
T_16 V_96 )
{
int V_6 ;
T_10 * V_24 ;
T_6 V_97 ;
T_14 * V_12 ;
T_5 * V_41 ;
T_6 V_98 ;
T_6 V_99 ;
T_1 V_9 ;
V_24 = V_15 -> V_26 ;
ASSERT ( V_15 -> V_49 . V_50 & V_52 ) ;
if ( V_15 -> V_53 . V_61 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_24 ) ) ;
return F_38 ( V_76 ) ;
}
ASSERT ( V_15 -> V_49 . V_56 == V_15 -> V_53 . V_61 ) ;
ASSERT ( V_15 -> V_49 . V_59 . V_60 != NULL ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
ASSERT ( V_15 -> V_53 . V_61 >= F_18 ( V_41 -> V_4 ) ) ;
if ( F_50 ( V_24 , * V_72 ) > V_24 -> V_46 )
return 0 ;
V_98 = F_51 ( V_24 , V_24 -> V_46 ,
V_100 ) ;
V_99 = F_51 ( V_24 , V_24 -> V_46 ,
V_101 ) ;
if ( * V_72 <= V_98 ) {
if ( V_96 ( V_95 , L_1 , 1 , V_98 & 0x7fffffff , V_15 -> V_65 , V_102 ) ) {
* V_72 = V_98 & 0x7fffffff ;
return 0 ;
}
}
if ( * V_72 <= V_99 ) {
V_9 = F_7 ( V_41 ) ;
if ( V_96 ( V_95 , L_2 , 2 , V_99 & 0x7fffffff , V_9 , V_102 ) ) {
* V_72 = V_99 & 0x7fffffff ;
return 0 ;
}
}
V_12 = F_25 ( V_41 ) ;
for ( V_6 = 0 ; V_6 < V_41 -> V_20 ; V_6 ++ ) {
V_97 = F_51 ( V_24 , V_24 -> V_46 ,
F_46 ( V_12 ) ) ;
if ( * V_72 > V_97 ) {
V_12 = F_28 ( V_41 , V_12 ) ;
continue;
}
V_9 = F_10 ( V_41 , V_12 ) ;
if ( V_96 ( V_95 , ( char * ) V_12 -> V_13 , V_12 -> V_14 ,
V_97 & 0x7fffffff , V_9 , V_103 ) ) {
* V_72 = V_97 & 0x7fffffff ;
return 0 ;
}
V_12 = F_28 ( V_41 , V_12 ) ;
}
* V_72 = F_51 ( V_24 , V_24 -> V_46 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
int
F_35 (
T_11 * args )
{
T_3 * V_15 ;
int V_6 ;
int error ;
T_14 * V_12 ;
T_5 * V_41 ;
enum V_104 V_105 ;
T_14 * V_106 ;
F_52 ( args ) ;
F_30 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_49 . V_50 & V_52 ) ;
if ( V_15 -> V_53 . V_61 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_76 ) ;
}
ASSERT ( V_15 -> V_49 . V_56 == V_15 -> V_53 . V_61 ) ;
ASSERT ( V_15 -> V_49 . V_59 . V_60 != NULL ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
ASSERT ( V_15 -> V_53 . V_61 >= F_18 ( V_41 -> V_4 ) ) ;
if ( args -> V_14 == 1 && args -> V_13 [ 0 ] == '.' ) {
args -> V_30 = V_15 -> V_65 ;
args -> V_107 = V_108 ;
return F_38 ( V_109 ) ;
}
if ( args -> V_14 == 2 &&
args -> V_13 [ 0 ] == '.' && args -> V_13 [ 1 ] == '.' ) {
args -> V_30 = F_7 ( V_41 ) ;
args -> V_107 = V_108 ;
return F_38 ( V_109 ) ;
}
V_106 = NULL ;
for ( V_6 = 0 , V_12 = F_25 ( V_41 ) ; V_6 < V_41 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_41 , V_12 ) ) {
V_105 = V_15 -> V_26 -> V_110 -> V_111 ( args , V_12 -> V_13 ,
V_12 -> V_14 ) ;
if ( V_105 != V_112 && V_105 != args -> V_107 ) {
args -> V_107 = V_105 ;
args -> V_30 = F_10 ( V_41 , V_12 ) ;
if ( V_105 == V_108 )
return F_38 ( V_109 ) ;
V_106 = V_12 ;
}
}
ASSERT ( args -> V_77 & V_113 ) ;
if ( ! V_106 )
return F_38 ( V_75 ) ;
error = F_53 ( args , V_106 -> V_13 , V_106 -> V_14 ) ;
return F_38 ( error ) ;
}
int
F_54 (
T_11 * args )
{
int V_80 ;
T_3 * V_15 ;
int V_114 ;
int V_6 ;
int V_115 ;
int V_116 ;
T_14 * V_12 ;
T_5 * V_41 ;
F_55 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_49 . V_50 & V_52 ) ;
V_116 = ( int ) V_15 -> V_53 . V_61 ;
if ( V_116 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_76 ) ;
}
ASSERT ( V_15 -> V_49 . V_56 == V_116 ) ;
ASSERT ( V_15 -> V_49 . V_59 . V_60 != NULL ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
ASSERT ( V_116 >= F_18 ( V_41 -> V_4 ) ) ;
for ( V_6 = 0 , V_12 = F_25 ( V_41 ) ; V_6 < V_41 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_41 , V_12 ) ) {
if ( F_56 ( args , V_12 -> V_13 , V_12 -> V_14 ) ==
V_108 ) {
ASSERT ( F_10 ( V_41 , V_12 ) ==
args -> V_30 ) ;
break;
}
}
if ( V_6 == V_41 -> V_20 )
return F_38 ( V_75 ) ;
V_80 = ( int ) ( ( char * ) V_12 - ( char * ) V_41 ) ;
V_114 = F_39 ( V_41 , args -> V_14 ) ;
V_115 = V_116 - V_114 ;
if ( V_80 + V_114 < V_116 )
memmove ( ( char * ) V_41 + V_80 , ( char * ) V_41 + V_80 + V_114 ,
V_116 - ( V_80 + V_114 ) ) ;
V_41 -> V_20 -- ;
V_15 -> V_53 . V_61 = V_115 ;
F_24 ( V_15 , V_115 - V_116 , V_57 ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
#if V_29
if ( args -> V_30 > V_31 ) {
if ( V_41 -> V_4 == 1 )
F_57 ( args ) ;
else
V_41 -> V_4 -- ;
}
#endif
F_30 ( args ) ;
F_31 ( args -> V_67 , V_15 , V_45 | V_58 ) ;
return 0 ;
}
int
F_58 (
T_11 * args )
{
T_3 * V_15 ;
int V_6 ;
#if V_29 || F_59 ( V_117 )
T_1 V_9 = 0 ;
#endif
#if V_29
int V_118 ;
#endif
T_14 * V_12 ;
T_5 * V_41 ;
F_60 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_49 . V_50 & V_52 ) ;
if ( V_15 -> V_53 . V_61 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_76 ) ;
}
ASSERT ( V_15 -> V_49 . V_56 == V_15 -> V_53 . V_61 ) ;
ASSERT ( V_15 -> V_49 . V_59 . V_60 != NULL ) ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
ASSERT ( V_15 -> V_53 . V_61 >= F_18 ( V_41 -> V_4 ) ) ;
#if V_29
if ( args -> V_30 > V_31 && V_41 -> V_4 == 0 ) {
int error ;
int V_115 ;
V_115 =
V_15 -> V_49 . V_56 +
( V_41 -> V_20 + 1 ) *
( ( V_32 ) sizeof( V_34 ) -
( V_32 ) sizeof( V_35 ) ) ;
if ( V_115 > F_19 ( V_15 ) ) {
error = F_41 ( args ) ;
if ( error ) {
return error ;
}
return F_61 ( args ) ;
}
F_44 ( args ) ;
V_118 = 1 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
} else
V_118 = 0 ;
#endif
ASSERT ( args -> V_14 != 1 || args -> V_13 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_13 [ 0 ] == '.' && args -> V_13 [ 1 ] == '.' ) {
#if V_29 || F_59 ( V_117 )
V_9 = F_7 ( V_41 ) ;
ASSERT ( args -> V_30 != V_9 ) ;
#endif
F_8 ( V_41 , args -> V_30 ) ;
}
else {
for ( V_6 = 0 , V_12 = F_25 ( V_41 ) ;
V_6 < V_41 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_41 , V_12 ) ) {
if ( F_56 ( args , V_12 -> V_13 , V_12 -> V_14 ) ==
V_108 ) {
#if V_29 || F_59 ( V_117 )
V_9 = F_10 ( V_41 , V_12 ) ;
ASSERT ( args -> V_30 != V_9 ) ;
#endif
F_11 ( V_41 , V_12 , args -> V_30 ) ;
break;
}
}
if ( V_6 == V_41 -> V_20 ) {
ASSERT ( args -> V_77 & V_113 ) ;
#if V_29
if ( V_118 )
F_57 ( args ) ;
#endif
return F_38 ( V_75 ) ;
}
}
#if V_29
if ( V_9 > V_31 &&
args -> V_30 <= V_31 ) {
if ( V_41 -> V_4 == 1 )
F_57 ( args ) ;
else
V_41 -> V_4 -- ;
}
if ( V_9 <= V_31 &&
args -> V_30 > V_31 ) {
ASSERT ( V_41 -> V_4 != 0 ) ;
if ( ! V_118 )
V_41 -> V_4 ++ ;
}
#endif
F_30 ( args ) ;
F_31 ( args -> V_67 , V_15 , V_58 ) ;
return 0 ;
}
static void
F_57 (
T_11 * args )
{
char * V_82 ;
T_3 * V_15 ;
int V_6 ;
int V_115 ;
T_14 * V_86 ;
T_5 * V_87 ;
int V_116 ;
T_14 * V_12 ;
T_5 * V_41 ;
F_62 ( args ) ;
V_15 = args -> V_15 ;
V_116 = V_15 -> V_49 . V_56 ;
V_82 = F_22 ( V_116 , V_43 ) ;
V_87 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
ASSERT ( V_87 -> V_4 == 1 ) ;
memcpy ( V_82 , V_87 , V_116 ) ;
V_115 =
V_116 -
( V_87 -> V_20 + 1 ) *
( ( V_32 ) sizeof( V_34 ) - ( V_32 ) sizeof( V_35 ) ) ;
F_24 ( V_15 , - V_116 , V_57 ) ;
F_24 ( V_15 , V_115 , V_57 ) ;
V_87 = ( T_5 * ) V_82 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_41 -> V_20 = V_87 -> V_20 ;
V_41 -> V_4 = 0 ;
F_8 ( V_41 , F_7 ( V_87 ) ) ;
for ( V_6 = 0 , V_12 = F_25 ( V_41 ) ,
V_86 = F_25 ( V_87 ) ;
V_6 < V_41 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_41 , V_12 ) ,
V_86 = F_28 ( V_87 , V_86 ) ) {
V_12 -> V_14 = V_86 -> V_14 ;
V_12 -> V_72 = V_86 -> V_72 ;
memcpy ( V_12 -> V_13 , V_86 -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_41 , V_12 ,
F_10 ( V_87 , V_86 ) ) ;
}
F_32 ( V_82 ) ;
V_15 -> V_53 . V_61 = V_115 ;
F_31 ( args -> V_67 , V_15 , V_45 | V_58 ) ;
}
static void
F_44 (
T_11 * args )
{
char * V_82 ;
T_3 * V_15 ;
int V_6 ;
int V_115 ;
T_14 * V_86 ;
T_5 * V_87 ;
int V_116 ;
T_14 * V_12 ;
T_5 * V_41 ;
F_63 ( args ) ;
V_15 = args -> V_15 ;
V_116 = V_15 -> V_49 . V_56 ;
V_82 = F_22 ( V_116 , V_43 ) ;
V_87 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
ASSERT ( V_87 -> V_4 == 0 ) ;
memcpy ( V_82 , V_87 , V_116 ) ;
V_115 =
V_116 +
( V_87 -> V_20 + 1 ) *
( ( V_32 ) sizeof( V_34 ) - ( V_32 ) sizeof( V_35 ) ) ;
F_24 ( V_15 , - V_116 , V_57 ) ;
F_24 ( V_15 , V_115 , V_57 ) ;
V_87 = ( T_5 * ) V_82 ;
V_41 = ( T_5 * ) V_15 -> V_49 . V_59 . V_60 ;
V_41 -> V_20 = V_87 -> V_20 ;
V_41 -> V_4 = 1 ;
F_8 ( V_41 , F_7 ( V_87 ) ) ;
for ( V_6 = 0 , V_12 = F_25 ( V_41 ) ,
V_86 = F_25 ( V_87 ) ;
V_6 < V_41 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_41 , V_12 ) ,
V_86 = F_28 ( V_87 , V_86 ) ) {
V_12 -> V_14 = V_86 -> V_14 ;
V_12 -> V_72 = V_86 -> V_72 ;
memcpy ( V_12 -> V_13 , V_86 -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_41 , V_12 ,
F_10 ( V_87 , V_86 ) ) ;
}
F_32 ( V_82 ) ;
V_15 -> V_53 . V_61 = V_115 ;
F_31 ( args -> V_67 , V_15 , V_45 | V_58 ) ;
}
