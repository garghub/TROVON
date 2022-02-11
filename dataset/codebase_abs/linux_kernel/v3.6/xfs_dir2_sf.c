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
struct V_36 * V_37 ,
int V_25 ,
T_5 * V_16 )
{
T_4 * V_2 ;
T_8 * V_19 ;
T_9 * V_21 ;
T_3 * V_15 ;
T_12 * V_38 ;
char * V_39 ;
int error ;
int V_40 ;
T_10 * V_24 ;
char * V_41 ;
T_13 * V_12 ;
T_5 * V_42 ;
F_21 ( args ) ;
V_15 = args -> V_15 ;
V_24 = V_15 -> V_26 ;
V_2 = F_22 ( V_24 -> V_43 , V_44 ) ;
memcpy ( V_2 , V_37 -> V_45 , V_24 -> V_43 ) ;
V_40 = V_46 ;
if ( ( error = F_23 ( args , V_24 -> V_47 , V_37 ) ) ) {
ASSERT ( error != V_48 ) ;
goto V_49;
}
V_15 -> V_50 . V_51 &= ~ V_52 ;
V_15 -> V_50 . V_51 |= V_53 ;
V_15 -> V_54 . V_55 = V_56 ;
ASSERT ( V_15 -> V_50 . V_57 == 0 ) ;
F_24 ( V_15 , V_25 , V_58 ) ;
V_40 |= V_59 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
memcpy ( V_42 , V_16 , F_18 ( V_16 -> V_4 ) ) ;
V_15 -> V_54 . V_62 = V_25 ;
V_19 = F_13 ( V_24 , V_2 ) ;
V_41 = ( char * ) ( V_2 + 1 ) ;
V_39 = ( char * ) F_14 ( V_19 ) ;
V_12 = F_25 ( V_42 ) ;
while ( V_41 < V_39 ) {
V_38 = ( T_12 * ) V_41 ;
if ( F_26 ( V_38 -> V_63 ) == V_64 ) {
V_41 += F_26 ( V_38 -> V_65 ) ;
continue;
}
V_21 = ( T_9 * ) V_41 ;
if ( V_21 -> V_14 == 1 && V_21 -> V_13 [ 0 ] == '.' )
ASSERT ( F_17 ( V_21 -> V_30 ) == V_15 -> V_66 ) ;
else if ( V_21 -> V_14 == 2 &&
V_21 -> V_13 [ 0 ] == '.' && V_21 -> V_13 [ 1 ] == '.' )
ASSERT ( F_17 ( V_21 -> V_30 ) ==
F_7 ( V_42 ) ) ;
else {
V_12 -> V_14 = V_21 -> V_14 ;
F_27 ( V_12 ,
( V_67 )
( ( char * ) V_21 - ( char * ) V_2 ) ) ;
memcpy ( V_12 -> V_13 , V_21 -> V_13 , V_21 -> V_14 ) ;
F_11 ( V_42 , V_12 ,
F_17 ( V_21 -> V_30 ) ) ;
V_12 = F_28 ( V_42 , V_12 ) ;
}
V_41 += F_29 ( V_21 -> V_14 ) ;
}
ASSERT ( ( char * ) V_12 - ( char * ) V_42 == V_25 ) ;
F_30 ( args ) ;
V_49:
F_31 ( args -> V_68 , V_15 , V_40 ) ;
F_32 ( V_2 ) ;
return error ;
}
int
F_33 (
T_11 * args )
{
int V_69 ;
T_3 * V_15 ;
int error ;
int V_70 ;
int V_71 ;
int V_72 ;
V_67 V_73 = 0 ;
int V_74 ;
int V_75 ;
T_5 * V_42 ;
T_13 * V_12 = NULL ;
F_34 ( args ) ;
ASSERT ( F_35 ( args ) == V_76 ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_50 . V_51 & V_53 ) ;
if ( V_15 -> V_54 . V_62 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_77 ) ;
}
ASSERT ( V_15 -> V_50 . V_57 == V_15 -> V_54 . V_62 ) ;
ASSERT ( V_15 -> V_50 . V_60 . V_61 != NULL ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
ASSERT ( V_15 -> V_54 . V_62 >= F_18 ( V_42 -> V_4 ) ) ;
V_69 = F_39 ( V_42 , args -> V_14 ) ;
V_70 = V_69 ;
V_72 = 0 ;
#if V_29
if ( args -> V_30 > V_31 && V_42 -> V_4 == 0 ) {
V_69 +=
( V_32 ) sizeof( V_34 ) -
( V_32 ) sizeof( V_35 ) ;
V_70 +=
( V_42 -> V_20 + 2 ) *
( ( V_32 ) sizeof( V_34 ) -
( V_32 ) sizeof( V_35 ) ) ;
V_72 = 1 ;
}
#endif
V_74 = ( int ) V_15 -> V_54 . V_62 ;
V_71 = V_74 + V_70 ;
if ( V_71 > F_19 ( V_15 ) ||
( V_75 =
F_40 ( args , V_72 , & V_12 , & V_73 ) ) == 0 ) {
if ( ( args -> V_78 & V_79 ) || args -> V_80 == 0 )
return F_38 ( V_48 ) ;
error = F_41 ( args ) ;
if ( error )
return error ;
return F_42 ( args ) ;
}
if ( args -> V_78 & V_79 )
return 0 ;
if ( V_75 == 1 )
F_43 ( args , V_12 , V_73 , V_71 ) ;
else {
ASSERT ( V_75 == 2 ) ;
#if V_29
if ( V_72 )
F_44 ( args ) ;
#endif
F_45 ( args , V_72 , V_71 ) ;
}
F_31 ( args -> V_68 , V_15 , V_46 | V_59 ) ;
return 0 ;
}
static void
F_43 (
T_11 * args ,
T_13 * V_12 ,
V_67 V_73 ,
int V_71 )
{
int V_81 ;
T_3 * V_15 ;
T_5 * V_42 ;
V_15 = args -> V_15 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_81 = ( int ) ( ( char * ) V_12 - ( char * ) V_42 ) ;
F_24 ( V_15 , F_39 ( V_42 , args -> V_14 ) ,
V_58 ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_12 = ( T_13 * ) ( ( char * ) V_42 + V_81 ) ;
V_12 -> V_14 = args -> V_14 ;
F_27 ( V_12 , V_73 ) ;
memcpy ( V_12 -> V_13 , args -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_42 , V_12 , args -> V_30 ) ;
V_42 -> V_20 ++ ;
#if V_29
if ( args -> V_30 > V_31 )
V_42 -> V_4 ++ ;
#endif
V_15 -> V_54 . V_62 = V_71 ;
F_30 ( args ) ;
}
static void
F_45 (
T_11 * args ,
int V_72 ,
int V_71 )
{
int V_82 ;
char * V_83 ;
T_3 * V_15 ;
int V_84 ;
int V_85 ;
V_67 V_86 ;
V_67 V_73 ;
int V_74 ;
T_13 * V_87 ;
T_5 * V_88 ;
T_13 * V_12 ;
T_5 * V_42 ;
V_15 = args -> V_15 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_74 = ( int ) V_15 -> V_54 . V_62 ;
V_83 = F_22 ( V_74 , V_44 ) ;
V_88 = ( T_5 * ) V_83 ;
memcpy ( V_88 , V_42 , V_74 ) ;
for ( V_73 = V_89 ,
V_87 = F_25 ( V_88 ) ,
V_82 = F_29 ( args -> V_14 ) ,
V_84 = ( char * ) V_87 == & V_83 [ V_74 ] ;
! V_84 ;
V_73 = V_86 + F_29 ( V_87 -> V_14 ) ,
V_87 = F_28 ( V_88 , V_87 ) ,
V_84 = ( char * ) V_87 == & V_83 [ V_74 ] ) {
V_86 = F_46 ( V_87 ) ;
if ( V_73 + V_82 <= V_86 )
break;
}
F_24 ( V_15 , - V_74 , V_58 ) ;
F_24 ( V_15 , V_71 , V_58 ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_85 = ( int ) ( ( char * ) V_87 - ( char * ) V_88 ) ;
memcpy ( V_42 , V_88 , V_85 ) ;
V_12 = ( T_13 * ) ( ( char * ) V_42 + V_85 ) ;
V_12 -> V_14 = args -> V_14 ;
F_27 ( V_12 , V_73 ) ;
memcpy ( V_12 -> V_13 , args -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_42 , V_12 , args -> V_30 ) ;
V_42 -> V_20 ++ ;
#if V_29
if ( args -> V_30 > V_31 && ! V_72 )
V_42 -> V_4 ++ ;
#endif
if ( ! V_84 ) {
V_12 = F_28 ( V_42 , V_12 ) ;
memcpy ( V_12 , V_87 , V_74 - V_85 ) ;
}
F_32 ( V_83 ) ;
V_15 -> V_54 . V_62 = V_71 ;
F_30 ( args ) ;
}
static int
F_40 (
T_11 * args ,
int V_72 ,
T_13 * * V_90 ,
V_67 * V_91 )
{
T_3 * V_15 ;
int V_92 ;
int V_6 ;
T_10 * V_24 ;
V_67 V_73 ;
T_13 * V_12 ;
T_5 * V_42 ;
int V_25 ;
int V_93 ;
V_15 = args -> V_15 ;
V_24 = V_15 -> V_26 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_25 = F_29 ( args -> V_14 ) ;
V_73 = V_89 ;
V_12 = F_25 ( V_42 ) ;
V_92 = 0 ;
for ( V_6 = 0 ; V_6 < V_42 -> V_20 ; V_6 ++ ) {
if ( ! V_92 )
V_92 = V_73 + V_25 <= F_46 ( V_12 ) ;
V_73 = F_46 ( V_12 ) +
F_29 ( V_12 -> V_14 ) ;
V_12 = F_28 ( V_42 , V_12 ) ;
}
V_93 = V_73 +
( V_42 -> V_20 + 3 ) * ( V_32 ) sizeof( T_7 ) +
( V_32 ) sizeof( T_8 ) ;
if ( V_93 + ( V_92 ? 0 : V_25 ) > V_24 -> V_43 )
return 0 ;
#if V_29
if ( V_72 ) {
return 2 ;
}
#else
ASSERT ( V_72 == 0 ) ;
#endif
if ( V_93 + V_25 > V_24 -> V_43 )
return 2 ;
* V_90 = V_12 ;
* V_91 = V_73 ;
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
int V_73 ;
T_13 * V_12 ;
T_5 * V_42 ;
V_15 = args -> V_15 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_73 = V_89 ;
V_9 = F_7 ( V_42 ) ;
V_4 = V_9 > V_31 ;
for ( V_6 = 0 , V_12 = F_25 ( V_42 ) ;
V_6 < V_42 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_42 , V_12 ) ) {
ASSERT ( F_46 ( V_12 ) >= V_73 ) ;
V_9 = F_10 ( V_42 , V_12 ) ;
V_4 += V_9 > V_31 ;
V_73 =
F_46 ( V_12 ) +
F_29 ( V_12 -> V_14 ) ;
}
ASSERT ( V_4 == V_42 -> V_4 ) ;
ASSERT ( V_29 || V_4 == 0 ) ;
ASSERT ( ( char * ) V_12 - ( char * ) V_42 == V_15 -> V_54 . V_62 ) ;
ASSERT ( V_73 +
( V_42 -> V_20 + 2 ) * ( V_32 ) sizeof( T_7 ) +
( V_32 ) sizeof( T_8 ) <=
V_15 -> V_26 -> V_43 ) ;
}
int
F_47 (
T_11 * args ,
T_1 V_94 )
{
T_3 * V_15 ;
int V_4 ;
T_5 * V_42 ;
int V_25 ;
F_48 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 != NULL ) ;
ASSERT ( V_15 -> V_54 . V_62 == 0 ) ;
if ( V_15 -> V_54 . V_55 == V_95 ) {
V_15 -> V_50 . V_51 &= ~ V_52 ;
V_15 -> V_54 . V_55 = V_56 ;
F_31 ( args -> V_68 , V_15 , V_46 ) ;
V_15 -> V_50 . V_51 |= V_53 ;
}
ASSERT ( V_15 -> V_50 . V_51 & V_53 ) ;
ASSERT ( V_15 -> V_50 . V_57 == 0 ) ;
V_4 = V_94 > V_31 ;
V_25 = F_18 ( V_4 ) ;
F_24 ( V_15 , V_25 , V_58 ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_42 -> V_4 = V_4 ;
F_8 ( V_42 , V_94 ) ;
V_42 -> V_20 = 0 ;
V_15 -> V_54 . V_62 = V_25 ;
F_30 ( args ) ;
F_31 ( args -> V_68 , V_15 , V_46 | V_59 ) ;
return 0 ;
}
int
F_49 (
T_3 * V_15 ,
void * V_96 ,
T_14 * V_73 ,
T_15 V_97 )
{
int V_6 ;
T_10 * V_24 ;
T_6 V_98 ;
T_13 * V_12 ;
T_5 * V_42 ;
T_6 V_99 ;
T_6 V_100 ;
T_1 V_9 ;
V_24 = V_15 -> V_26 ;
ASSERT ( V_15 -> V_50 . V_51 & V_53 ) ;
if ( V_15 -> V_54 . V_62 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_24 ) ) ;
return F_38 ( V_77 ) ;
}
ASSERT ( V_15 -> V_50 . V_57 == V_15 -> V_54 . V_62 ) ;
ASSERT ( V_15 -> V_50 . V_60 . V_61 != NULL ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
ASSERT ( V_15 -> V_54 . V_62 >= F_18 ( V_42 -> V_4 ) ) ;
if ( F_50 ( V_24 , * V_73 ) > V_24 -> V_47 )
return 0 ;
V_99 = F_51 ( V_24 , V_24 -> V_47 ,
V_101 ) ;
V_100 = F_51 ( V_24 , V_24 -> V_47 ,
V_102 ) ;
if ( * V_73 <= V_99 ) {
if ( V_97 ( V_96 , L_1 , 1 , V_99 & 0x7fffffff , V_15 -> V_66 , V_103 ) ) {
* V_73 = V_99 & 0x7fffffff ;
return 0 ;
}
}
if ( * V_73 <= V_100 ) {
V_9 = F_7 ( V_42 ) ;
if ( V_97 ( V_96 , L_2 , 2 , V_100 & 0x7fffffff , V_9 , V_103 ) ) {
* V_73 = V_100 & 0x7fffffff ;
return 0 ;
}
}
V_12 = F_25 ( V_42 ) ;
for ( V_6 = 0 ; V_6 < V_42 -> V_20 ; V_6 ++ ) {
V_98 = F_51 ( V_24 , V_24 -> V_47 ,
F_46 ( V_12 ) ) ;
if ( * V_73 > V_98 ) {
V_12 = F_28 ( V_42 , V_12 ) ;
continue;
}
V_9 = F_10 ( V_42 , V_12 ) ;
if ( V_97 ( V_96 , ( char * ) V_12 -> V_13 , V_12 -> V_14 ,
V_98 & 0x7fffffff , V_9 , V_104 ) ) {
* V_73 = V_98 & 0x7fffffff ;
return 0 ;
}
V_12 = F_28 ( V_42 , V_12 ) ;
}
* V_73 = F_51 ( V_24 , V_24 -> V_47 + 1 , 0 ) &
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
T_13 * V_12 ;
T_5 * V_42 ;
enum V_105 V_106 ;
T_13 * V_107 ;
F_52 ( args ) ;
F_30 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_50 . V_51 & V_53 ) ;
if ( V_15 -> V_54 . V_62 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_77 ) ;
}
ASSERT ( V_15 -> V_50 . V_57 == V_15 -> V_54 . V_62 ) ;
ASSERT ( V_15 -> V_50 . V_60 . V_61 != NULL ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
ASSERT ( V_15 -> V_54 . V_62 >= F_18 ( V_42 -> V_4 ) ) ;
if ( args -> V_14 == 1 && args -> V_13 [ 0 ] == '.' ) {
args -> V_30 = V_15 -> V_66 ;
args -> V_108 = V_109 ;
return F_38 ( V_110 ) ;
}
if ( args -> V_14 == 2 &&
args -> V_13 [ 0 ] == '.' && args -> V_13 [ 1 ] == '.' ) {
args -> V_30 = F_7 ( V_42 ) ;
args -> V_108 = V_109 ;
return F_38 ( V_110 ) ;
}
V_107 = NULL ;
for ( V_6 = 0 , V_12 = F_25 ( V_42 ) ; V_6 < V_42 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_42 , V_12 ) ) {
V_106 = V_15 -> V_26 -> V_111 -> V_112 ( args , V_12 -> V_13 ,
V_12 -> V_14 ) ;
if ( V_106 != V_113 && V_106 != args -> V_108 ) {
args -> V_108 = V_106 ;
args -> V_30 = F_10 ( V_42 , V_12 ) ;
if ( V_106 == V_109 )
return F_38 ( V_110 ) ;
V_107 = V_12 ;
}
}
ASSERT ( args -> V_78 & V_114 ) ;
if ( ! V_107 )
return F_38 ( V_76 ) ;
error = F_53 ( args , V_107 -> V_13 , V_107 -> V_14 ) ;
return F_38 ( error ) ;
}
int
F_54 (
T_11 * args )
{
int V_81 ;
T_3 * V_15 ;
int V_115 ;
int V_6 ;
int V_116 ;
int V_117 ;
T_13 * V_12 ;
T_5 * V_42 ;
F_55 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_50 . V_51 & V_53 ) ;
V_117 = ( int ) V_15 -> V_54 . V_62 ;
if ( V_117 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_77 ) ;
}
ASSERT ( V_15 -> V_50 . V_57 == V_117 ) ;
ASSERT ( V_15 -> V_50 . V_60 . V_61 != NULL ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
ASSERT ( V_117 >= F_18 ( V_42 -> V_4 ) ) ;
for ( V_6 = 0 , V_12 = F_25 ( V_42 ) ; V_6 < V_42 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_42 , V_12 ) ) {
if ( F_56 ( args , V_12 -> V_13 , V_12 -> V_14 ) ==
V_109 ) {
ASSERT ( F_10 ( V_42 , V_12 ) ==
args -> V_30 ) ;
break;
}
}
if ( V_6 == V_42 -> V_20 )
return F_38 ( V_76 ) ;
V_81 = ( int ) ( ( char * ) V_12 - ( char * ) V_42 ) ;
V_115 = F_39 ( V_42 , args -> V_14 ) ;
V_116 = V_117 - V_115 ;
if ( V_81 + V_115 < V_117 )
memmove ( ( char * ) V_42 + V_81 , ( char * ) V_42 + V_81 + V_115 ,
V_117 - ( V_81 + V_115 ) ) ;
V_42 -> V_20 -- ;
V_15 -> V_54 . V_62 = V_116 ;
F_24 ( V_15 , V_116 - V_117 , V_58 ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
#if V_29
if ( args -> V_30 > V_31 ) {
if ( V_42 -> V_4 == 1 )
F_57 ( args ) ;
else
V_42 -> V_4 -- ;
}
#endif
F_30 ( args ) ;
F_31 ( args -> V_68 , V_15 , V_46 | V_59 ) ;
return 0 ;
}
int
F_58 (
T_11 * args )
{
T_3 * V_15 ;
int V_6 ;
#if V_29 || F_59 ( V_118 )
T_1 V_9 = 0 ;
#endif
#if V_29
int V_119 ;
#endif
T_13 * V_12 ;
T_5 * V_42 ;
F_60 ( args ) ;
V_15 = args -> V_15 ;
ASSERT ( V_15 -> V_50 . V_51 & V_53 ) ;
if ( V_15 -> V_54 . V_62 < F_36 ( T_5 , V_10 ) ) {
ASSERT ( F_37 ( V_15 -> V_26 ) ) ;
return F_38 ( V_77 ) ;
}
ASSERT ( V_15 -> V_50 . V_57 == V_15 -> V_54 . V_62 ) ;
ASSERT ( V_15 -> V_50 . V_60 . V_61 != NULL ) ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
ASSERT ( V_15 -> V_54 . V_62 >= F_18 ( V_42 -> V_4 ) ) ;
#if V_29
if ( args -> V_30 > V_31 && V_42 -> V_4 == 0 ) {
int error ;
int V_116 ;
V_116 =
V_15 -> V_50 . V_57 +
( V_42 -> V_20 + 1 ) *
( ( V_32 ) sizeof( V_34 ) -
( V_32 ) sizeof( V_35 ) ) ;
if ( V_116 > F_19 ( V_15 ) ) {
error = F_41 ( args ) ;
if ( error ) {
return error ;
}
return F_61 ( args ) ;
}
F_44 ( args ) ;
V_119 = 1 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
} else
V_119 = 0 ;
#endif
ASSERT ( args -> V_14 != 1 || args -> V_13 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_13 [ 0 ] == '.' && args -> V_13 [ 1 ] == '.' ) {
#if V_29 || F_59 ( V_118 )
V_9 = F_7 ( V_42 ) ;
ASSERT ( args -> V_30 != V_9 ) ;
#endif
F_8 ( V_42 , args -> V_30 ) ;
}
else {
for ( V_6 = 0 , V_12 = F_25 ( V_42 ) ;
V_6 < V_42 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_42 , V_12 ) ) {
if ( F_56 ( args , V_12 -> V_13 , V_12 -> V_14 ) ==
V_109 ) {
#if V_29 || F_59 ( V_118 )
V_9 = F_10 ( V_42 , V_12 ) ;
ASSERT ( args -> V_30 != V_9 ) ;
#endif
F_11 ( V_42 , V_12 , args -> V_30 ) ;
break;
}
}
if ( V_6 == V_42 -> V_20 ) {
ASSERT ( args -> V_78 & V_114 ) ;
#if V_29
if ( V_119 )
F_57 ( args ) ;
#endif
return F_38 ( V_76 ) ;
}
}
#if V_29
if ( V_9 > V_31 &&
args -> V_30 <= V_31 ) {
if ( V_42 -> V_4 == 1 )
F_57 ( args ) ;
else
V_42 -> V_4 -- ;
}
if ( V_9 <= V_31 &&
args -> V_30 > V_31 ) {
ASSERT ( V_42 -> V_4 != 0 ) ;
if ( ! V_119 )
V_42 -> V_4 ++ ;
}
#endif
F_30 ( args ) ;
F_31 ( args -> V_68 , V_15 , V_59 ) ;
return 0 ;
}
static void
F_57 (
T_11 * args )
{
char * V_83 ;
T_3 * V_15 ;
int V_6 ;
int V_116 ;
T_13 * V_87 ;
T_5 * V_88 ;
int V_117 ;
T_13 * V_12 ;
T_5 * V_42 ;
F_62 ( args ) ;
V_15 = args -> V_15 ;
V_117 = V_15 -> V_50 . V_57 ;
V_83 = F_22 ( V_117 , V_44 ) ;
V_88 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
ASSERT ( V_88 -> V_4 == 1 ) ;
memcpy ( V_83 , V_88 , V_117 ) ;
V_116 =
V_117 -
( V_88 -> V_20 + 1 ) *
( ( V_32 ) sizeof( V_34 ) - ( V_32 ) sizeof( V_35 ) ) ;
F_24 ( V_15 , - V_117 , V_58 ) ;
F_24 ( V_15 , V_116 , V_58 ) ;
V_88 = ( T_5 * ) V_83 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_42 -> V_20 = V_88 -> V_20 ;
V_42 -> V_4 = 0 ;
F_8 ( V_42 , F_7 ( V_88 ) ) ;
for ( V_6 = 0 , V_12 = F_25 ( V_42 ) ,
V_87 = F_25 ( V_88 ) ;
V_6 < V_42 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_42 , V_12 ) ,
V_87 = F_28 ( V_88 , V_87 ) ) {
V_12 -> V_14 = V_87 -> V_14 ;
V_12 -> V_73 = V_87 -> V_73 ;
memcpy ( V_12 -> V_13 , V_87 -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_42 , V_12 ,
F_10 ( V_88 , V_87 ) ) ;
}
F_32 ( V_83 ) ;
V_15 -> V_54 . V_62 = V_116 ;
F_31 ( args -> V_68 , V_15 , V_46 | V_59 ) ;
}
static void
F_44 (
T_11 * args )
{
char * V_83 ;
T_3 * V_15 ;
int V_6 ;
int V_116 ;
T_13 * V_87 ;
T_5 * V_88 ;
int V_117 ;
T_13 * V_12 ;
T_5 * V_42 ;
F_63 ( args ) ;
V_15 = args -> V_15 ;
V_117 = V_15 -> V_50 . V_57 ;
V_83 = F_22 ( V_117 , V_44 ) ;
V_88 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
ASSERT ( V_88 -> V_4 == 0 ) ;
memcpy ( V_83 , V_88 , V_117 ) ;
V_116 =
V_117 +
( V_88 -> V_20 + 1 ) *
( ( V_32 ) sizeof( V_34 ) - ( V_32 ) sizeof( V_35 ) ) ;
F_24 ( V_15 , - V_117 , V_58 ) ;
F_24 ( V_15 , V_116 , V_58 ) ;
V_88 = ( T_5 * ) V_83 ;
V_42 = ( T_5 * ) V_15 -> V_50 . V_60 . V_61 ;
V_42 -> V_20 = V_88 -> V_20 ;
V_42 -> V_4 = 1 ;
F_8 ( V_42 , F_7 ( V_88 ) ) ;
for ( V_6 = 0 , V_12 = F_25 ( V_42 ) ,
V_87 = F_25 ( V_88 ) ;
V_6 < V_42 -> V_20 ;
V_6 ++ , V_12 = F_28 ( V_42 , V_12 ) ,
V_87 = F_28 ( V_88 , V_87 ) ) {
V_12 -> V_14 = V_87 -> V_14 ;
V_12 -> V_73 = V_87 -> V_73 ;
memcpy ( V_12 -> V_13 , V_87 -> V_13 , V_12 -> V_14 ) ;
F_11 ( V_42 , V_12 ,
F_10 ( V_88 , V_87 ) ) ;
}
F_32 ( V_83 ) ;
V_15 -> V_54 . V_62 = V_116 ;
F_31 ( args -> V_68 , V_15 , V_46 | V_59 ) ;
}
