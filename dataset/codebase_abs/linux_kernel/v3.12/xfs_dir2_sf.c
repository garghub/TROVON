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
void
F_8 (
struct V_1 * V_2 ,
T_1 V_9 )
{
F_4 ( V_2 , & V_2 -> V_10 , V_9 ) ;
}
static T_2 *
F_9 (
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
T_3 * V_15 = & V_14 -> V_16 [ V_14 -> V_17 ] ;
if ( F_10 ( & V_12 -> V_18 ) )
V_15 ++ ;
return ( T_2 * ) V_15 ;
}
T_1
F_11 (
struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
return F_1 ( V_2 , F_9 ( V_12 , V_14 ) ) ;
}
void
F_12 (
struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_1 V_9 )
{
F_4 ( V_2 , F_9 ( V_12 , V_14 ) , V_9 ) ;
}
int
F_13 (
T_4 * V_19 ,
T_5 * V_2 ,
T_6 * V_20 )
{
T_7 V_21 ;
T_8 * V_22 ;
T_9 * V_23 ;
int V_24 ;
T_10 * V_25 ;
int V_6 ;
int V_4 ;
int V_26 ;
int V_27 ;
T_11 * V_12 ;
int V_17 ;
T_1 V_10 = 0 ;
int V_28 = 0 ;
int V_29 ;
V_12 = V_19 -> V_30 ;
V_29 = F_10 ( & V_12 -> V_18 ) ? 1 : 0 ;
V_24 = V_4 = V_17 = 0 ;
V_23 = F_14 ( V_12 , V_2 ) ;
V_22 = F_15 ( V_23 ) ;
for ( V_6 = 0 ; V_6 < F_16 ( V_23 -> V_24 ) ; V_6 ++ ) {
if ( ( V_21 = F_16 ( V_22 [ V_6 ] . V_31 ) ) == V_32 )
continue;
V_25 = ( T_10 * )
( ( char * ) V_2 + F_17 ( V_12 , V_21 ) ) ;
V_26 = V_25 -> V_17 == 1 && V_25 -> V_16 [ 0 ] == '.' ;
V_27 =
V_25 -> V_17 == 2 &&
V_25 -> V_16 [ 0 ] == '.' && V_25 -> V_16 [ 1 ] == '.' ;
#if V_33
if ( ! V_26 )
V_4 += F_18 ( V_25 -> V_34 ) > V_35 ;
#endif
if ( ! V_26 && ! V_27 ) {
V_24 ++ ;
V_17 += V_25 -> V_17 + V_29 ;
} else if ( V_27 )
V_10 = F_18 ( V_25 -> V_34 ) ;
V_28 = F_19 ( V_4 ) +
V_24 +
V_24 * ( V_36 ) sizeof( V_37 ) +
V_17 +
( V_4 ?
( V_36 ) sizeof( V_38 ) * V_24 :
( V_36 ) sizeof( V_39 ) * V_24 ) ;
if ( V_28 > F_20 ( V_19 ) )
return V_28 ;
}
V_20 -> V_24 = V_24 ;
V_20 -> V_4 = V_4 ;
F_8 ( V_20 , V_10 ) ;
return V_28 ;
}
int
F_21 (
T_12 * args ,
struct V_40 * V_41 ,
int V_28 ,
T_6 * V_20 )
{
T_5 * V_2 ;
T_9 * V_23 ;
T_10 * V_25 ;
T_4 * V_19 ;
T_13 * V_42 ;
char * V_43 ;
int error ;
int V_44 ;
T_11 * V_12 ;
char * V_15 ;
T_14 * V_14 ;
T_6 * V_45 ;
F_22 ( args ) ;
V_19 = args -> V_19 ;
V_12 = V_19 -> V_30 ;
V_2 = F_23 ( V_12 -> V_46 , V_47 ) ;
memcpy ( V_2 , V_41 -> V_48 , V_12 -> V_46 ) ;
V_44 = V_49 ;
if ( ( error = F_24 ( args , V_12 -> V_50 , V_41 ) ) ) {
ASSERT ( error != V_51 ) ;
goto V_52;
}
V_19 -> V_53 . V_54 &= ~ V_55 ;
V_19 -> V_53 . V_54 |= V_56 ;
V_19 -> V_57 . V_58 = V_59 ;
ASSERT ( V_19 -> V_53 . V_60 == 0 ) ;
F_25 ( V_19 , V_28 , V_61 ) ;
V_44 |= V_62 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
memcpy ( V_45 , V_20 , F_19 ( V_20 -> V_4 ) ) ;
V_19 -> V_57 . V_65 = V_28 ;
V_23 = F_14 ( V_12 , V_2 ) ;
V_15 = ( char * ) F_26 ( V_2 ) ;
V_43 = ( char * ) F_15 ( V_23 ) ;
V_14 = F_27 ( V_45 ) ;
while ( V_15 < V_43 ) {
V_42 = ( T_13 * ) V_15 ;
if ( F_28 ( V_42 -> V_66 ) == V_67 ) {
V_15 += F_28 ( V_42 -> V_68 ) ;
continue;
}
V_25 = ( T_10 * ) V_15 ;
if ( V_25 -> V_17 == 1 && V_25 -> V_16 [ 0 ] == '.' )
ASSERT ( F_18 ( V_25 -> V_34 ) == V_19 -> V_69 ) ;
else if ( V_25 -> V_17 == 2 &&
V_25 -> V_16 [ 0 ] == '.' && V_25 -> V_16 [ 1 ] == '.' )
ASSERT ( F_18 ( V_25 -> V_34 ) ==
F_7 ( V_45 ) ) ;
else {
V_14 -> V_17 = V_25 -> V_17 ;
F_29 ( V_14 ,
( V_70 )
( ( char * ) V_25 - ( char * ) V_2 ) ) ;
memcpy ( V_14 -> V_16 , V_25 -> V_16 , V_25 -> V_17 ) ;
F_12 ( V_12 , V_45 , V_14 ,
F_18 ( V_25 -> V_34 ) ) ;
F_30 ( V_12 , V_45 , V_14 ,
F_31 ( V_12 , V_25 ) ) ;
V_14 = F_32 ( V_12 , V_45 , V_14 ) ;
}
V_15 += F_33 ( V_12 , V_25 -> V_17 ) ;
}
ASSERT ( ( char * ) V_14 - ( char * ) V_45 == V_28 ) ;
F_34 ( args ) ;
V_52:
F_35 ( args -> V_71 , V_19 , V_44 ) ;
F_36 ( V_2 ) ;
return error ;
}
int
F_37 (
T_12 * args )
{
int V_72 ;
T_4 * V_19 ;
int error ;
int V_73 ;
int V_74 ;
int V_75 ;
V_70 V_76 = 0 ;
int V_77 ;
int V_78 ;
T_6 * V_45 ;
T_14 * V_14 = NULL ;
F_38 ( args ) ;
ASSERT ( F_39 ( args ) == V_79 ) ;
V_19 = args -> V_19 ;
ASSERT ( V_19 -> V_53 . V_54 & V_56 ) ;
if ( V_19 -> V_57 . V_65 < F_40 ( T_6 , V_10 ) ) {
ASSERT ( F_41 ( V_19 -> V_30 ) ) ;
return F_42 ( V_80 ) ;
}
ASSERT ( V_19 -> V_53 . V_60 == V_19 -> V_57 . V_65 ) ;
ASSERT ( V_19 -> V_53 . V_63 . V_64 != NULL ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
ASSERT ( V_19 -> V_57 . V_65 >= F_19 ( V_45 -> V_4 ) ) ;
V_72 = F_43 ( V_19 -> V_30 , V_45 , args -> V_17 ) ;
V_73 = V_72 ;
V_75 = 0 ;
#if V_33
if ( args -> V_34 > V_35 && V_45 -> V_4 == 0 ) {
V_72 +=
( V_36 ) sizeof( V_38 ) -
( V_36 ) sizeof( V_39 ) ;
V_73 +=
( V_45 -> V_24 + 2 ) *
( ( V_36 ) sizeof( V_38 ) -
( V_36 ) sizeof( V_39 ) ) ;
V_75 = 1 ;
}
#endif
V_77 = ( int ) V_19 -> V_57 . V_65 ;
V_74 = V_77 + V_73 ;
if ( V_74 > F_20 ( V_19 ) ||
( V_78 =
F_44 ( args , V_75 , & V_14 , & V_76 ) ) == 0 ) {
if ( ( args -> V_81 & V_82 ) || args -> V_83 == 0 )
return F_42 ( V_51 ) ;
error = F_45 ( args ) ;
if ( error )
return error ;
return F_46 ( args ) ;
}
if ( args -> V_81 & V_82 )
return 0 ;
if ( V_78 == 1 )
F_47 ( args , V_14 , V_76 , V_74 ) ;
else {
ASSERT ( V_78 == 2 ) ;
#if V_33
if ( V_75 )
F_48 ( args ) ;
#endif
F_49 ( args , V_75 , V_74 ) ;
}
F_35 ( args -> V_71 , V_19 , V_49 | V_62 ) ;
return 0 ;
}
static void
F_47 (
T_12 * args ,
T_14 * V_14 ,
V_70 V_76 ,
int V_74 )
{
int V_84 ;
T_4 * V_19 ;
T_6 * V_45 ;
V_19 = args -> V_19 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_84 = ( int ) ( ( char * ) V_14 - ( char * ) V_45 ) ;
F_25 ( V_19 ,
F_43 ( V_19 -> V_30 , V_45 , args -> V_17 ) ,
V_61 ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_14 = ( T_14 * ) ( ( char * ) V_45 + V_84 ) ;
V_14 -> V_17 = args -> V_17 ;
F_29 ( V_14 , V_76 ) ;
memcpy ( V_14 -> V_16 , args -> V_16 , V_14 -> V_17 ) ;
F_12 ( V_19 -> V_30 , V_45 , V_14 , args -> V_34 ) ;
F_30 ( V_19 -> V_30 , V_45 , V_14 , args -> V_85 ) ;
V_45 -> V_24 ++ ;
#if V_33
if ( args -> V_34 > V_35 )
V_45 -> V_4 ++ ;
#endif
V_19 -> V_57 . V_65 = V_74 ;
F_34 ( args ) ;
}
static void
F_49 (
T_12 * args ,
int V_75 ,
int V_74 )
{
int V_86 ;
char * V_87 ;
T_4 * V_19 ;
int V_88 ;
int V_89 ;
V_70 V_90 ;
V_70 V_76 ;
int V_77 ;
T_14 * V_91 ;
T_6 * V_92 ;
T_14 * V_14 ;
T_6 * V_45 ;
struct V_11 * V_12 ;
V_19 = args -> V_19 ;
V_12 = V_19 -> V_30 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_77 = ( int ) V_19 -> V_57 . V_65 ;
V_87 = F_23 ( V_77 , V_47 ) ;
V_92 = ( T_6 * ) V_87 ;
memcpy ( V_92 , V_45 , V_77 ) ;
for ( V_76 = F_50 ( V_12 ) ,
V_91 = F_27 ( V_92 ) ,
V_86 = F_33 ( V_12 , args -> V_17 ) ,
V_88 = ( char * ) V_91 == & V_87 [ V_77 ] ;
! V_88 ;
V_76 = V_90 + F_33 ( V_12 , V_91 -> V_17 ) ,
V_91 = F_32 ( V_12 , V_92 , V_91 ) ,
V_88 = ( char * ) V_91 == & V_87 [ V_77 ] ) {
V_90 = F_51 ( V_91 ) ;
if ( V_76 + V_86 <= V_90 )
break;
}
F_25 ( V_19 , - V_77 , V_61 ) ;
F_25 ( V_19 , V_74 , V_61 ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_89 = ( int ) ( ( char * ) V_91 - ( char * ) V_92 ) ;
memcpy ( V_45 , V_92 , V_89 ) ;
V_14 = ( T_14 * ) ( ( char * ) V_45 + V_89 ) ;
V_14 -> V_17 = args -> V_17 ;
F_29 ( V_14 , V_76 ) ;
memcpy ( V_14 -> V_16 , args -> V_16 , V_14 -> V_17 ) ;
F_12 ( V_12 , V_45 , V_14 , args -> V_34 ) ;
F_30 ( V_12 , V_45 , V_14 , args -> V_85 ) ;
V_45 -> V_24 ++ ;
#if V_33
if ( args -> V_34 > V_35 && ! V_75 )
V_45 -> V_4 ++ ;
#endif
if ( ! V_88 ) {
V_14 = F_32 ( V_12 , V_45 , V_14 ) ;
memcpy ( V_14 , V_91 , V_77 - V_89 ) ;
}
F_36 ( V_87 ) ;
V_19 -> V_57 . V_65 = V_74 ;
F_34 ( args ) ;
}
static int
F_44 (
T_12 * args ,
int V_75 ,
T_14 * * V_93 ,
V_70 * V_94 )
{
T_4 * V_19 ;
int V_95 ;
int V_6 ;
T_11 * V_12 ;
V_70 V_76 ;
T_14 * V_14 ;
T_6 * V_45 ;
int V_28 ;
int V_96 ;
V_19 = args -> V_19 ;
V_12 = V_19 -> V_30 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_28 = F_33 ( V_12 , args -> V_17 ) ;
V_76 = F_50 ( V_12 ) ;
V_14 = F_27 ( V_45 ) ;
V_95 = 0 ;
for ( V_6 = 0 ; V_6 < V_45 -> V_24 ; V_6 ++ ) {
if ( ! V_95 )
V_95 = V_76 + V_28 <= F_51 ( V_14 ) ;
V_76 = F_51 ( V_14 ) +
F_33 ( V_12 , V_14 -> V_17 ) ;
V_14 = F_32 ( V_12 , V_45 , V_14 ) ;
}
V_96 = V_76 +
( V_45 -> V_24 + 3 ) * ( V_36 ) sizeof( T_8 ) +
( V_36 ) sizeof( T_9 ) ;
if ( V_96 + ( V_95 ? 0 : V_28 ) > V_12 -> V_46 )
return 0 ;
#if V_33
if ( V_75 ) {
return 2 ;
}
#else
ASSERT ( V_75 == 0 ) ;
#endif
if ( V_96 + V_28 > V_12 -> V_46 )
return 2 ;
* V_93 = V_14 ;
* V_94 = V_76 ;
return 1 ;
}
static void
F_34 (
T_12 * args )
{
T_4 * V_19 ;
int V_6 ;
int V_4 ;
T_1 V_9 ;
int V_76 ;
T_14 * V_14 ;
T_6 * V_45 ;
struct V_11 * V_12 ;
V_19 = args -> V_19 ;
V_12 = V_19 -> V_30 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_76 = F_50 ( V_12 ) ;
V_9 = F_7 ( V_45 ) ;
V_4 = V_9 > V_35 ;
for ( V_6 = 0 , V_14 = F_27 ( V_45 ) ;
V_6 < V_45 -> V_24 ;
V_6 ++ , V_14 = F_32 ( V_12 , V_45 , V_14 ) ) {
ASSERT ( F_51 ( V_14 ) >= V_76 ) ;
V_9 = F_11 ( V_12 , V_45 , V_14 ) ;
V_4 += V_9 > V_35 ;
V_76 =
F_51 ( V_14 ) +
F_33 ( V_12 , V_14 -> V_17 ) ;
ASSERT ( F_52 ( V_12 , V_45 , V_14 ) <
V_97 ) ;
}
ASSERT ( V_4 == V_45 -> V_4 ) ;
ASSERT ( V_33 || V_4 == 0 ) ;
ASSERT ( ( char * ) V_14 - ( char * ) V_45 == V_19 -> V_57 . V_65 ) ;
ASSERT ( V_76 +
( V_45 -> V_24 + 2 ) * ( V_36 ) sizeof( T_8 ) +
( V_36 ) sizeof( T_9 ) <= V_12 -> V_46 ) ;
}
int
F_53 (
T_12 * args ,
T_1 V_98 )
{
T_4 * V_19 ;
int V_4 ;
T_6 * V_45 ;
int V_28 ;
F_54 ( args ) ;
V_19 = args -> V_19 ;
ASSERT ( V_19 != NULL ) ;
ASSERT ( V_19 -> V_57 . V_65 == 0 ) ;
if ( V_19 -> V_57 . V_58 == V_99 ) {
V_19 -> V_53 . V_54 &= ~ V_55 ;
V_19 -> V_57 . V_58 = V_59 ;
F_35 ( args -> V_71 , V_19 , V_49 ) ;
V_19 -> V_53 . V_54 |= V_56 ;
}
ASSERT ( V_19 -> V_53 . V_54 & V_56 ) ;
ASSERT ( V_19 -> V_53 . V_60 == 0 ) ;
V_4 = V_98 > V_35 ;
V_28 = F_19 ( V_4 ) ;
F_25 ( V_19 , V_28 , V_61 ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_45 -> V_4 = V_4 ;
F_8 ( V_45 , V_98 ) ;
V_45 -> V_24 = 0 ;
V_19 -> V_57 . V_65 = V_28 ;
F_34 ( args ) ;
F_35 ( args -> V_71 , V_19 , V_49 | V_62 ) ;
return 0 ;
}
int
F_39 (
T_12 * args )
{
T_4 * V_19 ;
int V_6 ;
int error ;
T_14 * V_14 ;
T_6 * V_45 ;
enum V_100 V_101 ;
T_14 * V_102 ;
F_55 ( args ) ;
F_34 ( args ) ;
V_19 = args -> V_19 ;
ASSERT ( V_19 -> V_53 . V_54 & V_56 ) ;
if ( V_19 -> V_57 . V_65 < F_40 ( T_6 , V_10 ) ) {
ASSERT ( F_41 ( V_19 -> V_30 ) ) ;
return F_42 ( V_80 ) ;
}
ASSERT ( V_19 -> V_53 . V_60 == V_19 -> V_57 . V_65 ) ;
ASSERT ( V_19 -> V_53 . V_63 . V_64 != NULL ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
ASSERT ( V_19 -> V_57 . V_65 >= F_19 ( V_45 -> V_4 ) ) ;
if ( args -> V_17 == 1 && args -> V_16 [ 0 ] == '.' ) {
args -> V_34 = V_19 -> V_69 ;
args -> V_103 = V_104 ;
args -> V_85 = V_105 ;
return F_42 ( V_106 ) ;
}
if ( args -> V_17 == 2 &&
args -> V_16 [ 0 ] == '.' && args -> V_16 [ 1 ] == '.' ) {
args -> V_34 = F_7 ( V_45 ) ;
args -> V_103 = V_104 ;
args -> V_85 = V_105 ;
return F_42 ( V_106 ) ;
}
V_102 = NULL ;
for ( V_6 = 0 , V_14 = F_27 ( V_45 ) ; V_6 < V_45 -> V_24 ;
V_6 ++ , V_14 = F_32 ( V_19 -> V_30 , V_45 , V_14 ) ) {
V_101 = V_19 -> V_30 -> V_107 -> V_108 ( args , V_14 -> V_16 ,
V_14 -> V_17 ) ;
if ( V_101 != V_109 && V_101 != args -> V_103 ) {
args -> V_103 = V_101 ;
args -> V_34 = F_11 ( V_19 -> V_30 ,
V_45 , V_14 ) ;
args -> V_85 = F_52 ( V_19 -> V_30 ,
V_45 , V_14 ) ;
if ( V_101 == V_104 )
return F_42 ( V_106 ) ;
V_102 = V_14 ;
}
}
ASSERT ( args -> V_81 & V_110 ) ;
if ( ! V_102 )
return F_42 ( V_79 ) ;
error = F_56 ( args , V_102 -> V_16 , V_102 -> V_17 ) ;
return F_42 ( error ) ;
}
int
F_57 (
T_12 * args )
{
int V_84 ;
T_4 * V_19 ;
int V_111 ;
int V_6 ;
int V_112 ;
int V_113 ;
T_14 * V_14 ;
T_6 * V_45 ;
F_58 ( args ) ;
V_19 = args -> V_19 ;
ASSERT ( V_19 -> V_53 . V_54 & V_56 ) ;
V_113 = ( int ) V_19 -> V_57 . V_65 ;
if ( V_113 < F_40 ( T_6 , V_10 ) ) {
ASSERT ( F_41 ( V_19 -> V_30 ) ) ;
return F_42 ( V_80 ) ;
}
ASSERT ( V_19 -> V_53 . V_60 == V_113 ) ;
ASSERT ( V_19 -> V_53 . V_63 . V_64 != NULL ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
ASSERT ( V_113 >= F_19 ( V_45 -> V_4 ) ) ;
for ( V_6 = 0 , V_14 = F_27 ( V_45 ) ; V_6 < V_45 -> V_24 ;
V_6 ++ , V_14 = F_32 ( V_19 -> V_30 , V_45 , V_14 ) ) {
if ( F_59 ( args , V_14 -> V_16 , V_14 -> V_17 ) ==
V_104 ) {
ASSERT ( F_11 ( V_19 -> V_30 , V_45 , V_14 ) ==
args -> V_34 ) ;
break;
}
}
if ( V_6 == V_45 -> V_24 )
return F_42 ( V_79 ) ;
V_84 = ( int ) ( ( char * ) V_14 - ( char * ) V_45 ) ;
V_111 = F_43 ( V_19 -> V_30 , V_45 , args -> V_17 ) ;
V_112 = V_113 - V_111 ;
if ( V_84 + V_111 < V_113 )
memmove ( ( char * ) V_45 + V_84 , ( char * ) V_45 + V_84 + V_111 ,
V_113 - ( V_84 + V_111 ) ) ;
V_45 -> V_24 -- ;
V_19 -> V_57 . V_65 = V_112 ;
F_25 ( V_19 , V_112 - V_113 , V_61 ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
#if V_33
if ( args -> V_34 > V_35 ) {
if ( V_45 -> V_4 == 1 )
F_60 ( args ) ;
else
V_45 -> V_4 -- ;
}
#endif
F_34 ( args ) ;
F_35 ( args -> V_71 , V_19 , V_49 | V_62 ) ;
return 0 ;
}
int
F_61 (
T_12 * args )
{
T_4 * V_19 ;
int V_6 ;
#if V_33 || F_62 ( V_114 )
T_1 V_9 = 0 ;
#endif
#if V_33
int V_115 ;
#endif
T_14 * V_14 ;
T_6 * V_45 ;
F_63 ( args ) ;
V_19 = args -> V_19 ;
ASSERT ( V_19 -> V_53 . V_54 & V_56 ) ;
if ( V_19 -> V_57 . V_65 < F_40 ( T_6 , V_10 ) ) {
ASSERT ( F_41 ( V_19 -> V_30 ) ) ;
return F_42 ( V_80 ) ;
}
ASSERT ( V_19 -> V_53 . V_60 == V_19 -> V_57 . V_65 ) ;
ASSERT ( V_19 -> V_53 . V_63 . V_64 != NULL ) ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
ASSERT ( V_19 -> V_57 . V_65 >= F_19 ( V_45 -> V_4 ) ) ;
#if V_33
if ( args -> V_34 > V_35 && V_45 -> V_4 == 0 ) {
int error ;
int V_112 ;
V_112 =
V_19 -> V_53 . V_60 +
( V_45 -> V_24 + 1 ) *
( ( V_36 ) sizeof( V_38 ) -
( V_36 ) sizeof( V_39 ) ) ;
if ( V_112 > F_20 ( V_19 ) ) {
error = F_45 ( args ) ;
if ( error ) {
return error ;
}
return F_64 ( args ) ;
}
F_48 ( args ) ;
V_115 = 1 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
} else
V_115 = 0 ;
#endif
ASSERT ( args -> V_17 != 1 || args -> V_16 [ 0 ] != '.' ) ;
if ( args -> V_17 == 2 &&
args -> V_16 [ 0 ] == '.' && args -> V_16 [ 1 ] == '.' ) {
#if V_33 || F_62 ( V_114 )
V_9 = F_7 ( V_45 ) ;
ASSERT ( args -> V_34 != V_9 ) ;
#endif
F_8 ( V_45 , args -> V_34 ) ;
}
else {
for ( V_6 = 0 , V_14 = F_27 ( V_45 ) ; V_6 < V_45 -> V_24 ;
V_6 ++ , V_14 = F_32 ( V_19 -> V_30 , V_45 , V_14 ) ) {
if ( F_59 ( args , V_14 -> V_16 , V_14 -> V_17 ) ==
V_104 ) {
#if V_33 || F_62 ( V_114 )
V_9 = F_11 ( V_19 -> V_30 ,
V_45 , V_14 ) ;
ASSERT ( args -> V_34 != V_9 ) ;
#endif
F_12 ( V_19 -> V_30 , V_45 , V_14 ,
args -> V_34 ) ;
F_30 ( V_19 -> V_30 , V_45 , V_14 ,
args -> V_85 ) ;
break;
}
}
if ( V_6 == V_45 -> V_24 ) {
ASSERT ( args -> V_81 & V_110 ) ;
#if V_33
if ( V_115 )
F_60 ( args ) ;
#endif
return F_42 ( V_79 ) ;
}
}
#if V_33
if ( V_9 > V_35 &&
args -> V_34 <= V_35 ) {
if ( V_45 -> V_4 == 1 )
F_60 ( args ) ;
else
V_45 -> V_4 -- ;
}
if ( V_9 <= V_35 &&
args -> V_34 > V_35 ) {
ASSERT ( V_45 -> V_4 != 0 ) ;
if ( ! V_115 )
V_45 -> V_4 ++ ;
}
#endif
F_34 ( args ) ;
F_35 ( args -> V_71 , V_19 , V_62 ) ;
return 0 ;
}
static void
F_60 (
T_12 * args )
{
char * V_87 ;
T_4 * V_19 ;
int V_6 ;
int V_112 ;
T_14 * V_91 ;
T_6 * V_92 ;
int V_113 ;
T_14 * V_14 ;
T_6 * V_45 ;
struct V_11 * V_12 ;
F_65 ( args ) ;
V_19 = args -> V_19 ;
V_12 = V_19 -> V_30 ;
V_113 = V_19 -> V_53 . V_60 ;
V_87 = F_23 ( V_113 , V_47 ) ;
V_92 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
ASSERT ( V_92 -> V_4 == 1 ) ;
memcpy ( V_87 , V_92 , V_113 ) ;
V_112 =
V_113 -
( V_92 -> V_24 + 1 ) *
( ( V_36 ) sizeof( V_38 ) - ( V_36 ) sizeof( V_39 ) ) ;
F_25 ( V_19 , - V_113 , V_61 ) ;
F_25 ( V_19 , V_112 , V_61 ) ;
V_92 = ( T_6 * ) V_87 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_45 -> V_24 = V_92 -> V_24 ;
V_45 -> V_4 = 0 ;
F_8 ( V_45 , F_7 ( V_92 ) ) ;
for ( V_6 = 0 , V_14 = F_27 ( V_45 ) ,
V_91 = F_27 ( V_92 ) ;
V_6 < V_45 -> V_24 ;
V_6 ++ , V_14 = F_32 ( V_12 , V_45 , V_14 ) ,
V_91 = F_32 ( V_12 , V_92 , V_91 ) ) {
V_14 -> V_17 = V_91 -> V_17 ;
V_14 -> V_76 = V_91 -> V_76 ;
memcpy ( V_14 -> V_16 , V_91 -> V_16 , V_14 -> V_17 ) ;
F_12 ( V_12 , V_45 , V_14 ,
F_11 ( V_12 , V_92 , V_91 ) ) ;
F_30 ( V_12 , V_45 , V_14 ,
F_52 ( V_12 , V_92 , V_91 ) ) ;
}
F_36 ( V_87 ) ;
V_19 -> V_57 . V_65 = V_112 ;
F_35 ( args -> V_71 , V_19 , V_49 | V_62 ) ;
}
static void
F_48 (
T_12 * args )
{
char * V_87 ;
T_4 * V_19 ;
int V_6 ;
int V_112 ;
T_14 * V_91 ;
T_6 * V_92 ;
int V_113 ;
T_14 * V_14 ;
T_6 * V_45 ;
struct V_11 * V_12 ;
F_66 ( args ) ;
V_19 = args -> V_19 ;
V_12 = V_19 -> V_30 ;
V_113 = V_19 -> V_53 . V_60 ;
V_87 = F_23 ( V_113 , V_47 ) ;
V_92 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
ASSERT ( V_92 -> V_4 == 0 ) ;
memcpy ( V_87 , V_92 , V_113 ) ;
V_112 =
V_113 +
( V_92 -> V_24 + 1 ) *
( ( V_36 ) sizeof( V_38 ) - ( V_36 ) sizeof( V_39 ) ) ;
F_25 ( V_19 , - V_113 , V_61 ) ;
F_25 ( V_19 , V_112 , V_61 ) ;
V_92 = ( T_6 * ) V_87 ;
V_45 = ( T_6 * ) V_19 -> V_53 . V_63 . V_64 ;
V_45 -> V_24 = V_92 -> V_24 ;
V_45 -> V_4 = 1 ;
F_8 ( V_45 , F_7 ( V_92 ) ) ;
for ( V_6 = 0 , V_14 = F_27 ( V_45 ) ,
V_91 = F_27 ( V_92 ) ;
V_6 < V_45 -> V_24 ;
V_6 ++ , V_14 = F_32 ( V_12 , V_45 , V_14 ) ,
V_91 = F_32 ( V_12 , V_92 , V_91 ) ) {
V_14 -> V_17 = V_91 -> V_17 ;
V_14 -> V_76 = V_91 -> V_76 ;
memcpy ( V_14 -> V_16 , V_91 -> V_16 , V_14 -> V_17 ) ;
F_12 ( V_12 , V_45 , V_14 ,
F_11 ( V_12 , V_92 , V_91 ) ) ;
F_30 ( V_12 , V_45 , V_14 ,
F_52 ( V_12 , V_92 , V_91 ) ) ;
}
F_36 ( V_87 ) ;
V_19 -> V_57 . V_65 = V_112 ;
F_35 ( args -> V_71 , V_19 , V_49 | V_62 ) ;
}
