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
#if V_26
if ( ! V_11 )
V_10 += F_7 ( V_8 -> V_27 ) > V_28 ;
#endif
if ( ! V_11 && ! V_12 ) {
V_7 ++ ;
V_14 += V_8 -> V_14 + V_17 ;
} else if ( V_12 )
V_15 = F_7 ( V_8 -> V_27 ) ;
V_16 = F_8 ( V_10 ) +
V_7 +
V_7 * ( V_29 ) sizeof( V_30 ) +
V_14 +
( V_10 ?
( V_29 ) sizeof( V_31 ) * V_7 :
( V_29 ) sizeof( V_32 ) * V_7 ) ;
if ( V_16 > F_9 ( V_1 ) )
return V_16 ;
}
V_3 -> V_7 = V_7 ;
V_3 -> V_10 = V_10 ;
V_1 -> V_33 -> V_34 ( V_3 , V_15 ) ;
return V_16 ;
}
int
F_10 (
T_10 * args ,
struct V_35 * V_36 ,
int V_16 ,
T_3 * V_3 )
{
T_2 * V_2 ;
T_6 * V_6 ;
T_7 * V_8 ;
T_1 * V_1 ;
T_11 * V_37 ;
char * V_38 ;
int error ;
int V_39 ;
T_8 * V_13 ;
char * V_40 ;
T_12 * V_41 ;
T_3 * V_42 ;
T_3 * V_43 ;
F_11 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_43 = F_12 ( V_13 -> V_22 . V_44 , V_45 ) ;
V_2 = V_36 -> V_46 ;
V_42 = ( T_3 * ) V_43 ;
memcpy ( V_42 , V_3 , F_8 ( V_3 -> V_10 ) ) ;
V_6 = F_3 ( args -> V_19 , V_2 ) ;
V_40 = ( char * ) V_1 -> V_33 -> V_47 ( V_2 ) ;
V_38 = ( char * ) F_4 ( V_6 ) ;
V_41 = F_13 ( V_42 ) ;
while ( V_40 < V_38 ) {
V_37 = ( T_11 * ) V_40 ;
if ( F_14 ( V_37 -> V_48 ) == V_49 ) {
V_40 += F_14 ( V_37 -> V_50 ) ;
continue;
}
V_8 = ( T_7 * ) V_40 ;
if ( V_8 -> V_14 == 1 && V_8 -> V_25 [ 0 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_27 ) == V_1 -> V_51 ) ;
else if ( V_8 -> V_14 == 2 &&
V_8 -> V_25 [ 0 ] == '.' && V_8 -> V_25 [ 1 ] == '.' )
ASSERT ( F_7 ( V_8 -> V_27 ) ==
V_1 -> V_33 -> V_52 ( V_42 ) ) ;
else {
V_41 -> V_14 = V_8 -> V_14 ;
F_15 ( V_41 ,
( V_53 )
( ( char * ) V_8 - ( char * ) V_2 ) ) ;
memcpy ( V_41 -> V_25 , V_8 -> V_25 , V_8 -> V_14 ) ;
V_1 -> V_33 -> V_54 ( V_42 , V_41 ,
F_7 ( V_8 -> V_27 ) ) ;
V_1 -> V_33 -> V_55 ( V_41 ,
V_1 -> V_33 -> V_56 ( V_8 ) ) ;
V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ;
}
V_40 += V_1 -> V_33 -> V_58 ( V_8 -> V_14 ) ;
}
ASSERT ( ( char * ) V_41 - ( char * ) V_42 == V_16 ) ;
V_39 = V_59 ;
error = F_16 ( args , args -> V_19 -> V_60 , V_36 ) ;
if ( error ) {
ASSERT ( error != V_61 ) ;
goto V_62;
}
V_1 -> V_63 . V_64 &= ~ V_65 ;
V_1 -> V_63 . V_64 |= V_66 ;
V_1 -> V_67 . V_68 = V_69 ;
ASSERT ( V_1 -> V_63 . V_70 == 0 ) ;
F_17 ( V_1 , V_16 , V_71 ) ;
V_39 |= V_72 ;
memcpy ( V_1 -> V_63 . V_73 . V_74 , V_43 , V_16 ) ;
V_1 -> V_67 . V_75 = V_16 ;
F_18 ( args ) ;
V_62:
F_19 ( args -> V_76 , V_1 , V_39 ) ;
F_20 ( V_43 ) ;
return error ;
}
int
F_21 (
T_10 * args )
{
T_1 * V_1 ;
int error ;
int V_77 ;
int V_78 ;
int V_79 ;
V_53 V_80 = 0 ;
int V_81 ;
T_3 * V_42 ;
T_12 * V_41 = NULL ;
F_22 ( args ) ;
ASSERT ( F_23 ( args ) == V_82 ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_63 . V_64 & V_66 ) ;
if ( V_1 -> V_67 . V_75 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return F_26 ( V_83 ) ;
}
ASSERT ( V_1 -> V_63 . V_70 == V_1 -> V_67 . V_75 ) ;
ASSERT ( V_1 -> V_63 . V_73 . V_74 != NULL ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
ASSERT ( V_1 -> V_67 . V_75 >= F_8 ( V_42 -> V_10 ) ) ;
V_77 = V_1 -> V_33 -> V_84 ( V_42 , args -> V_14 ) ;
V_79 = 0 ;
#if V_26
if ( args -> V_27 > V_28 && V_42 -> V_10 == 0 ) {
V_77 +=
( V_42 -> V_7 + 2 ) *
( ( V_29 ) sizeof( V_31 ) -
( V_29 ) sizeof( V_32 ) ) ;
V_79 = 1 ;
}
#endif
V_78 = ( int ) V_1 -> V_67 . V_75 + V_77 ;
if ( V_78 > F_9 ( V_1 ) ||
( V_81 =
F_27 ( args , V_79 , & V_41 , & V_80 ) ) == 0 ) {
if ( ( args -> V_85 & V_86 ) || args -> V_87 == 0 )
return F_26 ( V_61 ) ;
error = F_28 ( args ) ;
if ( error )
return error ;
return F_29 ( args ) ;
}
if ( args -> V_85 & V_86 )
return 0 ;
if ( V_81 == 1 )
F_30 ( args , V_41 , V_80 , V_78 ) ;
else {
ASSERT ( V_81 == 2 ) ;
#if V_26
if ( V_79 )
F_31 ( args ) ;
#endif
F_32 ( args , V_79 , V_78 ) ;
}
F_19 ( args -> V_76 , V_1 , V_59 | V_72 ) ;
return 0 ;
}
static void
F_30 (
T_10 * args ,
T_12 * V_41 ,
V_53 V_80 ,
int V_78 )
{
int V_88 ;
T_1 * V_1 ;
T_3 * V_42 ;
V_1 = args -> V_1 ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_88 = ( int ) ( ( char * ) V_41 - ( char * ) V_42 ) ;
F_17 ( V_1 , V_1 -> V_33 -> V_84 ( V_42 , args -> V_14 ) ,
V_71 ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_41 = ( T_12 * ) ( ( char * ) V_42 + V_88 ) ;
V_41 -> V_14 = args -> V_14 ;
F_15 ( V_41 , V_80 ) ;
memcpy ( V_41 -> V_25 , args -> V_25 , V_41 -> V_14 ) ;
V_1 -> V_33 -> V_54 ( V_42 , V_41 , args -> V_27 ) ;
V_1 -> V_33 -> V_55 ( V_41 , args -> V_89 ) ;
V_42 -> V_7 ++ ;
#if V_26
if ( args -> V_27 > V_28 )
V_42 -> V_10 ++ ;
#endif
V_1 -> V_67 . V_75 = V_78 ;
F_18 ( args ) ;
}
static void
F_32 (
T_10 * args ,
int V_79 ,
int V_78 )
{
int V_90 ;
char * V_91 ;
T_1 * V_1 ;
int V_92 ;
int V_93 ;
V_53 V_94 ;
V_53 V_80 ;
int V_95 ;
T_12 * V_96 ;
T_3 * V_97 ;
T_12 * V_41 ;
T_3 * V_42 ;
struct V_98 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_95 = ( int ) V_1 -> V_67 . V_75 ;
V_91 = F_12 ( V_95 , V_45 ) ;
V_97 = ( T_3 * ) V_91 ;
memcpy ( V_97 , V_42 , V_95 ) ;
for ( V_80 = V_1 -> V_33 -> V_99 ,
V_96 = F_13 ( V_97 ) ,
V_90 = V_1 -> V_33 -> V_58 ( args -> V_14 ) ,
V_92 = ( char * ) V_96 == & V_91 [ V_95 ] ;
! V_92 ;
V_80 = V_94 + V_1 -> V_33 -> V_58 ( V_96 -> V_14 ) ,
V_96 = V_1 -> V_33 -> V_57 ( V_97 , V_96 ) ,
V_92 = ( char * ) V_96 == & V_91 [ V_95 ] ) {
V_94 = F_33 ( V_96 ) ;
if ( V_80 + V_90 <= V_94 )
break;
}
F_17 ( V_1 , - V_95 , V_71 ) ;
F_17 ( V_1 , V_78 , V_71 ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_93 = ( int ) ( ( char * ) V_96 - ( char * ) V_97 ) ;
memcpy ( V_42 , V_97 , V_93 ) ;
V_41 = ( T_12 * ) ( ( char * ) V_42 + V_93 ) ;
V_41 -> V_14 = args -> V_14 ;
F_15 ( V_41 , V_80 ) ;
memcpy ( V_41 -> V_25 , args -> V_25 , V_41 -> V_14 ) ;
V_1 -> V_33 -> V_54 ( V_42 , V_41 , args -> V_27 ) ;
V_1 -> V_33 -> V_55 ( V_41 , args -> V_89 ) ;
V_42 -> V_7 ++ ;
#if V_26
if ( args -> V_27 > V_28 && ! V_79 )
V_42 -> V_10 ++ ;
#endif
if ( ! V_92 ) {
V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ;
memcpy ( V_41 , V_96 , V_95 - V_93 ) ;
}
F_20 ( V_91 ) ;
V_1 -> V_67 . V_75 = V_78 ;
F_18 ( args ) ;
}
static int
F_27 (
T_10 * args ,
int V_79 ,
T_12 * * V_100 ,
V_53 * V_101 )
{
T_1 * V_1 ;
int V_102 ;
int V_9 ;
T_8 * V_13 ;
V_53 V_80 ;
T_12 * V_41 ;
T_3 * V_42 ;
int V_16 ;
int V_103 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_16 = V_1 -> V_33 -> V_58 ( args -> V_14 ) ;
V_80 = V_1 -> V_33 -> V_99 ;
V_41 = F_13 ( V_42 ) ;
V_102 = 0 ;
for ( V_9 = 0 ; V_9 < V_42 -> V_7 ; V_9 ++ ) {
if ( ! V_102 )
V_102 = V_80 + V_16 <= F_33 ( V_41 ) ;
V_80 = F_33 ( V_41 ) +
V_1 -> V_33 -> V_58 ( V_41 -> V_14 ) ;
V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ;
}
V_103 = V_80 +
( V_42 -> V_7 + 3 ) * ( V_29 ) sizeof( T_5 ) +
( V_29 ) sizeof( T_6 ) ;
if ( V_103 + ( V_102 ? 0 : V_16 ) > args -> V_19 -> V_104 )
return 0 ;
#if V_26
if ( V_79 ) {
return 2 ;
}
#else
ASSERT ( V_79 == 0 ) ;
#endif
if ( V_103 + V_16 > args -> V_19 -> V_104 )
return 2 ;
* V_100 = V_41 ;
* V_101 = V_80 ;
return 1 ;
}
static void
F_18 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int V_10 ;
T_9 V_105 ;
int V_80 ;
T_12 * V_41 ;
T_3 * V_42 ;
struct V_98 * V_13 ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_80 = V_1 -> V_33 -> V_99 ;
V_105 = V_1 -> V_33 -> V_52 ( V_42 ) ;
V_10 = V_105 > V_28 ;
for ( V_9 = 0 , V_41 = F_13 ( V_42 ) ;
V_9 < V_42 -> V_7 ;
V_9 ++ , V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ) {
ASSERT ( F_33 ( V_41 ) >= V_80 ) ;
V_105 = V_1 -> V_33 -> V_106 ( V_42 , V_41 ) ;
V_10 += V_105 > V_28 ;
V_80 =
F_33 ( V_41 ) +
V_1 -> V_33 -> V_58 ( V_41 -> V_14 ) ;
ASSERT ( V_1 -> V_33 -> V_107 ( V_41 ) < V_108 ) ;
}
ASSERT ( V_10 == V_42 -> V_10 ) ;
ASSERT ( V_26 || V_10 == 0 ) ;
ASSERT ( ( char * ) V_41 - ( char * ) V_42 == V_1 -> V_67 . V_75 ) ;
ASSERT ( V_80 +
( V_42 -> V_7 + 2 ) * ( V_29 ) sizeof( T_5 ) +
( V_29 ) sizeof( T_6 ) <= args -> V_19 -> V_104 ) ;
}
int
F_34 (
T_10 * args ,
T_9 V_109 )
{
T_1 * V_1 ;
int V_10 ;
T_3 * V_42 ;
int V_16 ;
F_35 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 != NULL ) ;
ASSERT ( V_1 -> V_67 . V_75 == 0 ) ;
if ( V_1 -> V_67 . V_68 == V_110 ) {
V_1 -> V_63 . V_64 &= ~ V_65 ;
V_1 -> V_67 . V_68 = V_69 ;
F_19 ( args -> V_76 , V_1 , V_59 ) ;
V_1 -> V_63 . V_64 |= V_66 ;
}
ASSERT ( V_1 -> V_63 . V_64 & V_66 ) ;
ASSERT ( V_1 -> V_63 . V_70 == 0 ) ;
V_10 = V_109 > V_28 ;
V_16 = F_8 ( V_10 ) ;
F_17 ( V_1 , V_16 , V_71 ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_42 -> V_10 = V_10 ;
V_1 -> V_33 -> V_34 ( V_42 , V_109 ) ;
V_42 -> V_7 = 0 ;
V_1 -> V_67 . V_75 = V_16 ;
F_18 ( args ) ;
F_19 ( args -> V_76 , V_1 , V_59 | V_72 ) ;
return 0 ;
}
int
F_23 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
int error ;
T_12 * V_41 ;
T_3 * V_42 ;
enum V_111 V_112 ;
T_12 * V_113 ;
F_36 ( args ) ;
F_18 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_63 . V_64 & V_66 ) ;
if ( V_1 -> V_67 . V_75 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return F_26 ( V_83 ) ;
}
ASSERT ( V_1 -> V_63 . V_70 == V_1 -> V_67 . V_75 ) ;
ASSERT ( V_1 -> V_63 . V_73 . V_74 != NULL ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
ASSERT ( V_1 -> V_67 . V_75 >= F_8 ( V_42 -> V_10 ) ) ;
if ( args -> V_14 == 1 && args -> V_25 [ 0 ] == '.' ) {
args -> V_27 = V_1 -> V_51 ;
args -> V_114 = V_115 ;
args -> V_89 = V_116 ;
return F_26 ( V_117 ) ;
}
if ( args -> V_14 == 2 &&
args -> V_25 [ 0 ] == '.' && args -> V_25 [ 1 ] == '.' ) {
args -> V_27 = V_1 -> V_33 -> V_52 ( V_42 ) ;
args -> V_114 = V_115 ;
args -> V_89 = V_116 ;
return F_26 ( V_117 ) ;
}
V_113 = NULL ;
for ( V_9 = 0 , V_41 = F_13 ( V_42 ) ; V_9 < V_42 -> V_7 ;
V_9 ++ , V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ) {
V_112 = V_1 -> V_20 -> V_118 -> V_119 ( args , V_41 -> V_25 ,
V_41 -> V_14 ) ;
if ( V_112 != V_120 && V_112 != args -> V_114 ) {
args -> V_114 = V_112 ;
args -> V_27 = V_1 -> V_33 -> V_106 ( V_42 , V_41 ) ;
args -> V_89 = V_1 -> V_33 -> V_107 ( V_41 ) ;
if ( V_112 == V_115 )
return F_26 ( V_117 ) ;
V_113 = V_41 ;
}
}
ASSERT ( args -> V_85 & V_121 ) ;
if ( ! V_113 )
return F_26 ( V_82 ) ;
error = F_37 ( args , V_113 -> V_25 , V_113 -> V_14 ) ;
return F_26 ( error ) ;
}
int
F_38 (
T_10 * args )
{
int V_88 ;
T_1 * V_1 ;
int V_122 ;
int V_9 ;
int V_123 ;
int V_124 ;
T_12 * V_41 ;
T_3 * V_42 ;
F_39 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_63 . V_64 & V_66 ) ;
V_124 = ( int ) V_1 -> V_67 . V_75 ;
if ( V_124 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return F_26 ( V_83 ) ;
}
ASSERT ( V_1 -> V_63 . V_70 == V_124 ) ;
ASSERT ( V_1 -> V_63 . V_73 . V_74 != NULL ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
ASSERT ( V_124 >= F_8 ( V_42 -> V_10 ) ) ;
for ( V_9 = 0 , V_41 = F_13 ( V_42 ) ; V_9 < V_42 -> V_7 ;
V_9 ++ , V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ) {
if ( F_40 ( args , V_41 -> V_25 , V_41 -> V_14 ) ==
V_115 ) {
ASSERT ( V_1 -> V_33 -> V_106 ( V_42 , V_41 ) ==
args -> V_27 ) ;
break;
}
}
if ( V_9 == V_42 -> V_7 )
return F_26 ( V_82 ) ;
V_88 = ( int ) ( ( char * ) V_41 - ( char * ) V_42 ) ;
V_122 = V_1 -> V_33 -> V_84 ( V_42 , args -> V_14 ) ;
V_123 = V_124 - V_122 ;
if ( V_88 + V_122 < V_124 )
memmove ( ( char * ) V_42 + V_88 , ( char * ) V_42 + V_88 + V_122 ,
V_124 - ( V_88 + V_122 ) ) ;
V_42 -> V_7 -- ;
V_1 -> V_67 . V_75 = V_123 ;
F_17 ( V_1 , V_123 - V_124 , V_71 ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
#if V_26
if ( args -> V_27 > V_28 ) {
if ( V_42 -> V_10 == 1 )
F_41 ( args ) ;
else
V_42 -> V_10 -- ;
}
#endif
F_18 ( args ) ;
F_19 ( args -> V_76 , V_1 , V_59 | V_72 ) ;
return 0 ;
}
int
F_42 (
T_10 * args )
{
T_1 * V_1 ;
int V_9 ;
#if V_26 || F_43 ( V_125 )
T_9 V_105 = 0 ;
#endif
#if V_26
int V_126 ;
#endif
T_12 * V_41 ;
T_3 * V_42 ;
F_44 ( args ) ;
V_1 = args -> V_1 ;
ASSERT ( V_1 -> V_63 . V_64 & V_66 ) ;
if ( V_1 -> V_67 . V_75 < F_24 ( T_3 , V_15 ) ) {
ASSERT ( F_25 ( V_1 -> V_20 ) ) ;
return F_26 ( V_83 ) ;
}
ASSERT ( V_1 -> V_63 . V_70 == V_1 -> V_67 . V_75 ) ;
ASSERT ( V_1 -> V_63 . V_73 . V_74 != NULL ) ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
ASSERT ( V_1 -> V_67 . V_75 >= F_8 ( V_42 -> V_10 ) ) ;
#if V_26
if ( args -> V_27 > V_28 && V_42 -> V_10 == 0 ) {
int error ;
int V_123 ;
V_123 =
V_1 -> V_63 . V_70 +
( V_42 -> V_7 + 1 ) *
( ( V_29 ) sizeof( V_31 ) -
( V_29 ) sizeof( V_32 ) ) ;
if ( V_123 > F_9 ( V_1 ) ) {
error = F_28 ( args ) ;
if ( error ) {
return error ;
}
return F_45 ( args ) ;
}
F_31 ( args ) ;
V_126 = 1 ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
} else
V_126 = 0 ;
#endif
ASSERT ( args -> V_14 != 1 || args -> V_25 [ 0 ] != '.' ) ;
if ( args -> V_14 == 2 &&
args -> V_25 [ 0 ] == '.' && args -> V_25 [ 1 ] == '.' ) {
#if V_26 || F_43 ( V_125 )
V_105 = V_1 -> V_33 -> V_52 ( V_42 ) ;
ASSERT ( args -> V_27 != V_105 ) ;
#endif
V_1 -> V_33 -> V_34 ( V_42 , args -> V_27 ) ;
}
else {
for ( V_9 = 0 , V_41 = F_13 ( V_42 ) ; V_9 < V_42 -> V_7 ;
V_9 ++ , V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ) {
if ( F_40 ( args , V_41 -> V_25 , V_41 -> V_14 ) ==
V_115 ) {
#if V_26 || F_43 ( V_125 )
V_105 = V_1 -> V_33 -> V_106 ( V_42 , V_41 ) ;
ASSERT ( args -> V_27 != V_105 ) ;
#endif
V_1 -> V_33 -> V_54 ( V_42 , V_41 , args -> V_27 ) ;
V_1 -> V_33 -> V_55 ( V_41 , args -> V_89 ) ;
break;
}
}
if ( V_9 == V_42 -> V_7 ) {
ASSERT ( args -> V_85 & V_121 ) ;
#if V_26
if ( V_126 )
F_41 ( args ) ;
#endif
return F_26 ( V_82 ) ;
}
}
#if V_26
if ( V_105 > V_28 &&
args -> V_27 <= V_28 ) {
if ( V_42 -> V_10 == 1 )
F_41 ( args ) ;
else
V_42 -> V_10 -- ;
}
if ( V_105 <= V_28 &&
args -> V_27 > V_28 ) {
ASSERT ( V_42 -> V_10 != 0 ) ;
if ( ! V_126 )
V_42 -> V_10 ++ ;
}
#endif
F_18 ( args ) ;
F_19 ( args -> V_76 , V_1 , V_72 ) ;
return 0 ;
}
static void
F_41 (
T_10 * args )
{
char * V_91 ;
T_1 * V_1 ;
int V_9 ;
int V_123 ;
T_12 * V_96 ;
T_3 * V_97 ;
int V_124 ;
T_12 * V_41 ;
T_3 * V_42 ;
struct V_98 * V_13 ;
F_46 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_124 = V_1 -> V_63 . V_70 ;
V_91 = F_12 ( V_124 , V_45 ) ;
V_97 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
ASSERT ( V_97 -> V_10 == 1 ) ;
memcpy ( V_91 , V_97 , V_124 ) ;
V_123 =
V_124 -
( V_97 -> V_7 + 1 ) *
( ( V_29 ) sizeof( V_31 ) - ( V_29 ) sizeof( V_32 ) ) ;
F_17 ( V_1 , - V_124 , V_71 ) ;
F_17 ( V_1 , V_123 , V_71 ) ;
V_97 = ( T_3 * ) V_91 ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_42 -> V_7 = V_97 -> V_7 ;
V_42 -> V_10 = 0 ;
V_1 -> V_33 -> V_34 ( V_42 , V_1 -> V_33 -> V_52 ( V_97 ) ) ;
for ( V_9 = 0 , V_41 = F_13 ( V_42 ) ,
V_96 = F_13 ( V_97 ) ;
V_9 < V_42 -> V_7 ;
V_9 ++ , V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ,
V_96 = V_1 -> V_33 -> V_57 ( V_97 , V_96 ) ) {
V_41 -> V_14 = V_96 -> V_14 ;
V_41 -> V_80 = V_96 -> V_80 ;
memcpy ( V_41 -> V_25 , V_96 -> V_25 , V_41 -> V_14 ) ;
V_1 -> V_33 -> V_54 ( V_42 , V_41 ,
V_1 -> V_33 -> V_106 ( V_97 , V_96 ) ) ;
V_1 -> V_33 -> V_55 ( V_41 , V_1 -> V_33 -> V_107 ( V_96 ) ) ;
}
F_20 ( V_91 ) ;
V_1 -> V_67 . V_75 = V_123 ;
F_19 ( args -> V_76 , V_1 , V_59 | V_72 ) ;
}
static void
F_31 (
T_10 * args )
{
char * V_91 ;
T_1 * V_1 ;
int V_9 ;
int V_123 ;
T_12 * V_96 ;
T_3 * V_97 ;
int V_124 ;
T_12 * V_41 ;
T_3 * V_42 ;
struct V_98 * V_13 ;
F_47 ( args ) ;
V_1 = args -> V_1 ;
V_13 = V_1 -> V_20 ;
V_124 = V_1 -> V_63 . V_70 ;
V_91 = F_12 ( V_124 , V_45 ) ;
V_97 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
ASSERT ( V_97 -> V_10 == 0 ) ;
memcpy ( V_91 , V_97 , V_124 ) ;
V_123 =
V_124 +
( V_97 -> V_7 + 1 ) *
( ( V_29 ) sizeof( V_31 ) - ( V_29 ) sizeof( V_32 ) ) ;
F_17 ( V_1 , - V_124 , V_71 ) ;
F_17 ( V_1 , V_123 , V_71 ) ;
V_97 = ( T_3 * ) V_91 ;
V_42 = ( T_3 * ) V_1 -> V_63 . V_73 . V_74 ;
V_42 -> V_7 = V_97 -> V_7 ;
V_42 -> V_10 = 1 ;
V_1 -> V_33 -> V_34 ( V_42 , V_1 -> V_33 -> V_52 ( V_97 ) ) ;
for ( V_9 = 0 , V_41 = F_13 ( V_42 ) ,
V_96 = F_13 ( V_97 ) ;
V_9 < V_42 -> V_7 ;
V_9 ++ , V_41 = V_1 -> V_33 -> V_57 ( V_42 , V_41 ) ,
V_96 = V_1 -> V_33 -> V_57 ( V_97 , V_96 ) ) {
V_41 -> V_14 = V_96 -> V_14 ;
V_41 -> V_80 = V_96 -> V_80 ;
memcpy ( V_41 -> V_25 , V_96 -> V_25 , V_41 -> V_14 ) ;
V_1 -> V_33 -> V_54 ( V_42 , V_41 ,
V_1 -> V_33 -> V_106 ( V_97 , V_96 ) ) ;
V_1 -> V_33 -> V_55 ( V_41 , V_1 -> V_33 -> V_107 ( V_96 ) ) ;
}
F_20 ( V_91 ) ;
V_1 -> V_67 . V_75 = V_123 ;
F_19 ( args -> V_76 , V_1 , V_59 | V_72 ) ;
}
