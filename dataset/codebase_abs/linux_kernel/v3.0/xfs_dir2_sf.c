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
V_13 = V_1 -> V_17 ;
V_7 = V_10 = V_14 = 0 ;
V_6 = F_2 ( V_13 , V_2 ) ;
V_5 = F_3 ( V_6 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_6 -> V_7 ) ; V_9 ++ ) {
if ( ( V_4 = F_4 ( V_5 [ V_9 ] . V_18 ) ) == V_19 )
continue;
V_8 = ( T_7 * )
( ( char * ) V_2 + F_5 ( V_13 , V_4 ) ) ;
V_11 = V_8 -> V_14 == 1 && V_8 -> V_20 [ 0 ] == '.' ;
V_12 =
V_8 -> V_14 == 2 &&
V_8 -> V_20 [ 0 ] == '.' && V_8 -> V_20 [ 1 ] == '.' ;
#if V_21
if ( ! V_11 )
V_10 += F_6 ( V_8 -> V_22 ) > V_23 ;
#endif
if ( ! V_11 && ! V_12 ) {
V_7 ++ ;
V_14 += V_8 -> V_14 ;
} else if ( V_12 )
V_15 = F_6 ( V_8 -> V_22 ) ;
V_16 = F_7 ( V_10 ) +
V_7 +
V_7 * ( V_24 ) sizeof( V_25 ) +
V_14 +
( V_10 ?
( V_24 ) sizeof( V_26 ) * V_7 :
( V_24 ) sizeof( V_27 ) * V_7 ) ;
if ( V_16 > F_8 ( V_1 ) )
return V_16 ;
}
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
F_9 ( ( V_28 * ) V_3 , & V_15 , & V_3 -> V_15 ) ;
return V_16 ;
}
int
F_10 (
T_10 * args ,
T_11 * V_29 ,
int V_16 ,
T_3 * V_3 )
{
T_2 * V_2 ;
T_6 * V_6 ;
T_7 * V_8 ;
T_1 * V_1 ;
T_12 * V_30 ;
char * V_31 ;
int error ;
int V_32 ;
T_8 * V_13 ;
char * V_33 ;
T_13 * V_34 ;
V_28 * V_35 ;
T_9 V_36 ;
F_11 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_17 ;
V_2 = F_12 ( V_13 -> V_37 , V_38 ) ;
memcpy ( V_2 , V_29 -> V_39 , V_13 -> V_37 ) ;
V_32 = V_40 ;
if ( ( error = F_13 ( args , V_13 -> V_41 , V_29 ) ) ) {
ASSERT ( error != V_42 ) ;
goto V_43;
}
V_1 -> V_44 . V_45 &= ~ V_46 ;
V_1 -> V_44 . V_45 |= V_47 ;
V_1 -> V_48 . V_49 = V_50 ;
ASSERT ( V_1 -> V_44 . V_51 == 0 ) ;
F_14 ( V_1 , V_16 , V_52 ) ;
V_32 |= V_53 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
memcpy ( V_35 , V_3 , F_7 ( V_3 -> V_10 ) ) ;
V_1 -> V_48 . V_56 = V_16 ;
V_6 = F_2 ( V_13 , V_2 ) ;
V_33 = ( char * ) V_2 -> V_57 ;
V_31 = ( char * ) F_3 ( V_6 ) ;
V_34 = F_15 ( V_35 ) ;
while ( V_33 < V_31 ) {
V_30 = ( T_12 * ) V_33 ;
if ( F_16 ( V_30 -> V_58 ) == V_59 ) {
V_33 += F_16 ( V_30 -> V_60 ) ;
continue;
}
V_8 = ( T_7 * ) V_33 ;
if ( V_8 -> V_14 == 1 && V_8 -> V_20 [ 0 ] == '.' )
ASSERT ( F_6 ( V_8 -> V_22 ) == V_1 -> V_61 ) ;
else if ( V_8 -> V_14 == 2 &&
V_8 -> V_20 [ 0 ] == '.' && V_8 -> V_20 [ 1 ] == '.' )
ASSERT ( F_6 ( V_8 -> V_22 ) ==
F_17 ( V_35 , & V_35 -> V_62 . V_15 ) ) ;
else {
V_34 -> V_14 = V_8 -> V_14 ;
F_18 ( V_34 ,
( V_63 )
( ( char * ) V_8 - ( char * ) V_2 ) ) ;
memcpy ( V_34 -> V_20 , V_8 -> V_20 , V_8 -> V_14 ) ;
V_36 = F_6 ( V_8 -> V_22 ) ;
F_9 ( V_35 , & V_36 ,
F_19 ( V_34 ) ) ;
V_34 = F_20 ( V_35 , V_34 ) ;
}
V_33 += F_21 ( V_8 -> V_14 ) ;
}
ASSERT ( ( char * ) V_34 - ( char * ) V_35 == V_16 ) ;
F_22 ( args ) ;
V_43:
F_23 ( args -> V_64 , V_1 , V_32 ) ;
F_24 ( V_2 ) ;
return error ;
}
int
F_25 (
T_10 * args )
{
int V_65 ;
T_1 * V_1 ;
int error ;
int V_66 ;
int V_67 ;
int V_68 ;
V_63 V_69 = 0 ;
int V_70 ;
int V_71 ;
V_28 * V_35 ;
T_13 * V_34 = NULL ;
F_26 ( args ) ;
ASSERT ( F_27 ( args ) == V_72 ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_44 . V_45 & V_47 ) ;
if ( V_1 -> V_48 . V_56 < F_28 ( T_3 , V_15 ) ) {
ASSERT ( F_29 ( V_1 -> V_17 ) ) ;
return F_30 ( V_73 ) ;
}
ASSERT ( V_1 -> V_44 . V_51 == V_1 -> V_48 . V_56 ) ;
ASSERT ( V_1 -> V_44 . V_54 . V_55 != NULL ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
ASSERT ( V_1 -> V_48 . V_56 >= F_7 ( V_35 -> V_62 . V_10 ) ) ;
V_65 = F_31 ( V_35 , args -> V_14 ) ;
V_66 = V_65 ;
V_68 = 0 ;
#if V_21
if ( args -> V_22 > V_23 && V_35 -> V_62 . V_10 == 0 ) {
V_65 +=
( V_24 ) sizeof( V_26 ) -
( V_24 ) sizeof( V_27 ) ;
V_66 +=
( V_35 -> V_62 . V_7 + 2 ) *
( ( V_24 ) sizeof( V_26 ) -
( V_24 ) sizeof( V_27 ) ) ;
V_68 = 1 ;
}
#endif
V_70 = ( int ) V_1 -> V_48 . V_56 ;
V_67 = V_70 + V_66 ;
if ( V_67 > F_8 ( V_1 ) ||
( V_71 =
F_32 ( args , V_68 , & V_34 , & V_69 ) ) == 0 ) {
if ( ( args -> V_74 & V_75 ) || args -> V_76 == 0 )
return F_30 ( V_42 ) ;
error = F_33 ( args ) ;
if ( error )
return error ;
return F_34 ( args ) ;
}
if ( args -> V_74 & V_75 )
return 0 ;
if ( V_71 == 1 )
F_35 ( args , V_34 , V_69 , V_67 ) ;
else {
ASSERT ( V_71 == 2 ) ;
#if V_21
if ( V_68 )
F_36 ( args ) ;
#endif
F_37 ( args , V_68 , V_67 ) ;
}
F_23 ( args -> V_64 , V_1 , V_40 | V_53 ) ;
return 0 ;
}
static void
F_35 (
T_10 * args ,
T_13 * V_34 ,
V_63 V_69 ,
int V_67 )
{
int V_77 ;
T_1 * V_1 ;
V_28 * V_35 ;
V_1 = args -> V_1 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_77 = ( int ) ( ( char * ) V_34 - ( char * ) V_35 ) ;
F_14 ( V_1 , F_31 ( V_35 , args -> V_14 ) ,
V_52 ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_34 = ( T_13 * ) ( ( char * ) V_35 + V_77 ) ;
V_34 -> V_14 = args -> V_14 ;
F_18 ( V_34 , V_69 ) ;
memcpy ( V_34 -> V_20 , args -> V_20 , V_34 -> V_14 ) ;
F_9 ( V_35 , & args -> V_22 ,
F_19 ( V_34 ) ) ;
V_35 -> V_62 . V_7 ++ ;
#if V_21
if ( args -> V_22 > V_23 )
V_35 -> V_62 . V_10 ++ ;
#endif
V_1 -> V_48 . V_56 = V_67 ;
F_22 ( args ) ;
}
static void
F_37 (
T_10 * args ,
int V_68 ,
int V_67 )
{
int V_78 ;
char * V_79 ;
T_1 * V_1 ;
int V_80 ;
int V_81 ;
V_63 V_82 ;
V_63 V_69 ;
int V_70 ;
T_13 * V_83 ;
V_28 * V_84 ;
T_13 * V_34 ;
V_28 * V_35 ;
V_1 = args -> V_1 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_70 = ( int ) V_1 -> V_48 . V_56 ;
V_79 = F_12 ( V_70 , V_38 ) ;
V_84 = ( V_28 * ) V_79 ;
memcpy ( V_84 , V_35 , V_70 ) ;
for ( V_69 = V_85 ,
V_83 = F_15 ( V_84 ) ,
V_78 = F_21 ( args -> V_14 ) ,
V_80 = ( char * ) V_83 == & V_79 [ V_70 ] ;
! V_80 ;
V_69 = V_82 + F_21 ( V_83 -> V_14 ) ,
V_83 = F_20 ( V_84 , V_83 ) ,
V_80 = ( char * ) V_83 == & V_79 [ V_70 ] ) {
V_82 = F_38 ( V_83 ) ;
if ( V_69 + V_78 <= V_82 )
break;
}
F_14 ( V_1 , - V_70 , V_52 ) ;
F_14 ( V_1 , V_67 , V_52 ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_81 = ( int ) ( ( char * ) V_83 - ( char * ) V_84 ) ;
memcpy ( V_35 , V_84 , V_81 ) ;
V_34 = ( T_13 * ) ( ( char * ) V_35 + V_81 ) ;
V_34 -> V_14 = args -> V_14 ;
F_18 ( V_34 , V_69 ) ;
memcpy ( V_34 -> V_20 , args -> V_20 , V_34 -> V_14 ) ;
F_9 ( V_35 , & args -> V_22 ,
F_19 ( V_34 ) ) ;
V_35 -> V_62 . V_7 ++ ;
#if V_21
if ( args -> V_22 > V_23 && ! V_68 )
V_35 -> V_62 . V_10 ++ ;
#endif
if ( ! V_80 ) {
V_34 = F_20 ( V_35 , V_34 ) ;
memcpy ( V_34 , V_83 , V_70 - V_81 ) ;
}
F_24 ( V_79 ) ;
V_1 -> V_48 . V_56 = V_67 ;
F_22 ( args ) ;
}
static int
F_32 (
T_10 * args ,
int V_68 ,
T_13 * * V_86 ,
V_63 * V_87 )
{
T_1 * V_1 ;
int V_88 ;
int V_9 ;
T_8 * V_13 ;
V_63 V_69 ;
T_13 * V_34 ;
V_28 * V_35 ;
int V_16 ;
int V_89 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_17 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_16 = F_21 ( args -> V_14 ) ;
V_69 = V_85 ;
V_34 = F_15 ( V_35 ) ;
V_88 = 0 ;
for ( V_9 = 0 ; V_9 < V_35 -> V_62 . V_7 ; V_9 ++ ) {
if ( ! V_88 )
V_88 = V_69 + V_16 <= F_38 ( V_34 ) ;
V_69 = F_38 ( V_34 ) +
F_21 ( V_34 -> V_14 ) ;
V_34 = F_20 ( V_35 , V_34 ) ;
}
V_89 = V_69 +
( V_35 -> V_62 . V_7 + 3 ) * ( V_24 ) sizeof( T_5 ) +
( V_24 ) sizeof( T_6 ) ;
if ( V_89 + ( V_88 ? 0 : V_16 ) > V_13 -> V_37 )
return 0 ;
#if V_21
if ( V_68 ) {
return 2 ;
}
#else
ASSERT ( V_68 == 0 ) ;
#endif
if ( V_89 + V_16 > V_13 -> V_37 )
return 2 ;
* V_86 = V_34 ;
* V_87 = V_69 ;
return 1 ;
}
static void
F_22 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int V_10 ;
T_9 V_90 ;
int V_69 ;
T_13 * V_34 ;
V_28 * V_35 ;
V_1 = args -> V_1 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_69 = V_85 ;
V_90 = F_17 ( V_35 , & V_35 -> V_62 . V_15 ) ;
V_10 = V_90 > V_23 ;
for ( V_9 = 0 , V_34 = F_15 ( V_35 ) ;
V_9 < V_35 -> V_62 . V_7 ;
V_9 ++ , V_34 = F_20 ( V_35 , V_34 ) ) {
ASSERT ( F_38 ( V_34 ) >= V_69 ) ;
V_90 = F_17 ( V_35 , F_19 ( V_34 ) ) ;
V_10 += V_90 > V_23 ;
V_69 =
F_38 ( V_34 ) +
F_21 ( V_34 -> V_14 ) ;
}
ASSERT ( V_10 == V_35 -> V_62 . V_10 ) ;
ASSERT ( V_21 || V_10 == 0 ) ;
ASSERT ( ( char * ) V_34 - ( char * ) V_35 == V_1 -> V_48 . V_56 ) ;
ASSERT ( V_69 +
( V_35 -> V_62 . V_7 + 2 ) * ( V_24 ) sizeof( T_5 ) +
( V_24 ) sizeof( T_6 ) <=
V_1 -> V_17 -> V_37 ) ;
}
int
F_39 (
T_10 * args ,
T_9 V_91 )
{
T_1 * V_1 ;
int V_10 ;
V_28 * V_35 ;
int V_16 ;
F_40 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_1 -> V_48 . V_56 == 0 ) ;
if ( V_1 -> V_48 . V_49 == V_92 ) {
V_1 -> V_44 . V_45 &= ~ V_46 ;
V_1 -> V_48 . V_49 = V_50 ;
F_23 ( args -> V_64 , V_1 , V_40 ) ;
V_1 -> V_44 . V_45 |= V_47 ;
}
ASSERT ( V_1 -> V_44 . V_45 & V_47 ) ;
ASSERT ( V_1 -> V_44 . V_51 == 0 ) ;
V_10 = V_91 > V_23 ;
V_16 = F_7 ( V_10 ) ;
F_14 ( V_1 , V_16 , V_52 ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_35 -> V_62 . V_10 = V_10 ;
F_9 ( V_35 , & V_91 , & V_35 -> V_62 . V_15 ) ;
V_35 -> V_62 . V_7 = 0 ;
V_1 -> V_48 . V_56 = V_16 ;
F_22 ( args ) ;
F_23 ( args -> V_64 , V_1 , V_40 | V_53 ) ;
return 0 ;
}
int
F_41 (
T_1 * V_1 ,
void * V_93 ,
T_14 * V_69 ,
T_15 V_94 )
{
int V_9 ;
T_8 * V_13 ;
T_4 V_95 ;
T_13 * V_34 ;
V_28 * V_35 ;
T_4 V_96 ;
T_4 V_97 ;
T_9 V_90 ;
V_13 = V_1 -> V_17 ;
ASSERT ( V_1 -> V_44 . V_45 & V_47 ) ;
if ( V_1 -> V_48 . V_56 < F_28 ( T_3 , V_15 ) ) {
ASSERT ( F_29 ( V_13 ) ) ;
return F_30 ( V_73 ) ;
}
ASSERT ( V_1 -> V_44 . V_51 == V_1 -> V_48 . V_56 ) ;
ASSERT ( V_1 -> V_44 . V_54 . V_55 != NULL ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
ASSERT ( V_1 -> V_48 . V_56 >= F_7 ( V_35 -> V_62 . V_10 ) ) ;
if ( F_42 ( V_13 , * V_69 ) > V_13 -> V_41 )
return 0 ;
V_96 = F_43 ( V_13 , V_13 -> V_41 ,
V_98 ) ;
V_97 = F_43 ( V_13 , V_13 -> V_41 ,
V_99 ) ;
if ( * V_69 <= V_96 ) {
if ( V_94 ( V_93 , L_1 , 1 , V_96 & 0x7fffffff , V_1 -> V_61 , V_100 ) ) {
* V_69 = V_96 & 0x7fffffff ;
return 0 ;
}
}
if ( * V_69 <= V_97 ) {
V_90 = F_17 ( V_35 , & V_35 -> V_62 . V_15 ) ;
if ( V_94 ( V_93 , L_2 , 2 , V_97 & 0x7fffffff , V_90 , V_100 ) ) {
* V_69 = V_97 & 0x7fffffff ;
return 0 ;
}
}
V_34 = F_15 ( V_35 ) ;
for ( V_9 = 0 ; V_9 < V_35 -> V_62 . V_7 ; V_9 ++ ) {
V_95 = F_43 ( V_13 , V_13 -> V_41 ,
F_38 ( V_34 ) ) ;
if ( * V_69 > V_95 ) {
V_34 = F_20 ( V_35 , V_34 ) ;
continue;
}
V_90 = F_17 ( V_35 , F_19 ( V_34 ) ) ;
if ( V_94 ( V_93 , ( char * ) V_34 -> V_20 , V_34 -> V_14 ,
V_95 & 0x7fffffff , V_90 , V_101 ) ) {
* V_69 = V_95 & 0x7fffffff ;
return 0 ;
}
V_34 = F_20 ( V_35 , V_34 ) ;
}
* V_69 = F_43 ( V_13 , V_13 -> V_41 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
int
F_27 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int error ;
T_13 * V_34 ;
V_28 * V_35 ;
enum V_102 V_103 ;
T_13 * V_104 ;
F_44 ( args ) ;
F_22 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_44 . V_45 & V_47 ) ;
if ( V_1 -> V_48 . V_56 < F_28 ( T_3 , V_15 ) ) {
ASSERT ( F_29 ( V_1 -> V_17 ) ) ;
return F_30 ( V_73 ) ;
}
ASSERT ( V_1 -> V_44 . V_51 == V_1 -> V_48 . V_56 ) ;
ASSERT ( V_1 -> V_44 . V_54 . V_55 != NULL ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
ASSERT ( V_1 -> V_48 . V_56 >= F_7 ( V_35 -> V_62 . V_10 ) ) ;
if ( args -> V_14 == 1 && args -> V_20 [ 0 ] == '.' ) {
args -> V_22 = V_1 -> V_61 ;
args -> V_105 = V_106 ;
return F_30 ( V_107 ) ;
}
if ( args -> V_14 == 2 &&
args -> V_20 [ 0 ] == '.' && args -> V_20 [ 1 ] == '.' ) {
args -> V_22 = F_17 ( V_35 , & V_35 -> V_62 . V_15 ) ;
args -> V_105 = V_106 ;
return F_30 ( V_107 ) ;
}
V_104 = NULL ;
for ( V_9 = 0 , V_34 = F_15 ( V_35 ) ; V_9 < V_35 -> V_62 . V_7 ;
V_9 ++ , V_34 = F_20 ( V_35 , V_34 ) ) {
V_103 = V_1 -> V_17 -> V_108 -> V_109 ( args , V_34 -> V_20 ,
V_34 -> V_14 ) ;
if ( V_103 != V_110 && V_103 != args -> V_105 ) {
args -> V_105 = V_103 ;
args -> V_22 = F_17 ( V_35 ,
F_19 ( V_34 ) ) ;
if ( V_103 == V_106 )
return F_30 ( V_107 ) ;
V_104 = V_34 ;
}
}
ASSERT ( args -> V_74 & V_111 ) ;
if ( ! V_104 )
return F_30 ( V_72 ) ;
error = F_45 ( args , V_104 -> V_20 , V_104 -> V_14 ) ;
return F_30 ( error ) ;
}
int
F_46 (
T_10 * args )
{
int V_77 ;
T_1 * V_1 ;
int V_112 ;
int V_9 ;
int V_113 ;
int V_114 ;
T_13 * V_34 ;
V_28 * V_35 ;
F_47 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_44 . V_45 & V_47 ) ;
V_114 = ( int ) V_1 -> V_48 . V_56 ;
if ( V_114 < F_28 ( T_3 , V_15 ) ) {
ASSERT ( F_29 ( V_1 -> V_17 ) ) ;
return F_30 ( V_73 ) ;
}
ASSERT ( V_1 -> V_44 . V_51 == V_114 ) ;
ASSERT ( V_1 -> V_44 . V_54 . V_55 != NULL ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
ASSERT ( V_114 >= F_7 ( V_35 -> V_62 . V_10 ) ) ;
for ( V_9 = 0 , V_34 = F_15 ( V_35 ) ; V_9 < V_35 -> V_62 . V_7 ;
V_9 ++ , V_34 = F_20 ( V_35 , V_34 ) ) {
if ( F_48 ( args , V_34 -> V_20 , V_34 -> V_14 ) ==
V_106 ) {
ASSERT ( F_17 ( V_35 ,
F_19 ( V_34 ) ) ==
args -> V_22 ) ;
break;
}
}
if ( V_9 == V_35 -> V_62 . V_7 )
return F_30 ( V_72 ) ;
V_77 = ( int ) ( ( char * ) V_34 - ( char * ) V_35 ) ;
V_112 = F_31 ( V_35 , args -> V_14 ) ;
V_113 = V_114 - V_112 ;
if ( V_77 + V_112 < V_114 )
memmove ( ( char * ) V_35 + V_77 , ( char * ) V_35 + V_77 + V_112 ,
V_114 - ( V_77 + V_112 ) ) ;
V_35 -> V_62 . V_7 -- ;
V_1 -> V_48 . V_56 = V_113 ;
F_14 ( V_1 , V_113 - V_114 , V_52 ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
#if V_21
if ( args -> V_22 > V_23 ) {
if ( V_35 -> V_62 . V_10 == 1 )
F_49 ( args ) ;
else
V_35 -> V_62 . V_10 -- ;
}
#endif
F_22 ( args ) ;
F_23 ( args -> V_64 , V_1 , V_40 | V_53 ) ;
return 0 ;
}
int
F_50 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
#if V_21 || F_51 ( V_115 )
T_9 V_90 = 0 ;
#endif
#if V_21
int V_116 ;
#endif
T_13 * V_34 ;
V_28 * V_35 ;
F_52 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_44 . V_45 & V_47 ) ;
if ( V_1 -> V_48 . V_56 < F_28 ( T_3 , V_15 ) ) {
ASSERT ( F_29 ( V_1 -> V_17 ) ) ;
return F_30 ( V_73 ) ;
}
ASSERT ( V_1 -> V_44 . V_51 == V_1 -> V_48 . V_56 ) ;
ASSERT ( V_1 -> V_44 . V_54 . V_55 != NULL ) ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
ASSERT ( V_1 -> V_48 . V_56 >= F_7 ( V_35 -> V_62 . V_10 ) ) ;
#if V_21
if ( args -> V_22 > V_23 && V_35 -> V_62 . V_10 == 0 ) {
int error ;
int V_113 ;
V_113 =
V_1 -> V_44 . V_51 +
( V_35 -> V_62 . V_7 + 1 ) *
( ( V_24 ) sizeof( V_26 ) -
( V_24 ) sizeof( V_27 ) ) ;
if ( V_113 > F_8 ( V_1 ) ) {
error = F_33 ( args ) ;
if ( error ) {
return error ;
}
return F_53 ( args ) ;
}
F_36 ( args ) ;
V_116 = 1 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
} else
V_116 = 0 ;
#endif
ASSERT ( args -> V_14 != 1 || args -> V_20 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_20 [ 0 ] == '.' && args -> V_20 [ 1 ] == '.' ) {
#if V_21 || F_51 ( V_115 )
V_90 = F_17 ( V_35 , & V_35 -> V_62 . V_15 ) ;
ASSERT ( args -> V_22 != V_90 ) ;
#endif
F_9 ( V_35 , & args -> V_22 , & V_35 -> V_62 . V_15 ) ;
}
else {
for ( V_9 = 0 , V_34 = F_15 ( V_35 ) ;
V_9 < V_35 -> V_62 . V_7 ;
V_9 ++ , V_34 = F_20 ( V_35 , V_34 ) ) {
if ( F_48 ( args , V_34 -> V_20 , V_34 -> V_14 ) ==
V_106 ) {
#if V_21 || F_51 ( V_115 )
V_90 = F_17 ( V_35 ,
F_19 ( V_34 ) ) ;
ASSERT ( args -> V_22 != V_90 ) ;
#endif
F_9 ( V_35 , & args -> V_22 ,
F_19 ( V_34 ) ) ;
break;
}
}
if ( V_9 == V_35 -> V_62 . V_7 ) {
ASSERT ( args -> V_74 & V_111 ) ;
#if V_21
if ( V_116 )
F_49 ( args ) ;
#endif
return F_30 ( V_72 ) ;
}
}
#if V_21
if ( V_90 > V_23 &&
args -> V_22 <= V_23 ) {
if ( V_35 -> V_62 . V_10 == 1 )
F_49 ( args ) ;
else
V_35 -> V_62 . V_10 -- ;
}
if ( V_90 <= V_23 &&
args -> V_22 > V_23 ) {
ASSERT ( V_35 -> V_62 . V_10 != 0 ) ;
if ( ! V_116 )
V_35 -> V_62 . V_10 ++ ;
}
#endif
F_22 ( args ) ;
F_23 ( args -> V_64 , V_1 , V_53 ) ;
return 0 ;
}
static void
F_49 (
T_10 * args )
{
char * V_79 ;
T_1 * V_1 ;
int V_9 ;
T_9 V_90 ;
int V_113 ;
T_13 * V_83 ;
V_28 * V_84 ;
int V_114 ;
T_13 * V_34 ;
V_28 * V_35 ;
F_54 ( args ) ;
V_1 = args -> V_1 ;
V_114 = V_1 -> V_44 . V_51 ;
V_79 = F_12 ( V_114 , V_38 ) ;
V_84 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
ASSERT ( V_84 -> V_62 . V_10 == 1 ) ;
memcpy ( V_79 , V_84 , V_114 ) ;
V_113 =
V_114 -
( V_84 -> V_62 . V_7 + 1 ) *
( ( V_24 ) sizeof( V_26 ) - ( V_24 ) sizeof( V_27 ) ) ;
F_14 ( V_1 , - V_114 , V_52 ) ;
F_14 ( V_1 , V_113 , V_52 ) ;
V_84 = ( V_28 * ) V_79 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_35 -> V_62 . V_7 = V_84 -> V_62 . V_7 ;
V_35 -> V_62 . V_10 = 0 ;
V_90 = F_17 ( V_84 , & V_84 -> V_62 . V_15 ) ;
F_9 ( V_35 , & V_90 , & V_35 -> V_62 . V_15 ) ;
for ( V_9 = 0 , V_34 = F_15 ( V_35 ) ,
V_83 = F_15 ( V_84 ) ;
V_9 < V_35 -> V_62 . V_7 ;
V_9 ++ , V_34 = F_20 ( V_35 , V_34 ) ,
V_83 = F_20 ( V_84 , V_83 ) ) {
V_34 -> V_14 = V_83 -> V_14 ;
V_34 -> V_69 = V_83 -> V_69 ;
memcpy ( V_34 -> V_20 , V_83 -> V_20 , V_34 -> V_14 ) ;
V_90 = F_17 ( V_84 ,
F_19 ( V_83 ) ) ;
F_9 ( V_35 , & V_90 , F_19 ( V_34 ) ) ;
}
F_24 ( V_79 ) ;
V_1 -> V_48 . V_56 = V_113 ;
F_23 ( args -> V_64 , V_1 , V_40 | V_53 ) ;
}
static void
F_36 (
T_10 * args )
{
char * V_79 ;
T_1 * V_1 ;
int V_9 ;
T_9 V_90 ;
int V_113 ;
T_13 * V_83 ;
V_28 * V_84 ;
int V_114 ;
T_13 * V_34 ;
V_28 * V_35 ;
F_55 ( args ) ;
V_1 = args -> V_1 ;
V_114 = V_1 -> V_44 . V_51 ;
V_79 = F_12 ( V_114 , V_38 ) ;
V_84 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
ASSERT ( V_84 -> V_62 . V_10 == 0 ) ;
memcpy ( V_79 , V_84 , V_114 ) ;
V_113 =
V_114 +
( V_84 -> V_62 . V_7 + 1 ) *
( ( V_24 ) sizeof( V_26 ) - ( V_24 ) sizeof( V_27 ) ) ;
F_14 ( V_1 , - V_114 , V_52 ) ;
F_14 ( V_1 , V_113 , V_52 ) ;
V_84 = ( V_28 * ) V_79 ;
V_35 = ( V_28 * ) V_1 -> V_44 . V_54 . V_55 ;
V_35 -> V_62 . V_7 = V_84 -> V_62 . V_7 ;
V_35 -> V_62 . V_10 = 1 ;
V_90 = F_17 ( V_84 , & V_84 -> V_62 . V_15 ) ;
F_9 ( V_35 , & V_90 , & V_35 -> V_62 . V_15 ) ;
for ( V_9 = 0 , V_34 = F_15 ( V_35 ) ,
V_83 = F_15 ( V_84 ) ;
V_9 < V_35 -> V_62 . V_7 ;
V_9 ++ , V_34 = F_20 ( V_35 , V_34 ) ,
V_83 = F_20 ( V_84 , V_83 ) ) {
V_34 -> V_14 = V_83 -> V_14 ;
V_34 -> V_69 = V_83 -> V_69 ;
memcpy ( V_34 -> V_20 , V_83 -> V_20 , V_34 -> V_14 ) ;
V_90 = F_17 ( V_84 ,
F_19 ( V_83 ) ) ;
F_9 ( V_35 , & V_90 , F_19 ( V_34 ) ) ;
}
F_24 ( V_79 ) ;
V_1 -> V_48 . V_56 = V_113 ;
F_23 ( args -> V_64 , V_1 , V_40 | V_53 ) ;
}
