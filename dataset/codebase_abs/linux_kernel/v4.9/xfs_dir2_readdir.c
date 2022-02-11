static unsigned char
F_1 (
struct V_1 * V_2 ,
T_1 V_3 )
{
if ( ! F_2 ( & V_2 -> V_4 ) )
return V_5 ;
if ( V_3 >= V_6 )
return V_5 ;
return V_7 [ V_3 ] ;
}
STATIC int
F_3 (
struct V_8 * args ,
struct V_9 * V_10 )
{
int V_11 ;
struct V_12 * V_13 = args -> V_13 ;
T_2 V_14 ;
T_3 * V_15 ;
T_4 * V_16 ;
T_2 V_17 ;
T_2 V_18 ;
T_5 V_19 ;
struct V_20 * V_21 = args -> V_21 ;
ASSERT ( V_13 -> V_22 . V_23 & V_24 ) ;
if ( V_13 -> V_25 . V_26 < F_4 ( T_4 , V_27 ) ) {
ASSERT ( F_5 ( V_13 -> V_28 ) ) ;
return - V_29 ;
}
ASSERT ( V_13 -> V_22 . V_30 == V_13 -> V_25 . V_26 ) ;
ASSERT ( V_13 -> V_22 . V_31 . V_32 != NULL ) ;
V_16 = ( T_4 * ) V_13 -> V_22 . V_31 . V_32 ;
if ( V_13 -> V_25 . V_26 < F_6 ( V_16 -> V_33 ) )
return - V_34 ;
if ( F_7 ( V_21 , V_10 -> V_35 ) > V_21 -> V_36 )
return 0 ;
V_17 = F_8 ( V_21 , V_21 -> V_36 ,
V_13 -> V_37 -> V_38 ) ;
V_18 = F_8 ( V_21 , V_21 -> V_36 ,
V_13 -> V_37 -> V_39 ) ;
if ( V_10 -> V_35 <= V_17 ) {
V_10 -> V_35 = V_17 & 0x7fffffff ;
if ( ! F_9 ( V_10 , L_1 , 1 , V_13 -> V_40 , V_41 ) )
return 0 ;
}
if ( V_10 -> V_35 <= V_18 ) {
V_19 = V_13 -> V_37 -> V_42 ( V_16 ) ;
V_10 -> V_35 = V_18 & 0x7fffffff ;
if ( ! F_9 ( V_10 , L_2 , 2 , V_19 , V_41 ) )
return 0 ;
}
V_15 = F_10 ( V_16 ) ;
for ( V_11 = 0 ; V_11 < V_16 -> V_43 ; V_11 ++ ) {
T_1 V_3 ;
V_14 = F_8 ( V_21 , V_21 -> V_36 ,
F_11 ( V_15 ) ) ;
if ( V_10 -> V_35 > V_14 ) {
V_15 = V_13 -> V_37 -> V_44 ( V_16 , V_15 ) ;
continue;
}
V_19 = V_13 -> V_37 -> V_45 ( V_16 , V_15 ) ;
V_3 = V_13 -> V_37 -> V_46 ( V_15 ) ;
V_10 -> V_35 = V_14 & 0x7fffffff ;
if ( ! F_9 ( V_10 , ( char * ) V_15 -> V_47 , V_15 -> V_48 , V_19 ,
F_1 ( V_13 -> V_28 , V_3 ) ) )
return 0 ;
V_15 = V_13 -> V_37 -> V_44 ( V_16 , V_15 ) ;
}
V_10 -> V_35 = F_8 ( V_21 , V_21 -> V_36 + 1 , 0 ) &
0x7fffffff ;
return 0 ;
}
STATIC int
F_12 (
struct V_8 * args ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = args -> V_13 ;
T_6 * V_49 ;
struct V_50 * V_51 ;
T_7 * V_52 ;
T_8 * V_53 ;
T_9 * V_54 ;
char * V_55 ;
int error ;
char * V_56 ;
int V_57 ;
T_10 V_58 ;
struct V_20 * V_21 = args -> V_21 ;
int V_59 ;
if ( F_7 ( V_21 , V_10 -> V_35 ) > V_21 -> V_36 )
return 0 ;
V_59 = F_13 ( V_13 ) ;
error = F_14 ( NULL , V_13 , & V_51 ) ;
F_15 ( V_13 , V_59 ) ;
if ( error )
return error ;
V_57 = F_16 ( V_21 , V_10 -> V_35 ) ;
V_49 = V_51 -> V_60 ;
F_17 ( V_13 , V_51 ) ;
V_52 = F_18 ( V_21 , V_49 ) ;
V_56 = ( char * ) V_13 -> V_37 -> V_61 ( V_49 ) ;
V_55 = ( char * ) F_19 ( V_52 ) ;
while ( V_56 < V_55 ) {
T_1 V_3 ;
V_54 = ( T_9 * ) V_56 ;
if ( F_20 ( V_54 -> V_62 ) == V_63 ) {
V_56 += F_20 ( V_54 -> V_64 ) ;
continue;
}
V_53 = ( T_8 * ) V_56 ;
V_56 += V_13 -> V_37 -> V_65 ( V_53 -> V_48 ) ;
if ( ( char * ) V_53 - ( char * ) V_49 < V_57 )
continue;
V_58 = F_8 ( V_21 , V_21 -> V_36 ,
( char * ) V_53 - ( char * ) V_49 ) ;
V_10 -> V_35 = V_58 & 0x7fffffff ;
V_3 = V_13 -> V_37 -> V_66 ( V_53 ) ;
if ( ! F_9 ( V_10 , ( char * ) V_53 -> V_47 , V_53 -> V_48 ,
F_21 ( V_53 -> V_67 ) ,
F_1 ( V_13 -> V_28 , V_3 ) ) ) {
F_22 ( NULL , V_51 ) ;
return 0 ;
}
}
V_10 -> V_35 = F_8 ( V_21 , V_21 -> V_36 + 1 , 0 ) &
0x7fffffff ;
F_22 ( NULL , V_51 ) ;
return 0 ;
}
STATIC int
F_23 (
struct V_8 * args ,
T_11 V_68 ,
struct V_69 * V_70 ,
T_12 * V_71 ,
struct V_50 * * V_72 ,
bool V_73 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_50 * V_51 = NULL ;
struct V_74 * V_75 = V_70 -> V_75 ;
struct V_76 V_77 ;
int error = 0 ;
int V_64 ;
int V_11 ;
int V_78 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_73 ) {
V_70 -> V_79 -= V_21 -> V_80 ;
for ( V_11 = V_21 -> V_80 ; V_11 > 0 ; ) {
V_78 = F_24 ( int , V_75 -> V_81 , V_11 ) ;
V_75 -> V_81 -= V_78 ;
V_75 -> V_82 += V_78 ;
V_75 -> V_83 += V_78 ;
if ( ! V_75 -> V_81 && -- V_70 -> V_84 )
memmove ( & V_75 [ 0 ] , & V_75 [ 1 ] ,
sizeof( V_75 [ 0 ] ) * V_70 -> V_84 ) ;
V_11 -= V_78 ;
}
}
V_70 -> V_85 = F_25 ( V_68 + V_21 -> V_86 , ( 1 << V_21 -> V_87 ) ) - 1 ;
ASSERT ( V_70 -> V_85 >= 0 ) ;
if ( 1 + V_70 -> V_85 > V_70 -> V_79 &&
V_70 -> V_88 < F_26 ( V_21 , V_89 ) ) {
V_70 -> V_90 = V_70 -> V_91 - V_70 -> V_84 ;
error = F_27 ( V_13 , V_70 -> V_88 ,
F_26 ( V_21 , V_89 ) -
V_70 -> V_88 ,
& V_75 [ V_70 -> V_84 ] , & V_70 -> V_90 , 0 ) ;
if ( error )
goto V_92;
if ( V_70 -> V_90 == V_70 -> V_91 - V_70 -> V_84 ) {
V_11 = V_70 -> V_84 + V_70 -> V_90 - 1 ;
V_70 -> V_88 = V_75 [ V_11 ] . V_83 + V_75 [ V_11 ] . V_81 ;
} else
V_70 -> V_88 = F_26 ( V_21 ,
V_89 ) ;
for ( V_11 = V_70 -> V_84 ; V_11 < V_70 -> V_84 + V_70 -> V_90 ; ) {
if ( V_75 [ V_11 ] . V_82 == V_93 ) {
V_70 -> V_90 -- ;
V_64 = V_70 -> V_84 + V_70 -> V_90 - V_11 ;
if ( V_64 )
memmove ( & V_75 [ V_11 ] , & V_75 [ V_11 + 1 ] ,
sizeof( V_75 [ V_11 ] ) * V_64 ) ;
} else {
V_70 -> V_79 += V_75 [ V_11 ] . V_81 ;
V_11 ++ ;
}
}
V_70 -> V_84 += V_70 -> V_90 ;
}
if ( ! V_70 -> V_84 ) {
* V_71 = F_28 ( V_21 , V_70 -> V_88 ) ;
goto V_92;
}
V_70 -> V_94 = F_29 ( V_21 , V_75 -> V_83 ) ;
error = F_30 ( NULL , V_13 , V_75 -> V_83 ,
V_75 -> V_81 >= V_21 -> V_80 ?
F_31 ( V_13 -> V_28 , V_75 -> V_82 ) :
- 1 , & V_51 ) ;
if ( error )
goto V_92;
if ( V_70 -> V_95 )
V_70 -> V_95 -= V_21 -> V_80 ;
F_32 ( & V_77 ) ;
for ( V_70 -> V_96 = V_70 -> V_97 = V_11 = 0 ;
V_70 -> V_85 > V_70 -> V_95 && V_11 < V_70 -> V_79 ;
V_11 += V_21 -> V_80 ) {
ASSERT ( V_70 -> V_96 < V_70 -> V_84 ) ;
if ( V_11 > V_70 -> V_95 &&
V_75 [ V_70 -> V_96 ] . V_81 >= V_21 -> V_80 ) {
F_33 ( V_13 ,
V_75 [ V_70 -> V_96 ] . V_83 + V_70 -> V_97 ,
F_31 ( V_13 -> V_28 ,
V_75 [ V_70 -> V_96 ] . V_82 +
V_70 -> V_97 ) ) ;
V_70 -> V_95 = V_11 ;
}
else if ( V_11 > V_70 -> V_95 ) {
F_33 ( V_13 ,
V_75 [ V_70 -> V_96 ] . V_83 +
V_70 -> V_97 , - 1 ) ;
V_70 -> V_95 = V_11 ;
}
for ( V_78 = 0 ; V_78 < V_21 -> V_80 ; V_78 += V_64 ) {
V_64 = F_24 ( int , V_21 -> V_80 ,
V_75 [ V_70 -> V_96 ] . V_81 -
V_70 -> V_97 ) ;
V_70 -> V_97 += V_64 ;
if ( V_70 -> V_97 == V_75 [ V_70 -> V_96 ] . V_81 ) {
V_70 -> V_97 = 0 ;
V_70 -> V_96 ++ ;
}
}
}
F_34 ( & V_77 ) ;
V_92:
* V_72 = V_51 ;
return error ;
}
STATIC int
F_35 (
struct V_8 * args ,
struct V_9 * V_10 ,
T_11 V_68 )
{
struct V_12 * V_13 = args -> V_13 ;
struct V_50 * V_51 = NULL ;
T_6 * V_49 ;
T_8 * V_53 ;
T_9 * V_54 ;
int error = 0 ;
int V_64 ;
int V_98 ;
T_12 V_71 ;
T_12 V_99 ;
char * V_56 = NULL ;
struct V_69 * V_100 ;
struct V_20 * V_21 = args -> V_21 ;
if ( V_10 -> V_35 >= V_101 )
return 0 ;
V_64 = F_25 ( V_68 + V_21 -> V_86 , ( 1 << V_21 -> V_87 ) ) ;
V_100 = F_36 ( F_4 ( struct V_69 , V_75 ) +
( V_64 * sizeof( struct V_74 ) ) ,
V_102 | V_103 ) ;
V_100 -> V_91 = V_64 ;
V_71 = F_37 ( V_10 -> V_35 ) ;
V_100 -> V_88 = F_38 ( V_21 ,
F_39 ( V_21 , V_71 ) ) ;
while ( V_71 < V_89 ) {
T_1 V_3 ;
if ( ! V_51 || V_56 >= ( char * ) V_51 -> V_60 + V_21 -> V_86 ) {
int V_59 ;
bool V_73 = false ;
if ( V_51 ) {
F_22 ( NULL , V_51 ) ;
V_51 = NULL ;
V_73 = true ;
}
V_59 = F_13 ( V_13 ) ;
error = F_23 ( args , V_68 , V_100 ,
& V_71 , & V_51 , V_73 ) ;
F_15 ( V_13 , V_59 ) ;
if ( error || ! V_100 -> V_84 )
break;
V_99 = F_40 ( V_21 ,
V_100 -> V_94 , 0 ) ;
if ( V_71 < V_99 )
V_71 = V_99 ;
else if ( V_71 > V_99 )
ASSERT ( F_39 ( V_21 , V_71 ) ==
V_100 -> V_94 ) ;
V_49 = V_51 -> V_60 ;
F_17 ( V_13 , V_51 ) ;
V_56 = ( char * ) V_13 -> V_37 -> V_61 ( V_49 ) ;
V_98 = F_41 ( V_21 , V_71 ) ;
if ( V_98 == 0 )
V_71 += V_13 -> V_37 -> V_104 ;
else {
while ( ( char * ) V_56 - ( char * ) V_49 < V_98 ) {
V_54 = ( T_9 * ) V_56 ;
if ( F_20 ( V_54 -> V_62 )
== V_63 ) {
V_64 = F_20 ( V_54 -> V_64 ) ;
V_56 += V_64 ;
continue;
}
V_53 = ( T_8 * ) V_56 ;
V_64 =
V_13 -> V_37 -> V_65 ( V_53 -> V_48 ) ;
V_56 += V_64 ;
}
V_71 =
F_40 ( V_21 ,
F_39 ( V_21 , V_71 ) ,
( char * ) V_56 - ( char * ) V_49 ) ;
if ( V_56 >= ( char * ) V_49 + V_21 -> V_86 ) {
continue;
}
}
}
V_54 = ( T_9 * ) V_56 ;
if ( F_20 ( V_54 -> V_62 ) == V_63 ) {
V_64 = F_20 ( V_54 -> V_64 ) ;
V_56 += V_64 ;
V_71 += V_64 ;
continue;
}
V_53 = ( T_8 * ) V_56 ;
V_64 = V_13 -> V_37 -> V_65 ( V_53 -> V_48 ) ;
V_3 = V_13 -> V_37 -> V_66 ( V_53 ) ;
V_10 -> V_35 = F_42 ( V_71 ) & 0x7fffffff ;
if ( ! F_9 ( V_10 , ( char * ) V_53 -> V_47 , V_53 -> V_48 ,
F_21 ( V_53 -> V_67 ) ,
F_1 ( V_13 -> V_28 , V_3 ) ) )
break;
V_56 += V_64 ;
V_71 += V_64 ;
V_68 = V_68 > V_64 ? V_68 - V_64 : 0 ;
}
if ( V_71 > F_37 ( V_101 ) )
V_10 -> V_35 = V_101 & 0x7fffffff ;
else
V_10 -> V_35 = F_42 ( V_71 ) & 0x7fffffff ;
F_43 ( V_100 ) ;
if ( V_51 )
F_22 ( NULL , V_51 ) ;
return error ;
}
int
F_44 (
struct V_12 * V_13 ,
struct V_9 * V_10 ,
T_11 V_68 )
{
struct V_8 args = { NULL } ;
int V_105 ;
int V_106 ;
F_45 ( V_13 ) ;
if ( F_5 ( V_13 -> V_28 ) )
return - V_29 ;
ASSERT ( F_46 ( F_47 ( V_13 ) -> V_107 ) ) ;
F_48 ( V_13 -> V_28 , V_108 ) ;
args . V_13 = V_13 ;
args . V_21 = V_13 -> V_28 -> V_109 ;
F_49 ( V_13 , V_110 ) ;
if ( V_13 -> V_25 . V_111 == V_112 )
V_105 = F_3 ( & args , V_10 ) ;
else if ( ( V_105 = F_50 ( & args , & V_106 ) ) )
;
else if ( V_106 )
V_105 = F_12 ( & args , V_10 ) ;
else
V_105 = F_35 ( & args , V_10 , V_68 ) ;
F_15 ( V_13 , V_110 ) ;
return V_105 ;
}
